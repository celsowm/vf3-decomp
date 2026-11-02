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
int vf3_away_batch77_adapter_10(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c0a07e4u: goto P_0c0a07e4;
case 0x0c0a07e6u: goto P_0c0a07e6;
case 0x0c0a07e8u: goto P_0c0a07e8;
case 0x0c0a07eau: goto P_0c0a07ea;
case 0x0c0a07ecu: goto P_0c0a07ec;
case 0x0c0a07eeu: goto P_0c0a07ee;
case 0x0c0a07f0u: goto P_0c0a07f0;
case 0x0c0a07f2u: goto P_0c0a07f2;
case 0x0c0a07f4u: goto P_0c0a07f4;
case 0x0c0a07f6u: goto P_0c0a07f6;
case 0x0c0a07f8u: goto P_0c0a07f8;
case 0x0c0a07fau: goto P_0c0a07fa;
case 0x0c0a07fcu: goto P_0c0a07fc;
case 0x0c0a07feu: goto P_0c0a07fe;
case 0x0c0a0800u: goto P_0c0a0800;
case 0x0c0a0802u: goto P_0c0a0802;
case 0x0c0a0804u: goto P_0c0a0804;
case 0x0c0a0806u: goto P_0c0a0806;
case 0x0c0a0808u: goto P_0c0a0808;
case 0x0c0a080au: goto P_0c0a080a;
case 0x0c0a080cu: goto P_0c0a080c;
case 0x0c0a080eu: goto P_0c0a080e;
case 0x0c0a0810u: goto P_0c0a0810;
case 0x0c0a0812u: goto P_0c0a0812;
case 0x0c0a0814u: goto P_0c0a0814;
case 0x0c0a0816u: goto P_0c0a0816;
case 0x0c0a0818u: goto P_0c0a0818;
case 0x0c0a081au: goto P_0c0a081a;
case 0x0c0a081cu: goto P_0c0a081c;
case 0x0c0a081eu: goto P_0c0a081e;
case 0x0c0a0820u: goto P_0c0a0820;
case 0x0c0a0822u: goto P_0c0a0822;
case 0x0c0a0824u: goto P_0c0a0824;
case 0x0c0a0826u: goto P_0c0a0826;
case 0x0c0a0828u: goto P_0c0a0828;
case 0x0c0a082au: goto P_0c0a082a;
case 0x0c0a082cu: goto P_0c0a082c;
case 0x0c0a082eu: goto P_0c0a082e;
case 0x0c0a0830u: goto P_0c0a0830;
case 0x0c0a0832u: goto P_0c0a0832;
case 0x0c0a0834u: goto P_0c0a0834;
case 0x0c0a0836u: goto P_0c0a0836;
case 0x0c0a085cu: goto P_0c0a085c;
case 0x0c0a085eu: goto P_0c0a085e;
case 0x0c0a0860u: goto P_0c0a0860;
case 0x0c0a0862u: goto P_0c0a0862;
case 0x0c0a0864u: goto P_0c0a0864;
case 0x0c0a0866u: goto P_0c0a0866;
case 0x0c0a0868u: goto P_0c0a0868;
case 0x0c0a086au: goto P_0c0a086a;
case 0x0c0a086cu: goto P_0c0a086c;
case 0x0c0a086eu: goto P_0c0a086e;
case 0x0c0a0870u: goto P_0c0a0870;
case 0x0c0a0872u: goto P_0c0a0872;
case 0x0c0a0874u: goto P_0c0a0874;
case 0x0c0a0876u: goto P_0c0a0876;
case 0x0c0a0878u: goto P_0c0a0878;
case 0x0c0a087au: goto P_0c0a087a;
case 0x0c0a087cu: goto P_0c0a087c;
case 0x0c0a087eu: goto P_0c0a087e;
case 0x0c0a0880u: goto P_0c0a0880;
case 0x0c0a0882u: goto P_0c0a0882;
case 0x0c0a0884u: goto P_0c0a0884;
case 0x0c0a0886u: goto P_0c0a0886;
case 0x0c0a0888u: goto P_0c0a0888;
case 0x0c0a088au: goto P_0c0a088a;
case 0x0c0a088cu: goto P_0c0a088c;
case 0x0c0a088eu: goto P_0c0a088e;
case 0x0c0a0890u: goto P_0c0a0890;
case 0x0c0a0892u: goto P_0c0a0892;
case 0x0c0a0894u: goto P_0c0a0894;
case 0x0c0a0896u: goto P_0c0a0896;
case 0x0c0a0898u: goto P_0c0a0898;
case 0x0c0a089au: goto P_0c0a089a;
case 0x0c0a089cu: goto P_0c0a089c;
case 0x0c0a089eu: goto P_0c0a089e;
case 0x0c0a08a0u: goto P_0c0a08a0;
case 0x0c0a08a2u: goto P_0c0a08a2;
case 0x0c0a08a4u: goto P_0c0a08a4;
case 0x0c0a08a6u: goto P_0c0a08a6;
case 0x0c0a08a8u: goto P_0c0a08a8;
case 0x0c0a08aau: goto P_0c0a08aa;
case 0x0c0a08acu: goto P_0c0a08ac;
case 0x0c0a08aeu: goto P_0c0a08ae;
case 0x0c0a08b0u: goto P_0c0a08b0;
case 0x0c0a08b2u: goto P_0c0a08b2;
case 0x0c0a08b4u: goto P_0c0a08b4;
case 0x0c0a08b6u: goto P_0c0a08b6;
case 0x0c0a08b8u: goto P_0c0a08b8;
case 0x0c0a08bau: goto P_0c0a08ba;
case 0x0c0a08bcu: goto P_0c0a08bc;
case 0x0c0a08beu: goto P_0c0a08be;
case 0x0c0a08c0u: goto P_0c0a08c0;
case 0x0c0a08c2u: goto P_0c0a08c2;
case 0x0c0a08c4u: goto P_0c0a08c4;
case 0x0c0a08c6u: goto P_0c0a08c6;
case 0x0c0a08c8u: goto P_0c0a08c8;
case 0x0c0a08cau: goto P_0c0a08ca;
case 0x0c0a08ccu: goto P_0c0a08cc;
case 0x0c0a08ceu: goto P_0c0a08ce;
case 0x0c0a08d0u: goto P_0c0a08d0;
case 0x0c0a08d2u: goto P_0c0a08d2;
case 0x0c0a08d4u: goto P_0c0a08d4;
case 0x0c0a08d6u: goto P_0c0a08d6;
case 0x0c0a08d8u: goto P_0c0a08d8;
case 0x0c0a08dau: goto P_0c0a08da;
case 0x0c0a08dcu: goto P_0c0a08dc;
case 0x0c0a08deu: goto P_0c0a08de;
case 0x0c0a08e0u: goto P_0c0a08e0;
case 0x0c0a08e2u: goto P_0c0a08e2;
case 0x0c0a08e4u: goto P_0c0a08e4;
case 0x0c0a08e6u: goto P_0c0a08e6;
case 0x0c0a08e8u: goto P_0c0a08e8;
case 0x0c0a08eau: goto P_0c0a08ea;
case 0x0c0a08ecu: goto P_0c0a08ec;
case 0x0c0a08eeu: goto P_0c0a08ee;
case 0x0c0a08f0u: goto P_0c0a08f0;
case 0x0c0a08f2u: goto P_0c0a08f2;
case 0x0c0a08f4u: goto P_0c0a08f4;
case 0x0c0a08f6u: goto P_0c0a08f6;
case 0x0c0a08f8u: goto P_0c0a08f8;
case 0x0c0a08fau: goto P_0c0a08fa;
case 0x0c0a08fcu: goto P_0c0a08fc;
case 0x0c0a08feu: goto P_0c0a08fe;
case 0x0c0a0900u: goto P_0c0a0900;
case 0x0c0a0902u: goto P_0c0a0902;
case 0x0c0a0904u: goto P_0c0a0904;
case 0x0c0a0906u: goto P_0c0a0906;
case 0x0c0a0908u: goto P_0c0a0908;
case 0x0c0a090au: goto P_0c0a090a;
case 0x0c0a090cu: goto P_0c0a090c;
case 0x0c0a090eu: goto P_0c0a090e;
case 0x0c0a0910u: goto P_0c0a0910;
case 0x0c0a0912u: goto P_0c0a0912;
case 0x0c0a0914u: goto P_0c0a0914;
case 0x0c0a0916u: goto P_0c0a0916;
case 0x0c0a0918u: goto P_0c0a0918;
case 0x0c0a091au: goto P_0c0a091a;
case 0x0c0a091cu: goto P_0c0a091c;
case 0x0c0a091eu: goto P_0c0a091e;
case 0x0c0a0920u: goto P_0c0a0920;
case 0x0c0a0922u: goto P_0c0a0922;
case 0x0c0a0924u: goto P_0c0a0924;
case 0x0c0a0926u: goto P_0c0a0926;
case 0x0c0a0928u: goto P_0c0a0928;
case 0x0c0a092au: goto P_0c0a092a;
case 0x0c0a092cu: goto P_0c0a092c;
case 0x0c0a092eu: goto P_0c0a092e;
case 0x0c0a0930u: goto P_0c0a0930;
case 0x0c0a0932u: goto P_0c0a0932;
case 0x0c0a0934u: goto P_0c0a0934;
case 0x0c0a0936u: goto P_0c0a0936;
case 0x0c0a0938u: goto P_0c0a0938;
case 0x0c0a093au: goto P_0c0a093a;
case 0x0c0a093cu: goto P_0c0a093c;
case 0x0c0a093eu: goto P_0c0a093e;
case 0x0c0a0940u: goto P_0c0a0940;
case 0x0c0a0942u: goto P_0c0a0942;
case 0x0c0a0944u: goto P_0c0a0944;
case 0x0c0a0946u: goto P_0c0a0946;
case 0x0c0a0948u: goto P_0c0a0948;
case 0x0c0a094au: goto P_0c0a094a;
case 0x0c0a094cu: goto P_0c0a094c;
case 0x0c0a094eu: goto P_0c0a094e;
case 0x0c0a0950u: goto P_0c0a0950;
case 0x0c0a0952u: goto P_0c0a0952;
case 0x0c0a0954u: goto P_0c0a0954;
case 0x0c0a0956u: goto P_0c0a0956;
case 0x0c0a0958u: goto P_0c0a0958;
case 0x0c0a095au: goto P_0c0a095a;
case 0x0c0a095cu: goto P_0c0a095c;
case 0x0c0a095eu: goto P_0c0a095e;
case 0x0c0a0960u: goto P_0c0a0960;
case 0x0c0a0962u: goto P_0c0a0962;
case 0x0c0a0964u: goto P_0c0a0964;
case 0x0c0a0966u: goto P_0c0a0966;
case 0x0c0a0968u: goto P_0c0a0968;
case 0x0c0a096au: goto P_0c0a096a;
case 0x0c0a096cu: goto P_0c0a096c;
case 0x0c0a096eu: goto P_0c0a096e;
case 0x0c0a0970u: goto P_0c0a0970;
case 0x0c0a0972u: goto P_0c0a0972;
case 0x0c0a0974u: goto P_0c0a0974;
case 0x0c0a0976u: goto P_0c0a0976;
case 0x0c0a0978u: goto P_0c0a0978;
case 0x0c0a097au: goto P_0c0a097a;
case 0x0c0a097cu: goto P_0c0a097c;
case 0x0c0a097eu: goto P_0c0a097e;
case 0x0c0a0980u: goto P_0c0a0980;
case 0x0c0a0982u: goto P_0c0a0982;
case 0x0c0a0984u: goto P_0c0a0984;
case 0x0c0a0986u: goto P_0c0a0986;
case 0x0c0a0988u: goto P_0c0a0988;
case 0x0c0a098au: goto P_0c0a098a;
case 0x0c0a098cu: goto P_0c0a098c;
case 0x0c0a098eu: goto P_0c0a098e;
case 0x0c0a0990u: goto P_0c0a0990;
case 0x0c0a0992u: goto P_0c0a0992;
case 0x0c0a0994u: goto P_0c0a0994;
case 0x0c0a0996u: goto P_0c0a0996;
case 0x0c0a0998u: goto P_0c0a0998;
case 0x0c0a099au: goto P_0c0a099a;
case 0x0c0a099cu: goto P_0c0a099c;
case 0x0c0a099eu: goto P_0c0a099e;
case 0x0c0a09a0u: goto P_0c0a09a0;
case 0x0c0a09a2u: goto P_0c0a09a2;
case 0x0c0a09a4u: goto P_0c0a09a4;
case 0x0c0a09a6u: goto P_0c0a09a6;
case 0x0c0a09a8u: goto P_0c0a09a8;
case 0x0c0a09aau: goto P_0c0a09aa;
case 0x0c0a09acu: goto P_0c0a09ac;
case 0x0c0a09aeu: goto P_0c0a09ae;
case 0x0c0a09b0u: goto P_0c0a09b0;
case 0x0c0a09b2u: goto P_0c0a09b2;
case 0x0c0a09b4u: goto P_0c0a09b4;
case 0x0c0a09b6u: goto P_0c0a09b6;
case 0x0c0a09b8u: goto P_0c0a09b8;
case 0x0c0a09bau: goto P_0c0a09ba;
case 0x0c0a09bcu: goto P_0c0a09bc;
case 0x0c0a09beu: goto P_0c0a09be;
case 0x0c0a09c0u: goto P_0c0a09c0;
case 0x0c0a09c2u: goto P_0c0a09c2;
case 0x0c0a09c4u: goto P_0c0a09c4;
case 0x0c0a09c6u: goto P_0c0a09c6;
case 0x0c0a09c8u: goto P_0c0a09c8;
case 0x0c0a09cau: goto P_0c0a09ca;
case 0x0c0a09ccu: goto P_0c0a09cc;
case 0x0c0a09ceu: goto P_0c0a09ce;
case 0x0c0a09d0u: goto P_0c0a09d0;
case 0x0c0a09d2u: goto P_0c0a09d2;
case 0x0c0a09d4u: goto P_0c0a09d4;
case 0x0c0a0a28u: goto P_0c0a0a28;
case 0x0c0a0a2au: goto P_0c0a0a2a;
case 0x0c0a0a2cu: goto P_0c0a0a2c;
case 0x0c0a0a2eu: goto P_0c0a0a2e;
case 0x0c0a0a30u: goto P_0c0a0a30;
case 0x0c0a0a32u: goto P_0c0a0a32;
case 0x0c0a0a34u: goto P_0c0a0a34;
case 0x0c0a0a36u: goto P_0c0a0a36;
case 0x0c0a0a38u: goto P_0c0a0a38;
case 0x0c0a0a3au: goto P_0c0a0a3a;
case 0x0c0a0a3cu: goto P_0c0a0a3c;
case 0x0c0a0a3eu: goto P_0c0a0a3e;
case 0x0c0a0a40u: goto P_0c0a0a40;
case 0x0c0a0a42u: goto P_0c0a0a42;
case 0x0c0a0a44u: goto P_0c0a0a44;
case 0x0c0a0a46u: goto P_0c0a0a46;
case 0x0c0a0a48u: goto P_0c0a0a48;
case 0x0c0a0a4au: goto P_0c0a0a4a;
case 0x0c0a0a4cu: goto P_0c0a0a4c;
case 0x0c0a0a4eu: goto P_0c0a0a4e;
case 0x0c0a0a50u: goto P_0c0a0a50;
case 0x0c0a0a52u: goto P_0c0a0a52;
case 0x0c0a0a54u: goto P_0c0a0a54;
case 0x0c0a0a56u: goto P_0c0a0a56;
case 0x0c0a0a58u: goto P_0c0a0a58;
case 0x0c0a0a5au: goto P_0c0a0a5a;
case 0x0c0a0a5cu: goto P_0c0a0a5c;
case 0x0c0a0a5eu: goto P_0c0a0a5e;
case 0x0c0a0a60u: goto P_0c0a0a60;
case 0x0c0a0a62u: goto P_0c0a0a62;
case 0x0c0a0a64u: goto P_0c0a0a64;
case 0x0c0a0a66u: goto P_0c0a0a66;
case 0x0c0a0a68u: goto P_0c0a0a68;
case 0x0c0a0a6au: goto P_0c0a0a6a;
case 0x0c0a0a6cu: goto P_0c0a0a6c;
case 0x0c0a0a6eu: goto P_0c0a0a6e;
case 0x0c0a0a70u: goto P_0c0a0a70;
case 0x0c0a0a72u: goto P_0c0a0a72;
case 0x0c0a0a74u: goto P_0c0a0a74;
case 0x0c0a0a76u: goto P_0c0a0a76;
case 0x0c0a0a78u: goto P_0c0a0a78;
case 0x0c0a0a7au: goto P_0c0a0a7a;
case 0x0c0a0a7cu: goto P_0c0a0a7c;
case 0x0c0a0a7eu: goto P_0c0a0a7e;
case 0x0c0a0a80u: goto P_0c0a0a80;
case 0x0c0a0a82u: goto P_0c0a0a82;
case 0x0c0a0a84u: goto P_0c0a0a84;
case 0x0c0a0a86u: goto P_0c0a0a86;
case 0x0c0a0a88u: goto P_0c0a0a88;
case 0x0c0a0a8au: goto P_0c0a0a8a;
case 0x0c0a0a8cu: goto P_0c0a0a8c;
case 0x0c0a0a8eu: goto P_0c0a0a8e;
case 0x0c0a0a90u: goto P_0c0a0a90;
case 0x0c0a0a92u: goto P_0c0a0a92;
case 0x0c0a0a94u: goto P_0c0a0a94;
case 0x0c0a0a96u: goto P_0c0a0a96;
case 0x0c0a0a98u: goto P_0c0a0a98;
case 0x0c0a0a9au: goto P_0c0a0a9a;
case 0x0c0a0a9cu: goto P_0c0a0a9c;
case 0x0c0a0a9eu: goto P_0c0a0a9e;
case 0x0c0a0aa0u: goto P_0c0a0aa0;
case 0x0c0a0aa2u: goto P_0c0a0aa2;
case 0x0c0a0aa4u: goto P_0c0a0aa4;
case 0x0c0a0aa6u: goto P_0c0a0aa6;
case 0x0c0a0aa8u: goto P_0c0a0aa8;
case 0x0c0a0aaau: goto P_0c0a0aaa;
case 0x0c0a0aacu: goto P_0c0a0aac;
case 0x0c0a0aaeu: goto P_0c0a0aae;
case 0x0c0a0ab0u: goto P_0c0a0ab0;
case 0x0c0a0ab2u: goto P_0c0a0ab2;
case 0x0c0a0ab4u: goto P_0c0a0ab4;
case 0x0c0a0ab6u: goto P_0c0a0ab6;
case 0x0c0a0ab8u: goto P_0c0a0ab8;
case 0x0c0a0abau: goto P_0c0a0aba;
case 0x0c0a0abcu: goto P_0c0a0abc;
case 0x0c0a0abeu: goto P_0c0a0abe;
case 0x0c0a0ac0u: goto P_0c0a0ac0;
case 0x0c0a0ac2u: goto P_0c0a0ac2;
case 0x0c0a0ac4u: goto P_0c0a0ac4;
case 0x0c0a0ac6u: goto P_0c0a0ac6;
case 0x0c0a0ac8u: goto P_0c0a0ac8;
case 0x0c0a0acau: goto P_0c0a0aca;
case 0x0c0a0accu: goto P_0c0a0acc;
case 0x0c0a0aceu: goto P_0c0a0ace;
case 0x0c0a0ad0u: goto P_0c0a0ad0;
case 0x0c0a0ad2u: goto P_0c0a0ad2;
case 0x0c0a0ad4u: goto P_0c0a0ad4;
case 0x0c0a0ad6u: goto P_0c0a0ad6;
case 0x0c0a0ad8u: goto P_0c0a0ad8;
case 0x0c0a0adau: goto P_0c0a0ada;
case 0x0c0a0adcu: goto P_0c0a0adc;
case 0x0c0a0adeu: goto P_0c0a0ade;
case 0x0c0a0ae0u: goto P_0c0a0ae0;
case 0x0c0a0ae2u: goto P_0c0a0ae2;
case 0x0c0a0ae4u: goto P_0c0a0ae4;
case 0x0c0a0ae6u: goto P_0c0a0ae6;
case 0x0c0a0ae8u: goto P_0c0a0ae8;
case 0x0c0a0aeau: goto P_0c0a0aea;
case 0x0c0a0aecu: goto P_0c0a0aec;
case 0x0c0a0aeeu: goto P_0c0a0aee;
case 0x0c0a0af0u: goto P_0c0a0af0;
case 0x0c0a0af2u: goto P_0c0a0af2;
case 0x0c0a0af4u: goto P_0c0a0af4;
case 0x0c0a0af6u: goto P_0c0a0af6;
case 0x0c0a0af8u: goto P_0c0a0af8;
case 0x0c0a0afau: goto P_0c0a0afa;
case 0x0c0a0afcu: goto P_0c0a0afc;
case 0x0c0a0afeu: goto P_0c0a0afe;
case 0x0c0a0b00u: goto P_0c0a0b00;
case 0x0c0a0b02u: goto P_0c0a0b02;
case 0x0c0a0b04u: goto P_0c0a0b04;
case 0x0c0a0b06u: goto P_0c0a0b06;
case 0x0c0a0b08u: goto P_0c0a0b08;
case 0x0c0a0b0au: goto P_0c0a0b0a;
case 0x0c0a0b0cu: goto P_0c0a0b0c;
case 0x0c0a0b0eu: goto P_0c0a0b0e;
case 0x0c0a0b10u: goto P_0c0a0b10;
case 0x0c0a0b12u: goto P_0c0a0b12;
case 0x0c0a0b14u: goto P_0c0a0b14;
case 0x0c0a0b16u: goto P_0c0a0b16;
case 0x0c0a0b18u: goto P_0c0a0b18;
case 0x0c0a0b1au: goto P_0c0a0b1a;
case 0x0c0a0b1cu: goto P_0c0a0b1c;
case 0x0c0a0b1eu: goto P_0c0a0b1e;
case 0x0c0a0b20u: goto P_0c0a0b20;
case 0x0c0a0b22u: goto P_0c0a0b22;
case 0x0c0a0b24u: goto P_0c0a0b24;
case 0x0c0a0b26u: goto P_0c0a0b26;
case 0x0c0a0b5cu: goto P_0c0a0b5c;
case 0x0c0a0b5eu: goto P_0c0a0b5e;
case 0x0c0a0b60u: goto P_0c0a0b60;
case 0x0c0a0b62u: goto P_0c0a0b62;
case 0x0c0a0b64u: goto P_0c0a0b64;
case 0x0c0a0b66u: goto P_0c0a0b66;
case 0x0c0a0b68u: goto P_0c0a0b68;
case 0x0c0a0b6au: goto P_0c0a0b6a;
case 0x0c0a0b6cu: goto P_0c0a0b6c;
case 0x0c0a0b6eu: goto P_0c0a0b6e;
case 0x0c0a0b70u: goto P_0c0a0b70;
case 0x0c0a0b72u: goto P_0c0a0b72;
case 0x0c0a0b74u: goto P_0c0a0b74;
case 0x0c0a0b76u: goto P_0c0a0b76;
case 0x0c0a0b78u: goto P_0c0a0b78;
case 0x0c0a0b7au: goto P_0c0a0b7a;
case 0x0c0a0b7cu: goto P_0c0a0b7c;
case 0x0c0a0b7eu: goto P_0c0a0b7e;
case 0x0c0a0b80u: goto P_0c0a0b80;
case 0x0c0a0b82u: goto P_0c0a0b82;
case 0x0c0a0b84u: goto P_0c0a0b84;
case 0x0c0a0b86u: goto P_0c0a0b86;
case 0x0c0a0b88u: goto P_0c0a0b88;
case 0x0c0a0b8au: goto P_0c0a0b8a;
case 0x0c0a0b8cu: goto P_0c0a0b8c;
case 0x0c0a0b8eu: goto P_0c0a0b8e;
case 0x0c0a0b90u: goto P_0c0a0b90;
case 0x0c0a0b92u: goto P_0c0a0b92;
case 0x0c0a0b94u: goto P_0c0a0b94;
case 0x0c0a0b96u: goto P_0c0a0b96;
case 0x0c0a0b98u: goto P_0c0a0b98;
case 0x0c0a0b9au: goto P_0c0a0b9a;
case 0x0c0a0b9cu: goto P_0c0a0b9c;
case 0x0c0a0b9eu: goto P_0c0a0b9e;
case 0x0c0a0ba0u: goto P_0c0a0ba0;
case 0x0c0a0ba2u: goto P_0c0a0ba2;
case 0x0c0a0ba4u: goto P_0c0a0ba4;
case 0x0c0a0ba6u: goto P_0c0a0ba6;
case 0x0c0a0ba8u: goto P_0c0a0ba8;
case 0x0c0a0baau: goto P_0c0a0baa;
case 0x0c0a0bacu: goto P_0c0a0bac;
case 0x0c0a0baeu: goto P_0c0a0bae;
case 0x0c0a0bb0u: goto P_0c0a0bb0;
case 0x0c0a0bb2u: goto P_0c0a0bb2;
case 0x0c0a0bb4u: goto P_0c0a0bb4;
case 0x0c0a0bb6u: goto P_0c0a0bb6;
case 0x0c0a0bb8u: goto P_0c0a0bb8;
case 0x0c0a0bbau: goto P_0c0a0bba;
case 0x0c0a0bbcu: goto P_0c0a0bbc;
case 0x0c0a0bbeu: goto P_0c0a0bbe;
case 0x0c0a0bc0u: goto P_0c0a0bc0;
case 0x0c0a0bc2u: goto P_0c0a0bc2;
case 0x0c0a0bc4u: goto P_0c0a0bc4;
case 0x0c0a0bc6u: goto P_0c0a0bc6;
case 0x0c0a0bc8u: goto P_0c0a0bc8;
case 0x0c0a0bcau: goto P_0c0a0bca;
case 0x0c0a0bccu: goto P_0c0a0bcc;
case 0x0c0a0bceu: goto P_0c0a0bce;
case 0x0c0a0bd0u: goto P_0c0a0bd0;
case 0x0c0a0bd2u: goto P_0c0a0bd2;
case 0x0c0a0bd4u: goto P_0c0a0bd4;
case 0x0c0a0bd6u: goto P_0c0a0bd6;
case 0x0c0a0bd8u: goto P_0c0a0bd8;
case 0x0c0a0bdau: goto P_0c0a0bda;
case 0x0c0a0bdcu: goto P_0c0a0bdc;
case 0x0c0a0bdeu: goto P_0c0a0bde;
case 0x0c0a0be0u: goto P_0c0a0be0;
case 0x0c0a0be2u: goto P_0c0a0be2;
case 0x0c0a0be4u: goto P_0c0a0be4;
case 0x0c0a0be6u: goto P_0c0a0be6;
case 0x0c0a0be8u: goto P_0c0a0be8;
case 0x0c0a0beau: goto P_0c0a0bea;
case 0x0c0a0becu: goto P_0c0a0bec;
case 0x0c0a0beeu: goto P_0c0a0bee;
case 0x0c0a0bf0u: goto P_0c0a0bf0;
case 0x0c0a0bf2u: goto P_0c0a0bf2;
case 0x0c0a0bf4u: goto P_0c0a0bf4;
case 0x0c0a0bf6u: goto P_0c0a0bf6;
case 0x0c0a0bf8u: goto P_0c0a0bf8;
case 0x0c0a0bfau: goto P_0c0a0bfa;
case 0x0c0a0bfcu: goto P_0c0a0bfc;
case 0x0c0a0bfeu: goto P_0c0a0bfe;
case 0x0c0a0c00u: goto P_0c0a0c00;
case 0x0c0a0c02u: goto P_0c0a0c02;
case 0x0c0a0c04u: goto P_0c0a0c04;
case 0x0c0a0c06u: goto P_0c0a0c06;
case 0x0c0a0c08u: goto P_0c0a0c08;
case 0x0c0a0c0au: goto P_0c0a0c0a;
case 0x0c0a0c0cu: goto P_0c0a0c0c;
case 0x0c0a0c0eu: goto P_0c0a0c0e;
case 0x0c0a0c10u: goto P_0c0a0c10;
case 0x0c0a0c12u: goto P_0c0a0c12;
case 0x0c0a0c14u: goto P_0c0a0c14;
case 0x0c0a0c16u: goto P_0c0a0c16;
case 0x0c0a0c18u: goto P_0c0a0c18;
case 0x0c0a0c1au: goto P_0c0a0c1a;
case 0x0c0a0c1cu: goto P_0c0a0c1c;
case 0x0c0a0c1eu: goto P_0c0a0c1e;
case 0x0c0a0c20u: goto P_0c0a0c20;
case 0x0c0a0c22u: goto P_0c0a0c22;
case 0x0c0a0c24u: goto P_0c0a0c24;
case 0x0c0a0c26u: goto P_0c0a0c26;
case 0x0c0a0c28u: goto P_0c0a0c28;
case 0x0c0a0c2au: goto P_0c0a0c2a;
case 0x0c0a0c2cu: goto P_0c0a0c2c;
case 0x0c0a0c2eu: goto P_0c0a0c2e;
case 0x0c0a0c30u: goto P_0c0a0c30;
case 0x0c0a0c32u: goto P_0c0a0c32;
case 0x0c0a0c34u: goto P_0c0a0c34;
case 0x0c0a0c36u: goto P_0c0a0c36;
case 0x0c0a0c38u: goto P_0c0a0c38;
case 0x0c0a0c3au: goto P_0c0a0c3a;
case 0x0c0a0c3cu: goto P_0c0a0c3c;
case 0x0c0a0c3eu: goto P_0c0a0c3e;
case 0x0c0a0c40u: goto P_0c0a0c40;
case 0x0c0a0c42u: goto P_0c0a0c42;
case 0x0c0a0c44u: goto P_0c0a0c44;
case 0x0c0a0c46u: goto P_0c0a0c46;
case 0x0c0a0c48u: goto P_0c0a0c48;
case 0x0c0a0c4au: goto P_0c0a0c4a;
case 0x0c0a0c4cu: goto P_0c0a0c4c;
case 0x0c0a0c4eu: goto P_0c0a0c4e;
case 0x0c0a0c50u: goto P_0c0a0c50;
case 0x0c0a0c52u: goto P_0c0a0c52;
case 0x0c0a0c54u: goto P_0c0a0c54;
case 0x0c0a0c56u: goto P_0c0a0c56;
case 0x0c0a0c58u: goto P_0c0a0c58;
case 0x0c0a0c5au: goto P_0c0a0c5a;
case 0x0c0a0c5cu: goto P_0c0a0c5c;
case 0x0c0a0c5eu: goto P_0c0a0c5e;
case 0x0c0a0c60u: goto P_0c0a0c60;
case 0x0c0a0c62u: goto P_0c0a0c62;
case 0x0c0a0c64u: goto P_0c0a0c64;
case 0x0c0a0c66u: goto P_0c0a0c66;
case 0x0c0a0c68u: goto P_0c0a0c68;
case 0x0c0a0c6au: goto P_0c0a0c6a;
case 0x0c0a0ca0u: goto P_0c0a0ca0;
case 0x0c0a0ca2u: goto P_0c0a0ca2;
case 0x0c0a0ca4u: goto P_0c0a0ca4;
case 0x0c0a0ca6u: goto P_0c0a0ca6;
case 0x0c0a0ca8u: goto P_0c0a0ca8;
case 0x0c0a0caau: goto P_0c0a0caa;
case 0x0c0a0cacu: goto P_0c0a0cac;
case 0x0c0a0caeu: goto P_0c0a0cae;
case 0x0c0a0cb0u: goto P_0c0a0cb0;
case 0x0c0a0cb2u: goto P_0c0a0cb2;
case 0x0c0a0cb4u: goto P_0c0a0cb4;
case 0x0c0a0cb6u: goto P_0c0a0cb6;
case 0x0c0a0cb8u: goto P_0c0a0cb8;
case 0x0c0a0cbau: goto P_0c0a0cba;
case 0x0c0a0cbcu: goto P_0c0a0cbc;
case 0x0c0a0cbeu: goto P_0c0a0cbe;
case 0x0c0a0cc0u: goto P_0c0a0cc0;
case 0x0c0a0cc2u: goto P_0c0a0cc2;
case 0x0c0a0cc4u: goto P_0c0a0cc4;
case 0x0c0a0cc6u: goto P_0c0a0cc6;
case 0x0c0a0cc8u: goto P_0c0a0cc8;
case 0x0c0a0ccau: goto P_0c0a0cca;
case 0x0c0a0cccu: goto P_0c0a0ccc;
case 0x0c0a0cceu: goto P_0c0a0cce;
case 0x0c0a0cd0u: goto P_0c0a0cd0;
case 0x0c0a0cd2u: goto P_0c0a0cd2;
case 0x0c0a0cd4u: goto P_0c0a0cd4;
case 0x0c0a0cd6u: goto P_0c0a0cd6;
case 0x0c0a0cd8u: goto P_0c0a0cd8;
case 0x0c0a0cdau: goto P_0c0a0cda;
case 0x0c0a0cdcu: goto P_0c0a0cdc;
case 0x0c0a0cdeu: goto P_0c0a0cde;
case 0x0c0a0ce0u: goto P_0c0a0ce0;
case 0x0c0a0ce2u: goto P_0c0a0ce2;
case 0x0c0a0ce4u: goto P_0c0a0ce4;
case 0x0c0a0ce6u: goto P_0c0a0ce6;
case 0x0c0a0ce8u: goto P_0c0a0ce8;
case 0x0c0a0ceau: goto P_0c0a0cea;
case 0x0c0a0cecu: goto P_0c0a0cec;
case 0x0c0a0ceeu: goto P_0c0a0cee;
case 0x0c0a0cf0u: goto P_0c0a0cf0;
case 0x0c0a0cf2u: goto P_0c0a0cf2;
case 0x0c0a0cf4u: goto P_0c0a0cf4;
case 0x0c0a0cf6u: goto P_0c0a0cf6;
case 0x0c0a0cf8u: goto P_0c0a0cf8;
case 0x0c0a0cfau: goto P_0c0a0cfa;
case 0x0c0a0cfcu: goto P_0c0a0cfc;
case 0x0c0a0cfeu: goto P_0c0a0cfe;
case 0x0c0a0d00u: goto P_0c0a0d00;
case 0x0c0a0d02u: goto P_0c0a0d02;
case 0x0c0a0d04u: goto P_0c0a0d04;
case 0x0c0a0d06u: goto P_0c0a0d06;
case 0x0c0a0d08u: goto P_0c0a0d08;
case 0x0c0a0d0au: goto P_0c0a0d0a;
case 0x0c0a0d0cu: goto P_0c0a0d0c;
case 0x0c0a0d0eu: goto P_0c0a0d0e;
case 0x0c0a0d10u: goto P_0c0a0d10;
case 0x0c0a0d12u: goto P_0c0a0d12;
case 0x0c0a0d14u: goto P_0c0a0d14;
case 0x0c0a0d16u: goto P_0c0a0d16;
case 0x0c0a0d18u: goto P_0c0a0d18;
case 0x0c0a0d1au: goto P_0c0a0d1a;
case 0x0c0a0d1cu: goto P_0c0a0d1c;
case 0x0c0a0d1eu: goto P_0c0a0d1e;
case 0x0c0a0d20u: goto P_0c0a0d20;
case 0x0c0a0d22u: goto P_0c0a0d22;
case 0x0c0a0d24u: goto P_0c0a0d24;
case 0x0c0a0d26u: goto P_0c0a0d26;
case 0x0c0a0d28u: goto P_0c0a0d28;
case 0x0c0a0d2au: goto P_0c0a0d2a;
case 0x0c0a0d2cu: goto P_0c0a0d2c;
case 0x0c0a0d2eu: goto P_0c0a0d2e;
case 0x0c0a0d30u: goto P_0c0a0d30;
default: return vf3_matrix_family(target,s,ram);
}
P_0c0a07e4: /* original 2fe6, guest PC 0x0c0a07e4 */
if(!s->budget--) { s->failed_pc=0x0c0a07e4u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a07e6;
P_0c0a07e6: /* original 2fd6, guest PC 0x0c0a07e6 */
if(!s->budget--) { s->failed_pc=0x0c0a07e6u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a07e8;
P_0c0a07e8: /* original 2fc6, guest PC 0x0c0a07e8 */
if(!s->budget--) { s->failed_pc=0x0c0a07e8u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a07ea;
P_0c0a07ea: /* original 2fb6, guest PC 0x0c0a07ea */
if(!s->budget--) { s->failed_pc=0x0c0a07eau; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a07ec;
P_0c0a07ec: /* original 2fa6, guest PC 0x0c0a07ec */
if(!s->budget--) { s->failed_pc=0x0c0a07ecu; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a07ee;
P_0c0a07ee: /* original 2f96, guest PC 0x0c0a07ee */
if(!s->budget--) { s->failed_pc=0x0c0a07eeu; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a07f0;
P_0c0a07f0: /* original 2f86, guest PC 0x0c0a07f0 */
if(!s->budget--) { s->failed_pc=0x0c0a07f0u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a07f2;
P_0c0a07f2: /* original fffb, guest PC 0x0c0a07f2 */
if(!s->budget--) { s->failed_pc=0x0c0a07f2u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c0a07f4;
P_0c0a07f4: /* original ffeb, guest PC 0x0c0a07f4 */
if(!s->budget--) { s->failed_pc=0x0c0a07f4u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,14,r[15]);
goto P_0c0a07f6;
P_0c0a07f6: /* original ffdb, guest PC 0x0c0a07f6 */
if(!s->budget--) { s->failed_pc=0x0c0a07f6u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,13,r[15]);
goto P_0c0a07f8;
P_0c0a07f8: /* original ffcb, guest PC 0x0c0a07f8 */
if(!s->budget--) { s->failed_pc=0x0c0a07f8u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,12,r[15]);
goto P_0c0a07fa;
P_0c0a07fa: /* original 4f22, guest PC 0x0c0a07fa */
if(!s->budget--) { s->failed_pc=0x0c0a07fau; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0a07fc;
P_0c0a07fc: /* original 7fe8, guest PC 0x0c0a07fc */
if(!s->budget--) { s->failed_pc=0x0c0a07fcu; return 0; }
r[15]+=0xffffffe8u;
goto P_0c0a07fe;
P_0c0a07fe: /* original 2f42, guest PC 0x0c0a07fe */
if(!s->budget--) { s->failed_pc=0x0c0a07feu; return 0; }
write(ram,r[15],r[4],4);
goto P_0c0a0800;
P_0c0a0800: /* original d311, guest PC 0x0c0a0800 */
if(!s->budget--) { s->failed_pc=0x0c0a0800u; return 0; }
r[3]=read(ram,0x0c0a0848u,4);
goto P_0c0a0802;
P_0c0a0802: /* original 1f33, guest PC 0x0c0a0802 */
if(!s->budget--) { s->failed_pc=0x0c0a0802u; return 0; }
write(ram,r[15]+12,r[3],4);
goto P_0c0a0804;
P_0c0a0804: /* original d313, guest PC 0x0c0a0804 */
if(!s->budget--) { s->failed_pc=0x0c0a0804u; return 0; }
r[3]=read(ram,0x0c0a0854u,4);
goto P_0c0a0806;
P_0c0a0806: /* original 430b, guest PC 0x0c0a0806 */
if(!s->budget--) { s->failed_pc=0x0c0a0806u; return 0; }
target=r[3];
r[16]=code_base|0x0c0a080au;
r[4]=0x00000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a080au) { target=s->pc; goto dispatch; }
goto P_0c0a080a;
P_0c0a0808: /* original e400, guest PC 0x0c0a0808 */
if(!s->budget--) { s->failed_pc=0x0c0a0808u; return 0; }
r[4]=0x00000000u;
goto P_0c0a080a;
P_0c0a080a: /* original 9019, guest PC 0x0c0a080a */
if(!s->budget--) { s->failed_pc=0x0c0a080au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a0840u,2);
goto P_0c0a080c;
P_0c0a080c: /* original 52f3, guest PC 0x0c0a080c */
if(!s->budget--) { s->failed_pc=0x0c0a080cu; return 0; }
r[2]=read(ram,r[15]+12,4);
goto P_0c0a080e;
P_0c0a080e: /* original d412, guest PC 0x0c0a080e */
if(!s->budget--) { s->failed_pc=0x0c0a080eu; return 0; }
r[4]=read(ram,0x0c0a0858u,4);
goto P_0c0a0810;
P_0c0a0810: /* original 032c, guest PC 0x0c0a0810 */
if(!s->budget--) { s->failed_pc=0x0c0a0810u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[2]+r[0],1);
goto P_0c0a0812;
P_0c0a0812: /* original 2338, guest PC 0x0c0a0812 */
if(!s->budget--) { s->failed_pc=0x0c0a0812u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c0a0814;
P_0c0a0814: /* original 8f03, guest PC 0x0c0a0814 */
if(!s->budget--) { s->failed_pc=0x0c0a0814u; return 0; }
cond=r[17]&1u;
r[0]=0x00000048u;
if(!cond) { goto P_0c0a081e; }
goto P_0c0a0818;
P_0c0a0816: /* original e048, guest PC 0x0c0a0816 */
if(!s->budget--) { s->failed_pc=0x0c0a0816u; return 0; }
r[0]=0x00000048u;
goto P_0c0a0818;
P_0c0a0818: /* original 5545, guest PC 0x0c0a0818 */
if(!s->budget--) { s->failed_pc=0x0c0a0818u; return 0; }
r[5]=read(ram,r[4]+20,4);
goto P_0c0a081a;
P_0c0a081a: /* original a002, guest PC 0x0c0a081a */
if(!s->budget--) { s->failed_pc=0x0c0a081au; return 0; }
r[6]=read(ram,r[4]+16,4);
goto P_0c0a0822;
P_0c0a081c: /* original 5644, guest PC 0x0c0a081c */
if(!s->budget--) { s->failed_pc=0x0c0a081cu; return 0; }
r[6]=read(ram,r[4]+16,4);
goto P_0c0a081e;
P_0c0a081e: /* original 5645, guest PC 0x0c0a081e */
if(!s->budget--) { s->failed_pc=0x0c0a081eu; return 0; }
r[6]=read(ram,r[4]+20,4);
goto P_0c0a0820;
P_0c0a0820: /* original 5544, guest PC 0x0c0a0820 */
if(!s->budget--) { s->failed_pc=0x0c0a0820u; return 0; }
r[5]=read(ram,r[4]+16,4);
goto P_0c0a0822;
P_0c0a0822: /* original 930e, guest PC 0x0c0a0822 */
if(!s->budget--) { s->failed_pc=0x0c0a0822u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a0842u,2);
goto P_0c0a0824;
P_0c0a0824: /* original 076e, guest PC 0x0c0a0824 */
if(!s->budget--) { s->failed_pc=0x0c0a0824u; return 0; }
r[7]=read(ram,r[6]+r[0],4);
goto P_0c0a0826;
P_0c0a0826: /* original 2738, guest PC 0x0c0a0826 */
if(!s->budget--) { s->failed_pc=0x0c0a0826u; return 0; }
r[17]=(r[17]&~1u)|(((r[7]&r[3])==0)!=0);
goto P_0c0a0828;
P_0c0a0828: /* original 8b18, guest PC 0x0c0a0828 */
if(!s->budget--) { s->failed_pc=0x0c0a0828u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a085c; }
goto P_0c0a082a;
P_0c0a082a: /* original 900b, guest PC 0x0c0a082a */
if(!s->budget--) { s->failed_pc=0x0c0a082au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a0844u,2);
goto P_0c0a082c;
P_0c0a082c: /* original 065d, guest PC 0x0c0a082c */
if(!s->budget--) { s->failed_pc=0x0c0a082cu; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,r[5]+r[0],2);
goto P_0c0a082e;
P_0c0a082e: /* original 855f, guest PC 0x0c0a082e */
if(!s->budget--) { s->failed_pc=0x0c0a082eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[5]+30,2);
goto P_0c0a0830;
P_0c0a0830: /* original 666d, guest PC 0x0c0a0830 */
if(!s->budget--) { s->failed_pc=0x0c0a0830u; return 0; }
r[6]=r[6]&65535u;
goto P_0c0a0832;
P_0c0a0832: /* original 6a0d, guest PC 0x0c0a0832 */
if(!s->budget--) { s->failed_pc=0x0c0a0832u; return 0; }
r[10]=r[0]&65535u;
goto P_0c0a0834;
P_0c0a0834: /* original a014, guest PC 0x0c0a0834 */
if(!s->budget--) { s->failed_pc=0x0c0a0834u; return 0; }
r[10]+=r[6];
goto P_0c0a0860;
P_0c0a0836: /* original 3a6c, guest PC 0x0c0a0836 */
if(!s->budget--) { s->failed_pc=0x0c0a0836u; return 0; }
r[10]+=r[6];
if(!vf3_matrix_family(0x0c0a0838u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0a0838u; return 0; } return 1;
P_0c0a085c: /* original 856f, guest PC 0x0c0a085c */
if(!s->budget--) { s->failed_pc=0x0c0a085cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[6]+30,2);
goto P_0c0a085e;
P_0c0a085e: /* original 6a0d, guest PC 0x0c0a085e */
if(!s->budget--) { s->failed_pc=0x0c0a085eu; return 0; }
r[10]=r[0]&65535u;
goto P_0c0a0860;
P_0c0a0860: /* original e044, guest PC 0x0c0a0860 */
if(!s->budget--) { s->failed_pc=0x0c0a0860u; return 0; }
r[0]=0x00000044u;
goto P_0c0a0862;
P_0c0a0862: /* original 92b9, guest PC 0x0c0a0862 */
if(!s->budget--) { s->failed_pc=0x0c0a0862u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a09d8u,2);
goto P_0c0a0864;
P_0c0a0864: /* original 044e, guest PC 0x0c0a0864 */
if(!s->budget--) { s->failed_pc=0x0c0a0864u; return 0; }
r[4]=read(ram,r[4]+r[0],4);
goto P_0c0a0866;
P_0c0a0866: /* original e912, guest PC 0x0c0a0866 */
if(!s->budget--) { s->failed_pc=0x0c0a0866u; return 0; }
r[9]=0x00000012u;
goto P_0c0a0868;
P_0c0a0868: /* original 63f2, guest PC 0x0c0a0868 */
if(!s->budget--) { s->failed_pc=0x0c0a0868u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c0a086a;
P_0c0a086a: /* original 90b4, guest PC 0x0c0a086a */
if(!s->budget--) { s->failed_pc=0x0c0a086au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a09d6u,2);
goto P_0c0a086c;
P_0c0a086c: /* original 323c, guest PC 0x0c0a086c */
if(!s->budget--) { s->failed_pc=0x0c0a086cu; return 0; }
r[2]+=r[3];
goto P_0c0a086e;
P_0c0a086e: /* original db5f, guest PC 0x0c0a086e */
if(!s->budget--) { s->failed_pc=0x0c0a086eu; return 0; }
r[11]=read(ram,0x0c0a09ecu,4);
goto P_0c0a0870;
P_0c0a0870: /* original 0d4e, guest PC 0x0c0a0870 */
if(!s->budget--) { s->failed_pc=0x0c0a0870u; return 0; }
r[13]=read(ram,r[4]+r[0],4);
goto P_0c0a0872;
P_0c0a0872: /* original d85f, guest PC 0x0c0a0872 */
if(!s->budget--) { s->failed_pc=0x0c0a0872u; return 0; }
r[8]=read(ram,0x0c0a09f0u,4);
goto P_0c0a0874;
P_0c0a0874: /* original 1f22, guest PC 0x0c0a0874 */
if(!s->budget--) { s->failed_pc=0x0c0a0874u; return 0; }
write(ram,r[15]+8,r[2],4);
goto P_0c0a0876;
P_0c0a0876: /* original e004, guest PC 0x0c0a0876 */
if(!s->budget--) { s->failed_pc=0x0c0a0876u; return 0; }
r[0]=0x00000004u;
goto P_0c0a0878;
P_0c0a0878: /* original ff86, guest PC 0x0c0a0878 */
if(!s->budget--) { s->failed_pc=0x0c0a0878u; return 0; }
vf3_matrix_load(s,ram,15,r[8]+r[0]);
goto P_0c0a087a;
P_0c0a087a: /* original 8488, guest PC 0x0c0a087a */
if(!s->budget--) { s->failed_pc=0x0c0a087au; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[8]+8,1);
goto P_0c0a087c;
P_0c0a087c: /* original 8801, guest PC 0x0c0a087c */
if(!s->budget--) { s->failed_pc=0x0c0a087cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c0a087e;
P_0c0a087e: /* original 8901, guest PC 0x0c0a087e */
if(!s->budget--) { s->failed_pc=0x0c0a087eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a0884; }
goto P_0c0a0880;
P_0c0a0880: /* original a11c, guest PC 0x0c0a0880 */
if(!s->budget--) { s->failed_pc=0x0c0a0880u; return 0; }
goto P_0c0a0abc;
P_0c0a0882: /* original 0009, guest PC 0x0c0a0882 */
if(!s->budget--) { s->failed_pc=0x0c0a0882u; return 0; }
goto P_0c0a0884;
P_0c0a0884: /* original 9ea9, guest PC 0x0c0a0884 */
if(!s->budget--) { s->failed_pc=0x0c0a0884u; return 0; }
r[14]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a09dau,2);
goto P_0c0a0886;
P_0c0a0886: /* original 2fd2, guest PC 0x0c0a0886 */
if(!s->budget--) { s->failed_pc=0x0c0a0886u; return 0; }
write(ram,r[15],r[13],4);
goto P_0c0a0888;
P_0c0a0888: /* original 55f2, guest PC 0x0c0a0888 */
if(!s->budget--) { s->failed_pc=0x0c0a0888u; return 0; }
r[5]=read(ram,r[15]+8,4);
goto P_0c0a088a;
P_0c0a088a: /* original 3edc, guest PC 0x0c0a088a */
if(!s->budget--) { s->failed_pc=0x0c0a088au; return 0; }
r[14]+=r[13];
goto P_0c0a088c;
P_0c0a088c: /* original d359, guest PC 0x0c0a088c */
if(!s->budget--) { s->failed_pc=0x0c0a088cu; return 0; }
r[3]=read(ram,0x0c0a09f4u,4);
goto P_0c0a088e;
P_0c0a088e: /* original 64e3, guest PC 0x0c0a088e */
if(!s->budget--) { s->failed_pc=0x0c0a088eu; return 0; }
r[4]=r[14];
goto P_0c0a0890;
P_0c0a0890: /* original 430b, guest PC 0x0c0a0890 */
if(!s->budget--) { s->failed_pc=0x0c0a0890u; return 0; }
target=r[3];
r[16]=code_base|0x0c0a0894u;
r[4]+=0x00000010u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a0894u) { target=s->pc; goto dispatch; }
goto P_0c0a0894;
P_0c0a0892: /* original 7410, guest PC 0x0c0a0892 */
if(!s->budget--) { s->failed_pc=0x0c0a0892u; return 0; }
r[4]+=0x00000010u;
goto P_0c0a0894;
P_0c0a0894: /* original c758, guest PC 0x0c0a0894 */
if(!s->budget--) { s->failed_pc=0x0c0a0894u; return 0; }
r[0]=code_base|0x000a09f8u;
goto P_0c0a0896;
P_0c0a0896: /* original fe9d, guest PC 0x0c0a0896 */
if(!s->budget--) { s->failed_pc=0x0c0a0896u; return 0; }
fr[14]=0x3f800000u;
goto P_0c0a0898;
P_0c0a0898: /* original f508, guest PC 0x0c0a0898 */
if(!s->budget--) { s->failed_pc=0x0c0a0898u; return 0; }
vf3_matrix_load(s,ram,5,r[0]);
goto P_0c0a089a;
P_0c0a089a: /* original c758, guest PC 0x0c0a089a */
if(!s->budget--) { s->failed_pc=0x0c0a089au; return 0; }
r[0]=code_base|0x000a09fcu;
goto P_0c0a089c;
P_0c0a089c: /* original f408, guest PC 0x0c0a089c */
if(!s->budget--) { s->failed_pc=0x0c0a089cu; return 0; }
vf3_matrix_load(s,ram,4,r[0]);
goto P_0c0a089e;
P_0c0a089e: /* original c758, guest PC 0x0c0a089e */
if(!s->budget--) { s->failed_pc=0x0c0a089eu; return 0; }
r[0]=code_base|0x000a0a00u;
goto P_0c0a08a0;
P_0c0a08a0: /* original f5f2, guest PC 0x0c0a08a0 */
if(!s->budget--) { s->failed_pc=0x0c0a08a0u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[15],r[18],'*');
goto P_0c0a08a2;
P_0c0a08a2: /* original f608, guest PC 0x0c0a08a2 */
if(!s->budget--) { s->failed_pc=0x0c0a08a2u; return 0; }
vf3_matrix_load(s,ram,6,r[0]);
goto P_0c0a08a4;
P_0c0a08a4: /* original f4f2, guest PC 0x0c0a08a4 */
if(!s->budget--) { s->failed_pc=0x0c0a08a4u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[15],r[18],'*');
goto P_0c0a08a6;
P_0c0a08a6: /* original c757, guest PC 0x0c0a08a6 */
if(!s->budget--) { s->failed_pc=0x0c0a08a6u; return 0; }
r[0]=code_base|0x000a0a04u;
goto P_0c0a08a8;
P_0c0a08a8: /* original f6f2, guest PC 0x0c0a08a8 */
if(!s->budget--) { s->failed_pc=0x0c0a08a8u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[15],r[18],'*');
goto P_0c0a08aa;
P_0c0a08aa: /* original f808, guest PC 0x0c0a08aa */
if(!s->budget--) { s->failed_pc=0x0c0a08aau; return 0; }
vf3_matrix_load(s,ram,8,r[0]);
goto P_0c0a08ac;
P_0c0a08ac: /* original 53f3, guest PC 0x0c0a08ac */
if(!s->budget--) { s->failed_pc=0x0c0a08acu; return 0; }
r[3]=read(ram,r[15]+12,4);
goto P_0c0a08ae;
P_0c0a08ae: /* original c756, guest PC 0x0c0a08ae */
if(!s->budget--) { s->failed_pc=0x0c0a08aeu; return 0; }
r[0]=code_base|0x000a0a08u;
goto P_0c0a08b0;
P_0c0a08b0: /* original f35c, guest PC 0x0c0a08b0 */
if(!s->budget--) { s->failed_pc=0x0c0a08b0u; return 0; }
vf3_matrix_move(s,3,5);
goto P_0c0a08b2;
P_0c0a08b2: /* original f5ec, guest PC 0x0c0a08b2 */
if(!s->budget--) { s->failed_pc=0x0c0a08b2u; return 0; }
vf3_matrix_move(s,5,14);
goto P_0c0a08b4;
P_0c0a08b4: /* original f533, guest PC 0x0c0a08b4 */
if(!s->budget--) { s->failed_pc=0x0c0a08b4u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[3],r[18],'/');
goto P_0c0a08b6;
P_0c0a08b6: /* original f34c, guest PC 0x0c0a08b6 */
if(!s->budget--) { s->failed_pc=0x0c0a08b6u; return 0; }
vf3_matrix_move(s,3,4);
goto P_0c0a08b8;
P_0c0a08b8: /* original f4ec, guest PC 0x0c0a08b8 */
if(!s->budget--) { s->failed_pc=0x0c0a08b8u; return 0; }
vf3_matrix_move(s,4,14);
goto P_0c0a08ba;
P_0c0a08ba: /* original f433, guest PC 0x0c0a08ba */
if(!s->budget--) { s->failed_pc=0x0c0a08bau; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'/');
goto P_0c0a08bc;
P_0c0a08bc: /* original f36c, guest PC 0x0c0a08bc */
if(!s->budget--) { s->failed_pc=0x0c0a08bcu; return 0; }
vf3_matrix_move(s,3,6);
goto P_0c0a08be;
P_0c0a08be: /* original f6ec, guest PC 0x0c0a08be */
if(!s->budget--) { s->failed_pc=0x0c0a08beu; return 0; }
vf3_matrix_move(s,6,14);
goto P_0c0a08c0;
P_0c0a08c0: /* original f633, guest PC 0x0c0a08c0 */
if(!s->budget--) { s->failed_pc=0x0c0a08c0u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[3],r[18],'/');
goto P_0c0a08c2;
P_0c0a08c2: /* original fb08, guest PC 0x0c0a08c2 */
if(!s->budget--) { s->failed_pc=0x0c0a08c2u; return 0; }
vf3_matrix_load(s,ram,11,r[0]);
goto P_0c0a08c4;
P_0c0a08c4: /* original e004, guest PC 0x0c0a08c4 */
if(!s->budget--) { s->failed_pc=0x0c0a08c4u; return 0; }
r[0]=0x00000004u;
goto P_0c0a08c6;
P_0c0a08c6: /* original fa38, guest PC 0x0c0a08c6 */
if(!s->budget--) { s->failed_pc=0x0c0a08c6u; return 0; }
vf3_matrix_load(s,ram,10,r[3]);
goto P_0c0a08c8;
P_0c0a08c8: /* original f78d, guest PC 0x0c0a08c8 */
if(!s->budget--) { s->failed_pc=0x0c0a08c8u; return 0; }
fr[7]=0;
goto P_0c0a08ca;
P_0c0a08ca: /* original f98c, guest PC 0x0c0a08ca */
if(!s->budget--) { s->failed_pc=0x0c0a08cau; return 0; }
vf3_matrix_move(s,9,8);
goto P_0c0a08cc;
P_0c0a08cc: /* original fa4d, guest PC 0x0c0a08cc */
if(!s->budget--) { s->failed_pc=0x0c0a08ccu; return 0; }
fr[10]^=0x80000000u;
goto P_0c0a08ce;
P_0c0a08ce: /* original feba, guest PC 0x0c0a08ce */
if(!s->budget--) { s->failed_pc=0x0c0a08ceu; return 0; }
vf3_matrix_store(s,ram,11,r[14]);
goto P_0c0a08d0;
P_0c0a08d0: /* original fe57, guest PC 0x0c0a08d0 */
if(!s->budget--) { s->failed_pc=0x0c0a08d0u; return 0; }
vf3_matrix_store(s,ram,5,r[14]+r[0]);
goto P_0c0a08d2;
P_0c0a08d2: /* original e008, guest PC 0x0c0a08d2 */
if(!s->budget--) { s->failed_pc=0x0c0a08d2u; return 0; }
r[0]=0x00000008u;
goto P_0c0a08d4;
P_0c0a08d4: /* original fe47, guest PC 0x0c0a08d4 */
if(!s->budget--) { s->failed_pc=0x0c0a08d4u; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c0a08d6;
P_0c0a08d6: /* original e00c, guest PC 0x0c0a08d6 */
if(!s->budget--) { s->failed_pc=0x0c0a08d6u; return 0; }
r[0]=0x0000000cu;
goto P_0c0a08d8;
P_0c0a08d8: /* original f64d, guest PC 0x0c0a08d8 */
if(!s->budget--) { s->failed_pc=0x0c0a08d8u; return 0; }
fr[6]^=0x80000000u;
goto P_0c0a08da;
P_0c0a08da: /* original 64af, guest PC 0x0c0a08da */
if(!s->budget--) { s->failed_pc=0x0c0a08dau; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)r[10];
goto P_0c0a08dc;
P_0c0a08dc: /* original fe67, guest PC 0x0c0a08dc */
if(!s->budget--) { s->failed_pc=0x0c0a08dcu; return 0; }
vf3_matrix_store(s,ram,6,r[14]+r[0]);
goto P_0c0a08de;
P_0c0a08de: /* original e068, guest PC 0x0c0a08de */
if(!s->budget--) { s->failed_pc=0x0c0a08deu; return 0; }
r[0]=0x00000068u;
goto P_0c0a08e0;
P_0c0a08e0: /* original fe77, guest PC 0x0c0a08e0 */
if(!s->budget--) { s->failed_pc=0x0c0a08e0u; return 0; }
vf3_matrix_store(s,ram,7,r[14]+r[0]);
goto P_0c0a08e2;
P_0c0a08e2: /* original e06c, guest PC 0x0c0a08e2 */
if(!s->budget--) { s->failed_pc=0x0c0a08e2u; return 0; }
r[0]=0x0000006cu;
goto P_0c0a08e4;
P_0c0a08e4: /* original fea7, guest PC 0x0c0a08e4 */
if(!s->budget--) { s->failed_pc=0x0c0a08e4u; return 0; }
vf3_matrix_store(s,ram,10,r[14]+r[0]);
goto P_0c0a08e6;
P_0c0a08e6: /* original e070, guest PC 0x0c0a08e6 */
if(!s->budget--) { s->failed_pc=0x0c0a08e6u; return 0; }
r[0]=0x00000070u;
goto P_0c0a08e8;
P_0c0a08e8: /* original fe77, guest PC 0x0c0a08e8 */
if(!s->budget--) { s->failed_pc=0x0c0a08e8u; return 0; }
vf3_matrix_store(s,ram,7,r[14]+r[0]);
goto P_0c0a08ea;
P_0c0a08ea: /* original e074, guest PC 0x0c0a08ea */
if(!s->budget--) { s->failed_pc=0x0c0a08eau; return 0; }
r[0]=0x00000074u;
goto P_0c0a08ec;
P_0c0a08ec: /* original fe97, guest PC 0x0c0a08ec */
if(!s->budget--) { s->failed_pc=0x0c0a08ecu; return 0; }
vf3_matrix_store(s,ram,9,r[14]+r[0]);
goto P_0c0a08ee;
P_0c0a08ee: /* original e078, guest PC 0x0c0a08ee */
if(!s->budget--) { s->failed_pc=0x0c0a08eeu; return 0; }
r[0]=0x00000078u;
goto P_0c0a08f0;
P_0c0a08f0: /* original fe97, guest PC 0x0c0a08f0 */
if(!s->budget--) { s->failed_pc=0x0c0a08f0u; return 0; }
vf3_matrix_store(s,ram,9,r[14]+r[0]);
goto P_0c0a08f2;
P_0c0a08f2: /* original e004, guest PC 0x0c0a08f2 */
if(!s->budget--) { s->failed_pc=0x0c0a08f2u; return 0; }
r[0]=0x00000004u;
goto P_0c0a08f4;
P_0c0a08f4: /* original f3b8, guest PC 0x0c0a08f4 */
if(!s->budget--) { s->failed_pc=0x0c0a08f4u; return 0; }
vf3_matrix_load(s,ram,3,r[11]);
goto P_0c0a08f6;
P_0c0a08f6: /* original ff37, guest PC 0x0c0a08f6 */
if(!s->budget--) { s->failed_pc=0x0c0a08f6u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0a08f8;
P_0c0a08f8: /* original e004, guest PC 0x0c0a08f8 */
if(!s->budget--) { s->failed_pc=0x0c0a08f8u; return 0; }
r[0]=0x00000004u;
goto P_0c0a08fa;
P_0c0a08fa: /* original f3b6, guest PC 0x0c0a08fa */
if(!s->budget--) { s->failed_pc=0x0c0a08fau; return 0; }
vf3_matrix_load(s,ram,3,r[11]+r[0]);
goto P_0c0a08fc;
P_0c0a08fc: /* original e014, guest PC 0x0c0a08fc */
if(!s->budget--) { s->failed_pc=0x0c0a08fcu; return 0; }
r[0]=0x00000014u;
goto P_0c0a08fe;
P_0c0a08fe: /* original ff37, guest PC 0x0c0a08fe */
if(!s->budget--) { s->failed_pc=0x0c0a08feu; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0a0900;
P_0c0a0900: /* original e008, guest PC 0x0c0a0900 */
if(!s->budget--) { s->failed_pc=0x0c0a0900u; return 0; }
r[0]=0x00000008u;
goto P_0c0a0902;
P_0c0a0902: /* original d342, guest PC 0x0c0a0902 */
if(!s->budget--) { s->failed_pc=0x0c0a0902u; return 0; }
r[3]=read(ram,0x0c0a0a0cu,4);
goto P_0c0a0904;
P_0c0a0904: /* original fdb6, guest PC 0x0c0a0904 */
if(!s->budget--) { s->failed_pc=0x0c0a0904u; return 0; }
vf3_matrix_load(s,ram,13,r[11]+r[0]);
goto P_0c0a0906;
P_0c0a0906: /* original 430b, guest PC 0x0c0a0906 */
if(!s->budget--) { s->failed_pc=0x0c0a0906u; return 0; }
target=r[3];
r[16]=code_base|0x0c0a090au;
write(ram,r[15]+16,r[4],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a090au) { target=s->pc; goto dispatch; }
goto P_0c0a090a;
P_0c0a0908: /* original 1f44, guest PC 0x0c0a0908 */
if(!s->budget--) { s->failed_pc=0x0c0a0908u; return 0; }
write(ram,r[15]+16,r[4],4);
goto P_0c0a090a;
P_0c0a090a: /* original d341, guest PC 0x0c0a090a */
if(!s->budget--) { s->failed_pc=0x0c0a090au; return 0; }
r[3]=read(ram,0x0c0a0a10u,4);
goto P_0c0a090c;
P_0c0a090c: /* original fc0c, guest PC 0x0c0a090c */
if(!s->budget--) { s->failed_pc=0x0c0a090cu; return 0; }
vf3_matrix_move(s,12,0);
goto P_0c0a090e;
P_0c0a090e: /* original 430b, guest PC 0x0c0a090e */
if(!s->budget--) { s->failed_pc=0x0c0a090eu; return 0; }
target=r[3];
r[16]=code_base|0x0c0a0912u;
r[4]=read(ram,r[15]+16,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a0912u) { target=s->pc; goto dispatch; }
goto P_0c0a0912;
P_0c0a0910: /* original 54f4, guest PC 0x0c0a0910 */
if(!s->budget--) { s->failed_pc=0x0c0a0910u; return 0; }
r[4]=read(ram,r[15]+16,4);
goto P_0c0a0912;
P_0c0a0912: /* original e004, guest PC 0x0c0a0912 */
if(!s->budget--) { s->failed_pc=0x0c0a0912u; return 0; }
r[0]=0x00000004u;
goto P_0c0a0914;
P_0c0a0914: /* original f1cc, guest PC 0x0c0a0914 */
if(!s->budget--) { s->failed_pc=0x0c0a0914u; return 0; }
vf3_matrix_move(s,1,12);
goto P_0c0a0916;
P_0c0a0916: /* original f3f6, guest PC 0x0c0a0916 */
if(!s->budget--) { s->failed_pc=0x0c0a0916u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0a0918;
P_0c0a0918: /* original f1d2, guest PC 0x0c0a0918 */
if(!s->budget--) { s->failed_pc=0x0c0a0918u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[13],r[18],'*');
goto P_0c0a091a;
P_0c0a091a: /* original f20c, guest PC 0x0c0a091a */
if(!s->budget--) { s->failed_pc=0x0c0a091au; return 0; }
vf3_matrix_move(s,2,0);
goto P_0c0a091c;
P_0c0a091c: /* original e05c, guest PC 0x0c0a091c */
if(!s->budget--) { s->failed_pc=0x0c0a091cu; return 0; }
r[0]=0x0000005cu;
goto P_0c0a091e;
P_0c0a091e: /* original f232, guest PC 0x0c0a091e */
if(!s->budget--) { s->failed_pc=0x0c0a091eu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c0a0920;
P_0c0a0920: /* original f40c, guest PC 0x0c0a0920 */
if(!s->budget--) { s->failed_pc=0x0c0a0920u; return 0; }
vf3_matrix_move(s,4,0);
goto P_0c0a0922;
P_0c0a0922: /* original f4d2, guest PC 0x0c0a0922 */
if(!s->budget--) { s->failed_pc=0x0c0a0922u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[13],r[18],'*');
goto P_0c0a0924;
P_0c0a0924: /* original f211, guest PC 0x0c0a0924 */
if(!s->budget--) { s->failed_pc=0x0c0a0924u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[1],r[18],'-');
goto P_0c0a0926;
P_0c0a0926: /* original fe27, guest PC 0x0c0a0926 */
if(!s->budget--) { s->failed_pc=0x0c0a0926u; return 0; }
vf3_matrix_store(s,ram,2,r[14]+r[0]);
goto P_0c0a0928;
P_0c0a0928: /* original e014, guest PC 0x0c0a0928 */
if(!s->budget--) { s->failed_pc=0x0c0a0928u; return 0; }
r[0]=0x00000014u;
goto P_0c0a092a;
P_0c0a092a: /* original f3f6, guest PC 0x0c0a092a */
if(!s->budget--) { s->failed_pc=0x0c0a092au; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0a092c;
P_0c0a092c: /* original e060, guest PC 0x0c0a092c */
if(!s->budget--) { s->failed_pc=0x0c0a092cu; return 0; }
r[0]=0x00000060u;
goto P_0c0a092e;
P_0c0a092e: /* original fe37, guest PC 0x0c0a092e */
if(!s->budget--) { s->failed_pc=0x0c0a092eu; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c0a0930;
P_0c0a0930: /* original e004, guest PC 0x0c0a0930 */
if(!s->budget--) { s->failed_pc=0x0c0a0930u; return 0; }
r[0]=0x00000004u;
goto P_0c0a0932;
P_0c0a0932: /* original f3f6, guest PC 0x0c0a0932 */
if(!s->budget--) { s->failed_pc=0x0c0a0932u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0a0934;
P_0c0a0934: /* original e064, guest PC 0x0c0a0934 */
if(!s->budget--) { s->failed_pc=0x0c0a0934u; return 0; }
r[0]=0x00000064u;
goto P_0c0a0936;
P_0c0a0936: /* original fc32, guest PC 0x0c0a0936 */
if(!s->budget--) { s->failed_pc=0x0c0a0936u; return 0; }
fr[12]=vf3_fpu_binary(fr[12],fr[3],r[18],'*');
goto P_0c0a0938;
P_0c0a0938: /* original fc4d, guest PC 0x0c0a0938 */
if(!s->budget--) { s->failed_pc=0x0c0a0938u; return 0; }
fr[12]^=0x80000000u;
goto P_0c0a093a;
P_0c0a093a: /* original fc41, guest PC 0x0c0a093a */
if(!s->budget--) { s->failed_pc=0x0c0a093au; return 0; }
fr[12]=vf3_fpu_binary(fr[12],fr[4],r[18],'-');
goto P_0c0a093c;
P_0c0a093c: /* original fec7, guest PC 0x0c0a093c */
if(!s->budget--) { s->failed_pc=0x0c0a093cu; return 0; }
vf3_matrix_store(s,ram,12,r[14]+r[0]);
goto P_0c0a093e;
P_0c0a093e: /* original 703c, guest PC 0x0c0a093e */
if(!s->budget--) { s->failed_pc=0x0c0a093eu; return 0; }
r[0]+=0x0000003cu;
goto P_0c0a0940;
P_0c0a0940: /* original dc34, guest PC 0x0c0a0940 */
if(!s->budget--) { s->failed_pc=0x0c0a0940u; return 0; }
r[12]=read(ram,0x0c0a0a14u,4);
goto P_0c0a0942;
P_0c0a0942: /* original 4c0b, guest PC 0x0c0a0942 */
if(!s->budget--) { s->failed_pc=0x0c0a0942u; return 0; }
target=r[12];
r[16]=code_base|0x0c0a0946u;
vf3_matrix_store(s,ram,15,r[14]+r[0]);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a0946u) { target=s->pc; goto dispatch; }
goto P_0c0a0946;
P_0c0a0944: /* original fef7, guest PC 0x0c0a0944 */
if(!s->budget--) { s->failed_pc=0x0c0a0944u; return 0; }
vf3_matrix_store(s,ram,15,r[14]+r[0]);
goto P_0c0a0946;
P_0c0a0946: /* original 914a, guest PC 0x0c0a0946 */
if(!s->budget--) { s->failed_pc=0x0c0a0946u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a09deu,2);
goto P_0c0a0948;
P_0c0a0948: /* original 4000, guest PC 0x0c0a0948 */
if(!s->budget--) { s->failed_pc=0x0c0a0948u; return 0; }
r[17]=(r[17]&~1u)|((r[0]>>31)!=0);
r[0]<<=1;
goto P_0c0a094a;
P_0c0a094a: /* original 9347, guest PC 0x0c0a094a */
if(!s->budget--) { s->failed_pc=0x0c0a094au; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a09dcu,2);
goto P_0c0a094c;
P_0c0a094c: /* original 31ec, guest PC 0x0c0a094c */
if(!s->budget--) { s->failed_pc=0x0c0a094cu; return 0; }
r[1]+=r[14];
goto P_0c0a094e;
P_0c0a094e: /* original 303c, guest PC 0x0c0a094e */
if(!s->budget--) { s->failed_pc=0x0c0a094eu; return 0; }
r[0]+=r[3];
goto P_0c0a0950;
P_0c0a0950: /* original 4c0b, guest PC 0x0c0a0950 */
if(!s->budget--) { s->failed_pc=0x0c0a0950u; return 0; }
target=r[12];
r[16]=code_base|0x0c0a0954u;
write(ram,r[1],r[0],2);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a0954u) { target=s->pc; goto dispatch; }
goto P_0c0a0954;
P_0c0a0952: /* original 2101, guest PC 0x0c0a0952 */
if(!s->budget--) { s->failed_pc=0x0c0a0952u; return 0; }
write(ram,r[1],r[0],2);
goto P_0c0a0954;
P_0c0a0954: /* original 9144, guest PC 0x0c0a0954 */
if(!s->budget--) { s->failed_pc=0x0c0a0954u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a09e0u,2);
goto P_0c0a0956;
P_0c0a0956: /* original 4000, guest PC 0x0c0a0956 */
if(!s->budget--) { s->failed_pc=0x0c0a0956u; return 0; }
r[17]=(r[17]&~1u)|((r[0]>>31)!=0);
r[0]<<=1;
goto P_0c0a0958;
P_0c0a0958: /* original 9340, guest PC 0x0c0a0958 */
if(!s->budget--) { s->failed_pc=0x0c0a0958u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a09dcu,2);
goto P_0c0a095a;
P_0c0a095a: /* original 31ec, guest PC 0x0c0a095a */
if(!s->budget--) { s->failed_pc=0x0c0a095au; return 0; }
r[1]+=r[14];
goto P_0c0a095c;
P_0c0a095c: /* original 303c, guest PC 0x0c0a095c */
if(!s->budget--) { s->failed_pc=0x0c0a095cu; return 0; }
r[0]+=r[3];
goto P_0c0a095e;
P_0c0a095e: /* original 4c0b, guest PC 0x0c0a095e */
if(!s->budget--) { s->failed_pc=0x0c0a095eu; return 0; }
target=r[12];
r[16]=code_base|0x0c0a0962u;
write(ram,r[1],r[0],2);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a0962u) { target=s->pc; goto dispatch; }
goto P_0c0a0962;
P_0c0a0960: /* original 2101, guest PC 0x0c0a0960 */
if(!s->budget--) { s->failed_pc=0x0c0a0960u; return 0; }
write(ram,r[1],r[0],2);
goto P_0c0a0962;
P_0c0a0962: /* original 913e, guest PC 0x0c0a0962 */
if(!s->budget--) { s->failed_pc=0x0c0a0962u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a09e2u,2);
goto P_0c0a0964;
P_0c0a0964: /* original 4000, guest PC 0x0c0a0964 */
if(!s->budget--) { s->failed_pc=0x0c0a0964u; return 0; }
r[17]=(r[17]&~1u)|((r[0]>>31)!=0);
r[0]<<=1;
goto P_0c0a0966;
P_0c0a0966: /* original 9339, guest PC 0x0c0a0966 */
if(!s->budget--) { s->failed_pc=0x0c0a0966u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a09dcu,2);
goto P_0c0a0968;
P_0c0a0968: /* original 31ec, guest PC 0x0c0a0968 */
if(!s->budget--) { s->failed_pc=0x0c0a0968u; return 0; }
r[1]+=r[14];
goto P_0c0a096a;
P_0c0a096a: /* original 303c, guest PC 0x0c0a096a */
if(!s->budget--) { s->failed_pc=0x0c0a096au; return 0; }
r[0]+=r[3];
goto P_0c0a096c;
P_0c0a096c: /* original 4c0b, guest PC 0x0c0a096c */
if(!s->budget--) { s->failed_pc=0x0c0a096cu; return 0; }
target=r[12];
r[16]=code_base|0x0c0a0970u;
write(ram,r[1],r[0],2);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a0970u) { target=s->pc; goto dispatch; }
goto P_0c0a0970;
P_0c0a096e: /* original 2101, guest PC 0x0c0a096e */
if(!s->budget--) { s->failed_pc=0x0c0a096eu; return 0; }
write(ram,r[1],r[0],2);
goto P_0c0a0970;
P_0c0a0970: /* original d329, guest PC 0x0c0a0970 */
if(!s->budget--) { s->failed_pc=0x0c0a0970u; return 0; }
r[3]=read(ram,0x0c0a0a18u,4);
goto P_0c0a0972;
P_0c0a0972: /* original 6103, guest PC 0x0c0a0972 */
if(!s->budget--) { s->failed_pc=0x0c0a0972u; return 0; }
r[1]=r[0];
goto P_0c0a0974;
P_0c0a0974: /* original 430b, guest PC 0x0c0a0974 */
if(!s->budget--) { s->failed_pc=0x0c0a0974u; return 0; }
target=r[3];
r[16]=code_base|0x0c0a0978u;
r[0]=0x00000018u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a0978u) { target=s->pc; goto dispatch; }
goto P_0c0a0978;
P_0c0a0976: /* original e018, guest PC 0x0c0a0976 */
if(!s->budget--) { s->failed_pc=0x0c0a0976u; return 0; }
r[0]=0x00000018u;
goto P_0c0a0978;
P_0c0a0978: /* original 9134, guest PC 0x0c0a0978 */
if(!s->budget--) { s->failed_pc=0x0c0a0978u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a09e4u,2);
goto P_0c0a097a;
P_0c0a097a: /* original 31ec, guest PC 0x0c0a097a */
if(!s->budget--) { s->failed_pc=0x0c0a097au; return 0; }
r[1]+=r[14];
goto P_0c0a097c;
P_0c0a097c: /* original 4c0b, guest PC 0x0c0a097c */
if(!s->budget--) { s->failed_pc=0x0c0a097cu; return 0; }
target=r[12];
r[16]=code_base|0x0c0a0980u;
write(ram,r[1],r[0],2);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a0980u) { target=s->pc; goto dispatch; }
goto P_0c0a0980;
P_0c0a097e: /* original 2101, guest PC 0x0c0a097e */
if(!s->budget--) { s->failed_pc=0x0c0a097eu; return 0; }
write(ram,r[1],r[0],2);
goto P_0c0a0980;
P_0c0a0980: /* original d325, guest PC 0x0c0a0980 */
if(!s->budget--) { s->failed_pc=0x0c0a0980u; return 0; }
r[3]=read(ram,0x0c0a0a18u,4);
goto P_0c0a0982;
P_0c0a0982: /* original 6103, guest PC 0x0c0a0982 */
if(!s->budget--) { s->failed_pc=0x0c0a0982u; return 0; }
r[1]=r[0];
goto P_0c0a0984;
P_0c0a0984: /* original 430b, guest PC 0x0c0a0984 */
if(!s->budget--) { s->failed_pc=0x0c0a0984u; return 0; }
target=r[3];
r[16]=code_base|0x0c0a0988u;
r[0]=0x00000018u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a0988u) { target=s->pc; goto dispatch; }
goto P_0c0a0988;
P_0c0a0986: /* original e018, guest PC 0x0c0a0986 */
if(!s->budget--) { s->failed_pc=0x0c0a0986u; return 0; }
r[0]=0x00000018u;
goto P_0c0a0988;
P_0c0a0988: /* original 912d, guest PC 0x0c0a0988 */
if(!s->budget--) { s->failed_pc=0x0c0a0988u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a09e6u,2);
goto P_0c0a098a;
P_0c0a098a: /* original 31ec, guest PC 0x0c0a098a */
if(!s->budget--) { s->failed_pc=0x0c0a098au; return 0; }
r[1]+=r[14];
goto P_0c0a098c;
P_0c0a098c: /* original 4c0b, guest PC 0x0c0a098c */
if(!s->budget--) { s->failed_pc=0x0c0a098cu; return 0; }
target=r[12];
r[16]=code_base|0x0c0a0990u;
write(ram,r[1],r[0],2);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a0990u) { target=s->pc; goto dispatch; }
goto P_0c0a0990;
P_0c0a098e: /* original 2101, guest PC 0x0c0a098e */
if(!s->budget--) { s->failed_pc=0x0c0a098eu; return 0; }
write(ram,r[1],r[0],2);
goto P_0c0a0990;
P_0c0a0990: /* original d321, guest PC 0x0c0a0990 */
if(!s->budget--) { s->failed_pc=0x0c0a0990u; return 0; }
r[3]=read(ram,0x0c0a0a18u,4);
goto P_0c0a0992;
P_0c0a0992: /* original 6103, guest PC 0x0c0a0992 */
if(!s->budget--) { s->failed_pc=0x0c0a0992u; return 0; }
r[1]=r[0];
goto P_0c0a0994;
P_0c0a0994: /* original 430b, guest PC 0x0c0a0994 */
if(!s->budget--) { s->failed_pc=0x0c0a0994u; return 0; }
target=r[3];
r[16]=code_base|0x0c0a0998u;
r[0]=0x00000018u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a0998u) { target=s->pc; goto dispatch; }
goto P_0c0a0998;
P_0c0a0996: /* original e018, guest PC 0x0c0a0996 */
if(!s->budget--) { s->failed_pc=0x0c0a0996u; return 0; }
r[0]=0x00000018u;
goto P_0c0a0998;
P_0c0a0998: /* original 9126, guest PC 0x0c0a0998 */
if(!s->budget--) { s->failed_pc=0x0c0a0998u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a09e8u,2);
goto P_0c0a099a;
P_0c0a099a: /* original 31ec, guest PC 0x0c0a099a */
if(!s->budget--) { s->failed_pc=0x0c0a099au; return 0; }
r[1]+=r[14];
goto P_0c0a099c;
P_0c0a099c: /* original 2101, guest PC 0x0c0a099c */
if(!s->budget--) { s->failed_pc=0x0c0a099cu; return 0; }
write(ram,r[1],r[0],2);
goto P_0c0a099e;
P_0c0a099e: /* original c71f, guest PC 0x0c0a099e */
if(!s->budget--) { s->failed_pc=0x0c0a099eu; return 0; }
r[0]=code_base|0x000a0a1cu;
goto P_0c0a09a0;
P_0c0a09a0: /* original f708, guest PC 0x0c0a09a0 */
if(!s->budget--) { s->failed_pc=0x0c0a09a0u; return 0; }
vf3_matrix_load(s,ram,7,r[0]);
goto P_0c0a09a2;
P_0c0a09a2: /* original c71f, guest PC 0x0c0a09a2 */
if(!s->budget--) { s->failed_pc=0x0c0a09a2u; return 0; }
r[0]=code_base|0x000a0a20u;
goto P_0c0a09a4;
P_0c0a09a4: /* original f608, guest PC 0x0c0a09a4 */
if(!s->budget--) { s->failed_pc=0x0c0a09a4u; return 0; }
vf3_matrix_load(s,ram,6,r[0]);
goto P_0c0a09a6;
P_0c0a09a6: /* original c71f, guest PC 0x0c0a09a6 */
if(!s->budget--) { s->failed_pc=0x0c0a09a6u; return 0; }
r[0]=code_base|0x000a0a24u;
goto P_0c0a09a8;
P_0c0a09a8: /* original f508, guest PC 0x0c0a09a8 */
if(!s->budget--) { s->failed_pc=0x0c0a09a8u; return 0; }
vf3_matrix_load(s,ram,5,r[0]);
goto P_0c0a09aa;
P_0c0a09aa: /* original e050, guest PC 0x0c0a09aa */
if(!s->budget--) { s->failed_pc=0x0c0a09aau; return 0; }
r[0]=0x00000050u;
goto P_0c0a09ac;
P_0c0a09ac: /* original f48d, guest PC 0x0c0a09ac */
if(!s->budget--) { s->failed_pc=0x0c0a09acu; return 0; }
fr[4]=0;
goto P_0c0a09ae;
P_0c0a09ae: /* original fe77, guest PC 0x0c0a09ae */
if(!s->budget--) { s->failed_pc=0x0c0a09aeu; return 0; }
vf3_matrix_store(s,ram,7,r[14]+r[0]);
goto P_0c0a09b0;
P_0c0a09b0: /* original e054, guest PC 0x0c0a09b0 */
if(!s->budget--) { s->failed_pc=0x0c0a09b0u; return 0; }
r[0]=0x00000054u;
goto P_0c0a09b2;
P_0c0a09b2: /* original fe67, guest PC 0x0c0a09b2 */
if(!s->budget--) { s->failed_pc=0x0c0a09b2u; return 0; }
vf3_matrix_store(s,ram,6,r[14]+r[0]);
goto P_0c0a09b4;
P_0c0a09b4: /* original e058, guest PC 0x0c0a09b4 */
if(!s->budget--) { s->failed_pc=0x0c0a09b4u; return 0; }
r[0]=0x00000058u;
goto P_0c0a09b6;
P_0c0a09b6: /* original fe57, guest PC 0x0c0a09b6 */
if(!s->budget--) { s->failed_pc=0x0c0a09b6u; return 0; }
vf3_matrix_store(s,ram,5,r[14]+r[0]);
goto P_0c0a09b8;
P_0c0a09b8: /* original e07c, guest PC 0x0c0a09b8 */
if(!s->budget--) { s->failed_pc=0x0c0a09b8u; return 0; }
r[0]=0x0000007cu;
goto P_0c0a09ba;
P_0c0a09ba: /* original fe47, guest PC 0x0c0a09ba */
if(!s->budget--) { s->failed_pc=0x0c0a09bau; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c0a09bc;
P_0c0a09bc: /* original 7004, guest PC 0x0c0a09bc */
if(!s->budget--) { s->failed_pc=0x0c0a09bcu; return 0; }
r[0]+=0x00000004u;
goto P_0c0a09be;
P_0c0a09be: /* original fe47, guest PC 0x0c0a09be */
if(!s->budget--) { s->failed_pc=0x0c0a09beu; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c0a09c0;
P_0c0a09c0: /* original 7004, guest PC 0x0c0a09c0 */
if(!s->budget--) { s->failed_pc=0x0c0a09c0u; return 0; }
r[0]+=0x00000004u;
goto P_0c0a09c2;
P_0c0a09c2: /* original fe47, guest PC 0x0c0a09c2 */
if(!s->budget--) { s->failed_pc=0x0c0a09c2u; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c0a09c4;
P_0c0a09c4: /* original 7004, guest PC 0x0c0a09c4 */
if(!s->budget--) { s->failed_pc=0x0c0a09c4u; return 0; }
r[0]+=0x00000004u;
goto P_0c0a09c6;
P_0c0a09c6: /* original fe47, guest PC 0x0c0a09c6 */
if(!s->budget--) { s->failed_pc=0x0c0a09c6u; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c0a09c8;
P_0c0a09c8: /* original 7004, guest PC 0x0c0a09c8 */
if(!s->budget--) { s->failed_pc=0x0c0a09c8u; return 0; }
r[0]+=0x00000004u;
goto P_0c0a09ca;
P_0c0a09ca: /* original fe47, guest PC 0x0c0a09ca */
if(!s->budget--) { s->failed_pc=0x0c0a09cau; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c0a09cc;
P_0c0a09cc: /* original 7004, guest PC 0x0c0a09cc */
if(!s->budget--) { s->failed_pc=0x0c0a09ccu; return 0; }
r[0]+=0x00000004u;
goto P_0c0a09ce;
P_0c0a09ce: /* original fe47, guest PC 0x0c0a09ce */
if(!s->budget--) { s->failed_pc=0x0c0a09ceu; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c0a09d0;
P_0c0a09d0: /* original 63f2, guest PC 0x0c0a09d0 */
if(!s->budget--) { s->failed_pc=0x0c0a09d0u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c0a09d2;
P_0c0a09d2: /* original a029, guest PC 0x0c0a09d2 */
if(!s->budget--) { s->failed_pc=0x0c0a09d2u; return 0; }
goto P_0c0a0a28;
P_0c0a09d4: /* original 0009, guest PC 0x0c0a09d4 */
if(!s->budget--) { s->failed_pc=0x0c0a09d4u; return 0; }
if(!vf3_matrix_family(0x0c0a09d6u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0a09d6u; return 0; } return 1;
P_0c0a0a28: /* original c741, guest PC 0x0c0a0a28 */
if(!s->budget--) { s->failed_pc=0x0c0a0a28u; return 0; }
r[0]=code_base|0x000a0b30u;
goto P_0c0a0a2a;
P_0c0a0a2a: /* original e208, guest PC 0x0c0a0a2a */
if(!s->budget--) { s->failed_pc=0x0c0a0a2au; return 0; }
r[2]=0x00000008u;
goto P_0c0a0a2c;
P_0c0a0a2c: /* original 2322, guest PC 0x0c0a0a2c */
if(!s->budget--) { s->failed_pc=0x0c0a0a2cu; return 0; }
write(ram,r[3],r[2],4);
goto P_0c0a0a2e;
P_0c0a0a2e: /* original f708, guest PC 0x0c0a0a2e */
if(!s->budget--) { s->failed_pc=0x0c0a0a2eu; return 0; }
vf3_matrix_load(s,ram,7,r[0]);
goto P_0c0a0a30;
P_0c0a0a30: /* original c740, guest PC 0x0c0a0a30 */
if(!s->budget--) { s->failed_pc=0x0c0a0a30u; return 0; }
r[0]=code_base|0x000a0b34u;
goto P_0c0a0a32;
P_0c0a0a32: /* original f508, guest PC 0x0c0a0a32 */
if(!s->budget--) { s->failed_pc=0x0c0a0a32u; return 0; }
vf3_matrix_load(s,ram,5,r[0]);
goto P_0c0a0a34;
P_0c0a0a34: /* original c740, guest PC 0x0c0a0a34 */
if(!s->budget--) { s->failed_pc=0x0c0a0a34u; return 0; }
r[0]=code_base|0x000a0b38u;
goto P_0c0a0a36;
P_0c0a0a36: /* original f608, guest PC 0x0c0a0a36 */
if(!s->budget--) { s->failed_pc=0x0c0a0a36u; return 0; }
vf3_matrix_load(s,ram,6,r[0]);
goto P_0c0a0a38;
P_0c0a0a38: /* original c740, guest PC 0x0c0a0a38 */
if(!s->budget--) { s->failed_pc=0x0c0a0a38u; return 0; }
r[0]=code_base|0x000a0b3cu;
goto P_0c0a0a3a;
P_0c0a0a3a: /* original f808, guest PC 0x0c0a0a3a */
if(!s->budget--) { s->failed_pc=0x0c0a0a3au; return 0; }
vf3_matrix_load(s,ram,8,r[0]);
goto P_0c0a0a3c;
P_0c0a0a3c: /* original c740, guest PC 0x0c0a0a3c */
if(!s->budget--) { s->failed_pc=0x0c0a0a3cu; return 0; }
r[0]=code_base|0x000a0b40u;
goto P_0c0a0a3e;
P_0c0a0a3e: /* original f408, guest PC 0x0c0a0a3e */
if(!s->budget--) { s->failed_pc=0x0c0a0a3eu; return 0; }
vf3_matrix_load(s,ram,4,r[0]);
goto P_0c0a0a40;
P_0c0a0a40: /* original f6f2, guest PC 0x0c0a0a40 */
if(!s->budget--) { s->failed_pc=0x0c0a0a40u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[15],r[18],'*');
goto P_0c0a0a42;
P_0c0a0a42: /* original 64f2, guest PC 0x0c0a0a42 */
if(!s->budget--) { s->failed_pc=0x0c0a0a42u; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c0a0a44;
P_0c0a0a44: /* original c73f, guest PC 0x0c0a0a44 */
if(!s->budget--) { s->failed_pc=0x0c0a0a44u; return 0; }
r[0]=code_base|0x000a0b44u;
goto P_0c0a0a46;
P_0c0a0a46: /* original f4f2, guest PC 0x0c0a0a46 */
if(!s->budget--) { s->failed_pc=0x0c0a0a46u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[15],r[18],'*');
goto P_0c0a0a48;
P_0c0a0a48: /* original f908, guest PC 0x0c0a0a48 */
if(!s->budget--) { s->failed_pc=0x0c0a0a48u; return 0; }
vf3_matrix_load(s,ram,9,r[0]);
goto P_0c0a0a4a;
P_0c0a0a4a: /* original f7f2, guest PC 0x0c0a0a4a */
if(!s->budget--) { s->failed_pc=0x0c0a0a4au; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[15],r[18],'*');
goto P_0c0a0a4c;
P_0c0a0a4c: /* original 7404, guest PC 0x0c0a0a4c */
if(!s->budget--) { s->failed_pc=0x0c0a0a4cu; return 0; }
r[4]+=0x00000004u;
goto P_0c0a0a4e;
P_0c0a0a4e: /* original e004, guest PC 0x0c0a0a4e */
if(!s->budget--) { s->failed_pc=0x0c0a0a4eu; return 0; }
r[0]=0x00000004u;
goto P_0c0a0a50;
P_0c0a0a50: /* original f5f2, guest PC 0x0c0a0a50 */
if(!s->budget--) { s->failed_pc=0x0c0a0a50u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[15],r[18],'*');
goto P_0c0a0a52;
P_0c0a0a52: /* original f8f2, guest PC 0x0c0a0a52 */
if(!s->budget--) { s->failed_pc=0x0c0a0a52u; return 0; }
fr[8]=vf3_fpu_binary(fr[8],fr[15],r[18],'*');
goto P_0c0a0a54;
P_0c0a0a54: /* original f9f2, guest PC 0x0c0a0a54 */
if(!s->budget--) { s->failed_pc=0x0c0a0a54u; return 0; }
fr[9]=vf3_fpu_binary(fr[9],fr[15],r[18],'*');
goto P_0c0a0a56;
P_0c0a0a56: /* original f47a, guest PC 0x0c0a0a56 */
if(!s->budget--) { s->failed_pc=0x0c0a0a56u; return 0; }
vf3_matrix_store(s,ram,7,r[4]);
goto P_0c0a0a58;
P_0c0a0a58: /* original f467, guest PC 0x0c0a0a58 */
if(!s->budget--) { s->failed_pc=0x0c0a0a58u; return 0; }
vf3_matrix_store(s,ram,6,r[4]+r[0]);
goto P_0c0a0a5a;
P_0c0a0a5a: /* original 6023, guest PC 0x0c0a0a5a */
if(!s->budget--) { s->failed_pc=0x0c0a0a5au; return 0; }
r[0]=r[2];
goto P_0c0a0a5c;
P_0c0a0a5c: /* original f447, guest PC 0x0c0a0a5c */
if(!s->budget--) { s->failed_pc=0x0c0a0a5cu; return 0; }
vf3_matrix_store(s,ram,4,r[4]+r[0]);
goto P_0c0a0a5e;
P_0c0a0a5e: /* original e004, guest PC 0x0c0a0a5e */
if(!s->budget--) { s->failed_pc=0x0c0a0a5eu; return 0; }
r[0]=0x00000004u;
goto P_0c0a0a60;
P_0c0a0a60: /* original 740c, guest PC 0x0c0a0a60 */
if(!s->budget--) { s->failed_pc=0x0c0a0a60u; return 0; }
r[4]+=0x0000000cu;
goto P_0c0a0a62;
P_0c0a0a62: /* original f47a, guest PC 0x0c0a0a62 */
if(!s->budget--) { s->failed_pc=0x0c0a0a62u; return 0; }
vf3_matrix_store(s,ram,7,r[4]);
goto P_0c0a0a64;
P_0c0a0a64: /* original f467, guest PC 0x0c0a0a64 */
if(!s->budget--) { s->failed_pc=0x0c0a0a64u; return 0; }
vf3_matrix_store(s,ram,6,r[4]+r[0]);
goto P_0c0a0a66;
P_0c0a0a66: /* original 6023, guest PC 0x0c0a0a66 */
if(!s->budget--) { s->failed_pc=0x0c0a0a66u; return 0; }
r[0]=r[2];
goto P_0c0a0a68;
P_0c0a0a68: /* original f497, guest PC 0x0c0a0a68 */
if(!s->budget--) { s->failed_pc=0x0c0a0a68u; return 0; }
vf3_matrix_store(s,ram,9,r[4]+r[0]);
goto P_0c0a0a6a;
P_0c0a0a6a: /* original e004, guest PC 0x0c0a0a6a */
if(!s->budget--) { s->failed_pc=0x0c0a0a6au; return 0; }
r[0]=0x00000004u;
goto P_0c0a0a6c;
P_0c0a0a6c: /* original 740c, guest PC 0x0c0a0a6c */
if(!s->budget--) { s->failed_pc=0x0c0a0a6cu; return 0; }
r[4]+=0x0000000cu;
goto P_0c0a0a6e;
P_0c0a0a6e: /* original f47a, guest PC 0x0c0a0a6e */
if(!s->budget--) { s->failed_pc=0x0c0a0a6eu; return 0; }
vf3_matrix_store(s,ram,7,r[4]);
goto P_0c0a0a70;
P_0c0a0a70: /* original f487, guest PC 0x0c0a0a70 */
if(!s->budget--) { s->failed_pc=0x0c0a0a70u; return 0; }
vf3_matrix_store(s,ram,8,r[4]+r[0]);
goto P_0c0a0a72;
P_0c0a0a72: /* original 6023, guest PC 0x0c0a0a72 */
if(!s->budget--) { s->failed_pc=0x0c0a0a72u; return 0; }
r[0]=r[2];
goto P_0c0a0a74;
P_0c0a0a74: /* original f447, guest PC 0x0c0a0a74 */
if(!s->budget--) { s->failed_pc=0x0c0a0a74u; return 0; }
vf3_matrix_store(s,ram,4,r[4]+r[0]);
goto P_0c0a0a76;
P_0c0a0a76: /* original e004, guest PC 0x0c0a0a76 */
if(!s->budget--) { s->failed_pc=0x0c0a0a76u; return 0; }
r[0]=0x00000004u;
goto P_0c0a0a78;
P_0c0a0a78: /* original 740c, guest PC 0x0c0a0a78 */
if(!s->budget--) { s->failed_pc=0x0c0a0a78u; return 0; }
r[4]+=0x0000000cu;
goto P_0c0a0a7a;
P_0c0a0a7a: /* original f47a, guest PC 0x0c0a0a7a */
if(!s->budget--) { s->failed_pc=0x0c0a0a7au; return 0; }
vf3_matrix_store(s,ram,7,r[4]);
goto P_0c0a0a7c;
P_0c0a0a7c: /* original f487, guest PC 0x0c0a0a7c */
if(!s->budget--) { s->failed_pc=0x0c0a0a7cu; return 0; }
vf3_matrix_store(s,ram,8,r[4]+r[0]);
goto P_0c0a0a7e;
P_0c0a0a7e: /* original 6023, guest PC 0x0c0a0a7e */
if(!s->budget--) { s->failed_pc=0x0c0a0a7eu; return 0; }
r[0]=r[2];
goto P_0c0a0a80;
P_0c0a0a80: /* original f497, guest PC 0x0c0a0a80 */
if(!s->budget--) { s->failed_pc=0x0c0a0a80u; return 0; }
vf3_matrix_store(s,ram,9,r[4]+r[0]);
goto P_0c0a0a82;
P_0c0a0a82: /* original e004, guest PC 0x0c0a0a82 */
if(!s->budget--) { s->failed_pc=0x0c0a0a82u; return 0; }
r[0]=0x00000004u;
goto P_0c0a0a84;
P_0c0a0a84: /* original 740c, guest PC 0x0c0a0a84 */
if(!s->budget--) { s->failed_pc=0x0c0a0a84u; return 0; }
r[4]+=0x0000000cu;
goto P_0c0a0a86;
P_0c0a0a86: /* original f45a, guest PC 0x0c0a0a86 */
if(!s->budget--) { s->failed_pc=0x0c0a0a86u; return 0; }
vf3_matrix_store(s,ram,5,r[4]);
goto P_0c0a0a88;
P_0c0a0a88: /* original f467, guest PC 0x0c0a0a88 */
if(!s->budget--) { s->failed_pc=0x0c0a0a88u; return 0; }
vf3_matrix_store(s,ram,6,r[4]+r[0]);
goto P_0c0a0a8a;
P_0c0a0a8a: /* original 6023, guest PC 0x0c0a0a8a */
if(!s->budget--) { s->failed_pc=0x0c0a0a8au; return 0; }
r[0]=r[2];
goto P_0c0a0a8c;
P_0c0a0a8c: /* original f447, guest PC 0x0c0a0a8c */
if(!s->budget--) { s->failed_pc=0x0c0a0a8cu; return 0; }
vf3_matrix_store(s,ram,4,r[4]+r[0]);
goto P_0c0a0a8e;
P_0c0a0a8e: /* original e004, guest PC 0x0c0a0a8e */
if(!s->budget--) { s->failed_pc=0x0c0a0a8eu; return 0; }
r[0]=0x00000004u;
goto P_0c0a0a90;
P_0c0a0a90: /* original 740c, guest PC 0x0c0a0a90 */
if(!s->budget--) { s->failed_pc=0x0c0a0a90u; return 0; }
r[4]+=0x0000000cu;
goto P_0c0a0a92;
P_0c0a0a92: /* original f45a, guest PC 0x0c0a0a92 */
if(!s->budget--) { s->failed_pc=0x0c0a0a92u; return 0; }
vf3_matrix_store(s,ram,5,r[4]);
goto P_0c0a0a94;
P_0c0a0a94: /* original f467, guest PC 0x0c0a0a94 */
if(!s->budget--) { s->failed_pc=0x0c0a0a94u; return 0; }
vf3_matrix_store(s,ram,6,r[4]+r[0]);
goto P_0c0a0a96;
P_0c0a0a96: /* original 6023, guest PC 0x0c0a0a96 */
if(!s->budget--) { s->failed_pc=0x0c0a0a96u; return 0; }
r[0]=r[2];
goto P_0c0a0a98;
P_0c0a0a98: /* original f497, guest PC 0x0c0a0a98 */
if(!s->budget--) { s->failed_pc=0x0c0a0a98u; return 0; }
vf3_matrix_store(s,ram,9,r[4]+r[0]);
goto P_0c0a0a9a;
P_0c0a0a9a: /* original e004, guest PC 0x0c0a0a9a */
if(!s->budget--) { s->failed_pc=0x0c0a0a9au; return 0; }
r[0]=0x00000004u;
goto P_0c0a0a9c;
P_0c0a0a9c: /* original 740c, guest PC 0x0c0a0a9c */
if(!s->budget--) { s->failed_pc=0x0c0a0a9cu; return 0; }
r[4]+=0x0000000cu;
goto P_0c0a0a9e;
P_0c0a0a9e: /* original f45a, guest PC 0x0c0a0a9e */
if(!s->budget--) { s->failed_pc=0x0c0a0a9eu; return 0; }
vf3_matrix_store(s,ram,5,r[4]);
goto P_0c0a0aa0;
P_0c0a0aa0: /* original f487, guest PC 0x0c0a0aa0 */
if(!s->budget--) { s->failed_pc=0x0c0a0aa0u; return 0; }
vf3_matrix_store(s,ram,8,r[4]+r[0]);
goto P_0c0a0aa2;
P_0c0a0aa2: /* original 6023, guest PC 0x0c0a0aa2 */
if(!s->budget--) { s->failed_pc=0x0c0a0aa2u; return 0; }
r[0]=r[2];
goto P_0c0a0aa4;
P_0c0a0aa4: /* original f447, guest PC 0x0c0a0aa4 */
if(!s->budget--) { s->failed_pc=0x0c0a0aa4u; return 0; }
vf3_matrix_store(s,ram,4,r[4]+r[0]);
goto P_0c0a0aa6;
P_0c0a0aa6: /* original 740c, guest PC 0x0c0a0aa6 */
if(!s->budget--) { s->failed_pc=0x0c0a0aa6u; return 0; }
r[4]+=0x0000000cu;
goto P_0c0a0aa8;
P_0c0a0aa8: /* original e004, guest PC 0x0c0a0aa8 */
if(!s->budget--) { s->failed_pc=0x0c0a0aa8u; return 0; }
r[0]=0x00000004u;
goto P_0c0a0aaa;
P_0c0a0aaa: /* original f45a, guest PC 0x0c0a0aaa */
if(!s->budget--) { s->failed_pc=0x0c0a0aaau; return 0; }
vf3_matrix_store(s,ram,5,r[4]);
goto P_0c0a0aac;
P_0c0a0aac: /* original f487, guest PC 0x0c0a0aac */
if(!s->budget--) { s->failed_pc=0x0c0a0aacu; return 0; }
vf3_matrix_store(s,ram,8,r[4]+r[0]);
goto P_0c0a0aae;
P_0c0a0aae: /* original 6023, guest PC 0x0c0a0aae */
if(!s->budget--) { s->failed_pc=0x0c0a0aaeu; return 0; }
r[0]=r[2];
goto P_0c0a0ab0;
P_0c0a0ab0: /* original f497, guest PC 0x0c0a0ab0 */
if(!s->budget--) { s->failed_pc=0x0c0a0ab0u; return 0; }
vf3_matrix_store(s,ram,9,r[4]+r[0]);
goto P_0c0a0ab2;
P_0c0a0ab2: /* original 7b0c, guest PC 0x0c0a0ab2 */
if(!s->budget--) { s->failed_pc=0x0c0a0ab2u; return 0; }
r[11]+=0x0000000cu;
goto P_0c0a0ab4;
P_0c0a0ab4: /* original 9038, guest PC 0x0c0a0ab4 */
if(!s->budget--) { s->failed_pc=0x0c0a0ab4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a0b28u,2);
goto P_0c0a0ab6;
P_0c0a0ab6: /* original fde7, guest PC 0x0c0a0ab6 */
if(!s->budget--) { s->failed_pc=0x0c0a0ab6u; return 0; }
vf3_matrix_store(s,ram,14,r[13]+r[0]);
goto P_0c0a0ab8;
P_0c0a0ab8: /* original 9337, guest PC 0x0c0a0ab8 */
if(!s->budget--) { s->failed_pc=0x0c0a0ab8u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a0b2au,2);
goto P_0c0a0aba;
P_0c0a0aba: /* original 3d3c, guest PC 0x0c0a0aba */
if(!s->budget--) { s->failed_pc=0x0c0a0abau; return 0; }
r[13]+=r[3];
goto P_0c0a0abc;
P_0c0a0abc: /* original 52f2, guest PC 0x0c0a0abc */
if(!s->budget--) { s->failed_pc=0x0c0a0abcu; return 0; }
r[2]=read(ram,r[15]+8,4);
goto P_0c0a0abe;
P_0c0a0abe: /* original 4910, guest PC 0x0c0a0abe */
if(!s->budget--) { s->failed_pc=0x0c0a0abeu; return 0; }
--r[9];
r[17]=(r[17]&~1u)|((r[9]==0)!=0);
goto P_0c0a0ac0;
P_0c0a0ac0: /* original 780c, guest PC 0x0c0a0ac0 */
if(!s->budget--) { s->failed_pc=0x0c0a0ac0u; return 0; }
r[8]+=0x0000000cu;
goto P_0c0a0ac2;
P_0c0a0ac2: /* original 7240, guest PC 0x0c0a0ac2 */
if(!s->budget--) { s->failed_pc=0x0c0a0ac2u; return 0; }
r[2]+=0x00000040u;
goto P_0c0a0ac4;
P_0c0a0ac4: /* original 8d02, guest PC 0x0c0a0ac4 */
if(!s->budget--) { s->failed_pc=0x0c0a0ac4u; return 0; }
cond=r[17]&1u;
write(ram,r[15]+8,r[2],4);
if(cond) { goto P_0c0a0acc; }
goto P_0c0a0ac8;
P_0c0a0ac6: /* original 1f22, guest PC 0x0c0a0ac6 */
if(!s->budget--) { s->failed_pc=0x0c0a0ac6u; return 0; }
write(ram,r[15]+8,r[2],4);
goto P_0c0a0ac8;
P_0c0a0ac8: /* original aed5, guest PC 0x0c0a0ac8 */
if(!s->budget--) { s->failed_pc=0x0c0a0ac8u; return 0; }
goto P_0c0a0876;
P_0c0a0aca: /* original 0009, guest PC 0x0c0a0aca */
if(!s->budget--) { s->failed_pc=0x0c0a0acau; return 0; }
goto P_0c0a0acc;
P_0c0a0acc: /* original 7f18, guest PC 0x0c0a0acc */
if(!s->budget--) { s->failed_pc=0x0c0a0accu; return 0; }
r[15]+=0x00000018u;
goto P_0c0a0ace;
P_0c0a0ace: /* original d31e, guest PC 0x0c0a0ace */
if(!s->budget--) { s->failed_pc=0x0c0a0aceu; return 0; }
r[3]=read(ram,0x0c0a0b48u,4);
goto P_0c0a0ad0;
P_0c0a0ad0: /* original 4f26, guest PC 0x0c0a0ad0 */
if(!s->budget--) { s->failed_pc=0x0c0a0ad0u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a0ad2;
P_0c0a0ad2: /* original e401, guest PC 0x0c0a0ad2 */
if(!s->budget--) { s->failed_pc=0x0c0a0ad2u; return 0; }
r[4]=0x00000001u;
goto P_0c0a0ad4;
P_0c0a0ad4: /* original fcf9, guest PC 0x0c0a0ad4 */
if(!s->budget--) { s->failed_pc=0x0c0a0ad4u; return 0; }
vf3_matrix_load(s,ram,12,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0a0ad6;
P_0c0a0ad6: /* original fdf9, guest PC 0x0c0a0ad6 */
if(!s->budget--) { s->failed_pc=0x0c0a0ad6u; return 0; }
vf3_matrix_load(s,ram,13,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0a0ad8;
P_0c0a0ad8: /* original fef9, guest PC 0x0c0a0ad8 */
if(!s->budget--) { s->failed_pc=0x0c0a0ad8u; return 0; }
vf3_matrix_load(s,ram,14,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0a0ada;
P_0c0a0ada: /* original fff9, guest PC 0x0c0a0ada */
if(!s->budget--) { s->failed_pc=0x0c0a0adau; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0a0adc;
P_0c0a0adc: /* original 68f6, guest PC 0x0c0a0adc */
if(!s->budget--) { s->failed_pc=0x0c0a0adcu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c0a0ade;
P_0c0a0ade: /* original 69f6, guest PC 0x0c0a0ade */
if(!s->budget--) { s->failed_pc=0x0c0a0adeu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c0a0ae0;
P_0c0a0ae0: /* original 6af6, guest PC 0x0c0a0ae0 */
if(!s->budget--) { s->failed_pc=0x0c0a0ae0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0a0ae2;
P_0c0a0ae2: /* original 6bf6, guest PC 0x0c0a0ae2 */
if(!s->budget--) { s->failed_pc=0x0c0a0ae2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0a0ae4;
P_0c0a0ae4: /* original 6cf6, guest PC 0x0c0a0ae4 */
if(!s->budget--) { s->failed_pc=0x0c0a0ae4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0a0ae6;
P_0c0a0ae6: /* original 6df6, guest PC 0x0c0a0ae6 */
if(!s->budget--) { s->failed_pc=0x0c0a0ae6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0a0ae8;
P_0c0a0ae8: /* original 432b, guest PC 0x0c0a0ae8 */
if(!s->budget--) { s->failed_pc=0x0c0a0ae8u; return 0; }
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
P_0c0a0aea: /* original 6ef6, guest PC 0x0c0a0aea */
if(!s->budget--) { s->failed_pc=0x0c0a0aeau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0a0aec;
P_0c0a0aec: /* original 2fe6, guest PC 0x0c0a0aec */
if(!s->budget--) { s->failed_pc=0x0c0a0aecu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a0aee;
P_0c0a0aee: /* original 2fd6, guest PC 0x0c0a0aee */
if(!s->budget--) { s->failed_pc=0x0c0a0aeeu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a0af0;
P_0c0a0af0: /* original 2fc6, guest PC 0x0c0a0af0 */
if(!s->budget--) { s->failed_pc=0x0c0a0af0u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a0af2;
P_0c0a0af2: /* original 2fb6, guest PC 0x0c0a0af2 */
if(!s->budget--) { s->failed_pc=0x0c0a0af2u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a0af4;
P_0c0a0af4: /* original 2fa6, guest PC 0x0c0a0af4 */
if(!s->budget--) { s->failed_pc=0x0c0a0af4u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a0af6;
P_0c0a0af6: /* original 2f96, guest PC 0x0c0a0af6 */
if(!s->budget--) { s->failed_pc=0x0c0a0af6u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a0af8;
P_0c0a0af8: /* original 2f86, guest PC 0x0c0a0af8 */
if(!s->budget--) { s->failed_pc=0x0c0a0af8u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a0afa;
P_0c0a0afa: /* original fffb, guest PC 0x0c0a0afa */
if(!s->budget--) { s->failed_pc=0x0c0a0afau; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c0a0afc;
P_0c0a0afc: /* original ffeb, guest PC 0x0c0a0afc */
if(!s->budget--) { s->failed_pc=0x0c0a0afcu; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,14,r[15]);
goto P_0c0a0afe;
P_0c0a0afe: /* original d115, guest PC 0x0c0a0afe */
if(!s->budget--) { s->failed_pc=0x0c0a0afeu; return 0; }
r[1]=read(ram,0x0c0a0b54u,4);
goto P_0c0a0b00;
P_0c0a0b00: /* original 4f22, guest PC 0x0c0a0b00 */
if(!s->budget--) { s->failed_pc=0x0c0a0b00u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0a0b02;
P_0c0a0b02: /* original d313, guest PC 0x0c0a0b02 */
if(!s->budget--) { s->failed_pc=0x0c0a0b02u; return 0; }
r[3]=read(ram,0x0c0a0b50u,4);
goto P_0c0a0b04;
P_0c0a0b04: /* original 6212, guest PC 0x0c0a0b04 */
if(!s->budget--) { s->failed_pc=0x0c0a0b04u; return 0; }
tmp=read(ram,r[1],4);
r[2]=tmp;
goto P_0c0a0b06;
P_0c0a0b06: /* original d611, guest PC 0x0c0a0b06 */
if(!s->budget--) { s->failed_pc=0x0c0a0b06u; return 0; }
r[6]=read(ram,0x0c0a0b4cu,4);
goto P_0c0a0b08;
P_0c0a0b08: /* original 7fe0, guest PC 0x0c0a0b08 */
if(!s->budget--) { s->failed_pc=0x0c0a0b08u; return 0; }
r[15]+=0xffffffe0u;
goto P_0c0a0b0a;
P_0c0a0b0a: /* original 2238, guest PC 0x0c0a0b0a */
if(!s->budget--) { s->failed_pc=0x0c0a0b0au; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c0a0b0c;
P_0c0a0b0c: /* original 8901, guest PC 0x0c0a0b0c */
if(!s->budget--) { s->failed_pc=0x0c0a0b0cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a0b12; }
goto P_0c0a0b0e;
P_0c0a0b0e: /* original a104, guest PC 0x0c0a0b0e */
if(!s->budget--) { s->failed_pc=0x0c0a0b0eu; return 0; }
goto P_0c0a0d1a;
P_0c0a0b10: /* original 0009, guest PC 0x0c0a0b10 */
if(!s->budget--) { s->failed_pc=0x0c0a0b10u; return 0; }
goto P_0c0a0b12;
P_0c0a0b12: /* original d511, guest PC 0x0c0a0b12 */
if(!s->budget--) { s->failed_pc=0x0c0a0b12u; return 0; }
r[5]=read(ram,0x0c0a0b58u,4);
goto P_0c0a0b14;
P_0c0a0b14: /* original e044, guest PC 0x0c0a0b14 */
if(!s->budget--) { s->failed_pc=0x0c0a0b14u; return 0; }
r[0]=0x00000044u;
goto P_0c0a0b16;
P_0c0a0b16: /* original 045e, guest PC 0x0c0a0b16 */
if(!s->budget--) { s->failed_pc=0x0c0a0b16u; return 0; }
r[4]=read(ram,r[5]+r[0],4);
goto P_0c0a0b18;
P_0c0a0b18: /* original 9008, guest PC 0x0c0a0b18 */
if(!s->budget--) { s->failed_pc=0x0c0a0b18u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a0b2cu,2);
goto P_0c0a0b1a;
P_0c0a0b1a: /* original 0c4e, guest PC 0x0c0a0b1a */
if(!s->budget--) { s->failed_pc=0x0c0a0b1au; return 0; }
r[12]=read(ram,r[4]+r[0],4);
goto P_0c0a0b1c;
P_0c0a0b1c: /* original 9007, guest PC 0x0c0a0b1c */
if(!s->budget--) { s->failed_pc=0x0c0a0b1cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a0b2eu,2);
goto P_0c0a0b1e;
P_0c0a0b1e: /* original 036c, guest PC 0x0c0a0b1e */
if(!s->budget--) { s->failed_pc=0x0c0a0b1eu; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[6]+r[0],1);
goto P_0c0a0b20;
P_0c0a0b20: /* original 2338, guest PC 0x0c0a0b20 */
if(!s->budget--) { s->failed_pc=0x0c0a0b20u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c0a0b22;
P_0c0a0b22: /* original 8b1b, guest PC 0x0c0a0b22 */
if(!s->budget--) { s->failed_pc=0x0c0a0b22u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a0b5c; }
goto P_0c0a0b24;
P_0c0a0b24: /* original a01b, guest PC 0x0c0a0b24 */
if(!s->budget--) { s->failed_pc=0x0c0a0b24u; return 0; }
r[4]=read(ram,r[5]+16,4);
goto P_0c0a0b5e;
P_0c0a0b26: /* original 5454, guest PC 0x0c0a0b26 */
if(!s->budget--) { s->failed_pc=0x0c0a0b26u; return 0; }
r[4]=read(ram,r[5]+16,4);
if(!vf3_matrix_family(0x0c0a0b28u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0a0b28u; return 0; } return 1;
P_0c0a0b5c: /* original 5455, guest PC 0x0c0a0b5c */
if(!s->budget--) { s->failed_pc=0x0c0a0b5cu; return 0; }
r[4]=read(ram,r[5]+20,4);
goto P_0c0a0b5e;
P_0c0a0b5e: /* original 9985, guest PC 0x0c0a0b5e */
if(!s->budget--) { s->failed_pc=0x0c0a0b5eu; return 0; }
r[9]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a0c6cu,2);
goto P_0c0a0b60;
P_0c0a0b60: /* original e812, guest PC 0x0c0a0b60 */
if(!s->budget--) { s->failed_pc=0x0c0a0b60u; return 0; }
r[8]=0x00000012u;
goto P_0c0a0b62;
P_0c0a0b62: /* original db46, guest PC 0x0c0a0b62 */
if(!s->budget--) { s->failed_pc=0x0c0a0b62u; return 0; }
r[11]=read(ram,0x0c0a0c7cu,4);
goto P_0c0a0b64;
P_0c0a0b64: /* original 394c, guest PC 0x0c0a0b64 */
if(!s->budget--) { s->failed_pc=0x0c0a0b64u; return 0; }
r[9]+=r[4];
goto P_0c0a0b66;
P_0c0a0b66: /* original 84b8, guest PC 0x0c0a0b66 */
if(!s->budget--) { s->failed_pc=0x0c0a0b66u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[11]+8,1);
goto P_0c0a0b68;
P_0c0a0b68: /* original 8801, guest PC 0x0c0a0b68 */
if(!s->budget--) { s->failed_pc=0x0c0a0b68u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c0a0b6a;
P_0c0a0b6a: /* original 8901, guest PC 0x0c0a0b6a */
if(!s->budget--) { s->failed_pc=0x0c0a0b6au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a0b70; }
goto P_0c0a0b6c;
P_0c0a0b6c: /* original a0cf, guest PC 0x0c0a0b6c */
if(!s->budget--) { s->failed_pc=0x0c0a0b6cu; return 0; }
goto P_0c0a0d0e;
P_0c0a0b6e: /* original 0009, guest PC 0x0c0a0b6e */
if(!s->budget--) { s->failed_pc=0x0c0a0b6eu; return 0; }
goto P_0c0a0b70;
P_0c0a0b70: /* original 9a7e, guest PC 0x0c0a0b70 */
if(!s->budget--) { s->failed_pc=0x0c0a0b70u; return 0; }
r[10]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a0c70u,2);
goto P_0c0a0b72;
P_0c0a0b72: /* original e300, guest PC 0x0c0a0b72 */
if(!s->budget--) { s->failed_pc=0x0c0a0b72u; return 0; }
r[3]=0x00000000u;
goto P_0c0a0b74;
P_0c0a0b74: /* original 9e7b, guest PC 0x0c0a0b74 */
if(!s->budget--) { s->failed_pc=0x0c0a0b74u; return 0; }
r[14]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a0c6eu,2);
goto P_0c0a0b76;
P_0c0a0b76: /* original 9d7c, guest PC 0x0c0a0b76 */
if(!s->budget--) { s->failed_pc=0x0c0a0b76u; return 0; }
r[13]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a0c72u,2);
goto P_0c0a0b78;
P_0c0a0b78: /* original 3acc, guest PC 0x0c0a0b78 */
if(!s->budget--) { s->failed_pc=0x0c0a0b78u; return 0; }
r[10]+=r[12];
goto P_0c0a0b7a;
P_0c0a0b7a: /* original 3ecc, guest PC 0x0c0a0b7a */
if(!s->budget--) { s->failed_pc=0x0c0a0b7au; return 0; }
r[14]+=r[12];
goto P_0c0a0b7c;
P_0c0a0b7c: /* original 1fc1, guest PC 0x0c0a0b7c */
if(!s->budget--) { s->failed_pc=0x0c0a0b7cu; return 0; }
write(ram,r[15]+4,r[12],4);
goto P_0c0a0b7e;
P_0c0a0b7e: /* original 64e3, guest PC 0x0c0a0b7e */
if(!s->budget--) { s->failed_pc=0x0c0a0b7eu; return 0; }
r[4]=r[14];
goto P_0c0a0b80;
P_0c0a0b80: /* original 2a32, guest PC 0x0c0a0b80 */
if(!s->budget--) { s->failed_pc=0x0c0a0b80u; return 0; }
write(ram,r[10],r[3],4);
goto P_0c0a0b82;
P_0c0a0b82: /* original d23f, guest PC 0x0c0a0b82 */
if(!s->budget--) { s->failed_pc=0x0c0a0b82u; return 0; }
r[2]=read(ram,0x0c0a0c80u,4);
goto P_0c0a0b84;
P_0c0a0b84: /* original 3dcc, guest PC 0x0c0a0b84 */
if(!s->budget--) { s->failed_pc=0x0c0a0b84u; return 0; }
r[13]+=r[12];
goto P_0c0a0b86;
P_0c0a0b86: /* original 420b, guest PC 0x0c0a0b86 */
if(!s->budget--) { s->failed_pc=0x0c0a0b86u; return 0; }
target=r[2];
r[16]=code_base|0x0c0a0b8au;
r[4]+=0x00000010u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a0b8au) { target=s->pc; goto dispatch; }
goto P_0c0a0b8a;
P_0c0a0b88: /* original 7410, guest PC 0x0c0a0b88 */
if(!s->budget--) { s->failed_pc=0x0c0a0b88u; return 0; }
r[4]+=0x00000010u;
goto P_0c0a0b8a;
P_0c0a0b8a: /* original e040, guest PC 0x0c0a0b8a */
if(!s->budget--) { s->failed_pc=0x0c0a0b8au; return 0; }
r[0]=0x00000040u;
goto P_0c0a0b8c;
P_0c0a0b8c: /* original 65f3, guest PC 0x0c0a0b8c */
if(!s->budget--) { s->failed_pc=0x0c0a0b8cu; return 0; }
r[5]=r[15];
goto P_0c0a0b8e;
P_0c0a0b8e: /* original fee6, guest PC 0x0c0a0b8e */
if(!s->budget--) { s->failed_pc=0x0c0a0b8eu; return 0; }
vf3_matrix_load(s,ram,14,r[14]+r[0]);
goto P_0c0a0b90;
P_0c0a0b90: /* original e044, guest PC 0x0c0a0b90 */
if(!s->budget--) { s->failed_pc=0x0c0a0b90u; return 0; }
r[0]=0x00000044u;
goto P_0c0a0b92;
P_0c0a0b92: /* original f3e6, guest PC 0x0c0a0b92 */
if(!s->budget--) { s->failed_pc=0x0c0a0b92u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c0a0b94;
P_0c0a0b94: /* original e048, guest PC 0x0c0a0b94 */
if(!s->budget--) { s->failed_pc=0x0c0a0b94u; return 0; }
r[0]=0x00000048u;
goto P_0c0a0b96;
P_0c0a0b96: /* original 64f3, guest PC 0x0c0a0b96 */
if(!s->budget--) { s->failed_pc=0x0c0a0b96u; return 0; }
r[4]=r[15];
goto P_0c0a0b98;
P_0c0a0b98: /* original 7514, guest PC 0x0c0a0b98 */
if(!s->budget--) { s->failed_pc=0x0c0a0b98u; return 0; }
r[5]+=0x00000014u;
goto P_0c0a0b9a;
P_0c0a0b9a: /* original ff3a, guest PC 0x0c0a0b9a */
if(!s->budget--) { s->failed_pc=0x0c0a0b9au; return 0; }
vf3_matrix_store(s,ram,3,r[15]);
goto P_0c0a0b9c;
P_0c0a0b9c: /* original ffe6, guest PC 0x0c0a0b9c */
if(!s->budget--) { s->failed_pc=0x0c0a0b9cu; return 0; }
vf3_matrix_load(s,ram,15,r[14]+r[0]);
goto P_0c0a0b9e;
P_0c0a0b9e: /* original d339, guest PC 0x0c0a0b9e */
if(!s->budget--) { s->failed_pc=0x0c0a0b9eu; return 0; }
r[3]=read(ram,0x0c0a0c84u,4);
goto P_0c0a0ba0;
P_0c0a0ba0: /* original f5fc, guest PC 0x0c0a0ba0 */
if(!s->budget--) { s->failed_pc=0x0c0a0ba0u; return 0; }
vf3_matrix_move(s,5,15);
goto P_0c0a0ba2;
P_0c0a0ba2: /* original f54d, guest PC 0x0c0a0ba2 */
if(!s->budget--) { s->failed_pc=0x0c0a0ba2u; return 0; }
fr[5]^=0x80000000u;
goto P_0c0a0ba4;
P_0c0a0ba4: /* original 430b, guest PC 0x0c0a0ba4 */
if(!s->budget--) { s->failed_pc=0x0c0a0ba4u; return 0; }
target=r[3];
r[16]=code_base|0x0c0a0ba8u;
vf3_matrix_move(s,4,14);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a0ba8u) { target=s->pc; goto dispatch; }
goto P_0c0a0ba8;
P_0c0a0ba6: /* original f4ec, guest PC 0x0c0a0ba6 */
if(!s->budget--) { s->failed_pc=0x0c0a0ba6u; return 0; }
vf3_matrix_move(s,4,14);
goto P_0c0a0ba8;
P_0c0a0ba8: /* original d237, guest PC 0x0c0a0ba8 */
if(!s->budget--) { s->failed_pc=0x0c0a0ba8u; return 0; }
r[2]=read(ram,0x0c0a0c88u,4);
goto P_0c0a0baa;
P_0c0a0baa: /* original 64f3, guest PC 0x0c0a0baa */
if(!s->budget--) { s->failed_pc=0x0c0a0baau; return 0; }
r[4]=r[15];
goto P_0c0a0bac;
P_0c0a0bac: /* original 420b, guest PC 0x0c0a0bac */
if(!s->budget--) { s->failed_pc=0x0c0a0bacu; return 0; }
target=r[2];
r[16]=code_base|0x0c0a0bb0u;
r[4]+=0x00000014u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a0bb0u) { target=s->pc; goto dispatch; }
goto P_0c0a0bb0;
P_0c0a0bae: /* original 7414, guest PC 0x0c0a0bae */
if(!s->budget--) { s->failed_pc=0x0c0a0baeu; return 0; }
r[4]+=0x00000014u;
goto P_0c0a0bb0;
P_0c0a0bb0: /* original e01c, guest PC 0x0c0a0bb0 */
if(!s->budget--) { s->failed_pc=0x0c0a0bb0u; return 0; }
r[0]=0x0000001cu;
goto P_0c0a0bb2;
P_0c0a0bb2: /* original f3f6, guest PC 0x0c0a0bb2 */
if(!s->budget--) { s->failed_pc=0x0c0a0bb2u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0a0bb4;
P_0c0a0bb4: /* original e01c, guest PC 0x0c0a0bb4 */
if(!s->budget--) { s->failed_pc=0x0c0a0bb4u; return 0; }
r[0]=0x0000001cu;
goto P_0c0a0bb6;
P_0c0a0bb6: /* original f34d, guest PC 0x0c0a0bb6 */
if(!s->budget--) { s->failed_pc=0x0c0a0bb6u; return 0; }
fr[3]^=0x80000000u;
goto P_0c0a0bb8;
P_0c0a0bb8: /* original ff37, guest PC 0x0c0a0bb8 */
if(!s->budget--) { s->failed_pc=0x0c0a0bb8u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0a0bba;
P_0c0a0bba: /* original c734, guest PC 0x0c0a0bba */
if(!s->budget--) { s->failed_pc=0x0c0a0bbau; return 0; }
r[0]=code_base|0x000a0c8cu;
goto P_0c0a0bbc;
P_0c0a0bbc: /* original f3f8, guest PC 0x0c0a0bbc */
if(!s->budget--) { s->failed_pc=0x0c0a0bbcu; return 0; }
vf3_matrix_load(s,ram,3,r[15]);
goto P_0c0a0bbe;
P_0c0a0bbe: /* original f408, guest PC 0x0c0a0bbe */
if(!s->budget--) { s->failed_pc=0x0c0a0bbeu; return 0; }
vf3_matrix_load(s,ram,4,r[0]);
goto P_0c0a0bc0;
P_0c0a0bc0: /* original e018, guest PC 0x0c0a0bc0 */
if(!s->budget--) { s->failed_pc=0x0c0a0bc0u; return 0; }
r[0]=0x00000018u;
goto P_0c0a0bc2;
P_0c0a0bc2: /* original f340, guest PC 0x0c0a0bc2 */
if(!s->budget--) { s->failed_pc=0x0c0a0bc2u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'+');
goto P_0c0a0bc4;
P_0c0a0bc4: /* original ff3a, guest PC 0x0c0a0bc4 */
if(!s->budget--) { s->failed_pc=0x0c0a0bc4u; return 0; }
vf3_matrix_store(s,ram,3,r[15]);
goto P_0c0a0bc6;
P_0c0a0bc6: /* original fde7, guest PC 0x0c0a0bc6 */
if(!s->budget--) { s->failed_pc=0x0c0a0bc6u; return 0; }
vf3_matrix_store(s,ram,14,r[13]+r[0]);
goto P_0c0a0bc8;
P_0c0a0bc8: /* original e01c, guest PC 0x0c0a0bc8 */
if(!s->budget--) { s->failed_pc=0x0c0a0bc8u; return 0; }
r[0]=0x0000001cu;
goto P_0c0a0bca;
P_0c0a0bca: /* original f3f8, guest PC 0x0c0a0bca */
if(!s->budget--) { s->failed_pc=0x0c0a0bcau; return 0; }
vf3_matrix_load(s,ram,3,r[15]);
goto P_0c0a0bcc;
P_0c0a0bcc: /* original fd37, guest PC 0x0c0a0bcc */
if(!s->budget--) { s->failed_pc=0x0c0a0bccu; return 0; }
vf3_matrix_store(s,ram,3,r[13]+r[0]);
goto P_0c0a0bce;
P_0c0a0bce: /* original e020, guest PC 0x0c0a0bce */
if(!s->budget--) { s->failed_pc=0x0c0a0bceu; return 0; }
r[0]=0x00000020u;
goto P_0c0a0bd0;
P_0c0a0bd0: /* original fdf7, guest PC 0x0c0a0bd0 */
if(!s->budget--) { s->failed_pc=0x0c0a0bd0u; return 0; }
vf3_matrix_store(s,ram,15,r[13]+r[0]);
goto P_0c0a0bd2;
P_0c0a0bd2: /* original e014, guest PC 0x0c0a0bd2 */
if(!s->budget--) { s->failed_pc=0x0c0a0bd2u; return 0; }
r[0]=0x00000014u;
goto P_0c0a0bd4;
P_0c0a0bd4: /* original f3f6, guest PC 0x0c0a0bd4 */
if(!s->budget--) { s->failed_pc=0x0c0a0bd4u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0a0bd6;
P_0c0a0bd6: /* original e018, guest PC 0x0c0a0bd6 */
if(!s->budget--) { s->failed_pc=0x0c0a0bd6u; return 0; }
r[0]=0x00000018u;
goto P_0c0a0bd8;
P_0c0a0bd8: /* original fd3a, guest PC 0x0c0a0bd8 */
if(!s->budget--) { s->failed_pc=0x0c0a0bd8u; return 0; }
vf3_matrix_store(s,ram,3,r[13]);
goto P_0c0a0bda;
P_0c0a0bda: /* original f3f6, guest PC 0x0c0a0bda */
if(!s->budget--) { s->failed_pc=0x0c0a0bdau; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0a0bdc;
P_0c0a0bdc: /* original e004, guest PC 0x0c0a0bdc */
if(!s->budget--) { s->failed_pc=0x0c0a0bdcu; return 0; }
r[0]=0x00000004u;
goto P_0c0a0bde;
P_0c0a0bde: /* original fd37, guest PC 0x0c0a0bde */
if(!s->budget--) { s->failed_pc=0x0c0a0bdeu; return 0; }
vf3_matrix_store(s,ram,3,r[13]+r[0]);
goto P_0c0a0be0;
P_0c0a0be0: /* original e01c, guest PC 0x0c0a0be0 */
if(!s->budget--) { s->failed_pc=0x0c0a0be0u; return 0; }
r[0]=0x0000001cu;
goto P_0c0a0be2;
P_0c0a0be2: /* original f3f6, guest PC 0x0c0a0be2 */
if(!s->budget--) { s->failed_pc=0x0c0a0be2u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0a0be4;
P_0c0a0be4: /* original e008, guest PC 0x0c0a0be4 */
if(!s->budget--) { s->failed_pc=0x0c0a0be4u; return 0; }
r[0]=0x00000008u;
goto P_0c0a0be6;
P_0c0a0be6: /* original fd37, guest PC 0x0c0a0be6 */
if(!s->budget--) { s->failed_pc=0x0c0a0be6u; return 0; }
vf3_matrix_store(s,ram,3,r[13]+r[0]);
goto P_0c0a0be8;
P_0c0a0be8: /* original e014, guest PC 0x0c0a0be8 */
if(!s->budget--) { s->failed_pc=0x0c0a0be8u; return 0; }
r[0]=0x00000014u;
goto P_0c0a0bea;
P_0c0a0bea: /* original f3f6, guest PC 0x0c0a0bea */
if(!s->budget--) { s->failed_pc=0x0c0a0beau; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0a0bec;
P_0c0a0bec: /* original f04c, guest PC 0x0c0a0bec */
if(!s->budget--) { s->failed_pc=0x0c0a0becu; return 0; }
vf3_matrix_move(s,0,4);
goto P_0c0a0bee;
P_0c0a0bee: /* original fe3e, guest PC 0x0c0a0bee */
if(!s->budget--) { s->failed_pc=0x0c0a0beeu; return 0; }
fr[14]=vf3_fpu_mac(fr[0],fr[3],fr[14],r[18]);
goto P_0c0a0bf0;
P_0c0a0bf0: /* original e00c, guest PC 0x0c0a0bf0 */
if(!s->budget--) { s->failed_pc=0x0c0a0bf0u; return 0; }
r[0]=0x0000000cu;
goto P_0c0a0bf2;
P_0c0a0bf2: /* original 65d3, guest PC 0x0c0a0bf2 */
if(!s->budget--) { s->failed_pc=0x0c0a0bf2u; return 0; }
r[5]=r[13];
goto P_0c0a0bf4;
P_0c0a0bf4: /* original fde7, guest PC 0x0c0a0bf4 */
if(!s->budget--) { s->failed_pc=0x0c0a0bf4u; return 0; }
vf3_matrix_store(s,ram,14,r[13]+r[0]);
goto P_0c0a0bf6;
P_0c0a0bf6: /* original e018, guest PC 0x0c0a0bf6 */
if(!s->budget--) { s->failed_pc=0x0c0a0bf6u; return 0; }
r[0]=0x00000018u;
goto P_0c0a0bf8;
P_0c0a0bf8: /* original f2f6, guest PC 0x0c0a0bf8 */
if(!s->budget--) { s->failed_pc=0x0c0a0bf8u; return 0; }
vf3_matrix_load(s,ram,2,r[15]+r[0]);
goto P_0c0a0bfa;
P_0c0a0bfa: /* original e010, guest PC 0x0c0a0bfa */
if(!s->budget--) { s->failed_pc=0x0c0a0bfau; return 0; }
r[0]=0x00000010u;
goto P_0c0a0bfc;
P_0c0a0bfc: /* original f3f8, guest PC 0x0c0a0bfc */
if(!s->budget--) { s->failed_pc=0x0c0a0bfcu; return 0; }
vf3_matrix_load(s,ram,3,r[15]);
goto P_0c0a0bfe;
P_0c0a0bfe: /* original f32e, guest PC 0x0c0a0bfe */
if(!s->budget--) { s->failed_pc=0x0c0a0bfeu; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[2],fr[3],r[18]);
goto P_0c0a0c00;
P_0c0a0c00: /* original fd37, guest PC 0x0c0a0c00 */
if(!s->budget--) { s->failed_pc=0x0c0a0c00u; return 0; }
vf3_matrix_store(s,ram,3,r[13]+r[0]);
goto P_0c0a0c02;
P_0c0a0c02: /* original e01c, guest PC 0x0c0a0c02 */
if(!s->budget--) { s->failed_pc=0x0c0a0c02u; return 0; }
r[0]=0x0000001cu;
goto P_0c0a0c04;
P_0c0a0c04: /* original f3f6, guest PC 0x0c0a0c04 */
if(!s->budget--) { s->failed_pc=0x0c0a0c04u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0a0c06;
P_0c0a0c06: /* original e014, guest PC 0x0c0a0c06 */
if(!s->budget--) { s->failed_pc=0x0c0a0c06u; return 0; }
r[0]=0x00000014u;
goto P_0c0a0c08;
P_0c0a0c08: /* original ff3e, guest PC 0x0c0a0c08 */
if(!s->budget--) { s->failed_pc=0x0c0a0c08u; return 0; }
fr[15]=vf3_fpu_mac(fr[0],fr[3],fr[15],r[18]);
goto P_0c0a0c0a;
P_0c0a0c0a: /* original fdf7, guest PC 0x0c0a0c0a */
if(!s->budget--) { s->failed_pc=0x0c0a0c0au; return 0; }
vf3_matrix_store(s,ram,15,r[13]+r[0]);
goto P_0c0a0c0c;
P_0c0a0c0c: /* original 56f1, guest PC 0x0c0a0c0c */
if(!s->budget--) { s->failed_pc=0x0c0a0c0cu; return 0; }
r[6]=read(ram,r[15]+4,4);
goto P_0c0a0c0e;
P_0c0a0c0e: /* original d320, guest PC 0x0c0a0c0e */
if(!s->budget--) { s->failed_pc=0x0c0a0c0eu; return 0; }
r[3]=read(ram,0x0c0a0c90u,4);
goto P_0c0a0c10;
P_0c0a0c10: /* original 430b, guest PC 0x0c0a0c10 */
if(!s->budget--) { s->failed_pc=0x0c0a0c10u; return 0; }
target=r[3];
r[16]=code_base|0x0c0a0c14u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a0c14u) { target=s->pc; goto dispatch; }
goto P_0c0a0c14;
P_0c0a0c12: /* original 64e3, guest PC 0x0c0a0c12 */
if(!s->budget--) { s->failed_pc=0x0c0a0c12u; return 0; }
r[4]=r[14];
goto P_0c0a0c14;
P_0c0a0c14: /* original 64f3, guest PC 0x0c0a0c14 */
if(!s->budget--) { s->failed_pc=0x0c0a0c14u; return 0; }
r[4]=r[15];
goto P_0c0a0c16;
P_0c0a0c16: /* original 6503, guest PC 0x0c0a0c16 */
if(!s->budget--) { s->failed_pc=0x0c0a0c16u; return 0; }
r[5]=r[0];
goto P_0c0a0c18;
P_0c0a0c18: /* original e004, guest PC 0x0c0a0c18 */
if(!s->budget--) { s->failed_pc=0x0c0a0c18u; return 0; }
r[0]=0x00000004u;
goto P_0c0a0c1a;
P_0c0a0c1a: /* original 7408, guest PC 0x0c0a0c1a */
if(!s->budget--) { s->failed_pc=0x0c0a0c1au; return 0; }
r[4]+=0x00000008u;
goto P_0c0a0c1c;
P_0c0a0c1c: /* original f346, guest PC 0x0c0a0c1c */
if(!s->budget--) { s->failed_pc=0x0c0a0c1cu; return 0; }
vf3_matrix_load(s,ram,3,r[4]+r[0]);
goto P_0c0a0c1e;
P_0c0a0c1e: /* original 2558, guest PC 0x0c0a0c1e */
if(!s->budget--) { s->failed_pc=0x0c0a0c1eu; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[5])==0)!=0);
goto P_0c0a0c20;
P_0c0a0c20: /* original 8d6a, guest PC 0x0c0a0c20 */
if(!s->budget--) { s->failed_pc=0x0c0a0c20u; return 0; }
cond=r[17]&1u;
vf3_matrix_store(s,ram,3,r[15]);
if(cond) { goto P_0c0a0cf8; }
goto P_0c0a0c24;
P_0c0a0c22: /* original ff3a, guest PC 0x0c0a0c22 */
if(!s->budget--) { s->failed_pc=0x0c0a0c22u; return 0; }
vf3_matrix_store(s,ram,3,r[15]);
goto P_0c0a0c24;
P_0c0a0c24: /* original c71b, guest PC 0x0c0a0c24 */
if(!s->budget--) { s->failed_pc=0x0c0a0c24u; return 0; }
r[0]=code_base|0x000a0c94u;
goto P_0c0a0c26;
P_0c0a0c26: /* original f508, guest PC 0x0c0a0c26 */
if(!s->budget--) { s->failed_pc=0x0c0a0c26u; return 0; }
vf3_matrix_load(s,ram,5,r[0]);
goto P_0c0a0c28;
P_0c0a0c28: /* original c71b, guest PC 0x0c0a0c28 */
if(!s->budget--) { s->failed_pc=0x0c0a0c28u; return 0; }
r[0]=code_base|0x000a0c98u;
goto P_0c0a0c2a;
P_0c0a0c2a: /* original f408, guest PC 0x0c0a0c2a */
if(!s->budget--) { s->failed_pc=0x0c0a0c2au; return 0; }
vf3_matrix_load(s,ram,4,r[0]);
goto P_0c0a0c2c;
P_0c0a0c2c: /* original e05c, guest PC 0x0c0a0c2c */
if(!s->budget--) { s->failed_pc=0x0c0a0c2cu; return 0; }
r[0]=0x0000005cu;
goto P_0c0a0c2e;
P_0c0a0c2e: /* original f3e6, guest PC 0x0c0a0c2e */
if(!s->budget--) { s->failed_pc=0x0c0a0c2eu; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c0a0c30;
P_0c0a0c30: /* original f352, guest PC 0x0c0a0c30 */
if(!s->budget--) { s->failed_pc=0x0c0a0c30u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[5],r[18],'*');
goto P_0c0a0c32;
P_0c0a0c32: /* original fe37, guest PC 0x0c0a0c32 */
if(!s->budget--) { s->failed_pc=0x0c0a0c32u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c0a0c34;
P_0c0a0c34: /* original e060, guest PC 0x0c0a0c34 */
if(!s->budget--) { s->failed_pc=0x0c0a0c34u; return 0; }
r[0]=0x00000060u;
goto P_0c0a0c36;
P_0c0a0c36: /* original d119, guest PC 0x0c0a0c36 */
if(!s->budget--) { s->failed_pc=0x0c0a0c36u; return 0; }
r[1]=read(ram,0x0c0a0c9cu,4);
goto P_0c0a0c38;
P_0c0a0c38: /* original f2e6, guest PC 0x0c0a0c38 */
if(!s->budget--) { s->failed_pc=0x0c0a0c38u; return 0; }
vf3_matrix_load(s,ram,2,r[14]+r[0]);
goto P_0c0a0c3a;
P_0c0a0c3a: /* original 415a, guest PC 0x0c0a0c3a */
if(!s->budget--) { s->failed_pc=0x0c0a0c3au; return 0; }
r[53]=r[1];
goto P_0c0a0c3c;
P_0c0a0c3c: /* original f30d, guest PC 0x0c0a0c3c */
if(!s->budget--) { s->failed_pc=0x0c0a0c3cu; return 0; }
fr[3]=r[53];
goto P_0c0a0c3e;
P_0c0a0c3e: /* original f232, guest PC 0x0c0a0c3e */
if(!s->budget--) { s->failed_pc=0x0c0a0c3eu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c0a0c40;
P_0c0a0c40: /* original fe27, guest PC 0x0c0a0c40 */
if(!s->budget--) { s->failed_pc=0x0c0a0c40u; return 0; }
vf3_matrix_store(s,ram,2,r[14]+r[0]);
goto P_0c0a0c42;
P_0c0a0c42: /* original e064, guest PC 0x0c0a0c42 */
if(!s->budget--) { s->failed_pc=0x0c0a0c42u; return 0; }
r[0]=0x00000064u;
goto P_0c0a0c44;
P_0c0a0c44: /* original f2e6, guest PC 0x0c0a0c44 */
if(!s->budget--) { s->failed_pc=0x0c0a0c44u; return 0; }
vf3_matrix_load(s,ram,2,r[14]+r[0]);
goto P_0c0a0c46;
P_0c0a0c46: /* original f252, guest PC 0x0c0a0c46 */
if(!s->budget--) { s->failed_pc=0x0c0a0c46u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'*');
goto P_0c0a0c48;
P_0c0a0c48: /* original fe27, guest PC 0x0c0a0c48 */
if(!s->budget--) { s->failed_pc=0x0c0a0c48u; return 0; }
vf3_matrix_store(s,ram,2,r[14]+r[0]);
goto P_0c0a0c4a;
P_0c0a0c4a: /* original 7030, guest PC 0x0c0a0c4a */
if(!s->budget--) { s->failed_pc=0x0c0a0c4au; return 0; }
r[0]+=0x00000030u;
goto P_0c0a0c4c;
P_0c0a0c4c: /* original 04ed, guest PC 0x0c0a0c4c */
if(!s->budget--) { s->failed_pc=0x0c0a0c4cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0a0c4e;
P_0c0a0c4e: /* original 9511, guest PC 0x0c0a0c4e */
if(!s->budget--) { s->failed_pc=0x0c0a0c4eu; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a0c74u,2);
goto P_0c0a0c50;
P_0c0a0c50: /* original 3453, guest PC 0x0c0a0c50 */
if(!s->budget--) { s->failed_pc=0x0c0a0c50u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=(int32_t)r[5])!=0);
goto P_0c0a0c52;
P_0c0a0c52: /* original 8b04, guest PC 0x0c0a0c52 */
if(!s->budget--) { s->failed_pc=0x0c0a0c52u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a0c5e; }
goto P_0c0a0c54;
P_0c0a0c54: /* original 4415, guest PC 0x0c0a0c54 */
if(!s->budget--) { s->failed_pc=0x0c0a0c54u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>0)!=0);
goto P_0c0a0c56;
P_0c0a0c56: /* original 8b23, guest PC 0x0c0a0c56 */
if(!s->budget--) { s->failed_pc=0x0c0a0c56u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a0ca0; }
goto P_0c0a0c58;
P_0c0a0c58: /* original 930d, guest PC 0x0c0a0c58 */
if(!s->budget--) { s->failed_pc=0x0c0a0c58u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a0c76u,2);
goto P_0c0a0c5a;
P_0c0a0c5a: /* original 3433, guest PC 0x0c0a0c5a */
if(!s->budget--) { s->failed_pc=0x0c0a0c5au; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=(int32_t)r[3])!=0);
goto P_0c0a0c5c;
P_0c0a0c5c: /* original 8920, guest PC 0x0c0a0c5c */
if(!s->budget--) { s->failed_pc=0x0c0a0c5cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a0ca0; }
goto P_0c0a0c5e;
P_0c0a0c5e: /* original 900b, guest PC 0x0c0a0c5e */
if(!s->budget--) { s->failed_pc=0x0c0a0c5eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a0c78u,2);
goto P_0c0a0c60;
P_0c0a0c60: /* original 03ed, guest PC 0x0c0a0c60 */
if(!s->budget--) { s->failed_pc=0x0c0a0c60u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0a0c62;
P_0c0a0c62: /* original 435a, guest PC 0x0c0a0c62 */
if(!s->budget--) { s->failed_pc=0x0c0a0c62u; return 0; }
r[53]=r[3];
goto P_0c0a0c64;
P_0c0a0c64: /* original f32d, guest PC 0x0c0a0c64 */
if(!s->budget--) { s->failed_pc=0x0c0a0c64u; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c0a0c66;
P_0c0a0c66: /* original f35d, guest PC 0x0c0a0c66 */
if(!s->budget--) { s->failed_pc=0x0c0a0c66u; return 0; }
fr[3]&=0x7fffffffu;
goto P_0c0a0c68;
P_0c0a0c68: /* original a021, guest PC 0x0c0a0c68 */
if(!s->budget--) { s->failed_pc=0x0c0a0c68u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'*');
goto P_0c0a0cae;
P_0c0a0c6a: /* original f342, guest PC 0x0c0a0c6a */
if(!s->budget--) { s->failed_pc=0x0c0a0c6au; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'*');
if(!vf3_matrix_family(0x0c0a0c6cu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0a0c6cu; return 0; } return 1;
P_0c0a0ca0: /* original 9069, guest PC 0x0c0a0ca0 */
if(!s->budget--) { s->failed_pc=0x0c0a0ca0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a0d76u,2);
goto P_0c0a0ca2;
P_0c0a0ca2: /* original 03ed, guest PC 0x0c0a0ca2 */
if(!s->budget--) { s->failed_pc=0x0c0a0ca2u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0a0ca4;
P_0c0a0ca4: /* original 435a, guest PC 0x0c0a0ca4 */
if(!s->budget--) { s->failed_pc=0x0c0a0ca4u; return 0; }
r[53]=r[3];
goto P_0c0a0ca6;
P_0c0a0ca6: /* original f32d, guest PC 0x0c0a0ca6 */
if(!s->budget--) { s->failed_pc=0x0c0a0ca6u; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c0a0ca8;
P_0c0a0ca8: /* original f35d, guest PC 0x0c0a0ca8 */
if(!s->budget--) { s->failed_pc=0x0c0a0ca8u; return 0; }
fr[3]&=0x7fffffffu;
goto P_0c0a0caa;
P_0c0a0caa: /* original f342, guest PC 0x0c0a0caa */
if(!s->budget--) { s->failed_pc=0x0c0a0caau; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'*');
goto P_0c0a0cac;
P_0c0a0cac: /* original f34d, guest PC 0x0c0a0cac */
if(!s->budget--) { s->failed_pc=0x0c0a0cacu; return 0; }
fr[3]^=0x80000000u;
goto P_0c0a0cae;
P_0c0a0cae: /* original f33d, guest PC 0x0c0a0cae */
if(!s->budget--) { s->failed_pc=0x0c0a0caeu; return 0; }
r[53]=truncate_float(fr[3]);
goto P_0c0a0cb0;
P_0c0a0cb0: /* original 035a, guest PC 0x0c0a0cb0 */
if(!s->budget--) { s->failed_pc=0x0c0a0cb0u; return 0; }
r[3]=r[53];
goto P_0c0a0cb2;
P_0c0a0cb2: /* original 0e35, guest PC 0x0c0a0cb2 */
if(!s->budget--) { s->failed_pc=0x0c0a0cb2u; return 0; }
write(ram,r[14]+r[0],r[3],2);
goto P_0c0a0cb4;
P_0c0a0cb4: /* original 9060, guest PC 0x0c0a0cb4 */
if(!s->budget--) { s->failed_pc=0x0c0a0cb4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a0d78u,2);
goto P_0c0a0cb6;
P_0c0a0cb6: /* original 04ed, guest PC 0x0c0a0cb6 */
if(!s->budget--) { s->failed_pc=0x0c0a0cb6u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0a0cb8;
P_0c0a0cb8: /* original 3453, guest PC 0x0c0a0cb8 */
if(!s->budget--) { s->failed_pc=0x0c0a0cb8u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=(int32_t)r[5])!=0);
goto P_0c0a0cba;
P_0c0a0cba: /* original 8b04, guest PC 0x0c0a0cba */
if(!s->budget--) { s->failed_pc=0x0c0a0cbau; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a0cc6; }
goto P_0c0a0cbc;
P_0c0a0cbc: /* original 4415, guest PC 0x0c0a0cbc */
if(!s->budget--) { s->failed_pc=0x0c0a0cbcu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>0)!=0);
goto P_0c0a0cbe;
P_0c0a0cbe: /* original 8b09, guest PC 0x0c0a0cbe */
if(!s->budget--) { s->failed_pc=0x0c0a0cbeu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a0cd4; }
goto P_0c0a0cc0;
P_0c0a0cc0: /* original 935b, guest PC 0x0c0a0cc0 */
if(!s->budget--) { s->failed_pc=0x0c0a0cc0u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a0d7au,2);
goto P_0c0a0cc2;
P_0c0a0cc2: /* original 3433, guest PC 0x0c0a0cc2 */
if(!s->budget--) { s->failed_pc=0x0c0a0cc2u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=(int32_t)r[3])!=0);
goto P_0c0a0cc4;
P_0c0a0cc4: /* original 8906, guest PC 0x0c0a0cc4 */
if(!s->budget--) { s->failed_pc=0x0c0a0cc4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a0cd4; }
goto P_0c0a0cc6;
P_0c0a0cc6: /* original 9059, guest PC 0x0c0a0cc6 */
if(!s->budget--) { s->failed_pc=0x0c0a0cc6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a0d7cu,2);
goto P_0c0a0cc8;
P_0c0a0cc8: /* original 03ed, guest PC 0x0c0a0cc8 */
if(!s->budget--) { s->failed_pc=0x0c0a0cc8u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0a0cca;
P_0c0a0cca: /* original 435a, guest PC 0x0c0a0cca */
if(!s->budget--) { s->failed_pc=0x0c0a0ccau; return 0; }
r[53]=r[3];
goto P_0c0a0ccc;
P_0c0a0ccc: /* original f32d, guest PC 0x0c0a0ccc */
if(!s->budget--) { s->failed_pc=0x0c0a0cccu; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c0a0cce;
P_0c0a0cce: /* original f35d, guest PC 0x0c0a0cce */
if(!s->budget--) { s->failed_pc=0x0c0a0cceu; return 0; }
fr[3]&=0x7fffffffu;
goto P_0c0a0cd0;
P_0c0a0cd0: /* original a007, guest PC 0x0c0a0cd0 */
if(!s->budget--) { s->failed_pc=0x0c0a0cd0u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'*');
goto P_0c0a0ce2;
P_0c0a0cd2: /* original f342, guest PC 0x0c0a0cd2 */
if(!s->budget--) { s->failed_pc=0x0c0a0cd2u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'*');
goto P_0c0a0cd4;
P_0c0a0cd4: /* original 9052, guest PC 0x0c0a0cd4 */
if(!s->budget--) { s->failed_pc=0x0c0a0cd4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a0d7cu,2);
goto P_0c0a0cd6;
P_0c0a0cd6: /* original 03ed, guest PC 0x0c0a0cd6 */
if(!s->budget--) { s->failed_pc=0x0c0a0cd6u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0a0cd8;
P_0c0a0cd8: /* original 435a, guest PC 0x0c0a0cd8 */
if(!s->budget--) { s->failed_pc=0x0c0a0cd8u; return 0; }
r[53]=r[3];
goto P_0c0a0cda;
P_0c0a0cda: /* original f32d, guest PC 0x0c0a0cda */
if(!s->budget--) { s->failed_pc=0x0c0a0cdau; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c0a0cdc;
P_0c0a0cdc: /* original f35d, guest PC 0x0c0a0cdc */
if(!s->budget--) { s->failed_pc=0x0c0a0cdcu; return 0; }
fr[3]&=0x7fffffffu;
goto P_0c0a0cde;
P_0c0a0cde: /* original f342, guest PC 0x0c0a0cde */
if(!s->budget--) { s->failed_pc=0x0c0a0cdeu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'*');
goto P_0c0a0ce0;
P_0c0a0ce0: /* original f34d, guest PC 0x0c0a0ce0 */
if(!s->budget--) { s->failed_pc=0x0c0a0ce0u; return 0; }
fr[3]^=0x80000000u;
goto P_0c0a0ce2;
P_0c0a0ce2: /* original f33d, guest PC 0x0c0a0ce2 */
if(!s->budget--) { s->failed_pc=0x0c0a0ce2u; return 0; }
r[53]=truncate_float(fr[3]);
goto P_0c0a0ce4;
P_0c0a0ce4: /* original 035a, guest PC 0x0c0a0ce4 */
if(!s->budget--) { s->failed_pc=0x0c0a0ce4u; return 0; }
r[3]=r[53];
goto P_0c0a0ce6;
P_0c0a0ce6: /* original 0e35, guest PC 0x0c0a0ce6 */
if(!s->budget--) { s->failed_pc=0x0c0a0ce6u; return 0; }
write(ram,r[14]+r[0],r[3],2);
goto P_0c0a0ce8;
P_0c0a0ce8: /* original 9049, guest PC 0x0c0a0ce8 */
if(!s->budget--) { s->failed_pc=0x0c0a0ce8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a0d7eu,2);
goto P_0c0a0cea;
P_0c0a0cea: /* original 03ed, guest PC 0x0c0a0cea */
if(!s->budget--) { s->failed_pc=0x0c0a0ceau; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0a0cec;
P_0c0a0cec: /* original 435a, guest PC 0x0c0a0cec */
if(!s->budget--) { s->failed_pc=0x0c0a0cecu; return 0; }
r[53]=r[3];
goto P_0c0a0cee;
P_0c0a0cee: /* original f32d, guest PC 0x0c0a0cee */
if(!s->budget--) { s->failed_pc=0x0c0a0ceeu; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c0a0cf0;
P_0c0a0cf0: /* original f342, guest PC 0x0c0a0cf0 */
if(!s->budget--) { s->failed_pc=0x0c0a0cf0u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'*');
goto P_0c0a0cf2;
P_0c0a0cf2: /* original f33d, guest PC 0x0c0a0cf2 */
if(!s->budget--) { s->failed_pc=0x0c0a0cf2u; return 0; }
r[53]=truncate_float(fr[3]);
goto P_0c0a0cf4;
P_0c0a0cf4: /* original 035a, guest PC 0x0c0a0cf4 */
if(!s->budget--) { s->failed_pc=0x0c0a0cf4u; return 0; }
r[3]=r[53];
goto P_0c0a0cf6;
P_0c0a0cf6: /* original 0e35, guest PC 0x0c0a0cf6 */
if(!s->budget--) { s->failed_pc=0x0c0a0cf6u; return 0; }
write(ram,r[14]+r[0],r[3],2);
goto P_0c0a0cf8;
P_0c0a0cf8: /* original d323, guest PC 0x0c0a0cf8 */
if(!s->budget--) { s->failed_pc=0x0c0a0cf8u; return 0; }
r[3]=read(ram,0x0c0a0d88u,4);
goto P_0c0a0cfa;
P_0c0a0cfa: /* original 65a3, guest PC 0x0c0a0cfa */
if(!s->budget--) { s->failed_pc=0x0c0a0cfau; return 0; }
r[5]=r[10];
goto P_0c0a0cfc;
P_0c0a0cfc: /* original 430b, guest PC 0x0c0a0cfc */
if(!s->budget--) { s->failed_pc=0x0c0a0cfcu; return 0; }
target=r[3];
r[16]=code_base|0x0c0a0d00u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a0d00u) { target=s->pc; goto dispatch; }
goto P_0c0a0d00;
P_0c0a0cfe: /* original 64e3, guest PC 0x0c0a0cfe */
if(!s->budget--) { s->failed_pc=0x0c0a0cfeu; return 0; }
r[4]=r[14];
goto P_0c0a0d00;
P_0c0a0d00: /* original d222, guest PC 0x0c0a0d00 */
if(!s->budget--) { s->failed_pc=0x0c0a0d00u; return 0; }
r[2]=read(ram,0x0c0a0d8cu,4);
goto P_0c0a0d02;
P_0c0a0d02: /* original 65e3, guest PC 0x0c0a0d02 */
if(!s->budget--) { s->failed_pc=0x0c0a0d02u; return 0; }
r[5]=r[14];
goto P_0c0a0d04;
P_0c0a0d04: /* original 7510, guest PC 0x0c0a0d04 */
if(!s->budget--) { s->failed_pc=0x0c0a0d04u; return 0; }
r[5]+=0x00000010u;
goto P_0c0a0d06;
P_0c0a0d06: /* original 420b, guest PC 0x0c0a0d06 */
if(!s->budget--) { s->failed_pc=0x0c0a0d06u; return 0; }
target=r[2];
r[16]=code_base|0x0c0a0d0au;
r[4]=r[9];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a0d0au) { target=s->pc; goto dispatch; }
goto P_0c0a0d0a;
P_0c0a0d08: /* original 6493, guest PC 0x0c0a0d08 */
if(!s->budget--) { s->failed_pc=0x0c0a0d08u; return 0; }
r[4]=r[9];
goto P_0c0a0d0a;
P_0c0a0d0a: /* original 9339, guest PC 0x0c0a0d0a */
if(!s->budget--) { s->failed_pc=0x0c0a0d0au; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a0d80u,2);
goto P_0c0a0d0c;
P_0c0a0d0c: /* original 3c3c, guest PC 0x0c0a0d0c */
if(!s->budget--) { s->failed_pc=0x0c0a0d0cu; return 0; }
r[12]+=r[3];
goto P_0c0a0d0e;
P_0c0a0d0e: /* original 4810, guest PC 0x0c0a0d0e */
if(!s->budget--) { s->failed_pc=0x0c0a0d0eu; return 0; }
--r[8];
r[17]=(r[17]&~1u)|((r[8]==0)!=0);
goto P_0c0a0d10;
P_0c0a0d10: /* original 7b0c, guest PC 0x0c0a0d10 */
if(!s->budget--) { s->failed_pc=0x0c0a0d10u; return 0; }
r[11]+=0x0000000cu;
goto P_0c0a0d12;
P_0c0a0d12: /* original 8d02, guest PC 0x0c0a0d12 */
if(!s->budget--) { s->failed_pc=0x0c0a0d12u; return 0; }
cond=r[17]&1u;
r[9]+=0x00000040u;
if(cond) { goto P_0c0a0d1a; }
goto P_0c0a0d16;
P_0c0a0d14: /* original 7940, guest PC 0x0c0a0d14 */
if(!s->budget--) { s->failed_pc=0x0c0a0d14u; return 0; }
r[9]+=0x00000040u;
goto P_0c0a0d16;
P_0c0a0d16: /* original af26, guest PC 0x0c0a0d16 */
if(!s->budget--) { s->failed_pc=0x0c0a0d16u; return 0; }
goto P_0c0a0b66;
P_0c0a0d18: /* original 0009, guest PC 0x0c0a0d18 */
if(!s->budget--) { s->failed_pc=0x0c0a0d18u; return 0; }
goto P_0c0a0d1a;
P_0c0a0d1a: /* original 7f20, guest PC 0x0c0a0d1a */
if(!s->budget--) { s->failed_pc=0x0c0a0d1au; return 0; }
r[15]+=0x00000020u;
goto P_0c0a0d1c;
P_0c0a0d1c: /* original 4f26, guest PC 0x0c0a0d1c */
if(!s->budget--) { s->failed_pc=0x0c0a0d1cu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a0d1e;
P_0c0a0d1e: /* original fef9, guest PC 0x0c0a0d1e */
if(!s->budget--) { s->failed_pc=0x0c0a0d1eu; return 0; }
vf3_matrix_load(s,ram,14,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0a0d20;
P_0c0a0d20: /* original fff9, guest PC 0x0c0a0d20 */
if(!s->budget--) { s->failed_pc=0x0c0a0d20u; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0a0d22;
P_0c0a0d22: /* original 68f6, guest PC 0x0c0a0d22 */
if(!s->budget--) { s->failed_pc=0x0c0a0d22u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c0a0d24;
P_0c0a0d24: /* original 69f6, guest PC 0x0c0a0d24 */
if(!s->budget--) { s->failed_pc=0x0c0a0d24u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c0a0d26;
P_0c0a0d26: /* original 6af6, guest PC 0x0c0a0d26 */
if(!s->budget--) { s->failed_pc=0x0c0a0d26u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0a0d28;
P_0c0a0d28: /* original 6bf6, guest PC 0x0c0a0d28 */
if(!s->budget--) { s->failed_pc=0x0c0a0d28u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0a0d2a;
P_0c0a0d2a: /* original 6cf6, guest PC 0x0c0a0d2a */
if(!s->budget--) { s->failed_pc=0x0c0a0d2au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0a0d2c;
P_0c0a0d2c: /* original 6df6, guest PC 0x0c0a0d2c */
if(!s->budget--) { s->failed_pc=0x0c0a0d2cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0a0d2e;
P_0c0a0d2e: /* original 000b, guest PC 0x0c0a0d2e */
if(!s->budget--) { s->failed_pc=0x0c0a0d2eu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0a0d30: /* original 6ef6, guest PC 0x0c0a0d30 */
if(!s->budget--) { s->failed_pc=0x0c0a0d30u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0a0d32u,s,ram);
unsupported: s->failed_pc=target; return 0;
}
