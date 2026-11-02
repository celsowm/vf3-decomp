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
int vf3_away_batch256_adapter_0(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c0955b0u: goto P_0c0955b0;
case 0x0c0955b2u: goto P_0c0955b2;
case 0x0c0955b4u: goto P_0c0955b4;
case 0x0c0955b6u: goto P_0c0955b6;
case 0x0c0955b8u: goto P_0c0955b8;
case 0x0c0955bau: goto P_0c0955ba;
case 0x0c0955bcu: goto P_0c0955bc;
case 0x0c0955beu: goto P_0c0955be;
case 0x0c0955c0u: goto P_0c0955c0;
case 0x0c0955c2u: goto P_0c0955c2;
case 0x0c0955c4u: goto P_0c0955c4;
case 0x0c0955c6u: goto P_0c0955c6;
case 0x0c0955c8u: goto P_0c0955c8;
case 0x0c0955cau: goto P_0c0955ca;
case 0x0c0955ccu: goto P_0c0955cc;
case 0x0c0955ceu: goto P_0c0955ce;
case 0x0c0955d0u: goto P_0c0955d0;
case 0x0c0955d2u: goto P_0c0955d2;
case 0x0c0955d4u: goto P_0c0955d4;
case 0x0c0955d6u: goto P_0c0955d6;
case 0x0c0955d8u: goto P_0c0955d8;
case 0x0c0955dau: goto P_0c0955da;
case 0x0c0955dcu: goto P_0c0955dc;
case 0x0c0955deu: goto P_0c0955de;
case 0x0c0955e0u: goto P_0c0955e0;
case 0x0c0955e2u: goto P_0c0955e2;
case 0x0c0955e4u: goto P_0c0955e4;
case 0x0c0955e6u: goto P_0c0955e6;
case 0x0c0955e8u: goto P_0c0955e8;
case 0x0c0955eau: goto P_0c0955ea;
case 0x0c0955ecu: goto P_0c0955ec;
case 0x0c0955eeu: goto P_0c0955ee;
case 0x0c0955f0u: goto P_0c0955f0;
case 0x0c0955f2u: goto P_0c0955f2;
case 0x0c0955f4u: goto P_0c0955f4;
case 0x0c0955f6u: goto P_0c0955f6;
case 0x0c0955f8u: goto P_0c0955f8;
case 0x0c0955fau: goto P_0c0955fa;
case 0x0c0955fcu: goto P_0c0955fc;
case 0x0c0955feu: goto P_0c0955fe;
case 0x0c095600u: goto P_0c095600;
case 0x0c095602u: goto P_0c095602;
case 0x0c0c9db6u: goto P_0c0c9db6;
case 0x0c0c9db8u: goto P_0c0c9db8;
case 0x0c0c9dbau: goto P_0c0c9dba;
case 0x0c0c9dbcu: goto P_0c0c9dbc;
case 0x0c0c9dbeu: goto P_0c0c9dbe;
case 0x0c0c9dc0u: goto P_0c0c9dc0;
case 0x0c0c9dc2u: goto P_0c0c9dc2;
case 0x0c0c9dc4u: goto P_0c0c9dc4;
case 0x0c0c9dc6u: goto P_0c0c9dc6;
case 0x0c0c9dc8u: goto P_0c0c9dc8;
case 0x0c0c9dcau: goto P_0c0c9dca;
case 0x0c0c9dccu: goto P_0c0c9dcc;
case 0x0c0c9dceu: goto P_0c0c9dce;
case 0x0c0c9dd0u: goto P_0c0c9dd0;
case 0x0c0c9dd2u: goto P_0c0c9dd2;
case 0x0c0c9dd4u: goto P_0c0c9dd4;
case 0x0c0c9dd6u: goto P_0c0c9dd6;
case 0x0c0c9dd8u: goto P_0c0c9dd8;
case 0x0c0c9ddau: goto P_0c0c9dda;
case 0x0c0c9ddcu: goto P_0c0c9ddc;
case 0x0c0c9ddeu: goto P_0c0c9dde;
case 0x0c0c9de0u: goto P_0c0c9de0;
case 0x0c0c9de2u: goto P_0c0c9de2;
case 0x0c0c9de4u: goto P_0c0c9de4;
case 0x0c0c9de6u: goto P_0c0c9de6;
case 0x0c0c9de8u: goto P_0c0c9de8;
case 0x0c0c9deau: goto P_0c0c9dea;
case 0x0c0c9decu: goto P_0c0c9dec;
case 0x0c0c9deeu: goto P_0c0c9dee;
case 0x0c0c9df0u: goto P_0c0c9df0;
case 0x0c0c9df2u: goto P_0c0c9df2;
case 0x0c0c9df4u: goto P_0c0c9df4;
case 0x0c0c9df6u: goto P_0c0c9df6;
case 0x0c0c9df8u: goto P_0c0c9df8;
case 0x0c0c9dfau: goto P_0c0c9dfa;
case 0x0c0c9dfcu: goto P_0c0c9dfc;
case 0x0c0c9dfeu: goto P_0c0c9dfe;
case 0x0c0c9e00u: goto P_0c0c9e00;
case 0x0c0c9e02u: goto P_0c0c9e02;
case 0x0c0c9e04u: goto P_0c0c9e04;
case 0x0c0c9e06u: goto P_0c0c9e06;
case 0x0c0c9e08u: goto P_0c0c9e08;
case 0x0c0c9e0au: goto P_0c0c9e0a;
case 0x0c0c9e0cu: goto P_0c0c9e0c;
case 0x0c0c9e0eu: goto P_0c0c9e0e;
case 0x0c0c9e10u: goto P_0c0c9e10;
case 0x0c0c9e12u: goto P_0c0c9e12;
case 0x0c0c9e14u: goto P_0c0c9e14;
case 0x0c0c9e16u: goto P_0c0c9e16;
case 0x0c0c9e18u: goto P_0c0c9e18;
case 0x0c0c9e1au: goto P_0c0c9e1a;
case 0x0c0c9e1cu: goto P_0c0c9e1c;
case 0x0c0c9e1eu: goto P_0c0c9e1e;
case 0x0c0c9e20u: goto P_0c0c9e20;
case 0x0c0c9e22u: goto P_0c0c9e22;
case 0x0c0c9e24u: goto P_0c0c9e24;
case 0x0c0c9e26u: goto P_0c0c9e26;
case 0x0c0c9e28u: goto P_0c0c9e28;
case 0x0c0c9e2au: goto P_0c0c9e2a;
case 0x0c0c9e2cu: goto P_0c0c9e2c;
case 0x0c0c9e2eu: goto P_0c0c9e2e;
case 0x0c0c9e30u: goto P_0c0c9e30;
case 0x0c0c9e32u: goto P_0c0c9e32;
case 0x0c0c9e34u: goto P_0c0c9e34;
case 0x0c0c9e36u: goto P_0c0c9e36;
case 0x0c0c9e38u: goto P_0c0c9e38;
case 0x0c0c9e3au: goto P_0c0c9e3a;
case 0x0c0c9e3cu: goto P_0c0c9e3c;
case 0x0c0c9e3eu: goto P_0c0c9e3e;
case 0x0c0c9e40u: goto P_0c0c9e40;
case 0x0c0c9e42u: goto P_0c0c9e42;
case 0x0c0c9e44u: goto P_0c0c9e44;
case 0x0c0c9e46u: goto P_0c0c9e46;
case 0x0c0c9e48u: goto P_0c0c9e48;
case 0x0c0c9e4au: goto P_0c0c9e4a;
case 0x0c0c9e4cu: goto P_0c0c9e4c;
case 0x0c0c9e4eu: goto P_0c0c9e4e;
case 0x0c0c9e50u: goto P_0c0c9e50;
case 0x0c0c9e52u: goto P_0c0c9e52;
case 0x0c0c9e54u: goto P_0c0c9e54;
case 0x0c0c9e56u: goto P_0c0c9e56;
case 0x0c0c9e58u: goto P_0c0c9e58;
case 0x0c0c9e5au: goto P_0c0c9e5a;
case 0x0c0c9e5cu: goto P_0c0c9e5c;
case 0x0c0c9e5eu: goto P_0c0c9e5e;
case 0x0c0c9e60u: goto P_0c0c9e60;
case 0x0c0c9e62u: goto P_0c0c9e62;
case 0x0c0c9e64u: goto P_0c0c9e64;
case 0x0c0c9e66u: goto P_0c0c9e66;
case 0x0c0c9e68u: goto P_0c0c9e68;
case 0x0c0c9e6au: goto P_0c0c9e6a;
case 0x0c0c9e6cu: goto P_0c0c9e6c;
case 0x0c0c9e6eu: goto P_0c0c9e6e;
case 0x0c0c9e80u: goto P_0c0c9e80;
case 0x0c0c9e82u: goto P_0c0c9e82;
case 0x0c0c9e84u: goto P_0c0c9e84;
case 0x0c0c9e86u: goto P_0c0c9e86;
case 0x0c0c9e88u: goto P_0c0c9e88;
case 0x0c0c9e8au: goto P_0c0c9e8a;
case 0x0c0c9e8cu: goto P_0c0c9e8c;
case 0x0c0c9e8eu: goto P_0c0c9e8e;
case 0x0c0c9e90u: goto P_0c0c9e90;
case 0x0c0c9e92u: goto P_0c0c9e92;
case 0x0c0c9e94u: goto P_0c0c9e94;
case 0x0c0c9e96u: goto P_0c0c9e96;
case 0x0c0c9e98u: goto P_0c0c9e98;
case 0x0c0c9e9au: goto P_0c0c9e9a;
case 0x0c0c9e9cu: goto P_0c0c9e9c;
case 0x0c0c9e9eu: goto P_0c0c9e9e;
case 0x0c0c9ea0u: goto P_0c0c9ea0;
case 0x0c0c9ea2u: goto P_0c0c9ea2;
case 0x0c0c9ea4u: goto P_0c0c9ea4;
case 0x0c0c9ea6u: goto P_0c0c9ea6;
case 0x0c0c9ea8u: goto P_0c0c9ea8;
case 0x0c0c9eaau: goto P_0c0c9eaa;
case 0x0c0c9eacu: goto P_0c0c9eac;
case 0x0c0c9eaeu: goto P_0c0c9eae;
case 0x0c0c9eb0u: goto P_0c0c9eb0;
case 0x0c0c9eb2u: goto P_0c0c9eb2;
case 0x0c0c9eb4u: goto P_0c0c9eb4;
case 0x0c0c9eb6u: goto P_0c0c9eb6;
case 0x0c0c9eb8u: goto P_0c0c9eb8;
case 0x0c0c9ebau: goto P_0c0c9eba;
case 0x0c0c9ebcu: goto P_0c0c9ebc;
case 0x0c0c9ebeu: goto P_0c0c9ebe;
case 0x0c0c9ec0u: goto P_0c0c9ec0;
case 0x0c0c9ec2u: goto P_0c0c9ec2;
case 0x0c0c9ec4u: goto P_0c0c9ec4;
case 0x0c0c9ec6u: goto P_0c0c9ec6;
case 0x0c0c9ec8u: goto P_0c0c9ec8;
case 0x0c0c9ecau: goto P_0c0c9eca;
case 0x0c0c9eccu: goto P_0c0c9ecc;
case 0x0c0c9eceu: goto P_0c0c9ece;
case 0x0c0c9ed0u: goto P_0c0c9ed0;
case 0x0c0c9ed2u: goto P_0c0c9ed2;
case 0x0c0c9ed4u: goto P_0c0c9ed4;
case 0x0c0c9ed6u: goto P_0c0c9ed6;
case 0x0c0c9ed8u: goto P_0c0c9ed8;
case 0x0c0c9edau: goto P_0c0c9eda;
case 0x0c0c9edcu: goto P_0c0c9edc;
case 0x0c0c9edeu: goto P_0c0c9ede;
case 0x0c0c9ee0u: goto P_0c0c9ee0;
case 0x0c0c9ee2u: goto P_0c0c9ee2;
case 0x0c0c9ee4u: goto P_0c0c9ee4;
case 0x0c0c9ee6u: goto P_0c0c9ee6;
case 0x0c0c9ee8u: goto P_0c0c9ee8;
case 0x0c0c9eeau: goto P_0c0c9eea;
case 0x0c0c9eecu: goto P_0c0c9eec;
case 0x0c0c9eeeu: goto P_0c0c9eee;
case 0x0c0c9ef0u: goto P_0c0c9ef0;
case 0x0c0c9ef2u: goto P_0c0c9ef2;
case 0x0c0c9ef4u: goto P_0c0c9ef4;
case 0x0c0c9ef6u: goto P_0c0c9ef6;
case 0x0c0c9ef8u: goto P_0c0c9ef8;
case 0x0c0c9efau: goto P_0c0c9efa;
case 0x0c0c9efcu: goto P_0c0c9efc;
case 0x0c0c9efeu: goto P_0c0c9efe;
case 0x0c0c9f00u: goto P_0c0c9f00;
case 0x0c0c9f02u: goto P_0c0c9f02;
case 0x0c0c9f04u: goto P_0c0c9f04;
case 0x0c0c9f06u: goto P_0c0c9f06;
case 0x0c0c9f08u: goto P_0c0c9f08;
case 0x0c0c9f0au: goto P_0c0c9f0a;
case 0x0c0c9f0cu: goto P_0c0c9f0c;
case 0x0c0c9f0eu: goto P_0c0c9f0e;
case 0x0c0c9f10u: goto P_0c0c9f10;
case 0x0c0c9f12u: goto P_0c0c9f12;
case 0x0c0c9f14u: goto P_0c0c9f14;
case 0x0c0c9f16u: goto P_0c0c9f16;
case 0x0c0c9f18u: goto P_0c0c9f18;
case 0x0c0c9f1au: goto P_0c0c9f1a;
case 0x0c0c9f1cu: goto P_0c0c9f1c;
case 0x0c0c9f1eu: goto P_0c0c9f1e;
case 0x0c0c9f20u: goto P_0c0c9f20;
case 0x0c0c9f22u: goto P_0c0c9f22;
case 0x0c0c9f24u: goto P_0c0c9f24;
case 0x0c0c9f26u: goto P_0c0c9f26;
case 0x0c0c9f28u: goto P_0c0c9f28;
case 0x0c0c9f2au: goto P_0c0c9f2a;
case 0x0c0c9f2cu: goto P_0c0c9f2c;
case 0x0c0c9f2eu: goto P_0c0c9f2e;
case 0x0c0c9f30u: goto P_0c0c9f30;
case 0x0c0c9f32u: goto P_0c0c9f32;
case 0x0c0c9f34u: goto P_0c0c9f34;
case 0x0c0c9f36u: goto P_0c0c9f36;
case 0x0c0c9f38u: goto P_0c0c9f38;
case 0x0c0c9f3au: goto P_0c0c9f3a;
default: return vf3_matrix_family(target,s,ram);
}
P_0c0955b0: /* original 4f22, guest PC 0x0c0955b0 */
if(!s->budget--) { s->failed_pc=0x0c0955b0u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0955b2;
P_0c0955b2: /* original 7ff0, guest PC 0x0c0955b2 */
if(!s->budget--) { s->failed_pc=0x0c0955b2u; return 0; }
r[15]+=0xfffffff0u;
goto P_0c0955b4;
P_0c0955b4: /* original 1f42, guest PC 0x0c0955b4 */
if(!s->budget--) { s->failed_pc=0x0c0955b4u; return 0; }
write(ram,r[15]+8,r[4],4);
goto P_0c0955b6;
P_0c0955b6: /* original 1f51, guest PC 0x0c0955b6 */
if(!s->budget--) { s->failed_pc=0x0c0955b6u; return 0; }
write(ram,r[15]+4,r[5],4);
goto P_0c0955b8;
P_0c0955b8: /* original 2f62, guest PC 0x0c0955b8 */
if(!s->budget--) { s->failed_pc=0x0c0955b8u; return 0; }
write(ram,r[15],r[6],4);
goto P_0c0955ba;
P_0c0955ba: /* original 1f73, guest PC 0x0c0955ba */
if(!s->budget--) { s->failed_pc=0x0c0955bau; return 0; }
write(ram,r[15]+12,r[7],4);
goto P_0c0955bc;
P_0c0955bc: /* original d34e, guest PC 0x0c0955bc */
if(!s->budget--) { s->failed_pc=0x0c0955bcu; return 0; }
r[3]=read(ram,0x0c0956f8u,4);
goto P_0c0955be;
P_0c0955be: /* original 430b, guest PC 0x0c0955be */
if(!s->budget--) { s->failed_pc=0x0c0955beu; return 0; }
target=r[3];
r[16]=code_base|0x0c0955c2u;
r[4]=0x00000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0955c2u) { target=s->pc; goto dispatch; }
goto P_0c0955c2;
P_0c0955c0: /* original e400, guest PC 0x0c0955c0 */
if(!s->budget--) { s->failed_pc=0x0c0955c0u; return 0; }
r[4]=0x00000000u;
goto P_0c0955c2;
P_0c0955c2: /* original d24e, guest PC 0x0c0955c2 */
if(!s->budget--) { s->failed_pc=0x0c0955c2u; return 0; }
r[2]=read(ram,0x0c0956fcu,4);
goto P_0c0955c4;
P_0c0955c4: /* original 420b, guest PC 0x0c0955c4 */
if(!s->budget--) { s->failed_pc=0x0c0955c4u; return 0; }
target=r[2];
r[16]=code_base|0x0c0955c8u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0955c8u) { target=s->pc; goto dispatch; }
goto P_0c0955c8;
P_0c0955c6: /* original 0009, guest PC 0x0c0955c6 */
if(!s->budget--) { s->failed_pc=0x0c0955c6u; return 0; }
goto P_0c0955c8;
P_0c0955c8: /* original d34d, guest PC 0x0c0955c8 */
if(!s->budget--) { s->failed_pc=0x0c0955c8u; return 0; }
r[3]=read(ram,0x0c095700u,4);
goto P_0c0955ca;
P_0c0955ca: /* original 430b, guest PC 0x0c0955ca */
if(!s->budget--) { s->failed_pc=0x0c0955cau; return 0; }
target=r[3];
r[16]=code_base|0x0c0955ceu;
r[4]=read(ram,r[15]+24,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0955ceu) { target=s->pc; goto dispatch; }
goto P_0c0955ce;
P_0c0955cc: /* original 54f6, guest PC 0x0c0955cc */
if(!s->budget--) { s->failed_pc=0x0c0955ccu; return 0; }
r[4]=read(ram,r[15]+24,4);
goto P_0c0955ce;
P_0c0955ce: /* original d34d, guest PC 0x0c0955ce */
if(!s->budget--) { s->failed_pc=0x0c0955ceu; return 0; }
r[3]=read(ram,0x0c095704u,4);
goto P_0c0955d0;
P_0c0955d0: /* original 430b, guest PC 0x0c0955d0 */
if(!s->budget--) { s->failed_pc=0x0c0955d0u; return 0; }
target=r[3];
r[16]=code_base|0x0c0955d4u;
r[4]=read(ram,r[15]+20,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0955d4u) { target=s->pc; goto dispatch; }
goto P_0c0955d4;
P_0c0955d2: /* original 54f5, guest PC 0x0c0955d2 */
if(!s->budget--) { s->failed_pc=0x0c0955d2u; return 0; }
r[4]=read(ram,r[15]+20,4);
goto P_0c0955d4;
P_0c0955d4: /* original d34c, guest PC 0x0c0955d4 */
if(!s->budget--) { s->failed_pc=0x0c0955d4u; return 0; }
r[3]=read(ram,0x0c095708u,4);
goto P_0c0955d6;
P_0c0955d6: /* original 430b, guest PC 0x0c0955d6 */
if(!s->budget--) { s->failed_pc=0x0c0955d6u; return 0; }
target=r[3];
r[16]=code_base|0x0c0955dau;
r[4]=read(ram,r[15]+12,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0955dau) { target=s->pc; goto dispatch; }
goto P_0c0955da;
P_0c0955d8: /* original 54f3, guest PC 0x0c0955d8 */
if(!s->budget--) { s->failed_pc=0x0c0955d8u; return 0; }
r[4]=read(ram,r[15]+12,4);
goto P_0c0955da;
P_0c0955da: /* original d24c, guest PC 0x0c0955da */
if(!s->budget--) { s->failed_pc=0x0c0955dau; return 0; }
r[2]=read(ram,0x0c09570cu,4);
goto P_0c0955dc;
P_0c0955dc: /* original 420b, guest PC 0x0c0955dc */
if(!s->budget--) { s->failed_pc=0x0c0955dcu; return 0; }
target=r[2];
r[16]=code_base|0x0c0955e0u;
r[4]=0x00000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0955e0u) { target=s->pc; goto dispatch; }
goto P_0c0955e0;
P_0c0955de: /* original e400, guest PC 0x0c0955de */
if(!s->budget--) { s->failed_pc=0x0c0955deu; return 0; }
r[4]=0x00000000u;
goto P_0c0955e0;
P_0c0955e0: /* original 6403, guest PC 0x0c0955e0 */
if(!s->budget--) { s->failed_pc=0x0c0955e0u; return 0; }
r[4]=r[0];
goto P_0c0955e2;
P_0c0955e2: /* original e020, guest PC 0x0c0955e2 */
if(!s->budget--) { s->failed_pc=0x0c0955e2u; return 0; }
r[0]=0x00000020u;
goto P_0c0955e4;
P_0c0955e4: /* original f346, guest PC 0x0c0955e4 */
if(!s->budget--) { s->failed_pc=0x0c0955e4u; return 0; }
vf3_matrix_load(s,ram,3,r[4]+r[0]);
goto P_0c0955e6;
P_0c0955e6: /* original e024, guest PC 0x0c0955e6 */
if(!s->budget--) { s->failed_pc=0x0c0955e6u; return 0; }
r[0]=0x00000024u;
goto P_0c0955e8;
P_0c0955e8: /* original 53f2, guest PC 0x0c0955e8 */
if(!s->budget--) { s->failed_pc=0x0c0955e8u; return 0; }
r[3]=read(ram,r[15]+8,4);
goto P_0c0955ea;
P_0c0955ea: /* original f33a, guest PC 0x0c0955ea */
if(!s->budget--) { s->failed_pc=0x0c0955eau; return 0; }
vf3_matrix_store(s,ram,3,r[3]);
goto P_0c0955ec;
P_0c0955ec: /* original f346, guest PC 0x0c0955ec */
if(!s->budget--) { s->failed_pc=0x0c0955ecu; return 0; }
vf3_matrix_load(s,ram,3,r[4]+r[0]);
goto P_0c0955ee;
P_0c0955ee: /* original e028, guest PC 0x0c0955ee */
if(!s->budget--) { s->failed_pc=0x0c0955eeu; return 0; }
r[0]=0x00000028u;
goto P_0c0955f0;
P_0c0955f0: /* original 53f1, guest PC 0x0c0955f0 */
if(!s->budget--) { s->failed_pc=0x0c0955f0u; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c0955f2;
P_0c0955f2: /* original f33a, guest PC 0x0c0955f2 */
if(!s->budget--) { s->failed_pc=0x0c0955f2u; return 0; }
vf3_matrix_store(s,ram,3,r[3]);
goto P_0c0955f4;
P_0c0955f4: /* original f346, guest PC 0x0c0955f4 */
if(!s->budget--) { s->failed_pc=0x0c0955f4u; return 0; }
vf3_matrix_load(s,ram,3,r[4]+r[0]);
goto P_0c0955f6;
P_0c0955f6: /* original e401, guest PC 0x0c0955f6 */
if(!s->budget--) { s->failed_pc=0x0c0955f6u; return 0; }
r[4]=0x00000001u;
goto P_0c0955f8;
P_0c0955f8: /* original 63f2, guest PC 0x0c0955f8 */
if(!s->budget--) { s->failed_pc=0x0c0955f8u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c0955fa;
P_0c0955fa: /* original 7f10, guest PC 0x0c0955fa */
if(!s->budget--) { s->failed_pc=0x0c0955fau; return 0; }
r[15]+=0x00000010u;
goto P_0c0955fc;
P_0c0955fc: /* original f33a, guest PC 0x0c0955fc */
if(!s->budget--) { s->failed_pc=0x0c0955fcu; return 0; }
vf3_matrix_store(s,ram,3,r[3]);
goto P_0c0955fe;
P_0c0955fe: /* original d344, guest PC 0x0c0955fe */
if(!s->budget--) { s->failed_pc=0x0c0955feu; return 0; }
r[3]=read(ram,0x0c095710u,4);
goto P_0c095600;
P_0c095600: /* original 432b, guest PC 0x0c095600 */
if(!s->budget--) { s->failed_pc=0x0c095600u; return 0; }
target=r[3];
r[16]=read(ram,r[15],4); r[15]+=4;
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
P_0c095602: /* original 4f26, guest PC 0x0c095602 */
if(!s->budget--) { s->failed_pc=0x0c095602u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
if(!vf3_matrix_family(0x0c095604u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c095604u; return 0; } return 1;
P_0c0c9db6: /* original 2fe6, guest PC 0x0c0c9db6 */
if(!s->budget--) { s->failed_pc=0x0c0c9db6u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c9db8;
P_0c0c9db8: /* original 2448, guest PC 0x0c0c9db8 */
if(!s->budget--) { s->failed_pc=0x0c0c9db8u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c0c9dba;
P_0c0c9dba: /* original 2fd6, guest PC 0x0c0c9dba */
if(!s->budget--) { s->failed_pc=0x0c0c9dbau; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c9dbc;
P_0c0c9dbc: /* original 2fc6, guest PC 0x0c0c9dbc */
if(!s->budget--) { s->failed_pc=0x0c0c9dbcu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c9dbe;
P_0c0c9dbe: /* original ec00, guest PC 0x0c0c9dbe */
if(!s->budget--) { s->failed_pc=0x0c0c9dbeu; return 0; }
r[12]=0x00000000u;
goto P_0c0c9dc0;
P_0c0c9dc0: /* original 2fb6, guest PC 0x0c0c9dc0 */
if(!s->budget--) { s->failed_pc=0x0c0c9dc0u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c9dc2;
P_0c0c9dc2: /* original 6b53, guest PC 0x0c0c9dc2 */
if(!s->budget--) { s->failed_pc=0x0c0c9dc2u; return 0; }
r[11]=r[5];
goto P_0c0c9dc4;
P_0c0c9dc4: /* original 2fa6, guest PC 0x0c0c9dc4 */
if(!s->budget--) { s->failed_pc=0x0c0c9dc4u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c9dc6;
P_0c0c9dc6: /* original 2f96, guest PC 0x0c0c9dc6 */
if(!s->budget--) { s->failed_pc=0x0c0c9dc6u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c9dc8;
P_0c0c9dc8: /* original 4f22, guest PC 0x0c0c9dc8 */
if(!s->budget--) { s->failed_pc=0x0c0c9dc8u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0c9dca;
P_0c0c9dca: /* original d32a, guest PC 0x0c0c9dca */
if(!s->budget--) { s->failed_pc=0x0c0c9dcau; return 0; }
r[3]=read(ram,0x0c0c9e74u,4);
goto P_0c0c9dcc;
P_0c0c9dcc: /* original 7ff4, guest PC 0x0c0c9dcc */
if(!s->budget--) { s->failed_pc=0x0c0c9dccu; return 0; }
r[15]+=0xfffffff4u;
goto P_0c0c9dce;
P_0c0c9dce: /* original 2f32, guest PC 0x0c0c9dce */
if(!s->budget--) { s->failed_pc=0x0c0c9dceu; return 0; }
write(ram,r[15],r[3],4);
goto P_0c0c9dd0;
P_0c0c9dd0: /* original 8f02, guest PC 0x0c0c9dd0 */
if(!s->budget--) { s->failed_pc=0x0c0c9dd0u; return 0; }
cond=r[17]&1u;
r[13]=0x00000001u;
if(!cond) { goto P_0c0c9dd8; }
goto P_0c0c9dd4;
P_0c0c9dd2: /* original ed01, guest PC 0x0c0c9dd2 */
if(!s->budget--) { s->failed_pc=0x0c0c9dd2u; return 0; }
r[13]=0x00000001u;
goto P_0c0c9dd4;
P_0c0c9dd4: /* original a001, guest PC 0x0c0c9dd4 */
if(!s->budget--) { s->failed_pc=0x0c0c9dd4u; return 0; }
r[5]=r[12];
goto P_0c0c9dda;
P_0c0c9dd6: /* original 65c3, guest PC 0x0c0c9dd6 */
if(!s->budget--) { s->failed_pc=0x0c0c9dd6u; return 0; }
r[5]=r[12];
goto P_0c0c9dd8;
P_0c0c9dd8: /* original 65d3, guest PC 0x0c0c9dd8 */
if(!s->budget--) { s->failed_pc=0x0c0c9dd8u; return 0; }
r[5]=r[13];
goto P_0c0c9dda;
P_0c0c9dda: /* original d027, guest PC 0x0c0c9dda */
if(!s->budget--) { s->failed_pc=0x0c0c9ddau; return 0; }
r[0]=read(ram,0x0c0c9e78u,4);
goto P_0c0c9ddc;
P_0c0c9ddc: /* original 6943, guest PC 0x0c0c9ddc */
if(!s->budget--) { s->failed_pc=0x0c0c9ddcu; return 0; }
r[9]=r[4];
goto P_0c0c9dde;
P_0c0c9dde: /* original 4908, guest PC 0x0c0c9dde */
if(!s->budget--) { s->failed_pc=0x0c0c9ddeu; return 0; }
r[9]<<=2;
goto P_0c0c9de0;
P_0c0c9de0: /* original da26, guest PC 0x0c0c9de0 */
if(!s->budget--) { s->failed_pc=0x0c0c9de0u; return 0; }
r[10]=read(ram,0x0c0c9e7cu,4);
goto P_0c0c9de2;
P_0c0c9de2: /* original 099e, guest PC 0x0c0c9de2 */
if(!s->budget--) { s->failed_pc=0x0c0c9de2u; return 0; }
r[9]=read(ram,r[9]+r[0],4);
goto P_0c0c9de4;
P_0c0c9de4: /* original e061, guest PC 0x0c0c9de4 */
if(!s->budget--) { s->failed_pc=0x0c0c9de4u; return 0; }
r[0]=0x00000061u;
goto P_0c0c9de6;
P_0c0c9de6: /* original 0ebc, guest PC 0x0c0c9de6 */
if(!s->budget--) { s->failed_pc=0x0c0c9de6u; return 0; }
r[14]=(uint32_t)(int32_t)(int8_t)read(ram,r[11]+r[0],1);
goto P_0c0c9de8;
P_0c0c9de8: /* original 6eec, guest PC 0x0c0c9de8 */
if(!s->budget--) { s->failed_pc=0x0c0c9de8u; return 0; }
r[14]=r[14]&255u;
goto P_0c0c9dea;
P_0c0c9dea: /* original 60e3, guest PC 0x0c0c9dea */
if(!s->budget--) { s->failed_pc=0x0c0c9deau; return 0; }
r[0]=r[14];
goto P_0c0c9dec;
P_0c0c9dec: /* original 8809, guest PC 0x0c0c9dec */
if(!s->budget--) { s->failed_pc=0x0c0c9decu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000009u)!=0);
goto P_0c0c9dee;
P_0c0c9dee: /* original 8971, guest PC 0x0c0c9dee */
if(!s->budget--) { s->failed_pc=0x0c0c9deeu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c9ed4; }
goto P_0c0c9df0;
P_0c0c9df0: /* original 2558, guest PC 0x0c0c9df0 */
if(!s->budget--) { s->failed_pc=0x0c0c9df0u; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[5])==0)!=0);
goto P_0c0c9df2;
P_0c0c9df2: /* original 8b69, guest PC 0x0c0c9df2 */
if(!s->budget--) { s->failed_pc=0x0c0c9df2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c9ec8; }
goto P_0c0c9df4;
P_0c0c9df4: /* original 60e3, guest PC 0x0c0c9df4 */
if(!s->budget--) { s->failed_pc=0x0c0c9df4u; return 0; }
r[0]=r[14];
goto P_0c0c9df6;
P_0c0c9df6: /* original 8806, guest PC 0x0c0c9df6 */
if(!s->budget--) { s->failed_pc=0x0c0c9df6u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000006u)!=0);
goto P_0c0c9df8;
P_0c0c9df8: /* original 8b01, guest PC 0x0c0c9df8 */
if(!s->budget--) { s->failed_pc=0x0c0c9df8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c9dfe; }
goto P_0c0c9dfa;
P_0c0c9dfa: /* original a001, guest PC 0x0c0c9dfa */
if(!s->budget--) { s->failed_pc=0x0c0c9dfau; return 0; }
write(ram,r[15]+4,r[12],4);
goto P_0c0c9e00;
P_0c0c9dfc: /* original 1fc1, guest PC 0x0c0c9dfc */
if(!s->budget--) { s->failed_pc=0x0c0c9dfcu; return 0; }
write(ram,r[15]+4,r[12],4);
goto P_0c0c9dfe;
P_0c0c9dfe: /* original 1fd1, guest PC 0x0c0c9dfe */
if(!s->budget--) { s->failed_pc=0x0c0c9dfeu; return 0; }
write(ram,r[15]+4,r[13],4);
goto P_0c0c9e00;
P_0c0c9e00: /* original 60e3, guest PC 0x0c0c9e00 */
if(!s->budget--) { s->failed_pc=0x0c0c9e00u; return 0; }
r[0]=r[14];
goto P_0c0c9e02;
P_0c0c9e02: /* original 880a, guest PC 0x0c0c9e02 */
if(!s->budget--) { s->failed_pc=0x0c0c9e02u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000au)!=0);
goto P_0c0c9e04;
P_0c0c9e04: /* original 8f02, guest PC 0x0c0c9e04 */
if(!s->budget--) { s->failed_pc=0x0c0c9e04u; return 0; }
cond=r[17]&1u;
r[0]=r[14];
if(!cond) { goto P_0c0c9e0c; }
goto P_0c0c9e08;
P_0c0c9e06: /* original 60e3, guest PC 0x0c0c9e06 */
if(!s->budget--) { s->failed_pc=0x0c0c9e06u; return 0; }
r[0]=r[14];
goto P_0c0c9e08;
P_0c0c9e08: /* original a001, guest PC 0x0c0c9e08 */
if(!s->budget--) { s->failed_pc=0x0c0c9e08u; return 0; }
r[4]=r[12];
goto P_0c0c9e0e;
P_0c0c9e0a: /* original 64c3, guest PC 0x0c0c9e0a */
if(!s->budget--) { s->failed_pc=0x0c0c9e0au; return 0; }
r[4]=r[12];
goto P_0c0c9e0c;
P_0c0c9e0c: /* original 64d3, guest PC 0x0c0c9e0c */
if(!s->budget--) { s->failed_pc=0x0c0c9e0cu; return 0; }
r[4]=r[13];
goto P_0c0c9e0e;
P_0c0c9e0e: /* original 8808, guest PC 0x0c0c9e0e */
if(!s->budget--) { s->failed_pc=0x0c0c9e0eu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000008u)!=0);
goto P_0c0c9e10;
P_0c0c9e10: /* original 8b01, guest PC 0x0c0c9e10 */
if(!s->budget--) { s->failed_pc=0x0c0c9e10u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c9e16; }
goto P_0c0c9e12;
P_0c0c9e12: /* original a001, guest PC 0x0c0c9e12 */
if(!s->budget--) { s->failed_pc=0x0c0c9e12u; return 0; }
write(ram,r[15]+8,r[12],4);
goto P_0c0c9e18;
P_0c0c9e14: /* original 1fc2, guest PC 0x0c0c9e14 */
if(!s->budget--) { s->failed_pc=0x0c0c9e14u; return 0; }
write(ram,r[15]+8,r[12],4);
goto P_0c0c9e16;
P_0c0c9e16: /* original 1fd2, guest PC 0x0c0c9e16 */
if(!s->budget--) { s->failed_pc=0x0c0c9e16u; return 0; }
write(ram,r[15]+8,r[13],4);
goto P_0c0c9e18;
P_0c0c9e18: /* original 60e3, guest PC 0x0c0c9e18 */
if(!s->budget--) { s->failed_pc=0x0c0c9e18u; return 0; }
r[0]=r[14];
goto P_0c0c9e1a;
P_0c0c9e1a: /* original 880b, guest PC 0x0c0c9e1a */
if(!s->budget--) { s->failed_pc=0x0c0c9e1au; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000bu)!=0);
goto P_0c0c9e1c;
P_0c0c9e1c: /* original 8f02, guest PC 0x0c0c9e1c */
if(!s->budget--) { s->failed_pc=0x0c0c9e1cu; return 0; }
cond=r[17]&1u;
r[0]=r[14];
if(!cond) { goto P_0c0c9e24; }
goto P_0c0c9e20;
P_0c0c9e1e: /* original 60e3, guest PC 0x0c0c9e1e */
if(!s->budget--) { s->failed_pc=0x0c0c9e1eu; return 0; }
r[0]=r[14];
goto P_0c0c9e20;
P_0c0c9e20: /* original a001, guest PC 0x0c0c9e20 */
if(!s->budget--) { s->failed_pc=0x0c0c9e20u; return 0; }
r[7]=r[12];
goto P_0c0c9e26;
P_0c0c9e22: /* original 67c3, guest PC 0x0c0c9e22 */
if(!s->budget--) { s->failed_pc=0x0c0c9e22u; return 0; }
r[7]=r[12];
goto P_0c0c9e24;
P_0c0c9e24: /* original 67d3, guest PC 0x0c0c9e24 */
if(!s->budget--) { s->failed_pc=0x0c0c9e24u; return 0; }
r[7]=r[13];
goto P_0c0c9e26;
P_0c0c9e26: /* original 880c, guest PC 0x0c0c9e26 */
if(!s->budget--) { s->failed_pc=0x0c0c9e26u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000cu)!=0);
goto P_0c0c9e28;
P_0c0c9e28: /* original 8f02, guest PC 0x0c0c9e28 */
if(!s->budget--) { s->failed_pc=0x0c0c9e28u; return 0; }
cond=r[17]&1u;
r[0]=r[14];
if(!cond) { goto P_0c0c9e30; }
goto P_0c0c9e2c;
P_0c0c9e2a: /* original 60e3, guest PC 0x0c0c9e2a */
if(!s->budget--) { s->failed_pc=0x0c0c9e2au; return 0; }
r[0]=r[14];
goto P_0c0c9e2c;
P_0c0c9e2c: /* original a001, guest PC 0x0c0c9e2c */
if(!s->budget--) { s->failed_pc=0x0c0c9e2cu; return 0; }
r[1]=r[12];
goto P_0c0c9e32;
P_0c0c9e2e: /* original 61c3, guest PC 0x0c0c9e2e */
if(!s->budget--) { s->failed_pc=0x0c0c9e2eu; return 0; }
r[1]=r[12];
goto P_0c0c9e30;
P_0c0c9e30: /* original 61d3, guest PC 0x0c0c9e30 */
if(!s->budget--) { s->failed_pc=0x0c0c9e30u; return 0; }
r[1]=r[13];
goto P_0c0c9e32;
P_0c0c9e32: /* original 8807, guest PC 0x0c0c9e32 */
if(!s->budget--) { s->failed_pc=0x0c0c9e32u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000007u)!=0);
goto P_0c0c9e34;
P_0c0c9e34: /* original 8f02, guest PC 0x0c0c9e34 */
if(!s->budget--) { s->failed_pc=0x0c0c9e34u; return 0; }
cond=r[17]&1u;
r[0]=r[14];
if(!cond) { goto P_0c0c9e3c; }
goto P_0c0c9e38;
P_0c0c9e36: /* original 60e3, guest PC 0x0c0c9e36 */
if(!s->budget--) { s->failed_pc=0x0c0c9e36u; return 0; }
r[0]=r[14];
goto P_0c0c9e38;
P_0c0c9e38: /* original a001, guest PC 0x0c0c9e38 */
if(!s->budget--) { s->failed_pc=0x0c0c9e38u; return 0; }
r[5]=r[12];
goto P_0c0c9e3e;
P_0c0c9e3a: /* original 65c3, guest PC 0x0c0c9e3a */
if(!s->budget--) { s->failed_pc=0x0c0c9e3au; return 0; }
r[5]=r[12];
goto P_0c0c9e3c;
P_0c0c9e3c: /* original 65d3, guest PC 0x0c0c9e3c */
if(!s->budget--) { s->failed_pc=0x0c0c9e3cu; return 0; }
r[5]=r[13];
goto P_0c0c9e3e;
P_0c0c9e3e: /* original 8805, guest PC 0x0c0c9e3e */
if(!s->budget--) { s->failed_pc=0x0c0c9e3eu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000005u)!=0);
goto P_0c0c9e40;
P_0c0c9e40: /* original 8b01, guest PC 0x0c0c9e40 */
if(!s->budget--) { s->failed_pc=0x0c0c9e40u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c9e46; }
goto P_0c0c9e42;
P_0c0c9e42: /* original a001, guest PC 0x0c0c9e42 */
if(!s->budget--) { s->failed_pc=0x0c0c9e42u; return 0; }
r[6]=r[12];
goto P_0c0c9e48;
P_0c0c9e44: /* original 66c3, guest PC 0x0c0c9e44 */
if(!s->budget--) { s->failed_pc=0x0c0c9e44u; return 0; }
r[6]=r[12];
goto P_0c0c9e46;
P_0c0c9e46: /* original 66d3, guest PC 0x0c0c9e46 */
if(!s->budget--) { s->failed_pc=0x0c0c9e46u; return 0; }
r[6]=r[13];
goto P_0c0c9e48;
P_0c0c9e48: /* original 53f1, guest PC 0x0c0c9e48 */
if(!s->budget--) { s->failed_pc=0x0c0c9e48u; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c0c9e4a;
P_0c0c9e4a: /* original 2338, guest PC 0x0c0c9e4a */
if(!s->budget--) { s->failed_pc=0x0c0c9e4au; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c0c9e4c;
P_0c0c9e4c: /* original 890e, guest PC 0x0c0c9e4c */
if(!s->budget--) { s->failed_pc=0x0c0c9e4cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c9e6c; }
goto P_0c0c9e4e;
P_0c0c9e4e: /* original 2448, guest PC 0x0c0c9e4e */
if(!s->budget--) { s->failed_pc=0x0c0c9e4eu; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c0c9e50;
P_0c0c9e50: /* original 890c, guest PC 0x0c0c9e50 */
if(!s->budget--) { s->failed_pc=0x0c0c9e50u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c9e6c; }
goto P_0c0c9e52;
P_0c0c9e52: /* original 52f2, guest PC 0x0c0c9e52 */
if(!s->budget--) { s->failed_pc=0x0c0c9e52u; return 0; }
r[2]=read(ram,r[15]+8,4);
goto P_0c0c9e54;
P_0c0c9e54: /* original 2228, guest PC 0x0c0c9e54 */
if(!s->budget--) { s->failed_pc=0x0c0c9e54u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c0c9e56;
P_0c0c9e56: /* original 8909, guest PC 0x0c0c9e56 */
if(!s->budget--) { s->failed_pc=0x0c0c9e56u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c9e6c; }
goto P_0c0c9e58;
P_0c0c9e58: /* original 2778, guest PC 0x0c0c9e58 */
if(!s->budget--) { s->failed_pc=0x0c0c9e58u; return 0; }
r[17]=(r[17]&~1u)|(((r[7]&r[7])==0)!=0);
goto P_0c0c9e5a;
P_0c0c9e5a: /* original 8907, guest PC 0x0c0c9e5a */
if(!s->budget--) { s->failed_pc=0x0c0c9e5au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c9e6c; }
goto P_0c0c9e5c;
P_0c0c9e5c: /* original 2118, guest PC 0x0c0c9e5c */
if(!s->budget--) { s->failed_pc=0x0c0c9e5cu; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[1])==0)!=0);
goto P_0c0c9e5e;
P_0c0c9e5e: /* original 890f, guest PC 0x0c0c9e5e */
if(!s->budget--) { s->failed_pc=0x0c0c9e5eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c9e80; }
goto P_0c0c9e60;
P_0c0c9e60: /* original 2558, guest PC 0x0c0c9e60 */
if(!s->budget--) { s->failed_pc=0x0c0c9e60u; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[5])==0)!=0);
goto P_0c0c9e62;
P_0c0c9e62: /* original 890d, guest PC 0x0c0c9e62 */
if(!s->budget--) { s->failed_pc=0x0c0c9e62u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c9e80; }
goto P_0c0c9e64;
P_0c0c9e64: /* original 2668, guest PC 0x0c0c9e64 */
if(!s->budget--) { s->failed_pc=0x0c0c9e64u; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[6])==0)!=0);
goto P_0c0c9e66;
P_0c0c9e66: /* original 890b, guest PC 0x0c0c9e66 */
if(!s->budget--) { s->failed_pc=0x0c0c9e66u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c9e80; }
goto P_0c0c9e68;
P_0c0c9e68: /* original a00f, guest PC 0x0c0c9e68 */
if(!s->budget--) { s->failed_pc=0x0c0c9e68u; return 0; }
goto P_0c0c9e8a;
P_0c0c9e6a: /* original 0009, guest PC 0x0c0c9e6a */
if(!s->budget--) { s->failed_pc=0x0c0c9e6au; return 0; }
goto P_0c0c9e6c;
P_0c0c9e6c: /* original a009, guest PC 0x0c0c9e6c */
if(!s->budget--) { s->failed_pc=0x0c0c9e6cu; return 0; }
r[14]=0x00000070u;
goto P_0c0c9e82;
P_0c0c9e6e: /* original ee70, guest PC 0x0c0c9e6e */
if(!s->budget--) { s->failed_pc=0x0c0c9e6eu; return 0; }
r[14]=0x00000070u;
if(!vf3_matrix_family(0x0c0c9e70u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0c9e70u; return 0; } return 1;
P_0c0c9e80: /* original ee71, guest PC 0x0c0c9e80 */
if(!s->budget--) { s->failed_pc=0x0c0c9e80u; return 0; }
r[14]=0x00000071u;
goto P_0c0c9e82;
P_0c0c9e82: /* original b03c, guest PC 0x0c0c9e82 */
if(!s->budget--) { s->failed_pc=0x0c0c9e82u; return 0; }
target=code_base|0x0c0c9efeu; r[16]=code_base|0x0c0c9e86u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c9e86u) { target=s->pc; goto dispatch; }
goto P_0c0c9e86;
P_0c0c9e84: /* original 64e3, guest PC 0x0c0c9e84 */
if(!s->budget--) { s->failed_pc=0x0c0c9e84u; return 0; }
r[4]=r[14];
goto P_0c0c9e86;
P_0c0c9e86: /* original 4a0b, guest PC 0x0c0c9e86 */
if(!s->budget--) { s->failed_pc=0x0c0c9e86u; return 0; }
target=r[10];
r[16]=code_base|0x0c0c9e8au;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c9e8au) { target=s->pc; goto dispatch; }
goto P_0c0c9e8a;
P_0c0c9e88: /* original 64e3, guest PC 0x0c0c9e88 */
if(!s->budget--) { s->failed_pc=0x0c0c9e88u; return 0; }
r[4]=r[14];
goto P_0c0c9e8a;
P_0c0c9e8a: /* original 60f2, guest PC 0x0c0c9e8a */
if(!s->budget--) { s->failed_pc=0x0c0c9e8au; return 0; }
tmp=read(ram,r[15],4);
r[0]=tmp;
goto P_0c0c9e8c;
P_0c0c9e8c: /* original e11c, guest PC 0x0c0c9e8c */
if(!s->budget--) { s->failed_pc=0x0c0c9e8cu; return 0; }
r[1]=0x0000001cu;
goto P_0c0c9e8e;
P_0c0c9e8e: /* original e40f, guest PC 0x0c0c9e8e */
if(!s->budget--) { s->failed_pc=0x0c0c9e8eu; return 0; }
r[4]=0x0000000fu;
goto P_0c0c9e90;
P_0c0c9e90: /* original 001c, guest PC 0x0c0c9e90 */
if(!s->budget--) { s->failed_pc=0x0c0c9e90u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[1]+r[0],1);
goto P_0c0c9e92;
P_0c0c9e92: /* original 600c, guest PC 0x0c0c9e92 */
if(!s->budget--) { s->failed_pc=0x0c0c9e92u; return 0; }
r[0]=r[0]&255u;
goto P_0c0c9e94;
P_0c0c9e94: /* original 2409, guest PC 0x0c0c9e94 */
if(!s->budget--) { s->failed_pc=0x0c0c9e94u; return 0; }
r[4]&=r[0];
goto P_0c0c9e96;
P_0c0c9e96: /* original 6043, guest PC 0x0c0c9e96 */
if(!s->budget--) { s->failed_pc=0x0c0c9e96u; return 0; }
r[0]=r[4];
goto P_0c0c9e98;
P_0c0c9e98: /* original 8809, guest PC 0x0c0c9e98 */
if(!s->budget--) { s->failed_pc=0x0c0c9e98u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000009u)!=0);
goto P_0c0c9e9a;
P_0c0c9e9a: /* original 8b15, guest PC 0x0c0c9e9a */
if(!s->budget--) { s->failed_pc=0x0c0c9e9au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c9ec8; }
goto P_0c0c9e9c;
P_0c0c9e9c: /* original 904e, guest PC 0x0c0c9e9c */
if(!s->budget--) { s->failed_pc=0x0c0c9e9cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c9f3cu,2);
goto P_0c0c9e9e;
P_0c0c9e9e: /* original f5b6, guest PC 0x0c0c9e9e */
if(!s->budget--) { s->failed_pc=0x0c0c9e9eu; return 0; }
vf3_matrix_load(s,ram,5,r[11]+r[0]);
goto P_0c0c9ea0;
P_0c0c9ea0: /* original 7008, guest PC 0x0c0c9ea0 */
if(!s->budget--) { s->failed_pc=0x0c0c9ea0u; return 0; }
r[0]+=0x00000008u;
goto P_0c0c9ea2;
P_0c0c9ea2: /* original f4b6, guest PC 0x0c0c9ea2 */
if(!s->budget--) { s->failed_pc=0x0c0c9ea2u; return 0; }
vf3_matrix_load(s,ram,4,r[11]+r[0]);
goto P_0c0c9ea4;
P_0c0c9ea4: /* original c726, guest PC 0x0c0c9ea4 */
if(!s->budget--) { s->failed_pc=0x0c0c9ea4u; return 0; }
r[0]=code_base|0x000c9f40u;
goto P_0c0c9ea6;
P_0c0c9ea6: /* original f608, guest PC 0x0c0c9ea6 */
if(!s->budget--) { s->failed_pc=0x0c0c9ea6u; return 0; }
vf3_matrix_load(s,ram,6,r[0]);
goto P_0c0c9ea8;
P_0c0c9ea8: /* original f565, guest PC 0x0c0c9ea8 */
if(!s->budget--) { s->failed_pc=0x0c0c9ea8u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[5])>as_float(fr[6]))!=0);
goto P_0c0c9eaa;
P_0c0c9eaa: /* original 890d, guest PC 0x0c0c9eaa */
if(!s->budget--) { s->failed_pc=0x0c0c9eaau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c9ec8; }
goto P_0c0c9eac;
P_0c0c9eac: /* original c725, guest PC 0x0c0c9eac */
if(!s->budget--) { s->failed_pc=0x0c0c9eacu; return 0; }
r[0]=code_base|0x000c9f44u;
goto P_0c0c9eae;
P_0c0c9eae: /* original f608, guest PC 0x0c0c9eae */
if(!s->budget--) { s->failed_pc=0x0c0c9eaeu; return 0; }
vf3_matrix_load(s,ram,6,r[0]);
goto P_0c0c9eb0;
P_0c0c9eb0: /* original f655, guest PC 0x0c0c9eb0 */
if(!s->budget--) { s->failed_pc=0x0c0c9eb0u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[6])>as_float(fr[5]))!=0);
goto P_0c0c9eb2;
P_0c0c9eb2: /* original 8909, guest PC 0x0c0c9eb2 */
if(!s->budget--) { s->failed_pc=0x0c0c9eb2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c9ec8; }
goto P_0c0c9eb4;
P_0c0c9eb4: /* original c724, guest PC 0x0c0c9eb4 */
if(!s->budget--) { s->failed_pc=0x0c0c9eb4u; return 0; }
r[0]=code_base|0x000c9f48u;
goto P_0c0c9eb6;
P_0c0c9eb6: /* original f508, guest PC 0x0c0c9eb6 */
if(!s->budget--) { s->failed_pc=0x0c0c9eb6u; return 0; }
vf3_matrix_load(s,ram,5,r[0]);
goto P_0c0c9eb8;
P_0c0c9eb8: /* original f455, guest PC 0x0c0c9eb8 */
if(!s->budget--) { s->failed_pc=0x0c0c9eb8u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[4])>as_float(fr[5]))!=0);
goto P_0c0c9eba;
P_0c0c9eba: /* original 8905, guest PC 0x0c0c9eba */
if(!s->budget--) { s->failed_pc=0x0c0c9ebau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c9ec8; }
goto P_0c0c9ebc;
P_0c0c9ebc: /* original c723, guest PC 0x0c0c9ebc */
if(!s->budget--) { s->failed_pc=0x0c0c9ebcu; return 0; }
r[0]=code_base|0x000c9f4cu;
goto P_0c0c9ebe;
P_0c0c9ebe: /* original f508, guest PC 0x0c0c9ebe */
if(!s->budget--) { s->failed_pc=0x0c0c9ebeu; return 0; }
vf3_matrix_load(s,ram,5,r[0]);
goto P_0c0c9ec0;
P_0c0c9ec0: /* original f545, guest PC 0x0c0c9ec0 */
if(!s->budget--) { s->failed_pc=0x0c0c9ec0u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[5])>as_float(fr[4]))!=0);
goto P_0c0c9ec2;
P_0c0c9ec2: /* original 8901, guest PC 0x0c0c9ec2 */
if(!s->budget--) { s->failed_pc=0x0c0c9ec2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c9ec8; }
goto P_0c0c9ec4;
P_0c0c9ec4: /* original a00b, guest PC 0x0c0c9ec4 */
if(!s->budget--) { s->failed_pc=0x0c0c9ec4u; return 0; }
r[14]=r[13];
goto P_0c0c9ede;
P_0c0c9ec6: /* original 6ed3, guest PC 0x0c0c9ec6 */
if(!s->budget--) { s->failed_pc=0x0c0c9ec6u; return 0; }
r[14]=r[13];
goto P_0c0c9ec8;
P_0c0c9ec8: /* original 9039, guest PC 0x0c0c9ec8 */
if(!s->budget--) { s->failed_pc=0x0c0c9ec8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c9f3eu,2);
goto P_0c0c9eca;
P_0c0c9eca: /* original 0ebe, guest PC 0x0c0c9eca */
if(!s->budget--) { s->failed_pc=0x0c0c9ecau; return 0; }
r[14]=read(ram,r[11]+r[0],4);
goto P_0c0c9ecc;
P_0c0c9ecc: /* original 2ee8, guest PC 0x0c0c9ecc */
if(!s->budget--) { s->failed_pc=0x0c0c9eccu; return 0; }
r[17]=(r[17]&~1u)|(((r[14]&r[14])==0)!=0);
goto P_0c0c9ece;
P_0c0c9ece: /* original 8906, guest PC 0x0c0c9ece */
if(!s->budget--) { s->failed_pc=0x0c0c9eceu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c9ede; }
goto P_0c0c9ed0;
P_0c0c9ed0: /* original a005, guest PC 0x0c0c9ed0 */
if(!s->budget--) { s->failed_pc=0x0c0c9ed0u; return 0; }
r[14]=r[12];
goto P_0c0c9ede;
P_0c0c9ed2: /* original 6ec3, guest PC 0x0c0c9ed2 */
if(!s->budget--) { s->failed_pc=0x0c0c9ed2u; return 0; }
r[14]=r[12];
goto P_0c0c9ed4;
P_0c0c9ed4: /* original 5d92, guest PC 0x0c0c9ed4 */
if(!s->budget--) { s->failed_pc=0x0c0c9ed4u; return 0; }
r[13]=read(ram,r[9]+8,4);
goto P_0c0c9ed6;
P_0c0c9ed6: /* original b012, guest PC 0x0c0c9ed6 */
if(!s->budget--) { s->failed_pc=0x0c0c9ed6u; return 0; }
target=code_base|0x0c0c9efeu; r[16]=code_base|0x0c0c9edau;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c9edau) { target=s->pc; goto dispatch; }
goto P_0c0c9eda;
P_0c0c9ed8: /* original 64d3, guest PC 0x0c0c9ed8 */
if(!s->budget--) { s->failed_pc=0x0c0c9ed8u; return 0; }
r[4]=r[13];
goto P_0c0c9eda;
P_0c0c9eda: /* original 4a0b, guest PC 0x0c0c9eda */
if(!s->budget--) { s->failed_pc=0x0c0c9edau; return 0; }
target=r[10];
r[16]=code_base|0x0c0c9edeu;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c9edeu) { target=s->pc; goto dispatch; }
goto P_0c0c9ede;
P_0c0c9edc: /* original 64d3, guest PC 0x0c0c9edc */
if(!s->budget--) { s->failed_pc=0x0c0c9edcu; return 0; }
r[4]=r[13];
goto P_0c0c9ede;
P_0c0c9ede: /* original 60e3, guest PC 0x0c0c9ede */
if(!s->budget--) { s->failed_pc=0x0c0c9edeu; return 0; }
r[0]=r[14];
goto P_0c0c9ee0;
P_0c0c9ee0: /* original 4008, guest PC 0x0c0c9ee0 */
if(!s->budget--) { s->failed_pc=0x0c0c9ee0u; return 0; }
r[0]<<=2;
goto P_0c0c9ee2;
P_0c0c9ee2: /* original 0e9e, guest PC 0x0c0c9ee2 */
if(!s->budget--) { s->failed_pc=0x0c0c9ee2u; return 0; }
r[14]=read(ram,r[9]+r[0],4);
goto P_0c0c9ee4;
P_0c0c9ee4: /* original b00b, guest PC 0x0c0c9ee4 */
if(!s->budget--) { s->failed_pc=0x0c0c9ee4u; return 0; }
target=code_base|0x0c0c9efeu; r[16]=code_base|0x0c0c9ee8u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c9ee8u) { target=s->pc; goto dispatch; }
goto P_0c0c9ee8;
P_0c0c9ee6: /* original 64e3, guest PC 0x0c0c9ee6 */
if(!s->budget--) { s->failed_pc=0x0c0c9ee6u; return 0; }
r[4]=r[14];
goto P_0c0c9ee8;
P_0c0c9ee8: /* original 4a0b, guest PC 0x0c0c9ee8 */
if(!s->budget--) { s->failed_pc=0x0c0c9ee8u; return 0; }
target=r[10];
r[16]=code_base|0x0c0c9eecu;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c9eecu) { target=s->pc; goto dispatch; }
goto P_0c0c9eec;
P_0c0c9eea: /* original 64e3, guest PC 0x0c0c9eea */
if(!s->budget--) { s->failed_pc=0x0c0c9eeau; return 0; }
r[4]=r[14];
goto P_0c0c9eec;
P_0c0c9eec: /* original 7f0c, guest PC 0x0c0c9eec */
if(!s->budget--) { s->failed_pc=0x0c0c9eecu; return 0; }
r[15]+=0x0000000cu;
goto P_0c0c9eee;
P_0c0c9eee: /* original 4f26, guest PC 0x0c0c9eee */
if(!s->budget--) { s->failed_pc=0x0c0c9eeeu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0c9ef0;
P_0c0c9ef0: /* original 69f6, guest PC 0x0c0c9ef0 */
if(!s->budget--) { s->failed_pc=0x0c0c9ef0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c0c9ef2;
P_0c0c9ef2: /* original 6af6, guest PC 0x0c0c9ef2 */
if(!s->budget--) { s->failed_pc=0x0c0c9ef2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0c9ef4;
P_0c0c9ef4: /* original 6bf6, guest PC 0x0c0c9ef4 */
if(!s->budget--) { s->failed_pc=0x0c0c9ef4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0c9ef6;
P_0c0c9ef6: /* original 6cf6, guest PC 0x0c0c9ef6 */
if(!s->budget--) { s->failed_pc=0x0c0c9ef6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0c9ef8;
P_0c0c9ef8: /* original 6df6, guest PC 0x0c0c9ef8 */
if(!s->budget--) { s->failed_pc=0x0c0c9ef8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0c9efa;
P_0c0c9efa: /* original 000b, guest PC 0x0c0c9efa */
if(!s->budget--) { s->failed_pc=0x0c0c9efau; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0c9efc: /* original 6ef6, guest PC 0x0c0c9efc */
if(!s->budget--) { s->failed_pc=0x0c0c9efcu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0c9efe;
P_0c0c9efe: /* original d514, guest PC 0x0c0c9efe */
if(!s->budget--) { s->failed_pc=0x0c0c9efeu; return 0; }
r[5]=read(ram,0x0c0c9f50u,4);
goto P_0c0c9f00;
P_0c0c9f00: /* original e01d, guest PC 0x0c0c9f00 */
if(!s->budget--) { s->failed_pc=0x0c0c9f00u; return 0; }
r[0]=0x0000001du;
goto P_0c0c9f02;
P_0c0c9f02: /* original e304, guest PC 0x0c0c9f02 */
if(!s->budget--) { s->failed_pc=0x0c0c9f02u; return 0; }
r[3]=0x00000004u;
goto P_0c0c9f04;
P_0c0c9f04: /* original 065c, guest PC 0x0c0c9f04 */
if(!s->budget--) { s->failed_pc=0x0c0c9f04u; return 0; }
r[6]=(uint32_t)(int32_t)(int8_t)read(ram,r[5]+r[0],1);
goto P_0c0c9f06;
P_0c0c9f06: /* original 666c, guest PC 0x0c0c9f06 */
if(!s->budget--) { s->failed_pc=0x0c0c9f06u; return 0; }
r[6]=r[6]&255u;
goto P_0c0c9f08;
P_0c0c9f08: /* original 3633, guest PC 0x0c0c9f08 */
if(!s->budget--) { s->failed_pc=0x0c0c9f08u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[6]>=(int32_t)r[3])!=0);
goto P_0c0c9f0a;
P_0c0c9f0a: /* original 8915, guest PC 0x0c0c9f0a */
if(!s->budget--) { s->failed_pc=0x0c0c9f0au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c9f38; }
goto P_0c0c9f0c;
P_0c0c9f0c: /* original 7601, guest PC 0x0c0c9f0c */
if(!s->budget--) { s->failed_pc=0x0c0c9f0cu; return 0; }
r[6]+=0x00000001u;
goto P_0c0c9f0e;
P_0c0c9f0e: /* original 6763, guest PC 0x0c0c9f0e */
if(!s->budget--) { s->failed_pc=0x0c0c9f0eu; return 0; }
r[7]=r[6];
goto P_0c0c9f10;
P_0c0c9f10: /* original 6353, guest PC 0x0c0c9f10 */
if(!s->budget--) { s->failed_pc=0x0c0c9f10u; return 0; }
r[3]=r[5];
goto P_0c0c9f12;
P_0c0c9f12: /* original 77ff, guest PC 0x0c0c9f12 */
if(!s->budget--) { s->failed_pc=0x0c0c9f12u; return 0; }
r[7]+=0xffffffffu;
goto P_0c0c9f14;
P_0c0c9f14: /* original 7330, guest PC 0x0c0c9f14 */
if(!s->budget--) { s->failed_pc=0x0c0c9f14u; return 0; }
r[3]+=0x00000030u;
goto P_0c0c9f16;
P_0c0c9f16: /* original 4708, guest PC 0x0c0c9f16 */
if(!s->budget--) { s->failed_pc=0x0c0c9f16u; return 0; }
r[7]<<=2;
goto P_0c0c9f18;
P_0c0c9f18: /* original 373c, guest PC 0x0c0c9f18 */
if(!s->budget--) { s->failed_pc=0x0c0c9f18u; return 0; }
r[7]+=r[3];
goto P_0c0c9f1a;
P_0c0c9f1a: /* original 6772, guest PC 0x0c0c9f1a */
if(!s->budget--) { s->failed_pc=0x0c0c9f1au; return 0; }
tmp=read(ram,r[7],4);
r[7]=tmp;
goto P_0c0c9f1c;
P_0c0c9f1c: /* original 3470, guest PC 0x0c0c9f1c */
if(!s->budget--) { s->failed_pc=0x0c0c9f1cu; return 0; }
r[17]=(r[17]&~1u)|((r[4]==r[7])!=0);
goto P_0c0c9f1e;
P_0c0c9f1e: /* original 890b, guest PC 0x0c0c9f1e */
if(!s->budget--) { s->failed_pc=0x0c0c9f1eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c9f38; }
goto P_0c0c9f20;
P_0c0c9f20: /* original 4610, guest PC 0x0c0c9f20 */
if(!s->budget--) { s->failed_pc=0x0c0c9f20u; return 0; }
--r[6];
r[17]=(r[17]&~1u)|((r[6]==0)!=0);
goto P_0c0c9f22;
P_0c0c9f22: /* original 8bf4, guest PC 0x0c0c9f22 */
if(!s->budget--) { s->failed_pc=0x0c0c9f22u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c9f0e; }
goto P_0c0c9f24;
P_0c0c9f24: /* original 025c, guest PC 0x0c0c9f24 */
if(!s->budget--) { s->failed_pc=0x0c0c9f24u; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[5]+r[0],1);
goto P_0c0c9f26;
P_0c0c9f26: /* original 6353, guest PC 0x0c0c9f26 */
if(!s->budget--) { s->failed_pc=0x0c0c9f26u; return 0; }
r[3]=r[5];
goto P_0c0c9f28;
P_0c0c9f28: /* original 7330, guest PC 0x0c0c9f28 */
if(!s->budget--) { s->failed_pc=0x0c0c9f28u; return 0; }
r[3]+=0x00000030u;
goto P_0c0c9f2a;
P_0c0c9f2a: /* original 622c, guest PC 0x0c0c9f2a */
if(!s->budget--) { s->failed_pc=0x0c0c9f2au; return 0; }
r[2]=r[2]&255u;
goto P_0c0c9f2c;
P_0c0c9f2c: /* original 4208, guest PC 0x0c0c9f2c */
if(!s->budget--) { s->failed_pc=0x0c0c9f2cu; return 0; }
r[2]<<=2;
goto P_0c0c9f2e;
P_0c0c9f2e: /* original 323c, guest PC 0x0c0c9f2e */
if(!s->budget--) { s->failed_pc=0x0c0c9f2eu; return 0; }
r[2]+=r[3];
goto P_0c0c9f30;
P_0c0c9f30: /* original 2242, guest PC 0x0c0c9f30 */
if(!s->budget--) { s->failed_pc=0x0c0c9f30u; return 0; }
write(ram,r[2],r[4],4);
goto P_0c0c9f32;
P_0c0c9f32: /* original 025c, guest PC 0x0c0c9f32 */
if(!s->budget--) { s->failed_pc=0x0c0c9f32u; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[5]+r[0],1);
goto P_0c0c9f34;
P_0c0c9f34: /* original 7201, guest PC 0x0c0c9f34 */
if(!s->budget--) { s->failed_pc=0x0c0c9f34u; return 0; }
r[2]+=0x00000001u;
goto P_0c0c9f36;
P_0c0c9f36: /* original 0524, guest PC 0x0c0c9f36 */
if(!s->budget--) { s->failed_pc=0x0c0c9f36u; return 0; }
write(ram,r[5]+r[0],r[2],1);
goto P_0c0c9f38;
P_0c0c9f38: /* original 000b, guest PC 0x0c0c9f38 */
if(!s->budget--) { s->failed_pc=0x0c0c9f38u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c0c9f3a: /* original 0009, guest PC 0x0c0c9f3a */
if(!s->budget--) { s->failed_pc=0x0c0c9f3au; return 0; }
if(!vf3_matrix_family(0x0c0c9f3cu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0c9f3cu; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
