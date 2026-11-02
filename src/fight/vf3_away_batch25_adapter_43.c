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
int vf3_away_batch25_adapter_43(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c0c78d0u: goto P_0c0c78d0;
case 0x0c0c78d2u: goto P_0c0c78d2;
case 0x0c0c78d4u: goto P_0c0c78d4;
case 0x0c0c78d6u: goto P_0c0c78d6;
case 0x0c0c78d8u: goto P_0c0c78d8;
case 0x0c0c78dau: goto P_0c0c78da;
case 0x0c0c78dcu: goto P_0c0c78dc;
case 0x0c0c78deu: goto P_0c0c78de;
case 0x0c0c78e0u: goto P_0c0c78e0;
case 0x0c0c78e2u: goto P_0c0c78e2;
case 0x0c0c78e4u: goto P_0c0c78e4;
case 0x0c0c78e6u: goto P_0c0c78e6;
case 0x0c0c78e8u: goto P_0c0c78e8;
case 0x0c0c78eau: goto P_0c0c78ea;
case 0x0c0c78ecu: goto P_0c0c78ec;
case 0x0c0c78eeu: goto P_0c0c78ee;
case 0x0c0c78f0u: goto P_0c0c78f0;
case 0x0c0c78f2u: goto P_0c0c78f2;
case 0x0c0c78f4u: goto P_0c0c78f4;
case 0x0c0c78f6u: goto P_0c0c78f6;
case 0x0c0c78f8u: goto P_0c0c78f8;
case 0x0c0c78fau: goto P_0c0c78fa;
case 0x0c0c78fcu: goto P_0c0c78fc;
case 0x0c0c78feu: goto P_0c0c78fe;
case 0x0c0c7900u: goto P_0c0c7900;
case 0x0c0c7902u: goto P_0c0c7902;
case 0x0c0c7904u: goto P_0c0c7904;
case 0x0c0c7906u: goto P_0c0c7906;
case 0x0c0c7908u: goto P_0c0c7908;
case 0x0c0c790au: goto P_0c0c790a;
case 0x0c0c790cu: goto P_0c0c790c;
case 0x0c0c790eu: goto P_0c0c790e;
case 0x0c0c7910u: goto P_0c0c7910;
case 0x0c0c7912u: goto P_0c0c7912;
case 0x0c0c7914u: goto P_0c0c7914;
case 0x0c0c7916u: goto P_0c0c7916;
case 0x0c0c7918u: goto P_0c0c7918;
case 0x0c0c791au: goto P_0c0c791a;
case 0x0c0c791cu: goto P_0c0c791c;
case 0x0c0c791eu: goto P_0c0c791e;
case 0x0c0c7920u: goto P_0c0c7920;
case 0x0c0c7922u: goto P_0c0c7922;
case 0x0c0c7924u: goto P_0c0c7924;
case 0x0c0c7926u: goto P_0c0c7926;
case 0x0c0c7928u: goto P_0c0c7928;
case 0x0c0c792au: goto P_0c0c792a;
case 0x0c0c792cu: goto P_0c0c792c;
case 0x0c0c792eu: goto P_0c0c792e;
case 0x0c0c7930u: goto P_0c0c7930;
case 0x0c0c7932u: goto P_0c0c7932;
case 0x0c0c7934u: goto P_0c0c7934;
case 0x0c0c7936u: goto P_0c0c7936;
case 0x0c0c7938u: goto P_0c0c7938;
case 0x0c0c793au: goto P_0c0c793a;
case 0x0c0c793cu: goto P_0c0c793c;
case 0x0c0c793eu: goto P_0c0c793e;
case 0x0c0c7940u: goto P_0c0c7940;
case 0x0c0c7942u: goto P_0c0c7942;
case 0x0c0c7944u: goto P_0c0c7944;
case 0x0c0c7946u: goto P_0c0c7946;
case 0x0c0c7948u: goto P_0c0c7948;
case 0x0c0c794au: goto P_0c0c794a;
case 0x0c0c794cu: goto P_0c0c794c;
case 0x0c0c794eu: goto P_0c0c794e;
case 0x0c0c7950u: goto P_0c0c7950;
case 0x0c0c7952u: goto P_0c0c7952;
case 0x0c0c7954u: goto P_0c0c7954;
case 0x0c0c7956u: goto P_0c0c7956;
case 0x0c0c7958u: goto P_0c0c7958;
case 0x0c0c795au: goto P_0c0c795a;
case 0x0c0c795cu: goto P_0c0c795c;
case 0x0c0c795eu: goto P_0c0c795e;
case 0x0c0c7960u: goto P_0c0c7960;
case 0x0c0c7962u: goto P_0c0c7962;
case 0x0c0c7964u: goto P_0c0c7964;
case 0x0c0c7966u: goto P_0c0c7966;
case 0x0c0c7968u: goto P_0c0c7968;
case 0x0c0c796au: goto P_0c0c796a;
case 0x0c0c796cu: goto P_0c0c796c;
case 0x0c0c796eu: goto P_0c0c796e;
case 0x0c0c7970u: goto P_0c0c7970;
case 0x0c0c7972u: goto P_0c0c7972;
case 0x0c0c7974u: goto P_0c0c7974;
case 0x0c0c7976u: goto P_0c0c7976;
case 0x0c0c7978u: goto P_0c0c7978;
case 0x0c0c797au: goto P_0c0c797a;
case 0x0c0c797cu: goto P_0c0c797c;
case 0x0c0c797eu: goto P_0c0c797e;
case 0x0c0c7980u: goto P_0c0c7980;
case 0x0c0c7982u: goto P_0c0c7982;
case 0x0c0c7984u: goto P_0c0c7984;
case 0x0c0c7986u: goto P_0c0c7986;
case 0x0c0c7988u: goto P_0c0c7988;
case 0x0c0c798au: goto P_0c0c798a;
case 0x0c0c798cu: goto P_0c0c798c;
case 0x0c0c798eu: goto P_0c0c798e;
case 0x0c0c7990u: goto P_0c0c7990;
case 0x0c0c7992u: goto P_0c0c7992;
case 0x0c0c7994u: goto P_0c0c7994;
case 0x0c0c7996u: goto P_0c0c7996;
case 0x0c0c7998u: goto P_0c0c7998;
case 0x0c0c799au: goto P_0c0c799a;
case 0x0c0c799cu: goto P_0c0c799c;
case 0x0c0c799eu: goto P_0c0c799e;
case 0x0c0c79a0u: goto P_0c0c79a0;
case 0x0c0c79a2u: goto P_0c0c79a2;
case 0x0c0c79a4u: goto P_0c0c79a4;
case 0x0c0c79a6u: goto P_0c0c79a6;
case 0x0c0c79a8u: goto P_0c0c79a8;
case 0x0c0c7a00u: goto P_0c0c7a00;
case 0x0c0c7a02u: goto P_0c0c7a02;
case 0x0c0c7a04u: goto P_0c0c7a04;
case 0x0c0c7a06u: goto P_0c0c7a06;
case 0x0c0c7a08u: goto P_0c0c7a08;
case 0x0c0c7a0au: goto P_0c0c7a0a;
case 0x0c0c7a0cu: goto P_0c0c7a0c;
case 0x0c0c7a0eu: goto P_0c0c7a0e;
case 0x0c0c7a10u: goto P_0c0c7a10;
case 0x0c0c7a12u: goto P_0c0c7a12;
case 0x0c0c7a14u: goto P_0c0c7a14;
case 0x0c0c7a16u: goto P_0c0c7a16;
case 0x0c0c7a18u: goto P_0c0c7a18;
case 0x0c0c7a1au: goto P_0c0c7a1a;
case 0x0c0c7a1cu: goto P_0c0c7a1c;
case 0x0c0c7a1eu: goto P_0c0c7a1e;
case 0x0c0c7a20u: goto P_0c0c7a20;
case 0x0c0c7a22u: goto P_0c0c7a22;
case 0x0c0c7a24u: goto P_0c0c7a24;
case 0x0c0c7a26u: goto P_0c0c7a26;
case 0x0c0c7a28u: goto P_0c0c7a28;
case 0x0c0c7a2au: goto P_0c0c7a2a;
case 0x0c0c7a2cu: goto P_0c0c7a2c;
case 0x0c0c7a2eu: goto P_0c0c7a2e;
case 0x0c0c7a30u: goto P_0c0c7a30;
case 0x0c0c7a32u: goto P_0c0c7a32;
case 0x0c0c7a34u: goto P_0c0c7a34;
case 0x0c0c7a36u: goto P_0c0c7a36;
case 0x0c0c7a38u: goto P_0c0c7a38;
case 0x0c0c7a3au: goto P_0c0c7a3a;
case 0x0c0c7a3cu: goto P_0c0c7a3c;
case 0x0c0c7a3eu: goto P_0c0c7a3e;
case 0x0c0c7a40u: goto P_0c0c7a40;
case 0x0c0c7a42u: goto P_0c0c7a42;
case 0x0c0c7a44u: goto P_0c0c7a44;
case 0x0c0c7a46u: goto P_0c0c7a46;
case 0x0c0c7a48u: goto P_0c0c7a48;
case 0x0c0c7a4au: goto P_0c0c7a4a;
case 0x0c0c7a4cu: goto P_0c0c7a4c;
case 0x0c0c7a4eu: goto P_0c0c7a4e;
case 0x0c0c7a50u: goto P_0c0c7a50;
case 0x0c0c7a52u: goto P_0c0c7a52;
case 0x0c0c7a54u: goto P_0c0c7a54;
case 0x0c0c7a56u: goto P_0c0c7a56;
case 0x0c0c7a58u: goto P_0c0c7a58;
case 0x0c0c7a5au: goto P_0c0c7a5a;
case 0x0c0c7a5cu: goto P_0c0c7a5c;
case 0x0c0c7a5eu: goto P_0c0c7a5e;
case 0x0c0c7a60u: goto P_0c0c7a60;
case 0x0c0c7a62u: goto P_0c0c7a62;
case 0x0c0c7a64u: goto P_0c0c7a64;
case 0x0c0c7a66u: goto P_0c0c7a66;
case 0x0c0c7a68u: goto P_0c0c7a68;
case 0x0c0c7a6au: goto P_0c0c7a6a;
case 0x0c0c7a6cu: goto P_0c0c7a6c;
case 0x0c0c7a6eu: goto P_0c0c7a6e;
case 0x0c0c7a70u: goto P_0c0c7a70;
case 0x0c0c7a72u: goto P_0c0c7a72;
case 0x0c0c7c50u: goto P_0c0c7c50;
case 0x0c0c7c52u: goto P_0c0c7c52;
case 0x0c0c7c54u: goto P_0c0c7c54;
case 0x0c0c7c56u: goto P_0c0c7c56;
case 0x0c0c7c58u: goto P_0c0c7c58;
case 0x0c0c7c5au: goto P_0c0c7c5a;
case 0x0c0c7c5cu: goto P_0c0c7c5c;
case 0x0c0c7c5eu: goto P_0c0c7c5e;
case 0x0c0c7c60u: goto P_0c0c7c60;
case 0x0c0c7c62u: goto P_0c0c7c62;
case 0x0c0c7c64u: goto P_0c0c7c64;
case 0x0c0c7c66u: goto P_0c0c7c66;
case 0x0c0c7c68u: goto P_0c0c7c68;
case 0x0c0c7c6au: goto P_0c0c7c6a;
case 0x0c0c7c6cu: goto P_0c0c7c6c;
case 0x0c0c7c6eu: goto P_0c0c7c6e;
case 0x0c0c7c70u: goto P_0c0c7c70;
case 0x0c0c7c72u: goto P_0c0c7c72;
case 0x0c0c7c74u: goto P_0c0c7c74;
case 0x0c0c7c76u: goto P_0c0c7c76;
case 0x0c0c7c78u: goto P_0c0c7c78;
case 0x0c0c7c7au: goto P_0c0c7c7a;
case 0x0c0c7c7cu: goto P_0c0c7c7c;
case 0x0c0c7c7eu: goto P_0c0c7c7e;
case 0x0c0c7c80u: goto P_0c0c7c80;
case 0x0c0c7c82u: goto P_0c0c7c82;
case 0x0c0c7c84u: goto P_0c0c7c84;
case 0x0c0c7c86u: goto P_0c0c7c86;
case 0x0c0c7c88u: goto P_0c0c7c88;
case 0x0c0c7c8au: goto P_0c0c7c8a;
case 0x0c0c7c8cu: goto P_0c0c7c8c;
case 0x0c0c7c8eu: goto P_0c0c7c8e;
case 0x0c0c7c90u: goto P_0c0c7c90;
case 0x0c0c7c92u: goto P_0c0c7c92;
case 0x0c0c7c94u: goto P_0c0c7c94;
case 0x0c0c7c96u: goto P_0c0c7c96;
case 0x0c0c7c98u: goto P_0c0c7c98;
case 0x0c0c7c9au: goto P_0c0c7c9a;
case 0x0c0c7c9cu: goto P_0c0c7c9c;
case 0x0c0c7c9eu: goto P_0c0c7c9e;
case 0x0c0c7ca0u: goto P_0c0c7ca0;
case 0x0c0c7ca2u: goto P_0c0c7ca2;
case 0x0c0c7ca4u: goto P_0c0c7ca4;
case 0x0c0c7ca6u: goto P_0c0c7ca6;
case 0x0c0c7ca8u: goto P_0c0c7ca8;
case 0x0c0c7caau: goto P_0c0c7caa;
case 0x0c0c7cacu: goto P_0c0c7cac;
case 0x0c0c7caeu: goto P_0c0c7cae;
case 0x0c0c7cb0u: goto P_0c0c7cb0;
case 0x0c0c7cb2u: goto P_0c0c7cb2;
case 0x0c0c7cb4u: goto P_0c0c7cb4;
case 0x0c0c7cb6u: goto P_0c0c7cb6;
case 0x0c0c7cb8u: goto P_0c0c7cb8;
case 0x0c0c7cbau: goto P_0c0c7cba;
case 0x0c0c7cbcu: goto P_0c0c7cbc;
case 0x0c0c7cbeu: goto P_0c0c7cbe;
case 0x0c0c7cc0u: goto P_0c0c7cc0;
case 0x0c0c7cc2u: goto P_0c0c7cc2;
case 0x0c0c7cc4u: goto P_0c0c7cc4;
case 0x0c0c7cc6u: goto P_0c0c7cc6;
case 0x0c0c7cc8u: goto P_0c0c7cc8;
case 0x0c0c7ccau: goto P_0c0c7cca;
case 0x0c0c7cccu: goto P_0c0c7ccc;
case 0x0c0c7cceu: goto P_0c0c7cce;
case 0x0c0c7cd0u: goto P_0c0c7cd0;
case 0x0c0c7cd2u: goto P_0c0c7cd2;
case 0x0c0c7cd4u: goto P_0c0c7cd4;
case 0x0c0c7cd6u: goto P_0c0c7cd6;
case 0x0c0c7cd8u: goto P_0c0c7cd8;
case 0x0c0c7cdau: goto P_0c0c7cda;
case 0x0c0c7cdcu: goto P_0c0c7cdc;
case 0x0c0c7cdeu: goto P_0c0c7cde;
case 0x0c0c7ce0u: goto P_0c0c7ce0;
case 0x0c0c7ce2u: goto P_0c0c7ce2;
case 0x0c0c7ce4u: goto P_0c0c7ce4;
case 0x0c0c7ce6u: goto P_0c0c7ce6;
case 0x0c0c7ce8u: goto P_0c0c7ce8;
case 0x0c0c7ceau: goto P_0c0c7cea;
case 0x0c0c7cecu: goto P_0c0c7cec;
case 0x0c0c7ceeu: goto P_0c0c7cee;
case 0x0c0c7cf0u: goto P_0c0c7cf0;
case 0x0c0c7cf2u: goto P_0c0c7cf2;
case 0x0c0c7cf4u: goto P_0c0c7cf4;
case 0x0c0c7cf6u: goto P_0c0c7cf6;
case 0x0c0c7cf8u: goto P_0c0c7cf8;
case 0x0c0c7cfau: goto P_0c0c7cfa;
case 0x0c0c7cfcu: goto P_0c0c7cfc;
case 0x0c0c7cfeu: goto P_0c0c7cfe;
case 0x0c0c7d00u: goto P_0c0c7d00;
case 0x0c0c7d02u: goto P_0c0c7d02;
case 0x0c0c7d04u: goto P_0c0c7d04;
case 0x0c0c7d06u: goto P_0c0c7d06;
case 0x0c0c7d08u: goto P_0c0c7d08;
case 0x0c0c7d0au: goto P_0c0c7d0a;
case 0x0c0c7d0cu: goto P_0c0c7d0c;
case 0x0c0c7d0eu: goto P_0c0c7d0e;
case 0x0c0c7d10u: goto P_0c0c7d10;
case 0x0c0c7d12u: goto P_0c0c7d12;
case 0x0c0c7d14u: goto P_0c0c7d14;
case 0x0c0c7d16u: goto P_0c0c7d16;
case 0x0c0c7d18u: goto P_0c0c7d18;
case 0x0c0c7d1au: goto P_0c0c7d1a;
case 0x0c0c7d1cu: goto P_0c0c7d1c;
case 0x0c0c7d1eu: goto P_0c0c7d1e;
case 0x0c0c7d20u: goto P_0c0c7d20;
case 0x0c0c7d22u: goto P_0c0c7d22;
case 0x0c0c7d24u: goto P_0c0c7d24;
case 0x0c0c7d26u: goto P_0c0c7d26;
case 0x0c0c7d28u: goto P_0c0c7d28;
case 0x0c0c7d2au: goto P_0c0c7d2a;
case 0x0c0c7d2cu: goto P_0c0c7d2c;
case 0x0c0c7d2eu: goto P_0c0c7d2e;
case 0x0c0c7d30u: goto P_0c0c7d30;
case 0x0c0c7d32u: goto P_0c0c7d32;
case 0x0c0c7d34u: goto P_0c0c7d34;
case 0x0c0c7d36u: goto P_0c0c7d36;
case 0x0c0c7d38u: goto P_0c0c7d38;
case 0x0c0c7d3au: goto P_0c0c7d3a;
case 0x0c0c7d3cu: goto P_0c0c7d3c;
case 0x0c0c7d3eu: goto P_0c0c7d3e;
case 0x0c0c7d40u: goto P_0c0c7d40;
case 0x0c0c7d42u: goto P_0c0c7d42;
case 0x0c0c7d44u: goto P_0c0c7d44;
case 0x0c0c7d46u: goto P_0c0c7d46;
case 0x0c0c7d48u: goto P_0c0c7d48;
case 0x0c0c7d4au: goto P_0c0c7d4a;
case 0x0c0c7d4cu: goto P_0c0c7d4c;
case 0x0c0c7d4eu: goto P_0c0c7d4e;
case 0x0c0c7d50u: goto P_0c0c7d50;
case 0x0c0c7d52u: goto P_0c0c7d52;
case 0x0c0c7d54u: goto P_0c0c7d54;
case 0x0c0c7d56u: goto P_0c0c7d56;
case 0x0c0c7d58u: goto P_0c0c7d58;
case 0x0c0c7d5au: goto P_0c0c7d5a;
case 0x0c0c7d5cu: goto P_0c0c7d5c;
case 0x0c0c7d5eu: goto P_0c0c7d5e;
case 0x0c0c7d60u: goto P_0c0c7d60;
case 0x0c0c7d62u: goto P_0c0c7d62;
case 0x0c0c7d64u: goto P_0c0c7d64;
case 0x0c0c7d66u: goto P_0c0c7d66;
case 0x0c0c7d68u: goto P_0c0c7d68;
case 0x0c0c7d6au: goto P_0c0c7d6a;
case 0x0c0c7d6cu: goto P_0c0c7d6c;
case 0x0c0c7d6eu: goto P_0c0c7d6e;
case 0x0c0c7d70u: goto P_0c0c7d70;
case 0x0c0c7d72u: goto P_0c0c7d72;
case 0x0c0c7d74u: goto P_0c0c7d74;
case 0x0c0c7d76u: goto P_0c0c7d76;
case 0x0c0c7d78u: goto P_0c0c7d78;
case 0x0c0c7de0u: goto P_0c0c7de0;
case 0x0c0c7de2u: goto P_0c0c7de2;
case 0x0c0c7de4u: goto P_0c0c7de4;
case 0x0c0c7de6u: goto P_0c0c7de6;
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
default: return vf3_matrix_family(target,s,ram);
}
P_0c0c78d0: /* original 2fe6, guest PC 0x0c0c78d0 */
if(!s->budget--) { s->failed_pc=0x0c0c78d0u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c78d2;
P_0c0c78d2: /* original 4511, guest PC 0x0c0c78d2 */
if(!s->budget--) { s->failed_pc=0x0c0c78d2u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[5]>=0)!=0);
goto P_0c0c78d4;
P_0c0c78d4: /* original 2fd6, guest PC 0x0c0c78d4 */
if(!s->budget--) { s->failed_pc=0x0c0c78d4u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c78d6;
P_0c0c78d6: /* original 2fc6, guest PC 0x0c0c78d6 */
if(!s->budget--) { s->failed_pc=0x0c0c78d6u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c78d8;
P_0c0c78d8: /* original 2fb6, guest PC 0x0c0c78d8 */
if(!s->budget--) { s->failed_pc=0x0c0c78d8u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c78da;
P_0c0c78da: /* original 2fa6, guest PC 0x0c0c78da */
if(!s->budget--) { s->failed_pc=0x0c0c78dau; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c78dc;
P_0c0c78dc: /* original 2f96, guest PC 0x0c0c78dc */
if(!s->budget--) { s->failed_pc=0x0c0c78dcu; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c78de;
P_0c0c78de: /* original 2f86, guest PC 0x0c0c78de */
if(!s->budget--) { s->failed_pc=0x0c0c78deu; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c78e0;
P_0c0c78e0: /* original 4f22, guest PC 0x0c0c78e0 */
if(!s->budget--) { s->failed_pc=0x0c0c78e0u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0c78e2;
P_0c0c78e2: /* original de37, guest PC 0x0c0c78e2 */
if(!s->budget--) { s->failed_pc=0x0c0c78e2u; return 0; }
r[14]=read(ram,0x0c0c79c0u,4);
goto P_0c0c78e4;
P_0c0c78e4: /* original 7ffc, guest PC 0x0c0c78e4 */
if(!s->budget--) { s->failed_pc=0x0c0c78e4u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c0c78e6;
P_0c0c78e6: /* original 8f55, guest PC 0x0c0c78e6 */
if(!s->budget--) { s->failed_pc=0x0c0c78e6u; return 0; }
cond=r[17]&1u;
r[11]=read(ram,r[4]+24,4);
if(!cond) { goto P_0c0c7994; }
goto P_0c0c78ea;
P_0c0c78e8: /* original 5b46, guest PC 0x0c0c78e8 */
if(!s->budget--) { s->failed_pc=0x0c0c78e8u; return 0; }
r[11]=read(ram,r[4]+24,4);
goto P_0c0c78ea;
P_0c0c78ea: /* original d33d, guest PC 0x0c0c78ea */
if(!s->budget--) { s->failed_pc=0x0c0c78eau; return 0; }
r[3]=read(ram,0x0c0c79e0u,4);
goto P_0c0c78ec;
P_0c0c78ec: /* original d23d, guest PC 0x0c0c78ec */
if(!s->budget--) { s->failed_pc=0x0c0c78ecu; return 0; }
r[2]=read(ram,0x0c0c79e4u,4);
goto P_0c0c78ee;
P_0c0c78ee: /* original 905e, guest PC 0x0c0c78ee */
if(!s->budget--) { s->failed_pc=0x0c0c78eeu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c79aeu,2);
goto P_0c0c78f0;
P_0c0c78f0: /* original 6522, guest PC 0x0c0c78f0 */
if(!s->budget--) { s->failed_pc=0x0c0c78f0u; return 0; }
tmp=read(ram,r[2],4);
r[5]=tmp;
goto P_0c0c78f2;
P_0c0c78f2: /* original d13d, guest PC 0x0c0c78f2 */
if(!s->budget--) { s->failed_pc=0x0c0c78f2u; return 0; }
r[1]=read(ram,0x0c0c79e8u,4);
goto P_0c0c78f4;
P_0c0c78f4: /* original 0cee, guest PC 0x0c0c78f4 */
if(!s->budget--) { s->failed_pc=0x0c0c78f4u; return 0; }
r[12]=read(ram,r[14]+r[0],4);
goto P_0c0c78f6;
P_0c0c78f6: /* original 6631, guest PC 0x0c0c78f6 */
if(!s->budget--) { s->failed_pc=0x0c0c78f6u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[3],2);
r[6]=tmp;
goto P_0c0c78f8;
P_0c0c78f8: /* original 410b, guest PC 0x0c0c78f8 */
if(!s->budget--) { s->failed_pc=0x0c0c78f8u; return 0; }
target=r[1];
r[16]=code_base|0x0c0c78fcu;
r[4]=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c78fcu) { target=s->pc; goto dispatch; }
goto P_0c0c78fc;
P_0c0c78fa: /* original 64c3, guest PC 0x0c0c78fa */
if(!s->budget--) { s->failed_pc=0x0c0c78fau; return 0; }
r[4]=r[12];
goto P_0c0c78fc;
P_0c0c78fc: /* original d83b, guest PC 0x0c0c78fc */
if(!s->budget--) { s->failed_pc=0x0c0c78fcu; return 0; }
r[8]=read(ram,0x0c0c79ecu,4);
goto P_0c0c78fe;
P_0c0c78fe: /* original 9a57, guest PC 0x0c0c78fe */
if(!s->budget--) { s->failed_pc=0x0c0c78feu; return 0; }
r[10]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c79b0u,2);
goto P_0c0c7900;
P_0c0c7900: /* original 59c4, guest PC 0x0c0c7900 */
if(!s->budget--) { s->failed_pc=0x0c0c7900u; return 0; }
r[9]=read(ram,r[12]+16,4);
goto P_0c0c7902;
P_0c0c7902: /* original a007, guest PC 0x0c0c7902 */
if(!s->budget--) { s->failed_pc=0x0c0c7902u; return 0; }
r[13]=0x00000000u;
goto P_0c0c7914;
P_0c0c7904: /* original ed00, guest PC 0x0c0c7904 */
if(!s->budget--) { s->failed_pc=0x0c0c7904u; return 0; }
r[13]=0x00000000u;
goto P_0c0c7906;
P_0c0c7906: /* original 60d3, guest PC 0x0c0c7906 */
if(!s->budget--) { s->failed_pc=0x0c0c7906u; return 0; }
r[0]=r[13];
goto P_0c0c7908;
P_0c0c7908: /* original 4008, guest PC 0x0c0c7908 */
if(!s->budget--) { s->failed_pc=0x0c0c7908u; return 0; }
r[0]<<=2;
goto P_0c0c790a;
P_0c0c790a: /* original 059e, guest PC 0x0c0c790a */
if(!s->budget--) { s->failed_pc=0x0c0c790au; return 0; }
r[5]=read(ram,r[9]+r[0],4);
goto P_0c0c790c;
P_0c0c790c: /* original 64a3, guest PC 0x0c0c790c */
if(!s->budget--) { s->failed_pc=0x0c0c790cu; return 0; }
r[4]=r[10];
goto P_0c0c790e;
P_0c0c790e: /* original 480b, guest PC 0x0c0c790e */
if(!s->budget--) { s->failed_pc=0x0c0c790eu; return 0; }
target=r[8];
r[16]=code_base|0x0c0c7912u;
r[10]+=0x00000001u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c7912u) { target=s->pc; goto dispatch; }
goto P_0c0c7912;
P_0c0c7910: /* original 7a01, guest PC 0x0c0c7910 */
if(!s->budget--) { s->failed_pc=0x0c0c7910u; return 0; }
r[10]+=0x00000001u;
goto P_0c0c7912;
P_0c0c7912: /* original 7d01, guest PC 0x0c0c7912 */
if(!s->budget--) { s->failed_pc=0x0c0c7912u; return 0; }
r[13]+=0x00000001u;
goto P_0c0c7914;
P_0c0c7914: /* original 85c6, guest PC 0x0c0c7914 */
if(!s->budget--) { s->failed_pc=0x0c0c7914u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[12]+12,2);
goto P_0c0c7916;
P_0c0c7916: /* original 600d, guest PC 0x0c0c7916 */
if(!s->budget--) { s->failed_pc=0x0c0c7916u; return 0; }
r[0]=r[0]&65535u;
goto P_0c0c7918;
P_0c0c7918: /* original 3d03, guest PC 0x0c0c7918 */
if(!s->budget--) { s->failed_pc=0x0c0c7918u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[13]>=(int32_t)r[0])!=0);
goto P_0c0c791a;
P_0c0c791a: /* original 8bf4, guest PC 0x0c0c791a */
if(!s->budget--) { s->failed_pc=0x0c0c791au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c7906; }
goto P_0c0c791c;
P_0c0c791c: /* original 9047, guest PC 0x0c0c791c */
if(!s->budget--) { s->failed_pc=0x0c0c791cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c79aeu,2);
goto P_0c0c791e;
P_0c0c791e: /* original 6db3, guest PC 0x0c0c791e */
if(!s->budget--) { s->failed_pc=0x0c0c791eu; return 0; }
r[13]=r[11];
goto P_0c0c7920;
P_0c0c7920: /* original 53c6, guest PC 0x0c0c7920 */
if(!s->budget--) { s->failed_pc=0x0c0c7920u; return 0; }
r[3]=read(ram,r[12]+24,4);
goto P_0c0c7922;
P_0c0c7922: /* original 4d08, guest PC 0x0c0c7922 */
if(!s->budget--) { s->failed_pc=0x0c0c7922u; return 0; }
r[13]<<=2;
goto P_0c0c7924;
P_0c0c7924: /* original 02ee, guest PC 0x0c0c7924 */
if(!s->budget--) { s->failed_pc=0x0c0c7924u; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c0c7926;
P_0c0c7926: /* original 7004, guest PC 0x0c0c7926 */
if(!s->budget--) { s->failed_pc=0x0c0c7926u; return 0; }
r[0]+=0x00000004u;
goto P_0c0c7928;
P_0c0c7928: /* original 9143, guest PC 0x0c0c7928 */
if(!s->budget--) { s->failed_pc=0x0c0c7928u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c79b2u,2);
goto P_0c0c792a;
P_0c0c792a: /* original 4d00, guest PC 0x0c0c792a */
if(!s->budget--) { s->failed_pc=0x0c0c792au; return 0; }
r[17]=(r[17]&~1u)|((r[13]>>31)!=0);
r[13]<<=1;
goto P_0c0c792c;
P_0c0c792c: /* original 323c, guest PC 0x0c0c792c */
if(!s->budget--) { s->failed_pc=0x0c0c792cu; return 0; }
r[2]+=r[3];
goto P_0c0c792e;
P_0c0c792e: /* original 9341, guest PC 0x0c0c792e */
if(!s->budget--) { s->failed_pc=0x0c0c792eu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c79b4u,2);
goto P_0c0c7930;
P_0c0c7930: /* original 321c, guest PC 0x0c0c7930 */
if(!s->budget--) { s->failed_pc=0x0c0c7930u; return 0; }
r[2]+=r[1];
goto P_0c0c7932;
P_0c0c7932: /* original 2239, guest PC 0x0c0c7932 */
if(!s->budget--) { s->failed_pc=0x0c0c7932u; return 0; }
r[2]&=r[3];
goto P_0c0c7934;
P_0c0c7934: /* original 0e26, guest PC 0x0c0c7934 */
if(!s->budget--) { s->failed_pc=0x0c0c7934u; return 0; }
write(ram,r[14]+r[0],r[2],4);
goto P_0c0c7936;
P_0c0c7936: /* original 70f8, guest PC 0x0c0c7936 */
if(!s->budget--) { s->failed_pc=0x0c0c7936u; return 0; }
r[0]+=0xfffffff8u;
goto P_0c0c7938;
P_0c0c7938: /* original 0e26, guest PC 0x0c0c7938 */
if(!s->budget--) { s->failed_pc=0x0c0c7938u; return 0; }
write(ram,r[14]+r[0],r[2],4);
goto P_0c0c793a;
P_0c0c793a: /* original d22d, guest PC 0x0c0c793a */
if(!s->budget--) { s->failed_pc=0x0c0c793au; return 0; }
r[2]=read(ram,0x0c0c79f0u,4);
goto P_0c0c793c;
P_0c0c793c: /* original 3d2c, guest PC 0x0c0c793c */
if(!s->budget--) { s->failed_pc=0x0c0c793cu; return 0; }
r[13]+=r[2];
goto P_0c0c793e;
P_0c0c793e: /* original 60d2, guest PC 0x0c0c793e */
if(!s->budget--) { s->failed_pc=0x0c0c793eu; return 0; }
tmp=read(ram,r[13],4);
r[0]=tmp;
goto P_0c0c7940;
P_0c0c7940: /* original 88ff, guest PC 0x0c0c7940 */
if(!s->budget--) { s->failed_pc=0x0c0c7940u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xffffffffu)!=0);
goto P_0c0c7942;
P_0c0c7942: /* original 891f, guest PC 0x0c0c7942 */
if(!s->budget--) { s->failed_pc=0x0c0c7942u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c7984; }
goto P_0c0c7944;
P_0c0c7944: /* original 9137, guest PC 0x0c0c7944 */
if(!s->budget--) { s->failed_pc=0x0c0c7944u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c79b6u,2);
goto P_0c0c7946;
P_0c0c7946: /* original e700, guest PC 0x0c0c7946 */
if(!s->budget--) { s->failed_pc=0x0c0c7946u; return 0; }
r[7]=0x00000000u;
goto P_0c0c7948;
P_0c0c7948: /* original 2f16, guest PC 0x0c0c7948 */
if(!s->budget--) { s->failed_pc=0x0c0c7948u; return 0; }
tmp=r[1]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c794a;
P_0c0c794a: /* original d32a, guest PC 0x0c0c794a */
if(!s->budget--) { s->failed_pc=0x0c0c794au; return 0; }
r[3]=read(ram,0x0c0c79f4u,4);
goto P_0c0c794c;
P_0c0c794c: /* original 2f36, guest PC 0x0c0c794c */
if(!s->budget--) { s->failed_pc=0x0c0c794cu; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c794e;
P_0c0c794e: /* original 2fb6, guest PC 0x0c0c794e */
if(!s->budget--) { s->failed_pc=0x0c0c794eu; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c7950;
P_0c0c7950: /* original 9632, guest PC 0x0c0c7950 */
if(!s->budget--) { s->failed_pc=0x0c0c7950u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c79b8u,2);
goto P_0c0c7952;
P_0c0c7952: /* original 9032, guest PC 0x0c0c7952 */
if(!s->budget--) { s->failed_pc=0x0c0c7952u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c79bau,2);
goto P_0c0c7954;
P_0c0c7954: /* original 36ec, guest PC 0x0c0c7954 */
if(!s->budget--) { s->failed_pc=0x0c0c7954u; return 0; }
r[6]+=r[14];
goto P_0c0c7956;
P_0c0c7956: /* original 05ee, guest PC 0x0c0c7956 */
if(!s->budget--) { s->failed_pc=0x0c0c7956u; return 0; }
r[5]=read(ram,r[14]+r[0],4);
goto P_0c0c7958;
P_0c0c7958: /* original 7608, guest PC 0x0c0c7958 */
if(!s->budget--) { s->failed_pc=0x0c0c7958u; return 0; }
r[6]+=0x00000008u;
goto P_0c0c795a;
P_0c0c795a: /* original 1fd3, guest PC 0x0c0c795a */
if(!s->budget--) { s->failed_pc=0x0c0c795au; return 0; }
write(ram,r[15]+12,r[13],4);
goto P_0c0c795c;
P_0c0c795c: /* original d326, guest PC 0x0c0c795c */
if(!s->budget--) { s->failed_pc=0x0c0c795cu; return 0; }
r[3]=read(ram,0x0c0c79f8u,4);
goto P_0c0c795e;
P_0c0c795e: /* original 430b, guest PC 0x0c0c795e */
if(!s->budget--) { s->failed_pc=0x0c0c795eu; return 0; }
target=r[3];
r[16]=code_base|0x0c0c7962u;
tmp=read(ram,r[13],4);
r[4]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c7962u) { target=s->pc; goto dispatch; }
goto P_0c0c7962;
P_0c0c7960: /* original 64d2, guest PC 0x0c0c7960 */
if(!s->budget--) { s->failed_pc=0x0c0c7960u; return 0; }
tmp=read(ram,r[13],4);
r[4]=tmp;
goto P_0c0c7962;
P_0c0c7962: /* original 922b, guest PC 0x0c0c7962 */
if(!s->budget--) { s->failed_pc=0x0c0c7962u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c79bcu,2);
goto P_0c0c7964;
P_0c0c7964: /* original 2f26, guest PC 0x0c0c7964 */
if(!s->budget--) { s->failed_pc=0x0c0c7964u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c7966;
P_0c0c7966: /* original d323, guest PC 0x0c0c7966 */
if(!s->budget--) { s->failed_pc=0x0c0c7966u; return 0; }
r[3]=read(ram,0x0c0c79f4u,4);
goto P_0c0c7968;
P_0c0c7968: /* original 2f36, guest PC 0x0c0c7968 */
if(!s->budget--) { s->failed_pc=0x0c0c7968u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c796a;
P_0c0c796a: /* original 2fb6, guest PC 0x0c0c796a */
if(!s->budget--) { s->failed_pc=0x0c0c796au; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c796c;
P_0c0c796c: /* original 9624, guest PC 0x0c0c796c */
if(!s->budget--) { s->failed_pc=0x0c0c796cu; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c79b8u,2);
goto P_0c0c796e;
P_0c0c796e: /* original d11d, guest PC 0x0c0c796e */
if(!s->budget--) { s->failed_pc=0x0c0c796eu; return 0; }
r[1]=read(ram,0x0c0c79e4u,4);
goto P_0c0c7970;
P_0c0c7970: /* original 53f6, guest PC 0x0c0c7970 */
if(!s->budget--) { s->failed_pc=0x0c0c7970u; return 0; }
r[3]=read(ram,r[15]+24,4);
goto P_0c0c7972;
P_0c0c7972: /* original 36ec, guest PC 0x0c0c7972 */
if(!s->budget--) { s->failed_pc=0x0c0c7972u; return 0; }
r[6]+=r[14];
goto P_0c0c7974;
P_0c0c7974: /* original 6512, guest PC 0x0c0c7974 */
if(!s->budget--) { s->failed_pc=0x0c0c7974u; return 0; }
tmp=read(ram,r[1],4);
r[5]=tmp;
goto P_0c0c7976;
P_0c0c7976: /* original 7608, guest PC 0x0c0c7976 */
if(!s->budget--) { s->failed_pc=0x0c0c7976u; return 0; }
r[6]+=0x00000008u;
goto P_0c0c7978;
P_0c0c7978: /* original d720, guest PC 0x0c0c7978 */
if(!s->budget--) { s->failed_pc=0x0c0c7978u; return 0; }
r[7]=read(ram,0x0c0c79fcu,4);
goto P_0c0c797a;
P_0c0c797a: /* original d21f, guest PC 0x0c0c797a */
if(!s->budget--) { s->failed_pc=0x0c0c797au; return 0; }
r[2]=read(ram,0x0c0c79f8u,4);
goto P_0c0c797c;
P_0c0c797c: /* original 420b, guest PC 0x0c0c797c */
if(!s->budget--) { s->failed_pc=0x0c0c797cu; return 0; }
target=r[2];
r[16]=code_base|0x0c0c7980u;
r[4]=read(ram,r[3]+4,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c7980u) { target=s->pc; goto dispatch; }
goto P_0c0c7980;
P_0c0c797e: /* original 5431, guest PC 0x0c0c797e */
if(!s->budget--) { s->failed_pc=0x0c0c797eu; return 0; }
r[4]=read(ram,r[3]+4,4);
goto P_0c0c7980;
P_0c0c7980: /* original a008, guest PC 0x0c0c7980 */
if(!s->budget--) { s->failed_pc=0x0c0c7980u; return 0; }
r[15]+=0x00000018u;
goto P_0c0c7994;
P_0c0c7982: /* original 7f18, guest PC 0x0c0c7982 */
if(!s->budget--) { s->failed_pc=0x0c0c7982u; return 0; }
r[15]+=0x00000018u;
goto P_0c0c7984;
P_0c0c7984: /* original 9119, guest PC 0x0c0c7984 */
if(!s->budget--) { s->failed_pc=0x0c0c7984u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c79bau,2);
goto P_0c0c7986;
P_0c0c7986: /* original e000, guest PC 0x0c0c7986 */
if(!s->budget--) { s->failed_pc=0x0c0c7986u; return 0; }
r[0]=0x00000000u;
goto P_0c0c7988;
P_0c0c7988: /* original e3ff, guest PC 0x0c0c7988 */
if(!s->budget--) { s->failed_pc=0x0c0c7988u; return 0; }
r[3]=0xffffffffu;
goto P_0c0c798a;
P_0c0c798a: /* original 31ec, guest PC 0x0c0c798a */
if(!s->budget--) { s->failed_pc=0x0c0c798au; return 0; }
r[1]+=r[14];
goto P_0c0c798c;
P_0c0c798c: /* original 2102, guest PC 0x0c0c798c */
if(!s->budget--) { s->failed_pc=0x0c0c798cu; return 0; }
write(ram,r[1],r[0],4);
goto P_0c0c798e;
P_0c0c798e: /* original 900d, guest PC 0x0c0c798e */
if(!s->budget--) { s->failed_pc=0x0c0c798eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c79acu,2);
goto P_0c0c7990;
P_0c0c7990: /* original bf37, guest PC 0x0c0c7990 */
if(!s->budget--) { s->failed_pc=0x0c0c7990u; return 0; }
target=code_base|0x0c0c7802u; r[16]=code_base|0x0c0c7994u;
write(ram,r[14]+r[0],r[3],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c7994u) { target=s->pc; goto dispatch; }
goto P_0c0c7994;
P_0c0c7992: /* original 0e36, guest PC 0x0c0c7992 */
if(!s->budget--) { s->failed_pc=0x0c0c7992u; return 0; }
write(ram,r[14]+r[0],r[3],4);
goto P_0c0c7994;
P_0c0c7994: /* original 7f04, guest PC 0x0c0c7994 */
if(!s->budget--) { s->failed_pc=0x0c0c7994u; return 0; }
r[15]+=0x00000004u;
goto P_0c0c7996;
P_0c0c7996: /* original 4f26, guest PC 0x0c0c7996 */
if(!s->budget--) { s->failed_pc=0x0c0c7996u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0c7998;
P_0c0c7998: /* original e000, guest PC 0x0c0c7998 */
if(!s->budget--) { s->failed_pc=0x0c0c7998u; return 0; }
r[0]=0x00000000u;
goto P_0c0c799a;
P_0c0c799a: /* original 68f6, guest PC 0x0c0c799a */
if(!s->budget--) { s->failed_pc=0x0c0c799au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c0c799c;
P_0c0c799c: /* original 69f6, guest PC 0x0c0c799c */
if(!s->budget--) { s->failed_pc=0x0c0c799cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c0c799e;
P_0c0c799e: /* original 6af6, guest PC 0x0c0c799e */
if(!s->budget--) { s->failed_pc=0x0c0c799eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0c79a0;
P_0c0c79a0: /* original 6bf6, guest PC 0x0c0c79a0 */
if(!s->budget--) { s->failed_pc=0x0c0c79a0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0c79a2;
P_0c0c79a2: /* original 6cf6, guest PC 0x0c0c79a2 */
if(!s->budget--) { s->failed_pc=0x0c0c79a2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0c79a4;
P_0c0c79a4: /* original 6df6, guest PC 0x0c0c79a4 */
if(!s->budget--) { s->failed_pc=0x0c0c79a4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0c79a6;
P_0c0c79a6: /* original 000b, guest PC 0x0c0c79a6 */
if(!s->budget--) { s->failed_pc=0x0c0c79a6u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0c79a8: /* original 6ef6, guest PC 0x0c0c79a8 */
if(!s->budget--) { s->failed_pc=0x0c0c79a8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0c79aau,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0c79aau; return 0; } return 1;
P_0c0c7a00: /* original 2fe6, guest PC 0x0c0c7a00 */
if(!s->budget--) { s->failed_pc=0x0c0c7a00u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c7a02;
P_0c0c7a02: /* original 4511, guest PC 0x0c0c7a02 */
if(!s->budget--) { s->failed_pc=0x0c0c7a02u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[5]>=0)!=0);
goto P_0c0c7a04;
P_0c0c7a04: /* original 2fd6, guest PC 0x0c0c7a04 */
if(!s->budget--) { s->failed_pc=0x0c0c7a04u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c7a06;
P_0c0c7a06: /* original 2fc6, guest PC 0x0c0c7a06 */
if(!s->budget--) { s->failed_pc=0x0c0c7a06u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c7a08;
P_0c0c7a08: /* original 2fb6, guest PC 0x0c0c7a08 */
if(!s->budget--) { s->failed_pc=0x0c0c7a08u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c7a0a;
P_0c0c7a0a: /* original 2fa6, guest PC 0x0c0c7a0a */
if(!s->budget--) { s->failed_pc=0x0c0c7a0au; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c7a0c;
P_0c0c7a0c: /* original 2f96, guest PC 0x0c0c7a0c */
if(!s->budget--) { s->failed_pc=0x0c0c7a0cu; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c7a0e;
P_0c0c7a0e: /* original 4f22, guest PC 0x0c0c7a0e */
if(!s->budget--) { s->failed_pc=0x0c0c7a0eu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0c7a10;
P_0c0c7a10: /* original dc4a, guest PC 0x0c0c7a10 */
if(!s->budget--) { s->failed_pc=0x0c0c7a10u; return 0; }
r[12]=read(ram,0x0c0c7b3cu,4);
goto P_0c0c7a12;
P_0c0c7a12: /* original 8b27, guest PC 0x0c0c7a12 */
if(!s->budget--) { s->failed_pc=0x0c0c7a12u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c7a64; }
goto P_0c0c7a14;
P_0c0c7a14: /* original d34a, guest PC 0x0c0c7a14 */
if(!s->budget--) { s->failed_pc=0x0c0c7a14u; return 0; }
r[3]=read(ram,0x0c0c7b40u,4);
goto P_0c0c7a16;
P_0c0c7a16: /* original d24b, guest PC 0x0c0c7a16 */
if(!s->budget--) { s->failed_pc=0x0c0c7a16u; return 0; }
r[2]=read(ram,0x0c0c7b44u,4);
goto P_0c0c7a18;
P_0c0c7a18: /* original 9086, guest PC 0x0c0c7a18 */
if(!s->budget--) { s->failed_pc=0x0c0c7a18u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c7b28u,2);
goto P_0c0c7a1a;
P_0c0c7a1a: /* original 6522, guest PC 0x0c0c7a1a */
if(!s->budget--) { s->failed_pc=0x0c0c7a1au; return 0; }
tmp=read(ram,r[2],4);
r[5]=tmp;
goto P_0c0c7a1c;
P_0c0c7a1c: /* original d14a, guest PC 0x0c0c7a1c */
if(!s->budget--) { s->failed_pc=0x0c0c7a1cu; return 0; }
r[1]=read(ram,0x0c0c7b48u,4);
goto P_0c0c7a1e;
P_0c0c7a1e: /* original 0dce, guest PC 0x0c0c7a1e */
if(!s->budget--) { s->failed_pc=0x0c0c7a1eu; return 0; }
r[13]=read(ram,r[12]+r[0],4);
goto P_0c0c7a20;
P_0c0c7a20: /* original 6631, guest PC 0x0c0c7a20 */
if(!s->budget--) { s->failed_pc=0x0c0c7a20u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[3],2);
r[6]=tmp;
goto P_0c0c7a22;
P_0c0c7a22: /* original 410b, guest PC 0x0c0c7a22 */
if(!s->budget--) { s->failed_pc=0x0c0c7a22u; return 0; }
target=r[1];
r[16]=code_base|0x0c0c7a26u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c7a26u) { target=s->pc; goto dispatch; }
goto P_0c0c7a26;
P_0c0c7a24: /* original 64d3, guest PC 0x0c0c7a24 */
if(!s->budget--) { s->failed_pc=0x0c0c7a24u; return 0; }
r[4]=r[13];
goto P_0c0c7a26;
P_0c0c7a26: /* original da49, guest PC 0x0c0c7a26 */
if(!s->budget--) { s->failed_pc=0x0c0c7a26u; return 0; }
r[10]=read(ram,0x0c0c7b4cu,4);
goto P_0c0c7a28;
P_0c0c7a28: /* original 9b7f, guest PC 0x0c0c7a28 */
if(!s->budget--) { s->failed_pc=0x0c0c7a28u; return 0; }
r[11]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c7b2au,2);
goto P_0c0c7a2a;
P_0c0c7a2a: /* original 59d4, guest PC 0x0c0c7a2a */
if(!s->budget--) { s->failed_pc=0x0c0c7a2au; return 0; }
r[9]=read(ram,r[13]+16,4);
goto P_0c0c7a2c;
P_0c0c7a2c: /* original a007, guest PC 0x0c0c7a2c */
if(!s->budget--) { s->failed_pc=0x0c0c7a2cu; return 0; }
r[14]=0x00000000u;
goto P_0c0c7a3e;
P_0c0c7a2e: /* original ee00, guest PC 0x0c0c7a2e */
if(!s->budget--) { s->failed_pc=0x0c0c7a2eu; return 0; }
r[14]=0x00000000u;
goto P_0c0c7a30;
P_0c0c7a30: /* original 60e3, guest PC 0x0c0c7a30 */
if(!s->budget--) { s->failed_pc=0x0c0c7a30u; return 0; }
r[0]=r[14];
goto P_0c0c7a32;
P_0c0c7a32: /* original 4008, guest PC 0x0c0c7a32 */
if(!s->budget--) { s->failed_pc=0x0c0c7a32u; return 0; }
r[0]<<=2;
goto P_0c0c7a34;
P_0c0c7a34: /* original 059e, guest PC 0x0c0c7a34 */
if(!s->budget--) { s->failed_pc=0x0c0c7a34u; return 0; }
r[5]=read(ram,r[9]+r[0],4);
goto P_0c0c7a36;
P_0c0c7a36: /* original 64b3, guest PC 0x0c0c7a36 */
if(!s->budget--) { s->failed_pc=0x0c0c7a36u; return 0; }
r[4]=r[11];
goto P_0c0c7a38;
P_0c0c7a38: /* original 4a0b, guest PC 0x0c0c7a38 */
if(!s->budget--) { s->failed_pc=0x0c0c7a38u; return 0; }
target=r[10];
r[16]=code_base|0x0c0c7a3cu;
r[11]+=0x00000001u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c7a3cu) { target=s->pc; goto dispatch; }
goto P_0c0c7a3c;
P_0c0c7a3a: /* original 7b01, guest PC 0x0c0c7a3a */
if(!s->budget--) { s->failed_pc=0x0c0c7a3au; return 0; }
r[11]+=0x00000001u;
goto P_0c0c7a3c;
P_0c0c7a3c: /* original 7e01, guest PC 0x0c0c7a3c */
if(!s->budget--) { s->failed_pc=0x0c0c7a3cu; return 0; }
r[14]+=0x00000001u;
goto P_0c0c7a3e;
P_0c0c7a3e: /* original 85d6, guest PC 0x0c0c7a3e */
if(!s->budget--) { s->failed_pc=0x0c0c7a3eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[13]+12,2);
goto P_0c0c7a40;
P_0c0c7a40: /* original 600d, guest PC 0x0c0c7a40 */
if(!s->budget--) { s->failed_pc=0x0c0c7a40u; return 0; }
r[0]=r[0]&65535u;
goto P_0c0c7a42;
P_0c0c7a42: /* original 3e03, guest PC 0x0c0c7a42 */
if(!s->budget--) { s->failed_pc=0x0c0c7a42u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[14]>=(int32_t)r[0])!=0);
goto P_0c0c7a44;
P_0c0c7a44: /* original 8bf4, guest PC 0x0c0c7a44 */
if(!s->budget--) { s->failed_pc=0x0c0c7a44u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c7a30; }
goto P_0c0c7a46;
P_0c0c7a46: /* original 906f, guest PC 0x0c0c7a46 */
if(!s->budget--) { s->failed_pc=0x0c0c7a46u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c7b28u,2);
goto P_0c0c7a48;
P_0c0c7a48: /* original 53d6, guest PC 0x0c0c7a48 */
if(!s->budget--) { s->failed_pc=0x0c0c7a48u; return 0; }
r[3]=read(ram,r[13]+24,4);
goto P_0c0c7a4a;
P_0c0c7a4a: /* original 02ce, guest PC 0x0c0c7a4a */
if(!s->budget--) { s->failed_pc=0x0c0c7a4au; return 0; }
r[2]=read(ram,r[12]+r[0],4);
goto P_0c0c7a4c;
P_0c0c7a4c: /* original 7008, guest PC 0x0c0c7a4c */
if(!s->budget--) { s->failed_pc=0x0c0c7a4cu; return 0; }
r[0]+=0x00000008u;
goto P_0c0c7a4e;
P_0c0c7a4e: /* original 916d, guest PC 0x0c0c7a4e */
if(!s->budget--) { s->failed_pc=0x0c0c7a4eu; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c7b2cu,2);
goto P_0c0c7a50;
P_0c0c7a50: /* original 323c, guest PC 0x0c0c7a50 */
if(!s->budget--) { s->failed_pc=0x0c0c7a50u; return 0; }
r[2]+=r[3];
goto P_0c0c7a52;
P_0c0c7a52: /* original 936c, guest PC 0x0c0c7a52 */
if(!s->budget--) { s->failed_pc=0x0c0c7a52u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c7b2eu,2);
goto P_0c0c7a54;
P_0c0c7a54: /* original 321c, guest PC 0x0c0c7a54 */
if(!s->budget--) { s->failed_pc=0x0c0c7a54u; return 0; }
r[2]+=r[1];
goto P_0c0c7a56;
P_0c0c7a56: /* original 2239, guest PC 0x0c0c7a56 */
if(!s->budget--) { s->failed_pc=0x0c0c7a56u; return 0; }
r[2]&=r[3];
goto P_0c0c7a58;
P_0c0c7a58: /* original 0c26, guest PC 0x0c0c7a58 */
if(!s->budget--) { s->failed_pc=0x0c0c7a58u; return 0; }
write(ram,r[12]+r[0],r[2],4);
goto P_0c0c7a5a;
P_0c0c7a5a: /* original 7040, guest PC 0x0c0c7a5a */
if(!s->budget--) { s->failed_pc=0x0c0c7a5au; return 0; }
r[0]+=0x00000040u;
goto P_0c0c7a5c;
P_0c0c7a5c: /* original e1ff, guest PC 0x0c0c7a5c */
if(!s->budget--) { s->failed_pc=0x0c0c7a5cu; return 0; }
r[1]=0xffffffffu;
goto P_0c0c7a5e;
P_0c0c7a5e: /* original bed0, guest PC 0x0c0c7a5e */
if(!s->budget--) { s->failed_pc=0x0c0c7a5eu; return 0; }
target=code_base|0x0c0c7802u; r[16]=code_base|0x0c0c7a62u;
write(ram,r[12]+r[0],r[1],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c7a62u) { target=s->pc; goto dispatch; }
goto P_0c0c7a62;
P_0c0c7a60: /* original 0c16, guest PC 0x0c0c7a60 */
if(!s->budget--) { s->failed_pc=0x0c0c7a60u; return 0; }
write(ram,r[12]+r[0],r[1],4);
goto P_0c0c7a62;
P_0c0c7a62: /* original e000, guest PC 0x0c0c7a62 */
if(!s->budget--) { s->failed_pc=0x0c0c7a62u; return 0; }
r[0]=0x00000000u;
goto P_0c0c7a64;
P_0c0c7a64: /* original 4f26, guest PC 0x0c0c7a64 */
if(!s->budget--) { s->failed_pc=0x0c0c7a64u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0c7a66;
P_0c0c7a66: /* original 69f6, guest PC 0x0c0c7a66 */
if(!s->budget--) { s->failed_pc=0x0c0c7a66u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c0c7a68;
P_0c0c7a68: /* original 6af6, guest PC 0x0c0c7a68 */
if(!s->budget--) { s->failed_pc=0x0c0c7a68u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0c7a6a;
P_0c0c7a6a: /* original 6bf6, guest PC 0x0c0c7a6a */
if(!s->budget--) { s->failed_pc=0x0c0c7a6au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0c7a6c;
P_0c0c7a6c: /* original 6cf6, guest PC 0x0c0c7a6c */
if(!s->budget--) { s->failed_pc=0x0c0c7a6cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0c7a6e;
P_0c0c7a6e: /* original 6df6, guest PC 0x0c0c7a6e */
if(!s->budget--) { s->failed_pc=0x0c0c7a6eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0c7a70;
P_0c0c7a70: /* original 000b, guest PC 0x0c0c7a70 */
if(!s->budget--) { s->failed_pc=0x0c0c7a70u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0c7a72: /* original 6ef6, guest PC 0x0c0c7a72 */
if(!s->budget--) { s->failed_pc=0x0c0c7a72u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0c7a74u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0c7a74u; return 0; } return 1;
P_0c0c7c50: /* original 2fe6, guest PC 0x0c0c7c50 */
if(!s->budget--) { s->failed_pc=0x0c0c7c50u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c7c52;
P_0c0c7c52: /* original e201, guest PC 0x0c0c7c52 */
if(!s->budget--) { s->failed_pc=0x0c0c7c52u; return 0; }
r[2]=0x00000001u;
goto P_0c0c7c54;
P_0c0c7c54: /* original 2fd6, guest PC 0x0c0c7c54 */
if(!s->budget--) { s->failed_pc=0x0c0c7c54u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c7c56;
P_0c0c7c56: /* original e07f, guest PC 0x0c0c7c56 */
if(!s->budget--) { s->failed_pc=0x0c0c7c56u; return 0; }
r[0]=0x0000007fu;
goto P_0c0c7c58;
P_0c0c7c58: /* original 2fc6, guest PC 0x0c0c7c58 */
if(!s->budget--) { s->failed_pc=0x0c0c7c58u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c7c5a;
P_0c0c7c5a: /* original ec34, guest PC 0x0c0c7c5a */
if(!s->budget--) { s->failed_pc=0x0c0c7c5au; return 0; }
r[12]=0x00000034u;
goto P_0c0c7c5c;
P_0c0c7c5c: /* original 2fb6, guest PC 0x0c0c7c5c */
if(!s->budget--) { s->failed_pc=0x0c0c7c5cu; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c7c5e;
P_0c0c7c5e: /* original 2fa6, guest PC 0x0c0c7c5e */
if(!s->budget--) { s->failed_pc=0x0c0c7c5eu; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c7c60;
P_0c0c7c60: /* original 2f96, guest PC 0x0c0c7c60 */
if(!s->budget--) { s->failed_pc=0x0c0c7c60u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c7c62;
P_0c0c7c62: /* original d94b, guest PC 0x0c0c7c62 */
if(!s->budget--) { s->failed_pc=0x0c0c7c62u; return 0; }
r[9]=read(ram,0x0c0c7d90u,4);
goto P_0c0c7c64;
P_0c0c7c64: /* original 4f22, guest PC 0x0c0c7c64 */
if(!s->budget--) { s->failed_pc=0x0c0c7c64u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0c7c66;
P_0c0c7c66: /* original d34c, guest PC 0x0c0c7c66 */
if(!s->budget--) { s->failed_pc=0x0c0c7c66u; return 0; }
r[3]=read(ram,0x0c0c7d98u,4);
goto P_0c0c7c68;
P_0c0c7c68: /* original db4a, guest PC 0x0c0c7c68 */
if(!s->budget--) { s->failed_pc=0x0c0c7c68u; return 0; }
r[11]=read(ram,0x0c0c7d94u,4);
goto P_0c0c7c6a;
P_0c0c7c6a: /* original 4f12, guest PC 0x0c0c7c6a */
if(!s->budget--) { s->failed_pc=0x0c0c7c6au; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c0c7c6c;
P_0c0c7c6c: /* original 7ffc, guest PC 0x0c0c7c6c */
if(!s->budget--) { s->failed_pc=0x0c0c7c6cu; return 0; }
r[15]+=0xfffffffcu;
goto P_0c0c7c6e;
P_0c0c7c6e: /* original 2f32, guest PC 0x0c0c7c6e */
if(!s->budget--) { s->failed_pc=0x0c0c7c6eu; return 0; }
write(ram,r[15],r[3],4);
goto P_0c0c7c70;
P_0c0c7c70: /* original 0924, guest PC 0x0c0c7c70 */
if(!s->budget--) { s->failed_pc=0x0c0c7c70u; return 0; }
write(ram,r[9]+r[0],r[2],1);
goto P_0c0c7c72;
P_0c0c7c72: /* original e01c, guest PC 0x0c0c7c72 */
if(!s->budget--) { s->failed_pc=0x0c0c7c72u; return 0; }
r[0]=0x0000001cu;
goto P_0c0c7c74;
P_0c0c7c74: /* original 0a9c, guest PC 0x0c0c7c74 */
if(!s->budget--) { s->failed_pc=0x0c0c7c74u; return 0; }
r[10]=(uint32_t)(int32_t)(int8_t)read(ram,r[9]+r[0],1);
goto P_0c0c7c76;
P_0c0c7c76: /* original d24a, guest PC 0x0c0c7c76 */
if(!s->budget--) { s->failed_pc=0x0c0c7c76u; return 0; }
r[2]=read(ram,0x0c0c7da0u,4);
goto P_0c0c7c78;
P_0c0c7c78: /* original 6aac, guest PC 0x0c0c7c78 */
if(!s->budget--) { s->failed_pc=0x0c0c7c78u; return 0; }
r[10]=r[10]&255u;
goto P_0c0c7c7a;
P_0c0c7c7a: /* original d348, guest PC 0x0c0c7c7a */
if(!s->budget--) { s->failed_pc=0x0c0c7c7au; return 0; }
r[3]=read(ram,0x0c0c7d9cu,4);
goto P_0c0c7c7c;
P_0c0c7c7c: /* original 2acf, guest PC 0x0c0c7c7c */
if(!s->budget--) { s->failed_pc=0x0c0c7c7cu; return 0; }
r[19]=(uint32_t)((int32_t)(int16_t)r[10]*(int32_t)(int16_t)r[12]);
goto P_0c0c7c7e;
P_0c0c7c7e: /* original 6ea3, guest PC 0x0c0c7c7e */
if(!s->budget--) { s->failed_pc=0x0c0c7c7eu; return 0; }
r[14]=r[10];
goto P_0c0c7c80;
P_0c0c7c80: /* original 4e08, guest PC 0x0c0c7c80 */
if(!s->budget--) { s->failed_pc=0x0c0c7c80u; return 0; }
r[14]<<=2;
goto P_0c0c7c82;
P_0c0c7c82: /* original 4e08, guest PC 0x0c0c7c82 */
if(!s->budget--) { s->failed_pc=0x0c0c7c82u; return 0; }
r[14]<<=2;
goto P_0c0c7c84;
P_0c0c7c84: /* original 9079, guest PC 0x0c0c7c84 */
if(!s->budget--) { s->failed_pc=0x0c0c7c84u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c7d7au,2);
goto P_0c0c7c86;
P_0c0c7c86: /* original 4e08, guest PC 0x0c0c7c86 */
if(!s->budget--) { s->failed_pc=0x0c0c7c86u; return 0; }
r[14]<<=2;
goto P_0c0c7c88;
P_0c0c7c88: /* original 0c1a, guest PC 0x0c0c7c88 */
if(!s->budget--) { s->failed_pc=0x0c0c7c88u; return 0; }
r[12]=r[19];
goto P_0c0c7c8a;
P_0c0c7c8a: /* original 3e3c, guest PC 0x0c0c7c8a */
if(!s->budget--) { s->failed_pc=0x0c0c7c8au; return 0; }
r[14]+=r[3];
goto P_0c0c7c8c;
P_0c0c7c8c: /* original 6ccf, guest PC 0x0c0c7c8c */
if(!s->budget--) { s->failed_pc=0x0c0c7c8cu; return 0; }
r[12]=(uint32_t)(int32_t)(int16_t)r[12];
goto P_0c0c7c8e;
P_0c0c7c8e: /* original 3c2c, guest PC 0x0c0c7c8e */
if(!s->budget--) { s->failed_pc=0x0c0c7c8eu; return 0; }
r[12]+=r[2];
goto P_0c0c7c90;
P_0c0c7c90: /* original 0be6, guest PC 0x0c0c7c90 */
if(!s->budget--) { s->failed_pc=0x0c0c7c90u; return 0; }
write(ram,r[11]+r[0],r[14],4);
goto P_0c0c7c92;
P_0c0c7c92: /* original 7004, guest PC 0x0c0c7c92 */
if(!s->budget--) { s->failed_pc=0x0c0c7c92u; return 0; }
r[0]+=0x00000004u;
goto P_0c0c7c94;
P_0c0c7c94: /* original 65c3, guest PC 0x0c0c7c94 */
if(!s->budget--) { s->failed_pc=0x0c0c7c94u; return 0; }
r[5]=r[12];
goto P_0c0c7c96;
P_0c0c7c96: /* original 0bc6, guest PC 0x0c0c7c96 */
if(!s->budget--) { s->failed_pc=0x0c0c7c96u; return 0; }
write(ram,r[11]+r[0],r[12],4);
goto P_0c0c7c98;
P_0c0c7c98: /* original d342, guest PC 0x0c0c7c98 */
if(!s->budget--) { s->failed_pc=0x0c0c7c98u; return 0; }
r[3]=read(ram,0x0c0c7da4u,4);
goto P_0c0c7c9a;
P_0c0c7c9a: /* original 430b, guest PC 0x0c0c7c9a */
if(!s->budget--) { s->failed_pc=0x0c0c7c9au; return 0; }
target=r[3];
r[16]=code_base|0x0c0c7c9eu;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c7c9eu) { target=s->pc; goto dispatch; }
goto P_0c0c7c9e;
P_0c0c7c9c: /* original 64e3, guest PC 0x0c0c7c9c */
if(!s->budget--) { s->failed_pc=0x0c0c7c9cu; return 0; }
r[4]=r[14];
goto P_0c0c7c9e;
P_0c0c7c9e: /* original 63e2, guest PC 0x0c0c7c9e */
if(!s->budget--) { s->failed_pc=0x0c0c7c9eu; return 0; }
tmp=read(ram,r[14],4);
r[3]=tmp;
goto P_0c0c7ca0;
P_0c0c7ca0: /* original 906c, guest PC 0x0c0c7ca0 */
if(!s->budget--) { s->failed_pc=0x0c0c7ca0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c7d7cu,2);
goto P_0c0c7ca2;
P_0c0c7ca2: /* original d241, guest PC 0x0c0c7ca2 */
if(!s->budget--) { s->failed_pc=0x0c0c7ca2u; return 0; }
r[2]=read(ram,0x0c0c7da8u,4);
goto P_0c0c7ca4;
P_0c0c7ca4: /* original 6d22, guest PC 0x0c0c7ca4 */
if(!s->budget--) { s->failed_pc=0x0c0c7ca4u; return 0; }
tmp=read(ram,r[2],4);
r[13]=tmp;
goto P_0c0c7ca6;
P_0c0c7ca6: /* original 0b36, guest PC 0x0c0c7ca6 */
if(!s->budget--) { s->failed_pc=0x0c0c7ca6u; return 0; }
write(ram,r[11]+r[0],r[3],4);
goto P_0c0c7ca8;
P_0c0c7ca8: /* original 6192, guest PC 0x0c0c7ca8 */
if(!s->budget--) { s->failed_pc=0x0c0c7ca8u; return 0; }
tmp=read(ram,r[9],4);
r[1]=tmp;
goto P_0c0c7caa;
P_0c0c7caa: /* original d340, guest PC 0x0c0c7caa */
if(!s->budget--) { s->failed_pc=0x0c0c7caau; return 0; }
r[3]=read(ram,0x0c0c7dacu,4);
goto P_0c0c7cac;
P_0c0c7cac: /* original 2138, guest PC 0x0c0c7cac */
if(!s->budget--) { s->failed_pc=0x0c0c7cacu; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[3])==0)!=0);
goto P_0c0c7cae;
P_0c0c7cae: /* original 8b03, guest PC 0x0c0c7cae */
if(!s->budget--) { s->failed_pc=0x0c0c7caeu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c7cb8; }
goto P_0c0c7cb0;
P_0c0c7cb0: /* original d23f, guest PC 0x0c0c7cb0 */
if(!s->budget--) { s->failed_pc=0x0c0c7cb0u; return 0; }
r[2]=read(ram,0x0c0c7db0u,4);
goto P_0c0c7cb2;
P_0c0c7cb2: /* original e034, guest PC 0x0c0c7cb2 */
if(!s->budget--) { s->failed_pc=0x0c0c7cb2u; return 0; }
r[0]=0x00000034u;
goto P_0c0c7cb4;
P_0c0c7cb4: /* original 420b, guest PC 0x0c0c7cb4 */
if(!s->budget--) { s->failed_pc=0x0c0c7cb4u; return 0; }
target=r[2];
r[16]=code_base|0x0c0c7cb8u;
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c7cb8u) { target=s->pc; goto dispatch; }
goto P_0c0c7cb8;
P_0c0c7cb6: /* original 04ed, guest PC 0x0c0c7cb6 */
if(!s->budget--) { s->failed_pc=0x0c0c7cb6u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0c7cb8;
P_0c0c7cb8: /* original e036, guest PC 0x0c0c7cb8 */
if(!s->budget--) { s->failed_pc=0x0c0c7cb8u; return 0; }
r[0]=0x00000036u;
goto P_0c0c7cba;
P_0c0c7cba: /* original 03ed, guest PC 0x0c0c7cba */
if(!s->budget--) { s->failed_pc=0x0c0c7cbau; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0c7cbc;
P_0c0c7cbc: /* original e731, guest PC 0x0c0c7cbc */
if(!s->budget--) { s->failed_pc=0x0c0c7cbcu; return 0; }
r[7]=0x00000031u;
goto P_0c0c7cbe;
P_0c0c7cbe: /* original 905e, guest PC 0x0c0c7cbe */
if(!s->budget--) { s->failed_pc=0x0c0c7cbeu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c7d7eu,2);
goto P_0c0c7cc0;
P_0c0c7cc0: /* original 6273, guest PC 0x0c0c7cc0 */
if(!s->budget--) { s->failed_pc=0x0c0c7cc0u; return 0; }
r[2]=r[7];
goto P_0c0c7cc2;
P_0c0c7cc2: /* original 7253, guest PC 0x0c0c7cc2 */
if(!s->budget--) { s->failed_pc=0x0c0c7cc2u; return 0; }
r[2]+=0x00000053u;
goto P_0c0c7cc4;
P_0c0c7cc4: /* original 0b35, guest PC 0x0c0c7cc4 */
if(!s->budget--) { s->failed_pc=0x0c0c7cc4u; return 0; }
write(ram,r[11]+r[0],r[3],2);
goto P_0c0c7cc6;
P_0c0c7cc6: /* original e300, guest PC 0x0c0c7cc6 */
if(!s->budget--) { s->failed_pc=0x0c0c7cc6u; return 0; }
r[3]=0x00000000u;
goto P_0c0c7cc8;
P_0c0c7cc8: /* original 915a, guest PC 0x0c0c7cc8 */
if(!s->budget--) { s->failed_pc=0x0c0c7cc8u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c7d80u,2);
goto P_0c0c7cca;
P_0c0c7cca: /* original e640, guest PC 0x0c0c7cca */
if(!s->budget--) { s->failed_pc=0x0c0c7ccau; return 0; }
r[6]=0x00000040u;
goto P_0c0c7ccc;
P_0c0c7ccc: /* original 85c6, guest PC 0x0c0c7ccc */
if(!s->budget--) { s->failed_pc=0x0c0c7cccu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[12]+12,2);
goto P_0c0c7cce;
P_0c0c7cce: /* original 6533, guest PC 0x0c0c7cce */
if(!s->budget--) { s->failed_pc=0x0c0c7cceu; return 0; }
r[5]=r[3];
goto P_0c0c7cd0;
P_0c0c7cd0: /* original 31bc, guest PC 0x0c0c7cd0 */
if(!s->budget--) { s->failed_pc=0x0c0c7cd0u; return 0; }
r[1]+=r[11];
goto P_0c0c7cd2;
P_0c0c7cd2: /* original 2101, guest PC 0x0c0c7cd2 */
if(!s->budget--) { s->failed_pc=0x0c0c7cd2u; return 0; }
write(ram,r[1],r[0],2);
goto P_0c0c7cd4;
P_0c0c7cd4: /* original 2f36, guest PC 0x0c0c7cd4 */
if(!s->budget--) { s->failed_pc=0x0c0c7cd4u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c7cd6;
P_0c0c7cd6: /* original 54f1, guest PC 0x0c0c7cd6 */
if(!s->budget--) { s->failed_pc=0x0c0c7cd6u; return 0; }
r[4]=read(ram,r[15]+4,4);
goto P_0c0c7cd8;
P_0c0c7cd8: /* original d136, guest PC 0x0c0c7cd8 */
if(!s->budget--) { s->failed_pc=0x0c0c7cd8u; return 0; }
r[1]=read(ram,0x0c0c7db4u,4);
goto P_0c0c7cda;
P_0c0c7cda: /* original 410b, guest PC 0x0c0c7cda */
if(!s->budget--) { s->failed_pc=0x0c0c7cdau; return 0; }
target=r[1];
r[16]=code_base|0x0c0c7cdeu;
r[4]+=r[2];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c7cdeu) { target=s->pc; goto dispatch; }
goto P_0c0c7cde;
P_0c0c7cdc: /* original 342c, guest PC 0x0c0c7cdc */
if(!s->budget--) { s->failed_pc=0x0c0c7cdcu; return 0; }
r[4]+=r[2];
goto P_0c0c7cde;
P_0c0c7cde: /* original d336, guest PC 0x0c0c7cde */
if(!s->budget--) { s->failed_pc=0x0c0c7cdeu; return 0; }
r[3]=read(ram,0x0c0c7db8u,4);
goto P_0c0c7ce0;
P_0c0c7ce0: /* original 7f04, guest PC 0x0c0c7ce0 */
if(!s->budget--) { s->failed_pc=0x0c0c7ce0u; return 0; }
r[15]+=0x00000004u;
goto P_0c0c7ce2;
P_0c0c7ce2: /* original 430b, guest PC 0x0c0c7ce2 */
if(!s->budget--) { s->failed_pc=0x0c0c7ce2u; return 0; }
target=r[3];
r[16]=code_base|0x0c0c7ce6u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c7ce6u) { target=s->pc; goto dispatch; }
goto P_0c0c7ce6;
P_0c0c7ce4: /* original 64d3, guest PC 0x0c0c7ce4 */
if(!s->budget--) { s->failed_pc=0x0c0c7ce4u; return 0; }
r[4]=r[13];
goto P_0c0c7ce6;
P_0c0c7ce6: /* original e024, guest PC 0x0c0c7ce6 */
if(!s->budget--) { s->failed_pc=0x0c0c7ce6u; return 0; }
r[0]=0x00000024u;
goto P_0c0c7ce8;
P_0c0c7ce8: /* original f3c6, guest PC 0x0c0c7ce8 */
if(!s->budget--) { s->failed_pc=0x0c0c7ce8u; return 0; }
vf3_matrix_load(s,ram,3,r[12]+r[0]);
goto P_0c0c7cea;
P_0c0c7cea: /* original e300, guest PC 0x0c0c7cea */
if(!s->budget--) { s->failed_pc=0x0c0c7ceau; return 0; }
r[3]=0x00000000u;
goto P_0c0c7cec;
P_0c0c7cec: /* original 9049, guest PC 0x0c0c7cec */
if(!s->budget--) { s->failed_pc=0x0c0c7cecu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c7d82u,2);
goto P_0c0c7cee;
P_0c0c7cee: /* original fd37, guest PC 0x0c0c7cee */
if(!s->budget--) { s->failed_pc=0x0c0c7ceeu; return 0; }
vf3_matrix_store(s,ram,3,r[13]+r[0]);
goto P_0c0c7cf0;
P_0c0c7cf0: /* original e028, guest PC 0x0c0c7cf0 */
if(!s->budget--) { s->failed_pc=0x0c0c7cf0u; return 0; }
r[0]=0x00000028u;
goto P_0c0c7cf2;
P_0c0c7cf2: /* original f3c6, guest PC 0x0c0c7cf2 */
if(!s->budget--) { s->failed_pc=0x0c0c7cf2u; return 0; }
vf3_matrix_load(s,ram,3,r[12]+r[0]);
goto P_0c0c7cf4;
P_0c0c7cf4: /* original 9046, guest PC 0x0c0c7cf4 */
if(!s->budget--) { s->failed_pc=0x0c0c7cf4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c7d84u,2);
goto P_0c0c7cf6;
P_0c0c7cf6: /* original fd37, guest PC 0x0c0c7cf6 */
if(!s->budget--) { s->failed_pc=0x0c0c7cf6u; return 0; }
vf3_matrix_store(s,ram,3,r[13]+r[0]);
goto P_0c0c7cf8;
P_0c0c7cf8: /* original 9045, guest PC 0x0c0c7cf8 */
if(!s->budget--) { s->failed_pc=0x0c0c7cf8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c7d86u,2);
goto P_0c0c7cfa;
P_0c0c7cfa: /* original 0b36, guest PC 0x0c0c7cfa */
if(!s->budget--) { s->failed_pc=0x0c0c7cfau; return 0; }
write(ram,r[11]+r[0],r[3],4);
goto P_0c0c7cfc;
P_0c0c7cfc: /* original e02c, guest PC 0x0c0c7cfc */
if(!s->budget--) { s->failed_pc=0x0c0c7cfcu; return 0; }
r[0]=0x0000002cu;
goto P_0c0c7cfe;
P_0c0c7cfe: /* original f3c6, guest PC 0x0c0c7cfe */
if(!s->budget--) { s->failed_pc=0x0c0c7cfeu; return 0; }
vf3_matrix_load(s,ram,3,r[12]+r[0]);
goto P_0c0c7d00;
P_0c0c7d00: /* original 9042, guest PC 0x0c0c7d00 */
if(!s->budget--) { s->failed_pc=0x0c0c7d00u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c7d88u,2);
goto P_0c0c7d02;
P_0c0c7d02: /* original fd37, guest PC 0x0c0c7d02 */
if(!s->budget--) { s->failed_pc=0x0c0c7d02u; return 0; }
vf3_matrix_store(s,ram,3,r[13]+r[0]);
goto P_0c0c7d04;
P_0c0c7d04: /* original e030, guest PC 0x0c0c7d04 */
if(!s->budget--) { s->failed_pc=0x0c0c7d04u; return 0; }
r[0]=0x00000030u;
goto P_0c0c7d06;
P_0c0c7d06: /* original f3c6, guest PC 0x0c0c7d06 */
if(!s->budget--) { s->failed_pc=0x0c0c7d06u; return 0; }
vf3_matrix_load(s,ram,3,r[12]+r[0]);
goto P_0c0c7d08;
P_0c0c7d08: /* original 903f, guest PC 0x0c0c7d08 */
if(!s->budget--) { s->failed_pc=0x0c0c7d08u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c7d8au,2);
goto P_0c0c7d0a;
P_0c0c7d0a: /* original fd37, guest PC 0x0c0c7d0a */
if(!s->budget--) { s->failed_pc=0x0c0c7d0au; return 0; }
vf3_matrix_store(s,ram,3,r[13]+r[0]);
goto P_0c0c7d0c;
P_0c0c7d0c: /* original d22b, guest PC 0x0c0c7d0c */
if(!s->budget--) { s->failed_pc=0x0c0c7d0cu; return 0; }
r[2]=read(ram,0x0c0c7dbcu,4);
goto P_0c0c7d0e;
P_0c0c7d0e: /* original 6322, guest PC 0x0c0c7d0e */
if(!s->budget--) { s->failed_pc=0x0c0c7d0eu; return 0; }
tmp=read(ram,r[2],4);
r[3]=tmp;
goto P_0c0c7d10;
P_0c0c7d10: /* original 3a30, guest PC 0x0c0c7d10 */
if(!s->budget--) { s->failed_pc=0x0c0c7d10u; return 0; }
r[17]=(r[17]&~1u)|((r[10]==r[3])!=0);
goto P_0c0c7d12;
P_0c0c7d12: /* original 890d, guest PC 0x0c0c7d12 */
if(!s->budget--) { s->failed_pc=0x0c0c7d12u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c7d30; }
goto P_0c0c7d14;
P_0c0c7d14: /* original bc98, guest PC 0x0c0c7d14 */
if(!s->budget--) { s->failed_pc=0x0c0c7d14u; return 0; }
target=code_base|0x0c0c7648u; r[16]=code_base|0x0c0c7d18u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c7d18u) { target=s->pc; goto dispatch; }
goto P_0c0c7d18;
P_0c0c7d16: /* original 0009, guest PC 0x0c0c7d16 */
if(!s->budget--) { s->failed_pc=0x0c0c7d16u; return 0; }
goto P_0c0c7d18;
P_0c0c7d18: /* original 6192, guest PC 0x0c0c7d18 */
if(!s->budget--) { s->failed_pc=0x0c0c7d18u; return 0; }
tmp=read(ram,r[9],4);
r[1]=tmp;
goto P_0c0c7d1a;
P_0c0c7d1a: /* original d324, guest PC 0x0c0c7d1a */
if(!s->budget--) { s->failed_pc=0x0c0c7d1au; return 0; }
r[3]=read(ram,0x0c0c7dacu,4);
goto P_0c0c7d1c;
P_0c0c7d1c: /* original 2138, guest PC 0x0c0c7d1c */
if(!s->budget--) { s->failed_pc=0x0c0c7d1cu; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[3])==0)!=0);
goto P_0c0c7d1e;
P_0c0c7d1e: /* original 8b07, guest PC 0x0c0c7d1e */
if(!s->budget--) { s->failed_pc=0x0c0c7d1eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c7d30; }
goto P_0c0c7d20;
P_0c0c7d20: /* original d227, guest PC 0x0c0c7d20 */
if(!s->budget--) { s->failed_pc=0x0c0c7d20u; return 0; }
r[2]=read(ram,0x0c0c7dc0u,4);
goto P_0c0c7d22;
P_0c0c7d22: /* original 420b, guest PC 0x0c0c7d22 */
if(!s->budget--) { s->failed_pc=0x0c0c7d22u; return 0; }
target=r[2];
r[16]=code_base|0x0c0c7d26u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c7d26u) { target=s->pc; goto dispatch; }
goto P_0c0c7d26;
P_0c0c7d24: /* original 0009, guest PC 0x0c0c7d24 */
if(!s->budget--) { s->failed_pc=0x0c0c7d24u; return 0; }
goto P_0c0c7d26;
P_0c0c7d26: /* original bccb, guest PC 0x0c0c7d26 */
if(!s->budget--) { s->failed_pc=0x0c0c7d26u; return 0; }
target=code_base|0x0c0c76c0u; r[16]=code_base|0x0c0c7d2au;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c7d2au) { target=s->pc; goto dispatch; }
goto P_0c0c7d2a;
P_0c0c7d28: /* original 0009, guest PC 0x0c0c7d28 */
if(!s->budget--) { s->failed_pc=0x0c0c7d28u; return 0; }
goto P_0c0c7d2a;
P_0c0c7d2a: /* original d226, guest PC 0x0c0c7d2a */
if(!s->budget--) { s->failed_pc=0x0c0c7d2au; return 0; }
r[2]=read(ram,0x0c0c7dc4u,4);
goto P_0c0c7d2c;
P_0c0c7d2c: /* original 420b, guest PC 0x0c0c7d2c */
if(!s->budget--) { s->failed_pc=0x0c0c7d2cu; return 0; }
target=r[2];
r[16]=code_base|0x0c0c7d30u;
r[4]=r[10];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c7d30u) { target=s->pc; goto dispatch; }
goto P_0c0c7d30;
P_0c0c7d2e: /* original 64a3, guest PC 0x0c0c7d2e */
if(!s->budget--) { s->failed_pc=0x0c0c7d2eu; return 0; }
r[4]=r[10];
goto P_0c0c7d30;
P_0c0c7d30: /* original 902c, guest PC 0x0c0c7d30 */
if(!s->budget--) { s->failed_pc=0x0c0c7d30u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c7d8cu,2);
goto P_0c0c7d32;
P_0c0c7d32: /* original 0da4, guest PC 0x0c0c7d32 */
if(!s->budget--) { s->failed_pc=0x0c0c7d32u; return 0; }
write(ram,r[13]+r[0],r[10],1);
goto P_0c0c7d34;
P_0c0c7d34: /* original e031, guest PC 0x0c0c7d34 */
if(!s->budget--) { s->failed_pc=0x0c0c7d34u; return 0; }
r[0]=0x00000031u;
goto P_0c0c7d36;
P_0c0c7d36: /* original 03ec, guest PC 0x0c0c7d36 */
if(!s->budget--) { s->failed_pc=0x0c0c7d36u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0c7d38;
P_0c0c7d38: /* original 2338, guest PC 0x0c0c7d38 */
if(!s->budget--) { s->failed_pc=0x0c0c7d38u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c0c7d3a;
P_0c0c7d3a: /* original 8904, guest PC 0x0c0c7d3a */
if(!s->budget--) { s->failed_pc=0x0c0c7d3au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c7d46; }
goto P_0c0c7d3c;
P_0c0c7d3c: /* original d322, guest PC 0x0c0c7d3c */
if(!s->budget--) { s->failed_pc=0x0c0c7d3cu; return 0; }
r[3]=read(ram,0x0c0c7dc8u,4);
goto P_0c0c7d3e;
P_0c0c7d3e: /* original 65a3, guest PC 0x0c0c7d3e */
if(!s->budget--) { s->failed_pc=0x0c0c7d3eu; return 0; }
r[5]=r[10];
goto P_0c0c7d40;
P_0c0c7d40: /* original 84e4, guest PC 0x0c0c7d40 */
if(!s->budget--) { s->failed_pc=0x0c0c7d40u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+4,1);
goto P_0c0c7d42;
P_0c0c7d42: /* original 430b, guest PC 0x0c0c7d42 */
if(!s->budget--) { s->failed_pc=0x0c0c7d42u; return 0; }
target=r[3];
r[16]=code_base|0x0c0c7d46u;
r[4]=r[0]&255u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c7d46u) { target=s->pc; goto dispatch; }
goto P_0c0c7d46;
P_0c0c7d44: /* original 640c, guest PC 0x0c0c7d44 */
if(!s->budget--) { s->failed_pc=0x0c0c7d44u; return 0; }
r[4]=r[0]&255u;
goto P_0c0c7d46;
P_0c0c7d46: /* original d321, guest PC 0x0c0c7d46 */
if(!s->budget--) { s->failed_pc=0x0c0c7d46u; return 0; }
r[3]=read(ram,0x0c0c7dccu,4);
goto P_0c0c7d48;
P_0c0c7d48: /* original 430b, guest PC 0x0c0c7d48 */
if(!s->budget--) { s->failed_pc=0x0c0c7d48u; return 0; }
target=r[3];
r[16]=code_base|0x0c0c7d4cu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c7d4cu) { target=s->pc; goto dispatch; }
goto P_0c0c7d4c;
P_0c0c7d4a: /* original 0009, guest PC 0x0c0c7d4a */
if(!s->budget--) { s->failed_pc=0x0c0c7d4au; return 0; }
goto P_0c0c7d4c;
P_0c0c7d4c: /* original d220, guest PC 0x0c0c7d4c */
if(!s->budget--) { s->failed_pc=0x0c0c7d4cu; return 0; }
r[2]=read(ram,0x0c0c7dd0u,4);
goto P_0c0c7d4e;
P_0c0c7d4e: /* original 420b, guest PC 0x0c0c7d4e */
if(!s->budget--) { s->failed_pc=0x0c0c7d4eu; return 0; }
target=r[2];
r[16]=code_base|0x0c0c7d52u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c7d52u) { target=s->pc; goto dispatch; }
goto P_0c0c7d52;
P_0c0c7d50: /* original 0009, guest PC 0x0c0c7d50 */
if(!s->budget--) { s->failed_pc=0x0c0c7d50u; return 0; }
goto P_0c0c7d52;
P_0c0c7d52: /* original 60d2, guest PC 0x0c0c7d52 */
if(!s->budget--) { s->failed_pc=0x0c0c7d52u; return 0; }
tmp=read(ram,r[13],4);
r[0]=tmp;
goto P_0c0c7d54;
P_0c0c7d54: /* original c810, guest PC 0x0c0c7d54 */
if(!s->budget--) { s->failed_pc=0x0c0c7d54u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&16u)==0)!=0);
goto P_0c0c7d56;
P_0c0c7d56: /* original 8b02, guest PC 0x0c0c7d56 */
if(!s->budget--) { s->failed_pc=0x0c0c7d56u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c7d5e; }
goto P_0c0c7d58;
P_0c0c7d58: /* original d21e, guest PC 0x0c0c7d58 */
if(!s->budget--) { s->failed_pc=0x0c0c7d58u; return 0; }
r[2]=read(ram,0x0c0c7dd4u,4);
goto P_0c0c7d5a;
P_0c0c7d5a: /* original 420b, guest PC 0x0c0c7d5a */
if(!s->budget--) { s->failed_pc=0x0c0c7d5au; return 0; }
target=r[2];
r[16]=code_base|0x0c0c7d5eu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c7d5eu) { target=s->pc; goto dispatch; }
goto P_0c0c7d5e;
P_0c0c7d5c: /* original 0009, guest PC 0x0c0c7d5c */
if(!s->budget--) { s->failed_pc=0x0c0c7d5cu; return 0; }
goto P_0c0c7d5e;
P_0c0c7d5e: /* original d31e, guest PC 0x0c0c7d5e */
if(!s->budget--) { s->failed_pc=0x0c0c7d5eu; return 0; }
r[3]=read(ram,0x0c0c7dd8u,4);
goto P_0c0c7d60;
P_0c0c7d60: /* original 430b, guest PC 0x0c0c7d60 */
if(!s->budget--) { s->failed_pc=0x0c0c7d60u; return 0; }
target=r[3];
r[16]=code_base|0x0c0c7d64u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c7d64u) { target=s->pc; goto dispatch; }
goto P_0c0c7d64;
P_0c0c7d62: /* original 0009, guest PC 0x0c0c7d62 */
if(!s->budget--) { s->failed_pc=0x0c0c7d62u; return 0; }
goto P_0c0c7d64;
P_0c0c7d64: /* original d21d, guest PC 0x0c0c7d64 */
if(!s->budget--) { s->failed_pc=0x0c0c7d64u; return 0; }
r[2]=read(ram,0x0c0c7ddcu,4);
goto P_0c0c7d66;
P_0c0c7d66: /* original 420b, guest PC 0x0c0c7d66 */
if(!s->budget--) { s->failed_pc=0x0c0c7d66u; return 0; }
target=r[2];
r[16]=code_base|0x0c0c7d6au;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c7d6au) { target=s->pc; goto dispatch; }
goto P_0c0c7d6a;
P_0c0c7d68: /* original 0009, guest PC 0x0c0c7d68 */
if(!s->budget--) { s->failed_pc=0x0c0c7d68u; return 0; }
goto P_0c0c7d6a;
P_0c0c7d6a: /* original 7f04, guest PC 0x0c0c7d6a */
if(!s->budget--) { s->failed_pc=0x0c0c7d6au; return 0; }
r[15]+=0x00000004u;
goto P_0c0c7d6c;
P_0c0c7d6c: /* original 4f16, guest PC 0x0c0c7d6c */
if(!s->budget--) { s->failed_pc=0x0c0c7d6cu; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c0c7d6e;
P_0c0c7d6e: /* original 4f26, guest PC 0x0c0c7d6e */
if(!s->budget--) { s->failed_pc=0x0c0c7d6eu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0c7d70;
P_0c0c7d70: /* original 69f6, guest PC 0x0c0c7d70 */
if(!s->budget--) { s->failed_pc=0x0c0c7d70u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c0c7d72;
P_0c0c7d72: /* original 6af6, guest PC 0x0c0c7d72 */
if(!s->budget--) { s->failed_pc=0x0c0c7d72u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0c7d74;
P_0c0c7d74: /* original 6bf6, guest PC 0x0c0c7d74 */
if(!s->budget--) { s->failed_pc=0x0c0c7d74u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0c7d76;
P_0c0c7d76: /* original a033, guest PC 0x0c0c7d76 */
if(!s->budget--) { s->failed_pc=0x0c0c7d76u; return 0; }
goto P_0c0c7de0;
P_0c0c7d78: /* original 0009, guest PC 0x0c0c7d78 */
if(!s->budget--) { s->failed_pc=0x0c0c7d78u; return 0; }
if(!vf3_matrix_family(0x0c0c7d7au,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0c7d7au; return 0; } return 1;
P_0c0c7de0: /* original 6cf6, guest PC 0x0c0c7de0 */
if(!s->budget--) { s->failed_pc=0x0c0c7de0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0c7de2;
P_0c0c7de2: /* original 6df6, guest PC 0x0c0c7de2 */
if(!s->budget--) { s->failed_pc=0x0c0c7de2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0c7de4;
P_0c0c7de4: /* original a95e, guest PC 0x0c0c7de4 */
if(!s->budget--) { s->failed_pc=0x0c0c7de4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0c70a4u,s,ram);
P_0c0c7de6: /* original 6ef6, guest PC 0x0c0c7de6 */
if(!s->budget--) { s->failed_pc=0x0c0c7de6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0c7de8u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0c7de8u; return 0; } return 1;
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
if(!vf3_matrix_family(0x0c0c9d04u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0c9d04u; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
