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
int vf3_away_batch13_adapter_4(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
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
case 0x0c082e00u: goto P_0c082e00;
case 0x0c082e02u: goto P_0c082e02;
case 0x0c082e04u: goto P_0c082e04;
case 0x0c082e06u: goto P_0c082e06;
case 0x0c082e08u: goto P_0c082e08;
case 0x0c082e0au: goto P_0c082e0a;
case 0x0c082e0cu: goto P_0c082e0c;
case 0x0c082e0eu: goto P_0c082e0e;
case 0x0c082e10u: goto P_0c082e10;
case 0x0c082e12u: goto P_0c082e12;
case 0x0c082e14u: goto P_0c082e14;
case 0x0c082e16u: goto P_0c082e16;
case 0x0c082e18u: goto P_0c082e18;
case 0x0c082e1au: goto P_0c082e1a;
case 0x0c082e1cu: goto P_0c082e1c;
case 0x0c082e1eu: goto P_0c082e1e;
case 0x0c082e20u: goto P_0c082e20;
case 0x0c082e22u: goto P_0c082e22;
case 0x0c082e24u: goto P_0c082e24;
case 0x0c082e26u: goto P_0c082e26;
case 0x0c082e28u: goto P_0c082e28;
case 0x0c082e2au: goto P_0c082e2a;
case 0x0c082e2cu: goto P_0c082e2c;
case 0x0c082e2eu: goto P_0c082e2e;
case 0x0c082e30u: goto P_0c082e30;
case 0x0c082e32u: goto P_0c082e32;
case 0x0c082e34u: goto P_0c082e34;
case 0x0c082e36u: goto P_0c082e36;
case 0x0c082e38u: goto P_0c082e38;
case 0x0c082e3au: goto P_0c082e3a;
case 0x0c082e3cu: goto P_0c082e3c;
case 0x0c082e3eu: goto P_0c082e3e;
case 0x0c082e40u: goto P_0c082e40;
case 0x0c082e42u: goto P_0c082e42;
case 0x0c082e44u: goto P_0c082e44;
case 0x0c082e46u: goto P_0c082e46;
case 0x0c082e48u: goto P_0c082e48;
case 0x0c082e4au: goto P_0c082e4a;
case 0x0c082e4cu: goto P_0c082e4c;
case 0x0c082e4eu: goto P_0c082e4e;
case 0x0c082e50u: goto P_0c082e50;
case 0x0c082e52u: goto P_0c082e52;
case 0x0c082e54u: goto P_0c082e54;
case 0x0c082e56u: goto P_0c082e56;
case 0x0c082e58u: goto P_0c082e58;
case 0x0c082e5au: goto P_0c082e5a;
case 0x0c082e5cu: goto P_0c082e5c;
case 0x0c082e5eu: goto P_0c082e5e;
case 0x0c082e60u: goto P_0c082e60;
case 0x0c082e62u: goto P_0c082e62;
case 0x0c082e64u: goto P_0c082e64;
case 0x0c082e66u: goto P_0c082e66;
case 0x0c082ee4u: goto P_0c082ee4;
case 0x0c082ee6u: goto P_0c082ee6;
case 0x0c082ee8u: goto P_0c082ee8;
case 0x0c082eeau: goto P_0c082eea;
case 0x0c082eecu: goto P_0c082eec;
case 0x0c082eeeu: goto P_0c082eee;
case 0x0c082ef0u: goto P_0c082ef0;
case 0x0c082ef2u: goto P_0c082ef2;
case 0x0c082ef4u: goto P_0c082ef4;
case 0x0c082ef6u: goto P_0c082ef6;
case 0x0c082ef8u: goto P_0c082ef8;
case 0x0c082efau: goto P_0c082efa;
case 0x0c082efcu: goto P_0c082efc;
case 0x0c082efeu: goto P_0c082efe;
case 0x0c082f00u: goto P_0c082f00;
case 0x0c082f02u: goto P_0c082f02;
case 0x0c082f04u: goto P_0c082f04;
case 0x0c082f06u: goto P_0c082f06;
case 0x0c082f08u: goto P_0c082f08;
case 0x0c082f0au: goto P_0c082f0a;
case 0x0c082f0cu: goto P_0c082f0c;
case 0x0c0831b4u: goto P_0c0831b4;
case 0x0c0831b6u: goto P_0c0831b6;
case 0x0c0831b8u: goto P_0c0831b8;
case 0x0c0831bau: goto P_0c0831ba;
case 0x0c0831bcu: goto P_0c0831bc;
case 0x0c0831beu: goto P_0c0831be;
case 0x0c0831c0u: goto P_0c0831c0;
case 0x0c0831c2u: goto P_0c0831c2;
case 0x0c0831c4u: goto P_0c0831c4;
case 0x0c0831c6u: goto P_0c0831c6;
case 0x0c0831c8u: goto P_0c0831c8;
case 0x0c0831cau: goto P_0c0831ca;
case 0x0c0831ccu: goto P_0c0831cc;
case 0x0c0831ceu: goto P_0c0831ce;
case 0x0c0831d0u: goto P_0c0831d0;
case 0x0c0831d2u: goto P_0c0831d2;
case 0x0c0831d4u: goto P_0c0831d4;
case 0x0c0831d6u: goto P_0c0831d6;
case 0x0c0831d8u: goto P_0c0831d8;
case 0x0c0831dau: goto P_0c0831da;
case 0x0c0831dcu: goto P_0c0831dc;
case 0x0c0831deu: goto P_0c0831de;
case 0x0c0831e0u: goto P_0c0831e0;
case 0x0c0831e2u: goto P_0c0831e2;
case 0x0c0831e4u: goto P_0c0831e4;
case 0x0c0831e6u: goto P_0c0831e6;
case 0x0c0831e8u: goto P_0c0831e8;
case 0x0c0831eau: goto P_0c0831ea;
case 0x0c0831ecu: goto P_0c0831ec;
case 0x0c0831eeu: goto P_0c0831ee;
case 0x0c0831f0u: goto P_0c0831f0;
case 0x0c0831f2u: goto P_0c0831f2;
case 0x0c0831f4u: goto P_0c0831f4;
case 0x0c0831f6u: goto P_0c0831f6;
case 0x0c0831f8u: goto P_0c0831f8;
case 0x0c0831fau: goto P_0c0831fa;
case 0x0c0831fcu: goto P_0c0831fc;
case 0x0c0831feu: goto P_0c0831fe;
case 0x0c083200u: goto P_0c083200;
case 0x0c083202u: goto P_0c083202;
case 0x0c083204u: goto P_0c083204;
case 0x0c083206u: goto P_0c083206;
case 0x0c083208u: goto P_0c083208;
case 0x0c08320au: goto P_0c08320a;
case 0x0c08320cu: goto P_0c08320c;
case 0x0c08320eu: goto P_0c08320e;
case 0x0c083210u: goto P_0c083210;
case 0x0c083212u: goto P_0c083212;
case 0x0c083214u: goto P_0c083214;
case 0x0c083216u: goto P_0c083216;
case 0x0c083218u: goto P_0c083218;
case 0x0c08321au: goto P_0c08321a;
case 0x0c08321cu: goto P_0c08321c;
case 0x0c08321eu: goto P_0c08321e;
case 0x0c083220u: goto P_0c083220;
case 0x0c083222u: goto P_0c083222;
case 0x0c083224u: goto P_0c083224;
case 0x0c083226u: goto P_0c083226;
case 0x0c083228u: goto P_0c083228;
case 0x0c08322au: goto P_0c08322a;
case 0x0c08322cu: goto P_0c08322c;
case 0x0c08322eu: goto P_0c08322e;
case 0x0c083230u: goto P_0c083230;
case 0x0c083232u: goto P_0c083232;
case 0x0c083234u: goto P_0c083234;
case 0x0c083236u: goto P_0c083236;
case 0x0c083238u: goto P_0c083238;
case 0x0c08323au: goto P_0c08323a;
case 0x0c08323cu: goto P_0c08323c;
case 0x0c08323eu: goto P_0c08323e;
case 0x0c083240u: goto P_0c083240;
case 0x0c083242u: goto P_0c083242;
case 0x0c083244u: goto P_0c083244;
case 0x0c08327cu: goto P_0c08327c;
case 0x0c08327eu: goto P_0c08327e;
case 0x0c083280u: goto P_0c083280;
case 0x0c083282u: goto P_0c083282;
case 0x0c083284u: goto P_0c083284;
case 0x0c083286u: goto P_0c083286;
case 0x0c083288u: goto P_0c083288;
case 0x0c08328au: goto P_0c08328a;
case 0x0c08328cu: goto P_0c08328c;
case 0x0c08328eu: goto P_0c08328e;
case 0x0c083290u: goto P_0c083290;
case 0x0c083292u: goto P_0c083292;
case 0x0c083294u: goto P_0c083294;
case 0x0c083296u: goto P_0c083296;
case 0x0c083298u: goto P_0c083298;
case 0x0c08329au: goto P_0c08329a;
case 0x0c08329cu: goto P_0c08329c;
case 0x0c08329eu: goto P_0c08329e;
case 0x0c0832a0u: goto P_0c0832a0;
case 0x0c0832a2u: goto P_0c0832a2;
case 0x0c0832a4u: goto P_0c0832a4;
case 0x0c0832a6u: goto P_0c0832a6;
case 0x0c0832a8u: goto P_0c0832a8;
case 0x0c0832aau: goto P_0c0832aa;
case 0x0c0832acu: goto P_0c0832ac;
case 0x0c0832aeu: goto P_0c0832ae;
case 0x0c0832b0u: goto P_0c0832b0;
case 0x0c0832b2u: goto P_0c0832b2;
case 0x0c0832b4u: goto P_0c0832b4;
case 0x0c0832b6u: goto P_0c0832b6;
case 0x0c0832b8u: goto P_0c0832b8;
case 0x0c0832bau: goto P_0c0832ba;
case 0x0c0832bcu: goto P_0c0832bc;
case 0x0c0832beu: goto P_0c0832be;
case 0x0c0832c0u: goto P_0c0832c0;
case 0x0c0832c2u: goto P_0c0832c2;
case 0x0c0832c4u: goto P_0c0832c4;
case 0x0c0832c6u: goto P_0c0832c6;
case 0x0c0832c8u: goto P_0c0832c8;
case 0x0c0832cau: goto P_0c0832ca;
case 0x0c0832ccu: goto P_0c0832cc;
case 0x0c0832ceu: goto P_0c0832ce;
case 0x0c0832d0u: goto P_0c0832d0;
case 0x0c0832d2u: goto P_0c0832d2;
case 0x0c0832d4u: goto P_0c0832d4;
case 0x0c0832d6u: goto P_0c0832d6;
case 0x0c0832d8u: goto P_0c0832d8;
case 0x0c0832dau: goto P_0c0832da;
case 0x0c0832dcu: goto P_0c0832dc;
case 0x0c0832deu: goto P_0c0832de;
case 0x0c0832e0u: goto P_0c0832e0;
case 0x0c0832e2u: goto P_0c0832e2;
case 0x0c0832e4u: goto P_0c0832e4;
case 0x0c0832e6u: goto P_0c0832e6;
case 0x0c0832e8u: goto P_0c0832e8;
case 0x0c0832eau: goto P_0c0832ea;
case 0x0c0832ecu: goto P_0c0832ec;
case 0x0c0832eeu: goto P_0c0832ee;
case 0x0c0832f0u: goto P_0c0832f0;
case 0x0c0832f2u: goto P_0c0832f2;
case 0x0c0832f4u: goto P_0c0832f4;
case 0x0c0832f6u: goto P_0c0832f6;
case 0x0c0832f8u: goto P_0c0832f8;
case 0x0c0832fau: goto P_0c0832fa;
case 0x0c0832fcu: goto P_0c0832fc;
case 0x0c0832feu: goto P_0c0832fe;
case 0x0c083300u: goto P_0c083300;
case 0x0c083302u: goto P_0c083302;
case 0x0c083304u: goto P_0c083304;
case 0x0c083306u: goto P_0c083306;
case 0x0c083308u: goto P_0c083308;
case 0x0c08330au: goto P_0c08330a;
case 0x0c08330cu: goto P_0c08330c;
case 0x0c08330eu: goto P_0c08330e;
case 0x0c083310u: goto P_0c083310;
case 0x0c083312u: goto P_0c083312;
case 0x0c083314u: goto P_0c083314;
case 0x0c083316u: goto P_0c083316;
case 0x0c083318u: goto P_0c083318;
case 0x0c08331au: goto P_0c08331a;
case 0x0c08331cu: goto P_0c08331c;
case 0x0c08331eu: goto P_0c08331e;
case 0x0c083320u: goto P_0c083320;
case 0x0c083322u: goto P_0c083322;
case 0x0c083324u: goto P_0c083324;
case 0x0c083326u: goto P_0c083326;
case 0x0c083328u: goto P_0c083328;
case 0x0c08332au: goto P_0c08332a;
case 0x0c08332cu: goto P_0c08332c;
case 0x0c08332eu: goto P_0c08332e;
case 0x0c083330u: goto P_0c083330;
case 0x0c083332u: goto P_0c083332;
case 0x0c083334u: goto P_0c083334;
case 0x0c083336u: goto P_0c083336;
case 0x0c083338u: goto P_0c083338;
case 0x0c08333au: goto P_0c08333a;
case 0x0c08333cu: goto P_0c08333c;
case 0x0c08333eu: goto P_0c08333e;
case 0x0c083340u: goto P_0c083340;
case 0x0c083342u: goto P_0c083342;
case 0x0c083344u: goto P_0c083344;
case 0x0c083346u: goto P_0c083346;
case 0x0c083348u: goto P_0c083348;
case 0x0c08334au: goto P_0c08334a;
case 0x0c08334cu: goto P_0c08334c;
case 0x0c08334eu: goto P_0c08334e;
case 0x0c083350u: goto P_0c083350;
case 0x0c083352u: goto P_0c083352;
case 0x0c083354u: goto P_0c083354;
case 0x0c083356u: goto P_0c083356;
case 0x0c083358u: goto P_0c083358;
case 0x0c08335au: goto P_0c08335a;
case 0x0c08335cu: goto P_0c08335c;
case 0x0c08335eu: goto P_0c08335e;
case 0x0c083360u: goto P_0c083360;
case 0x0c083362u: goto P_0c083362;
case 0x0c083364u: goto P_0c083364;
case 0x0c083384u: goto P_0c083384;
case 0x0c083386u: goto P_0c083386;
case 0x0c083388u: goto P_0c083388;
case 0x0c08338au: goto P_0c08338a;
case 0x0c08338cu: goto P_0c08338c;
case 0x0c08338eu: goto P_0c08338e;
case 0x0c083390u: goto P_0c083390;
case 0x0c083392u: goto P_0c083392;
case 0x0c083394u: goto P_0c083394;
case 0x0c083396u: goto P_0c083396;
case 0x0c083398u: goto P_0c083398;
case 0x0c08339au: goto P_0c08339a;
case 0x0c08339cu: goto P_0c08339c;
case 0x0c08339eu: goto P_0c08339e;
case 0x0c0833a0u: goto P_0c0833a0;
case 0x0c0833a2u: goto P_0c0833a2;
case 0x0c0833a4u: goto P_0c0833a4;
case 0x0c0833a6u: goto P_0c0833a6;
case 0x0c0833a8u: goto P_0c0833a8;
case 0x0c0833aau: goto P_0c0833aa;
case 0x0c0833acu: goto P_0c0833ac;
case 0x0c0833aeu: goto P_0c0833ae;
case 0x0c0833b0u: goto P_0c0833b0;
case 0x0c0833b2u: goto P_0c0833b2;
case 0x0c0833b4u: goto P_0c0833b4;
case 0x0c0833b6u: goto P_0c0833b6;
case 0x0c0833b8u: goto P_0c0833b8;
case 0x0c0833bau: goto P_0c0833ba;
case 0x0c0833bcu: goto P_0c0833bc;
case 0x0c0833beu: goto P_0c0833be;
case 0x0c0833c0u: goto P_0c0833c0;
case 0x0c0833c2u: goto P_0c0833c2;
case 0x0c0833c4u: goto P_0c0833c4;
case 0x0c0833c6u: goto P_0c0833c6;
case 0x0c0833c8u: goto P_0c0833c8;
case 0x0c0833cau: goto P_0c0833ca;
case 0x0c0833ccu: goto P_0c0833cc;
case 0x0c0833ceu: goto P_0c0833ce;
case 0x0c0833d0u: goto P_0c0833d0;
case 0x0c0833d2u: goto P_0c0833d2;
case 0x0c0833d4u: goto P_0c0833d4;
case 0x0c0833d6u: goto P_0c0833d6;
case 0x0c0833d8u: goto P_0c0833d8;
case 0x0c0833dau: goto P_0c0833da;
case 0x0c0833dcu: goto P_0c0833dc;
case 0x0c0833deu: goto P_0c0833de;
case 0x0c0833e0u: goto P_0c0833e0;
case 0x0c0833e2u: goto P_0c0833e2;
case 0x0c0833e4u: goto P_0c0833e4;
case 0x0c0833e6u: goto P_0c0833e6;
case 0x0c0833e8u: goto P_0c0833e8;
case 0x0c0833eau: goto P_0c0833ea;
case 0x0c0833ecu: goto P_0c0833ec;
case 0x0c0833eeu: goto P_0c0833ee;
case 0x0c0833f0u: goto P_0c0833f0;
case 0x0c0833f2u: goto P_0c0833f2;
case 0x0c0833f4u: goto P_0c0833f4;
case 0x0c0833f6u: goto P_0c0833f6;
case 0x0c0833f8u: goto P_0c0833f8;
case 0x0c0833fau: goto P_0c0833fa;
case 0x0c0833fcu: goto P_0c0833fc;
case 0x0c0833feu: goto P_0c0833fe;
case 0x0c083400u: goto P_0c083400;
case 0x0c083402u: goto P_0c083402;
case 0x0c083404u: goto P_0c083404;
case 0x0c083406u: goto P_0c083406;
case 0x0c083408u: goto P_0c083408;
case 0x0c08340au: goto P_0c08340a;
case 0x0c08340cu: goto P_0c08340c;
case 0x0c08340eu: goto P_0c08340e;
case 0x0c083410u: goto P_0c083410;
case 0x0c083412u: goto P_0c083412;
case 0x0c083414u: goto P_0c083414;
case 0x0c083416u: goto P_0c083416;
case 0x0c083418u: goto P_0c083418;
case 0x0c08341au: goto P_0c08341a;
case 0x0c08341cu: goto P_0c08341c;
case 0x0c08341eu: goto P_0c08341e;
case 0x0c083420u: goto P_0c083420;
case 0x0c083422u: goto P_0c083422;
case 0x0c083424u: goto P_0c083424;
case 0x0c083426u: goto P_0c083426;
case 0x0c083428u: goto P_0c083428;
case 0x0c08342au: goto P_0c08342a;
case 0x0c08342cu: goto P_0c08342c;
case 0x0c08342eu: goto P_0c08342e;
case 0x0c083430u: goto P_0c083430;
case 0x0c083432u: goto P_0c083432;
case 0x0c083434u: goto P_0c083434;
case 0x0c083436u: goto P_0c083436;
case 0x0c083438u: goto P_0c083438;
case 0x0c08343au: goto P_0c08343a;
case 0x0c08343cu: goto P_0c08343c;
case 0x0c08343eu: goto P_0c08343e;
case 0x0c083440u: goto P_0c083440;
case 0x0c083442u: goto P_0c083442;
case 0x0c083444u: goto P_0c083444;
case 0x0c083446u: goto P_0c083446;
case 0x0c083448u: goto P_0c083448;
case 0x0c08344au: goto P_0c08344a;
case 0x0c08344cu: goto P_0c08344c;
case 0x0c08344eu: goto P_0c08344e;
case 0x0c083450u: goto P_0c083450;
case 0x0c083452u: goto P_0c083452;
case 0x0c083454u: goto P_0c083454;
case 0x0c083456u: goto P_0c083456;
case 0x0c083458u: goto P_0c083458;
case 0x0c08345au: goto P_0c08345a;
case 0x0c08345cu: goto P_0c08345c;
case 0x0c08345eu: goto P_0c08345e;
case 0x0c083460u: goto P_0c083460;
case 0x0c083462u: goto P_0c083462;
case 0x0c083464u: goto P_0c083464;
case 0x0c083466u: goto P_0c083466;
case 0x0c083468u: goto P_0c083468;
case 0x0c08346au: goto P_0c08346a;
case 0x0c08346cu: goto P_0c08346c;
case 0x0c08346eu: goto P_0c08346e;
case 0x0c083470u: goto P_0c083470;
case 0x0c083472u: goto P_0c083472;
case 0x0c083474u: goto P_0c083474;
case 0x0c083476u: goto P_0c083476;
case 0x0c083478u: goto P_0c083478;
case 0x0c08347au: goto P_0c08347a;
case 0x0c08347cu: goto P_0c08347c;
case 0x0c08347eu: goto P_0c08347e;
case 0x0c083480u: goto P_0c083480;
case 0x0c083482u: goto P_0c083482;
case 0x0c083484u: goto P_0c083484;
case 0x0c083486u: goto P_0c083486;
case 0x0c083488u: goto P_0c083488;
case 0x0c08348au: goto P_0c08348a;
case 0x0c08348cu: goto P_0c08348c;
case 0x0c08348eu: goto P_0c08348e;
case 0x0c083490u: goto P_0c083490;
case 0x0c083492u: goto P_0c083492;
case 0x0c0834b0u: goto P_0c0834b0;
case 0x0c0834b2u: goto P_0c0834b2;
case 0x0c0834b4u: goto P_0c0834b4;
case 0x0c0834b6u: goto P_0c0834b6;
case 0x0c0834b8u: goto P_0c0834b8;
case 0x0c0834bau: goto P_0c0834ba;
case 0x0c0834bcu: goto P_0c0834bc;
case 0x0c0834beu: goto P_0c0834be;
case 0x0c0834c0u: goto P_0c0834c0;
case 0x0c0834c2u: goto P_0c0834c2;
case 0x0c0834c4u: goto P_0c0834c4;
case 0x0c0834c6u: goto P_0c0834c6;
case 0x0c0834c8u: goto P_0c0834c8;
case 0x0c0834cau: goto P_0c0834ca;
case 0x0c0834ccu: goto P_0c0834cc;
case 0x0c0834ceu: goto P_0c0834ce;
case 0x0c0834d0u: goto P_0c0834d0;
case 0x0c0834d2u: goto P_0c0834d2;
case 0x0c0834d4u: goto P_0c0834d4;
case 0x0c0834d6u: goto P_0c0834d6;
case 0x0c0834d8u: goto P_0c0834d8;
case 0x0c0834dau: goto P_0c0834da;
case 0x0c0834dcu: goto P_0c0834dc;
case 0x0c0834deu: goto P_0c0834de;
case 0x0c0834e0u: goto P_0c0834e0;
case 0x0c0834e2u: goto P_0c0834e2;
case 0x0c0834e4u: goto P_0c0834e4;
case 0x0c0834e6u: goto P_0c0834e6;
case 0x0c0834e8u: goto P_0c0834e8;
case 0x0c0834eau: goto P_0c0834ea;
case 0x0c0834ecu: goto P_0c0834ec;
case 0x0c0834eeu: goto P_0c0834ee;
case 0x0c0834f0u: goto P_0c0834f0;
case 0x0c0834f2u: goto P_0c0834f2;
case 0x0c0834f4u: goto P_0c0834f4;
case 0x0c0834f6u: goto P_0c0834f6;
case 0x0c0834f8u: goto P_0c0834f8;
case 0x0c0834fau: goto P_0c0834fa;
case 0x0c0834fcu: goto P_0c0834fc;
case 0x0c0834feu: goto P_0c0834fe;
case 0x0c083500u: goto P_0c083500;
case 0x0c083502u: goto P_0c083502;
case 0x0c083504u: goto P_0c083504;
case 0x0c083506u: goto P_0c083506;
case 0x0c083508u: goto P_0c083508;
case 0x0c08350au: goto P_0c08350a;
case 0x0c08350cu: goto P_0c08350c;
case 0x0c08350eu: goto P_0c08350e;
case 0x0c083510u: goto P_0c083510;
case 0x0c083512u: goto P_0c083512;
case 0x0c083514u: goto P_0c083514;
case 0x0c083516u: goto P_0c083516;
case 0x0c083518u: goto P_0c083518;
case 0x0c08351au: goto P_0c08351a;
case 0x0c08351cu: goto P_0c08351c;
case 0x0c08351eu: goto P_0c08351e;
case 0x0c083520u: goto P_0c083520;
case 0x0c083522u: goto P_0c083522;
case 0x0c083524u: goto P_0c083524;
case 0x0c083526u: goto P_0c083526;
case 0x0c083528u: goto P_0c083528;
case 0x0c08352au: goto P_0c08352a;
case 0x0c08352cu: goto P_0c08352c;
case 0x0c08352eu: goto P_0c08352e;
case 0x0c083530u: goto P_0c083530;
case 0x0c083532u: goto P_0c083532;
case 0x0c083534u: goto P_0c083534;
case 0x0c083536u: goto P_0c083536;
case 0x0c083538u: goto P_0c083538;
case 0x0c08353au: goto P_0c08353a;
case 0x0c08353cu: goto P_0c08353c;
case 0x0c08353eu: goto P_0c08353e;
case 0x0c083540u: goto P_0c083540;
case 0x0c083542u: goto P_0c083542;
case 0x0c083544u: goto P_0c083544;
case 0x0c083546u: goto P_0c083546;
case 0x0c083548u: goto P_0c083548;
case 0x0c08354au: goto P_0c08354a;
case 0x0c08354cu: goto P_0c08354c;
case 0x0c08354eu: goto P_0c08354e;
case 0x0c083550u: goto P_0c083550;
case 0x0c083552u: goto P_0c083552;
case 0x0c083554u: goto P_0c083554;
case 0x0c083556u: goto P_0c083556;
case 0x0c083558u: goto P_0c083558;
case 0x0c08355au: goto P_0c08355a;
case 0x0c08355cu: goto P_0c08355c;
case 0x0c08355eu: goto P_0c08355e;
case 0x0c083560u: goto P_0c083560;
case 0x0c083562u: goto P_0c083562;
case 0x0c083564u: goto P_0c083564;
case 0x0c083566u: goto P_0c083566;
case 0x0c083568u: goto P_0c083568;
case 0x0c08356au: goto P_0c08356a;
case 0x0c08356cu: goto P_0c08356c;
case 0x0c08356eu: goto P_0c08356e;
case 0x0c083570u: goto P_0c083570;
case 0x0c083572u: goto P_0c083572;
case 0x0c083574u: goto P_0c083574;
case 0x0c083576u: goto P_0c083576;
case 0x0c083578u: goto P_0c083578;
case 0x0c08357au: goto P_0c08357a;
case 0x0c08357cu: goto P_0c08357c;
case 0x0c08357eu: goto P_0c08357e;
case 0x0c083580u: goto P_0c083580;
case 0x0c083582u: goto P_0c083582;
case 0x0c083584u: goto P_0c083584;
case 0x0c083586u: goto P_0c083586;
case 0x0c083588u: goto P_0c083588;
case 0x0c08358au: goto P_0c08358a;
case 0x0c08358cu: goto P_0c08358c;
case 0x0c08358eu: goto P_0c08358e;
case 0x0c083590u: goto P_0c083590;
case 0x0c083592u: goto P_0c083592;
case 0x0c083594u: goto P_0c083594;
case 0x0c083596u: goto P_0c083596;
case 0x0c083598u: goto P_0c083598;
case 0x0c08359au: goto P_0c08359a;
case 0x0c08359cu: goto P_0c08359c;
case 0x0c08359eu: goto P_0c08359e;
case 0x0c0835a0u: goto P_0c0835a0;
case 0x0c0835a2u: goto P_0c0835a2;
case 0x0c0835a4u: goto P_0c0835a4;
case 0x0c0835a6u: goto P_0c0835a6;
case 0x0c0835a8u: goto P_0c0835a8;
case 0x0c0835c4u: goto P_0c0835c4;
case 0x0c0835c6u: goto P_0c0835c6;
case 0x0c0835c8u: goto P_0c0835c8;
case 0x0c0835cau: goto P_0c0835ca;
case 0x0c0835ccu: goto P_0c0835cc;
case 0x0c0835ceu: goto P_0c0835ce;
case 0x0c0835d0u: goto P_0c0835d0;
case 0x0c0835d2u: goto P_0c0835d2;
case 0x0c0835d4u: goto P_0c0835d4;
case 0x0c0835d6u: goto P_0c0835d6;
case 0x0c0835d8u: goto P_0c0835d8;
case 0x0c0835dau: goto P_0c0835da;
case 0x0c0835dcu: goto P_0c0835dc;
case 0x0c0835deu: goto P_0c0835de;
case 0x0c0835e0u: goto P_0c0835e0;
case 0x0c0835e2u: goto P_0c0835e2;
case 0x0c0835e4u: goto P_0c0835e4;
case 0x0c0835e6u: goto P_0c0835e6;
case 0x0c0835e8u: goto P_0c0835e8;
case 0x0c0835eau: goto P_0c0835ea;
case 0x0c0835ecu: goto P_0c0835ec;
case 0x0c0835eeu: goto P_0c0835ee;
case 0x0c0835f0u: goto P_0c0835f0;
case 0x0c0835f2u: goto P_0c0835f2;
case 0x0c0835f4u: goto P_0c0835f4;
case 0x0c0835f6u: goto P_0c0835f6;
case 0x0c0835f8u: goto P_0c0835f8;
case 0x0c0835fau: goto P_0c0835fa;
case 0x0c0835fcu: goto P_0c0835fc;
case 0x0c0835feu: goto P_0c0835fe;
case 0x0c083600u: goto P_0c083600;
case 0x0c083602u: goto P_0c083602;
case 0x0c083604u: goto P_0c083604;
case 0x0c083606u: goto P_0c083606;
case 0x0c083608u: goto P_0c083608;
case 0x0c08360au: goto P_0c08360a;
case 0x0c08360cu: goto P_0c08360c;
case 0x0c08360eu: goto P_0c08360e;
case 0x0c083610u: goto P_0c083610;
case 0x0c083612u: goto P_0c083612;
case 0x0c083614u: goto P_0c083614;
case 0x0c083616u: goto P_0c083616;
case 0x0c083618u: goto P_0c083618;
case 0x0c08361au: goto P_0c08361a;
case 0x0c08361cu: goto P_0c08361c;
case 0x0c08361eu: goto P_0c08361e;
case 0x0c083620u: goto P_0c083620;
case 0x0c083622u: goto P_0c083622;
case 0x0c083624u: goto P_0c083624;
case 0x0c083626u: goto P_0c083626;
case 0x0c083628u: goto P_0c083628;
case 0x0c08362au: goto P_0c08362a;
case 0x0c08362cu: goto P_0c08362c;
case 0x0c08362eu: goto P_0c08362e;
case 0x0c083630u: goto P_0c083630;
case 0x0c083632u: goto P_0c083632;
case 0x0c083634u: goto P_0c083634;
case 0x0c083636u: goto P_0c083636;
case 0x0c083638u: goto P_0c083638;
case 0x0c08363au: goto P_0c08363a;
case 0x0c08363cu: goto P_0c08363c;
case 0x0c08363eu: goto P_0c08363e;
case 0x0c083640u: goto P_0c083640;
case 0x0c083642u: goto P_0c083642;
case 0x0c083644u: goto P_0c083644;
case 0x0c083646u: goto P_0c083646;
case 0x0c083648u: goto P_0c083648;
case 0x0c08364au: goto P_0c08364a;
case 0x0c08364cu: goto P_0c08364c;
case 0x0c08364eu: goto P_0c08364e;
case 0x0c083650u: goto P_0c083650;
case 0x0c083652u: goto P_0c083652;
case 0x0c083654u: goto P_0c083654;
case 0x0c083656u: goto P_0c083656;
case 0x0c083658u: goto P_0c083658;
case 0x0c08365au: goto P_0c08365a;
case 0x0c08365cu: goto P_0c08365c;
case 0x0c08365eu: goto P_0c08365e;
case 0x0c083660u: goto P_0c083660;
case 0x0c083662u: goto P_0c083662;
case 0x0c083664u: goto P_0c083664;
case 0x0c083666u: goto P_0c083666;
case 0x0c083668u: goto P_0c083668;
case 0x0c08366au: goto P_0c08366a;
case 0x0c08366cu: goto P_0c08366c;
case 0x0c08366eu: goto P_0c08366e;
case 0x0c083670u: goto P_0c083670;
case 0x0c083672u: goto P_0c083672;
case 0x0c083674u: goto P_0c083674;
case 0x0c083676u: goto P_0c083676;
case 0x0c083678u: goto P_0c083678;
case 0x0c08367au: goto P_0c08367a;
case 0x0c08367cu: goto P_0c08367c;
case 0x0c08367eu: goto P_0c08367e;
case 0x0c083680u: goto P_0c083680;
case 0x0c083682u: goto P_0c083682;
case 0x0c083684u: goto P_0c083684;
case 0x0c083686u: goto P_0c083686;
case 0x0c083688u: goto P_0c083688;
case 0x0c08368au: goto P_0c08368a;
case 0x0c08368cu: goto P_0c08368c;
case 0x0c08368eu: goto P_0c08368e;
case 0x0c083690u: goto P_0c083690;
case 0x0c083692u: goto P_0c083692;
case 0x0c083694u: goto P_0c083694;
case 0x0c083696u: goto P_0c083696;
case 0x0c083698u: goto P_0c083698;
case 0x0c08369au: goto P_0c08369a;
case 0x0c08369cu: goto P_0c08369c;
case 0x0c08369eu: goto P_0c08369e;
case 0x0c0836a0u: goto P_0c0836a0;
case 0x0c0836a2u: goto P_0c0836a2;
case 0x0c0836a4u: goto P_0c0836a4;
case 0x0c0836a6u: goto P_0c0836a6;
case 0x0c0836a8u: goto P_0c0836a8;
case 0x0c0836aau: goto P_0c0836aa;
case 0x0c0836acu: goto P_0c0836ac;
case 0x0c0836aeu: goto P_0c0836ae;
case 0x0c0836b0u: goto P_0c0836b0;
case 0x0c0836b2u: goto P_0c0836b2;
case 0x0c0836b4u: goto P_0c0836b4;
case 0x0c0836b6u: goto P_0c0836b6;
case 0x0c0836b8u: goto P_0c0836b8;
case 0x0c0836bau: goto P_0c0836ba;
case 0x0c0836bcu: goto P_0c0836bc;
case 0x0c0836beu: goto P_0c0836be;
case 0x0c0836c0u: goto P_0c0836c0;
case 0x0c0836c2u: goto P_0c0836c2;
case 0x0c0836c4u: goto P_0c0836c4;
case 0x0c0836c6u: goto P_0c0836c6;
case 0x0c0836c8u: goto P_0c0836c8;
case 0x0c0836cau: goto P_0c0836ca;
case 0x0c0836ccu: goto P_0c0836cc;
case 0x0c0836ceu: goto P_0c0836ce;
case 0x0c0836d0u: goto P_0c0836d0;
case 0x0c0836d2u: goto P_0c0836d2;
case 0x0c0836d4u: goto P_0c0836d4;
case 0x0c0836f0u: goto P_0c0836f0;
case 0x0c0836f2u: goto P_0c0836f2;
case 0x0c0836f4u: goto P_0c0836f4;
case 0x0c0836f6u: goto P_0c0836f6;
case 0x0c0836f8u: goto P_0c0836f8;
case 0x0c0836fau: goto P_0c0836fa;
case 0x0c0836fcu: goto P_0c0836fc;
case 0x0c0836feu: goto P_0c0836fe;
case 0x0c083700u: goto P_0c083700;
case 0x0c083702u: goto P_0c083702;
case 0x0c083704u: goto P_0c083704;
case 0x0c083706u: goto P_0c083706;
case 0x0c083708u: goto P_0c083708;
case 0x0c08370au: goto P_0c08370a;
case 0x0c08370cu: goto P_0c08370c;
case 0x0c08370eu: goto P_0c08370e;
case 0x0c083710u: goto P_0c083710;
case 0x0c083712u: goto P_0c083712;
case 0x0c083714u: goto P_0c083714;
case 0x0c083716u: goto P_0c083716;
case 0x0c083718u: goto P_0c083718;
case 0x0c08371au: goto P_0c08371a;
case 0x0c08371cu: goto P_0c08371c;
case 0x0c08371eu: goto P_0c08371e;
case 0x0c083720u: goto P_0c083720;
case 0x0c083722u: goto P_0c083722;
case 0x0c083724u: goto P_0c083724;
case 0x0c083726u: goto P_0c083726;
case 0x0c083728u: goto P_0c083728;
case 0x0c08372au: goto P_0c08372a;
case 0x0c08372cu: goto P_0c08372c;
case 0x0c08372eu: goto P_0c08372e;
case 0x0c083730u: goto P_0c083730;
case 0x0c083732u: goto P_0c083732;
case 0x0c083734u: goto P_0c083734;
case 0x0c083736u: goto P_0c083736;
case 0x0c083738u: goto P_0c083738;
case 0x0c08373au: goto P_0c08373a;
case 0x0c08373cu: goto P_0c08373c;
case 0x0c08373eu: goto P_0c08373e;
case 0x0c083740u: goto P_0c083740;
case 0x0c083742u: goto P_0c083742;
case 0x0c083744u: goto P_0c083744;
case 0x0c083746u: goto P_0c083746;
case 0x0c083748u: goto P_0c083748;
case 0x0c08374au: goto P_0c08374a;
case 0x0c08374cu: goto P_0c08374c;
case 0x0c08374eu: goto P_0c08374e;
case 0x0c083750u: goto P_0c083750;
case 0x0c083752u: goto P_0c083752;
case 0x0c083754u: goto P_0c083754;
case 0x0c083756u: goto P_0c083756;
case 0x0c083758u: goto P_0c083758;
case 0x0c08375au: goto P_0c08375a;
case 0x0c08375cu: goto P_0c08375c;
case 0x0c08375eu: goto P_0c08375e;
case 0x0c083760u: goto P_0c083760;
case 0x0c083762u: goto P_0c083762;
case 0x0c083764u: goto P_0c083764;
case 0x0c083766u: goto P_0c083766;
case 0x0c083768u: goto P_0c083768;
case 0x0c08376au: goto P_0c08376a;
case 0x0c08376cu: goto P_0c08376c;
case 0x0c08376eu: goto P_0c08376e;
case 0x0c083770u: goto P_0c083770;
case 0x0c083772u: goto P_0c083772;
case 0x0c083774u: goto P_0c083774;
case 0x0c083776u: goto P_0c083776;
case 0x0c083778u: goto P_0c083778;
case 0x0c08377au: goto P_0c08377a;
case 0x0c08377cu: goto P_0c08377c;
case 0x0c08377eu: goto P_0c08377e;
case 0x0c083780u: goto P_0c083780;
case 0x0c083782u: goto P_0c083782;
case 0x0c083784u: goto P_0c083784;
case 0x0c083786u: goto P_0c083786;
case 0x0c083788u: goto P_0c083788;
case 0x0c08378au: goto P_0c08378a;
case 0x0c08378cu: goto P_0c08378c;
case 0x0c08378eu: goto P_0c08378e;
case 0x0c083790u: goto P_0c083790;
case 0x0c083792u: goto P_0c083792;
case 0x0c083794u: goto P_0c083794;
case 0x0c083796u: goto P_0c083796;
case 0x0c083798u: goto P_0c083798;
case 0x0c08379au: goto P_0c08379a;
case 0x0c08379cu: goto P_0c08379c;
case 0x0c08379eu: goto P_0c08379e;
case 0x0c0837a0u: goto P_0c0837a0;
case 0x0c0837a2u: goto P_0c0837a2;
case 0x0c0837a4u: goto P_0c0837a4;
case 0x0c0837a6u: goto P_0c0837a6;
case 0x0c0837a8u: goto P_0c0837a8;
case 0x0c0837aau: goto P_0c0837aa;
case 0x0c0837acu: goto P_0c0837ac;
case 0x0c0837aeu: goto P_0c0837ae;
case 0x0c0837b0u: goto P_0c0837b0;
case 0x0c0837b2u: goto P_0c0837b2;
case 0x0c0837b4u: goto P_0c0837b4;
case 0x0c0837b6u: goto P_0c0837b6;
case 0x0c0837b8u: goto P_0c0837b8;
case 0x0c0837bau: goto P_0c0837ba;
case 0x0c0837bcu: goto P_0c0837bc;
case 0x0c0837beu: goto P_0c0837be;
case 0x0c0837c0u: goto P_0c0837c0;
case 0x0c0837c2u: goto P_0c0837c2;
case 0x0c0837c4u: goto P_0c0837c4;
case 0x0c0837c6u: goto P_0c0837c6;
case 0x0c0837c8u: goto P_0c0837c8;
case 0x0c0837cau: goto P_0c0837ca;
case 0x0c0837ccu: goto P_0c0837cc;
case 0x0c0837ceu: goto P_0c0837ce;
case 0x0c0837d0u: goto P_0c0837d0;
case 0x0c0837d2u: goto P_0c0837d2;
case 0x0c0837d4u: goto P_0c0837d4;
case 0x0c0837d6u: goto P_0c0837d6;
case 0x0c0837d8u: goto P_0c0837d8;
case 0x0c0837dau: goto P_0c0837da;
case 0x0c0837dcu: goto P_0c0837dc;
case 0x0c0837deu: goto P_0c0837de;
case 0x0c0837e0u: goto P_0c0837e0;
case 0x0c0837e2u: goto P_0c0837e2;
case 0x0c0837e4u: goto P_0c0837e4;
case 0x0c0837e6u: goto P_0c0837e6;
case 0x0c0837e8u: goto P_0c0837e8;
case 0x0c0837eau: goto P_0c0837ea;
case 0x0c0837ecu: goto P_0c0837ec;
case 0x0c0837eeu: goto P_0c0837ee;
case 0x0c0837f0u: goto P_0c0837f0;
case 0x0c08380cu: goto P_0c08380c;
case 0x0c08380eu: goto P_0c08380e;
case 0x0c083810u: goto P_0c083810;
case 0x0c083812u: goto P_0c083812;
case 0x0c083814u: goto P_0c083814;
case 0x0c083816u: goto P_0c083816;
case 0x0c083818u: goto P_0c083818;
case 0x0c08381au: goto P_0c08381a;
case 0x0c08381cu: goto P_0c08381c;
case 0x0c08381eu: goto P_0c08381e;
case 0x0c083820u: goto P_0c083820;
case 0x0c083822u: goto P_0c083822;
case 0x0c083824u: goto P_0c083824;
case 0x0c083826u: goto P_0c083826;
case 0x0c083828u: goto P_0c083828;
case 0x0c08382au: goto P_0c08382a;
case 0x0c08382cu: goto P_0c08382c;
case 0x0c08382eu: goto P_0c08382e;
case 0x0c083830u: goto P_0c083830;
case 0x0c083832u: goto P_0c083832;
case 0x0c083834u: goto P_0c083834;
case 0x0c083836u: goto P_0c083836;
case 0x0c083838u: goto P_0c083838;
case 0x0c08383au: goto P_0c08383a;
case 0x0c08383cu: goto P_0c08383c;
case 0x0c08383eu: goto P_0c08383e;
case 0x0c083840u: goto P_0c083840;
case 0x0c083842u: goto P_0c083842;
case 0x0c083844u: goto P_0c083844;
case 0x0c083846u: goto P_0c083846;
case 0x0c083848u: goto P_0c083848;
case 0x0c08384au: goto P_0c08384a;
case 0x0c08384cu: goto P_0c08384c;
case 0x0c08384eu: goto P_0c08384e;
case 0x0c083850u: goto P_0c083850;
case 0x0c083852u: goto P_0c083852;
case 0x0c083854u: goto P_0c083854;
case 0x0c083856u: goto P_0c083856;
case 0x0c083858u: goto P_0c083858;
case 0x0c08385au: goto P_0c08385a;
case 0x0c08385cu: goto P_0c08385c;
case 0x0c08385eu: goto P_0c08385e;
case 0x0c083860u: goto P_0c083860;
case 0x0c083862u: goto P_0c083862;
case 0x0c083864u: goto P_0c083864;
case 0x0c083866u: goto P_0c083866;
case 0x0c083868u: goto P_0c083868;
case 0x0c08386au: goto P_0c08386a;
case 0x0c08386cu: goto P_0c08386c;
case 0x0c08386eu: goto P_0c08386e;
case 0x0c083870u: goto P_0c083870;
case 0x0c083872u: goto P_0c083872;
case 0x0c083874u: goto P_0c083874;
case 0x0c083876u: goto P_0c083876;
case 0x0c083878u: goto P_0c083878;
case 0x0c08387au: goto P_0c08387a;
case 0x0c08387cu: goto P_0c08387c;
case 0x0c08387eu: goto P_0c08387e;
case 0x0c083880u: goto P_0c083880;
case 0x0c083882u: goto P_0c083882;
case 0x0c083884u: goto P_0c083884;
case 0x0c083886u: goto P_0c083886;
case 0x0c083888u: goto P_0c083888;
case 0x0c08388au: goto P_0c08388a;
case 0x0c08388cu: goto P_0c08388c;
case 0x0c08388eu: goto P_0c08388e;
case 0x0c083890u: goto P_0c083890;
case 0x0c083892u: goto P_0c083892;
case 0x0c083894u: goto P_0c083894;
case 0x0c083896u: goto P_0c083896;
case 0x0c083898u: goto P_0c083898;
case 0x0c08389au: goto P_0c08389a;
case 0x0c08389cu: goto P_0c08389c;
case 0x0c08389eu: goto P_0c08389e;
case 0x0c0838a0u: goto P_0c0838a0;
case 0x0c0838a2u: goto P_0c0838a2;
case 0x0c0838a4u: goto P_0c0838a4;
case 0x0c0838a6u: goto P_0c0838a6;
case 0x0c0838a8u: goto P_0c0838a8;
case 0x0c0838aau: goto P_0c0838aa;
case 0x0c0838acu: goto P_0c0838ac;
case 0x0c0838aeu: goto P_0c0838ae;
case 0x0c0838b0u: goto P_0c0838b0;
case 0x0c0838b2u: goto P_0c0838b2;
case 0x0c0838b4u: goto P_0c0838b4;
case 0x0c0838b6u: goto P_0c0838b6;
case 0x0c0838b8u: goto P_0c0838b8;
case 0x0c0838bau: goto P_0c0838ba;
case 0x0c0838bcu: goto P_0c0838bc;
case 0x0c0838beu: goto P_0c0838be;
case 0x0c0838c0u: goto P_0c0838c0;
case 0x0c0838c2u: goto P_0c0838c2;
case 0x0c0838c4u: goto P_0c0838c4;
case 0x0c0838c6u: goto P_0c0838c6;
case 0x0c0838c8u: goto P_0c0838c8;
case 0x0c0838cau: goto P_0c0838ca;
case 0x0c0838ccu: goto P_0c0838cc;
case 0x0c0838ceu: goto P_0c0838ce;
case 0x0c0838d0u: goto P_0c0838d0;
case 0x0c0838d2u: goto P_0c0838d2;
case 0x0c0838d4u: goto P_0c0838d4;
case 0x0c0838d6u: goto P_0c0838d6;
case 0x0c0838f0u: goto P_0c0838f0;
case 0x0c0838f2u: goto P_0c0838f2;
case 0x0c0838f4u: goto P_0c0838f4;
case 0x0c0838f6u: goto P_0c0838f6;
case 0x0c0838f8u: goto P_0c0838f8;
case 0x0c0838fau: goto P_0c0838fa;
case 0x0c0838fcu: goto P_0c0838fc;
case 0x0c0838feu: goto P_0c0838fe;
case 0x0c083900u: goto P_0c083900;
case 0x0c083902u: goto P_0c083902;
case 0x0c083904u: goto P_0c083904;
case 0x0c083906u: goto P_0c083906;
case 0x0c083908u: goto P_0c083908;
case 0x0c08390au: goto P_0c08390a;
case 0x0c08390cu: goto P_0c08390c;
case 0x0c08390eu: goto P_0c08390e;
case 0x0c083910u: goto P_0c083910;
case 0x0c083912u: goto P_0c083912;
case 0x0c083914u: goto P_0c083914;
case 0x0c083916u: goto P_0c083916;
case 0x0c083918u: goto P_0c083918;
case 0x0c08391au: goto P_0c08391a;
case 0x0c08391cu: goto P_0c08391c;
case 0x0c08391eu: goto P_0c08391e;
case 0x0c083920u: goto P_0c083920;
case 0x0c083922u: goto P_0c083922;
case 0x0c083924u: goto P_0c083924;
case 0x0c083926u: goto P_0c083926;
case 0x0c083928u: goto P_0c083928;
case 0x0c08392au: goto P_0c08392a;
case 0x0c08392cu: goto P_0c08392c;
case 0x0c08392eu: goto P_0c08392e;
case 0x0c083930u: goto P_0c083930;
case 0x0c083932u: goto P_0c083932;
case 0x0c083934u: goto P_0c083934;
case 0x0c083936u: goto P_0c083936;
case 0x0c083938u: goto P_0c083938;
case 0x0c08393au: goto P_0c08393a;
case 0x0c08393cu: goto P_0c08393c;
case 0x0c08393eu: goto P_0c08393e;
case 0x0c083940u: goto P_0c083940;
case 0x0c083942u: goto P_0c083942;
case 0x0c083944u: goto P_0c083944;
case 0x0c083946u: goto P_0c083946;
case 0x0c083948u: goto P_0c083948;
case 0x0c08394au: goto P_0c08394a;
case 0x0c08394cu: goto P_0c08394c;
case 0x0c08394eu: goto P_0c08394e;
case 0x0c083950u: goto P_0c083950;
case 0x0c083952u: goto P_0c083952;
case 0x0c083954u: goto P_0c083954;
case 0x0c083956u: goto P_0c083956;
case 0x0c083958u: goto P_0c083958;
case 0x0c08395au: goto P_0c08395a;
case 0x0c08395cu: goto P_0c08395c;
case 0x0c08395eu: goto P_0c08395e;
case 0x0c083960u: goto P_0c083960;
case 0x0c083962u: goto P_0c083962;
case 0x0c083964u: goto P_0c083964;
case 0x0c083966u: goto P_0c083966;
case 0x0c083968u: goto P_0c083968;
case 0x0c08396au: goto P_0c08396a;
case 0x0c08396cu: goto P_0c08396c;
case 0x0c08396eu: goto P_0c08396e;
case 0x0c083970u: goto P_0c083970;
case 0x0c083972u: goto P_0c083972;
case 0x0c083974u: goto P_0c083974;
case 0x0c083976u: goto P_0c083976;
case 0x0c083978u: goto P_0c083978;
case 0x0c08397au: goto P_0c08397a;
case 0x0c08397cu: goto P_0c08397c;
case 0x0c08397eu: goto P_0c08397e;
case 0x0c083980u: goto P_0c083980;
case 0x0c083982u: goto P_0c083982;
case 0x0c083984u: goto P_0c083984;
case 0x0c083986u: goto P_0c083986;
case 0x0c083988u: goto P_0c083988;
case 0x0c08398au: goto P_0c08398a;
case 0x0c08398cu: goto P_0c08398c;
case 0x0c08398eu: goto P_0c08398e;
case 0x0c083990u: goto P_0c083990;
case 0x0c083992u: goto P_0c083992;
case 0x0c083994u: goto P_0c083994;
case 0x0c083996u: goto P_0c083996;
case 0x0c083998u: goto P_0c083998;
case 0x0c08399au: goto P_0c08399a;
case 0x0c08399cu: goto P_0c08399c;
case 0x0c08399eu: goto P_0c08399e;
case 0x0c0839a0u: goto P_0c0839a0;
case 0x0c0839a2u: goto P_0c0839a2;
case 0x0c0839a4u: goto P_0c0839a4;
case 0x0c0839a6u: goto P_0c0839a6;
case 0x0c0839a8u: goto P_0c0839a8;
case 0x0c0839aau: goto P_0c0839aa;
case 0x0c0839acu: goto P_0c0839ac;
case 0x0c0839aeu: goto P_0c0839ae;
case 0x0c0839b0u: goto P_0c0839b0;
case 0x0c0839b2u: goto P_0c0839b2;
case 0x0c0839b4u: goto P_0c0839b4;
case 0x0c0839b6u: goto P_0c0839b6;
case 0x0c0839b8u: goto P_0c0839b8;
case 0x0c0839bau: goto P_0c0839ba;
case 0x0c0839bcu: goto P_0c0839bc;
case 0x0c0839beu: goto P_0c0839be;
case 0x0c0839c0u: goto P_0c0839c0;
case 0x0c0839c2u: goto P_0c0839c2;
case 0x0c0839c4u: goto P_0c0839c4;
case 0x0c0839c6u: goto P_0c0839c6;
case 0x0c0839c8u: goto P_0c0839c8;
case 0x0c0839cau: goto P_0c0839ca;
case 0x0c0839ccu: goto P_0c0839cc;
case 0x0c0839ceu: goto P_0c0839ce;
case 0x0c0839d0u: goto P_0c0839d0;
case 0x0c0839d2u: goto P_0c0839d2;
case 0x0c0839d4u: goto P_0c0839d4;
case 0x0c0839d6u: goto P_0c0839d6;
case 0x0c0839d8u: goto P_0c0839d8;
case 0x0c0839dau: goto P_0c0839da;
case 0x0c0839dcu: goto P_0c0839dc;
case 0x0c0839deu: goto P_0c0839de;
case 0x0c0839e0u: goto P_0c0839e0;
case 0x0c0839e2u: goto P_0c0839e2;
case 0x0c0839e4u: goto P_0c0839e4;
case 0x0c0839e6u: goto P_0c0839e6;
case 0x0c0839e8u: goto P_0c0839e8;
case 0x0c0839eau: goto P_0c0839ea;
case 0x0c0839ecu: goto P_0c0839ec;
case 0x0c0839eeu: goto P_0c0839ee;
case 0x0c0839f0u: goto P_0c0839f0;
case 0x0c0839f2u: goto P_0c0839f2;
case 0x0c0839f4u: goto P_0c0839f4;
case 0x0c0839f6u: goto P_0c0839f6;
case 0x0c0839f8u: goto P_0c0839f8;
case 0x0c0839fau: goto P_0c0839fa;
case 0x0c0839fcu: goto P_0c0839fc;
case 0x0c0839feu: goto P_0c0839fe;
case 0x0c083a00u: goto P_0c083a00;
case 0x0c083a02u: goto P_0c083a02;
case 0x0c083a04u: goto P_0c083a04;
case 0x0c083a24u: goto P_0c083a24;
case 0x0c083a26u: goto P_0c083a26;
case 0x0c083a28u: goto P_0c083a28;
case 0x0c083a2au: goto P_0c083a2a;
case 0x0c083a2cu: goto P_0c083a2c;
case 0x0c083a2eu: goto P_0c083a2e;
case 0x0c083a30u: goto P_0c083a30;
case 0x0c083a32u: goto P_0c083a32;
case 0x0c083a34u: goto P_0c083a34;
case 0x0c083a36u: goto P_0c083a36;
case 0x0c083a38u: goto P_0c083a38;
case 0x0c083a3au: goto P_0c083a3a;
case 0x0c083a3cu: goto P_0c083a3c;
case 0x0c083a3eu: goto P_0c083a3e;
case 0x0c083a40u: goto P_0c083a40;
case 0x0c083a42u: goto P_0c083a42;
case 0x0c083a44u: goto P_0c083a44;
case 0x0c083a46u: goto P_0c083a46;
case 0x0c083a48u: goto P_0c083a48;
case 0x0c083a4au: goto P_0c083a4a;
case 0x0c083a4cu: goto P_0c083a4c;
case 0x0c083a4eu: goto P_0c083a4e;
case 0x0c083a50u: goto P_0c083a50;
case 0x0c083a52u: goto P_0c083a52;
case 0x0c083a54u: goto P_0c083a54;
case 0x0c083a56u: goto P_0c083a56;
case 0x0c083a58u: goto P_0c083a58;
case 0x0c083a5au: goto P_0c083a5a;
case 0x0c083a5cu: goto P_0c083a5c;
case 0x0c083a5eu: goto P_0c083a5e;
case 0x0c083a60u: goto P_0c083a60;
case 0x0c083a62u: goto P_0c083a62;
case 0x0c083a64u: goto P_0c083a64;
case 0x0c083a66u: goto P_0c083a66;
case 0x0c083a68u: goto P_0c083a68;
case 0x0c083a6au: goto P_0c083a6a;
case 0x0c083a6cu: goto P_0c083a6c;
case 0x0c083a6eu: goto P_0c083a6e;
case 0x0c083a70u: goto P_0c083a70;
case 0x0c083a72u: goto P_0c083a72;
case 0x0c083a74u: goto P_0c083a74;
case 0x0c083a76u: goto P_0c083a76;
case 0x0c083a78u: goto P_0c083a78;
case 0x0c083a7au: goto P_0c083a7a;
case 0x0c083a7cu: goto P_0c083a7c;
case 0x0c083a7eu: goto P_0c083a7e;
case 0x0c083a80u: goto P_0c083a80;
case 0x0c083a82u: goto P_0c083a82;
case 0x0c083a84u: goto P_0c083a84;
case 0x0c083a86u: goto P_0c083a86;
case 0x0c083a88u: goto P_0c083a88;
case 0x0c083a8au: goto P_0c083a8a;
case 0x0c083a8cu: goto P_0c083a8c;
case 0x0c083a8eu: goto P_0c083a8e;
case 0x0c083a90u: goto P_0c083a90;
case 0x0c083a92u: goto P_0c083a92;
case 0x0c083a94u: goto P_0c083a94;
case 0x0c083a96u: goto P_0c083a96;
case 0x0c083a98u: goto P_0c083a98;
case 0x0c083a9au: goto P_0c083a9a;
case 0x0c083a9cu: goto P_0c083a9c;
case 0x0c083a9eu: goto P_0c083a9e;
case 0x0c083aa0u: goto P_0c083aa0;
case 0x0c083aa2u: goto P_0c083aa2;
case 0x0c083aa4u: goto P_0c083aa4;
case 0x0c083aa6u: goto P_0c083aa6;
case 0x0c083aa8u: goto P_0c083aa8;
case 0x0c083aaau: goto P_0c083aaa;
case 0x0c083aacu: goto P_0c083aac;
case 0x0c083aaeu: goto P_0c083aae;
case 0x0c083ab0u: goto P_0c083ab0;
case 0x0c083ab2u: goto P_0c083ab2;
case 0x0c083ab4u: goto P_0c083ab4;
case 0x0c083ab6u: goto P_0c083ab6;
case 0x0c083ab8u: goto P_0c083ab8;
case 0x0c083abau: goto P_0c083aba;
case 0x0c083abcu: goto P_0c083abc;
case 0x0c083abeu: goto P_0c083abe;
case 0x0c083ac0u: goto P_0c083ac0;
case 0x0c083ac2u: goto P_0c083ac2;
case 0x0c083ac4u: goto P_0c083ac4;
case 0x0c083ac6u: goto P_0c083ac6;
case 0x0c083ac8u: goto P_0c083ac8;
case 0x0c083acau: goto P_0c083aca;
case 0x0c083accu: goto P_0c083acc;
case 0x0c083aceu: goto P_0c083ace;
case 0x0c083ad0u: goto P_0c083ad0;
case 0x0c083ad2u: goto P_0c083ad2;
case 0x0c083ad4u: goto P_0c083ad4;
case 0x0c083ad6u: goto P_0c083ad6;
case 0x0c083ad8u: goto P_0c083ad8;
case 0x0c083adau: goto P_0c083ada;
case 0x0c083adcu: goto P_0c083adc;
case 0x0c083adeu: goto P_0c083ade;
case 0x0c083ae0u: goto P_0c083ae0;
case 0x0c083ae2u: goto P_0c083ae2;
case 0x0c083ae4u: goto P_0c083ae4;
case 0x0c083ae6u: goto P_0c083ae6;
case 0x0c083ae8u: goto P_0c083ae8;
case 0x0c083aeau: goto P_0c083aea;
case 0x0c083aecu: goto P_0c083aec;
case 0x0c083aeeu: goto P_0c083aee;
case 0x0c083af0u: goto P_0c083af0;
case 0x0c083af2u: goto P_0c083af2;
case 0x0c083af4u: goto P_0c083af4;
case 0x0c083af6u: goto P_0c083af6;
case 0x0c083af8u: goto P_0c083af8;
case 0x0c083afau: goto P_0c083afa;
case 0x0c083afcu: goto P_0c083afc;
case 0x0c083afeu: goto P_0c083afe;
case 0x0c083b00u: goto P_0c083b00;
case 0x0c083b02u: goto P_0c083b02;
case 0x0c083b04u: goto P_0c083b04;
case 0x0c083b06u: goto P_0c083b06;
case 0x0c083b08u: goto P_0c083b08;
case 0x0c083b0au: goto P_0c083b0a;
case 0x0c083b0cu: goto P_0c083b0c;
case 0x0c083b0eu: goto P_0c083b0e;
case 0x0c083b10u: goto P_0c083b10;
case 0x0c083b12u: goto P_0c083b12;
case 0x0c083b14u: goto P_0c083b14;
case 0x0c083b16u: goto P_0c083b16;
case 0x0c083b18u: goto P_0c083b18;
case 0x0c083b1au: goto P_0c083b1a;
case 0x0c083b1cu: goto P_0c083b1c;
case 0x0c083b1eu: goto P_0c083b1e;
case 0x0c083b20u: goto P_0c083b20;
case 0x0c083b22u: goto P_0c083b22;
case 0x0c083b24u: goto P_0c083b24;
case 0x0c083b26u: goto P_0c083b26;
case 0x0c083b28u: goto P_0c083b28;
case 0x0c083b2au: goto P_0c083b2a;
case 0x0c083b2cu: goto P_0c083b2c;
case 0x0c083b2eu: goto P_0c083b2e;
case 0x0c083b30u: goto P_0c083b30;
case 0x0c083b32u: goto P_0c083b32;
case 0x0c083b34u: goto P_0c083b34;
case 0x0c083b36u: goto P_0c083b36;
case 0x0c083b38u: goto P_0c083b38;
case 0x0c083b3au: goto P_0c083b3a;
case 0x0c083b78u: goto P_0c083b78;
case 0x0c083b7au: goto P_0c083b7a;
case 0x0c083b7cu: goto P_0c083b7c;
case 0x0c083b7eu: goto P_0c083b7e;
case 0x0c083b80u: goto P_0c083b80;
case 0x0c083b82u: goto P_0c083b82;
case 0x0c083b84u: goto P_0c083b84;
case 0x0c083b86u: goto P_0c083b86;
case 0x0c083b88u: goto P_0c083b88;
case 0x0c083b8au: goto P_0c083b8a;
case 0x0c083b8cu: goto P_0c083b8c;
case 0x0c083b8eu: goto P_0c083b8e;
case 0x0c083b90u: goto P_0c083b90;
case 0x0c083b92u: goto P_0c083b92;
case 0x0c083b94u: goto P_0c083b94;
case 0x0c083b96u: goto P_0c083b96;
case 0x0c083b98u: goto P_0c083b98;
case 0x0c083b9au: goto P_0c083b9a;
case 0x0c083b9cu: goto P_0c083b9c;
case 0x0c083b9eu: goto P_0c083b9e;
case 0x0c083ba0u: goto P_0c083ba0;
case 0x0c083ba2u: goto P_0c083ba2;
case 0x0c083ba4u: goto P_0c083ba4;
case 0x0c083ba6u: goto P_0c083ba6;
case 0x0c083ba8u: goto P_0c083ba8;
case 0x0c083baau: goto P_0c083baa;
case 0x0c083bacu: goto P_0c083bac;
case 0x0c083baeu: goto P_0c083bae;
case 0x0c083bb0u: goto P_0c083bb0;
case 0x0c083bb2u: goto P_0c083bb2;
case 0x0c083bb4u: goto P_0c083bb4;
case 0x0c083bb6u: goto P_0c083bb6;
case 0x0c083bb8u: goto P_0c083bb8;
case 0x0c083bbau: goto P_0c083bba;
case 0x0c083bbcu: goto P_0c083bbc;
case 0x0c083bbeu: goto P_0c083bbe;
case 0x0c083bc0u: goto P_0c083bc0;
case 0x0c083bc2u: goto P_0c083bc2;
case 0x0c083bc4u: goto P_0c083bc4;
case 0x0c083bc6u: goto P_0c083bc6;
case 0x0c083bc8u: goto P_0c083bc8;
case 0x0c083bcau: goto P_0c083bca;
case 0x0c083bccu: goto P_0c083bcc;
case 0x0c083bceu: goto P_0c083bce;
case 0x0c083bd0u: goto P_0c083bd0;
case 0x0c083bd2u: goto P_0c083bd2;
case 0x0c083bd4u: goto P_0c083bd4;
case 0x0c083bd6u: goto P_0c083bd6;
case 0x0c083bd8u: goto P_0c083bd8;
case 0x0c083bdau: goto P_0c083bda;
case 0x0c083bdcu: goto P_0c083bdc;
case 0x0c083bdeu: goto P_0c083bde;
case 0x0c083be0u: goto P_0c083be0;
case 0x0c083be2u: goto P_0c083be2;
case 0x0c083be4u: goto P_0c083be4;
case 0x0c083be6u: goto P_0c083be6;
case 0x0c083be8u: goto P_0c083be8;
case 0x0c083beau: goto P_0c083bea;
case 0x0c083becu: goto P_0c083bec;
case 0x0c083beeu: goto P_0c083bee;
case 0x0c083bf0u: goto P_0c083bf0;
case 0x0c083bf2u: goto P_0c083bf2;
case 0x0c083bf4u: goto P_0c083bf4;
case 0x0c083bf6u: goto P_0c083bf6;
case 0x0c083bf8u: goto P_0c083bf8;
case 0x0c083bfau: goto P_0c083bfa;
case 0x0c083bfcu: goto P_0c083bfc;
case 0x0c083bfeu: goto P_0c083bfe;
case 0x0c083c00u: goto P_0c083c00;
case 0x0c083c02u: goto P_0c083c02;
case 0x0c083c04u: goto P_0c083c04;
case 0x0c083c06u: goto P_0c083c06;
case 0x0c083c08u: goto P_0c083c08;
case 0x0c083c0au: goto P_0c083c0a;
case 0x0c083c0cu: goto P_0c083c0c;
case 0x0c083c0eu: goto P_0c083c0e;
case 0x0c083c10u: goto P_0c083c10;
case 0x0c083c12u: goto P_0c083c12;
case 0x0c083c14u: goto P_0c083c14;
case 0x0c083c16u: goto P_0c083c16;
case 0x0c083c18u: goto P_0c083c18;
case 0x0c083c1au: goto P_0c083c1a;
case 0x0c083c1cu: goto P_0c083c1c;
case 0x0c083c1eu: goto P_0c083c1e;
case 0x0c083c20u: goto P_0c083c20;
case 0x0c083c22u: goto P_0c083c22;
case 0x0c083c24u: goto P_0c083c24;
case 0x0c083c26u: goto P_0c083c26;
case 0x0c083c28u: goto P_0c083c28;
case 0x0c083c2au: goto P_0c083c2a;
case 0x0c083c2cu: goto P_0c083c2c;
case 0x0c083c2eu: goto P_0c083c2e;
case 0x0c083c30u: goto P_0c083c30;
case 0x0c083c32u: goto P_0c083c32;
case 0x0c083c34u: goto P_0c083c34;
case 0x0c083c36u: goto P_0c083c36;
case 0x0c083c38u: goto P_0c083c38;
case 0x0c083c3au: goto P_0c083c3a;
case 0x0c083c3cu: goto P_0c083c3c;
case 0x0c083c3eu: goto P_0c083c3e;
case 0x0c083c40u: goto P_0c083c40;
case 0x0c083c42u: goto P_0c083c42;
case 0x0c083c44u: goto P_0c083c44;
case 0x0c083c46u: goto P_0c083c46;
case 0x0c083c48u: goto P_0c083c48;
case 0x0c083c4au: goto P_0c083c4a;
case 0x0c083c4cu: goto P_0c083c4c;
case 0x0c083c4eu: goto P_0c083c4e;
case 0x0c083c50u: goto P_0c083c50;
case 0x0c083c52u: goto P_0c083c52;
case 0x0c083c54u: goto P_0c083c54;
case 0x0c083d66u: goto P_0c083d66;
case 0x0c083d68u: goto P_0c083d68;
case 0x0c083d6au: goto P_0c083d6a;
case 0x0c083d6cu: goto P_0c083d6c;
case 0x0c083d6eu: goto P_0c083d6e;
case 0x0c083d70u: goto P_0c083d70;
case 0x0c083d72u: goto P_0c083d72;
case 0x0c083d74u: goto P_0c083d74;
case 0x0c083d76u: goto P_0c083d76;
case 0x0c083d78u: goto P_0c083d78;
case 0x0c083d7au: goto P_0c083d7a;
case 0x0c083d7cu: goto P_0c083d7c;
case 0x0c083d7eu: goto P_0c083d7e;
case 0x0c083d80u: goto P_0c083d80;
case 0x0c083d82u: goto P_0c083d82;
case 0x0c083d84u: goto P_0c083d84;
case 0x0c083d86u: goto P_0c083d86;
case 0x0c083d88u: goto P_0c083d88;
case 0x0c083d8au: goto P_0c083d8a;
case 0x0c083d8cu: goto P_0c083d8c;
case 0x0c083d8eu: goto P_0c083d8e;
case 0x0c083d90u: goto P_0c083d90;
case 0x0c083d92u: goto P_0c083d92;
case 0x0c083d94u: goto P_0c083d94;
case 0x0c083d96u: goto P_0c083d96;
case 0x0c083d98u: goto P_0c083d98;
case 0x0c083d9au: goto P_0c083d9a;
case 0x0c083d9cu: goto P_0c083d9c;
case 0x0c083d9eu: goto P_0c083d9e;
case 0x0c083da0u: goto P_0c083da0;
case 0x0c083da2u: goto P_0c083da2;
case 0x0c083da4u: goto P_0c083da4;
case 0x0c083da6u: goto P_0c083da6;
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
P_0c082e00: /* original 2fe6, guest PC 0x0c082e00 */
if(!s->budget--) { s->failed_pc=0x0c082e00u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c082e02;
P_0c082e02: /* original 2fd6, guest PC 0x0c082e02 */
if(!s->budget--) { s->failed_pc=0x0c082e02u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c082e04;
P_0c082e04: /* original 2fc6, guest PC 0x0c082e04 */
if(!s->budget--) { s->failed_pc=0x0c082e04u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c082e06;
P_0c082e06: /* original 2fb6, guest PC 0x0c082e06 */
if(!s->budget--) { s->failed_pc=0x0c082e06u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c082e08;
P_0c082e08: /* original 2fa6, guest PC 0x0c082e08 */
if(!s->budget--) { s->failed_pc=0x0c082e08u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c082e0a;
P_0c082e0a: /* original 2f96, guest PC 0x0c082e0a */
if(!s->budget--) { s->failed_pc=0x0c082e0au; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c082e0c;
P_0c082e0c: /* original 2f86, guest PC 0x0c082e0c */
if(!s->budget--) { s->failed_pc=0x0c082e0cu; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c082e0e;
P_0c082e0e: /* original 4f22, guest PC 0x0c082e0e */
if(!s->budget--) { s->failed_pc=0x0c082e0eu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c082e10;
P_0c082e10: /* original 7fec, guest PC 0x0c082e10 */
if(!s->budget--) { s->failed_pc=0x0c082e10u; return 0; }
r[15]+=0xffffffecu;
goto P_0c082e12;
P_0c082e12: /* original 1f43, guest PC 0x0c082e12 */
if(!s->budget--) { s->failed_pc=0x0c082e12u; return 0; }
write(ram,r[15]+12,r[4],4);
goto P_0c082e14;
P_0c082e14: /* original 1f54, guest PC 0x0c082e14 */
if(!s->budget--) { s->failed_pc=0x0c082e14u; return 0; }
write(ram,r[15]+16,r[5],4);
goto P_0c082e16;
P_0c082e16: /* original d32d, guest PC 0x0c082e16 */
if(!s->budget--) { s->failed_pc=0x0c082e16u; return 0; }
r[3]=read(ram,0x0c082eccu,4);
goto P_0c082e18;
P_0c082e18: /* original dc2b, guest PC 0x0c082e18 */
if(!s->budget--) { s->failed_pc=0x0c082e18u; return 0; }
r[12]=read(ram,0x0c082ec8u,4);
goto P_0c082e1a;
P_0c082e1a: /* original dd2a, guest PC 0x0c082e1a */
if(!s->budget--) { s->failed_pc=0x0c082e1au; return 0; }
r[13]=read(ram,0x0c082ec4u,4);
goto P_0c082e1c;
P_0c082e1c: /* original 1f32, guest PC 0x0c082e1c */
if(!s->budget--) { s->failed_pc=0x0c082e1cu; return 0; }
write(ram,r[15]+8,r[3],4);
goto P_0c082e1e;
P_0c082e1e: /* original de2c, guest PC 0x0c082e1e */
if(!s->budget--) { s->failed_pc=0x0c082e1eu; return 0; }
r[14]=read(ram,0x0c082ed0u,4);
goto P_0c082e20;
P_0c082e20: /* original 1fe1, guest PC 0x0c082e20 */
if(!s->budget--) { s->failed_pc=0x0c082e20u; return 0; }
write(ram,r[15]+4,r[14],4);
goto P_0c082e22;
P_0c082e22: /* original d32c, guest PC 0x0c082e22 */
if(!s->budget--) { s->failed_pc=0x0c082e22u; return 0; }
r[3]=read(ram,0x0c082ed4u,4);
goto P_0c082e24;
P_0c082e24: /* original 430b, guest PC 0x0c082e24 */
if(!s->budget--) { s->failed_pc=0x0c082e24u; return 0; }
target=r[3];
r[16]=code_base|0x0c082e28u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c082e28u) { target=s->pc; goto dispatch; }
goto P_0c082e28;
P_0c082e26: /* original 64e3, guest PC 0x0c082e26 */
if(!s->budget--) { s->failed_pc=0x0c082e26u; return 0; }
r[4]=r[14];
goto P_0c082e28;
P_0c082e28: /* original d215, guest PC 0x0c082e28 */
if(!s->budget--) { s->failed_pc=0x0c082e28u; return 0; }
r[2]=read(ram,0x0c082e80u,4);
goto P_0c082e2a;
P_0c082e2a: /* original e503, guest PC 0x0c082e2a */
if(!s->budget--) { s->failed_pc=0x0c082e2au; return 0; }
r[5]=0x00000003u;
goto P_0c082e2c;
P_0c082e2c: /* original 9622, guest PC 0x0c082e2c */
if(!s->budget--) { s->failed_pc=0x0c082e2cu; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c082e74u,2);
goto P_0c082e2e;
P_0c082e2e: /* original 420b, guest PC 0x0c082e2e */
if(!s->budget--) { s->failed_pc=0x0c082e2eu; return 0; }
target=r[2];
r[16]=code_base|0x0c082e32u;
r[4]=0x0000001au;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c082e32u) { target=s->pc; goto dispatch; }
goto P_0c082e32;
P_0c082e30: /* original e41a, guest PC 0x0c082e30 */
if(!s->budget--) { s->failed_pc=0x0c082e30u; return 0; }
r[4]=0x0000001au;
goto P_0c082e32;
P_0c082e32: /* original d329, guest PC 0x0c082e32 */
if(!s->budget--) { s->failed_pc=0x0c082e32u; return 0; }
r[3]=read(ram,0x0c082ed8u,4);
goto P_0c082e34;
P_0c082e34: /* original 951f, guest PC 0x0c082e34 */
if(!s->budget--) { s->failed_pc=0x0c082e34u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c082e76u,2);
goto P_0c082e36;
P_0c082e36: /* original 430b, guest PC 0x0c082e36 */
if(!s->budget--) { s->failed_pc=0x0c082e36u; return 0; }
target=r[3];
r[16]=code_base|0x0c082e3au;
r[4]=read(ram,r[15]+4,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c082e3au) { target=s->pc; goto dispatch; }
goto P_0c082e3a;
P_0c082e38: /* original 54f1, guest PC 0x0c082e38 */
if(!s->budget--) { s->failed_pc=0x0c082e38u; return 0; }
r[4]=read(ram,r[15]+4,4);
goto P_0c082e3a;
P_0c082e3a: /* original d928, guest PC 0x0c082e3a */
if(!s->budget--) { s->failed_pc=0x0c082e3au; return 0; }
r[9]=read(ram,0x0c082edcu,4);
goto P_0c082e3c;
P_0c082e3c: /* original ee00, guest PC 0x0c082e3c */
if(!s->budget--) { s->failed_pc=0x0c082e3cu; return 0; }
r[14]=0x00000000u;
goto P_0c082e3e;
P_0c082e3e: /* original db28, guest PC 0x0c082e3e */
if(!s->budget--) { s->failed_pc=0x0c082e3eu; return 0; }
r[11]=read(ram,0x0c082ee0u,4);
goto P_0c082e40;
P_0c082e40: /* original ea08, guest PC 0x0c082e40 */
if(!s->budget--) { s->failed_pc=0x0c082e40u; return 0; }
r[10]=0x00000008u;
goto P_0c082e42;
P_0c082e42: /* original 9819, guest PC 0x0c082e42 */
if(!s->budget--) { s->failed_pc=0x0c082e42u; return 0; }
r[8]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c082e78u,2);
goto P_0c082e44;
P_0c082e44: /* original 9019, guest PC 0x0c082e44 */
if(!s->budget--) { s->failed_pc=0x0c082e44u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c082e7au,2);
goto P_0c082e46;
P_0c082e46: /* original 02de, guest PC 0x0c082e46 */
if(!s->budget--) { s->failed_pc=0x0c082e46u; return 0; }
r[2]=read(ram,r[13]+r[0],4);
goto P_0c082e48;
P_0c082e48: /* original 3e20, guest PC 0x0c082e48 */
if(!s->budget--) { s->failed_pc=0x0c082e48u; return 0; }
r[17]=(r[17]&~1u)|((r[14]==r[2])!=0);
goto P_0c082e4a;
P_0c082e4a: /* original 8b4b, guest PC 0x0c082e4a */
if(!s->budget--) { s->failed_pc=0x0c082e4au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c082ee4; }
goto P_0c082e4c;
P_0c082e4c: /* original 61f2, guest PC 0x0c082e4c */
if(!s->budget--) { s->failed_pc=0x0c082e4cu; return 0; }
tmp=read(ram,r[15],4);
r[1]=tmp;
goto P_0c082e4e;
P_0c082e4e: /* original e307, guest PC 0x0c082e4e */
if(!s->budget--) { s->failed_pc=0x0c082e4eu; return 0; }
r[3]=0x00000007u;
goto P_0c082e50;
P_0c082e50: /* original 413c, guest PC 0x0c082e50 */
if(!s->budget--) { s->failed_pc=0x0c082e50u; return 0; }
r[1]=(r[3]&0x80000000u)?((r[3]&31u)?(uint32_t)((int32_t)r[1]>>((-r[3])&31u)):((int32_t)r[1]<0?0xffffffffu:0)):r[1]<<(r[3]&31u);
goto P_0c082e52;
P_0c082e52: /* original 21ab, guest PC 0x0c082e52 */
if(!s->budget--) { s->failed_pc=0x0c082e52u; return 0; }
r[1]|=r[10];
goto P_0c082e54;
P_0c082e54: /* original 1f14, guest PC 0x0c082e54 */
if(!s->budget--) { s->failed_pc=0x0c082e54u; return 0; }
write(ram,r[15]+16,r[1],4);
goto P_0c082e56;
P_0c082e56: /* original 62f2, guest PC 0x0c082e56 */
if(!s->budget--) { s->failed_pc=0x0c082e56u; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c082e58;
P_0c082e58: /* original 7203, guest PC 0x0c082e58 */
if(!s->budget--) { s->failed_pc=0x0c082e58u; return 0; }
r[2]+=0x00000003u;
goto P_0c082e5a;
P_0c082e5a: /* original 2f22, guest PC 0x0c082e5a */
if(!s->budget--) { s->failed_pc=0x0c082e5au; return 0; }
write(ram,r[15],r[2],4);
goto P_0c082e5c;
P_0c082e5c: /* original 950e, guest PC 0x0c082e5c */
if(!s->budget--) { s->failed_pc=0x0c082e5cu; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c082e7cu,2);
goto P_0c082e5e;
P_0c082e5e: /* original d31e, guest PC 0x0c082e5e */
if(!s->budget--) { s->failed_pc=0x0c082e5eu; return 0; }
r[3]=read(ram,0x0c082ed8u,4);
goto P_0c082e60;
P_0c082e60: /* original 430b, guest PC 0x0c082e60 */
if(!s->budget--) { s->failed_pc=0x0c082e60u; return 0; }
target=r[3];
r[16]=code_base|0x0c082e64u;
r[4]=read(ram,r[15]+4,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c082e64u) { target=s->pc; goto dispatch; }
goto P_0c082e64;
P_0c082e62: /* original 54f1, guest PC 0x0c082e62 */
if(!s->budget--) { s->failed_pc=0x0c082e62u; return 0; }
r[4]=read(ram,r[15]+4,4);
goto P_0c082e64;
P_0c082e64: /* original a047, guest PC 0x0c082e64 */
if(!s->budget--) { s->failed_pc=0x0c082e64u; return 0; }
goto P_0c082ef6;
P_0c082e66: /* original 0009, guest PC 0x0c082e66 */
if(!s->budget--) { s->failed_pc=0x0c082e66u; return 0; }
if(!vf3_matrix_family(0x0c082e68u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c082e68u; return 0; } return 1;
P_0c082ee4: /* original 63f2, guest PC 0x0c082ee4 */
if(!s->budget--) { s->failed_pc=0x0c082ee4u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c082ee6;
P_0c082ee6: /* original e207, guest PC 0x0c082ee6 */
if(!s->budget--) { s->failed_pc=0x0c082ee6u; return 0; }
r[2]=0x00000007u;
goto P_0c082ee8;
P_0c082ee8: /* original 7301, guest PC 0x0c082ee8 */
if(!s->budget--) { s->failed_pc=0x0c082ee8u; return 0; }
r[3]+=0x00000001u;
goto P_0c082eea;
P_0c082eea: /* original 432c, guest PC 0x0c082eea */
if(!s->budget--) { s->failed_pc=0x0c082eeau; return 0; }
r[3]=(r[2]&0x80000000u)?((r[2]&31u)?(uint32_t)((int32_t)r[3]>>((-r[2])&31u)):((int32_t)r[3]<0?0xffffffffu:0)):r[3]<<(r[2]&31u);
goto P_0c082eec;
P_0c082eec: /* original 23ab, guest PC 0x0c082eec */
if(!s->budget--) { s->failed_pc=0x0c082eecu; return 0; }
r[3]|=r[10];
goto P_0c082eee;
P_0c082eee: /* original 1f34, guest PC 0x0c082eee */
if(!s->budget--) { s->failed_pc=0x0c082eeeu; return 0; }
write(ram,r[15]+16,r[3],4);
goto P_0c082ef0;
P_0c082ef0: /* original 61f2, guest PC 0x0c082ef0 */
if(!s->budget--) { s->failed_pc=0x0c082ef0u; return 0; }
tmp=read(ram,r[15],4);
r[1]=tmp;
goto P_0c082ef2;
P_0c082ef2: /* original 7103, guest PC 0x0c082ef2 */
if(!s->budget--) { s->failed_pc=0x0c082ef2u; return 0; }
r[1]+=0x00000003u;
goto P_0c082ef4;
P_0c082ef4: /* original 2f12, guest PC 0x0c082ef4 */
if(!s->budget--) { s->failed_pc=0x0c082ef4u; return 0; }
write(ram,r[15],r[1],4);
goto P_0c082ef6;
P_0c082ef6: /* original 60e3, guest PC 0x0c082ef6 */
if(!s->budget--) { s->failed_pc=0x0c082ef6u; return 0; }
r[0]=r[14];
goto P_0c082ef8;
P_0c082ef8: /* original e10c, guest PC 0x0c082ef8 */
if(!s->budget--) { s->failed_pc=0x0c082ef8u; return 0; }
r[1]=0x0000000cu;
goto P_0c082efa;
P_0c082efa: /* original 3012, guest PC 0x0c082efa */
if(!s->budget--) { s->failed_pc=0x0c082efau; return 0; }
r[17]=(r[17]&~1u)|((r[0]>=r[1])!=0);
goto P_0c082efc;
P_0c082efc: /* original 8b01, guest PC 0x0c082efc */
if(!s->budget--) { s->failed_pc=0x0c082efcu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c082f02; }
goto P_0c082efe;
P_0c082efe: /* original a159, guest PC 0x0c082efe */
if(!s->budget--) { s->failed_pc=0x0c082efeu; return 0; }
goto P_0c0831b4;
P_0c082f00: /* original 0009, guest PC 0x0c082f00 */
if(!s->budget--) { s->failed_pc=0x0c082f00u; return 0; }
goto P_0c082f02;
P_0c082f02: /* original 4000, guest PC 0x0c082f02 */
if(!s->budget--) { s->failed_pc=0x0c082f02u; return 0; }
r[17]=(r[17]&~1u)|((r[0]>>31)!=0);
r[0]<<=1;
goto P_0c082f04;
P_0c082f04: /* original 6103, guest PC 0x0c082f04 */
if(!s->budget--) { s->failed_pc=0x0c082f04u; return 0; }
r[1]=r[0];
goto P_0c082f06;
P_0c082f06: /* original c702, guest PC 0x0c082f06 */
if(!s->budget--) { s->failed_pc=0x0c082f06u; return 0; }
r[0]=code_base|0x00082f10u;
goto P_0c082f08;
P_0c082f08: /* original 001d, guest PC 0x0c082f08 */
if(!s->budget--) { s->failed_pc=0x0c082f08u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[1]+r[0],2);
goto P_0c082f0a;
P_0c082f0a: /* original 0023, guest PC 0x0c082f0a */
if(!s->budget--) { s->failed_pc=0x0c082f0au; return 0; }
target=r[0]+0x0c082f0eu;
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
P_0c082f0c: /* original 0009, guest PC 0x0c082f0c */
if(!s->budget--) { s->failed_pc=0x0c082f0cu; return 0; }
if(!vf3_matrix_family(0x0c082f0eu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c082f0eu; return 0; } return 1;
P_0c0831b4: /* original 9048, guest PC 0x0c0831b4 */
if(!s->budget--) { s->failed_pc=0x0c0831b4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c083248u,2);
goto P_0c0831b6;
P_0c0831b6: /* original 02de, guest PC 0x0c0831b6 */
if(!s->budget--) { s->failed_pc=0x0c0831b6u; return 0; }
r[2]=read(ram,r[13]+r[0],4);
goto P_0c0831b8;
P_0c0831b8: /* original 3e20, guest PC 0x0c0831b8 */
if(!s->budget--) { s->failed_pc=0x0c0831b8u; return 0; }
r[17]=(r[17]&~1u)|((r[14]==r[2])!=0);
goto P_0c0831ba;
P_0c0831ba: /* original 8b03, guest PC 0x0c0831ba */
if(!s->budget--) { s->failed_pc=0x0c0831bau; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0831c4; }
goto P_0c0831bc;
P_0c0831bc: /* original d328, guest PC 0x0c0831bc */
if(!s->budget--) { s->failed_pc=0x0c0831bcu; return 0; }
r[3]=read(ram,0x0c083260u,4);
goto P_0c0831be;
P_0c0831be: /* original 9548, guest PC 0x0c0831be */
if(!s->budget--) { s->failed_pc=0x0c0831beu; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c083252u,2);
goto P_0c0831c0;
P_0c0831c0: /* original 430b, guest PC 0x0c0831c0 */
if(!s->budget--) { s->failed_pc=0x0c0831c0u; return 0; }
target=r[3];
r[16]=code_base|0x0c0831c4u;
r[4]=read(ram,r[15]+4,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0831c4u) { target=s->pc; goto dispatch; }
goto P_0c0831c4;
P_0c0831c2: /* original 54f1, guest PC 0x0c0831c2 */
if(!s->budget--) { s->failed_pc=0x0c0831c2u; return 0; }
r[4]=read(ram,r[15]+4,4);
goto P_0c0831c4;
P_0c0831c4: /* original e20c, guest PC 0x0c0831c4 */
if(!s->budget--) { s->failed_pc=0x0c0831c4u; return 0; }
r[2]=0x0000000cu;
goto P_0c0831c6;
P_0c0831c6: /* original 7e01, guest PC 0x0c0831c6 */
if(!s->budget--) { s->failed_pc=0x0c0831c6u; return 0; }
r[14]+=0x00000001u;
goto P_0c0831c8;
P_0c0831c8: /* original 3e23, guest PC 0x0c0831c8 */
if(!s->budget--) { s->failed_pc=0x0c0831c8u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[14]>=(int32_t)r[2])!=0);
goto P_0c0831ca;
P_0c0831ca: /* original 8901, guest PC 0x0c0831ca */
if(!s->budget--) { s->failed_pc=0x0c0831cau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0831d0; }
goto P_0c0831cc;
P_0c0831cc: /* original ae3a, guest PC 0x0c0831cc */
if(!s->budget--) { s->failed_pc=0x0c0831ccu; return 0; }
goto P_0c082e44;
P_0c0831ce: /* original 0009, guest PC 0x0c0831ce */
if(!s->budget--) { s->failed_pc=0x0c0831ceu; return 0; }
goto P_0c0831d0;
P_0c0831d0: /* original 54f3, guest PC 0x0c0831d0 */
if(!s->budget--) { s->failed_pc=0x0c0831d0u; return 0; }
r[4]=read(ram,r[15]+12,4);
goto P_0c0831d2;
P_0c0831d2: /* original 55f4, guest PC 0x0c0831d2 */
if(!s->budget--) { s->failed_pc=0x0c0831d2u; return 0; }
r[5]=read(ram,r[15]+16,4);
goto P_0c0831d4;
P_0c0831d4: /* original 7f14, guest PC 0x0c0831d4 */
if(!s->budget--) { s->failed_pc=0x0c0831d4u; return 0; }
r[15]+=0x00000014u;
goto P_0c0831d6;
P_0c0831d6: /* original 4f26, guest PC 0x0c0831d6 */
if(!s->budget--) { s->failed_pc=0x0c0831d6u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0831d8;
P_0c0831d8: /* original d322, guest PC 0x0c0831d8 */
if(!s->budget--) { s->failed_pc=0x0c0831d8u; return 0; }
r[3]=read(ram,0x0c083264u,4);
goto P_0c0831da;
P_0c0831da: /* original 68f6, guest PC 0x0c0831da */
if(!s->budget--) { s->failed_pc=0x0c0831dau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c0831dc;
P_0c0831dc: /* original 69f6, guest PC 0x0c0831dc */
if(!s->budget--) { s->failed_pc=0x0c0831dcu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c0831de;
P_0c0831de: /* original 6af6, guest PC 0x0c0831de */
if(!s->budget--) { s->failed_pc=0x0c0831deu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0831e0;
P_0c0831e0: /* original 6bf6, guest PC 0x0c0831e0 */
if(!s->budget--) { s->failed_pc=0x0c0831e0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0831e2;
P_0c0831e2: /* original 6cf6, guest PC 0x0c0831e2 */
if(!s->budget--) { s->failed_pc=0x0c0831e2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0831e4;
P_0c0831e4: /* original 6df6, guest PC 0x0c0831e4 */
if(!s->budget--) { s->failed_pc=0x0c0831e4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0831e6;
P_0c0831e6: /* original 432b, guest PC 0x0c0831e6 */
if(!s->budget--) { s->failed_pc=0x0c0831e6u; return 0; }
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
P_0c0831e8: /* original 6ef6, guest PC 0x0c0831e8 */
if(!s->budget--) { s->failed_pc=0x0c0831e8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0831ea;
P_0c0831ea: /* original 2fe6, guest PC 0x0c0831ea */
if(!s->budget--) { s->failed_pc=0x0c0831eau; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0831ec;
P_0c0831ec: /* original 2fd6, guest PC 0x0c0831ec */
if(!s->budget--) { s->failed_pc=0x0c0831ecu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0831ee;
P_0c0831ee: /* original 2fc6, guest PC 0x0c0831ee */
if(!s->budget--) { s->failed_pc=0x0c0831eeu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0831f0;
P_0c0831f0: /* original 2fb6, guest PC 0x0c0831f0 */
if(!s->budget--) { s->failed_pc=0x0c0831f0u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0831f2;
P_0c0831f2: /* original 2fa6, guest PC 0x0c0831f2 */
if(!s->budget--) { s->failed_pc=0x0c0831f2u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0831f4;
P_0c0831f4: /* original 2f96, guest PC 0x0c0831f4 */
if(!s->budget--) { s->failed_pc=0x0c0831f4u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0831f6;
P_0c0831f6: /* original 2f86, guest PC 0x0c0831f6 */
if(!s->budget--) { s->failed_pc=0x0c0831f6u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0831f8;
P_0c0831f8: /* original 4f22, guest PC 0x0c0831f8 */
if(!s->budget--) { s->failed_pc=0x0c0831f8u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0831fa;
P_0c0831fa: /* original 9b2b, guest PC 0x0c0831fa */
if(!s->budget--) { s->failed_pc=0x0c0831fau; return 0; }
r[11]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c083254u,2);
goto P_0c0831fc;
P_0c0831fc: /* original 7fec, guest PC 0x0c0831fc */
if(!s->budget--) { s->failed_pc=0x0c0831fcu; return 0; }
r[15]+=0xffffffecu;
goto P_0c0831fe;
P_0c0831fe: /* original 1f43, guest PC 0x0c0831fe */
if(!s->budget--) { s->failed_pc=0x0c0831feu; return 0; }
write(ram,r[15]+12,r[4],4);
goto P_0c083200;
P_0c083200: /* original 1f54, guest PC 0x0c083200 */
if(!s->budget--) { s->failed_pc=0x0c083200u; return 0; }
write(ram,r[15]+16,r[5],4);
goto P_0c083202;
P_0c083202: /* original dd1a, guest PC 0x0c083202 */
if(!s->budget--) { s->failed_pc=0x0c083202u; return 0; }
r[13]=read(ram,0x0c08326cu,4);
goto P_0c083204;
P_0c083204: /* original de18, guest PC 0x0c083204 */
if(!s->budget--) { s->failed_pc=0x0c083204u; return 0; }
r[14]=read(ram,0x0c083268u,4);
goto P_0c083206;
P_0c083206: /* original d31a, guest PC 0x0c083206 */
if(!s->budget--) { s->failed_pc=0x0c083206u; return 0; }
r[3]=read(ram,0x0c083270u,4);
goto P_0c083208;
P_0c083208: /* original 430b, guest PC 0x0c083208 */
if(!s->budget--) { s->failed_pc=0x0c083208u; return 0; }
target=r[3];
r[16]=code_base|0x0c08320cu;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08320cu) { target=s->pc; goto dispatch; }
goto P_0c08320c;
P_0c08320a: /* original 64d3, guest PC 0x0c08320a */
if(!s->budget--) { s->failed_pc=0x0c08320au; return 0; }
r[4]=r[13];
goto P_0c08320c;
P_0c08320c: /* original d213, guest PC 0x0c08320c */
if(!s->budget--) { s->failed_pc=0x0c08320cu; return 0; }
r[2]=read(ram,0x0c08325cu,4);
goto P_0c08320e;
P_0c08320e: /* original e502, guest PC 0x0c08320e */
if(!s->budget--) { s->failed_pc=0x0c08320eu; return 0; }
r[5]=0x00000002u;
goto P_0c083210;
P_0c083210: /* original 9621, guest PC 0x0c083210 */
if(!s->budget--) { s->failed_pc=0x0c083210u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c083256u,2);
goto P_0c083212;
P_0c083212: /* original 420b, guest PC 0x0c083212 */
if(!s->budget--) { s->failed_pc=0x0c083212u; return 0; }
target=r[2];
r[16]=code_base|0x0c083216u;
r[4]=0x00000016u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c083216u) { target=s->pc; goto dispatch; }
goto P_0c083216;
P_0c083214: /* original e416, guest PC 0x0c083214 */
if(!s->budget--) { s->failed_pc=0x0c083214u; return 0; }
r[4]=0x00000016u;
goto P_0c083216;
P_0c083216: /* original a42d, guest PC 0x0c083216 */
if(!s->budget--) { s->failed_pc=0x0c083216u; return 0; }
r[10]=0x00000000u;
goto P_0c083a74;
P_0c083218: /* original ea00, guest PC 0x0c083218 */
if(!s->budget--) { s->failed_pc=0x0c083218u; return 0; }
r[10]=0x00000000u;
goto P_0c08321a;
P_0c08321a: /* original dc16, guest PC 0x0c08321a */
if(!s->budget--) { s->failed_pc=0x0c08321au; return 0; }
r[12]=read(ram,0x0c083274u,4);
goto P_0c08321c;
P_0c08321c: /* original 4c0b, guest PC 0x0c08321c */
if(!s->budget--) { s->failed_pc=0x0c08321cu; return 0; }
target=r[12];
r[16]=code_base|0x0c083220u;
r[4]=r[10];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c083220u) { target=s->pc; goto dispatch; }
goto P_0c083220;
P_0c08321e: /* original 64a3, guest PC 0x0c08321e */
if(!s->budget--) { s->failed_pc=0x0c08321eu; return 0; }
r[4]=r[10];
goto P_0c083220;
P_0c083220: /* original 68a3, guest PC 0x0c083220 */
if(!s->budget--) { s->failed_pc=0x0c083220u; return 0; }
r[8]=r[10];
goto P_0c083222;
P_0c083222: /* original 4808, guest PC 0x0c083222 */
if(!s->budget--) { s->failed_pc=0x0c083222u; return 0; }
r[8]<<=2;
goto P_0c083224;
P_0c083224: /* original 63a3, guest PC 0x0c083224 */
if(!s->budget--) { s->failed_pc=0x0c083224u; return 0; }
r[3]=r[10];
goto P_0c083226;
P_0c083226: /* original 383c, guest PC 0x0c083226 */
if(!s->budget--) { s->failed_pc=0x0c083226u; return 0; }
r[8]+=r[3];
goto P_0c083228;
P_0c083228: /* original 6903, guest PC 0x0c083228 */
if(!s->budget--) { s->failed_pc=0x0c083228u; return 0; }
r[9]=r[0];
goto P_0c08322a;
P_0c08322a: /* original 6392, guest PC 0x0c08322a */
if(!s->budget--) { s->failed_pc=0x0c08322au; return 0; }
tmp=read(ram,r[9],4);
r[3]=tmp;
goto P_0c08322c;
P_0c08322c: /* original d212, guest PC 0x0c08322c */
if(!s->budget--) { s->failed_pc=0x0c08322cu; return 0; }
r[2]=read(ram,0x0c083278u,4);
goto P_0c08322e;
P_0c08322e: /* original 4808, guest PC 0x0c08322e */
if(!s->budget--) { s->failed_pc=0x0c08322eu; return 0; }
r[8]<<=2;
goto P_0c083230;
P_0c083230: /* original 6c83, guest PC 0x0c083230 */
if(!s->budget--) { s->failed_pc=0x0c083230u; return 0; }
r[12]=r[8];
goto P_0c083232;
P_0c083232: /* original 3320, guest PC 0x0c083232 */
if(!s->budget--) { s->failed_pc=0x0c083232u; return 0; }
r[17]=(r[17]&~1u)|((r[3]==r[2])!=0);
goto P_0c083234;
P_0c083234: /* original 8f22, guest PC 0x0c083234 */
if(!s->budget--) { s->failed_pc=0x0c083234u; return 0; }
cond=r[17]&1u;
r[12]+=0x00000007u;
if(!cond) { goto P_0c08327c; }
goto P_0c083238;
P_0c083236: /* original 7c07, guest PC 0x0c083236 */
if(!s->budget--) { s->failed_pc=0x0c083236u; return 0; }
r[12]+=0x00000007u;
goto P_0c083238;
P_0c083238: /* original d308, guest PC 0x0c083238 */
if(!s->budget--) { s->failed_pc=0x0c083238u; return 0; }
r[3]=read(ram,0x0c08325cu,4);
goto P_0c08323a;
P_0c08323a: /* original 65c3, guest PC 0x0c08323a */
if(!s->budget--) { s->failed_pc=0x0c08323au; return 0; }
r[5]=r[12];
goto P_0c08323c;
P_0c08323c: /* original 960c, guest PC 0x0c08323c */
if(!s->budget--) { s->failed_pc=0x0c08323cu; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c083258u,2);
goto P_0c08323e;
P_0c08323e: /* original 430b, guest PC 0x0c08323e */
if(!s->budget--) { s->failed_pc=0x0c08323eu; return 0; }
target=r[3];
r[16]=code_base|0x0c083242u;
r[4]=0x0000001du;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c083242u) { target=s->pc; goto dispatch; }
goto P_0c083242;
P_0c083240: /* original e41d, guest PC 0x0c083240 */
if(!s->budget--) { s->failed_pc=0x0c083240u; return 0; }
r[4]=0x0000001du;
goto P_0c083242;
P_0c083242: /* original a022, guest PC 0x0c083242 */
if(!s->budget--) { s->failed_pc=0x0c083242u; return 0; }
goto P_0c08328a;
P_0c083244: /* original 0009, guest PC 0x0c083244 */
if(!s->budget--) { s->failed_pc=0x0c083244u; return 0; }
if(!vf3_matrix_family(0x0c083246u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c083246u; return 0; } return 1;
P_0c08327c: /* original 33b0, guest PC 0x0c08327c */
if(!s->budget--) { s->failed_pc=0x0c08327cu; return 0; }
r[17]=(r[17]&~1u)|((r[3]==r[11])!=0);
goto P_0c08327e;
P_0c08327e: /* original 8b04, guest PC 0x0c08327e */
if(!s->budget--) { s->failed_pc=0x0c08327eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c08328a; }
goto P_0c083280;
P_0c083280: /* original d33e, guest PC 0x0c083280 */
if(!s->budget--) { s->failed_pc=0x0c083280u; return 0; }
r[3]=read(ram,0x0c08337cu,4);
goto P_0c083282;
P_0c083282: /* original 65c3, guest PC 0x0c083282 */
if(!s->budget--) { s->failed_pc=0x0c083282u; return 0; }
r[5]=r[12];
goto P_0c083284;
P_0c083284: /* original 966f, guest PC 0x0c083284 */
if(!s->budget--) { s->failed_pc=0x0c083284u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c083366u,2);
goto P_0c083286;
P_0c083286: /* original 430b, guest PC 0x0c083286 */
if(!s->budget--) { s->failed_pc=0x0c083286u; return 0; }
target=r[3];
r[16]=code_base|0x0c08328au;
r[4]=0x00000021u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08328au) { target=s->pc; goto dispatch; }
goto P_0c08328a;
P_0c083288: /* original e421, guest PC 0x0c083288 */
if(!s->budget--) { s->failed_pc=0x0c083288u; return 0; }
r[4]=0x00000021u;
goto P_0c08328a;
P_0c08328a: /* original d53d, guest PC 0x0c08328a */
if(!s->budget--) { s->failed_pc=0x0c08328au; return 0; }
r[5]=read(ram,0x0c083380u,4);
goto P_0c08328c;
P_0c08328c: /* original e408, guest PC 0x0c08328c */
if(!s->budget--) { s->failed_pc=0x0c08328cu; return 0; }
r[4]=0x00000008u;
goto P_0c08328e;
P_0c08328e: /* original 63a3, guest PC 0x0c08328e */
if(!s->budget--) { s->failed_pc=0x0c08328eu; return 0; }
r[3]=r[10];
goto P_0c083290;
P_0c083290: /* original 4308, guest PC 0x0c083290 */
if(!s->budget--) { s->failed_pc=0x0c083290u; return 0; }
r[3]<<=2;
goto P_0c083292;
P_0c083292: /* original 6252, guest PC 0x0c083292 */
if(!s->budget--) { s->failed_pc=0x0c083292u; return 0; }
tmp=read(ram,r[5],4);
r[2]=tmp;
goto P_0c083294;
P_0c083294: /* original e501, guest PC 0x0c083294 */
if(!s->budget--) { s->failed_pc=0x0c083294u; return 0; }
r[5]=0x00000001u;
goto P_0c083296;
P_0c083296: /* original 2249, guest PC 0x0c083296 */
if(!s->budget--) { s->failed_pc=0x0c083296u; return 0; }
r[2]&=r[4];
goto P_0c083298;
P_0c083298: /* original 1f22, guest PC 0x0c083298 */
if(!s->budget--) { s->failed_pc=0x0c083298u; return 0; }
write(ram,r[15]+8,r[2],4);
goto P_0c08329a;
P_0c08329a: /* original 2f32, guest PC 0x0c08329a */
if(!s->budget--) { s->failed_pc=0x0c08329au; return 0; }
write(ram,r[15],r[3],4);
goto P_0c08329c;
P_0c08329c: /* original 9264, guest PC 0x0c08329c */
if(!s->budget--) { s->failed_pc=0x0c08329cu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c083368u,2);
goto P_0c08329e;
P_0c08329e: /* original 32ec, guest PC 0x0c08329e */
if(!s->budget--) { s->failed_pc=0x0c08329eu; return 0; }
r[2]+=r[14];
goto P_0c0832a0;
P_0c0832a0: /* original 332c, guest PC 0x0c0832a0 */
if(!s->budget--) { s->failed_pc=0x0c0832a0u; return 0; }
r[3]+=r[2];
goto P_0c0832a2;
P_0c0832a2: /* original 62d3, guest PC 0x0c0832a2 */
if(!s->budget--) { s->failed_pc=0x0c0832a2u; return 0; }
r[2]=r[13];
goto P_0c0832a4;
P_0c0832a4: /* original 6132, guest PC 0x0c0832a4 */
if(!s->budget--) { s->failed_pc=0x0c0832a4u; return 0; }
tmp=read(ram,r[3],4);
r[1]=tmp;
goto P_0c0832a6;
P_0c0832a6: /* original e307, guest PC 0x0c0832a6 */
if(!s->budget--) { s->failed_pc=0x0c0832a6u; return 0; }
r[3]=0x00000007u;
goto P_0c0832a8;
P_0c0832a8: /* original 423c, guest PC 0x0c0832a8 */
if(!s->budget--) { s->failed_pc=0x0c0832a8u; return 0; }
r[2]=(r[3]&0x80000000u)?((r[3]&31u)?(uint32_t)((int32_t)r[2]>>((-r[3])&31u)):((int32_t)r[2]<0?0xffffffffu:0)):r[2]<<(r[3]&31u);
goto P_0c0832aa;
P_0c0832aa: /* original 2159, guest PC 0x0c0832aa */
if(!s->budget--) { s->failed_pc=0x0c0832aau; return 0; }
r[1]&=r[5];
goto P_0c0832ac;
P_0c0832ac: /* original 65c3, guest PC 0x0c0832ac */
if(!s->budget--) { s->failed_pc=0x0c0832acu; return 0; }
r[5]=r[12];
goto P_0c0832ae;
P_0c0832ae: /* original 1f11, guest PC 0x0c0832ae */
if(!s->budget--) { s->failed_pc=0x0c0832aeu; return 0; }
write(ram,r[15]+4,r[1],4);
goto P_0c0832b0;
P_0c0832b0: /* original 224b, guest PC 0x0c0832b0 */
if(!s->budget--) { s->failed_pc=0x0c0832b0u; return 0; }
r[2]|=r[4];
goto P_0c0832b2;
P_0c0832b2: /* original 1f24, guest PC 0x0c0832b2 */
if(!s->budget--) { s->failed_pc=0x0c0832b2u; return 0; }
write(ram,r[15]+16,r[2],4);
goto P_0c0832b4;
P_0c0832b4: /* original 9659, guest PC 0x0c0832b4 */
if(!s->budget--) { s->failed_pc=0x0c0832b4u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08336au,2);
goto P_0c0832b6;
P_0c0832b6: /* original d131, guest PC 0x0c0832b6 */
if(!s->budget--) { s->failed_pc=0x0c0832b6u; return 0; }
r[1]=read(ram,0x0c08337cu,4);
goto P_0c0832b8;
P_0c0832b8: /* original 36ac, guest PC 0x0c0832b8 */
if(!s->budget--) { s->failed_pc=0x0c0832b8u; return 0; }
r[6]+=r[10];
goto P_0c0832ba;
P_0c0832ba: /* original 410b, guest PC 0x0c0832ba */
if(!s->budget--) { s->failed_pc=0x0c0832bau; return 0; }
target=r[1];
r[16]=code_base|0x0c0832beu;
r[4]=0x00000004u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0832beu) { target=s->pc; goto dispatch; }
goto P_0c0832be;
P_0c0832bc: /* original e404, guest PC 0x0c0832bc */
if(!s->budget--) { s->failed_pc=0x0c0832bcu; return 0; }
r[4]=0x00000004u;
goto P_0c0832be;
P_0c0832be: /* original 9053, guest PC 0x0c0832be */
if(!s->budget--) { s->failed_pc=0x0c0832beu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c083368u,2);
goto P_0c0832c0;
P_0c0832c0: /* original 63f2, guest PC 0x0c0832c0 */
if(!s->budget--) { s->failed_pc=0x0c0832c0u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c0832c2;
P_0c0832c2: /* original 30ec, guest PC 0x0c0832c2 */
if(!s->budget--) { s->failed_pc=0x0c0832c2u; return 0; }
r[0]+=r[14];
goto P_0c0832c4;
P_0c0832c4: /* original 003e, guest PC 0x0c0832c4 */
if(!s->budget--) { s->failed_pc=0x0c0832c4u; return 0; }
r[0]=read(ram,r[3]+r[0],4);
goto P_0c0832c6;
P_0c0832c6: /* original c804, guest PC 0x0c0832c6 */
if(!s->budget--) { s->failed_pc=0x0c0832c6u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&4u)==0)!=0);
goto P_0c0832c8;
P_0c0832c8: /* original 8907, guest PC 0x0c0832c8 */
if(!s->budget--) { s->failed_pc=0x0c0832c8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0832da; }
goto P_0c0832ca;
P_0c0832ca: /* original 994f, guest PC 0x0c0832ca */
if(!s->budget--) { s->failed_pc=0x0c0832cau; return 0; }
r[9]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08336cu,2);
goto P_0c0832cc;
P_0c0832cc: /* original 65c3, guest PC 0x0c0832cc */
if(!s->budget--) { s->failed_pc=0x0c0832ccu; return 0; }
r[5]=r[12];
goto P_0c0832ce;
P_0c0832ce: /* original d12b, guest PC 0x0c0832ce */
if(!s->budget--) { s->failed_pc=0x0c0832ceu; return 0; }
r[1]=read(ram,0x0c08337cu,4);
goto P_0c0832d0;
P_0c0832d0: /* original 6693, guest PC 0x0c0832d0 */
if(!s->budget--) { s->failed_pc=0x0c0832d0u; return 0; }
r[6]=r[9];
goto P_0c0832d2;
P_0c0832d2: /* original 410b, guest PC 0x0c0832d2 */
if(!s->budget--) { s->failed_pc=0x0c0832d2u; return 0; }
target=r[1];
r[16]=code_base|0x0c0832d6u;
r[4]=0x00000007u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0832d6u) { target=s->pc; goto dispatch; }
goto P_0c0832d6;
P_0c0832d4: /* original e407, guest PC 0x0c0832d4 */
if(!s->budget--) { s->failed_pc=0x0c0832d4u; return 0; }
r[4]=0x00000007u;
goto P_0c0832d6;
P_0c0832d6: /* original a3cb, guest PC 0x0c0832d6 */
if(!s->budget--) { s->failed_pc=0x0c0832d6u; return 0; }
goto P_0c083a70;
P_0c0832d8: /* original 0009, guest PC 0x0c0832d8 */
if(!s->budget--) { s->failed_pc=0x0c0832d8u; return 0; }
goto P_0c0832da;
P_0c0832da: /* original 6283, guest PC 0x0c0832da */
if(!s->budget--) { s->failed_pc=0x0c0832dau; return 0; }
r[2]=r[8];
goto P_0c0832dc;
P_0c0832dc: /* original 7217, guest PC 0x0c0832dc */
if(!s->budget--) { s->failed_pc=0x0c0832dcu; return 0; }
r[2]+=0x00000017u;
goto P_0c0832de;
P_0c0832de: /* original 9d46, guest PC 0x0c0832de */
if(!s->budget--) { s->failed_pc=0x0c0832deu; return 0; }
r[13]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08336eu,2);
goto P_0c0832e0;
P_0c0832e0: /* original 2f22, guest PC 0x0c0832e0 */
if(!s->budget--) { s->failed_pc=0x0c0832e0u; return 0; }
write(ram,r[15],r[2],4);
goto P_0c0832e2;
P_0c0832e2: /* original 51f1, guest PC 0x0c0832e2 */
if(!s->budget--) { s->failed_pc=0x0c0832e2u; return 0; }
r[1]=read(ram,r[15]+4,4);
goto P_0c0832e4;
P_0c0832e4: /* original 2118, guest PC 0x0c0832e4 */
if(!s->budget--) { s->failed_pc=0x0c0832e4u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[1])==0)!=0);
goto P_0c0832e6;
P_0c0832e6: /* original 8910, guest PC 0x0c0832e6 */
if(!s->budget--) { s->failed_pc=0x0c0832e6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c08330a; }
goto P_0c0832e8;
P_0c0832e8: /* original d124, guest PC 0x0c0832e8 */
if(!s->budget--) { s->failed_pc=0x0c0832e8u; return 0; }
r[1]=read(ram,0x0c08337cu,4);
goto P_0c0832ea;
P_0c0832ea: /* original 65c3, guest PC 0x0c0832ea */
if(!s->budget--) { s->failed_pc=0x0c0832eau; return 0; }
r[5]=r[12];
goto P_0c0832ec;
P_0c0832ec: /* original 9640, guest PC 0x0c0832ec */
if(!s->budget--) { s->failed_pc=0x0c0832ecu; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c083370u,2);
goto P_0c0832ee;
P_0c0832ee: /* original 410b, guest PC 0x0c0832ee */
if(!s->budget--) { s->failed_pc=0x0c0832eeu; return 0; }
target=r[1];
r[16]=code_base|0x0c0832f2u;
r[4]=0x00000014u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0832f2u) { target=s->pc; goto dispatch; }
goto P_0c0832f2;
P_0c0832f0: /* original e414, guest PC 0x0c0832f0 */
if(!s->budget--) { s->failed_pc=0x0c0832f0u; return 0; }
r[4]=0x00000014u;
goto P_0c0832f2;
P_0c0832f2: /* original d322, guest PC 0x0c0832f2 */
if(!s->budget--) { s->failed_pc=0x0c0832f2u; return 0; }
r[3]=read(ram,0x0c08337cu,4);
goto P_0c0832f4;
P_0c0832f4: /* original 65c3, guest PC 0x0c0832f4 */
if(!s->budget--) { s->failed_pc=0x0c0832f4u; return 0; }
r[5]=r[12];
goto P_0c0832f6;
P_0c0832f6: /* original 963c, guest PC 0x0c0832f6 */
if(!s->budget--) { s->failed_pc=0x0c0832f6u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c083372u,2);
goto P_0c0832f8;
P_0c0832f8: /* original 430b, guest PC 0x0c0832f8 */
if(!s->budget--) { s->failed_pc=0x0c0832f8u; return 0; }
target=r[3];
r[16]=code_base|0x0c0832fcu;
r[4]=0x00000007u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0832fcu) { target=s->pc; goto dispatch; }
goto P_0c0832fc;
P_0c0832fa: /* original e407, guest PC 0x0c0832fa */
if(!s->budget--) { s->failed_pc=0x0c0832fau; return 0; }
r[4]=0x00000007u;
goto P_0c0832fc;
P_0c0832fc: /* original d31f, guest PC 0x0c0832fc */
if(!s->budget--) { s->failed_pc=0x0c0832fcu; return 0; }
r[3]=read(ram,0x0c08337cu,4);
goto P_0c0832fe;
P_0c0832fe: /* original 66d3, guest PC 0x0c0832fe */
if(!s->budget--) { s->failed_pc=0x0c0832feu; return 0; }
r[6]=r[13];
goto P_0c083300;
P_0c083300: /* original 65f2, guest PC 0x0c083300 */
if(!s->budget--) { s->failed_pc=0x0c083300u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c083302;
P_0c083302: /* original 430b, guest PC 0x0c083302 */
if(!s->budget--) { s->failed_pc=0x0c083302u; return 0; }
target=r[3];
r[16]=code_base|0x0c083306u;
r[4]=0x00000010u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c083306u) { target=s->pc; goto dispatch; }
goto P_0c083306;
P_0c083304: /* original e410, guest PC 0x0c083304 */
if(!s->budget--) { s->failed_pc=0x0c083304u; return 0; }
r[4]=0x00000010u;
goto P_0c083306;
P_0c083306: /* original a068, guest PC 0x0c083306 */
if(!s->budget--) { s->failed_pc=0x0c083306u; return 0; }
goto P_0c0833da;
P_0c083308: /* original 0009, guest PC 0x0c083308 */
if(!s->budget--) { s->failed_pc=0x0c083308u; return 0; }
goto P_0c08330a;
P_0c08330a: /* original 9233, guest PC 0x0c08330a */
if(!s->budget--) { s->failed_pc=0x0c08330au; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c083374u,2);
goto P_0c08330c;
P_0c08330c: /* original 63a3, guest PC 0x0c08330c */
if(!s->budget--) { s->failed_pc=0x0c08330cu; return 0; }
r[3]=r[10];
goto P_0c08330e;
P_0c08330e: /* original 4308, guest PC 0x0c08330e */
if(!s->budget--) { s->failed_pc=0x0c08330eu; return 0; }
r[3]<<=2;
goto P_0c083310;
P_0c083310: /* original 32ec, guest PC 0x0c083310 */
if(!s->budget--) { s->failed_pc=0x0c083310u; return 0; }
r[2]+=r[14];
goto P_0c083312;
P_0c083312: /* original 332c, guest PC 0x0c083312 */
if(!s->budget--) { s->failed_pc=0x0c083312u; return 0; }
r[3]+=r[2];
goto P_0c083314;
P_0c083314: /* original 6132, guest PC 0x0c083314 */
if(!s->budget--) { s->failed_pc=0x0c083314u; return 0; }
tmp=read(ram,r[3],4);
r[1]=tmp;
goto P_0c083316;
P_0c083316: /* original 2118, guest PC 0x0c083316 */
if(!s->budget--) { s->failed_pc=0x0c083316u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[1])==0)!=0);
goto P_0c083318;
P_0c083318: /* original 8b34, guest PC 0x0c083318 */
if(!s->budget--) { s->failed_pc=0x0c083318u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c083384; }
goto P_0c08331a;
P_0c08331a: /* original d318, guest PC 0x0c08331a */
if(!s->budget--) { s->failed_pc=0x0c08331au; return 0; }
r[3]=read(ram,0x0c08337cu,4);
goto P_0c08331c;
P_0c08331c: /* original 65c3, guest PC 0x0c08331c */
if(!s->budget--) { s->failed_pc=0x0c08331cu; return 0; }
r[5]=r[12];
goto P_0c08331e;
P_0c08331e: /* original 9627, guest PC 0x0c08331e */
if(!s->budget--) { s->failed_pc=0x0c08331eu; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c083370u,2);
goto P_0c083320;
P_0c083320: /* original 430b, guest PC 0x0c083320 */
if(!s->budget--) { s->failed_pc=0x0c083320u; return 0; }
target=r[3];
r[16]=code_base|0x0c083324u;
r[4]=0x00000014u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c083324u) { target=s->pc; goto dispatch; }
goto P_0c083324;
P_0c083322: /* original e414, guest PC 0x0c083322 */
if(!s->budget--) { s->failed_pc=0x0c083322u; return 0; }
r[4]=0x00000014u;
goto P_0c083324;
P_0c083324: /* original 9327, guest PC 0x0c083324 */
if(!s->budget--) { s->failed_pc=0x0c083324u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c083376u,2);
goto P_0c083326;
P_0c083326: /* original 60a3, guest PC 0x0c083326 */
if(!s->budget--) { s->failed_pc=0x0c083326u; return 0; }
r[0]=r[10];
goto P_0c083328;
P_0c083328: /* original 4008, guest PC 0x0c083328 */
if(!s->budget--) { s->failed_pc=0x0c083328u; return 0; }
r[0]<<=2;
goto P_0c08332a;
P_0c08332a: /* original 33ec, guest PC 0x0c08332a */
if(!s->budget--) { s->failed_pc=0x0c08332au; return 0; }
r[3]+=r[14];
goto P_0c08332c;
P_0c08332c: /* original 003e, guest PC 0x0c08332c */
if(!s->budget--) { s->failed_pc=0x0c08332cu; return 0; }
r[0]=read(ram,r[3]+r[0],4);
goto P_0c08332e;
P_0c08332e: /* original 8809, guest PC 0x0c08332e */
if(!s->budget--) { s->failed_pc=0x0c08332eu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000009u)!=0);
goto P_0c083330;
P_0c083330: /* original 8b09, guest PC 0x0c083330 */
if(!s->budget--) { s->failed_pc=0x0c083330u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c083346; }
goto P_0c083332;
P_0c083332: /* original 53f2, guest PC 0x0c083332 */
if(!s->budget--) { s->failed_pc=0x0c083332u; return 0; }
r[3]=read(ram,r[15]+8,4);
goto P_0c083334;
P_0c083334: /* original 2338, guest PC 0x0c083334 */
if(!s->budget--) { s->failed_pc=0x0c083334u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c083336;
P_0c083336: /* original 890e, guest PC 0x0c083336 */
if(!s->budget--) { s->failed_pc=0x0c083336u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c083356; }
goto P_0c083338;
P_0c083338: /* original d310, guest PC 0x0c083338 */
if(!s->budget--) { s->failed_pc=0x0c083338u; return 0; }
r[3]=read(ram,0x0c08337cu,4);
goto P_0c08333a;
P_0c08333a: /* original 65f2, guest PC 0x0c08333a */
if(!s->budget--) { s->failed_pc=0x0c08333au; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c08333c;
P_0c08333c: /* original 961c, guest PC 0x0c08333c */
if(!s->budget--) { s->failed_pc=0x0c08333cu; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c083378u,2);
goto P_0c08333e;
P_0c08333e: /* original 430b, guest PC 0x0c08333e */
if(!s->budget--) { s->failed_pc=0x0c08333eu; return 0; }
target=r[3];
r[16]=code_base|0x0c083342u;
r[4]=0x00000010u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c083342u) { target=s->pc; goto dispatch; }
goto P_0c083342;
P_0c083340: /* original e410, guest PC 0x0c083340 */
if(!s->budget--) { s->failed_pc=0x0c083340u; return 0; }
r[4]=0x00000010u;
goto P_0c083342;
P_0c083342: /* original a008, guest PC 0x0c083342 */
if(!s->budget--) { s->failed_pc=0x0c083342u; return 0; }
goto P_0c083356;
P_0c083344: /* original 0009, guest PC 0x0c083344 */
if(!s->budget--) { s->failed_pc=0x0c083344u; return 0; }
goto P_0c083346;
P_0c083346: /* original d30d, guest PC 0x0c083346 */
if(!s->budget--) { s->failed_pc=0x0c083346u; return 0; }
r[3]=read(ram,0x0c08337cu,4);
goto P_0c083348;
P_0c083348: /* original 66d3, guest PC 0x0c083348 */
if(!s->budget--) { s->failed_pc=0x0c083348u; return 0; }
r[6]=r[13];
goto P_0c08334a;
P_0c08334a: /* original 65f2, guest PC 0x0c08334a */
if(!s->budget--) { s->failed_pc=0x0c08334au; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c08334c;
P_0c08334c: /* original 430b, guest PC 0x0c08334c */
if(!s->budget--) { s->failed_pc=0x0c08334cu; return 0; }
target=r[3];
r[16]=code_base|0x0c083350u;
r[4]=0x00000010u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c083350u) { target=s->pc; goto dispatch; }
goto P_0c083350;
P_0c08334e: /* original e410, guest PC 0x0c08334e */
if(!s->budget--) { s->failed_pc=0x0c08334eu; return 0; }
r[4]=0x00000010u;
goto P_0c083350;
P_0c083350: /* original 52f2, guest PC 0x0c083350 */
if(!s->budget--) { s->failed_pc=0x0c083350u; return 0; }
r[2]=read(ram,r[15]+8,4);
goto P_0c083352;
P_0c083352: /* original 2228, guest PC 0x0c083352 */
if(!s->budget--) { s->failed_pc=0x0c083352u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c083354;
P_0c083354: /* original 8941, guest PC 0x0c083354 */
if(!s->budget--) { s->failed_pc=0x0c083354u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0833da; }
goto P_0c083356;
P_0c083356: /* original 9d10, guest PC 0x0c083356 */
if(!s->budget--) { s->failed_pc=0x0c083356u; return 0; }
r[13]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08337au,2);
goto P_0c083358;
P_0c083358: /* original 65c3, guest PC 0x0c083358 */
if(!s->budget--) { s->failed_pc=0x0c083358u; return 0; }
r[5]=r[12];
goto P_0c08335a;
P_0c08335a: /* original d308, guest PC 0x0c08335a */
if(!s->budget--) { s->failed_pc=0x0c08335au; return 0; }
r[3]=read(ram,0x0c08337cu,4);
goto P_0c08335c;
P_0c08335c: /* original 66d3, guest PC 0x0c08335c */
if(!s->budget--) { s->failed_pc=0x0c08335cu; return 0; }
r[6]=r[13];
goto P_0c08335e;
P_0c08335e: /* original 430b, guest PC 0x0c08335e */
if(!s->budget--) { s->failed_pc=0x0c08335eu; return 0; }
target=r[3];
r[16]=code_base|0x0c083362u;
r[4]=0x00000007u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c083362u) { target=s->pc; goto dispatch; }
goto P_0c083362;
P_0c083360: /* original e407, guest PC 0x0c083360 */
if(!s->budget--) { s->failed_pc=0x0c083360u; return 0; }
r[4]=0x00000007u;
goto P_0c083362;
P_0c083362: /* original a03a, guest PC 0x0c083362 */
if(!s->budget--) { s->failed_pc=0x0c083362u; return 0; }
goto P_0c0833da;
P_0c083364: /* original 0009, guest PC 0x0c083364 */
if(!s->budget--) { s->failed_pc=0x0c083364u; return 0; }
if(!vf3_matrix_family(0x0c083366u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c083366u; return 0; } return 1;
P_0c083384: /* original 9386, guest PC 0x0c083384 */
if(!s->budget--) { s->failed_pc=0x0c083384u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c083494u,2);
goto P_0c083386;
P_0c083386: /* original 60a3, guest PC 0x0c083386 */
if(!s->budget--) { s->failed_pc=0x0c083386u; return 0; }
r[0]=r[10];
goto P_0c083388;
P_0c083388: /* original 4008, guest PC 0x0c083388 */
if(!s->budget--) { s->failed_pc=0x0c083388u; return 0; }
r[0]<<=2;
goto P_0c08338a;
P_0c08338a: /* original 33ec, guest PC 0x0c08338a */
if(!s->budget--) { s->failed_pc=0x0c08338au; return 0; }
r[3]+=r[14];
goto P_0c08338c;
P_0c08338c: /* original 003e, guest PC 0x0c08338c */
if(!s->budget--) { s->failed_pc=0x0c08338cu; return 0; }
r[0]=read(ram,r[3]+r[0],4);
goto P_0c08338e;
P_0c08338e: /* original 8801, guest PC 0x0c08338e */
if(!s->budget--) { s->failed_pc=0x0c08338eu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c083390;
P_0c083390: /* original 8b23, guest PC 0x0c083390 */
if(!s->budget--) { s->failed_pc=0x0c083390u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0833da; }
goto P_0c083392;
P_0c083392: /* original d344, guest PC 0x0c083392 */
if(!s->budget--) { s->failed_pc=0x0c083392u; return 0; }
r[3]=read(ram,0x0c0834a4u,4);
goto P_0c083394;
P_0c083394: /* original 65c3, guest PC 0x0c083394 */
if(!s->budget--) { s->failed_pc=0x0c083394u; return 0; }
r[5]=r[12];
goto P_0c083396;
P_0c083396: /* original 967e, guest PC 0x0c083396 */
if(!s->budget--) { s->failed_pc=0x0c083396u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c083496u,2);
goto P_0c083398;
P_0c083398: /* original 430b, guest PC 0x0c083398 */
if(!s->budget--) { s->failed_pc=0x0c083398u; return 0; }
target=r[3];
r[16]=code_base|0x0c08339cu;
r[4]=0x00000007u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08339cu) { target=s->pc; goto dispatch; }
goto P_0c08339c;
P_0c08339a: /* original e407, guest PC 0x0c08339a */
if(!s->budget--) { s->failed_pc=0x0c08339au; return 0; }
r[4]=0x00000007u;
goto P_0c08339c;
P_0c08339c: /* original 937c, guest PC 0x0c08339c */
if(!s->budget--) { s->failed_pc=0x0c08339cu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c083498u,2);
goto P_0c08339e;
P_0c08339e: /* original 60a3, guest PC 0x0c08339e */
if(!s->budget--) { s->failed_pc=0x0c08339eu; return 0; }
r[0]=r[10];
goto P_0c0833a0;
P_0c0833a0: /* original 4008, guest PC 0x0c0833a0 */
if(!s->budget--) { s->failed_pc=0x0c0833a0u; return 0; }
r[0]<<=2;
goto P_0c0833a2;
P_0c0833a2: /* original 33ec, guest PC 0x0c0833a2 */
if(!s->budget--) { s->failed_pc=0x0c0833a2u; return 0; }
r[3]+=r[14];
goto P_0c0833a4;
P_0c0833a4: /* original 003e, guest PC 0x0c0833a4 */
if(!s->budget--) { s->failed_pc=0x0c0833a4u; return 0; }
r[0]=read(ram,r[3]+r[0],4);
goto P_0c0833a6;
P_0c0833a6: /* original 8809, guest PC 0x0c0833a6 */
if(!s->budget--) { s->failed_pc=0x0c0833a6u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000009u)!=0);
goto P_0c0833a8;
P_0c0833a8: /* original 8b09, guest PC 0x0c0833a8 */
if(!s->budget--) { s->failed_pc=0x0c0833a8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0833be; }
goto P_0c0833aa;
P_0c0833aa: /* original 53f2, guest PC 0x0c0833aa */
if(!s->budget--) { s->failed_pc=0x0c0833aau; return 0; }
r[3]=read(ram,r[15]+8,4);
goto P_0c0833ac;
P_0c0833ac: /* original 2338, guest PC 0x0c0833ac */
if(!s->budget--) { s->failed_pc=0x0c0833acu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c0833ae;
P_0c0833ae: /* original 890e, guest PC 0x0c0833ae */
if(!s->budget--) { s->failed_pc=0x0c0833aeu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0833ce; }
goto P_0c0833b0;
P_0c0833b0: /* original d33c, guest PC 0x0c0833b0 */
if(!s->budget--) { s->failed_pc=0x0c0833b0u; return 0; }
r[3]=read(ram,0x0c0834a4u,4);
goto P_0c0833b2;
P_0c0833b2: /* original 65f2, guest PC 0x0c0833b2 */
if(!s->budget--) { s->failed_pc=0x0c0833b2u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0833b4;
P_0c0833b4: /* original 9671, guest PC 0x0c0833b4 */
if(!s->budget--) { s->failed_pc=0x0c0833b4u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08349au,2);
goto P_0c0833b6;
P_0c0833b6: /* original 430b, guest PC 0x0c0833b6 */
if(!s->budget--) { s->failed_pc=0x0c0833b6u; return 0; }
target=r[3];
r[16]=code_base|0x0c0833bau;
r[4]=0x00000010u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0833bau) { target=s->pc; goto dispatch; }
goto P_0c0833ba;
P_0c0833b8: /* original e410, guest PC 0x0c0833b8 */
if(!s->budget--) { s->failed_pc=0x0c0833b8u; return 0; }
r[4]=0x00000010u;
goto P_0c0833ba;
P_0c0833ba: /* original a008, guest PC 0x0c0833ba */
if(!s->budget--) { s->failed_pc=0x0c0833bau; return 0; }
goto P_0c0833ce;
P_0c0833bc: /* original 0009, guest PC 0x0c0833bc */
if(!s->budget--) { s->failed_pc=0x0c0833bcu; return 0; }
goto P_0c0833be;
P_0c0833be: /* original d339, guest PC 0x0c0833be */
if(!s->budget--) { s->failed_pc=0x0c0833beu; return 0; }
r[3]=read(ram,0x0c0834a4u,4);
goto P_0c0833c0;
P_0c0833c0: /* original 66d3, guest PC 0x0c0833c0 */
if(!s->budget--) { s->failed_pc=0x0c0833c0u; return 0; }
r[6]=r[13];
goto P_0c0833c2;
P_0c0833c2: /* original 65f2, guest PC 0x0c0833c2 */
if(!s->budget--) { s->failed_pc=0x0c0833c2u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0833c4;
P_0c0833c4: /* original 430b, guest PC 0x0c0833c4 */
if(!s->budget--) { s->failed_pc=0x0c0833c4u; return 0; }
target=r[3];
r[16]=code_base|0x0c0833c8u;
r[4]=0x00000010u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0833c8u) { target=s->pc; goto dispatch; }
goto P_0c0833c8;
P_0c0833c6: /* original e410, guest PC 0x0c0833c6 */
if(!s->budget--) { s->failed_pc=0x0c0833c6u; return 0; }
r[4]=0x00000010u;
goto P_0c0833c8;
P_0c0833c8: /* original 52f2, guest PC 0x0c0833c8 */
if(!s->budget--) { s->failed_pc=0x0c0833c8u; return 0; }
r[2]=read(ram,r[15]+8,4);
goto P_0c0833ca;
P_0c0833ca: /* original 2228, guest PC 0x0c0833ca */
if(!s->budget--) { s->failed_pc=0x0c0833cau; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c0833cc;
P_0c0833cc: /* original 8905, guest PC 0x0c0833cc */
if(!s->budget--) { s->failed_pc=0x0c0833ccu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0833da; }
goto P_0c0833ce;
P_0c0833ce: /* original 9d65, guest PC 0x0c0833ce */
if(!s->budget--) { s->failed_pc=0x0c0833ceu; return 0; }
r[13]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08349cu,2);
goto P_0c0833d0;
P_0c0833d0: /* original 65c3, guest PC 0x0c0833d0 */
if(!s->budget--) { s->failed_pc=0x0c0833d0u; return 0; }
r[5]=r[12];
goto P_0c0833d2;
P_0c0833d2: /* original d334, guest PC 0x0c0833d2 */
if(!s->budget--) { s->failed_pc=0x0c0833d2u; return 0; }
r[3]=read(ram,0x0c0834a4u,4);
goto P_0c0833d4;
P_0c0833d4: /* original 66d3, guest PC 0x0c0833d4 */
if(!s->budget--) { s->failed_pc=0x0c0833d4u; return 0; }
r[6]=r[13];
goto P_0c0833d6;
P_0c0833d6: /* original 430b, guest PC 0x0c0833d6 */
if(!s->budget--) { s->failed_pc=0x0c0833d6u; return 0; }
target=r[3];
r[16]=code_base|0x0c0833dau;
r[4]=0x00000014u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0833dau) { target=s->pc; goto dispatch; }
goto P_0c0833da;
P_0c0833d8: /* original e414, guest PC 0x0c0833d8 */
if(!s->budget--) { s->failed_pc=0x0c0833d8u; return 0; }
r[4]=0x00000014u;
goto P_0c0833da;
P_0c0833da: /* original 6383, guest PC 0x0c0833da */
if(!s->budget--) { s->failed_pc=0x0c0833dau; return 0; }
r[3]=r[8];
goto P_0c0833dc;
P_0c0833dc: /* original 7311, guest PC 0x0c0833dc */
if(!s->budget--) { s->failed_pc=0x0c0833dcu; return 0; }
r[3]+=0x00000011u;
goto P_0c0833de;
P_0c0833de: /* original 60a3, guest PC 0x0c0833de */
if(!s->budget--) { s->failed_pc=0x0c0833deu; return 0; }
r[0]=r[10];
goto P_0c0833e0;
P_0c0833e0: /* original 4008, guest PC 0x0c0833e0 */
if(!s->budget--) { s->failed_pc=0x0c0833e0u; return 0; }
r[0]<<=2;
goto P_0c0833e2;
P_0c0833e2: /* original 6283, guest PC 0x0c0833e2 */
if(!s->budget--) { s->failed_pc=0x0c0833e2u; return 0; }
r[2]=r[8];
goto P_0c0833e4;
P_0c0833e4: /* original 6ca3, guest PC 0x0c0833e4 */
if(!s->budget--) { s->failed_pc=0x0c0833e4u; return 0; }
r[12]=r[10];
goto P_0c0833e6;
P_0c0833e6: /* original 6d83, guest PC 0x0c0833e6 */
if(!s->budget--) { s->failed_pc=0x0c0833e6u; return 0; }
r[13]=r[8];
goto P_0c0833e8;
P_0c0833e8: /* original 7d0a, guest PC 0x0c0833e8 */
if(!s->budget--) { s->failed_pc=0x0c0833e8u; return 0; }
r[13]+=0x0000000au;
goto P_0c0833ea;
P_0c0833ea: /* original 4c08, guest PC 0x0c0833ea */
if(!s->budget--) { s->failed_pc=0x0c0833eau; return 0; }
r[12]<<=2;
goto P_0c0833ec;
P_0c0833ec: /* original 1fd2, guest PC 0x0c0833ec */
if(!s->budget--) { s->failed_pc=0x0c0833ecu; return 0; }
write(ram,r[15]+8,r[13],4);
goto P_0c0833ee;
P_0c0833ee: /* original 2f32, guest PC 0x0c0833ee */
if(!s->budget--) { s->failed_pc=0x0c0833eeu; return 0; }
write(ram,r[15],r[3],4);
goto P_0c0833f0;
P_0c0833f0: /* original 720f, guest PC 0x0c0833f0 */
if(!s->budget--) { s->failed_pc=0x0c0833f0u; return 0; }
r[2]+=0x0000000fu;
goto P_0c0833f2;
P_0c0833f2: /* original 4c08, guest PC 0x0c0833f2 */
if(!s->budget--) { s->failed_pc=0x0c0833f2u; return 0; }
r[12]<<=2;
goto P_0c0833f4;
P_0c0833f4: /* original 1f21, guest PC 0x0c0833f4 */
if(!s->budget--) { s->failed_pc=0x0c0833f4u; return 0; }
write(ram,r[15]+4,r[2],4);
goto P_0c0833f6;
P_0c0833f6: /* original 934d, guest PC 0x0c0833f6 */
if(!s->budget--) { s->failed_pc=0x0c0833f6u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c083494u,2);
goto P_0c0833f8;
P_0c0833f8: /* original 33ec, guest PC 0x0c0833f8 */
if(!s->budget--) { s->failed_pc=0x0c0833f8u; return 0; }
r[3]+=r[14];
goto P_0c0833fa;
P_0c0833fa: /* original 003e, guest PC 0x0c0833fa */
if(!s->budget--) { s->failed_pc=0x0c0833fau; return 0; }
r[0]=read(ram,r[3]+r[0],4);
goto P_0c0833fc;
P_0c0833fc: /* original 8801, guest PC 0x0c0833fc */
if(!s->budget--) { s->failed_pc=0x0c0833fcu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c0833fe;
P_0c0833fe: /* original 8f57, guest PC 0x0c0833fe */
if(!s->budget--) { s->failed_pc=0x0c0833feu; return 0; }
cond=r[17]&1u;
r[12]<<=2;
if(!cond) { goto P_0c0834b0; }
goto P_0c083402;
P_0c083400: /* original 4c08, guest PC 0x0c083400 */
if(!s->budget--) { s->failed_pc=0x0c083400u; return 0; }
r[12]<<=2;
goto P_0c083402;
P_0c083402: /* original 9349, guest PC 0x0c083402 */
if(!s->budget--) { s->failed_pc=0x0c083402u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c083498u,2);
goto P_0c083404;
P_0c083404: /* original 60a3, guest PC 0x0c083404 */
if(!s->budget--) { s->failed_pc=0x0c083404u; return 0; }
r[0]=r[10];
goto P_0c083406;
P_0c083406: /* original 4008, guest PC 0x0c083406 */
if(!s->budget--) { s->failed_pc=0x0c083406u; return 0; }
r[0]<<=2;
goto P_0c083408;
P_0c083408: /* original 33ec, guest PC 0x0c083408 */
if(!s->budget--) { s->failed_pc=0x0c083408u; return 0; }
r[3]+=r[14];
goto P_0c08340a;
P_0c08340a: /* original 003e, guest PC 0x0c08340a */
if(!s->budget--) { s->failed_pc=0x0c08340au; return 0; }
r[0]=read(ram,r[3]+r[0],4);
goto P_0c08340c;
P_0c08340c: /* original 8801, guest PC 0x0c08340c */
if(!s->budget--) { s->failed_pc=0x0c08340cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c08340e;
P_0c08340e: /* original 8b20, guest PC 0x0c08340e */
if(!s->budget--) { s->failed_pc=0x0c08340eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c083452; }
goto P_0c083410;
P_0c083410: /* original d324, guest PC 0x0c083410 */
if(!s->budget--) { s->failed_pc=0x0c083410u; return 0; }
r[3]=read(ram,0x0c0834a4u,4);
goto P_0c083412;
P_0c083412: /* original 65d3, guest PC 0x0c083412 */
if(!s->budget--) { s->failed_pc=0x0c083412u; return 0; }
r[5]=r[13];
goto P_0c083414;
P_0c083414: /* original 9643, guest PC 0x0c083414 */
if(!s->budget--) { s->failed_pc=0x0c083414u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08349eu,2);
goto P_0c083416;
P_0c083416: /* original 430b, guest PC 0x0c083416 */
if(!s->budget--) { s->failed_pc=0x0c083416u; return 0; }
target=r[3];
r[16]=code_base|0x0c08341au;
r[4]=0x00000012u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08341au) { target=s->pc; goto dispatch; }
goto P_0c08341a;
P_0c083418: /* original e412, guest PC 0x0c083418 */
if(!s->budget--) { s->failed_pc=0x0c083418u; return 0; }
r[4]=0x00000012u;
goto P_0c08341a;
P_0c08341a: /* original 9641, guest PC 0x0c08341a */
if(!s->budget--) { s->failed_pc=0x0c08341au; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0834a0u,2);
goto P_0c08341c;
P_0c08341c: /* original 65d3, guest PC 0x0c08341c */
if(!s->budget--) { s->failed_pc=0x0c08341cu; return 0; }
r[5]=r[13];
goto P_0c08341e;
P_0c08341e: /* original d322, guest PC 0x0c08341e */
if(!s->budget--) { s->failed_pc=0x0c08341eu; return 0; }
r[3]=read(ram,0x0c0834a8u,4);
goto P_0c083420;
P_0c083420: /* original 36ec, guest PC 0x0c083420 */
if(!s->budget--) { s->failed_pc=0x0c083420u; return 0; }
r[6]+=r[14];
goto P_0c083422;
P_0c083422: /* original 36cc, guest PC 0x0c083422 */
if(!s->budget--) { s->failed_pc=0x0c083422u; return 0; }
r[6]+=r[12];
goto P_0c083424;
P_0c083424: /* original 5661, guest PC 0x0c083424 */
if(!s->budget--) { s->failed_pc=0x0c083424u; return 0; }
r[6]=read(ram,r[6]+4,4);
goto P_0c083426;
P_0c083426: /* original 430b, guest PC 0x0c083426 */
if(!s->budget--) { s->failed_pc=0x0c083426u; return 0; }
target=r[3];
r[16]=code_base|0x0c08342au;
r[4]=0x00000014u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08342au) { target=s->pc; goto dispatch; }
goto P_0c08342a;
P_0c083428: /* original e414, guest PC 0x0c083428 */
if(!s->budget--) { s->failed_pc=0x0c083428u; return 0; }
r[4]=0x00000014u;
goto P_0c08342a;
P_0c08342a: /* original 6292, guest PC 0x0c08342a */
if(!s->budget--) { s->failed_pc=0x0c08342au; return 0; }
tmp=read(ram,r[9],4);
r[2]=tmp;
goto P_0c08342c;
P_0c08342c: /* original 32b0, guest PC 0x0c08342c */
if(!s->budget--) { s->failed_pc=0x0c08342cu; return 0; }
r[17]=(r[17]&~1u)|((r[2]==r[11])!=0);
goto P_0c08342e;
P_0c08342e: /* original 8f06, guest PC 0x0c08342e */
if(!s->budget--) { s->failed_pc=0x0c08342eu; return 0; }
cond=r[17]&1u;
r[4]=0x0000002du;
if(!cond) { goto P_0c08343e; }
goto P_0c083432;
P_0c083430: /* original e42d, guest PC 0x0c083430 */
if(!s->budget--) { s->failed_pc=0x0c083430u; return 0; }
r[4]=0x0000002du;
goto P_0c083432;
P_0c083432: /* original 9635, guest PC 0x0c083432 */
if(!s->budget--) { s->failed_pc=0x0c083432u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0834a0u,2);
goto P_0c083434;
P_0c083434: /* original 36ec, guest PC 0x0c083434 */
if(!s->budget--) { s->failed_pc=0x0c083434u; return 0; }
r[6]+=r[14];
goto P_0c083436;
P_0c083436: /* original 36cc, guest PC 0x0c083436 */
if(!s->budget--) { s->failed_pc=0x0c083436u; return 0; }
r[6]+=r[12];
goto P_0c083438;
P_0c083438: /* original 5661, guest PC 0x0c083438 */
if(!s->budget--) { s->failed_pc=0x0c083438u; return 0; }
r[6]=read(ram,r[6]+4,4);
goto P_0c08343a;
P_0c08343a: /* original a005, guest PC 0x0c08343a */
if(!s->budget--) { s->failed_pc=0x0c08343au; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c083448;
P_0c08343c: /* original 65f2, guest PC 0x0c08343c */
if(!s->budget--) { s->failed_pc=0x0c08343cu; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c08343e;
P_0c08343e: /* original 962f, guest PC 0x0c08343e */
if(!s->budget--) { s->failed_pc=0x0c08343eu; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0834a0u,2);
goto P_0c083440;
P_0c083440: /* original 55f1, guest PC 0x0c083440 */
if(!s->budget--) { s->failed_pc=0x0c083440u; return 0; }
r[5]=read(ram,r[15]+4,4);
goto P_0c083442;
P_0c083442: /* original 36ec, guest PC 0x0c083442 */
if(!s->budget--) { s->failed_pc=0x0c083442u; return 0; }
r[6]+=r[14];
goto P_0c083444;
P_0c083444: /* original 36cc, guest PC 0x0c083444 */
if(!s->budget--) { s->failed_pc=0x0c083444u; return 0; }
r[6]+=r[12];
goto P_0c083446;
P_0c083446: /* original 5661, guest PC 0x0c083446 */
if(!s->budget--) { s->failed_pc=0x0c083446u; return 0; }
r[6]=read(ram,r[6]+4,4);
goto P_0c083448;
P_0c083448: /* original d317, guest PC 0x0c083448 */
if(!s->budget--) { s->failed_pc=0x0c083448u; return 0; }
r[3]=read(ram,0x0c0834a8u,4);
goto P_0c08344a;
P_0c08344a: /* original 430b, guest PC 0x0c08344a */
if(!s->budget--) { s->failed_pc=0x0c08344au; return 0; }
target=r[3];
r[16]=code_base|0x0c08344eu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08344eu) { target=s->pc; goto dispatch; }
goto P_0c08344e;
P_0c08344c: /* original 0009, guest PC 0x0c08344c */
if(!s->budget--) { s->failed_pc=0x0c08344cu; return 0; }
goto P_0c08344e;
P_0c08344e: /* original a045, guest PC 0x0c08344e */
if(!s->budget--) { s->failed_pc=0x0c08344eu; return 0; }
goto P_0c0834dc;
P_0c083450: /* original 0009, guest PC 0x0c083450 */
if(!s->budget--) { s->failed_pc=0x0c083450u; return 0; }
goto P_0c083452;
P_0c083452: /* original d314, guest PC 0x0c083452 */
if(!s->budget--) { s->failed_pc=0x0c083452u; return 0; }
r[3]=read(ram,0x0c0834a4u,4);
goto P_0c083454;
P_0c083454: /* original 65d3, guest PC 0x0c083454 */
if(!s->budget--) { s->failed_pc=0x0c083454u; return 0; }
r[5]=r[13];
goto P_0c083456;
P_0c083456: /* original 9624, guest PC 0x0c083456 */
if(!s->budget--) { s->failed_pc=0x0c083456u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0834a2u,2);
goto P_0c083458;
P_0c083458: /* original 430b, guest PC 0x0c083458 */
if(!s->budget--) { s->failed_pc=0x0c083458u; return 0; }
target=r[3];
r[16]=code_base|0x0c08345cu;
r[4]=0x00000012u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08345cu) { target=s->pc; goto dispatch; }
goto P_0c08345c;
P_0c08345a: /* original e412, guest PC 0x0c08345a */
if(!s->budget--) { s->failed_pc=0x0c08345au; return 0; }
r[4]=0x00000012u;
goto P_0c08345c;
P_0c08345c: /* original 9620, guest PC 0x0c08345c */
if(!s->budget--) { s->failed_pc=0x0c08345cu; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0834a0u,2);
goto P_0c08345e;
P_0c08345e: /* original 65d3, guest PC 0x0c08345e */
if(!s->budget--) { s->failed_pc=0x0c08345eu; return 0; }
r[5]=r[13];
goto P_0c083460;
P_0c083460: /* original d312, guest PC 0x0c083460 */
if(!s->budget--) { s->failed_pc=0x0c083460u; return 0; }
r[3]=read(ram,0x0c0834acu,4);
goto P_0c083462;
P_0c083462: /* original 36ec, guest PC 0x0c083462 */
if(!s->budget--) { s->failed_pc=0x0c083462u; return 0; }
r[6]+=r[14];
goto P_0c083464;
P_0c083464: /* original 36cc, guest PC 0x0c083464 */
if(!s->budget--) { s->failed_pc=0x0c083464u; return 0; }
r[6]+=r[12];
goto P_0c083466;
P_0c083466: /* original 5661, guest PC 0x0c083466 */
if(!s->budget--) { s->failed_pc=0x0c083466u; return 0; }
r[6]=read(ram,r[6]+4,4);
goto P_0c083468;
P_0c083468: /* original 430b, guest PC 0x0c083468 */
if(!s->budget--) { s->failed_pc=0x0c083468u; return 0; }
target=r[3];
r[16]=code_base|0x0c08346cu;
r[4]=0x00000014u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08346cu) { target=s->pc; goto dispatch; }
goto P_0c08346c;
P_0c08346a: /* original e414, guest PC 0x0c08346a */
if(!s->budget--) { s->failed_pc=0x0c08346au; return 0; }
r[4]=0x00000014u;
goto P_0c08346c;
P_0c08346c: /* original 6292, guest PC 0x0c08346c */
if(!s->budget--) { s->failed_pc=0x0c08346cu; return 0; }
tmp=read(ram,r[9],4);
r[2]=tmp;
goto P_0c08346e;
P_0c08346e: /* original 32b0, guest PC 0x0c08346e */
if(!s->budget--) { s->failed_pc=0x0c08346eu; return 0; }
r[17]=(r[17]&~1u)|((r[2]==r[11])!=0);
goto P_0c083470;
P_0c083470: /* original 8f06, guest PC 0x0c083470 */
if(!s->budget--) { s->failed_pc=0x0c083470u; return 0; }
cond=r[17]&1u;
r[4]=0x0000002du;
if(!cond) { goto P_0c083480; }
goto P_0c083474;
P_0c083472: /* original e42d, guest PC 0x0c083472 */
if(!s->budget--) { s->failed_pc=0x0c083472u; return 0; }
r[4]=0x0000002du;
goto P_0c083474;
P_0c083474: /* original 9614, guest PC 0x0c083474 */
if(!s->budget--) { s->failed_pc=0x0c083474u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0834a0u,2);
goto P_0c083476;
P_0c083476: /* original 36ec, guest PC 0x0c083476 */
if(!s->budget--) { s->failed_pc=0x0c083476u; return 0; }
r[6]+=r[14];
goto P_0c083478;
P_0c083478: /* original 36cc, guest PC 0x0c083478 */
if(!s->budget--) { s->failed_pc=0x0c083478u; return 0; }
r[6]+=r[12];
goto P_0c08347a;
P_0c08347a: /* original 5661, guest PC 0x0c08347a */
if(!s->budget--) { s->failed_pc=0x0c08347au; return 0; }
r[6]=read(ram,r[6]+4,4);
goto P_0c08347c;
P_0c08347c: /* original a005, guest PC 0x0c08347c */
if(!s->budget--) { s->failed_pc=0x0c08347cu; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c08348a;
P_0c08347e: /* original 65f2, guest PC 0x0c08347e */
if(!s->budget--) { s->failed_pc=0x0c08347eu; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c083480;
P_0c083480: /* original 960e, guest PC 0x0c083480 */
if(!s->budget--) { s->failed_pc=0x0c083480u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0834a0u,2);
goto P_0c083482;
P_0c083482: /* original 55f1, guest PC 0x0c083482 */
if(!s->budget--) { s->failed_pc=0x0c083482u; return 0; }
r[5]=read(ram,r[15]+4,4);
goto P_0c083484;
P_0c083484: /* original 36ec, guest PC 0x0c083484 */
if(!s->budget--) { s->failed_pc=0x0c083484u; return 0; }
r[6]+=r[14];
goto P_0c083486;
P_0c083486: /* original 36cc, guest PC 0x0c083486 */
if(!s->budget--) { s->failed_pc=0x0c083486u; return 0; }
r[6]+=r[12];
goto P_0c083488;
P_0c083488: /* original 5661, guest PC 0x0c083488 */
if(!s->budget--) { s->failed_pc=0x0c083488u; return 0; }
r[6]=read(ram,r[6]+4,4);
goto P_0c08348a;
P_0c08348a: /* original d308, guest PC 0x0c08348a */
if(!s->budget--) { s->failed_pc=0x0c08348au; return 0; }
r[3]=read(ram,0x0c0834acu,4);
goto P_0c08348c;
P_0c08348c: /* original 430b, guest PC 0x0c08348c */
if(!s->budget--) { s->failed_pc=0x0c08348cu; return 0; }
target=r[3];
r[16]=code_base|0x0c083490u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c083490u) { target=s->pc; goto dispatch; }
goto P_0c083490;
P_0c08348e: /* original 0009, guest PC 0x0c08348e */
if(!s->budget--) { s->failed_pc=0x0c08348eu; return 0; }
goto P_0c083490;
P_0c083490: /* original a024, guest PC 0x0c083490 */
if(!s->budget--) { s->failed_pc=0x0c083490u; return 0; }
goto P_0c0834dc;
P_0c083492: /* original 0009, guest PC 0x0c083492 */
if(!s->budget--) { s->failed_pc=0x0c083492u; return 0; }
if(!vf3_matrix_family(0x0c083494u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c083494u; return 0; } return 1;
P_0c0834b0: /* original d341, guest PC 0x0c0834b0 */
if(!s->budget--) { s->failed_pc=0x0c0834b0u; return 0; }
r[3]=read(ram,0x0c0835b8u,4);
goto P_0c0834b2;
P_0c0834b2: /* original 65d3, guest PC 0x0c0834b2 */
if(!s->budget--) { s->failed_pc=0x0c0834b2u; return 0; }
r[5]=r[13];
goto P_0c0834b4;
P_0c0834b4: /* original 9679, guest PC 0x0c0834b4 */
if(!s->budget--) { s->failed_pc=0x0c0834b4u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0835aau,2);
goto P_0c0834b6;
P_0c0834b6: /* original 430b, guest PC 0x0c0834b6 */
if(!s->budget--) { s->failed_pc=0x0c0834b6u; return 0; }
target=r[3];
r[16]=code_base|0x0c0834bau;
r[4]=0x00000012u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0834bau) { target=s->pc; goto dispatch; }
goto P_0c0834ba;
P_0c0834b8: /* original e412, guest PC 0x0c0834b8 */
if(!s->budget--) { s->failed_pc=0x0c0834b8u; return 0; }
r[4]=0x00000012u;
goto P_0c0834ba;
P_0c0834ba: /* original d240, guest PC 0x0c0834ba */
if(!s->budget--) { s->failed_pc=0x0c0834bau; return 0; }
r[2]=read(ram,0x0c0835bcu,4);
goto P_0c0834bc;
P_0c0834bc: /* original 65d3, guest PC 0x0c0834bc */
if(!s->budget--) { s->failed_pc=0x0c0834bcu; return 0; }
r[5]=r[13];
goto P_0c0834be;
P_0c0834be: /* original e604, guest PC 0x0c0834be */
if(!s->budget--) { s->failed_pc=0x0c0834beu; return 0; }
r[6]=0x00000004u;
goto P_0c0834c0;
P_0c0834c0: /* original 420b, guest PC 0x0c0834c0 */
if(!s->budget--) { s->failed_pc=0x0c0834c0u; return 0; }
target=r[2];
r[16]=code_base|0x0c0834c4u;
r[4]=0x00000007u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0834c4u) { target=s->pc; goto dispatch; }
goto P_0c0834c4;
P_0c0834c2: /* original e407, guest PC 0x0c0834c2 */
if(!s->budget--) { s->failed_pc=0x0c0834c2u; return 0; }
r[4]=0x00000007u;
goto P_0c0834c4;
P_0c0834c4: /* original 6392, guest PC 0x0c0834c4 */
if(!s->budget--) { s->failed_pc=0x0c0834c4u; return 0; }
tmp=read(ram,r[9],4);
r[3]=tmp;
goto P_0c0834c6;
P_0c0834c6: /* original 33b0, guest PC 0x0c0834c6 */
if(!s->budget--) { s->failed_pc=0x0c0834c6u; return 0; }
r[17]=(r[17]&~1u)|((r[3]==r[11])!=0);
goto P_0c0834c8;
P_0c0834c8: /* original 8f03, guest PC 0x0c0834c8 */
if(!s->budget--) { s->failed_pc=0x0c0834c8u; return 0; }
cond=r[17]&1u;
r[4]=0x0000002du;
if(!cond) { goto P_0c0834d2; }
goto P_0c0834cc;
P_0c0834ca: /* original e42d, guest PC 0x0c0834ca */
if(!s->budget--) { s->failed_pc=0x0c0834cau; return 0; }
r[4]=0x0000002du;
goto P_0c0834cc;
P_0c0834cc: /* original e604, guest PC 0x0c0834cc */
if(!s->budget--) { s->failed_pc=0x0c0834ccu; return 0; }
r[6]=0x00000004u;
goto P_0c0834ce;
P_0c0834ce: /* original a002, guest PC 0x0c0834ce */
if(!s->budget--) { s->failed_pc=0x0c0834ceu; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0834d6;
P_0c0834d0: /* original 65f2, guest PC 0x0c0834d0 */
if(!s->budget--) { s->failed_pc=0x0c0834d0u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0834d2;
P_0c0834d2: /* original 55f1, guest PC 0x0c0834d2 */
if(!s->budget--) { s->failed_pc=0x0c0834d2u; return 0; }
r[5]=read(ram,r[15]+4,4);
goto P_0c0834d4;
P_0c0834d4: /* original e604, guest PC 0x0c0834d4 */
if(!s->budget--) { s->failed_pc=0x0c0834d4u; return 0; }
r[6]=0x00000004u;
goto P_0c0834d6;
P_0c0834d6: /* original d339, guest PC 0x0c0834d6 */
if(!s->budget--) { s->failed_pc=0x0c0834d6u; return 0; }
r[3]=read(ram,0x0c0835bcu,4);
goto P_0c0834d8;
P_0c0834d8: /* original 430b, guest PC 0x0c0834d8 */
if(!s->budget--) { s->failed_pc=0x0c0834d8u; return 0; }
target=r[3];
r[16]=code_base|0x0c0834dcu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0834dcu) { target=s->pc; goto dispatch; }
goto P_0c0834dc;
P_0c0834da: /* original 0009, guest PC 0x0c0834da */
if(!s->budget--) { s->failed_pc=0x0c0834dau; return 0; }
goto P_0c0834dc;
P_0c0834dc: /* original 60a3, guest PC 0x0c0834dc */
if(!s->budget--) { s->failed_pc=0x0c0834dcu; return 0; }
r[0]=r[10];
goto P_0c0834de;
P_0c0834de: /* original 4008, guest PC 0x0c0834de */
if(!s->budget--) { s->failed_pc=0x0c0834deu; return 0; }
r[0]<<=2;
goto P_0c0834e0;
P_0c0834e0: /* original 6283, guest PC 0x0c0834e0 */
if(!s->budget--) { s->failed_pc=0x0c0834e0u; return 0; }
r[2]=r[8];
goto P_0c0834e2;
P_0c0834e2: /* original 720d, guest PC 0x0c0834e2 */
if(!s->budget--) { s->failed_pc=0x0c0834e2u; return 0; }
r[2]+=0x0000000du;
goto P_0c0834e4;
P_0c0834e4: /* original 2f22, guest PC 0x0c0834e4 */
if(!s->budget--) { s->failed_pc=0x0c0834e4u; return 0; }
write(ram,r[15],r[2],4);
goto P_0c0834e6;
P_0c0834e6: /* original 9361, guest PC 0x0c0834e6 */
if(!s->budget--) { s->failed_pc=0x0c0834e6u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0835acu,2);
goto P_0c0834e8;
P_0c0834e8: /* original 33ec, guest PC 0x0c0834e8 */
if(!s->budget--) { s->failed_pc=0x0c0834e8u; return 0; }
r[3]+=r[14];
goto P_0c0834ea;
P_0c0834ea: /* original 003e, guest PC 0x0c0834ea */
if(!s->budget--) { s->failed_pc=0x0c0834eau; return 0; }
r[0]=read(ram,r[3]+r[0],4);
goto P_0c0834ec;
P_0c0834ec: /* original 8801, guest PC 0x0c0834ec */
if(!s->budget--) { s->failed_pc=0x0c0834ecu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c0834ee;
P_0c0834ee: /* original 8f4b, guest PC 0x0c0834ee */
if(!s->budget--) { s->failed_pc=0x0c0834eeu; return 0; }
cond=r[17]&1u;
r[13]+=0x00000002u;
if(!cond) { goto P_0c083588; }
goto P_0c0834f2;
P_0c0834f0: /* original 7d02, guest PC 0x0c0834f0 */
if(!s->budget--) { s->failed_pc=0x0c0834f0u; return 0; }
r[13]+=0x00000002u;
goto P_0c0834f2;
P_0c0834f2: /* original 935c, guest PC 0x0c0834f2 */
if(!s->budget--) { s->failed_pc=0x0c0834f2u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0835aeu,2);
goto P_0c0834f4;
P_0c0834f4: /* original 60a3, guest PC 0x0c0834f4 */
if(!s->budget--) { s->failed_pc=0x0c0834f4u; return 0; }
r[0]=r[10];
goto P_0c0834f6;
P_0c0834f6: /* original 4008, guest PC 0x0c0834f6 */
if(!s->budget--) { s->failed_pc=0x0c0834f6u; return 0; }
r[0]<<=2;
goto P_0c0834f8;
P_0c0834f8: /* original 33ec, guest PC 0x0c0834f8 */
if(!s->budget--) { s->failed_pc=0x0c0834f8u; return 0; }
r[3]+=r[14];
goto P_0c0834fa;
P_0c0834fa: /* original 003e, guest PC 0x0c0834fa */
if(!s->budget--) { s->failed_pc=0x0c0834fau; return 0; }
r[0]=read(ram,r[3]+r[0],4);
goto P_0c0834fc;
P_0c0834fc: /* original 8802, guest PC 0x0c0834fc */
if(!s->budget--) { s->failed_pc=0x0c0834fcu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c0834fe;
P_0c0834fe: /* original 8b21, guest PC 0x0c0834fe */
if(!s->budget--) { s->failed_pc=0x0c0834feu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c083544; }
goto P_0c083500;
P_0c083500: /* original d32d, guest PC 0x0c083500 */
if(!s->budget--) { s->failed_pc=0x0c083500u; return 0; }
r[3]=read(ram,0x0c0835b8u,4);
goto P_0c083502;
P_0c083502: /* original 65d3, guest PC 0x0c083502 */
if(!s->budget--) { s->failed_pc=0x0c083502u; return 0; }
r[5]=r[13];
goto P_0c083504;
P_0c083504: /* original 9654, guest PC 0x0c083504 */
if(!s->budget--) { s->failed_pc=0x0c083504u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0835b0u,2);
goto P_0c083506;
P_0c083506: /* original 430b, guest PC 0x0c083506 */
if(!s->budget--) { s->failed_pc=0x0c083506u; return 0; }
target=r[3];
r[16]=code_base|0x0c08350au;
r[4]=0x00000012u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08350au) { target=s->pc; goto dispatch; }
goto P_0c08350a;
P_0c083508: /* original e412, guest PC 0x0c083508 */
if(!s->budget--) { s->failed_pc=0x0c083508u; return 0; }
r[4]=0x00000012u;
goto P_0c08350a;
P_0c08350a: /* original 9652, guest PC 0x0c08350a */
if(!s->budget--) { s->failed_pc=0x0c08350au; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0835b2u,2);
goto P_0c08350c;
P_0c08350c: /* original 65d3, guest PC 0x0c08350c */
if(!s->budget--) { s->failed_pc=0x0c08350cu; return 0; }
r[5]=r[13];
goto P_0c08350e;
P_0c08350e: /* original d32c, guest PC 0x0c08350e */
if(!s->budget--) { s->failed_pc=0x0c08350eu; return 0; }
r[3]=read(ram,0x0c0835c0u,4);
goto P_0c083510;
P_0c083510: /* original 36ec, guest PC 0x0c083510 */
if(!s->budget--) { s->failed_pc=0x0c083510u; return 0; }
r[6]+=r[14];
goto P_0c083512;
P_0c083512: /* original 36cc, guest PC 0x0c083512 */
if(!s->budget--) { s->failed_pc=0x0c083512u; return 0; }
r[6]+=r[12];
goto P_0c083514;
P_0c083514: /* original 5662, guest PC 0x0c083514 */
if(!s->budget--) { s->failed_pc=0x0c083514u; return 0; }
r[6]=read(ram,r[6]+8,4);
goto P_0c083516;
P_0c083516: /* original 430b, guest PC 0x0c083516 */
if(!s->budget--) { s->failed_pc=0x0c083516u; return 0; }
target=r[3];
r[16]=code_base|0x0c08351au;
r[4]=0x00000014u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08351au) { target=s->pc; goto dispatch; }
goto P_0c08351a;
P_0c083518: /* original e414, guest PC 0x0c083518 */
if(!s->budget--) { s->failed_pc=0x0c083518u; return 0; }
r[4]=0x00000014u;
goto P_0c08351a;
P_0c08351a: /* original 6292, guest PC 0x0c08351a */
if(!s->budget--) { s->failed_pc=0x0c08351au; return 0; }
tmp=read(ram,r[9],4);
r[2]=tmp;
goto P_0c08351c;
P_0c08351c: /* original 32b0, guest PC 0x0c08351c */
if(!s->budget--) { s->failed_pc=0x0c08351cu; return 0; }
r[17]=(r[17]&~1u)|((r[2]==r[11])!=0);
goto P_0c08351e;
P_0c08351e: /* original 8b06, guest PC 0x0c08351e */
if(!s->budget--) { s->failed_pc=0x0c08351eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c08352e; }
goto P_0c083520;
P_0c083520: /* original 9647, guest PC 0x0c083520 */
if(!s->budget--) { s->failed_pc=0x0c083520u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0835b2u,2);
goto P_0c083522;
P_0c083522: /* original 55f1, guest PC 0x0c083522 */
if(!s->budget--) { s->failed_pc=0x0c083522u; return 0; }
r[5]=read(ram,r[15]+4,4);
goto P_0c083524;
P_0c083524: /* original 36ec, guest PC 0x0c083524 */
if(!s->budget--) { s->failed_pc=0x0c083524u; return 0; }
r[6]+=r[14];
goto P_0c083526;
P_0c083526: /* original 36cc, guest PC 0x0c083526 */
if(!s->budget--) { s->failed_pc=0x0c083526u; return 0; }
r[6]+=r[12];
goto P_0c083528;
P_0c083528: /* original 5662, guest PC 0x0c083528 */
if(!s->budget--) { s->failed_pc=0x0c083528u; return 0; }
r[6]=read(ram,r[6]+8,4);
goto P_0c08352a;
P_0c08352a: /* original a006, guest PC 0x0c08352a */
if(!s->budget--) { s->failed_pc=0x0c08352au; return 0; }
r[4]=0x00000030u;
goto P_0c08353a;
P_0c08352c: /* original e430, guest PC 0x0c08352c */
if(!s->budget--) { s->failed_pc=0x0c08352cu; return 0; }
r[4]=0x00000030u;
goto P_0c08352e;
P_0c08352e: /* original 9640, guest PC 0x0c08352e */
if(!s->budget--) { s->failed_pc=0x0c08352eu; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0835b2u,2);
goto P_0c083530;
P_0c083530: /* original e433, guest PC 0x0c083530 */
if(!s->budget--) { s->failed_pc=0x0c083530u; return 0; }
r[4]=0x00000033u;
goto P_0c083532;
P_0c083532: /* original 65f2, guest PC 0x0c083532 */
if(!s->budget--) { s->failed_pc=0x0c083532u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c083534;
P_0c083534: /* original 36ec, guest PC 0x0c083534 */
if(!s->budget--) { s->failed_pc=0x0c083534u; return 0; }
r[6]+=r[14];
goto P_0c083536;
P_0c083536: /* original 36cc, guest PC 0x0c083536 */
if(!s->budget--) { s->failed_pc=0x0c083536u; return 0; }
r[6]+=r[12];
goto P_0c083538;
P_0c083538: /* original 5662, guest PC 0x0c083538 */
if(!s->budget--) { s->failed_pc=0x0c083538u; return 0; }
r[6]=read(ram,r[6]+8,4);
goto P_0c08353a;
P_0c08353a: /* original d321, guest PC 0x0c08353a */
if(!s->budget--) { s->failed_pc=0x0c08353au; return 0; }
r[3]=read(ram,0x0c0835c0u,4);
goto P_0c08353c;
P_0c08353c: /* original 430b, guest PC 0x0c08353c */
if(!s->budget--) { s->failed_pc=0x0c08353cu; return 0; }
target=r[3];
r[16]=code_base|0x0c083540u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c083540u) { target=s->pc; goto dispatch; }
goto P_0c083540;
P_0c08353e: /* original 0009, guest PC 0x0c08353e */
if(!s->budget--) { s->failed_pc=0x0c08353eu; return 0; }
goto P_0c083540;
P_0c083540: /* original a046, guest PC 0x0c083540 */
if(!s->budget--) { s->failed_pc=0x0c083540u; return 0; }
goto P_0c0835d0;
P_0c083542: /* original 0009, guest PC 0x0c083542 */
if(!s->budget--) { s->failed_pc=0x0c083542u; return 0; }
goto P_0c083544;
P_0c083544: /* original d31c, guest PC 0x0c083544 */
if(!s->budget--) { s->failed_pc=0x0c083544u; return 0; }
r[3]=read(ram,0x0c0835b8u,4);
goto P_0c083546;
P_0c083546: /* original 65d3, guest PC 0x0c083546 */
if(!s->budget--) { s->failed_pc=0x0c083546u; return 0; }
r[5]=r[13];
goto P_0c083548;
P_0c083548: /* original 9634, guest PC 0x0c083548 */
if(!s->budget--) { s->failed_pc=0x0c083548u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0835b4u,2);
goto P_0c08354a;
P_0c08354a: /* original 430b, guest PC 0x0c08354a */
if(!s->budget--) { s->failed_pc=0x0c08354au; return 0; }
target=r[3];
r[16]=code_base|0x0c08354eu;
r[4]=0x00000012u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08354eu) { target=s->pc; goto dispatch; }
goto P_0c08354e;
P_0c08354c: /* original e412, guest PC 0x0c08354c */
if(!s->budget--) { s->failed_pc=0x0c08354cu; return 0; }
r[4]=0x00000012u;
goto P_0c08354e;
P_0c08354e: /* original 9630, guest PC 0x0c08354e */
if(!s->budget--) { s->failed_pc=0x0c08354eu; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0835b2u,2);
goto P_0c083550;
P_0c083550: /* original 65d3, guest PC 0x0c083550 */
if(!s->budget--) { s->failed_pc=0x0c083550u; return 0; }
r[5]=r[13];
goto P_0c083552;
P_0c083552: /* original d31a, guest PC 0x0c083552 */
if(!s->budget--) { s->failed_pc=0x0c083552u; return 0; }
r[3]=read(ram,0x0c0835bcu,4);
goto P_0c083554;
P_0c083554: /* original 36ec, guest PC 0x0c083554 */
if(!s->budget--) { s->failed_pc=0x0c083554u; return 0; }
r[6]+=r[14];
goto P_0c083556;
P_0c083556: /* original 36cc, guest PC 0x0c083556 */
if(!s->budget--) { s->failed_pc=0x0c083556u; return 0; }
r[6]+=r[12];
goto P_0c083558;
P_0c083558: /* original 5662, guest PC 0x0c083558 */
if(!s->budget--) { s->failed_pc=0x0c083558u; return 0; }
r[6]=read(ram,r[6]+8,4);
goto P_0c08355a;
P_0c08355a: /* original 430b, guest PC 0x0c08355a */
if(!s->budget--) { s->failed_pc=0x0c08355au; return 0; }
target=r[3];
r[16]=code_base|0x0c08355eu;
r[4]=0x00000014u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08355eu) { target=s->pc; goto dispatch; }
goto P_0c08355e;
P_0c08355c: /* original e414, guest PC 0x0c08355c */
if(!s->budget--) { s->failed_pc=0x0c08355cu; return 0; }
r[4]=0x00000014u;
goto P_0c08355e;
P_0c08355e: /* original 6292, guest PC 0x0c08355e */
if(!s->budget--) { s->failed_pc=0x0c08355eu; return 0; }
tmp=read(ram,r[9],4);
r[2]=tmp;
goto P_0c083560;
P_0c083560: /* original 32b0, guest PC 0x0c083560 */
if(!s->budget--) { s->failed_pc=0x0c083560u; return 0; }
r[17]=(r[17]&~1u)|((r[2]==r[11])!=0);
goto P_0c083562;
P_0c083562: /* original 8b06, guest PC 0x0c083562 */
if(!s->budget--) { s->failed_pc=0x0c083562u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c083572; }
goto P_0c083564;
P_0c083564: /* original 9625, guest PC 0x0c083564 */
if(!s->budget--) { s->failed_pc=0x0c083564u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0835b2u,2);
goto P_0c083566;
P_0c083566: /* original 55f1, guest PC 0x0c083566 */
if(!s->budget--) { s->failed_pc=0x0c083566u; return 0; }
r[5]=read(ram,r[15]+4,4);
goto P_0c083568;
P_0c083568: /* original 36ec, guest PC 0x0c083568 */
if(!s->budget--) { s->failed_pc=0x0c083568u; return 0; }
r[6]+=r[14];
goto P_0c08356a;
P_0c08356a: /* original 36cc, guest PC 0x0c08356a */
if(!s->budget--) { s->failed_pc=0x0c08356au; return 0; }
r[6]+=r[12];
goto P_0c08356c;
P_0c08356c: /* original 5662, guest PC 0x0c08356c */
if(!s->budget--) { s->failed_pc=0x0c08356cu; return 0; }
r[6]=read(ram,r[6]+8,4);
goto P_0c08356e;
P_0c08356e: /* original a006, guest PC 0x0c08356e */
if(!s->budget--) { s->failed_pc=0x0c08356eu; return 0; }
r[4]=0x00000030u;
goto P_0c08357e;
P_0c083570: /* original e430, guest PC 0x0c083570 */
if(!s->budget--) { s->failed_pc=0x0c083570u; return 0; }
r[4]=0x00000030u;
goto P_0c083572;
P_0c083572: /* original 961e, guest PC 0x0c083572 */
if(!s->budget--) { s->failed_pc=0x0c083572u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0835b2u,2);
goto P_0c083574;
P_0c083574: /* original e433, guest PC 0x0c083574 */
if(!s->budget--) { s->failed_pc=0x0c083574u; return 0; }
r[4]=0x00000033u;
goto P_0c083576;
P_0c083576: /* original 65f2, guest PC 0x0c083576 */
if(!s->budget--) { s->failed_pc=0x0c083576u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c083578;
P_0c083578: /* original 36ec, guest PC 0x0c083578 */
if(!s->budget--) { s->failed_pc=0x0c083578u; return 0; }
r[6]+=r[14];
goto P_0c08357a;
P_0c08357a: /* original 36cc, guest PC 0x0c08357a */
if(!s->budget--) { s->failed_pc=0x0c08357au; return 0; }
r[6]+=r[12];
goto P_0c08357c;
P_0c08357c: /* original 5662, guest PC 0x0c08357c */
if(!s->budget--) { s->failed_pc=0x0c08357cu; return 0; }
r[6]=read(ram,r[6]+8,4);
goto P_0c08357e;
P_0c08357e: /* original d30f, guest PC 0x0c08357e */
if(!s->budget--) { s->failed_pc=0x0c08357eu; return 0; }
r[3]=read(ram,0x0c0835bcu,4);
goto P_0c083580;
P_0c083580: /* original 430b, guest PC 0x0c083580 */
if(!s->budget--) { s->failed_pc=0x0c083580u; return 0; }
target=r[3];
r[16]=code_base|0x0c083584u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c083584u) { target=s->pc; goto dispatch; }
goto P_0c083584;
P_0c083582: /* original 0009, guest PC 0x0c083582 */
if(!s->budget--) { s->failed_pc=0x0c083582u; return 0; }
goto P_0c083584;
P_0c083584: /* original a024, guest PC 0x0c083584 */
if(!s->budget--) { s->failed_pc=0x0c083584u; return 0; }
goto P_0c0835d0;
P_0c083586: /* original 0009, guest PC 0x0c083586 */
if(!s->budget--) { s->failed_pc=0x0c083586u; return 0; }
goto P_0c083588;
P_0c083588: /* original d30b, guest PC 0x0c083588 */
if(!s->budget--) { s->failed_pc=0x0c083588u; return 0; }
r[3]=read(ram,0x0c0835b8u,4);
goto P_0c08358a;
P_0c08358a: /* original 65d3, guest PC 0x0c08358a */
if(!s->budget--) { s->failed_pc=0x0c08358au; return 0; }
r[5]=r[13];
goto P_0c08358c;
P_0c08358c: /* original 9612, guest PC 0x0c08358c */
if(!s->budget--) { s->failed_pc=0x0c08358cu; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0835b4u,2);
goto P_0c08358e;
P_0c08358e: /* original 430b, guest PC 0x0c08358e */
if(!s->budget--) { s->failed_pc=0x0c08358eu; return 0; }
target=r[3];
r[16]=code_base|0x0c083592u;
r[4]=0x00000012u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c083592u) { target=s->pc; goto dispatch; }
goto P_0c083592;
P_0c083590: /* original e412, guest PC 0x0c083590 */
if(!s->budget--) { s->failed_pc=0x0c083590u; return 0; }
r[4]=0x00000012u;
goto P_0c083592;
P_0c083592: /* original d20a, guest PC 0x0c083592 */
if(!s->budget--) { s->failed_pc=0x0c083592u; return 0; }
r[2]=read(ram,0x0c0835bcu,4);
goto P_0c083594;
P_0c083594: /* original 65d3, guest PC 0x0c083594 */
if(!s->budget--) { s->failed_pc=0x0c083594u; return 0; }
r[5]=r[13];
goto P_0c083596;
P_0c083596: /* original e608, guest PC 0x0c083596 */
if(!s->budget--) { s->failed_pc=0x0c083596u; return 0; }
r[6]=0x00000008u;
goto P_0c083598;
P_0c083598: /* original 420b, guest PC 0x0c083598 */
if(!s->budget--) { s->failed_pc=0x0c083598u; return 0; }
target=r[2];
r[16]=code_base|0x0c08359cu;
r[4]=0x00000007u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08359cu) { target=s->pc; goto dispatch; }
goto P_0c08359c;
P_0c08359a: /* original e407, guest PC 0x0c08359a */
if(!s->budget--) { s->failed_pc=0x0c08359au; return 0; }
r[4]=0x00000007u;
goto P_0c08359c;
P_0c08359c: /* original 6392, guest PC 0x0c08359c */
if(!s->budget--) { s->failed_pc=0x0c08359cu; return 0; }
tmp=read(ram,r[9],4);
r[3]=tmp;
goto P_0c08359e;
P_0c08359e: /* original 33b0, guest PC 0x0c08359e */
if(!s->budget--) { s->failed_pc=0x0c08359eu; return 0; }
r[17]=(r[17]&~1u)|((r[3]==r[11])!=0);
goto P_0c0835a0;
P_0c0835a0: /* original 8b10, guest PC 0x0c0835a0 */
if(!s->budget--) { s->failed_pc=0x0c0835a0u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0835c4; }
goto P_0c0835a2;
P_0c0835a2: /* original 55f1, guest PC 0x0c0835a2 */
if(!s->budget--) { s->failed_pc=0x0c0835a2u; return 0; }
r[5]=read(ram,r[15]+4,4);
goto P_0c0835a4;
P_0c0835a4: /* original e608, guest PC 0x0c0835a4 */
if(!s->budget--) { s->failed_pc=0x0c0835a4u; return 0; }
r[6]=0x00000008u;
goto P_0c0835a6;
P_0c0835a6: /* original a010, guest PC 0x0c0835a6 */
if(!s->budget--) { s->failed_pc=0x0c0835a6u; return 0; }
r[4]=0x00000030u;
goto P_0c0835ca;
P_0c0835a8: /* original e430, guest PC 0x0c0835a8 */
if(!s->budget--) { s->failed_pc=0x0c0835a8u; return 0; }
r[4]=0x00000030u;
if(!vf3_matrix_family(0x0c0835aau,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0835aau; return 0; } return 1;
P_0c0835c4: /* original 65f2, guest PC 0x0c0835c4 */
if(!s->budget--) { s->failed_pc=0x0c0835c4u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0835c6;
P_0c0835c6: /* original e433, guest PC 0x0c0835c6 */
if(!s->budget--) { s->failed_pc=0x0c0835c6u; return 0; }
r[4]=0x00000033u;
goto P_0c0835c8;
P_0c0835c8: /* original e608, guest PC 0x0c0835c8 */
if(!s->budget--) { s->failed_pc=0x0c0835c8u; return 0; }
r[6]=0x00000008u;
goto P_0c0835ca;
P_0c0835ca: /* original d346, guest PC 0x0c0835ca */
if(!s->budget--) { s->failed_pc=0x0c0835cau; return 0; }
r[3]=read(ram,0x0c0836e4u,4);
goto P_0c0835cc;
P_0c0835cc: /* original 430b, guest PC 0x0c0835cc */
if(!s->budget--) { s->failed_pc=0x0c0835ccu; return 0; }
target=r[3];
r[16]=code_base|0x0c0835d0u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0835d0u) { target=s->pc; goto dispatch; }
goto P_0c0835d0;
P_0c0835ce: /* original 0009, guest PC 0x0c0835ce */
if(!s->budget--) { s->failed_pc=0x0c0835ceu; return 0; }
goto P_0c0835d0;
P_0c0835d0: /* original 6292, guest PC 0x0c0835d0 */
if(!s->budget--) { s->failed_pc=0x0c0835d0u; return 0; }
tmp=read(ram,r[9],4);
r[2]=tmp;
goto P_0c0835d2;
P_0c0835d2: /* original 32b0, guest PC 0x0c0835d2 */
if(!s->budget--) { s->failed_pc=0x0c0835d2u; return 0; }
r[17]=(r[17]&~1u)|((r[2]==r[11])!=0);
goto P_0c0835d4;
P_0c0835d4: /* original 8b4b, guest PC 0x0c0835d4 */
if(!s->budget--) { s->failed_pc=0x0c0835d4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c08366e; }
goto P_0c0835d6;
P_0c0835d6: /* original 937e, guest PC 0x0c0835d6 */
if(!s->budget--) { s->failed_pc=0x0c0835d6u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0836d6u,2);
goto P_0c0835d8;
P_0c0835d8: /* original 60a3, guest PC 0x0c0835d8 */
if(!s->budget--) { s->failed_pc=0x0c0835d8u; return 0; }
r[0]=r[10];
goto P_0c0835da;
P_0c0835da: /* original 4008, guest PC 0x0c0835da */
if(!s->budget--) { s->failed_pc=0x0c0835dau; return 0; }
r[0]<<=2;
goto P_0c0835dc;
P_0c0835dc: /* original 33ec, guest PC 0x0c0835dc */
if(!s->budget--) { s->failed_pc=0x0c0835dcu; return 0; }
r[3]+=r[14];
goto P_0c0835de;
P_0c0835de: /* original 003e, guest PC 0x0c0835de */
if(!s->budget--) { s->failed_pc=0x0c0835deu; return 0; }
r[0]=read(ram,r[3]+r[0],4);
goto P_0c0835e0;
P_0c0835e0: /* original 8801, guest PC 0x0c0835e0 */
if(!s->budget--) { s->failed_pc=0x0c0835e0u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c0835e2;
P_0c0835e2: /* original 8f35, guest PC 0x0c0835e2 */
if(!s->budget--) { s->failed_pc=0x0c0835e2u; return 0; }
cond=r[17]&1u;
r[13]+=0x00000002u;
if(!cond) { goto P_0c083650; }
goto P_0c0835e6;
P_0c0835e4: /* original 7d02, guest PC 0x0c0835e4 */
if(!s->budget--) { s->failed_pc=0x0c0835e4u; return 0; }
r[13]+=0x00000002u;
goto P_0c0835e6;
P_0c0835e6: /* original 9377, guest PC 0x0c0835e6 */
if(!s->budget--) { s->failed_pc=0x0c0835e6u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0836d8u,2);
goto P_0c0835e8;
P_0c0835e8: /* original 60a3, guest PC 0x0c0835e8 */
if(!s->budget--) { s->failed_pc=0x0c0835e8u; return 0; }
r[0]=r[10];
goto P_0c0835ea;
P_0c0835ea: /* original 4008, guest PC 0x0c0835ea */
if(!s->budget--) { s->failed_pc=0x0c0835eau; return 0; }
r[0]<<=2;
goto P_0c0835ec;
P_0c0835ec: /* original 33ec, guest PC 0x0c0835ec */
if(!s->budget--) { s->failed_pc=0x0c0835ecu; return 0; }
r[3]+=r[14];
goto P_0c0835ee;
P_0c0835ee: /* original 003e, guest PC 0x0c0835ee */
if(!s->budget--) { s->failed_pc=0x0c0835eeu; return 0; }
r[0]=read(ram,r[3]+r[0],4);
goto P_0c0835f0;
P_0c0835f0: /* original 8803, guest PC 0x0c0835f0 */
if(!s->budget--) { s->failed_pc=0x0c0835f0u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000003u)!=0);
goto P_0c0835f2;
P_0c0835f2: /* original 8b16, guest PC 0x0c0835f2 */
if(!s->budget--) { s->failed_pc=0x0c0835f2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c083622; }
goto P_0c0835f4;
P_0c0835f4: /* original d33c, guest PC 0x0c0835f4 */
if(!s->budget--) { s->failed_pc=0x0c0835f4u; return 0; }
r[3]=read(ram,0x0c0836e8u,4);
goto P_0c0835f6;
P_0c0835f6: /* original 65d3, guest PC 0x0c0835f6 */
if(!s->budget--) { s->failed_pc=0x0c0835f6u; return 0; }
r[5]=r[13];
goto P_0c0835f8;
P_0c0835f8: /* original 966f, guest PC 0x0c0835f8 */
if(!s->budget--) { s->failed_pc=0x0c0835f8u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0836dau,2);
goto P_0c0835fa;
P_0c0835fa: /* original 430b, guest PC 0x0c0835fa */
if(!s->budget--) { s->failed_pc=0x0c0835fau; return 0; }
target=r[3];
r[16]=code_base|0x0c0835feu;
r[4]=0x00000012u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0835feu) { target=s->pc; goto dispatch; }
goto P_0c0835fe;
P_0c0835fc: /* original e412, guest PC 0x0c0835fc */
if(!s->budget--) { s->failed_pc=0x0c0835fcu; return 0; }
r[4]=0x00000012u;
goto P_0c0835fe;
P_0c0835fe: /* original 966d, guest PC 0x0c0835fe */
if(!s->budget--) { s->failed_pc=0x0c0835feu; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0836dcu,2);
goto P_0c083600;
P_0c083600: /* original 65d3, guest PC 0x0c083600 */
if(!s->budget--) { s->failed_pc=0x0c083600u; return 0; }
r[5]=r[13];
goto P_0c083602;
P_0c083602: /* original d33a, guest PC 0x0c083602 */
if(!s->budget--) { s->failed_pc=0x0c083602u; return 0; }
r[3]=read(ram,0x0c0836ecu,4);
goto P_0c083604;
P_0c083604: /* original 36ec, guest PC 0x0c083604 */
if(!s->budget--) { s->failed_pc=0x0c083604u; return 0; }
r[6]+=r[14];
goto P_0c083606;
P_0c083606: /* original 36cc, guest PC 0x0c083606 */
if(!s->budget--) { s->failed_pc=0x0c083606u; return 0; }
r[6]+=r[12];
goto P_0c083608;
P_0c083608: /* original 5663, guest PC 0x0c083608 */
if(!s->budget--) { s->failed_pc=0x0c083608u; return 0; }
r[6]=read(ram,r[6]+12,4);
goto P_0c08360a;
P_0c08360a: /* original 430b, guest PC 0x0c08360a */
if(!s->budget--) { s->failed_pc=0x0c08360au; return 0; }
target=r[3];
r[16]=code_base|0x0c08360eu;
r[4]=0x00000014u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08360eu) { target=s->pc; goto dispatch; }
goto P_0c08360e;
P_0c08360c: /* original e414, guest PC 0x0c08360c */
if(!s->budget--) { s->failed_pc=0x0c08360cu; return 0; }
r[4]=0x00000014u;
goto P_0c08360e;
P_0c08360e: /* original 9665, guest PC 0x0c08360e */
if(!s->budget--) { s->failed_pc=0x0c08360eu; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0836dcu,2);
goto P_0c083610;
P_0c083610: /* original d336, guest PC 0x0c083610 */
if(!s->budget--) { s->failed_pc=0x0c083610u; return 0; }
r[3]=read(ram,0x0c0836ecu,4);
goto P_0c083612;
P_0c083612: /* original 36ec, guest PC 0x0c083612 */
if(!s->budget--) { s->failed_pc=0x0c083612u; return 0; }
r[6]+=r[14];
goto P_0c083614;
P_0c083614: /* original 65f2, guest PC 0x0c083614 */
if(!s->budget--) { s->failed_pc=0x0c083614u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c083616;
P_0c083616: /* original 36cc, guest PC 0x0c083616 */
if(!s->budget--) { s->failed_pc=0x0c083616u; return 0; }
r[6]+=r[12];
goto P_0c083618;
P_0c083618: /* original 5663, guest PC 0x0c083618 */
if(!s->budget--) { s->failed_pc=0x0c083618u; return 0; }
r[6]=read(ram,r[6]+12,4);
goto P_0c08361a;
P_0c08361a: /* original 430b, guest PC 0x0c08361a */
if(!s->budget--) { s->failed_pc=0x0c08361au; return 0; }
target=r[3];
r[16]=code_base|0x0c08361eu;
r[4]=0x00000034u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08361eu) { target=s->pc; goto dispatch; }
goto P_0c08361e;
P_0c08361c: /* original e434, guest PC 0x0c08361c */
if(!s->budget--) { s->failed_pc=0x0c08361cu; return 0; }
r[4]=0x00000034u;
goto P_0c08361e;
P_0c08361e: /* original a026, guest PC 0x0c08361e */
if(!s->budget--) { s->failed_pc=0x0c08361eu; return 0; }
goto P_0c08366e;
P_0c083620: /* original 0009, guest PC 0x0c083620 */
if(!s->budget--) { s->failed_pc=0x0c083620u; return 0; }
goto P_0c083622;
P_0c083622: /* original d331, guest PC 0x0c083622 */
if(!s->budget--) { s->failed_pc=0x0c083622u; return 0; }
r[3]=read(ram,0x0c0836e8u,4);
goto P_0c083624;
P_0c083624: /* original 65d3, guest PC 0x0c083624 */
if(!s->budget--) { s->failed_pc=0x0c083624u; return 0; }
r[5]=r[13];
goto P_0c083626;
P_0c083626: /* original 965a, guest PC 0x0c083626 */
if(!s->budget--) { s->failed_pc=0x0c083626u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0836deu,2);
goto P_0c083628;
P_0c083628: /* original 430b, guest PC 0x0c083628 */
if(!s->budget--) { s->failed_pc=0x0c083628u; return 0; }
target=r[3];
r[16]=code_base|0x0c08362cu;
r[4]=0x00000012u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08362cu) { target=s->pc; goto dispatch; }
goto P_0c08362c;
P_0c08362a: /* original e412, guest PC 0x0c08362a */
if(!s->budget--) { s->failed_pc=0x0c08362au; return 0; }
r[4]=0x00000012u;
goto P_0c08362c;
P_0c08362c: /* original 9656, guest PC 0x0c08362c */
if(!s->budget--) { s->failed_pc=0x0c08362cu; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0836dcu,2);
goto P_0c08362e;
P_0c08362e: /* original 65d3, guest PC 0x0c08362e */
if(!s->budget--) { s->failed_pc=0x0c08362eu; return 0; }
r[5]=r[13];
goto P_0c083630;
P_0c083630: /* original d32c, guest PC 0x0c083630 */
if(!s->budget--) { s->failed_pc=0x0c083630u; return 0; }
r[3]=read(ram,0x0c0836e4u,4);
goto P_0c083632;
P_0c083632: /* original 36ec, guest PC 0x0c083632 */
if(!s->budget--) { s->failed_pc=0x0c083632u; return 0; }
r[6]+=r[14];
goto P_0c083634;
P_0c083634: /* original 36cc, guest PC 0x0c083634 */
if(!s->budget--) { s->failed_pc=0x0c083634u; return 0; }
r[6]+=r[12];
goto P_0c083636;
P_0c083636: /* original 5663, guest PC 0x0c083636 */
if(!s->budget--) { s->failed_pc=0x0c083636u; return 0; }
r[6]=read(ram,r[6]+12,4);
goto P_0c083638;
P_0c083638: /* original 430b, guest PC 0x0c083638 */
if(!s->budget--) { s->failed_pc=0x0c083638u; return 0; }
target=r[3];
r[16]=code_base|0x0c08363cu;
r[4]=0x00000014u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08363cu) { target=s->pc; goto dispatch; }
goto P_0c08363c;
P_0c08363a: /* original e414, guest PC 0x0c08363a */
if(!s->budget--) { s->failed_pc=0x0c08363au; return 0; }
r[4]=0x00000014u;
goto P_0c08363c;
P_0c08363c: /* original 964e, guest PC 0x0c08363c */
if(!s->budget--) { s->failed_pc=0x0c08363cu; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0836dcu,2);
goto P_0c08363e;
P_0c08363e: /* original d329, guest PC 0x0c08363e */
if(!s->budget--) { s->failed_pc=0x0c08363eu; return 0; }
r[3]=read(ram,0x0c0836e4u,4);
goto P_0c083640;
P_0c083640: /* original 36ec, guest PC 0x0c083640 */
if(!s->budget--) { s->failed_pc=0x0c083640u; return 0; }
r[6]+=r[14];
goto P_0c083642;
P_0c083642: /* original 65f2, guest PC 0x0c083642 */
if(!s->budget--) { s->failed_pc=0x0c083642u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c083644;
P_0c083644: /* original 36cc, guest PC 0x0c083644 */
if(!s->budget--) { s->failed_pc=0x0c083644u; return 0; }
r[6]+=r[12];
goto P_0c083646;
P_0c083646: /* original 5663, guest PC 0x0c083646 */
if(!s->budget--) { s->failed_pc=0x0c083646u; return 0; }
r[6]=read(ram,r[6]+12,4);
goto P_0c083648;
P_0c083648: /* original 430b, guest PC 0x0c083648 */
if(!s->budget--) { s->failed_pc=0x0c083648u; return 0; }
target=r[3];
r[16]=code_base|0x0c08364cu;
r[4]=0x00000034u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08364cu) { target=s->pc; goto dispatch; }
goto P_0c08364c;
P_0c08364a: /* original e434, guest PC 0x0c08364a */
if(!s->budget--) { s->failed_pc=0x0c08364au; return 0; }
r[4]=0x00000034u;
goto P_0c08364c;
P_0c08364c: /* original a00f, guest PC 0x0c08364c */
if(!s->budget--) { s->failed_pc=0x0c08364cu; return 0; }
goto P_0c08366e;
P_0c08364e: /* original 0009, guest PC 0x0c08364e */
if(!s->budget--) { s->failed_pc=0x0c08364eu; return 0; }
goto P_0c083650;
P_0c083650: /* original d325, guest PC 0x0c083650 */
if(!s->budget--) { s->failed_pc=0x0c083650u; return 0; }
r[3]=read(ram,0x0c0836e8u,4);
goto P_0c083652;
P_0c083652: /* original 65d3, guest PC 0x0c083652 */
if(!s->budget--) { s->failed_pc=0x0c083652u; return 0; }
r[5]=r[13];
goto P_0c083654;
P_0c083654: /* original 9643, guest PC 0x0c083654 */
if(!s->budget--) { s->failed_pc=0x0c083654u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0836deu,2);
goto P_0c083656;
P_0c083656: /* original 430b, guest PC 0x0c083656 */
if(!s->budget--) { s->failed_pc=0x0c083656u; return 0; }
target=r[3];
r[16]=code_base|0x0c08365au;
r[4]=0x00000012u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08365au) { target=s->pc; goto dispatch; }
goto P_0c08365a;
P_0c083658: /* original e412, guest PC 0x0c083658 */
if(!s->budget--) { s->failed_pc=0x0c083658u; return 0; }
r[4]=0x00000012u;
goto P_0c08365a;
P_0c08365a: /* original d222, guest PC 0x0c08365a */
if(!s->budget--) { s->failed_pc=0x0c08365au; return 0; }
r[2]=read(ram,0x0c0836e4u,4);
goto P_0c08365c;
P_0c08365c: /* original 65d3, guest PC 0x0c08365c */
if(!s->budget--) { s->failed_pc=0x0c08365cu; return 0; }
r[5]=r[13];
goto P_0c08365e;
P_0c08365e: /* original e610, guest PC 0x0c08365e */
if(!s->budget--) { s->failed_pc=0x0c08365eu; return 0; }
r[6]=0x00000010u;
goto P_0c083660;
P_0c083660: /* original 420b, guest PC 0x0c083660 */
if(!s->budget--) { s->failed_pc=0x0c083660u; return 0; }
target=r[2];
r[16]=code_base|0x0c083664u;
r[4]=0x00000007u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c083664u) { target=s->pc; goto dispatch; }
goto P_0c083664;
P_0c083662: /* original e407, guest PC 0x0c083662 */
if(!s->budget--) { s->failed_pc=0x0c083662u; return 0; }
r[4]=0x00000007u;
goto P_0c083664;
P_0c083664: /* original d31f, guest PC 0x0c083664 */
if(!s->budget--) { s->failed_pc=0x0c083664u; return 0; }
r[3]=read(ram,0x0c0836e4u,4);
goto P_0c083666;
P_0c083666: /* original e610, guest PC 0x0c083666 */
if(!s->budget--) { s->failed_pc=0x0c083666u; return 0; }
r[6]=0x00000010u;
goto P_0c083668;
P_0c083668: /* original 65f2, guest PC 0x0c083668 */
if(!s->budget--) { s->failed_pc=0x0c083668u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c08366a;
P_0c08366a: /* original 430b, guest PC 0x0c08366a */
if(!s->budget--) { s->failed_pc=0x0c08366au; return 0; }
target=r[3];
r[16]=code_base|0x0c08366eu;
r[4]=0x00000034u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08366eu) { target=s->pc; goto dispatch; }
goto P_0c08366e;
P_0c08366c: /* original e434, guest PC 0x0c08366c */
if(!s->budget--) { s->failed_pc=0x0c08366cu; return 0; }
r[4]=0x00000034u;
goto P_0c08366e;
P_0c08366e: /* original 60a3, guest PC 0x0c08366e */
if(!s->budget--) { s->failed_pc=0x0c08366eu; return 0; }
r[0]=r[10];
goto P_0c083670;
P_0c083670: /* original 4008, guest PC 0x0c083670 */
if(!s->budget--) { s->failed_pc=0x0c083670u; return 0; }
r[0]<<=2;
goto P_0c083672;
P_0c083672: /* original 6283, guest PC 0x0c083672 */
if(!s->budget--) { s->failed_pc=0x0c083672u; return 0; }
r[2]=r[8];
goto P_0c083674;
P_0c083674: /* original 720c, guest PC 0x0c083674 */
if(!s->budget--) { s->failed_pc=0x0c083674u; return 0; }
r[2]+=0x0000000cu;
goto P_0c083676;
P_0c083676: /* original 1f21, guest PC 0x0c083676 */
if(!s->budget--) { s->failed_pc=0x0c083676u; return 0; }
write(ram,r[15]+4,r[2],4);
goto P_0c083678;
P_0c083678: /* original 932d, guest PC 0x0c083678 */
if(!s->budget--) { s->failed_pc=0x0c083678u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0836d6u,2);
goto P_0c08367a;
P_0c08367a: /* original 33ec, guest PC 0x0c08367a */
if(!s->budget--) { s->failed_pc=0x0c08367au; return 0; }
r[3]+=r[14];
goto P_0c08367c;
P_0c08367c: /* original 003e, guest PC 0x0c08367c */
if(!s->budget--) { s->failed_pc=0x0c08367cu; return 0; }
r[0]=read(ram,r[3]+r[0],4);
goto P_0c08367e;
P_0c08367e: /* original 8801, guest PC 0x0c08367e */
if(!s->budget--) { s->failed_pc=0x0c08367eu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c083680;
P_0c083680: /* original 8f58, guest PC 0x0c083680 */
if(!s->budget--) { s->failed_pc=0x0c083680u; return 0; }
cond=r[17]&1u;
r[13]+=0x00000002u;
if(!cond) { goto P_0c083734; }
goto P_0c083684;
P_0c083682: /* original 7d02, guest PC 0x0c083682 */
if(!s->budget--) { s->failed_pc=0x0c083682u; return 0; }
r[13]+=0x00000002u;
goto P_0c083684;
P_0c083684: /* original 9328, guest PC 0x0c083684 */
if(!s->budget--) { s->failed_pc=0x0c083684u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0836d8u,2);
goto P_0c083686;
P_0c083686: /* original 60a3, guest PC 0x0c083686 */
if(!s->budget--) { s->failed_pc=0x0c083686u; return 0; }
r[0]=r[10];
goto P_0c083688;
P_0c083688: /* original 4008, guest PC 0x0c083688 */
if(!s->budget--) { s->failed_pc=0x0c083688u; return 0; }
r[0]<<=2;
goto P_0c08368a;
P_0c08368a: /* original 33ec, guest PC 0x0c08368a */
if(!s->budget--) { s->failed_pc=0x0c08368au; return 0; }
r[3]+=r[14];
goto P_0c08368c;
P_0c08368c: /* original 003e, guest PC 0x0c08368c */
if(!s->budget--) { s->failed_pc=0x0c08368cu; return 0; }
r[0]=read(ram,r[3]+r[0],4);
goto P_0c08368e;
P_0c08368e: /* original 8804, guest PC 0x0c08368e */
if(!s->budget--) { s->failed_pc=0x0c08368eu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000004u)!=0);
goto P_0c083690;
P_0c083690: /* original 8b2e, guest PC 0x0c083690 */
if(!s->budget--) { s->failed_pc=0x0c083690u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0836f0; }
goto P_0c083692;
P_0c083692: /* original d315, guest PC 0x0c083692 */
if(!s->budget--) { s->failed_pc=0x0c083692u; return 0; }
r[3]=read(ram,0x0c0836e8u,4);
goto P_0c083694;
P_0c083694: /* original 65d3, guest PC 0x0c083694 */
if(!s->budget--) { s->failed_pc=0x0c083694u; return 0; }
r[5]=r[13];
goto P_0c083696;
P_0c083696: /* original 9623, guest PC 0x0c083696 */
if(!s->budget--) { s->failed_pc=0x0c083696u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0836e0u,2);
goto P_0c083698;
P_0c083698: /* original 430b, guest PC 0x0c083698 */
if(!s->budget--) { s->failed_pc=0x0c083698u; return 0; }
target=r[3];
r[16]=code_base|0x0c08369cu;
r[4]=0x00000012u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08369cu) { target=s->pc; goto dispatch; }
goto P_0c08369c;
P_0c08369a: /* original e412, guest PC 0x0c08369a */
if(!s->budget--) { s->failed_pc=0x0c08369au; return 0; }
r[4]=0x00000012u;
goto P_0c08369c;
P_0c08369c: /* original 961e, guest PC 0x0c08369c */
if(!s->budget--) { s->failed_pc=0x0c08369cu; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0836dcu,2);
goto P_0c08369e;
P_0c08369e: /* original 65d3, guest PC 0x0c08369e */
if(!s->budget--) { s->failed_pc=0x0c08369eu; return 0; }
r[5]=r[13];
goto P_0c0836a0;
P_0c0836a0: /* original d312, guest PC 0x0c0836a0 */
if(!s->budget--) { s->failed_pc=0x0c0836a0u; return 0; }
r[3]=read(ram,0x0c0836ecu,4);
goto P_0c0836a2;
P_0c0836a2: /* original 36ec, guest PC 0x0c0836a2 */
if(!s->budget--) { s->failed_pc=0x0c0836a2u; return 0; }
r[6]+=r[14];
goto P_0c0836a4;
P_0c0836a4: /* original 36cc, guest PC 0x0c0836a4 */
if(!s->budget--) { s->failed_pc=0x0c0836a4u; return 0; }
r[6]+=r[12];
goto P_0c0836a6;
P_0c0836a6: /* original 5664, guest PC 0x0c0836a6 */
if(!s->budget--) { s->failed_pc=0x0c0836a6u; return 0; }
r[6]=read(ram,r[6]+16,4);
goto P_0c0836a8;
P_0c0836a8: /* original 430b, guest PC 0x0c0836a8 */
if(!s->budget--) { s->failed_pc=0x0c0836a8u; return 0; }
target=r[3];
r[16]=code_base|0x0c0836acu;
r[4]=0x00000014u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0836acu) { target=s->pc; goto dispatch; }
goto P_0c0836ac;
P_0c0836aa: /* original e414, guest PC 0x0c0836aa */
if(!s->budget--) { s->failed_pc=0x0c0836aau; return 0; }
r[4]=0x00000014u;
goto P_0c0836ac;
P_0c0836ac: /* original 6292, guest PC 0x0c0836ac */
if(!s->budget--) { s->failed_pc=0x0c0836acu; return 0; }
tmp=read(ram,r[9],4);
r[2]=tmp;
goto P_0c0836ae;
P_0c0836ae: /* original 32b0, guest PC 0x0c0836ae */
if(!s->budget--) { s->failed_pc=0x0c0836aeu; return 0; }
r[17]=(r[17]&~1u)|((r[2]==r[11])!=0);
goto P_0c0836b0;
P_0c0836b0: /* original 8b06, guest PC 0x0c0836b0 */
if(!s->budget--) { s->failed_pc=0x0c0836b0u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0836c0; }
goto P_0c0836b2;
P_0c0836b2: /* original 9613, guest PC 0x0c0836b2 */
if(!s->budget--) { s->failed_pc=0x0c0836b2u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0836dcu,2);
goto P_0c0836b4;
P_0c0836b4: /* original 55f1, guest PC 0x0c0836b4 */
if(!s->budget--) { s->failed_pc=0x0c0836b4u; return 0; }
r[5]=read(ram,r[15]+4,4);
goto P_0c0836b6;
P_0c0836b6: /* original 36ec, guest PC 0x0c0836b6 */
if(!s->budget--) { s->failed_pc=0x0c0836b6u; return 0; }
r[6]+=r[14];
goto P_0c0836b8;
P_0c0836b8: /* original 36cc, guest PC 0x0c0836b8 */
if(!s->budget--) { s->failed_pc=0x0c0836b8u; return 0; }
r[6]+=r[12];
goto P_0c0836ba;
P_0c0836ba: /* original 5664, guest PC 0x0c0836ba */
if(!s->budget--) { s->failed_pc=0x0c0836bau; return 0; }
r[6]=read(ram,r[6]+16,4);
goto P_0c0836bc;
P_0c0836bc: /* original a006, guest PC 0x0c0836bc */
if(!s->budget--) { s->failed_pc=0x0c0836bcu; return 0; }
r[4]=0x00000027u;
goto P_0c0836cc;
P_0c0836be: /* original e427, guest PC 0x0c0836be */
if(!s->budget--) { s->failed_pc=0x0c0836beu; return 0; }
r[4]=0x00000027u;
goto P_0c0836c0;
P_0c0836c0: /* original 960c, guest PC 0x0c0836c0 */
if(!s->budget--) { s->failed_pc=0x0c0836c0u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0836dcu,2);
goto P_0c0836c2;
P_0c0836c2: /* original e428, guest PC 0x0c0836c2 */
if(!s->budget--) { s->failed_pc=0x0c0836c2u; return 0; }
r[4]=0x00000028u;
goto P_0c0836c4;
P_0c0836c4: /* original 65f2, guest PC 0x0c0836c4 */
if(!s->budget--) { s->failed_pc=0x0c0836c4u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0836c6;
P_0c0836c6: /* original 36ec, guest PC 0x0c0836c6 */
if(!s->budget--) { s->failed_pc=0x0c0836c6u; return 0; }
r[6]+=r[14];
goto P_0c0836c8;
P_0c0836c8: /* original 36cc, guest PC 0x0c0836c8 */
if(!s->budget--) { s->failed_pc=0x0c0836c8u; return 0; }
r[6]+=r[12];
goto P_0c0836ca;
P_0c0836ca: /* original 5664, guest PC 0x0c0836ca */
if(!s->budget--) { s->failed_pc=0x0c0836cau; return 0; }
r[6]=read(ram,r[6]+16,4);
goto P_0c0836cc;
P_0c0836cc: /* original d307, guest PC 0x0c0836cc */
if(!s->budget--) { s->failed_pc=0x0c0836ccu; return 0; }
r[3]=read(ram,0x0c0836ecu,4);
goto P_0c0836ce;
P_0c0836ce: /* original 430b, guest PC 0x0c0836ce */
if(!s->budget--) { s->failed_pc=0x0c0836ceu; return 0; }
target=r[3];
r[16]=code_base|0x0c0836d2u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0836d2u) { target=s->pc; goto dispatch; }
goto P_0c0836d2;
P_0c0836d0: /* original 0009, guest PC 0x0c0836d0 */
if(!s->budget--) { s->failed_pc=0x0c0836d0u; return 0; }
goto P_0c0836d2;
P_0c0836d2: /* original a046, guest PC 0x0c0836d2 */
if(!s->budget--) { s->failed_pc=0x0c0836d2u; return 0; }
goto P_0c083762;
P_0c0836d4: /* original 0009, guest PC 0x0c0836d4 */
if(!s->budget--) { s->failed_pc=0x0c0836d4u; return 0; }
if(!vf3_matrix_family(0x0c0836d6u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0836d6u; return 0; } return 1;
P_0c0836f0: /* original d343, guest PC 0x0c0836f0 */
if(!s->budget--) { s->failed_pc=0x0c0836f0u; return 0; }
r[3]=read(ram,0x0c083800u,4);
goto P_0c0836f2;
P_0c0836f2: /* original 65d3, guest PC 0x0c0836f2 */
if(!s->budget--) { s->failed_pc=0x0c0836f2u; return 0; }
r[5]=r[13];
goto P_0c0836f4;
P_0c0836f4: /* original 967d, guest PC 0x0c0836f4 */
if(!s->budget--) { s->failed_pc=0x0c0836f4u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0837f2u,2);
goto P_0c0836f6;
P_0c0836f6: /* original 430b, guest PC 0x0c0836f6 */
if(!s->budget--) { s->failed_pc=0x0c0836f6u; return 0; }
target=r[3];
r[16]=code_base|0x0c0836fau;
r[4]=0x00000012u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0836fau) { target=s->pc; goto dispatch; }
goto P_0c0836fa;
P_0c0836f8: /* original e412, guest PC 0x0c0836f8 */
if(!s->budget--) { s->failed_pc=0x0c0836f8u; return 0; }
r[4]=0x00000012u;
goto P_0c0836fa;
P_0c0836fa: /* original 967b, guest PC 0x0c0836fa */
if(!s->budget--) { s->failed_pc=0x0c0836fau; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0837f4u,2);
goto P_0c0836fc;
P_0c0836fc: /* original 65d3, guest PC 0x0c0836fc */
if(!s->budget--) { s->failed_pc=0x0c0836fcu; return 0; }
r[5]=r[13];
goto P_0c0836fe;
P_0c0836fe: /* original d341, guest PC 0x0c0836fe */
if(!s->budget--) { s->failed_pc=0x0c0836feu; return 0; }
r[3]=read(ram,0x0c083804u,4);
goto P_0c083700;
P_0c083700: /* original 36ec, guest PC 0x0c083700 */
if(!s->budget--) { s->failed_pc=0x0c083700u; return 0; }
r[6]+=r[14];
goto P_0c083702;
P_0c083702: /* original 36cc, guest PC 0x0c083702 */
if(!s->budget--) { s->failed_pc=0x0c083702u; return 0; }
r[6]+=r[12];
goto P_0c083704;
P_0c083704: /* original 5664, guest PC 0x0c083704 */
if(!s->budget--) { s->failed_pc=0x0c083704u; return 0; }
r[6]=read(ram,r[6]+16,4);
goto P_0c083706;
P_0c083706: /* original 430b, guest PC 0x0c083706 */
if(!s->budget--) { s->failed_pc=0x0c083706u; return 0; }
target=r[3];
r[16]=code_base|0x0c08370au;
r[4]=0x00000014u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08370au) { target=s->pc; goto dispatch; }
goto P_0c08370a;
P_0c083708: /* original e414, guest PC 0x0c083708 */
if(!s->budget--) { s->failed_pc=0x0c083708u; return 0; }
r[4]=0x00000014u;
goto P_0c08370a;
P_0c08370a: /* original 6292, guest PC 0x0c08370a */
if(!s->budget--) { s->failed_pc=0x0c08370au; return 0; }
tmp=read(ram,r[9],4);
r[2]=tmp;
goto P_0c08370c;
P_0c08370c: /* original 32b0, guest PC 0x0c08370c */
if(!s->budget--) { s->failed_pc=0x0c08370cu; return 0; }
r[17]=(r[17]&~1u)|((r[2]==r[11])!=0);
goto P_0c08370e;
P_0c08370e: /* original 8b06, guest PC 0x0c08370e */
if(!s->budget--) { s->failed_pc=0x0c08370eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c08371e; }
goto P_0c083710;
P_0c083710: /* original 9670, guest PC 0x0c083710 */
if(!s->budget--) { s->failed_pc=0x0c083710u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0837f4u,2);
goto P_0c083712;
P_0c083712: /* original 55f1, guest PC 0x0c083712 */
if(!s->budget--) { s->failed_pc=0x0c083712u; return 0; }
r[5]=read(ram,r[15]+4,4);
goto P_0c083714;
P_0c083714: /* original 36ec, guest PC 0x0c083714 */
if(!s->budget--) { s->failed_pc=0x0c083714u; return 0; }
r[6]+=r[14];
goto P_0c083716;
P_0c083716: /* original 36cc, guest PC 0x0c083716 */
if(!s->budget--) { s->failed_pc=0x0c083716u; return 0; }
r[6]+=r[12];
goto P_0c083718;
P_0c083718: /* original 5664, guest PC 0x0c083718 */
if(!s->budget--) { s->failed_pc=0x0c083718u; return 0; }
r[6]=read(ram,r[6]+16,4);
goto P_0c08371a;
P_0c08371a: /* original a006, guest PC 0x0c08371a */
if(!s->budget--) { s->failed_pc=0x0c08371au; return 0; }
r[4]=0x00000027u;
goto P_0c08372a;
P_0c08371c: /* original e427, guest PC 0x0c08371c */
if(!s->budget--) { s->failed_pc=0x0c08371cu; return 0; }
r[4]=0x00000027u;
goto P_0c08371e;
P_0c08371e: /* original 9669, guest PC 0x0c08371e */
if(!s->budget--) { s->failed_pc=0x0c08371eu; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0837f4u,2);
goto P_0c083720;
P_0c083720: /* original e428, guest PC 0x0c083720 */
if(!s->budget--) { s->failed_pc=0x0c083720u; return 0; }
r[4]=0x00000028u;
goto P_0c083722;
P_0c083722: /* original 65f2, guest PC 0x0c083722 */
if(!s->budget--) { s->failed_pc=0x0c083722u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c083724;
P_0c083724: /* original 36ec, guest PC 0x0c083724 */
if(!s->budget--) { s->failed_pc=0x0c083724u; return 0; }
r[6]+=r[14];
goto P_0c083726;
P_0c083726: /* original 36cc, guest PC 0x0c083726 */
if(!s->budget--) { s->failed_pc=0x0c083726u; return 0; }
r[6]+=r[12];
goto P_0c083728;
P_0c083728: /* original 5664, guest PC 0x0c083728 */
if(!s->budget--) { s->failed_pc=0x0c083728u; return 0; }
r[6]=read(ram,r[6]+16,4);
goto P_0c08372a;
P_0c08372a: /* original d336, guest PC 0x0c08372a */
if(!s->budget--) { s->failed_pc=0x0c08372au; return 0; }
r[3]=read(ram,0x0c083804u,4);
goto P_0c08372c;
P_0c08372c: /* original 430b, guest PC 0x0c08372c */
if(!s->budget--) { s->failed_pc=0x0c08372cu; return 0; }
target=r[3];
r[16]=code_base|0x0c083730u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c083730u) { target=s->pc; goto dispatch; }
goto P_0c083730;
P_0c08372e: /* original 0009, guest PC 0x0c08372e */
if(!s->budget--) { s->failed_pc=0x0c08372eu; return 0; }
goto P_0c083730;
P_0c083730: /* original a017, guest PC 0x0c083730 */
if(!s->budget--) { s->failed_pc=0x0c083730u; return 0; }
goto P_0c083762;
P_0c083732: /* original 0009, guest PC 0x0c083732 */
if(!s->budget--) { s->failed_pc=0x0c083732u; return 0; }
goto P_0c083734;
P_0c083734: /* original d332, guest PC 0x0c083734 */
if(!s->budget--) { s->failed_pc=0x0c083734u; return 0; }
r[3]=read(ram,0x0c083800u,4);
goto P_0c083736;
P_0c083736: /* original 65d3, guest PC 0x0c083736 */
if(!s->budget--) { s->failed_pc=0x0c083736u; return 0; }
r[5]=r[13];
goto P_0c083738;
P_0c083738: /* original 965b, guest PC 0x0c083738 */
if(!s->budget--) { s->failed_pc=0x0c083738u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0837f2u,2);
goto P_0c08373a;
P_0c08373a: /* original 430b, guest PC 0x0c08373a */
if(!s->budget--) { s->failed_pc=0x0c08373au; return 0; }
target=r[3];
r[16]=code_base|0x0c08373eu;
r[4]=0x00000012u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08373eu) { target=s->pc; goto dispatch; }
goto P_0c08373e;
P_0c08373c: /* original e412, guest PC 0x0c08373c */
if(!s->budget--) { s->failed_pc=0x0c08373cu; return 0; }
r[4]=0x00000012u;
goto P_0c08373e;
P_0c08373e: /* original d231, guest PC 0x0c08373e */
if(!s->budget--) { s->failed_pc=0x0c08373eu; return 0; }
r[2]=read(ram,0x0c083804u,4);
goto P_0c083740;
P_0c083740: /* original 65d3, guest PC 0x0c083740 */
if(!s->budget--) { s->failed_pc=0x0c083740u; return 0; }
r[5]=r[13];
goto P_0c083742;
P_0c083742: /* original e601, guest PC 0x0c083742 */
if(!s->budget--) { s->failed_pc=0x0c083742u; return 0; }
r[6]=0x00000001u;
goto P_0c083744;
P_0c083744: /* original 420b, guest PC 0x0c083744 */
if(!s->budget--) { s->failed_pc=0x0c083744u; return 0; }
target=r[2];
r[16]=code_base|0x0c083748u;
r[4]=0x00000007u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c083748u) { target=s->pc; goto dispatch; }
goto P_0c083748;
P_0c083746: /* original e407, guest PC 0x0c083746 */
if(!s->budget--) { s->failed_pc=0x0c083746u; return 0; }
r[4]=0x00000007u;
goto P_0c083748;
P_0c083748: /* original 6392, guest PC 0x0c083748 */
if(!s->budget--) { s->failed_pc=0x0c083748u; return 0; }
tmp=read(ram,r[9],4);
r[3]=tmp;
goto P_0c08374a;
P_0c08374a: /* original 33b0, guest PC 0x0c08374a */
if(!s->budget--) { s->failed_pc=0x0c08374au; return 0; }
r[17]=(r[17]&~1u)|((r[3]==r[11])!=0);
goto P_0c08374c;
P_0c08374c: /* original 8b03, guest PC 0x0c08374c */
if(!s->budget--) { s->failed_pc=0x0c08374cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c083756; }
goto P_0c08374e;
P_0c08374e: /* original 55f1, guest PC 0x0c08374e */
if(!s->budget--) { s->failed_pc=0x0c08374eu; return 0; }
r[5]=read(ram,r[15]+4,4);
goto P_0c083750;
P_0c083750: /* original e601, guest PC 0x0c083750 */
if(!s->budget--) { s->failed_pc=0x0c083750u; return 0; }
r[6]=0x00000001u;
goto P_0c083752;
P_0c083752: /* original a003, guest PC 0x0c083752 */
if(!s->budget--) { s->failed_pc=0x0c083752u; return 0; }
r[4]=0x00000027u;
goto P_0c08375c;
P_0c083754: /* original e427, guest PC 0x0c083754 */
if(!s->budget--) { s->failed_pc=0x0c083754u; return 0; }
r[4]=0x00000027u;
goto P_0c083756;
P_0c083756: /* original 65f2, guest PC 0x0c083756 */
if(!s->budget--) { s->failed_pc=0x0c083756u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c083758;
P_0c083758: /* original e428, guest PC 0x0c083758 */
if(!s->budget--) { s->failed_pc=0x0c083758u; return 0; }
r[4]=0x00000028u;
goto P_0c08375a;
P_0c08375a: /* original e601, guest PC 0x0c08375a */
if(!s->budget--) { s->failed_pc=0x0c08375au; return 0; }
r[6]=0x00000001u;
goto P_0c08375c;
P_0c08375c: /* original d329, guest PC 0x0c08375c */
if(!s->budget--) { s->failed_pc=0x0c08375cu; return 0; }
r[3]=read(ram,0x0c083804u,4);
goto P_0c08375e;
P_0c08375e: /* original 430b, guest PC 0x0c08375e */
if(!s->budget--) { s->failed_pc=0x0c08375eu; return 0; }
target=r[3];
r[16]=code_base|0x0c083762u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c083762u) { target=s->pc; goto dispatch; }
goto P_0c083762;
P_0c083760: /* original 0009, guest PC 0x0c083760 */
if(!s->budget--) { s->failed_pc=0x0c083760u; return 0; }
goto P_0c083762;
P_0c083762: /* original 9348, guest PC 0x0c083762 */
if(!s->budget--) { s->failed_pc=0x0c083762u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0837f6u,2);
goto P_0c083764;
P_0c083764: /* original 60a3, guest PC 0x0c083764 */
if(!s->budget--) { s->failed_pc=0x0c083764u; return 0; }
r[0]=r[10];
goto P_0c083766;
P_0c083766: /* original 4008, guest PC 0x0c083766 */
if(!s->budget--) { s->failed_pc=0x0c083766u; return 0; }
r[0]<<=2;
goto P_0c083768;
P_0c083768: /* original 33ec, guest PC 0x0c083768 */
if(!s->budget--) { s->failed_pc=0x0c083768u; return 0; }
r[3]+=r[14];
goto P_0c08376a;
P_0c08376a: /* original 003e, guest PC 0x0c08376a */
if(!s->budget--) { s->failed_pc=0x0c08376au; return 0; }
r[0]=read(ram,r[3]+r[0],4);
goto P_0c08376c;
P_0c08376c: /* original 8801, guest PC 0x0c08376c */
if(!s->budget--) { s->failed_pc=0x0c08376cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c08376e;
P_0c08376e: /* original 8f58, guest PC 0x0c08376e */
if(!s->budget--) { s->failed_pc=0x0c08376eu; return 0; }
cond=r[17]&1u;
r[13]+=0x00000002u;
if(!cond) { goto P_0c083822; }
goto P_0c083772;
P_0c083770: /* original 7d02, guest PC 0x0c083770 */
if(!s->budget--) { s->failed_pc=0x0c083770u; return 0; }
r[13]+=0x00000002u;
goto P_0c083772;
P_0c083772: /* original 9341, guest PC 0x0c083772 */
if(!s->budget--) { s->failed_pc=0x0c083772u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0837f8u,2);
goto P_0c083774;
P_0c083774: /* original 60a3, guest PC 0x0c083774 */
if(!s->budget--) { s->failed_pc=0x0c083774u; return 0; }
r[0]=r[10];
goto P_0c083776;
P_0c083776: /* original 4008, guest PC 0x0c083776 */
if(!s->budget--) { s->failed_pc=0x0c083776u; return 0; }
r[0]<<=2;
goto P_0c083778;
P_0c083778: /* original 33ec, guest PC 0x0c083778 */
if(!s->budget--) { s->failed_pc=0x0c083778u; return 0; }
r[3]+=r[14];
goto P_0c08377a;
P_0c08377a: /* original 003e, guest PC 0x0c08377a */
if(!s->budget--) { s->failed_pc=0x0c08377au; return 0; }
r[0]=read(ram,r[3]+r[0],4);
goto P_0c08377c;
P_0c08377c: /* original 8805, guest PC 0x0c08377c */
if(!s->budget--) { s->failed_pc=0x0c08377cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000005u)!=0);
goto P_0c08377e;
P_0c08377e: /* original 8b21, guest PC 0x0c08377e */
if(!s->budget--) { s->failed_pc=0x0c08377eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0837c4; }
goto P_0c083780;
P_0c083780: /* original d31f, guest PC 0x0c083780 */
if(!s->budget--) { s->failed_pc=0x0c083780u; return 0; }
r[3]=read(ram,0x0c083800u,4);
goto P_0c083782;
P_0c083782: /* original 65d3, guest PC 0x0c083782 */
if(!s->budget--) { s->failed_pc=0x0c083782u; return 0; }
r[5]=r[13];
goto P_0c083784;
P_0c083784: /* original 9639, guest PC 0x0c083784 */
if(!s->budget--) { s->failed_pc=0x0c083784u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0837fau,2);
goto P_0c083786;
P_0c083786: /* original 430b, guest PC 0x0c083786 */
if(!s->budget--) { s->failed_pc=0x0c083786u; return 0; }
target=r[3];
r[16]=code_base|0x0c08378au;
r[4]=0x00000012u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08378au) { target=s->pc; goto dispatch; }
goto P_0c08378a;
P_0c083788: /* original e412, guest PC 0x0c083788 */
if(!s->budget--) { s->failed_pc=0x0c083788u; return 0; }
r[4]=0x00000012u;
goto P_0c08378a;
P_0c08378a: /* original 9633, guest PC 0x0c08378a */
if(!s->budget--) { s->failed_pc=0x0c08378au; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0837f4u,2);
goto P_0c08378c;
P_0c08378c: /* original 65d3, guest PC 0x0c08378c */
if(!s->budget--) { s->failed_pc=0x0c08378cu; return 0; }
r[5]=r[13];
goto P_0c08378e;
P_0c08378e: /* original d31e, guest PC 0x0c08378e */
if(!s->budget--) { s->failed_pc=0x0c08378eu; return 0; }
r[3]=read(ram,0x0c083808u,4);
goto P_0c083790;
P_0c083790: /* original 36ec, guest PC 0x0c083790 */
if(!s->budget--) { s->failed_pc=0x0c083790u; return 0; }
r[6]+=r[14];
goto P_0c083792;
P_0c083792: /* original 36cc, guest PC 0x0c083792 */
if(!s->budget--) { s->failed_pc=0x0c083792u; return 0; }
r[6]+=r[12];
goto P_0c083794;
P_0c083794: /* original 5665, guest PC 0x0c083794 */
if(!s->budget--) { s->failed_pc=0x0c083794u; return 0; }
r[6]=read(ram,r[6]+20,4);
goto P_0c083796;
P_0c083796: /* original 430b, guest PC 0x0c083796 */
if(!s->budget--) { s->failed_pc=0x0c083796u; return 0; }
target=r[3];
r[16]=code_base|0x0c08379au;
r[4]=0x00000014u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08379au) { target=s->pc; goto dispatch; }
goto P_0c08379a;
P_0c083798: /* original e414, guest PC 0x0c083798 */
if(!s->budget--) { s->failed_pc=0x0c083798u; return 0; }
r[4]=0x00000014u;
goto P_0c08379a;
P_0c08379a: /* original 6292, guest PC 0x0c08379a */
if(!s->budget--) { s->failed_pc=0x0c08379au; return 0; }
tmp=read(ram,r[9],4);
r[2]=tmp;
goto P_0c08379c;
P_0c08379c: /* original 32b0, guest PC 0x0c08379c */
if(!s->budget--) { s->failed_pc=0x0c08379cu; return 0; }
r[17]=(r[17]&~1u)|((r[2]==r[11])!=0);
goto P_0c08379e;
P_0c08379e: /* original 8b06, guest PC 0x0c08379e */
if(!s->budget--) { s->failed_pc=0x0c08379eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0837ae; }
goto P_0c0837a0;
P_0c0837a0: /* original 9628, guest PC 0x0c0837a0 */
if(!s->budget--) { s->failed_pc=0x0c0837a0u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0837f4u,2);
goto P_0c0837a2;
P_0c0837a2: /* original 55f2, guest PC 0x0c0837a2 */
if(!s->budget--) { s->failed_pc=0x0c0837a2u; return 0; }
r[5]=read(ram,r[15]+8,4);
goto P_0c0837a4;
P_0c0837a4: /* original 36ec, guest PC 0x0c0837a4 */
if(!s->budget--) { s->failed_pc=0x0c0837a4u; return 0; }
r[6]+=r[14];
goto P_0c0837a6;
P_0c0837a6: /* original 36cc, guest PC 0x0c0837a6 */
if(!s->budget--) { s->failed_pc=0x0c0837a6u; return 0; }
r[6]+=r[12];
goto P_0c0837a8;
P_0c0837a8: /* original 5665, guest PC 0x0c0837a8 */
if(!s->budget--) { s->failed_pc=0x0c0837a8u; return 0; }
r[6]=read(ram,r[6]+20,4);
goto P_0c0837aa;
P_0c0837aa: /* original a006, guest PC 0x0c0837aa */
if(!s->budget--) { s->failed_pc=0x0c0837aau; return 0; }
r[4]=0x0000002bu;
goto P_0c0837ba;
P_0c0837ac: /* original e42b, guest PC 0x0c0837ac */
if(!s->budget--) { s->failed_pc=0x0c0837acu; return 0; }
r[4]=0x0000002bu;
goto P_0c0837ae;
P_0c0837ae: /* original 9621, guest PC 0x0c0837ae */
if(!s->budget--) { s->failed_pc=0x0c0837aeu; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0837f4u,2);
goto P_0c0837b0;
P_0c0837b0: /* original e42e, guest PC 0x0c0837b0 */
if(!s->budget--) { s->failed_pc=0x0c0837b0u; return 0; }
r[4]=0x0000002eu;
goto P_0c0837b2;
P_0c0837b2: /* original 55f2, guest PC 0x0c0837b2 */
if(!s->budget--) { s->failed_pc=0x0c0837b2u; return 0; }
r[5]=read(ram,r[15]+8,4);
goto P_0c0837b4;
P_0c0837b4: /* original 36ec, guest PC 0x0c0837b4 */
if(!s->budget--) { s->failed_pc=0x0c0837b4u; return 0; }
r[6]+=r[14];
goto P_0c0837b6;
P_0c0837b6: /* original 36cc, guest PC 0x0c0837b6 */
if(!s->budget--) { s->failed_pc=0x0c0837b6u; return 0; }
r[6]+=r[12];
goto P_0c0837b8;
P_0c0837b8: /* original 5665, guest PC 0x0c0837b8 */
if(!s->budget--) { s->failed_pc=0x0c0837b8u; return 0; }
r[6]=read(ram,r[6]+20,4);
goto P_0c0837ba;
P_0c0837ba: /* original d313, guest PC 0x0c0837ba */
if(!s->budget--) { s->failed_pc=0x0c0837bau; return 0; }
r[3]=read(ram,0x0c083808u,4);
goto P_0c0837bc;
P_0c0837bc: /* original 430b, guest PC 0x0c0837bc */
if(!s->budget--) { s->failed_pc=0x0c0837bcu; return 0; }
target=r[3];
r[16]=code_base|0x0c0837c0u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0837c0u) { target=s->pc; goto dispatch; }
goto P_0c0837c0;
P_0c0837be: /* original 0009, guest PC 0x0c0837be */
if(!s->budget--) { s->failed_pc=0x0c0837beu; return 0; }
goto P_0c0837c0;
P_0c0837c0: /* original a046, guest PC 0x0c0837c0 */
if(!s->budget--) { s->failed_pc=0x0c0837c0u; return 0; }
goto P_0c083850;
P_0c0837c2: /* original 0009, guest PC 0x0c0837c2 */
if(!s->budget--) { s->failed_pc=0x0c0837c2u; return 0; }
goto P_0c0837c4;
P_0c0837c4: /* original d30e, guest PC 0x0c0837c4 */
if(!s->budget--) { s->failed_pc=0x0c0837c4u; return 0; }
r[3]=read(ram,0x0c083800u,4);
goto P_0c0837c6;
P_0c0837c6: /* original 65d3, guest PC 0x0c0837c6 */
if(!s->budget--) { s->failed_pc=0x0c0837c6u; return 0; }
r[5]=r[13];
goto P_0c0837c8;
P_0c0837c8: /* original 9618, guest PC 0x0c0837c8 */
if(!s->budget--) { s->failed_pc=0x0c0837c8u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0837fcu,2);
goto P_0c0837ca;
P_0c0837ca: /* original 430b, guest PC 0x0c0837ca */
if(!s->budget--) { s->failed_pc=0x0c0837cau; return 0; }
target=r[3];
r[16]=code_base|0x0c0837ceu;
r[4]=0x00000012u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0837ceu) { target=s->pc; goto dispatch; }
goto P_0c0837ce;
P_0c0837cc: /* original e412, guest PC 0x0c0837cc */
if(!s->budget--) { s->failed_pc=0x0c0837ccu; return 0; }
r[4]=0x00000012u;
goto P_0c0837ce;
P_0c0837ce: /* original 9611, guest PC 0x0c0837ce */
if(!s->budget--) { s->failed_pc=0x0c0837ceu; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0837f4u,2);
goto P_0c0837d0;
P_0c0837d0: /* original 65d3, guest PC 0x0c0837d0 */
if(!s->budget--) { s->failed_pc=0x0c0837d0u; return 0; }
r[5]=r[13];
goto P_0c0837d2;
P_0c0837d2: /* original d30c, guest PC 0x0c0837d2 */
if(!s->budget--) { s->failed_pc=0x0c0837d2u; return 0; }
r[3]=read(ram,0x0c083804u,4);
goto P_0c0837d4;
P_0c0837d4: /* original 36ec, guest PC 0x0c0837d4 */
if(!s->budget--) { s->failed_pc=0x0c0837d4u; return 0; }
r[6]+=r[14];
goto P_0c0837d6;
P_0c0837d6: /* original 36cc, guest PC 0x0c0837d6 */
if(!s->budget--) { s->failed_pc=0x0c0837d6u; return 0; }
r[6]+=r[12];
goto P_0c0837d8;
P_0c0837d8: /* original 5665, guest PC 0x0c0837d8 */
if(!s->budget--) { s->failed_pc=0x0c0837d8u; return 0; }
r[6]=read(ram,r[6]+20,4);
goto P_0c0837da;
P_0c0837da: /* original 430b, guest PC 0x0c0837da */
if(!s->budget--) { s->failed_pc=0x0c0837dau; return 0; }
target=r[3];
r[16]=code_base|0x0c0837deu;
r[4]=0x00000014u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0837deu) { target=s->pc; goto dispatch; }
goto P_0c0837de;
P_0c0837dc: /* original e414, guest PC 0x0c0837dc */
if(!s->budget--) { s->failed_pc=0x0c0837dcu; return 0; }
r[4]=0x00000014u;
goto P_0c0837de;
P_0c0837de: /* original 6292, guest PC 0x0c0837de */
if(!s->budget--) { s->failed_pc=0x0c0837deu; return 0; }
tmp=read(ram,r[9],4);
r[2]=tmp;
goto P_0c0837e0;
P_0c0837e0: /* original 32b0, guest PC 0x0c0837e0 */
if(!s->budget--) { s->failed_pc=0x0c0837e0u; return 0; }
r[17]=(r[17]&~1u)|((r[2]==r[11])!=0);
goto P_0c0837e2;
P_0c0837e2: /* original 8b13, guest PC 0x0c0837e2 */
if(!s->budget--) { s->failed_pc=0x0c0837e2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c08380c; }
goto P_0c0837e4;
P_0c0837e4: /* original 9606, guest PC 0x0c0837e4 */
if(!s->budget--) { s->failed_pc=0x0c0837e4u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0837f4u,2);
goto P_0c0837e6;
P_0c0837e6: /* original 55f2, guest PC 0x0c0837e6 */
if(!s->budget--) { s->failed_pc=0x0c0837e6u; return 0; }
r[5]=read(ram,r[15]+8,4);
goto P_0c0837e8;
P_0c0837e8: /* original 36ec, guest PC 0x0c0837e8 */
if(!s->budget--) { s->failed_pc=0x0c0837e8u; return 0; }
r[6]+=r[14];
goto P_0c0837ea;
P_0c0837ea: /* original 36cc, guest PC 0x0c0837ea */
if(!s->budget--) { s->failed_pc=0x0c0837eau; return 0; }
r[6]+=r[12];
goto P_0c0837ec;
P_0c0837ec: /* original 5665, guest PC 0x0c0837ec */
if(!s->budget--) { s->failed_pc=0x0c0837ecu; return 0; }
r[6]=read(ram,r[6]+20,4);
goto P_0c0837ee;
P_0c0837ee: /* original a013, guest PC 0x0c0837ee */
if(!s->budget--) { s->failed_pc=0x0c0837eeu; return 0; }
r[4]=0x0000002bu;
goto P_0c083818;
P_0c0837f0: /* original e42b, guest PC 0x0c0837f0 */
if(!s->budget--) { s->failed_pc=0x0c0837f0u; return 0; }
r[4]=0x0000002bu;
if(!vf3_matrix_family(0x0c0837f2u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0837f2u; return 0; } return 1;
P_0c08380c: /* original 9664, guest PC 0x0c08380c */
if(!s->budget--) { s->failed_pc=0x0c08380cu; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0838d8u,2);
goto P_0c08380e;
P_0c08380e: /* original e42e, guest PC 0x0c08380e */
if(!s->budget--) { s->failed_pc=0x0c08380eu; return 0; }
r[4]=0x0000002eu;
goto P_0c083810;
P_0c083810: /* original 55f2, guest PC 0x0c083810 */
if(!s->budget--) { s->failed_pc=0x0c083810u; return 0; }
r[5]=read(ram,r[15]+8,4);
goto P_0c083812;
P_0c083812: /* original 36ec, guest PC 0x0c083812 */
if(!s->budget--) { s->failed_pc=0x0c083812u; return 0; }
r[6]+=r[14];
goto P_0c083814;
P_0c083814: /* original 36cc, guest PC 0x0c083814 */
if(!s->budget--) { s->failed_pc=0x0c083814u; return 0; }
r[6]+=r[12];
goto P_0c083816;
P_0c083816: /* original 5665, guest PC 0x0c083816 */
if(!s->budget--) { s->failed_pc=0x0c083816u; return 0; }
r[6]=read(ram,r[6]+20,4);
goto P_0c083818;
P_0c083818: /* original d332, guest PC 0x0c083818 */
if(!s->budget--) { s->failed_pc=0x0c083818u; return 0; }
r[3]=read(ram,0x0c0838e4u,4);
goto P_0c08381a;
P_0c08381a: /* original 430b, guest PC 0x0c08381a */
if(!s->budget--) { s->failed_pc=0x0c08381au; return 0; }
target=r[3];
r[16]=code_base|0x0c08381eu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08381eu) { target=s->pc; goto dispatch; }
goto P_0c08381e;
P_0c08381c: /* original 0009, guest PC 0x0c08381c */
if(!s->budget--) { s->failed_pc=0x0c08381cu; return 0; }
goto P_0c08381e;
P_0c08381e: /* original a017, guest PC 0x0c08381e */
if(!s->budget--) { s->failed_pc=0x0c08381eu; return 0; }
goto P_0c083850;
P_0c083820: /* original 0009, guest PC 0x0c083820 */
if(!s->budget--) { s->failed_pc=0x0c083820u; return 0; }
goto P_0c083822;
P_0c083822: /* original d331, guest PC 0x0c083822 */
if(!s->budget--) { s->failed_pc=0x0c083822u; return 0; }
r[3]=read(ram,0x0c0838e8u,4);
goto P_0c083824;
P_0c083824: /* original 65d3, guest PC 0x0c083824 */
if(!s->budget--) { s->failed_pc=0x0c083824u; return 0; }
r[5]=r[13];
goto P_0c083826;
P_0c083826: /* original 9658, guest PC 0x0c083826 */
if(!s->budget--) { s->failed_pc=0x0c083826u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0838dau,2);
goto P_0c083828;
P_0c083828: /* original 430b, guest PC 0x0c083828 */
if(!s->budget--) { s->failed_pc=0x0c083828u; return 0; }
target=r[3];
r[16]=code_base|0x0c08382cu;
r[4]=0x00000012u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08382cu) { target=s->pc; goto dispatch; }
goto P_0c08382c;
P_0c08382a: /* original e412, guest PC 0x0c08382a */
if(!s->budget--) { s->failed_pc=0x0c08382au; return 0; }
r[4]=0x00000012u;
goto P_0c08382c;
P_0c08382c: /* original d22d, guest PC 0x0c08382c */
if(!s->budget--) { s->failed_pc=0x0c08382cu; return 0; }
r[2]=read(ram,0x0c0838e4u,4);
goto P_0c08382e;
P_0c08382e: /* original 65d3, guest PC 0x0c08382e */
if(!s->budget--) { s->failed_pc=0x0c08382eu; return 0; }
r[5]=r[13];
goto P_0c083830;
P_0c083830: /* original e602, guest PC 0x0c083830 */
if(!s->budget--) { s->failed_pc=0x0c083830u; return 0; }
r[6]=0x00000002u;
goto P_0c083832;
P_0c083832: /* original 420b, guest PC 0x0c083832 */
if(!s->budget--) { s->failed_pc=0x0c083832u; return 0; }
target=r[2];
r[16]=code_base|0x0c083836u;
r[4]=0x00000007u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c083836u) { target=s->pc; goto dispatch; }
goto P_0c083836;
P_0c083834: /* original e407, guest PC 0x0c083834 */
if(!s->budget--) { s->failed_pc=0x0c083834u; return 0; }
r[4]=0x00000007u;
goto P_0c083836;
P_0c083836: /* original 6392, guest PC 0x0c083836 */
if(!s->budget--) { s->failed_pc=0x0c083836u; return 0; }
tmp=read(ram,r[9],4);
r[3]=tmp;
goto P_0c083838;
P_0c083838: /* original 33b0, guest PC 0x0c083838 */
if(!s->budget--) { s->failed_pc=0x0c083838u; return 0; }
r[17]=(r[17]&~1u)|((r[3]==r[11])!=0);
goto P_0c08383a;
P_0c08383a: /* original 8b03, guest PC 0x0c08383a */
if(!s->budget--) { s->failed_pc=0x0c08383au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c083844; }
goto P_0c08383c;
P_0c08383c: /* original 55f2, guest PC 0x0c08383c */
if(!s->budget--) { s->failed_pc=0x0c08383cu; return 0; }
r[5]=read(ram,r[15]+8,4);
goto P_0c08383e;
P_0c08383e: /* original e602, guest PC 0x0c08383e */
if(!s->budget--) { s->failed_pc=0x0c08383eu; return 0; }
r[6]=0x00000002u;
goto P_0c083840;
P_0c083840: /* original a003, guest PC 0x0c083840 */
if(!s->budget--) { s->failed_pc=0x0c083840u; return 0; }
r[4]=0x0000002bu;
goto P_0c08384a;
P_0c083842: /* original e42b, guest PC 0x0c083842 */
if(!s->budget--) { s->failed_pc=0x0c083842u; return 0; }
r[4]=0x0000002bu;
goto P_0c083844;
P_0c083844: /* original 55f2, guest PC 0x0c083844 */
if(!s->budget--) { s->failed_pc=0x0c083844u; return 0; }
r[5]=read(ram,r[15]+8,4);
goto P_0c083846;
P_0c083846: /* original e42e, guest PC 0x0c083846 */
if(!s->budget--) { s->failed_pc=0x0c083846u; return 0; }
r[4]=0x0000002eu;
goto P_0c083848;
P_0c083848: /* original e602, guest PC 0x0c083848 */
if(!s->budget--) { s->failed_pc=0x0c083848u; return 0; }
r[6]=0x00000002u;
goto P_0c08384a;
P_0c08384a: /* original d326, guest PC 0x0c08384a */
if(!s->budget--) { s->failed_pc=0x0c08384au; return 0; }
r[3]=read(ram,0x0c0838e4u,4);
goto P_0c08384c;
P_0c08384c: /* original 430b, guest PC 0x0c08384c */
if(!s->budget--) { s->failed_pc=0x0c08384cu; return 0; }
target=r[3];
r[16]=code_base|0x0c083850u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c083850u) { target=s->pc; goto dispatch; }
goto P_0c083850;
P_0c08384e: /* original 0009, guest PC 0x0c08384e */
if(!s->budget--) { s->failed_pc=0x0c08384eu; return 0; }
goto P_0c083850;
P_0c083850: /* original 7808, guest PC 0x0c083850 */
if(!s->budget--) { s->failed_pc=0x0c083850u; return 0; }
r[8]+=0x00000008u;
goto P_0c083852;
P_0c083852: /* original 2f82, guest PC 0x0c083852 */
if(!s->budget--) { s->failed_pc=0x0c083852u; return 0; }
write(ram,r[15],r[8],4);
goto P_0c083854;
P_0c083854: /* original 6392, guest PC 0x0c083854 */
if(!s->budget--) { s->failed_pc=0x0c083854u; return 0; }
tmp=read(ram,r[9],4);
r[3]=tmp;
goto P_0c083856;
P_0c083856: /* original 33b0, guest PC 0x0c083856 */
if(!s->budget--) { s->failed_pc=0x0c083856u; return 0; }
r[17]=(r[17]&~1u)|((r[3]==r[11])!=0);
goto P_0c083858;
P_0c083858: /* original 8b59, guest PC 0x0c083858 */
if(!s->budget--) { s->failed_pc=0x0c083858u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c08390e; }
goto P_0c08385a;
P_0c08385a: /* original 9340, guest PC 0x0c08385a */
if(!s->budget--) { s->failed_pc=0x0c08385au; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0838deu,2);
goto P_0c08385c;
P_0c08385c: /* original 60a3, guest PC 0x0c08385c */
if(!s->budget--) { s->failed_pc=0x0c08385cu; return 0; }
r[0]=r[10];
goto P_0c08385e;
P_0c08385e: /* original 4008, guest PC 0x0c08385e */
if(!s->budget--) { s->failed_pc=0x0c08385eu; return 0; }
r[0]<<=2;
goto P_0c083860;
P_0c083860: /* original 983c, guest PC 0x0c083860 */
if(!s->budget--) { s->failed_pc=0x0c083860u; return 0; }
r[8]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0838dcu,2);
goto P_0c083862;
P_0c083862: /* original 33ec, guest PC 0x0c083862 */
if(!s->budget--) { s->failed_pc=0x0c083862u; return 0; }
r[3]+=r[14];
goto P_0c083864;
P_0c083864: /* original 003e, guest PC 0x0c083864 */
if(!s->budget--) { s->failed_pc=0x0c083864u; return 0; }
r[0]=read(ram,r[3]+r[0],4);
goto P_0c083866;
P_0c083866: /* original 8801, guest PC 0x0c083866 */
if(!s->budget--) { s->failed_pc=0x0c083866u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c083868;
P_0c083868: /* original 8f42, guest PC 0x0c083868 */
if(!s->budget--) { s->failed_pc=0x0c083868u; return 0; }
cond=r[17]&1u;
r[13]+=0x00000002u;
if(!cond) { goto P_0c0838f0; }
goto P_0c08386c;
P_0c08386a: /* original 7d02, guest PC 0x0c08386a */
if(!s->budget--) { s->failed_pc=0x0c08386au; return 0; }
r[13]+=0x00000002u;
goto P_0c08386c;
P_0c08386c: /* original 9338, guest PC 0x0c08386c */
if(!s->budget--) { s->failed_pc=0x0c08386cu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0838e0u,2);
goto P_0c08386e;
P_0c08386e: /* original 60a3, guest PC 0x0c08386e */
if(!s->budget--) { s->failed_pc=0x0c08386eu; return 0; }
r[0]=r[10];
goto P_0c083870;
P_0c083870: /* original 4008, guest PC 0x0c083870 */
if(!s->budget--) { s->failed_pc=0x0c083870u; return 0; }
r[0]<<=2;
goto P_0c083872;
P_0c083872: /* original 33ec, guest PC 0x0c083872 */
if(!s->budget--) { s->failed_pc=0x0c083872u; return 0; }
r[3]+=r[14];
goto P_0c083874;
P_0c083874: /* original 003e, guest PC 0x0c083874 */
if(!s->budget--) { s->failed_pc=0x0c083874u; return 0; }
r[0]=read(ram,r[3]+r[0],4);
goto P_0c083876;
P_0c083876: /* original 8806, guest PC 0x0c083876 */
if(!s->budget--) { s->failed_pc=0x0c083876u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000006u)!=0);
goto P_0c083878;
P_0c083878: /* original 8b17, guest PC 0x0c083878 */
if(!s->budget--) { s->failed_pc=0x0c083878u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0838aa; }
goto P_0c08387a;
P_0c08387a: /* original 9832, guest PC 0x0c08387a */
if(!s->budget--) { s->failed_pc=0x0c08387au; return 0; }
r[8]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0838e2u,2);
goto P_0c08387c;
P_0c08387c: /* original 65d3, guest PC 0x0c08387c */
if(!s->budget--) { s->failed_pc=0x0c08387cu; return 0; }
r[5]=r[13];
goto P_0c08387e;
P_0c08387e: /* original d31a, guest PC 0x0c08387e */
if(!s->budget--) { s->failed_pc=0x0c08387eu; return 0; }
r[3]=read(ram,0x0c0838e8u,4);
goto P_0c083880;
P_0c083880: /* original 6683, guest PC 0x0c083880 */
if(!s->budget--) { s->failed_pc=0x0c083880u; return 0; }
r[6]=r[8];
goto P_0c083882;
P_0c083882: /* original 430b, guest PC 0x0c083882 */
if(!s->budget--) { s->failed_pc=0x0c083882u; return 0; }
target=r[3];
r[16]=code_base|0x0c083886u;
r[4]=0x00000012u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c083886u) { target=s->pc; goto dispatch; }
goto P_0c083886;
P_0c083884: /* original e412, guest PC 0x0c083884 */
if(!s->budget--) { s->failed_pc=0x0c083884u; return 0; }
r[4]=0x00000012u;
goto P_0c083886;
P_0c083886: /* original 9627, guest PC 0x0c083886 */
if(!s->budget--) { s->failed_pc=0x0c083886u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0838d8u,2);
goto P_0c083888;
P_0c083888: /* original 65d3, guest PC 0x0c083888 */
if(!s->budget--) { s->failed_pc=0x0c083888u; return 0; }
r[5]=r[13];
goto P_0c08388a;
P_0c08388a: /* original d318, guest PC 0x0c08388a */
if(!s->budget--) { s->failed_pc=0x0c08388au; return 0; }
r[3]=read(ram,0x0c0838ecu,4);
goto P_0c08388c;
P_0c08388c: /* original 36ec, guest PC 0x0c08388c */
if(!s->budget--) { s->failed_pc=0x0c08388cu; return 0; }
r[6]+=r[14];
goto P_0c08388e;
P_0c08388e: /* original 36cc, guest PC 0x0c08388e */
if(!s->budget--) { s->failed_pc=0x0c08388eu; return 0; }
r[6]+=r[12];
goto P_0c083890;
P_0c083890: /* original 5666, guest PC 0x0c083890 */
if(!s->budget--) { s->failed_pc=0x0c083890u; return 0; }
r[6]=read(ram,r[6]+24,4);
goto P_0c083892;
P_0c083892: /* original 430b, guest PC 0x0c083892 */
if(!s->budget--) { s->failed_pc=0x0c083892u; return 0; }
target=r[3];
r[16]=code_base|0x0c083896u;
r[4]=0x00000014u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c083896u) { target=s->pc; goto dispatch; }
goto P_0c083896;
P_0c083894: /* original e414, guest PC 0x0c083894 */
if(!s->budget--) { s->failed_pc=0x0c083894u; return 0; }
r[4]=0x00000014u;
goto P_0c083896;
P_0c083896: /* original 961f, guest PC 0x0c083896 */
if(!s->budget--) { s->failed_pc=0x0c083896u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0838d8u,2);
goto P_0c083898;
P_0c083898: /* original d314, guest PC 0x0c083898 */
if(!s->budget--) { s->failed_pc=0x0c083898u; return 0; }
r[3]=read(ram,0x0c0838ecu,4);
goto P_0c08389a;
P_0c08389a: /* original 36ec, guest PC 0x0c08389a */
if(!s->budget--) { s->failed_pc=0x0c08389au; return 0; }
r[6]+=r[14];
goto P_0c08389c;
P_0c08389c: /* original 65f2, guest PC 0x0c08389c */
if(!s->budget--) { s->failed_pc=0x0c08389cu; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c08389e;
P_0c08389e: /* original 36cc, guest PC 0x0c08389e */
if(!s->budget--) { s->failed_pc=0x0c08389eu; return 0; }
r[6]+=r[12];
goto P_0c0838a0;
P_0c0838a0: /* original 5666, guest PC 0x0c0838a0 */
if(!s->budget--) { s->failed_pc=0x0c0838a0u; return 0; }
r[6]=read(ram,r[6]+24,4);
goto P_0c0838a2;
P_0c0838a2: /* original 430b, guest PC 0x0c0838a2 */
if(!s->budget--) { s->failed_pc=0x0c0838a2u; return 0; }
target=r[3];
r[16]=code_base|0x0c0838a6u;
r[4]=0x00000033u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0838a6u) { target=s->pc; goto dispatch; }
goto P_0c0838a6;
P_0c0838a4: /* original e433, guest PC 0x0c0838a4 */
if(!s->budget--) { s->failed_pc=0x0c0838a4u; return 0; }
r[4]=0x00000033u;
goto P_0c0838a6;
P_0c0838a6: /* original a032, guest PC 0x0c0838a6 */
if(!s->budget--) { s->failed_pc=0x0c0838a6u; return 0; }
goto P_0c08390e;
P_0c0838a8: /* original 0009, guest PC 0x0c0838a8 */
if(!s->budget--) { s->failed_pc=0x0c0838a8u; return 0; }
goto P_0c0838aa;
P_0c0838aa: /* original d30f, guest PC 0x0c0838aa */
if(!s->budget--) { s->failed_pc=0x0c0838aau; return 0; }
r[3]=read(ram,0x0c0838e8u,4);
goto P_0c0838ac;
P_0c0838ac: /* original 65d3, guest PC 0x0c0838ac */
if(!s->budget--) { s->failed_pc=0x0c0838acu; return 0; }
r[5]=r[13];
goto P_0c0838ae;
P_0c0838ae: /* original 6683, guest PC 0x0c0838ae */
if(!s->budget--) { s->failed_pc=0x0c0838aeu; return 0; }
r[6]=r[8];
goto P_0c0838b0;
P_0c0838b0: /* original 430b, guest PC 0x0c0838b0 */
if(!s->budget--) { s->failed_pc=0x0c0838b0u; return 0; }
target=r[3];
r[16]=code_base|0x0c0838b4u;
r[4]=0x00000012u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0838b4u) { target=s->pc; goto dispatch; }
goto P_0c0838b4;
P_0c0838b2: /* original e412, guest PC 0x0c0838b2 */
if(!s->budget--) { s->failed_pc=0x0c0838b2u; return 0; }
r[4]=0x00000012u;
goto P_0c0838b4;
P_0c0838b4: /* original 9610, guest PC 0x0c0838b4 */
if(!s->budget--) { s->failed_pc=0x0c0838b4u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0838d8u,2);
goto P_0c0838b6;
P_0c0838b6: /* original 65d3, guest PC 0x0c0838b6 */
if(!s->budget--) { s->failed_pc=0x0c0838b6u; return 0; }
r[5]=r[13];
goto P_0c0838b8;
P_0c0838b8: /* original d30a, guest PC 0x0c0838b8 */
if(!s->budget--) { s->failed_pc=0x0c0838b8u; return 0; }
r[3]=read(ram,0x0c0838e4u,4);
goto P_0c0838ba;
P_0c0838ba: /* original 36ec, guest PC 0x0c0838ba */
if(!s->budget--) { s->failed_pc=0x0c0838bau; return 0; }
r[6]+=r[14];
goto P_0c0838bc;
P_0c0838bc: /* original 36cc, guest PC 0x0c0838bc */
if(!s->budget--) { s->failed_pc=0x0c0838bcu; return 0; }
r[6]+=r[12];
goto P_0c0838be;
P_0c0838be: /* original 5666, guest PC 0x0c0838be */
if(!s->budget--) { s->failed_pc=0x0c0838beu; return 0; }
r[6]=read(ram,r[6]+24,4);
goto P_0c0838c0;
P_0c0838c0: /* original 430b, guest PC 0x0c0838c0 */
if(!s->budget--) { s->failed_pc=0x0c0838c0u; return 0; }
target=r[3];
r[16]=code_base|0x0c0838c4u;
r[4]=0x00000014u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0838c4u) { target=s->pc; goto dispatch; }
goto P_0c0838c4;
P_0c0838c2: /* original e414, guest PC 0x0c0838c2 */
if(!s->budget--) { s->failed_pc=0x0c0838c2u; return 0; }
r[4]=0x00000014u;
goto P_0c0838c4;
P_0c0838c4: /* original 9608, guest PC 0x0c0838c4 */
if(!s->budget--) { s->failed_pc=0x0c0838c4u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0838d8u,2);
goto P_0c0838c6;
P_0c0838c6: /* original d307, guest PC 0x0c0838c6 */
if(!s->budget--) { s->failed_pc=0x0c0838c6u; return 0; }
r[3]=read(ram,0x0c0838e4u,4);
goto P_0c0838c8;
P_0c0838c8: /* original 36ec, guest PC 0x0c0838c8 */
if(!s->budget--) { s->failed_pc=0x0c0838c8u; return 0; }
r[6]+=r[14];
goto P_0c0838ca;
P_0c0838ca: /* original 65f2, guest PC 0x0c0838ca */
if(!s->budget--) { s->failed_pc=0x0c0838cau; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0838cc;
P_0c0838cc: /* original 36cc, guest PC 0x0c0838cc */
if(!s->budget--) { s->failed_pc=0x0c0838ccu; return 0; }
r[6]+=r[12];
goto P_0c0838ce;
P_0c0838ce: /* original 5666, guest PC 0x0c0838ce */
if(!s->budget--) { s->failed_pc=0x0c0838ceu; return 0; }
r[6]=read(ram,r[6]+24,4);
goto P_0c0838d0;
P_0c0838d0: /* original 430b, guest PC 0x0c0838d0 */
if(!s->budget--) { s->failed_pc=0x0c0838d0u; return 0; }
target=r[3];
r[16]=code_base|0x0c0838d4u;
r[4]=0x00000033u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0838d4u) { target=s->pc; goto dispatch; }
goto P_0c0838d4;
P_0c0838d2: /* original e433, guest PC 0x0c0838d2 */
if(!s->budget--) { s->failed_pc=0x0c0838d2u; return 0; }
r[4]=0x00000033u;
goto P_0c0838d4;
P_0c0838d4: /* original a01b, guest PC 0x0c0838d4 */
if(!s->budget--) { s->failed_pc=0x0c0838d4u; return 0; }
goto P_0c08390e;
P_0c0838d6: /* original 0009, guest PC 0x0c0838d6 */
if(!s->budget--) { s->failed_pc=0x0c0838d6u; return 0; }
if(!vf3_matrix_family(0x0c0838d8u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0838d8u; return 0; } return 1;
P_0c0838f0: /* original d348, guest PC 0x0c0838f0 */
if(!s->budget--) { s->failed_pc=0x0c0838f0u; return 0; }
r[3]=read(ram,0x0c083a14u,4);
goto P_0c0838f2;
P_0c0838f2: /* original 65d3, guest PC 0x0c0838f2 */
if(!s->budget--) { s->failed_pc=0x0c0838f2u; return 0; }
r[5]=r[13];
goto P_0c0838f4;
P_0c0838f4: /* original 6683, guest PC 0x0c0838f4 */
if(!s->budget--) { s->failed_pc=0x0c0838f4u; return 0; }
r[6]=r[8];
goto P_0c0838f6;
P_0c0838f6: /* original 430b, guest PC 0x0c0838f6 */
if(!s->budget--) { s->failed_pc=0x0c0838f6u; return 0; }
target=r[3];
r[16]=code_base|0x0c0838fau;
r[4]=0x00000012u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0838fau) { target=s->pc; goto dispatch; }
goto P_0c0838fa;
P_0c0838f8: /* original e412, guest PC 0x0c0838f8 */
if(!s->budget--) { s->failed_pc=0x0c0838f8u; return 0; }
r[4]=0x00000012u;
goto P_0c0838fa;
P_0c0838fa: /* original d247, guest PC 0x0c0838fa */
if(!s->budget--) { s->failed_pc=0x0c0838fau; return 0; }
r[2]=read(ram,0x0c083a18u,4);
goto P_0c0838fc;
P_0c0838fc: /* original 65d3, guest PC 0x0c0838fc */
if(!s->budget--) { s->failed_pc=0x0c0838fcu; return 0; }
r[5]=r[13];
goto P_0c0838fe;
P_0c0838fe: /* original e608, guest PC 0x0c0838fe */
if(!s->budget--) { s->failed_pc=0x0c0838feu; return 0; }
r[6]=0x00000008u;
goto P_0c083900;
P_0c083900: /* original 420b, guest PC 0x0c083900 */
if(!s->budget--) { s->failed_pc=0x0c083900u; return 0; }
target=r[2];
r[16]=code_base|0x0c083904u;
r[4]=0x00000007u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c083904u) { target=s->pc; goto dispatch; }
goto P_0c083904;
P_0c083902: /* original e407, guest PC 0x0c083902 */
if(!s->budget--) { s->failed_pc=0x0c083902u; return 0; }
r[4]=0x00000007u;
goto P_0c083904;
P_0c083904: /* original d344, guest PC 0x0c083904 */
if(!s->budget--) { s->failed_pc=0x0c083904u; return 0; }
r[3]=read(ram,0x0c083a18u,4);
goto P_0c083906;
P_0c083906: /* original e608, guest PC 0x0c083906 */
if(!s->budget--) { s->failed_pc=0x0c083906u; return 0; }
r[6]=0x00000008u;
goto P_0c083908;
P_0c083908: /* original 65f2, guest PC 0x0c083908 */
if(!s->budget--) { s->failed_pc=0x0c083908u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c08390a;
P_0c08390a: /* original 430b, guest PC 0x0c08390a */
if(!s->budget--) { s->failed_pc=0x0c08390au; return 0; }
target=r[3];
r[16]=code_base|0x0c08390eu;
r[4]=0x00000033u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08390eu) { target=s->pc; goto dispatch; }
goto P_0c08390e;
P_0c08390c: /* original e433, guest PC 0x0c08390c */
if(!s->budget--) { s->failed_pc=0x0c08390cu; return 0; }
r[4]=0x00000033u;
goto P_0c08390e;
P_0c08390e: /* original 6392, guest PC 0x0c08390e */
if(!s->budget--) { s->failed_pc=0x0c08390eu; return 0; }
tmp=read(ram,r[9],4);
r[3]=tmp;
goto P_0c083910;
P_0c083910: /* original d242, guest PC 0x0c083910 */
if(!s->budget--) { s->failed_pc=0x0c083910u; return 0; }
r[2]=read(ram,0x0c083a1cu,4);
goto P_0c083912;
P_0c083912: /* original 3320, guest PC 0x0c083912 */
if(!s->budget--) { s->failed_pc=0x0c083912u; return 0; }
r[17]=(r[17]&~1u)|((r[3]==r[2])!=0);
goto P_0c083914;
P_0c083914: /* original 8901, guest PC 0x0c083914 */
if(!s->budget--) { s->failed_pc=0x0c083914u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c08391a; }
goto P_0c083916;
P_0c083916: /* original a0ab, guest PC 0x0c083916 */
if(!s->budget--) { s->failed_pc=0x0c083916u; return 0; }
goto P_0c083a70;
P_0c083918: /* original 0009, guest PC 0x0c083918 */
if(!s->budget--) { s->failed_pc=0x0c083918u; return 0; }
goto P_0c08391a;
P_0c08391a: /* original 9375, guest PC 0x0c08391a */
if(!s->budget--) { s->failed_pc=0x0c08391au; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c083a08u,2);
goto P_0c08391c;
P_0c08391c: /* original 60a3, guest PC 0x0c08391c */
if(!s->budget--) { s->failed_pc=0x0c08391cu; return 0; }
r[0]=r[10];
goto P_0c08391e;
P_0c08391e: /* original 4008, guest PC 0x0c08391e */
if(!s->budget--) { s->failed_pc=0x0c08391eu; return 0; }
r[0]<<=2;
goto P_0c083920;
P_0c083920: /* original 9971, guest PC 0x0c083920 */
if(!s->budget--) { s->failed_pc=0x0c083920u; return 0; }
r[9]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c083a06u,2);
goto P_0c083922;
P_0c083922: /* original 33ec, guest PC 0x0c083922 */
if(!s->budget--) { s->failed_pc=0x0c083922u; return 0; }
r[3]+=r[14];
goto P_0c083924;
P_0c083924: /* original 003e, guest PC 0x0c083924 */
if(!s->budget--) { s->failed_pc=0x0c083924u; return 0; }
r[0]=read(ram,r[3]+r[0],4);
goto P_0c083926;
P_0c083926: /* original 8801, guest PC 0x0c083926 */
if(!s->budget--) { s->failed_pc=0x0c083926u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c083928;
P_0c083928: /* original 8f36, guest PC 0x0c083928 */
if(!s->budget--) { s->failed_pc=0x0c083928u; return 0; }
cond=r[17]&1u;
r[13]+=0x00000002u;
if(!cond) { goto P_0c083998; }
goto P_0c08392c;
P_0c08392a: /* original 7d02, guest PC 0x0c08392a */
if(!s->budget--) { s->failed_pc=0x0c08392au; return 0; }
r[13]+=0x00000002u;
goto P_0c08392c;
P_0c08392c: /* original 936d, guest PC 0x0c08392c */
if(!s->budget--) { s->failed_pc=0x0c08392cu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c083a0au,2);
goto P_0c08392e;
P_0c08392e: /* original 60a3, guest PC 0x0c08392e */
if(!s->budget--) { s->failed_pc=0x0c08392eu; return 0; }
r[0]=r[10];
goto P_0c083930;
P_0c083930: /* original 4008, guest PC 0x0c083930 */
if(!s->budget--) { s->failed_pc=0x0c083930u; return 0; }
r[0]<<=2;
goto P_0c083932;
P_0c083932: /* original 33ec, guest PC 0x0c083932 */
if(!s->budget--) { s->failed_pc=0x0c083932u; return 0; }
r[3]+=r[14];
goto P_0c083934;
P_0c083934: /* original 003e, guest PC 0x0c083934 */
if(!s->budget--) { s->failed_pc=0x0c083934u; return 0; }
r[0]=read(ram,r[3]+r[0],4);
goto P_0c083936;
P_0c083936: /* original 8807, guest PC 0x0c083936 */
if(!s->budget--) { s->failed_pc=0x0c083936u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000007u)!=0);
goto P_0c083938;
P_0c083938: /* original 8b17, guest PC 0x0c083938 */
if(!s->budget--) { s->failed_pc=0x0c083938u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c08396a; }
goto P_0c08393a;
P_0c08393a: /* original 9967, guest PC 0x0c08393a */
if(!s->budget--) { s->failed_pc=0x0c08393au; return 0; }
r[9]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c083a0cu,2);
goto P_0c08393c;
P_0c08393c: /* original 65d3, guest PC 0x0c08393c */
if(!s->budget--) { s->failed_pc=0x0c08393cu; return 0; }
r[5]=r[13];
goto P_0c08393e;
P_0c08393e: /* original d335, guest PC 0x0c08393e */
if(!s->budget--) { s->failed_pc=0x0c08393eu; return 0; }
r[3]=read(ram,0x0c083a14u,4);
goto P_0c083940;
P_0c083940: /* original 6693, guest PC 0x0c083940 */
if(!s->budget--) { s->failed_pc=0x0c083940u; return 0; }
r[6]=r[9];
goto P_0c083942;
P_0c083942: /* original 430b, guest PC 0x0c083942 */
if(!s->budget--) { s->failed_pc=0x0c083942u; return 0; }
target=r[3];
r[16]=code_base|0x0c083946u;
r[4]=0x00000012u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c083946u) { target=s->pc; goto dispatch; }
goto P_0c083946;
P_0c083944: /* original e412, guest PC 0x0c083944 */
if(!s->budget--) { s->failed_pc=0x0c083944u; return 0; }
r[4]=0x00000012u;
goto P_0c083946;
P_0c083946: /* original 9662, guest PC 0x0c083946 */
if(!s->budget--) { s->failed_pc=0x0c083946u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c083a0eu,2);
goto P_0c083948;
P_0c083948: /* original 65d3, guest PC 0x0c083948 */
if(!s->budget--) { s->failed_pc=0x0c083948u; return 0; }
r[5]=r[13];
goto P_0c08394a;
P_0c08394a: /* original d335, guest PC 0x0c08394a */
if(!s->budget--) { s->failed_pc=0x0c08394au; return 0; }
r[3]=read(ram,0x0c083a20u,4);
goto P_0c08394c;
P_0c08394c: /* original 36ec, guest PC 0x0c08394c */
if(!s->budget--) { s->failed_pc=0x0c08394cu; return 0; }
r[6]+=r[14];
goto P_0c08394e;
P_0c08394e: /* original 36cc, guest PC 0x0c08394e */
if(!s->budget--) { s->failed_pc=0x0c08394eu; return 0; }
r[6]+=r[12];
goto P_0c083950;
P_0c083950: /* original 5667, guest PC 0x0c083950 */
if(!s->budget--) { s->failed_pc=0x0c083950u; return 0; }
r[6]=read(ram,r[6]+28,4);
goto P_0c083952;
P_0c083952: /* original 430b, guest PC 0x0c083952 */
if(!s->budget--) { s->failed_pc=0x0c083952u; return 0; }
target=r[3];
r[16]=code_base|0x0c083956u;
r[4]=0x00000014u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c083956u) { target=s->pc; goto dispatch; }
goto P_0c083956;
P_0c083954: /* original e414, guest PC 0x0c083954 */
if(!s->budget--) { s->failed_pc=0x0c083954u; return 0; }
r[4]=0x00000014u;
goto P_0c083956;
P_0c083956: /* original 965a, guest PC 0x0c083956 */
if(!s->budget--) { s->failed_pc=0x0c083956u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c083a0eu,2);
goto P_0c083958;
P_0c083958: /* original d331, guest PC 0x0c083958 */
if(!s->budget--) { s->failed_pc=0x0c083958u; return 0; }
r[3]=read(ram,0x0c083a20u,4);
goto P_0c08395a;
P_0c08395a: /* original 36ec, guest PC 0x0c08395a */
if(!s->budget--) { s->failed_pc=0x0c08395au; return 0; }
r[6]+=r[14];
goto P_0c08395c;
P_0c08395c: /* original 65f2, guest PC 0x0c08395c */
if(!s->budget--) { s->failed_pc=0x0c08395cu; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c08395e;
P_0c08395e: /* original 36cc, guest PC 0x0c08395e */
if(!s->budget--) { s->failed_pc=0x0c08395eu; return 0; }
r[6]+=r[12];
goto P_0c083960;
P_0c083960: /* original 5667, guest PC 0x0c083960 */
if(!s->budget--) { s->failed_pc=0x0c083960u; return 0; }
r[6]=read(ram,r[6]+28,4);
goto P_0c083962;
P_0c083962: /* original 430b, guest PC 0x0c083962 */
if(!s->budget--) { s->failed_pc=0x0c083962u; return 0; }
target=r[3];
r[16]=code_base|0x0c083966u;
r[4]=0x00000021u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c083966u) { target=s->pc; goto dispatch; }
goto P_0c083966;
P_0c083964: /* original e421, guest PC 0x0c083964 */
if(!s->budget--) { s->failed_pc=0x0c083964u; return 0; }
r[4]=0x00000021u;
goto P_0c083966;
P_0c083966: /* original a026, guest PC 0x0c083966 */
if(!s->budget--) { s->failed_pc=0x0c083966u; return 0; }
goto P_0c0839b6;
P_0c083968: /* original 0009, guest PC 0x0c083968 */
if(!s->budget--) { s->failed_pc=0x0c083968u; return 0; }
goto P_0c08396a;
P_0c08396a: /* original d32a, guest PC 0x0c08396a */
if(!s->budget--) { s->failed_pc=0x0c08396au; return 0; }
r[3]=read(ram,0x0c083a14u,4);
goto P_0c08396c;
P_0c08396c: /* original 65d3, guest PC 0x0c08396c */
if(!s->budget--) { s->failed_pc=0x0c08396cu; return 0; }
r[5]=r[13];
goto P_0c08396e;
P_0c08396e: /* original 6693, guest PC 0x0c08396e */
if(!s->budget--) { s->failed_pc=0x0c08396eu; return 0; }
r[6]=r[9];
goto P_0c083970;
P_0c083970: /* original 430b, guest PC 0x0c083970 */
if(!s->budget--) { s->failed_pc=0x0c083970u; return 0; }
target=r[3];
r[16]=code_base|0x0c083974u;
r[4]=0x00000012u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c083974u) { target=s->pc; goto dispatch; }
goto P_0c083974;
P_0c083972: /* original e412, guest PC 0x0c083972 */
if(!s->budget--) { s->failed_pc=0x0c083972u; return 0; }
r[4]=0x00000012u;
goto P_0c083974;
P_0c083974: /* original 964b, guest PC 0x0c083974 */
if(!s->budget--) { s->failed_pc=0x0c083974u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c083a0eu,2);
goto P_0c083976;
P_0c083976: /* original 65d3, guest PC 0x0c083976 */
if(!s->budget--) { s->failed_pc=0x0c083976u; return 0; }
r[5]=r[13];
goto P_0c083978;
P_0c083978: /* original d327, guest PC 0x0c083978 */
if(!s->budget--) { s->failed_pc=0x0c083978u; return 0; }
r[3]=read(ram,0x0c083a18u,4);
goto P_0c08397a;
P_0c08397a: /* original 36ec, guest PC 0x0c08397a */
if(!s->budget--) { s->failed_pc=0x0c08397au; return 0; }
r[6]+=r[14];
goto P_0c08397c;
P_0c08397c: /* original 36cc, guest PC 0x0c08397c */
if(!s->budget--) { s->failed_pc=0x0c08397cu; return 0; }
r[6]+=r[12];
goto P_0c08397e;
P_0c08397e: /* original 5667, guest PC 0x0c08397e */
if(!s->budget--) { s->failed_pc=0x0c08397eu; return 0; }
r[6]=read(ram,r[6]+28,4);
goto P_0c083980;
P_0c083980: /* original 430b, guest PC 0x0c083980 */
if(!s->budget--) { s->failed_pc=0x0c083980u; return 0; }
target=r[3];
r[16]=code_base|0x0c083984u;
r[4]=0x00000014u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c083984u) { target=s->pc; goto dispatch; }
goto P_0c083984;
P_0c083982: /* original e414, guest PC 0x0c083982 */
if(!s->budget--) { s->failed_pc=0x0c083982u; return 0; }
r[4]=0x00000014u;
goto P_0c083984;
P_0c083984: /* original 9643, guest PC 0x0c083984 */
if(!s->budget--) { s->failed_pc=0x0c083984u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c083a0eu,2);
goto P_0c083986;
P_0c083986: /* original d324, guest PC 0x0c083986 */
if(!s->budget--) { s->failed_pc=0x0c083986u; return 0; }
r[3]=read(ram,0x0c083a18u,4);
goto P_0c083988;
P_0c083988: /* original 36ec, guest PC 0x0c083988 */
if(!s->budget--) { s->failed_pc=0x0c083988u; return 0; }
r[6]+=r[14];
goto P_0c08398a;
P_0c08398a: /* original 65f2, guest PC 0x0c08398a */
if(!s->budget--) { s->failed_pc=0x0c08398au; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c08398c;
P_0c08398c: /* original 36cc, guest PC 0x0c08398c */
if(!s->budget--) { s->failed_pc=0x0c08398cu; return 0; }
r[6]+=r[12];
goto P_0c08398e;
P_0c08398e: /* original 5667, guest PC 0x0c08398e */
if(!s->budget--) { s->failed_pc=0x0c08398eu; return 0; }
r[6]=read(ram,r[6]+28,4);
goto P_0c083990;
P_0c083990: /* original 430b, guest PC 0x0c083990 */
if(!s->budget--) { s->failed_pc=0x0c083990u; return 0; }
target=r[3];
r[16]=code_base|0x0c083994u;
r[4]=0x00000021u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c083994u) { target=s->pc; goto dispatch; }
goto P_0c083994;
P_0c083992: /* original e421, guest PC 0x0c083992 */
if(!s->budget--) { s->failed_pc=0x0c083992u; return 0; }
r[4]=0x00000021u;
goto P_0c083994;
P_0c083994: /* original a00f, guest PC 0x0c083994 */
if(!s->budget--) { s->failed_pc=0x0c083994u; return 0; }
goto P_0c0839b6;
P_0c083996: /* original 0009, guest PC 0x0c083996 */
if(!s->budget--) { s->failed_pc=0x0c083996u; return 0; }
goto P_0c083998;
P_0c083998: /* original d31e, guest PC 0x0c083998 */
if(!s->budget--) { s->failed_pc=0x0c083998u; return 0; }
r[3]=read(ram,0x0c083a14u,4);
goto P_0c08399a;
P_0c08399a: /* original 65d3, guest PC 0x0c08399a */
if(!s->budget--) { s->failed_pc=0x0c08399au; return 0; }
r[5]=r[13];
goto P_0c08399c;
P_0c08399c: /* original 6693, guest PC 0x0c08399c */
if(!s->budget--) { s->failed_pc=0x0c08399cu; return 0; }
r[6]=r[9];
goto P_0c08399e;
P_0c08399e: /* original 430b, guest PC 0x0c08399e */
if(!s->budget--) { s->failed_pc=0x0c08399eu; return 0; }
target=r[3];
r[16]=code_base|0x0c0839a2u;
r[4]=0x00000012u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0839a2u) { target=s->pc; goto dispatch; }
goto P_0c0839a2;
P_0c0839a0: /* original e412, guest PC 0x0c0839a0 */
if(!s->budget--) { s->failed_pc=0x0c0839a0u; return 0; }
r[4]=0x00000012u;
goto P_0c0839a2;
P_0c0839a2: /* original d21d, guest PC 0x0c0839a2 */
if(!s->budget--) { s->failed_pc=0x0c0839a2u; return 0; }
r[2]=read(ram,0x0c083a18u,4);
goto P_0c0839a4;
P_0c0839a4: /* original 65d3, guest PC 0x0c0839a4 */
if(!s->budget--) { s->failed_pc=0x0c0839a4u; return 0; }
r[5]=r[13];
goto P_0c0839a6;
P_0c0839a6: /* original e610, guest PC 0x0c0839a6 */
if(!s->budget--) { s->failed_pc=0x0c0839a6u; return 0; }
r[6]=0x00000010u;
goto P_0c0839a8;
P_0c0839a8: /* original 420b, guest PC 0x0c0839a8 */
if(!s->budget--) { s->failed_pc=0x0c0839a8u; return 0; }
target=r[2];
r[16]=code_base|0x0c0839acu;
r[4]=0x00000007u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0839acu) { target=s->pc; goto dispatch; }
goto P_0c0839ac;
P_0c0839aa: /* original e407, guest PC 0x0c0839aa */
if(!s->budget--) { s->failed_pc=0x0c0839aau; return 0; }
r[4]=0x00000007u;
goto P_0c0839ac;
P_0c0839ac: /* original d31a, guest PC 0x0c0839ac */
if(!s->budget--) { s->failed_pc=0x0c0839acu; return 0; }
r[3]=read(ram,0x0c083a18u,4);
goto P_0c0839ae;
P_0c0839ae: /* original e610, guest PC 0x0c0839ae */
if(!s->budget--) { s->failed_pc=0x0c0839aeu; return 0; }
r[6]=0x00000010u;
goto P_0c0839b0;
P_0c0839b0: /* original 65f2, guest PC 0x0c0839b0 */
if(!s->budget--) { s->failed_pc=0x0c0839b0u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0839b2;
P_0c0839b2: /* original 430b, guest PC 0x0c0839b2 */
if(!s->budget--) { s->failed_pc=0x0c0839b2u; return 0; }
target=r[3];
r[16]=code_base|0x0c0839b6u;
r[4]=0x00000021u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0839b6u) { target=s->pc; goto dispatch; }
goto P_0c0839b6;
P_0c0839b4: /* original e421, guest PC 0x0c0839b4 */
if(!s->budget--) { s->failed_pc=0x0c0839b4u; return 0; }
r[4]=0x00000021u;
goto P_0c0839b6;
P_0c0839b6: /* original 9327, guest PC 0x0c0839b6 */
if(!s->budget--) { s->failed_pc=0x0c0839b6u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c083a08u,2);
goto P_0c0839b8;
P_0c0839b8: /* original 60a3, guest PC 0x0c0839b8 */
if(!s->budget--) { s->failed_pc=0x0c0839b8u; return 0; }
r[0]=r[10];
goto P_0c0839ba;
P_0c0839ba: /* original 4008, guest PC 0x0c0839ba */
if(!s->budget--) { s->failed_pc=0x0c0839bau; return 0; }
r[0]<<=2;
goto P_0c0839bc;
P_0c0839bc: /* original 9928, guest PC 0x0c0839bc */
if(!s->budget--) { s->failed_pc=0x0c0839bcu; return 0; }
r[9]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c083a10u,2);
goto P_0c0839be;
P_0c0839be: /* original 33ec, guest PC 0x0c0839be */
if(!s->budget--) { s->failed_pc=0x0c0839beu; return 0; }
r[3]+=r[14];
goto P_0c0839c0;
P_0c0839c0: /* original 003e, guest PC 0x0c0839c0 */
if(!s->budget--) { s->failed_pc=0x0c0839c0u; return 0; }
r[0]=read(ram,r[3]+r[0],4);
goto P_0c0839c2;
P_0c0839c2: /* original 8801, guest PC 0x0c0839c2 */
if(!s->budget--) { s->failed_pc=0x0c0839c2u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c0839c4;
P_0c0839c4: /* original 8f45, guest PC 0x0c0839c4 */
if(!s->budget--) { s->failed_pc=0x0c0839c4u; return 0; }
cond=r[17]&1u;
r[13]+=0x00000002u;
if(!cond) { goto P_0c083a52; }
goto P_0c0839c8;
P_0c0839c6: /* original 7d02, guest PC 0x0c0839c6 */
if(!s->budget--) { s->failed_pc=0x0c0839c6u; return 0; }
r[13]+=0x00000002u;
goto P_0c0839c8;
P_0c0839c8: /* original 931f, guest PC 0x0c0839c8 */
if(!s->budget--) { s->failed_pc=0x0c0839c8u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c083a0au,2);
goto P_0c0839ca;
P_0c0839ca: /* original 60a3, guest PC 0x0c0839ca */
if(!s->budget--) { s->failed_pc=0x0c0839cau; return 0; }
r[0]=r[10];
goto P_0c0839cc;
P_0c0839cc: /* original 4008, guest PC 0x0c0839cc */
if(!s->budget--) { s->failed_pc=0x0c0839ccu; return 0; }
r[0]<<=2;
goto P_0c0839ce;
P_0c0839ce: /* original 33ec, guest PC 0x0c0839ce */
if(!s->budget--) { s->failed_pc=0x0c0839ceu; return 0; }
r[3]+=r[14];
goto P_0c0839d0;
P_0c0839d0: /* original 003e, guest PC 0x0c0839d0 */
if(!s->budget--) { s->failed_pc=0x0c0839d0u; return 0; }
r[0]=read(ram,r[3]+r[0],4);
goto P_0c0839d2;
P_0c0839d2: /* original 8808, guest PC 0x0c0839d2 */
if(!s->budget--) { s->failed_pc=0x0c0839d2u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000008u)!=0);
goto P_0c0839d4;
P_0c0839d4: /* original 8b26, guest PC 0x0c0839d4 */
if(!s->budget--) { s->failed_pc=0x0c0839d4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c083a24; }
goto P_0c0839d6;
P_0c0839d6: /* original 991c, guest PC 0x0c0839d6 */
if(!s->budget--) { s->failed_pc=0x0c0839d6u; return 0; }
r[9]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c083a12u,2);
goto P_0c0839d8;
P_0c0839d8: /* original 65d3, guest PC 0x0c0839d8 */
if(!s->budget--) { s->failed_pc=0x0c0839d8u; return 0; }
r[5]=r[13];
goto P_0c0839da;
P_0c0839da: /* original d30e, guest PC 0x0c0839da */
if(!s->budget--) { s->failed_pc=0x0c0839dau; return 0; }
r[3]=read(ram,0x0c083a14u,4);
goto P_0c0839dc;
P_0c0839dc: /* original 6693, guest PC 0x0c0839dc */
if(!s->budget--) { s->failed_pc=0x0c0839dcu; return 0; }
r[6]=r[9];
goto P_0c0839de;
P_0c0839de: /* original 430b, guest PC 0x0c0839de */
if(!s->budget--) { s->failed_pc=0x0c0839deu; return 0; }
target=r[3];
r[16]=code_base|0x0c0839e2u;
r[4]=0x00000012u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0839e2u) { target=s->pc; goto dispatch; }
goto P_0c0839e2;
P_0c0839e0: /* original e412, guest PC 0x0c0839e0 */
if(!s->budget--) { s->failed_pc=0x0c0839e0u; return 0; }
r[4]=0x00000012u;
goto P_0c0839e2;
P_0c0839e2: /* original 9614, guest PC 0x0c0839e2 */
if(!s->budget--) { s->failed_pc=0x0c0839e2u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c083a0eu,2);
goto P_0c0839e4;
P_0c0839e4: /* original 65d3, guest PC 0x0c0839e4 */
if(!s->budget--) { s->failed_pc=0x0c0839e4u; return 0; }
r[5]=r[13];
goto P_0c0839e6;
P_0c0839e6: /* original d30e, guest PC 0x0c0839e6 */
if(!s->budget--) { s->failed_pc=0x0c0839e6u; return 0; }
r[3]=read(ram,0x0c083a20u,4);
goto P_0c0839e8;
P_0c0839e8: /* original 36ec, guest PC 0x0c0839e8 */
if(!s->budget--) { s->failed_pc=0x0c0839e8u; return 0; }
r[6]+=r[14];
goto P_0c0839ea;
P_0c0839ea: /* original 36cc, guest PC 0x0c0839ea */
if(!s->budget--) { s->failed_pc=0x0c0839eau; return 0; }
r[6]+=r[12];
goto P_0c0839ec;
P_0c0839ec: /* original 5668, guest PC 0x0c0839ec */
if(!s->budget--) { s->failed_pc=0x0c0839ecu; return 0; }
r[6]=read(ram,r[6]+32,4);
goto P_0c0839ee;
P_0c0839ee: /* original 430b, guest PC 0x0c0839ee */
if(!s->budget--) { s->failed_pc=0x0c0839eeu; return 0; }
target=r[3];
r[16]=code_base|0x0c0839f2u;
r[4]=0x00000014u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0839f2u) { target=s->pc; goto dispatch; }
goto P_0c0839f2;
P_0c0839f0: /* original e414, guest PC 0x0c0839f0 */
if(!s->budget--) { s->failed_pc=0x0c0839f0u; return 0; }
r[4]=0x00000014u;
goto P_0c0839f2;
P_0c0839f2: /* original 960c, guest PC 0x0c0839f2 */
if(!s->budget--) { s->failed_pc=0x0c0839f2u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c083a0eu,2);
goto P_0c0839f4;
P_0c0839f4: /* original d30a, guest PC 0x0c0839f4 */
if(!s->budget--) { s->failed_pc=0x0c0839f4u; return 0; }
r[3]=read(ram,0x0c083a20u,4);
goto P_0c0839f6;
P_0c0839f6: /* original 36ec, guest PC 0x0c0839f6 */
if(!s->budget--) { s->failed_pc=0x0c0839f6u; return 0; }
r[6]+=r[14];
goto P_0c0839f8;
P_0c0839f8: /* original 65f2, guest PC 0x0c0839f8 */
if(!s->budget--) { s->failed_pc=0x0c0839f8u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0839fa;
P_0c0839fa: /* original 36cc, guest PC 0x0c0839fa */
if(!s->budget--) { s->failed_pc=0x0c0839fau; return 0; }
r[6]+=r[12];
goto P_0c0839fc;
P_0c0839fc: /* original 5668, guest PC 0x0c0839fc */
if(!s->budget--) { s->failed_pc=0x0c0839fcu; return 0; }
r[6]=read(ram,r[6]+32,4);
goto P_0c0839fe;
P_0c0839fe: /* original 430b, guest PC 0x0c0839fe */
if(!s->budget--) { s->failed_pc=0x0c0839feu; return 0; }
target=r[3];
r[16]=code_base|0x0c083a02u;
r[4]=0x00000031u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c083a02u) { target=s->pc; goto dispatch; }
goto P_0c083a02;
P_0c083a00: /* original e431, guest PC 0x0c083a00 */
if(!s->budget--) { s->failed_pc=0x0c083a00u; return 0; }
r[4]=0x00000031u;
goto P_0c083a02;
P_0c083a02: /* original a035, guest PC 0x0c083a02 */
if(!s->budget--) { s->failed_pc=0x0c083a02u; return 0; }
goto P_0c083a70;
P_0c083a04: /* original 0009, guest PC 0x0c083a04 */
if(!s->budget--) { s->failed_pc=0x0c083a04u; return 0; }
if(!vf3_matrix_family(0x0c083a06u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c083a06u; return 0; } return 1;
P_0c083a24: /* original d34a, guest PC 0x0c083a24 */
if(!s->budget--) { s->failed_pc=0x0c083a24u; return 0; }
r[3]=read(ram,0x0c083b50u,4);
goto P_0c083a26;
P_0c083a26: /* original 65d3, guest PC 0x0c083a26 */
if(!s->budget--) { s->failed_pc=0x0c083a26u; return 0; }
r[5]=r[13];
goto P_0c083a28;
P_0c083a28: /* original 6693, guest PC 0x0c083a28 */
if(!s->budget--) { s->failed_pc=0x0c083a28u; return 0; }
r[6]=r[9];
goto P_0c083a2a;
P_0c083a2a: /* original 430b, guest PC 0x0c083a2a */
if(!s->budget--) { s->failed_pc=0x0c083a2au; return 0; }
target=r[3];
r[16]=code_base|0x0c083a2eu;
r[4]=0x00000012u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c083a2eu) { target=s->pc; goto dispatch; }
goto P_0c083a2e;
P_0c083a2c: /* original e412, guest PC 0x0c083a2c */
if(!s->budget--) { s->failed_pc=0x0c083a2cu; return 0; }
r[4]=0x00000012u;
goto P_0c083a2e;
P_0c083a2e: /* original 9685, guest PC 0x0c083a2e */
if(!s->budget--) { s->failed_pc=0x0c083a2eu; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c083b3cu,2);
goto P_0c083a30;
P_0c083a30: /* original 65d3, guest PC 0x0c083a30 */
if(!s->budget--) { s->failed_pc=0x0c083a30u; return 0; }
r[5]=r[13];
goto P_0c083a32;
P_0c083a32: /* original d348, guest PC 0x0c083a32 */
if(!s->budget--) { s->failed_pc=0x0c083a32u; return 0; }
r[3]=read(ram,0x0c083b54u,4);
goto P_0c083a34;
P_0c083a34: /* original 36ec, guest PC 0x0c083a34 */
if(!s->budget--) { s->failed_pc=0x0c083a34u; return 0; }
r[6]+=r[14];
goto P_0c083a36;
P_0c083a36: /* original 36cc, guest PC 0x0c083a36 */
if(!s->budget--) { s->failed_pc=0x0c083a36u; return 0; }
r[6]+=r[12];
goto P_0c083a38;
P_0c083a38: /* original 5668, guest PC 0x0c083a38 */
if(!s->budget--) { s->failed_pc=0x0c083a38u; return 0; }
r[6]=read(ram,r[6]+32,4);
goto P_0c083a3a;
P_0c083a3a: /* original 430b, guest PC 0x0c083a3a */
if(!s->budget--) { s->failed_pc=0x0c083a3au; return 0; }
target=r[3];
r[16]=code_base|0x0c083a3eu;
r[4]=0x00000014u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c083a3eu) { target=s->pc; goto dispatch; }
goto P_0c083a3e;
P_0c083a3c: /* original e414, guest PC 0x0c083a3c */
if(!s->budget--) { s->failed_pc=0x0c083a3cu; return 0; }
r[4]=0x00000014u;
goto P_0c083a3e;
P_0c083a3e: /* original 967d, guest PC 0x0c083a3e */
if(!s->budget--) { s->failed_pc=0x0c083a3eu; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c083b3cu,2);
goto P_0c083a40;
P_0c083a40: /* original d344, guest PC 0x0c083a40 */
if(!s->budget--) { s->failed_pc=0x0c083a40u; return 0; }
r[3]=read(ram,0x0c083b54u,4);
goto P_0c083a42;
P_0c083a42: /* original 36ec, guest PC 0x0c083a42 */
if(!s->budget--) { s->failed_pc=0x0c083a42u; return 0; }
r[6]+=r[14];
goto P_0c083a44;
P_0c083a44: /* original 65f2, guest PC 0x0c083a44 */
if(!s->budget--) { s->failed_pc=0x0c083a44u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c083a46;
P_0c083a46: /* original 36cc, guest PC 0x0c083a46 */
if(!s->budget--) { s->failed_pc=0x0c083a46u; return 0; }
r[6]+=r[12];
goto P_0c083a48;
P_0c083a48: /* original 5668, guest PC 0x0c083a48 */
if(!s->budget--) { s->failed_pc=0x0c083a48u; return 0; }
r[6]=read(ram,r[6]+32,4);
goto P_0c083a4a;
P_0c083a4a: /* original 430b, guest PC 0x0c083a4a */
if(!s->budget--) { s->failed_pc=0x0c083a4au; return 0; }
target=r[3];
r[16]=code_base|0x0c083a4eu;
r[4]=0x00000031u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c083a4eu) { target=s->pc; goto dispatch; }
goto P_0c083a4e;
P_0c083a4c: /* original e431, guest PC 0x0c083a4c */
if(!s->budget--) { s->failed_pc=0x0c083a4cu; return 0; }
r[4]=0x00000031u;
goto P_0c083a4e;
P_0c083a4e: /* original a00f, guest PC 0x0c083a4e */
if(!s->budget--) { s->failed_pc=0x0c083a4eu; return 0; }
goto P_0c083a70;
P_0c083a50: /* original 0009, guest PC 0x0c083a50 */
if(!s->budget--) { s->failed_pc=0x0c083a50u; return 0; }
goto P_0c083a52;
P_0c083a52: /* original d33f, guest PC 0x0c083a52 */
if(!s->budget--) { s->failed_pc=0x0c083a52u; return 0; }
r[3]=read(ram,0x0c083b50u,4);
goto P_0c083a54;
P_0c083a54: /* original 65d3, guest PC 0x0c083a54 */
if(!s->budget--) { s->failed_pc=0x0c083a54u; return 0; }
r[5]=r[13];
goto P_0c083a56;
P_0c083a56: /* original 6693, guest PC 0x0c083a56 */
if(!s->budget--) { s->failed_pc=0x0c083a56u; return 0; }
r[6]=r[9];
goto P_0c083a58;
P_0c083a58: /* original 430b, guest PC 0x0c083a58 */
if(!s->budget--) { s->failed_pc=0x0c083a58u; return 0; }
target=r[3];
r[16]=code_base|0x0c083a5cu;
r[4]=0x00000012u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c083a5cu) { target=s->pc; goto dispatch; }
goto P_0c083a5c;
P_0c083a5a: /* original e412, guest PC 0x0c083a5a */
if(!s->budget--) { s->failed_pc=0x0c083a5au; return 0; }
r[4]=0x00000012u;
goto P_0c083a5c;
P_0c083a5c: /* original d23d, guest PC 0x0c083a5c */
if(!s->budget--) { s->failed_pc=0x0c083a5cu; return 0; }
r[2]=read(ram,0x0c083b54u,4);
goto P_0c083a5e;
P_0c083a5e: /* original 65d3, guest PC 0x0c083a5e */
if(!s->budget--) { s->failed_pc=0x0c083a5eu; return 0; }
r[5]=r[13];
goto P_0c083a60;
P_0c083a60: /* original e610, guest PC 0x0c083a60 */
if(!s->budget--) { s->failed_pc=0x0c083a60u; return 0; }
r[6]=0x00000010u;
goto P_0c083a62;
P_0c083a62: /* original 420b, guest PC 0x0c083a62 */
if(!s->budget--) { s->failed_pc=0x0c083a62u; return 0; }
target=r[2];
r[16]=code_base|0x0c083a66u;
r[4]=0x00000007u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c083a66u) { target=s->pc; goto dispatch; }
goto P_0c083a66;
P_0c083a64: /* original e407, guest PC 0x0c083a64 */
if(!s->budget--) { s->failed_pc=0x0c083a64u; return 0; }
r[4]=0x00000007u;
goto P_0c083a66;
P_0c083a66: /* original d33b, guest PC 0x0c083a66 */
if(!s->budget--) { s->failed_pc=0x0c083a66u; return 0; }
r[3]=read(ram,0x0c083b54u,4);
goto P_0c083a68;
P_0c083a68: /* original e610, guest PC 0x0c083a68 */
if(!s->budget--) { s->failed_pc=0x0c083a68u; return 0; }
r[6]=0x00000010u;
goto P_0c083a6a;
P_0c083a6a: /* original 65f2, guest PC 0x0c083a6a */
if(!s->budget--) { s->failed_pc=0x0c083a6au; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c083a6c;
P_0c083a6c: /* original 430b, guest PC 0x0c083a6c */
if(!s->budget--) { s->failed_pc=0x0c083a6cu; return 0; }
target=r[3];
r[16]=code_base|0x0c083a70u;
r[4]=0x00000031u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c083a70u) { target=s->pc; goto dispatch; }
goto P_0c083a70;
P_0c083a6e: /* original e431, guest PC 0x0c083a6e */
if(!s->budget--) { s->failed_pc=0x0c083a6eu; return 0; }
r[4]=0x00000031u;
goto P_0c083a70;
P_0c083a70: /* original 7a01, guest PC 0x0c083a70 */
if(!s->budget--) { s->failed_pc=0x0c083a70u; return 0; }
r[10]+=0x00000001u;
goto P_0c083a72;
P_0c083a72: /* original 7d0c, guest PC 0x0c083a72 */
if(!s->budget--) { s->failed_pc=0x0c083a72u; return 0; }
r[13]+=0x0000000cu;
goto P_0c083a74;
P_0c083a74: /* original e402, guest PC 0x0c083a74 */
if(!s->budget--) { s->failed_pc=0x0c083a74u; return 0; }
r[4]=0x00000002u;
goto P_0c083a76;
P_0c083a76: /* original 3a43, guest PC 0x0c083a76 */
if(!s->budget--) { s->failed_pc=0x0c083a76u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[10]>=(int32_t)r[4])!=0);
goto P_0c083a78;
P_0c083a78: /* original 8901, guest PC 0x0c083a78 */
if(!s->budget--) { s->failed_pc=0x0c083a78u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c083a7e; }
goto P_0c083a7a;
P_0c083a7a: /* original abce, guest PC 0x0c083a7a */
if(!s->budget--) { s->failed_pc=0x0c083a7au; return 0; }
goto P_0c08321a;
P_0c083a7c: /* original 0009, guest PC 0x0c083a7c */
if(!s->budget--) { s->failed_pc=0x0c083a7cu; return 0; }
goto P_0c083a7e;
P_0c083a7e: /* original 54f3, guest PC 0x0c083a7e */
if(!s->budget--) { s->failed_pc=0x0c083a7eu; return 0; }
r[4]=read(ram,r[15]+12,4);
goto P_0c083a80;
P_0c083a80: /* original 55f4, guest PC 0x0c083a80 */
if(!s->budget--) { s->failed_pc=0x0c083a80u; return 0; }
r[5]=read(ram,r[15]+16,4);
goto P_0c083a82;
P_0c083a82: /* original 7f14, guest PC 0x0c083a82 */
if(!s->budget--) { s->failed_pc=0x0c083a82u; return 0; }
r[15]+=0x00000014u;
goto P_0c083a84;
P_0c083a84: /* original 4f26, guest PC 0x0c083a84 */
if(!s->budget--) { s->failed_pc=0x0c083a84u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c083a86;
P_0c083a86: /* original d334, guest PC 0x0c083a86 */
if(!s->budget--) { s->failed_pc=0x0c083a86u; return 0; }
r[3]=read(ram,0x0c083b58u,4);
goto P_0c083a88;
P_0c083a88: /* original 68f6, guest PC 0x0c083a88 */
if(!s->budget--) { s->failed_pc=0x0c083a88u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c083a8a;
P_0c083a8a: /* original 69f6, guest PC 0x0c083a8a */
if(!s->budget--) { s->failed_pc=0x0c083a8au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c083a8c;
P_0c083a8c: /* original 6af6, guest PC 0x0c083a8c */
if(!s->budget--) { s->failed_pc=0x0c083a8cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c083a8e;
P_0c083a8e: /* original 6bf6, guest PC 0x0c083a8e */
if(!s->budget--) { s->failed_pc=0x0c083a8eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c083a90;
P_0c083a90: /* original 6cf6, guest PC 0x0c083a90 */
if(!s->budget--) { s->failed_pc=0x0c083a90u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c083a92;
P_0c083a92: /* original 6df6, guest PC 0x0c083a92 */
if(!s->budget--) { s->failed_pc=0x0c083a92u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c083a94;
P_0c083a94: /* original 432b, guest PC 0x0c083a94 */
if(!s->budget--) { s->failed_pc=0x0c083a94u; return 0; }
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
P_0c083a96: /* original 6ef6, guest PC 0x0c083a96 */
if(!s->budget--) { s->failed_pc=0x0c083a96u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c083a98;
P_0c083a98: /* original 2fe6, guest PC 0x0c083a98 */
if(!s->budget--) { s->failed_pc=0x0c083a98u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c083a9a;
P_0c083a9a: /* original 2fd6, guest PC 0x0c083a9a */
if(!s->budget--) { s->failed_pc=0x0c083a9au; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c083a9c;
P_0c083a9c: /* original 2fc6, guest PC 0x0c083a9c */
if(!s->budget--) { s->failed_pc=0x0c083a9cu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c083a9e;
P_0c083a9e: /* original 6c53, guest PC 0x0c083a9e */
if(!s->budget--) { s->failed_pc=0x0c083a9eu; return 0; }
r[12]=r[5];
goto P_0c083aa0;
P_0c083aa0: /* original 2fb6, guest PC 0x0c083aa0 */
if(!s->budget--) { s->failed_pc=0x0c083aa0u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c083aa2;
P_0c083aa2: /* original 2fa6, guest PC 0x0c083aa2 */
if(!s->budget--) { s->failed_pc=0x0c083aa2u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c083aa4;
P_0c083aa4: /* original 2f96, guest PC 0x0c083aa4 */
if(!s->budget--) { s->failed_pc=0x0c083aa4u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c083aa6;
P_0c083aa6: /* original 2f86, guest PC 0x0c083aa6 */
if(!s->budget--) { s->failed_pc=0x0c083aa6u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c083aa8;
P_0c083aa8: /* original 4f22, guest PC 0x0c083aa8 */
if(!s->budget--) { s->failed_pc=0x0c083aa8u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c083aaa;
P_0c083aaa: /* original 7ff4, guest PC 0x0c083aaa */
if(!s->budget--) { s->failed_pc=0x0c083aaau; return 0; }
r[15]+=0xfffffff4u;
goto P_0c083aac;
P_0c083aac: /* original 1f42, guest PC 0x0c083aac */
if(!s->budget--) { s->failed_pc=0x0c083aacu; return 0; }
write(ram,r[15]+8,r[4],4);
goto P_0c083aae;
P_0c083aae: /* original dd2c, guest PC 0x0c083aae */
if(!s->budget--) { s->failed_pc=0x0c083aaeu; return 0; }
r[13]=read(ram,0x0c083b60u,4);
goto P_0c083ab0;
P_0c083ab0: /* original de2a, guest PC 0x0c083ab0 */
if(!s->budget--) { s->failed_pc=0x0c083ab0u; return 0; }
r[14]=read(ram,0x0c083b5cu,4);
goto P_0c083ab2;
P_0c083ab2: /* original 1fd1, guest PC 0x0c083ab2 */
if(!s->budget--) { s->failed_pc=0x0c083ab2u; return 0; }
write(ram,r[15]+4,r[13],4);
goto P_0c083ab4;
P_0c083ab4: /* original d32b, guest PC 0x0c083ab4 */
if(!s->budget--) { s->failed_pc=0x0c083ab4u; return 0; }
r[3]=read(ram,0x0c083b64u,4);
goto P_0c083ab6;
P_0c083ab6: /* original 430b, guest PC 0x0c083ab6 */
if(!s->budget--) { s->failed_pc=0x0c083ab6u; return 0; }
target=r[3];
r[16]=code_base|0x0c083abau;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c083abau) { target=s->pc; goto dispatch; }
goto P_0c083aba;
P_0c083ab8: /* original 64d3, guest PC 0x0c083ab8 */
if(!s->budget--) { s->failed_pc=0x0c083ab8u; return 0; }
r[4]=r[13];
goto P_0c083aba;
P_0c083aba: /* original d225, guest PC 0x0c083aba */
if(!s->budget--) { s->failed_pc=0x0c083abau; return 0; }
r[2]=read(ram,0x0c083b50u,4);
goto P_0c083abc;
P_0c083abc: /* original e50b, guest PC 0x0c083abc */
if(!s->budget--) { s->failed_pc=0x0c083abcu; return 0; }
r[5]=0x0000000bu;
goto P_0c083abe;
P_0c083abe: /* original 963e, guest PC 0x0c083abe */
if(!s->budget--) { s->failed_pc=0x0c083abeu; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c083b3eu,2);
goto P_0c083ac0;
P_0c083ac0: /* original 420b, guest PC 0x0c083ac0 */
if(!s->budget--) { s->failed_pc=0x0c083ac0u; return 0; }
target=r[2];
r[16]=code_base|0x0c083ac4u;
r[4]=0x00000017u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c083ac4u) { target=s->pc; goto dispatch; }
goto P_0c083ac4;
P_0c083ac2: /* original e417, guest PC 0x0c083ac2 */
if(!s->budget--) { s->failed_pc=0x0c083ac2u; return 0; }
r[4]=0x00000017u;
goto P_0c083ac4;
P_0c083ac4: /* original 9a3c, guest PC 0x0c083ac4 */
if(!s->budget--) { s->failed_pc=0x0c083ac4u; return 0; }
r[10]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c083b40u,2);
goto P_0c083ac6;
P_0c083ac6: /* original ed00, guest PC 0x0c083ac6 */
if(!s->budget--) { s->failed_pc=0x0c083ac6u; return 0; }
r[13]=0x00000000u;
goto P_0c083ac8;
P_0c083ac8: /* original 9b3b, guest PC 0x0c083ac8 */
if(!s->budget--) { s->failed_pc=0x0c083ac8u; return 0; }
r[11]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c083b42u,2);
goto P_0c083aca;
P_0c083aca: /* original d928, guest PC 0x0c083aca */
if(!s->budget--) { s->failed_pc=0x0c083acau; return 0; }
r[9]=read(ram,0x0c083b6cu,4);
goto P_0c083acc;
P_0c083acc: /* original d826, guest PC 0x0c083acc */
if(!s->budget--) { s->failed_pc=0x0c083accu; return 0; }
r[8]=read(ram,0x0c083b68u,4);
goto P_0c083ace;
P_0c083ace: /* original d328, guest PC 0x0c083ace */
if(!s->budget--) { s->failed_pc=0x0c083aceu; return 0; }
r[3]=read(ram,0x0c083b70u,4);
goto P_0c083ad0;
P_0c083ad0: /* original e500, guest PC 0x0c083ad0 */
if(!s->budget--) { s->failed_pc=0x0c083ad0u; return 0; }
r[5]=0x00000000u;
goto P_0c083ad2;
P_0c083ad2: /* original 430b, guest PC 0x0c083ad2 */
if(!s->budget--) { s->failed_pc=0x0c083ad2u; return 0; }
target=r[3];
r[16]=code_base|0x0c083ad6u;
r[4]=read(ram,r[15]+4,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c083ad6u) { target=s->pc; goto dispatch; }
goto P_0c083ad6;
P_0c083ad4: /* original 54f1, guest PC 0x0c083ad4 */
if(!s->budget--) { s->failed_pc=0x0c083ad4u; return 0; }
r[4]=read(ram,r[15]+4,4);
goto P_0c083ad6;
P_0c083ad6: /* original 60d3, guest PC 0x0c083ad6 */
if(!s->budget--) { s->failed_pc=0x0c083ad6u; return 0; }
r[0]=r[13];
goto P_0c083ad8;
P_0c083ad8: /* original 8800, guest PC 0x0c083ad8 */
if(!s->budget--) { s->failed_pc=0x0c083ad8u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000000u)!=0);
goto P_0c083ada;
P_0c083ada: /* original 8909, guest PC 0x0c083ada */
if(!s->budget--) { s->failed_pc=0x0c083adau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c083af0; }
goto P_0c083adc;
P_0c083adc: /* original 8801, guest PC 0x0c083adc */
if(!s->budget--) { s->failed_pc=0x0c083adcu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c083ade;
P_0c083ade: /* original 894b, guest PC 0x0c083ade */
if(!s->budget--) { s->failed_pc=0x0c083adeu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c083b78; }
goto P_0c083ae0;
P_0c083ae0: /* original 8802, guest PC 0x0c083ae0 */
if(!s->budget--) { s->failed_pc=0x0c083ae0u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c083ae2;
P_0c083ae2: /* original 896d, guest PC 0x0c083ae2 */
if(!s->budget--) { s->failed_pc=0x0c083ae2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c083bc0; }
goto P_0c083ae4;
P_0c083ae4: /* original 8803, guest PC 0x0c083ae4 */
if(!s->budget--) { s->failed_pc=0x0c083ae4u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000003u)!=0);
goto P_0c083ae6;
P_0c083ae6: /* original 8b01, guest PC 0x0c083ae6 */
if(!s->budget--) { s->failed_pc=0x0c083ae6u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c083aec; }
goto P_0c083ae8;
P_0c083ae8: /* original a092, guest PC 0x0c083ae8 */
if(!s->budget--) { s->failed_pc=0x0c083ae8u; return 0; }
goto P_0c083c10;
P_0c083aea: /* original 0009, guest PC 0x0c083aea */
if(!s->budget--) { s->failed_pc=0x0c083aeau; return 0; }
goto P_0c083aec;
P_0c083aec: /* original a09c, guest PC 0x0c083aec */
if(!s->budget--) { s->failed_pc=0x0c083aecu; return 0; }
goto P_0c083c28;
P_0c083aee: /* original 0009, guest PC 0x0c083aee */
if(!s->budget--) { s->failed_pc=0x0c083aeeu; return 0; }
goto P_0c083af0;
P_0c083af0: /* original 9028, guest PC 0x0c083af0 */
if(!s->budget--) { s->failed_pc=0x0c083af0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c083b44u,2);
goto P_0c083af2;
P_0c083af2: /* original 02ee, guest PC 0x0c083af2 */
if(!s->budget--) { s->failed_pc=0x0c083af2u; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c083af4;
P_0c083af4: /* original 3d20, guest PC 0x0c083af4 */
if(!s->budget--) { s->failed_pc=0x0c083af4u; return 0; }
r[17]=(r[17]&~1u)|((r[13]==r[2])!=0);
goto P_0c083af6;
P_0c083af6: /* original 8b0d, guest PC 0x0c083af6 */
if(!s->budget--) { s->failed_pc=0x0c083af6u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c083b14; }
goto P_0c083af8;
P_0c083af8: /* original d215, guest PC 0x0c083af8 */
if(!s->budget--) { s->failed_pc=0x0c083af8u; return 0; }
r[2]=read(ram,0x0c083b50u,4);
goto P_0c083afa;
P_0c083afa: /* original e512, guest PC 0x0c083afa */
if(!s->budget--) { s->failed_pc=0x0c083afau; return 0; }
r[5]=0x00000012u;
goto P_0c083afc;
P_0c083afc: /* original 9623, guest PC 0x0c083afc */
if(!s->budget--) { s->failed_pc=0x0c083afcu; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c083b46u,2);
goto P_0c083afe;
P_0c083afe: /* original 420b, guest PC 0x0c083afe */
if(!s->budget--) { s->failed_pc=0x0c083afeu; return 0; }
target=r[2];
r[16]=code_base|0x0c083b02u;
r[4]=0x00000010u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c083b02u) { target=s->pc; goto dispatch; }
goto P_0c083b02;
P_0c083b00: /* original e410, guest PC 0x0c083b00 */
if(!s->budget--) { s->failed_pc=0x0c083b00u; return 0; }
r[4]=0x00000010u;
goto P_0c083b02;
P_0c083b02: /* original d313, guest PC 0x0c083b02 */
if(!s->budget--) { s->failed_pc=0x0c083b02u; return 0; }
r[3]=read(ram,0x0c083b50u,4);
goto P_0c083b04;
P_0c083b04: /* original e513, guest PC 0x0c083b04 */
if(!s->budget--) { s->failed_pc=0x0c083b04u; return 0; }
r[5]=0x00000013u;
goto P_0c083b06;
P_0c083b06: /* original 66b3, guest PC 0x0c083b06 */
if(!s->budget--) { s->failed_pc=0x0c083b06u; return 0; }
r[6]=r[11];
goto P_0c083b08;
P_0c083b08: /* original 430b, guest PC 0x0c083b08 */
if(!s->budget--) { s->failed_pc=0x0c083b08u; return 0; }
target=r[3];
r[16]=code_base|0x0c083b0cu;
r[4]=0x0000001du;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c083b0cu) { target=s->pc; goto dispatch; }
goto P_0c083b0c;
P_0c083b0a: /* original e41d, guest PC 0x0c083b0a */
if(!s->budget--) { s->failed_pc=0x0c083b0au; return 0; }
r[4]=0x0000001du;
goto P_0c083b0c;
P_0c083b0c: /* original e513, guest PC 0x0c083b0c */
if(!s->budget--) { s->failed_pc=0x0c083b0cu; return 0; }
r[5]=0x00000013u;
goto P_0c083b0e;
P_0c083b0e: /* original 66a3, guest PC 0x0c083b0e */
if(!s->budget--) { s->failed_pc=0x0c083b0eu; return 0; }
r[6]=r[10];
goto P_0c083b10;
P_0c083b10: /* original a003, guest PC 0x0c083b10 */
if(!s->budget--) { s->failed_pc=0x0c083b10u; return 0; }
r[4]=0x00000038u;
goto P_0c083b1a;
P_0c083b12: /* original e438, guest PC 0x0c083b12 */
if(!s->budget--) { s->failed_pc=0x0c083b12u; return 0; }
r[4]=0x00000038u;
goto P_0c083b14;
P_0c083b14: /* original 9618, guest PC 0x0c083b14 */
if(!s->budget--) { s->failed_pc=0x0c083b14u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c083b48u,2);
goto P_0c083b16;
P_0c083b16: /* original e410, guest PC 0x0c083b16 */
if(!s->budget--) { s->failed_pc=0x0c083b16u; return 0; }
r[4]=0x00000010u;
goto P_0c083b18;
P_0c083b18: /* original e512, guest PC 0x0c083b18 */
if(!s->budget--) { s->failed_pc=0x0c083b18u; return 0; }
r[5]=0x00000012u;
goto P_0c083b1a;
P_0c083b1a: /* original d20d, guest PC 0x0c083b1a */
if(!s->budget--) { s->failed_pc=0x0c083b1au; return 0; }
r[2]=read(ram,0x0c083b50u,4);
goto P_0c083b1c;
P_0c083b1c: /* original 420b, guest PC 0x0c083b1c */
if(!s->budget--) { s->failed_pc=0x0c083b1cu; return 0; }
target=r[2];
r[16]=code_base|0x0c083b20u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c083b20u) { target=s->pc; goto dispatch; }
goto P_0c083b20;
P_0c083b1e: /* original 0009, guest PC 0x0c083b1e */
if(!s->budget--) { s->failed_pc=0x0c083b1eu; return 0; }
goto P_0c083b20;
P_0c083b20: /* original 9014, guest PC 0x0c083b20 */
if(!s->budget--) { s->failed_pc=0x0c083b20u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c083b4cu,2);
goto P_0c083b22;
P_0c083b22: /* original 9c12, guest PC 0x0c083b22 */
if(!s->budget--) { s->failed_pc=0x0c083b22u; return 0; }
r[12]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c083b4au,2);
goto P_0c083b24;
P_0c083b24: /* original 03ee, guest PC 0x0c083b24 */
if(!s->budget--) { s->failed_pc=0x0c083b24u; return 0; }
r[3]=read(ram,r[14]+r[0],4);
goto P_0c083b26;
P_0c083b26: /* original 6233, guest PC 0x0c083b26 */
if(!s->budget--) { s->failed_pc=0x0c083b26u; return 0; }
r[2]=r[3];
goto P_0c083b28;
P_0c083b28: /* original 2f32, guest PC 0x0c083b28 */
if(!s->budget--) { s->failed_pc=0x0c083b28u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c083b2a;
P_0c083b2a: /* original 4300, guest PC 0x0c083b2a */
if(!s->budget--) { s->failed_pc=0x0c083b2au; return 0; }
r[17]=(r[17]&~1u)|((r[3]>>31)!=0);
r[3]<<=1;
goto P_0c083b2c;
P_0c083b2c: /* original d011, guest PC 0x0c083b2c */
if(!s->budget--) { s->failed_pc=0x0c083b2cu; return 0; }
r[0]=read(ram,0x0c083b74u,4);
goto P_0c083b2e;
P_0c083b2e: /* original 332c, guest PC 0x0c083b2e */
if(!s->budget--) { s->failed_pc=0x0c083b2eu; return 0; }
r[3]+=r[2];
goto P_0c083b30;
P_0c083b30: /* original 4308, guest PC 0x0c083b30 */
if(!s->budget--) { s->failed_pc=0x0c083b30u; return 0; }
r[3]<<=2;
goto P_0c083b32;
P_0c083b32: /* original 013e, guest PC 0x0c083b32 */
if(!s->budget--) { s->failed_pc=0x0c083b32u; return 0; }
r[1]=read(ram,r[3]+r[0],4);
goto P_0c083b34;
P_0c083b34: /* original 2f16, guest PC 0x0c083b34 */
if(!s->budget--) { s->failed_pc=0x0c083b34u; return 0; }
tmp=r[1]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c083b36;
P_0c083b36: /* original 52f1, guest PC 0x0c083b36 */
if(!s->budget--) { s->failed_pc=0x0c083b36u; return 0; }
r[2]=read(ram,r[15]+4,4);
goto P_0c083b38;
P_0c083b38: /* original a065, guest PC 0x0c083b38 */
if(!s->budget--) { s->failed_pc=0x0c083b38u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c083c06;
P_0c083b3a: /* original 2f26, guest PC 0x0c083b3a */
if(!s->budget--) { s->failed_pc=0x0c083b3au; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
if(!vf3_matrix_family(0x0c083b3cu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c083b3cu; return 0; } return 1;
P_0c083b78: /* original 906d, guest PC 0x0c083b78 */
if(!s->budget--) { s->failed_pc=0x0c083b78u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c083c56u,2);
goto P_0c083b7a;
P_0c083b7a: /* original 02ee, guest PC 0x0c083b7a */
if(!s->budget--) { s->failed_pc=0x0c083b7au; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c083b7c;
P_0c083b7c: /* original 3d20, guest PC 0x0c083b7c */
if(!s->budget--) { s->failed_pc=0x0c083b7cu; return 0; }
r[17]=(r[17]&~1u)|((r[13]==r[2])!=0);
goto P_0c083b7e;
P_0c083b7e: /* original 8b0d, guest PC 0x0c083b7e */
if(!s->budget--) { s->failed_pc=0x0c083b7eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c083b9c; }
goto P_0c083b80;
P_0c083b80: /* original d23b, guest PC 0x0c083b80 */
if(!s->budget--) { s->failed_pc=0x0c083b80u; return 0; }
r[2]=read(ram,0x0c083c70u,4);
goto P_0c083b82;
P_0c083b82: /* original e516, guest PC 0x0c083b82 */
if(!s->budget--) { s->failed_pc=0x0c083b82u; return 0; }
r[5]=0x00000016u;
goto P_0c083b84;
P_0c083b84: /* original 9668, guest PC 0x0c083b84 */
if(!s->budget--) { s->failed_pc=0x0c083b84u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c083c58u,2);
goto P_0c083b86;
P_0c083b86: /* original 420b, guest PC 0x0c083b86 */
if(!s->budget--) { s->failed_pc=0x0c083b86u; return 0; }
target=r[2];
r[16]=code_base|0x0c083b8au;
r[4]=0x00000010u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c083b8au) { target=s->pc; goto dispatch; }
goto P_0c083b8a;
P_0c083b88: /* original e410, guest PC 0x0c083b88 */
if(!s->budget--) { s->failed_pc=0x0c083b88u; return 0; }
r[4]=0x00000010u;
goto P_0c083b8a;
P_0c083b8a: /* original d339, guest PC 0x0c083b8a */
if(!s->budget--) { s->failed_pc=0x0c083b8au; return 0; }
r[3]=read(ram,0x0c083c70u,4);
goto P_0c083b8c;
P_0c083b8c: /* original e517, guest PC 0x0c083b8c */
if(!s->budget--) { s->failed_pc=0x0c083b8cu; return 0; }
r[5]=0x00000017u;
goto P_0c083b8e;
P_0c083b8e: /* original 66b3, guest PC 0x0c083b8e */
if(!s->budget--) { s->failed_pc=0x0c083b8eu; return 0; }
r[6]=r[11];
goto P_0c083b90;
P_0c083b90: /* original 430b, guest PC 0x0c083b90 */
if(!s->budget--) { s->failed_pc=0x0c083b90u; return 0; }
target=r[3];
r[16]=code_base|0x0c083b94u;
r[4]=0x0000001du;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c083b94u) { target=s->pc; goto dispatch; }
goto P_0c083b94;
P_0c083b92: /* original e41d, guest PC 0x0c083b92 */
if(!s->budget--) { s->failed_pc=0x0c083b92u; return 0; }
r[4]=0x0000001du;
goto P_0c083b94;
P_0c083b94: /* original e517, guest PC 0x0c083b94 */
if(!s->budget--) { s->failed_pc=0x0c083b94u; return 0; }
r[5]=0x00000017u;
goto P_0c083b96;
P_0c083b96: /* original 66a3, guest PC 0x0c083b96 */
if(!s->budget--) { s->failed_pc=0x0c083b96u; return 0; }
r[6]=r[10];
goto P_0c083b98;
P_0c083b98: /* original a003, guest PC 0x0c083b98 */
if(!s->budget--) { s->failed_pc=0x0c083b98u; return 0; }
r[4]=0x00000038u;
goto P_0c083ba2;
P_0c083b9a: /* original e438, guest PC 0x0c083b9a */
if(!s->budget--) { s->failed_pc=0x0c083b9au; return 0; }
r[4]=0x00000038u;
goto P_0c083b9c;
P_0c083b9c: /* original 965d, guest PC 0x0c083b9c */
if(!s->budget--) { s->failed_pc=0x0c083b9cu; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c083c5au,2);
goto P_0c083b9e;
P_0c083b9e: /* original e410, guest PC 0x0c083b9e */
if(!s->budget--) { s->failed_pc=0x0c083b9eu; return 0; }
r[4]=0x00000010u;
goto P_0c083ba0;
P_0c083ba0: /* original e516, guest PC 0x0c083ba0 */
if(!s->budget--) { s->failed_pc=0x0c083ba0u; return 0; }
r[5]=0x00000016u;
goto P_0c083ba2;
P_0c083ba2: /* original d233, guest PC 0x0c083ba2 */
if(!s->budget--) { s->failed_pc=0x0c083ba2u; return 0; }
r[2]=read(ram,0x0c083c70u,4);
goto P_0c083ba4;
P_0c083ba4: /* original 420b, guest PC 0x0c083ba4 */
if(!s->budget--) { s->failed_pc=0x0c083ba4u; return 0; }
target=r[2];
r[16]=code_base|0x0c083ba8u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c083ba8u) { target=s->pc; goto dispatch; }
goto P_0c083ba8;
P_0c083ba6: /* original 0009, guest PC 0x0c083ba6 */
if(!s->budget--) { s->failed_pc=0x0c083ba6u; return 0; }
goto P_0c083ba8;
P_0c083ba8: /* original 9059, guest PC 0x0c083ba8 */
if(!s->budget--) { s->failed_pc=0x0c083ba8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c083c5eu,2);
goto P_0c083baa;
P_0c083baa: /* original 9c57, guest PC 0x0c083baa */
if(!s->budget--) { s->failed_pc=0x0c083baau; return 0; }
r[12]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c083c5cu,2);
goto P_0c083bac;
P_0c083bac: /* original 03ee, guest PC 0x0c083bac */
if(!s->budget--) { s->failed_pc=0x0c083bacu; return 0; }
r[3]=read(ram,r[14]+r[0],4);
goto P_0c083bae;
P_0c083bae: /* original 2f32, guest PC 0x0c083bae */
if(!s->budget--) { s->failed_pc=0x0c083baeu; return 0; }
write(ram,r[15],r[3],4);
goto P_0c083bb0;
P_0c083bb0: /* original 4308, guest PC 0x0c083bb0 */
if(!s->budget--) { s->failed_pc=0x0c083bb0u; return 0; }
r[3]<<=2;
goto P_0c083bb2;
P_0c083bb2: /* original d030, guest PC 0x0c083bb2 */
if(!s->budget--) { s->failed_pc=0x0c083bb2u; return 0; }
r[0]=read(ram,0x0c083c74u,4);
goto P_0c083bb4;
P_0c083bb4: /* original 4300, guest PC 0x0c083bb4 */
if(!s->budget--) { s->failed_pc=0x0c083bb4u; return 0; }
r[17]=(r[17]&~1u)|((r[3]>>31)!=0);
r[3]<<=1;
goto P_0c083bb6;
P_0c083bb6: /* original 023e, guest PC 0x0c083bb6 */
if(!s->budget--) { s->failed_pc=0x0c083bb6u; return 0; }
r[2]=read(ram,r[3]+r[0],4);
goto P_0c083bb8;
P_0c083bb8: /* original 2f26, guest PC 0x0c083bb8 */
if(!s->budget--) { s->failed_pc=0x0c083bb8u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c083bba;
P_0c083bba: /* original 51f1, guest PC 0x0c083bba */
if(!s->budget--) { s->failed_pc=0x0c083bbau; return 0; }
r[1]=read(ram,r[15]+4,4);
goto P_0c083bbc;
P_0c083bbc: /* original a023, guest PC 0x0c083bbc */
if(!s->budget--) { s->failed_pc=0x0c083bbcu; return 0; }
tmp=r[1]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c083c06;
P_0c083bbe: /* original 2f16, guest PC 0x0c083bbe */
if(!s->budget--) { s->failed_pc=0x0c083bbeu; return 0; }
tmp=r[1]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c083bc0;
P_0c083bc0: /* original 9049, guest PC 0x0c083bc0 */
if(!s->budget--) { s->failed_pc=0x0c083bc0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c083c56u,2);
goto P_0c083bc2;
P_0c083bc2: /* original 02ee, guest PC 0x0c083bc2 */
if(!s->budget--) { s->failed_pc=0x0c083bc2u; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c083bc4;
P_0c083bc4: /* original 3d20, guest PC 0x0c083bc4 */
if(!s->budget--) { s->failed_pc=0x0c083bc4u; return 0; }
r[17]=(r[17]&~1u)|((r[13]==r[2])!=0);
goto P_0c083bc6;
P_0c083bc6: /* original 8b0d, guest PC 0x0c083bc6 */
if(!s->budget--) { s->failed_pc=0x0c083bc6u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c083be4; }
goto P_0c083bc8;
P_0c083bc8: /* original d229, guest PC 0x0c083bc8 */
if(!s->budget--) { s->failed_pc=0x0c083bc8u; return 0; }
r[2]=read(ram,0x0c083c70u,4);
goto P_0c083bca;
P_0c083bca: /* original e51a, guest PC 0x0c083bca */
if(!s->budget--) { s->failed_pc=0x0c083bcau; return 0; }
r[5]=0x0000001au;
goto P_0c083bcc;
P_0c083bcc: /* original 9648, guest PC 0x0c083bcc */
if(!s->budget--) { s->failed_pc=0x0c083bccu; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c083c60u,2);
goto P_0c083bce;
P_0c083bce: /* original 420b, guest PC 0x0c083bce */
if(!s->budget--) { s->failed_pc=0x0c083bceu; return 0; }
target=r[2];
r[16]=code_base|0x0c083bd2u;
r[4]=0x00000010u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c083bd2u) { target=s->pc; goto dispatch; }
goto P_0c083bd2;
P_0c083bd0: /* original e410, guest PC 0x0c083bd0 */
if(!s->budget--) { s->failed_pc=0x0c083bd0u; return 0; }
r[4]=0x00000010u;
goto P_0c083bd2;
P_0c083bd2: /* original d327, guest PC 0x0c083bd2 */
if(!s->budget--) { s->failed_pc=0x0c083bd2u; return 0; }
r[3]=read(ram,0x0c083c70u,4);
goto P_0c083bd4;
P_0c083bd4: /* original e51b, guest PC 0x0c083bd4 */
if(!s->budget--) { s->failed_pc=0x0c083bd4u; return 0; }
r[5]=0x0000001bu;
goto P_0c083bd6;
P_0c083bd6: /* original 66b3, guest PC 0x0c083bd6 */
if(!s->budget--) { s->failed_pc=0x0c083bd6u; return 0; }
r[6]=r[11];
goto P_0c083bd8;
P_0c083bd8: /* original 430b, guest PC 0x0c083bd8 */
if(!s->budget--) { s->failed_pc=0x0c083bd8u; return 0; }
target=r[3];
r[16]=code_base|0x0c083bdcu;
r[4]=0x0000001du;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c083bdcu) { target=s->pc; goto dispatch; }
goto P_0c083bdc;
P_0c083bda: /* original e41d, guest PC 0x0c083bda */
if(!s->budget--) { s->failed_pc=0x0c083bdau; return 0; }
r[4]=0x0000001du;
goto P_0c083bdc;
P_0c083bdc: /* original e51b, guest PC 0x0c083bdc */
if(!s->budget--) { s->failed_pc=0x0c083bdcu; return 0; }
r[5]=0x0000001bu;
goto P_0c083bde;
P_0c083bde: /* original 66a3, guest PC 0x0c083bde */
if(!s->budget--) { s->failed_pc=0x0c083bdeu; return 0; }
r[6]=r[10];
goto P_0c083be0;
P_0c083be0: /* original a003, guest PC 0x0c083be0 */
if(!s->budget--) { s->failed_pc=0x0c083be0u; return 0; }
r[4]=0x00000038u;
goto P_0c083bea;
P_0c083be2: /* original e438, guest PC 0x0c083be2 */
if(!s->budget--) { s->failed_pc=0x0c083be2u; return 0; }
r[4]=0x00000038u;
goto P_0c083be4;
P_0c083be4: /* original 963d, guest PC 0x0c083be4 */
if(!s->budget--) { s->failed_pc=0x0c083be4u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c083c62u,2);
goto P_0c083be6;
P_0c083be6: /* original e410, guest PC 0x0c083be6 */
if(!s->budget--) { s->failed_pc=0x0c083be6u; return 0; }
r[4]=0x00000010u;
goto P_0c083be8;
P_0c083be8: /* original e51a, guest PC 0x0c083be8 */
if(!s->budget--) { s->failed_pc=0x0c083be8u; return 0; }
r[5]=0x0000001au;
goto P_0c083bea;
P_0c083bea: /* original d221, guest PC 0x0c083bea */
if(!s->budget--) { s->failed_pc=0x0c083beau; return 0; }
r[2]=read(ram,0x0c083c70u,4);
goto P_0c083bec;
P_0c083bec: /* original 420b, guest PC 0x0c083bec */
if(!s->budget--) { s->failed_pc=0x0c083becu; return 0; }
target=r[2];
r[16]=code_base|0x0c083bf0u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c083bf0u) { target=s->pc; goto dispatch; }
goto P_0c083bf0;
P_0c083bee: /* original 0009, guest PC 0x0c083bee */
if(!s->budget--) { s->failed_pc=0x0c083beeu; return 0; }
goto P_0c083bf0;
P_0c083bf0: /* original 9039, guest PC 0x0c083bf0 */
if(!s->budget--) { s->failed_pc=0x0c083bf0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c083c66u,2);
goto P_0c083bf2;
P_0c083bf2: /* original 9c37, guest PC 0x0c083bf2 */
if(!s->budget--) { s->failed_pc=0x0c083bf2u; return 0; }
r[12]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c083c64u,2);
goto P_0c083bf4;
P_0c083bf4: /* original 03ee, guest PC 0x0c083bf4 */
if(!s->budget--) { s->failed_pc=0x0c083bf4u; return 0; }
r[3]=read(ram,r[14]+r[0],4);
goto P_0c083bf6;
P_0c083bf6: /* original 2f32, guest PC 0x0c083bf6 */
if(!s->budget--) { s->failed_pc=0x0c083bf6u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c083bf8;
P_0c083bf8: /* original 4308, guest PC 0x0c083bf8 */
if(!s->budget--) { s->failed_pc=0x0c083bf8u; return 0; }
r[3]<<=2;
goto P_0c083bfa;
P_0c083bfa: /* original d01f, guest PC 0x0c083bfa */
if(!s->budget--) { s->failed_pc=0x0c083bfau; return 0; }
r[0]=read(ram,0x0c083c78u,4);
goto P_0c083bfc;
P_0c083bfc: /* original 4300, guest PC 0x0c083bfc */
if(!s->budget--) { s->failed_pc=0x0c083bfcu; return 0; }
r[17]=(r[17]&~1u)|((r[3]>>31)!=0);
r[3]<<=1;
goto P_0c083bfe;
P_0c083bfe: /* original 023e, guest PC 0x0c083bfe */
if(!s->budget--) { s->failed_pc=0x0c083bfeu; return 0; }
r[2]=read(ram,r[3]+r[0],4);
goto P_0c083c00;
P_0c083c00: /* original 2f26, guest PC 0x0c083c00 */
if(!s->budget--) { s->failed_pc=0x0c083c00u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c083c02;
P_0c083c02: /* original 51f1, guest PC 0x0c083c02 */
if(!s->budget--) { s->failed_pc=0x0c083c02u; return 0; }
r[1]=read(ram,r[15]+4,4);
goto P_0c083c04;
P_0c083c04: /* original 2f16, guest PC 0x0c083c04 */
if(!s->budget--) { s->failed_pc=0x0c083c04u; return 0; }
tmp=r[1]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c083c06;
P_0c083c06: /* original 2f86, guest PC 0x0c083c06 */
if(!s->budget--) { s->failed_pc=0x0c083c06u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c083c08;
P_0c083c08: /* original 490b, guest PC 0x0c083c08 */
if(!s->budget--) { s->failed_pc=0x0c083c08u; return 0; }
target=r[9];
r[16]=code_base|0x0c083c0cu;
r[4]=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c083c0cu) { target=s->pc; goto dispatch; }
goto P_0c083c0c;
P_0c083c0a: /* original 64c3, guest PC 0x0c083c0a */
if(!s->budget--) { s->failed_pc=0x0c083c0au; return 0; }
r[4]=r[12];
goto P_0c083c0c;
P_0c083c0c: /* original a00c, guest PC 0x0c083c0c */
if(!s->budget--) { s->failed_pc=0x0c083c0cu; return 0; }
r[15]+=0x0000000cu;
goto P_0c083c28;
P_0c083c0e: /* original 7f0c, guest PC 0x0c083c0e */
if(!s->budget--) { s->failed_pc=0x0c083c0eu; return 0; }
r[15]+=0x0000000cu;
goto P_0c083c10;
P_0c083c10: /* original 9021, guest PC 0x0c083c10 */
if(!s->budget--) { s->failed_pc=0x0c083c10u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c083c56u,2);
goto P_0c083c12;
P_0c083c12: /* original 02ee, guest PC 0x0c083c12 */
if(!s->budget--) { s->failed_pc=0x0c083c12u; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c083c14;
P_0c083c14: /* original 3d20, guest PC 0x0c083c14 */
if(!s->budget--) { s->failed_pc=0x0c083c14u; return 0; }
r[17]=(r[17]&~1u)|((r[13]==r[2])!=0);
goto P_0c083c16;
P_0c083c16: /* original 8f03, guest PC 0x0c083c16 */
if(!s->budget--) { s->failed_pc=0x0c083c16u; return 0; }
cond=r[17]&1u;
r[5]=0x0000001fu;
if(!cond) { goto P_0c083c20; }
goto P_0c083c1a;
P_0c083c18: /* original e51f, guest PC 0x0c083c18 */
if(!s->budget--) { s->failed_pc=0x0c083c18u; return 0; }
r[5]=0x0000001fu;
goto P_0c083c1a;
P_0c083c1a: /* original 9625, guest PC 0x0c083c1a */
if(!s->budget--) { s->failed_pc=0x0c083c1au; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c083c68u,2);
goto P_0c083c1c;
P_0c083c1c: /* original a001, guest PC 0x0c083c1c */
if(!s->budget--) { s->failed_pc=0x0c083c1cu; return 0; }
goto P_0c083c22;
P_0c083c1e: /* original 0009, guest PC 0x0c083c1e */
if(!s->budget--) { s->failed_pc=0x0c083c1eu; return 0; }
goto P_0c083c20;
P_0c083c20: /* original 9623, guest PC 0x0c083c20 */
if(!s->budget--) { s->failed_pc=0x0c083c20u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c083c6au,2);
goto P_0c083c22;
P_0c083c22: /* original d213, guest PC 0x0c083c22 */
if(!s->budget--) { s->failed_pc=0x0c083c22u; return 0; }
r[2]=read(ram,0x0c083c70u,4);
goto P_0c083c24;
P_0c083c24: /* original 420b, guest PC 0x0c083c24 */
if(!s->budget--) { s->failed_pc=0x0c083c24u; return 0; }
target=r[2];
r[16]=code_base|0x0c083c28u;
r[4]=0x00000010u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c083c28u) { target=s->pc; goto dispatch; }
goto P_0c083c28;
P_0c083c26: /* original e410, guest PC 0x0c083c26 */
if(!s->budget--) { s->failed_pc=0x0c083c26u; return 0; }
r[4]=0x00000010u;
goto P_0c083c28;
P_0c083c28: /* original e204, guest PC 0x0c083c28 */
if(!s->budget--) { s->failed_pc=0x0c083c28u; return 0; }
r[2]=0x00000004u;
goto P_0c083c2a;
P_0c083c2a: /* original 7d01, guest PC 0x0c083c2a */
if(!s->budget--) { s->failed_pc=0x0c083c2au; return 0; }
r[13]+=0x00000001u;
goto P_0c083c2c;
P_0c083c2c: /* original 3d23, guest PC 0x0c083c2c */
if(!s->budget--) { s->failed_pc=0x0c083c2cu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[13]>=(int32_t)r[2])!=0);
goto P_0c083c2e;
P_0c083c2e: /* original 8901, guest PC 0x0c083c2e */
if(!s->budget--) { s->failed_pc=0x0c083c2eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c083c34; }
goto P_0c083c30;
P_0c083c30: /* original af4d, guest PC 0x0c083c30 */
if(!s->budget--) { s->failed_pc=0x0c083c30u; return 0; }
goto P_0c083ace;
P_0c083c32: /* original 0009, guest PC 0x0c083c32 */
if(!s->budget--) { s->failed_pc=0x0c083c32u; return 0; }
goto P_0c083c34;
P_0c083c34: /* original d311, guest PC 0x0c083c34 */
if(!s->budget--) { s->failed_pc=0x0c083c34u; return 0; }
r[3]=read(ram,0x0c083c7cu,4);
goto P_0c083c36;
P_0c083c36: /* original 9519, guest PC 0x0c083c36 */
if(!s->budget--) { s->failed_pc=0x0c083c36u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c083c6cu,2);
goto P_0c083c38;
P_0c083c38: /* original 430b, guest PC 0x0c083c38 */
if(!s->budget--) { s->failed_pc=0x0c083c38u; return 0; }
target=r[3];
r[16]=code_base|0x0c083c3cu;
r[4]=read(ram,r[15]+4,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c083c3cu) { target=s->pc; goto dispatch; }
goto P_0c083c3c;
P_0c083c3a: /* original 54f1, guest PC 0x0c083c3a */
if(!s->budget--) { s->failed_pc=0x0c083c3au; return 0; }
r[4]=read(ram,r[15]+4,4);
goto P_0c083c3c;
P_0c083c3c: /* original 54f2, guest PC 0x0c083c3c */
if(!s->budget--) { s->failed_pc=0x0c083c3cu; return 0; }
r[4]=read(ram,r[15]+8,4);
goto P_0c083c3e;
P_0c083c3e: /* original 7f0c, guest PC 0x0c083c3e */
if(!s->budget--) { s->failed_pc=0x0c083c3eu; return 0; }
r[15]+=0x0000000cu;
goto P_0c083c40;
P_0c083c40: /* original 4f26, guest PC 0x0c083c40 */
if(!s->budget--) { s->failed_pc=0x0c083c40u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c083c42;
P_0c083c42: /* original 65c3, guest PC 0x0c083c42 */
if(!s->budget--) { s->failed_pc=0x0c083c42u; return 0; }
r[5]=r[12];
goto P_0c083c44;
P_0c083c44: /* original d30e, guest PC 0x0c083c44 */
if(!s->budget--) { s->failed_pc=0x0c083c44u; return 0; }
r[3]=read(ram,0x0c083c80u,4);
goto P_0c083c46;
P_0c083c46: /* original 68f6, guest PC 0x0c083c46 */
if(!s->budget--) { s->failed_pc=0x0c083c46u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c083c48;
P_0c083c48: /* original 69f6, guest PC 0x0c083c48 */
if(!s->budget--) { s->failed_pc=0x0c083c48u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c083c4a;
P_0c083c4a: /* original 6af6, guest PC 0x0c083c4a */
if(!s->budget--) { s->failed_pc=0x0c083c4au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c083c4c;
P_0c083c4c: /* original 6bf6, guest PC 0x0c083c4c */
if(!s->budget--) { s->failed_pc=0x0c083c4cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c083c4e;
P_0c083c4e: /* original 6cf6, guest PC 0x0c083c4e */
if(!s->budget--) { s->failed_pc=0x0c083c4eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c083c50;
P_0c083c50: /* original 6df6, guest PC 0x0c083c50 */
if(!s->budget--) { s->failed_pc=0x0c083c50u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c083c52;
P_0c083c52: /* original 432b, guest PC 0x0c083c52 */
if(!s->budget--) { s->failed_pc=0x0c083c52u; return 0; }
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
P_0c083c54: /* original 6ef6, guest PC 0x0c083c54 */
if(!s->budget--) { s->failed_pc=0x0c083c54u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c083c56u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c083c56u; return 0; } return 1;
P_0c083d66: /* original 2fe6, guest PC 0x0c083d66 */
if(!s->budget--) { s->failed_pc=0x0c083d66u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c083d68;
P_0c083d68: /* original 6e43, guest PC 0x0c083d68 */
if(!s->budget--) { s->failed_pc=0x0c083d68u; return 0; }
r[14]=r[4];
goto P_0c083d6a;
P_0c083d6a: /* original 2fd6, guest PC 0x0c083d6a */
if(!s->budget--) { s->failed_pc=0x0c083d6au; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c083d6c;
P_0c083d6c: /* original 2fc6, guest PC 0x0c083d6c */
if(!s->budget--) { s->failed_pc=0x0c083d6cu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c083d6e;
P_0c083d6e: /* original 2fb6, guest PC 0x0c083d6e */
if(!s->budget--) { s->failed_pc=0x0c083d6eu; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c083d70;
P_0c083d70: /* original 4f22, guest PC 0x0c083d70 */
if(!s->budget--) { s->failed_pc=0x0c083d70u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c083d72;
P_0c083d72: /* original dc1b, guest PC 0x0c083d72 */
if(!s->budget--) { s->failed_pc=0x0c083d72u; return 0; }
r[12]=read(ram,0x0c083de0u,4);
goto P_0c083d74;
P_0c083d74: /* original db17, guest PC 0x0c083d74 */
if(!s->budget--) { s->failed_pc=0x0c083d74u; return 0; }
r[11]=read(ram,0x0c083dd4u,4);
goto P_0c083d76;
P_0c083d76: /* original a00e, guest PC 0x0c083d76 */
if(!s->budget--) { s->failed_pc=0x0c083d76u; return 0; }
r[13]=0x00000000u;
goto P_0c083d96;
P_0c083d78: /* original ed00, guest PC 0x0c083d78 */
if(!s->budget--) { s->failed_pc=0x0c083d78u; return 0; }
r[13]=0x00000000u;
goto P_0c083d7a;
P_0c083d7a: /* original 85e1, guest PC 0x0c083d7a */
if(!s->budget--) { s->failed_pc=0x0c083d7au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+2,2);
goto P_0c083d7c;
P_0c083d7c: /* original e307, guest PC 0x0c083d7c */
if(!s->budget--) { s->failed_pc=0x0c083d7cu; return 0; }
r[3]=0x00000007u;
goto P_0c083d7e;
P_0c083d7e: /* original 64e1, guest PC 0x0c083d7e */
if(!s->budget--) { s->failed_pc=0x0c083d7eu; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[14],2);
r[4]=tmp;
goto P_0c083d80;
P_0c083d80: /* original 66c3, guest PC 0x0c083d80 */
if(!s->budget--) { s->failed_pc=0x0c083d80u; return 0; }
r[6]=r[12];
goto P_0c083d82;
P_0c083d82: /* original 403c, guest PC 0x0c083d82 */
if(!s->budget--) { s->failed_pc=0x0c083d82u; return 0; }
r[0]=(r[3]&0x80000000u)?((r[3]&31u)?(uint32_t)((int32_t)r[0]>>((-r[3])&31u)):((int32_t)r[0]<0?0xffffffffu:0)):r[0]<<(r[3]&31u);
goto P_0c083d84;
P_0c083d84: /* original 2fd6, guest PC 0x0c083d84 */
if(!s->budget--) { s->failed_pc=0x0c083d84u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c083d86;
P_0c083d86: /* original 4400, guest PC 0x0c083d86 */
if(!s->budget--) { s->failed_pc=0x0c083d86u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c083d88;
P_0c083d88: /* original 240b, guest PC 0x0c083d88 */
if(!s->budget--) { s->failed_pc=0x0c083d88u; return 0; }
r[4]|=r[0];
goto P_0c083d8a;
P_0c083d8a: /* original 85e2, guest PC 0x0c083d8a */
if(!s->budget--) { s->failed_pc=0x0c083d8au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+4,2);
goto P_0c083d8c;
P_0c083d8c: /* original e700, guest PC 0x0c083d8c */
if(!s->budget--) { s->failed_pc=0x0c083d8cu; return 0; }
r[7]=0x00000000u;
goto P_0c083d8e;
P_0c083d8e: /* original 4b0b, guest PC 0x0c083d8e */
if(!s->budget--) { s->failed_pc=0x0c083d8eu; return 0; }
target=r[11];
r[16]=code_base|0x0c083d92u;
r[5]=r[0];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c083d92u) { target=s->pc; goto dispatch; }
goto P_0c083d92;
P_0c083d90: /* original 6503, guest PC 0x0c083d90 */
if(!s->budget--) { s->failed_pc=0x0c083d90u; return 0; }
r[5]=r[0];
goto P_0c083d92;
P_0c083d92: /* original 7e06, guest PC 0x0c083d92 */
if(!s->budget--) { s->failed_pc=0x0c083d92u; return 0; }
r[14]+=0x00000006u;
goto P_0c083d94;
P_0c083d94: /* original 7f04, guest PC 0x0c083d94 */
if(!s->budget--) { s->failed_pc=0x0c083d94u; return 0; }
r[15]+=0x00000004u;
goto P_0c083d96;
P_0c083d96: /* original 63e1, guest PC 0x0c083d96 */
if(!s->budget--) { s->failed_pc=0x0c083d96u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[14],2);
r[3]=tmp;
goto P_0c083d98;
P_0c083d98: /* original 4311, guest PC 0x0c083d98 */
if(!s->budget--) { s->failed_pc=0x0c083d98u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>=0)!=0);
goto P_0c083d9a;
P_0c083d9a: /* original 89ee, guest PC 0x0c083d9a */
if(!s->budget--) { s->failed_pc=0x0c083d9au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c083d7a; }
goto P_0c083d9c;
P_0c083d9c: /* original 4f26, guest PC 0x0c083d9c */
if(!s->budget--) { s->failed_pc=0x0c083d9cu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c083d9e;
P_0c083d9e: /* original 6bf6, guest PC 0x0c083d9e */
if(!s->budget--) { s->failed_pc=0x0c083d9eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c083da0;
P_0c083da0: /* original 6cf6, guest PC 0x0c083da0 */
if(!s->budget--) { s->failed_pc=0x0c083da0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c083da2;
P_0c083da2: /* original 6df6, guest PC 0x0c083da2 */
if(!s->budget--) { s->failed_pc=0x0c083da2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c083da4;
P_0c083da4: /* original 000b, guest PC 0x0c083da4 */
if(!s->budget--) { s->failed_pc=0x0c083da4u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c083da6: /* original 6ef6, guest PC 0x0c083da6 */
if(!s->budget--) { s->failed_pc=0x0c083da6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c083da8u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c083da8u; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
