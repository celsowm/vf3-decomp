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
int vf3_away_batch33_adapter_1(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c065dd4u: goto P_0c065dd4;
case 0x0c065dd6u: goto P_0c065dd6;
case 0x0c065dd8u: goto P_0c065dd8;
case 0x0c065ddau: goto P_0c065dda;
case 0x0c065ddcu: goto P_0c065ddc;
case 0x0c065ddeu: goto P_0c065dde;
case 0x0c065de0u: goto P_0c065de0;
case 0x0c065de2u: goto P_0c065de2;
case 0x0c065de4u: goto P_0c065de4;
case 0x0c065de6u: goto P_0c065de6;
case 0x0c065de8u: goto P_0c065de8;
case 0x0c065deau: goto P_0c065dea;
case 0x0c065decu: goto P_0c065dec;
case 0x0c065deeu: goto P_0c065dee;
case 0x0c065df0u: goto P_0c065df0;
case 0x0c065df2u: goto P_0c065df2;
case 0x0c065df4u: goto P_0c065df4;
case 0x0c065df6u: goto P_0c065df6;
case 0x0c065df8u: goto P_0c065df8;
case 0x0c065dfau: goto P_0c065dfa;
case 0x0c065dfcu: goto P_0c065dfc;
case 0x0c065dfeu: goto P_0c065dfe;
case 0x0c065e00u: goto P_0c065e00;
case 0x0c065e02u: goto P_0c065e02;
case 0x0c065e04u: goto P_0c065e04;
case 0x0c065e06u: goto P_0c065e06;
case 0x0c065e08u: goto P_0c065e08;
case 0x0c065e0au: goto P_0c065e0a;
case 0x0c065e0cu: goto P_0c065e0c;
case 0x0c065e0eu: goto P_0c065e0e;
case 0x0c065e10u: goto P_0c065e10;
case 0x0c065e12u: goto P_0c065e12;
case 0x0c065e14u: goto P_0c065e14;
case 0x0c065e16u: goto P_0c065e16;
case 0x0c065e18u: goto P_0c065e18;
case 0x0c065e1au: goto P_0c065e1a;
case 0x0c065e1cu: goto P_0c065e1c;
case 0x0c065e1eu: goto P_0c065e1e;
case 0x0c065e20u: goto P_0c065e20;
case 0x0c065e22u: goto P_0c065e22;
case 0x0c065e24u: goto P_0c065e24;
case 0x0c065e26u: goto P_0c065e26;
case 0x0c065e28u: goto P_0c065e28;
case 0x0c065e2au: goto P_0c065e2a;
case 0x0c065e2cu: goto P_0c065e2c;
case 0x0c065e2eu: goto P_0c065e2e;
case 0x0c065e30u: goto P_0c065e30;
case 0x0c065e32u: goto P_0c065e32;
case 0x0c065e34u: goto P_0c065e34;
case 0x0c065e36u: goto P_0c065e36;
case 0x0c065e38u: goto P_0c065e38;
case 0x0c065e3au: goto P_0c065e3a;
case 0x0c065e3cu: goto P_0c065e3c;
case 0x0c065e3eu: goto P_0c065e3e;
case 0x0c065e40u: goto P_0c065e40;
case 0x0c065e42u: goto P_0c065e42;
case 0x0c065e44u: goto P_0c065e44;
case 0x0c065e46u: goto P_0c065e46;
case 0x0c065e48u: goto P_0c065e48;
case 0x0c065e4au: goto P_0c065e4a;
case 0x0c065e4cu: goto P_0c065e4c;
case 0x0c065e4eu: goto P_0c065e4e;
case 0x0c065e50u: goto P_0c065e50;
case 0x0c065e52u: goto P_0c065e52;
case 0x0c065e54u: goto P_0c065e54;
case 0x0c065e56u: goto P_0c065e56;
case 0x0c065e58u: goto P_0c065e58;
case 0x0c065e5au: goto P_0c065e5a;
case 0x0c065e5cu: goto P_0c065e5c;
case 0x0c065e5eu: goto P_0c065e5e;
case 0x0c065e60u: goto P_0c065e60;
case 0x0c065e62u: goto P_0c065e62;
case 0x0c065e64u: goto P_0c065e64;
case 0x0c065e66u: goto P_0c065e66;
case 0x0c065e68u: goto P_0c065e68;
case 0x0c065e6au: goto P_0c065e6a;
case 0x0c065e6cu: goto P_0c065e6c;
case 0x0c065e6eu: goto P_0c065e6e;
case 0x0c065e70u: goto P_0c065e70;
case 0x0c065e72u: goto P_0c065e72;
case 0x0c065e74u: goto P_0c065e74;
case 0x0c065e76u: goto P_0c065e76;
case 0x0c065e78u: goto P_0c065e78;
case 0x0c065e7au: goto P_0c065e7a;
case 0x0c065e7cu: goto P_0c065e7c;
case 0x0c065e7eu: goto P_0c065e7e;
case 0x0c065e80u: goto P_0c065e80;
case 0x0c065e82u: goto P_0c065e82;
case 0x0c065e84u: goto P_0c065e84;
case 0x0c065e86u: goto P_0c065e86;
case 0x0c065e88u: goto P_0c065e88;
case 0x0c065e8au: goto P_0c065e8a;
case 0x0c065e8cu: goto P_0c065e8c;
case 0x0c065e8eu: goto P_0c065e8e;
case 0x0c065e90u: goto P_0c065e90;
case 0x0c065e92u: goto P_0c065e92;
case 0x0c065e94u: goto P_0c065e94;
case 0x0c065e96u: goto P_0c065e96;
case 0x0c065e98u: goto P_0c065e98;
case 0x0c065e9au: goto P_0c065e9a;
case 0x0c065e9cu: goto P_0c065e9c;
case 0x0c065e9eu: goto P_0c065e9e;
case 0x0c065ea0u: goto P_0c065ea0;
case 0x0c065ea2u: goto P_0c065ea2;
case 0x0c065ea4u: goto P_0c065ea4;
case 0x0c065ea6u: goto P_0c065ea6;
case 0x0c065ea8u: goto P_0c065ea8;
case 0x0c065eaau: goto P_0c065eaa;
case 0x0c065eacu: goto P_0c065eac;
case 0x0c065eaeu: goto P_0c065eae;
case 0x0c065eb0u: goto P_0c065eb0;
case 0x0c065eb2u: goto P_0c065eb2;
case 0x0c065eb4u: goto P_0c065eb4;
case 0x0c065eb6u: goto P_0c065eb6;
case 0x0c065eb8u: goto P_0c065eb8;
case 0x0c065ebau: goto P_0c065eba;
case 0x0c065ebcu: goto P_0c065ebc;
case 0x0c065ebeu: goto P_0c065ebe;
case 0x0c065ec0u: goto P_0c065ec0;
case 0x0c065ec2u: goto P_0c065ec2;
case 0x0c065ec4u: goto P_0c065ec4;
case 0x0c065ec6u: goto P_0c065ec6;
case 0x0c065ec8u: goto P_0c065ec8;
case 0x0c065ecau: goto P_0c065eca;
case 0x0c065eccu: goto P_0c065ecc;
case 0x0c065eceu: goto P_0c065ece;
case 0x0c065ed0u: goto P_0c065ed0;
case 0x0c065ed2u: goto P_0c065ed2;
case 0x0c065ed4u: goto P_0c065ed4;
case 0x0c065ed6u: goto P_0c065ed6;
case 0x0c065ed8u: goto P_0c065ed8;
case 0x0c065edau: goto P_0c065eda;
case 0x0c065edcu: goto P_0c065edc;
case 0x0c065edeu: goto P_0c065ede;
case 0x0c065ee0u: goto P_0c065ee0;
case 0x0c065ee2u: goto P_0c065ee2;
case 0x0c065ee4u: goto P_0c065ee4;
case 0x0c065ee6u: goto P_0c065ee6;
case 0x0c065ee8u: goto P_0c065ee8;
case 0x0c065eeau: goto P_0c065eea;
case 0x0c065eecu: goto P_0c065eec;
case 0x0c065eeeu: goto P_0c065eee;
case 0x0c065ef0u: goto P_0c065ef0;
case 0x0c065ef2u: goto P_0c065ef2;
case 0x0c065ef4u: goto P_0c065ef4;
case 0x0c065ef6u: goto P_0c065ef6;
case 0x0c065ef8u: goto P_0c065ef8;
case 0x0c065efau: goto P_0c065efa;
case 0x0c065efcu: goto P_0c065efc;
case 0x0c065efeu: goto P_0c065efe;
case 0x0c065f00u: goto P_0c065f00;
case 0x0c065f02u: goto P_0c065f02;
case 0x0c065f04u: goto P_0c065f04;
case 0x0c065f06u: goto P_0c065f06;
case 0x0c065f08u: goto P_0c065f08;
case 0x0c065f0au: goto P_0c065f0a;
case 0x0c065f0cu: goto P_0c065f0c;
case 0x0c065f0eu: goto P_0c065f0e;
case 0x0c065f10u: goto P_0c065f10;
case 0x0c065f12u: goto P_0c065f12;
case 0x0c065f14u: goto P_0c065f14;
case 0x0c065f16u: goto P_0c065f16;
case 0x0c065f18u: goto P_0c065f18;
case 0x0c065f1au: goto P_0c065f1a;
case 0x0c065f1cu: goto P_0c065f1c;
case 0x0c065f1eu: goto P_0c065f1e;
case 0x0c065f20u: goto P_0c065f20;
case 0x0c065f22u: goto P_0c065f22;
case 0x0c065f24u: goto P_0c065f24;
case 0x0c065f26u: goto P_0c065f26;
case 0x0c065f28u: goto P_0c065f28;
case 0x0c065f2au: goto P_0c065f2a;
case 0x0c065f2cu: goto P_0c065f2c;
case 0x0c065f2eu: goto P_0c065f2e;
case 0x0c065f30u: goto P_0c065f30;
case 0x0c065f32u: goto P_0c065f32;
case 0x0c065f34u: goto P_0c065f34;
case 0x0c065f36u: goto P_0c065f36;
case 0x0c065f38u: goto P_0c065f38;
case 0x0c065f3au: goto P_0c065f3a;
case 0x0c065f3cu: goto P_0c065f3c;
case 0x0c065f3eu: goto P_0c065f3e;
case 0x0c065f40u: goto P_0c065f40;
case 0x0c065f42u: goto P_0c065f42;
case 0x0c065f44u: goto P_0c065f44;
case 0x0c065f46u: goto P_0c065f46;
case 0x0c065f48u: goto P_0c065f48;
case 0x0c065f4au: goto P_0c065f4a;
case 0x0c065f4cu: goto P_0c065f4c;
case 0x0c065f4eu: goto P_0c065f4e;
case 0x0c065f50u: goto P_0c065f50;
case 0x0c065f52u: goto P_0c065f52;
case 0x0c065f54u: goto P_0c065f54;
case 0x0c065f56u: goto P_0c065f56;
case 0x0c065f58u: goto P_0c065f58;
case 0x0c065f5au: goto P_0c065f5a;
case 0x0c065f5cu: goto P_0c065f5c;
case 0x0c065f5eu: goto P_0c065f5e;
case 0x0c065f60u: goto P_0c065f60;
case 0x0c065f62u: goto P_0c065f62;
case 0x0c065f64u: goto P_0c065f64;
case 0x0c065f66u: goto P_0c065f66;
case 0x0c065f68u: goto P_0c065f68;
case 0x0c065f6au: goto P_0c065f6a;
case 0x0c065f6cu: goto P_0c065f6c;
case 0x0c065f6eu: goto P_0c065f6e;
case 0x0c065f70u: goto P_0c065f70;
case 0x0c065f72u: goto P_0c065f72;
case 0x0c065f74u: goto P_0c065f74;
case 0x0c065f76u: goto P_0c065f76;
case 0x0c065f78u: goto P_0c065f78;
case 0x0c065f7au: goto P_0c065f7a;
case 0x0c065f7cu: goto P_0c065f7c;
case 0x0c065f7eu: goto P_0c065f7e;
case 0x0c065f80u: goto P_0c065f80;
case 0x0c065f82u: goto P_0c065f82;
case 0x0c065f84u: goto P_0c065f84;
case 0x0c065f86u: goto P_0c065f86;
case 0x0c065f88u: goto P_0c065f88;
case 0x0c065f8au: goto P_0c065f8a;
case 0x0c065f8cu: goto P_0c065f8c;
case 0x0c065f8eu: goto P_0c065f8e;
case 0x0c065f90u: goto P_0c065f90;
case 0x0c065f92u: goto P_0c065f92;
case 0x0c065f94u: goto P_0c065f94;
case 0x0c065f96u: goto P_0c065f96;
case 0x0c065f98u: goto P_0c065f98;
case 0x0c065f9au: goto P_0c065f9a;
case 0x0c065f9cu: goto P_0c065f9c;
case 0x0c065f9eu: goto P_0c065f9e;
case 0x0c065fa0u: goto P_0c065fa0;
case 0x0c065fa2u: goto P_0c065fa2;
case 0x0c065fa4u: goto P_0c065fa4;
case 0x0c065fa6u: goto P_0c065fa6;
case 0x0c065fa8u: goto P_0c065fa8;
case 0x0c065faau: goto P_0c065faa;
case 0x0c065facu: goto P_0c065fac;
case 0x0c065faeu: goto P_0c065fae;
case 0x0c065fb0u: goto P_0c065fb0;
case 0x0c065fb2u: goto P_0c065fb2;
case 0x0c065fb4u: goto P_0c065fb4;
case 0x0c065fb6u: goto P_0c065fb6;
case 0x0c065fb8u: goto P_0c065fb8;
case 0x0c065fbau: goto P_0c065fba;
case 0x0c065fbcu: goto P_0c065fbc;
case 0x0c065fbeu: goto P_0c065fbe;
case 0x0c065fc0u: goto P_0c065fc0;
case 0x0c065fc2u: goto P_0c065fc2;
case 0x0c065fc4u: goto P_0c065fc4;
case 0x0c065fc6u: goto P_0c065fc6;
case 0x0c065fc8u: goto P_0c065fc8;
case 0x0c065fcau: goto P_0c065fca;
case 0x0c065fccu: goto P_0c065fcc;
case 0x0c065fceu: goto P_0c065fce;
case 0x0c065fd0u: goto P_0c065fd0;
case 0x0c065fd2u: goto P_0c065fd2;
case 0x0c065fd4u: goto P_0c065fd4;
case 0x0c065fd6u: goto P_0c065fd6;
case 0x0c065fd8u: goto P_0c065fd8;
case 0x0c065fdau: goto P_0c065fda;
case 0x0c065fdcu: goto P_0c065fdc;
case 0x0c065fdeu: goto P_0c065fde;
case 0x0c065fe0u: goto P_0c065fe0;
case 0x0c065fe2u: goto P_0c065fe2;
case 0x0c065fe4u: goto P_0c065fe4;
case 0x0c065fe6u: goto P_0c065fe6;
case 0x0c065fe8u: goto P_0c065fe8;
case 0x0c065feau: goto P_0c065fea;
case 0x0c065fecu: goto P_0c065fec;
case 0x0c065feeu: goto P_0c065fee;
case 0x0c065ff0u: goto P_0c065ff0;
case 0x0c065ff2u: goto P_0c065ff2;
case 0x0c065ff4u: goto P_0c065ff4;
case 0x0c065ff6u: goto P_0c065ff6;
case 0x0c065ff8u: goto P_0c065ff8;
case 0x0c065ffau: goto P_0c065ffa;
case 0x0c065ffcu: goto P_0c065ffc;
case 0x0c065ffeu: goto P_0c065ffe;
case 0x0c066000u: goto P_0c066000;
case 0x0c066002u: goto P_0c066002;
case 0x0c066004u: goto P_0c066004;
case 0x0c066006u: goto P_0c066006;
case 0x0c066008u: goto P_0c066008;
case 0x0c06600au: goto P_0c06600a;
case 0x0c06600cu: goto P_0c06600c;
default: return vf3_matrix_family(target,s,ram);
}
P_0c065dd4: /* original 2fe6, guest PC 0x0c065dd4 */
if(!s->budget--) { s->failed_pc=0x0c065dd4u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c065dd6;
P_0c065dd6: /* original 2fd6, guest PC 0x0c065dd6 */
if(!s->budget--) { s->failed_pc=0x0c065dd6u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c065dd8;
P_0c065dd8: /* original 2fc6, guest PC 0x0c065dd8 */
if(!s->budget--) { s->failed_pc=0x0c065dd8u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c065dda;
P_0c065dda: /* original ec00, guest PC 0x0c065dda */
if(!s->budget--) { s->failed_pc=0x0c065ddau; return 0; }
r[12]=0x00000000u;
goto P_0c065ddc;
P_0c065ddc: /* original 2fb6, guest PC 0x0c065ddc */
if(!s->budget--) { s->failed_pc=0x0c065ddcu; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c065dde;
P_0c065dde: /* original 2fa6, guest PC 0x0c065dde */
if(!s->budget--) { s->failed_pc=0x0c065ddeu; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c065de0;
P_0c065de0: /* original 2f96, guest PC 0x0c065de0 */
if(!s->budget--) { s->failed_pc=0x0c065de0u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c065de2;
P_0c065de2: /* original fffb, guest PC 0x0c065de2 */
if(!s->budget--) { s->failed_pc=0x0c065de2u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c065de4;
P_0c065de4: /* original 4f22, guest PC 0x0c065de4 */
if(!s->budget--) { s->failed_pc=0x0c065de4u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c065de6;
P_0c065de6: /* original 7ff0, guest PC 0x0c065de6 */
if(!s->budget--) { s->failed_pc=0x0c065de6u; return 0; }
r[15]+=0xfffffff0u;
goto P_0c065de8;
P_0c065de8: /* original 6342, guest PC 0x0c065de8 */
if(!s->budget--) { s->failed_pc=0x0c065de8u; return 0; }
tmp=read(ram,r[4],4);
r[3]=tmp;
goto P_0c065dea;
P_0c065dea: /* original 65f3, guest PC 0x0c065dea */
if(!s->budget--) { s->failed_pc=0x0c065deau; return 0; }
r[5]=r[15];
goto P_0c065dec;
P_0c065dec: /* original 7504, guest PC 0x0c065dec */
if(!s->budget--) { s->failed_pc=0x0c065decu; return 0; }
r[5]+=0x00000004u;
goto P_0c065dee;
P_0c065dee: /* original 6d53, guest PC 0x0c065dee */
if(!s->budget--) { s->failed_pc=0x0c065deeu; return 0; }
r[13]=r[5];
goto P_0c065df0;
P_0c065df0: /* original 2d32, guest PC 0x0c065df0 */
if(!s->budget--) { s->failed_pc=0x0c065df0u; return 0; }
write(ram,r[13],r[3],4);
goto P_0c065df2;
P_0c065df2: /* original 6bd3, guest PC 0x0c065df2 */
if(!s->budget--) { s->failed_pc=0x0c065df2u; return 0; }
r[11]=r[13];
goto P_0c065df4;
P_0c065df4: /* original 5241, guest PC 0x0c065df4 */
if(!s->budget--) { s->failed_pc=0x0c065df4u; return 0; }
r[2]=read(ram,r[4]+4,4);
goto P_0c065df6;
P_0c065df6: /* original 6ad3, guest PC 0x0c065df6 */
if(!s->budget--) { s->failed_pc=0x0c065df6u; return 0; }
r[10]=r[13];
goto P_0c065df8;
P_0c065df8: /* original 7b04, guest PC 0x0c065df8 */
if(!s->budget--) { s->failed_pc=0x0c065df8u; return 0; }
r[11]+=0x00000004u;
goto P_0c065dfa;
P_0c065dfa: /* original 7a08, guest PC 0x0c065dfa */
if(!s->budget--) { s->failed_pc=0x0c065dfau; return 0; }
r[10]+=0x00000008u;
goto P_0c065dfc;
P_0c065dfc: /* original 2b22, guest PC 0x0c065dfc */
if(!s->budget--) { s->failed_pc=0x0c065dfcu; return 0; }
write(ram,r[11],r[2],4);
goto P_0c065dfe;
P_0c065dfe: /* original 5342, guest PC 0x0c065dfe */
if(!s->budget--) { s->failed_pc=0x0c065dfeu; return 0; }
r[3]=read(ram,r[4]+8,4);
goto P_0c065e00;
P_0c065e00: /* original d283, guest PC 0x0c065e00 */
if(!s->budget--) { s->failed_pc=0x0c065e00u; return 0; }
r[2]=read(ram,0x0c066010u,4);
goto P_0c065e02;
P_0c065e02: /* original 2a32, guest PC 0x0c065e02 */
if(!s->budget--) { s->failed_pc=0x0c065e02u; return 0; }
write(ram,r[10],r[3],4);
goto P_0c065e04;
P_0c065e04: /* original 6e22, guest PC 0x0c065e04 */
if(!s->budget--) { s->failed_pc=0x0c065e04u; return 0; }
tmp=read(ram,r[2],4);
r[14]=tmp;
goto P_0c065e06;
P_0c065e06: /* original d383, guest PC 0x0c065e06 */
if(!s->budget--) { s->failed_pc=0x0c065e06u; return 0; }
r[3]=read(ram,0x0c066014u,4);
goto P_0c065e08;
P_0c065e08: /* original 6532, guest PC 0x0c065e08 */
if(!s->budget--) { s->failed_pc=0x0c065e08u; return 0; }
tmp=read(ram,r[3],4);
r[5]=tmp;
goto P_0c065e0a;
P_0c065e0a: /* original d183, guest PC 0x0c065e0a */
if(!s->budget--) { s->failed_pc=0x0c065e0au; return 0; }
r[1]=read(ram,0x0c066018u,4);
goto P_0c065e0c;
P_0c065e0c: /* original 6412, guest PC 0x0c065e0c */
if(!s->budget--) { s->failed_pc=0x0c065e0cu; return 0; }
tmp=read(ram,r[1],4);
r[4]=tmp;
goto P_0c065e0e;
P_0c065e0e: /* original d083, guest PC 0x0c065e0e */
if(!s->budget--) { s->failed_pc=0x0c065e0eu; return 0; }
r[0]=read(ram,0x0c06601cu,4);
goto P_0c065e10;
P_0c065e10: /* original 62c3, guest PC 0x0c065e10 */
if(!s->budget--) { s->failed_pc=0x0c065e10u; return 0; }
r[2]=r[12];
goto P_0c065e12;
P_0c065e12: /* original 7c01, guest PC 0x0c065e12 */
if(!s->budget--) { s->failed_pc=0x0c065e12u; return 0; }
r[12]+=0x00000001u;
goto P_0c065e14;
P_0c065e14: /* original 4208, guest PC 0x0c065e14 */
if(!s->budget--) { s->failed_pc=0x0c065e14u; return 0; }
r[2]<<=2;
goto P_0c065e16;
P_0c065e16: /* original 02e6, guest PC 0x0c065e16 */
if(!s->budget--) { s->failed_pc=0x0c065e16u; return 0; }
write(ram,r[2]+r[0],r[14],4);
goto P_0c065e18;
P_0c065e18: /* original 63c3, guest PC 0x0c065e18 */
if(!s->budget--) { s->failed_pc=0x0c065e18u; return 0; }
r[3]=r[12];
goto P_0c065e1a;
P_0c065e1a: /* original 7c01, guest PC 0x0c065e1a */
if(!s->budget--) { s->failed_pc=0x0c065e1au; return 0; }
r[12]+=0x00000001u;
goto P_0c065e1c;
P_0c065e1c: /* original 4308, guest PC 0x0c065e1c */
if(!s->budget--) { s->failed_pc=0x0c065e1cu; return 0; }
r[3]<<=2;
goto P_0c065e1e;
P_0c065e1e: /* original 0356, guest PC 0x0c065e1e */
if(!s->budget--) { s->failed_pc=0x0c065e1eu; return 0; }
write(ram,r[3]+r[0],r[5],4);
goto P_0c065e20;
P_0c065e20: /* original 62c3, guest PC 0x0c065e20 */
if(!s->budget--) { s->failed_pc=0x0c065e20u; return 0; }
r[2]=r[12];
goto P_0c065e22;
P_0c065e22: /* original 7c01, guest PC 0x0c065e22 */
if(!s->budget--) { s->failed_pc=0x0c065e22u; return 0; }
r[12]+=0x00000001u;
goto P_0c065e24;
P_0c065e24: /* original 4208, guest PC 0x0c065e24 */
if(!s->budget--) { s->failed_pc=0x0c065e24u; return 0; }
r[2]<<=2;
goto P_0c065e26;
P_0c065e26: /* original 0246, guest PC 0x0c065e26 */
if(!s->budget--) { s->failed_pc=0x0c065e26u; return 0; }
write(ram,r[2]+r[0],r[4],4);
goto P_0c065e28;
P_0c065e28: /* original 62d2, guest PC 0x0c065e28 */
if(!s->budget--) { s->failed_pc=0x0c065e28u; return 0; }
tmp=read(ram,r[13],4);
r[2]=tmp;
goto P_0c065e2a;
P_0c065e2a: /* original 63c3, guest PC 0x0c065e2a */
if(!s->budget--) { s->failed_pc=0x0c065e2au; return 0; }
r[3]=r[12];
goto P_0c065e2c;
P_0c065e2c: /* original 5221, guest PC 0x0c065e2c */
if(!s->budget--) { s->failed_pc=0x0c065e2cu; return 0; }
r[2]=read(ram,r[2]+4,4);
goto P_0c065e2e;
P_0c065e2e: /* original 7c01, guest PC 0x0c065e2e */
if(!s->budget--) { s->failed_pc=0x0c065e2eu; return 0; }
r[12]+=0x00000001u;
goto P_0c065e30;
P_0c065e30: /* original 4308, guest PC 0x0c065e30 */
if(!s->budget--) { s->failed_pc=0x0c065e30u; return 0; }
r[3]<<=2;
goto P_0c065e32;
P_0c065e32: /* original 0326, guest PC 0x0c065e32 */
if(!s->budget--) { s->failed_pc=0x0c065e32u; return 0; }
write(ram,r[3]+r[0],r[2],4);
goto P_0c065e34;
P_0c065e34: /* original 62d2, guest PC 0x0c065e34 */
if(!s->budget--) { s->failed_pc=0x0c065e34u; return 0; }
tmp=read(ram,r[13],4);
r[2]=tmp;
goto P_0c065e36;
P_0c065e36: /* original 63c3, guest PC 0x0c065e36 */
if(!s->budget--) { s->failed_pc=0x0c065e36u; return 0; }
r[3]=r[12];
goto P_0c065e38;
P_0c065e38: /* original 5222, guest PC 0x0c065e38 */
if(!s->budget--) { s->failed_pc=0x0c065e38u; return 0; }
r[2]=read(ram,r[2]+8,4);
goto P_0c065e3a;
P_0c065e3a: /* original 7c01, guest PC 0x0c065e3a */
if(!s->budget--) { s->failed_pc=0x0c065e3au; return 0; }
r[12]+=0x00000001u;
goto P_0c065e3c;
P_0c065e3c: /* original 4308, guest PC 0x0c065e3c */
if(!s->budget--) { s->failed_pc=0x0c065e3cu; return 0; }
r[3]<<=2;
goto P_0c065e3e;
P_0c065e3e: /* original 0326, guest PC 0x0c065e3e */
if(!s->budget--) { s->failed_pc=0x0c065e3eu; return 0; }
write(ram,r[3]+r[0],r[2],4);
goto P_0c065e40;
P_0c065e40: /* original 62d2, guest PC 0x0c065e40 */
if(!s->budget--) { s->failed_pc=0x0c065e40u; return 0; }
tmp=read(ram,r[13],4);
r[2]=tmp;
goto P_0c065e42;
P_0c065e42: /* original 63c3, guest PC 0x0c065e42 */
if(!s->budget--) { s->failed_pc=0x0c065e42u; return 0; }
r[3]=r[12];
goto P_0c065e44;
P_0c065e44: /* original 5223, guest PC 0x0c065e44 */
if(!s->budget--) { s->failed_pc=0x0c065e44u; return 0; }
r[2]=read(ram,r[2]+12,4);
goto P_0c065e46;
P_0c065e46: /* original 7c01, guest PC 0x0c065e46 */
if(!s->budget--) { s->failed_pc=0x0c065e46u; return 0; }
r[12]+=0x00000001u;
goto P_0c065e48;
P_0c065e48: /* original 4308, guest PC 0x0c065e48 */
if(!s->budget--) { s->failed_pc=0x0c065e48u; return 0; }
r[3]<<=2;
goto P_0c065e4a;
P_0c065e4a: /* original 0326, guest PC 0x0c065e4a */
if(!s->budget--) { s->failed_pc=0x0c065e4au; return 0; }
write(ram,r[3]+r[0],r[2],4);
goto P_0c065e4c;
P_0c065e4c: /* original 67d2, guest PC 0x0c065e4c */
if(!s->budget--) { s->failed_pc=0x0c065e4cu; return 0; }
tmp=read(ram,r[13],4);
r[7]=tmp;
goto P_0c065e4e;
P_0c065e4e: /* original 2f72, guest PC 0x0c065e4e */
if(!s->budget--) { s->failed_pc=0x0c065e4eu; return 0; }
write(ram,r[15],r[7],4);
goto P_0c065e50;
P_0c065e50: /* original 5775, guest PC 0x0c065e50 */
if(!s->budget--) { s->failed_pc=0x0c065e50u; return 0; }
r[7]=read(ram,r[7]+20,4);
goto P_0c065e52;
P_0c065e52: /* original 65c3, guest PC 0x0c065e52 */
if(!s->budget--) { s->failed_pc=0x0c065e52u; return 0; }
r[5]=r[12];
goto P_0c065e54;
P_0c065e54: /* original d372, guest PC 0x0c065e54 */
if(!s->budget--) { s->failed_pc=0x0c065e54u; return 0; }
r[3]=read(ram,0x0c066020u,4);
goto P_0c065e56;
P_0c065e56: /* original 66f2, guest PC 0x0c065e56 */
if(!s->budget--) { s->failed_pc=0x0c065e56u; return 0; }
tmp=read(ram,r[15],4);
r[6]=tmp;
goto P_0c065e58;
P_0c065e58: /* original 5664, guest PC 0x0c065e58 */
if(!s->budget--) { s->failed_pc=0x0c065e58u; return 0; }
r[6]=read(ram,r[6]+16,4);
goto P_0c065e5a;
P_0c065e5a: /* original 430b, guest PC 0x0c065e5a */
if(!s->budget--) { s->failed_pc=0x0c065e5au; return 0; }
target=r[3];
r[16]=code_base|0x0c065e5eu;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c065e5eu) { target=s->pc; goto dispatch; }
goto P_0c065e5e;
P_0c065e5c: /* original 64e3, guest PC 0x0c065e5c */
if(!s->budget--) { s->failed_pc=0x0c065e5cu; return 0; }
r[4]=r[14];
goto P_0c065e5e;
P_0c065e5e: /* original 6903, guest PC 0x0c065e5e */
if(!s->budget--) { s->failed_pc=0x0c065e5eu; return 0; }
r[9]=r[0];
goto P_0c065e60;
P_0c065e60: /* original 64d2, guest PC 0x0c065e60 */
if(!s->budget--) { s->failed_pc=0x0c065e60u; return 0; }
tmp=read(ram,r[13],4);
r[4]=tmp;
goto P_0c065e62;
P_0c065e62: /* original e118, guest PC 0x0c065e62 */
if(!s->budget--) { s->failed_pc=0x0c065e62u; return 0; }
r[1]=0x00000018u;
goto P_0c065e64;
P_0c065e64: /* original c76f, guest PC 0x0c065e64 */
if(!s->budget--) { s->failed_pc=0x0c065e64u; return 0; }
r[0]=code_base|0x00066024u;
goto P_0c065e66;
P_0c065e66: /* original 6393, guest PC 0x0c065e66 */
if(!s->budget--) { s->failed_pc=0x0c065e66u; return 0; }
r[3]=r[9];
goto P_0c065e68;
P_0c065e68: /* original ff08, guest PC 0x0c065e68 */
if(!s->budget--) { s->failed_pc=0x0c065e68u; return 0; }
vf3_matrix_load(s,ram,15,r[0]);
goto P_0c065e6a;
P_0c065e6a: /* original 314c, guest PC 0x0c065e6a */
if(!s->budget--) { s->failed_pc=0x0c065e6au; return 0; }
r[1]+=r[4];
goto P_0c065e6c;
P_0c065e6c: /* original d06b, guest PC 0x0c065e6c */
if(!s->budget--) { s->failed_pc=0x0c065e6cu; return 0; }
r[0]=read(ram,0x0c06601cu,4);
goto P_0c065e6e;
P_0c065e6e: /* original 7901, guest PC 0x0c065e6e */
if(!s->budget--) { s->failed_pc=0x0c065e6eu; return 0; }
r[9]+=0x00000001u;
goto P_0c065e70;
P_0c065e70: /* original f318, guest PC 0x0c065e70 */
if(!s->budget--) { s->failed_pc=0x0c065e70u; return 0; }
vf3_matrix_load(s,ram,3,r[1]);
goto P_0c065e72;
P_0c065e72: /* original 4308, guest PC 0x0c065e72 */
if(!s->budget--) { s->failed_pc=0x0c065e72u; return 0; }
r[3]<<=2;
goto P_0c065e74;
P_0c065e74: /* original f3f2, guest PC 0x0c065e74 */
if(!s->budget--) { s->failed_pc=0x0c065e74u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[15],r[18],'*');
goto P_0c065e76;
P_0c065e76: /* original f33d, guest PC 0x0c065e76 */
if(!s->budget--) { s->failed_pc=0x0c065e76u; return 0; }
r[53]=truncate_float(fr[3]);
goto P_0c065e78;
P_0c065e78: /* original 045a, guest PC 0x0c065e78 */
if(!s->budget--) { s->failed_pc=0x0c065e78u; return 0; }
r[4]=r[53];
goto P_0c065e7a;
P_0c065e7a: /* original 6243, guest PC 0x0c065e7a */
if(!s->budget--) { s->failed_pc=0x0c065e7au; return 0; }
r[2]=r[4];
goto P_0c065e7c;
P_0c065e7c: /* original 4228, guest PC 0x0c065e7c */
if(!s->budget--) { s->failed_pc=0x0c065e7cu; return 0; }
r[2]<<=16;
goto P_0c065e7e;
P_0c065e7e: /* original 4218, guest PC 0x0c065e7e */
if(!s->budget--) { s->failed_pc=0x0c065e7eu; return 0; }
r[2]<<=8;
goto P_0c065e80;
P_0c065e80: /* original 6143, guest PC 0x0c065e80 */
if(!s->budget--) { s->failed_pc=0x0c065e80u; return 0; }
r[1]=r[4];
goto P_0c065e82;
P_0c065e82: /* original 4128, guest PC 0x0c065e82 */
if(!s->budget--) { s->failed_pc=0x0c065e82u; return 0; }
r[1]<<=16;
goto P_0c065e84;
P_0c065e84: /* original 221b, guest PC 0x0c065e84 */
if(!s->budget--) { s->failed_pc=0x0c065e84u; return 0; }
r[2]|=r[1];
goto P_0c065e86;
P_0c065e86: /* original 6143, guest PC 0x0c065e86 */
if(!s->budget--) { s->failed_pc=0x0c065e86u; return 0; }
r[1]=r[4];
goto P_0c065e88;
P_0c065e88: /* original 4118, guest PC 0x0c065e88 */
if(!s->budget--) { s->failed_pc=0x0c065e88u; return 0; }
r[1]<<=8;
goto P_0c065e8a;
P_0c065e8a: /* original 221b, guest PC 0x0c065e8a */
if(!s->budget--) { s->failed_pc=0x0c065e8au; return 0; }
r[2]|=r[1];
goto P_0c065e8c;
P_0c065e8c: /* original 224b, guest PC 0x0c065e8c */
if(!s->budget--) { s->failed_pc=0x0c065e8cu; return 0; }
r[2]|=r[4];
goto P_0c065e8e;
P_0c065e8e: /* original 0326, guest PC 0x0c065e8e */
if(!s->budget--) { s->failed_pc=0x0c065e8eu; return 0; }
write(ram,r[3]+r[0],r[2],4);
goto P_0c065e90;
P_0c065e90: /* original 6cd2, guest PC 0x0c065e90 */
if(!s->budget--) { s->failed_pc=0x0c065e90u; return 0; }
tmp=read(ram,r[13],4);
r[12]=tmp;
goto P_0c065e92;
P_0c065e92: /* original e01c, guest PC 0x0c065e92 */
if(!s->budget--) { s->failed_pc=0x0c065e92u; return 0; }
r[0]=0x0000001cu;
goto P_0c065e94;
P_0c065e94: /* original f3c6, guest PC 0x0c065e94 */
if(!s->budget--) { s->failed_pc=0x0c065e94u; return 0; }
vf3_matrix_load(s,ram,3,r[12]+r[0]);
goto P_0c065e96;
P_0c065e96: /* original f3f2, guest PC 0x0c065e96 */
if(!s->budget--) { s->failed_pc=0x0c065e96u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[15],r[18],'*');
goto P_0c065e98;
P_0c065e98: /* original f33d, guest PC 0x0c065e98 */
if(!s->budget--) { s->failed_pc=0x0c065e98u; return 0; }
r[53]=truncate_float(fr[3]);
goto P_0c065e9a;
P_0c065e9a: /* original 0c5a, guest PC 0x0c065e9a */
if(!s->budget--) { s->failed_pc=0x0c065e9au; return 0; }
r[12]=r[53];
goto P_0c065e9c;
P_0c065e9c: /* original 66c3, guest PC 0x0c065e9c */
if(!s->budget--) { s->failed_pc=0x0c065e9cu; return 0; }
r[6]=r[12];
goto P_0c065e9e;
P_0c065e9e: /* original 4628, guest PC 0x0c065e9e */
if(!s->budget--) { s->failed_pc=0x0c065e9eu; return 0; }
r[6]<<=16;
goto P_0c065ea0;
P_0c065ea0: /* original 4618, guest PC 0x0c065ea0 */
if(!s->budget--) { s->failed_pc=0x0c065ea0u; return 0; }
r[6]<<=8;
goto P_0c065ea2;
P_0c065ea2: /* original 63c3, guest PC 0x0c065ea2 */
if(!s->budget--) { s->failed_pc=0x0c065ea2u; return 0; }
r[3]=r[12];
goto P_0c065ea4;
P_0c065ea4: /* original 4328, guest PC 0x0c065ea4 */
if(!s->budget--) { s->failed_pc=0x0c065ea4u; return 0; }
r[3]<<=16;
goto P_0c065ea6;
P_0c065ea6: /* original 263b, guest PC 0x0c065ea6 */
if(!s->budget--) { s->failed_pc=0x0c065ea6u; return 0; }
r[6]|=r[3];
goto P_0c065ea8;
P_0c065ea8: /* original d35f, guest PC 0x0c065ea8 */
if(!s->budget--) { s->failed_pc=0x0c065ea8u; return 0; }
r[3]=read(ram,0x0c066028u,4);
goto P_0c065eaa;
P_0c065eaa: /* original 62c3, guest PC 0x0c065eaa */
if(!s->budget--) { s->failed_pc=0x0c065eaau; return 0; }
r[2]=r[12];
goto P_0c065eac;
P_0c065eac: /* original 4218, guest PC 0x0c065eac */
if(!s->budget--) { s->failed_pc=0x0c065eacu; return 0; }
r[2]<<=8;
goto P_0c065eae;
P_0c065eae: /* original 262b, guest PC 0x0c065eae */
if(!s->budget--) { s->failed_pc=0x0c065eaeu; return 0; }
r[6]|=r[2];
goto P_0c065eb0;
P_0c065eb0: /* original 26cb, guest PC 0x0c065eb0 */
if(!s->budget--) { s->failed_pc=0x0c065eb0u; return 0; }
r[6]|=r[12];
goto P_0c065eb2;
P_0c065eb2: /* original 6593, guest PC 0x0c065eb2 */
if(!s->budget--) { s->failed_pc=0x0c065eb2u; return 0; }
r[5]=r[9];
goto P_0c065eb4;
P_0c065eb4: /* original 430b, guest PC 0x0c065eb4 */
if(!s->budget--) { s->failed_pc=0x0c065eb4u; return 0; }
target=r[3];
r[16]=code_base|0x0c065eb8u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c065eb8u) { target=s->pc; goto dispatch; }
goto P_0c065eb8;
P_0c065eb6: /* original 64e3, guest PC 0x0c065eb6 */
if(!s->budget--) { s->failed_pc=0x0c065eb6u; return 0; }
r[4]=r[14];
goto P_0c065eb8;
P_0c065eb8: /* original 61b2, guest PC 0x0c065eb8 */
if(!s->budget--) { s->failed_pc=0x0c065eb8u; return 0; }
tmp=read(ram,r[11],4);
r[1]=tmp;
goto P_0c065eba;
P_0c065eba: /* original 6c03, guest PC 0x0c065eba */
if(!s->budget--) { s->failed_pc=0x0c065ebau; return 0; }
r[12]=r[0];
goto P_0c065ebc;
P_0c065ebc: /* original 5311, guest PC 0x0c065ebc */
if(!s->budget--) { s->failed_pc=0x0c065ebcu; return 0; }
r[3]=read(ram,r[1]+4,4);
goto P_0c065ebe;
P_0c065ebe: /* original 62c3, guest PC 0x0c065ebe */
if(!s->budget--) { s->failed_pc=0x0c065ebeu; return 0; }
r[2]=r[12];
goto P_0c065ec0;
P_0c065ec0: /* original d056, guest PC 0x0c065ec0 */
if(!s->budget--) { s->failed_pc=0x0c065ec0u; return 0; }
r[0]=read(ram,0x0c06601cu,4);
goto P_0c065ec2;
P_0c065ec2: /* original 7c01, guest PC 0x0c065ec2 */
if(!s->budget--) { s->failed_pc=0x0c065ec2u; return 0; }
r[12]+=0x00000001u;
goto P_0c065ec4;
P_0c065ec4: /* original 4208, guest PC 0x0c065ec4 */
if(!s->budget--) { s->failed_pc=0x0c065ec4u; return 0; }
r[2]<<=2;
goto P_0c065ec6;
P_0c065ec6: /* original 0236, guest PC 0x0c065ec6 */
if(!s->budget--) { s->failed_pc=0x0c065ec6u; return 0; }
write(ram,r[2]+r[0],r[3],4);
goto P_0c065ec8;
P_0c065ec8: /* original 61b2, guest PC 0x0c065ec8 */
if(!s->budget--) { s->failed_pc=0x0c065ec8u; return 0; }
tmp=read(ram,r[11],4);
r[1]=tmp;
goto P_0c065eca;
P_0c065eca: /* original 62c3, guest PC 0x0c065eca */
if(!s->budget--) { s->failed_pc=0x0c065ecau; return 0; }
r[2]=r[12];
goto P_0c065ecc;
P_0c065ecc: /* original 5312, guest PC 0x0c065ecc */
if(!s->budget--) { s->failed_pc=0x0c065eccu; return 0; }
r[3]=read(ram,r[1]+8,4);
goto P_0c065ece;
P_0c065ece: /* original 7c01, guest PC 0x0c065ece */
if(!s->budget--) { s->failed_pc=0x0c065eceu; return 0; }
r[12]+=0x00000001u;
goto P_0c065ed0;
P_0c065ed0: /* original 4208, guest PC 0x0c065ed0 */
if(!s->budget--) { s->failed_pc=0x0c065ed0u; return 0; }
r[2]<<=2;
goto P_0c065ed2;
P_0c065ed2: /* original 0236, guest PC 0x0c065ed2 */
if(!s->budget--) { s->failed_pc=0x0c065ed2u; return 0; }
write(ram,r[2]+r[0],r[3],4);
goto P_0c065ed4;
P_0c065ed4: /* original 61b2, guest PC 0x0c065ed4 */
if(!s->budget--) { s->failed_pc=0x0c065ed4u; return 0; }
tmp=read(ram,r[11],4);
r[1]=tmp;
goto P_0c065ed6;
P_0c065ed6: /* original 62c3, guest PC 0x0c065ed6 */
if(!s->budget--) { s->failed_pc=0x0c065ed6u; return 0; }
r[2]=r[12];
goto P_0c065ed8;
P_0c065ed8: /* original 5313, guest PC 0x0c065ed8 */
if(!s->budget--) { s->failed_pc=0x0c065ed8u; return 0; }
r[3]=read(ram,r[1]+12,4);
goto P_0c065eda;
P_0c065eda: /* original 7c01, guest PC 0x0c065eda */
if(!s->budget--) { s->failed_pc=0x0c065edau; return 0; }
r[12]+=0x00000001u;
goto P_0c065edc;
P_0c065edc: /* original 4208, guest PC 0x0c065edc */
if(!s->budget--) { s->failed_pc=0x0c065edcu; return 0; }
r[2]<<=2;
goto P_0c065ede;
P_0c065ede: /* original 0236, guest PC 0x0c065ede */
if(!s->budget--) { s->failed_pc=0x0c065edeu; return 0; }
write(ram,r[2]+r[0],r[3],4);
goto P_0c065ee0;
P_0c065ee0: /* original 67b2, guest PC 0x0c065ee0 */
if(!s->budget--) { s->failed_pc=0x0c065ee0u; return 0; }
tmp=read(ram,r[11],4);
r[7]=tmp;
goto P_0c065ee2;
P_0c065ee2: /* original 65c3, guest PC 0x0c065ee2 */
if(!s->budget--) { s->failed_pc=0x0c065ee2u; return 0; }
r[5]=r[12];
goto P_0c065ee4;
P_0c065ee4: /* original d34e, guest PC 0x0c065ee4 */
if(!s->budget--) { s->failed_pc=0x0c065ee4u; return 0; }
r[3]=read(ram,0x0c066020u,4);
goto P_0c065ee6;
P_0c065ee6: /* original 2f72, guest PC 0x0c065ee6 */
if(!s->budget--) { s->failed_pc=0x0c065ee6u; return 0; }
write(ram,r[15],r[7],4);
goto P_0c065ee8;
P_0c065ee8: /* original 5775, guest PC 0x0c065ee8 */
if(!s->budget--) { s->failed_pc=0x0c065ee8u; return 0; }
r[7]=read(ram,r[7]+20,4);
goto P_0c065eea;
P_0c065eea: /* original 66f2, guest PC 0x0c065eea */
if(!s->budget--) { s->failed_pc=0x0c065eeau; return 0; }
tmp=read(ram,r[15],4);
r[6]=tmp;
goto P_0c065eec;
P_0c065eec: /* original 5664, guest PC 0x0c065eec */
if(!s->budget--) { s->failed_pc=0x0c065eecu; return 0; }
r[6]=read(ram,r[6]+16,4);
goto P_0c065eee;
P_0c065eee: /* original 430b, guest PC 0x0c065eee */
if(!s->budget--) { s->failed_pc=0x0c065eeeu; return 0; }
target=r[3];
r[16]=code_base|0x0c065ef2u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c065ef2u) { target=s->pc; goto dispatch; }
goto P_0c065ef2;
P_0c065ef0: /* original 64e3, guest PC 0x0c065ef0 */
if(!s->budget--) { s->failed_pc=0x0c065ef0u; return 0; }
r[4]=r[14];
goto P_0c065ef2;
P_0c065ef2: /* original 6903, guest PC 0x0c065ef2 */
if(!s->budget--) { s->failed_pc=0x0c065ef2u; return 0; }
r[9]=r[0];
goto P_0c065ef4;
P_0c065ef4: /* original 64b2, guest PC 0x0c065ef4 */
if(!s->budget--) { s->failed_pc=0x0c065ef4u; return 0; }
tmp=read(ram,r[11],4);
r[4]=tmp;
goto P_0c065ef6;
P_0c065ef6: /* original e118, guest PC 0x0c065ef6 */
if(!s->budget--) { s->failed_pc=0x0c065ef6u; return 0; }
r[1]=0x00000018u;
goto P_0c065ef8;
P_0c065ef8: /* original d048, guest PC 0x0c065ef8 */
if(!s->budget--) { s->failed_pc=0x0c065ef8u; return 0; }
r[0]=read(ram,0x0c06601cu,4);
goto P_0c065efa;
P_0c065efa: /* original 6293, guest PC 0x0c065efa */
if(!s->budget--) { s->failed_pc=0x0c065efau; return 0; }
r[2]=r[9];
goto P_0c065efc;
P_0c065efc: /* original 7901, guest PC 0x0c065efc */
if(!s->budget--) { s->failed_pc=0x0c065efcu; return 0; }
r[9]+=0x00000001u;
goto P_0c065efe;
P_0c065efe: /* original 4208, guest PC 0x0c065efe */
if(!s->budget--) { s->failed_pc=0x0c065efeu; return 0; }
r[2]<<=2;
goto P_0c065f00;
P_0c065f00: /* original 314c, guest PC 0x0c065f00 */
if(!s->budget--) { s->failed_pc=0x0c065f00u; return 0; }
r[1]+=r[4];
goto P_0c065f02;
P_0c065f02: /* original f318, guest PC 0x0c065f02 */
if(!s->budget--) { s->failed_pc=0x0c065f02u; return 0; }
vf3_matrix_load(s,ram,3,r[1]);
goto P_0c065f04;
P_0c065f04: /* original f3f2, guest PC 0x0c065f04 */
if(!s->budget--) { s->failed_pc=0x0c065f04u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[15],r[18],'*');
goto P_0c065f06;
P_0c065f06: /* original f33d, guest PC 0x0c065f06 */
if(!s->budget--) { s->failed_pc=0x0c065f06u; return 0; }
r[53]=truncate_float(fr[3]);
goto P_0c065f08;
P_0c065f08: /* original 045a, guest PC 0x0c065f08 */
if(!s->budget--) { s->failed_pc=0x0c065f08u; return 0; }
r[4]=r[53];
goto P_0c065f0a;
P_0c065f0a: /* original 6343, guest PC 0x0c065f0a */
if(!s->budget--) { s->failed_pc=0x0c065f0au; return 0; }
r[3]=r[4];
goto P_0c065f0c;
P_0c065f0c: /* original 4328, guest PC 0x0c065f0c */
if(!s->budget--) { s->failed_pc=0x0c065f0cu; return 0; }
r[3]<<=16;
goto P_0c065f0e;
P_0c065f0e: /* original 4318, guest PC 0x0c065f0e */
if(!s->budget--) { s->failed_pc=0x0c065f0eu; return 0; }
r[3]<<=8;
goto P_0c065f10;
P_0c065f10: /* original 6143, guest PC 0x0c065f10 */
if(!s->budget--) { s->failed_pc=0x0c065f10u; return 0; }
r[1]=r[4];
goto P_0c065f12;
P_0c065f12: /* original 4128, guest PC 0x0c065f12 */
if(!s->budget--) { s->failed_pc=0x0c065f12u; return 0; }
r[1]<<=16;
goto P_0c065f14;
P_0c065f14: /* original 231b, guest PC 0x0c065f14 */
if(!s->budget--) { s->failed_pc=0x0c065f14u; return 0; }
r[3]|=r[1];
goto P_0c065f16;
P_0c065f16: /* original 6143, guest PC 0x0c065f16 */
if(!s->budget--) { s->failed_pc=0x0c065f16u; return 0; }
r[1]=r[4];
goto P_0c065f18;
P_0c065f18: /* original 4118, guest PC 0x0c065f18 */
if(!s->budget--) { s->failed_pc=0x0c065f18u; return 0; }
r[1]<<=8;
goto P_0c065f1a;
P_0c065f1a: /* original 231b, guest PC 0x0c065f1a */
if(!s->budget--) { s->failed_pc=0x0c065f1au; return 0; }
r[3]|=r[1];
goto P_0c065f1c;
P_0c065f1c: /* original 234b, guest PC 0x0c065f1c */
if(!s->budget--) { s->failed_pc=0x0c065f1cu; return 0; }
r[3]|=r[4];
goto P_0c065f1e;
P_0c065f1e: /* original 0236, guest PC 0x0c065f1e */
if(!s->budget--) { s->failed_pc=0x0c065f1eu; return 0; }
write(ram,r[2]+r[0],r[3],4);
goto P_0c065f20;
P_0c065f20: /* original 6cb2, guest PC 0x0c065f20 */
if(!s->budget--) { s->failed_pc=0x0c065f20u; return 0; }
tmp=read(ram,r[11],4);
r[12]=tmp;
goto P_0c065f22;
P_0c065f22: /* original e01c, guest PC 0x0c065f22 */
if(!s->budget--) { s->failed_pc=0x0c065f22u; return 0; }
r[0]=0x0000001cu;
goto P_0c065f24;
P_0c065f24: /* original f3c6, guest PC 0x0c065f24 */
if(!s->budget--) { s->failed_pc=0x0c065f24u; return 0; }
vf3_matrix_load(s,ram,3,r[12]+r[0]);
goto P_0c065f26;
P_0c065f26: /* original f3f2, guest PC 0x0c065f26 */
if(!s->budget--) { s->failed_pc=0x0c065f26u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[15],r[18],'*');
goto P_0c065f28;
P_0c065f28: /* original f33d, guest PC 0x0c065f28 */
if(!s->budget--) { s->failed_pc=0x0c065f28u; return 0; }
r[53]=truncate_float(fr[3]);
goto P_0c065f2a;
P_0c065f2a: /* original 0c5a, guest PC 0x0c065f2a */
if(!s->budget--) { s->failed_pc=0x0c065f2au; return 0; }
r[12]=r[53];
goto P_0c065f2c;
P_0c065f2c: /* original 66c3, guest PC 0x0c065f2c */
if(!s->budget--) { s->failed_pc=0x0c065f2cu; return 0; }
r[6]=r[12];
goto P_0c065f2e;
P_0c065f2e: /* original 4628, guest PC 0x0c065f2e */
if(!s->budget--) { s->failed_pc=0x0c065f2eu; return 0; }
r[6]<<=16;
goto P_0c065f30;
P_0c065f30: /* original 4618, guest PC 0x0c065f30 */
if(!s->budget--) { s->failed_pc=0x0c065f30u; return 0; }
r[6]<<=8;
goto P_0c065f32;
P_0c065f32: /* original 63c3, guest PC 0x0c065f32 */
if(!s->budget--) { s->failed_pc=0x0c065f32u; return 0; }
r[3]=r[12];
goto P_0c065f34;
P_0c065f34: /* original 4328, guest PC 0x0c065f34 */
if(!s->budget--) { s->failed_pc=0x0c065f34u; return 0; }
r[3]<<=16;
goto P_0c065f36;
P_0c065f36: /* original 263b, guest PC 0x0c065f36 */
if(!s->budget--) { s->failed_pc=0x0c065f36u; return 0; }
r[6]|=r[3];
goto P_0c065f38;
P_0c065f38: /* original d33b, guest PC 0x0c065f38 */
if(!s->budget--) { s->failed_pc=0x0c065f38u; return 0; }
r[3]=read(ram,0x0c066028u,4);
goto P_0c065f3a;
P_0c065f3a: /* original 62c3, guest PC 0x0c065f3a */
if(!s->budget--) { s->failed_pc=0x0c065f3au; return 0; }
r[2]=r[12];
goto P_0c065f3c;
P_0c065f3c: /* original 4218, guest PC 0x0c065f3c */
if(!s->budget--) { s->failed_pc=0x0c065f3cu; return 0; }
r[2]<<=8;
goto P_0c065f3e;
P_0c065f3e: /* original 262b, guest PC 0x0c065f3e */
if(!s->budget--) { s->failed_pc=0x0c065f3eu; return 0; }
r[6]|=r[2];
goto P_0c065f40;
P_0c065f40: /* original 26cb, guest PC 0x0c065f40 */
if(!s->budget--) { s->failed_pc=0x0c065f40u; return 0; }
r[6]|=r[12];
goto P_0c065f42;
P_0c065f42: /* original 6593, guest PC 0x0c065f42 */
if(!s->budget--) { s->failed_pc=0x0c065f42u; return 0; }
r[5]=r[9];
goto P_0c065f44;
P_0c065f44: /* original 430b, guest PC 0x0c065f44 */
if(!s->budget--) { s->failed_pc=0x0c065f44u; return 0; }
target=r[3];
r[16]=code_base|0x0c065f48u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c065f48u) { target=s->pc; goto dispatch; }
goto P_0c065f48;
P_0c065f46: /* original 64e3, guest PC 0x0c065f46 */
if(!s->budget--) { s->failed_pc=0x0c065f46u; return 0; }
r[4]=r[14];
goto P_0c065f48;
P_0c065f48: /* original 61a2, guest PC 0x0c065f48 */
if(!s->budget--) { s->failed_pc=0x0c065f48u; return 0; }
tmp=read(ram,r[10],4);
r[1]=tmp;
goto P_0c065f4a;
P_0c065f4a: /* original 6c03, guest PC 0x0c065f4a */
if(!s->budget--) { s->failed_pc=0x0c065f4au; return 0; }
r[12]=r[0];
goto P_0c065f4c;
P_0c065f4c: /* original 5311, guest PC 0x0c065f4c */
if(!s->budget--) { s->failed_pc=0x0c065f4cu; return 0; }
r[3]=read(ram,r[1]+4,4);
goto P_0c065f4e;
P_0c065f4e: /* original 62c3, guest PC 0x0c065f4e */
if(!s->budget--) { s->failed_pc=0x0c065f4eu; return 0; }
r[2]=r[12];
goto P_0c065f50;
P_0c065f50: /* original d032, guest PC 0x0c065f50 */
if(!s->budget--) { s->failed_pc=0x0c065f50u; return 0; }
r[0]=read(ram,0x0c06601cu,4);
goto P_0c065f52;
P_0c065f52: /* original 7c01, guest PC 0x0c065f52 */
if(!s->budget--) { s->failed_pc=0x0c065f52u; return 0; }
r[12]+=0x00000001u;
goto P_0c065f54;
P_0c065f54: /* original 4208, guest PC 0x0c065f54 */
if(!s->budget--) { s->failed_pc=0x0c065f54u; return 0; }
r[2]<<=2;
goto P_0c065f56;
P_0c065f56: /* original 0236, guest PC 0x0c065f56 */
if(!s->budget--) { s->failed_pc=0x0c065f56u; return 0; }
write(ram,r[2]+r[0],r[3],4);
goto P_0c065f58;
P_0c065f58: /* original 61a2, guest PC 0x0c065f58 */
if(!s->budget--) { s->failed_pc=0x0c065f58u; return 0; }
tmp=read(ram,r[10],4);
r[1]=tmp;
goto P_0c065f5a;
P_0c065f5a: /* original 62c3, guest PC 0x0c065f5a */
if(!s->budget--) { s->failed_pc=0x0c065f5au; return 0; }
r[2]=r[12];
goto P_0c065f5c;
P_0c065f5c: /* original 5312, guest PC 0x0c065f5c */
if(!s->budget--) { s->failed_pc=0x0c065f5cu; return 0; }
r[3]=read(ram,r[1]+8,4);
goto P_0c065f5e;
P_0c065f5e: /* original 7c01, guest PC 0x0c065f5e */
if(!s->budget--) { s->failed_pc=0x0c065f5eu; return 0; }
r[12]+=0x00000001u;
goto P_0c065f60;
P_0c065f60: /* original 4208, guest PC 0x0c065f60 */
if(!s->budget--) { s->failed_pc=0x0c065f60u; return 0; }
r[2]<<=2;
goto P_0c065f62;
P_0c065f62: /* original 0236, guest PC 0x0c065f62 */
if(!s->budget--) { s->failed_pc=0x0c065f62u; return 0; }
write(ram,r[2]+r[0],r[3],4);
goto P_0c065f64;
P_0c065f64: /* original 61a2, guest PC 0x0c065f64 */
if(!s->budget--) { s->failed_pc=0x0c065f64u; return 0; }
tmp=read(ram,r[10],4);
r[1]=tmp;
goto P_0c065f66;
P_0c065f66: /* original 62c3, guest PC 0x0c065f66 */
if(!s->budget--) { s->failed_pc=0x0c065f66u; return 0; }
r[2]=r[12];
goto P_0c065f68;
P_0c065f68: /* original 5313, guest PC 0x0c065f68 */
if(!s->budget--) { s->failed_pc=0x0c065f68u; return 0; }
r[3]=read(ram,r[1]+12,4);
goto P_0c065f6a;
P_0c065f6a: /* original 7c01, guest PC 0x0c065f6a */
if(!s->budget--) { s->failed_pc=0x0c065f6au; return 0; }
r[12]+=0x00000001u;
goto P_0c065f6c;
P_0c065f6c: /* original 4208, guest PC 0x0c065f6c */
if(!s->budget--) { s->failed_pc=0x0c065f6cu; return 0; }
r[2]<<=2;
goto P_0c065f6e;
P_0c065f6e: /* original 0236, guest PC 0x0c065f6e */
if(!s->budget--) { s->failed_pc=0x0c065f6eu; return 0; }
write(ram,r[2]+r[0],r[3],4);
goto P_0c065f70;
P_0c065f70: /* original 67a2, guest PC 0x0c065f70 */
if(!s->budget--) { s->failed_pc=0x0c065f70u; return 0; }
tmp=read(ram,r[10],4);
r[7]=tmp;
goto P_0c065f72;
P_0c065f72: /* original 65c3, guest PC 0x0c065f72 */
if(!s->budget--) { s->failed_pc=0x0c065f72u; return 0; }
r[5]=r[12];
goto P_0c065f74;
P_0c065f74: /* original d32a, guest PC 0x0c065f74 */
if(!s->budget--) { s->failed_pc=0x0c065f74u; return 0; }
r[3]=read(ram,0x0c066020u,4);
goto P_0c065f76;
P_0c065f76: /* original 2f72, guest PC 0x0c065f76 */
if(!s->budget--) { s->failed_pc=0x0c065f76u; return 0; }
write(ram,r[15],r[7],4);
goto P_0c065f78;
P_0c065f78: /* original 5775, guest PC 0x0c065f78 */
if(!s->budget--) { s->failed_pc=0x0c065f78u; return 0; }
r[7]=read(ram,r[7]+20,4);
goto P_0c065f7a;
P_0c065f7a: /* original 66f2, guest PC 0x0c065f7a */
if(!s->budget--) { s->failed_pc=0x0c065f7au; return 0; }
tmp=read(ram,r[15],4);
r[6]=tmp;
goto P_0c065f7c;
P_0c065f7c: /* original 5664, guest PC 0x0c065f7c */
if(!s->budget--) { s->failed_pc=0x0c065f7cu; return 0; }
r[6]=read(ram,r[6]+16,4);
goto P_0c065f7e;
P_0c065f7e: /* original 430b, guest PC 0x0c065f7e */
if(!s->budget--) { s->failed_pc=0x0c065f7eu; return 0; }
target=r[3];
r[16]=code_base|0x0c065f82u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c065f82u) { target=s->pc; goto dispatch; }
goto P_0c065f82;
P_0c065f80: /* original 64e3, guest PC 0x0c065f80 */
if(!s->budget--) { s->failed_pc=0x0c065f80u; return 0; }
r[4]=r[14];
goto P_0c065f82;
P_0c065f82: /* original 6b03, guest PC 0x0c065f82 */
if(!s->budget--) { s->failed_pc=0x0c065f82u; return 0; }
r[11]=r[0];
goto P_0c065f84;
P_0c065f84: /* original 64a2, guest PC 0x0c065f84 */
if(!s->budget--) { s->failed_pc=0x0c065f84u; return 0; }
tmp=read(ram,r[10],4);
r[4]=tmp;
goto P_0c065f86;
P_0c065f86: /* original e118, guest PC 0x0c065f86 */
if(!s->budget--) { s->failed_pc=0x0c065f86u; return 0; }
r[1]=0x00000018u;
goto P_0c065f88;
P_0c065f88: /* original d024, guest PC 0x0c065f88 */
if(!s->budget--) { s->failed_pc=0x0c065f88u; return 0; }
r[0]=read(ram,0x0c06601cu,4);
goto P_0c065f8a;
P_0c065f8a: /* original 62b3, guest PC 0x0c065f8a */
if(!s->budget--) { s->failed_pc=0x0c065f8au; return 0; }
r[2]=r[11];
goto P_0c065f8c;
P_0c065f8c: /* original 7b01, guest PC 0x0c065f8c */
if(!s->budget--) { s->failed_pc=0x0c065f8cu; return 0; }
r[11]+=0x00000001u;
goto P_0c065f8e;
P_0c065f8e: /* original 4208, guest PC 0x0c065f8e */
if(!s->budget--) { s->failed_pc=0x0c065f8eu; return 0; }
r[2]<<=2;
goto P_0c065f90;
P_0c065f90: /* original 314c, guest PC 0x0c065f90 */
if(!s->budget--) { s->failed_pc=0x0c065f90u; return 0; }
r[1]+=r[4];
goto P_0c065f92;
P_0c065f92: /* original f318, guest PC 0x0c065f92 */
if(!s->budget--) { s->failed_pc=0x0c065f92u; return 0; }
vf3_matrix_load(s,ram,3,r[1]);
goto P_0c065f94;
P_0c065f94: /* original f3f2, guest PC 0x0c065f94 */
if(!s->budget--) { s->failed_pc=0x0c065f94u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[15],r[18],'*');
goto P_0c065f96;
P_0c065f96: /* original f33d, guest PC 0x0c065f96 */
if(!s->budget--) { s->failed_pc=0x0c065f96u; return 0; }
r[53]=truncate_float(fr[3]);
goto P_0c065f98;
P_0c065f98: /* original 045a, guest PC 0x0c065f98 */
if(!s->budget--) { s->failed_pc=0x0c065f98u; return 0; }
r[4]=r[53];
goto P_0c065f9a;
P_0c065f9a: /* original 6343, guest PC 0x0c065f9a */
if(!s->budget--) { s->failed_pc=0x0c065f9au; return 0; }
r[3]=r[4];
goto P_0c065f9c;
P_0c065f9c: /* original 4328, guest PC 0x0c065f9c */
if(!s->budget--) { s->failed_pc=0x0c065f9cu; return 0; }
r[3]<<=16;
goto P_0c065f9e;
P_0c065f9e: /* original 4318, guest PC 0x0c065f9e */
if(!s->budget--) { s->failed_pc=0x0c065f9eu; return 0; }
r[3]<<=8;
goto P_0c065fa0;
P_0c065fa0: /* original 6143, guest PC 0x0c065fa0 */
if(!s->budget--) { s->failed_pc=0x0c065fa0u; return 0; }
r[1]=r[4];
goto P_0c065fa2;
P_0c065fa2: /* original 4128, guest PC 0x0c065fa2 */
if(!s->budget--) { s->failed_pc=0x0c065fa2u; return 0; }
r[1]<<=16;
goto P_0c065fa4;
P_0c065fa4: /* original 231b, guest PC 0x0c065fa4 */
if(!s->budget--) { s->failed_pc=0x0c065fa4u; return 0; }
r[3]|=r[1];
goto P_0c065fa6;
P_0c065fa6: /* original 6143, guest PC 0x0c065fa6 */
if(!s->budget--) { s->failed_pc=0x0c065fa6u; return 0; }
r[1]=r[4];
goto P_0c065fa8;
P_0c065fa8: /* original 4118, guest PC 0x0c065fa8 */
if(!s->budget--) { s->failed_pc=0x0c065fa8u; return 0; }
r[1]<<=8;
goto P_0c065faa;
P_0c065faa: /* original 231b, guest PC 0x0c065faa */
if(!s->budget--) { s->failed_pc=0x0c065faau; return 0; }
r[3]|=r[1];
goto P_0c065fac;
P_0c065fac: /* original 234b, guest PC 0x0c065fac */
if(!s->budget--) { s->failed_pc=0x0c065facu; return 0; }
r[3]|=r[4];
goto P_0c065fae;
P_0c065fae: /* original 0236, guest PC 0x0c065fae */
if(!s->budget--) { s->failed_pc=0x0c065faeu; return 0; }
write(ram,r[2]+r[0],r[3],4);
goto P_0c065fb0;
P_0c065fb0: /* original 6ca2, guest PC 0x0c065fb0 */
if(!s->budget--) { s->failed_pc=0x0c065fb0u; return 0; }
tmp=read(ram,r[10],4);
r[12]=tmp;
goto P_0c065fb2;
P_0c065fb2: /* original e01c, guest PC 0x0c065fb2 */
if(!s->budget--) { s->failed_pc=0x0c065fb2u; return 0; }
r[0]=0x0000001cu;
goto P_0c065fb4;
P_0c065fb4: /* original f3c6, guest PC 0x0c065fb4 */
if(!s->budget--) { s->failed_pc=0x0c065fb4u; return 0; }
vf3_matrix_load(s,ram,3,r[12]+r[0]);
goto P_0c065fb6;
P_0c065fb6: /* original f3f2, guest PC 0x0c065fb6 */
if(!s->budget--) { s->failed_pc=0x0c065fb6u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[15],r[18],'*');
goto P_0c065fb8;
P_0c065fb8: /* original f33d, guest PC 0x0c065fb8 */
if(!s->budget--) { s->failed_pc=0x0c065fb8u; return 0; }
r[53]=truncate_float(fr[3]);
goto P_0c065fba;
P_0c065fba: /* original 0c5a, guest PC 0x0c065fba */
if(!s->budget--) { s->failed_pc=0x0c065fbau; return 0; }
r[12]=r[53];
goto P_0c065fbc;
P_0c065fbc: /* original 66c3, guest PC 0x0c065fbc */
if(!s->budget--) { s->failed_pc=0x0c065fbcu; return 0; }
r[6]=r[12];
goto P_0c065fbe;
P_0c065fbe: /* original 4628, guest PC 0x0c065fbe */
if(!s->budget--) { s->failed_pc=0x0c065fbeu; return 0; }
r[6]<<=16;
goto P_0c065fc0;
P_0c065fc0: /* original 4618, guest PC 0x0c065fc0 */
if(!s->budget--) { s->failed_pc=0x0c065fc0u; return 0; }
r[6]<<=8;
goto P_0c065fc2;
P_0c065fc2: /* original 63c3, guest PC 0x0c065fc2 */
if(!s->budget--) { s->failed_pc=0x0c065fc2u; return 0; }
r[3]=r[12];
goto P_0c065fc4;
P_0c065fc4: /* original 4328, guest PC 0x0c065fc4 */
if(!s->budget--) { s->failed_pc=0x0c065fc4u; return 0; }
r[3]<<=16;
goto P_0c065fc6;
P_0c065fc6: /* original 263b, guest PC 0x0c065fc6 */
if(!s->budget--) { s->failed_pc=0x0c065fc6u; return 0; }
r[6]|=r[3];
goto P_0c065fc8;
P_0c065fc8: /* original d317, guest PC 0x0c065fc8 */
if(!s->budget--) { s->failed_pc=0x0c065fc8u; return 0; }
r[3]=read(ram,0x0c066028u,4);
goto P_0c065fca;
P_0c065fca: /* original 62c3, guest PC 0x0c065fca */
if(!s->budget--) { s->failed_pc=0x0c065fcau; return 0; }
r[2]=r[12];
goto P_0c065fcc;
P_0c065fcc: /* original 4218, guest PC 0x0c065fcc */
if(!s->budget--) { s->failed_pc=0x0c065fccu; return 0; }
r[2]<<=8;
goto P_0c065fce;
P_0c065fce: /* original 262b, guest PC 0x0c065fce */
if(!s->budget--) { s->failed_pc=0x0c065fceu; return 0; }
r[6]|=r[2];
goto P_0c065fd0;
P_0c065fd0: /* original 26cb, guest PC 0x0c065fd0 */
if(!s->budget--) { s->failed_pc=0x0c065fd0u; return 0; }
r[6]|=r[12];
goto P_0c065fd2;
P_0c065fd2: /* original 65b3, guest PC 0x0c065fd2 */
if(!s->budget--) { s->failed_pc=0x0c065fd2u; return 0; }
r[5]=r[11];
goto P_0c065fd4;
P_0c065fd4: /* original 430b, guest PC 0x0c065fd4 */
if(!s->budget--) { s->failed_pc=0x0c065fd4u; return 0; }
target=r[3];
r[16]=code_base|0x0c065fd8u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c065fd8u) { target=s->pc; goto dispatch; }
goto P_0c065fd8;
P_0c065fd6: /* original 64e3, guest PC 0x0c065fd6 */
if(!s->budget--) { s->failed_pc=0x0c065fd6u; return 0; }
r[4]=r[14];
goto P_0c065fd8;
P_0c065fd8: /* original d214, guest PC 0x0c065fd8 */
if(!s->budget--) { s->failed_pc=0x0c065fd8u; return 0; }
r[2]=read(ram,0x0c06602cu,4);
goto P_0c065fda;
P_0c065fda: /* original 6403, guest PC 0x0c065fda */
if(!s->budget--) { s->failed_pc=0x0c065fdau; return 0; }
r[4]=r[0];
goto P_0c065fdc;
P_0c065fdc: /* original 4408, guest PC 0x0c065fdc */
if(!s->budget--) { s->failed_pc=0x0c065fdcu; return 0; }
r[4]<<=2;
goto P_0c065fde;
P_0c065fde: /* original 2242, guest PC 0x0c065fde */
if(!s->budget--) { s->failed_pc=0x0c065fdeu; return 0; }
write(ram,r[2],r[4],4);
goto P_0c065fe0;
P_0c065fe0: /* original d313, guest PC 0x0c065fe0 */
if(!s->budget--) { s->failed_pc=0x0c065fe0u; return 0; }
r[3]=read(ram,0x0c066030u,4);
goto P_0c065fe2;
P_0c065fe2: /* original 430b, guest PC 0x0c065fe2 */
if(!s->budget--) { s->failed_pc=0x0c065fe2u; return 0; }
target=r[3];
r[16]=code_base|0x0c065fe6u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c065fe6u) { target=s->pc; goto dispatch; }
goto P_0c065fe6;
P_0c065fe4: /* original 64e3, guest PC 0x0c065fe4 */
if(!s->budget--) { s->failed_pc=0x0c065fe4u; return 0; }
r[4]=r[14];
goto P_0c065fe6;
P_0c065fe6: /* original 6403, guest PC 0x0c065fe6 */
if(!s->budget--) { s->failed_pc=0x0c065fe6u; return 0; }
r[4]=r[0];
goto P_0c065fe8;
P_0c065fe8: /* original d212, guest PC 0x0c065fe8 */
if(!s->budget--) { s->failed_pc=0x0c065fe8u; return 0; }
r[2]=read(ram,0x0c066034u,4);
goto P_0c065fea;
P_0c065fea: /* original e500, guest PC 0x0c065fea */
if(!s->budget--) { s->failed_pc=0x0c065feau; return 0; }
r[5]=0x00000000u;
goto P_0c065fec;
P_0c065fec: /* original 420b, guest PC 0x0c065fec */
if(!s->budget--) { s->failed_pc=0x0c065fecu; return 0; }
target=r[2];
r[16]=code_base|0x0c065ff0u;
r[6]=r[5];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c065ff0u) { target=s->pc; goto dispatch; }
goto P_0c065ff0;
P_0c065fee: /* original 6653, guest PC 0x0c065fee */
if(!s->budget--) { s->failed_pc=0x0c065feeu; return 0; }
r[6]=r[5];
goto P_0c065ff0;
P_0c065ff0: /* original 62d2, guest PC 0x0c065ff0 */
if(!s->budget--) { s->failed_pc=0x0c065ff0u; return 0; }
tmp=read(ram,r[13],4);
r[2]=tmp;
goto P_0c065ff2;
P_0c065ff2: /* original 5323, guest PC 0x0c065ff2 */
if(!s->budget--) { s->failed_pc=0x0c065ff2u; return 0; }
r[3]=read(ram,r[2]+12,4);
goto P_0c065ff4;
P_0c065ff4: /* original d110, guest PC 0x0c065ff4 */
if(!s->budget--) { s->failed_pc=0x0c065ff4u; return 0; }
r[1]=read(ram,0x0c066038u,4);
goto P_0c065ff6;
P_0c065ff6: /* original 2132, guest PC 0x0c065ff6 */
if(!s->budget--) { s->failed_pc=0x0c065ff6u; return 0; }
write(ram,r[1],r[3],4);
goto P_0c065ff8;
P_0c065ff8: /* original e000, guest PC 0x0c065ff8 */
if(!s->budget--) { s->failed_pc=0x0c065ff8u; return 0; }
r[0]=0x00000000u;
goto P_0c065ffa;
P_0c065ffa: /* original 7f10, guest PC 0x0c065ffa */
if(!s->budget--) { s->failed_pc=0x0c065ffau; return 0; }
r[15]+=0x00000010u;
goto P_0c065ffc;
P_0c065ffc: /* original 4f26, guest PC 0x0c065ffc */
if(!s->budget--) { s->failed_pc=0x0c065ffcu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c065ffe;
P_0c065ffe: /* original fff9, guest PC 0x0c065ffe */
if(!s->budget--) { s->failed_pc=0x0c065ffeu; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c066000;
P_0c066000: /* original 69f6, guest PC 0x0c066000 */
if(!s->budget--) { s->failed_pc=0x0c066000u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c066002;
P_0c066002: /* original 6af6, guest PC 0x0c066002 */
if(!s->budget--) { s->failed_pc=0x0c066002u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c066004;
P_0c066004: /* original 6bf6, guest PC 0x0c066004 */
if(!s->budget--) { s->failed_pc=0x0c066004u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c066006;
P_0c066006: /* original 6cf6, guest PC 0x0c066006 */
if(!s->budget--) { s->failed_pc=0x0c066006u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c066008;
P_0c066008: /* original 6df6, guest PC 0x0c066008 */
if(!s->budget--) { s->failed_pc=0x0c066008u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c06600a;
P_0c06600a: /* original 000b, guest PC 0x0c06600a */
if(!s->budget--) { s->failed_pc=0x0c06600au; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c06600c: /* original 6ef6, guest PC 0x0c06600c */
if(!s->budget--) { s->failed_pc=0x0c06600cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c06600eu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c06600eu; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
