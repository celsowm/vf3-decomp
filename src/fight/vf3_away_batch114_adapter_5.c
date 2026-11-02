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
int vf3_away_batch114_adapter_5(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c05e3d6u: goto P_0c05e3d6;
case 0x0c05e3d8u: goto P_0c05e3d8;
case 0x0c05e3dau: goto P_0c05e3da;
case 0x0c05e3dcu: goto P_0c05e3dc;
case 0x0c05e3deu: goto P_0c05e3de;
case 0x0c05e3e0u: goto P_0c05e3e0;
case 0x0c05e3e2u: goto P_0c05e3e2;
case 0x0c05e3e4u: goto P_0c05e3e4;
case 0x0c05e3e6u: goto P_0c05e3e6;
case 0x0c05e3e8u: goto P_0c05e3e8;
case 0x0c05e3eau: goto P_0c05e3ea;
case 0x0c05e3ecu: goto P_0c05e3ec;
case 0x0c05e3eeu: goto P_0c05e3ee;
case 0x0c05e3f0u: goto P_0c05e3f0;
case 0x0c05e3f2u: goto P_0c05e3f2;
case 0x0c05e3f4u: goto P_0c05e3f4;
case 0x0c05e3f6u: goto P_0c05e3f6;
case 0x0c05e3f8u: goto P_0c05e3f8;
case 0x0c05fcc4u: goto P_0c05fcc4;
case 0x0c05fcc6u: goto P_0c05fcc6;
case 0x0c05fcc8u: goto P_0c05fcc8;
case 0x0c05fccau: goto P_0c05fcca;
case 0x0c05fcccu: goto P_0c05fccc;
case 0x0c05fcceu: goto P_0c05fcce;
case 0x0c062e7eu: goto P_0c062e7e;
case 0x0c062e80u: goto P_0c062e80;
case 0x0c062e82u: goto P_0c062e82;
case 0x0c062e84u: goto P_0c062e84;
case 0x0c062e86u: goto P_0c062e86;
case 0x0c062e88u: goto P_0c062e88;
case 0x0c062e8au: goto P_0c062e8a;
case 0x0c062e8cu: goto P_0c062e8c;
case 0x0c09493cu: goto P_0c09493c;
case 0x0c09493eu: goto P_0c09493e;
case 0x0c094940u: goto P_0c094940;
case 0x0c094942u: goto P_0c094942;
case 0x0c094944u: goto P_0c094944;
case 0x0c094946u: goto P_0c094946;
case 0x0c094948u: goto P_0c094948;
case 0x0c09494au: goto P_0c09494a;
case 0x0c09494cu: goto P_0c09494c;
case 0x0c09494eu: goto P_0c09494e;
case 0x0c094950u: goto P_0c094950;
case 0x0c094952u: goto P_0c094952;
case 0x0c094954u: goto P_0c094954;
case 0x0c094956u: goto P_0c094956;
case 0x0c094958u: goto P_0c094958;
case 0x0c09495au: goto P_0c09495a;
case 0x0c09495cu: goto P_0c09495c;
case 0x0c09495eu: goto P_0c09495e;
case 0x0c094960u: goto P_0c094960;
case 0x0c094962u: goto P_0c094962;
case 0x0c094964u: goto P_0c094964;
case 0x0c094966u: goto P_0c094966;
case 0x0c094968u: goto P_0c094968;
case 0x0c09496au: goto P_0c09496a;
case 0x0c09496cu: goto P_0c09496c;
case 0x0c09496eu: goto P_0c09496e;
case 0x0c094970u: goto P_0c094970;
case 0x0c094e6cu: goto P_0c094e6c;
case 0x0c094e6eu: goto P_0c094e6e;
case 0x0c094e70u: goto P_0c094e70;
case 0x0c094e72u: goto P_0c094e72;
case 0x0c094e74u: goto P_0c094e74;
case 0x0c094e76u: goto P_0c094e76;
case 0x0c094e78u: goto P_0c094e78;
case 0x0c094e7au: goto P_0c094e7a;
case 0x0c094e7cu: goto P_0c094e7c;
case 0x0c094e7eu: goto P_0c094e7e;
case 0x0c094e80u: goto P_0c094e80;
case 0x0c094e82u: goto P_0c094e82;
case 0x0c094e84u: goto P_0c094e84;
case 0x0c094e86u: goto P_0c094e86;
case 0x0c094e88u: goto P_0c094e88;
case 0x0c094e8au: goto P_0c094e8a;
case 0x0c094e8cu: goto P_0c094e8c;
case 0x0c094e8eu: goto P_0c094e8e;
case 0x0c094e90u: goto P_0c094e90;
case 0x0c094e92u: goto P_0c094e92;
case 0x0c094e94u: goto P_0c094e94;
case 0x0c094e96u: goto P_0c094e96;
case 0x0c094eb0u: goto P_0c094eb0;
case 0x0c094eb2u: goto P_0c094eb2;
case 0x0c094eb4u: goto P_0c094eb4;
case 0x0c094eb6u: goto P_0c094eb6;
case 0x0c094eb8u: goto P_0c094eb8;
case 0x0c094ebau: goto P_0c094eba;
case 0x0c094ebcu: goto P_0c094ebc;
case 0x0c094ebeu: goto P_0c094ebe;
case 0x0c094ec0u: goto P_0c094ec0;
case 0x0c094ec2u: goto P_0c094ec2;
case 0x0c094ec4u: goto P_0c094ec4;
case 0x0c094ec6u: goto P_0c094ec6;
case 0x0c094ec8u: goto P_0c094ec8;
case 0x0c094ecau: goto P_0c094eca;
case 0x0c094eccu: goto P_0c094ecc;
case 0x0c094eceu: goto P_0c094ece;
case 0x0c094ed0u: goto P_0c094ed0;
case 0x0c094ed2u: goto P_0c094ed2;
case 0x0c094ed4u: goto P_0c094ed4;
case 0x0c094ed6u: goto P_0c094ed6;
case 0x0c094ed8u: goto P_0c094ed8;
case 0x0c094edau: goto P_0c094eda;
case 0x0c094edcu: goto P_0c094edc;
case 0x0c094edeu: goto P_0c094ede;
case 0x0c094ee0u: goto P_0c094ee0;
case 0x0c094ee2u: goto P_0c094ee2;
case 0x0c094ee4u: goto P_0c094ee4;
case 0x0c094ee6u: goto P_0c094ee6;
case 0x0c094ee8u: goto P_0c094ee8;
case 0x0c094eeau: goto P_0c094eea;
case 0x0c094eecu: goto P_0c094eec;
case 0x0c094eeeu: goto P_0c094eee;
case 0x0c094ef0u: goto P_0c094ef0;
case 0x0c094ef2u: goto P_0c094ef2;
case 0x0c094ef4u: goto P_0c094ef4;
case 0x0c094ef6u: goto P_0c094ef6;
case 0x0c094ef8u: goto P_0c094ef8;
case 0x0c094efau: goto P_0c094efa;
case 0x0c094efcu: goto P_0c094efc;
case 0x0c094efeu: goto P_0c094efe;
case 0x0c094f00u: goto P_0c094f00;
case 0x0c094f02u: goto P_0c094f02;
case 0x0c094f04u: goto P_0c094f04;
case 0x0c094f06u: goto P_0c094f06;
case 0x0c094f08u: goto P_0c094f08;
case 0x0c094f0au: goto P_0c094f0a;
case 0x0c094f0cu: goto P_0c094f0c;
case 0x0c094f0eu: goto P_0c094f0e;
case 0x0c094f10u: goto P_0c094f10;
case 0x0c094f12u: goto P_0c094f12;
case 0x0c094f14u: goto P_0c094f14;
case 0x0c094f16u: goto P_0c094f16;
case 0x0c094f18u: goto P_0c094f18;
case 0x0c094f1au: goto P_0c094f1a;
case 0x0c094f1cu: goto P_0c094f1c;
case 0x0c094f1eu: goto P_0c094f1e;
case 0x0c094f20u: goto P_0c094f20;
case 0x0c094f22u: goto P_0c094f22;
case 0x0c094f24u: goto P_0c094f24;
case 0x0c094f26u: goto P_0c094f26;
case 0x0c094f28u: goto P_0c094f28;
case 0x0c094f2au: goto P_0c094f2a;
case 0x0c094f2cu: goto P_0c094f2c;
case 0x0c094f2eu: goto P_0c094f2e;
case 0x0c094f30u: goto P_0c094f30;
case 0x0c094f32u: goto P_0c094f32;
case 0x0c094f34u: goto P_0c094f34;
case 0x0c094f36u: goto P_0c094f36;
case 0x0c094f38u: goto P_0c094f38;
case 0x0c094f3au: goto P_0c094f3a;
case 0x0c094f3cu: goto P_0c094f3c;
case 0x0c094f3eu: goto P_0c094f3e;
case 0x0c094f40u: goto P_0c094f40;
case 0x0c094f42u: goto P_0c094f42;
case 0x0c094f44u: goto P_0c094f44;
case 0x0c094f46u: goto P_0c094f46;
case 0x0c094f48u: goto P_0c094f48;
case 0x0c094f4au: goto P_0c094f4a;
case 0x0c094f4cu: goto P_0c094f4c;
case 0x0c094f4eu: goto P_0c094f4e;
case 0x0c094f50u: goto P_0c094f50;
case 0x0c094f52u: goto P_0c094f52;
case 0x0c094f54u: goto P_0c094f54;
case 0x0c094f56u: goto P_0c094f56;
case 0x0c094f58u: goto P_0c094f58;
case 0x0c094f5au: goto P_0c094f5a;
case 0x0c094f5cu: goto P_0c094f5c;
case 0x0c094f5eu: goto P_0c094f5e;
case 0x0c094f60u: goto P_0c094f60;
case 0x0c094f62u: goto P_0c094f62;
case 0x0c094f64u: goto P_0c094f64;
case 0x0c094f66u: goto P_0c094f66;
case 0x0c094f68u: goto P_0c094f68;
case 0x0c094f6au: goto P_0c094f6a;
case 0x0c094f6cu: goto P_0c094f6c;
case 0x0c094f6eu: goto P_0c094f6e;
case 0x0c094f70u: goto P_0c094f70;
case 0x0c094f72u: goto P_0c094f72;
case 0x0c094f74u: goto P_0c094f74;
case 0x0c094f76u: goto P_0c094f76;
case 0x0c094f78u: goto P_0c094f78;
case 0x0c094f7au: goto P_0c094f7a;
case 0x0c094f7cu: goto P_0c094f7c;
case 0x0c094fc0u: goto P_0c094fc0;
case 0x0c094fc2u: goto P_0c094fc2;
case 0x0c094fc4u: goto P_0c094fc4;
case 0x0c094fc6u: goto P_0c094fc6;
case 0x0c094fc8u: goto P_0c094fc8;
case 0x0c094fcau: goto P_0c094fca;
case 0x0c094fccu: goto P_0c094fcc;
case 0x0c094fceu: goto P_0c094fce;
case 0x0c094fd0u: goto P_0c094fd0;
case 0x0c094fd2u: goto P_0c094fd2;
case 0x0c094fd4u: goto P_0c094fd4;
case 0x0c094fd6u: goto P_0c094fd6;
case 0x0c094fd8u: goto P_0c094fd8;
case 0x0c094fdau: goto P_0c094fda;
case 0x0c094fdcu: goto P_0c094fdc;
case 0x0c094fdeu: goto P_0c094fde;
case 0x0c094fe0u: goto P_0c094fe0;
case 0x0c094fe2u: goto P_0c094fe2;
case 0x0c094fe4u: goto P_0c094fe4;
case 0x0c094fe6u: goto P_0c094fe6;
case 0x0c094fe8u: goto P_0c094fe8;
case 0x0c094feau: goto P_0c094fea;
case 0x0c094fecu: goto P_0c094fec;
case 0x0c094feeu: goto P_0c094fee;
case 0x0c094ff0u: goto P_0c094ff0;
case 0x0c094ff2u: goto P_0c094ff2;
case 0x0c094ff4u: goto P_0c094ff4;
case 0x0c094ff6u: goto P_0c094ff6;
case 0x0c094ff8u: goto P_0c094ff8;
case 0x0c094ffau: goto P_0c094ffa;
case 0x0c094ffcu: goto P_0c094ffc;
case 0x0c094ffeu: goto P_0c094ffe;
case 0x0c095000u: goto P_0c095000;
case 0x0c095002u: goto P_0c095002;
case 0x0c095004u: goto P_0c095004;
case 0x0c095006u: goto P_0c095006;
case 0x0c095008u: goto P_0c095008;
case 0x0c09500au: goto P_0c09500a;
case 0x0c09500cu: goto P_0c09500c;
case 0x0c09500eu: goto P_0c09500e;
case 0x0c095010u: goto P_0c095010;
case 0x0c095012u: goto P_0c095012;
case 0x0c095014u: goto P_0c095014;
case 0x0c095016u: goto P_0c095016;
case 0x0c095018u: goto P_0c095018;
case 0x0c09501au: goto P_0c09501a;
case 0x0c09501cu: goto P_0c09501c;
case 0x0c09501eu: goto P_0c09501e;
case 0x0c095020u: goto P_0c095020;
case 0x0c095022u: goto P_0c095022;
case 0x0c095024u: goto P_0c095024;
case 0x0c095026u: goto P_0c095026;
case 0x0c095028u: goto P_0c095028;
case 0x0c09502au: goto P_0c09502a;
case 0x0c09502cu: goto P_0c09502c;
case 0x0c09502eu: goto P_0c09502e;
case 0x0c095030u: goto P_0c095030;
case 0x0c095032u: goto P_0c095032;
case 0x0c095034u: goto P_0c095034;
default: return vf3_matrix_family(target,s,ram);
}
P_0c05e3d6: /* original 6353, guest PC 0x0c05e3d6 */
if(!s->budget--) { s->failed_pc=0x0c05e3d6u; return 0; }
r[3]=r[5];
goto P_0c05e3d8;
P_0c05e3d8: /* original d011, guest PC 0x0c05e3d8 */
if(!s->budget--) { s->failed_pc=0x0c05e3d8u; return 0; }
r[0]=read(ram,0x0c05e420u,4);
goto P_0c05e3da;
P_0c05e3da: /* original 4308, guest PC 0x0c05e3da */
if(!s->budget--) { s->failed_pc=0x0c05e3dau; return 0; }
r[3]<<=2;
goto P_0c05e3dc;
P_0c05e3dc: /* original 4f22, guest PC 0x0c05e3dc */
if(!s->budget--) { s->failed_pc=0x0c05e3dcu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c05e3de;
P_0c05e3de: /* original 7ffc, guest PC 0x0c05e3de */
if(!s->budget--) { s->failed_pc=0x0c05e3deu; return 0; }
r[15]+=0xfffffffcu;
goto P_0c05e3e0;
P_0c05e3e0: /* original 2f52, guest PC 0x0c05e3e0 */
if(!s->budget--) { s->failed_pc=0x0c05e3e0u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c05e3e2;
P_0c05e3e2: /* original 033e, guest PC 0x0c05e3e2 */
if(!s->budget--) { s->failed_pc=0x0c05e3e2u; return 0; }
r[3]=read(ram,r[3]+r[0],4);
goto P_0c05e3e4;
P_0c05e3e4: /* original 430b, guest PC 0x0c05e3e4 */
if(!s->budget--) { s->failed_pc=0x0c05e3e4u; return 0; }
target=r[3];
r[16]=code_base|0x0c05e3e8u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c05e3e8u) { target=s->pc; goto dispatch; }
goto P_0c05e3e8;
P_0c05e3e6: /* original 0009, guest PC 0x0c05e3e6 */
if(!s->budget--) { s->failed_pc=0x0c05e3e6u; return 0; }
goto P_0c05e3e8;
P_0c05e3e8: /* original d30e, guest PC 0x0c05e3e8 */
if(!s->budget--) { s->failed_pc=0x0c05e3e8u; return 0; }
r[3]=read(ram,0x0c05e424u,4);
goto P_0c05e3ea;
P_0c05e3ea: /* original d20f, guest PC 0x0c05e3ea */
if(!s->budget--) { s->failed_pc=0x0c05e3eau; return 0; }
r[2]=read(ram,0x0c05e428u,4);
goto P_0c05e3ec;
P_0c05e3ec: /* original 6132, guest PC 0x0c05e3ec */
if(!s->budget--) { s->failed_pc=0x0c05e3ecu; return 0; }
tmp=read(ram,r[3],4);
r[1]=tmp;
goto P_0c05e3ee;
P_0c05e3ee: /* original 2129, guest PC 0x0c05e3ee */
if(!s->budget--) { s->failed_pc=0x0c05e3eeu; return 0; }
r[1]&=r[2];
goto P_0c05e3f0;
P_0c05e3f0: /* original 2312, guest PC 0x0c05e3f0 */
if(!s->budget--) { s->failed_pc=0x0c05e3f0u; return 0; }
write(ram,r[3],r[1],4);
goto P_0c05e3f2;
P_0c05e3f2: /* original 7f04, guest PC 0x0c05e3f2 */
if(!s->budget--) { s->failed_pc=0x0c05e3f2u; return 0; }
r[15]+=0x00000004u;
goto P_0c05e3f4;
P_0c05e3f4: /* original 4f26, guest PC 0x0c05e3f4 */
if(!s->budget--) { s->failed_pc=0x0c05e3f4u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c05e3f6;
P_0c05e3f6: /* original 000b, guest PC 0x0c05e3f6 */
if(!s->budget--) { s->failed_pc=0x0c05e3f6u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c05e3f8: /* original 0009, guest PC 0x0c05e3f8 */
if(!s->budget--) { s->failed_pc=0x0c05e3f8u; return 0; }
if(!vf3_matrix_family(0x0c05e3fau,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c05e3fau; return 0; } return 1;
P_0c05fcc4: /* original d330, guest PC 0x0c05fcc4 */
if(!s->budget--) { s->failed_pc=0x0c05fcc4u; return 0; }
r[3]=read(ram,0x0c05fd88u,4);
goto P_0c05fcc6;
P_0c05fcc6: /* original 7ffc, guest PC 0x0c05fcc6 */
if(!s->budget--) { s->failed_pc=0x0c05fcc6u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c05fcc8;
P_0c05fcc8: /* original 2f42, guest PC 0x0c05fcc8 */
if(!s->budget--) { s->failed_pc=0x0c05fcc8u; return 0; }
write(ram,r[15],r[4],4);
goto P_0c05fcca;
P_0c05fcca: /* original 6232, guest PC 0x0c05fcca */
if(!s->budget--) { s->failed_pc=0x0c05fccau; return 0; }
tmp=read(ram,r[3],4);
r[2]=tmp;
goto P_0c05fccc;
P_0c05fccc: /* original 422b, guest PC 0x0c05fccc */
if(!s->budget--) { s->failed_pc=0x0c05fcccu; return 0; }
target=r[2];
r[15]+=0x00000004u;
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
P_0c05fcce: /* original 7f04, guest PC 0x0c05fcce */
if(!s->budget--) { s->failed_pc=0x0c05fcceu; return 0; }
r[15]+=0x00000004u;
if(!vf3_matrix_family(0x0c05fcd0u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c05fcd0u; return 0; } return 1;
P_0c062e7e: /* original 4609, guest PC 0x0c062e7e */
if(!s->budget--) { s->failed_pc=0x0c062e7eu; return 0; }
r[6]>>=2;
goto P_0c062e80;
P_0c062e80: /* original 6056, guest PC 0x0c062e80 */
if(!s->budget--) { s->failed_pc=0x0c062e80u; return 0; }
tmp=read(ram,r[5],4);
r[5]+=4;
r[0]=tmp;
goto P_0c062e82;
P_0c062e82: /* original 4610, guest PC 0x0c062e82 */
if(!s->budget--) { s->failed_pc=0x0c062e82u; return 0; }
--r[6];
r[17]=(r[17]&~1u)|((r[6]==0)!=0);
goto P_0c062e84;
P_0c062e84: /* original 2402, guest PC 0x0c062e84 */
if(!s->budget--) { s->failed_pc=0x0c062e84u; return 0; }
write(ram,r[4],r[0],4);
goto P_0c062e86;
P_0c062e86: /* original 8ffb, guest PC 0x0c062e86 */
if(!s->budget--) { s->failed_pc=0x0c062e86u; return 0; }
cond=r[17]&1u;
r[4]+=0x00000004u;
if(!cond) { goto P_0c062e80; }
goto P_0c062e8a;
P_0c062e88: /* original 7404, guest PC 0x0c062e88 */
if(!s->budget--) { s->failed_pc=0x0c062e88u; return 0; }
r[4]+=0x00000004u;
goto P_0c062e8a;
P_0c062e8a: /* original 000b, guest PC 0x0c062e8a */
if(!s->budget--) { s->failed_pc=0x0c062e8au; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c062e8c: /* original 0009, guest PC 0x0c062e8c */
if(!s->budget--) { s->failed_pc=0x0c062e8cu; return 0; }
if(!vf3_matrix_family(0x0c062e8eu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c062e8eu; return 0; } return 1;
P_0c09493c: /* original 4715, guest PC 0x0c09493c */
if(!s->budget--) { s->failed_pc=0x0c09493cu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[7]>0)!=0);
goto P_0c09493e;
P_0c09493e: /* original 6453, guest PC 0x0c09493e */
if(!s->budget--) { s->failed_pc=0x0c09493eu; return 0; }
r[4]=r[5];
goto P_0c094940;
P_0c094940: /* original 8f15, guest PC 0x0c094940 */
if(!s->budget--) { s->failed_pc=0x0c094940u; return 0; }
cond=r[17]&1u;
r[5]=r[6];
if(!cond) { goto P_0c09496e; }
goto P_0c094944;
P_0c094942: /* original 6563, guest PC 0x0c094942 */
if(!s->budget--) { s->failed_pc=0x0c094942u; return 0; }
r[5]=r[6];
goto P_0c094944;
P_0c094944: /* original f549, guest PC 0x0c094944 */
if(!s->budget--) { s->failed_pc=0x0c094944u; return 0; }
vf3_matrix_load(s,ram,5,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c094946;
P_0c094946: /* original 77ff, guest PC 0x0c094946 */
if(!s->budget--) { s->failed_pc=0x0c094946u; return 0; }
r[7]+=0xffffffffu;
goto P_0c094948;
P_0c094948: /* original 4715, guest PC 0x0c094948 */
if(!s->budget--) { s->failed_pc=0x0c094948u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[7]>0)!=0);
goto P_0c09494a;
P_0c09494a: /* original f649, guest PC 0x0c09494a */
if(!s->budget--) { s->failed_pc=0x0c09494au; return 0; }
vf3_matrix_load(s,ram,6,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c09494c;
P_0c09494c: /* original f749, guest PC 0x0c09494c */
if(!s->budget--) { s->failed_pc=0x0c09494cu; return 0; }
vf3_matrix_load(s,ram,7,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c09494e;
P_0c09494e: /* original f849, guest PC 0x0c09494e */
if(!s->budget--) { s->failed_pc=0x0c09494eu; return 0; }
vf3_matrix_load(s,ram,8,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c094950;
P_0c094950: /* original f949, guest PC 0x0c094950 */
if(!s->budget--) { s->failed_pc=0x0c094950u; return 0; }
vf3_matrix_load(s,ram,9,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c094952;
P_0c094952: /* original f449, guest PC 0x0c094952 */
if(!s->budget--) { s->failed_pc=0x0c094952u; return 0; }
vf3_matrix_load(s,ram,4,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c094954;
P_0c094954: /* original f55a, guest PC 0x0c094954 */
if(!s->budget--) { s->failed_pc=0x0c094954u; return 0; }
vf3_matrix_store(s,ram,5,r[5]);
goto P_0c094956;
P_0c094956: /* original 7504, guest PC 0x0c094956 */
if(!s->budget--) { s->failed_pc=0x0c094956u; return 0; }
r[5]+=0x00000004u;
goto P_0c094958;
P_0c094958: /* original f56a, guest PC 0x0c094958 */
if(!s->budget--) { s->failed_pc=0x0c094958u; return 0; }
vf3_matrix_store(s,ram,6,r[5]);
goto P_0c09495a;
P_0c09495a: /* original 7504, guest PC 0x0c09495a */
if(!s->budget--) { s->failed_pc=0x0c09495au; return 0; }
r[5]+=0x00000004u;
goto P_0c09495c;
P_0c09495c: /* original f57a, guest PC 0x0c09495c */
if(!s->budget--) { s->failed_pc=0x0c09495cu; return 0; }
vf3_matrix_store(s,ram,7,r[5]);
goto P_0c09495e;
P_0c09495e: /* original 7504, guest PC 0x0c09495e */
if(!s->budget--) { s->failed_pc=0x0c09495eu; return 0; }
r[5]+=0x00000004u;
goto P_0c094960;
P_0c094960: /* original f58a, guest PC 0x0c094960 */
if(!s->budget--) { s->failed_pc=0x0c094960u; return 0; }
vf3_matrix_store(s,ram,8,r[5]);
goto P_0c094962;
P_0c094962: /* original 7504, guest PC 0x0c094962 */
if(!s->budget--) { s->failed_pc=0x0c094962u; return 0; }
r[5]+=0x00000004u;
goto P_0c094964;
P_0c094964: /* original f59a, guest PC 0x0c094964 */
if(!s->budget--) { s->failed_pc=0x0c094964u; return 0; }
vf3_matrix_store(s,ram,9,r[5]);
goto P_0c094966;
P_0c094966: /* original 7504, guest PC 0x0c094966 */
if(!s->budget--) { s->failed_pc=0x0c094966u; return 0; }
r[5]+=0x00000004u;
goto P_0c094968;
P_0c094968: /* original f54a, guest PC 0x0c094968 */
if(!s->budget--) { s->failed_pc=0x0c094968u; return 0; }
vf3_matrix_store(s,ram,4,r[5]);
goto P_0c09496a;
P_0c09496a: /* original 8deb, guest PC 0x0c09496a */
if(!s->budget--) { s->failed_pc=0x0c09496au; return 0; }
cond=r[17]&1u;
r[5]+=0x00000004u;
if(cond) { goto P_0c094944; }
goto P_0c09496e;
P_0c09496c: /* original 7504, guest PC 0x0c09496c */
if(!s->budget--) { s->failed_pc=0x0c09496cu; return 0; }
r[5]+=0x00000004u;
goto P_0c09496e;
P_0c09496e: /* original 000b, guest PC 0x0c09496e */
if(!s->budget--) { s->failed_pc=0x0c09496eu; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c094970: /* original 0009, guest PC 0x0c094970 */
if(!s->budget--) { s->failed_pc=0x0c094970u; return 0; }
if(!vf3_matrix_family(0x0c094972u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c094972u; return 0; } return 1;
P_0c094e6c: /* original 2fe6, guest PC 0x0c094e6c */
if(!s->budget--) { s->failed_pc=0x0c094e6cu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c094e6e;
P_0c094e6e: /* original 2fd6, guest PC 0x0c094e6e */
if(!s->budget--) { s->failed_pc=0x0c094e6eu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c094e70;
P_0c094e70: /* original 6d43, guest PC 0x0c094e70 */
if(!s->budget--) { s->failed_pc=0x0c094e70u; return 0; }
r[13]=r[4];
goto P_0c094e72;
P_0c094e72: /* original 2fc6, guest PC 0x0c094e72 */
if(!s->budget--) { s->failed_pc=0x0c094e72u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c094e74;
P_0c094e74: /* original 2fb6, guest PC 0x0c094e74 */
if(!s->budget--) { s->failed_pc=0x0c094e74u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c094e76;
P_0c094e76: /* original 2fa6, guest PC 0x0c094e76 */
if(!s->budget--) { s->failed_pc=0x0c094e76u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c094e78;
P_0c094e78: /* original 2f96, guest PC 0x0c094e78 */
if(!s->budget--) { s->failed_pc=0x0c094e78u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c094e7a;
P_0c094e7a: /* original 950d, guest PC 0x0c094e7a */
if(!s->budget--) { s->failed_pc=0x0c094e7au; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c094e98u,2);
goto P_0c094e7c;
P_0c094e7c: /* original 8444, guest PC 0x0c094e7c */
if(!s->budget--) { s->failed_pc=0x0c094e7cu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+4,1);
goto P_0c094e7e;
P_0c094e7e: /* original 3d5c, guest PC 0x0c094e7e */
if(!s->budget--) { s->failed_pc=0x0c094e7eu; return 0; }
r[13]+=r[5];
goto P_0c094e80;
P_0c094e80: /* original 6cd3, guest PC 0x0c094e80 */
if(!s->budget--) { s->failed_pc=0x0c094e80u; return 0; }
r[12]=r[13];
goto P_0c094e82;
P_0c094e82: /* original 3c5c, guest PC 0x0c094e82 */
if(!s->budget--) { s->failed_pc=0x0c094e82u; return 0; }
r[12]+=r[5];
goto P_0c094e84;
P_0c094e84: /* original 6ec3, guest PC 0x0c094e84 */
if(!s->budget--) { s->failed_pc=0x0c094e84u; return 0; }
r[14]=r[12];
goto P_0c094e86;
P_0c094e86: /* original 3e5c, guest PC 0x0c094e86 */
if(!s->budget--) { s->failed_pc=0x0c094e86u; return 0; }
r[14]+=r[5];
goto P_0c094e88;
P_0c094e88: /* original 6be3, guest PC 0x0c094e88 */
if(!s->budget--) { s->failed_pc=0x0c094e88u; return 0; }
r[11]=r[14];
goto P_0c094e8a;
P_0c094e8a: /* original 3b5c, guest PC 0x0c094e8a */
if(!s->budget--) { s->failed_pc=0x0c094e8au; return 0; }
r[11]+=r[5];
goto P_0c094e8c;
P_0c094e8c: /* original 4f22, guest PC 0x0c094e8c */
if(!s->budget--) { s->failed_pc=0x0c094e8cu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c094e8e;
P_0c094e8e: /* original d507, guest PC 0x0c094e8e */
if(!s->budget--) { s->failed_pc=0x0c094e8eu; return 0; }
r[5]=read(ram,0x0c094eacu,4);
goto P_0c094e90;
P_0c094e90: /* original 2008, guest PC 0x0c094e90 */
if(!s->budget--) { s->failed_pc=0x0c094e90u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c094e92;
P_0c094e92: /* original 8b0d, guest PC 0x0c094e92 */
if(!s->budget--) { s->failed_pc=0x0c094e92u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c094eb0; }
goto P_0c094e94;
P_0c094e94: /* original a00d, guest PC 0x0c094e94 */
if(!s->budget--) { s->failed_pc=0x0c094e94u; return 0; }
r[10]=read(ram,r[5]+16,4);
goto P_0c094eb2;
P_0c094e96: /* original 5a54, guest PC 0x0c094e96 */
if(!s->budget--) { s->failed_pc=0x0c094e96u; return 0; }
r[10]=read(ram,r[5]+16,4);
if(!vf3_matrix_family(0x0c094e98u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c094e98u; return 0; } return 1;
P_0c094eb0: /* original 5a55, guest PC 0x0c094eb0 */
if(!s->budget--) { s->failed_pc=0x0c094eb0u; return 0; }
r[10]=read(ram,r[5]+20,4);
goto P_0c094eb2;
P_0c094eb2: /* original 9064, guest PC 0x0c094eb2 */
if(!s->budget--) { s->failed_pc=0x0c094eb2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c094f7eu,2);
goto P_0c094eb4;
P_0c094eb4: /* original e501, guest PC 0x0c094eb4 */
if(!s->budget--) { s->failed_pc=0x0c094eb4u; return 0; }
r[5]=0x00000001u;
goto P_0c094eb6;
P_0c094eb6: /* original 04a6, guest PC 0x0c094eb6 */
if(!s->budget--) { s->failed_pc=0x0c094eb6u; return 0; }
write(ram,r[4]+r[0],r[10],4);
goto P_0c094eb8;
P_0c094eb8: /* original 70fa, guest PC 0x0c094eb8 */
if(!s->budget--) { s->failed_pc=0x0c094eb8u; return 0; }
r[0]+=0xfffffffau;
goto P_0c094eba;
P_0c094eba: /* original 0454, guest PC 0x0c094eba */
if(!s->budget--) { s->failed_pc=0x0c094ebau; return 0; }
write(ram,r[4]+r[0],r[5],1);
goto P_0c094ebc;
P_0c094ebc: /* original e022, guest PC 0x0c094ebc */
if(!s->budget--) { s->failed_pc=0x0c094ebcu; return 0; }
r[0]=0x00000022u;
goto P_0c094ebe;
P_0c094ebe: /* original 5345, guest PC 0x0c094ebe */
if(!s->budget--) { s->failed_pc=0x0c094ebeu; return 0; }
r[3]=read(ram,r[4]+20,4);
goto P_0c094ec0;
P_0c094ec0: /* original 0435, guest PC 0x0c094ec0 */
if(!s->budget--) { s->failed_pc=0x0c094ec0u; return 0; }
write(ram,r[4]+r[0],r[3],2);
goto P_0c094ec2;
P_0c094ec2: /* original 707e, guest PC 0x0c094ec2 */
if(!s->budget--) { s->failed_pc=0x0c094ec2u; return 0; }
r[0]+=0x0000007eu;
goto P_0c094ec4;
P_0c094ec4: /* original 0da6, guest PC 0x0c094ec4 */
if(!s->budget--) { s->failed_pc=0x0c094ec4u; return 0; }
write(ram,r[13]+r[0],r[10],4);
goto P_0c094ec6;
P_0c094ec6: /* original 70fa, guest PC 0x0c094ec6 */
if(!s->budget--) { s->failed_pc=0x0c094ec6u; return 0; }
r[0]+=0xfffffffau;
goto P_0c094ec8;
P_0c094ec8: /* original 0d54, guest PC 0x0c094ec8 */
if(!s->budget--) { s->failed_pc=0x0c094ec8u; return 0; }
write(ram,r[13]+r[0],r[5],1);
goto P_0c094eca;
P_0c094eca: /* original e022, guest PC 0x0c094eca */
if(!s->budget--) { s->failed_pc=0x0c094ecau; return 0; }
r[0]=0x00000022u;
goto P_0c094ecc;
P_0c094ecc: /* original 5345, guest PC 0x0c094ecc */
if(!s->budget--) { s->failed_pc=0x0c094eccu; return 0; }
r[3]=read(ram,r[4]+20,4);
goto P_0c094ece;
P_0c094ece: /* original 0d35, guest PC 0x0c094ece */
if(!s->budget--) { s->failed_pc=0x0c094eceu; return 0; }
write(ram,r[13]+r[0],r[3],2);
goto P_0c094ed0;
P_0c094ed0: /* original 707e, guest PC 0x0c094ed0 */
if(!s->budget--) { s->failed_pc=0x0c094ed0u; return 0; }
r[0]+=0x0000007eu;
goto P_0c094ed2;
P_0c094ed2: /* original 0ca6, guest PC 0x0c094ed2 */
if(!s->budget--) { s->failed_pc=0x0c094ed2u; return 0; }
write(ram,r[12]+r[0],r[10],4);
goto P_0c094ed4;
P_0c094ed4: /* original 70fa, guest PC 0x0c094ed4 */
if(!s->budget--) { s->failed_pc=0x0c094ed4u; return 0; }
r[0]+=0xfffffffau;
goto P_0c094ed6;
P_0c094ed6: /* original 0c54, guest PC 0x0c094ed6 */
if(!s->budget--) { s->failed_pc=0x0c094ed6u; return 0; }
write(ram,r[12]+r[0],r[5],1);
goto P_0c094ed8;
P_0c094ed8: /* original e022, guest PC 0x0c094ed8 */
if(!s->budget--) { s->failed_pc=0x0c094ed8u; return 0; }
r[0]=0x00000022u;
goto P_0c094eda;
P_0c094eda: /* original 5345, guest PC 0x0c094eda */
if(!s->budget--) { s->failed_pc=0x0c094edau; return 0; }
r[3]=read(ram,r[4]+20,4);
goto P_0c094edc;
P_0c094edc: /* original 0c35, guest PC 0x0c094edc */
if(!s->budget--) { s->failed_pc=0x0c094edcu; return 0; }
write(ram,r[12]+r[0],r[3],2);
goto P_0c094ede;
P_0c094ede: /* original 707e, guest PC 0x0c094ede */
if(!s->budget--) { s->failed_pc=0x0c094edeu; return 0; }
r[0]+=0x0000007eu;
goto P_0c094ee0;
P_0c094ee0: /* original 0ea6, guest PC 0x0c094ee0 */
if(!s->budget--) { s->failed_pc=0x0c094ee0u; return 0; }
write(ram,r[14]+r[0],r[10],4);
goto P_0c094ee2;
P_0c094ee2: /* original 70fa, guest PC 0x0c094ee2 */
if(!s->budget--) { s->failed_pc=0x0c094ee2u; return 0; }
r[0]+=0xfffffffau;
goto P_0c094ee4;
P_0c094ee4: /* original 0e54, guest PC 0x0c094ee4 */
if(!s->budget--) { s->failed_pc=0x0c094ee4u; return 0; }
write(ram,r[14]+r[0],r[5],1);
goto P_0c094ee6;
P_0c094ee6: /* original e022, guest PC 0x0c094ee6 */
if(!s->budget--) { s->failed_pc=0x0c094ee6u; return 0; }
r[0]=0x00000022u;
goto P_0c094ee8;
P_0c094ee8: /* original 5345, guest PC 0x0c094ee8 */
if(!s->budget--) { s->failed_pc=0x0c094ee8u; return 0; }
r[3]=read(ram,r[4]+20,4);
goto P_0c094eea;
P_0c094eea: /* original 0e35, guest PC 0x0c094eea */
if(!s->budget--) { s->failed_pc=0x0c094eeau; return 0; }
write(ram,r[14]+r[0],r[3],2);
goto P_0c094eec;
P_0c094eec: /* original 707e, guest PC 0x0c094eec */
if(!s->budget--) { s->failed_pc=0x0c094eecu; return 0; }
r[0]+=0x0000007eu;
goto P_0c094eee;
P_0c094eee: /* original 0ba6, guest PC 0x0c094eee */
if(!s->budget--) { s->failed_pc=0x0c094eeeu; return 0; }
write(ram,r[11]+r[0],r[10],4);
goto P_0c094ef0;
P_0c094ef0: /* original 70fa, guest PC 0x0c094ef0 */
if(!s->budget--) { s->failed_pc=0x0c094ef0u; return 0; }
r[0]+=0xfffffffau;
goto P_0c094ef2;
P_0c094ef2: /* original 0b54, guest PC 0x0c094ef2 */
if(!s->budget--) { s->failed_pc=0x0c094ef2u; return 0; }
write(ram,r[11]+r[0],r[5],1);
goto P_0c094ef4;
P_0c094ef4: /* original e022, guest PC 0x0c094ef4 */
if(!s->budget--) { s->failed_pc=0x0c094ef4u; return 0; }
r[0]=0x00000022u;
goto P_0c094ef6;
P_0c094ef6: /* original 5345, guest PC 0x0c094ef6 */
if(!s->budget--) { s->failed_pc=0x0c094ef6u; return 0; }
r[3]=read(ram,r[4]+20,4);
goto P_0c094ef8;
P_0c094ef8: /* original e679, guest PC 0x0c094ef8 */
if(!s->budget--) { s->failed_pc=0x0c094ef8u; return 0; }
r[6]=0x00000079u;
goto P_0c094efa;
P_0c094efa: /* original 0b35, guest PC 0x0c094efa */
if(!s->budget--) { s->failed_pc=0x0c094efau; return 0; }
write(ram,r[11]+r[0],r[3],2);
goto P_0c094efc;
P_0c094efc: /* original e068, guest PC 0x0c094efc */
if(!s->budget--) { s->failed_pc=0x0c094efcu; return 0; }
r[0]=0x00000068u;
goto P_0c094efe;
P_0c094efe: /* original d221, guest PC 0x0c094efe */
if(!s->budget--) { s->failed_pc=0x0c094efeu; return 0; }
r[2]=read(ram,0x0c094f84u,4);
goto P_0c094f00;
P_0c094f00: /* original 0426, guest PC 0x0c094f00 */
if(!s->budget--) { s->failed_pc=0x0c094f00u; return 0; }
write(ram,r[4]+r[0],r[2],4);
goto P_0c094f02;
P_0c094f02: /* original d321, guest PC 0x0c094f02 */
if(!s->budget--) { s->failed_pc=0x0c094f02u; return 0; }
r[3]=read(ram,0x0c094f88u,4);
goto P_0c094f04;
P_0c094f04: /* original 0d36, guest PC 0x0c094f04 */
if(!s->budget--) { s->failed_pc=0x0c094f04u; return 0; }
write(ram,r[13]+r[0],r[3],4);
goto P_0c094f06;
P_0c094f06: /* original d221, guest PC 0x0c094f06 */
if(!s->budget--) { s->failed_pc=0x0c094f06u; return 0; }
r[2]=read(ram,0x0c094f8cu,4);
goto P_0c094f08;
P_0c094f08: /* original 0c26, guest PC 0x0c094f08 */
if(!s->budget--) { s->failed_pc=0x0c094f08u; return 0; }
write(ram,r[12]+r[0],r[2],4);
goto P_0c094f0a;
P_0c094f0a: /* original d321, guest PC 0x0c094f0a */
if(!s->budget--) { s->failed_pc=0x0c094f0au; return 0; }
r[3]=read(ram,0x0c094f90u,4);
goto P_0c094f0c;
P_0c094f0c: /* original 0e36, guest PC 0x0c094f0c */
if(!s->budget--) { s->failed_pc=0x0c094f0cu; return 0; }
write(ram,r[14]+r[0],r[3],4);
goto P_0c094f0e;
P_0c094f0e: /* original d221, guest PC 0x0c094f0e */
if(!s->budget--) { s->failed_pc=0x0c094f0eu; return 0; }
r[2]=read(ram,0x0c094f94u,4);
goto P_0c094f10;
P_0c094f10: /* original 0b26, guest PC 0x0c094f10 */
if(!s->budget--) { s->failed_pc=0x0c094f10u; return 0; }
write(ram,r[11]+r[0],r[2],4);
goto P_0c094f12;
P_0c094f12: /* original 5045, guest PC 0x0c094f12 */
if(!s->budget--) { s->failed_pc=0x0c094f12u; return 0; }
r[0]=read(ram,r[4]+20,4);
goto P_0c094f14;
P_0c094f14: /* original 8805, guest PC 0x0c094f14 */
if(!s->budget--) { s->failed_pc=0x0c094f14u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000005u)!=0);
goto P_0c094f16;
P_0c094f16: /* original 8f18, guest PC 0x0c094f16 */
if(!s->budget--) { s->failed_pc=0x0c094f16u; return 0; }
cond=r[17]&1u;
r[5]=0x00000010u;
if(!cond) { goto P_0c094f4a; }
goto P_0c094f1a;
P_0c094f18: /* original e510, guest PC 0x0c094f18 */
if(!s->budget--) { s->failed_pc=0x0c094f18u; return 0; }
r[5]=0x00000010u;
goto P_0c094f1a;
P_0c094f1a: /* original d21f, guest PC 0x0c094f1a */
if(!s->budget--) { s->failed_pc=0x0c094f1au; return 0; }
r[2]=read(ram,0x0c094f98u,4);
goto P_0c094f1c;
P_0c094f1c: /* original e050, guest PC 0x0c094f1c */
if(!s->budget--) { s->failed_pc=0x0c094f1cu; return 0; }
r[0]=0x00000050u;
goto P_0c094f1e;
P_0c094f1e: /* original 0426, guest PC 0x0c094f1e */
if(!s->budget--) { s->failed_pc=0x0c094f1eu; return 0; }
write(ram,r[4]+r[0],r[2],4);
goto P_0c094f20;
P_0c094f20: /* original d31e, guest PC 0x0c094f20 */
if(!s->budget--) { s->failed_pc=0x0c094f20u; return 0; }
r[3]=read(ram,0x0c094f9cu,4);
goto P_0c094f22;
P_0c094f22: /* original 0d36, guest PC 0x0c094f22 */
if(!s->budget--) { s->failed_pc=0x0c094f22u; return 0; }
write(ram,r[13]+r[0],r[3],4);
goto P_0c094f24;
P_0c094f24: /* original d21e, guest PC 0x0c094f24 */
if(!s->budget--) { s->failed_pc=0x0c094f24u; return 0; }
r[2]=read(ram,0x0c094fa0u,4);
goto P_0c094f26;
P_0c094f26: /* original 0c26, guest PC 0x0c094f26 */
if(!s->budget--) { s->failed_pc=0x0c094f26u; return 0; }
write(ram,r[12]+r[0],r[2],4);
goto P_0c094f28;
P_0c094f28: /* original d31e, guest PC 0x0c094f28 */
if(!s->budget--) { s->failed_pc=0x0c094f28u; return 0; }
r[3]=read(ram,0x0c094fa4u,4);
goto P_0c094f2a;
P_0c094f2a: /* original 0e36, guest PC 0x0c094f2a */
if(!s->budget--) { s->failed_pc=0x0c094f2au; return 0; }
write(ram,r[14]+r[0],r[3],4);
goto P_0c094f2c;
P_0c094f2c: /* original d21e, guest PC 0x0c094f2c */
if(!s->budget--) { s->failed_pc=0x0c094f2cu; return 0; }
r[2]=read(ram,0x0c094fa8u,4);
goto P_0c094f2e;
P_0c094f2e: /* original 0b26, guest PC 0x0c094f2e */
if(!s->budget--) { s->failed_pc=0x0c094f2eu; return 0; }
write(ram,r[11]+r[0],r[2],4);
goto P_0c094f30;
P_0c094f30: /* original 6063, guest PC 0x0c094f30 */
if(!s->budget--) { s->failed_pc=0x0c094f30u; return 0; }
r[0]=r[6];
goto P_0c094f32;
P_0c094f32: /* original e637, guest PC 0x0c094f32 */
if(!s->budget--) { s->failed_pc=0x0c094f32u; return 0; }
r[6]=0x00000037u;
goto P_0c094f34;
P_0c094f34: /* original 814f, guest PC 0x0c094f34 */
if(!s->budget--) { s->failed_pc=0x0c094f34u; return 0; }
write(ram,r[4]+30,r[0],2);
goto P_0c094f36;
P_0c094f36: /* original 6063, guest PC 0x0c094f36 */
if(!s->budget--) { s->failed_pc=0x0c094f36u; return 0; }
r[0]=r[6];
goto P_0c094f38;
P_0c094f38: /* original 81df, guest PC 0x0c094f38 */
if(!s->budget--) { s->failed_pc=0x0c094f38u; return 0; }
write(ram,r[13]+30,r[0],2);
goto P_0c094f3a;
P_0c094f3a: /* original 6053, guest PC 0x0c094f3a */
if(!s->budget--) { s->failed_pc=0x0c094f3au; return 0; }
r[0]=r[5];
goto P_0c094f3c;
P_0c094f3c: /* original 81cf, guest PC 0x0c094f3c */
if(!s->budget--) { s->failed_pc=0x0c094f3cu; return 0; }
write(ram,r[12]+30,r[0],2);
goto P_0c094f3e;
P_0c094f3e: /* original 6063, guest PC 0x0c094f3e */
if(!s->budget--) { s->failed_pc=0x0c094f3eu; return 0; }
r[0]=r[6];
goto P_0c094f40;
P_0c094f40: /* original 81ef, guest PC 0x0c094f40 */
if(!s->budget--) { s->failed_pc=0x0c094f40u; return 0; }
write(ram,r[14]+30,r[0],2);
goto P_0c094f42;
P_0c094f42: /* original 6053, guest PC 0x0c094f42 */
if(!s->budget--) { s->failed_pc=0x0c094f42u; return 0; }
r[0]=r[5];
goto P_0c094f44;
P_0c094f44: /* original 951c, guest PC 0x0c094f44 */
if(!s->budget--) { s->failed_pc=0x0c094f44u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c094f80u,2);
goto P_0c094f46;
P_0c094f46: /* original a055, guest PC 0x0c094f46 */
if(!s->budget--) { s->failed_pc=0x0c094f46u; return 0; }
write(ram,r[11]+30,r[0],2);
goto P_0c094ff4;
P_0c094f48: /* original 81bf, guest PC 0x0c094f48 */
if(!s->budget--) { s->failed_pc=0x0c094f48u; return 0; }
write(ram,r[11]+30,r[0],2);
goto P_0c094f4a;
P_0c094f4a: /* original 8812, guest PC 0x0c094f4a */
if(!s->budget--) { s->failed_pc=0x0c094f4au; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000012u)!=0);
goto P_0c094f4c;
P_0c094f4c: /* original 8b38, guest PC 0x0c094f4c */
if(!s->budget--) { s->failed_pc=0x0c094f4cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c094fc0; }
goto P_0c094f4e;
P_0c094f4e: /* original d317, guest PC 0x0c094f4e */
if(!s->budget--) { s->failed_pc=0x0c094f4eu; return 0; }
r[3]=read(ram,0x0c094facu,4);
goto P_0c094f50;
P_0c094f50: /* original e050, guest PC 0x0c094f50 */
if(!s->budget--) { s->failed_pc=0x0c094f50u; return 0; }
r[0]=0x00000050u;
goto P_0c094f52;
P_0c094f52: /* original 0436, guest PC 0x0c094f52 */
if(!s->budget--) { s->failed_pc=0x0c094f52u; return 0; }
write(ram,r[4]+r[0],r[3],4);
goto P_0c094f54;
P_0c094f54: /* original d216, guest PC 0x0c094f54 */
if(!s->budget--) { s->failed_pc=0x0c094f54u; return 0; }
r[2]=read(ram,0x0c094fb0u,4);
goto P_0c094f56;
P_0c094f56: /* original 0d26, guest PC 0x0c094f56 */
if(!s->budget--) { s->failed_pc=0x0c094f56u; return 0; }
write(ram,r[13]+r[0],r[2],4);
goto P_0c094f58;
P_0c094f58: /* original d316, guest PC 0x0c094f58 */
if(!s->budget--) { s->failed_pc=0x0c094f58u; return 0; }
r[3]=read(ram,0x0c094fb4u,4);
goto P_0c094f5a;
P_0c094f5a: /* original 0c36, guest PC 0x0c094f5a */
if(!s->budget--) { s->failed_pc=0x0c094f5au; return 0; }
write(ram,r[12]+r[0],r[3],4);
goto P_0c094f5c;
P_0c094f5c: /* original d216, guest PC 0x0c094f5c */
if(!s->budget--) { s->failed_pc=0x0c094f5cu; return 0; }
r[2]=read(ram,0x0c094fb8u,4);
goto P_0c094f5e;
P_0c094f5e: /* original 0e26, guest PC 0x0c094f5e */
if(!s->budget--) { s->failed_pc=0x0c094f5eu; return 0; }
write(ram,r[14]+r[0],r[2],4);
goto P_0c094f60;
P_0c094f60: /* original d316, guest PC 0x0c094f60 */
if(!s->budget--) { s->failed_pc=0x0c094f60u; return 0; }
r[3]=read(ram,0x0c094fbcu,4);
goto P_0c094f62;
P_0c094f62: /* original 0b36, guest PC 0x0c094f62 */
if(!s->budget--) { s->failed_pc=0x0c094f62u; return 0; }
write(ram,r[11]+r[0],r[3],4);
goto P_0c094f64;
P_0c094f64: /* original 6063, guest PC 0x0c094f64 */
if(!s->budget--) { s->failed_pc=0x0c094f64u; return 0; }
r[0]=r[6];
goto P_0c094f66;
P_0c094f66: /* original e647, guest PC 0x0c094f66 */
if(!s->budget--) { s->failed_pc=0x0c094f66u; return 0; }
r[6]=0x00000047u;
goto P_0c094f68;
P_0c094f68: /* original 814f, guest PC 0x0c094f68 */
if(!s->budget--) { s->failed_pc=0x0c094f68u; return 0; }
write(ram,r[4]+30,r[0],2);
goto P_0c094f6a;
P_0c094f6a: /* original 6063, guest PC 0x0c094f6a */
if(!s->budget--) { s->failed_pc=0x0c094f6au; return 0; }
r[0]=r[6];
goto P_0c094f6c;
P_0c094f6c: /* original 81df, guest PC 0x0c094f6c */
if(!s->budget--) { s->failed_pc=0x0c094f6cu; return 0; }
write(ram,r[13]+30,r[0],2);
goto P_0c094f6e;
P_0c094f6e: /* original 6053, guest PC 0x0c094f6e */
if(!s->budget--) { s->failed_pc=0x0c094f6eu; return 0; }
r[0]=r[5];
goto P_0c094f70;
P_0c094f70: /* original 81cf, guest PC 0x0c094f70 */
if(!s->budget--) { s->failed_pc=0x0c094f70u; return 0; }
write(ram,r[12]+30,r[0],2);
goto P_0c094f72;
P_0c094f72: /* original 6063, guest PC 0x0c094f72 */
if(!s->budget--) { s->failed_pc=0x0c094f72u; return 0; }
r[0]=r[6];
goto P_0c094f74;
P_0c094f74: /* original 81ef, guest PC 0x0c094f74 */
if(!s->budget--) { s->failed_pc=0x0c094f74u; return 0; }
write(ram,r[14]+30,r[0],2);
goto P_0c094f76;
P_0c094f76: /* original 6053, guest PC 0x0c094f76 */
if(!s->budget--) { s->failed_pc=0x0c094f76u; return 0; }
r[0]=r[5];
goto P_0c094f78;
P_0c094f78: /* original 9503, guest PC 0x0c094f78 */
if(!s->budget--) { s->failed_pc=0x0c094f78u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c094f82u,2);
goto P_0c094f7a;
P_0c094f7a: /* original a03b, guest PC 0x0c094f7a */
if(!s->budget--) { s->failed_pc=0x0c094f7au; return 0; }
write(ram,r[11]+30,r[0],2);
goto P_0c094ff4;
P_0c094f7c: /* original 81bf, guest PC 0x0c094f7c */
if(!s->budget--) { s->failed_pc=0x0c094f7cu; return 0; }
write(ram,r[11]+30,r[0],2);
if(!vf3_matrix_family(0x0c094f7eu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c094f7eu; return 0; } return 1;
P_0c094fc0: /* original 5045, guest PC 0x0c094fc0 */
if(!s->budget--) { s->failed_pc=0x0c094fc0u; return 0; }
r[0]=read(ram,r[4]+20,4);
goto P_0c094fc2;
P_0c094fc2: /* original 8807, guest PC 0x0c094fc2 */
if(!s->budget--) { s->failed_pc=0x0c094fc2u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000007u)!=0);
goto P_0c094fc4;
P_0c094fc4: /* original 8b2f, guest PC 0x0c094fc4 */
if(!s->budget--) { s->failed_pc=0x0c094fc4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c095026; }
goto P_0c094fc6;
P_0c094fc6: /* original d357, guest PC 0x0c094fc6 */
if(!s->budget--) { s->failed_pc=0x0c094fc6u; return 0; }
r[3]=read(ram,0x0c095124u,4);
goto P_0c094fc8;
P_0c094fc8: /* original e050, guest PC 0x0c094fc8 */
if(!s->budget--) { s->failed_pc=0x0c094fc8u; return 0; }
r[0]=0x00000050u;
goto P_0c094fca;
P_0c094fca: /* original e63c, guest PC 0x0c094fca */
if(!s->budget--) { s->failed_pc=0x0c094fcau; return 0; }
r[6]=0x0000003cu;
goto P_0c094fcc;
P_0c094fcc: /* original 0436, guest PC 0x0c094fcc */
if(!s->budget--) { s->failed_pc=0x0c094fccu; return 0; }
write(ram,r[4]+r[0],r[3],4);
goto P_0c094fce;
P_0c094fce: /* original d256, guest PC 0x0c094fce */
if(!s->budget--) { s->failed_pc=0x0c094fceu; return 0; }
r[2]=read(ram,0x0c095128u,4);
goto P_0c094fd0;
P_0c094fd0: /* original 0d26, guest PC 0x0c094fd0 */
if(!s->budget--) { s->failed_pc=0x0c094fd0u; return 0; }
write(ram,r[13]+r[0],r[2],4);
goto P_0c094fd2;
P_0c094fd2: /* original d356, guest PC 0x0c094fd2 */
if(!s->budget--) { s->failed_pc=0x0c094fd2u; return 0; }
r[3]=read(ram,0x0c09512cu,4);
goto P_0c094fd4;
P_0c094fd4: /* original 0c36, guest PC 0x0c094fd4 */
if(!s->budget--) { s->failed_pc=0x0c094fd4u; return 0; }
write(ram,r[12]+r[0],r[3],4);
goto P_0c094fd6;
P_0c094fd6: /* original d256, guest PC 0x0c094fd6 */
if(!s->budget--) { s->failed_pc=0x0c094fd6u; return 0; }
r[2]=read(ram,0x0c095130u,4);
goto P_0c094fd8;
P_0c094fd8: /* original 0e26, guest PC 0x0c094fd8 */
if(!s->budget--) { s->failed_pc=0x0c094fd8u; return 0; }
write(ram,r[14]+r[0],r[2],4);
goto P_0c094fda;
P_0c094fda: /* original d356, guest PC 0x0c094fda */
if(!s->budget--) { s->failed_pc=0x0c094fdau; return 0; }
r[3]=read(ram,0x0c095134u,4);
goto P_0c094fdc;
P_0c094fdc: /* original 0b36, guest PC 0x0c094fdc */
if(!s->budget--) { s->failed_pc=0x0c094fdcu; return 0; }
write(ram,r[11]+r[0],r[3],4);
goto P_0c094fde;
P_0c094fde: /* original e05c, guest PC 0x0c094fde */
if(!s->budget--) { s->failed_pc=0x0c094fdeu; return 0; }
r[0]=0x0000005cu;
goto P_0c094fe0;
P_0c094fe0: /* original 814f, guest PC 0x0c094fe0 */
if(!s->budget--) { s->failed_pc=0x0c094fe0u; return 0; }
write(ram,r[4]+30,r[0],2);
goto P_0c094fe2;
P_0c094fe2: /* original 6063, guest PC 0x0c094fe2 */
if(!s->budget--) { s->failed_pc=0x0c094fe2u; return 0; }
r[0]=r[6];
goto P_0c094fe4;
P_0c094fe4: /* original 81df, guest PC 0x0c094fe4 */
if(!s->budget--) { s->failed_pc=0x0c094fe4u; return 0; }
write(ram,r[13]+30,r[0],2);
goto P_0c094fe6;
P_0c094fe6: /* original 6053, guest PC 0x0c094fe6 */
if(!s->budget--) { s->failed_pc=0x0c094fe6u; return 0; }
r[0]=r[5];
goto P_0c094fe8;
P_0c094fe8: /* original 81cf, guest PC 0x0c094fe8 */
if(!s->budget--) { s->failed_pc=0x0c094fe8u; return 0; }
write(ram,r[12]+30,r[0],2);
goto P_0c094fea;
P_0c094fea: /* original 6063, guest PC 0x0c094fea */
if(!s->budget--) { s->failed_pc=0x0c094feau; return 0; }
r[0]=r[6];
goto P_0c094fec;
P_0c094fec: /* original 81ef, guest PC 0x0c094fec */
if(!s->budget--) { s->failed_pc=0x0c094fecu; return 0; }
write(ram,r[14]+30,r[0],2);
goto P_0c094fee;
P_0c094fee: /* original 6053, guest PC 0x0c094fee */
if(!s->budget--) { s->failed_pc=0x0c094feeu; return 0; }
r[0]=r[5];
goto P_0c094ff0;
P_0c094ff0: /* original 81bf, guest PC 0x0c094ff0 */
if(!s->budget--) { s->failed_pc=0x0c094ff0u; return 0; }
write(ram,r[11]+30,r[0],2);
goto P_0c094ff2;
P_0c094ff2: /* original 9590, guest PC 0x0c094ff2 */
if(!s->budget--) { s->failed_pc=0x0c094ff2u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c095116u,2);
goto P_0c094ff4;
P_0c094ff4: /* original d050, guest PC 0x0c094ff4 */
if(!s->budget--) { s->failed_pc=0x0c094ff4u; return 0; }
r[0]=read(ram,0x0c095138u,4);
goto P_0c094ff6;
P_0c094ff6: /* original 6953, guest PC 0x0c094ff6 */
if(!s->budget--) { s->failed_pc=0x0c094ff6u; return 0; }
r[9]=r[5];
goto P_0c094ff8;
P_0c094ff8: /* original 4908, guest PC 0x0c094ff8 */
if(!s->budget--) { s->failed_pc=0x0c094ff8u; return 0; }
r[9]<<=2;
goto P_0c094ffa;
P_0c094ffa: /* original 099e, guest PC 0x0c094ffa */
if(!s->budget--) { s->failed_pc=0x0c094ffau; return 0; }
r[9]=read(ram,r[9]+r[0],4);
goto P_0c094ffc;
P_0c094ffc: /* original 6693, guest PC 0x0c094ffc */
if(!s->budget--) { s->failed_pc=0x0c094ffcu; return 0; }
r[6]=r[9];
goto P_0c094ffe;
P_0c094ffe: /* original b01a, guest PC 0x0c094ffe */
if(!s->budget--) { s->failed_pc=0x0c094ffeu; return 0; }
target=code_base|0x0c095036u; r[16]=code_base|0x0c095002u;
r[5]=r[10];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c095002u) { target=s->pc; goto dispatch; }
goto P_0c095002;
P_0c095000: /* original 65a3, guest PC 0x0c095000 */
if(!s->budget--) { s->failed_pc=0x0c095000u; return 0; }
r[5]=r[10];
goto P_0c095002;
P_0c095002: /* original 599b, guest PC 0x0c095002 */
if(!s->budget--) { s->failed_pc=0x0c095002u; return 0; }
r[9]=read(ram,r[9]+44,4);
goto P_0c095004;
P_0c095004: /* original 65a3, guest PC 0x0c095004 */
if(!s->budget--) { s->failed_pc=0x0c095004u; return 0; }
r[5]=r[10];
goto P_0c095006;
P_0c095006: /* original 6693, guest PC 0x0c095006 */
if(!s->budget--) { s->failed_pc=0x0c095006u; return 0; }
r[6]=r[9];
goto P_0c095008;
P_0c095008: /* original b015, guest PC 0x0c095008 */
if(!s->budget--) { s->failed_pc=0x0c095008u; return 0; }
target=code_base|0x0c095036u; r[16]=code_base|0x0c09500cu;
r[4]=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09500cu) { target=s->pc; goto dispatch; }
goto P_0c09500c;
P_0c09500a: /* original 64c3, guest PC 0x0c09500a */
if(!s->budget--) { s->failed_pc=0x0c09500au; return 0; }
r[4]=r[12];
goto P_0c09500c;
P_0c09500c: /* original 569b, guest PC 0x0c09500c */
if(!s->budget--) { s->failed_pc=0x0c09500cu; return 0; }
r[6]=read(ram,r[9]+44,4);
goto P_0c09500e;
P_0c09500e: /* original 65a3, guest PC 0x0c09500e */
if(!s->budget--) { s->failed_pc=0x0c09500eu; return 0; }
r[5]=r[10];
goto P_0c095010;
P_0c095010: /* original b011, guest PC 0x0c095010 */
if(!s->budget--) { s->failed_pc=0x0c095010u; return 0; }
target=code_base|0x0c095036u; r[16]=code_base|0x0c095014u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c095014u) { target=s->pc; goto dispatch; }
goto P_0c095014;
P_0c095012: /* original 64d3, guest PC 0x0c095012 */
if(!s->budget--) { s->failed_pc=0x0c095012u; return 0; }
r[4]=r[13];
goto P_0c095014;
P_0c095014: /* original 5d9c, guest PC 0x0c095014 */
if(!s->budget--) { s->failed_pc=0x0c095014u; return 0; }
r[13]=read(ram,r[9]+48,4);
goto P_0c095016;
P_0c095016: /* original 65a3, guest PC 0x0c095016 */
if(!s->budget--) { s->failed_pc=0x0c095016u; return 0; }
r[5]=r[10];
goto P_0c095018;
P_0c095018: /* original 66d3, guest PC 0x0c095018 */
if(!s->budget--) { s->failed_pc=0x0c095018u; return 0; }
r[6]=r[13];
goto P_0c09501a;
P_0c09501a: /* original b00c, guest PC 0x0c09501a */
if(!s->budget--) { s->failed_pc=0x0c09501au; return 0; }
target=code_base|0x0c095036u; r[16]=code_base|0x0c09501eu;
r[4]=r[11];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09501eu) { target=s->pc; goto dispatch; }
goto P_0c09501e;
P_0c09501c: /* original 64b3, guest PC 0x0c09501c */
if(!s->budget--) { s->failed_pc=0x0c09501cu; return 0; }
r[4]=r[11];
goto P_0c09501e;
P_0c09501e: /* original 56db, guest PC 0x0c09501e */
if(!s->budget--) { s->failed_pc=0x0c09501eu; return 0; }
r[6]=read(ram,r[13]+44,4);
goto P_0c095020;
P_0c095020: /* original 65a3, guest PC 0x0c095020 */
if(!s->budget--) { s->failed_pc=0x0c095020u; return 0; }
r[5]=r[10];
goto P_0c095022;
P_0c095022: /* original b008, guest PC 0x0c095022 */
if(!s->budget--) { s->failed_pc=0x0c095022u; return 0; }
target=code_base|0x0c095036u; r[16]=code_base|0x0c095026u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c095026u) { target=s->pc; goto dispatch; }
goto P_0c095026;
P_0c095024: /* original 64e3, guest PC 0x0c095024 */
if(!s->budget--) { s->failed_pc=0x0c095024u; return 0; }
r[4]=r[14];
goto P_0c095026;
P_0c095026: /* original 4f26, guest PC 0x0c095026 */
if(!s->budget--) { s->failed_pc=0x0c095026u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c095028;
P_0c095028: /* original 69f6, guest PC 0x0c095028 */
if(!s->budget--) { s->failed_pc=0x0c095028u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c09502a;
P_0c09502a: /* original 6af6, guest PC 0x0c09502a */
if(!s->budget--) { s->failed_pc=0x0c09502au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c09502c;
P_0c09502c: /* original 6bf6, guest PC 0x0c09502c */
if(!s->budget--) { s->failed_pc=0x0c09502cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c09502e;
P_0c09502e: /* original 6cf6, guest PC 0x0c09502e */
if(!s->budget--) { s->failed_pc=0x0c09502eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c095030;
P_0c095030: /* original 6df6, guest PC 0x0c095030 */
if(!s->budget--) { s->failed_pc=0x0c095030u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c095032;
P_0c095032: /* original 000b, guest PC 0x0c095032 */
if(!s->budget--) { s->failed_pc=0x0c095032u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c095034: /* original 6ef6, guest PC 0x0c095034 */
if(!s->budget--) { s->failed_pc=0x0c095034u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c095036u,s,ram);
unsupported: s->failed_pc=target; return 0;
}
