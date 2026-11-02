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
int vf3_away_batch1_adapter_1(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c034ce0u: goto P_0c034ce0;
case 0x0c034ce2u: goto P_0c034ce2;
case 0x0c034ce4u: goto P_0c034ce4;
case 0x0c034ce6u: goto P_0c034ce6;
case 0x0c034ce8u: goto P_0c034ce8;
case 0x0c034ceau: goto P_0c034cea;
case 0x0c034cecu: goto P_0c034cec;
case 0x0c034ceeu: goto P_0c034cee;
case 0x0c034cf0u: goto P_0c034cf0;
case 0x0c034cf2u: goto P_0c034cf2;
case 0x0c034cf4u: goto P_0c034cf4;
case 0x0c034cf6u: goto P_0c034cf6;
case 0x0c034cf8u: goto P_0c034cf8;
case 0x0c034d14u: goto P_0c034d14;
case 0x0c034d16u: goto P_0c034d16;
case 0x0c034d18u: goto P_0c034d18;
case 0x0c034d1au: goto P_0c034d1a;
case 0x0c034d1cu: goto P_0c034d1c;
case 0x0c034d1eu: goto P_0c034d1e;
case 0x0c034d20u: goto P_0c034d20;
case 0x0c034d22u: goto P_0c034d22;
case 0x0c034d24u: goto P_0c034d24;
case 0x0c034d26u: goto P_0c034d26;
case 0x0c034d28u: goto P_0c034d28;
case 0x0c034d2au: goto P_0c034d2a;
case 0x0c034d2cu: goto P_0c034d2c;
case 0x0c034d2eu: goto P_0c034d2e;
case 0x0c034d30u: goto P_0c034d30;
case 0x0c034d32u: goto P_0c034d32;
case 0x0c034d34u: goto P_0c034d34;
case 0x0c034d36u: goto P_0c034d36;
case 0x0c034d38u: goto P_0c034d38;
case 0x0c034d3au: goto P_0c034d3a;
case 0x0c034d3cu: goto P_0c034d3c;
case 0x0c034d3eu: goto P_0c034d3e;
case 0x0c034d40u: goto P_0c034d40;
case 0x0c034d42u: goto P_0c034d42;
case 0x0c034d44u: goto P_0c034d44;
case 0x0c034d46u: goto P_0c034d46;
case 0x0c034d48u: goto P_0c034d48;
case 0x0c034d4au: goto P_0c034d4a;
case 0x0c034d4cu: goto P_0c034d4c;
case 0x0c034d4eu: goto P_0c034d4e;
case 0x0c034d50u: goto P_0c034d50;
case 0x0c034d52u: goto P_0c034d52;
case 0x0c034d54u: goto P_0c034d54;
case 0x0c034d56u: goto P_0c034d56;
case 0x0c034d58u: goto P_0c034d58;
case 0x0c034d5au: goto P_0c034d5a;
case 0x0c034d5cu: goto P_0c034d5c;
case 0x0c034d5eu: goto P_0c034d5e;
case 0x0c034d60u: goto P_0c034d60;
case 0x0c034d62u: goto P_0c034d62;
case 0x0c034d64u: goto P_0c034d64;
case 0x0c034d66u: goto P_0c034d66;
case 0x0c034d68u: goto P_0c034d68;
case 0x0c034d6au: goto P_0c034d6a;
case 0x0c034d6cu: goto P_0c034d6c;
case 0x0c034d6eu: goto P_0c034d6e;
case 0x0c034d70u: goto P_0c034d70;
case 0x0c034d72u: goto P_0c034d72;
case 0x0c034d74u: goto P_0c034d74;
case 0x0c034d76u: goto P_0c034d76;
case 0x0c034d78u: goto P_0c034d78;
case 0x0c034d7au: goto P_0c034d7a;
case 0x0c034d7cu: goto P_0c034d7c;
case 0x0c034d7eu: goto P_0c034d7e;
case 0x0c034d80u: goto P_0c034d80;
case 0x0c034d82u: goto P_0c034d82;
case 0x0c034d84u: goto P_0c034d84;
case 0x0c034d86u: goto P_0c034d86;
case 0x0c034d88u: goto P_0c034d88;
case 0x0c034d8au: goto P_0c034d8a;
case 0x0c034d8cu: goto P_0c034d8c;
case 0x0c034d8eu: goto P_0c034d8e;
case 0x0c034d90u: goto P_0c034d90;
case 0x0c034d92u: goto P_0c034d92;
case 0x0c034d94u: goto P_0c034d94;
case 0x0c034d96u: goto P_0c034d96;
case 0x0c034d98u: goto P_0c034d98;
case 0x0c034d9au: goto P_0c034d9a;
case 0x0c034d9cu: goto P_0c034d9c;
case 0x0c034d9eu: goto P_0c034d9e;
case 0x0c034da0u: goto P_0c034da0;
case 0x0c034da2u: goto P_0c034da2;
case 0x0c034da4u: goto P_0c034da4;
case 0x0c034da6u: goto P_0c034da6;
case 0x0c034da8u: goto P_0c034da8;
case 0x0c034daau: goto P_0c034daa;
case 0x0c034dacu: goto P_0c034dac;
case 0x0c034daeu: goto P_0c034dae;
case 0x0c034db0u: goto P_0c034db0;
case 0x0c034db2u: goto P_0c034db2;
case 0x0c034db4u: goto P_0c034db4;
case 0x0c034db6u: goto P_0c034db6;
case 0x0c034db8u: goto P_0c034db8;
case 0x0c034dbau: goto P_0c034dba;
case 0x0c034dbcu: goto P_0c034dbc;
case 0x0c034dbeu: goto P_0c034dbe;
case 0x0c034dc0u: goto P_0c034dc0;
case 0x0c034dc2u: goto P_0c034dc2;
case 0x0c034dc4u: goto P_0c034dc4;
case 0x0c034dc6u: goto P_0c034dc6;
case 0x0c034dc8u: goto P_0c034dc8;
case 0x0c034dcau: goto P_0c034dca;
case 0x0c034dccu: goto P_0c034dcc;
case 0x0c034dceu: goto P_0c034dce;
case 0x0c034dd0u: goto P_0c034dd0;
case 0x0c034dd2u: goto P_0c034dd2;
case 0x0c034dd4u: goto P_0c034dd4;
case 0x0c034dd6u: goto P_0c034dd6;
case 0x0c034dd8u: goto P_0c034dd8;
case 0x0c034ddau: goto P_0c034dda;
case 0x0c034ddcu: goto P_0c034ddc;
case 0x0c034ddeu: goto P_0c034dde;
case 0x0c034de0u: goto P_0c034de0;
case 0x0c034de2u: goto P_0c034de2;
case 0x0c034de4u: goto P_0c034de4;
case 0x0c034de6u: goto P_0c034de6;
case 0x0c034de8u: goto P_0c034de8;
case 0x0c034deau: goto P_0c034dea;
case 0x0c034decu: goto P_0c034dec;
case 0x0c034deeu: goto P_0c034dee;
case 0x0c034df0u: goto P_0c034df0;
case 0x0c034df2u: goto P_0c034df2;
case 0x0c034df4u: goto P_0c034df4;
case 0x0c034df6u: goto P_0c034df6;
case 0x0c034df8u: goto P_0c034df8;
case 0x0c034dfau: goto P_0c034dfa;
case 0x0c034dfcu: goto P_0c034dfc;
case 0x0c034dfeu: goto P_0c034dfe;
case 0x0c034e00u: goto P_0c034e00;
case 0x0c034e02u: goto P_0c034e02;
case 0x0c034e04u: goto P_0c034e04;
case 0x0c034e06u: goto P_0c034e06;
case 0x0c034e08u: goto P_0c034e08;
case 0x0c034e0au: goto P_0c034e0a;
case 0x0c034e0cu: goto P_0c034e0c;
case 0x0c034e0eu: goto P_0c034e0e;
case 0x0c034e10u: goto P_0c034e10;
case 0x0c034e12u: goto P_0c034e12;
case 0x0c034e14u: goto P_0c034e14;
case 0x0c034e16u: goto P_0c034e16;
case 0x0c034e18u: goto P_0c034e18;
case 0x0c034e1au: goto P_0c034e1a;
case 0x0c034e1cu: goto P_0c034e1c;
case 0x0c034e1eu: goto P_0c034e1e;
case 0x0c034e20u: goto P_0c034e20;
case 0x0c034e22u: goto P_0c034e22;
case 0x0c034e24u: goto P_0c034e24;
case 0x0c034e26u: goto P_0c034e26;
case 0x0c034e28u: goto P_0c034e28;
case 0x0c034e2au: goto P_0c034e2a;
case 0x0c034e2cu: goto P_0c034e2c;
case 0x0c034e2eu: goto P_0c034e2e;
case 0x0c034e30u: goto P_0c034e30;
case 0x0c034e32u: goto P_0c034e32;
case 0x0c034e34u: goto P_0c034e34;
case 0x0c034e36u: goto P_0c034e36;
case 0x0c034e38u: goto P_0c034e38;
case 0x0c034e6cu: goto P_0c034e6c;
case 0x0c034e6eu: goto P_0c034e6e;
case 0x0c034e70u: goto P_0c034e70;
case 0x0c034e72u: goto P_0c034e72;
case 0x0c034e74u: goto P_0c034e74;
case 0x0c034e76u: goto P_0c034e76;
case 0x0c034e78u: goto P_0c034e78;
case 0x0c034e7au: goto P_0c034e7a;
case 0x0c034e7cu: goto P_0c034e7c;
case 0x0c034e7eu: goto P_0c034e7e;
case 0x0c034e80u: goto P_0c034e80;
case 0x0c034e82u: goto P_0c034e82;
case 0x0c034e84u: goto P_0c034e84;
case 0x0c034e86u: goto P_0c034e86;
case 0x0c034e88u: goto P_0c034e88;
case 0x0c034e8au: goto P_0c034e8a;
case 0x0c034e8cu: goto P_0c034e8c;
case 0x0c034e8eu: goto P_0c034e8e;
case 0x0c034e90u: goto P_0c034e90;
case 0x0c034e92u: goto P_0c034e92;
case 0x0c034e94u: goto P_0c034e94;
case 0x0c034e96u: goto P_0c034e96;
case 0x0c034e98u: goto P_0c034e98;
case 0x0c034e9au: goto P_0c034e9a;
case 0x0c034e9cu: goto P_0c034e9c;
case 0x0c034e9eu: goto P_0c034e9e;
case 0x0c034ea0u: goto P_0c034ea0;
case 0x0c034ea2u: goto P_0c034ea2;
case 0x0c034ea4u: goto P_0c034ea4;
case 0x0c034ea6u: goto P_0c034ea6;
case 0x0c034ea8u: goto P_0c034ea8;
case 0x0c034eaau: goto P_0c034eaa;
case 0x0c034eacu: goto P_0c034eac;
case 0x0c034eaeu: goto P_0c034eae;
case 0x0c034eb0u: goto P_0c034eb0;
case 0x0c034eb2u: goto P_0c034eb2;
case 0x0c034eb4u: goto P_0c034eb4;
case 0x0c034eb6u: goto P_0c034eb6;
case 0x0c034eb8u: goto P_0c034eb8;
case 0x0c034ebau: goto P_0c034eba;
case 0x0c034ebcu: goto P_0c034ebc;
case 0x0c034ebeu: goto P_0c034ebe;
case 0x0c034ec0u: goto P_0c034ec0;
case 0x0c034ec2u: goto P_0c034ec2;
case 0x0c034ec4u: goto P_0c034ec4;
case 0x0c034ec6u: goto P_0c034ec6;
case 0x0c034ec8u: goto P_0c034ec8;
case 0x0c034ecau: goto P_0c034eca;
case 0x0c034eccu: goto P_0c034ecc;
case 0x0c034eceu: goto P_0c034ece;
case 0x0c034ed0u: goto P_0c034ed0;
case 0x0c034ed2u: goto P_0c034ed2;
case 0x0c034ed4u: goto P_0c034ed4;
case 0x0c034ed6u: goto P_0c034ed6;
case 0x0c034ed8u: goto P_0c034ed8;
case 0x0c034edau: goto P_0c034eda;
case 0x0c034edcu: goto P_0c034edc;
case 0x0c034edeu: goto P_0c034ede;
case 0x0c034ee0u: goto P_0c034ee0;
case 0x0c034ee2u: goto P_0c034ee2;
case 0x0c034ee4u: goto P_0c034ee4;
case 0x0c034ee6u: goto P_0c034ee6;
case 0x0c034ee8u: goto P_0c034ee8;
case 0x0c034eeau: goto P_0c034eea;
case 0x0c034eecu: goto P_0c034eec;
case 0x0c034eeeu: goto P_0c034eee;
case 0x0c034ef0u: goto P_0c034ef0;
case 0x0c034ef2u: goto P_0c034ef2;
case 0x0c034ef4u: goto P_0c034ef4;
case 0x0c034ef6u: goto P_0c034ef6;
case 0x0c034ef8u: goto P_0c034ef8;
case 0x0c034efau: goto P_0c034efa;
case 0x0c034efcu: goto P_0c034efc;
case 0x0c034efeu: goto P_0c034efe;
case 0x0c034f00u: goto P_0c034f00;
case 0x0c034f02u: goto P_0c034f02;
case 0x0c034f04u: goto P_0c034f04;
case 0x0c034f06u: goto P_0c034f06;
case 0x0c034f08u: goto P_0c034f08;
case 0x0c034f0au: goto P_0c034f0a;
case 0x0c034f0cu: goto P_0c034f0c;
case 0x0c034f0eu: goto P_0c034f0e;
case 0x0c034f10u: goto P_0c034f10;
case 0x0c034f12u: goto P_0c034f12;
case 0x0c034f14u: goto P_0c034f14;
case 0x0c034f16u: goto P_0c034f16;
case 0x0c034f18u: goto P_0c034f18;
case 0x0c034f1au: goto P_0c034f1a;
case 0x0c034f1cu: goto P_0c034f1c;
case 0x0c034f1eu: goto P_0c034f1e;
case 0x0c034f20u: goto P_0c034f20;
case 0x0c034f22u: goto P_0c034f22;
case 0x0c034f24u: goto P_0c034f24;
default: return vf3_matrix_family(target,s,ram);
}
P_0c034ce0: /* original 2fe6, guest PC 0x0c034ce0 */
if(!s->budget--) { s->failed_pc=0x0c034ce0u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c034ce2;
P_0c034ce2: /* original 2fd6, guest PC 0x0c034ce2 */
if(!s->budget--) { s->failed_pc=0x0c034ce2u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c034ce4;
P_0c034ce4: /* original 2fc6, guest PC 0x0c034ce4 */
if(!s->budget--) { s->failed_pc=0x0c034ce4u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c034ce6;
P_0c034ce6: /* original 2fb6, guest PC 0x0c034ce6 */
if(!s->budget--) { s->failed_pc=0x0c034ce6u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c034ce8;
P_0c034ce8: /* original 2f86, guest PC 0x0c034ce8 */
if(!s->budget--) { s->failed_pc=0x0c034ce8u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c034cea;
P_0c034cea: /* original de09, guest PC 0x0c034cea */
if(!s->budget--) { s->failed_pc=0x0c034ceau; return 0; }
r[14]=read(ram,0x0c034d10u,4);
goto P_0c034cec;
P_0c034cec: /* original 4f22, guest PC 0x0c034cec */
if(!s->budget--) { s->failed_pc=0x0c034cecu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c034cee;
P_0c034cee: /* original 6de2, guest PC 0x0c034cee */
if(!s->budget--) { s->failed_pc=0x0c034ceeu; return 0; }
tmp=read(ram,r[14],4);
r[13]=tmp;
goto P_0c034cf0;
P_0c034cf0: /* original 2dd8, guest PC 0x0c034cf0 */
if(!s->budget--) { s->failed_pc=0x0c034cf0u; return 0; }
r[17]=(r[17]&~1u)|(((r[13]&r[13])==0)!=0);
goto P_0c034cf2;
P_0c034cf2: /* original 7ff4, guest PC 0x0c034cf2 */
if(!s->budget--) { s->failed_pc=0x0c034cf2u; return 0; }
r[15]+=0xfffffff4u;
goto P_0c034cf4;
P_0c034cf4: /* original 8b0e, guest PC 0x0c034cf4 */
if(!s->budget--) { s->failed_pc=0x0c034cf4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c034d14; }
goto P_0c034cf6;
P_0c034cf6: /* original a10e, guest PC 0x0c034cf6 */
if(!s->budget--) { s->failed_pc=0x0c034cf6u; return 0; }
r[0]=0xffffffffu;
goto P_0c034f16;
P_0c034cf8: /* original e0ff, guest PC 0x0c034cf8 */
if(!s->budget--) { s->failed_pc=0x0c034cf8u; return 0; }
r[0]=0xffffffffu;
if(!vf3_matrix_family(0x0c034cfau,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c034cfau; return 0; } return 1;
P_0c034d14: /* original 0002, guest PC 0x0c034d14 */
if(!s->budget--) { s->failed_pc=0x0c034d14u; return 0; }
r[0]=r[17];
goto P_0c034d16;
P_0c034d16: /* original 4009, guest PC 0x0c034d16 */
if(!s->budget--) { s->failed_pc=0x0c034d16u; return 0; }
r[0]>>=2;
goto P_0c034d18;
P_0c034d18: /* original 4009, guest PC 0x0c034d18 */
if(!s->budget--) { s->failed_pc=0x0c034d18u; return 0; }
r[0]>>=2;
goto P_0c034d1a;
P_0c034d1a: /* original c90f, guest PC 0x0c034d1a */
if(!s->budget--) { s->failed_pc=0x0c034d1au; return 0; }
r[0]&=15u;
goto P_0c034d1c;
P_0c034d1c: /* original 2f02, guest PC 0x0c034d1c */
if(!s->budget--) { s->failed_pc=0x0c034d1cu; return 0; }
write(ram,r[15],r[0],4);
goto P_0c034d1e;
P_0c034d1e: /* original 0002, guest PC 0x0c034d1e */
if(!s->budget--) { s->failed_pc=0x0c034d1eu; return 0; }
r[0]=r[17];
goto P_0c034d20;
P_0c034d20: /* original 938b, guest PC 0x0c034d20 */
if(!s->budget--) { s->failed_pc=0x0c034d20u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c034e3au,2);
goto P_0c034d22;
P_0c034d22: /* original 2039, guest PC 0x0c034d22 */
if(!s->budget--) { s->failed_pc=0x0c034d22u; return 0; }
r[0]&=r[3];
goto P_0c034d24;
P_0c034d24: /* original 400e, guest PC 0x0c034d24 */
if(!s->budget--) { s->failed_pc=0x0c034d24u; return 0; }
r[17]=r[0];
goto P_0c034d26;
P_0c034d26: /* original 52d5, guest PC 0x0c034d26 */
if(!s->budget--) { s->failed_pc=0x0c034d26u; return 0; }
r[2]=read(ram,r[13]+20,4);
goto P_0c034d28;
P_0c034d28: /* original 6322, guest PC 0x0c034d28 */
if(!s->budget--) { s->failed_pc=0x0c034d28u; return 0; }
tmp=read(ram,r[2],4);
r[3]=tmp;
goto P_0c034d2a;
P_0c034d2a: /* original 430b, guest PC 0x0c034d2a */
if(!s->budget--) { s->failed_pc=0x0c034d2au; return 0; }
target=r[3];
r[16]=code_base|0x0c034d2eu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c034d2eu) { target=s->pc; goto dispatch; }
goto P_0c034d2e;
P_0c034d2c: /* original 0009, guest PC 0x0c034d2c */
if(!s->budget--) { s->failed_pc=0x0c034d2cu; return 0; }
goto P_0c034d2e;
P_0c034d2e: /* original 62e2, guest PC 0x0c034d2e */
if(!s->budget--) { s->failed_pc=0x0c034d2eu; return 0; }
tmp=read(ram,r[14],4);
r[2]=tmp;
goto P_0c034d30;
P_0c034d30: /* original ed00, guest PC 0x0c034d30 */
if(!s->budget--) { s->failed_pc=0x0c034d30u; return 0; }
r[13]=0x00000000u;
goto P_0c034d32;
P_0c034d32: /* original 12d8, guest PC 0x0c034d32 */
if(!s->budget--) { s->failed_pc=0x0c034d32u; return 0; }
write(ram,r[2]+32,r[13],4);
goto P_0c034d34;
P_0c034d34: /* original 63e2, guest PC 0x0c034d34 */
if(!s->budget--) { s->failed_pc=0x0c034d34u; return 0; }
tmp=read(ram,r[14],4);
r[3]=tmp;
goto P_0c034d36;
P_0c034d36: /* original 13d9, guest PC 0x0c034d36 */
if(!s->budget--) { s->failed_pc=0x0c034d36u; return 0; }
write(ram,r[3]+36,r[13],4);
goto P_0c034d38;
P_0c034d38: /* original d142, guest PC 0x0c034d38 */
if(!s->budget--) { s->failed_pc=0x0c034d38u; return 0; }
r[1]=read(ram,0x0c034e44u,4);
goto P_0c034d3a;
P_0c034d3a: /* original 62e2, guest PC 0x0c034d3a */
if(!s->budget--) { s->failed_pc=0x0c034d3au; return 0; }
tmp=read(ram,r[14],4);
r[2]=tmp;
goto P_0c034d3c;
P_0c034d3c: /* original 6312, guest PC 0x0c034d3c */
if(!s->budget--) { s->failed_pc=0x0c034d3cu; return 0; }
tmp=read(ram,r[1],4);
r[3]=tmp;
goto P_0c034d3e;
P_0c034d3e: /* original 1231, guest PC 0x0c034d3e */
if(!s->budget--) { s->failed_pc=0x0c034d3eu; return 0; }
write(ram,r[2]+4,r[3],4);
goto P_0c034d40;
P_0c034d40: /* original d041, guest PC 0x0c034d40 */
if(!s->budget--) { s->failed_pc=0x0c034d40u; return 0; }
r[0]=read(ram,0x0c034e48u,4);
goto P_0c034d42;
P_0c034d42: /* original 62e2, guest PC 0x0c034d42 */
if(!s->budget--) { s->failed_pc=0x0c034d42u; return 0; }
tmp=read(ram,r[14],4);
r[2]=tmp;
goto P_0c034d44;
P_0c034d44: /* original 6302, guest PC 0x0c034d44 */
if(!s->budget--) { s->failed_pc=0x0c034d44u; return 0; }
tmp=read(ram,r[0],4);
r[3]=tmp;
goto P_0c034d46;
P_0c034d46: /* original 1232, guest PC 0x0c034d46 */
if(!s->budget--) { s->failed_pc=0x0c034d46u; return 0; }
write(ram,r[2]+8,r[3],4);
goto P_0c034d48;
P_0c034d48: /* original 62e2, guest PC 0x0c034d48 */
if(!s->budget--) { s->failed_pc=0x0c034d48u; return 0; }
tmp=read(ram,r[14],4);
r[2]=tmp;
goto P_0c034d4a;
P_0c034d4a: /* original 12da, guest PC 0x0c034d4a */
if(!s->budget--) { s->failed_pc=0x0c034d4au; return 0; }
write(ram,r[2]+40,r[13],4);
goto P_0c034d4c;
P_0c034d4c: /* original 62e2, guest PC 0x0c034d4c */
if(!s->budget--) { s->failed_pc=0x0c034d4cu; return 0; }
tmp=read(ram,r[14],4);
r[2]=tmp;
goto P_0c034d4e;
P_0c034d4e: /* original 64d3, guest PC 0x0c034d4e */
if(!s->budget--) { s->failed_pc=0x0c034d4eu; return 0; }
r[4]=r[13];
goto P_0c034d50;
P_0c034d50: /* original 65e2, guest PC 0x0c034d50 */
if(!s->budget--) { s->failed_pc=0x0c034d50u; return 0; }
tmp=read(ram,r[14],4);
r[5]=tmp;
goto P_0c034d52;
P_0c034d52: /* original 6122, guest PC 0x0c034d52 */
if(!s->budget--) { s->failed_pc=0x0c034d52u; return 0; }
tmp=read(ram,r[2],4);
r[1]=tmp;
goto P_0c034d54;
P_0c034d54: /* original 9372, guest PC 0x0c034d54 */
if(!s->budget--) { s->failed_pc=0x0c034d54u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c034e3cu,2);
goto P_0c034d56;
P_0c034d56: /* original 7101, guest PC 0x0c034d56 */
if(!s->budget--) { s->failed_pc=0x0c034d56u; return 0; }
r[1]+=0x00000001u;
goto P_0c034d58;
P_0c034d58: /* original 4115, guest PC 0x0c034d58 */
if(!s->budget--) { s->failed_pc=0x0c034d58u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[1]>0)!=0);
goto P_0c034d5a;
P_0c034d5a: /* original 8f09, guest PC 0x0c034d5a */
if(!s->budget--) { s->failed_pc=0x0c034d5au; return 0; }
cond=r[17]&1u;
r[5]+=r[3];
if(!cond) { goto P_0c034d70; }
goto P_0c034d5e;
P_0c034d5c: /* original 353c, guest PC 0x0c034d5c */
if(!s->budget--) { s->failed_pc=0x0c034d5cu; return 0; }
r[5]+=r[3];
goto P_0c034d5e;
P_0c034d5e: /* original e048, guest PC 0x0c034d5e */
if(!s->budget--) { s->failed_pc=0x0c034d5eu; return 0; }
r[0]=0x00000048u;
goto P_0c034d60;
P_0c034d60: /* original 7401, guest PC 0x0c034d60 */
if(!s->budget--) { s->failed_pc=0x0c034d60u; return 0; }
r[4]+=0x00000001u;
goto P_0c034d62;
P_0c034d62: /* original 05d5, guest PC 0x0c034d62 */
if(!s->budget--) { s->failed_pc=0x0c034d62u; return 0; }
write(ram,r[5]+r[0],r[13],2);
goto P_0c034d64;
P_0c034d64: /* original 63e2, guest PC 0x0c034d64 */
if(!s->budget--) { s->failed_pc=0x0c034d64u; return 0; }
tmp=read(ram,r[14],4);
r[3]=tmp;
goto P_0c034d66;
P_0c034d66: /* original 6232, guest PC 0x0c034d66 */
if(!s->budget--) { s->failed_pc=0x0c034d66u; return 0; }
tmp=read(ram,r[3],4);
r[2]=tmp;
goto P_0c034d68;
P_0c034d68: /* original 7201, guest PC 0x0c034d68 */
if(!s->budget--) { s->failed_pc=0x0c034d68u; return 0; }
r[2]+=0x00000001u;
goto P_0c034d6a;
P_0c034d6a: /* original 3423, guest PC 0x0c034d6a */
if(!s->budget--) { s->failed_pc=0x0c034d6au; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=(int32_t)r[2])!=0);
goto P_0c034d6c;
P_0c034d6c: /* original 8ff7, guest PC 0x0c034d6c */
if(!s->budget--) { s->failed_pc=0x0c034d6cu; return 0; }
cond=r[17]&1u;
r[5]+=0x00000050u;
if(!cond) { goto P_0c034d5e; }
goto P_0c034d70;
P_0c034d6e: /* original 7550, guest PC 0x0c034d6e */
if(!s->budget--) { s->failed_pc=0x0c034d6eu; return 0; }
r[5]+=0x00000050u;
goto P_0c034d70;
P_0c034d70: /* original 62e2, guest PC 0x0c034d70 */
if(!s->budget--) { s->failed_pc=0x0c034d70u; return 0; }
tmp=read(ram,r[14],4);
r[2]=tmp;
goto P_0c034d72;
P_0c034d72: /* original 9163, guest PC 0x0c034d72 */
if(!s->budget--) { s->failed_pc=0x0c034d72u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c034e3cu,2);
goto P_0c034d74;
P_0c034d74: /* original 6323, guest PC 0x0c034d74 */
if(!s->budget--) { s->failed_pc=0x0c034d74u; return 0; }
r[3]=r[2];
goto P_0c034d76;
P_0c034d76: /* original 313c, guest PC 0x0c034d76 */
if(!s->budget--) { s->failed_pc=0x0c034d76u; return 0; }
r[1]+=r[3];
goto P_0c034d78;
P_0c034d78: /* original 121b, guest PC 0x0c034d78 */
if(!s->budget--) { s->failed_pc=0x0c034d78u; return 0; }
write(ram,r[2]+44,r[1],4);
goto P_0c034d7a;
P_0c034d7a: /* original 63e2, guest PC 0x0c034d7a */
if(!s->budget--) { s->failed_pc=0x0c034d7au; return 0; }
tmp=read(ram,r[14],4);
r[3]=tmp;
goto P_0c034d7c;
P_0c034d7c: /* original 915e, guest PC 0x0c034d7c */
if(!s->budget--) { s->failed_pc=0x0c034d7cu; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c034e3cu,2);
goto P_0c034d7e;
P_0c034d7e: /* original 6233, guest PC 0x0c034d7e */
if(!s->budget--) { s->failed_pc=0x0c034d7eu; return 0; }
r[2]=r[3];
goto P_0c034d80;
P_0c034d80: /* original 312c, guest PC 0x0c034d80 */
if(!s->budget--) { s->failed_pc=0x0c034d80u; return 0; }
r[1]+=r[2];
goto P_0c034d82;
P_0c034d82: /* original 7150, guest PC 0x0c034d82 */
if(!s->budget--) { s->failed_pc=0x0c034d82u; return 0; }
r[1]+=0x00000050u;
goto P_0c034d84;
P_0c034d84: /* original 131c, guest PC 0x0c034d84 */
if(!s->budget--) { s->failed_pc=0x0c034d84u; return 0; }
write(ram,r[3]+48,r[1],4);
goto P_0c034d86;
P_0c034d86: /* original 60f2, guest PC 0x0c034d86 */
if(!s->budget--) { s->failed_pc=0x0c034d86u; return 0; }
tmp=read(ram,r[15],4);
r[0]=tmp;
goto P_0c034d88;
P_0c034d88: /* original 0302, guest PC 0x0c034d88 */
if(!s->budget--) { s->failed_pc=0x0c034d88u; return 0; }
r[3]=r[17];
goto P_0c034d8a;
P_0c034d8a: /* original 9256, guest PC 0x0c034d8a */
if(!s->budget--) { s->failed_pc=0x0c034d8au; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c034e3au,2);
goto P_0c034d8c;
P_0c034d8c: /* original c90f, guest PC 0x0c034d8c */
if(!s->budget--) { s->failed_pc=0x0c034d8cu; return 0; }
r[0]&=15u;
goto P_0c034d8e;
P_0c034d8e: /* original 4008, guest PC 0x0c034d8e */
if(!s->budget--) { s->failed_pc=0x0c034d8eu; return 0; }
r[0]<<=2;
goto P_0c034d90;
P_0c034d90: /* original 2329, guest PC 0x0c034d90 */
if(!s->budget--) { s->failed_pc=0x0c034d90u; return 0; }
r[3]&=r[2];
goto P_0c034d92;
P_0c034d92: /* original 4008, guest PC 0x0c034d92 */
if(!s->budget--) { s->failed_pc=0x0c034d92u; return 0; }
r[0]<<=2;
goto P_0c034d94;
P_0c034d94: /* original 203b, guest PC 0x0c034d94 */
if(!s->budget--) { s->failed_pc=0x0c034d94u; return 0; }
r[0]|=r[3];
goto P_0c034d96;
P_0c034d96: /* original 400e, guest PC 0x0c034d96 */
if(!s->budget--) { s->failed_pc=0x0c034d96u; return 0; }
r[17]=r[0];
goto P_0c034d98;
P_0c034d98: /* original d32c, guest PC 0x0c034d98 */
if(!s->budget--) { s->failed_pc=0x0c034d98u; return 0; }
r[3]=read(ram,0x0c034e4cu,4);
goto P_0c034d9a;
P_0c034d9a: /* original 6132, guest PC 0x0c034d9a */
if(!s->budget--) { s->failed_pc=0x0c034d9au; return 0; }
tmp=read(ram,r[3],4);
r[1]=tmp;
goto P_0c034d9c;
P_0c034d9c: /* original 2118, guest PC 0x0c034d9c */
if(!s->budget--) { s->failed_pc=0x0c034d9cu; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[1])==0)!=0);
goto P_0c034d9e;
P_0c034d9e: /* original 8b07, guest PC 0x0c034d9e */
if(!s->budget--) { s->failed_pc=0x0c034d9eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c034db0; }
goto P_0c034da0;
P_0c034da0: /* original 944d, guest PC 0x0c034da0 */
if(!s->budget--) { s->failed_pc=0x0c034da0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c034e3eu,2);
goto P_0c034da2;
P_0c034da2: /* original e700, guest PC 0x0c034da2 */
if(!s->budget--) { s->failed_pc=0x0c034da2u; return 0; }
r[7]=0x00000000u;
goto P_0c034da4;
P_0c034da4: /* original d22b, guest PC 0x0c034da4 */
if(!s->budget--) { s->failed_pc=0x0c034da4u; return 0; }
r[2]=read(ram,0x0c034e54u,4);
goto P_0c034da6;
P_0c034da6: /* original d52a, guest PC 0x0c034da6 */
if(!s->budget--) { s->failed_pc=0x0c034da6u; return 0; }
r[5]=read(ram,0x0c034e50u,4);
goto P_0c034da8;
P_0c034da8: /* original 420b, guest PC 0x0c034da8 */
if(!s->budget--) { s->failed_pc=0x0c034da8u; return 0; }
target=r[2];
r[16]=code_base|0x0c034dacu;
r[6]=0x00000050u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c034dacu) { target=s->pc; goto dispatch; }
goto P_0c034dac;
P_0c034daa: /* original e650, guest PC 0x0c034daa */
if(!s->budget--) { s->failed_pc=0x0c034daau; return 0; }
r[6]=0x00000050u;
goto P_0c034dac;
P_0c034dac: /* original d327, guest PC 0x0c034dac */
if(!s->budget--) { s->failed_pc=0x0c034dacu; return 0; }
r[3]=read(ram,0x0c034e4cu,4);
goto P_0c034dae;
P_0c034dae: /* original 2302, guest PC 0x0c034dae */
if(!s->budget--) { s->failed_pc=0x0c034daeu; return 0; }
write(ram,r[3],r[0],4);
goto P_0c034db0;
P_0c034db0: /* original d129, guest PC 0x0c034db0 */
if(!s->budget--) { s->failed_pc=0x0c034db0u; return 0; }
r[1]=read(ram,0x0c034e58u,4);
goto P_0c034db2;
P_0c034db2: /* original 6212, guest PC 0x0c034db2 */
if(!s->budget--) { s->failed_pc=0x0c034db2u; return 0; }
tmp=read(ram,r[1],4);
r[2]=tmp;
goto P_0c034db4;
P_0c034db4: /* original 2228, guest PC 0x0c034db4 */
if(!s->budget--) { s->failed_pc=0x0c034db4u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c034db6;
P_0c034db6: /* original 8b07, guest PC 0x0c034db6 */
if(!s->budget--) { s->failed_pc=0x0c034db6u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c034dc8; }
goto P_0c034db8;
P_0c034db8: /* original 9442, guest PC 0x0c034db8 */
if(!s->budget--) { s->failed_pc=0x0c034db8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c034e40u,2);
goto P_0c034dba;
P_0c034dba: /* original e700, guest PC 0x0c034dba */
if(!s->budget--) { s->failed_pc=0x0c034dbau; return 0; }
r[7]=0x00000000u;
goto P_0c034dbc;
P_0c034dbc: /* original d325, guest PC 0x0c034dbc */
if(!s->budget--) { s->failed_pc=0x0c034dbcu; return 0; }
r[3]=read(ram,0x0c034e54u,4);
goto P_0c034dbe;
P_0c034dbe: /* original d527, guest PC 0x0c034dbe */
if(!s->budget--) { s->failed_pc=0x0c034dbeu; return 0; }
r[5]=read(ram,0x0c034e5cu,4);
goto P_0c034dc0;
P_0c034dc0: /* original 430b, guest PC 0x0c034dc0 */
if(!s->budget--) { s->failed_pc=0x0c034dc0u; return 0; }
target=r[3];
r[16]=code_base|0x0c034dc4u;
r[6]=0x00000010u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c034dc4u) { target=s->pc; goto dispatch; }
goto P_0c034dc4;
P_0c034dc2: /* original e610, guest PC 0x0c034dc2 */
if(!s->budget--) { s->failed_pc=0x0c034dc2u; return 0; }
r[6]=0x00000010u;
goto P_0c034dc4;
P_0c034dc4: /* original d224, guest PC 0x0c034dc4 */
if(!s->budget--) { s->failed_pc=0x0c034dc4u; return 0; }
r[2]=read(ram,0x0c034e58u,4);
goto P_0c034dc6;
P_0c034dc6: /* original 2202, guest PC 0x0c034dc6 */
if(!s->budget--) { s->failed_pc=0x0c034dc6u; return 0; }
write(ram,r[2],r[0],4);
goto P_0c034dc8;
P_0c034dc8: /* original 64e2, guest PC 0x0c034dc8 */
if(!s->budget--) { s->failed_pc=0x0c034dc8u; return 0; }
tmp=read(ram,r[14],4);
r[4]=tmp;
goto P_0c034dca;
P_0c034dca: /* original e700, guest PC 0x0c034dca */
if(!s->budget--) { s->failed_pc=0x0c034dcau; return 0; }
r[7]=0x00000000u;
goto P_0c034dcc;
P_0c034dcc: /* original d324, guest PC 0x0c034dcc */
if(!s->budget--) { s->failed_pc=0x0c034dccu; return 0; }
r[3]=read(ram,0x0c034e60u,4);
goto P_0c034dce;
P_0c034dce: /* original 6673, guest PC 0x0c034dce */
if(!s->budget--) { s->failed_pc=0x0c034dceu; return 0; }
r[6]=r[7];
goto P_0c034dd0;
P_0c034dd0: /* original 6573, guest PC 0x0c034dd0 */
if(!s->budget--) { s->failed_pc=0x0c034dd0u; return 0; }
r[5]=r[7];
goto P_0c034dd2;
P_0c034dd2: /* original 430b, guest PC 0x0c034dd2 */
if(!s->budget--) { s->failed_pc=0x0c034dd2u; return 0; }
target=r[3];
r[16]=code_base|0x0c034dd6u;
r[4]=read(ram,r[4]+44,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c034dd6u) { target=s->pc; goto dispatch; }
goto P_0c034dd6;
P_0c034dd4: /* original 544b, guest PC 0x0c034dd4 */
if(!s->budget--) { s->failed_pc=0x0c034dd4u; return 0; }
r[4]=read(ram,r[4]+44,4);
goto P_0c034dd6;
P_0c034dd6: /* original 62e2, guest PC 0x0c034dd6 */
if(!s->budget--) { s->failed_pc=0x0c034dd6u; return 0; }
tmp=read(ram,r[14],4);
r[2]=tmp;
goto P_0c034dd8;
P_0c034dd8: /* original 5325, guest PC 0x0c034dd8 */
if(!s->budget--) { s->failed_pc=0x0c034dd8u; return 0; }
r[3]=read(ram,r[2]+20,4);
goto P_0c034dda;
P_0c034dda: /* original 5137, guest PC 0x0c034dda */
if(!s->budget--) { s->failed_pc=0x0c034ddau; return 0; }
r[1]=read(ram,r[3]+28,4);
goto P_0c034ddc;
P_0c034ddc: /* original 410b, guest PC 0x0c034ddc */
if(!s->budget--) { s->failed_pc=0x0c034ddcu; return 0; }
target=r[1];
r[16]=code_base|0x0c034de0u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c034de0u) { target=s->pc; goto dispatch; }
goto P_0c034de0;
P_0c034dde: /* original 0009, guest PC 0x0c034dde */
if(!s->budget--) { s->failed_pc=0x0c034ddeu; return 0; }
goto P_0c034de0;
P_0c034de0: /* original 6403, guest PC 0x0c034de0 */
if(!s->budget--) { s->failed_pc=0x0c034de0u; return 0; }
r[4]=r[0];
goto P_0c034de2;
P_0c034de2: /* original 2448, guest PC 0x0c034de2 */
if(!s->budget--) { s->failed_pc=0x0c034de2u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c034de4;
P_0c034de4: /* original 891d, guest PC 0x0c034de4 */
if(!s->budget--) { s->failed_pc=0x0c034de4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c034e22; }
goto P_0c034de6;
P_0c034de6: /* original 62e2, guest PC 0x0c034de6 */
if(!s->budget--) { s->failed_pc=0x0c034de6u; return 0; }
tmp=read(ram,r[14],4);
r[2]=tmp;
goto P_0c034de8;
P_0c034de8: /* original e04c, guest PC 0x0c034de8 */
if(!s->budget--) { s->failed_pc=0x0c034de8u; return 0; }
r[0]=0x0000004cu;
goto P_0c034dea;
P_0c034dea: /* original e104, guest PC 0x0c034dea */
if(!s->budget--) { s->failed_pc=0x0c034deau; return 0; }
r[1]=0x00000004u;
goto P_0c034dec;
P_0c034dec: /* original 532b, guest PC 0x0c034dec */
if(!s->budget--) { s->failed_pc=0x0c034decu; return 0; }
r[3]=read(ram,r[2]+44,4);
goto P_0c034dee;
P_0c034dee: /* original 134f, guest PC 0x0c034dee */
if(!s->budget--) { s->failed_pc=0x0c034deeu; return 0; }
write(ram,r[3]+60,r[4],4);
goto P_0c034df0;
P_0c034df0: /* original 62e2, guest PC 0x0c034df0 */
if(!s->budget--) { s->failed_pc=0x0c034df0u; return 0; }
tmp=read(ram,r[14],4);
r[2]=tmp;
goto P_0c034df2;
P_0c034df2: /* original 532b, guest PC 0x0c034df2 */
if(!s->budget--) { s->failed_pc=0x0c034df2u; return 0; }
r[3]=read(ram,r[2]+44,4);
goto P_0c034df4;
P_0c034df4: /* original 0315, guest PC 0x0c034df4 */
if(!s->budget--) { s->failed_pc=0x0c034df4u; return 0; }
write(ram,r[3]+r[0],r[1],2);
goto P_0c034df6;
P_0c034df6: /* original 63e2, guest PC 0x0c034df6 */
if(!s->budget--) { s->failed_pc=0x0c034df6u; return 0; }
tmp=read(ram,r[14],4);
r[3]=tmp;
goto P_0c034df8;
P_0c034df8: /* original 6233, guest PC 0x0c034df8 */
if(!s->budget--) { s->failed_pc=0x0c034df8u; return 0; }
r[2]=r[3];
goto P_0c034dfa;
P_0c034dfa: /* original 512b, guest PC 0x0c034dfa */
if(!s->budget--) { s->failed_pc=0x0c034dfau; return 0; }
r[1]=read(ram,r[2]+44,4);
goto P_0c034dfc;
P_0c034dfc: /* original 131a, guest PC 0x0c034dfc */
if(!s->budget--) { s->failed_pc=0x0c034dfcu; return 0; }
write(ram,r[3]+40,r[1],4);
goto P_0c034dfe;
P_0c034dfe: /* original d319, guest PC 0x0c034dfe */
if(!s->budget--) { s->failed_pc=0x0c034dfeu; return 0; }
r[3]=read(ram,0x0c034e64u,4);
goto P_0c034e00;
P_0c034e00: /* original 64e2, guest PC 0x0c034e00 */
if(!s->budget--) { s->failed_pc=0x0c034e00u; return 0; }
tmp=read(ram,r[14],4);
r[4]=tmp;
goto P_0c034e02;
P_0c034e02: /* original 430b, guest PC 0x0c034e02 */
if(!s->budget--) { s->failed_pc=0x0c034e02u; return 0; }
target=r[3];
r[16]=code_base|0x0c034e06u;
r[4]=read(ram,r[4]+44,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c034e06u) { target=s->pc; goto dispatch; }
goto P_0c034e06;
P_0c034e04: /* original 544b, guest PC 0x0c034e04 */
if(!s->budget--) { s->failed_pc=0x0c034e04u; return 0; }
r[4]=read(ram,r[4]+44,4);
goto P_0c034e06;
P_0c034e06: /* original d318, guest PC 0x0c034e06 */
if(!s->budget--) { s->failed_pc=0x0c034e06u; return 0; }
r[3]=read(ram,0x0c034e68u,4);
goto P_0c034e08;
P_0c034e08: /* original 6c03, guest PC 0x0c034e08 */
if(!s->budget--) { s->failed_pc=0x0c034e08u; return 0; }
r[12]=r[0];
goto P_0c034e0a;
P_0c034e0a: /* original 64e2, guest PC 0x0c034e0a */
if(!s->budget--) { s->failed_pc=0x0c034e0au; return 0; }
tmp=read(ram,r[14],4);
r[4]=tmp;
goto P_0c034e0c;
P_0c034e0c: /* original 430b, guest PC 0x0c034e0c */
if(!s->budget--) { s->failed_pc=0x0c034e0cu; return 0; }
target=r[3];
r[16]=code_base|0x0c034e10u;
r[4]=read(ram,r[4]+44,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c034e10u) { target=s->pc; goto dispatch; }
goto P_0c034e10;
P_0c034e0e: /* original 544b, guest PC 0x0c034e0e */
if(!s->budget--) { s->failed_pc=0x0c034e0eu; return 0; }
r[4]=read(ram,r[4]+44,4);
goto P_0c034e10;
P_0c034e10: /* original 62e2, guest PC 0x0c034e10 */
if(!s->budget--) { s->failed_pc=0x0c034e10u; return 0; }
tmp=read(ram,r[14],4);
r[2]=tmp;
goto P_0c034e12;
P_0c034e12: /* original 6bf3, guest PC 0x0c034e12 */
if(!s->budget--) { s->failed_pc=0x0c034e12u; return 0; }
r[11]=r[15];
goto P_0c034e14;
P_0c034e14: /* original 7b04, guest PC 0x0c034e14 */
if(!s->budget--) { s->failed_pc=0x0c034e14u; return 0; }
r[11]+=0x00000004u;
goto P_0c034e16;
P_0c034e16: /* original 5325, guest PC 0x0c034e16 */
if(!s->budget--) { s->failed_pc=0x0c034e16u; return 0; }
r[3]=read(ram,r[2]+20,4);
goto P_0c034e18;
P_0c034e18: /* original 5138, guest PC 0x0c034e18 */
if(!s->budget--) { s->failed_pc=0x0c034e18u; return 0; }
r[1]=read(ram,r[3]+32,4);
goto P_0c034e1a;
P_0c034e1a: /* original 410b, guest PC 0x0c034e1a */
if(!s->budget--) { s->failed_pc=0x0c034e1au; return 0; }
target=r[1];
r[16]=code_base|0x0c034e1eu;
r[4]=r[11];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c034e1eu) { target=s->pc; goto dispatch; }
goto P_0c034e1e;
P_0c034e1c: /* original 64b3, guest PC 0x0c034e1c */
if(!s->budget--) { s->failed_pc=0x0c034e1cu; return 0; }
r[4]=r[11];
goto P_0c034e1e;
P_0c034e1e: /* original 2008, guest PC 0x0c034e1e */
if(!s->budget--) { s->failed_pc=0x0c034e1eu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c034e20;
P_0c034e20: /* original 8b01, guest PC 0x0c034e20 */
if(!s->budget--) { s->failed_pc=0x0c034e20u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c034e26; }
goto P_0c034e22;
P_0c034e22: /* original a078, guest PC 0x0c034e22 */
if(!s->budget--) { s->failed_pc=0x0c034e22u; return 0; }
r[0]=0xfffffffeu;
goto P_0c034f16;
P_0c034e24: /* original e0fe, guest PC 0x0c034e24 */
if(!s->budget--) { s->failed_pc=0x0c034e24u; return 0; }
r[0]=0xfffffffeu;
goto P_0c034e26;
P_0c034e26: /* original 2cc8, guest PC 0x0c034e26 */
if(!s->budget--) { s->failed_pc=0x0c034e26u; return 0; }
r[17]=(r[17]&~1u)|(((r[12]&r[12])==0)!=0);
goto P_0c034e28;
P_0c034e28: /* original 8922, guest PC 0x0c034e28 */
if(!s->budget--) { s->failed_pc=0x0c034e28u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c034e70; }
goto P_0c034e2a;
P_0c034e2a: /* original 60c3, guest PC 0x0c034e2a */
if(!s->budget--) { s->failed_pc=0x0c034e2au; return 0; }
r[0]=r[12];
goto P_0c034e2c;
P_0c034e2c: /* original 88e3, guest PC 0x0c034e2c */
if(!s->budget--) { s->failed_pc=0x0c034e2cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xffffffe3u)!=0);
goto P_0c034e2e;
P_0c034e2e: /* original 8b1d, guest PC 0x0c034e2e */
if(!s->budget--) { s->failed_pc=0x0c034e2eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c034e6c; }
goto P_0c034e30;
P_0c034e30: /* original 60b2, guest PC 0x0c034e30 */
if(!s->budget--) { s->failed_pc=0x0c034e30u; return 0; }
tmp=read(ram,r[11],4);
r[0]=tmp;
goto P_0c034e32;
P_0c034e32: /* original 8806, guest PC 0x0c034e32 */
if(!s->budget--) { s->failed_pc=0x0c034e32u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000006u)!=0);
goto P_0c034e34;
P_0c034e34: /* original 8b1a, guest PC 0x0c034e34 */
if(!s->budget--) { s->failed_pc=0x0c034e34u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c034e6c; }
goto P_0c034e36;
P_0c034e36: /* original a06e, guest PC 0x0c034e36 */
if(!s->budget--) { s->failed_pc=0x0c034e36u; return 0; }
r[0]=0xffffffe9u;
goto P_0c034f16;
P_0c034e38: /* original e0e9, guest PC 0x0c034e38 */
if(!s->budget--) { s->failed_pc=0x0c034e38u; return 0; }
r[0]=0xffffffe9u;
if(!vf3_matrix_family(0x0c034e3au,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c034e3au; return 0; } return 1;
P_0c034e6c: /* original a053, guest PC 0x0c034e6c */
if(!s->budget--) { s->failed_pc=0x0c034e6cu; return 0; }
r[0]=r[12];
goto P_0c034f16;
P_0c034e6e: /* original 60c3, guest PC 0x0c034e6e */
if(!s->budget--) { s->failed_pc=0x0c034e6eu; return 0; }
r[0]=r[12];
goto P_0c034e70;
P_0c034e70: /* original 52b1, guest PC 0x0c034e70 */
if(!s->budget--) { s->failed_pc=0x0c034e70u; return 0; }
r[2]=read(ram,r[11]+4,4);
goto P_0c034e72;
P_0c034e72: /* original 9370, guest PC 0x0c034e72 */
if(!s->budget--) { s->failed_pc=0x0c034e72u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c034f56u,2);
goto P_0c034e74;
P_0c034e74: /* original 3230, guest PC 0x0c034e74 */
if(!s->budget--) { s->failed_pc=0x0c034e74u; return 0; }
r[17]=(r[17]&~1u)|((r[2]==r[3])!=0);
goto P_0c034e76;
P_0c034e76: /* original 8b49, guest PC 0x0c034e76 */
if(!s->budget--) { s->failed_pc=0x0c034e76u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c034f0c; }
goto P_0c034e78;
P_0c034e78: /* original 66e2, guest PC 0x0c034e78 */
if(!s->budget--) { s->failed_pc=0x0c034e78u; return 0; }
tmp=read(ram,r[14],4);
r[6]=tmp;
goto P_0c034e7a;
P_0c034e7a: /* original e501, guest PC 0x0c034e7a */
if(!s->budget--) { s->failed_pc=0x0c034e7au; return 0; }
r[5]=0x00000001u;
goto P_0c034e7c;
P_0c034e7c: /* original 64e2, guest PC 0x0c034e7c */
if(!s->budget--) { s->failed_pc=0x0c034e7cu; return 0; }
tmp=read(ram,r[14],4);
r[4]=tmp;
goto P_0c034e7e;
P_0c034e7e: /* original d339, guest PC 0x0c034e7e */
if(!s->budget--) { s->failed_pc=0x0c034e7eu; return 0; }
r[3]=read(ram,0x0c034f64u,4);
goto P_0c034e80;
P_0c034e80: /* original 7640, guest PC 0x0c034e80 */
if(!s->budget--) { s->failed_pc=0x0c034e80u; return 0; }
r[6]+=0x00000040u;
goto P_0c034e82;
P_0c034e82: /* original 430b, guest PC 0x0c034e82 */
if(!s->budget--) { s->failed_pc=0x0c034e82u; return 0; }
target=r[3];
r[16]=code_base|0x0c034e86u;
r[4]=read(ram,r[4]+4,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c034e86u) { target=s->pc; goto dispatch; }
goto P_0c034e86;
P_0c034e84: /* original 5441, guest PC 0x0c034e84 */
if(!s->budget--) { s->failed_pc=0x0c034e84u; return 0; }
r[4]=read(ram,r[4]+4,4);
goto P_0c034e86;
P_0c034e86: /* original 6403, guest PC 0x0c034e86 */
if(!s->budget--) { s->failed_pc=0x0c034e86u; return 0; }
r[4]=r[0];
goto P_0c034e88;
P_0c034e88: /* original 2448, guest PC 0x0c034e88 */
if(!s->budget--) { s->failed_pc=0x0c034e88u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c034e8a;
P_0c034e8a: /* original 8b38, guest PC 0x0c034e8a */
if(!s->budget--) { s->failed_pc=0x0c034e8au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c034efe; }
goto P_0c034e8c;
P_0c034e8c: /* original 64e2, guest PC 0x0c034e8c */
if(!s->budget--) { s->failed_pc=0x0c034e8cu; return 0; }
tmp=read(ram,r[14],4);
r[4]=tmp;
goto P_0c034e8e;
P_0c034e8e: /* original bcca, guest PC 0x0c034e8e */
if(!s->budget--) { s->failed_pc=0x0c034e8eu; return 0; }
target=code_base|0x0c034826u; r[16]=code_base|0x0c034e92u;
r[4]+=0x00000040u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c034e92u) { target=s->pc; goto dispatch; }
goto P_0c034e92;
P_0c034e90: /* original 7440, guest PC 0x0c034e90 */
if(!s->budget--) { s->failed_pc=0x0c034e90u; return 0; }
r[4]+=0x00000040u;
goto P_0c034e92;
P_0c034e92: /* original 2008, guest PC 0x0c034e92 */
if(!s->budget--) { s->failed_pc=0x0c034e92u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c034e94;
P_0c034e94: /* original 893a, guest PC 0x0c034e94 */
if(!s->budget--) { s->failed_pc=0x0c034e94u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c034f0c; }
goto P_0c034e96;
P_0c034e96: /* original 64e2, guest PC 0x0c034e96 */
if(!s->budget--) { s->failed_pc=0x0c034e96u; return 0; }
tmp=read(ram,r[14],4);
r[4]=tmp;
goto P_0c034e98;
P_0c034e98: /* original 68e2, guest PC 0x0c034e98 */
if(!s->budget--) { s->failed_pc=0x0c034e98u; return 0; }
tmp=read(ram,r[14],4);
r[8]=tmp;
goto P_0c034e9a;
P_0c034e9a: /* original 935d, guest PC 0x0c034e9a */
if(!s->budget--) { s->failed_pc=0x0c034e9au; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c034f58u,2);
goto P_0c034e9c;
P_0c034e9c: /* original 7440, guest PC 0x0c034e9c */
if(!s->budget--) { s->failed_pc=0x0c034e9cu; return 0; }
r[4]+=0x00000040u;
goto P_0c034e9e;
P_0c034e9e: /* original 780c, guest PC 0x0c034e9e */
if(!s->budget--) { s->failed_pc=0x0c034e9eu; return 0; }
r[8]+=0x0000000cu;
goto P_0c034ea0;
P_0c034ea0: /* original bcae, guest PC 0x0c034ea0 */
if(!s->budget--) { s->failed_pc=0x0c034ea0u; return 0; }
target=code_base|0x0c034800u; r[16]=code_base|0x0c034ea4u;
r[4]+=r[3];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c034ea4u) { target=s->pc; goto dispatch; }
goto P_0c034ea4;
P_0c034ea2: /* original 343c, guest PC 0x0c034ea2 */
if(!s->budget--) { s->failed_pc=0x0c034ea2u; return 0; }
r[4]+=r[3];
goto P_0c034ea4;
P_0c034ea4: /* original 2802, guest PC 0x0c034ea4 */
if(!s->budget--) { s->failed_pc=0x0c034ea4u; return 0; }
write(ram,r[8],r[0],4);
goto P_0c034ea6;
P_0c034ea6: /* original 63e2, guest PC 0x0c034ea6 */
if(!s->budget--) { s->failed_pc=0x0c034ea6u; return 0; }
tmp=read(ram,r[14],4);
r[3]=tmp;
goto P_0c034ea8;
P_0c034ea8: /* original 9257, guest PC 0x0c034ea8 */
if(!s->budget--) { s->failed_pc=0x0c034ea8u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c034f5au,2);
goto P_0c034eaa;
P_0c034eaa: /* original 5133, guest PC 0x0c034eaa */
if(!s->budget--) { s->failed_pc=0x0c034eaau; return 0; }
r[1]=read(ram,r[3]+12,4);
goto P_0c034eac;
P_0c034eac: /* original 312c, guest PC 0x0c034eac */
if(!s->budget--) { s->failed_pc=0x0c034eacu; return 0; }
r[1]+=r[2];
goto P_0c034eae;
P_0c034eae: /* original 1313, guest PC 0x0c034eae */
if(!s->budget--) { s->failed_pc=0x0c034eaeu; return 0; }
write(ram,r[3]+12,r[1],4);
goto P_0c034eb0;
P_0c034eb0: /* original 64e2, guest PC 0x0c034eb0 */
if(!s->budget--) { s->failed_pc=0x0c034eb0u; return 0; }
tmp=read(ram,r[14],4);
r[4]=tmp;
goto P_0c034eb2;
P_0c034eb2: /* original 68e2, guest PC 0x0c034eb2 */
if(!s->budget--) { s->failed_pc=0x0c034eb2u; return 0; }
tmp=read(ram,r[14],4);
r[8]=tmp;
goto P_0c034eb4;
P_0c034eb4: /* original 9352, guest PC 0x0c034eb4 */
if(!s->budget--) { s->failed_pc=0x0c034eb4u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c034f5cu,2);
goto P_0c034eb6;
P_0c034eb6: /* original 7440, guest PC 0x0c034eb6 */
if(!s->budget--) { s->failed_pc=0x0c034eb6u; return 0; }
r[4]+=0x00000040u;
goto P_0c034eb8;
P_0c034eb8: /* original 7810, guest PC 0x0c034eb8 */
if(!s->budget--) { s->failed_pc=0x0c034eb8u; return 0; }
r[8]+=0x00000010u;
goto P_0c034eba;
P_0c034eba: /* original bca1, guest PC 0x0c034eba */
if(!s->budget--) { s->failed_pc=0x0c034ebau; return 0; }
target=code_base|0x0c034800u; r[16]=code_base|0x0c034ebeu;
r[4]+=r[3];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c034ebeu) { target=s->pc; goto dispatch; }
goto P_0c034ebe;
P_0c034ebc: /* original 343c, guest PC 0x0c034ebc */
if(!s->budget--) { s->failed_pc=0x0c034ebcu; return 0; }
r[4]+=r[3];
goto P_0c034ebe;
P_0c034ebe: /* original 2802, guest PC 0x0c034ebe */
if(!s->budget--) { s->failed_pc=0x0c034ebeu; return 0; }
write(ram,r[8],r[0],4);
goto P_0c034ec0;
P_0c034ec0: /* original 64e2, guest PC 0x0c034ec0 */
if(!s->budget--) { s->failed_pc=0x0c034ec0u; return 0; }
tmp=read(ram,r[14],4);
r[4]=tmp;
goto P_0c034ec2;
P_0c034ec2: /* original 934c, guest PC 0x0c034ec2 */
if(!s->budget--) { s->failed_pc=0x0c034ec2u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c034f5eu,2);
goto P_0c034ec4;
P_0c034ec4: /* original 7440, guest PC 0x0c034ec4 */
if(!s->budget--) { s->failed_pc=0x0c034ec4u; return 0; }
r[4]+=0x00000040u;
goto P_0c034ec6;
P_0c034ec6: /* original bc9b, guest PC 0x0c034ec6 */
if(!s->budget--) { s->failed_pc=0x0c034ec6u; return 0; }
target=code_base|0x0c034800u; r[16]=code_base|0x0c034ecau;
r[4]+=r[3];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c034ecau) { target=s->pc; goto dispatch; }
goto P_0c034eca;
P_0c034ec8: /* original 343c, guest PC 0x0c034ec8 */
if(!s->budget--) { s->failed_pc=0x0c034ec8u; return 0; }
r[4]+=r[3];
goto P_0c034eca;
P_0c034eca: /* original 64e2, guest PC 0x0c034eca */
if(!s->budget--) { s->failed_pc=0x0c034ecau; return 0; }
tmp=read(ram,r[14],4);
r[4]=tmp;
goto P_0c034ecc;
P_0c034ecc: /* original 6c03, guest PC 0x0c034ecc */
if(!s->budget--) { s->failed_pc=0x0c034eccu; return 0; }
r[12]=r[0];
goto P_0c034ece;
P_0c034ece: /* original 9344, guest PC 0x0c034ece */
if(!s->budget--) { s->failed_pc=0x0c034eceu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c034f5au,2);
goto P_0c034ed0;
P_0c034ed0: /* original 9246, guest PC 0x0c034ed0 */
if(!s->budget--) { s->failed_pc=0x0c034ed0u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c034f60u,2);
goto P_0c034ed2;
P_0c034ed2: /* original 7440, guest PC 0x0c034ed2 */
if(!s->budget--) { s->failed_pc=0x0c034ed2u; return 0; }
r[4]+=0x00000040u;
goto P_0c034ed4;
P_0c034ed4: /* original 3c3c, guest PC 0x0c034ed4 */
if(!s->budget--) { s->failed_pc=0x0c034ed4u; return 0; }
r[12]+=r[3];
goto P_0c034ed6;
P_0c034ed6: /* original bc93, guest PC 0x0c034ed6 */
if(!s->budget--) { s->failed_pc=0x0c034ed6u; return 0; }
target=code_base|0x0c034800u; r[16]=code_base|0x0c034edau;
r[4]+=r[2];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c034edau) { target=s->pc; goto dispatch; }
goto P_0c034eda;
P_0c034ed8: /* original 342c, guest PC 0x0c034ed8 */
if(!s->budget--) { s->failed_pc=0x0c034ed8u; return 0; }
r[4]+=r[2];
goto P_0c034eda;
P_0c034eda: /* original 63e2, guest PC 0x0c034eda */
if(!s->budget--) { s->failed_pc=0x0c034edau; return 0; }
tmp=read(ram,r[14],4);
r[3]=tmp;
goto P_0c034edc;
P_0c034edc: /* original 6703, guest PC 0x0c034edc */
if(!s->budget--) { s->failed_pc=0x0c034edcu; return 0; }
r[7]=r[0];
goto P_0c034ede;
P_0c034ede: /* original 65c3, guest PC 0x0c034ede */
if(!s->budget--) { s->failed_pc=0x0c034edeu; return 0; }
r[5]=r[12];
goto P_0c034ee0;
P_0c034ee0: /* original 5236, guest PC 0x0c034ee0 */
if(!s->budget--) { s->failed_pc=0x0c034ee0u; return 0; }
r[2]=read(ram,r[3]+24,4);
goto P_0c034ee2;
P_0c034ee2: /* original 12d2, guest PC 0x0c034ee2 */
if(!s->budget--) { s->failed_pc=0x0c034ee2u; return 0; }
write(ram,r[2]+8,r[13],4);
goto P_0c034ee4;
P_0c034ee4: /* original 66e2, guest PC 0x0c034ee4 */
if(!s->budget--) { s->failed_pc=0x0c034ee4u; return 0; }
tmp=read(ram,r[14],4);
r[6]=tmp;
goto P_0c034ee6;
P_0c034ee6: /* original 64e2, guest PC 0x0c034ee6 */
if(!s->budget--) { s->failed_pc=0x0c034ee6u; return 0; }
tmp=read(ram,r[14],4);
r[4]=tmp;
goto P_0c034ee8;
P_0c034ee8: /* original d31f, guest PC 0x0c034ee8 */
if(!s->budget--) { s->failed_pc=0x0c034ee8u; return 0; }
r[3]=read(ram,0x0c034f68u,4);
goto P_0c034eea;
P_0c034eea: /* original 5666, guest PC 0x0c034eea */
if(!s->budget--) { s->failed_pc=0x0c034eeau; return 0; }
r[6]=read(ram,r[6]+24,4);
goto P_0c034eec;
P_0c034eec: /* original 430b, guest PC 0x0c034eec */
if(!s->budget--) { s->failed_pc=0x0c034eecu; return 0; }
target=r[3];
r[16]=code_base|0x0c034ef0u;
r[4]+=0x00000040u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c034ef0u) { target=s->pc; goto dispatch; }
goto P_0c034ef0;
P_0c034eee: /* original 7440, guest PC 0x0c034eee */
if(!s->budget--) { s->failed_pc=0x0c034eeeu; return 0; }
r[4]+=0x00000040u;
goto P_0c034ef0;
P_0c034ef0: /* original 88f4, guest PC 0x0c034ef0 */
if(!s->budget--) { s->failed_pc=0x0c034ef0u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xfffffff4u)!=0);
goto P_0c034ef2;
P_0c034ef2: /* original 8f02, guest PC 0x0c034ef2 */
if(!s->budget--) { s->failed_pc=0x0c034ef2u; return 0; }
cond=r[17]&1u;
r[4]=r[0];
if(!cond) { goto P_0c034efa; }
goto P_0c034ef6;
P_0c034ef4: /* original 6403, guest PC 0x0c034ef4 */
if(!s->budget--) { s->failed_pc=0x0c034ef4u; return 0; }
r[4]=r[0];
goto P_0c034ef6;
P_0c034ef6: /* original a00e, guest PC 0x0c034ef6 */
if(!s->budget--) { s->failed_pc=0x0c034ef6u; return 0; }
r[0]=r[4];
goto P_0c034f16;
P_0c034ef8: /* original 6043, guest PC 0x0c034ef8 */
if(!s->budget--) { s->failed_pc=0x0c034ef8u; return 0; }
r[0]=r[4];
goto P_0c034efa;
P_0c034efa: /* original 2448, guest PC 0x0c034efa */
if(!s->budget--) { s->failed_pc=0x0c034efau; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c034efc;
P_0c034efc: /* original 8901, guest PC 0x0c034efc */
if(!s->budget--) { s->failed_pc=0x0c034efcu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c034f02; }
goto P_0c034efe;
P_0c034efe: /* original a00a, guest PC 0x0c034efe */
if(!s->budget--) { s->failed_pc=0x0c034efeu; return 0; }
r[0]=0xfffffffcu;
goto P_0c034f16;
P_0c034f00: /* original e0fc, guest PC 0x0c034f00 */
if(!s->budget--) { s->failed_pc=0x0c034f00u; return 0; }
r[0]=0xfffffffcu;
goto P_0c034f02;
P_0c034f02: /* original 64e2, guest PC 0x0c034f02 */
if(!s->budget--) { s->failed_pc=0x0c034f02u; return 0; }
tmp=read(ram,r[14],4);
r[4]=tmp;
goto P_0c034f04;
P_0c034f04: /* original 5346, guest PC 0x0c034f04 */
if(!s->budget--) { s->failed_pc=0x0c034f04u; return 0; }
r[3]=read(ram,r[4]+24,4);
goto P_0c034f06;
P_0c034f06: /* original 6232, guest PC 0x0c034f06 */
if(!s->budget--) { s->failed_pc=0x0c034f06u; return 0; }
tmp=read(ram,r[3],4);
r[2]=tmp;
goto P_0c034f08;
P_0c034f08: /* original 2228, guest PC 0x0c034f08 */
if(!s->budget--) { s->failed_pc=0x0c034f08u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c034f0a;
P_0c034f0a: /* original 8b01, guest PC 0x0c034f0a */
if(!s->budget--) { s->failed_pc=0x0c034f0au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c034f10; }
goto P_0c034f0c;
P_0c034f0c: /* original a003, guest PC 0x0c034f0c */
if(!s->budget--) { s->failed_pc=0x0c034f0cu; return 0; }
r[0]=0xfffffffbu;
goto P_0c034f16;
P_0c034f0e: /* original e0fb, guest PC 0x0c034f0e */
if(!s->budget--) { s->failed_pc=0x0c034f0eu; return 0; }
r[0]=0xfffffffbu;
goto P_0c034f10;
P_0c034f10: /* original e301, guest PC 0x0c034f10 */
if(!s->budget--) { s->failed_pc=0x0c034f10u; return 0; }
r[3]=0x00000001u;
goto P_0c034f12;
P_0c034f12: /* original e000, guest PC 0x0c034f12 */
if(!s->budget--) { s->failed_pc=0x0c034f12u; return 0; }
r[0]=0x00000000u;
goto P_0c034f14;
P_0c034f14: /* original 1438, guest PC 0x0c034f14 */
if(!s->budget--) { s->failed_pc=0x0c034f14u; return 0; }
write(ram,r[4]+32,r[3],4);
goto P_0c034f16;
P_0c034f16: /* original 7f0c, guest PC 0x0c034f16 */
if(!s->budget--) { s->failed_pc=0x0c034f16u; return 0; }
r[15]+=0x0000000cu;
goto P_0c034f18;
P_0c034f18: /* original 4f26, guest PC 0x0c034f18 */
if(!s->budget--) { s->failed_pc=0x0c034f18u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c034f1a;
P_0c034f1a: /* original 68f6, guest PC 0x0c034f1a */
if(!s->budget--) { s->failed_pc=0x0c034f1au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c034f1c;
P_0c034f1c: /* original 6bf6, guest PC 0x0c034f1c */
if(!s->budget--) { s->failed_pc=0x0c034f1cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c034f1e;
P_0c034f1e: /* original 6cf6, guest PC 0x0c034f1e */
if(!s->budget--) { s->failed_pc=0x0c034f1eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c034f20;
P_0c034f20: /* original 6df6, guest PC 0x0c034f20 */
if(!s->budget--) { s->failed_pc=0x0c034f20u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c034f22;
P_0c034f22: /* original 000b, guest PC 0x0c034f22 */
if(!s->budget--) { s->failed_pc=0x0c034f22u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c034f24: /* original 6ef6, guest PC 0x0c034f24 */
if(!s->budget--) { s->failed_pc=0x0c034f24u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c034f26u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c034f26u; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
