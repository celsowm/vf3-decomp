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
int vf3_away_batch202_adapter_3(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c0a9e60u: goto P_0c0a9e60;
case 0x0c0a9e62u: goto P_0c0a9e62;
case 0x0c0a9e64u: goto P_0c0a9e64;
case 0x0c0a9e66u: goto P_0c0a9e66;
case 0x0c0a9e68u: goto P_0c0a9e68;
case 0x0c0a9e6au: goto P_0c0a9e6a;
case 0x0c0a9e6cu: goto P_0c0a9e6c;
case 0x0c0a9e6eu: goto P_0c0a9e6e;
case 0x0c0a9e70u: goto P_0c0a9e70;
case 0x0c0a9e72u: goto P_0c0a9e72;
case 0x0c0a9e74u: goto P_0c0a9e74;
case 0x0c0a9e76u: goto P_0c0a9e76;
case 0x0c0a9e78u: goto P_0c0a9e78;
case 0x0c0a9e7au: goto P_0c0a9e7a;
case 0x0c0a9e7cu: goto P_0c0a9e7c;
case 0x0c0a9ea4u: goto P_0c0a9ea4;
case 0x0c0a9ea6u: goto P_0c0a9ea6;
case 0x0c0a9ea8u: goto P_0c0a9ea8;
case 0x0c0a9eaau: goto P_0c0a9eaa;
case 0x0c0a9eacu: goto P_0c0a9eac;
case 0x0c0a9eaeu: goto P_0c0a9eae;
case 0x0c0a9eb0u: goto P_0c0a9eb0;
case 0x0c0a9eb2u: goto P_0c0a9eb2;
case 0x0c0a9eb4u: goto P_0c0a9eb4;
case 0x0c0a9eb6u: goto P_0c0a9eb6;
case 0x0c0a9eb8u: goto P_0c0a9eb8;
case 0x0c0a9ebau: goto P_0c0a9eba;
case 0x0c0a9ebcu: goto P_0c0a9ebc;
case 0x0c0a9ebeu: goto P_0c0a9ebe;
case 0x0c0a9ec0u: goto P_0c0a9ec0;
case 0x0c0a9ec2u: goto P_0c0a9ec2;
case 0x0c0a9ec4u: goto P_0c0a9ec4;
case 0x0c0a9ec6u: goto P_0c0a9ec6;
case 0x0c0a9ec8u: goto P_0c0a9ec8;
case 0x0c0a9ecau: goto P_0c0a9eca;
case 0x0c0a9eccu: goto P_0c0a9ecc;
case 0x0c0a9eceu: goto P_0c0a9ece;
case 0x0c0a9ed0u: goto P_0c0a9ed0;
case 0x0c0a9ed2u: goto P_0c0a9ed2;
case 0x0c0a9ed4u: goto P_0c0a9ed4;
case 0x0c0a9ed6u: goto P_0c0a9ed6;
case 0x0c0a9ed8u: goto P_0c0a9ed8;
case 0x0c0a9edau: goto P_0c0a9eda;
case 0x0c0a9edcu: goto P_0c0a9edc;
case 0x0c0a9edeu: goto P_0c0a9ede;
case 0x0c0a9ee0u: goto P_0c0a9ee0;
case 0x0c0a9ee2u: goto P_0c0a9ee2;
case 0x0c0a9ee4u: goto P_0c0a9ee4;
case 0x0c0a9ee6u: goto P_0c0a9ee6;
case 0x0c0a9ee8u: goto P_0c0a9ee8;
case 0x0c0a9eeau: goto P_0c0a9eea;
case 0x0c0a9eecu: goto P_0c0a9eec;
case 0x0c0a9eeeu: goto P_0c0a9eee;
case 0x0c0a9ef0u: goto P_0c0a9ef0;
case 0x0c0a9ef2u: goto P_0c0a9ef2;
case 0x0c0a9ef4u: goto P_0c0a9ef4;
case 0x0c0a9ef6u: goto P_0c0a9ef6;
case 0x0c0a9ef8u: goto P_0c0a9ef8;
case 0x0c0a9efau: goto P_0c0a9efa;
case 0x0c0a9efcu: goto P_0c0a9efc;
case 0x0c0a9efeu: goto P_0c0a9efe;
case 0x0c0a9f00u: goto P_0c0a9f00;
case 0x0c0a9f02u: goto P_0c0a9f02;
case 0x0c0a9f04u: goto P_0c0a9f04;
case 0x0c0a9f06u: goto P_0c0a9f06;
case 0x0c0a9f08u: goto P_0c0a9f08;
case 0x0c0a9f0au: goto P_0c0a9f0a;
case 0x0c0a9f0cu: goto P_0c0a9f0c;
case 0x0c0a9f0eu: goto P_0c0a9f0e;
case 0x0c0a9f10u: goto P_0c0a9f10;
case 0x0c0a9f12u: goto P_0c0a9f12;
case 0x0c0a9f14u: goto P_0c0a9f14;
case 0x0c0a9f16u: goto P_0c0a9f16;
case 0x0c0a9f18u: goto P_0c0a9f18;
case 0x0c0a9f1au: goto P_0c0a9f1a;
case 0x0c0a9f1cu: goto P_0c0a9f1c;
case 0x0c0a9f1eu: goto P_0c0a9f1e;
case 0x0c0a9f20u: goto P_0c0a9f20;
case 0x0c0a9f22u: goto P_0c0a9f22;
case 0x0c0a9f24u: goto P_0c0a9f24;
case 0x0c0a9f26u: goto P_0c0a9f26;
case 0x0c0a9f28u: goto P_0c0a9f28;
case 0x0c0a9f2au: goto P_0c0a9f2a;
case 0x0c0a9f2cu: goto P_0c0a9f2c;
case 0x0c0a9f2eu: goto P_0c0a9f2e;
case 0x0c0a9f30u: goto P_0c0a9f30;
case 0x0c0a9f32u: goto P_0c0a9f32;
case 0x0c0a9f34u: goto P_0c0a9f34;
case 0x0c0a9f36u: goto P_0c0a9f36;
case 0x0c0a9f38u: goto P_0c0a9f38;
case 0x0c0a9f3au: goto P_0c0a9f3a;
case 0x0c0a9f3cu: goto P_0c0a9f3c;
case 0x0c0a9f3eu: goto P_0c0a9f3e;
case 0x0c0a9f40u: goto P_0c0a9f40;
case 0x0c0a9f42u: goto P_0c0a9f42;
case 0x0c0a9f44u: goto P_0c0a9f44;
case 0x0c0a9f46u: goto P_0c0a9f46;
case 0x0c0a9f48u: goto P_0c0a9f48;
case 0x0c0a9f4au: goto P_0c0a9f4a;
case 0x0c0a9f4cu: goto P_0c0a9f4c;
case 0x0c0a9f4eu: goto P_0c0a9f4e;
case 0x0c0a9f50u: goto P_0c0a9f50;
case 0x0c0a9f52u: goto P_0c0a9f52;
case 0x0c0a9f54u: goto P_0c0a9f54;
case 0x0c0a9f56u: goto P_0c0a9f56;
case 0x0c0a9f58u: goto P_0c0a9f58;
case 0x0c0a9f5au: goto P_0c0a9f5a;
case 0x0c0a9f5cu: goto P_0c0a9f5c;
case 0x0c0a9f5eu: goto P_0c0a9f5e;
case 0x0c0a9f60u: goto P_0c0a9f60;
case 0x0c0a9f62u: goto P_0c0a9f62;
case 0x0c0a9f64u: goto P_0c0a9f64;
case 0x0c0a9f66u: goto P_0c0a9f66;
case 0x0c0a9f68u: goto P_0c0a9f68;
case 0x0c0a9f6au: goto P_0c0a9f6a;
case 0x0c0a9f6cu: goto P_0c0a9f6c;
case 0x0c0a9f6eu: goto P_0c0a9f6e;
case 0x0c0a9f70u: goto P_0c0a9f70;
case 0x0c0a9f72u: goto P_0c0a9f72;
case 0x0c0a9f74u: goto P_0c0a9f74;
case 0x0c0a9f76u: goto P_0c0a9f76;
case 0x0c0a9f78u: goto P_0c0a9f78;
case 0x0c0a9f7au: goto P_0c0a9f7a;
case 0x0c0a9f7cu: goto P_0c0a9f7c;
case 0x0c0a9f7eu: goto P_0c0a9f7e;
case 0x0c0a9f80u: goto P_0c0a9f80;
case 0x0c0a9f82u: goto P_0c0a9f82;
case 0x0c0a9f84u: goto P_0c0a9f84;
case 0x0c0a9f86u: goto P_0c0a9f86;
case 0x0c0a9f88u: goto P_0c0a9f88;
case 0x0c0a9f8au: goto P_0c0a9f8a;
case 0x0c0a9f8cu: goto P_0c0a9f8c;
case 0x0c0a9f8eu: goto P_0c0a9f8e;
case 0x0c0a9f90u: goto P_0c0a9f90;
case 0x0c0a9f92u: goto P_0c0a9f92;
case 0x0c0a9f94u: goto P_0c0a9f94;
case 0x0c0a9f96u: goto P_0c0a9f96;
case 0x0c0a9f98u: goto P_0c0a9f98;
case 0x0c0a9f9au: goto P_0c0a9f9a;
case 0x0c0a9f9cu: goto P_0c0a9f9c;
case 0x0c0a9f9eu: goto P_0c0a9f9e;
case 0x0c0a9fa0u: goto P_0c0a9fa0;
case 0x0c0a9fa2u: goto P_0c0a9fa2;
case 0x0c0a9fa4u: goto P_0c0a9fa4;
case 0x0c0a9fa6u: goto P_0c0a9fa6;
case 0x0c0a9fa8u: goto P_0c0a9fa8;
case 0x0c0a9faau: goto P_0c0a9faa;
case 0x0c0a9facu: goto P_0c0a9fac;
case 0x0c0a9faeu: goto P_0c0a9fae;
case 0x0c0aa444u: goto P_0c0aa444;
case 0x0c0aa446u: goto P_0c0aa446;
case 0x0c0aa448u: goto P_0c0aa448;
case 0x0c0aa44au: goto P_0c0aa44a;
case 0x0c0aa44cu: goto P_0c0aa44c;
case 0x0c0aa44eu: goto P_0c0aa44e;
case 0x0c0aa450u: goto P_0c0aa450;
case 0x0c0aa452u: goto P_0c0aa452;
case 0x0c0aa454u: goto P_0c0aa454;
case 0x0c0aa456u: goto P_0c0aa456;
case 0x0c0aa458u: goto P_0c0aa458;
case 0x0c0aa45au: goto P_0c0aa45a;
case 0x0c0aa45cu: goto P_0c0aa45c;
case 0x0c0aa45eu: goto P_0c0aa45e;
case 0x0c0aa460u: goto P_0c0aa460;
case 0x0c0aa462u: goto P_0c0aa462;
case 0x0c0aa464u: goto P_0c0aa464;
case 0x0c0aa466u: goto P_0c0aa466;
case 0x0c0aa468u: goto P_0c0aa468;
case 0x0c0aa46au: goto P_0c0aa46a;
case 0x0c0aa46cu: goto P_0c0aa46c;
case 0x0c0aa46eu: goto P_0c0aa46e;
case 0x0c0aa470u: goto P_0c0aa470;
case 0x0c0aa472u: goto P_0c0aa472;
case 0x0c0aa474u: goto P_0c0aa474;
case 0x0c0ae0a4u: goto P_0c0ae0a4;
case 0x0c0ae0a6u: goto P_0c0ae0a6;
case 0x0c0ae0a8u: goto P_0c0ae0a8;
case 0x0c0ae0aau: goto P_0c0ae0aa;
case 0x0c0ae0acu: goto P_0c0ae0ac;
case 0x0c0ae0aeu: goto P_0c0ae0ae;
case 0x0c0ae0b0u: goto P_0c0ae0b0;
case 0x0c0ae0b2u: goto P_0c0ae0b2;
case 0x0c0ae0b4u: goto P_0c0ae0b4;
case 0x0c0ae0b6u: goto P_0c0ae0b6;
case 0x0c0ae0b8u: goto P_0c0ae0b8;
case 0x0c0ae0bau: goto P_0c0ae0ba;
case 0x0c0ae0bcu: goto P_0c0ae0bc;
case 0x0c0ae0beu: goto P_0c0ae0be;
case 0x0c0ae0c0u: goto P_0c0ae0c0;
case 0x0c0ae0c2u: goto P_0c0ae0c2;
case 0x0c0ae0c4u: goto P_0c0ae0c4;
case 0x0c0ae0c6u: goto P_0c0ae0c6;
case 0x0c0ae0c8u: goto P_0c0ae0c8;
case 0x0c0ae0cau: goto P_0c0ae0ca;
case 0x0c0ae0ccu: goto P_0c0ae0cc;
case 0x0c0ae0ceu: goto P_0c0ae0ce;
case 0x0c0ae0d0u: goto P_0c0ae0d0;
case 0x0c0ae0d2u: goto P_0c0ae0d2;
case 0x0c0ae0d4u: goto P_0c0ae0d4;
case 0x0c0ae0d6u: goto P_0c0ae0d6;
case 0x0c0ae0d8u: goto P_0c0ae0d8;
case 0x0c0ae0dau: goto P_0c0ae0da;
case 0x0c0ae0dcu: goto P_0c0ae0dc;
case 0x0c0ae0deu: goto P_0c0ae0de;
case 0x0c0ae0e0u: goto P_0c0ae0e0;
case 0x0c0ae0e2u: goto P_0c0ae0e2;
case 0x0c0ae0e4u: goto P_0c0ae0e4;
case 0x0c0ae0e6u: goto P_0c0ae0e6;
case 0x0c0ae0e8u: goto P_0c0ae0e8;
case 0x0c0ae0eau: goto P_0c0ae0ea;
default: return vf3_matrix_family(target,s,ram);
}
P_0c0a9e60: /* original 2fe6, guest PC 0x0c0a9e60 */
if(!s->budget--) { s->failed_pc=0x0c0a9e60u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a9e62;
P_0c0a9e62: /* original 6e43, guest PC 0x0c0a9e62 */
if(!s->budget--) { s->failed_pc=0x0c0a9e62u; return 0; }
r[14]=r[4];
goto P_0c0a9e64;
P_0c0a9e64: /* original 2fd6, guest PC 0x0c0a9e64 */
if(!s->budget--) { s->failed_pc=0x0c0a9e64u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a9e66;
P_0c0a9e66: /* original 2fc6, guest PC 0x0c0a9e66 */
if(!s->budget--) { s->failed_pc=0x0c0a9e66u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a9e68;
P_0c0a9e68: /* original 54ed, guest PC 0x0c0a9e68 */
if(!s->budget--) { s->failed_pc=0x0c0a9e68u; return 0; }
r[4]=read(ram,r[14]+52,4);
goto P_0c0a9e6a;
P_0c0a9e6a: /* original 4f22, guest PC 0x0c0a9e6a */
if(!s->budget--) { s->failed_pc=0x0c0a9e6au; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0a9e6c;
P_0c0a9e6c: /* original 2448, guest PC 0x0c0a9e6c */
if(!s->budget--) { s->failed_pc=0x0c0a9e6cu; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c0a9e6e;
P_0c0a9e6e: /* original 8d19, guest PC 0x0c0a9e6e */
if(!s->budget--) { s->failed_pc=0x0c0a9e6eu; return 0; }
cond=r[17]&1u;
r[13]=0x00000000u;
if(cond) { goto P_0c0a9ea4; }
goto P_0c0a9e72;
P_0c0a9e70: /* original ed00, guest PC 0x0c0a9e70 */
if(!s->budget--) { s->failed_pc=0x0c0a9e70u; return 0; }
r[13]=0x00000000u;
goto P_0c0a9e72;
P_0c0a9e72: /* original 1e4c, guest PC 0x0c0a9e72 */
if(!s->budget--) { s->failed_pc=0x0c0a9e72u; return 0; }
write(ram,r[14]+48,r[4],4);
goto P_0c0a9e74;
P_0c0a9e74: /* original 9008, guest PC 0x0c0a9e74 */
if(!s->budget--) { s->failed_pc=0x0c0a9e74u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a9e88u,2);
goto P_0c0a9e76;
P_0c0a9e76: /* original 0ed6, guest PC 0x0c0a9e76 */
if(!s->budget--) { s->failed_pc=0x0c0a9e76u; return 0; }
write(ram,r[14]+r[0],r[13],4);
goto P_0c0a9e78;
P_0c0a9e78: /* original 7004, guest PC 0x0c0a9e78 */
if(!s->budget--) { s->failed_pc=0x0c0a9e78u; return 0; }
r[0]+=0x00000004u;
goto P_0c0a9e7a;
P_0c0a9e7a: /* original a06a, guest PC 0x0c0a9e7a */
if(!s->budget--) { s->failed_pc=0x0c0a9e7au; return 0; }
write(ram,r[14]+r[0],r[13],4);
goto P_0c0a9f52;
P_0c0a9e7c: /* original 0ed6, guest PC 0x0c0a9e7c */
if(!s->budget--) { s->failed_pc=0x0c0a9e7cu; return 0; }
write(ram,r[14]+r[0],r[13],4);
if(!vf3_matrix_family(0x0c0a9e7eu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0a9e7eu; return 0; } return 1;
P_0c0a9ea4: /* original 9084, guest PC 0x0c0a9ea4 */
if(!s->budget--) { s->failed_pc=0x0c0a9ea4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a9fb0u,2);
goto P_0c0a9ea6;
P_0c0a9ea6: /* original 04ee, guest PC 0x0c0a9ea6 */
if(!s->budget--) { s->failed_pc=0x0c0a9ea6u; return 0; }
r[4]=read(ram,r[14]+r[0],4);
goto P_0c0a9ea8;
P_0c0a9ea8: /* original 2448, guest PC 0x0c0a9ea8 */
if(!s->budget--) { s->failed_pc=0x0c0a9ea8u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c0a9eaa;
P_0c0a9eaa: /* original 890a, guest PC 0x0c0a9eaa */
if(!s->budget--) { s->failed_pc=0x0c0a9eaau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a9ec2; }
goto P_0c0a9eac;
P_0c0a9eac: /* original e03e, guest PC 0x0c0a9eac */
if(!s->budget--) { s->failed_pc=0x0c0a9eacu; return 0; }
r[0]=0x0000003eu;
goto P_0c0a9eae;
P_0c0a9eae: /* original 02ed, guest PC 0x0c0a9eae */
if(!s->budget--) { s->failed_pc=0x0c0a9eaeu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0a9eb0;
P_0c0a9eb0: /* original 907f, guest PC 0x0c0a9eb0 */
if(!s->budget--) { s->failed_pc=0x0c0a9eb0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a9fb2u,2);
goto P_0c0a9eb2;
P_0c0a9eb2: /* original 622d, guest PC 0x0c0a9eb2 */
if(!s->budget--) { s->failed_pc=0x0c0a9eb2u; return 0; }
r[2]=r[2]&65535u;
goto P_0c0a9eb4;
P_0c0a9eb4: /* original 03ed, guest PC 0x0c0a9eb4 */
if(!s->budget--) { s->failed_pc=0x0c0a9eb4u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0a9eb6;
P_0c0a9eb6: /* original 3233, guest PC 0x0c0a9eb6 */
if(!s->budget--) { s->failed_pc=0x0c0a9eb6u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[2]>=(int32_t)r[3])!=0);
goto P_0c0a9eb8;
P_0c0a9eb8: /* original 8b03, guest PC 0x0c0a9eb8 */
if(!s->budget--) { s->failed_pc=0x0c0a9eb8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a9ec2; }
goto P_0c0a9eba;
P_0c0a9eba: /* original 1e4c, guest PC 0x0c0a9eba */
if(!s->budget--) { s->failed_pc=0x0c0a9ebau; return 0; }
write(ram,r[14]+48,r[4],4);
goto P_0c0a9ebc;
P_0c0a9ebc: /* original 9078, guest PC 0x0c0a9ebc */
if(!s->budget--) { s->failed_pc=0x0c0a9ebcu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a9fb0u,2);
goto P_0c0a9ebe;
P_0c0a9ebe: /* original a04a, guest PC 0x0c0a9ebe */
if(!s->budget--) { s->failed_pc=0x0c0a9ebeu; return 0; }
write(ram,r[14]+r[0],r[13],4);
goto P_0c0a9f56;
P_0c0a9ec0: /* original 0ed6, guest PC 0x0c0a9ec0 */
if(!s->budget--) { s->failed_pc=0x0c0a9ec0u; return 0; }
write(ram,r[14]+r[0],r[13],4);
goto P_0c0a9ec2;
P_0c0a9ec2: /* original 5cec, guest PC 0x0c0a9ec2 */
if(!s->budget--) { s->failed_pc=0x0c0a9ec2u; return 0; }
r[12]=read(ram,r[14]+48,4);
goto P_0c0a9ec4;
P_0c0a9ec4: /* original 64c3, guest PC 0x0c0a9ec4 */
if(!s->budget--) { s->failed_pc=0x0c0a9ec4u; return 0; }
r[4]=r[12];
goto P_0c0a9ec6;
P_0c0a9ec6: /* original 4429, guest PC 0x0c0a9ec6 */
if(!s->budget--) { s->failed_pc=0x0c0a9ec6u; return 0; }
r[4]>>=16;
goto P_0c0a9ec8;
P_0c0a9ec8: /* original 4419, guest PC 0x0c0a9ec8 */
if(!s->budget--) { s->failed_pc=0x0c0a9ec8u; return 0; }
r[4]>>=8;
goto P_0c0a9eca;
P_0c0a9eca: /* original 6043, guest PC 0x0c0a9eca */
if(!s->budget--) { s->failed_pc=0x0c0a9ecau; return 0; }
r[0]=r[4];
goto P_0c0a9ecc;
P_0c0a9ecc: /* original 8817, guest PC 0x0c0a9ecc */
if(!s->budget--) { s->failed_pc=0x0c0a9eccu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000017u)!=0);
goto P_0c0a9ece;
P_0c0a9ece: /* original 8b15, guest PC 0x0c0a9ece */
if(!s->budget--) { s->failed_pc=0x0c0a9eceu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a9efc; }
goto P_0c0a9ed0;
P_0c0a9ed0: /* original 54ec, guest PC 0x0c0a9ed0 */
if(!s->budget--) { s->failed_pc=0x0c0a9ed0u; return 0; }
r[4]=read(ram,r[14]+48,4);
goto P_0c0a9ed2;
P_0c0a9ed2: /* original d339, guest PC 0x0c0a9ed2 */
if(!s->budget--) { s->failed_pc=0x0c0a9ed2u; return 0; }
r[3]=read(ram,0x0c0a9fb8u,4);
goto P_0c0a9ed4;
P_0c0a9ed4: /* original 644d, guest PC 0x0c0a9ed4 */
if(!s->budget--) { s->failed_pc=0x0c0a9ed4u; return 0; }
r[4]=r[4]&65535u;
goto P_0c0a9ed6;
P_0c0a9ed6: /* original 430b, guest PC 0x0c0a9ed6 */
if(!s->budget--) { s->failed_pc=0x0c0a9ed6u; return 0; }
target=r[3];
r[16]=code_base|0x0c0a9edau;
r[5]=0x0000000fu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a9edau) { target=s->pc; goto dispatch; }
goto P_0c0a9eda;
P_0c0a9ed8: /* original e50f, guest PC 0x0c0a9ed8 */
if(!s->budget--) { s->failed_pc=0x0c0a9ed8u; return 0; }
r[5]=0x0000000fu;
goto P_0c0a9eda;
P_0c0a9eda: /* original 6403, guest PC 0x0c0a9eda */
if(!s->budget--) { s->failed_pc=0x0c0a9edau; return 0; }
r[4]=r[0];
goto P_0c0a9edc;
P_0c0a9edc: /* original 8442, guest PC 0x0c0a9edc */
if(!s->budget--) { s->failed_pc=0x0c0a9edcu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+2,1);
goto P_0c0a9ede;
P_0c0a9ede: /* original d337, guest PC 0x0c0a9ede */
if(!s->budget--) { s->failed_pc=0x0c0a9edeu; return 0; }
r[3]=read(ram,0x0c0a9fbcu,4);
goto P_0c0a9ee0;
P_0c0a9ee0: /* original 600c, guest PC 0x0c0a9ee0 */
if(!s->budget--) { s->failed_pc=0x0c0a9ee0u; return 0; }
r[0]=r[0]&255u;
goto P_0c0a9ee2;
P_0c0a9ee2: /* original 4018, guest PC 0x0c0a9ee2 */
if(!s->budget--) { s->failed_pc=0x0c0a9ee2u; return 0; }
r[0]<<=8;
goto P_0c0a9ee4;
P_0c0a9ee4: /* original 2039, guest PC 0x0c0a9ee4 */
if(!s->budget--) { s->failed_pc=0x0c0a9ee4u; return 0; }
r[0]&=r[3];
goto P_0c0a9ee6;
P_0c0a9ee6: /* original 6203, guest PC 0x0c0a9ee6 */
if(!s->budget--) { s->failed_pc=0x0c0a9ee6u; return 0; }
r[2]=r[0];
goto P_0c0a9ee8;
P_0c0a9ee8: /* original 8441, guest PC 0x0c0a9ee8 */
if(!s->budget--) { s->failed_pc=0x0c0a9ee8u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+1,1);
goto P_0c0a9eea;
P_0c0a9eea: /* original 6423, guest PC 0x0c0a9eea */
if(!s->budget--) { s->failed_pc=0x0c0a9eeau; return 0; }
r[4]=r[2];
goto P_0c0a9eec;
P_0c0a9eec: /* original 600c, guest PC 0x0c0a9eec */
if(!s->budget--) { s->failed_pc=0x0c0a9eecu; return 0; }
r[0]=r[0]&255u;
goto P_0c0a9eee;
P_0c0a9eee: /* original 240b, guest PC 0x0c0a9eee */
if(!s->budget--) { s->failed_pc=0x0c0a9eeeu; return 0; }
r[4]|=r[0];
goto P_0c0a9ef0;
P_0c0a9ef0: /* original 905f, guest PC 0x0c0a9ef0 */
if(!s->budget--) { s->failed_pc=0x0c0a9ef0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a9fb2u,2);
goto P_0c0a9ef2;
P_0c0a9ef2: /* original 74ff, guest PC 0x0c0a9ef2 */
if(!s->budget--) { s->failed_pc=0x0c0a9ef2u; return 0; }
r[4]+=0xffffffffu;
goto P_0c0a9ef4;
P_0c0a9ef4: /* original 0e45, guest PC 0x0c0a9ef4 */
if(!s->budget--) { s->failed_pc=0x0c0a9ef4u; return 0; }
write(ram,r[14]+r[0],r[4],2);
goto P_0c0a9ef6;
P_0c0a9ef6: /* original 70fc, guest PC 0x0c0a9ef6 */
if(!s->budget--) { s->failed_pc=0x0c0a9ef6u; return 0; }
r[0]+=0xfffffffcu;
goto P_0c0a9ef8;
P_0c0a9ef8: /* original a027, guest PC 0x0c0a9ef8 */
if(!s->budget--) { s->failed_pc=0x0c0a9ef8u; return 0; }
write(ram,r[14]+r[0],r[12],4);
goto P_0c0a9f4a;
P_0c0a9efa: /* original 0ec6, guest PC 0x0c0a9efa */
if(!s->budget--) { s->failed_pc=0x0c0a9efau; return 0; }
write(ram,r[14]+r[0],r[12],4);
goto P_0c0a9efc;
P_0c0a9efc: /* original 881b, guest PC 0x0c0a9efc */
if(!s->budget--) { s->failed_pc=0x0c0a9efcu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000001bu)!=0);
goto P_0c0a9efe;
P_0c0a9efe: /* original 8b1d, guest PC 0x0c0a9efe */
if(!s->budget--) { s->failed_pc=0x0c0a9efeu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a9f3c; }
goto P_0c0a9f00;
P_0c0a9f00: /* original e03e, guest PC 0x0c0a9f00 */
if(!s->budget--) { s->failed_pc=0x0c0a9f00u; return 0; }
r[0]=0x0000003eu;
goto P_0c0a9f02;
P_0c0a9f02: /* original 04ed, guest PC 0x0c0a9f02 */
if(!s->budget--) { s->failed_pc=0x0c0a9f02u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0a9f04;
P_0c0a9f04: /* original e042, guest PC 0x0c0a9f04 */
if(!s->budget--) { s->failed_pc=0x0c0a9f04u; return 0; }
r[0]=0x00000042u;
goto P_0c0a9f06;
P_0c0a9f06: /* original 05ed, guest PC 0x0c0a9f06 */
if(!s->budget--) { s->failed_pc=0x0c0a9f06u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0a9f08;
P_0c0a9f08: /* original e040, guest PC 0x0c0a9f08 */
if(!s->budget--) { s->failed_pc=0x0c0a9f08u; return 0; }
r[0]=0x00000040u;
goto P_0c0a9f0a;
P_0c0a9f0a: /* original 06ed, guest PC 0x0c0a9f0a */
if(!s->budget--) { s->failed_pc=0x0c0a9f0au; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0a9f0c;
P_0c0a9f0c: /* original 644d, guest PC 0x0c0a9f0c */
if(!s->budget--) { s->failed_pc=0x0c0a9f0cu; return 0; }
r[4]=r[4]&65535u;
goto P_0c0a9f0e;
P_0c0a9f0e: /* original 655d, guest PC 0x0c0a9f0e */
if(!s->budget--) { s->failed_pc=0x0c0a9f0eu; return 0; }
r[5]=r[5]&65535u;
goto P_0c0a9f10;
P_0c0a9f10: /* original 6353, guest PC 0x0c0a9f10 */
if(!s->budget--) { s->failed_pc=0x0c0a9f10u; return 0; }
r[3]=r[5];
goto P_0c0a9f12;
P_0c0a9f12: /* original 4500, guest PC 0x0c0a9f12 */
if(!s->budget--) { s->failed_pc=0x0c0a9f12u; return 0; }
r[17]=(r[17]&~1u)|((r[5]>>31)!=0);
r[5]<<=1;
goto P_0c0a9f14;
P_0c0a9f14: /* original 4428, guest PC 0x0c0a9f14 */
if(!s->budget--) { s->failed_pc=0x0c0a9f14u; return 0; }
r[4]<<=16;
goto P_0c0a9f16;
P_0c0a9f16: /* original 353c, guest PC 0x0c0a9f16 */
if(!s->budget--) { s->failed_pc=0x0c0a9f16u; return 0; }
r[5]+=r[3];
goto P_0c0a9f18;
P_0c0a9f18: /* original 666d, guest PC 0x0c0a9f18 */
if(!s->budget--) { s->failed_pc=0x0c0a9f18u; return 0; }
r[6]=r[6]&65535u;
goto P_0c0a9f1a;
P_0c0a9f1a: /* original 246b, guest PC 0x0c0a9f1a */
if(!s->budget--) { s->failed_pc=0x0c0a9f1au; return 0; }
r[4]|=r[6];
goto P_0c0a9f1c;
P_0c0a9f1c: /* original 4518, guest PC 0x0c0a9f1c */
if(!s->budget--) { s->failed_pc=0x0c0a9f1cu; return 0; }
r[5]<<=8;
goto P_0c0a9f1e;
P_0c0a9f1e: /* original 345c, guest PC 0x0c0a9f1e */
if(!s->budget--) { s->failed_pc=0x0c0a9f1eu; return 0; }
r[4]+=r[5];
goto P_0c0a9f20;
P_0c0a9f20: /* original 0e45, guest PC 0x0c0a9f20 */
if(!s->budget--) { s->failed_pc=0x0c0a9f20u; return 0; }
write(ram,r[14]+r[0],r[4],2);
goto P_0c0a9f22;
P_0c0a9f22: /* original 4429, guest PC 0x0c0a9f22 */
if(!s->budget--) { s->failed_pc=0x0c0a9f22u; return 0; }
r[4]>>=16;
goto P_0c0a9f24;
P_0c0a9f24: /* original 9046, guest PC 0x0c0a9f24 */
if(!s->budget--) { s->failed_pc=0x0c0a9f24u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a9fb4u,2);
goto P_0c0a9f26;
P_0c0a9f26: /* original 05ed, guest PC 0x0c0a9f26 */
if(!s->budget--) { s->failed_pc=0x0c0a9f26u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0a9f28;
P_0c0a9f28: /* original 655d, guest PC 0x0c0a9f28 */
if(!s->budget--) { s->failed_pc=0x0c0a9f28u; return 0; }
r[5]=r[5]&65535u;
goto P_0c0a9f2a;
P_0c0a9f2a: /* original 75ff, guest PC 0x0c0a9f2a */
if(!s->budget--) { s->failed_pc=0x0c0a9f2au; return 0; }
r[5]+=0xffffffffu;
goto P_0c0a9f2c;
P_0c0a9f2c: /* original 3452, guest PC 0x0c0a9f2c */
if(!s->budget--) { s->failed_pc=0x0c0a9f2cu; return 0; }
r[17]=(r[17]&~1u)|((r[4]>=r[5])!=0);
goto P_0c0a9f2e;
P_0c0a9f2e: /* original 8902, guest PC 0x0c0a9f2e */
if(!s->budget--) { s->failed_pc=0x0c0a9f2eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a9f36; }
goto P_0c0a9f30;
P_0c0a9f30: /* original e03e, guest PC 0x0c0a9f30 */
if(!s->budget--) { s->failed_pc=0x0c0a9f30u; return 0; }
r[0]=0x0000003eu;
goto P_0c0a9f32;
P_0c0a9f32: /* original a00a, guest PC 0x0c0a9f32 */
if(!s->budget--) { s->failed_pc=0x0c0a9f32u; return 0; }
write(ram,r[14]+r[0],r[4],2);
goto P_0c0a9f4a;
P_0c0a9f34: /* original 0e45, guest PC 0x0c0a9f34 */
if(!s->budget--) { s->failed_pc=0x0c0a9f34u; return 0; }
write(ram,r[14]+r[0],r[4],2);
goto P_0c0a9f36;
P_0c0a9f36: /* original e03e, guest PC 0x0c0a9f36 */
if(!s->budget--) { s->failed_pc=0x0c0a9f36u; return 0; }
r[0]=0x0000003eu;
goto P_0c0a9f38;
P_0c0a9f38: /* original a007, guest PC 0x0c0a9f38 */
if(!s->budget--) { s->failed_pc=0x0c0a9f38u; return 0; }
write(ram,r[14]+r[0],r[5],2);
goto P_0c0a9f4a;
P_0c0a9f3a: /* original 0e55, guest PC 0x0c0a9f3a */
if(!s->budget--) { s->failed_pc=0x0c0a9f3au; return 0; }
write(ram,r[14]+r[0],r[5],2);
goto P_0c0a9f3c;
P_0c0a9f3c: /* original 62e2, guest PC 0x0c0a9f3c */
if(!s->budget--) { s->failed_pc=0x0c0a9f3cu; return 0; }
tmp=read(ram,r[14],4);
r[2]=tmp;
goto P_0c0a9f3e;
P_0c0a9f3e: /* original d320, guest PC 0x0c0a9f3e */
if(!s->budget--) { s->failed_pc=0x0c0a9f3eu; return 0; }
r[3]=read(ram,0x0c0a9fc0u,4);
goto P_0c0a9f40;
P_0c0a9f40: /* original 2238, guest PC 0x0c0a9f40 */
if(!s->budget--) { s->failed_pc=0x0c0a9f40u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c0a9f42;
P_0c0a9f42: /* original 8904, guest PC 0x0c0a9f42 */
if(!s->budget--) { s->failed_pc=0x0c0a9f42u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a9f4e; }
goto P_0c0a9f44;
P_0c0a9f44: /* original 6043, guest PC 0x0c0a9f44 */
if(!s->budget--) { s->failed_pc=0x0c0a9f44u; return 0; }
r[0]=r[4];
goto P_0c0a9f46;
P_0c0a9f46: /* original 880b, guest PC 0x0c0a9f46 */
if(!s->budget--) { s->failed_pc=0x0c0a9f46u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000bu)!=0);
goto P_0c0a9f48;
P_0c0a9f48: /* original 8901, guest PC 0x0c0a9f48 */
if(!s->budget--) { s->failed_pc=0x0c0a9f48u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a9f4e; }
goto P_0c0a9f4a;
P_0c0a9f4a: /* original a004, guest PC 0x0c0a9f4a */
if(!s->budget--) { s->failed_pc=0x0c0a9f4au; return 0; }
write(ram,r[14]+48,r[13],4);
goto P_0c0a9f56;
P_0c0a9f4c: /* original 1edc, guest PC 0x0c0a9f4c */
if(!s->budget--) { s->failed_pc=0x0c0a9f4cu; return 0; }
write(ram,r[14]+48,r[13],4);
goto P_0c0a9f4e;
P_0c0a9f4e: /* original 2cc8, guest PC 0x0c0a9f4e */
if(!s->budget--) { s->failed_pc=0x0c0a9f4eu; return 0; }
r[17]=(r[17]&~1u)|(((r[12]&r[12])==0)!=0);
goto P_0c0a9f50;
P_0c0a9f50: /* original 8901, guest PC 0x0c0a9f50 */
if(!s->budget--) { s->failed_pc=0x0c0a9f50u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a9f56; }
goto P_0c0a9f52;
P_0c0a9f52: /* original 902d, guest PC 0x0c0a9f52 */
if(!s->budget--) { s->failed_pc=0x0c0a9f52u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a9fb0u,2);
goto P_0c0a9f54;
P_0c0a9f54: /* original 0ed6, guest PC 0x0c0a9f54 */
if(!s->budget--) { s->failed_pc=0x0c0a9f54u; return 0; }
write(ram,r[14]+r[0],r[13],4);
goto P_0c0a9f56;
P_0c0a9f56: /* original 4f26, guest PC 0x0c0a9f56 */
if(!s->budget--) { s->failed_pc=0x0c0a9f56u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a9f58;
P_0c0a9f58: /* original 6cf6, guest PC 0x0c0a9f58 */
if(!s->budget--) { s->failed_pc=0x0c0a9f58u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0a9f5a;
P_0c0a9f5a: /* original 6df6, guest PC 0x0c0a9f5a */
if(!s->budget--) { s->failed_pc=0x0c0a9f5au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0a9f5c;
P_0c0a9f5c: /* original 000b, guest PC 0x0c0a9f5c */
if(!s->budget--) { s->failed_pc=0x0c0a9f5cu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0a9f5e: /* original 6ef6, guest PC 0x0c0a9f5e */
if(!s->budget--) { s->failed_pc=0x0c0a9f5eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0a9f60;
P_0c0a9f60: /* original 534c, guest PC 0x0c0a9f60 */
if(!s->budget--) { s->failed_pc=0x0c0a9f60u; return 0; }
r[3]=read(ram,r[4]+48,4);
goto P_0c0a9f62;
P_0c0a9f62: /* original 4f22, guest PC 0x0c0a9f62 */
if(!s->budget--) { s->failed_pc=0x0c0a9f62u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0a9f64;
P_0c0a9f64: /* original 6233, guest PC 0x0c0a9f64 */
if(!s->budget--) { s->failed_pc=0x0c0a9f64u; return 0; }
r[2]=r[3];
goto P_0c0a9f66;
P_0c0a9f66: /* original 2228, guest PC 0x0c0a9f66 */
if(!s->budget--) { s->failed_pc=0x0c0a9f66u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c0a9f68;
P_0c0a9f68: /* original 7ff0, guest PC 0x0c0a9f68 */
if(!s->budget--) { s->failed_pc=0x0c0a9f68u; return 0; }
r[15]+=0xfffffff0u;
goto P_0c0a9f6a;
P_0c0a9f6a: /* original 8f06, guest PC 0x0c0a9f6a */
if(!s->budget--) { s->failed_pc=0x0c0a9f6au; return 0; }
cond=r[17]&1u;
write(ram,r[15]+12,r[3],4);
if(!cond) { goto P_0c0a9f7a; }
goto P_0c0a9f6e;
P_0c0a9f6c: /* original 1f33, guest PC 0x0c0a9f6c */
if(!s->budget--) { s->failed_pc=0x0c0a9f6cu; return 0; }
write(ram,r[15]+12,r[3],4);
goto P_0c0a9f6e;
P_0c0a9f6e: /* original b01c, guest PC 0x0c0a9f6e */
if(!s->budget--) { s->failed_pc=0x0c0a9f6eu; return 0; }
target=code_base|0x0c0a9faau; r[16]=code_base|0x0c0a9f72u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a9f72u) { target=s->pc; goto dispatch; }
goto P_0c0a9f72;
P_0c0a9f70: /* original 0009, guest PC 0x0c0a9f70 */
if(!s->budget--) { s->failed_pc=0x0c0a9f70u; return 0; }
goto P_0c0a9f72;
P_0c0a9f72: /* original 7f10, guest PC 0x0c0a9f72 */
if(!s->budget--) { s->failed_pc=0x0c0a9f72u; return 0; }
r[15]+=0x00000010u;
goto P_0c0a9f74;
P_0c0a9f74: /* original 4f26, guest PC 0x0c0a9f74 */
if(!s->budget--) { s->failed_pc=0x0c0a9f74u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a9f76;
P_0c0a9f76: /* original 000b, guest PC 0x0c0a9f76 */
if(!s->budget--) { s->failed_pc=0x0c0a9f76u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c0a9f78: /* original 0009, guest PC 0x0c0a9f78 */
if(!s->budget--) { s->failed_pc=0x0c0a9f78u; return 0; }
goto P_0c0a9f7a;
P_0c0a9f7a: /* original 6243, guest PC 0x0c0a9f7a */
if(!s->budget--) { s->failed_pc=0x0c0a9f7au; return 0; }
r[2]=r[4];
goto P_0c0a9f7c;
P_0c0a9f7c: /* original 7238, guest PC 0x0c0a9f7c */
if(!s->budget--) { s->failed_pc=0x0c0a9f7cu; return 0; }
r[2]+=0x00000038u;
goto P_0c0a9f7e;
P_0c0a9f7e: /* original 8423, guest PC 0x0c0a9f7e */
if(!s->budget--) { s->failed_pc=0x0c0a9f7eu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[2]+3,1);
goto P_0c0a9f80;
P_0c0a9f80: /* original 66f3, guest PC 0x0c0a9f80 */
if(!s->budget--) { s->failed_pc=0x0c0a9f80u; return 0; }
r[6]=r[15];
goto P_0c0a9f82;
P_0c0a9f82: /* original 600c, guest PC 0x0c0a9f82 */
if(!s->budget--) { s->failed_pc=0x0c0a9f82u; return 0; }
r[0]=r[0]&255u;
goto P_0c0a9f84;
P_0c0a9f84: /* original 1f02, guest PC 0x0c0a9f84 */
if(!s->budget--) { s->failed_pc=0x0c0a9f84u; return 0; }
write(ram,r[15]+8,r[0],4);
goto P_0c0a9f86;
P_0c0a9f86: /* original 53f3, guest PC 0x0c0a9f86 */
if(!s->budget--) { s->failed_pc=0x0c0a9f86u; return 0; }
r[3]=read(ram,r[15]+12,4);
goto P_0c0a9f88;
P_0c0a9f88: /* original 4329, guest PC 0x0c0a9f88 */
if(!s->budget--) { s->failed_pc=0x0c0a9f88u; return 0; }
r[3]>>=16;
goto P_0c0a9f8a;
P_0c0a9f8a: /* original 4319, guest PC 0x0c0a9f8a */
if(!s->budget--) { s->failed_pc=0x0c0a9f8au; return 0; }
r[3]>>=8;
goto P_0c0a9f8c;
P_0c0a9f8c: /* original 6033, guest PC 0x0c0a9f8c */
if(!s->budget--) { s->failed_pc=0x0c0a9f8cu; return 0; }
r[0]=r[3];
goto P_0c0a9f8e;
P_0c0a9f8e: /* original c9ff, guest PC 0x0c0a9f8e */
if(!s->budget--) { s->failed_pc=0x0c0a9f8eu; return 0; }
r[0]&=255u;
goto P_0c0a9f90;
P_0c0a9f90: /* original 6303, guest PC 0x0c0a9f90 */
if(!s->budget--) { s->failed_pc=0x0c0a9f90u; return 0; }
r[3]=r[0];
goto P_0c0a9f92;
P_0c0a9f92: /* original 1f01, guest PC 0x0c0a9f92 */
if(!s->budget--) { s->failed_pc=0x0c0a9f92u; return 0; }
write(ram,r[15]+4,r[0],4);
goto P_0c0a9f94;
P_0c0a9f94: /* original d00b, guest PC 0x0c0a9f94 */
if(!s->budget--) { s->failed_pc=0x0c0a9f94u; return 0; }
r[0]=read(ram,0x0c0a9fc4u,4);
goto P_0c0a9f96;
P_0c0a9f96: /* original 4308, guest PC 0x0c0a9f96 */
if(!s->budget--) { s->failed_pc=0x0c0a9f96u; return 0; }
r[3]<<=2;
goto P_0c0a9f98;
P_0c0a9f98: /* original 023e, guest PC 0x0c0a9f98 */
if(!s->budget--) { s->failed_pc=0x0c0a9f98u; return 0; }
r[2]=read(ram,r[3]+r[0],4);
goto P_0c0a9f9a;
P_0c0a9f9a: /* original 6323, guest PC 0x0c0a9f9a */
if(!s->budget--) { s->failed_pc=0x0c0a9f9au; return 0; }
r[3]=r[2];
goto P_0c0a9f9c;
P_0c0a9f9c: /* original 2f22, guest PC 0x0c0a9f9c */
if(!s->budget--) { s->failed_pc=0x0c0a9f9cu; return 0; }
write(ram,r[15],r[2],4);
goto P_0c0a9f9e;
P_0c0a9f9e: /* original 430b, guest PC 0x0c0a9f9e */
if(!s->budget--) { s->failed_pc=0x0c0a9f9eu; return 0; }
target=r[3];
r[16]=code_base|0x0c0a9fa2u;
r[6]+=0x00000004u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a9fa2u) { target=s->pc; goto dispatch; }
goto P_0c0a9fa2;
P_0c0a9fa0: /* original 7604, guest PC 0x0c0a9fa0 */
if(!s->budget--) { s->failed_pc=0x0c0a9fa0u; return 0; }
r[6]+=0x00000004u;
goto P_0c0a9fa2;
P_0c0a9fa2: /* original 7f10, guest PC 0x0c0a9fa2 */
if(!s->budget--) { s->failed_pc=0x0c0a9fa2u; return 0; }
r[15]+=0x00000010u;
goto P_0c0a9fa4;
P_0c0a9fa4: /* original 4f26, guest PC 0x0c0a9fa4 */
if(!s->budget--) { s->failed_pc=0x0c0a9fa4u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a9fa6;
P_0c0a9fa6: /* original 000b, guest PC 0x0c0a9fa6 */
if(!s->budget--) { s->failed_pc=0x0c0a9fa6u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c0a9fa8: /* original 0009, guest PC 0x0c0a9fa8 */
if(!s->budget--) { s->failed_pc=0x0c0a9fa8u; return 0; }
goto P_0c0a9faa;
P_0c0a9faa: /* original e300, guest PC 0x0c0a9faa */
if(!s->budget--) { s->failed_pc=0x0c0a9faau; return 0; }
r[3]=0x00000000u;
goto P_0c0a9fac;
P_0c0a9fac: /* original 000b, guest PC 0x0c0a9fac */
if(!s->budget--) { s->failed_pc=0x0c0a9facu; return 0; }
target=r[16];
write(ram,r[4]+48,r[3],4);
s->pc=target; return ram->oob==0;
P_0c0a9fae: /* original 143c, guest PC 0x0c0a9fae */
if(!s->budget--) { s->failed_pc=0x0c0a9faeu; return 0; }
write(ram,r[4]+48,r[3],4);
if(!vf3_matrix_family(0x0c0a9fb0u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0a9fb0u; return 0; } return 1;
P_0c0aa444: /* original 534e, guest PC 0x0c0aa444 */
if(!s->budget--) { s->failed_pc=0x0c0aa444u; return 0; }
r[3]=read(ram,r[4]+56,4);
goto P_0c0aa446;
P_0c0aa446: /* original 4f22, guest PC 0x0c0aa446 */
if(!s->budget--) { s->failed_pc=0x0c0aa446u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0aa448;
P_0c0aa448: /* original 6233, guest PC 0x0c0aa448 */
if(!s->budget--) { s->failed_pc=0x0c0aa448u; return 0; }
r[2]=r[3];
goto P_0c0aa44a;
P_0c0aa44a: /* original 2228, guest PC 0x0c0aa44a */
if(!s->budget--) { s->failed_pc=0x0c0aa44au; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c0aa44c;
P_0c0aa44c: /* original 7ff4, guest PC 0x0c0aa44c */
if(!s->budget--) { s->failed_pc=0x0c0aa44cu; return 0; }
r[15]+=0xfffffff4u;
goto P_0c0aa44e;
P_0c0aa44e: /* original 8d0e, guest PC 0x0c0aa44e */
if(!s->budget--) { s->failed_pc=0x0c0aa44eu; return 0; }
cond=r[17]&1u;
write(ram,r[15]+4,r[3],4);
if(cond) { goto P_0c0aa46e; }
goto P_0c0aa452;
P_0c0aa450: /* original 1f31, guest PC 0x0c0aa450 */
if(!s->budget--) { s->failed_pc=0x0c0aa450u; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c0aa452;
P_0c0aa452: /* original e062, guest PC 0x0c0aa452 */
if(!s->budget--) { s->failed_pc=0x0c0aa452u; return 0; }
r[0]=0x00000062u;
goto P_0c0aa454;
P_0c0aa454: /* original 024c, guest PC 0x0c0aa454 */
if(!s->budget--) { s->failed_pc=0x0c0aa454u; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c0aa456;
P_0c0aa456: /* original 622c, guest PC 0x0c0aa456 */
if(!s->budget--) { s->failed_pc=0x0c0aa456u; return 0; }
r[2]=r[2]&255u;
goto P_0c0aa458;
P_0c0aa458: /* original 1f22, guest PC 0x0c0aa458 */
if(!s->budget--) { s->failed_pc=0x0c0aa458u; return 0; }
write(ram,r[15]+8,r[2],4);
goto P_0c0aa45a;
P_0c0aa45a: /* original 56f1, guest PC 0x0c0aa45a */
if(!s->budget--) { s->failed_pc=0x0c0aa45au; return 0; }
r[6]=read(ram,r[15]+4,4);
goto P_0c0aa45c;
P_0c0aa45c: /* original d013, guest PC 0x0c0aa45c */
if(!s->budget--) { s->failed_pc=0x0c0aa45cu; return 0; }
r[0]=read(ram,0x0c0aa4acu,4);
goto P_0c0aa45e;
P_0c0aa45e: /* original 4629, guest PC 0x0c0aa45e */
if(!s->budget--) { s->failed_pc=0x0c0aa45eu; return 0; }
r[6]>>=16;
goto P_0c0aa460;
P_0c0aa460: /* original 4619, guest PC 0x0c0aa460 */
if(!s->budget--) { s->failed_pc=0x0c0aa460u; return 0; }
r[6]>>=8;
goto P_0c0aa462;
P_0c0aa462: /* original 4608, guest PC 0x0c0aa462 */
if(!s->budget--) { s->failed_pc=0x0c0aa462u; return 0; }
r[6]<<=2;
goto P_0c0aa464;
P_0c0aa464: /* original 036e, guest PC 0x0c0aa464 */
if(!s->budget--) { s->failed_pc=0x0c0aa464u; return 0; }
r[3]=read(ram,r[6]+r[0],4);
goto P_0c0aa466;
P_0c0aa466: /* original 66f3, guest PC 0x0c0aa466 */
if(!s->budget--) { s->failed_pc=0x0c0aa466u; return 0; }
r[6]=r[15];
goto P_0c0aa468;
P_0c0aa468: /* original 2f32, guest PC 0x0c0aa468 */
if(!s->budget--) { s->failed_pc=0x0c0aa468u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c0aa46a;
P_0c0aa46a: /* original 430b, guest PC 0x0c0aa46a */
if(!s->budget--) { s->failed_pc=0x0c0aa46au; return 0; }
target=r[3];
r[16]=code_base|0x0c0aa46eu;
r[6]+=0x00000004u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0aa46eu) { target=s->pc; goto dispatch; }
goto P_0c0aa46e;
P_0c0aa46c: /* original 7604, guest PC 0x0c0aa46c */
if(!s->budget--) { s->failed_pc=0x0c0aa46cu; return 0; }
r[6]+=0x00000004u;
goto P_0c0aa46e;
P_0c0aa46e: /* original 7f0c, guest PC 0x0c0aa46e */
if(!s->budget--) { s->failed_pc=0x0c0aa46eu; return 0; }
r[15]+=0x0000000cu;
goto P_0c0aa470;
P_0c0aa470: /* original 4f26, guest PC 0x0c0aa470 */
if(!s->budget--) { s->failed_pc=0x0c0aa470u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0aa472;
P_0c0aa472: /* original 000b, guest PC 0x0c0aa472 */
if(!s->budget--) { s->failed_pc=0x0c0aa472u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c0aa474: /* original 0009, guest PC 0x0c0aa474 */
if(!s->budget--) { s->failed_pc=0x0c0aa474u; return 0; }
if(!vf3_matrix_family(0x0c0aa476u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0aa476u; return 0; } return 1;
P_0c0ae0a4: /* original 925d, guest PC 0x0c0ae0a4 */
if(!s->budget--) { s->failed_pc=0x0c0ae0a4u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ae162u,2);
goto P_0c0ae0a6;
P_0c0ae0a6: /* original d333, guest PC 0x0c0ae0a6 */
if(!s->budget--) { s->failed_pc=0x0c0ae0a6u; return 0; }
r[3]=read(ram,0x0c0ae174u,4);
goto P_0c0ae0a8;
P_0c0ae0a8: /* original 915c, guest PC 0x0c0ae0a8 */
if(!s->budget--) { s->failed_pc=0x0c0ae0a8u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ae164u,2);
goto P_0c0ae0aa;
P_0c0ae0aa: /* original 2429, guest PC 0x0c0ae0aa */
if(!s->budget--) { s->failed_pc=0x0c0ae0aau; return 0; }
r[4]&=r[2];
goto P_0c0ae0ac;
P_0c0ae0ac: /* original 6632, guest PC 0x0c0ae0ac */
if(!s->budget--) { s->failed_pc=0x0c0ae0acu; return 0; }
tmp=read(ram,r[3],4);
r[6]=tmp;
goto P_0c0ae0ae;
P_0c0ae0ae: /* original 3412, guest PC 0x0c0ae0ae */
if(!s->budget--) { s->failed_pc=0x0c0ae0aeu; return 0; }
r[17]=(r[17]&~1u)|((r[4]>=r[1])!=0);
goto P_0c0ae0b0;
P_0c0ae0b0: /* original 8919, guest PC 0x0c0ae0b0 */
if(!s->budget--) { s->failed_pc=0x0c0ae0b0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0ae0e6; }
goto P_0c0ae0b2;
P_0c0ae0b2: /* original 6043, guest PC 0x0c0ae0b2 */
if(!s->budget--) { s->failed_pc=0x0c0ae0b2u; return 0; }
r[0]=r[4];
goto P_0c0ae0b4;
P_0c0ae0b4: /* original 70ff, guest PC 0x0c0ae0b4 */
if(!s->budget--) { s->failed_pc=0x0c0ae0b4u; return 0; }
r[0]+=0xffffffffu;
goto P_0c0ae0b6;
P_0c0ae0b6: /* original 4008, guest PC 0x0c0ae0b6 */
if(!s->budget--) { s->failed_pc=0x0c0ae0b6u; return 0; }
r[0]<<=2;
goto P_0c0ae0b8;
P_0c0ae0b8: /* original 036e, guest PC 0x0c0ae0b8 */
if(!s->budget--) { s->failed_pc=0x0c0ae0b8u; return 0; }
r[3]=read(ram,r[6]+r[0],4);
goto P_0c0ae0ba;
P_0c0ae0ba: /* original 6433, guest PC 0x0c0ae0ba */
if(!s->budget--) { s->failed_pc=0x0c0ae0bau; return 0; }
r[4]=r[3];
goto P_0c0ae0bc;
P_0c0ae0bc: /* original 346c, guest PC 0x0c0ae0bc */
if(!s->budget--) { s->failed_pc=0x0c0ae0bcu; return 0; }
r[4]+=r[6];
goto P_0c0ae0be;
P_0c0ae0be: /* original 6643, guest PC 0x0c0ae0be */
if(!s->budget--) { s->failed_pc=0x0c0ae0beu; return 0; }
r[6]=r[4];
goto P_0c0ae0c0;
P_0c0ae0c0: /* original 760c, guest PC 0x0c0ae0c0 */
if(!s->budget--) { s->failed_pc=0x0c0ae0c0u; return 0; }
r[6]+=0x0000000cu;
goto P_0c0ae0c2;
P_0c0ae0c2: /* original 6460, guest PC 0x0c0ae0c2 */
if(!s->budget--) { s->failed_pc=0x0c0ae0c2u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[6],1);
r[4]=tmp;
goto P_0c0ae0c4;
P_0c0ae0c4: /* original 644c, guest PC 0x0c0ae0c4 */
if(!s->budget--) { s->failed_pc=0x0c0ae0c4u; return 0; }
r[4]=r[4]&255u;
goto P_0c0ae0c6;
P_0c0ae0c6: /* original 3450, guest PC 0x0c0ae0c6 */
if(!s->budget--) { s->failed_pc=0x0c0ae0c6u; return 0; }
r[17]=(r[17]&~1u)|((r[4]==r[5])!=0);
goto P_0c0ae0c8;
P_0c0ae0c8: /* original 8b01, guest PC 0x0c0ae0c8 */
if(!s->budget--) { s->failed_pc=0x0c0ae0c8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0ae0ce; }
goto P_0c0ae0ca;
P_0c0ae0ca: /* original 000b, guest PC 0x0c0ae0ca */
if(!s->budget--) { s->failed_pc=0x0c0ae0cau; return 0; }
target=r[16];
r[0]=r[6];
s->pc=target; return ram->oob==0;
P_0c0ae0cc: /* original 6063, guest PC 0x0c0ae0cc */
if(!s->budget--) { s->failed_pc=0x0c0ae0ccu; return 0; }
r[0]=r[6];
goto P_0c0ae0ce;
P_0c0ae0ce: /* original 2448, guest PC 0x0c0ae0ce */
if(!s->budget--) { s->failed_pc=0x0c0ae0ceu; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c0ae0d0;
P_0c0ae0d0: /* original 8909, guest PC 0x0c0ae0d0 */
if(!s->budget--) { s->failed_pc=0x0c0ae0d0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0ae0e6; }
goto P_0c0ae0d2;
P_0c0ae0d2: /* original 6043, guest PC 0x0c0ae0d2 */
if(!s->budget--) { s->failed_pc=0x0c0ae0d2u; return 0; }
r[0]=r[4];
goto P_0c0ae0d4;
P_0c0ae0d4: /* original 8808, guest PC 0x0c0ae0d4 */
if(!s->budget--) { s->failed_pc=0x0c0ae0d4u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000008u)!=0);
goto P_0c0ae0d6;
P_0c0ae0d6: /* original 8906, guest PC 0x0c0ae0d6 */
if(!s->budget--) { s->failed_pc=0x0c0ae0d6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0ae0e6; }
goto P_0c0ae0d8;
P_0c0ae0d8: /* original e316, guest PC 0x0c0ae0d8 */
if(!s->budget--) { s->failed_pc=0x0c0ae0d8u; return 0; }
r[3]=0x00000016u;
goto P_0c0ae0da;
P_0c0ae0da: /* original 3436, guest PC 0x0c0ae0da */
if(!s->budget--) { s->failed_pc=0x0c0ae0dau; return 0; }
r[17]=(r[17]&~1u)|((r[4]>r[3])!=0);
goto P_0c0ae0dc;
P_0c0ae0dc: /* original 8903, guest PC 0x0c0ae0dc */
if(!s->budget--) { s->failed_pc=0x0c0ae0dcu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0ae0e6; }
goto P_0c0ae0de;
P_0c0ae0de: /* original d026, guest PC 0x0c0ae0de */
if(!s->budget--) { s->failed_pc=0x0c0ae0deu; return 0; }
r[0]=read(ram,0x0c0ae178u,4);
goto P_0c0ae0e0;
P_0c0ae0e0: /* original 034c, guest PC 0x0c0ae0e0 */
if(!s->budget--) { s->failed_pc=0x0c0ae0e0u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c0ae0e2;
P_0c0ae0e2: /* original afee, guest PC 0x0c0ae0e2 */
if(!s->budget--) { s->failed_pc=0x0c0ae0e2u; return 0; }
r[6]+=r[3];
goto P_0c0ae0c2;
P_0c0ae0e4: /* original 363c, guest PC 0x0c0ae0e4 */
if(!s->budget--) { s->failed_pc=0x0c0ae0e4u; return 0; }
r[6]+=r[3];
goto P_0c0ae0e6;
P_0c0ae0e6: /* original e000, guest PC 0x0c0ae0e6 */
if(!s->budget--) { s->failed_pc=0x0c0ae0e6u; return 0; }
r[0]=0x00000000u;
goto P_0c0ae0e8;
P_0c0ae0e8: /* original 000b, guest PC 0x0c0ae0e8 */
if(!s->budget--) { s->failed_pc=0x0c0ae0e8u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c0ae0ea: /* original 0009, guest PC 0x0c0ae0ea */
if(!s->budget--) { s->failed_pc=0x0c0ae0eau; return 0; }
if(!vf3_matrix_family(0x0c0ae0ecu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0ae0ecu; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
