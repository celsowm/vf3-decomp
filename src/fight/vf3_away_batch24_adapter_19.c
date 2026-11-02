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
int vf3_away_batch24_adapter_19(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c0c0ebau: goto P_0c0c0eba;
case 0x0c0c0ebcu: goto P_0c0c0ebc;
case 0x0c0c0ebeu: goto P_0c0c0ebe;
case 0x0c0c0ec0u: goto P_0c0c0ec0;
case 0x0c0c0ec2u: goto P_0c0c0ec2;
case 0x0c0c0ec4u: goto P_0c0c0ec4;
case 0x0c0c0ec6u: goto P_0c0c0ec6;
case 0x0c0c0ec8u: goto P_0c0c0ec8;
case 0x0c0c0ecau: goto P_0c0c0eca;
case 0x0c0c0eccu: goto P_0c0c0ecc;
case 0x0c0c0eceu: goto P_0c0c0ece;
case 0x0c0c0ed0u: goto P_0c0c0ed0;
case 0x0c0c0ed2u: goto P_0c0c0ed2;
case 0x0c0c0ed4u: goto P_0c0c0ed4;
case 0x0c0c0ed6u: goto P_0c0c0ed6;
case 0x0c0c0ed8u: goto P_0c0c0ed8;
case 0x0c0c0edau: goto P_0c0c0eda;
case 0x0c0c0edcu: goto P_0c0c0edc;
case 0x0c0c0edeu: goto P_0c0c0ede;
case 0x0c0c0ee0u: goto P_0c0c0ee0;
case 0x0c0c0ee2u: goto P_0c0c0ee2;
case 0x0c0c0ee4u: goto P_0c0c0ee4;
case 0x0c0c0ee6u: goto P_0c0c0ee6;
case 0x0c0c0ee8u: goto P_0c0c0ee8;
case 0x0c0c0eeau: goto P_0c0c0eea;
case 0x0c0c0eecu: goto P_0c0c0eec;
case 0x0c0c0eeeu: goto P_0c0c0eee;
case 0x0c0c0ef0u: goto P_0c0c0ef0;
case 0x0c0c0ef2u: goto P_0c0c0ef2;
case 0x0c0c0ef4u: goto P_0c0c0ef4;
case 0x0c0c0ef6u: goto P_0c0c0ef6;
case 0x0c0c0ef8u: goto P_0c0c0ef8;
case 0x0c0c0efau: goto P_0c0c0efa;
case 0x0c0c0efcu: goto P_0c0c0efc;
case 0x0c0c0efeu: goto P_0c0c0efe;
case 0x0c0c0f00u: goto P_0c0c0f00;
case 0x0c0c0f02u: goto P_0c0c0f02;
case 0x0c0c0f04u: goto P_0c0c0f04;
case 0x0c0c0f06u: goto P_0c0c0f06;
case 0x0c0c0f08u: goto P_0c0c0f08;
case 0x0c0c0f0au: goto P_0c0c0f0a;
case 0x0c0c0f0cu: goto P_0c0c0f0c;
case 0x0c0c0f0eu: goto P_0c0c0f0e;
case 0x0c0c0f10u: goto P_0c0c0f10;
case 0x0c0c0f12u: goto P_0c0c0f12;
case 0x0c0c0f14u: goto P_0c0c0f14;
case 0x0c0c0f16u: goto P_0c0c0f16;
case 0x0c0c0f18u: goto P_0c0c0f18;
case 0x0c0c0f1au: goto P_0c0c0f1a;
case 0x0c0c0f1cu: goto P_0c0c0f1c;
case 0x0c0c0f1eu: goto P_0c0c0f1e;
case 0x0c0c0f20u: goto P_0c0c0f20;
case 0x0c0c0f22u: goto P_0c0c0f22;
case 0x0c0c0f24u: goto P_0c0c0f24;
case 0x0c0c0f26u: goto P_0c0c0f26;
case 0x0c0c0f28u: goto P_0c0c0f28;
case 0x0c0c0f2au: goto P_0c0c0f2a;
case 0x0c0c0f2cu: goto P_0c0c0f2c;
case 0x0c0c0f2eu: goto P_0c0c0f2e;
case 0x0c0c0f30u: goto P_0c0c0f30;
case 0x0c0c0f32u: goto P_0c0c0f32;
case 0x0c0c0f34u: goto P_0c0c0f34;
case 0x0c0c0f36u: goto P_0c0c0f36;
case 0x0c0c0f38u: goto P_0c0c0f38;
case 0x0c0c0f3au: goto P_0c0c0f3a;
case 0x0c0c0f3cu: goto P_0c0c0f3c;
case 0x0c0c0f3eu: goto P_0c0c0f3e;
case 0x0c0c0f40u: goto P_0c0c0f40;
case 0x0c0c0f42u: goto P_0c0c0f42;
case 0x0c0c0f44u: goto P_0c0c0f44;
case 0x0c0c0f46u: goto P_0c0c0f46;
case 0x0c0c0f48u: goto P_0c0c0f48;
case 0x0c0c0f4au: goto P_0c0c0f4a;
case 0x0c0c0f4cu: goto P_0c0c0f4c;
case 0x0c0c0f4eu: goto P_0c0c0f4e;
case 0x0c0c0f50u: goto P_0c0c0f50;
case 0x0c0c0f52u: goto P_0c0c0f52;
case 0x0c0c0f60u: goto P_0c0c0f60;
case 0x0c0c0f62u: goto P_0c0c0f62;
case 0x0c0c0f64u: goto P_0c0c0f64;
case 0x0c0c0f66u: goto P_0c0c0f66;
case 0x0c0c0f68u: goto P_0c0c0f68;
case 0x0c0c0f6au: goto P_0c0c0f6a;
case 0x0c0c0f6cu: goto P_0c0c0f6c;
case 0x0c0c0f6eu: goto P_0c0c0f6e;
case 0x0c0c0f70u: goto P_0c0c0f70;
case 0x0c0c0f72u: goto P_0c0c0f72;
case 0x0c0c0f74u: goto P_0c0c0f74;
case 0x0c0c0f76u: goto P_0c0c0f76;
case 0x0c0c0f78u: goto P_0c0c0f78;
case 0x0c0c0f7au: goto P_0c0c0f7a;
case 0x0c0c0f7cu: goto P_0c0c0f7c;
case 0x0c0c0f7eu: goto P_0c0c0f7e;
case 0x0c0c0f80u: goto P_0c0c0f80;
case 0x0c0c0f82u: goto P_0c0c0f82;
case 0x0c0c0f84u: goto P_0c0c0f84;
case 0x0c0c0f86u: goto P_0c0c0f86;
case 0x0c0c0f88u: goto P_0c0c0f88;
case 0x0c0c0f8au: goto P_0c0c0f8a;
case 0x0c0c0f8cu: goto P_0c0c0f8c;
case 0x0c0c0f8eu: goto P_0c0c0f8e;
case 0x0c0c0f90u: goto P_0c0c0f90;
case 0x0c0c0f92u: goto P_0c0c0f92;
case 0x0c0c0f94u: goto P_0c0c0f94;
case 0x0c0c0f96u: goto P_0c0c0f96;
case 0x0c0c0f98u: goto P_0c0c0f98;
case 0x0c0c0f9au: goto P_0c0c0f9a;
case 0x0c0c0f9cu: goto P_0c0c0f9c;
case 0x0c0c0f9eu: goto P_0c0c0f9e;
case 0x0c0c0fa0u: goto P_0c0c0fa0;
case 0x0c0c0fa2u: goto P_0c0c0fa2;
case 0x0c0c0fa4u: goto P_0c0c0fa4;
case 0x0c0c0fa6u: goto P_0c0c0fa6;
case 0x0c0c0fa8u: goto P_0c0c0fa8;
case 0x0c0c0faau: goto P_0c0c0faa;
case 0x0c0c0facu: goto P_0c0c0fac;
case 0x0c0c0faeu: goto P_0c0c0fae;
case 0x0c0c0fb0u: goto P_0c0c0fb0;
case 0x0c0c0fb2u: goto P_0c0c0fb2;
case 0x0c0c0fb4u: goto P_0c0c0fb4;
case 0x0c0c0fb6u: goto P_0c0c0fb6;
case 0x0c0c0fb8u: goto P_0c0c0fb8;
case 0x0c0c0fbau: goto P_0c0c0fba;
case 0x0c0c0fbcu: goto P_0c0c0fbc;
case 0x0c0c0fbeu: goto P_0c0c0fbe;
case 0x0c0c0fc0u: goto P_0c0c0fc0;
case 0x0c0c0fc2u: goto P_0c0c0fc2;
case 0x0c0c0fc4u: goto P_0c0c0fc4;
case 0x0c0c0fc6u: goto P_0c0c0fc6;
case 0x0c0c0fc8u: goto P_0c0c0fc8;
case 0x0c0c0fcau: goto P_0c0c0fca;
case 0x0c0c0fccu: goto P_0c0c0fcc;
case 0x0c0c0fceu: goto P_0c0c0fce;
case 0x0c0c0fd0u: goto P_0c0c0fd0;
case 0x0c0c0fd2u: goto P_0c0c0fd2;
case 0x0c0c0fd4u: goto P_0c0c0fd4;
case 0x0c0c0fd6u: goto P_0c0c0fd6;
case 0x0c0c0fd8u: goto P_0c0c0fd8;
case 0x0c0c0fdau: goto P_0c0c0fda;
case 0x0c0c0fdcu: goto P_0c0c0fdc;
case 0x0c0c0fdeu: goto P_0c0c0fde;
case 0x0c0c0fe0u: goto P_0c0c0fe0;
case 0x0c0c0fe2u: goto P_0c0c0fe2;
case 0x0c0c0fe4u: goto P_0c0c0fe4;
case 0x0c0c0fe6u: goto P_0c0c0fe6;
case 0x0c0c0fe8u: goto P_0c0c0fe8;
case 0x0c0c0feau: goto P_0c0c0fea;
case 0x0c0c0fecu: goto P_0c0c0fec;
case 0x0c0c0feeu: goto P_0c0c0fee;
case 0x0c0c0ff0u: goto P_0c0c0ff0;
case 0x0c0c0ff2u: goto P_0c0c0ff2;
case 0x0c0c0ff4u: goto P_0c0c0ff4;
case 0x0c0c0ff6u: goto P_0c0c0ff6;
case 0x0c0c0ff8u: goto P_0c0c0ff8;
case 0x0c0c0ffau: goto P_0c0c0ffa;
case 0x0c0c0ffcu: goto P_0c0c0ffc;
case 0x0c0c0ffeu: goto P_0c0c0ffe;
case 0x0c0c1000u: goto P_0c0c1000;
case 0x0c0c1002u: goto P_0c0c1002;
case 0x0c0c1004u: goto P_0c0c1004;
case 0x0c0c1006u: goto P_0c0c1006;
case 0x0c0c1008u: goto P_0c0c1008;
case 0x0c0c100au: goto P_0c0c100a;
case 0x0c0c100cu: goto P_0c0c100c;
case 0x0c0c100eu: goto P_0c0c100e;
case 0x0c0c1010u: goto P_0c0c1010;
case 0x0c0c1012u: goto P_0c0c1012;
case 0x0c0c1014u: goto P_0c0c1014;
case 0x0c0c1016u: goto P_0c0c1016;
case 0x0c0c1018u: goto P_0c0c1018;
case 0x0c0c101au: goto P_0c0c101a;
case 0x0c0c101cu: goto P_0c0c101c;
case 0x0c0c101eu: goto P_0c0c101e;
case 0x0c0c1020u: goto P_0c0c1020;
case 0x0c0c1022u: goto P_0c0c1022;
case 0x0c0c1024u: goto P_0c0c1024;
case 0x0c0c1026u: goto P_0c0c1026;
case 0x0c0c1028u: goto P_0c0c1028;
case 0x0c0c102au: goto P_0c0c102a;
case 0x0c0c102cu: goto P_0c0c102c;
case 0x0c0c102eu: goto P_0c0c102e;
case 0x0c0c1030u: goto P_0c0c1030;
case 0x0c0c1032u: goto P_0c0c1032;
case 0x0c0c1034u: goto P_0c0c1034;
case 0x0c0c1036u: goto P_0c0c1036;
case 0x0c0c1038u: goto P_0c0c1038;
case 0x0c0c103au: goto P_0c0c103a;
case 0x0c0c103cu: goto P_0c0c103c;
case 0x0c0c103eu: goto P_0c0c103e;
case 0x0c0c1040u: goto P_0c0c1040;
case 0x0c0c1042u: goto P_0c0c1042;
case 0x0c0c1044u: goto P_0c0c1044;
case 0x0c0c1046u: goto P_0c0c1046;
case 0x0c0c1048u: goto P_0c0c1048;
case 0x0c0c104au: goto P_0c0c104a;
case 0x0c0c104cu: goto P_0c0c104c;
case 0x0c0c104eu: goto P_0c0c104e;
case 0x0c0c1050u: goto P_0c0c1050;
case 0x0c0c1052u: goto P_0c0c1052;
case 0x0c0c1054u: goto P_0c0c1054;
case 0x0c0c1056u: goto P_0c0c1056;
case 0x0c0c1058u: goto P_0c0c1058;
case 0x0c0c105au: goto P_0c0c105a;
case 0x0c0c105cu: goto P_0c0c105c;
case 0x0c0c105eu: goto P_0c0c105e;
case 0x0c0c1060u: goto P_0c0c1060;
case 0x0c0c1062u: goto P_0c0c1062;
case 0x0c0c1064u: goto P_0c0c1064;
case 0x0c0c1066u: goto P_0c0c1066;
case 0x0c0c1068u: goto P_0c0c1068;
case 0x0c0c106au: goto P_0c0c106a;
case 0x0c0c106cu: goto P_0c0c106c;
case 0x0c0c106eu: goto P_0c0c106e;
case 0x0c0c1070u: goto P_0c0c1070;
case 0x0c0c1072u: goto P_0c0c1072;
case 0x0c0c1074u: goto P_0c0c1074;
case 0x0c0c1076u: goto P_0c0c1076;
case 0x0c0c1078u: goto P_0c0c1078;
case 0x0c0c107au: goto P_0c0c107a;
case 0x0c0c107cu: goto P_0c0c107c;
case 0x0c0c107eu: goto P_0c0c107e;
case 0x0c0c1080u: goto P_0c0c1080;
case 0x0c0c1082u: goto P_0c0c1082;
default: return vf3_matrix_family(target,s,ram);
}
P_0c0c0eba: /* original 2fe6, guest PC 0x0c0c0eba */
if(!s->budget--) { s->failed_pc=0x0c0c0ebau; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c0ebc;
P_0c0c0ebc: /* original ee00, guest PC 0x0c0c0ebc */
if(!s->budget--) { s->failed_pc=0x0c0c0ebcu; return 0; }
r[14]=0x00000000u;
goto P_0c0c0ebe;
P_0c0c0ebe: /* original 2fd6, guest PC 0x0c0c0ebe */
if(!s->budget--) { s->failed_pc=0x0c0c0ebeu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c0ec0;
P_0c0c0ec0: /* original 2fc6, guest PC 0x0c0c0ec0 */
if(!s->budget--) { s->failed_pc=0x0c0c0ec0u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c0ec2;
P_0c0c0ec2: /* original 6ce3, guest PC 0x0c0c0ec2 */
if(!s->budget--) { s->failed_pc=0x0c0c0ec2u; return 0; }
r[12]=r[14];
goto P_0c0c0ec4;
P_0c0c0ec4: /* original 2fb6, guest PC 0x0c0c0ec4 */
if(!s->budget--) { s->failed_pc=0x0c0c0ec4u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c0ec6;
P_0c0c0ec6: /* original 4f22, guest PC 0x0c0c0ec6 */
if(!s->budget--) { s->failed_pc=0x0c0c0ec6u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0c0ec8;
P_0c0c0ec8: /* original 7ff4, guest PC 0x0c0c0ec8 */
if(!s->budget--) { s->failed_pc=0x0c0c0ec8u; return 0; }
r[15]+=0xfffffff4u;
goto P_0c0c0eca;
P_0c0c0eca: /* original 1f41, guest PC 0x0c0c0eca */
if(!s->budget--) { s->failed_pc=0x0c0c0ecau; return 0; }
write(ram,r[15]+4,r[4],4);
goto P_0c0c0ecc;
P_0c0c0ecc: /* original 2f52, guest PC 0x0c0c0ecc */
if(!s->budget--) { s->failed_pc=0x0c0c0eccu; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0c0ece;
P_0c0c0ece: /* original 6de3, guest PC 0x0c0c0ece */
if(!s->budget--) { s->failed_pc=0x0c0c0eceu; return 0; }
r[13]=r[14];
goto P_0c0c0ed0;
P_0c0c0ed0: /* original 50f1, guest PC 0x0c0c0ed0 */
if(!s->budget--) { s->failed_pc=0x0c0c0ed0u; return 0; }
r[0]=read(ram,r[15]+4,4);
goto P_0c0c0ed2;
P_0c0c0ed2: /* original 64c3, guest PC 0x0c0c0ed2 */
if(!s->budget--) { s->failed_pc=0x0c0c0ed2u; return 0; }
r[4]=r[12];
goto P_0c0c0ed4;
P_0c0c0ed4: /* original 63f2, guest PC 0x0c0c0ed4 */
if(!s->budget--) { s->failed_pc=0x0c0c0ed4u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c0c0ed6;
P_0c0c0ed6: /* original 4408, guest PC 0x0c0c0ed6 */
if(!s->budget--) { s->failed_pc=0x0c0c0ed6u; return 0; }
r[4]<<=2;
goto P_0c0c0ed8;
P_0c0c0ed8: /* original 6b03, guest PC 0x0c0c0ed8 */
if(!s->budget--) { s->failed_pc=0x0c0c0ed8u; return 0; }
r[11]=r[0];
goto P_0c0c0eda;
P_0c0c0eda: /* original 4408, guest PC 0x0c0c0eda */
if(!s->budget--) { s->failed_pc=0x0c0c0edau; return 0; }
r[4]<<=2;
goto P_0c0c0edc;
P_0c0c0edc: /* original 7b10, guest PC 0x0c0c0edc */
if(!s->budget--) { s->failed_pc=0x0c0c0edcu; return 0; }
r[11]+=0x00000010u;
goto P_0c0c0ede;
P_0c0c0ede: /* original 5231, guest PC 0x0c0c0ede */
if(!s->budget--) { s->failed_pc=0x0c0c0edeu; return 0; }
r[2]=read(ram,r[3]+4,4);
goto P_0c0c0ee0;
P_0c0c0ee0: /* original 4400, guest PC 0x0c0c0ee0 */
if(!s->budget--) { s->failed_pc=0x0c0c0ee0u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c0c0ee2;
P_0c0c0ee2: /* original 3bdc, guest PC 0x0c0c0ee2 */
if(!s->budget--) { s->failed_pc=0x0c0c0ee2u; return 0; }
r[11]+=r[13];
goto P_0c0c0ee4;
P_0c0c0ee4: /* original 342c, guest PC 0x0c0c0ee4 */
if(!s->budget--) { s->failed_pc=0x0c0c0ee4u; return 0; }
r[4]+=r[2];
goto P_0c0c0ee6;
P_0c0c0ee6: /* original 6bb0, guest PC 0x0c0c0ee6 */
if(!s->budget--) { s->failed_pc=0x0c0c0ee6u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[11],1);
r[11]=tmp;
goto P_0c0c0ee8;
P_0c0c0ee8: /* original 1f42, guest PC 0x0c0c0ee8 */
if(!s->budget--) { s->failed_pc=0x0c0c0ee8u; return 0; }
write(ram,r[15]+8,r[4],4);
goto P_0c0c0eea;
P_0c0c0eea: /* original d31c, guest PC 0x0c0c0eea */
if(!s->budget--) { s->failed_pc=0x0c0c0eeau; return 0; }
r[3]=read(ram,0x0c0c0f5cu,4);
goto P_0c0c0eec;
P_0c0c0eec: /* original 430b, guest PC 0x0c0c0eec */
if(!s->budget--) { s->failed_pc=0x0c0c0eecu; return 0; }
target=r[3];
r[16]=code_base|0x0c0c0ef0u;
r[4]+=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c0ef0u) { target=s->pc; goto dispatch; }
goto P_0c0c0ef0;
P_0c0c0eee: /* original 34dc, guest PC 0x0c0c0eee */
if(!s->budget--) { s->failed_pc=0x0c0c0eeeu; return 0; }
r[4]+=r[13];
goto P_0c0c0ef0;
P_0c0c0ef0: /* original 660c, guest PC 0x0c0c0ef0 */
if(!s->budget--) { s->failed_pc=0x0c0c0ef0u; return 0; }
r[6]=r[0]&255u;
goto P_0c0c0ef2;
P_0c0c0ef2: /* original 36b0, guest PC 0x0c0c0ef2 */
if(!s->budget--) { s->failed_pc=0x0c0c0ef2u; return 0; }
r[17]=(r[17]&~1u)|((r[6]==r[11])!=0);
goto P_0c0c0ef4;
P_0c0c0ef4: /* original 8f02, guest PC 0x0c0c0ef4 */
if(!s->budget--) { s->failed_pc=0x0c0c0ef4u; return 0; }
cond=r[17]&1u;
r[5]=0x00000001u;
if(!cond) { goto P_0c0c0efc; }
goto P_0c0c0ef8;
P_0c0c0ef6: /* original e501, guest PC 0x0c0c0ef6 */
if(!s->budget--) { s->failed_pc=0x0c0c0ef6u; return 0; }
r[5]=0x00000001u;
goto P_0c0c0ef8;
P_0c0c0ef8: /* original a001, guest PC 0x0c0c0ef8 */
if(!s->budget--) { s->failed_pc=0x0c0c0ef8u; return 0; }
r[7]=r[14];
goto P_0c0c0efe;
P_0c0c0efa: /* original 67e3, guest PC 0x0c0c0efa */
if(!s->budget--) { s->failed_pc=0x0c0c0efau; return 0; }
r[7]=r[14];
goto P_0c0c0efc;
P_0c0c0efc: /* original 6753, guest PC 0x0c0c0efc */
if(!s->budget--) { s->failed_pc=0x0c0c0efcu; return 0; }
r[7]=r[5];
goto P_0c0c0efe;
P_0c0c0efe: /* original 922a, guest PC 0x0c0c0efe */
if(!s->budget--) { s->failed_pc=0x0c0c0efeu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c0f56u,2);
goto P_0c0c0f00;
P_0c0c0f00: /* original 3b20, guest PC 0x0c0c0f00 */
if(!s->budget--) { s->failed_pc=0x0c0c0f00u; return 0; }
r[17]=(r[17]&~1u)|((r[11]==r[2])!=0);
goto P_0c0c0f02;
P_0c0c0f02: /* original 8b01, guest PC 0x0c0c0f02 */
if(!s->budget--) { s->failed_pc=0x0c0c0f02u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c0f08; }
goto P_0c0c0f04;
P_0c0c0f04: /* original a001, guest PC 0x0c0c0f04 */
if(!s->budget--) { s->failed_pc=0x0c0c0f04u; return 0; }
r[4]=r[14];
goto P_0c0c0f0a;
P_0c0c0f06: /* original 64e3, guest PC 0x0c0c0f06 */
if(!s->budget--) { s->failed_pc=0x0c0c0f06u; return 0; }
r[4]=r[14];
goto P_0c0c0f08;
P_0c0c0f08: /* original 6453, guest PC 0x0c0c0f08 */
if(!s->budget--) { s->failed_pc=0x0c0c0f08u; return 0; }
r[4]=r[5];
goto P_0c0c0f0a;
P_0c0c0f0a: /* original 9324, guest PC 0x0c0c0f0a */
if(!s->budget--) { s->failed_pc=0x0c0c0f0au; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c0f56u,2);
goto P_0c0c0f0c;
P_0c0c0f0c: /* original 3630, guest PC 0x0c0c0f0c */
if(!s->budget--) { s->failed_pc=0x0c0c0f0cu; return 0; }
r[17]=(r[17]&~1u)|((r[6]==r[3])!=0);
goto P_0c0c0f0e;
P_0c0c0f0e: /* original 8b01, guest PC 0x0c0c0f0e */
if(!s->budget--) { s->failed_pc=0x0c0c0f0eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c0f14; }
goto P_0c0c0f10;
P_0c0c0f10: /* original a001, guest PC 0x0c0c0f10 */
if(!s->budget--) { s->failed_pc=0x0c0c0f10u; return 0; }
r[6]=r[14];
goto P_0c0c0f16;
P_0c0c0f12: /* original 66e3, guest PC 0x0c0c0f12 */
if(!s->budget--) { s->failed_pc=0x0c0c0f12u; return 0; }
r[6]=r[14];
goto P_0c0c0f14;
P_0c0c0f14: /* original 6653, guest PC 0x0c0c0f14 */
if(!s->budget--) { s->failed_pc=0x0c0c0f14u; return 0; }
r[6]=r[5];
goto P_0c0c0f16;
P_0c0c0f16: /* original 2778, guest PC 0x0c0c0f16 */
if(!s->budget--) { s->failed_pc=0x0c0c0f16u; return 0; }
r[17]=(r[17]&~1u)|(((r[7]&r[7])==0)!=0);
goto P_0c0c0f18;
P_0c0c0f18: /* original 8b08, guest PC 0x0c0c0f18 */
if(!s->budget--) { s->failed_pc=0x0c0c0f18u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c0f2c; }
goto P_0c0c0f1a;
P_0c0c0f1a: /* original 2448, guest PC 0x0c0c0f1a */
if(!s->budget--) { s->failed_pc=0x0c0c0f1au; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c0c0f1c;
P_0c0c0f1c: /* original 8904, guest PC 0x0c0c0f1c */
if(!s->budget--) { s->failed_pc=0x0c0c0f1cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c0f28; }
goto P_0c0c0f1e;
P_0c0c0f1e: /* original e304, guest PC 0x0c0c0f1e */
if(!s->budget--) { s->failed_pc=0x0c0c0f1eu; return 0; }
r[3]=0x00000004u;
goto P_0c0c0f20;
P_0c0c0f20: /* original 64d3, guest PC 0x0c0c0f20 */
if(!s->budget--) { s->failed_pc=0x0c0c0f20u; return 0; }
r[4]=r[13];
goto P_0c0c0f22;
P_0c0c0f22: /* original 3433, guest PC 0x0c0c0f22 */
if(!s->budget--) { s->failed_pc=0x0c0c0f22u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=(int32_t)r[3])!=0);
goto P_0c0c0f24;
P_0c0c0f24: /* original 8fd4, guest PC 0x0c0c0f24 */
if(!s->budget--) { s->failed_pc=0x0c0c0f24u; return 0; }
cond=r[17]&1u;
r[13]+=0x00000001u;
if(!cond) { goto P_0c0c0ed0; }
goto P_0c0c0f28;
P_0c0c0f26: /* original 7d01, guest PC 0x0c0c0f26 */
if(!s->budget--) { s->failed_pc=0x0c0c0f26u; return 0; }
r[13]+=0x00000001u;
goto P_0c0c0f28;
P_0c0c0f28: /* original a00d, guest PC 0x0c0c0f28 */
if(!s->budget--) { s->failed_pc=0x0c0c0f28u; return 0; }
r[0]=0x00000000u;
goto P_0c0c0f46;
P_0c0c0f2a: /* original e000, guest PC 0x0c0c0f2a */
if(!s->budget--) { s->failed_pc=0x0c0c0f2au; return 0; }
r[0]=0x00000000u;
goto P_0c0c0f2c;
P_0c0c0f2c: /* original 2448, guest PC 0x0c0c0f2c */
if(!s->budget--) { s->failed_pc=0x0c0c0f2cu; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c0c0f2e;
P_0c0c0f2e: /* original 8901, guest PC 0x0c0c0f2e */
if(!s->budget--) { s->failed_pc=0x0c0c0f2eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c0f34; }
goto P_0c0c0f30;
P_0c0c0f30: /* original 2668, guest PC 0x0c0c0f30 */
if(!s->budget--) { s->failed_pc=0x0c0c0f30u; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[6])==0)!=0);
goto P_0c0c0f32;
P_0c0c0f32: /* original 8b01, guest PC 0x0c0c0f32 */
if(!s->budget--) { s->failed_pc=0x0c0c0f32u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c0f38; }
goto P_0c0c0f34;
P_0c0c0f34: /* original a007, guest PC 0x0c0c0f34 */
if(!s->budget--) { s->failed_pc=0x0c0c0f34u; return 0; }
r[0]=0x00000001u;
goto P_0c0c0f46;
P_0c0c0f36: /* original e001, guest PC 0x0c0c0f36 */
if(!s->budget--) { s->failed_pc=0x0c0c0f36u; return 0; }
r[0]=0x00000001u;
goto P_0c0c0f38;
P_0c0c0f38: /* original e27f, guest PC 0x0c0c0f38 */
if(!s->budget--) { s->failed_pc=0x0c0c0f38u; return 0; }
r[2]=0x0000007fu;
goto P_0c0c0f3a;
P_0c0c0f3a: /* original 3c23, guest PC 0x0c0c0f3a */
if(!s->budget--) { s->failed_pc=0x0c0c0f3au; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[12]>=(int32_t)r[2])!=0);
goto P_0c0c0f3c;
P_0c0c0f3c: /* original 8901, guest PC 0x0c0c0f3c */
if(!s->budget--) { s->failed_pc=0x0c0c0f3cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c0f42; }
goto P_0c0c0f3e;
P_0c0c0f3e: /* original afc6, guest PC 0x0c0c0f3e */
if(!s->budget--) { s->failed_pc=0x0c0c0f3eu; return 0; }
r[12]+=0x00000001u;
goto P_0c0c0ece;
P_0c0c0f40: /* original 7c01, guest PC 0x0c0c0f40 */
if(!s->budget--) { s->failed_pc=0x0c0c0f40u; return 0; }
r[12]+=0x00000001u;
goto P_0c0c0f42;
P_0c0c0f42: /* original 60c3, guest PC 0x0c0c0f42 */
if(!s->budget--) { s->failed_pc=0x0c0c0f42u; return 0; }
r[0]=r[12];
goto P_0c0c0f44;
P_0c0c0f44: /* original 7081, guest PC 0x0c0c0f44 */
if(!s->budget--) { s->failed_pc=0x0c0c0f44u; return 0; }
r[0]+=0xffffff81u;
goto P_0c0c0f46;
P_0c0c0f46: /* original 7f0c, guest PC 0x0c0c0f46 */
if(!s->budget--) { s->failed_pc=0x0c0c0f46u; return 0; }
r[15]+=0x0000000cu;
goto P_0c0c0f48;
P_0c0c0f48: /* original 4f26, guest PC 0x0c0c0f48 */
if(!s->budget--) { s->failed_pc=0x0c0c0f48u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0c0f4a;
P_0c0c0f4a: /* original 6bf6, guest PC 0x0c0c0f4a */
if(!s->budget--) { s->failed_pc=0x0c0c0f4au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0c0f4c;
P_0c0c0f4c: /* original 6cf6, guest PC 0x0c0c0f4c */
if(!s->budget--) { s->failed_pc=0x0c0c0f4cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0c0f4e;
P_0c0c0f4e: /* original 6df6, guest PC 0x0c0c0f4e */
if(!s->budget--) { s->failed_pc=0x0c0c0f4eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0c0f50;
P_0c0c0f50: /* original 000b, guest PC 0x0c0c0f50 */
if(!s->budget--) { s->failed_pc=0x0c0c0f50u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0c0f52: /* original 6ef6, guest PC 0x0c0c0f52 */
if(!s->budget--) { s->failed_pc=0x0c0c0f52u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0c0f54u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0c0f54u; return 0; } return 1;
P_0c0c0f60: /* original 2fe6, guest PC 0x0c0c0f60 */
if(!s->budget--) { s->failed_pc=0x0c0c0f60u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c0f62;
P_0c0c0f62: /* original e302, guest PC 0x0c0c0f62 */
if(!s->budget--) { s->failed_pc=0x0c0c0f62u; return 0; }
r[3]=0x00000002u;
goto P_0c0c0f64;
P_0c0c0f64: /* original 2fd6, guest PC 0x0c0c0f64 */
if(!s->budget--) { s->failed_pc=0x0c0c0f64u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c0f66;
P_0c0c0f66: /* original 2fc6, guest PC 0x0c0c0f66 */
if(!s->budget--) { s->failed_pc=0x0c0c0f66u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c0f68;
P_0c0c0f68: /* original 2fb6, guest PC 0x0c0c0f68 */
if(!s->budget--) { s->failed_pc=0x0c0c0f68u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c0f6a;
P_0c0c0f6a: /* original 2fa6, guest PC 0x0c0c0f6a */
if(!s->budget--) { s->failed_pc=0x0c0c0f6au; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c0f6c;
P_0c0c0f6c: /* original 2f96, guest PC 0x0c0c0f6c */
if(!s->budget--) { s->failed_pc=0x0c0c0f6cu; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c0f6e;
P_0c0c0f6e: /* original 2f86, guest PC 0x0c0c0f6e */
if(!s->budget--) { s->failed_pc=0x0c0c0f6eu; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c0f70;
P_0c0c0f70: /* original 4f22, guest PC 0x0c0c0f70 */
if(!s->budget--) { s->failed_pc=0x0c0c0f70u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0c0f72;
P_0c0c0f72: /* original 4f12, guest PC 0x0c0c0f72 */
if(!s->budget--) { s->failed_pc=0x0c0c0f72u; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c0c0f74;
P_0c0c0f74: /* original 7ff4, guest PC 0x0c0c0f74 */
if(!s->budget--) { s->failed_pc=0x0c0c0f74u; return 0; }
r[15]+=0xfffffff4u;
goto P_0c0c0f76;
P_0c0c0f76: /* original 1f41, guest PC 0x0c0c0f76 */
if(!s->budget--) { s->failed_pc=0x0c0c0f76u; return 0; }
write(ram,r[15]+4,r[4],4);
goto P_0c0c0f78;
P_0c0c0f78: /* original 6453, guest PC 0x0c0c0f78 */
if(!s->budget--) { s->failed_pc=0x0c0c0f78u; return 0; }
r[4]=r[5];
goto P_0c0c0f7a;
P_0c0c0f7a: /* original 2f52, guest PC 0x0c0c0f7a */
if(!s->budget--) { s->failed_pc=0x0c0c0f7au; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0c0f7c;
P_0c0c0f7c: /* original 544b, guest PC 0x0c0c0f7c */
if(!s->budget--) { s->failed_pc=0x0c0c0f7cu; return 0; }
r[4]=read(ram,r[4]+44,4);
goto P_0c0c0f7e;
P_0c0c0f7e: /* original db44, guest PC 0x0c0c0f7e */
if(!s->budget--) { s->failed_pc=0x0c0c0f7eu; return 0; }
r[11]=read(ram,0x0c0c1090u,4);
goto P_0c0c0f80;
P_0c0c0f80: /* original 6442, guest PC 0x0c0c0f80 */
if(!s->budget--) { s->failed_pc=0x0c0c0f80u; return 0; }
tmp=read(ram,r[4],4);
r[4]=tmp;
goto P_0c0c0f82;
P_0c0c0f82: /* original 2438, guest PC 0x0c0c0f82 */
if(!s->budget--) { s->failed_pc=0x0c0c0f82u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[3])==0)!=0);
goto P_0c0c0f84;
P_0c0c0f84: /* original 8926, guest PC 0x0c0c0f84 */
if(!s->budget--) { s->failed_pc=0x0c0c0f84u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c0fd4; }
goto P_0c0c0f86;
P_0c0c0f86: /* original e304, guest PC 0x0c0c0f86 */
if(!s->budget--) { s->failed_pc=0x0c0c0f86u; return 0; }
r[3]=0x00000004u;
goto P_0c0c0f88;
P_0c0c0f88: /* original 997e, guest PC 0x0c0c0f88 */
if(!s->budget--) { s->failed_pc=0x0c0c0f88u; return 0; }
r[9]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c1088u,2);
goto P_0c0c0f8a;
P_0c0c0f8a: /* original ee00, guest PC 0x0c0c0f8a */
if(!s->budget--) { s->failed_pc=0x0c0c0f8au; return 0; }
r[14]=0x00000000u;
goto P_0c0c0f8c;
P_0c0c0f8c: /* original 1f32, guest PC 0x0c0c0f8c */
if(!s->budget--) { s->failed_pc=0x0c0c0f8cu; return 0; }
write(ram,r[15]+8,r[3],4);
goto P_0c0c0f8e;
P_0c0c0f8e: /* original 9c7c, guest PC 0x0c0c0f8e */
if(!s->budget--) { s->failed_pc=0x0c0c0f8eu; return 0; }
r[12]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c108au,2);
goto P_0c0c0f90;
P_0c0c0f90: /* original ed00, guest PC 0x0c0c0f90 */
if(!s->budget--) { s->failed_pc=0x0c0c0f90u; return 0; }
r[13]=0x00000000u;
goto P_0c0c0f92;
P_0c0c0f92: /* original 68f2, guest PC 0x0c0c0f92 */
if(!s->budget--) { s->failed_pc=0x0c0c0f92u; return 0; }
tmp=read(ram,r[15],4);
r[8]=tmp;
goto P_0c0c0f94;
P_0c0c0f94: /* original 64e3, guest PC 0x0c0c0f94 */
if(!s->budget--) { s->failed_pc=0x0c0c0f94u; return 0; }
r[4]=r[14];
goto P_0c0c0f96;
P_0c0c0f96: /* original 4408, guest PC 0x0c0c0f96 */
if(!s->budget--) { s->failed_pc=0x0c0c0f96u; return 0; }
r[4]<<=2;
goto P_0c0c0f98;
P_0c0c0f98: /* original d33e, guest PC 0x0c0c0f98 */
if(!s->budget--) { s->failed_pc=0x0c0c0f98u; return 0; }
r[3]=read(ram,0x0c0c1094u,4);
goto P_0c0c0f9a;
P_0c0c0f9a: /* original 5881, guest PC 0x0c0c0f9a */
if(!s->budget--) { s->failed_pc=0x0c0c0f9au; return 0; }
r[8]=read(ram,r[8]+4,4);
goto P_0c0c0f9c;
P_0c0c0f9c: /* original 4408, guest PC 0x0c0c0f9c */
if(!s->budget--) { s->failed_pc=0x0c0c0f9cu; return 0; }
r[4]<<=2;
goto P_0c0c0f9e;
P_0c0c0f9e: /* original 4400, guest PC 0x0c0c0f9e */
if(!s->budget--) { s->failed_pc=0x0c0c0f9eu; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c0c0fa0;
P_0c0c0fa0: /* original 384c, guest PC 0x0c0c0fa0 */
if(!s->budget--) { s->failed_pc=0x0c0c0fa0u; return 0; }
r[8]+=r[4];
goto P_0c0c0fa2;
P_0c0c0fa2: /* original 6483, guest PC 0x0c0c0fa2 */
if(!s->budget--) { s->failed_pc=0x0c0c0fa2u; return 0; }
r[4]=r[8];
goto P_0c0c0fa4;
P_0c0c0fa4: /* original 430b, guest PC 0x0c0c0fa4 */
if(!s->budget--) { s->failed_pc=0x0c0c0fa4u; return 0; }
target=r[3];
r[16]=code_base|0x0c0c0fa8u;
r[4]+=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c0fa8u) { target=s->pc; goto dispatch; }
goto P_0c0c0fa8;
P_0c0c0fa6: /* original 34dc, guest PC 0x0c0c0fa6 */
if(!s->budget--) { s->failed_pc=0x0c0c0fa6u; return 0; }
r[4]+=r[13];
goto P_0c0c0fa8;
P_0c0c0fa8: /* original 926e, guest PC 0x0c0c0fa8 */
if(!s->budget--) { s->failed_pc=0x0c0c0fa8u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c1088u,2);
goto P_0c0c0faa;
P_0c0c0faa: /* original 640c, guest PC 0x0c0c0faa */
if(!s->budget--) { s->failed_pc=0x0c0c0faau; return 0; }
r[4]=r[0]&255u;
goto P_0c0c0fac;
P_0c0c0fac: /* original 3420, guest PC 0x0c0c0fac */
if(!s->budget--) { s->failed_pc=0x0c0c0facu; return 0; }
r[17]=(r[17]&~1u)|((r[4]==r[2])!=0);
goto P_0c0c0fae;
P_0c0c0fae: /* original 8b07, guest PC 0x0c0c0fae */
if(!s->budget--) { s->failed_pc=0x0c0c0faeu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c0fc0; }
goto P_0c0c0fb0;
P_0c0c0fb0: /* original e301, guest PC 0x0c0c0fb0 */
if(!s->budget--) { s->failed_pc=0x0c0c0fb0u; return 0; }
r[3]=0x00000001u;
goto P_0c0c0fb2;
P_0c0c0fb2: /* original 3d37, guest PC 0x0c0c0fb2 */
if(!s->budget--) { s->failed_pc=0x0c0c0fb2u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[13]>(int32_t)r[3])!=0);
goto P_0c0c0fb4;
P_0c0c0fb4: /* original 8b36, guest PC 0x0c0c0fb4 */
if(!s->budget--) { s->failed_pc=0x0c0c0fb4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c1024; }
goto P_0c0c0fb6;
P_0c0c0fb6: /* original 53f2, guest PC 0x0c0c0fb6 */
if(!s->budget--) { s->failed_pc=0x0c0c0fb6u; return 0; }
r[3]=read(ram,r[15]+8,4);
goto P_0c0c0fb8;
P_0c0c0fb8: /* original 3d33, guest PC 0x0c0c0fb8 */
if(!s->budget--) { s->failed_pc=0x0c0c0fb8u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[13]>=(int32_t)r[3])!=0);
goto P_0c0c0fba;
P_0c0c0fba: /* original 8912, guest PC 0x0c0c0fba */
if(!s->budget--) { s->failed_pc=0x0c0c0fbau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c0fe2; }
goto P_0c0c0fbc;
P_0c0c0fbc: /* original a014, guest PC 0x0c0c0fbc */
if(!s->budget--) { s->failed_pc=0x0c0c0fbcu; return 0; }
write(ram,r[15]+8,r[13],4);
goto P_0c0c0fe8;
P_0c0c0fbe: /* original 1fd2, guest PC 0x0c0c0fbe */
if(!s->budget--) { s->failed_pc=0x0c0c0fbeu; return 0; }
write(ram,r[15]+8,r[13],4);
goto P_0c0c0fc0;
P_0c0c0fc0: /* original d234, guest PC 0x0c0c0fc0 */
if(!s->budget--) { s->failed_pc=0x0c0c0fc0u; return 0; }
r[2]=read(ram,0x0c0c1094u,4);
goto P_0c0c0fc2;
P_0c0c0fc2: /* original 6483, guest PC 0x0c0c0fc2 */
if(!s->budget--) { s->failed_pc=0x0c0c0fc2u; return 0; }
r[4]=r[8];
goto P_0c0c0fc4;
P_0c0c0fc4: /* original 7405, guest PC 0x0c0c0fc4 */
if(!s->budget--) { s->failed_pc=0x0c0c0fc4u; return 0; }
r[4]+=0x00000005u;
goto P_0c0c0fc6;
P_0c0c0fc6: /* original 420b, guest PC 0x0c0c0fc6 */
if(!s->budget--) { s->failed_pc=0x0c0c0fc6u; return 0; }
target=r[2];
r[16]=code_base|0x0c0c0fcau;
r[4]+=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c0fcau) { target=s->pc; goto dispatch; }
goto P_0c0c0fca;
P_0c0c0fc8: /* original 34dc, guest PC 0x0c0c0fc8 */
if(!s->budget--) { s->failed_pc=0x0c0c0fc8u; return 0; }
r[4]+=r[13];
goto P_0c0c0fca;
P_0c0c0fca: /* original 6a0c, guest PC 0x0c0c0fca */
if(!s->budget--) { s->failed_pc=0x0c0c0fcau; return 0; }
r[10]=r[0]&255u;
goto P_0c0c0fcc;
P_0c0c0fcc: /* original 2aa8, guest PC 0x0c0c0fcc */
if(!s->budget--) { s->failed_pc=0x0c0c0fccu; return 0; }
r[17]=(r[17]&~1u)|(((r[10]&r[10])==0)!=0);
goto P_0c0c0fce;
P_0c0c0fce: /* original 8b03, guest PC 0x0c0c0fce */
if(!s->budget--) { s->failed_pc=0x0c0c0fceu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c0fd8; }
goto P_0c0c0fd0;
P_0c0c0fd0: /* original a028, guest PC 0x0c0c0fd0 */
if(!s->budget--) { s->failed_pc=0x0c0c0fd0u; return 0; }
goto P_0c0c1024;
P_0c0c0fd2: /* original 0009, guest PC 0x0c0c0fd2 */
if(!s->budget--) { s->failed_pc=0x0c0c0fd2u; return 0; }
goto P_0c0c0fd4;
P_0c0c0fd4: /* original a027, guest PC 0x0c0c0fd4 */
if(!s->budget--) { s->failed_pc=0x0c0c0fd4u; return 0; }
r[0]=0x00000000u;
goto P_0c0c1026;
P_0c0c0fd6: /* original e000, guest PC 0x0c0c0fd6 */
if(!s->budget--) { s->failed_pc=0x0c0c0fd6u; return 0; }
r[0]=0x00000000u;
goto P_0c0c0fd8;
P_0c0c0fd8: /* original e204, guest PC 0x0c0c0fd8 */
if(!s->budget--) { s->failed_pc=0x0c0c0fd8u; return 0; }
r[2]=0x00000004u;
goto P_0c0c0fda;
P_0c0c0fda: /* original 64d3, guest PC 0x0c0c0fda */
if(!s->budget--) { s->failed_pc=0x0c0c0fdau; return 0; }
r[4]=r[13];
goto P_0c0c0fdc;
P_0c0c0fdc: /* original 3423, guest PC 0x0c0c0fdc */
if(!s->budget--) { s->failed_pc=0x0c0c0fdcu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=(int32_t)r[2])!=0);
goto P_0c0c0fde;
P_0c0c0fde: /* original 8fd8, guest PC 0x0c0c0fde */
if(!s->budget--) { s->failed_pc=0x0c0c0fdeu; return 0; }
cond=r[17]&1u;
r[13]+=0x00000001u;
if(!cond) { goto P_0c0c0f92; }
goto P_0c0c0fe2;
P_0c0c0fe0: /* original 7d01, guest PC 0x0c0c0fe0 */
if(!s->budget--) { s->failed_pc=0x0c0c0fe0u; return 0; }
r[13]+=0x00000001u;
goto P_0c0c0fe2;
P_0c0c0fe2: /* original 3a93, guest PC 0x0c0c0fe2 */
if(!s->budget--) { s->failed_pc=0x0c0c0fe2u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[10]>=(int32_t)r[9])!=0);
goto P_0c0c0fe4;
P_0c0c0fe4: /* original 8901, guest PC 0x0c0c0fe4 */
if(!s->budget--) { s->failed_pc=0x0c0c0fe4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c0fea; }
goto P_0c0c0fe6;
P_0c0c0fe6: /* original 69a3, guest PC 0x0c0c0fe6 */
if(!s->budget--) { s->failed_pc=0x0c0c0fe6u; return 0; }
r[9]=r[10];
goto P_0c0c0fe8;
P_0c0c0fe8: /* original 6ce3, guest PC 0x0c0c0fe8 */
if(!s->budget--) { s->failed_pc=0x0c0c0fe8u; return 0; }
r[12]=r[14];
goto P_0c0c0fea;
P_0c0c0fea: /* original e37f, guest PC 0x0c0c0fea */
if(!s->budget--) { s->failed_pc=0x0c0c0feau; return 0; }
r[3]=0x0000007fu;
goto P_0c0c0fec;
P_0c0c0fec: /* original 64e3, guest PC 0x0c0c0fec */
if(!s->budget--) { s->failed_pc=0x0c0c0fecu; return 0; }
r[4]=r[14];
goto P_0c0c0fee;
P_0c0c0fee: /* original 3433, guest PC 0x0c0c0fee */
if(!s->budget--) { s->failed_pc=0x0c0c0feeu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=(int32_t)r[3])!=0);
goto P_0c0c0ff0;
P_0c0c0ff0: /* original 8fce, guest PC 0x0c0c0ff0 */
if(!s->budget--) { s->failed_pc=0x0c0c0ff0u; return 0; }
cond=r[17]&1u;
r[14]+=0x00000001u;
if(!cond) { goto P_0c0c0f90; }
goto P_0c0c0ff4;
P_0c0c0ff2: /* original 7e01, guest PC 0x0c0c0ff2 */
if(!s->budget--) { s->failed_pc=0x0c0c0ff2u; return 0; }
r[14]+=0x00000001u;
goto P_0c0c0ff4;
P_0c0c0ff4: /* original 9349, guest PC 0x0c0c0ff4 */
if(!s->budget--) { s->failed_pc=0x0c0c0ff4u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c108au,2);
goto P_0c0c0ff6;
P_0c0c0ff6: /* original 3c30, guest PC 0x0c0c0ff6 */
if(!s->budget--) { s->failed_pc=0x0c0c0ff6u; return 0; }
r[17]=(r[17]&~1u)|((r[12]==r[3])!=0);
goto P_0c0c0ff8;
P_0c0c0ff8: /* original 8f14, guest PC 0x0c0c0ff8 */
if(!s->budget--) { s->failed_pc=0x0c0c0ff8u; return 0; }
cond=r[17]&1u;
r[14]=r[12];
if(!cond) { goto P_0c0c1024; }
goto P_0c0c0ffc;
P_0c0c0ffa: /* original 6ec3, guest PC 0x0c0c0ffa */
if(!s->budget--) { s->failed_pc=0x0c0c0ffau; return 0; }
r[14]=r[12];
goto P_0c0c0ffc;
P_0c0c0ffc: /* original 9046, guest PC 0x0c0c0ffc */
if(!s->budget--) { s->failed_pc=0x0c0c0ffcu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c108cu,2);
goto P_0c0c0ffe;
P_0c0c0ffe: /* original 04be, guest PC 0x0c0c0ffe */
if(!s->budget--) { s->failed_pc=0x0c0c0ffeu; return 0; }
r[4]=read(ram,r[11]+r[0],4);
goto P_0c0c1000;
P_0c0c1000: /* original 7004, guest PC 0x0c0c1000 */
if(!s->budget--) { s->failed_pc=0x0c0c1000u; return 0; }
r[0]+=0x00000004u;
goto P_0c0c1002;
P_0c0c1002: /* original 03be, guest PC 0x0c0c1002 */
if(!s->budget--) { s->failed_pc=0x0c0c1002u; return 0; }
r[3]=read(ram,r[11]+r[0],4);
goto P_0c0c1004;
P_0c0c1004: /* original 7004, guest PC 0x0c0c1004 */
if(!s->budget--) { s->failed_pc=0x0c0c1004u; return 0; }
r[0]+=0x00000004u;
goto P_0c0c1006;
P_0c0c1006: /* original 02bd, guest PC 0x0c0c1006 */
if(!s->budget--) { s->failed_pc=0x0c0c1006u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,r[11]+r[0],2);
goto P_0c0c1008;
P_0c0c1008: /* original 70f8, guest PC 0x0c0c1008 */
if(!s->budget--) { s->failed_pc=0x0c0c1008u; return 0; }
r[0]+=0xfffffff8u;
goto P_0c0c100a;
P_0c0c100a: /* original 0437, guest PC 0x0c0c100a */
if(!s->budget--) { s->failed_pc=0x0c0c100au; return 0; }
r[19]=r[4]*r[3];
goto P_0c0c100c;
P_0c0c100c: /* original 041a, guest PC 0x0c0c100c */
if(!s->budget--) { s->failed_pc=0x0c0c100cu; return 0; }
r[4]=r[19];
goto P_0c0c100e;
P_0c0c100e: /* original 342c, guest PC 0x0c0c100e */
if(!s->budget--) { s->failed_pc=0x0c0c100eu; return 0; }
r[4]+=r[2];
goto P_0c0c1010;
P_0c0c1010: /* original 0b46, guest PC 0x0c0c1010 */
if(!s->budget--) { s->failed_pc=0x0c0c1010u; return 0; }
write(ram,r[11]+r[0],r[4],4);
goto P_0c0c1012;
P_0c0c1012: /* original 4429, guest PC 0x0c0c1012 */
if(!s->budget--) { s->failed_pc=0x0c0c1012u; return 0; }
r[4]>>=16;
goto P_0c0c1014;
P_0c0c1014: /* original 9e3b, guest PC 0x0c0c1014 */
if(!s->budget--) { s->failed_pc=0x0c0c1014u; return 0; }
r[14]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c108eu,2);
goto P_0c0c1016;
P_0c0c1016: /* original 644f, guest PC 0x0c0c1016 */
if(!s->budget--) { s->failed_pc=0x0c0c1016u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)r[4];
goto P_0c0c1018;
P_0c0c1018: /* original d31f, guest PC 0x0c0c1018 */
if(!s->budget--) { s->failed_pc=0x0c0c1018u; return 0; }
r[3]=read(ram,0x0c0c1098u,4);
goto P_0c0c101a;
P_0c0c101a: /* original 70d0, guest PC 0x0c0c101a */
if(!s->budget--) { s->failed_pc=0x0c0c101au; return 0; }
r[0]+=0xffffffd0u;
goto P_0c0c101c;
P_0c0c101c: /* original 2e49, guest PC 0x0c0c101c */
if(!s->budget--) { s->failed_pc=0x0c0c101cu; return 0; }
r[14]&=r[4];
goto P_0c0c101e;
P_0c0c101e: /* original 430b, guest PC 0x0c0c101e */
if(!s->budget--) { s->failed_pc=0x0c0c101eu; return 0; }
target=r[3];
r[16]=code_base|0x0c0c1022u;
r[1]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c1022u) { target=s->pc; goto dispatch; }
goto P_0c0c1022;
P_0c0c1020: /* original 61e3, guest PC 0x0c0c1020 */
if(!s->budget--) { s->failed_pc=0x0c0c1020u; return 0; }
r[1]=r[14];
goto P_0c0c1022;
P_0c0c1022: /* original 6e03, guest PC 0x0c0c1022 */
if(!s->budget--) { s->failed_pc=0x0c0c1022u; return 0; }
r[14]=r[0];
goto P_0c0c1024;
P_0c0c1024: /* original 60e3, guest PC 0x0c0c1024 */
if(!s->budget--) { s->failed_pc=0x0c0c1024u; return 0; }
r[0]=r[14];
goto P_0c0c1026;
P_0c0c1026: /* original 7f0c, guest PC 0x0c0c1026 */
if(!s->budget--) { s->failed_pc=0x0c0c1026u; return 0; }
r[15]+=0x0000000cu;
goto P_0c0c1028;
P_0c0c1028: /* original 4f16, guest PC 0x0c0c1028 */
if(!s->budget--) { s->failed_pc=0x0c0c1028u; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c0c102a;
P_0c0c102a: /* original 4f26, guest PC 0x0c0c102a */
if(!s->budget--) { s->failed_pc=0x0c0c102au; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0c102c;
P_0c0c102c: /* original 68f6, guest PC 0x0c0c102c */
if(!s->budget--) { s->failed_pc=0x0c0c102cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c0c102e;
P_0c0c102e: /* original 69f6, guest PC 0x0c0c102e */
if(!s->budget--) { s->failed_pc=0x0c0c102eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c0c1030;
P_0c0c1030: /* original 6af6, guest PC 0x0c0c1030 */
if(!s->budget--) { s->failed_pc=0x0c0c1030u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0c1032;
P_0c0c1032: /* original 6bf6, guest PC 0x0c0c1032 */
if(!s->budget--) { s->failed_pc=0x0c0c1032u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0c1034;
P_0c0c1034: /* original 6cf6, guest PC 0x0c0c1034 */
if(!s->budget--) { s->failed_pc=0x0c0c1034u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0c1036;
P_0c0c1036: /* original 6df6, guest PC 0x0c0c1036 */
if(!s->budget--) { s->failed_pc=0x0c0c1036u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0c1038;
P_0c0c1038: /* original 000b, guest PC 0x0c0c1038 */
if(!s->budget--) { s->failed_pc=0x0c0c1038u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0c103a: /* original 6ef6, guest PC 0x0c0c103a */
if(!s->budget--) { s->failed_pc=0x0c0c103au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0c103c;
P_0c0c103c: /* original e600, guest PC 0x0c0c103c */
if(!s->budget--) { s->failed_pc=0x0c0c103cu; return 0; }
r[6]=0x00000000u;
goto P_0c0c103e;
P_0c0c103e: /* original 6343, guest PC 0x0c0c103e */
if(!s->budget--) { s->failed_pc=0x0c0c103eu; return 0; }
r[3]=r[4];
goto P_0c0c1040;
P_0c0c1040: /* original 1565, guest PC 0x0c0c1040 */
if(!s->budget--) { s->failed_pc=0x0c0c1040u; return 0; }
write(ram,r[5]+20,r[6],4);
goto P_0c0c1042;
P_0c0c1042: /* original e011, guest PC 0x0c0c1042 */
if(!s->budget--) { s->failed_pc=0x0c0c1042u; return 0; }
r[0]=0x00000011u;
goto P_0c0c1044;
P_0c0c1044: /* original e5ff, guest PC 0x0c0c1044 */
if(!s->budget--) { s->failed_pc=0x0c0c1044u; return 0; }
r[5]=0xffffffffu;
goto P_0c0c1046;
P_0c0c1046: /* original 7310, guest PC 0x0c0c1046 */
if(!s->budget--) { s->failed_pc=0x0c0c1046u; return 0; }
r[3]+=0x00000010u;
goto P_0c0c1048;
P_0c0c1048: /* original 2350, guest PC 0x0c0c1048 */
if(!s->budget--) { s->failed_pc=0x0c0c1048u; return 0; }
write(ram,r[3],r[5],1);
goto P_0c0c104a;
P_0c0c104a: /* original 0454, guest PC 0x0c0c104a */
if(!s->budget--) { s->failed_pc=0x0c0c104au; return 0; }
write(ram,r[4]+r[0],r[5],1);
goto P_0c0c104c;
P_0c0c104c: /* original e012, guest PC 0x0c0c104c */
if(!s->budget--) { s->failed_pc=0x0c0c104cu; return 0; }
r[0]=0x00000012u;
goto P_0c0c104e;
P_0c0c104e: /* original 0454, guest PC 0x0c0c104e */
if(!s->budget--) { s->failed_pc=0x0c0c104eu; return 0; }
write(ram,r[4]+r[0],r[5],1);
goto P_0c0c1050;
P_0c0c1050: /* original e013, guest PC 0x0c0c1050 */
if(!s->budget--) { s->failed_pc=0x0c0c1050u; return 0; }
r[0]=0x00000013u;
goto P_0c0c1052;
P_0c0c1052: /* original 0454, guest PC 0x0c0c1052 */
if(!s->budget--) { s->failed_pc=0x0c0c1052u; return 0; }
write(ram,r[4]+r[0],r[5],1);
goto P_0c0c1054;
P_0c0c1054: /* original e014, guest PC 0x0c0c1054 */
if(!s->budget--) { s->failed_pc=0x0c0c1054u; return 0; }
r[0]=0x00000014u;
goto P_0c0c1056;
P_0c0c1056: /* original 0454, guest PC 0x0c0c1056 */
if(!s->budget--) { s->failed_pc=0x0c0c1056u; return 0; }
write(ram,r[4]+r[0],r[5],1);
goto P_0c0c1058;
P_0c0c1058: /* original 6063, guest PC 0x0c0c1058 */
if(!s->budget--) { s->failed_pc=0x0c0c1058u; return 0; }
r[0]=r[6];
goto P_0c0c105a;
P_0c0c105a: /* original 814b, guest PC 0x0c0c105a */
if(!s->budget--) { s->failed_pc=0x0c0c105au; return 0; }
write(ram,r[4]+22,r[0],2);
goto P_0c0c105c;
P_0c0c105c: /* original 814c, guest PC 0x0c0c105c */
if(!s->budget--) { s->failed_pc=0x0c0c105cu; return 0; }
write(ram,r[4]+24,r[0],2);
goto P_0c0c105e;
P_0c0c105e: /* original 814d, guest PC 0x0c0c105e */
if(!s->budget--) { s->failed_pc=0x0c0c105eu; return 0; }
write(ram,r[4]+26,r[0],2);
goto P_0c0c1060;
P_0c0c1060: /* original 814e, guest PC 0x0c0c1060 */
if(!s->budget--) { s->failed_pc=0x0c0c1060u; return 0; }
write(ram,r[4]+28,r[0],2);
goto P_0c0c1062;
P_0c0c1062: /* original 814f, guest PC 0x0c0c1062 */
if(!s->budget--) { s->failed_pc=0x0c0c1062u; return 0; }
write(ram,r[4]+30,r[0],2);
goto P_0c0c1064;
P_0c0c1064: /* original e020, guest PC 0x0c0c1064 */
if(!s->budget--) { s->failed_pc=0x0c0c1064u; return 0; }
r[0]=0x00000020u;
goto P_0c0c1066;
P_0c0c1066: /* original 0465, guest PC 0x0c0c1066 */
if(!s->budget--) { s->failed_pc=0x0c0c1066u; return 0; }
write(ram,r[4]+r[0],r[6],2);
goto P_0c0c1068;
P_0c0c1068: /* original e022, guest PC 0x0c0c1068 */
if(!s->budget--) { s->failed_pc=0x0c0c1068u; return 0; }
r[0]=0x00000022u;
goto P_0c0c106a;
P_0c0c106a: /* original 0465, guest PC 0x0c0c106a */
if(!s->budget--) { s->failed_pc=0x0c0c106au; return 0; }
write(ram,r[4]+r[0],r[6],2);
goto P_0c0c106c;
P_0c0c106c: /* original e024, guest PC 0x0c0c106c */
if(!s->budget--) { s->failed_pc=0x0c0c106cu; return 0; }
r[0]=0x00000024u;
goto P_0c0c106e;
P_0c0c106e: /* original 0465, guest PC 0x0c0c106e */
if(!s->budget--) { s->failed_pc=0x0c0c106eu; return 0; }
write(ram,r[4]+r[0],r[6],2);
goto P_0c0c1070;
P_0c0c1070: /* original e026, guest PC 0x0c0c1070 */
if(!s->budget--) { s->failed_pc=0x0c0c1070u; return 0; }
r[0]=0x00000026u;
goto P_0c0c1072;
P_0c0c1072: /* original 0465, guest PC 0x0c0c1072 */
if(!s->budget--) { s->failed_pc=0x0c0c1072u; return 0; }
write(ram,r[4]+r[0],r[6],2);
goto P_0c0c1074;
P_0c0c1074: /* original e028, guest PC 0x0c0c1074 */
if(!s->budget--) { s->failed_pc=0x0c0c1074u; return 0; }
r[0]=0x00000028u;
goto P_0c0c1076;
P_0c0c1076: /* original 0465, guest PC 0x0c0c1076 */
if(!s->budget--) { s->failed_pc=0x0c0c1076u; return 0; }
write(ram,r[4]+r[0],r[6],2);
goto P_0c0c1078;
P_0c0c1078: /* original 146b, guest PC 0x0c0c1078 */
if(!s->budget--) { s->failed_pc=0x0c0c1078u; return 0; }
write(ram,r[4]+44,r[6],4);
goto P_0c0c107a;
P_0c0c107a: /* original 146c, guest PC 0x0c0c107a */
if(!s->budget--) { s->failed_pc=0x0c0c107au; return 0; }
write(ram,r[4]+48,r[6],4);
goto P_0c0c107c;
P_0c0c107c: /* original 146d, guest PC 0x0c0c107c */
if(!s->budget--) { s->failed_pc=0x0c0c107cu; return 0; }
write(ram,r[4]+52,r[6],4);
goto P_0c0c107e;
P_0c0c107e: /* original 146e, guest PC 0x0c0c107e */
if(!s->budget--) { s->failed_pc=0x0c0c107eu; return 0; }
write(ram,r[4]+56,r[6],4);
goto P_0c0c1080;
P_0c0c1080: /* original 000b, guest PC 0x0c0c1080 */
if(!s->budget--) { s->failed_pc=0x0c0c1080u; return 0; }
target=r[16];
write(ram,r[4]+60,r[6],4);
s->pc=target; return ram->oob==0;
P_0c0c1082: /* original 146f, guest PC 0x0c0c1082 */
if(!s->budget--) { s->failed_pc=0x0c0c1082u; return 0; }
write(ram,r[4]+60,r[6],4);
if(!vf3_matrix_family(0x0c0c1084u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0c1084u; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
