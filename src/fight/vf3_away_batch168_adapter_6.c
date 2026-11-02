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
int vf3_away_batch168_adapter_6(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c0c8e6cu: goto P_0c0c8e6c;
case 0x0c0c8e6eu: goto P_0c0c8e6e;
case 0x0c0c8e70u: goto P_0c0c8e70;
case 0x0c0c8e72u: goto P_0c0c8e72;
case 0x0c0c8e74u: goto P_0c0c8e74;
case 0x0c0c8e76u: goto P_0c0c8e76;
case 0x0c0c8e78u: goto P_0c0c8e78;
case 0x0c0c8e7au: goto P_0c0c8e7a;
case 0x0c0c8e7cu: goto P_0c0c8e7c;
case 0x0c0c8e7eu: goto P_0c0c8e7e;
case 0x0c0c8e80u: goto P_0c0c8e80;
case 0x0c0c8e82u: goto P_0c0c8e82;
case 0x0c0c8e84u: goto P_0c0c8e84;
case 0x0c0c8e86u: goto P_0c0c8e86;
case 0x0c0c8e88u: goto P_0c0c8e88;
case 0x0c0c8e8au: goto P_0c0c8e8a;
case 0x0c0c8e8cu: goto P_0c0c8e8c;
case 0x0c0c8e8eu: goto P_0c0c8e8e;
case 0x0c0c8e90u: goto P_0c0c8e90;
case 0x0c0c8e92u: goto P_0c0c8e92;
case 0x0c0c8e94u: goto P_0c0c8e94;
case 0x0c0c8e96u: goto P_0c0c8e96;
case 0x0c0c8e98u: goto P_0c0c8e98;
case 0x0c0c8e9au: goto P_0c0c8e9a;
case 0x0c0c8e9cu: goto P_0c0c8e9c;
case 0x0c0c8e9eu: goto P_0c0c8e9e;
case 0x0c0c8ea0u: goto P_0c0c8ea0;
case 0x0c0c8ea2u: goto P_0c0c8ea2;
case 0x0c0c8ea4u: goto P_0c0c8ea4;
case 0x0c0c8ea6u: goto P_0c0c8ea6;
case 0x0c0c8ea8u: goto P_0c0c8ea8;
case 0x0c0c8eaau: goto P_0c0c8eaa;
case 0x0c0c8eacu: goto P_0c0c8eac;
case 0x0c0c8eaeu: goto P_0c0c8eae;
case 0x0c0c8eb0u: goto P_0c0c8eb0;
case 0x0c0c8eb2u: goto P_0c0c8eb2;
case 0x0c0c8eb4u: goto P_0c0c8eb4;
case 0x0c0c8eb6u: goto P_0c0c8eb6;
case 0x0c0c8eb8u: goto P_0c0c8eb8;
case 0x0c0c8ebau: goto P_0c0c8eba;
case 0x0c0c8ebcu: goto P_0c0c8ebc;
case 0x0c0c8ebeu: goto P_0c0c8ebe;
case 0x0c0c8ec0u: goto P_0c0c8ec0;
case 0x0c0c8ec2u: goto P_0c0c8ec2;
case 0x0c0c8ec4u: goto P_0c0c8ec4;
case 0x0c0c8ec6u: goto P_0c0c8ec6;
case 0x0c0c8ec8u: goto P_0c0c8ec8;
case 0x0c0c8ecau: goto P_0c0c8eca;
case 0x0c0c8eccu: goto P_0c0c8ecc;
case 0x0c0c8eceu: goto P_0c0c8ece;
case 0x0c0c8ed0u: goto P_0c0c8ed0;
case 0x0c0c8ed2u: goto P_0c0c8ed2;
case 0x0c0c8ed4u: goto P_0c0c8ed4;
case 0x0c0c8ed6u: goto P_0c0c8ed6;
case 0x0c0c8ed8u: goto P_0c0c8ed8;
case 0x0c0c8edau: goto P_0c0c8eda;
case 0x0c0c8edcu: goto P_0c0c8edc;
case 0x0c0c8edeu: goto P_0c0c8ede;
case 0x0c0c8ee0u: goto P_0c0c8ee0;
case 0x0c0c8ee2u: goto P_0c0c8ee2;
case 0x0c0c8ee4u: goto P_0c0c8ee4;
case 0x0c0c8ee6u: goto P_0c0c8ee6;
case 0x0c0c8ee8u: goto P_0c0c8ee8;
case 0x0c0c8eeau: goto P_0c0c8eea;
case 0x0c0c8eecu: goto P_0c0c8eec;
case 0x0c0c8eeeu: goto P_0c0c8eee;
case 0x0c0c8ef0u: goto P_0c0c8ef0;
case 0x0c0c8ef2u: goto P_0c0c8ef2;
case 0x0c0c8ef4u: goto P_0c0c8ef4;
case 0x0c0c8ef6u: goto P_0c0c8ef6;
case 0x0c0c8ef8u: goto P_0c0c8ef8;
case 0x0c0c8efau: goto P_0c0c8efa;
case 0x0c0c8efcu: goto P_0c0c8efc;
case 0x0c0c8efeu: goto P_0c0c8efe;
case 0x0c0c8f00u: goto P_0c0c8f00;
case 0x0c0c8f02u: goto P_0c0c8f02;
case 0x0c0c8f04u: goto P_0c0c8f04;
case 0x0c0c8f06u: goto P_0c0c8f06;
case 0x0c0c8f08u: goto P_0c0c8f08;
case 0x0c0c8f0au: goto P_0c0c8f0a;
case 0x0c0c8f0cu: goto P_0c0c8f0c;
case 0x0c0c8f0eu: goto P_0c0c8f0e;
case 0x0c0c8f10u: goto P_0c0c8f10;
case 0x0c0c8f12u: goto P_0c0c8f12;
case 0x0c0c8f14u: goto P_0c0c8f14;
case 0x0c0c8f16u: goto P_0c0c8f16;
case 0x0c0c8f18u: goto P_0c0c8f18;
case 0x0c0c8f1au: goto P_0c0c8f1a;
case 0x0c0c8f1cu: goto P_0c0c8f1c;
case 0x0c0c8f1eu: goto P_0c0c8f1e;
case 0x0c0c8f20u: goto P_0c0c8f20;
case 0x0c0c8f22u: goto P_0c0c8f22;
case 0x0c0c8f24u: goto P_0c0c8f24;
case 0x0c0c8f26u: goto P_0c0c8f26;
case 0x0c0c8f28u: goto P_0c0c8f28;
case 0x0c0c8f2au: goto P_0c0c8f2a;
case 0x0c0c8f2cu: goto P_0c0c8f2c;
case 0x0c0c8f2eu: goto P_0c0c8f2e;
case 0x0c0c8f30u: goto P_0c0c8f30;
case 0x0c0c8f32u: goto P_0c0c8f32;
case 0x0c0c8f34u: goto P_0c0c8f34;
case 0x0c0c927cu: goto P_0c0c927c;
case 0x0c0c927eu: goto P_0c0c927e;
case 0x0c0c9280u: goto P_0c0c9280;
case 0x0c0c9282u: goto P_0c0c9282;
case 0x0c0c9284u: goto P_0c0c9284;
case 0x0c0c9286u: goto P_0c0c9286;
case 0x0c0c9288u: goto P_0c0c9288;
case 0x0c0c928au: goto P_0c0c928a;
case 0x0c0c928cu: goto P_0c0c928c;
case 0x0c0c928eu: goto P_0c0c928e;
case 0x0c0c9290u: goto P_0c0c9290;
case 0x0c0c9292u: goto P_0c0c9292;
case 0x0c0c9294u: goto P_0c0c9294;
case 0x0c0c9296u: goto P_0c0c9296;
case 0x0c0c9298u: goto P_0c0c9298;
case 0x0c0c929au: goto P_0c0c929a;
case 0x0c0c929cu: goto P_0c0c929c;
case 0x0c0c929eu: goto P_0c0c929e;
case 0x0c0c92a0u: goto P_0c0c92a0;
case 0x0c0c92a2u: goto P_0c0c92a2;
case 0x0c0c92a4u: goto P_0c0c92a4;
case 0x0c0c92a6u: goto P_0c0c92a6;
case 0x0c0c92a8u: goto P_0c0c92a8;
case 0x0c0c92aau: goto P_0c0c92aa;
case 0x0c0c92acu: goto P_0c0c92ac;
case 0x0c0c92aeu: goto P_0c0c92ae;
case 0x0c0c92b0u: goto P_0c0c92b0;
default: return vf3_matrix_family(target,s,ram);
}
P_0c0c8e6c: /* original 2fe6, guest PC 0x0c0c8e6c */
if(!s->budget--) { s->failed_pc=0x0c0c8e6cu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c8e6e;
P_0c0c8e6e: /* original e043, guest PC 0x0c0c8e6e */
if(!s->budget--) { s->failed_pc=0x0c0c8e6eu; return 0; }
r[0]=0x00000043u;
goto P_0c0c8e70;
P_0c0c8e70: /* original 2fd6, guest PC 0x0c0c8e70 */
if(!s->budget--) { s->failed_pc=0x0c0c8e70u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c8e72;
P_0c0c8e72: /* original e307, guest PC 0x0c0c8e72 */
if(!s->budget--) { s->failed_pc=0x0c0c8e72u; return 0; }
r[3]=0x00000007u;
goto P_0c0c8e74;
P_0c0c8e74: /* original 2fc6, guest PC 0x0c0c8e74 */
if(!s->budget--) { s->failed_pc=0x0c0c8e74u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c8e76;
P_0c0c8e76: /* original e228, guest PC 0x0c0c8e76 */
if(!s->budget--) { s->failed_pc=0x0c0c8e76u; return 0; }
r[2]=0x00000028u;
goto P_0c0c8e78;
P_0c0c8e78: /* original 2fb6, guest PC 0x0c0c8e78 */
if(!s->budget--) { s->failed_pc=0x0c0c8e78u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c8e7a;
P_0c0c8e7a: /* original dc33, guest PC 0x0c0c8e7a */
if(!s->budget--) { s->failed_pc=0x0c0c8e7au; return 0; }
r[12]=read(ram,0x0c0c8f48u,4);
goto P_0c0c8e7c;
P_0c0c8e7c: /* original 4f22, guest PC 0x0c0c8e7c */
if(!s->budget--) { s->failed_pc=0x0c0c8e7cu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0c8e7e;
P_0c0c8e7e: /* original 0ecc, guest PC 0x0c0c8e7e */
if(!s->budget--) { s->failed_pc=0x0c0c8e7eu; return 0; }
r[14]=(uint32_t)(int32_t)(int8_t)read(ram,r[12]+r[0],1);
goto P_0c0c8e80;
P_0c0c8e80: /* original d032, guest PC 0x0c0c8e80 */
if(!s->budget--) { s->failed_pc=0x0c0c8e80u; return 0; }
r[0]=read(ram,0x0c0c8f4cu,4);
goto P_0c0c8e82;
P_0c0c8e82: /* original 7ffc, guest PC 0x0c0c8e82 */
if(!s->budget--) { s->failed_pc=0x0c0c8e82u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c0c8e84;
P_0c0c8e84: /* original db2f, guest PC 0x0c0c8e84 */
if(!s->budget--) { s->failed_pc=0x0c0c8e84u; return 0; }
r[11]=read(ram,0x0c0c8f44u,4);
goto P_0c0c8e86;
P_0c0c8e86: /* original 04ec, guest PC 0x0c0c8e86 */
if(!s->budget--) { s->failed_pc=0x0c0c8e86u; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0c8e88;
P_0c0c8e88: /* original 644c, guest PC 0x0c0c8e88 */
if(!s->budget--) { s->failed_pc=0x0c0c8e88u; return 0; }
r[4]=r[4]&255u;
goto P_0c0c8e8a;
P_0c0c8e8a: /* original 443c, guest PC 0x0c0c8e8a */
if(!s->budget--) { s->failed_pc=0x0c0c8e8au; return 0; }
r[4]=(r[3]&0x80000000u)?((r[3]&31u)?(uint32_t)((int32_t)r[4]>>((-r[3])&31u)):((int32_t)r[4]<0?0xffffffffu:0)):r[4]<<(r[3]&31u);
goto P_0c0c8e8c;
P_0c0c8e8c: /* original 242b, guest PC 0x0c0c8e8c */
if(!s->budget--) { s->failed_pc=0x0c0c8e8cu; return 0; }
r[4]|=r[2];
goto P_0c0c8e8e;
P_0c0c8e8e: /* original 2f42, guest PC 0x0c0c8e8e */
if(!s->budget--) { s->failed_pc=0x0c0c8e8eu; return 0; }
write(ram,r[15],r[4],4);
goto P_0c0c8e90;
P_0c0c8e90: /* original d12f, guest PC 0x0c0c8e90 */
if(!s->budget--) { s->failed_pc=0x0c0c8e90u; return 0; }
r[1]=read(ram,0x0c0c8f50u,4);
goto P_0c0c8e92;
P_0c0c8e92: /* original 2f16, guest PC 0x0c0c8e92 */
if(!s->budget--) { s->failed_pc=0x0c0c8e92u; return 0; }
tmp=r[1]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c8e94;
P_0c0c8e94: /* original d32f, guest PC 0x0c0c8e94 */
if(!s->budget--) { s->failed_pc=0x0c0c8e94u; return 0; }
r[3]=read(ram,0x0c0c8f54u,4);
goto P_0c0c8e96;
P_0c0c8e96: /* original 430b, guest PC 0x0c0c8e96 */
if(!s->budget--) { s->failed_pc=0x0c0c8e96u; return 0; }
target=r[3];
r[16]=code_base|0x0c0c8e9au;
r[4]=read(ram,r[15]+4,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c8e9au) { target=s->pc; goto dispatch; }
goto P_0c0c8e9a;
P_0c0c8e98: /* original 54f1, guest PC 0x0c0c8e98 */
if(!s->budget--) { s->failed_pc=0x0c0c8e98u; return 0; }
r[4]=read(ram,r[15]+4,4);
goto P_0c0c8e9a;
P_0c0c8e9a: /* original 904e, guest PC 0x0c0c8e9a */
if(!s->budget--) { s->failed_pc=0x0c0c8e9au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c8f3au,2);
goto P_0c0c8e9c;
P_0c0c8e9c: /* original 7f04, guest PC 0x0c0c8e9c */
if(!s->budget--) { s->failed_pc=0x0c0c8e9cu; return 0; }
r[15]+=0x00000004u;
goto P_0c0c8e9e;
P_0c0c8e9e: /* original 934d, guest PC 0x0c0c8e9e */
if(!s->budget--) { s->failed_pc=0x0c0c8e9eu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c8f3cu,2);
goto P_0c0c8ea0;
P_0c0c8ea0: /* original 0dbe, guest PC 0x0c0c8ea0 */
if(!s->budget--) { s->failed_pc=0x0c0c8ea0u; return 0; }
r[13]=read(ram,r[11]+r[0],4);
goto P_0c0c8ea2;
P_0c0c8ea2: /* original 23d8, guest PC 0x0c0c8ea2 */
if(!s->budget--) { s->failed_pc=0x0c0c8ea2u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[13])==0)!=0);
goto P_0c0c8ea4;
P_0c0c8ea4: /* original 8f14, guest PC 0x0c0c8ea4 */
if(!s->budget--) { s->failed_pc=0x0c0c8ea4u; return 0; }
cond=r[17]&1u;
r[4]=0x0000000fu;
if(!cond) { goto P_0c0c8ed0; }
goto P_0c0c8ea8;
P_0c0c8ea6: /* original e40f, guest PC 0x0c0c8ea6 */
if(!s->budget--) { s->failed_pc=0x0c0c8ea6u; return 0; }
r[4]=0x0000000fu;
goto P_0c0c8ea8;
P_0c0c8ea8: /* original 9249, guest PC 0x0c0c8ea8 */
if(!s->budget--) { s->failed_pc=0x0c0c8ea8u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c8f3eu,2);
goto P_0c0c8eaa;
P_0c0c8eaa: /* original 22d8, guest PC 0x0c0c8eaa */
if(!s->budget--) { s->failed_pc=0x0c0c8eaau; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[13])==0)!=0);
goto P_0c0c8eac;
P_0c0c8eac: /* original 8b15, guest PC 0x0c0c8eac */
if(!s->budget--) { s->failed_pc=0x0c0c8eacu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c8eda; }
goto P_0c0c8eae;
P_0c0c8eae: /* original e308, guest PC 0x0c0c8eae */
if(!s->budget--) { s->failed_pc=0x0c0c8eaeu; return 0; }
r[3]=0x00000008u;
goto P_0c0c8eb0;
P_0c0c8eb0: /* original 23d8, guest PC 0x0c0c8eb0 */
if(!s->budget--) { s->failed_pc=0x0c0c8eb0u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[13])==0)!=0);
goto P_0c0c8eb2;
P_0c0c8eb2: /* original 8b12, guest PC 0x0c0c8eb2 */
if(!s->budget--) { s->failed_pc=0x0c0c8eb2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c8eda; }
goto P_0c0c8eb4;
P_0c0c8eb4: /* original d228, guest PC 0x0c0c8eb4 */
if(!s->budget--) { s->failed_pc=0x0c0c8eb4u; return 0; }
r[2]=read(ram,0x0c0c8f58u,4);
goto P_0c0c8eb6;
P_0c0c8eb6: /* original 22d8, guest PC 0x0c0c8eb6 */
if(!s->budget--) { s->failed_pc=0x0c0c8eb6u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[13])==0)!=0);
goto P_0c0c8eb8;
P_0c0c8eb8: /* original 8b0f, guest PC 0x0c0c8eb8 */
if(!s->budget--) { s->failed_pc=0x0c0c8eb8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c8eda; }
goto P_0c0c8eba;
P_0c0c8eba: /* original 9341, guest PC 0x0c0c8eba */
if(!s->budget--) { s->failed_pc=0x0c0c8ebau; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c8f40u,2);
goto P_0c0c8ebc;
P_0c0c8ebc: /* original 23d8, guest PC 0x0c0c8ebc */
if(!s->budget--) { s->failed_pc=0x0c0c8ebcu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[13])==0)!=0);
goto P_0c0c8ebe;
P_0c0c8ebe: /* original 8b11, guest PC 0x0c0c8ebe */
if(!s->budget--) { s->failed_pc=0x0c0c8ebeu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c8ee4; }
goto P_0c0c8ec0;
P_0c0c8ec0: /* original e204, guest PC 0x0c0c8ec0 */
if(!s->budget--) { s->failed_pc=0x0c0c8ec0u; return 0; }
r[2]=0x00000004u;
goto P_0c0c8ec2;
P_0c0c8ec2: /* original 22d8, guest PC 0x0c0c8ec2 */
if(!s->budget--) { s->failed_pc=0x0c0c8ec2u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[13])==0)!=0);
goto P_0c0c8ec4;
P_0c0c8ec4: /* original 8b0e, guest PC 0x0c0c8ec4 */
if(!s->budget--) { s->failed_pc=0x0c0c8ec4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c8ee4; }
goto P_0c0c8ec6;
P_0c0c8ec6: /* original d325, guest PC 0x0c0c8ec6 */
if(!s->budget--) { s->failed_pc=0x0c0c8ec6u; return 0; }
r[3]=read(ram,0x0c0c8f5cu,4);
goto P_0c0c8ec8;
P_0c0c8ec8: /* original 23d8, guest PC 0x0c0c8ec8 */
if(!s->budget--) { s->failed_pc=0x0c0c8ec8u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[13])==0)!=0);
goto P_0c0c8eca;
P_0c0c8eca: /* original 8b0b, guest PC 0x0c0c8eca */
if(!s->budget--) { s->failed_pc=0x0c0c8ecau; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c8ee4; }
goto P_0c0c8ecc;
P_0c0c8ecc: /* original a014, guest PC 0x0c0c8ecc */
if(!s->budget--) { s->failed_pc=0x0c0c8eccu; return 0; }
goto P_0c0c8ef8;
P_0c0c8ece: /* original 0009, guest PC 0x0c0c8ece */
if(!s->budget--) { s->failed_pc=0x0c0c8eceu; return 0; }
goto P_0c0c8ed0;
P_0c0c8ed0: /* original 7eff, guest PC 0x0c0c8ed0 */
if(!s->budget--) { s->failed_pc=0x0c0c8ed0u; return 0; }
r[14]+=0xffffffffu;
goto P_0c0c8ed2;
P_0c0c8ed2: /* original 4e11, guest PC 0x0c0c8ed2 */
if(!s->budget--) { s->failed_pc=0x0c0c8ed2u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[14]>=0)!=0);
goto P_0c0c8ed4;
P_0c0c8ed4: /* original 8910, guest PC 0x0c0c8ed4 */
if(!s->budget--) { s->failed_pc=0x0c0c8ed4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c8ef8; }
goto P_0c0c8ed6;
P_0c0c8ed6: /* original a00f, guest PC 0x0c0c8ed6 */
if(!s->budget--) { s->failed_pc=0x0c0c8ed6u; return 0; }
r[14]=r[4];
goto P_0c0c8ef8;
P_0c0c8ed8: /* original 6e43, guest PC 0x0c0c8ed8 */
if(!s->budget--) { s->failed_pc=0x0c0c8ed8u; return 0; }
r[14]=r[4];
goto P_0c0c8eda;
P_0c0c8eda: /* original 7e01, guest PC 0x0c0c8eda */
if(!s->budget--) { s->failed_pc=0x0c0c8edau; return 0; }
r[14]+=0x00000001u;
goto P_0c0c8edc;
P_0c0c8edc: /* original 3e47, guest PC 0x0c0c8edc */
if(!s->budget--) { s->failed_pc=0x0c0c8edcu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[14]>(int32_t)r[4])!=0);
goto P_0c0c8ede;
P_0c0c8ede: /* original 8b0b, guest PC 0x0c0c8ede */
if(!s->budget--) { s->failed_pc=0x0c0c8edeu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c8ef8; }
goto P_0c0c8ee0;
P_0c0c8ee0: /* original a00a, guest PC 0x0c0c8ee0 */
if(!s->budget--) { s->failed_pc=0x0c0c8ee0u; return 0; }
r[14]=0x00000000u;
goto P_0c0c8ef8;
P_0c0c8ee2: /* original ee00, guest PC 0x0c0c8ee2 */
if(!s->budget--) { s->failed_pc=0x0c0c8ee2u; return 0; }
r[14]=0x00000000u;
goto P_0c0c8ee4;
P_0c0c8ee4: /* original 60e3, guest PC 0x0c0c8ee4 */
if(!s->budget--) { s->failed_pc=0x0c0c8ee4u; return 0; }
r[0]=r[14];
goto P_0c0c8ee6;
P_0c0c8ee6: /* original 880f, guest PC 0x0c0c8ee6 */
if(!s->budget--) { s->failed_pc=0x0c0c8ee6u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000fu)!=0);
goto P_0c0c8ee8;
P_0c0c8ee8: /* original 8b02, guest PC 0x0c0c8ee8 */
if(!s->budget--) { s->failed_pc=0x0c0c8ee8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c8ef0; }
goto P_0c0c8eea;
P_0c0c8eea: /* original d21d, guest PC 0x0c0c8eea */
if(!s->budget--) { s->failed_pc=0x0c0c8eeau; return 0; }
r[2]=read(ram,0x0c0c8f60u,4);
goto P_0c0c8eec;
P_0c0c8eec: /* original 420b, guest PC 0x0c0c8eec */
if(!s->budget--) { s->failed_pc=0x0c0c8eecu; return 0; }
target=r[2];
r[16]=code_base|0x0c0c8ef0u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c8ef0u) { target=s->pc; goto dispatch; }
goto P_0c0c8ef0;
P_0c0c8eee: /* original 0009, guest PC 0x0c0c8eee */
if(!s->budget--) { s->failed_pc=0x0c0c8eeeu; return 0; }
goto P_0c0c8ef0;
P_0c0c8ef0: /* original 60e3, guest PC 0x0c0c8ef0 */
if(!s->budget--) { s->failed_pc=0x0c0c8ef0u; return 0; }
r[0]=r[14];
goto P_0c0c8ef2;
P_0c0c8ef2: /* original 7001, guest PC 0x0c0c8ef2 */
if(!s->budget--) { s->failed_pc=0x0c0c8ef2u; return 0; }
r[0]+=0x00000001u;
goto P_0c0c8ef4;
P_0c0c8ef4: /* original 4000, guest PC 0x0c0c8ef4 */
if(!s->budget--) { s->failed_pc=0x0c0c8ef4u; return 0; }
r[17]=(r[17]&~1u)|((r[0]>>31)!=0);
r[0]<<=1;
goto P_0c0c8ef6;
P_0c0c8ef6: /* original 80bb, guest PC 0x0c0c8ef6 */
if(!s->budget--) { s->failed_pc=0x0c0c8ef6u; return 0; }
write(ram,r[11]+11,r[0],1);
goto P_0c0c8ef8;
P_0c0c8ef8: /* original 60e3, guest PC 0x0c0c8ef8 */
if(!s->budget--) { s->failed_pc=0x0c0c8ef8u; return 0; }
r[0]=r[14];
goto P_0c0c8efa;
P_0c0c8efa: /* original 880e, guest PC 0x0c0c8efa */
if(!s->budget--) { s->failed_pc=0x0c0c8efau; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000eu)!=0);
goto P_0c0c8efc;
P_0c0c8efc: /* original 8b05, guest PC 0x0c0c8efc */
if(!s->budget--) { s->failed_pc=0x0c0c8efcu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c8f0a; }
goto P_0c0c8efe;
P_0c0c8efe: /* original d319, guest PC 0x0c0c8efe */
if(!s->budget--) { s->failed_pc=0x0c0c8efeu; return 0; }
r[3]=read(ram,0x0c0c8f64u,4);
goto P_0c0c8f00;
P_0c0c8f00: /* original 2d38, guest PC 0x0c0c8f00 */
if(!s->budget--) { s->failed_pc=0x0c0c8f00u; return 0; }
r[17]=(r[17]&~1u)|(((r[13]&r[3])==0)!=0);
goto P_0c0c8f02;
P_0c0c8f02: /* original 8901, guest PC 0x0c0c8f02 */
if(!s->budget--) { s->failed_pc=0x0c0c8f02u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c8f08; }
goto P_0c0c8f04;
P_0c0c8f04: /* original a001, guest PC 0x0c0c8f04 */
if(!s->budget--) { s->failed_pc=0x0c0c8f04u; return 0; }
r[14]+=0x00000001u;
goto P_0c0c8f0a;
P_0c0c8f06: /* original 7e01, guest PC 0x0c0c8f06 */
if(!s->budget--) { s->failed_pc=0x0c0c8f06u; return 0; }
r[14]+=0x00000001u;
goto P_0c0c8f08;
P_0c0c8f08: /* original 7eff, guest PC 0x0c0c8f08 */
if(!s->budget--) { s->failed_pc=0x0c0c8f08u; return 0; }
r[14]+=0xffffffffu;
goto P_0c0c8f0a;
P_0c0c8f0a: /* original e043, guest PC 0x0c0c8f0a */
if(!s->budget--) { s->failed_pc=0x0c0c8f0au; return 0; }
r[0]=0x00000043u;
goto P_0c0c8f0c;
P_0c0c8f0c: /* original 0ce4, guest PC 0x0c0c8f0c */
if(!s->budget--) { s->failed_pc=0x0c0c8f0cu; return 0; }
write(ram,r[12]+r[0],r[14],1);
goto P_0c0c8f0e;
P_0c0c8f0e: /* original e307, guest PC 0x0c0c8f0e */
if(!s->budget--) { s->failed_pc=0x0c0c8f0eu; return 0; }
r[3]=0x00000007u;
goto P_0c0c8f10;
P_0c0c8f10: /* original d00e, guest PC 0x0c0c8f10 */
if(!s->budget--) { s->failed_pc=0x0c0c8f10u; return 0; }
r[0]=read(ram,0x0c0c8f4cu,4);
goto P_0c0c8f12;
P_0c0c8f12: /* original e228, guest PC 0x0c0c8f12 */
if(!s->budget--) { s->failed_pc=0x0c0c8f12u; return 0; }
r[2]=0x00000028u;
goto P_0c0c8f14;
P_0c0c8f14: /* original 04ec, guest PC 0x0c0c8f14 */
if(!s->budget--) { s->failed_pc=0x0c0c8f14u; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0c8f16;
P_0c0c8f16: /* original 644c, guest PC 0x0c0c8f16 */
if(!s->budget--) { s->failed_pc=0x0c0c8f16u; return 0; }
r[4]=r[4]&255u;
goto P_0c0c8f18;
P_0c0c8f18: /* original 443c, guest PC 0x0c0c8f18 */
if(!s->budget--) { s->failed_pc=0x0c0c8f18u; return 0; }
r[4]=(r[3]&0x80000000u)?((r[3]&31u)?(uint32_t)((int32_t)r[4]>>((-r[3])&31u)):((int32_t)r[4]<0?0xffffffffu:0)):r[4]<<(r[3]&31u);
goto P_0c0c8f1a;
P_0c0c8f1a: /* original 242b, guest PC 0x0c0c8f1a */
if(!s->budget--) { s->failed_pc=0x0c0c8f1au; return 0; }
r[4]|=r[2];
goto P_0c0c8f1c;
P_0c0c8f1c: /* original 2f42, guest PC 0x0c0c8f1c */
if(!s->budget--) { s->failed_pc=0x0c0c8f1cu; return 0; }
write(ram,r[15],r[4],4);
goto P_0c0c8f1e;
P_0c0c8f1e: /* original d512, guest PC 0x0c0c8f1e */
if(!s->budget--) { s->failed_pc=0x0c0c8f1eu; return 0; }
r[5]=read(ram,0x0c0c8f68u,4);
goto P_0c0c8f20;
P_0c0c8f20: /* original d112, guest PC 0x0c0c8f20 */
if(!s->budget--) { s->failed_pc=0x0c0c8f20u; return 0; }
r[1]=read(ram,0x0c0c8f6cu,4);
goto P_0c0c8f22;
P_0c0c8f22: /* original 410b, guest PC 0x0c0c8f22 */
if(!s->budget--) { s->failed_pc=0x0c0c8f22u; return 0; }
target=r[1];
r[16]=code_base|0x0c0c8f26u;
r[6]=0x00000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c8f26u) { target=s->pc; goto dispatch; }
goto P_0c0c8f26;
P_0c0c8f24: /* original e600, guest PC 0x0c0c8f24 */
if(!s->budget--) { s->failed_pc=0x0c0c8f24u; return 0; }
r[6]=0x00000000u;
goto P_0c0c8f26;
P_0c0c8f26: /* original 7f04, guest PC 0x0c0c8f26 */
if(!s->budget--) { s->failed_pc=0x0c0c8f26u; return 0; }
r[15]+=0x00000004u;
goto P_0c0c8f28;
P_0c0c8f28: /* original d311, guest PC 0x0c0c8f28 */
if(!s->budget--) { s->failed_pc=0x0c0c8f28u; return 0; }
r[3]=read(ram,0x0c0c8f70u,4);
goto P_0c0c8f2a;
P_0c0c8f2a: /* original 4f26, guest PC 0x0c0c8f2a */
if(!s->budget--) { s->failed_pc=0x0c0c8f2au; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0c8f2c;
P_0c0c8f2c: /* original 6bf6, guest PC 0x0c0c8f2c */
if(!s->budget--) { s->failed_pc=0x0c0c8f2cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0c8f2e;
P_0c0c8f2e: /* original 6cf6, guest PC 0x0c0c8f2e */
if(!s->budget--) { s->failed_pc=0x0c0c8f2eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0c8f30;
P_0c0c8f30: /* original 6df6, guest PC 0x0c0c8f30 */
if(!s->budget--) { s->failed_pc=0x0c0c8f30u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0c8f32;
P_0c0c8f32: /* original 432b, guest PC 0x0c0c8f32 */
if(!s->budget--) { s->failed_pc=0x0c0c8f32u; return 0; }
target=r[3];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
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
P_0c0c8f34: /* original 6ef6, guest PC 0x0c0c8f34 */
if(!s->budget--) { s->failed_pc=0x0c0c8f34u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0c8f36u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0c8f36u; return 0; } return 1;
P_0c0c927c: /* original 2fe6, guest PC 0x0c0c927c */
if(!s->budget--) { s->failed_pc=0x0c0c927cu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c927e;
P_0c0c927e: /* original 9033, guest PC 0x0c0c927e */
if(!s->budget--) { s->failed_pc=0x0c0c927eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c92e8u,2);
goto P_0c0c9280;
P_0c0c9280: /* original de1a, guest PC 0x0c0c9280 */
if(!s->budget--) { s->failed_pc=0x0c0c9280u; return 0; }
r[14]=read(ram,0x0c0c92ecu,4);
goto P_0c0c9282;
P_0c0c9282: /* original d51b, guest PC 0x0c0c9282 */
if(!s->budget--) { s->failed_pc=0x0c0c9282u; return 0; }
r[5]=read(ram,0x0c0c92f0u,4);
goto P_0c0c9284;
P_0c0c9284: /* original 04ee, guest PC 0x0c0c9284 */
if(!s->budget--) { s->failed_pc=0x0c0c9284u; return 0; }
r[4]=read(ram,r[14]+r[0],4);
goto P_0c0c9286;
P_0c0c9286: /* original 4f22, guest PC 0x0c0c9286 */
if(!s->budget--) { s->failed_pc=0x0c0c9286u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0c9288;
P_0c0c9288: /* original 2458, guest PC 0x0c0c9288 */
if(!s->budget--) { s->failed_pc=0x0c0c9288u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[5])==0)!=0);
goto P_0c0c928a;
P_0c0c928a: /* original 890e, guest PC 0x0c0c928a */
if(!s->budget--) { s->failed_pc=0x0c0c928au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c92aa; }
goto P_0c0c928c;
P_0c0c928c: /* original e011, guest PC 0x0c0c928c */
if(!s->budget--) { s->failed_pc=0x0c0c928cu; return 0; }
r[0]=0x00000011u;
goto P_0c0c928e;
P_0c0c928e: /* original 04ec, guest PC 0x0c0c928e */
if(!s->budget--) { s->failed_pc=0x0c0c928eu; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0c9290;
P_0c0c9290: /* original 604c, guest PC 0x0c0c9290 */
if(!s->budget--) { s->failed_pc=0x0c0c9290u; return 0; }
r[0]=r[4]&255u;
goto P_0c0c9292;
P_0c0c9292: /* original 8848, guest PC 0x0c0c9292 */
if(!s->budget--) { s->failed_pc=0x0c0c9292u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000048u)!=0);
goto P_0c0c9294;
P_0c0c9294: /* original 8f04, guest PC 0x0c0c9294 */
if(!s->budget--) { s->failed_pc=0x0c0c9294u; return 0; }
cond=r[17]&1u;
r[4]=r[0];
if(!cond) { goto P_0c0c92a0; }
goto P_0c0c9298;
P_0c0c9296: /* original 6403, guest PC 0x0c0c9296 */
if(!s->budget--) { s->failed_pc=0x0c0c9296u; return 0; }
r[4]=r[0];
goto P_0c0c9298;
P_0c0c9298: /* original e010, guest PC 0x0c0c9298 */
if(!s->budget--) { s->failed_pc=0x0c0c9298u; return 0; }
r[0]=0x00000010u;
goto P_0c0c929a;
P_0c0c929a: /* original e349, guest PC 0x0c0c929a */
if(!s->budget--) { s->failed_pc=0x0c0c929au; return 0; }
r[3]=0x00000049u;
goto P_0c0c929c;
P_0c0c929c: /* original a005, guest PC 0x0c0c929c */
if(!s->budget--) { s->failed_pc=0x0c0c929cu; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c0c92aa;
P_0c0c929e: /* original 0e34, guest PC 0x0c0c929e */
if(!s->budget--) { s->failed_pc=0x0c0c929eu; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c0c92a0;
P_0c0c92a0: /* original d314, guest PC 0x0c0c92a0 */
if(!s->budget--) { s->failed_pc=0x0c0c92a0u; return 0; }
r[3]=read(ram,0x0c0c92f4u,4);
goto P_0c0c92a2;
P_0c0c92a2: /* original 430b, guest PC 0x0c0c92a2 */
if(!s->budget--) { s->failed_pc=0x0c0c92a2u; return 0; }
target=r[3];
r[16]=code_base|0x0c0c92a6u;
r[4]=0x00000010u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c92a6u) { target=s->pc; goto dispatch; }
goto P_0c0c92a6;
P_0c0c92a4: /* original e410, guest PC 0x0c0c92a4 */
if(!s->budget--) { s->failed_pc=0x0c0c92a4u; return 0; }
r[4]=0x00000010u;
goto P_0c0c92a6;
P_0c0c92a6: /* original e000, guest PC 0x0c0c92a6 */
if(!s->budget--) { s->failed_pc=0x0c0c92a6u; return 0; }
r[0]=0x00000000u;
goto P_0c0c92a8;
P_0c0c92a8: /* original 80eb, guest PC 0x0c0c92a8 */
if(!s->budget--) { s->failed_pc=0x0c0c92a8u; return 0; }
write(ram,r[14]+11,r[0],1);
goto P_0c0c92aa;
P_0c0c92aa: /* original 4f26, guest PC 0x0c0c92aa */
if(!s->budget--) { s->failed_pc=0x0c0c92aau; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0c92ac;
P_0c0c92ac: /* original d312, guest PC 0x0c0c92ac */
if(!s->budget--) { s->failed_pc=0x0c0c92acu; return 0; }
r[3]=read(ram,0x0c0c92f8u,4);
goto P_0c0c92ae;
P_0c0c92ae: /* original 432b, guest PC 0x0c0c92ae */
if(!s->budget--) { s->failed_pc=0x0c0c92aeu; return 0; }
target=r[3];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
code_base=target&0xff000000u;
switch(target&0x1fffffffu) {
case 0x0c09abc4u: return vf3_matrix_family(0x0c09abc4u,s,ram);
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
P_0c0c92b0: /* original 6ef6, guest PC 0x0c0c92b0 */
if(!s->budget--) { s->failed_pc=0x0c0c92b0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0c92b2u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0c92b2u; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
