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
int vf3_away_batch116_adapter_30(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c0c42ecu: goto P_0c0c42ec;
case 0x0c0c42eeu: goto P_0c0c42ee;
case 0x0c0c42f0u: goto P_0c0c42f0;
case 0x0c0c42f2u: goto P_0c0c42f2;
case 0x0c0c42f4u: goto P_0c0c42f4;
case 0x0c0c42f6u: goto P_0c0c42f6;
case 0x0c0c42f8u: goto P_0c0c42f8;
case 0x0c0c42fau: goto P_0c0c42fa;
case 0x0c0c42fcu: goto P_0c0c42fc;
case 0x0c0c42feu: goto P_0c0c42fe;
case 0x0c0c4300u: goto P_0c0c4300;
case 0x0c0c4302u: goto P_0c0c4302;
case 0x0c0c4304u: goto P_0c0c4304;
case 0x0c0c4306u: goto P_0c0c4306;
case 0x0c0c4308u: goto P_0c0c4308;
case 0x0c0c430au: goto P_0c0c430a;
case 0x0c0c430cu: goto P_0c0c430c;
case 0x0c0c430eu: goto P_0c0c430e;
case 0x0c0c4310u: goto P_0c0c4310;
case 0x0c0c4312u: goto P_0c0c4312;
case 0x0c0c4314u: goto P_0c0c4314;
case 0x0c0c4316u: goto P_0c0c4316;
case 0x0c0c4318u: goto P_0c0c4318;
case 0x0c0c431au: goto P_0c0c431a;
case 0x0c0c431cu: goto P_0c0c431c;
case 0x0c0c431eu: goto P_0c0c431e;
case 0x0c0c4320u: goto P_0c0c4320;
case 0x0c0c4322u: goto P_0c0c4322;
case 0x0c0c4324u: goto P_0c0c4324;
case 0x0c0c5c94u: goto P_0c0c5c94;
case 0x0c0c5c96u: goto P_0c0c5c96;
case 0x0c0c5c98u: goto P_0c0c5c98;
case 0x0c0c5c9au: goto P_0c0c5c9a;
case 0x0c0c5c9cu: goto P_0c0c5c9c;
case 0x0c0c5c9eu: goto P_0c0c5c9e;
case 0x0c0c5ca0u: goto P_0c0c5ca0;
case 0x0c0c5ca2u: goto P_0c0c5ca2;
case 0x0c0c5ca4u: goto P_0c0c5ca4;
case 0x0c0c5ca6u: goto P_0c0c5ca6;
case 0x0c0c5ca8u: goto P_0c0c5ca8;
case 0x0c0c5caau: goto P_0c0c5caa;
case 0x0c0c5cacu: goto P_0c0c5cac;
case 0x0c0c5caeu: goto P_0c0c5cae;
case 0x0c0c5cb0u: goto P_0c0c5cb0;
case 0x0c0c5cf4u: goto P_0c0c5cf4;
case 0x0c0c5cf6u: goto P_0c0c5cf6;
case 0x0c0c5cf8u: goto P_0c0c5cf8;
case 0x0c0c5cfau: goto P_0c0c5cfa;
case 0x0c0c5cfcu: goto P_0c0c5cfc;
case 0x0c0c5cfeu: goto P_0c0c5cfe;
case 0x0c0c5d00u: goto P_0c0c5d00;
case 0x0c0c5d02u: goto P_0c0c5d02;
case 0x0c0c5d04u: goto P_0c0c5d04;
case 0x0c0c5d06u: goto P_0c0c5d06;
case 0x0c0c5d08u: goto P_0c0c5d08;
case 0x0c0c5d0au: goto P_0c0c5d0a;
case 0x0c0c5d0cu: goto P_0c0c5d0c;
case 0x0c0c5d0eu: goto P_0c0c5d0e;
case 0x0c0c5d10u: goto P_0c0c5d10;
case 0x0c0c5d12u: goto P_0c0c5d12;
case 0x0c0c5d14u: goto P_0c0c5d14;
case 0x0c0c5d16u: goto P_0c0c5d16;
case 0x0c0c5d18u: goto P_0c0c5d18;
case 0x0c0c5d1au: goto P_0c0c5d1a;
case 0x0c0c5d1cu: goto P_0c0c5d1c;
case 0x0c0c5d1eu: goto P_0c0c5d1e;
case 0x0c0c5d20u: goto P_0c0c5d20;
case 0x0c0c5d22u: goto P_0c0c5d22;
case 0x0c0c5d24u: goto P_0c0c5d24;
case 0x0c0c5d26u: goto P_0c0c5d26;
case 0x0c0c5d28u: goto P_0c0c5d28;
case 0x0c0c5d2au: goto P_0c0c5d2a;
case 0x0c0c5d2cu: goto P_0c0c5d2c;
case 0x0c0c5d2eu: goto P_0c0c5d2e;
case 0x0c0c5d30u: goto P_0c0c5d30;
case 0x0c0c5d32u: goto P_0c0c5d32;
case 0x0c0c5d34u: goto P_0c0c5d34;
case 0x0c0c5d36u: goto P_0c0c5d36;
case 0x0c0c5d38u: goto P_0c0c5d38;
case 0x0c0c5d3au: goto P_0c0c5d3a;
case 0x0c0c5d3cu: goto P_0c0c5d3c;
case 0x0c0c5d3eu: goto P_0c0c5d3e;
case 0x0c0c5d40u: goto P_0c0c5d40;
case 0x0c0c5d42u: goto P_0c0c5d42;
case 0x0c0c5d44u: goto P_0c0c5d44;
case 0x0c0c5d46u: goto P_0c0c5d46;
case 0x0c0c5d48u: goto P_0c0c5d48;
case 0x0c0c5d4au: goto P_0c0c5d4a;
case 0x0c0c5d4cu: goto P_0c0c5d4c;
case 0x0c0c5d4eu: goto P_0c0c5d4e;
case 0x0c0c5d50u: goto P_0c0c5d50;
case 0x0c0c5d52u: goto P_0c0c5d52;
case 0x0c0c5d54u: goto P_0c0c5d54;
case 0x0c0c5d56u: goto P_0c0c5d56;
case 0x0c0c5d58u: goto P_0c0c5d58;
case 0x0c0c5d5au: goto P_0c0c5d5a;
case 0x0c0c5d5cu: goto P_0c0c5d5c;
case 0x0c0c5d5eu: goto P_0c0c5d5e;
case 0x0c0c5d60u: goto P_0c0c5d60;
case 0x0c0c5d62u: goto P_0c0c5d62;
case 0x0c0c5d64u: goto P_0c0c5d64;
case 0x0c0c5d66u: goto P_0c0c5d66;
case 0x0c0c5d68u: goto P_0c0c5d68;
case 0x0c0c5d6au: goto P_0c0c5d6a;
case 0x0c0c5d6cu: goto P_0c0c5d6c;
case 0x0c0c5d6eu: goto P_0c0c5d6e;
case 0x0c0c5d70u: goto P_0c0c5d70;
case 0x0c0c5d72u: goto P_0c0c5d72;
case 0x0c0c5d74u: goto P_0c0c5d74;
case 0x0c0c5d76u: goto P_0c0c5d76;
case 0x0c0c5d78u: goto P_0c0c5d78;
case 0x0c0c5d7au: goto P_0c0c5d7a;
case 0x0c0c5d7cu: goto P_0c0c5d7c;
case 0x0c0c5d7eu: goto P_0c0c5d7e;
case 0x0c0c5d80u: goto P_0c0c5d80;
case 0x0c0c5d82u: goto P_0c0c5d82;
case 0x0c0c5d84u: goto P_0c0c5d84;
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
P_0c0c42ec: /* original d313, guest PC 0x0c0c42ec */
if(!s->budget--) { s->failed_pc=0x0c0c42ecu; return 0; }
r[3]=read(ram,0x0c0c433cu,4);
goto P_0c0c42ee;
P_0c0c42ee: /* original 7ff8, guest PC 0x0c0c42ee */
if(!s->budget--) { s->failed_pc=0x0c0c42eeu; return 0; }
r[15]+=0xfffffff8u;
goto P_0c0c42f0;
P_0c0c42f0: /* original 2f32, guest PC 0x0c0c42f0 */
if(!s->budget--) { s->failed_pc=0x0c0c42f0u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c0c42f2;
P_0c0c42f2: /* original e306, guest PC 0x0c0c42f2 */
if(!s->budget--) { s->failed_pc=0x0c0c42f2u; return 0; }
r[3]=0x00000006u;
goto P_0c0c42f4;
P_0c0c42f4: /* original d213, guest PC 0x0c0c42f4 */
if(!s->budget--) { s->failed_pc=0x0c0c42f4u; return 0; }
r[2]=read(ram,0x0c0c4344u,4);
goto P_0c0c42f6;
P_0c0c42f6: /* original 1f21, guest PC 0x0c0c42f6 */
if(!s->budget--) { s->failed_pc=0x0c0c42f6u; return 0; }
write(ram,r[15]+4,r[2],4);
goto P_0c0c42f8;
P_0c0c42f8: /* original 6742, guest PC 0x0c0c42f8 */
if(!s->budget--) { s->failed_pc=0x0c0c42f8u; return 0; }
tmp=read(ram,r[4],4);
r[7]=tmp;
goto P_0c0c42fa;
P_0c0c42fa: /* original 2738, guest PC 0x0c0c42fa */
if(!s->budget--) { s->failed_pc=0x0c0c42fau; return 0; }
r[17]=(r[17]&~1u)|(((r[7]&r[3])==0)!=0);
goto P_0c0c42fc;
P_0c0c42fc: /* original 8b10, guest PC 0x0c0c42fc */
if(!s->budget--) { s->failed_pc=0x0c0c42fcu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c4320; }
goto P_0c0c42fe;
P_0c0c42fe: /* original 9019, guest PC 0x0c0c42fe */
if(!s->budget--) { s->failed_pc=0x0c0c42feu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c4334u,2);
goto P_0c0c4300;
P_0c0c4300: /* original 53f1, guest PC 0x0c0c4300 */
if(!s->budget--) { s->failed_pc=0x0c0c4300u; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c0c4302;
P_0c0c4302: /* original 023c, guest PC 0x0c0c4302 */
if(!s->budget--) { s->failed_pc=0x0c0c4302u; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[3]+r[0],1);
goto P_0c0c4304;
P_0c0c4304: /* original 2228, guest PC 0x0c0c4304 */
if(!s->budget--) { s->failed_pc=0x0c0c4304u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c0c4306;
P_0c0c4306: /* original 8b02, guest PC 0x0c0c4306 */
if(!s->budget--) { s->failed_pc=0x0c0c4306u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c430e; }
goto P_0c0c4308;
P_0c0c4308: /* original 6253, guest PC 0x0c0c4308 */
if(!s->budget--) { s->failed_pc=0x0c0c4308u; return 0; }
r[2]=r[5];
goto P_0c0c430a;
P_0c0c430a: /* original 2268, guest PC 0x0c0c430a */
if(!s->budget--) { s->failed_pc=0x0c0c430au; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[6])==0)!=0);
goto P_0c0c430c;
P_0c0c430c: /* original 8908, guest PC 0x0c0c430c */
if(!s->budget--) { s->failed_pc=0x0c0c430cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c4320; }
goto P_0c0c430e;
P_0c0c430e: /* original e305, guest PC 0x0c0c430e */
if(!s->budget--) { s->failed_pc=0x0c0c430eu; return 0; }
r[3]=0x00000005u;
goto P_0c0c4310;
P_0c0c4310: /* original 2432, guest PC 0x0c0c4310 */
if(!s->budget--) { s->failed_pc=0x0c0c4310u; return 0; }
write(ram,r[4],r[3],4);
goto P_0c0c4312;
P_0c0c4312: /* original 6667, guest PC 0x0c0c4312 */
if(!s->budget--) { s->failed_pc=0x0c0c4312u; return 0; }
r[6]=~r[6];
goto P_0c0c4314;
P_0c0c4314: /* original d20c, guest PC 0x0c0c4314 */
if(!s->budget--) { s->failed_pc=0x0c0c4314u; return 0; }
r[2]=read(ram,0x0c0c4348u,4);
goto P_0c0c4316;
P_0c0c4316: /* original 2569, guest PC 0x0c0c4316 */
if(!s->budget--) { s->failed_pc=0x0c0c4316u; return 0; }
r[5]&=r[6];
goto P_0c0c4318;
P_0c0c4318: /* original 1423, guest PC 0x0c0c4318 */
if(!s->budget--) { s->failed_pc=0x0c0c4318u; return 0; }
write(ram,r[4]+12,r[2],4);
goto P_0c0c431a;
P_0c0c431a: /* original 920c, guest PC 0x0c0c431a */
if(!s->budget--) { s->failed_pc=0x0c0c431au; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c4336u,2);
goto P_0c0c431c;
P_0c0c431c: /* original 63f2, guest PC 0x0c0c431c */
if(!s->budget--) { s->failed_pc=0x0c0c431cu; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c0c431e;
P_0c0c431e: /* original 132b, guest PC 0x0c0c431e */
if(!s->budget--) { s->failed_pc=0x0c0c431eu; return 0; }
write(ram,r[3]+44,r[2],4);
goto P_0c0c4320;
P_0c0c4320: /* original 6053, guest PC 0x0c0c4320 */
if(!s->budget--) { s->failed_pc=0x0c0c4320u; return 0; }
r[0]=r[5];
goto P_0c0c4322;
P_0c0c4322: /* original 000b, guest PC 0x0c0c4322 */
if(!s->budget--) { s->failed_pc=0x0c0c4322u; return 0; }
target=r[16];
r[15]+=0x00000008u;
s->pc=target; return ram->oob==0;
P_0c0c4324: /* original 7f08, guest PC 0x0c0c4324 */
if(!s->budget--) { s->failed_pc=0x0c0c4324u; return 0; }
r[15]+=0x00000008u;
if(!vf3_matrix_family(0x0c0c4326u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0c4326u; return 0; } return 1;
P_0c0c5c94: /* original 2fe6, guest PC 0x0c0c5c94 */
if(!s->budget--) { s->failed_pc=0x0c0c5c94u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c5c96;
P_0c0c5c96: /* original 6043, guest PC 0x0c0c5c96 */
if(!s->budget--) { s->failed_pc=0x0c0c5c96u; return 0; }
r[0]=r[4];
goto P_0c0c5c98;
P_0c0c5c98: /* original 2fd6, guest PC 0x0c0c5c98 */
if(!s->budget--) { s->failed_pc=0x0c0c5c98u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c5c9a;
P_0c0c5c9a: /* original 88ff, guest PC 0x0c0c5c9a */
if(!s->budget--) { s->failed_pc=0x0c0c5c9au; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xffffffffu)!=0);
goto P_0c0c5c9c;
P_0c0c5c9c: /* original 2fc6, guest PC 0x0c0c5c9c */
if(!s->budget--) { s->failed_pc=0x0c0c5c9cu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c5c9e;
P_0c0c5c9e: /* original 6d43, guest PC 0x0c0c5c9e */
if(!s->budget--) { s->failed_pc=0x0c0c5c9eu; return 0; }
r[13]=r[4];
goto P_0c0c5ca0;
P_0c0c5ca0: /* original 2fb6, guest PC 0x0c0c5ca0 */
if(!s->budget--) { s->failed_pc=0x0c0c5ca0u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c5ca2;
P_0c0c5ca2: /* original 4f22, guest PC 0x0c0c5ca2 */
if(!s->budget--) { s->failed_pc=0x0c0c5ca2u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0c5ca4;
P_0c0c5ca4: /* original 8d03, guest PC 0x0c0c5ca4 */
if(!s->budget--) { s->failed_pc=0x0c0c5ca4u; return 0; }
cond=r[17]&1u;
r[11]=r[5];
if(cond) { goto P_0c0c5cae; }
goto P_0c0c5ca8;
P_0c0c5ca6: /* original 6b53, guest PC 0x0c0c5ca6 */
if(!s->budget--) { s->failed_pc=0x0c0c5ca6u; return 0; }
r[11]=r[5];
goto P_0c0c5ca8;
P_0c0c5ca8: /* original 930d, guest PC 0x0c0c5ca8 */
if(!s->budget--) { s->failed_pc=0x0c0c5ca8u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c5cc6u,2);
goto P_0c0c5caa;
P_0c0c5caa: /* original 3d30, guest PC 0x0c0c5caa */
if(!s->budget--) { s->failed_pc=0x0c0c5caau; return 0; }
r[17]=(r[17]&~1u)|((r[13]==r[3])!=0);
goto P_0c0c5cac;
P_0c0c5cac: /* original 8b22, guest PC 0x0c0c5cac */
if(!s->budget--) { s->failed_pc=0x0c0c5cacu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c5cf4; }
goto P_0c0c5cae;
P_0c0c5cae: /* original a064, guest PC 0x0c0c5cae */
if(!s->budget--) { s->failed_pc=0x0c0c5caeu; return 0; }
r[0]=0xffffffffu;
goto P_0c0c5d7a;
P_0c0c5cb0: /* original e0ff, guest PC 0x0c0c5cb0 */
if(!s->budget--) { s->failed_pc=0x0c0c5cb0u; return 0; }
r[0]=0xffffffffu;
if(!vf3_matrix_family(0x0c0c5cb2u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0c5cb2u; return 0; } return 1;
P_0c0c5cf4: /* original 9381, guest PC 0x0c0c5cf4 */
if(!s->budget--) { s->failed_pc=0x0c0c5cf4u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c5dfau,2);
goto P_0c0c5cf6;
P_0c0c5cf6: /* original de43, guest PC 0x0c0c5cf6 */
if(!s->budget--) { s->failed_pc=0x0c0c5cf6u; return 0; }
r[14]=read(ram,0x0c0c5e04u,4);
goto P_0c0c5cf8;
P_0c0c5cf8: /* original 3d30, guest PC 0x0c0c5cf8 */
if(!s->budget--) { s->failed_pc=0x0c0c5cf8u; return 0; }
r[17]=(r[17]&~1u)|((r[13]==r[3])!=0);
goto P_0c0c5cfa;
P_0c0c5cfa: /* original 8905, guest PC 0x0c0c5cfa */
if(!s->budget--) { s->failed_pc=0x0c0c5cfau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c5d08; }
goto P_0c0c5cfc;
P_0c0c5cfc: /* original 917e, guest PC 0x0c0c5cfc */
if(!s->budget--) { s->failed_pc=0x0c0c5cfcu; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c5dfcu,2);
goto P_0c0c5cfe;
P_0c0c5cfe: /* original 3d10, guest PC 0x0c0c5cfe */
if(!s->budget--) { s->failed_pc=0x0c0c5cfeu; return 0; }
r[17]=(r[17]&~1u)|((r[13]==r[1])!=0);
goto P_0c0c5d00;
P_0c0c5d00: /* original 8902, guest PC 0x0c0c5d00 */
if(!s->budget--) { s->failed_pc=0x0c0c5d00u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c5d08; }
goto P_0c0c5d02;
P_0c0c5d02: /* original 907c, guest PC 0x0c0c5d02 */
if(!s->budget--) { s->failed_pc=0x0c0c5d02u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c5dfeu,2);
goto P_0c0c5d04;
P_0c0c5d04: /* original 3d00, guest PC 0x0c0c5d04 */
if(!s->budget--) { s->failed_pc=0x0c0c5d04u; return 0; }
r[17]=(r[17]&~1u)|((r[13]==r[0])!=0);
goto P_0c0c5d06;
P_0c0c5d06: /* original 8b07, guest PC 0x0c0c5d06 */
if(!s->budget--) { s->failed_pc=0x0c0c5d06u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c5d18; }
goto P_0c0c5d08;
P_0c0c5d08: /* original 65d3, guest PC 0x0c0c5d08 */
if(!s->budget--) { s->failed_pc=0x0c0c5d08u; return 0; }
r[5]=r[13];
goto P_0c0c5d0a;
P_0c0c5d0a: /* original 66b3, guest PC 0x0c0c5d0a */
if(!s->budget--) { s->failed_pc=0x0c0c5d0au; return 0; }
r[6]=r[11];
goto P_0c0c5d0c;
P_0c0c5d0c: /* original 4e0b, guest PC 0x0c0c5d0c */
if(!s->budget--) { s->failed_pc=0x0c0c5d0cu; return 0; }
target=r[14];
r[16]=code_base|0x0c0c5d10u;
r[4]=0x00000004u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c5d10u) { target=s->pc; goto dispatch; }
goto P_0c0c5d10;
P_0c0c5d0e: /* original e404, guest PC 0x0c0c5d0e */
if(!s->budget--) { s->failed_pc=0x0c0c5d0eu; return 0; }
r[4]=0x00000004u;
goto P_0c0c5d10;
P_0c0c5d10: /* original 65d3, guest PC 0x0c0c5d10 */
if(!s->budget--) { s->failed_pc=0x0c0c5d10u; return 0; }
r[5]=r[13];
goto P_0c0c5d12;
P_0c0c5d12: /* original 66b3, guest PC 0x0c0c5d12 */
if(!s->budget--) { s->failed_pc=0x0c0c5d12u; return 0; }
r[6]=r[11];
goto P_0c0c5d14;
P_0c0c5d14: /* original a02f, guest PC 0x0c0c5d14 */
if(!s->budget--) { s->failed_pc=0x0c0c5d14u; return 0; }
r[4]=0x00000003u;
goto P_0c0c5d76;
P_0c0c5d16: /* original e403, guest PC 0x0c0c5d16 */
if(!s->budget--) { s->failed_pc=0x0c0c5d16u; return 0; }
r[4]=0x00000003u;
goto P_0c0c5d18;
P_0c0c5d18: /* original d33c, guest PC 0x0c0c5d18 */
if(!s->budget--) { s->failed_pc=0x0c0c5d18u; return 0; }
r[3]=read(ram,0x0c0c5e0cu,4);
goto P_0c0c5d1a;
P_0c0c5d1a: /* original dc3b, guest PC 0x0c0c5d1a */
if(!s->budget--) { s->failed_pc=0x0c0c5d1au; return 0; }
r[12]=read(ram,0x0c0c5e08u,4);
goto P_0c0c5d1c;
P_0c0c5d1c: /* original 3d30, guest PC 0x0c0c5d1c */
if(!s->budget--) { s->failed_pc=0x0c0c5d1cu; return 0; }
r[17]=(r[17]&~1u)|((r[13]==r[3])!=0);
goto P_0c0c5d1e;
P_0c0c5d1e: /* original 8b0b, guest PC 0x0c0c5d1e */
if(!s->budget--) { s->failed_pc=0x0c0c5d1eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c5d38; }
goto P_0c0c5d20;
P_0c0c5d20: /* original 65c3, guest PC 0x0c0c5d20 */
if(!s->budget--) { s->failed_pc=0x0c0c5d20u; return 0; }
r[5]=r[12];
goto P_0c0c5d22;
P_0c0c5d22: /* original e600, guest PC 0x0c0c5d22 */
if(!s->budget--) { s->failed_pc=0x0c0c5d22u; return 0; }
r[6]=0x00000000u;
goto P_0c0c5d24;
P_0c0c5d24: /* original 4e0b, guest PC 0x0c0c5d24 */
if(!s->budget--) { s->failed_pc=0x0c0c5d24u; return 0; }
target=r[14];
r[16]=code_base|0x0c0c5d28u;
r[4]=0x00000001u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c5d28u) { target=s->pc; goto dispatch; }
goto P_0c0c5d28;
P_0c0c5d26: /* original e401, guest PC 0x0c0c5d26 */
if(!s->budget--) { s->failed_pc=0x0c0c5d26u; return 0; }
r[4]=0x00000001u;
goto P_0c0c5d28;
P_0c0c5d28: /* original 65c3, guest PC 0x0c0c5d28 */
if(!s->budget--) { s->failed_pc=0x0c0c5d28u; return 0; }
r[5]=r[12];
goto P_0c0c5d2a;
P_0c0c5d2a: /* original e600, guest PC 0x0c0c5d2a */
if(!s->budget--) { s->failed_pc=0x0c0c5d2au; return 0; }
r[6]=0x00000000u;
goto P_0c0c5d2c;
P_0c0c5d2c: /* original 4e0b, guest PC 0x0c0c5d2c */
if(!s->budget--) { s->failed_pc=0x0c0c5d2cu; return 0; }
target=r[14];
r[16]=code_base|0x0c0c5d30u;
r[4]=0x00000002u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c5d30u) { target=s->pc; goto dispatch; }
goto P_0c0c5d30;
P_0c0c5d2e: /* original e402, guest PC 0x0c0c5d2e */
if(!s->budget--) { s->failed_pc=0x0c0c5d2eu; return 0; }
r[4]=0x00000002u;
goto P_0c0c5d30;
P_0c0c5d30: /* original 65c3, guest PC 0x0c0c5d30 */
if(!s->budget--) { s->failed_pc=0x0c0c5d30u; return 0; }
r[5]=r[12];
goto P_0c0c5d32;
P_0c0c5d32: /* original e600, guest PC 0x0c0c5d32 */
if(!s->budget--) { s->failed_pc=0x0c0c5d32u; return 0; }
r[6]=0x00000000u;
goto P_0c0c5d34;
P_0c0c5d34: /* original a00a, guest PC 0x0c0c5d34 */
if(!s->budget--) { s->failed_pc=0x0c0c5d34u; return 0; }
r[4]=0x00000003u;
goto P_0c0c5d4c;
P_0c0c5d36: /* original e403, guest PC 0x0c0c5d36 */
if(!s->budget--) { s->failed_pc=0x0c0c5d36u; return 0; }
r[4]=0x00000003u;
goto P_0c0c5d38;
P_0c0c5d38: /* original d135, guest PC 0x0c0c5d38 */
if(!s->budget--) { s->failed_pc=0x0c0c5d38u; return 0; }
r[1]=read(ram,0x0c0c5e10u,4);
goto P_0c0c5d3a;
P_0c0c5d3a: /* original 3d10, guest PC 0x0c0c5d3a */
if(!s->budget--) { s->failed_pc=0x0c0c5d3au; return 0; }
r[17]=(r[17]&~1u)|((r[13]==r[1])!=0);
goto P_0c0c5d3c;
P_0c0c5d3c: /* original 8b18, guest PC 0x0c0c5d3c */
if(!s->budget--) { s->failed_pc=0x0c0c5d3cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c5d70; }
goto P_0c0c5d3e;
P_0c0c5d3e: /* original 65c3, guest PC 0x0c0c5d3e */
if(!s->budget--) { s->failed_pc=0x0c0c5d3eu; return 0; }
r[5]=r[12];
goto P_0c0c5d40;
P_0c0c5d40: /* original e600, guest PC 0x0c0c5d40 */
if(!s->budget--) { s->failed_pc=0x0c0c5d40u; return 0; }
r[6]=0x00000000u;
goto P_0c0c5d42;
P_0c0c5d42: /* original 4e0b, guest PC 0x0c0c5d42 */
if(!s->budget--) { s->failed_pc=0x0c0c5d42u; return 0; }
target=r[14];
r[16]=code_base|0x0c0c5d46u;
r[4]=0x00000001u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c5d46u) { target=s->pc; goto dispatch; }
goto P_0c0c5d46;
P_0c0c5d44: /* original e401, guest PC 0x0c0c5d44 */
if(!s->budget--) { s->failed_pc=0x0c0c5d44u; return 0; }
r[4]=0x00000001u;
goto P_0c0c5d46;
P_0c0c5d46: /* original e402, guest PC 0x0c0c5d46 */
if(!s->budget--) { s->failed_pc=0x0c0c5d46u; return 0; }
r[4]=0x00000002u;
goto P_0c0c5d48;
P_0c0c5d48: /* original 65c3, guest PC 0x0c0c5d48 */
if(!s->budget--) { s->failed_pc=0x0c0c5d48u; return 0; }
r[5]=r[12];
goto P_0c0c5d4a;
P_0c0c5d4a: /* original e600, guest PC 0x0c0c5d4a */
if(!s->budget--) { s->failed_pc=0x0c0c5d4au; return 0; }
r[6]=0x00000000u;
goto P_0c0c5d4c;
P_0c0c5d4c: /* original 4e0b, guest PC 0x0c0c5d4c */
if(!s->budget--) { s->failed_pc=0x0c0c5d4cu; return 0; }
target=r[14];
r[16]=code_base|0x0c0c5d50u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c5d50u) { target=s->pc; goto dispatch; }
goto P_0c0c5d50;
P_0c0c5d4e: /* original 0009, guest PC 0x0c0c5d4e */
if(!s->budget--) { s->failed_pc=0x0c0c5d4eu; return 0; }
goto P_0c0c5d50;
P_0c0c5d50: /* original 65c3, guest PC 0x0c0c5d50 */
if(!s->budget--) { s->failed_pc=0x0c0c5d50u; return 0; }
r[5]=r[12];
goto P_0c0c5d52;
P_0c0c5d52: /* original e600, guest PC 0x0c0c5d52 */
if(!s->budget--) { s->failed_pc=0x0c0c5d52u; return 0; }
r[6]=0x00000000u;
goto P_0c0c5d54;
P_0c0c5d54: /* original 4e0b, guest PC 0x0c0c5d54 */
if(!s->budget--) { s->failed_pc=0x0c0c5d54u; return 0; }
target=r[14];
r[16]=code_base|0x0c0c5d58u;
r[4]=0x00000004u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c5d58u) { target=s->pc; goto dispatch; }
goto P_0c0c5d58;
P_0c0c5d56: /* original e404, guest PC 0x0c0c5d56 */
if(!s->budget--) { s->failed_pc=0x0c0c5d56u; return 0; }
r[4]=0x00000004u;
goto P_0c0c5d58;
P_0c0c5d58: /* original 65c3, guest PC 0x0c0c5d58 */
if(!s->budget--) { s->failed_pc=0x0c0c5d58u; return 0; }
r[5]=r[12];
goto P_0c0c5d5a;
P_0c0c5d5a: /* original e600, guest PC 0x0c0c5d5a */
if(!s->budget--) { s->failed_pc=0x0c0c5d5au; return 0; }
r[6]=0x00000000u;
goto P_0c0c5d5c;
P_0c0c5d5c: /* original 4e0b, guest PC 0x0c0c5d5c */
if(!s->budget--) { s->failed_pc=0x0c0c5d5cu; return 0; }
target=r[14];
r[16]=code_base|0x0c0c5d60u;
r[4]=0x00000005u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c5d60u) { target=s->pc; goto dispatch; }
goto P_0c0c5d60;
P_0c0c5d5e: /* original e405, guest PC 0x0c0c5d5e */
if(!s->budget--) { s->failed_pc=0x0c0c5d5eu; return 0; }
r[4]=0x00000005u;
goto P_0c0c5d60;
P_0c0c5d60: /* original 65c3, guest PC 0x0c0c5d60 */
if(!s->budget--) { s->failed_pc=0x0c0c5d60u; return 0; }
r[5]=r[12];
goto P_0c0c5d62;
P_0c0c5d62: /* original e600, guest PC 0x0c0c5d62 */
if(!s->budget--) { s->failed_pc=0x0c0c5d62u; return 0; }
r[6]=0x00000000u;
goto P_0c0c5d64;
P_0c0c5d64: /* original 4e0b, guest PC 0x0c0c5d64 */
if(!s->budget--) { s->failed_pc=0x0c0c5d64u; return 0; }
target=r[14];
r[16]=code_base|0x0c0c5d68u;
r[4]=0x00000006u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c5d68u) { target=s->pc; goto dispatch; }
goto P_0c0c5d68;
P_0c0c5d66: /* original e406, guest PC 0x0c0c5d66 */
if(!s->budget--) { s->failed_pc=0x0c0c5d66u; return 0; }
r[4]=0x00000006u;
goto P_0c0c5d68;
P_0c0c5d68: /* original 65c3, guest PC 0x0c0c5d68 */
if(!s->budget--) { s->failed_pc=0x0c0c5d68u; return 0; }
r[5]=r[12];
goto P_0c0c5d6a;
P_0c0c5d6a: /* original e600, guest PC 0x0c0c5d6a */
if(!s->budget--) { s->failed_pc=0x0c0c5d6au; return 0; }
r[6]=0x00000000u;
goto P_0c0c5d6c;
P_0c0c5d6c: /* original a003, guest PC 0x0c0c5d6c */
if(!s->budget--) { s->failed_pc=0x0c0c5d6cu; return 0; }
r[4]=0x00000007u;
goto P_0c0c5d76;
P_0c0c5d6e: /* original e407, guest PC 0x0c0c5d6e */
if(!s->budget--) { s->failed_pc=0x0c0c5d6eu; return 0; }
r[4]=0x00000007u;
goto P_0c0c5d70;
P_0c0c5d70: /* original e400, guest PC 0x0c0c5d70 */
if(!s->budget--) { s->failed_pc=0x0c0c5d70u; return 0; }
r[4]=0x00000000u;
goto P_0c0c5d72;
P_0c0c5d72: /* original 65d3, guest PC 0x0c0c5d72 */
if(!s->budget--) { s->failed_pc=0x0c0c5d72u; return 0; }
r[5]=r[13];
goto P_0c0c5d74;
P_0c0c5d74: /* original 66b3, guest PC 0x0c0c5d74 */
if(!s->budget--) { s->failed_pc=0x0c0c5d74u; return 0; }
r[6]=r[11];
goto P_0c0c5d76;
P_0c0c5d76: /* original 4e0b, guest PC 0x0c0c5d76 */
if(!s->budget--) { s->failed_pc=0x0c0c5d76u; return 0; }
target=r[14];
r[16]=code_base|0x0c0c5d7au;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c5d7au) { target=s->pc; goto dispatch; }
goto P_0c0c5d7a;
P_0c0c5d78: /* original 0009, guest PC 0x0c0c5d78 */
if(!s->budget--) { s->failed_pc=0x0c0c5d78u; return 0; }
goto P_0c0c5d7a;
P_0c0c5d7a: /* original 4f26, guest PC 0x0c0c5d7a */
if(!s->budget--) { s->failed_pc=0x0c0c5d7au; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0c5d7c;
P_0c0c5d7c: /* original 6bf6, guest PC 0x0c0c5d7c */
if(!s->budget--) { s->failed_pc=0x0c0c5d7cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0c5d7e;
P_0c0c5d7e: /* original 6cf6, guest PC 0x0c0c5d7e */
if(!s->budget--) { s->failed_pc=0x0c0c5d7eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0c5d80;
P_0c0c5d80: /* original 6df6, guest PC 0x0c0c5d80 */
if(!s->budget--) { s->failed_pc=0x0c0c5d80u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0c5d82;
P_0c0c5d82: /* original 000b, guest PC 0x0c0c5d82 */
if(!s->budget--) { s->failed_pc=0x0c0c5d82u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0c5d84: /* original 6ef6, guest PC 0x0c0c5d84 */
if(!s->budget--) { s->failed_pc=0x0c0c5d84u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0c5d86;
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
