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
int vf3_away_batch33_adapter_3(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c066d48u: goto P_0c066d48;
case 0x0c066d4au: goto P_0c066d4a;
case 0x0c066d4cu: goto P_0c066d4c;
case 0x0c066d4eu: goto P_0c066d4e;
case 0x0c066d50u: goto P_0c066d50;
case 0x0c066d52u: goto P_0c066d52;
case 0x0c066d54u: goto P_0c066d54;
case 0x0c066d56u: goto P_0c066d56;
case 0x0c066d58u: goto P_0c066d58;
case 0x0c066d5au: goto P_0c066d5a;
case 0x0c066d5cu: goto P_0c066d5c;
case 0x0c066d5eu: goto P_0c066d5e;
case 0x0c066d60u: goto P_0c066d60;
case 0x0c066d62u: goto P_0c066d62;
case 0x0c066d64u: goto P_0c066d64;
case 0x0c066d66u: goto P_0c066d66;
case 0x0c066d68u: goto P_0c066d68;
case 0x0c066d6au: goto P_0c066d6a;
case 0x0c066d6cu: goto P_0c066d6c;
case 0x0c066d6eu: goto P_0c066d6e;
case 0x0c066d70u: goto P_0c066d70;
case 0x0c066d72u: goto P_0c066d72;
case 0x0c066d74u: goto P_0c066d74;
case 0x0c066d76u: goto P_0c066d76;
case 0x0c066d78u: goto P_0c066d78;
case 0x0c066d7au: goto P_0c066d7a;
case 0x0c066d7cu: goto P_0c066d7c;
case 0x0c066d7eu: goto P_0c066d7e;
case 0x0c066d80u: goto P_0c066d80;
case 0x0c066d82u: goto P_0c066d82;
case 0x0c066d84u: goto P_0c066d84;
case 0x0c066d86u: goto P_0c066d86;
case 0x0c066d88u: goto P_0c066d88;
case 0x0c066d8au: goto P_0c066d8a;
case 0x0c066d8cu: goto P_0c066d8c;
case 0x0c066d8eu: goto P_0c066d8e;
case 0x0c066d90u: goto P_0c066d90;
case 0x0c066d92u: goto P_0c066d92;
case 0x0c066d94u: goto P_0c066d94;
case 0x0c066d96u: goto P_0c066d96;
case 0x0c066d98u: goto P_0c066d98;
case 0x0c066d9au: goto P_0c066d9a;
case 0x0c066d9cu: goto P_0c066d9c;
case 0x0c066d9eu: goto P_0c066d9e;
case 0x0c066da0u: goto P_0c066da0;
case 0x0c066da2u: goto P_0c066da2;
case 0x0c066da4u: goto P_0c066da4;
case 0x0c066da6u: goto P_0c066da6;
case 0x0c066da8u: goto P_0c066da8;
case 0x0c066daau: goto P_0c066daa;
case 0x0c066dacu: goto P_0c066dac;
case 0x0c066daeu: goto P_0c066dae;
case 0x0c066db0u: goto P_0c066db0;
case 0x0c066db2u: goto P_0c066db2;
case 0x0c066db4u: goto P_0c066db4;
case 0x0c066db6u: goto P_0c066db6;
case 0x0c066db8u: goto P_0c066db8;
case 0x0c066dbau: goto P_0c066dba;
case 0x0c066dbcu: goto P_0c066dbc;
case 0x0c066dbeu: goto P_0c066dbe;
case 0x0c066dc0u: goto P_0c066dc0;
case 0x0c066dc2u: goto P_0c066dc2;
case 0x0c066deeu: goto P_0c066dee;
case 0x0c066df0u: goto P_0c066df0;
case 0x0c066df2u: goto P_0c066df2;
case 0x0c066df4u: goto P_0c066df4;
case 0x0c066df6u: goto P_0c066df6;
case 0x0c066df8u: goto P_0c066df8;
case 0x0c066dfau: goto P_0c066dfa;
case 0x0c066dfcu: goto P_0c066dfc;
case 0x0c066dfeu: goto P_0c066dfe;
case 0x0c066e00u: goto P_0c066e00;
case 0x0c066e02u: goto P_0c066e02;
case 0x0c066e04u: goto P_0c066e04;
case 0x0c066e06u: goto P_0c066e06;
case 0x0c066e08u: goto P_0c066e08;
case 0x0c066e0au: goto P_0c066e0a;
case 0x0c066e0cu: goto P_0c066e0c;
case 0x0c066e0eu: goto P_0c066e0e;
case 0x0c066e10u: goto P_0c066e10;
case 0x0c066e12u: goto P_0c066e12;
case 0x0c066e14u: goto P_0c066e14;
case 0x0c066e16u: goto P_0c066e16;
case 0x0c066e18u: goto P_0c066e18;
case 0x0c066e1au: goto P_0c066e1a;
case 0x0c066e1cu: goto P_0c066e1c;
case 0x0c066e1eu: goto P_0c066e1e;
case 0x0c066e20u: goto P_0c066e20;
case 0x0c066e22u: goto P_0c066e22;
case 0x0c066e24u: goto P_0c066e24;
case 0x0c066e26u: goto P_0c066e26;
case 0x0c066e28u: goto P_0c066e28;
case 0x0c066e2au: goto P_0c066e2a;
case 0x0c066e2cu: goto P_0c066e2c;
case 0x0c066e2eu: goto P_0c066e2e;
case 0x0c066e30u: goto P_0c066e30;
case 0x0c066e32u: goto P_0c066e32;
case 0x0c066e34u: goto P_0c066e34;
case 0x0c066e36u: goto P_0c066e36;
case 0x0c066e38u: goto P_0c066e38;
case 0x0c066e3au: goto P_0c066e3a;
case 0x0c066e3cu: goto P_0c066e3c;
case 0x0c066e3eu: goto P_0c066e3e;
case 0x0c066e40u: goto P_0c066e40;
case 0x0c066e42u: goto P_0c066e42;
case 0x0c066e44u: goto P_0c066e44;
case 0x0c066e46u: goto P_0c066e46;
case 0x0c066e78u: goto P_0c066e78;
case 0x0c066e7au: goto P_0c066e7a;
case 0x0c066e7cu: goto P_0c066e7c;
case 0x0c066e7eu: goto P_0c066e7e;
case 0x0c066e80u: goto P_0c066e80;
case 0x0c066e82u: goto P_0c066e82;
case 0x0c066e84u: goto P_0c066e84;
case 0x0c066e86u: goto P_0c066e86;
case 0x0c066e88u: goto P_0c066e88;
case 0x0c066e8au: goto P_0c066e8a;
case 0x0c066e8cu: goto P_0c066e8c;
case 0x0c066e8eu: goto P_0c066e8e;
case 0x0c066e90u: goto P_0c066e90;
case 0x0c066e92u: goto P_0c066e92;
case 0x0c066e94u: goto P_0c066e94;
case 0x0c066e96u: goto P_0c066e96;
case 0x0c066e98u: goto P_0c066e98;
case 0x0c066e9au: goto P_0c066e9a;
case 0x0c066e9cu: goto P_0c066e9c;
case 0x0c066e9eu: goto P_0c066e9e;
case 0x0c066ea0u: goto P_0c066ea0;
case 0x0c066ea2u: goto P_0c066ea2;
case 0x0c066ea4u: goto P_0c066ea4;
case 0x0c066ea6u: goto P_0c066ea6;
case 0x0c066ea8u: goto P_0c066ea8;
case 0x0c066eaau: goto P_0c066eaa;
case 0x0c066eacu: goto P_0c066eac;
case 0x0c066eaeu: goto P_0c066eae;
case 0x0c066eb0u: goto P_0c066eb0;
case 0x0c066eb2u: goto P_0c066eb2;
case 0x0c066eb4u: goto P_0c066eb4;
case 0x0c066eb6u: goto P_0c066eb6;
case 0x0c066eb8u: goto P_0c066eb8;
case 0x0c066ebau: goto P_0c066eba;
case 0x0c066ebcu: goto P_0c066ebc;
case 0x0c066ebeu: goto P_0c066ebe;
case 0x0c066ec0u: goto P_0c066ec0;
case 0x0c066ec2u: goto P_0c066ec2;
case 0x0c066ec4u: goto P_0c066ec4;
case 0x0c066ec6u: goto P_0c066ec6;
case 0x0c066ec8u: goto P_0c066ec8;
case 0x0c066ecau: goto P_0c066eca;
case 0x0c066eccu: goto P_0c066ecc;
case 0x0c066eceu: goto P_0c066ece;
case 0x0c066ed0u: goto P_0c066ed0;
case 0x0c066ed2u: goto P_0c066ed2;
case 0x0c066ed4u: goto P_0c066ed4;
case 0x0c066ed6u: goto P_0c066ed6;
case 0x0c066ed8u: goto P_0c066ed8;
case 0x0c066edau: goto P_0c066eda;
case 0x0c066edcu: goto P_0c066edc;
case 0x0c066edeu: goto P_0c066ede;
case 0x0c066ee0u: goto P_0c066ee0;
case 0x0c066ee2u: goto P_0c066ee2;
case 0x0c066ee4u: goto P_0c066ee4;
case 0x0c066ee6u: goto P_0c066ee6;
case 0x0c066ee8u: goto P_0c066ee8;
case 0x0c066eeau: goto P_0c066eea;
case 0x0c066eecu: goto P_0c066eec;
case 0x0c066eeeu: goto P_0c066eee;
case 0x0c066ef0u: goto P_0c066ef0;
case 0x0c066ef2u: goto P_0c066ef2;
case 0x0c066ef4u: goto P_0c066ef4;
case 0x0c066ef6u: goto P_0c066ef6;
case 0x0c066ef8u: goto P_0c066ef8;
case 0x0c066efau: goto P_0c066efa;
case 0x0c066efcu: goto P_0c066efc;
case 0x0c066efeu: goto P_0c066efe;
case 0x0c066f00u: goto P_0c066f00;
case 0x0c066f02u: goto P_0c066f02;
case 0x0c066f04u: goto P_0c066f04;
case 0x0c066f06u: goto P_0c066f06;
case 0x0c066f08u: goto P_0c066f08;
case 0x0c066f0au: goto P_0c066f0a;
case 0x0c066f0cu: goto P_0c066f0c;
case 0x0c066f0eu: goto P_0c066f0e;
case 0x0c066f10u: goto P_0c066f10;
case 0x0c066f12u: goto P_0c066f12;
case 0x0c066f14u: goto P_0c066f14;
case 0x0c066f16u: goto P_0c066f16;
case 0x0c066f18u: goto P_0c066f18;
case 0x0c066f1au: goto P_0c066f1a;
case 0x0c066f1cu: goto P_0c066f1c;
case 0x0c066f1eu: goto P_0c066f1e;
case 0x0c066f20u: goto P_0c066f20;
case 0x0c066f22u: goto P_0c066f22;
case 0x0c066f24u: goto P_0c066f24;
case 0x0c066f26u: goto P_0c066f26;
case 0x0c066f28u: goto P_0c066f28;
case 0x0c066f2au: goto P_0c066f2a;
case 0x0c066f2cu: goto P_0c066f2c;
case 0x0c066f2eu: goto P_0c066f2e;
case 0x0c066f30u: goto P_0c066f30;
case 0x0c066f32u: goto P_0c066f32;
case 0x0c066f34u: goto P_0c066f34;
case 0x0c066f36u: goto P_0c066f36;
case 0x0c066f38u: goto P_0c066f38;
case 0x0c066f3au: goto P_0c066f3a;
case 0x0c066f3cu: goto P_0c066f3c;
case 0x0c066f3eu: goto P_0c066f3e;
case 0x0c066f40u: goto P_0c066f40;
case 0x0c066f42u: goto P_0c066f42;
case 0x0c066f44u: goto P_0c066f44;
case 0x0c066f46u: goto P_0c066f46;
case 0x0c066f48u: goto P_0c066f48;
case 0x0c066f4au: goto P_0c066f4a;
case 0x0c066f4cu: goto P_0c066f4c;
case 0x0c066f4eu: goto P_0c066f4e;
case 0x0c066f50u: goto P_0c066f50;
case 0x0c066f52u: goto P_0c066f52;
case 0x0c066f54u: goto P_0c066f54;
case 0x0c066f56u: goto P_0c066f56;
case 0x0c066f58u: goto P_0c066f58;
case 0x0c066f5au: goto P_0c066f5a;
case 0x0c066f5cu: goto P_0c066f5c;
case 0x0c066f5eu: goto P_0c066f5e;
case 0x0c066f60u: goto P_0c066f60;
case 0x0c066f62u: goto P_0c066f62;
case 0x0c066f64u: goto P_0c066f64;
case 0x0c066f66u: goto P_0c066f66;
case 0x0c066f68u: goto P_0c066f68;
case 0x0c066f6au: goto P_0c066f6a;
case 0x0c066f6cu: goto P_0c066f6c;
case 0x0c066f6eu: goto P_0c066f6e;
case 0x0c066f70u: goto P_0c066f70;
case 0x0c066f72u: goto P_0c066f72;
case 0x0c066f74u: goto P_0c066f74;
case 0x0c066f76u: goto P_0c066f76;
case 0x0c066f78u: goto P_0c066f78;
case 0x0c066f7au: goto P_0c066f7a;
case 0x0c066f7cu: goto P_0c066f7c;
case 0x0c066f7eu: goto P_0c066f7e;
case 0x0c066f80u: goto P_0c066f80;
case 0x0c066f82u: goto P_0c066f82;
case 0x0c066f84u: goto P_0c066f84;
case 0x0c066f86u: goto P_0c066f86;
default: return vf3_matrix_family(target,s,ram);
}
P_0c066d48: /* original 2fe6, guest PC 0x0c066d48 */
if(!s->budget--) { s->failed_pc=0x0c066d48u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c066d4a;
P_0c066d4a: /* original e214, guest PC 0x0c066d4a */
if(!s->budget--) { s->failed_pc=0x0c066d4au; return 0; }
r[2]=0x00000014u;
goto P_0c066d4c;
P_0c066d4c: /* original 2fd6, guest PC 0x0c066d4c */
if(!s->budget--) { s->failed_pc=0x0c066d4cu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c066d4e;
P_0c066d4e: /* original d344, guest PC 0x0c066d4e */
if(!s->budget--) { s->failed_pc=0x0c066d4eu; return 0; }
r[3]=read(ram,0x0c066e60u,4);
goto P_0c066d50;
P_0c066d50: /* original 907a, guest PC 0x0c066d50 */
if(!s->budget--) { s->failed_pc=0x0c066d50u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c066e48u,2);
goto P_0c066d52;
P_0c066d52: /* original 6e32, guest PC 0x0c066d52 */
if(!s->budget--) { s->failed_pc=0x0c066d52u; return 0; }
tmp=read(ram,r[3],4);
r[14]=tmp;
goto P_0c066d54;
P_0c066d54: /* original 4f22, guest PC 0x0c066d54 */
if(!s->budget--) { s->failed_pc=0x0c066d54u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c066d56;
P_0c066d56: /* original dd41, guest PC 0x0c066d56 */
if(!s->budget--) { s->failed_pc=0x0c066d56u; return 0; }
r[13]=read(ram,0x0c066e5cu,4);
goto P_0c066d58;
P_0c066d58: /* original 0e24, guest PC 0x0c066d58 */
if(!s->budget--) { s->failed_pc=0x0c066d58u; return 0; }
write(ram,r[14]+r[0],r[2],1);
goto P_0c066d5a;
P_0c066d5a: /* original 9076, guest PC 0x0c066d5a */
if(!s->budget--) { s->failed_pc=0x0c066d5au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c066e4au,2);
goto P_0c066d5c;
P_0c066d5c: /* original 0e46, guest PC 0x0c066d5c */
if(!s->budget--) { s->failed_pc=0x0c066d5cu; return 0; }
write(ram,r[14]+r[0],r[4],4);
goto P_0c066d5e;
P_0c066d5e: /* original e400, guest PC 0x0c066d5e */
if(!s->budget--) { s->failed_pc=0x0c066d5eu; return 0; }
r[4]=0x00000000u;
goto P_0c066d60;
P_0c066d60: /* original 7004, guest PC 0x0c066d60 */
if(!s->budget--) { s->failed_pc=0x0c066d60u; return 0; }
r[0]+=0x00000004u;
goto P_0c066d62;
P_0c066d62: /* original 6643, guest PC 0x0c066d62 */
if(!s->budget--) { s->failed_pc=0x0c066d62u; return 0; }
r[6]=r[4];
goto P_0c066d64;
P_0c066d64: /* original 0e44, guest PC 0x0c066d64 */
if(!s->budget--) { s->failed_pc=0x0c066d64u; return 0; }
write(ram,r[14]+r[0],r[4],1);
goto P_0c066d66;
P_0c066d66: /* original 70fa, guest PC 0x0c066d66 */
if(!s->budget--) { s->failed_pc=0x0c066d66u; return 0; }
r[0]+=0xfffffffau;
goto P_0c066d68;
P_0c066d68: /* original 0e45, guest PC 0x0c066d68 */
if(!s->budget--) { s->failed_pc=0x0c066d68u; return 0; }
write(ram,r[14]+r[0],r[4],2);
goto P_0c066d6a;
P_0c066d6a: /* original 906f, guest PC 0x0c066d6a */
if(!s->budget--) { s->failed_pc=0x0c066d6au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c066e4cu,2);
goto P_0c066d6c;
P_0c066d6c: /* original 0e45, guest PC 0x0c066d6c */
if(!s->budget--) { s->failed_pc=0x0c066d6cu; return 0; }
write(ram,r[14]+r[0],r[4],2);
goto P_0c066d6e;
P_0c066d6e: /* original 906e, guest PC 0x0c066d6e */
if(!s->budget--) { s->failed_pc=0x0c066d6eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c066e4eu,2);
goto P_0c066d70;
P_0c066d70: /* original 0e45, guest PC 0x0c066d70 */
if(!s->budget--) { s->failed_pc=0x0c066d70u; return 0; }
write(ram,r[14]+r[0],r[4],2);
goto P_0c066d72;
P_0c066d72: /* original 70f8, guest PC 0x0c066d72 */
if(!s->budget--) { s->failed_pc=0x0c066d72u; return 0; }
r[0]+=0xfffffff8u;
goto P_0c066d74;
P_0c066d74: /* original f48d, guest PC 0x0c066d74 */
if(!s->budget--) { s->failed_pc=0x0c066d74u; return 0; }
fr[4]=0;
goto P_0c066d76;
P_0c066d76: /* original fe47, guest PC 0x0c066d76 */
if(!s->budget--) { s->failed_pc=0x0c066d76u; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c066d78;
P_0c066d78: /* original 70e4, guest PC 0x0c066d78 */
if(!s->budget--) { s->failed_pc=0x0c066d78u; return 0; }
r[0]+=0xffffffe4u;
goto P_0c066d7a;
P_0c066d7a: /* original fe47, guest PC 0x0c066d7a */
if(!s->budget--) { s->failed_pc=0x0c066d7au; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c066d7c;
P_0c066d7c: /* original 7004, guest PC 0x0c066d7c */
if(!s->budget--) { s->failed_pc=0x0c066d7cu; return 0; }
r[0]+=0x00000004u;
goto P_0c066d7e;
P_0c066d7e: /* original fe47, guest PC 0x0c066d7e */
if(!s->budget--) { s->failed_pc=0x0c066d7eu; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c066d80;
P_0c066d80: /* original 7004, guest PC 0x0c066d80 */
if(!s->budget--) { s->failed_pc=0x0c066d80u; return 0; }
r[0]+=0x00000004u;
goto P_0c066d82;
P_0c066d82: /* original fe47, guest PC 0x0c066d82 */
if(!s->budget--) { s->failed_pc=0x0c066d82u; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c066d84;
P_0c066d84: /* original 9464, guest PC 0x0c066d84 */
if(!s->budget--) { s->failed_pc=0x0c066d84u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c066e50u,2);
goto P_0c066d86;
P_0c066d86: /* original d237, guest PC 0x0c066d86 */
if(!s->budget--) { s->failed_pc=0x0c066d86u; return 0; }
r[2]=read(ram,0x0c066e64u,4);
goto P_0c066d88;
P_0c066d88: /* original 420b, guest PC 0x0c066d88 */
if(!s->budget--) { s->failed_pc=0x0c066d88u; return 0; }
target=r[2];
r[16]=code_base|0x0c066d8cu;
r[5]=0x00000001u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c066d8cu) { target=s->pc; goto dispatch; }
goto P_0c066d8c;
P_0c066d8a: /* original e501, guest PC 0x0c066d8a */
if(!s->budget--) { s->failed_pc=0x0c066d8au; return 0; }
r[5]=0x00000001u;
goto P_0c066d8c;
P_0c066d8c: /* original 9062, guest PC 0x0c066d8c */
if(!s->budget--) { s->failed_pc=0x0c066d8cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c066e54u,2);
goto P_0c066d8e;
P_0c066d8e: /* original e201, guest PC 0x0c066d8e */
if(!s->budget--) { s->failed_pc=0x0c066d8eu; return 0; }
r[2]=0x00000001u;
goto P_0c066d90;
P_0c066d90: /* original 935f, guest PC 0x0c066d90 */
if(!s->budget--) { s->failed_pc=0x0c066d90u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c066e52u,2);
goto P_0c066d92;
P_0c066d92: /* original 0e35, guest PC 0x0c066d92 */
if(!s->budget--) { s->failed_pc=0x0c066d92u; return 0; }
write(ram,r[14]+r[0],r[3],2);
goto P_0c066d94;
P_0c066d94: /* original 2e22, guest PC 0x0c066d94 */
if(!s->budget--) { s->failed_pc=0x0c066d94u; return 0; }
write(ram,r[14],r[2],4);
goto P_0c066d96;
P_0c066d96: /* original b2e7, guest PC 0x0c066d96 */
if(!s->budget--) { s->failed_pc=0x0c066d96u; return 0; }
target=code_base|0x0c067368u; r[16]=code_base|0x0c066d9au;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c066d9au) { target=s->pc; goto dispatch; }
goto P_0c066d9a;
P_0c066d98: /* original 64e3, guest PC 0x0c066d98 */
if(!s->budget--) { s->failed_pc=0x0c066d98u; return 0; }
r[4]=r[14];
goto P_0c066d9a;
P_0c066d9a: /* original e020, guest PC 0x0c066d9a */
if(!s->budget--) { s->failed_pc=0x0c066d9au; return 0; }
r[0]=0x00000020u;
goto P_0c066d9c;
P_0c066d9c: /* original 05dd, guest PC 0x0c066d9c */
if(!s->budget--) { s->failed_pc=0x0c066d9cu; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,r[13]+r[0],2);
goto P_0c066d9e;
P_0c066d9e: /* original e022, guest PC 0x0c066d9e */
if(!s->budget--) { s->failed_pc=0x0c066d9eu; return 0; }
r[0]=0x00000022u;
goto P_0c066da0;
P_0c066da0: /* original 04dd, guest PC 0x0c066da0 */
if(!s->budget--) { s->failed_pc=0x0c066da0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[13]+r[0],2);
goto P_0c066da2;
P_0c066da2: /* original 9058, guest PC 0x0c066da2 */
if(!s->budget--) { s->failed_pc=0x0c066da2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c066e56u,2);
goto P_0c066da4;
P_0c066da4: /* original 0d55, guest PC 0x0c066da4 */
if(!s->budget--) { s->failed_pc=0x0c066da4u; return 0; }
write(ram,r[13]+r[0],r[5],2);
goto P_0c066da6;
P_0c066da6: /* original 7002, guest PC 0x0c066da6 */
if(!s->budget--) { s->failed_pc=0x0c066da6u; return 0; }
r[0]+=0x00000002u;
goto P_0c066da8;
P_0c066da8: /* original d32f, guest PC 0x0c066da8 */
if(!s->budget--) { s->failed_pc=0x0c066da8u; return 0; }
r[3]=read(ram,0x0c066e68u,4);
goto P_0c066daa;
P_0c066daa: /* original 430b, guest PC 0x0c066daa */
if(!s->budget--) { s->failed_pc=0x0c066daau; return 0; }
target=r[3];
r[16]=code_base|0x0c066daeu;
write(ram,r[13]+r[0],r[4],2);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c066daeu) { target=s->pc; goto dispatch; }
goto P_0c066dae;
P_0c066dac: /* original 0d45, guest PC 0x0c066dac */
if(!s->budget--) { s->failed_pc=0x0c066dacu; return 0; }
write(ram,r[13]+r[0],r[4],2);
goto P_0c066dae;
P_0c066dae: /* original 2008, guest PC 0x0c066dae */
if(!s->budget--) { s->failed_pc=0x0c066daeu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c066db0;
P_0c066db0: /* original 8904, guest PC 0x0c066db0 */
if(!s->budget--) { s->failed_pc=0x0c066db0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c066dbc; }
goto P_0c066db2;
P_0c066db2: /* original 4f26, guest PC 0x0c066db2 */
if(!s->budget--) { s->failed_pc=0x0c066db2u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c066db4;
P_0c066db4: /* original 64e3, guest PC 0x0c066db4 */
if(!s->budget--) { s->failed_pc=0x0c066db4u; return 0; }
r[4]=r[14];
goto P_0c066db6;
P_0c066db6: /* original 6df6, guest PC 0x0c066db6 */
if(!s->budget--) { s->failed_pc=0x0c066db6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c066db8;
P_0c066db8: /* original a019, guest PC 0x0c066db8 */
if(!s->budget--) { s->failed_pc=0x0c066db8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c066dee;
P_0c066dba: /* original 6ef6, guest PC 0x0c066dba */
if(!s->budget--) { s->failed_pc=0x0c066dbau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c066dbc;
P_0c066dbc: /* original 4f26, guest PC 0x0c066dbc */
if(!s->budget--) { s->failed_pc=0x0c066dbcu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c066dbe;
P_0c066dbe: /* original 6df6, guest PC 0x0c066dbe */
if(!s->budget--) { s->failed_pc=0x0c066dbeu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c066dc0;
P_0c066dc0: /* original 000b, guest PC 0x0c066dc0 */
if(!s->budget--) { s->failed_pc=0x0c066dc0u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c066dc2: /* original 6ef6, guest PC 0x0c066dc2 */
if(!s->budget--) { s->failed_pc=0x0c066dc2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c066dc4u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c066dc4u; return 0; } return 1;
P_0c066dee: /* original 2fe6, guest PC 0x0c066dee */
if(!s->budget--) { s->failed_pc=0x0c066deeu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c066df0;
P_0c066df0: /* original 6e43, guest PC 0x0c066df0 */
if(!s->budget--) { s->failed_pc=0x0c066df0u; return 0; }
r[14]=r[4];
goto P_0c066df2;
P_0c066df2: /* original 2fd6, guest PC 0x0c066df2 */
if(!s->budget--) { s->failed_pc=0x0c066df2u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c066df4;
P_0c066df4: /* original 2fc6, guest PC 0x0c066df4 */
if(!s->budget--) { s->failed_pc=0x0c066df4u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c066df6;
P_0c066df6: /* original 2fb6, guest PC 0x0c066df6 */
if(!s->budget--) { s->failed_pc=0x0c066df6u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c066df8;
P_0c066df8: /* original eb01, guest PC 0x0c066df8 */
if(!s->budget--) { s->failed_pc=0x0c066df8u; return 0; }
r[11]=0x00000001u;
goto P_0c066dfa;
P_0c066dfa: /* original 2fa6, guest PC 0x0c066dfa */
if(!s->budget--) { s->failed_pc=0x0c066dfau; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c066dfc;
P_0c066dfc: /* original 6cb3, guest PC 0x0c066dfc */
if(!s->budget--) { s->failed_pc=0x0c066dfcu; return 0; }
r[12]=r[11];
goto P_0c066dfe;
P_0c066dfe: /* original 2f96, guest PC 0x0c066dfe */
if(!s->budget--) { s->failed_pc=0x0c066dfeu; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c066e00;
P_0c066e00: /* original 2f86, guest PC 0x0c066e00 */
if(!s->budget--) { s->failed_pc=0x0c066e00u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c066e02;
P_0c066e02: /* original 4f22, guest PC 0x0c066e02 */
if(!s->budget--) { s->failed_pc=0x0c066e02u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c066e04;
P_0c066e04: /* original d319, guest PC 0x0c066e04 */
if(!s->budget--) { s->failed_pc=0x0c066e04u; return 0; }
r[3]=read(ram,0x0c066e6cu,4);
goto P_0c066e06;
P_0c066e06: /* original d61a, guest PC 0x0c066e06 */
if(!s->budget--) { s->failed_pc=0x0c066e06u; return 0; }
r[6]=read(ram,0x0c066e70u,4);
goto P_0c066e08;
P_0c066e08: /* original 7fe8, guest PC 0x0c066e08 */
if(!s->budget--) { s->failed_pc=0x0c066e08u; return 0; }
r[15]+=0xffffffe8u;
goto P_0c066e0a;
P_0c066e0a: /* original 1f31, guest PC 0x0c066e0a */
if(!s->budget--) { s->failed_pc=0x0c066e0au; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c066e0c;
P_0c066e0c: /* original e340, guest PC 0x0c066e0c */
if(!s->budget--) { s->failed_pc=0x0c066e0cu; return 0; }
r[3]=0x00000040u;
goto P_0c066e0e;
P_0c066e0e: /* original 64e2, guest PC 0x0c066e0e */
if(!s->budget--) { s->failed_pc=0x0c066e0eu; return 0; }
tmp=read(ram,r[14],4);
r[4]=tmp;
goto P_0c066e10;
P_0c066e10: /* original 2438, guest PC 0x0c066e10 */
if(!s->budget--) { s->failed_pc=0x0c066e10u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[3])==0)!=0);
goto P_0c066e12;
P_0c066e12: /* original 8d04, guest PC 0x0c066e12 */
if(!s->budget--) { s->failed_pc=0x0c066e12u; return 0; }
cond=r[17]&1u;
r[5]=0x00000000u;
if(cond) { goto P_0c066e1e; }
goto P_0c066e16;
P_0c066e14: /* original e500, guest PC 0x0c066e14 */
if(!s->budget--) { s->failed_pc=0x0c066e14u; return 0; }
r[5]=0x00000000u;
goto P_0c066e16;
P_0c066e16: /* original 6462, guest PC 0x0c066e16 */
if(!s->budget--) { s->failed_pc=0x0c066e16u; return 0; }
tmp=read(ram,r[6],4);
r[4]=tmp;
goto P_0c066e18;
P_0c066e18: /* original 24b8, guest PC 0x0c066e18 */
if(!s->budget--) { s->failed_pc=0x0c066e18u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[11])==0)!=0);
goto P_0c066e1a;
P_0c066e1a: /* original 8900, guest PC 0x0c066e1a */
if(!s->budget--) { s->failed_pc=0x0c066e1au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c066e1e; }
goto P_0c066e1c;
P_0c066e1c: /* original 6c53, guest PC 0x0c066e1c */
if(!s->budget--) { s->failed_pc=0x0c066e1cu; return 0; }
r[12]=r[5];
goto P_0c066e1e;
P_0c066e1e: /* original 901b, guest PC 0x0c066e1e */
if(!s->budget--) { s->failed_pc=0x0c066e1eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c066e58u,2);
goto P_0c066e20;
P_0c066e20: /* original e200, guest PC 0x0c066e20 */
if(!s->budget--) { s->failed_pc=0x0c066e20u; return 0; }
r[2]=0x00000000u;
goto P_0c066e22;
P_0c066e22: /* original 03ed, guest PC 0x0c066e22 */
if(!s->budget--) { s->failed_pc=0x0c066e22u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c066e24;
P_0c066e24: /* original 04ed, guest PC 0x0c066e24 */
if(!s->budget--) { s->failed_pc=0x0c066e24u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c066e26;
P_0c066e26: /* original 73ff, guest PC 0x0c066e26 */
if(!s->budget--) { s->failed_pc=0x0c066e26u; return 0; }
r[3]+=0xffffffffu;
goto P_0c066e28;
P_0c066e28: /* original 3426, guest PC 0x0c066e28 */
if(!s->budget--) { s->failed_pc=0x0c066e28u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>r[2])!=0);
goto P_0c066e2a;
P_0c066e2a: /* original 0e35, guest PC 0x0c066e2a */
if(!s->budget--) { s->failed_pc=0x0c066e2au; return 0; }
write(ram,r[14]+r[0],r[3],2);
goto P_0c066e2c;
P_0c066e2c: /* original dd11, guest PC 0x0c066e2c */
if(!s->budget--) { s->failed_pc=0x0c066e2cu; return 0; }
r[13]=read(ram,0x0c066e74u,4);
goto P_0c066e2e;
P_0c066e2e: /* original 8978, guest PC 0x0c066e2e */
if(!s->budget--) { s->failed_pc=0x0c066e2eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c066f22; }
goto P_0c066e30;
P_0c066e30: /* original 900b, guest PC 0x0c066e30 */
if(!s->budget--) { s->failed_pc=0x0c066e30u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c066e4au,2);
goto P_0c066e32;
P_0c066e32: /* original 9212, guest PC 0x0c066e32 */
if(!s->budget--) { s->failed_pc=0x0c066e32u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c066e5au,2);
goto P_0c066e34;
P_0c066e34: /* original 04ee, guest PC 0x0c066e34 */
if(!s->budget--) { s->failed_pc=0x0c066e34u; return 0; }
r[4]=read(ram,r[14]+r[0],4);
goto P_0c066e36;
P_0c066e36: /* original 56d4, guest PC 0x0c066e36 */
if(!s->budget--) { s->failed_pc=0x0c066e36u; return 0; }
r[6]=read(ram,r[13]+16,4);
goto P_0c066e38;
P_0c066e38: /* original 6340, guest PC 0x0c066e38 */
if(!s->budget--) { s->failed_pc=0x0c066e38u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[4],1);
r[3]=tmp;
goto P_0c066e3a;
P_0c066e3a: /* original 633c, guest PC 0x0c066e3a */
if(!s->budget--) { s->failed_pc=0x0c066e3au; return 0; }
r[3]=r[3]&255u;
goto P_0c066e3c;
P_0c066e3c: /* original 3320, guest PC 0x0c066e3c */
if(!s->budget--) { s->failed_pc=0x0c066e3cu; return 0; }
r[17]=(r[17]&~1u)|((r[3]==r[2])!=0);
goto P_0c066e3e;
P_0c066e3e: /* original 8f1b, guest PC 0x0c066e3e */
if(!s->budget--) { s->failed_pc=0x0c066e3eu; return 0; }
cond=r[17]&1u;
r[7]=read(ram,r[13]+20,4);
if(!cond) { goto P_0c066e78; }
goto P_0c066e42;
P_0c066e40: /* original 57d5, guest PC 0x0c066e40 */
if(!s->budget--) { s->failed_pc=0x0c066e40u; return 0; }
r[7]=read(ram,r[13]+20,4);
goto P_0c066e42;
P_0c066e42: /* original 53f1, guest PC 0x0c066e42 */
if(!s->budget--) { s->failed_pc=0x0c066e42u; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c066e44;
P_0c066e44: /* original a096, guest PC 0x0c066e44 */
if(!s->budget--) { s->failed_pc=0x0c066e44u; return 0; }
write(ram,r[3]+12,r[5],4);
goto P_0c066f74;
P_0c066e46: /* original 1353, guest PC 0x0c066e46 */
if(!s->budget--) { s->failed_pc=0x0c066e46u; return 0; }
write(ram,r[3]+12,r[5],4);
if(!vf3_matrix_family(0x0c066e48u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c066e48u; return 0; } return 1;
P_0c066e78: /* original 6240, guest PC 0x0c066e78 */
if(!s->budget--) { s->failed_pc=0x0c066e78u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[4],1);
r[2]=tmp;
goto P_0c066e7a;
P_0c066e7a: /* original 622c, guest PC 0x0c066e7a */
if(!s->budget--) { s->failed_pc=0x0c066e7au; return 0; }
r[2]=r[2]&255u;
goto P_0c066e7c;
P_0c066e7c: /* original 1f24, guest PC 0x0c066e7c */
if(!s->budget--) { s->failed_pc=0x0c066e7cu; return 0; }
write(ram,r[15]+16,r[2],4);
goto P_0c066e7e;
P_0c066e7e: /* original 8541, guest PC 0x0c066e7e */
if(!s->budget--) { s->failed_pc=0x0c066e7eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+2,2);
goto P_0c066e80;
P_0c066e80: /* original 600d, guest PC 0x0c066e80 */
if(!s->budget--) { s->failed_pc=0x0c066e80u; return 0; }
r[0]=r[0]&65535u;
goto P_0c066e82;
P_0c066e82: /* original 1f02, guest PC 0x0c066e82 */
if(!s->budget--) { s->failed_pc=0x0c066e82u; return 0; }
write(ram,r[15]+8,r[0],4);
goto P_0c066e84;
P_0c066e84: /* original 5343, guest PC 0x0c066e84 */
if(!s->budget--) { s->failed_pc=0x0c066e84u; return 0; }
r[3]=read(ram,r[4]+12,4);
goto P_0c066e86;
P_0c066e86: /* original 5941, guest PC 0x0c066e86 */
if(!s->budget--) { s->failed_pc=0x0c066e86u; return 0; }
r[9]=read(ram,r[4]+4,4);
goto P_0c066e88;
P_0c066e88: /* original 5842, guest PC 0x0c066e88 */
if(!s->budget--) { s->failed_pc=0x0c066e88u; return 0; }
r[8]=read(ram,r[4]+8,4);
goto P_0c066e8a;
P_0c066e8a: /* original 1f31, guest PC 0x0c066e8a */
if(!s->budget--) { s->failed_pc=0x0c066e8au; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c066e8c;
P_0c066e8c: /* original 5345, guest PC 0x0c066e8c */
if(!s->budget--) { s->failed_pc=0x0c066e8cu; return 0; }
r[3]=read(ram,r[4]+20,4);
goto P_0c066e8e;
P_0c066e8e: /* original 5a44, guest PC 0x0c066e8e */
if(!s->budget--) { s->failed_pc=0x0c066e8eu; return 0; }
r[10]=read(ram,r[4]+16,4);
goto P_0c066e90;
P_0c066e90: /* original 1f35, guest PC 0x0c066e90 */
if(!s->budget--) { s->failed_pc=0x0c066e90u; return 0; }
write(ram,r[15]+20,r[3],4);
goto P_0c066e92;
P_0c066e92: /* original 5246, guest PC 0x0c066e92 */
if(!s->budget--) { s->failed_pc=0x0c066e92u; return 0; }
r[2]=read(ram,r[4]+24,4);
goto P_0c066e94;
P_0c066e94: /* original 741c, guest PC 0x0c066e94 */
if(!s->budget--) { s->failed_pc=0x0c066e94u; return 0; }
r[4]+=0x0000001cu;
goto P_0c066e96;
P_0c066e96: /* original 1f23, guest PC 0x0c066e96 */
if(!s->budget--) { s->failed_pc=0x0c066e96u; return 0; }
write(ram,r[15]+12,r[2],4);
goto P_0c066e98;
P_0c066e98: /* original 908d, guest PC 0x0c066e98 */
if(!s->budget--) { s->failed_pc=0x0c066e98u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c066fb6u,2);
goto P_0c066e9a;
P_0c066e9a: /* original 0e46, guest PC 0x0c066e9a */
if(!s->budget--) { s->failed_pc=0x0c066e9au; return 0; }
write(ram,r[14]+r[0],r[4],4);
goto P_0c066e9c;
P_0c066e9c: /* original 908c, guest PC 0x0c066e9c */
if(!s->budget--) { s->failed_pc=0x0c066e9cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c066fb8u,2);
goto P_0c066e9e;
P_0c066e9e: /* original 53f4, guest PC 0x0c066e9e */
if(!s->budget--) { s->failed_pc=0x0c066e9eu; return 0; }
r[3]=read(ram,r[15]+16,4);
goto P_0c066ea0;
P_0c066ea0: /* original 0e34, guest PC 0x0c066ea0 */
if(!s->budget--) { s->failed_pc=0x0c066ea0u; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c066ea2;
P_0c066ea2: /* original 908a, guest PC 0x0c066ea2 */
if(!s->budget--) { s->failed_pc=0x0c066ea2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c066fbau,2);
goto P_0c066ea4;
P_0c066ea4: /* original 52f2, guest PC 0x0c066ea4 */
if(!s->budget--) { s->failed_pc=0x0c066ea4u; return 0; }
r[2]=read(ram,r[15]+8,4);
goto P_0c066ea6;
P_0c066ea6: /* original 0e25, guest PC 0x0c066ea6 */
if(!s->budget--) { s->failed_pc=0x0c066ea6u; return 0; }
write(ram,r[14]+r[0],r[2],2);
goto P_0c066ea8;
P_0c066ea8: /* original 9088, guest PC 0x0c066ea8 */
if(!s->budget--) { s->failed_pc=0x0c066ea8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c066fbcu,2);
goto P_0c066eaa;
P_0c066eaa: /* original 0696, guest PC 0x0c066eaa */
if(!s->budget--) { s->failed_pc=0x0c066eaau; return 0; }
write(ram,r[6]+r[0],r[9],4);
goto P_0c066eac;
P_0c066eac: /* original 0786, guest PC 0x0c066eac */
if(!s->budget--) { s->failed_pc=0x0c066eacu; return 0; }
write(ram,r[7]+r[0],r[8],4);
goto P_0c066eae;
P_0c066eae: /* original 9086, guest PC 0x0c066eae */
if(!s->budget--) { s->failed_pc=0x0c066eaeu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c066fbeu,2);
goto P_0c066eb0;
P_0c066eb0: /* original 53f1, guest PC 0x0c066eb0 */
if(!s->budget--) { s->failed_pc=0x0c066eb0u; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c066eb2;
P_0c066eb2: /* original 0636, guest PC 0x0c066eb2 */
if(!s->budget--) { s->failed_pc=0x0c066eb2u; return 0; }
write(ram,r[6]+r[0],r[3],4);
goto P_0c066eb4;
P_0c066eb4: /* original 07a6, guest PC 0x0c066eb4 */
if(!s->budget--) { s->failed_pc=0x0c066eb4u; return 0; }
write(ram,r[7]+r[0],r[10],4);
goto P_0c066eb6;
P_0c066eb6: /* original 53f5, guest PC 0x0c066eb6 */
if(!s->budget--) { s->failed_pc=0x0c066eb6u; return 0; }
r[3]=read(ram,r[15]+20,4);
goto P_0c066eb8;
P_0c066eb8: /* original 9082, guest PC 0x0c066eb8 */
if(!s->budget--) { s->failed_pc=0x0c066eb8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c066fc0u,2);
goto P_0c066eba;
P_0c066eba: /* original 7a04, guest PC 0x0c066eba */
if(!s->budget--) { s->failed_pc=0x0c066ebau; return 0; }
r[10]+=0x00000004u;
goto P_0c066ebc;
P_0c066ebc: /* original 0e36, guest PC 0x0c066ebc */
if(!s->budget--) { s->failed_pc=0x0c066ebcu; return 0; }
write(ram,r[14]+r[0],r[3],4);
goto P_0c066ebe;
P_0c066ebe: /* original e3f3, guest PC 0x0c066ebe */
if(!s->budget--) { s->failed_pc=0x0c066ebeu; return 0; }
r[3]=0xfffffff3u;
goto P_0c066ec0;
P_0c066ec0: /* original 907f, guest PC 0x0c066ec0 */
if(!s->budget--) { s->failed_pc=0x0c066ec0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c066fc2u,2);
goto P_0c066ec2;
P_0c066ec2: /* original 52f3, guest PC 0x0c066ec2 */
if(!s->budget--) { s->failed_pc=0x0c066ec2u; return 0; }
r[2]=read(ram,r[15]+12,4);
goto P_0c066ec4;
P_0c066ec4: /* original 0e26, guest PC 0x0c066ec4 */
if(!s->budget--) { s->failed_pc=0x0c066ec4u; return 0; }
write(ram,r[14]+r[0],r[2],4);
goto P_0c066ec6;
P_0c066ec6: /* original 61e2, guest PC 0x0c066ec6 */
if(!s->budget--) { s->failed_pc=0x0c066ec6u; return 0; }
tmp=read(ram,r[14],4);
r[1]=tmp;
goto P_0c066ec8;
P_0c066ec8: /* original 2139, guest PC 0x0c066ec8 */
if(!s->budget--) { s->failed_pc=0x0c066ec8u; return 0; }
r[1]&=r[3];
goto P_0c066eca;
P_0c066eca: /* original 2e12, guest PC 0x0c066eca */
if(!s->budget--) { s->failed_pc=0x0c066ecau; return 0; }
write(ram,r[14],r[1],4);
goto P_0c066ecc;
P_0c066ecc: /* original 947a, guest PC 0x0c066ecc */
if(!s->budget--) { s->failed_pc=0x0c066eccu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c066fc4u,2);
goto P_0c066ece;
P_0c066ece: /* original 1f94, guest PC 0x0c066ece */
if(!s->budget--) { s->failed_pc=0x0c066eceu; return 0; }
write(ram,r[15]+16,r[9],4);
goto P_0c066ed0;
P_0c066ed0: /* original 6953, guest PC 0x0c066ed0 */
if(!s->budget--) { s->failed_pc=0x0c066ed0u; return 0; }
r[9]=r[5];
goto P_0c066ed2;
P_0c066ed2: /* original 1f83, guest PC 0x0c066ed2 */
if(!s->budget--) { s->failed_pc=0x0c066ed2u; return 0; }
write(ram,r[15]+12,r[8],4);
goto P_0c066ed4;
P_0c066ed4: /* original 6853, guest PC 0x0c066ed4 */
if(!s->budget--) { s->failed_pc=0x0c066ed4u; return 0; }
r[8]=r[5];
goto P_0c066ed6;
P_0c066ed6: /* original 52f1, guest PC 0x0c066ed6 */
if(!s->budget--) { s->failed_pc=0x0c066ed6u; return 0; }
r[2]=read(ram,r[15]+4,4);
goto P_0c066ed8;
P_0c066ed8: /* original 7204, guest PC 0x0c066ed8 */
if(!s->budget--) { s->failed_pc=0x0c066ed8u; return 0; }
r[2]+=0x00000004u;
goto P_0c066eda;
P_0c066eda: /* original 1f22, guest PC 0x0c066eda */
if(!s->budget--) { s->failed_pc=0x0c066edau; return 0; }
write(ram,r[15]+8,r[2],4);
goto P_0c066edc;
P_0c066edc: /* original 1fa5, guest PC 0x0c066edc */
if(!s->budget--) { s->failed_pc=0x0c066edcu; return 0; }
write(ram,r[15]+20,r[10],4);
goto P_0c066ede;
P_0c066ede: /* original 1f51, guest PC 0x0c066ede */
if(!s->budget--) { s->failed_pc=0x0c066edeu; return 0; }
write(ram,r[15]+4,r[5],4);
goto P_0c066ee0;
P_0c066ee0: /* original 51f4, guest PC 0x0c066ee0 */
if(!s->budget--) { s->failed_pc=0x0c066ee0u; return 0; }
r[1]=read(ram,r[15]+16,4);
goto P_0c066ee2;
P_0c066ee2: /* original 2118, guest PC 0x0c066ee2 */
if(!s->budget--) { s->failed_pc=0x0c066ee2u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[1])==0)!=0);
goto P_0c066ee4;
P_0c066ee4: /* original 8f01, guest PC 0x0c066ee4 */
if(!s->budget--) { s->failed_pc=0x0c066ee4u; return 0; }
cond=r[17]&1u;
r[10]=r[5];
if(!cond) { goto P_0c066eea; }
goto P_0c066ee8;
P_0c066ee6: /* original 6a53, guest PC 0x0c066ee6 */
if(!s->budget--) { s->failed_pc=0x0c066ee6u; return 0; }
r[10]=r[5];
goto P_0c066ee8;
P_0c066ee8: /* original 1f41, guest PC 0x0c066ee8 */
if(!s->budget--) { s->failed_pc=0x0c066ee8u; return 0; }
write(ram,r[15]+4,r[4],4);
goto P_0c066eea;
P_0c066eea: /* original 53f3, guest PC 0x0c066eea */
if(!s->budget--) { s->failed_pc=0x0c066eeau; return 0; }
r[3]=read(ram,r[15]+12,4);
goto P_0c066eec;
P_0c066eec: /* original 2338, guest PC 0x0c066eec */
if(!s->budget--) { s->failed_pc=0x0c066eecu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c066eee;
P_0c066eee: /* original 8b00, guest PC 0x0c066eee */
if(!s->budget--) { s->failed_pc=0x0c066eeeu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c066ef2; }
goto P_0c066ef0;
P_0c066ef0: /* original 6843, guest PC 0x0c066ef0 */
if(!s->budget--) { s->failed_pc=0x0c066ef0u; return 0; }
r[8]=r[4];
goto P_0c066ef2;
P_0c066ef2: /* original 52f2, guest PC 0x0c066ef2 */
if(!s->budget--) { s->failed_pc=0x0c066ef2u; return 0; }
r[2]=read(ram,r[15]+8,4);
goto P_0c066ef4;
P_0c066ef4: /* original 2228, guest PC 0x0c066ef4 */
if(!s->budget--) { s->failed_pc=0x0c066ef4u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c066ef6;
P_0c066ef6: /* original 8b00, guest PC 0x0c066ef6 */
if(!s->budget--) { s->failed_pc=0x0c066ef6u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c066efa; }
goto P_0c066ef8;
P_0c066ef8: /* original 6943, guest PC 0x0c066ef8 */
if(!s->budget--) { s->failed_pc=0x0c066ef8u; return 0; }
r[9]=r[4];
goto P_0c066efa;
P_0c066efa: /* original 52f5, guest PC 0x0c066efa */
if(!s->budget--) { s->failed_pc=0x0c066efau; return 0; }
r[2]=read(ram,r[15]+20,4);
goto P_0c066efc;
P_0c066efc: /* original 2228, guest PC 0x0c066efc */
if(!s->budget--) { s->failed_pc=0x0c066efcu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c066efe;
P_0c066efe: /* original 8b00, guest PC 0x0c066efe */
if(!s->budget--) { s->failed_pc=0x0c066efeu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c066f02; }
goto P_0c066f00;
P_0c066f00: /* original 6a43, guest PC 0x0c066f00 */
if(!s->budget--) { s->failed_pc=0x0c066f00u; return 0; }
r[10]=r[4];
goto P_0c066f02;
P_0c066f02: /* original 9060, guest PC 0x0c066f02 */
if(!s->budget--) { s->failed_pc=0x0c066f02u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c066fc6u,2);
goto P_0c066f04;
P_0c066f04: /* original 52f1, guest PC 0x0c066f04 */
if(!s->budget--) { s->failed_pc=0x0c066f04u; return 0; }
r[2]=read(ram,r[15]+4,4);
goto P_0c066f06;
P_0c066f06: /* original 0625, guest PC 0x0c066f06 */
if(!s->budget--) { s->failed_pc=0x0c066f06u; return 0; }
write(ram,r[6]+r[0],r[2],2);
goto P_0c066f08;
P_0c066f08: /* original 0785, guest PC 0x0c066f08 */
if(!s->budget--) { s->failed_pc=0x0c066f08u; return 0; }
write(ram,r[7]+r[0],r[8],2);
goto P_0c066f0a;
P_0c066f0a: /* original 7002, guest PC 0x0c066f0a */
if(!s->budget--) { s->failed_pc=0x0c066f0au; return 0; }
r[0]+=0x00000002u;
goto P_0c066f0c;
P_0c066f0c: /* original 0695, guest PC 0x0c066f0c */
if(!s->budget--) { s->failed_pc=0x0c066f0cu; return 0; }
write(ram,r[6]+r[0],r[9],2);
goto P_0c066f0e;
P_0c066f0e: /* original 07a5, guest PC 0x0c066f0e */
if(!s->budget--) { s->failed_pc=0x0c066f0eu; return 0; }
write(ram,r[7]+r[0],r[10],2);
goto P_0c066f10;
P_0c066f10: /* original 6053, guest PC 0x0c066f10 */
if(!s->budget--) { s->failed_pc=0x0c066f10u; return 0; }
r[0]=r[5];
goto P_0c066f12;
P_0c066f12: /* original b14a, guest PC 0x0c066f12 */
if(!s->budget--) { s->failed_pc=0x0c066f12u; return 0; }
target=code_base|0x0c0671aau; r[16]=code_base|0x0c066f16u;
write(ram,r[14]+6,r[0],2);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c066f16u) { target=s->pc; goto dispatch; }
goto P_0c066f16;
P_0c066f14: /* original 81e3, guest PC 0x0c066f14 */
if(!s->budget--) { s->failed_pc=0x0c066f14u; return 0; }
write(ram,r[14]+6,r[0],2);
goto P_0c066f16;
P_0c066f16: /* original b247, guest PC 0x0c066f16 */
if(!s->budget--) { s->failed_pc=0x0c066f16u; return 0; }
target=code_base|0x0c0673a8u; r[16]=code_base|0x0c066f1au;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c066f1au) { target=s->pc; goto dispatch; }
goto P_0c066f1a;
P_0c066f18: /* original 64e3, guest PC 0x0c066f18 */
if(!s->budget--) { s->failed_pc=0x0c066f18u; return 0; }
r[4]=r[14];
goto P_0c066f1a;
P_0c066f1a: /* original d32c, guest PC 0x0c066f1a */
if(!s->budget--) { s->failed_pc=0x0c066f1au; return 0; }
r[3]=read(ram,0x0c066fccu,4);
goto P_0c066f1c;
P_0c066f1c: /* original e5ff, guest PC 0x0c066f1c */
if(!s->budget--) { s->failed_pc=0x0c066f1cu; return 0; }
r[5]=0xffffffffu;
goto P_0c066f1e;
P_0c066f1e: /* original 430b, guest PC 0x0c066f1e */
if(!s->budget--) { s->failed_pc=0x0c066f1eu; return 0; }
target=r[3];
r[16]=code_base|0x0c066f22u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c066f22u) { target=s->pc; goto dispatch; }
goto P_0c066f22;
P_0c066f20: /* original 64e3, guest PC 0x0c066f20 */
if(!s->budget--) { s->failed_pc=0x0c066f20u; return 0; }
r[4]=r[14];
goto P_0c066f22;
P_0c066f22: /* original 62e2, guest PC 0x0c066f22 */
if(!s->budget--) { s->failed_pc=0x0c066f22u; return 0; }
tmp=read(ram,r[14],4);
r[2]=tmp;
goto P_0c066f24;
P_0c066f24: /* original 2f22, guest PC 0x0c066f24 */
if(!s->budget--) { s->failed_pc=0x0c066f24u; return 0; }
write(ram,r[15],r[2],4);
goto P_0c066f26;
P_0c066f26: /* original 904f, guest PC 0x0c066f26 */
if(!s->budget--) { s->failed_pc=0x0c066f26u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c066fc8u,2);
goto P_0c066f28;
P_0c066f28: /* original 03ed, guest PC 0x0c066f28 */
if(!s->budget--) { s->failed_pc=0x0c066f28u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c066f2a;
P_0c066f2a: /* original 7301, guest PC 0x0c066f2a */
if(!s->budget--) { s->failed_pc=0x0c066f2au; return 0; }
r[3]+=0x00000001u;
goto P_0c066f2c;
P_0c066f2c: /* original 0e35, guest PC 0x0c066f2c */
if(!s->budget--) { s->failed_pc=0x0c066f2cu; return 0; }
write(ram,r[14]+r[0],r[3],2);
goto P_0c066f2e;
P_0c066f2e: /* original 5ad4, guest PC 0x0c066f2e */
if(!s->budget--) { s->failed_pc=0x0c066f2eu; return 0; }
r[10]=read(ram,r[13]+16,4);
goto P_0c066f30;
P_0c066f30: /* original b095, guest PC 0x0c066f30 */
if(!s->budget--) { s->failed_pc=0x0c066f30u; return 0; }
target=code_base|0x0c06705eu; r[16]=code_base|0x0c066f34u;
r[4]=r[10];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c066f34u) { target=s->pc; goto dispatch; }
goto P_0c066f34;
P_0c066f32: /* original 64a3, guest PC 0x0c066f32 */
if(!s->budget--) { s->failed_pc=0x0c066f32u; return 0; }
r[4]=r[10];
goto P_0c066f34;
P_0c066f34: /* original 65f3, guest PC 0x0c066f34 */
if(!s->budget--) { s->failed_pc=0x0c066f34u; return 0; }
r[5]=r[15];
goto P_0c066f36;
P_0c066f36: /* original e604, guest PC 0x0c066f36 */
if(!s->budget--) { s->failed_pc=0x0c066f36u; return 0; }
r[6]=0x00000004u;
goto P_0c066f38;
P_0c066f38: /* original 67c3, guest PC 0x0c066f38 */
if(!s->budget--) { s->failed_pc=0x0c066f38u; return 0; }
r[7]=r[12];
goto P_0c066f3a;
P_0c066f3a: /* original b04d, guest PC 0x0c066f3a */
if(!s->budget--) { s->failed_pc=0x0c066f3au; return 0; }
target=code_base|0x0c066fd8u; r[16]=code_base|0x0c066f3eu;
r[4]=r[10];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c066f3eu) { target=s->pc; goto dispatch; }
goto P_0c066f3e;
P_0c066f3c: /* original 64a3, guest PC 0x0c066f3c */
if(!s->budget--) { s->failed_pc=0x0c066f3cu; return 0; }
r[4]=r[10];
goto P_0c066f3e;
P_0c066f3e: /* original 5ad5, guest PC 0x0c066f3e */
if(!s->budget--) { s->failed_pc=0x0c066f3eu; return 0; }
r[10]=read(ram,r[13]+20,4);
goto P_0c066f40;
P_0c066f40: /* original b08d, guest PC 0x0c066f40 */
if(!s->budget--) { s->failed_pc=0x0c066f40u; return 0; }
target=code_base|0x0c06705eu; r[16]=code_base|0x0c066f44u;
r[4]=r[10];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c066f44u) { target=s->pc; goto dispatch; }
goto P_0c066f44;
P_0c066f42: /* original 64a3, guest PC 0x0c066f42 */
if(!s->budget--) { s->failed_pc=0x0c066f42u; return 0; }
r[4]=r[10];
goto P_0c066f44;
P_0c066f44: /* original 65f3, guest PC 0x0c066f44 */
if(!s->budget--) { s->failed_pc=0x0c066f44u; return 0; }
r[5]=r[15];
goto P_0c066f46;
P_0c066f46: /* original e608, guest PC 0x0c066f46 */
if(!s->budget--) { s->failed_pc=0x0c066f46u; return 0; }
r[6]=0x00000008u;
goto P_0c066f48;
P_0c066f48: /* original 67c3, guest PC 0x0c066f48 */
if(!s->budget--) { s->failed_pc=0x0c066f48u; return 0; }
r[7]=r[12];
goto P_0c066f4a;
P_0c066f4a: /* original b045, guest PC 0x0c066f4a */
if(!s->budget--) { s->failed_pc=0x0c066f4au; return 0; }
target=code_base|0x0c066fd8u; r[16]=code_base|0x0c066f4eu;
r[4]=r[10];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c066f4eu) { target=s->pc; goto dispatch; }
goto P_0c066f4e;
P_0c066f4c: /* original 64a3, guest PC 0x0c066f4c */
if(!s->budget--) { s->failed_pc=0x0c066f4cu; return 0; }
r[4]=r[10];
goto P_0c066f4e;
P_0c066f4e: /* original 62f2, guest PC 0x0c066f4e */
if(!s->budget--) { s->failed_pc=0x0c066f4eu; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c066f50;
P_0c066f50: /* original 2b2b, guest PC 0x0c066f50 */
if(!s->budget--) { s->failed_pc=0x0c066f50u; return 0; }
r[11]|=r[2];
goto P_0c066f52;
P_0c066f52: /* original 63b3, guest PC 0x0c066f52 */
if(!s->budget--) { s->failed_pc=0x0c066f52u; return 0; }
r[3]=r[11];
goto P_0c066f54;
P_0c066f54: /* original 2fb2, guest PC 0x0c066f54 */
if(!s->budget--) { s->failed_pc=0x0c066f54u; return 0; }
write(ram,r[15],r[11],4);
goto P_0c066f56;
P_0c066f56: /* original 2eb2, guest PC 0x0c066f56 */
if(!s->budget--) { s->failed_pc=0x0c066f56u; return 0; }
write(ram,r[14],r[11],4);
goto P_0c066f58;
P_0c066f58: /* original b226, guest PC 0x0c066f58 */
if(!s->budget--) { s->failed_pc=0x0c066f58u; return 0; }
target=code_base|0x0c0673a8u; r[16]=code_base|0x0c066f5cu;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c066f5cu) { target=s->pc; goto dispatch; }
goto P_0c066f5c;
P_0c066f5a: /* original 64e3, guest PC 0x0c066f5a */
if(!s->budget--) { s->failed_pc=0x0c066f5au; return 0; }
r[4]=r[14];
goto P_0c066f5c;
P_0c066f5c: /* original b13c, guest PC 0x0c066f5c */
if(!s->budget--) { s->failed_pc=0x0c066f5cu; return 0; }
target=code_base|0x0c0671d8u; r[16]=code_base|0x0c066f60u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c066f60u) { target=s->pc; goto dispatch; }
goto P_0c066f60;
P_0c066f5e: /* original 64e3, guest PC 0x0c066f5e */
if(!s->budget--) { s->failed_pc=0x0c066f5eu; return 0; }
r[4]=r[14];
goto P_0c066f60;
P_0c066f60: /* original b1ae, guest PC 0x0c066f60 */
if(!s->budget--) { s->failed_pc=0x0c066f60u; return 0; }
target=code_base|0x0c0672c0u; r[16]=code_base|0x0c066f64u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c066f64u) { target=s->pc; goto dispatch; }
goto P_0c066f64;
P_0c066f62: /* original 64e3, guest PC 0x0c066f62 */
if(!s->budget--) { s->failed_pc=0x0c066f62u; return 0; }
r[4]=r[14];
goto P_0c066f64;
P_0c066f64: /* original b1f2, guest PC 0x0c066f64 */
if(!s->budget--) { s->failed_pc=0x0c066f64u; return 0; }
target=code_base|0x0c06734cu; r[16]=code_base|0x0c066f68u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c066f68u) { target=s->pc; goto dispatch; }
goto P_0c066f68;
P_0c066f66: /* original 0009, guest PC 0x0c066f66 */
if(!s->budget--) { s->failed_pc=0x0c066f66u; return 0; }
goto P_0c066f68;
P_0c066f68: /* original b1f2, guest PC 0x0c066f68 */
if(!s->budget--) { s->failed_pc=0x0c066f68u; return 0; }
target=code_base|0x0c067350u; r[16]=code_base|0x0c066f6cu;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c066f6cu) { target=s->pc; goto dispatch; }
goto P_0c066f6c;
P_0c066f6a: /* original 64e3, guest PC 0x0c066f6a */
if(!s->budget--) { s->failed_pc=0x0c066f6au; return 0; }
r[4]=r[14];
goto P_0c066f6c;
P_0c066f6c: /* original d217, guest PC 0x0c066f6c */
if(!s->budget--) { s->failed_pc=0x0c066f6cu; return 0; }
r[2]=read(ram,0x0c066fccu,4);
goto P_0c066f6e;
P_0c066f6e: /* original e500, guest PC 0x0c066f6e */
if(!s->budget--) { s->failed_pc=0x0c066f6eu; return 0; }
r[5]=0x00000000u;
goto P_0c066f70;
P_0c066f70: /* original 420b, guest PC 0x0c066f70 */
if(!s->budget--) { s->failed_pc=0x0c066f70u; return 0; }
target=r[2];
r[16]=code_base|0x0c066f74u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c066f74u) { target=s->pc; goto dispatch; }
goto P_0c066f74;
P_0c066f72: /* original 64e3, guest PC 0x0c066f72 */
if(!s->budget--) { s->failed_pc=0x0c066f72u; return 0; }
r[4]=r[14];
goto P_0c066f74;
P_0c066f74: /* original 7f18, guest PC 0x0c066f74 */
if(!s->budget--) { s->failed_pc=0x0c066f74u; return 0; }
r[15]+=0x00000018u;
goto P_0c066f76;
P_0c066f76: /* original 4f26, guest PC 0x0c066f76 */
if(!s->budget--) { s->failed_pc=0x0c066f76u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c066f78;
P_0c066f78: /* original 68f6, guest PC 0x0c066f78 */
if(!s->budget--) { s->failed_pc=0x0c066f78u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c066f7a;
P_0c066f7a: /* original 69f6, guest PC 0x0c066f7a */
if(!s->budget--) { s->failed_pc=0x0c066f7au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c066f7c;
P_0c066f7c: /* original 6af6, guest PC 0x0c066f7c */
if(!s->budget--) { s->failed_pc=0x0c066f7cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c066f7e;
P_0c066f7e: /* original 6bf6, guest PC 0x0c066f7e */
if(!s->budget--) { s->failed_pc=0x0c066f7eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c066f80;
P_0c066f80: /* original 6cf6, guest PC 0x0c066f80 */
if(!s->budget--) { s->failed_pc=0x0c066f80u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c066f82;
P_0c066f82: /* original 6df6, guest PC 0x0c066f82 */
if(!s->budget--) { s->failed_pc=0x0c066f82u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c066f84;
P_0c066f84: /* original 000b, guest PC 0x0c066f84 */
if(!s->budget--) { s->failed_pc=0x0c066f84u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c066f86: /* original 6ef6, guest PC 0x0c066f86 */
if(!s->budget--) { s->failed_pc=0x0c066f86u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c066f88u,s,ram);
unsupported: s->failed_pc=target; return 0;
}
