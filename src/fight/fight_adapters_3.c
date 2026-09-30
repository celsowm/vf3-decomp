/* Static C ABI adapters. Generated with tools/oracle/translate_adapters.py.
 * Matrix operations are hand-written in matrix_family.c; unknown code fails.
 * Executed opcodes are checked against the untouched identity image. */
#include "fight/matrix_family.h"
#include "fight/sh4_fpu.h"
#include <math.h>
#include <string.h>
#define read vf3_matrix_read
#define write vf3_matrix_write
static float as_float(uint32_t u) { float f; memcpy(&f,&u,4); return f; }
static uint32_t as_bits(float f) { uint32_t u; memcpy(&u,&f,4); return u; }
static uint32_t truncate_float(uint32_t u) { double d=as_float(u); if(isnan(d) || d< -2147483648.0) return 0x80000000u; if(d>=2147483648.0) return 0x7fffffffu; return (uint32_t)(int32_t)d; }
static void divide_step(vf3_matrix_state*s,unsigned n,unsigned m) { uint32_t *r=s->v; unsigned oldq=(r[17]>>8)&1u,sign=(r[17]>>9)&1u,q=r[n]>>31; uint32_t divisor=r[m],shifted=(r[n]<<1)|(r[17]&1u); r[n]=oldq==sign?shifted-divisor:shifted+divisor; unsigned carry=oldq==sign?r[n]>shifted:r[n]<shifted; q^=carry^sign; r[17]=(r[17]&~0x101u)|(q<<8)|(q==sign); }
int vf3_fight_adapter_3(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c0c9c1cu: goto P_0c0c9c1c;
case 0x0c0c9c1eu: goto P_0c0c9c1e;
case 0x0c0c9cc0u: goto P_0c0c9cc0;
case 0x0c0c9cc2u: goto P_0c0c9cc2;
case 0x0c0c9cc4u: goto P_0c0c9cc4;
case 0x0c0c9cc6u: goto P_0c0c9cc6;
case 0x0c0c9cc8u: goto P_0c0c9cc8;
case 0x0c0c9ccau: goto P_0c0c9cca;
case 0x0c0c9cccu: goto P_0c0c9ccc;
case 0x0c0c9cceu: goto P_0c0c9cce;
case 0x0c0c9cd0u: goto P_0c0c9cd0;
case 0x0c0c9cd2u: goto P_0c0c9cd2;
case 0x0c0c9cd4u: goto P_0c0c9cd4;
case 0x0c0c9cd6u: goto P_0c0c9cd6;
case 0x0c0c9cd8u: goto P_0c0c9cd8;
case 0x0c0c9cdau: goto P_0c0c9cda;
case 0x0c0c9cdcu: goto P_0c0c9cdc;
case 0x0c0c9cdeu: goto P_0c0c9cde;
case 0x0c0c9ce0u: goto P_0c0c9ce0;
case 0x0c0c9ce2u: goto P_0c0c9ce2;
case 0x0c0c9ce4u: goto P_0c0c9ce4;
case 0x0c0c9ce6u: goto P_0c0c9ce6;
case 0x0c0c9ce8u: goto P_0c0c9ce8;
case 0x0c0c9ceau: goto P_0c0c9cea;
case 0x0c0c9cecu: goto P_0c0c9cec;
case 0x0c0c9ceeu: goto P_0c0c9cee;
case 0x0c0c9cf0u: goto P_0c0c9cf0;
case 0x0c0c9cf2u: goto P_0c0c9cf2;
case 0x0c0c9cf4u: goto P_0c0c9cf4;
case 0x0c0c9cf6u: goto P_0c0c9cf6;
case 0x0c0c9cf8u: goto P_0c0c9cf8;
case 0x0c0c9cfau: goto P_0c0c9cfa;
case 0x0c0c9cfcu: goto P_0c0c9cfc;
case 0x0c0c9cfeu: goto P_0c0c9cfe;
case 0x0c0c9d00u: goto P_0c0c9d00;
case 0x0c0c9d02u: goto P_0c0c9d02;
case 0x0c0c9dc8u: goto P_0c0c9dc8;
case 0x0c0c9dcau: goto P_0c0c9dca;
case 0x0c0c9dccu: goto P_0c0c9dcc;
case 0x0c0c9dceu: goto P_0c0c9dce;
case 0x0c0c9dd0u: goto P_0c0c9dd0;
case 0x0c0c9dd2u: goto P_0c0c9dd2;
case 0x0c0c9dd4u: goto P_0c0c9dd4;
case 0x0c0c9dd6u: goto P_0c0c9dd6;
case 0x0c0c9dd8u: goto P_0c0c9dd8;
case 0x0c0c9ddau: goto P_0c0c9dda;
case 0x0c0c9ddcu: goto P_0c0c9ddc;
case 0x0c0c9ddeu: goto P_0c0c9dde;
case 0x0c0c9de0u: goto P_0c0c9de0;
case 0x0c0c9de2u: goto P_0c0c9de2;
case 0x0c0c9de4u: goto P_0c0c9de4;
case 0x0c0c9de6u: goto P_0c0c9de6;
case 0x0c0c9de8u: goto P_0c0c9de8;
case 0x0c0c9deau: goto P_0c0c9dea;
case 0x0c0c9decu: goto P_0c0c9dec;
case 0x0c0c9deeu: goto P_0c0c9dee;
case 0x0c0c9df0u: goto P_0c0c9df0;
case 0x0c0c9df2u: goto P_0c0c9df2;
case 0x0c0c9df4u: goto P_0c0c9df4;
case 0x0c0c9df6u: goto P_0c0c9df6;
case 0x0c0c9df8u: goto P_0c0c9df8;
case 0x0c0c9dfau: goto P_0c0c9dfa;
case 0x0c0c9dfcu: goto P_0c0c9dfc;
case 0x0c0c9dfeu: goto P_0c0c9dfe;
case 0x0c0c9e00u: goto P_0c0c9e00;
case 0x0c0c9e02u: goto P_0c0c9e02;
case 0x0c0c9e04u: goto P_0c0c9e04;
case 0x0c0c9e06u: goto P_0c0c9e06;
case 0x0c0c9e08u: goto P_0c0c9e08;
case 0x0c0c9e0au: goto P_0c0c9e0a;
case 0x0c0c9e0cu: goto P_0c0c9e0c;
case 0x0c0c9e0eu: goto P_0c0c9e0e;
case 0x0c0c9e10u: goto P_0c0c9e10;
case 0x0c0c9e12u: goto P_0c0c9e12;
case 0x0c0c9e14u: goto P_0c0c9e14;
case 0x0c0c9e16u: goto P_0c0c9e16;
case 0x0c0c9e18u: goto P_0c0c9e18;
case 0x0c0c9e1au: goto P_0c0c9e1a;
case 0x0c0c9e1cu: goto P_0c0c9e1c;
case 0x0c0c9e1eu: goto P_0c0c9e1e;
case 0x0c0c9e20u: goto P_0c0c9e20;
case 0x0c0c9e22u: goto P_0c0c9e22;
case 0x0c0c9e24u: goto P_0c0c9e24;
case 0x0c0c9e26u: goto P_0c0c9e26;
case 0x0c0c9e28u: goto P_0c0c9e28;
case 0x0c0c9e2au: goto P_0c0c9e2a;
case 0x0c0c9e2cu: goto P_0c0c9e2c;
case 0x0c0c9e2eu: goto P_0c0c9e2e;
case 0x0c0c9e30u: goto P_0c0c9e30;
case 0x0c0c9e32u: goto P_0c0c9e32;
case 0x0c0c9e34u: goto P_0c0c9e34;
case 0x0c0c9e36u: goto P_0c0c9e36;
case 0x0c0c9e38u: goto P_0c0c9e38;
case 0x0c0c9e3au: goto P_0c0c9e3a;
case 0x0c0c9e3cu: goto P_0c0c9e3c;
case 0x0c0c9e3eu: goto P_0c0c9e3e;
case 0x0c0c9e40u: goto P_0c0c9e40;
case 0x0c0c9e42u: goto P_0c0c9e42;
case 0x0c0c9e44u: goto P_0c0c9e44;
case 0x0c0c9e46u: goto P_0c0c9e46;
case 0x0c0c9e48u: goto P_0c0c9e48;
case 0x0c0c9e4au: goto P_0c0c9e4a;
case 0x0c0c9e4cu: goto P_0c0c9e4c;
case 0x0c0c9e4eu: goto P_0c0c9e4e;
case 0x0c0c9e50u: goto P_0c0c9e50;
case 0x0c0c9e52u: goto P_0c0c9e52;
case 0x0c0c9e54u: goto P_0c0c9e54;
case 0x0c0c9e56u: goto P_0c0c9e56;
case 0x0c0c9e58u: goto P_0c0c9e58;
case 0x0c0c9e5au: goto P_0c0c9e5a;
case 0x0c0c9e5cu: goto P_0c0c9e5c;
case 0x0c0c9e5eu: goto P_0c0c9e5e;
case 0x0c0c9e60u: goto P_0c0c9e60;
case 0x0c0c9e62u: goto P_0c0c9e62;
case 0x0c0c9e64u: goto P_0c0c9e64;
case 0x0c0c9e66u: goto P_0c0c9e66;
case 0x0c0c9e68u: goto P_0c0c9e68;
case 0x0c0c9e6au: goto P_0c0c9e6a;
case 0x0c0c9e6cu: goto P_0c0c9e6c;
case 0x0c0c9e6eu: goto P_0c0c9e6e;
case 0x0c0c9e80u: goto P_0c0c9e80;
case 0x0c0c9e82u: goto P_0c0c9e82;
case 0x0c0c9e84u: goto P_0c0c9e84;
case 0x0c0c9e86u: goto P_0c0c9e86;
case 0x0c0c9e88u: goto P_0c0c9e88;
case 0x0c0c9e8au: goto P_0c0c9e8a;
case 0x0c0c9e8cu: goto P_0c0c9e8c;
case 0x0c0c9e8eu: goto P_0c0c9e8e;
case 0x0c0c9e90u: goto P_0c0c9e90;
case 0x0c0c9e92u: goto P_0c0c9e92;
case 0x0c0c9e94u: goto P_0c0c9e94;
case 0x0c0c9e96u: goto P_0c0c9e96;
case 0x0c0c9e98u: goto P_0c0c9e98;
case 0x0c0c9e9au: goto P_0c0c9e9a;
case 0x0c0c9e9cu: goto P_0c0c9e9c;
case 0x0c0c9e9eu: goto P_0c0c9e9e;
case 0x0c0c9ea0u: goto P_0c0c9ea0;
case 0x0c0c9ea2u: goto P_0c0c9ea2;
case 0x0c0c9ea4u: goto P_0c0c9ea4;
case 0x0c0c9ea6u: goto P_0c0c9ea6;
case 0x0c0c9ea8u: goto P_0c0c9ea8;
case 0x0c0c9eaau: goto P_0c0c9eaa;
case 0x0c0c9eacu: goto P_0c0c9eac;
case 0x0c0c9eaeu: goto P_0c0c9eae;
case 0x0c0c9eb0u: goto P_0c0c9eb0;
case 0x0c0c9eb2u: goto P_0c0c9eb2;
case 0x0c0c9eb4u: goto P_0c0c9eb4;
case 0x0c0c9eb6u: goto P_0c0c9eb6;
case 0x0c0c9eb8u: goto P_0c0c9eb8;
case 0x0c0c9ebau: goto P_0c0c9eba;
case 0x0c0c9ebcu: goto P_0c0c9ebc;
case 0x0c0c9ebeu: goto P_0c0c9ebe;
case 0x0c0c9ec0u: goto P_0c0c9ec0;
case 0x0c0c9ec2u: goto P_0c0c9ec2;
case 0x0c0c9ec4u: goto P_0c0c9ec4;
case 0x0c0c9ec6u: goto P_0c0c9ec6;
case 0x0c0c9ec8u: goto P_0c0c9ec8;
case 0x0c0c9ecau: goto P_0c0c9eca;
case 0x0c0c9eccu: goto P_0c0c9ecc;
case 0x0c0c9eceu: goto P_0c0c9ece;
case 0x0c0c9ed0u: goto P_0c0c9ed0;
case 0x0c0c9ed2u: goto P_0c0c9ed2;
case 0x0c0c9ed4u: goto P_0c0c9ed4;
case 0x0c0c9ed6u: goto P_0c0c9ed6;
case 0x0c0c9ed8u: goto P_0c0c9ed8;
case 0x0c0c9edau: goto P_0c0c9eda;
case 0x0c0c9edcu: goto P_0c0c9edc;
case 0x0c0c9edeu: goto P_0c0c9ede;
case 0x0c0c9ee0u: goto P_0c0c9ee0;
case 0x0c0c9ee2u: goto P_0c0c9ee2;
case 0x0c0c9ee4u: goto P_0c0c9ee4;
case 0x0c0c9ee6u: goto P_0c0c9ee6;
case 0x0c0c9ee8u: goto P_0c0c9ee8;
case 0x0c0c9eeau: goto P_0c0c9eea;
case 0x0c0c9eecu: goto P_0c0c9eec;
case 0x0c0c9eeeu: goto P_0c0c9eee;
case 0x0c0c9ef0u: goto P_0c0c9ef0;
case 0x0c0c9ef2u: goto P_0c0c9ef2;
case 0x0c0c9ef4u: goto P_0c0c9ef4;
case 0x0c0c9ef6u: goto P_0c0c9ef6;
case 0x0c0c9ef8u: goto P_0c0c9ef8;
case 0x0c0c9efau: goto P_0c0c9efa;
case 0x0c0c9efcu: goto P_0c0c9efc;
case 0x0c0c9efeu: goto P_0c0c9efe;
case 0x0c0c9f00u: goto P_0c0c9f00;
case 0x0c0c9f02u: goto P_0c0c9f02;
case 0x0c0c9f04u: goto P_0c0c9f04;
case 0x0c0c9f06u: goto P_0c0c9f06;
case 0x0c0c9f08u: goto P_0c0c9f08;
case 0x0c0c9f0au: goto P_0c0c9f0a;
case 0x0c0c9f0cu: goto P_0c0c9f0c;
case 0x0c0c9f0eu: goto P_0c0c9f0e;
case 0x0c0c9f10u: goto P_0c0c9f10;
case 0x0c0c9f12u: goto P_0c0c9f12;
case 0x0c0c9f14u: goto P_0c0c9f14;
case 0x0c0c9f16u: goto P_0c0c9f16;
case 0x0c0c9f18u: goto P_0c0c9f18;
case 0x0c0c9f1au: goto P_0c0c9f1a;
case 0x0c0c9f1cu: goto P_0c0c9f1c;
case 0x0c0c9f1eu: goto P_0c0c9f1e;
case 0x0c0c9f20u: goto P_0c0c9f20;
case 0x0c0c9f22u: goto P_0c0c9f22;
case 0x0c0c9f24u: goto P_0c0c9f24;
case 0x0c0c9f26u: goto P_0c0c9f26;
case 0x0c0c9f28u: goto P_0c0c9f28;
case 0x0c0c9f2au: goto P_0c0c9f2a;
case 0x0c0c9f2cu: goto P_0c0c9f2c;
case 0x0c0c9f2eu: goto P_0c0c9f2e;
case 0x0c0c9f30u: goto P_0c0c9f30;
case 0x0c0c9f32u: goto P_0c0c9f32;
case 0x0c0c9f34u: goto P_0c0c9f34;
case 0x0c0c9f36u: goto P_0c0c9f36;
case 0x0c0c9f38u: goto P_0c0c9f38;
case 0x0c0c9f3au: goto P_0c0c9f3a;
case 0x0c0ca234u: goto P_0c0ca234;
case 0x0c0ca236u: goto P_0c0ca236;
case 0x0c0ca238u: goto P_0c0ca238;
case 0x0c0ca23au: goto P_0c0ca23a;
case 0x0c0ca23cu: goto P_0c0ca23c;
case 0x0c0ca23eu: goto P_0c0ca23e;
case 0x0c0ca240u: goto P_0c0ca240;
case 0x0c0ca242u: goto P_0c0ca242;
case 0x0c0ca244u: goto P_0c0ca244;
case 0x0c0ca246u: goto P_0c0ca246;
case 0x0c0ca248u: goto P_0c0ca248;
case 0x0c0ca24au: goto P_0c0ca24a;
case 0x0c0ca24cu: goto P_0c0ca24c;
case 0x0c0ca24eu: goto P_0c0ca24e;
case 0x0c0ca250u: goto P_0c0ca250;
case 0x0c0ca252u: goto P_0c0ca252;
case 0x0c0ca254u: goto P_0c0ca254;
case 0x0c0ca256u: goto P_0c0ca256;
case 0x0c0ca258u: goto P_0c0ca258;
case 0x0c0ca25au: goto P_0c0ca25a;
case 0x0c0ca25cu: goto P_0c0ca25c;
case 0x0c0ca25eu: goto P_0c0ca25e;
case 0x0c0ca260u: goto P_0c0ca260;
case 0x0c0ca262u: goto P_0c0ca262;
case 0x0c0ca264u: goto P_0c0ca264;
case 0x0c0ca266u: goto P_0c0ca266;
case 0x0c0ca268u: goto P_0c0ca268;
case 0x0c0ca26au: goto P_0c0ca26a;
case 0x0c0ca26cu: goto P_0c0ca26c;
case 0x0c0ca26eu: goto P_0c0ca26e;
case 0x0c0ca270u: goto P_0c0ca270;
case 0x0c0ca272u: goto P_0c0ca272;
case 0x0c0ca274u: goto P_0c0ca274;
case 0x0c0ca276u: goto P_0c0ca276;
case 0x0c0ca278u: goto P_0c0ca278;
case 0x0c0ca27au: goto P_0c0ca27a;
case 0x0c0ca27cu: goto P_0c0ca27c;
case 0x0c0ca27eu: goto P_0c0ca27e;
case 0x0c0ca280u: goto P_0c0ca280;
case 0x0c0ca322u: goto P_0c0ca322;
case 0x0c0ca324u: goto P_0c0ca324;
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
case 0x0c0caa9cu: goto P_0c0caa9c;
case 0x0c0caa9eu: goto P_0c0caa9e;
case 0x0c0caaa0u: goto P_0c0caaa0;
case 0x0c0caaa2u: goto P_0c0caaa2;
case 0x0c0caaa4u: goto P_0c0caaa4;
case 0x0c0caaa6u: goto P_0c0caaa6;
case 0x0c0caaa8u: goto P_0c0caaa8;
case 0x0c0caaaau: goto P_0c0caaaa;
case 0x0c0caaacu: goto P_0c0caaac;
case 0x0c0caaaeu: goto P_0c0caaae;
case 0x0c0caab0u: goto P_0c0caab0;
case 0x0c0caab2u: goto P_0c0caab2;
case 0x0c0caab4u: goto P_0c0caab4;
case 0x0c0caab6u: goto P_0c0caab6;
case 0x0c0caab8u: goto P_0c0caab8;
case 0x0c0caabau: goto P_0c0caaba;
case 0x0c0caabcu: goto P_0c0caabc;
case 0x0c0caabeu: goto P_0c0caabe;
case 0x0c0caac0u: goto P_0c0caac0;
case 0x0c0caac2u: goto P_0c0caac2;
case 0x0c0caac4u: goto P_0c0caac4;
case 0x0c0caac6u: goto P_0c0caac6;
case 0x0c0caac8u: goto P_0c0caac8;
case 0x0c0caacau: goto P_0c0caaca;
case 0x0c0caaccu: goto P_0c0caacc;
case 0x0c0caaceu: goto P_0c0caace;
case 0x0c0caad0u: goto P_0c0caad0;
case 0x0c0caad2u: goto P_0c0caad2;
case 0x0c0caad4u: goto P_0c0caad4;
case 0x0c0caad6u: goto P_0c0caad6;
case 0x0c0caad8u: goto P_0c0caad8;
case 0x0c0caadau: goto P_0c0caada;
case 0x0c0caadcu: goto P_0c0caadc;
case 0x0c0caadeu: goto P_0c0caade;
case 0x0c0caae0u: goto P_0c0caae0;
case 0x0c0caae2u: goto P_0c0caae2;
case 0x0c0caae4u: goto P_0c0caae4;
case 0x0c0caae6u: goto P_0c0caae6;
case 0x0c0caae8u: goto P_0c0caae8;
case 0x0c0caaeau: goto P_0c0caaea;
case 0x0c0caaecu: goto P_0c0caaec;
case 0x0c0caaeeu: goto P_0c0caaee;
case 0x0c0caaf0u: goto P_0c0caaf0;
case 0x0c0caaf2u: goto P_0c0caaf2;
case 0x0c0caaf4u: goto P_0c0caaf4;
case 0x0c0caaf6u: goto P_0c0caaf6;
case 0x0c0caaf8u: goto P_0c0caaf8;
case 0x0c0caafau: goto P_0c0caafa;
case 0x0c0caafcu: goto P_0c0caafc;
case 0x0c0caafeu: goto P_0c0caafe;
case 0x0c0cab00u: goto P_0c0cab00;
case 0x0c0cab02u: goto P_0c0cab02;
case 0x0c0cab04u: goto P_0c0cab04;
case 0x0c0cab06u: goto P_0c0cab06;
case 0x0c0cab08u: goto P_0c0cab08;
case 0x0c0cab0au: goto P_0c0cab0a;
case 0x0c0cab0cu: goto P_0c0cab0c;
case 0x0c0cab0eu: goto P_0c0cab0e;
case 0x0c0cab10u: goto P_0c0cab10;
case 0x0c0cab30u: goto P_0c0cab30;
case 0x0c0cab32u: goto P_0c0cab32;
case 0x0c0cab34u: goto P_0c0cab34;
case 0x0c0cab36u: goto P_0c0cab36;
case 0x0c0cab38u: goto P_0c0cab38;
case 0x0c0cab3au: goto P_0c0cab3a;
case 0x0c0cab3cu: goto P_0c0cab3c;
case 0x0c0cab3eu: goto P_0c0cab3e;
case 0x0c0cab40u: goto P_0c0cab40;
case 0x0c0cab42u: goto P_0c0cab42;
case 0x0c0cab44u: goto P_0c0cab44;
case 0x0c0cab46u: goto P_0c0cab46;
case 0x0c0cab48u: goto P_0c0cab48;
case 0x0c0cab4au: goto P_0c0cab4a;
case 0x0c0cab4cu: goto P_0c0cab4c;
case 0x0c0cab4eu: goto P_0c0cab4e;
case 0x0c0cab50u: goto P_0c0cab50;
case 0x0c0cab52u: goto P_0c0cab52;
case 0x0c0cab54u: goto P_0c0cab54;
case 0x0c0cab56u: goto P_0c0cab56;
case 0x0c0cab58u: goto P_0c0cab58;
case 0x0c0cab5au: goto P_0c0cab5a;
case 0x0c0cab5cu: goto P_0c0cab5c;
case 0x0c0cab5eu: goto P_0c0cab5e;
case 0x0c0cab60u: goto P_0c0cab60;
case 0x0c0cab62u: goto P_0c0cab62;
case 0x0c0cab64u: goto P_0c0cab64;
case 0x0c0cab66u: goto P_0c0cab66;
case 0x0c0cab68u: goto P_0c0cab68;
case 0x0c0cab6au: goto P_0c0cab6a;
case 0x0c0cab6cu: goto P_0c0cab6c;
case 0x0c0cab6eu: goto P_0c0cab6e;
case 0x0c0cab70u: goto P_0c0cab70;
case 0x0c0cab72u: goto P_0c0cab72;
case 0x0c0cab74u: goto P_0c0cab74;
case 0x0c0cab76u: goto P_0c0cab76;
case 0x0c0cab78u: goto P_0c0cab78;
case 0x0c0cab7au: goto P_0c0cab7a;
case 0x0c0cab7cu: goto P_0c0cab7c;
case 0x0c0cab7eu: goto P_0c0cab7e;
case 0x0c0cab80u: goto P_0c0cab80;
case 0x0c0cab82u: goto P_0c0cab82;
case 0x0c0cab84u: goto P_0c0cab84;
case 0x0c0cab86u: goto P_0c0cab86;
case 0x0c0cab88u: goto P_0c0cab88;
case 0x0c0cab8au: goto P_0c0cab8a;
case 0x0c0cab8cu: goto P_0c0cab8c;
case 0x0c0cab8eu: goto P_0c0cab8e;
case 0x0c0cab90u: goto P_0c0cab90;
case 0x0c0cab92u: goto P_0c0cab92;
case 0x0c0cab94u: goto P_0c0cab94;
case 0x0c0cab96u: goto P_0c0cab96;
case 0x0c0cab98u: goto P_0c0cab98;
case 0x0c0cab9au: goto P_0c0cab9a;
case 0x0c0cab9cu: goto P_0c0cab9c;
case 0x0c0cab9eu: goto P_0c0cab9e;
case 0x0c0caba0u: goto P_0c0caba0;
case 0x0c0caba2u: goto P_0c0caba2;
case 0x0c0caba4u: goto P_0c0caba4;
case 0x0c0caba6u: goto P_0c0caba6;
case 0x0c0caba8u: goto P_0c0caba8;
case 0x0c0cabaau: goto P_0c0cabaa;
case 0x0c0cabacu: goto P_0c0cabac;
case 0x0c0cabaeu: goto P_0c0cabae;
case 0x0c0cabb0u: goto P_0c0cabb0;
case 0x0c0cabb2u: goto P_0c0cabb2;
case 0x0c0cabb4u: goto P_0c0cabb4;
case 0x0c0cabb6u: goto P_0c0cabb6;
case 0x0c0cabb8u: goto P_0c0cabb8;
case 0x0c0cabbau: goto P_0c0cabba;
case 0x0c0cabbcu: goto P_0c0cabbc;
case 0x0c0cabbeu: goto P_0c0cabbe;
case 0x0c0cabc0u: goto P_0c0cabc0;
case 0x0c0cabc2u: goto P_0c0cabc2;
case 0x0c0cabc4u: goto P_0c0cabc4;
case 0x0c0cabc6u: goto P_0c0cabc6;
case 0x0c0cabc8u: goto P_0c0cabc8;
case 0x0c0cabcau: goto P_0c0cabca;
case 0x0c0cabccu: goto P_0c0cabcc;
case 0x0c0cabceu: goto P_0c0cabce;
case 0x0c0cabd0u: goto P_0c0cabd0;
case 0x0c0cabd2u: goto P_0c0cabd2;
case 0x0c0cabd4u: goto P_0c0cabd4;
case 0x0c0cabd6u: goto P_0c0cabd6;
case 0x0c0cabd8u: goto P_0c0cabd8;
case 0x0c0cabdau: goto P_0c0cabda;
case 0x0c0cabdcu: goto P_0c0cabdc;
case 0x0c0cabdeu: goto P_0c0cabde;
case 0x0c0cabe0u: goto P_0c0cabe0;
case 0x0c0cabe2u: goto P_0c0cabe2;
case 0x0c0cabe4u: goto P_0c0cabe4;
case 0x0c0cabe6u: goto P_0c0cabe6;
case 0x0c0cabe8u: goto P_0c0cabe8;
case 0x0c0cabeau: goto P_0c0cabea;
case 0x0c0cabecu: goto P_0c0cabec;
case 0x0c0cabeeu: goto P_0c0cabee;
case 0x0c0cabf0u: goto P_0c0cabf0;
case 0x0c0cabf2u: goto P_0c0cabf2;
case 0x0c0cabf4u: goto P_0c0cabf4;
case 0x0c0cabf6u: goto P_0c0cabf6;
case 0x0c0cabf8u: goto P_0c0cabf8;
case 0x0c0cabfau: goto P_0c0cabfa;
case 0x0c0cabfcu: goto P_0c0cabfc;
case 0x0c0cabfeu: goto P_0c0cabfe;
case 0x0c0cac00u: goto P_0c0cac00;
case 0x0c0cac02u: goto P_0c0cac02;
case 0x0c0cac04u: goto P_0c0cac04;
case 0x0c0cac06u: goto P_0c0cac06;
case 0x0c0cac08u: goto P_0c0cac08;
case 0x0c0cac0au: goto P_0c0cac0a;
case 0x0c0cac0cu: goto P_0c0cac0c;
case 0x0c0cac0eu: goto P_0c0cac0e;
case 0x0c0cac10u: goto P_0c0cac10;
case 0x0c0cac12u: goto P_0c0cac12;
case 0x0c0cac14u: goto P_0c0cac14;
case 0x0c0cac16u: goto P_0c0cac16;
case 0x0c0cac18u: goto P_0c0cac18;
case 0x0c0cac1au: goto P_0c0cac1a;
case 0x0c0cac1cu: goto P_0c0cac1c;
case 0x0c0cac1eu: goto P_0c0cac1e;
case 0x0c0cac20u: goto P_0c0cac20;
case 0x0c0cac22u: goto P_0c0cac22;
case 0x0c0cac24u: goto P_0c0cac24;
case 0x0c0cac26u: goto P_0c0cac26;
case 0x0c0cac28u: goto P_0c0cac28;
case 0x0c0cac2au: goto P_0c0cac2a;
case 0x0c0cac2cu: goto P_0c0cac2c;
case 0x0c0cac2eu: goto P_0c0cac2e;
case 0x0c0cac5cu: goto P_0c0cac5c;
case 0x0c0cac5eu: goto P_0c0cac5e;
case 0x0c0cac60u: goto P_0c0cac60;
case 0x0c0cac62u: goto P_0c0cac62;
case 0x0c0cac64u: goto P_0c0cac64;
case 0x0c0cac66u: goto P_0c0cac66;
case 0x0c0cac68u: goto P_0c0cac68;
case 0x0c0cac6au: goto P_0c0cac6a;
case 0x0c0cac6cu: goto P_0c0cac6c;
case 0x0c0cac6eu: goto P_0c0cac6e;
case 0x0c0cac70u: goto P_0c0cac70;
case 0x0c0cac72u: goto P_0c0cac72;
case 0x0c0cac74u: goto P_0c0cac74;
case 0x0c0cac76u: goto P_0c0cac76;
case 0x0c0cac78u: goto P_0c0cac78;
case 0x0c0cac7au: goto P_0c0cac7a;
case 0x0c0cac7cu: goto P_0c0cac7c;
case 0x0c0cac7eu: goto P_0c0cac7e;
case 0x0c0cac80u: goto P_0c0cac80;
case 0x0c0cac82u: goto P_0c0cac82;
case 0x0c0cac84u: goto P_0c0cac84;
case 0x0c0cac86u: goto P_0c0cac86;
case 0x0c0cac88u: goto P_0c0cac88;
case 0x0c0cac8au: goto P_0c0cac8a;
case 0x0c0cac8cu: goto P_0c0cac8c;
case 0x0c0cac8eu: goto P_0c0cac8e;
case 0x0c0cac90u: goto P_0c0cac90;
case 0x0c0cac92u: goto P_0c0cac92;
case 0x0c0cac94u: goto P_0c0cac94;
case 0x0c0cac96u: goto P_0c0cac96;
case 0x0c0cac98u: goto P_0c0cac98;
case 0x0c0cac9au: goto P_0c0cac9a;
case 0x0c0cac9cu: goto P_0c0cac9c;
case 0x0c0cac9eu: goto P_0c0cac9e;
case 0x0c0caca0u: goto P_0c0caca0;
case 0x0c0caca2u: goto P_0c0caca2;
case 0x0c0caca4u: goto P_0c0caca4;
case 0x0c0caca6u: goto P_0c0caca6;
case 0x0c0caca8u: goto P_0c0caca8;
case 0x0c0cacaau: goto P_0c0cacaa;
case 0x0c0cacacu: goto P_0c0cacac;
case 0x0c0cacaeu: goto P_0c0cacae;
case 0x0c0cacb0u: goto P_0c0cacb0;
case 0x0c0cacb2u: goto P_0c0cacb2;
case 0x0c0cacb4u: goto P_0c0cacb4;
case 0x0c0cacb6u: goto P_0c0cacb6;
case 0x0c0cacb8u: goto P_0c0cacb8;
case 0x0c0cacbau: goto P_0c0cacba;
case 0x0c0cacbcu: goto P_0c0cacbc;
case 0x0c0cacbeu: goto P_0c0cacbe;
case 0x0c0cacc0u: goto P_0c0cacc0;
case 0x0c0cacc2u: goto P_0c0cacc2;
case 0x0c0cacc4u: goto P_0c0cacc4;
case 0x0c0cacc6u: goto P_0c0cacc6;
case 0x0c0cacc8u: goto P_0c0cacc8;
case 0x0c0caccau: goto P_0c0cacca;
case 0x0c0cacccu: goto P_0c0caccc;
case 0x0c0cacceu: goto P_0c0cacce;
case 0x0c0cacd0u: goto P_0c0cacd0;
case 0x0c0cacd2u: goto P_0c0cacd2;
case 0x0c0cacd4u: goto P_0c0cacd4;
case 0x0c0cacd6u: goto P_0c0cacd6;
case 0x0c0cacd8u: goto P_0c0cacd8;
case 0x0c0cacdau: goto P_0c0cacda;
case 0x0c0cacdcu: goto P_0c0cacdc;
case 0x0c0cacdeu: goto P_0c0cacde;
case 0x0c0cace0u: goto P_0c0cace0;
case 0x0c0cace2u: goto P_0c0cace2;
case 0x0c0cace4u: goto P_0c0cace4;
case 0x0c0cace6u: goto P_0c0cace6;
case 0x0c0cace8u: goto P_0c0cace8;
case 0x0c0caceau: goto P_0c0cacea;
case 0x0c0cacecu: goto P_0c0cacec;
case 0x0c0caceeu: goto P_0c0cacee;
case 0x0c0cad04u: goto P_0c0cad04;
case 0x0c0cad06u: goto P_0c0cad06;
case 0x0c0cad08u: goto P_0c0cad08;
case 0x0c0cad0au: goto P_0c0cad0a;
case 0x0c0cad0cu: goto P_0c0cad0c;
case 0x0c0cad0eu: goto P_0c0cad0e;
case 0x0c0cad10u: goto P_0c0cad10;
case 0x0c0cad12u: goto P_0c0cad12;
case 0x0c0cad14u: goto P_0c0cad14;
case 0x0c0cad16u: goto P_0c0cad16;
case 0x0c0cad18u: goto P_0c0cad18;
case 0x0c0cad1au: goto P_0c0cad1a;
case 0x0c0cad1cu: goto P_0c0cad1c;
case 0x0c0cad1eu: goto P_0c0cad1e;
case 0x0c0cad20u: goto P_0c0cad20;
case 0x0c0cad22u: goto P_0c0cad22;
case 0x0c0cad24u: goto P_0c0cad24;
case 0x0c0cad26u: goto P_0c0cad26;
case 0x0c0cad28u: goto P_0c0cad28;
case 0x0c0cad2au: goto P_0c0cad2a;
case 0x0c0cad2cu: goto P_0c0cad2c;
case 0x0c0cad2eu: goto P_0c0cad2e;
case 0x0c0cad30u: goto P_0c0cad30;
case 0x0c0cad32u: goto P_0c0cad32;
case 0x0c0cad34u: goto P_0c0cad34;
case 0x0c0cad36u: goto P_0c0cad36;
case 0x0c0cad38u: goto P_0c0cad38;
case 0x0c0cad3au: goto P_0c0cad3a;
case 0x0c0cad3cu: goto P_0c0cad3c;
case 0x0c0cad3eu: goto P_0c0cad3e;
case 0x0c0cad40u: goto P_0c0cad40;
case 0x0c0cad42u: goto P_0c0cad42;
case 0x0c0cad44u: goto P_0c0cad44;
case 0x0c0cad46u: goto P_0c0cad46;
case 0x0c0cad48u: goto P_0c0cad48;
case 0x0c0cad4au: goto P_0c0cad4a;
case 0x0c0cad4cu: goto P_0c0cad4c;
case 0x0c0cad4eu: goto P_0c0cad4e;
case 0x0c0cad50u: goto P_0c0cad50;
case 0x0c0cad52u: goto P_0c0cad52;
case 0x0c0cad54u: goto P_0c0cad54;
case 0x0c0cad56u: goto P_0c0cad56;
case 0x0c0cad58u: goto P_0c0cad58;
case 0x0c0cad5au: goto P_0c0cad5a;
case 0x0c0cad5cu: goto P_0c0cad5c;
case 0x0c0cad5eu: goto P_0c0cad5e;
case 0x0c0cad60u: goto P_0c0cad60;
case 0x0c0cad62u: goto P_0c0cad62;
case 0x0c0cad64u: goto P_0c0cad64;
case 0x0c0cad66u: goto P_0c0cad66;
case 0x0c0cad68u: goto P_0c0cad68;
case 0x0c0cad6au: goto P_0c0cad6a;
case 0x0c0cad6cu: goto P_0c0cad6c;
case 0x0c0cad6eu: goto P_0c0cad6e;
case 0x0c0cad70u: goto P_0c0cad70;
case 0x0c0cad72u: goto P_0c0cad72;
case 0x0c0cad74u: goto P_0c0cad74;
case 0x0c0cad76u: goto P_0c0cad76;
case 0x0c0cad78u: goto P_0c0cad78;
case 0x0c0cad7au: goto P_0c0cad7a;
case 0x0c0cad7cu: goto P_0c0cad7c;
case 0x0c0cad7eu: goto P_0c0cad7e;
case 0x0c0cad80u: goto P_0c0cad80;
case 0x0c0cad82u: goto P_0c0cad82;
case 0x0c0cad84u: goto P_0c0cad84;
case 0x0c0cad86u: goto P_0c0cad86;
case 0x0c0cad88u: goto P_0c0cad88;
case 0x0c0cad8au: goto P_0c0cad8a;
case 0x0c0cad8cu: goto P_0c0cad8c;
case 0x0c0cad8eu: goto P_0c0cad8e;
case 0x0c0cad90u: goto P_0c0cad90;
case 0x0c0cad92u: goto P_0c0cad92;
case 0x0c0cad94u: goto P_0c0cad94;
case 0x0c0cad96u: goto P_0c0cad96;
case 0x0c0cad98u: goto P_0c0cad98;
case 0x0c0cad9au: goto P_0c0cad9a;
case 0x0c0cad9cu: goto P_0c0cad9c;
case 0x0c0cad9eu: goto P_0c0cad9e;
case 0x0c0cada0u: goto P_0c0cada0;
case 0x0c0cada2u: goto P_0c0cada2;
case 0x0c0cada4u: goto P_0c0cada4;
case 0x0c0cada6u: goto P_0c0cada6;
case 0x0c0cada8u: goto P_0c0cada8;
case 0x0c0cadaau: goto P_0c0cadaa;
case 0x0c0cadacu: goto P_0c0cadac;
case 0x0c0cadaeu: goto P_0c0cadae;
case 0x0c0cadb0u: goto P_0c0cadb0;
case 0x0c0cadb2u: goto P_0c0cadb2;
case 0x0c0cadb4u: goto P_0c0cadb4;
case 0x0c0cadb6u: goto P_0c0cadb6;
case 0x0c0cadb8u: goto P_0c0cadb8;
case 0x0c0cadbau: goto P_0c0cadba;
case 0x0c0cadbcu: goto P_0c0cadbc;
case 0x0c0cadbeu: goto P_0c0cadbe;
case 0x0c0cadc0u: goto P_0c0cadc0;
case 0x0c0cadc2u: goto P_0c0cadc2;
case 0x0c0cade0u: goto P_0c0cade0;
case 0x0c0cade2u: goto P_0c0cade2;
case 0x0c0cade4u: goto P_0c0cade4;
case 0x0c0cade6u: goto P_0c0cade6;
case 0x0c0cade8u: goto P_0c0cade8;
case 0x0c0cadeau: goto P_0c0cadea;
case 0x0c0cadecu: goto P_0c0cadec;
case 0x0c0cadeeu: goto P_0c0cadee;
case 0x0c0cadf0u: goto P_0c0cadf0;
case 0x0c0cadf2u: goto P_0c0cadf2;
case 0x0c0cadf4u: goto P_0c0cadf4;
case 0x0c0cadf6u: goto P_0c0cadf6;
case 0x0c0cadf8u: goto P_0c0cadf8;
case 0x0c0cadfau: goto P_0c0cadfa;
case 0x0c0cadfcu: goto P_0c0cadfc;
case 0x0c0cadfeu: goto P_0c0cadfe;
case 0x0c0cae00u: goto P_0c0cae00;
case 0x0c0cae02u: goto P_0c0cae02;
case 0x0c0cae04u: goto P_0c0cae04;
case 0x0c0cae06u: goto P_0c0cae06;
case 0x0c0cae08u: goto P_0c0cae08;
case 0x0c0cae0au: goto P_0c0cae0a;
case 0x0c0cae0cu: goto P_0c0cae0c;
case 0x0c0cae0eu: goto P_0c0cae0e;
case 0x0c0cae10u: goto P_0c0cae10;
case 0x0c0cae12u: goto P_0c0cae12;
case 0x0c0cae14u: goto P_0c0cae14;
case 0x0c0cae16u: goto P_0c0cae16;
case 0x0c0cae18u: goto P_0c0cae18;
case 0x0c0cae1au: goto P_0c0cae1a;
case 0x0c0cae1cu: goto P_0c0cae1c;
case 0x0c0cae1eu: goto P_0c0cae1e;
case 0x0c0cae20u: goto P_0c0cae20;
case 0x0c0cae22u: goto P_0c0cae22;
case 0x0c0cae24u: goto P_0c0cae24;
case 0x0c0cae26u: goto P_0c0cae26;
case 0x0c0cae28u: goto P_0c0cae28;
case 0x0c0cae2au: goto P_0c0cae2a;
case 0x0c0cae2cu: goto P_0c0cae2c;
case 0x0c0cae2eu: goto P_0c0cae2e;
case 0x0c0cae30u: goto P_0c0cae30;
case 0x0c0cae32u: goto P_0c0cae32;
case 0x0c0cae34u: goto P_0c0cae34;
case 0x0c0cae36u: goto P_0c0cae36;
case 0x0c0cae38u: goto P_0c0cae38;
case 0x0c0cae3au: goto P_0c0cae3a;
case 0x0c0cae3cu: goto P_0c0cae3c;
case 0x0c0cae3eu: goto P_0c0cae3e;
case 0x0c0cae40u: goto P_0c0cae40;
case 0x0c0cae42u: goto P_0c0cae42;
case 0x0c0cae44u: goto P_0c0cae44;
case 0x0c0cae46u: goto P_0c0cae46;
case 0x0c0cae48u: goto P_0c0cae48;
case 0x0c0cae4au: goto P_0c0cae4a;
case 0x0c0cae4cu: goto P_0c0cae4c;
case 0x0c0cae4eu: goto P_0c0cae4e;
case 0x0c0cae50u: goto P_0c0cae50;
case 0x0c0cae52u: goto P_0c0cae52;
case 0x0c0cae54u: goto P_0c0cae54;
case 0x0c0cae56u: goto P_0c0cae56;
case 0x0c0cae58u: goto P_0c0cae58;
case 0x0c0cae5au: goto P_0c0cae5a;
case 0x0c0cae5cu: goto P_0c0cae5c;
case 0x0c0cae5eu: goto P_0c0cae5e;
case 0x0c0cae60u: goto P_0c0cae60;
case 0x0c0cae62u: goto P_0c0cae62;
case 0x0c0cae64u: goto P_0c0cae64;
case 0x0c0cae66u: goto P_0c0cae66;
case 0x0c0cae68u: goto P_0c0cae68;
case 0x0c0cae6au: goto P_0c0cae6a;
case 0x0c0cae6cu: goto P_0c0cae6c;
case 0x0c0cae6eu: goto P_0c0cae6e;
case 0x0c0cae70u: goto P_0c0cae70;
case 0x0c0cae72u: goto P_0c0cae72;
case 0x0c0cae74u: goto P_0c0cae74;
case 0x0c0cae76u: goto P_0c0cae76;
case 0x0c0cae78u: goto P_0c0cae78;
case 0x0c0cae7au: goto P_0c0cae7a;
case 0x0c0cae7cu: goto P_0c0cae7c;
case 0x0c0cae7eu: goto P_0c0cae7e;
case 0x0c0cae80u: goto P_0c0cae80;
case 0x0c0cae82u: goto P_0c0cae82;
case 0x0c0cae84u: goto P_0c0cae84;
case 0x0c0cae86u: goto P_0c0cae86;
case 0x0c0cae88u: goto P_0c0cae88;
case 0x0c0cae8au: goto P_0c0cae8a;
case 0x0c0cae8cu: goto P_0c0cae8c;
case 0x0c0cae8eu: goto P_0c0cae8e;
case 0x0c0cae90u: goto P_0c0cae90;
case 0x0c0cae92u: goto P_0c0cae92;
case 0x0c0cae94u: goto P_0c0cae94;
case 0x0c0cae96u: goto P_0c0cae96;
case 0x0c0cae98u: goto P_0c0cae98;
case 0x0c0cae9au: goto P_0c0cae9a;
case 0x0c0cae9cu: goto P_0c0cae9c;
case 0x0c0cae9eu: goto P_0c0cae9e;
case 0x0c0caea0u: goto P_0c0caea0;
case 0x0c0caea2u: goto P_0c0caea2;
case 0x0c0caea4u: goto P_0c0caea4;
case 0x0c0caea6u: goto P_0c0caea6;
case 0x0c0caea8u: goto P_0c0caea8;
case 0x0c0caeaau: goto P_0c0caeaa;
case 0x0c0caeacu: goto P_0c0caeac;
case 0x0c0caeaeu: goto P_0c0caeae;
case 0x0c0caeb0u: goto P_0c0caeb0;
case 0x0c0caeb2u: goto P_0c0caeb2;
case 0x0c0caeb4u: goto P_0c0caeb4;
case 0x0c0caeb6u: goto P_0c0caeb6;
case 0x0c0caeb8u: goto P_0c0caeb8;
case 0x0c0caebau: goto P_0c0caeba;
case 0x0c0caebcu: goto P_0c0caebc;
case 0x0c0caebeu: goto P_0c0caebe;
case 0x0c0caec0u: goto P_0c0caec0;
case 0x0c0caec2u: goto P_0c0caec2;
case 0x0c0caec4u: goto P_0c0caec4;
case 0x0c0caec6u: goto P_0c0caec6;
case 0x0c0caec8u: goto P_0c0caec8;
case 0x0c0caecau: goto P_0c0caeca;
case 0x0c0caeccu: goto P_0c0caecc;
case 0x0c0caeceu: goto P_0c0caece;
case 0x0c0caed0u: goto P_0c0caed0;
case 0x0c0caed2u: goto P_0c0caed2;
case 0x0c0caed4u: goto P_0c0caed4;
case 0x0c0caed6u: goto P_0c0caed6;
case 0x0c0caed8u: goto P_0c0caed8;
case 0x0c0caedau: goto P_0c0caeda;
case 0x0c0caedcu: goto P_0c0caedc;
case 0x0c0caedeu: goto P_0c0caede;
case 0x0c0caee0u: goto P_0c0caee0;
case 0x0c0caee2u: goto P_0c0caee2;
case 0x0c0caee4u: goto P_0c0caee4;
case 0x0c0caee6u: goto P_0c0caee6;
case 0x0c0caee8u: goto P_0c0caee8;
case 0x0c0caeeau: goto P_0c0caeea;
case 0x0c0caeecu: goto P_0c0caeec;
case 0x0c0caeeeu: goto P_0c0caeee;
case 0x0c0caef0u: goto P_0c0caef0;
case 0x0c0caef2u: goto P_0c0caef2;
case 0x0c0caf18u: goto P_0c0caf18;
case 0x0c0caf1au: goto P_0c0caf1a;
case 0x0c0caf1cu: goto P_0c0caf1c;
case 0x0c0caf1eu: goto P_0c0caf1e;
case 0x0c0caf20u: goto P_0c0caf20;
case 0x0c0caf22u: goto P_0c0caf22;
case 0x0c0caf24u: goto P_0c0caf24;
case 0x0c0caf26u: goto P_0c0caf26;
case 0x0c0caf28u: goto P_0c0caf28;
case 0x0c0caf2au: goto P_0c0caf2a;
case 0x0c0caf2cu: goto P_0c0caf2c;
case 0x0c0caf2eu: goto P_0c0caf2e;
case 0x0c0caf30u: goto P_0c0caf30;
case 0x0c0caf32u: goto P_0c0caf32;
case 0x0c0caf34u: goto P_0c0caf34;
case 0x0c0caf36u: goto P_0c0caf36;
case 0x0c0caf38u: goto P_0c0caf38;
case 0x0c0caf3au: goto P_0c0caf3a;
case 0x0c0caf3cu: goto P_0c0caf3c;
case 0x0c0caf3eu: goto P_0c0caf3e;
case 0x0c0caf40u: goto P_0c0caf40;
case 0x0c0caf42u: goto P_0c0caf42;
case 0x0c0caf44u: goto P_0c0caf44;
case 0x0c0caf46u: goto P_0c0caf46;
case 0x0c0caf48u: goto P_0c0caf48;
case 0x0c0caf4au: goto P_0c0caf4a;
case 0x0c0caf4cu: goto P_0c0caf4c;
case 0x0c0caf4eu: goto P_0c0caf4e;
case 0x0c0caf50u: goto P_0c0caf50;
case 0x0c0caf52u: goto P_0c0caf52;
case 0x0c0caf54u: goto P_0c0caf54;
case 0x0c0caf56u: goto P_0c0caf56;
case 0x0c0caf58u: goto P_0c0caf58;
case 0x0c0caf5au: goto P_0c0caf5a;
case 0x0c0caf5cu: goto P_0c0caf5c;
case 0x0c0caf5eu: goto P_0c0caf5e;
case 0x0c0caf60u: goto P_0c0caf60;
case 0x0c0caf62u: goto P_0c0caf62;
case 0x0c0caf64u: goto P_0c0caf64;
case 0x0c0caf66u: goto P_0c0caf66;
case 0x0c0caf68u: goto P_0c0caf68;
case 0x0c0caf6au: goto P_0c0caf6a;
case 0x0c0caf6cu: goto P_0c0caf6c;
case 0x0c0caf6eu: goto P_0c0caf6e;
case 0x0c0caf70u: goto P_0c0caf70;
case 0x0c0caf72u: goto P_0c0caf72;
case 0x0c0caf74u: goto P_0c0caf74;
case 0x0c0caf76u: goto P_0c0caf76;
case 0x0c0caf78u: goto P_0c0caf78;
case 0x0c0caf7au: goto P_0c0caf7a;
case 0x0c0caf7cu: goto P_0c0caf7c;
case 0x0c0caf7eu: goto P_0c0caf7e;
case 0x0c0caf80u: goto P_0c0caf80;
case 0x0c0caf82u: goto P_0c0caf82;
case 0x0c0caf84u: goto P_0c0caf84;
case 0x0c0caf86u: goto P_0c0caf86;
case 0x0c0caf88u: goto P_0c0caf88;
case 0x0c0caf8au: goto P_0c0caf8a;
case 0x0c0caf8cu: goto P_0c0caf8c;
case 0x0c0caf8eu: goto P_0c0caf8e;
case 0x0c0caf90u: goto P_0c0caf90;
case 0x0c0caf92u: goto P_0c0caf92;
case 0x0c0caf94u: goto P_0c0caf94;
case 0x0c0caf96u: goto P_0c0caf96;
case 0x0c0caf98u: goto P_0c0caf98;
case 0x0c0caf9au: goto P_0c0caf9a;
case 0x0c0caf9cu: goto P_0c0caf9c;
case 0x0c0caf9eu: goto P_0c0caf9e;
case 0x0c0cafa0u: goto P_0c0cafa0;
case 0x0c0cafa2u: goto P_0c0cafa2;
case 0x0c0cafa4u: goto P_0c0cafa4;
case 0x0c0cafa6u: goto P_0c0cafa6;
case 0x0c0cafa8u: goto P_0c0cafa8;
case 0x0c0cafaau: goto P_0c0cafaa;
case 0x0c0cafacu: goto P_0c0cafac;
case 0x0c0cafaeu: goto P_0c0cafae;
case 0x0c0cafb0u: goto P_0c0cafb0;
case 0x0c0cafb2u: goto P_0c0cafb2;
case 0x0c0cafb4u: goto P_0c0cafb4;
case 0x0c0cafb6u: goto P_0c0cafb6;
case 0x0c0cafb8u: goto P_0c0cafb8;
case 0x0c0cafbau: goto P_0c0cafba;
case 0x0c0cafbcu: goto P_0c0cafbc;
case 0x0c0cafbeu: goto P_0c0cafbe;
case 0x0c0cafc0u: goto P_0c0cafc0;
case 0x0c0cafc2u: goto P_0c0cafc2;
case 0x0c0cafc4u: goto P_0c0cafc4;
case 0x0c0cafc6u: goto P_0c0cafc6;
case 0x0c0cafc8u: goto P_0c0cafc8;
case 0x0c0cafcau: goto P_0c0cafca;
case 0x0c0cafccu: goto P_0c0cafcc;
case 0x0c0cafceu: goto P_0c0cafce;
case 0x0c0cafd0u: goto P_0c0cafd0;
case 0x0c0cafd2u: goto P_0c0cafd2;
case 0x0c0cafd4u: goto P_0c0cafd4;
case 0x0c0cafd6u: goto P_0c0cafd6;
case 0x0c0cafd8u: goto P_0c0cafd8;
case 0x0c0cafdau: goto P_0c0cafda;
case 0x0c0cafdcu: goto P_0c0cafdc;
case 0x0c0cafdeu: goto P_0c0cafde;
case 0x0c0cafe0u: goto P_0c0cafe0;
case 0x0c0cafe2u: goto P_0c0cafe2;
case 0x0c0cafe4u: goto P_0c0cafe4;
case 0x0c0cafe6u: goto P_0c0cafe6;
case 0x0c0cafe8u: goto P_0c0cafe8;
case 0x0c0cafeau: goto P_0c0cafea;
case 0x0c0cafecu: goto P_0c0cafec;
case 0x0c0cafeeu: goto P_0c0cafee;
case 0x0c0caff0u: goto P_0c0caff0;
case 0x0c0caff2u: goto P_0c0caff2;
case 0x0c0caff4u: goto P_0c0caff4;
case 0x0c0caff6u: goto P_0c0caff6;
case 0x0c0caff8u: goto P_0c0caff8;
case 0x0c0caffau: goto P_0c0caffa;
case 0x0c0caffcu: goto P_0c0caffc;
case 0x0c0caffeu: goto P_0c0caffe;
case 0x0c0cb000u: goto P_0c0cb000;
case 0x0c0cb002u: goto P_0c0cb002;
case 0x0c0cb004u: goto P_0c0cb004;
case 0x0c0cb006u: goto P_0c0cb006;
case 0x0c0cb008u: goto P_0c0cb008;
case 0x0c0cb00au: goto P_0c0cb00a;
case 0x0c0cb00cu: goto P_0c0cb00c;
case 0x0c0cb00eu: goto P_0c0cb00e;
case 0x0c0cb010u: goto P_0c0cb010;
case 0x0c0cb012u: goto P_0c0cb012;
case 0x0c0cb014u: goto P_0c0cb014;
case 0x0c0cb016u: goto P_0c0cb016;
case 0x0c0cb018u: goto P_0c0cb018;
case 0x0c0cb01au: goto P_0c0cb01a;
case 0x0c0cb01cu: goto P_0c0cb01c;
case 0x0c0cb01eu: goto P_0c0cb01e;
case 0x0c0cb020u: goto P_0c0cb020;
case 0x0c0cb022u: goto P_0c0cb022;
case 0x0c0cb024u: goto P_0c0cb024;
case 0x0c0cb026u: goto P_0c0cb026;
case 0x0c0cb028u: goto P_0c0cb028;
case 0x0c0cb02au: goto P_0c0cb02a;
case 0x0c0cb02cu: goto P_0c0cb02c;
case 0x0c0cb02eu: goto P_0c0cb02e;
case 0x0c0cb050u: goto P_0c0cb050;
case 0x0c0cb052u: goto P_0c0cb052;
case 0x0c0cb054u: goto P_0c0cb054;
case 0x0c0cb056u: goto P_0c0cb056;
case 0x0c0cb058u: goto P_0c0cb058;
case 0x0c0cb05au: goto P_0c0cb05a;
case 0x0c0cb05cu: goto P_0c0cb05c;
case 0x0c0cb05eu: goto P_0c0cb05e;
case 0x0c0cb060u: goto P_0c0cb060;
case 0x0c0cb062u: goto P_0c0cb062;
case 0x0c0cb064u: goto P_0c0cb064;
case 0x0c0cb066u: goto P_0c0cb066;
case 0x0c0cb068u: goto P_0c0cb068;
case 0x0c0cb06au: goto P_0c0cb06a;
case 0x0c0cb06cu: goto P_0c0cb06c;
case 0x0c0cb06eu: goto P_0c0cb06e;
case 0x0c0cb070u: goto P_0c0cb070;
case 0x0c0cb072u: goto P_0c0cb072;
case 0x0c0cb074u: goto P_0c0cb074;
case 0x0c0cb076u: goto P_0c0cb076;
case 0x0c0cb078u: goto P_0c0cb078;
case 0x0c0cb07au: goto P_0c0cb07a;
case 0x0c0cb07cu: goto P_0c0cb07c;
case 0x0c0cb07eu: goto P_0c0cb07e;
case 0x0c0cb080u: goto P_0c0cb080;
case 0x0c0cb082u: goto P_0c0cb082;
case 0x0c0cb084u: goto P_0c0cb084;
case 0x0c0cb086u: goto P_0c0cb086;
case 0x0c0cb088u: goto P_0c0cb088;
case 0x0c0cb08au: goto P_0c0cb08a;
case 0x0c0cb08cu: goto P_0c0cb08c;
case 0x0c0cb08eu: goto P_0c0cb08e;
case 0x0c0cb090u: goto P_0c0cb090;
case 0x0c0cb092u: goto P_0c0cb092;
case 0x0c0cb094u: goto P_0c0cb094;
case 0x0c0cb096u: goto P_0c0cb096;
case 0x0c0cb098u: goto P_0c0cb098;
case 0x0c0cb09au: goto P_0c0cb09a;
case 0x0c0cb09cu: goto P_0c0cb09c;
case 0x0c0cb09eu: goto P_0c0cb09e;
case 0x0c0cb0a0u: goto P_0c0cb0a0;
case 0x0c0cb0a2u: goto P_0c0cb0a2;
case 0x0c0cb0a4u: goto P_0c0cb0a4;
case 0x0c0cb0a6u: goto P_0c0cb0a6;
case 0x0c0cb0a8u: goto P_0c0cb0a8;
case 0x0c0cb0aau: goto P_0c0cb0aa;
case 0x0c0cb0acu: goto P_0c0cb0ac;
case 0x0c0cb0aeu: goto P_0c0cb0ae;
case 0x0c0cb0b0u: goto P_0c0cb0b0;
case 0x0c0cb0b2u: goto P_0c0cb0b2;
case 0x0c0cb0b4u: goto P_0c0cb0b4;
case 0x0c0cb0b6u: goto P_0c0cb0b6;
case 0x0c0cb0b8u: goto P_0c0cb0b8;
case 0x0c0cb0bau: goto P_0c0cb0ba;
case 0x0c0cb0bcu: goto P_0c0cb0bc;
case 0x0c0cb0beu: goto P_0c0cb0be;
case 0x0c0cb0c0u: goto P_0c0cb0c0;
case 0x0c0cb0c2u: goto P_0c0cb0c2;
case 0x0c0cb0c4u: goto P_0c0cb0c4;
case 0x0c0cb0c6u: goto P_0c0cb0c6;
case 0x0c0cb0c8u: goto P_0c0cb0c8;
case 0x0c0cb0cau: goto P_0c0cb0ca;
case 0x0c0cb0ccu: goto P_0c0cb0cc;
case 0x0c0cb0ceu: goto P_0c0cb0ce;
case 0x0c0cb0d0u: goto P_0c0cb0d0;
case 0x0c0cb0d2u: goto P_0c0cb0d2;
case 0x0c0cb0d4u: goto P_0c0cb0d4;
case 0x0c0cb0d6u: goto P_0c0cb0d6;
case 0x0c0cb0d8u: goto P_0c0cb0d8;
case 0x0c0cb0dau: goto P_0c0cb0da;
case 0x0c0cb0dcu: goto P_0c0cb0dc;
case 0x0c0cb0deu: goto P_0c0cb0de;
case 0x0c0cb0e0u: goto P_0c0cb0e0;
case 0x0c0cb0e2u: goto P_0c0cb0e2;
case 0x0c0cb0e4u: goto P_0c0cb0e4;
case 0x0c0cb0e6u: goto P_0c0cb0e6;
case 0x0c0cb0e8u: goto P_0c0cb0e8;
case 0x0c0cb0eau: goto P_0c0cb0ea;
case 0x0c0cb114u: goto P_0c0cb114;
case 0x0c0cb116u: goto P_0c0cb116;
case 0x0c0cb118u: goto P_0c0cb118;
case 0x0c0cb11au: goto P_0c0cb11a;
case 0x0c0cb11cu: goto P_0c0cb11c;
case 0x0c0cb11eu: goto P_0c0cb11e;
case 0x0c0cb120u: goto P_0c0cb120;
case 0x0c0cb122u: goto P_0c0cb122;
case 0x0c0cb124u: goto P_0c0cb124;
case 0x0c0cb126u: goto P_0c0cb126;
case 0x0c0cb128u: goto P_0c0cb128;
case 0x0c0cb12au: goto P_0c0cb12a;
case 0x0c0cb12cu: goto P_0c0cb12c;
case 0x0c0cb12eu: goto P_0c0cb12e;
case 0x0c0cb130u: goto P_0c0cb130;
case 0x0c0cb132u: goto P_0c0cb132;
case 0x0c0cb134u: goto P_0c0cb134;
case 0x0c0cb136u: goto P_0c0cb136;
case 0x0c0cb138u: goto P_0c0cb138;
case 0x0c0cb13au: goto P_0c0cb13a;
case 0x0c0cb13cu: goto P_0c0cb13c;
case 0x0c0cb13eu: goto P_0c0cb13e;
case 0x0c0cb140u: goto P_0c0cb140;
case 0x0c0cb142u: goto P_0c0cb142;
case 0x0c0cb144u: goto P_0c0cb144;
case 0x0c0cb146u: goto P_0c0cb146;
case 0x0c0cb148u: goto P_0c0cb148;
case 0x0c0cb14au: goto P_0c0cb14a;
case 0x0c0cb14cu: goto P_0c0cb14c;
case 0x0c0cb14eu: goto P_0c0cb14e;
case 0x0c0cb150u: goto P_0c0cb150;
case 0x0c0cb152u: goto P_0c0cb152;
case 0x0c0cb154u: goto P_0c0cb154;
case 0x0c0cb156u: goto P_0c0cb156;
case 0x0c0cb158u: goto P_0c0cb158;
case 0x0c0cb15au: goto P_0c0cb15a;
case 0x0c0cb15cu: goto P_0c0cb15c;
case 0x0c0cb15eu: goto P_0c0cb15e;
case 0x0c0cb160u: goto P_0c0cb160;
case 0x0c0cb162u: goto P_0c0cb162;
case 0x0c0cb164u: goto P_0c0cb164;
case 0x0c0cb166u: goto P_0c0cb166;
case 0x0c0cb168u: goto P_0c0cb168;
case 0x0c0cb16au: goto P_0c0cb16a;
case 0x0c0cb16cu: goto P_0c0cb16c;
case 0x0c0cb16eu: goto P_0c0cb16e;
case 0x0c0cb170u: goto P_0c0cb170;
case 0x0c0cb172u: goto P_0c0cb172;
case 0x0c0cb174u: goto P_0c0cb174;
case 0x0c0cb176u: goto P_0c0cb176;
case 0x0c0cb178u: goto P_0c0cb178;
case 0x0c0cb17au: goto P_0c0cb17a;
case 0x0c0cb17cu: goto P_0c0cb17c;
case 0x0c0cb17eu: goto P_0c0cb17e;
case 0x0c0cb180u: goto P_0c0cb180;
case 0x0c0cb182u: goto P_0c0cb182;
case 0x0c0cb184u: goto P_0c0cb184;
case 0x0c0cb186u: goto P_0c0cb186;
case 0x0c0cb188u: goto P_0c0cb188;
case 0x0c0cb18au: goto P_0c0cb18a;
case 0x0c0cb18cu: goto P_0c0cb18c;
case 0x0c0cb18eu: goto P_0c0cb18e;
case 0x0c0cb190u: goto P_0c0cb190;
case 0x0c0cb192u: goto P_0c0cb192;
case 0x0c0cb194u: goto P_0c0cb194;
case 0x0c0cb196u: goto P_0c0cb196;
case 0x0c0cb198u: goto P_0c0cb198;
case 0x0c0cb19au: goto P_0c0cb19a;
case 0x0c0cb19cu: goto P_0c0cb19c;
case 0x0c0cb19eu: goto P_0c0cb19e;
case 0x0c0cb1a0u: goto P_0c0cb1a0;
case 0x0c0cb1a2u: goto P_0c0cb1a2;
case 0x0c0cb1a4u: goto P_0c0cb1a4;
case 0x0c0cb1a6u: goto P_0c0cb1a6;
case 0x0c0cb1a8u: goto P_0c0cb1a8;
case 0x0c0cb1aau: goto P_0c0cb1aa;
case 0x0c0cb1acu: goto P_0c0cb1ac;
case 0x0c0cb1aeu: goto P_0c0cb1ae;
case 0x0c0cb1b0u: goto P_0c0cb1b0;
case 0x0c0cb1b2u: goto P_0c0cb1b2;
case 0x0c0cb1b4u: goto P_0c0cb1b4;
case 0x0c0cb1b6u: goto P_0c0cb1b6;
case 0x0c0cb1b8u: goto P_0c0cb1b8;
case 0x0c0cb1bau: goto P_0c0cb1ba;
case 0x0c0cb1bcu: goto P_0c0cb1bc;
case 0x0c0cb1beu: goto P_0c0cb1be;
case 0x0c0cb1c0u: goto P_0c0cb1c0;
case 0x0c0cb1c2u: goto P_0c0cb1c2;
case 0x0c0cb1c4u: goto P_0c0cb1c4;
case 0x0c0cb1c6u: goto P_0c0cb1c6;
case 0x0c0cb1c8u: goto P_0c0cb1c8;
case 0x0c0cb1cau: goto P_0c0cb1ca;
case 0x0c0cb1ccu: goto P_0c0cb1cc;
case 0x0c0cb1ceu: goto P_0c0cb1ce;
case 0x0c0cb1d0u: goto P_0c0cb1d0;
case 0x0c0cb1d2u: goto P_0c0cb1d2;
case 0x0c0cb1d4u: goto P_0c0cb1d4;
case 0x0c0cb1d6u: goto P_0c0cb1d6;
case 0x0c0cb1d8u: goto P_0c0cb1d8;
case 0x0c0cb1dau: goto P_0c0cb1da;
case 0x0c0cb1dcu: goto P_0c0cb1dc;
case 0x0c0cb1deu: goto P_0c0cb1de;
case 0x0c0cb1e0u: goto P_0c0cb1e0;
case 0x0c0cb1e2u: goto P_0c0cb1e2;
case 0x0c0cb1e4u: goto P_0c0cb1e4;
case 0x0c0cb1e6u: goto P_0c0cb1e6;
case 0x0c0cb1e8u: goto P_0c0cb1e8;
case 0x0c0cb1eau: goto P_0c0cb1ea;
case 0x0c0cb1ecu: goto P_0c0cb1ec;
case 0x0c0cb1eeu: goto P_0c0cb1ee;
case 0x0c0cb1f0u: goto P_0c0cb1f0;
case 0x0c0cb1f2u: goto P_0c0cb1f2;
case 0x0c0cb1f4u: goto P_0c0cb1f4;
case 0x0c0cb1f6u: goto P_0c0cb1f6;
case 0x0c0cb1f8u: goto P_0c0cb1f8;
case 0x0c0cb1fau: goto P_0c0cb1fa;
case 0x0c0cb1fcu: goto P_0c0cb1fc;
case 0x0c0cb1feu: goto P_0c0cb1fe;
case 0x0c0cb200u: goto P_0c0cb200;
case 0x0c0cb202u: goto P_0c0cb202;
case 0x0c0cb204u: goto P_0c0cb204;
case 0x0c0cb206u: goto P_0c0cb206;
case 0x0c0cb208u: goto P_0c0cb208;
case 0x0c0cb20au: goto P_0c0cb20a;
case 0x0c0cb20cu: goto P_0c0cb20c;
case 0x0c0cb20eu: goto P_0c0cb20e;
case 0x0c0cb210u: goto P_0c0cb210;
case 0x0c0cb212u: goto P_0c0cb212;
case 0x0c0cb214u: goto P_0c0cb214;
case 0x0c0cb216u: goto P_0c0cb216;
case 0x0c0cb218u: goto P_0c0cb218;
case 0x0c0cb244u: goto P_0c0cb244;
case 0x0c0cb246u: goto P_0c0cb246;
case 0x0c0cb248u: goto P_0c0cb248;
case 0x0c0cb24au: goto P_0c0cb24a;
case 0x0c0cb24cu: goto P_0c0cb24c;
case 0x0c0cb24eu: goto P_0c0cb24e;
case 0x0c0cb250u: goto P_0c0cb250;
case 0x0c0cb252u: goto P_0c0cb252;
case 0x0c0cb254u: goto P_0c0cb254;
case 0x0c0cb256u: goto P_0c0cb256;
case 0x0c0cb258u: goto P_0c0cb258;
case 0x0c0cb25au: goto P_0c0cb25a;
case 0x0c0cb25cu: goto P_0c0cb25c;
case 0x0c0cb25eu: goto P_0c0cb25e;
case 0x0c0cb260u: goto P_0c0cb260;
case 0x0c0cb262u: goto P_0c0cb262;
case 0x0c0cb264u: goto P_0c0cb264;
case 0x0c0cb266u: goto P_0c0cb266;
case 0x0c0cb268u: goto P_0c0cb268;
case 0x0c0cb26au: goto P_0c0cb26a;
case 0x0c0cb26cu: goto P_0c0cb26c;
case 0x0c0cb26eu: goto P_0c0cb26e;
case 0x0c0cb270u: goto P_0c0cb270;
case 0x0c0cb272u: goto P_0c0cb272;
case 0x0c0cb274u: goto P_0c0cb274;
case 0x0c0cb276u: goto P_0c0cb276;
case 0x0c0cb278u: goto P_0c0cb278;
case 0x0c0cb27au: goto P_0c0cb27a;
case 0x0c0cb27cu: goto P_0c0cb27c;
case 0x0c0cb27eu: goto P_0c0cb27e;
case 0x0c0cb280u: goto P_0c0cb280;
case 0x0c0cb282u: goto P_0c0cb282;
case 0x0c0cb284u: goto P_0c0cb284;
case 0x0c0cb286u: goto P_0c0cb286;
case 0x0c0cb288u: goto P_0c0cb288;
case 0x0c0cb28au: goto P_0c0cb28a;
case 0x0c0cb28cu: goto P_0c0cb28c;
case 0x0c0cb28eu: goto P_0c0cb28e;
case 0x0c0cb290u: goto P_0c0cb290;
case 0x0c0cb292u: goto P_0c0cb292;
case 0x0c0cb294u: goto P_0c0cb294;
case 0x0c0cb296u: goto P_0c0cb296;
case 0x0c0cb298u: goto P_0c0cb298;
case 0x0c0cb29au: goto P_0c0cb29a;
case 0x0c0cb29cu: goto P_0c0cb29c;
case 0x0c0cb29eu: goto P_0c0cb29e;
case 0x0c0cb2a0u: goto P_0c0cb2a0;
case 0x0c0cb2a2u: goto P_0c0cb2a2;
case 0x0c0cb2a4u: goto P_0c0cb2a4;
case 0x0c0cb2a6u: goto P_0c0cb2a6;
case 0x0c0cb2a8u: goto P_0c0cb2a8;
case 0x0c0cb2aau: goto P_0c0cb2aa;
case 0x0c0cb2acu: goto P_0c0cb2ac;
case 0x0c0cb2aeu: goto P_0c0cb2ae;
case 0x0c0cb2b0u: goto P_0c0cb2b0;
case 0x0c0cb2b2u: goto P_0c0cb2b2;
case 0x0c0cb2b4u: goto P_0c0cb2b4;
case 0x0c0cb2b6u: goto P_0c0cb2b6;
case 0x0c0cb2b8u: goto P_0c0cb2b8;
case 0x0c0cb2bau: goto P_0c0cb2ba;
case 0x0c0cb2bcu: goto P_0c0cb2bc;
case 0x0c0cb2beu: goto P_0c0cb2be;
case 0x0c0cb2c0u: goto P_0c0cb2c0;
case 0x0c0cb2c2u: goto P_0c0cb2c2;
case 0x0c0cb2c4u: goto P_0c0cb2c4;
case 0x0c0cb2c6u: goto P_0c0cb2c6;
case 0x0c0cb2c8u: goto P_0c0cb2c8;
case 0x0c0cb2cau: goto P_0c0cb2ca;
case 0x0c0cb2ccu: goto P_0c0cb2cc;
case 0x0c0cb2ceu: goto P_0c0cb2ce;
case 0x0c0cb2d0u: goto P_0c0cb2d0;
case 0x0c0cb2d2u: goto P_0c0cb2d2;
case 0x0c0cb2d4u: goto P_0c0cb2d4;
case 0x0c0cb2d6u: goto P_0c0cb2d6;
case 0x0c0cb2d8u: goto P_0c0cb2d8;
case 0x0c0cb2dau: goto P_0c0cb2da;
case 0x0c0cb2dcu: goto P_0c0cb2dc;
case 0x0c0cb2deu: goto P_0c0cb2de;
case 0x0c0cb2e0u: goto P_0c0cb2e0;
case 0x0c0cb2e2u: goto P_0c0cb2e2;
case 0x0c0cb2e4u: goto P_0c0cb2e4;
case 0x0c0cb2e6u: goto P_0c0cb2e6;
case 0x0c0cb2e8u: goto P_0c0cb2e8;
case 0x0c0cb2eau: goto P_0c0cb2ea;
case 0x0c0cb2ecu: goto P_0c0cb2ec;
case 0x0c0cb2eeu: goto P_0c0cb2ee;
case 0x0c0cb2f0u: goto P_0c0cb2f0;
case 0x0c0cb2f2u: goto P_0c0cb2f2;
case 0x0c0cb2f4u: goto P_0c0cb2f4;
case 0x0c0cb2f6u: goto P_0c0cb2f6;
case 0x0c0cb2f8u: goto P_0c0cb2f8;
case 0x0c0cb2fau: goto P_0c0cb2fa;
case 0x0c0cb2fcu: goto P_0c0cb2fc;
case 0x0c0cb2feu: goto P_0c0cb2fe;
case 0x0c0cb300u: goto P_0c0cb300;
case 0x0c0cb302u: goto P_0c0cb302;
case 0x0c0cb304u: goto P_0c0cb304;
case 0x0c0cb306u: goto P_0c0cb306;
case 0x0c0cb308u: goto P_0c0cb308;
case 0x0c0cb30au: goto P_0c0cb30a;
case 0x0c0cb30cu: goto P_0c0cb30c;
case 0x0c0cb30eu: goto P_0c0cb30e;
case 0x0c0cb310u: goto P_0c0cb310;
case 0x0c0cb312u: goto P_0c0cb312;
case 0x0c0cb314u: goto P_0c0cb314;
case 0x0c0cb316u: goto P_0c0cb316;
case 0x0c0cb318u: goto P_0c0cb318;
case 0x0c0cb31au: goto P_0c0cb31a;
case 0x0c0cb31cu: goto P_0c0cb31c;
case 0x0c0cb31eu: goto P_0c0cb31e;
case 0x0c0cb320u: goto P_0c0cb320;
case 0x0c0cb322u: goto P_0c0cb322;
case 0x0c0cb324u: goto P_0c0cb324;
case 0x0c0cb326u: goto P_0c0cb326;
case 0x0c0cb328u: goto P_0c0cb328;
case 0x0c0cb32au: goto P_0c0cb32a;
case 0x0c0cb32cu: goto P_0c0cb32c;
case 0x0c0cb32eu: goto P_0c0cb32e;
case 0x0c0cb330u: goto P_0c0cb330;
case 0x0c0cb332u: goto P_0c0cb332;
case 0x0c0cb334u: goto P_0c0cb334;
case 0x0c0cb336u: goto P_0c0cb336;
case 0x0c0cb338u: goto P_0c0cb338;
case 0x0c0cb34cu: goto P_0c0cb34c;
case 0x0c0cb34eu: goto P_0c0cb34e;
case 0x0c0cb350u: goto P_0c0cb350;
case 0x0c0cb352u: goto P_0c0cb352;
case 0x0c0cb354u: goto P_0c0cb354;
case 0x0c0cb356u: goto P_0c0cb356;
case 0x0c0cb358u: goto P_0c0cb358;
case 0x0c0cb35au: goto P_0c0cb35a;
case 0x0c0cb35cu: goto P_0c0cb35c;
case 0x0c0cb35eu: goto P_0c0cb35e;
case 0x0c0cb360u: goto P_0c0cb360;
case 0x0c0cb362u: goto P_0c0cb362;
case 0x0c0cb364u: goto P_0c0cb364;
case 0x0c0cb366u: goto P_0c0cb366;
case 0x0c0cb368u: goto P_0c0cb368;
case 0x0c0cb36au: goto P_0c0cb36a;
case 0x0c0cb36cu: goto P_0c0cb36c;
case 0x0c0cb36eu: goto P_0c0cb36e;
case 0x0c0cb370u: goto P_0c0cb370;
case 0x0c0cb372u: goto P_0c0cb372;
case 0x0c0cb374u: goto P_0c0cb374;
case 0x0c0cb376u: goto P_0c0cb376;
case 0x0c0cb378u: goto P_0c0cb378;
case 0x0c0cb37au: goto P_0c0cb37a;
case 0x0c0cb37cu: goto P_0c0cb37c;
case 0x0c0cb37eu: goto P_0c0cb37e;
case 0x0c0cb380u: goto P_0c0cb380;
case 0x0c0cb382u: goto P_0c0cb382;
case 0x0c0cb384u: goto P_0c0cb384;
case 0x0c0cb386u: goto P_0c0cb386;
case 0x0c0cb388u: goto P_0c0cb388;
case 0x0c0cb38au: goto P_0c0cb38a;
case 0x0c0cb38cu: goto P_0c0cb38c;
case 0x0c0cb38eu: goto P_0c0cb38e;
case 0x0c0cb390u: goto P_0c0cb390;
case 0x0c0cb392u: goto P_0c0cb392;
case 0x0c0cb394u: goto P_0c0cb394;
case 0x0c0cb396u: goto P_0c0cb396;
case 0x0c0cb398u: goto P_0c0cb398;
case 0x0c0cb39au: goto P_0c0cb39a;
case 0x0c0cb39cu: goto P_0c0cb39c;
case 0x0c0cb39eu: goto P_0c0cb39e;
case 0x0c0cb3a0u: goto P_0c0cb3a0;
case 0x0c0cb3a2u: goto P_0c0cb3a2;
case 0x0c0cb3a4u: goto P_0c0cb3a4;
case 0x0c0cb3a6u: goto P_0c0cb3a6;
case 0x0c0cb3a8u: goto P_0c0cb3a8;
case 0x0c0cb3aau: goto P_0c0cb3aa;
case 0x0c0cb3acu: goto P_0c0cb3ac;
case 0x0c0cb3aeu: goto P_0c0cb3ae;
case 0x0c0cb3b0u: goto P_0c0cb3b0;
case 0x0c0cb3b2u: goto P_0c0cb3b2;
case 0x0c0cb3b4u: goto P_0c0cb3b4;
case 0x0c0cb3b6u: goto P_0c0cb3b6;
case 0x0c0cb3b8u: goto P_0c0cb3b8;
case 0x0c0cb3bau: goto P_0c0cb3ba;
case 0x0c0cb3bcu: goto P_0c0cb3bc;
case 0x0c0cb3beu: goto P_0c0cb3be;
case 0x0c0cb3c0u: goto P_0c0cb3c0;
case 0x0c0cb3c2u: goto P_0c0cb3c2;
case 0x0c0cb3c4u: goto P_0c0cb3c4;
case 0x0c0cb3c6u: goto P_0c0cb3c6;
case 0x0c0cb3c8u: goto P_0c0cb3c8;
case 0x0c0cb3cau: goto P_0c0cb3ca;
case 0x0c0cb3ccu: goto P_0c0cb3cc;
case 0x0c0cb3ceu: goto P_0c0cb3ce;
case 0x0c0cb3d0u: goto P_0c0cb3d0;
case 0x0c0cb3d2u: goto P_0c0cb3d2;
case 0x0c0cb3d4u: goto P_0c0cb3d4;
case 0x0c0cb3d6u: goto P_0c0cb3d6;
case 0x0c0cb3d8u: goto P_0c0cb3d8;
case 0x0c0cb3dau: goto P_0c0cb3da;
case 0x0c0cb3dcu: goto P_0c0cb3dc;
case 0x0c0cb3deu: goto P_0c0cb3de;
case 0x0c0cb3e0u: goto P_0c0cb3e0;
case 0x0c0cb3e2u: goto P_0c0cb3e2;
case 0x0c0cb3e4u: goto P_0c0cb3e4;
case 0x0c0cb3e6u: goto P_0c0cb3e6;
case 0x0c0cb3e8u: goto P_0c0cb3e8;
case 0x0c0cb3eau: goto P_0c0cb3ea;
case 0x0c0cb3ecu: goto P_0c0cb3ec;
case 0x0c0cb3eeu: goto P_0c0cb3ee;
case 0x0c0cb3f0u: goto P_0c0cb3f0;
case 0x0c0cb3f2u: goto P_0c0cb3f2;
case 0x0c0cb3f4u: goto P_0c0cb3f4;
case 0x0c0cb3f6u: goto P_0c0cb3f6;
case 0x0c0cb3f8u: goto P_0c0cb3f8;
case 0x0c0cb3fau: goto P_0c0cb3fa;
case 0x0c0cb3fcu: goto P_0c0cb3fc;
case 0x0c0cb3feu: goto P_0c0cb3fe;
case 0x0c0cb400u: goto P_0c0cb400;
case 0x0c0cb402u: goto P_0c0cb402;
case 0x0c0cb404u: goto P_0c0cb404;
case 0x0c0cb406u: goto P_0c0cb406;
case 0x0c0cb408u: goto P_0c0cb408;
case 0x0c0cb40au: goto P_0c0cb40a;
case 0x0c0cb40cu: goto P_0c0cb40c;
case 0x0c0cb40eu: goto P_0c0cb40e;
case 0x0c0cb410u: goto P_0c0cb410;
case 0x0c0cb412u: goto P_0c0cb412;
case 0x0c0cb414u: goto P_0c0cb414;
case 0x0c0cb416u: goto P_0c0cb416;
case 0x0c0cb418u: goto P_0c0cb418;
case 0x0c0cb41au: goto P_0c0cb41a;
case 0x0c0cb41cu: goto P_0c0cb41c;
case 0x0c0cb41eu: goto P_0c0cb41e;
case 0x0c0cb420u: goto P_0c0cb420;
case 0x0c0cb422u: goto P_0c0cb422;
case 0x0c0cb424u: goto P_0c0cb424;
case 0x0c0cb426u: goto P_0c0cb426;
case 0x0c0cb428u: goto P_0c0cb428;
case 0x0c0cb42au: goto P_0c0cb42a;
case 0x0c0cb42cu: goto P_0c0cb42c;
case 0x0c0cb42eu: goto P_0c0cb42e;
case 0x0c0cb430u: goto P_0c0cb430;
case 0x0c0cb432u: goto P_0c0cb432;
case 0x0c0cb434u: goto P_0c0cb434;
case 0x0c0cb436u: goto P_0c0cb436;
case 0x0c0cb438u: goto P_0c0cb438;
case 0x0c0cb43au: goto P_0c0cb43a;
case 0x0c0cb43cu: goto P_0c0cb43c;
case 0x0c0cb43eu: goto P_0c0cb43e;
case 0x0c0cb440u: goto P_0c0cb440;
case 0x0c0cb442u: goto P_0c0cb442;
case 0x0c0cb444u: goto P_0c0cb444;
case 0x0c0cb446u: goto P_0c0cb446;
case 0x0c0cb448u: goto P_0c0cb448;
case 0x0c0cb44au: goto P_0c0cb44a;
case 0x0c0cb44cu: goto P_0c0cb44c;
case 0x0c0cb44eu: goto P_0c0cb44e;
case 0x0c0cb450u: goto P_0c0cb450;
case 0x0c0cb452u: goto P_0c0cb452;
case 0x0c0cb454u: goto P_0c0cb454;
case 0x0c0cb456u: goto P_0c0cb456;
case 0x0c0cb458u: goto P_0c0cb458;
case 0x0c0cb45au: goto P_0c0cb45a;
case 0x0c0cb45cu: goto P_0c0cb45c;
case 0x0c0cb48cu: goto P_0c0cb48c;
case 0x0c0cb48eu: goto P_0c0cb48e;
case 0x0c0cb490u: goto P_0c0cb490;
case 0x0c0cb492u: goto P_0c0cb492;
case 0x0c0cb494u: goto P_0c0cb494;
case 0x0c0cb496u: goto P_0c0cb496;
case 0x0c0cb498u: goto P_0c0cb498;
case 0x0c0cb49au: goto P_0c0cb49a;
case 0x0c0cb49cu: goto P_0c0cb49c;
case 0x0c0cb49eu: goto P_0c0cb49e;
case 0x0c0cb4a0u: goto P_0c0cb4a0;
case 0x0c0cb4a2u: goto P_0c0cb4a2;
case 0x0c0cb4a4u: goto P_0c0cb4a4;
case 0x0c0cb4a6u: goto P_0c0cb4a6;
case 0x0c0cb4a8u: goto P_0c0cb4a8;
case 0x0c0cb4aau: goto P_0c0cb4aa;
case 0x0c0cb4acu: goto P_0c0cb4ac;
case 0x0c0cb4aeu: goto P_0c0cb4ae;
case 0x0c0cb4b0u: goto P_0c0cb4b0;
case 0x0c0cb4b2u: goto P_0c0cb4b2;
case 0x0c0cb4b4u: goto P_0c0cb4b4;
case 0x0c0cb4b6u: goto P_0c0cb4b6;
case 0x0c0cb4b8u: goto P_0c0cb4b8;
case 0x0c0cb4bau: goto P_0c0cb4ba;
case 0x0c0cb4bcu: goto P_0c0cb4bc;
case 0x0c0cb4beu: goto P_0c0cb4be;
case 0x0c0cb4c0u: goto P_0c0cb4c0;
case 0x0c0cb4c2u: goto P_0c0cb4c2;
case 0x0c0cb4c4u: goto P_0c0cb4c4;
case 0x0c0cb4c6u: goto P_0c0cb4c6;
case 0x0c0cb4c8u: goto P_0c0cb4c8;
case 0x0c0cb4cau: goto P_0c0cb4ca;
case 0x0c0cb4ccu: goto P_0c0cb4cc;
case 0x0c0cb4ceu: goto P_0c0cb4ce;
case 0x0c0cb4d0u: goto P_0c0cb4d0;
case 0x0c0cb4d2u: goto P_0c0cb4d2;
case 0x0c0cb4d4u: goto P_0c0cb4d4;
case 0x0c0cb4d6u: goto P_0c0cb4d6;
case 0x0c0cb4d8u: goto P_0c0cb4d8;
case 0x0c0cb4dau: goto P_0c0cb4da;
case 0x0c0cb4dcu: goto P_0c0cb4dc;
case 0x0c0cb4deu: goto P_0c0cb4de;
case 0x0c0cb4e0u: goto P_0c0cb4e0;
case 0x0c0cb4e2u: goto P_0c0cb4e2;
case 0x0c0cb4e4u: goto P_0c0cb4e4;
case 0x0c0cb4e6u: goto P_0c0cb4e6;
case 0x0c0cb4e8u: goto P_0c0cb4e8;
case 0x0c0cb4eau: goto P_0c0cb4ea;
case 0x0c0cb4ecu: goto P_0c0cb4ec;
case 0x0c0cb4eeu: goto P_0c0cb4ee;
case 0x0c0cb4f0u: goto P_0c0cb4f0;
case 0x0c0cb4f2u: goto P_0c0cb4f2;
case 0x0c0cb4f4u: goto P_0c0cb4f4;
case 0x0c0cb4f6u: goto P_0c0cb4f6;
case 0x0c0cb4f8u: goto P_0c0cb4f8;
case 0x0c0cb4fau: goto P_0c0cb4fa;
case 0x0c0cb4fcu: goto P_0c0cb4fc;
case 0x0c0cb4feu: goto P_0c0cb4fe;
case 0x0c0cb500u: goto P_0c0cb500;
case 0x0c0cb502u: goto P_0c0cb502;
case 0x0c0cb504u: goto P_0c0cb504;
case 0x0c0cb506u: goto P_0c0cb506;
case 0x0c0cb508u: goto P_0c0cb508;
case 0x0c0cb50au: goto P_0c0cb50a;
case 0x0c0cb50cu: goto P_0c0cb50c;
case 0x0c0cb50eu: goto P_0c0cb50e;
case 0x0c0cb510u: goto P_0c0cb510;
case 0x0c0cb512u: goto P_0c0cb512;
case 0x0c0cb514u: goto P_0c0cb514;
case 0x0c0cb516u: goto P_0c0cb516;
case 0x0c0cb518u: goto P_0c0cb518;
case 0x0c0cb51au: goto P_0c0cb51a;
case 0x0c0cb51cu: goto P_0c0cb51c;
case 0x0c0cb51eu: goto P_0c0cb51e;
case 0x0c0cb520u: goto P_0c0cb520;
case 0x0c0cb522u: goto P_0c0cb522;
case 0x0c0cb524u: goto P_0c0cb524;
case 0x0c0cb526u: goto P_0c0cb526;
case 0x0c0cb528u: goto P_0c0cb528;
case 0x0c0cb52au: goto P_0c0cb52a;
case 0x0c0cb52cu: goto P_0c0cb52c;
case 0x0c0cb52eu: goto P_0c0cb52e;
case 0x0c0cb530u: goto P_0c0cb530;
case 0x0c0cb532u: goto P_0c0cb532;
case 0x0c0cb534u: goto P_0c0cb534;
case 0x0c0cb536u: goto P_0c0cb536;
case 0x0c0cb538u: goto P_0c0cb538;
case 0x0c0cb53au: goto P_0c0cb53a;
case 0x0c0cb53cu: goto P_0c0cb53c;
case 0x0c0cb53eu: goto P_0c0cb53e;
case 0x0c0cb540u: goto P_0c0cb540;
case 0x0c0cb542u: goto P_0c0cb542;
case 0x0c0cb544u: goto P_0c0cb544;
case 0x0c0cb546u: goto P_0c0cb546;
case 0x0c0cb548u: goto P_0c0cb548;
case 0x0c0cb54au: goto P_0c0cb54a;
case 0x0c0cb54cu: goto P_0c0cb54c;
case 0x0c0cb54eu: goto P_0c0cb54e;
case 0x0c0cb550u: goto P_0c0cb550;
case 0x0c0cb552u: goto P_0c0cb552;
case 0x0c0cb554u: goto P_0c0cb554;
case 0x0c0cb57cu: goto P_0c0cb57c;
case 0x0c0cb57eu: goto P_0c0cb57e;
case 0x0c0cb580u: goto P_0c0cb580;
case 0x0c0cb582u: goto P_0c0cb582;
case 0x0c0cb584u: goto P_0c0cb584;
case 0x0c0cb586u: goto P_0c0cb586;
case 0x0c0cb588u: goto P_0c0cb588;
case 0x0c0cb58au: goto P_0c0cb58a;
case 0x0c0cb58cu: goto P_0c0cb58c;
case 0x0c0cb58eu: goto P_0c0cb58e;
case 0x0c0cb590u: goto P_0c0cb590;
case 0x0c0cb592u: goto P_0c0cb592;
case 0x0c0cb594u: goto P_0c0cb594;
case 0x0c0cb596u: goto P_0c0cb596;
case 0x0c0cb598u: goto P_0c0cb598;
case 0x0c0cb59au: goto P_0c0cb59a;
case 0x0c0cb59cu: goto P_0c0cb59c;
case 0x0c0cb59eu: goto P_0c0cb59e;
case 0x0c0cb5a0u: goto P_0c0cb5a0;
case 0x0c0cb5a2u: goto P_0c0cb5a2;
case 0x0c0cb5a4u: goto P_0c0cb5a4;
case 0x0c0cb5a6u: goto P_0c0cb5a6;
case 0x0c0cb5a8u: goto P_0c0cb5a8;
case 0x0c0cb5aau: goto P_0c0cb5aa;
case 0x0c0cb5acu: goto P_0c0cb5ac;
case 0x0c0cb5aeu: goto P_0c0cb5ae;
case 0x0c0cb5b0u: goto P_0c0cb5b0;
case 0x0c0cb5b2u: goto P_0c0cb5b2;
case 0x0c0cb5b4u: goto P_0c0cb5b4;
case 0x0c0cb5b6u: goto P_0c0cb5b6;
case 0x0c0cb5b8u: goto P_0c0cb5b8;
case 0x0c0cb5bau: goto P_0c0cb5ba;
case 0x0c0cb5bcu: goto P_0c0cb5bc;
case 0x0c0cb5beu: goto P_0c0cb5be;
case 0x0c0cb5c0u: goto P_0c0cb5c0;
case 0x0c0cb5c2u: goto P_0c0cb5c2;
case 0x0c0cb5c4u: goto P_0c0cb5c4;
case 0x0c0cb5c6u: goto P_0c0cb5c6;
case 0x0c0cb5c8u: goto P_0c0cb5c8;
case 0x0c0cb5cau: goto P_0c0cb5ca;
case 0x0c0cb5ccu: goto P_0c0cb5cc;
case 0x0c0cb5ceu: goto P_0c0cb5ce;
case 0x0c0cb5d0u: goto P_0c0cb5d0;
case 0x0c0cb5d2u: goto P_0c0cb5d2;
case 0x0c0cb5d4u: goto P_0c0cb5d4;
case 0x0c0cb5d6u: goto P_0c0cb5d6;
case 0x0c0cb5d8u: goto P_0c0cb5d8;
case 0x0c0cb5dau: goto P_0c0cb5da;
case 0x0c0cb5dcu: goto P_0c0cb5dc;
case 0x0c0cb5deu: goto P_0c0cb5de;
case 0x0c0cb5e0u: goto P_0c0cb5e0;
case 0x0c0cb5e2u: goto P_0c0cb5e2;
case 0x0c0cb5e4u: goto P_0c0cb5e4;
case 0x0c0cb5e6u: goto P_0c0cb5e6;
case 0x0c0cb5e8u: goto P_0c0cb5e8;
case 0x0c0cb5eau: goto P_0c0cb5ea;
case 0x0c0cb5ecu: goto P_0c0cb5ec;
case 0x0c0cb5eeu: goto P_0c0cb5ee;
case 0x0c0cb5f0u: goto P_0c0cb5f0;
case 0x0c0cb5f2u: goto P_0c0cb5f2;
case 0x0c0cb5f4u: goto P_0c0cb5f4;
case 0x0c0cb5f6u: goto P_0c0cb5f6;
case 0x0c0cb5f8u: goto P_0c0cb5f8;
case 0x0c0cb5fau: goto P_0c0cb5fa;
case 0x0c0cb5fcu: goto P_0c0cb5fc;
case 0x0c0cb5feu: goto P_0c0cb5fe;
case 0x0c0cb600u: goto P_0c0cb600;
case 0x0c0cb602u: goto P_0c0cb602;
case 0x0c0cb604u: goto P_0c0cb604;
case 0x0c0cb606u: goto P_0c0cb606;
case 0x0c0cb608u: goto P_0c0cb608;
case 0x0c0cb60au: goto P_0c0cb60a;
case 0x0c0cb60cu: goto P_0c0cb60c;
case 0x0c0cb60eu: goto P_0c0cb60e;
case 0x0c0cb610u: goto P_0c0cb610;
case 0x0c0cb612u: goto P_0c0cb612;
case 0x0c0cb614u: goto P_0c0cb614;
case 0x0c0cb616u: goto P_0c0cb616;
case 0x0c0cb618u: goto P_0c0cb618;
case 0x0c0cb61au: goto P_0c0cb61a;
case 0x0c0cb61cu: goto P_0c0cb61c;
case 0x0c0cb61eu: goto P_0c0cb61e;
case 0x0c0cb620u: goto P_0c0cb620;
case 0x0c0cb622u: goto P_0c0cb622;
case 0x0c0cb624u: goto P_0c0cb624;
case 0x0c0cb626u: goto P_0c0cb626;
case 0x0c0cb628u: goto P_0c0cb628;
case 0x0c0cb62au: goto P_0c0cb62a;
case 0x0c0cb62cu: goto P_0c0cb62c;
case 0x0c0cb62eu: goto P_0c0cb62e;
case 0x0c0cb630u: goto P_0c0cb630;
case 0x0c0cb632u: goto P_0c0cb632;
case 0x0c0cb634u: goto P_0c0cb634;
case 0x0c0cb636u: goto P_0c0cb636;
case 0x0c0cb638u: goto P_0c0cb638;
case 0x0c0cb63au: goto P_0c0cb63a;
case 0x0c0cb63cu: goto P_0c0cb63c;
case 0x0c0cb63eu: goto P_0c0cb63e;
case 0x0c0cb640u: goto P_0c0cb640;
case 0x0c0cb642u: goto P_0c0cb642;
case 0x0c0cb644u: goto P_0c0cb644;
case 0x0c0cb646u: goto P_0c0cb646;
case 0x0c0cb648u: goto P_0c0cb648;
case 0x0c0cb64au: goto P_0c0cb64a;
case 0x0c0cb64cu: goto P_0c0cb64c;
case 0x0c0cb64eu: goto P_0c0cb64e;
case 0x0c0cb650u: goto P_0c0cb650;
case 0x0c0cb652u: goto P_0c0cb652;
case 0x0c0cb654u: goto P_0c0cb654;
case 0x0c0cb656u: goto P_0c0cb656;
case 0x0c0cb658u: goto P_0c0cb658;
case 0x0c0cb65au: goto P_0c0cb65a;
case 0x0c0cb65cu: goto P_0c0cb65c;
case 0x0c0cb65eu: goto P_0c0cb65e;
case 0x0c0cb660u: goto P_0c0cb660;
case 0x0c0cb662u: goto P_0c0cb662;
case 0x0c0cb664u: goto P_0c0cb664;
case 0x0c0cb666u: goto P_0c0cb666;
case 0x0c0cb668u: goto P_0c0cb668;
case 0x0c0cb66au: goto P_0c0cb66a;
case 0x0c0cb66cu: goto P_0c0cb66c;
case 0x0c0cb66eu: goto P_0c0cb66e;
case 0x0c0cb670u: goto P_0c0cb670;
case 0x0c0cb672u: goto P_0c0cb672;
case 0x0c0cb674u: goto P_0c0cb674;
case 0x0c0cb676u: goto P_0c0cb676;
case 0x0c0cb678u: goto P_0c0cb678;
case 0x0c0cb67au: goto P_0c0cb67a;
case 0x0c0cb67cu: goto P_0c0cb67c;
case 0x0c0cb67eu: goto P_0c0cb67e;
case 0x0c0cb680u: goto P_0c0cb680;
case 0x0c0cb682u: goto P_0c0cb682;
case 0x0c0cb684u: goto P_0c0cb684;
case 0x0c0cb686u: goto P_0c0cb686;
case 0x0c0cb688u: goto P_0c0cb688;
case 0x0c0cb68au: goto P_0c0cb68a;
case 0x0c0cb68cu: goto P_0c0cb68c;
case 0x0c0cb68eu: goto P_0c0cb68e;
case 0x0c0cb690u: goto P_0c0cb690;
case 0x0c0cb692u: goto P_0c0cb692;
case 0x0c0cb694u: goto P_0c0cb694;
case 0x0c0cb696u: goto P_0c0cb696;
case 0x0c0cb698u: goto P_0c0cb698;
case 0x0c0cb69au: goto P_0c0cb69a;
case 0x0c0cb69cu: goto P_0c0cb69c;
case 0x0c0cb69eu: goto P_0c0cb69e;
case 0x0c0cb6a0u: goto P_0c0cb6a0;
case 0x0c0cb6a2u: goto P_0c0cb6a2;
case 0x0c0cb6a4u: goto P_0c0cb6a4;
case 0x0c0cb6a6u: goto P_0c0cb6a6;
case 0x0c0cb6a8u: goto P_0c0cb6a8;
case 0x0c0cb6d4u: goto P_0c0cb6d4;
case 0x0c0cb6d6u: goto P_0c0cb6d6;
case 0x0c0cb6d8u: goto P_0c0cb6d8;
case 0x0c0cb6dau: goto P_0c0cb6da;
case 0x0c0cb6dcu: goto P_0c0cb6dc;
case 0x0c0cb6deu: goto P_0c0cb6de;
case 0x0c0cb6e0u: goto P_0c0cb6e0;
case 0x0c0cb6e2u: goto P_0c0cb6e2;
case 0x0c0cb6e4u: goto P_0c0cb6e4;
case 0x0c0cb6e6u: goto P_0c0cb6e6;
case 0x0c0cb6e8u: goto P_0c0cb6e8;
case 0x0c0cb6eau: goto P_0c0cb6ea;
case 0x0c0cb6ecu: goto P_0c0cb6ec;
case 0x0c0cb6eeu: goto P_0c0cb6ee;
case 0x0c0cb6f0u: goto P_0c0cb6f0;
case 0x0c0cb6f2u: goto P_0c0cb6f2;
case 0x0c0cb6f4u: goto P_0c0cb6f4;
case 0x0c0cb6f6u: goto P_0c0cb6f6;
case 0x0c0cb6f8u: goto P_0c0cb6f8;
case 0x0c0cb6fau: goto P_0c0cb6fa;
case 0x0c0cb6fcu: goto P_0c0cb6fc;
case 0x0c0cb6feu: goto P_0c0cb6fe;
case 0x0c0cb700u: goto P_0c0cb700;
case 0x0c0cb702u: goto P_0c0cb702;
case 0x0c0cb704u: goto P_0c0cb704;
case 0x0c0cb706u: goto P_0c0cb706;
case 0x0c0cb708u: goto P_0c0cb708;
case 0x0c0cb70au: goto P_0c0cb70a;
case 0x0c0cb70cu: goto P_0c0cb70c;
case 0x0c0cb70eu: goto P_0c0cb70e;
case 0x0c0cb710u: goto P_0c0cb710;
case 0x0c0cb712u: goto P_0c0cb712;
case 0x0c0cb714u: goto P_0c0cb714;
case 0x0c0cb716u: goto P_0c0cb716;
case 0x0c0cb718u: goto P_0c0cb718;
case 0x0c0cb71au: goto P_0c0cb71a;
case 0x0c0cb71cu: goto P_0c0cb71c;
case 0x0c0cb71eu: goto P_0c0cb71e;
case 0x0c0cb720u: goto P_0c0cb720;
case 0x0c0cb722u: goto P_0c0cb722;
case 0x0c0cb724u: goto P_0c0cb724;
case 0x0c0cb726u: goto P_0c0cb726;
case 0x0c0cb728u: goto P_0c0cb728;
case 0x0c0cb72au: goto P_0c0cb72a;
case 0x0c0cb72cu: goto P_0c0cb72c;
case 0x0c0cb72eu: goto P_0c0cb72e;
case 0x0c0cb730u: goto P_0c0cb730;
case 0x0c0cb732u: goto P_0c0cb732;
case 0x0c0cb734u: goto P_0c0cb734;
case 0x0c0cb736u: goto P_0c0cb736;
case 0x0c0cb738u: goto P_0c0cb738;
case 0x0c0cb73au: goto P_0c0cb73a;
case 0x0c0cb73cu: goto P_0c0cb73c;
case 0x0c0cb73eu: goto P_0c0cb73e;
case 0x0c0cb740u: goto P_0c0cb740;
case 0x0c0cb742u: goto P_0c0cb742;
case 0x0c0cb744u: goto P_0c0cb744;
case 0x0c0cb746u: goto P_0c0cb746;
case 0x0c0cb748u: goto P_0c0cb748;
case 0x0c0cb74au: goto P_0c0cb74a;
case 0x0c0cb74cu: goto P_0c0cb74c;
case 0x0c0cb74eu: goto P_0c0cb74e;
case 0x0c0cb750u: goto P_0c0cb750;
case 0x0c0cb752u: goto P_0c0cb752;
case 0x0c0cb754u: goto P_0c0cb754;
case 0x0c0cb756u: goto P_0c0cb756;
case 0x0c0cb758u: goto P_0c0cb758;
case 0x0c0cb75au: goto P_0c0cb75a;
case 0x0c0cb75cu: goto P_0c0cb75c;
case 0x0c0cb75eu: goto P_0c0cb75e;
case 0x0c0cb760u: goto P_0c0cb760;
case 0x0c0cb762u: goto P_0c0cb762;
case 0x0c0cb764u: goto P_0c0cb764;
case 0x0c0cb766u: goto P_0c0cb766;
case 0x0c0cb768u: goto P_0c0cb768;
case 0x0c0cb76au: goto P_0c0cb76a;
case 0x0c0cb76cu: goto P_0c0cb76c;
case 0x0c0cb784u: goto P_0c0cb784;
case 0x0c0cb786u: goto P_0c0cb786;
case 0x0c0cb788u: goto P_0c0cb788;
case 0x0c0cb78au: goto P_0c0cb78a;
case 0x0c0cb78cu: goto P_0c0cb78c;
case 0x0c0cb78eu: goto P_0c0cb78e;
case 0x0c0cb790u: goto P_0c0cb790;
case 0x0c0cb792u: goto P_0c0cb792;
case 0x0c0cb794u: goto P_0c0cb794;
case 0x0c0cb796u: goto P_0c0cb796;
case 0x0c0cb798u: goto P_0c0cb798;
case 0x0c0cb79au: goto P_0c0cb79a;
case 0x0c0cb79cu: goto P_0c0cb79c;
case 0x0c0cb79eu: goto P_0c0cb79e;
case 0x0c0cb7a0u: goto P_0c0cb7a0;
case 0x0c0cb7a2u: goto P_0c0cb7a2;
case 0x0c0cb7a4u: goto P_0c0cb7a4;
case 0x0c0cb7a6u: goto P_0c0cb7a6;
case 0x0c0cb7a8u: goto P_0c0cb7a8;
case 0x0c0cb7aau: goto P_0c0cb7aa;
case 0x0c0cb7acu: goto P_0c0cb7ac;
case 0x0c0cb7aeu: goto P_0c0cb7ae;
case 0x0c0cb7b0u: goto P_0c0cb7b0;
case 0x0c0cb7b2u: goto P_0c0cb7b2;
case 0x0c0cb7b4u: goto P_0c0cb7b4;
case 0x0c0cb7b6u: goto P_0c0cb7b6;
case 0x0c0cb7b8u: goto P_0c0cb7b8;
case 0x0c0cb7bau: goto P_0c0cb7ba;
case 0x0c0cb8ecu: goto P_0c0cb8ec;
case 0x0c0cb8eeu: goto P_0c0cb8ee;
case 0x0c0cb8f0u: goto P_0c0cb8f0;
case 0x0c0cb8f2u: goto P_0c0cb8f2;
case 0x0c0cb8f4u: goto P_0c0cb8f4;
case 0x0c0cb8f6u: goto P_0c0cb8f6;
case 0x0c0cb8f8u: goto P_0c0cb8f8;
case 0x0c0cb8fau: goto P_0c0cb8fa;
case 0x0c0cb8fcu: goto P_0c0cb8fc;
case 0x0c0cb8feu: goto P_0c0cb8fe;
case 0x0c0cb900u: goto P_0c0cb900;
case 0x0c0cb902u: goto P_0c0cb902;
case 0x0c0cb904u: goto P_0c0cb904;
case 0x0c0cb906u: goto P_0c0cb906;
case 0x0c0cb908u: goto P_0c0cb908;
case 0x0c0cb90au: goto P_0c0cb90a;
case 0x0c0cb90cu: goto P_0c0cb90c;
case 0x0c0cb90eu: goto P_0c0cb90e;
case 0x0c0cb910u: goto P_0c0cb910;
case 0x0c0cb912u: goto P_0c0cb912;
case 0x0c0cb914u: goto P_0c0cb914;
case 0x0c0cb916u: goto P_0c0cb916;
case 0x0c0cb918u: goto P_0c0cb918;
case 0x0c0cb91au: goto P_0c0cb91a;
case 0x0c0cb91cu: goto P_0c0cb91c;
case 0x0c0cb91eu: goto P_0c0cb91e;
case 0x0c0cb920u: goto P_0c0cb920;
case 0x0c0cb922u: goto P_0c0cb922;
case 0x0c0cb924u: goto P_0c0cb924;
case 0x0c0cb926u: goto P_0c0cb926;
case 0x0c0cb928u: goto P_0c0cb928;
case 0x0c0cb92au: goto P_0c0cb92a;
case 0x0c0cb92cu: goto P_0c0cb92c;
case 0x0c0cb92eu: goto P_0c0cb92e;
case 0x0c0cb930u: goto P_0c0cb930;
case 0x0c0cb932u: goto P_0c0cb932;
case 0x0c0cb934u: goto P_0c0cb934;
case 0x0c0cb936u: goto P_0c0cb936;
case 0x0c0cb938u: goto P_0c0cb938;
case 0x0c0cb93au: goto P_0c0cb93a;
case 0x0c0cb93cu: goto P_0c0cb93c;
case 0x0c0cb93eu: goto P_0c0cb93e;
case 0x0c0cb940u: goto P_0c0cb940;
case 0x0c0cb942u: goto P_0c0cb942;
case 0x0c0cb944u: goto P_0c0cb944;
case 0x0c0cb946u: goto P_0c0cb946;
case 0x0c0cb948u: goto P_0c0cb948;
case 0x0c0cb94au: goto P_0c0cb94a;
case 0x0c0cb94cu: goto P_0c0cb94c;
case 0x0c0cb94eu: goto P_0c0cb94e;
case 0x0c0cb950u: goto P_0c0cb950;
case 0x0c0cb952u: goto P_0c0cb952;
case 0x0c0cb954u: goto P_0c0cb954;
case 0x0c0cb956u: goto P_0c0cb956;
case 0x0c0cb958u: goto P_0c0cb958;
case 0x0c0cb95au: goto P_0c0cb95a;
case 0x0c0cb95cu: goto P_0c0cb95c;
case 0x0c0cb95eu: goto P_0c0cb95e;
case 0x0c0cb960u: goto P_0c0cb960;
case 0x0c0cb962u: goto P_0c0cb962;
case 0x0c0cb964u: goto P_0c0cb964;
case 0x0c0cb966u: goto P_0c0cb966;
case 0x0c0cb968u: goto P_0c0cb968;
case 0x0c0cb96au: goto P_0c0cb96a;
case 0x0c0cb96cu: goto P_0c0cb96c;
case 0x0c0cb96eu: goto P_0c0cb96e;
case 0x0c0cb970u: goto P_0c0cb970;
case 0x0c0cb972u: goto P_0c0cb972;
case 0x0c0cb974u: goto P_0c0cb974;
case 0x0c0cb976u: goto P_0c0cb976;
case 0x0c0cb978u: goto P_0c0cb978;
case 0x0c0cb97au: goto P_0c0cb97a;
case 0x0c0cb97cu: goto P_0c0cb97c;
case 0x0c0cb97eu: goto P_0c0cb97e;
case 0x0c0cb980u: goto P_0c0cb980;
case 0x0c0cb982u: goto P_0c0cb982;
case 0x0c0cb984u: goto P_0c0cb984;
case 0x0c0cb986u: goto P_0c0cb986;
case 0x0c0cb988u: goto P_0c0cb988;
case 0x0c0cb98au: goto P_0c0cb98a;
case 0x0c0cb98cu: goto P_0c0cb98c;
case 0x0c0cb98eu: goto P_0c0cb98e;
case 0x0c0cb990u: goto P_0c0cb990;
case 0x0c0cb992u: goto P_0c0cb992;
case 0x0c0cb994u: goto P_0c0cb994;
case 0x0c0cb996u: goto P_0c0cb996;
case 0x0c0cb998u: goto P_0c0cb998;
case 0x0c0cb99au: goto P_0c0cb99a;
case 0x0c0cb99cu: goto P_0c0cb99c;
case 0x0c0cb99eu: goto P_0c0cb99e;
case 0x0c0cb9a0u: goto P_0c0cb9a0;
case 0x0c0cb9a2u: goto P_0c0cb9a2;
case 0x0c0cb9a4u: goto P_0c0cb9a4;
case 0x0c0cb9a6u: goto P_0c0cb9a6;
case 0x0c0cb9a8u: goto P_0c0cb9a8;
case 0x0c0cb9aau: goto P_0c0cb9aa;
case 0x0c0cb9acu: goto P_0c0cb9ac;
case 0x0c0cb9aeu: goto P_0c0cb9ae;
case 0x0c0cb9b0u: goto P_0c0cb9b0;
case 0x0c0cb9b2u: goto P_0c0cb9b2;
case 0x0c0cb9d8u: goto P_0c0cb9d8;
case 0x0c0cb9dau: goto P_0c0cb9da;
case 0x0c0cb9dcu: goto P_0c0cb9dc;
case 0x0c0cb9deu: goto P_0c0cb9de;
case 0x0c0cb9e0u: goto P_0c0cb9e0;
case 0x0c0cb9e2u: goto P_0c0cb9e2;
case 0x0c0cb9e4u: goto P_0c0cb9e4;
case 0x0c0cb9e6u: goto P_0c0cb9e6;
case 0x0c0cb9e8u: goto P_0c0cb9e8;
case 0x0c0cb9eau: goto P_0c0cb9ea;
case 0x0c0cb9ecu: goto P_0c0cb9ec;
case 0x0c0cb9eeu: goto P_0c0cb9ee;
case 0x0c0cb9f0u: goto P_0c0cb9f0;
case 0x0c0cb9f2u: goto P_0c0cb9f2;
case 0x0c0cb9f4u: goto P_0c0cb9f4;
case 0x0c0cb9f6u: goto P_0c0cb9f6;
case 0x0c0cb9f8u: goto P_0c0cb9f8;
case 0x0c0cb9fau: goto P_0c0cb9fa;
case 0x0c0cb9fcu: goto P_0c0cb9fc;
case 0x0c0cb9feu: goto P_0c0cb9fe;
case 0x0c0cba00u: goto P_0c0cba00;
case 0x0c0cba02u: goto P_0c0cba02;
case 0x0c0cba04u: goto P_0c0cba04;
case 0x0c0cba06u: goto P_0c0cba06;
case 0x0c0cba08u: goto P_0c0cba08;
case 0x0c0cba0au: goto P_0c0cba0a;
case 0x0c0cba0cu: goto P_0c0cba0c;
case 0x0c0cba0eu: goto P_0c0cba0e;
case 0x0c0cba10u: goto P_0c0cba10;
case 0x0c0cba12u: goto P_0c0cba12;
case 0x0c0cba14u: goto P_0c0cba14;
case 0x0c0cba16u: goto P_0c0cba16;
case 0x0c0cba18u: goto P_0c0cba18;
case 0x0c0cba1au: goto P_0c0cba1a;
case 0x0c0cba1cu: goto P_0c0cba1c;
case 0x0c0cba1eu: goto P_0c0cba1e;
case 0x0c0cba20u: goto P_0c0cba20;
case 0x0c0cba22u: goto P_0c0cba22;
case 0x0c0cba24u: goto P_0c0cba24;
case 0x0c0cba26u: goto P_0c0cba26;
case 0x0c0cba28u: goto P_0c0cba28;
case 0x0c0cba2au: goto P_0c0cba2a;
case 0x0c0cba2cu: goto P_0c0cba2c;
case 0x0c0cba2eu: goto P_0c0cba2e;
case 0x0c0cba30u: goto P_0c0cba30;
case 0x0c0cba32u: goto P_0c0cba32;
case 0x0c0cba34u: goto P_0c0cba34;
case 0x0c0cba36u: goto P_0c0cba36;
case 0x0c0cba38u: goto P_0c0cba38;
case 0x0c0cba3au: goto P_0c0cba3a;
case 0x0c0cba3cu: goto P_0c0cba3c;
case 0x0c0cba3eu: goto P_0c0cba3e;
case 0x0c0cba40u: goto P_0c0cba40;
case 0x0c0cba42u: goto P_0c0cba42;
case 0x0c0cba44u: goto P_0c0cba44;
case 0x0c0cba46u: goto P_0c0cba46;
case 0x0c0cba48u: goto P_0c0cba48;
case 0x0c0cba4au: goto P_0c0cba4a;
case 0x0c0cba4cu: goto P_0c0cba4c;
case 0x0c0cba4eu: goto P_0c0cba4e;
case 0x0c0cba50u: goto P_0c0cba50;
case 0x0c0cba52u: goto P_0c0cba52;
case 0x0c0cba54u: goto P_0c0cba54;
case 0x0c0cba56u: goto P_0c0cba56;
case 0x0c0cba58u: goto P_0c0cba58;
case 0x0c0cba5au: goto P_0c0cba5a;
case 0x0c0cba5cu: goto P_0c0cba5c;
case 0x0c0cba5eu: goto P_0c0cba5e;
case 0x0c0cba60u: goto P_0c0cba60;
case 0x0c0cba62u: goto P_0c0cba62;
case 0x0c0cba64u: goto P_0c0cba64;
case 0x0c0cba66u: goto P_0c0cba66;
case 0x0c0cba68u: goto P_0c0cba68;
case 0x0c0cba6au: goto P_0c0cba6a;
case 0x0c0cba6cu: goto P_0c0cba6c;
case 0x0c0cba6eu: goto P_0c0cba6e;
case 0x0c0cba70u: goto P_0c0cba70;
case 0x0c0cba72u: goto P_0c0cba72;
case 0x0c0cba74u: goto P_0c0cba74;
case 0x0c0cba76u: goto P_0c0cba76;
case 0x0c0cba78u: goto P_0c0cba78;
case 0x0c0cba7au: goto P_0c0cba7a;
case 0x0c0cba7cu: goto P_0c0cba7c;
case 0x0c0cba7eu: goto P_0c0cba7e;
case 0x0c0cba80u: goto P_0c0cba80;
case 0x0c0cba82u: goto P_0c0cba82;
case 0x0c0cba84u: goto P_0c0cba84;
case 0x0c0cba86u: goto P_0c0cba86;
case 0x0c0cba88u: goto P_0c0cba88;
case 0x0c0cba8au: goto P_0c0cba8a;
case 0x0c0cba8cu: goto P_0c0cba8c;
case 0x0c0cba8eu: goto P_0c0cba8e;
case 0x0c0cba90u: goto P_0c0cba90;
case 0x0c0cba92u: goto P_0c0cba92;
case 0x0c0cba94u: goto P_0c0cba94;
case 0x0c0cba96u: goto P_0c0cba96;
case 0x0c0cba98u: goto P_0c0cba98;
case 0x0c0cba9au: goto P_0c0cba9a;
case 0x0c0cba9cu: goto P_0c0cba9c;
case 0x0c0cba9eu: goto P_0c0cba9e;
case 0x0c0cbaa0u: goto P_0c0cbaa0;
case 0x0c0cbaa2u: goto P_0c0cbaa2;
case 0x0c0cbaa4u: goto P_0c0cbaa4;
case 0x0c0cbaa6u: goto P_0c0cbaa6;
case 0x0c0cbaa8u: goto P_0c0cbaa8;
case 0x0c0cbaaau: goto P_0c0cbaaa;
case 0x0c0cbaacu: goto P_0c0cbaac;
case 0x0c0cbaaeu: goto P_0c0cbaae;
case 0x0c0cbab0u: goto P_0c0cbab0;
case 0x0c0cbab2u: goto P_0c0cbab2;
case 0x0c0cbab4u: goto P_0c0cbab4;
case 0x0c0cbab6u: goto P_0c0cbab6;
case 0x0c0cbab8u: goto P_0c0cbab8;
case 0x0c0cbabau: goto P_0c0cbaba;
case 0x0c0cbabcu: goto P_0c0cbabc;
case 0x0c0cbabeu: goto P_0c0cbabe;
case 0x0c0cbac0u: goto P_0c0cbac0;
case 0x0c0cbadcu: goto P_0c0cbadc;
case 0x0c0cbadeu: goto P_0c0cbade;
case 0x0c0cbae0u: goto P_0c0cbae0;
case 0x0c0cbae2u: goto P_0c0cbae2;
case 0x0c0cbae4u: goto P_0c0cbae4;
case 0x0c0cbae6u: goto P_0c0cbae6;
case 0x0c0cbae8u: goto P_0c0cbae8;
case 0x0c0cbaeau: goto P_0c0cbaea;
case 0x0c0cbaecu: goto P_0c0cbaec;
case 0x0c0cbaeeu: goto P_0c0cbaee;
case 0x0c0cbaf0u: goto P_0c0cbaf0;
case 0x0c0cbaf2u: goto P_0c0cbaf2;
case 0x0c0cbaf4u: goto P_0c0cbaf4;
case 0x0c0cbaf6u: goto P_0c0cbaf6;
case 0x0c0cbaf8u: goto P_0c0cbaf8;
case 0x0c0cbafau: goto P_0c0cbafa;
case 0x0c0cbafcu: goto P_0c0cbafc;
case 0x0c0cbafeu: goto P_0c0cbafe;
case 0x0c0cbb00u: goto P_0c0cbb00;
case 0x0c0cbb02u: goto P_0c0cbb02;
case 0x0c0cbb04u: goto P_0c0cbb04;
case 0x0c0cbb06u: goto P_0c0cbb06;
case 0x0c0cbb08u: goto P_0c0cbb08;
case 0x0c0cbb0au: goto P_0c0cbb0a;
case 0x0c0cbb0cu: goto P_0c0cbb0c;
case 0x0c0cbb0eu: goto P_0c0cbb0e;
case 0x0c0cbb10u: goto P_0c0cbb10;
case 0x0c0cbb12u: goto P_0c0cbb12;
case 0x0c0cbb14u: goto P_0c0cbb14;
case 0x0c0cbb16u: goto P_0c0cbb16;
case 0x0c0cbb18u: goto P_0c0cbb18;
case 0x0c0cbb1au: goto P_0c0cbb1a;
case 0x0c0cbb1cu: goto P_0c0cbb1c;
case 0x0c0cbb1eu: goto P_0c0cbb1e;
case 0x0c0cbb20u: goto P_0c0cbb20;
case 0x0c0cbb22u: goto P_0c0cbb22;
case 0x0c0cbb24u: goto P_0c0cbb24;
case 0x0c0cbb26u: goto P_0c0cbb26;
case 0x0c0cbb28u: goto P_0c0cbb28;
case 0x0c0cbb2au: goto P_0c0cbb2a;
case 0x0c0cbb2cu: goto P_0c0cbb2c;
case 0x0c0cbb2eu: goto P_0c0cbb2e;
case 0x0c0cbb30u: goto P_0c0cbb30;
case 0x0c0cbb32u: goto P_0c0cbb32;
case 0x0c0cbb34u: goto P_0c0cbb34;
case 0x0c0cbb36u: goto P_0c0cbb36;
case 0x0c0cbb38u: goto P_0c0cbb38;
case 0x0c0cbb3au: goto P_0c0cbb3a;
case 0x0c0cbb3cu: goto P_0c0cbb3c;
case 0x0c0cbb3eu: goto P_0c0cbb3e;
case 0x0c0cbb40u: goto P_0c0cbb40;
case 0x0c0cbb42u: goto P_0c0cbb42;
case 0x0c0cbb44u: goto P_0c0cbb44;
case 0x0c0cbb6au: goto P_0c0cbb6a;
case 0x0c0cbb6cu: goto P_0c0cbb6c;
case 0x0c0cbb6eu: goto P_0c0cbb6e;
case 0x0c0cbb70u: goto P_0c0cbb70;
case 0x0c0cbb72u: goto P_0c0cbb72;
case 0x0c0cbb74u: goto P_0c0cbb74;
case 0x0c0cbb76u: goto P_0c0cbb76;
case 0x0c0cbb78u: goto P_0c0cbb78;
case 0x0c0cbb7au: goto P_0c0cbb7a;
case 0x0c0cbb7cu: goto P_0c0cbb7c;
case 0x0c0cbb7eu: goto P_0c0cbb7e;
case 0x0c0cbb80u: goto P_0c0cbb80;
case 0x0c0cbb82u: goto P_0c0cbb82;
case 0x0c0cbb84u: goto P_0c0cbb84;
case 0x0c0cbb86u: goto P_0c0cbb86;
case 0x0c0cbb88u: goto P_0c0cbb88;
case 0x0c0cbb8au: goto P_0c0cbb8a;
case 0x0c0cbb8cu: goto P_0c0cbb8c;
case 0x0c0cbb8eu: goto P_0c0cbb8e;
case 0x0c0cbb90u: goto P_0c0cbb90;
case 0x0c0cbb92u: goto P_0c0cbb92;
case 0x0c0cbb94u: goto P_0c0cbb94;
case 0x0c0cbb96u: goto P_0c0cbb96;
case 0x0c0cbb98u: goto P_0c0cbb98;
case 0x0c0cbb9au: goto P_0c0cbb9a;
case 0x0c0cbb9cu: goto P_0c0cbb9c;
case 0x0c0cbb9eu: goto P_0c0cbb9e;
case 0x0c0cbba0u: goto P_0c0cbba0;
case 0x0c0cbba2u: goto P_0c0cbba2;
case 0x0c0cbba4u: goto P_0c0cbba4;
case 0x0c0cbba6u: goto P_0c0cbba6;
case 0x0c0cbba8u: goto P_0c0cbba8;
case 0x0c0cbbaau: goto P_0c0cbbaa;
case 0x0c0cbbacu: goto P_0c0cbbac;
case 0x0c0cbbaeu: goto P_0c0cbbae;
case 0x0c0cbbb0u: goto P_0c0cbbb0;
case 0x0c0cbbb2u: goto P_0c0cbbb2;
case 0x0c0cbbb4u: goto P_0c0cbbb4;
case 0x0c0cbbb6u: goto P_0c0cbbb6;
case 0x0c0cbbb8u: goto P_0c0cbbb8;
case 0x0c0cbbbau: goto P_0c0cbbba;
case 0x0c0cbbbcu: goto P_0c0cbbbc;
case 0x0c0cbbbeu: goto P_0c0cbbbe;
case 0x0c0cbbc0u: goto P_0c0cbbc0;
case 0x0c0cbbc2u: goto P_0c0cbbc2;
case 0x0c0cbbc4u: goto P_0c0cbbc4;
case 0x0c0cbbc6u: goto P_0c0cbbc6;
case 0x0c0cbbc8u: goto P_0c0cbbc8;
case 0x0c0cbbcau: goto P_0c0cbbca;
case 0x0c0cbbccu: goto P_0c0cbbcc;
case 0x0c0cbbceu: goto P_0c0cbbce;
case 0x0c0cbbd0u: goto P_0c0cbbd0;
case 0x0c0cbbd2u: goto P_0c0cbbd2;
case 0x0c0cbbd4u: goto P_0c0cbbd4;
case 0x0c0cbbd6u: goto P_0c0cbbd6;
case 0x0c0cbbd8u: goto P_0c0cbbd8;
case 0x0c0cbbdau: goto P_0c0cbbda;
case 0x0c0cbbdcu: goto P_0c0cbbdc;
case 0x0c0cbbdeu: goto P_0c0cbbde;
case 0x0c0cbbe0u: goto P_0c0cbbe0;
case 0x0c0cbbe2u: goto P_0c0cbbe2;
case 0x0c0cbbe4u: goto P_0c0cbbe4;
case 0x0c0cbbe6u: goto P_0c0cbbe6;
case 0x0c0cbbe8u: goto P_0c0cbbe8;
case 0x0c0cbbeau: goto P_0c0cbbea;
case 0x0c0cbbecu: goto P_0c0cbbec;
case 0x0c0cbbeeu: goto P_0c0cbbee;
case 0x0c0cbbf0u: goto P_0c0cbbf0;
case 0x0c0cbbf2u: goto P_0c0cbbf2;
case 0x0c0cbbf4u: goto P_0c0cbbf4;
case 0x0c0cbbf6u: goto P_0c0cbbf6;
case 0x0c0cbbf8u: goto P_0c0cbbf8;
case 0x0c0cbbfau: goto P_0c0cbbfa;
case 0x0c0cbbfcu: goto P_0c0cbbfc;
case 0x0c0cbbfeu: goto P_0c0cbbfe;
case 0x0c0cbc00u: goto P_0c0cbc00;
case 0x0c0cbc02u: goto P_0c0cbc02;
case 0x0c0cbc04u: goto P_0c0cbc04;
case 0x0c0cbc06u: goto P_0c0cbc06;
case 0x0c0cbc08u: goto P_0c0cbc08;
case 0x0c0cbc0au: goto P_0c0cbc0a;
case 0x0c0cbc0cu: goto P_0c0cbc0c;
case 0x0c0cbc0eu: goto P_0c0cbc0e;
case 0x0c0cbc10u: goto P_0c0cbc10;
case 0x0c0cbc12u: goto P_0c0cbc12;
case 0x0c0cbc14u: goto P_0c0cbc14;
case 0x0c0cbc16u: goto P_0c0cbc16;
case 0x0c0cbc18u: goto P_0c0cbc18;
case 0x0c0cbc1au: goto P_0c0cbc1a;
case 0x0c0cbc1cu: goto P_0c0cbc1c;
case 0x0c0cbc1eu: goto P_0c0cbc1e;
case 0x0c0cbc20u: goto P_0c0cbc20;
case 0x0c0cbc22u: goto P_0c0cbc22;
case 0x0c0cbc24u: goto P_0c0cbc24;
case 0x0c0cbc26u: goto P_0c0cbc26;
case 0x0c0cbc28u: goto P_0c0cbc28;
case 0x0c0cbc2au: goto P_0c0cbc2a;
case 0x0c0cbc2cu: goto P_0c0cbc2c;
case 0x0c0cbc2eu: goto P_0c0cbc2e;
case 0x0c0cbc30u: goto P_0c0cbc30;
case 0x0c0cbc32u: goto P_0c0cbc32;
case 0x0c0cbc34u: goto P_0c0cbc34;
case 0x0c0cbc36u: goto P_0c0cbc36;
case 0x0c0cbc38u: goto P_0c0cbc38;
case 0x0c0cbc3au: goto P_0c0cbc3a;
case 0x0c0cbc3cu: goto P_0c0cbc3c;
case 0x0c0cbc3eu: goto P_0c0cbc3e;
case 0x0c0cbc40u: goto P_0c0cbc40;
case 0x0c0cbc42u: goto P_0c0cbc42;
case 0x0c0cbc44u: goto P_0c0cbc44;
case 0x0c0cbc46u: goto P_0c0cbc46;
case 0x0c0cbc48u: goto P_0c0cbc48;
case 0x0c0cbc4au: goto P_0c0cbc4a;
case 0x0c0cbc4cu: goto P_0c0cbc4c;
case 0x0c0cbc4eu: goto P_0c0cbc4e;
case 0x0c0cbc50u: goto P_0c0cbc50;
case 0x0c0cbc52u: goto P_0c0cbc52;
case 0x0c0cbc54u: goto P_0c0cbc54;
case 0x0c0cbc56u: goto P_0c0cbc56;
case 0x0c0cbc58u: goto P_0c0cbc58;
case 0x0c0cbc5au: goto P_0c0cbc5a;
case 0x0c0cbc5cu: goto P_0c0cbc5c;
case 0x0c0cbc5eu: goto P_0c0cbc5e;
case 0x0c0cbc60u: goto P_0c0cbc60;
case 0x0c0cbc62u: goto P_0c0cbc62;
case 0x0c0cbc64u: goto P_0c0cbc64;
case 0x0c0cbc66u: goto P_0c0cbc66;
case 0x0c0cbc68u: goto P_0c0cbc68;
case 0x0c0cbc6au: goto P_0c0cbc6a;
case 0x0c0cbc6cu: goto P_0c0cbc6c;
case 0x0c0cbc6eu: goto P_0c0cbc6e;
case 0x0c0cbc70u: goto P_0c0cbc70;
case 0x0c0cbc72u: goto P_0c0cbc72;
case 0x0c0cbc74u: goto P_0c0cbc74;
case 0x0c0cbc76u: goto P_0c0cbc76;
case 0x0c0cbc78u: goto P_0c0cbc78;
case 0x0c0cbc7au: goto P_0c0cbc7a;
case 0x0c0cbc7cu: goto P_0c0cbc7c;
case 0x0c0cbc7eu: goto P_0c0cbc7e;
case 0x0c0cbc80u: goto P_0c0cbc80;
case 0x0c0cbc82u: goto P_0c0cbc82;
case 0x0c0cbc84u: goto P_0c0cbc84;
case 0x0c0cbc86u: goto P_0c0cbc86;
case 0x0c0cbc88u: goto P_0c0cbc88;
case 0x0c0cbc8au: goto P_0c0cbc8a;
case 0x0c0cbc8cu: goto P_0c0cbc8c;
case 0x0c0cbc8eu: goto P_0c0cbc8e;
case 0x0c0cbc90u: goto P_0c0cbc90;
case 0x0c0cbc92u: goto P_0c0cbc92;
case 0x0c0cbc94u: goto P_0c0cbc94;
case 0x0c0cbc96u: goto P_0c0cbc96;
case 0x0c0cbc98u: goto P_0c0cbc98;
case 0x0c0cbc9au: goto P_0c0cbc9a;
case 0x0c0cbc9cu: goto P_0c0cbc9c;
case 0x0c0cbc9eu: goto P_0c0cbc9e;
case 0x0c0cbca0u: goto P_0c0cbca0;
case 0x0c0cbca2u: goto P_0c0cbca2;
case 0x0c0cbca4u: goto P_0c0cbca4;
case 0x0c0cbca6u: goto P_0c0cbca6;
case 0x0c0cbca8u: goto P_0c0cbca8;
case 0x0c0cbcaau: goto P_0c0cbcaa;
case 0x0c0cbcacu: goto P_0c0cbcac;
case 0x0c0cbcaeu: goto P_0c0cbcae;
case 0x0c0cbcb0u: goto P_0c0cbcb0;
case 0x0c0cbcb2u: goto P_0c0cbcb2;
case 0x0c0cbcb4u: goto P_0c0cbcb4;
case 0x0c0cbcb6u: goto P_0c0cbcb6;
case 0x0c0cbcb8u: goto P_0c0cbcb8;
case 0x0c0cbcbau: goto P_0c0cbcba;
case 0x0c0cbcbcu: goto P_0c0cbcbc;
case 0x0c0cbcbeu: goto P_0c0cbcbe;
case 0x0c0cbcc0u: goto P_0c0cbcc0;
case 0x0c0cbcc2u: goto P_0c0cbcc2;
case 0x0c0cbcc4u: goto P_0c0cbcc4;
case 0x0c0cbcc6u: goto P_0c0cbcc6;
case 0x0c0cbdccu: goto P_0c0cbdcc;
case 0x0c0cbdceu: goto P_0c0cbdce;
case 0x0c0cbdd0u: goto P_0c0cbdd0;
case 0x0c0cbdd2u: goto P_0c0cbdd2;
case 0x0c0cbdd4u: goto P_0c0cbdd4;
case 0x0c0cbdd6u: goto P_0c0cbdd6;
case 0x0c0cbdd8u: goto P_0c0cbdd8;
case 0x0c0cbddau: goto P_0c0cbdda;
case 0x0c0cbddcu: goto P_0c0cbddc;
case 0x0c0cbddeu: goto P_0c0cbdde;
case 0x0c0cbde0u: goto P_0c0cbde0;
case 0x0c0cbde2u: goto P_0c0cbde2;
case 0x0c0cbde4u: goto P_0c0cbde4;
case 0x0c0cbde6u: goto P_0c0cbde6;
case 0x0c0cbde8u: goto P_0c0cbde8;
case 0x0c0cbdeau: goto P_0c0cbdea;
case 0x0c0cbdecu: goto P_0c0cbdec;
case 0x0c0cbdeeu: goto P_0c0cbdee;
case 0x0c0cbdf0u: goto P_0c0cbdf0;
case 0x0c0cbdf2u: goto P_0c0cbdf2;
case 0x0c0cbdf4u: goto P_0c0cbdf4;
case 0x0c0cbdf6u: goto P_0c0cbdf6;
case 0x0c0cbdf8u: goto P_0c0cbdf8;
case 0x0c0cbdfau: goto P_0c0cbdfa;
case 0x0c0cbdfcu: goto P_0c0cbdfc;
case 0x0c0cbdfeu: goto P_0c0cbdfe;
case 0x0c0cbe00u: goto P_0c0cbe00;
case 0x0c0cbe02u: goto P_0c0cbe02;
case 0x0c0cbe04u: goto P_0c0cbe04;
case 0x0c0cbe06u: goto P_0c0cbe06;
case 0x0c0cbe08u: goto P_0c0cbe08;
case 0x0c0cbe0au: goto P_0c0cbe0a;
case 0x0c0cbe0cu: goto P_0c0cbe0c;
case 0x0c0cbe0eu: goto P_0c0cbe0e;
case 0x0c0cbe10u: goto P_0c0cbe10;
case 0x0c0cbe12u: goto P_0c0cbe12;
case 0x0c0cbe14u: goto P_0c0cbe14;
case 0x0c0cbe16u: goto P_0c0cbe16;
case 0x0c0cbe18u: goto P_0c0cbe18;
case 0x0c0cbe1au: goto P_0c0cbe1a;
case 0x0c0cbe1cu: goto P_0c0cbe1c;
case 0x0c0cbe1eu: goto P_0c0cbe1e;
case 0x0c0cbe20u: goto P_0c0cbe20;
case 0x0c0cbe22u: goto P_0c0cbe22;
case 0x0c0cbe24u: goto P_0c0cbe24;
case 0x0c0cbe26u: goto P_0c0cbe26;
case 0x0c0cbe28u: goto P_0c0cbe28;
case 0x0c0cbe2au: goto P_0c0cbe2a;
case 0x0c0cbe2cu: goto P_0c0cbe2c;
case 0x0c0cbe2eu: goto P_0c0cbe2e;
case 0x0c0cbe30u: goto P_0c0cbe30;
case 0x0c0cbe32u: goto P_0c0cbe32;
case 0x0c0cbe34u: goto P_0c0cbe34;
case 0x0c0cbe36u: goto P_0c0cbe36;
case 0x0c0cbe38u: goto P_0c0cbe38;
case 0x0c0cbe3au: goto P_0c0cbe3a;
case 0x0c0cbe3cu: goto P_0c0cbe3c;
case 0x0c0cbe3eu: goto P_0c0cbe3e;
case 0x0c0cbe40u: goto P_0c0cbe40;
case 0x0c0cbe42u: goto P_0c0cbe42;
case 0x0c0cbe44u: goto P_0c0cbe44;
case 0x0c0cbe46u: goto P_0c0cbe46;
case 0x0c0cbe48u: goto P_0c0cbe48;
case 0x0c0cbe4au: goto P_0c0cbe4a;
case 0x0c0cbe4cu: goto P_0c0cbe4c;
case 0x0c0cbe4eu: goto P_0c0cbe4e;
case 0x0c0cbe50u: goto P_0c0cbe50;
case 0x0c0cbe52u: goto P_0c0cbe52;
case 0x0c0cbe54u: goto P_0c0cbe54;
case 0x0c0cbe56u: goto P_0c0cbe56;
case 0x0c0cbe58u: goto P_0c0cbe58;
case 0x0c0cbe5au: goto P_0c0cbe5a;
case 0x0c0cbe5cu: goto P_0c0cbe5c;
case 0x0c0cbe5eu: goto P_0c0cbe5e;
case 0x0c0cbe60u: goto P_0c0cbe60;
case 0x0c0cbe62u: goto P_0c0cbe62;
case 0x0c0cbe64u: goto P_0c0cbe64;
case 0x0c0cbe66u: goto P_0c0cbe66;
case 0x0c0cbe68u: goto P_0c0cbe68;
case 0x0c0cbe6au: goto P_0c0cbe6a;
case 0x0c0cbe6cu: goto P_0c0cbe6c;
case 0x0c0cbe6eu: goto P_0c0cbe6e;
case 0x0c0cbe70u: goto P_0c0cbe70;
case 0x0c0cbe72u: goto P_0c0cbe72;
case 0x0c0cbe74u: goto P_0c0cbe74;
case 0x0c0cbe76u: goto P_0c0cbe76;
case 0x0c0cbe78u: goto P_0c0cbe78;
case 0x0c0cbe7au: goto P_0c0cbe7a;
case 0x0c0cbe7cu: goto P_0c0cbe7c;
case 0x0c0cbe7eu: goto P_0c0cbe7e;
case 0x0c0cbe80u: goto P_0c0cbe80;
case 0x0c0cbe82u: goto P_0c0cbe82;
case 0x0c0cbe84u: goto P_0c0cbe84;
case 0x0c0cbe86u: goto P_0c0cbe86;
case 0x0c0cbe88u: goto P_0c0cbe88;
case 0x0c0cbe8au: goto P_0c0cbe8a;
case 0x0c0cbe8cu: goto P_0c0cbe8c;
case 0x0c0cbe8eu: goto P_0c0cbe8e;
case 0x0c0cbe90u: goto P_0c0cbe90;
case 0x0c0cbe92u: goto P_0c0cbe92;
case 0x0c0cbe94u: goto P_0c0cbe94;
case 0x0c0cbe96u: goto P_0c0cbe96;
case 0x0c0cbe98u: goto P_0c0cbe98;
case 0x0c0cbe9au: goto P_0c0cbe9a;
case 0x0c0cbe9cu: goto P_0c0cbe9c;
case 0x0c0cbe9eu: goto P_0c0cbe9e;
case 0x0c0cbea0u: goto P_0c0cbea0;
case 0x0c0cbea2u: goto P_0c0cbea2;
case 0x0c0cbea4u: goto P_0c0cbea4;
case 0x0c0cbea6u: goto P_0c0cbea6;
case 0x0c0cbea8u: goto P_0c0cbea8;
case 0x0c0cbeaau: goto P_0c0cbeaa;
case 0x0c0cbeacu: goto P_0c0cbeac;
case 0x0c0cbeaeu: goto P_0c0cbeae;
case 0x0c0cbeb0u: goto P_0c0cbeb0;
case 0x0c0cbeb2u: goto P_0c0cbeb2;
case 0x0c0cbeb4u: goto P_0c0cbeb4;
case 0x0c0cbeb6u: goto P_0c0cbeb6;
case 0x0c0cbeb8u: goto P_0c0cbeb8;
case 0x0c0cbebau: goto P_0c0cbeba;
case 0x0c0cbebcu: goto P_0c0cbebc;
case 0x0c0cbebeu: goto P_0c0cbebe;
case 0x0c0cbec0u: goto P_0c0cbec0;
case 0x0c0cbec2u: goto P_0c0cbec2;
case 0x0c0cbec4u: goto P_0c0cbec4;
case 0x0c0cbec6u: goto P_0c0cbec6;
case 0x0c0cbec8u: goto P_0c0cbec8;
case 0x0c0cbecau: goto P_0c0cbeca;
case 0x0c0cbeccu: goto P_0c0cbecc;
case 0x0c0cbeceu: goto P_0c0cbece;
case 0x0c0cbed0u: goto P_0c0cbed0;
case 0x0c0cbed2u: goto P_0c0cbed2;
case 0x0c0cbed4u: goto P_0c0cbed4;
case 0x0c0cbed6u: goto P_0c0cbed6;
case 0x0c0cbed8u: goto P_0c0cbed8;
case 0x0c0cbedau: goto P_0c0cbeda;
case 0x0c0cbedcu: goto P_0c0cbedc;
case 0x0c0cbedeu: goto P_0c0cbede;
case 0x0c0cbee0u: goto P_0c0cbee0;
case 0x0c0cbee2u: goto P_0c0cbee2;
case 0x0c0cbee4u: goto P_0c0cbee4;
case 0x0c0cbee6u: goto P_0c0cbee6;
case 0x0c0cbee8u: goto P_0c0cbee8;
case 0x0c0cbeeau: goto P_0c0cbeea;
case 0x0c0cbeecu: goto P_0c0cbeec;
case 0x0c0cbeeeu: goto P_0c0cbeee;
case 0x0c0cbef0u: goto P_0c0cbef0;
case 0x0c0cbef2u: goto P_0c0cbef2;
case 0x0c0cbef4u: goto P_0c0cbef4;
case 0x0c0cbef6u: goto P_0c0cbef6;
case 0x0c0cbef8u: goto P_0c0cbef8;
case 0x0c0cbefau: goto P_0c0cbefa;
case 0x0c0cbefcu: goto P_0c0cbefc;
case 0x0c0cbefeu: goto P_0c0cbefe;
case 0x0c0cbf00u: goto P_0c0cbf00;
case 0x0c0cbf02u: goto P_0c0cbf02;
case 0x0c0cbf04u: goto P_0c0cbf04;
case 0x0c0cbf06u: goto P_0c0cbf06;
case 0x0c0cbf08u: goto P_0c0cbf08;
case 0x0c0cbf0au: goto P_0c0cbf0a;
case 0x0c0cbf0cu: goto P_0c0cbf0c;
case 0x0c0cbf0eu: goto P_0c0cbf0e;
case 0x0c0cbf10u: goto P_0c0cbf10;
case 0x0c0cbf12u: goto P_0c0cbf12;
case 0x0c0cbf14u: goto P_0c0cbf14;
case 0x0c0cbf16u: goto P_0c0cbf16;
case 0x0c0cbf18u: goto P_0c0cbf18;
case 0x0c0cbf1au: goto P_0c0cbf1a;
case 0x0c0cbf1cu: goto P_0c0cbf1c;
case 0x0c0cbf1eu: goto P_0c0cbf1e;
case 0x0c0cbf20u: goto P_0c0cbf20;
case 0x0c0cbf22u: goto P_0c0cbf22;
case 0x0c0cbf24u: goto P_0c0cbf24;
case 0x0c0cbf26u: goto P_0c0cbf26;
case 0x0c0cbf28u: goto P_0c0cbf28;
case 0x0c0cbf2au: goto P_0c0cbf2a;
case 0x0c0cbf2cu: goto P_0c0cbf2c;
case 0x0c0cbf2eu: goto P_0c0cbf2e;
case 0x0c0cbf30u: goto P_0c0cbf30;
case 0x0c0cbf32u: goto P_0c0cbf32;
case 0x0c0cbf34u: goto P_0c0cbf34;
case 0x0c0cbf36u: goto P_0c0cbf36;
case 0x0c0cbf38u: goto P_0c0cbf38;
case 0x0c0cbf3au: goto P_0c0cbf3a;
case 0x0c0cbf3cu: goto P_0c0cbf3c;
case 0x0c0cbf3eu: goto P_0c0cbf3e;
case 0x0c0cbf40u: goto P_0c0cbf40;
case 0x0c0cbf42u: goto P_0c0cbf42;
case 0x0c0cbf44u: goto P_0c0cbf44;
case 0x0c0cbf46u: goto P_0c0cbf46;
case 0x0c0cbf48u: goto P_0c0cbf48;
case 0x0c0cbf4au: goto P_0c0cbf4a;
case 0x0c0cbf4cu: goto P_0c0cbf4c;
case 0x0c0cbf4eu: goto P_0c0cbf4e;
case 0x0c0cbf50u: goto P_0c0cbf50;
case 0x0c0cbf52u: goto P_0c0cbf52;
case 0x0c0cbf54u: goto P_0c0cbf54;
case 0x0c0cbf56u: goto P_0c0cbf56;
case 0x0c0cbf58u: goto P_0c0cbf58;
case 0x0c0cbf5au: goto P_0c0cbf5a;
case 0x0c0cbf5cu: goto P_0c0cbf5c;
case 0x0c0cbf5eu: goto P_0c0cbf5e;
case 0x0c0cbf60u: goto P_0c0cbf60;
case 0x0c0cbf62u: goto P_0c0cbf62;
case 0x0c0cbf64u: goto P_0c0cbf64;
case 0x0c0cbf66u: goto P_0c0cbf66;
case 0x0c0cbf68u: goto P_0c0cbf68;
case 0x0c0cbf6au: goto P_0c0cbf6a;
case 0x0c0cbf6cu: goto P_0c0cbf6c;
case 0x0c0cbf6eu: goto P_0c0cbf6e;
case 0x0c0cbf70u: goto P_0c0cbf70;
case 0x0c0cbf72u: goto P_0c0cbf72;
case 0x0c0cbf74u: goto P_0c0cbf74;
case 0x0c0cbf76u: goto P_0c0cbf76;
case 0x0c0cbf78u: goto P_0c0cbf78;
case 0x0c0cbf7au: goto P_0c0cbf7a;
case 0x0c0cbf7cu: goto P_0c0cbf7c;
case 0x0c0cbf7eu: goto P_0c0cbf7e;
case 0x0c0cbf80u: goto P_0c0cbf80;
case 0x0c0cbf82u: goto P_0c0cbf82;
case 0x0c0cbf84u: goto P_0c0cbf84;
case 0x0c0cbf86u: goto P_0c0cbf86;
case 0x0c0cbf88u: goto P_0c0cbf88;
case 0x0c0cbf8au: goto P_0c0cbf8a;
case 0x0c0cbf8cu: goto P_0c0cbf8c;
case 0x0c0cbf8eu: goto P_0c0cbf8e;
case 0x0c0cbf90u: goto P_0c0cbf90;
case 0x0c0cbf92u: goto P_0c0cbf92;
case 0x0c0cbf94u: goto P_0c0cbf94;
case 0x0c0cbf96u: goto P_0c0cbf96;
case 0x0c0cbf98u: goto P_0c0cbf98;
case 0x0c0cbf9au: goto P_0c0cbf9a;
case 0x0c0cbf9cu: goto P_0c0cbf9c;
case 0x0c0cbf9eu: goto P_0c0cbf9e;
case 0x0c0cbfa0u: goto P_0c0cbfa0;
case 0x0c0cbfa2u: goto P_0c0cbfa2;
case 0x0c0cbfa4u: goto P_0c0cbfa4;
case 0x0c0cbfa6u: goto P_0c0cbfa6;
case 0x0c0cbfa8u: goto P_0c0cbfa8;
case 0x0c0cbfaau: goto P_0c0cbfaa;
case 0x0c0cbfacu: goto P_0c0cbfac;
case 0x0c0cbfaeu: goto P_0c0cbfae;
case 0x0c0cbfb0u: goto P_0c0cbfb0;
case 0x0c0cbfb2u: goto P_0c0cbfb2;
case 0x0c0cbfb4u: goto P_0c0cbfb4;
case 0x0c0cbfb6u: goto P_0c0cbfb6;
case 0x0c0cbfb8u: goto P_0c0cbfb8;
case 0x0c0cbfbau: goto P_0c0cbfba;
case 0x0c0cbfbcu: goto P_0c0cbfbc;
case 0x0c0cbfbeu: goto P_0c0cbfbe;
case 0x0c0cbfc0u: goto P_0c0cbfc0;
case 0x0c0cbfc2u: goto P_0c0cbfc2;
case 0x0c0cbfc4u: goto P_0c0cbfc4;
case 0x0c0cbfc6u: goto P_0c0cbfc6;
case 0x0c0cbfc8u: goto P_0c0cbfc8;
case 0x0c0cbfcau: goto P_0c0cbfca;
case 0x0c0cbfccu: goto P_0c0cbfcc;
case 0x0c0cbfceu: goto P_0c0cbfce;
case 0x0c0cbfd0u: goto P_0c0cbfd0;
case 0x0c0cbfd2u: goto P_0c0cbfd2;
case 0x0c0cbfd4u: goto P_0c0cbfd4;
case 0x0c0cbfd6u: goto P_0c0cbfd6;
case 0x0c0cbfd8u: goto P_0c0cbfd8;
case 0x0c0cbfdau: goto P_0c0cbfda;
case 0x0c0cbfdcu: goto P_0c0cbfdc;
case 0x0c0cbfdeu: goto P_0c0cbfde;
case 0x0c0cbfe0u: goto P_0c0cbfe0;
case 0x0c0cbfe2u: goto P_0c0cbfe2;
case 0x0c0cbfe4u: goto P_0c0cbfe4;
case 0x0c0cbfe6u: goto P_0c0cbfe6;
case 0x0c0cbfe8u: goto P_0c0cbfe8;
case 0x0c0cbfeau: goto P_0c0cbfea;
case 0x0c0cbfecu: goto P_0c0cbfec;
case 0x0c0cbfeeu: goto P_0c0cbfee;
case 0x0c0cbff0u: goto P_0c0cbff0;
case 0x0c0cbff2u: goto P_0c0cbff2;
case 0x0c0cbff4u: goto P_0c0cbff4;
case 0x0c0cbff6u: goto P_0c0cbff6;
case 0x0c0cbff8u: goto P_0c0cbff8;
case 0x0c0cbffau: goto P_0c0cbffa;
case 0x0c0cbffcu: goto P_0c0cbffc;
case 0x0c0cbffeu: goto P_0c0cbffe;
case 0x0c0cc000u: goto P_0c0cc000;
case 0x0c0cc002u: goto P_0c0cc002;
case 0x0c0cc004u: goto P_0c0cc004;
case 0x0c0cc006u: goto P_0c0cc006;
case 0x0c0cc008u: goto P_0c0cc008;
case 0x0c0cc00au: goto P_0c0cc00a;
case 0x0c0cc00cu: goto P_0c0cc00c;
case 0x0c0cc00eu: goto P_0c0cc00e;
case 0x0c0cc010u: goto P_0c0cc010;
case 0x0c0cc012u: goto P_0c0cc012;
case 0x0c0cc014u: goto P_0c0cc014;
case 0x0c0cc016u: goto P_0c0cc016;
case 0x0c0cc018u: goto P_0c0cc018;
case 0x0c0cc044u: goto P_0c0cc044;
case 0x0c0cc046u: goto P_0c0cc046;
case 0x0c0cc048u: goto P_0c0cc048;
case 0x0c0cc04au: goto P_0c0cc04a;
case 0x0c0cc04cu: goto P_0c0cc04c;
case 0x0c0cc04eu: goto P_0c0cc04e;
case 0x0c0cc050u: goto P_0c0cc050;
case 0x0c0cc052u: goto P_0c0cc052;
case 0x0c0cc054u: goto P_0c0cc054;
case 0x0c0cc056u: goto P_0c0cc056;
case 0x0c0cc058u: goto P_0c0cc058;
case 0x0c0cc05au: goto P_0c0cc05a;
case 0x0c0cc05cu: goto P_0c0cc05c;
case 0x0c0cc05eu: goto P_0c0cc05e;
case 0x0c0cc060u: goto P_0c0cc060;
case 0x0c0cc062u: goto P_0c0cc062;
case 0x0c0cc064u: goto P_0c0cc064;
case 0x0c0cc066u: goto P_0c0cc066;
case 0x0c0cc068u: goto P_0c0cc068;
case 0x0c0cc06au: goto P_0c0cc06a;
case 0x0c0cc06cu: goto P_0c0cc06c;
case 0x0c0cc06eu: goto P_0c0cc06e;
case 0x0c0cc070u: goto P_0c0cc070;
case 0x0c0cc072u: goto P_0c0cc072;
case 0x0c0cc074u: goto P_0c0cc074;
case 0x0c0cc076u: goto P_0c0cc076;
case 0x0c0cc078u: goto P_0c0cc078;
case 0x0c0cc07au: goto P_0c0cc07a;
case 0x0c0cc07cu: goto P_0c0cc07c;
case 0x0c0cc07eu: goto P_0c0cc07e;
case 0x0c0cc080u: goto P_0c0cc080;
case 0x0c0cc082u: goto P_0c0cc082;
case 0x0c0cc084u: goto P_0c0cc084;
case 0x0c0cc086u: goto P_0c0cc086;
case 0x0c0cc088u: goto P_0c0cc088;
case 0x0c0cc08au: goto P_0c0cc08a;
case 0x0c0cc08cu: goto P_0c0cc08c;
case 0x0c0cc08eu: goto P_0c0cc08e;
case 0x0c0cc090u: goto P_0c0cc090;
case 0x0c0cc092u: goto P_0c0cc092;
case 0x0c0cc094u: goto P_0c0cc094;
case 0x0c0cc096u: goto P_0c0cc096;
case 0x0c0cc098u: goto P_0c0cc098;
case 0x0c0cc09au: goto P_0c0cc09a;
case 0x0c0cc09cu: goto P_0c0cc09c;
case 0x0c0cc09eu: goto P_0c0cc09e;
case 0x0c0cc0a0u: goto P_0c0cc0a0;
case 0x0c0cc0a2u: goto P_0c0cc0a2;
case 0x0c0cc0a4u: goto P_0c0cc0a4;
case 0x0c0cc0a6u: goto P_0c0cc0a6;
case 0x0c0cc0a8u: goto P_0c0cc0a8;
case 0x0c0cc0aau: goto P_0c0cc0aa;
case 0x0c0cc0acu: goto P_0c0cc0ac;
case 0x0c0cc0aeu: goto P_0c0cc0ae;
case 0x0c0cc0b0u: goto P_0c0cc0b0;
case 0x0c0cc0b2u: goto P_0c0cc0b2;
case 0x0c0cc0b4u: goto P_0c0cc0b4;
case 0x0c0cc0b6u: goto P_0c0cc0b6;
case 0x0c0cc0b8u: goto P_0c0cc0b8;
case 0x0c0cc0bau: goto P_0c0cc0ba;
case 0x0c0cc0bcu: goto P_0c0cc0bc;
case 0x0c0cc0beu: goto P_0c0cc0be;
case 0x0c0cc0c0u: goto P_0c0cc0c0;
case 0x0c0cc0c2u: goto P_0c0cc0c2;
case 0x0c0cc0c4u: goto P_0c0cc0c4;
case 0x0c0cc0c6u: goto P_0c0cc0c6;
case 0x0c0cc0c8u: goto P_0c0cc0c8;
case 0x0c0cc0cau: goto P_0c0cc0ca;
case 0x0c0cc0ccu: goto P_0c0cc0cc;
case 0x0c0cc0ceu: goto P_0c0cc0ce;
case 0x0c0cc0d0u: goto P_0c0cc0d0;
case 0x0c0cc0d2u: goto P_0c0cc0d2;
case 0x0c0cc0d4u: goto P_0c0cc0d4;
case 0x0c0cc0d6u: goto P_0c0cc0d6;
case 0x0c0cc0d8u: goto P_0c0cc0d8;
case 0x0c0cc0dau: goto P_0c0cc0da;
case 0x0c0cc0dcu: goto P_0c0cc0dc;
case 0x0c0cc0deu: goto P_0c0cc0de;
case 0x0c0cc0e0u: goto P_0c0cc0e0;
case 0x0c0cc0e2u: goto P_0c0cc0e2;
case 0x0c0cc0e4u: goto P_0c0cc0e4;
case 0x0c0cc0e6u: goto P_0c0cc0e6;
case 0x0c0cc0e8u: goto P_0c0cc0e8;
case 0x0c0cc0eau: goto P_0c0cc0ea;
case 0x0c0cc0ecu: goto P_0c0cc0ec;
case 0x0c0cc0eeu: goto P_0c0cc0ee;
case 0x0c0cc0f0u: goto P_0c0cc0f0;
case 0x0c0cc0f2u: goto P_0c0cc0f2;
case 0x0c0cc0f4u: goto P_0c0cc0f4;
case 0x0c0cc0f6u: goto P_0c0cc0f6;
case 0x0c0cc0f8u: goto P_0c0cc0f8;
case 0x0c0cc0fau: goto P_0c0cc0fa;
case 0x0c0cc0fcu: goto P_0c0cc0fc;
case 0x0c0cc0feu: goto P_0c0cc0fe;
case 0x0c0cc100u: goto P_0c0cc100;
case 0x0c0cc102u: goto P_0c0cc102;
case 0x0c0cc104u: goto P_0c0cc104;
case 0x0c0cc106u: goto P_0c0cc106;
case 0x0c0cc108u: goto P_0c0cc108;
case 0x0c0cc10au: goto P_0c0cc10a;
case 0x0c0cc10cu: goto P_0c0cc10c;
case 0x0c0cc10eu: goto P_0c0cc10e;
case 0x0c0cc110u: goto P_0c0cc110;
case 0x0c0cc112u: goto P_0c0cc112;
case 0x0c0cc114u: goto P_0c0cc114;
case 0x0c0cc116u: goto P_0c0cc116;
case 0x0c0cc118u: goto P_0c0cc118;
case 0x0c0cc11au: goto P_0c0cc11a;
case 0x0c0cc11cu: goto P_0c0cc11c;
case 0x0c0cc11eu: goto P_0c0cc11e;
case 0x0c0cc120u: goto P_0c0cc120;
case 0x0c0cc122u: goto P_0c0cc122;
case 0x0c0cc124u: goto P_0c0cc124;
case 0x0c0cc126u: goto P_0c0cc126;
case 0x0c0cc128u: goto P_0c0cc128;
case 0x0c0cc12au: goto P_0c0cc12a;
case 0x0c0cc12cu: goto P_0c0cc12c;
case 0x0c0cc12eu: goto P_0c0cc12e;
case 0x0c0cc130u: goto P_0c0cc130;
case 0x0c0cc132u: goto P_0c0cc132;
case 0x0c0cc134u: goto P_0c0cc134;
case 0x0c0cc136u: goto P_0c0cc136;
case 0x0c0cc138u: goto P_0c0cc138;
case 0x0c0cc13au: goto P_0c0cc13a;
case 0x0c0cc13cu: goto P_0c0cc13c;
case 0x0c0cc13eu: goto P_0c0cc13e;
case 0x0c0cc140u: goto P_0c0cc140;
case 0x0c0cc142u: goto P_0c0cc142;
case 0x0c0cc144u: goto P_0c0cc144;
case 0x0c0cc146u: goto P_0c0cc146;
case 0x0c0cc148u: goto P_0c0cc148;
case 0x0c0cc14au: goto P_0c0cc14a;
case 0x0c0cc14cu: goto P_0c0cc14c;
case 0x0c0cc14eu: goto P_0c0cc14e;
case 0x0c0cc150u: goto P_0c0cc150;
case 0x0c0cc152u: goto P_0c0cc152;
case 0x0c0cc154u: goto P_0c0cc154;
case 0x0c0cc156u: goto P_0c0cc156;
case 0x0c0cc158u: goto P_0c0cc158;
case 0x0c0cc15au: goto P_0c0cc15a;
case 0x0c0cc15cu: goto P_0c0cc15c;
case 0x0c0cc15eu: goto P_0c0cc15e;
case 0x0c0cc160u: goto P_0c0cc160;
case 0x0c0cc162u: goto P_0c0cc162;
case 0x0c0cc164u: goto P_0c0cc164;
case 0x0c0cc166u: goto P_0c0cc166;
case 0x0c0cc168u: goto P_0c0cc168;
case 0x0c0cc16au: goto P_0c0cc16a;
case 0x0c0cc16cu: goto P_0c0cc16c;
case 0x0c0cc16eu: goto P_0c0cc16e;
case 0x0c0cc170u: goto P_0c0cc170;
case 0x0c0cc172u: goto P_0c0cc172;
case 0x0c0cc174u: goto P_0c0cc174;
case 0x0c0cc176u: goto P_0c0cc176;
case 0x0c0cc178u: goto P_0c0cc178;
case 0x0c0cc17au: goto P_0c0cc17a;
case 0x0c0cc17cu: goto P_0c0cc17c;
case 0x0c0cc17eu: goto P_0c0cc17e;
case 0x0c0cc180u: goto P_0c0cc180;
case 0x0c0cc182u: goto P_0c0cc182;
case 0x0c0cc184u: goto P_0c0cc184;
case 0x0c0cc186u: goto P_0c0cc186;
case 0x0c0cc188u: goto P_0c0cc188;
case 0x0c0cc18au: goto P_0c0cc18a;
case 0x0c0cc18cu: goto P_0c0cc18c;
case 0x0c0cc18eu: goto P_0c0cc18e;
case 0x0c0cc190u: goto P_0c0cc190;
case 0x0c0cc192u: goto P_0c0cc192;
case 0x0c0cc194u: goto P_0c0cc194;
case 0x0c0cc196u: goto P_0c0cc196;
case 0x0c0cc198u: goto P_0c0cc198;
case 0x0c0cc19au: goto P_0c0cc19a;
case 0x0c0cc19cu: goto P_0c0cc19c;
case 0x0c0cc19eu: goto P_0c0cc19e;
case 0x0c0cc1a0u: goto P_0c0cc1a0;
case 0x0c0cc1a2u: goto P_0c0cc1a2;
case 0x0c0cc1a4u: goto P_0c0cc1a4;
case 0x0c0cc1a6u: goto P_0c0cc1a6;
case 0x0c0cc1a8u: goto P_0c0cc1a8;
case 0x0c0cc1aau: goto P_0c0cc1aa;
case 0x0c0cc1acu: goto P_0c0cc1ac;
case 0x0c0cc1aeu: goto P_0c0cc1ae;
case 0x0c0cc1b0u: goto P_0c0cc1b0;
case 0x0c0cc1b2u: goto P_0c0cc1b2;
case 0x0c0cc1b4u: goto P_0c0cc1b4;
case 0x0c0cc1b6u: goto P_0c0cc1b6;
case 0x0c0cc1b8u: goto P_0c0cc1b8;
case 0x0c0cc1bau: goto P_0c0cc1ba;
case 0x0c0cc1bcu: goto P_0c0cc1bc;
case 0x0c0cc1beu: goto P_0c0cc1be;
case 0x0c0cc1c0u: goto P_0c0cc1c0;
case 0x0c0cc1c2u: goto P_0c0cc1c2;
case 0x0c0cc1c4u: goto P_0c0cc1c4;
case 0x0c0cc1c6u: goto P_0c0cc1c6;
case 0x0c0cc1c8u: goto P_0c0cc1c8;
case 0x0c0cc1cau: goto P_0c0cc1ca;
case 0x0c0cc1ccu: goto P_0c0cc1cc;
case 0x0c0cc1ceu: goto P_0c0cc1ce;
case 0x0c0cc1d0u: goto P_0c0cc1d0;
case 0x0c0cc1d2u: goto P_0c0cc1d2;
case 0x0c0cc1d4u: goto P_0c0cc1d4;
case 0x0c0cc1d6u: goto P_0c0cc1d6;
case 0x0c0cc1d8u: goto P_0c0cc1d8;
case 0x0c0cc1dau: goto P_0c0cc1da;
case 0x0c0cc1dcu: goto P_0c0cc1dc;
case 0x0c0cc1deu: goto P_0c0cc1de;
case 0x0c0cc1e0u: goto P_0c0cc1e0;
case 0x0c0cc1e2u: goto P_0c0cc1e2;
case 0x0c0cc1e4u: goto P_0c0cc1e4;
case 0x0c0cc1e6u: goto P_0c0cc1e6;
case 0x0c0cc1e8u: goto P_0c0cc1e8;
case 0x0c0cc1eau: goto P_0c0cc1ea;
case 0x0c0cc1ecu: goto P_0c0cc1ec;
case 0x0c0cc1eeu: goto P_0c0cc1ee;
case 0x0c0cc1f0u: goto P_0c0cc1f0;
case 0x0c0cc1f2u: goto P_0c0cc1f2;
case 0x0c0cc1f4u: goto P_0c0cc1f4;
case 0x0c0cc1f6u: goto P_0c0cc1f6;
case 0x0c0cc1f8u: goto P_0c0cc1f8;
case 0x0c0cc1fau: goto P_0c0cc1fa;
case 0x0c0cc1fcu: goto P_0c0cc1fc;
case 0x0c0cc1feu: goto P_0c0cc1fe;
case 0x0c0cc200u: goto P_0c0cc200;
case 0x0c0cc202u: goto P_0c0cc202;
case 0x0c0cc204u: goto P_0c0cc204;
case 0x0c0cc206u: goto P_0c0cc206;
case 0x0c0cc208u: goto P_0c0cc208;
case 0x0c0cc20au: goto P_0c0cc20a;
case 0x0c0cc20cu: goto P_0c0cc20c;
case 0x0c0cc20eu: goto P_0c0cc20e;
case 0x0c0cc210u: goto P_0c0cc210;
case 0x0c0cc212u: goto P_0c0cc212;
case 0x0c0cc214u: goto P_0c0cc214;
case 0x0c0cc216u: goto P_0c0cc216;
case 0x0c0cc218u: goto P_0c0cc218;
case 0x0c0cc21au: goto P_0c0cc21a;
case 0x0c0cc21cu: goto P_0c0cc21c;
case 0x0c0cc21eu: goto P_0c0cc21e;
case 0x0c0cc220u: goto P_0c0cc220;
case 0x0c0cc222u: goto P_0c0cc222;
case 0x0c0cc224u: goto P_0c0cc224;
case 0x0c0cc226u: goto P_0c0cc226;
case 0x0c0cc228u: goto P_0c0cc228;
case 0x0c0cc22au: goto P_0c0cc22a;
case 0x0c0cc22cu: goto P_0c0cc22c;
case 0x0c0cc22eu: goto P_0c0cc22e;
case 0x0c0cc230u: goto P_0c0cc230;
case 0x0c0cc232u: goto P_0c0cc232;
case 0x0c0cc234u: goto P_0c0cc234;
case 0x0c0cc236u: goto P_0c0cc236;
case 0x0c0cc238u: goto P_0c0cc238;
case 0x0c0cc23au: goto P_0c0cc23a;
case 0x0c0cc23cu: goto P_0c0cc23c;
case 0x0c0cc23eu: goto P_0c0cc23e;
case 0x0c0cc240u: goto P_0c0cc240;
case 0x0c0cc242u: goto P_0c0cc242;
case 0x0c0cc244u: goto P_0c0cc244;
case 0x0c0cc246u: goto P_0c0cc246;
case 0x0c0cc248u: goto P_0c0cc248;
case 0x0c0cc24au: goto P_0c0cc24a;
case 0x0c0cc24cu: goto P_0c0cc24c;
case 0x0c0cc24eu: goto P_0c0cc24e;
case 0x0c0cc250u: goto P_0c0cc250;
case 0x0c0cc252u: goto P_0c0cc252;
case 0x0c0cc254u: goto P_0c0cc254;
case 0x0c0cc256u: goto P_0c0cc256;
case 0x0c0cc258u: goto P_0c0cc258;
case 0x0c0cc25au: goto P_0c0cc25a;
case 0x0c0cc25cu: goto P_0c0cc25c;
case 0x0c0cc25eu: goto P_0c0cc25e;
case 0x0c0cc260u: goto P_0c0cc260;
case 0x0c0cc262u: goto P_0c0cc262;
case 0x0c0cc264u: goto P_0c0cc264;
case 0x0c0cc266u: goto P_0c0cc266;
case 0x0c0cc268u: goto P_0c0cc268;
case 0x0c0cc26au: goto P_0c0cc26a;
case 0x0c0cc26cu: goto P_0c0cc26c;
case 0x0c0cc26eu: goto P_0c0cc26e;
case 0x0c0cc270u: goto P_0c0cc270;
case 0x0c0cc272u: goto P_0c0cc272;
case 0x0c0cc274u: goto P_0c0cc274;
case 0x0c0cc276u: goto P_0c0cc276;
case 0x0c0cc278u: goto P_0c0cc278;
case 0x0c0cc27au: goto P_0c0cc27a;
case 0x0c0cc27cu: goto P_0c0cc27c;
case 0x0c0cc27eu: goto P_0c0cc27e;
case 0x0c0cc280u: goto P_0c0cc280;
case 0x0c0cc282u: goto P_0c0cc282;
case 0x0c0cc284u: goto P_0c0cc284;
case 0x0c0cc286u: goto P_0c0cc286;
case 0x0c0cc288u: goto P_0c0cc288;
case 0x0c0cc28au: goto P_0c0cc28a;
case 0x0c0cc28cu: goto P_0c0cc28c;
case 0x0c0cc28eu: goto P_0c0cc28e;
case 0x0c0cc290u: goto P_0c0cc290;
case 0x0c0cc292u: goto P_0c0cc292;
case 0x0c0cc294u: goto P_0c0cc294;
case 0x0c0cc296u: goto P_0c0cc296;
case 0x0c0cc298u: goto P_0c0cc298;
case 0x0c0cc29au: goto P_0c0cc29a;
case 0x0c0cc29cu: goto P_0c0cc29c;
case 0x0c0cc29eu: goto P_0c0cc29e;
case 0x0c0cc2a0u: goto P_0c0cc2a0;
case 0x0c0cc2a2u: goto P_0c0cc2a2;
case 0x0c0cc2a4u: goto P_0c0cc2a4;
case 0x0c0cc2a6u: goto P_0c0cc2a6;
case 0x0c0cc2a8u: goto P_0c0cc2a8;
case 0x0c0cc2aau: goto P_0c0cc2aa;
case 0x0c0cc2acu: goto P_0c0cc2ac;
case 0x0c0cc2aeu: goto P_0c0cc2ae;
case 0x0c0cc2b0u: goto P_0c0cc2b0;
case 0x0c0cc2b2u: goto P_0c0cc2b2;
case 0x0c0cc2b4u: goto P_0c0cc2b4;
case 0x0c0cc2b6u: goto P_0c0cc2b6;
case 0x0c0cc2b8u: goto P_0c0cc2b8;
case 0x0c0cc2bau: goto P_0c0cc2ba;
case 0x0c0cc2bcu: goto P_0c0cc2bc;
case 0x0c0cc2beu: goto P_0c0cc2be;
case 0x0c0cc2c0u: goto P_0c0cc2c0;
case 0x0c0cc2c2u: goto P_0c0cc2c2;
case 0x0c0cc2c4u: goto P_0c0cc2c4;
case 0x0c0cc2c6u: goto P_0c0cc2c6;
case 0x0c0cc2c8u: goto P_0c0cc2c8;
case 0x0c0cc2cau: goto P_0c0cc2ca;
case 0x0c0cc2ccu: goto P_0c0cc2cc;
case 0x0c0cc2ceu: goto P_0c0cc2ce;
case 0x0c0cc2d0u: goto P_0c0cc2d0;
case 0x0c0cc2d2u: goto P_0c0cc2d2;
case 0x0c0cc2d4u: goto P_0c0cc2d4;
case 0x0c0cc67cu: goto P_0c0cc67c;
case 0x0c0cc67eu: goto P_0c0cc67e;
case 0x0c0cc680u: goto P_0c0cc680;
case 0x0c0cc682u: goto P_0c0cc682;
case 0x0c0cc684u: goto P_0c0cc684;
case 0x0c0cc686u: goto P_0c0cc686;
case 0x0c0cc688u: goto P_0c0cc688;
case 0x0c0cc68au: goto P_0c0cc68a;
case 0x0c0cc68cu: goto P_0c0cc68c;
case 0x0c0cc68eu: goto P_0c0cc68e;
case 0x0c0cc690u: goto P_0c0cc690;
case 0x0c0cc692u: goto P_0c0cc692;
case 0x0c0cc694u: goto P_0c0cc694;
case 0x0c0cc696u: goto P_0c0cc696;
case 0x0c0cc698u: goto P_0c0cc698;
case 0x0c0cc69au: goto P_0c0cc69a;
case 0x0c0cc69cu: goto P_0c0cc69c;
case 0x0c0cc69eu: goto P_0c0cc69e;
case 0x0c0cc6a0u: goto P_0c0cc6a0;
case 0x0c0cc6a2u: goto P_0c0cc6a2;
case 0x0c0cc6a4u: goto P_0c0cc6a4;
case 0x0c0cc6a6u: goto P_0c0cc6a6;
case 0x0c0cc6a8u: goto P_0c0cc6a8;
case 0x0c0cc6aau: goto P_0c0cc6aa;
case 0x0c0cc6acu: goto P_0c0cc6ac;
case 0x0c0cc6aeu: goto P_0c0cc6ae;
case 0x0c0cc6b0u: goto P_0c0cc6b0;
case 0x0c0cc6b2u: goto P_0c0cc6b2;
case 0x0c0cc6b4u: goto P_0c0cc6b4;
case 0x0c0cc6b6u: goto P_0c0cc6b6;
case 0x0c0cc6b8u: goto P_0c0cc6b8;
case 0x0c0cc6bau: goto P_0c0cc6ba;
case 0x0c0cc6bcu: goto P_0c0cc6bc;
case 0x0c0cc6beu: goto P_0c0cc6be;
case 0x0c0cc6c0u: goto P_0c0cc6c0;
case 0x0c0cc6c2u: goto P_0c0cc6c2;
case 0x0c0cc6c4u: goto P_0c0cc6c4;
case 0x0c0cc6c6u: goto P_0c0cc6c6;
case 0x0c0cc6c8u: goto P_0c0cc6c8;
case 0x0c0cc6cau: goto P_0c0cc6ca;
case 0x0c0cc6ccu: goto P_0c0cc6cc;
case 0x0c0cc6ceu: goto P_0c0cc6ce;
case 0x0c0cc6d0u: goto P_0c0cc6d0;
case 0x0c0cc6d2u: goto P_0c0cc6d2;
case 0x0c0cc6d4u: goto P_0c0cc6d4;
case 0x0c0cc6d6u: goto P_0c0cc6d6;
case 0x0c0cc6d8u: goto P_0c0cc6d8;
case 0x0c0cc6dau: goto P_0c0cc6da;
case 0x0c0cc6dcu: goto P_0c0cc6dc;
case 0x0c0cc6deu: goto P_0c0cc6de;
case 0x0c0cc6e0u: goto P_0c0cc6e0;
case 0x0c0cc6e2u: goto P_0c0cc6e2;
case 0x0c0cc6e4u: goto P_0c0cc6e4;
case 0x0c0cc6e6u: goto P_0c0cc6e6;
case 0x0c0cc6e8u: goto P_0c0cc6e8;
case 0x0c0cc6eau: goto P_0c0cc6ea;
case 0x0c0cc6ecu: goto P_0c0cc6ec;
case 0x0c0cc6eeu: goto P_0c0cc6ee;
case 0x0c0cc6f0u: goto P_0c0cc6f0;
case 0x0c0cc6f2u: goto P_0c0cc6f2;
case 0x0c0cc6f4u: goto P_0c0cc6f4;
case 0x0c0cc6f6u: goto P_0c0cc6f6;
case 0x0c0cc6f8u: goto P_0c0cc6f8;
case 0x0c0cc6fau: goto P_0c0cc6fa;
case 0x0c0cc6fcu: goto P_0c0cc6fc;
case 0x0c0cc6feu: goto P_0c0cc6fe;
case 0x0c0cc700u: goto P_0c0cc700;
case 0x0c0cc702u: goto P_0c0cc702;
case 0x0c0cc704u: goto P_0c0cc704;
case 0x0c0cc706u: goto P_0c0cc706;
case 0x0c0cc708u: goto P_0c0cc708;
case 0x0c0cc70au: goto P_0c0cc70a;
case 0x0c0cc70cu: goto P_0c0cc70c;
case 0x0c0cc70eu: goto P_0c0cc70e;
case 0x0c0cc710u: goto P_0c0cc710;
case 0x0c0cc712u: goto P_0c0cc712;
case 0x0c0cc714u: goto P_0c0cc714;
case 0x0c0cc716u: goto P_0c0cc716;
case 0x0c0cc718u: goto P_0c0cc718;
case 0x0c0cc71au: goto P_0c0cc71a;
case 0x0c0cc71cu: goto P_0c0cc71c;
case 0x0c0cc71eu: goto P_0c0cc71e;
case 0x0c0cc720u: goto P_0c0cc720;
case 0x0c0cc722u: goto P_0c0cc722;
case 0x0c0cc724u: goto P_0c0cc724;
case 0x0c0cc726u: goto P_0c0cc726;
case 0x0c0cc728u: goto P_0c0cc728;
case 0x0c0cc72au: goto P_0c0cc72a;
case 0x0c0cc72cu: goto P_0c0cc72c;
case 0x0c0cc72eu: goto P_0c0cc72e;
case 0x0c0cc730u: goto P_0c0cc730;
case 0x0c0cc732u: goto P_0c0cc732;
case 0x0c0cc734u: goto P_0c0cc734;
case 0x0c0cc736u: goto P_0c0cc736;
case 0x0c0cc738u: goto P_0c0cc738;
case 0x0c0cc73au: goto P_0c0cc73a;
case 0x0c0cc73cu: goto P_0c0cc73c;
case 0x0c0cc73eu: goto P_0c0cc73e;
case 0x0c0cc740u: goto P_0c0cc740;
case 0x0c0cc742u: goto P_0c0cc742;
case 0x0c0cc744u: goto P_0c0cc744;
case 0x0c0cc746u: goto P_0c0cc746;
case 0x0c0cc748u: goto P_0c0cc748;
case 0x0c0cc74au: goto P_0c0cc74a;
case 0x0c0cc74cu: goto P_0c0cc74c;
case 0x0c0cc74eu: goto P_0c0cc74e;
case 0x0c0cc750u: goto P_0c0cc750;
case 0x0c0cc752u: goto P_0c0cc752;
case 0x0c0cc754u: goto P_0c0cc754;
case 0x0c0cc756u: goto P_0c0cc756;
case 0x0c0cc758u: goto P_0c0cc758;
case 0x0c0cc75au: goto P_0c0cc75a;
case 0x0c0cc75cu: goto P_0c0cc75c;
case 0x0c0cc75eu: goto P_0c0cc75e;
case 0x0c0cc760u: goto P_0c0cc760;
case 0x0c0cc762u: goto P_0c0cc762;
case 0x0c0cc764u: goto P_0c0cc764;
case 0x0c0cc766u: goto P_0c0cc766;
case 0x0c0cc768u: goto P_0c0cc768;
case 0x0c0cc76au: goto P_0c0cc76a;
case 0x0c0cc76cu: goto P_0c0cc76c;
case 0x0c0cc76eu: goto P_0c0cc76e;
case 0x0c0cc770u: goto P_0c0cc770;
case 0x0c0cc772u: goto P_0c0cc772;
case 0x0c0cc774u: goto P_0c0cc774;
case 0x0c0cc776u: goto P_0c0cc776;
case 0x0c0cc778u: goto P_0c0cc778;
case 0x0c0cc77au: goto P_0c0cc77a;
case 0x0c0cc77cu: goto P_0c0cc77c;
case 0x0c0cc7b4u: goto P_0c0cc7b4;
case 0x0c0cc7b6u: goto P_0c0cc7b6;
case 0x0c0cc7b8u: goto P_0c0cc7b8;
case 0x0c0cc7bau: goto P_0c0cc7ba;
case 0x0c0cc7bcu: goto P_0c0cc7bc;
case 0x0c0cc7beu: goto P_0c0cc7be;
case 0x0c0cc7c0u: goto P_0c0cc7c0;
case 0x0c0cc7c2u: goto P_0c0cc7c2;
case 0x0c0cc7c4u: goto P_0c0cc7c4;
case 0x0c0cc7c6u: goto P_0c0cc7c6;
case 0x0c0cc7c8u: goto P_0c0cc7c8;
case 0x0c0cc7cau: goto P_0c0cc7ca;
case 0x0c0cc7ccu: goto P_0c0cc7cc;
case 0x0c0cc7ceu: goto P_0c0cc7ce;
case 0x0c0cc7d0u: goto P_0c0cc7d0;
case 0x0c0cc7d2u: goto P_0c0cc7d2;
case 0x0c0cc7d4u: goto P_0c0cc7d4;
case 0x0c0cc7d6u: goto P_0c0cc7d6;
case 0x0c0cc7d8u: goto P_0c0cc7d8;
case 0x0c0cc7dau: goto P_0c0cc7da;
case 0x0c0cc7dcu: goto P_0c0cc7dc;
case 0x0c0cc7deu: goto P_0c0cc7de;
case 0x0c0cc7e0u: goto P_0c0cc7e0;
case 0x0c0cc7e2u: goto P_0c0cc7e2;
case 0x0c0cc7e4u: goto P_0c0cc7e4;
case 0x0c0cc7e6u: goto P_0c0cc7e6;
case 0x0c0cc7e8u: goto P_0c0cc7e8;
case 0x0c0cc7eau: goto P_0c0cc7ea;
case 0x0c0cc7ecu: goto P_0c0cc7ec;
case 0x0c0cc7eeu: goto P_0c0cc7ee;
case 0x0c0cc7f0u: goto P_0c0cc7f0;
case 0x0c0cc7f2u: goto P_0c0cc7f2;
case 0x0c0cc7f4u: goto P_0c0cc7f4;
case 0x0c0cc7f6u: goto P_0c0cc7f6;
case 0x0c0cc7f8u: goto P_0c0cc7f8;
case 0x0c0cc7fau: goto P_0c0cc7fa;
case 0x0c0cc7fcu: goto P_0c0cc7fc;
case 0x0c0cc7feu: goto P_0c0cc7fe;
case 0x0c0cc800u: goto P_0c0cc800;
case 0x0c0cc802u: goto P_0c0cc802;
case 0x0c0cc804u: goto P_0c0cc804;
case 0x0c0cc806u: goto P_0c0cc806;
case 0x0c0cc808u: goto P_0c0cc808;
case 0x0c0cc80au: goto P_0c0cc80a;
case 0x0c0cc80cu: goto P_0c0cc80c;
case 0x0c0cc80eu: goto P_0c0cc80e;
case 0x0c0cc810u: goto P_0c0cc810;
case 0x0c0cc812u: goto P_0c0cc812;
case 0x0c0cc814u: goto P_0c0cc814;
case 0x0c0cc816u: goto P_0c0cc816;
case 0x0c0cc818u: goto P_0c0cc818;
case 0x0c0cc81au: goto P_0c0cc81a;
case 0x0c0cc81cu: goto P_0c0cc81c;
case 0x0c0cc81eu: goto P_0c0cc81e;
case 0x0c0cc820u: goto P_0c0cc820;
case 0x0c0cc822u: goto P_0c0cc822;
case 0x0c0cc824u: goto P_0c0cc824;
case 0x0c0cc826u: goto P_0c0cc826;
case 0x0c0cc828u: goto P_0c0cc828;
case 0x0c0cc82au: goto P_0c0cc82a;
case 0x0c0cc82cu: goto P_0c0cc82c;
case 0x0c0cc82eu: goto P_0c0cc82e;
case 0x0c0cc830u: goto P_0c0cc830;
case 0x0c0cc832u: goto P_0c0cc832;
case 0x0c0cc834u: goto P_0c0cc834;
case 0x0c0cc836u: goto P_0c0cc836;
case 0x0c0cc838u: goto P_0c0cc838;
case 0x0c0cc83au: goto P_0c0cc83a;
case 0x0c0cc83cu: goto P_0c0cc83c;
case 0x0c0cc83eu: goto P_0c0cc83e;
case 0x0c0cc840u: goto P_0c0cc840;
case 0x0c0cc842u: goto P_0c0cc842;
case 0x0c0cc844u: goto P_0c0cc844;
case 0x0c0cc846u: goto P_0c0cc846;
case 0x0c0cc848u: goto P_0c0cc848;
case 0x0c0cc84au: goto P_0c0cc84a;
case 0x0c0cc84cu: goto P_0c0cc84c;
case 0x0c0cc84eu: goto P_0c0cc84e;
case 0x0c0cc850u: goto P_0c0cc850;
case 0x0c0cc852u: goto P_0c0cc852;
case 0x0c0cc854u: goto P_0c0cc854;
case 0x0c0cc856u: goto P_0c0cc856;
case 0x0c0cc858u: goto P_0c0cc858;
case 0x0c0cc85au: goto P_0c0cc85a;
case 0x0c0cc85cu: goto P_0c0cc85c;
case 0x0c0cc85eu: goto P_0c0cc85e;
case 0x0c0cc860u: goto P_0c0cc860;
case 0x0c0cc862u: goto P_0c0cc862;
case 0x0c0cc864u: goto P_0c0cc864;
case 0x0c0cc866u: goto P_0c0cc866;
case 0x0c0cc868u: goto P_0c0cc868;
case 0x0c0cc86au: goto P_0c0cc86a;
case 0x0c0cc86cu: goto P_0c0cc86c;
case 0x0c0cc86eu: goto P_0c0cc86e;
case 0x0c0cc870u: goto P_0c0cc870;
case 0x0c0cc872u: goto P_0c0cc872;
case 0x0c0cc874u: goto P_0c0cc874;
case 0x0c0cc876u: goto P_0c0cc876;
case 0x0c0cc878u: goto P_0c0cc878;
case 0x0c0cc87au: goto P_0c0cc87a;
case 0x0c0cc87cu: goto P_0c0cc87c;
case 0x0c0cc87eu: goto P_0c0cc87e;
case 0x0c0cc880u: goto P_0c0cc880;
case 0x0c0cc882u: goto P_0c0cc882;
case 0x0c0cc884u: goto P_0c0cc884;
case 0x0c0cc886u: goto P_0c0cc886;
case 0x0c0cc888u: goto P_0c0cc888;
case 0x0c0cc88au: goto P_0c0cc88a;
case 0x0c0cc88cu: goto P_0c0cc88c;
case 0x0c0cc88eu: goto P_0c0cc88e;
case 0x0c0cc890u: goto P_0c0cc890;
case 0x0c0cc892u: goto P_0c0cc892;
case 0x0c0cc894u: goto P_0c0cc894;
case 0x0c0cc896u: goto P_0c0cc896;
case 0x0c0cc898u: goto P_0c0cc898;
case 0x0c0cc89au: goto P_0c0cc89a;
case 0x0c0cc8f0u: goto P_0c0cc8f0;
case 0x0c0cc8f2u: goto P_0c0cc8f2;
case 0x0c0cc8f4u: goto P_0c0cc8f4;
case 0x0c0cc8f6u: goto P_0c0cc8f6;
case 0x0c0cc8f8u: goto P_0c0cc8f8;
case 0x0c0cc8fau: goto P_0c0cc8fa;
case 0x0c0cc8fcu: goto P_0c0cc8fc;
case 0x0c0cc8feu: goto P_0c0cc8fe;
case 0x0c0cc900u: goto P_0c0cc900;
case 0x0c0cc902u: goto P_0c0cc902;
case 0x0c0cc904u: goto P_0c0cc904;
case 0x0c0cc906u: goto P_0c0cc906;
case 0x0c0cc908u: goto P_0c0cc908;
case 0x0c0cc90au: goto P_0c0cc90a;
case 0x0c0cc90cu: goto P_0c0cc90c;
case 0x0c0cc90eu: goto P_0c0cc90e;
case 0x0c0cc910u: goto P_0c0cc910;
case 0x0c0cc912u: goto P_0c0cc912;
case 0x0c0cc914u: goto P_0c0cc914;
case 0x0c0cc916u: goto P_0c0cc916;
case 0x0c0cc918u: goto P_0c0cc918;
default: return vf3_matrix_family(target,s,ram);
}
P_0c0c9c1c: /* original 000b, guest PC 0x0c0c9c1c */
if(!s->budget--) { s->failed_pc=0x0c0c9c1cu; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c0c9c1e: /* original 0009, guest PC 0x0c0c9c1e */
if(!s->budget--) { s->failed_pc=0x0c0c9c1eu; return 0; }
return vf3_matrix_family(0x0c0c9c20u,s,ram);
P_0c0c9cc0: /* original 9031, guest PC 0x0c0c9cc0 */
if(!s->budget--) { s->failed_pc=0x0c0c9cc0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c9d26u,2);
goto P_0c0c9cc2;
P_0c0c9cc2: /* original d41c, guest PC 0x0c0c9cc2 */
if(!s->budget--) { s->failed_pc=0x0c0c9cc2u; return 0; }
r[4]=read(ram,0x0c0c9d34u,4);
goto P_0c0c9cc4;
P_0c0c9cc4: /* original 4f12, guest PC 0x0c0c9cc4 */
if(!s->budget--) { s->failed_pc=0x0c0c9cc4u; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c0c9cc6;
P_0c0c9cc6: /* original 034e, guest PC 0x0c0c9cc6 */
if(!s->budget--) { s->failed_pc=0x0c0c9cc6u; return 0; }
r[3]=read(ram,r[4]+r[0],4);
goto P_0c0c9cc8;
P_0c0c9cc8: /* original 70fc, guest PC 0x0c0c9cc8 */
if(!s->budget--) { s->failed_pc=0x0c0c9cc8u; return 0; }
r[0]+=0xfffffffcu;
goto P_0c0c9cca;
P_0c0c9cca: /* original 024e, guest PC 0x0c0c9cca */
if(!s->budget--) { s->failed_pc=0x0c0c9ccau; return 0; }
r[2]=read(ram,r[4]+r[0],4);
goto P_0c0c9ccc;
P_0c0c9ccc: /* original 7008, guest PC 0x0c0c9ccc */
if(!s->budget--) { s->failed_pc=0x0c0c9cccu; return 0; }
r[0]+=0x00000008u;
goto P_0c0c9cce;
P_0c0c9cce: /* original 014d, guest PC 0x0c0c9cce */
if(!s->budget--) { s->failed_pc=0x0c0c9cceu; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c0c9cd0;
P_0c0c9cd0: /* original 70f8, guest PC 0x0c0c9cd0 */
if(!s->budget--) { s->failed_pc=0x0c0c9cd0u; return 0; }
r[0]+=0xfffffff8u;
goto P_0c0c9cd2;
P_0c0c9cd2: /* original 0237, guest PC 0x0c0c9cd2 */
if(!s->budget--) { s->failed_pc=0x0c0c9cd2u; return 0; }
r[19]=r[2]*r[3];
goto P_0c0c9cd4;
P_0c0c9cd4: /* original 051a, guest PC 0x0c0c9cd4 */
if(!s->budget--) { s->failed_pc=0x0c0c9cd4u; return 0; }
r[5]=r[19];
goto P_0c0c9cd6;
P_0c0c9cd6: /* original 351c, guest PC 0x0c0c9cd6 */
if(!s->budget--) { s->failed_pc=0x0c0c9cd6u; return 0; }
r[5]+=r[1];
goto P_0c0c9cd8;
P_0c0c9cd8: /* original 0456, guest PC 0x0c0c9cd8 */
if(!s->budget--) { s->failed_pc=0x0c0c9cd8u; return 0; }
write(ram,r[4]+r[0],r[5],4);
goto P_0c0c9cda;
P_0c0c9cda: /* original 4529, guest PC 0x0c0c9cda */
if(!s->budget--) { s->failed_pc=0x0c0c9cdau; return 0; }
r[5]>>=16;
goto P_0c0c9cdc;
P_0c0c9cdc: /* original 9421, guest PC 0x0c0c9cdc */
if(!s->budget--) { s->failed_pc=0x0c0c9cdcu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c9d22u,2);
goto P_0c0c9cde;
P_0c0c9cde: /* original 2459, guest PC 0x0c0c9cde */
if(!s->budget--) { s->failed_pc=0x0c0c9cdeu; return 0; }
r[4]&=r[5];
goto P_0c0c9ce0;
P_0c0c9ce0: /* original 6043, guest PC 0x0c0c9ce0 */
if(!s->budget--) { s->failed_pc=0x0c0c9ce0u; return 0; }
r[0]=r[4];
goto P_0c0c9ce2;
P_0c0c9ce2: /* original 000b, guest PC 0x0c0c9ce2 */
if(!s->budget--) { s->failed_pc=0x0c0c9ce2u; return 0; }
target=r[16];
r[19]=read(ram,r[15],4); r[15]+=4;
s->pc=target; return ram->oob==0;
P_0c0c9ce4: /* original 4f16, guest PC 0x0c0c9ce4 */
if(!s->budget--) { s->failed_pc=0x0c0c9ce4u; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c0c9ce6;
P_0c0c9ce6: /* original 901d, guest PC 0x0c0c9ce6 */
if(!s->budget--) { s->failed_pc=0x0c0c9ce6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c9d24u,2);
goto P_0c0c9ce8;
P_0c0c9ce8: /* original d412, guest PC 0x0c0c9ce8 */
if(!s->budget--) { s->failed_pc=0x0c0c9ce8u; return 0; }
r[4]=read(ram,0x0c0c9d34u,4);
goto P_0c0c9cea;
P_0c0c9cea: /* original d316, guest PC 0x0c0c9cea */
if(!s->budget--) { s->failed_pc=0x0c0c9ceau; return 0; }
r[3]=read(ram,0x0c0c9d44u,4);
goto P_0c0c9cec;
P_0c0c9cec: /* original 054e, guest PC 0x0c0c9cec */
if(!s->budget--) { s->failed_pc=0x0c0c9cecu; return 0; }
r[5]=read(ram,r[4]+r[0],4);
goto P_0c0c9cee;
P_0c0c9cee: /* original 4f12, guest PC 0x0c0c9cee */
if(!s->budget--) { s->failed_pc=0x0c0c9ceeu; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c0c9cf0;
P_0c0c9cf0: /* original 0537, guest PC 0x0c0c9cf0 */
if(!s->budget--) { s->failed_pc=0x0c0c9cf0u; return 0; }
r[19]=r[5]*r[3];
goto P_0c0c9cf2;
P_0c0c9cf2: /* original 051a, guest PC 0x0c0c9cf2 */
if(!s->budget--) { s->failed_pc=0x0c0c9cf2u; return 0; }
r[5]=r[19];
goto P_0c0c9cf4;
P_0c0c9cf4: /* original 7501, guest PC 0x0c0c9cf4 */
if(!s->budget--) { s->failed_pc=0x0c0c9cf4u; return 0; }
r[5]+=0x00000001u;
goto P_0c0c9cf6;
P_0c0c9cf6: /* original 0456, guest PC 0x0c0c9cf6 */
if(!s->budget--) { s->failed_pc=0x0c0c9cf6u; return 0; }
write(ram,r[4]+r[0],r[5],4);
goto P_0c0c9cf8;
P_0c0c9cf8: /* original 4529, guest PC 0x0c0c9cf8 */
if(!s->budget--) { s->failed_pc=0x0c0c9cf8u; return 0; }
r[5]>>=16;
goto P_0c0c9cfa;
P_0c0c9cfa: /* original 9412, guest PC 0x0c0c9cfa */
if(!s->budget--) { s->failed_pc=0x0c0c9cfau; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c9d22u,2);
goto P_0c0c9cfc;
P_0c0c9cfc: /* original 2459, guest PC 0x0c0c9cfc */
if(!s->budget--) { s->failed_pc=0x0c0c9cfcu; return 0; }
r[4]&=r[5];
goto P_0c0c9cfe;
P_0c0c9cfe: /* original 6043, guest PC 0x0c0c9cfe */
if(!s->budget--) { s->failed_pc=0x0c0c9cfeu; return 0; }
r[0]=r[4];
goto P_0c0c9d00;
P_0c0c9d00: /* original 000b, guest PC 0x0c0c9d00 */
if(!s->budget--) { s->failed_pc=0x0c0c9d00u; return 0; }
target=r[16];
r[19]=read(ram,r[15],4); r[15]+=4;
s->pc=target; return ram->oob==0;
P_0c0c9d02: /* original 4f16, guest PC 0x0c0c9d02 */
if(!s->budget--) { s->failed_pc=0x0c0c9d02u; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
return vf3_matrix_family(0x0c0c9d04u,s,ram);
P_0c0c9dc8: /* original 4f22, guest PC 0x0c0c9dc8 */
if(!s->budget--) { s->failed_pc=0x0c0c9dc8u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0c9dca;
P_0c0c9dca: /* original d32a, guest PC 0x0c0c9dca */
if(!s->budget--) { s->failed_pc=0x0c0c9dcau; return 0; }
r[3]=read(ram,0x0c0c9e74u,4);
goto P_0c0c9dcc;
P_0c0c9dcc: /* original 7ff4, guest PC 0x0c0c9dcc */
if(!s->budget--) { s->failed_pc=0x0c0c9dccu; return 0; }
r[15]+=0xfffffff4u;
goto P_0c0c9dce;
P_0c0c9dce: /* original 2f32, guest PC 0x0c0c9dce */
if(!s->budget--) { s->failed_pc=0x0c0c9dceu; return 0; }
write(ram,r[15],r[3],4);
goto P_0c0c9dd0;
P_0c0c9dd0: /* original 8f02, guest PC 0x0c0c9dd0 */
if(!s->budget--) { s->failed_pc=0x0c0c9dd0u; return 0; }
cond=r[17]&1u;
r[13]=0x00000001u;
if(!cond) { goto P_0c0c9dd8; }
goto P_0c0c9dd4;
P_0c0c9dd2: /* original ed01, guest PC 0x0c0c9dd2 */
if(!s->budget--) { s->failed_pc=0x0c0c9dd2u; return 0; }
r[13]=0x00000001u;
goto P_0c0c9dd4;
P_0c0c9dd4: /* original a001, guest PC 0x0c0c9dd4 */
if(!s->budget--) { s->failed_pc=0x0c0c9dd4u; return 0; }
r[5]=r[12];
goto P_0c0c9dda;
P_0c0c9dd6: /* original 65c3, guest PC 0x0c0c9dd6 */
if(!s->budget--) { s->failed_pc=0x0c0c9dd6u; return 0; }
r[5]=r[12];
goto P_0c0c9dd8;
P_0c0c9dd8: /* original 65d3, guest PC 0x0c0c9dd8 */
if(!s->budget--) { s->failed_pc=0x0c0c9dd8u; return 0; }
r[5]=r[13];
goto P_0c0c9dda;
P_0c0c9dda: /* original d027, guest PC 0x0c0c9dda */
if(!s->budget--) { s->failed_pc=0x0c0c9ddau; return 0; }
r[0]=read(ram,0x0c0c9e78u,4);
goto P_0c0c9ddc;
P_0c0c9ddc: /* original 6943, guest PC 0x0c0c9ddc */
if(!s->budget--) { s->failed_pc=0x0c0c9ddcu; return 0; }
r[9]=r[4];
goto P_0c0c9dde;
P_0c0c9dde: /* original 4908, guest PC 0x0c0c9dde */
if(!s->budget--) { s->failed_pc=0x0c0c9ddeu; return 0; }
r[9]<<=2;
goto P_0c0c9de0;
P_0c0c9de0: /* original da26, guest PC 0x0c0c9de0 */
if(!s->budget--) { s->failed_pc=0x0c0c9de0u; return 0; }
r[10]=read(ram,0x0c0c9e7cu,4);
goto P_0c0c9de2;
P_0c0c9de2: /* original 099e, guest PC 0x0c0c9de2 */
if(!s->budget--) { s->failed_pc=0x0c0c9de2u; return 0; }
r[9]=read(ram,r[9]+r[0],4);
goto P_0c0c9de4;
P_0c0c9de4: /* original e061, guest PC 0x0c0c9de4 */
if(!s->budget--) { s->failed_pc=0x0c0c9de4u; return 0; }
r[0]=0x00000061u;
goto P_0c0c9de6;
P_0c0c9de6: /* original 0ebc, guest PC 0x0c0c9de6 */
if(!s->budget--) { s->failed_pc=0x0c0c9de6u; return 0; }
r[14]=(uint32_t)(int32_t)(int8_t)read(ram,r[11]+r[0],1);
goto P_0c0c9de8;
P_0c0c9de8: /* original 6eec, guest PC 0x0c0c9de8 */
if(!s->budget--) { s->failed_pc=0x0c0c9de8u; return 0; }
r[14]=r[14]&255u;
goto P_0c0c9dea;
P_0c0c9dea: /* original 60e3, guest PC 0x0c0c9dea */
if(!s->budget--) { s->failed_pc=0x0c0c9deau; return 0; }
r[0]=r[14];
goto P_0c0c9dec;
P_0c0c9dec: /* original 8809, guest PC 0x0c0c9dec */
if(!s->budget--) { s->failed_pc=0x0c0c9decu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000009u)!=0);
goto P_0c0c9dee;
P_0c0c9dee: /* original 8971, guest PC 0x0c0c9dee */
if(!s->budget--) { s->failed_pc=0x0c0c9deeu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c9ed4; }
goto P_0c0c9df0;
P_0c0c9df0: /* original 2558, guest PC 0x0c0c9df0 */
if(!s->budget--) { s->failed_pc=0x0c0c9df0u; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[5])==0)!=0);
goto P_0c0c9df2;
P_0c0c9df2: /* original 8b69, guest PC 0x0c0c9df2 */
if(!s->budget--) { s->failed_pc=0x0c0c9df2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c9ec8; }
goto P_0c0c9df4;
P_0c0c9df4: /* original 60e3, guest PC 0x0c0c9df4 */
if(!s->budget--) { s->failed_pc=0x0c0c9df4u; return 0; }
r[0]=r[14];
goto P_0c0c9df6;
P_0c0c9df6: /* original 8806, guest PC 0x0c0c9df6 */
if(!s->budget--) { s->failed_pc=0x0c0c9df6u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000006u)!=0);
goto P_0c0c9df8;
P_0c0c9df8: /* original 8b01, guest PC 0x0c0c9df8 */
if(!s->budget--) { s->failed_pc=0x0c0c9df8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c9dfe; }
goto P_0c0c9dfa;
P_0c0c9dfa: /* original a001, guest PC 0x0c0c9dfa */
if(!s->budget--) { s->failed_pc=0x0c0c9dfau; return 0; }
write(ram,r[15]+4,r[12],4);
goto P_0c0c9e00;
P_0c0c9dfc: /* original 1fc1, guest PC 0x0c0c9dfc */
if(!s->budget--) { s->failed_pc=0x0c0c9dfcu; return 0; }
write(ram,r[15]+4,r[12],4);
goto P_0c0c9dfe;
P_0c0c9dfe: /* original 1fd1, guest PC 0x0c0c9dfe */
if(!s->budget--) { s->failed_pc=0x0c0c9dfeu; return 0; }
write(ram,r[15]+4,r[13],4);
goto P_0c0c9e00;
P_0c0c9e00: /* original 60e3, guest PC 0x0c0c9e00 */
if(!s->budget--) { s->failed_pc=0x0c0c9e00u; return 0; }
r[0]=r[14];
goto P_0c0c9e02;
P_0c0c9e02: /* original 880a, guest PC 0x0c0c9e02 */
if(!s->budget--) { s->failed_pc=0x0c0c9e02u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000au)!=0);
goto P_0c0c9e04;
P_0c0c9e04: /* original 8f02, guest PC 0x0c0c9e04 */
if(!s->budget--) { s->failed_pc=0x0c0c9e04u; return 0; }
cond=r[17]&1u;
r[0]=r[14];
if(!cond) { goto P_0c0c9e0c; }
goto P_0c0c9e08;
P_0c0c9e06: /* original 60e3, guest PC 0x0c0c9e06 */
if(!s->budget--) { s->failed_pc=0x0c0c9e06u; return 0; }
r[0]=r[14];
goto P_0c0c9e08;
P_0c0c9e08: /* original a001, guest PC 0x0c0c9e08 */
if(!s->budget--) { s->failed_pc=0x0c0c9e08u; return 0; }
r[4]=r[12];
goto P_0c0c9e0e;
P_0c0c9e0a: /* original 64c3, guest PC 0x0c0c9e0a */
if(!s->budget--) { s->failed_pc=0x0c0c9e0au; return 0; }
r[4]=r[12];
goto P_0c0c9e0c;
P_0c0c9e0c: /* original 64d3, guest PC 0x0c0c9e0c */
if(!s->budget--) { s->failed_pc=0x0c0c9e0cu; return 0; }
r[4]=r[13];
goto P_0c0c9e0e;
P_0c0c9e0e: /* original 8808, guest PC 0x0c0c9e0e */
if(!s->budget--) { s->failed_pc=0x0c0c9e0eu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000008u)!=0);
goto P_0c0c9e10;
P_0c0c9e10: /* original 8b01, guest PC 0x0c0c9e10 */
if(!s->budget--) { s->failed_pc=0x0c0c9e10u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c9e16; }
goto P_0c0c9e12;
P_0c0c9e12: /* original a001, guest PC 0x0c0c9e12 */
if(!s->budget--) { s->failed_pc=0x0c0c9e12u; return 0; }
write(ram,r[15]+8,r[12],4);
goto P_0c0c9e18;
P_0c0c9e14: /* original 1fc2, guest PC 0x0c0c9e14 */
if(!s->budget--) { s->failed_pc=0x0c0c9e14u; return 0; }
write(ram,r[15]+8,r[12],4);
goto P_0c0c9e16;
P_0c0c9e16: /* original 1fd2, guest PC 0x0c0c9e16 */
if(!s->budget--) { s->failed_pc=0x0c0c9e16u; return 0; }
write(ram,r[15]+8,r[13],4);
goto P_0c0c9e18;
P_0c0c9e18: /* original 60e3, guest PC 0x0c0c9e18 */
if(!s->budget--) { s->failed_pc=0x0c0c9e18u; return 0; }
r[0]=r[14];
goto P_0c0c9e1a;
P_0c0c9e1a: /* original 880b, guest PC 0x0c0c9e1a */
if(!s->budget--) { s->failed_pc=0x0c0c9e1au; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000bu)!=0);
goto P_0c0c9e1c;
P_0c0c9e1c: /* original 8f02, guest PC 0x0c0c9e1c */
if(!s->budget--) { s->failed_pc=0x0c0c9e1cu; return 0; }
cond=r[17]&1u;
r[0]=r[14];
if(!cond) { goto P_0c0c9e24; }
goto P_0c0c9e20;
P_0c0c9e1e: /* original 60e3, guest PC 0x0c0c9e1e */
if(!s->budget--) { s->failed_pc=0x0c0c9e1eu; return 0; }
r[0]=r[14];
goto P_0c0c9e20;
P_0c0c9e20: /* original a001, guest PC 0x0c0c9e20 */
if(!s->budget--) { s->failed_pc=0x0c0c9e20u; return 0; }
r[7]=r[12];
goto P_0c0c9e26;
P_0c0c9e22: /* original 67c3, guest PC 0x0c0c9e22 */
if(!s->budget--) { s->failed_pc=0x0c0c9e22u; return 0; }
r[7]=r[12];
goto P_0c0c9e24;
P_0c0c9e24: /* original 67d3, guest PC 0x0c0c9e24 */
if(!s->budget--) { s->failed_pc=0x0c0c9e24u; return 0; }
r[7]=r[13];
goto P_0c0c9e26;
P_0c0c9e26: /* original 880c, guest PC 0x0c0c9e26 */
if(!s->budget--) { s->failed_pc=0x0c0c9e26u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000cu)!=0);
goto P_0c0c9e28;
P_0c0c9e28: /* original 8f02, guest PC 0x0c0c9e28 */
if(!s->budget--) { s->failed_pc=0x0c0c9e28u; return 0; }
cond=r[17]&1u;
r[0]=r[14];
if(!cond) { goto P_0c0c9e30; }
goto P_0c0c9e2c;
P_0c0c9e2a: /* original 60e3, guest PC 0x0c0c9e2a */
if(!s->budget--) { s->failed_pc=0x0c0c9e2au; return 0; }
r[0]=r[14];
goto P_0c0c9e2c;
P_0c0c9e2c: /* original a001, guest PC 0x0c0c9e2c */
if(!s->budget--) { s->failed_pc=0x0c0c9e2cu; return 0; }
r[1]=r[12];
goto P_0c0c9e32;
P_0c0c9e2e: /* original 61c3, guest PC 0x0c0c9e2e */
if(!s->budget--) { s->failed_pc=0x0c0c9e2eu; return 0; }
r[1]=r[12];
goto P_0c0c9e30;
P_0c0c9e30: /* original 61d3, guest PC 0x0c0c9e30 */
if(!s->budget--) { s->failed_pc=0x0c0c9e30u; return 0; }
r[1]=r[13];
goto P_0c0c9e32;
P_0c0c9e32: /* original 8807, guest PC 0x0c0c9e32 */
if(!s->budget--) { s->failed_pc=0x0c0c9e32u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000007u)!=0);
goto P_0c0c9e34;
P_0c0c9e34: /* original 8f02, guest PC 0x0c0c9e34 */
if(!s->budget--) { s->failed_pc=0x0c0c9e34u; return 0; }
cond=r[17]&1u;
r[0]=r[14];
if(!cond) { goto P_0c0c9e3c; }
goto P_0c0c9e38;
P_0c0c9e36: /* original 60e3, guest PC 0x0c0c9e36 */
if(!s->budget--) { s->failed_pc=0x0c0c9e36u; return 0; }
r[0]=r[14];
goto P_0c0c9e38;
P_0c0c9e38: /* original a001, guest PC 0x0c0c9e38 */
if(!s->budget--) { s->failed_pc=0x0c0c9e38u; return 0; }
r[5]=r[12];
goto P_0c0c9e3e;
P_0c0c9e3a: /* original 65c3, guest PC 0x0c0c9e3a */
if(!s->budget--) { s->failed_pc=0x0c0c9e3au; return 0; }
r[5]=r[12];
goto P_0c0c9e3c;
P_0c0c9e3c: /* original 65d3, guest PC 0x0c0c9e3c */
if(!s->budget--) { s->failed_pc=0x0c0c9e3cu; return 0; }
r[5]=r[13];
goto P_0c0c9e3e;
P_0c0c9e3e: /* original 8805, guest PC 0x0c0c9e3e */
if(!s->budget--) { s->failed_pc=0x0c0c9e3eu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000005u)!=0);
goto P_0c0c9e40;
P_0c0c9e40: /* original 8b01, guest PC 0x0c0c9e40 */
if(!s->budget--) { s->failed_pc=0x0c0c9e40u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c9e46; }
goto P_0c0c9e42;
P_0c0c9e42: /* original a001, guest PC 0x0c0c9e42 */
if(!s->budget--) { s->failed_pc=0x0c0c9e42u; return 0; }
r[6]=r[12];
goto P_0c0c9e48;
P_0c0c9e44: /* original 66c3, guest PC 0x0c0c9e44 */
if(!s->budget--) { s->failed_pc=0x0c0c9e44u; return 0; }
r[6]=r[12];
goto P_0c0c9e46;
P_0c0c9e46: /* original 66d3, guest PC 0x0c0c9e46 */
if(!s->budget--) { s->failed_pc=0x0c0c9e46u; return 0; }
r[6]=r[13];
goto P_0c0c9e48;
P_0c0c9e48: /* original 53f1, guest PC 0x0c0c9e48 */
if(!s->budget--) { s->failed_pc=0x0c0c9e48u; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c0c9e4a;
P_0c0c9e4a: /* original 2338, guest PC 0x0c0c9e4a */
if(!s->budget--) { s->failed_pc=0x0c0c9e4au; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c0c9e4c;
P_0c0c9e4c: /* original 890e, guest PC 0x0c0c9e4c */
if(!s->budget--) { s->failed_pc=0x0c0c9e4cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c9e6c; }
goto P_0c0c9e4e;
P_0c0c9e4e: /* original 2448, guest PC 0x0c0c9e4e */
if(!s->budget--) { s->failed_pc=0x0c0c9e4eu; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c0c9e50;
P_0c0c9e50: /* original 890c, guest PC 0x0c0c9e50 */
if(!s->budget--) { s->failed_pc=0x0c0c9e50u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c9e6c; }
goto P_0c0c9e52;
P_0c0c9e52: /* original 52f2, guest PC 0x0c0c9e52 */
if(!s->budget--) { s->failed_pc=0x0c0c9e52u; return 0; }
r[2]=read(ram,r[15]+8,4);
goto P_0c0c9e54;
P_0c0c9e54: /* original 2228, guest PC 0x0c0c9e54 */
if(!s->budget--) { s->failed_pc=0x0c0c9e54u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c0c9e56;
P_0c0c9e56: /* original 8909, guest PC 0x0c0c9e56 */
if(!s->budget--) { s->failed_pc=0x0c0c9e56u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c9e6c; }
goto P_0c0c9e58;
P_0c0c9e58: /* original 2778, guest PC 0x0c0c9e58 */
if(!s->budget--) { s->failed_pc=0x0c0c9e58u; return 0; }
r[17]=(r[17]&~1u)|(((r[7]&r[7])==0)!=0);
goto P_0c0c9e5a;
P_0c0c9e5a: /* original 8907, guest PC 0x0c0c9e5a */
if(!s->budget--) { s->failed_pc=0x0c0c9e5au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c9e6c; }
goto P_0c0c9e5c;
P_0c0c9e5c: /* original 2118, guest PC 0x0c0c9e5c */
if(!s->budget--) { s->failed_pc=0x0c0c9e5cu; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[1])==0)!=0);
goto P_0c0c9e5e;
P_0c0c9e5e: /* original 890f, guest PC 0x0c0c9e5e */
if(!s->budget--) { s->failed_pc=0x0c0c9e5eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c9e80; }
goto P_0c0c9e60;
P_0c0c9e60: /* original 2558, guest PC 0x0c0c9e60 */
if(!s->budget--) { s->failed_pc=0x0c0c9e60u; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[5])==0)!=0);
goto P_0c0c9e62;
P_0c0c9e62: /* original 890d, guest PC 0x0c0c9e62 */
if(!s->budget--) { s->failed_pc=0x0c0c9e62u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c9e80; }
goto P_0c0c9e64;
P_0c0c9e64: /* original 2668, guest PC 0x0c0c9e64 */
if(!s->budget--) { s->failed_pc=0x0c0c9e64u; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[6])==0)!=0);
goto P_0c0c9e66;
P_0c0c9e66: /* original 890b, guest PC 0x0c0c9e66 */
if(!s->budget--) { s->failed_pc=0x0c0c9e66u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c9e80; }
goto P_0c0c9e68;
P_0c0c9e68: /* original a00f, guest PC 0x0c0c9e68 */
if(!s->budget--) { s->failed_pc=0x0c0c9e68u; return 0; }
goto P_0c0c9e8a;
P_0c0c9e6a: /* original 0009, guest PC 0x0c0c9e6a */
if(!s->budget--) { s->failed_pc=0x0c0c9e6au; return 0; }
goto P_0c0c9e6c;
P_0c0c9e6c: /* original a009, guest PC 0x0c0c9e6c */
if(!s->budget--) { s->failed_pc=0x0c0c9e6cu; return 0; }
r[14]=0x00000070u;
goto P_0c0c9e82;
P_0c0c9e6e: /* original ee70, guest PC 0x0c0c9e6e */
if(!s->budget--) { s->failed_pc=0x0c0c9e6eu; return 0; }
r[14]=0x00000070u;
return vf3_matrix_family(0x0c0c9e70u,s,ram);
P_0c0c9e80: /* original ee71, guest PC 0x0c0c9e80 */
if(!s->budget--) { s->failed_pc=0x0c0c9e80u; return 0; }
r[14]=0x00000071u;
goto P_0c0c9e82;
P_0c0c9e82: /* original b03c, guest PC 0x0c0c9e82 */
if(!s->budget--) { s->failed_pc=0x0c0c9e82u; return 0; }
target=0x0c0c9efeu; r[16]=0x0c0c9e86u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c9e86u) { target=s->pc; goto dispatch; }
goto P_0c0c9e86;
P_0c0c9e84: /* original 64e3, guest PC 0x0c0c9e84 */
if(!s->budget--) { s->failed_pc=0x0c0c9e84u; return 0; }
r[4]=r[14];
goto P_0c0c9e86;
P_0c0c9e86: /* original 4a0b, guest PC 0x0c0c9e86 */
if(!s->budget--) { s->failed_pc=0x0c0c9e86u; return 0; }
target=r[10];
r[16]=0x0c0c9e8au;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c9e8au) { target=s->pc; goto dispatch; }
goto P_0c0c9e8a;
P_0c0c9e88: /* original 64e3, guest PC 0x0c0c9e88 */
if(!s->budget--) { s->failed_pc=0x0c0c9e88u; return 0; }
r[4]=r[14];
goto P_0c0c9e8a;
P_0c0c9e8a: /* original 60f2, guest PC 0x0c0c9e8a */
if(!s->budget--) { s->failed_pc=0x0c0c9e8au; return 0; }
tmp=read(ram,r[15],4);
r[0]=tmp;
goto P_0c0c9e8c;
P_0c0c9e8c: /* original e11c, guest PC 0x0c0c9e8c */
if(!s->budget--) { s->failed_pc=0x0c0c9e8cu; return 0; }
r[1]=0x0000001cu;
goto P_0c0c9e8e;
P_0c0c9e8e: /* original e40f, guest PC 0x0c0c9e8e */
if(!s->budget--) { s->failed_pc=0x0c0c9e8eu; return 0; }
r[4]=0x0000000fu;
goto P_0c0c9e90;
P_0c0c9e90: /* original 001c, guest PC 0x0c0c9e90 */
if(!s->budget--) { s->failed_pc=0x0c0c9e90u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[1]+r[0],1);
goto P_0c0c9e92;
P_0c0c9e92: /* original 600c, guest PC 0x0c0c9e92 */
if(!s->budget--) { s->failed_pc=0x0c0c9e92u; return 0; }
r[0]=r[0]&255u;
goto P_0c0c9e94;
P_0c0c9e94: /* original 2409, guest PC 0x0c0c9e94 */
if(!s->budget--) { s->failed_pc=0x0c0c9e94u; return 0; }
r[4]&=r[0];
goto P_0c0c9e96;
P_0c0c9e96: /* original 6043, guest PC 0x0c0c9e96 */
if(!s->budget--) { s->failed_pc=0x0c0c9e96u; return 0; }
r[0]=r[4];
goto P_0c0c9e98;
P_0c0c9e98: /* original 8809, guest PC 0x0c0c9e98 */
if(!s->budget--) { s->failed_pc=0x0c0c9e98u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000009u)!=0);
goto P_0c0c9e9a;
P_0c0c9e9a: /* original 8b15, guest PC 0x0c0c9e9a */
if(!s->budget--) { s->failed_pc=0x0c0c9e9au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c9ec8; }
goto P_0c0c9e9c;
P_0c0c9e9c: /* original 904e, guest PC 0x0c0c9e9c */
if(!s->budget--) { s->failed_pc=0x0c0c9e9cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c9f3cu,2);
goto P_0c0c9e9e;
P_0c0c9e9e: /* original f5b6, guest PC 0x0c0c9e9e */
if(!s->budget--) { s->failed_pc=0x0c0c9e9eu; return 0; }
vf3_matrix_load(s,ram,5,r[11]+r[0]);
goto P_0c0c9ea0;
P_0c0c9ea0: /* original 7008, guest PC 0x0c0c9ea0 */
if(!s->budget--) { s->failed_pc=0x0c0c9ea0u; return 0; }
r[0]+=0x00000008u;
goto P_0c0c9ea2;
P_0c0c9ea2: /* original f4b6, guest PC 0x0c0c9ea2 */
if(!s->budget--) { s->failed_pc=0x0c0c9ea2u; return 0; }
vf3_matrix_load(s,ram,4,r[11]+r[0]);
goto P_0c0c9ea4;
P_0c0c9ea4: /* original c726, guest PC 0x0c0c9ea4 */
if(!s->budget--) { s->failed_pc=0x0c0c9ea4u; return 0; }
r[0]=0x0c0c9f40u;
goto P_0c0c9ea6;
P_0c0c9ea6: /* original f608, guest PC 0x0c0c9ea6 */
if(!s->budget--) { s->failed_pc=0x0c0c9ea6u; return 0; }
vf3_matrix_load(s,ram,6,r[0]);
goto P_0c0c9ea8;
P_0c0c9ea8: /* original f565, guest PC 0x0c0c9ea8 */
if(!s->budget--) { s->failed_pc=0x0c0c9ea8u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[5])>as_float(fr[6]))!=0);
goto P_0c0c9eaa;
P_0c0c9eaa: /* original 890d, guest PC 0x0c0c9eaa */
if(!s->budget--) { s->failed_pc=0x0c0c9eaau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c9ec8; }
goto P_0c0c9eac;
P_0c0c9eac: /* original c725, guest PC 0x0c0c9eac */
if(!s->budget--) { s->failed_pc=0x0c0c9eacu; return 0; }
r[0]=0x0c0c9f44u;
goto P_0c0c9eae;
P_0c0c9eae: /* original f608, guest PC 0x0c0c9eae */
if(!s->budget--) { s->failed_pc=0x0c0c9eaeu; return 0; }
vf3_matrix_load(s,ram,6,r[0]);
goto P_0c0c9eb0;
P_0c0c9eb0: /* original f655, guest PC 0x0c0c9eb0 */
if(!s->budget--) { s->failed_pc=0x0c0c9eb0u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[6])>as_float(fr[5]))!=0);
goto P_0c0c9eb2;
P_0c0c9eb2: /* original 8909, guest PC 0x0c0c9eb2 */
if(!s->budget--) { s->failed_pc=0x0c0c9eb2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c9ec8; }
goto P_0c0c9eb4;
P_0c0c9eb4: /* original c724, guest PC 0x0c0c9eb4 */
if(!s->budget--) { s->failed_pc=0x0c0c9eb4u; return 0; }
r[0]=0x0c0c9f48u;
goto P_0c0c9eb6;
P_0c0c9eb6: /* original f508, guest PC 0x0c0c9eb6 */
if(!s->budget--) { s->failed_pc=0x0c0c9eb6u; return 0; }
vf3_matrix_load(s,ram,5,r[0]);
goto P_0c0c9eb8;
P_0c0c9eb8: /* original f455, guest PC 0x0c0c9eb8 */
if(!s->budget--) { s->failed_pc=0x0c0c9eb8u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[4])>as_float(fr[5]))!=0);
goto P_0c0c9eba;
P_0c0c9eba: /* original 8905, guest PC 0x0c0c9eba */
if(!s->budget--) { s->failed_pc=0x0c0c9ebau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c9ec8; }
goto P_0c0c9ebc;
P_0c0c9ebc: /* original c723, guest PC 0x0c0c9ebc */
if(!s->budget--) { s->failed_pc=0x0c0c9ebcu; return 0; }
r[0]=0x0c0c9f4cu;
goto P_0c0c9ebe;
P_0c0c9ebe: /* original f508, guest PC 0x0c0c9ebe */
if(!s->budget--) { s->failed_pc=0x0c0c9ebeu; return 0; }
vf3_matrix_load(s,ram,5,r[0]);
goto P_0c0c9ec0;
P_0c0c9ec0: /* original f545, guest PC 0x0c0c9ec0 */
if(!s->budget--) { s->failed_pc=0x0c0c9ec0u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[5])>as_float(fr[4]))!=0);
goto P_0c0c9ec2;
P_0c0c9ec2: /* original 8901, guest PC 0x0c0c9ec2 */
if(!s->budget--) { s->failed_pc=0x0c0c9ec2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c9ec8; }
goto P_0c0c9ec4;
P_0c0c9ec4: /* original a00b, guest PC 0x0c0c9ec4 */
if(!s->budget--) { s->failed_pc=0x0c0c9ec4u; return 0; }
r[14]=r[13];
goto P_0c0c9ede;
P_0c0c9ec6: /* original 6ed3, guest PC 0x0c0c9ec6 */
if(!s->budget--) { s->failed_pc=0x0c0c9ec6u; return 0; }
r[14]=r[13];
goto P_0c0c9ec8;
P_0c0c9ec8: /* original 9039, guest PC 0x0c0c9ec8 */
if(!s->budget--) { s->failed_pc=0x0c0c9ec8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c9f3eu,2);
goto P_0c0c9eca;
P_0c0c9eca: /* original 0ebe, guest PC 0x0c0c9eca */
if(!s->budget--) { s->failed_pc=0x0c0c9ecau; return 0; }
r[14]=read(ram,r[11]+r[0],4);
goto P_0c0c9ecc;
P_0c0c9ecc: /* original 2ee8, guest PC 0x0c0c9ecc */
if(!s->budget--) { s->failed_pc=0x0c0c9eccu; return 0; }
r[17]=(r[17]&~1u)|(((r[14]&r[14])==0)!=0);
goto P_0c0c9ece;
P_0c0c9ece: /* original 8906, guest PC 0x0c0c9ece */
if(!s->budget--) { s->failed_pc=0x0c0c9eceu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c9ede; }
goto P_0c0c9ed0;
P_0c0c9ed0: /* original a005, guest PC 0x0c0c9ed0 */
if(!s->budget--) { s->failed_pc=0x0c0c9ed0u; return 0; }
r[14]=r[12];
goto P_0c0c9ede;
P_0c0c9ed2: /* original 6ec3, guest PC 0x0c0c9ed2 */
if(!s->budget--) { s->failed_pc=0x0c0c9ed2u; return 0; }
r[14]=r[12];
goto P_0c0c9ed4;
P_0c0c9ed4: /* original 5d92, guest PC 0x0c0c9ed4 */
if(!s->budget--) { s->failed_pc=0x0c0c9ed4u; return 0; }
r[13]=read(ram,r[9]+8,4);
goto P_0c0c9ed6;
P_0c0c9ed6: /* original b012, guest PC 0x0c0c9ed6 */
if(!s->budget--) { s->failed_pc=0x0c0c9ed6u; return 0; }
target=0x0c0c9efeu; r[16]=0x0c0c9edau;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c9edau) { target=s->pc; goto dispatch; }
goto P_0c0c9eda;
P_0c0c9ed8: /* original 64d3, guest PC 0x0c0c9ed8 */
if(!s->budget--) { s->failed_pc=0x0c0c9ed8u; return 0; }
r[4]=r[13];
goto P_0c0c9eda;
P_0c0c9eda: /* original 4a0b, guest PC 0x0c0c9eda */
if(!s->budget--) { s->failed_pc=0x0c0c9edau; return 0; }
target=r[10];
r[16]=0x0c0c9edeu;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c9edeu) { target=s->pc; goto dispatch; }
goto P_0c0c9ede;
P_0c0c9edc: /* original 64d3, guest PC 0x0c0c9edc */
if(!s->budget--) { s->failed_pc=0x0c0c9edcu; return 0; }
r[4]=r[13];
goto P_0c0c9ede;
P_0c0c9ede: /* original 60e3, guest PC 0x0c0c9ede */
if(!s->budget--) { s->failed_pc=0x0c0c9edeu; return 0; }
r[0]=r[14];
goto P_0c0c9ee0;
P_0c0c9ee0: /* original 4008, guest PC 0x0c0c9ee0 */
if(!s->budget--) { s->failed_pc=0x0c0c9ee0u; return 0; }
r[0]<<=2;
goto P_0c0c9ee2;
P_0c0c9ee2: /* original 0e9e, guest PC 0x0c0c9ee2 */
if(!s->budget--) { s->failed_pc=0x0c0c9ee2u; return 0; }
r[14]=read(ram,r[9]+r[0],4);
goto P_0c0c9ee4;
P_0c0c9ee4: /* original b00b, guest PC 0x0c0c9ee4 */
if(!s->budget--) { s->failed_pc=0x0c0c9ee4u; return 0; }
target=0x0c0c9efeu; r[16]=0x0c0c9ee8u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c9ee8u) { target=s->pc; goto dispatch; }
goto P_0c0c9ee8;
P_0c0c9ee6: /* original 64e3, guest PC 0x0c0c9ee6 */
if(!s->budget--) { s->failed_pc=0x0c0c9ee6u; return 0; }
r[4]=r[14];
goto P_0c0c9ee8;
P_0c0c9ee8: /* original 4a0b, guest PC 0x0c0c9ee8 */
if(!s->budget--) { s->failed_pc=0x0c0c9ee8u; return 0; }
target=r[10];
r[16]=0x0c0c9eecu;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c9eecu) { target=s->pc; goto dispatch; }
goto P_0c0c9eec;
P_0c0c9eea: /* original 64e3, guest PC 0x0c0c9eea */
if(!s->budget--) { s->failed_pc=0x0c0c9eeau; return 0; }
r[4]=r[14];
goto P_0c0c9eec;
P_0c0c9eec: /* original 7f0c, guest PC 0x0c0c9eec */
if(!s->budget--) { s->failed_pc=0x0c0c9eecu; return 0; }
r[15]+=0x0000000cu;
goto P_0c0c9eee;
P_0c0c9eee: /* original 4f26, guest PC 0x0c0c9eee */
if(!s->budget--) { s->failed_pc=0x0c0c9eeeu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0c9ef0;
P_0c0c9ef0: /* original 69f6, guest PC 0x0c0c9ef0 */
if(!s->budget--) { s->failed_pc=0x0c0c9ef0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c0c9ef2;
P_0c0c9ef2: /* original 6af6, guest PC 0x0c0c9ef2 */
if(!s->budget--) { s->failed_pc=0x0c0c9ef2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0c9ef4;
P_0c0c9ef4: /* original 6bf6, guest PC 0x0c0c9ef4 */
if(!s->budget--) { s->failed_pc=0x0c0c9ef4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0c9ef6;
P_0c0c9ef6: /* original 6cf6, guest PC 0x0c0c9ef6 */
if(!s->budget--) { s->failed_pc=0x0c0c9ef6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0c9ef8;
P_0c0c9ef8: /* original 6df6, guest PC 0x0c0c9ef8 */
if(!s->budget--) { s->failed_pc=0x0c0c9ef8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0c9efa;
P_0c0c9efa: /* original 000b, guest PC 0x0c0c9efa */
if(!s->budget--) { s->failed_pc=0x0c0c9efau; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0c9efc: /* original 6ef6, guest PC 0x0c0c9efc */
if(!s->budget--) { s->failed_pc=0x0c0c9efcu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0c9efe;
P_0c0c9efe: /* original d514, guest PC 0x0c0c9efe */
if(!s->budget--) { s->failed_pc=0x0c0c9efeu; return 0; }
r[5]=read(ram,0x0c0c9f50u,4);
goto P_0c0c9f00;
P_0c0c9f00: /* original e01d, guest PC 0x0c0c9f00 */
if(!s->budget--) { s->failed_pc=0x0c0c9f00u; return 0; }
r[0]=0x0000001du;
goto P_0c0c9f02;
P_0c0c9f02: /* original e304, guest PC 0x0c0c9f02 */
if(!s->budget--) { s->failed_pc=0x0c0c9f02u; return 0; }
r[3]=0x00000004u;
goto P_0c0c9f04;
P_0c0c9f04: /* original 065c, guest PC 0x0c0c9f04 */
if(!s->budget--) { s->failed_pc=0x0c0c9f04u; return 0; }
r[6]=(uint32_t)(int32_t)(int8_t)read(ram,r[5]+r[0],1);
goto P_0c0c9f06;
P_0c0c9f06: /* original 666c, guest PC 0x0c0c9f06 */
if(!s->budget--) { s->failed_pc=0x0c0c9f06u; return 0; }
r[6]=r[6]&255u;
goto P_0c0c9f08;
P_0c0c9f08: /* original 3633, guest PC 0x0c0c9f08 */
if(!s->budget--) { s->failed_pc=0x0c0c9f08u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[6]>=(int32_t)r[3])!=0);
goto P_0c0c9f0a;
P_0c0c9f0a: /* original 8915, guest PC 0x0c0c9f0a */
if(!s->budget--) { s->failed_pc=0x0c0c9f0au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c9f38; }
goto P_0c0c9f0c;
P_0c0c9f0c: /* original 7601, guest PC 0x0c0c9f0c */
if(!s->budget--) { s->failed_pc=0x0c0c9f0cu; return 0; }
r[6]+=0x00000001u;
goto P_0c0c9f0e;
P_0c0c9f0e: /* original 6763, guest PC 0x0c0c9f0e */
if(!s->budget--) { s->failed_pc=0x0c0c9f0eu; return 0; }
r[7]=r[6];
goto P_0c0c9f10;
P_0c0c9f10: /* original 6353, guest PC 0x0c0c9f10 */
if(!s->budget--) { s->failed_pc=0x0c0c9f10u; return 0; }
r[3]=r[5];
goto P_0c0c9f12;
P_0c0c9f12: /* original 77ff, guest PC 0x0c0c9f12 */
if(!s->budget--) { s->failed_pc=0x0c0c9f12u; return 0; }
r[7]+=0xffffffffu;
goto P_0c0c9f14;
P_0c0c9f14: /* original 7330, guest PC 0x0c0c9f14 */
if(!s->budget--) { s->failed_pc=0x0c0c9f14u; return 0; }
r[3]+=0x00000030u;
goto P_0c0c9f16;
P_0c0c9f16: /* original 4708, guest PC 0x0c0c9f16 */
if(!s->budget--) { s->failed_pc=0x0c0c9f16u; return 0; }
r[7]<<=2;
goto P_0c0c9f18;
P_0c0c9f18: /* original 373c, guest PC 0x0c0c9f18 */
if(!s->budget--) { s->failed_pc=0x0c0c9f18u; return 0; }
r[7]+=r[3];
goto P_0c0c9f1a;
P_0c0c9f1a: /* original 6772, guest PC 0x0c0c9f1a */
if(!s->budget--) { s->failed_pc=0x0c0c9f1au; return 0; }
tmp=read(ram,r[7],4);
r[7]=tmp;
goto P_0c0c9f1c;
P_0c0c9f1c: /* original 3470, guest PC 0x0c0c9f1c */
if(!s->budget--) { s->failed_pc=0x0c0c9f1cu; return 0; }
r[17]=(r[17]&~1u)|((r[4]==r[7])!=0);
goto P_0c0c9f1e;
P_0c0c9f1e: /* original 890b, guest PC 0x0c0c9f1e */
if(!s->budget--) { s->failed_pc=0x0c0c9f1eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c9f38; }
goto P_0c0c9f20;
P_0c0c9f20: /* original 4610, guest PC 0x0c0c9f20 */
if(!s->budget--) { s->failed_pc=0x0c0c9f20u; return 0; }
--r[6];
r[17]=(r[17]&~1u)|((r[6]==0)!=0);
goto P_0c0c9f22;
P_0c0c9f22: /* original 8bf4, guest PC 0x0c0c9f22 */
if(!s->budget--) { s->failed_pc=0x0c0c9f22u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c9f0e; }
goto P_0c0c9f24;
P_0c0c9f24: /* original 025c, guest PC 0x0c0c9f24 */
if(!s->budget--) { s->failed_pc=0x0c0c9f24u; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[5]+r[0],1);
goto P_0c0c9f26;
P_0c0c9f26: /* original 6353, guest PC 0x0c0c9f26 */
if(!s->budget--) { s->failed_pc=0x0c0c9f26u; return 0; }
r[3]=r[5];
goto P_0c0c9f28;
P_0c0c9f28: /* original 7330, guest PC 0x0c0c9f28 */
if(!s->budget--) { s->failed_pc=0x0c0c9f28u; return 0; }
r[3]+=0x00000030u;
goto P_0c0c9f2a;
P_0c0c9f2a: /* original 622c, guest PC 0x0c0c9f2a */
if(!s->budget--) { s->failed_pc=0x0c0c9f2au; return 0; }
r[2]=r[2]&255u;
goto P_0c0c9f2c;
P_0c0c9f2c: /* original 4208, guest PC 0x0c0c9f2c */
if(!s->budget--) { s->failed_pc=0x0c0c9f2cu; return 0; }
r[2]<<=2;
goto P_0c0c9f2e;
P_0c0c9f2e: /* original 323c, guest PC 0x0c0c9f2e */
if(!s->budget--) { s->failed_pc=0x0c0c9f2eu; return 0; }
r[2]+=r[3];
goto P_0c0c9f30;
P_0c0c9f30: /* original 2242, guest PC 0x0c0c9f30 */
if(!s->budget--) { s->failed_pc=0x0c0c9f30u; return 0; }
write(ram,r[2],r[4],4);
goto P_0c0c9f32;
P_0c0c9f32: /* original 025c, guest PC 0x0c0c9f32 */
if(!s->budget--) { s->failed_pc=0x0c0c9f32u; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[5]+r[0],1);
goto P_0c0c9f34;
P_0c0c9f34: /* original 7201, guest PC 0x0c0c9f34 */
if(!s->budget--) { s->failed_pc=0x0c0c9f34u; return 0; }
r[2]+=0x00000001u;
goto P_0c0c9f36;
P_0c0c9f36: /* original 0524, guest PC 0x0c0c9f36 */
if(!s->budget--) { s->failed_pc=0x0c0c9f36u; return 0; }
write(ram,r[5]+r[0],r[2],1);
goto P_0c0c9f38;
P_0c0c9f38: /* original 000b, guest PC 0x0c0c9f38 */
if(!s->budget--) { s->failed_pc=0x0c0c9f38u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c0c9f3a: /* original 0009, guest PC 0x0c0c9f3a */
if(!s->budget--) { s->failed_pc=0x0c0c9f3au; return 0; }
return vf3_matrix_family(0x0c0c9f3cu,s,ram);
P_0c0ca234: /* original d52a, guest PC 0x0c0ca234 */
if(!s->budget--) { s->failed_pc=0x0c0ca234u; return 0; }
r[5]=read(ram,0x0c0ca2e0u,4);
goto P_0c0ca236;
P_0c0ca236: /* original e01c, guest PC 0x0c0ca236 */
if(!s->budget--) { s->failed_pc=0x0c0ca236u; return 0; }
r[0]=0x0000001cu;
goto P_0c0ca238;
P_0c0ca238: /* original d42a, guest PC 0x0c0ca238 */
if(!s->budget--) { s->failed_pc=0x0c0ca238u; return 0; }
r[4]=read(ram,0x0c0ca2e4u,4);
goto P_0c0ca23a;
P_0c0ca23a: /* original e3fe, guest PC 0x0c0ca23a */
if(!s->budget--) { s->failed_pc=0x0c0ca23au; return 0; }
r[3]=0xfffffffeu;
goto P_0c0ca23c;
P_0c0ca23c: /* original 5251, guest PC 0x0c0ca23c */
if(!s->budget--) { s->failed_pc=0x0c0ca23cu; return 0; }
r[2]=read(ram,r[5]+4,4);
goto P_0c0ca23e;
P_0c0ca23e: /* original e70f, guest PC 0x0c0ca23e */
if(!s->budget--) { s->failed_pc=0x0c0ca23eu; return 0; }
r[7]=0x0000000fu;
goto P_0c0ca240;
P_0c0ca240: /* original 4f22, guest PC 0x0c0ca240 */
if(!s->budget--) { s->failed_pc=0x0c0ca240u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0ca242;
P_0c0ca242: /* original 2239, guest PC 0x0c0ca242 */
if(!s->budget--) { s->failed_pc=0x0c0ca242u; return 0; }
r[2]&=r[3];
goto P_0c0ca244;
P_0c0ca244: /* original 1521, guest PC 0x0c0ca244 */
if(!s->budget--) { s->failed_pc=0x0c0ca244u; return 0; }
write(ram,r[5]+4,r[2],4);
goto P_0c0ca246;
P_0c0ca246: /* original 004c, guest PC 0x0c0ca246 */
if(!s->budget--) { s->failed_pc=0x0c0ca246u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c0ca248;
P_0c0ca248: /* original 7ffc, guest PC 0x0c0ca248 */
if(!s->budget--) { s->failed_pc=0x0c0ca248u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c0ca24a;
P_0c0ca24a: /* original d427, guest PC 0x0c0ca24a */
if(!s->budget--) { s->failed_pc=0x0c0ca24au; return 0; }
r[4]=read(ram,0x0c0ca2e8u,4);
goto P_0c0ca24c;
P_0c0ca24c: /* original 600c, guest PC 0x0c0ca24c */
if(!s->budget--) { s->failed_pc=0x0c0ca24cu; return 0; }
r[0]=r[0]&255u;
goto P_0c0ca24e;
P_0c0ca24e: /* original 2709, guest PC 0x0c0ca24e */
if(!s->budget--) { s->failed_pc=0x0c0ca24eu; return 0; }
r[7]&=r[0];
goto P_0c0ca250;
P_0c0ca250: /* original 5341, guest PC 0x0c0ca250 */
if(!s->budget--) { s->failed_pc=0x0c0ca250u; return 0; }
r[3]=read(ram,r[4]+4,4);
goto P_0c0ca252;
P_0c0ca252: /* original 6642, guest PC 0x0c0ca252 */
if(!s->budget--) { s->failed_pc=0x0c0ca252u; return 0; }
tmp=read(ram,r[4],4);
r[6]=tmp;
goto P_0c0ca254;
P_0c0ca254: /* original 2f32, guest PC 0x0c0ca254 */
if(!s->budget--) { s->failed_pc=0x0c0ca254u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c0ca256;
P_0c0ca256: /* original 3760, guest PC 0x0c0ca256 */
if(!s->budget--) { s->failed_pc=0x0c0ca256u; return 0; }
r[17]=(r[17]&~1u)|((r[7]==r[6])!=0);
goto P_0c0ca258;
P_0c0ca258: /* original 8d0c, guest PC 0x0c0ca258 */
if(!s->budget--) { s->failed_pc=0x0c0ca258u; return 0; }
cond=r[17]&1u;
r[4]+=0x00000008u;
if(cond) { goto P_0c0ca274; }
goto P_0c0ca25c;
P_0c0ca25a: /* original 7408, guest PC 0x0c0ca25a */
if(!s->budget--) { s->failed_pc=0x0c0ca25au; return 0; }
r[4]+=0x00000008u;
goto P_0c0ca25c;
P_0c0ca25c: /* original 6063, guest PC 0x0c0ca25c */
if(!s->budget--) { s->failed_pc=0x0c0ca25cu; return 0; }
r[0]=r[6];
goto P_0c0ca25e;
P_0c0ca25e: /* original 88ff, guest PC 0x0c0ca25e */
if(!s->budget--) { s->failed_pc=0x0c0ca25eu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xffffffffu)!=0);
goto P_0c0ca260;
P_0c0ca260: /* original 8bf6, guest PC 0x0c0ca260 */
if(!s->budget--) { s->failed_pc=0x0c0ca260u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0ca250; }
goto P_0c0ca262;
P_0c0ca262: /* original e000, guest PC 0x0c0ca262 */
if(!s->budget--) { s->failed_pc=0x0c0ca262u; return 0; }
r[0]=0x00000000u;
goto P_0c0ca264;
P_0c0ca264: /* original 8051, guest PC 0x0c0ca264 */
if(!s->budget--) { s->failed_pc=0x0c0ca264u; return 0; }
write(ram,r[5]+1,r[0],1);
goto P_0c0ca266;
P_0c0ca266: /* original d421, guest PC 0x0c0ca266 */
if(!s->budget--) { s->failed_pc=0x0c0ca266u; return 0; }
r[4]=read(ram,0x0c0ca2ecu,4);
goto P_0c0ca268;
P_0c0ca268: /* original b05b, guest PC 0x0c0ca268 */
if(!s->budget--) { s->failed_pc=0x0c0ca268u; return 0; }
target=0x0c0ca322u; r[16]=0x0c0ca26cu;
r[5]=0x00000001u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0ca26cu) { target=s->pc; goto dispatch; }
goto P_0c0ca26c;
P_0c0ca26a: /* original e501, guest PC 0x0c0ca26a */
if(!s->budget--) { s->failed_pc=0x0c0ca26au; return 0; }
r[5]=0x00000001u;
goto P_0c0ca26c;
P_0c0ca26c: /* original 7f04, guest PC 0x0c0ca26c */
if(!s->budget--) { s->failed_pc=0x0c0ca26cu; return 0; }
r[15]+=0x00000004u;
goto P_0c0ca26e;
P_0c0ca26e: /* original 4f26, guest PC 0x0c0ca26e */
if(!s->budget--) { s->failed_pc=0x0c0ca26eu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0ca270;
P_0c0ca270: /* original 000b, guest PC 0x0c0ca270 */
if(!s->budget--) { s->failed_pc=0x0c0ca270u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c0ca272: /* original 0009, guest PC 0x0c0ca272 */
if(!s->budget--) { s->failed_pc=0x0c0ca272u; return 0; }
goto P_0c0ca274;
P_0c0ca274: /* original 63f2, guest PC 0x0c0ca274 */
if(!s->budget--) { s->failed_pc=0x0c0ca274u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c0ca276;
P_0c0ca276: /* original 430b, guest PC 0x0c0ca276 */
if(!s->budget--) { s->failed_pc=0x0c0ca276u; return 0; }
target=r[3];
r[16]=0x0c0ca27au;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0ca27au) { target=s->pc; goto dispatch; }
goto P_0c0ca27a;
P_0c0ca278: /* original 0009, guest PC 0x0c0ca278 */
if(!s->budget--) { s->failed_pc=0x0c0ca278u; return 0; }
goto P_0c0ca27a;
P_0c0ca27a: /* original 7f04, guest PC 0x0c0ca27a */
if(!s->budget--) { s->failed_pc=0x0c0ca27au; return 0; }
r[15]+=0x00000004u;
goto P_0c0ca27c;
P_0c0ca27c: /* original 4f26, guest PC 0x0c0ca27c */
if(!s->budget--) { s->failed_pc=0x0c0ca27cu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0ca27e;
P_0c0ca27e: /* original 000b, guest PC 0x0c0ca27e */
if(!s->budget--) { s->failed_pc=0x0c0ca27eu; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c0ca280: /* original 0009, guest PC 0x0c0ca280 */
if(!s->budget--) { s->failed_pc=0x0c0ca280u; return 0; }
return vf3_matrix_family(0x0c0ca282u,s,ram);
P_0c0ca322: /* original 000b, guest PC 0x0c0ca322 */
if(!s->budget--) { s->failed_pc=0x0c0ca322u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c0ca324: /* original 0009, guest PC 0x0c0ca324 */
if(!s->budget--) { s->failed_pc=0x0c0ca324u; return 0; }
return vf3_matrix_family(0x0c0ca326u,s,ram);
P_0c0ca6c6: /* original 2fe6, guest PC 0x0c0ca6c6 */
if(!s->budget--) { s->failed_pc=0x0c0ca6c6u; return 0; }
r[15]-=4; write(ram,r[15],r[14],4);
goto P_0c0ca6c8;
P_0c0ca6c8: /* original 6e43, guest PC 0x0c0ca6c8 */
if(!s->budget--) { s->failed_pc=0x0c0ca6c8u; return 0; }
r[14]=r[4];
goto P_0c0ca6ca;
P_0c0ca6ca: /* original 2fd6, guest PC 0x0c0ca6ca */
if(!s->budget--) { s->failed_pc=0x0c0ca6cau; return 0; }
r[15]-=4; write(ram,r[15],r[13],4);
goto P_0c0ca6cc;
P_0c0ca6cc: /* original 2fc6, guest PC 0x0c0ca6cc */
if(!s->budget--) { s->failed_pc=0x0c0ca6ccu; return 0; }
r[15]-=4; write(ram,r[15],r[12],4);
goto P_0c0ca6ce;
P_0c0ca6ce: /* original 2fb6, guest PC 0x0c0ca6ce */
if(!s->budget--) { s->failed_pc=0x0c0ca6ceu; return 0; }
r[15]-=4; write(ram,r[15],r[11],4);
goto P_0c0ca6d0;
P_0c0ca6d0: /* original 2fa6, guest PC 0x0c0ca6d0 */
if(!s->budget--) { s->failed_pc=0x0c0ca6d0u; return 0; }
r[15]-=4; write(ram,r[15],r[10],4);
goto P_0c0ca6d2;
P_0c0ca6d2: /* original 2f96, guest PC 0x0c0ca6d2 */
if(!s->budget--) { s->failed_pc=0x0c0ca6d2u; return 0; }
r[15]-=4; write(ram,r[15],r[9],4);
goto P_0c0ca6d4;
P_0c0ca6d4: /* original 2f86, guest PC 0x0c0ca6d4 */
if(!s->budget--) { s->failed_pc=0x0c0ca6d4u; return 0; }
r[15]-=4; write(ram,r[15],r[8],4);
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
r[16]=0x0c0ca6f2u;
vf3_matrix_load(s,ram,4,r[14]+r[0]);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0ca6f2u) { target=s->pc; goto dispatch; }
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
r[0]=0x0c0ca7d0u;
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
r[0]=0x0c0ca7d4u;
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
r[16]=0x0c0ca76eu;
r[4]+=0x00000004u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0ca76eu) { target=s->pc; goto dispatch; }
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
r[0]=0x0c0ca7d8u;
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
return vf3_matrix_family(0x0c0ca7b2u,s,ram);
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
return vf3_matrix_family(0x0c0ca838u,s,ram);
P_0c0caa9c: /* original 903d, guest PC 0x0c0caa9c */
if(!s->budget--) { s->failed_pc=0x0c0caa9cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0cab1au,2);
goto P_0c0caa9e;
P_0c0caa9e: /* original e340, guest PC 0x0c0caa9e */
if(!s->budget--) { s->failed_pc=0x0c0caa9eu; return 0; }
r[3]=0x00000040u;
goto P_0c0caaa0;
P_0c0caaa0: /* original 054c, guest PC 0x0c0caaa0 */
if(!s->budget--) { s->failed_pc=0x0c0caaa0u; return 0; }
r[5]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c0caaa2;
P_0c0caaa2: /* original 655c, guest PC 0x0c0caaa2 */
if(!s->budget--) { s->failed_pc=0x0c0caaa2u; return 0; }
r[5]=r[5]&255u;
goto P_0c0caaa4;
P_0c0caaa4: /* original 2358, guest PC 0x0c0caaa4 */
if(!s->budget--) { s->failed_pc=0x0c0caaa4u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[5])==0)!=0);
goto P_0c0caaa6;
P_0c0caaa6: /* original 8922, guest PC 0x0c0caaa6 */
if(!s->budget--) { s->failed_pc=0x0c0caaa6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0caaee; }
goto P_0c0caaa8;
P_0c0caaa8: /* original 9038, guest PC 0x0c0caaa8 */
if(!s->budget--) { s->failed_pc=0x0c0caaa8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0cab1cu,2);
goto P_0c0caaaa;
P_0c0caaaa: /* original f646, guest PC 0x0c0caaaa */
if(!s->budget--) { s->failed_pc=0x0c0caaaau; return 0; }
vf3_matrix_load(s,ram,6,r[4]+r[0]);
goto P_0c0caaac;
P_0c0caaac: /* original 700c, guest PC 0x0c0caaac */
if(!s->budget--) { s->failed_pc=0x0c0caaacu; return 0; }
r[0]+=0x0000000cu;
goto P_0c0caaae;
P_0c0caaae: /* original f746, guest PC 0x0c0caaae */
if(!s->budget--) { s->failed_pc=0x0c0caaaeu; return 0; }
vf3_matrix_load(s,ram,7,r[4]+r[0]);
goto P_0c0caab0;
P_0c0caab0: /* original 70dc, guest PC 0x0c0caab0 */
if(!s->budget--) { s->failed_pc=0x0c0caab0u; return 0; }
r[0]+=0xffffffdcu;
goto P_0c0caab2;
P_0c0caab2: /* original f846, guest PC 0x0c0caab2 */
if(!s->budget--) { s->failed_pc=0x0c0caab2u; return 0; }
vf3_matrix_load(s,ram,8,r[4]+r[0]);
goto P_0c0caab4;
P_0c0caab4: /* original 700c, guest PC 0x0c0caab4 */
if(!s->budget--) { s->failed_pc=0x0c0caab4u; return 0; }
r[0]+=0x0000000cu;
goto P_0c0caab6;
P_0c0caab6: /* original f946, guest PC 0x0c0caab6 */
if(!s->budget--) { s->failed_pc=0x0c0caab6u; return 0; }
vf3_matrix_load(s,ram,9,r[4]+r[0]);
goto P_0c0caab8;
P_0c0caab8: /* original c719, guest PC 0x0c0caab8 */
if(!s->budget--) { s->failed_pc=0x0c0caab8u; return 0; }
r[0]=0x0c0cab20u;
goto P_0c0caaba;
P_0c0caaba: /* original f508, guest PC 0x0c0caaba */
if(!s->budget--) { s->failed_pc=0x0c0caabau; return 0; }
vf3_matrix_load(s,ram,5,r[0]);
goto P_0c0caabc;
P_0c0caabc: /* original c719, guest PC 0x0c0caabc */
if(!s->budget--) { s->failed_pc=0x0c0caabcu; return 0; }
r[0]=0x0c0cab24u;
goto P_0c0caabe;
P_0c0caabe: /* original f655, guest PC 0x0c0caabe */
if(!s->budget--) { s->failed_pc=0x0c0caabeu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[6])>as_float(fr[5]))!=0);
goto P_0c0caac0;
P_0c0caac0: /* original 8d0e, guest PC 0x0c0caac0 */
if(!s->budget--) { s->failed_pc=0x0c0caac0u; return 0; }
cond=r[17]&1u;
vf3_matrix_load(s,ram,4,r[0]);
if(cond) { goto P_0c0caae0; }
goto P_0c0caac4;
P_0c0caac2: /* original f408, guest PC 0x0c0caac2 */
if(!s->budget--) { s->failed_pc=0x0c0caac2u; return 0; }
vf3_matrix_load(s,ram,4,r[0]);
goto P_0c0caac4;
P_0c0caac4: /* original f465, guest PC 0x0c0caac4 */
if(!s->budget--) { s->failed_pc=0x0c0caac4u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[4])>as_float(fr[6]))!=0);
goto P_0c0caac6;
P_0c0caac6: /* original 890b, guest PC 0x0c0caac6 */
if(!s->budget--) { s->failed_pc=0x0c0caac6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0caae0; }
goto P_0c0caac8;
P_0c0caac8: /* original f755, guest PC 0x0c0caac8 */
if(!s->budget--) { s->failed_pc=0x0c0caac8u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[7])>as_float(fr[5]))!=0);
goto P_0c0caaca;
P_0c0caaca: /* original 8909, guest PC 0x0c0caaca */
if(!s->budget--) { s->failed_pc=0x0c0caacau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0caae0; }
goto P_0c0caacc;
P_0c0caacc: /* original f475, guest PC 0x0c0caacc */
if(!s->budget--) { s->failed_pc=0x0c0caaccu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[4])>as_float(fr[7]))!=0);
goto P_0c0caace;
P_0c0caace: /* original 8907, guest PC 0x0c0caace */
if(!s->budget--) { s->failed_pc=0x0c0caaceu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0caae0; }
goto P_0c0caad0;
P_0c0caad0: /* original f855, guest PC 0x0c0caad0 */
if(!s->budget--) { s->failed_pc=0x0c0caad0u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[8])>as_float(fr[5]))!=0);
goto P_0c0caad2;
P_0c0caad2: /* original 8905, guest PC 0x0c0caad2 */
if(!s->budget--) { s->failed_pc=0x0c0caad2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0caae0; }
goto P_0c0caad4;
P_0c0caad4: /* original f485, guest PC 0x0c0caad4 */
if(!s->budget--) { s->failed_pc=0x0c0caad4u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[4])>as_float(fr[8]))!=0);
goto P_0c0caad6;
P_0c0caad6: /* original 8903, guest PC 0x0c0caad6 */
if(!s->budget--) { s->failed_pc=0x0c0caad6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0caae0; }
goto P_0c0caad8;
P_0c0caad8: /* original f955, guest PC 0x0c0caad8 */
if(!s->budget--) { s->failed_pc=0x0c0caad8u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[9])>as_float(fr[5]))!=0);
goto P_0c0caada;
P_0c0caada: /* original 8901, guest PC 0x0c0caada */
if(!s->budget--) { s->failed_pc=0x0c0caadau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0caae0; }
goto P_0c0caadc;
P_0c0caadc: /* original f495, guest PC 0x0c0caadc */
if(!s->budget--) { s->failed_pc=0x0c0caadcu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[4])>as_float(fr[9]))!=0);
goto P_0c0caade;
P_0c0caade: /* original 8b02, guest PC 0x0c0caade */
if(!s->budget--) { s->failed_pc=0x0c0caadeu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0caae6; }
goto P_0c0caae0;
P_0c0caae0: /* original e310, guest PC 0x0c0caae0 */
if(!s->budget--) { s->failed_pc=0x0c0caae0u; return 0; }
r[3]=0x00000010u;
goto P_0c0caae2;
P_0c0caae2: /* original a002, guest PC 0x0c0caae2 */
if(!s->budget--) { s->failed_pc=0x0c0caae2u; return 0; }
r[5]|=r[3];
goto P_0c0caaea;
P_0c0caae4: /* original 253b, guest PC 0x0c0caae4 */
if(!s->budget--) { s->failed_pc=0x0c0caae4u; return 0; }
r[5]|=r[3];
goto P_0c0caae6;
P_0c0caae6: /* original e1ef, guest PC 0x0c0caae6 */
if(!s->budget--) { s->failed_pc=0x0c0caae6u; return 0; }
r[1]=0xffffffefu;
goto P_0c0caae8;
P_0c0caae8: /* original 2519, guest PC 0x0c0caae8 */
if(!s->budget--) { s->failed_pc=0x0c0caae8u; return 0; }
r[5]&=r[1];
goto P_0c0caaea;
P_0c0caaea: /* original 9016, guest PC 0x0c0caaea */
if(!s->budget--) { s->failed_pc=0x0c0caaeau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0cab1au,2);
goto P_0c0caaec;
P_0c0caaec: /* original 0454, guest PC 0x0c0caaec */
if(!s->budget--) { s->failed_pc=0x0c0caaecu; return 0; }
write(ram,r[4]+r[0],r[5],1);
goto P_0c0caaee;
P_0c0caaee: /* original 000b, guest PC 0x0c0caaee */
if(!s->budget--) { s->failed_pc=0x0c0caaeeu; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c0caaf0: /* original 0009, guest PC 0x0c0caaf0 */
if(!s->budget--) { s->failed_pc=0x0c0caaf0u; return 0; }
goto P_0c0caaf2;
P_0c0caaf2: /* original 4f22, guest PC 0x0c0caaf2 */
if(!s->budget--) { s->failed_pc=0x0c0caaf2u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0caaf4;
P_0c0caaf4: /* original 7ffc, guest PC 0x0c0caaf4 */
if(!s->budget--) { s->failed_pc=0x0c0caaf4u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c0caaf6;
P_0c0caaf6: /* original 2f52, guest PC 0x0c0caaf6 */
if(!s->budget--) { s->failed_pc=0x0c0caaf6u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0caaf8;
P_0c0caaf8: /* original d10c, guest PC 0x0c0caaf8 */
if(!s->budget--) { s->failed_pc=0x0c0caaf8u; return 0; }
r[1]=read(ram,0x0c0cab2cu,4);
goto P_0c0caafa;
P_0c0caafa: /* original d30b, guest PC 0x0c0caafa */
if(!s->budget--) { s->failed_pc=0x0c0caafau; return 0; }
r[3]=read(ram,0x0c0cab28u,4);
goto P_0c0caafc;
P_0c0caafc: /* original 6212, guest PC 0x0c0caafc */
if(!s->budget--) { s->failed_pc=0x0c0caafcu; return 0; }
tmp=read(ram,r[1],4);
r[2]=tmp;
goto P_0c0caafe;
P_0c0caafe: /* original 2238, guest PC 0x0c0caafe */
if(!s->budget--) { s->failed_pc=0x0c0caafeu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c0cab00;
P_0c0cab00: /* original 8b03, guest PC 0x0c0cab00 */
if(!s->budget--) { s->failed_pc=0x0c0cab00u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0cab0a; }
goto P_0c0cab02;
P_0c0cab02: /* original b015, guest PC 0x0c0cab02 */
if(!s->budget--) { s->failed_pc=0x0c0cab02u; return 0; }
target=0x0c0cab30u; r[16]=0x0c0cab06u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0cab06u) { target=s->pc; goto dispatch; }
goto P_0c0cab06;
P_0c0cab04: /* original 0009, guest PC 0x0c0cab04 */
if(!s->budget--) { s->failed_pc=0x0c0cab04u; return 0; }
goto P_0c0cab06;
P_0c0cab06: /* original b013, guest PC 0x0c0cab06 */
if(!s->budget--) { s->failed_pc=0x0c0cab06u; return 0; }
target=0x0c0cab30u; r[16]=0x0c0cab0au;
tmp=read(ram,r[15],4);
r[4]=tmp;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0cab0au) { target=s->pc; goto dispatch; }
goto P_0c0cab0a;
P_0c0cab08: /* original 64f2, guest PC 0x0c0cab08 */
if(!s->budget--) { s->failed_pc=0x0c0cab08u; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c0cab0a;
P_0c0cab0a: /* original 7f04, guest PC 0x0c0cab0a */
if(!s->budget--) { s->failed_pc=0x0c0cab0au; return 0; }
r[15]+=0x00000004u;
goto P_0c0cab0c;
P_0c0cab0c: /* original 4f26, guest PC 0x0c0cab0c */
if(!s->budget--) { s->failed_pc=0x0c0cab0cu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0cab0e;
P_0c0cab0e: /* original 000b, guest PC 0x0c0cab0e */
if(!s->budget--) { s->failed_pc=0x0c0cab0eu; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c0cab10: /* original 0009, guest PC 0x0c0cab10 */
if(!s->budget--) { s->failed_pc=0x0c0cab10u; return 0; }
return vf3_matrix_family(0x0c0cab12u,s,ram);
P_0c0cab30: /* original 2fe6, guest PC 0x0c0cab30 */
if(!s->budget--) { s->failed_pc=0x0c0cab30u; return 0; }
r[15]-=4; write(ram,r[15],r[14],4);
goto P_0c0cab32;
P_0c0cab32: /* original 6e43, guest PC 0x0c0cab32 */
if(!s->budget--) { s->failed_pc=0x0c0cab32u; return 0; }
r[14]=r[4];
goto P_0c0cab34;
P_0c0cab34: /* original 2fd6, guest PC 0x0c0cab34 */
if(!s->budget--) { s->failed_pc=0x0c0cab34u; return 0; }
r[15]-=4; write(ram,r[15],r[13],4);
goto P_0c0cab36;
P_0c0cab36: /* original 2fc6, guest PC 0x0c0cab36 */
if(!s->budget--) { s->failed_pc=0x0c0cab36u; return 0; }
r[15]-=4; write(ram,r[15],r[12],4);
goto P_0c0cab38;
P_0c0cab38: /* original 2fb6, guest PC 0x0c0cab38 */
if(!s->budget--) { s->failed_pc=0x0c0cab38u; return 0; }
r[15]-=4; write(ram,r[15],r[11],4);
goto P_0c0cab3a;
P_0c0cab3a: /* original 2fa6, guest PC 0x0c0cab3a */
if(!s->budget--) { s->failed_pc=0x0c0cab3au; return 0; }
r[15]-=4; write(ram,r[15],r[10],4);
goto P_0c0cab3c;
P_0c0cab3c: /* original 2f96, guest PC 0x0c0cab3c */
if(!s->budget--) { s->failed_pc=0x0c0cab3cu; return 0; }
r[15]-=4; write(ram,r[15],r[9],4);
goto P_0c0cab3e;
P_0c0cab3e: /* original 2f86, guest PC 0x0c0cab3e */
if(!s->budget--) { s->failed_pc=0x0c0cab3eu; return 0; }
r[15]-=4; write(ram,r[15],r[8],4);
goto P_0c0cab40;
P_0c0cab40: /* original fffb, guest PC 0x0c0cab40 */
if(!s->budget--) { s->failed_pc=0x0c0cab40u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c0cab42;
P_0c0cab42: /* original ffeb, guest PC 0x0c0cab42 */
if(!s->budget--) { s->failed_pc=0x0c0cab42u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,14,r[15]);
goto P_0c0cab44;
P_0c0cab44: /* original ffdb, guest PC 0x0c0cab44 */
if(!s->budget--) { s->failed_pc=0x0c0cab44u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,13,r[15]);
goto P_0c0cab46;
P_0c0cab46: /* original 4f22, guest PC 0x0c0cab46 */
if(!s->budget--) { s->failed_pc=0x0c0cab46u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0cab48;
P_0c0cab48: /* original d33c, guest PC 0x0c0cab48 */
if(!s->budget--) { s->failed_pc=0x0c0cab48u; return 0; }
r[3]=read(ram,0x0c0cac3cu,4);
goto P_0c0cab4a;
P_0c0cab4a: /* original 7fc4, guest PC 0x0c0cab4a */
if(!s->budget--) { s->failed_pc=0x0c0cab4au; return 0; }
r[15]+=0xffffffc4u;
goto P_0c0cab4c;
P_0c0cab4c: /* original 1f37, guest PC 0x0c0cab4c */
if(!s->budget--) { s->failed_pc=0x0c0cab4cu; return 0; }
write(ram,r[15]+28,r[3],4);
goto P_0c0cab4e;
P_0c0cab4e: /* original d23c, guest PC 0x0c0cab4e */
if(!s->budget--) { s->failed_pc=0x0c0cab4eu; return 0; }
r[2]=read(ram,0x0c0cac40u,4);
goto P_0c0cab50;
P_0c0cab50: /* original 1f28, guest PC 0x0c0cab50 */
if(!s->budget--) { s->failed_pc=0x0c0cab50u; return 0; }
write(ram,r[15]+32,r[2],4);
goto P_0c0cab52;
P_0c0cab52: /* original bdb8, guest PC 0x0c0cab52 */
if(!s->budget--) { s->failed_pc=0x0c0cab52u; return 0; }
target=0x0c0ca6c6u; r[16]=0x0c0cab56u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0cab56u) { target=s->pc; goto dispatch; }
goto P_0c0cab56;
P_0c0cab54: /* original 64e3, guest PC 0x0c0cab54 */
if(!s->budget--) { s->failed_pc=0x0c0cab54u; return 0; }
r[4]=r[14];
goto P_0c0cab56;
P_0c0cab56: /* original bfa1, guest PC 0x0c0cab56 */
if(!s->budget--) { s->failed_pc=0x0c0cab56u; return 0; }
target=0x0c0caa9cu; r[16]=0x0c0cab5au;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0cab5au) { target=s->pc; goto dispatch; }
goto P_0c0cab5a;
P_0c0cab58: /* original 64e3, guest PC 0x0c0cab58 */
if(!s->budget--) { s->failed_pc=0x0c0cab58u; return 0; }
r[4]=r[14];
goto P_0c0cab5a;
P_0c0cab5a: /* original e048, guest PC 0x0c0cab5a */
if(!s->budget--) { s->failed_pc=0x0c0cab5au; return 0; }
r[0]=0x00000048u;
goto P_0c0cab5c;
P_0c0cab5c: /* original 65e2, guest PC 0x0c0cab5c */
if(!s->budget--) { s->failed_pc=0x0c0cab5cu; return 0; }
tmp=read(ram,r[14],4);
r[5]=tmp;
goto P_0c0cab5e;
P_0c0cab5e: /* original 03ee, guest PC 0x0c0cab5e */
if(!s->budget--) { s->failed_pc=0x0c0cab5eu; return 0; }
r[3]=read(ram,r[14]+r[0],4);
goto P_0c0cab60;
P_0c0cab60: /* original 1f34, guest PC 0x0c0cab60 */
if(!s->budget--) { s->failed_pc=0x0c0cab60u; return 0; }
write(ram,r[15]+16,r[3],4);
goto P_0c0cab62;
P_0c0cab62: /* original d338, guest PC 0x0c0cab62 */
if(!s->budget--) { s->failed_pc=0x0c0cab62u; return 0; }
r[3]=read(ram,0x0c0cac44u,4);
goto P_0c0cab64;
P_0c0cab64: /* original 2358, guest PC 0x0c0cab64 */
if(!s->budget--) { s->failed_pc=0x0c0cab64u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[5])==0)!=0);
goto P_0c0cab66;
P_0c0cab66: /* original 8f04, guest PC 0x0c0cab66 */
if(!s->budget--) { s->failed_pc=0x0c0cab66u; return 0; }
cond=r[17]&1u;
r[10]=0x00000000u;
if(!cond) { goto P_0c0cab72; }
goto P_0c0cab6a;
P_0c0cab68: /* original ea00, guest PC 0x0c0cab68 */
if(!s->budget--) { s->failed_pc=0x0c0cab68u; return 0; }
r[10]=0x00000000u;
goto P_0c0cab6a;
P_0c0cab6a: /* original 52f4, guest PC 0x0c0cab6a */
if(!s->budget--) { s->failed_pc=0x0c0cab6au; return 0; }
r[2]=read(ram,r[15]+16,4);
goto P_0c0cab6c;
P_0c0cab6c: /* original 9360, guest PC 0x0c0cab6c */
if(!s->budget--) { s->failed_pc=0x0c0cab6cu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0cac30u,2);
goto P_0c0cab6e;
P_0c0cab6e: /* original 2238, guest PC 0x0c0cab6e */
if(!s->budget--) { s->failed_pc=0x0c0cab6eu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c0cab70;
P_0c0cab70: /* original 8901, guest PC 0x0c0cab70 */
if(!s->budget--) { s->failed_pc=0x0c0cab70u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0cab76; }
goto P_0c0cab72;
P_0c0cab72: /* original a001, guest PC 0x0c0cab72 */
if(!s->budget--) { s->failed_pc=0x0c0cab72u; return 0; }
r[8]=0x00000001u;
goto P_0c0cab78;
P_0c0cab74: /* original e801, guest PC 0x0c0cab74 */
if(!s->budget--) { s->failed_pc=0x0c0cab74u; return 0; }
r[8]=0x00000001u;
goto P_0c0cab76;
P_0c0cab76: /* original 68a3, guest PC 0x0c0cab76 */
if(!s->budget--) { s->failed_pc=0x0c0cab76u; return 0; }
r[8]=r[10];
goto P_0c0cab78;
P_0c0cab78: /* original c733, guest PC 0x0c0cab78 */
if(!s->budget--) { s->failed_pc=0x0c0cab78u; return 0; }
r[0]=0x0c0cac48u;
goto P_0c0cab7a;
P_0c0cab7a: /* original 6ba3, guest PC 0x0c0cab7a */
if(!s->budget--) { s->failed_pc=0x0c0cab7au; return 0; }
r[11]=r[10];
goto P_0c0cab7c;
P_0c0cab7c: /* original f308, guest PC 0x0c0cab7c */
if(!s->budget--) { s->failed_pc=0x0c0cab7cu; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c0cab7e;
P_0c0cab7e: /* original e004, guest PC 0x0c0cab7e */
if(!s->budget--) { s->failed_pc=0x0c0cab7eu; return 0; }
r[0]=0x00000004u;
goto P_0c0cab80;
P_0c0cab80: /* original 6cb3, guest PC 0x0c0cab80 */
if(!s->budget--) { s->failed_pc=0x0c0cab80u; return 0; }
r[12]=r[11];
goto P_0c0cab82;
P_0c0cab82: /* original 69b3, guest PC 0x0c0cab82 */
if(!s->budget--) { s->failed_pc=0x0c0cab82u; return 0; }
r[9]=r[11];
goto P_0c0cab84;
P_0c0cab84: /* original ff37, guest PC 0x0c0cab84 */
if(!s->budget--) { s->failed_pc=0x0c0cab84u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0cab86;
P_0c0cab86: /* original e014, guest PC 0x0c0cab86 */
if(!s->budget--) { s->failed_pc=0x0c0cab86u; return 0; }
r[0]=0x00000014u;
goto P_0c0cab88;
P_0c0cab88: /* original f4e6, guest PC 0x0c0cab88 */
if(!s->budget--) { s->failed_pc=0x0c0cab88u; return 0; }
vf3_matrix_load(s,ram,4,r[14]+r[0]);
goto P_0c0cab8a;
P_0c0cab8a: /* original c730, guest PC 0x0c0cab8a */
if(!s->budget--) { s->failed_pc=0x0c0cab8au; return 0; }
r[0]=0x0c0cac4cu;
goto P_0c0cab8c;
P_0c0cab8c: /* original 9352, guest PC 0x0c0cab8c */
if(!s->budget--) { s->failed_pc=0x0c0cab8cu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0cac34u,2);
goto P_0c0cab8e;
P_0c0cab8e: /* original f708, guest PC 0x0c0cab8e */
if(!s->budget--) { s->failed_pc=0x0c0cab8eu; return 0; }
vf3_matrix_load(s,ram,7,r[0]);
goto P_0c0cab90;
P_0c0cab90: /* original e004, guest PC 0x0c0cab90 */
if(!s->budget--) { s->failed_pc=0x0c0cab90u; return 0; }
r[0]=0x00000004u;
goto P_0c0cab92;
P_0c0cab92: /* original 33ec, guest PC 0x0c0cab92 */
if(!s->budget--) { s->failed_pc=0x0c0cab92u; return 0; }
r[3]+=r[14];
goto P_0c0cab94;
P_0c0cab94: /* original f34c, guest PC 0x0c0cab94 */
if(!s->budget--) { s->failed_pc=0x0c0cab94u; return 0; }
vf3_matrix_move(s,3,4);
goto P_0c0cab96;
P_0c0cab96: /* original f4f6, guest PC 0x0c0cab96 */
if(!s->budget--) { s->failed_pc=0x0c0cab96u; return 0; }
vf3_matrix_load(s,ram,4,r[15]+r[0]);
goto P_0c0cab98;
P_0c0cab98: /* original 904b, guest PC 0x0c0cab98 */
if(!s->budget--) { s->failed_pc=0x0c0cab98u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0cac32u,2);
goto P_0c0cab9a;
P_0c0cab9a: /* original f430, guest PC 0x0c0cab9a */
if(!s->budget--) { s->failed_pc=0x0c0cab9au; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'+');
goto P_0c0cab9c;
P_0c0cab9c: /* original dd2c, guest PC 0x0c0cab9c */
if(!s->budget--) { s->failed_pc=0x0c0cab9cu; return 0; }
r[13]=read(ram,0x0c0cac50u,4);
goto P_0c0cab9e;
P_0c0cab9e: /* original 07ee, guest PC 0x0c0cab9e */
if(!s->budget--) { s->failed_pc=0x0c0cab9eu; return 0; }
r[7]=read(ram,r[14]+r[0],4);
goto P_0c0caba0;
P_0c0caba0: /* original 1f3c, guest PC 0x0c0caba0 */
if(!s->budget--) { s->failed_pc=0x0c0caba0u; return 0; }
write(ram,r[15]+48,r[3],4);
goto P_0c0caba2;
P_0c0caba2: /* original 64d3, guest PC 0x0c0caba2 */
if(!s->budget--) { s->failed_pc=0x0c0caba2u; return 0; }
r[4]=r[13];
goto P_0c0caba4;
P_0c0caba4: /* original 9247, guest PC 0x0c0caba4 */
if(!s->budget--) { s->failed_pc=0x0c0caba4u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0cac36u,2);
goto P_0c0caba6;
P_0c0caba6: /* original 32ec, guest PC 0x0c0caba6 */
if(!s->budget--) { s->failed_pc=0x0c0caba6u; return 0; }
r[2]+=r[14];
goto P_0c0caba8;
P_0c0caba8: /* original 1f2d, guest PC 0x0c0caba8 */
if(!s->budget--) { s->failed_pc=0x0c0caba8u; return 0; }
write(ram,r[15]+52,r[2],4);
goto P_0c0cabaa;
P_0c0cabaa: /* original 9345, guest PC 0x0c0cabaa */
if(!s->budget--) { s->failed_pc=0x0c0cabaau; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0cac38u,2);
goto P_0c0cabac;
P_0c0cabac: /* original 33ec, guest PC 0x0c0cabac */
if(!s->budget--) { s->failed_pc=0x0c0cabacu; return 0; }
r[3]+=r[14];
goto P_0c0cabae;
P_0c0cabae: /* original 1f3e, guest PC 0x0c0cabae */
if(!s->budget--) { s->failed_pc=0x0c0cabaeu; return 0; }
write(ram,r[15]+56,r[3],4);
goto P_0c0cabb0;
P_0c0cabb0: /* original e32c, guest PC 0x0c0cabb0 */
if(!s->budget--) { s->failed_pc=0x0c0cabb0u; return 0; }
r[3]=0x0000002cu;
goto P_0c0cabb2;
P_0c0cabb2: /* original 923f, guest PC 0x0c0cabb2 */
if(!s->budget--) { s->failed_pc=0x0c0cabb2u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0cac34u,2);
goto P_0c0cabb4;
P_0c0cabb4: /* original 32ec, guest PC 0x0c0cabb4 */
if(!s->budget--) { s->failed_pc=0x0c0cabb4u; return 0; }
r[2]+=r[14];
goto P_0c0cabb6;
P_0c0cabb6: /* original 1f2a, guest PC 0x0c0cabb6 */
if(!s->budget--) { s->failed_pc=0x0c0cabb6u; return 0; }
write(ram,r[15]+40,r[2],4);
goto P_0c0cabb8;
P_0c0cabb8: /* original e11c, guest PC 0x0c0cabb8 */
if(!s->budget--) { s->failed_pc=0x0c0cabb8u; return 0; }
r[1]=0x0000001cu;
goto P_0c0cabba;
P_0c0cabba: /* original 1f3b, guest PC 0x0c0cabba */
if(!s->budget--) { s->failed_pc=0x0c0cabbau; return 0; }
write(ram,r[15]+44,r[3],4);
goto P_0c0cabbc;
P_0c0cabbc: /* original 50f7, guest PC 0x0c0cabbc */
if(!s->budget--) { s->failed_pc=0x0c0cabbcu; return 0; }
r[0]=read(ram,r[15]+28,4);
goto P_0c0cabbe;
P_0c0cabbe: /* original 001c, guest PC 0x0c0cabbe */
if(!s->budget--) { s->failed_pc=0x0c0cabbeu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[1]+r[0],1);
goto P_0c0cabc0;
P_0c0cabc0: /* original 600c, guest PC 0x0c0cabc0 */
if(!s->budget--) { s->failed_pc=0x0c0cabc0u; return 0; }
r[0]=r[0]&255u;
goto P_0c0cabc2;
P_0c0cabc2: /* original c90f, guest PC 0x0c0cabc2 */
if(!s->budget--) { s->failed_pc=0x0c0cabc2u; return 0; }
r[0]&=15u;
goto P_0c0cabc4;
P_0c0cabc4: /* original 8804, guest PC 0x0c0cabc4 */
if(!s->budget--) { s->failed_pc=0x0c0cabc4u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000004u)!=0);
goto P_0c0cabc6;
P_0c0cabc6: /* original 8d02, guest PC 0x0c0cabc6 */
if(!s->budget--) { s->failed_pc=0x0c0cabc6u; return 0; }
cond=r[17]&1u;
write(ram,r[15],r[0],4);
if(cond) { goto P_0c0cabce; }
goto P_0c0cabca;
P_0c0cabc8: /* original 2f02, guest PC 0x0c0cabc8 */
if(!s->budget--) { s->failed_pc=0x0c0cabc8u; return 0; }
write(ram,r[15],r[0],4);
goto P_0c0cabca;
P_0c0cabca: /* original 8801, guest PC 0x0c0cabca */
if(!s->budget--) { s->failed_pc=0x0c0cabcau; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c0cabcc;
P_0c0cabcc: /* original 8b02, guest PC 0x0c0cabcc */
if(!s->budget--) { s->failed_pc=0x0c0cabccu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0cabd4; }
goto P_0c0cabce;
P_0c0cabce: /* original d621, guest PC 0x0c0cabce */
if(!s->budget--) { s->failed_pc=0x0c0cabceu; return 0; }
r[6]=read(ram,0x0c0cac54u,4);
goto P_0c0cabd0;
P_0c0cabd0: /* original a001, guest PC 0x0c0cabd0 */
if(!s->budget--) { s->failed_pc=0x0c0cabd0u; return 0; }
goto P_0c0cabd6;
P_0c0cabd2: /* original 0009, guest PC 0x0c0cabd2 */
if(!s->budget--) { s->failed_pc=0x0c0cabd2u; return 0; }
goto P_0c0cabd4;
P_0c0cabd4: /* original d620, guest PC 0x0c0cabd4 */
if(!s->budget--) { s->failed_pc=0x0c0cabd4u; return 0; }
r[6]=read(ram,0x0c0cac58u,4);
goto P_0c0cabd6;
P_0c0cabd6: /* original e21c, guest PC 0x0c0cabd6 */
if(!s->budget--) { s->failed_pc=0x0c0cabd6u; return 0; }
r[2]=0x0000001cu;
goto P_0c0cabd8;
P_0c0cabd8: /* original 1f22, guest PC 0x0c0cabd8 */
if(!s->budget--) { s->failed_pc=0x0c0cabd8u; return 0; }
write(ram,r[15]+8,r[2],4);
goto P_0c0cabda;
P_0c0cabda: /* original 53fe, guest PC 0x0c0cabda */
if(!s->budget--) { s->failed_pc=0x0c0cabdau; return 0; }
r[3]=read(ram,r[15]+56,4);
goto P_0c0cabdc;
P_0c0cabdc: /* original e004, guest PC 0x0c0cabdc */
if(!s->budget--) { s->failed_pc=0x0c0cabdcu; return 0; }
r[0]=0x00000004u;
goto P_0c0cabde;
P_0c0cabde: /* original 7304, guest PC 0x0c0cabde */
if(!s->budget--) { s->failed_pc=0x0c0cabdeu; return 0; }
r[3]+=0x00000004u;
goto P_0c0cabe0;
P_0c0cabe0: /* original 1f3e, guest PC 0x0c0cabe0 */
if(!s->budget--) { s->failed_pc=0x0c0cabe0u; return 0; }
write(ram,r[15]+56,r[3],4);
goto P_0c0cabe2;
P_0c0cabe2: /* original 73fc, guest PC 0x0c0cabe2 */
if(!s->budget--) { s->failed_pc=0x0c0cabe2u; return 0; }
r[3]+=0xfffffffcu;
goto P_0c0cabe4;
P_0c0cabe4: /* original f338, guest PC 0x0c0cabe4 */
if(!s->budget--) { s->failed_pc=0x0c0cabe4u; return 0; }
vf3_matrix_load(s,ram,3,r[3]);
goto P_0c0cabe6;
P_0c0cabe6: /* original 53fd, guest PC 0x0c0cabe6 */
if(!s->budget--) { s->failed_pc=0x0c0cabe6u; return 0; }
r[3]=read(ram,r[15]+52,4);
goto P_0c0cabe8;
P_0c0cabe8: /* original f576, guest PC 0x0c0cabe8 */
if(!s->budget--) { s->failed_pc=0x0c0cabe8u; return 0; }
vf3_matrix_load(s,ram,5,r[7]+r[0]);
goto P_0c0cabea;
P_0c0cabea: /* original 770c, guest PC 0x0c0cabea */
if(!s->budget--) { s->failed_pc=0x0c0cabeau; return 0; }
r[7]+=0x0000000cu;
goto P_0c0cabec;
P_0c0cabec: /* original 7304, guest PC 0x0c0cabec */
if(!s->budget--) { s->failed_pc=0x0c0cabecu; return 0; }
r[3]+=0x00000004u;
goto P_0c0cabee;
P_0c0cabee: /* original 1f3d, guest PC 0x0c0cabee */
if(!s->budget--) { s->failed_pc=0x0c0cabeeu; return 0; }
write(ram,r[15]+52,r[3],4);
goto P_0c0cabf0;
P_0c0cabf0: /* original 73fc, guest PC 0x0c0cabf0 */
if(!s->budget--) { s->failed_pc=0x0c0cabf0u; return 0; }
r[3]+=0xfffffffcu;
goto P_0c0cabf2;
P_0c0cabf2: /* original 6260, guest PC 0x0c0cabf2 */
if(!s->budget--) { s->failed_pc=0x0c0cabf2u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[6],1);
r[2]=tmp;
goto P_0c0cabf4;
P_0c0cabf4: /* original f838, guest PC 0x0c0cabf4 */
if(!s->budget--) { s->failed_pc=0x0c0cabf4u; return 0; }
vf3_matrix_load(s,ram,8,r[3]);
goto P_0c0cabf6;
P_0c0cabf6: /* original 1f26, guest PC 0x0c0cabf6 */
if(!s->budget--) { s->failed_pc=0x0c0cabf6u; return 0; }
write(ram,r[15]+24,r[2],4);
goto P_0c0cabf8;
P_0c0cabf8: /* original 4208, guest PC 0x0c0cabf8 */
if(!s->budget--) { s->failed_pc=0x0c0cabf8u; return 0; }
r[2]<<=2;
goto P_0c0cabfa;
P_0c0cabfa: /* original 50fc, guest PC 0x0c0cabfa */
if(!s->budget--) { s->failed_pc=0x0c0cabfau; return 0; }
r[0]=read(ram,r[15]+48,4);
goto P_0c0cabfc;
P_0c0cabfc: /* original f581, guest PC 0x0c0cabfc */
if(!s->budget--) { s->failed_pc=0x0c0cabfcu; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[8],r[18],'-');
goto P_0c0cabfe;
P_0c0cabfe: /* original 032e, guest PC 0x0c0cabfe */
if(!s->budget--) { s->failed_pc=0x0c0cabfeu; return 0; }
r[3]=read(ram,r[2]+r[0],4);
goto P_0c0cac00;
P_0c0cac00: /* original 2f32, guest PC 0x0c0cac00 */
if(!s->budget--) { s->failed_pc=0x0c0cac00u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c0cac02;
P_0c0cac02: /* original 52fb, guest PC 0x0c0cac02 */
if(!s->budget--) { s->failed_pc=0x0c0cac02u; return 0; }
r[2]=read(ram,r[15]+44,4);
goto P_0c0cac04;
P_0c0cac04: /* original 2239, guest PC 0x0c0cac04 */
if(!s->budget--) { s->failed_pc=0x0c0cac04u; return 0; }
r[2]&=r[3];
goto P_0c0cac06;
P_0c0cac06: /* original 1f26, guest PC 0x0c0cac06 */
if(!s->budget--) { s->failed_pc=0x0c0cac06u; return 0; }
write(ram,r[15]+24,r[2],4);
goto P_0c0cac08;
P_0c0cac08: /* original 51fa, guest PC 0x0c0cac08 */
if(!s->budget--) { s->failed_pc=0x0c0cac08u; return 0; }
r[1]=read(ram,r[15]+40,4);
goto P_0c0cac0a;
P_0c0cac0a: /* original 7104, guest PC 0x0c0cac0a */
if(!s->budget--) { s->failed_pc=0x0c0cac0au; return 0; }
r[1]+=0x00000004u;
goto P_0c0cac0c;
P_0c0cac0c: /* original 1f1a, guest PC 0x0c0cac0c */
if(!s->budget--) { s->failed_pc=0x0c0cac0cu; return 0; }
write(ram,r[15]+40,r[1],4);
goto P_0c0cac0e;
P_0c0cac0e: /* original 2136, guest PC 0x0c0cac0e */
if(!s->budget--) { s->failed_pc=0x0c0cac0eu; return 0; }
r[1]-=4; write(ram,r[1],r[3],4);
goto P_0c0cac10;
P_0c0cac10: /* original 53f6, guest PC 0x0c0cac10 */
if(!s->budget--) { s->failed_pc=0x0c0cac10u; return 0; }
r[3]=read(ram,r[15]+24,4);
goto P_0c0cac12;
P_0c0cac12: /* original f67c, guest PC 0x0c0cac12 */
if(!s->budget--) { s->failed_pc=0x0c0cac12u; return 0; }
vf3_matrix_move(s,6,7);
goto P_0c0cac14;
P_0c0cac14: /* original 2338, guest PC 0x0c0cac14 */
if(!s->budget--) { s->failed_pc=0x0c0cac14u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c0cac16;
P_0c0cac16: /* original 8d03, guest PC 0x0c0cac16 */
if(!s->budget--) { s->failed_pc=0x0c0cac16u; return 0; }
cond=r[17]&1u;
fr[6]=vf3_fpu_binary(fr[6],fr[3],r[18],'+');
if(cond) { goto P_0c0cac20; }
goto P_0c0cac1a;
P_0c0cac18: /* original f630, guest PC 0x0c0cac18 */
if(!s->budget--) { s->failed_pc=0x0c0cac18u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[3],r[18],'+');
goto P_0c0cac1a;
P_0c0cac1a: /* original e301, guest PC 0x0c0cac1a */
if(!s->budget--) { s->failed_pc=0x0c0cac1au; return 0; }
r[3]=0x00000001u;
goto P_0c0cac1c;
P_0c0cac1c: /* original a001, guest PC 0x0c0cac1c */
if(!s->budget--) { s->failed_pc=0x0c0cac1cu; return 0; }
write(ram,r[15]+24,r[3],4);
goto P_0c0cac22;
P_0c0cac1e: /* original 1f36, guest PC 0x0c0cac1e */
if(!s->budget--) { s->failed_pc=0x0c0cac1eu; return 0; }
write(ram,r[15]+24,r[3],4);
goto P_0c0cac20;
P_0c0cac20: /* original 1fa6, guest PC 0x0c0cac20 */
if(!s->budget--) { s->failed_pc=0x0c0cac20u; return 0; }
write(ram,r[15]+24,r[10],4);
goto P_0c0cac22;
P_0c0cac22: /* original 60f2, guest PC 0x0c0cac22 */
if(!s->budget--) { s->failed_pc=0x0c0cac22u; return 0; }
tmp=read(ram,r[15],4);
r[0]=tmp;
goto P_0c0cac24;
P_0c0cac24: /* original c820, guest PC 0x0c0cac24 */
if(!s->budget--) { s->failed_pc=0x0c0cac24u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&32u)==0)!=0);
goto P_0c0cac26;
P_0c0cac26: /* original 8d19, guest PC 0x0c0cac26 */
if(!s->budget--) { s->failed_pc=0x0c0cac26u; return 0; }
cond=r[17]&1u;
vf3_matrix_move(s,8,5);
if(cond) { goto P_0c0cac5c; }
goto P_0c0cac2a;
P_0c0cac28: /* original f85c, guest PC 0x0c0cac28 */
if(!s->budget--) { s->failed_pc=0x0c0cac28u; return 0; }
vf3_matrix_move(s,8,5);
goto P_0c0cac2a;
P_0c0cac2a: /* original e201, guest PC 0x0c0cac2a */
if(!s->budget--) { s->failed_pc=0x0c0cac2au; return 0; }
r[2]=0x00000001u;
goto P_0c0cac2c;
P_0c0cac2c: /* original a017, guest PC 0x0c0cac2c */
if(!s->budget--) { s->failed_pc=0x0c0cac2cu; return 0; }
write(ram,r[15]+36,r[2],4);
goto P_0c0cac5e;
P_0c0cac2e: /* original 1f29, guest PC 0x0c0cac2e */
if(!s->budget--) { s->failed_pc=0x0c0cac2eu; return 0; }
write(ram,r[15]+36,r[2],4);
return vf3_matrix_family(0x0c0cac30u,s,ram);
P_0c0cac5c: /* original 1fa9, guest PC 0x0c0cac5c */
if(!s->budget--) { s->failed_pc=0x0c0cac5cu; return 0; }
write(ram,r[15]+36,r[10],4);
goto P_0c0cac5e;
P_0c0cac5e: /* original f841, guest PC 0x0c0cac5e */
if(!s->budget--) { s->failed_pc=0x0c0cac5eu; return 0; }
fr[8]=vf3_fpu_binary(fr[8],fr[4],r[18],'-');
goto P_0c0cac60;
P_0c0cac60: /* original 60f2, guest PC 0x0c0cac60 */
if(!s->budget--) { s->failed_pc=0x0c0cac60u; return 0; }
tmp=read(ram,r[15],4);
r[0]=tmp;
goto P_0c0cac62;
P_0c0cac62: /* original c802, guest PC 0x0c0cac62 */
if(!s->budget--) { s->failed_pc=0x0c0cac62u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&2u)==0)!=0);
goto P_0c0cac64;
P_0c0cac64: /* original 8f1c, guest PC 0x0c0cac64 */
if(!s->budget--) { s->failed_pc=0x0c0cac64u; return 0; }
cond=r[17]&1u;
fr[5]=vf3_fpu_binary(fr[5],fr[6],r[18],'-');
if(!cond) { goto P_0c0caca0; }
goto P_0c0cac68;
P_0c0cac66: /* original f561, guest PC 0x0c0cac66 */
if(!s->budget--) { s->failed_pc=0x0c0cac66u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[6],r[18],'-');
goto P_0c0cac68;
P_0c0cac68: /* original 53f6, guest PC 0x0c0cac68 */
if(!s->budget--) { s->failed_pc=0x0c0cac68u; return 0; }
r[3]=read(ram,r[15]+24,4);
goto P_0c0cac6a;
P_0c0cac6a: /* original 2338, guest PC 0x0c0cac6a */
if(!s->budget--) { s->failed_pc=0x0c0cac6au; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c0cac6c;
P_0c0cac6c: /* original 8902, guest PC 0x0c0cac6c */
if(!s->budget--) { s->failed_pc=0x0c0cac6cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0cac74; }
goto P_0c0cac6e;
P_0c0cac6e: /* original 933f, guest PC 0x0c0cac6e */
if(!s->budget--) { s->failed_pc=0x0c0cac6eu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0cacf0u,2);
goto P_0c0cac70;
P_0c0cac70: /* original 2358, guest PC 0x0c0cac70 */
if(!s->budget--) { s->failed_pc=0x0c0cac70u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[5])==0)!=0);
goto P_0c0cac72;
P_0c0cac72: /* original 8910, guest PC 0x0c0cac72 */
if(!s->budget--) { s->failed_pc=0x0c0cac72u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0cac96; }
goto P_0c0cac74;
P_0c0cac74: /* original f38d, guest PC 0x0c0cac74 */
if(!s->budget--) { s->failed_pc=0x0c0cac74u; return 0; }
fr[3]=0;
goto P_0c0cac76;
P_0c0cac76: /* original f835, guest PC 0x0c0cac76 */
if(!s->budget--) { s->failed_pc=0x0c0cac76u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[8])>as_float(fr[3]))!=0);
goto P_0c0cac78;
P_0c0cac78: /* original 8908, guest PC 0x0c0cac78 */
if(!s->budget--) { s->failed_pc=0x0c0cac78u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0cac8c; }
goto P_0c0cac7a;
P_0c0cac7a: /* original 2888, guest PC 0x0c0cac7a */
if(!s->budget--) { s->failed_pc=0x0c0cac7au; return 0; }
r[17]=(r[17]&~1u)|(((r[8]&r[8])==0)!=0);
goto P_0c0cac7c;
P_0c0cac7c: /* original 8b06, guest PC 0x0c0cac7c */
if(!s->budget--) { s->failed_pc=0x0c0cac7cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0cac8c; }
goto P_0c0cac7e;
P_0c0cac7e: /* original 53f9, guest PC 0x0c0cac7e */
if(!s->budget--) { s->failed_pc=0x0c0cac7eu; return 0; }
r[3]=read(ram,r[15]+36,4);
goto P_0c0cac80;
P_0c0cac80: /* original 2338, guest PC 0x0c0cac80 */
if(!s->budget--) { s->failed_pc=0x0c0cac80u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c0cac82;
P_0c0cac82: /* original 8902, guest PC 0x0c0cac82 */
if(!s->budget--) { s->failed_pc=0x0c0cac82u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0cac8a; }
goto P_0c0cac84;
P_0c0cac84: /* original 9234, guest PC 0x0c0cac84 */
if(!s->budget--) { s->failed_pc=0x0c0cac84u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0cacf0u,2);
goto P_0c0cac86;
P_0c0cac86: /* original 2258, guest PC 0x0c0cac86 */
if(!s->budget--) { s->failed_pc=0x0c0cac86u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[5])==0)!=0);
goto P_0c0cac88;
P_0c0cac88: /* original 8900, guest PC 0x0c0cac88 */
if(!s->budget--) { s->failed_pc=0x0c0cac88u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0cac8c; }
goto P_0c0cac8a;
P_0c0cac8a: /* original 2c4b, guest PC 0x0c0cac8a */
if(!s->budget--) { s->failed_pc=0x0c0cac8au; return 0; }
r[12]|=r[4];
goto P_0c0cac8c;
P_0c0cac8c: /* original f38d, guest PC 0x0c0cac8c */
if(!s->budget--) { s->failed_pc=0x0c0cac8cu; return 0; }
fr[3]=0;
goto P_0c0cac8e;
P_0c0cac8e: /* original f535, guest PC 0x0c0cac8e */
if(!s->budget--) { s->failed_pc=0x0c0cac8eu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[5])>as_float(fr[3]))!=0);
goto P_0c0cac90;
P_0c0cac90: /* original 890b, guest PC 0x0c0cac90 */
if(!s->budget--) { s->failed_pc=0x0c0cac90u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0cacaa; }
goto P_0c0cac92;
P_0c0cac92: /* original a00a, guest PC 0x0c0cac92 */
if(!s->budget--) { s->failed_pc=0x0c0cac92u; return 0; }
r[9]|=r[4];
goto P_0c0cacaa;
P_0c0cac94: /* original 294b, guest PC 0x0c0cac94 */
if(!s->budget--) { s->failed_pc=0x0c0cac94u; return 0; }
r[9]|=r[4];
goto P_0c0cac96;
P_0c0cac96: /* original f38d, guest PC 0x0c0cac96 */
if(!s->budget--) { s->failed_pc=0x0c0cac96u; return 0; }
fr[3]=0;
goto P_0c0cac98;
P_0c0cac98: /* original f535, guest PC 0x0c0cac98 */
if(!s->budget--) { s->failed_pc=0x0c0cac98u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[5])>as_float(fr[3]))!=0);
goto P_0c0cac9a;
P_0c0cac9a: /* original 8906, guest PC 0x0c0cac9a */
if(!s->budget--) { s->failed_pc=0x0c0cac9au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0cacaa; }
goto P_0c0cac9c;
P_0c0cac9c: /* original a005, guest PC 0x0c0cac9c */
if(!s->budget--) { s->failed_pc=0x0c0cac9cu; return 0; }
r[11]|=r[4];
goto P_0c0cacaa;
P_0c0cac9e: /* original 2b4b, guest PC 0x0c0cac9e */
if(!s->budget--) { s->failed_pc=0x0c0cac9eu; return 0; }
r[11]|=r[4];
goto P_0c0caca0;
P_0c0caca0: /* original 52f4, guest PC 0x0c0caca0 */
if(!s->budget--) { s->failed_pc=0x0c0caca0u; return 0; }
r[2]=read(ram,r[15]+16,4);
goto P_0c0caca2;
P_0c0caca2: /* original d316, guest PC 0x0c0caca2 */
if(!s->budget--) { s->failed_pc=0x0c0caca2u; return 0; }
r[3]=read(ram,0x0c0cacfcu,4);
goto P_0c0caca4;
P_0c0caca4: /* original 2238, guest PC 0x0c0caca4 */
if(!s->budget--) { s->failed_pc=0x0c0caca4u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c0caca6;
P_0c0caca6: /* original 8b00, guest PC 0x0c0caca6 */
if(!s->budget--) { s->failed_pc=0x0c0caca6u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0cacaa; }
goto P_0c0caca8;
P_0c0caca8: /* original 2b4b, guest PC 0x0c0caca8 */
if(!s->budget--) { s->failed_pc=0x0c0caca8u; return 0; }
r[11]|=r[4];
goto P_0c0cacaa;
P_0c0cacaa: /* original 53f2, guest PC 0x0c0cacaa */
if(!s->budget--) { s->failed_pc=0x0c0cacaau; return 0; }
r[3]=read(ram,r[15]+8,4);
goto P_0c0cacac;
P_0c0cacac: /* original 4401, guest PC 0x0c0cacac */
if(!s->budget--) { s->failed_pc=0x0c0cacacu; return 0; }
r[17]=(r[17]&~1u)|((r[4]&1)!=0);
r[4]>>=1;
goto P_0c0cacae;
P_0c0cacae: /* original 7601, guest PC 0x0c0cacae */
if(!s->budget--) { s->failed_pc=0x0c0cacaeu; return 0; }
r[6]+=0x00000001u;
goto P_0c0cacb0;
P_0c0cacb0: /* original 73ff, guest PC 0x0c0cacb0 */
if(!s->budget--) { s->failed_pc=0x0c0cacb0u; return 0; }
r[3]+=0xffffffffu;
goto P_0c0cacb2;
P_0c0cacb2: /* original 2338, guest PC 0x0c0cacb2 */
if(!s->budget--) { s->failed_pc=0x0c0cacb2u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c0cacb4;
P_0c0cacb4: /* original 8f91, guest PC 0x0c0cacb4 */
if(!s->budget--) { s->failed_pc=0x0c0cacb4u; return 0; }
cond=r[17]&1u;
write(ram,r[15]+8,r[3],4);
if(!cond) { goto P_0c0cabda; }
goto P_0c0cacb8;
P_0c0cacb6: /* original 1f32, guest PC 0x0c0cacb6 */
if(!s->budget--) { s->failed_pc=0x0c0cacb6u; return 0; }
write(ram,r[15]+8,r[3],4);
goto P_0c0cacb8;
P_0c0cacb8: /* original e061, guest PC 0x0c0cacb8 */
if(!s->budget--) { s->failed_pc=0x0c0cacb8u; return 0; }
r[0]=0x00000061u;
goto P_0c0cacba;
P_0c0cacba: /* original 00ec, guest PC 0x0c0cacba */
if(!s->budget--) { s->failed_pc=0x0c0cacbau; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0cacbc;
P_0c0cacbc: /* original 600c, guest PC 0x0c0cacbc */
if(!s->budget--) { s->failed_pc=0x0c0cacbcu; return 0; }
r[0]=r[0]&255u;
goto P_0c0cacbe;
P_0c0cacbe: /* original 8809, guest PC 0x0c0cacbe */
if(!s->budget--) { s->failed_pc=0x0c0cacbeu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000009u)!=0);
goto P_0c0cacc0;
P_0c0cacc0: /* original 8905, guest PC 0x0c0cacc0 */
if(!s->budget--) { s->failed_pc=0x0c0cacc0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0cacce; }
goto P_0c0cacc2;
P_0c0cacc2: /* original 9017, guest PC 0x0c0cacc2 */
if(!s->budget--) { s->failed_pc=0x0c0cacc2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0cacf4u,2);
goto P_0c0cacc4;
P_0c0cacc4: /* original 53f8, guest PC 0x0c0cacc4 */
if(!s->budget--) { s->failed_pc=0x0c0cacc4u; return 0; }
r[3]=read(ram,r[15]+32,4);
goto P_0c0cacc6;
P_0c0cacc6: /* original 9214, guest PC 0x0c0cacc6 */
if(!s->budget--) { s->failed_pc=0x0c0cacc6u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0cacf2u,2);
goto P_0c0cacc8;
P_0c0cacc8: /* original 013e, guest PC 0x0c0cacc8 */
if(!s->budget--) { s->failed_pc=0x0c0cacc8u; return 0; }
r[1]=read(ram,r[3]+r[0],4);
goto P_0c0cacca;
P_0c0cacca: /* original 2128, guest PC 0x0c0cacca */
if(!s->budget--) { s->failed_pc=0x0c0caccau; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[2])==0)!=0);
goto P_0c0caccc;
P_0c0caccc: /* original 8b08, guest PC 0x0c0caccc */
if(!s->budget--) { s->failed_pc=0x0c0cacccu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0cace0; }
goto P_0c0cacce;
P_0c0cacce: /* original 9012, guest PC 0x0c0cacce */
if(!s->budget--) { s->failed_pc=0x0c0cacceu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0cacf6u,2);
goto P_0c0cacd0;
P_0c0cacd0: /* original 64f3, guest PC 0x0c0cacd0 */
if(!s->budget--) { s->failed_pc=0x0c0cacd0u; return 0; }
r[4]=r[15];
goto P_0c0cacd2;
P_0c0cacd2: /* original d30b, guest PC 0x0c0cacd2 */
if(!s->budget--) { s->failed_pc=0x0c0cacd2u; return 0; }
r[3]=read(ram,0x0c0cad00u,4);
goto P_0c0cacd4;
P_0c0cacd4: /* original 7404, guest PC 0x0c0cacd4 */
if(!s->budget--) { s->failed_pc=0x0c0cacd4u; return 0; }
r[4]+=0x00000004u;
goto P_0c0cacd6;
P_0c0cacd6: /* original 430b, guest PC 0x0c0cacd6 */
if(!s->budget--) { s->failed_pc=0x0c0cacd6u; return 0; }
target=r[3];
r[16]=0x0c0cacdau;
vf3_matrix_load(s,ram,4,r[14]+r[0]);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0cacdau) { target=s->pc; goto dispatch; }
goto P_0c0cacda;
P_0c0cacd8: /* original f4e6, guest PC 0x0c0cacd8 */
if(!s->budget--) { s->failed_pc=0x0c0cacd8u; return 0; }
vf3_matrix_load(s,ram,4,r[14]+r[0]);
goto P_0c0cacda;
P_0c0cacda: /* original f38d, guest PC 0x0c0cacda */
if(!s->budget--) { s->failed_pc=0x0c0cacdau; return 0; }
fr[3]=0;
goto P_0c0cacdc;
P_0c0cacdc: /* original f035, guest PC 0x0c0cacdc */
if(!s->budget--) { s->failed_pc=0x0c0cacdcu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[0])>as_float(fr[3]))!=0);
goto P_0c0cacde;
P_0c0cacde: /* original 8b05, guest PC 0x0c0cacde */
if(!s->budget--) { s->failed_pc=0x0c0cacdeu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0cacec; }
goto P_0c0cace0;
P_0c0cace0: /* original 2bb8, guest PC 0x0c0cace0 */
if(!s->budget--) { s->failed_pc=0x0c0cace0u; return 0; }
r[17]=(r[17]&~1u)|(((r[11]&r[11])==0)!=0);
goto P_0c0cace2;
P_0c0cace2: /* original 8b0f, guest PC 0x0c0cace2 */
if(!s->budget--) { s->failed_pc=0x0c0cace2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0cad04; }
goto P_0c0cace4;
P_0c0cace4: /* original 9008, guest PC 0x0c0cace4 */
if(!s->budget--) { s->failed_pc=0x0c0cace4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0cacf8u,2);
goto P_0c0cace6;
P_0c0cace6: /* original 00ee, guest PC 0x0c0cace6 */
if(!s->budget--) { s->failed_pc=0x0c0cace6u; return 0; }
r[0]=read(ram,r[14]+r[0],4);
goto P_0c0cace8;
P_0c0cace8: /* original c804, guest PC 0x0c0cace8 */
if(!s->budget--) { s->failed_pc=0x0c0cace8u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&4u)==0)!=0);
goto P_0c0cacea;
P_0c0cacea: /* original 8b0b, guest PC 0x0c0cacea */
if(!s->budget--) { s->failed_pc=0x0c0caceau; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0cad04; }
goto P_0c0cacec;
P_0c0cacec: /* original a01c, guest PC 0x0c0cacec */
if(!s->budget--) { s->failed_pc=0x0c0cacecu; return 0; }
r[12]=r[10];
goto P_0c0cad28;
P_0c0cacee: /* original 6ca3, guest PC 0x0c0cacee */
if(!s->budget--) { s->failed_pc=0x0c0caceeu; return 0; }
r[12]=r[10];
return vf3_matrix_family(0x0c0cacf0u,s,ram);
P_0c0cad04: /* original 905e, guest PC 0x0c0cad04 */
if(!s->budget--) { s->failed_pc=0x0c0cad04u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0cadc4u,2);
goto P_0c0cad06;
P_0c0cad06: /* original d332, guest PC 0x0c0cad06 */
if(!s->budget--) { s->failed_pc=0x0c0cad06u; return 0; }
r[3]=read(ram,0x0c0cadd0u,4);
goto P_0c0cad08;
P_0c0cad08: /* original 02ee, guest PC 0x0c0cad08 */
if(!s->budget--) { s->failed_pc=0x0c0cad08u; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c0cad0a;
P_0c0cad0a: /* original 2238, guest PC 0x0c0cad0a */
if(!s->budget--) { s->failed_pc=0x0c0cad0au; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c0cad0c;
P_0c0cad0c: /* original 8908, guest PC 0x0c0cad0c */
if(!s->budget--) { s->failed_pc=0x0c0cad0cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0cad20; }
goto P_0c0cad0e;
P_0c0cad0e: /* original 905a, guest PC 0x0c0cad0e */
if(!s->budget--) { s->failed_pc=0x0c0cad0eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0cadc6u,2);
goto P_0c0cad10;
P_0c0cad10: /* original 01ec, guest PC 0x0c0cad10 */
if(!s->budget--) { s->failed_pc=0x0c0cad10u; return 0; }
r[1]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0cad12;
P_0c0cad12: /* original d030, guest PC 0x0c0cad12 */
if(!s->budget--) { s->failed_pc=0x0c0cad12u; return 0; }
r[0]=read(ram,0x0c0cadd4u,4);
goto P_0c0cad14;
P_0c0cad14: /* original 611c, guest PC 0x0c0cad14 */
if(!s->budget--) { s->failed_pc=0x0c0cad14u; return 0; }
r[1]=r[1]&255u;
goto P_0c0cad16;
P_0c0cad16: /* original 4108, guest PC 0x0c0cad16 */
if(!s->budget--) { s->failed_pc=0x0c0cad16u; return 0; }
r[1]<<=2;
goto P_0c0cad18;
P_0c0cad18: /* original 031e, guest PC 0x0c0cad18 */
if(!s->budget--) { s->failed_pc=0x0c0cad18u; return 0; }
r[3]=read(ram,r[1]+r[0],4);
goto P_0c0cad1a;
P_0c0cad1a: /* original 6237, guest PC 0x0c0cad1a */
if(!s->budget--) { s->failed_pc=0x0c0cad1au; return 0; }
r[2]=~r[3];
goto P_0c0cad1c;
P_0c0cad1c: /* original 2f32, guest PC 0x0c0cad1c */
if(!s->budget--) { s->failed_pc=0x0c0cad1cu; return 0; }
write(ram,r[15],r[3],4);
goto P_0c0cad1e;
P_0c0cad1e: /* original 2c29, guest PC 0x0c0cad1e */
if(!s->budget--) { s->failed_pc=0x0c0cad1eu; return 0; }
r[12]&=r[2];
goto P_0c0cad20;
P_0c0cad20: /* original 6397, guest PC 0x0c0cad20 */
if(!s->budget--) { s->failed_pc=0x0c0cad20u; return 0; }
r[3]=~r[9];
goto P_0c0cad22;
P_0c0cad22: /* original 62b7, guest PC 0x0c0cad22 */
if(!s->budget--) { s->failed_pc=0x0c0cad22u; return 0; }
r[2]=~r[11];
goto P_0c0cad24;
P_0c0cad24: /* original 2c39, guest PC 0x0c0cad24 */
if(!s->budget--) { s->failed_pc=0x0c0cad24u; return 0; }
r[12]&=r[3];
goto P_0c0cad26;
P_0c0cad26: /* original 2c29, guest PC 0x0c0cad26 */
if(!s->budget--) { s->failed_pc=0x0c0cad26u; return 0; }
r[12]&=r[2];
goto P_0c0cad28;
P_0c0cad28: /* original 904e, guest PC 0x0c0cad28 */
if(!s->budget--) { s->failed_pc=0x0c0cad28u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0cadc8u,2);
goto P_0c0cad2a;
P_0c0cad2a: /* original d82b, guest PC 0x0c0cad2a */
if(!s->budget--) { s->failed_pc=0x0c0cad2au; return 0; }
r[8]=read(ram,0x0c0cadd8u,4);
goto P_0c0cad2c;
P_0c0cad2c: /* original 0ec6, guest PC 0x0c0cad2c */
if(!s->budget--) { s->failed_pc=0x0c0cad2cu; return 0; }
write(ram,r[14]+r[0],r[12],4);
goto P_0c0cad2e;
P_0c0cad2e: /* original 904c, guest PC 0x0c0cad2e */
if(!s->budget--) { s->failed_pc=0x0c0cad2eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0cadcau,2);
goto P_0c0cad30;
P_0c0cad30: /* original 0e96, guest PC 0x0c0cad30 */
if(!s->budget--) { s->failed_pc=0x0c0cad30u; return 0; }
write(ram,r[14]+r[0],r[9],4);
goto P_0c0cad32;
P_0c0cad32: /* original 70f8, guest PC 0x0c0cad32 */
if(!s->budget--) { s->failed_pc=0x0c0cad32u; return 0; }
r[0]+=0xfffffff8u;
goto P_0c0cad34;
P_0c0cad34: /* original 0eb6, guest PC 0x0c0cad34 */
if(!s->budget--) { s->failed_pc=0x0c0cad34u; return 0; }
write(ram,r[14]+r[0],r[11],4);
goto P_0c0cad36;
P_0c0cad36: /* original 2fc2, guest PC 0x0c0cad36 */
if(!s->budget--) { s->failed_pc=0x0c0cad36u; return 0; }
write(ram,r[15],r[12],4);
goto P_0c0cad38;
P_0c0cad38: /* original 1fa2, guest PC 0x0c0cad38 */
if(!s->budget--) { s->failed_pc=0x0c0cad38u; return 0; }
write(ram,r[15]+8,r[10],4);
goto P_0c0cad3a;
P_0c0cad3a: /* original dc28, guest PC 0x0c0cad3a */
if(!s->budget--) { s->failed_pc=0x0c0cad3au; return 0; }
r[12]=read(ram,0x0c0caddcu,4);
goto P_0c0cad3c;
P_0c0cad3c: /* original 4c0b, guest PC 0x0c0cad3c */
if(!s->budget--) { s->failed_pc=0x0c0cad3cu; return 0; }
target=r[12];
r[16]=0x0c0cad40u;
tmp=read(ram,r[15],4);
r[4]=tmp;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0cad40u) { target=s->pc; goto dispatch; }
goto P_0c0cad40;
P_0c0cad3e: /* original 64f2, guest PC 0x0c0cad3e */
if(!s->budget--) { s->failed_pc=0x0c0cad3eu; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c0cad40;
P_0c0cad40: /* original 8820, guest PC 0x0c0cad40 */
if(!s->budget--) { s->failed_pc=0x0c0cad40u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000020u)!=0);
goto P_0c0cad42;
P_0c0cad42: /* original 8d10, guest PC 0x0c0cad42 */
if(!s->budget--) { s->failed_pc=0x0c0cad42u; return 0; }
cond=r[17]&1u;
r[4]=r[0];
if(cond) { goto P_0c0cad66; }
goto P_0c0cad46;
P_0c0cad44: /* original 6403, guest PC 0x0c0cad44 */
if(!s->budget--) { s->failed_pc=0x0c0cad44u; return 0; }
r[4]=r[0];
goto P_0c0cad46;
P_0c0cad46: /* original 6043, guest PC 0x0c0cad46 */
if(!s->budget--) { s->failed_pc=0x0c0cad46u; return 0; }
r[0]=r[4];
goto P_0c0cad48;
P_0c0cad48: /* original 058c, guest PC 0x0c0cad48 */
if(!s->budget--) { s->failed_pc=0x0c0cad48u; return 0; }
r[5]=(uint32_t)(int32_t)(int8_t)read(ram,r[8]+r[0],1);
goto P_0c0cad4a;
P_0c0cad4a: /* original 52f2, guest PC 0x0c0cad4a */
if(!s->budget--) { s->failed_pc=0x0c0cad4au; return 0; }
r[2]=read(ram,r[15]+8,4);
goto P_0c0cad4c;
P_0c0cad4c: /* original 635b, guest PC 0x0c0cad4c */
if(!s->budget--) { s->failed_pc=0x0c0cad4cu; return 0; }
r[3]=0u-r[5];
goto P_0c0cad4e;
P_0c0cad4e: /* original 65d3, guest PC 0x0c0cad4e */
if(!s->budget--) { s->failed_pc=0x0c0cad4eu; return 0; }
r[5]=r[13];
goto P_0c0cad50;
P_0c0cad50: /* original 453d, guest PC 0x0c0cad50 */
if(!s->budget--) { s->failed_pc=0x0c0cad50u; return 0; }
r[5]=(r[3]&0x80000000u)?((r[3]&31u)?r[5]>>((-r[3])&31u):0):r[5]<<(r[3]&31u);
goto P_0c0cad52;
P_0c0cad52: /* original 634b, guest PC 0x0c0cad52 */
if(!s->budget--) { s->failed_pc=0x0c0cad52u; return 0; }
r[3]=0u-r[4];
goto P_0c0cad54;
P_0c0cad54: /* original 64d3, guest PC 0x0c0cad54 */
if(!s->budget--) { s->failed_pc=0x0c0cad54u; return 0; }
r[4]=r[13];
goto P_0c0cad56;
P_0c0cad56: /* original 443d, guest PC 0x0c0cad56 */
if(!s->budget--) { s->failed_pc=0x0c0cad56u; return 0; }
r[4]=(r[3]&0x80000000u)?((r[3]&31u)?r[4]>>((-r[3])&31u):0):r[4]<<(r[3]&31u);
goto P_0c0cad58;
P_0c0cad58: /* original 6447, guest PC 0x0c0cad58 */
if(!s->budget--) { s->failed_pc=0x0c0cad58u; return 0; }
r[4]=~r[4];
goto P_0c0cad5a;
P_0c0cad5a: /* original 252b, guest PC 0x0c0cad5a */
if(!s->budget--) { s->failed_pc=0x0c0cad5au; return 0; }
r[5]|=r[2];
goto P_0c0cad5c;
P_0c0cad5c: /* original 1f52, guest PC 0x0c0cad5c */
if(!s->budget--) { s->failed_pc=0x0c0cad5cu; return 0; }
write(ram,r[15]+8,r[5],4);
goto P_0c0cad5e;
P_0c0cad5e: /* original 63f2, guest PC 0x0c0cad5e */
if(!s->budget--) { s->failed_pc=0x0c0cad5eu; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c0cad60;
P_0c0cad60: /* original 2439, guest PC 0x0c0cad60 */
if(!s->budget--) { s->failed_pc=0x0c0cad60u; return 0; }
r[4]&=r[3];
goto P_0c0cad62;
P_0c0cad62: /* original afeb, guest PC 0x0c0cad62 */
if(!s->budget--) { s->failed_pc=0x0c0cad62u; return 0; }
write(ram,r[15],r[4],4);
goto P_0c0cad3c;
P_0c0cad64: /* original 2f42, guest PC 0x0c0cad64 */
if(!s->budget--) { s->failed_pc=0x0c0cad64u; return 0; }
write(ram,r[15],r[4],4);
goto P_0c0cad66;
P_0c0cad66: /* original 9031, guest PC 0x0c0cad66 */
if(!s->budget--) { s->failed_pc=0x0c0cad66u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0cadccu,2);
goto P_0c0cad68;
P_0c0cad68: /* original 53f2, guest PC 0x0c0cad68 */
if(!s->budget--) { s->failed_pc=0x0c0cad68u; return 0; }
r[3]=read(ram,r[15]+8,4);
goto P_0c0cad6a;
P_0c0cad6a: /* original 0e36, guest PC 0x0c0cad6a */
if(!s->budget--) { s->failed_pc=0x0c0cad6au; return 0; }
write(ram,r[14]+r[0],r[3],4);
goto P_0c0cad6c;
P_0c0cad6c: /* original 2f92, guest PC 0x0c0cad6c */
if(!s->budget--) { s->failed_pc=0x0c0cad6cu; return 0; }
write(ram,r[15],r[9],4);
goto P_0c0cad6e;
P_0c0cad6e: /* original 69a3, guest PC 0x0c0cad6e */
if(!s->budget--) { s->failed_pc=0x0c0cad6eu; return 0; }
r[9]=r[10];
goto P_0c0cad70;
P_0c0cad70: /* original 4c0b, guest PC 0x0c0cad70 */
if(!s->budget--) { s->failed_pc=0x0c0cad70u; return 0; }
target=r[12];
r[16]=0x0c0cad74u;
tmp=read(ram,r[15],4);
r[4]=tmp;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0cad74u) { target=s->pc; goto dispatch; }
goto P_0c0cad74;
P_0c0cad72: /* original 64f2, guest PC 0x0c0cad72 */
if(!s->budget--) { s->failed_pc=0x0c0cad72u; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c0cad74;
P_0c0cad74: /* original 8820, guest PC 0x0c0cad74 */
if(!s->budget--) { s->failed_pc=0x0c0cad74u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000020u)!=0);
goto P_0c0cad76;
P_0c0cad76: /* original 8d0e, guest PC 0x0c0cad76 */
if(!s->budget--) { s->failed_pc=0x0c0cad76u; return 0; }
cond=r[17]&1u;
r[4]=r[0];
if(cond) { goto P_0c0cad96; }
goto P_0c0cad7a;
P_0c0cad78: /* original 6403, guest PC 0x0c0cad78 */
if(!s->budget--) { s->failed_pc=0x0c0cad78u; return 0; }
r[4]=r[0];
goto P_0c0cad7a;
P_0c0cad7a: /* original 6043, guest PC 0x0c0cad7a */
if(!s->budget--) { s->failed_pc=0x0c0cad7au; return 0; }
r[0]=r[4];
goto P_0c0cad7c;
P_0c0cad7c: /* original 058c, guest PC 0x0c0cad7c */
if(!s->budget--) { s->failed_pc=0x0c0cad7cu; return 0; }
r[5]=(uint32_t)(int32_t)(int8_t)read(ram,r[8]+r[0],1);
goto P_0c0cad7e;
P_0c0cad7e: /* original 62f2, guest PC 0x0c0cad7e */
if(!s->budget--) { s->failed_pc=0x0c0cad7eu; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c0cad80;
P_0c0cad80: /* original 635b, guest PC 0x0c0cad80 */
if(!s->budget--) { s->failed_pc=0x0c0cad80u; return 0; }
r[3]=0u-r[5];
goto P_0c0cad82;
P_0c0cad82: /* original 65d3, guest PC 0x0c0cad82 */
if(!s->budget--) { s->failed_pc=0x0c0cad82u; return 0; }
r[5]=r[13];
goto P_0c0cad84;
P_0c0cad84: /* original 453d, guest PC 0x0c0cad84 */
if(!s->budget--) { s->failed_pc=0x0c0cad84u; return 0; }
r[5]=(r[3]&0x80000000u)?((r[3]&31u)?r[5]>>((-r[3])&31u):0):r[5]<<(r[3]&31u);
goto P_0c0cad86;
P_0c0cad86: /* original 634b, guest PC 0x0c0cad86 */
if(!s->budget--) { s->failed_pc=0x0c0cad86u; return 0; }
r[3]=0u-r[4];
goto P_0c0cad88;
P_0c0cad88: /* original 64d3, guest PC 0x0c0cad88 */
if(!s->budget--) { s->failed_pc=0x0c0cad88u; return 0; }
r[4]=r[13];
goto P_0c0cad8a;
P_0c0cad8a: /* original 443d, guest PC 0x0c0cad8a */
if(!s->budget--) { s->failed_pc=0x0c0cad8au; return 0; }
r[4]=(r[3]&0x80000000u)?((r[3]&31u)?r[4]>>((-r[3])&31u):0):r[4]<<(r[3]&31u);
goto P_0c0cad8c;
P_0c0cad8c: /* original 6447, guest PC 0x0c0cad8c */
if(!s->budget--) { s->failed_pc=0x0c0cad8cu; return 0; }
r[4]=~r[4];
goto P_0c0cad8e;
P_0c0cad8e: /* original 2429, guest PC 0x0c0cad8e */
if(!s->budget--) { s->failed_pc=0x0c0cad8eu; return 0; }
r[4]&=r[2];
goto P_0c0cad90;
P_0c0cad90: /* original 295b, guest PC 0x0c0cad90 */
if(!s->budget--) { s->failed_pc=0x0c0cad90u; return 0; }
r[9]|=r[5];
goto P_0c0cad92;
P_0c0cad92: /* original afed, guest PC 0x0c0cad92 */
if(!s->budget--) { s->failed_pc=0x0c0cad92u; return 0; }
write(ram,r[15],r[4],4);
goto P_0c0cad70;
P_0c0cad94: /* original 2f42, guest PC 0x0c0cad94 */
if(!s->budget--) { s->failed_pc=0x0c0cad94u; return 0; }
write(ram,r[15],r[4],4);
goto P_0c0cad96;
P_0c0cad96: /* original 901a, guest PC 0x0c0cad96 */
if(!s->budget--) { s->failed_pc=0x0c0cad96u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0cadceu,2);
goto P_0c0cad98;
P_0c0cad98: /* original 0e96, guest PC 0x0c0cad98 */
if(!s->budget--) { s->failed_pc=0x0c0cad98u; return 0; }
write(ram,r[14]+r[0],r[9],4);
goto P_0c0cad9a;
P_0c0cad9a: /* original 2fb2, guest PC 0x0c0cad9a */
if(!s->budget--) { s->failed_pc=0x0c0cad9au; return 0; }
write(ram,r[15],r[11],4);
goto P_0c0cad9c;
P_0c0cad9c: /* original 6ba3, guest PC 0x0c0cad9c */
if(!s->budget--) { s->failed_pc=0x0c0cad9cu; return 0; }
r[11]=r[10];
goto P_0c0cad9e;
P_0c0cad9e: /* original 4c0b, guest PC 0x0c0cad9e */
if(!s->budget--) { s->failed_pc=0x0c0cad9eu; return 0; }
target=r[12];
r[16]=0x0c0cada2u;
tmp=read(ram,r[15],4);
r[4]=tmp;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0cada2u) { target=s->pc; goto dispatch; }
goto P_0c0cada2;
P_0c0cada0: /* original 64f2, guest PC 0x0c0cada0 */
if(!s->budget--) { s->failed_pc=0x0c0cada0u; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c0cada2;
P_0c0cada2: /* original 8820, guest PC 0x0c0cada2 */
if(!s->budget--) { s->failed_pc=0x0c0cada2u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000020u)!=0);
goto P_0c0cada4;
P_0c0cada4: /* original 8d1c, guest PC 0x0c0cada4 */
if(!s->budget--) { s->failed_pc=0x0c0cada4u; return 0; }
cond=r[17]&1u;
r[4]=r[0];
if(cond) { goto P_0c0cade0; }
goto P_0c0cada8;
P_0c0cada6: /* original 6403, guest PC 0x0c0cada6 */
if(!s->budget--) { s->failed_pc=0x0c0cada6u; return 0; }
r[4]=r[0];
goto P_0c0cada8;
P_0c0cada8: /* original 6043, guest PC 0x0c0cada8 */
if(!s->budget--) { s->failed_pc=0x0c0cada8u; return 0; }
r[0]=r[4];
goto P_0c0cadaa;
P_0c0cadaa: /* original 058c, guest PC 0x0c0cadaa */
if(!s->budget--) { s->failed_pc=0x0c0cadaau; return 0; }
r[5]=(uint32_t)(int32_t)(int8_t)read(ram,r[8]+r[0],1);
goto P_0c0cadac;
P_0c0cadac: /* original 62f2, guest PC 0x0c0cadac */
if(!s->budget--) { s->failed_pc=0x0c0cadacu; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c0cadae;
P_0c0cadae: /* original 635b, guest PC 0x0c0cadae */
if(!s->budget--) { s->failed_pc=0x0c0cadaeu; return 0; }
r[3]=0u-r[5];
goto P_0c0cadb0;
P_0c0cadb0: /* original 65d3, guest PC 0x0c0cadb0 */
if(!s->budget--) { s->failed_pc=0x0c0cadb0u; return 0; }
r[5]=r[13];
goto P_0c0cadb2;
P_0c0cadb2: /* original 453d, guest PC 0x0c0cadb2 */
if(!s->budget--) { s->failed_pc=0x0c0cadb2u; return 0; }
r[5]=(r[3]&0x80000000u)?((r[3]&31u)?r[5]>>((-r[3])&31u):0):r[5]<<(r[3]&31u);
goto P_0c0cadb4;
P_0c0cadb4: /* original 634b, guest PC 0x0c0cadb4 */
if(!s->budget--) { s->failed_pc=0x0c0cadb4u; return 0; }
r[3]=0u-r[4];
goto P_0c0cadb6;
P_0c0cadb6: /* original 64d3, guest PC 0x0c0cadb6 */
if(!s->budget--) { s->failed_pc=0x0c0cadb6u; return 0; }
r[4]=r[13];
goto P_0c0cadb8;
P_0c0cadb8: /* original 443d, guest PC 0x0c0cadb8 */
if(!s->budget--) { s->failed_pc=0x0c0cadb8u; return 0; }
r[4]=(r[3]&0x80000000u)?((r[3]&31u)?r[4]>>((-r[3])&31u):0):r[4]<<(r[3]&31u);
goto P_0c0cadba;
P_0c0cadba: /* original 6447, guest PC 0x0c0cadba */
if(!s->budget--) { s->failed_pc=0x0c0cadbau; return 0; }
r[4]=~r[4];
goto P_0c0cadbc;
P_0c0cadbc: /* original 2429, guest PC 0x0c0cadbc */
if(!s->budget--) { s->failed_pc=0x0c0cadbcu; return 0; }
r[4]&=r[2];
goto P_0c0cadbe;
P_0c0cadbe: /* original 2b5b, guest PC 0x0c0cadbe */
if(!s->budget--) { s->failed_pc=0x0c0cadbeu; return 0; }
r[11]|=r[5];
goto P_0c0cadc0;
P_0c0cadc0: /* original afed, guest PC 0x0c0cadc0 */
if(!s->budget--) { s->failed_pc=0x0c0cadc0u; return 0; }
write(ram,r[15],r[4],4);
goto P_0c0cad9e;
P_0c0cadc2: /* original 2f42, guest PC 0x0c0cadc2 */
if(!s->budget--) { s->failed_pc=0x0c0cadc2u; return 0; }
write(ram,r[15],r[4],4);
return vf3_matrix_family(0x0c0cadc4u,s,ram);
P_0c0cade0: /* original 9088, guest PC 0x0c0cade0 */
if(!s->budget--) { s->failed_pc=0x0c0cade0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0caef4u,2);
goto P_0c0cade2;
P_0c0cade2: /* original 0eb6, guest PC 0x0c0cade2 */
if(!s->budget--) { s->failed_pc=0x0c0cade2u; return 0; }
write(ram,r[14]+r[0],r[11],4);
goto P_0c0cade4;
P_0c0cade4: /* original 52f4, guest PC 0x0c0cade4 */
if(!s->budget--) { s->failed_pc=0x0c0cade4u; return 0; }
r[2]=read(ram,r[15]+16,4);
goto P_0c0cade6;
P_0c0cade6: /* original 9386, guest PC 0x0c0cade6 */
if(!s->budget--) { s->failed_pc=0x0c0cade6u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0caef6u,2);
goto P_0c0cade8;
P_0c0cade8: /* original fe8d, guest PC 0x0c0cade8 */
if(!s->budget--) { s->failed_pc=0x0c0cade8u; return 0; }
fr[14]=0;
goto P_0c0cadea;
P_0c0cadea: /* original 2238, guest PC 0x0c0cadea */
if(!s->budget--) { s->failed_pc=0x0c0cadeau; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c0cadec;
P_0c0cadec: /* original ffec, guest PC 0x0c0cadec */
if(!s->budget--) { s->failed_pc=0x0c0cadecu; return 0; }
vf3_matrix_move(s,15,14);
goto P_0c0cadee;
P_0c0cadee: /* original 8f02, guest PC 0x0c0cadee */
if(!s->budget--) { s->failed_pc=0x0c0cadeeu; return 0; }
cond=r[17]&1u;
vf3_matrix_move(s,13,14);
if(!cond) { goto P_0c0cadf6; }
goto P_0c0cadf2;
P_0c0cadf0: /* original fdec, guest PC 0x0c0cadf0 */
if(!s->budget--) { s->failed_pc=0x0c0cadf0u; return 0; }
vf3_matrix_move(s,13,14);
goto P_0c0cadf2;
P_0c0cadf2: /* original a0a1, guest PC 0x0c0cadf2 */
if(!s->budget--) { s->failed_pc=0x0c0cadf2u; return 0; }
goto P_0c0caf38;
P_0c0cadf4: /* original 0009, guest PC 0x0c0cadf4 */
if(!s->budget--) { s->failed_pc=0x0c0cadf4u; return 0; }
goto P_0c0cadf6;
P_0c0cadf6: /* original 50f7, guest PC 0x0c0cadf6 */
if(!s->budget--) { s->failed_pc=0x0c0cadf6u; return 0; }
r[0]=read(ram,r[15]+28,4);
goto P_0c0cadf8;
P_0c0cadf8: /* original e11c, guest PC 0x0c0cadf8 */
if(!s->budget--) { s->failed_pc=0x0c0cadf8u; return 0; }
r[1]=0x0000001cu;
goto P_0c0cadfa;
P_0c0cadfa: /* original 001c, guest PC 0x0c0cadfa */
if(!s->budget--) { s->failed_pc=0x0c0cadfau; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[1]+r[0],1);
goto P_0c0cadfc;
P_0c0cadfc: /* original 600c, guest PC 0x0c0cadfc */
if(!s->budget--) { s->failed_pc=0x0c0cadfcu; return 0; }
r[0]=r[0]&255u;
goto P_0c0cadfe;
P_0c0cadfe: /* original c90f, guest PC 0x0c0cadfe */
if(!s->budget--) { s->failed_pc=0x0c0cadfeu; return 0; }
r[0]&=15u;
goto P_0c0cae00;
P_0c0cae00: /* original 8801, guest PC 0x0c0cae00 */
if(!s->budget--) { s->failed_pc=0x0c0cae00u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c0cae02;
P_0c0cae02: /* original 8b26, guest PC 0x0c0cae02 */
if(!s->budget--) { s->failed_pc=0x0c0cae02u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0cae52; }
goto P_0c0cae04;
P_0c0cae04: /* original 63f3, guest PC 0x0c0cae04 */
if(!s->budget--) { s->failed_pc=0x0c0cae04u; return 0; }
r[3]=r[15];
goto P_0c0cae06;
P_0c0cae06: /* original 2f36, guest PC 0x0c0cae06 */
if(!s->budget--) { s->failed_pc=0x0c0cae06u; return 0; }
r[15]-=4; write(ram,r[15],r[3],4);
goto P_0c0cae08;
P_0c0cae08: /* original 65f3, guest PC 0x0c0cae08 */
if(!s->budget--) { s->failed_pc=0x0c0cae08u; return 0; }
r[5]=r[15];
goto P_0c0cae0a;
P_0c0cae0a: /* original d23f, guest PC 0x0c0cae0a */
if(!s->budget--) { s->failed_pc=0x0c0cae0au; return 0; }
r[2]=read(ram,0x0c0caf08u,4);
goto P_0c0cae0c;
P_0c0cae0c: /* original 66f3, guest PC 0x0c0cae0c */
if(!s->budget--) { s->failed_pc=0x0c0cae0cu; return 0; }
r[6]=r[15];
goto P_0c0cae0e;
P_0c0cae0e: /* original 67f3, guest PC 0x0c0cae0e */
if(!s->budget--) { s->failed_pc=0x0c0cae0eu; return 0; }
r[7]=r[15];
goto P_0c0cae10;
P_0c0cae10: /* original 7508, guest PC 0x0c0cae10 */
if(!s->budget--) { s->failed_pc=0x0c0cae10u; return 0; }
r[5]+=0x00000008u;
goto P_0c0cae12;
P_0c0cae12: /* original 7610, guest PC 0x0c0cae12 */
if(!s->budget--) { s->failed_pc=0x0c0cae12u; return 0; }
r[6]+=0x00000010u;
goto P_0c0cae14;
P_0c0cae14: /* original 7718, guest PC 0x0c0cae14 */
if(!s->budget--) { s->failed_pc=0x0c0cae14u; return 0; }
r[7]+=0x00000018u;
goto P_0c0cae16;
P_0c0cae16: /* original 420b, guest PC 0x0c0cae16 */
if(!s->budget--) { s->failed_pc=0x0c0cae16u; return 0; }
target=r[2];
r[16]=0x0c0cae1au;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0cae1au) { target=s->pc; goto dispatch; }
goto P_0c0cae1a;
P_0c0cae18: /* original 64e3, guest PC 0x0c0cae18 */
if(!s->budget--) { s->failed_pc=0x0c0cae18u; return 0; }
r[4]=r[14];
goto P_0c0cae1a;
P_0c0cae1a: /* original 906d, guest PC 0x0c0cae1a */
if(!s->budget--) { s->failed_pc=0x0c0cae1au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0caef8u,2);
goto P_0c0cae1c;
P_0c0cae1c: /* original 7f04, guest PC 0x0c0cae1c */
if(!s->budget--) { s->failed_pc=0x0c0cae1cu; return 0; }
r[15]+=0x00000004u;
goto P_0c0cae1e;
P_0c0cae1e: /* original f3e6, guest PC 0x0c0cae1e */
if(!s->budget--) { s->failed_pc=0x0c0cae1eu; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c0cae20;
P_0c0cae20: /* original e014, guest PC 0x0c0cae20 */
if(!s->budget--) { s->failed_pc=0x0c0cae20u; return 0; }
r[0]=0x00000014u;
goto P_0c0cae22;
P_0c0cae22: /* original ff37, guest PC 0x0c0cae22 */
if(!s->budget--) { s->failed_pc=0x0c0cae22u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0cae24;
P_0c0cae24: /* original 9069, guest PC 0x0c0cae24 */
if(!s->budget--) { s->failed_pc=0x0c0cae24u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0caefau,2);
goto P_0c0cae26;
P_0c0cae26: /* original f4e6, guest PC 0x0c0cae26 */
if(!s->budget--) { s->failed_pc=0x0c0cae26u; return 0; }
vf3_matrix_load(s,ram,4,r[14]+r[0]);
goto P_0c0cae28;
P_0c0cae28: /* original e004, guest PC 0x0c0cae28 */
if(!s->budget--) { s->failed_pc=0x0c0cae28u; return 0; }
r[0]=0x00000004u;
goto P_0c0cae2a;
P_0c0cae2a: /* original f2f6, guest PC 0x0c0cae2a */
if(!s->budget--) { s->failed_pc=0x0c0cae2au; return 0; }
vf3_matrix_load(s,ram,2,r[15]+r[0]);
goto P_0c0cae2c;
P_0c0cae2c: /* original e004, guest PC 0x0c0cae2c */
if(!s->budget--) { s->failed_pc=0x0c0cae2cu; return 0; }
r[0]=0x00000004u;
goto P_0c0cae2e;
P_0c0cae2e: /* original f44d, guest PC 0x0c0cae2e */
if(!s->budget--) { s->failed_pc=0x0c0cae2eu; return 0; }
fr[4]^=0x80000000u;
goto P_0c0cae30;
P_0c0cae30: /* original f231, guest PC 0x0c0cae30 */
if(!s->budget--) { s->failed_pc=0x0c0cae30u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'-');
goto P_0c0cae32;
P_0c0cae32: /* original ff27, guest PC 0x0c0cae32 */
if(!s->budget--) { s->failed_pc=0x0c0cae32u; return 0; }
vf3_matrix_store(s,ram,2,r[15]+r[0]);
goto P_0c0cae34;
P_0c0cae34: /* original e00c, guest PC 0x0c0cae34 */
if(!s->budget--) { s->failed_pc=0x0c0cae34u; return 0; }
r[0]=0x0000000cu;
goto P_0c0cae36;
P_0c0cae36: /* original f1f6, guest PC 0x0c0cae36 */
if(!s->budget--) { s->failed_pc=0x0c0cae36u; return 0; }
vf3_matrix_load(s,ram,1,r[15]+r[0]);
goto P_0c0cae38;
P_0c0cae38: /* original f222, guest PC 0x0c0cae38 */
if(!s->budget--) { s->failed_pc=0x0c0cae38u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[2],r[18],'*');
goto P_0c0cae3a;
P_0c0cae3a: /* original e00c, guest PC 0x0c0cae3a */
if(!s->budget--) { s->failed_pc=0x0c0cae3au; return 0; }
r[0]=0x0000000cu;
goto P_0c0cae3c;
P_0c0cae3c: /* original f141, guest PC 0x0c0cae3c */
if(!s->budget--) { s->failed_pc=0x0c0cae3cu; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'-');
goto P_0c0cae3e;
P_0c0cae3e: /* original ff17, guest PC 0x0c0cae3e */
if(!s->budget--) { s->failed_pc=0x0c0cae3eu; return 0; }
vf3_matrix_store(s,ram,1,r[15]+r[0]);
goto P_0c0cae40;
P_0c0cae40: /* original e004, guest PC 0x0c0cae40 */
if(!s->budget--) { s->failed_pc=0x0c0cae40u; return 0; }
r[0]=0x00000004u;
goto P_0c0cae42;
P_0c0cae42: /* original f32c, guest PC 0x0c0cae42 */
if(!s->budget--) { s->failed_pc=0x0c0cae42u; return 0; }
vf3_matrix_move(s,3,2);
goto P_0c0cae44;
P_0c0cae44: /* original f01c, guest PC 0x0c0cae44 */
if(!s->budget--) { s->failed_pc=0x0c0cae44u; return 0; }
vf3_matrix_move(s,0,1);
goto P_0c0cae46;
P_0c0cae46: /* original f31e, guest PC 0x0c0cae46 */
if(!s->budget--) { s->failed_pc=0x0c0cae46u; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[1],fr[3],r[18]);
goto P_0c0cae48;
P_0c0cae48: /* original ff37, guest PC 0x0c0cae48 */
if(!s->budget--) { s->failed_pc=0x0c0cae48u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0cae4a;
P_0c0cae4a: /* original c730, guest PC 0x0c0cae4a */
if(!s->budget--) { s->failed_pc=0x0c0cae4au; return 0; }
r[0]=0x0c0caf0cu;
goto P_0c0cae4c;
P_0c0cae4c: /* original f408, guest PC 0x0c0cae4c */
if(!s->budget--) { s->failed_pc=0x0c0cae4cu; return 0; }
vf3_matrix_load(s,ram,4,r[0]);
goto P_0c0cae4e;
P_0c0cae4e: /* original f345, guest PC 0x0c0cae4e */
if(!s->budget--) { s->failed_pc=0x0c0cae4eu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[4]))!=0);
goto P_0c0cae50;
P_0c0cae50: /* original 8972, guest PC 0x0c0cae50 */
if(!s->budget--) { s->failed_pc=0x0c0cae50u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0caf38; }
goto P_0c0cae52;
P_0c0cae52: /* original 9053, guest PC 0x0c0cae52 */
if(!s->budget--) { s->failed_pc=0x0c0cae52u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0caefcu,2);
goto P_0c0cae54;
P_0c0cae54: /* original e506, guest PC 0x0c0cae54 */
if(!s->budget--) { s->failed_pc=0x0c0cae54u; return 0; }
r[5]=0x00000006u;
goto P_0c0cae56;
P_0c0cae56: /* original d32e, guest PC 0x0c0cae56 */
if(!s->budget--) { s->failed_pc=0x0c0cae56u; return 0; }
r[3]=read(ram,0x0c0caf10u,4);
goto P_0c0cae58;
P_0c0cae58: /* original 6453, guest PC 0x0c0cae58 */
if(!s->budget--) { s->failed_pc=0x0c0cae58u; return 0; }
r[4]=r[5];
goto P_0c0cae5a;
P_0c0cae5a: /* original f8e6, guest PC 0x0c0cae5a */
if(!s->budget--) { s->failed_pc=0x0c0cae5au; return 0; }
vf3_matrix_load(s,ram,8,r[14]+r[0]);
goto P_0c0cae5c;
P_0c0cae5c: /* original 7004, guest PC 0x0c0cae5c */
if(!s->budget--) { s->failed_pc=0x0c0cae5cu; return 0; }
r[0]+=0x00000004u;
goto P_0c0cae5e;
P_0c0cae5e: /* original f7e6, guest PC 0x0c0cae5e */
if(!s->budget--) { s->failed_pc=0x0c0cae5eu; return 0; }
vf3_matrix_load(s,ram,7,r[14]+r[0]);
goto P_0c0cae60;
P_0c0cae60: /* original 701b, guest PC 0x0c0cae60 */
if(!s->budget--) { s->failed_pc=0x0c0cae60u; return 0; }
r[0]+=0x0000001bu;
goto P_0c0cae62;
P_0c0cae62: /* original 07ec, guest PC 0x0c0cae62 */
if(!s->budget--) { s->failed_pc=0x0c0cae62u; return 0; }
r[7]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0cae64;
P_0c0cae64: /* original 1f34, guest PC 0x0c0cae64 */
if(!s->budget--) { s->failed_pc=0x0c0cae64u; return 0; }
write(ram,r[15]+16,r[3],4);
goto P_0c0cae66;
P_0c0cae66: /* original 677c, guest PC 0x0c0cae66 */
if(!s->budget--) { s->failed_pc=0x0c0cae66u; return 0; }
r[7]=r[7]&255u;
goto P_0c0cae68;
P_0c0cae68: /* original 6353, guest PC 0x0c0cae68 */
if(!s->budget--) { s->failed_pc=0x0c0cae68u; return 0; }
r[3]=r[5];
goto P_0c0cae6a;
P_0c0cae6a: /* original 3348, guest PC 0x0c0cae6a */
if(!s->budget--) { s->failed_pc=0x0c0cae6au; return 0; }
r[3]-=r[4];
goto P_0c0cae6c;
P_0c0cae6c: /* original 2f32, guest PC 0x0c0cae6c */
if(!s->budget--) { s->failed_pc=0x0c0cae6cu; return 0; }
write(ram,r[15],r[3],4);
goto P_0c0cae6e;
P_0c0cae6e: /* original 56f4, guest PC 0x0c0cae6e */
if(!s->budget--) { s->failed_pc=0x0c0cae6eu; return 0; }
r[6]=read(ram,r[15]+16,4);
goto P_0c0cae70;
P_0c0cae70: /* original d228, guest PC 0x0c0cae70 */
if(!s->budget--) { s->failed_pc=0x0c0cae70u; return 0; }
r[2]=read(ram,0x0c0caf14u,4);
goto P_0c0cae72;
P_0c0cae72: /* original 363c, guest PC 0x0c0cae72 */
if(!s->budget--) { s->failed_pc=0x0c0cae72u; return 0; }
r[6]+=r[3];
goto P_0c0cae74;
P_0c0cae74: /* original 6160, guest PC 0x0c0cae74 */
if(!s->budget--) { s->failed_pc=0x0c0cae74u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[6],1);
r[1]=tmp;
goto P_0c0cae76;
P_0c0cae76: /* original 420b, guest PC 0x0c0cae76 */
if(!s->budget--) { s->failed_pc=0x0c0cae76u; return 0; }
target=r[2];
r[16]=0x0c0cae7au;
r[0]=0x00000004u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0cae7au) { target=s->pc; goto dispatch; }
goto P_0c0cae7a;
P_0c0cae78: /* original e004, guest PC 0x0c0cae78 */
if(!s->budget--) { s->failed_pc=0x0c0cae78u; return 0; }
r[0]=0x00000004u;
goto P_0c0cae7a;
P_0c0cae7a: /* original 9340, guest PC 0x0c0cae7a */
if(!s->budget--) { s->failed_pc=0x0c0cae7au; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0caefeu,2);
goto P_0c0cae7c;
P_0c0cae7c: /* original 660e, guest PC 0x0c0cae7c */
if(!s->budget--) { s->failed_pc=0x0c0cae7cu; return 0; }
r[6]=(uint32_t)(int32_t)(int8_t)r[0];
goto P_0c0cae7e;
P_0c0cae7e: /* original 4608, guest PC 0x0c0cae7e */
if(!s->budget--) { s->failed_pc=0x0c0cae7eu; return 0; }
r[6]<<=2;
goto P_0c0cae80;
P_0c0cae80: /* original 33ec, guest PC 0x0c0cae80 */
if(!s->budget--) { s->failed_pc=0x0c0cae80u; return 0; }
r[3]+=r[14];
goto P_0c0cae82;
P_0c0cae82: /* original 363c, guest PC 0x0c0cae82 */
if(!s->budget--) { s->failed_pc=0x0c0cae82u; return 0; }
r[6]+=r[3];
goto P_0c0cae84;
P_0c0cae84: /* original 6662, guest PC 0x0c0cae84 */
if(!s->budget--) { s->failed_pc=0x0c0cae84u; return 0; }
tmp=read(ram,r[6],4);
r[6]=tmp;
goto P_0c0cae86;
P_0c0cae86: /* original e204, guest PC 0x0c0cae86 */
if(!s->budget--) { s->failed_pc=0x0c0cae86u; return 0; }
r[2]=0x00000004u;
goto P_0c0cae88;
P_0c0cae88: /* original 2628, guest PC 0x0c0cae88 */
if(!s->budget--) { s->failed_pc=0x0c0cae88u; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[2])==0)!=0);
goto P_0c0cae8a;
P_0c0cae8a: /* original 8902, guest PC 0x0c0cae8a */
if(!s->budget--) { s->failed_pc=0x0c0cae8au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0cae92; }
goto P_0c0cae8c;
P_0c0cae8c: /* original f58c, guest PC 0x0c0cae8c */
if(!s->budget--) { s->failed_pc=0x0c0cae8cu; return 0; }
vf3_matrix_move(s,5,8);
goto P_0c0cae8e;
P_0c0cae8e: /* original a002, guest PC 0x0c0cae8e */
if(!s->budget--) { s->failed_pc=0x0c0cae8eu; return 0; }
vf3_matrix_move(s,4,7);
goto P_0c0cae96;
P_0c0cae90: /* original f47c, guest PC 0x0c0cae90 */
if(!s->budget--) { s->failed_pc=0x0c0cae90u; return 0; }
vf3_matrix_move(s,4,7);
goto P_0c0cae92;
P_0c0cae92: /* original f48d, guest PC 0x0c0cae92 */
if(!s->budget--) { s->failed_pc=0x0c0cae92u; return 0; }
fr[4]=0;
goto P_0c0cae94;
P_0c0cae94: /* original f54c, guest PC 0x0c0cae94 */
if(!s->budget--) { s->failed_pc=0x0c0cae94u; return 0; }
vf3_matrix_move(s,5,4);
goto P_0c0cae96;
P_0c0cae96: /* original 4410, guest PC 0x0c0cae96 */
if(!s->budget--) { s->failed_pc=0x0c0cae96u; return 0; }
--r[4];
r[17]=(r[17]&~1u)|((r[4]==0)!=0);
goto P_0c0cae98;
P_0c0cae98: /* original 8be6, guest PC 0x0c0cae98 */
if(!s->budget--) { s->failed_pc=0x0c0cae98u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0cae68; }
goto P_0c0cae9a;
P_0c0cae9a: /* original 9332, guest PC 0x0c0cae9a */
if(!s->budget--) { s->failed_pc=0x0c0cae9au; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0caf02u,2);
goto P_0c0cae9c;
P_0c0cae9c: /* original e41c, guest PC 0x0c0cae9c */
if(!s->budget--) { s->failed_pc=0x0c0cae9cu; return 0; }
r[4]=0x0000001cu;
goto P_0c0cae9e;
P_0c0cae9e: /* original 902f, guest PC 0x0c0cae9e */
if(!s->budget--) { s->failed_pc=0x0c0cae9eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0caf00u,2);
goto P_0c0caea0;
P_0c0caea0: /* original 33ec, guest PC 0x0c0caea0 */
if(!s->budget--) { s->failed_pc=0x0c0caea0u; return 0; }
r[3]+=r[14];
goto P_0c0caea2;
P_0c0caea2: /* original 05ee, guest PC 0x0c0caea2 */
if(!s->budget--) { s->failed_pc=0x0c0caea2u; return 0; }
r[5]=read(ram,r[14]+r[0],4);
goto P_0c0caea4;
P_0c0caea4: /* original 1f32, guest PC 0x0c0caea4 */
if(!s->budget--) { s->failed_pc=0x0c0caea4u; return 0; }
write(ram,r[15]+8,r[3],4);
goto P_0c0caea6;
P_0c0caea6: /* original 922d, guest PC 0x0c0caea6 */
if(!s->budget--) { s->failed_pc=0x0c0caea6u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0caf04u,2);
goto P_0c0caea8;
P_0c0caea8: /* original 32ec, guest PC 0x0c0caea8 */
if(!s->budget--) { s->failed_pc=0x0c0caea8u; return 0; }
r[2]+=r[14];
goto P_0c0caeaa;
P_0c0caeaa: /* original 1f24, guest PC 0x0c0caeaa */
if(!s->budget--) { s->failed_pc=0x0c0caeaau; return 0; }
write(ram,r[15]+16,r[2],4);
goto P_0c0caeac;
P_0c0caeac: /* original 53f2, guest PC 0x0c0caeac */
if(!s->budget--) { s->failed_pc=0x0c0caeacu; return 0; }
r[3]=read(ram,r[15]+8,4);
goto P_0c0caeae;
P_0c0caeae: /* original e004, guest PC 0x0c0caeae */
if(!s->budget--) { s->failed_pc=0x0c0caeaeu; return 0; }
r[0]=0x00000004u;
goto P_0c0caeb0;
P_0c0caeb0: /* original f656, guest PC 0x0c0caeb0 */
if(!s->budget--) { s->failed_pc=0x0c0caeb0u; return 0; }
vf3_matrix_load(s,ram,6,r[5]+r[0]);
goto P_0c0caeb2;
P_0c0caeb2: /* original 7304, guest PC 0x0c0caeb2 */
if(!s->budget--) { s->failed_pc=0x0c0caeb2u; return 0; }
r[3]+=0x00000004u;
goto P_0c0caeb4;
P_0c0caeb4: /* original 1f32, guest PC 0x0c0caeb4 */
if(!s->budget--) { s->failed_pc=0x0c0caeb4u; return 0; }
write(ram,r[15]+8,r[3],4);
goto P_0c0caeb6;
P_0c0caeb6: /* original 73fc, guest PC 0x0c0caeb6 */
if(!s->budget--) { s->failed_pc=0x0c0caeb6u; return 0; }
r[3]+=0xfffffffcu;
goto P_0c0caeb8;
P_0c0caeb8: /* original 52f4, guest PC 0x0c0caeb8 */
if(!s->budget--) { s->failed_pc=0x0c0caeb8u; return 0; }
r[2]=read(ram,r[15]+16,4);
goto P_0c0caeba;
P_0c0caeba: /* original fa38, guest PC 0x0c0caeba */
if(!s->budget--) { s->failed_pc=0x0c0caebau; return 0; }
vf3_matrix_load(s,ram,10,r[3]);
goto P_0c0caebc;
P_0c0caebc: /* original 7204, guest PC 0x0c0caebc */
if(!s->budget--) { s->failed_pc=0x0c0caebcu; return 0; }
r[2]+=0x00000004u;
goto P_0c0caebe;
P_0c0caebe: /* original f6a1, guest PC 0x0c0caebe */
if(!s->budget--) { s->failed_pc=0x0c0caebeu; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[10],r[18],'-');
goto P_0c0caec0;
P_0c0caec0: /* original 1f24, guest PC 0x0c0caec0 */
if(!s->budget--) { s->failed_pc=0x0c0caec0u; return 0; }
write(ram,r[15]+16,r[2],4);
goto P_0c0caec2;
P_0c0caec2: /* original 72fc, guest PC 0x0c0caec2 */
if(!s->budget--) { s->failed_pc=0x0c0caec2u; return 0; }
r[2]+=0xfffffffcu;
goto P_0c0caec4;
P_0c0caec4: /* original f928, guest PC 0x0c0caec4 */
if(!s->budget--) { s->failed_pc=0x0c0caec4u; return 0; }
vf3_matrix_load(s,ram,9,r[2]);
goto P_0c0caec6;
P_0c0caec6: /* original f965, guest PC 0x0c0caec6 */
if(!s->budget--) { s->failed_pc=0x0c0caec6u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[9])>as_float(fr[6]))!=0);
goto P_0c0caec8;
P_0c0caec8: /* original 8f2a, guest PC 0x0c0caec8 */
if(!s->budget--) { s->failed_pc=0x0c0caec8u; return 0; }
cond=r[17]&1u;
r[5]+=0x0000000cu;
if(!cond) { goto P_0c0caf20; }
goto P_0c0caecc;
P_0c0caeca: /* original 750c, guest PC 0x0c0caeca */
if(!s->budget--) { s->failed_pc=0x0c0caecau; return 0; }
r[5]+=0x0000000cu;
goto P_0c0caecc;
P_0c0caecc: /* original f961, guest PC 0x0c0caecc */
if(!s->budget--) { s->failed_pc=0x0c0caeccu; return 0; }
fr[9]=vf3_fpu_binary(fr[9],fr[6],r[18],'-');
goto P_0c0caece;
P_0c0caece: /* original e004, guest PC 0x0c0caece */
if(!s->budget--) { s->failed_pc=0x0c0caeceu; return 0; }
r[0]=0x00000004u;
goto P_0c0caed0;
P_0c0caed0: /* original f39c, guest PC 0x0c0caed0 */
if(!s->budget--) { s->failed_pc=0x0c0caed0u; return 0; }
vf3_matrix_move(s,3,9);
goto P_0c0caed2;
P_0c0caed2: /* original f3f5, guest PC 0x0c0caed2 */
if(!s->budget--) { s->failed_pc=0x0c0caed2u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[15]))!=0);
goto P_0c0caed4;
P_0c0caed4: /* original 8f24, guest PC 0x0c0caed4 */
if(!s->budget--) { s->failed_pc=0x0c0caed4u; return 0; }
cond=r[17]&1u;
vf3_matrix_store(s,ram,9,r[15]+r[0]);
if(!cond) { goto P_0c0caf20; }
goto P_0c0caed8;
P_0c0caed6: /* original ff97, guest PC 0x0c0caed6 */
if(!s->budget--) { s->failed_pc=0x0c0caed6u; return 0; }
vf3_matrix_store(s,ram,9,r[15]+r[0]);
goto P_0c0caed8;
P_0c0caed8: /* original 6043, guest PC 0x0c0caed8 */
if(!s->budget--) { s->failed_pc=0x0c0caed8u; return 0; }
r[0]=r[4];
goto P_0c0caeda;
P_0c0caeda: /* original 880d, guest PC 0x0c0caeda */
if(!s->budget--) { s->failed_pc=0x0c0caedau; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000du)!=0);
goto P_0c0caedc;
P_0c0caedc: /* original f58c, guest PC 0x0c0caedc */
if(!s->budget--) { s->failed_pc=0x0c0caedcu; return 0; }
vf3_matrix_move(s,5,8);
goto P_0c0caede;
P_0c0caede: /* original 8d1d, guest PC 0x0c0caede */
if(!s->budget--) { s->failed_pc=0x0c0caedeu; return 0; }
cond=r[17]&1u;
vf3_matrix_move(s,4,7);
if(cond) { goto P_0c0caf1c; }
goto P_0c0caee2;
P_0c0caee0: /* original f47c, guest PC 0x0c0caee0 */
if(!s->budget--) { s->failed_pc=0x0c0caee0u; return 0; }
vf3_matrix_move(s,4,7);
goto P_0c0caee2;
P_0c0caee2: /* original e30d, guest PC 0x0c0caee2 */
if(!s->budget--) { s->failed_pc=0x0c0caee2u; return 0; }
r[3]=0x0000000du;
goto P_0c0caee4;
P_0c0caee4: /* original 3437, guest PC 0x0c0caee4 */
if(!s->budget--) { s->failed_pc=0x0c0caee4u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>(int32_t)r[3])!=0);
goto P_0c0caee6;
P_0c0caee6: /* original e602, guest PC 0x0c0caee6 */
if(!s->budget--) { s->failed_pc=0x0c0caee6u; return 0; }
r[6]=0x00000002u;
goto P_0c0caee8;
P_0c0caee8: /* original 8d16, guest PC 0x0c0caee8 */
if(!s->budget--) { s->failed_pc=0x0c0caee8u; return 0; }
cond=r[17]&1u;
r[6]&=r[7];
if(cond) { goto P_0c0caf18; }
goto P_0c0caeec;
P_0c0caeea: /* original 2679, guest PC 0x0c0caeea */
if(!s->budget--) { s->failed_pc=0x0c0caeeau; return 0; }
r[6]&=r[7];
goto P_0c0caeec;
P_0c0caeec: /* original 2668, guest PC 0x0c0caeec */
if(!s->budget--) { s->failed_pc=0x0c0caeecu; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[6])==0)!=0);
goto P_0c0caeee;
P_0c0caeee: /* original 8b17, guest PC 0x0c0caeee */
if(!s->budget--) { s->failed_pc=0x0c0caeeeu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0caf20; }
goto P_0c0caef0;
P_0c0caef0: /* original a014, guest PC 0x0c0caef0 */
if(!s->budget--) { s->failed_pc=0x0c0caef0u; return 0; }
goto P_0c0caf1c;
P_0c0caef2: /* original 0009, guest PC 0x0c0caef2 */
if(!s->budget--) { s->failed_pc=0x0c0caef2u; return 0; }
return vf3_matrix_family(0x0c0caef4u,s,ram);
P_0c0caf18: /* original 2668, guest PC 0x0c0caf18 */
if(!s->budget--) { s->failed_pc=0x0c0caf18u; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[6])==0)!=0);
goto P_0c0caf1a;
P_0c0caf1a: /* original 8901, guest PC 0x0c0caf1a */
if(!s->budget--) { s->failed_pc=0x0c0caf1au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0caf20; }
goto P_0c0caf1c;
P_0c0caf1c: /* original e004, guest PC 0x0c0caf1c */
if(!s->budget--) { s->failed_pc=0x0c0caf1cu; return 0; }
r[0]=0x00000004u;
goto P_0c0caf1e;
P_0c0caf1e: /* original fff6, guest PC 0x0c0caf1e */
if(!s->budget--) { s->failed_pc=0x0c0caf1eu; return 0; }
vf3_matrix_load(s,ram,15,r[15]+r[0]);
goto P_0c0caf20;
P_0c0caf20: /* original 4410, guest PC 0x0c0caf20 */
if(!s->budget--) { s->failed_pc=0x0c0caf20u; return 0; }
--r[4];
r[17]=(r[17]&~1u)|((r[4]==0)!=0);
goto P_0c0caf22;
P_0c0caf22: /* original 8bc3, guest PC 0x0c0caf22 */
if(!s->budget--) { s->failed_pc=0x0c0caf22u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0caeac; }
goto P_0c0caf24;
P_0c0caf24: /* original 62e2, guest PC 0x0c0caf24 */
if(!s->budget--) { s->failed_pc=0x0c0caf24u; return 0; }
tmp=read(ram,r[14],4);
r[2]=tmp;
goto P_0c0caf26;
P_0c0caf26: /* original 9383, guest PC 0x0c0caf26 */
if(!s->budget--) { s->failed_pc=0x0c0caf26u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0cb030u,2);
goto P_0c0caf28;
P_0c0caf28: /* original 2238, guest PC 0x0c0caf28 */
if(!s->budget--) { s->failed_pc=0x0c0caf28u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c0caf2a;
P_0c0caf2a: /* original 8903, guest PC 0x0c0caf2a */
if(!s->budget--) { s->failed_pc=0x0c0caf2au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0caf34; }
goto P_0c0caf2c;
P_0c0caf2c: /* original c742, guest PC 0x0c0caf2c */
if(!s->budget--) { s->failed_pc=0x0c0caf2cu; return 0; }
r[0]=0x0c0cb038u;
goto P_0c0caf2e;
P_0c0caf2e: /* original f608, guest PC 0x0c0caf2e */
if(!s->budget--) { s->failed_pc=0x0c0caf2eu; return 0; }
vf3_matrix_load(s,ram,6,r[0]);
goto P_0c0caf30;
P_0c0caf30: /* original f462, guest PC 0x0c0caf30 */
if(!s->budget--) { s->failed_pc=0x0c0caf30u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[6],r[18],'*');
goto P_0c0caf32;
P_0c0caf32: /* original f562, guest PC 0x0c0caf32 */
if(!s->budget--) { s->failed_pc=0x0c0caf32u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[6],r[18],'*');
goto P_0c0caf34;
P_0c0caf34: /* original fe4c, guest PC 0x0c0caf34 */
if(!s->budget--) { s->failed_pc=0x0c0caf34u; return 0; }
vf3_matrix_move(s,14,4);
goto P_0c0caf36;
P_0c0caf36: /* original fd5c, guest PC 0x0c0caf36 */
if(!s->budget--) { s->failed_pc=0x0c0caf36u; return 0; }
vf3_matrix_move(s,13,5);
goto P_0c0caf38;
P_0c0caf38: /* original 907b, guest PC 0x0c0caf38 */
if(!s->budget--) { s->failed_pc=0x0c0caf38u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0cb032u,2);
goto P_0c0caf3a;
P_0c0caf3a: /* original 7f3c, guest PC 0x0c0caf3a */
if(!s->budget--) { s->failed_pc=0x0c0caf3au; return 0; }
r[15]+=0x0000003cu;
goto P_0c0caf3c;
P_0c0caf3c: /* original 4f26, guest PC 0x0c0caf3c */
if(!s->budget--) { s->failed_pc=0x0c0caf3cu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0caf3e;
P_0c0caf3e: /* original fed7, guest PC 0x0c0caf3e */
if(!s->budget--) { s->failed_pc=0x0c0caf3eu; return 0; }
vf3_matrix_store(s,ram,13,r[14]+r[0]);
goto P_0c0caf40;
P_0c0caf40: /* original 7004, guest PC 0x0c0caf40 */
if(!s->budget--) { s->failed_pc=0x0c0caf40u; return 0; }
r[0]+=0x00000004u;
goto P_0c0caf42;
P_0c0caf42: /* original fef7, guest PC 0x0c0caf42 */
if(!s->budget--) { s->failed_pc=0x0c0caf42u; return 0; }
vf3_matrix_store(s,ram,15,r[14]+r[0]);
goto P_0c0caf44;
P_0c0caf44: /* original 7004, guest PC 0x0c0caf44 */
if(!s->budget--) { s->failed_pc=0x0c0caf44u; return 0; }
r[0]+=0x00000004u;
goto P_0c0caf46;
P_0c0caf46: /* original fee7, guest PC 0x0c0caf46 */
if(!s->budget--) { s->failed_pc=0x0c0caf46u; return 0; }
vf3_matrix_store(s,ram,14,r[14]+r[0]);
goto P_0c0caf48;
P_0c0caf48: /* original fdf9, guest PC 0x0c0caf48 */
if(!s->budget--) { s->failed_pc=0x0c0caf48u; return 0; }
vf3_matrix_load(s,ram,13,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0caf4a;
P_0c0caf4a: /* original fef9, guest PC 0x0c0caf4a */
if(!s->budget--) { s->failed_pc=0x0c0caf4au; return 0; }
vf3_matrix_load(s,ram,14,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0caf4c;
P_0c0caf4c: /* original fff9, guest PC 0x0c0caf4c */
if(!s->budget--) { s->failed_pc=0x0c0caf4cu; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0caf4e;
P_0c0caf4e: /* original 68f6, guest PC 0x0c0caf4e */
if(!s->budget--) { s->failed_pc=0x0c0caf4eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c0caf50;
P_0c0caf50: /* original 69f6, guest PC 0x0c0caf50 */
if(!s->budget--) { s->failed_pc=0x0c0caf50u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c0caf52;
P_0c0caf52: /* original 6af6, guest PC 0x0c0caf52 */
if(!s->budget--) { s->failed_pc=0x0c0caf52u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0caf54;
P_0c0caf54: /* original 6bf6, guest PC 0x0c0caf54 */
if(!s->budget--) { s->failed_pc=0x0c0caf54u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0caf56;
P_0c0caf56: /* original 6cf6, guest PC 0x0c0caf56 */
if(!s->budget--) { s->failed_pc=0x0c0caf56u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0caf58;
P_0c0caf58: /* original 6df6, guest PC 0x0c0caf58 */
if(!s->budget--) { s->failed_pc=0x0c0caf58u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0caf5a;
P_0c0caf5a: /* original 000b, guest PC 0x0c0caf5a */
if(!s->budget--) { s->failed_pc=0x0c0caf5au; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0caf5c: /* original 6ef6, guest PC 0x0c0caf5c */
if(!s->budget--) { s->failed_pc=0x0c0caf5cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0caf5e;
P_0c0caf5e: /* original 2fe6, guest PC 0x0c0caf5e */
if(!s->budget--) { s->failed_pc=0x0c0caf5eu; return 0; }
r[15]-=4; write(ram,r[15],r[14],4);
goto P_0c0caf60;
P_0c0caf60: /* original 6e53, guest PC 0x0c0caf60 */
if(!s->budget--) { s->failed_pc=0x0c0caf60u; return 0; }
r[14]=r[5];
goto P_0c0caf62;
P_0c0caf62: /* original 2fd6, guest PC 0x0c0caf62 */
if(!s->budget--) { s->failed_pc=0x0c0caf62u; return 0; }
r[15]-=4; write(ram,r[15],r[13],4);
goto P_0c0caf64;
P_0c0caf64: /* original 4f22, guest PC 0x0c0caf64 */
if(!s->budget--) { s->failed_pc=0x0c0caf64u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0caf66;
P_0c0caf66: /* original 7ffc, guest PC 0x0c0caf66 */
if(!s->budget--) { s->failed_pc=0x0c0caf66u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c0caf68;
P_0c0caf68: /* original 2f42, guest PC 0x0c0caf68 */
if(!s->budget--) { s->failed_pc=0x0c0caf68u; return 0; }
write(ram,r[15],r[4],4);
goto P_0c0caf6a;
P_0c0caf6a: /* original d135, guest PC 0x0c0caf6a */
if(!s->budget--) { s->failed_pc=0x0c0caf6au; return 0; }
r[1]=read(ram,0x0c0cb040u,4);
goto P_0c0caf6c;
P_0c0caf6c: /* original d333, guest PC 0x0c0caf6c */
if(!s->budget--) { s->failed_pc=0x0c0caf6cu; return 0; }
r[3]=read(ram,0x0c0cb03cu,4);
goto P_0c0caf6e;
P_0c0caf6e: /* original 6212, guest PC 0x0c0caf6e */
if(!s->budget--) { s->failed_pc=0x0c0caf6eu; return 0; }
tmp=read(ram,r[1],4);
r[2]=tmp;
goto P_0c0caf70;
P_0c0caf70: /* original 2238, guest PC 0x0c0caf70 */
if(!s->budget--) { s->failed_pc=0x0c0caf70u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c0caf72;
P_0c0caf72: /* original 8f36, guest PC 0x0c0caf72 */
if(!s->budget--) { s->failed_pc=0x0c0caf72u; return 0; }
cond=r[17]&1u;
r[13]=r[6];
if(!cond) { goto P_0c0cafe2; }
goto P_0c0caf76;
P_0c0caf74: /* original 6d63, guest PC 0x0c0caf74 */
if(!s->budget--) { s->failed_pc=0x0c0caf74u; return 0; }
r[13]=r[6];
goto P_0c0caf76;
P_0c0caf76: /* original b039, guest PC 0x0c0caf76 */
if(!s->budget--) { s->failed_pc=0x0c0caf76u; return 0; }
target=0x0c0cafecu; r[16]=0x0c0caf7au;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0caf7au) { target=s->pc; goto dispatch; }
goto P_0c0caf7a;
P_0c0caf78: /* original 64e3, guest PC 0x0c0caf78 */
if(!s->budget--) { s->failed_pc=0x0c0caf78u; return 0; }
r[4]=r[14];
goto P_0c0caf7a;
P_0c0caf7a: /* original b037, guest PC 0x0c0caf7a */
if(!s->budget--) { s->failed_pc=0x0c0caf7au; return 0; }
target=0x0c0cafecu; r[16]=0x0c0caf7eu;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0caf7eu) { target=s->pc; goto dispatch; }
goto P_0c0caf7e;
P_0c0caf7c: /* original 64d3, guest PC 0x0c0caf7c */
if(!s->budget--) { s->failed_pc=0x0c0caf7cu; return 0; }
r[4]=r[13];
goto P_0c0caf7e;
P_0c0caf7e: /* original e048, guest PC 0x0c0caf7e */
if(!s->budget--) { s->failed_pc=0x0c0caf7eu; return 0; }
r[0]=0x00000048u;
goto P_0c0caf80;
P_0c0caf80: /* original 9358, guest PC 0x0c0caf80 */
if(!s->budget--) { s->failed_pc=0x0c0caf80u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0cb034u,2);
goto P_0c0caf82;
P_0c0caf82: /* original 05de, guest PC 0x0c0caf82 */
if(!s->budget--) { s->failed_pc=0x0c0caf82u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0caf84;
P_0c0caf84: /* original 04ee, guest PC 0x0c0caf84 */
if(!s->budget--) { s->failed_pc=0x0c0caf84u; return 0; }
r[4]=read(ram,r[14]+r[0],4);
goto P_0c0caf86;
P_0c0caf86: /* original 245b, guest PC 0x0c0caf86 */
if(!s->budget--) { s->failed_pc=0x0c0caf86u; return 0; }
r[4]|=r[5];
goto P_0c0caf88;
P_0c0caf88: /* original 2438, guest PC 0x0c0caf88 */
if(!s->budget--) { s->failed_pc=0x0c0caf88u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[3])==0)!=0);
goto P_0c0caf8a;
P_0c0caf8a: /* original 892a, guest PC 0x0c0caf8a */
if(!s->budget--) { s->failed_pc=0x0c0caf8au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0cafe2; }
goto P_0c0caf8c;
P_0c0caf8c: /* original 62f2, guest PC 0x0c0caf8c */
if(!s->budget--) { s->failed_pc=0x0c0caf8cu; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c0caf8e;
P_0c0caf8e: /* original e034, guest PC 0x0c0caf8e */
if(!s->budget--) { s->failed_pc=0x0c0caf8eu; return 0; }
r[0]=0x00000034u;
goto P_0c0caf90;
P_0c0caf90: /* original 032c, guest PC 0x0c0caf90 */
if(!s->budget--) { s->failed_pc=0x0c0caf90u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[2]+r[0],1);
goto P_0c0caf92;
P_0c0caf92: /* original 2338, guest PC 0x0c0caf92 */
if(!s->budget--) { s->failed_pc=0x0c0caf92u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c0caf94;
P_0c0caf94: /* original 8925, guest PC 0x0c0caf94 */
if(!s->budget--) { s->failed_pc=0x0c0caf94u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0cafe2; }
goto P_0c0caf96;
P_0c0caf96: /* original 904c, guest PC 0x0c0caf96 */
if(!s->budget--) { s->failed_pc=0x0c0caf96u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0cb032u,2);
goto P_0c0caf98;
P_0c0caf98: /* original f38d, guest PC 0x0c0caf98 */
if(!s->budget--) { s->failed_pc=0x0c0caf98u; return 0; }
fr[3]=0;
goto P_0c0caf9a;
P_0c0caf9a: /* original f6e6, guest PC 0x0c0caf9a */
if(!s->budget--) { s->failed_pc=0x0c0caf9au; return 0; }
vf3_matrix_load(s,ram,6,r[14]+r[0]);
goto P_0c0caf9c;
P_0c0caf9c: /* original 7008, guest PC 0x0c0caf9c */
if(!s->budget--) { s->failed_pc=0x0c0caf9cu; return 0; }
r[0]+=0x00000008u;
goto P_0c0caf9e;
P_0c0caf9e: /* original f7e6, guest PC 0x0c0caf9e */
if(!s->budget--) { s->failed_pc=0x0c0caf9eu; return 0; }
vf3_matrix_load(s,ram,7,r[14]+r[0]);
goto P_0c0cafa0;
P_0c0cafa0: /* original 70f8, guest PC 0x0c0cafa0 */
if(!s->budget--) { s->failed_pc=0x0c0cafa0u; return 0; }
r[0]+=0xfffffff8u;
goto P_0c0cafa2;
P_0c0cafa2: /* original f8d6, guest PC 0x0c0cafa2 */
if(!s->budget--) { s->failed_pc=0x0c0cafa2u; return 0; }
vf3_matrix_load(s,ram,8,r[13]+r[0]);
goto P_0c0cafa4;
P_0c0cafa4: /* original 7008, guest PC 0x0c0cafa4 */
if(!s->budget--) { s->failed_pc=0x0c0cafa4u; return 0; }
r[0]+=0x00000008u;
goto P_0c0cafa6;
P_0c0cafa6: /* original f46c, guest PC 0x0c0cafa6 */
if(!s->budget--) { s->failed_pc=0x0c0cafa6u; return 0; }
vf3_matrix_move(s,4,6);
goto P_0c0cafa8;
P_0c0cafa8: /* original fb8c, guest PC 0x0c0cafa8 */
if(!s->budget--) { s->failed_pc=0x0c0cafa8u; return 0; }
vf3_matrix_move(s,11,8);
goto P_0c0cafaa;
P_0c0cafaa: /* original fb5d, guest PC 0x0c0cafaa */
if(!s->budget--) { s->failed_pc=0x0c0cafaau; return 0; }
fr[11]&=0x7fffffffu;
goto P_0c0cafac;
P_0c0cafac: /* original f45d, guest PC 0x0c0cafac */
if(!s->budget--) { s->failed_pc=0x0c0cafacu; return 0; }
fr[4]&=0x7fffffffu;
goto P_0c0cafae;
P_0c0cafae: /* original f4b1, guest PC 0x0c0cafae */
if(!s->budget--) { s->failed_pc=0x0c0cafaeu; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[11],r[18],'-');
goto P_0c0cafb0;
P_0c0cafb0: /* original f9d6, guest PC 0x0c0cafb0 */
if(!s->budget--) { s->failed_pc=0x0c0cafb0u; return 0; }
vf3_matrix_load(s,ram,9,r[13]+r[0]);
goto P_0c0cafb2;
P_0c0cafb2: /* original f57c, guest PC 0x0c0cafb2 */
if(!s->budget--) { s->failed_pc=0x0c0cafb2u; return 0; }
vf3_matrix_move(s,5,7);
goto P_0c0cafb4;
P_0c0cafb4: /* original fa9c, guest PC 0x0c0cafb4 */
if(!s->budget--) { s->failed_pc=0x0c0cafb4u; return 0; }
vf3_matrix_move(s,10,9);
goto P_0c0cafb6;
P_0c0cafb6: /* original f345, guest PC 0x0c0cafb6 */
if(!s->budget--) { s->failed_pc=0x0c0cafb6u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[4]))!=0);
goto P_0c0cafb8;
P_0c0cafb8: /* original fa5d, guest PC 0x0c0cafb8 */
if(!s->budget--) { s->failed_pc=0x0c0cafb8u; return 0; }
fr[10]&=0x7fffffffu;
goto P_0c0cafba;
P_0c0cafba: /* original f55d, guest PC 0x0c0cafba */
if(!s->budget--) { s->failed_pc=0x0c0cafbau; return 0; }
fr[5]&=0x7fffffffu;
goto P_0c0cafbc;
P_0c0cafbc: /* original 8d02, guest PC 0x0c0cafbc */
if(!s->budget--) { s->failed_pc=0x0c0cafbcu; return 0; }
cond=r[17]&1u;
fr[5]=vf3_fpu_binary(fr[5],fr[10],r[18],'-');
if(cond) { goto P_0c0cafc4; }
goto P_0c0cafc0;
P_0c0cafbe: /* original f5a1, guest PC 0x0c0cafbe */
if(!s->budget--) { s->failed_pc=0x0c0cafbeu; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[10],r[18],'-');
goto P_0c0cafc0;
P_0c0cafc0: /* original a001, guest PC 0x0c0cafc0 */
if(!s->budget--) { s->failed_pc=0x0c0cafc0u; return 0; }
vf3_matrix_move(s,4,6);
goto P_0c0cafc6;
P_0c0cafc2: /* original f46c, guest PC 0x0c0cafc2 */
if(!s->budget--) { s->failed_pc=0x0c0cafc2u; return 0; }
vf3_matrix_move(s,4,6);
goto P_0c0cafc4;
P_0c0cafc4: /* original f48c, guest PC 0x0c0cafc4 */
if(!s->budget--) { s->failed_pc=0x0c0cafc4u; return 0; }
vf3_matrix_move(s,4,8);
goto P_0c0cafc6;
P_0c0cafc6: /* original f38d, guest PC 0x0c0cafc6 */
if(!s->budget--) { s->failed_pc=0x0c0cafc6u; return 0; }
fr[3]=0;
goto P_0c0cafc8;
P_0c0cafc8: /* original f355, guest PC 0x0c0cafc8 */
if(!s->budget--) { s->failed_pc=0x0c0cafc8u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[5]))!=0);
goto P_0c0cafca;
P_0c0cafca: /* original 8901, guest PC 0x0c0cafca */
if(!s->budget--) { s->failed_pc=0x0c0cafcau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0cafd0; }
goto P_0c0cafcc;
P_0c0cafcc: /* original a001, guest PC 0x0c0cafcc */
if(!s->budget--) { s->failed_pc=0x0c0cafccu; return 0; }
vf3_matrix_move(s,5,7);
goto P_0c0cafd2;
P_0c0cafce: /* original f57c, guest PC 0x0c0cafce */
if(!s->budget--) { s->failed_pc=0x0c0cafceu; return 0; }
vf3_matrix_move(s,5,7);
goto P_0c0cafd0;
P_0c0cafd0: /* original f59c, guest PC 0x0c0cafd0 */
if(!s->budget--) { s->failed_pc=0x0c0cafd0u; return 0; }
vf3_matrix_move(s,5,9);
goto P_0c0cafd2;
P_0c0cafd2: /* original 902e, guest PC 0x0c0cafd2 */
if(!s->budget--) { s->failed_pc=0x0c0cafd2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0cb032u,2);
goto P_0c0cafd4;
P_0c0cafd4: /* original fe47, guest PC 0x0c0cafd4 */
if(!s->budget--) { s->failed_pc=0x0c0cafd4u; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c0cafd6;
P_0c0cafd6: /* original 7008, guest PC 0x0c0cafd6 */
if(!s->budget--) { s->failed_pc=0x0c0cafd6u; return 0; }
r[0]+=0x00000008u;
goto P_0c0cafd8;
P_0c0cafd8: /* original fe57, guest PC 0x0c0cafd8 */
if(!s->budget--) { s->failed_pc=0x0c0cafd8u; return 0; }
vf3_matrix_store(s,ram,5,r[14]+r[0]);
goto P_0c0cafda;
P_0c0cafda: /* original 70f8, guest PC 0x0c0cafda */
if(!s->budget--) { s->failed_pc=0x0c0cafdau; return 0; }
r[0]+=0xfffffff8u;
goto P_0c0cafdc;
P_0c0cafdc: /* original fd47, guest PC 0x0c0cafdc */
if(!s->budget--) { s->failed_pc=0x0c0cafdcu; return 0; }
vf3_matrix_store(s,ram,4,r[13]+r[0]);
goto P_0c0cafde;
P_0c0cafde: /* original 7008, guest PC 0x0c0cafde */
if(!s->budget--) { s->failed_pc=0x0c0cafdeu; return 0; }
r[0]+=0x00000008u;
goto P_0c0cafe0;
P_0c0cafe0: /* original fd57, guest PC 0x0c0cafe0 */
if(!s->budget--) { s->failed_pc=0x0c0cafe0u; return 0; }
vf3_matrix_store(s,ram,5,r[13]+r[0]);
goto P_0c0cafe2;
P_0c0cafe2: /* original 7f04, guest PC 0x0c0cafe2 */
if(!s->budget--) { s->failed_pc=0x0c0cafe2u; return 0; }
r[15]+=0x00000004u;
goto P_0c0cafe4;
P_0c0cafe4: /* original 4f26, guest PC 0x0c0cafe4 */
if(!s->budget--) { s->failed_pc=0x0c0cafe4u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0cafe6;
P_0c0cafe6: /* original 6df6, guest PC 0x0c0cafe6 */
if(!s->budget--) { s->failed_pc=0x0c0cafe6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0cafe8;
P_0c0cafe8: /* original 000b, guest PC 0x0c0cafe8 */
if(!s->budget--) { s->failed_pc=0x0c0cafe8u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0cafea: /* original 6ef6, guest PC 0x0c0cafea */
if(!s->budget--) { s->failed_pc=0x0c0cafeau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0cafec;
P_0c0cafec: /* original 2fe6, guest PC 0x0c0cafec */
if(!s->budget--) { s->failed_pc=0x0c0cafecu; return 0; }
r[15]-=4; write(ram,r[15],r[14],4);
goto P_0c0cafee;
P_0c0cafee: /* original e368, guest PC 0x0c0cafee */
if(!s->budget--) { s->failed_pc=0x0c0cafeeu; return 0; }
r[3]=0x00000068u;
goto P_0c0caff0;
P_0c0caff0: /* original 2fd6, guest PC 0x0c0caff0 */
if(!s->budget--) { s->failed_pc=0x0c0caff0u; return 0; }
r[15]-=4; write(ram,r[15],r[13],4);
goto P_0c0caff2;
P_0c0caff2: /* original e040, guest PC 0x0c0caff2 */
if(!s->budget--) { s->failed_pc=0x0c0caff2u; return 0; }
r[0]=0x00000040u;
goto P_0c0caff4;
P_0c0caff4: /* original 2fc6, guest PC 0x0c0caff4 */
if(!s->budget--) { s->failed_pc=0x0c0caff4u; return 0; }
r[15]-=4; write(ram,r[15],r[12],4);
goto P_0c0caff6;
P_0c0caff6: /* original 6e43, guest PC 0x0c0caff6 */
if(!s->budget--) { s->failed_pc=0x0c0caff6u; return 0; }
r[14]=r[4];
goto P_0c0caff8;
P_0c0caff8: /* original 2fb6, guest PC 0x0c0caff8 */
if(!s->budget--) { s->failed_pc=0x0c0caff8u; return 0; }
r[15]-=4; write(ram,r[15],r[11],4);
goto P_0c0caffa;
P_0c0caffa: /* original 2fa6, guest PC 0x0c0caffa */
if(!s->budget--) { s->failed_pc=0x0c0caffau; return 0; }
r[15]-=4; write(ram,r[15],r[10],4);
goto P_0c0caffc;
P_0c0caffc: /* original 2f96, guest PC 0x0c0caffc */
if(!s->budget--) { s->failed_pc=0x0c0caffcu; return 0; }
r[15]-=4; write(ram,r[15],r[9],4);
goto P_0c0caffe;
P_0c0caffe: /* original 2f86, guest PC 0x0c0caffe */
if(!s->budget--) { s->failed_pc=0x0c0caffeu; return 0; }
r[15]-=4; write(ram,r[15],r[8],4);
goto P_0c0cb000;
P_0c0cb000: /* original fffb, guest PC 0x0c0cb000 */
if(!s->budget--) { s->failed_pc=0x0c0cb000u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c0cb002;
P_0c0cb002: /* original ffeb, guest PC 0x0c0cb002 */
if(!s->budget--) { s->failed_pc=0x0c0cb002u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,14,r[15]);
goto P_0c0cb004;
P_0c0cb004: /* original ffdb, guest PC 0x0c0cb004 */
if(!s->budget--) { s->failed_pc=0x0c0cb004u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,13,r[15]);
goto P_0c0cb006;
P_0c0cb006: /* original ffcb, guest PC 0x0c0cb006 */
if(!s->budget--) { s->failed_pc=0x0c0cb006u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,12,r[15]);
goto P_0c0cb008;
P_0c0cb008: /* original 4f22, guest PC 0x0c0cb008 */
if(!s->budget--) { s->failed_pc=0x0c0cb008u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0cb00a;
P_0c0cb00a: /* original d40e, guest PC 0x0c0cb00a */
if(!s->budget--) { s->failed_pc=0x0c0cb00au; return 0; }
r[4]=read(ram,0x0c0cb044u,4);
goto P_0c0cb00c;
P_0c0cb00c: /* original 7f8c, guest PC 0x0c0cb00c */
if(!s->budget--) { s->failed_pc=0x0c0cb00cu; return 0; }
r[15]+=0xffffff8cu;
goto P_0c0cb00e;
P_0c0cb00e: /* original 0f36, guest PC 0x0c0cb00e */
if(!s->budget--) { s->failed_pc=0x0c0cb00eu; return 0; }
write(ram,r[15]+r[0],r[3],4);
goto P_0c0cb010;
P_0c0cb010: /* original e048, guest PC 0x0c0cb010 */
if(!s->budget--) { s->failed_pc=0x0c0cb010u; return 0; }
r[0]=0x00000048u;
goto P_0c0cb012;
P_0c0cb012: /* original 0cee, guest PC 0x0c0cb012 */
if(!s->budget--) { s->failed_pc=0x0c0cb012u; return 0; }
r[12]=read(ram,r[14]+r[0],4);
goto P_0c0cb014;
P_0c0cb014: /* original e05c, guest PC 0x0c0cb014 */
if(!s->budget--) { s->failed_pc=0x0c0cb014u; return 0; }
r[0]=0x0000005cu;
goto P_0c0cb016;
P_0c0cb016: /* original d30c, guest PC 0x0c0cb016 */
if(!s->budget--) { s->failed_pc=0x0c0cb016u; return 0; }
r[3]=read(ram,0x0c0cb048u,4);
goto P_0c0cb018;
P_0c0cb018: /* original 6de2, guest PC 0x0c0cb018 */
if(!s->budget--) { s->failed_pc=0x0c0cb018u; return 0; }
tmp=read(ram,r[14],4);
r[13]=tmp;
goto P_0c0cb01a;
P_0c0cb01a: /* original 0f36, guest PC 0x0c0cb01a */
if(!s->budget--) { s->failed_pc=0x0c0cb01au; return 0; }
write(ram,r[15]+r[0],r[3],4);
goto P_0c0cb01c;
P_0c0cb01c: /* original d20b, guest PC 0x0c0cb01c */
if(!s->budget--) { s->failed_pc=0x0c0cb01cu; return 0; }
r[2]=read(ram,0x0c0cb04cu,4);
goto P_0c0cb01e;
P_0c0cb01e: /* original 6020, guest PC 0x0c0cb01e */
if(!s->budget--) { s->failed_pc=0x0c0cb01eu; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[2],1);
r[0]=tmp;
goto P_0c0cb020;
P_0c0cb020: /* original 600c, guest PC 0x0c0cb020 */
if(!s->budget--) { s->failed_pc=0x0c0cb020u; return 0; }
r[0]=r[0]&255u;
goto P_0c0cb022;
P_0c0cb022: /* original c90f, guest PC 0x0c0cb022 */
if(!s->budget--) { s->failed_pc=0x0c0cb022u; return 0; }
r[0]&=15u;
goto P_0c0cb024;
P_0c0cb024: /* original 880d, guest PC 0x0c0cb024 */
if(!s->budget--) { s->failed_pc=0x0c0cb024u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000du)!=0);
goto P_0c0cb026;
P_0c0cb026: /* original 8b13, guest PC 0x0c0cb026 */
if(!s->budget--) { s->failed_pc=0x0c0cb026u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0cb050; }
goto P_0c0cb028;
P_0c0cb028: /* original b279, guest PC 0x0c0cb028 */
if(!s->budget--) { s->failed_pc=0x0c0cb028u; return 0; }
target=0x0c0cb51eu; r[16]=0x0c0cb02cu;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0cb02cu) { target=s->pc; goto dispatch; }
goto P_0c0cb02c;
P_0c0cb02a: /* original 64e3, guest PC 0x0c0cb02a */
if(!s->budget--) { s->failed_pc=0x0c0cb02au; return 0; }
r[4]=r[14];
goto P_0c0cb02c;
P_0c0cb02c: /* original a237, guest PC 0x0c0cb02c */
if(!s->budget--) { s->failed_pc=0x0c0cb02cu; return 0; }
goto P_0c0cb49e;
P_0c0cb02e: /* original 0009, guest PC 0x0c0cb02e */
if(!s->budget--) { s->failed_pc=0x0c0cb02eu; return 0; }
return vf3_matrix_family(0x0c0cb030u,s,ram);
P_0c0cb050: /* original 904c, guest PC 0x0c0cb050 */
if(!s->budget--) { s->failed_pc=0x0c0cb050u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0cb0ecu,2);
goto P_0c0cb052;
P_0c0cb052: /* original d32a, guest PC 0x0c0cb052 */
if(!s->budget--) { s->failed_pc=0x0c0cb052u; return 0; }
r[3]=read(ram,0x0c0cb0fcu,4);
goto P_0c0cb054;
P_0c0cb054: /* original 024e, guest PC 0x0c0cb054 */
if(!s->budget--) { s->failed_pc=0x0c0cb054u; return 0; }
r[2]=read(ram,r[4]+r[0],4);
goto P_0c0cb056;
P_0c0cb056: /* original d928, guest PC 0x0c0cb056 */
if(!s->budget--) { s->failed_pc=0x0c0cb056u; return 0; }
r[9]=read(ram,0x0c0cb0f8u,4);
goto P_0c0cb058;
P_0c0cb058: /* original 2238, guest PC 0x0c0cb058 */
if(!s->budget--) { s->failed_pc=0x0c0cb058u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c0cb05a;
P_0c0cb05a: /* original 8d5b, guest PC 0x0c0cb05a */
if(!s->budget--) { s->failed_pc=0x0c0cb05au; return 0; }
cond=r[17]&1u;
r[9]&=r[12];
if(cond) { goto P_0c0cb114; }
goto P_0c0cb05e;
P_0c0cb05c: /* original 29c9, guest PC 0x0c0cb05c */
if(!s->budget--) { s->failed_pc=0x0c0cb05cu; return 0; }
r[9]&=r[12];
goto P_0c0cb05e;
P_0c0cb05e: /* original 9146, guest PC 0x0c0cb05e */
if(!s->budget--) { s->failed_pc=0x0c0cb05eu; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0cb0eeu,2);
goto P_0c0cb060;
P_0c0cb060: /* original 21c8, guest PC 0x0c0cb060 */
if(!s->budget--) { s->failed_pc=0x0c0cb060u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[12])==0)!=0);
goto P_0c0cb062;
P_0c0cb062: /* original 8b57, guest PC 0x0c0cb062 */
if(!s->budget--) { s->failed_pc=0x0c0cb062u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0cb114; }
goto P_0c0cb064;
P_0c0cb064: /* original 2998, guest PC 0x0c0cb064 */
if(!s->budget--) { s->failed_pc=0x0c0cb064u; return 0; }
r[17]=(r[17]&~1u)|(((r[9]&r[9])==0)!=0);
goto P_0c0cb066;
P_0c0cb066: /* original 8b02, guest PC 0x0c0cb066 */
if(!s->budget--) { s->failed_pc=0x0c0cb066u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0cb06e; }
goto P_0c0cb068;
P_0c0cb068: /* original d325, guest PC 0x0c0cb068 */
if(!s->budget--) { s->failed_pc=0x0c0cb068u; return 0; }
r[3]=read(ram,0x0c0cb100u,4);
goto P_0c0cb06a;
P_0c0cb06a: /* original 23c8, guest PC 0x0c0cb06a */
if(!s->budget--) { s->failed_pc=0x0c0cb06au; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[12])==0)!=0);
goto P_0c0cb06c;
P_0c0cb06c: /* original 8952, guest PC 0x0c0cb06c */
if(!s->budget--) { s->failed_pc=0x0c0cb06cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0cb114; }
goto P_0c0cb06e;
P_0c0cb06e: /* original e03c, guest PC 0x0c0cb06e */
if(!s->budget--) { s->failed_pc=0x0c0cb06eu; return 0; }
r[0]=0x0000003cu;
goto P_0c0cb070;
P_0c0cb070: /* original 933e, guest PC 0x0c0cb070 */
if(!s->budget--) { s->failed_pc=0x0c0cb070u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0cb0f0u,2);
goto P_0c0cb072;
P_0c0cb072: /* original 02ed, guest PC 0x0c0cb072 */
if(!s->budget--) { s->failed_pc=0x0c0cb072u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0cb074;
P_0c0cb074: /* original 622d, guest PC 0x0c0cb074 */
if(!s->budget--) { s->failed_pc=0x0c0cb074u; return 0; }
r[2]=r[2]&65535u;
goto P_0c0cb076;
P_0c0cb076: /* original 3230, guest PC 0x0c0cb076 */
if(!s->budget--) { s->failed_pc=0x0c0cb076u; return 0; }
r[17]=(r[17]&~1u)|((r[2]==r[3])!=0);
goto P_0c0cb078;
P_0c0cb078: /* original 8d4c, guest PC 0x0c0cb078 */
if(!s->budget--) { s->failed_pc=0x0c0cb078u; return 0; }
cond=r[17]&1u;
write(ram,r[15]+8,r[2],4);
if(cond) { goto P_0c0cb114; }
goto P_0c0cb07c;
P_0c0cb07a: /* original 1f22, guest PC 0x0c0cb07a */
if(!s->budget--) { s->failed_pc=0x0c0cb07au; return 0; }
write(ram,r[15]+8,r[2],4);
goto P_0c0cb07c;
P_0c0cb07c: /* original 9039, guest PC 0x0c0cb07c */
if(!s->budget--) { s->failed_pc=0x0c0cb07cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0cb0f2u,2);
goto P_0c0cb07e;
P_0c0cb07e: /* original 3200, guest PC 0x0c0cb07e */
if(!s->budget--) { s->failed_pc=0x0c0cb07eu; return 0; }
r[17]=(r[17]&~1u)|((r[2]==r[0])!=0);
goto P_0c0cb080;
P_0c0cb080: /* original 8948, guest PC 0x0c0cb080 */
if(!s->budget--) { s->failed_pc=0x0c0cb080u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0cb114; }
goto P_0c0cb082;
P_0c0cb082: /* original 63f3, guest PC 0x0c0cb082 */
if(!s->budget--) { s->failed_pc=0x0c0cb082u; return 0; }
r[3]=r[15];
goto P_0c0cb084;
P_0c0cb084: /* original 7308, guest PC 0x0c0cb084 */
if(!s->budget--) { s->failed_pc=0x0c0cb084u; return 0; }
r[3]+=0x00000008u;
goto P_0c0cb086;
P_0c0cb086: /* original 2f36, guest PC 0x0c0cb086 */
if(!s->budget--) { s->failed_pc=0x0c0cb086u; return 0; }
r[15]-=4; write(ram,r[15],r[3],4);
goto P_0c0cb088;
P_0c0cb088: /* original 66f3, guest PC 0x0c0cb088 */
if(!s->budget--) { s->failed_pc=0x0c0cb088u; return 0; }
r[6]=r[15];
goto P_0c0cb08a;
P_0c0cb08a: /* original 65f3, guest PC 0x0c0cb08a */
if(!s->budget--) { s->failed_pc=0x0c0cb08au; return 0; }
r[5]=r[15];
goto P_0c0cb08c;
P_0c0cb08c: /* original 67f3, guest PC 0x0c0cb08c */
if(!s->budget--) { s->failed_pc=0x0c0cb08cu; return 0; }
r[7]=r[15];
goto P_0c0cb08e;
P_0c0cb08e: /* original d21d, guest PC 0x0c0cb08e */
if(!s->budget--) { s->failed_pc=0x0c0cb08eu; return 0; }
r[2]=read(ram,0x0c0cb104u,4);
goto P_0c0cb090;
P_0c0cb090: /* original 7504, guest PC 0x0c0cb090 */
if(!s->budget--) { s->failed_pc=0x0c0cb090u; return 0; }
r[5]+=0x00000004u;
goto P_0c0cb092;
P_0c0cb092: /* original 7710, guest PC 0x0c0cb092 */
if(!s->budget--) { s->failed_pc=0x0c0cb092u; return 0; }
r[7]+=0x00000010u;
goto P_0c0cb094;
P_0c0cb094: /* original 7608, guest PC 0x0c0cb094 */
if(!s->budget--) { s->failed_pc=0x0c0cb094u; return 0; }
r[6]+=0x00000008u;
goto P_0c0cb096;
P_0c0cb096: /* original 420b, guest PC 0x0c0cb096 */
if(!s->budget--) { s->failed_pc=0x0c0cb096u; return 0; }
target=r[2];
r[16]=0x0c0cb09au;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0cb09au) { target=s->pc; goto dispatch; }
goto P_0c0cb09a;
P_0c0cb098: /* original 64e3, guest PC 0x0c0cb098 */
if(!s->budget--) { s->failed_pc=0x0c0cb098u; return 0; }
r[4]=r[14];
goto P_0c0cb09a;
P_0c0cb09a: /* original 7f04, guest PC 0x0c0cb09a */
if(!s->budget--) { s->failed_pc=0x0c0cb09au; return 0; }
r[15]+=0x00000004u;
goto P_0c0cb09c;
P_0c0cb09c: /* original f3f8, guest PC 0x0c0cb09c */
if(!s->budget--) { s->failed_pc=0x0c0cb09cu; return 0; }
vf3_matrix_load(s,ram,3,r[15]);
goto P_0c0cb09e;
P_0c0cb09e: /* original e03c, guest PC 0x0c0cb09e */
if(!s->budget--) { s->failed_pc=0x0c0cb09eu; return 0; }
r[0]=0x0000003cu;
goto P_0c0cb0a0;
P_0c0cb0a0: /* original ff37, guest PC 0x0c0cb0a0 */
if(!s->budget--) { s->failed_pc=0x0c0cb0a0u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0cb0a2;
P_0c0cb0a2: /* original 54f2, guest PC 0x0c0cb0a2 */
if(!s->budget--) { s->failed_pc=0x0c0cb0a2u; return 0; }
r[4]=read(ram,r[15]+8,4);
goto P_0c0cb0a4;
P_0c0cb0a4: /* original d318, guest PC 0x0c0cb0a4 */
if(!s->budget--) { s->failed_pc=0x0c0cb0a4u; return 0; }
r[3]=read(ram,0x0c0cb108u,4);
goto P_0c0cb0a6;
P_0c0cb0a6: /* original 430b, guest PC 0x0c0cb0a6 */
if(!s->budget--) { s->failed_pc=0x0c0cb0a6u; return 0; }
target=r[3];
r[16]=0x0c0cb0aau;
r[4]=(uint32_t)(int32_t)(int16_t)r[4];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0cb0aau) { target=s->pc; goto dispatch; }
goto P_0c0cb0aa;
P_0c0cb0a8: /* original 644f, guest PC 0x0c0cb0a8 */
if(!s->budget--) { s->failed_pc=0x0c0cb0a8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)r[4];
goto P_0c0cb0aa;
P_0c0cb0aa: /* original ff0a, guest PC 0x0c0cb0aa */
if(!s->budget--) { s->failed_pc=0x0c0cb0aau; return 0; }
vf3_matrix_store(s,ram,0,r[15]);
goto P_0c0cb0ac;
P_0c0cb0ac: /* original d317, guest PC 0x0c0cb0ac */
if(!s->budget--) { s->failed_pc=0x0c0cb0acu; return 0; }
r[3]=read(ram,0x0c0cb10cu,4);
goto P_0c0cb0ae;
P_0c0cb0ae: /* original 54f2, guest PC 0x0c0cb0ae */
if(!s->budget--) { s->failed_pc=0x0c0cb0aeu; return 0; }
r[4]=read(ram,r[15]+8,4);
goto P_0c0cb0b0;
P_0c0cb0b0: /* original 430b, guest PC 0x0c0cb0b0 */
if(!s->budget--) { s->failed_pc=0x0c0cb0b0u; return 0; }
target=r[3];
r[16]=0x0c0cb0b4u;
r[4]=(uint32_t)(int32_t)(int16_t)r[4];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0cb0b4u) { target=s->pc; goto dispatch; }
goto P_0c0cb0b4;
P_0c0cb0b2: /* original 644f, guest PC 0x0c0cb0b2 */
if(!s->budget--) { s->failed_pc=0x0c0cb0b2u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)r[4];
goto P_0c0cb0b4;
P_0c0cb0b4: /* original c716, guest PC 0x0c0cb0b4 */
if(!s->budget--) { s->failed_pc=0x0c0cb0b4u; return 0; }
r[0]=0x0c0cb110u;
goto P_0c0cb0b6;
P_0c0cb0b6: /* original f70c, guest PC 0x0c0cb0b6 */
if(!s->budget--) { s->failed_pc=0x0c0cb0b6u; return 0; }
vf3_matrix_move(s,7,0);
goto P_0c0cb0b8;
P_0c0cb0b8: /* original f308, guest PC 0x0c0cb0b8 */
if(!s->budget--) { s->failed_pc=0x0c0cb0b8u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c0cb0ba;
P_0c0cb0ba: /* original e00c, guest PC 0x0c0cb0ba */
if(!s->budget--) { s->failed_pc=0x0c0cb0bau; return 0; }
r[0]=0x0000000cu;
goto P_0c0cb0bc;
P_0c0cb0bc: /* original ff37, guest PC 0x0c0cb0bc */
if(!s->budget--) { s->failed_pc=0x0c0cb0bcu; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0cb0be;
P_0c0cb0be: /* original e00c, guest PC 0x0c0cb0be */
if(!s->budget--) { s->failed_pc=0x0c0cb0beu; return 0; }
r[0]=0x0000000cu;
goto P_0c0cb0c0;
P_0c0cb0c0: /* original f3f8, guest PC 0x0c0cb0c0 */
if(!s->budget--) { s->failed_pc=0x0c0cb0c0u; return 0; }
vf3_matrix_load(s,ram,3,r[15]);
goto P_0c0cb0c2;
P_0c0cb0c2: /* original f34d, guest PC 0x0c0cb0c2 */
if(!s->budget--) { s->failed_pc=0x0c0cb0c2u; return 0; }
fr[3]^=0x80000000u;
goto P_0c0cb0c4;
P_0c0cb0c4: /* original ff3a, guest PC 0x0c0cb0c4 */
if(!s->budget--) { s->failed_pc=0x0c0cb0c4u; return 0; }
vf3_matrix_store(s,ram,3,r[15]);
goto P_0c0cb0c6;
P_0c0cb0c6: /* original f2f6, guest PC 0x0c0cb0c6 */
if(!s->budget--) { s->failed_pc=0x0c0cb0c6u; return 0; }
vf3_matrix_load(s,ram,2,r[15]+r[0]);
goto P_0c0cb0c8;
P_0c0cb0c8: /* original e03c, guest PC 0x0c0cb0c8 */
if(!s->budget--) { s->failed_pc=0x0c0cb0c8u; return 0; }
r[0]=0x0000003cu;
goto P_0c0cb0ca;
P_0c0cb0ca: /* original f1f6, guest PC 0x0c0cb0ca */
if(!s->budget--) { s->failed_pc=0x0c0cb0cau; return 0; }
vf3_matrix_load(s,ram,1,r[15]+r[0]);
goto P_0c0cb0cc;
P_0c0cb0cc: /* original e004, guest PC 0x0c0cb0cc */
if(!s->budget--) { s->failed_pc=0x0c0cb0ccu; return 0; }
r[0]=0x00000004u;
goto P_0c0cb0ce;
P_0c0cb0ce: /* original f63c, guest PC 0x0c0cb0ce */
if(!s->budget--) { s->failed_pc=0x0c0cb0ceu; return 0; }
vf3_matrix_move(s,6,3);
goto P_0c0cb0d0;
P_0c0cb0d0: /* original f622, guest PC 0x0c0cb0d0 */
if(!s->budget--) { s->failed_pc=0x0c0cb0d0u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[2],r[18],'*');
goto P_0c0cb0d2;
P_0c0cb0d2: /* original f722, guest PC 0x0c0cb0d2 */
if(!s->budget--) { s->failed_pc=0x0c0cb0d2u; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[2],r[18],'*');
goto P_0c0cb0d4;
P_0c0cb0d4: /* original ff1a, guest PC 0x0c0cb0d4 */
if(!s->budget--) { s->failed_pc=0x0c0cb0d4u; return 0; }
vf3_matrix_store(s,ram,1,r[15]);
goto P_0c0cb0d6;
P_0c0cb0d6: /* original f5f6, guest PC 0x0c0cb0d6 */
if(!s->budget--) { s->failed_pc=0x0c0cb0d6u; return 0; }
vf3_matrix_load(s,ram,5,r[15]+r[0]);
goto P_0c0cb0d8;
P_0c0cb0d8: /* original f54d, guest PC 0x0c0cb0d8 */
if(!s->budget--) { s->failed_pc=0x0c0cb0d8u; return 0; }
fr[5]^=0x80000000u;
goto P_0c0cb0da;
P_0c0cb0da: /* original b1ee, guest PC 0x0c0cb0da */
if(!s->budget--) { s->failed_pc=0x0c0cb0dau; return 0; }
target=0x0c0cb4bau; r[16]=0x0c0cb0deu;
vf3_matrix_move(s,4,1);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0cb0deu) { target=s->pc; goto dispatch; }
goto P_0c0cb0de;
P_0c0cb0dc: /* original f41c, guest PC 0x0c0cb0dc */
if(!s->budget--) { s->failed_pc=0x0c0cb0dcu; return 0; }
vf3_matrix_move(s,4,1);
goto P_0c0cb0de;
P_0c0cb0de: /* original e014, guest PC 0x0c0cb0de */
if(!s->budget--) { s->failed_pc=0x0c0cb0deu; return 0; }
r[0]=0x00000014u;
goto P_0c0cb0e0;
P_0c0cb0e0: /* original f40c, guest PC 0x0c0cb0e0 */
if(!s->budget--) { s->failed_pc=0x0c0cb0e0u; return 0; }
vf3_matrix_move(s,4,0);
goto P_0c0cb0e2;
P_0c0cb0e2: /* original ff47, guest PC 0x0c0cb0e2 */
if(!s->budget--) { s->failed_pc=0x0c0cb0e2u; return 0; }
vf3_matrix_store(s,ram,4,r[15]+r[0]);
goto P_0c0cb0e4;
P_0c0cb0e4: /* original 9006, guest PC 0x0c0cb0e4 */
if(!s->budget--) { s->failed_pc=0x0c0cb0e4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0cb0f4u,2);
goto P_0c0cb0e6;
P_0c0cb0e6: /* original f34c, guest PC 0x0c0cb0e6 */
if(!s->budget--) { s->failed_pc=0x0c0cb0e6u; return 0; }
vf3_matrix_move(s,3,4);
goto P_0c0cb0e8;
P_0c0cb0e8: /* original a018, guest PC 0x0c0cb0e8 */
if(!s->budget--) { s->failed_pc=0x0c0cb0e8u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c0cb11c;
P_0c0cb0ea: /* original fe37, guest PC 0x0c0cb0ea */
if(!s->budget--) { s->failed_pc=0x0c0cb0eau; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
return vf3_matrix_family(0x0c0cb0ecu,s,ram);
P_0c0cb114: /* original c743, guest PC 0x0c0cb114 */
if(!s->budget--) { s->failed_pc=0x0c0cb114u; return 0; }
r[0]=0x0c0cb224u;
goto P_0c0cb116;
P_0c0cb116: /* original f308, guest PC 0x0c0cb116 */
if(!s->budget--) { s->failed_pc=0x0c0cb116u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c0cb118;
P_0c0cb118: /* original e014, guest PC 0x0c0cb118 */
if(!s->budget--) { s->failed_pc=0x0c0cb118u; return 0; }
r[0]=0x00000014u;
goto P_0c0cb11a;
P_0c0cb11a: /* original ff37, guest PC 0x0c0cb11a */
if(!s->budget--) { s->failed_pc=0x0c0cb11au; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0cb11c;
P_0c0cb11c: /* original d342, guest PC 0x0c0cb11c */
if(!s->budget--) { s->failed_pc=0x0c0cb11cu; return 0; }
r[3]=read(ram,0x0c0cb228u,4);
goto P_0c0cb11e;
P_0c0cb11e: /* original 430b, guest PC 0x0c0cb11e */
if(!s->budget--) { s->failed_pc=0x0c0cb11eu; return 0; }
target=r[3];
r[16]=0x0c0cb122u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0cb122u) { target=s->pc; goto dispatch; }
goto P_0c0cb122;
P_0c0cb120: /* original 64e3, guest PC 0x0c0cb120 */
if(!s->budget--) { s->failed_pc=0x0c0cb120u; return 0; }
r[4]=r[14];
goto P_0c0cb122;
P_0c0cb122: /* original e206, guest PC 0x0c0cb122 */
if(!s->budget--) { s->failed_pc=0x0c0cb122u; return 0; }
r[2]=0x00000006u;
goto P_0c0cb124;
P_0c0cb124: /* original 1f2d, guest PC 0x0c0cb124 */
if(!s->budget--) { s->failed_pc=0x0c0cb124u; return 0; }
write(ram,r[15]+52,r[2],4);
goto P_0c0cb126;
P_0c0cb126: /* original ea00, guest PC 0x0c0cb126 */
if(!s->budget--) { s->failed_pc=0x0c0cb126u; return 0; }
r[10]=0x00000000u;
goto P_0c0cb128;
P_0c0cb128: /* original 9077, guest PC 0x0c0cb128 */
if(!s->budget--) { s->failed_pc=0x0c0cb128u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0cb21au,2);
goto P_0c0cb12a;
P_0c0cb12a: /* original 9377, guest PC 0x0c0cb12a */
if(!s->budget--) { s->failed_pc=0x0c0cb12au; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0cb21cu,2);
goto P_0c0cb12c;
P_0c0cb12c: /* original 08ee, guest PC 0x0c0cb12c */
if(!s->budget--) { s->failed_pc=0x0c0cb12cu; return 0; }
r[8]=read(ram,r[14]+r[0],4);
goto P_0c0cb12e;
P_0c0cb12e: /* original e054, guest PC 0x0c0cb12e */
if(!s->budget--) { s->failed_pc=0x0c0cb12eu; return 0; }
r[0]=0x00000054u;
goto P_0c0cb130;
P_0c0cb130: /* original 33ec, guest PC 0x0c0cb130 */
if(!s->budget--) { s->failed_pc=0x0c0cb130u; return 0; }
r[3]+=r[14];
goto P_0c0cb132;
P_0c0cb132: /* original 0f36, guest PC 0x0c0cb132 */
if(!s->budget--) { s->failed_pc=0x0c0cb132u; return 0; }
write(ram,r[15]+r[0],r[3],4);
goto P_0c0cb134;
P_0c0cb134: /* original c73e, guest PC 0x0c0cb134 */
if(!s->budget--) { s->failed_pc=0x0c0cb134u; return 0; }
r[0]=0x0c0cb230u;
goto P_0c0cb136;
P_0c0cb136: /* original 9272, guest PC 0x0c0cb136 */
if(!s->budget--) { s->failed_pc=0x0c0cb136u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0cb21eu,2);
goto P_0c0cb138;
P_0c0cb138: /* original 32ec, guest PC 0x0c0cb138 */
if(!s->budget--) { s->failed_pc=0x0c0cb138u; return 0; }
r[2]+=r[14];
goto P_0c0cb13a;
P_0c0cb13a: /* original 1f2c, guest PC 0x0c0cb13a */
if(!s->budget--) { s->failed_pc=0x0c0cb13au; return 0; }
write(ram,r[15]+48,r[2],4);
goto P_0c0cb13c;
P_0c0cb13c: /* original d33b, guest PC 0x0c0cb13c */
if(!s->budget--) { s->failed_pc=0x0c0cb13cu; return 0; }
r[3]=read(ram,0x0c0cb22cu,4);
goto P_0c0cb13e;
P_0c0cb13e: /* original 1f3e, guest PC 0x0c0cb13e */
if(!s->budget--) { s->failed_pc=0x0c0cb13eu; return 0; }
write(ram,r[15]+56,r[3],4);
goto P_0c0cb140;
P_0c0cb140: /* original f308, guest PC 0x0c0cb140 */
if(!s->budget--) { s->failed_pc=0x0c0cb140u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c0cb142;
P_0c0cb142: /* original e02c, guest PC 0x0c0cb142 */
if(!s->budget--) { s->failed_pc=0x0c0cb142u; return 0; }
r[0]=0x0000002cu;
goto P_0c0cb144;
P_0c0cb144: /* original ff37, guest PC 0x0c0cb144 */
if(!s->budget--) { s->failed_pc=0x0c0cb144u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0cb146;
P_0c0cb146: /* original c73b, guest PC 0x0c0cb146 */
if(!s->budget--) { s->failed_pc=0x0c0cb146u; return 0; }
r[0]=0x0c0cb234u;
goto P_0c0cb148;
P_0c0cb148: /* original f308, guest PC 0x0c0cb148 */
if(!s->budget--) { s->failed_pc=0x0c0cb148u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c0cb14a;
P_0c0cb14a: /* original e028, guest PC 0x0c0cb14a */
if(!s->budget--) { s->failed_pc=0x0c0cb14au; return 0; }
r[0]=0x00000028u;
goto P_0c0cb14c;
P_0c0cb14c: /* original ff37, guest PC 0x0c0cb14c */
if(!s->budget--) { s->failed_pc=0x0c0cb14cu; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0cb14e;
P_0c0cb14e: /* original e010, guest PC 0x0c0cb14e */
if(!s->budget--) { s->failed_pc=0x0c0cb14eu; return 0; }
r[0]=0x00000010u;
goto P_0c0cb150;
P_0c0cb150: /* original fc8d, guest PC 0x0c0cb150 */
if(!s->budget--) { s->failed_pc=0x0c0cb150u; return 0; }
fr[12]=0;
goto P_0c0cb152;
P_0c0cb152: /* original 5bfd, guest PC 0x0c0cb152 */
if(!s->budget--) { s->failed_pc=0x0c0cb152u; return 0; }
r[11]=read(ram,r[15]+52,4);
goto P_0c0cb154;
P_0c0cb154: /* original ffc7, guest PC 0x0c0cb154 */
if(!s->budget--) { s->failed_pc=0x0c0cb154u; return 0; }
vf3_matrix_store(s,ram,12,r[15]+r[0]);
goto P_0c0cb156;
P_0c0cb156: /* original e060, guest PC 0x0c0cb156 */
if(!s->budget--) { s->failed_pc=0x0c0cb156u; return 0; }
r[0]=0x00000060u;
goto P_0c0cb158;
P_0c0cb158: /* original ffc7, guest PC 0x0c0cb158 */
if(!s->budget--) { s->failed_pc=0x0c0cb158u; return 0; }
vf3_matrix_store(s,ram,12,r[15]+r[0]);
goto P_0c0cb15a;
P_0c0cb15a: /* original e064, guest PC 0x0c0cb15a */
if(!s->budget--) { s->failed_pc=0x0c0cb15au; return 0; }
r[0]=0x00000064u;
goto P_0c0cb15c;
P_0c0cb15c: /* original ffc7, guest PC 0x0c0cb15c */
if(!s->budget--) { s->failed_pc=0x0c0cb15cu; return 0; }
vf3_matrix_store(s,ram,12,r[15]+r[0]);
goto P_0c0cb15e;
P_0c0cb15e: /* original d336, guest PC 0x0c0cb15e */
if(!s->budget--) { s->failed_pc=0x0c0cb15eu; return 0; }
r[3]=read(ram,0x0c0cb238u,4);
goto P_0c0cb160;
P_0c0cb160: /* original 6030, guest PC 0x0c0cb160 */
if(!s->budget--) { s->failed_pc=0x0c0cb160u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[3],1);
r[0]=tmp;
goto P_0c0cb162;
P_0c0cb162: /* original 61f3, guest PC 0x0c0cb162 */
if(!s->budget--) { s->failed_pc=0x0c0cb162u; return 0; }
r[1]=r[15];
goto P_0c0cb164;
P_0c0cb164: /* original 600c, guest PC 0x0c0cb164 */
if(!s->budget--) { s->failed_pc=0x0c0cb164u; return 0; }
r[0]=r[0]&255u;
goto P_0c0cb166;
P_0c0cb166: /* original 7158, guest PC 0x0c0cb166 */
if(!s->budget--) { s->failed_pc=0x0c0cb166u; return 0; }
r[1]+=0x00000058u;
goto P_0c0cb168;
P_0c0cb168: /* original c90f, guest PC 0x0c0cb168 */
if(!s->budget--) { s->failed_pc=0x0c0cb168u; return 0; }
r[0]&=15u;
goto P_0c0cb16a;
P_0c0cb16a: /* original 2102, guest PC 0x0c0cb16a */
if(!s->budget--) { s->failed_pc=0x0c0cb16au; return 0; }
write(ram,r[1],r[0],4);
goto P_0c0cb16c;
P_0c0cb16c: /* original 53fd, guest PC 0x0c0cb16c */
if(!s->budget--) { s->failed_pc=0x0c0cb16cu; return 0; }
r[3]=read(ram,r[15]+52,4);
goto P_0c0cb16e;
P_0c0cb16e: /* original 33b8, guest PC 0x0c0cb16e */
if(!s->budget--) { s->failed_pc=0x0c0cb16eu; return 0; }
r[3]-=r[11];
goto P_0c0cb170;
P_0c0cb170: /* original 1f32, guest PC 0x0c0cb170 */
if(!s->budget--) { s->failed_pc=0x0c0cb170u; return 0; }
write(ram,r[15]+8,r[3],4);
goto P_0c0cb172;
P_0c0cb172: /* original 54fe, guest PC 0x0c0cb172 */
if(!s->budget--) { s->failed_pc=0x0c0cb172u; return 0; }
r[4]=read(ram,r[15]+56,4);
goto P_0c0cb174;
P_0c0cb174: /* original d231, guest PC 0x0c0cb174 */
if(!s->budget--) { s->failed_pc=0x0c0cb174u; return 0; }
r[2]=read(ram,0x0c0cb23cu,4);
goto P_0c0cb176;
P_0c0cb176: /* original 343c, guest PC 0x0c0cb176 */
if(!s->budget--) { s->failed_pc=0x0c0cb176u; return 0; }
r[4]+=r[3];
goto P_0c0cb178;
P_0c0cb178: /* original 6140, guest PC 0x0c0cb178 */
if(!s->budget--) { s->failed_pc=0x0c0cb178u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[4],1);
r[1]=tmp;
goto P_0c0cb17a;
P_0c0cb17a: /* original 420b, guest PC 0x0c0cb17a */
if(!s->budget--) { s->failed_pc=0x0c0cb17au; return 0; }
target=r[2];
r[16]=0x0c0cb17eu;
r[0]=0x00000004u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0cb17eu) { target=s->pc; goto dispatch; }
goto P_0c0cb17e;
P_0c0cb17c: /* original e004, guest PC 0x0c0cb17c */
if(!s->budget--) { s->failed_pc=0x0c0cb17cu; return 0; }
r[0]=0x00000004u;
goto P_0c0cb17e;
P_0c0cb17e: /* original 6403, guest PC 0x0c0cb17e */
if(!s->budget--) { s->failed_pc=0x0c0cb17eu; return 0; }
r[4]=r[0];
goto P_0c0cb180;
P_0c0cb180: /* original e054, guest PC 0x0c0cb180 */
if(!s->budget--) { s->failed_pc=0x0c0cb180u; return 0; }
r[0]=0x00000054u;
goto P_0c0cb182;
P_0c0cb182: /* original 654e, guest PC 0x0c0cb182 */
if(!s->budget--) { s->failed_pc=0x0c0cb182u; return 0; }
r[5]=(uint32_t)(int32_t)(int8_t)r[4];
goto P_0c0cb184;
P_0c0cb184: /* original 02fe, guest PC 0x0c0cb184 */
if(!s->budget--) { s->failed_pc=0x0c0cb184u; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c0cb186;
P_0c0cb186: /* original 4500, guest PC 0x0c0cb186 */
if(!s->budget--) { s->failed_pc=0x0c0cb186u; return 0; }
r[17]=(r[17]&~1u)|((r[5]>>31)!=0);
r[5]<<=1;
goto P_0c0cb188;
P_0c0cb188: /* original 4508, guest PC 0x0c0cb188 */
if(!s->budget--) { s->failed_pc=0x0c0cb188u; return 0; }
r[5]<<=2;
goto P_0c0cb18a;
P_0c0cb18a: /* original 352c, guest PC 0x0c0cb18a */
if(!s->budget--) { s->failed_pc=0x0c0cb18au; return 0; }
r[5]+=r[2];
goto P_0c0cb18c;
P_0c0cb18c: /* original 634e, guest PC 0x0c0cb18c */
if(!s->budget--) { s->failed_pc=0x0c0cb18cu; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)r[4];
goto P_0c0cb18e;
P_0c0cb18e: /* original ff58, guest PC 0x0c0cb18e */
if(!s->budget--) { s->failed_pc=0x0c0cb18eu; return 0; }
vf3_matrix_load(s,ram,15,r[5]);
goto P_0c0cb190;
P_0c0cb190: /* original 4308, guest PC 0x0c0cb190 */
if(!s->budget--) { s->failed_pc=0x0c0cb190u; return 0; }
r[3]<<=2;
goto P_0c0cb192;
P_0c0cb192: /* original e004, guest PC 0x0c0cb192 */
if(!s->budget--) { s->failed_pc=0x0c0cb192u; return 0; }
r[0]=0x00000004u;
goto P_0c0cb194;
P_0c0cb194: /* original fe56, guest PC 0x0c0cb194 */
if(!s->budget--) { s->failed_pc=0x0c0cb194u; return 0; }
vf3_matrix_load(s,ram,14,r[5]+r[0]);
goto P_0c0cb196;
P_0c0cb196: /* original 654e, guest PC 0x0c0cb196 */
if(!s->budget--) { s->failed_pc=0x0c0cb196u; return 0; }
r[5]=(uint32_t)(int32_t)(int8_t)r[4];
goto P_0c0cb198;
P_0c0cb198: /* original 1f36, guest PC 0x0c0cb198 */
if(!s->budget--) { s->failed_pc=0x0c0cb198u; return 0; }
write(ram,r[15]+24,r[3],4);
goto P_0c0cb19a;
P_0c0cb19a: /* original e020, guest PC 0x0c0cb19a */
if(!s->budget--) { s->failed_pc=0x0c0cb19au; return 0; }
r[0]=0x00000020u;
goto P_0c0cb19c;
P_0c0cb19c: /* original 9240, guest PC 0x0c0cb19c */
if(!s->budget--) { s->failed_pc=0x0c0cb19cu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0cb220u,2);
goto P_0c0cb19e;
P_0c0cb19e: /* original 32ec, guest PC 0x0c0cb19e */
if(!s->budget--) { s->failed_pc=0x0c0cb19eu; return 0; }
r[2]+=r[14];
goto P_0c0cb1a0;
P_0c0cb1a0: /* original 332c, guest PC 0x0c0cb1a0 */
if(!s->budget--) { s->failed_pc=0x0c0cb1a0u; return 0; }
r[3]+=r[2];
goto P_0c0cb1a2;
P_0c0cb1a2: /* original f638, guest PC 0x0c0cb1a2 */
if(!s->budget--) { s->failed_pc=0x0c0cb1a2u; return 0; }
vf3_matrix_load(s,ram,6,r[3]);
goto P_0c0cb1a4;
P_0c0cb1a4: /* original 6353, guest PC 0x0c0cb1a4 */
if(!s->budget--) { s->failed_pc=0x0c0cb1a4u; return 0; }
r[3]=r[5];
goto P_0c0cb1a6;
P_0c0cb1a6: /* original 4500, guest PC 0x0c0cb1a6 */
if(!s->budget--) { s->failed_pc=0x0c0cb1a6u; return 0; }
r[17]=(r[17]&~1u)|((r[5]>>31)!=0);
r[5]<<=1;
goto P_0c0cb1a8;
P_0c0cb1a8: /* original 353c, guest PC 0x0c0cb1a8 */
if(!s->budget--) { s->failed_pc=0x0c0cb1a8u; return 0; }
r[5]+=r[3];
goto P_0c0cb1aa;
P_0c0cb1aa: /* original 4508, guest PC 0x0c0cb1aa */
if(!s->budget--) { s->failed_pc=0x0c0cb1aau; return 0; }
r[5]<<=2;
goto P_0c0cb1ac;
P_0c0cb1ac: /* original 358c, guest PC 0x0c0cb1ac */
if(!s->budget--) { s->failed_pc=0x0c0cb1acu; return 0; }
r[5]+=r[8];
goto P_0c0cb1ae;
P_0c0cb1ae: /* original f358, guest PC 0x0c0cb1ae */
if(!s->budget--) { s->failed_pc=0x0c0cb1aeu; return 0; }
vf3_matrix_load(s,ram,3,r[5]);
goto P_0c0cb1b0;
P_0c0cb1b0: /* original ff37, guest PC 0x0c0cb1b0 */
if(!s->budget--) { s->failed_pc=0x0c0cb1b0u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0cb1b2;
P_0c0cb1b2: /* original e004, guest PC 0x0c0cb1b2 */
if(!s->budget--) { s->failed_pc=0x0c0cb1b2u; return 0; }
r[0]=0x00000004u;
goto P_0c0cb1b4;
P_0c0cb1b4: /* original f356, guest PC 0x0c0cb1b4 */
if(!s->budget--) { s->failed_pc=0x0c0cb1b4u; return 0; }
vf3_matrix_load(s,ram,3,r[5]+r[0]);
goto P_0c0cb1b6;
P_0c0cb1b6: /* original e008, guest PC 0x0c0cb1b6 */
if(!s->budget--) { s->failed_pc=0x0c0cb1b6u; return 0; }
r[0]=0x00000008u;
goto P_0c0cb1b8;
P_0c0cb1b8: /* original ff3a, guest PC 0x0c0cb1b8 */
if(!s->budget--) { s->failed_pc=0x0c0cb1b8u; return 0; }
vf3_matrix_store(s,ram,3,r[15]);
goto P_0c0cb1ba;
P_0c0cb1ba: /* original f356, guest PC 0x0c0cb1ba */
if(!s->budget--) { s->failed_pc=0x0c0cb1bau; return 0; }
vf3_matrix_load(s,ram,3,r[5]+r[0]);
goto P_0c0cb1bc;
P_0c0cb1bc: /* original e01c, guest PC 0x0c0cb1bc */
if(!s->budget--) { s->failed_pc=0x0c0cb1bcu; return 0; }
r[0]=0x0000001cu;
goto P_0c0cb1be;
P_0c0cb1be: /* original ff37, guest PC 0x0c0cb1be */
if(!s->budget--) { s->failed_pc=0x0c0cb1beu; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0cb1c0;
P_0c0cb1c0: /* original f5fc, guest PC 0x0c0cb1c0 */
if(!s->budget--) { s->failed_pc=0x0c0cb1c0u; return 0; }
vf3_matrix_move(s,5,15);
goto P_0c0cb1c2;
P_0c0cb1c2: /* original f4fc, guest PC 0x0c0cb1c2 */
if(!s->budget--) { s->failed_pc=0x0c0cb1c2u; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c0cb1c4;
P_0c0cb1c4: /* original f542, guest PC 0x0c0cb1c4 */
if(!s->budget--) { s->failed_pc=0x0c0cb1c4u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[4],r[18],'*');
goto P_0c0cb1c6;
P_0c0cb1c6: /* original f0ec, guest PC 0x0c0cb1c6 */
if(!s->budget--) { s->failed_pc=0x0c0cb1c6u; return 0; }
vf3_matrix_move(s,0,14);
goto P_0c0cb1c8;
P_0c0cb1c8: /* original fdec, guest PC 0x0c0cb1c8 */
if(!s->budget--) { s->failed_pc=0x0c0cb1c8u; return 0; }
vf3_matrix_move(s,13,14);
goto P_0c0cb1ca;
P_0c0cb1ca: /* original 50f6, guest PC 0x0c0cb1ca */
if(!s->budget--) { s->failed_pc=0x0c0cb1cau; return 0; }
r[0]=read(ram,r[15]+24,4);
goto P_0c0cb1cc;
P_0c0cb1cc: /* original f35c, guest PC 0x0c0cb1cc */
if(!s->budget--) { s->failed_pc=0x0c0cb1ccu; return 0; }
vf3_matrix_move(s,3,5);
goto P_0c0cb1ce;
P_0c0cb1ce: /* original f3de, guest PC 0x0c0cb1ce */
if(!s->budget--) { s->failed_pc=0x0c0cb1ceu; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[13],fr[3],r[18]);
goto P_0c0cb1d0;
P_0c0cb1d0: /* original 53fc, guest PC 0x0c0cb1d0 */
if(!s->budget--) { s->failed_pc=0x0c0cb1d0u; return 0; }
r[3]=read(ram,r[15]+48,4);
goto P_0c0cb1d2;
P_0c0cb1d2: /* original f53c, guest PC 0x0c0cb1d2 */
if(!s->budget--) { s->failed_pc=0x0c0cb1d2u; return 0; }
vf3_matrix_move(s,5,3);
goto P_0c0cb1d4;
P_0c0cb1d4: /* original f357, guest PC 0x0c0cb1d4 */
if(!s->budget--) { s->failed_pc=0x0c0cb1d4u; return 0; }
vf3_matrix_store(s,ram,5,r[3]+r[0]);
goto P_0c0cb1d6;
P_0c0cb1d6: /* original e014, guest PC 0x0c0cb1d6 */
if(!s->budget--) { s->failed_pc=0x0c0cb1d6u; return 0; }
r[0]=0x00000014u;
goto P_0c0cb1d8;
P_0c0cb1d8: /* original f3f8, guest PC 0x0c0cb1d8 */
if(!s->budget--) { s->failed_pc=0x0c0cb1d8u; return 0; }
vf3_matrix_load(s,ram,3,r[15]);
goto P_0c0cb1da;
P_0c0cb1da: /* original f361, guest PC 0x0c0cb1da */
if(!s->budget--) { s->failed_pc=0x0c0cb1dau; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[6],r[18],'-');
goto P_0c0cb1dc;
P_0c0cb1dc: /* original ff3a, guest PC 0x0c0cb1dc */
if(!s->budget--) { s->failed_pc=0x0c0cb1dcu; return 0; }
vf3_matrix_store(s,ram,3,r[15]);
goto P_0c0cb1de;
P_0c0cb1de: /* original f2f6, guest PC 0x0c0cb1de */
if(!s->budget--) { s->failed_pc=0x0c0cb1deu; return 0; }
vf3_matrix_load(s,ram,2,r[15]+r[0]);
goto P_0c0cb1e0;
P_0c0cb1e0: /* original f325, guest PC 0x0c0cb1e0 */
if(!s->budget--) { s->failed_pc=0x0c0cb1e0u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[2]))!=0);
goto P_0c0cb1e2;
P_0c0cb1e2: /* original 8b01, guest PC 0x0c0cb1e2 */
if(!s->budget--) { s->failed_pc=0x0c0cb1e2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0cb1e8; }
goto P_0c0cb1e4;
P_0c0cb1e4: /* original a0b6, guest PC 0x0c0cb1e4 */
if(!s->budget--) { s->failed_pc=0x0c0cb1e4u; return 0; }
goto P_0c0cb354;
P_0c0cb1e6: /* original 0009, guest PC 0x0c0cb1e6 */
if(!s->budget--) { s->failed_pc=0x0c0cb1e6u; return 0; }
goto P_0c0cb1e8;
P_0c0cb1e8: /* original e02c, guest PC 0x0c0cb1e8 */
if(!s->budget--) { s->failed_pc=0x0c0cb1e8u; return 0; }
r[0]=0x0000002cu;
goto P_0c0cb1ea;
P_0c0cb1ea: /* original f3f6, guest PC 0x0c0cb1ea */
if(!s->budget--) { s->failed_pc=0x0c0cb1eau; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0cb1ec;
P_0c0cb1ec: /* original f3f5, guest PC 0x0c0cb1ec */
if(!s->budget--) { s->failed_pc=0x0c0cb1ecu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[15]))!=0);
goto P_0c0cb1ee;
P_0c0cb1ee: /* original 8b0d, guest PC 0x0c0cb1ee */
if(!s->budget--) { s->failed_pc=0x0c0cb1eeu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0cb20c; }
goto P_0c0cb1f0;
P_0c0cb1f0: /* original e028, guest PC 0x0c0cb1f0 */
if(!s->budget--) { s->failed_pc=0x0c0cb1f0u; return 0; }
r[0]=0x00000028u;
goto P_0c0cb1f2;
P_0c0cb1f2: /* original f3f6, guest PC 0x0c0cb1f2 */
if(!s->budget--) { s->failed_pc=0x0c0cb1f2u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0cb1f4;
P_0c0cb1f4: /* original ff35, guest PC 0x0c0cb1f4 */
if(!s->budget--) { s->failed_pc=0x0c0cb1f4u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[15])>as_float(fr[3]))!=0);
goto P_0c0cb1f6;
P_0c0cb1f6: /* original 8b09, guest PC 0x0c0cb1f6 */
if(!s->budget--) { s->failed_pc=0x0c0cb1f6u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0cb20c; }
goto P_0c0cb1f8;
P_0c0cb1f8: /* original e02c, guest PC 0x0c0cb1f8 */
if(!s->budget--) { s->failed_pc=0x0c0cb1f8u; return 0; }
r[0]=0x0000002cu;
goto P_0c0cb1fa;
P_0c0cb1fa: /* original f3f6, guest PC 0x0c0cb1fa */
if(!s->budget--) { s->failed_pc=0x0c0cb1fau; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0cb1fc;
P_0c0cb1fc: /* original f3e5, guest PC 0x0c0cb1fc */
if(!s->budget--) { s->failed_pc=0x0c0cb1fcu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[14]))!=0);
goto P_0c0cb1fe;
P_0c0cb1fe: /* original 8b05, guest PC 0x0c0cb1fe */
if(!s->budget--) { s->failed_pc=0x0c0cb1feu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0cb20c; }
goto P_0c0cb200;
P_0c0cb200: /* original e028, guest PC 0x0c0cb200 */
if(!s->budget--) { s->failed_pc=0x0c0cb200u; return 0; }
r[0]=0x00000028u;
goto P_0c0cb202;
P_0c0cb202: /* original f3f6, guest PC 0x0c0cb202 */
if(!s->budget--) { s->failed_pc=0x0c0cb202u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0cb204;
P_0c0cb204: /* original fe35, guest PC 0x0c0cb204 */
if(!s->budget--) { s->failed_pc=0x0c0cb204u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[14])>as_float(fr[3]))!=0);
goto P_0c0cb206;
P_0c0cb206: /* original 8b01, guest PC 0x0c0cb206 */
if(!s->budget--) { s->failed_pc=0x0c0cb206u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0cb20c; }
goto P_0c0cb208;
P_0c0cb208: /* original a0a4, guest PC 0x0c0cb208 */
if(!s->budget--) { s->failed_pc=0x0c0cb208u; return 0; }
goto P_0c0cb354;
P_0c0cb20a: /* original 0009, guest PC 0x0c0cb20a */
if(!s->budget--) { s->failed_pc=0x0c0cb20au; return 0; }
goto P_0c0cb20c;
P_0c0cb20c: /* original c70c, guest PC 0x0c0cb20c */
if(!s->budget--) { s->failed_pc=0x0c0cb20cu; return 0; }
r[0]=0x0c0cb240u;
goto P_0c0cb20e;
P_0c0cb20e: /* original f308, guest PC 0x0c0cb20e */
if(!s->budget--) { s->failed_pc=0x0c0cb20eu; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c0cb210;
P_0c0cb210: /* original f355, guest PC 0x0c0cb210 */
if(!s->budget--) { s->failed_pc=0x0c0cb210u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[5]))!=0);
goto P_0c0cb212;
P_0c0cb212: /* original 8f17, guest PC 0x0c0cb212 */
if(!s->budget--) { s->failed_pc=0x0c0cb212u; return 0; }
cond=r[17]&1u;
vf3_matrix_move(s,3,4);
if(!cond) { goto P_0c0cb244; }
goto P_0c0cb216;
P_0c0cb214: /* original f34c, guest PC 0x0c0cb214 */
if(!s->budget--) { s->failed_pc=0x0c0cb214u; return 0; }
vf3_matrix_move(s,3,4);
goto P_0c0cb216;
P_0c0cb216: /* original a016, guest PC 0x0c0cb216 */
if(!s->budget--) { s->failed_pc=0x0c0cb216u; return 0; }
fr[5]=0;
goto P_0c0cb246;
P_0c0cb218: /* original f58d, guest PC 0x0c0cb218 */
if(!s->budget--) { s->failed_pc=0x0c0cb218u; return 0; }
fr[5]=0;
return vf3_matrix_family(0x0c0cb21au,s,ram);
P_0c0cb244: /* original f57d, guest PC 0x0c0cb244 */
if(!s->budget--) { s->failed_pc=0x0c0cb244u; return 0; }
if(!vf3_fpu_fsrra(fr[5],r[18],&fr[5])) goto unsupported;
goto P_0c0cb246;
P_0c0cb246: /* original f45c, guest PC 0x0c0cb246 */
if(!s->budget--) { s->failed_pc=0x0c0cb246u; return 0; }
vf3_matrix_move(s,4,5);
goto P_0c0cb248;
P_0c0cb248: /* original f432, guest PC 0x0c0cb248 */
if(!s->budget--) { s->failed_pc=0x0c0cb248u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'*');
goto P_0c0cb24a;
P_0c0cb24a: /* original e024, guest PC 0x0c0cb24a */
if(!s->budget--) { s->failed_pc=0x0c0cb24au; return 0; }
r[0]=0x00000024u;
goto P_0c0cb24c;
P_0c0cb24c: /* original f3dc, guest PC 0x0c0cb24c */
if(!s->budget--) { s->failed_pc=0x0c0cb24cu; return 0; }
vf3_matrix_move(s,3,13);
goto P_0c0cb24e;
P_0c0cb24e: /* original fd5c, guest PC 0x0c0cb24e */
if(!s->budget--) { s->failed_pc=0x0c0cb24eu; return 0; }
vf3_matrix_move(s,13,5);
goto P_0c0cb250;
P_0c0cb250: /* original fd32, guest PC 0x0c0cb250 */
if(!s->budget--) { s->failed_pc=0x0c0cb250u; return 0; }
fr[13]=vf3_fpu_binary(fr[13],fr[3],r[18],'*');
goto P_0c0cb252;
P_0c0cb252: /* original f44d, guest PC 0x0c0cb252 */
if(!s->budget--) { s->failed_pc=0x0c0cb252u; return 0; }
fr[4]^=0x80000000u;
goto P_0c0cb254;
P_0c0cb254: /* original ff47, guest PC 0x0c0cb254 */
if(!s->budget--) { s->failed_pc=0x0c0cb254u; return 0; }
vf3_matrix_store(s,ram,4,r[15]+r[0]);
goto P_0c0cb256;
P_0c0cb256: /* original e020, guest PC 0x0c0cb256 */
if(!s->budget--) { s->failed_pc=0x0c0cb256u; return 0; }
r[0]=0x00000020u;
goto P_0c0cb258;
P_0c0cb258: /* original f3f6, guest PC 0x0c0cb258 */
if(!s->budget--) { s->failed_pc=0x0c0cb258u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0cb25a;
P_0c0cb25a: /* original e01c, guest PC 0x0c0cb25a */
if(!s->budget--) { s->failed_pc=0x0c0cb25au; return 0; }
r[0]=0x0000001cu;
goto P_0c0cb25c;
P_0c0cb25c: /* original f06c, guest PC 0x0c0cb25c */
if(!s->budget--) { s->failed_pc=0x0c0cb25cu; return 0; }
vf3_matrix_move(s,0,6);
goto P_0c0cb25e;
P_0c0cb25e: /* original f24c, guest PC 0x0c0cb25e */
if(!s->budget--) { s->failed_pc=0x0c0cb25eu; return 0; }
vf3_matrix_move(s,2,4);
goto P_0c0cb260;
P_0c0cb260: /* original f32e, guest PC 0x0c0cb260 */
if(!s->budget--) { s->failed_pc=0x0c0cb260u; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[2],fr[3],r[18]);
goto P_0c0cb262;
P_0c0cb262: /* original ff3a, guest PC 0x0c0cb262 */
if(!s->budget--) { s->failed_pc=0x0c0cb262u; return 0; }
vf3_matrix_store(s,ram,3,r[15]);
goto P_0c0cb264;
P_0c0cb264: /* original f2f6, guest PC 0x0c0cb264 */
if(!s->budget--) { s->failed_pc=0x0c0cb264u; return 0; }
vf3_matrix_load(s,ram,2,r[15]+r[0]);
goto P_0c0cb266;
P_0c0cb266: /* original e004, guest PC 0x0c0cb266 */
if(!s->budget--) { s->failed_pc=0x0c0cb266u; return 0; }
r[0]=0x00000004u;
goto P_0c0cb268;
P_0c0cb268: /* original f2de, guest PC 0x0c0cb268 */
if(!s->budget--) { s->failed_pc=0x0c0cb268u; return 0; }
fr[2]=vf3_fpu_mac(fr[0],fr[13],fr[2],r[18]);
goto P_0c0cb26a;
P_0c0cb26a: /* original ff27, guest PC 0x0c0cb26a */
if(!s->budget--) { s->failed_pc=0x0c0cb26au; return 0; }
vf3_matrix_store(s,ram,2,r[15]+r[0]);
goto P_0c0cb26c;
P_0c0cb26c: /* original d333, guest PC 0x0c0cb26c */
if(!s->budget--) { s->failed_pc=0x0c0cb26cu; return 0; }
r[3]=read(ram,0x0c0cb33cu,4);
goto P_0c0cb26e;
P_0c0cb26e: /* original 6030, guest PC 0x0c0cb26e */
if(!s->budget--) { s->failed_pc=0x0c0cb26eu; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[3],1);
r[0]=tmp;
goto P_0c0cb270;
P_0c0cb270: /* original 600c, guest PC 0x0c0cb270 */
if(!s->budget--) { s->failed_pc=0x0c0cb270u; return 0; }
r[0]=r[0]&255u;
goto P_0c0cb272;
P_0c0cb272: /* original c90f, guest PC 0x0c0cb272 */
if(!s->budget--) { s->failed_pc=0x0c0cb272u; return 0; }
r[0]&=15u;
goto P_0c0cb274;
P_0c0cb274: /* original 8809, guest PC 0x0c0cb274 */
if(!s->budget--) { s->failed_pc=0x0c0cb274u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000009u)!=0);
goto P_0c0cb276;
P_0c0cb276: /* original 8b11, guest PC 0x0c0cb276 */
if(!s->budget--) { s->failed_pc=0x0c0cb276u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0cb29c; }
goto P_0c0cb278;
P_0c0cb278: /* original c731, guest PC 0x0c0cb278 */
if(!s->budget--) { s->failed_pc=0x0c0cb278u; return 0; }
r[0]=0x0c0cb340u;
goto P_0c0cb27a;
P_0c0cb27a: /* original f308, guest PC 0x0c0cb27a */
if(!s->budget--) { s->failed_pc=0x0c0cb27au; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c0cb27c;
P_0c0cb27c: /* original 905d, guest PC 0x0c0cb27c */
if(!s->budget--) { s->failed_pc=0x0c0cb27cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0cb33au,2);
goto P_0c0cb27e;
P_0c0cb27e: /* original f2e6, guest PC 0x0c0cb27e */
if(!s->budget--) { s->failed_pc=0x0c0cb27eu; return 0; }
vf3_matrix_load(s,ram,2,r[14]+r[0]);
goto P_0c0cb280;
P_0c0cb280: /* original f235, guest PC 0x0c0cb280 */
if(!s->budget--) { s->failed_pc=0x0c0cb280u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[2])>as_float(fr[3]))!=0);
goto P_0c0cb282;
P_0c0cb282: /* original 8b0b, guest PC 0x0c0cb282 */
if(!s->budget--) { s->failed_pc=0x0c0cb282u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0cb29c; }
goto P_0c0cb284;
P_0c0cb284: /* original c72f, guest PC 0x0c0cb284 */
if(!s->budget--) { s->failed_pc=0x0c0cb284u; return 0; }
r[0]=0x0c0cb344u;
goto P_0c0cb286;
P_0c0cb286: /* original d330, guest PC 0x0c0cb286 */
if(!s->budget--) { s->failed_pc=0x0c0cb286u; return 0; }
r[3]=read(ram,0x0c0cb348u,4);
goto P_0c0cb288;
P_0c0cb288: /* original f308, guest PC 0x0c0cb288 */
if(!s->budget--) { s->failed_pc=0x0c0cb288u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c0cb28a;
P_0c0cb28a: /* original e004, guest PC 0x0c0cb28a */
if(!s->budget--) { s->failed_pc=0x0c0cb28au; return 0; }
r[0]=0x00000004u;
goto P_0c0cb28c;
P_0c0cb28c: /* original f5f6, guest PC 0x0c0cb28c */
if(!s->budget--) { s->failed_pc=0x0c0cb28cu; return 0; }
vf3_matrix_load(s,ram,5,r[15]+r[0]);
goto P_0c0cb28e;
P_0c0cb28e: /* original 64f3, guest PC 0x0c0cb28e */
if(!s->budget--) { s->failed_pc=0x0c0cb28eu; return 0; }
r[4]=r[15];
goto P_0c0cb290;
P_0c0cb290: /* original 7468, guest PC 0x0c0cb290 */
if(!s->budget--) { s->failed_pc=0x0c0cb290u; return 0; }
r[4]+=0x00000068u;
goto P_0c0cb292;
P_0c0cb292: /* original f530, guest PC 0x0c0cb292 */
if(!s->budget--) { s->failed_pc=0x0c0cb292u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[3],r[18],'+');
goto P_0c0cb294;
P_0c0cb294: /* original 430b, guest PC 0x0c0cb294 */
if(!s->budget--) { s->failed_pc=0x0c0cb294u; return 0; }
target=r[3];
r[16]=0x0c0cb298u;
vf3_matrix_load(s,ram,4,r[15]);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0cb298u) { target=s->pc; goto dispatch; }
goto P_0c0cb298;
P_0c0cb296: /* original f4f8, guest PC 0x0c0cb296 */
if(!s->budget--) { s->failed_pc=0x0c0cb296u; return 0; }
vf3_matrix_load(s,ram,4,r[15]);
goto P_0c0cb298;
P_0c0cb298: /* original a007, guest PC 0x0c0cb298 */
if(!s->budget--) { s->failed_pc=0x0c0cb298u; return 0; }
goto P_0c0cb2aa;
P_0c0cb29a: /* original 0009, guest PC 0x0c0cb29a */
if(!s->budget--) { s->failed_pc=0x0c0cb29au; return 0; }
goto P_0c0cb29c;
P_0c0cb29c: /* original e004, guest PC 0x0c0cb29c */
if(!s->budget--) { s->failed_pc=0x0c0cb29cu; return 0; }
r[0]=0x00000004u;
goto P_0c0cb29e;
P_0c0cb29e: /* original d32a, guest PC 0x0c0cb29e */
if(!s->budget--) { s->failed_pc=0x0c0cb29eu; return 0; }
r[3]=read(ram,0x0c0cb348u,4);
goto P_0c0cb2a0;
P_0c0cb2a0: /* original f5f6, guest PC 0x0c0cb2a0 */
if(!s->budget--) { s->failed_pc=0x0c0cb2a0u; return 0; }
vf3_matrix_load(s,ram,5,r[15]+r[0]);
goto P_0c0cb2a2;
P_0c0cb2a2: /* original 64f3, guest PC 0x0c0cb2a2 */
if(!s->budget--) { s->failed_pc=0x0c0cb2a2u; return 0; }
r[4]=r[15];
goto P_0c0cb2a4;
P_0c0cb2a4: /* original 7468, guest PC 0x0c0cb2a4 */
if(!s->budget--) { s->failed_pc=0x0c0cb2a4u; return 0; }
r[4]+=0x00000068u;
goto P_0c0cb2a6;
P_0c0cb2a6: /* original 430b, guest PC 0x0c0cb2a6 */
if(!s->budget--) { s->failed_pc=0x0c0cb2a6u; return 0; }
target=r[3];
r[16]=0x0c0cb2aau;
vf3_matrix_load(s,ram,4,r[15]);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0cb2aau) { target=s->pc; goto dispatch; }
goto P_0c0cb2aa;
P_0c0cb2a8: /* original f4f8, guest PC 0x0c0cb2a8 */
if(!s->budget--) { s->failed_pc=0x0c0cb2a8u; return 0; }
vf3_matrix_load(s,ram,4,r[15]);
goto P_0c0cb2aa;
P_0c0cb2aa: /* original 6303, guest PC 0x0c0cb2aa */
if(!s->budget--) { s->failed_pc=0x0c0cb2aau; return 0; }
r[3]=r[0];
goto P_0c0cb2ac;
P_0c0cb2ac: /* original 1f02, guest PC 0x0c0cb2ac */
if(!s->budget--) { s->failed_pc=0x0c0cb2acu; return 0; }
write(ram,r[15]+8,r[0],4);
goto P_0c0cb2ae;
P_0c0cb2ae: /* original e040, guest PC 0x0c0cb2ae */
if(!s->budget--) { s->failed_pc=0x0c0cb2aeu; return 0; }
r[0]=0x00000040u;
goto P_0c0cb2b0;
P_0c0cb2b0: /* original 02fe, guest PC 0x0c0cb2b0 */
if(!s->budget--) { s->failed_pc=0x0c0cb2b0u; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c0cb2b2;
P_0c0cb2b2: /* original 2238, guest PC 0x0c0cb2b2 */
if(!s->budget--) { s->failed_pc=0x0c0cb2b2u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c0cb2b4;
P_0c0cb2b4: /* original 8b04, guest PC 0x0c0cb2b4 */
if(!s->budget--) { s->failed_pc=0x0c0cb2b4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0cb2c0; }
goto P_0c0cb2b6;
P_0c0cb2b6: /* original 50f6, guest PC 0x0c0cb2b6 */
if(!s->budget--) { s->failed_pc=0x0c0cb2b6u; return 0; }
r[0]=read(ram,r[15]+24,4);
goto P_0c0cb2b8;
P_0c0cb2b8: /* original 51fc, guest PC 0x0c0cb2b8 */
if(!s->budget--) { s->failed_pc=0x0c0cb2b8u; return 0; }
r[1]=read(ram,r[15]+48,4);
goto P_0c0cb2ba;
P_0c0cb2ba: /* original f38d, guest PC 0x0c0cb2ba */
if(!s->budget--) { s->failed_pc=0x0c0cb2bau; return 0; }
fr[3]=0;
goto P_0c0cb2bc;
P_0c0cb2bc: /* original a04a, guest PC 0x0c0cb2bc */
if(!s->budget--) { s->failed_pc=0x0c0cb2bcu; return 0; }
vf3_matrix_store(s,ram,3,r[1]+r[0]);
goto P_0c0cb354;
P_0c0cb2be: /* original f137, guest PC 0x0c0cb2be */
if(!s->budget--) { s->failed_pc=0x0c0cb2beu; return 0; }
vf3_matrix_store(s,ram,3,r[1]+r[0]);
goto P_0c0cb2c0;
P_0c0cb2c0: /* original e004, guest PC 0x0c0cb2c0 */
if(!s->budget--) { s->failed_pc=0x0c0cb2c0u; return 0; }
r[0]=0x00000004u;
goto P_0c0cb2c2;
P_0c0cb2c2: /* original f3fc, guest PC 0x0c0cb2c2 */
if(!s->budget--) { s->failed_pc=0x0c0cb2c2u; return 0; }
vf3_matrix_move(s,3,15);
goto P_0c0cb2c4;
P_0c0cb2c4: /* original f35d, guest PC 0x0c0cb2c4 */
if(!s->budget--) { s->failed_pc=0x0c0cb2c4u; return 0; }
fr[3]&=0x7fffffffu;
goto P_0c0cb2c6;
P_0c0cb2c6: /* original ff3a, guest PC 0x0c0cb2c6 */
if(!s->budget--) { s->failed_pc=0x0c0cb2c6u; return 0; }
vf3_matrix_store(s,ram,3,r[15]);
goto P_0c0cb2c8;
P_0c0cb2c8: /* original f2ec, guest PC 0x0c0cb2c8 */
if(!s->budget--) { s->failed_pc=0x0c0cb2c8u; return 0; }
vf3_matrix_move(s,2,14);
goto P_0c0cb2ca;
P_0c0cb2ca: /* original f25d, guest PC 0x0c0cb2ca */
if(!s->budget--) { s->failed_pc=0x0c0cb2cau; return 0; }
fr[2]&=0x7fffffffu;
goto P_0c0cb2cc;
P_0c0cb2cc: /* original ff27, guest PC 0x0c0cb2cc */
if(!s->budget--) { s->failed_pc=0x0c0cb2ccu; return 0; }
vf3_matrix_store(s,ram,2,r[15]+r[0]);
goto P_0c0cb2ce;
P_0c0cb2ce: /* original e064, guest PC 0x0c0cb2ce */
if(!s->budget--) { s->failed_pc=0x0c0cb2ceu; return 0; }
r[0]=0x00000064u;
goto P_0c0cb2d0;
P_0c0cb2d0: /* original f1f6, guest PC 0x0c0cb2d0 */
if(!s->budget--) { s->failed_pc=0x0c0cb2d0u; return 0; }
vf3_matrix_load(s,ram,1,r[15]+r[0]);
goto P_0c0cb2d2;
P_0c0cb2d2: /* original e060, guest PC 0x0c0cb2d2 */
if(!s->budget--) { s->failed_pc=0x0c0cb2d2u; return 0; }
r[0]=0x00000060u;
goto P_0c0cb2d4;
P_0c0cb2d4: /* original f43c, guest PC 0x0c0cb2d4 */
if(!s->budget--) { s->failed_pc=0x0c0cb2d4u; return 0; }
vf3_matrix_move(s,4,3);
goto P_0c0cb2d6;
P_0c0cb2d6: /* original f411, guest PC 0x0c0cb2d6 */
if(!s->budget--) { s->failed_pc=0x0c0cb2d6u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[1],r[18],'-');
goto P_0c0cb2d8;
P_0c0cb2d8: /* original f1f6, guest PC 0x0c0cb2d8 */
if(!s->budget--) { s->failed_pc=0x0c0cb2d8u; return 0; }
vf3_matrix_load(s,ram,1,r[15]+r[0]);
goto P_0c0cb2da;
P_0c0cb2da: /* original f52c, guest PC 0x0c0cb2da */
if(!s->budget--) { s->failed_pc=0x0c0cb2dau; return 0; }
vf3_matrix_move(s,5,2);
goto P_0c0cb2dc;
P_0c0cb2dc: /* original f511, guest PC 0x0c0cb2dc */
if(!s->budget--) { s->failed_pc=0x0c0cb2dcu; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[1],r[18],'-');
goto P_0c0cb2de;
P_0c0cb2de: /* original f18d, guest PC 0x0c0cb2de */
if(!s->budget--) { s->failed_pc=0x0c0cb2deu; return 0; }
fr[1]=0;
goto P_0c0cb2e0;
P_0c0cb2e0: /* original f415, guest PC 0x0c0cb2e0 */
if(!s->budget--) { s->failed_pc=0x0c0cb2e0u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[4])>as_float(fr[1]))!=0);
goto P_0c0cb2e2;
P_0c0cb2e2: /* original 8b02, guest PC 0x0c0cb2e2 */
if(!s->budget--) { s->failed_pc=0x0c0cb2e2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0cb2ea; }
goto P_0c0cb2e4;
P_0c0cb2e4: /* original e064, guest PC 0x0c0cb2e4 */
if(!s->budget--) { s->failed_pc=0x0c0cb2e4u; return 0; }
r[0]=0x00000064u;
goto P_0c0cb2e6;
P_0c0cb2e6: /* original fcfc, guest PC 0x0c0cb2e6 */
if(!s->budget--) { s->failed_pc=0x0c0cb2e6u; return 0; }
vf3_matrix_move(s,12,15);
goto P_0c0cb2e8;
P_0c0cb2e8: /* original ff37, guest PC 0x0c0cb2e8 */
if(!s->budget--) { s->failed_pc=0x0c0cb2e8u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0cb2ea;
P_0c0cb2ea: /* original f38d, guest PC 0x0c0cb2ea */
if(!s->budget--) { s->failed_pc=0x0c0cb2eau; return 0; }
fr[3]=0;
goto P_0c0cb2ec;
P_0c0cb2ec: /* original f535, guest PC 0x0c0cb2ec */
if(!s->budget--) { s->failed_pc=0x0c0cb2ecu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[5])>as_float(fr[3]))!=0);
goto P_0c0cb2ee;
P_0c0cb2ee: /* original 8b05, guest PC 0x0c0cb2ee */
if(!s->budget--) { s->failed_pc=0x0c0cb2eeu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0cb2fc; }
goto P_0c0cb2f0;
P_0c0cb2f0: /* original e010, guest PC 0x0c0cb2f0 */
if(!s->budget--) { s->failed_pc=0x0c0cb2f0u; return 0; }
r[0]=0x00000010u;
goto P_0c0cb2f2;
P_0c0cb2f2: /* original ffe7, guest PC 0x0c0cb2f2 */
if(!s->budget--) { s->failed_pc=0x0c0cb2f2u; return 0; }
vf3_matrix_store(s,ram,14,r[15]+r[0]);
goto P_0c0cb2f4;
P_0c0cb2f4: /* original e004, guest PC 0x0c0cb2f4 */
if(!s->budget--) { s->failed_pc=0x0c0cb2f4u; return 0; }
r[0]=0x00000004u;
goto P_0c0cb2f6;
P_0c0cb2f6: /* original f3f6, guest PC 0x0c0cb2f6 */
if(!s->budget--) { s->failed_pc=0x0c0cb2f6u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0cb2f8;
P_0c0cb2f8: /* original e060, guest PC 0x0c0cb2f8 */
if(!s->budget--) { s->failed_pc=0x0c0cb2f8u; return 0; }
r[0]=0x00000060u;
goto P_0c0cb2fa;
P_0c0cb2fa: /* original ff37, guest PC 0x0c0cb2fa */
if(!s->budget--) { s->failed_pc=0x0c0cb2fau; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0cb2fc;
P_0c0cb2fc: /* original f38d, guest PC 0x0c0cb2fc */
if(!s->budget--) { s->failed_pc=0x0c0cb2fcu; return 0; }
fr[3]=0;
goto P_0c0cb2fe;
P_0c0cb2fe: /* original f435, guest PC 0x0c0cb2fe */
if(!s->budget--) { s->failed_pc=0x0c0cb2feu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[4])>as_float(fr[3]))!=0);
goto P_0c0cb300;
P_0c0cb300: /* original 8902, guest PC 0x0c0cb300 */
if(!s->budget--) { s->failed_pc=0x0c0cb300u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0cb308; }
goto P_0c0cb302;
P_0c0cb302: /* original f38d, guest PC 0x0c0cb302 */
if(!s->budget--) { s->failed_pc=0x0c0cb302u; return 0; }
fr[3]=0;
goto P_0c0cb304;
P_0c0cb304: /* original f535, guest PC 0x0c0cb304 */
if(!s->budget--) { s->failed_pc=0x0c0cb304u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[5])>as_float(fr[3]))!=0);
goto P_0c0cb306;
P_0c0cb306: /* original 8b25, guest PC 0x0c0cb306 */
if(!s->budget--) { s->failed_pc=0x0c0cb306u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0cb354; }
goto P_0c0cb308;
P_0c0cb308: /* original e024, guest PC 0x0c0cb308 */
if(!s->budget--) { s->failed_pc=0x0c0cb308u; return 0; }
r[0]=0x00000024u;
goto P_0c0cb30a;
P_0c0cb30a: /* original f3f6, guest PC 0x0c0cb30a */
if(!s->budget--) { s->failed_pc=0x0c0cb30au; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0cb30c;
P_0c0cb30c: /* original e050, guest PC 0x0c0cb30c */
if(!s->budget--) { s->failed_pc=0x0c0cb30cu; return 0; }
r[0]=0x00000050u;
goto P_0c0cb30e;
P_0c0cb30e: /* original ff37, guest PC 0x0c0cb30e */
if(!s->budget--) { s->failed_pc=0x0c0cb30eu; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0cb310;
P_0c0cb310: /* original e020, guest PC 0x0c0cb310 */
if(!s->budget--) { s->failed_pc=0x0c0cb310u; return 0; }
r[0]=0x00000020u;
goto P_0c0cb312;
P_0c0cb312: /* original f3f6, guest PC 0x0c0cb312 */
if(!s->budget--) { s->failed_pc=0x0c0cb312u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0cb314;
P_0c0cb314: /* original e048, guest PC 0x0c0cb314 */
if(!s->budget--) { s->failed_pc=0x0c0cb314u; return 0; }
r[0]=0x00000048u;
goto P_0c0cb316;
P_0c0cb316: /* original ff30, guest PC 0x0c0cb316 */
if(!s->budget--) { s->failed_pc=0x0c0cb316u; return 0; }
fr[15]=vf3_fpu_binary(fr[15],fr[3],r[18],'+');
goto P_0c0cb318;
P_0c0cb318: /* original fff7, guest PC 0x0c0cb318 */
if(!s->budget--) { s->failed_pc=0x0c0cb318u; return 0; }
vf3_matrix_store(s,ram,15,r[15]+r[0]);
goto P_0c0cb31a;
P_0c0cb31a: /* original e04c, guest PC 0x0c0cb31a */
if(!s->budget--) { s->failed_pc=0x0c0cb31au; return 0; }
r[0]=0x0000004cu;
goto P_0c0cb31c;
P_0c0cb31c: /* original ffd7, guest PC 0x0c0cb31c */
if(!s->budget--) { s->failed_pc=0x0c0cb31cu; return 0; }
vf3_matrix_store(s,ram,13,r[15]+r[0]);
goto P_0c0cb31e;
P_0c0cb31e: /* original e01c, guest PC 0x0c0cb31e */
if(!s->budget--) { s->failed_pc=0x0c0cb31eu; return 0; }
r[0]=0x0000001cu;
goto P_0c0cb320;
P_0c0cb320: /* original f2f6, guest PC 0x0c0cb320 */
if(!s->budget--) { s->failed_pc=0x0c0cb320u; return 0; }
vf3_matrix_load(s,ram,2,r[15]+r[0]);
goto P_0c0cb322;
P_0c0cb322: /* original e044, guest PC 0x0c0cb322 */
if(!s->budget--) { s->failed_pc=0x0c0cb322u; return 0; }
r[0]=0x00000044u;
goto P_0c0cb324;
P_0c0cb324: /* original fe20, guest PC 0x0c0cb324 */
if(!s->budget--) { s->failed_pc=0x0c0cb324u; return 0; }
fr[14]=vf3_fpu_binary(fr[14],fr[2],r[18],'+');
goto P_0c0cb326;
P_0c0cb326: /* original ffe7, guest PC 0x0c0cb326 */
if(!s->budget--) { s->failed_pc=0x0c0cb326u; return 0; }
vf3_matrix_store(s,ram,14,r[15]+r[0]);
goto P_0c0cb328;
P_0c0cb328: /* original e058, guest PC 0x0c0cb328 */
if(!s->budget--) { s->failed_pc=0x0c0cb328u; return 0; }
r[0]=0x00000058u;
goto P_0c0cb32a;
P_0c0cb32a: /* original 00fe, guest PC 0x0c0cb32a */
if(!s->budget--) { s->failed_pc=0x0c0cb32au; return 0; }
r[0]=read(ram,r[15]+r[0],4);
goto P_0c0cb32c;
P_0c0cb32c: /* original 8806, guest PC 0x0c0cb32c */
if(!s->budget--) { s->failed_pc=0x0c0cb32cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000006u)!=0);
goto P_0c0cb32e;
P_0c0cb32e: /* original 890d, guest PC 0x0c0cb32e */
if(!s->budget--) { s->failed_pc=0x0c0cb32eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0cb34c; }
goto P_0c0cb330;
P_0c0cb330: /* original 50f2, guest PC 0x0c0cb330 */
if(!s->budget--) { s->failed_pc=0x0c0cb330u; return 0; }
r[0]=read(ram,r[15]+8,4);
goto P_0c0cb332;
P_0c0cb332: /* original c848, guest PC 0x0c0cb332 */
if(!s->budget--) { s->failed_pc=0x0c0cb332u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&72u)==0)!=0);
goto P_0c0cb334;
P_0c0cb334: /* original 8b0a, guest PC 0x0c0cb334 */
if(!s->budget--) { s->failed_pc=0x0c0cb334u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0cb34c; }
goto P_0c0cb336;
P_0c0cb336: /* original a00a, guest PC 0x0c0cb336 */
if(!s->budget--) { s->failed_pc=0x0c0cb336u; return 0; }
r[10]=0x00000001u;
goto P_0c0cb34e;
P_0c0cb338: /* original ea01, guest PC 0x0c0cb338 */
if(!s->budget--) { s->failed_pc=0x0c0cb338u; return 0; }
r[10]=0x00000001u;
return vf3_matrix_family(0x0c0cb33au,s,ram);
P_0c0cb34c: /* original ea00, guest PC 0x0c0cb34c */
if(!s->budget--) { s->failed_pc=0x0c0cb34cu; return 0; }
r[10]=0x00000000u;
goto P_0c0cb34e;
P_0c0cb34e: /* original e05c, guest PC 0x0c0cb34e */
if(!s->budget--) { s->failed_pc=0x0c0cb34eu; return 0; }
r[0]=0x0000005cu;
goto P_0c0cb350;
P_0c0cb350: /* original 02fe, guest PC 0x0c0cb350 */
if(!s->budget--) { s->failed_pc=0x0c0cb350u; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c0cb352;
P_0c0cb352: /* original 2d2b, guest PC 0x0c0cb352 */
if(!s->budget--) { s->failed_pc=0x0c0cb352u; return 0; }
r[13]|=r[2];
goto P_0c0cb354;
P_0c0cb354: /* original 4b10, guest PC 0x0c0cb354 */
if(!s->budget--) { s->failed_pc=0x0c0cb354u; return 0; }
--r[11];
r[17]=(r[17]&~1u)|((r[11]==0)!=0);
goto P_0c0cb356;
P_0c0cb356: /* original 8901, guest PC 0x0c0cb356 */
if(!s->budget--) { s->failed_pc=0x0c0cb356u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0cb35c; }
goto P_0c0cb358;
P_0c0cb358: /* original af08, guest PC 0x0c0cb358 */
if(!s->budget--) { s->failed_pc=0x0c0cb358u; return 0; }
goto P_0c0cb16c;
P_0c0cb35a: /* original 0009, guest PC 0x0c0cb35a */
if(!s->budget--) { s->failed_pc=0x0c0cb35au; return 0; }
goto P_0c0cb35c;
P_0c0cb35c: /* original 907f, guest PC 0x0c0cb35c */
if(!s->budget--) { s->failed_pc=0x0c0cb35cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0cb45eu,2);
goto P_0c0cb35e;
P_0c0cb35e: /* original fec7, guest PC 0x0c0cb35e */
if(!s->budget--) { s->failed_pc=0x0c0cb35eu; return 0; }
vf3_matrix_store(s,ram,12,r[14]+r[0]);
goto P_0c0cb360;
P_0c0cb360: /* original e010, guest PC 0x0c0cb360 */
if(!s->budget--) { s->failed_pc=0x0c0cb360u; return 0; }
r[0]=0x00000010u;
goto P_0c0cb362;
P_0c0cb362: /* original f3f6, guest PC 0x0c0cb362 */
if(!s->budget--) { s->failed_pc=0x0c0cb362u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0cb364;
P_0c0cb364: /* original 907c, guest PC 0x0c0cb364 */
if(!s->budget--) { s->failed_pc=0x0c0cb364u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0cb460u,2);
goto P_0c0cb366;
P_0c0cb366: /* original f34d, guest PC 0x0c0cb366 */
if(!s->budget--) { s->failed_pc=0x0c0cb366u; return 0; }
fr[3]^=0x80000000u;
goto P_0c0cb368;
P_0c0cb368: /* original fe37, guest PC 0x0c0cb368 */
if(!s->budget--) { s->failed_pc=0x0c0cb368u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c0cb36a;
P_0c0cb36a: /* original c741, guest PC 0x0c0cb36a */
if(!s->budget--) { s->failed_pc=0x0c0cb36au; return 0; }
r[0]=0x0c0cb470u;
goto P_0c0cb36c;
P_0c0cb36c: /* original f308, guest PC 0x0c0cb36c */
if(!s->budget--) { s->failed_pc=0x0c0cb36cu; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c0cb36e;
P_0c0cb36e: /* original e014, guest PC 0x0c0cb36e */
if(!s->budget--) { s->failed_pc=0x0c0cb36eu; return 0; }
r[0]=0x00000014u;
goto P_0c0cb370;
P_0c0cb370: /* original f2f6, guest PC 0x0c0cb370 */
if(!s->budget--) { s->failed_pc=0x0c0cb370u; return 0; }
vf3_matrix_load(s,ram,2,r[15]+r[0]);
goto P_0c0cb372;
P_0c0cb372: /* original f325, guest PC 0x0c0cb372 */
if(!s->budget--) { s->failed_pc=0x0c0cb372u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[2]))!=0);
goto P_0c0cb374;
P_0c0cb374: /* original 8901, guest PC 0x0c0cb374 */
if(!s->budget--) { s->failed_pc=0x0c0cb374u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0cb37a; }
goto P_0c0cb376;
P_0c0cb376: /* original a091, guest PC 0x0c0cb376 */
if(!s->budget--) { s->failed_pc=0x0c0cb376u; return 0; }
goto P_0c0cb49c;
P_0c0cb378: /* original 0009, guest PC 0x0c0cb378 */
if(!s->budget--) { s->failed_pc=0x0c0cb378u; return 0; }
goto P_0c0cb37a;
P_0c0cb37a: /* original d33e, guest PC 0x0c0cb37a */
if(!s->budget--) { s->failed_pc=0x0c0cb37au; return 0; }
r[3]=read(ram,0x0c0cb474u,4);
goto P_0c0cb37c;
P_0c0cb37c: /* original 9471, guest PC 0x0c0cb37c */
if(!s->budget--) { s->failed_pc=0x0c0cb37cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0cb462u,2);
goto P_0c0cb37e;
P_0c0cb37e: /* original 23c8, guest PC 0x0c0cb37e */
if(!s->budget--) { s->failed_pc=0x0c0cb37eu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[12])==0)!=0);
goto P_0c0cb380;
P_0c0cb380: /* original 891b, guest PC 0x0c0cb380 */
if(!s->budget--) { s->failed_pc=0x0c0cb380u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0cb3ba; }
goto P_0c0cb382;
P_0c0cb382: /* original 906f, guest PC 0x0c0cb382 */
if(!s->budget--) { s->failed_pc=0x0c0cb382u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0cb464u,2);
goto P_0c0cb384;
P_0c0cb384: /* original 02ee, guest PC 0x0c0cb384 */
if(!s->budget--) { s->failed_pc=0x0c0cb384u; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c0cb386;
P_0c0cb386: /* original 6023, guest PC 0x0c0cb386 */
if(!s->budget--) { s->failed_pc=0x0c0cb386u; return 0; }
r[0]=r[2];
goto P_0c0cb388;
P_0c0cb388: /* original c820, guest PC 0x0c0cb388 */
if(!s->budget--) { s->failed_pc=0x0c0cb388u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&32u)==0)!=0);
goto P_0c0cb38a;
P_0c0cb38a: /* original 1f22, guest PC 0x0c0cb38a */
if(!s->budget--) { s->failed_pc=0x0c0cb38au; return 0; }
write(ram,r[15]+8,r[2],4);
goto P_0c0cb38c;
P_0c0cb38c: /* original 8915, guest PC 0x0c0cb38c */
if(!s->budget--) { s->failed_pc=0x0c0cb38cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0cb3ba; }
goto P_0c0cb38e;
P_0c0cb38e: /* original 906a, guest PC 0x0c0cb38e */
if(!s->budget--) { s->failed_pc=0x0c0cb38eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0cb466u,2);
goto P_0c0cb390;
P_0c0cb390: /* original f3e6, guest PC 0x0c0cb390 */
if(!s->budget--) { s->failed_pc=0x0c0cb390u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c0cb392;
P_0c0cb392: /* original e004, guest PC 0x0c0cb392 */
if(!s->budget--) { s->failed_pc=0x0c0cb392u; return 0; }
r[0]=0x00000004u;
goto P_0c0cb394;
P_0c0cb394: /* original f23c, guest PC 0x0c0cb394 */
if(!s->budget--) { s->failed_pc=0x0c0cb394u; return 0; }
vf3_matrix_move(s,2,3);
goto P_0c0cb396;
P_0c0cb396: /* original f232, guest PC 0x0c0cb396 */
if(!s->budget--) { s->failed_pc=0x0c0cb396u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c0cb398;
P_0c0cb398: /* original ff27, guest PC 0x0c0cb398 */
if(!s->budget--) { s->failed_pc=0x0c0cb398u; return 0; }
vf3_matrix_store(s,ram,2,r[15]+r[0]);
goto P_0c0cb39a;
P_0c0cb39a: /* original e010, guest PC 0x0c0cb39a */
if(!s->budget--) { s->failed_pc=0x0c0cb39au; return 0; }
r[0]=0x00000010u;
goto P_0c0cb39c;
P_0c0cb39c: /* original f3cc, guest PC 0x0c0cb39c */
if(!s->budget--) { s->failed_pc=0x0c0cb39cu; return 0; }
vf3_matrix_move(s,3,12);
goto P_0c0cb39e;
P_0c0cb39e: /* original f3c2, guest PC 0x0c0cb39e */
if(!s->budget--) { s->failed_pc=0x0c0cb39eu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[12],r[18],'*');
goto P_0c0cb3a0;
P_0c0cb3a0: /* original ff3a, guest PC 0x0c0cb3a0 */
if(!s->budget--) { s->failed_pc=0x0c0cb3a0u; return 0; }
vf3_matrix_store(s,ram,3,r[15]);
goto P_0c0cb3a2;
P_0c0cb3a2: /* original f1f6, guest PC 0x0c0cb3a2 */
if(!s->budget--) { s->failed_pc=0x0c0cb3a2u; return 0; }
vf3_matrix_load(s,ram,1,r[15]+r[0]);
goto P_0c0cb3a4;
P_0c0cb3a4: /* original e004, guest PC 0x0c0cb3a4 */
if(!s->budget--) { s->failed_pc=0x0c0cb3a4u; return 0; }
r[0]=0x00000004u;
goto P_0c0cb3a6;
P_0c0cb3a6: /* original f01c, guest PC 0x0c0cb3a6 */
if(!s->budget--) { s->failed_pc=0x0c0cb3a6u; return 0; }
vf3_matrix_move(s,0,1);
goto P_0c0cb3a8;
P_0c0cb3a8: /* original f31e, guest PC 0x0c0cb3a8 */
if(!s->budget--) { s->failed_pc=0x0c0cb3a8u; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[1],fr[3],r[18]);
goto P_0c0cb3aa;
P_0c0cb3aa: /* original f231, guest PC 0x0c0cb3aa */
if(!s->budget--) { s->failed_pc=0x0c0cb3aau; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'-');
goto P_0c0cb3ac;
P_0c0cb3ac: /* original ff3a, guest PC 0x0c0cb3ac */
if(!s->budget--) { s->failed_pc=0x0c0cb3acu; return 0; }
vf3_matrix_store(s,ram,3,r[15]);
goto P_0c0cb3ae;
P_0c0cb3ae: /* original ff27, guest PC 0x0c0cb3ae */
if(!s->budget--) { s->failed_pc=0x0c0cb3aeu; return 0; }
vf3_matrix_store(s,ram,2,r[15]+r[0]);
goto P_0c0cb3b0;
P_0c0cb3b0: /* original c731, guest PC 0x0c0cb3b0 */
if(!s->budget--) { s->failed_pc=0x0c0cb3b0u; return 0; }
r[0]=0x0c0cb478u;
goto P_0c0cb3b2;
P_0c0cb3b2: /* original f308, guest PC 0x0c0cb3b2 */
if(!s->budget--) { s->failed_pc=0x0c0cb3b2u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c0cb3b4;
P_0c0cb3b4: /* original f325, guest PC 0x0c0cb3b4 */
if(!s->budget--) { s->failed_pc=0x0c0cb3b4u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[2]))!=0);
goto P_0c0cb3b6;
P_0c0cb3b6: /* original 8900, guest PC 0x0c0cb3b6 */
if(!s->budget--) { s->failed_pc=0x0c0cb3b6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0cb3ba; }
goto P_0c0cb3b8;
P_0c0cb3b8: /* original 2d4b, guest PC 0x0c0cb3b8 */
if(!s->budget--) { s->failed_pc=0x0c0cb3b8u; return 0; }
r[13]|=r[4];
goto P_0c0cb3ba;
P_0c0cb3ba: /* original 9055, guest PC 0x0c0cb3ba */
if(!s->budget--) { s->failed_pc=0x0c0cb3bau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0cb468u,2);
goto P_0c0cb3bc;
P_0c0cb3bc: /* original 05ee, guest PC 0x0c0cb3bc */
if(!s->budget--) { s->failed_pc=0x0c0cb3bcu; return 0; }
r[5]=read(ram,r[14]+r[0],4);
goto P_0c0cb3be;
P_0c0cb3be: /* original 60a3, guest PC 0x0c0cb3be */
if(!s->budget--) { s->failed_pc=0x0c0cb3beu; return 0; }
r[0]=r[10];
goto P_0c0cb3c0;
P_0c0cb3c0: /* original 8801, guest PC 0x0c0cb3c0 */
if(!s->budget--) { s->failed_pc=0x0c0cb3c0u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c0cb3c2;
P_0c0cb3c2: /* original 8b6b, guest PC 0x0c0cb3c2 */
if(!s->budget--) { s->failed_pc=0x0c0cb3c2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0cb49c; }
goto P_0c0cb3c4;
P_0c0cb3c4: /* original 2998, guest PC 0x0c0cb3c4 */
if(!s->budget--) { s->failed_pc=0x0c0cb3c4u; return 0; }
r[17]=(r[17]&~1u)|(((r[9]&r[9])==0)!=0);
goto P_0c0cb3c6;
P_0c0cb3c6: /* original 8b02, guest PC 0x0c0cb3c6 */
if(!s->budget--) { s->failed_pc=0x0c0cb3c6u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0cb3ce; }
goto P_0c0cb3c8;
P_0c0cb3c8: /* original d32a, guest PC 0x0c0cb3c8 */
if(!s->budget--) { s->failed_pc=0x0c0cb3c8u; return 0; }
r[3]=read(ram,0x0c0cb474u,4);
goto P_0c0cb3ca;
P_0c0cb3ca: /* original 23c8, guest PC 0x0c0cb3ca */
if(!s->budget--) { s->failed_pc=0x0c0cb3cau; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[12])==0)!=0);
goto P_0c0cb3cc;
P_0c0cb3cc: /* original 8966, guest PC 0x0c0cb3cc */
if(!s->budget--) { s->failed_pc=0x0c0cb3ccu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0cb49c; }
goto P_0c0cb3ce;
P_0c0cb3ce: /* original d22b, guest PC 0x0c0cb3ce */
if(!s->budget--) { s->failed_pc=0x0c0cb3ceu; return 0; }
r[2]=read(ram,0x0c0cb47cu,4);
goto P_0c0cb3d0;
P_0c0cb3d0: /* original 2528, guest PC 0x0c0cb3d0 */
if(!s->budget--) { s->failed_pc=0x0c0cb3d0u; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[2])==0)!=0);
goto P_0c0cb3d2;
P_0c0cb3d2: /* original 8b63, guest PC 0x0c0cb3d2 */
if(!s->budget--) { s->failed_pc=0x0c0cb3d2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0cb49c; }
goto P_0c0cb3d4;
P_0c0cb3d4: /* original d32a, guest PC 0x0c0cb3d4 */
if(!s->budget--) { s->failed_pc=0x0c0cb3d4u; return 0; }
r[3]=read(ram,0x0c0cb480u,4);
goto P_0c0cb3d6;
P_0c0cb3d6: /* original 23d8, guest PC 0x0c0cb3d6 */
if(!s->budget--) { s->failed_pc=0x0c0cb3d6u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[13])==0)!=0);
goto P_0c0cb3d8;
P_0c0cb3d8: /* original 8b59, guest PC 0x0c0cb3d8 */
if(!s->budget--) { s->failed_pc=0x0c0cb3d8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0cb48e; }
goto P_0c0cb3da;
P_0c0cb3da: /* original 24d8, guest PC 0x0c0cb3da */
if(!s->budget--) { s->failed_pc=0x0c0cb3dau; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[13])==0)!=0);
goto P_0c0cb3dc;
P_0c0cb3dc: /* original 8b57, guest PC 0x0c0cb3dc */
if(!s->budget--) { s->failed_pc=0x0c0cb3dcu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0cb48e; }
goto P_0c0cb3de;
P_0c0cb3de: /* original 9344, guest PC 0x0c0cb3de */
if(!s->budget--) { s->failed_pc=0x0c0cb3deu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0cb46au,2);
goto P_0c0cb3e0;
P_0c0cb3e0: /* original 2c38, guest PC 0x0c0cb3e0 */
if(!s->budget--) { s->failed_pc=0x0c0cb3e0u; return 0; }
r[17]=(r[17]&~1u)|(((r[12]&r[3])==0)!=0);
goto P_0c0cb3e2;
P_0c0cb3e2: /* original 8b54, guest PC 0x0c0cb3e2 */
if(!s->budget--) { s->failed_pc=0x0c0cb3e2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0cb48e; }
goto P_0c0cb3e4;
P_0c0cb3e4: /* original c727, guest PC 0x0c0cb3e4 */
if(!s->budget--) { s->failed_pc=0x0c0cb3e4u; return 0; }
r[0]=0x0c0cb484u;
goto P_0c0cb3e6;
P_0c0cb3e6: /* original f308, guest PC 0x0c0cb3e6 */
if(!s->budget--) { s->failed_pc=0x0c0cb3e6u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c0cb3e8;
P_0c0cb3e8: /* original e050, guest PC 0x0c0cb3e8 */
if(!s->budget--) { s->failed_pc=0x0c0cb3e8u; return 0; }
r[0]=0x00000050u;
goto P_0c0cb3ea;
P_0c0cb3ea: /* original ff3a, guest PC 0x0c0cb3ea */
if(!s->budget--) { s->failed_pc=0x0c0cb3eau; return 0; }
vf3_matrix_store(s,ram,3,r[15]);
goto P_0c0cb3ec;
P_0c0cb3ec: /* original f3f6, guest PC 0x0c0cb3ec */
if(!s->budget--) { s->failed_pc=0x0c0cb3ecu; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0cb3ee;
P_0c0cb3ee: /* original e04c, guest PC 0x0c0cb3ee */
if(!s->budget--) { s->failed_pc=0x0c0cb3eeu; return 0; }
r[0]=0x0000004cu;
goto P_0c0cb3f0;
P_0c0cb3f0: /* original f2f6, guest PC 0x0c0cb3f0 */
if(!s->budget--) { s->failed_pc=0x0c0cb3f0u; return 0; }
vf3_matrix_load(s,ram,2,r[15]+r[0]);
goto P_0c0cb3f2;
P_0c0cb3f2: /* original e048, guest PC 0x0c0cb3f2 */
if(!s->budget--) { s->failed_pc=0x0c0cb3f2u; return 0; }
r[0]=0x00000048u;
goto P_0c0cb3f4;
P_0c0cb3f4: /* original f1f6, guest PC 0x0c0cb3f4 */
if(!s->budget--) { s->failed_pc=0x0c0cb3f4u; return 0; }
vf3_matrix_load(s,ram,1,r[15]+r[0]);
goto P_0c0cb3f6;
P_0c0cb3f6: /* original e044, guest PC 0x0c0cb3f6 */
if(!s->budget--) { s->failed_pc=0x0c0cb3f6u; return 0; }
r[0]=0x00000044u;
goto P_0c0cb3f8;
P_0c0cb3f8: /* original f7f8, guest PC 0x0c0cb3f8 */
if(!s->budget--) { s->failed_pc=0x0c0cb3f8u; return 0; }
vf3_matrix_load(s,ram,7,r[15]);
goto P_0c0cb3fa;
P_0c0cb3fa: /* original f6f8, guest PC 0x0c0cb3fa */
if(!s->budget--) { s->failed_pc=0x0c0cb3fau; return 0; }
vf3_matrix_load(s,ram,6,r[15]);
goto P_0c0cb3fc;
P_0c0cb3fc: /* original ff1a, guest PC 0x0c0cb3fc */
if(!s->budget--) { s->failed_pc=0x0c0cb3fcu; return 0; }
vf3_matrix_store(s,ram,1,r[15]);
goto P_0c0cb3fe;
P_0c0cb3fe: /* original f722, guest PC 0x0c0cb3fe */
if(!s->budget--) { s->failed_pc=0x0c0cb3feu; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[2],r[18],'*');
goto P_0c0cb400;
P_0c0cb400: /* original f632, guest PC 0x0c0cb400 */
if(!s->budget--) { s->failed_pc=0x0c0cb400u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[3],r[18],'*');
goto P_0c0cb402;
P_0c0cb402: /* original f1f6, guest PC 0x0c0cb402 */
if(!s->budget--) { s->failed_pc=0x0c0cb402u; return 0; }
vf3_matrix_load(s,ram,1,r[15]+r[0]);
goto P_0c0cb404;
P_0c0cb404: /* original e004, guest PC 0x0c0cb404 */
if(!s->budget--) { s->failed_pc=0x0c0cb404u; return 0; }
r[0]=0x00000004u;
goto P_0c0cb406;
P_0c0cb406: /* original ff17, guest PC 0x0c0cb406 */
if(!s->budget--) { s->failed_pc=0x0c0cb406u; return 0; }
vf3_matrix_store(s,ram,1,r[15]+r[0]);
goto P_0c0cb408;
P_0c0cb408: /* original f51c, guest PC 0x0c0cb408 */
if(!s->budget--) { s->failed_pc=0x0c0cb408u; return 0; }
vf3_matrix_move(s,5,1);
goto P_0c0cb40a;
P_0c0cb40a: /* original b056, guest PC 0x0c0cb40a */
if(!s->budget--) { s->failed_pc=0x0c0cb40au; return 0; }
target=0x0c0cb4bau; r[16]=0x0c0cb40eu;
vf3_matrix_load(s,ram,4,r[15]);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0cb40eu) { target=s->pc; goto dispatch; }
goto P_0c0cb40e;
P_0c0cb40c: /* original f4f8, guest PC 0x0c0cb40c */
if(!s->budget--) { s->failed_pc=0x0c0cb40cu; return 0; }
vf3_matrix_load(s,ram,4,r[15]);
goto P_0c0cb40e;
P_0c0cb40e: /* original 902d, guest PC 0x0c0cb40e */
if(!s->budget--) { s->failed_pc=0x0c0cb40eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0cb46cu,2);
goto P_0c0cb410;
P_0c0cb410: /* original e406, guest PC 0x0c0cb410 */
if(!s->budget--) { s->failed_pc=0x0c0cb410u; return 0; }
r[4]=0x00000006u;
goto P_0c0cb412;
P_0c0cb412: /* original f40c, guest PC 0x0c0cb412 */
if(!s->budget--) { s->failed_pc=0x0c0cb412u; return 0; }
vf3_matrix_move(s,4,0);
goto P_0c0cb414;
P_0c0cb414: /* original e600, guest PC 0x0c0cb414 */
if(!s->budget--) { s->failed_pc=0x0c0cb414u; return 0; }
r[6]=0x00000000u;
goto P_0c0cb416;
P_0c0cb416: /* original fe47, guest PC 0x0c0cb416 */
if(!s->budget--) { s->failed_pc=0x0c0cb416u; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c0cb418;
P_0c0cb418: /* original 6343, guest PC 0x0c0cb418 */
if(!s->budget--) { s->failed_pc=0x0c0cb418u; return 0; }
r[3]=r[4];
goto P_0c0cb41a;
P_0c0cb41a: /* original 33b8, guest PC 0x0c0cb41a */
if(!s->budget--) { s->failed_pc=0x0c0cb41au; return 0; }
r[3]-=r[11];
goto P_0c0cb41c;
P_0c0cb41c: /* original 1f32, guest PC 0x0c0cb41c */
if(!s->budget--) { s->failed_pc=0x0c0cb41cu; return 0; }
write(ram,r[15]+8,r[3],4);
goto P_0c0cb41e;
P_0c0cb41e: /* original 55fe, guest PC 0x0c0cb41e */
if(!s->budget--) { s->failed_pc=0x0c0cb41eu; return 0; }
r[5]=read(ram,r[15]+56,4);
goto P_0c0cb420;
P_0c0cb420: /* original d219, guest PC 0x0c0cb420 */
if(!s->budget--) { s->failed_pc=0x0c0cb420u; return 0; }
r[2]=read(ram,0x0c0cb488u,4);
goto P_0c0cb422;
P_0c0cb422: /* original 353c, guest PC 0x0c0cb422 */
if(!s->budget--) { s->failed_pc=0x0c0cb422u; return 0; }
r[5]+=r[3];
goto P_0c0cb424;
P_0c0cb424: /* original 6150, guest PC 0x0c0cb424 */
if(!s->budget--) { s->failed_pc=0x0c0cb424u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[5],1);
r[1]=tmp;
goto P_0c0cb426;
P_0c0cb426: /* original 420b, guest PC 0x0c0cb426 */
if(!s->budget--) { s->failed_pc=0x0c0cb426u; return 0; }
target=r[2];
r[16]=0x0c0cb42au;
r[0]=0x00000004u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0cb42au) { target=s->pc; goto dispatch; }
goto P_0c0cb42a;
P_0c0cb428: /* original e004, guest PC 0x0c0cb428 */
if(!s->budget--) { s->failed_pc=0x0c0cb428u; return 0; }
r[0]=0x00000004u;
goto P_0c0cb42a;
P_0c0cb42a: /* original 9220, guest PC 0x0c0cb42a */
if(!s->budget--) { s->failed_pc=0x0c0cb42au; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0cb46eu,2);
goto P_0c0cb42c;
P_0c0cb42c: /* original 6503, guest PC 0x0c0cb42c */
if(!s->budget--) { s->failed_pc=0x0c0cb42cu; return 0; }
r[5]=r[0];
goto P_0c0cb42e;
P_0c0cb42e: /* original 635e, guest PC 0x0c0cb42e */
if(!s->budget--) { s->failed_pc=0x0c0cb42eu; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)r[5];
goto P_0c0cb430;
P_0c0cb430: /* original 32ec, guest PC 0x0c0cb430 */
if(!s->budget--) { s->failed_pc=0x0c0cb430u; return 0; }
r[2]+=r[14];
goto P_0c0cb432;
P_0c0cb432: /* original 4308, guest PC 0x0c0cb432 */
if(!s->budget--) { s->failed_pc=0x0c0cb432u; return 0; }
r[3]<<=2;
goto P_0c0cb434;
P_0c0cb434: /* original 332c, guest PC 0x0c0cb434 */
if(!s->budget--) { s->failed_pc=0x0c0cb434u; return 0; }
r[3]+=r[2];
goto P_0c0cb436;
P_0c0cb436: /* original 655e, guest PC 0x0c0cb436 */
if(!s->budget--) { s->failed_pc=0x0c0cb436u; return 0; }
r[5]=(uint32_t)(int32_t)(int8_t)r[5];
goto P_0c0cb438;
P_0c0cb438: /* original f338, guest PC 0x0c0cb438 */
if(!s->budget--) { s->failed_pc=0x0c0cb438u; return 0; }
vf3_matrix_load(s,ram,3,r[3]);
goto P_0c0cb43a;
P_0c0cb43a: /* original 6353, guest PC 0x0c0cb43a */
if(!s->budget--) { s->failed_pc=0x0c0cb43au; return 0; }
r[3]=r[5];
goto P_0c0cb43c;
P_0c0cb43c: /* original 4500, guest PC 0x0c0cb43c */
if(!s->budget--) { s->failed_pc=0x0c0cb43cu; return 0; }
r[17]=(r[17]&~1u)|((r[5]>>31)!=0);
r[5]<<=1;
goto P_0c0cb43e;
P_0c0cb43e: /* original 353c, guest PC 0x0c0cb43e */
if(!s->budget--) { s->failed_pc=0x0c0cb43eu; return 0; }
r[5]+=r[3];
goto P_0c0cb440;
P_0c0cb440: /* original ff3a, guest PC 0x0c0cb440 */
if(!s->budget--) { s->failed_pc=0x0c0cb440u; return 0; }
vf3_matrix_store(s,ram,3,r[15]);
goto P_0c0cb442;
P_0c0cb442: /* original 4508, guest PC 0x0c0cb442 */
if(!s->budget--) { s->failed_pc=0x0c0cb442u; return 0; }
r[5]<<=2;
goto P_0c0cb444;
P_0c0cb444: /* original e004, guest PC 0x0c0cb444 */
if(!s->budget--) { s->failed_pc=0x0c0cb444u; return 0; }
r[0]=0x00000004u;
goto P_0c0cb446;
P_0c0cb446: /* original 358c, guest PC 0x0c0cb446 */
if(!s->budget--) { s->failed_pc=0x0c0cb446u; return 0; }
r[5]+=r[8];
goto P_0c0cb448;
P_0c0cb448: /* original f556, guest PC 0x0c0cb448 */
if(!s->budget--) { s->failed_pc=0x0c0cb448u; return 0; }
vf3_matrix_load(s,ram,5,r[5]+r[0]);
goto P_0c0cb44a;
P_0c0cb44a: /* original f531, guest PC 0x0c0cb44a */
if(!s->budget--) { s->failed_pc=0x0c0cb44au; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[3],r[18],'-');
goto P_0c0cb44c;
P_0c0cb44c: /* original f545, guest PC 0x0c0cb44c */
if(!s->budget--) { s->failed_pc=0x0c0cb44cu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[5])>as_float(fr[4]))!=0);
goto P_0c0cb44e;
P_0c0cb44e: /* original 8900, guest PC 0x0c0cb44e */
if(!s->budget--) { s->failed_pc=0x0c0cb44eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0cb452; }
goto P_0c0cb450;
P_0c0cb450: /* original e601, guest PC 0x0c0cb450 */
if(!s->budget--) { s->failed_pc=0x0c0cb450u; return 0; }
r[6]=0x00000001u;
goto P_0c0cb452;
P_0c0cb452: /* original 4410, guest PC 0x0c0cb452 */
if(!s->budget--) { s->failed_pc=0x0c0cb452u; return 0; }
--r[4];
r[17]=(r[17]&~1u)|((r[4]==0)!=0);
goto P_0c0cb454;
P_0c0cb454: /* original 8be0, guest PC 0x0c0cb454 */
if(!s->budget--) { s->failed_pc=0x0c0cb454u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0cb418; }
goto P_0c0cb456;
P_0c0cb456: /* original e301, guest PC 0x0c0cb456 */
if(!s->budget--) { s->failed_pc=0x0c0cb456u; return 0; }
r[3]=0x00000001u;
goto P_0c0cb458;
P_0c0cb458: /* original 2638, guest PC 0x0c0cb458 */
if(!s->budget--) { s->failed_pc=0x0c0cb458u; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[3])==0)!=0);
goto P_0c0cb45a;
P_0c0cb45a: /* original a017, guest PC 0x0c0cb45a */
if(!s->budget--) { s->failed_pc=0x0c0cb45au; return 0; }
goto P_0c0cb48c;
P_0c0cb45c: /* original 0009, guest PC 0x0c0cb45c */
if(!s->budget--) { s->failed_pc=0x0c0cb45cu; return 0; }
return vf3_matrix_family(0x0c0cb45eu,s,ram);
P_0c0cb48c: /* original 8b06, guest PC 0x0c0cb48c */
if(!s->budget--) { s->failed_pc=0x0c0cb48cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0cb49c; }
goto P_0c0cb48e;
P_0c0cb48e: /* original 9062, guest PC 0x0c0cb48e */
if(!s->budget--) { s->failed_pc=0x0c0cb48eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0cb556u,2);
goto P_0c0cb490;
P_0c0cb490: /* original f38d, guest PC 0x0c0cb490 */
if(!s->budget--) { s->failed_pc=0x0c0cb490u; return 0; }
fr[3]=0;
goto P_0c0cb492;
P_0c0cb492: /* original fe37, guest PC 0x0c0cb492 */
if(!s->budget--) { s->failed_pc=0x0c0cb492u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c0cb494;
P_0c0cb494: /* original 70f8, guest PC 0x0c0cb494 */
if(!s->budget--) { s->failed_pc=0x0c0cb494u; return 0; }
r[0]+=0xfffffff8u;
goto P_0c0cb496;
P_0c0cb496: /* original fe37, guest PC 0x0c0cb496 */
if(!s->budget--) { s->failed_pc=0x0c0cb496u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c0cb498;
P_0c0cb498: /* original d330, guest PC 0x0c0cb498 */
if(!s->budget--) { s->failed_pc=0x0c0cb498u; return 0; }
r[3]=read(ram,0x0c0cb55cu,4);
goto P_0c0cb49a;
P_0c0cb49a: /* original 2d39, guest PC 0x0c0cb49a */
if(!s->budget--) { s->failed_pc=0x0c0cb49au; return 0; }
r[13]&=r[3];
goto P_0c0cb49c;
P_0c0cb49c: /* original 2ed2, guest PC 0x0c0cb49c */
if(!s->budget--) { s->failed_pc=0x0c0cb49cu; return 0; }
write(ram,r[14],r[13],4);
goto P_0c0cb49e;
P_0c0cb49e: /* original 7f74, guest PC 0x0c0cb49e */
if(!s->budget--) { s->failed_pc=0x0c0cb49eu; return 0; }
r[15]+=0x00000074u;
goto P_0c0cb4a0;
P_0c0cb4a0: /* original 4f26, guest PC 0x0c0cb4a0 */
if(!s->budget--) { s->failed_pc=0x0c0cb4a0u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0cb4a2;
P_0c0cb4a2: /* original fcf9, guest PC 0x0c0cb4a2 */
if(!s->budget--) { s->failed_pc=0x0c0cb4a2u; return 0; }
vf3_matrix_load(s,ram,12,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0cb4a4;
P_0c0cb4a4: /* original fdf9, guest PC 0x0c0cb4a4 */
if(!s->budget--) { s->failed_pc=0x0c0cb4a4u; return 0; }
vf3_matrix_load(s,ram,13,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0cb4a6;
P_0c0cb4a6: /* original fef9, guest PC 0x0c0cb4a6 */
if(!s->budget--) { s->failed_pc=0x0c0cb4a6u; return 0; }
vf3_matrix_load(s,ram,14,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0cb4a8;
P_0c0cb4a8: /* original fff9, guest PC 0x0c0cb4a8 */
if(!s->budget--) { s->failed_pc=0x0c0cb4a8u; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0cb4aa;
P_0c0cb4aa: /* original 68f6, guest PC 0x0c0cb4aa */
if(!s->budget--) { s->failed_pc=0x0c0cb4aau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c0cb4ac;
P_0c0cb4ac: /* original 69f6, guest PC 0x0c0cb4ac */
if(!s->budget--) { s->failed_pc=0x0c0cb4acu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c0cb4ae;
P_0c0cb4ae: /* original 6af6, guest PC 0x0c0cb4ae */
if(!s->budget--) { s->failed_pc=0x0c0cb4aeu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0cb4b0;
P_0c0cb4b0: /* original 6bf6, guest PC 0x0c0cb4b0 */
if(!s->budget--) { s->failed_pc=0x0c0cb4b0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0cb4b2;
P_0c0cb4b2: /* original 6cf6, guest PC 0x0c0cb4b2 */
if(!s->budget--) { s->failed_pc=0x0c0cb4b2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0cb4b4;
P_0c0cb4b4: /* original 6df6, guest PC 0x0c0cb4b4 */
if(!s->budget--) { s->failed_pc=0x0c0cb4b4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0cb4b6;
P_0c0cb4b6: /* original 000b, guest PC 0x0c0cb4b6 */
if(!s->budget--) { s->failed_pc=0x0c0cb4b6u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0cb4b8: /* original 6ef6, guest PC 0x0c0cb4b8 */
if(!s->budget--) { s->failed_pc=0x0c0cb4b8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0cb4ba;
P_0c0cb4ba: /* original 2fe6, guest PC 0x0c0cb4ba */
if(!s->budget--) { s->failed_pc=0x0c0cb4bau; return 0; }
r[15]-=4; write(ram,r[15],r[14],4);
goto P_0c0cb4bc;
P_0c0cb4bc: /* original e004, guest PC 0x0c0cb4bc */
if(!s->budget--) { s->failed_pc=0x0c0cb4bcu; return 0; }
r[0]=0x00000004u;
goto P_0c0cb4be;
P_0c0cb4be: /* original 2fd6, guest PC 0x0c0cb4be */
if(!s->budget--) { s->failed_pc=0x0c0cb4beu; return 0; }
r[15]-=4; write(ram,r[15],r[13],4);
goto P_0c0cb4c0;
P_0c0cb4c0: /* original fffb, guest PC 0x0c0cb4c0 */
if(!s->budget--) { s->failed_pc=0x0c0cb4c0u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c0cb4c2;
P_0c0cb4c2: /* original ffeb, guest PC 0x0c0cb4c2 */
if(!s->budget--) { s->failed_pc=0x0c0cb4c2u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,14,r[15]);
goto P_0c0cb4c4;
P_0c0cb4c4: /* original ffdb, guest PC 0x0c0cb4c4 */
if(!s->budget--) { s->failed_pc=0x0c0cb4c4u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,13,r[15]);
goto P_0c0cb4c6;
P_0c0cb4c6: /* original 4f22, guest PC 0x0c0cb4c6 */
if(!s->budget--) { s->failed_pc=0x0c0cb4c6u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0cb4c8;
P_0c0cb4c8: /* original 7ff8, guest PC 0x0c0cb4c8 */
if(!s->budget--) { s->failed_pc=0x0c0cb4c8u; return 0; }
r[15]+=0xfffffff8u;
goto P_0c0cb4ca;
P_0c0cb4ca: /* original ff6a, guest PC 0x0c0cb4ca */
if(!s->budget--) { s->failed_pc=0x0c0cb4cau; return 0; }
vf3_matrix_store(s,ram,6,r[15]);
goto P_0c0cb4cc;
P_0c0cb4cc: /* original ff77, guest PC 0x0c0cb4cc */
if(!s->budget--) { s->failed_pc=0x0c0cb4ccu; return 0; }
vf3_matrix_store(s,ram,7,r[15]+r[0]);
goto P_0c0cb4ce;
P_0c0cb4ce: /* original c724, guest PC 0x0c0cb4ce */
if(!s->budget--) { s->failed_pc=0x0c0cb4ceu; return 0; }
r[0]=0x0c0cb560u;
goto P_0c0cb4d0;
P_0c0cb4d0: /* original f308, guest PC 0x0c0cb4d0 */
if(!s->budget--) { s->failed_pc=0x0c0cb4d0u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c0cb4d2;
P_0c0cb4d2: /* original fd4c, guest PC 0x0c0cb4d2 */
if(!s->budget--) { s->failed_pc=0x0c0cb4d2u; return 0; }
vf3_matrix_move(s,13,4);
goto P_0c0cb4d4;
P_0c0cb4d4: /* original fd30, guest PC 0x0c0cb4d4 */
if(!s->budget--) { s->failed_pc=0x0c0cb4d4u; return 0; }
fr[13]=vf3_fpu_binary(fr[13],fr[3],r[18],'+');
goto P_0c0cb4d6;
P_0c0cb4d6: /* original dd23, guest PC 0x0c0cb4d6 */
if(!s->budget--) { s->failed_pc=0x0c0cb4d6u; return 0; }
r[13]=read(ram,0x0c0cb564u,4);
goto P_0c0cb4d8;
P_0c0cb4d8: /* original fe5c, guest PC 0x0c0cb4d8 */
if(!s->budget--) { s->failed_pc=0x0c0cb4d8u; return 0; }
vf3_matrix_move(s,14,5);
goto P_0c0cb4da;
P_0c0cb4da: /* original f54d, guest PC 0x0c0cb4da */
if(!s->budget--) { s->failed_pc=0x0c0cb4dau; return 0; }
fr[5]^=0x80000000u;
goto P_0c0cb4dc;
P_0c0cb4dc: /* original 4d0b, guest PC 0x0c0cb4dc */
if(!s->budget--) { s->failed_pc=0x0c0cb4dcu; return 0; }
target=r[13];
r[16]=0x0c0cb4e0u;
vf3_matrix_move(s,4,13);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0cb4e0u) { target=s->pc; goto dispatch; }
goto P_0c0cb4e0;
P_0c0cb4de: /* original f4dc, guest PC 0x0c0cb4de */
if(!s->budget--) { s->failed_pc=0x0c0cb4deu; return 0; }
vf3_matrix_move(s,4,13);
goto P_0c0cb4e0;
P_0c0cb4e0: /* original ff0c, guest PC 0x0c0cb4e0 */
if(!s->budget--) { s->failed_pc=0x0c0cb4e0u; return 0; }
vf3_matrix_move(s,15,0);
goto P_0c0cb4e2;
P_0c0cb4e2: /* original a00e, guest PC 0x0c0cb4e2 */
if(!s->budget--) { s->failed_pc=0x0c0cb4e2u; return 0; }
r[14]=0x00000004u;
goto P_0c0cb502;
P_0c0cb4e4: /* original ee04, guest PC 0x0c0cb4e4 */
if(!s->budget--) { s->failed_pc=0x0c0cb4e4u; return 0; }
r[14]=0x00000004u;
goto P_0c0cb4e6;
P_0c0cb4e6: /* original e004, guest PC 0x0c0cb4e6 */
if(!s->budget--) { s->failed_pc=0x0c0cb4e6u; return 0; }
r[0]=0x00000004u;
goto P_0c0cb4e8;
P_0c0cb4e8: /* original f3f8, guest PC 0x0c0cb4e8 */
if(!s->budget--) { s->failed_pc=0x0c0cb4e8u; return 0; }
vf3_matrix_load(s,ram,3,r[15]);
goto P_0c0cb4ea;
P_0c0cb4ea: /* original f2f6, guest PC 0x0c0cb4ea */
if(!s->budget--) { s->failed_pc=0x0c0cb4eau; return 0; }
vf3_matrix_load(s,ram,2,r[15]+r[0]);
goto P_0c0cb4ec;
P_0c0cb4ec: /* original fd30, guest PC 0x0c0cb4ec */
if(!s->budget--) { s->failed_pc=0x0c0cb4ecu; return 0; }
fr[13]=vf3_fpu_binary(fr[13],fr[3],r[18],'+');
goto P_0c0cb4ee;
P_0c0cb4ee: /* original fe20, guest PC 0x0c0cb4ee */
if(!s->budget--) { s->failed_pc=0x0c0cb4eeu; return 0; }
fr[14]=vf3_fpu_binary(fr[14],fr[2],r[18],'+');
goto P_0c0cb4f0;
P_0c0cb4f0: /* original f5ec, guest PC 0x0c0cb4f0 */
if(!s->budget--) { s->failed_pc=0x0c0cb4f0u; return 0; }
vf3_matrix_move(s,5,14);
goto P_0c0cb4f2;
P_0c0cb4f2: /* original f54d, guest PC 0x0c0cb4f2 */
if(!s->budget--) { s->failed_pc=0x0c0cb4f2u; return 0; }
fr[5]^=0x80000000u;
goto P_0c0cb4f4;
P_0c0cb4f4: /* original 4d0b, guest PC 0x0c0cb4f4 */
if(!s->budget--) { s->failed_pc=0x0c0cb4f4u; return 0; }
target=r[13];
r[16]=0x0c0cb4f8u;
vf3_matrix_move(s,4,13);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0cb4f8u) { target=s->pc; goto dispatch; }
goto P_0c0cb4f8;
P_0c0cb4f6: /* original f4dc, guest PC 0x0c0cb4f6 */
if(!s->budget--) { s->failed_pc=0x0c0cb4f6u; return 0; }
vf3_matrix_move(s,4,13);
goto P_0c0cb4f8;
P_0c0cb4f8: /* original f40c, guest PC 0x0c0cb4f8 */
if(!s->budget--) { s->failed_pc=0x0c0cb4f8u; return 0; }
vf3_matrix_move(s,4,0);
goto P_0c0cb4fa;
P_0c0cb4fa: /* original f4f5, guest PC 0x0c0cb4fa */
if(!s->budget--) { s->failed_pc=0x0c0cb4fau; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[4])>as_float(fr[15]))!=0);
goto P_0c0cb4fc;
P_0c0cb4fc: /* original 8f01, guest PC 0x0c0cb4fc */
if(!s->budget--) { s->failed_pc=0x0c0cb4fcu; return 0; }
cond=r[17]&1u;
r[14]+=0xffffffffu;
if(!cond) { goto P_0c0cb502; }
goto P_0c0cb500;
P_0c0cb4fe: /* original 7eff, guest PC 0x0c0cb4fe */
if(!s->budget--) { s->failed_pc=0x0c0cb4feu; return 0; }
r[14]+=0xffffffffu;
goto P_0c0cb500;
P_0c0cb500: /* original ff4c, guest PC 0x0c0cb500 */
if(!s->budget--) { s->failed_pc=0x0c0cb500u; return 0; }
vf3_matrix_move(s,15,4);
goto P_0c0cb502;
P_0c0cb502: /* original 2ee8, guest PC 0x0c0cb502 */
if(!s->budget--) { s->failed_pc=0x0c0cb502u; return 0; }
r[17]=(r[17]&~1u)|(((r[14]&r[14])==0)!=0);
goto P_0c0cb504;
P_0c0cb504: /* original 8bef, guest PC 0x0c0cb504 */
if(!s->budget--) { s->failed_pc=0x0c0cb504u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0cb4e6; }
goto P_0c0cb506;
P_0c0cb506: /* original 7f08, guest PC 0x0c0cb506 */
if(!s->budget--) { s->failed_pc=0x0c0cb506u; return 0; }
r[15]+=0x00000008u;
goto P_0c0cb508;
P_0c0cb508: /* original c717, guest PC 0x0c0cb508 */
if(!s->budget--) { s->failed_pc=0x0c0cb508u; return 0; }
r[0]=0x0c0cb568u;
goto P_0c0cb50a;
P_0c0cb50a: /* original 4f26, guest PC 0x0c0cb50a */
if(!s->budget--) { s->failed_pc=0x0c0cb50au; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0cb50c;
P_0c0cb50c: /* original f308, guest PC 0x0c0cb50c */
if(!s->budget--) { s->failed_pc=0x0c0cb50cu; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c0cb50e;
P_0c0cb50e: /* original ff30, guest PC 0x0c0cb50e */
if(!s->budget--) { s->failed_pc=0x0c0cb50eu; return 0; }
fr[15]=vf3_fpu_binary(fr[15],fr[3],r[18],'+');
goto P_0c0cb510;
P_0c0cb510: /* original fdf9, guest PC 0x0c0cb510 */
if(!s->budget--) { s->failed_pc=0x0c0cb510u; return 0; }
vf3_matrix_load(s,ram,13,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0cb512;
P_0c0cb512: /* original fef9, guest PC 0x0c0cb512 */
if(!s->budget--) { s->failed_pc=0x0c0cb512u; return 0; }
vf3_matrix_load(s,ram,14,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0cb514;
P_0c0cb514: /* original f0fc, guest PC 0x0c0cb514 */
if(!s->budget--) { s->failed_pc=0x0c0cb514u; return 0; }
vf3_matrix_move(s,0,15);
goto P_0c0cb516;
P_0c0cb516: /* original fff9, guest PC 0x0c0cb516 */
if(!s->budget--) { s->failed_pc=0x0c0cb516u; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0cb518;
P_0c0cb518: /* original 6df6, guest PC 0x0c0cb518 */
if(!s->budget--) { s->failed_pc=0x0c0cb518u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0cb51a;
P_0c0cb51a: /* original 000b, guest PC 0x0c0cb51a */
if(!s->budget--) { s->failed_pc=0x0c0cb51au; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0cb51c: /* original 6ef6, guest PC 0x0c0cb51c */
if(!s->budget--) { s->failed_pc=0x0c0cb51cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0cb51e;
P_0c0cb51e: /* original 2fd6, guest PC 0x0c0cb51e */
if(!s->budget--) { s->failed_pc=0x0c0cb51eu; return 0; }
r[15]-=4; write(ram,r[15],r[13],4);
goto P_0c0cb520;
P_0c0cb520: /* original 2fc6, guest PC 0x0c0cb520 */
if(!s->budget--) { s->failed_pc=0x0c0cb520u; return 0; }
r[15]-=4; write(ram,r[15],r[12],4);
goto P_0c0cb522;
P_0c0cb522: /* original ec06, guest PC 0x0c0cb522 */
if(!s->budget--) { s->failed_pc=0x0c0cb522u; return 0; }
r[12]=0x00000006u;
goto P_0c0cb524;
P_0c0cb524: /* original 2fb6, guest PC 0x0c0cb524 */
if(!s->budget--) { s->failed_pc=0x0c0cb524u; return 0; }
r[15]-=4; write(ram,r[15],r[11],4);
goto P_0c0cb526;
P_0c0cb526: /* original 66c3, guest PC 0x0c0cb526 */
if(!s->budget--) { s->failed_pc=0x0c0cb526u; return 0; }
r[6]=r[12];
goto P_0c0cb528;
P_0c0cb528: /* original 2fa6, guest PC 0x0c0cb528 */
if(!s->budget--) { s->failed_pc=0x0c0cb528u; return 0; }
r[15]-=4; write(ram,r[15],r[10],4);
goto P_0c0cb52a;
P_0c0cb52a: /* original 2f96, guest PC 0x0c0cb52a */
if(!s->budget--) { s->failed_pc=0x0c0cb52au; return 0; }
r[15]-=4; write(ram,r[15],r[9],4);
goto P_0c0cb52c;
P_0c0cb52c: /* original fffb, guest PC 0x0c0cb52c */
if(!s->budget--) { s->failed_pc=0x0c0cb52cu; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c0cb52e;
P_0c0cb52e: /* original ffdb, guest PC 0x0c0cb52e */
if(!s->budget--) { s->failed_pc=0x0c0cb52eu; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,13,r[15]);
goto P_0c0cb530;
P_0c0cb530: /* original 9012, guest PC 0x0c0cb530 */
if(!s->budget--) { s->failed_pc=0x0c0cb530u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0cb558u,2);
goto P_0c0cb532;
P_0c0cb532: /* original 4f22, guest PC 0x0c0cb532 */
if(!s->budget--) { s->failed_pc=0x0c0cb532u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0cb534;
P_0c0cb534: /* original 094e, guest PC 0x0c0cb534 */
if(!s->budget--) { s->failed_pc=0x0c0cb534u; return 0; }
r[9]=read(ram,r[4]+r[0],4);
goto P_0c0cb536;
P_0c0cb536: /* original c70e, guest PC 0x0c0cb536 */
if(!s->budget--) { s->failed_pc=0x0c0cb536u; return 0; }
r[0]=0x0c0cb570u;
goto P_0c0cb538;
P_0c0cb538: /* original f308, guest PC 0x0c0cb538 */
if(!s->budget--) { s->failed_pc=0x0c0cb538u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c0cb53a;
P_0c0cb53a: /* original c70e, guest PC 0x0c0cb53a */
if(!s->budget--) { s->failed_pc=0x0c0cb53au; return 0; }
r[0]=0x0c0cb574u;
goto P_0c0cb53c;
P_0c0cb53c: /* original 7ff4, guest PC 0x0c0cb53c */
if(!s->budget--) { s->failed_pc=0x0c0cb53cu; return 0; }
r[15]+=0xfffffff4u;
goto P_0c0cb53e;
P_0c0cb53e: /* original 6742, guest PC 0x0c0cb53e */
if(!s->budget--) { s->failed_pc=0x0c0cb53eu; return 0; }
tmp=read(ram,r[4],4);
r[7]=tmp;
goto P_0c0cb540;
P_0c0cb540: /* original da0a, guest PC 0x0c0cb540 */
if(!s->budget--) { s->failed_pc=0x0c0cb540u; return 0; }
r[10]=read(ram,0x0c0cb56cu,4);
goto P_0c0cb542;
P_0c0cb542: /* original ff3a, guest PC 0x0c0cb542 */
if(!s->budget--) { s->failed_pc=0x0c0cb542u; return 0; }
vf3_matrix_store(s,ram,3,r[15]);
goto P_0c0cb544;
P_0c0cb544: /* original f708, guest PC 0x0c0cb544 */
if(!s->budget--) { s->failed_pc=0x0c0cb544u; return 0; }
vf3_matrix_load(s,ram,7,r[0]);
goto P_0c0cb546;
P_0c0cb546: /* original e004, guest PC 0x0c0cb546 */
if(!s->budget--) { s->failed_pc=0x0c0cb546u; return 0; }
r[0]=0x00000004u;
goto P_0c0cb548;
P_0c0cb548: /* original fb8d, guest PC 0x0c0cb548 */
if(!s->budget--) { s->failed_pc=0x0c0cb548u; return 0; }
fr[11]=0;
goto P_0c0cb54a;
P_0c0cb54a: /* original ffb7, guest PC 0x0c0cb54a */
if(!s->budget--) { s->failed_pc=0x0c0cb54au; return 0; }
vf3_matrix_store(s,ram,11,r[15]+r[0]);
goto P_0c0cb54c;
P_0c0cb54c: /* original e008, guest PC 0x0c0cb54c */
if(!s->budget--) { s->failed_pc=0x0c0cb54cu; return 0; }
r[0]=0x00000008u;
goto P_0c0cb54e;
P_0c0cb54e: /* original ffb7, guest PC 0x0c0cb54e */
if(!s->budget--) { s->failed_pc=0x0c0cb54eu; return 0; }
vf3_matrix_store(s,ram,11,r[15]+r[0]);
goto P_0c0cb550;
P_0c0cb550: /* original dd09, guest PC 0x0c0cb550 */
if(!s->budget--) { s->failed_pc=0x0c0cb550u; return 0; }
r[13]=read(ram,0x0c0cb578u,4);
goto P_0c0cb552;
P_0c0cb552: /* original a06d, guest PC 0x0c0cb552 */
if(!s->budget--) { s->failed_pc=0x0c0cb552u; return 0; }
r[11]=0x00000004u;
goto P_0c0cb630;
P_0c0cb554: /* original eb04, guest PC 0x0c0cb554 */
if(!s->budget--) { s->failed_pc=0x0c0cb554u; return 0; }
r[11]=0x00000004u;
return vf3_matrix_family(0x0c0cb556u,s,ram);
P_0c0cb57c: /* original 65c3, guest PC 0x0c0cb57c */
if(!s->budget--) { s->failed_pc=0x0c0cb57cu; return 0; }
r[5]=r[12];
goto P_0c0cb57e;
P_0c0cb57e: /* original 3568, guest PC 0x0c0cb57e */
if(!s->budget--) { s->failed_pc=0x0c0cb57eu; return 0; }
r[5]-=r[6];
goto P_0c0cb580;
P_0c0cb580: /* original 35ac, guest PC 0x0c0cb580 */
if(!s->budget--) { s->failed_pc=0x0c0cb580u; return 0; }
r[5]+=r[10];
goto P_0c0cb582;
P_0c0cb582: /* original d24d, guest PC 0x0c0cb582 */
if(!s->budget--) { s->failed_pc=0x0c0cb582u; return 0; }
r[2]=read(ram,0x0c0cb6b8u,4);
goto P_0c0cb584;
P_0c0cb584: /* original 6150, guest PC 0x0c0cb584 */
if(!s->budget--) { s->failed_pc=0x0c0cb584u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[5],1);
r[1]=tmp;
goto P_0c0cb586;
P_0c0cb586: /* original 420b, guest PC 0x0c0cb586 */
if(!s->budget--) { s->failed_pc=0x0c0cb586u; return 0; }
target=r[2];
r[16]=0x0c0cb58au;
r[0]=r[11];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0cb58au) { target=s->pc; goto dispatch; }
goto P_0c0cb58a;
P_0c0cb588: /* original 60b3, guest PC 0x0c0cb588 */
if(!s->budget--) { s->failed_pc=0x0c0cb588u; return 0; }
r[0]=r[11];
goto P_0c0cb58a;
P_0c0cb58a: /* original 928e, guest PC 0x0c0cb58a */
if(!s->budget--) { s->failed_pc=0x0c0cb58au; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0cb6aau,2);
goto P_0c0cb58c;
P_0c0cb58c: /* original 6503, guest PC 0x0c0cb58c */
if(!s->budget--) { s->failed_pc=0x0c0cb58cu; return 0; }
r[5]=r[0];
goto P_0c0cb58e;
P_0c0cb58e: /* original 635e, guest PC 0x0c0cb58e */
if(!s->budget--) { s->failed_pc=0x0c0cb58eu; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)r[5];
goto P_0c0cb590;
P_0c0cb590: /* original f3f8, guest PC 0x0c0cb590 */
if(!s->budget--) { s->failed_pc=0x0c0cb590u; return 0; }
vf3_matrix_load(s,ram,3,r[15]);
goto P_0c0cb592;
P_0c0cb592: /* original 324c, guest PC 0x0c0cb592 */
if(!s->budget--) { s->failed_pc=0x0c0cb592u; return 0; }
r[2]+=r[4];
goto P_0c0cb594;
P_0c0cb594: /* original 4308, guest PC 0x0c0cb594 */
if(!s->budget--) { s->failed_pc=0x0c0cb594u; return 0; }
r[3]<<=2;
goto P_0c0cb596;
P_0c0cb596: /* original 332c, guest PC 0x0c0cb596 */
if(!s->budget--) { s->failed_pc=0x0c0cb596u; return 0; }
r[3]+=r[2];
goto P_0c0cb598;
P_0c0cb598: /* original 615e, guest PC 0x0c0cb598 */
if(!s->budget--) { s->failed_pc=0x0c0cb598u; return 0; }
r[1]=(uint32_t)(int32_t)(int8_t)r[5];
goto P_0c0cb59a;
P_0c0cb59a: /* original f438, guest PC 0x0c0cb59a */
if(!s->budget--) { s->failed_pc=0x0c0cb59au; return 0; }
vf3_matrix_load(s,ram,4,r[3]);
goto P_0c0cb59c;
P_0c0cb59c: /* original 6313, guest PC 0x0c0cb59c */
if(!s->budget--) { s->failed_pc=0x0c0cb59cu; return 0; }
r[3]=r[1];
goto P_0c0cb59e;
P_0c0cb59e: /* original 4100, guest PC 0x0c0cb59e */
if(!s->budget--) { s->failed_pc=0x0c0cb59eu; return 0; }
r[17]=(r[17]&~1u)|((r[1]>>31)!=0);
r[1]<<=1;
goto P_0c0cb5a0;
P_0c0cb5a0: /* original 313c, guest PC 0x0c0cb5a0 */
if(!s->budget--) { s->failed_pc=0x0c0cb5a0u; return 0; }
r[1]+=r[3];
goto P_0c0cb5a2;
P_0c0cb5a2: /* original fa4c, guest PC 0x0c0cb5a2 */
if(!s->budget--) { s->failed_pc=0x0c0cb5a2u; return 0; }
vf3_matrix_move(s,10,4);
goto P_0c0cb5a4;
P_0c0cb5a4: /* original 4108, guest PC 0x0c0cb5a4 */
if(!s->budget--) { s->failed_pc=0x0c0cb5a4u; return 0; }
r[1]<<=2;
goto P_0c0cb5a6;
P_0c0cb5a6: /* original 319c, guest PC 0x0c0cb5a6 */
if(!s->budget--) { s->failed_pc=0x0c0cb5a6u; return 0; }
r[1]+=r[9];
goto P_0c0cb5a8;
P_0c0cb5a8: /* original f618, guest PC 0x0c0cb5a8 */
if(!s->budget--) { s->failed_pc=0x0c0cb5a8u; return 0; }
vf3_matrix_load(s,ram,6,r[1]);
goto P_0c0cb5aa;
P_0c0cb5aa: /* original e008, guest PC 0x0c0cb5aa */
if(!s->budget--) { s->failed_pc=0x0c0cb5aau; return 0; }
r[0]=0x00000008u;
goto P_0c0cb5ac;
P_0c0cb5ac: /* original f516, guest PC 0x0c0cb5ac */
if(!s->budget--) { s->failed_pc=0x0c0cb5acu; return 0; }
vf3_matrix_load(s,ram,5,r[1]+r[0]);
goto P_0c0cb5ae;
P_0c0cb5ae: /* original f96c, guest PC 0x0c0cb5ae */
if(!s->budget--) { s->failed_pc=0x0c0cb5aeu; return 0; }
vf3_matrix_move(s,9,6);
goto P_0c0cb5b0;
P_0c0cb5b0: /* original fa60, guest PC 0x0c0cb5b0 */
if(!s->budget--) { s->failed_pc=0x0c0cb5b0u; return 0; }
fr[10]=vf3_fpu_binary(fr[10],fr[6],r[18],'+');
goto P_0c0cb5b2;
P_0c0cb5b2: /* original f64c, guest PC 0x0c0cb5b2 */
if(!s->budget--) { s->failed_pc=0x0c0cb5b2u; return 0; }
vf3_matrix_move(s,6,4);
goto P_0c0cb5b4;
P_0c0cb5b4: /* original f650, guest PC 0x0c0cb5b4 */
if(!s->budget--) { s->failed_pc=0x0c0cb5b4u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[5],r[18],'+');
goto P_0c0cb5b6;
P_0c0cb5b6: /* original f941, guest PC 0x0c0cb5b6 */
if(!s->budget--) { s->failed_pc=0x0c0cb5b6u; return 0; }
fr[9]=vf3_fpu_binary(fr[9],fr[4],r[18],'-');
goto P_0c0cb5b8;
P_0c0cb5b8: /* original f85c, guest PC 0x0c0cb5b8 */
if(!s->budget--) { s->failed_pc=0x0c0cb5b8u; return 0; }
vf3_matrix_move(s,8,5);
goto P_0c0cb5ba;
P_0c0cb5ba: /* original f841, guest PC 0x0c0cb5ba */
if(!s->budget--) { s->failed_pc=0x0c0cb5bau; return 0; }
fr[8]=vf3_fpu_binary(fr[8],fr[4],r[18],'-');
goto P_0c0cb5bc;
P_0c0cb5bc: /* original f0ac, guest PC 0x0c0cb5bc */
if(!s->budget--) { s->failed_pc=0x0c0cb5bcu; return 0; }
vf3_matrix_move(s,0,10);
goto P_0c0cb5be;
P_0c0cb5be: /* original f031, guest PC 0x0c0cb5be */
if(!s->budget--) { s->failed_pc=0x0c0cb5beu; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'-');
goto P_0c0cb5c0;
P_0c0cb5c0: /* original ff6c, guest PC 0x0c0cb5c0 */
if(!s->budget--) { s->failed_pc=0x0c0cb5c0u; return 0; }
vf3_matrix_move(s,15,6);
goto P_0c0cb5c2;
P_0c0cb5c2: /* original ff31, guest PC 0x0c0cb5c2 */
if(!s->budget--) { s->failed_pc=0x0c0cb5c2u; return 0; }
fr[15]=vf3_fpu_binary(fr[15],fr[3],r[18],'-');
goto P_0c0cb5c4;
P_0c0cb5c4: /* original f19c, guest PC 0x0c0cb5c4 */
if(!s->budget--) { s->failed_pc=0x0c0cb5c4u; return 0; }
vf3_matrix_move(s,1,9);
goto P_0c0cb5c6;
P_0c0cb5c6: /* original f171, guest PC 0x0c0cb5c6 */
if(!s->budget--) { s->failed_pc=0x0c0cb5c6u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[7],r[18],'-');
goto P_0c0cb5c8;
P_0c0cb5c8: /* original fd8c, guest PC 0x0c0cb5c8 */
if(!s->budget--) { s->failed_pc=0x0c0cb5c8u; return 0; }
vf3_matrix_move(s,13,8);
goto P_0c0cb5ca;
P_0c0cb5ca: /* original f38d, guest PC 0x0c0cb5ca */
if(!s->budget--) { s->failed_pc=0x0c0cb5cau; return 0; }
fr[3]=0;
goto P_0c0cb5cc;
P_0c0cb5cc: /* original f305, guest PC 0x0c0cb5cc */
if(!s->budget--) { s->failed_pc=0x0c0cb5ccu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[0]))!=0);
goto P_0c0cb5ce;
P_0c0cb5ce: /* original fd71, guest PC 0x0c0cb5ce */
if(!s->budget--) { s->failed_pc=0x0c0cb5ceu; return 0; }
fr[13]=vf3_fpu_binary(fr[13],fr[7],r[18],'-');
goto P_0c0cb5d0;
P_0c0cb5d0: /* original f48d, guest PC 0x0c0cb5d0 */
if(!s->budget--) { s->failed_pc=0x0c0cb5d0u; return 0; }
fr[4]=0;
goto P_0c0cb5d2;
P_0c0cb5d2: /* original f64c, guest PC 0x0c0cb5d2 */
if(!s->budget--) { s->failed_pc=0x0c0cb5d2u; return 0; }
vf3_matrix_move(s,6,4);
goto P_0c0cb5d4;
P_0c0cb5d4: /* original 8d03, guest PC 0x0c0cb5d4 */
if(!s->budget--) { s->failed_pc=0x0c0cb5d4u; return 0; }
cond=r[17]&1u;
vf3_matrix_move(s,5,4);
if(cond) { goto P_0c0cb5de; }
goto P_0c0cb5d8;
P_0c0cb5d6: /* original f54c, guest PC 0x0c0cb5d6 */
if(!s->budget--) { s->failed_pc=0x0c0cb5d6u; return 0; }
vf3_matrix_move(s,5,4);
goto P_0c0cb5d8;
P_0c0cb5d8: /* original f40c, guest PC 0x0c0cb5d8 */
if(!s->budget--) { s->failed_pc=0x0c0cb5d8u; return 0; }
vf3_matrix_move(s,4,0);
goto P_0c0cb5da;
P_0c0cb5da: /* original f50c, guest PC 0x0c0cb5da */
if(!s->budget--) { s->failed_pc=0x0c0cb5dau; return 0; }
vf3_matrix_move(s,5,0);
goto P_0c0cb5dc;
P_0c0cb5dc: /* original f452, guest PC 0x0c0cb5dc */
if(!s->budget--) { s->failed_pc=0x0c0cb5dcu; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[5],r[18],'*');
goto P_0c0cb5de;
P_0c0cb5de: /* original f38d, guest PC 0x0c0cb5de */
if(!s->budget--) { s->failed_pc=0x0c0cb5deu; return 0; }
fr[3]=0;
goto P_0c0cb5e0;
P_0c0cb5e0: /* original f135, guest PC 0x0c0cb5e0 */
if(!s->budget--) { s->failed_pc=0x0c0cb5e0u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[1])>as_float(fr[3]))!=0);
goto P_0c0cb5e2;
P_0c0cb5e2: /* original 8907, guest PC 0x0c0cb5e2 */
if(!s->budget--) { s->failed_pc=0x0c0cb5e2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0cb5f4; }
goto P_0c0cb5e4;
P_0c0cb5e4: /* original f39c, guest PC 0x0c0cb5e4 */
if(!s->budget--) { s->failed_pc=0x0c0cb5e4u; return 0; }
vf3_matrix_move(s,3,9);
goto P_0c0cb5e6;
P_0c0cb5e6: /* original f97c, guest PC 0x0c0cb5e6 */
if(!s->budget--) { s->failed_pc=0x0c0cb5e6u; return 0; }
vf3_matrix_move(s,9,7);
goto P_0c0cb5e8;
P_0c0cb5e8: /* original f931, guest PC 0x0c0cb5e8 */
if(!s->budget--) { s->failed_pc=0x0c0cb5e8u; return 0; }
fr[9]=vf3_fpu_binary(fr[9],fr[3],r[18],'-');
goto P_0c0cb5ea;
P_0c0cb5ea: /* original f24c, guest PC 0x0c0cb5ea */
if(!s->budget--) { s->failed_pc=0x0c0cb5eau; return 0; }
vf3_matrix_move(s,2,4);
goto P_0c0cb5ec;
P_0c0cb5ec: /* original f51c, guest PC 0x0c0cb5ec */
if(!s->budget--) { s->failed_pc=0x0c0cb5ecu; return 0; }
vf3_matrix_move(s,5,1);
goto P_0c0cb5ee;
P_0c0cb5ee: /* original f09c, guest PC 0x0c0cb5ee */
if(!s->budget--) { s->failed_pc=0x0c0cb5eeu; return 0; }
vf3_matrix_move(s,0,9);
goto P_0c0cb5f0;
P_0c0cb5f0: /* original f29e, guest PC 0x0c0cb5f0 */
if(!s->budget--) { s->failed_pc=0x0c0cb5f0u; return 0; }
fr[2]=vf3_fpu_mac(fr[0],fr[9],fr[2],r[18]);
goto P_0c0cb5f2;
P_0c0cb5f2: /* original f42c, guest PC 0x0c0cb5f2 */
if(!s->budget--) { s->failed_pc=0x0c0cb5f2u; return 0; }
vf3_matrix_move(s,4,2);
goto P_0c0cb5f4;
P_0c0cb5f4: /* original f38d, guest PC 0x0c0cb5f4 */
if(!s->budget--) { s->failed_pc=0x0c0cb5f4u; return 0; }
fr[3]=0;
goto P_0c0cb5f6;
P_0c0cb5f6: /* original f3f5, guest PC 0x0c0cb5f6 */
if(!s->budget--) { s->failed_pc=0x0c0cb5f6u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[15]))!=0);
goto P_0c0cb5f8;
P_0c0cb5f8: /* original 8d05, guest PC 0x0c0cb5f8 */
if(!s->budget--) { s->failed_pc=0x0c0cb5f8u; return 0; }
cond=r[17]&1u;
fr[2]=0;
if(cond) { goto P_0c0cb606; }
goto P_0c0cb5fc;
P_0c0cb5fa: /* original f28d, guest PC 0x0c0cb5fa */
if(!s->budget--) { s->failed_pc=0x0c0cb5fau; return 0; }
fr[2]=0;
goto P_0c0cb5fc;
P_0c0cb5fc: /* original f0fc, guest PC 0x0c0cb5fc */
if(!s->budget--) { s->failed_pc=0x0c0cb5fcu; return 0; }
vf3_matrix_move(s,0,15);
goto P_0c0cb5fe;
P_0c0cb5fe: /* original f34c, guest PC 0x0c0cb5fe */
if(!s->budget--) { s->failed_pc=0x0c0cb5feu; return 0; }
vf3_matrix_move(s,3,4);
goto P_0c0cb600;
P_0c0cb600: /* original f6fc, guest PC 0x0c0cb600 */
if(!s->budget--) { s->failed_pc=0x0c0cb600u; return 0; }
vf3_matrix_move(s,6,15);
goto P_0c0cb602;
P_0c0cb602: /* original f36e, guest PC 0x0c0cb602 */
if(!s->budget--) { s->failed_pc=0x0c0cb602u; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[6],fr[3],r[18]);
goto P_0c0cb604;
P_0c0cb604: /* original f43c, guest PC 0x0c0cb604 */
if(!s->budget--) { s->failed_pc=0x0c0cb604u; return 0; }
vf3_matrix_move(s,4,3);
goto P_0c0cb606;
P_0c0cb606: /* original fd25, guest PC 0x0c0cb606 */
if(!s->budget--) { s->failed_pc=0x0c0cb606u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[13])>as_float(fr[2]))!=0);
goto P_0c0cb608;
P_0c0cb608: /* original 8907, guest PC 0x0c0cb608 */
if(!s->budget--) { s->failed_pc=0x0c0cb608u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0cb61a; }
goto P_0c0cb60a;
P_0c0cb60a: /* original f38c, guest PC 0x0c0cb60a */
if(!s->budget--) { s->failed_pc=0x0c0cb60au; return 0; }
vf3_matrix_move(s,3,8);
goto P_0c0cb60c;
P_0c0cb60c: /* original f87c, guest PC 0x0c0cb60c */
if(!s->budget--) { s->failed_pc=0x0c0cb60cu; return 0; }
vf3_matrix_move(s,8,7);
goto P_0c0cb60e;
P_0c0cb60e: /* original f831, guest PC 0x0c0cb60e */
if(!s->budget--) { s->failed_pc=0x0c0cb60eu; return 0; }
fr[8]=vf3_fpu_binary(fr[8],fr[3],r[18],'-');
goto P_0c0cb610;
P_0c0cb610: /* original f24c, guest PC 0x0c0cb610 */
if(!s->budget--) { s->failed_pc=0x0c0cb610u; return 0; }
vf3_matrix_move(s,2,4);
goto P_0c0cb612;
P_0c0cb612: /* original f6dc, guest PC 0x0c0cb612 */
if(!s->budget--) { s->failed_pc=0x0c0cb612u; return 0; }
vf3_matrix_move(s,6,13);
goto P_0c0cb614;
P_0c0cb614: /* original f08c, guest PC 0x0c0cb614 */
if(!s->budget--) { s->failed_pc=0x0c0cb614u; return 0; }
vf3_matrix_move(s,0,8);
goto P_0c0cb616;
P_0c0cb616: /* original f28e, guest PC 0x0c0cb616 */
if(!s->budget--) { s->failed_pc=0x0c0cb616u; return 0; }
fr[2]=vf3_fpu_mac(fr[0],fr[8],fr[2],r[18]);
goto P_0c0cb618;
P_0c0cb618: /* original f42c, guest PC 0x0c0cb618 */
if(!s->budget--) { s->failed_pc=0x0c0cb618u; return 0; }
vf3_matrix_move(s,4,2);
goto P_0c0cb61a;
P_0c0cb61a: /* original f4b5, guest PC 0x0c0cb61a */
if(!s->budget--) { s->failed_pc=0x0c0cb61au; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[4])>as_float(fr[11]))!=0);
goto P_0c0cb61c;
P_0c0cb61c: /* original 8f08, guest PC 0x0c0cb61c */
if(!s->budget--) { s->failed_pc=0x0c0cb61cu; return 0; }
cond=r[17]&1u;
r[6]+=0xffffffffu;
if(!cond) { goto P_0c0cb630; }
goto P_0c0cb620;
P_0c0cb61e: /* original 76ff, guest PC 0x0c0cb61e */
if(!s->budget--) { s->failed_pc=0x0c0cb61eu; return 0; }
r[6]+=0xffffffffu;
goto P_0c0cb620;
P_0c0cb620: /* original e008, guest PC 0x0c0cb620 */
if(!s->budget--) { s->failed_pc=0x0c0cb620u; return 0; }
r[0]=0x00000008u;
goto P_0c0cb622;
P_0c0cb622: /* original f54d, guest PC 0x0c0cb622 */
if(!s->budget--) { s->failed_pc=0x0c0cb622u; return 0; }
fr[5]^=0x80000000u;
goto P_0c0cb624;
P_0c0cb624: /* original ff57, guest PC 0x0c0cb624 */
if(!s->budget--) { s->failed_pc=0x0c0cb624u; return 0; }
vf3_matrix_store(s,ram,5,r[15]+r[0]);
goto P_0c0cb626;
P_0c0cb626: /* original e004, guest PC 0x0c0cb626 */
if(!s->budget--) { s->failed_pc=0x0c0cb626u; return 0; }
r[0]=0x00000004u;
goto P_0c0cb628;
P_0c0cb628: /* original f64d, guest PC 0x0c0cb628 */
if(!s->budget--) { s->failed_pc=0x0c0cb628u; return 0; }
fr[6]^=0x80000000u;
goto P_0c0cb62a;
P_0c0cb62a: /* original 27db, guest PC 0x0c0cb62a */
if(!s->budget--) { s->failed_pc=0x0c0cb62au; return 0; }
r[7]|=r[13];
goto P_0c0cb62c;
P_0c0cb62c: /* original ff67, guest PC 0x0c0cb62c */
if(!s->budget--) { s->failed_pc=0x0c0cb62cu; return 0; }
vf3_matrix_store(s,ram,6,r[15]+r[0]);
goto P_0c0cb62e;
P_0c0cb62e: /* original fb4c, guest PC 0x0c0cb62e */
if(!s->budget--) { s->failed_pc=0x0c0cb62eu; return 0; }
vf3_matrix_move(s,11,4);
goto P_0c0cb630;
P_0c0cb630: /* original 2668, guest PC 0x0c0cb630 */
if(!s->budget--) { s->failed_pc=0x0c0cb630u; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[6])==0)!=0);
goto P_0c0cb632;
P_0c0cb632: /* original 8ba3, guest PC 0x0c0cb632 */
if(!s->budget--) { s->failed_pc=0x0c0cb632u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0cb57c; }
goto P_0c0cb634;
P_0c0cb634: /* original e008, guest PC 0x0c0cb634 */
if(!s->budget--) { s->failed_pc=0x0c0cb634u; return 0; }
r[0]=0x00000008u;
goto P_0c0cb636;
P_0c0cb636: /* original f3f6, guest PC 0x0c0cb636 */
if(!s->budget--) { s->failed_pc=0x0c0cb636u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0cb638;
P_0c0cb638: /* original 9038, guest PC 0x0c0cb638 */
if(!s->budget--) { s->failed_pc=0x0c0cb638u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0cb6acu,2);
goto P_0c0cb63a;
P_0c0cb63a: /* original f437, guest PC 0x0c0cb63a */
if(!s->budget--) { s->failed_pc=0x0c0cb63au; return 0; }
vf3_matrix_store(s,ram,3,r[4]+r[0]);
goto P_0c0cb63c;
P_0c0cb63c: /* original e004, guest PC 0x0c0cb63c */
if(!s->budget--) { s->failed_pc=0x0c0cb63cu; return 0; }
r[0]=0x00000004u;
goto P_0c0cb63e;
P_0c0cb63e: /* original f3f6, guest PC 0x0c0cb63e */
if(!s->budget--) { s->failed_pc=0x0c0cb63eu; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0cb640;
P_0c0cb640: /* original 7f0c, guest PC 0x0c0cb640 */
if(!s->budget--) { s->failed_pc=0x0c0cb640u; return 0; }
r[15]+=0x0000000cu;
goto P_0c0cb642;
P_0c0cb642: /* original 4f26, guest PC 0x0c0cb642 */
if(!s->budget--) { s->failed_pc=0x0c0cb642u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0cb644;
P_0c0cb644: /* original 9033, guest PC 0x0c0cb644 */
if(!s->budget--) { s->failed_pc=0x0c0cb644u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0cb6aeu,2);
goto P_0c0cb646;
P_0c0cb646: /* original f437, guest PC 0x0c0cb646 */
if(!s->budget--) { s->failed_pc=0x0c0cb646u; return 0; }
vf3_matrix_store(s,ram,3,r[4]+r[0]);
goto P_0c0cb648;
P_0c0cb648: /* original 2472, guest PC 0x0c0cb648 */
if(!s->budget--) { s->failed_pc=0x0c0cb648u; return 0; }
write(ram,r[4],r[7],4);
goto P_0c0cb64a;
P_0c0cb64a: /* original fdf9, guest PC 0x0c0cb64a */
if(!s->budget--) { s->failed_pc=0x0c0cb64au; return 0; }
vf3_matrix_load(s,ram,13,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0cb64c;
P_0c0cb64c: /* original fff9, guest PC 0x0c0cb64c */
if(!s->budget--) { s->failed_pc=0x0c0cb64cu; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0cb64e;
P_0c0cb64e: /* original 69f6, guest PC 0x0c0cb64e */
if(!s->budget--) { s->failed_pc=0x0c0cb64eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c0cb650;
P_0c0cb650: /* original 6af6, guest PC 0x0c0cb650 */
if(!s->budget--) { s->failed_pc=0x0c0cb650u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0cb652;
P_0c0cb652: /* original 6bf6, guest PC 0x0c0cb652 */
if(!s->budget--) { s->failed_pc=0x0c0cb652u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0cb654;
P_0c0cb654: /* original 6cf6, guest PC 0x0c0cb654 */
if(!s->budget--) { s->failed_pc=0x0c0cb654u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0cb656;
P_0c0cb656: /* original 000b, guest PC 0x0c0cb656 */
if(!s->budget--) { s->failed_pc=0x0c0cb656u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
s->pc=target; return ram->oob==0;
P_0c0cb658: /* original 6df6, guest PC 0x0c0cb658 */
if(!s->budget--) { s->failed_pc=0x0c0cb658u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0cb65a;
P_0c0cb65a: /* original 4f22, guest PC 0x0c0cb65a */
if(!s->budget--) { s->failed_pc=0x0c0cb65au; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0cb65c;
P_0c0cb65c: /* original 7ffc, guest PC 0x0c0cb65c */
if(!s->budget--) { s->failed_pc=0x0c0cb65cu; return 0; }
r[15]+=0xfffffffcu;
goto P_0c0cb65e;
P_0c0cb65e: /* original 2f52, guest PC 0x0c0cb65e */
if(!s->budget--) { s->failed_pc=0x0c0cb65eu; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0cb660;
P_0c0cb660: /* original d117, guest PC 0x0c0cb660 */
if(!s->budget--) { s->failed_pc=0x0c0cb660u; return 0; }
r[1]=read(ram,0x0c0cb6c0u,4);
goto P_0c0cb662;
P_0c0cb662: /* original d316, guest PC 0x0c0cb662 */
if(!s->budget--) { s->failed_pc=0x0c0cb662u; return 0; }
r[3]=read(ram,0x0c0cb6bcu,4);
goto P_0c0cb664;
P_0c0cb664: /* original 6212, guest PC 0x0c0cb664 */
if(!s->budget--) { s->failed_pc=0x0c0cb664u; return 0; }
tmp=read(ram,r[1],4);
r[2]=tmp;
goto P_0c0cb666;
P_0c0cb666: /* original 2238, guest PC 0x0c0cb666 */
if(!s->budget--) { s->failed_pc=0x0c0cb666u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c0cb668;
P_0c0cb668: /* original 8b03, guest PC 0x0c0cb668 */
if(!s->budget--) { s->failed_pc=0x0c0cb668u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0cb672; }
goto P_0c0cb66a;
P_0c0cb66a: /* original b006, guest PC 0x0c0cb66a */
if(!s->budget--) { s->failed_pc=0x0c0cb66au; return 0; }
target=0x0c0cb67au; r[16]=0x0c0cb66eu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0cb66eu) { target=s->pc; goto dispatch; }
goto P_0c0cb66e;
P_0c0cb66c: /* original 0009, guest PC 0x0c0cb66c */
if(!s->budget--) { s->failed_pc=0x0c0cb66cu; return 0; }
goto P_0c0cb66e;
P_0c0cb66e: /* original b004, guest PC 0x0c0cb66e */
if(!s->budget--) { s->failed_pc=0x0c0cb66eu; return 0; }
target=0x0c0cb67au; r[16]=0x0c0cb672u;
tmp=read(ram,r[15],4);
r[4]=tmp;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0cb672u) { target=s->pc; goto dispatch; }
goto P_0c0cb672;
P_0c0cb670: /* original 64f2, guest PC 0x0c0cb670 */
if(!s->budget--) { s->failed_pc=0x0c0cb670u; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c0cb672;
P_0c0cb672: /* original 7f04, guest PC 0x0c0cb672 */
if(!s->budget--) { s->failed_pc=0x0c0cb672u; return 0; }
r[15]+=0x00000004u;
goto P_0c0cb674;
P_0c0cb674: /* original 4f26, guest PC 0x0c0cb674 */
if(!s->budget--) { s->failed_pc=0x0c0cb674u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0cb676;
P_0c0cb676: /* original 000b, guest PC 0x0c0cb676 */
if(!s->budget--) { s->failed_pc=0x0c0cb676u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c0cb678: /* original 0009, guest PC 0x0c0cb678 */
if(!s->budget--) { s->failed_pc=0x0c0cb678u; return 0; }
goto P_0c0cb67a;
P_0c0cb67a: /* original 2fd6, guest PC 0x0c0cb67a */
if(!s->budget--) { s->failed_pc=0x0c0cb67au; return 0; }
r[15]-=4; write(ram,r[15],r[13],4);
goto P_0c0cb67c;
P_0c0cb67c: /* original 2fc6, guest PC 0x0c0cb67c */
if(!s->budget--) { s->failed_pc=0x0c0cb67cu; return 0; }
r[15]-=4; write(ram,r[15],r[12],4);
goto P_0c0cb67e;
P_0c0cb67e: /* original ec04, guest PC 0x0c0cb67e */
if(!s->budget--) { s->failed_pc=0x0c0cb67eu; return 0; }
r[12]=0x00000004u;
goto P_0c0cb680;
P_0c0cb680: /* original 2fb6, guest PC 0x0c0cb680 */
if(!s->budget--) { s->failed_pc=0x0c0cb680u; return 0; }
r[15]-=4; write(ram,r[15],r[11],4);
goto P_0c0cb682;
P_0c0cb682: /* original eb06, guest PC 0x0c0cb682 */
if(!s->budget--) { s->failed_pc=0x0c0cb682u; return 0; }
r[11]=0x00000006u;
goto P_0c0cb684;
P_0c0cb684: /* original 2fa6, guest PC 0x0c0cb684 */
if(!s->budget--) { s->failed_pc=0x0c0cb684u; return 0; }
r[15]-=4; write(ram,r[15],r[10],4);
goto P_0c0cb686;
P_0c0cb686: /* original 65b3, guest PC 0x0c0cb686 */
if(!s->budget--) { s->failed_pc=0x0c0cb686u; return 0; }
r[5]=r[11];
goto P_0c0cb688;
P_0c0cb688: /* original 2f96, guest PC 0x0c0cb688 */
if(!s->budget--) { s->failed_pc=0x0c0cb688u; return 0; }
r[15]-=4; write(ram,r[15],r[9],4);
goto P_0c0cb68a;
P_0c0cb68a: /* original 9011, guest PC 0x0c0cb68a */
if(!s->budget--) { s->failed_pc=0x0c0cb68au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0cb6b0u,2);
goto P_0c0cb68c;
P_0c0cb68c: /* original 9712, guest PC 0x0c0cb68c */
if(!s->budget--) { s->failed_pc=0x0c0cb68cu; return 0; }
r[7]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0cb6b4u,2);
goto P_0c0cb68e;
P_0c0cb68e: /* original 094e, guest PC 0x0c0cb68e */
if(!s->budget--) { s->failed_pc=0x0c0cb68eu; return 0; }
r[9]=read(ram,r[4]+r[0],4);
goto P_0c0cb690;
P_0c0cb690: /* original c70d, guest PC 0x0c0cb690 */
if(!s->budget--) { s->failed_pc=0x0c0cb690u; return 0; }
r[0]=0x0c0cb6c8u;
goto P_0c0cb692;
P_0c0cb692: /* original fa08, guest PC 0x0c0cb692 */
if(!s->budget--) { s->failed_pc=0x0c0cb692u; return 0; }
vf3_matrix_load(s,ram,10,r[0]);
goto P_0c0cb694;
P_0c0cb694: /* original c70d, guest PC 0x0c0cb694 */
if(!s->budget--) { s->failed_pc=0x0c0cb694u; return 0; }
r[0]=0x0c0cb6ccu;
goto P_0c0cb696;
P_0c0cb696: /* original f108, guest PC 0x0c0cb696 */
if(!s->budget--) { s->failed_pc=0x0c0cb696u; return 0; }
vf3_matrix_load(s,ram,1,r[0]);
goto P_0c0cb698;
P_0c0cb698: /* original c70d, guest PC 0x0c0cb698 */
if(!s->budget--) { s->failed_pc=0x0c0cb698u; return 0; }
r[0]=0x0c0cb6d0u;
goto P_0c0cb69a;
P_0c0cb69a: /* original 9d0a, guest PC 0x0c0cb69a */
if(!s->budget--) { s->failed_pc=0x0c0cb69au; return 0; }
r[13]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0cb6b2u,2);
goto P_0c0cb69c;
P_0c0cb69c: /* original 374c, guest PC 0x0c0cb69c */
if(!s->budget--) { s->failed_pc=0x0c0cb69cu; return 0; }
r[7]+=r[4];
goto P_0c0cb69e;
P_0c0cb69e: /* original 4f22, guest PC 0x0c0cb69e */
if(!s->budget--) { s->failed_pc=0x0c0cb69eu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0cb6a0;
P_0c0cb6a0: /* original da08, guest PC 0x0c0cb6a0 */
if(!s->budget--) { s->failed_pc=0x0c0cb6a0u; return 0; }
r[10]=read(ram,0x0c0cb6c4u,4);
goto P_0c0cb6a2;
P_0c0cb6a2: /* original 3d4c, guest PC 0x0c0cb6a2 */
if(!s->budget--) { s->failed_pc=0x0c0cb6a2u; return 0; }
r[13]+=r[4];
goto P_0c0cb6a4;
P_0c0cb6a4: /* original fb08, guest PC 0x0c0cb6a4 */
if(!s->budget--) { s->failed_pc=0x0c0cb6a4u; return 0; }
vf3_matrix_load(s,ram,11,r[0]);
goto P_0c0cb6a6;
P_0c0cb6a6: /* original a059, guest PC 0x0c0cb6a6 */
if(!s->budget--) { s->failed_pc=0x0c0cb6a6u; return 0; }
fr[8]=0;
goto P_0c0cb75c;
P_0c0cb6a8: /* original f88d, guest PC 0x0c0cb6a8 */
if(!s->budget--) { s->failed_pc=0x0c0cb6a8u; return 0; }
fr[8]=0;
return vf3_matrix_family(0x0c0cb6aau,s,ram);
P_0c0cb6d4: /* original 64b3, guest PC 0x0c0cb6d4 */
if(!s->budget--) { s->failed_pc=0x0c0cb6d4u; return 0; }
r[4]=r[11];
goto P_0c0cb6d6;
P_0c0cb6d6: /* original 3458, guest PC 0x0c0cb6d6 */
if(!s->budget--) { s->failed_pc=0x0c0cb6d6u; return 0; }
r[4]-=r[5];
goto P_0c0cb6d8;
P_0c0cb6d8: /* original 34ac, guest PC 0x0c0cb6d8 */
if(!s->budget--) { s->failed_pc=0x0c0cb6d8u; return 0; }
r[4]+=r[10];
goto P_0c0cb6da;
P_0c0cb6da: /* original d225, guest PC 0x0c0cb6da */
if(!s->budget--) { s->failed_pc=0x0c0cb6dau; return 0; }
r[2]=read(ram,0x0c0cb770u,4);
goto P_0c0cb6dc;
P_0c0cb6dc: /* original 6140, guest PC 0x0c0cb6dc */
if(!s->budget--) { s->failed_pc=0x0c0cb6dcu; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[4],1);
r[1]=tmp;
goto P_0c0cb6de;
P_0c0cb6de: /* original 420b, guest PC 0x0c0cb6de */
if(!s->budget--) { s->failed_pc=0x0c0cb6deu; return 0; }
target=r[2];
r[16]=0x0c0cb6e2u;
r[0]=r[12];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0cb6e2u) { target=s->pc; goto dispatch; }
goto P_0c0cb6e2;
P_0c0cb6e0: /* original 60c3, guest PC 0x0c0cb6e0 */
if(!s->budget--) { s->failed_pc=0x0c0cb6e0u; return 0; }
r[0]=r[12];
goto P_0c0cb6e2;
P_0c0cb6e2: /* original 6403, guest PC 0x0c0cb6e2 */
if(!s->budget--) { s->failed_pc=0x0c0cb6e2u; return 0; }
r[4]=r[0];
goto P_0c0cb6e4;
P_0c0cb6e4: /* original 664e, guest PC 0x0c0cb6e4 */
if(!s->budget--) { s->failed_pc=0x0c0cb6e4u; return 0; }
r[6]=(uint32_t)(int32_t)(int8_t)r[4];
goto P_0c0cb6e6;
P_0c0cb6e6: /* original 6363, guest PC 0x0c0cb6e6 */
if(!s->budget--) { s->failed_pc=0x0c0cb6e6u; return 0; }
r[3]=r[6];
goto P_0c0cb6e8;
P_0c0cb6e8: /* original 4600, guest PC 0x0c0cb6e8 */
if(!s->budget--) { s->failed_pc=0x0c0cb6e8u; return 0; }
r[17]=(r[17]&~1u)|((r[6]>>31)!=0);
r[6]<<=1;
goto P_0c0cb6ea;
P_0c0cb6ea: /* original 363c, guest PC 0x0c0cb6ea */
if(!s->budget--) { s->failed_pc=0x0c0cb6eau; return 0; }
r[6]+=r[3];
goto P_0c0cb6ec;
P_0c0cb6ec: /* original 4608, guest PC 0x0c0cb6ec */
if(!s->budget--) { s->failed_pc=0x0c0cb6ecu; return 0; }
r[6]<<=2;
goto P_0c0cb6ee;
P_0c0cb6ee: /* original 369c, guest PC 0x0c0cb6ee */
if(!s->budget--) { s->failed_pc=0x0c0cb6eeu; return 0; }
r[6]+=r[9];
goto P_0c0cb6f0;
P_0c0cb6f0: /* original f668, guest PC 0x0c0cb6f0 */
if(!s->budget--) { s->failed_pc=0x0c0cb6f0u; return 0; }
vf3_matrix_load(s,ram,6,r[6]);
goto P_0c0cb6f2;
P_0c0cb6f2: /* original e008, guest PC 0x0c0cb6f2 */
if(!s->budget--) { s->failed_pc=0x0c0cb6f2u; return 0; }
r[0]=0x00000008u;
goto P_0c0cb6f4;
P_0c0cb6f4: /* original f766, guest PC 0x0c0cb6f4 */
if(!s->budget--) { s->failed_pc=0x0c0cb6f4u; return 0; }
vf3_matrix_load(s,ram,7,r[6]+r[0]);
goto P_0c0cb6f6;
P_0c0cb6f6: /* original f36c, guest PC 0x0c0cb6f6 */
if(!s->budget--) { s->failed_pc=0x0c0cb6f6u; return 0; }
vf3_matrix_move(s,3,6);
goto P_0c0cb6f8;
P_0c0cb6f8: /* original f362, guest PC 0x0c0cb6f8 */
if(!s->budget--) { s->failed_pc=0x0c0cb6f8u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[6],r[18],'*');
goto P_0c0cb6fa;
P_0c0cb6fa: /* original f07c, guest PC 0x0c0cb6fa */
if(!s->budget--) { s->failed_pc=0x0c0cb6fau; return 0; }
vf3_matrix_move(s,0,7);
goto P_0c0cb6fc;
P_0c0cb6fc: /* original f37e, guest PC 0x0c0cb6fc */
if(!s->budget--) { s->failed_pc=0x0c0cb6fcu; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[7],fr[3],r[18]);
goto P_0c0cb6fe;
P_0c0cb6fe: /* original f93c, guest PC 0x0c0cb6fe */
if(!s->budget--) { s->failed_pc=0x0c0cb6feu; return 0; }
vf3_matrix_move(s,9,3);
goto P_0c0cb700;
P_0c0cb700: /* original fb95, guest PC 0x0c0cb700 */
if(!s->budget--) { s->failed_pc=0x0c0cb700u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[11])>as_float(fr[9]))!=0);
goto P_0c0cb702;
P_0c0cb702: /* original 8b01, guest PC 0x0c0cb702 */
if(!s->budget--) { s->failed_pc=0x0c0cb702u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0cb708; }
goto P_0c0cb704;
P_0c0cb704: /* original a002, guest PC 0x0c0cb704 */
if(!s->budget--) { s->failed_pc=0x0c0cb704u; return 0; }
fr[5]=0;
goto P_0c0cb70c;
P_0c0cb706: /* original f58d, guest PC 0x0c0cb706 */
if(!s->budget--) { s->failed_pc=0x0c0cb706u; return 0; }
fr[5]=0;
goto P_0c0cb708;
P_0c0cb708: /* original f59c, guest PC 0x0c0cb708 */
if(!s->budget--) { s->failed_pc=0x0c0cb708u; return 0; }
vf3_matrix_move(s,5,9);
goto P_0c0cb70a;
P_0c0cb70a: /* original f57d, guest PC 0x0c0cb70a */
if(!s->budget--) { s->failed_pc=0x0c0cb70au; return 0; }
if(!vf3_fpu_fsrra(fr[5],r[18],&fr[5])) goto unsupported;
goto P_0c0cb70c;
P_0c0cb70c: /* original f45c, guest PC 0x0c0cb70c */
if(!s->budget--) { s->failed_pc=0x0c0cb70cu; return 0; }
vf3_matrix_move(s,4,5);
goto P_0c0cb70e;
P_0c0cb70e: /* original f462, guest PC 0x0c0cb70e */
if(!s->budget--) { s->failed_pc=0x0c0cb70eu; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[6],r[18],'*');
goto P_0c0cb710;
P_0c0cb710: /* original f572, guest PC 0x0c0cb710 */
if(!s->budget--) { s->failed_pc=0x0c0cb710u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[7],r[18],'*');
goto P_0c0cb712;
P_0c0cb712: /* original 614e, guest PC 0x0c0cb712 */
if(!s->budget--) { s->failed_pc=0x0c0cb712u; return 0; }
r[1]=(uint32_t)(int32_t)(int8_t)r[4];
goto P_0c0cb714;
P_0c0cb714: /* original 4100, guest PC 0x0c0cb714 */
if(!s->budget--) { s->failed_pc=0x0c0cb714u; return 0; }
r[17]=(r[17]&~1u)|((r[1]>>31)!=0);
r[1]<<=1;
goto P_0c0cb716;
P_0c0cb716: /* original f915, guest PC 0x0c0cb716 */
if(!s->budget--) { s->failed_pc=0x0c0cb716u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[9])>as_float(fr[1]))!=0);
goto P_0c0cb718;
P_0c0cb718: /* original f34c, guest PC 0x0c0cb718 */
if(!s->budget--) { s->failed_pc=0x0c0cb718u; return 0; }
vf3_matrix_move(s,3,4);
goto P_0c0cb71a;
P_0c0cb71a: /* original f4ac, guest PC 0x0c0cb71a */
if(!s->budget--) { s->failed_pc=0x0c0cb71au; return 0; }
vf3_matrix_move(s,4,10);
goto P_0c0cb71c;
P_0c0cb71c: /* original f432, guest PC 0x0c0cb71c */
if(!s->budget--) { s->failed_pc=0x0c0cb71cu; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'*');
goto P_0c0cb71e;
P_0c0cb71e: /* original f35c, guest PC 0x0c0cb71e */
if(!s->budget--) { s->failed_pc=0x0c0cb71eu; return 0; }
vf3_matrix_move(s,3,5);
goto P_0c0cb720;
P_0c0cb720: /* original f5ac, guest PC 0x0c0cb720 */
if(!s->budget--) { s->failed_pc=0x0c0cb720u; return 0; }
vf3_matrix_move(s,5,10);
goto P_0c0cb722;
P_0c0cb722: /* original f532, guest PC 0x0c0cb722 */
if(!s->budget--) { s->failed_pc=0x0c0cb722u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[3],r[18],'*');
goto P_0c0cb724;
P_0c0cb724: /* original 8d0a, guest PC 0x0c0cb724 */
if(!s->budget--) { s->failed_pc=0x0c0cb724u; return 0; }
cond=r[17]&1u;
r[1]<<=2;
if(cond) { goto P_0c0cb73c; }
goto P_0c0cb728;
P_0c0cb726: /* original 4108, guest PC 0x0c0cb726 */
if(!s->budget--) { s->failed_pc=0x0c0cb726u; return 0; }
r[1]<<=2;
goto P_0c0cb728;
P_0c0cb728: /* original f571, guest PC 0x0c0cb728 */
if(!s->budget--) { s->failed_pc=0x0c0cb728u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[7],r[18],'-');
goto P_0c0cb72a;
P_0c0cb72a: /* original 6413, guest PC 0x0c0cb72a */
if(!s->budget--) { s->failed_pc=0x0c0cb72au; return 0; }
r[4]=r[1];
goto P_0c0cb72c;
P_0c0cb72c: /* original f461, guest PC 0x0c0cb72c */
if(!s->budget--) { s->failed_pc=0x0c0cb72cu; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[6],r[18],'-');
goto P_0c0cb72e;
P_0c0cb72e: /* original 34dc, guest PC 0x0c0cb72e */
if(!s->budget--) { s->failed_pc=0x0c0cb72eu; return 0; }
r[4]+=r[13];
goto P_0c0cb730;
P_0c0cb730: /* original e004, guest PC 0x0c0cb730 */
if(!s->budget--) { s->failed_pc=0x0c0cb730u; return 0; }
r[0]=0x00000004u;
goto P_0c0cb732;
P_0c0cb732: /* original f487, guest PC 0x0c0cb732 */
if(!s->budget--) { s->failed_pc=0x0c0cb732u; return 0; }
vf3_matrix_store(s,ram,8,r[4]+r[0]);
goto P_0c0cb734;
P_0c0cb734: /* original f48a, guest PC 0x0c0cb734 */
if(!s->budget--) { s->failed_pc=0x0c0cb734u; return 0; }
vf3_matrix_store(s,ram,8,r[4]);
goto P_0c0cb736;
P_0c0cb736: /* original 6413, guest PC 0x0c0cb736 */
if(!s->budget--) { s->failed_pc=0x0c0cb736u; return 0; }
r[4]=r[1];
goto P_0c0cb738;
P_0c0cb738: /* original a00d, guest PC 0x0c0cb738 */
if(!s->budget--) { s->failed_pc=0x0c0cb738u; return 0; }
r[4]+=r[7];
goto P_0c0cb756;
P_0c0cb73a: /* original 347c, guest PC 0x0c0cb73a */
if(!s->budget--) { s->failed_pc=0x0c0cb73au; return 0; }
r[4]+=r[7];
goto P_0c0cb73c;
P_0c0cb73c: /* original 6413, guest PC 0x0c0cb73c */
if(!s->budget--) { s->failed_pc=0x0c0cb73cu; return 0; }
r[4]=r[1];
goto P_0c0cb73e;
P_0c0cb73e: /* original e004, guest PC 0x0c0cb73e */
if(!s->budget--) { s->failed_pc=0x0c0cb73eu; return 0; }
r[0]=0x00000004u;
goto P_0c0cb740;
P_0c0cb740: /* original 347c, guest PC 0x0c0cb740 */
if(!s->budget--) { s->failed_pc=0x0c0cb740u; return 0; }
r[4]+=r[7];
goto P_0c0cb742;
P_0c0cb742: /* original f487, guest PC 0x0c0cb742 */
if(!s->budget--) { s->failed_pc=0x0c0cb742u; return 0; }
vf3_matrix_store(s,ram,8,r[4]+r[0]);
goto P_0c0cb744;
P_0c0cb744: /* original f48a, guest PC 0x0c0cb744 */
if(!s->budget--) { s->failed_pc=0x0c0cb744u; return 0; }
vf3_matrix_store(s,ram,8,r[4]);
goto P_0c0cb746;
P_0c0cb746: /* original 6413, guest PC 0x0c0cb746 */
if(!s->budget--) { s->failed_pc=0x0c0cb746u; return 0; }
r[4]=r[1];
goto P_0c0cb748;
P_0c0cb748: /* original f34c, guest PC 0x0c0cb748 */
if(!s->budget--) { s->failed_pc=0x0c0cb748u; return 0; }
vf3_matrix_move(s,3,4);
goto P_0c0cb74a;
P_0c0cb74a: /* original 34dc, guest PC 0x0c0cb74a */
if(!s->budget--) { s->failed_pc=0x0c0cb74au; return 0; }
r[4]+=r[13];
goto P_0c0cb74c;
P_0c0cb74c: /* original f46c, guest PC 0x0c0cb74c */
if(!s->budget--) { s->failed_pc=0x0c0cb74cu; return 0; }
vf3_matrix_move(s,4,6);
goto P_0c0cb74e;
P_0c0cb74e: /* original f431, guest PC 0x0c0cb74e */
if(!s->budget--) { s->failed_pc=0x0c0cb74eu; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'-');
goto P_0c0cb750;
P_0c0cb750: /* original f35c, guest PC 0x0c0cb750 */
if(!s->budget--) { s->failed_pc=0x0c0cb750u; return 0; }
vf3_matrix_move(s,3,5);
goto P_0c0cb752;
P_0c0cb752: /* original f57c, guest PC 0x0c0cb752 */
if(!s->budget--) { s->failed_pc=0x0c0cb752u; return 0; }
vf3_matrix_move(s,5,7);
goto P_0c0cb754;
P_0c0cb754: /* original f531, guest PC 0x0c0cb754 */
if(!s->budget--) { s->failed_pc=0x0c0cb754u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[3],r[18],'-');
goto P_0c0cb756;
P_0c0cb756: /* original 75ff, guest PC 0x0c0cb756 */
if(!s->budget--) { s->failed_pc=0x0c0cb756u; return 0; }
r[5]+=0xffffffffu;
goto P_0c0cb758;
P_0c0cb758: /* original f44a, guest PC 0x0c0cb758 */
if(!s->budget--) { s->failed_pc=0x0c0cb758u; return 0; }
vf3_matrix_store(s,ram,4,r[4]);
goto P_0c0cb75a;
P_0c0cb75a: /* original f457, guest PC 0x0c0cb75a */
if(!s->budget--) { s->failed_pc=0x0c0cb75au; return 0; }
vf3_matrix_store(s,ram,5,r[4]+r[0]);
goto P_0c0cb75c;
P_0c0cb75c: /* original 2558, guest PC 0x0c0cb75c */
if(!s->budget--) { s->failed_pc=0x0c0cb75cu; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[5])==0)!=0);
goto P_0c0cb75e;
P_0c0cb75e: /* original 8bb9, guest PC 0x0c0cb75e */
if(!s->budget--) { s->failed_pc=0x0c0cb75eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0cb6d4; }
goto P_0c0cb760;
P_0c0cb760: /* original 4f26, guest PC 0x0c0cb760 */
if(!s->budget--) { s->failed_pc=0x0c0cb760u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0cb762;
P_0c0cb762: /* original 69f6, guest PC 0x0c0cb762 */
if(!s->budget--) { s->failed_pc=0x0c0cb762u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c0cb764;
P_0c0cb764: /* original 6af6, guest PC 0x0c0cb764 */
if(!s->budget--) { s->failed_pc=0x0c0cb764u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0cb766;
P_0c0cb766: /* original 6bf6, guest PC 0x0c0cb766 */
if(!s->budget--) { s->failed_pc=0x0c0cb766u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0cb768;
P_0c0cb768: /* original 6cf6, guest PC 0x0c0cb768 */
if(!s->budget--) { s->failed_pc=0x0c0cb768u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0cb76a;
P_0c0cb76a: /* original 000b, guest PC 0x0c0cb76a */
if(!s->budget--) { s->failed_pc=0x0c0cb76au; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
s->pc=target; return ram->oob==0;
P_0c0cb76c: /* original 6df6, guest PC 0x0c0cb76c */
if(!s->budget--) { s->failed_pc=0x0c0cb76cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
return vf3_matrix_family(0x0c0cb76eu,s,ram);
P_0c0cb784: /* original 5641, guest PC 0x0c0cb784 */
if(!s->budget--) { s->failed_pc=0x0c0cb784u; return 0; }
r[6]=read(ram,r[4]+4,4);
goto P_0c0cb786;
P_0c0cb786: /* original d543, guest PC 0x0c0cb786 */
if(!s->budget--) { s->failed_pc=0x0c0cb786u; return 0; }
r[5]=read(ram,0x0c0cb894u,4);
goto P_0c0cb788;
P_0c0cb788: /* original 4f12, guest PC 0x0c0cb788 */
if(!s->budget--) { s->failed_pc=0x0c0cb788u; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c0cb78a;
P_0c0cb78a: /* original 0567, guest PC 0x0c0cb78a */
if(!s->budget--) { s->failed_pc=0x0c0cb78au; return 0; }
r[19]=r[5]*r[6];
goto P_0c0cb78c;
P_0c0cb78c: /* original 937b, guest PC 0x0c0cb78c */
if(!s->budget--) { s->failed_pc=0x0c0cb78cu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0cb886u,2);
goto P_0c0cb78e;
P_0c0cb78e: /* original 051a, guest PC 0x0c0cb78e */
if(!s->budget--) { s->failed_pc=0x0c0cb78eu; return 0; }
r[5]=r[19];
goto P_0c0cb790;
P_0c0cb790: /* original 353c, guest PC 0x0c0cb790 */
if(!s->budget--) { s->failed_pc=0x0c0cb790u; return 0; }
r[5]+=r[3];
goto P_0c0cb792;
P_0c0cb792: /* original 1451, guest PC 0x0c0cb792 */
if(!s->budget--) { s->failed_pc=0x0c0cb792u; return 0; }
write(ram,r[4]+4,r[5],4);
goto P_0c0cb794;
P_0c0cb794: /* original 4529, guest PC 0x0c0cb794 */
if(!s->budget--) { s->failed_pc=0x0c0cb794u; return 0; }
r[5]>>=16;
goto P_0c0cb796;
P_0c0cb796: /* original 9277, guest PC 0x0c0cb796 */
if(!s->budget--) { s->failed_pc=0x0c0cb796u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0cb888u,2);
goto P_0c0cb798;
P_0c0cb798: /* original 9677, guest PC 0x0c0cb798 */
if(!s->budget--) { s->failed_pc=0x0c0cb798u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0cb88au,2);
goto P_0c0cb79a;
P_0c0cb79a: /* original 2529, guest PC 0x0c0cb79a */
if(!s->budget--) { s->failed_pc=0x0c0cb79au; return 0; }
r[5]&=r[2];
goto P_0c0cb79c;
P_0c0cb79c: /* original 365c, guest PC 0x0c0cb79c */
if(!s->budget--) { s->failed_pc=0x0c0cb79cu; return 0; }
r[6]+=r[5];
goto P_0c0cb79e;
P_0c0cb79e: /* original 4611, guest PC 0x0c0cb79e */
if(!s->budget--) { s->failed_pc=0x0c0cb79eu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[6]>=0)!=0);
goto P_0c0cb7a0;
P_0c0cb7a0: /* original 8f01, guest PC 0x0c0cb7a0 */
if(!s->budget--) { s->failed_pc=0x0c0cb7a0u; return 0; }
cond=r[17]&1u;
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+3,1);
if(!cond) { goto P_0c0cb7a6; }
goto P_0c0cb7a4;
P_0c0cb7a2: /* original 8443, guest PC 0x0c0cb7a2 */
if(!s->budget--) { s->failed_pc=0x0c0cb7a2u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+3,1);
goto P_0c0cb7a4;
P_0c0cb7a4: /* original 6563, guest PC 0x0c0cb7a4 */
if(!s->budget--) { s->failed_pc=0x0c0cb7a4u; return 0; }
r[5]=r[6];
goto P_0c0cb7a6;
P_0c0cb7a6: /* original 6603, guest PC 0x0c0cb7a6 */
if(!s->budget--) { s->failed_pc=0x0c0cb7a6u; return 0; }
r[6]=r[0];
goto P_0c0cb7a8;
P_0c0cb7a8: /* original e301, guest PC 0x0c0cb7a8 */
if(!s->budget--) { s->failed_pc=0x0c0cb7a8u; return 0; }
r[3]=0x00000001u;
goto P_0c0cb7aa;
P_0c0cb7aa: /* original 7601, guest PC 0x0c0cb7aa */
if(!s->budget--) { s->failed_pc=0x0c0cb7aau; return 0; }
r[6]+=0x00000001u;
goto P_0c0cb7ac;
P_0c0cb7ac: /* original 2638, guest PC 0x0c0cb7ac */
if(!s->budget--) { s->failed_pc=0x0c0cb7acu; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[3])==0)!=0);
goto P_0c0cb7ae;
P_0c0cb7ae: /* original 6063, guest PC 0x0c0cb7ae */
if(!s->budget--) { s->failed_pc=0x0c0cb7aeu; return 0; }
r[0]=r[6];
goto P_0c0cb7b0;
P_0c0cb7b0: /* original 8d01, guest PC 0x0c0cb7b0 */
if(!s->budget--) { s->failed_pc=0x0c0cb7b0u; return 0; }
cond=r[17]&1u;
write(ram,r[4]+3,r[0],1);
if(cond) { goto P_0c0cb7b6; }
goto P_0c0cb7b4;
P_0c0cb7b2: /* original 8043, guest PC 0x0c0cb7b2 */
if(!s->budget--) { s->failed_pc=0x0c0cb7b2u; return 0; }
write(ram,r[4]+3,r[0],1);
goto P_0c0cb7b4;
P_0c0cb7b4: /* original 655b, guest PC 0x0c0cb7b4 */
if(!s->budget--) { s->failed_pc=0x0c0cb7b4u; return 0; }
r[5]=0u-r[5];
goto P_0c0cb7b6;
P_0c0cb7b6: /* original 6053, guest PC 0x0c0cb7b6 */
if(!s->budget--) { s->failed_pc=0x0c0cb7b6u; return 0; }
r[0]=r[5];
goto P_0c0cb7b8;
P_0c0cb7b8: /* original 000b, guest PC 0x0c0cb7b8 */
if(!s->budget--) { s->failed_pc=0x0c0cb7b8u; return 0; }
target=r[16];
r[19]=read(ram,r[15],4); r[15]+=4;
s->pc=target; return ram->oob==0;
P_0c0cb7ba: /* original 4f16, guest PC 0x0c0cb7ba */
if(!s->budget--) { s->failed_pc=0x0c0cb7bau; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
return vf3_matrix_family(0x0c0cb7bcu,s,ram);
P_0c0cb8ec: /* original 2fe6, guest PC 0x0c0cb8ec */
if(!s->budget--) { s->failed_pc=0x0c0cb8ecu; return 0; }
r[15]-=4; write(ram,r[15],r[14],4);
goto P_0c0cb8ee;
P_0c0cb8ee: /* original 6e53, guest PC 0x0c0cb8ee */
if(!s->budget--) { s->failed_pc=0x0c0cb8eeu; return 0; }
r[14]=r[5];
goto P_0c0cb8f0;
P_0c0cb8f0: /* original 2fd6, guest PC 0x0c0cb8f0 */
if(!s->budget--) { s->failed_pc=0x0c0cb8f0u; return 0; }
r[15]-=4; write(ram,r[15],r[13],4);
goto P_0c0cb8f2;
P_0c0cb8f2: /* original 2fc6, guest PC 0x0c0cb8f2 */
if(!s->budget--) { s->failed_pc=0x0c0cb8f2u; return 0; }
r[15]-=4; write(ram,r[15],r[12],4);
goto P_0c0cb8f4;
P_0c0cb8f4: /* original 2fb6, guest PC 0x0c0cb8f4 */
if(!s->budget--) { s->failed_pc=0x0c0cb8f4u; return 0; }
r[15]-=4; write(ram,r[15],r[11],4);
goto P_0c0cb8f6;
P_0c0cb8f6: /* original 2fa6, guest PC 0x0c0cb8f6 */
if(!s->budget--) { s->failed_pc=0x0c0cb8f6u; return 0; }
r[15]-=4; write(ram,r[15],r[10],4);
goto P_0c0cb8f8;
P_0c0cb8f8: /* original 2f96, guest PC 0x0c0cb8f8 */
if(!s->budget--) { s->failed_pc=0x0c0cb8f8u; return 0; }
r[15]-=4; write(ram,r[15],r[9],4);
goto P_0c0cb8fa;
P_0c0cb8fa: /* original 2f86, guest PC 0x0c0cb8fa */
if(!s->budget--) { s->failed_pc=0x0c0cb8fau; return 0; }
r[15]-=4; write(ram,r[15],r[8],4);
goto P_0c0cb8fc;
P_0c0cb8fc: /* original 4f22, guest PC 0x0c0cb8fc */
if(!s->budget--) { s->failed_pc=0x0c0cb8fcu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0cb8fe;
P_0c0cb8fe: /* original 7ff0, guest PC 0x0c0cb8fe */
if(!s->budget--) { s->failed_pc=0x0c0cb8feu; return 0; }
r[15]+=0xfffffff0u;
goto P_0c0cb900;
P_0c0cb900: /* original 1f62, guest PC 0x0c0cb900 */
if(!s->budget--) { s->failed_pc=0x0c0cb900u; return 0; }
write(ram,r[15]+8,r[6],4);
goto P_0c0cb902;
P_0c0cb902: /* original 1f71, guest PC 0x0c0cb902 */
if(!s->budget--) { s->failed_pc=0x0c0cb902u; return 0; }
write(ram,r[15]+4,r[7],4);
goto P_0c0cb904;
P_0c0cb904: /* original ff4a, guest PC 0x0c0cb904 */
if(!s->budget--) { s->failed_pc=0x0c0cb904u; return 0; }
vf3_matrix_store(s,ram,4,r[15]);
goto P_0c0cb906;
P_0c0cb906: /* original 53e4, guest PC 0x0c0cb906 */
if(!s->budget--) { s->failed_pc=0x0c0cb906u; return 0; }
r[3]=read(ram,r[14]+16,4);
goto P_0c0cb908;
P_0c0cb908: /* original 4315, guest PC 0x0c0cb908 */
if(!s->budget--) { s->failed_pc=0x0c0cb908u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>0)!=0);
goto P_0c0cb90a;
P_0c0cb90a: /* original 8f49, guest PC 0x0c0cb90a */
if(!s->budget--) { s->failed_pc=0x0c0cb90au; return 0; }
cond=r[17]&1u;
r[9]=r[4];
if(!cond) { goto P_0c0cb9a0; }
goto P_0c0cb90e;
P_0c0cb90c: /* original 6943, guest PC 0x0c0cb90c */
if(!s->budget--) { s->failed_pc=0x0c0cb90cu; return 0; }
r[9]=r[4];
goto P_0c0cb90e;
P_0c0cb90e: /* original 63e2, guest PC 0x0c0cb90e */
if(!s->budget--) { s->failed_pc=0x0c0cb90eu; return 0; }
tmp=read(ram,r[14],4);
r[3]=tmp;
goto P_0c0cb910;
P_0c0cb910: /* original 2338, guest PC 0x0c0cb910 */
if(!s->budget--) { s->failed_pc=0x0c0cb910u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c0cb912;
P_0c0cb912: /* original 8f06, guest PC 0x0c0cb912 */
if(!s->budget--) { s->failed_pc=0x0c0cb912u; return 0; }
cond=r[17]&1u;
r[4]=read(ram,r[9]+52,4);
if(!cond) { goto P_0c0cb922; }
goto P_0c0cb916;
P_0c0cb914: /* original 549d, guest PC 0x0c0cb914 */
if(!s->budget--) { s->failed_pc=0x0c0cb914u; return 0; }
r[4]=read(ram,r[9]+52,4);
goto P_0c0cb916;
P_0c0cb916: /* original e300, guest PC 0x0c0cb916 */
if(!s->budget--) { s->failed_pc=0x0c0cb916u; return 0; }
r[3]=0x00000000u;
goto P_0c0cb918;
P_0c0cb918: /* original 6543, guest PC 0x0c0cb918 */
if(!s->budget--) { s->failed_pc=0x0c0cb918u; return 0; }
r[5]=r[4];
goto P_0c0cb91a;
P_0c0cb91a: /* original 3357, guest PC 0x0c0cb91a */
if(!s->budget--) { s->failed_pc=0x0c0cb91au; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>(int32_t)r[5])!=0);
goto P_0c0cb91c;
P_0c0cb91c: /* original 353e, guest PC 0x0c0cb91c */
if(!s->budget--) { s->failed_pc=0x0c0cb91cu; return 0; }
wide=(uint64_t)r[5]+r[3]+(r[17]&1u); r[5]=(uint32_t)wide;
r[17]=(r[17]&~1u)|((wide>>32)!=0);
goto P_0c0cb91e;
P_0c0cb91e: /* original 4521, guest PC 0x0c0cb91e */
if(!s->budget--) { s->failed_pc=0x0c0cb91eu; return 0; }
r[17]=(r[17]&~1u)|((r[5]&1)!=0);
r[5]=(uint32_t)((int32_t)r[5]>>1);
goto P_0c0cb920;
P_0c0cb920: /* original 3458, guest PC 0x0c0cb920 */
if(!s->budget--) { s->failed_pc=0x0c0cb920u; return 0; }
r[4]-=r[5];
goto P_0c0cb922;
P_0c0cb922: /* original 9548, guest PC 0x0c0cb922 */
if(!s->budget--) { s->failed_pc=0x0c0cb922u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0cb9b6u,2);
goto P_0c0cb924;
P_0c0cb924: /* original 4408, guest PC 0x0c0cb924 */
if(!s->budget--) { s->failed_pc=0x0c0cb924u; return 0; }
r[4]<<=2;
goto P_0c0cb926;
P_0c0cb926: /* original 4408, guest PC 0x0c0cb926 */
if(!s->budget--) { s->failed_pc=0x0c0cb926u; return 0; }
r[4]<<=2;
goto P_0c0cb928;
P_0c0cb928: /* original 359c, guest PC 0x0c0cb928 */
if(!s->budget--) { s->failed_pc=0x0c0cb928u; return 0; }
r[5]+=r[9];
goto P_0c0cb92a;
P_0c0cb92a: /* original 4400, guest PC 0x0c0cb92a */
if(!s->budget--) { s->failed_pc=0x0c0cb92au; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c0cb92c;
P_0c0cb92c: /* original 354c, guest PC 0x0c0cb92c */
if(!s->budget--) { s->failed_pc=0x0c0cb92cu; return 0; }
r[5]+=r[4];
goto P_0c0cb92e;
P_0c0cb92e: /* original eb02, guest PC 0x0c0cb92e */
if(!s->budget--) { s->failed_pc=0x0c0cb92eu; return 0; }
r[11]=0x00000002u;
goto P_0c0cb930;
P_0c0cb930: /* original 1f53, guest PC 0x0c0cb930 */
if(!s->budget--) { s->failed_pc=0x0c0cb930u; return 0; }
write(ram,r[15]+12,r[5],4);
goto P_0c0cb932;
P_0c0cb932: /* original 5d93, guest PC 0x0c0cb932 */
if(!s->budget--) { s->failed_pc=0x0c0cb932u; return 0; }
r[13]=read(ram,r[9]+12,4);
goto P_0c0cb934;
P_0c0cb934: /* original ec04, guest PC 0x0c0cb934 */
if(!s->budget--) { s->failed_pc=0x0c0cb934u; return 0; }
r[12]=0x00000004u;
goto P_0c0cb936;
P_0c0cb936: /* original ea01, guest PC 0x0c0cb936 */
if(!s->budget--) { s->failed_pc=0x0c0cb936u; return 0; }
r[10]=0x00000001u;
goto P_0c0cb938;
P_0c0cb938: /* original 52f3, guest PC 0x0c0cb938 */
if(!s->budget--) { s->failed_pc=0x0c0cb938u; return 0; }
r[2]=read(ram,r[15]+12,4);
goto P_0c0cb93a;
P_0c0cb93a: /* original 3d22, guest PC 0x0c0cb93a */
if(!s->budget--) { s->failed_pc=0x0c0cb93au; return 0; }
r[17]=(r[17]&~1u)|((r[13]>=r[2])!=0);
goto P_0c0cb93c;
P_0c0cb93c: /* original 892f, guest PC 0x0c0cb93c */
if(!s->budget--) { s->failed_pc=0x0c0cb93cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0cb99e; }
goto P_0c0cb93e;
P_0c0cb93e: /* original 85dd, guest PC 0x0c0cb93e */
if(!s->budget--) { s->failed_pc=0x0c0cb93eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[13]+26,2);
goto P_0c0cb940;
P_0c0cb940: /* original 6303, guest PC 0x0c0cb940 */
if(!s->budget--) { s->failed_pc=0x0c0cb940u; return 0; }
r[3]=r[0];
goto P_0c0cb942;
P_0c0cb942: /* original 23a8, guest PC 0x0c0cb942 */
if(!s->budget--) { s->failed_pc=0x0c0cb942u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[10])==0)!=0);
goto P_0c0cb944;
P_0c0cb944: /* original 8f29, guest PC 0x0c0cb944 */
if(!s->budget--) { s->failed_pc=0x0c0cb944u; return 0; }
cond=r[17]&1u;
r[4]=r[0];
if(!cond) { goto P_0c0cb99a; }
goto P_0c0cb948;
P_0c0cb946: /* original 6403, guest PC 0x0c0cb946 */
if(!s->budget--) { s->failed_pc=0x0c0cb946u; return 0; }
r[4]=r[0];
goto P_0c0cb948;
P_0c0cb948: /* original 52e2, guest PC 0x0c0cb948 */
if(!s->budget--) { s->failed_pc=0x0c0cb948u; return 0; }
r[2]=read(ram,r[14]+8,4);
goto P_0c0cb94a;
P_0c0cb94a: /* original 24ab, guest PC 0x0c0cb94a */
if(!s->budget--) { s->failed_pc=0x0c0cb94au; return 0; }
r[4]|=r[10];
goto P_0c0cb94c;
P_0c0cb94c: /* original d31e, guest PC 0x0c0cb94c */
if(!s->budget--) { s->failed_pc=0x0c0cb94cu; return 0; }
r[3]=read(ram,0x0c0cb9c8u,4);
goto P_0c0cb94e;
P_0c0cb94e: /* original 22b8, guest PC 0x0c0cb94e */
if(!s->budget--) { s->failed_pc=0x0c0cb94eu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[11])==0)!=0);
goto P_0c0cb950;
P_0c0cb950: /* original 8d01, guest PC 0x0c0cb950 */
if(!s->budget--) { s->failed_pc=0x0c0cb950u; return 0; }
cond=r[17]&1u;
r[4]&=r[3];
if(cond) { goto P_0c0cb956; }
goto P_0c0cb954;
P_0c0cb952: /* original 2439, guest PC 0x0c0cb952 */
if(!s->budget--) { s->failed_pc=0x0c0cb952u; return 0; }
r[4]&=r[3];
goto P_0c0cb954;
P_0c0cb954: /* original 24bb, guest PC 0x0c0cb954 */
if(!s->budget--) { s->failed_pc=0x0c0cb954u; return 0; }
r[4]|=r[11];
goto P_0c0cb956;
P_0c0cb956: /* original 52e2, guest PC 0x0c0cb956 */
if(!s->budget--) { s->failed_pc=0x0c0cb956u; return 0; }
r[2]=read(ram,r[14]+8,4);
goto P_0c0cb958;
P_0c0cb958: /* original d31c, guest PC 0x0c0cb958 */
if(!s->budget--) { s->failed_pc=0x0c0cb958u; return 0; }
r[3]=read(ram,0x0c0cb9ccu,4);
goto P_0c0cb95a;
P_0c0cb95a: /* original 22c8, guest PC 0x0c0cb95a */
if(!s->budget--) { s->failed_pc=0x0c0cb95au; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[12])==0)!=0);
goto P_0c0cb95c;
P_0c0cb95c: /* original 8d01, guest PC 0x0c0cb95c */
if(!s->budget--) { s->failed_pc=0x0c0cb95cu; return 0; }
cond=r[17]&1u;
r[4]&=r[3];
if(cond) { goto P_0c0cb962; }
goto P_0c0cb960;
P_0c0cb95e: /* original 2439, guest PC 0x0c0cb95e */
if(!s->budget--) { s->failed_pc=0x0c0cb95eu; return 0; }
r[4]&=r[3];
goto P_0c0cb960;
P_0c0cb960: /* original 24cb, guest PC 0x0c0cb960 */
if(!s->budget--) { s->failed_pc=0x0c0cb960u; return 0; }
r[4]|=r[12];
goto P_0c0cb962;
P_0c0cb962: /* original 6043, guest PC 0x0c0cb962 */
if(!s->budget--) { s->failed_pc=0x0c0cb962u; return 0; }
r[0]=r[4];
goto P_0c0cb964;
P_0c0cb964: /* original 81dd, guest PC 0x0c0cb964 */
if(!s->budget--) { s->failed_pc=0x0c0cb964u; return 0; }
write(ram,r[13]+26,r[0],2);
goto P_0c0cb966;
P_0c0cb966: /* original bf0d, guest PC 0x0c0cb966 */
if(!s->budget--) { s->failed_pc=0x0c0cb966u; return 0; }
target=0x0c0cb784u; r[16]=0x0c0cb96au;
r[4]=r[9];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0cb96au) { target=s->pc; goto dispatch; }
goto P_0c0cb96a;
P_0c0cb968: /* original 6493, guest PC 0x0c0cb968 */
if(!s->budget--) { s->failed_pc=0x0c0cb968u; return 0; }
r[4]=r[9];
goto P_0c0cb96a;
P_0c0cb96a: /* original d219, guest PC 0x0c0cb96a */
if(!s->budget--) { s->failed_pc=0x0c0cb96au; return 0; }
r[2]=read(ram,0x0c0cb9d0u,4);
goto P_0c0cb96c;
P_0c0cb96c: /* original 6403, guest PC 0x0c0cb96c */
if(!s->budget--) { s->failed_pc=0x0c0cb96cu; return 0; }
r[4]=r[0];
goto P_0c0cb96e;
P_0c0cb96e: /* original 51e5, guest PC 0x0c0cb96e */
if(!s->budget--) { s->failed_pc=0x0c0cb96eu; return 0; }
r[1]=read(ram,r[14]+20,4);
goto P_0c0cb970;
P_0c0cb970: /* original 420b, guest PC 0x0c0cb970 */
if(!s->budget--) { s->failed_pc=0x0c0cb970u; return 0; }
target=r[2];
r[16]=0x0c0cb974u;
r[0]=r[12];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0cb974u) { target=s->pc; goto dispatch; }
goto P_0c0cb974;
P_0c0cb972: /* original 60c3, guest PC 0x0c0cb972 */
if(!s->budget--) { s->failed_pc=0x0c0cb972u; return 0; }
r[0]=r[12];
goto P_0c0cb974;
P_0c0cb974: /* original 6803, guest PC 0x0c0cb974 */
if(!s->budget--) { s->failed_pc=0x0c0cb974u; return 0; }
r[8]=r[0];
goto P_0c0cb976;
P_0c0cb976: /* original d017, guest PC 0x0c0cb976 */
if(!s->budget--) { s->failed_pc=0x0c0cb976u; return 0; }
r[0]=read(ram,0x0c0cb9d4u,4);
goto P_0c0cb978;
P_0c0cb978: /* original 4808, guest PC 0x0c0cb978 */
if(!s->budget--) { s->failed_pc=0x0c0cb978u; return 0; }
r[8]<<=2;
goto P_0c0cb97a;
P_0c0cb97a: /* original 65e3, guest PC 0x0c0cb97a */
if(!s->budget--) { s->failed_pc=0x0c0cb97au; return 0; }
r[5]=r[14];
goto P_0c0cb97c;
P_0c0cb97c: /* original 088e, guest PC 0x0c0cb97c */
if(!s->budget--) { s->failed_pc=0x0c0cb97cu; return 0; }
r[8]=read(ram,r[8]+r[0],4);
goto P_0c0cb97e;
P_0c0cb97e: /* original e004, guest PC 0x0c0cb97e */
if(!s->budget--) { s->failed_pc=0x0c0cb97eu; return 0; }
r[0]=0x00000004u;
goto P_0c0cb980;
P_0c0cb980: /* original 2f46, guest PC 0x0c0cb980 */
if(!s->budget--) { s->failed_pc=0x0c0cb980u; return 0; }
r[15]-=4; write(ram,r[15],r[4],4);
goto P_0c0cb982;
P_0c0cb982: /* original 56f3, guest PC 0x0c0cb982 */
if(!s->budget--) { s->failed_pc=0x0c0cb982u; return 0; }
r[6]=read(ram,r[15]+12,4);
goto P_0c0cb984;
P_0c0cb984: /* original 57f2, guest PC 0x0c0cb984 */
if(!s->budget--) { s->failed_pc=0x0c0cb984u; return 0; }
r[7]=read(ram,r[15]+8,4);
goto P_0c0cb986;
P_0c0cb986: /* original f4f6, guest PC 0x0c0cb986 */
if(!s->budget--) { s->failed_pc=0x0c0cb986u; return 0; }
vf3_matrix_load(s,ram,4,r[15]+r[0]);
goto P_0c0cb988;
P_0c0cb988: /* original 480b, guest PC 0x0c0cb988 */
if(!s->budget--) { s->failed_pc=0x0c0cb988u; return 0; }
target=r[8];
r[16]=0x0c0cb98cu;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0cb98cu) { target=s->pc; goto dispatch; }
goto P_0c0cb98c;
P_0c0cb98a: /* original 64d3, guest PC 0x0c0cb98a */
if(!s->budget--) { s->failed_pc=0x0c0cb98au; return 0; }
r[4]=r[13];
goto P_0c0cb98c;
P_0c0cb98c: /* original 53e4, guest PC 0x0c0cb98c */
if(!s->budget--) { s->failed_pc=0x0c0cb98cu; return 0; }
r[3]=read(ram,r[14]+16,4);
goto P_0c0cb98e;
P_0c0cb98e: /* original 73ff, guest PC 0x0c0cb98e */
if(!s->budget--) { s->failed_pc=0x0c0cb98eu; return 0; }
r[3]+=0xffffffffu;
goto P_0c0cb990;
P_0c0cb990: /* original 6233, guest PC 0x0c0cb990 */
if(!s->budget--) { s->failed_pc=0x0c0cb990u; return 0; }
r[2]=r[3];
goto P_0c0cb992;
P_0c0cb992: /* original 4215, guest PC 0x0c0cb992 */
if(!s->budget--) { s->failed_pc=0x0c0cb992u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[2]>0)!=0);
goto P_0c0cb994;
P_0c0cb994: /* original 1e34, guest PC 0x0c0cb994 */
if(!s->budget--) { s->failed_pc=0x0c0cb994u; return 0; }
write(ram,r[14]+16,r[3],4);
goto P_0c0cb996;
P_0c0cb996: /* original 8f02, guest PC 0x0c0cb996 */
if(!s->budget--) { s->failed_pc=0x0c0cb996u; return 0; }
cond=r[17]&1u;
r[15]+=0x00000004u;
if(!cond) { goto P_0c0cb99e; }
goto P_0c0cb99a;
P_0c0cb998: /* original 7f04, guest PC 0x0c0cb998 */
if(!s->budget--) { s->failed_pc=0x0c0cb998u; return 0; }
r[15]+=0x00000004u;
goto P_0c0cb99a;
P_0c0cb99a: /* original afcd, guest PC 0x0c0cb99a */
if(!s->budget--) { s->failed_pc=0x0c0cb99au; return 0; }
r[13]+=0x00000020u;
goto P_0c0cb938;
P_0c0cb99c: /* original 7d20, guest PC 0x0c0cb99c */
if(!s->budget--) { s->failed_pc=0x0c0cb99cu; return 0; }
r[13]+=0x00000020u;
goto P_0c0cb99e;
P_0c0cb99e: /* original 19d3, guest PC 0x0c0cb99e */
if(!s->budget--) { s->failed_pc=0x0c0cb99eu; return 0; }
write(ram,r[9]+12,r[13],4);
goto P_0c0cb9a0;
P_0c0cb9a0: /* original 7f10, guest PC 0x0c0cb9a0 */
if(!s->budget--) { s->failed_pc=0x0c0cb9a0u; return 0; }
r[15]+=0x00000010u;
goto P_0c0cb9a2;
P_0c0cb9a2: /* original 4f26, guest PC 0x0c0cb9a2 */
if(!s->budget--) { s->failed_pc=0x0c0cb9a2u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0cb9a4;
P_0c0cb9a4: /* original 68f6, guest PC 0x0c0cb9a4 */
if(!s->budget--) { s->failed_pc=0x0c0cb9a4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c0cb9a6;
P_0c0cb9a6: /* original 69f6, guest PC 0x0c0cb9a6 */
if(!s->budget--) { s->failed_pc=0x0c0cb9a6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c0cb9a8;
P_0c0cb9a8: /* original 6af6, guest PC 0x0c0cb9a8 */
if(!s->budget--) { s->failed_pc=0x0c0cb9a8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0cb9aa;
P_0c0cb9aa: /* original 6bf6, guest PC 0x0c0cb9aa */
if(!s->budget--) { s->failed_pc=0x0c0cb9aau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0cb9ac;
P_0c0cb9ac: /* original 6cf6, guest PC 0x0c0cb9ac */
if(!s->budget--) { s->failed_pc=0x0c0cb9acu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0cb9ae;
P_0c0cb9ae: /* original 6df6, guest PC 0x0c0cb9ae */
if(!s->budget--) { s->failed_pc=0x0c0cb9aeu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0cb9b0;
P_0c0cb9b0: /* original 000b, guest PC 0x0c0cb9b0 */
if(!s->budget--) { s->failed_pc=0x0c0cb9b0u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0cb9b2: /* original 6ef6, guest PC 0x0c0cb9b2 */
if(!s->budget--) { s->failed_pc=0x0c0cb9b2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0cb9b4u,s,ram);
P_0c0cb9d8: /* original 2fe6, guest PC 0x0c0cb9d8 */
if(!s->budget--) { s->failed_pc=0x0c0cb9d8u; return 0; }
r[15]-=4; write(ram,r[15],r[14],4);
goto P_0c0cb9da;
P_0c0cb9da: /* original e074, guest PC 0x0c0cb9da */
if(!s->budget--) { s->failed_pc=0x0c0cb9dau; return 0; }
r[0]=0x00000074u;
goto P_0c0cb9dc;
P_0c0cb9dc: /* original 2fd6, guest PC 0x0c0cb9dc */
if(!s->budget--) { s->failed_pc=0x0c0cb9dcu; return 0; }
r[15]-=4; write(ram,r[15],r[13],4);
goto P_0c0cb9de;
P_0c0cb9de: /* original 6d53, guest PC 0x0c0cb9de */
if(!s->budget--) { s->failed_pc=0x0c0cb9deu; return 0; }
r[13]=r[5];
goto P_0c0cb9e0;
P_0c0cb9e0: /* original 2fc6, guest PC 0x0c0cb9e0 */
if(!s->budget--) { s->failed_pc=0x0c0cb9e0u; return 0; }
r[15]-=4; write(ram,r[15],r[12],4);
goto P_0c0cb9e2;
P_0c0cb9e2: /* original 6c63, guest PC 0x0c0cb9e2 */
if(!s->budget--) { s->failed_pc=0x0c0cb9e2u; return 0; }
r[12]=r[6];
goto P_0c0cb9e4;
P_0c0cb9e4: /* original 2fb6, guest PC 0x0c0cb9e4 */
if(!s->budget--) { s->failed_pc=0x0c0cb9e4u; return 0; }
r[15]-=4; write(ram,r[15],r[11],4);
goto P_0c0cb9e6;
P_0c0cb9e6: /* original 6b43, guest PC 0x0c0cb9e6 */
if(!s->budget--) { s->failed_pc=0x0c0cb9e6u; return 0; }
r[11]=r[4];
goto P_0c0cb9e8;
P_0c0cb9e8: /* original 2fa6, guest PC 0x0c0cb9e8 */
if(!s->budget--) { s->failed_pc=0x0c0cb9e8u; return 0; }
r[15]-=4; write(ram,r[15],r[10],4);
goto P_0c0cb9ea;
P_0c0cb9ea: /* original 2f96, guest PC 0x0c0cb9ea */
if(!s->budget--) { s->failed_pc=0x0c0cb9eau; return 0; }
r[15]-=4; write(ram,r[15],r[9],4);
goto P_0c0cb9ec;
P_0c0cb9ec: /* original 2f86, guest PC 0x0c0cb9ec */
if(!s->budget--) { s->failed_pc=0x0c0cb9ecu; return 0; }
r[15]-=4; write(ram,r[15],r[8],4);
goto P_0c0cb9ee;
P_0c0cb9ee: /* original fffb, guest PC 0x0c0cb9ee */
if(!s->budget--) { s->failed_pc=0x0c0cb9eeu; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c0cb9f0;
P_0c0cb9f0: /* original 4f22, guest PC 0x0c0cb9f0 */
if(!s->budget--) { s->failed_pc=0x0c0cb9f0u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0cb9f2;
P_0c0cb9f2: /* original 7fb4, guest PC 0x0c0cb9f2 */
if(!s->budget--) { s->failed_pc=0x0c0cb9f2u; return 0; }
r[15]+=0xffffffb4u;
goto P_0c0cb9f4;
P_0c0cb9f4: /* original 1f71, guest PC 0x0c0cb9f4 */
if(!s->budget--) { s->failed_pc=0x0c0cb9f4u; return 0; }
write(ram,r[15]+4,r[7],4);
goto P_0c0cb9f6;
P_0c0cb9f6: /* original 08fe, guest PC 0x0c0cb9f6 */
if(!s->budget--) { s->failed_pc=0x0c0cb9f6u; return 0; }
r[8]=read(ram,r[15]+r[0],4);
goto P_0c0cb9f8;
P_0c0cb9f8: /* original 84b1, guest PC 0x0c0cb9f8 */
if(!s->budget--) { s->failed_pc=0x0c0cb9f8u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[11]+1,1);
goto P_0c0cb9fa;
P_0c0cb9fa: /* original 600c, guest PC 0x0c0cb9fa */
if(!s->budget--) { s->failed_pc=0x0c0cb9fau; return 0; }
r[0]=r[0]&255u;
goto P_0c0cb9fc;
P_0c0cb9fc: /* original 4015, guest PC 0x0c0cb9fc */
if(!s->budget--) { s->failed_pc=0x0c0cb9fcu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[0]>0)!=0);
goto P_0c0cb9fe;
P_0c0cb9fe: /* original 8f04, guest PC 0x0c0cb9fe */
if(!s->budget--) { s->failed_pc=0x0c0cb9feu; return 0; }
cond=r[17]&1u;
vf3_matrix_move(s,15,4);
if(!cond) { goto P_0c0cba0a; }
goto P_0c0cba02;
P_0c0cba00: /* original ff4c, guest PC 0x0c0cba00 */
if(!s->budget--) { s->failed_pc=0x0c0cba00u; return 0; }
vf3_matrix_move(s,15,4);
goto P_0c0cba02;
P_0c0cba02: /* original 84b1, guest PC 0x0c0cba02 */
if(!s->budget--) { s->failed_pc=0x0c0cba02u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[11]+1,1);
goto P_0c0cba04;
P_0c0cba04: /* original 70ff, guest PC 0x0c0cba04 */
if(!s->budget--) { s->failed_pc=0x0c0cba04u; return 0; }
r[0]+=0xffffffffu;
goto P_0c0cba06;
P_0c0cba06: /* original a093, guest PC 0x0c0cba06 */
if(!s->budget--) { s->failed_pc=0x0c0cba06u; return 0; }
write(ram,r[11]+1,r[0],1);
goto P_0c0cbb30;
P_0c0cba08: /* original 80b1, guest PC 0x0c0cba08 */
if(!s->budget--) { s->failed_pc=0x0c0cba08u; return 0; }
write(ram,r[11]+1,r[0],1);
goto P_0c0cba0a;
P_0c0cba0a: /* original d330, guest PC 0x0c0cba0a */
if(!s->budget--) { s->failed_pc=0x0c0cba0au; return 0; }
r[3]=read(ram,0x0c0cbaccu,4);
goto P_0c0cba0c;
P_0c0cba0c: /* original ea0f, guest PC 0x0c0cba0c */
if(!s->budget--) { s->failed_pc=0x0c0cba0cu; return 0; }
r[10]=0x0000000fu;
goto P_0c0cba0e;
P_0c0cba0e: /* original 6030, guest PC 0x0c0cba0e */
if(!s->budget--) { s->failed_pc=0x0c0cba0eu; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[3],1);
r[0]=tmp;
goto P_0c0cba10;
P_0c0cba10: /* original 600c, guest PC 0x0c0cba10 */
if(!s->budget--) { s->failed_pc=0x0c0cba10u; return 0; }
r[0]=r[0]&255u;
goto P_0c0cba12;
P_0c0cba12: /* original 2a09, guest PC 0x0c0cba12 */
if(!s->budget--) { s->failed_pc=0x0c0cba12u; return 0; }
r[10]&=r[0];
goto P_0c0cba14;
P_0c0cba14: /* original 84d1, guest PC 0x0c0cba14 */
if(!s->budget--) { s->failed_pc=0x0c0cba14u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+1,1);
goto P_0c0cba16;
P_0c0cba16: /* original 1f09, guest PC 0x0c0cba16 */
if(!s->budget--) { s->failed_pc=0x0c0cba16u; return 0; }
write(ram,r[15]+36,r[0],4);
goto P_0c0cba18;
P_0c0cba18: /* original e008, guest PC 0x0c0cba18 */
if(!s->budget--) { s->failed_pc=0x0c0cba18u; return 0; }
r[0]=0x00000008u;
goto P_0c0cba1a;
P_0c0cba1a: /* original 69d0, guest PC 0x0c0cba1a */
if(!s->budget--) { s->failed_pc=0x0c0cba1au; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[13],1);
r[9]=tmp;
goto P_0c0cba1c;
P_0c0cba1c: /* original f5c6, guest PC 0x0c0cba1c */
if(!s->budget--) { s->failed_pc=0x0c0cba1cu; return 0; }
vf3_matrix_load(s,ram,5,r[12]+r[0]);
goto P_0c0cba1e;
P_0c0cba1e: /* original 60a3, guest PC 0x0c0cba1e */
if(!s->budget--) { s->failed_pc=0x0c0cba1eu; return 0; }
r[0]=r[10];
goto P_0c0cba20;
P_0c0cba20: /* original 924f, guest PC 0x0c0cba20 */
if(!s->budget--) { s->failed_pc=0x0c0cba20u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0cbac2u,2);
goto P_0c0cba22;
P_0c0cba22: /* original 6e93, guest PC 0x0c0cba22 */
if(!s->budget--) { s->failed_pc=0x0c0cba22u; return 0; }
r[14]=r[9];
goto P_0c0cba24;
P_0c0cba24: /* original 880d, guest PC 0x0c0cba24 */
if(!s->budget--) { s->failed_pc=0x0c0cba24u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000du)!=0);
goto P_0c0cba26;
P_0c0cba26: /* original 2e29, guest PC 0x0c0cba26 */
if(!s->budget--) { s->failed_pc=0x0c0cba26u; return 0; }
r[14]&=r[2];
goto P_0c0cba28;
P_0c0cba28: /* original 8f0c, guest PC 0x0c0cba28 */
if(!s->budget--) { s->failed_pc=0x0c0cba28u; return 0; }
cond=r[17]&1u;
vf3_matrix_load(s,ram,4,r[12]);
if(!cond) { goto P_0c0cba44; }
goto P_0c0cba2c;
P_0c0cba2a: /* original f4c8, guest PC 0x0c0cba2a */
if(!s->budget--) { s->failed_pc=0x0c0cba2au; return 0; }
vf3_matrix_load(s,ram,4,r[12]);
goto P_0c0cba2c;
P_0c0cba2c: /* original d128, guest PC 0x0c0cba2c */
if(!s->budget--) { s->failed_pc=0x0c0cba2cu; return 0; }
r[1]=read(ram,0x0c0cbad0u,4);
goto P_0c0cba2e;
P_0c0cba2e: /* original 65f3, guest PC 0x0c0cba2e */
if(!s->budget--) { s->failed_pc=0x0c0cba2eu; return 0; }
r[5]=r[15];
goto P_0c0cba30;
P_0c0cba30: /* original 750c, guest PC 0x0c0cba30 */
if(!s->budget--) { s->failed_pc=0x0c0cba30u; return 0; }
r[5]+=0x0000000cu;
goto P_0c0cba32;
P_0c0cba32: /* original 410b, guest PC 0x0c0cba32 */
if(!s->budget--) { s->failed_pc=0x0c0cba32u; return 0; }
target=r[1];
r[16]=0x0c0cba36u;
r[4]=r[15];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0cba36u) { target=s->pc; goto dispatch; }
goto P_0c0cba36;
P_0c0cba34: /* original 64f3, guest PC 0x0c0cba34 */
if(!s->budget--) { s->failed_pc=0x0c0cba34u; return 0; }
r[4]=r[15];
goto P_0c0cba36;
P_0c0cba36: /* original 9345, guest PC 0x0c0cba36 */
if(!s->budget--) { s->failed_pc=0x0c0cba36u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0cbac4u,2);
goto P_0c0cba38;
P_0c0cba38: /* original 6403, guest PC 0x0c0cba38 */
if(!s->budget--) { s->failed_pc=0x0c0cba38u; return 0; }
r[4]=r[0];
goto P_0c0cba3a;
P_0c0cba3a: /* original 2438, guest PC 0x0c0cba3a */
if(!s->budget--) { s->failed_pc=0x0c0cba3au; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[3])==0)!=0);
goto P_0c0cba3c;
P_0c0cba3c: /* original 8915, guest PC 0x0c0cba3c */
if(!s->budget--) { s->failed_pc=0x0c0cba3cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0cba6a; }
goto P_0c0cba3e;
P_0c0cba3e: /* original e104, guest PC 0x0c0cba3e */
if(!s->budget--) { s->failed_pc=0x0c0cba3eu; return 0; }
r[1]=0x00000004u;
goto P_0c0cba40;
P_0c0cba40: /* original a013, guest PC 0x0c0cba40 */
if(!s->budget--) { s->failed_pc=0x0c0cba40u; return 0; }
r[14]|=r[1];
goto P_0c0cba6a;
P_0c0cba42: /* original 2e1b, guest PC 0x0c0cba42 */
if(!s->budget--) { s->failed_pc=0x0c0cba42u; return 0; }
r[14]|=r[1];
goto P_0c0cba44;
P_0c0cba44: /* original d123, guest PC 0x0c0cba44 */
if(!s->budget--) { s->failed_pc=0x0c0cba44u; return 0; }
r[1]=read(ram,0x0c0cbad4u,4);
goto P_0c0cba46;
P_0c0cba46: /* original 410b, guest PC 0x0c0cba46 */
if(!s->budget--) { s->failed_pc=0x0c0cba46u; return 0; }
target=r[1];
r[16]=0x0c0cba4au;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0cba4au) { target=s->pc; goto dispatch; }
goto P_0c0cba4a;
P_0c0cba48: /* original 0009, guest PC 0x0c0cba48 */
if(!s->budget--) { s->failed_pc=0x0c0cba48u; return 0; }
goto P_0c0cba4a;
P_0c0cba4a: /* original 60a3, guest PC 0x0c0cba4a */
if(!s->budget--) { s->failed_pc=0x0c0cba4au; return 0; }
r[0]=r[10];
goto P_0c0cba4c;
P_0c0cba4c: /* original 880b, guest PC 0x0c0cba4c */
if(!s->budget--) { s->failed_pc=0x0c0cba4cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000bu)!=0);
goto P_0c0cba4e;
P_0c0cba4e: /* original ff0a, guest PC 0x0c0cba4e */
if(!s->budget--) { s->failed_pc=0x0c0cba4eu; return 0; }
vf3_matrix_store(s,ram,0,r[15]);
goto P_0c0cba50;
P_0c0cba50: /* original e402, guest PC 0x0c0cba50 */
if(!s->budget--) { s->failed_pc=0x0c0cba50u; return 0; }
r[4]=0x00000002u;
goto P_0c0cba52;
P_0c0cba52: /* original 8f04, guest PC 0x0c0cba52 */
if(!s->budget--) { s->failed_pc=0x0c0cba52u; return 0; }
cond=r[17]&1u;
r[4]&=r[8];
if(!cond) { goto P_0c0cba5e; }
goto P_0c0cba56;
P_0c0cba54: /* original 2489, guest PC 0x0c0cba54 */
if(!s->budget--) { s->failed_pc=0x0c0cba54u; return 0; }
r[4]&=r[8];
goto P_0c0cba56;
P_0c0cba56: /* original 2448, guest PC 0x0c0cba56 */
if(!s->budget--) { s->failed_pc=0x0c0cba56u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c0cba58;
P_0c0cba58: /* original 8967, guest PC 0x0c0cba58 */
if(!s->budget--) { s->failed_pc=0x0c0cba58u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0cbb2a; }
goto P_0c0cba5a;
P_0c0cba5a: /* original a006, guest PC 0x0c0cba5a */
if(!s->budget--) { s->failed_pc=0x0c0cba5au; return 0; }
goto P_0c0cba6a;
P_0c0cba5c: /* original 0009, guest PC 0x0c0cba5c */
if(!s->budget--) { s->failed_pc=0x0c0cba5cu; return 0; }
goto P_0c0cba5e;
P_0c0cba5e: /* original 8806, guest PC 0x0c0cba5e */
if(!s->budget--) { s->failed_pc=0x0c0cba5eu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000006u)!=0);
goto P_0c0cba60;
P_0c0cba60: /* original 8b03, guest PC 0x0c0cba60 */
if(!s->budget--) { s->failed_pc=0x0c0cba60u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0cba6a; }
goto P_0c0cba62;
P_0c0cba62: /* original 2448, guest PC 0x0c0cba62 */
if(!s->budget--) { s->failed_pc=0x0c0cba62u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c0cba64;
P_0c0cba64: /* original 8901, guest PC 0x0c0cba64 */
if(!s->budget--) { s->failed_pc=0x0c0cba64u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0cba6a; }
goto P_0c0cba66;
P_0c0cba66: /* original c71c, guest PC 0x0c0cba66 */
if(!s->budget--) { s->failed_pc=0x0c0cba66u; return 0; }
r[0]=0x0c0cbad8u;
goto P_0c0cba68;
P_0c0cba68: /* original ff08, guest PC 0x0c0cba68 */
if(!s->budget--) { s->failed_pc=0x0c0cba68u; return 0; }
vf3_matrix_load(s,ram,15,r[0]);
goto P_0c0cba6a;
P_0c0cba6a: /* original f4f8, guest PC 0x0c0cba6a */
if(!s->budget--) { s->failed_pc=0x0c0cba6au; return 0; }
vf3_matrix_load(s,ram,4,r[15]);
goto P_0c0cba6c;
P_0c0cba6c: /* original e004, guest PC 0x0c0cba6c */
if(!s->budget--) { s->failed_pc=0x0c0cba6cu; return 0; }
r[0]=0x00000004u;
goto P_0c0cba6e;
P_0c0cba6e: /* original f6c6, guest PC 0x0c0cba6e */
if(!s->budget--) { s->failed_pc=0x0c0cba6eu; return 0; }
vf3_matrix_load(s,ram,6,r[12]+r[0]);
goto P_0c0cba70;
P_0c0cba70: /* original 609c, guest PC 0x0c0cba70 */
if(!s->budget--) { s->failed_pc=0x0c0cba70u; return 0; }
r[0]=r[9]&255u;
goto P_0c0cba72;
P_0c0cba72: /* original f4f1, guest PC 0x0c0cba72 */
if(!s->budget--) { s->failed_pc=0x0c0cba72u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[15],r[18],'-');
goto P_0c0cba74;
P_0c0cba74: /* original f3f8, guest PC 0x0c0cba74 */
if(!s->budget--) { s->failed_pc=0x0c0cba74u; return 0; }
vf3_matrix_load(s,ram,3,r[15]);
goto P_0c0cba76;
P_0c0cba76: /* original f28d, guest PC 0x0c0cba76 */
if(!s->budget--) { s->failed_pc=0x0c0cba76u; return 0; }
fr[2]=0;
goto P_0c0cba78;
P_0c0cba78: /* original e401, guest PC 0x0c0cba78 */
if(!s->budget--) { s->failed_pc=0x0c0cba78u; return 0; }
r[4]=0x00000001u;
goto P_0c0cba7a;
P_0c0cba7a: /* original f56c, guest PC 0x0c0cba7a */
if(!s->budget--) { s->failed_pc=0x0c0cba7au; return 0; }
vf3_matrix_move(s,5,6);
goto P_0c0cba7c;
P_0c0cba7c: /* original f631, guest PC 0x0c0cba7c */
if(!s->budget--) { s->failed_pc=0x0c0cba7cu; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[3],r[18],'-');
goto P_0c0cba7e;
P_0c0cba7e: /* original f5f1, guest PC 0x0c0cba7e */
if(!s->budget--) { s->failed_pc=0x0c0cba7eu; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[15],r[18],'-');
goto P_0c0cba80;
P_0c0cba80: /* original f245, guest PC 0x0c0cba80 */
if(!s->budget--) { s->failed_pc=0x0c0cba80u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[2])>as_float(fr[4]))!=0);
goto P_0c0cba82;
P_0c0cba82: /* original 8f12, guest PC 0x0c0cba82 */
if(!s->budget--) { s->failed_pc=0x0c0cba82u; return 0; }
cond=r[17]&1u;
r[4]&=r[0];
if(!cond) { goto P_0c0cbaaa; }
goto P_0c0cba86;
P_0c0cba84: /* original 2409, guest PC 0x0c0cba84 */
if(!s->budget--) { s->failed_pc=0x0c0cba84u; return 0; }
r[4]&=r[0];
goto P_0c0cba86;
P_0c0cba86: /* original f28d, guest PC 0x0c0cba86 */
if(!s->budget--) { s->failed_pc=0x0c0cba86u; return 0; }
fr[2]=0;
goto P_0c0cba88;
P_0c0cba88: /* original f525, guest PC 0x0c0cba88 */
if(!s->budget--) { s->failed_pc=0x0c0cba88u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[5])>as_float(fr[2]))!=0);
goto P_0c0cba8a;
P_0c0cba8a: /* original 8908, guest PC 0x0c0cba8a */
if(!s->budget--) { s->failed_pc=0x0c0cba8au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0cba9e; }
goto P_0c0cba8c;
P_0c0cba8c: /* original 921b, guest PC 0x0c0cba8c */
if(!s->budget--) { s->failed_pc=0x0c0cba8cu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0cbac6u,2);
goto P_0c0cba8e;
P_0c0cba8e: /* original e302, guest PC 0x0c0cba8e */
if(!s->budget--) { s->failed_pc=0x0c0cba8eu; return 0; }
r[3]=0x00000002u;
goto P_0c0cba90;
P_0c0cba90: /* original 2448, guest PC 0x0c0cba90 */
if(!s->budget--) { s->failed_pc=0x0c0cba90u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c0cba92;
P_0c0cba92: /* original 2e29, guest PC 0x0c0cba92 */
if(!s->budget--) { s->failed_pc=0x0c0cba92u; return 0; }
r[14]&=r[2];
goto P_0c0cba94;
P_0c0cba94: /* original 2e3b, guest PC 0x0c0cba94 */
if(!s->budget--) { s->failed_pc=0x0c0cba94u; return 0; }
r[14]|=r[3];
goto P_0c0cba96;
P_0c0cba96: /* original 8f10, guest PC 0x0c0cba96 */
if(!s->budget--) { s->failed_pc=0x0c0cba96u; return 0; }
cond=r[17]&1u;
vf3_matrix_store(s,ram,15,r[15]);
if(!cond) { goto P_0c0cbaba; }
goto P_0c0cba9a;
P_0c0cba98: /* original fffa, guest PC 0x0c0cba98 */
if(!s->budget--) { s->failed_pc=0x0c0cba98u; return 0; }
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c0cba9a;
P_0c0cba9a: /* original a010, guest PC 0x0c0cba9a */
if(!s->budget--) { s->failed_pc=0x0c0cba9au; return 0; }
goto P_0c0cbabe;
P_0c0cba9c: /* original 0009, guest PC 0x0c0cba9c */
if(!s->budget--) { s->failed_pc=0x0c0cba9cu; return 0; }
goto P_0c0cba9e;
P_0c0cba9e: /* original 2448, guest PC 0x0c0cba9e */
if(!s->budget--) { s->failed_pc=0x0c0cba9eu; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c0cbaa0;
P_0c0cbaa0: /* original e201, guest PC 0x0c0cbaa0 */
if(!s->budget--) { s->failed_pc=0x0c0cbaa0u; return 0; }
r[2]=0x00000001u;
goto P_0c0cbaa2;
P_0c0cbaa2: /* original 8f1f, guest PC 0x0c0cbaa2 */
if(!s->budget--) { s->failed_pc=0x0c0cbaa2u; return 0; }
cond=r[17]&1u;
r[14]|=r[2];
if(!cond) { goto P_0c0cbae4; }
goto P_0c0cbaa6;
P_0c0cbaa4: /* original 2e2b, guest PC 0x0c0cbaa4 */
if(!s->budget--) { s->failed_pc=0x0c0cbaa4u; return 0; }
r[14]|=r[2];
goto P_0c0cbaa6;
P_0c0cbaa6: /* original a01f, guest PC 0x0c0cbaa6 */
if(!s->budget--) { s->failed_pc=0x0c0cbaa6u; return 0; }
goto P_0c0cbae8;
P_0c0cbaa8: /* original 0009, guest PC 0x0c0cbaa8 */
if(!s->budget--) { s->failed_pc=0x0c0cbaa8u; return 0; }
goto P_0c0cbaaa;
P_0c0cbaaa: /* original f625, guest PC 0x0c0cbaaa */
if(!s->budget--) { s->failed_pc=0x0c0cbaaau; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[6])>as_float(fr[2]))!=0);
goto P_0c0cbaac;
P_0c0cbaac: /* original 8916, guest PC 0x0c0cbaac */
if(!s->budget--) { s->failed_pc=0x0c0cbaacu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0cbadc; }
goto P_0c0cbaae;
P_0c0cbaae: /* original 920a, guest PC 0x0c0cbaae */
if(!s->budget--) { s->failed_pc=0x0c0cbaaeu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0cbac6u,2);
goto P_0c0cbab0;
P_0c0cbab0: /* original 2448, guest PC 0x0c0cbab0 */
if(!s->budget--) { s->failed_pc=0x0c0cbab0u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c0cbab2;
P_0c0cbab2: /* original 9309, guest PC 0x0c0cbab2 */
if(!s->budget--) { s->failed_pc=0x0c0cbab2u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0cbac8u,2);
goto P_0c0cbab4;
P_0c0cbab4: /* original 2e29, guest PC 0x0c0cbab4 */
if(!s->budget--) { s->failed_pc=0x0c0cbab4u; return 0; }
r[14]&=r[2];
goto P_0c0cbab6;
P_0c0cbab6: /* original 8d02, guest PC 0x0c0cbab6 */
if(!s->budget--) { s->failed_pc=0x0c0cbab6u; return 0; }
cond=r[17]&1u;
r[14]&=r[3];
if(cond) { goto P_0c0cbabe; }
goto P_0c0cbaba;
P_0c0cbab8: /* original 2e39, guest PC 0x0c0cbab8 */
if(!s->budget--) { s->failed_pc=0x0c0cbab8u; return 0; }
r[14]&=r[3];
goto P_0c0cbaba;
P_0c0cbaba: /* original a016, guest PC 0x0c0cbaba */
if(!s->budget--) { s->failed_pc=0x0c0cbabau; return 0; }
r[4]=0x00000000u;
goto P_0c0cbaea;
P_0c0cbabc: /* original e400, guest PC 0x0c0cbabc */
if(!s->budget--) { s->failed_pc=0x0c0cbabcu; return 0; }
r[4]=0x00000000u;
goto P_0c0cbabe;
P_0c0cbabe: /* original a014, guest PC 0x0c0cbabe */
if(!s->budget--) { s->failed_pc=0x0c0cbabeu; return 0; }
r[4]=0x00000004u;
goto P_0c0cbaea;
P_0c0cbac0: /* original e404, guest PC 0x0c0cbac0 */
if(!s->budget--) { s->failed_pc=0x0c0cbac0u; return 0; }
r[4]=0x00000004u;
return vf3_matrix_family(0x0c0cbac2u,s,ram);
P_0c0cbadc: /* original 2448, guest PC 0x0c0cbadc */
if(!s->budget--) { s->failed_pc=0x0c0cbadcu; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c0cbade;
P_0c0cbade: /* original e301, guest PC 0x0c0cbade */
if(!s->budget--) { s->failed_pc=0x0c0cbadeu; return 0; }
r[3]=0x00000001u;
goto P_0c0cbae0;
P_0c0cbae0: /* original 8d02, guest PC 0x0c0cbae0 */
if(!s->budget--) { s->failed_pc=0x0c0cbae0u; return 0; }
cond=r[17]&1u;
r[14]|=r[3];
if(cond) { goto P_0c0cbae8; }
goto P_0c0cbae4;
P_0c0cbae2: /* original 2e3b, guest PC 0x0c0cbae2 */
if(!s->budget--) { s->failed_pc=0x0c0cbae2u; return 0; }
r[14]|=r[3];
goto P_0c0cbae4;
P_0c0cbae4: /* original a001, guest PC 0x0c0cbae4 */
if(!s->budget--) { s->failed_pc=0x0c0cbae4u; return 0; }
r[4]=0x0000000cu;
goto P_0c0cbaea;
P_0c0cbae6: /* original e40c, guest PC 0x0c0cbae6 */
if(!s->budget--) { s->failed_pc=0x0c0cbae6u; return 0; }
r[4]=0x0000000cu;
goto P_0c0cbae8;
P_0c0cbae8: /* original e408, guest PC 0x0c0cbae8 */
if(!s->budget--) { s->failed_pc=0x0c0cbae8u; return 0; }
r[4]=0x00000008u;
goto P_0c0cbaea;
P_0c0cbaea: /* original e070, guest PC 0x0c0cbaea */
if(!s->budget--) { s->failed_pc=0x0c0cbaeau; return 0; }
r[0]=0x00000070u;
goto P_0c0cbaec;
P_0c0cbaec: /* original 6143, guest PC 0x0c0cbaec */
if(!s->budget--) { s->failed_pc=0x0c0cbaecu; return 0; }
r[1]=r[4];
goto P_0c0cbaee;
P_0c0cbaee: /* original 02fe, guest PC 0x0c0cbaee */
if(!s->budget--) { s->failed_pc=0x0c0cbaeeu; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c0cbaf0;
P_0c0cbaf0: /* original 63ec, guest PC 0x0c0cbaf0 */
if(!s->budget--) { s->failed_pc=0x0c0cbaf0u; return 0; }
r[3]=r[14]&255u;
goto P_0c0cbaf2;
P_0c0cbaf2: /* original 1f26, guest PC 0x0c0cbaf2 */
if(!s->budget--) { s->failed_pc=0x0c0cbaf2u; return 0; }
write(ram,r[15]+24,r[2],4);
goto P_0c0cbaf4;
P_0c0cbaf4: /* original 1f87, guest PC 0x0c0cbaf4 */
if(!s->budget--) { s->failed_pc=0x0c0cbaf4u; return 0; }
write(ram,r[15]+28,r[8],4);
goto P_0c0cbaf6;
P_0c0cbaf6: /* original 1f38, guest PC 0x0c0cbaf6 */
if(!s->budget--) { s->failed_pc=0x0c0cbaf6u; return 0; }
write(ram,r[15]+32,r[3],4);
goto P_0c0cbaf8;
P_0c0cbaf8: /* original d213, guest PC 0x0c0cbaf8 */
if(!s->budget--) { s->failed_pc=0x0c0cbaf8u; return 0; }
r[2]=read(ram,0x0c0cbb48u,4);
goto P_0c0cbafa;
P_0c0cbafa: /* original 420b, guest PC 0x0c0cbafa */
if(!s->budget--) { s->failed_pc=0x0c0cbafau; return 0; }
target=r[2];
r[16]=0x0c0cbafeu;
r[0]=0x00000004u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0cbafeu) { target=s->pc; goto dispatch; }
goto P_0c0cbafe;
P_0c0cbafc: /* original e004, guest PC 0x0c0cbafc */
if(!s->budget--) { s->failed_pc=0x0c0cbafcu; return 0; }
r[0]=0x00000004u;
goto P_0c0cbafe;
P_0c0cbafe: /* original d113, guest PC 0x0c0cbafe */
if(!s->budget--) { s->failed_pc=0x0c0cbafeu; return 0; }
r[1]=read(ram,0x0c0cbb4cu,4);
goto P_0c0cbb00;
P_0c0cbb00: /* original 4008, guest PC 0x0c0cbb00 */
if(!s->budget--) { s->failed_pc=0x0c0cbb00u; return 0; }
r[0]<<=2;
goto P_0c0cbb02;
P_0c0cbb02: /* original 65d3, guest PC 0x0c0cbb02 */
if(!s->budget--) { s->failed_pc=0x0c0cbb02u; return 0; }
r[5]=r[13];
goto P_0c0cbb04;
P_0c0cbb04: /* original 66c3, guest PC 0x0c0cbb04 */
if(!s->budget--) { s->failed_pc=0x0c0cbb04u; return 0; }
r[6]=r[12];
goto P_0c0cbb06;
P_0c0cbb06: /* original 031e, guest PC 0x0c0cbb06 */
if(!s->budget--) { s->failed_pc=0x0c0cbb06u; return 0; }
r[3]=read(ram,r[1]+r[0],4);
goto P_0c0cbb08;
P_0c0cbb08: /* original 1f32, guest PC 0x0c0cbb08 */
if(!s->budget--) { s->failed_pc=0x0c0cbb08u; return 0; }
write(ram,r[15]+8,r[3],4);
goto P_0c0cbb0a;
P_0c0cbb0a: /* original 6233, guest PC 0x0c0cbb0a */
if(!s->budget--) { s->failed_pc=0x0c0cbb0au; return 0; }
r[2]=r[3];
goto P_0c0cbb0c;
P_0c0cbb0c: /* original 2f86, guest PC 0x0c0cbb0c */
if(!s->budget--) { s->failed_pc=0x0c0cbb0cu; return 0; }
r[15]-=4; write(ram,r[15],r[8],4);
goto P_0c0cbb0e;
P_0c0cbb0e: /* original 63f3, guest PC 0x0c0cbb0e */
if(!s->budget--) { s->failed_pc=0x0c0cbb0eu; return 0; }
r[3]=r[15];
goto P_0c0cbb10;
P_0c0cbb10: /* original 731c, guest PC 0x0c0cbb10 */
if(!s->budget--) { s->failed_pc=0x0c0cbb10u; return 0; }
r[3]+=0x0000001cu;
goto P_0c0cbb12;
P_0c0cbb12: /* original 2f36, guest PC 0x0c0cbb12 */
if(!s->budget--) { s->failed_pc=0x0c0cbb12u; return 0; }
r[15]-=4; write(ram,r[15],r[3],4);
goto P_0c0cbb14;
P_0c0cbb14: /* original 57f3, guest PC 0x0c0cbb14 */
if(!s->budget--) { s->failed_pc=0x0c0cbb14u; return 0; }
r[7]=read(ram,r[15]+12,4);
goto P_0c0cbb16;
P_0c0cbb16: /* original 420b, guest PC 0x0c0cbb16 */
if(!s->budget--) { s->failed_pc=0x0c0cbb16u; return 0; }
target=r[2];
r[16]=0x0c0cbb1au;
r[4]=r[11];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0cbb1au) { target=s->pc; goto dispatch; }
goto P_0c0cbb1a;
P_0c0cbb18: /* original 64b3, guest PC 0x0c0cbb18 */
if(!s->budget--) { s->failed_pc=0x0c0cbb18u; return 0; }
r[4]=r[11];
goto P_0c0cbb1a;
P_0c0cbb1a: /* original 7f08, guest PC 0x0c0cbb1a */
if(!s->budget--) { s->failed_pc=0x0c0cbb1au; return 0; }
r[15]+=0x00000008u;
goto P_0c0cbb1c;
P_0c0cbb1c: /* original 66c3, guest PC 0x0c0cbb1c */
if(!s->budget--) { s->failed_pc=0x0c0cbb1cu; return 0; }
r[6]=r[12];
goto P_0c0cbb1e;
P_0c0cbb1e: /* original 65f3, guest PC 0x0c0cbb1e */
if(!s->budget--) { s->failed_pc=0x0c0cbb1eu; return 0; }
r[5]=r[15];
goto P_0c0cbb20;
P_0c0cbb20: /* original 57f1, guest PC 0x0c0cbb20 */
if(!s->budget--) { s->failed_pc=0x0c0cbb20u; return 0; }
r[7]=read(ram,r[15]+4,4);
goto P_0c0cbb22;
P_0c0cbb22: /* original f4f8, guest PC 0x0c0cbb22 */
if(!s->budget--) { s->failed_pc=0x0c0cbb22u; return 0; }
vf3_matrix_load(s,ram,4,r[15]);
goto P_0c0cbb24;
P_0c0cbb24: /* original 7518, guest PC 0x0c0cbb24 */
if(!s->budget--) { s->failed_pc=0x0c0cbb24u; return 0; }
r[5]+=0x00000018u;
goto P_0c0cbb26;
P_0c0cbb26: /* original bee1, guest PC 0x0c0cbb26 */
if(!s->budget--) { s->failed_pc=0x0c0cbb26u; return 0; }
target=0x0c0cb8ecu; r[16]=0x0c0cbb2au;
r[4]=r[11];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0cbb2au) { target=s->pc; goto dispatch; }
goto P_0c0cbb2a;
P_0c0cbb28: /* original 64b3, guest PC 0x0c0cbb28 */
if(!s->budget--) { s->failed_pc=0x0c0cbb28u; return 0; }
r[4]=r[11];
goto P_0c0cbb2a;
P_0c0cbb2a: /* original 2de0, guest PC 0x0c0cbb2a */
if(!s->budget--) { s->failed_pc=0x0c0cbb2au; return 0; }
write(ram,r[13],r[14],1);
goto P_0c0cbb2c;
P_0c0cbb2c: /* original 50f9, guest PC 0x0c0cbb2c */
if(!s->budget--) { s->failed_pc=0x0c0cbb2cu; return 0; }
r[0]=read(ram,r[15]+36,4);
goto P_0c0cbb2e;
P_0c0cbb2e: /* original 80d1, guest PC 0x0c0cbb2e */
if(!s->budget--) { s->failed_pc=0x0c0cbb2eu; return 0; }
write(ram,r[13]+1,r[0],1);
goto P_0c0cbb30;
P_0c0cbb30: /* original 7f4c, guest PC 0x0c0cbb30 */
if(!s->budget--) { s->failed_pc=0x0c0cbb30u; return 0; }
r[15]+=0x0000004cu;
goto P_0c0cbb32;
P_0c0cbb32: /* original 4f26, guest PC 0x0c0cbb32 */
if(!s->budget--) { s->failed_pc=0x0c0cbb32u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0cbb34;
P_0c0cbb34: /* original fff9, guest PC 0x0c0cbb34 */
if(!s->budget--) { s->failed_pc=0x0c0cbb34u; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0cbb36;
P_0c0cbb36: /* original 68f6, guest PC 0x0c0cbb36 */
if(!s->budget--) { s->failed_pc=0x0c0cbb36u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c0cbb38;
P_0c0cbb38: /* original 69f6, guest PC 0x0c0cbb38 */
if(!s->budget--) { s->failed_pc=0x0c0cbb38u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c0cbb3a;
P_0c0cbb3a: /* original 6af6, guest PC 0x0c0cbb3a */
if(!s->budget--) { s->failed_pc=0x0c0cbb3au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0cbb3c;
P_0c0cbb3c: /* original 6bf6, guest PC 0x0c0cbb3c */
if(!s->budget--) { s->failed_pc=0x0c0cbb3cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0cbb3e;
P_0c0cbb3e: /* original 6cf6, guest PC 0x0c0cbb3e */
if(!s->budget--) { s->failed_pc=0x0c0cbb3eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0cbb40;
P_0c0cbb40: /* original 6df6, guest PC 0x0c0cbb40 */
if(!s->budget--) { s->failed_pc=0x0c0cbb40u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0cbb42;
P_0c0cbb42: /* original 000b, guest PC 0x0c0cbb42 */
if(!s->budget--) { s->failed_pc=0x0c0cbb42u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0cbb44: /* original 6ef6, guest PC 0x0c0cbb44 */
if(!s->budget--) { s->failed_pc=0x0c0cbb44u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0cbb46u,s,ram);
P_0c0cbb6a: /* original 4f22, guest PC 0x0c0cbb6a */
if(!s->budget--) { s->failed_pc=0x0c0cbb6au; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0cbb6c;
P_0c0cbb6c: /* original f3d6, guest PC 0x0c0cbb6c */
if(!s->budget--) { s->failed_pc=0x0c0cbb6cu; return 0; }
vf3_matrix_load(s,ram,3,r[13]+r[0]);
goto P_0c0cbb6e;
P_0c0cbb6e: /* original e00c, guest PC 0x0c0cbb6e */
if(!s->budget--) { s->failed_pc=0x0c0cbb6eu; return 0; }
r[0]=0x0000000cu;
goto P_0c0cbb70;
P_0c0cbb70: /* original 7fe8, guest PC 0x0c0cbb70 */
if(!s->budget--) { s->failed_pc=0x0c0cbb70u; return 0; }
r[15]+=0xffffffe8u;
goto P_0c0cbb72;
P_0c0cbb72: /* original ff37, guest PC 0x0c0cbb72 */
if(!s->budget--) { s->failed_pc=0x0c0cbb72u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0cbb74;
P_0c0cbb74: /* original 90a9, guest PC 0x0c0cbb74 */
if(!s->budget--) { s->failed_pc=0x0c0cbb74u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0cbccau,2);
goto P_0c0cbb76;
P_0c0cbb76: /* original f3d6, guest PC 0x0c0cbb76 */
if(!s->budget--) { s->failed_pc=0x0c0cbb76u; return 0; }
vf3_matrix_load(s,ram,3,r[13]+r[0]);
goto P_0c0cbb78;
P_0c0cbb78: /* original e010, guest PC 0x0c0cbb78 */
if(!s->budget--) { s->failed_pc=0x0c0cbb78u; return 0; }
r[0]=0x00000010u;
goto P_0c0cbb7a;
P_0c0cbb7a: /* original ff37, guest PC 0x0c0cbb7a */
if(!s->budget--) { s->failed_pc=0x0c0cbb7au; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0cbb7c;
P_0c0cbb7c: /* original 90a6, guest PC 0x0c0cbb7c */
if(!s->budget--) { s->failed_pc=0x0c0cbb7cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0cbcccu,2);
goto P_0c0cbb7e;
P_0c0cbb7e: /* original f3d6, guest PC 0x0c0cbb7e */
if(!s->budget--) { s->failed_pc=0x0c0cbb7eu; return 0; }
vf3_matrix_load(s,ram,3,r[13]+r[0]);
goto P_0c0cbb80;
P_0c0cbb80: /* original e014, guest PC 0x0c0cbb80 */
if(!s->budget--) { s->failed_pc=0x0c0cbb80u; return 0; }
r[0]=0x00000014u;
goto P_0c0cbb82;
P_0c0cbb82: /* original f34d, guest PC 0x0c0cbb82 */
if(!s->budget--) { s->failed_pc=0x0c0cbb82u; return 0; }
fr[3]^=0x80000000u;
goto P_0c0cbb84;
P_0c0cbb84: /* original ff37, guest PC 0x0c0cbb84 */
if(!s->budget--) { s->failed_pc=0x0c0cbb84u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0cbb86;
P_0c0cbb86: /* original c755, guest PC 0x0c0cbb86 */
if(!s->budget--) { s->failed_pc=0x0c0cbb86u; return 0; }
r[0]=0x0c0cbcdcu;
goto P_0c0cbb88;
P_0c0cbb88: /* original fe08, guest PC 0x0c0cbb88 */
if(!s->budget--) { s->failed_pc=0x0c0cbb88u; return 0; }
vf3_matrix_load(s,ram,14,r[0]);
goto P_0c0cbb8a;
P_0c0cbb8a: /* original e010, guest PC 0x0c0cbb8a */
if(!s->budget--) { s->failed_pc=0x0c0cbb8au; return 0; }
r[0]=0x00000010u;
goto P_0c0cbb8c;
P_0c0cbb8c: /* original f3f6, guest PC 0x0c0cbb8c */
if(!s->budget--) { s->failed_pc=0x0c0cbb8cu; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0cbb8e;
P_0c0cbb8e: /* original f4ec, guest PC 0x0c0cbb8e */
if(!s->budget--) { s->failed_pc=0x0c0cbb8eu; return 0; }
vf3_matrix_move(s,4,14);
goto P_0c0cbb90;
P_0c0cbb90: /* original f340, guest PC 0x0c0cbb90 */
if(!s->budget--) { s->failed_pc=0x0c0cbb90u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'+');
goto P_0c0cbb92;
P_0c0cbb92: /* original e010, guest PC 0x0c0cbb92 */
if(!s->budget--) { s->failed_pc=0x0c0cbb92u; return 0; }
r[0]=0x00000010u;
goto P_0c0cbb94;
P_0c0cbb94: /* original e400, guest PC 0x0c0cbb94 */
if(!s->budget--) { s->failed_pc=0x0c0cbb94u; return 0; }
r[4]=0x00000000u;
goto P_0c0cbb96;
P_0c0cbb96: /* original ff37, guest PC 0x0c0cbb96 */
if(!s->budget--) { s->failed_pc=0x0c0cbb96u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0cbb98;
P_0c0cbb98: /* original e004, guest PC 0x0c0cbb98 */
if(!s->budget--) { s->failed_pc=0x0c0cbb98u; return 0; }
r[0]=0x00000004u;
goto P_0c0cbb9a;
P_0c0cbb9a: /* original f3e6, guest PC 0x0c0cbb9a */
if(!s->budget--) { s->failed_pc=0x0c0cbb9au; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c0cbb9c;
P_0c0cbb9c: /* original e008, guest PC 0x0c0cbb9c */
if(!s->budget--) { s->failed_pc=0x0c0cbb9cu; return 0; }
r[0]=0x00000008u;
goto P_0c0cbb9e;
P_0c0cbb9e: /* original ff3a, guest PC 0x0c0cbb9e */
if(!s->budget--) { s->failed_pc=0x0c0cbb9eu; return 0; }
vf3_matrix_store(s,ram,3,r[15]);
goto P_0c0cbba0;
P_0c0cbba0: /* original f3e6, guest PC 0x0c0cbba0 */
if(!s->budget--) { s->failed_pc=0x0c0cbba0u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c0cbba2;
P_0c0cbba2: /* original e004, guest PC 0x0c0cbba2 */
if(!s->budget--) { s->failed_pc=0x0c0cbba2u; return 0; }
r[0]=0x00000004u;
goto P_0c0cbba4;
P_0c0cbba4: /* original ff37, guest PC 0x0c0cbba4 */
if(!s->budget--) { s->failed_pc=0x0c0cbba4u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0cbba6;
P_0c0cbba6: /* original e00c, guest PC 0x0c0cbba6 */
if(!s->budget--) { s->failed_pc=0x0c0cbba6u; return 0; }
r[0]=0x0000000cu;
goto P_0c0cbba8;
P_0c0cbba8: /* original f3e6, guest PC 0x0c0cbba8 */
if(!s->budget--) { s->failed_pc=0x0c0cbba8u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c0cbbaa;
P_0c0cbbaa: /* original e008, guest PC 0x0c0cbbaa */
if(!s->budget--) { s->failed_pc=0x0c0cbbaau; return 0; }
r[0]=0x00000008u;
goto P_0c0cbbac;
P_0c0cbbac: /* original ff37, guest PC 0x0c0cbbac */
if(!s->budget--) { s->failed_pc=0x0c0cbbacu; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0cbbae;
P_0c0cbbae: /* original e00c, guest PC 0x0c0cbbae */
if(!s->budget--) { s->failed_pc=0x0c0cbbaeu; return 0; }
r[0]=0x0000000cu;
goto P_0c0cbbb0;
P_0c0cbbb0: /* original f3f6, guest PC 0x0c0cbbb0 */
if(!s->budget--) { s->failed_pc=0x0c0cbbb0u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0cbbb2;
P_0c0cbbb2: /* original e004, guest PC 0x0c0cbbb2 */
if(!s->budget--) { s->failed_pc=0x0c0cbbb2u; return 0; }
r[0]=0x00000004u;
goto P_0c0cbbb4;
P_0c0cbbb4: /* original fe37, guest PC 0x0c0cbbb4 */
if(!s->budget--) { s->failed_pc=0x0c0cbbb4u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c0cbbb6;
P_0c0cbbb6: /* original e010, guest PC 0x0c0cbbb6 */
if(!s->budget--) { s->failed_pc=0x0c0cbbb6u; return 0; }
r[0]=0x00000010u;
goto P_0c0cbbb8;
P_0c0cbbb8: /* original f3f6, guest PC 0x0c0cbbb8 */
if(!s->budget--) { s->failed_pc=0x0c0cbbb8u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0cbbba;
P_0c0cbbba: /* original e008, guest PC 0x0c0cbbba */
if(!s->budget--) { s->failed_pc=0x0c0cbbbau; return 0; }
r[0]=0x00000008u;
goto P_0c0cbbbc;
P_0c0cbbbc: /* original fe37, guest PC 0x0c0cbbbc */
if(!s->budget--) { s->failed_pc=0x0c0cbbbcu; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c0cbbbe;
P_0c0cbbbe: /* original e014, guest PC 0x0c0cbbbe */
if(!s->budget--) { s->failed_pc=0x0c0cbbbeu; return 0; }
r[0]=0x00000014u;
goto P_0c0cbbc0;
P_0c0cbbc0: /* original f3f6, guest PC 0x0c0cbbc0 */
if(!s->budget--) { s->failed_pc=0x0c0cbbc0u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0cbbc2;
P_0c0cbbc2: /* original e00c, guest PC 0x0c0cbbc2 */
if(!s->budget--) { s->failed_pc=0x0c0cbbc2u; return 0; }
r[0]=0x0000000cu;
goto P_0c0cbbc4;
P_0c0cbbc4: /* original fe37, guest PC 0x0c0cbbc4 */
if(!s->budget--) { s->failed_pc=0x0c0cbbc4u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c0cbbc6;
P_0c0cbbc6: /* original 2fb6, guest PC 0x0c0cbbc6 */
if(!s->budget--) { s->failed_pc=0x0c0cbbc6u; return 0; }
r[15]-=4; write(ram,r[15],r[11],4);
goto P_0c0cbbc8;
P_0c0cbbc8: /* original 2f46, guest PC 0x0c0cbbc8 */
if(!s->budget--) { s->failed_pc=0x0c0cbbc8u; return 0; }
r[15]-=4; write(ram,r[15],r[4],4);
goto P_0c0cbbca;
P_0c0cbbca: /* original 67f3, guest PC 0x0c0cbbca */
if(!s->budget--) { s->failed_pc=0x0c0cbbcau; return 0; }
r[7]=r[15];
goto P_0c0cbbcc;
P_0c0cbbcc: /* original 7708, guest PC 0x0c0cbbcc */
if(!s->budget--) { s->failed_pc=0x0c0cbbccu; return 0; }
r[7]+=0x00000008u;
goto P_0c0cbbce;
P_0c0cbbce: /* original f4fc, guest PC 0x0c0cbbce */
if(!s->budget--) { s->failed_pc=0x0c0cbbceu; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c0cbbd0;
P_0c0cbbd0: /* original 66f3, guest PC 0x0c0cbbd0 */
if(!s->budget--) { s->failed_pc=0x0c0cbbd0u; return 0; }
r[6]=r[15];
goto P_0c0cbbd2;
P_0c0cbbd2: /* original 65e3, guest PC 0x0c0cbbd2 */
if(!s->budget--) { s->failed_pc=0x0c0cbbd2u; return 0; }
r[5]=r[14];
goto P_0c0cbbd4;
P_0c0cbbd4: /* original 7614, guest PC 0x0c0cbbd4 */
if(!s->budget--) { s->failed_pc=0x0c0cbbd4u; return 0; }
r[6]+=0x00000014u;
goto P_0c0cbbd6;
P_0c0cbbd6: /* original beff, guest PC 0x0c0cbbd6 */
if(!s->budget--) { s->failed_pc=0x0c0cbbd6u; return 0; }
target=0x0c0cb9d8u; r[16]=0x0c0cbbdau;
r[4]=r[12];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0cbbdau) { target=s->pc; goto dispatch; }
goto P_0c0cbbda;
P_0c0cbbd8: /* original 64c3, guest PC 0x0c0cbbd8 */
if(!s->budget--) { s->failed_pc=0x0c0cbbd8u; return 0; }
r[4]=r[12];
goto P_0c0cbbda;
P_0c0cbbda: /* original 9078, guest PC 0x0c0cbbda */
if(!s->budget--) { s->failed_pc=0x0c0cbbdau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0cbcceu,2);
goto P_0c0cbbdc;
P_0c0cbbdc: /* original 7e20, guest PC 0x0c0cbbdc */
if(!s->budget--) { s->failed_pc=0x0c0cbbdcu; return 0; }
r[14]+=0x00000020u;
goto P_0c0cbbde;
P_0c0cbbde: /* original f3d6, guest PC 0x0c0cbbde */
if(!s->budget--) { s->failed_pc=0x0c0cbbdeu; return 0; }
vf3_matrix_load(s,ram,3,r[13]+r[0]);
goto P_0c0cbbe0;
P_0c0cbbe0: /* original e014, guest PC 0x0c0cbbe0 */
if(!s->budget--) { s->failed_pc=0x0c0cbbe0u; return 0; }
r[0]=0x00000014u;
goto P_0c0cbbe2;
P_0c0cbbe2: /* original ff37, guest PC 0x0c0cbbe2 */
if(!s->budget--) { s->failed_pc=0x0c0cbbe2u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0cbbe4;
P_0c0cbbe4: /* original 9074, guest PC 0x0c0cbbe4 */
if(!s->budget--) { s->failed_pc=0x0c0cbbe4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0cbcd0u,2);
goto P_0c0cbbe6;
P_0c0cbbe6: /* original f3d6, guest PC 0x0c0cbbe6 */
if(!s->budget--) { s->failed_pc=0x0c0cbbe6u; return 0; }
vf3_matrix_load(s,ram,3,r[13]+r[0]);
goto P_0c0cbbe8;
P_0c0cbbe8: /* original e018, guest PC 0x0c0cbbe8 */
if(!s->budget--) { s->failed_pc=0x0c0cbbe8u; return 0; }
r[0]=0x00000018u;
goto P_0c0cbbea;
P_0c0cbbea: /* original ff37, guest PC 0x0c0cbbea */
if(!s->budget--) { s->failed_pc=0x0c0cbbeau; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0cbbec;
P_0c0cbbec: /* original 9071, guest PC 0x0c0cbbec */
if(!s->budget--) { s->failed_pc=0x0c0cbbecu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0cbcd2u,2);
goto P_0c0cbbee;
P_0c0cbbee: /* original f3d6, guest PC 0x0c0cbbee */
if(!s->budget--) { s->failed_pc=0x0c0cbbeeu; return 0; }
vf3_matrix_load(s,ram,3,r[13]+r[0]);
goto P_0c0cbbf0;
P_0c0cbbf0: /* original e01c, guest PC 0x0c0cbbf0 */
if(!s->budget--) { s->failed_pc=0x0c0cbbf0u; return 0; }
r[0]=0x0000001cu;
goto P_0c0cbbf2;
P_0c0cbbf2: /* original f34d, guest PC 0x0c0cbbf2 */
if(!s->budget--) { s->failed_pc=0x0c0cbbf2u; return 0; }
fr[3]^=0x80000000u;
goto P_0c0cbbf4;
P_0c0cbbf4: /* original ff37, guest PC 0x0c0cbbf4 */
if(!s->budget--) { s->failed_pc=0x0c0cbbf4u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0cbbf6;
P_0c0cbbf6: /* original e018, guest PC 0x0c0cbbf6 */
if(!s->budget--) { s->failed_pc=0x0c0cbbf6u; return 0; }
r[0]=0x00000018u;
goto P_0c0cbbf8;
P_0c0cbbf8: /* original f3f6, guest PC 0x0c0cbbf8 */
if(!s->budget--) { s->failed_pc=0x0c0cbbf8u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0cbbfa;
P_0c0cbbfa: /* original e018, guest PC 0x0c0cbbfa */
if(!s->budget--) { s->failed_pc=0x0c0cbbfau; return 0; }
r[0]=0x00000018u;
goto P_0c0cbbfc;
P_0c0cbbfc: /* original f4ec, guest PC 0x0c0cbbfc */
if(!s->budget--) { s->failed_pc=0x0c0cbbfcu; return 0; }
vf3_matrix_move(s,4,14);
goto P_0c0cbbfe;
P_0c0cbbfe: /* original f340, guest PC 0x0c0cbbfe */
if(!s->budget--) { s->failed_pc=0x0c0cbbfeu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'+');
goto P_0c0cbc00;
P_0c0cbc00: /* original ff37, guest PC 0x0c0cbc00 */
if(!s->budget--) { s->failed_pc=0x0c0cbc00u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0cbc02;
P_0c0cbc02: /* original e004, guest PC 0x0c0cbc02 */
if(!s->budget--) { s->failed_pc=0x0c0cbc02u; return 0; }
r[0]=0x00000004u;
goto P_0c0cbc04;
P_0c0cbc04: /* original f3e6, guest PC 0x0c0cbc04 */
if(!s->budget--) { s->failed_pc=0x0c0cbc04u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c0cbc06;
P_0c0cbc06: /* original e008, guest PC 0x0c0cbc06 */
if(!s->budget--) { s->failed_pc=0x0c0cbc06u; return 0; }
r[0]=0x00000008u;
goto P_0c0cbc08;
P_0c0cbc08: /* original ff37, guest PC 0x0c0cbc08 */
if(!s->budget--) { s->failed_pc=0x0c0cbc08u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0cbc0a;
P_0c0cbc0a: /* original e008, guest PC 0x0c0cbc0a */
if(!s->budget--) { s->failed_pc=0x0c0cbc0au; return 0; }
r[0]=0x00000008u;
goto P_0c0cbc0c;
P_0c0cbc0c: /* original f3e6, guest PC 0x0c0cbc0c */
if(!s->budget--) { s->failed_pc=0x0c0cbc0cu; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c0cbc0e;
P_0c0cbc0e: /* original e00c, guest PC 0x0c0cbc0e */
if(!s->budget--) { s->failed_pc=0x0c0cbc0eu; return 0; }
r[0]=0x0000000cu;
goto P_0c0cbc10;
P_0c0cbc10: /* original ff37, guest PC 0x0c0cbc10 */
if(!s->budget--) { s->failed_pc=0x0c0cbc10u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0cbc12;
P_0c0cbc12: /* original e00c, guest PC 0x0c0cbc12 */
if(!s->budget--) { s->failed_pc=0x0c0cbc12u; return 0; }
r[0]=0x0000000cu;
goto P_0c0cbc14;
P_0c0cbc14: /* original f3e6, guest PC 0x0c0cbc14 */
if(!s->budget--) { s->failed_pc=0x0c0cbc14u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c0cbc16;
P_0c0cbc16: /* original e010, guest PC 0x0c0cbc16 */
if(!s->budget--) { s->failed_pc=0x0c0cbc16u; return 0; }
r[0]=0x00000010u;
goto P_0c0cbc18;
P_0c0cbc18: /* original ff37, guest PC 0x0c0cbc18 */
if(!s->budget--) { s->failed_pc=0x0c0cbc18u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0cbc1a;
P_0c0cbc1a: /* original e014, guest PC 0x0c0cbc1a */
if(!s->budget--) { s->failed_pc=0x0c0cbc1au; return 0; }
r[0]=0x00000014u;
goto P_0c0cbc1c;
P_0c0cbc1c: /* original 65e3, guest PC 0x0c0cbc1c */
if(!s->budget--) { s->failed_pc=0x0c0cbc1cu; return 0; }
r[5]=r[14];
goto P_0c0cbc1e;
P_0c0cbc1e: /* original f3f6, guest PC 0x0c0cbc1e */
if(!s->budget--) { s->failed_pc=0x0c0cbc1eu; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0cbc20;
P_0c0cbc20: /* original e004, guest PC 0x0c0cbc20 */
if(!s->budget--) { s->failed_pc=0x0c0cbc20u; return 0; }
r[0]=0x00000004u;
goto P_0c0cbc22;
P_0c0cbc22: /* original e400, guest PC 0x0c0cbc22 */
if(!s->budget--) { s->failed_pc=0x0c0cbc22u; return 0; }
r[4]=0x00000000u;
goto P_0c0cbc24;
P_0c0cbc24: /* original fe37, guest PC 0x0c0cbc24 */
if(!s->budget--) { s->failed_pc=0x0c0cbc24u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c0cbc26;
P_0c0cbc26: /* original e018, guest PC 0x0c0cbc26 */
if(!s->budget--) { s->failed_pc=0x0c0cbc26u; return 0; }
r[0]=0x00000018u;
goto P_0c0cbc28;
P_0c0cbc28: /* original f3f6, guest PC 0x0c0cbc28 */
if(!s->budget--) { s->failed_pc=0x0c0cbc28u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0cbc2a;
P_0c0cbc2a: /* original e008, guest PC 0x0c0cbc2a */
if(!s->budget--) { s->failed_pc=0x0c0cbc2au; return 0; }
r[0]=0x00000008u;
goto P_0c0cbc2c;
P_0c0cbc2c: /* original fe37, guest PC 0x0c0cbc2c */
if(!s->budget--) { s->failed_pc=0x0c0cbc2cu; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c0cbc2e;
P_0c0cbc2e: /* original e01c, guest PC 0x0c0cbc2e */
if(!s->budget--) { s->failed_pc=0x0c0cbc2eu; return 0; }
r[0]=0x0000001cu;
goto P_0c0cbc30;
P_0c0cbc30: /* original f3f6, guest PC 0x0c0cbc30 */
if(!s->budget--) { s->failed_pc=0x0c0cbc30u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0cbc32;
P_0c0cbc32: /* original e00c, guest PC 0x0c0cbc32 */
if(!s->budget--) { s->failed_pc=0x0c0cbc32u; return 0; }
r[0]=0x0000000cu;
goto P_0c0cbc34;
P_0c0cbc34: /* original fe37, guest PC 0x0c0cbc34 */
if(!s->budget--) { s->failed_pc=0x0c0cbc34u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c0cbc36;
P_0c0cbc36: /* original 2fb6, guest PC 0x0c0cbc36 */
if(!s->budget--) { s->failed_pc=0x0c0cbc36u; return 0; }
r[15]-=4; write(ram,r[15],r[11],4);
goto P_0c0cbc38;
P_0c0cbc38: /* original 2f46, guest PC 0x0c0cbc38 */
if(!s->budget--) { s->failed_pc=0x0c0cbc38u; return 0; }
r[15]-=4; write(ram,r[15],r[4],4);
goto P_0c0cbc3a;
P_0c0cbc3a: /* original 66f3, guest PC 0x0c0cbc3a */
if(!s->budget--) { s->failed_pc=0x0c0cbc3au; return 0; }
r[6]=r[15];
goto P_0c0cbc3c;
P_0c0cbc3c: /* original 67f3, guest PC 0x0c0cbc3c */
if(!s->budget--) { s->failed_pc=0x0c0cbc3cu; return 0; }
r[7]=r[15];
goto P_0c0cbc3e;
P_0c0cbc3e: /* original 761c, guest PC 0x0c0cbc3e */
if(!s->budget--) { s->failed_pc=0x0c0cbc3eu; return 0; }
r[6]+=0x0000001cu;
goto P_0c0cbc40;
P_0c0cbc40: /* original f4fc, guest PC 0x0c0cbc40 */
if(!s->budget--) { s->failed_pc=0x0c0cbc40u; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c0cbc42;
P_0c0cbc42: /* original 7710, guest PC 0x0c0cbc42 */
if(!s->budget--) { s->failed_pc=0x0c0cbc42u; return 0; }
r[7]+=0x00000010u;
goto P_0c0cbc44;
P_0c0cbc44: /* original bec8, guest PC 0x0c0cbc44 */
if(!s->budget--) { s->failed_pc=0x0c0cbc44u; return 0; }
target=0x0c0cb9d8u; r[16]=0x0c0cbc48u;
r[4]=r[12];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0cbc48u) { target=s->pc; goto dispatch; }
goto P_0c0cbc48;
P_0c0cbc46: /* original 64c3, guest PC 0x0c0cbc46 */
if(!s->budget--) { s->failed_pc=0x0c0cbc46u; return 0; }
r[4]=r[12];
goto P_0c0cbc48;
P_0c0cbc48: /* original 9044, guest PC 0x0c0cbc48 */
if(!s->budget--) { s->failed_pc=0x0c0cbc48u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0cbcd4u,2);
goto P_0c0cbc4a;
P_0c0cbc4a: /* original 7e20, guest PC 0x0c0cbc4a */
if(!s->budget--) { s->failed_pc=0x0c0cbc4au; return 0; }
r[14]+=0x00000020u;
goto P_0c0cbc4c;
P_0c0cbc4c: /* original f3d6, guest PC 0x0c0cbc4c */
if(!s->budget--) { s->failed_pc=0x0c0cbc4cu; return 0; }
vf3_matrix_load(s,ram,3,r[13]+r[0]);
goto P_0c0cbc4e;
P_0c0cbc4e: /* original e01c, guest PC 0x0c0cbc4e */
if(!s->budget--) { s->failed_pc=0x0c0cbc4eu; return 0; }
r[0]=0x0000001cu;
goto P_0c0cbc50;
P_0c0cbc50: /* original ff37, guest PC 0x0c0cbc50 */
if(!s->budget--) { s->failed_pc=0x0c0cbc50u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0cbc52;
P_0c0cbc52: /* original 9040, guest PC 0x0c0cbc52 */
if(!s->budget--) { s->failed_pc=0x0c0cbc52u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0cbcd6u,2);
goto P_0c0cbc54;
P_0c0cbc54: /* original f3d6, guest PC 0x0c0cbc54 */
if(!s->budget--) { s->failed_pc=0x0c0cbc54u; return 0; }
vf3_matrix_load(s,ram,3,r[13]+r[0]);
goto P_0c0cbc56;
P_0c0cbc56: /* original e020, guest PC 0x0c0cbc56 */
if(!s->budget--) { s->failed_pc=0x0c0cbc56u; return 0; }
r[0]=0x00000020u;
goto P_0c0cbc58;
P_0c0cbc58: /* original ff37, guest PC 0x0c0cbc58 */
if(!s->budget--) { s->failed_pc=0x0c0cbc58u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0cbc5a;
P_0c0cbc5a: /* original 903d, guest PC 0x0c0cbc5a */
if(!s->budget--) { s->failed_pc=0x0c0cbc5au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0cbcd8u,2);
goto P_0c0cbc5c;
P_0c0cbc5c: /* original f3d6, guest PC 0x0c0cbc5c */
if(!s->budget--) { s->failed_pc=0x0c0cbc5cu; return 0; }
vf3_matrix_load(s,ram,3,r[13]+r[0]);
goto P_0c0cbc5e;
P_0c0cbc5e: /* original e024, guest PC 0x0c0cbc5e */
if(!s->budget--) { s->failed_pc=0x0c0cbc5eu; return 0; }
r[0]=0x00000024u;
goto P_0c0cbc60;
P_0c0cbc60: /* original f34d, guest PC 0x0c0cbc60 */
if(!s->budget--) { s->failed_pc=0x0c0cbc60u; return 0; }
fr[3]^=0x80000000u;
goto P_0c0cbc62;
P_0c0cbc62: /* original ff37, guest PC 0x0c0cbc62 */
if(!s->budget--) { s->failed_pc=0x0c0cbc62u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0cbc64;
P_0c0cbc64: /* original e020, guest PC 0x0c0cbc64 */
if(!s->budget--) { s->failed_pc=0x0c0cbc64u; return 0; }
r[0]=0x00000020u;
goto P_0c0cbc66;
P_0c0cbc66: /* original f3f6, guest PC 0x0c0cbc66 */
if(!s->budget--) { s->failed_pc=0x0c0cbc66u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0cbc68;
P_0c0cbc68: /* original e020, guest PC 0x0c0cbc68 */
if(!s->budget--) { s->failed_pc=0x0c0cbc68u; return 0; }
r[0]=0x00000020u;
goto P_0c0cbc6a;
P_0c0cbc6a: /* original f4ec, guest PC 0x0c0cbc6a */
if(!s->budget--) { s->failed_pc=0x0c0cbc6au; return 0; }
vf3_matrix_move(s,4,14);
goto P_0c0cbc6c;
P_0c0cbc6c: /* original f340, guest PC 0x0c0cbc6c */
if(!s->budget--) { s->failed_pc=0x0c0cbc6cu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'+');
goto P_0c0cbc6e;
P_0c0cbc6e: /* original ff37, guest PC 0x0c0cbc6e */
if(!s->budget--) { s->failed_pc=0x0c0cbc6eu; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0cbc70;
P_0c0cbc70: /* original e004, guest PC 0x0c0cbc70 */
if(!s->budget--) { s->failed_pc=0x0c0cbc70u; return 0; }
r[0]=0x00000004u;
goto P_0c0cbc72;
P_0c0cbc72: /* original f3e6, guest PC 0x0c0cbc72 */
if(!s->budget--) { s->failed_pc=0x0c0cbc72u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c0cbc74;
P_0c0cbc74: /* original e010, guest PC 0x0c0cbc74 */
if(!s->budget--) { s->failed_pc=0x0c0cbc74u; return 0; }
r[0]=0x00000010u;
goto P_0c0cbc76;
P_0c0cbc76: /* original ff37, guest PC 0x0c0cbc76 */
if(!s->budget--) { s->failed_pc=0x0c0cbc76u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0cbc78;
P_0c0cbc78: /* original e008, guest PC 0x0c0cbc78 */
if(!s->budget--) { s->failed_pc=0x0c0cbc78u; return 0; }
r[0]=0x00000008u;
goto P_0c0cbc7a;
P_0c0cbc7a: /* original f3e6, guest PC 0x0c0cbc7a */
if(!s->budget--) { s->failed_pc=0x0c0cbc7au; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c0cbc7c;
P_0c0cbc7c: /* original e014, guest PC 0x0c0cbc7c */
if(!s->budget--) { s->failed_pc=0x0c0cbc7cu; return 0; }
r[0]=0x00000014u;
goto P_0c0cbc7e;
P_0c0cbc7e: /* original ff37, guest PC 0x0c0cbc7e */
if(!s->budget--) { s->failed_pc=0x0c0cbc7eu; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0cbc80;
P_0c0cbc80: /* original e00c, guest PC 0x0c0cbc80 */
if(!s->budget--) { s->failed_pc=0x0c0cbc80u; return 0; }
r[0]=0x0000000cu;
goto P_0c0cbc82;
P_0c0cbc82: /* original f3e6, guest PC 0x0c0cbc82 */
if(!s->budget--) { s->failed_pc=0x0c0cbc82u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c0cbc84;
P_0c0cbc84: /* original e018, guest PC 0x0c0cbc84 */
if(!s->budget--) { s->failed_pc=0x0c0cbc84u; return 0; }
r[0]=0x00000018u;
goto P_0c0cbc86;
P_0c0cbc86: /* original ff37, guest PC 0x0c0cbc86 */
if(!s->budget--) { s->failed_pc=0x0c0cbc86u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0cbc88;
P_0c0cbc88: /* original e01c, guest PC 0x0c0cbc88 */
if(!s->budget--) { s->failed_pc=0x0c0cbc88u; return 0; }
r[0]=0x0000001cu;
goto P_0c0cbc8a;
P_0c0cbc8a: /* original 65e3, guest PC 0x0c0cbc8a */
if(!s->budget--) { s->failed_pc=0x0c0cbc8au; return 0; }
r[5]=r[14];
goto P_0c0cbc8c;
P_0c0cbc8c: /* original f3f6, guest PC 0x0c0cbc8c */
if(!s->budget--) { s->failed_pc=0x0c0cbc8cu; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0cbc8e;
P_0c0cbc8e: /* original e004, guest PC 0x0c0cbc8e */
if(!s->budget--) { s->failed_pc=0x0c0cbc8eu; return 0; }
r[0]=0x00000004u;
goto P_0c0cbc90;
P_0c0cbc90: /* original e408, guest PC 0x0c0cbc90 */
if(!s->budget--) { s->failed_pc=0x0c0cbc90u; return 0; }
r[4]=0x00000008u;
goto P_0c0cbc92;
P_0c0cbc92: /* original fe37, guest PC 0x0c0cbc92 */
if(!s->budget--) { s->failed_pc=0x0c0cbc92u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c0cbc94;
P_0c0cbc94: /* original e020, guest PC 0x0c0cbc94 */
if(!s->budget--) { s->failed_pc=0x0c0cbc94u; return 0; }
r[0]=0x00000020u;
goto P_0c0cbc96;
P_0c0cbc96: /* original f3f6, guest PC 0x0c0cbc96 */
if(!s->budget--) { s->failed_pc=0x0c0cbc96u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0cbc98;
P_0c0cbc98: /* original e008, guest PC 0x0c0cbc98 */
if(!s->budget--) { s->failed_pc=0x0c0cbc98u; return 0; }
r[0]=0x00000008u;
goto P_0c0cbc9a;
P_0c0cbc9a: /* original fe37, guest PC 0x0c0cbc9a */
if(!s->budget--) { s->failed_pc=0x0c0cbc9au; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c0cbc9c;
P_0c0cbc9c: /* original e024, guest PC 0x0c0cbc9c */
if(!s->budget--) { s->failed_pc=0x0c0cbc9cu; return 0; }
r[0]=0x00000024u;
goto P_0c0cbc9e;
P_0c0cbc9e: /* original f3f6, guest PC 0x0c0cbc9e */
if(!s->budget--) { s->failed_pc=0x0c0cbc9eu; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0cbca0;
P_0c0cbca0: /* original e00c, guest PC 0x0c0cbca0 */
if(!s->budget--) { s->failed_pc=0x0c0cbca0u; return 0; }
r[0]=0x0000000cu;
goto P_0c0cbca2;
P_0c0cbca2: /* original fe37, guest PC 0x0c0cbca2 */
if(!s->budget--) { s->failed_pc=0x0c0cbca2u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c0cbca4;
P_0c0cbca4: /* original 2fb6, guest PC 0x0c0cbca4 */
if(!s->budget--) { s->failed_pc=0x0c0cbca4u; return 0; }
r[15]-=4; write(ram,r[15],r[11],4);
goto P_0c0cbca6;
P_0c0cbca6: /* original 2f46, guest PC 0x0c0cbca6 */
if(!s->budget--) { s->failed_pc=0x0c0cbca6u; return 0; }
r[15]-=4; write(ram,r[15],r[4],4);
goto P_0c0cbca8;
P_0c0cbca8: /* original 66f3, guest PC 0x0c0cbca8 */
if(!s->budget--) { s->failed_pc=0x0c0cbca8u; return 0; }
r[6]=r[15];
goto P_0c0cbcaa;
P_0c0cbcaa: /* original 67f3, guest PC 0x0c0cbcaa */
if(!s->budget--) { s->failed_pc=0x0c0cbcaau; return 0; }
r[7]=r[15];
goto P_0c0cbcac;
P_0c0cbcac: /* original 7624, guest PC 0x0c0cbcac */
if(!s->budget--) { s->failed_pc=0x0c0cbcacu; return 0; }
r[6]+=0x00000024u;
goto P_0c0cbcae;
P_0c0cbcae: /* original f4fc, guest PC 0x0c0cbcae */
if(!s->budget--) { s->failed_pc=0x0c0cbcaeu; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c0cbcb0;
P_0c0cbcb0: /* original 7718, guest PC 0x0c0cbcb0 */
if(!s->budget--) { s->failed_pc=0x0c0cbcb0u; return 0; }
r[7]+=0x00000018u;
goto P_0c0cbcb2;
P_0c0cbcb2: /* original be91, guest PC 0x0c0cbcb2 */
if(!s->budget--) { s->failed_pc=0x0c0cbcb2u; return 0; }
target=0x0c0cb9d8u; r[16]=0x0c0cbcb6u;
r[4]=r[12];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0cbcb6u) { target=s->pc; goto dispatch; }
goto P_0c0cbcb6;
P_0c0cbcb4: /* original 64c3, guest PC 0x0c0cbcb4 */
if(!s->budget--) { s->failed_pc=0x0c0cbcb4u; return 0; }
r[4]=r[12];
goto P_0c0cbcb6;
P_0c0cbcb6: /* original 7f30, guest PC 0x0c0cbcb6 */
if(!s->budget--) { s->failed_pc=0x0c0cbcb6u; return 0; }
r[15]+=0x00000030u;
goto P_0c0cbcb8;
P_0c0cbcb8: /* original 4f26, guest PC 0x0c0cbcb8 */
if(!s->budget--) { s->failed_pc=0x0c0cbcb8u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0cbcba;
P_0c0cbcba: /* original fef9, guest PC 0x0c0cbcba */
if(!s->budget--) { s->failed_pc=0x0c0cbcbau; return 0; }
vf3_matrix_load(s,ram,14,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0cbcbc;
P_0c0cbcbc: /* original fff9, guest PC 0x0c0cbcbc */
if(!s->budget--) { s->failed_pc=0x0c0cbcbcu; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0cbcbe;
P_0c0cbcbe: /* original 6bf6, guest PC 0x0c0cbcbe */
if(!s->budget--) { s->failed_pc=0x0c0cbcbeu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0cbcc0;
P_0c0cbcc0: /* original 6cf6, guest PC 0x0c0cbcc0 */
if(!s->budget--) { s->failed_pc=0x0c0cbcc0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0cbcc2;
P_0c0cbcc2: /* original 6df6, guest PC 0x0c0cbcc2 */
if(!s->budget--) { s->failed_pc=0x0c0cbcc2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0cbcc4;
P_0c0cbcc4: /* original 000b, guest PC 0x0c0cbcc4 */
if(!s->budget--) { s->failed_pc=0x0c0cbcc4u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0cbcc6: /* original 6ef6, guest PC 0x0c0cbcc6 */
if(!s->budget--) { s->failed_pc=0x0c0cbcc6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0cbcc8u,s,ram);
P_0c0cbdcc: /* original 2fe6, guest PC 0x0c0cbdcc */
if(!s->budget--) { s->failed_pc=0x0c0cbdccu; return 0; }
r[15]-=4; write(ram,r[15],r[14],4);
goto P_0c0cbdce;
P_0c0cbdce: /* original e018, guest PC 0x0c0cbdce */
if(!s->budget--) { s->failed_pc=0x0c0cbdceu; return 0; }
r[0]=0x00000018u;
goto P_0c0cbdd0;
P_0c0cbdd0: /* original 4f22, guest PC 0x0c0cbdd0 */
if(!s->budget--) { s->failed_pc=0x0c0cbdd0u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0cbdd2;
P_0c0cbdd2: /* original e300, guest PC 0x0c0cbdd2 */
if(!s->budget--) { s->failed_pc=0x0c0cbdd2u; return 0; }
r[3]=0x00000000u;
goto P_0c0cbdd4;
P_0c0cbdd4: /* original 6233, guest PC 0x0c0cbdd4 */
if(!s->budget--) { s->failed_pc=0x0c0cbdd4u; return 0; }
r[2]=r[3];
goto P_0c0cbdd6;
P_0c0cbdd6: /* original 5ef2, guest PC 0x0c0cbdd6 */
if(!s->budget--) { s->failed_pc=0x0c0cbdd6u; return 0; }
r[14]=read(ram,r[15]+8,4);
goto P_0c0cbdd8;
P_0c0cbdd8: /* original 1e34, guest PC 0x0c0cbdd8 */
if(!s->budget--) { s->failed_pc=0x0c0cbdd8u; return 0; }
write(ram,r[14]+16,r[3],4);
goto P_0c0cbdda;
P_0c0cbdda: /* original 1e33, guest PC 0x0c0cbdda */
if(!s->budget--) { s->failed_pc=0x0c0cbddau; return 0; }
write(ram,r[14]+12,r[3],4);
goto P_0c0cbddc;
P_0c0cbddc: /* original f378, guest PC 0x0c0cbddc */
if(!s->budget--) { s->failed_pc=0x0c0cbddcu; return 0; }
vf3_matrix_load(s,ram,3,r[7]);
goto P_0c0cbdde;
P_0c0cbdde: /* original f268, guest PC 0x0c0cbdde */
if(!s->budget--) { s->failed_pc=0x0c0cbddeu; return 0; }
vf3_matrix_load(s,ram,2,r[6]);
goto P_0c0cbde0;
P_0c0cbde0: /* original f231, guest PC 0x0c0cbde0 */
if(!s->budget--) { s->failed_pc=0x0c0cbde0u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'-');
goto P_0c0cbde2;
P_0c0cbde2: /* original fe27, guest PC 0x0c0cbde2 */
if(!s->budget--) { s->failed_pc=0x0c0cbde2u; return 0; }
vf3_matrix_store(s,ram,2,r[14]+r[0]);
goto P_0c0cbde4;
P_0c0cbde4: /* original e004, guest PC 0x0c0cbde4 */
if(!s->budget--) { s->failed_pc=0x0c0cbde4u; return 0; }
r[0]=0x00000004u;
goto P_0c0cbde6;
P_0c0cbde6: /* original f276, guest PC 0x0c0cbde6 */
if(!s->budget--) { s->failed_pc=0x0c0cbde6u; return 0; }
vf3_matrix_load(s,ram,2,r[7]+r[0]);
goto P_0c0cbde8;
P_0c0cbde8: /* original f366, guest PC 0x0c0cbde8 */
if(!s->budget--) { s->failed_pc=0x0c0cbde8u; return 0; }
vf3_matrix_load(s,ram,3,r[6]+r[0]);
goto P_0c0cbdea;
P_0c0cbdea: /* original e01c, guest PC 0x0c0cbdea */
if(!s->budget--) { s->failed_pc=0x0c0cbdeau; return 0; }
r[0]=0x0000001cu;
goto P_0c0cbdec;
P_0c0cbdec: /* original f231, guest PC 0x0c0cbdec */
if(!s->budget--) { s->failed_pc=0x0c0cbdecu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'-');
goto P_0c0cbdee;
P_0c0cbdee: /* original fe27, guest PC 0x0c0cbdee */
if(!s->budget--) { s->failed_pc=0x0c0cbdeeu; return 0; }
vf3_matrix_store(s,ram,2,r[14]+r[0]);
goto P_0c0cbdf0;
P_0c0cbdf0: /* original e008, guest PC 0x0c0cbdf0 */
if(!s->budget--) { s->failed_pc=0x0c0cbdf0u; return 0; }
r[0]=0x00000008u;
goto P_0c0cbdf2;
P_0c0cbdf2: /* original f266, guest PC 0x0c0cbdf2 */
if(!s->budget--) { s->failed_pc=0x0c0cbdf2u; return 0; }
vf3_matrix_load(s,ram,2,r[6]+r[0]);
goto P_0c0cbdf4;
P_0c0cbdf4: /* original f376, guest PC 0x0c0cbdf4 */
if(!s->budget--) { s->failed_pc=0x0c0cbdf4u; return 0; }
vf3_matrix_load(s,ram,3,r[7]+r[0]);
goto P_0c0cbdf6;
P_0c0cbdf6: /* original e020, guest PC 0x0c0cbdf6 */
if(!s->budget--) { s->failed_pc=0x0c0cbdf6u; return 0; }
r[0]=0x00000020u;
goto P_0c0cbdf8;
P_0c0cbdf8: /* original f231, guest PC 0x0c0cbdf8 */
if(!s->budget--) { s->failed_pc=0x0c0cbdf8u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'-');
goto P_0c0cbdfa;
P_0c0cbdfa: /* original fe27, guest PC 0x0c0cbdfa */
if(!s->budget--) { s->failed_pc=0x0c0cbdfau; return 0; }
vf3_matrix_store(s,ram,2,r[14]+r[0]);
goto P_0c0cbdfc;
P_0c0cbdfc: /* original e018, guest PC 0x0c0cbdfc */
if(!s->budget--) { s->failed_pc=0x0c0cbdfcu; return 0; }
r[0]=0x00000018u;
goto P_0c0cbdfe;
P_0c0cbdfe: /* original f4e6, guest PC 0x0c0cbdfe */
if(!s->budget--) { s->failed_pc=0x0c0cbdfeu; return 0; }
vf3_matrix_load(s,ram,4,r[14]+r[0]);
goto P_0c0cbe00;
P_0c0cbe00: /* original e020, guest PC 0x0c0cbe00 */
if(!s->budget--) { s->failed_pc=0x0c0cbe00u; return 0; }
r[0]=0x00000020u;
goto P_0c0cbe02;
P_0c0cbe02: /* original f54c, guest PC 0x0c0cbe02 */
if(!s->budget--) { s->failed_pc=0x0c0cbe02u; return 0; }
vf3_matrix_move(s,5,4);
goto P_0c0cbe04;
P_0c0cbe04: /* original f542, guest PC 0x0c0cbe04 */
if(!s->budget--) { s->failed_pc=0x0c0cbe04u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[4],r[18],'*');
goto P_0c0cbe06;
P_0c0cbe06: /* original f4e6, guest PC 0x0c0cbe06 */
if(!s->budget--) { s->failed_pc=0x0c0cbe06u; return 0; }
vf3_matrix_load(s,ram,4,r[14]+r[0]);
goto P_0c0cbe08;
P_0c0cbe08: /* original f04c, guest PC 0x0c0cbe08 */
if(!s->budget--) { s->failed_pc=0x0c0cbe08u; return 0; }
vf3_matrix_move(s,0,4);
goto P_0c0cbe0a;
P_0c0cbe0a: /* original f54e, guest PC 0x0c0cbe0a */
if(!s->budget--) { s->failed_pc=0x0c0cbe0au; return 0; }
fr[5]=vf3_fpu_mac(fr[0],fr[4],fr[5],r[18]);
goto P_0c0cbe0c;
P_0c0cbe0c: /* original e01c, guest PC 0x0c0cbe0c */
if(!s->budget--) { s->failed_pc=0x0c0cbe0cu; return 0; }
r[0]=0x0000001cu;
goto P_0c0cbe0e;
P_0c0cbe0e: /* original f45c, guest PC 0x0c0cbe0e */
if(!s->budget--) { s->failed_pc=0x0c0cbe0eu; return 0; }
vf3_matrix_move(s,4,5);
goto P_0c0cbe10;
P_0c0cbe10: /* original f5e6, guest PC 0x0c0cbe10 */
if(!s->budget--) { s->failed_pc=0x0c0cbe10u; return 0; }
vf3_matrix_load(s,ram,5,r[14]+r[0]);
goto P_0c0cbe12;
P_0c0cbe12: /* original c782, guest PC 0x0c0cbe12 */
if(!s->budget--) { s->failed_pc=0x0c0cbe12u; return 0; }
r[0]=0x0c0cc01cu;
goto P_0c0cbe14;
P_0c0cbe14: /* original f34c, guest PC 0x0c0cbe14 */
if(!s->budget--) { s->failed_pc=0x0c0cbe14u; return 0; }
vf3_matrix_move(s,3,4);
goto P_0c0cbe16;
P_0c0cbe16: /* original f05c, guest PC 0x0c0cbe16 */
if(!s->budget--) { s->failed_pc=0x0c0cbe16u; return 0; }
vf3_matrix_move(s,0,5);
goto P_0c0cbe18;
P_0c0cbe18: /* original f35e, guest PC 0x0c0cbe18 */
if(!s->budget--) { s->failed_pc=0x0c0cbe18u; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[5],fr[3],r[18]);
goto P_0c0cbe1a;
P_0c0cbe1a: /* original f708, guest PC 0x0c0cbe1a */
if(!s->budget--) { s->failed_pc=0x0c0cbe1au; return 0; }
vf3_matrix_load(s,ram,7,r[0]);
goto P_0c0cbe1c;
P_0c0cbe1c: /* original f53c, guest PC 0x0c0cbe1c */
if(!s->budget--) { s->failed_pc=0x0c0cbe1cu; return 0; }
vf3_matrix_move(s,5,3);
goto P_0c0cbe1e;
P_0c0cbe1e: /* original f755, guest PC 0x0c0cbe1e */
if(!s->budget--) { s->failed_pc=0x0c0cbe1eu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[7])>as_float(fr[5]))!=0);
goto P_0c0cbe20;
P_0c0cbe20: /* original 8b01, guest PC 0x0c0cbe20 */
if(!s->budget--) { s->failed_pc=0x0c0cbe20u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0cbe26; }
goto P_0c0cbe22;
P_0c0cbe22: /* original a002, guest PC 0x0c0cbe22 */
if(!s->budget--) { s->failed_pc=0x0c0cbe22u; return 0; }
fr[6]=0;
goto P_0c0cbe2a;
P_0c0cbe24: /* original f68d, guest PC 0x0c0cbe24 */
if(!s->budget--) { s->failed_pc=0x0c0cbe24u; return 0; }
fr[6]=0;
goto P_0c0cbe26;
P_0c0cbe26: /* original f65c, guest PC 0x0c0cbe26 */
if(!s->budget--) { s->failed_pc=0x0c0cbe26u; return 0; }
vf3_matrix_move(s,6,5);
goto P_0c0cbe28;
P_0c0cbe28: /* original f67d, guest PC 0x0c0cbe28 */
if(!s->budget--) { s->failed_pc=0x0c0cbe28u; return 0; }
if(!vf3_fpu_fsrra(fr[6],r[18],&fr[6])) goto unsupported;
goto P_0c0cbe2a;
P_0c0cbe2a: /* original f745, guest PC 0x0c0cbe2a */
if(!s->budget--) { s->failed_pc=0x0c0cbe2au; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[7])>as_float(fr[4]))!=0);
goto P_0c0cbe2c;
P_0c0cbe2c: /* original 8b01, guest PC 0x0c0cbe2c */
if(!s->budget--) { s->failed_pc=0x0c0cbe2cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0cbe32; }
goto P_0c0cbe2e;
P_0c0cbe2e: /* original a002, guest PC 0x0c0cbe2e */
if(!s->budget--) { s->failed_pc=0x0c0cbe2eu; return 0; }
fr[5]=0;
goto P_0c0cbe36;
P_0c0cbe30: /* original f58d, guest PC 0x0c0cbe30 */
if(!s->budget--) { s->failed_pc=0x0c0cbe30u; return 0; }
fr[5]=0;
goto P_0c0cbe32;
P_0c0cbe32: /* original f54c, guest PC 0x0c0cbe32 */
if(!s->budget--) { s->failed_pc=0x0c0cbe32u; return 0; }
vf3_matrix_move(s,5,4);
goto P_0c0cbe34;
P_0c0cbe34: /* original f57d, guest PC 0x0c0cbe34 */
if(!s->budget--) { s->failed_pc=0x0c0cbe34u; return 0; }
if(!vf3_fpu_fsrra(fr[5],r[18],&fr[5])) goto unsupported;
goto P_0c0cbe36;
P_0c0cbe36: /* original f49d, guest PC 0x0c0cbe36 */
if(!s->budget--) { s->failed_pc=0x0c0cbe36u; return 0; }
fr[4]=0x3f800000u;
goto P_0c0cbe38;
P_0c0cbe38: /* original f463, guest PC 0x0c0cbe38 */
if(!s->budget--) { s->failed_pc=0x0c0cbe38u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[6],r[18],'/');
goto P_0c0cbe3a;
P_0c0cbe3a: /* original c779, guest PC 0x0c0cbe3a */
if(!s->budget--) { s->failed_pc=0x0c0cbe3au; return 0; }
r[0]=0x0c0cc020u;
goto P_0c0cbe3c;
P_0c0cbe3c: /* original f708, guest PC 0x0c0cbe3c */
if(!s->budget--) { s->failed_pc=0x0c0cbe3cu; return 0; }
vf3_matrix_load(s,ram,7,r[0]);
goto P_0c0cbe3e;
P_0c0cbe3e: /* original c779, guest PC 0x0c0cbe3e */
if(!s->budget--) { s->failed_pc=0x0c0cbe3eu; return 0; }
r[0]=0x0c0cc024u;
goto P_0c0cbe40;
P_0c0cbe40: /* original f475, guest PC 0x0c0cbe40 */
if(!s->budget--) { s->failed_pc=0x0c0cbe40u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[4])>as_float(fr[7]))!=0);
goto P_0c0cbe42;
P_0c0cbe42: /* original 8f4a, guest PC 0x0c0cbe42 */
if(!s->budget--) { s->failed_pc=0x0c0cbe42u; return 0; }
cond=r[17]&1u;
vf3_matrix_load(s,ram,6,r[0]);
if(!cond) { goto P_0c0cbeda; }
goto P_0c0cbe46;
P_0c0cbe44: /* original f608, guest PC 0x0c0cbe44 */
if(!s->budget--) { s->failed_pc=0x0c0cbe44u; return 0; }
vf3_matrix_load(s,ram,6,r[0]);
goto P_0c0cbe46;
P_0c0cbe46: /* original f465, guest PC 0x0c0cbe46 */
if(!s->budget--) { s->failed_pc=0x0c0cbe46u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[4])>as_float(fr[6]))!=0);
goto P_0c0cbe48;
P_0c0cbe48: /* original 8b00, guest PC 0x0c0cbe48 */
if(!s->budget--) { s->failed_pc=0x0c0cbe48u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0cbe4c; }
goto P_0c0cbe4a;
P_0c0cbe4a: /* original f46c, guest PC 0x0c0cbe4a */
if(!s->budget--) { s->failed_pc=0x0c0cbe4au; return 0; }
vf3_matrix_move(s,4,6);
goto P_0c0cbe4c;
P_0c0cbe4c: /* original 50e2, guest PC 0x0c0cbe4c */
if(!s->budget--) { s->failed_pc=0x0c0cbe4cu; return 0; }
r[0]=read(ram,r[14]+8,4);
goto P_0c0cbe4e;
P_0c0cbe4e: /* original d776, guest PC 0x0c0cbe4e */
if(!s->budget--) { s->failed_pc=0x0c0cbe4eu; return 0; }
r[7]=read(ram,0x0c0cc028u,4);
goto P_0c0cbe50;
P_0c0cbe50: /* original c802, guest PC 0x0c0cbe50 */
if(!s->budget--) { s->failed_pc=0x0c0cbe50u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&2u)==0)!=0);
goto P_0c0cbe52;
P_0c0cbe52: /* original 8b10, guest PC 0x0c0cbe52 */
if(!s->budget--) { s->failed_pc=0x0c0cbe52u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0cbe76; }
goto P_0c0cbe54;
P_0c0cbe54: /* original e018, guest PC 0x0c0cbe54 */
if(!s->budget--) { s->failed_pc=0x0c0cbe54u; return 0; }
r[0]=0x00000018u;
goto P_0c0cbe56;
P_0c0cbe56: /* original f746, guest PC 0x0c0cbe56 */
if(!s->budget--) { s->failed_pc=0x0c0cbe56u; return 0; }
vf3_matrix_load(s,ram,7,r[4]+r[0]);
goto P_0c0cbe58;
P_0c0cbe58: /* original c774, guest PC 0x0c0cbe58 */
if(!s->budget--) { s->failed_pc=0x0c0cbe58u; return 0; }
r[0]=0x0c0cc02cu;
goto P_0c0cbe5a;
P_0c0cbe5a: /* original f608, guest PC 0x0c0cbe5a */
if(!s->budget--) { s->failed_pc=0x0c0cbe5au; return 0; }
vf3_matrix_load(s,ram,6,r[0]);
goto P_0c0cbe5c;
P_0c0cbe5c: /* original e018, guest PC 0x0c0cbe5c */
if(!s->budget--) { s->failed_pc=0x0c0cbe5cu; return 0; }
r[0]=0x00000018u;
goto P_0c0cbe5e;
P_0c0cbe5e: /* original f3e6, guest PC 0x0c0cbe5e */
if(!s->budget--) { s->failed_pc=0x0c0cbe5eu; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c0cbe60;
P_0c0cbe60: /* original f362, guest PC 0x0c0cbe60 */
if(!s->budget--) { s->failed_pc=0x0c0cbe60u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[6],r[18],'*');
goto P_0c0cbe62;
P_0c0cbe62: /* original fe37, guest PC 0x0c0cbe62 */
if(!s->budget--) { s->failed_pc=0x0c0cbe62u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c0cbe64;
P_0c0cbe64: /* original e01c, guest PC 0x0c0cbe64 */
if(!s->budget--) { s->failed_pc=0x0c0cbe64u; return 0; }
r[0]=0x0000001cu;
goto P_0c0cbe66;
P_0c0cbe66: /* original f2e6, guest PC 0x0c0cbe66 */
if(!s->budget--) { s->failed_pc=0x0c0cbe66u; return 0; }
vf3_matrix_load(s,ram,2,r[14]+r[0]);
goto P_0c0cbe68;
P_0c0cbe68: /* original f262, guest PC 0x0c0cbe68 */
if(!s->budget--) { s->failed_pc=0x0c0cbe68u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[6],r[18],'*');
goto P_0c0cbe6a;
P_0c0cbe6a: /* original fe27, guest PC 0x0c0cbe6a */
if(!s->budget--) { s->failed_pc=0x0c0cbe6au; return 0; }
vf3_matrix_store(s,ram,2,r[14]+r[0]);
goto P_0c0cbe6c;
P_0c0cbe6c: /* original e020, guest PC 0x0c0cbe6c */
if(!s->budget--) { s->failed_pc=0x0c0cbe6cu; return 0; }
r[0]=0x00000020u;
goto P_0c0cbe6e;
P_0c0cbe6e: /* original f3e6, guest PC 0x0c0cbe6e */
if(!s->budget--) { s->failed_pc=0x0c0cbe6eu; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c0cbe70;
P_0c0cbe70: /* original f362, guest PC 0x0c0cbe70 */
if(!s->budget--) { s->failed_pc=0x0c0cbe70u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[6],r[18],'*');
goto P_0c0cbe72;
P_0c0cbe72: /* original a015, guest PC 0x0c0cbe72 */
if(!s->budget--) { s->failed_pc=0x0c0cbe72u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c0cbea0;
P_0c0cbe74: /* original fe37, guest PC 0x0c0cbe74 */
if(!s->budget--) { s->failed_pc=0x0c0cbe74u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c0cbe76;
P_0c0cbe76: /* original d36e, guest PC 0x0c0cbe76 */
if(!s->budget--) { s->failed_pc=0x0c0cbe76u; return 0; }
r[3]=read(ram,0x0c0cc030u,4);
goto P_0c0cbe78;
P_0c0cbe78: /* original e014, guest PC 0x0c0cbe78 */
if(!s->budget--) { s->failed_pc=0x0c0cbe78u; return 0; }
r[0]=0x00000014u;
goto P_0c0cbe7a;
P_0c0cbe7a: /* original f746, guest PC 0x0c0cbe7a */
if(!s->budget--) { s->failed_pc=0x0c0cbe7au; return 0; }
vf3_matrix_load(s,ram,7,r[4]+r[0]);
goto P_0c0cbe7c;
P_0c0cbe7c: /* original 7718, guest PC 0x0c0cbe7c */
if(!s->budget--) { s->failed_pc=0x0c0cbe7cu; return 0; }
r[7]+=0x00000018u;
goto P_0c0cbe7e;
P_0c0cbe7e: /* original 6632, guest PC 0x0c0cbe7e */
if(!s->budget--) { s->failed_pc=0x0c0cbe7eu; return 0; }
tmp=read(ram,r[3],4);
r[6]=tmp;
goto P_0c0cbe80;
P_0c0cbe80: /* original e210, guest PC 0x0c0cbe80 */
if(!s->budget--) { s->failed_pc=0x0c0cbe80u; return 0; }
r[2]=0x00000010u;
goto P_0c0cbe82;
P_0c0cbe82: /* original 50f3, guest PC 0x0c0cbe82 */
if(!s->budget--) { s->failed_pc=0x0c0cbe82u; return 0; }
r[0]=read(ram,r[15]+12,4);
goto P_0c0cbe84;
P_0c0cbe84: /* original 6462, guest PC 0x0c0cbe84 */
if(!s->budget--) { s->failed_pc=0x0c0cbe84u; return 0; }
tmp=read(ram,r[6],4);
r[4]=tmp;
goto P_0c0cbe86;
P_0c0cbe86: /* original c802, guest PC 0x0c0cbe86 */
if(!s->budget--) { s->failed_pc=0x0c0cbe86u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&2u)==0)!=0);
goto P_0c0cbe88;
P_0c0cbe88: /* original 8d09, guest PC 0x0c0cbe88 */
if(!s->budget--) { s->failed_pc=0x0c0cbe88u; return 0; }
cond=r[17]&1u;
r[4]|=r[2];
if(cond) { goto P_0c0cbe9e; }
goto P_0c0cbe8c;
P_0c0cbe8a: /* original 242b, guest PC 0x0c0cbe8a */
if(!s->budget--) { s->failed_pc=0x0c0cbe8au; return 0; }
r[4]|=r[2];
goto P_0c0cbe8c;
P_0c0cbe8c: /* original d369, guest PC 0x0c0cbe8c */
if(!s->budget--) { s->failed_pc=0x0c0cbe8cu; return 0; }
r[3]=read(ram,0x0c0cc034u,4);
goto P_0c0cbe8e;
P_0c0cbe8e: /* original e01c, guest PC 0x0c0cbe8e */
if(!s->budget--) { s->failed_pc=0x0c0cbe8eu; return 0; }
r[0]=0x0000001cu;
goto P_0c0cbe90;
P_0c0cbe90: /* original f2e6, guest PC 0x0c0cbe90 */
if(!s->budget--) { s->failed_pc=0x0c0cbe90u; return 0; }
vf3_matrix_load(s,ram,2,r[14]+r[0]);
goto P_0c0cbe92;
P_0c0cbe92: /* original e120, guest PC 0x0c0cbe92 */
if(!s->budget--) { s->failed_pc=0x0c0cbe92u; return 0; }
r[1]=0x00000020u;
goto P_0c0cbe94;
P_0c0cbe94: /* original 435a, guest PC 0x0c0cbe94 */
if(!s->budget--) { s->failed_pc=0x0c0cbe94u; return 0; }
r[53]=r[3];
goto P_0c0cbe96;
P_0c0cbe96: /* original 241b, guest PC 0x0c0cbe96 */
if(!s->budget--) { s->failed_pc=0x0c0cbe96u; return 0; }
r[4]|=r[1];
goto P_0c0cbe98;
P_0c0cbe98: /* original f30d, guest PC 0x0c0cbe98 */
if(!s->budget--) { s->failed_pc=0x0c0cbe98u; return 0; }
fr[3]=r[53];
goto P_0c0cbe9a;
P_0c0cbe9a: /* original f232, guest PC 0x0c0cbe9a */
if(!s->budget--) { s->failed_pc=0x0c0cbe9au; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c0cbe9c;
P_0c0cbe9c: /* original fe27, guest PC 0x0c0cbe9c */
if(!s->budget--) { s->failed_pc=0x0c0cbe9cu; return 0; }
vf3_matrix_store(s,ram,2,r[14]+r[0]);
goto P_0c0cbe9e;
P_0c0cbe9e: /* original 2642, guest PC 0x0c0cbe9e */
if(!s->budget--) { s->failed_pc=0x0c0cbe9eu; return 0; }
write(ram,r[6],r[4],4);
goto P_0c0cbea0;
P_0c0cbea0: /* original 64e2, guest PC 0x0c0cbea0 */
if(!s->budget--) { s->failed_pc=0x0c0cbea0u; return 0; }
tmp=read(ram,r[14],4);
r[4]=tmp;
goto P_0c0cbea2;
P_0c0cbea2: /* original e004, guest PC 0x0c0cbea2 */
if(!s->budget--) { s->failed_pc=0x0c0cbea2u; return 0; }
r[0]=0x00000004u;
goto P_0c0cbea4;
P_0c0cbea4: /* original 347c, guest PC 0x0c0cbea4 */
if(!s->budget--) { s->failed_pc=0x0c0cbea4u; return 0; }
r[4]+=r[7];
goto P_0c0cbea6;
P_0c0cbea6: /* original f648, guest PC 0x0c0cbea6 */
if(!s->budget--) { s->failed_pc=0x0c0cbea6u; return 0; }
vf3_matrix_load(s,ram,6,r[4]);
goto P_0c0cbea8;
P_0c0cbea8: /* original f672, guest PC 0x0c0cbea8 */
if(!s->budget--) { s->failed_pc=0x0c0cbea8u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[7],r[18],'*');
goto P_0c0cbeaa;
P_0c0cbeaa: /* original f642, guest PC 0x0c0cbeaa */
if(!s->budget--) { s->failed_pc=0x0c0cbeaau; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[4],r[18],'*');
goto P_0c0cbeac;
P_0c0cbeac: /* original f63d, guest PC 0x0c0cbeac */
if(!s->budget--) { s->failed_pc=0x0c0cbeacu; return 0; }
r[53]=truncate_float(fr[6]);
goto P_0c0cbeae;
P_0c0cbeae: /* original 025a, guest PC 0x0c0cbeae */
if(!s->budget--) { s->failed_pc=0x0c0cbeaeu; return 0; }
r[2]=r[53];
goto P_0c0cbeb0;
P_0c0cbeb0: /* original 1e24, guest PC 0x0c0cbeb0 */
if(!s->budget--) { s->failed_pc=0x0c0cbeb0u; return 0; }
write(ram,r[14]+16,r[2],4);
goto P_0c0cbeb2;
P_0c0cbeb2: /* original f446, guest PC 0x0c0cbeb2 */
if(!s->budget--) { s->failed_pc=0x0c0cbeb2u; return 0; }
vf3_matrix_load(s,ram,4,r[4]+r[0]);
goto P_0c0cbeb4;
P_0c0cbeb4: /* original e024, guest PC 0x0c0cbeb4 */
if(!s->budget--) { s->failed_pc=0x0c0cbeb4u; return 0; }
r[0]=0x00000024u;
goto P_0c0cbeb6;
P_0c0cbeb6: /* original f542, guest PC 0x0c0cbeb6 */
if(!s->budget--) { s->failed_pc=0x0c0cbeb6u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[4],r[18],'*');
goto P_0c0cbeb8;
P_0c0cbeb8: /* original fe57, guest PC 0x0c0cbeb8 */
if(!s->budget--) { s->failed_pc=0x0c0cbeb8u; return 0; }
vf3_matrix_store(s,ram,5,r[14]+r[0]);
goto P_0c0cbeba;
P_0c0cbeba: /* original e018, guest PC 0x0c0cbeba */
if(!s->budget--) { s->failed_pc=0x0c0cbebau; return 0; }
r[0]=0x00000018u;
goto P_0c0cbebc;
P_0c0cbebc: /* original f3e6, guest PC 0x0c0cbebc */
if(!s->budget--) { s->failed_pc=0x0c0cbebcu; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c0cbebe;
P_0c0cbebe: /* original e010, guest PC 0x0c0cbebe */
if(!s->budget--) { s->failed_pc=0x0c0cbebeu; return 0; }
r[0]=0x00000010u;
goto P_0c0cbec0;
P_0c0cbec0: /* original f537, guest PC 0x0c0cbec0 */
if(!s->budget--) { s->failed_pc=0x0c0cbec0u; return 0; }
vf3_matrix_store(s,ram,3,r[5]+r[0]);
goto P_0c0cbec2;
P_0c0cbec2: /* original e01c, guest PC 0x0c0cbec2 */
if(!s->budget--) { s->failed_pc=0x0c0cbec2u; return 0; }
r[0]=0x0000001cu;
goto P_0c0cbec4;
P_0c0cbec4: /* original f3e6, guest PC 0x0c0cbec4 */
if(!s->budget--) { s->failed_pc=0x0c0cbec4u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c0cbec6;
P_0c0cbec6: /* original e014, guest PC 0x0c0cbec6 */
if(!s->budget--) { s->failed_pc=0x0c0cbec6u; return 0; }
r[0]=0x00000014u;
goto P_0c0cbec8;
P_0c0cbec8: /* original f537, guest PC 0x0c0cbec8 */
if(!s->budget--) { s->failed_pc=0x0c0cbec8u; return 0; }
vf3_matrix_store(s,ram,3,r[5]+r[0]);
goto P_0c0cbeca;
P_0c0cbeca: /* original e020, guest PC 0x0c0cbeca */
if(!s->budget--) { s->failed_pc=0x0c0cbecau; return 0; }
r[0]=0x00000020u;
goto P_0c0cbecc;
P_0c0cbecc: /* original f3e6, guest PC 0x0c0cbecc */
if(!s->budget--) { s->failed_pc=0x0c0cbeccu; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c0cbece;
P_0c0cbece: /* original e018, guest PC 0x0c0cbece */
if(!s->budget--) { s->failed_pc=0x0c0cbeceu; return 0; }
r[0]=0x00000018u;
goto P_0c0cbed0;
P_0c0cbed0: /* original f537, guest PC 0x0c0cbed0 */
if(!s->budget--) { s->failed_pc=0x0c0cbed0u; return 0; }
vf3_matrix_store(s,ram,3,r[5]+r[0]);
goto P_0c0cbed2;
P_0c0cbed2: /* original e024, guest PC 0x0c0cbed2 */
if(!s->budget--) { s->failed_pc=0x0c0cbed2u; return 0; }
r[0]=0x00000024u;
goto P_0c0cbed4;
P_0c0cbed4: /* original f3e6, guest PC 0x0c0cbed4 */
if(!s->budget--) { s->failed_pc=0x0c0cbed4u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c0cbed6;
P_0c0cbed6: /* original e01c, guest PC 0x0c0cbed6 */
if(!s->budget--) { s->failed_pc=0x0c0cbed6u; return 0; }
r[0]=0x0000001cu;
goto P_0c0cbed8;
P_0c0cbed8: /* original f537, guest PC 0x0c0cbed8 */
if(!s->budget--) { s->failed_pc=0x0c0cbed8u; return 0; }
vf3_matrix_store(s,ram,3,r[5]+r[0]);
goto P_0c0cbeda;
P_0c0cbeda: /* original d357, guest PC 0x0c0cbeda */
if(!s->budget--) { s->failed_pc=0x0c0cbedau; return 0; }
r[3]=read(ram,0x0c0cc038u,4);
goto P_0c0cbedc;
P_0c0cbedc: /* original e004, guest PC 0x0c0cbedc */
if(!s->budget--) { s->failed_pc=0x0c0cbedcu; return 0; }
r[0]=0x00000004u;
goto P_0c0cbede;
P_0c0cbede: /* original 54e4, guest PC 0x0c0cbede */
if(!s->budget--) { s->failed_pc=0x0c0cbedeu; return 0; }
r[4]=read(ram,r[14]+16,4);
goto P_0c0cbee0;
P_0c0cbee0: /* original 430b, guest PC 0x0c0cbee0 */
if(!s->budget--) { s->failed_pc=0x0c0cbee0u; return 0; }
target=r[3];
r[16]=0x0c0cbee4u;
r[1]=r[4];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0cbee4u) { target=s->pc; goto dispatch; }
goto P_0c0cbee4;
P_0c0cbee2: /* original 6143, guest PC 0x0c0cbee2 */
if(!s->budget--) { s->failed_pc=0x0c0cbee2u; return 0; }
r[1]=r[4];
goto P_0c0cbee4;
P_0c0cbee4: /* original 6303, guest PC 0x0c0cbee4 */
if(!s->budget--) { s->failed_pc=0x0c0cbee4u; return 0; }
r[3]=r[0];
goto P_0c0cbee6;
P_0c0cbee6: /* original 3438, guest PC 0x0c0cbee6 */
if(!s->budget--) { s->failed_pc=0x0c0cbee6u; return 0; }
r[4]-=r[3];
goto P_0c0cbee8;
P_0c0cbee8: /* original 4f26, guest PC 0x0c0cbee8 */
if(!s->budget--) { s->failed_pc=0x0c0cbee8u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0cbeea;
P_0c0cbeea: /* original 1e04, guest PC 0x0c0cbeea */
if(!s->budget--) { s->failed_pc=0x0c0cbeeau; return 0; }
write(ram,r[14]+16,r[0],4);
goto P_0c0cbeec;
P_0c0cbeec: /* original e300, guest PC 0x0c0cbeec */
if(!s->budget--) { s->failed_pc=0x0c0cbeecu; return 0; }
r[3]=0x00000000u;
goto P_0c0cbeee;
P_0c0cbeee: /* original 6043, guest PC 0x0c0cbeee */
if(!s->budget--) { s->failed_pc=0x0c0cbeeeu; return 0; }
r[0]=r[4];
goto P_0c0cbef0;
P_0c0cbef0: /* original 8151, guest PC 0x0c0cbef0 */
if(!s->budget--) { s->failed_pc=0x0c0cbef0u; return 0; }
write(ram,r[5]+2,r[0],2);
goto P_0c0cbef2;
P_0c0cbef2: /* original 1e35, guest PC 0x0c0cbef2 */
if(!s->budget--) { s->failed_pc=0x0c0cbef2u; return 0; }
write(ram,r[14]+20,r[3],4);
goto P_0c0cbef4;
P_0c0cbef4: /* original 000b, guest PC 0x0c0cbef4 */
if(!s->budget--) { s->failed_pc=0x0c0cbef4u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0cbef6: /* original 6ef6, guest PC 0x0c0cbef6 */
if(!s->budget--) { s->failed_pc=0x0c0cbef6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0cbef8;
P_0c0cbef8: /* original 2fe6, guest PC 0x0c0cbef8 */
if(!s->budget--) { s->failed_pc=0x0c0cbef8u; return 0; }
r[15]-=4; write(ram,r[15],r[14],4);
goto P_0c0cbefa;
P_0c0cbefa: /* original e010, guest PC 0x0c0cbefa */
if(!s->budget--) { s->failed_pc=0x0c0cbefau; return 0; }
r[0]=0x00000010u;
goto P_0c0cbefc;
P_0c0cbefc: /* original 4f22, guest PC 0x0c0cbefc */
if(!s->budget--) { s->failed_pc=0x0c0cbefcu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0cbefe;
P_0c0cbefe: /* original f356, guest PC 0x0c0cbefe */
if(!s->budget--) { s->failed_pc=0x0c0cbefeu; return 0; }
vf3_matrix_load(s,ram,3,r[5]+r[0]);
goto P_0c0cbf00;
P_0c0cbf00: /* original e018, guest PC 0x0c0cbf00 */
if(!s->budget--) { s->failed_pc=0x0c0cbf00u; return 0; }
r[0]=0x00000018u;
goto P_0c0cbf02;
P_0c0cbf02: /* original 54f2, guest PC 0x0c0cbf02 */
if(!s->budget--) { s->failed_pc=0x0c0cbf02u; return 0; }
r[4]=read(ram,r[15]+8,4);
goto P_0c0cbf04;
P_0c0cbf04: /* original f437, guest PC 0x0c0cbf04 */
if(!s->budget--) { s->failed_pc=0x0c0cbf04u; return 0; }
vf3_matrix_store(s,ram,3,r[4]+r[0]);
goto P_0c0cbf06;
P_0c0cbf06: /* original e014, guest PC 0x0c0cbf06 */
if(!s->budget--) { s->failed_pc=0x0c0cbf06u; return 0; }
r[0]=0x00000014u;
goto P_0c0cbf08;
P_0c0cbf08: /* original f356, guest PC 0x0c0cbf08 */
if(!s->budget--) { s->failed_pc=0x0c0cbf08u; return 0; }
vf3_matrix_load(s,ram,3,r[5]+r[0]);
goto P_0c0cbf0a;
P_0c0cbf0a: /* original e01c, guest PC 0x0c0cbf0a */
if(!s->budget--) { s->failed_pc=0x0c0cbf0au; return 0; }
r[0]=0x0000001cu;
goto P_0c0cbf0c;
P_0c0cbf0c: /* original f437, guest PC 0x0c0cbf0c */
if(!s->budget--) { s->failed_pc=0x0c0cbf0cu; return 0; }
vf3_matrix_store(s,ram,3,r[4]+r[0]);
goto P_0c0cbf0e;
P_0c0cbf0e: /* original e018, guest PC 0x0c0cbf0e */
if(!s->budget--) { s->failed_pc=0x0c0cbf0eu; return 0; }
r[0]=0x00000018u;
goto P_0c0cbf10;
P_0c0cbf10: /* original f356, guest PC 0x0c0cbf10 */
if(!s->budget--) { s->failed_pc=0x0c0cbf10u; return 0; }
vf3_matrix_load(s,ram,3,r[5]+r[0]);
goto P_0c0cbf12;
P_0c0cbf12: /* original e020, guest PC 0x0c0cbf12 */
if(!s->budget--) { s->failed_pc=0x0c0cbf12u; return 0; }
r[0]=0x00000020u;
goto P_0c0cbf14;
P_0c0cbf14: /* original f437, guest PC 0x0c0cbf14 */
if(!s->budget--) { s->failed_pc=0x0c0cbf14u; return 0; }
vf3_matrix_store(s,ram,3,r[4]+r[0]);
goto P_0c0cbf16;
P_0c0cbf16: /* original e01c, guest PC 0x0c0cbf16 */
if(!s->budget--) { s->failed_pc=0x0c0cbf16u; return 0; }
r[0]=0x0000001cu;
goto P_0c0cbf18;
P_0c0cbf18: /* original f356, guest PC 0x0c0cbf18 */
if(!s->budget--) { s->failed_pc=0x0c0cbf18u; return 0; }
vf3_matrix_load(s,ram,3,r[5]+r[0]);
goto P_0c0cbf1a;
P_0c0cbf1a: /* original e024, guest PC 0x0c0cbf1a */
if(!s->budget--) { s->failed_pc=0x0c0cbf1au; return 0; }
r[0]=0x00000024u;
goto P_0c0cbf1c;
P_0c0cbf1c: /* original f437, guest PC 0x0c0cbf1c */
if(!s->budget--) { s->failed_pc=0x0c0cbf1cu; return 0; }
vf3_matrix_store(s,ram,3,r[4]+r[0]);
goto P_0c0cbf1e;
P_0c0cbf1e: /* original 5041, guest PC 0x0c0cbf1e */
if(!s->budget--) { s->failed_pc=0x0c0cbf1eu; return 0; }
r[0]=read(ram,r[4]+4,4);
goto P_0c0cbf20;
P_0c0cbf20: /* original c802, guest PC 0x0c0cbf20 */
if(!s->budget--) { s->failed_pc=0x0c0cbf20u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&2u)==0)!=0);
goto P_0c0cbf22;
P_0c0cbf22: /* original 8d0a, guest PC 0x0c0cbf22 */
if(!s->budget--) { s->failed_pc=0x0c0cbf22u; return 0; }
cond=r[17]&1u;
r[1]=0x00000004u;
if(cond) { goto P_0c0cbf3a; }
goto P_0c0cbf26;
P_0c0cbf24: /* original e104, guest PC 0x0c0cbf24 */
if(!s->budget--) { s->failed_pc=0x0c0cbf24u; return 0; }
r[1]=0x00000004u;
goto P_0c0cbf26;
P_0c0cbf26: /* original d145, guest PC 0x0c0cbf26 */
if(!s->budget--) { s->failed_pc=0x0c0cbf26u; return 0; }
r[1]=read(ram,0x0c0cc03cu,4);
goto P_0c0cbf28;
P_0c0cbf28: /* original e01c, guest PC 0x0c0cbf28 */
if(!s->budget--) { s->failed_pc=0x0c0cbf28u; return 0; }
r[0]=0x0000001cu;
goto P_0c0cbf2a;
P_0c0cbf2a: /* original f246, guest PC 0x0c0cbf2a */
if(!s->budget--) { s->failed_pc=0x0c0cbf2au; return 0; }
vf3_matrix_load(s,ram,2,r[4]+r[0]);
goto P_0c0cbf2c;
P_0c0cbf2c: /* original 415a, guest PC 0x0c0cbf2c */
if(!s->budget--) { s->failed_pc=0x0c0cbf2cu; return 0; }
r[53]=r[1];
goto P_0c0cbf2e;
P_0c0cbf2e: /* original e10a, guest PC 0x0c0cbf2e */
if(!s->budget--) { s->failed_pc=0x0c0cbf2eu; return 0; }
r[1]=0x0000000au;
goto P_0c0cbf30;
P_0c0cbf30: /* original f30d, guest PC 0x0c0cbf30 */
if(!s->budget--) { s->failed_pc=0x0c0cbf30u; return 0; }
fr[3]=r[53];
goto P_0c0cbf32;
P_0c0cbf32: /* original f232, guest PC 0x0c0cbf32 */
if(!s->budget--) { s->failed_pc=0x0c0cbf32u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c0cbf34;
P_0c0cbf34: /* original f427, guest PC 0x0c0cbf34 */
if(!s->budget--) { s->failed_pc=0x0c0cbf34u; return 0; }
vf3_matrix_store(s,ram,2,r[4]+r[0]);
goto P_0c0cbf36;
P_0c0cbf36: /* original e014, guest PC 0x0c0cbf36 */
if(!s->budget--) { s->failed_pc=0x0c0cbf36u; return 0; }
r[0]=0x00000014u;
goto P_0c0cbf38;
P_0c0cbf38: /* original f527, guest PC 0x0c0cbf38 */
if(!s->budget--) { s->failed_pc=0x0c0cbf38u; return 0; }
vf3_matrix_store(s,ram,2,r[5]+r[0]);
goto P_0c0cbf3a;
P_0c0cbf3a: /* original 5343, guest PC 0x0c0cbf3a */
if(!s->budget--) { s->failed_pc=0x0c0cbf3au; return 0; }
r[3]=read(ram,r[4]+12,4);
goto P_0c0cbf3c;
P_0c0cbf3c: /* original 3317, guest PC 0x0c0cbf3c */
if(!s->budget--) { s->failed_pc=0x0c0cbf3cu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>(int32_t)r[1])!=0);
goto P_0c0cbf3e;
P_0c0cbf3e: /* original 8f29, guest PC 0x0c0cbf3e */
if(!s->budget--) { s->failed_pc=0x0c0cbf3eu; return 0; }
cond=r[17]&1u;
r[14]=0x00000000u;
if(!cond) { goto P_0c0cbf94; }
goto P_0c0cbf42;
P_0c0cbf40: /* original ee00, guest PC 0x0c0cbf40 */
if(!s->budget--) { s->failed_pc=0x0c0cbf40u; return 0; }
r[14]=0x00000000u;
goto P_0c0cbf42;
P_0c0cbf42: /* original 14e4, guest PC 0x0c0cbf42 */
if(!s->budget--) { s->failed_pc=0x0c0cbf42u; return 0; }
write(ram,r[4]+16,r[14],4);
goto P_0c0cbf44;
P_0c0cbf44: /* original 5042, guest PC 0x0c0cbf44 */
if(!s->budget--) { s->failed_pc=0x0c0cbf44u; return 0; }
r[0]=read(ram,r[4]+8,4);
goto P_0c0cbf46;
P_0c0cbf46: /* original c802, guest PC 0x0c0cbf46 */
if(!s->budget--) { s->failed_pc=0x0c0cbf46u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&2u)==0)!=0);
goto P_0c0cbf48;
P_0c0cbf48: /* original 8922, guest PC 0x0c0cbf48 */
if(!s->budget--) { s->failed_pc=0x0c0cbf48u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0cbf90; }
goto P_0c0cbf4a;
P_0c0cbf4a: /* original f268, guest PC 0x0c0cbf4a */
if(!s->budget--) { s->failed_pc=0x0c0cbf4au; return 0; }
vf3_matrix_load(s,ram,2,r[6]);
goto P_0c0cbf4c;
P_0c0cbf4c: /* original e018, guest PC 0x0c0cbf4c */
if(!s->budget--) { s->failed_pc=0x0c0cbf4cu; return 0; }
r[0]=0x00000018u;
goto P_0c0cbf4e;
P_0c0cbf4e: /* original f378, guest PC 0x0c0cbf4e */
if(!s->budget--) { s->failed_pc=0x0c0cbf4eu; return 0; }
vf3_matrix_load(s,ram,3,r[7]);
goto P_0c0cbf50;
P_0c0cbf50: /* original f231, guest PC 0x0c0cbf50 */
if(!s->budget--) { s->failed_pc=0x0c0cbf50u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'-');
goto P_0c0cbf52;
P_0c0cbf52: /* original f427, guest PC 0x0c0cbf52 */
if(!s->budget--) { s->failed_pc=0x0c0cbf52u; return 0; }
vf3_matrix_store(s,ram,2,r[4]+r[0]);
goto P_0c0cbf54;
P_0c0cbf54: /* original e008, guest PC 0x0c0cbf54 */
if(!s->budget--) { s->failed_pc=0x0c0cbf54u; return 0; }
r[0]=0x00000008u;
goto P_0c0cbf56;
P_0c0cbf56: /* original f266, guest PC 0x0c0cbf56 */
if(!s->budget--) { s->failed_pc=0x0c0cbf56u; return 0; }
vf3_matrix_load(s,ram,2,r[6]+r[0]);
goto P_0c0cbf58;
P_0c0cbf58: /* original f376, guest PC 0x0c0cbf58 */
if(!s->budget--) { s->failed_pc=0x0c0cbf58u; return 0; }
vf3_matrix_load(s,ram,3,r[7]+r[0]);
goto P_0c0cbf5a;
P_0c0cbf5a: /* original e020, guest PC 0x0c0cbf5a */
if(!s->budget--) { s->failed_pc=0x0c0cbf5au; return 0; }
r[0]=0x00000020u;
goto P_0c0cbf5c;
P_0c0cbf5c: /* original f231, guest PC 0x0c0cbf5c */
if(!s->budget--) { s->failed_pc=0x0c0cbf5cu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'-');
goto P_0c0cbf5e;
P_0c0cbf5e: /* original f427, guest PC 0x0c0cbf5e */
if(!s->budget--) { s->failed_pc=0x0c0cbf5eu; return 0; }
vf3_matrix_store(s,ram,2,r[4]+r[0]);
goto P_0c0cbf60;
P_0c0cbf60: /* original e018, guest PC 0x0c0cbf60 */
if(!s->budget--) { s->failed_pc=0x0c0cbf60u; return 0; }
r[0]=0x00000018u;
goto P_0c0cbf62;
P_0c0cbf62: /* original f446, guest PC 0x0c0cbf62 */
if(!s->budget--) { s->failed_pc=0x0c0cbf62u; return 0; }
vf3_matrix_load(s,ram,4,r[4]+r[0]);
goto P_0c0cbf64;
P_0c0cbf64: /* original e020, guest PC 0x0c0cbf64 */
if(!s->budget--) { s->failed_pc=0x0c0cbf64u; return 0; }
r[0]=0x00000020u;
goto P_0c0cbf66;
P_0c0cbf66: /* original f546, guest PC 0x0c0cbf66 */
if(!s->budget--) { s->failed_pc=0x0c0cbf66u; return 0; }
vf3_matrix_load(s,ram,5,r[4]+r[0]);
goto P_0c0cbf68;
P_0c0cbf68: /* original c735, guest PC 0x0c0cbf68 */
if(!s->budget--) { s->failed_pc=0x0c0cbf68u; return 0; }
r[0]=0x0c0cc040u;
goto P_0c0cbf6a;
P_0c0cbf6a: /* original f04c, guest PC 0x0c0cbf6a */
if(!s->budget--) { s->failed_pc=0x0c0cbf6au; return 0; }
vf3_matrix_move(s,0,4);
goto P_0c0cbf6c;
P_0c0cbf6c: /* original f35c, guest PC 0x0c0cbf6c */
if(!s->budget--) { s->failed_pc=0x0c0cbf6cu; return 0; }
vf3_matrix_move(s,3,5);
goto P_0c0cbf6e;
P_0c0cbf6e: /* original f352, guest PC 0x0c0cbf6e */
if(!s->budget--) { s->failed_pc=0x0c0cbf6eu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[5],r[18],'*');
goto P_0c0cbf70;
P_0c0cbf70: /* original f34e, guest PC 0x0c0cbf70 */
if(!s->budget--) { s->failed_pc=0x0c0cbf70u; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[4],fr[3],r[18]);
goto P_0c0cbf72;
P_0c0cbf72: /* original f408, guest PC 0x0c0cbf72 */
if(!s->budget--) { s->failed_pc=0x0c0cbf72u; return 0; }
vf3_matrix_load(s,ram,4,r[0]);
goto P_0c0cbf74;
P_0c0cbf74: /* original f53c, guest PC 0x0c0cbf74 */
if(!s->budget--) { s->failed_pc=0x0c0cbf74u; return 0; }
vf3_matrix_move(s,5,3);
goto P_0c0cbf76;
P_0c0cbf76: /* original f455, guest PC 0x0c0cbf76 */
if(!s->budget--) { s->failed_pc=0x0c0cbf76u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[4])>as_float(fr[5]))!=0);
goto P_0c0cbf78;
P_0c0cbf78: /* original 890a, guest PC 0x0c0cbf78 */
if(!s->budget--) { s->failed_pc=0x0c0cbf78u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0cbf90; }
goto P_0c0cbf7a;
P_0c0cbf7a: /* original c72a, guest PC 0x0c0cbf7a */
if(!s->budget--) { s->failed_pc=0x0c0cbf7au; return 0; }
r[0]=0x0c0cc024u;
goto P_0c0cbf7c;
P_0c0cbf7c: /* original 4f26, guest PC 0x0c0cbf7c */
if(!s->budget--) { s->failed_pc=0x0c0cbf7cu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0cbf7e;
P_0c0cbf7e: /* original f308, guest PC 0x0c0cbf7e */
if(!s->budget--) { s->failed_pc=0x0c0cbf7eu; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c0cbf80;
P_0c0cbf80: /* original e208, guest PC 0x0c0cbf80 */
if(!s->budget--) { s->failed_pc=0x0c0cbf80u; return 0; }
r[2]=0x00000008u;
goto P_0c0cbf82;
P_0c0cbf82: /* original e30f, guest PC 0x0c0cbf82 */
if(!s->budget--) { s->failed_pc=0x0c0cbf82u; return 0; }
r[3]=0x0000000fu;
goto P_0c0cbf84;
P_0c0cbf84: /* original e01c, guest PC 0x0c0cbf84 */
if(!s->budget--) { s->failed_pc=0x0c0cbf84u; return 0; }
r[0]=0x0000001cu;
goto P_0c0cbf86;
P_0c0cbf86: /* original f437, guest PC 0x0c0cbf86 */
if(!s->budget--) { s->failed_pc=0x0c0cbf86u; return 0; }
vf3_matrix_store(s,ram,3,r[4]+r[0]);
goto P_0c0cbf88;
P_0c0cbf88: /* original 1434, guest PC 0x0c0cbf88 */
if(!s->budget--) { s->failed_pc=0x0c0cbf88u; return 0; }
write(ram,r[4]+16,r[3],4);
goto P_0c0cbf8a;
P_0c0cbf8a: /* original 1425, guest PC 0x0c0cbf8a */
if(!s->budget--) { s->failed_pc=0x0c0cbf8au; return 0; }
write(ram,r[4]+20,r[2],4);
goto P_0c0cbf8c;
P_0c0cbf8c: /* original 000b, guest PC 0x0c0cbf8c */
if(!s->budget--) { s->failed_pc=0x0c0cbf8cu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0cbf8e: /* original 6ef6, guest PC 0x0c0cbf8e */
if(!s->budget--) { s->failed_pc=0x0c0cbf8eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0cbf90;
P_0c0cbf90: /* original a013, guest PC 0x0c0cbf90 */
if(!s->budget--) { s->failed_pc=0x0c0cbf90u; return 0; }
r[0]=r[14];
goto P_0c0cbfba;
P_0c0cbf92: /* original 60e3, guest PC 0x0c0cbf92 */
if(!s->budget--) { s->failed_pc=0x0c0cbf92u; return 0; }
r[0]=r[14];
goto P_0c0cbf94;
P_0c0cbf94: /* original 5243, guest PC 0x0c0cbf94 */
if(!s->budget--) { s->failed_pc=0x0c0cbf94u; return 0; }
r[2]=read(ram,r[4]+12,4);
goto P_0c0cbf96;
P_0c0cbf96: /* original 7201, guest PC 0x0c0cbf96 */
if(!s->budget--) { s->failed_pc=0x0c0cbf96u; return 0; }
r[2]+=0x00000001u;
goto P_0c0cbf98;
P_0c0cbf98: /* original 1423, guest PC 0x0c0cbf98 */
if(!s->budget--) { s->failed_pc=0x0c0cbf98u; return 0; }
write(ram,r[4]+12,r[2],4);
goto P_0c0cbf9a;
P_0c0cbf9a: /* original 8551, guest PC 0x0c0cbf9a */
if(!s->budget--) { s->failed_pc=0x0c0cbf9au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[5]+2,2);
goto P_0c0cbf9c;
P_0c0cbf9c: /* original d326, guest PC 0x0c0cbf9c */
if(!s->budget--) { s->failed_pc=0x0c0cbf9cu; return 0; }
r[3]=read(ram,0x0c0cc038u,4);
goto P_0c0cbf9e;
P_0c0cbf9e: /* original 6603, guest PC 0x0c0cbf9e */
if(!s->budget--) { s->failed_pc=0x0c0cbf9eu; return 0; }
r[6]=r[0];
goto P_0c0cbfa0;
P_0c0cbfa0: /* original e004, guest PC 0x0c0cbfa0 */
if(!s->budget--) { s->failed_pc=0x0c0cbfa0u; return 0; }
r[0]=0x00000004u;
goto P_0c0cbfa2;
P_0c0cbfa2: /* original 430b, guest PC 0x0c0cbfa2 */
if(!s->budget--) { s->failed_pc=0x0c0cbfa2u; return 0; }
target=r[3];
r[16]=0x0c0cbfa6u;
r[1]=read(ram,r[4]+16,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0cbfa6u) { target=s->pc; goto dispatch; }
goto P_0c0cbfa6;
P_0c0cbfa4: /* original 5144, guest PC 0x0c0cbfa4 */
if(!s->budget--) { s->failed_pc=0x0c0cbfa4u; return 0; }
r[1]=read(ram,r[4]+16,4);
goto P_0c0cbfa6;
P_0c0cbfa6: /* original 6303, guest PC 0x0c0cbfa6 */
if(!s->budget--) { s->failed_pc=0x0c0cbfa6u; return 0; }
r[3]=r[0];
goto P_0c0cbfa8;
P_0c0cbfa8: /* original 3638, guest PC 0x0c0cbfa8 */
if(!s->budget--) { s->failed_pc=0x0c0cbfa8u; return 0; }
r[6]-=r[3];
goto P_0c0cbfaa;
P_0c0cbfaa: /* original 4611, guest PC 0x0c0cbfaa */
if(!s->budget--) { s->failed_pc=0x0c0cbfaau; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[6]>=0)!=0);
goto P_0c0cbfac;
P_0c0cbfac: /* original 8d04, guest PC 0x0c0cbfac */
if(!s->budget--) { s->failed_pc=0x0c0cbfacu; return 0; }
cond=r[17]&1u;
write(ram,r[4]+16,r[0],4);
if(cond) { goto P_0c0cbfb8; }
goto P_0c0cbfb0;
P_0c0cbfae: /* original 1404, guest PC 0x0c0cbfae */
if(!s->budget--) { s->failed_pc=0x0c0cbfaeu; return 0; }
write(ram,r[4]+16,r[0],4);
goto P_0c0cbfb0;
P_0c0cbfb0: /* original 5344, guest PC 0x0c0cbfb0 */
if(!s->budget--) { s->failed_pc=0x0c0cbfb0u; return 0; }
r[3]=read(ram,r[4]+16,4);
goto P_0c0cbfb2;
P_0c0cbfb2: /* original 336c, guest PC 0x0c0cbfb2 */
if(!s->budget--) { s->failed_pc=0x0c0cbfb2u; return 0; }
r[3]+=r[6];
goto P_0c0cbfb4;
P_0c0cbfb4: /* original 66e3, guest PC 0x0c0cbfb4 */
if(!s->budget--) { s->failed_pc=0x0c0cbfb4u; return 0; }
r[6]=r[14];
goto P_0c0cbfb6;
P_0c0cbfb6: /* original 1434, guest PC 0x0c0cbfb6 */
if(!s->budget--) { s->failed_pc=0x0c0cbfb6u; return 0; }
write(ram,r[4]+16,r[3],4);
goto P_0c0cbfb8;
P_0c0cbfb8: /* original 6063, guest PC 0x0c0cbfb8 */
if(!s->budget--) { s->failed_pc=0x0c0cbfb8u; return 0; }
r[0]=r[6];
goto P_0c0cbfba;
P_0c0cbfba: /* original 8151, guest PC 0x0c0cbfba */
if(!s->budget--) { s->failed_pc=0x0c0cbfbau; return 0; }
write(ram,r[5]+2,r[0],2);
goto P_0c0cbfbc;
P_0c0cbfbc: /* original 14e5, guest PC 0x0c0cbfbc */
if(!s->budget--) { s->failed_pc=0x0c0cbfbcu; return 0; }
write(ram,r[4]+20,r[14],4);
goto P_0c0cbfbe;
P_0c0cbfbe: /* original 4f26, guest PC 0x0c0cbfbe */
if(!s->budget--) { s->failed_pc=0x0c0cbfbeu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0cbfc0;
P_0c0cbfc0: /* original 000b, guest PC 0x0c0cbfc0 */
if(!s->budget--) { s->failed_pc=0x0c0cbfc0u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0cbfc2: /* original 6ef6, guest PC 0x0c0cbfc2 */
if(!s->budget--) { s->failed_pc=0x0c0cbfc2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0cbfc4;
P_0c0cbfc4: /* original e004, guest PC 0x0c0cbfc4 */
if(!s->budget--) { s->failed_pc=0x0c0cbfc4u; return 0; }
r[0]=0x00000004u;
goto P_0c0cbfc6;
P_0c0cbfc6: /* original 2fe6, guest PC 0x0c0cbfc6 */
if(!s->budget--) { s->failed_pc=0x0c0cbfc6u; return 0; }
r[15]-=4; write(ram,r[15],r[14],4);
goto P_0c0cbfc8;
P_0c0cbfc8: /* original 4f22, guest PC 0x0c0cbfc8 */
if(!s->budget--) { s->failed_pc=0x0c0cbfc8u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0cbfca;
P_0c0cbfca: /* original e300, guest PC 0x0c0cbfca */
if(!s->budget--) { s->failed_pc=0x0c0cbfcau; return 0; }
r[3]=0x00000000u;
goto P_0c0cbfcc;
P_0c0cbfcc: /* original 6233, guest PC 0x0c0cbfcc */
if(!s->budget--) { s->failed_pc=0x0c0cbfccu; return 0; }
r[2]=r[3];
goto P_0c0cbfce;
P_0c0cbfce: /* original 5ef2, guest PC 0x0c0cbfce */
if(!s->budget--) { s->failed_pc=0x0c0cbfceu; return 0; }
r[14]=read(ram,r[15]+8,4);
goto P_0c0cbfd0;
P_0c0cbfd0: /* original 1e34, guest PC 0x0c0cbfd0 */
if(!s->budget--) { s->failed_pc=0x0c0cbfd0u; return 0; }
write(ram,r[14]+16,r[3],4);
goto P_0c0cbfd2;
P_0c0cbfd2: /* original 1e33, guest PC 0x0c0cbfd2 */
if(!s->budget--) { s->failed_pc=0x0c0cbfd2u; return 0; }
write(ram,r[14]+12,r[3],4);
goto P_0c0cbfd4;
P_0c0cbfd4: /* original f378, guest PC 0x0c0cbfd4 */
if(!s->budget--) { s->failed_pc=0x0c0cbfd4u; return 0; }
vf3_matrix_load(s,ram,3,r[7]);
goto P_0c0cbfd6;
P_0c0cbfd6: /* original f468, guest PC 0x0c0cbfd6 */
if(!s->budget--) { s->failed_pc=0x0c0cbfd6u; return 0; }
vf3_matrix_load(s,ram,4,r[6]);
goto P_0c0cbfd8;
P_0c0cbfd8: /* original f666, guest PC 0x0c0cbfd8 */
if(!s->budget--) { s->failed_pc=0x0c0cbfd8u; return 0; }
vf3_matrix_load(s,ram,6,r[6]+r[0]);
goto P_0c0cbfda;
P_0c0cbfda: /* original f431, guest PC 0x0c0cbfda */
if(!s->budget--) { s->failed_pc=0x0c0cbfdau; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'-');
goto P_0c0cbfdc;
P_0c0cbfdc: /* original f376, guest PC 0x0c0cbfdc */
if(!s->budget--) { s->failed_pc=0x0c0cbfdcu; return 0; }
vf3_matrix_load(s,ram,3,r[7]+r[0]);
goto P_0c0cbfde;
P_0c0cbfde: /* original e008, guest PC 0x0c0cbfde */
if(!s->budget--) { s->failed_pc=0x0c0cbfdeu; return 0; }
r[0]=0x00000008u;
goto P_0c0cbfe0;
P_0c0cbfe0: /* original f631, guest PC 0x0c0cbfe0 */
if(!s->budget--) { s->failed_pc=0x0c0cbfe0u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[3],r[18],'-');
goto P_0c0cbfe2;
P_0c0cbfe2: /* original f566, guest PC 0x0c0cbfe2 */
if(!s->budget--) { s->failed_pc=0x0c0cbfe2u; return 0; }
vf3_matrix_load(s,ram,5,r[6]+r[0]);
goto P_0c0cbfe4;
P_0c0cbfe4: /* original f376, guest PC 0x0c0cbfe4 */
if(!s->budget--) { s->failed_pc=0x0c0cbfe4u; return 0; }
vf3_matrix_load(s,ram,3,r[7]+r[0]);
goto P_0c0cbfe6;
P_0c0cbfe6: /* original c70d, guest PC 0x0c0cbfe6 */
if(!s->budget--) { s->failed_pc=0x0c0cbfe6u; return 0; }
r[0]=0x0c0cc01cu;
goto P_0c0cbfe8;
P_0c0cbfe8: /* original f74c, guest PC 0x0c0cbfe8 */
if(!s->budget--) { s->failed_pc=0x0c0cbfe8u; return 0; }
vf3_matrix_move(s,7,4);
goto P_0c0cbfea;
P_0c0cbfea: /* original f742, guest PC 0x0c0cbfea */
if(!s->budget--) { s->failed_pc=0x0c0cbfeau; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[4],r[18],'*');
goto P_0c0cbfec;
P_0c0cbfec: /* original f531, guest PC 0x0c0cbfec */
if(!s->budget--) { s->failed_pc=0x0c0cbfecu; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[3],r[18],'-');
goto P_0c0cbfee;
P_0c0cbfee: /* original f06c, guest PC 0x0c0cbfee */
if(!s->budget--) { s->failed_pc=0x0c0cbfeeu; return 0; }
vf3_matrix_move(s,0,6);
goto P_0c0cbff0;
P_0c0cbff0: /* original f37c, guest PC 0x0c0cbff0 */
if(!s->budget--) { s->failed_pc=0x0c0cbff0u; return 0; }
vf3_matrix_move(s,3,7);
goto P_0c0cbff2;
P_0c0cbff2: /* original f85c, guest PC 0x0c0cbff2 */
if(!s->budget--) { s->failed_pc=0x0c0cbff2u; return 0; }
vf3_matrix_move(s,8,5);
goto P_0c0cbff4;
P_0c0cbff4: /* original f852, guest PC 0x0c0cbff4 */
if(!s->budget--) { s->failed_pc=0x0c0cbff4u; return 0; }
fr[8]=vf3_fpu_binary(fr[8],fr[5],r[18],'*');
goto P_0c0cbff6;
P_0c0cbff6: /* original f708, guest PC 0x0c0cbff6 */
if(!s->budget--) { s->failed_pc=0x0c0cbff6u; return 0; }
vf3_matrix_load(s,ram,7,r[0]);
goto P_0c0cbff8;
P_0c0cbff8: /* original f58c, guest PC 0x0c0cbff8 */
if(!s->budget--) { s->failed_pc=0x0c0cbff8u; return 0; }
vf3_matrix_move(s,5,8);
goto P_0c0cbffa;
P_0c0cbffa: /* original f530, guest PC 0x0c0cbffa */
if(!s->budget--) { s->failed_pc=0x0c0cbffau; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[3],r[18],'+');
goto P_0c0cbffc;
P_0c0cbffc: /* original f48c, guest PC 0x0c0cbffc */
if(!s->budget--) { s->failed_pc=0x0c0cbffcu; return 0; }
vf3_matrix_move(s,4,8);
goto P_0c0cbffe;
P_0c0cbffe: /* original f430, guest PC 0x0c0cbffe */
if(!s->budget--) { s->failed_pc=0x0c0cbffeu; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'+');
goto P_0c0cc000;
P_0c0cc000: /* original f25c, guest PC 0x0c0cc000 */
if(!s->budget--) { s->failed_pc=0x0c0cc000u; return 0; }
vf3_matrix_move(s,2,5);
goto P_0c0cc002;
P_0c0cc002: /* original f26e, guest PC 0x0c0cc002 */
if(!s->budget--) { s->failed_pc=0x0c0cc002u; return 0; }
fr[2]=vf3_fpu_mac(fr[0],fr[6],fr[2],r[18]);
goto P_0c0cc004;
P_0c0cc004: /* original f755, guest PC 0x0c0cc004 */
if(!s->budget--) { s->failed_pc=0x0c0cc004u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[7])>as_float(fr[5]))!=0);
goto P_0c0cc006;
P_0c0cc006: /* original 8f02, guest PC 0x0c0cc006 */
if(!s->budget--) { s->failed_pc=0x0c0cc006u; return 0; }
cond=r[17]&1u;
vf3_matrix_move(s,6,2);
if(!cond) { goto P_0c0cc00e; }
goto P_0c0cc00a;
P_0c0cc008: /* original f62c, guest PC 0x0c0cc008 */
if(!s->budget--) { s->failed_pc=0x0c0cc008u; return 0; }
vf3_matrix_move(s,6,2);
goto P_0c0cc00a;
P_0c0cc00a: /* original a001, guest PC 0x0c0cc00a */
if(!s->budget--) { s->failed_pc=0x0c0cc00au; return 0; }
fr[5]=0;
goto P_0c0cc010;
P_0c0cc00c: /* original f58d, guest PC 0x0c0cc00c */
if(!s->budget--) { s->failed_pc=0x0c0cc00cu; return 0; }
fr[5]=0;
goto P_0c0cc00e;
P_0c0cc00e: /* original f57d, guest PC 0x0c0cc00e */
if(!s->budget--) { s->failed_pc=0x0c0cc00eu; return 0; }
if(!vf3_fpu_fsrra(fr[5],r[18],&fr[5])) goto unsupported;
goto P_0c0cc010;
P_0c0cc010: /* original f765, guest PC 0x0c0cc010 */
if(!s->budget--) { s->failed_pc=0x0c0cc010u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[7])>as_float(fr[6]))!=0);
goto P_0c0cc012;
P_0c0cc012: /* original 8f17, guest PC 0x0c0cc012 */
if(!s->budget--) { s->failed_pc=0x0c0cc012u; return 0; }
cond=r[17]&1u;
fr[4]=vf3_fpu_binary(fr[4],fr[5],r[18],'*');
if(!cond) { goto P_0c0cc044; }
goto P_0c0cc016;
P_0c0cc014: /* original f452, guest PC 0x0c0cc014 */
if(!s->budget--) { s->failed_pc=0x0c0cc014u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[5],r[18],'*');
goto P_0c0cc016;
P_0c0cc016: /* original a016, guest PC 0x0c0cc016 */
if(!s->budget--) { s->failed_pc=0x0c0cc016u; return 0; }
fr[6]=0;
goto P_0c0cc046;
P_0c0cc018: /* original f68d, guest PC 0x0c0cc018 */
if(!s->budget--) { s->failed_pc=0x0c0cc018u; return 0; }
fr[6]=0;
return vf3_matrix_family(0x0c0cc01au,s,ram);
P_0c0cc044: /* original f67d, guest PC 0x0c0cc044 */
if(!s->budget--) { s->failed_pc=0x0c0cc044u; return 0; }
if(!vf3_fpu_fsrra(fr[6],r[18],&fr[6])) goto unsupported;
goto P_0c0cc046;
P_0c0cc046: /* original f462, guest PC 0x0c0cc046 */
if(!s->budget--) { s->failed_pc=0x0c0cc046u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[6],r[18],'*');
goto P_0c0cc048;
P_0c0cc048: /* original f69d, guest PC 0x0c0cc048 */
if(!s->budget--) { s->failed_pc=0x0c0cc048u; return 0; }
fr[6]=0x3f800000u;
goto P_0c0cc04a;
P_0c0cc04a: /* original f653, guest PC 0x0c0cc04a */
if(!s->budget--) { s->failed_pc=0x0c0cc04au; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[5],r[18],'/');
goto P_0c0cc04c;
P_0c0cc04c: /* original c7c1, guest PC 0x0c0cc04c */
if(!s->budget--) { s->failed_pc=0x0c0cc04cu; return 0; }
r[0]=0x0c0cc354u;
goto P_0c0cc04e;
P_0c0cc04e: /* original f808, guest PC 0x0c0cc04e */
if(!s->budget--) { s->failed_pc=0x0c0cc04eu; return 0; }
vf3_matrix_load(s,ram,8,r[0]);
goto P_0c0cc050;
P_0c0cc050: /* original c7c1, guest PC 0x0c0cc050 */
if(!s->budget--) { s->failed_pc=0x0c0cc050u; return 0; }
r[0]=0x0c0cc358u;
goto P_0c0cc052;
P_0c0cc052: /* original f508, guest PC 0x0c0cc052 */
if(!s->budget--) { s->failed_pc=0x0c0cc052u; return 0; }
vf3_matrix_load(s,ram,5,r[0]);
goto P_0c0cc054;
P_0c0cc054: /* original c7c1, guest PC 0x0c0cc054 */
if(!s->budget--) { s->failed_pc=0x0c0cc054u; return 0; }
r[0]=0x0c0cc35cu;
goto P_0c0cc056;
P_0c0cc056: /* original f685, guest PC 0x0c0cc056 */
if(!s->budget--) { s->failed_pc=0x0c0cc056u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[6])>as_float(fr[8]))!=0);
goto P_0c0cc058;
P_0c0cc058: /* original 8f1d, guest PC 0x0c0cc058 */
if(!s->budget--) { s->failed_pc=0x0c0cc058u; return 0; }
cond=r[17]&1u;
vf3_matrix_load(s,ram,7,r[0]);
if(!cond) { goto P_0c0cc096; }
goto P_0c0cc05c;
P_0c0cc05a: /* original f708, guest PC 0x0c0cc05a */
if(!s->budget--) { s->failed_pc=0x0c0cc05au; return 0; }
vf3_matrix_load(s,ram,7,r[0]);
goto P_0c0cc05c;
P_0c0cc05c: /* original f655, guest PC 0x0c0cc05c */
if(!s->budget--) { s->failed_pc=0x0c0cc05cu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[6])>as_float(fr[5]))!=0);
goto P_0c0cc05e;
P_0c0cc05e: /* original 8b00, guest PC 0x0c0cc05e */
if(!s->budget--) { s->failed_pc=0x0c0cc05eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0cc062; }
goto P_0c0cc060;
P_0c0cc060: /* original f65c, guest PC 0x0c0cc060 */
if(!s->budget--) { s->failed_pc=0x0c0cc060u; return 0; }
vf3_matrix_move(s,6,5);
goto P_0c0cc062;
P_0c0cc062: /* original f745, guest PC 0x0c0cc062 */
if(!s->budget--) { s->failed_pc=0x0c0cc062u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[7])>as_float(fr[4]))!=0);
goto P_0c0cc064;
P_0c0cc064: /* original 8b00, guest PC 0x0c0cc064 */
if(!s->budget--) { s->failed_pc=0x0c0cc064u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0cc068; }
goto P_0c0cc066;
P_0c0cc066: /* original f47c, guest PC 0x0c0cc066 */
if(!s->budget--) { s->failed_pc=0x0c0cc066u; return 0; }
vf3_matrix_move(s,4,7);
goto P_0c0cc068;
P_0c0cc068: /* original e018, guest PC 0x0c0cc068 */
if(!s->budget--) { s->failed_pc=0x0c0cc068u; return 0; }
r[0]=0x00000018u;
goto P_0c0cc06a;
P_0c0cc06a: /* original d1bd, guest PC 0x0c0cc06a */
if(!s->budget--) { s->failed_pc=0x0c0cc06au; return 0; }
r[1]=read(ram,0x0c0cc360u,4);
goto P_0c0cc06c;
P_0c0cc06c: /* original f746, guest PC 0x0c0cc06c */
if(!s->budget--) { s->failed_pc=0x0c0cc06cu; return 0; }
vf3_matrix_load(s,ram,7,r[4]+r[0]);
goto P_0c0cc06e;
P_0c0cc06e: /* original 50e2, guest PC 0x0c0cc06e */
if(!s->budget--) { s->failed_pc=0x0c0cc06eu; return 0; }
r[0]=read(ram,r[14]+8,4);
goto P_0c0cc070;
P_0c0cc070: /* original c802, guest PC 0x0c0cc070 */
if(!s->budget--) { s->failed_pc=0x0c0cc070u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&2u)==0)!=0);
goto P_0c0cc072;
P_0c0cc072: /* original 8902, guest PC 0x0c0cc072 */
if(!s->budget--) { s->failed_pc=0x0c0cc072u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0cc07a; }
goto P_0c0cc074;
P_0c0cc074: /* original e014, guest PC 0x0c0cc074 */
if(!s->budget--) { s->failed_pc=0x0c0cc074u; return 0; }
r[0]=0x00000014u;
goto P_0c0cc076;
P_0c0cc076: /* original f746, guest PC 0x0c0cc076 */
if(!s->budget--) { s->failed_pc=0x0c0cc076u; return 0; }
vf3_matrix_load(s,ram,7,r[4]+r[0]);
goto P_0c0cc078;
P_0c0cc078: /* original 7118, guest PC 0x0c0cc078 */
if(!s->budget--) { s->failed_pc=0x0c0cc078u; return 0; }
r[1]+=0x00000018u;
goto P_0c0cc07a;
P_0c0cc07a: /* original 64e2, guest PC 0x0c0cc07a */
if(!s->budget--) { s->failed_pc=0x0c0cc07au; return 0; }
tmp=read(ram,r[14],4);
r[4]=tmp;
goto P_0c0cc07c;
P_0c0cc07c: /* original f57c, guest PC 0x0c0cc07c */
if(!s->budget--) { s->failed_pc=0x0c0cc07cu; return 0; }
vf3_matrix_move(s,5,7);
goto P_0c0cc07e;
P_0c0cc07e: /* original 341c, guest PC 0x0c0cc07e */
if(!s->budget--) { s->failed_pc=0x0c0cc07eu; return 0; }
r[4]+=r[1];
goto P_0c0cc080;
P_0c0cc080: /* original f348, guest PC 0x0c0cc080 */
if(!s->budget--) { s->failed_pc=0x0c0cc080u; return 0; }
vf3_matrix_load(s,ram,3,r[4]);
goto P_0c0cc082;
P_0c0cc082: /* original f532, guest PC 0x0c0cc082 */
if(!s->budget--) { s->failed_pc=0x0c0cc082u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[3],r[18],'*');
goto P_0c0cc084;
P_0c0cc084: /* original f35c, guest PC 0x0c0cc084 */
if(!s->budget--) { s->failed_pc=0x0c0cc084u; return 0; }
vf3_matrix_move(s,3,5);
goto P_0c0cc086;
P_0c0cc086: /* original f54c, guest PC 0x0c0cc086 */
if(!s->budget--) { s->failed_pc=0x0c0cc086u; return 0; }
vf3_matrix_move(s,5,4);
goto P_0c0cc088;
P_0c0cc088: /* original f532, guest PC 0x0c0cc088 */
if(!s->budget--) { s->failed_pc=0x0c0cc088u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[3],r[18],'*');
goto P_0c0cc08a;
P_0c0cc08a: /* original f35c, guest PC 0x0c0cc08a */
if(!s->budget--) { s->failed_pc=0x0c0cc08au; return 0; }
vf3_matrix_move(s,3,5);
goto P_0c0cc08c;
P_0c0cc08c: /* original f56c, guest PC 0x0c0cc08c */
if(!s->budget--) { s->failed_pc=0x0c0cc08cu; return 0; }
vf3_matrix_move(s,5,6);
goto P_0c0cc08e;
P_0c0cc08e: /* original f532, guest PC 0x0c0cc08e */
if(!s->budget--) { s->failed_pc=0x0c0cc08eu; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[3],r[18],'*');
goto P_0c0cc090;
P_0c0cc090: /* original f53d, guest PC 0x0c0cc090 */
if(!s->budget--) { s->failed_pc=0x0c0cc090u; return 0; }
r[53]=truncate_float(fr[5]);
goto P_0c0cc092;
P_0c0cc092: /* original 035a, guest PC 0x0c0cc092 */
if(!s->budget--) { s->failed_pc=0x0c0cc092u; return 0; }
r[3]=r[53];
goto P_0c0cc094;
P_0c0cc094: /* original 1e34, guest PC 0x0c0cc094 */
if(!s->budget--) { s->failed_pc=0x0c0cc094u; return 0; }
write(ram,r[14]+16,r[3],4);
goto P_0c0cc096;
P_0c0cc096: /* original d2b3, guest PC 0x0c0cc096 */
if(!s->budget--) { s->failed_pc=0x0c0cc096u; return 0; }
r[2]=read(ram,0x0c0cc364u,4);
goto P_0c0cc098;
P_0c0cc098: /* original e004, guest PC 0x0c0cc098 */
if(!s->budget--) { s->failed_pc=0x0c0cc098u; return 0; }
r[0]=0x00000004u;
goto P_0c0cc09a;
P_0c0cc09a: /* original 54e4, guest PC 0x0c0cc09a */
if(!s->budget--) { s->failed_pc=0x0c0cc09au; return 0; }
r[4]=read(ram,r[14]+16,4);
goto P_0c0cc09c;
P_0c0cc09c: /* original 420b, guest PC 0x0c0cc09c */
if(!s->budget--) { s->failed_pc=0x0c0cc09cu; return 0; }
target=r[2];
r[16]=0x0c0cc0a0u;
r[1]=r[4];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0cc0a0u) { target=s->pc; goto dispatch; }
goto P_0c0cc0a0;
P_0c0cc09e: /* original 6143, guest PC 0x0c0cc09e */
if(!s->budget--) { s->failed_pc=0x0c0cc09eu; return 0; }
r[1]=r[4];
goto P_0c0cc0a0;
P_0c0cc0a0: /* original 6303, guest PC 0x0c0cc0a0 */
if(!s->budget--) { s->failed_pc=0x0c0cc0a0u; return 0; }
r[3]=r[0];
goto P_0c0cc0a2;
P_0c0cc0a2: /* original 1e04, guest PC 0x0c0cc0a2 */
if(!s->budget--) { s->failed_pc=0x0c0cc0a2u; return 0; }
write(ram,r[14]+16,r[0],4);
goto P_0c0cc0a4;
P_0c0cc0a4: /* original 3438, guest PC 0x0c0cc0a4 */
if(!s->budget--) { s->failed_pc=0x0c0cc0a4u; return 0; }
r[4]-=r[3];
goto P_0c0cc0a6;
P_0c0cc0a6: /* original 6043, guest PC 0x0c0cc0a6 */
if(!s->budget--) { s->failed_pc=0x0c0cc0a6u; return 0; }
r[0]=r[4];
goto P_0c0cc0a8;
P_0c0cc0a8: /* original 8151, guest PC 0x0c0cc0a8 */
if(!s->budget--) { s->failed_pc=0x0c0cc0a8u; return 0; }
write(ram,r[5]+2,r[0],2);
goto P_0c0cc0aa;
P_0c0cc0aa: /* original f378, guest PC 0x0c0cc0aa */
if(!s->budget--) { s->failed_pc=0x0c0cc0aau; return 0; }
vf3_matrix_load(s,ram,3,r[7]);
goto P_0c0cc0ac;
P_0c0cc0ac: /* original e018, guest PC 0x0c0cc0ac */
if(!s->budget--) { s->failed_pc=0x0c0cc0acu; return 0; }
r[0]=0x00000018u;
goto P_0c0cc0ae;
P_0c0cc0ae: /* original f268, guest PC 0x0c0cc0ae */
if(!s->budget--) { s->failed_pc=0x0c0cc0aeu; return 0; }
vf3_matrix_load(s,ram,2,r[6]);
goto P_0c0cc0b0;
P_0c0cc0b0: /* original e304, guest PC 0x0c0cc0b0 */
if(!s->budget--) { s->failed_pc=0x0c0cc0b0u; return 0; }
r[3]=0x00000004u;
goto P_0c0cc0b2;
P_0c0cc0b2: /* original 4f26, guest PC 0x0c0cc0b2 */
if(!s->budget--) { s->failed_pc=0x0c0cc0b2u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0cc0b4;
P_0c0cc0b4: /* original f231, guest PC 0x0c0cc0b4 */
if(!s->budget--) { s->failed_pc=0x0c0cc0b4u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'-');
goto P_0c0cc0b6;
P_0c0cc0b6: /* original fe27, guest PC 0x0c0cc0b6 */
if(!s->budget--) { s->failed_pc=0x0c0cc0b6u; return 0; }
vf3_matrix_store(s,ram,2,r[14]+r[0]);
goto P_0c0cc0b8;
P_0c0cc0b8: /* original e004, guest PC 0x0c0cc0b8 */
if(!s->budget--) { s->failed_pc=0x0c0cc0b8u; return 0; }
r[0]=0x00000004u;
goto P_0c0cc0ba;
P_0c0cc0ba: /* original f266, guest PC 0x0c0cc0ba */
if(!s->budget--) { s->failed_pc=0x0c0cc0bau; return 0; }
vf3_matrix_load(s,ram,2,r[6]+r[0]);
goto P_0c0cc0bc;
P_0c0cc0bc: /* original f376, guest PC 0x0c0cc0bc */
if(!s->budget--) { s->failed_pc=0x0c0cc0bcu; return 0; }
vf3_matrix_load(s,ram,3,r[7]+r[0]);
goto P_0c0cc0be;
P_0c0cc0be: /* original e01c, guest PC 0x0c0cc0be */
if(!s->budget--) { s->failed_pc=0x0c0cc0beu; return 0; }
r[0]=0x0000001cu;
goto P_0c0cc0c0;
P_0c0cc0c0: /* original f231, guest PC 0x0c0cc0c0 */
if(!s->budget--) { s->failed_pc=0x0c0cc0c0u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'-');
goto P_0c0cc0c2;
P_0c0cc0c2: /* original fe27, guest PC 0x0c0cc0c2 */
if(!s->budget--) { s->failed_pc=0x0c0cc0c2u; return 0; }
vf3_matrix_store(s,ram,2,r[14]+r[0]);
goto P_0c0cc0c4;
P_0c0cc0c4: /* original e008, guest PC 0x0c0cc0c4 */
if(!s->budget--) { s->failed_pc=0x0c0cc0c4u; return 0; }
r[0]=0x00000008u;
goto P_0c0cc0c6;
P_0c0cc0c6: /* original f266, guest PC 0x0c0cc0c6 */
if(!s->budget--) { s->failed_pc=0x0c0cc0c6u; return 0; }
vf3_matrix_load(s,ram,2,r[6]+r[0]);
goto P_0c0cc0c8;
P_0c0cc0c8: /* original f376, guest PC 0x0c0cc0c8 */
if(!s->budget--) { s->failed_pc=0x0c0cc0c8u; return 0; }
vf3_matrix_load(s,ram,3,r[7]+r[0]);
goto P_0c0cc0ca;
P_0c0cc0ca: /* original e020, guest PC 0x0c0cc0ca */
if(!s->budget--) { s->failed_pc=0x0c0cc0cau; return 0; }
r[0]=0x00000020u;
goto P_0c0cc0cc;
P_0c0cc0cc: /* original f231, guest PC 0x0c0cc0cc */
if(!s->budget--) { s->failed_pc=0x0c0cc0ccu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'-');
goto P_0c0cc0ce;
P_0c0cc0ce: /* original fe27, guest PC 0x0c0cc0ce */
if(!s->budget--) { s->failed_pc=0x0c0cc0ceu; return 0; }
vf3_matrix_store(s,ram,2,r[14]+r[0]);
goto P_0c0cc0d0;
P_0c0cc0d0: /* original 1e35, guest PC 0x0c0cc0d0 */
if(!s->budget--) { s->failed_pc=0x0c0cc0d0u; return 0; }
write(ram,r[14]+20,r[3],4);
goto P_0c0cc0d2;
P_0c0cc0d2: /* original 000b, guest PC 0x0c0cc0d2 */
if(!s->budget--) { s->failed_pc=0x0c0cc0d2u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0cc0d4: /* original 6ef6, guest PC 0x0c0cc0d4 */
if(!s->budget--) { s->failed_pc=0x0c0cc0d4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0cc0d6;
P_0c0cc0d6: /* original 2fe6, guest PC 0x0c0cc0d6 */
if(!s->budget--) { s->failed_pc=0x0c0cc0d6u; return 0; }
r[15]-=4; write(ram,r[15],r[14],4);
goto P_0c0cc0d8;
P_0c0cc0d8: /* original 2fd6, guest PC 0x0c0cc0d8 */
if(!s->budget--) { s->failed_pc=0x0c0cc0d8u; return 0; }
r[15]-=4; write(ram,r[15],r[13],4);
goto P_0c0cc0da;
P_0c0cc0da: /* original ed04, guest PC 0x0c0cc0da */
if(!s->budget--) { s->failed_pc=0x0c0cc0dau; return 0; }
r[13]=0x00000004u;
goto P_0c0cc0dc;
P_0c0cc0dc: /* original 4f22, guest PC 0x0c0cc0dc */
if(!s->budget--) { s->failed_pc=0x0c0cc0dcu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0cc0de;
P_0c0cc0de: /* original 54f3, guest PC 0x0c0cc0de */
if(!s->budget--) { s->failed_pc=0x0c0cc0deu; return 0; }
r[4]=read(ram,r[15]+12,4);
goto P_0c0cc0e0;
P_0c0cc0e0: /* original 5343, guest PC 0x0c0cc0e0 */
if(!s->budget--) { s->failed_pc=0x0c0cc0e0u; return 0; }
r[3]=read(ram,r[4]+12,4);
goto P_0c0cc0e2;
P_0c0cc0e2: /* original 33d7, guest PC 0x0c0cc0e2 */
if(!s->budget--) { s->failed_pc=0x0c0cc0e2u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>(int32_t)r[13])!=0);
goto P_0c0cc0e4;
P_0c0cc0e4: /* original 8902, guest PC 0x0c0cc0e4 */
if(!s->budget--) { s->failed_pc=0x0c0cc0e4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0cc0ec; }
goto P_0c0cc0e6;
P_0c0cc0e6: /* original 5143, guest PC 0x0c0cc0e6 */
if(!s->budget--) { s->failed_pc=0x0c0cc0e6u; return 0; }
r[1]=read(ram,r[4]+12,4);
goto P_0c0cc0e8;
P_0c0cc0e8: /* original 7101, guest PC 0x0c0cc0e8 */
if(!s->budget--) { s->failed_pc=0x0c0cc0e8u; return 0; }
r[1]+=0x00000001u;
goto P_0c0cc0ea;
P_0c0cc0ea: /* original 1413, guest PC 0x0c0cc0ea */
if(!s->budget--) { s->failed_pc=0x0c0cc0eau; return 0; }
write(ram,r[4]+12,r[1],4);
goto P_0c0cc0ec;
P_0c0cc0ec: /* original 8551, guest PC 0x0c0cc0ec */
if(!s->budget--) { s->failed_pc=0x0c0cc0ecu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[5]+2,2);
goto P_0c0cc0ee;
P_0c0cc0ee: /* original d39d, guest PC 0x0c0cc0ee */
if(!s->budget--) { s->failed_pc=0x0c0cc0eeu; return 0; }
r[3]=read(ram,0x0c0cc364u,4);
goto P_0c0cc0f0;
P_0c0cc0f0: /* original 6103, guest PC 0x0c0cc0f0 */
if(!s->budget--) { s->failed_pc=0x0c0cc0f0u; return 0; }
r[1]=r[0];
goto P_0c0cc0f2;
P_0c0cc0f2: /* original 6e03, guest PC 0x0c0cc0f2 */
if(!s->budget--) { s->failed_pc=0x0c0cc0f2u; return 0; }
r[14]=r[0];
goto P_0c0cc0f4;
P_0c0cc0f4: /* original 430b, guest PC 0x0c0cc0f4 */
if(!s->budget--) { s->failed_pc=0x0c0cc0f4u; return 0; }
target=r[3];
r[16]=0x0c0cc0f8u;
r[0]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0cc0f8u) { target=s->pc; goto dispatch; }
goto P_0c0cc0f8;
P_0c0cc0f6: /* original 60d3, guest PC 0x0c0cc0f6 */
if(!s->budget--) { s->failed_pc=0x0c0cc0f6u; return 0; }
r[0]=r[13];
goto P_0c0cc0f8;
P_0c0cc0f8: /* original 6303, guest PC 0x0c0cc0f8 */
if(!s->budget--) { s->failed_pc=0x0c0cc0f8u; return 0; }
r[3]=r[0];
goto P_0c0cc0fa;
P_0c0cc0fa: /* original 3e38, guest PC 0x0c0cc0fa */
if(!s->budget--) { s->failed_pc=0x0c0cc0fau; return 0; }
r[14]-=r[3];
goto P_0c0cc0fc;
P_0c0cc0fc: /* original 4e11, guest PC 0x0c0cc0fc */
if(!s->budget--) { s->failed_pc=0x0c0cc0fcu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[14]>=0)!=0);
goto P_0c0cc0fe;
P_0c0cc0fe: /* original 8d04, guest PC 0x0c0cc0fe */
if(!s->budget--) { s->failed_pc=0x0c0cc0feu; return 0; }
cond=r[17]&1u;
write(ram,r[4]+16,r[0],4);
if(cond) { goto P_0c0cc10a; }
goto P_0c0cc102;
P_0c0cc100: /* original 1404, guest PC 0x0c0cc100 */
if(!s->budget--) { s->failed_pc=0x0c0cc100u; return 0; }
write(ram,r[4]+16,r[0],4);
goto P_0c0cc102;
P_0c0cc102: /* original 5344, guest PC 0x0c0cc102 */
if(!s->budget--) { s->failed_pc=0x0c0cc102u; return 0; }
r[3]=read(ram,r[4]+16,4);
goto P_0c0cc104;
P_0c0cc104: /* original 33ec, guest PC 0x0c0cc104 */
if(!s->budget--) { s->failed_pc=0x0c0cc104u; return 0; }
r[3]+=r[14];
goto P_0c0cc106;
P_0c0cc106: /* original ee00, guest PC 0x0c0cc106 */
if(!s->budget--) { s->failed_pc=0x0c0cc106u; return 0; }
r[14]=0x00000000u;
goto P_0c0cc108;
P_0c0cc108: /* original 1434, guest PC 0x0c0cc108 */
if(!s->budget--) { s->failed_pc=0x0c0cc108u; return 0; }
write(ram,r[4]+16,r[3],4);
goto P_0c0cc10a;
P_0c0cc10a: /* original 60e3, guest PC 0x0c0cc10a */
if(!s->budget--) { s->failed_pc=0x0c0cc10au; return 0; }
r[0]=r[14];
goto P_0c0cc10c;
P_0c0cc10c: /* original 8151, guest PC 0x0c0cc10c */
if(!s->budget--) { s->failed_pc=0x0c0cc10cu; return 0; }
write(ram,r[5]+2,r[0],2);
goto P_0c0cc10e;
P_0c0cc10e: /* original f378, guest PC 0x0c0cc10e */
if(!s->budget--) { s->failed_pc=0x0c0cc10eu; return 0; }
vf3_matrix_load(s,ram,3,r[7]);
goto P_0c0cc110;
P_0c0cc110: /* original e018, guest PC 0x0c0cc110 */
if(!s->budget--) { s->failed_pc=0x0c0cc110u; return 0; }
r[0]=0x00000018u;
goto P_0c0cc112;
P_0c0cc112: /* original f268, guest PC 0x0c0cc112 */
if(!s->budget--) { s->failed_pc=0x0c0cc112u; return 0; }
vf3_matrix_load(s,ram,2,r[6]);
goto P_0c0cc114;
P_0c0cc114: /* original 4f26, guest PC 0x0c0cc114 */
if(!s->budget--) { s->failed_pc=0x0c0cc114u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0cc116;
P_0c0cc116: /* original f231, guest PC 0x0c0cc116 */
if(!s->budget--) { s->failed_pc=0x0c0cc116u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'-');
goto P_0c0cc118;
P_0c0cc118: /* original f427, guest PC 0x0c0cc118 */
if(!s->budget--) { s->failed_pc=0x0c0cc118u; return 0; }
vf3_matrix_store(s,ram,2,r[4]+r[0]);
goto P_0c0cc11a;
P_0c0cc11a: /* original e004, guest PC 0x0c0cc11a */
if(!s->budget--) { s->failed_pc=0x0c0cc11au; return 0; }
r[0]=0x00000004u;
goto P_0c0cc11c;
P_0c0cc11c: /* original f266, guest PC 0x0c0cc11c */
if(!s->budget--) { s->failed_pc=0x0c0cc11cu; return 0; }
vf3_matrix_load(s,ram,2,r[6]+r[0]);
goto P_0c0cc11e;
P_0c0cc11e: /* original f376, guest PC 0x0c0cc11e */
if(!s->budget--) { s->failed_pc=0x0c0cc11eu; return 0; }
vf3_matrix_load(s,ram,3,r[7]+r[0]);
goto P_0c0cc120;
P_0c0cc120: /* original e01c, guest PC 0x0c0cc120 */
if(!s->budget--) { s->failed_pc=0x0c0cc120u; return 0; }
r[0]=0x0000001cu;
goto P_0c0cc122;
P_0c0cc122: /* original f231, guest PC 0x0c0cc122 */
if(!s->budget--) { s->failed_pc=0x0c0cc122u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'-');
goto P_0c0cc124;
P_0c0cc124: /* original f427, guest PC 0x0c0cc124 */
if(!s->budget--) { s->failed_pc=0x0c0cc124u; return 0; }
vf3_matrix_store(s,ram,2,r[4]+r[0]);
goto P_0c0cc126;
P_0c0cc126: /* original e008, guest PC 0x0c0cc126 */
if(!s->budget--) { s->failed_pc=0x0c0cc126u; return 0; }
r[0]=0x00000008u;
goto P_0c0cc128;
P_0c0cc128: /* original f266, guest PC 0x0c0cc128 */
if(!s->budget--) { s->failed_pc=0x0c0cc128u; return 0; }
vf3_matrix_load(s,ram,2,r[6]+r[0]);
goto P_0c0cc12a;
P_0c0cc12a: /* original f376, guest PC 0x0c0cc12a */
if(!s->budget--) { s->failed_pc=0x0c0cc12au; return 0; }
vf3_matrix_load(s,ram,3,r[7]+r[0]);
goto P_0c0cc12c;
P_0c0cc12c: /* original e020, guest PC 0x0c0cc12c */
if(!s->budget--) { s->failed_pc=0x0c0cc12cu; return 0; }
r[0]=0x00000020u;
goto P_0c0cc12e;
P_0c0cc12e: /* original f231, guest PC 0x0c0cc12e */
if(!s->budget--) { s->failed_pc=0x0c0cc12eu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'-');
goto P_0c0cc130;
P_0c0cc130: /* original f427, guest PC 0x0c0cc130 */
if(!s->budget--) { s->failed_pc=0x0c0cc130u; return 0; }
vf3_matrix_store(s,ram,2,r[4]+r[0]);
goto P_0c0cc132;
P_0c0cc132: /* original 14d5, guest PC 0x0c0cc132 */
if(!s->budget--) { s->failed_pc=0x0c0cc132u; return 0; }
write(ram,r[4]+20,r[13],4);
goto P_0c0cc134;
P_0c0cc134: /* original 6df6, guest PC 0x0c0cc134 */
if(!s->budget--) { s->failed_pc=0x0c0cc134u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0cc136;
P_0c0cc136: /* original 000b, guest PC 0x0c0cc136 */
if(!s->budget--) { s->failed_pc=0x0c0cc136u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0cc138: /* original 6ef6, guest PC 0x0c0cc138 */
if(!s->budget--) { s->failed_pc=0x0c0cc138u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0cc13a;
P_0c0cc13a: /* original 2fe6, guest PC 0x0c0cc13a */
if(!s->budget--) { s->failed_pc=0x0c0cc13au; return 0; }
r[15]-=4; write(ram,r[15],r[14],4);
goto P_0c0cc13c;
P_0c0cc13c: /* original e004, guest PC 0x0c0cc13c */
if(!s->budget--) { s->failed_pc=0x0c0cc13cu; return 0; }
r[0]=0x00000004u;
goto P_0c0cc13e;
P_0c0cc13e: /* original 2fd6, guest PC 0x0c0cc13e */
if(!s->budget--) { s->failed_pc=0x0c0cc13eu; return 0; }
r[15]-=4; write(ram,r[15],r[13],4);
goto P_0c0cc140;
P_0c0cc140: /* original 6d43, guest PC 0x0c0cc140 */
if(!s->budget--) { s->failed_pc=0x0c0cc140u; return 0; }
r[13]=r[4];
goto P_0c0cc142;
P_0c0cc142: /* original 2fc6, guest PC 0x0c0cc142 */
if(!s->budget--) { s->failed_pc=0x0c0cc142u; return 0; }
r[15]-=4; write(ram,r[15],r[12],4);
goto P_0c0cc144;
P_0c0cc144: /* original 6e53, guest PC 0x0c0cc144 */
if(!s->budget--) { s->failed_pc=0x0c0cc144u; return 0; }
r[14]=r[5];
goto P_0c0cc146;
P_0c0cc146: /* original fffb, guest PC 0x0c0cc146 */
if(!s->budget--) { s->failed_pc=0x0c0cc146u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c0cc148;
P_0c0cc148: /* original 4f22, guest PC 0x0c0cc148 */
if(!s->budget--) { s->failed_pc=0x0c0cc148u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0cc14a;
P_0c0cc14a: /* original 7ff4, guest PC 0x0c0cc14a */
if(!s->budget--) { s->failed_pc=0x0c0cc14au; return 0; }
r[15]+=0xfffffff4u;
goto P_0c0cc14c;
P_0c0cc14c: /* original 2f62, guest PC 0x0c0cc14c */
if(!s->budget--) { s->failed_pc=0x0c0cc14cu; return 0; }
write(ram,r[15],r[6],4);
goto P_0c0cc14e;
P_0c0cc14e: /* original ff47, guest PC 0x0c0cc14e */
if(!s->budget--) { s->failed_pc=0x0c0cc14eu; return 0; }
vf3_matrix_store(s,ram,4,r[15]+r[0]);
goto P_0c0cc150;
P_0c0cc150: /* original 5cf8, guest PC 0x0c0cc150 */
if(!s->budget--) { s->failed_pc=0x0c0cc150u; return 0; }
r[12]=read(ram,r[15]+32,4);
goto P_0c0cc152;
P_0c0cc152: /* original d385, guest PC 0x0c0cc152 */
if(!s->budget--) { s->failed_pc=0x0c0cc152u; return 0; }
r[3]=read(ram,0x0c0cc368u,4);
goto P_0c0cc154;
P_0c0cc154: /* original 64cf, guest PC 0x0c0cc154 */
if(!s->budget--) { s->failed_pc=0x0c0cc154u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)r[12];
goto P_0c0cc156;
P_0c0cc156: /* original 430b, guest PC 0x0c0cc156 */
if(!s->budget--) { s->failed_pc=0x0c0cc156u; return 0; }
target=r[3];
r[16]=0x0c0cc15au;
write(ram,r[15]+8,r[4],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0cc15au) { target=s->pc; goto dispatch; }
goto P_0c0cc15a;
P_0c0cc158: /* original 1f42, guest PC 0x0c0cc158 */
if(!s->budget--) { s->failed_pc=0x0c0cc158u; return 0; }
write(ram,r[15]+8,r[4],4);
goto P_0c0cc15a;
P_0c0cc15a: /* original d384, guest PC 0x0c0cc15a */
if(!s->budget--) { s->failed_pc=0x0c0cc15au; return 0; }
r[3]=read(ram,0x0c0cc36cu,4);
goto P_0c0cc15c;
P_0c0cc15c: /* original ff0c, guest PC 0x0c0cc15c */
if(!s->budget--) { s->failed_pc=0x0c0cc15cu; return 0; }
vf3_matrix_move(s,15,0);
goto P_0c0cc15e;
P_0c0cc15e: /* original 430b, guest PC 0x0c0cc15e */
if(!s->budget--) { s->failed_pc=0x0c0cc15eu; return 0; }
target=r[3];
r[16]=0x0c0cc162u;
r[4]=read(ram,r[15]+8,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0cc162u) { target=s->pc; goto dispatch; }
goto P_0c0cc162;
P_0c0cc160: /* original 54f2, guest PC 0x0c0cc160 */
if(!s->budget--) { s->failed_pc=0x0c0cc160u; return 0; }
r[4]=read(ram,r[15]+8,4);
goto P_0c0cc162;
P_0c0cc162: /* original e018, guest PC 0x0c0cc162 */
if(!s->budget--) { s->failed_pc=0x0c0cc162u; return 0; }
r[0]=0x00000018u;
goto P_0c0cc164;
P_0c0cc164: /* original f40c, guest PC 0x0c0cc164 */
if(!s->budget--) { s->failed_pc=0x0c0cc164u; return 0; }
vf3_matrix_move(s,4,0);
goto P_0c0cc166;
P_0c0cc166: /* original f5e6, guest PC 0x0c0cc166 */
if(!s->budget--) { s->failed_pc=0x0c0cc166u; return 0; }
vf3_matrix_load(s,ram,5,r[14]+r[0]);
goto P_0c0cc168;
P_0c0cc168: /* original e020, guest PC 0x0c0cc168 */
if(!s->budget--) { s->failed_pc=0x0c0cc168u; return 0; }
r[0]=0x00000020u;
goto P_0c0cc16a;
P_0c0cc16a: /* original f30c, guest PC 0x0c0cc16a */
if(!s->budget--) { s->failed_pc=0x0c0cc16au; return 0; }
vf3_matrix_move(s,3,0);
goto P_0c0cc16c;
P_0c0cc16c: /* original e40f, guest PC 0x0c0cc16c */
if(!s->budget--) { s->failed_pc=0x0c0cc16cu; return 0; }
r[4]=0x0000000fu;
goto P_0c0cc16e;
P_0c0cc16e: /* original f65c, guest PC 0x0c0cc16e */
if(!s->budget--) { s->failed_pc=0x0c0cc16eu; return 0; }
vf3_matrix_move(s,6,5);
goto P_0c0cc170;
P_0c0cc170: /* original f642, guest PC 0x0c0cc170 */
if(!s->budget--) { s->failed_pc=0x0c0cc170u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[4],r[18],'*');
goto P_0c0cc172;
P_0c0cc172: /* original f85c, guest PC 0x0c0cc172 */
if(!s->budget--) { s->failed_pc=0x0c0cc172u; return 0; }
vf3_matrix_move(s,8,5);
goto P_0c0cc174;
P_0c0cc174: /* original f8f2, guest PC 0x0c0cc174 */
if(!s->budget--) { s->failed_pc=0x0c0cc174u; return 0; }
fr[8]=vf3_fpu_binary(fr[8],fr[15],r[18],'*');
goto P_0c0cc176;
P_0c0cc176: /* original f5e6, guest PC 0x0c0cc176 */
if(!s->budget--) { s->failed_pc=0x0c0cc176u; return 0; }
vf3_matrix_load(s,ram,5,r[14]+r[0]);
goto P_0c0cc178;
P_0c0cc178: /* original 24c9, guest PC 0x0c0cc178 */
if(!s->budget--) { s->failed_pc=0x0c0cc178u; return 0; }
r[4]&=r[12];
goto P_0c0cc17a;
P_0c0cc17a: /* original e018, guest PC 0x0c0cc17a */
if(!s->budget--) { s->failed_pc=0x0c0cc17au; return 0; }
r[0]=0x00000018u;
goto P_0c0cc17c;
P_0c0cc17c: /* original 6543, guest PC 0x0c0cc17c */
if(!s->budget--) { s->failed_pc=0x0c0cc17cu; return 0; }
r[5]=r[4];
goto P_0c0cc17e;
P_0c0cc17e: /* original f75c, guest PC 0x0c0cc17e */
if(!s->budget--) { s->failed_pc=0x0c0cc17eu; return 0; }
vf3_matrix_move(s,7,5);
goto P_0c0cc180;
P_0c0cc180: /* original f7f2, guest PC 0x0c0cc180 */
if(!s->budget--) { s->failed_pc=0x0c0cc180u; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[15],r[18],'*');
goto P_0c0cc182;
P_0c0cc182: /* original f45c, guest PC 0x0c0cc182 */
if(!s->budget--) { s->failed_pc=0x0c0cc182u; return 0; }
vf3_matrix_move(s,4,5);
goto P_0c0cc184;
P_0c0cc184: /* original f432, guest PC 0x0c0cc184 */
if(!s->budget--) { s->failed_pc=0x0c0cc184u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'*');
goto P_0c0cc186;
P_0c0cc186: /* original 7512, guest PC 0x0c0cc186 */
if(!s->budget--) { s->failed_pc=0x0c0cc186u; return 0; }
r[5]+=0x00000012u;
goto P_0c0cc188;
P_0c0cc188: /* original f671, guest PC 0x0c0cc188 */
if(!s->budget--) { s->failed_pc=0x0c0cc188u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[7],r[18],'-');
goto P_0c0cc18a;
P_0c0cc18a: /* original f840, guest PC 0x0c0cc18a */
if(!s->budget--) { s->failed_pc=0x0c0cc18au; return 0; }
fr[8]=vf3_fpu_binary(fr[8],fr[4],r[18],'+');
goto P_0c0cc18c;
P_0c0cc18c: /* original fe67, guest PC 0x0c0cc18c */
if(!s->budget--) { s->failed_pc=0x0c0cc18cu; return 0; }
vf3_matrix_store(s,ram,6,r[14]+r[0]);
goto P_0c0cc18e;
P_0c0cc18e: /* original e020, guest PC 0x0c0cc18e */
if(!s->budget--) { s->failed_pc=0x0c0cc18eu; return 0; }
r[0]=0x00000020u;
goto P_0c0cc190;
P_0c0cc190: /* original fe87, guest PC 0x0c0cc190 */
if(!s->budget--) { s->failed_pc=0x0c0cc190u; return 0; }
vf3_matrix_store(s,ram,8,r[14]+r[0]);
goto P_0c0cc192;
P_0c0cc192: /* original 6053, guest PC 0x0c0cc192 */
if(!s->budget--) { s->failed_pc=0x0c0cc192u; return 0; }
r[0]=r[5];
goto P_0c0cc194;
P_0c0cc194: /* original f49d, guest PC 0x0c0cc194 */
if(!s->budget--) { s->failed_pc=0x0c0cc194u; return 0; }
fr[4]=0x3f800000u;
goto P_0c0cc196;
P_0c0cc196: /* original 81df, guest PC 0x0c0cc196 */
if(!s->budget--) { s->failed_pc=0x0c0cc196u; return 0; }
write(ram,r[13]+30,r[0],2);
goto P_0c0cc198;
P_0c0cc198: /* original c775, guest PC 0x0c0cc198 */
if(!s->budget--) { s->failed_pc=0x0c0cc198u; return 0; }
r[0]=0x0c0cc370u;
goto P_0c0cc19a;
P_0c0cc19a: /* original 445a, guest PC 0x0c0cc19a */
if(!s->budget--) { s->failed_pc=0x0c0cc19au; return 0; }
r[53]=r[4];
goto P_0c0cc19c;
P_0c0cc19c: /* original f24c, guest PC 0x0c0cc19c */
if(!s->budget--) { s->failed_pc=0x0c0cc19cu; return 0; }
vf3_matrix_move(s,2,4);
goto P_0c0cc19e;
P_0c0cc19e: /* original f32d, guest PC 0x0c0cc19e */
if(!s->budget--) { s->failed_pc=0x0c0cc19eu; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c0cc1a0;
P_0c0cc1a0: /* original f53c, guest PC 0x0c0cc1a0 */
if(!s->budget--) { s->failed_pc=0x0c0cc1a0u; return 0; }
vf3_matrix_move(s,5,3);
goto P_0c0cc1a2;
P_0c0cc1a2: /* original f008, guest PC 0x0c0cc1a2 */
if(!s->budget--) { s->failed_pc=0x0c0cc1a2u; return 0; }
vf3_matrix_load(s,ram,0,r[0]);
goto P_0c0cc1a4;
P_0c0cc1a4: /* original e024, guest PC 0x0c0cc1a4 */
if(!s->budget--) { s->failed_pc=0x0c0cc1a4u; return 0; }
r[0]=0x00000024u;
goto P_0c0cc1a6;
P_0c0cc1a6: /* original f3e6, guest PC 0x0c0cc1a6 */
if(!s->budget--) { s->failed_pc=0x0c0cc1a6u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c0cc1a8;
P_0c0cc1a8: /* original e018, guest PC 0x0c0cc1a8 */
if(!s->budget--) { s->failed_pc=0x0c0cc1a8u; return 0; }
r[0]=0x00000018u;
goto P_0c0cc1aa;
P_0c0cc1aa: /* original f25e, guest PC 0x0c0cc1aa */
if(!s->budget--) { s->failed_pc=0x0c0cc1aau; return 0; }
fr[2]=vf3_fpu_mac(fr[0],fr[5],fr[2],r[18]);
goto P_0c0cc1ac;
P_0c0cc1ac: /* original 63f2, guest PC 0x0c0cc1ac */
if(!s->budget--) { s->failed_pc=0x0c0cc1acu; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c0cc1ae;
P_0c0cc1ae: /* original 64cc, guest PC 0x0c0cc1ae */
if(!s->budget--) { s->failed_pc=0x0c0cc1aeu; return 0; }
r[4]=r[12]&255u;
goto P_0c0cc1b0;
P_0c0cc1b0: /* original f538, guest PC 0x0c0cc1b0 */
if(!s->budget--) { s->failed_pc=0x0c0cc1b0u; return 0; }
vf3_matrix_load(s,ram,5,r[3]);
goto P_0c0cc1b2;
P_0c0cc1b2: /* original f42c, guest PC 0x0c0cc1b2 */
if(!s->budget--) { s->failed_pc=0x0c0cc1b2u; return 0; }
vf3_matrix_move(s,4,2);
goto P_0c0cc1b4;
P_0c0cc1b4: /* original f432, guest PC 0x0c0cc1b4 */
if(!s->budget--) { s->failed_pc=0x0c0cc1b4u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'*');
goto P_0c0cc1b6;
P_0c0cc1b6: /* original f3e6, guest PC 0x0c0cc1b6 */
if(!s->budget--) { s->failed_pc=0x0c0cc1b6u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c0cc1b8;
P_0c0cc1b8: /* original e008, guest PC 0x0c0cc1b8 */
if(!s->budget--) { s->failed_pc=0x0c0cc1b8u; return 0; }
r[0]=0x00000008u;
goto P_0c0cc1ba;
P_0c0cc1ba: /* original f04c, guest PC 0x0c0cc1ba */
if(!s->budget--) { s->failed_pc=0x0c0cc1bau; return 0; }
vf3_matrix_move(s,0,4);
goto P_0c0cc1bc;
P_0c0cc1bc: /* original f53e, guest PC 0x0c0cc1bc */
if(!s->budget--) { s->failed_pc=0x0c0cc1bcu; return 0; }
fr[5]=vf3_fpu_mac(fr[0],fr[3],fr[5],r[18]);
goto P_0c0cc1be;
P_0c0cc1be: /* original f336, guest PC 0x0c0cc1be */
if(!s->budget--) { s->failed_pc=0x0c0cc1beu; return 0; }
vf3_matrix_load(s,ram,3,r[3]+r[0]);
goto P_0c0cc1c0;
P_0c0cc1c0: /* original e020, guest PC 0x0c0cc1c0 */
if(!s->budget--) { s->failed_pc=0x0c0cc1c0u; return 0; }
r[0]=0x00000020u;
goto P_0c0cc1c2;
P_0c0cc1c2: /* original f2e6, guest PC 0x0c0cc1c2 */
if(!s->budget--) { s->failed_pc=0x0c0cc1c2u; return 0; }
vf3_matrix_load(s,ram,2,r[14]+r[0]);
goto P_0c0cc1c4;
P_0c0cc1c4: /* original e004, guest PC 0x0c0cc1c4 */
if(!s->budget--) { s->failed_pc=0x0c0cc1c4u; return 0; }
r[0]=0x00000004u;
goto P_0c0cc1c6;
P_0c0cc1c6: /* original f32e, guest PC 0x0c0cc1c6 */
if(!s->budget--) { s->failed_pc=0x0c0cc1c6u; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[2],fr[3],r[18]);
goto P_0c0cc1c8;
P_0c0cc1c8: /* original f43c, guest PC 0x0c0cc1c8 */
if(!s->budget--) { s->failed_pc=0x0c0cc1c8u; return 0; }
vf3_matrix_move(s,4,3);
goto P_0c0cc1ca;
P_0c0cc1ca: /* original fd5a, guest PC 0x0c0cc1ca */
if(!s->budget--) { s->failed_pc=0x0c0cc1cau; return 0; }
vf3_matrix_store(s,ram,5,r[13]);
goto P_0c0cc1cc;
P_0c0cc1cc: /* original f3f6, guest PC 0x0c0cc1cc */
if(!s->budget--) { s->failed_pc=0x0c0cc1ccu; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0cc1ce;
P_0c0cc1ce: /* original e004, guest PC 0x0c0cc1ce */
if(!s->budget--) { s->failed_pc=0x0c0cc1ceu; return 0; }
r[0]=0x00000004u;
goto P_0c0cc1d0;
P_0c0cc1d0: /* original fd37, guest PC 0x0c0cc1d0 */
if(!s->budget--) { s->failed_pc=0x0c0cc1d0u; return 0; }
vf3_matrix_store(s,ram,3,r[13]+r[0]);
goto P_0c0cc1d2;
P_0c0cc1d2: /* original e008, guest PC 0x0c0cc1d2 */
if(!s->budget--) { s->failed_pc=0x0c0cc1d2u; return 0; }
r[0]=0x00000008u;
goto P_0c0cc1d4;
P_0c0cc1d4: /* original f44d, guest PC 0x0c0cc1d4 */
if(!s->budget--) { s->failed_pc=0x0c0cc1d4u; return 0; }
fr[4]^=0x80000000u;
goto P_0c0cc1d6;
P_0c0cc1d6: /* original fd47, guest PC 0x0c0cc1d6 */
if(!s->budget--) { s->failed_pc=0x0c0cc1d6u; return 0; }
vf3_matrix_store(s,ram,4,r[13]+r[0]);
goto P_0c0cc1d8;
P_0c0cc1d8: /* original c766, guest PC 0x0c0cc1d8 */
if(!s->budget--) { s->failed_pc=0x0c0cc1d8u; return 0; }
r[0]=0x0c0cc374u;
goto P_0c0cc1da;
P_0c0cc1da: /* original 445a, guest PC 0x0c0cc1da */
if(!s->budget--) { s->failed_pc=0x0c0cc1dau; return 0; }
r[53]=r[4];
goto P_0c0cc1dc;
P_0c0cc1dc: /* original f508, guest PC 0x0c0cc1dc */
if(!s->budget--) { s->failed_pc=0x0c0cc1dcu; return 0; }
vf3_matrix_load(s,ram,5,r[0]);
goto P_0c0cc1de;
P_0c0cc1de: /* original f32d, guest PC 0x0c0cc1de */
if(!s->budget--) { s->failed_pc=0x0c0cc1deu; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c0cc1e0;
P_0c0cc1e0: /* original f43c, guest PC 0x0c0cc1e0 */
if(!s->budget--) { s->failed_pc=0x0c0cc1e0u; return 0; }
vf3_matrix_move(s,4,3);
goto P_0c0cc1e2;
P_0c0cc1e2: /* original f35c, guest PC 0x0c0cc1e2 */
if(!s->budget--) { s->failed_pc=0x0c0cc1e2u; return 0; }
vf3_matrix_move(s,3,5);
goto P_0c0cc1e4;
P_0c0cc1e4: /* original c764, guest PC 0x0c0cc1e4 */
if(!s->budget--) { s->failed_pc=0x0c0cc1e4u; return 0; }
r[0]=0x0c0cc378u;
goto P_0c0cc1e6;
P_0c0cc1e6: /* original f54c, guest PC 0x0c0cc1e6 */
if(!s->budget--) { s->failed_pc=0x0c0cc1e6u; return 0; }
vf3_matrix_move(s,5,4);
goto P_0c0cc1e8;
P_0c0cc1e8: /* original f532, guest PC 0x0c0cc1e8 */
if(!s->budget--) { s->failed_pc=0x0c0cc1e8u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[3],r[18],'*');
goto P_0c0cc1ea;
P_0c0cc1ea: /* original f408, guest PC 0x0c0cc1ea */
if(!s->budget--) { s->failed_pc=0x0c0cc1eau; return 0; }
vf3_matrix_load(s,ram,4,r[0]);
goto P_0c0cc1ec;
P_0c0cc1ec: /* original e018, guest PC 0x0c0cc1ec */
if(!s->budget--) { s->failed_pc=0x0c0cc1ecu; return 0; }
r[0]=0x00000018u;
goto P_0c0cc1ee;
P_0c0cc1ee: /* original f3e6, guest PC 0x0c0cc1ee */
if(!s->budget--) { s->failed_pc=0x0c0cc1eeu; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c0cc1f0;
P_0c0cc1f0: /* original e00c, guest PC 0x0c0cc1f0 */
if(!s->budget--) { s->failed_pc=0x0c0cc1f0u; return 0; }
r[0]=0x0000000cu;
goto P_0c0cc1f2;
P_0c0cc1f2: /* original 7f0c, guest PC 0x0c0cc1f2 */
if(!s->budget--) { s->failed_pc=0x0c0cc1f2u; return 0; }
r[15]+=0x0000000cu;
goto P_0c0cc1f4;
P_0c0cc1f4: /* original f450, guest PC 0x0c0cc1f4 */
if(!s->budget--) { s->failed_pc=0x0c0cc1f4u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[5],r[18],'+');
goto P_0c0cc1f6;
P_0c0cc1f6: /* original 4f26, guest PC 0x0c0cc1f6 */
if(!s->budget--) { s->failed_pc=0x0c0cc1f6u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0cc1f8;
P_0c0cc1f8: /* original f342, guest PC 0x0c0cc1f8 */
if(!s->budget--) { s->failed_pc=0x0c0cc1f8u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'*');
goto P_0c0cc1fa;
P_0c0cc1fa: /* original fd37, guest PC 0x0c0cc1fa */
if(!s->budget--) { s->failed_pc=0x0c0cc1fau; return 0; }
vf3_matrix_store(s,ram,3,r[13]+r[0]);
goto P_0c0cc1fc;
P_0c0cc1fc: /* original e01c, guest PC 0x0c0cc1fc */
if(!s->budget--) { s->failed_pc=0x0c0cc1fcu; return 0; }
r[0]=0x0000001cu;
goto P_0c0cc1fe;
P_0c0cc1fe: /* original f3e6, guest PC 0x0c0cc1fe */
if(!s->budget--) { s->failed_pc=0x0c0cc1feu; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c0cc200;
P_0c0cc200: /* original e010, guest PC 0x0c0cc200 */
if(!s->budget--) { s->failed_pc=0x0c0cc200u; return 0; }
r[0]=0x00000010u;
goto P_0c0cc202;
P_0c0cc202: /* original f342, guest PC 0x0c0cc202 */
if(!s->budget--) { s->failed_pc=0x0c0cc202u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'*');
goto P_0c0cc204;
P_0c0cc204: /* original fd37, guest PC 0x0c0cc204 */
if(!s->budget--) { s->failed_pc=0x0c0cc204u; return 0; }
vf3_matrix_store(s,ram,3,r[13]+r[0]);
goto P_0c0cc206;
P_0c0cc206: /* original e020, guest PC 0x0c0cc206 */
if(!s->budget--) { s->failed_pc=0x0c0cc206u; return 0; }
r[0]=0x00000020u;
goto P_0c0cc208;
P_0c0cc208: /* original f3e6, guest PC 0x0c0cc208 */
if(!s->budget--) { s->failed_pc=0x0c0cc208u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c0cc20a;
P_0c0cc20a: /* original e014, guest PC 0x0c0cc20a */
if(!s->budget--) { s->failed_pc=0x0c0cc20au; return 0; }
r[0]=0x00000014u;
goto P_0c0cc20c;
P_0c0cc20c: /* original f342, guest PC 0x0c0cc20c */
if(!s->budget--) { s->failed_pc=0x0c0cc20cu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'*');
goto P_0c0cc20e;
P_0c0cc20e: /* original fd37, guest PC 0x0c0cc20e */
if(!s->budget--) { s->failed_pc=0x0c0cc20eu; return 0; }
vf3_matrix_store(s,ram,3,r[13]+r[0]);
goto P_0c0cc210;
P_0c0cc210: /* original fff9, guest PC 0x0c0cc210 */
if(!s->budget--) { s->failed_pc=0x0c0cc210u; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0cc212;
P_0c0cc212: /* original 6cf6, guest PC 0x0c0cc212 */
if(!s->budget--) { s->failed_pc=0x0c0cc212u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0cc214;
P_0c0cc214: /* original 6df6, guest PC 0x0c0cc214 */
if(!s->budget--) { s->failed_pc=0x0c0cc214u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0cc216;
P_0c0cc216: /* original 000b, guest PC 0x0c0cc216 */
if(!s->budget--) { s->failed_pc=0x0c0cc216u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0cc218: /* original 6ef6, guest PC 0x0c0cc218 */
if(!s->budget--) { s->failed_pc=0x0c0cc218u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0cc21a;
P_0c0cc21a: /* original 2fe6, guest PC 0x0c0cc21a */
if(!s->budget--) { s->failed_pc=0x0c0cc21au; return 0; }
r[15]-=4; write(ram,r[15],r[14],4);
goto P_0c0cc21c;
P_0c0cc21c: /* original ee1f, guest PC 0x0c0cc21c */
if(!s->budget--) { s->failed_pc=0x0c0cc21cu; return 0; }
r[14]=0x0000001fu;
goto P_0c0cc21e;
P_0c0cc21e: /* original 7ffc, guest PC 0x0c0cc21e */
if(!s->budget--) { s->failed_pc=0x0c0cc21eu; return 0; }
r[15]+=0xfffffffcu;
goto P_0c0cc220;
P_0c0cc220: /* original 5253, guest PC 0x0c0cc220 */
if(!s->budget--) { s->failed_pc=0x0c0cc220u; return 0; }
r[2]=read(ram,r[5]+12,4);
goto P_0c0cc222;
P_0c0cc222: /* original 56f2, guest PC 0x0c0cc222 */
if(!s->budget--) { s->failed_pc=0x0c0cc222u; return 0; }
r[6]=read(ram,r[15]+8,4);
goto P_0c0cc224;
P_0c0cc224: /* original c752, guest PC 0x0c0cc224 */
if(!s->budget--) { s->failed_pc=0x0c0cc224u; return 0; }
r[0]=0x0c0cc370u;
goto P_0c0cc226;
P_0c0cc226: /* original f508, guest PC 0x0c0cc226 */
if(!s->budget--) { s->failed_pc=0x0c0cc226u; return 0; }
vf3_matrix_load(s,ram,5,r[0]);
goto P_0c0cc228;
P_0c0cc228: /* original e3fb, guest PC 0x0c0cc228 */
if(!s->budget--) { s->failed_pc=0x0c0cc228u; return 0; }
r[3]=0xfffffffbu;
goto P_0c0cc22a;
P_0c0cc22a: /* original 6163, guest PC 0x0c0cc22a */
if(!s->budget--) { s->failed_pc=0x0c0cc22au; return 0; }
r[1]=r[6];
goto P_0c0cc22c;
P_0c0cc22c: /* original 21e9, guest PC 0x0c0cc22c */
if(!s->budget--) { s->failed_pc=0x0c0cc22cu; return 0; }
r[1]&=r[14];
goto P_0c0cc22e;
P_0c0cc22e: /* original 71f0, guest PC 0x0c0cc22e */
if(!s->budget--) { s->failed_pc=0x0c0cc22eu; return 0; }
r[1]+=0xfffffff0u;
goto P_0c0cc230;
P_0c0cc230: /* original 6063, guest PC 0x0c0cc230 */
if(!s->budget--) { s->failed_pc=0x0c0cc230u; return 0; }
r[0]=r[6];
goto P_0c0cc232;
P_0c0cc232: /* original 415a, guest PC 0x0c0cc232 */
if(!s->budget--) { s->failed_pc=0x0c0cc232u; return 0; }
r[53]=r[1];
goto P_0c0cc234;
P_0c0cc234: /* original 2228, guest PC 0x0c0cc234 */
if(!s->budget--) { s->failed_pc=0x0c0cc234u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c0cc236;
P_0c0cc236: /* original 403c, guest PC 0x0c0cc236 */
if(!s->budget--) { s->failed_pc=0x0c0cc236u; return 0; }
r[0]=(r[3]&0x80000000u)?((r[3]&31u)?(uint32_t)((int32_t)r[0]>>((-r[3])&31u)):((int32_t)r[0]<0?0xffffffffu:0)):r[0]<<(r[3]&31u);
goto P_0c0cc238;
P_0c0cc238: /* original e10f, guest PC 0x0c0cc238 */
if(!s->budget--) { s->failed_pc=0x0c0cc238u; return 0; }
r[1]=0x0000000fu;
goto P_0c0cc23a;
P_0c0cc23a: /* original f32d, guest PC 0x0c0cc23a */
if(!s->budget--) { s->failed_pc=0x0c0cc23au; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c0cc23c;
P_0c0cc23c: /* original f43c, guest PC 0x0c0cc23c */
if(!s->budget--) { s->failed_pc=0x0c0cc23cu; return 0; }
vf3_matrix_move(s,4,3);
goto P_0c0cc23e;
P_0c0cc23e: /* original f452, guest PC 0x0c0cc23e */
if(!s->budget--) { s->failed_pc=0x0c0cc23eu; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[5],r[18],'*');
goto P_0c0cc240;
P_0c0cc240: /* original 8f02, guest PC 0x0c0cc240 */
if(!s->budget--) { s->failed_pc=0x0c0cc240u; return 0; }
cond=r[17]&1u;
r[1]&=r[0];
if(!cond) { goto P_0c0cc248; }
goto P_0c0cc244;
P_0c0cc242: /* original 2109, guest PC 0x0c0cc242 */
if(!s->budget--) { s->failed_pc=0x0c0cc242u; return 0; }
r[1]&=r[0];
goto P_0c0cc244;
P_0c0cc244: /* original a001, guest PC 0x0c0cc244 */
if(!s->budget--) { s->failed_pc=0x0c0cc244u; return 0; }
r[0]=0x00000007u;
goto P_0c0cc24a;
P_0c0cc246: /* original e007, guest PC 0x0c0cc246 */
if(!s->budget--) { s->failed_pc=0x0c0cc246u; return 0; }
r[0]=0x00000007u;
goto P_0c0cc248;
P_0c0cc248: /* original e0f1, guest PC 0x0c0cc248 */
if(!s->budget--) { s->failed_pc=0x0c0cc248u; return 0; }
r[0]=0xfffffff1u;
goto P_0c0cc24a;
P_0c0cc24a: /* original 310c, guest PC 0x0c0cc24a */
if(!s->budget--) { s->failed_pc=0x0c0cc24au; return 0; }
r[1]+=r[0];
goto P_0c0cc24c;
P_0c0cc24c: /* original 415a, guest PC 0x0c0cc24c */
if(!s->budget--) { s->failed_pc=0x0c0cc24cu; return 0; }
r[53]=r[1];
goto P_0c0cc24e;
P_0c0cc24e: /* original 6163, guest PC 0x0c0cc24e */
if(!s->budget--) { s->failed_pc=0x0c0cc24eu; return 0; }
r[1]=r[6];
goto P_0c0cc250;
P_0c0cc250: /* original e3f6, guest PC 0x0c0cc250 */
if(!s->budget--) { s->failed_pc=0x0c0cc250u; return 0; }
r[3]=0xfffffff6u;
goto P_0c0cc252;
P_0c0cc252: /* original 413c, guest PC 0x0c0cc252 */
if(!s->budget--) { s->failed_pc=0x0c0cc252u; return 0; }
r[1]=(r[3]&0x80000000u)?((r[3]&31u)?(uint32_t)((int32_t)r[1]>>((-r[3])&31u)):((int32_t)r[1]<0?0xffffffffu:0)):r[1]<<(r[3]&31u);
goto P_0c0cc254;
P_0c0cc254: /* original f32d, guest PC 0x0c0cc254 */
if(!s->budget--) { s->failed_pc=0x0c0cc254u; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c0cc256;
P_0c0cc256: /* original 21e9, guest PC 0x0c0cc256 */
if(!s->budget--) { s->failed_pc=0x0c0cc256u; return 0; }
r[1]&=r[14];
goto P_0c0cc258;
P_0c0cc258: /* original 71f0, guest PC 0x0c0cc258 */
if(!s->budget--) { s->failed_pc=0x0c0cc258u; return 0; }
r[1]+=0xfffffff0u;
goto P_0c0cc25a;
P_0c0cc25a: /* original 415a, guest PC 0x0c0cc25a */
if(!s->budget--) { s->failed_pc=0x0c0cc25au; return 0; }
r[53]=r[1];
goto P_0c0cc25c;
P_0c0cc25c: /* original 636c, guest PC 0x0c0cc25c */
if(!s->budget--) { s->failed_pc=0x0c0cc25cu; return 0; }
r[3]=r[6]&255u;
goto P_0c0cc25e;
P_0c0cc25e: /* original c745, guest PC 0x0c0cc25e */
if(!s->budget--) { s->failed_pc=0x0c0cc25eu; return 0; }
r[0]=0x0c0cc374u;
goto P_0c0cc260;
P_0c0cc260: /* original f73c, guest PC 0x0c0cc260 */
if(!s->budget--) { s->failed_pc=0x0c0cc260u; return 0; }
vf3_matrix_move(s,7,3);
goto P_0c0cc262;
P_0c0cc262: /* original f32d, guest PC 0x0c0cc262 */
if(!s->budget--) { s->failed_pc=0x0c0cc262u; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c0cc264;
P_0c0cc264: /* original f752, guest PC 0x0c0cc264 */
if(!s->budget--) { s->failed_pc=0x0c0cc264u; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[5],r[18],'*');
goto P_0c0cc266;
P_0c0cc266: /* original f63c, guest PC 0x0c0cc266 */
if(!s->budget--) { s->failed_pc=0x0c0cc266u; return 0; }
vf3_matrix_move(s,6,3);
goto P_0c0cc268;
P_0c0cc268: /* original f652, guest PC 0x0c0cc268 */
if(!s->budget--) { s->failed_pc=0x0c0cc268u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[5],r[18],'*');
goto P_0c0cc26a;
P_0c0cc26a: /* original 2f32, guest PC 0x0c0cc26a */
if(!s->budget--) { s->failed_pc=0x0c0cc26au; return 0; }
write(ram,r[15],r[3],4);
goto P_0c0cc26c;
P_0c0cc26c: /* original 435a, guest PC 0x0c0cc26c */
if(!s->budget--) { s->failed_pc=0x0c0cc26cu; return 0; }
r[53]=r[3];
goto P_0c0cc26e;
P_0c0cc26e: /* original f32d, guest PC 0x0c0cc26e */
if(!s->budget--) { s->failed_pc=0x0c0cc26eu; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c0cc270;
P_0c0cc270: /* original f53c, guest PC 0x0c0cc270 */
if(!s->budget--) { s->failed_pc=0x0c0cc270u; return 0; }
vf3_matrix_move(s,5,3);
goto P_0c0cc272;
P_0c0cc272: /* original f308, guest PC 0x0c0cc272 */
if(!s->budget--) { s->failed_pc=0x0c0cc272u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c0cc274;
P_0c0cc274: /* original e018, guest PC 0x0c0cc274 */
if(!s->budget--) { s->failed_pc=0x0c0cc274u; return 0; }
r[0]=0x00000018u;
goto P_0c0cc276;
P_0c0cc276: /* original f856, guest PC 0x0c0cc276 */
if(!s->budget--) { s->failed_pc=0x0c0cc276u; return 0; }
vf3_matrix_load(s,ram,8,r[5]+r[0]);
goto P_0c0cc278;
P_0c0cc278: /* original e01c, guest PC 0x0c0cc278 */
if(!s->budget--) { s->failed_pc=0x0c0cc278u; return 0; }
r[0]=0x0000001cu;
goto P_0c0cc27a;
P_0c0cc27a: /* original f532, guest PC 0x0c0cc27a */
if(!s->budget--) { s->failed_pc=0x0c0cc27au; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[3],r[18],'*');
goto P_0c0cc27c;
P_0c0cc27c: /* original f956, guest PC 0x0c0cc27c */
if(!s->budget--) { s->failed_pc=0x0c0cc27cu; return 0; }
vf3_matrix_load(s,ram,9,r[5]+r[0]);
goto P_0c0cc27e;
P_0c0cc27e: /* original e020, guest PC 0x0c0cc27e */
if(!s->budget--) { s->failed_pc=0x0c0cc27eu; return 0; }
r[0]=0x00000020u;
goto P_0c0cc280;
P_0c0cc280: /* original f25c, guest PC 0x0c0cc280 */
if(!s->budget--) { s->failed_pc=0x0c0cc280u; return 0; }
vf3_matrix_move(s,2,5);
goto P_0c0cc282;
P_0c0cc282: /* original f952, guest PC 0x0c0cc282 */
if(!s->budget--) { s->failed_pc=0x0c0cc282u; return 0; }
fr[9]=vf3_fpu_binary(fr[9],fr[5],r[18],'*');
goto P_0c0cc284;
P_0c0cc284: /* original f852, guest PC 0x0c0cc284 */
if(!s->budget--) { s->failed_pc=0x0c0cc284u; return 0; }
fr[8]=vf3_fpu_binary(fr[8],fr[5],r[18],'*');
goto P_0c0cc286;
P_0c0cc286: /* original f556, guest PC 0x0c0cc286 */
if(!s->budget--) { s->failed_pc=0x0c0cc286u; return 0; }
vf3_matrix_load(s,ram,5,r[5]+r[0]);
goto P_0c0cc288;
P_0c0cc288: /* original f522, guest PC 0x0c0cc288 */
if(!s->budget--) { s->failed_pc=0x0c0cc288u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[2],r[18],'*');
goto P_0c0cc28a;
P_0c0cc28a: /* original e00c, guest PC 0x0c0cc28a */
if(!s->budget--) { s->failed_pc=0x0c0cc28au; return 0; }
r[0]=0x0000000cu;
goto P_0c0cc28c;
P_0c0cc28c: /* original f480, guest PC 0x0c0cc28c */
if(!s->budget--) { s->failed_pc=0x0c0cc28cu; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[8],r[18],'+');
goto P_0c0cc28e;
P_0c0cc28e: /* original f487, guest PC 0x0c0cc28e */
if(!s->budget--) { s->failed_pc=0x0c0cc28eu; return 0; }
vf3_matrix_store(s,ram,8,r[4]+r[0]);
goto P_0c0cc290;
P_0c0cc290: /* original e010, guest PC 0x0c0cc290 */
if(!s->budget--) { s->failed_pc=0x0c0cc290u; return 0; }
r[0]=0x00000010u;
goto P_0c0cc292;
P_0c0cc292: /* original f497, guest PC 0x0c0cc292 */
if(!s->budget--) { s->failed_pc=0x0c0cc292u; return 0; }
vf3_matrix_store(s,ram,9,r[4]+r[0]);
goto P_0c0cc294;
P_0c0cc294: /* original e014, guest PC 0x0c0cc294 */
if(!s->budget--) { s->failed_pc=0x0c0cc294u; return 0; }
r[0]=0x00000014u;
goto P_0c0cc296;
P_0c0cc296: /* original f790, guest PC 0x0c0cc296 */
if(!s->budget--) { s->failed_pc=0x0c0cc296u; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[9],r[18],'+');
goto P_0c0cc298;
P_0c0cc298: /* original f457, guest PC 0x0c0cc298 */
if(!s->budget--) { s->failed_pc=0x0c0cc298u; return 0; }
vf3_matrix_store(s,ram,5,r[4]+r[0]);
goto P_0c0cc29a;
P_0c0cc29a: /* original f278, guest PC 0x0c0cc29a */
if(!s->budget--) { s->failed_pc=0x0c0cc29au; return 0; }
vf3_matrix_load(s,ram,2,r[7]);
goto P_0c0cc29c;
P_0c0cc29c: /* original e004, guest PC 0x0c0cc29c */
if(!s->budget--) { s->failed_pc=0x0c0cc29cu; return 0; }
r[0]=0x00000004u;
goto P_0c0cc29e;
P_0c0cc29e: /* original f650, guest PC 0x0c0cc29e */
if(!s->budget--) { s->failed_pc=0x0c0cc29eu; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[5],r[18],'+');
goto P_0c0cc2a0;
P_0c0cc2a0: /* original e3f8, guest PC 0x0c0cc2a0 */
if(!s->budget--) { s->failed_pc=0x0c0cc2a0u; return 0; }
r[3]=0xfffffff8u;
goto P_0c0cc2a2;
P_0c0cc2a2: /* original f420, guest PC 0x0c0cc2a2 */
if(!s->budget--) { s->failed_pc=0x0c0cc2a2u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[2],r[18],'+');
goto P_0c0cc2a4;
P_0c0cc2a4: /* original 463c, guest PC 0x0c0cc2a4 */
if(!s->budget--) { s->failed_pc=0x0c0cc2a4u; return 0; }
r[6]=(r[3]&0x80000000u)?((r[3]&31u)?(uint32_t)((int32_t)r[6]>>((-r[3])&31u)):((int32_t)r[6]<0?0xffffffffu:0)):r[6]<<(r[3]&31u);
goto P_0c0cc2a6;
P_0c0cc2a6: /* original e201, guest PC 0x0c0cc2a6 */
if(!s->budget--) { s->failed_pc=0x0c0cc2a6u; return 0; }
r[2]=0x00000001u;
goto P_0c0cc2a8;
P_0c0cc2a8: /* original 26e9, guest PC 0x0c0cc2a8 */
if(!s->budget--) { s->failed_pc=0x0c0cc2a8u; return 0; }
r[6]&=r[14];
goto P_0c0cc2aa;
P_0c0cc2aa: /* original f44a, guest PC 0x0c0cc2aa */
if(!s->budget--) { s->failed_pc=0x0c0cc2aau; return 0; }
vf3_matrix_store(s,ram,4,r[4]);
goto P_0c0cc2ac;
P_0c0cc2ac: /* original f276, guest PC 0x0c0cc2ac */
if(!s->budget--) { s->failed_pc=0x0c0cc2acu; return 0; }
vf3_matrix_load(s,ram,2,r[7]+r[0]);
goto P_0c0cc2ae;
P_0c0cc2ae: /* original f720, guest PC 0x0c0cc2ae */
if(!s->budget--) { s->failed_pc=0x0c0cc2aeu; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[2],r[18],'+');
goto P_0c0cc2b0;
P_0c0cc2b0: /* original f477, guest PC 0x0c0cc2b0 */
if(!s->budget--) { s->failed_pc=0x0c0cc2b0u; return 0; }
vf3_matrix_store(s,ram,7,r[4]+r[0]);
goto P_0c0cc2b2;
P_0c0cc2b2: /* original e008, guest PC 0x0c0cc2b2 */
if(!s->budget--) { s->failed_pc=0x0c0cc2b2u; return 0; }
r[0]=0x00000008u;
goto P_0c0cc2b4;
P_0c0cc2b4: /* original f276, guest PC 0x0c0cc2b4 */
if(!s->budget--) { s->failed_pc=0x0c0cc2b4u; return 0; }
vf3_matrix_load(s,ram,2,r[7]+r[0]);
goto P_0c0cc2b6;
P_0c0cc2b6: /* original f64d, guest PC 0x0c0cc2b6 */
if(!s->budget--) { s->failed_pc=0x0c0cc2b6u; return 0; }
fr[6]^=0x80000000u;
goto P_0c0cc2b8;
P_0c0cc2b8: /* original f621, guest PC 0x0c0cc2b8 */
if(!s->budget--) { s->failed_pc=0x0c0cc2b8u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[2],r[18],'-');
goto P_0c0cc2ba;
P_0c0cc2ba: /* original f467, guest PC 0x0c0cc2ba */
if(!s->budget--) { s->failed_pc=0x0c0cc2bau; return 0; }
vf3_matrix_store(s,ram,6,r[4]+r[0]);
goto P_0c0cc2bc;
P_0c0cc2bc: /* original 5353, guest PC 0x0c0cc2bc */
if(!s->budget--) { s->failed_pc=0x0c0cc2bcu; return 0; }
r[3]=read(ram,r[5]+12,4);
goto P_0c0cc2be;
P_0c0cc2be: /* original 3327, guest PC 0x0c0cc2be */
if(!s->budget--) { s->failed_pc=0x0c0cc2beu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>(int32_t)r[2])!=0);
goto P_0c0cc2c0;
P_0c0cc2c0: /* original 8f04, guest PC 0x0c0cc2c0 */
if(!s->budget--) { s->failed_pc=0x0c0cc2c0u; return 0; }
cond=r[17]&1u;
r[6]+=0x00000004u;
if(!cond) { goto P_0c0cc2cc; }
goto P_0c0cc2c4;
P_0c0cc2c2: /* original 7604, guest PC 0x0c0cc2c2 */
if(!s->budget--) { s->failed_pc=0x0c0cc2c2u; return 0; }
r[6]+=0x00000004u;
goto P_0c0cc2c4;
P_0c0cc2c4: /* original e01c, guest PC 0x0c0cc2c4 */
if(!s->budget--) { s->failed_pc=0x0c0cc2c4u; return 0; }
r[0]=0x0000001cu;
goto P_0c0cc2c6;
P_0c0cc2c6: /* original 3607, guest PC 0x0c0cc2c6 */
if(!s->budget--) { s->failed_pc=0x0c0cc2c6u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[6]>(int32_t)r[0])!=0);
goto P_0c0cc2c8;
P_0c0cc2c8: /* original 8b00, guest PC 0x0c0cc2c8 */
if(!s->budget--) { s->failed_pc=0x0c0cc2c8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0cc2cc; }
goto P_0c0cc2ca;
P_0c0cc2ca: /* original e61c, guest PC 0x0c0cc2ca */
if(!s->budget--) { s->failed_pc=0x0c0cc2cau; return 0; }
r[6]=0x0000001cu;
goto P_0c0cc2cc;
P_0c0cc2cc: /* original 6063, guest PC 0x0c0cc2cc */
if(!s->budget--) { s->failed_pc=0x0c0cc2ccu; return 0; }
r[0]=r[6];
goto P_0c0cc2ce;
P_0c0cc2ce: /* original 7f04, guest PC 0x0c0cc2ce */
if(!s->budget--) { s->failed_pc=0x0c0cc2ceu; return 0; }
r[15]+=0x00000004u;
goto P_0c0cc2d0;
P_0c0cc2d0: /* original 814f, guest PC 0x0c0cc2d0 */
if(!s->budget--) { s->failed_pc=0x0c0cc2d0u; return 0; }
write(ram,r[4]+30,r[0],2);
goto P_0c0cc2d2;
P_0c0cc2d2: /* original 000b, guest PC 0x0c0cc2d2 */
if(!s->budget--) { s->failed_pc=0x0c0cc2d2u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0cc2d4: /* original 6ef6, guest PC 0x0c0cc2d4 */
if(!s->budget--) { s->failed_pc=0x0c0cc2d4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0cc2d6u,s,ram);
P_0c0cc67c: /* original 2fe6, guest PC 0x0c0cc67c */
if(!s->budget--) { s->failed_pc=0x0c0cc67cu; return 0; }
r[15]-=4; write(ram,r[15],r[14],4);
goto P_0c0cc67e;
P_0c0cc67e: /* original c744, guest PC 0x0c0cc67e */
if(!s->budget--) { s->failed_pc=0x0c0cc67eu; return 0; }
r[0]=0x0c0cc790u;
goto P_0c0cc680;
P_0c0cc680: /* original 2fd6, guest PC 0x0c0cc680 */
if(!s->budget--) { s->failed_pc=0x0c0cc680u; return 0; }
r[15]-=4; write(ram,r[15],r[13],4);
goto P_0c0cc682;
P_0c0cc682: /* original 6e53, guest PC 0x0c0cc682 */
if(!s->budget--) { s->failed_pc=0x0c0cc682u; return 0; }
r[14]=r[5];
goto P_0c0cc684;
P_0c0cc684: /* original 2fc6, guest PC 0x0c0cc684 */
if(!s->budget--) { s->failed_pc=0x0c0cc684u; return 0; }
r[15]-=4; write(ram,r[15],r[12],4);
goto P_0c0cc686;
P_0c0cc686: /* original 2fb6, guest PC 0x0c0cc686 */
if(!s->budget--) { s->failed_pc=0x0c0cc686u; return 0; }
r[15]-=4; write(ram,r[15],r[11],4);
goto P_0c0cc688;
P_0c0cc688: /* original 2fa6, guest PC 0x0c0cc688 */
if(!s->budget--) { s->failed_pc=0x0c0cc688u; return 0; }
r[15]-=4; write(ram,r[15],r[10],4);
goto P_0c0cc68a;
P_0c0cc68a: /* original 2f96, guest PC 0x0c0cc68a */
if(!s->budget--) { s->failed_pc=0x0c0cc68au; return 0; }
r[15]-=4; write(ram,r[15],r[9],4);
goto P_0c0cc68c;
P_0c0cc68c: /* original 2f86, guest PC 0x0c0cc68c */
if(!s->budget--) { s->failed_pc=0x0c0cc68cu; return 0; }
r[15]-=4; write(ram,r[15],r[8],4);
goto P_0c0cc68e;
P_0c0cc68e: /* original fffb, guest PC 0x0c0cc68e */
if(!s->budget--) { s->failed_pc=0x0c0cc68eu; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c0cc690;
P_0c0cc690: /* original dc3d, guest PC 0x0c0cc690 */
if(!s->budget--) { s->failed_pc=0x0c0cc690u; return 0; }
r[12]=read(ram,0x0c0cc788u,4);
goto P_0c0cc692;
P_0c0cc692: /* original 4f22, guest PC 0x0c0cc692 */
if(!s->budget--) { s->failed_pc=0x0c0cc692u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0cc694;
P_0c0cc694: /* original 53c1, guest PC 0x0c0cc694 */
if(!s->budget--) { s->failed_pc=0x0c0cc694u; return 0; }
r[3]=read(ram,r[12]+4,4);
goto P_0c0cc696;
P_0c0cc696: /* original 67c2, guest PC 0x0c0cc696 */
if(!s->budget--) { s->failed_pc=0x0c0cc696u; return 0; }
tmp=read(ram,r[12],4);
r[7]=tmp;
goto P_0c0cc698;
P_0c0cc698: /* original 7ffc, guest PC 0x0c0cc698 */
if(!s->budget--) { s->failed_pc=0x0c0cc698u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c0cc69a;
P_0c0cc69a: /* original d63c, guest PC 0x0c0cc69a */
if(!s->budget--) { s->failed_pc=0x0c0cc69au; return 0; }
r[6]=read(ram,0x0c0cc78cu,4);
goto P_0c0cc69c;
P_0c0cc69c: /* original 65e2, guest PC 0x0c0cc69c */
if(!s->budget--) { s->failed_pc=0x0c0cc69cu; return 0; }
tmp=read(ram,r[14],4);
r[5]=tmp;
goto P_0c0cc69e;
P_0c0cc69e: /* original ff08, guest PC 0x0c0cc69e */
if(!s->budget--) { s->failed_pc=0x0c0cc69eu; return 0; }
vf3_matrix_load(s,ram,15,r[0]);
goto P_0c0cc6a0;
P_0c0cc6a0: /* original 2f32, guest PC 0x0c0cc6a0 */
if(!s->budget--) { s->failed_pc=0x0c0cc6a0u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c0cc6a2;
P_0c0cc6a2: /* original 6373, guest PC 0x0c0cc6a2 */
if(!s->budget--) { s->failed_pc=0x0c0cc6a2u; return 0; }
r[3]=r[7];
goto P_0c0cc6a4;
P_0c0cc6a4: /* original db3b, guest PC 0x0c0cc6a4 */
if(!s->budget--) { s->failed_pc=0x0c0cc6a4u; return 0; }
r[11]=read(ram,0x0c0cc794u,4);
goto P_0c0cc6a6;
P_0c0cc6a6: /* original 23b8, guest PC 0x0c0cc6a6 */
if(!s->budget--) { s->failed_pc=0x0c0cc6a6u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[11])==0)!=0);
goto P_0c0cc6a8;
P_0c0cc6a8: /* original 8b14, guest PC 0x0c0cc6a8 */
if(!s->budget--) { s->failed_pc=0x0c0cc6a8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0cc6d4; }
goto P_0c0cc6aa;
P_0c0cc6aa: /* original d23b, guest PC 0x0c0cc6aa */
if(!s->budget--) { s->failed_pc=0x0c0cc6aau; return 0; }
r[2]=read(ram,0x0c0cc798u,4);
goto P_0c0cc6ac;
P_0c0cc6ac: /* original 2728, guest PC 0x0c0cc6ac */
if(!s->budget--) { s->failed_pc=0x0c0cc6acu; return 0; }
r[17]=(r[17]&~1u)|(((r[7]&r[2])==0)!=0);
goto P_0c0cc6ae;
P_0c0cc6ae: /* original 8902, guest PC 0x0c0cc6ae */
if(!s->budget--) { s->failed_pc=0x0c0cc6aeu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0cc6b6; }
goto P_0c0cc6b0;
P_0c0cc6b0: /* original 63f2, guest PC 0x0c0cc6b0 */
if(!s->budget--) { s->failed_pc=0x0c0cc6b0u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c0cc6b2;
P_0c0cc6b2: /* original 23b8, guest PC 0x0c0cc6b2 */
if(!s->budget--) { s->failed_pc=0x0c0cc6b2u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[11])==0)!=0);
goto P_0c0cc6b4;
P_0c0cc6b4: /* original 8b0e, guest PC 0x0c0cc6b4 */
if(!s->budget--) { s->failed_pc=0x0c0cc6b4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0cc6d4; }
goto P_0c0cc6b6;
P_0c0cc6b6: /* original e201, guest PC 0x0c0cc6b6 */
if(!s->budget--) { s->failed_pc=0x0c0cc6b6u; return 0; }
r[2]=0x00000001u;
goto P_0c0cc6b8;
P_0c0cc6b8: /* original 2258, guest PC 0x0c0cc6b8 */
if(!s->budget--) { s->failed_pc=0x0c0cc6b8u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[5])==0)!=0);
goto P_0c0cc6ba;
P_0c0cc6ba: /* original 8b01, guest PC 0x0c0cc6ba */
if(!s->budget--) { s->failed_pc=0x0c0cc6bau; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0cc6c0; }
goto P_0c0cc6bc;
P_0c0cc6bc: /* original a122, guest PC 0x0c0cc6bc */
if(!s->budget--) { s->failed_pc=0x0c0cc6bcu; return 0; }
goto P_0c0cc904;
P_0c0cc6be: /* original 0009, guest PC 0x0c0cc6be */
if(!s->budget--) { s->failed_pc=0x0c0cc6beu; return 0; }
goto P_0c0cc6c0;
P_0c0cc6c0: /* original d136, guest PC 0x0c0cc6c0 */
if(!s->budget--) { s->failed_pc=0x0c0cc6c0u; return 0; }
r[1]=read(ram,0x0c0cc79cu,4);
goto P_0c0cc6c2;
P_0c0cc6c2: /* original 2158, guest PC 0x0c0cc6c2 */
if(!s->budget--) { s->failed_pc=0x0c0cc6c2u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[5])==0)!=0);
goto P_0c0cc6c4;
P_0c0cc6c4: /* original 8b01, guest PC 0x0c0cc6c4 */
if(!s->budget--) { s->failed_pc=0x0c0cc6c4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0cc6ca; }
goto P_0c0cc6c6;
P_0c0cc6c6: /* original a11d, guest PC 0x0c0cc6c6 */
if(!s->budget--) { s->failed_pc=0x0c0cc6c6u; return 0; }
goto P_0c0cc904;
P_0c0cc6c8: /* original 0009, guest PC 0x0c0cc6c8 */
if(!s->budget--) { s->failed_pc=0x0c0cc6c8u; return 0; }
goto P_0c0cc6ca;
P_0c0cc6ca: /* original e202, guest PC 0x0c0cc6ca */
if(!s->budget--) { s->failed_pc=0x0c0cc6cau; return 0; }
r[2]=0x00000002u;
goto P_0c0cc6cc;
P_0c0cc6cc: /* original 2528, guest PC 0x0c0cc6cc */
if(!s->budget--) { s->failed_pc=0x0c0cc6ccu; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[2])==0)!=0);
goto P_0c0cc6ce;
P_0c0cc6ce: /* original 8901, guest PC 0x0c0cc6ce */
if(!s->budget--) { s->failed_pc=0x0c0cc6ceu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0cc6d4; }
goto P_0c0cc6d0;
P_0c0cc6d0: /* original a118, guest PC 0x0c0cc6d0 */
if(!s->budget--) { s->failed_pc=0x0c0cc6d0u; return 0; }
goto P_0c0cc904;
P_0c0cc6d2: /* original 0009, guest PC 0x0c0cc6d2 */
if(!s->budget--) { s->failed_pc=0x0c0cc6d2u; return 0; }
goto P_0c0cc6d4;
P_0c0cc6d4: /* original e01c, guest PC 0x0c0cc6d4 */
if(!s->budget--) { s->failed_pc=0x0c0cc6d4u; return 0; }
r[0]=0x0000001cu;
goto P_0c0cc6d6;
P_0c0cc6d6: /* original 05cc, guest PC 0x0c0cc6d6 */
if(!s->budget--) { s->failed_pc=0x0c0cc6d6u; return 0; }
r[5]=(uint32_t)(int32_t)(int8_t)read(ram,r[12]+r[0],1);
goto P_0c0cc6d8;
P_0c0cc6d8: /* original e30f, guest PC 0x0c0cc6d8 */
if(!s->budget--) { s->failed_pc=0x0c0cc6d8u; return 0; }
r[3]=0x0000000fu;
goto P_0c0cc6da;
P_0c0cc6da: /* original 9050, guest PC 0x0c0cc6da */
if(!s->budget--) { s->failed_pc=0x0c0cc6dau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0cc77eu,2);
goto P_0c0cc6dc;
P_0c0cc6dc: /* original 655c, guest PC 0x0c0cc6dc */
if(!s->budget--) { s->failed_pc=0x0c0cc6dcu; return 0; }
r[5]=r[5]&255u;
goto P_0c0cc6de;
P_0c0cc6de: /* original 044c, guest PC 0x0c0cc6de */
if(!s->budget--) { s->failed_pc=0x0c0cc6deu; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c0cc6e0;
P_0c0cc6e0: /* original 6043, guest PC 0x0c0cc6e0 */
if(!s->budget--) { s->failed_pc=0x0c0cc6e0u; return 0; }
r[0]=r[4];
goto P_0c0cc6e2;
P_0c0cc6e2: /* original 8817, guest PC 0x0c0cc6e2 */
if(!s->budget--) { s->failed_pc=0x0c0cc6e2u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000017u)!=0);
goto P_0c0cc6e4;
P_0c0cc6e4: /* original 8f02, guest PC 0x0c0cc6e4 */
if(!s->budget--) { s->failed_pc=0x0c0cc6e4u; return 0; }
cond=r[17]&1u;
r[5]&=r[3];
if(!cond) { goto P_0c0cc6ec; }
goto P_0c0cc6e8;
P_0c0cc6e6: /* original 2539, guest PC 0x0c0cc6e6 */
if(!s->budget--) { s->failed_pc=0x0c0cc6e6u; return 0; }
r[5]&=r[3];
goto P_0c0cc6e8;
P_0c0cc6e8: /* original a10c, guest PC 0x0c0cc6e8 */
if(!s->budget--) { s->failed_pc=0x0c0cc6e8u; return 0; }
goto P_0c0cc904;
P_0c0cc6ea: /* original 0009, guest PC 0x0c0cc6ea */
if(!s->budget--) { s->failed_pc=0x0c0cc6eau; return 0; }
goto P_0c0cc6ec;
P_0c0cc6ec: /* original 6043, guest PC 0x0c0cc6ec */
if(!s->budget--) { s->failed_pc=0x0c0cc6ecu; return 0; }
r[0]=r[4];
goto P_0c0cc6ee;
P_0c0cc6ee: /* original 8807, guest PC 0x0c0cc6ee */
if(!s->budget--) { s->failed_pc=0x0c0cc6eeu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000007u)!=0);
goto P_0c0cc6f0;
P_0c0cc6f0: /* original 8b01, guest PC 0x0c0cc6f0 */
if(!s->budget--) { s->failed_pc=0x0c0cc6f0u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0cc6f6; }
goto P_0c0cc6f2;
P_0c0cc6f2: /* original a107, guest PC 0x0c0cc6f2 */
if(!s->budget--) { s->failed_pc=0x0c0cc6f2u; return 0; }
goto P_0c0cc904;
P_0c0cc6f4: /* original 0009, guest PC 0x0c0cc6f4 */
if(!s->budget--) { s->failed_pc=0x0c0cc6f4u; return 0; }
goto P_0c0cc6f6;
P_0c0cc6f6: /* original 6053, guest PC 0x0c0cc6f6 */
if(!s->budget--) { s->failed_pc=0x0c0cc6f6u; return 0; }
r[0]=r[5];
goto P_0c0cc6f8;
P_0c0cc6f8: /* original 8807, guest PC 0x0c0cc6f8 */
if(!s->budget--) { s->failed_pc=0x0c0cc6f8u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000007u)!=0);
goto P_0c0cc6fa;
P_0c0cc6fa: /* original 8b01, guest PC 0x0c0cc6fa */
if(!s->budget--) { s->failed_pc=0x0c0cc6fau; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0cc700; }
goto P_0c0cc6fc;
P_0c0cc6fc: /* original a102, guest PC 0x0c0cc6fc */
if(!s->budget--) { s->failed_pc=0x0c0cc6fcu; return 0; }
goto P_0c0cc904;
P_0c0cc6fe: /* original 0009, guest PC 0x0c0cc6fe */
if(!s->budget--) { s->failed_pc=0x0c0cc6feu; return 0; }
goto P_0c0cc700;
P_0c0cc700: /* original 6053, guest PC 0x0c0cc700 */
if(!s->budget--) { s->failed_pc=0x0c0cc700u; return 0; }
r[0]=r[5];
goto P_0c0cc702;
P_0c0cc702: /* original 8806, guest PC 0x0c0cc702 */
if(!s->budget--) { s->failed_pc=0x0c0cc702u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000006u)!=0);
goto P_0c0cc704;
P_0c0cc704: /* original 8b01, guest PC 0x0c0cc704 */
if(!s->budget--) { s->failed_pc=0x0c0cc704u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0cc70a; }
goto P_0c0cc706;
P_0c0cc706: /* original a0fd, guest PC 0x0c0cc706 */
if(!s->budget--) { s->failed_pc=0x0c0cc706u; return 0; }
goto P_0c0cc904;
P_0c0cc708: /* original 0009, guest PC 0x0c0cc708 */
if(!s->budget--) { s->failed_pc=0x0c0cc708u; return 0; }
goto P_0c0cc70a;
P_0c0cc70a: /* original 6053, guest PC 0x0c0cc70a */
if(!s->budget--) { s->failed_pc=0x0c0cc70au; return 0; }
r[0]=r[5];
goto P_0c0cc70c;
P_0c0cc70c: /* original 880e, guest PC 0x0c0cc70c */
if(!s->budget--) { s->failed_pc=0x0c0cc70cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000eu)!=0);
goto P_0c0cc70e;
P_0c0cc70e: /* original 8b01, guest PC 0x0c0cc70e */
if(!s->budget--) { s->failed_pc=0x0c0cc70eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0cc714; }
goto P_0c0cc710;
P_0c0cc710: /* original a0f8, guest PC 0x0c0cc710 */
if(!s->budget--) { s->failed_pc=0x0c0cc710u; return 0; }
goto P_0c0cc904;
P_0c0cc712: /* original 0009, guest PC 0x0c0cc712 */
if(!s->budget--) { s->failed_pc=0x0c0cc712u; return 0; }
goto P_0c0cc714;
P_0c0cc714: /* original 63c2, guest PC 0x0c0cc714 */
if(!s->budget--) { s->failed_pc=0x0c0cc714u; return 0; }
tmp=read(ram,r[12],4);
r[3]=tmp;
goto P_0c0cc716;
P_0c0cc716: /* original 23b8, guest PC 0x0c0cc716 */
if(!s->budget--) { s->failed_pc=0x0c0cc716u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[11])==0)!=0);
goto P_0c0cc718;
P_0c0cc718: /* original 8906, guest PC 0x0c0cc718 */
if(!s->budget--) { s->failed_pc=0x0c0cc718u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0cc728; }
goto P_0c0cc71a;
P_0c0cc71a: /* original e061, guest PC 0x0c0cc71a */
if(!s->budget--) { s->failed_pc=0x0c0cc71au; return 0; }
r[0]=0x00000061u;
goto P_0c0cc71c;
P_0c0cc71c: /* original 00ec, guest PC 0x0c0cc71c */
if(!s->budget--) { s->failed_pc=0x0c0cc71cu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0cc71e;
P_0c0cc71e: /* original 600c, guest PC 0x0c0cc71e */
if(!s->budget--) { s->failed_pc=0x0c0cc71eu; return 0; }
r[0]=r[0]&255u;
goto P_0c0cc720;
P_0c0cc720: /* original 880c, guest PC 0x0c0cc720 */
if(!s->budget--) { s->failed_pc=0x0c0cc720u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000cu)!=0);
goto P_0c0cc722;
P_0c0cc722: /* original 8b01, guest PC 0x0c0cc722 */
if(!s->budget--) { s->failed_pc=0x0c0cc722u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0cc728; }
goto P_0c0cc724;
P_0c0cc724: /* original a0ee, guest PC 0x0c0cc724 */
if(!s->budget--) { s->failed_pc=0x0c0cc724u; return 0; }
goto P_0c0cc904;
P_0c0cc726: /* original 0009, guest PC 0x0c0cc726 */
if(!s->budget--) { s->failed_pc=0x0c0cc726u; return 0; }
goto P_0c0cc728;
P_0c0cc728: /* original 902a, guest PC 0x0c0cc728 */
if(!s->budget--) { s->failed_pc=0x0c0cc728u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0cc780u,2);
goto P_0c0cc72a;
P_0c0cc72a: /* original 026c, guest PC 0x0c0cc72a */
if(!s->budget--) { s->failed_pc=0x0c0cc72au; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[6]+r[0],1);
goto P_0c0cc72c;
P_0c0cc72c: /* original 2228, guest PC 0x0c0cc72c */
if(!s->budget--) { s->failed_pc=0x0c0cc72cu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c0cc72e;
P_0c0cc72e: /* original 8903, guest PC 0x0c0cc72e */
if(!s->budget--) { s->failed_pc=0x0c0cc72eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0cc738; }
goto P_0c0cc730;
P_0c0cc730: /* original 036c, guest PC 0x0c0cc730 */
if(!s->budget--) { s->failed_pc=0x0c0cc730u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[6]+r[0],1);
goto P_0c0cc732;
P_0c0cc732: /* original 73ff, guest PC 0x0c0cc732 */
if(!s->budget--) { s->failed_pc=0x0c0cc732u; return 0; }
r[3]+=0xffffffffu;
goto P_0c0cc734;
P_0c0cc734: /* original a0e6, guest PC 0x0c0cc734 */
if(!s->budget--) { s->failed_pc=0x0c0cc734u; return 0; }
write(ram,r[6]+r[0],r[3],1);
goto P_0c0cc904;
P_0c0cc736: /* original 0634, guest PC 0x0c0cc736 */
if(!s->budget--) { s->failed_pc=0x0c0cc736u; return 0; }
write(ram,r[6]+r[0],r[3],1);
goto P_0c0cc738;
P_0c0cc738: /* original d219, guest PC 0x0c0cc738 */
if(!s->budget--) { s->failed_pc=0x0c0cc738u; return 0; }
r[2]=read(ram,0x0c0cc7a0u,4);
goto P_0c0cc73a;
P_0c0cc73a: /* original 420b, guest PC 0x0c0cc73a */
if(!s->budget--) { s->failed_pc=0x0c0cc73au; return 0; }
target=r[2];
r[16]=0x0c0cc73eu;
r[4]=0x00000000u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0cc73eu) { target=s->pc; goto dispatch; }
goto P_0c0cc73e;
P_0c0cc73c: /* original e400, guest PC 0x0c0cc73c */
if(!s->budget--) { s->failed_pc=0x0c0cc73cu; return 0; }
r[4]=0x00000000u;
goto P_0c0cc73e;
P_0c0cc73e: /* original 63c2, guest PC 0x0c0cc73e */
if(!s->budget--) { s->failed_pc=0x0c0cc73eu; return 0; }
tmp=read(ram,r[12],4);
r[3]=tmp;
goto P_0c0cc740;
P_0c0cc740: /* original d518, guest PC 0x0c0cc740 */
if(!s->budget--) { s->failed_pc=0x0c0cc740u; return 0; }
r[5]=read(ram,0x0c0cc7a4u,4);
goto P_0c0cc742;
P_0c0cc742: /* original 2b38, guest PC 0x0c0cc742 */
if(!s->budget--) { s->failed_pc=0x0c0cc742u; return 0; }
r[17]=(r[17]&~1u)|(((r[11]&r[3])==0)!=0);
goto P_0c0cc744;
P_0c0cc744: /* original 8d0c, guest PC 0x0c0cc744 */
if(!s->budget--) { s->failed_pc=0x0c0cc744u; return 0; }
cond=r[17]&1u;
r[13]=0x00000000u;
if(cond) { goto P_0c0cc760; }
goto P_0c0cc748;
P_0c0cc746: /* original ed00, guest PC 0x0c0cc746 */
if(!s->budget--) { s->failed_pc=0x0c0cc746u; return 0; }
r[13]=0x00000000u;
goto P_0c0cc748;
P_0c0cc748: /* original c717, guest PC 0x0c0cc748 */
if(!s->budget--) { s->failed_pc=0x0c0cc748u; return 0; }
r[0]=0x0c0cc7a8u;
goto P_0c0cc74a;
P_0c0cc74a: /* original d318, guest PC 0x0c0cc74a */
if(!s->budget--) { s->failed_pc=0x0c0cc74au; return 0; }
r[3]=read(ram,0x0c0cc7acu,4);
goto P_0c0cc74c;
P_0c0cc74c: /* original ff08, guest PC 0x0c0cc74c */
if(!s->budget--) { s->failed_pc=0x0c0cc74cu; return 0; }
vf3_matrix_load(s,ram,15,r[0]);
goto P_0c0cc74e;
P_0c0cc74e: /* original e048, guest PC 0x0c0cc74e */
if(!s->budget--) { s->failed_pc=0x0c0cc74eu; return 0; }
r[0]=0x00000048u;
goto P_0c0cc750;
P_0c0cc750: /* original 02ee, guest PC 0x0c0cc750 */
if(!s->budget--) { s->failed_pc=0x0c0cc750u; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c0cc752;
P_0c0cc752: /* original 2238, guest PC 0x0c0cc752 */
if(!s->budget--) { s->failed_pc=0x0c0cc752u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c0cc754;
P_0c0cc754: /* original 8901, guest PC 0x0c0cc754 */
if(!s->budget--) { s->failed_pc=0x0c0cc754u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0cc75a; }
goto P_0c0cc756;
P_0c0cc756: /* original a09c, guest PC 0x0c0cc756 */
if(!s->budget--) { s->failed_pc=0x0c0cc756u; return 0; }
goto P_0c0cc892;
P_0c0cc758: /* original 0009, guest PC 0x0c0cc758 */
if(!s->budget--) { s->failed_pc=0x0c0cc758u; return 0; }
goto P_0c0cc75a;
P_0c0cc75a: /* original 9012, guest PC 0x0c0cc75a */
if(!s->budget--) { s->failed_pc=0x0c0cc75au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0cc782u,2);
goto P_0c0cc75c;
P_0c0cc75c: /* original a03b, guest PC 0x0c0cc75c */
if(!s->budget--) { s->failed_pc=0x0c0cc75cu; return 0; }
r[4]=read(ram,r[5]+r[0],4);
goto P_0c0cc7d6;
P_0c0cc75e: /* original 045e, guest PC 0x0c0cc75e */
if(!s->budget--) { s->failed_pc=0x0c0cc75eu; return 0; }
r[4]=read(ram,r[5]+r[0],4);
goto P_0c0cc760;
P_0c0cc760: /* original e04c, guest PC 0x0c0cc760 */
if(!s->budget--) { s->failed_pc=0x0c0cc760u; return 0; }
r[0]=0x0000004cu;
goto P_0c0cc762;
P_0c0cc762: /* original 00ee, guest PC 0x0c0cc762 */
if(!s->budget--) { s->failed_pc=0x0c0cc762u; return 0; }
r[0]=read(ram,r[14]+r[0],4);
goto P_0c0cc764;
P_0c0cc764: /* original c880, guest PC 0x0c0cc764 */
if(!s->budget--) { s->failed_pc=0x0c0cc764u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&128u)==0)!=0);
goto P_0c0cc766;
P_0c0cc766: /* original 8b01, guest PC 0x0c0cc766 */
if(!s->budget--) { s->failed_pc=0x0c0cc766u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0cc76c; }
goto P_0c0cc768;
P_0c0cc768: /* original a093, guest PC 0x0c0cc768 */
if(!s->budget--) { s->failed_pc=0x0c0cc768u; return 0; }
goto P_0c0cc892;
P_0c0cc76a: /* original 0009, guest PC 0x0c0cc76a */
if(!s->budget--) { s->failed_pc=0x0c0cc76au; return 0; }
goto P_0c0cc76c;
P_0c0cc76c: /* original 900a, guest PC 0x0c0cc76c */
if(!s->budget--) { s->failed_pc=0x0c0cc76cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0cc784u,2);
goto P_0c0cc76e;
P_0c0cc76e: /* original d310, guest PC 0x0c0cc76e */
if(!s->budget--) { s->failed_pc=0x0c0cc76eu; return 0; }
r[3]=read(ram,0x0c0cc7b0u,4);
goto P_0c0cc770;
P_0c0cc770: /* original 02ee, guest PC 0x0c0cc770 */
if(!s->budget--) { s->failed_pc=0x0c0cc770u; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c0cc772;
P_0c0cc772: /* original 2238, guest PC 0x0c0cc772 */
if(!s->budget--) { s->failed_pc=0x0c0cc772u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c0cc774;
P_0c0cc774: /* original 891e, guest PC 0x0c0cc774 */
if(!s->budget--) { s->failed_pc=0x0c0cc774u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0cc7b4; }
goto P_0c0cc776;
P_0c0cc776: /* original 9006, guest PC 0x0c0cc776 */
if(!s->budget--) { s->failed_pc=0x0c0cc776u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0cc786u,2);
goto P_0c0cc778;
P_0c0cc778: /* original 04ec, guest PC 0x0c0cc778 */
if(!s->budget--) { s->failed_pc=0x0c0cc778u; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0cc77a;
P_0c0cc77a: /* original a020, guest PC 0x0c0cc77a */
if(!s->budget--) { s->failed_pc=0x0c0cc77au; return 0; }
r[4]=r[4]&255u;
goto P_0c0cc7be;
P_0c0cc77c: /* original 644c, guest PC 0x0c0cc77c */
if(!s->budget--) { s->failed_pc=0x0c0cc77cu; return 0; }
r[4]=r[4]&255u;
return vf3_matrix_family(0x0c0cc77eu,s,ram);
P_0c0cc7b4: /* original 9072, guest PC 0x0c0cc7b4 */
if(!s->budget--) { s->failed_pc=0x0c0cc7b4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0cc89cu,2);
goto P_0c0cc7b6;
P_0c0cc7b6: /* original 04ec, guest PC 0x0c0cc7b6 */
if(!s->budget--) { s->failed_pc=0x0c0cc7b6u; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0cc7b8;
P_0c0cc7b8: /* original 644c, guest PC 0x0c0cc7b8 */
if(!s->budget--) { s->failed_pc=0x0c0cc7b8u; return 0; }
r[4]=r[4]&255u;
goto P_0c0cc7ba;
P_0c0cc7ba: /* original 2448, guest PC 0x0c0cc7ba */
if(!s->budget--) { s->failed_pc=0x0c0cc7bau; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c0cc7bc;
P_0c0cc7bc: /* original 8969, guest PC 0x0c0cc7bc */
if(!s->budget--) { s->failed_pc=0x0c0cc7bcu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0cc892; }
goto P_0c0cc7be;
P_0c0cc7be: /* original 6043, guest PC 0x0c0cc7be */
if(!s->budget--) { s->failed_pc=0x0c0cc7beu; return 0; }
r[0]=r[4];
goto P_0c0cc7c0;
P_0c0cc7c0: /* original 4008, guest PC 0x0c0cc7c0 */
if(!s->budget--) { s->failed_pc=0x0c0cc7c0u; return 0; }
r[0]<<=2;
goto P_0c0cc7c2;
P_0c0cc7c2: /* original d339, guest PC 0x0c0cc7c2 */
if(!s->budget--) { s->failed_pc=0x0c0cc7c2u; return 0; }
r[3]=read(ram,0x0c0cc8a8u,4);
goto P_0c0cc7c4;
P_0c0cc7c4: /* original 045e, guest PC 0x0c0cc7c4 */
if(!s->budget--) { s->failed_pc=0x0c0cc7c4u; return 0; }
r[4]=read(ram,r[5]+r[0],4);
goto P_0c0cc7c6;
P_0c0cc7c6: /* original 2348, guest PC 0x0c0cc7c6 */
if(!s->budget--) { s->failed_pc=0x0c0cc7c6u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[4])==0)!=0);
goto P_0c0cc7c8;
P_0c0cc7c8: /* original 8900, guest PC 0x0c0cc7c8 */
if(!s->budget--) { s->failed_pc=0x0c0cc7c8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0cc7cc; }
goto P_0c0cc7ca;
P_0c0cc7ca: /* original dd38, guest PC 0x0c0cc7ca */
if(!s->budget--) { s->failed_pc=0x0c0cc7cau; return 0; }
r[13]=read(ram,0x0c0cc8acu,4);
goto P_0c0cc7cc;
P_0c0cc7cc: /* original d338, guest PC 0x0c0cc7cc */
if(!s->budget--) { s->failed_pc=0x0c0cc7ccu; return 0; }
r[3]=read(ram,0x0c0cc8b0u,4);
goto P_0c0cc7ce;
P_0c0cc7ce: /* original 2348, guest PC 0x0c0cc7ce */
if(!s->budget--) { s->failed_pc=0x0c0cc7ceu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[4])==0)!=0);
goto P_0c0cc7d0;
P_0c0cc7d0: /* original 8901, guest PC 0x0c0cc7d0 */
if(!s->budget--) { s->failed_pc=0x0c0cc7d0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0cc7d6; }
goto P_0c0cc7d2;
P_0c0cc7d2: /* original d138, guest PC 0x0c0cc7d2 */
if(!s->budget--) { s->failed_pc=0x0c0cc7d2u; return 0; }
r[1]=read(ram,0x0c0cc8b4u,4);
goto P_0c0cc7d4;
P_0c0cc7d4: /* original 2d1b, guest PC 0x0c0cc7d4 */
if(!s->budget--) { s->failed_pc=0x0c0cc7d4u; return 0; }
r[13]|=r[1];
goto P_0c0cc7d6;
P_0c0cc7d6: /* original d338, guest PC 0x0c0cc7d6 */
if(!s->budget--) { s->failed_pc=0x0c0cc7d6u; return 0; }
r[3]=read(ram,0x0c0cc8b8u,4);
goto P_0c0cc7d8;
P_0c0cc7d8: /* original 2348, guest PC 0x0c0cc7d8 */
if(!s->budget--) { s->failed_pc=0x0c0cc7d8u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[4])==0)!=0);
goto P_0c0cc7da;
P_0c0cc7da: /* original 8901, guest PC 0x0c0cc7da */
if(!s->budget--) { s->failed_pc=0x0c0cc7dau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0cc7e0; }
goto P_0c0cc7dc;
P_0c0cc7dc: /* original d137, guest PC 0x0c0cc7dc */
if(!s->budget--) { s->failed_pc=0x0c0cc7dcu; return 0; }
r[1]=read(ram,0x0c0cc8bcu,4);
goto P_0c0cc7de;
P_0c0cc7de: /* original 2d1b, guest PC 0x0c0cc7de */
if(!s->budget--) { s->failed_pc=0x0c0cc7deu; return 0; }
r[13]|=r[1];
goto P_0c0cc7e0;
P_0c0cc7e0: /* original d337, guest PC 0x0c0cc7e0 */
if(!s->budget--) { s->failed_pc=0x0c0cc7e0u; return 0; }
r[3]=read(ram,0x0c0cc8c0u,4);
goto P_0c0cc7e2;
P_0c0cc7e2: /* original 2348, guest PC 0x0c0cc7e2 */
if(!s->budget--) { s->failed_pc=0x0c0cc7e2u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[4])==0)!=0);
goto P_0c0cc7e4;
P_0c0cc7e4: /* original 8901, guest PC 0x0c0cc7e4 */
if(!s->budget--) { s->failed_pc=0x0c0cc7e4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0cc7ea; }
goto P_0c0cc7e6;
P_0c0cc7e6: /* original d137, guest PC 0x0c0cc7e6 */
if(!s->budget--) { s->failed_pc=0x0c0cc7e6u; return 0; }
r[1]=read(ram,0x0c0cc8c4u,4);
goto P_0c0cc7e8;
P_0c0cc7e8: /* original 2d1b, guest PC 0x0c0cc7e8 */
if(!s->budget--) { s->failed_pc=0x0c0cc7e8u; return 0; }
r[13]|=r[1];
goto P_0c0cc7ea;
P_0c0cc7ea: /* original d337, guest PC 0x0c0cc7ea */
if(!s->budget--) { s->failed_pc=0x0c0cc7eau; return 0; }
r[3]=read(ram,0x0c0cc8c8u,4);
goto P_0c0cc7ec;
P_0c0cc7ec: /* original 2348, guest PC 0x0c0cc7ec */
if(!s->budget--) { s->failed_pc=0x0c0cc7ecu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[4])==0)!=0);
goto P_0c0cc7ee;
P_0c0cc7ee: /* original 8901, guest PC 0x0c0cc7ee */
if(!s->budget--) { s->failed_pc=0x0c0cc7eeu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0cc7f4; }
goto P_0c0cc7f0;
P_0c0cc7f0: /* original d136, guest PC 0x0c0cc7f0 */
if(!s->budget--) { s->failed_pc=0x0c0cc7f0u; return 0; }
r[1]=read(ram,0x0c0cc8ccu,4);
goto P_0c0cc7f2;
P_0c0cc7f2: /* original 2d1b, guest PC 0x0c0cc7f2 */
if(!s->budget--) { s->failed_pc=0x0c0cc7f2u; return 0; }
r[13]|=r[1];
goto P_0c0cc7f4;
P_0c0cc7f4: /* original 9353, guest PC 0x0c0cc7f4 */
if(!s->budget--) { s->failed_pc=0x0c0cc7f4u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0cc89eu,2);
goto P_0c0cc7f6;
P_0c0cc7f6: /* original 2438, guest PC 0x0c0cc7f6 */
if(!s->budget--) { s->failed_pc=0x0c0cc7f6u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[3])==0)!=0);
goto P_0c0cc7f8;
P_0c0cc7f8: /* original 8d02, guest PC 0x0c0cc7f8 */
if(!s->budget--) { s->failed_pc=0x0c0cc7f8u; return 0; }
cond=r[17]&1u;
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+4,1);
if(cond) { goto P_0c0cc800; }
goto P_0c0cc7fc;
P_0c0cc7fa: /* original 84e4, guest PC 0x0c0cc7fa */
if(!s->budget--) { s->failed_pc=0x0c0cc7fau; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+4,1);
goto P_0c0cc7fc;
P_0c0cc7fc: /* original d134, guest PC 0x0c0cc7fc */
if(!s->budget--) { s->failed_pc=0x0c0cc7fcu; return 0; }
r[1]=read(ram,0x0c0cc8d0u,4);
goto P_0c0cc7fe;
P_0c0cc7fe: /* original 2d1b, guest PC 0x0c0cc7fe */
if(!s->budget--) { s->failed_pc=0x0c0cc7feu; return 0; }
r[13]|=r[1];
goto P_0c0cc800;
P_0c0cc800: /* original 600c, guest PC 0x0c0cc800 */
if(!s->budget--) { s->failed_pc=0x0c0cc800u; return 0; }
r[0]=r[0]&255u;
goto P_0c0cc802;
P_0c0cc802: /* original 924e, guest PC 0x0c0cc802 */
if(!s->budget--) { s->failed_pc=0x0c0cc802u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0cc8a2u,2);
goto P_0c0cc804;
P_0c0cc804: /* original 6303, guest PC 0x0c0cc804 */
if(!s->budget--) { s->failed_pc=0x0c0cc804u; return 0; }
r[3]=r[0];
goto P_0c0cc806;
P_0c0cc806: /* original 4008, guest PC 0x0c0cc806 */
if(!s->budget--) { s->failed_pc=0x0c0cc806u; return 0; }
r[0]<<=2;
goto P_0c0cc808;
P_0c0cc808: /* original 4008, guest PC 0x0c0cc808 */
if(!s->budget--) { s->failed_pc=0x0c0cc808u; return 0; }
r[0]<<=2;
goto P_0c0cc80a;
P_0c0cc80a: /* original 9849, guest PC 0x0c0cc80a */
if(!s->budget--) { s->failed_pc=0x0c0cc80au; return 0; }
r[8]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0cc8a0u,2);
goto P_0c0cc80c;
P_0c0cc80c: /* original 4000, guest PC 0x0c0cc80c */
if(!s->budget--) { s->failed_pc=0x0c0cc80cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]>>31)!=0);
r[0]<<=1;
goto P_0c0cc80e;
P_0c0cc80e: /* original 303c, guest PC 0x0c0cc80e */
if(!s->budget--) { s->failed_pc=0x0c0cc80eu; return 0; }
r[0]+=r[3];
goto P_0c0cc810;
P_0c0cc810: /* original d330, guest PC 0x0c0cc810 */
if(!s->budget--) { s->failed_pc=0x0c0cc810u; return 0; }
r[3]=read(ram,0x0c0cc8d4u,4);
goto P_0c0cc812;
P_0c0cc812: /* original 4008, guest PC 0x0c0cc812 */
if(!s->budget--) { s->failed_pc=0x0c0cc812u; return 0; }
r[0]<<=2;
goto P_0c0cc814;
P_0c0cc814: /* original 4008, guest PC 0x0c0cc814 */
if(!s->budget--) { s->failed_pc=0x0c0cc814u; return 0; }
r[0]<<=2;
goto P_0c0cc816;
P_0c0cc816: /* original 4008, guest PC 0x0c0cc816 */
if(!s->budget--) { s->failed_pc=0x0c0cc816u; return 0; }
r[0]<<=2;
goto P_0c0cc818;
P_0c0cc818: /* original 6a0f, guest PC 0x0c0cc818 */
if(!s->budget--) { s->failed_pc=0x0c0cc818u; return 0; }
r[10]=(uint32_t)(int32_t)(int16_t)r[0];
goto P_0c0cc81a;
P_0c0cc81a: /* original e061, guest PC 0x0c0cc81a */
if(!s->budget--) { s->failed_pc=0x0c0cc81au; return 0; }
r[0]=0x00000061u;
goto P_0c0cc81c;
P_0c0cc81c: /* original 00ec, guest PC 0x0c0cc81c */
if(!s->budget--) { s->failed_pc=0x0c0cc81cu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0cc81e;
P_0c0cc81e: /* original 3a3c, guest PC 0x0c0cc81e */
if(!s->budget--) { s->failed_pc=0x0c0cc81eu; return 0; }
r[10]+=r[3];
goto P_0c0cc820;
P_0c0cc820: /* original 3a2c, guest PC 0x0c0cc820 */
if(!s->budget--) { s->failed_pc=0x0c0cc820u; return 0; }
r[10]+=r[2];
goto P_0c0cc822;
P_0c0cc822: /* original 600c, guest PC 0x0c0cc822 */
if(!s->budget--) { s->failed_pc=0x0c0cc822u; return 0; }
r[0]=r[0]&255u;
goto P_0c0cc824;
P_0c0cc824: /* original 880c, guest PC 0x0c0cc824 */
if(!s->budget--) { s->failed_pc=0x0c0cc824u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000cu)!=0);
goto P_0c0cc826;
P_0c0cc826: /* original 38ec, guest PC 0x0c0cc826 */
if(!s->budget--) { s->failed_pc=0x0c0cc826u; return 0; }
r[8]+=r[14];
goto P_0c0cc828;
P_0c0cc828: /* original 8f01, guest PC 0x0c0cc828 */
if(!s->budget--) { s->failed_pc=0x0c0cc828u; return 0; }
cond=r[17]&1u;
r[11]=0x00000004u;
if(!cond) { goto P_0c0cc82e; }
goto P_0c0cc82c;
P_0c0cc82a: /* original eb04, guest PC 0x0c0cc82a */
if(!s->budget--) { s->failed_pc=0x0c0cc82au; return 0; }
r[11]=0x00000004u;
goto P_0c0cc82c;
P_0c0cc82c: /* original eb02, guest PC 0x0c0cc82c */
if(!s->budget--) { s->failed_pc=0x0c0cc82cu; return 0; }
r[11]=0x00000002u;
goto P_0c0cc82e;
P_0c0cc82e: /* original e061, guest PC 0x0c0cc82e */
if(!s->budget--) { s->failed_pc=0x0c0cc82eu; return 0; }
r[0]=0x00000061u;
goto P_0c0cc830;
P_0c0cc830: /* original 00ec, guest PC 0x0c0cc830 */
if(!s->budget--) { s->failed_pc=0x0c0cc830u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0cc832;
P_0c0cc832: /* original 600c, guest PC 0x0c0cc832 */
if(!s->budget--) { s->failed_pc=0x0c0cc832u; return 0; }
r[0]=r[0]&255u;
goto P_0c0cc834;
P_0c0cc834: /* original 8809, guest PC 0x0c0cc834 */
if(!s->budget--) { s->failed_pc=0x0c0cc834u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000009u)!=0);
goto P_0c0cc836;
P_0c0cc836: /* original 8b07, guest PC 0x0c0cc836 */
if(!s->budget--) { s->failed_pc=0x0c0cc836u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0cc848; }
goto P_0c0cc838;
P_0c0cc838: /* original 84e4, guest PC 0x0c0cc838 */
if(!s->budget--) { s->failed_pc=0x0c0cc838u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+4,1);
goto P_0c0cc83a;
P_0c0cc83a: /* original 9333, guest PC 0x0c0cc83a */
if(!s->budget--) { s->failed_pc=0x0c0cc83au; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0cc8a4u,2);
goto P_0c0cc83c;
P_0c0cc83c: /* original 600c, guest PC 0x0c0cc83c */
if(!s->budget--) { s->failed_pc=0x0c0cc83cu; return 0; }
r[0]=r[0]&255u;
goto P_0c0cc83e;
P_0c0cc83e: /* original 33cc, guest PC 0x0c0cc83e */
if(!s->budget--) { s->failed_pc=0x0c0cc83eu; return 0; }
r[3]+=r[12];
goto P_0c0cc840;
P_0c0cc840: /* original 4008, guest PC 0x0c0cc840 */
if(!s->budget--) { s->failed_pc=0x0c0cc840u; return 0; }
r[0]<<=2;
goto P_0c0cc842;
P_0c0cc842: /* original 303c, guest PC 0x0c0cc842 */
if(!s->budget--) { s->failed_pc=0x0c0cc842u; return 0; }
r[0]+=r[3];
goto P_0c0cc844;
P_0c0cc844: /* original f308, guest PC 0x0c0cc844 */
if(!s->budget--) { s->failed_pc=0x0c0cc844u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c0cc846;
P_0c0cc846: /* original ff32, guest PC 0x0c0cc846 */
if(!s->budget--) { s->failed_pc=0x0c0cc846u; return 0; }
fr[15]=vf3_fpu_binary(fr[15],fr[3],r[18],'*');
goto P_0c0cc848;
P_0c0cc848: /* original 6986, guest PC 0x0c0cc848 */
if(!s->budget--) { s->failed_pc=0x0c0cc848u; return 0; }
tmp=read(ram,r[8],4);
r[8]+=4;
r[9]=tmp;
goto P_0c0cc84a;
P_0c0cc84a: /* original ee08, guest PC 0x0c0cc84a */
if(!s->budget--) { s->failed_pc=0x0c0cc84au; return 0; }
r[14]=0x00000008u;
goto P_0c0cc84c;
P_0c0cc84c: /* original e308, guest PC 0x0c0cc84c */
if(!s->budget--) { s->failed_pc=0x0c0cc84cu; return 0; }
r[3]=0x00000008u;
goto P_0c0cc84e;
P_0c0cc84e: /* original d022, guest PC 0x0c0cc84e */
if(!s->budget--) { s->failed_pc=0x0c0cc84eu; return 0; }
r[0]=read(ram,0x0c0cc8d8u,4);
goto P_0c0cc850;
P_0c0cc850: /* original 33e8, guest PC 0x0c0cc850 */
if(!s->budget--) { s->failed_pc=0x0c0cc850u; return 0; }
r[3]-=r[14];
goto P_0c0cc852;
P_0c0cc852: /* original 4308, guest PC 0x0c0cc852 */
if(!s->budget--) { s->failed_pc=0x0c0cc852u; return 0; }
r[3]<<=2;
goto P_0c0cc854;
P_0c0cc854: /* original 023e, guest PC 0x0c0cc854 */
if(!s->budget--) { s->failed_pc=0x0c0cc854u; return 0; }
r[2]=read(ram,r[3]+r[0],4);
goto P_0c0cc856;
P_0c0cc856: /* original 22d8, guest PC 0x0c0cc856 */
if(!s->budget--) { s->failed_pc=0x0c0cc856u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[13])==0)!=0);
goto P_0c0cc858;
P_0c0cc858: /* original 8912, guest PC 0x0c0cc858 */
if(!s->budget--) { s->failed_pc=0x0c0cc858u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0cc880; }
goto P_0c0cc85a;
P_0c0cc85a: /* original 64a1, guest PC 0x0c0cc85a */
if(!s->budget--) { s->failed_pc=0x0c0cc85au; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[10],2);
r[4]=tmp;
goto P_0c0cc85c;
P_0c0cc85c: /* original 6c4f, guest PC 0x0c0cc85c */
if(!s->budget--) { s->failed_pc=0x0c0cc85cu; return 0; }
r[12]=(uint32_t)(int32_t)(int16_t)r[4];
goto P_0c0cc85e;
P_0c0cc85e: /* original 60c3, guest PC 0x0c0cc85e */
if(!s->budget--) { s->failed_pc=0x0c0cc85eu; return 0; }
r[0]=r[12];
goto P_0c0cc860;
P_0c0cc860: /* original 88ff, guest PC 0x0c0cc860 */
if(!s->budget--) { s->failed_pc=0x0c0cc860u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xffffffffu)!=0);
goto P_0c0cc862;
P_0c0cc862: /* original 890d, guest PC 0x0c0cc862 */
if(!s->budget--) { s->failed_pc=0x0c0cc862u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0cc880; }
goto P_0c0cc864;
P_0c0cc864: /* original d31d, guest PC 0x0c0cc864 */
if(!s->budget--) { s->failed_pc=0x0c0cc864u; return 0; }
r[3]=read(ram,0x0c0cc8dcu,4);
goto P_0c0cc866;
P_0c0cc866: /* original 430b, guest PC 0x0c0cc866 */
if(!s->budget--) { s->failed_pc=0x0c0cc866u; return 0; }
target=r[3];
r[16]=0x0c0cc86au;
r[4]=r[9];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0cc86au) { target=s->pc; goto dispatch; }
goto P_0c0cc86a;
P_0c0cc868: /* original 6493, guest PC 0x0c0cc868 */
if(!s->budget--) { s->failed_pc=0x0c0cc868u; return 0; }
r[4]=r[9];
goto P_0c0cc86a;
P_0c0cc86a: /* original e205, guest PC 0x0c0cc86a */
if(!s->budget--) { s->failed_pc=0x0c0cc86au; return 0; }
r[2]=0x00000005u;
goto P_0c0cc86c;
P_0c0cc86c: /* original 3e23, guest PC 0x0c0cc86c */
if(!s->budget--) { s->failed_pc=0x0c0cc86cu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[14]>=(int32_t)r[2])!=0);
goto P_0c0cc86e;
P_0c0cc86e: /* original 8903, guest PC 0x0c0cc86e */
if(!s->budget--) { s->failed_pc=0x0c0cc86eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0cc878; }
goto P_0c0cc870;
P_0c0cc870: /* original d11c, guest PC 0x0c0cc870 */
if(!s->budget--) { s->failed_pc=0x0c0cc870u; return 0; }
r[1]=read(ram,0x0c0cc8e4u,4);
goto P_0c0cc872;
P_0c0cc872: /* original d41b, guest PC 0x0c0cc872 */
if(!s->budget--) { s->failed_pc=0x0c0cc872u; return 0; }
r[4]=read(ram,0x0c0cc8e0u,4);
goto P_0c0cc874;
P_0c0cc874: /* original 410b, guest PC 0x0c0cc874 */
if(!s->budget--) { s->failed_pc=0x0c0cc874u; return 0; }
target=r[1];
r[16]=0x0c0cc878u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0cc878u) { target=s->pc; goto dispatch; }
goto P_0c0cc878;
P_0c0cc876: /* original 0009, guest PC 0x0c0cc876 */
if(!s->budget--) { s->failed_pc=0x0c0cc876u; return 0; }
goto P_0c0cc878;
P_0c0cc878: /* original d31b, guest PC 0x0c0cc878 */
if(!s->budget--) { s->failed_pc=0x0c0cc878u; return 0; }
r[3]=read(ram,0x0c0cc8e8u,4);
goto P_0c0cc87a;
P_0c0cc87a: /* original f4fc, guest PC 0x0c0cc87a */
if(!s->budget--) { s->failed_pc=0x0c0cc87au; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c0cc87c;
P_0c0cc87c: /* original 430b, guest PC 0x0c0cc87c */
if(!s->budget--) { s->failed_pc=0x0c0cc87cu; return 0; }
target=r[3];
r[16]=0x0c0cc880u;
r[4]=r[12];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0cc880u) { target=s->pc; goto dispatch; }
goto P_0c0cc880;
P_0c0cc87e: /* original 64c3, guest PC 0x0c0cc87e */
if(!s->budget--) { s->failed_pc=0x0c0cc87eu; return 0; }
r[4]=r[12];
goto P_0c0cc880;
P_0c0cc880: /* original 4e10, guest PC 0x0c0cc880 */
if(!s->budget--) { s->failed_pc=0x0c0cc880u; return 0; }
--r[14];
r[17]=(r[17]&~1u)|((r[14]==0)!=0);
goto P_0c0cc882;
P_0c0cc882: /* original 7940, guest PC 0x0c0cc882 */
if(!s->budget--) { s->failed_pc=0x0c0cc882u; return 0; }
r[9]+=0x00000040u;
goto P_0c0cc884;
P_0c0cc884: /* original 8fe2, guest PC 0x0c0cc884 */
if(!s->budget--) { s->failed_pc=0x0c0cc884u; return 0; }
cond=r[17]&1u;
r[10]+=0x00000002u;
if(!cond) { goto P_0c0cc84c; }
goto P_0c0cc888;
P_0c0cc886: /* original 7a02, guest PC 0x0c0cc886 */
if(!s->budget--) { s->failed_pc=0x0c0cc886u; return 0; }
r[10]+=0x00000002u;
goto P_0c0cc888;
P_0c0cc888: /* original c718, guest PC 0x0c0cc888 */
if(!s->budget--) { s->failed_pc=0x0c0cc888u; return 0; }
r[0]=0x0c0cc8ecu;
goto P_0c0cc88a;
P_0c0cc88a: /* original f308, guest PC 0x0c0cc88a */
if(!s->budget--) { s->failed_pc=0x0c0cc88au; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c0cc88c;
P_0c0cc88c: /* original 4b10, guest PC 0x0c0cc88c */
if(!s->budget--) { s->failed_pc=0x0c0cc88cu; return 0; }
--r[11];
r[17]=(r[17]&~1u)|((r[11]==0)!=0);
goto P_0c0cc88e;
P_0c0cc88e: /* original 8fdb, guest PC 0x0c0cc88e */
if(!s->budget--) { s->failed_pc=0x0c0cc88eu; return 0; }
cond=r[17]&1u;
fr[15]=vf3_fpu_binary(fr[15],fr[3],r[18],'*');
if(!cond) { goto P_0c0cc848; }
goto P_0c0cc892;
P_0c0cc890: /* original ff32, guest PC 0x0c0cc890 */
if(!s->budget--) { s->failed_pc=0x0c0cc890u; return 0; }
fr[15]=vf3_fpu_binary(fr[15],fr[3],r[18],'*');
goto P_0c0cc892;
P_0c0cc892: /* original 7f04, guest PC 0x0c0cc892 */
if(!s->budget--) { s->failed_pc=0x0c0cc892u; return 0; }
r[15]+=0x00000004u;
goto P_0c0cc894;
P_0c0cc894: /* original 4f26, guest PC 0x0c0cc894 */
if(!s->budget--) { s->failed_pc=0x0c0cc894u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0cc896;
P_0c0cc896: /* original e401, guest PC 0x0c0cc896 */
if(!s->budget--) { s->failed_pc=0x0c0cc896u; return 0; }
r[4]=0x00000001u;
goto P_0c0cc898;
P_0c0cc898: /* original a02a, guest PC 0x0c0cc898 */
if(!s->budget--) { s->failed_pc=0x0c0cc898u; return 0; }
goto P_0c0cc8f0;
P_0c0cc89a: /* original 0009, guest PC 0x0c0cc89a */
if(!s->budget--) { s->failed_pc=0x0c0cc89au; return 0; }
return vf3_matrix_family(0x0c0cc89cu,s,ram);
P_0c0cc8f0: /* original fff9, guest PC 0x0c0cc8f0 */
if(!s->budget--) { s->failed_pc=0x0c0cc8f0u; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0cc8f2;
P_0c0cc8f2: /* original d30a, guest PC 0x0c0cc8f2 */
if(!s->budget--) { s->failed_pc=0x0c0cc8f2u; return 0; }
r[3]=read(ram,0x0c0cc91cu,4);
goto P_0c0cc8f4;
P_0c0cc8f4: /* original 68f6, guest PC 0x0c0cc8f4 */
if(!s->budget--) { s->failed_pc=0x0c0cc8f4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c0cc8f6;
P_0c0cc8f6: /* original 69f6, guest PC 0x0c0cc8f6 */
if(!s->budget--) { s->failed_pc=0x0c0cc8f6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c0cc8f8;
P_0c0cc8f8: /* original 6af6, guest PC 0x0c0cc8f8 */
if(!s->budget--) { s->failed_pc=0x0c0cc8f8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0cc8fa;
P_0c0cc8fa: /* original 6bf6, guest PC 0x0c0cc8fa */
if(!s->budget--) { s->failed_pc=0x0c0cc8fau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0cc8fc;
P_0c0cc8fc: /* original 6cf6, guest PC 0x0c0cc8fc */
if(!s->budget--) { s->failed_pc=0x0c0cc8fcu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0cc8fe;
P_0c0cc8fe: /* original 6df6, guest PC 0x0c0cc8fe */
if(!s->budget--) { s->failed_pc=0x0c0cc8feu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0cc900;
P_0c0cc900: /* original 432b, guest PC 0x0c0cc900 */
if(!s->budget--) { s->failed_pc=0x0c0cc900u; return 0; }
target=r[3];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
switch(target&0x1fffffffu) {
case 0x0c03b450u: return vf3_matrix_family(target,s,ram);
case 0x0c03b4b0u: return vf3_matrix_family(target,s,ram);
case 0x0c03b530u: return vf3_matrix_family(target,s,ram);
case 0x0c03b620u: return vf3_matrix_family(target,s,ram);
case 0x0c03b820u: return vf3_matrix_family(target,s,ram);
case 0x0c03bd80u: return vf3_matrix_family(target,s,ram);
case 0x0c03c0e0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c4a0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c4f0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c610u: return vf3_matrix_family(target,s,ram);
case 0x0c03c6c0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c880u: return vf3_matrix_family(target,s,ram);
case 0x0c03c940u: return vf3_matrix_family(target,s,ram);
case 0x0c03c970u: return vf3_matrix_family(target,s,ram);
case 0x0c03cbd0u: return vf3_matrix_family(target,s,ram);
case 0x0c03cc60u: return vf3_matrix_family(target,s,ram);
case 0x0c03cc90u: return vf3_matrix_family(target,s,ram);
case 0x0c03ccb0u: return vf3_matrix_family(target,s,ram);
default: goto dispatch; }
P_0c0cc902: /* original 6ef6, guest PC 0x0c0cc902 */
if(!s->budget--) { s->failed_pc=0x0c0cc902u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0cc904;
P_0c0cc904: /* original 7f04, guest PC 0x0c0cc904 */
if(!s->budget--) { s->failed_pc=0x0c0cc904u; return 0; }
r[15]+=0x00000004u;
goto P_0c0cc906;
P_0c0cc906: /* original 4f26, guest PC 0x0c0cc906 */
if(!s->budget--) { s->failed_pc=0x0c0cc906u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0cc908;
P_0c0cc908: /* original fff9, guest PC 0x0c0cc908 */
if(!s->budget--) { s->failed_pc=0x0c0cc908u; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0cc90a;
P_0c0cc90a: /* original 68f6, guest PC 0x0c0cc90a */
if(!s->budget--) { s->failed_pc=0x0c0cc90au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c0cc90c;
P_0c0cc90c: /* original 69f6, guest PC 0x0c0cc90c */
if(!s->budget--) { s->failed_pc=0x0c0cc90cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c0cc90e;
P_0c0cc90e: /* original 6af6, guest PC 0x0c0cc90e */
if(!s->budget--) { s->failed_pc=0x0c0cc90eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0cc910;
P_0c0cc910: /* original 6bf6, guest PC 0x0c0cc910 */
if(!s->budget--) { s->failed_pc=0x0c0cc910u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0cc912;
P_0c0cc912: /* original 6cf6, guest PC 0x0c0cc912 */
if(!s->budget--) { s->failed_pc=0x0c0cc912u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0cc914;
P_0c0cc914: /* original 6df6, guest PC 0x0c0cc914 */
if(!s->budget--) { s->failed_pc=0x0c0cc914u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0cc916;
P_0c0cc916: /* original 000b, guest PC 0x0c0cc916 */
if(!s->budget--) { s->failed_pc=0x0c0cc916u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0cc918: /* original 6ef6, guest PC 0x0c0cc918 */
if(!s->budget--) { s->failed_pc=0x0c0cc918u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0cc91au,s,ram);
unsupported: s->failed_pc=target; return 0;
}
