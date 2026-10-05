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
int vf3_advance_medium_adapter(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
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
case 0x0c08af6cu: goto P_0c08af6c;
case 0x0c08af6eu: goto P_0c08af6e;
case 0x0c08af70u: goto P_0c08af70;
case 0x0c08af72u: goto P_0c08af72;
case 0x0c08af74u: goto P_0c08af74;
case 0x0c08af76u: goto P_0c08af76;
case 0x0c08af78u: goto P_0c08af78;
case 0x0c08af7au: goto P_0c08af7a;
case 0x0c08af7cu: goto P_0c08af7c;
case 0x0c08af7eu: goto P_0c08af7e;
case 0x0c08af80u: goto P_0c08af80;
case 0x0c08af82u: goto P_0c08af82;
case 0x0c08af84u: goto P_0c08af84;
case 0x0c08af86u: goto P_0c08af86;
case 0x0c08af88u: goto P_0c08af88;
case 0x0c08af8au: goto P_0c08af8a;
case 0x0c08af8cu: goto P_0c08af8c;
case 0x0c08af8eu: goto P_0c08af8e;
case 0x0c08af90u: goto P_0c08af90;
case 0x0c08af92u: goto P_0c08af92;
case 0x0c08af94u: goto P_0c08af94;
case 0x0c08af96u: goto P_0c08af96;
case 0x0c08af98u: goto P_0c08af98;
case 0x0c08af9au: goto P_0c08af9a;
case 0x0c08af9cu: goto P_0c08af9c;
case 0x0c08af9eu: goto P_0c08af9e;
case 0x0c08afa0u: goto P_0c08afa0;
case 0x0c08afa2u: goto P_0c08afa2;
case 0x0c08afa4u: goto P_0c08afa4;
case 0x0c08afa6u: goto P_0c08afa6;
case 0x0c08afa8u: goto P_0c08afa8;
case 0x0c08afaau: goto P_0c08afaa;
case 0x0c08afacu: goto P_0c08afac;
case 0x0c08afaeu: goto P_0c08afae;
case 0x0c08afb0u: goto P_0c08afb0;
case 0x0c08aff4u: goto P_0c08aff4;
case 0x0c08aff6u: goto P_0c08aff6;
case 0x0c08aff8u: goto P_0c08aff8;
case 0x0c08affau: goto P_0c08affa;
case 0x0c08affcu: goto P_0c08affc;
case 0x0c08affeu: goto P_0c08affe;
case 0x0c08b000u: goto P_0c08b000;
case 0x0c08b002u: goto P_0c08b002;
case 0x0c08b004u: goto P_0c08b004;
case 0x0c08b006u: goto P_0c08b006;
case 0x0c08b008u: goto P_0c08b008;
case 0x0c08b00au: goto P_0c08b00a;
case 0x0c08b00cu: goto P_0c08b00c;
case 0x0c08b00eu: goto P_0c08b00e;
case 0x0c08b010u: goto P_0c08b010;
case 0x0c08b012u: goto P_0c08b012;
case 0x0c08b014u: goto P_0c08b014;
case 0x0c08b016u: goto P_0c08b016;
case 0x0c08b018u: goto P_0c08b018;
case 0x0c08b01au: goto P_0c08b01a;
case 0x0c08b01cu: goto P_0c08b01c;
case 0x0c08b01eu: goto P_0c08b01e;
case 0x0c08b020u: goto P_0c08b020;
case 0x0c08b022u: goto P_0c08b022;
case 0x0c08b024u: goto P_0c08b024;
case 0x0c08b026u: goto P_0c08b026;
case 0x0c08b028u: goto P_0c08b028;
case 0x0c08b02au: goto P_0c08b02a;
case 0x0c08b02cu: goto P_0c08b02c;
case 0x0c08b02eu: goto P_0c08b02e;
case 0x0c08b030u: goto P_0c08b030;
case 0x0c08b032u: goto P_0c08b032;
case 0x0c08b034u: goto P_0c08b034;
case 0x0c08b036u: goto P_0c08b036;
case 0x0c08b038u: goto P_0c08b038;
case 0x0c08b03au: goto P_0c08b03a;
case 0x0c08b03cu: goto P_0c08b03c;
case 0x0c08b03eu: goto P_0c08b03e;
case 0x0c08b040u: goto P_0c08b040;
case 0x0c08b042u: goto P_0c08b042;
case 0x0c08b044u: goto P_0c08b044;
case 0x0c08b046u: goto P_0c08b046;
case 0x0c08b048u: goto P_0c08b048;
case 0x0c08b04au: goto P_0c08b04a;
case 0x0c08b04cu: goto P_0c08b04c;
case 0x0c08b04eu: goto P_0c08b04e;
case 0x0c08b050u: goto P_0c08b050;
case 0x0c08b052u: goto P_0c08b052;
case 0x0c08b054u: goto P_0c08b054;
case 0x0c08b056u: goto P_0c08b056;
case 0x0c08b058u: goto P_0c08b058;
case 0x0c08b05au: goto P_0c08b05a;
case 0x0c08b05cu: goto P_0c08b05c;
case 0x0c08b05eu: goto P_0c08b05e;
case 0x0c08b060u: goto P_0c08b060;
case 0x0c08b062u: goto P_0c08b062;
case 0x0c08b064u: goto P_0c08b064;
case 0x0c08b066u: goto P_0c08b066;
case 0x0c08b068u: goto P_0c08b068;
case 0x0c08b06au: goto P_0c08b06a;
case 0x0c08b06cu: goto P_0c08b06c;
case 0x0c08b06eu: goto P_0c08b06e;
case 0x0c08b070u: goto P_0c08b070;
case 0x0c08b072u: goto P_0c08b072;
case 0x0c08b074u: goto P_0c08b074;
case 0x0c08b076u: goto P_0c08b076;
case 0x0c08b078u: goto P_0c08b078;
case 0x0c08b07au: goto P_0c08b07a;
case 0x0c08b07cu: goto P_0c08b07c;
case 0x0c08b07eu: goto P_0c08b07e;
case 0x0c08b080u: goto P_0c08b080;
case 0x0c08b082u: goto P_0c08b082;
case 0x0c08b084u: goto P_0c08b084;
case 0x0c08b086u: goto P_0c08b086;
case 0x0c08b088u: goto P_0c08b088;
case 0x0c08b08au: goto P_0c08b08a;
case 0x0c08b08cu: goto P_0c08b08c;
case 0x0c08b08eu: goto P_0c08b08e;
case 0x0c08b090u: goto P_0c08b090;
case 0x0c08b092u: goto P_0c08b092;
case 0x0c08b094u: goto P_0c08b094;
case 0x0c08b096u: goto P_0c08b096;
case 0x0c08b098u: goto P_0c08b098;
case 0x0c08b09au: goto P_0c08b09a;
case 0x0c08b09cu: goto P_0c08b09c;
case 0x0c08b09eu: goto P_0c08b09e;
case 0x0c08b0a0u: goto P_0c08b0a0;
case 0x0c08b0a2u: goto P_0c08b0a2;
case 0x0c08b0a4u: goto P_0c08b0a4;
case 0x0c08b0a6u: goto P_0c08b0a6;
case 0x0c08b0a8u: goto P_0c08b0a8;
case 0x0c08b0aau: goto P_0c08b0aa;
case 0x0c08b0acu: goto P_0c08b0ac;
case 0x0c08b0aeu: goto P_0c08b0ae;
case 0x0c08b0b0u: goto P_0c08b0b0;
case 0x0c08b0b2u: goto P_0c08b0b2;
case 0x0c08b0b4u: goto P_0c08b0b4;
case 0x0c08b0b6u: goto P_0c08b0b6;
case 0x0c08b0b8u: goto P_0c08b0b8;
case 0x0c08b0bau: goto P_0c08b0ba;
case 0x0c08b0bcu: goto P_0c08b0bc;
case 0x0c08b0beu: goto P_0c08b0be;
case 0x0c08b0c0u: goto P_0c08b0c0;
case 0x0c08b0c2u: goto P_0c08b0c2;
case 0x0c08b0c4u: goto P_0c08b0c4;
case 0x0c08b0c6u: goto P_0c08b0c6;
case 0x0c08b0c8u: goto P_0c08b0c8;
case 0x0c08b0cau: goto P_0c08b0ca;
case 0x0c08b0ccu: goto P_0c08b0cc;
case 0x0c08b0ceu: goto P_0c08b0ce;
case 0x0c08b0d0u: goto P_0c08b0d0;
case 0x0c08b0d2u: goto P_0c08b0d2;
case 0x0c08b0d4u: goto P_0c08b0d4;
case 0x0c08b0d6u: goto P_0c08b0d6;
case 0x0c08b0d8u: goto P_0c08b0d8;
case 0x0c08b0dau: goto P_0c08b0da;
case 0x0c08b0dcu: goto P_0c08b0dc;
case 0x0c08b0deu: goto P_0c08b0de;
case 0x0c08b0e0u: goto P_0c08b0e0;
case 0x0c08b0e2u: goto P_0c08b0e2;
case 0x0c08b0e4u: goto P_0c08b0e4;
case 0x0c08b0e6u: goto P_0c08b0e6;
case 0x0c08b0e8u: goto P_0c08b0e8;
case 0x0c08b0eau: goto P_0c08b0ea;
case 0x0c08b0ecu: goto P_0c08b0ec;
case 0x0c08b0eeu: goto P_0c08b0ee;
case 0x0c08b0f0u: goto P_0c08b0f0;
case 0x0c08b0f2u: goto P_0c08b0f2;
case 0x0c08b0f4u: goto P_0c08b0f4;
case 0x0c08b0f6u: goto P_0c08b0f6;
case 0x0c08b0f8u: goto P_0c08b0f8;
case 0x0c08b0fau: goto P_0c08b0fa;
case 0x0c08b0fcu: goto P_0c08b0fc;
case 0x0c08b0feu: goto P_0c08b0fe;
case 0x0c08b100u: goto P_0c08b100;
case 0x0c08b102u: goto P_0c08b102;
case 0x0c08b104u: goto P_0c08b104;
case 0x0c08b106u: goto P_0c08b106;
case 0x0c08b108u: goto P_0c08b108;
case 0x0c08b10au: goto P_0c08b10a;
case 0x0c08b10cu: goto P_0c08b10c;
case 0x0c08b10eu: goto P_0c08b10e;
case 0x0c08b110u: goto P_0c08b110;
case 0x0c08b112u: goto P_0c08b112;
case 0x0c08b114u: goto P_0c08b114;
case 0x0c08b116u: goto P_0c08b116;
case 0x0c08b118u: goto P_0c08b118;
case 0x0c08b11au: goto P_0c08b11a;
case 0x0c08ef62u: goto P_0c08ef62;
case 0x0c08ef64u: goto P_0c08ef64;
case 0x0c08ef66u: goto P_0c08ef66;
case 0x0c08ef68u: goto P_0c08ef68;
case 0x0c08ef6au: goto P_0c08ef6a;
case 0x0c08ef6cu: goto P_0c08ef6c;
case 0x0c08ef6eu: goto P_0c08ef6e;
case 0x0c08ef70u: goto P_0c08ef70;
case 0x0c08ef72u: goto P_0c08ef72;
case 0x0c08ef74u: goto P_0c08ef74;
case 0x0c08ef76u: goto P_0c08ef76;
case 0x0c08ef78u: goto P_0c08ef78;
case 0x0c08ef7au: goto P_0c08ef7a;
case 0x0c08ef7cu: goto P_0c08ef7c;
case 0x0c08ef7eu: goto P_0c08ef7e;
case 0x0c08ef80u: goto P_0c08ef80;
case 0x0c08ef82u: goto P_0c08ef82;
case 0x0c08ef84u: goto P_0c08ef84;
case 0x0c08ef86u: goto P_0c08ef86;
case 0x0c08ef88u: goto P_0c08ef88;
case 0x0c08ef8au: goto P_0c08ef8a;
case 0x0c08ef8cu: goto P_0c08ef8c;
case 0x0c08ef8eu: goto P_0c08ef8e;
case 0x0c08ef90u: goto P_0c08ef90;
case 0x0c08ef92u: goto P_0c08ef92;
case 0x0c08ef94u: goto P_0c08ef94;
case 0x0c08ef96u: goto P_0c08ef96;
case 0x0c08ef98u: goto P_0c08ef98;
case 0x0c08ef9au: goto P_0c08ef9a;
case 0x0c08ef9cu: goto P_0c08ef9c;
case 0x0c08ef9eu: goto P_0c08ef9e;
case 0x0c08efa0u: goto P_0c08efa0;
case 0x0c08efa2u: goto P_0c08efa2;
case 0x0c08efa4u: goto P_0c08efa4;
case 0x0c08efa6u: goto P_0c08efa6;
case 0x0c08efa8u: goto P_0c08efa8;
case 0x0c08efaau: goto P_0c08efaa;
case 0x0c08efacu: goto P_0c08efac;
case 0x0c08efaeu: goto P_0c08efae;
case 0x0c08efb0u: goto P_0c08efb0;
case 0x0c08efb2u: goto P_0c08efb2;
case 0x0c08efb4u: goto P_0c08efb4;
case 0x0c08efb6u: goto P_0c08efb6;
case 0x0c08efb8u: goto P_0c08efb8;
case 0x0c08efbau: goto P_0c08efba;
case 0x0c08efbcu: goto P_0c08efbc;
case 0x0c08efbeu: goto P_0c08efbe;
case 0x0c08efc0u: goto P_0c08efc0;
case 0x0c08efc2u: goto P_0c08efc2;
case 0x0c08efc4u: goto P_0c08efc4;
case 0x0c08efc6u: goto P_0c08efc6;
case 0x0c08efc8u: goto P_0c08efc8;
case 0x0c08efcau: goto P_0c08efca;
case 0x0c08efccu: goto P_0c08efcc;
case 0x0c08efceu: goto P_0c08efce;
case 0x0c08efd0u: goto P_0c08efd0;
case 0x0c08efd2u: goto P_0c08efd2;
case 0x0c08efd4u: goto P_0c08efd4;
case 0x0c08efd6u: goto P_0c08efd6;
case 0x0c08efd8u: goto P_0c08efd8;
case 0x0c08efdau: goto P_0c08efda;
case 0x0c08efdcu: goto P_0c08efdc;
case 0x0c08efdeu: goto P_0c08efde;
case 0x0c08efe0u: goto P_0c08efe0;
case 0x0c08efe2u: goto P_0c08efe2;
case 0x0c08efe4u: goto P_0c08efe4;
case 0x0c08efe6u: goto P_0c08efe6;
case 0x0c08efe8u: goto P_0c08efe8;
case 0x0c08efeau: goto P_0c08efea;
case 0x0c08efecu: goto P_0c08efec;
case 0x0c08efeeu: goto P_0c08efee;
case 0x0c08eff0u: goto P_0c08eff0;
case 0x0c08eff2u: goto P_0c08eff2;
case 0x0c08eff4u: goto P_0c08eff4;
case 0x0c08eff6u: goto P_0c08eff6;
case 0x0c08eff8u: goto P_0c08eff8;
case 0x0c08effau: goto P_0c08effa;
case 0x0c08effcu: goto P_0c08effc;
case 0x0c08effeu: goto P_0c08effe;
case 0x0c08f000u: goto P_0c08f000;
case 0x0c08f002u: goto P_0c08f002;
case 0x0c08f004u: goto P_0c08f004;
case 0x0c08f006u: goto P_0c08f006;
case 0x0c08f008u: goto P_0c08f008;
case 0x0c08f00au: goto P_0c08f00a;
case 0x0c08f00cu: goto P_0c08f00c;
case 0x0c08f00eu: goto P_0c08f00e;
case 0x0c08f010u: goto P_0c08f010;
case 0x0c08f012u: goto P_0c08f012;
case 0x0c08f014u: goto P_0c08f014;
case 0x0c08f016u: goto P_0c08f016;
case 0x0c08f018u: goto P_0c08f018;
case 0x0c08f01au: goto P_0c08f01a;
case 0x0c08f01cu: goto P_0c08f01c;
case 0x0c08f01eu: goto P_0c08f01e;
case 0x0c08f020u: goto P_0c08f020;
case 0x0c08f022u: goto P_0c08f022;
case 0x0c08f024u: goto P_0c08f024;
case 0x0c08f026u: goto P_0c08f026;
case 0x0c08f028u: goto P_0c08f028;
case 0x0c08f02au: goto P_0c08f02a;
case 0x0c08f02cu: goto P_0c08f02c;
case 0x0c08f02eu: goto P_0c08f02e;
case 0x0c08f030u: goto P_0c08f030;
case 0x0c08f032u: goto P_0c08f032;
case 0x0c08f034u: goto P_0c08f034;
case 0x0c08f036u: goto P_0c08f036;
case 0x0c08f038u: goto P_0c08f038;
case 0x0c08f03au: goto P_0c08f03a;
case 0x0c08f03cu: goto P_0c08f03c;
case 0x0c08f03eu: goto P_0c08f03e;
case 0x0c08f040u: goto P_0c08f040;
case 0x0c08f042u: goto P_0c08f042;
case 0x0c08f044u: goto P_0c08f044;
case 0x0c08f046u: goto P_0c08f046;
case 0x0c08f048u: goto P_0c08f048;
case 0x0c08f04au: goto P_0c08f04a;
case 0x0c08f04cu: goto P_0c08f04c;
case 0x0c08f04eu: goto P_0c08f04e;
case 0x0c08f050u: goto P_0c08f050;
case 0x0c08f052u: goto P_0c08f052;
case 0x0c08f054u: goto P_0c08f054;
case 0x0c08f056u: goto P_0c08f056;
case 0x0c08f058u: goto P_0c08f058;
case 0x0c08f05au: goto P_0c08f05a;
case 0x0c08f05cu: goto P_0c08f05c;
case 0x0c08f05eu: goto P_0c08f05e;
case 0x0c08f060u: goto P_0c08f060;
case 0x0c08f062u: goto P_0c08f062;
case 0x0c08f064u: goto P_0c08f064;
case 0x0c08f066u: goto P_0c08f066;
case 0x0c08f068u: goto P_0c08f068;
case 0x0c08f06au: goto P_0c08f06a;
case 0x0c08f06cu: goto P_0c08f06c;
case 0x0c08f06eu: goto P_0c08f06e;
case 0x0c08f070u: goto P_0c08f070;
case 0x0c08f072u: goto P_0c08f072;
case 0x0c08f074u: goto P_0c08f074;
case 0x0c08f076u: goto P_0c08f076;
case 0x0c08f078u: goto P_0c08f078;
case 0x0c08f07au: goto P_0c08f07a;
case 0x0c08f07cu: goto P_0c08f07c;
case 0x0c08f07eu: goto P_0c08f07e;
case 0x0c08f080u: goto P_0c08f080;
case 0x0c08f082u: goto P_0c08f082;
case 0x0c08f084u: goto P_0c08f084;
case 0x0c08f086u: goto P_0c08f086;
case 0x0c08f088u: goto P_0c08f088;
case 0x0c08f08au: goto P_0c08f08a;
case 0x0c08f08cu: goto P_0c08f08c;
case 0x0c08f08eu: goto P_0c08f08e;
case 0x0c08f090u: goto P_0c08f090;
case 0x0c08f092u: goto P_0c08f092;
case 0x0c08f094u: goto P_0c08f094;
case 0x0c08f096u: goto P_0c08f096;
case 0x0c08f098u: goto P_0c08f098;
case 0x0c08f09au: goto P_0c08f09a;
case 0x0c08f09cu: goto P_0c08f09c;
case 0x0c08f09eu: goto P_0c08f09e;
case 0x0c08f0a0u: goto P_0c08f0a0;
case 0x0c08f0a2u: goto P_0c08f0a2;
case 0x0c08f0a4u: goto P_0c08f0a4;
case 0x0c08f0a6u: goto P_0c08f0a6;
case 0x0c08f0a8u: goto P_0c08f0a8;
case 0x0c08f0aau: goto P_0c08f0aa;
case 0x0c08f0acu: goto P_0c08f0ac;
case 0x0c08f0aeu: goto P_0c08f0ae;
case 0x0c08f0b0u: goto P_0c08f0b0;
case 0x0c08f0b2u: goto P_0c08f0b2;
case 0x0c08f0b4u: goto P_0c08f0b4;
case 0x0c08f0b6u: goto P_0c08f0b6;
case 0x0c08f0b8u: goto P_0c08f0b8;
case 0x0c08f0bau: goto P_0c08f0ba;
case 0x0c08f0bcu: goto P_0c08f0bc;
case 0x0c08f0beu: goto P_0c08f0be;
case 0x0c08f0c0u: goto P_0c08f0c0;
case 0x0c08f0c2u: goto P_0c08f0c2;
case 0x0c08f0c4u: goto P_0c08f0c4;
case 0x0c08f0c6u: goto P_0c08f0c6;
case 0x0c08f0c8u: goto P_0c08f0c8;
case 0x0c08f0cau: goto P_0c08f0ca;
case 0x0c08f0ccu: goto P_0c08f0cc;
case 0x0c08f0ceu: goto P_0c08f0ce;
case 0x0c08f0d0u: goto P_0c08f0d0;
case 0x0c08f0d2u: goto P_0c08f0d2;
case 0x0c08f0d4u: goto P_0c08f0d4;
case 0x0c08f0d6u: goto P_0c08f0d6;
case 0x0c08f0d8u: goto P_0c08f0d8;
case 0x0c08f0dau: goto P_0c08f0da;
case 0x0c08f0dcu: goto P_0c08f0dc;
case 0x0c08f0deu: goto P_0c08f0de;
case 0x0c08f0e0u: goto P_0c08f0e0;
case 0x0c08f0e2u: goto P_0c08f0e2;
case 0x0c08f0e4u: goto P_0c08f0e4;
default: return vf3_matrix_family(target,s,ram);
}
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
r[16]=0x0c081e98u;
r[4]=r[12];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c081e98u) { target=s->pc; goto dispatch; }
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
r[16]=0x0c081eacu;
r[4]=r[12];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c081eacu) { target=s->pc; goto dispatch; }
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
r[16]=0x0c081ec0u;
r[4]=r[12];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c081ec0u) { target=s->pc; goto dispatch; }
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
r[16]=0x0c081ed4u;
r[4]=r[12];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c081ed4u) { target=s->pc; goto dispatch; }
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
r[16]=0x0c081ee8u;
r[4]=r[12];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c081ee8u) { target=s->pc; goto dispatch; }
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
r[16]=0x0c081efcu;
r[4]=r[12];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c081efcu) { target=s->pc; goto dispatch; }
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
r[16]=0x0c081f10u;
r[4]=r[12];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c081f10u) { target=s->pc; goto dispatch; }
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
r[16]=0x0c081f24u;
r[4]=r[12];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c081f24u) { target=s->pc; goto dispatch; }
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
r[16]=0x0c081f38u;
r[4]=r[12];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c081f38u) { target=s->pc; goto dispatch; }
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
r[16]=0x0c081f4cu;
r[4]=r[12];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c081f4cu) { target=s->pc; goto dispatch; }
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
r[16]=0x0c081f60u;
r[4]=r[12];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c081f60u) { target=s->pc; goto dispatch; }
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
r[16]=0x0c081f74u;
r[4]=r[12];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c081f74u) { target=s->pc; goto dispatch; }
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
return vf3_matrix_family(0x0c081f84u,s,ram);
P_0c08af6c: /* original 4f22, guest PC 0x0c08af6c */
if(!s->budget--) { s->failed_pc=0x0c08af6cu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c08af6e;
P_0c08af6e: /* original f3c6, guest PC 0x0c08af6e */
if(!s->budget--) { s->failed_pc=0x0c08af6eu; return 0; }
vf3_matrix_load(s,ram,3,r[12]+r[0]);
goto P_0c08af70;
P_0c08af70: /* original e004, guest PC 0x0c08af70 */
if(!s->budget--) { s->failed_pc=0x0c08af70u; return 0; }
r[0]=0x00000004u;
goto P_0c08af72;
P_0c08af72: /* original 7fd0, guest PC 0x0c08af72 */
if(!s->budget--) { s->failed_pc=0x0c08af72u; return 0; }
r[15]+=0xffffffd0u;
goto P_0c08af74;
P_0c08af74: /* original ff37, guest PC 0x0c08af74 */
if(!s->budget--) { s->failed_pc=0x0c08af74u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c08af76;
P_0c08af76: /* original e02c, guest PC 0x0c08af76 */
if(!s->budget--) { s->failed_pc=0x0c08af76u; return 0; }
r[0]=0x0000002cu;
goto P_0c08af78;
P_0c08af78: /* original dd16, guest PC 0x0c08af78 */
if(!s->budget--) { s->failed_pc=0x0c08af78u; return 0; }
r[13]=read(ram,0x0c08afd4u,4);
goto P_0c08af7a;
P_0c08af7a: /* original fcc6, guest PC 0x0c08af7a */
if(!s->budget--) { s->failed_pc=0x0c08af7au; return 0; }
vf3_matrix_load(s,ram,12,r[12]+r[0]);
goto P_0c08af7c;
P_0c08af7c: /* original e030, guest PC 0x0c08af7c */
if(!s->budget--) { s->failed_pc=0x0c08af7cu; return 0; }
r[0]=0x00000030u;
goto P_0c08af7e;
P_0c08af7e: /* original 4d0b, guest PC 0x0c08af7e */
if(!s->budget--) { s->failed_pc=0x0c08af7eu; return 0; }
target=r[13];
r[16]=0x0c08af82u;
vf3_matrix_load(s,ram,15,r[12]+r[0]);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08af82u) { target=s->pc; goto dispatch; }
goto P_0c08af82;
P_0c08af80: /* original ffc6, guest PC 0x0c08af80 */
if(!s->budget--) { s->failed_pc=0x0c08af80u; return 0; }
vf3_matrix_load(s,ram,15,r[12]+r[0]);
goto P_0c08af82;
P_0c08af82: /* original f6fc, guest PC 0x0c08af82 */
if(!s->budget--) { s->failed_pc=0x0c08af82u; return 0; }
vf3_matrix_move(s,6,15);
goto P_0c08af84;
P_0c08af84: /* original e004, guest PC 0x0c08af84 */
if(!s->budget--) { s->failed_pc=0x0c08af84u; return 0; }
r[0]=0x00000004u;
goto P_0c08af86;
P_0c08af86: /* original de14, guest PC 0x0c08af86 */
if(!s->budget--) { s->failed_pc=0x0c08af86u; return 0; }
r[14]=read(ram,0x0c08afd8u,4);
goto P_0c08af88;
P_0c08af88: /* original f5cc, guest PC 0x0c08af88 */
if(!s->budget--) { s->failed_pc=0x0c08af88u; return 0; }
vf3_matrix_move(s,5,12);
goto P_0c08af8a;
P_0c08af8a: /* original f64d, guest PC 0x0c08af8a */
if(!s->budget--) { s->failed_pc=0x0c08af8au; return 0; }
fr[6]^=0x80000000u;
goto P_0c08af8c;
P_0c08af8c: /* original 4e0b, guest PC 0x0c08af8c */
if(!s->budget--) { s->failed_pc=0x0c08af8cu; return 0; }
target=r[14];
r[16]=0x0c08af90u;
vf3_matrix_load(s,ram,4,r[15]+r[0]);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08af90u) { target=s->pc; goto dispatch; }
goto P_0c08af90;
P_0c08af8e: /* original f4f6, guest PC 0x0c08af8e */
if(!s->budget--) { s->failed_pc=0x0c08af8eu; return 0; }
vf3_matrix_load(s,ram,4,r[15]+r[0]);
goto P_0c08af90;
P_0c08af90: /* original c712, guest PC 0x0c08af90 */
if(!s->budget--) { s->failed_pc=0x0c08af90u; return 0; }
r[0]=0x0c08afdcu;
goto P_0c08af92;
P_0c08af92: /* original f308, guest PC 0x0c08af92 */
if(!s->budget--) { s->failed_pc=0x0c08af92u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c08af94;
P_0c08af94: /* original e010, guest PC 0x0c08af94 */
if(!s->budget--) { s->failed_pc=0x0c08af94u; return 0; }
r[0]=0x00000010u;
goto P_0c08af96;
P_0c08af96: /* original ff37, guest PC 0x0c08af96 */
if(!s->budget--) { s->failed_pc=0x0c08af96u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c08af98;
P_0c08af98: /* original c711, guest PC 0x0c08af98 */
if(!s->budget--) { s->failed_pc=0x0c08af98u; return 0; }
r[0]=0x0c08afe0u;
goto P_0c08af9a;
P_0c08af9a: /* original fd08, guest PC 0x0c08af9a */
if(!s->budget--) { s->failed_pc=0x0c08af9au; return 0; }
vf3_matrix_load(s,ram,13,r[0]);
goto P_0c08af9c;
P_0c08af9c: /* original e014, guest PC 0x0c08af9c */
if(!s->budget--) { s->failed_pc=0x0c08af9cu; return 0; }
r[0]=0x00000014u;
goto P_0c08af9e;
P_0c08af9e: /* original ffd7, guest PC 0x0c08af9e */
if(!s->budget--) { s->failed_pc=0x0c08af9eu; return 0; }
vf3_matrix_store(s,ram,13,r[15]+r[0]);
goto P_0c08afa0;
P_0c08afa0: /* original c710, guest PC 0x0c08afa0 */
if(!s->budget--) { s->failed_pc=0x0c08afa0u; return 0; }
r[0]=0x0c08afe4u;
goto P_0c08afa2;
P_0c08afa2: /* original fe08, guest PC 0x0c08afa2 */
if(!s->budget--) { s->failed_pc=0x0c08afa2u; return 0; }
vf3_matrix_load(s,ram,14,r[0]);
goto P_0c08afa4;
P_0c08afa4: /* original e02c, guest PC 0x0c08afa4 */
if(!s->budget--) { s->failed_pc=0x0c08afa4u; return 0; }
r[0]=0x0000002cu;
goto P_0c08afa6;
P_0c08afa6: /* original ffe7, guest PC 0x0c08afa6 */
if(!s->budget--) { s->failed_pc=0x0c08afa6u; return 0; }
vf3_matrix_store(s,ram,14,r[15]+r[0]);
goto P_0c08afa8;
P_0c08afa8: /* original d90f, guest PC 0x0c08afa8 */
if(!s->budget--) { s->failed_pc=0x0c08afa8u; return 0; }
r[9]=read(ram,0x0c08afe8u,4);
goto P_0c08afaa;
P_0c08afaa: /* original da10, guest PC 0x0c08afaa */
if(!s->budget--) { s->failed_pc=0x0c08afaau; return 0; }
r[10]=read(ram,0x0c08afecu,4);
goto P_0c08afac;
P_0c08afac: /* original db10, guest PC 0x0c08afac */
if(!s->budget--) { s->failed_pc=0x0c08afacu; return 0; }
r[11]=read(ram,0x0c08aff0u,4);
goto P_0c08afae;
P_0c08afae: /* original a039, guest PC 0x0c08afae */
if(!s->budget--) { s->failed_pc=0x0c08afaeu; return 0; }
r[3]=0x00000008u;
goto P_0c08b024;
P_0c08afb0: /* original e308, guest PC 0x0c08afb0 */
if(!s->budget--) { s->failed_pc=0x0c08afb0u; return 0; }
r[3]=0x00000008u;
return vf3_matrix_family(0x0c08afb2u,s,ram);
P_0c08aff4: /* original e014, guest PC 0x0c08aff4 */
if(!s->budget--) { s->failed_pc=0x0c08aff4u; return 0; }
r[0]=0x00000014u;
goto P_0c08aff6;
P_0c08aff6: /* original f3f6, guest PC 0x0c08aff6 */
if(!s->budget--) { s->failed_pc=0x0c08aff6u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c08aff8;
P_0c08aff8: /* original ff35, guest PC 0x0c08aff8 */
if(!s->budget--) { s->failed_pc=0x0c08aff8u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[15])>as_float(fr[3]))!=0);
goto P_0c08affa;
P_0c08affa: /* original 8907, guest PC 0x0c08affa */
if(!s->budget--) { s->failed_pc=0x0c08affau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c08b00c; }
goto P_0c08affc;
P_0c08affc: /* original e02c, guest PC 0x0c08affc */
if(!s->budget--) { s->failed_pc=0x0c08affcu; return 0; }
r[0]=0x0000002cu;
goto P_0c08affe;
P_0c08affe: /* original f3f6, guest PC 0x0c08affe */
if(!s->budget--) { s->failed_pc=0x0c08affeu; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c08b000;
P_0c08b000: /* original f3f5, guest PC 0x0c08b000 */
if(!s->budget--) { s->failed_pc=0x0c08b000u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[15]))!=0);
goto P_0c08b002;
P_0c08b002: /* original 8903, guest PC 0x0c08b002 */
if(!s->budget--) { s->failed_pc=0x0c08b002u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c08b00c; }
goto P_0c08b004;
P_0c08b004: /* original 4a0b, guest PC 0x0c08b004 */
if(!s->budget--) { s->failed_pc=0x0c08b004u; return 0; }
target=r[10];
r[16]=0x0c08b008u;
r[4]=r[9];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08b008u) { target=s->pc; goto dispatch; }
goto P_0c08b008;
P_0c08b006: /* original 6493, guest PC 0x0c08b006 */
if(!s->budget--) { s->failed_pc=0x0c08b006u; return 0; }
r[4]=r[9];
goto P_0c08b008;
P_0c08b008: /* original 4b0b, guest PC 0x0c08b008 */
if(!s->budget--) { s->failed_pc=0x0c08b008u; return 0; }
target=r[11];
r[16]=0x0c08b00cu;
r[4]=r[8];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08b00cu) { target=s->pc; goto dispatch; }
goto P_0c08b00c;
P_0c08b00a: /* original 6483, guest PC 0x0c08b00a */
if(!s->budget--) { s->failed_pc=0x0c08b00au; return 0; }
r[4]=r[8];
goto P_0c08b00c;
P_0c08b00c: /* original e010, guest PC 0x0c08b00c */
if(!s->budget--) { s->failed_pc=0x0c08b00cu; return 0; }
r[0]=0x00000010u;
goto P_0c08b00e;
P_0c08b00e: /* original f3f6, guest PC 0x0c08b00e */
if(!s->budget--) { s->failed_pc=0x0c08b00eu; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c08b010;
P_0c08b010: /* original 4d0b, guest PC 0x0c08b010 */
if(!s->budget--) { s->failed_pc=0x0c08b010u; return 0; }
target=r[13];
r[16]=0x0c08b014u;
fr[15]=vf3_fpu_binary(fr[15],fr[3],r[18],'-');
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08b014u) { target=s->pc; goto dispatch; }
goto P_0c08b014;
P_0c08b012: /* original ff31, guest PC 0x0c08b012 */
if(!s->budget--) { s->failed_pc=0x0c08b012u; return 0; }
fr[15]=vf3_fpu_binary(fr[15],fr[3],r[18],'-');
goto P_0c08b014;
P_0c08b014: /* original f6fc, guest PC 0x0c08b014 */
if(!s->budget--) { s->failed_pc=0x0c08b014u; return 0; }
vf3_matrix_move(s,6,15);
goto P_0c08b016;
P_0c08b016: /* original e004, guest PC 0x0c08b016 */
if(!s->budget--) { s->failed_pc=0x0c08b016u; return 0; }
r[0]=0x00000004u;
goto P_0c08b018;
P_0c08b018: /* original f5cc, guest PC 0x0c08b018 */
if(!s->budget--) { s->failed_pc=0x0c08b018u; return 0; }
vf3_matrix_move(s,5,12);
goto P_0c08b01a;
P_0c08b01a: /* original f64d, guest PC 0x0c08b01a */
if(!s->budget--) { s->failed_pc=0x0c08b01au; return 0; }
fr[6]^=0x80000000u;
goto P_0c08b01c;
P_0c08b01c: /* original 4e0b, guest PC 0x0c08b01c */
if(!s->budget--) { s->failed_pc=0x0c08b01cu; return 0; }
target=r[14];
r[16]=0x0c08b020u;
vf3_matrix_load(s,ram,4,r[15]+r[0]);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08b020u) { target=s->pc; goto dispatch; }
goto P_0c08b020;
P_0c08b01e: /* original f4f6, guest PC 0x0c08b01e */
if(!s->budget--) { s->failed_pc=0x0c08b01eu; return 0; }
vf3_matrix_load(s,ram,4,r[15]+r[0]);
goto P_0c08b020;
P_0c08b020: /* original 63f2, guest PC 0x0c08b020 */
if(!s->budget--) { s->failed_pc=0x0c08b020u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c08b022;
P_0c08b022: /* original 73ff, guest PC 0x0c08b022 */
if(!s->budget--) { s->failed_pc=0x0c08b022u; return 0; }
r[3]+=0xffffffffu;
goto P_0c08b024;
P_0c08b024: /* original 6233, guest PC 0x0c08b024 */
if(!s->budget--) { s->failed_pc=0x0c08b024u; return 0; }
r[2]=r[3];
goto P_0c08b026;
P_0c08b026: /* original 2228, guest PC 0x0c08b026 */
if(!s->budget--) { s->failed_pc=0x0c08b026u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c08b028;
P_0c08b028: /* original 8fe4, guest PC 0x0c08b028 */
if(!s->budget--) { s->failed_pc=0x0c08b028u; return 0; }
cond=r[17]&1u;
write(ram,r[15],r[3],4);
if(!cond) { goto P_0c08aff4; }
goto P_0c08b02c;
P_0c08b02a: /* original 2f32, guest PC 0x0c08b02a */
if(!s->budget--) { s->failed_pc=0x0c08b02au; return 0; }
write(ram,r[15],r[3],4);
goto P_0c08b02c;
P_0c08b02c: /* original e034, guest PC 0x0c08b02c */
if(!s->budget--) { s->failed_pc=0x0c08b02cu; return 0; }
r[0]=0x00000034u;
goto P_0c08b02e;
P_0c08b02e: /* original fcc6, guest PC 0x0c08b02e */
if(!s->budget--) { s->failed_pc=0x0c08b02eu; return 0; }
vf3_matrix_load(s,ram,12,r[12]+r[0]);
goto P_0c08b030;
P_0c08b030: /* original e038, guest PC 0x0c08b030 */
if(!s->budget--) { s->failed_pc=0x0c08b030u; return 0; }
r[0]=0x00000038u;
goto P_0c08b032;
P_0c08b032: /* original f3c6, guest PC 0x0c08b032 */
if(!s->budget--) { s->failed_pc=0x0c08b032u; return 0; }
vf3_matrix_load(s,ram,3,r[12]+r[0]);
goto P_0c08b034;
P_0c08b034: /* original e008, guest PC 0x0c08b034 */
if(!s->budget--) { s->failed_pc=0x0c08b034u; return 0; }
r[0]=0x00000008u;
goto P_0c08b036;
P_0c08b036: /* original ff37, guest PC 0x0c08b036 */
if(!s->budget--) { s->failed_pc=0x0c08b036u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c08b038;
P_0c08b038: /* original e03c, guest PC 0x0c08b038 */
if(!s->budget--) { s->failed_pc=0x0c08b038u; return 0; }
r[0]=0x0000003cu;
goto P_0c08b03a;
P_0c08b03a: /* original 4d0b, guest PC 0x0c08b03a */
if(!s->budget--) { s->failed_pc=0x0c08b03au; return 0; }
target=r[13];
r[16]=0x0c08b03eu;
vf3_matrix_load(s,ram,15,r[12]+r[0]);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08b03eu) { target=s->pc; goto dispatch; }
goto P_0c08b03e;
P_0c08b03c: /* original ffc6, guest PC 0x0c08b03c */
if(!s->budget--) { s->failed_pc=0x0c08b03cu; return 0; }
vf3_matrix_load(s,ram,15,r[12]+r[0]);
goto P_0c08b03e;
P_0c08b03e: /* original e008, guest PC 0x0c08b03e */
if(!s->budget--) { s->failed_pc=0x0c08b03eu; return 0; }
r[0]=0x00000008u;
goto P_0c08b040;
P_0c08b040: /* original f6fc, guest PC 0x0c08b040 */
if(!s->budget--) { s->failed_pc=0x0c08b040u; return 0; }
vf3_matrix_move(s,6,15);
goto P_0c08b042;
P_0c08b042: /* original f5f6, guest PC 0x0c08b042 */
if(!s->budget--) { s->failed_pc=0x0c08b042u; return 0; }
vf3_matrix_load(s,ram,5,r[15]+r[0]);
goto P_0c08b044;
P_0c08b044: /* original f64d, guest PC 0x0c08b044 */
if(!s->budget--) { s->failed_pc=0x0c08b044u; return 0; }
fr[6]^=0x80000000u;
goto P_0c08b046;
P_0c08b046: /* original 4e0b, guest PC 0x0c08b046 */
if(!s->budget--) { s->failed_pc=0x0c08b046u; return 0; }
target=r[14];
r[16]=0x0c08b04au;
vf3_matrix_move(s,4,12);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08b04au) { target=s->pc; goto dispatch; }
goto P_0c08b04a;
P_0c08b048: /* original f4cc, guest PC 0x0c08b048 */
if(!s->budget--) { s->failed_pc=0x0c08b048u; return 0; }
vf3_matrix_move(s,4,12);
goto P_0c08b04a;
P_0c08b04a: /* original c735, guest PC 0x0c08b04a */
if(!s->budget--) { s->failed_pc=0x0c08b04au; return 0; }
r[0]=0x0c08b120u;
goto P_0c08b04c;
P_0c08b04c: /* original f308, guest PC 0x0c08b04c */
if(!s->budget--) { s->failed_pc=0x0c08b04cu; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c08b04e;
P_0c08b04e: /* original e020, guest PC 0x0c08b04e */
if(!s->budget--) { s->failed_pc=0x0c08b04eu; return 0; }
r[0]=0x00000020u;
goto P_0c08b050;
P_0c08b050: /* original ff37, guest PC 0x0c08b050 */
if(!s->budget--) { s->failed_pc=0x0c08b050u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c08b052;
P_0c08b052: /* original e018, guest PC 0x0c08b052 */
if(!s->budget--) { s->failed_pc=0x0c08b052u; return 0; }
r[0]=0x00000018u;
goto P_0c08b054;
P_0c08b054: /* original ffd7, guest PC 0x0c08b054 */
if(!s->budget--) { s->failed_pc=0x0c08b054u; return 0; }
vf3_matrix_store(s,ram,13,r[15]+r[0]);
goto P_0c08b056;
P_0c08b056: /* original e01c, guest PC 0x0c08b056 */
if(!s->budget--) { s->failed_pc=0x0c08b056u; return 0; }
r[0]=0x0000001cu;
goto P_0c08b058;
P_0c08b058: /* original ffe7, guest PC 0x0c08b058 */
if(!s->budget--) { s->failed_pc=0x0c08b058u; return 0; }
vf3_matrix_store(s,ram,14,r[15]+r[0]);
goto P_0c08b05a;
P_0c08b05a: /* original a019, guest PC 0x0c08b05a */
if(!s->budget--) { s->failed_pc=0x0c08b05au; return 0; }
r[3]=0x00000008u;
goto P_0c08b090;
P_0c08b05c: /* original e308, guest PC 0x0c08b05c */
if(!s->budget--) { s->failed_pc=0x0c08b05cu; return 0; }
r[3]=0x00000008u;
goto P_0c08b05e;
P_0c08b05e: /* original e018, guest PC 0x0c08b05e */
if(!s->budget--) { s->failed_pc=0x0c08b05eu; return 0; }
r[0]=0x00000018u;
goto P_0c08b060;
P_0c08b060: /* original f3f6, guest PC 0x0c08b060 */
if(!s->budget--) { s->failed_pc=0x0c08b060u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c08b062;
P_0c08b062: /* original ff35, guest PC 0x0c08b062 */
if(!s->budget--) { s->failed_pc=0x0c08b062u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[15])>as_float(fr[3]))!=0);
goto P_0c08b064;
P_0c08b064: /* original 8908, guest PC 0x0c08b064 */
if(!s->budget--) { s->failed_pc=0x0c08b064u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c08b078; }
goto P_0c08b066;
P_0c08b066: /* original e01c, guest PC 0x0c08b066 */
if(!s->budget--) { s->failed_pc=0x0c08b066u; return 0; }
r[0]=0x0000001cu;
goto P_0c08b068;
P_0c08b068: /* original f3f6, guest PC 0x0c08b068 */
if(!s->budget--) { s->failed_pc=0x0c08b068u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c08b06a;
P_0c08b06a: /* original f3f5, guest PC 0x0c08b06a */
if(!s->budget--) { s->failed_pc=0x0c08b06au; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[15]))!=0);
goto P_0c08b06c;
P_0c08b06c: /* original 8904, guest PC 0x0c08b06c */
if(!s->budget--) { s->failed_pc=0x0c08b06cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c08b078; }
goto P_0c08b06e;
P_0c08b06e: /* original 9455, guest PC 0x0c08b06e */
if(!s->budget--) { s->failed_pc=0x0c08b06eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08b11cu,2);
goto P_0c08b070;
P_0c08b070: /* original 4a0b, guest PC 0x0c08b070 */
if(!s->budget--) { s->failed_pc=0x0c08b070u; return 0; }
target=r[10];
r[16]=0x0c08b074u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08b074u) { target=s->pc; goto dispatch; }
goto P_0c08b074;
P_0c08b072: /* original 0009, guest PC 0x0c08b072 */
if(!s->budget--) { s->failed_pc=0x0c08b072u; return 0; }
goto P_0c08b074;
P_0c08b074: /* original 4b0b, guest PC 0x0c08b074 */
if(!s->budget--) { s->failed_pc=0x0c08b074u; return 0; }
target=r[11];
r[16]=0x0c08b078u;
r[4]=r[8];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08b078u) { target=s->pc; goto dispatch; }
goto P_0c08b078;
P_0c08b076: /* original 6483, guest PC 0x0c08b076 */
if(!s->budget--) { s->failed_pc=0x0c08b076u; return 0; }
r[4]=r[8];
goto P_0c08b078;
P_0c08b078: /* original e020, guest PC 0x0c08b078 */
if(!s->budget--) { s->failed_pc=0x0c08b078u; return 0; }
r[0]=0x00000020u;
goto P_0c08b07a;
P_0c08b07a: /* original f3f6, guest PC 0x0c08b07a */
if(!s->budget--) { s->failed_pc=0x0c08b07au; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c08b07c;
P_0c08b07c: /* original 4d0b, guest PC 0x0c08b07c */
if(!s->budget--) { s->failed_pc=0x0c08b07cu; return 0; }
target=r[13];
r[16]=0x0c08b080u;
fr[15]=vf3_fpu_binary(fr[15],fr[3],r[18],'-');
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08b080u) { target=s->pc; goto dispatch; }
goto P_0c08b080;
P_0c08b07e: /* original ff31, guest PC 0x0c08b07e */
if(!s->budget--) { s->failed_pc=0x0c08b07eu; return 0; }
fr[15]=vf3_fpu_binary(fr[15],fr[3],r[18],'-');
goto P_0c08b080;
P_0c08b080: /* original e008, guest PC 0x0c08b080 */
if(!s->budget--) { s->failed_pc=0x0c08b080u; return 0; }
r[0]=0x00000008u;
goto P_0c08b082;
P_0c08b082: /* original f6fc, guest PC 0x0c08b082 */
if(!s->budget--) { s->failed_pc=0x0c08b082u; return 0; }
vf3_matrix_move(s,6,15);
goto P_0c08b084;
P_0c08b084: /* original f5f6, guest PC 0x0c08b084 */
if(!s->budget--) { s->failed_pc=0x0c08b084u; return 0; }
vf3_matrix_load(s,ram,5,r[15]+r[0]);
goto P_0c08b086;
P_0c08b086: /* original f64d, guest PC 0x0c08b086 */
if(!s->budget--) { s->failed_pc=0x0c08b086u; return 0; }
fr[6]^=0x80000000u;
goto P_0c08b088;
P_0c08b088: /* original 4e0b, guest PC 0x0c08b088 */
if(!s->budget--) { s->failed_pc=0x0c08b088u; return 0; }
target=r[14];
r[16]=0x0c08b08cu;
vf3_matrix_move(s,4,12);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08b08cu) { target=s->pc; goto dispatch; }
goto P_0c08b08c;
P_0c08b08a: /* original f4cc, guest PC 0x0c08b08a */
if(!s->budget--) { s->failed_pc=0x0c08b08au; return 0; }
vf3_matrix_move(s,4,12);
goto P_0c08b08c;
P_0c08b08c: /* original 63f2, guest PC 0x0c08b08c */
if(!s->budget--) { s->failed_pc=0x0c08b08cu; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c08b08e;
P_0c08b08e: /* original 73ff, guest PC 0x0c08b08e */
if(!s->budget--) { s->failed_pc=0x0c08b08eu; return 0; }
r[3]+=0xffffffffu;
goto P_0c08b090;
P_0c08b090: /* original 6233, guest PC 0x0c08b090 */
if(!s->budget--) { s->failed_pc=0x0c08b090u; return 0; }
r[2]=r[3];
goto P_0c08b092;
P_0c08b092: /* original 2228, guest PC 0x0c08b092 */
if(!s->budget--) { s->failed_pc=0x0c08b092u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c08b094;
P_0c08b094: /* original 8fe3, guest PC 0x0c08b094 */
if(!s->budget--) { s->failed_pc=0x0c08b094u; return 0; }
cond=r[17]&1u;
write(ram,r[15],r[3],4);
if(!cond) { goto P_0c08b05e; }
goto P_0c08b098;
P_0c08b096: /* original 2f32, guest PC 0x0c08b096 */
if(!s->budget--) { s->failed_pc=0x0c08b096u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c08b098;
P_0c08b098: /* original d222, guest PC 0x0c08b098 */
if(!s->budget--) { s->failed_pc=0x0c08b098u; return 0; }
r[2]=read(ram,0x0c08b124u,4);
goto P_0c08b09a;
P_0c08b09a: /* original 6020, guest PC 0x0c08b09a */
if(!s->budget--) { s->failed_pc=0x0c08b09au; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[2],1);
r[0]=tmp;
goto P_0c08b09c;
P_0c08b09c: /* original 600c, guest PC 0x0c08b09c */
if(!s->budget--) { s->failed_pc=0x0c08b09cu; return 0; }
r[0]=r[0]&255u;
goto P_0c08b09e;
P_0c08b09e: /* original c810, guest PC 0x0c08b09e */
if(!s->budget--) { s->failed_pc=0x0c08b09eu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&16u)==0)!=0);
goto P_0c08b0a0;
P_0c08b0a0: /* original 8b2e, guest PC 0x0c08b0a0 */
if(!s->budget--) { s->failed_pc=0x0c08b0a0u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c08b100; }
goto P_0c08b0a2;
P_0c08b0a2: /* original e018, guest PC 0x0c08b0a2 */
if(!s->budget--) { s->failed_pc=0x0c08b0a2u; return 0; }
r[0]=0x00000018u;
goto P_0c08b0a4;
P_0c08b0a4: /* original f3c6, guest PC 0x0c08b0a4 */
if(!s->budget--) { s->failed_pc=0x0c08b0a4u; return 0; }
vf3_matrix_load(s,ram,3,r[12]+r[0]);
goto P_0c08b0a6;
P_0c08b0a6: /* original e00c, guest PC 0x0c08b0a6 */
if(!s->budget--) { s->failed_pc=0x0c08b0a6u; return 0; }
r[0]=0x0000000cu;
goto P_0c08b0a8;
P_0c08b0a8: /* original ff37, guest PC 0x0c08b0a8 */
if(!s->budget--) { s->failed_pc=0x0c08b0a8u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c08b0aa;
P_0c08b0aa: /* original e01c, guest PC 0x0c08b0aa */
if(!s->budget--) { s->failed_pc=0x0c08b0aau; return 0; }
r[0]=0x0000001cu;
goto P_0c08b0ac;
P_0c08b0ac: /* original fcc6, guest PC 0x0c08b0ac */
if(!s->budget--) { s->failed_pc=0x0c08b0acu; return 0; }
vf3_matrix_load(s,ram,12,r[12]+r[0]);
goto P_0c08b0ae;
P_0c08b0ae: /* original e020, guest PC 0x0c08b0ae */
if(!s->budget--) { s->failed_pc=0x0c08b0aeu; return 0; }
r[0]=0x00000020u;
goto P_0c08b0b0;
P_0c08b0b0: /* original 4d0b, guest PC 0x0c08b0b0 */
if(!s->budget--) { s->failed_pc=0x0c08b0b0u; return 0; }
target=r[13];
r[16]=0x0c08b0b4u;
vf3_matrix_load(s,ram,15,r[12]+r[0]);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08b0b4u) { target=s->pc; goto dispatch; }
goto P_0c08b0b4;
P_0c08b0b2: /* original ffc6, guest PC 0x0c08b0b2 */
if(!s->budget--) { s->failed_pc=0x0c08b0b2u; return 0; }
vf3_matrix_load(s,ram,15,r[12]+r[0]);
goto P_0c08b0b4;
P_0c08b0b4: /* original f6fc, guest PC 0x0c08b0b4 */
if(!s->budget--) { s->failed_pc=0x0c08b0b4u; return 0; }
vf3_matrix_move(s,6,15);
goto P_0c08b0b6;
P_0c08b0b6: /* original e00c, guest PC 0x0c08b0b6 */
if(!s->budget--) { s->failed_pc=0x0c08b0b6u; return 0; }
r[0]=0x0000000cu;
goto P_0c08b0b8;
P_0c08b0b8: /* original f5cc, guest PC 0x0c08b0b8 */
if(!s->budget--) { s->failed_pc=0x0c08b0b8u; return 0; }
vf3_matrix_move(s,5,12);
goto P_0c08b0ba;
P_0c08b0ba: /* original f64d, guest PC 0x0c08b0ba */
if(!s->budget--) { s->failed_pc=0x0c08b0bau; return 0; }
fr[6]^=0x80000000u;
goto P_0c08b0bc;
P_0c08b0bc: /* original 4e0b, guest PC 0x0c08b0bc */
if(!s->budget--) { s->failed_pc=0x0c08b0bcu; return 0; }
target=r[14];
r[16]=0x0c08b0c0u;
vf3_matrix_load(s,ram,4,r[15]+r[0]);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08b0c0u) { target=s->pc; goto dispatch; }
goto P_0c08b0c0;
P_0c08b0be: /* original f4f6, guest PC 0x0c08b0be */
if(!s->budget--) { s->failed_pc=0x0c08b0beu; return 0; }
vf3_matrix_load(s,ram,4,r[15]+r[0]);
goto P_0c08b0c0;
P_0c08b0c0: /* original c717, guest PC 0x0c08b0c0 */
if(!s->budget--) { s->failed_pc=0x0c08b0c0u; return 0; }
r[0]=0x0c08b120u;
goto P_0c08b0c2;
P_0c08b0c2: /* original f308, guest PC 0x0c08b0c2 */
if(!s->budget--) { s->failed_pc=0x0c08b0c2u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c08b0c4;
P_0c08b0c4: /* original e028, guest PC 0x0c08b0c4 */
if(!s->budget--) { s->failed_pc=0x0c08b0c4u; return 0; }
r[0]=0x00000028u;
goto P_0c08b0c6;
P_0c08b0c6: /* original ff37, guest PC 0x0c08b0c6 */
if(!s->budget--) { s->failed_pc=0x0c08b0c6u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c08b0c8;
P_0c08b0c8: /* original e024, guest PC 0x0c08b0c8 */
if(!s->budget--) { s->failed_pc=0x0c08b0c8u; return 0; }
r[0]=0x00000024u;
goto P_0c08b0ca;
P_0c08b0ca: /* original ffd7, guest PC 0x0c08b0ca */
if(!s->budget--) { s->failed_pc=0x0c08b0cau; return 0; }
vf3_matrix_store(s,ram,13,r[15]+r[0]);
goto P_0c08b0cc;
P_0c08b0cc: /* original fdec, guest PC 0x0c08b0cc */
if(!s->budget--) { s->failed_pc=0x0c08b0ccu; return 0; }
vf3_matrix_move(s,13,14);
goto P_0c08b0ce;
P_0c08b0ce: /* original a015, guest PC 0x0c08b0ce */
if(!s->budget--) { s->failed_pc=0x0c08b0ceu; return 0; }
r[12]=0x00000008u;
goto P_0c08b0fc;
P_0c08b0d0: /* original ec08, guest PC 0x0c08b0d0 */
if(!s->budget--) { s->failed_pc=0x0c08b0d0u; return 0; }
r[12]=0x00000008u;
goto P_0c08b0d2;
P_0c08b0d2: /* original e024, guest PC 0x0c08b0d2 */
if(!s->budget--) { s->failed_pc=0x0c08b0d2u; return 0; }
r[0]=0x00000024u;
goto P_0c08b0d4;
P_0c08b0d4: /* original f3f6, guest PC 0x0c08b0d4 */
if(!s->budget--) { s->failed_pc=0x0c08b0d4u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c08b0d6;
P_0c08b0d6: /* original ff35, guest PC 0x0c08b0d6 */
if(!s->budget--) { s->failed_pc=0x0c08b0d6u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[15])>as_float(fr[3]))!=0);
goto P_0c08b0d8;
P_0c08b0d8: /* original 8905, guest PC 0x0c08b0d8 */
if(!s->budget--) { s->failed_pc=0x0c08b0d8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c08b0e6; }
goto P_0c08b0da;
P_0c08b0da: /* original fdf5, guest PC 0x0c08b0da */
if(!s->budget--) { s->failed_pc=0x0c08b0dau; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[13])>as_float(fr[15]))!=0);
goto P_0c08b0dc;
P_0c08b0dc: /* original 8903, guest PC 0x0c08b0dc */
if(!s->budget--) { s->failed_pc=0x0c08b0dcu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c08b0e6; }
goto P_0c08b0de;
P_0c08b0de: /* original 4a0b, guest PC 0x0c08b0de */
if(!s->budget--) { s->failed_pc=0x0c08b0deu; return 0; }
target=r[10];
r[16]=0x0c08b0e2u;
r[4]=r[9];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08b0e2u) { target=s->pc; goto dispatch; }
goto P_0c08b0e2;
P_0c08b0e0: /* original 6493, guest PC 0x0c08b0e0 */
if(!s->budget--) { s->failed_pc=0x0c08b0e0u; return 0; }
r[4]=r[9];
goto P_0c08b0e2;
P_0c08b0e2: /* original 4b0b, guest PC 0x0c08b0e2 */
if(!s->budget--) { s->failed_pc=0x0c08b0e2u; return 0; }
target=r[11];
r[16]=0x0c08b0e6u;
r[4]=r[8];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08b0e6u) { target=s->pc; goto dispatch; }
goto P_0c08b0e6;
P_0c08b0e4: /* original 6483, guest PC 0x0c08b0e4 */
if(!s->budget--) { s->failed_pc=0x0c08b0e4u; return 0; }
r[4]=r[8];
goto P_0c08b0e6;
P_0c08b0e6: /* original e028, guest PC 0x0c08b0e6 */
if(!s->budget--) { s->failed_pc=0x0c08b0e6u; return 0; }
r[0]=0x00000028u;
goto P_0c08b0e8;
P_0c08b0e8: /* original f3f6, guest PC 0x0c08b0e8 */
if(!s->budget--) { s->failed_pc=0x0c08b0e8u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c08b0ea;
P_0c08b0ea: /* original 4d0b, guest PC 0x0c08b0ea */
if(!s->budget--) { s->failed_pc=0x0c08b0eau; return 0; }
target=r[13];
r[16]=0x0c08b0eeu;
fr[15]=vf3_fpu_binary(fr[15],fr[3],r[18],'-');
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08b0eeu) { target=s->pc; goto dispatch; }
goto P_0c08b0ee;
P_0c08b0ec: /* original ff31, guest PC 0x0c08b0ec */
if(!s->budget--) { s->failed_pc=0x0c08b0ecu; return 0; }
fr[15]=vf3_fpu_binary(fr[15],fr[3],r[18],'-');
goto P_0c08b0ee;
P_0c08b0ee: /* original f6fc, guest PC 0x0c08b0ee */
if(!s->budget--) { s->failed_pc=0x0c08b0eeu; return 0; }
vf3_matrix_move(s,6,15);
goto P_0c08b0f0;
P_0c08b0f0: /* original e00c, guest PC 0x0c08b0f0 */
if(!s->budget--) { s->failed_pc=0x0c08b0f0u; return 0; }
r[0]=0x0000000cu;
goto P_0c08b0f2;
P_0c08b0f2: /* original f5cc, guest PC 0x0c08b0f2 */
if(!s->budget--) { s->failed_pc=0x0c08b0f2u; return 0; }
vf3_matrix_move(s,5,12);
goto P_0c08b0f4;
P_0c08b0f4: /* original f64d, guest PC 0x0c08b0f4 */
if(!s->budget--) { s->failed_pc=0x0c08b0f4u; return 0; }
fr[6]^=0x80000000u;
goto P_0c08b0f6;
P_0c08b0f6: /* original 4e0b, guest PC 0x0c08b0f6 */
if(!s->budget--) { s->failed_pc=0x0c08b0f6u; return 0; }
target=r[14];
r[16]=0x0c08b0fau;
vf3_matrix_load(s,ram,4,r[15]+r[0]);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08b0fau) { target=s->pc; goto dispatch; }
goto P_0c08b0fa;
P_0c08b0f8: /* original f4f6, guest PC 0x0c08b0f8 */
if(!s->budget--) { s->failed_pc=0x0c08b0f8u; return 0; }
vf3_matrix_load(s,ram,4,r[15]+r[0]);
goto P_0c08b0fa;
P_0c08b0fa: /* original 7cff, guest PC 0x0c08b0fa */
if(!s->budget--) { s->failed_pc=0x0c08b0fau; return 0; }
r[12]+=0xffffffffu;
goto P_0c08b0fc;
P_0c08b0fc: /* original 2cc8, guest PC 0x0c08b0fc */
if(!s->budget--) { s->failed_pc=0x0c08b0fcu; return 0; }
r[17]=(r[17]&~1u)|(((r[12]&r[12])==0)!=0);
goto P_0c08b0fe;
P_0c08b0fe: /* original 8be8, guest PC 0x0c08b0fe */
if(!s->budget--) { s->failed_pc=0x0c08b0feu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c08b0d2; }
goto P_0c08b100;
P_0c08b100: /* original 7f30, guest PC 0x0c08b100 */
if(!s->budget--) { s->failed_pc=0x0c08b100u; return 0; }
r[15]+=0x00000030u;
goto P_0c08b102;
P_0c08b102: /* original 4f26, guest PC 0x0c08b102 */
if(!s->budget--) { s->failed_pc=0x0c08b102u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c08b104;
P_0c08b104: /* original fcf9, guest PC 0x0c08b104 */
if(!s->budget--) { s->failed_pc=0x0c08b104u; return 0; }
vf3_matrix_load(s,ram,12,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c08b106;
P_0c08b106: /* original fdf9, guest PC 0x0c08b106 */
if(!s->budget--) { s->failed_pc=0x0c08b106u; return 0; }
vf3_matrix_load(s,ram,13,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c08b108;
P_0c08b108: /* original fef9, guest PC 0x0c08b108 */
if(!s->budget--) { s->failed_pc=0x0c08b108u; return 0; }
vf3_matrix_load(s,ram,14,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c08b10a;
P_0c08b10a: /* original fff9, guest PC 0x0c08b10a */
if(!s->budget--) { s->failed_pc=0x0c08b10au; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c08b10c;
P_0c08b10c: /* original 68f6, guest PC 0x0c08b10c */
if(!s->budget--) { s->failed_pc=0x0c08b10cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c08b10e;
P_0c08b10e: /* original 69f6, guest PC 0x0c08b10e */
if(!s->budget--) { s->failed_pc=0x0c08b10eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c08b110;
P_0c08b110: /* original 6af6, guest PC 0x0c08b110 */
if(!s->budget--) { s->failed_pc=0x0c08b110u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c08b112;
P_0c08b112: /* original 6bf6, guest PC 0x0c08b112 */
if(!s->budget--) { s->failed_pc=0x0c08b112u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c08b114;
P_0c08b114: /* original 6cf6, guest PC 0x0c08b114 */
if(!s->budget--) { s->failed_pc=0x0c08b114u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c08b116;
P_0c08b116: /* original 6df6, guest PC 0x0c08b116 */
if(!s->budget--) { s->failed_pc=0x0c08b116u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c08b118;
P_0c08b118: /* original 000b, guest PC 0x0c08b118 */
if(!s->budget--) { s->failed_pc=0x0c08b118u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c08b11a: /* original 6ef6, guest PC 0x0c08b11a */
if(!s->budget--) { s->failed_pc=0x0c08b11au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c08b11cu,s,ram);
P_0c08ef62: /* original 4f22, guest PC 0x0c08ef62 */
if(!s->budget--) { s->failed_pc=0x0c08ef62u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c08ef64;
P_0c08ef64: /* original 7fdc, guest PC 0x0c08ef64 */
if(!s->budget--) { s->failed_pc=0x0c08ef64u; return 0; }
r[15]+=0xffffffdcu;
goto P_0c08ef66;
P_0c08ef66: /* original ff47, guest PC 0x0c08ef66 */
if(!s->budget--) { s->failed_pc=0x0c08ef66u; return 0; }
vf3_matrix_store(s,ram,4,r[15]+r[0]);
goto P_0c08ef68;
P_0c08ef68: /* original e008, guest PC 0x0c08ef68 */
if(!s->budget--) { s->failed_pc=0x0c08ef68u; return 0; }
r[0]=0x00000008u;
goto P_0c08ef6a;
P_0c08ef6a: /* original ff5a, guest PC 0x0c08ef6a */
if(!s->budget--) { s->failed_pc=0x0c08ef6au; return 0; }
vf3_matrix_store(s,ram,5,r[15]);
goto P_0c08ef6c;
P_0c08ef6c: /* original ff67, guest PC 0x0c08ef6c */
if(!s->budget--) { s->failed_pc=0x0c08ef6cu; return 0; }
vf3_matrix_store(s,ram,6,r[15]+r[0]);
goto P_0c08ef6e;
P_0c08ef6e: /* original d361, guest PC 0x0c08ef6e */
if(!s->budget--) { s->failed_pc=0x0c08ef6eu; return 0; }
r[3]=read(ram,0x0c08f0f4u,4);
goto P_0c08ef70;
P_0c08ef70: /* original 430b, guest PC 0x0c08ef70 */
if(!s->budget--) { s->failed_pc=0x0c08ef70u; return 0; }
target=r[3];
r[16]=0x0c08ef74u;
r[4]=0x00000000u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08ef74u) { target=s->pc; goto dispatch; }
goto P_0c08ef74;
P_0c08ef72: /* original e400, guest PC 0x0c08ef72 */
if(!s->budget--) { s->failed_pc=0x0c08ef72u; return 0; }
r[4]=0x00000000u;
goto P_0c08ef74;
P_0c08ef74: /* original da61, guest PC 0x0c08ef74 */
if(!s->budget--) { s->failed_pc=0x0c08ef74u; return 0; }
r[10]=read(ram,0x0c08f0fcu,4);
goto P_0c08ef76;
P_0c08ef76: /* original c760, guest PC 0x0c08ef76 */
if(!s->budget--) { s->failed_pc=0x0c08ef76u; return 0; }
r[0]=0x0c08f0f8u;
goto P_0c08ef78;
P_0c08ef78: /* original 4a0b, guest PC 0x0c08ef78 */
if(!s->budget--) { s->failed_pc=0x0c08ef78u; return 0; }
target=r[10];
r[16]=0x0c08ef7cu;
vf3_matrix_load(s,ram,15,r[0]);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08ef7cu) { target=s->pc; goto dispatch; }
goto P_0c08ef7c;
P_0c08ef7a: /* original ff08, guest PC 0x0c08ef7a */
if(!s->budget--) { s->failed_pc=0x0c08ef7au; return 0; }
vf3_matrix_load(s,ram,15,r[0]);
goto P_0c08ef7c;
P_0c08ef7c: /* original e07c, guest PC 0x0c08ef7c */
if(!s->budget--) { s->failed_pc=0x0c08ef7cu; return 0; }
r[0]=0x0000007cu;
goto P_0c08ef7e;
P_0c08ef7e: /* original f4e6, guest PC 0x0c08ef7e */
if(!s->budget--) { s->failed_pc=0x0c08ef7eu; return 0; }
vf3_matrix_load(s,ram,4,r[14]+r[0]);
goto P_0c08ef80;
P_0c08ef80: /* original 7004, guest PC 0x0c08ef80 */
if(!s->budget--) { s->failed_pc=0x0c08ef80u; return 0; }
r[0]+=0x00000004u;
goto P_0c08ef82;
P_0c08ef82: /* original f5e6, guest PC 0x0c08ef82 */
if(!s->budget--) { s->failed_pc=0x0c08ef82u; return 0; }
vf3_matrix_load(s,ram,5,r[14]+r[0]);
goto P_0c08ef84;
P_0c08ef84: /* original 7004, guest PC 0x0c08ef84 */
if(!s->budget--) { s->failed_pc=0x0c08ef84u; return 0; }
r[0]+=0x00000004u;
goto P_0c08ef86;
P_0c08ef86: /* original f3e6, guest PC 0x0c08ef86 */
if(!s->budget--) { s->failed_pc=0x0c08ef86u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c08ef88;
P_0c08ef88: /* original e01c, guest PC 0x0c08ef88 */
if(!s->budget--) { s->failed_pc=0x0c08ef88u; return 0; }
r[0]=0x0000001cu;
goto P_0c08ef8a;
P_0c08ef8a: /* original ff37, guest PC 0x0c08ef8a */
if(!s->budget--) { s->failed_pc=0x0c08ef8au; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c08ef8c;
P_0c08ef8c: /* original dd5c, guest PC 0x0c08ef8c */
if(!s->budget--) { s->failed_pc=0x0c08ef8cu; return 0; }
r[13]=read(ram,0x0c08f100u,4);
goto P_0c08ef8e;
P_0c08ef8e: /* original f63c, guest PC 0x0c08ef8e */
if(!s->budget--) { s->failed_pc=0x0c08ef8eu; return 0; }
vf3_matrix_move(s,6,3);
goto P_0c08ef90;
P_0c08ef90: /* original 4d0b, guest PC 0x0c08ef90 */
if(!s->budget--) { s->failed_pc=0x0c08ef90u; return 0; }
target=r[13];
r[16]=0x0c08ef94u;
fr[6]^=0x80000000u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08ef94u) { target=s->pc; goto dispatch; }
goto P_0c08ef94;
P_0c08ef92: /* original f64d, guest PC 0x0c08ef92 */
if(!s->budget--) { s->failed_pc=0x0c08ef92u; return 0; }
fr[6]^=0x80000000u;
goto P_0c08ef94;
P_0c08ef94: /* original dc5b, guest PC 0x0c08ef94 */
if(!s->budget--) { s->failed_pc=0x0c08ef94u; return 0; }
r[12]=read(ram,0x0c08f104u,4);
goto P_0c08ef96;
P_0c08ef96: /* original f5fc, guest PC 0x0c08ef96 */
if(!s->budget--) { s->failed_pc=0x0c08ef96u; return 0; }
vf3_matrix_move(s,5,15);
goto P_0c08ef98;
P_0c08ef98: /* original f6fc, guest PC 0x0c08ef98 */
if(!s->budget--) { s->failed_pc=0x0c08ef98u; return 0; }
vf3_matrix_move(s,6,15);
goto P_0c08ef9a;
P_0c08ef9a: /* original 4c0b, guest PC 0x0c08ef9a */
if(!s->budget--) { s->failed_pc=0x0c08ef9au; return 0; }
target=r[12];
r[16]=0x0c08ef9eu;
vf3_matrix_move(s,4,15);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08ef9eu) { target=s->pc; goto dispatch; }
goto P_0c08ef9e;
P_0c08ef9c: /* original f4fc, guest PC 0x0c08ef9c */
if(!s->budget--) { s->failed_pc=0x0c08ef9cu; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c08ef9e;
P_0c08ef9e: /* original db5a, guest PC 0x0c08ef9e */
if(!s->budget--) { s->failed_pc=0x0c08ef9eu; return 0; }
r[11]=read(ram,0x0c08f108u,4);
goto P_0c08efa0;
P_0c08efa0: /* original 99a1, guest PC 0x0c08efa0 */
if(!s->budget--) { s->failed_pc=0x0c08efa0u; return 0; }
r[9]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08f0e6u,2);
goto P_0c08efa2;
P_0c08efa2: /* original 4b0b, guest PC 0x0c08efa2 */
if(!s->budget--) { s->failed_pc=0x0c08efa2u; return 0; }
target=r[11];
r[16]=0x0c08efa6u;
r[4]=r[9];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08efa6u) { target=s->pc; goto dispatch; }
goto P_0c08efa6;
P_0c08efa4: /* original 6493, guest PC 0x0c08efa4 */
if(!s->budget--) { s->failed_pc=0x0c08efa4u; return 0; }
r[4]=r[9];
goto P_0c08efa6;
P_0c08efa6: /* original 4a0b, guest PC 0x0c08efa6 */
if(!s->budget--) { s->failed_pc=0x0c08efa6u; return 0; }
target=r[10];
r[16]=0x0c08efaau;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08efaau) { target=s->pc; goto dispatch; }
goto P_0c08efaa;
P_0c08efa8: /* original 0009, guest PC 0x0c08efa8 */
if(!s->budget--) { s->failed_pc=0x0c08efa8u; return 0; }
goto P_0c08efaa;
P_0c08efaa: /* original 909d, guest PC 0x0c08efaa */
if(!s->budget--) { s->failed_pc=0x0c08efaau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08f0e8u,2);
goto P_0c08efac;
P_0c08efac: /* original f4e6, guest PC 0x0c08efac */
if(!s->budget--) { s->failed_pc=0x0c08efacu; return 0; }
vf3_matrix_load(s,ram,4,r[14]+r[0]);
goto P_0c08efae;
P_0c08efae: /* original 7004, guest PC 0x0c08efae */
if(!s->budget--) { s->failed_pc=0x0c08efaeu; return 0; }
r[0]+=0x00000004u;
goto P_0c08efb0;
P_0c08efb0: /* original f5e6, guest PC 0x0c08efb0 */
if(!s->budget--) { s->failed_pc=0x0c08efb0u; return 0; }
vf3_matrix_load(s,ram,5,r[14]+r[0]);
goto P_0c08efb2;
P_0c08efb2: /* original 7004, guest PC 0x0c08efb2 */
if(!s->budget--) { s->failed_pc=0x0c08efb2u; return 0; }
r[0]+=0x00000004u;
goto P_0c08efb4;
P_0c08efb4: /* original f3e6, guest PC 0x0c08efb4 */
if(!s->budget--) { s->failed_pc=0x0c08efb4u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c08efb6;
P_0c08efb6: /* original e014, guest PC 0x0c08efb6 */
if(!s->budget--) { s->failed_pc=0x0c08efb6u; return 0; }
r[0]=0x00000014u;
goto P_0c08efb8;
P_0c08efb8: /* original ff37, guest PC 0x0c08efb8 */
if(!s->budget--) { s->failed_pc=0x0c08efb8u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c08efba;
P_0c08efba: /* original f63c, guest PC 0x0c08efba */
if(!s->budget--) { s->failed_pc=0x0c08efbau; return 0; }
vf3_matrix_move(s,6,3);
goto P_0c08efbc;
P_0c08efbc: /* original 4d0b, guest PC 0x0c08efbc */
if(!s->budget--) { s->failed_pc=0x0c08efbcu; return 0; }
target=r[13];
r[16]=0x0c08efc0u;
fr[6]^=0x80000000u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08efc0u) { target=s->pc; goto dispatch; }
goto P_0c08efc0;
P_0c08efbe: /* original f64d, guest PC 0x0c08efbe */
if(!s->budget--) { s->failed_pc=0x0c08efbeu; return 0; }
fr[6]^=0x80000000u;
goto P_0c08efc0;
P_0c08efc0: /* original f5fc, guest PC 0x0c08efc0 */
if(!s->budget--) { s->failed_pc=0x0c08efc0u; return 0; }
vf3_matrix_move(s,5,15);
goto P_0c08efc2;
P_0c08efc2: /* original f6fc, guest PC 0x0c08efc2 */
if(!s->budget--) { s->failed_pc=0x0c08efc2u; return 0; }
vf3_matrix_move(s,6,15);
goto P_0c08efc4;
P_0c08efc4: /* original 4c0b, guest PC 0x0c08efc4 */
if(!s->budget--) { s->failed_pc=0x0c08efc4u; return 0; }
target=r[12];
r[16]=0x0c08efc8u;
vf3_matrix_move(s,4,15);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08efc8u) { target=s->pc; goto dispatch; }
goto P_0c08efc8;
P_0c08efc6: /* original f4fc, guest PC 0x0c08efc6 */
if(!s->budget--) { s->failed_pc=0x0c08efc6u; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c08efc8;
P_0c08efc8: /* original 4b0b, guest PC 0x0c08efc8 */
if(!s->budget--) { s->failed_pc=0x0c08efc8u; return 0; }
target=r[11];
r[16]=0x0c08efccu;
r[4]=r[9];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08efccu) { target=s->pc; goto dispatch; }
goto P_0c08efcc;
P_0c08efca: /* original 6493, guest PC 0x0c08efca */
if(!s->budget--) { s->failed_pc=0x0c08efcau; return 0; }
r[4]=r[9];
goto P_0c08efcc;
P_0c08efcc: /* original 4a0b, guest PC 0x0c08efcc */
if(!s->budget--) { s->failed_pc=0x0c08efccu; return 0; }
target=r[10];
r[16]=0x0c08efd0u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08efd0u) { target=s->pc; goto dispatch; }
goto P_0c08efd0;
P_0c08efce: /* original 0009, guest PC 0x0c08efce */
if(!s->budget--) { s->failed_pc=0x0c08efceu; return 0; }
goto P_0c08efd0;
P_0c08efd0: /* original 85ef, guest PC 0x0c08efd0 */
if(!s->budget--) { s->failed_pc=0x0c08efd0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+30,2);
goto P_0c08efd2;
P_0c08efd2: /* original d84e, guest PC 0x0c08efd2 */
if(!s->budget--) { s->failed_pc=0x0c08efd2u; return 0; }
r[8]=read(ram,0x0c08f10cu,4);
goto P_0c08efd4;
P_0c08efd4: /* original 480b, guest PC 0x0c08efd4 */
if(!s->budget--) { s->failed_pc=0x0c08efd4u; return 0; }
target=r[8];
r[16]=0x0c08efd8u;
r[4]=r[0];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08efd8u) { target=s->pc; goto dispatch; }
goto P_0c08efd8;
P_0c08efd6: /* original 6403, guest PC 0x0c08efd6 */
if(!s->budget--) { s->failed_pc=0x0c08efd6u; return 0; }
r[4]=r[0];
goto P_0c08efd8;
P_0c08efd8: /* original d34d, guest PC 0x0c08efd8 */
if(!s->budget--) { s->failed_pc=0x0c08efd8u; return 0; }
r[3]=read(ram,0x0c08f110u,4);
goto P_0c08efda;
P_0c08efda: /* original 85ee, guest PC 0x0c08efda */
if(!s->budget--) { s->failed_pc=0x0c08efdau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+28,2);
goto P_0c08efdc;
P_0c08efdc: /* original 430b, guest PC 0x0c08efdc */
if(!s->budget--) { s->failed_pc=0x0c08efdcu; return 0; }
target=r[3];
r[16]=0x0c08efe0u;
r[4]=r[0];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08efe0u) { target=s->pc; goto dispatch; }
goto P_0c08efe0;
P_0c08efde: /* original 6403, guest PC 0x0c08efde */
if(!s->budget--) { s->failed_pc=0x0c08efdeu; return 0; }
r[4]=r[0];
goto P_0c08efe0;
P_0c08efe0: /* original e004, guest PC 0x0c08efe0 */
if(!s->budget--) { s->failed_pc=0x0c08efe0u; return 0; }
r[0]=0x00000004u;
goto P_0c08efe2;
P_0c08efe2: /* original f5f8, guest PC 0x0c08efe2 */
if(!s->budget--) { s->failed_pc=0x0c08efe2u; return 0; }
vf3_matrix_load(s,ram,5,r[15]);
goto P_0c08efe4;
P_0c08efe4: /* original f4f6, guest PC 0x0c08efe4 */
if(!s->budget--) { s->failed_pc=0x0c08efe4u; return 0; }
vf3_matrix_load(s,ram,4,r[15]+r[0]);
goto P_0c08efe6;
P_0c08efe6: /* original e008, guest PC 0x0c08efe6 */
if(!s->budget--) { s->failed_pc=0x0c08efe6u; return 0; }
r[0]=0x00000008u;
goto P_0c08efe8;
P_0c08efe8: /* original f3f6, guest PC 0x0c08efe8 */
if(!s->budget--) { s->failed_pc=0x0c08efe8u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c08efea;
P_0c08efea: /* original e020, guest PC 0x0c08efea */
if(!s->budget--) { s->failed_pc=0x0c08efeau; return 0; }
r[0]=0x00000020u;
goto P_0c08efec;
P_0c08efec: /* original ff37, guest PC 0x0c08efec */
if(!s->budget--) { s->failed_pc=0x0c08efecu; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c08efee;
P_0c08efee: /* original f63c, guest PC 0x0c08efee */
if(!s->budget--) { s->failed_pc=0x0c08efeeu; return 0; }
vf3_matrix_move(s,6,3);
goto P_0c08eff0;
P_0c08eff0: /* original 4d0b, guest PC 0x0c08eff0 */
if(!s->budget--) { s->failed_pc=0x0c08eff0u; return 0; }
target=r[13];
r[16]=0x0c08eff4u;
fr[6]^=0x80000000u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08eff4u) { target=s->pc; goto dispatch; }
goto P_0c08eff4;
P_0c08eff2: /* original f64d, guest PC 0x0c08eff2 */
if(!s->budget--) { s->failed_pc=0x0c08eff2u; return 0; }
fr[6]^=0x80000000u;
goto P_0c08eff4;
P_0c08eff4: /* original d346, guest PC 0x0c08eff4 */
if(!s->budget--) { s->failed_pc=0x0c08eff4u; return 0; }
r[3]=read(ram,0x0c08f110u,4);
goto P_0c08eff6;
P_0c08eff6: /* original 85ee, guest PC 0x0c08eff6 */
if(!s->budget--) { s->failed_pc=0x0c08eff6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+28,2);
goto P_0c08eff8;
P_0c08eff8: /* original 430b, guest PC 0x0c08eff8 */
if(!s->budget--) { s->failed_pc=0x0c08eff8u; return 0; }
target=r[3];
r[16]=0x0c08effcu;
r[4]=0u-r[0];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08effcu) { target=s->pc; goto dispatch; }
goto P_0c08effc;
P_0c08effa: /* original 640b, guest PC 0x0c08effa */
if(!s->budget--) { s->failed_pc=0x0c08effau; return 0; }
r[4]=0u-r[0];
goto P_0c08effc;
P_0c08effc: /* original 85ef, guest PC 0x0c08effc */
if(!s->budget--) { s->failed_pc=0x0c08effcu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+30,2);
goto P_0c08effe;
P_0c08effe: /* original 480b, guest PC 0x0c08effe */
if(!s->budget--) { s->failed_pc=0x0c08effeu; return 0; }
target=r[8];
r[16]=0x0c08f002u;
r[4]=0u-r[0];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08f002u) { target=s->pc; goto dispatch; }
goto P_0c08f002;
P_0c08f000: /* original 640b, guest PC 0x0c08f000 */
if(!s->budget--) { s->failed_pc=0x0c08f000u; return 0; }
r[4]=0u-r[0];
goto P_0c08f002;
P_0c08f002: /* original 9072, guest PC 0x0c08f002 */
if(!s->budget--) { s->failed_pc=0x0c08f002u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08f0eau,2);
goto P_0c08f004;
P_0c08f004: /* original f6e6, guest PC 0x0c08f004 */
if(!s->budget--) { s->failed_pc=0x0c08f004u; return 0; }
vf3_matrix_load(s,ram,6,r[14]+r[0]);
goto P_0c08f006;
P_0c08f006: /* original 70fc, guest PC 0x0c08f006 */
if(!s->budget--) { s->failed_pc=0x0c08f006u; return 0; }
r[0]+=0xfffffffcu;
goto P_0c08f008;
P_0c08f008: /* original f5e6, guest PC 0x0c08f008 */
if(!s->budget--) { s->failed_pc=0x0c08f008u; return 0; }
vf3_matrix_load(s,ram,5,r[14]+r[0]);
goto P_0c08f00a;
P_0c08f00a: /* original 70fc, guest PC 0x0c08f00a */
if(!s->budget--) { s->failed_pc=0x0c08f00au; return 0; }
r[0]+=0xfffffffcu;
goto P_0c08f00c;
P_0c08f00c: /* original f64d, guest PC 0x0c08f00c */
if(!s->budget--) { s->failed_pc=0x0c08f00cu; return 0; }
fr[6]^=0x80000000u;
goto P_0c08f00e;
P_0c08f00e: /* original 4d0b, guest PC 0x0c08f00e */
if(!s->budget--) { s->failed_pc=0x0c08f00eu; return 0; }
target=r[13];
r[16]=0x0c08f012u;
vf3_matrix_load(s,ram,4,r[14]+r[0]);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08f012u) { target=s->pc; goto dispatch; }
goto P_0c08f012;
P_0c08f010: /* original f4e6, guest PC 0x0c08f010 */
if(!s->budget--) { s->failed_pc=0x0c08f010u; return 0; }
vf3_matrix_load(s,ram,4,r[14]+r[0]);
goto P_0c08f012;
P_0c08f012: /* original f5fc, guest PC 0x0c08f012 */
if(!s->budget--) { s->failed_pc=0x0c08f012u; return 0; }
vf3_matrix_move(s,5,15);
goto P_0c08f014;
P_0c08f014: /* original f6fc, guest PC 0x0c08f014 */
if(!s->budget--) { s->failed_pc=0x0c08f014u; return 0; }
vf3_matrix_move(s,6,15);
goto P_0c08f016;
P_0c08f016: /* original 4c0b, guest PC 0x0c08f016 */
if(!s->budget--) { s->failed_pc=0x0c08f016u; return 0; }
target=r[12];
r[16]=0x0c08f01au;
vf3_matrix_move(s,4,15);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08f01au) { target=s->pc; goto dispatch; }
goto P_0c08f01a;
P_0c08f018: /* original f4fc, guest PC 0x0c08f018 */
if(!s->budget--) { s->failed_pc=0x0c08f018u; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c08f01a;
P_0c08f01a: /* original c73e, guest PC 0x0c08f01a */
if(!s->budget--) { s->failed_pc=0x0c08f01au; return 0; }
r[0]=0x0c08f114u;
goto P_0c08f01c;
P_0c08f01c: /* original fe08, guest PC 0x0c08f01c */
if(!s->budget--) { s->failed_pc=0x0c08f01cu; return 0; }
vf3_matrix_load(s,ram,14,r[0]);
goto P_0c08f01e;
P_0c08f01e: /* original f5ec, guest PC 0x0c08f01e */
if(!s->budget--) { s->failed_pc=0x0c08f01eu; return 0; }
vf3_matrix_move(s,5,14);
goto P_0c08f020;
P_0c08f020: /* original f6ec, guest PC 0x0c08f020 */
if(!s->budget--) { s->failed_pc=0x0c08f020u; return 0; }
vf3_matrix_move(s,6,14);
goto P_0c08f022;
P_0c08f022: /* original 4c0b, guest PC 0x0c08f022 */
if(!s->budget--) { s->failed_pc=0x0c08f022u; return 0; }
target=r[12];
r[16]=0x0c08f026u;
vf3_matrix_move(s,4,14);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08f026u) { target=s->pc; goto dispatch; }
goto P_0c08f026;
P_0c08f024: /* original f4ec, guest PC 0x0c08f024 */
if(!s->budget--) { s->failed_pc=0x0c08f024u; return 0; }
vf3_matrix_move(s,4,14);
goto P_0c08f026;
P_0c08f026: /* original 9461, guest PC 0x0c08f026 */
if(!s->budget--) { s->failed_pc=0x0c08f026u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08f0ecu,2);
goto P_0c08f028;
P_0c08f028: /* original 4b0b, guest PC 0x0c08f028 */
if(!s->budget--) { s->failed_pc=0x0c08f028u; return 0; }
target=r[11];
r[16]=0x0c08f02cu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08f02cu) { target=s->pc; goto dispatch; }
goto P_0c08f02c;
P_0c08f02a: /* original 0009, guest PC 0x0c08f02a */
if(!s->budget--) { s->failed_pc=0x0c08f02au; return 0; }
goto P_0c08f02c;
P_0c08f02c: /* original 4a0b, guest PC 0x0c08f02c */
if(!s->budget--) { s->failed_pc=0x0c08f02cu; return 0; }
target=r[10];
r[16]=0x0c08f030u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08f030u) { target=s->pc; goto dispatch; }
goto P_0c08f030;
P_0c08f02e: /* original 0009, guest PC 0x0c08f02e */
if(!s->budget--) { s->failed_pc=0x0c08f02eu; return 0; }
goto P_0c08f030;
P_0c08f030: /* original 905d, guest PC 0x0c08f030 */
if(!s->budget--) { s->failed_pc=0x0c08f030u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08f0eeu,2);
goto P_0c08f032;
P_0c08f032: /* original f6e6, guest PC 0x0c08f032 */
if(!s->budget--) { s->failed_pc=0x0c08f032u; return 0; }
vf3_matrix_load(s,ram,6,r[14]+r[0]);
goto P_0c08f034;
P_0c08f034: /* original 70fc, guest PC 0x0c08f034 */
if(!s->budget--) { s->failed_pc=0x0c08f034u; return 0; }
r[0]+=0xfffffffcu;
goto P_0c08f036;
P_0c08f036: /* original f5e6, guest PC 0x0c08f036 */
if(!s->budget--) { s->failed_pc=0x0c08f036u; return 0; }
vf3_matrix_load(s,ram,5,r[14]+r[0]);
goto P_0c08f038;
P_0c08f038: /* original 70fc, guest PC 0x0c08f038 */
if(!s->budget--) { s->failed_pc=0x0c08f038u; return 0; }
r[0]+=0xfffffffcu;
goto P_0c08f03a;
P_0c08f03a: /* original f64d, guest PC 0x0c08f03a */
if(!s->budget--) { s->failed_pc=0x0c08f03au; return 0; }
fr[6]^=0x80000000u;
goto P_0c08f03c;
P_0c08f03c: /* original 4d0b, guest PC 0x0c08f03c */
if(!s->budget--) { s->failed_pc=0x0c08f03cu; return 0; }
target=r[13];
r[16]=0x0c08f040u;
vf3_matrix_load(s,ram,4,r[14]+r[0]);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08f040u) { target=s->pc; goto dispatch; }
goto P_0c08f040;
P_0c08f03e: /* original f4e6, guest PC 0x0c08f03e */
if(!s->budget--) { s->failed_pc=0x0c08f03eu; return 0; }
vf3_matrix_load(s,ram,4,r[14]+r[0]);
goto P_0c08f040;
P_0c08f040: /* original f5fc, guest PC 0x0c08f040 */
if(!s->budget--) { s->failed_pc=0x0c08f040u; return 0; }
vf3_matrix_move(s,5,15);
goto P_0c08f042;
P_0c08f042: /* original f6fc, guest PC 0x0c08f042 */
if(!s->budget--) { s->failed_pc=0x0c08f042u; return 0; }
vf3_matrix_move(s,6,15);
goto P_0c08f044;
P_0c08f044: /* original 4c0b, guest PC 0x0c08f044 */
if(!s->budget--) { s->failed_pc=0x0c08f044u; return 0; }
target=r[12];
r[16]=0x0c08f048u;
vf3_matrix_move(s,4,15);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08f048u) { target=s->pc; goto dispatch; }
goto P_0c08f048;
P_0c08f046: /* original f4fc, guest PC 0x0c08f046 */
if(!s->budget--) { s->failed_pc=0x0c08f046u; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c08f048;
P_0c08f048: /* original 4b0b, guest PC 0x0c08f048 */
if(!s->budget--) { s->failed_pc=0x0c08f048u; return 0; }
target=r[11];
r[16]=0x0c08f04cu;
r[4]=r[9];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08f04cu) { target=s->pc; goto dispatch; }
goto P_0c08f04c;
P_0c08f04a: /* original 6493, guest PC 0x0c08f04a */
if(!s->budget--) { s->failed_pc=0x0c08f04au; return 0; }
r[4]=r[9];
goto P_0c08f04c;
P_0c08f04c: /* original 4a0b, guest PC 0x0c08f04c */
if(!s->budget--) { s->failed_pc=0x0c08f04cu; return 0; }
target=r[10];
r[16]=0x0c08f050u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08f050u) { target=s->pc; goto dispatch; }
goto P_0c08f050;
P_0c08f04e: /* original 0009, guest PC 0x0c08f04e */
if(!s->budget--) { s->failed_pc=0x0c08f04eu; return 0; }
goto P_0c08f050;
P_0c08f050: /* original 85ef, guest PC 0x0c08f050 */
if(!s->budget--) { s->failed_pc=0x0c08f050u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+30,2);
goto P_0c08f052;
P_0c08f052: /* original 480b, guest PC 0x0c08f052 */
if(!s->budget--) { s->failed_pc=0x0c08f052u; return 0; }
target=r[8];
r[16]=0x0c08f056u;
r[4]=r[0];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08f056u) { target=s->pc; goto dispatch; }
goto P_0c08f056;
P_0c08f054: /* original 6403, guest PC 0x0c08f054 */
if(!s->budget--) { s->failed_pc=0x0c08f054u; return 0; }
r[4]=r[0];
goto P_0c08f056;
P_0c08f056: /* original d32e, guest PC 0x0c08f056 */
if(!s->budget--) { s->failed_pc=0x0c08f056u; return 0; }
r[3]=read(ram,0x0c08f110u,4);
goto P_0c08f058;
P_0c08f058: /* original 85ee, guest PC 0x0c08f058 */
if(!s->budget--) { s->failed_pc=0x0c08f058u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+28,2);
goto P_0c08f05a;
P_0c08f05a: /* original 430b, guest PC 0x0c08f05a */
if(!s->budget--) { s->failed_pc=0x0c08f05au; return 0; }
target=r[3];
r[16]=0x0c08f05eu;
r[4]=r[0];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08f05eu) { target=s->pc; goto dispatch; }
goto P_0c08f05e;
P_0c08f05c: /* original 6403, guest PC 0x0c08f05c */
if(!s->budget--) { s->failed_pc=0x0c08f05cu; return 0; }
r[4]=r[0];
goto P_0c08f05e;
P_0c08f05e: /* original e004, guest PC 0x0c08f05e */
if(!s->budget--) { s->failed_pc=0x0c08f05eu; return 0; }
r[0]=0x00000004u;
goto P_0c08f060;
P_0c08f060: /* original f5f8, guest PC 0x0c08f060 */
if(!s->budget--) { s->failed_pc=0x0c08f060u; return 0; }
vf3_matrix_load(s,ram,5,r[15]);
goto P_0c08f062;
P_0c08f062: /* original f4f6, guest PC 0x0c08f062 */
if(!s->budget--) { s->failed_pc=0x0c08f062u; return 0; }
vf3_matrix_load(s,ram,4,r[15]+r[0]);
goto P_0c08f064;
P_0c08f064: /* original e008, guest PC 0x0c08f064 */
if(!s->budget--) { s->failed_pc=0x0c08f064u; return 0; }
r[0]=0x00000008u;
goto P_0c08f066;
P_0c08f066: /* original f3f6, guest PC 0x0c08f066 */
if(!s->budget--) { s->failed_pc=0x0c08f066u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c08f068;
P_0c08f068: /* original e010, guest PC 0x0c08f068 */
if(!s->budget--) { s->failed_pc=0x0c08f068u; return 0; }
r[0]=0x00000010u;
goto P_0c08f06a;
P_0c08f06a: /* original ff37, guest PC 0x0c08f06a */
if(!s->budget--) { s->failed_pc=0x0c08f06au; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c08f06c;
P_0c08f06c: /* original f63c, guest PC 0x0c08f06c */
if(!s->budget--) { s->failed_pc=0x0c08f06cu; return 0; }
vf3_matrix_move(s,6,3);
goto P_0c08f06e;
P_0c08f06e: /* original 4d0b, guest PC 0x0c08f06e */
if(!s->budget--) { s->failed_pc=0x0c08f06eu; return 0; }
target=r[13];
r[16]=0x0c08f072u;
fr[6]^=0x80000000u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08f072u) { target=s->pc; goto dispatch; }
goto P_0c08f072;
P_0c08f070: /* original f64d, guest PC 0x0c08f070 */
if(!s->budget--) { s->failed_pc=0x0c08f070u; return 0; }
fr[6]^=0x80000000u;
goto P_0c08f072;
P_0c08f072: /* original d327, guest PC 0x0c08f072 */
if(!s->budget--) { s->failed_pc=0x0c08f072u; return 0; }
r[3]=read(ram,0x0c08f110u,4);
goto P_0c08f074;
P_0c08f074: /* original 85ee, guest PC 0x0c08f074 */
if(!s->budget--) { s->failed_pc=0x0c08f074u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+28,2);
goto P_0c08f076;
P_0c08f076: /* original 430b, guest PC 0x0c08f076 */
if(!s->budget--) { s->failed_pc=0x0c08f076u; return 0; }
target=r[3];
r[16]=0x0c08f07au;
r[4]=0u-r[0];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08f07au) { target=s->pc; goto dispatch; }
goto P_0c08f07a;
P_0c08f078: /* original 640b, guest PC 0x0c08f078 */
if(!s->budget--) { s->failed_pc=0x0c08f078u; return 0; }
r[4]=0u-r[0];
goto P_0c08f07a;
P_0c08f07a: /* original 85ef, guest PC 0x0c08f07a */
if(!s->budget--) { s->failed_pc=0x0c08f07au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+30,2);
goto P_0c08f07c;
P_0c08f07c: /* original 480b, guest PC 0x0c08f07c */
if(!s->budget--) { s->failed_pc=0x0c08f07cu; return 0; }
target=r[8];
r[16]=0x0c08f080u;
r[4]=0u-r[0];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08f080u) { target=s->pc; goto dispatch; }
goto P_0c08f080;
P_0c08f07e: /* original 640b, guest PC 0x0c08f07e */
if(!s->budget--) { s->failed_pc=0x0c08f07eu; return 0; }
r[4]=0u-r[0];
goto P_0c08f080;
P_0c08f080: /* original 9036, guest PC 0x0c08f080 */
if(!s->budget--) { s->failed_pc=0x0c08f080u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08f0f0u,2);
goto P_0c08f082;
P_0c08f082: /* original f4e6, guest PC 0x0c08f082 */
if(!s->budget--) { s->failed_pc=0x0c08f082u; return 0; }
vf3_matrix_load(s,ram,4,r[14]+r[0]);
goto P_0c08f084;
P_0c08f084: /* original 7004, guest PC 0x0c08f084 */
if(!s->budget--) { s->failed_pc=0x0c08f084u; return 0; }
r[0]+=0x00000004u;
goto P_0c08f086;
P_0c08f086: /* original f5e6, guest PC 0x0c08f086 */
if(!s->budget--) { s->failed_pc=0x0c08f086u; return 0; }
vf3_matrix_load(s,ram,5,r[14]+r[0]);
goto P_0c08f088;
P_0c08f088: /* original 7004, guest PC 0x0c08f088 */
if(!s->budget--) { s->failed_pc=0x0c08f088u; return 0; }
r[0]+=0x00000004u;
goto P_0c08f08a;
P_0c08f08a: /* original f3e6, guest PC 0x0c08f08a */
if(!s->budget--) { s->failed_pc=0x0c08f08au; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c08f08c;
P_0c08f08c: /* original e00c, guest PC 0x0c08f08c */
if(!s->budget--) { s->failed_pc=0x0c08f08cu; return 0; }
r[0]=0x0000000cu;
goto P_0c08f08e;
P_0c08f08e: /* original ff37, guest PC 0x0c08f08e */
if(!s->budget--) { s->failed_pc=0x0c08f08eu; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c08f090;
P_0c08f090: /* original f63c, guest PC 0x0c08f090 */
if(!s->budget--) { s->failed_pc=0x0c08f090u; return 0; }
vf3_matrix_move(s,6,3);
goto P_0c08f092;
P_0c08f092: /* original 4d0b, guest PC 0x0c08f092 */
if(!s->budget--) { s->failed_pc=0x0c08f092u; return 0; }
target=r[13];
r[16]=0x0c08f096u;
fr[6]^=0x80000000u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08f096u) { target=s->pc; goto dispatch; }
goto P_0c08f096;
P_0c08f094: /* original f64d, guest PC 0x0c08f094 */
if(!s->budget--) { s->failed_pc=0x0c08f094u; return 0; }
fr[6]^=0x80000000u;
goto P_0c08f096;
P_0c08f096: /* original f5fc, guest PC 0x0c08f096 */
if(!s->budget--) { s->failed_pc=0x0c08f096u; return 0; }
vf3_matrix_move(s,5,15);
goto P_0c08f098;
P_0c08f098: /* original f6fc, guest PC 0x0c08f098 */
if(!s->budget--) { s->failed_pc=0x0c08f098u; return 0; }
vf3_matrix_move(s,6,15);
goto P_0c08f09a;
P_0c08f09a: /* original 4c0b, guest PC 0x0c08f09a */
if(!s->budget--) { s->failed_pc=0x0c08f09au; return 0; }
target=r[12];
r[16]=0x0c08f09eu;
vf3_matrix_move(s,4,15);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08f09eu) { target=s->pc; goto dispatch; }
goto P_0c08f09e;
P_0c08f09c: /* original f4fc, guest PC 0x0c08f09c */
if(!s->budget--) { s->failed_pc=0x0c08f09cu; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c08f09e;
P_0c08f09e: /* original 4b0b, guest PC 0x0c08f09e */
if(!s->budget--) { s->failed_pc=0x0c08f09eu; return 0; }
target=r[11];
r[16]=0x0c08f0a2u;
r[4]=r[9];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08f0a2u) { target=s->pc; goto dispatch; }
goto P_0c08f0a2;
P_0c08f0a0: /* original 6493, guest PC 0x0c08f0a0 */
if(!s->budget--) { s->failed_pc=0x0c08f0a0u; return 0; }
r[4]=r[9];
goto P_0c08f0a2;
P_0c08f0a2: /* original 4a0b, guest PC 0x0c08f0a2 */
if(!s->budget--) { s->failed_pc=0x0c08f0a2u; return 0; }
target=r[10];
r[16]=0x0c08f0a6u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08f0a6u) { target=s->pc; goto dispatch; }
goto P_0c08f0a6;
P_0c08f0a4: /* original 0009, guest PC 0x0c08f0a4 */
if(!s->budget--) { s->failed_pc=0x0c08f0a4u; return 0; }
goto P_0c08f0a6;
P_0c08f0a6: /* original 9024, guest PC 0x0c08f0a6 */
if(!s->budget--) { s->failed_pc=0x0c08f0a6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08f0f2u,2);
goto P_0c08f0a8;
P_0c08f0a8: /* original f4e6, guest PC 0x0c08f0a8 */
if(!s->budget--) { s->failed_pc=0x0c08f0a8u; return 0; }
vf3_matrix_load(s,ram,4,r[14]+r[0]);
goto P_0c08f0aa;
P_0c08f0aa: /* original 7004, guest PC 0x0c08f0aa */
if(!s->budget--) { s->failed_pc=0x0c08f0aau; return 0; }
r[0]+=0x00000004u;
goto P_0c08f0ac;
P_0c08f0ac: /* original f5e6, guest PC 0x0c08f0ac */
if(!s->budget--) { s->failed_pc=0x0c08f0acu; return 0; }
vf3_matrix_load(s,ram,5,r[14]+r[0]);
goto P_0c08f0ae;
P_0c08f0ae: /* original 7004, guest PC 0x0c08f0ae */
if(!s->budget--) { s->failed_pc=0x0c08f0aeu; return 0; }
r[0]+=0x00000004u;
goto P_0c08f0b0;
P_0c08f0b0: /* original f3e6, guest PC 0x0c08f0b0 */
if(!s->budget--) { s->failed_pc=0x0c08f0b0u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c08f0b2;
P_0c08f0b2: /* original e018, guest PC 0x0c08f0b2 */
if(!s->budget--) { s->failed_pc=0x0c08f0b2u; return 0; }
r[0]=0x00000018u;
goto P_0c08f0b4;
P_0c08f0b4: /* original ff37, guest PC 0x0c08f0b4 */
if(!s->budget--) { s->failed_pc=0x0c08f0b4u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c08f0b6;
P_0c08f0b6: /* original f63c, guest PC 0x0c08f0b6 */
if(!s->budget--) { s->failed_pc=0x0c08f0b6u; return 0; }
vf3_matrix_move(s,6,3);
goto P_0c08f0b8;
P_0c08f0b8: /* original 4d0b, guest PC 0x0c08f0b8 */
if(!s->budget--) { s->failed_pc=0x0c08f0b8u; return 0; }
target=r[13];
r[16]=0x0c08f0bcu;
fr[6]^=0x80000000u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08f0bcu) { target=s->pc; goto dispatch; }
goto P_0c08f0bc;
P_0c08f0ba: /* original f64d, guest PC 0x0c08f0ba */
if(!s->budget--) { s->failed_pc=0x0c08f0bau; return 0; }
fr[6]^=0x80000000u;
goto P_0c08f0bc;
P_0c08f0bc: /* original f5fc, guest PC 0x0c08f0bc */
if(!s->budget--) { s->failed_pc=0x0c08f0bcu; return 0; }
vf3_matrix_move(s,5,15);
goto P_0c08f0be;
P_0c08f0be: /* original f6fc, guest PC 0x0c08f0be */
if(!s->budget--) { s->failed_pc=0x0c08f0beu; return 0; }
vf3_matrix_move(s,6,15);
goto P_0c08f0c0;
P_0c08f0c0: /* original 4c0b, guest PC 0x0c08f0c0 */
if(!s->budget--) { s->failed_pc=0x0c08f0c0u; return 0; }
target=r[12];
r[16]=0x0c08f0c4u;
vf3_matrix_move(s,4,15);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08f0c4u) { target=s->pc; goto dispatch; }
goto P_0c08f0c4;
P_0c08f0c2: /* original f4fc, guest PC 0x0c08f0c2 */
if(!s->budget--) { s->failed_pc=0x0c08f0c2u; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c08f0c4;
P_0c08f0c4: /* original 4b0b, guest PC 0x0c08f0c4 */
if(!s->budget--) { s->failed_pc=0x0c08f0c4u; return 0; }
target=r[11];
r[16]=0x0c08f0c8u;
r[4]=r[9];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08f0c8u) { target=s->pc; goto dispatch; }
goto P_0c08f0c8;
P_0c08f0c6: /* original 6493, guest PC 0x0c08f0c6 */
if(!s->budget--) { s->failed_pc=0x0c08f0c6u; return 0; }
r[4]=r[9];
goto P_0c08f0c8;
P_0c08f0c8: /* original d313, guest PC 0x0c08f0c8 */
if(!s->budget--) { s->failed_pc=0x0c08f0c8u; return 0; }
r[3]=read(ram,0x0c08f118u,4);
goto P_0c08f0ca;
P_0c08f0ca: /* original 430b, guest PC 0x0c08f0ca */
if(!s->budget--) { s->failed_pc=0x0c08f0cau; return 0; }
target=r[3];
r[16]=0x0c08f0ceu;
r[4]=0x00000001u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08f0ceu) { target=s->pc; goto dispatch; }
goto P_0c08f0ce;
P_0c08f0cc: /* original e401, guest PC 0x0c08f0cc */
if(!s->budget--) { s->failed_pc=0x0c08f0ccu; return 0; }
r[4]=0x00000001u;
goto P_0c08f0ce;
P_0c08f0ce: /* original 7f24, guest PC 0x0c08f0ce */
if(!s->budget--) { s->failed_pc=0x0c08f0ceu; return 0; }
r[15]+=0x00000024u;
goto P_0c08f0d0;
P_0c08f0d0: /* original 4f26, guest PC 0x0c08f0d0 */
if(!s->budget--) { s->failed_pc=0x0c08f0d0u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c08f0d2;
P_0c08f0d2: /* original fef9, guest PC 0x0c08f0d2 */
if(!s->budget--) { s->failed_pc=0x0c08f0d2u; return 0; }
vf3_matrix_load(s,ram,14,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c08f0d4;
P_0c08f0d4: /* original fff9, guest PC 0x0c08f0d4 */
if(!s->budget--) { s->failed_pc=0x0c08f0d4u; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c08f0d6;
P_0c08f0d6: /* original 68f6, guest PC 0x0c08f0d6 */
if(!s->budget--) { s->failed_pc=0x0c08f0d6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c08f0d8;
P_0c08f0d8: /* original 69f6, guest PC 0x0c08f0d8 */
if(!s->budget--) { s->failed_pc=0x0c08f0d8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c08f0da;
P_0c08f0da: /* original 6af6, guest PC 0x0c08f0da */
if(!s->budget--) { s->failed_pc=0x0c08f0dau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c08f0dc;
P_0c08f0dc: /* original 6bf6, guest PC 0x0c08f0dc */
if(!s->budget--) { s->failed_pc=0x0c08f0dcu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c08f0de;
P_0c08f0de: /* original 6cf6, guest PC 0x0c08f0de */
if(!s->budget--) { s->failed_pc=0x0c08f0deu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c08f0e0;
P_0c08f0e0: /* original 6df6, guest PC 0x0c08f0e0 */
if(!s->budget--) { s->failed_pc=0x0c08f0e0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c08f0e2;
P_0c08f0e2: /* original 000b, guest PC 0x0c08f0e2 */
if(!s->budget--) { s->failed_pc=0x0c08f0e2u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c08f0e4: /* original 6ef6, guest PC 0x0c08f0e4 */
if(!s->budget--) { s->failed_pc=0x0c08f0e4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c08f0e6u,s,ram);
unsupported: s->failed_pc=target; return 0;
}
static const uint32_t owned_pcs[]={
0x0c081e7cu,0x0c081e7eu,0x0c081e80u,0x0c081e82u,0x0c081e84u,0x0c081e86u,0x0c081e88u,0x0c081e8au,0x0c081e8cu,0x0c081e8eu,0x0c081e90u,0x0c081e92u,0x0c081e94u,0x0c081e96u,0x0c081e98u,0x0c081e9au,
0x0c081e9cu,0x0c081e9eu,0x0c081ea0u,0x0c081ea2u,0x0c081ea4u,0x0c081ea6u,0x0c081ea8u,0x0c081eaau,0x0c081eacu,0x0c081eaeu,0x0c081eb0u,0x0c081eb2u,0x0c081eb4u,0x0c081eb6u,0x0c081eb8u,0x0c081ebau,
0x0c081ebcu,0x0c081ebeu,0x0c081ec0u,0x0c081ec2u,0x0c081ec4u,0x0c081ec6u,0x0c081ec8u,0x0c081ecau,0x0c081eccu,0x0c081eceu,0x0c081ed0u,0x0c081ed2u,0x0c081ed4u,0x0c081ed6u,0x0c081ed8u,0x0c081edau,
0x0c081edcu,0x0c081edeu,0x0c081ee0u,0x0c081ee2u,0x0c081ee4u,0x0c081ee6u,0x0c081ee8u,0x0c081eeau,0x0c081eecu,0x0c081eeeu,0x0c081ef0u,0x0c081ef2u,0x0c081ef4u,0x0c081ef6u,0x0c081ef8u,0x0c081efau,
0x0c081efcu,0x0c081efeu,0x0c081f00u,0x0c081f02u,0x0c081f04u,0x0c081f06u,0x0c081f08u,0x0c081f0au,0x0c081f0cu,0x0c081f0eu,0x0c081f10u,0x0c081f12u,0x0c081f14u,0x0c081f16u,0x0c081f18u,0x0c081f1au,
0x0c081f1cu,0x0c081f1eu,0x0c081f20u,0x0c081f22u,0x0c081f24u,0x0c081f26u,0x0c081f28u,0x0c081f2au,0x0c081f2cu,0x0c081f2eu,0x0c081f30u,0x0c081f32u,0x0c081f34u,0x0c081f36u,0x0c081f38u,0x0c081f3au,
0x0c081f3cu,0x0c081f3eu,0x0c081f40u,0x0c081f42u,0x0c081f44u,0x0c081f46u,0x0c081f48u,0x0c081f4au,0x0c081f4cu,0x0c081f4eu,0x0c081f50u,0x0c081f52u,0x0c081f54u,0x0c081f56u,0x0c081f58u,0x0c081f5au,
0x0c081f5cu,0x0c081f5eu,0x0c081f60u,0x0c081f62u,0x0c081f64u,0x0c081f66u,0x0c081f68u,0x0c081f6au,0x0c081f6cu,0x0c081f6eu,0x0c081f70u,0x0c081f72u,0x0c081f74u,0x0c081f76u,0x0c081f78u,0x0c081f7au,
0x0c081f7cu,0x0c081f7eu,0x0c081f80u,0x0c081f82u,0x0c08af6cu,0x0c08af6eu,0x0c08af70u,0x0c08af72u,0x0c08af74u,0x0c08af76u,0x0c08af78u,0x0c08af7au,0x0c08af7cu,0x0c08af7eu,0x0c08af80u,0x0c08af82u,
0x0c08af84u,0x0c08af86u,0x0c08af88u,0x0c08af8au,0x0c08af8cu,0x0c08af8eu,0x0c08af90u,0x0c08af92u,0x0c08af94u,0x0c08af96u,0x0c08af98u,0x0c08af9au,0x0c08af9cu,0x0c08af9eu,0x0c08afa0u,0x0c08afa2u,
0x0c08afa4u,0x0c08afa6u,0x0c08afa8u,0x0c08afaau,0x0c08afacu,0x0c08afaeu,0x0c08afb0u,0x0c08aff4u,0x0c08aff6u,0x0c08aff8u,0x0c08affau,0x0c08affcu,0x0c08affeu,0x0c08b000u,0x0c08b002u,0x0c08b004u,
0x0c08b006u,0x0c08b008u,0x0c08b00au,0x0c08b00cu,0x0c08b00eu,0x0c08b010u,0x0c08b012u,0x0c08b014u,0x0c08b016u,0x0c08b018u,0x0c08b01au,0x0c08b01cu,0x0c08b01eu,0x0c08b020u,0x0c08b022u,0x0c08b024u,
0x0c08b026u,0x0c08b028u,0x0c08b02au,0x0c08b02cu,0x0c08b02eu,0x0c08b030u,0x0c08b032u,0x0c08b034u,0x0c08b036u,0x0c08b038u,0x0c08b03au,0x0c08b03cu,0x0c08b03eu,0x0c08b040u,0x0c08b042u,0x0c08b044u,
0x0c08b046u,0x0c08b048u,0x0c08b04au,0x0c08b04cu,0x0c08b04eu,0x0c08b050u,0x0c08b052u,0x0c08b054u,0x0c08b056u,0x0c08b058u,0x0c08b05au,0x0c08b05cu,0x0c08b05eu,0x0c08b060u,0x0c08b062u,0x0c08b064u,
0x0c08b066u,0x0c08b068u,0x0c08b06au,0x0c08b06cu,0x0c08b06eu,0x0c08b070u,0x0c08b072u,0x0c08b074u,0x0c08b076u,0x0c08b078u,0x0c08b07au,0x0c08b07cu,0x0c08b07eu,0x0c08b080u,0x0c08b082u,0x0c08b084u,
0x0c08b086u,0x0c08b088u,0x0c08b08au,0x0c08b08cu,0x0c08b08eu,0x0c08b090u,0x0c08b092u,0x0c08b094u,0x0c08b096u,0x0c08b098u,0x0c08b09au,0x0c08b09cu,0x0c08b09eu,0x0c08b0a0u,0x0c08b0a2u,0x0c08b0a4u,
0x0c08b0a6u,0x0c08b0a8u,0x0c08b0aau,0x0c08b0acu,0x0c08b0aeu,0x0c08b0b0u,0x0c08b0b2u,0x0c08b0b4u,0x0c08b0b6u,0x0c08b0b8u,0x0c08b0bau,0x0c08b0bcu,0x0c08b0beu,0x0c08b0c0u,0x0c08b0c2u,0x0c08b0c4u,
0x0c08b0c6u,0x0c08b0c8u,0x0c08b0cau,0x0c08b0ccu,0x0c08b0ceu,0x0c08b0d0u,0x0c08b0d2u,0x0c08b0d4u,0x0c08b0d6u,0x0c08b0d8u,0x0c08b0dau,0x0c08b0dcu,0x0c08b0deu,0x0c08b0e0u,0x0c08b0e2u,0x0c08b0e4u,
0x0c08b0e6u,0x0c08b0e8u,0x0c08b0eau,0x0c08b0ecu,0x0c08b0eeu,0x0c08b0f0u,0x0c08b0f2u,0x0c08b0f4u,0x0c08b0f6u,0x0c08b0f8u,0x0c08b0fau,0x0c08b0fcu,0x0c08b0feu,0x0c08b100u,0x0c08b102u,0x0c08b104u,
0x0c08b106u,0x0c08b108u,0x0c08b10au,0x0c08b10cu,0x0c08b10eu,0x0c08b110u,0x0c08b112u,0x0c08b114u,0x0c08b116u,0x0c08b118u,0x0c08b11au,0x0c08ef62u,0x0c08ef64u,0x0c08ef66u,0x0c08ef68u,0x0c08ef6au,
0x0c08ef6cu,0x0c08ef6eu,0x0c08ef70u,0x0c08ef72u,0x0c08ef74u,0x0c08ef76u,0x0c08ef78u,0x0c08ef7au,0x0c08ef7cu,0x0c08ef7eu,0x0c08ef80u,0x0c08ef82u,0x0c08ef84u,0x0c08ef86u,0x0c08ef88u,0x0c08ef8au,
0x0c08ef8cu,0x0c08ef8eu,0x0c08ef90u,0x0c08ef92u,0x0c08ef94u,0x0c08ef96u,0x0c08ef98u,0x0c08ef9au,0x0c08ef9cu,0x0c08ef9eu,0x0c08efa0u,0x0c08efa2u,0x0c08efa4u,0x0c08efa6u,0x0c08efa8u,0x0c08efaau,
0x0c08efacu,0x0c08efaeu,0x0c08efb0u,0x0c08efb2u,0x0c08efb4u,0x0c08efb6u,0x0c08efb8u,0x0c08efbau,0x0c08efbcu,0x0c08efbeu,0x0c08efc0u,0x0c08efc2u,0x0c08efc4u,0x0c08efc6u,0x0c08efc8u,0x0c08efcau,
0x0c08efccu,0x0c08efceu,0x0c08efd0u,0x0c08efd2u,0x0c08efd4u,0x0c08efd6u,0x0c08efd8u,0x0c08efdau,0x0c08efdcu,0x0c08efdeu,0x0c08efe0u,0x0c08efe2u,0x0c08efe4u,0x0c08efe6u,0x0c08efe8u,0x0c08efeau,
0x0c08efecu,0x0c08efeeu,0x0c08eff0u,0x0c08eff2u,0x0c08eff4u,0x0c08eff6u,0x0c08eff8u,0x0c08effau,0x0c08effcu,0x0c08effeu,0x0c08f000u,0x0c08f002u,0x0c08f004u,0x0c08f006u,0x0c08f008u,0x0c08f00au,
0x0c08f00cu,0x0c08f00eu,0x0c08f010u,0x0c08f012u,0x0c08f014u,0x0c08f016u,0x0c08f018u,0x0c08f01au,0x0c08f01cu,0x0c08f01eu,0x0c08f020u,0x0c08f022u,0x0c08f024u,0x0c08f026u,0x0c08f028u,0x0c08f02au,
0x0c08f02cu,0x0c08f02eu,0x0c08f030u,0x0c08f032u,0x0c08f034u,0x0c08f036u,0x0c08f038u,0x0c08f03au,0x0c08f03cu,0x0c08f03eu,0x0c08f040u,0x0c08f042u,0x0c08f044u,0x0c08f046u,0x0c08f048u,0x0c08f04au,
0x0c08f04cu,0x0c08f04eu,0x0c08f050u,0x0c08f052u,0x0c08f054u,0x0c08f056u,0x0c08f058u,0x0c08f05au,0x0c08f05cu,0x0c08f05eu,0x0c08f060u,0x0c08f062u,0x0c08f064u,0x0c08f066u,0x0c08f068u,0x0c08f06au,
0x0c08f06cu,0x0c08f06eu,0x0c08f070u,0x0c08f072u,0x0c08f074u,0x0c08f076u,0x0c08f078u,0x0c08f07au,0x0c08f07cu,0x0c08f07eu,0x0c08f080u,0x0c08f082u,0x0c08f084u,0x0c08f086u,0x0c08f088u,0x0c08f08au,
0x0c08f08cu,0x0c08f08eu,0x0c08f090u,0x0c08f092u,0x0c08f094u,0x0c08f096u,0x0c08f098u,0x0c08f09au,0x0c08f09cu,0x0c08f09eu,0x0c08f0a0u,0x0c08f0a2u,0x0c08f0a4u,0x0c08f0a6u,0x0c08f0a8u,0x0c08f0aau,
0x0c08f0acu,0x0c08f0aeu,0x0c08f0b0u,0x0c08f0b2u,0x0c08f0b4u,0x0c08f0b6u,0x0c08f0b8u,0x0c08f0bau,0x0c08f0bcu,0x0c08f0beu,0x0c08f0c0u,0x0c08f0c2u,0x0c08f0c4u,0x0c08f0c6u,0x0c08f0c8u,0x0c08f0cau,
0x0c08f0ccu,0x0c08f0ceu,0x0c08f0d0u,0x0c08f0d2u,0x0c08f0d4u,0x0c08f0d6u,0x0c08f0d8u,0x0c08f0dau,0x0c08f0dcu,0x0c08f0deu,0x0c08f0e0u,0x0c08f0e2u,0x0c08f0e4u,
};
int vf3_advance_medium_adapter_contains(uint32_t pc) {
pc&=0x1fffffffu; unsigned lo=0,hi=sizeof(owned_pcs)/sizeof(owned_pcs[0]);
while(lo<hi) { unsigned mid=lo+(hi-lo)/2; if(owned_pcs[mid]<pc) lo=mid+1; else hi=mid; }
return lo<sizeof(owned_pcs)/sizeof(owned_pcs[0]) && owned_pcs[lo]==pc;
}
