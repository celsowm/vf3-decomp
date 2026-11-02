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
int vf3_away_batch20_adapter_57(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c0c7de8u: goto P_0c0c7de8;
case 0x0c0c7deau: goto P_0c0c7dea;
case 0x0c0c7decu: goto P_0c0c7dec;
case 0x0c0c7deeu: goto P_0c0c7dee;
case 0x0c0c7df0u: goto P_0c0c7df0;
case 0x0c0c7df2u: goto P_0c0c7df2;
case 0x0c0c7df4u: goto P_0c0c7df4;
case 0x0c0c7df6u: goto P_0c0c7df6;
case 0x0c0c7df8u: goto P_0c0c7df8;
case 0x0c0c7dfau: goto P_0c0c7dfa;
case 0x0c0c7dfcu: goto P_0c0c7dfc;
case 0x0c0c7dfeu: goto P_0c0c7dfe;
case 0x0c0c7e1cu: goto P_0c0c7e1c;
case 0x0c0c7e1eu: goto P_0c0c7e1e;
case 0x0c0c7e20u: goto P_0c0c7e20;
case 0x0c0c7e22u: goto P_0c0c7e22;
case 0x0c0c7e24u: goto P_0c0c7e24;
case 0x0c0c7e26u: goto P_0c0c7e26;
case 0x0c0c7e28u: goto P_0c0c7e28;
case 0x0c0c7e2au: goto P_0c0c7e2a;
case 0x0c0c7e2cu: goto P_0c0c7e2c;
case 0x0c0c7e2eu: goto P_0c0c7e2e;
case 0x0c0c7e30u: goto P_0c0c7e30;
case 0x0c0c7e32u: goto P_0c0c7e32;
case 0x0c0c7e34u: goto P_0c0c7e34;
case 0x0c0c7e36u: goto P_0c0c7e36;
case 0x0c0c7e38u: goto P_0c0c7e38;
case 0x0c0c7e3au: goto P_0c0c7e3a;
case 0x0c0c7e3cu: goto P_0c0c7e3c;
case 0x0c0c7e3eu: goto P_0c0c7e3e;
case 0x0c0c7e40u: goto P_0c0c7e40;
case 0x0c0c7e42u: goto P_0c0c7e42;
case 0x0c0c7e44u: goto P_0c0c7e44;
case 0x0c0c7e46u: goto P_0c0c7e46;
case 0x0c0c7e48u: goto P_0c0c7e48;
case 0x0c0c7e4au: goto P_0c0c7e4a;
case 0x0c0c7e4cu: goto P_0c0c7e4c;
case 0x0c0c7e4eu: goto P_0c0c7e4e;
case 0x0c0c7e50u: goto P_0c0c7e50;
case 0x0c0c7e52u: goto P_0c0c7e52;
case 0x0c0c7e54u: goto P_0c0c7e54;
case 0x0c0c7e56u: goto P_0c0c7e56;
case 0x0c0c7e58u: goto P_0c0c7e58;
case 0x0c0c7e5au: goto P_0c0c7e5a;
case 0x0c0c7e5cu: goto P_0c0c7e5c;
case 0x0c0c7e5eu: goto P_0c0c7e5e;
case 0x0c0c7e60u: goto P_0c0c7e60;
case 0x0c0c7e62u: goto P_0c0c7e62;
case 0x0c0c7e64u: goto P_0c0c7e64;
case 0x0c0c7e66u: goto P_0c0c7e66;
case 0x0c0c7e68u: goto P_0c0c7e68;
case 0x0c0c7e6au: goto P_0c0c7e6a;
case 0x0c0c7e6cu: goto P_0c0c7e6c;
case 0x0c0c7e6eu: goto P_0c0c7e6e;
case 0x0c0c7e70u: goto P_0c0c7e70;
case 0x0c0c7e72u: goto P_0c0c7e72;
case 0x0c0c7e74u: goto P_0c0c7e74;
case 0x0c0c7e76u: goto P_0c0c7e76;
case 0x0c0c7e78u: goto P_0c0c7e78;
case 0x0c0c7e7au: goto P_0c0c7e7a;
case 0x0c0c7e7cu: goto P_0c0c7e7c;
case 0x0c0c7e7eu: goto P_0c0c7e7e;
case 0x0c0c7e80u: goto P_0c0c7e80;
case 0x0c0c7e82u: goto P_0c0c7e82;
case 0x0c0c7e84u: goto P_0c0c7e84;
case 0x0c0c7e86u: goto P_0c0c7e86;
case 0x0c0c7e88u: goto P_0c0c7e88;
case 0x0c0c7e8au: goto P_0c0c7e8a;
case 0x0c0c7e8cu: goto P_0c0c7e8c;
case 0x0c0c7e8eu: goto P_0c0c7e8e;
case 0x0c0c7e90u: goto P_0c0c7e90;
case 0x0c0c7e92u: goto P_0c0c7e92;
case 0x0c0c7e94u: goto P_0c0c7e94;
case 0x0c0c7e96u: goto P_0c0c7e96;
case 0x0c0c7e98u: goto P_0c0c7e98;
case 0x0c0c7e9au: goto P_0c0c7e9a;
case 0x0c0c7e9cu: goto P_0c0c7e9c;
case 0x0c0c7e9eu: goto P_0c0c7e9e;
case 0x0c0c7ea0u: goto P_0c0c7ea0;
case 0x0c0c7ea2u: goto P_0c0c7ea2;
case 0x0c0c7ea4u: goto P_0c0c7ea4;
case 0x0c0c7ea6u: goto P_0c0c7ea6;
case 0x0c0c7ea8u: goto P_0c0c7ea8;
case 0x0c0c7eaau: goto P_0c0c7eaa;
case 0x0c0c7eacu: goto P_0c0c7eac;
case 0x0c0c7eaeu: goto P_0c0c7eae;
case 0x0c0c7eb0u: goto P_0c0c7eb0;
case 0x0c0c7eb2u: goto P_0c0c7eb2;
case 0x0c0c7eb4u: goto P_0c0c7eb4;
case 0x0c0c7eb6u: goto P_0c0c7eb6;
case 0x0c0c7eb8u: goto P_0c0c7eb8;
case 0x0c0c7ebau: goto P_0c0c7eba;
case 0x0c0c7ebcu: goto P_0c0c7ebc;
case 0x0c0c7ebeu: goto P_0c0c7ebe;
case 0x0c0c7ec0u: goto P_0c0c7ec0;
case 0x0c0c7ec2u: goto P_0c0c7ec2;
case 0x0c0c7ec4u: goto P_0c0c7ec4;
case 0x0c0c7ec6u: goto P_0c0c7ec6;
case 0x0c0c7ec8u: goto P_0c0c7ec8;
case 0x0c0c7ecau: goto P_0c0c7eca;
case 0x0c0c7eccu: goto P_0c0c7ecc;
case 0x0c0c7eceu: goto P_0c0c7ece;
case 0x0c0c7ed0u: goto P_0c0c7ed0;
case 0x0c0c7ed2u: goto P_0c0c7ed2;
case 0x0c0c7ed4u: goto P_0c0c7ed4;
case 0x0c0c7ed6u: goto P_0c0c7ed6;
case 0x0c0c7ed8u: goto P_0c0c7ed8;
case 0x0c0c7edau: goto P_0c0c7eda;
case 0x0c0c7edcu: goto P_0c0c7edc;
case 0x0c0c7edeu: goto P_0c0c7ede;
case 0x0c0c7ee0u: goto P_0c0c7ee0;
case 0x0c0c7ee2u: goto P_0c0c7ee2;
case 0x0c0c7ee4u: goto P_0c0c7ee4;
case 0x0c0c7ee6u: goto P_0c0c7ee6;
case 0x0c0c7ee8u: goto P_0c0c7ee8;
case 0x0c0c7eeau: goto P_0c0c7eea;
case 0x0c0c7eecu: goto P_0c0c7eec;
case 0x0c0c7eeeu: goto P_0c0c7eee;
case 0x0c0c7ef0u: goto P_0c0c7ef0;
case 0x0c0c7ef2u: goto P_0c0c7ef2;
case 0x0c0c7ef4u: goto P_0c0c7ef4;
case 0x0c0c7ef6u: goto P_0c0c7ef6;
case 0x0c0c7ef8u: goto P_0c0c7ef8;
case 0x0c0c7efau: goto P_0c0c7efa;
case 0x0c0c7efcu: goto P_0c0c7efc;
case 0x0c0c7efeu: goto P_0c0c7efe;
case 0x0c0c7f00u: goto P_0c0c7f00;
case 0x0c0c7f02u: goto P_0c0c7f02;
case 0x0c0c7f44u: goto P_0c0c7f44;
case 0x0c0c7f46u: goto P_0c0c7f46;
case 0x0c0c7f48u: goto P_0c0c7f48;
case 0x0c0c7f4au: goto P_0c0c7f4a;
case 0x0c0c7f4cu: goto P_0c0c7f4c;
case 0x0c0c7f4eu: goto P_0c0c7f4e;
case 0x0c0c7f50u: goto P_0c0c7f50;
case 0x0c0c7f52u: goto P_0c0c7f52;
case 0x0c0c7f54u: goto P_0c0c7f54;
case 0x0c0c7f56u: goto P_0c0c7f56;
case 0x0c0c7f58u: goto P_0c0c7f58;
case 0x0c0c7f5au: goto P_0c0c7f5a;
case 0x0c0c7f5cu: goto P_0c0c7f5c;
case 0x0c0c7f5eu: goto P_0c0c7f5e;
case 0x0c0c7f60u: goto P_0c0c7f60;
case 0x0c0c7f62u: goto P_0c0c7f62;
case 0x0c0c7f64u: goto P_0c0c7f64;
case 0x0c0c7f66u: goto P_0c0c7f66;
case 0x0c0c7f68u: goto P_0c0c7f68;
case 0x0c0c7f6au: goto P_0c0c7f6a;
case 0x0c0c7f6cu: goto P_0c0c7f6c;
case 0x0c0c7f6eu: goto P_0c0c7f6e;
case 0x0c0c7f70u: goto P_0c0c7f70;
case 0x0c0c7f72u: goto P_0c0c7f72;
case 0x0c0c7f74u: goto P_0c0c7f74;
case 0x0c0c7f76u: goto P_0c0c7f76;
case 0x0c0c7f78u: goto P_0c0c7f78;
case 0x0c0c7f7au: goto P_0c0c7f7a;
case 0x0c0c7f7cu: goto P_0c0c7f7c;
case 0x0c0c7f7eu: goto P_0c0c7f7e;
case 0x0c0c7f80u: goto P_0c0c7f80;
case 0x0c0c7f82u: goto P_0c0c7f82;
case 0x0c0c7f84u: goto P_0c0c7f84;
case 0x0c0c7f86u: goto P_0c0c7f86;
case 0x0c0c7f88u: goto P_0c0c7f88;
case 0x0c0c7f8au: goto P_0c0c7f8a;
case 0x0c0c7f8cu: goto P_0c0c7f8c;
case 0x0c0c7f8eu: goto P_0c0c7f8e;
case 0x0c0c7f90u: goto P_0c0c7f90;
case 0x0c0c7f92u: goto P_0c0c7f92;
case 0x0c0c7f94u: goto P_0c0c7f94;
case 0x0c0c7f96u: goto P_0c0c7f96;
case 0x0c0c7f98u: goto P_0c0c7f98;
case 0x0c0c7f9au: goto P_0c0c7f9a;
case 0x0c0c7f9cu: goto P_0c0c7f9c;
case 0x0c0c7f9eu: goto P_0c0c7f9e;
case 0x0c0c7fa0u: goto P_0c0c7fa0;
case 0x0c0c7fa2u: goto P_0c0c7fa2;
case 0x0c0c7fa4u: goto P_0c0c7fa4;
case 0x0c0c7fa6u: goto P_0c0c7fa6;
case 0x0c0c7fa8u: goto P_0c0c7fa8;
case 0x0c0c7faau: goto P_0c0c7faa;
case 0x0c0c7facu: goto P_0c0c7fac;
case 0x0c0c7faeu: goto P_0c0c7fae;
case 0x0c0c7fb0u: goto P_0c0c7fb0;
case 0x0c0c7fb2u: goto P_0c0c7fb2;
case 0x0c0c7fb4u: goto P_0c0c7fb4;
case 0x0c0ca6c6u: goto P_0c0ca6c6;
case 0x0c0ca6c8u: goto P_0c0ca6c8;
case 0x0c0ca6cau: goto P_0c0ca6ca;
case 0x0c0ca6ccu: goto P_0c0ca6cc;
case 0x0c0ca6ceu: goto P_0c0ca6ce;
case 0x0c0ca6d0u: goto P_0c0ca6d0;
case 0x0c0ca6d2u: goto P_0c0ca6d2;
case 0x0c0ca6d4u: goto P_0c0ca6d4;
case 0x0c0ca6d6u: goto P_0c0ca6d6;
case 0x0c0ca6d8u: goto P_0c0ca6d8;
case 0x0c0ca6dau: goto P_0c0ca6da;
case 0x0c0ca6dcu: goto P_0c0ca6dc;
case 0x0c0ca6deu: goto P_0c0ca6de;
case 0x0c0ca6e0u: goto P_0c0ca6e0;
case 0x0c0ca6e2u: goto P_0c0ca6e2;
case 0x0c0ca6e4u: goto P_0c0ca6e4;
case 0x0c0ca6e6u: goto P_0c0ca6e6;
case 0x0c0ca6e8u: goto P_0c0ca6e8;
case 0x0c0ca6eau: goto P_0c0ca6ea;
case 0x0c0ca6ecu: goto P_0c0ca6ec;
case 0x0c0ca6eeu: goto P_0c0ca6ee;
case 0x0c0ca6f0u: goto P_0c0ca6f0;
case 0x0c0ca6f2u: goto P_0c0ca6f2;
case 0x0c0ca6f4u: goto P_0c0ca6f4;
case 0x0c0ca6f6u: goto P_0c0ca6f6;
case 0x0c0ca6f8u: goto P_0c0ca6f8;
case 0x0c0ca6fau: goto P_0c0ca6fa;
case 0x0c0ca6fcu: goto P_0c0ca6fc;
case 0x0c0ca6feu: goto P_0c0ca6fe;
case 0x0c0ca700u: goto P_0c0ca700;
case 0x0c0ca702u: goto P_0c0ca702;
case 0x0c0ca704u: goto P_0c0ca704;
case 0x0c0ca706u: goto P_0c0ca706;
case 0x0c0ca708u: goto P_0c0ca708;
case 0x0c0ca70au: goto P_0c0ca70a;
case 0x0c0ca70cu: goto P_0c0ca70c;
case 0x0c0ca70eu: goto P_0c0ca70e;
case 0x0c0ca710u: goto P_0c0ca710;
case 0x0c0ca712u: goto P_0c0ca712;
case 0x0c0ca714u: goto P_0c0ca714;
case 0x0c0ca716u: goto P_0c0ca716;
case 0x0c0ca718u: goto P_0c0ca718;
case 0x0c0ca71au: goto P_0c0ca71a;
case 0x0c0ca71cu: goto P_0c0ca71c;
case 0x0c0ca71eu: goto P_0c0ca71e;
case 0x0c0ca720u: goto P_0c0ca720;
case 0x0c0ca722u: goto P_0c0ca722;
case 0x0c0ca724u: goto P_0c0ca724;
case 0x0c0ca726u: goto P_0c0ca726;
case 0x0c0ca728u: goto P_0c0ca728;
case 0x0c0ca72au: goto P_0c0ca72a;
case 0x0c0ca72cu: goto P_0c0ca72c;
case 0x0c0ca72eu: goto P_0c0ca72e;
case 0x0c0ca730u: goto P_0c0ca730;
case 0x0c0ca732u: goto P_0c0ca732;
case 0x0c0ca734u: goto P_0c0ca734;
case 0x0c0ca736u: goto P_0c0ca736;
case 0x0c0ca738u: goto P_0c0ca738;
case 0x0c0ca73au: goto P_0c0ca73a;
case 0x0c0ca73cu: goto P_0c0ca73c;
case 0x0c0ca73eu: goto P_0c0ca73e;
case 0x0c0ca740u: goto P_0c0ca740;
case 0x0c0ca742u: goto P_0c0ca742;
case 0x0c0ca744u: goto P_0c0ca744;
case 0x0c0ca746u: goto P_0c0ca746;
case 0x0c0ca748u: goto P_0c0ca748;
case 0x0c0ca74au: goto P_0c0ca74a;
case 0x0c0ca74cu: goto P_0c0ca74c;
case 0x0c0ca74eu: goto P_0c0ca74e;
case 0x0c0ca750u: goto P_0c0ca750;
case 0x0c0ca752u: goto P_0c0ca752;
case 0x0c0ca754u: goto P_0c0ca754;
case 0x0c0ca756u: goto P_0c0ca756;
case 0x0c0ca758u: goto P_0c0ca758;
case 0x0c0ca75au: goto P_0c0ca75a;
case 0x0c0ca75cu: goto P_0c0ca75c;
case 0x0c0ca75eu: goto P_0c0ca75e;
case 0x0c0ca760u: goto P_0c0ca760;
case 0x0c0ca762u: goto P_0c0ca762;
case 0x0c0ca764u: goto P_0c0ca764;
case 0x0c0ca766u: goto P_0c0ca766;
case 0x0c0ca768u: goto P_0c0ca768;
case 0x0c0ca76au: goto P_0c0ca76a;
case 0x0c0ca76cu: goto P_0c0ca76c;
case 0x0c0ca76eu: goto P_0c0ca76e;
case 0x0c0ca770u: goto P_0c0ca770;
case 0x0c0ca772u: goto P_0c0ca772;
case 0x0c0ca774u: goto P_0c0ca774;
case 0x0c0ca776u: goto P_0c0ca776;
case 0x0c0ca778u: goto P_0c0ca778;
case 0x0c0ca77au: goto P_0c0ca77a;
case 0x0c0ca77cu: goto P_0c0ca77c;
case 0x0c0ca77eu: goto P_0c0ca77e;
case 0x0c0ca780u: goto P_0c0ca780;
case 0x0c0ca782u: goto P_0c0ca782;
case 0x0c0ca784u: goto P_0c0ca784;
case 0x0c0ca786u: goto P_0c0ca786;
case 0x0c0ca788u: goto P_0c0ca788;
case 0x0c0ca78au: goto P_0c0ca78a;
case 0x0c0ca78cu: goto P_0c0ca78c;
case 0x0c0ca78eu: goto P_0c0ca78e;
case 0x0c0ca790u: goto P_0c0ca790;
case 0x0c0ca792u: goto P_0c0ca792;
case 0x0c0ca794u: goto P_0c0ca794;
case 0x0c0ca796u: goto P_0c0ca796;
case 0x0c0ca798u: goto P_0c0ca798;
case 0x0c0ca79au: goto P_0c0ca79a;
case 0x0c0ca79cu: goto P_0c0ca79c;
case 0x0c0ca79eu: goto P_0c0ca79e;
case 0x0c0ca7a0u: goto P_0c0ca7a0;
case 0x0c0ca7a2u: goto P_0c0ca7a2;
case 0x0c0ca7a4u: goto P_0c0ca7a4;
case 0x0c0ca7a6u: goto P_0c0ca7a6;
case 0x0c0ca7a8u: goto P_0c0ca7a8;
case 0x0c0ca7aau: goto P_0c0ca7aa;
case 0x0c0ca7acu: goto P_0c0ca7ac;
case 0x0c0ca7aeu: goto P_0c0ca7ae;
case 0x0c0ca7b0u: goto P_0c0ca7b0;
case 0x0c0ca7dcu: goto P_0c0ca7dc;
case 0x0c0ca7deu: goto P_0c0ca7de;
case 0x0c0ca7e0u: goto P_0c0ca7e0;
case 0x0c0ca7e2u: goto P_0c0ca7e2;
case 0x0c0ca7e4u: goto P_0c0ca7e4;
case 0x0c0ca7e6u: goto P_0c0ca7e6;
case 0x0c0ca7e8u: goto P_0c0ca7e8;
case 0x0c0ca7eau: goto P_0c0ca7ea;
case 0x0c0ca7ecu: goto P_0c0ca7ec;
case 0x0c0ca7eeu: goto P_0c0ca7ee;
case 0x0c0ca7f0u: goto P_0c0ca7f0;
case 0x0c0ca7f2u: goto P_0c0ca7f2;
case 0x0c0ca7f4u: goto P_0c0ca7f4;
case 0x0c0ca7f6u: goto P_0c0ca7f6;
case 0x0c0ca7f8u: goto P_0c0ca7f8;
case 0x0c0ca7fau: goto P_0c0ca7fa;
case 0x0c0ca7fcu: goto P_0c0ca7fc;
case 0x0c0ca7feu: goto P_0c0ca7fe;
case 0x0c0ca800u: goto P_0c0ca800;
case 0x0c0ca802u: goto P_0c0ca802;
case 0x0c0ca804u: goto P_0c0ca804;
case 0x0c0ca806u: goto P_0c0ca806;
case 0x0c0ca808u: goto P_0c0ca808;
case 0x0c0ca80au: goto P_0c0ca80a;
case 0x0c0ca80cu: goto P_0c0ca80c;
case 0x0c0ca80eu: goto P_0c0ca80e;
case 0x0c0ca810u: goto P_0c0ca810;
case 0x0c0ca812u: goto P_0c0ca812;
case 0x0c0ca814u: goto P_0c0ca814;
case 0x0c0ca816u: goto P_0c0ca816;
case 0x0c0ca818u: goto P_0c0ca818;
case 0x0c0ca81au: goto P_0c0ca81a;
case 0x0c0ca81cu: goto P_0c0ca81c;
case 0x0c0ca81eu: goto P_0c0ca81e;
case 0x0c0ca820u: goto P_0c0ca820;
case 0x0c0ca822u: goto P_0c0ca822;
case 0x0c0ca824u: goto P_0c0ca824;
case 0x0c0ca826u: goto P_0c0ca826;
case 0x0c0ca828u: goto P_0c0ca828;
case 0x0c0ca82au: goto P_0c0ca82a;
case 0x0c0ca82cu: goto P_0c0ca82c;
case 0x0c0ca82eu: goto P_0c0ca82e;
case 0x0c0ca830u: goto P_0c0ca830;
case 0x0c0ca832u: goto P_0c0ca832;
case 0x0c0ca834u: goto P_0c0ca834;
case 0x0c0ca836u: goto P_0c0ca836;
default: return vf3_matrix_family(target,s,ram);
}
P_0c0c7de8: /* original d54a, guest PC 0x0c0c7de8 */
if(!s->budget--) { s->failed_pc=0x0c0c7de8u; return 0; }
r[5]=read(ram,0x0c0c7f14u,4);
goto P_0c0c7dea;
P_0c0c7dea: /* original e01c, guest PC 0x0c0c7dea */
if(!s->budget--) { s->failed_pc=0x0c0c7deau; return 0; }
r[0]=0x0000001cu;
goto P_0c0c7dec;
P_0c0c7dec: /* original e30f, guest PC 0x0c0c7dec */
if(!s->budget--) { s->failed_pc=0x0c0c7decu; return 0; }
r[3]=0x0000000fu;
goto P_0c0c7dee;
P_0c0c7dee: /* original 9189, guest PC 0x0c0c7dee */
if(!s->budget--) { s->failed_pc=0x0c0c7deeu; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c7f04u,2);
goto P_0c0c7df0;
P_0c0c7df0: /* original 045c, guest PC 0x0c0c7df0 */
if(!s->budget--) { s->failed_pc=0x0c0c7df0u; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[5]+r[0],1);
goto P_0c0c7df2;
P_0c0c7df2: /* original d049, guest PC 0x0c0c7df2 */
if(!s->budget--) { s->failed_pc=0x0c0c7df2u; return 0; }
r[0]=read(ram,0x0c0c7f18u,4);
goto P_0c0c7df4;
P_0c0c7df4: /* original 315c, guest PC 0x0c0c7df4 */
if(!s->budget--) { s->failed_pc=0x0c0c7df4u; return 0; }
r[1]+=r[5];
goto P_0c0c7df6;
P_0c0c7df6: /* original 644c, guest PC 0x0c0c7df6 */
if(!s->budget--) { s->failed_pc=0x0c0c7df6u; return 0; }
r[4]=r[4]&255u;
goto P_0c0c7df8;
P_0c0c7df8: /* original 2439, guest PC 0x0c0c7df8 */
if(!s->budget--) { s->failed_pc=0x0c0c7df8u; return 0; }
r[4]&=r[3];
goto P_0c0c7dfa;
P_0c0c7dfa: /* original 024c, guest PC 0x0c0c7dfa */
if(!s->budget--) { s->failed_pc=0x0c0c7dfau; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c0c7dfc;
P_0c0c7dfc: /* original 000b, guest PC 0x0c0c7dfc */
if(!s->budget--) { s->failed_pc=0x0c0c7dfcu; return 0; }
target=r[16];
write(ram,r[1],r[2],1);
s->pc=target; return ram->oob==0;
P_0c0c7dfe: /* original 2120, guest PC 0x0c0c7dfe */
if(!s->budget--) { s->failed_pc=0x0c0c7dfeu; return 0; }
write(ram,r[1],r[2],1);
if(!vf3_matrix_family(0x0c0c7e00u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0c7e00u; return 0; } return 1;
P_0c0c7e1c: /* original 2fe6, guest PC 0x0c0c7e1c */
if(!s->budget--) { s->failed_pc=0x0c0c7e1cu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c7e1e;
P_0c0c7e1e: /* original e00c, guest PC 0x0c0c7e1e */
if(!s->budget--) { s->failed_pc=0x0c0c7e1eu; return 0; }
r[0]=0x0000000cu;
goto P_0c0c7e20;
P_0c0c7e20: /* original 2fd6, guest PC 0x0c0c7e20 */
if(!s->budget--) { s->failed_pc=0x0c0c7e20u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c7e22;
P_0c0c7e22: /* original 6d53, guest PC 0x0c0c7e22 */
if(!s->budget--) { s->failed_pc=0x0c0c7e22u; return 0; }
r[13]=r[5];
goto P_0c0c7e24;
P_0c0c7e24: /* original 2fc6, guest PC 0x0c0c7e24 */
if(!s->budget--) { s->failed_pc=0x0c0c7e24u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c7e26;
P_0c0c7e26: /* original 2fb6, guest PC 0x0c0c7e26 */
if(!s->budget--) { s->failed_pc=0x0c0c7e26u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c7e28;
P_0c0c7e28: /* original fffb, guest PC 0x0c0c7e28 */
if(!s->budget--) { s->failed_pc=0x0c0c7e28u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c0c7e2a;
P_0c0c7e2a: /* original 4f22, guest PC 0x0c0c7e2a */
if(!s->budget--) { s->failed_pc=0x0c0c7e2au; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0c7e2c;
P_0c0c7e2c: /* original 7fec, guest PC 0x0c0c7e2c */
if(!s->budget--) { s->failed_pc=0x0c0c7e2cu; return 0; }
r[15]+=0xffffffecu;
goto P_0c0c7e2e;
P_0c0c7e2e: /* original ff47, guest PC 0x0c0c7e2e */
if(!s->budget--) { s->failed_pc=0x0c0c7e2eu; return 0; }
vf3_matrix_store(s,ram,4,r[15]+r[0]);
goto P_0c0c7e30;
P_0c0c7e30: /* original e010, guest PC 0x0c0c7e30 */
if(!s->budget--) { s->failed_pc=0x0c0c7e30u; return 0; }
r[0]=0x00000010u;
goto P_0c0c7e32;
P_0c0c7e32: /* original ff67, guest PC 0x0c0c7e32 */
if(!s->budget--) { s->failed_pc=0x0c0c7e32u; return 0; }
vf3_matrix_store(s,ram,6,r[15]+r[0]);
goto P_0c0c7e34;
P_0c0c7e34: /* original 1f62, guest PC 0x0c0c7e34 */
if(!s->budget--) { s->failed_pc=0x0c0c7e34u; return 0; }
write(ram,r[15]+8,r[6],4);
goto P_0c0c7e36;
P_0c0c7e36: /* original dc37, guest PC 0x0c0c7e36 */
if(!s->budget--) { s->failed_pc=0x0c0c7e36u; return 0; }
r[12]=read(ram,0x0c0c7f14u,4);
goto P_0c0c7e38;
P_0c0c7e38: /* original bfd6, guest PC 0x0c0c7e38 */
if(!s->budget--) { s->failed_pc=0x0c0c7e38u; return 0; }
target=code_base|0x0c0c7de8u; r[16]=code_base|0x0c0c7e3cu;
r[14]=r[4];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c7e3cu) { target=s->pc; goto dispatch; }
goto P_0c0c7e3c;
P_0c0c7e3a: /* original 6e43, guest PC 0x0c0c7e3a */
if(!s->budget--) { s->failed_pc=0x0c0c7e3au; return 0; }
r[14]=r[4];
goto P_0c0c7e3c;
P_0c0c7e3c: /* original 60d3, guest PC 0x0c0c7e3c */
if(!s->budget--) { s->failed_pc=0x0c0c7e3cu; return 0; }
r[0]=r[13];
goto P_0c0c7e3e;
P_0c0c7e3e: /* original 80e4, guest PC 0x0c0c7e3e */
if(!s->budget--) { s->failed_pc=0x0c0c7e3eu; return 0; }
write(ram,r[14]+4,r[0],1);
goto P_0c0c7e40;
P_0c0c7e40: /* original e01c, guest PC 0x0c0c7e40 */
if(!s->budget--) { s->failed_pc=0x0c0c7e40u; return 0; }
r[0]=0x0000001cu;
goto P_0c0c7e42;
P_0c0c7e42: /* original d337, guest PC 0x0c0c7e42 */
if(!s->budget--) { s->failed_pc=0x0c0c7e42u; return 0; }
r[3]=read(ram,0x0c0c7f20u,4);
goto P_0c0c7e44;
P_0c0c7e44: /* original 04cc, guest PC 0x0c0c7e44 */
if(!s->budget--) { s->failed_pc=0x0c0c7e44u; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[12]+r[0],1);
goto P_0c0c7e46;
P_0c0c7e46: /* original e032, guest PC 0x0c0c7e46 */
if(!s->budget--) { s->failed_pc=0x0c0c7e46u; return 0; }
r[0]=0x00000032u;
goto P_0c0c7e48;
P_0c0c7e48: /* original 65f3, guest PC 0x0c0c7e48 */
if(!s->budget--) { s->failed_pc=0x0c0c7e48u; return 0; }
r[5]=r[15];
goto P_0c0c7e4a;
P_0c0c7e4a: /* original 7504, guest PC 0x0c0c7e4a */
if(!s->budget--) { s->failed_pc=0x0c0c7e4au; return 0; }
r[5]+=0x00000004u;
goto P_0c0c7e4c;
P_0c0c7e4c: /* original 644c, guest PC 0x0c0c7e4c */
if(!s->budget--) { s->failed_pc=0x0c0c7e4cu; return 0; }
r[4]=r[4]&255u;
goto P_0c0c7e4e;
P_0c0c7e4e: /* original 66f3, guest PC 0x0c0c7e4e */
if(!s->budget--) { s->failed_pc=0x0c0c7e4eu; return 0; }
r[6]=r[15];
goto P_0c0c7e50;
P_0c0c7e50: /* original 4408, guest PC 0x0c0c7e50 */
if(!s->budget--) { s->failed_pc=0x0c0c7e50u; return 0; }
r[4]<<=2;
goto P_0c0c7e52;
P_0c0c7e52: /* original 4408, guest PC 0x0c0c7e52 */
if(!s->budget--) { s->failed_pc=0x0c0c7e52u; return 0; }
r[4]<<=2;
goto P_0c0c7e54;
P_0c0c7e54: /* original 4408, guest PC 0x0c0c7e54 */
if(!s->budget--) { s->failed_pc=0x0c0c7e54u; return 0; }
r[4]<<=2;
goto P_0c0c7e56;
P_0c0c7e56: /* original 343c, guest PC 0x0c0c7e56 */
if(!s->budget--) { s->failed_pc=0x0c0c7e56u; return 0; }
r[4]+=r[3];
goto P_0c0c7e58;
P_0c0c7e58: /* original 0b4d, guest PC 0x0c0c7e58 */
if(!s->budget--) { s->failed_pc=0x0c0c7e58u; return 0; }
r[11]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c0c7e5a;
P_0c0c7e5a: /* original e028, guest PC 0x0c0c7e5a */
if(!s->budget--) { s->failed_pc=0x0c0c7e5au; return 0; }
r[0]=0x00000028u;
goto P_0c0c7e5c;
P_0c0c7e5c: /* original f446, guest PC 0x0c0c7e5c */
if(!s->budget--) { s->failed_pc=0x0c0c7e5cu; return 0; }
vf3_matrix_load(s,ram,4,r[4]+r[0]);
goto P_0c0c7e5e;
P_0c0c7e5e: /* original e00c, guest PC 0x0c0c7e5e */
if(!s->budget--) { s->failed_pc=0x0c0c7e5eu; return 0; }
r[0]=0x0000000cu;
goto P_0c0c7e60;
P_0c0c7e60: /* original f34c, guest PC 0x0c0c7e60 */
if(!s->budget--) { s->failed_pc=0x0c0c7e60u; return 0; }
vf3_matrix_move(s,3,4);
goto P_0c0c7e62;
P_0c0c7e62: /* original f4f6, guest PC 0x0c0c7e62 */
if(!s->budget--) { s->failed_pc=0x0c0c7e62u; return 0; }
vf3_matrix_load(s,ram,4,r[15]+r[0]);
goto P_0c0c7e64;
P_0c0c7e64: /* original e010, guest PC 0x0c0c7e64 */
if(!s->budget--) { s->failed_pc=0x0c0c7e64u; return 0; }
r[0]=0x00000010u;
goto P_0c0c7e66;
P_0c0c7e66: /* original f5f6, guest PC 0x0c0c7e66 */
if(!s->budget--) { s->failed_pc=0x0c0c7e66u; return 0; }
vf3_matrix_load(s,ram,5,r[15]+r[0]);
goto P_0c0c7e68;
P_0c0c7e68: /* original e004, guest PC 0x0c0c7e68 */
if(!s->budget--) { s->failed_pc=0x0c0c7e68u; return 0; }
r[0]=0x00000004u;
goto P_0c0c7e6a;
P_0c0c7e6a: /* original f430, guest PC 0x0c0c7e6a */
if(!s->budget--) { s->failed_pc=0x0c0c7e6au; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'+');
goto P_0c0c7e6c;
P_0c0c7e6c: /* original ff47, guest PC 0x0c0c7e6c */
if(!s->budget--) { s->failed_pc=0x0c0c7e6cu; return 0; }
vf3_matrix_store(s,ram,4,r[15]+r[0]);
goto P_0c0c7e6e;
P_0c0c7e6e: /* original ff5a, guest PC 0x0c0c7e6e */
if(!s->budget--) { s->failed_pc=0x0c0c7e6eu; return 0; }
vf3_matrix_store(s,ram,5,r[15]);
goto P_0c0c7e70;
P_0c0c7e70: /* original d22c, guest PC 0x0c0c7e70 */
if(!s->budget--) { s->failed_pc=0x0c0c7e70u; return 0; }
r[2]=read(ram,0x0c0c7f24u,4);
goto P_0c0c7e72;
P_0c0c7e72: /* original 420b, guest PC 0x0c0c7e72 */
if(!s->budget--) { s->failed_pc=0x0c0c7e72u; return 0; }
target=r[2];
r[16]=code_base|0x0c0c7e76u;
r[4]=r[11];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c7e76u) { target=s->pc; goto dispatch; }
goto P_0c0c7e76;
P_0c0c7e74: /* original 64b3, guest PC 0x0c0c7e74 */
if(!s->budget--) { s->failed_pc=0x0c0c7e74u; return 0; }
r[4]=r[11];
goto P_0c0c7e76;
P_0c0c7e76: /* original e004, guest PC 0x0c0c7e76 */
if(!s->budget--) { s->failed_pc=0x0c0c7e76u; return 0; }
r[0]=0x00000004u;
goto P_0c0c7e78;
P_0c0c7e78: /* original fff8, guest PC 0x0c0c7e78 */
if(!s->budget--) { s->failed_pc=0x0c0c7e78u; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
goto P_0c0c7e7a;
P_0c0c7e7a: /* original f4f6, guest PC 0x0c0c7e7a */
if(!s->budget--) { s->failed_pc=0x0c0c7e7au; return 0; }
vf3_matrix_load(s,ram,4,r[15]+r[0]);
goto P_0c0c7e7c;
P_0c0c7e7c: /* original e010, guest PC 0x0c0c7e7c */
if(!s->budget--) { s->failed_pc=0x0c0c7e7cu; return 0; }
r[0]=0x00000010u;
goto P_0c0c7e7e;
P_0c0c7e7e: /* original 54f2, guest PC 0x0c0c7e7e */
if(!s->budget--) { s->failed_pc=0x0c0c7e7eu; return 0; }
r[4]=read(ram,r[15]+8,4);
goto P_0c0c7e80;
P_0c0c7e80: /* original fe47, guest PC 0x0c0c7e80 */
if(!s->budget--) { s->failed_pc=0x0c0c7e80u; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c0c7e82;
P_0c0c7e82: /* original e018, guest PC 0x0c0c7e82 */
if(!s->budget--) { s->failed_pc=0x0c0c7e82u; return 0; }
r[0]=0x00000018u;
goto P_0c0c7e84;
P_0c0c7e84: /* original fef7, guest PC 0x0c0c7e84 */
if(!s->budget--) { s->failed_pc=0x0c0c7e84u; return 0; }
vf3_matrix_store(s,ram,15,r[14]+r[0]);
goto P_0c0c7e86;
P_0c0c7e86: /* original 34bc, guest PC 0x0c0c7e86 */
if(!s->budget--) { s->failed_pc=0x0c0c7e86u; return 0; }
r[4]+=r[11];
goto P_0c0c7e88;
P_0c0c7e88: /* original 903d, guest PC 0x0c0c7e88 */
if(!s->budget--) { s->failed_pc=0x0c0c7e88u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c7f06u,2);
goto P_0c0c7e8a;
P_0c0c7e8a: /* original fe47, guest PC 0x0c0c7e8a */
if(!s->budget--) { s->failed_pc=0x0c0c7e8au; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c0c7e8c;
P_0c0c7e8c: /* original 7008, guest PC 0x0c0c7e8c */
if(!s->budget--) { s->failed_pc=0x0c0c7e8cu; return 0; }
r[0]+=0x00000008u;
goto P_0c0c7e8e;
P_0c0c7e8e: /* original fef7, guest PC 0x0c0c7e8e */
if(!s->budget--) { s->failed_pc=0x0c0c7e8eu; return 0; }
vf3_matrix_store(s,ram,15,r[14]+r[0]);
goto P_0c0c7e90;
P_0c0c7e90: /* original 6043, guest PC 0x0c0c7e90 */
if(!s->budget--) { s->failed_pc=0x0c0c7e90u; return 0; }
r[0]=r[4];
goto P_0c0c7e92;
P_0c0c7e92: /* original 81ef, guest PC 0x0c0c7e92 */
if(!s->budget--) { s->failed_pc=0x0c0c7e92u; return 0; }
write(ram,r[14]+30,r[0],2);
goto P_0c0c7e94;
P_0c0c7e94: /* original d324, guest PC 0x0c0c7e94 */
if(!s->budget--) { s->failed_pc=0x0c0c7e94u; return 0; }
r[3]=read(ram,0x0c0c7f28u,4);
goto P_0c0c7e96;
P_0c0c7e96: /* original f5fc, guest PC 0x0c0c7e96 */
if(!s->budget--) { s->failed_pc=0x0c0c7e96u; return 0; }
vf3_matrix_move(s,5,15);
goto P_0c0c7e98;
P_0c0c7e98: /* original 430b, guest PC 0x0c0c7e98 */
if(!s->budget--) { s->failed_pc=0x0c0c7e98u; return 0; }
target=r[3];
r[16]=code_base|0x0c0c7e9cu;
fr[5]^=0x80000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c7e9cu) { target=s->pc; goto dispatch; }
goto P_0c0c7e9c;
P_0c0c7e9a: /* original f54d, guest PC 0x0c0c7e9a */
if(!s->budget--) { s->failed_pc=0x0c0c7e9au; return 0; }
fr[5]^=0x80000000u;
goto P_0c0c7e9c;
P_0c0c7e9c: /* original e014, guest PC 0x0c0c7e9c */
if(!s->budget--) { s->failed_pc=0x0c0c7e9cu; return 0; }
r[0]=0x00000014u;
goto P_0c0c7e9e;
P_0c0c7e9e: /* original f40c, guest PC 0x0c0c7e9e */
if(!s->budget--) { s->failed_pc=0x0c0c7e9eu; return 0; }
vf3_matrix_move(s,4,0);
goto P_0c0c7ea0;
P_0c0c7ea0: /* original fe47, guest PC 0x0c0c7ea0 */
if(!s->budget--) { s->failed_pc=0x0c0c7ea0u; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c0c7ea2;
P_0c0c7ea2: /* original e30d, guest PC 0x0c0c7ea2 */
if(!s->budget--) { s->failed_pc=0x0c0c7ea2u; return 0; }
r[3]=0x0000000du;
goto P_0c0c7ea4;
P_0c0c7ea4: /* original 9030, guest PC 0x0c0c7ea4 */
if(!s->budget--) { s->failed_pc=0x0c0c7ea4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c7f08u,2);
goto P_0c0c7ea6;
P_0c0c7ea6: /* original fe47, guest PC 0x0c0c7ea6 */
if(!s->budget--) { s->failed_pc=0x0c0c7ea6u; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c0c7ea8;
P_0c0c7ea8: /* original e060, guest PC 0x0c0c7ea8 */
if(!s->budget--) { s->failed_pc=0x0c0c7ea8u; return 0; }
r[0]=0x00000060u;
goto P_0c0c7eaa;
P_0c0c7eaa: /* original 04ec, guest PC 0x0c0c7eaa */
if(!s->budget--) { s->failed_pc=0x0c0c7eaau; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0c7eac;
P_0c0c7eac: /* original 644c, guest PC 0x0c0c7eac */
if(!s->budget--) { s->failed_pc=0x0c0c7eacu; return 0; }
r[4]=r[4]&255u;
goto P_0c0c7eae;
P_0c0c7eae: /* original 3433, guest PC 0x0c0c7eae */
if(!s->budget--) { s->failed_pc=0x0c0c7eaeu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=(int32_t)r[3])!=0);
goto P_0c0c7eb0;
P_0c0c7eb0: /* original 8f01, guest PC 0x0c0c7eb0 */
if(!s->budget--) { s->failed_pc=0x0c0c7eb0u; return 0; }
cond=r[17]&1u;
r[0]=0x00000061u;
if(!cond) { goto P_0c0c7eb6; }
goto P_0c0c7eb4;
P_0c0c7eb2: /* original e061, guest PC 0x0c0c7eb2 */
if(!s->budget--) { s->failed_pc=0x0c0c7eb2u; return 0; }
r[0]=0x00000061u;
goto P_0c0c7eb4;
P_0c0c7eb4: /* original 74f3, guest PC 0x0c0c7eb4 */
if(!s->budget--) { s->failed_pc=0x0c0c7eb4u; return 0; }
r[4]+=0xfffffff3u;
goto P_0c0c7eb6;
P_0c0c7eb6: /* original 634b, guest PC 0x0c0c7eb6 */
if(!s->budget--) { s->failed_pc=0x0c0c7eb6u; return 0; }
r[3]=0u-r[4];
goto P_0c0c7eb8;
P_0c0c7eb8: /* original 0e44, guest PC 0x0c0c7eb8 */
if(!s->budget--) { s->failed_pc=0x0c0c7eb8u; return 0; }
write(ram,r[14]+r[0],r[4],1);
goto P_0c0c7eba;
P_0c0c7eba: /* original d41c, guest PC 0x0c0c7eba */
if(!s->budget--) { s->failed_pc=0x0c0c7ebau; return 0; }
r[4]=read(ram,0x0c0c7f2cu,4);
goto P_0c0c7ebc;
P_0c0c7ebc: /* original 9025, guest PC 0x0c0c7ebc */
if(!s->budget--) { s->failed_pc=0x0c0c7ebcu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c7f0au,2);
goto P_0c0c7ebe;
P_0c0c7ebe: /* original 443d, guest PC 0x0c0c7ebe */
if(!s->budget--) { s->failed_pc=0x0c0c7ebeu; return 0; }
r[4]=(r[3]&0x80000000u)?((r[3]&31u)?r[4]>>((-r[3])&31u):0):r[4]<<(r[3]&31u);
goto P_0c0c7ec0;
P_0c0c7ec0: /* original 0e46, guest PC 0x0c0c7ec0 */
if(!s->budget--) { s->failed_pc=0x0c0c7ec0u; return 0; }
write(ram,r[14]+r[0],r[4],4);
goto P_0c0c7ec2;
P_0c0c7ec2: /* original e400, guest PC 0x0c0c7ec2 */
if(!s->budget--) { s->failed_pc=0x0c0c7ec2u; return 0; }
r[4]=0x00000000u;
goto P_0c0c7ec4;
P_0c0c7ec4: /* original e022, guest PC 0x0c0c7ec4 */
if(!s->budget--) { s->failed_pc=0x0c0c7ec4u; return 0; }
r[0]=0x00000022u;
goto P_0c0c7ec6;
P_0c0c7ec6: /* original d31a, guest PC 0x0c0c7ec6 */
if(!s->budget--) { s->failed_pc=0x0c0c7ec6u; return 0; }
r[3]=read(ram,0x0c0c7f30u,4);
goto P_0c0c7ec8;
P_0c0c7ec8: /* original 1e33, guest PC 0x0c0c7ec8 */
if(!s->budget--) { s->failed_pc=0x0c0c7ec8u; return 0; }
write(ram,r[14]+12,r[3],4);
goto P_0c0c7eca;
P_0c0c7eca: /* original 0e44, guest PC 0x0c0c7eca */
if(!s->budget--) { s->failed_pc=0x0c0c7ecau; return 0; }
write(ram,r[14]+r[0],r[4],1);
goto P_0c0c7ecc;
P_0c0c7ecc: /* original 901e, guest PC 0x0c0c7ecc */
if(!s->budget--) { s->failed_pc=0x0c0c7eccu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c7f0cu,2);
goto P_0c0c7ece;
P_0c0c7ece: /* original 0e46, guest PC 0x0c0c7ece */
if(!s->budget--) { s->failed_pc=0x0c0c7eceu; return 0; }
write(ram,r[14]+r[0],r[4],4);
goto P_0c0c7ed0;
P_0c0c7ed0: /* original 700c, guest PC 0x0c0c7ed0 */
if(!s->budget--) { s->failed_pc=0x0c0c7ed0u; return 0; }
r[0]+=0x0000000cu;
goto P_0c0c7ed2;
P_0c0c7ed2: /* original 0e46, guest PC 0x0c0c7ed2 */
if(!s->budget--) { s->failed_pc=0x0c0c7ed2u; return 0; }
write(ram,r[14]+r[0],r[4],4);
goto P_0c0c7ed4;
P_0c0c7ed4: /* original 901b, guest PC 0x0c0c7ed4 */
if(!s->budget--) { s->failed_pc=0x0c0c7ed4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c7f0eu,2);
goto P_0c0c7ed6;
P_0c0c7ed6: /* original 0e46, guest PC 0x0c0c7ed6 */
if(!s->budget--) { s->failed_pc=0x0c0c7ed6u; return 0; }
write(ram,r[14]+r[0],r[4],4);
goto P_0c0c7ed8;
P_0c0c7ed8: /* original 700c, guest PC 0x0c0c7ed8 */
if(!s->budget--) { s->failed_pc=0x0c0c7ed8u; return 0; }
r[0]+=0x0000000cu;
goto P_0c0c7eda;
P_0c0c7eda: /* original 0e46, guest PC 0x0c0c7eda */
if(!s->budget--) { s->failed_pc=0x0c0c7edau; return 0; }
write(ram,r[14]+r[0],r[4],4);
goto P_0c0c7edc;
P_0c0c7edc: /* original 9018, guest PC 0x0c0c7edc */
if(!s->budget--) { s->failed_pc=0x0c0c7edcu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c7f10u,2);
goto P_0c0c7ede;
P_0c0c7ede: /* original 0e44, guest PC 0x0c0c7ede */
if(!s->budget--) { s->failed_pc=0x0c0c7edeu; return 0; }
write(ram,r[14]+r[0],r[4],1);
goto P_0c0c7ee0;
P_0c0c7ee0: /* original e401, guest PC 0x0c0c7ee0 */
if(!s->budget--) { s->failed_pc=0x0c0c7ee0u; return 0; }
r[4]=0x00000001u;
goto P_0c0c7ee2;
P_0c0c7ee2: /* original 60e2, guest PC 0x0c0c7ee2 */
if(!s->budget--) { s->failed_pc=0x0c0c7ee2u; return 0; }
tmp=read(ram,r[14],4);
r[0]=tmp;
goto P_0c0c7ee4;
P_0c0c7ee4: /* original d313, guest PC 0x0c0c7ee4 */
if(!s->budget--) { s->failed_pc=0x0c0c7ee4u; return 0; }
r[3]=read(ram,0x0c0c7f34u,4);
goto P_0c0c7ee6;
P_0c0c7ee6: /* original 2039, guest PC 0x0c0c7ee6 */
if(!s->budget--) { s->failed_pc=0x0c0c7ee6u; return 0; }
r[0]&=r[3];
goto P_0c0c7ee8;
P_0c0c7ee8: /* original 240b, guest PC 0x0c0c7ee8 */
if(!s->budget--) { s->failed_pc=0x0c0c7ee8u; return 0; }
r[4]|=r[0];
goto P_0c0c7eea;
P_0c0c7eea: /* original 2e42, guest PC 0x0c0c7eea */
if(!s->budget--) { s->failed_pc=0x0c0c7eeau; return 0; }
write(ram,r[14],r[4],4);
goto P_0c0c7eec;
P_0c0c7eec: /* original d212, guest PC 0x0c0c7eec */
if(!s->budget--) { s->failed_pc=0x0c0c7eecu; return 0; }
r[2]=read(ram,0x0c0c7f38u,4);
goto P_0c0c7eee;
P_0c0c7eee: /* original 420b, guest PC 0x0c0c7eee */
if(!s->budget--) { s->failed_pc=0x0c0c7eeeu; return 0; }
target=r[2];
r[16]=code_base|0x0c0c7ef2u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c7ef2u) { target=s->pc; goto dispatch; }
goto P_0c0c7ef2;
P_0c0c7ef0: /* original 64e3, guest PC 0x0c0c7ef0 */
if(!s->budget--) { s->failed_pc=0x0c0c7ef0u; return 0; }
r[4]=r[14];
goto P_0c0c7ef2;
P_0c0c7ef2: /* original 62c2, guest PC 0x0c0c7ef2 */
if(!s->budget--) { s->failed_pc=0x0c0c7ef2u; return 0; }
tmp=read(ram,r[12],4);
r[2]=tmp;
goto P_0c0c7ef4;
P_0c0c7ef4: /* original d311, guest PC 0x0c0c7ef4 */
if(!s->budget--) { s->failed_pc=0x0c0c7ef4u; return 0; }
r[3]=read(ram,0x0c0c7f3cu,4);
goto P_0c0c7ef6;
P_0c0c7ef6: /* original 2238, guest PC 0x0c0c7ef6 */
if(!s->budget--) { s->failed_pc=0x0c0c7ef6u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c0c7ef8;
P_0c0c7ef8: /* original 8924, guest PC 0x0c0c7ef8 */
if(!s->budget--) { s->failed_pc=0x0c0c7ef8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c7f44; }
goto P_0c0c7efa;
P_0c0c7efa: /* original d211, guest PC 0x0c0c7efa */
if(!s->budget--) { s->failed_pc=0x0c0c7efau; return 0; }
r[2]=read(ram,0x0c0c7f40u,4);
goto P_0c0c7efc;
P_0c0c7efc: /* original 420b, guest PC 0x0c0c7efc */
if(!s->budget--) { s->failed_pc=0x0c0c7efcu; return 0; }
target=r[2];
r[16]=code_base|0x0c0c7f00u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c7f00u) { target=s->pc; goto dispatch; }
goto P_0c0c7f00;
P_0c0c7efe: /* original 64e3, guest PC 0x0c0c7efe */
if(!s->budget--) { s->failed_pc=0x0c0c7efeu; return 0; }
r[4]=r[14];
goto P_0c0c7f00;
P_0c0c7f00: /* original a02a, guest PC 0x0c0c7f00 */
if(!s->budget--) { s->failed_pc=0x0c0c7f00u; return 0; }
goto P_0c0c7f58;
P_0c0c7f02: /* original 0009, guest PC 0x0c0c7f02 */
if(!s->budget--) { s->failed_pc=0x0c0c7f02u; return 0; }
if(!vf3_matrix_family(0x0c0c7f04u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0c7f04u; return 0; } return 1;
P_0c0c7f44: /* original e060, guest PC 0x0c0c7f44 */
if(!s->budget--) { s->failed_pc=0x0c0c7f44u; return 0; }
r[0]=0x00000060u;
goto P_0c0c7f46;
P_0c0c7f46: /* original d247, guest PC 0x0c0c7f46 */
if(!s->budget--) { s->failed_pc=0x0c0c7f46u; return 0; }
r[2]=read(ram,0x0c0c8064u,4);
goto P_0c0c7f48;
P_0c0c7f48: /* original 05ec, guest PC 0x0c0c7f48 */
if(!s->budget--) { s->failed_pc=0x0c0c7f48u; return 0; }
r[5]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0c7f4a;
P_0c0c7f4a: /* original 84e4, guest PC 0x0c0c7f4a */
if(!s->budget--) { s->failed_pc=0x0c0c7f4au; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+4,1);
goto P_0c0c7f4c;
P_0c0c7f4c: /* original 655c, guest PC 0x0c0c7f4c */
if(!s->budget--) { s->failed_pc=0x0c0c7f4cu; return 0; }
r[5]=r[5]&255u;
goto P_0c0c7f4e;
P_0c0c7f4e: /* original 420b, guest PC 0x0c0c7f4e */
if(!s->budget--) { s->failed_pc=0x0c0c7f4eu; return 0; }
target=r[2];
r[16]=code_base|0x0c0c7f52u;
r[4]=r[0]&255u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c7f52u) { target=s->pc; goto dispatch; }
goto P_0c0c7f52;
P_0c0c7f50: /* original 640c, guest PC 0x0c0c7f50 */
if(!s->budget--) { s->failed_pc=0x0c0c7f50u; return 0; }
r[4]=r[0]&255u;
goto P_0c0c7f52;
P_0c0c7f52: /* original d345, guest PC 0x0c0c7f52 */
if(!s->budget--) { s->failed_pc=0x0c0c7f52u; return 0; }
r[3]=read(ram,0x0c0c8068u,4);
goto P_0c0c7f54;
P_0c0c7f54: /* original 430b, guest PC 0x0c0c7f54 */
if(!s->budget--) { s->failed_pc=0x0c0c7f54u; return 0; }
target=r[3];
r[16]=code_base|0x0c0c7f58u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c7f58u) { target=s->pc; goto dispatch; }
goto P_0c0c7f58;
P_0c0c7f56: /* original 64e3, guest PC 0x0c0c7f56 */
if(!s->budget--) { s->failed_pc=0x0c0c7f56u; return 0; }
r[4]=r[14];
goto P_0c0c7f58;
P_0c0c7f58: /* original e060, guest PC 0x0c0c7f58 */
if(!s->budget--) { s->failed_pc=0x0c0c7f58u; return 0; }
r[0]=0x00000060u;
goto P_0c0c7f5a;
P_0c0c7f5a: /* original 02ec, guest PC 0x0c0c7f5a */
if(!s->budget--) { s->failed_pc=0x0c0c7f5au; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0c7f5c;
P_0c0c7f5c: /* original 907e, guest PC 0x0c0c7f5c */
if(!s->budget--) { s->failed_pc=0x0c0c7f5cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c805cu,2);
goto P_0c0c7f5e;
P_0c0c7f5e: /* original 0e24, guest PC 0x0c0c7f5e */
if(!s->budget--) { s->failed_pc=0x0c0c7f5eu; return 0; }
write(ram,r[14]+r[0],r[2],1);
goto P_0c0c7f60;
P_0c0c7f60: /* original d342, guest PC 0x0c0c7f60 */
if(!s->budget--) { s->failed_pc=0x0c0c7f60u; return 0; }
r[3]=read(ram,0x0c0c806cu,4);
goto P_0c0c7f62;
P_0c0c7f62: /* original 61c2, guest PC 0x0c0c7f62 */
if(!s->budget--) { s->failed_pc=0x0c0c7f62u; return 0; }
tmp=read(ram,r[12],4);
r[1]=tmp;
goto P_0c0c7f64;
P_0c0c7f64: /* original 2138, guest PC 0x0c0c7f64 */
if(!s->budget--) { s->failed_pc=0x0c0c7f64u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[3])==0)!=0);
goto P_0c0c7f66;
P_0c0c7f66: /* original 8904, guest PC 0x0c0c7f66 */
if(!s->budget--) { s->failed_pc=0x0c0c7f66u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c7f72; }
goto P_0c0c7f68;
P_0c0c7f68: /* original d241, guest PC 0x0c0c7f68 */
if(!s->budget--) { s->failed_pc=0x0c0c7f68u; return 0; }
r[2]=read(ram,0x0c0c8070u,4);
goto P_0c0c7f6a;
P_0c0c7f6a: /* original 420b, guest PC 0x0c0c7f6a */
if(!s->budget--) { s->failed_pc=0x0c0c7f6au; return 0; }
target=r[2];
r[16]=code_base|0x0c0c7f6eu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c7f6eu) { target=s->pc; goto dispatch; }
goto P_0c0c7f6e;
P_0c0c7f6c: /* original 0009, guest PC 0x0c0c7f6c */
if(!s->budget--) { s->failed_pc=0x0c0c7f6cu; return 0; }
goto P_0c0c7f6e;
P_0c0c7f6e: /* original a006, guest PC 0x0c0c7f6e */
if(!s->budget--) { s->failed_pc=0x0c0c7f6eu; return 0; }
goto P_0c0c7f7e;
P_0c0c7f70: /* original 0009, guest PC 0x0c0c7f70 */
if(!s->budget--) { s->failed_pc=0x0c0c7f70u; return 0; }
goto P_0c0c7f72;
P_0c0c7f72: /* original 60d3, guest PC 0x0c0c7f72 */
if(!s->budget--) { s->failed_pc=0x0c0c7f72u; return 0; }
r[0]=r[13];
goto P_0c0c7f74;
P_0c0c7f74: /* original 8801, guest PC 0x0c0c7f74 */
if(!s->budget--) { s->failed_pc=0x0c0c7f74u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c0c7f76;
P_0c0c7f76: /* original 8b02, guest PC 0x0c0c7f76 */
if(!s->budget--) { s->failed_pc=0x0c0c7f76u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c7f7e; }
goto P_0c0c7f78;
P_0c0c7f78: /* original d13e, guest PC 0x0c0c7f78 */
if(!s->budget--) { s->failed_pc=0x0c0c7f78u; return 0; }
r[1]=read(ram,0x0c0c8074u,4);
goto P_0c0c7f7a;
P_0c0c7f7a: /* original 410b, guest PC 0x0c0c7f7a */
if(!s->budget--) { s->failed_pc=0x0c0c7f7au; return 0; }
target=r[1];
r[16]=code_base|0x0c0c7f7eu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c7f7eu) { target=s->pc; goto dispatch; }
goto P_0c0c7f7e;
P_0c0c7f7c: /* original 0009, guest PC 0x0c0c7f7c */
if(!s->budget--) { s->failed_pc=0x0c0c7f7cu; return 0; }
goto P_0c0c7f7e;
P_0c0c7f7e: /* original d33e, guest PC 0x0c0c7f7e */
if(!s->budget--) { s->failed_pc=0x0c0c7f7eu; return 0; }
r[3]=read(ram,0x0c0c8078u,4);
goto P_0c0c7f80;
P_0c0c7f80: /* original 430b, guest PC 0x0c0c7f80 */
if(!s->budget--) { s->failed_pc=0x0c0c7f80u; return 0; }
target=r[3];
r[16]=code_base|0x0c0c7f84u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c7f84u) { target=s->pc; goto dispatch; }
goto P_0c0c7f84;
P_0c0c7f82: /* original 64e3, guest PC 0x0c0c7f82 */
if(!s->budget--) { s->failed_pc=0x0c0c7f82u; return 0; }
r[4]=r[14];
goto P_0c0c7f84;
P_0c0c7f84: /* original d23d, guest PC 0x0c0c7f84 */
if(!s->budget--) { s->failed_pc=0x0c0c7f84u; return 0; }
r[2]=read(ram,0x0c0c807cu,4);
goto P_0c0c7f86;
P_0c0c7f86: /* original 420b, guest PC 0x0c0c7f86 */
if(!s->budget--) { s->failed_pc=0x0c0c7f86u; return 0; }
target=r[2];
r[16]=code_base|0x0c0c7f8au;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c7f8au) { target=s->pc; goto dispatch; }
goto P_0c0c7f8a;
P_0c0c7f88: /* original 0009, guest PC 0x0c0c7f88 */
if(!s->budget--) { s->failed_pc=0x0c0c7f88u; return 0; }
goto P_0c0c7f8a;
P_0c0c7f8a: /* original 2dd8, guest PC 0x0c0c7f8a */
if(!s->budget--) { s->failed_pc=0x0c0c7f8au; return 0; }
r[17]=(r[17]&~1u)|(((r[13]&r[13])==0)!=0);
goto P_0c0c7f8c;
P_0c0c7f8c: /* original 8b06, guest PC 0x0c0c7f8c */
if(!s->budget--) { s->failed_pc=0x0c0c7f8cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c7f9c; }
goto P_0c0c7f8e;
P_0c0c7f8e: /* original d33e, guest PC 0x0c0c7f8e */
if(!s->budget--) { s->failed_pc=0x0c0c7f8eu; return 0; }
r[3]=read(ram,0x0c0c8088u,4);
goto P_0c0c7f90;
P_0c0c7f90: /* original d23c, guest PC 0x0c0c7f90 */
if(!s->budget--) { s->failed_pc=0x0c0c7f90u; return 0; }
r[2]=read(ram,0x0c0c8084u,4);
goto P_0c0c7f92;
P_0c0c7f92: /* original d53b, guest PC 0x0c0c7f92 */
if(!s->budget--) { s->failed_pc=0x0c0c7f92u; return 0; }
r[5]=read(ram,0x0c0c8080u,4);
goto P_0c0c7f94;
P_0c0c7f94: /* original 430b, guest PC 0x0c0c7f94 */
if(!s->budget--) { s->failed_pc=0x0c0c7f94u; return 0; }
target=r[3];
r[16]=code_base|0x0c0c7f98u;
tmp=read(ram,r[2],4);
r[4]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c7f98u) { target=s->pc; goto dispatch; }
goto P_0c0c7f98;
P_0c0c7f96: /* original 6422, guest PC 0x0c0c7f96 */
if(!s->budget--) { s->failed_pc=0x0c0c7f96u; return 0; }
tmp=read(ram,r[2],4);
r[4]=tmp;
goto P_0c0c7f98;
P_0c0c7f98: /* original a005, guest PC 0x0c0c7f98 */
if(!s->budget--) { s->failed_pc=0x0c0c7f98u; return 0; }
goto P_0c0c7fa6;
P_0c0c7f9a: /* original 0009, guest PC 0x0c0c7f9a */
if(!s->budget--) { s->failed_pc=0x0c0c7f9au; return 0; }
goto P_0c0c7f9c;
P_0c0c7f9c: /* original d23a, guest PC 0x0c0c7f9c */
if(!s->budget--) { s->failed_pc=0x0c0c7f9cu; return 0; }
r[2]=read(ram,0x0c0c8088u,4);
goto P_0c0c7f9e;
P_0c0c7f9e: /* original d33b, guest PC 0x0c0c7f9e */
if(!s->budget--) { s->failed_pc=0x0c0c7f9eu; return 0; }
r[3]=read(ram,0x0c0c808cu,4);
goto P_0c0c7fa0;
P_0c0c7fa0: /* original d537, guest PC 0x0c0c7fa0 */
if(!s->budget--) { s->failed_pc=0x0c0c7fa0u; return 0; }
r[5]=read(ram,0x0c0c8080u,4);
goto P_0c0c7fa2;
P_0c0c7fa2: /* original 420b, guest PC 0x0c0c7fa2 */
if(!s->budget--) { s->failed_pc=0x0c0c7fa2u; return 0; }
target=r[2];
r[16]=code_base|0x0c0c7fa6u;
tmp=read(ram,r[3],4);
r[4]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c7fa6u) { target=s->pc; goto dispatch; }
goto P_0c0c7fa6;
P_0c0c7fa4: /* original 6432, guest PC 0x0c0c7fa4 */
if(!s->budget--) { s->failed_pc=0x0c0c7fa4u; return 0; }
tmp=read(ram,r[3],4);
r[4]=tmp;
goto P_0c0c7fa6;
P_0c0c7fa6: /* original 7f14, guest PC 0x0c0c7fa6 */
if(!s->budget--) { s->failed_pc=0x0c0c7fa6u; return 0; }
r[15]+=0x00000014u;
goto P_0c0c7fa8;
P_0c0c7fa8: /* original 4f26, guest PC 0x0c0c7fa8 */
if(!s->budget--) { s->failed_pc=0x0c0c7fa8u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0c7faa;
P_0c0c7faa: /* original fff9, guest PC 0x0c0c7faa */
if(!s->budget--) { s->failed_pc=0x0c0c7faau; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0c7fac;
P_0c0c7fac: /* original 6bf6, guest PC 0x0c0c7fac */
if(!s->budget--) { s->failed_pc=0x0c0c7facu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0c7fae;
P_0c0c7fae: /* original 6cf6, guest PC 0x0c0c7fae */
if(!s->budget--) { s->failed_pc=0x0c0c7faeu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0c7fb0;
P_0c0c7fb0: /* original 6df6, guest PC 0x0c0c7fb0 */
if(!s->budget--) { s->failed_pc=0x0c0c7fb0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0c7fb2;
P_0c0c7fb2: /* original 000b, guest PC 0x0c0c7fb2 */
if(!s->budget--) { s->failed_pc=0x0c0c7fb2u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0c7fb4: /* original 6ef6, guest PC 0x0c0c7fb4 */
if(!s->budget--) { s->failed_pc=0x0c0c7fb4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0c7fb6u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0c7fb6u; return 0; } return 1;
P_0c0ca6c6: /* original 2fe6, guest PC 0x0c0ca6c6 */
if(!s->budget--) { s->failed_pc=0x0c0ca6c6u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0ca6c8;
P_0c0ca6c8: /* original 6e43, guest PC 0x0c0ca6c8 */
if(!s->budget--) { s->failed_pc=0x0c0ca6c8u; return 0; }
r[14]=r[4];
goto P_0c0ca6ca;
P_0c0ca6ca: /* original 2fd6, guest PC 0x0c0ca6ca */
if(!s->budget--) { s->failed_pc=0x0c0ca6cau; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0ca6cc;
P_0c0ca6cc: /* original 2fc6, guest PC 0x0c0ca6cc */
if(!s->budget--) { s->failed_pc=0x0c0ca6ccu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0ca6ce;
P_0c0ca6ce: /* original 2fb6, guest PC 0x0c0ca6ce */
if(!s->budget--) { s->failed_pc=0x0c0ca6ceu; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0ca6d0;
P_0c0ca6d0: /* original 2fa6, guest PC 0x0c0ca6d0 */
if(!s->budget--) { s->failed_pc=0x0c0ca6d0u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0ca6d2;
P_0c0ca6d2: /* original 2f96, guest PC 0x0c0ca6d2 */
if(!s->budget--) { s->failed_pc=0x0c0ca6d2u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0ca6d4;
P_0c0ca6d4: /* original 2f86, guest PC 0x0c0ca6d4 */
if(!s->budget--) { s->failed_pc=0x0c0ca6d4u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0ca6d6;
P_0c0ca6d6: /* original fffb, guest PC 0x0c0ca6d6 */
if(!s->budget--) { s->failed_pc=0x0c0ca6d6u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c0ca6d8;
P_0c0ca6d8: /* original ffeb, guest PC 0x0c0ca6d8 */
if(!s->budget--) { s->failed_pc=0x0c0ca6d8u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,14,r[15]);
goto P_0c0ca6da;
P_0c0ca6da: /* original ffdb, guest PC 0x0c0ca6da */
if(!s->budget--) { s->failed_pc=0x0c0ca6dau; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,13,r[15]);
goto P_0c0ca6dc;
P_0c0ca6dc: /* original ffcb, guest PC 0x0c0ca6dc */
if(!s->budget--) { s->failed_pc=0x0c0ca6dcu; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,12,r[15]);
goto P_0c0ca6de;
P_0c0ca6de: /* original 4f22, guest PC 0x0c0ca6de */
if(!s->budget--) { s->failed_pc=0x0c0ca6deu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0ca6e0;
P_0c0ca6e0: /* original 9067, guest PC 0x0c0ca6e0 */
if(!s->budget--) { s->failed_pc=0x0c0ca6e0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ca7b2u,2);
goto P_0c0ca6e2;
P_0c0ca6e2: /* original db37, guest PC 0x0c0ca6e2 */
if(!s->budget--) { s->failed_pc=0x0c0ca6e2u; return 0; }
r[11]=read(ram,0x0c0ca7c0u,4);
goto P_0c0ca6e4;
P_0c0ca6e4: /* original 7ff0, guest PC 0x0c0ca6e4 */
if(!s->budget--) { s->failed_pc=0x0c0ca6e4u; return 0; }
r[15]+=0xfffffff0u;
goto P_0c0ca6e6;
P_0c0ca6e6: /* original f5e6, guest PC 0x0c0ca6e6 */
if(!s->budget--) { s->failed_pc=0x0c0ca6e6u; return 0; }
vf3_matrix_load(s,ram,5,r[14]+r[0]);
goto P_0c0ca6e8;
P_0c0ca6e8: /* original 64f3, guest PC 0x0c0ca6e8 */
if(!s->budget--) { s->failed_pc=0x0c0ca6e8u; return 0; }
r[4]=r[15];
goto P_0c0ca6ea;
P_0c0ca6ea: /* original 70f8, guest PC 0x0c0ca6ea */
if(!s->budget--) { s->failed_pc=0x0c0ca6eau; return 0; }
r[0]+=0xfffffff8u;
goto P_0c0ca6ec;
P_0c0ca6ec: /* original 7404, guest PC 0x0c0ca6ec */
if(!s->budget--) { s->failed_pc=0x0c0ca6ecu; return 0; }
r[4]+=0x00000004u;
goto P_0c0ca6ee;
P_0c0ca6ee: /* original 4b0b, guest PC 0x0c0ca6ee */
if(!s->budget--) { s->failed_pc=0x0c0ca6eeu; return 0; }
target=r[11];
r[16]=code_base|0x0c0ca6f2u;
vf3_matrix_load(s,ram,4,r[14]+r[0]);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ca6f2u) { target=s->pc; goto dispatch; }
goto P_0c0ca6f2;
P_0c0ca6f0: /* original f4e6, guest PC 0x0c0ca6f0 */
if(!s->budget--) { s->failed_pc=0x0c0ca6f0u; return 0; }
vf3_matrix_load(s,ram,4,r[14]+r[0]);
goto P_0c0ca6f2;
P_0c0ca6f2: /* original 6403, guest PC 0x0c0ca6f2 */
if(!s->budget--) { s->failed_pc=0x0c0ca6f2u; return 0; }
r[4]=r[0];
goto P_0c0ca6f4;
P_0c0ca6f4: /* original 905e, guest PC 0x0c0ca6f4 */
if(!s->budget--) { s->failed_pc=0x0c0ca6f4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ca7b4u,2);
goto P_0c0ca6f6;
P_0c0ca6f6: /* original 0e46, guest PC 0x0c0ca6f6 */
if(!s->budget--) { s->failed_pc=0x0c0ca6f6u; return 0; }
write(ram,r[14]+r[0],r[4],4);
goto P_0c0ca6f8;
P_0c0ca6f8: /* original e004, guest PC 0x0c0ca6f8 */
if(!s->budget--) { s->failed_pc=0x0c0ca6f8u; return 0; }
r[0]=0x00000004u;
goto P_0c0ca6fa;
P_0c0ca6fa: /* original fff6, guest PC 0x0c0ca6fa */
if(!s->budget--) { s->failed_pc=0x0c0ca6fau; return 0; }
vf3_matrix_load(s,ram,15,r[15]+r[0]);
goto P_0c0ca6fc;
P_0c0ca6fc: /* original e008, guest PC 0x0c0ca6fc */
if(!s->budget--) { s->failed_pc=0x0c0ca6fcu; return 0; }
r[0]=0x00000008u;
goto P_0c0ca6fe;
P_0c0ca6fe: /* original fdf6, guest PC 0x0c0ca6fe */
if(!s->budget--) { s->failed_pc=0x0c0ca6feu; return 0; }
vf3_matrix_load(s,ram,13,r[15]+r[0]);
goto P_0c0ca700;
P_0c0ca700: /* original e00c, guest PC 0x0c0ca700 */
if(!s->budget--) { s->failed_pc=0x0c0ca700u; return 0; }
r[0]=0x0000000cu;
goto P_0c0ca702;
P_0c0ca702: /* original d330, guest PC 0x0c0ca702 */
if(!s->budget--) { s->failed_pc=0x0c0ca702u; return 0; }
r[3]=read(ram,0x0c0ca7c4u,4);
goto P_0c0ca704;
P_0c0ca704: /* original e40f, guest PC 0x0c0ca704 */
if(!s->budget--) { s->failed_pc=0x0c0ca704u; return 0; }
r[4]=0x0000000fu;
goto P_0c0ca706;
P_0c0ca706: /* original fef6, guest PC 0x0c0ca706 */
if(!s->budget--) { s->failed_pc=0x0c0ca706u; return 0; }
vf3_matrix_load(s,ram,14,r[15]+r[0]);
goto P_0c0ca708;
P_0c0ca708: /* original 6030, guest PC 0x0c0ca708 */
if(!s->budget--) { s->failed_pc=0x0c0ca708u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[3],1);
r[0]=tmp;
goto P_0c0ca70a;
P_0c0ca70a: /* original d52f, guest PC 0x0c0ca70a */
if(!s->budget--) { s->failed_pc=0x0c0ca70au; return 0; }
r[5]=read(ram,0x0c0ca7c8u,4);
goto P_0c0ca70c;
P_0c0ca70c: /* original 600c, guest PC 0x0c0ca70c */
if(!s->budget--) { s->failed_pc=0x0c0ca70cu; return 0; }
r[0]=r[0]&255u;
goto P_0c0ca70e;
P_0c0ca70e: /* original fe4d, guest PC 0x0c0ca70e */
if(!s->budget--) { s->failed_pc=0x0c0ca70eu; return 0; }
fr[14]^=0x80000000u;
goto P_0c0ca710;
P_0c0ca710: /* original 2409, guest PC 0x0c0ca710 */
if(!s->budget--) { s->failed_pc=0x0c0ca710u; return 0; }
r[4]&=r[0];
goto P_0c0ca712;
P_0c0ca712: /* original 6043, guest PC 0x0c0ca712 */
if(!s->budget--) { s->failed_pc=0x0c0ca712u; return 0; }
r[0]=r[4];
goto P_0c0ca714;
P_0c0ca714: /* original 880f, guest PC 0x0c0ca714 */
if(!s->budget--) { s->failed_pc=0x0c0ca714u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000fu)!=0);
goto P_0c0ca716;
P_0c0ca716: /* original 8d3e, guest PC 0x0c0ca716 */
if(!s->budget--) { s->failed_pc=0x0c0ca716u; return 0; }
cond=r[17]&1u;
r[6]=0x0000000du;
if(cond) { goto P_0c0ca796; }
goto P_0c0ca71a;
P_0c0ca718: /* original e60d, guest PC 0x0c0ca718 */
if(!s->budget--) { s->failed_pc=0x0c0ca718u; return 0; }
r[6]=0x0000000du;
goto P_0c0ca71a;
P_0c0ca71a: /* original 904c, guest PC 0x0c0ca71a */
if(!s->budget--) { s->failed_pc=0x0c0ca71au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ca7b6u,2);
goto P_0c0ca71c;
P_0c0ca71c: /* original 994c, guest PC 0x0c0ca71c */
if(!s->budget--) { s->failed_pc=0x0c0ca71cu; return 0; }
r[9]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ca7b8u,2);
goto P_0c0ca71e;
P_0c0ca71e: /* original 07ee, guest PC 0x0c0ca71e */
if(!s->budget--) { s->failed_pc=0x0c0ca71eu; return 0; }
r[7]=read(ram,r[14]+r[0],4);
goto P_0c0ca720;
P_0c0ca720: /* original 6043, guest PC 0x0c0ca720 */
if(!s->budget--) { s->failed_pc=0x0c0ca720u; return 0; }
r[0]=r[4];
goto P_0c0ca722;
P_0c0ca722: /* original 8804, guest PC 0x0c0ca722 */
if(!s->budget--) { s->failed_pc=0x0c0ca722u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000004u)!=0);
goto P_0c0ca724;
P_0c0ca724: /* original 6a73, guest PC 0x0c0ca724 */
if(!s->budget--) { s->failed_pc=0x0c0ca724u; return 0; }
r[10]=r[7];
goto P_0c0ca726;
P_0c0ca726: /* original 6873, guest PC 0x0c0ca726 */
if(!s->budget--) { s->failed_pc=0x0c0ca726u; return 0; }
r[8]=r[7];
goto P_0c0ca728;
P_0c0ca728: /* original 7a08, guest PC 0x0c0ca728 */
if(!s->budget--) { s->failed_pc=0x0c0ca728u; return 0; }
r[10]+=0x00000008u;
goto P_0c0ca72a;
P_0c0ca72a: /* original 8d03, guest PC 0x0c0ca72a */
if(!s->budget--) { s->failed_pc=0x0c0ca72au; return 0; }
cond=r[17]&1u;
r[9]+=r[14];
if(cond) { goto P_0c0ca734; }
goto P_0c0ca72e;
P_0c0ca72c: /* original 39ec, guest PC 0x0c0ca72c */
if(!s->budget--) { s->failed_pc=0x0c0ca72cu; return 0; }
r[9]+=r[14];
goto P_0c0ca72e;
P_0c0ca72e: /* original 6043, guest PC 0x0c0ca72e */
if(!s->budget--) { s->failed_pc=0x0c0ca72eu; return 0; }
r[0]=r[4];
goto P_0c0ca730;
P_0c0ca730: /* original 8801, guest PC 0x0c0ca730 */
if(!s->budget--) { s->failed_pc=0x0c0ca730u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c0ca732;
P_0c0ca732: /* original 8b05, guest PC 0x0c0ca732 */
if(!s->budget--) { s->failed_pc=0x0c0ca732u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0ca740; }
goto P_0c0ca734;
P_0c0ca734: /* original d325, guest PC 0x0c0ca734 */
if(!s->budget--) { s->failed_pc=0x0c0ca734u; return 0; }
r[3]=read(ram,0x0c0ca7ccu,4);
goto P_0c0ca736;
P_0c0ca736: /* original c726, guest PC 0x0c0ca736 */
if(!s->budget--) { s->failed_pc=0x0c0ca736u; return 0; }
r[0]=code_base|0x000ca7d0u;
goto P_0c0ca738;
P_0c0ca738: /* original ed07, guest PC 0x0c0ca738 */
if(!s->budget--) { s->failed_pc=0x0c0ca738u; return 0; }
r[13]=0x00000007u;
goto P_0c0ca73a;
P_0c0ca73a: /* original 2f32, guest PC 0x0c0ca73a */
if(!s->budget--) { s->failed_pc=0x0c0ca73au; return 0; }
write(ram,r[15],r[3],4);
goto P_0c0ca73c;
P_0c0ca73c: /* original a004, guest PC 0x0c0ca73c */
if(!s->budget--) { s->failed_pc=0x0c0ca73cu; return 0; }
vf3_matrix_load(s,ram,4,r[0]);
goto P_0c0ca748;
P_0c0ca73e: /* original f408, guest PC 0x0c0ca73e */
if(!s->budget--) { s->failed_pc=0x0c0ca73eu; return 0; }
vf3_matrix_load(s,ram,4,r[0]);
goto P_0c0ca740;
P_0c0ca740: /* original c724, guest PC 0x0c0ca740 */
if(!s->budget--) { s->failed_pc=0x0c0ca740u; return 0; }
r[0]=code_base|0x000ca7d4u;
goto P_0c0ca742;
P_0c0ca742: /* original 6d63, guest PC 0x0c0ca742 */
if(!s->budget--) { s->failed_pc=0x0c0ca742u; return 0; }
r[13]=r[6];
goto P_0c0ca744;
P_0c0ca744: /* original 2f52, guest PC 0x0c0ca744 */
if(!s->budget--) { s->failed_pc=0x0c0ca744u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0ca746;
P_0c0ca746: /* original f408, guest PC 0x0c0ca746 */
if(!s->budget--) { s->failed_pc=0x0c0ca746u; return 0; }
vf3_matrix_load(s,ram,4,r[0]);
goto P_0c0ca748;
P_0c0ca748: /* original a01f, guest PC 0x0c0ca748 */
if(!s->budget--) { s->failed_pc=0x0c0ca748u; return 0; }
vf3_matrix_move(s,12,4);
goto P_0c0ca78a;
P_0c0ca74a: /* original fc4c, guest PC 0x0c0ca74a */
if(!s->budget--) { s->failed_pc=0x0c0ca74au; return 0; }
vf3_matrix_move(s,12,4);
goto P_0c0ca74c;
P_0c0ca74c: /* original 6cf2, guest PC 0x0c0ca74c */
if(!s->budget--) { s->failed_pc=0x0c0ca74cu; return 0; }
tmp=read(ram,r[15],4);
r[12]=tmp;
goto P_0c0ca74e;
P_0c0ca74e: /* original 7c01, guest PC 0x0c0ca74e */
if(!s->budget--) { s->failed_pc=0x0c0ca74eu; return 0; }
r[12]+=0x00000001u;
goto P_0c0ca750;
P_0c0ca750: /* original 2fc2, guest PC 0x0c0ca750 */
if(!s->budget--) { s->failed_pc=0x0c0ca750u; return 0; }
write(ram,r[15],r[12],4);
goto P_0c0ca752;
P_0c0ca752: /* original 7cff, guest PC 0x0c0ca752 */
if(!s->budget--) { s->failed_pc=0x0c0ca752u; return 0; }
r[12]+=0xffffffffu;
goto P_0c0ca754;
P_0c0ca754: /* original 6cc0, guest PC 0x0c0ca754 */
if(!s->budget--) { s->failed_pc=0x0c0ca754u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[12],1);
r[12]=tmp;
goto P_0c0ca756;
P_0c0ca756: /* original 65c3, guest PC 0x0c0ca756 */
if(!s->budget--) { s->failed_pc=0x0c0ca756u; return 0; }
r[5]=r[12];
goto P_0c0ca758;
P_0c0ca758: /* original 4500, guest PC 0x0c0ca758 */
if(!s->budget--) { s->failed_pc=0x0c0ca758u; return 0; }
r[17]=(r[17]&~1u)|((r[5]>>31)!=0);
r[5]<<=1;
goto P_0c0ca75a;
P_0c0ca75a: /* original 63c3, guest PC 0x0c0ca75a */
if(!s->budget--) { s->failed_pc=0x0c0ca75au; return 0; }
r[3]=r[12];
goto P_0c0ca75c;
P_0c0ca75c: /* original 353c, guest PC 0x0c0ca75c */
if(!s->budget--) { s->failed_pc=0x0c0ca75cu; return 0; }
r[5]+=r[3];
goto P_0c0ca75e;
P_0c0ca75e: /* original 4508, guest PC 0x0c0ca75e */
if(!s->budget--) { s->failed_pc=0x0c0ca75eu; return 0; }
r[5]<<=2;
goto P_0c0ca760;
P_0c0ca760: /* original 6053, guest PC 0x0c0ca760 */
if(!s->budget--) { s->failed_pc=0x0c0ca760u; return 0; }
r[0]=r[5];
goto P_0c0ca762;
P_0c0ca762: /* original f486, guest PC 0x0c0ca762 */
if(!s->budget--) { s->failed_pc=0x0c0ca762u; return 0; }
vf3_matrix_load(s,ram,4,r[8]+r[0]);
goto P_0c0ca764;
P_0c0ca764: /* original f5a6, guest PC 0x0c0ca764 */
if(!s->budget--) { s->failed_pc=0x0c0ca764u; return 0; }
vf3_matrix_load(s,ram,5,r[10]+r[0]);
goto P_0c0ca766;
P_0c0ca766: /* original 6453, guest PC 0x0c0ca766 */
if(!s->budget--) { s->failed_pc=0x0c0ca766u; return 0; }
r[4]=r[5];
goto P_0c0ca768;
P_0c0ca768: /* original 64f3, guest PC 0x0c0ca768 */
if(!s->budget--) { s->failed_pc=0x0c0ca768u; return 0; }
r[4]=r[15];
goto P_0c0ca76a;
P_0c0ca76a: /* original 4b0b, guest PC 0x0c0ca76a */
if(!s->budget--) { s->failed_pc=0x0c0ca76au; return 0; }
target=r[11];
r[16]=code_base|0x0c0ca76eu;
r[4]+=0x00000004u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ca76eu) { target=s->pc; goto dispatch; }
goto P_0c0ca76e;
P_0c0ca76c: /* original 7404, guest PC 0x0c0ca76c */
if(!s->budget--) { s->failed_pc=0x0c0ca76cu; return 0; }
r[4]+=0x00000004u;
goto P_0c0ca76e;
P_0c0ca76e: /* original 6403, guest PC 0x0c0ca76e */
if(!s->budget--) { s->failed_pc=0x0c0ca76eu; return 0; }
r[4]=r[0];
goto P_0c0ca770;
P_0c0ca770: /* original e004, guest PC 0x0c0ca770 */
if(!s->budget--) { s->failed_pc=0x0c0ca770u; return 0; }
r[0]=0x00000004u;
goto P_0c0ca772;
P_0c0ca772: /* original f3f6, guest PC 0x0c0ca772 */
if(!s->budget--) { s->failed_pc=0x0c0ca772u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0ca774;
P_0c0ca774: /* original e008, guest PC 0x0c0ca774 */
if(!s->budget--) { s->failed_pc=0x0c0ca774u; return 0; }
r[0]=0x00000008u;
goto P_0c0ca776;
P_0c0ca776: /* original 7dff, guest PC 0x0c0ca776 */
if(!s->budget--) { s->failed_pc=0x0c0ca776u; return 0; }
r[13]+=0xffffffffu;
goto P_0c0ca778;
P_0c0ca778: /* original ff30, guest PC 0x0c0ca778 */
if(!s->budget--) { s->failed_pc=0x0c0ca778u; return 0; }
fr[15]=vf3_fpu_binary(fr[15],fr[3],r[18],'+');
goto P_0c0ca77a;
P_0c0ca77a: /* original f3f6, guest PC 0x0c0ca77a */
if(!s->budget--) { s->failed_pc=0x0c0ca77au; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0ca77c;
P_0c0ca77c: /* original e00c, guest PC 0x0c0ca77c */
if(!s->budget--) { s->failed_pc=0x0c0ca77cu; return 0; }
r[0]=0x0000000cu;
goto P_0c0ca77e;
P_0c0ca77e: /* original fd30, guest PC 0x0c0ca77e */
if(!s->budget--) { s->failed_pc=0x0c0ca77eu; return 0; }
fr[13]=vf3_fpu_binary(fr[13],fr[3],r[18],'+');
goto P_0c0ca780;
P_0c0ca780: /* original f3f6, guest PC 0x0c0ca780 */
if(!s->budget--) { s->failed_pc=0x0c0ca780u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0ca782;
P_0c0ca782: /* original 60c3, guest PC 0x0c0ca782 */
if(!s->budget--) { s->failed_pc=0x0c0ca782u; return 0; }
r[0]=r[12];
goto P_0c0ca784;
P_0c0ca784: /* original 4008, guest PC 0x0c0ca784 */
if(!s->budget--) { s->failed_pc=0x0c0ca784u; return 0; }
r[0]<<=2;
goto P_0c0ca786;
P_0c0ca786: /* original fe31, guest PC 0x0c0ca786 */
if(!s->budget--) { s->failed_pc=0x0c0ca786u; return 0; }
fr[14]=vf3_fpu_binary(fr[14],fr[3],r[18],'-');
goto P_0c0ca788;
P_0c0ca788: /* original 0946, guest PC 0x0c0ca788 */
if(!s->budget--) { s->failed_pc=0x0c0ca788u; return 0; }
write(ram,r[9]+r[0],r[4],4);
goto P_0c0ca78a;
P_0c0ca78a: /* original 2dd8, guest PC 0x0c0ca78a */
if(!s->budget--) { s->failed_pc=0x0c0ca78au; return 0; }
r[17]=(r[17]&~1u)|(((r[13]&r[13])==0)!=0);
goto P_0c0ca78c;
P_0c0ca78c: /* original 8bde, guest PC 0x0c0ca78c */
if(!s->budget--) { s->failed_pc=0x0c0ca78cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0ca74c; }
goto P_0c0ca78e;
P_0c0ca78e: /* original fdc2, guest PC 0x0c0ca78e */
if(!s->budget--) { s->failed_pc=0x0c0ca78eu; return 0; }
fr[13]=vf3_fpu_binary(fr[13],fr[12],r[18],'*');
goto P_0c0ca790;
P_0c0ca790: /* original ffc2, guest PC 0x0c0ca790 */
if(!s->budget--) { s->failed_pc=0x0c0ca790u; return 0; }
fr[15]=vf3_fpu_binary(fr[15],fr[12],r[18],'*');
goto P_0c0ca792;
P_0c0ca792: /* original a03d, guest PC 0x0c0ca792 */
if(!s->budget--) { s->failed_pc=0x0c0ca792u; return 0; }
fr[14]=vf3_fpu_binary(fr[14],fr[12],r[18],'*');
goto P_0c0ca810;
P_0c0ca794: /* original fec2, guest PC 0x0c0ca794 */
if(!s->budget--) { s->failed_pc=0x0c0ca794u; return 0; }
fr[14]=vf3_fpu_binary(fr[14],fr[12],r[18],'*');
goto P_0c0ca796;
P_0c0ca796: /* original 900e, guest PC 0x0c0ca796 */
if(!s->budget--) { s->failed_pc=0x0c0ca796u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ca7b6u,2);
goto P_0c0ca798;
P_0c0ca798: /* original 6a53, guest PC 0x0c0ca798 */
if(!s->budget--) { s->failed_pc=0x0c0ca798u; return 0; }
r[10]=r[5];
goto P_0c0ca79a;
P_0c0ca79a: /* original 990d, guest PC 0x0c0ca79a */
if(!s->budget--) { s->failed_pc=0x0c0ca79au; return 0; }
r[9]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ca7b8u,2);
goto P_0c0ca79c;
P_0c0ca79c: /* original 04ee, guest PC 0x0c0ca79c */
if(!s->budget--) { s->failed_pc=0x0c0ca79cu; return 0; }
r[4]=read(ram,r[14]+r[0],4);
goto P_0c0ca79e;
P_0c0ca79e: /* original c70e, guest PC 0x0c0ca79e */
if(!s->budget--) { s->failed_pc=0x0c0ca79eu; return 0; }
r[0]=code_base|0x000ca7d8u;
goto P_0c0ca7a0;
P_0c0ca7a0: /* original 9b0b, guest PC 0x0c0ca7a0 */
if(!s->budget--) { s->failed_pc=0x0c0ca7a0u; return 0; }
r[11]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ca7bau,2);
goto P_0c0ca7a2;
P_0c0ca7a2: /* original 39ec, guest PC 0x0c0ca7a2 */
if(!s->budget--) { s->failed_pc=0x0c0ca7a2u; return 0; }
r[9]+=r[14];
goto P_0c0ca7a4;
P_0c0ca7a4: /* original 6843, guest PC 0x0c0ca7a4 */
if(!s->budget--) { s->failed_pc=0x0c0ca7a4u; return 0; }
r[8]=r[4];
goto P_0c0ca7a6;
P_0c0ca7a6: /* original f608, guest PC 0x0c0ca7a6 */
if(!s->budget--) { s->failed_pc=0x0c0ca7a6u; return 0; }
vf3_matrix_load(s,ram,6,r[0]);
goto P_0c0ca7a8;
P_0c0ca7a8: /* original 7808, guest PC 0x0c0ca7a8 */
if(!s->budget--) { s->failed_pc=0x0c0ca7a8u; return 0; }
r[8]+=0x00000008u;
goto P_0c0ca7aa;
P_0c0ca7aa: /* original 67b3, guest PC 0x0c0ca7aa */
if(!s->budget--) { s->failed_pc=0x0c0ca7aau; return 0; }
r[7]=r[11];
goto P_0c0ca7ac;
P_0c0ca7ac: /* original 6d43, guest PC 0x0c0ca7ac */
if(!s->budget--) { s->failed_pc=0x0c0ca7acu; return 0; }
r[13]=r[4];
goto P_0c0ca7ae;
P_0c0ca7ae: /* original a02d, guest PC 0x0c0ca7ae */
if(!s->budget--) { s->failed_pc=0x0c0ca7aeu; return 0; }
r[7]+=0xfffffffcu;
goto P_0c0ca80c;
P_0c0ca7b0: /* original 77fc, guest PC 0x0c0ca7b0 */
if(!s->budget--) { s->failed_pc=0x0c0ca7b0u; return 0; }
r[7]+=0xfffffffcu;
if(!vf3_matrix_family(0x0c0ca7b2u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0ca7b2u; return 0; } return 1;
P_0c0ca7dc: /* original 65a4, guest PC 0x0c0ca7dc */
if(!s->budget--) { s->failed_pc=0x0c0ca7dcu; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[10],1);
r[10]+=1;
r[5]=tmp;
goto P_0c0ca7de;
P_0c0ca7de: /* original 6453, guest PC 0x0c0ca7de */
if(!s->budget--) { s->failed_pc=0x0c0ca7deu; return 0; }
r[4]=r[5];
goto P_0c0ca7e0;
P_0c0ca7e0: /* original 4400, guest PC 0x0c0ca7e0 */
if(!s->budget--) { s->failed_pc=0x0c0ca7e0u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c0ca7e2;
P_0c0ca7e2: /* original 6353, guest PC 0x0c0ca7e2 */
if(!s->budget--) { s->failed_pc=0x0c0ca7e2u; return 0; }
r[3]=r[5];
goto P_0c0ca7e4;
P_0c0ca7e4: /* original 343c, guest PC 0x0c0ca7e4 */
if(!s->budget--) { s->failed_pc=0x0c0ca7e4u; return 0; }
r[4]+=r[3];
goto P_0c0ca7e6;
P_0c0ca7e6: /* original 4408, guest PC 0x0c0ca7e6 */
if(!s->budget--) { s->failed_pc=0x0c0ca7e6u; return 0; }
r[4]<<=2;
goto P_0c0ca7e8;
P_0c0ca7e8: /* original 6043, guest PC 0x0c0ca7e8 */
if(!s->budget--) { s->failed_pc=0x0c0ca7e8u; return 0; }
r[0]=r[4];
goto P_0c0ca7ea;
P_0c0ca7ea: /* original f4d6, guest PC 0x0c0ca7ea */
if(!s->budget--) { s->failed_pc=0x0c0ca7eau; return 0; }
vf3_matrix_load(s,ram,4,r[13]+r[0]);
goto P_0c0ca7ec;
P_0c0ca7ec: /* original f586, guest PC 0x0c0ca7ec */
if(!s->budget--) { s->failed_pc=0x0c0ca7ecu; return 0; }
vf3_matrix_load(s,ram,5,r[8]+r[0]);
goto P_0c0ca7ee;
P_0c0ca7ee: /* original 6c43, guest PC 0x0c0ca7ee */
if(!s->budget--) { s->failed_pc=0x0c0ca7eeu; return 0; }
r[12]=r[4];
goto P_0c0ca7f0;
P_0c0ca7f0: /* original f74c, guest PC 0x0c0ca7f0 */
if(!s->budget--) { s->failed_pc=0x0c0ca7f0u; return 0; }
vf3_matrix_move(s,7,4);
goto P_0c0ca7f2;
P_0c0ca7f2: /* original f742, guest PC 0x0c0ca7f2 */
if(!s->budget--) { s->failed_pc=0x0c0ca7f2u; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[4],r[18],'*');
goto P_0c0ca7f4;
P_0c0ca7f4: /* original f05c, guest PC 0x0c0ca7f4 */
if(!s->budget--) { s->failed_pc=0x0c0ca7f4u; return 0; }
vf3_matrix_move(s,0,5);
goto P_0c0ca7f6;
P_0c0ca7f6: /* original f46c, guest PC 0x0c0ca7f6 */
if(!s->budget--) { s->failed_pc=0x0c0ca7f6u; return 0; }
vf3_matrix_move(s,4,6);
goto P_0c0ca7f8;
P_0c0ca7f8: /* original f75e, guest PC 0x0c0ca7f8 */
if(!s->budget--) { s->failed_pc=0x0c0ca7f8u; return 0; }
fr[7]=vf3_fpu_mac(fr[0],fr[5],fr[7],r[18]);
goto P_0c0ca7fa;
P_0c0ca7fa: /* original f57c, guest PC 0x0c0ca7fa */
if(!s->budget--) { s->failed_pc=0x0c0ca7fau; return 0; }
vf3_matrix_move(s,5,7);
goto P_0c0ca7fc;
P_0c0ca7fc: /* original f545, guest PC 0x0c0ca7fc */
if(!s->budget--) { s->failed_pc=0x0c0ca7fcu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[5])>as_float(fr[4]))!=0);
goto P_0c0ca7fe;
P_0c0ca7fe: /* original 8d01, guest PC 0x0c0ca7fe */
if(!s->budget--) { s->failed_pc=0x0c0ca7feu; return 0; }
cond=r[17]&1u;
r[4]=r[7];
if(cond) { goto P_0c0ca804; }
goto P_0c0ca802;
P_0c0ca800: /* original 6473, guest PC 0x0c0ca800 */
if(!s->budget--) { s->failed_pc=0x0c0ca800u; return 0; }
r[4]=r[7];
goto P_0c0ca802;
P_0c0ca802: /* original 64b3, guest PC 0x0c0ca802 */
if(!s->budget--) { s->failed_pc=0x0c0ca802u; return 0; }
r[4]=r[11];
goto P_0c0ca804;
P_0c0ca804: /* original 6053, guest PC 0x0c0ca804 */
if(!s->budget--) { s->failed_pc=0x0c0ca804u; return 0; }
r[0]=r[5];
goto P_0c0ca806;
P_0c0ca806: /* original 4008, guest PC 0x0c0ca806 */
if(!s->budget--) { s->failed_pc=0x0c0ca806u; return 0; }
r[0]<<=2;
goto P_0c0ca808;
P_0c0ca808: /* original 76ff, guest PC 0x0c0ca808 */
if(!s->budget--) { s->failed_pc=0x0c0ca808u; return 0; }
r[6]+=0xffffffffu;
goto P_0c0ca80a;
P_0c0ca80a: /* original 0946, guest PC 0x0c0ca80a */
if(!s->budget--) { s->failed_pc=0x0c0ca80au; return 0; }
write(ram,r[9]+r[0],r[4],4);
goto P_0c0ca80c;
P_0c0ca80c: /* original 2668, guest PC 0x0c0ca80c */
if(!s->budget--) { s->failed_pc=0x0c0ca80cu; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[6])==0)!=0);
goto P_0c0ca80e;
P_0c0ca80e: /* original 8be5, guest PC 0x0c0ca80e */
if(!s->budget--) { s->failed_pc=0x0c0ca80eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0ca7dc; }
goto P_0c0ca810;
P_0c0ca810: /* original 7f10, guest PC 0x0c0ca810 */
if(!s->budget--) { s->failed_pc=0x0c0ca810u; return 0; }
r[15]+=0x00000010u;
goto P_0c0ca812;
P_0c0ca812: /* original 9078, guest PC 0x0c0ca812 */
if(!s->budget--) { s->failed_pc=0x0c0ca812u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ca906u,2);
goto P_0c0ca814;
P_0c0ca814: /* original 4f26, guest PC 0x0c0ca814 */
if(!s->budget--) { s->failed_pc=0x0c0ca814u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0ca816;
P_0c0ca816: /* original fef7, guest PC 0x0c0ca816 */
if(!s->budget--) { s->failed_pc=0x0c0ca816u; return 0; }
vf3_matrix_store(s,ram,15,r[14]+r[0]);
goto P_0c0ca818;
P_0c0ca818: /* original 7004, guest PC 0x0c0ca818 */
if(!s->budget--) { s->failed_pc=0x0c0ca818u; return 0; }
r[0]+=0x00000004u;
goto P_0c0ca81a;
P_0c0ca81a: /* original fed7, guest PC 0x0c0ca81a */
if(!s->budget--) { s->failed_pc=0x0c0ca81au; return 0; }
vf3_matrix_store(s,ram,13,r[14]+r[0]);
goto P_0c0ca81c;
P_0c0ca81c: /* original 7004, guest PC 0x0c0ca81c */
if(!s->budget--) { s->failed_pc=0x0c0ca81cu; return 0; }
r[0]+=0x00000004u;
goto P_0c0ca81e;
P_0c0ca81e: /* original fee7, guest PC 0x0c0ca81e */
if(!s->budget--) { s->failed_pc=0x0c0ca81eu; return 0; }
vf3_matrix_store(s,ram,14,r[14]+r[0]);
goto P_0c0ca820;
P_0c0ca820: /* original fcf9, guest PC 0x0c0ca820 */
if(!s->budget--) { s->failed_pc=0x0c0ca820u; return 0; }
vf3_matrix_load(s,ram,12,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0ca822;
P_0c0ca822: /* original fdf9, guest PC 0x0c0ca822 */
if(!s->budget--) { s->failed_pc=0x0c0ca822u; return 0; }
vf3_matrix_load(s,ram,13,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0ca824;
P_0c0ca824: /* original fef9, guest PC 0x0c0ca824 */
if(!s->budget--) { s->failed_pc=0x0c0ca824u; return 0; }
vf3_matrix_load(s,ram,14,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0ca826;
P_0c0ca826: /* original fff9, guest PC 0x0c0ca826 */
if(!s->budget--) { s->failed_pc=0x0c0ca826u; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0ca828;
P_0c0ca828: /* original 68f6, guest PC 0x0c0ca828 */
if(!s->budget--) { s->failed_pc=0x0c0ca828u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c0ca82a;
P_0c0ca82a: /* original 69f6, guest PC 0x0c0ca82a */
if(!s->budget--) { s->failed_pc=0x0c0ca82au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c0ca82c;
P_0c0ca82c: /* original 6af6, guest PC 0x0c0ca82c */
if(!s->budget--) { s->failed_pc=0x0c0ca82cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0ca82e;
P_0c0ca82e: /* original 6bf6, guest PC 0x0c0ca82e */
if(!s->budget--) { s->failed_pc=0x0c0ca82eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0ca830;
P_0c0ca830: /* original 6cf6, guest PC 0x0c0ca830 */
if(!s->budget--) { s->failed_pc=0x0c0ca830u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0ca832;
P_0c0ca832: /* original 6df6, guest PC 0x0c0ca832 */
if(!s->budget--) { s->failed_pc=0x0c0ca832u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0ca834;
P_0c0ca834: /* original 000b, guest PC 0x0c0ca834 */
if(!s->budget--) { s->failed_pc=0x0c0ca834u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0ca836: /* original 6ef6, guest PC 0x0c0ca836 */
if(!s->budget--) { s->failed_pc=0x0c0ca836u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0ca838u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0ca838u; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
