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
int vf3_away_batch12_adapter_14(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c081e68u: goto P_0c081e68;
case 0x0c081e6au: goto P_0c081e6a;
case 0x0c081e6cu: goto P_0c081e6c;
case 0x0c081e6eu: goto P_0c081e6e;
case 0x0c081e70u: goto P_0c081e70;
case 0x0c081e72u: goto P_0c081e72;
case 0x0c081e74u: goto P_0c081e74;
case 0x0c081e76u: goto P_0c081e76;
case 0x0c081e78u: goto P_0c081e78;
case 0x0c081e7au: goto P_0c081e7a;
case 0x0c081e7cu: goto P_0c081e7c;
case 0x0c081e7eu: goto P_0c081e7e;
case 0x0c081e80u: goto P_0c081e80;
case 0x0c081e82u: goto P_0c081e82;
case 0x0c081e84u: goto P_0c081e84;
case 0x0c081e86u: goto P_0c081e86;
case 0x0c081e88u: goto P_0c081e88;
case 0x0c081e8au: goto P_0c081e8a;
case 0x0c081e8cu: goto P_0c081e8c;
case 0x0c081e8eu: goto P_0c081e8e;
case 0x0c081e90u: goto P_0c081e90;
case 0x0c081e92u: goto P_0c081e92;
case 0x0c081e94u: goto P_0c081e94;
case 0x0c081e96u: goto P_0c081e96;
case 0x0c081e98u: goto P_0c081e98;
case 0x0c081e9au: goto P_0c081e9a;
case 0x0c081e9cu: goto P_0c081e9c;
case 0x0c081e9eu: goto P_0c081e9e;
case 0x0c081ea0u: goto P_0c081ea0;
case 0x0c081ea2u: goto P_0c081ea2;
case 0x0c081ea4u: goto P_0c081ea4;
case 0x0c081ea6u: goto P_0c081ea6;
case 0x0c081ea8u: goto P_0c081ea8;
case 0x0c081eaau: goto P_0c081eaa;
case 0x0c081eacu: goto P_0c081eac;
case 0x0c081eaeu: goto P_0c081eae;
case 0x0c081eb0u: goto P_0c081eb0;
case 0x0c081eb2u: goto P_0c081eb2;
case 0x0c081eb4u: goto P_0c081eb4;
case 0x0c081eb6u: goto P_0c081eb6;
case 0x0c081eb8u: goto P_0c081eb8;
case 0x0c081ebau: goto P_0c081eba;
case 0x0c081ebcu: goto P_0c081ebc;
case 0x0c081ebeu: goto P_0c081ebe;
case 0x0c081ec0u: goto P_0c081ec0;
case 0x0c081ec2u: goto P_0c081ec2;
case 0x0c081ec4u: goto P_0c081ec4;
case 0x0c081ec6u: goto P_0c081ec6;
case 0x0c081ec8u: goto P_0c081ec8;
case 0x0c081ecau: goto P_0c081eca;
case 0x0c081eccu: goto P_0c081ecc;
case 0x0c081eceu: goto P_0c081ece;
case 0x0c081ed0u: goto P_0c081ed0;
case 0x0c081ed2u: goto P_0c081ed2;
case 0x0c081ed4u: goto P_0c081ed4;
case 0x0c081ed6u: goto P_0c081ed6;
case 0x0c081ed8u: goto P_0c081ed8;
case 0x0c081edau: goto P_0c081eda;
case 0x0c081edcu: goto P_0c081edc;
case 0x0c081edeu: goto P_0c081ede;
case 0x0c081ee0u: goto P_0c081ee0;
case 0x0c081ee2u: goto P_0c081ee2;
case 0x0c081ee4u: goto P_0c081ee4;
case 0x0c081ee6u: goto P_0c081ee6;
case 0x0c081ee8u: goto P_0c081ee8;
case 0x0c081eeau: goto P_0c081eea;
case 0x0c081eecu: goto P_0c081eec;
case 0x0c081eeeu: goto P_0c081eee;
case 0x0c081ef0u: goto P_0c081ef0;
case 0x0c081ef2u: goto P_0c081ef2;
case 0x0c081ef4u: goto P_0c081ef4;
case 0x0c081ef6u: goto P_0c081ef6;
case 0x0c081ef8u: goto P_0c081ef8;
case 0x0c081efau: goto P_0c081efa;
case 0x0c081efcu: goto P_0c081efc;
case 0x0c081efeu: goto P_0c081efe;
case 0x0c081f00u: goto P_0c081f00;
case 0x0c081f02u: goto P_0c081f02;
case 0x0c081f04u: goto P_0c081f04;
case 0x0c081f06u: goto P_0c081f06;
case 0x0c081f08u: goto P_0c081f08;
case 0x0c081f0au: goto P_0c081f0a;
case 0x0c081f0cu: goto P_0c081f0c;
case 0x0c081f0eu: goto P_0c081f0e;
case 0x0c081f10u: goto P_0c081f10;
case 0x0c081f12u: goto P_0c081f12;
case 0x0c081f14u: goto P_0c081f14;
case 0x0c081f16u: goto P_0c081f16;
case 0x0c081f18u: goto P_0c081f18;
case 0x0c081f1au: goto P_0c081f1a;
case 0x0c081f1cu: goto P_0c081f1c;
case 0x0c081f1eu: goto P_0c081f1e;
case 0x0c081f20u: goto P_0c081f20;
case 0x0c081f22u: goto P_0c081f22;
case 0x0c081f24u: goto P_0c081f24;
case 0x0c081f26u: goto P_0c081f26;
case 0x0c081f28u: goto P_0c081f28;
case 0x0c081f2au: goto P_0c081f2a;
case 0x0c081f2cu: goto P_0c081f2c;
case 0x0c081f2eu: goto P_0c081f2e;
case 0x0c081f30u: goto P_0c081f30;
case 0x0c081f32u: goto P_0c081f32;
case 0x0c081f34u: goto P_0c081f34;
case 0x0c081f36u: goto P_0c081f36;
case 0x0c081f38u: goto P_0c081f38;
case 0x0c081f3au: goto P_0c081f3a;
case 0x0c081f3cu: goto P_0c081f3c;
case 0x0c081f3eu: goto P_0c081f3e;
case 0x0c081f40u: goto P_0c081f40;
case 0x0c081f42u: goto P_0c081f42;
case 0x0c081f44u: goto P_0c081f44;
case 0x0c081f46u: goto P_0c081f46;
case 0x0c081f48u: goto P_0c081f48;
case 0x0c081f4au: goto P_0c081f4a;
case 0x0c081f4cu: goto P_0c081f4c;
case 0x0c081f4eu: goto P_0c081f4e;
case 0x0c081f50u: goto P_0c081f50;
case 0x0c081f52u: goto P_0c081f52;
case 0x0c081f54u: goto P_0c081f54;
case 0x0c081f56u: goto P_0c081f56;
case 0x0c081f58u: goto P_0c081f58;
case 0x0c081f5au: goto P_0c081f5a;
case 0x0c081f5cu: goto P_0c081f5c;
case 0x0c081f5eu: goto P_0c081f5e;
case 0x0c081f60u: goto P_0c081f60;
case 0x0c081f62u: goto P_0c081f62;
case 0x0c081f64u: goto P_0c081f64;
case 0x0c081f66u: goto P_0c081f66;
case 0x0c081f68u: goto P_0c081f68;
case 0x0c081f6au: goto P_0c081f6a;
case 0x0c081f6cu: goto P_0c081f6c;
case 0x0c081f6eu: goto P_0c081f6e;
case 0x0c081f70u: goto P_0c081f70;
case 0x0c081f72u: goto P_0c081f72;
case 0x0c081f74u: goto P_0c081f74;
case 0x0c081f76u: goto P_0c081f76;
case 0x0c081f78u: goto P_0c081f78;
case 0x0c081f7au: goto P_0c081f7a;
case 0x0c081f7cu: goto P_0c081f7c;
case 0x0c081f7eu: goto P_0c081f7e;
case 0x0c081f80u: goto P_0c081f80;
case 0x0c081f82u: goto P_0c081f82;
case 0x0c081facu: goto P_0c081fac;
case 0x0c081faeu: goto P_0c081fae;
case 0x0c081fb0u: goto P_0c081fb0;
case 0x0c081fb2u: goto P_0c081fb2;
case 0x0c081fb4u: goto P_0c081fb4;
case 0x0c081fb6u: goto P_0c081fb6;
case 0x0c081fb8u: goto P_0c081fb8;
case 0x0c081fbau: goto P_0c081fba;
case 0x0c081fbcu: goto P_0c081fbc;
case 0x0c081fbeu: goto P_0c081fbe;
case 0x0c081fc0u: goto P_0c081fc0;
case 0x0c081fc2u: goto P_0c081fc2;
case 0x0c081fc4u: goto P_0c081fc4;
case 0x0c081fc6u: goto P_0c081fc6;
case 0x0c081fc8u: goto P_0c081fc8;
case 0x0c081fcau: goto P_0c081fca;
case 0x0c081fccu: goto P_0c081fcc;
case 0x0c081fceu: goto P_0c081fce;
case 0x0c081fd0u: goto P_0c081fd0;
case 0x0c081fd2u: goto P_0c081fd2;
case 0x0c081fd4u: goto P_0c081fd4;
case 0x0c081fd6u: goto P_0c081fd6;
case 0x0c081fd8u: goto P_0c081fd8;
case 0x0c081fdau: goto P_0c081fda;
case 0x0c081fdcu: goto P_0c081fdc;
case 0x0c081fdeu: goto P_0c081fde;
case 0x0c081fe0u: goto P_0c081fe0;
case 0x0c081fe2u: goto P_0c081fe2;
case 0x0c081fe4u: goto P_0c081fe4;
case 0x0c081fe6u: goto P_0c081fe6;
case 0x0c081fe8u: goto P_0c081fe8;
case 0x0c081feau: goto P_0c081fea;
case 0x0c081fecu: goto P_0c081fec;
case 0x0c081feeu: goto P_0c081fee;
case 0x0c081ff0u: goto P_0c081ff0;
case 0x0c081ff2u: goto P_0c081ff2;
case 0x0c081ff4u: goto P_0c081ff4;
case 0x0c081ff6u: goto P_0c081ff6;
case 0x0c081ff8u: goto P_0c081ff8;
case 0x0c081ffau: goto P_0c081ffa;
case 0x0c081ffcu: goto P_0c081ffc;
case 0x0c081ffeu: goto P_0c081ffe;
case 0x0c082000u: goto P_0c082000;
case 0x0c082002u: goto P_0c082002;
case 0x0c082004u: goto P_0c082004;
case 0x0c082006u: goto P_0c082006;
case 0x0c082008u: goto P_0c082008;
case 0x0c08200au: goto P_0c08200a;
case 0x0c08200cu: goto P_0c08200c;
case 0x0c08200eu: goto P_0c08200e;
case 0x0c082010u: goto P_0c082010;
case 0x0c082012u: goto P_0c082012;
case 0x0c082014u: goto P_0c082014;
case 0x0c082016u: goto P_0c082016;
case 0x0c082018u: goto P_0c082018;
case 0x0c08201au: goto P_0c08201a;
case 0x0c08201cu: goto P_0c08201c;
case 0x0c08201eu: goto P_0c08201e;
case 0x0c082020u: goto P_0c082020;
case 0x0c082022u: goto P_0c082022;
case 0x0c082024u: goto P_0c082024;
case 0x0c082026u: goto P_0c082026;
case 0x0c082028u: goto P_0c082028;
case 0x0c08202au: goto P_0c08202a;
case 0x0c08202cu: goto P_0c08202c;
case 0x0c08202eu: goto P_0c08202e;
case 0x0c082030u: goto P_0c082030;
case 0x0c082032u: goto P_0c082032;
case 0x0c082034u: goto P_0c082034;
case 0x0c082036u: goto P_0c082036;
case 0x0c082038u: goto P_0c082038;
case 0x0c08203au: goto P_0c08203a;
case 0x0c08203cu: goto P_0c08203c;
case 0x0c08203eu: goto P_0c08203e;
case 0x0c082040u: goto P_0c082040;
case 0x0c082042u: goto P_0c082042;
case 0x0c082044u: goto P_0c082044;
case 0x0c082046u: goto P_0c082046;
case 0x0c082048u: goto P_0c082048;
case 0x0c08204au: goto P_0c08204a;
case 0x0c08204cu: goto P_0c08204c;
case 0x0c08204eu: goto P_0c08204e;
case 0x0c082050u: goto P_0c082050;
case 0x0c082052u: goto P_0c082052;
case 0x0c082054u: goto P_0c082054;
default: return vf3_matrix_family(target,s,ram);
}
P_0c081e68: /* original 2fe6, guest PC 0x0c081e68 */
if(!s->budget--) { s->failed_pc=0x0c081e68u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c081e6a;
P_0c081e6a: /* original e307, guest PC 0x0c081e6a */
if(!s->budget--) { s->failed_pc=0x0c081e6au; return 0; }
r[3]=0x00000007u;
goto P_0c081e6c;
P_0c081e6c: /* original 2fd6, guest PC 0x0c081e6c */
if(!s->budget--) { s->failed_pc=0x0c081e6cu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c081e6e;
P_0c081e6e: /* original 453c, guest PC 0x0c081e6e */
if(!s->budget--) { s->failed_pc=0x0c081e6eu; return 0; }
r[5]=(r[3]&0x80000000u)?((r[3]&31u)?(uint32_t)((int32_t)r[5]>>((-r[3])&31u)):((int32_t)r[5]<0?0xffffffffu:0)):r[5]<<(r[3]&31u);
goto P_0c081e70;
P_0c081e70: /* original 2fc6, guest PC 0x0c081e70 */
if(!s->budget--) { s->failed_pc=0x0c081e70u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c081e72;
P_0c081e72: /* original 6c43, guest PC 0x0c081e72 */
if(!s->budget--) { s->failed_pc=0x0c081e72u; return 0; }
r[12]=r[4];
goto P_0c081e74;
P_0c081e74: /* original 2fb6, guest PC 0x0c081e74 */
if(!s->budget--) { s->failed_pc=0x0c081e74u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c081e76;
P_0c081e76: /* original 7c02, guest PC 0x0c081e76 */
if(!s->budget--) { s->failed_pc=0x0c081e76u; return 0; }
r[12]+=0x00000002u;
goto P_0c081e78;
P_0c081e78: /* original 2fa6, guest PC 0x0c081e78 */
if(!s->budget--) { s->failed_pc=0x0c081e78u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c081e7a;
P_0c081e7a: /* original 6d63, guest PC 0x0c081e7a */
if(!s->budget--) { s->failed_pc=0x0c081e7au; return 0; }
r[13]=r[6];
goto P_0c081e7c;
P_0c081e7c: /* original 4f22, guest PC 0x0c081e7c */
if(!s->budget--) { s->failed_pc=0x0c081e7cu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c081e7e;
P_0c081e7e: /* original db4a, guest PC 0x0c081e7e */
if(!s->budget--) { s->failed_pc=0x0c081e7eu; return 0; }
r[11]=read(ram,0x0c081fa8u,4);
goto P_0c081e80;
P_0c081e80: /* original 4c00, guest PC 0x0c081e80 */
if(!s->budget--) { s->failed_pc=0x0c081e80u; return 0; }
r[17]=(r[17]&~1u)|((r[12]>>31)!=0);
r[12]<<=1;
goto P_0c081e82;
P_0c081e82: /* original de48, guest PC 0x0c081e82 */
if(!s->budget--) { s->failed_pc=0x0c081e82u; return 0; }
r[14]=read(ram,0x0c081fa4u,4);
goto P_0c081e84;
P_0c081e84: /* original 2dd8, guest PC 0x0c081e84 */
if(!s->budget--) { s->failed_pc=0x0c081e84u; return 0; }
r[17]=(r[17]&~1u)|(((r[13]&r[13])==0)!=0);
goto P_0c081e86;
P_0c081e86: /* original 2c5b, guest PC 0x0c081e86 */
if(!s->budget--) { s->failed_pc=0x0c081e86u; return 0; }
r[12]|=r[5];
goto P_0c081e88;
P_0c081e88: /* original 8f07, guest PC 0x0c081e88 */
if(!s->budget--) { s->failed_pc=0x0c081e88u; return 0; }
cond=r[17]&1u;
r[10]=0x00000010u;
if(!cond) { goto P_0c081e9a; }
goto P_0c081e8c;
P_0c081e8a: /* original ea10, guest PC 0x0c081e8a */
if(!s->budget--) { s->failed_pc=0x0c081e8au; return 0; }
r[10]=0x00000010u;
goto P_0c081e8c;
P_0c081e8c: /* original 66e3, guest PC 0x0c081e8c */
if(!s->budget--) { s->failed_pc=0x0c081e8cu; return 0; }
r[6]=r[14];
goto P_0c081e8e;
P_0c081e8e: /* original 2fa6, guest PC 0x0c081e8e */
if(!s->budget--) { s->failed_pc=0x0c081e8eu; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c081e90;
P_0c081e90: /* original 9578, guest PC 0x0c081e90 */
if(!s->budget--) { s->failed_pc=0x0c081e90u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c081f84u,2);
goto P_0c081e92;
P_0c081e92: /* original e700, guest PC 0x0c081e92 */
if(!s->budget--) { s->failed_pc=0x0c081e92u; return 0; }
r[7]=0x00000000u;
goto P_0c081e94;
P_0c081e94: /* original 4b0b, guest PC 0x0c081e94 */
if(!s->budget--) { s->failed_pc=0x0c081e94u; return 0; }
target=r[11];
r[16]=code_base|0x0c081e98u;
r[4]=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c081e98u) { target=s->pc; goto dispatch; }
goto P_0c081e98;
P_0c081e96: /* original 64c3, guest PC 0x0c081e96 */
if(!s->budget--) { s->failed_pc=0x0c081e96u; return 0; }
r[4]=r[12];
goto P_0c081e98;
P_0c081e98: /* original 7f04, guest PC 0x0c081e98 */
if(!s->budget--) { s->failed_pc=0x0c081e98u; return 0; }
r[15]+=0x00000004u;
goto P_0c081e9a;
P_0c081e9a: /* original 60d3, guest PC 0x0c081e9a */
if(!s->budget--) { s->failed_pc=0x0c081e9au; return 0; }
r[0]=r[13];
goto P_0c081e9c;
P_0c081e9c: /* original 8801, guest PC 0x0c081e9c */
if(!s->budget--) { s->failed_pc=0x0c081e9cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c081e9e;
P_0c081e9e: /* original 8b06, guest PC 0x0c081e9e */
if(!s->budget--) { s->failed_pc=0x0c081e9eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c081eae; }
goto P_0c081ea0;
P_0c081ea0: /* original 66e3, guest PC 0x0c081ea0 */
if(!s->budget--) { s->failed_pc=0x0c081ea0u; return 0; }
r[6]=r[14];
goto P_0c081ea2;
P_0c081ea2: /* original 2fa6, guest PC 0x0c081ea2 */
if(!s->budget--) { s->failed_pc=0x0c081ea2u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c081ea4;
P_0c081ea4: /* original 956f, guest PC 0x0c081ea4 */
if(!s->budget--) { s->failed_pc=0x0c081ea4u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c081f86u,2);
goto P_0c081ea6;
P_0c081ea6: /* original e700, guest PC 0x0c081ea6 */
if(!s->budget--) { s->failed_pc=0x0c081ea6u; return 0; }
r[7]=0x00000000u;
goto P_0c081ea8;
P_0c081ea8: /* original 4b0b, guest PC 0x0c081ea8 */
if(!s->budget--) { s->failed_pc=0x0c081ea8u; return 0; }
target=r[11];
r[16]=code_base|0x0c081eacu;
r[4]=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c081eacu) { target=s->pc; goto dispatch; }
goto P_0c081eac;
P_0c081eaa: /* original 64c3, guest PC 0x0c081eaa */
if(!s->budget--) { s->failed_pc=0x0c081eaau; return 0; }
r[4]=r[12];
goto P_0c081eac;
P_0c081eac: /* original 7f04, guest PC 0x0c081eac */
if(!s->budget--) { s->failed_pc=0x0c081eacu; return 0; }
r[15]+=0x00000004u;
goto P_0c081eae;
P_0c081eae: /* original 60d3, guest PC 0x0c081eae */
if(!s->budget--) { s->failed_pc=0x0c081eaeu; return 0; }
r[0]=r[13];
goto P_0c081eb0;
P_0c081eb0: /* original 8802, guest PC 0x0c081eb0 */
if(!s->budget--) { s->failed_pc=0x0c081eb0u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c081eb2;
P_0c081eb2: /* original 8b06, guest PC 0x0c081eb2 */
if(!s->budget--) { s->failed_pc=0x0c081eb2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c081ec2; }
goto P_0c081eb4;
P_0c081eb4: /* original 66e3, guest PC 0x0c081eb4 */
if(!s->budget--) { s->failed_pc=0x0c081eb4u; return 0; }
r[6]=r[14];
goto P_0c081eb6;
P_0c081eb6: /* original 2fa6, guest PC 0x0c081eb6 */
if(!s->budget--) { s->failed_pc=0x0c081eb6u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c081eb8;
P_0c081eb8: /* original 9566, guest PC 0x0c081eb8 */
if(!s->budget--) { s->failed_pc=0x0c081eb8u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c081f88u,2);
goto P_0c081eba;
P_0c081eba: /* original e700, guest PC 0x0c081eba */
if(!s->budget--) { s->failed_pc=0x0c081ebau; return 0; }
r[7]=0x00000000u;
goto P_0c081ebc;
P_0c081ebc: /* original 4b0b, guest PC 0x0c081ebc */
if(!s->budget--) { s->failed_pc=0x0c081ebcu; return 0; }
target=r[11];
r[16]=code_base|0x0c081ec0u;
r[4]=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c081ec0u) { target=s->pc; goto dispatch; }
goto P_0c081ec0;
P_0c081ebe: /* original 64c3, guest PC 0x0c081ebe */
if(!s->budget--) { s->failed_pc=0x0c081ebeu; return 0; }
r[4]=r[12];
goto P_0c081ec0;
P_0c081ec0: /* original 7f04, guest PC 0x0c081ec0 */
if(!s->budget--) { s->failed_pc=0x0c081ec0u; return 0; }
r[15]+=0x00000004u;
goto P_0c081ec2;
P_0c081ec2: /* original 60d3, guest PC 0x0c081ec2 */
if(!s->budget--) { s->failed_pc=0x0c081ec2u; return 0; }
r[0]=r[13];
goto P_0c081ec4;
P_0c081ec4: /* original 8804, guest PC 0x0c081ec4 */
if(!s->budget--) { s->failed_pc=0x0c081ec4u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000004u)!=0);
goto P_0c081ec6;
P_0c081ec6: /* original 8b06, guest PC 0x0c081ec6 */
if(!s->budget--) { s->failed_pc=0x0c081ec6u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c081ed6; }
goto P_0c081ec8;
P_0c081ec8: /* original 66e3, guest PC 0x0c081ec8 */
if(!s->budget--) { s->failed_pc=0x0c081ec8u; return 0; }
r[6]=r[14];
goto P_0c081eca;
P_0c081eca: /* original 2fa6, guest PC 0x0c081eca */
if(!s->budget--) { s->failed_pc=0x0c081ecau; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c081ecc;
P_0c081ecc: /* original 955d, guest PC 0x0c081ecc */
if(!s->budget--) { s->failed_pc=0x0c081eccu; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c081f8au,2);
goto P_0c081ece;
P_0c081ece: /* original e700, guest PC 0x0c081ece */
if(!s->budget--) { s->failed_pc=0x0c081eceu; return 0; }
r[7]=0x00000000u;
goto P_0c081ed0;
P_0c081ed0: /* original 4b0b, guest PC 0x0c081ed0 */
if(!s->budget--) { s->failed_pc=0x0c081ed0u; return 0; }
target=r[11];
r[16]=code_base|0x0c081ed4u;
r[4]=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c081ed4u) { target=s->pc; goto dispatch; }
goto P_0c081ed4;
P_0c081ed2: /* original 64c3, guest PC 0x0c081ed2 */
if(!s->budget--) { s->failed_pc=0x0c081ed2u; return 0; }
r[4]=r[12];
goto P_0c081ed4;
P_0c081ed4: /* original 7f04, guest PC 0x0c081ed4 */
if(!s->budget--) { s->failed_pc=0x0c081ed4u; return 0; }
r[15]+=0x00000004u;
goto P_0c081ed6;
P_0c081ed6: /* original 60d3, guest PC 0x0c081ed6 */
if(!s->budget--) { s->failed_pc=0x0c081ed6u; return 0; }
r[0]=r[13];
goto P_0c081ed8;
P_0c081ed8: /* original 8808, guest PC 0x0c081ed8 */
if(!s->budget--) { s->failed_pc=0x0c081ed8u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000008u)!=0);
goto P_0c081eda;
P_0c081eda: /* original 8b06, guest PC 0x0c081eda */
if(!s->budget--) { s->failed_pc=0x0c081edau; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c081eea; }
goto P_0c081edc;
P_0c081edc: /* original 66e3, guest PC 0x0c081edc */
if(!s->budget--) { s->failed_pc=0x0c081edcu; return 0; }
r[6]=r[14];
goto P_0c081ede;
P_0c081ede: /* original 2fa6, guest PC 0x0c081ede */
if(!s->budget--) { s->failed_pc=0x0c081edeu; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c081ee0;
P_0c081ee0: /* original 9554, guest PC 0x0c081ee0 */
if(!s->budget--) { s->failed_pc=0x0c081ee0u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c081f8cu,2);
goto P_0c081ee2;
P_0c081ee2: /* original e700, guest PC 0x0c081ee2 */
if(!s->budget--) { s->failed_pc=0x0c081ee2u; return 0; }
r[7]=0x00000000u;
goto P_0c081ee4;
P_0c081ee4: /* original 4b0b, guest PC 0x0c081ee4 */
if(!s->budget--) { s->failed_pc=0x0c081ee4u; return 0; }
target=r[11];
r[16]=code_base|0x0c081ee8u;
r[4]=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c081ee8u) { target=s->pc; goto dispatch; }
goto P_0c081ee8;
P_0c081ee6: /* original 64c3, guest PC 0x0c081ee6 */
if(!s->budget--) { s->failed_pc=0x0c081ee6u; return 0; }
r[4]=r[12];
goto P_0c081ee8;
P_0c081ee8: /* original 7f04, guest PC 0x0c081ee8 */
if(!s->budget--) { s->failed_pc=0x0c081ee8u; return 0; }
r[15]+=0x00000004u;
goto P_0c081eea;
P_0c081eea: /* original 60d3, guest PC 0x0c081eea */
if(!s->budget--) { s->failed_pc=0x0c081eeau; return 0; }
r[0]=r[13];
goto P_0c081eec;
P_0c081eec: /* original 8810, guest PC 0x0c081eec */
if(!s->budget--) { s->failed_pc=0x0c081eecu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000010u)!=0);
goto P_0c081eee;
P_0c081eee: /* original 8b06, guest PC 0x0c081eee */
if(!s->budget--) { s->failed_pc=0x0c081eeeu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c081efe; }
goto P_0c081ef0;
P_0c081ef0: /* original 66e3, guest PC 0x0c081ef0 */
if(!s->budget--) { s->failed_pc=0x0c081ef0u; return 0; }
r[6]=r[14];
goto P_0c081ef2;
P_0c081ef2: /* original 2fa6, guest PC 0x0c081ef2 */
if(!s->budget--) { s->failed_pc=0x0c081ef2u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c081ef4;
P_0c081ef4: /* original 954b, guest PC 0x0c081ef4 */
if(!s->budget--) { s->failed_pc=0x0c081ef4u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c081f8eu,2);
goto P_0c081ef6;
P_0c081ef6: /* original e700, guest PC 0x0c081ef6 */
if(!s->budget--) { s->failed_pc=0x0c081ef6u; return 0; }
r[7]=0x00000000u;
goto P_0c081ef8;
P_0c081ef8: /* original 4b0b, guest PC 0x0c081ef8 */
if(!s->budget--) { s->failed_pc=0x0c081ef8u; return 0; }
target=r[11];
r[16]=code_base|0x0c081efcu;
r[4]=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c081efcu) { target=s->pc; goto dispatch; }
goto P_0c081efc;
P_0c081efa: /* original 64c3, guest PC 0x0c081efa */
if(!s->budget--) { s->failed_pc=0x0c081efau; return 0; }
r[4]=r[12];
goto P_0c081efc;
P_0c081efc: /* original 7f04, guest PC 0x0c081efc */
if(!s->budget--) { s->failed_pc=0x0c081efcu; return 0; }
r[15]+=0x00000004u;
goto P_0c081efe;
P_0c081efe: /* original 60d3, guest PC 0x0c081efe */
if(!s->budget--) { s->failed_pc=0x0c081efeu; return 0; }
r[0]=r[13];
goto P_0c081f00;
P_0c081f00: /* original 8820, guest PC 0x0c081f00 */
if(!s->budget--) { s->failed_pc=0x0c081f00u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000020u)!=0);
goto P_0c081f02;
P_0c081f02: /* original 8b06, guest PC 0x0c081f02 */
if(!s->budget--) { s->failed_pc=0x0c081f02u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c081f12; }
goto P_0c081f04;
P_0c081f04: /* original 66e3, guest PC 0x0c081f04 */
if(!s->budget--) { s->failed_pc=0x0c081f04u; return 0; }
r[6]=r[14];
goto P_0c081f06;
P_0c081f06: /* original 2fa6, guest PC 0x0c081f06 */
if(!s->budget--) { s->failed_pc=0x0c081f06u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c081f08;
P_0c081f08: /* original 9542, guest PC 0x0c081f08 */
if(!s->budget--) { s->failed_pc=0x0c081f08u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c081f90u,2);
goto P_0c081f0a;
P_0c081f0a: /* original e700, guest PC 0x0c081f0a */
if(!s->budget--) { s->failed_pc=0x0c081f0au; return 0; }
r[7]=0x00000000u;
goto P_0c081f0c;
P_0c081f0c: /* original 4b0b, guest PC 0x0c081f0c */
if(!s->budget--) { s->failed_pc=0x0c081f0cu; return 0; }
target=r[11];
r[16]=code_base|0x0c081f10u;
r[4]=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c081f10u) { target=s->pc; goto dispatch; }
goto P_0c081f10;
P_0c081f0e: /* original 64c3, guest PC 0x0c081f0e */
if(!s->budget--) { s->failed_pc=0x0c081f0eu; return 0; }
r[4]=r[12];
goto P_0c081f10;
P_0c081f10: /* original 7f04, guest PC 0x0c081f10 */
if(!s->budget--) { s->failed_pc=0x0c081f10u; return 0; }
r[15]+=0x00000004u;
goto P_0c081f12;
P_0c081f12: /* original 60d3, guest PC 0x0c081f12 */
if(!s->budget--) { s->failed_pc=0x0c081f12u; return 0; }
r[0]=r[13];
goto P_0c081f14;
P_0c081f14: /* original 8840, guest PC 0x0c081f14 */
if(!s->budget--) { s->failed_pc=0x0c081f14u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000040u)!=0);
goto P_0c081f16;
P_0c081f16: /* original 8b06, guest PC 0x0c081f16 */
if(!s->budget--) { s->failed_pc=0x0c081f16u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c081f26; }
goto P_0c081f18;
P_0c081f18: /* original 66e3, guest PC 0x0c081f18 */
if(!s->budget--) { s->failed_pc=0x0c081f18u; return 0; }
r[6]=r[14];
goto P_0c081f1a;
P_0c081f1a: /* original 2fa6, guest PC 0x0c081f1a */
if(!s->budget--) { s->failed_pc=0x0c081f1au; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c081f1c;
P_0c081f1c: /* original 9539, guest PC 0x0c081f1c */
if(!s->budget--) { s->failed_pc=0x0c081f1cu; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c081f92u,2);
goto P_0c081f1e;
P_0c081f1e: /* original e700, guest PC 0x0c081f1e */
if(!s->budget--) { s->failed_pc=0x0c081f1eu; return 0; }
r[7]=0x00000000u;
goto P_0c081f20;
P_0c081f20: /* original 4b0b, guest PC 0x0c081f20 */
if(!s->budget--) { s->failed_pc=0x0c081f20u; return 0; }
target=r[11];
r[16]=code_base|0x0c081f24u;
r[4]=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c081f24u) { target=s->pc; goto dispatch; }
goto P_0c081f24;
P_0c081f22: /* original 64c3, guest PC 0x0c081f22 */
if(!s->budget--) { s->failed_pc=0x0c081f22u; return 0; }
r[4]=r[12];
goto P_0c081f24;
P_0c081f24: /* original 7f04, guest PC 0x0c081f24 */
if(!s->budget--) { s->failed_pc=0x0c081f24u; return 0; }
r[15]+=0x00000004u;
goto P_0c081f26;
P_0c081f26: /* original 9235, guest PC 0x0c081f26 */
if(!s->budget--) { s->failed_pc=0x0c081f26u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c081f94u,2);
goto P_0c081f28;
P_0c081f28: /* original 3d20, guest PC 0x0c081f28 */
if(!s->budget--) { s->failed_pc=0x0c081f28u; return 0; }
r[17]=(r[17]&~1u)|((r[13]==r[2])!=0);
goto P_0c081f2a;
P_0c081f2a: /* original 8b06, guest PC 0x0c081f2a */
if(!s->budget--) { s->failed_pc=0x0c081f2au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c081f3a; }
goto P_0c081f2c;
P_0c081f2c: /* original 66e3, guest PC 0x0c081f2c */
if(!s->budget--) { s->failed_pc=0x0c081f2cu; return 0; }
r[6]=r[14];
goto P_0c081f2e;
P_0c081f2e: /* original 2fa6, guest PC 0x0c081f2e */
if(!s->budget--) { s->failed_pc=0x0c081f2eu; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c081f30;
P_0c081f30: /* original 9531, guest PC 0x0c081f30 */
if(!s->budget--) { s->failed_pc=0x0c081f30u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c081f96u,2);
goto P_0c081f32;
P_0c081f32: /* original e700, guest PC 0x0c081f32 */
if(!s->budget--) { s->failed_pc=0x0c081f32u; return 0; }
r[7]=0x00000000u;
goto P_0c081f34;
P_0c081f34: /* original 4b0b, guest PC 0x0c081f34 */
if(!s->budget--) { s->failed_pc=0x0c081f34u; return 0; }
target=r[11];
r[16]=code_base|0x0c081f38u;
r[4]=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c081f38u) { target=s->pc; goto dispatch; }
goto P_0c081f38;
P_0c081f36: /* original 64c3, guest PC 0x0c081f36 */
if(!s->budget--) { s->failed_pc=0x0c081f36u; return 0; }
r[4]=r[12];
goto P_0c081f38;
P_0c081f38: /* original 7f04, guest PC 0x0c081f38 */
if(!s->budget--) { s->failed_pc=0x0c081f38u; return 0; }
r[15]+=0x00000004u;
goto P_0c081f3a;
P_0c081f3a: /* original 922d, guest PC 0x0c081f3a */
if(!s->budget--) { s->failed_pc=0x0c081f3au; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c081f98u,2);
goto P_0c081f3c;
P_0c081f3c: /* original 3d20, guest PC 0x0c081f3c */
if(!s->budget--) { s->failed_pc=0x0c081f3cu; return 0; }
r[17]=(r[17]&~1u)|((r[13]==r[2])!=0);
goto P_0c081f3e;
P_0c081f3e: /* original 8b06, guest PC 0x0c081f3e */
if(!s->budget--) { s->failed_pc=0x0c081f3eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c081f4e; }
goto P_0c081f40;
P_0c081f40: /* original 66e3, guest PC 0x0c081f40 */
if(!s->budget--) { s->failed_pc=0x0c081f40u; return 0; }
r[6]=r[14];
goto P_0c081f42;
P_0c081f42: /* original 2fa6, guest PC 0x0c081f42 */
if(!s->budget--) { s->failed_pc=0x0c081f42u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c081f44;
P_0c081f44: /* original 9529, guest PC 0x0c081f44 */
if(!s->budget--) { s->failed_pc=0x0c081f44u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c081f9au,2);
goto P_0c081f46;
P_0c081f46: /* original e700, guest PC 0x0c081f46 */
if(!s->budget--) { s->failed_pc=0x0c081f46u; return 0; }
r[7]=0x00000000u;
goto P_0c081f48;
P_0c081f48: /* original 4b0b, guest PC 0x0c081f48 */
if(!s->budget--) { s->failed_pc=0x0c081f48u; return 0; }
target=r[11];
r[16]=code_base|0x0c081f4cu;
r[4]=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c081f4cu) { target=s->pc; goto dispatch; }
goto P_0c081f4c;
P_0c081f4a: /* original 64c3, guest PC 0x0c081f4a */
if(!s->budget--) { s->failed_pc=0x0c081f4au; return 0; }
r[4]=r[12];
goto P_0c081f4c;
P_0c081f4c: /* original 7f04, guest PC 0x0c081f4c */
if(!s->budget--) { s->failed_pc=0x0c081f4cu; return 0; }
r[15]+=0x00000004u;
goto P_0c081f4e;
P_0c081f4e: /* original 9225, guest PC 0x0c081f4e */
if(!s->budget--) { s->failed_pc=0x0c081f4eu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c081f9cu,2);
goto P_0c081f50;
P_0c081f50: /* original 3d20, guest PC 0x0c081f50 */
if(!s->budget--) { s->failed_pc=0x0c081f50u; return 0; }
r[17]=(r[17]&~1u)|((r[13]==r[2])!=0);
goto P_0c081f52;
P_0c081f52: /* original 8b06, guest PC 0x0c081f52 */
if(!s->budget--) { s->failed_pc=0x0c081f52u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c081f62; }
goto P_0c081f54;
P_0c081f54: /* original 66e3, guest PC 0x0c081f54 */
if(!s->budget--) { s->failed_pc=0x0c081f54u; return 0; }
r[6]=r[14];
goto P_0c081f56;
P_0c081f56: /* original 2fa6, guest PC 0x0c081f56 */
if(!s->budget--) { s->failed_pc=0x0c081f56u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c081f58;
P_0c081f58: /* original 9521, guest PC 0x0c081f58 */
if(!s->budget--) { s->failed_pc=0x0c081f58u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c081f9eu,2);
goto P_0c081f5a;
P_0c081f5a: /* original e700, guest PC 0x0c081f5a */
if(!s->budget--) { s->failed_pc=0x0c081f5au; return 0; }
r[7]=0x00000000u;
goto P_0c081f5c;
P_0c081f5c: /* original 4b0b, guest PC 0x0c081f5c */
if(!s->budget--) { s->failed_pc=0x0c081f5cu; return 0; }
target=r[11];
r[16]=code_base|0x0c081f60u;
r[4]=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c081f60u) { target=s->pc; goto dispatch; }
goto P_0c081f60;
P_0c081f5e: /* original 64c3, guest PC 0x0c081f5e */
if(!s->budget--) { s->failed_pc=0x0c081f5eu; return 0; }
r[4]=r[12];
goto P_0c081f60;
P_0c081f60: /* original 7f04, guest PC 0x0c081f60 */
if(!s->budget--) { s->failed_pc=0x0c081f60u; return 0; }
r[15]+=0x00000004u;
goto P_0c081f62;
P_0c081f62: /* original 921d, guest PC 0x0c081f62 */
if(!s->budget--) { s->failed_pc=0x0c081f62u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c081fa0u,2);
goto P_0c081f64;
P_0c081f64: /* original 3d20, guest PC 0x0c081f64 */
if(!s->budget--) { s->failed_pc=0x0c081f64u; return 0; }
r[17]=(r[17]&~1u)|((r[13]==r[2])!=0);
goto P_0c081f66;
P_0c081f66: /* original 8b06, guest PC 0x0c081f66 */
if(!s->budget--) { s->failed_pc=0x0c081f66u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c081f76; }
goto P_0c081f68;
P_0c081f68: /* original 66e3, guest PC 0x0c081f68 */
if(!s->budget--) { s->failed_pc=0x0c081f68u; return 0; }
r[6]=r[14];
goto P_0c081f6a;
P_0c081f6a: /* original 2fa6, guest PC 0x0c081f6a */
if(!s->budget--) { s->failed_pc=0x0c081f6au; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c081f6c;
P_0c081f6c: /* original 9519, guest PC 0x0c081f6c */
if(!s->budget--) { s->failed_pc=0x0c081f6cu; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c081fa2u,2);
goto P_0c081f6e;
P_0c081f6e: /* original e700, guest PC 0x0c081f6e */
if(!s->budget--) { s->failed_pc=0x0c081f6eu; return 0; }
r[7]=0x00000000u;
goto P_0c081f70;
P_0c081f70: /* original 4b0b, guest PC 0x0c081f70 */
if(!s->budget--) { s->failed_pc=0x0c081f70u; return 0; }
target=r[11];
r[16]=code_base|0x0c081f74u;
r[4]=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c081f74u) { target=s->pc; goto dispatch; }
goto P_0c081f74;
P_0c081f72: /* original 64c3, guest PC 0x0c081f72 */
if(!s->budget--) { s->failed_pc=0x0c081f72u; return 0; }
r[4]=r[12];
goto P_0c081f74;
P_0c081f74: /* original 7f04, guest PC 0x0c081f74 */
if(!s->budget--) { s->failed_pc=0x0c081f74u; return 0; }
r[15]+=0x00000004u;
goto P_0c081f76;
P_0c081f76: /* original 4f26, guest PC 0x0c081f76 */
if(!s->budget--) { s->failed_pc=0x0c081f76u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c081f78;
P_0c081f78: /* original 6af6, guest PC 0x0c081f78 */
if(!s->budget--) { s->failed_pc=0x0c081f78u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c081f7a;
P_0c081f7a: /* original 6bf6, guest PC 0x0c081f7a */
if(!s->budget--) { s->failed_pc=0x0c081f7au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c081f7c;
P_0c081f7c: /* original 6cf6, guest PC 0x0c081f7c */
if(!s->budget--) { s->failed_pc=0x0c081f7cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c081f7e;
P_0c081f7e: /* original 6df6, guest PC 0x0c081f7e */
if(!s->budget--) { s->failed_pc=0x0c081f7eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c081f80;
P_0c081f80: /* original 000b, guest PC 0x0c081f80 */
if(!s->budget--) { s->failed_pc=0x0c081f80u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c081f82: /* original 6ef6, guest PC 0x0c081f82 */
if(!s->budget--) { s->failed_pc=0x0c081f82u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c081f84u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c081f84u; return 0; } return 1;
P_0c081fac: /* original 2fe6, guest PC 0x0c081fac */
if(!s->budget--) { s->failed_pc=0x0c081facu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c081fae;
P_0c081fae: /* original 6163, guest PC 0x0c081fae */
if(!s->budget--) { s->failed_pc=0x0c081faeu; return 0; }
r[1]=r[6];
goto P_0c081fb0;
P_0c081fb0: /* original 2fd6, guest PC 0x0c081fb0 */
if(!s->budget--) { s->failed_pc=0x0c081fb0u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c081fb2;
P_0c081fb2: /* original 2fc6, guest PC 0x0c081fb2 */
if(!s->budget--) { s->failed_pc=0x0c081fb2u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c081fb4;
P_0c081fb4: /* original 2fb6, guest PC 0x0c081fb4 */
if(!s->budget--) { s->failed_pc=0x0c081fb4u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c081fb6;
P_0c081fb6: /* original 2fa6, guest PC 0x0c081fb6 */
if(!s->budget--) { s->failed_pc=0x0c081fb6u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c081fb8;
P_0c081fb8: /* original 2f96, guest PC 0x0c081fb8 */
if(!s->budget--) { s->failed_pc=0x0c081fb8u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c081fba;
P_0c081fba: /* original 2f86, guest PC 0x0c081fba */
if(!s->budget--) { s->failed_pc=0x0c081fbau; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c081fbc;
P_0c081fbc: /* original 6843, guest PC 0x0c081fbc */
if(!s->budget--) { s->failed_pc=0x0c081fbcu; return 0; }
r[8]=r[4];
goto P_0c081fbe;
P_0c081fbe: /* original 4f22, guest PC 0x0c081fbe */
if(!s->budget--) { s->failed_pc=0x0c081fbeu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c081fc0;
P_0c081fc0: /* original de49, guest PC 0x0c081fc0 */
if(!s->budget--) { s->failed_pc=0x0c081fc0u; return 0; }
r[14]=read(ram,0x0c0820e8u,4);
goto P_0c081fc2;
P_0c081fc2: /* original e40a, guest PC 0x0c081fc2 */
if(!s->budget--) { s->failed_pc=0x0c081fc2u; return 0; }
r[4]=0x0000000au;
goto P_0c081fc4;
P_0c081fc4: /* original d349, guest PC 0x0c081fc4 */
if(!s->budget--) { s->failed_pc=0x0c081fc4u; return 0; }
r[3]=read(ram,0x0c0820ecu,4);
goto P_0c081fc6;
P_0c081fc6: /* original 7ff8, guest PC 0x0c081fc6 */
if(!s->budget--) { s->failed_pc=0x0c081fc6u; return 0; }
r[15]+=0xfffffff8u;
goto P_0c081fc8;
P_0c081fc8: /* original 430b, guest PC 0x0c081fc8 */
if(!s->budget--) { s->failed_pc=0x0c081fc8u; return 0; }
target=r[3];
r[16]=code_base|0x0c081fccu;
r[0]=r[4];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c081fccu) { target=s->pc; goto dispatch; }
goto P_0c081fcc;
P_0c081fca: /* original 6043, guest PC 0x0c081fca */
if(!s->budget--) { s->failed_pc=0x0c081fcau; return 0; }
r[0]=r[4];
goto P_0c081fcc;
P_0c081fcc: /* original 1f01, guest PC 0x0c081fcc */
if(!s->budget--) { s->failed_pc=0x0c081fccu; return 0; }
write(ram,r[15]+4,r[0],4);
goto P_0c081fce;
P_0c081fce: /* original 6043, guest PC 0x0c081fce */
if(!s->budget--) { s->failed_pc=0x0c081fceu; return 0; }
r[0]=r[4];
goto P_0c081fd0;
P_0c081fd0: /* original d347, guest PC 0x0c081fd0 */
if(!s->budget--) { s->failed_pc=0x0c081fd0u; return 0; }
r[3]=read(ram,0x0c0820f0u,4);
goto P_0c081fd2;
P_0c081fd2: /* original 430b, guest PC 0x0c081fd2 */
if(!s->budget--) { s->failed_pc=0x0c081fd2u; return 0; }
target=r[3];
r[16]=code_base|0x0c081fd6u;
r[1]=r[6];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c081fd6u) { target=s->pc; goto dispatch; }
goto P_0c081fd6;
P_0c081fd4: /* original 6163, guest PC 0x0c081fd4 */
if(!s->budget--) { s->failed_pc=0x0c081fd4u; return 0; }
r[1]=r[6];
goto P_0c081fd6;
P_0c081fd6: /* original d245, guest PC 0x0c081fd6 */
if(!s->budget--) { s->failed_pc=0x0c081fd6u; return 0; }
r[2]=read(ram,0x0c0820ecu,4);
goto P_0c081fd8;
P_0c081fd8: /* original 6103, guest PC 0x0c081fd8 */
if(!s->budget--) { s->failed_pc=0x0c081fd8u; return 0; }
r[1]=r[0];
goto P_0c081fda;
P_0c081fda: /* original 6603, guest PC 0x0c081fda */
if(!s->budget--) { s->failed_pc=0x0c081fdau; return 0; }
r[6]=r[0];
goto P_0c081fdc;
P_0c081fdc: /* original 420b, guest PC 0x0c081fdc */
if(!s->budget--) { s->failed_pc=0x0c081fdcu; return 0; }
target=r[2];
r[16]=code_base|0x0c081fe0u;
r[0]=r[4];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c081fe0u) { target=s->pc; goto dispatch; }
goto P_0c081fe0;
P_0c081fde: /* original 6043, guest PC 0x0c081fde */
if(!s->budget--) { s->failed_pc=0x0c081fdeu; return 0; }
r[0]=r[4];
goto P_0c081fe0;
P_0c081fe0: /* original 2f02, guest PC 0x0c081fe0 */
if(!s->budget--) { s->failed_pc=0x0c081fe0u; return 0; }
write(ram,r[15],r[0],4);
goto P_0c081fe2;
P_0c081fe2: /* original 6043, guest PC 0x0c081fe2 */
if(!s->budget--) { s->failed_pc=0x0c081fe2u; return 0; }
r[0]=r[4];
goto P_0c081fe4;
P_0c081fe4: /* original d342, guest PC 0x0c081fe4 */
if(!s->budget--) { s->failed_pc=0x0c081fe4u; return 0; }
r[3]=read(ram,0x0c0820f0u,4);
goto P_0c081fe6;
P_0c081fe6: /* original 430b, guest PC 0x0c081fe6 */
if(!s->budget--) { s->failed_pc=0x0c081fe6u; return 0; }
target=r[3];
r[16]=code_base|0x0c081feau;
r[1]=r[6];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c081feau) { target=s->pc; goto dispatch; }
goto P_0c081fea;
P_0c081fe8: /* original 6163, guest PC 0x0c081fe8 */
if(!s->budget--) { s->failed_pc=0x0c081fe8u; return 0; }
r[1]=r[6];
goto P_0c081fea;
P_0c081fea: /* original d240, guest PC 0x0c081fea */
if(!s->budget--) { s->failed_pc=0x0c081feau; return 0; }
r[2]=read(ram,0x0c0820ecu,4);
goto P_0c081fec;
P_0c081fec: /* original 6103, guest PC 0x0c081fec */
if(!s->budget--) { s->failed_pc=0x0c081fecu; return 0; }
r[1]=r[0];
goto P_0c081fee;
P_0c081fee: /* original 6603, guest PC 0x0c081fee */
if(!s->budget--) { s->failed_pc=0x0c081feeu; return 0; }
r[6]=r[0];
goto P_0c081ff0;
P_0c081ff0: /* original 420b, guest PC 0x0c081ff0 */
if(!s->budget--) { s->failed_pc=0x0c081ff0u; return 0; }
target=r[2];
r[16]=code_base|0x0c081ff4u;
r[0]=r[4];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c081ff4u) { target=s->pc; goto dispatch; }
goto P_0c081ff4;
P_0c081ff2: /* original 6043, guest PC 0x0c081ff2 */
if(!s->budget--) { s->failed_pc=0x0c081ff2u; return 0; }
r[0]=r[4];
goto P_0c081ff4;
P_0c081ff4: /* original 9d71, guest PC 0x0c081ff4 */
if(!s->budget--) { s->failed_pc=0x0c081ff4u; return 0; }
r[13]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0820dau,2);
goto P_0c081ff6;
P_0c081ff6: /* original 6903, guest PC 0x0c081ff6 */
if(!s->budget--) { s->failed_pc=0x0c081ff6u; return 0; }
r[9]=r[0];
goto P_0c081ff8;
P_0c081ff8: /* original da3e, guest PC 0x0c081ff8 */
if(!s->budget--) { s->failed_pc=0x0c081ff8u; return 0; }
r[10]=read(ram,0x0c0820f4u,4);
goto P_0c081ffa;
P_0c081ffa: /* original 6c53, guest PC 0x0c081ffa */
if(!s->budget--) { s->failed_pc=0x0c081ffau; return 0; }
r[12]=r[5];
goto P_0c081ffc;
P_0c081ffc: /* original 2998, guest PC 0x0c081ffc */
if(!s->budget--) { s->failed_pc=0x0c081ffcu; return 0; }
r[17]=(r[17]&~1u)|(((r[9]&r[9])==0)!=0);
goto P_0c081ffe;
P_0c081ffe: /* original eb00, guest PC 0x0c081ffe */
if(!s->budget--) { s->failed_pc=0x0c081ffeu; return 0; }
r[11]=0x00000000u;
goto P_0c082000;
P_0c082000: /* original e307, guest PC 0x0c082000 */
if(!s->budget--) { s->failed_pc=0x0c082000u; return 0; }
r[3]=0x00000007u;
goto P_0c082002;
P_0c082002: /* original 8d0a, guest PC 0x0c082002 */
if(!s->budget--) { s->failed_pc=0x0c082002u; return 0; }
cond=r[17]&1u;
r[12]=(r[3]&0x80000000u)?((r[3]&31u)?(uint32_t)((int32_t)r[12]>>((-r[3])&31u)):((int32_t)r[12]<0?0xffffffffu:0)):r[12]<<(r[3]&31u);
if(cond) { goto P_0c08201a; }
goto P_0c082006;
P_0c082004: /* original 4c3c, guest PC 0x0c082004 */
if(!s->budget--) { s->failed_pc=0x0c082004u; return 0; }
r[12]=(r[3]&0x80000000u)?((r[3]&31u)?(uint32_t)((int32_t)r[12]>>((-r[3])&31u)):((int32_t)r[12]<0?0xffffffffu:0)):r[12]<<(r[3]&31u);
goto P_0c082006;
P_0c082006: /* original 6483, guest PC 0x0c082006 */
if(!s->budget--) { s->failed_pc=0x0c082006u; return 0; }
r[4]=r[8];
goto P_0c082008;
P_0c082008: /* original 4400, guest PC 0x0c082008 */
if(!s->budget--) { s->failed_pc=0x0c082008u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c08200a;
P_0c08200a: /* original 66e3, guest PC 0x0c08200a */
if(!s->budget--) { s->failed_pc=0x0c08200au; return 0; }
r[6]=r[14];
goto P_0c08200c;
P_0c08200c: /* original 6593, guest PC 0x0c08200c */
if(!s->budget--) { s->failed_pc=0x0c08200cu; return 0; }
r[5]=r[9];
goto P_0c08200e;
P_0c08200e: /* original e700, guest PC 0x0c08200e */
if(!s->budget--) { s->failed_pc=0x0c08200eu; return 0; }
r[7]=0x00000000u;
goto P_0c082010;
P_0c082010: /* original 2fb6, guest PC 0x0c082010 */
if(!s->budget--) { s->failed_pc=0x0c082010u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c082012;
P_0c082012: /* original 24cb, guest PC 0x0c082012 */
if(!s->budget--) { s->failed_pc=0x0c082012u; return 0; }
r[4]|=r[12];
goto P_0c082014;
P_0c082014: /* original 4a0b, guest PC 0x0c082014 */
if(!s->budget--) { s->failed_pc=0x0c082014u; return 0; }
target=r[10];
r[16]=code_base|0x0c082018u;
r[5]+=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c082018u) { target=s->pc; goto dispatch; }
goto P_0c082018;
P_0c082016: /* original 35dc, guest PC 0x0c082016 */
if(!s->budget--) { s->failed_pc=0x0c082016u; return 0; }
r[5]+=r[13];
goto P_0c082018;
P_0c082018: /* original 7f04, guest PC 0x0c082018 */
if(!s->budget--) { s->failed_pc=0x0c082018u; return 0; }
r[15]+=0x00000004u;
goto P_0c08201a;
P_0c08201a: /* original 6483, guest PC 0x0c08201a */
if(!s->budget--) { s->failed_pc=0x0c08201au; return 0; }
r[4]=r[8];
goto P_0c08201c;
P_0c08201c: /* original 2fb6, guest PC 0x0c08201c */
if(!s->budget--) { s->failed_pc=0x0c08201cu; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08201e;
P_0c08201e: /* original 7402, guest PC 0x0c08201e */
if(!s->budget--) { s->failed_pc=0x0c08201eu; return 0; }
r[4]+=0x00000002u;
goto P_0c082020;
P_0c082020: /* original 55f1, guest PC 0x0c082020 */
if(!s->budget--) { s->failed_pc=0x0c082020u; return 0; }
r[5]=read(ram,r[15]+4,4);
goto P_0c082022;
P_0c082022: /* original 4400, guest PC 0x0c082022 */
if(!s->budget--) { s->failed_pc=0x0c082022u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c082024;
P_0c082024: /* original 66e3, guest PC 0x0c082024 */
if(!s->budget--) { s->failed_pc=0x0c082024u; return 0; }
r[6]=r[14];
goto P_0c082026;
P_0c082026: /* original 24cb, guest PC 0x0c082026 */
if(!s->budget--) { s->failed_pc=0x0c082026u; return 0; }
r[4]|=r[12];
goto P_0c082028;
P_0c082028: /* original e700, guest PC 0x0c082028 */
if(!s->budget--) { s->failed_pc=0x0c082028u; return 0; }
r[7]=0x00000000u;
goto P_0c08202a;
P_0c08202a: /* original 4a0b, guest PC 0x0c08202a */
if(!s->budget--) { s->failed_pc=0x0c08202au; return 0; }
target=r[10];
r[16]=code_base|0x0c08202eu;
r[5]+=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08202eu) { target=s->pc; goto dispatch; }
goto P_0c08202e;
P_0c08202c: /* original 35dc, guest PC 0x0c08202c */
if(!s->budget--) { s->failed_pc=0x0c08202cu; return 0; }
r[5]+=r[13];
goto P_0c08202e;
P_0c08202e: /* original 6483, guest PC 0x0c08202e */
if(!s->budget--) { s->failed_pc=0x0c08202eu; return 0; }
r[4]=r[8];
goto P_0c082030;
P_0c082030: /* original 2fb6, guest PC 0x0c082030 */
if(!s->budget--) { s->failed_pc=0x0c082030u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c082032;
P_0c082032: /* original 7404, guest PC 0x0c082032 */
if(!s->budget--) { s->failed_pc=0x0c082032u; return 0; }
r[4]+=0x00000004u;
goto P_0c082034;
P_0c082034: /* original 55f3, guest PC 0x0c082034 */
if(!s->budget--) { s->failed_pc=0x0c082034u; return 0; }
r[5]=read(ram,r[15]+12,4);
goto P_0c082036;
P_0c082036: /* original 4400, guest PC 0x0c082036 */
if(!s->budget--) { s->failed_pc=0x0c082036u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c082038;
P_0c082038: /* original 66e3, guest PC 0x0c082038 */
if(!s->budget--) { s->failed_pc=0x0c082038u; return 0; }
r[6]=r[14];
goto P_0c08203a;
P_0c08203a: /* original 24cb, guest PC 0x0c08203a */
if(!s->budget--) { s->failed_pc=0x0c08203au; return 0; }
r[4]|=r[12];
goto P_0c08203c;
P_0c08203c: /* original e700, guest PC 0x0c08203c */
if(!s->budget--) { s->failed_pc=0x0c08203cu; return 0; }
r[7]=0x00000000u;
goto P_0c08203e;
P_0c08203e: /* original 4a0b, guest PC 0x0c08203e */
if(!s->budget--) { s->failed_pc=0x0c08203eu; return 0; }
target=r[10];
r[16]=code_base|0x0c082042u;
r[5]+=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c082042u) { target=s->pc; goto dispatch; }
goto P_0c082042;
P_0c082040: /* original 35dc, guest PC 0x0c082040 */
if(!s->budget--) { s->failed_pc=0x0c082040u; return 0; }
r[5]+=r[13];
goto P_0c082042;
P_0c082042: /* original 7f10, guest PC 0x0c082042 */
if(!s->budget--) { s->failed_pc=0x0c082042u; return 0; }
r[15]+=0x00000010u;
goto P_0c082044;
P_0c082044: /* original 4f26, guest PC 0x0c082044 */
if(!s->budget--) { s->failed_pc=0x0c082044u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c082046;
P_0c082046: /* original 68f6, guest PC 0x0c082046 */
if(!s->budget--) { s->failed_pc=0x0c082046u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c082048;
P_0c082048: /* original 69f6, guest PC 0x0c082048 */
if(!s->budget--) { s->failed_pc=0x0c082048u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c08204a;
P_0c08204a: /* original 6af6, guest PC 0x0c08204a */
if(!s->budget--) { s->failed_pc=0x0c08204au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c08204c;
P_0c08204c: /* original 6bf6, guest PC 0x0c08204c */
if(!s->budget--) { s->failed_pc=0x0c08204cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c08204e;
P_0c08204e: /* original 6cf6, guest PC 0x0c08204e */
if(!s->budget--) { s->failed_pc=0x0c08204eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c082050;
P_0c082050: /* original 6df6, guest PC 0x0c082050 */
if(!s->budget--) { s->failed_pc=0x0c082050u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c082052;
P_0c082052: /* original 000b, guest PC 0x0c082052 */
if(!s->budget--) { s->failed_pc=0x0c082052u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c082054: /* original 6ef6, guest PC 0x0c082054 */
if(!s->budget--) { s->failed_pc=0x0c082054u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c082056u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c082056u; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
