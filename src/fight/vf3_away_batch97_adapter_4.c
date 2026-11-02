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
int vf3_away_batch97_adapter_4(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c0c2d06u: goto P_0c0c2d06;
case 0x0c0c2d08u: goto P_0c0c2d08;
case 0x0c0c2d0au: goto P_0c0c2d0a;
case 0x0c0c2d0cu: goto P_0c0c2d0c;
case 0x0c0c2d0eu: goto P_0c0c2d0e;
case 0x0c0c2d10u: goto P_0c0c2d10;
case 0x0c0c2d12u: goto P_0c0c2d12;
case 0x0c0c2d14u: goto P_0c0c2d14;
case 0x0c0c2d16u: goto P_0c0c2d16;
case 0x0c0c2d18u: goto P_0c0c2d18;
case 0x0c0c2d1au: goto P_0c0c2d1a;
case 0x0c0c2d1cu: goto P_0c0c2d1c;
case 0x0c0c2d1eu: goto P_0c0c2d1e;
case 0x0c0c2d20u: goto P_0c0c2d20;
case 0x0c0c2d22u: goto P_0c0c2d22;
case 0x0c0c2d24u: goto P_0c0c2d24;
case 0x0c0c2d26u: goto P_0c0c2d26;
case 0x0c0c2d28u: goto P_0c0c2d28;
case 0x0c0c2d2au: goto P_0c0c2d2a;
case 0x0c0c2d2cu: goto P_0c0c2d2c;
case 0x0c0c2d2eu: goto P_0c0c2d2e;
case 0x0c0c2d30u: goto P_0c0c2d30;
case 0x0c0c2d32u: goto P_0c0c2d32;
case 0x0c0c2d34u: goto P_0c0c2d34;
case 0x0c0c2d36u: goto P_0c0c2d36;
case 0x0c0c2d38u: goto P_0c0c2d38;
case 0x0c0c2d3au: goto P_0c0c2d3a;
case 0x0c0c2d3cu: goto P_0c0c2d3c;
case 0x0c0c2d3eu: goto P_0c0c2d3e;
case 0x0c0c2d40u: goto P_0c0c2d40;
case 0x0c0c2d42u: goto P_0c0c2d42;
case 0x0c0c2d44u: goto P_0c0c2d44;
case 0x0c0c2d46u: goto P_0c0c2d46;
case 0x0c0c2d48u: goto P_0c0c2d48;
case 0x0c0c2d4au: goto P_0c0c2d4a;
case 0x0c0c2d4cu: goto P_0c0c2d4c;
case 0x0c0c2d4eu: goto P_0c0c2d4e;
case 0x0c0c2d50u: goto P_0c0c2d50;
case 0x0c0c2d52u: goto P_0c0c2d52;
case 0x0c0c2d54u: goto P_0c0c2d54;
case 0x0c0c2d56u: goto P_0c0c2d56;
case 0x0c0c2d58u: goto P_0c0c2d58;
case 0x0c0c2d5au: goto P_0c0c2d5a;
case 0x0c0c2d5cu: goto P_0c0c2d5c;
case 0x0c0c2d5eu: goto P_0c0c2d5e;
case 0x0c0c2d60u: goto P_0c0c2d60;
case 0x0c0c2d62u: goto P_0c0c2d62;
case 0x0c0c2d64u: goto P_0c0c2d64;
case 0x0c0c2d66u: goto P_0c0c2d66;
case 0x0c0c2d68u: goto P_0c0c2d68;
case 0x0c0c2d6au: goto P_0c0c2d6a;
case 0x0c0c2d6cu: goto P_0c0c2d6c;
case 0x0c0c2d6eu: goto P_0c0c2d6e;
case 0x0c0c2d70u: goto P_0c0c2d70;
case 0x0c0c2d72u: goto P_0c0c2d72;
case 0x0c0c2d74u: goto P_0c0c2d74;
case 0x0c0c2d76u: goto P_0c0c2d76;
case 0x0c0c2d78u: goto P_0c0c2d78;
case 0x0c0c2d7au: goto P_0c0c2d7a;
case 0x0c0c2d7cu: goto P_0c0c2d7c;
case 0x0c0c2d7eu: goto P_0c0c2d7e;
case 0x0c0c2d80u: goto P_0c0c2d80;
case 0x0c0c2d82u: goto P_0c0c2d82;
case 0x0c0c2d84u: goto P_0c0c2d84;
case 0x0c0c2d86u: goto P_0c0c2d86;
case 0x0c0c2dccu: goto P_0c0c2dcc;
case 0x0c0c2dceu: goto P_0c0c2dce;
case 0x0c0c2dd0u: goto P_0c0c2dd0;
case 0x0c0c2dd2u: goto P_0c0c2dd2;
case 0x0c0c2dd4u: goto P_0c0c2dd4;
case 0x0c0c2dd6u: goto P_0c0c2dd6;
case 0x0c0c2dd8u: goto P_0c0c2dd8;
case 0x0c0c2ddau: goto P_0c0c2dda;
case 0x0c0c2ddcu: goto P_0c0c2ddc;
case 0x0c0c2ddeu: goto P_0c0c2dde;
case 0x0c0c2de0u: goto P_0c0c2de0;
case 0x0c0c2de2u: goto P_0c0c2de2;
case 0x0c0c2de4u: goto P_0c0c2de4;
case 0x0c0c2de6u: goto P_0c0c2de6;
case 0x0c0c2de8u: goto P_0c0c2de8;
case 0x0c0c2deau: goto P_0c0c2dea;
case 0x0c0c2decu: goto P_0c0c2dec;
case 0x0c0c2deeu: goto P_0c0c2dee;
case 0x0c0c2df0u: goto P_0c0c2df0;
case 0x0c0c2df2u: goto P_0c0c2df2;
case 0x0c0c2df4u: goto P_0c0c2df4;
case 0x0c0c2df6u: goto P_0c0c2df6;
case 0x0c0c2df8u: goto P_0c0c2df8;
case 0x0c0c2dfau: goto P_0c0c2dfa;
case 0x0c0c2dfcu: goto P_0c0c2dfc;
case 0x0c0c2dfeu: goto P_0c0c2dfe;
case 0x0c0c2e00u: goto P_0c0c2e00;
case 0x0c0c2e02u: goto P_0c0c2e02;
case 0x0c0c2e04u: goto P_0c0c2e04;
case 0x0c0c2e06u: goto P_0c0c2e06;
case 0x0c0c2e08u: goto P_0c0c2e08;
case 0x0c0c2e0au: goto P_0c0c2e0a;
case 0x0c0c2e0cu: goto P_0c0c2e0c;
case 0x0c0c2e0eu: goto P_0c0c2e0e;
case 0x0c0c2e10u: goto P_0c0c2e10;
case 0x0c0c2e12u: goto P_0c0c2e12;
case 0x0c0c2e14u: goto P_0c0c2e14;
case 0x0c0c2e16u: goto P_0c0c2e16;
case 0x0c0c2e18u: goto P_0c0c2e18;
case 0x0c0c2e1au: goto P_0c0c2e1a;
case 0x0c0c2e1cu: goto P_0c0c2e1c;
case 0x0c0c2e1eu: goto P_0c0c2e1e;
case 0x0c0c2e20u: goto P_0c0c2e20;
case 0x0c0c2e22u: goto P_0c0c2e22;
case 0x0c0c2e24u: goto P_0c0c2e24;
case 0x0c0c2e26u: goto P_0c0c2e26;
case 0x0c0c2e28u: goto P_0c0c2e28;
case 0x0c0c2e2au: goto P_0c0c2e2a;
case 0x0c0c2e2cu: goto P_0c0c2e2c;
case 0x0c0c2e2eu: goto P_0c0c2e2e;
case 0x0c0c2e30u: goto P_0c0c2e30;
case 0x0c0c2e32u: goto P_0c0c2e32;
case 0x0c0c2e34u: goto P_0c0c2e34;
case 0x0c0c2e36u: goto P_0c0c2e36;
case 0x0c0c2e38u: goto P_0c0c2e38;
case 0x0c0c2e3au: goto P_0c0c2e3a;
case 0x0c0c2e3cu: goto P_0c0c2e3c;
case 0x0c0c2e3eu: goto P_0c0c2e3e;
case 0x0c0c2e40u: goto P_0c0c2e40;
case 0x0c0c2e42u: goto P_0c0c2e42;
case 0x0c0c2e44u: goto P_0c0c2e44;
case 0x0c0c2e46u: goto P_0c0c2e46;
case 0x0c0c2e48u: goto P_0c0c2e48;
case 0x0c0c2e4au: goto P_0c0c2e4a;
case 0x0c0c2e4cu: goto P_0c0c2e4c;
case 0x0c0c2e4eu: goto P_0c0c2e4e;
case 0x0c0c2e50u: goto P_0c0c2e50;
case 0x0c0c2e52u: goto P_0c0c2e52;
case 0x0c0c2e54u: goto P_0c0c2e54;
case 0x0c0c2e56u: goto P_0c0c2e56;
case 0x0c0c2e58u: goto P_0c0c2e58;
case 0x0c0c2e5au: goto P_0c0c2e5a;
case 0x0c0c2e5cu: goto P_0c0c2e5c;
case 0x0c0c2e5eu: goto P_0c0c2e5e;
case 0x0c0c2e60u: goto P_0c0c2e60;
case 0x0c0c2e62u: goto P_0c0c2e62;
case 0x0c0c2e64u: goto P_0c0c2e64;
case 0x0c0c2e66u: goto P_0c0c2e66;
case 0x0c0c2e68u: goto P_0c0c2e68;
case 0x0c0c2e6au: goto P_0c0c2e6a;
case 0x0c0c2e6cu: goto P_0c0c2e6c;
case 0x0c0c2e6eu: goto P_0c0c2e6e;
case 0x0c0c2e70u: goto P_0c0c2e70;
case 0x0c0c2e72u: goto P_0c0c2e72;
case 0x0c0c2e74u: goto P_0c0c2e74;
case 0x0c0c2e76u: goto P_0c0c2e76;
case 0x0c0c2e78u: goto P_0c0c2e78;
case 0x0c0c2e7au: goto P_0c0c2e7a;
case 0x0c0c2e7cu: goto P_0c0c2e7c;
case 0x0c0c2e7eu: goto P_0c0c2e7e;
case 0x0c0c2e80u: goto P_0c0c2e80;
case 0x0c0c2e82u: goto P_0c0c2e82;
case 0x0c0c2e84u: goto P_0c0c2e84;
case 0x0c0c2e86u: goto P_0c0c2e86;
case 0x0c0c2e88u: goto P_0c0c2e88;
case 0x0c0c2e8au: goto P_0c0c2e8a;
case 0x0c0c2e8cu: goto P_0c0c2e8c;
case 0x0c0c2e8eu: goto P_0c0c2e8e;
case 0x0c0c2e90u: goto P_0c0c2e90;
case 0x0c0c2e92u: goto P_0c0c2e92;
case 0x0c0c2e94u: goto P_0c0c2e94;
case 0x0c0c2e96u: goto P_0c0c2e96;
case 0x0c0c2e98u: goto P_0c0c2e98;
case 0x0c0c2e9au: goto P_0c0c2e9a;
case 0x0c0c2e9cu: goto P_0c0c2e9c;
case 0x0c0c2e9eu: goto P_0c0c2e9e;
case 0x0c0c2ea0u: goto P_0c0c2ea0;
case 0x0c0c2ea2u: goto P_0c0c2ea2;
case 0x0c0c2ea4u: goto P_0c0c2ea4;
case 0x0c0c2ea6u: goto P_0c0c2ea6;
case 0x0c0c2ea8u: goto P_0c0c2ea8;
case 0x0c0c2eaau: goto P_0c0c2eaa;
case 0x0c0c2eacu: goto P_0c0c2eac;
case 0x0c0c2eaeu: goto P_0c0c2eae;
case 0x0c0c2eb0u: goto P_0c0c2eb0;
case 0x0c0c2eb2u: goto P_0c0c2eb2;
case 0x0c0c2eb4u: goto P_0c0c2eb4;
case 0x0c0c2eb6u: goto P_0c0c2eb6;
case 0x0c0c2eb8u: goto P_0c0c2eb8;
case 0x0c0c2ebau: goto P_0c0c2eba;
case 0x0c0c2ebcu: goto P_0c0c2ebc;
case 0x0c0c2ebeu: goto P_0c0c2ebe;
case 0x0c0c2ec0u: goto P_0c0c2ec0;
case 0x0c0c2ec2u: goto P_0c0c2ec2;
case 0x0c0c2ec4u: goto P_0c0c2ec4;
case 0x0c0c2ec6u: goto P_0c0c2ec6;
case 0x0c0c2ec8u: goto P_0c0c2ec8;
case 0x0c0c2ecau: goto P_0c0c2eca;
case 0x0c0c2eccu: goto P_0c0c2ecc;
case 0x0c0c2eceu: goto P_0c0c2ece;
case 0x0c0c2ed0u: goto P_0c0c2ed0;
case 0x0c0c2ed2u: goto P_0c0c2ed2;
case 0x0c0c2ed4u: goto P_0c0c2ed4;
case 0x0c0c2ed6u: goto P_0c0c2ed6;
case 0x0c0c2ed8u: goto P_0c0c2ed8;
case 0x0c0c2edau: goto P_0c0c2eda;
case 0x0c0c2edcu: goto P_0c0c2edc;
case 0x0c0c2edeu: goto P_0c0c2ede;
case 0x0c0c2ee0u: goto P_0c0c2ee0;
case 0x0c0c2ee2u: goto P_0c0c2ee2;
case 0x0c0c2ee4u: goto P_0c0c2ee4;
case 0x0c0c2ee6u: goto P_0c0c2ee6;
case 0x0c0c2ee8u: goto P_0c0c2ee8;
case 0x0c0c2eeau: goto P_0c0c2eea;
case 0x0c0c2eecu: goto P_0c0c2eec;
case 0x0c0c2eeeu: goto P_0c0c2eee;
case 0x0c0c2ef0u: goto P_0c0c2ef0;
case 0x0c0c2ef2u: goto P_0c0c2ef2;
case 0x0c0c2ef4u: goto P_0c0c2ef4;
case 0x0c0c2ef6u: goto P_0c0c2ef6;
case 0x0c0c2ef8u: goto P_0c0c2ef8;
case 0x0c0c2efau: goto P_0c0c2efa;
case 0x0c0c2efcu: goto P_0c0c2efc;
case 0x0c0c2efeu: goto P_0c0c2efe;
case 0x0c0c2f00u: goto P_0c0c2f00;
case 0x0c0c2f02u: goto P_0c0c2f02;
case 0x0c0c2f04u: goto P_0c0c2f04;
case 0x0c0c2f06u: goto P_0c0c2f06;
case 0x0c0c2f08u: goto P_0c0c2f08;
case 0x0c0c2f0au: goto P_0c0c2f0a;
case 0x0c0c2f0cu: goto P_0c0c2f0c;
case 0x0c0c2f0eu: goto P_0c0c2f0e;
case 0x0c0c2f10u: goto P_0c0c2f10;
case 0x0c0c2f12u: goto P_0c0c2f12;
default: return vf3_matrix_family(target,s,ram);
}
P_0c0c2d06: /* original 2fe6, guest PC 0x0c0c2d06 */
if(!s->budget--) { s->failed_pc=0x0c0c2d06u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c2d08;
P_0c0c2d08: /* original 2fd6, guest PC 0x0c0c2d08 */
if(!s->budget--) { s->failed_pc=0x0c0c2d08u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c2d0a;
P_0c0c2d0a: /* original 2fc6, guest PC 0x0c0c2d0a */
if(!s->budget--) { s->failed_pc=0x0c0c2d0au; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c2d0c;
P_0c0c2d0c: /* original 2fb6, guest PC 0x0c0c2d0c */
if(!s->budget--) { s->failed_pc=0x0c0c2d0cu; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c2d0e;
P_0c0c2d0e: /* original fffb, guest PC 0x0c0c2d0e */
if(!s->budget--) { s->failed_pc=0x0c0c2d0eu; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c0c2d10;
P_0c0c2d10: /* original 4f22, guest PC 0x0c0c2d10 */
if(!s->budget--) { s->failed_pc=0x0c0c2d10u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0c2d12;
P_0c0c2d12: /* original de28, guest PC 0x0c0c2d12 */
if(!s->budget--) { s->failed_pc=0x0c0c2d12u; return 0; }
r[14]=read(ram,0x0c0c2db4u,4);
goto P_0c0c2d14;
P_0c0c2d14: /* original d328, guest PC 0x0c0c2d14 */
if(!s->budget--) { s->failed_pc=0x0c0c2d14u; return 0; }
r[3]=read(ram,0x0c0c2db8u,4);
goto P_0c0c2d16;
P_0c0c2d16: /* original 65e3, guest PC 0x0c0c2d16 */
if(!s->budget--) { s->failed_pc=0x0c0c2d16u; return 0; }
r[5]=r[14];
goto P_0c0c2d18;
P_0c0c2d18: /* original 7ff8, guest PC 0x0c0c2d18 */
if(!s->budget--) { s->failed_pc=0x0c0c2d18u; return 0; }
r[15]+=0xfffffff8u;
goto P_0c0c2d1a;
P_0c0c2d1a: /* original 66e3, guest PC 0x0c0c2d1a */
if(!s->budget--) { s->failed_pc=0x0c0c2d1au; return 0; }
r[6]=r[14];
goto P_0c0c2d1c;
P_0c0c2d1c: /* original 430b, guest PC 0x0c0c2d1c */
if(!s->budget--) { s->failed_pc=0x0c0c2d1cu; return 0; }
target=r[3];
r[16]=code_base|0x0c0c2d20u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c2d20u) { target=s->pc; goto dispatch; }
goto P_0c0c2d20;
P_0c0c2d1e: /* original 64e3, guest PC 0x0c0c2d1e */
if(!s->budget--) { s->failed_pc=0x0c0c2d1eu; return 0; }
r[4]=r[14];
goto P_0c0c2d20;
P_0c0c2d20: /* original de22, guest PC 0x0c0c2d20 */
if(!s->budget--) { s->failed_pc=0x0c0c2d20u; return 0; }
r[14]=read(ram,0x0c0c2dacu,4);
goto P_0c0c2d22;
P_0c0c2d22: /* original db20, guest PC 0x0c0c2d22 */
if(!s->budget--) { s->failed_pc=0x0c0c2d22u; return 0; }
r[11]=read(ram,0x0c0c2da4u,4);
goto P_0c0c2d24;
P_0c0c2d24: /* original 54e2, guest PC 0x0c0c2d24 */
if(!s->budget--) { s->failed_pc=0x0c0c2d24u; return 0; }
r[4]=read(ram,r[14]+8,4);
goto P_0c0c2d26;
P_0c0c2d26: /* original dc1e, guest PC 0x0c0c2d26 */
if(!s->budget--) { s->failed_pc=0x0c0c2d26u; return 0; }
r[12]=read(ram,0x0c0c2da0u,4);
goto P_0c0c2d28;
P_0c0c2d28: /* original 6243, guest PC 0x0c0c2d28 */
if(!s->budget--) { s->failed_pc=0x0c0c2d28u; return 0; }
r[2]=r[4];
goto P_0c0c2d2a;
P_0c0c2d2a: /* original 2448, guest PC 0x0c0c2d2a */
if(!s->budget--) { s->failed_pc=0x0c0c2d2au; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c0c2d2c;
P_0c0c2d2c: /* original 7201, guest PC 0x0c0c2d2c */
if(!s->budget--) { s->failed_pc=0x0c0c2d2cu; return 0; }
r[2]+=0x00000001u;
goto P_0c0c2d2e;
P_0c0c2d2e: /* original 8f08, guest PC 0x0c0c2d2e */
if(!s->budget--) { s->failed_pc=0x0c0c2d2eu; return 0; }
cond=r[17]&1u;
write(ram,r[14]+8,r[2],4);
if(!cond) { goto P_0c0c2d42; }
goto P_0c0c2d32;
P_0c0c2d30: /* original 1e22, guest PC 0x0c0c2d30 */
if(!s->budget--) { s->failed_pc=0x0c0c2d30u; return 0; }
write(ram,r[14]+8,r[2],4);
goto P_0c0c2d32;
P_0c0c2d32: /* original 942c, guest PC 0x0c0c2d32 */
if(!s->budget--) { s->failed_pc=0x0c0c2d32u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c2d8eu,2);
goto P_0c0c2d34;
P_0c0c2d34: /* original e700, guest PC 0x0c0c2d34 */
if(!s->budget--) { s->failed_pc=0x0c0c2d34u; return 0; }
r[7]=0x00000000u;
goto P_0c0c2d36;
P_0c0c2d36: /* original 6573, guest PC 0x0c0c2d36 */
if(!s->budget--) { s->failed_pc=0x0c0c2d36u; return 0; }
r[5]=r[7];
goto P_0c0c2d38;
P_0c0c2d38: /* original 6673, guest PC 0x0c0c2d38 */
if(!s->budget--) { s->failed_pc=0x0c0c2d38u; return 0; }
r[6]=r[7];
goto P_0c0c2d3a;
P_0c0c2d3a: /* original 4b0b, guest PC 0x0c0c2d3a */
if(!s->budget--) { s->failed_pc=0x0c0c2d3au; return 0; }
target=r[11];
r[16]=code_base|0x0c0c2d3eu;
r[4]+=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c2d3eu) { target=s->pc; goto dispatch; }
goto P_0c0c2d3e;
P_0c0c2d3c: /* original 34cc, guest PC 0x0c0c2d3c */
if(!s->budget--) { s->failed_pc=0x0c0c2d3cu; return 0; }
r[4]+=r[12];
goto P_0c0c2d3e;
P_0c0c2d3e: /* original a070, guest PC 0x0c0c2d3e */
if(!s->budget--) { s->failed_pc=0x0c0c2d3eu; return 0; }
goto P_0c0c2e22;
P_0c0c2d40: /* original 0009, guest PC 0x0c0c2d40 */
if(!s->budget--) { s->failed_pc=0x0c0c2d40u; return 0; }
goto P_0c0c2d42;
P_0c0c2d42: /* original e308, guest PC 0x0c0c2d42 */
if(!s->budget--) { s->failed_pc=0x0c0c2d42u; return 0; }
r[3]=0x00000008u;
goto P_0c0c2d44;
P_0c0c2d44: /* original 3433, guest PC 0x0c0c2d44 */
if(!s->budget--) { s->failed_pc=0x0c0c2d44u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=(int32_t)r[3])!=0);
goto P_0c0c2d46;
P_0c0c2d46: /* original 8941, guest PC 0x0c0c2d46 */
if(!s->budget--) { s->failed_pc=0x0c0c2d46u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c2dcc; }
goto P_0c0c2d48;
P_0c0c2d48: /* original c71c, guest PC 0x0c0c2d48 */
if(!s->budget--) { s->failed_pc=0x0c0c2d48u; return 0; }
r[0]=code_base|0x000c2dbcu;
goto P_0c0c2d4a;
P_0c0c2d4a: /* original ffe8, guest PC 0x0c0c2d4a */
if(!s->budget--) { s->failed_pc=0x0c0c2d4au; return 0; }
vf3_matrix_load(s,ram,15,r[14]);
goto P_0c0c2d4c;
P_0c0c2d4c: /* original f408, guest PC 0x0c0c2d4c */
if(!s->budget--) { s->failed_pc=0x0c0c2d4cu; return 0; }
vf3_matrix_load(s,ram,4,r[0]);
goto P_0c0c2d4e;
P_0c0c2d4e: /* original 52e1, guest PC 0x0c0c2d4e */
if(!s->budget--) { s->failed_pc=0x0c0c2d4eu; return 0; }
r[2]=read(ram,r[14]+4,4);
goto P_0c0c2d50;
P_0c0c2d50: /* original ff45, guest PC 0x0c0c2d50 */
if(!s->budget--) { s->failed_pc=0x0c0c2d50u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[15])>as_float(fr[4]))!=0);
goto P_0c0c2d52;
P_0c0c2d52: /* original 1f21, guest PC 0x0c0c2d52 */
if(!s->budget--) { s->failed_pc=0x0c0c2d52u; return 0; }
write(ram,r[15]+4,r[2],4);
goto P_0c0c2d54;
P_0c0c2d54: /* original 8b65, guest PC 0x0c0c2d54 */
if(!s->budget--) { s->failed_pc=0x0c0c2d54u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c2e22; }
goto P_0c0c2d56;
P_0c0c2d56: /* original f39d, guest PC 0x0c0c2d56 */
if(!s->budget--) { s->failed_pc=0x0c0c2d56u; return 0; }
fr[3]=0x3f800000u;
goto P_0c0c2d58;
P_0c0c2d58: /* original f3f1, guest PC 0x0c0c2d58 */
if(!s->budget--) { s->failed_pc=0x0c0c2d58u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[15],r[18],'-');
goto P_0c0c2d5a;
P_0c0c2d5a: /* original c719, guest PC 0x0c0c2d5a */
if(!s->budget--) { s->failed_pc=0x0c0c2d5au; return 0; }
r[0]=code_base|0x000c2dc0u;
goto P_0c0c2d5c;
P_0c0c2d5c: /* original 64c3, guest PC 0x0c0c2d5c */
if(!s->budget--) { s->failed_pc=0x0c0c2d5cu; return 0; }
r[4]=r[12];
goto P_0c0c2d5e;
P_0c0c2d5e: /* original f6fc, guest PC 0x0c0c2d5e */
if(!s->budget--) { s->failed_pc=0x0c0c2d5eu; return 0; }
vf3_matrix_move(s,6,15);
goto P_0c0c2d60;
P_0c0c2d60: /* original e600, guest PC 0x0c0c2d60 */
if(!s->budget--) { s->failed_pc=0x0c0c2d60u; return 0; }
r[6]=0x00000000u;
goto P_0c0c2d62;
P_0c0c2d62: /* original ff3a, guest PC 0x0c0c2d62 */
if(!s->budget--) { s->failed_pc=0x0c0c2d62u; return 0; }
vf3_matrix_store(s,ram,3,r[15]);
goto P_0c0c2d64;
P_0c0c2d64: /* original f208, guest PC 0x0c0c2d64 */
if(!s->budget--) { s->failed_pc=0x0c0c2d64u; return 0; }
vf3_matrix_load(s,ram,2,r[0]);
goto P_0c0c2d66;
P_0c0c2d66: /* original c717, guest PC 0x0c0c2d66 */
if(!s->budget--) { s->failed_pc=0x0c0c2d66u; return 0; }
r[0]=code_base|0x000c2dc4u;
goto P_0c0c2d68;
P_0c0c2d68: /* original f108, guest PC 0x0c0c2d68 */
if(!s->budget--) { s->failed_pc=0x0c0c2d68u; return 0; }
vf3_matrix_load(s,ram,1,r[0]);
goto P_0c0c2d6a;
P_0c0c2d6a: /* original f43c, guest PC 0x0c0c2d6a */
if(!s->budget--) { s->failed_pc=0x0c0c2d6au; return 0; }
vf3_matrix_move(s,4,3);
goto P_0c0c2d6c;
P_0c0c2d6c: /* original f53c, guest PC 0x0c0c2d6c */
if(!s->budget--) { s->failed_pc=0x0c0c2d6cu; return 0; }
vf3_matrix_move(s,5,3);
goto P_0c0c2d6e;
P_0c0c2d6e: /* original f412, guest PC 0x0c0c2d6e */
if(!s->budget--) { s->failed_pc=0x0c0c2d6eu; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[1],r[18],'*');
goto P_0c0c2d70;
P_0c0c2d70: /* original f522, guest PC 0x0c0c2d70 */
if(!s->budget--) { s->failed_pc=0x0c0c2d70u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[2],r[18],'*');
goto P_0c0c2d72;
P_0c0c2d72: /* original 950e, guest PC 0x0c0c2d72 */
if(!s->budget--) { s->failed_pc=0x0c0c2d72u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c2d92u,2);
goto P_0c0c2d74;
P_0c0c2d74: /* original b05d, guest PC 0x0c0c2d74 */
if(!s->budget--) { s->failed_pc=0x0c0c2d74u; return 0; }
target=code_base|0x0c0c2e32u; r[16]=code_base|0x0c0c2d78u;
r[4]+=0x00000058u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c2d78u) { target=s->pc; goto dispatch; }
goto P_0c0c2d78;
P_0c0c2d76: /* original 7458, guest PC 0x0c0c2d76 */
if(!s->budget--) { s->failed_pc=0x0c0c2d76u; return 0; }
r[4]+=0x00000058u;
goto P_0c0c2d78;
P_0c0c2d78: /* original c713, guest PC 0x0c0c2d78 */
if(!s->budget--) { s->failed_pc=0x0c0c2d78u; return 0; }
r[0]=code_base|0x000c2dc8u;
goto P_0c0c2d7a;
P_0c0c2d7a: /* original f308, guest PC 0x0c0c2d7a */
if(!s->budget--) { s->failed_pc=0x0c0c2d7au; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c0c2d7c;
P_0c0c2d7c: /* original ff30, guest PC 0x0c0c2d7c */
if(!s->budget--) { s->failed_pc=0x0c0c2d7cu; return 0; }
fr[15]=vf3_fpu_binary(fr[15],fr[3],r[18],'+');
goto P_0c0c2d7e;
P_0c0c2d7e: /* original fefa, guest PC 0x0c0c2d7e */
if(!s->budget--) { s->failed_pc=0x0c0c2d7eu; return 0; }
vf3_matrix_store(s,ram,15,r[14]);
goto P_0c0c2d80;
P_0c0c2d80: /* original 53f1, guest PC 0x0c0c2d80 */
if(!s->budget--) { s->failed_pc=0x0c0c2d80u; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c0c2d82;
P_0c0c2d82: /* original 73ff, guest PC 0x0c0c2d82 */
if(!s->budget--) { s->failed_pc=0x0c0c2d82u; return 0; }
r[3]+=0xffffffffu;
goto P_0c0c2d84;
P_0c0c2d84: /* original a04d, guest PC 0x0c0c2d84 */
if(!s->budget--) { s->failed_pc=0x0c0c2d84u; return 0; }
write(ram,r[14]+4,r[3],4);
goto P_0c0c2e22;
P_0c0c2d86: /* original 1e31, guest PC 0x0c0c2d86 */
if(!s->budget--) { s->failed_pc=0x0c0c2d86u; return 0; }
write(ram,r[14]+4,r[3],4);
if(!vf3_matrix_family(0x0c0c2d88u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0c2d88u; return 0; } return 1;
P_0c0c2dcc: /* original 6043, guest PC 0x0c0c2dcc */
if(!s->budget--) { s->failed_pc=0x0c0c2dccu; return 0; }
r[0]=r[4];
goto P_0c0c2dce;
P_0c0c2dce: /* original 8808, guest PC 0x0c0c2dce */
if(!s->budget--) { s->failed_pc=0x0c0c2dceu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000008u)!=0);
goto P_0c0c2dd0;
P_0c0c2dd0: /* original 8b0c, guest PC 0x0c0c2dd0 */
if(!s->budget--) { s->failed_pc=0x0c0c2dd0u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c2dec; }
goto P_0c0c2dd2;
P_0c0c2dd2: /* original d252, guest PC 0x0c0c2dd2 */
if(!s->budget--) { s->failed_pc=0x0c0c2dd2u; return 0; }
r[2]=read(ram,0x0c0c2f1cu,4);
goto P_0c0c2dd4;
P_0c0c2dd4: /* original 64c3, guest PC 0x0c0c2dd4 */
if(!s->budget--) { s->failed_pc=0x0c0c2dd4u; return 0; }
r[4]=r[12];
goto P_0c0c2dd6;
P_0c0c2dd6: /* original 420b, guest PC 0x0c0c2dd6 */
if(!s->budget--) { s->failed_pc=0x0c0c2dd6u; return 0; }
target=r[2];
r[16]=code_base|0x0c0c2ddau;
r[4]+=0x00000058u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c2ddau) { target=s->pc; goto dispatch; }
goto P_0c0c2dda;
P_0c0c2dd8: /* original 7458, guest PC 0x0c0c2dd8 */
if(!s->budget--) { s->failed_pc=0x0c0c2dd8u; return 0; }
r[4]+=0x00000058u;
goto P_0c0c2dda;
P_0c0c2dda: /* original 949b, guest PC 0x0c0c2dda */
if(!s->budget--) { s->failed_pc=0x0c0c2ddau; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c2f14u,2);
goto P_0c0c2ddc;
P_0c0c2ddc: /* original e71f, guest PC 0x0c0c2ddc */
if(!s->budget--) { s->failed_pc=0x0c0c2ddcu; return 0; }
r[7]=0x0000001fu;
goto P_0c0c2dde;
P_0c0c2dde: /* original 6573, guest PC 0x0c0c2dde */
if(!s->budget--) { s->failed_pc=0x0c0c2ddeu; return 0; }
r[5]=r[7];
goto P_0c0c2de0;
P_0c0c2de0: /* original 6673, guest PC 0x0c0c2de0 */
if(!s->budget--) { s->failed_pc=0x0c0c2de0u; return 0; }
r[6]=r[7];
goto P_0c0c2de2;
P_0c0c2de2: /* original 4b0b, guest PC 0x0c0c2de2 */
if(!s->budget--) { s->failed_pc=0x0c0c2de2u; return 0; }
target=r[11];
r[16]=code_base|0x0c0c2de6u;
r[4]+=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c2de6u) { target=s->pc; goto dispatch; }
goto P_0c0c2de6;
P_0c0c2de4: /* original 34cc, guest PC 0x0c0c2de4 */
if(!s->budget--) { s->failed_pc=0x0c0c2de4u; return 0; }
r[4]+=r[12];
goto P_0c0c2de6;
P_0c0c2de6: /* original e31f, guest PC 0x0c0c2de6 */
if(!s->budget--) { s->failed_pc=0x0c0c2de6u; return 0; }
r[3]=0x0000001fu;
goto P_0c0c2de8;
P_0c0c2de8: /* original a01b, guest PC 0x0c0c2de8 */
if(!s->budget--) { s->failed_pc=0x0c0c2de8u; return 0; }
write(ram,r[14]+4,r[3],4);
goto P_0c0c2e22;
P_0c0c2dea: /* original 1e31, guest PC 0x0c0c2dea */
if(!s->budget--) { s->failed_pc=0x0c0c2deau; return 0; }
write(ram,r[14]+4,r[3],4);
goto P_0c0c2dec;
P_0c0c2dec: /* original 8809, guest PC 0x0c0c2dec */
if(!s->budget--) { s->failed_pc=0x0c0c2decu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000009u)!=0);
goto P_0c0c2dee;
P_0c0c2dee: /* original 8b0a, guest PC 0x0c0c2dee */
if(!s->budget--) { s->failed_pc=0x0c0c2deeu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c2e06; }
goto P_0c0c2df0;
P_0c0c2df0: /* original 66c3, guest PC 0x0c0c2df0 */
if(!s->budget--) { s->failed_pc=0x0c0c2df0u; return 0; }
r[6]=r[12];
goto P_0c0c2df2;
P_0c0c2df2: /* original e201, guest PC 0x0c0c2df2 */
if(!s->budget--) { s->failed_pc=0x0c0c2df2u; return 0; }
r[2]=0x00000001u;
goto P_0c0c2df4;
P_0c0c2df4: /* original 2f26, guest PC 0x0c0c2df4 */
if(!s->budget--) { s->failed_pc=0x0c0c2df4u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c2df6;
P_0c0c2df6: /* original e700, guest PC 0x0c0c2df6 */
if(!s->budget--) { s->failed_pc=0x0c0c2df6u; return 0; }
r[7]=0x00000000u;
goto P_0c0c2df8;
P_0c0c2df8: /* original 958d, guest PC 0x0c0c2df8 */
if(!s->budget--) { s->failed_pc=0x0c0c2df8u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c2f16u,2);
goto P_0c0c2dfa;
P_0c0c2dfa: /* original 7658, guest PC 0x0c0c2dfa */
if(!s->budget--) { s->failed_pc=0x0c0c2dfau; return 0; }
r[6]+=0x00000058u;
goto P_0c0c2dfc;
P_0c0c2dfc: /* original d148, guest PC 0x0c0c2dfc */
if(!s->budget--) { s->failed_pc=0x0c0c2dfcu; return 0; }
r[1]=read(ram,0x0c0c2f20u,4);
goto P_0c0c2dfe;
P_0c0c2dfe: /* original 410b, guest PC 0x0c0c2dfe */
if(!s->budget--) { s->failed_pc=0x0c0c2dfeu; return 0; }
target=r[1];
r[16]=code_base|0x0c0c2e02u;
r[4]=r[7];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c2e02u) { target=s->pc; goto dispatch; }
goto P_0c0c2e02;
P_0c0c2e00: /* original 6473, guest PC 0x0c0c2e00 */
if(!s->budget--) { s->failed_pc=0x0c0c2e00u; return 0; }
r[4]=r[7];
goto P_0c0c2e02;
P_0c0c2e02: /* original a00e, guest PC 0x0c0c2e02 */
if(!s->budget--) { s->failed_pc=0x0c0c2e02u; return 0; }
r[15]+=0x00000004u;
goto P_0c0c2e22;
P_0c0c2e04: /* original 7f04, guest PC 0x0c0c2e04 */
if(!s->budget--) { s->failed_pc=0x0c0c2e04u; return 0; }
r[15]+=0x00000004u;
goto P_0c0c2e06;
P_0c0c2e06: /* original e229, guest PC 0x0c0c2e06 */
if(!s->budget--) { s->failed_pc=0x0c0c2e06u; return 0; }
r[2]=0x00000029u;
goto P_0c0c2e08;
P_0c0c2e08: /* original 3423, guest PC 0x0c0c2e08 */
if(!s->budget--) { s->failed_pc=0x0c0c2e08u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=(int32_t)r[2])!=0);
goto P_0c0c2e0a;
P_0c0c2e0a: /* original 890a, guest PC 0x0c0c2e0a */
if(!s->budget--) { s->failed_pc=0x0c0c2e0au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c2e22; }
goto P_0c0c2e0c;
P_0c0c2e0c: /* original 5de1, guest PC 0x0c0c2e0c */
if(!s->budget--) { s->failed_pc=0x0c0c2e0cu; return 0; }
r[13]=read(ram,r[14]+4,4);
goto P_0c0c2e0e;
P_0c0c2e0e: /* original 2dd8, guest PC 0x0c0c2e0e */
if(!s->budget--) { s->failed_pc=0x0c0c2e0eu; return 0; }
r[17]=(r[17]&~1u)|(((r[13]&r[13])==0)!=0);
goto P_0c0c2e10;
P_0c0c2e10: /* original 8907, guest PC 0x0c0c2e10 */
if(!s->budget--) { s->failed_pc=0x0c0c2e10u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c2e22; }
goto P_0c0c2e12;
P_0c0c2e12: /* original 947f, guest PC 0x0c0c2e12 */
if(!s->budget--) { s->failed_pc=0x0c0c2e12u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c2f14u,2);
goto P_0c0c2e14;
P_0c0c2e14: /* original 65d3, guest PC 0x0c0c2e14 */
if(!s->budget--) { s->failed_pc=0x0c0c2e14u; return 0; }
r[5]=r[13];
goto P_0c0c2e16;
P_0c0c2e16: /* original 67d3, guest PC 0x0c0c2e16 */
if(!s->budget--) { s->failed_pc=0x0c0c2e16u; return 0; }
r[7]=r[13];
goto P_0c0c2e18;
P_0c0c2e18: /* original 66d3, guest PC 0x0c0c2e18 */
if(!s->budget--) { s->failed_pc=0x0c0c2e18u; return 0; }
r[6]=r[13];
goto P_0c0c2e1a;
P_0c0c2e1a: /* original 4b0b, guest PC 0x0c0c2e1a */
if(!s->budget--) { s->failed_pc=0x0c0c2e1au; return 0; }
target=r[11];
r[16]=code_base|0x0c0c2e1eu;
r[4]+=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c2e1eu) { target=s->pc; goto dispatch; }
goto P_0c0c2e1e;
P_0c0c2e1c: /* original 34cc, guest PC 0x0c0c2e1c */
if(!s->budget--) { s->failed_pc=0x0c0c2e1cu; return 0; }
r[4]+=r[12];
goto P_0c0c2e1e;
P_0c0c2e1e: /* original 7dff, guest PC 0x0c0c2e1e */
if(!s->budget--) { s->failed_pc=0x0c0c2e1eu; return 0; }
r[13]+=0xffffffffu;
goto P_0c0c2e20;
P_0c0c2e20: /* original 1ed1, guest PC 0x0c0c2e20 */
if(!s->budget--) { s->failed_pc=0x0c0c2e20u; return 0; }
write(ram,r[14]+4,r[13],4);
goto P_0c0c2e22;
P_0c0c2e22: /* original 7f08, guest PC 0x0c0c2e22 */
if(!s->budget--) { s->failed_pc=0x0c0c2e22u; return 0; }
r[15]+=0x00000008u;
goto P_0c0c2e24;
P_0c0c2e24: /* original 4f26, guest PC 0x0c0c2e24 */
if(!s->budget--) { s->failed_pc=0x0c0c2e24u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0c2e26;
P_0c0c2e26: /* original fff9, guest PC 0x0c0c2e26 */
if(!s->budget--) { s->failed_pc=0x0c0c2e26u; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0c2e28;
P_0c0c2e28: /* original 6bf6, guest PC 0x0c0c2e28 */
if(!s->budget--) { s->failed_pc=0x0c0c2e28u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0c2e2a;
P_0c0c2e2a: /* original 6cf6, guest PC 0x0c0c2e2a */
if(!s->budget--) { s->failed_pc=0x0c0c2e2au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0c2e2c;
P_0c0c2e2c: /* original 6df6, guest PC 0x0c0c2e2c */
if(!s->budget--) { s->failed_pc=0x0c0c2e2cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0c2e2e;
P_0c0c2e2e: /* original 000b, guest PC 0x0c0c2e2e */
if(!s->budget--) { s->failed_pc=0x0c0c2e2eu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0c2e30: /* original 6ef6, guest PC 0x0c0c2e30 */
if(!s->budget--) { s->failed_pc=0x0c0c2e30u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0c2e32;
P_0c0c2e32: /* original 2fe6, guest PC 0x0c0c2e32 */
if(!s->budget--) { s->failed_pc=0x0c0c2e32u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c2e34;
P_0c0c2e34: /* original e004, guest PC 0x0c0c2e34 */
if(!s->budget--) { s->failed_pc=0x0c0c2e34u; return 0; }
r[0]=0x00000004u;
goto P_0c0c2e36;
P_0c0c2e36: /* original 2fd6, guest PC 0x0c0c2e36 */
if(!s->budget--) { s->failed_pc=0x0c0c2e36u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c2e38;
P_0c0c2e38: /* original fffb, guest PC 0x0c0c2e38 */
if(!s->budget--) { s->failed_pc=0x0c0c2e38u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c0c2e3a;
P_0c0c2e3a: /* original 4f22, guest PC 0x0c0c2e3a */
if(!s->budget--) { s->failed_pc=0x0c0c2e3au; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0c2e3c;
P_0c0c2e3c: /* original 7ff4, guest PC 0x0c0c2e3c */
if(!s->budget--) { s->failed_pc=0x0c0c2e3cu; return 0; }
r[15]+=0xfffffff4u;
goto P_0c0c2e3e;
P_0c0c2e3e: /* original 1f52, guest PC 0x0c0c2e3e */
if(!s->budget--) { s->failed_pc=0x0c0c2e3eu; return 0; }
write(ram,r[15]+8,r[5],4);
goto P_0c0c2e40;
P_0c0c2e40: /* original ff4a, guest PC 0x0c0c2e40 */
if(!s->budget--) { s->failed_pc=0x0c0c2e40u; return 0; }
vf3_matrix_store(s,ram,4,r[15]);
goto P_0c0c2e42;
P_0c0c2e42: /* original ff57, guest PC 0x0c0c2e42 */
if(!s->budget--) { s->failed_pc=0x0c0c2e42u; return 0; }
vf3_matrix_store(s,ram,5,r[15]+r[0]);
goto P_0c0c2e44;
P_0c0c2e44: /* original d337, guest PC 0x0c0c2e44 */
if(!s->budget--) { s->failed_pc=0x0c0c2e44u; return 0; }
r[3]=read(ram,0x0c0c2f24u,4);
goto P_0c0c2e46;
P_0c0c2e46: /* original 430b, guest PC 0x0c0c2e46 */
if(!s->budget--) { s->failed_pc=0x0c0c2e46u; return 0; }
target=r[3];
r[16]=code_base|0x0c0c2e4au;
vf3_matrix_move(s,15,6);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c2e4au) { target=s->pc; goto dispatch; }
goto P_0c0c2e4a;
P_0c0c2e48: /* original ff6c, guest PC 0x0c0c2e48 */
if(!s->budget--) { s->failed_pc=0x0c0c2e48u; return 0; }
vf3_matrix_move(s,15,6);
goto P_0c0c2e4a;
P_0c0c2e4a: /* original 6e03, guest PC 0x0c0c2e4a */
if(!s->budget--) { s->failed_pc=0x0c0c2e4au; return 0; }
r[14]=r[0];
goto P_0c0c2e4c;
P_0c0c2e4c: /* original 2ee8, guest PC 0x0c0c2e4c */
if(!s->budget--) { s->failed_pc=0x0c0c2e4cu; return 0; }
r[17]=(r[17]&~1u)|(((r[14]&r[14])==0)!=0);
goto P_0c0c2e4e;
P_0c0c2e4e: /* original 8b01, guest PC 0x0c0c2e4e */
if(!s->budget--) { s->failed_pc=0x0c0c2e4eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c2e54; }
goto P_0c0c2e50;
P_0c0c2e50: /* original a05a, guest PC 0x0c0c2e50 */
if(!s->budget--) { s->failed_pc=0x0c0c2e50u; return 0; }
r[0]=0xffffffffu;
goto P_0c0c2f08;
P_0c0c2e52: /* original e0ff, guest PC 0x0c0c2e52 */
if(!s->budget--) { s->failed_pc=0x0c0c2e52u; return 0; }
r[0]=0xffffffffu;
goto P_0c0c2e54;
P_0c0c2e54: /* original f3f8, guest PC 0x0c0c2e54 */
if(!s->budget--) { s->failed_pc=0x0c0c2e54u; return 0; }
vf3_matrix_load(s,ram,3,r[15]);
goto P_0c0c2e56;
P_0c0c2e56: /* original e004, guest PC 0x0c0c2e56 */
if(!s->budget--) { s->failed_pc=0x0c0c2e56u; return 0; }
r[0]=0x00000004u;
goto P_0c0c2e58;
P_0c0c2e58: /* original f2f6, guest PC 0x0c0c2e58 */
if(!s->budget--) { s->failed_pc=0x0c0c2e58u; return 0; }
vf3_matrix_load(s,ram,2,r[15]+r[0]);
goto P_0c0c2e5a;
P_0c0c2e5a: /* original f33d, guest PC 0x0c0c2e5a */
if(!s->budget--) { s->failed_pc=0x0c0c2e5au; return 0; }
r[53]=truncate_float(fr[3]);
goto P_0c0c2e5c;
P_0c0c2e5c: /* original 055a, guest PC 0x0c0c2e5c */
if(!s->budget--) { s->failed_pc=0x0c0c2e5cu; return 0; }
r[5]=r[53];
goto P_0c0c2e5e;
P_0c0c2e5e: /* original f23d, guest PC 0x0c0c2e5e */
if(!s->budget--) { s->failed_pc=0x0c0c2e5eu; return 0; }
r[53]=truncate_float(fr[2]);
goto P_0c0c2e60;
P_0c0c2e60: /* original 4521, guest PC 0x0c0c2e60 */
if(!s->budget--) { s->failed_pc=0x0c0c2e60u; return 0; }
r[17]=(r[17]&~1u)|((r[5]&1)!=0);
r[5]=(uint32_t)((int32_t)r[5]>>1);
goto P_0c0c2e62;
P_0c0c2e62: /* original 045a, guest PC 0x0c0c2e62 */
if(!s->budget--) { s->failed_pc=0x0c0c2e62u; return 0; }
r[4]=r[53];
goto P_0c0c2e64;
P_0c0c2e64: /* original 4521, guest PC 0x0c0c2e64 */
if(!s->budget--) { s->failed_pc=0x0c0c2e64u; return 0; }
r[17]=(r[17]&~1u)|((r[5]&1)!=0);
r[5]=(uint32_t)((int32_t)r[5]>>1);
goto P_0c0c2e66;
P_0c0c2e66: /* original 4521, guest PC 0x0c0c2e66 */
if(!s->budget--) { s->failed_pc=0x0c0c2e66u; return 0; }
r[17]=(r[17]&~1u)|((r[5]&1)!=0);
r[5]=(uint32_t)((int32_t)r[5]>>1);
goto P_0c0c2e68;
P_0c0c2e68: /* original 6053, guest PC 0x0c0c2e68 */
if(!s->budget--) { s->failed_pc=0x0c0c2e68u; return 0; }
r[0]=r[5];
goto P_0c0c2e6a;
P_0c0c2e6a: /* original 81e3, guest PC 0x0c0c2e6a */
if(!s->budget--) { s->failed_pc=0x0c0c2e6au; return 0; }
write(ram,r[14]+6,r[0],2);
goto P_0c0c2e6c;
P_0c0c2e6c: /* original 4421, guest PC 0x0c0c2e6c */
if(!s->budget--) { s->failed_pc=0x0c0c2e6cu; return 0; }
r[17]=(r[17]&~1u)|((r[4]&1)!=0);
r[4]=(uint32_t)((int32_t)r[4]>>1);
goto P_0c0c2e6e;
P_0c0c2e6e: /* original 4421, guest PC 0x0c0c2e6e */
if(!s->budget--) { s->failed_pc=0x0c0c2e6eu; return 0; }
r[17]=(r[17]&~1u)|((r[4]&1)!=0);
r[4]=(uint32_t)((int32_t)r[4]>>1);
goto P_0c0c2e70;
P_0c0c2e70: /* original 4421, guest PC 0x0c0c2e70 */
if(!s->budget--) { s->failed_pc=0x0c0c2e70u; return 0; }
r[17]=(r[17]&~1u)|((r[4]&1)!=0);
r[4]=(uint32_t)((int32_t)r[4]>>1);
goto P_0c0c2e72;
P_0c0c2e72: /* original 6043, guest PC 0x0c0c2e72 */
if(!s->budget--) { s->failed_pc=0x0c0c2e72u; return 0; }
r[0]=r[4];
goto P_0c0c2e74;
P_0c0c2e74: /* original 81e4, guest PC 0x0c0c2e74 */
if(!s->budget--) { s->failed_pc=0x0c0c2e74u; return 0; }
write(ram,r[14]+8,r[0],2);
goto P_0c0c2e76;
P_0c0c2e76: /* original 85f4, guest PC 0x0c0c2e76 */
if(!s->budget--) { s->failed_pc=0x0c0c2e76u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[15]+8,2);
goto P_0c0c2e78;
P_0c0c2e78: /* original 81e1, guest PC 0x0c0c2e78 */
if(!s->budget--) { s->failed_pc=0x0c0c2e78u; return 0; }
write(ram,r[14]+2,r[0],2);
goto P_0c0c2e7a;
P_0c0c2e7a: /* original d32b, guest PC 0x0c0c2e7a */
if(!s->budget--) { s->failed_pc=0x0c0c2e7au; return 0; }
r[3]=read(ram,0x0c0c2f28u,4);
goto P_0c0c2e7c;
P_0c0c2e7c: /* original 430b, guest PC 0x0c0c2e7c */
if(!s->budget--) { s->failed_pc=0x0c0c2e7cu; return 0; }
target=r[3];
r[16]=code_base|0x0c0c2e80u;
r[4]=read(ram,r[15]+8,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c2e80u) { target=s->pc; goto dispatch; }
goto P_0c0c2e80;
P_0c0c2e7e: /* original 54f2, guest PC 0x0c0c2e7e */
if(!s->budget--) { s->failed_pc=0x0c0c2e7eu; return 0; }
r[4]=read(ram,r[15]+8,4);
goto P_0c0c2e80;
P_0c0c2e80: /* original 6d03, guest PC 0x0c0c2e80 */
if(!s->budget--) { s->failed_pc=0x0c0c2e80u; return 0; }
r[13]=r[0];
goto P_0c0c2e82;
P_0c0c2e82: /* original e008, guest PC 0x0c0c2e82 */
if(!s->budget--) { s->failed_pc=0x0c0c2e82u; return 0; }
r[0]=0x00000008u;
goto P_0c0c2e84;
P_0c0c2e84: /* original f5d6, guest PC 0x0c0c2e84 */
if(!s->budget--) { s->failed_pc=0x0c0c2e84u; return 0; }
vf3_matrix_load(s,ram,5,r[13]+r[0]);
goto P_0c0c2e86;
P_0c0c2e86: /* original e00c, guest PC 0x0c0c2e86 */
if(!s->budget--) { s->failed_pc=0x0c0c2e86u; return 0; }
r[0]=0x0000000cu;
goto P_0c0c2e88;
P_0c0c2e88: /* original f4d6, guest PC 0x0c0c2e88 */
if(!s->budget--) { s->failed_pc=0x0c0c2e88u; return 0; }
vf3_matrix_load(s,ram,4,r[13]+r[0]);
goto P_0c0c2e8a;
P_0c0c2e8a: /* original f5f2, guest PC 0x0c0c2e8a */
if(!s->budget--) { s->failed_pc=0x0c0c2e8au; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[15],r[18],'*');
goto P_0c0c2e8c;
P_0c0c2e8c: /* original f4f2, guest PC 0x0c0c2e8c */
if(!s->budget--) { s->failed_pc=0x0c0c2e8cu; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[15],r[18],'*');
goto P_0c0c2e8e;
P_0c0c2e8e: /* original f53d, guest PC 0x0c0c2e8e */
if(!s->budget--) { s->failed_pc=0x0c0c2e8eu; return 0; }
r[53]=truncate_float(fr[5]);
goto P_0c0c2e90;
P_0c0c2e90: /* original 005a, guest PC 0x0c0c2e90 */
if(!s->budget--) { s->failed_pc=0x0c0c2e90u; return 0; }
r[0]=r[53];
goto P_0c0c2e92;
P_0c0c2e92: /* original f43d, guest PC 0x0c0c2e92 */
if(!s->budget--) { s->failed_pc=0x0c0c2e92u; return 0; }
r[53]=truncate_float(fr[4]);
goto P_0c0c2e94;
P_0c0c2e94: /* original 600d, guest PC 0x0c0c2e94 */
if(!s->budget--) { s->failed_pc=0x0c0c2e94u; return 0; }
r[0]=r[0]&65535u;
goto P_0c0c2e96;
P_0c0c2e96: /* original 4009, guest PC 0x0c0c2e96 */
if(!s->budget--) { s->failed_pc=0x0c0c2e96u; return 0; }
r[0]>>=2;
goto P_0c0c2e98;
P_0c0c2e98: /* original 4001, guest PC 0x0c0c2e98 */
if(!s->budget--) { s->failed_pc=0x0c0c2e98u; return 0; }
r[17]=(r[17]&~1u)|((r[0]&1)!=0);
r[0]>>=1;
goto P_0c0c2e9a;
P_0c0c2e9a: /* original 81e5, guest PC 0x0c0c2e9a */
if(!s->budget--) { s->failed_pc=0x0c0c2e9au; return 0; }
write(ram,r[14]+10,r[0],2);
goto P_0c0c2e9c;
P_0c0c2e9c: /* original 005a, guest PC 0x0c0c2e9c */
if(!s->budget--) { s->failed_pc=0x0c0c2e9cu; return 0; }
r[0]=r[53];
goto P_0c0c2e9e;
P_0c0c2e9e: /* original 600d, guest PC 0x0c0c2e9e */
if(!s->budget--) { s->failed_pc=0x0c0c2e9eu; return 0; }
r[0]=r[0]&65535u;
goto P_0c0c2ea0;
P_0c0c2ea0: /* original 4009, guest PC 0x0c0c2ea0 */
if(!s->budget--) { s->failed_pc=0x0c0c2ea0u; return 0; }
r[0]>>=2;
goto P_0c0c2ea2;
P_0c0c2ea2: /* original 4001, guest PC 0x0c0c2ea2 */
if(!s->budget--) { s->failed_pc=0x0c0c2ea2u; return 0; }
r[17]=(r[17]&~1u)|((r[0]&1)!=0);
r[0]>>=1;
goto P_0c0c2ea4;
P_0c0c2ea4: /* original 81e6, guest PC 0x0c0c2ea4 */
if(!s->budget--) { s->failed_pc=0x0c0c2ea4u; return 0; }
write(ram,r[14]+12,r[0],2);
goto P_0c0c2ea6;
P_0c0c2ea6: /* original e010, guest PC 0x0c0c2ea6 */
if(!s->budget--) { s->failed_pc=0x0c0c2ea6u; return 0; }
r[0]=0x00000010u;
goto P_0c0c2ea8;
P_0c0c2ea8: /* original f3d6, guest PC 0x0c0c2ea8 */
if(!s->budget--) { s->failed_pc=0x0c0c2ea8u; return 0; }
vf3_matrix_load(s,ram,3,r[13]+r[0]);
goto P_0c0c2eaa;
P_0c0c2eaa: /* original e014, guest PC 0x0c0c2eaa */
if(!s->budget--) { s->failed_pc=0x0c0c2eaau; return 0; }
r[0]=0x00000014u;
goto P_0c0c2eac;
P_0c0c2eac: /* original f65c, guest PC 0x0c0c2eac */
if(!s->budget--) { s->failed_pc=0x0c0c2eacu; return 0; }
vf3_matrix_move(s,6,5);
goto P_0c0c2eae;
P_0c0c2eae: /* original f632, guest PC 0x0c0c2eae */
if(!s->budget--) { s->failed_pc=0x0c0c2eaeu; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[3],r[18],'*');
goto P_0c0c2eb0;
P_0c0c2eb0: /* original f3d6, guest PC 0x0c0c2eb0 */
if(!s->budget--) { s->failed_pc=0x0c0c2eb0u; return 0; }
vf3_matrix_load(s,ram,3,r[13]+r[0]);
goto P_0c0c2eb2;
P_0c0c2eb2: /* original f74c, guest PC 0x0c0c2eb2 */
if(!s->budget--) { s->failed_pc=0x0c0c2eb2u; return 0; }
vf3_matrix_move(s,7,4);
goto P_0c0c2eb4;
P_0c0c2eb4: /* original c71d, guest PC 0x0c0c2eb4 */
if(!s->budget--) { s->failed_pc=0x0c0c2eb4u; return 0; }
r[0]=code_base|0x000c2f2cu;
goto P_0c0c2eb6;
P_0c0c2eb6: /* original f732, guest PC 0x0c0c2eb6 */
if(!s->budget--) { s->failed_pc=0x0c0c2eb6u; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[3],r[18],'*');
goto P_0c0c2eb8;
P_0c0c2eb8: /* original f308, guest PC 0x0c0c2eb8 */
if(!s->budget--) { s->failed_pc=0x0c0c2eb8u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c0c2eba;
P_0c0c2eba: /* original f8fc, guest PC 0x0c0c2eba */
if(!s->budget--) { s->failed_pc=0x0c0c2ebau; return 0; }
vf3_matrix_move(s,8,15);
goto P_0c0c2ebc;
P_0c0c2ebc: /* original e004, guest PC 0x0c0c2ebc */
if(!s->budget--) { s->failed_pc=0x0c0c2ebcu; return 0; }
r[0]=0x00000004u;
goto P_0c0c2ebe;
P_0c0c2ebe: /* original f832, guest PC 0x0c0c2ebe */
if(!s->budget--) { s->failed_pc=0x0c0c2ebeu; return 0; }
fr[8]=vf3_fpu_binary(fr[8],fr[3],r[18],'*');
goto P_0c0c2ec0;
P_0c0c2ec0: /* original d31b, guest PC 0x0c0c2ec0 */
if(!s->budget--) { s->failed_pc=0x0c0c2ec0u; return 0; }
r[3]=read(ram,0x0c0c2f30u,4);
goto P_0c0c2ec2;
P_0c0c2ec2: /* original 64e3, guest PC 0x0c0c2ec2 */
if(!s->budget--) { s->failed_pc=0x0c0c2ec2u; return 0; }
r[4]=r[14];
goto P_0c0c2ec4;
P_0c0c2ec4: /* original f4f8, guest PC 0x0c0c2ec4 */
if(!s->budget--) { s->failed_pc=0x0c0c2ec4u; return 0; }
vf3_matrix_load(s,ram,4,r[15]);
goto P_0c0c2ec6;
P_0c0c2ec6: /* original f5f6, guest PC 0x0c0c2ec6 */
if(!s->budget--) { s->failed_pc=0x0c0c2ec6u; return 0; }
vf3_matrix_load(s,ram,5,r[15]+r[0]);
goto P_0c0c2ec8;
P_0c0c2ec8: /* original 430b, guest PC 0x0c0c2ec8 */
if(!s->budget--) { s->failed_pc=0x0c0c2ec8u; return 0; }
target=r[3];
r[16]=code_base|0x0c0c2eccu;
r[4]+=0x00000010u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c2eccu) { target=s->pc; goto dispatch; }
goto P_0c0c2ecc;
P_0c0c2eca: /* original 7410, guest PC 0x0c0c2eca */
if(!s->budget--) { s->failed_pc=0x0c0c2ecau; return 0; }
r[4]+=0x00000010u;
goto P_0c0c2ecc;
P_0c0c2ecc: /* original e014, guest PC 0x0c0c2ecc */
if(!s->budget--) { s->failed_pc=0x0c0c2eccu; return 0; }
r[0]=0x00000014u;
goto P_0c0c2ece;
P_0c0c2ece: /* original d319, guest PC 0x0c0c2ece */
if(!s->budget--) { s->failed_pc=0x0c0c2eceu; return 0; }
r[3]=read(ram,0x0c0c2f34u,4);
goto P_0c0c2ed0;
P_0c0c2ed0: /* original f9d6, guest PC 0x0c0c2ed0 */
if(!s->budget--) { s->failed_pc=0x0c0c2ed0u; return 0; }
vf3_matrix_load(s,ram,9,r[13]+r[0]);
goto P_0c0c2ed2;
P_0c0c2ed2: /* original e010, guest PC 0x0c0c2ed2 */
if(!s->budget--) { s->failed_pc=0x0c0c2ed2u; return 0; }
r[0]=0x00000010u;
goto P_0c0c2ed4;
P_0c0c2ed4: /* original f8d6, guest PC 0x0c0c2ed4 */
if(!s->budget--) { s->failed_pc=0x0c0c2ed4u; return 0; }
vf3_matrix_load(s,ram,8,r[13]+r[0]);
goto P_0c0c2ed6;
P_0c0c2ed6: /* original e00c, guest PC 0x0c0c2ed6 */
if(!s->budget--) { s->failed_pc=0x0c0c2ed6u; return 0; }
r[0]=0x0000000cu;
goto P_0c0c2ed8;
P_0c0c2ed8: /* original f7d6, guest PC 0x0c0c2ed8 */
if(!s->budget--) { s->failed_pc=0x0c0c2ed8u; return 0; }
vf3_matrix_load(s,ram,7,r[13]+r[0]);
goto P_0c0c2eda;
P_0c0c2eda: /* original e008, guest PC 0x0c0c2eda */
if(!s->budget--) { s->failed_pc=0x0c0c2edau; return 0; }
r[0]=0x00000008u;
goto P_0c0c2edc;
P_0c0c2edc: /* original f6d6, guest PC 0x0c0c2edc */
if(!s->budget--) { s->failed_pc=0x0c0c2edcu; return 0; }
vf3_matrix_load(s,ram,6,r[13]+r[0]);
goto P_0c0c2ede;
P_0c0c2ede: /* original e004, guest PC 0x0c0c2ede */
if(!s->budget--) { s->failed_pc=0x0c0c2edeu; return 0; }
r[0]=0x00000004u;
goto P_0c0c2ee0;
P_0c0c2ee0: /* original f4d8, guest PC 0x0c0c2ee0 */
if(!s->budget--) { s->failed_pc=0x0c0c2ee0u; return 0; }
vf3_matrix_load(s,ram,4,r[13]);
goto P_0c0c2ee2;
P_0c0c2ee2: /* original 64e3, guest PC 0x0c0c2ee2 */
if(!s->budget--) { s->failed_pc=0x0c0c2ee2u; return 0; }
r[4]=r[14];
goto P_0c0c2ee4;
P_0c0c2ee4: /* original f5d6, guest PC 0x0c0c2ee4 */
if(!s->budget--) { s->failed_pc=0x0c0c2ee4u; return 0; }
vf3_matrix_load(s,ram,5,r[13]+r[0]);
goto P_0c0c2ee6;
P_0c0c2ee6: /* original 430b, guest PC 0x0c0c2ee6 */
if(!s->budget--) { s->failed_pc=0x0c0c2ee6u; return 0; }
target=r[3];
r[16]=code_base|0x0c0c2eeau;
r[4]+=0x00000010u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c2eeau) { target=s->pc; goto dispatch; }
goto P_0c0c2eea;
P_0c0c2ee8: /* original 7410, guest PC 0x0c0c2ee8 */
if(!s->budget--) { s->failed_pc=0x0c0c2ee8u; return 0; }
r[4]+=0x00000010u;
goto P_0c0c2eea;
P_0c0c2eea: /* original 50d8, guest PC 0x0c0c2eea */
if(!s->budget--) { s->failed_pc=0x0c0c2eeau; return 0; }
r[0]=read(ram,r[13]+32,4);
goto P_0c0c2eec;
P_0c0c2eec: /* original e400, guest PC 0x0c0c2eec */
if(!s->budget--) { s->failed_pc=0x0c0c2eecu; return 0; }
r[4]=0x00000000u;
goto P_0c0c2eee;
P_0c0c2eee: /* original d112, guest PC 0x0c0c2eee */
if(!s->budget--) { s->failed_pc=0x0c0c2eeeu; return 0; }
r[1]=read(ram,0x0c0c2f38u,4);
goto P_0c0c2ef0;
P_0c0c2ef0: /* original 4000, guest PC 0x0c0c2ef0 */
if(!s->budget--) { s->failed_pc=0x0c0c2ef0u; return 0; }
r[17]=(r[17]&~1u)|((r[0]>>31)!=0);
r[0]<<=1;
goto P_0c0c2ef2;
P_0c0c2ef2: /* original 001d, guest PC 0x0c0c2ef2 */
if(!s->budget--) { s->failed_pc=0x0c0c2ef2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[1]+r[0],2);
goto P_0c0c2ef4;
P_0c0c2ef4: /* original 81e2, guest PC 0x0c0c2ef4 */
if(!s->budget--) { s->failed_pc=0x0c0c2ef4u; return 0; }
write(ram,r[14]+4,r[0],2);
goto P_0c0c2ef6;
P_0c0c2ef6: /* original 600d, guest PC 0x0c0c2ef6 */
if(!s->budget--) { s->failed_pc=0x0c0c2ef6u; return 0; }
r[0]=r[0]&65535u;
goto P_0c0c2ef8;
P_0c0c2ef8: /* original 1e04, guest PC 0x0c0c2ef8 */
if(!s->budget--) { s->failed_pc=0x0c0c2ef8u; return 0; }
write(ram,r[14]+16,r[0],4);
goto P_0c0c2efa;
P_0c0c2efa: /* original 60e1, guest PC 0x0c0c2efa */
if(!s->budget--) { s->failed_pc=0x0c0c2efau; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[14],2);
r[0]=tmp;
goto P_0c0c2efc;
P_0c0c2efc: /* original cb01, guest PC 0x0c0c2efc */
if(!s->budget--) { s->failed_pc=0x0c0c2efcu; return 0; }
r[0]|=1u;
goto P_0c0c2efe;
P_0c0c2efe: /* original 2e01, guest PC 0x0c0c2efe */
if(!s->budget--) { s->failed_pc=0x0c0c2efeu; return 0; }
write(ram,r[14],r[0],2);
goto P_0c0c2f00;
P_0c0c2f00: /* original 6043, guest PC 0x0c0c2f00 */
if(!s->budget--) { s->failed_pc=0x0c0c2f00u; return 0; }
r[0]=r[4];
goto P_0c0c2f02;
P_0c0c2f02: /* original 9309, guest PC 0x0c0c2f02 */
if(!s->budget--) { s->failed_pc=0x0c0c2f02u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c2f18u,2);
goto P_0c0c2f04;
P_0c0c2f04: /* original 1e3f, guest PC 0x0c0c2f04 */
if(!s->budget--) { s->failed_pc=0x0c0c2f04u; return 0; }
write(ram,r[14]+60,r[3],4);
goto P_0c0c2f06;
P_0c0c2f06: /* original 1e4e, guest PC 0x0c0c2f06 */
if(!s->budget--) { s->failed_pc=0x0c0c2f06u; return 0; }
write(ram,r[14]+56,r[4],4);
goto P_0c0c2f08;
P_0c0c2f08: /* original 7f0c, guest PC 0x0c0c2f08 */
if(!s->budget--) { s->failed_pc=0x0c0c2f08u; return 0; }
r[15]+=0x0000000cu;
goto P_0c0c2f0a;
P_0c0c2f0a: /* original 4f26, guest PC 0x0c0c2f0a */
if(!s->budget--) { s->failed_pc=0x0c0c2f0au; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0c2f0c;
P_0c0c2f0c: /* original fff9, guest PC 0x0c0c2f0c */
if(!s->budget--) { s->failed_pc=0x0c0c2f0cu; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0c2f0e;
P_0c0c2f0e: /* original 6df6, guest PC 0x0c0c2f0e */
if(!s->budget--) { s->failed_pc=0x0c0c2f0eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0c2f10;
P_0c0c2f10: /* original 000b, guest PC 0x0c0c2f10 */
if(!s->budget--) { s->failed_pc=0x0c0c2f10u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0c2f12: /* original 6ef6, guest PC 0x0c0c2f12 */
if(!s->budget--) { s->failed_pc=0x0c0c2f12u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0c2f14u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0c2f14u; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
