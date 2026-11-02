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
int vf3_away_batch25_adapter_39(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c0c5d86u: goto P_0c0c5d86;
case 0x0c0c5d88u: goto P_0c0c5d88;
case 0x0c0c5d8au: goto P_0c0c5d8a;
case 0x0c0c5d8cu: goto P_0c0c5d8c;
case 0x0c0c5d8eu: goto P_0c0c5d8e;
case 0x0c0c5d90u: goto P_0c0c5d90;
case 0x0c0c5d92u: goto P_0c0c5d92;
case 0x0c0c5d94u: goto P_0c0c5d94;
case 0x0c0c5d96u: goto P_0c0c5d96;
case 0x0c0c5d98u: goto P_0c0c5d98;
case 0x0c0c5d9au: goto P_0c0c5d9a;
case 0x0c0c5d9cu: goto P_0c0c5d9c;
case 0x0c0c5d9eu: goto P_0c0c5d9e;
case 0x0c0c5da0u: goto P_0c0c5da0;
case 0x0c0c5da2u: goto P_0c0c5da2;
case 0x0c0c5da4u: goto P_0c0c5da4;
case 0x0c0c5da6u: goto P_0c0c5da6;
case 0x0c0c5da8u: goto P_0c0c5da8;
case 0x0c0c5daau: goto P_0c0c5daa;
case 0x0c0c5dacu: goto P_0c0c5dac;
case 0x0c0c5daeu: goto P_0c0c5dae;
case 0x0c0c5db0u: goto P_0c0c5db0;
case 0x0c0c5db2u: goto P_0c0c5db2;
case 0x0c0c5db4u: goto P_0c0c5db4;
case 0x0c0c5db6u: goto P_0c0c5db6;
case 0x0c0c5db8u: goto P_0c0c5db8;
case 0x0c0c5dbau: goto P_0c0c5dba;
case 0x0c0c5dbcu: goto P_0c0c5dbc;
case 0x0c0c5dbeu: goto P_0c0c5dbe;
case 0x0c0c5dc0u: goto P_0c0c5dc0;
case 0x0c0c5dc2u: goto P_0c0c5dc2;
case 0x0c0c5dc4u: goto P_0c0c5dc4;
case 0x0c0c5dc6u: goto P_0c0c5dc6;
case 0x0c0c5dc8u: goto P_0c0c5dc8;
case 0x0c0c5dcau: goto P_0c0c5dca;
case 0x0c0c5dccu: goto P_0c0c5dcc;
case 0x0c0c5dceu: goto P_0c0c5dce;
case 0x0c0c5dd0u: goto P_0c0c5dd0;
case 0x0c0c5dd2u: goto P_0c0c5dd2;
case 0x0c0c5dd4u: goto P_0c0c5dd4;
case 0x0c0c5dd6u: goto P_0c0c5dd6;
case 0x0c0c5dd8u: goto P_0c0c5dd8;
case 0x0c0c5ddau: goto P_0c0c5dda;
case 0x0c0c5ddcu: goto P_0c0c5ddc;
case 0x0c0c5ddeu: goto P_0c0c5dde;
case 0x0c0c5de0u: goto P_0c0c5de0;
case 0x0c0c5de2u: goto P_0c0c5de2;
case 0x0c0c5de4u: goto P_0c0c5de4;
case 0x0c0c5de6u: goto P_0c0c5de6;
case 0x0c0c5de8u: goto P_0c0c5de8;
case 0x0c0c5deau: goto P_0c0c5dea;
case 0x0c0c5decu: goto P_0c0c5dec;
case 0x0c0c5deeu: goto P_0c0c5dee;
case 0x0c0c5df0u: goto P_0c0c5df0;
case 0x0c0c5df2u: goto P_0c0c5df2;
case 0x0c0c5df4u: goto P_0c0c5df4;
case 0x0c0c5e7au: goto P_0c0c5e7a;
case 0x0c0c5e7cu: goto P_0c0c5e7c;
case 0x0c0c5e7eu: goto P_0c0c5e7e;
case 0x0c0c5e80u: goto P_0c0c5e80;
case 0x0c0c5e82u: goto P_0c0c5e82;
case 0x0c0c5e84u: goto P_0c0c5e84;
case 0x0c0c5e86u: goto P_0c0c5e86;
case 0x0c0c5e88u: goto P_0c0c5e88;
case 0x0c0c5e8au: goto P_0c0c5e8a;
case 0x0c0c5e8cu: goto P_0c0c5e8c;
case 0x0c0c5e8eu: goto P_0c0c5e8e;
case 0x0c0c5e90u: goto P_0c0c5e90;
case 0x0c0c5e92u: goto P_0c0c5e92;
case 0x0c0c5e94u: goto P_0c0c5e94;
case 0x0c0c5e96u: goto P_0c0c5e96;
case 0x0c0c5e98u: goto P_0c0c5e98;
case 0x0c0c5e9au: goto P_0c0c5e9a;
case 0x0c0c5e9cu: goto P_0c0c5e9c;
case 0x0c0c5e9eu: goto P_0c0c5e9e;
case 0x0c0c5ea0u: goto P_0c0c5ea0;
case 0x0c0c5ea2u: goto P_0c0c5ea2;
case 0x0c0c5ea4u: goto P_0c0c5ea4;
case 0x0c0c5ea6u: goto P_0c0c5ea6;
case 0x0c0c5ea8u: goto P_0c0c5ea8;
case 0x0c0c5eaau: goto P_0c0c5eaa;
case 0x0c0c5eacu: goto P_0c0c5eac;
case 0x0c0c5eaeu: goto P_0c0c5eae;
case 0x0c0c5eb0u: goto P_0c0c5eb0;
case 0x0c0c5eb2u: goto P_0c0c5eb2;
case 0x0c0c5eb4u: goto P_0c0c5eb4;
case 0x0c0c5eb6u: goto P_0c0c5eb6;
case 0x0c0c5eb8u: goto P_0c0c5eb8;
case 0x0c0c5ebau: goto P_0c0c5eba;
case 0x0c0c5ebcu: goto P_0c0c5ebc;
case 0x0c0c5ebeu: goto P_0c0c5ebe;
case 0x0c0c5ec0u: goto P_0c0c5ec0;
case 0x0c0c5ec2u: goto P_0c0c5ec2;
case 0x0c0c5ec4u: goto P_0c0c5ec4;
case 0x0c0c5ec6u: goto P_0c0c5ec6;
case 0x0c0c5ec8u: goto P_0c0c5ec8;
case 0x0c0c5ecau: goto P_0c0c5eca;
case 0x0c0c5eccu: goto P_0c0c5ecc;
case 0x0c0c5eceu: goto P_0c0c5ece;
case 0x0c0c5ed0u: goto P_0c0c5ed0;
case 0x0c0c5ed2u: goto P_0c0c5ed2;
case 0x0c0c5ed4u: goto P_0c0c5ed4;
case 0x0c0c5ed6u: goto P_0c0c5ed6;
case 0x0c0c5ed8u: goto P_0c0c5ed8;
case 0x0c0c5edau: goto P_0c0c5eda;
case 0x0c0c5edcu: goto P_0c0c5edc;
case 0x0c0c5edeu: goto P_0c0c5ede;
case 0x0c0c5ee0u: goto P_0c0c5ee0;
case 0x0c0c5ee2u: goto P_0c0c5ee2;
case 0x0c0c5ee4u: goto P_0c0c5ee4;
case 0x0c0c5ee6u: goto P_0c0c5ee6;
case 0x0c0c5ee8u: goto P_0c0c5ee8;
case 0x0c0c5eeau: goto P_0c0c5eea;
case 0x0c0c5eecu: goto P_0c0c5eec;
case 0x0c0c5eeeu: goto P_0c0c5eee;
case 0x0c0c5ef0u: goto P_0c0c5ef0;
case 0x0c0c5ef2u: goto P_0c0c5ef2;
case 0x0c0c5ef4u: goto P_0c0c5ef4;
case 0x0c0c5ef6u: goto P_0c0c5ef6;
case 0x0c0c5ef8u: goto P_0c0c5ef8;
case 0x0c0c5efau: goto P_0c0c5efa;
case 0x0c0c5efcu: goto P_0c0c5efc;
case 0x0c0c5efeu: goto P_0c0c5efe;
case 0x0c0c5f00u: goto P_0c0c5f00;
case 0x0c0c5f02u: goto P_0c0c5f02;
case 0x0c0c5f04u: goto P_0c0c5f04;
case 0x0c0c5f06u: goto P_0c0c5f06;
case 0x0c0c5f08u: goto P_0c0c5f08;
case 0x0c0c5f0au: goto P_0c0c5f0a;
case 0x0c0c5f0cu: goto P_0c0c5f0c;
case 0x0c0c5f0eu: goto P_0c0c5f0e;
case 0x0c0c5f10u: goto P_0c0c5f10;
case 0x0c0c600cu: goto P_0c0c600c;
case 0x0c0c600eu: goto P_0c0c600e;
case 0x0c0c6010u: goto P_0c0c6010;
case 0x0c0c6012u: goto P_0c0c6012;
case 0x0c0c6014u: goto P_0c0c6014;
case 0x0c0c6016u: goto P_0c0c6016;
case 0x0c0c6018u: goto P_0c0c6018;
case 0x0c0c601au: goto P_0c0c601a;
case 0x0c0c601cu: goto P_0c0c601c;
case 0x0c0c601eu: goto P_0c0c601e;
case 0x0c0c6020u: goto P_0c0c6020;
case 0x0c0c6022u: goto P_0c0c6022;
case 0x0c0c6024u: goto P_0c0c6024;
case 0x0c0c6026u: goto P_0c0c6026;
case 0x0c0c6028u: goto P_0c0c6028;
case 0x0c0c602au: goto P_0c0c602a;
case 0x0c0c602cu: goto P_0c0c602c;
case 0x0c0c602eu: goto P_0c0c602e;
case 0x0c0c6030u: goto P_0c0c6030;
case 0x0c0c6032u: goto P_0c0c6032;
case 0x0c0c6034u: goto P_0c0c6034;
case 0x0c0c6036u: goto P_0c0c6036;
case 0x0c0c6038u: goto P_0c0c6038;
case 0x0c0c603au: goto P_0c0c603a;
case 0x0c0c603cu: goto P_0c0c603c;
case 0x0c0c603eu: goto P_0c0c603e;
case 0x0c0c6040u: goto P_0c0c6040;
case 0x0c0c6042u: goto P_0c0c6042;
case 0x0c0c6044u: goto P_0c0c6044;
case 0x0c0c6046u: goto P_0c0c6046;
case 0x0c0c6048u: goto P_0c0c6048;
case 0x0c0c604au: goto P_0c0c604a;
case 0x0c0c604cu: goto P_0c0c604c;
case 0x0c0c604eu: goto P_0c0c604e;
case 0x0c0c6050u: goto P_0c0c6050;
case 0x0c0c6052u: goto P_0c0c6052;
case 0x0c0c6054u: goto P_0c0c6054;
case 0x0c0c6056u: goto P_0c0c6056;
case 0x0c0c6058u: goto P_0c0c6058;
case 0x0c0c605au: goto P_0c0c605a;
case 0x0c0c605cu: goto P_0c0c605c;
case 0x0c0c605eu: goto P_0c0c605e;
case 0x0c0c6060u: goto P_0c0c6060;
case 0x0c0c6062u: goto P_0c0c6062;
case 0x0c0c6064u: goto P_0c0c6064;
case 0x0c0c6066u: goto P_0c0c6066;
case 0x0c0c6068u: goto P_0c0c6068;
case 0x0c0c606au: goto P_0c0c606a;
case 0x0c0c606cu: goto P_0c0c606c;
case 0x0c0c606eu: goto P_0c0c606e;
case 0x0c0c6070u: goto P_0c0c6070;
case 0x0c0c6072u: goto P_0c0c6072;
case 0x0c0c6074u: goto P_0c0c6074;
case 0x0c0c6076u: goto P_0c0c6076;
case 0x0c0c6078u: goto P_0c0c6078;
case 0x0c0c607au: goto P_0c0c607a;
case 0x0c0c607cu: goto P_0c0c607c;
case 0x0c0c607eu: goto P_0c0c607e;
case 0x0c0c6080u: goto P_0c0c6080;
case 0x0c0c6082u: goto P_0c0c6082;
case 0x0c0c6084u: goto P_0c0c6084;
case 0x0c0c6086u: goto P_0c0c6086;
case 0x0c0c6088u: goto P_0c0c6088;
case 0x0c0c608au: goto P_0c0c608a;
case 0x0c0c608cu: goto P_0c0c608c;
case 0x0c0c608eu: goto P_0c0c608e;
case 0x0c0c6090u: goto P_0c0c6090;
case 0x0c0c6092u: goto P_0c0c6092;
case 0x0c0c6094u: goto P_0c0c6094;
case 0x0c0c6096u: goto P_0c0c6096;
case 0x0c0c6098u: goto P_0c0c6098;
case 0x0c0c609au: goto P_0c0c609a;
case 0x0c0c609cu: goto P_0c0c609c;
case 0x0c0c609eu: goto P_0c0c609e;
case 0x0c0c60a0u: goto P_0c0c60a0;
case 0x0c0c60a2u: goto P_0c0c60a2;
case 0x0c0c60a4u: goto P_0c0c60a4;
case 0x0c0c60a6u: goto P_0c0c60a6;
case 0x0c0c60a8u: goto P_0c0c60a8;
case 0x0c0c60aau: goto P_0c0c60aa;
case 0x0c0c60acu: goto P_0c0c60ac;
case 0x0c0c60aeu: goto P_0c0c60ae;
case 0x0c0c60b0u: goto P_0c0c60b0;
case 0x0c0c60b2u: goto P_0c0c60b2;
case 0x0c0c60b4u: goto P_0c0c60b4;
case 0x0c0c60b6u: goto P_0c0c60b6;
case 0x0c0c60b8u: goto P_0c0c60b8;
case 0x0c0c60bau: goto P_0c0c60ba;
case 0x0c0c60bcu: goto P_0c0c60bc;
case 0x0c0c60beu: goto P_0c0c60be;
default: return vf3_matrix_family(target,s,ram);
}
P_0c0c5d86: /* original 4f22, guest PC 0x0c0c5d86 */
if(!s->budget--) { s->failed_pc=0x0c0c5d86u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0c5d88;
P_0c0c5d88: /* original 7ff8, guest PC 0x0c0c5d88 */
if(!s->budget--) { s->failed_pc=0x0c0c5d88u; return 0; }
r[15]+=0xfffffff8u;
goto P_0c0c5d8a;
P_0c0c5d8a: /* original 2f42, guest PC 0x0c0c5d8a */
if(!s->budget--) { s->failed_pc=0x0c0c5d8au; return 0; }
write(ram,r[15],r[4],4);
goto P_0c0c5d8c;
P_0c0c5d8c: /* original d421, guest PC 0x0c0c5d8c */
if(!s->budget--) { s->failed_pc=0x0c0c5d8cu; return 0; }
r[4]=read(ram,0x0c0c5e14u,4);
goto P_0c0c5d8e;
P_0c0c5d8e: /* original d322, guest PC 0x0c0c5d8e */
if(!s->budget--) { s->failed_pc=0x0c0c5d8eu; return 0; }
r[3]=read(ram,0x0c0c5e18u,4);
goto P_0c0c5d90;
P_0c0c5d90: /* original 1f31, guest PC 0x0c0c5d90 */
if(!s->budget--) { s->failed_pc=0x0c0c5d90u; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c0c5d92;
P_0c0c5d92: /* original 8448, guest PC 0x0c0c5d92 */
if(!s->budget--) { s->failed_pc=0x0c0c5d92u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+8,1);
goto P_0c0c5d94;
P_0c0c5d94: /* original 600c, guest PC 0x0c0c5d94 */
if(!s->budget--) { s->failed_pc=0x0c0c5d94u; return 0; }
r[0]=r[0]&255u;
goto P_0c0c5d96;
P_0c0c5d96: /* original 8803, guest PC 0x0c0c5d96 */
if(!s->budget--) { s->failed_pc=0x0c0c5d96u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000003u)!=0);
goto P_0c0c5d98;
P_0c0c5d98: /* original 8f07, guest PC 0x0c0c5d98 */
if(!s->budget--) { s->failed_pc=0x0c0c5d98u; return 0; }
cond=r[17]&1u;
r[4]=r[0];
if(!cond) { goto P_0c0c5daa; }
goto P_0c0c5d9c;
P_0c0c5d9a: /* original 6403, guest PC 0x0c0c5d9a */
if(!s->budget--) { s->failed_pc=0x0c0c5d9au; return 0; }
r[4]=r[0];
goto P_0c0c5d9c;
P_0c0c5d9c: /* original d31f, guest PC 0x0c0c5d9c */
if(!s->budget--) { s->failed_pc=0x0c0c5d9cu; return 0; }
r[3]=read(ram,0x0c0c5e1cu,4);
goto P_0c0c5d9e;
P_0c0c5d9e: /* original 54f1, guest PC 0x0c0c5d9e */
if(!s->budget--) { s->failed_pc=0x0c0c5d9eu; return 0; }
r[4]=read(ram,r[15]+4,4);
goto P_0c0c5da0;
P_0c0c5da0: /* original 430b, guest PC 0x0c0c5da0 */
if(!s->budget--) { s->failed_pc=0x0c0c5da0u; return 0; }
target=r[3];
r[16]=code_base|0x0c0c5da4u;
r[4]+=0x00000003u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c5da4u) { target=s->pc; goto dispatch; }
goto P_0c0c5da4;
P_0c0c5da2: /* original 7403, guest PC 0x0c0c5da2 */
if(!s->budget--) { s->failed_pc=0x0c0c5da2u; return 0; }
r[4]+=0x00000003u;
goto P_0c0c5da4;
P_0c0c5da4: /* original 640c, guest PC 0x0c0c5da4 */
if(!s->budget--) { s->failed_pc=0x0c0c5da4u; return 0; }
r[4]=r[0]&255u;
goto P_0c0c5da6;
P_0c0c5da6: /* original 2448, guest PC 0x0c0c5da6 */
if(!s->budget--) { s->failed_pc=0x0c0c5da6u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c0c5da8;
P_0c0c5da8: /* original 8b03, guest PC 0x0c0c5da8 */
if(!s->budget--) { s->failed_pc=0x0c0c5da8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c5db2; }
goto P_0c0c5daa;
P_0c0c5daa: /* original 64f2, guest PC 0x0c0c5daa */
if(!s->budget--) { s->failed_pc=0x0c0c5daau; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c0c5dac;
P_0c0c5dac: /* original 7f08, guest PC 0x0c0c5dac */
if(!s->budget--) { s->failed_pc=0x0c0c5dacu; return 0; }
r[15]+=0x00000008u;
goto P_0c0c5dae;
P_0c0c5dae: /* original a004, guest PC 0x0c0c5dae */
if(!s->budget--) { s->failed_pc=0x0c0c5daeu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0c5dba;
P_0c0c5db0: /* original 4f26, guest PC 0x0c0c5db0 */
if(!s->budget--) { s->failed_pc=0x0c0c5db0u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0c5db2;
P_0c0c5db2: /* original 7f08, guest PC 0x0c0c5db2 */
if(!s->budget--) { s->failed_pc=0x0c0c5db2u; return 0; }
r[15]+=0x00000008u;
goto P_0c0c5db4;
P_0c0c5db4: /* original 4f26, guest PC 0x0c0c5db4 */
if(!s->budget--) { s->failed_pc=0x0c0c5db4u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0c5db6;
P_0c0c5db6: /* original 000b, guest PC 0x0c0c5db6 */
if(!s->budget--) { s->failed_pc=0x0c0c5db6u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c0c5db8: /* original 0009, guest PC 0x0c0c5db8 */
if(!s->budget--) { s->failed_pc=0x0c0c5db8u; return 0; }
goto P_0c0c5dba;
P_0c0c5dba: /* original 2fe6, guest PC 0x0c0c5dba */
if(!s->budget--) { s->failed_pc=0x0c0c5dbau; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c5dbc;
P_0c0c5dbc: /* original 4411, guest PC 0x0c0c5dbc */
if(!s->budget--) { s->failed_pc=0x0c0c5dbcu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=0)!=0);
goto P_0c0c5dbe;
P_0c0c5dbe: /* original 4f22, guest PC 0x0c0c5dbe */
if(!s->budget--) { s->failed_pc=0x0c0c5dbeu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0c5dc0;
P_0c0c5dc0: /* original d517, guest PC 0x0c0c5dc0 */
if(!s->budget--) { s->failed_pc=0x0c0c5dc0u; return 0; }
r[5]=read(ram,0x0c0c5e20u,4);
goto P_0c0c5dc2;
P_0c0c5dc2: /* original 8b15, guest PC 0x0c0c5dc2 */
if(!s->budget--) { s->failed_pc=0x0c0c5dc2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c5df0; }
goto P_0c0c5dc4;
P_0c0c5dc4: /* original 921c, guest PC 0x0c0c5dc4 */
if(!s->budget--) { s->failed_pc=0x0c0c5dc4u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c5e00u,2);
goto P_0c0c5dc6;
P_0c0c5dc6: /* original 3423, guest PC 0x0c0c5dc6 */
if(!s->budget--) { s->failed_pc=0x0c0c5dc6u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=(int32_t)r[2])!=0);
goto P_0c0c5dc8;
P_0c0c5dc8: /* original 8912, guest PC 0x0c0c5dc8 */
if(!s->budget--) { s->failed_pc=0x0c0c5dc8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c5df0; }
goto P_0c0c5dca;
P_0c0c5dca: /* original d016, guest PC 0x0c0c5dca */
if(!s->budget--) { s->failed_pc=0x0c0c5dcau; return 0; }
r[0]=read(ram,0x0c0c5e24u,4);
goto P_0c0c5dcc;
P_0c0c5dcc: /* original 4408, guest PC 0x0c0c5dcc */
if(!s->budget--) { s->failed_pc=0x0c0c5dccu; return 0; }
r[4]<<=2;
goto P_0c0c5dce;
P_0c0c5dce: /* original 6e43, guest PC 0x0c0c5dce */
if(!s->budget--) { s->failed_pc=0x0c0c5dceu; return 0; }
r[14]=r[4];
goto P_0c0c5dd0;
P_0c0c5dd0: /* original 03ee, guest PC 0x0c0c5dd0 */
if(!s->budget--) { s->failed_pc=0x0c0c5dd0u; return 0; }
r[3]=read(ram,r[14]+r[0],4);
goto P_0c0c5dd2;
P_0c0c5dd2: /* original 4311, guest PC 0x0c0c5dd2 */
if(!s->budget--) { s->failed_pc=0x0c0c5dd2u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>=0)!=0);
goto P_0c0c5dd4;
P_0c0c5dd4: /* original 8b0c, guest PC 0x0c0c5dd4 */
if(!s->budget--) { s->failed_pc=0x0c0c5dd4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c5df0; }
goto P_0c0c5dd6;
P_0c0c5dd6: /* original d414, guest PC 0x0c0c5dd6 */
if(!s->budget--) { s->failed_pc=0x0c0c5dd6u; return 0; }
r[4]=read(ram,0x0c0c5e28u,4);
goto P_0c0c5dd8;
P_0c0c5dd8: /* original 60e3, guest PC 0x0c0c5dd8 */
if(!s->budget--) { s->failed_pc=0x0c0c5dd8u; return 0; }
r[0]=r[14];
goto P_0c0c5dda;
P_0c0c5dda: /* original 6252, guest PC 0x0c0c5dda */
if(!s->budget--) { s->failed_pc=0x0c0c5ddau; return 0; }
tmp=read(ram,r[5],4);
r[2]=tmp;
goto P_0c0c5ddc;
P_0c0c5ddc: /* original 034e, guest PC 0x0c0c5ddc */
if(!s->budget--) { s->failed_pc=0x0c0c5ddcu; return 0; }
r[3]=read(ram,r[4]+r[0],4);
goto P_0c0c5dde;
P_0c0c5dde: /* original 3320, guest PC 0x0c0c5dde */
if(!s->budget--) { s->failed_pc=0x0c0c5ddeu; return 0; }
r[17]=(r[17]&~1u)|((r[3]==r[2])!=0);
goto P_0c0c5de0;
P_0c0c5de0: /* original 8906, guest PC 0x0c0c5de0 */
if(!s->budget--) { s->failed_pc=0x0c0c5de0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c5df0; }
goto P_0c0c5de2;
P_0c0c5de2: /* original 6352, guest PC 0x0c0c5de2 */
if(!s->budget--) { s->failed_pc=0x0c0c5de2u; return 0; }
tmp=read(ram,r[5],4);
r[3]=tmp;
goto P_0c0c5de4;
P_0c0c5de4: /* original 60e3, guest PC 0x0c0c5de4 */
if(!s->budget--) { s->failed_pc=0x0c0c5de4u; return 0; }
r[0]=r[14];
goto P_0c0c5de6;
P_0c0c5de6: /* original 0436, guest PC 0x0c0c5de6 */
if(!s->budget--) { s->failed_pc=0x0c0c5de6u; return 0; }
write(ram,r[4]+r[0],r[3],4);
goto P_0c0c5de8;
P_0c0c5de8: /* original d310, guest PC 0x0c0c5de8 */
if(!s->budget--) { s->failed_pc=0x0c0c5de8u; return 0; }
r[3]=read(ram,0x0c0c5e2cu,4);
goto P_0c0c5dea;
P_0c0c5dea: /* original d00e, guest PC 0x0c0c5dea */
if(!s->budget--) { s->failed_pc=0x0c0c5deau; return 0; }
r[0]=read(ram,0x0c0c5e24u,4);
goto P_0c0c5dec;
P_0c0c5dec: /* original 430b, guest PC 0x0c0c5dec */
if(!s->budget--) { s->failed_pc=0x0c0c5decu; return 0; }
target=r[3];
r[16]=code_base|0x0c0c5df0u;
r[4]=read(ram,r[14]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c5df0u) { target=s->pc; goto dispatch; }
goto P_0c0c5df0;
P_0c0c5dee: /* original 04ee, guest PC 0x0c0c5dee */
if(!s->budget--) { s->failed_pc=0x0c0c5deeu; return 0; }
r[4]=read(ram,r[14]+r[0],4);
goto P_0c0c5df0;
P_0c0c5df0: /* original 4f26, guest PC 0x0c0c5df0 */
if(!s->budget--) { s->failed_pc=0x0c0c5df0u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0c5df2;
P_0c0c5df2: /* original 000b, guest PC 0x0c0c5df2 */
if(!s->budget--) { s->failed_pc=0x0c0c5df2u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0c5df4: /* original 6ef6, guest PC 0x0c0c5df4 */
if(!s->budget--) { s->failed_pc=0x0c0c5df4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0c5df6u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0c5df6u; return 0; } return 1;
P_0c0c5e7a: /* original 2fe6, guest PC 0x0c0c5e7a */
if(!s->budget--) { s->failed_pc=0x0c0c5e7au; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c5e7c;
P_0c0c5e7c: /* original e705, guest PC 0x0c0c5e7c */
if(!s->budget--) { s->failed_pc=0x0c0c5e7cu; return 0; }
r[7]=0x00000005u;
goto P_0c0c5e7e;
P_0c0c5e7e: /* original 2fd6, guest PC 0x0c0c5e7e */
if(!s->budget--) { s->failed_pc=0x0c0c5e7eu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c5e80;
P_0c0c5e80: /* original ee06, guest PC 0x0c0c5e80 */
if(!s->budget--) { s->failed_pc=0x0c0c5e80u; return 0; }
r[14]=0x00000006u;
goto P_0c0c5e82;
P_0c0c5e82: /* original 2fc6, guest PC 0x0c0c5e82 */
if(!s->budget--) { s->failed_pc=0x0c0c5e82u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c5e84;
P_0c0c5e84: /* original 6573, guest PC 0x0c0c5e84 */
if(!s->budget--) { s->failed_pc=0x0c0c5e84u; return 0; }
r[5]=r[7];
goto P_0c0c5e86;
P_0c0c5e86: /* original 4f22, guest PC 0x0c0c5e86 */
if(!s->budget--) { s->failed_pc=0x0c0c5e86u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0c5e88;
P_0c0c5e88: /* original d425, guest PC 0x0c0c5e88 */
if(!s->budget--) { s->failed_pc=0x0c0c5e88u; return 0; }
r[4]=read(ram,0x0c0c5f20u,4);
goto P_0c0c5e8a;
P_0c0c5e8a: /* original e600, guest PC 0x0c0c5e8a */
if(!s->budget--) { s->failed_pc=0x0c0c5e8au; return 0; }
r[6]=0x00000000u;
goto P_0c0c5e8c;
P_0c0c5e8c: /* original 7501, guest PC 0x0c0c5e8c */
if(!s->budget--) { s->failed_pc=0x0c0c5e8cu; return 0; }
r[5]+=0x00000001u;
goto P_0c0c5e8e;
P_0c0c5e8e: /* original 2462, guest PC 0x0c0c5e8e */
if(!s->budget--) { s->failed_pc=0x0c0c5e8eu; return 0; }
write(ram,r[4],r[6],4);
goto P_0c0c5e90;
P_0c0c5e90: /* original 35e7, guest PC 0x0c0c5e90 */
if(!s->budget--) { s->failed_pc=0x0c0c5e90u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[5]>(int32_t)r[14])!=0);
goto P_0c0c5e92;
P_0c0c5e92: /* original 8ffb, guest PC 0x0c0c5e92 */
if(!s->budget--) { s->failed_pc=0x0c0c5e92u; return 0; }
cond=r[17]&1u;
r[4]+=0x00000004u;
if(!cond) { goto P_0c0c5e8c; }
goto P_0c0c5e96;
P_0c0c5e94: /* original 7404, guest PC 0x0c0c5e94 */
if(!s->budget--) { s->failed_pc=0x0c0c5e94u; return 0; }
r[4]+=0x00000004u;
goto P_0c0c5e96;
P_0c0c5e96: /* original dc21, guest PC 0x0c0c5e96 */
if(!s->budget--) { s->failed_pc=0x0c0c5e96u; return 0; }
r[12]=read(ram,0x0c0c5f1cu,4);
goto P_0c0c5e98;
P_0c0c5e98: /* original 6d73, guest PC 0x0c0c5e98 */
if(!s->budget--) { s->failed_pc=0x0c0c5e98u; return 0; }
r[13]=r[7];
goto P_0c0c5e9a;
P_0c0c5e9a: /* original 4c0b, guest PC 0x0c0c5e9a */
if(!s->budget--) { s->failed_pc=0x0c0c5e9au; return 0; }
target=r[12];
r[16]=code_base|0x0c0c5e9eu;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c5e9eu) { target=s->pc; goto dispatch; }
goto P_0c0c5e9e;
P_0c0c5e9c: /* original 64d3, guest PC 0x0c0c5e9c */
if(!s->budget--) { s->failed_pc=0x0c0c5e9cu; return 0; }
r[4]=r[13];
goto P_0c0c5e9e;
P_0c0c5e9e: /* original 7d01, guest PC 0x0c0c5e9e */
if(!s->budget--) { s->failed_pc=0x0c0c5e9eu; return 0; }
r[13]+=0x00000001u;
goto P_0c0c5ea0;
P_0c0c5ea0: /* original 3de7, guest PC 0x0c0c5ea0 */
if(!s->budget--) { s->failed_pc=0x0c0c5ea0u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[13]>(int32_t)r[14])!=0);
goto P_0c0c5ea2;
P_0c0c5ea2: /* original 8bfa, guest PC 0x0c0c5ea2 */
if(!s->budget--) { s->failed_pc=0x0c0c5ea2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c5e9a; }
goto P_0c0c5ea4;
P_0c0c5ea4: /* original 4f26, guest PC 0x0c0c5ea4 */
if(!s->budget--) { s->failed_pc=0x0c0c5ea4u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0c5ea6;
P_0c0c5ea6: /* original 6cf6, guest PC 0x0c0c5ea6 */
if(!s->budget--) { s->failed_pc=0x0c0c5ea6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0c5ea8;
P_0c0c5ea8: /* original 6df6, guest PC 0x0c0c5ea8 */
if(!s->budget--) { s->failed_pc=0x0c0c5ea8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0c5eaa;
P_0c0c5eaa: /* original 000b, guest PC 0x0c0c5eaa */
if(!s->budget--) { s->failed_pc=0x0c0c5eaau; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0c5eac: /* original 6ef6, guest PC 0x0c0c5eac */
if(!s->budget--) { s->failed_pc=0x0c0c5eacu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0c5eae;
P_0c0c5eae: /* original 2fe6, guest PC 0x0c0c5eae */
if(!s->budget--) { s->failed_pc=0x0c0c5eaeu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c5eb0;
P_0c0c5eb0: /* original 2fd6, guest PC 0x0c0c5eb0 */
if(!s->budget--) { s->failed_pc=0x0c0c5eb0u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c5eb2;
P_0c0c5eb2: /* original ed1f, guest PC 0x0c0c5eb2 */
if(!s->budget--) { s->failed_pc=0x0c0c5eb2u; return 0; }
r[13]=0x0000001fu;
goto P_0c0c5eb4;
P_0c0c5eb4: /* original 2d49, guest PC 0x0c0c5eb4 */
if(!s->budget--) { s->failed_pc=0x0c0c5eb4u; return 0; }
r[13]&=r[4];
goto P_0c0c5eb6;
P_0c0c5eb6: /* original d31b, guest PC 0x0c0c5eb6 */
if(!s->budget--) { s->failed_pc=0x0c0c5eb6u; return 0; }
r[3]=read(ram,0x0c0c5f24u,4);
goto P_0c0c5eb8;
P_0c0c5eb8: /* original 4d00, guest PC 0x0c0c5eb8 */
if(!s->budget--) { s->failed_pc=0x0c0c5eb8u; return 0; }
r[17]=(r[17]&~1u)|((r[13]>>31)!=0);
r[13]<<=1;
goto P_0c0c5eba;
P_0c0c5eba: /* original 6ed3, guest PC 0x0c0c5eba */
if(!s->budget--) { s->failed_pc=0x0c0c5ebau; return 0; }
r[14]=r[13];
goto P_0c0c5ebc;
P_0c0c5ebc: /* original 4e08, guest PC 0x0c0c5ebc */
if(!s->budget--) { s->failed_pc=0x0c0c5ebcu; return 0; }
r[14]<<=2;
goto P_0c0c5ebe;
P_0c0c5ebe: /* original 3e3c, guest PC 0x0c0c5ebe */
if(!s->budget--) { s->failed_pc=0x0c0c5ebeu; return 0; }
r[14]+=r[3];
goto P_0c0c5ec0;
P_0c0c5ec0: /* original 62e2, guest PC 0x0c0c5ec0 */
if(!s->budget--) { s->failed_pc=0x0c0c5ec0u; return 0; }
tmp=read(ram,r[14],4);
r[2]=tmp;
goto P_0c0c5ec2;
P_0c0c5ec2: /* original 4f22, guest PC 0x0c0c5ec2 */
if(!s->budget--) { s->failed_pc=0x0c0c5ec2u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0c5ec4;
P_0c0c5ec4: /* original 2228, guest PC 0x0c0c5ec4 */
if(!s->budget--) { s->failed_pc=0x0c0c5ec4u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c0c5ec6;
P_0c0c5ec6: /* original 8920, guest PC 0x0c0c5ec6 */
if(!s->budget--) { s->failed_pc=0x0c0c5ec6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c5f0a; }
goto P_0c0c5ec8;
P_0c0c5ec8: /* original d217, guest PC 0x0c0c5ec8 */
if(!s->budget--) { s->failed_pc=0x0c0c5ec8u; return 0; }
r[2]=read(ram,0x0c0c5f28u,4);
goto P_0c0c5eca;
P_0c0c5eca: /* original 61e2, guest PC 0x0c0c5eca */
if(!s->budget--) { s->failed_pc=0x0c0c5ecau; return 0; }
tmp=read(ram,r[14],4);
r[1]=tmp;
goto P_0c0c5ecc;
P_0c0c5ecc: /* original 6022, guest PC 0x0c0c5ecc */
if(!s->budget--) { s->failed_pc=0x0c0c5eccu; return 0; }
tmp=read(ram,r[2],4);
r[0]=tmp;
goto P_0c0c5ece;
P_0c0c5ece: /* original 3010, guest PC 0x0c0c5ece */
if(!s->budget--) { s->failed_pc=0x0c0c5eceu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==r[1])!=0);
goto P_0c0c5ed0;
P_0c0c5ed0: /* original 891b, guest PC 0x0c0c5ed0 */
if(!s->budget--) { s->failed_pc=0x0c0c5ed0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c5f0a; }
goto P_0c0c5ed2;
P_0c0c5ed2: /* original d317, guest PC 0x0c0c5ed2 */
if(!s->budget--) { s->failed_pc=0x0c0c5ed2u; return 0; }
r[3]=read(ram,0x0c0c5f30u,4);
goto P_0c0c5ed4;
P_0c0c5ed4: /* original d115, guest PC 0x0c0c5ed4 */
if(!s->budget--) { s->failed_pc=0x0c0c5ed4u; return 0; }
r[1]=read(ram,0x0c0c5f2cu,4);
goto P_0c0c5ed6;
P_0c0c5ed6: /* original 6532, guest PC 0x0c0c5ed6 */
if(!s->budget--) { s->failed_pc=0x0c0c5ed6u; return 0; }
tmp=read(ram,r[3],4);
r[5]=tmp;
goto P_0c0c5ed8;
P_0c0c5ed8: /* original d216, guest PC 0x0c0c5ed8 */
if(!s->budget--) { s->failed_pc=0x0c0c5ed8u; return 0; }
r[2]=read(ram,0x0c0c5f34u,4);
goto P_0c0c5eda;
P_0c0c5eda: /* original 351c, guest PC 0x0c0c5eda */
if(!s->budget--) { s->failed_pc=0x0c0c5edau; return 0; }
r[5]+=r[1];
goto P_0c0c5edc;
P_0c0c5edc: /* original 420b, guest PC 0x0c0c5edc */
if(!s->budget--) { s->failed_pc=0x0c0c5edcu; return 0; }
target=r[2];
r[16]=code_base|0x0c0c5ee0u;
tmp=read(ram,r[14],4);
r[4]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c5ee0u) { target=s->pc; goto dispatch; }
goto P_0c0c5ee0;
P_0c0c5ede: /* original 64e2, guest PC 0x0c0c5ede */
if(!s->budget--) { s->failed_pc=0x0c0c5edeu; return 0; }
tmp=read(ram,r[14],4);
r[4]=tmp;
goto P_0c0c5ee0;
P_0c0c5ee0: /* original d30e, guest PC 0x0c0c5ee0 */
if(!s->budget--) { s->failed_pc=0x0c0c5ee0u; return 0; }
r[3]=read(ram,0x0c0c5f1cu,4);
goto P_0c0c5ee2;
P_0c0c5ee2: /* original 430b, guest PC 0x0c0c5ee2 */
if(!s->budget--) { s->failed_pc=0x0c0c5ee2u; return 0; }
target=r[3];
r[16]=code_base|0x0c0c5ee6u;
r[4]=0x00000004u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c5ee6u) { target=s->pc; goto dispatch; }
goto P_0c0c5ee6;
P_0c0c5ee4: /* original e404, guest PC 0x0c0c5ee4 */
if(!s->budget--) { s->failed_pc=0x0c0c5ee4u; return 0; }
r[4]=0x00000004u;
goto P_0c0c5ee6;
P_0c0c5ee6: /* original d212, guest PC 0x0c0c5ee6 */
if(!s->budget--) { s->failed_pc=0x0c0c5ee6u; return 0; }
r[2]=read(ram,0x0c0c5f30u,4);
goto P_0c0c5ee8;
P_0c0c5ee8: /* original e504, guest PC 0x0c0c5ee8 */
if(!s->budget--) { s->failed_pc=0x0c0c5ee8u; return 0; }
r[5]=0x00000004u;
goto P_0c0c5eea;
P_0c0c5eea: /* original d113, guest PC 0x0c0c5eea */
if(!s->budget--) { s->failed_pc=0x0c0c5eeau; return 0; }
r[1]=read(ram,0x0c0c5f38u,4);
goto P_0c0c5eec;
P_0c0c5eec: /* original 6422, guest PC 0x0c0c5eec */
if(!s->budget--) { s->failed_pc=0x0c0c5eecu; return 0; }
tmp=read(ram,r[2],4);
r[4]=tmp;
goto P_0c0c5eee;
P_0c0c5eee: /* original d30f, guest PC 0x0c0c5eee */
if(!s->budget--) { s->failed_pc=0x0c0c5eeeu; return 0; }
r[3]=read(ram,0x0c0c5f2cu,4);
goto P_0c0c5ef0;
P_0c0c5ef0: /* original 410b, guest PC 0x0c0c5ef0 */
if(!s->budget--) { s->failed_pc=0x0c0c5ef0u; return 0; }
target=r[1];
r[16]=code_base|0x0c0c5ef4u;
r[4]+=r[3];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c5ef4u) { target=s->pc; goto dispatch; }
goto P_0c0c5ef4;
P_0c0c5ef2: /* original 343c, guest PC 0x0c0c5ef2 */
if(!s->budget--) { s->failed_pc=0x0c0c5ef2u; return 0; }
r[4]+=r[3];
goto P_0c0c5ef4;
P_0c0c5ef4: /* original 2008, guest PC 0x0c0c5ef4 */
if(!s->budget--) { s->failed_pc=0x0c0c5ef4u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c0c5ef6;
P_0c0c5ef6: /* original 8903, guest PC 0x0c0c5ef6 */
if(!s->budget--) { s->failed_pc=0x0c0c5ef6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c5f00; }
goto P_0c0c5ef8;
P_0c0c5ef8: /* original d210, guest PC 0x0c0c5ef8 */
if(!s->budget--) { s->failed_pc=0x0c0c5ef8u; return 0; }
r[2]=read(ram,0x0c0c5f3cu,4);
goto P_0c0c5efa;
P_0c0c5efa: /* original 950a, guest PC 0x0c0c5efa */
if(!s->budget--) { s->failed_pc=0x0c0c5efau; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c5f12u,2);
goto P_0c0c5efc;
P_0c0c5efc: /* original 420b, guest PC 0x0c0c5efc */
if(!s->budget--) { s->failed_pc=0x0c0c5efcu; return 0; }
target=r[2];
r[16]=code_base|0x0c0c5f00u;
r[4]=0x00000001u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c5f00u) { target=s->pc; goto dispatch; }
goto P_0c0c5f00;
P_0c0c5efe: /* original e401, guest PC 0x0c0c5efe */
if(!s->budget--) { s->failed_pc=0x0c0c5efeu; return 0; }
r[4]=0x00000001u;
goto P_0c0c5f00;
P_0c0c5f00: /* original d008, guest PC 0x0c0c5f00 */
if(!s->budget--) { s->failed_pc=0x0c0c5f00u; return 0; }
r[0]=read(ram,0x0c0c5f24u,4);
goto P_0c0c5f02;
P_0c0c5f02: /* original 4d08, guest PC 0x0c0c5f02 */
if(!s->budget--) { s->failed_pc=0x0c0c5f02u; return 0; }
r[13]<<=2;
goto P_0c0c5f04;
P_0c0c5f04: /* original d308, guest PC 0x0c0c5f04 */
if(!s->budget--) { s->failed_pc=0x0c0c5f04u; return 0; }
r[3]=read(ram,0x0c0c5f28u,4);
goto P_0c0c5f06;
P_0c0c5f06: /* original 02de, guest PC 0x0c0c5f06 */
if(!s->budget--) { s->failed_pc=0x0c0c5f06u; return 0; }
r[2]=read(ram,r[13]+r[0],4);
goto P_0c0c5f08;
P_0c0c5f08: /* original 2322, guest PC 0x0c0c5f08 */
if(!s->budget--) { s->failed_pc=0x0c0c5f08u; return 0; }
write(ram,r[3],r[2],4);
goto P_0c0c5f0a;
P_0c0c5f0a: /* original 4f26, guest PC 0x0c0c5f0a */
if(!s->budget--) { s->failed_pc=0x0c0c5f0au; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0c5f0c;
P_0c0c5f0c: /* original 6df6, guest PC 0x0c0c5f0c */
if(!s->budget--) { s->failed_pc=0x0c0c5f0cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0c5f0e;
P_0c0c5f0e: /* original 000b, guest PC 0x0c0c5f0e */
if(!s->budget--) { s->failed_pc=0x0c0c5f0eu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0c5f10: /* original 6ef6, guest PC 0x0c0c5f10 */
if(!s->budget--) { s->failed_pc=0x0c0c5f10u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0c5f12u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0c5f12u; return 0; } return 1;
P_0c0c600c: /* original 2fe6, guest PC 0x0c0c600c */
if(!s->budget--) { s->failed_pc=0x0c0c600cu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c600e;
P_0c0c600e: /* original 4411, guest PC 0x0c0c600e */
if(!s->budget--) { s->failed_pc=0x0c0c600eu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=0)!=0);
goto P_0c0c6010;
P_0c0c6010: /* original 2fd6, guest PC 0x0c0c6010 */
if(!s->budget--) { s->failed_pc=0x0c0c6010u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c6012;
P_0c0c6012: /* original 2fc6, guest PC 0x0c0c6012 */
if(!s->budget--) { s->failed_pc=0x0c0c6012u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c6014;
P_0c0c6014: /* original 2fb6, guest PC 0x0c0c6014 */
if(!s->budget--) { s->failed_pc=0x0c0c6014u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c6016;
P_0c0c6016: /* original 2fa6, guest PC 0x0c0c6016 */
if(!s->budget--) { s->failed_pc=0x0c0c6016u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c6018;
P_0c0c6018: /* original 2f96, guest PC 0x0c0c6018 */
if(!s->budget--) { s->failed_pc=0x0c0c6018u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c601a;
P_0c0c601a: /* original 2f86, guest PC 0x0c0c601a */
if(!s->budget--) { s->failed_pc=0x0c0c601au; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c601c;
P_0c0c601c: /* original 4f22, guest PC 0x0c0c601c */
if(!s->budget--) { s->failed_pc=0x0c0c601cu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0c601e;
P_0c0c601e: /* original d32a, guest PC 0x0c0c601e */
if(!s->budget--) { s->failed_pc=0x0c0c601eu; return 0; }
r[3]=read(ram,0x0c0c60c8u,4);
goto P_0c0c6020;
P_0c0c6020: /* original 7ff8, guest PC 0x0c0c6020 */
if(!s->budget--) { s->failed_pc=0x0c0c6020u; return 0; }
r[15]+=0xfffffff8u;
goto P_0c0c6022;
P_0c0c6022: /* original 1f31, guest PC 0x0c0c6022 */
if(!s->budget--) { s->failed_pc=0x0c0c6022u; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c0c6024;
P_0c0c6024: /* original 8b42, guest PC 0x0c0c6024 */
if(!s->budget--) { s->failed_pc=0x0c0c6024u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c60ac; }
goto P_0c0c6026;
P_0c0c6026: /* original 924b, guest PC 0x0c0c6026 */
if(!s->budget--) { s->failed_pc=0x0c0c6026u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c60c0u,2);
goto P_0c0c6028;
P_0c0c6028: /* original 3423, guest PC 0x0c0c6028 */
if(!s->budget--) { s->failed_pc=0x0c0c6028u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=(int32_t)r[2])!=0);
goto P_0c0c602a;
P_0c0c602a: /* original 893f, guest PC 0x0c0c602a */
if(!s->budget--) { s->failed_pc=0x0c0c602au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c60ac; }
goto P_0c0c602c;
P_0c0c602c: /* original d027, guest PC 0x0c0c602c */
if(!s->budget--) { s->failed_pc=0x0c0c602cu; return 0; }
r[0]=read(ram,0x0c0c60ccu,4);
goto P_0c0c602e;
P_0c0c602e: /* original 6143, guest PC 0x0c0c602e */
if(!s->budget--) { s->failed_pc=0x0c0c602eu; return 0; }
r[1]=r[4];
goto P_0c0c6030;
P_0c0c6030: /* original 4108, guest PC 0x0c0c6030 */
if(!s->budget--) { s->failed_pc=0x0c0c6030u; return 0; }
r[1]<<=2;
goto P_0c0c6032;
P_0c0c6032: /* original 031e, guest PC 0x0c0c6032 */
if(!s->budget--) { s->failed_pc=0x0c0c6032u; return 0; }
r[3]=read(ram,r[1]+r[0],4);
goto P_0c0c6034;
P_0c0c6034: /* original 4311, guest PC 0x0c0c6034 */
if(!s->budget--) { s->failed_pc=0x0c0c6034u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>=0)!=0);
goto P_0c0c6036;
P_0c0c6036: /* original 8b39, guest PC 0x0c0c6036 */
if(!s->budget--) { s->failed_pc=0x0c0c6036u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c60ac; }
goto P_0c0c6038;
P_0c0c6038: /* original d325, guest PC 0x0c0c6038 */
if(!s->budget--) { s->failed_pc=0x0c0c6038u; return 0; }
r[3]=read(ram,0x0c0c60d0u,4);
goto P_0c0c603a;
P_0c0c603a: /* original ec00, guest PC 0x0c0c603a */
if(!s->budget--) { s->failed_pc=0x0c0c603au; return 0; }
r[12]=0x00000000u;
goto P_0c0c603c;
P_0c0c603c: /* original e8ff, guest PC 0x0c0c603c */
if(!s->budget--) { s->failed_pc=0x0c0c603cu; return 0; }
r[8]=0xffffffffu;
goto P_0c0c603e;
P_0c0c603e: /* original 2f32, guest PC 0x0c0c603e */
if(!s->budget--) { s->failed_pc=0x0c0c603eu; return 0; }
write(ram,r[15],r[3],4);
goto P_0c0c6040;
P_0c0c6040: /* original da24, guest PC 0x0c0c6040 */
if(!s->budget--) { s->failed_pc=0x0c0c6040u; return 0; }
r[10]=read(ram,0x0c0c60d4u,4);
goto P_0c0c6042;
P_0c0c6042: /* original 993e, guest PC 0x0c0c6042 */
if(!s->budget--) { s->failed_pc=0x0c0c6042u; return 0; }
r[9]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c60c2u,2);
goto P_0c0c6044;
P_0c0c6044: /* original dd25, guest PC 0x0c0c6044 */
if(!s->budget--) { s->failed_pc=0x0c0c6044u; return 0; }
r[13]=read(ram,0x0c0c60dcu,4);
goto P_0c0c6046;
P_0c0c6046: /* original db24, guest PC 0x0c0c6046 */
if(!s->budget--) { s->failed_pc=0x0c0c6046u; return 0; }
r[11]=read(ram,0x0c0c60d8u,4);
goto P_0c0c6048;
P_0c0c6048: /* original 6ec3, guest PC 0x0c0c6048 */
if(!s->budget--) { s->failed_pc=0x0c0c6048u; return 0; }
r[14]=r[12];
goto P_0c0c604a;
P_0c0c604a: /* original 4e08, guest PC 0x0c0c604a */
if(!s->budget--) { s->failed_pc=0x0c0c604au; return 0; }
r[14]<<=2;
goto P_0c0c604c;
P_0c0c604c: /* original 4e00, guest PC 0x0c0c604c */
if(!s->budget--) { s->failed_pc=0x0c0c604cu; return 0; }
r[17]=(r[17]&~1u)|((r[14]>>31)!=0);
r[14]<<=1;
goto P_0c0c604e;
P_0c0c604e: /* original 3eac, guest PC 0x0c0c604e */
if(!s->budget--) { s->failed_pc=0x0c0c604eu; return 0; }
r[14]+=r[10];
goto P_0c0c6050;
P_0c0c6050: /* original 53e1, guest PC 0x0c0c6050 */
if(!s->budget--) { s->failed_pc=0x0c0c6050u; return 0; }
r[3]=read(ram,r[14]+4,4);
goto P_0c0c6052;
P_0c0c6052: /* original 2338, guest PC 0x0c0c6052 */
if(!s->budget--) { s->failed_pc=0x0c0c6052u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c0c6054;
P_0c0c6054: /* original 892a, guest PC 0x0c0c6054 */
if(!s->budget--) { s->failed_pc=0x0c0c6054u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c60ac; }
goto P_0c0c6056;
P_0c0c6056: /* original 52e1, guest PC 0x0c0c6056 */
if(!s->budget--) { s->failed_pc=0x0c0c6056u; return 0; }
r[2]=read(ram,r[14]+4,4);
goto P_0c0c6058;
P_0c0c6058: /* original 3420, guest PC 0x0c0c6058 */
if(!s->budget--) { s->failed_pc=0x0c0c6058u; return 0; }
r[17]=(r[17]&~1u)|((r[4]==r[2])!=0);
goto P_0c0c605a;
P_0c0c605a: /* original 8b25, guest PC 0x0c0c605a */
if(!s->budget--) { s->failed_pc=0x0c0c605au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c60a8; }
goto P_0c0c605c;
P_0c0c605c: /* original 61f2, guest PC 0x0c0c605c */
if(!s->budget--) { s->failed_pc=0x0c0c605cu; return 0; }
tmp=read(ram,r[15],4);
r[1]=tmp;
goto P_0c0c605e;
P_0c0c605e: /* original 63e2, guest PC 0x0c0c605e */
if(!s->budget--) { s->failed_pc=0x0c0c605eu; return 0; }
tmp=read(ram,r[14],4);
r[3]=tmp;
goto P_0c0c6060;
P_0c0c6060: /* original 6212, guest PC 0x0c0c6060 */
if(!s->budget--) { s->failed_pc=0x0c0c6060u; return 0; }
tmp=read(ram,r[1],4);
r[2]=tmp;
goto P_0c0c6062;
P_0c0c6062: /* original 3230, guest PC 0x0c0c6062 */
if(!s->budget--) { s->failed_pc=0x0c0c6062u; return 0; }
r[17]=(r[17]&~1u)|((r[2]==r[3])!=0);
goto P_0c0c6064;
P_0c0c6064: /* original 891b, guest PC 0x0c0c6064 */
if(!s->budget--) { s->failed_pc=0x0c0c6064u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c609e; }
goto P_0c0c6066;
P_0c0c6066: /* original 65b2, guest PC 0x0c0c6066 */
if(!s->budget--) { s->failed_pc=0x0c0c6066u; return 0; }
tmp=read(ram,r[11],4);
r[5]=tmp;
goto P_0c0c6068;
P_0c0c6068: /* original d31d, guest PC 0x0c0c6068 */
if(!s->budget--) { s->failed_pc=0x0c0c6068u; return 0; }
r[3]=read(ram,0x0c0c60e0u,4);
goto P_0c0c606a;
P_0c0c606a: /* original 35dc, guest PC 0x0c0c606a */
if(!s->budget--) { s->failed_pc=0x0c0c606au; return 0; }
r[5]+=r[13];
goto P_0c0c606c;
P_0c0c606c: /* original 430b, guest PC 0x0c0c606c */
if(!s->budget--) { s->failed_pc=0x0c0c606cu; return 0; }
target=r[3];
r[16]=code_base|0x0c0c6070u;
tmp=read(ram,r[14],4);
r[4]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c6070u) { target=s->pc; goto dispatch; }
goto P_0c0c6070;
P_0c0c606e: /* original 64e2, guest PC 0x0c0c606e */
if(!s->budget--) { s->failed_pc=0x0c0c606eu; return 0; }
tmp=read(ram,r[14],4);
r[4]=tmp;
goto P_0c0c6070;
P_0c0c6070: /* original d41c, guest PC 0x0c0c6070 */
if(!s->budget--) { s->failed_pc=0x0c0c6070u; return 0; }
r[4]=read(ram,0x0c0c60e4u,4);
goto P_0c0c6072;
P_0c0c6072: /* original be0f, guest PC 0x0c0c6072 */
if(!s->budget--) { s->failed_pc=0x0c0c6072u; return 0; }
target=code_base|0x0c0c5c94u; r[16]=code_base|0x0c0c6076u;
r[5]=0x00000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c6076u) { target=s->pc; goto dispatch; }
goto P_0c0c6076;
P_0c0c6074: /* original e500, guest PC 0x0c0c6074 */
if(!s->budget--) { s->failed_pc=0x0c0c6074u; return 0; }
r[5]=0x00000000u;
goto P_0c0c6076;
P_0c0c6076: /* original d31c, guest PC 0x0c0c6076 */
if(!s->budget--) { s->failed_pc=0x0c0c6076u; return 0; }
r[3]=read(ram,0x0c0c60e8u,4);
goto P_0c0c6078;
P_0c0c6078: /* original 430b, guest PC 0x0c0c6078 */
if(!s->budget--) { s->failed_pc=0x0c0c6078u; return 0; }
target=r[3];
r[16]=code_base|0x0c0c607cu;
r[4]=0x00000003u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c607cu) { target=s->pc; goto dispatch; }
goto P_0c0c607c;
P_0c0c607a: /* original e403, guest PC 0x0c0c607a */
if(!s->budget--) { s->failed_pc=0x0c0c607au; return 0; }
r[4]=0x00000003u;
goto P_0c0c607c;
P_0c0c607c: /* original d21b, guest PC 0x0c0c607c */
if(!s->budget--) { s->failed_pc=0x0c0c607cu; return 0; }
r[2]=read(ram,0x0c0c60ecu,4);
goto P_0c0c607e;
P_0c0c607e: /* original e503, guest PC 0x0c0c607e */
if(!s->budget--) { s->failed_pc=0x0c0c607eu; return 0; }
r[5]=0x00000003u;
goto P_0c0c6080;
P_0c0c6080: /* original 64b2, guest PC 0x0c0c6080 */
if(!s->budget--) { s->failed_pc=0x0c0c6080u; return 0; }
tmp=read(ram,r[11],4);
r[4]=tmp;
goto P_0c0c6082;
P_0c0c6082: /* original 420b, guest PC 0x0c0c6082 */
if(!s->budget--) { s->failed_pc=0x0c0c6082u; return 0; }
target=r[2];
r[16]=code_base|0x0c0c6086u;
r[4]+=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c6086u) { target=s->pc; goto dispatch; }
goto P_0c0c6086;
P_0c0c6084: /* original 34dc, guest PC 0x0c0c6084 */
if(!s->budget--) { s->failed_pc=0x0c0c6084u; return 0; }
r[4]+=r[13];
goto P_0c0c6086;
P_0c0c6086: /* original 2008, guest PC 0x0c0c6086 */
if(!s->budget--) { s->failed_pc=0x0c0c6086u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c0c6088;
P_0c0c6088: /* original 8903, guest PC 0x0c0c6088 */
if(!s->budget--) { s->failed_pc=0x0c0c6088u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c6092; }
goto P_0c0c608a;
P_0c0c608a: /* original d219, guest PC 0x0c0c608a */
if(!s->budget--) { s->failed_pc=0x0c0c608au; return 0; }
r[2]=read(ram,0x0c0c60f0u,4);
goto P_0c0c608c;
P_0c0c608c: /* original 6593, guest PC 0x0c0c608c */
if(!s->budget--) { s->failed_pc=0x0c0c608cu; return 0; }
r[5]=r[9];
goto P_0c0c608e;
P_0c0c608e: /* original 420b, guest PC 0x0c0c608e */
if(!s->budget--) { s->failed_pc=0x0c0c608eu; return 0; }
target=r[2];
r[16]=code_base|0x0c0c6092u;
r[4]=0x00000001u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c6092u) { target=s->pc; goto dispatch; }
goto P_0c0c6092;
P_0c0c6090: /* original e401, guest PC 0x0c0c6090 */
if(!s->budget--) { s->failed_pc=0x0c0c6090u; return 0; }
r[4]=0x00000001u;
goto P_0c0c6092;
P_0c0c6092: /* original 4c08, guest PC 0x0c0c6092 */
if(!s->budget--) { s->failed_pc=0x0c0c6092u; return 0; }
r[12]<<=2;
goto P_0c0c6094;
P_0c0c6094: /* original 63f2, guest PC 0x0c0c6094 */
if(!s->budget--) { s->failed_pc=0x0c0c6094u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c0c6096;
P_0c0c6096: /* original 4c00, guest PC 0x0c0c6096 */
if(!s->budget--) { s->failed_pc=0x0c0c6096u; return 0; }
r[17]=(r[17]&~1u)|((r[12]>>31)!=0);
r[12]<<=1;
goto P_0c0c6098;
P_0c0c6098: /* original 3cac, guest PC 0x0c0c6098 */
if(!s->budget--) { s->failed_pc=0x0c0c6098u; return 0; }
r[12]+=r[10];
goto P_0c0c609a;
P_0c0c609a: /* original 62c2, guest PC 0x0c0c609a */
if(!s->budget--) { s->failed_pc=0x0c0c609au; return 0; }
tmp=read(ram,r[12],4);
r[2]=tmp;
goto P_0c0c609c;
P_0c0c609c: /* original 2322, guest PC 0x0c0c609c */
if(!s->budget--) { s->failed_pc=0x0c0c609cu; return 0; }
write(ram,r[3],r[2],4);
goto P_0c0c609e;
P_0c0c609e: /* original 9011, guest PC 0x0c0c609e */
if(!s->budget--) { s->failed_pc=0x0c0c609eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c60c4u,2);
goto P_0c0c60a0;
P_0c0c60a0: /* original 53f1, guest PC 0x0c0c60a0 */
if(!s->budget--) { s->failed_pc=0x0c0c60a0u; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c0c60a2;
P_0c0c60a2: /* original 0386, guest PC 0x0c0c60a2 */
if(!s->budget--) { s->failed_pc=0x0c0c60a2u; return 0; }
write(ram,r[3]+r[0],r[8],4);
goto P_0c0c60a4;
P_0c0c60a4: /* original a002, guest PC 0x0c0c60a4 */
if(!s->budget--) { s->failed_pc=0x0c0c60a4u; return 0; }
goto P_0c0c60ac;
P_0c0c60a6: /* original 0009, guest PC 0x0c0c60a6 */
if(!s->budget--) { s->failed_pc=0x0c0c60a6u; return 0; }
goto P_0c0c60a8;
P_0c0c60a8: /* original afce, guest PC 0x0c0c60a8 */
if(!s->budget--) { s->failed_pc=0x0c0c60a8u; return 0; }
r[12]+=0x00000001u;
goto P_0c0c6048;
P_0c0c60aa: /* original 7c01, guest PC 0x0c0c60aa */
if(!s->budget--) { s->failed_pc=0x0c0c60aau; return 0; }
r[12]+=0x00000001u;
goto P_0c0c60ac;
P_0c0c60ac: /* original 7f08, guest PC 0x0c0c60ac */
if(!s->budget--) { s->failed_pc=0x0c0c60acu; return 0; }
r[15]+=0x00000008u;
goto P_0c0c60ae;
P_0c0c60ae: /* original 4f26, guest PC 0x0c0c60ae */
if(!s->budget--) { s->failed_pc=0x0c0c60aeu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0c60b0;
P_0c0c60b0: /* original 68f6, guest PC 0x0c0c60b0 */
if(!s->budget--) { s->failed_pc=0x0c0c60b0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c0c60b2;
P_0c0c60b2: /* original 69f6, guest PC 0x0c0c60b2 */
if(!s->budget--) { s->failed_pc=0x0c0c60b2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c0c60b4;
P_0c0c60b4: /* original 6af6, guest PC 0x0c0c60b4 */
if(!s->budget--) { s->failed_pc=0x0c0c60b4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0c60b6;
P_0c0c60b6: /* original 6bf6, guest PC 0x0c0c60b6 */
if(!s->budget--) { s->failed_pc=0x0c0c60b6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0c60b8;
P_0c0c60b8: /* original 6cf6, guest PC 0x0c0c60b8 */
if(!s->budget--) { s->failed_pc=0x0c0c60b8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0c60ba;
P_0c0c60ba: /* original 6df6, guest PC 0x0c0c60ba */
if(!s->budget--) { s->failed_pc=0x0c0c60bau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0c60bc;
P_0c0c60bc: /* original 000b, guest PC 0x0c0c60bc */
if(!s->budget--) { s->failed_pc=0x0c0c60bcu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0c60be: /* original 6ef6, guest PC 0x0c0c60be */
if(!s->budget--) { s->failed_pc=0x0c0c60beu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0c60c0u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0c60c0u; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
