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
int vf3_away_batch6_adapter_21(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c053ca4u: goto P_0c053ca4;
case 0x0c053ca6u: goto P_0c053ca6;
case 0x0c053ca8u: goto P_0c053ca8;
case 0x0c053caau: goto P_0c053caa;
case 0x0c053cacu: goto P_0c053cac;
case 0x0c053caeu: goto P_0c053cae;
case 0x0c053cb0u: goto P_0c053cb0;
case 0x0c053cb2u: goto P_0c053cb2;
case 0x0c053cb4u: goto P_0c053cb4;
case 0x0c053cb6u: goto P_0c053cb6;
case 0x0c053cb8u: goto P_0c053cb8;
case 0x0c053cbau: goto P_0c053cba;
case 0x0c053cbcu: goto P_0c053cbc;
case 0x0c053cbeu: goto P_0c053cbe;
case 0x0c053cc0u: goto P_0c053cc0;
case 0x0c053cc2u: goto P_0c053cc2;
case 0x0c053cc4u: goto P_0c053cc4;
case 0x0c053cc6u: goto P_0c053cc6;
case 0x0c053cc8u: goto P_0c053cc8;
case 0x0c053ccau: goto P_0c053cca;
case 0x0c053cccu: goto P_0c053ccc;
case 0x0c053cceu: goto P_0c053cce;
case 0x0c053cd0u: goto P_0c053cd0;
case 0x0c053cd2u: goto P_0c053cd2;
case 0x0c053cd4u: goto P_0c053cd4;
case 0x0c053cd6u: goto P_0c053cd6;
case 0x0c053cd8u: goto P_0c053cd8;
case 0x0c053cdau: goto P_0c053cda;
case 0x0c053cdcu: goto P_0c053cdc;
case 0x0c053cdeu: goto P_0c053cde;
case 0x0c053ce0u: goto P_0c053ce0;
case 0x0c053ce2u: goto P_0c053ce2;
case 0x0c053ce4u: goto P_0c053ce4;
case 0x0c053ce6u: goto P_0c053ce6;
case 0x0c053ce8u: goto P_0c053ce8;
case 0x0c053ceau: goto P_0c053cea;
case 0x0c053cecu: goto P_0c053cec;
case 0x0c053ceeu: goto P_0c053cee;
case 0x0c053cf0u: goto P_0c053cf0;
case 0x0c053cf2u: goto P_0c053cf2;
case 0x0c053cf4u: goto P_0c053cf4;
case 0x0c053cf6u: goto P_0c053cf6;
case 0x0c053cf8u: goto P_0c053cf8;
case 0x0c053cfau: goto P_0c053cfa;
case 0x0c053cfcu: goto P_0c053cfc;
case 0x0c053cfeu: goto P_0c053cfe;
case 0x0c053d00u: goto P_0c053d00;
case 0x0c053d02u: goto P_0c053d02;
case 0x0c053d04u: goto P_0c053d04;
case 0x0c053d06u: goto P_0c053d06;
case 0x0c053d08u: goto P_0c053d08;
case 0x0c053d0au: goto P_0c053d0a;
case 0x0c053d0cu: goto P_0c053d0c;
case 0x0c053d0eu: goto P_0c053d0e;
case 0x0c053d10u: goto P_0c053d10;
case 0x0c053d12u: goto P_0c053d12;
case 0x0c053d14u: goto P_0c053d14;
case 0x0c053d16u: goto P_0c053d16;
case 0x0c053d18u: goto P_0c053d18;
case 0x0c053d1au: goto P_0c053d1a;
case 0x0c053d1cu: goto P_0c053d1c;
case 0x0c053d1eu: goto P_0c053d1e;
case 0x0c053d20u: goto P_0c053d20;
case 0x0c053d22u: goto P_0c053d22;
case 0x0c053d24u: goto P_0c053d24;
case 0x0c053d26u: goto P_0c053d26;
case 0x0c053d28u: goto P_0c053d28;
case 0x0c053d2au: goto P_0c053d2a;
case 0x0c053d2cu: goto P_0c053d2c;
case 0x0c053d2eu: goto P_0c053d2e;
case 0x0c053db4u: goto P_0c053db4;
case 0x0c053db6u: goto P_0c053db6;
case 0x0c053db8u: goto P_0c053db8;
case 0x0c053dbau: goto P_0c053dba;
case 0x0c053dbcu: goto P_0c053dbc;
case 0x0c053dbeu: goto P_0c053dbe;
case 0x0c053dc0u: goto P_0c053dc0;
case 0x0c053dc2u: goto P_0c053dc2;
case 0x0c053dc4u: goto P_0c053dc4;
case 0x0c053dc6u: goto P_0c053dc6;
case 0x0c053dc8u: goto P_0c053dc8;
case 0x0c053dcau: goto P_0c053dca;
case 0x0c053dccu: goto P_0c053dcc;
case 0x0c053dceu: goto P_0c053dce;
case 0x0c053dd0u: goto P_0c053dd0;
case 0x0c053dd2u: goto P_0c053dd2;
case 0x0c053dd4u: goto P_0c053dd4;
case 0x0c053dd6u: goto P_0c053dd6;
case 0x0c053dd8u: goto P_0c053dd8;
case 0x0c053ddau: goto P_0c053dda;
case 0x0c053ddcu: goto P_0c053ddc;
case 0x0c053ddeu: goto P_0c053dde;
case 0x0c053de0u: goto P_0c053de0;
case 0x0c053de2u: goto P_0c053de2;
case 0x0c053de4u: goto P_0c053de4;
case 0x0c053de6u: goto P_0c053de6;
case 0x0c053de8u: goto P_0c053de8;
case 0x0c053deau: goto P_0c053dea;
case 0x0c053decu: goto P_0c053dec;
case 0x0c053deeu: goto P_0c053dee;
case 0x0c053df0u: goto P_0c053df0;
case 0x0c053df2u: goto P_0c053df2;
case 0x0c053df4u: goto P_0c053df4;
case 0x0c053df6u: goto P_0c053df6;
case 0x0c053df8u: goto P_0c053df8;
case 0x0c053dfau: goto P_0c053dfa;
case 0x0c053dfcu: goto P_0c053dfc;
case 0x0c053dfeu: goto P_0c053dfe;
case 0x0c053e00u: goto P_0c053e00;
case 0x0c053e02u: goto P_0c053e02;
case 0x0c053e04u: goto P_0c053e04;
case 0x0c053e06u: goto P_0c053e06;
case 0x0c053e08u: goto P_0c053e08;
case 0x0c053e0au: goto P_0c053e0a;
case 0x0c053e0cu: goto P_0c053e0c;
case 0x0c053e0eu: goto P_0c053e0e;
case 0x0c053e10u: goto P_0c053e10;
case 0x0c053e12u: goto P_0c053e12;
case 0x0c053e14u: goto P_0c053e14;
case 0x0c053e16u: goto P_0c053e16;
case 0x0c053e18u: goto P_0c053e18;
case 0x0c053e1au: goto P_0c053e1a;
case 0x0c053e1cu: goto P_0c053e1c;
case 0x0c053e1eu: goto P_0c053e1e;
case 0x0c053e20u: goto P_0c053e20;
case 0x0c053e22u: goto P_0c053e22;
case 0x0c053e24u: goto P_0c053e24;
case 0x0c053e26u: goto P_0c053e26;
case 0x0c053e28u: goto P_0c053e28;
case 0x0c053e2au: goto P_0c053e2a;
case 0x0c053e2cu: goto P_0c053e2c;
case 0x0c053e2eu: goto P_0c053e2e;
case 0x0c053e30u: goto P_0c053e30;
case 0x0c053e32u: goto P_0c053e32;
case 0x0c053e34u: goto P_0c053e34;
case 0x0c053e36u: goto P_0c053e36;
case 0x0c053e38u: goto P_0c053e38;
case 0x0c053e3au: goto P_0c053e3a;
case 0x0c053e3cu: goto P_0c053e3c;
case 0x0c053e3eu: goto P_0c053e3e;
case 0x0c053e40u: goto P_0c053e40;
case 0x0c053e42u: goto P_0c053e42;
case 0x0c053e44u: goto P_0c053e44;
case 0x0c053e46u: goto P_0c053e46;
case 0x0c053e48u: goto P_0c053e48;
case 0x0c053e4au: goto P_0c053e4a;
case 0x0c053e4cu: goto P_0c053e4c;
case 0x0c053e4eu: goto P_0c053e4e;
case 0x0c053e50u: goto P_0c053e50;
case 0x0c053e52u: goto P_0c053e52;
case 0x0c053e54u: goto P_0c053e54;
case 0x0c053e56u: goto P_0c053e56;
case 0x0c053e58u: goto P_0c053e58;
case 0x0c053e5au: goto P_0c053e5a;
case 0x0c053e5cu: goto P_0c053e5c;
case 0x0c053e5eu: goto P_0c053e5e;
case 0x0c053e60u: goto P_0c053e60;
case 0x0c053e62u: goto P_0c053e62;
case 0x0c053e64u: goto P_0c053e64;
case 0x0c053e66u: goto P_0c053e66;
case 0x0c053e68u: goto P_0c053e68;
case 0x0c053e6au: goto P_0c053e6a;
case 0x0c053e6cu: goto P_0c053e6c;
case 0x0c053e6eu: goto P_0c053e6e;
case 0x0c053e70u: goto P_0c053e70;
case 0x0c053e72u: goto P_0c053e72;
case 0x0c053e74u: goto P_0c053e74;
case 0x0c053e76u: goto P_0c053e76;
case 0x0c053e78u: goto P_0c053e78;
case 0x0c053e7au: goto P_0c053e7a;
case 0x0c053e7cu: goto P_0c053e7c;
case 0x0c053e7eu: goto P_0c053e7e;
case 0x0c053e80u: goto P_0c053e80;
case 0x0c053e82u: goto P_0c053e82;
case 0x0c053e84u: goto P_0c053e84;
case 0x0c053e86u: goto P_0c053e86;
case 0x0c053e88u: goto P_0c053e88;
case 0x0c053e8au: goto P_0c053e8a;
case 0x0c053e8cu: goto P_0c053e8c;
case 0x0c053e8eu: goto P_0c053e8e;
case 0x0c053e90u: goto P_0c053e90;
case 0x0c053e92u: goto P_0c053e92;
case 0x0c053e94u: goto P_0c053e94;
case 0x0c053e96u: goto P_0c053e96;
case 0x0c053e98u: goto P_0c053e98;
case 0x0c053e9au: goto P_0c053e9a;
case 0x0c053e9cu: goto P_0c053e9c;
case 0x0c053e9eu: goto P_0c053e9e;
case 0x0c053ea0u: goto P_0c053ea0;
case 0x0c053ea2u: goto P_0c053ea2;
case 0x0c053ea4u: goto P_0c053ea4;
case 0x0c053ea6u: goto P_0c053ea6;
case 0x0c053ea8u: goto P_0c053ea8;
case 0x0c053eaau: goto P_0c053eaa;
case 0x0c053eacu: goto P_0c053eac;
case 0x0c053eaeu: goto P_0c053eae;
case 0x0c053eb0u: goto P_0c053eb0;
case 0x0c053eb2u: goto P_0c053eb2;
case 0x0c053ed4u: goto P_0c053ed4;
case 0x0c053ed6u: goto P_0c053ed6;
case 0x0c053ed8u: goto P_0c053ed8;
case 0x0c053edau: goto P_0c053eda;
case 0x0c053edcu: goto P_0c053edc;
case 0x0c053edeu: goto P_0c053ede;
case 0x0c053ee0u: goto P_0c053ee0;
case 0x0c053ee2u: goto P_0c053ee2;
case 0x0c053ee4u: goto P_0c053ee4;
case 0x0c053ee6u: goto P_0c053ee6;
case 0x0c053ee8u: goto P_0c053ee8;
case 0x0c053eeau: goto P_0c053eea;
case 0x0c053eecu: goto P_0c053eec;
case 0x0c053eeeu: goto P_0c053eee;
case 0x0c053ef0u: goto P_0c053ef0;
case 0x0c053ef2u: goto P_0c053ef2;
case 0x0c053ef4u: goto P_0c053ef4;
case 0x0c053ef6u: goto P_0c053ef6;
case 0x0c053ef8u: goto P_0c053ef8;
case 0x0c053efau: goto P_0c053efa;
case 0x0c053efcu: goto P_0c053efc;
case 0x0c053efeu: goto P_0c053efe;
case 0x0c053f00u: goto P_0c053f00;
case 0x0c053f02u: goto P_0c053f02;
case 0x0c053f04u: goto P_0c053f04;
case 0x0c053f06u: goto P_0c053f06;
case 0x0c053f08u: goto P_0c053f08;
case 0x0c053f0au: goto P_0c053f0a;
case 0x0c053f0cu: goto P_0c053f0c;
case 0x0c053f0eu: goto P_0c053f0e;
case 0x0c053f10u: goto P_0c053f10;
case 0x0c053f12u: goto P_0c053f12;
case 0x0c053f14u: goto P_0c053f14;
case 0x0c053f16u: goto P_0c053f16;
case 0x0c053f18u: goto P_0c053f18;
case 0x0c053f1au: goto P_0c053f1a;
case 0x0c053f1cu: goto P_0c053f1c;
case 0x0c053f1eu: goto P_0c053f1e;
case 0x0c053f20u: goto P_0c053f20;
case 0x0c053f22u: goto P_0c053f22;
case 0x0c053f24u: goto P_0c053f24;
case 0x0c053f26u: goto P_0c053f26;
case 0x0c053f28u: goto P_0c053f28;
case 0x0c053f2au: goto P_0c053f2a;
case 0x0c053f2cu: goto P_0c053f2c;
case 0x0c053f2eu: goto P_0c053f2e;
case 0x0c053f30u: goto P_0c053f30;
case 0x0c053f32u: goto P_0c053f32;
case 0x0c053f34u: goto P_0c053f34;
default: return vf3_matrix_family(target,s,ram);
}
P_0c053ca4: /* original 2fe6, guest PC 0x0c053ca4 */
if(!s->budget--) { s->failed_pc=0x0c053ca4u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c053ca6;
P_0c053ca6: /* original 6e43, guest PC 0x0c053ca6 */
if(!s->budget--) { s->failed_pc=0x0c053ca6u; return 0; }
r[14]=r[4];
goto P_0c053ca8;
P_0c053ca8: /* original d026, guest PC 0x0c053ca8 */
if(!s->budget--) { s->failed_pc=0x0c053ca8u; return 0; }
r[0]=read(ram,0x0c053d44u,4);
goto P_0c053caa;
P_0c053caa: /* original 4e08, guest PC 0x0c053caa */
if(!s->budget--) { s->failed_pc=0x0c053caau; return 0; }
r[14]<<=2;
goto P_0c053cac;
P_0c053cac: /* original 4f22, guest PC 0x0c053cac */
if(!s->budget--) { s->failed_pc=0x0c053cacu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c053cae;
P_0c053cae: /* original 0eee, guest PC 0x0c053cae */
if(!s->budget--) { s->failed_pc=0x0c053caeu; return 0; }
r[14]=read(ram,r[14]+r[0],4);
goto P_0c053cb0;
P_0c053cb0: /* original d325, guest PC 0x0c053cb0 */
if(!s->budget--) { s->failed_pc=0x0c053cb0u; return 0; }
r[3]=read(ram,0x0c053d48u,4);
goto P_0c053cb2;
P_0c053cb2: /* original 7ffc, guest PC 0x0c053cb2 */
if(!s->budget--) { s->failed_pc=0x0c053cb2u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c053cb4;
P_0c053cb4: /* original 430b, guest PC 0x0c053cb4 */
if(!s->budget--) { s->failed_pc=0x0c053cb4u; return 0; }
target=r[3];
r[16]=code_base|0x0c053cb8u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c053cb8u) { target=s->pc; goto dispatch; }
goto P_0c053cb8;
P_0c053cb6: /* original 64e3, guest PC 0x0c053cb6 */
if(!s->budget--) { s->failed_pc=0x0c053cb6u; return 0; }
r[4]=r[14];
goto P_0c053cb8;
P_0c053cb8: /* original 2f02, guest PC 0x0c053cb8 */
if(!s->budget--) { s->failed_pc=0x0c053cb8u; return 0; }
write(ram,r[15],r[0],4);
goto P_0c053cba;
P_0c053cba: /* original d324, guest PC 0x0c053cba */
if(!s->budget--) { s->failed_pc=0x0c053cbau; return 0; }
r[3]=read(ram,0x0c053d4cu,4);
goto P_0c053cbc;
P_0c053cbc: /* original 430b, guest PC 0x0c053cbc */
if(!s->budget--) { s->failed_pc=0x0c053cbcu; return 0; }
target=r[3];
r[16]=code_base|0x0c053cc0u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c053cc0u) { target=s->pc; goto dispatch; }
goto P_0c053cc0;
P_0c053cbe: /* original 64e3, guest PC 0x0c053cbe */
if(!s->budget--) { s->failed_pc=0x0c053cbeu; return 0; }
r[4]=r[14];
goto P_0c053cc0;
P_0c053cc0: /* original 62f2, guest PC 0x0c053cc0 */
if(!s->budget--) { s->failed_pc=0x0c053cc0u; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c053cc2;
P_0c053cc2: /* original 6403, guest PC 0x0c053cc2 */
if(!s->budget--) { s->failed_pc=0x0c053cc2u; return 0; }
r[4]=r[0];
goto P_0c053cc4;
P_0c053cc4: /* original 6320, guest PC 0x0c053cc4 */
if(!s->budget--) { s->failed_pc=0x0c053cc4u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[2],1);
r[3]=tmp;
goto P_0c053cc6;
P_0c053cc6: /* original 2338, guest PC 0x0c053cc6 */
if(!s->budget--) { s->failed_pc=0x0c053cc6u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c053cc8;
P_0c053cc8: /* original 8902, guest PC 0x0c053cc8 */
if(!s->budget--) { s->failed_pc=0x0c053cc8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c053cd0; }
goto P_0c053cca;
P_0c053cca: /* original 6042, guest PC 0x0c053cca */
if(!s->budget--) { s->failed_pc=0x0c053ccau; return 0; }
tmp=read(ram,r[4],4);
r[0]=tmp;
goto P_0c053ccc;
P_0c053ccc: /* original c802, guest PC 0x0c053ccc */
if(!s->budget--) { s->failed_pc=0x0c053cccu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&2u)==0)!=0);
goto P_0c053cce;
P_0c053cce: /* original 8b04, guest PC 0x0c053cce */
if(!s->budget--) { s->failed_pc=0x0c053cceu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c053cda; }
goto P_0c053cd0;
P_0c053cd0: /* original 7f04, guest PC 0x0c053cd0 */
if(!s->budget--) { s->failed_pc=0x0c053cd0u; return 0; }
r[15]+=0x00000004u;
goto P_0c053cd2;
P_0c053cd2: /* original 4f26, guest PC 0x0c053cd2 */
if(!s->budget--) { s->failed_pc=0x0c053cd2u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c053cd4;
P_0c053cd4: /* original e000, guest PC 0x0c053cd4 */
if(!s->budget--) { s->failed_pc=0x0c053cd4u; return 0; }
r[0]=0x00000000u;
goto P_0c053cd6;
P_0c053cd6: /* original 000b, guest PC 0x0c053cd6 */
if(!s->budget--) { s->failed_pc=0x0c053cd6u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c053cd8: /* original 6ef6, guest PC 0x0c053cd8 */
if(!s->budget--) { s->failed_pc=0x0c053cd8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c053cda;
P_0c053cda: /* original e001, guest PC 0x0c053cda */
if(!s->budget--) { s->failed_pc=0x0c053cdau; return 0; }
r[0]=0x00000001u;
goto P_0c053cdc;
P_0c053cdc: /* original 7f04, guest PC 0x0c053cdc */
if(!s->budget--) { s->failed_pc=0x0c053cdcu; return 0; }
r[15]+=0x00000004u;
goto P_0c053cde;
P_0c053cde: /* original 4f26, guest PC 0x0c053cde */
if(!s->budget--) { s->failed_pc=0x0c053cdeu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c053ce0;
P_0c053ce0: /* original 000b, guest PC 0x0c053ce0 */
if(!s->budget--) { s->failed_pc=0x0c053ce0u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c053ce2: /* original 6ef6, guest PC 0x0c053ce2 */
if(!s->budget--) { s->failed_pc=0x0c053ce2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c053ce4;
P_0c053ce4: /* original 2fe6, guest PC 0x0c053ce4 */
if(!s->budget--) { s->failed_pc=0x0c053ce4u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c053ce6;
P_0c053ce6: /* original 6e43, guest PC 0x0c053ce6 */
if(!s->budget--) { s->failed_pc=0x0c053ce6u; return 0; }
r[14]=r[4];
goto P_0c053ce8;
P_0c053ce8: /* original d016, guest PC 0x0c053ce8 */
if(!s->budget--) { s->failed_pc=0x0c053ce8u; return 0; }
r[0]=read(ram,0x0c053d44u,4);
goto P_0c053cea;
P_0c053cea: /* original 4e08, guest PC 0x0c053cea */
if(!s->budget--) { s->failed_pc=0x0c053ceau; return 0; }
r[14]<<=2;
goto P_0c053cec;
P_0c053cec: /* original 4f22, guest PC 0x0c053cec */
if(!s->budget--) { s->failed_pc=0x0c053cecu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c053cee;
P_0c053cee: /* original 0eee, guest PC 0x0c053cee */
if(!s->budget--) { s->failed_pc=0x0c053ceeu; return 0; }
r[14]=read(ram,r[14]+r[0],4);
goto P_0c053cf0;
P_0c053cf0: /* original d315, guest PC 0x0c053cf0 */
if(!s->budget--) { s->failed_pc=0x0c053cf0u; return 0; }
r[3]=read(ram,0x0c053d48u,4);
goto P_0c053cf2;
P_0c053cf2: /* original 7ff8, guest PC 0x0c053cf2 */
if(!s->budget--) { s->failed_pc=0x0c053cf2u; return 0; }
r[15]+=0xfffffff8u;
goto P_0c053cf4;
P_0c053cf4: /* original 430b, guest PC 0x0c053cf4 */
if(!s->budget--) { s->failed_pc=0x0c053cf4u; return 0; }
target=r[3];
r[16]=code_base|0x0c053cf8u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c053cf8u) { target=s->pc; goto dispatch; }
goto P_0c053cf8;
P_0c053cf6: /* original 64e3, guest PC 0x0c053cf6 */
if(!s->budget--) { s->failed_pc=0x0c053cf6u; return 0; }
r[4]=r[14];
goto P_0c053cf8;
P_0c053cf8: /* original 1f01, guest PC 0x0c053cf8 */
if(!s->budget--) { s->failed_pc=0x0c053cf8u; return 0; }
write(ram,r[15]+4,r[0],4);
goto P_0c053cfa;
P_0c053cfa: /* original d314, guest PC 0x0c053cfa */
if(!s->budget--) { s->failed_pc=0x0c053cfau; return 0; }
r[3]=read(ram,0x0c053d4cu,4);
goto P_0c053cfc;
P_0c053cfc: /* original 430b, guest PC 0x0c053cfc */
if(!s->budget--) { s->failed_pc=0x0c053cfcu; return 0; }
target=r[3];
r[16]=code_base|0x0c053d00u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c053d00u) { target=s->pc; goto dispatch; }
goto P_0c053d00;
P_0c053cfe: /* original 64e3, guest PC 0x0c053cfe */
if(!s->budget--) { s->failed_pc=0x0c053cfeu; return 0; }
r[4]=r[14];
goto P_0c053d00;
P_0c053d00: /* original 2f02, guest PC 0x0c053d00 */
if(!s->budget--) { s->failed_pc=0x0c053d00u; return 0; }
write(ram,r[15],r[0],4);
goto P_0c053d02;
P_0c053d02: /* original 53f1, guest PC 0x0c053d02 */
if(!s->budget--) { s->failed_pc=0x0c053d02u; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c053d04;
P_0c053d04: /* original 6230, guest PC 0x0c053d04 */
if(!s->budget--) { s->failed_pc=0x0c053d04u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[3],1);
r[2]=tmp;
goto P_0c053d06;
P_0c053d06: /* original 2228, guest PC 0x0c053d06 */
if(!s->budget--) { s->failed_pc=0x0c053d06u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c053d08;
P_0c053d08: /* original 8908, guest PC 0x0c053d08 */
if(!s->budget--) { s->failed_pc=0x0c053d08u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c053d1c; }
goto P_0c053d0a;
P_0c053d0a: /* original d311, guest PC 0x0c053d0a */
if(!s->budget--) { s->failed_pc=0x0c053d0au; return 0; }
r[3]=read(ram,0x0c053d50u,4);
goto P_0c053d0c;
P_0c053d0c: /* original 430b, guest PC 0x0c053d0c */
if(!s->budget--) { s->failed_pc=0x0c053d0cu; return 0; }
target=r[3];
r[16]=code_base|0x0c053d10u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c053d10u) { target=s->pc; goto dispatch; }
goto P_0c053d10;
P_0c053d0e: /* original 64e3, guest PC 0x0c053d0e */
if(!s->budget--) { s->failed_pc=0x0c053d0eu; return 0; }
r[4]=r[14];
goto P_0c053d10;
P_0c053d10: /* original 2008, guest PC 0x0c053d10 */
if(!s->budget--) { s->failed_pc=0x0c053d10u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c053d12;
P_0c053d12: /* original 8b03, guest PC 0x0c053d12 */
if(!s->budget--) { s->failed_pc=0x0c053d12u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c053d1c; }
goto P_0c053d14;
P_0c053d14: /* original 60f2, guest PC 0x0c053d14 */
if(!s->budget--) { s->failed_pc=0x0c053d14u; return 0; }
tmp=read(ram,r[15],4);
r[0]=tmp;
goto P_0c053d16;
P_0c053d16: /* original 6002, guest PC 0x0c053d16 */
if(!s->budget--) { s->failed_pc=0x0c053d16u; return 0; }
tmp=read(ram,r[0],4);
r[0]=tmp;
goto P_0c053d18;
P_0c053d18: /* original c802, guest PC 0x0c053d18 */
if(!s->budget--) { s->failed_pc=0x0c053d18u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&2u)==0)!=0);
goto P_0c053d1a;
P_0c053d1a: /* original 8b04, guest PC 0x0c053d1a */
if(!s->budget--) { s->failed_pc=0x0c053d1au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c053d26; }
goto P_0c053d1c;
P_0c053d1c: /* original 7f08, guest PC 0x0c053d1c */
if(!s->budget--) { s->failed_pc=0x0c053d1cu; return 0; }
r[15]+=0x00000008u;
goto P_0c053d1e;
P_0c053d1e: /* original 4f26, guest PC 0x0c053d1e */
if(!s->budget--) { s->failed_pc=0x0c053d1eu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c053d20;
P_0c053d20: /* original e000, guest PC 0x0c053d20 */
if(!s->budget--) { s->failed_pc=0x0c053d20u; return 0; }
r[0]=0x00000000u;
goto P_0c053d22;
P_0c053d22: /* original 000b, guest PC 0x0c053d22 */
if(!s->budget--) { s->failed_pc=0x0c053d22u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c053d24: /* original 6ef6, guest PC 0x0c053d24 */
if(!s->budget--) { s->failed_pc=0x0c053d24u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c053d26;
P_0c053d26: /* original e001, guest PC 0x0c053d26 */
if(!s->budget--) { s->failed_pc=0x0c053d26u; return 0; }
r[0]=0x00000001u;
goto P_0c053d28;
P_0c053d28: /* original 7f08, guest PC 0x0c053d28 */
if(!s->budget--) { s->failed_pc=0x0c053d28u; return 0; }
r[15]+=0x00000008u;
goto P_0c053d2a;
P_0c053d2a: /* original 4f26, guest PC 0x0c053d2a */
if(!s->budget--) { s->failed_pc=0x0c053d2au; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c053d2c;
P_0c053d2c: /* original 000b, guest PC 0x0c053d2c */
if(!s->budget--) { s->failed_pc=0x0c053d2cu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c053d2e: /* original 6ef6, guest PC 0x0c053d2e */
if(!s->budget--) { s->failed_pc=0x0c053d2eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c053d30u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c053d30u; return 0; } return 1;
P_0c053db4: /* original 4515, guest PC 0x0c053db4 */
if(!s->budget--) { s->failed_pc=0x0c053db4u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[5]>0)!=0);
goto P_0c053db6;
P_0c053db6: /* original 8f0a, guest PC 0x0c053db6 */
if(!s->budget--) { s->failed_pc=0x0c053db6u; return 0; }
cond=r[17]&1u;
r[6]=0x00000000u;
if(!cond) { goto P_0c053dce; }
goto P_0c053dba;
P_0c053db8: /* original e600, guest PC 0x0c053db8 */
if(!s->budget--) { s->failed_pc=0x0c053db8u; return 0; }
r[6]=0x00000000u;
goto P_0c053dba;
P_0c053dba: /* original 6240, guest PC 0x0c053dba */
if(!s->budget--) { s->failed_pc=0x0c053dbau; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[4],1);
r[2]=tmp;
goto P_0c053dbc;
P_0c053dbc: /* original 2228, guest PC 0x0c053dbc */
if(!s->budget--) { s->failed_pc=0x0c053dbcu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c053dbe;
P_0c053dbe: /* original 8d02, guest PC 0x0c053dbe */
if(!s->budget--) { s->failed_pc=0x0c053dbeu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c053dc6; }
goto P_0c053dc2;
P_0c053dc0: /* original 0009, guest PC 0x0c053dc0 */
if(!s->budget--) { s->failed_pc=0x0c053dc0u; return 0; }
goto P_0c053dc2;
P_0c053dc2: /* original 000b, guest PC 0x0c053dc2 */
if(!s->budget--) { s->failed_pc=0x0c053dc2u; return 0; }
target=r[16];
r[0]=0x00000000u;
s->pc=target; return ram->oob==0;
P_0c053dc4: /* original e000, guest PC 0x0c053dc4 */
if(!s->budget--) { s->failed_pc=0x0c053dc4u; return 0; }
r[0]=0x00000000u;
goto P_0c053dc6;
P_0c053dc6: /* original 7601, guest PC 0x0c053dc6 */
if(!s->budget--) { s->failed_pc=0x0c053dc6u; return 0; }
r[6]+=0x00000001u;
goto P_0c053dc8;
P_0c053dc8: /* original 3653, guest PC 0x0c053dc8 */
if(!s->budget--) { s->failed_pc=0x0c053dc8u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[6]>=(int32_t)r[5])!=0);
goto P_0c053dca;
P_0c053dca: /* original 8ff6, guest PC 0x0c053dca */
if(!s->budget--) { s->failed_pc=0x0c053dcau; return 0; }
cond=r[17]&1u;
r[4]+=0x00000001u;
if(!cond) { goto P_0c053dba; }
goto P_0c053dce;
P_0c053dcc: /* original 7401, guest PC 0x0c053dcc */
if(!s->budget--) { s->failed_pc=0x0c053dccu; return 0; }
r[4]+=0x00000001u;
goto P_0c053dce;
P_0c053dce: /* original e001, guest PC 0x0c053dce */
if(!s->budget--) { s->failed_pc=0x0c053dceu; return 0; }
r[0]=0x00000001u;
goto P_0c053dd0;
P_0c053dd0: /* original 000b, guest PC 0x0c053dd0 */
if(!s->budget--) { s->failed_pc=0x0c053dd0u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c053dd2: /* original 0009, guest PC 0x0c053dd2 */
if(!s->budget--) { s->failed_pc=0x0c053dd2u; return 0; }
goto P_0c053dd4;
P_0c053dd4: /* original 2fe6, guest PC 0x0c053dd4 */
if(!s->budget--) { s->failed_pc=0x0c053dd4u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c053dd6;
P_0c053dd6: /* original 2fd6, guest PC 0x0c053dd6 */
if(!s->budget--) { s->failed_pc=0x0c053dd6u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c053dd8;
P_0c053dd8: /* original 2fc6, guest PC 0x0c053dd8 */
if(!s->budget--) { s->failed_pc=0x0c053dd8u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c053dda;
P_0c053dda: /* original 4f22, guest PC 0x0c053dda */
if(!s->budget--) { s->failed_pc=0x0c053ddau; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c053ddc;
P_0c053ddc: /* original 7fe0, guest PC 0x0c053ddc */
if(!s->budget--) { s->failed_pc=0x0c053ddcu; return 0; }
r[15]+=0xffffffe0u;
goto P_0c053dde;
P_0c053dde: /* original 6043, guest PC 0x0c053dde */
if(!s->budget--) { s->failed_pc=0x0c053ddeu; return 0; }
r[0]=r[4];
goto P_0c053de0;
P_0c053de0: /* original 0009, guest PC 0x0c053de0 */
if(!s->budget--) { s->failed_pc=0x0c053de0u; return 0; }
goto P_0c053de2;
P_0c053de2: /* original 6d63, guest PC 0x0c053de2 */
if(!s->budget--) { s->failed_pc=0x0c053de2u; return 0; }
r[13]=r[6];
goto P_0c053de4;
P_0c053de4: /* original 81f4, guest PC 0x0c053de4 */
if(!s->budget--) { s->failed_pc=0x0c053de4u; return 0; }
write(ram,r[15]+8,r[0],2);
goto P_0c053de6;
P_0c053de6: /* original 6ef3, guest PC 0x0c053de6 */
if(!s->budget--) { s->failed_pc=0x0c053de6u; return 0; }
r[14]=r[15];
goto P_0c053de8;
P_0c053de8: /* original 1f51, guest PC 0x0c053de8 */
if(!s->budget--) { s->failed_pc=0x0c053de8u; return 0; }
write(ram,r[15]+4,r[5],4);
goto P_0c053dea;
P_0c053dea: /* original e008, guest PC 0x0c053dea */
if(!s->budget--) { s->failed_pc=0x0c053deau; return 0; }
r[0]=0x00000008u;
goto P_0c053dec;
P_0c053dec: /* original 1f73, guest PC 0x0c053dec */
if(!s->budget--) { s->failed_pc=0x0c053decu; return 0; }
write(ram,r[15]+12,r[7],4);
goto P_0c053dee;
P_0c053dee: /* original 4d15, guest PC 0x0c053dee */
if(!s->budget--) { s->failed_pc=0x0c053deeu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[13]>0)!=0);
goto P_0c053df0;
P_0c053df0: /* original 81f8, guest PC 0x0c053df0 */
if(!s->budget--) { s->failed_pc=0x0c053df0u; return 0; }
write(ram,r[15]+16,r[0],2);
goto P_0c053df2;
P_0c053df2: /* original 8f0e, guest PC 0x0c053df2 */
if(!s->budget--) { s->failed_pc=0x0c053df2u; return 0; }
cond=r[17]&1u;
r[14]+=0x00000014u;
if(!cond) { goto P_0c053e12; }
goto P_0c053df6;
P_0c053df4: /* original 7e14, guest PC 0x0c053df4 */
if(!s->budget--) { s->failed_pc=0x0c053df4u; return 0; }
r[14]+=0x00000014u;
goto P_0c053df6;
P_0c053df6: /* original 66e3, guest PC 0x0c053df6 */
if(!s->budget--) { s->failed_pc=0x0c053df6u; return 0; }
r[6]=r[14];
goto P_0c053df8;
P_0c053df8: /* original d22e, guest PC 0x0c053df8 */
if(!s->budget--) { s->failed_pc=0x0c053df8u; return 0; }
r[2]=read(ram,0x0c053eb4u,4);
goto P_0c053dfa;
P_0c053dfa: /* original 65f3, guest PC 0x0c053dfa */
if(!s->budget--) { s->failed_pc=0x0c053dfau; return 0; }
r[5]=r[15];
goto P_0c053dfc;
P_0c053dfc: /* original 420b, guest PC 0x0c053dfc */
if(!s->budget--) { s->failed_pc=0x0c053dfcu; return 0; }
target=r[2];
r[16]=code_base|0x0c053e00u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c053e00u) { target=s->pc; goto dispatch; }
goto P_0c053e00;
P_0c053dfe: /* original 64d3, guest PC 0x0c053dfe */
if(!s->budget--) { s->failed_pc=0x0c053dfeu; return 0; }
r[4]=r[13];
goto P_0c053e00;
P_0c053e00: /* original 57f1, guest PC 0x0c053e00 */
if(!s->budget--) { s->failed_pc=0x0c053e00u; return 0; }
r[7]=read(ram,r[15]+4,4);
goto P_0c053e02;
P_0c053e02: /* original 65e3, guest PC 0x0c053e02 */
if(!s->budget--) { s->failed_pc=0x0c053e02u; return 0; }
r[5]=r[14];
goto P_0c053e04;
P_0c053e04: /* original d32c, guest PC 0x0c053e04 */
if(!s->budget--) { s->failed_pc=0x0c053e04u; return 0; }
r[3]=read(ram,0x0c053eb8u,4);
goto P_0c053e06;
P_0c053e06: /* original 85f4, guest PC 0x0c053e06 */
if(!s->budget--) { s->failed_pc=0x0c053e06u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[15]+8,2);
goto P_0c053e08;
P_0c053e08: /* original 6603, guest PC 0x0c053e08 */
if(!s->budget--) { s->failed_pc=0x0c053e08u; return 0; }
r[6]=r[0];
goto P_0c053e0a;
P_0c053e0a: /* original 430b, guest PC 0x0c053e0a */
if(!s->budget--) { s->failed_pc=0x0c053e0au; return 0; }
target=r[3];
r[16]=code_base|0x0c053e0eu;
r[4]=r[15];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c053e0eu) { target=s->pc; goto dispatch; }
goto P_0c053e0e;
P_0c053e0c: /* original 64f3, guest PC 0x0c053e0c */
if(!s->budget--) { s->failed_pc=0x0c053e0cu; return 0; }
r[4]=r[15];
goto P_0c053e0e;
P_0c053e0e: /* original a00c, guest PC 0x0c053e0e */
if(!s->budget--) { s->failed_pc=0x0c053e0eu; return 0; }
goto P_0c053e2a;
P_0c053e10: /* original 0009, guest PC 0x0c053e10 */
if(!s->budget--) { s->failed_pc=0x0c053e10u; return 0; }
goto P_0c053e12;
P_0c053e12: /* original 66e3, guest PC 0x0c053e12 */
if(!s->budget--) { s->failed_pc=0x0c053e12u; return 0; }
r[6]=r[14];
goto P_0c053e14;
P_0c053e14: /* original d327, guest PC 0x0c053e14 */
if(!s->budget--) { s->failed_pc=0x0c053e14u; return 0; }
r[3]=read(ram,0x0c053eb4u,4);
goto P_0c053e16;
P_0c053e16: /* original 65f3, guest PC 0x0c053e16 */
if(!s->budget--) { s->failed_pc=0x0c053e16u; return 0; }
r[5]=r[15];
goto P_0c053e18;
P_0c053e18: /* original 430b, guest PC 0x0c053e18 */
if(!s->budget--) { s->failed_pc=0x0c053e18u; return 0; }
target=r[3];
r[16]=code_base|0x0c053e1cu;
r[4]=0u-r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c053e1cu) { target=s->pc; goto dispatch; }
goto P_0c053e1c;
P_0c053e1a: /* original 64db, guest PC 0x0c053e1a */
if(!s->budget--) { s->failed_pc=0x0c053e1au; return 0; }
r[4]=0u-r[13];
goto P_0c053e1c;
P_0c053e1c: /* original 57f1, guest PC 0x0c053e1c */
if(!s->budget--) { s->failed_pc=0x0c053e1cu; return 0; }
r[7]=read(ram,r[15]+4,4);
goto P_0c053e1e;
P_0c053e1e: /* original 65e3, guest PC 0x0c053e1e */
if(!s->budget--) { s->failed_pc=0x0c053e1eu; return 0; }
r[5]=r[14];
goto P_0c053e20;
P_0c053e20: /* original d326, guest PC 0x0c053e20 */
if(!s->budget--) { s->failed_pc=0x0c053e20u; return 0; }
r[3]=read(ram,0x0c053ebcu,4);
goto P_0c053e22;
P_0c053e22: /* original 85f4, guest PC 0x0c053e22 */
if(!s->budget--) { s->failed_pc=0x0c053e22u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[15]+8,2);
goto P_0c053e24;
P_0c053e24: /* original 6603, guest PC 0x0c053e24 */
if(!s->budget--) { s->failed_pc=0x0c053e24u; return 0; }
r[6]=r[0];
goto P_0c053e26;
P_0c053e26: /* original 430b, guest PC 0x0c053e26 */
if(!s->budget--) { s->failed_pc=0x0c053e26u; return 0; }
target=r[3];
r[16]=code_base|0x0c053e2au;
r[4]=r[15];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c053e2au) { target=s->pc; goto dispatch; }
goto P_0c053e2a;
P_0c053e28: /* original 64f3, guest PC 0x0c053e28 */
if(!s->budget--) { s->failed_pc=0x0c053e28u; return 0; }
r[4]=r[15];
goto P_0c053e2a;
P_0c053e2a: /* original ed3f, guest PC 0x0c053e2a */
if(!s->budget--) { s->failed_pc=0x0c053e2au; return 0; }
r[13]=0x0000003fu;
goto P_0c053e2c;
P_0c053e2c: /* original d224, guest PC 0x0c053e2c */
if(!s->budget--) { s->failed_pc=0x0c053e2cu; return 0; }
r[2]=read(ram,0x0c053ec0u,4);
goto P_0c053e2e;
P_0c053e2e: /* original 63f1, guest PC 0x0c053e2e */
if(!s->budget--) { s->failed_pc=0x0c053e2eu; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[15],2);
r[3]=tmp;
goto P_0c053e30;
P_0c053e30: /* original 3d38, guest PC 0x0c053e30 */
if(!s->budget--) { s->failed_pc=0x0c053e30u; return 0; }
r[13]-=r[3];
goto P_0c053e32;
P_0c053e32: /* original 61d3, guest PC 0x0c053e32 */
if(!s->budget--) { s->failed_pc=0x0c053e32u; return 0; }
r[1]=r[13];
goto P_0c053e34;
P_0c053e34: /* original 420b, guest PC 0x0c053e34 */
if(!s->budget--) { s->failed_pc=0x0c053e34u; return 0; }
target=r[2];
r[16]=code_base|0x0c053e38u;
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[15]+16,2);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c053e38u) { target=s->pc; goto dispatch; }
goto P_0c053e38;
P_0c053e36: /* original 85f8, guest PC 0x0c053e36 */
if(!s->budget--) { s->failed_pc=0x0c053e36u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[15]+16,2);
goto P_0c053e38;
P_0c053e38: /* original d122, guest PC 0x0c053e38 */
if(!s->budget--) { s->failed_pc=0x0c053e38u; return 0; }
r[1]=read(ram,0x0c053ec4u,4);
goto P_0c053e3a;
P_0c053e3a: /* original 6c03, guest PC 0x0c053e3a */
if(!s->budget--) { s->failed_pc=0x0c053e3au; return 0; }
r[12]=r[0];
goto P_0c053e3c;
P_0c053e3c: /* original 62df, guest PC 0x0c053e3c */
if(!s->budget--) { s->failed_pc=0x0c053e3cu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)r[13];
goto P_0c053e3e;
P_0c053e3e: /* original e642, guest PC 0x0c053e3e */
if(!s->budget--) { s->failed_pc=0x0c053e3eu; return 0; }
r[6]=0x00000042u;
goto P_0c053e40;
P_0c053e40: /* original 3628, guest PC 0x0c053e40 */
if(!s->budget--) { s->failed_pc=0x0c053e40u; return 0; }
r[6]-=r[2];
goto P_0c053e42;
P_0c053e42: /* original e509, guest PC 0x0c053e42 */
if(!s->budget--) { s->failed_pc=0x0c053e42u; return 0; }
r[5]=0x00000009u;
goto P_0c053e44;
P_0c053e44: /* original 410b, guest PC 0x0c053e44 */
if(!s->budget--) { s->failed_pc=0x0c053e44u; return 0; }
target=r[1];
r[16]=code_base|0x0c053e48u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c053e48u) { target=s->pc; goto dispatch; }
goto P_0c053e48;
P_0c053e46: /* original 64e3, guest PC 0x0c053e46 */
if(!s->budget--) { s->failed_pc=0x0c053e46u; return 0; }
r[4]=r[14];
goto P_0c053e48;
P_0c053e48: /* original e008, guest PC 0x0c053e48 */
if(!s->budget--) { s->failed_pc=0x0c053e48u; return 0; }
r[0]=0x00000008u;
goto P_0c053e4a;
P_0c053e4a: /* original 65cf, guest PC 0x0c053e4a */
if(!s->budget--) { s->failed_pc=0x0c053e4au; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)r[12];
goto P_0c053e4c;
P_0c053e4c: /* original 6303, guest PC 0x0c053e4c */
if(!s->budget--) { s->failed_pc=0x0c053e4cu; return 0; }
r[3]=r[0];
goto P_0c053e4e;
P_0c053e4e: /* original 3353, guest PC 0x0c053e4e */
if(!s->budget--) { s->failed_pc=0x0c053e4eu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>=(int32_t)r[5])!=0);
goto P_0c053e50;
P_0c053e50: /* original 8f0b, guest PC 0x0c053e50 */
if(!s->budget--) { s->failed_pc=0x0c053e50u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c053e6a; }
goto P_0c053e54;
P_0c053e52: /* original 0009, guest PC 0x0c053e52 */
if(!s->budget--) { s->failed_pc=0x0c053e52u; return 0; }
goto P_0c053e54;
P_0c053e54: /* original 600f, guest PC 0x0c053e54 */
if(!s->budget--) { s->failed_pc=0x0c053e54u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)r[0];
goto P_0c053e56;
P_0c053e56: /* original 630f, guest PC 0x0c053e56 */
if(!s->budget--) { s->failed_pc=0x0c053e56u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)r[0];
goto P_0c053e58;
P_0c053e58: /* original 3358, guest PC 0x0c053e58 */
if(!s->budget--) { s->failed_pc=0x0c053e58u; return 0; }
r[3]-=r[5];
goto P_0c053e5a;
P_0c053e5a: /* original 33ec, guest PC 0x0c053e5a */
if(!s->budget--) { s->failed_pc=0x0c053e5au; return 0; }
r[3]+=r[14];
goto P_0c053e5c;
P_0c053e5c: /* original 6330, guest PC 0x0c053e5c */
if(!s->budget--) { s->failed_pc=0x0c053e5cu; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[3],1);
r[3]=tmp;
goto P_0c053e5e;
P_0c053e5e: /* original 0e34, guest PC 0x0c053e5e */
if(!s->budget--) { s->failed_pc=0x0c053e5eu; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c053e60;
P_0c053e60: /* original 70ff, guest PC 0x0c053e60 */
if(!s->budget--) { s->failed_pc=0x0c053e60u; return 0; }
r[0]+=0xffffffffu;
goto P_0c053e62;
P_0c053e62: /* original 620f, guest PC 0x0c053e62 */
if(!s->budget--) { s->failed_pc=0x0c053e62u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)r[0];
goto P_0c053e64;
P_0c053e64: /* original 3253, guest PC 0x0c053e64 */
if(!s->budget--) { s->failed_pc=0x0c053e64u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[2]>=(int32_t)r[5])!=0);
goto P_0c053e66;
P_0c053e66: /* original 8df5, guest PC 0x0c053e66 */
if(!s->budget--) { s->failed_pc=0x0c053e66u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c053e54; }
goto P_0c053e6a;
P_0c053e68: /* original 0009, guest PC 0x0c053e68 */
if(!s->budget--) { s->failed_pc=0x0c053e68u; return 0; }
goto P_0c053e6a;
P_0c053e6a: /* original 660f, guest PC 0x0c053e6a */
if(!s->budget--) { s->failed_pc=0x0c053e6au; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)r[0];
goto P_0c053e6c;
P_0c053e6c: /* original 36ec, guest PC 0x0c053e6c */
if(!s->budget--) { s->failed_pc=0x0c053e6cu; return 0; }
r[6]+=r[14];
goto P_0c053e6e;
P_0c053e6e: /* original 7601, guest PC 0x0c053e6e */
if(!s->budget--) { s->failed_pc=0x0c053e6eu; return 0; }
r[6]+=0x00000001u;
goto P_0c053e70;
P_0c053e70: /* original 630f, guest PC 0x0c053e70 */
if(!s->budget--) { s->failed_pc=0x0c053e70u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)r[0];
goto P_0c053e72;
P_0c053e72: /* original 4311, guest PC 0x0c053e72 */
if(!s->budget--) { s->failed_pc=0x0c053e72u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>=0)!=0);
goto P_0c053e74;
P_0c053e74: /* original 8f05, guest PC 0x0c053e74 */
if(!s->budget--) { s->failed_pc=0x0c053e74u; return 0; }
cond=r[17]&1u;
r[5]=0x00000000u;
if(!cond) { goto P_0c053e82; }
goto P_0c053e78;
P_0c053e76: /* original e500, guest PC 0x0c053e76 */
if(!s->budget--) { s->failed_pc=0x0c053e76u; return 0; }
r[5]=0x00000000u;
goto P_0c053e78;
P_0c053e78: /* original 70ff, guest PC 0x0c053e78 */
if(!s->budget--) { s->failed_pc=0x0c053e78u; return 0; }
r[0]+=0xffffffffu;
goto P_0c053e7a;
P_0c053e7a: /* original 630f, guest PC 0x0c053e7a */
if(!s->budget--) { s->failed_pc=0x0c053e7au; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)r[0];
goto P_0c053e7c;
P_0c053e7c: /* original 4311, guest PC 0x0c053e7c */
if(!s->budget--) { s->failed_pc=0x0c053e7cu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>=0)!=0);
goto P_0c053e7e;
P_0c053e7e: /* original 8dfb, guest PC 0x0c053e7e */
if(!s->budget--) { s->failed_pc=0x0c053e7eu; return 0; }
cond=r[17]&1u;
tmp=r[5]; r[6]-=1; write(ram,r[6],tmp,1);
if(cond) { goto P_0c053e78; }
goto P_0c053e82;
P_0c053e80: /* original 2654, guest PC 0x0c053e80 */
if(!s->budget--) { s->failed_pc=0x0c053e80u; return 0; }
tmp=r[5]; r[6]-=1; write(ram,r[6],tmp,1);
goto P_0c053e82;
P_0c053e82: /* original 4c08, guest PC 0x0c053e82 */
if(!s->budget--) { s->failed_pc=0x0c053e82u; return 0; }
r[12]<<=2;
goto P_0c053e84;
P_0c053e84: /* original d310, guest PC 0x0c053e84 */
if(!s->budget--) { s->failed_pc=0x0c053e84u; return 0; }
r[3]=read(ram,0x0c053ec8u,4);
goto P_0c053e86;
P_0c053e86: /* original 66d3, guest PC 0x0c053e86 */
if(!s->budget--) { s->failed_pc=0x0c053e86u; return 0; }
r[6]=r[13];
goto P_0c053e88;
P_0c053e88: /* original 4c00, guest PC 0x0c053e88 */
if(!s->budget--) { s->failed_pc=0x0c053e88u; return 0; }
r[17]=(r[17]&~1u)|((r[12]>>31)!=0);
r[12]<<=1;
goto P_0c053e8a;
P_0c053e8a: /* original 36c8, guest PC 0x0c053e8a */
if(!s->budget--) { s->failed_pc=0x0c053e8au; return 0; }
r[6]-=r[12];
goto P_0c053e8c;
P_0c053e8c: /* original e509, guest PC 0x0c053e8c */
if(!s->budget--) { s->failed_pc=0x0c053e8cu; return 0; }
r[5]=0x00000009u;
goto P_0c053e8e;
P_0c053e8e: /* original 430b, guest PC 0x0c053e8e */
if(!s->budget--) { s->failed_pc=0x0c053e8eu; return 0; }
target=r[3];
r[16]=code_base|0x0c053e92u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c053e92u) { target=s->pc; goto dispatch; }
goto P_0c053e92;
P_0c053e90: /* original 64e3, guest PC 0x0c053e90 */
if(!s->budget--) { s->failed_pc=0x0c053e90u; return 0; }
r[4]=r[14];
goto P_0c053e92;
P_0c053e92: /* original e23f, guest PC 0x0c053e92 */
if(!s->budget--) { s->failed_pc=0x0c053e92u; return 0; }
r[2]=0x0000003fu;
goto P_0c053e94;
P_0c053e94: /* original d30d, guest PC 0x0c053e94 */
if(!s->budget--) { s->failed_pc=0x0c053e94u; return 0; }
r[3]=read(ram,0x0c053eccu,4);
goto P_0c053e96;
P_0c053e96: /* original e540, guest PC 0x0c053e96 */
if(!s->budget--) { s->failed_pc=0x0c053e96u; return 0; }
r[5]=0x00000040u;
goto P_0c053e98;
P_0c053e98: /* original 2f21, guest PC 0x0c053e98 */
if(!s->budget--) { s->failed_pc=0x0c053e98u; return 0; }
write(ram,r[15],r[2],2);
goto P_0c053e9a;
P_0c053e9a: /* original 430b, guest PC 0x0c053e9a */
if(!s->budget--) { s->failed_pc=0x0c053e9au; return 0; }
target=r[3];
r[16]=code_base|0x0c053e9eu;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c053e9eu) { target=s->pc; goto dispatch; }
goto P_0c053e9e;
P_0c053e9c: /* original 64e3, guest PC 0x0c053e9c */
if(!s->budget--) { s->failed_pc=0x0c053e9cu; return 0; }
r[4]=r[14];
goto P_0c053e9e;
P_0c053e9e: /* original e608, guest PC 0x0c053e9e */
if(!s->budget--) { s->failed_pc=0x0c053e9eu; return 0; }
r[6]=0x00000008u;
goto P_0c053ea0;
P_0c053ea0: /* original d30b, guest PC 0x0c053ea0 */
if(!s->budget--) { s->failed_pc=0x0c053ea0u; return 0; }
r[3]=read(ram,0x0c053ed0u,4);
goto P_0c053ea2;
P_0c053ea2: /* original 65e3, guest PC 0x0c053ea2 */
if(!s->budget--) { s->failed_pc=0x0c053ea2u; return 0; }
r[5]=r[14];
goto P_0c053ea4;
P_0c053ea4: /* original 430b, guest PC 0x0c053ea4 */
if(!s->budget--) { s->failed_pc=0x0c053ea4u; return 0; }
target=r[3];
r[16]=code_base|0x0c053ea8u;
r[4]=read(ram,r[15]+12,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c053ea8u) { target=s->pc; goto dispatch; }
goto P_0c053ea8;
P_0c053ea6: /* original 54f3, guest PC 0x0c053ea6 */
if(!s->budget--) { s->failed_pc=0x0c053ea6u; return 0; }
r[4]=read(ram,r[15]+12,4);
goto P_0c053ea8;
P_0c053ea8: /* original 7f20, guest PC 0x0c053ea8 */
if(!s->budget--) { s->failed_pc=0x0c053ea8u; return 0; }
r[15]+=0x00000020u;
goto P_0c053eaa;
P_0c053eaa: /* original 4f26, guest PC 0x0c053eaa */
if(!s->budget--) { s->failed_pc=0x0c053eaau; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c053eac;
P_0c053eac: /* original 6cf6, guest PC 0x0c053eac */
if(!s->budget--) { s->failed_pc=0x0c053eacu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c053eae;
P_0c053eae: /* original 6df6, guest PC 0x0c053eae */
if(!s->budget--) { s->failed_pc=0x0c053eaeu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c053eb0;
P_0c053eb0: /* original 000b, guest PC 0x0c053eb0 */
if(!s->budget--) { s->failed_pc=0x0c053eb0u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c053eb2: /* original 6ef6, guest PC 0x0c053eb2 */
if(!s->budget--) { s->failed_pc=0x0c053eb2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c053eb4u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c053eb4u; return 0; } return 1;
P_0c053ed4: /* original 4f22, guest PC 0x0c053ed4 */
if(!s->budget--) { s->failed_pc=0x0c053ed4u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c053ed6;
P_0c053ed6: /* original 7fec, guest PC 0x0c053ed6 */
if(!s->budget--) { s->failed_pc=0x0c053ed6u; return 0; }
r[15]+=0xffffffecu;
goto P_0c053ed8;
P_0c053ed8: /* original 7ff8, guest PC 0x0c053ed8 */
if(!s->budget--) { s->failed_pc=0x0c053ed8u; return 0; }
r[15]+=0xfffffff8u;
goto P_0c053eda;
P_0c053eda: /* original 53f9, guest PC 0x0c053eda */
if(!s->budget--) { s->failed_pc=0x0c053edau; return 0; }
r[3]=read(ram,r[15]+36,4);
goto P_0c053edc;
P_0c053edc: /* original 2f36, guest PC 0x0c053edc */
if(!s->budget--) { s->failed_pc=0x0c053edcu; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c053ede;
P_0c053ede: /* original 53f9, guest PC 0x0c053ede */
if(!s->budget--) { s->failed_pc=0x0c053edeu; return 0; }
r[3]=read(ram,r[15]+36,4);
goto P_0c053ee0;
P_0c053ee0: /* original 2f36, guest PC 0x0c053ee0 */
if(!s->budget--) { s->failed_pc=0x0c053ee0u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c053ee2;
P_0c053ee2: /* original 64f3, guest PC 0x0c053ee2 */
if(!s->budget--) { s->failed_pc=0x0c053ee2u; return 0; }
r[4]=r[15];
goto P_0c053ee4;
P_0c053ee4: /* original 7410, guest PC 0x0c053ee4 */
if(!s->budget--) { s->failed_pc=0x0c053ee4u; return 0; }
r[4]+=0x00000010u;
goto P_0c053ee6;
P_0c053ee6: /* original e308, guest PC 0x0c053ee6 */
if(!s->budget--) { s->failed_pc=0x0c053ee6u; return 0; }
r[3]=0x00000008u;
goto P_0c053ee8;
P_0c053ee8: /* original 33fc, guest PC 0x0c053ee8 */
if(!s->budget--) { s->failed_pc=0x0c053ee8u; return 0; }
r[3]+=r[15];
goto P_0c053eea;
P_0c053eea: /* original b024, guest PC 0x0c053eea */
if(!s->budget--) { s->failed_pc=0x0c053eeau; return 0; }
target=code_base|0x0c053f36u; r[16]=code_base|0x0c053eeeu;
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c053eeeu) { target=s->pc; goto dispatch; }
goto P_0c053eee;
P_0c053eec: /* original 2f36, guest PC 0x0c053eec */
if(!s->budget--) { s->failed_pc=0x0c053eecu; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c053eee;
P_0c053eee: /* original 7f14, guest PC 0x0c053eee */
if(!s->budget--) { s->failed_pc=0x0c053eeeu; return 0; }
r[15]+=0x00000014u;
goto P_0c053ef0;
P_0c053ef0: /* original d34c, guest PC 0x0c053ef0 */
if(!s->budget--) { s->failed_pc=0x0c053ef0u; return 0; }
r[3]=read(ram,0x0c054024u,4);
goto P_0c053ef2;
P_0c053ef2: /* original 60f2, guest PC 0x0c053ef2 */
if(!s->budget--) { s->failed_pc=0x0c053ef2u; return 0; }
tmp=read(ram,r[15],4);
r[0]=tmp;
goto P_0c053ef4;
P_0c053ef4: /* original 7ff8, guest PC 0x0c053ef4 */
if(!s->budget--) { s->failed_pc=0x0c053ef4u; return 0; }
r[15]+=0xfffffff8u;
goto P_0c053ef6;
P_0c053ef6: /* original 430b, guest PC 0x0c053ef6 */
if(!s->budget--) { s->failed_pc=0x0c053ef6u; return 0; }
target=r[3];
r[16]=code_base|0x0c053efau;
tmp=r[15]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c053efau) { target=s->pc; goto dispatch; }
goto P_0c053efa;
P_0c053ef8: /* original 2ff6, guest PC 0x0c053ef8 */
if(!s->budget--) { s->failed_pc=0x0c053ef8u; return 0; }
tmp=r[15]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c053efa;
P_0c053efa: /* original d24b, guest PC 0x0c053efa */
if(!s->budget--) { s->failed_pc=0x0c053efau; return 0; }
r[2]=read(ram,0x0c054028u,4);
goto P_0c053efc;
P_0c053efc: /* original d34c, guest PC 0x0c053efc */
if(!s->budget--) { s->failed_pc=0x0c053efcu; return 0; }
r[3]=read(ram,0x0c054030u,4);
goto P_0c053efe;
P_0c053efe: /* original 2f26, guest PC 0x0c053efe */
if(!s->budget--) { s->failed_pc=0x0c053efeu; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c053f00;
P_0c053f00: /* original d24a, guest PC 0x0c053f00 */
if(!s->budget--) { s->failed_pc=0x0c053f00u; return 0; }
r[2]=read(ram,0x0c05402cu,4);
goto P_0c053f02;
P_0c053f02: /* original 2f26, guest PC 0x0c053f02 */
if(!s->budget--) { s->failed_pc=0x0c053f02u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c053f04;
P_0c053f04: /* original 61f3, guest PC 0x0c053f04 */
if(!s->budget--) { s->failed_pc=0x0c053f04u; return 0; }
r[1]=r[15];
goto P_0c053f06;
P_0c053f06: /* original 7114, guest PC 0x0c053f06 */
if(!s->budget--) { s->failed_pc=0x0c053f06u; return 0; }
r[1]+=0x00000014u;
goto P_0c053f08;
P_0c053f08: /* original 430b, guest PC 0x0c053f08 */
if(!s->budget--) { s->failed_pc=0x0c053f08u; return 0; }
target=r[3];
r[16]=code_base|0x0c053f0cu;
tmp=r[1]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c053f0cu) { target=s->pc; goto dispatch; }
goto P_0c053f0c;
P_0c053f0a: /* original 2f16, guest PC 0x0c053f0a */
if(!s->budget--) { s->failed_pc=0x0c053f0au; return 0; }
tmp=r[1]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c053f0c;
P_0c053f0c: /* original 7ff8, guest PC 0x0c053f0c */
if(!s->budget--) { s->failed_pc=0x0c053f0cu; return 0; }
r[15]+=0xfffffff8u;
goto P_0c053f0e;
P_0c053f0e: /* original e308, guest PC 0x0c053f0e */
if(!s->budget--) { s->failed_pc=0x0c053f0eu; return 0; }
r[3]=0x00000008u;
goto P_0c053f10;
P_0c053f10: /* original 52f4, guest PC 0x0c053f10 */
if(!s->budget--) { s->failed_pc=0x0c053f10u; return 0; }
r[2]=read(ram,r[15]+16,4);
goto P_0c053f12;
P_0c053f12: /* original 2f26, guest PC 0x0c053f12 */
if(!s->budget--) { s->failed_pc=0x0c053f12u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c053f14;
P_0c053f14: /* original 52f4, guest PC 0x0c053f14 */
if(!s->budget--) { s->failed_pc=0x0c053f14u; return 0; }
r[2]=read(ram,r[15]+16,4);
goto P_0c053f16;
P_0c053f16: /* original 2f26, guest PC 0x0c053f16 */
if(!s->budget--) { s->failed_pc=0x0c053f16u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c053f18;
P_0c053f18: /* original 64f3, guest PC 0x0c053f18 */
if(!s->budget--) { s->failed_pc=0x0c053f18u; return 0; }
r[4]=r[15];
goto P_0c053f1a;
P_0c053f1a: /* original 741c, guest PC 0x0c053f1a */
if(!s->budget--) { s->failed_pc=0x0c053f1au; return 0; }
r[4]+=0x0000001cu;
goto P_0c053f1c;
P_0c053f1c: /* original 33fc, guest PC 0x0c053f1c */
if(!s->budget--) { s->failed_pc=0x0c053f1cu; return 0; }
r[3]+=r[15];
goto P_0c053f1e;
P_0c053f1e: /* original b0c3, guest PC 0x0c053f1e */
if(!s->budget--) { s->failed_pc=0x0c053f1eu; return 0; }
target=code_base|0x0c0540a8u; r[16]=code_base|0x0c053f22u;
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c053f22u) { target=s->pc; goto dispatch; }
goto P_0c053f22;
P_0c053f20: /* original 2f36, guest PC 0x0c053f20 */
if(!s->budget--) { s->failed_pc=0x0c053f20u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c053f22;
P_0c053f22: /* original 53f9, guest PC 0x0c053f22 */
if(!s->budget--) { s->failed_pc=0x0c053f22u; return 0; }
r[3]=read(ram,r[15]+36,4);
goto P_0c053f24;
P_0c053f24: /* original d243, guest PC 0x0c053f24 */
if(!s->budget--) { s->failed_pc=0x0c053f24u; return 0; }
r[2]=read(ram,0x0c054034u,4);
goto P_0c053f26;
P_0c053f26: /* original 2f36, guest PC 0x0c053f26 */
if(!s->budget--) { s->failed_pc=0x0c053f26u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c053f28;
P_0c053f28: /* original 53f9, guest PC 0x0c053f28 */
if(!s->budget--) { s->failed_pc=0x0c053f28u; return 0; }
r[3]=read(ram,r[15]+36,4);
goto P_0c053f2a;
P_0c053f2a: /* original 420b, guest PC 0x0c053f2a */
if(!s->budget--) { s->failed_pc=0x0c053f2au; return 0; }
target=r[2];
r[16]=code_base|0x0c053f2eu;
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c053f2eu) { target=s->pc; goto dispatch; }
goto P_0c053f2e;
P_0c053f2c: /* original 2f36, guest PC 0x0c053f2c */
if(!s->budget--) { s->failed_pc=0x0c053f2cu; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c053f2e;
P_0c053f2e: /* original 7f28, guest PC 0x0c053f2e */
if(!s->budget--) { s->failed_pc=0x0c053f2eu; return 0; }
r[15]+=0x00000028u;
goto P_0c053f30;
P_0c053f30: /* original 4f26, guest PC 0x0c053f30 */
if(!s->budget--) { s->failed_pc=0x0c053f30u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c053f32;
P_0c053f32: /* original 000b, guest PC 0x0c053f32 */
if(!s->budget--) { s->failed_pc=0x0c053f32u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c053f34: /* original 0009, guest PC 0x0c053f34 */
if(!s->budget--) { s->failed_pc=0x0c053f34u; return 0; }
return vf3_matrix_family(0x0c053f36u,s,ram);
unsupported: s->failed_pc=target; return 0;
}
