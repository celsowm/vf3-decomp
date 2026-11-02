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
int vf3_away_batch115_adapter_17(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c09571cu: goto P_0c09571c;
case 0x0c09571eu: goto P_0c09571e;
case 0x0c095720u: goto P_0c095720;
case 0x0c095722u: goto P_0c095722;
case 0x0c0968f8u: goto P_0c0968f8;
case 0x0c0968fau: goto P_0c0968fa;
case 0x0c0968fcu: goto P_0c0968fc;
case 0x0c0968feu: goto P_0c0968fe;
case 0x0c096900u: goto P_0c096900;
case 0x0c096944u: goto P_0c096944;
case 0x0c096946u: goto P_0c096946;
case 0x0c096948u: goto P_0c096948;
case 0x0c09694au: goto P_0c09694a;
case 0x0c09694cu: goto P_0c09694c;
case 0x0c09694eu: goto P_0c09694e;
case 0x0c096950u: goto P_0c096950;
case 0x0c096952u: goto P_0c096952;
case 0x0c096954u: goto P_0c096954;
case 0x0c096956u: goto P_0c096956;
case 0x0c096958u: goto P_0c096958;
case 0x0c09695au: goto P_0c09695a;
case 0x0c09695cu: goto P_0c09695c;
case 0x0c09695eu: goto P_0c09695e;
case 0x0c096960u: goto P_0c096960;
case 0x0c096962u: goto P_0c096962;
case 0x0c096964u: goto P_0c096964;
case 0x0c096966u: goto P_0c096966;
case 0x0c096968u: goto P_0c096968;
case 0x0c09696au: goto P_0c09696a;
case 0x0c09696cu: goto P_0c09696c;
case 0x0c09696eu: goto P_0c09696e;
case 0x0c096970u: goto P_0c096970;
case 0x0c096972u: goto P_0c096972;
case 0x0c096974u: goto P_0c096974;
case 0x0c096976u: goto P_0c096976;
case 0x0c096978u: goto P_0c096978;
case 0x0c09697au: goto P_0c09697a;
case 0x0c09697cu: goto P_0c09697c;
case 0x0c09697eu: goto P_0c09697e;
case 0x0c096980u: goto P_0c096980;
case 0x0c096982u: goto P_0c096982;
case 0x0c096984u: goto P_0c096984;
case 0x0c096986u: goto P_0c096986;
case 0x0c096988u: goto P_0c096988;
case 0x0c09698au: goto P_0c09698a;
case 0x0c09698cu: goto P_0c09698c;
case 0x0c09698eu: goto P_0c09698e;
case 0x0c096990u: goto P_0c096990;
case 0x0c096992u: goto P_0c096992;
case 0x0c096994u: goto P_0c096994;
case 0x0c096996u: goto P_0c096996;
case 0x0c096998u: goto P_0c096998;
case 0x0c09699au: goto P_0c09699a;
case 0x0c09699cu: goto P_0c09699c;
case 0x0c09699eu: goto P_0c09699e;
case 0x0c0969a0u: goto P_0c0969a0;
case 0x0c0969a2u: goto P_0c0969a2;
case 0x0c0969a4u: goto P_0c0969a4;
case 0x0c0969a6u: goto P_0c0969a6;
case 0x0c0969a8u: goto P_0c0969a8;
case 0x0c0969aau: goto P_0c0969aa;
case 0x0c0969acu: goto P_0c0969ac;
case 0x0c0969aeu: goto P_0c0969ae;
case 0x0c0969b0u: goto P_0c0969b0;
case 0x0c0969b2u: goto P_0c0969b2;
case 0x0c0969b4u: goto P_0c0969b4;
case 0x0c0969b6u: goto P_0c0969b6;
case 0x0c0969b8u: goto P_0c0969b8;
case 0x0c0969bau: goto P_0c0969ba;
case 0x0c0969bcu: goto P_0c0969bc;
case 0x0c0969beu: goto P_0c0969be;
case 0x0c0969c0u: goto P_0c0969c0;
case 0x0c0969c2u: goto P_0c0969c2;
case 0x0c0969c4u: goto P_0c0969c4;
case 0x0c0969c6u: goto P_0c0969c6;
case 0x0c0969c8u: goto P_0c0969c8;
case 0x0c0969cau: goto P_0c0969ca;
case 0x0c0969ccu: goto P_0c0969cc;
case 0x0c0969ceu: goto P_0c0969ce;
case 0x0c0969d0u: goto P_0c0969d0;
case 0x0c0969d2u: goto P_0c0969d2;
case 0x0c0969d4u: goto P_0c0969d4;
case 0x0c0969d6u: goto P_0c0969d6;
case 0x0c0969d8u: goto P_0c0969d8;
case 0x0c0969dau: goto P_0c0969da;
case 0x0c0969dcu: goto P_0c0969dc;
case 0x0c0969deu: goto P_0c0969de;
case 0x0c0969e0u: goto P_0c0969e0;
case 0x0c0969e2u: goto P_0c0969e2;
case 0x0c0969e4u: goto P_0c0969e4;
case 0x0c0969e6u: goto P_0c0969e6;
case 0x0c0969e8u: goto P_0c0969e8;
case 0x0c0969eau: goto P_0c0969ea;
case 0x0c0969ecu: goto P_0c0969ec;
case 0x0c0969eeu: goto P_0c0969ee;
case 0x0c0969f0u: goto P_0c0969f0;
case 0x0c0969f2u: goto P_0c0969f2;
case 0x0c0969f4u: goto P_0c0969f4;
case 0x0c0969f6u: goto P_0c0969f6;
case 0x0c0969f8u: goto P_0c0969f8;
case 0x0c0969fau: goto P_0c0969fa;
case 0x0c0969fcu: goto P_0c0969fc;
case 0x0c0969feu: goto P_0c0969fe;
case 0x0c096a00u: goto P_0c096a00;
case 0x0c096a02u: goto P_0c096a02;
case 0x0c096a04u: goto P_0c096a04;
case 0x0c096a06u: goto P_0c096a06;
case 0x0c096a08u: goto P_0c096a08;
case 0x0c096a0au: goto P_0c096a0a;
case 0x0c096a0cu: goto P_0c096a0c;
case 0x0c096a0eu: goto P_0c096a0e;
case 0x0c096a10u: goto P_0c096a10;
case 0x0c096a12u: goto P_0c096a12;
case 0x0c096a14u: goto P_0c096a14;
case 0x0c096a16u: goto P_0c096a16;
case 0x0c096a18u: goto P_0c096a18;
case 0x0c096a1au: goto P_0c096a1a;
case 0x0c096a1cu: goto P_0c096a1c;
case 0x0c096a1eu: goto P_0c096a1e;
case 0x0c096a20u: goto P_0c096a20;
case 0x0c096a22u: goto P_0c096a22;
case 0x0c096a50u: goto P_0c096a50;
case 0x0c096a52u: goto P_0c096a52;
case 0x0c096a54u: goto P_0c096a54;
case 0x0c096a56u: goto P_0c096a56;
case 0x0c096a58u: goto P_0c096a58;
case 0x0c096a5au: goto P_0c096a5a;
case 0x0c096a5cu: goto P_0c096a5c;
case 0x0c096a5eu: goto P_0c096a5e;
case 0x0c096a60u: goto P_0c096a60;
case 0x0c096a62u: goto P_0c096a62;
case 0x0c096a64u: goto P_0c096a64;
case 0x0c096a66u: goto P_0c096a66;
case 0x0c096a68u: goto P_0c096a68;
case 0x0c096a6au: goto P_0c096a6a;
case 0x0c096a6cu: goto P_0c096a6c;
case 0x0c096a6eu: goto P_0c096a6e;
case 0x0c096a70u: goto P_0c096a70;
case 0x0c096a72u: goto P_0c096a72;
case 0x0c096a74u: goto P_0c096a74;
case 0x0c096a76u: goto P_0c096a76;
case 0x0c096a78u: goto P_0c096a78;
case 0x0c096a7au: goto P_0c096a7a;
case 0x0c096a7cu: goto P_0c096a7c;
case 0x0c096a7eu: goto P_0c096a7e;
case 0x0c096a80u: goto P_0c096a80;
case 0x0c096a82u: goto P_0c096a82;
case 0x0c096a84u: goto P_0c096a84;
case 0x0c096a86u: goto P_0c096a86;
case 0x0c096a88u: goto P_0c096a88;
case 0x0c096a8au: goto P_0c096a8a;
case 0x0c096a8cu: goto P_0c096a8c;
case 0x0c096a8eu: goto P_0c096a8e;
case 0x0c096a90u: goto P_0c096a90;
case 0x0c096a92u: goto P_0c096a92;
case 0x0c096a94u: goto P_0c096a94;
case 0x0c096a96u: goto P_0c096a96;
case 0x0c096a98u: goto P_0c096a98;
case 0x0c096a9au: goto P_0c096a9a;
case 0x0c096a9cu: goto P_0c096a9c;
case 0x0c096a9eu: goto P_0c096a9e;
case 0x0c096aa0u: goto P_0c096aa0;
case 0x0c096aa2u: goto P_0c096aa2;
case 0x0c096aa4u: goto P_0c096aa4;
case 0x0c096aa6u: goto P_0c096aa6;
case 0x0c096aa8u: goto P_0c096aa8;
case 0x0c096aaau: goto P_0c096aaa;
case 0x0c096aacu: goto P_0c096aac;
case 0x0c096aaeu: goto P_0c096aae;
case 0x0c096ab0u: goto P_0c096ab0;
case 0x0c096ab2u: goto P_0c096ab2;
case 0x0c096ab4u: goto P_0c096ab4;
case 0x0c096ab6u: goto P_0c096ab6;
case 0x0c096ab8u: goto P_0c096ab8;
case 0x0c096abau: goto P_0c096aba;
case 0x0c096abcu: goto P_0c096abc;
case 0x0c096abeu: goto P_0c096abe;
case 0x0c096ac0u: goto P_0c096ac0;
case 0x0c096ac2u: goto P_0c096ac2;
case 0x0c096ac4u: goto P_0c096ac4;
case 0x0c096ac6u: goto P_0c096ac6;
case 0x0c096ac8u: goto P_0c096ac8;
case 0x0c096acau: goto P_0c096aca;
case 0x0c096accu: goto P_0c096acc;
case 0x0c096aceu: goto P_0c096ace;
case 0x0c096ad0u: goto P_0c096ad0;
case 0x0c096ad2u: goto P_0c096ad2;
case 0x0c096ad4u: goto P_0c096ad4;
case 0x0c096ad6u: goto P_0c096ad6;
case 0x0c096afcu: goto P_0c096afc;
case 0x0c096afeu: goto P_0c096afe;
case 0x0c096b00u: goto P_0c096b00;
case 0x0c096b02u: goto P_0c096b02;
case 0x0c096b04u: goto P_0c096b04;
case 0x0c096b06u: goto P_0c096b06;
case 0x0c096b08u: goto P_0c096b08;
case 0x0c096b0au: goto P_0c096b0a;
case 0x0c096b0cu: goto P_0c096b0c;
case 0x0c096b0eu: goto P_0c096b0e;
case 0x0c096b10u: goto P_0c096b10;
case 0x0c096b12u: goto P_0c096b12;
case 0x0c096b14u: goto P_0c096b14;
case 0x0c096b16u: goto P_0c096b16;
case 0x0c096b18u: goto P_0c096b18;
case 0x0c096b1au: goto P_0c096b1a;
case 0x0c096b1cu: goto P_0c096b1c;
case 0x0c096b1eu: goto P_0c096b1e;
case 0x0c096b20u: goto P_0c096b20;
case 0x0c096b22u: goto P_0c096b22;
case 0x0c096b24u: goto P_0c096b24;
case 0x0c096b26u: goto P_0c096b26;
case 0x0c096b28u: goto P_0c096b28;
case 0x0c096b2au: goto P_0c096b2a;
case 0x0c096b2cu: goto P_0c096b2c;
case 0x0c096b2eu: goto P_0c096b2e;
case 0x0c096b30u: goto P_0c096b30;
case 0x0c096b32u: goto P_0c096b32;
case 0x0c096b34u: goto P_0c096b34;
case 0x0c096b36u: goto P_0c096b36;
case 0x0c096b38u: goto P_0c096b38;
case 0x0c096b3au: goto P_0c096b3a;
case 0x0c096b3cu: goto P_0c096b3c;
case 0x0c096b3eu: goto P_0c096b3e;
case 0x0c096b40u: goto P_0c096b40;
case 0x0c096b42u: goto P_0c096b42;
case 0x0c096b44u: goto P_0c096b44;
case 0x0c096b46u: goto P_0c096b46;
case 0x0c096b48u: goto P_0c096b48;
case 0x0c096b4au: goto P_0c096b4a;
case 0x0c096b4cu: goto P_0c096b4c;
case 0x0c096b4eu: goto P_0c096b4e;
case 0x0c096b50u: goto P_0c096b50;
case 0x0c096b52u: goto P_0c096b52;
case 0x0c096b54u: goto P_0c096b54;
case 0x0c096b56u: goto P_0c096b56;
case 0x0c096b58u: goto P_0c096b58;
case 0x0c096b5au: goto P_0c096b5a;
case 0x0c096b5cu: goto P_0c096b5c;
case 0x0c096b5eu: goto P_0c096b5e;
case 0x0c096b60u: goto P_0c096b60;
case 0x0c096b62u: goto P_0c096b62;
case 0x0c096b64u: goto P_0c096b64;
case 0x0c096b66u: goto P_0c096b66;
case 0x0c096b68u: goto P_0c096b68;
case 0x0c096b6au: goto P_0c096b6a;
case 0x0c096b6cu: goto P_0c096b6c;
case 0x0c096b6eu: goto P_0c096b6e;
case 0x0c096b70u: goto P_0c096b70;
case 0x0c096b72u: goto P_0c096b72;
case 0x0c096b74u: goto P_0c096b74;
case 0x0c096b76u: goto P_0c096b76;
case 0x0c096b78u: goto P_0c096b78;
case 0x0c096b7au: goto P_0c096b7a;
case 0x0c096b7cu: goto P_0c096b7c;
case 0x0c096b7eu: goto P_0c096b7e;
case 0x0c096b80u: goto P_0c096b80;
case 0x0c096b82u: goto P_0c096b82;
case 0x0c096b84u: goto P_0c096b84;
case 0x0c096b86u: goto P_0c096b86;
case 0x0c096b88u: goto P_0c096b88;
case 0x0c096b8au: goto P_0c096b8a;
case 0x0c096b8cu: goto P_0c096b8c;
case 0x0c096b8eu: goto P_0c096b8e;
case 0x0c096b90u: goto P_0c096b90;
case 0x0c096b92u: goto P_0c096b92;
case 0x0c096b94u: goto P_0c096b94;
case 0x0c096b96u: goto P_0c096b96;
case 0x0c096b98u: goto P_0c096b98;
case 0x0c096b9au: goto P_0c096b9a;
case 0x0c096b9cu: goto P_0c096b9c;
case 0x0c096b9eu: goto P_0c096b9e;
case 0x0c096ba0u: goto P_0c096ba0;
case 0x0c096ba2u: goto P_0c096ba2;
case 0x0c096ba4u: goto P_0c096ba4;
case 0x0c096ba6u: goto P_0c096ba6;
case 0x0c096ba8u: goto P_0c096ba8;
case 0x0c096baau: goto P_0c096baa;
case 0x0c096bacu: goto P_0c096bac;
case 0x0c096baeu: goto P_0c096bae;
case 0x0c096bb0u: goto P_0c096bb0;
case 0x0c096bb2u: goto P_0c096bb2;
case 0x0c096bb4u: goto P_0c096bb4;
case 0x0c096bb6u: goto P_0c096bb6;
case 0x0c096bb8u: goto P_0c096bb8;
case 0x0c096bbau: goto P_0c096bba;
case 0x0c096bbcu: goto P_0c096bbc;
case 0x0c096bbeu: goto P_0c096bbe;
case 0x0c096bc0u: goto P_0c096bc0;
case 0x0c096bc2u: goto P_0c096bc2;
case 0x0c096bc4u: goto P_0c096bc4;
case 0x0c096bc6u: goto P_0c096bc6;
case 0x0c096bc8u: goto P_0c096bc8;
case 0x0c096bcau: goto P_0c096bca;
case 0x0c096bccu: goto P_0c096bcc;
case 0x0c096bceu: goto P_0c096bce;
case 0x0c096bd0u: goto P_0c096bd0;
case 0x0c096bd2u: goto P_0c096bd2;
case 0x0c096bd4u: goto P_0c096bd4;
case 0x0c096bd6u: goto P_0c096bd6;
case 0x0c096bd8u: goto P_0c096bd8;
case 0x0c096bdau: goto P_0c096bda;
case 0x0c096bdcu: goto P_0c096bdc;
case 0x0c096bdeu: goto P_0c096bde;
case 0x0c096be0u: goto P_0c096be0;
case 0x0c096be2u: goto P_0c096be2;
case 0x0c096be4u: goto P_0c096be4;
case 0x0c096be6u: goto P_0c096be6;
case 0x0c096be8u: goto P_0c096be8;
case 0x0c096beau: goto P_0c096bea;
case 0x0c096becu: goto P_0c096bec;
case 0x0c096beeu: goto P_0c096bee;
case 0x0c096bf0u: goto P_0c096bf0;
case 0x0c096bf2u: goto P_0c096bf2;
case 0x0c096bf4u: goto P_0c096bf4;
case 0x0c096bf6u: goto P_0c096bf6;
case 0x0c096bf8u: goto P_0c096bf8;
case 0x0c096bfau: goto P_0c096bfa;
case 0x0c096bfcu: goto P_0c096bfc;
case 0x0c096bfeu: goto P_0c096bfe;
case 0x0c096c00u: goto P_0c096c00;
case 0x0c096c02u: goto P_0c096c02;
case 0x0c096c04u: goto P_0c096c04;
case 0x0c096c06u: goto P_0c096c06;
case 0x0c096c08u: goto P_0c096c08;
case 0x0c096c0au: goto P_0c096c0a;
case 0x0c096c0cu: goto P_0c096c0c;
case 0x0c096c0eu: goto P_0c096c0e;
case 0x0c096c10u: goto P_0c096c10;
case 0x0c096c12u: goto P_0c096c12;
case 0x0c096c14u: goto P_0c096c14;
case 0x0c096c16u: goto P_0c096c16;
case 0x0c096c18u: goto P_0c096c18;
case 0x0c096c1au: goto P_0c096c1a;
case 0x0c096c1cu: goto P_0c096c1c;
case 0x0c096c1eu: goto P_0c096c1e;
case 0x0c096c20u: goto P_0c096c20;
case 0x0c096c22u: goto P_0c096c22;
case 0x0c096c24u: goto P_0c096c24;
case 0x0c096c26u: goto P_0c096c26;
case 0x0c096c28u: goto P_0c096c28;
case 0x0c096c2au: goto P_0c096c2a;
case 0x0c096c2cu: goto P_0c096c2c;
case 0x0c096c2eu: goto P_0c096c2e;
case 0x0c096c30u: goto P_0c096c30;
case 0x0c096c32u: goto P_0c096c32;
case 0x0c096c34u: goto P_0c096c34;
case 0x0c096c36u: goto P_0c096c36;
case 0x0c096c38u: goto P_0c096c38;
case 0x0c096c3au: goto P_0c096c3a;
case 0x0c096c3cu: goto P_0c096c3c;
case 0x0c096c3eu: goto P_0c096c3e;
case 0x0c096c40u: goto P_0c096c40;
case 0x0c096c42u: goto P_0c096c42;
case 0x0c096c44u: goto P_0c096c44;
case 0x0c096c46u: goto P_0c096c46;
case 0x0c096c48u: goto P_0c096c48;
case 0x0c096c4au: goto P_0c096c4a;
case 0x0c096c4cu: goto P_0c096c4c;
case 0x0c096c4eu: goto P_0c096c4e;
case 0x0c096c50u: goto P_0c096c50;
case 0x0c096c52u: goto P_0c096c52;
case 0x0c096c54u: goto P_0c096c54;
case 0x0c096c56u: goto P_0c096c56;
case 0x0c096c58u: goto P_0c096c58;
case 0x0c096c5au: goto P_0c096c5a;
case 0x0c096c5cu: goto P_0c096c5c;
case 0x0c096c5eu: goto P_0c096c5e;
case 0x0c096cb4u: goto P_0c096cb4;
case 0x0c096cb6u: goto P_0c096cb6;
case 0x0c096cb8u: goto P_0c096cb8;
case 0x0c096cbau: goto P_0c096cba;
case 0x0c096cbcu: goto P_0c096cbc;
case 0x0c096cbeu: goto P_0c096cbe;
case 0x0c096cc0u: goto P_0c096cc0;
case 0x0c096cc2u: goto P_0c096cc2;
case 0x0c096cc4u: goto P_0c096cc4;
case 0x0c096cc6u: goto P_0c096cc6;
case 0x0c096cc8u: goto P_0c096cc8;
case 0x0c096ccau: goto P_0c096cca;
case 0x0c096cccu: goto P_0c096ccc;
case 0x0c096cceu: goto P_0c096cce;
case 0x0c096cd0u: goto P_0c096cd0;
case 0x0c096cd2u: goto P_0c096cd2;
case 0x0c096cd4u: goto P_0c096cd4;
case 0x0c096cd6u: goto P_0c096cd6;
case 0x0c096cd8u: goto P_0c096cd8;
case 0x0c096cdau: goto P_0c096cda;
case 0x0c096cdcu: goto P_0c096cdc;
case 0x0c096cdeu: goto P_0c096cde;
case 0x0c096ce0u: goto P_0c096ce0;
case 0x0c096ce2u: goto P_0c096ce2;
case 0x0c096ce4u: goto P_0c096ce4;
case 0x0c096ce6u: goto P_0c096ce6;
case 0x0c096ce8u: goto P_0c096ce8;
case 0x0c096ceau: goto P_0c096cea;
case 0x0c096cecu: goto P_0c096cec;
case 0x0c096ceeu: goto P_0c096cee;
case 0x0c096cf0u: goto P_0c096cf0;
case 0x0c096cf2u: goto P_0c096cf2;
case 0x0c096cf4u: goto P_0c096cf4;
case 0x0c096cf6u: goto P_0c096cf6;
case 0x0c096cf8u: goto P_0c096cf8;
case 0x0c096cfau: goto P_0c096cfa;
case 0x0c096cfcu: goto P_0c096cfc;
case 0x0c096cfeu: goto P_0c096cfe;
case 0x0c096d00u: goto P_0c096d00;
case 0x0c096d02u: goto P_0c096d02;
case 0x0c096d04u: goto P_0c096d04;
case 0x0c096d06u: goto P_0c096d06;
case 0x0c096d08u: goto P_0c096d08;
case 0x0c096d0au: goto P_0c096d0a;
case 0x0c096d0cu: goto P_0c096d0c;
case 0x0c096d0eu: goto P_0c096d0e;
case 0x0c096d10u: goto P_0c096d10;
case 0x0c096d12u: goto P_0c096d12;
case 0x0c096d14u: goto P_0c096d14;
case 0x0c096d16u: goto P_0c096d16;
case 0x0c096d18u: goto P_0c096d18;
case 0x0c096d1au: goto P_0c096d1a;
case 0x0c096d1cu: goto P_0c096d1c;
case 0x0c096d1eu: goto P_0c096d1e;
case 0x0c096d20u: goto P_0c096d20;
case 0x0c096d22u: goto P_0c096d22;
case 0x0c096d24u: goto P_0c096d24;
case 0x0c096d26u: goto P_0c096d26;
case 0x0c096d28u: goto P_0c096d28;
case 0x0c096d2au: goto P_0c096d2a;
case 0x0c096d2cu: goto P_0c096d2c;
case 0x0c096d2eu: goto P_0c096d2e;
case 0x0c096d30u: goto P_0c096d30;
case 0x0c096d32u: goto P_0c096d32;
case 0x0c096d34u: goto P_0c096d34;
case 0x0c096d36u: goto P_0c096d36;
case 0x0c096d38u: goto P_0c096d38;
case 0x0c096d3au: goto P_0c096d3a;
case 0x0c096d3cu: goto P_0c096d3c;
case 0x0c096d3eu: goto P_0c096d3e;
case 0x0c096d40u: goto P_0c096d40;
case 0x0c096d42u: goto P_0c096d42;
case 0x0c096d44u: goto P_0c096d44;
case 0x0c096d46u: goto P_0c096d46;
case 0x0c096d48u: goto P_0c096d48;
case 0x0c096d4au: goto P_0c096d4a;
case 0x0c096d4cu: goto P_0c096d4c;
case 0x0c096d4eu: goto P_0c096d4e;
case 0x0c096d50u: goto P_0c096d50;
case 0x0c096d52u: goto P_0c096d52;
case 0x0c096d54u: goto P_0c096d54;
case 0x0c096d56u: goto P_0c096d56;
case 0x0c096d58u: goto P_0c096d58;
case 0x0c096d5au: goto P_0c096d5a;
case 0x0c096d5cu: goto P_0c096d5c;
case 0x0c0a2b98u: goto P_0c0a2b98;
case 0x0c0a2b9au: goto P_0c0a2b9a;
case 0x0c0a2b9cu: goto P_0c0a2b9c;
case 0x0c0a2b9eu: goto P_0c0a2b9e;
case 0x0c0a2ba0u: goto P_0c0a2ba0;
case 0x0c0a2ba2u: goto P_0c0a2ba2;
case 0x0c0a2ba4u: goto P_0c0a2ba4;
case 0x0c0a2ba6u: goto P_0c0a2ba6;
case 0x0c0a2ba8u: goto P_0c0a2ba8;
case 0x0c0a2baau: goto P_0c0a2baa;
case 0x0c0a2bacu: goto P_0c0a2bac;
case 0x0c0a2baeu: goto P_0c0a2bae;
case 0x0c0a2bb0u: goto P_0c0a2bb0;
case 0x0c0a2bb2u: goto P_0c0a2bb2;
case 0x0c0a2bb4u: goto P_0c0a2bb4;
case 0x0c0a2bb6u: goto P_0c0a2bb6;
case 0x0c0a2bb8u: goto P_0c0a2bb8;
case 0x0c0a2bbau: goto P_0c0a2bba;
case 0x0c0a2bbcu: goto P_0c0a2bbc;
case 0x0c0a2bbeu: goto P_0c0a2bbe;
case 0x0c0a2bc0u: goto P_0c0a2bc0;
case 0x0c0a2bc2u: goto P_0c0a2bc2;
case 0x0c0a2bc4u: goto P_0c0a2bc4;
case 0x0c0a2bc6u: goto P_0c0a2bc6;
case 0x0c0a2bc8u: goto P_0c0a2bc8;
case 0x0c0a2bcau: goto P_0c0a2bca;
case 0x0c0a2bccu: goto P_0c0a2bcc;
case 0x0c0a2bceu: goto P_0c0a2bce;
case 0x0c0a2bd0u: goto P_0c0a2bd0;
case 0x0c0a2bd2u: goto P_0c0a2bd2;
case 0x0c0a2bd4u: goto P_0c0a2bd4;
case 0x0c0a2bd6u: goto P_0c0a2bd6;
case 0x0c0a2bd8u: goto P_0c0a2bd8;
case 0x0c0a2bdau: goto P_0c0a2bda;
case 0x0c0a2bdcu: goto P_0c0a2bdc;
case 0x0c0a2bdeu: goto P_0c0a2bde;
case 0x0c0a2be0u: goto P_0c0a2be0;
case 0x0c0a2be2u: goto P_0c0a2be2;
case 0x0c0a2be4u: goto P_0c0a2be4;
case 0x0c0a2be6u: goto P_0c0a2be6;
case 0x0c0a2be8u: goto P_0c0a2be8;
case 0x0c0a2beau: goto P_0c0a2bea;
case 0x0c0a2becu: goto P_0c0a2bec;
case 0x0c0a2beeu: goto P_0c0a2bee;
case 0x0c0a2bf0u: goto P_0c0a2bf0;
case 0x0c0a2bf2u: goto P_0c0a2bf2;
case 0x0c0a2bf4u: goto P_0c0a2bf4;
case 0x0c0a2bf6u: goto P_0c0a2bf6;
case 0x0c0a2bf8u: goto P_0c0a2bf8;
case 0x0c0a2bfau: goto P_0c0a2bfa;
case 0x0c0a2bfcu: goto P_0c0a2bfc;
case 0x0c0a2bfeu: goto P_0c0a2bfe;
case 0x0c0a2c00u: goto P_0c0a2c00;
case 0x0c0a2c02u: goto P_0c0a2c02;
case 0x0c0a2c04u: goto P_0c0a2c04;
case 0x0c0a2c06u: goto P_0c0a2c06;
case 0x0c0a2c08u: goto P_0c0a2c08;
case 0x0c0a2c0au: goto P_0c0a2c0a;
case 0x0c0a2c0cu: goto P_0c0a2c0c;
case 0x0c0a2c0eu: goto P_0c0a2c0e;
case 0x0c0a2c10u: goto P_0c0a2c10;
case 0x0c0a2c12u: goto P_0c0a2c12;
case 0x0c0a2c14u: goto P_0c0a2c14;
case 0x0c0a2c16u: goto P_0c0a2c16;
case 0x0c0a2c18u: goto P_0c0a2c18;
case 0x0c0a2c1au: goto P_0c0a2c1a;
case 0x0c0a2c1cu: goto P_0c0a2c1c;
case 0x0c0a2c1eu: goto P_0c0a2c1e;
case 0x0c0a2c20u: goto P_0c0a2c20;
case 0x0c0a2c22u: goto P_0c0a2c22;
case 0x0c0a2c24u: goto P_0c0a2c24;
case 0x0c0a2c26u: goto P_0c0a2c26;
case 0x0c0a2c28u: goto P_0c0a2c28;
case 0x0c0a2c2au: goto P_0c0a2c2a;
case 0x0c0a2c2cu: goto P_0c0a2c2c;
case 0x0c0a2c2eu: goto P_0c0a2c2e;
case 0x0c0a2c30u: goto P_0c0a2c30;
case 0x0c0a2c32u: goto P_0c0a2c32;
case 0x0c0a2c34u: goto P_0c0a2c34;
default: return vf3_matrix_family(target,s,ram);
}
P_0c09571c: /* original d21c, guest PC 0x0c09571c */
if(!s->budget--) { s->failed_pc=0x0c09571cu; return 0; }
r[2]=read(ram,0x0c095790u,4);
goto P_0c09571e;
P_0c09571e: /* original 6322, guest PC 0x0c09571e */
if(!s->budget--) { s->failed_pc=0x0c09571eu; return 0; }
tmp=read(ram,r[2],4);
r[3]=tmp;
goto P_0c095720;
P_0c095720: /* original 432b, guest PC 0x0c095720 */
if(!s->budget--) { s->failed_pc=0x0c095720u; return 0; }
target=r[3];
r[4]=0x00000001u;
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
P_0c095722: /* original e401, guest PC 0x0c095722 */
if(!s->budget--) { s->failed_pc=0x0c095722u; return 0; }
r[4]=0x00000001u;
if(!vf3_matrix_family(0x0c095724u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c095724u; return 0; } return 1;
P_0c0968f8: /* original 6142, guest PC 0x0c0968f8 */
if(!s->budget--) { s->failed_pc=0x0c0968f8u; return 0; }
tmp=read(ram,r[4],4);
r[1]=tmp;
goto P_0c0968fa;
P_0c0968fa: /* original e3fe, guest PC 0x0c0968fa */
if(!s->budget--) { s->failed_pc=0x0c0968fau; return 0; }
r[3]=0xfffffffeu;
goto P_0c0968fc;
P_0c0968fc: /* original 2139, guest PC 0x0c0968fc */
if(!s->budget--) { s->failed_pc=0x0c0968fcu; return 0; }
r[1]&=r[3];
goto P_0c0968fe;
P_0c0968fe: /* original 000b, guest PC 0x0c0968fe */
if(!s->budget--) { s->failed_pc=0x0c0968feu; return 0; }
target=r[16];
write(ram,r[4],r[1],4);
s->pc=target; return ram->oob==0;
P_0c096900: /* original 2412, guest PC 0x0c096900 */
if(!s->budget--) { s->failed_pc=0x0c096900u; return 0; }
write(ram,r[4],r[1],4);
if(!vf3_matrix_family(0x0c096902u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c096902u; return 0; } return 1;
P_0c096944: /* original 2fe6, guest PC 0x0c096944 */
if(!s->budget--) { s->failed_pc=0x0c096944u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c096946;
P_0c096946: /* original e600, guest PC 0x0c096946 */
if(!s->budget--) { s->failed_pc=0x0c096946u; return 0; }
r[6]=0x00000000u;
goto P_0c096948;
P_0c096948: /* original 2fd6, guest PC 0x0c096948 */
if(!s->budget--) { s->failed_pc=0x0c096948u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09694a;
P_0c09694a: /* original 6563, guest PC 0x0c09694a */
if(!s->budget--) { s->failed_pc=0x0c09694au; return 0; }
r[5]=r[6];
goto P_0c09694c;
P_0c09694c: /* original 2fc6, guest PC 0x0c09694c */
if(!s->budget--) { s->failed_pc=0x0c09694cu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09694e;
P_0c09694e: /* original 2fb6, guest PC 0x0c09694e */
if(!s->budget--) { s->failed_pc=0x0c09694eu; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c096950;
P_0c096950: /* original 2fa6, guest PC 0x0c096950 */
if(!s->budget--) { s->failed_pc=0x0c096950u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c096952;
P_0c096952: /* original 2f96, guest PC 0x0c096952 */
if(!s->budget--) { s->failed_pc=0x0c096952u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c096954;
P_0c096954: /* original 2f86, guest PC 0x0c096954 */
if(!s->budget--) { s->failed_pc=0x0c096954u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c096956;
P_0c096956: /* original fffb, guest PC 0x0c096956 */
if(!s->budget--) { s->failed_pc=0x0c096956u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c096958;
P_0c096958: /* original 4f22, guest PC 0x0c096958 */
if(!s->budget--) { s->failed_pc=0x0c096958u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c09695a;
P_0c09695a: /* original d336, guest PC 0x0c09695a */
if(!s->budget--) { s->failed_pc=0x0c09695au; return 0; }
r[3]=read(ram,0x0c096a34u,4);
goto P_0c09695c;
P_0c09695c: /* original de34, guest PC 0x0c09695c */
if(!s->budget--) { s->failed_pc=0x0c09695cu; return 0; }
r[14]=read(ram,0x0c096a30u,4);
goto P_0c09695e;
P_0c09695e: /* original 430b, guest PC 0x0c09695e */
if(!s->budget--) { s->failed_pc=0x0c09695eu; return 0; }
target=r[3];
r[16]=code_base|0x0c096962u;
r[4]=r[6];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c096962u) { target=s->pc; goto dispatch; }
goto P_0c096962;
P_0c096960: /* original 6463, guest PC 0x0c096960 */
if(!s->budget--) { s->failed_pc=0x0c096960u; return 0; }
r[4]=r[6];
goto P_0c096962;
P_0c096962: /* original e600, guest PC 0x0c096962 */
if(!s->budget--) { s->failed_pc=0x0c096962u; return 0; }
r[6]=0x00000000u;
goto P_0c096964;
P_0c096964: /* original d234, guest PC 0x0c096964 */
if(!s->budget--) { s->failed_pc=0x0c096964u; return 0; }
r[2]=read(ram,0x0c096a38u,4);
goto P_0c096966;
P_0c096966: /* original ff8d, guest PC 0x0c096966 */
if(!s->budget--) { s->failed_pc=0x0c096966u; return 0; }
fr[15]=0;
goto P_0c096968;
P_0c096968: /* original 6563, guest PC 0x0c096968 */
if(!s->budget--) { s->failed_pc=0x0c096968u; return 0; }
r[5]=r[6];
goto P_0c09696a;
P_0c09696a: /* original f5fc, guest PC 0x0c09696a */
if(!s->budget--) { s->failed_pc=0x0c09696au; return 0; }
vf3_matrix_move(s,5,15);
goto P_0c09696c;
P_0c09696c: /* original f4fc, guest PC 0x0c09696c */
if(!s->budget--) { s->failed_pc=0x0c09696cu; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c09696e;
P_0c09696e: /* original 420b, guest PC 0x0c09696e */
if(!s->budget--) { s->failed_pc=0x0c09696eu; return 0; }
target=r[2];
r[16]=code_base|0x0c096972u;
r[4]=r[6];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c096972u) { target=s->pc; goto dispatch; }
goto P_0c096972;
P_0c096970: /* original 6463, guest PC 0x0c096970 */
if(!s->budget--) { s->failed_pc=0x0c096970u; return 0; }
r[4]=r[6];
goto P_0c096972;
P_0c096972: /* original d332, guest PC 0x0c096972 */
if(!s->budget--) { s->failed_pc=0x0c096972u; return 0; }
r[3]=read(ram,0x0c096a3cu,4);
goto P_0c096974;
P_0c096974: /* original 430b, guest PC 0x0c096974 */
if(!s->budget--) { s->failed_pc=0x0c096974u; return 0; }
target=r[3];
r[16]=code_base|0x0c096978u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c096978u) { target=s->pc; goto dispatch; }
goto P_0c096978;
P_0c096976: /* original 0009, guest PC 0x0c096976 */
if(!s->budget--) { s->failed_pc=0x0c096976u; return 0; }
goto P_0c096978;
P_0c096978: /* original d22e, guest PC 0x0c096978 */
if(!s->budget--) { s->failed_pc=0x0c096978u; return 0; }
r[2]=read(ram,0x0c096a34u,4);
goto P_0c09697a;
P_0c09697a: /* original e600, guest PC 0x0c09697a */
if(!s->budget--) { s->failed_pc=0x0c09697au; return 0; }
r[6]=0x00000000u;
goto P_0c09697c;
P_0c09697c: /* original 6563, guest PC 0x0c09697c */
if(!s->budget--) { s->failed_pc=0x0c09697cu; return 0; }
r[5]=r[6];
goto P_0c09697e;
P_0c09697e: /* original 420b, guest PC 0x0c09697e */
if(!s->budget--) { s->failed_pc=0x0c09697eu; return 0; }
target=r[2];
r[16]=code_base|0x0c096982u;
r[4]=r[6];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c096982u) { target=s->pc; goto dispatch; }
goto P_0c096982;
P_0c096980: /* original 6463, guest PC 0x0c096980 */
if(!s->budget--) { s->failed_pc=0x0c096980u; return 0; }
r[4]=r[6];
goto P_0c096982;
P_0c096982: /* original e600, guest PC 0x0c096982 */
if(!s->budget--) { s->failed_pc=0x0c096982u; return 0; }
r[6]=0x00000000u;
goto P_0c096984;
P_0c096984: /* original d32c, guest PC 0x0c096984 */
if(!s->budget--) { s->failed_pc=0x0c096984u; return 0; }
r[3]=read(ram,0x0c096a38u,4);
goto P_0c096986;
P_0c096986: /* original f5fc, guest PC 0x0c096986 */
if(!s->budget--) { s->failed_pc=0x0c096986u; return 0; }
vf3_matrix_move(s,5,15);
goto P_0c096988;
P_0c096988: /* original 6563, guest PC 0x0c096988 */
if(!s->budget--) { s->failed_pc=0x0c096988u; return 0; }
r[5]=r[6];
goto P_0c09698a;
P_0c09698a: /* original f4fc, guest PC 0x0c09698a */
if(!s->budget--) { s->failed_pc=0x0c09698au; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c09698c;
P_0c09698c: /* original 430b, guest PC 0x0c09698c */
if(!s->budget--) { s->failed_pc=0x0c09698cu; return 0; }
target=r[3];
r[16]=code_base|0x0c096990u;
r[4]=r[6];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c096990u) { target=s->pc; goto dispatch; }
goto P_0c096990;
P_0c09698e: /* original 6463, guest PC 0x0c09698e */
if(!s->budget--) { s->failed_pc=0x0c09698eu; return 0; }
r[4]=r[6];
goto P_0c096990;
P_0c096990: /* original d22a, guest PC 0x0c096990 */
if(!s->budget--) { s->failed_pc=0x0c096990u; return 0; }
r[2]=read(ram,0x0c096a3cu,4);
goto P_0c096992;
P_0c096992: /* original 420b, guest PC 0x0c096992 */
if(!s->budget--) { s->failed_pc=0x0c096992u; return 0; }
target=r[2];
r[16]=code_base|0x0c096996u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c096996u) { target=s->pc; goto dispatch; }
goto P_0c096996;
P_0c096994: /* original 0009, guest PC 0x0c096994 */
if(!s->budget--) { s->failed_pc=0x0c096994u; return 0; }
goto P_0c096996;
P_0c096996: /* original d32a, guest PC 0x0c096996 */
if(!s->budget--) { s->failed_pc=0x0c096996u; return 0; }
r[3]=read(ram,0x0c096a40u,4);
goto P_0c096998;
P_0c096998: /* original 430b, guest PC 0x0c096998 */
if(!s->budget--) { s->failed_pc=0x0c096998u; return 0; }
target=r[3];
r[16]=code_base|0x0c09699cu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09699cu) { target=s->pc; goto dispatch; }
goto P_0c09699c;
P_0c09699a: /* original 0009, guest PC 0x0c09699a */
if(!s->budget--) { s->failed_pc=0x0c09699au; return 0; }
goto P_0c09699c;
P_0c09699c: /* original 9442, guest PC 0x0c09699c */
if(!s->budget--) { s->failed_pc=0x0c09699cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c096a24u,2);
goto P_0c09699e;
P_0c09699e: /* original e802, guest PC 0x0c09699e */
if(!s->budget--) { s->failed_pc=0x0c09699eu; return 0; }
r[8]=0x00000002u;
goto P_0c0969a0;
P_0c0969a0: /* original 9a41, guest PC 0x0c0969a0 */
if(!s->budget--) { s->failed_pc=0x0c0969a0u; return 0; }
r[10]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c096a26u,2);
goto P_0c0969a2;
P_0c0969a2: /* original ec00, guest PC 0x0c0969a2 */
if(!s->budget--) { s->failed_pc=0x0c0969a2u; return 0; }
r[12]=0x00000000u;
goto P_0c0969a4;
P_0c0969a4: /* original dd27, guest PC 0x0c0969a4 */
if(!s->budget--) { s->failed_pc=0x0c0969a4u; return 0; }
r[13]=read(ram,0x0c096a44u,4);
goto P_0c0969a6;
P_0c0969a6: /* original 34ec, guest PC 0x0c0969a6 */
if(!s->budget--) { s->failed_pc=0x0c0969a6u; return 0; }
r[4]+=r[14];
goto P_0c0969a8;
P_0c0969a8: /* original 3aec, guest PC 0x0c0969a8 */
if(!s->budget--) { s->failed_pc=0x0c0969a8u; return 0; }
r[10]+=r[14];
goto P_0c0969aa;
P_0c0969aa: /* original 6b43, guest PC 0x0c0969aa */
if(!s->budget--) { s->failed_pc=0x0c0969aau; return 0; }
r[11]=r[4];
goto P_0c0969ac;
P_0c0969ac: /* original 6943, guest PC 0x0c0969ac */
if(!s->budget--) { s->failed_pc=0x0c0969acu; return 0; }
r[9]=r[4];
goto P_0c0969ae;
P_0c0969ae: /* original 933a, guest PC 0x0c0969ae */
if(!s->budget--) { s->failed_pc=0x0c0969aeu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c096a26u,2);
goto P_0c0969b0;
P_0c0969b0: /* original 62c3, guest PC 0x0c0969b0 */
if(!s->budget--) { s->failed_pc=0x0c0969b0u; return 0; }
r[2]=r[12];
goto P_0c0969b2;
P_0c0969b2: /* original 4208, guest PC 0x0c0969b2 */
if(!s->budget--) { s->failed_pc=0x0c0969b2u; return 0; }
r[2]<<=2;
goto P_0c0969b4;
P_0c0969b4: /* original 33ec, guest PC 0x0c0969b4 */
if(!s->budget--) { s->failed_pc=0x0c0969b4u; return 0; }
r[3]+=r[14];
goto P_0c0969b6;
P_0c0969b6: /* original 323c, guest PC 0x0c0969b6 */
if(!s->budget--) { s->failed_pc=0x0c0969b6u; return 0; }
r[2]+=r[3];
goto P_0c0969b8;
P_0c0969b8: /* original 6122, guest PC 0x0c0969b8 */
if(!s->budget--) { s->failed_pc=0x0c0969b8u; return 0; }
tmp=read(ram,r[2],4);
r[1]=tmp;
goto P_0c0969ba;
P_0c0969ba: /* original 2118, guest PC 0x0c0969ba */
if(!s->budget--) { s->failed_pc=0x0c0969bau; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[1])==0)!=0);
goto P_0c0969bc;
P_0c0969bc: /* original 8901, guest PC 0x0c0969bc */
if(!s->budget--) { s->failed_pc=0x0c0969bcu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0969c2; }
goto P_0c0969be;
P_0c0969be: /* original 4d0b, guest PC 0x0c0969be */
if(!s->budget--) { s->failed_pc=0x0c0969beu; return 0; }
target=r[13];
r[16]=code_base|0x0c0969c2u;
tmp=read(ram,r[10],4);
r[4]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0969c2u) { target=s->pc; goto dispatch; }
goto P_0c0969c2;
P_0c0969c0: /* original 64a2, guest PC 0x0c0969c0 */
if(!s->budget--) { s->failed_pc=0x0c0969c0u; return 0; }
tmp=read(ram,r[10],4);
r[4]=tmp;
goto P_0c0969c2;
P_0c0969c2: /* original 6392, guest PC 0x0c0969c2 */
if(!s->budget--) { s->failed_pc=0x0c0969c2u; return 0; }
tmp=read(ram,r[9],4);
r[3]=tmp;
goto P_0c0969c4;
P_0c0969c4: /* original 2338, guest PC 0x0c0969c4 */
if(!s->budget--) { s->failed_pc=0x0c0969c4u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c0969c6;
P_0c0969c6: /* original 8901, guest PC 0x0c0969c6 */
if(!s->budget--) { s->failed_pc=0x0c0969c6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0969cc; }
goto P_0c0969c8;
P_0c0969c8: /* original 4d0b, guest PC 0x0c0969c8 */
if(!s->budget--) { s->failed_pc=0x0c0969c8u; return 0; }
target=r[13];
r[16]=code_base|0x0c0969ccu;
tmp=read(ram,r[11],4);
r[4]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0969ccu) { target=s->pc; goto dispatch; }
goto P_0c0969cc;
P_0c0969ca: /* original 64b2, guest PC 0x0c0969ca */
if(!s->budget--) { s->failed_pc=0x0c0969cau; return 0; }
tmp=read(ram,r[11],4);
r[4]=tmp;
goto P_0c0969cc;
P_0c0969cc: /* original 7c01, guest PC 0x0c0969cc */
if(!s->budget--) { s->failed_pc=0x0c0969ccu; return 0; }
r[12]+=0x00000001u;
goto P_0c0969ce;
P_0c0969ce: /* original 3c83, guest PC 0x0c0969ce */
if(!s->budget--) { s->failed_pc=0x0c0969ceu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[12]>=(int32_t)r[8])!=0);
goto P_0c0969d0;
P_0c0969d0: /* original 7904, guest PC 0x0c0969d0 */
if(!s->budget--) { s->failed_pc=0x0c0969d0u; return 0; }
r[9]+=0x00000004u;
goto P_0c0969d2;
P_0c0969d2: /* original 7b04, guest PC 0x0c0969d2 */
if(!s->budget--) { s->failed_pc=0x0c0969d2u; return 0; }
r[11]+=0x00000004u;
goto P_0c0969d4;
P_0c0969d4: /* original 8feb, guest PC 0x0c0969d4 */
if(!s->budget--) { s->failed_pc=0x0c0969d4u; return 0; }
cond=r[17]&1u;
r[10]+=0x00000004u;
if(!cond) { goto P_0c0969ae; }
goto P_0c0969d8;
P_0c0969d6: /* original 7a04, guest PC 0x0c0969d6 */
if(!s->budget--) { s->failed_pc=0x0c0969d6u; return 0; }
r[10]+=0x00000004u;
goto P_0c0969d8;
P_0c0969d8: /* original 9026, guest PC 0x0c0969d8 */
if(!s->budget--) { s->failed_pc=0x0c0969d8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c096a28u,2);
goto P_0c0969da;
P_0c0969da: /* original 02ee, guest PC 0x0c0969da */
if(!s->budget--) { s->failed_pc=0x0c0969dau; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c0969dc;
P_0c0969dc: /* original 2228, guest PC 0x0c0969dc */
if(!s->budget--) { s->failed_pc=0x0c0969dcu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c0969de;
P_0c0969de: /* original 8901, guest PC 0x0c0969de */
if(!s->budget--) { s->failed_pc=0x0c0969deu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0969e4; }
goto P_0c0969e0;
P_0c0969e0: /* original 4d0b, guest PC 0x0c0969e0 */
if(!s->budget--) { s->failed_pc=0x0c0969e0u; return 0; }
target=r[13];
r[16]=code_base|0x0c0969e4u;
r[4]=read(ram,r[14]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0969e4u) { target=s->pc; goto dispatch; }
goto P_0c0969e4;
P_0c0969e2: /* original 04ee, guest PC 0x0c0969e2 */
if(!s->budget--) { s->failed_pc=0x0c0969e2u; return 0; }
r[4]=read(ram,r[14]+r[0],4);
goto P_0c0969e4;
P_0c0969e4: /* original 9021, guest PC 0x0c0969e4 */
if(!s->budget--) { s->failed_pc=0x0c0969e4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c096a2au,2);
goto P_0c0969e6;
P_0c0969e6: /* original 03ee, guest PC 0x0c0969e6 */
if(!s->budget--) { s->failed_pc=0x0c0969e6u; return 0; }
r[3]=read(ram,r[14]+r[0],4);
goto P_0c0969e8;
P_0c0969e8: /* original 2338, guest PC 0x0c0969e8 */
if(!s->budget--) { s->failed_pc=0x0c0969e8u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c0969ea;
P_0c0969ea: /* original 8901, guest PC 0x0c0969ea */
if(!s->budget--) { s->failed_pc=0x0c0969eau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0969f0; }
goto P_0c0969ec;
P_0c0969ec: /* original 4d0b, guest PC 0x0c0969ec */
if(!s->budget--) { s->failed_pc=0x0c0969ecu; return 0; }
target=r[13];
r[16]=code_base|0x0c0969f0u;
r[4]=read(ram,r[14]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0969f0u) { target=s->pc; goto dispatch; }
goto P_0c0969f0;
P_0c0969ee: /* original 04ee, guest PC 0x0c0969ee */
if(!s->budget--) { s->failed_pc=0x0c0969eeu; return 0; }
r[4]=read(ram,r[14]+r[0],4);
goto P_0c0969f0;
P_0c0969f0: /* original 901c, guest PC 0x0c0969f0 */
if(!s->budget--) { s->failed_pc=0x0c0969f0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c096a2cu,2);
goto P_0c0969f2;
P_0c0969f2: /* original 03ee, guest PC 0x0c0969f2 */
if(!s->budget--) { s->failed_pc=0x0c0969f2u; return 0; }
r[3]=read(ram,r[14]+r[0],4);
goto P_0c0969f4;
P_0c0969f4: /* original 2338, guest PC 0x0c0969f4 */
if(!s->budget--) { s->failed_pc=0x0c0969f4u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c0969f6;
P_0c0969f6: /* original 8901, guest PC 0x0c0969f6 */
if(!s->budget--) { s->failed_pc=0x0c0969f6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0969fc; }
goto P_0c0969f8;
P_0c0969f8: /* original 4d0b, guest PC 0x0c0969f8 */
if(!s->budget--) { s->failed_pc=0x0c0969f8u; return 0; }
target=r[13];
r[16]=code_base|0x0c0969fcu;
r[4]=read(ram,r[14]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0969fcu) { target=s->pc; goto dispatch; }
goto P_0c0969fc;
P_0c0969fa: /* original 04ee, guest PC 0x0c0969fa */
if(!s->budget--) { s->failed_pc=0x0c0969fau; return 0; }
r[4]=read(ram,r[14]+r[0],4);
goto P_0c0969fc;
P_0c0969fc: /* original 9017, guest PC 0x0c0969fc */
if(!s->budget--) { s->failed_pc=0x0c0969fcu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c096a2eu,2);
goto P_0c0969fe;
P_0c0969fe: /* original 03ee, guest PC 0x0c0969fe */
if(!s->budget--) { s->failed_pc=0x0c0969feu; return 0; }
r[3]=read(ram,r[14]+r[0],4);
goto P_0c096a00;
P_0c096a00: /* original 2338, guest PC 0x0c096a00 */
if(!s->budget--) { s->failed_pc=0x0c096a00u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c096a02;
P_0c096a02: /* original 8901, guest PC 0x0c096a02 */
if(!s->budget--) { s->failed_pc=0x0c096a02u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c096a08; }
goto P_0c096a04;
P_0c096a04: /* original 4d0b, guest PC 0x0c096a04 */
if(!s->budget--) { s->failed_pc=0x0c096a04u; return 0; }
target=r[13];
r[16]=code_base|0x0c096a08u;
r[4]=read(ram,r[14]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c096a08u) { target=s->pc; goto dispatch; }
goto P_0c096a08;
P_0c096a06: /* original 04ee, guest PC 0x0c096a06 */
if(!s->budget--) { s->failed_pc=0x0c096a06u; return 0; }
r[4]=read(ram,r[14]+r[0],4);
goto P_0c096a08;
P_0c096a08: /* original d30f, guest PC 0x0c096a08 */
if(!s->budget--) { s->failed_pc=0x0c096a08u; return 0; }
r[3]=read(ram,0x0c096a48u,4);
goto P_0c096a0a;
P_0c096a0a: /* original 430b, guest PC 0x0c096a0a */
if(!s->budget--) { s->failed_pc=0x0c096a0au; return 0; }
target=r[3];
r[16]=code_base|0x0c096a0eu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c096a0eu) { target=s->pc; goto dispatch; }
goto P_0c096a0e;
P_0c096a0c: /* original 0009, guest PC 0x0c096a0c */
if(!s->budget--) { s->failed_pc=0x0c096a0cu; return 0; }
goto P_0c096a0e;
P_0c096a0e: /* original 4f26, guest PC 0x0c096a0e */
if(!s->budget--) { s->failed_pc=0x0c096a0eu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c096a10;
P_0c096a10: /* original d20e, guest PC 0x0c096a10 */
if(!s->budget--) { s->failed_pc=0x0c096a10u; return 0; }
r[2]=read(ram,0x0c096a4cu,4);
goto P_0c096a12;
P_0c096a12: /* original fff9, guest PC 0x0c096a12 */
if(!s->budget--) { s->failed_pc=0x0c096a12u; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c096a14;
P_0c096a14: /* original 68f6, guest PC 0x0c096a14 */
if(!s->budget--) { s->failed_pc=0x0c096a14u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c096a16;
P_0c096a16: /* original 69f6, guest PC 0x0c096a16 */
if(!s->budget--) { s->failed_pc=0x0c096a16u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c096a18;
P_0c096a18: /* original 6af6, guest PC 0x0c096a18 */
if(!s->budget--) { s->failed_pc=0x0c096a18u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c096a1a;
P_0c096a1a: /* original 6bf6, guest PC 0x0c096a1a */
if(!s->budget--) { s->failed_pc=0x0c096a1au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c096a1c;
P_0c096a1c: /* original 6cf6, guest PC 0x0c096a1c */
if(!s->budget--) { s->failed_pc=0x0c096a1cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c096a1e;
P_0c096a1e: /* original 6df6, guest PC 0x0c096a1e */
if(!s->budget--) { s->failed_pc=0x0c096a1eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c096a20;
P_0c096a20: /* original 422b, guest PC 0x0c096a20 */
if(!s->budget--) { s->failed_pc=0x0c096a20u; return 0; }
target=r[2];
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
P_0c096a22: /* original 6ef6, guest PC 0x0c096a22 */
if(!s->budget--) { s->failed_pc=0x0c096a22u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c096a24u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c096a24u; return 0; } return 1;
P_0c096a50: /* original 2fe6, guest PC 0x0c096a50 */
if(!s->budget--) { s->failed_pc=0x0c096a50u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c096a52;
P_0c096a52: /* original e100, guest PC 0x0c096a52 */
if(!s->budget--) { s->failed_pc=0x0c096a52u; return 0; }
r[1]=0x00000000u;
goto P_0c096a54;
P_0c096a54: /* original 2fd6, guest PC 0x0c096a54 */
if(!s->budget--) { s->failed_pc=0x0c096a54u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c096a56;
P_0c096a56: /* original 2fc6, guest PC 0x0c096a56 */
if(!s->budget--) { s->failed_pc=0x0c096a56u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c096a58;
P_0c096a58: /* original d324, guest PC 0x0c096a58 */
if(!s->budget--) { s->failed_pc=0x0c096a58u; return 0; }
r[3]=read(ram,0x0c096aecu,4);
goto P_0c096a5a;
P_0c096a5a: /* original 903d, guest PC 0x0c096a5a */
if(!s->budget--) { s->failed_pc=0x0c096a5au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c096ad8u,2);
goto P_0c096a5c;
P_0c096a5c: /* original 6432, guest PC 0x0c096a5c */
if(!s->budget--) { s->failed_pc=0x0c096a5cu; return 0; }
tmp=read(ram,r[3],4);
r[4]=tmp;
goto P_0c096a5e;
P_0c096a5e: /* original d224, guest PC 0x0c096a5e */
if(!s->budget--) { s->failed_pc=0x0c096a5eu; return 0; }
r[2]=read(ram,0x0c096af0u,4);
goto P_0c096a60;
P_0c096a60: /* original 4f22, guest PC 0x0c096a60 */
if(!s->budget--) { s->failed_pc=0x0c096a60u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c096a62;
P_0c096a62: /* original dc21, guest PC 0x0c096a62 */
if(!s->budget--) { s->failed_pc=0x0c096a62u; return 0; }
r[12]=read(ram,0x0c096ae8u,4);
goto P_0c096a64;
P_0c096a64: /* original dd1e, guest PC 0x0c096a64 */
if(!s->budget--) { s->failed_pc=0x0c096a64u; return 0; }
r[13]=read(ram,0x0c096ae0u,4);
goto P_0c096a66;
P_0c096a66: /* original de1f, guest PC 0x0c096a66 */
if(!s->budget--) { s->failed_pc=0x0c096a66u; return 0; }
r[14]=read(ram,0x0c096ae4u,4);
goto P_0c096a68;
P_0c096a68: /* original 0426, guest PC 0x0c096a68 */
if(!s->budget--) { s->failed_pc=0x0c096a68u; return 0; }
write(ram,r[4]+r[0],r[2],4);
goto P_0c096a6a;
P_0c096a6a: /* original e029, guest PC 0x0c096a6a */
if(!s->budget--) { s->failed_pc=0x0c096a6au; return 0; }
r[0]=0x00000029u;
goto P_0c096a6c;
P_0c096a6c: /* original 64c3, guest PC 0x0c096a6c */
if(!s->budget--) { s->failed_pc=0x0c096a6cu; return 0; }
r[4]=r[12];
goto P_0c096a6e;
P_0c096a6e: /* original 0d14, guest PC 0x0c096a6e */
if(!s->budget--) { s->failed_pc=0x0c096a6eu; return 0; }
write(ram,r[13]+r[0],r[1],1);
goto P_0c096a70;
P_0c096a70: /* original d220, guest PC 0x0c096a70 */
if(!s->budget--) { s->failed_pc=0x0c096a70u; return 0; }
r[2]=read(ram,0x0c096af4u,4);
goto P_0c096a72;
P_0c096a72: /* original 420b, guest PC 0x0c096a72 */
if(!s->budget--) { s->failed_pc=0x0c096a72u; return 0; }
target=r[2];
r[16]=code_base|0x0c096a76u;
r[4]+=0x00000001u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c096a76u) { target=s->pc; goto dispatch; }
goto P_0c096a76;
P_0c096a74: /* original 7401, guest PC 0x0c096a74 */
if(!s->budget--) { s->failed_pc=0x0c096a74u; return 0; }
r[4]+=0x00000001u;
goto P_0c096a76;
P_0c096a76: /* original 640c, guest PC 0x0c096a76 */
if(!s->budget--) { s->failed_pc=0x0c096a76u; return 0; }
r[4]=r[0]&255u;
goto P_0c096a78;
P_0c096a78: /* original 902f, guest PC 0x0c096a78 */
if(!s->budget--) { s->failed_pc=0x0c096a78u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c096adau,2);
goto P_0c096a7a;
P_0c096a7a: /* original e301, guest PC 0x0c096a7a */
if(!s->budget--) { s->failed_pc=0x0c096a7au; return 0; }
r[3]=0x00000001u;
goto P_0c096a7c;
P_0c096a7c: /* original 0d44, guest PC 0x0c096a7c */
if(!s->budget--) { s->failed_pc=0x0c096a7cu; return 0; }
write(ram,r[13]+r[0],r[4],1);
goto P_0c096a7e;
P_0c096a7e: /* original 70ff, guest PC 0x0c096a7e */
if(!s->budget--) { s->failed_pc=0x0c096a7eu; return 0; }
r[0]+=0xffffffffu;
goto P_0c096a80;
P_0c096a80: /* original 0d34, guest PC 0x0c096a80 */
if(!s->budget--) { s->failed_pc=0x0c096a80u; return 0; }
write(ram,r[13]+r[0],r[3],1);
goto P_0c096a82;
P_0c096a82: /* original 64c3, guest PC 0x0c096a82 */
if(!s->budget--) { s->failed_pc=0x0c096a82u; return 0; }
r[4]=r[12];
goto P_0c096a84;
P_0c096a84: /* original d31b, guest PC 0x0c096a84 */
if(!s->budget--) { s->failed_pc=0x0c096a84u; return 0; }
r[3]=read(ram,0x0c096af4u,4);
goto P_0c096a86;
P_0c096a86: /* original 430b, guest PC 0x0c096a86 */
if(!s->budget--) { s->failed_pc=0x0c096a86u; return 0; }
target=r[3];
r[16]=code_base|0x0c096a8au;
r[4]+=0x00000030u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c096a8au) { target=s->pc; goto dispatch; }
goto P_0c096a8a;
P_0c096a88: /* original 7430, guest PC 0x0c096a88 */
if(!s->budget--) { s->failed_pc=0x0c096a88u; return 0; }
r[4]+=0x00000030u;
goto P_0c096a8a;
P_0c096a8a: /* original 9227, guest PC 0x0c096a8a */
if(!s->budget--) { s->failed_pc=0x0c096a8au; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c096adcu,2);
goto P_0c096a8c;
P_0c096a8c: /* original 640c, guest PC 0x0c096a8c */
if(!s->budget--) { s->failed_pc=0x0c096a8cu; return 0; }
r[4]=r[0]&255u;
goto P_0c096a8e;
P_0c096a8e: /* original 3420, guest PC 0x0c096a8e */
if(!s->budget--) { s->failed_pc=0x0c096a8eu; return 0; }
r[17]=(r[17]&~1u)|((r[4]==r[2])!=0);
goto P_0c096a90;
P_0c096a90: /* original 8d01, guest PC 0x0c096a90 */
if(!s->budget--) { s->failed_pc=0x0c096a90u; return 0; }
cond=r[17]&1u;
r[5]=0x00000003u;
if(cond) { goto P_0c096a96; }
goto P_0c096a94;
P_0c096a92: /* original e503, guest PC 0x0c096a92 */
if(!s->budget--) { s->failed_pc=0x0c096a92u; return 0; }
r[5]=0x00000003u;
goto P_0c096a94;
P_0c096a94: /* original e340, guest PC 0x0c096a94 */
if(!s->budget--) { s->failed_pc=0x0c096a94u; return 0; }
r[3]=0x00000040u;
goto P_0c096a96;
P_0c096a96: /* original 4f26, guest PC 0x0c096a96 */
if(!s->budget--) { s->failed_pc=0x0c096a96u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c096a98;
P_0c096a98: /* original e010, guest PC 0x0c096a98 */
if(!s->budget--) { s->failed_pc=0x0c096a98u; return 0; }
r[0]=0x00000010u;
goto P_0c096a9a;
P_0c096a9a: /* original 1e53, guest PC 0x0c096a9a */
if(!s->budget--) { s->failed_pc=0x0c096a9au; return 0; }
write(ram,r[14]+12,r[5],4);
goto P_0c096a9c;
P_0c096a9c: /* original e301, guest PC 0x0c096a9c */
if(!s->budget--) { s->failed_pc=0x0c096a9cu; return 0; }
r[3]=0x00000001u;
goto P_0c096a9e;
P_0c096a9e: /* original 0e34, guest PC 0x0c096a9e */
if(!s->budget--) { s->failed_pc=0x0c096a9eu; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c096aa0;
P_0c096aa0: /* original 84ea, guest PC 0x0c096aa0 */
if(!s->budget--) { s->failed_pc=0x0c096aa0u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+10,1);
goto P_0c096aa2;
P_0c096aa2: /* original 7001, guest PC 0x0c096aa2 */
if(!s->budget--) { s->failed_pc=0x0c096aa2u; return 0; }
r[0]+=0x00000001u;
goto P_0c096aa4;
P_0c096aa4: /* original 80ea, guest PC 0x0c096aa4 */
if(!s->budget--) { s->failed_pc=0x0c096aa4u; return 0; }
write(ram,r[14]+10,r[0],1);
goto P_0c096aa6;
P_0c096aa6: /* original 6cf6, guest PC 0x0c096aa6 */
if(!s->budget--) { s->failed_pc=0x0c096aa6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c096aa8;
P_0c096aa8: /* original 6df6, guest PC 0x0c096aa8 */
if(!s->budget--) { s->failed_pc=0x0c096aa8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c096aaa;
P_0c096aaa: /* original a000, guest PC 0x0c096aaa */
if(!s->budget--) { s->failed_pc=0x0c096aaau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c096aae;
P_0c096aac: /* original 6ef6, guest PC 0x0c096aac */
if(!s->budget--) { s->failed_pc=0x0c096aacu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c096aae;
P_0c096aae: /* original d40d, guest PC 0x0c096aae */
if(!s->budget--) { s->failed_pc=0x0c096aaeu; return 0; }
r[4]=read(ram,0x0c096ae4u,4);
goto P_0c096ab0;
P_0c096ab0: /* original 9315, guest PC 0x0c096ab0 */
if(!s->budget--) { s->failed_pc=0x0c096ab0u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c096adeu,2);
goto P_0c096ab2;
P_0c096ab2: /* original 5243, guest PC 0x0c096ab2 */
if(!s->budget--) { s->failed_pc=0x0c096ab2u; return 0; }
r[2]=read(ram,r[4]+12,4);
goto P_0c096ab4;
P_0c096ab4: /* original 3233, guest PC 0x0c096ab4 */
if(!s->budget--) { s->failed_pc=0x0c096ab4u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[2]>=(int32_t)r[3])!=0);
goto P_0c096ab6;
P_0c096ab6: /* original 8907, guest PC 0x0c096ab6 */
if(!s->budget--) { s->failed_pc=0x0c096ab6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c096ac8; }
goto P_0c096ab8;
P_0c096ab8: /* original d50f, guest PC 0x0c096ab8 */
if(!s->budget--) { s->failed_pc=0x0c096ab8u; return 0; }
r[5]=read(ram,0x0c096af8u,4);
goto P_0c096aba;
P_0c096aba: /* original 8551, guest PC 0x0c096aba */
if(!s->budget--) { s->failed_pc=0x0c096abau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[5]+2,2);
goto P_0c096abc;
P_0c096abc: /* original 620d, guest PC 0x0c096abc */
if(!s->budget--) { s->failed_pc=0x0c096abcu; return 0; }
r[2]=r[0]&65535u;
goto P_0c096abe;
P_0c096abe: /* original 8559, guest PC 0x0c096abe */
if(!s->budget--) { s->failed_pc=0x0c096abeu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[5]+18,2);
goto P_0c096ac0;
P_0c096ac0: /* original 600d, guest PC 0x0c096ac0 */
if(!s->budget--) { s->failed_pc=0x0c096ac0u; return 0; }
r[0]=r[0]&65535u;
goto P_0c096ac2;
P_0c096ac2: /* original 220b, guest PC 0x0c096ac2 */
if(!s->budget--) { s->failed_pc=0x0c096ac2u; return 0; }
r[2]|=r[0];
goto P_0c096ac4;
P_0c096ac4: /* original 2228, guest PC 0x0c096ac4 */
if(!s->budget--) { s->failed_pc=0x0c096ac4u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c096ac6;
P_0c096ac6: /* original 8b02, guest PC 0x0c096ac6 */
if(!s->budget--) { s->failed_pc=0x0c096ac6u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c096ace; }
goto P_0c096ac8;
P_0c096ac8: /* original 5343, guest PC 0x0c096ac8 */
if(!s->budget--) { s->failed_pc=0x0c096ac8u; return 0; }
r[3]=read(ram,r[4]+12,4);
goto P_0c096aca;
P_0c096aca: /* original 4315, guest PC 0x0c096aca */
if(!s->budget--) { s->failed_pc=0x0c096acau; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>0)!=0);
goto P_0c096acc;
P_0c096acc: /* original 8902, guest PC 0x0c096acc */
if(!s->budget--) { s->failed_pc=0x0c096accu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c096ad4; }
goto P_0c096ace;
P_0c096ace: /* original 844a, guest PC 0x0c096ace */
if(!s->budget--) { s->failed_pc=0x0c096aceu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+10,1);
goto P_0c096ad0;
P_0c096ad0: /* original 7001, guest PC 0x0c096ad0 */
if(!s->budget--) { s->failed_pc=0x0c096ad0u; return 0; }
r[0]+=0x00000001u;
goto P_0c096ad2;
P_0c096ad2: /* original 804a, guest PC 0x0c096ad2 */
if(!s->budget--) { s->failed_pc=0x0c096ad2u; return 0; }
write(ram,r[4]+10,r[0],1);
goto P_0c096ad4;
P_0c096ad4: /* original 000b, guest PC 0x0c096ad4 */
if(!s->budget--) { s->failed_pc=0x0c096ad4u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c096ad6: /* original 0009, guest PC 0x0c096ad6 */
if(!s->budget--) { s->failed_pc=0x0c096ad6u; return 0; }
if(!vf3_matrix_family(0x0c096ad8u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c096ad8u; return 0; } return 1;
P_0c096afc: /* original 2fe6, guest PC 0x0c096afc */
if(!s->budget--) { s->failed_pc=0x0c096afcu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c096afe;
P_0c096afe: /* original 2fd6, guest PC 0x0c096afe */
if(!s->budget--) { s->failed_pc=0x0c096afeu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c096b00;
P_0c096b00: /* original 2fc6, guest PC 0x0c096b00 */
if(!s->budget--) { s->failed_pc=0x0c096b00u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c096b02;
P_0c096b02: /* original 2fb6, guest PC 0x0c096b02 */
if(!s->budget--) { s->failed_pc=0x0c096b02u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c096b04;
P_0c096b04: /* original 2fa6, guest PC 0x0c096b04 */
if(!s->budget--) { s->failed_pc=0x0c096b04u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c096b06;
P_0c096b06: /* original 2f96, guest PC 0x0c096b06 */
if(!s->budget--) { s->failed_pc=0x0c096b06u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c096b08;
P_0c096b08: /* original 2f86, guest PC 0x0c096b08 */
if(!s->budget--) { s->failed_pc=0x0c096b08u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c096b0a;
P_0c096b0a: /* original 4f22, guest PC 0x0c096b0a */
if(!s->budget--) { s->failed_pc=0x0c096b0au; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c096b0c;
P_0c096b0c: /* original d35b, guest PC 0x0c096b0c */
if(!s->budget--) { s->failed_pc=0x0c096b0cu; return 0; }
r[3]=read(ram,0x0c096c7cu,4);
goto P_0c096b0e;
P_0c096b0e: /* original 7ff8, guest PC 0x0c096b0e */
if(!s->budget--) { s->failed_pc=0x0c096b0eu; return 0; }
r[15]+=0xfffffff8u;
goto P_0c096b10;
P_0c096b10: /* original 1f31, guest PC 0x0c096b10 */
if(!s->budget--) { s->failed_pc=0x0c096b10u; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c096b12;
P_0c096b12: /* original d35d, guest PC 0x0c096b12 */
if(!s->budget--) { s->failed_pc=0x0c096b12u; return 0; }
r[3]=read(ram,0x0c096c88u,4);
goto P_0c096b14;
P_0c096b14: /* original db5b, guest PC 0x0c096b14 */
if(!s->budget--) { s->failed_pc=0x0c096b14u; return 0; }
r[11]=read(ram,0x0c096c84u,4);
goto P_0c096b16;
P_0c096b16: /* original de5a, guest PC 0x0c096b16 */
if(!s->budget--) { s->failed_pc=0x0c096b16u; return 0; }
r[14]=read(ram,0x0c096c80u,4);
goto P_0c096b18;
P_0c096b18: /* original 430b, guest PC 0x0c096b18 */
if(!s->budget--) { s->failed_pc=0x0c096b18u; return 0; }
target=r[3];
r[16]=code_base|0x0c096b1cu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c096b1cu) { target=s->pc; goto dispatch; }
goto P_0c096b1c;
P_0c096b1a: /* original 0009, guest PC 0x0c096b1a */
if(!s->budget--) { s->failed_pc=0x0c096b1au; return 0; }
goto P_0c096b1c;
P_0c096b1c: /* original d25b, guest PC 0x0c096b1c */
if(!s->budget--) { s->failed_pc=0x0c096b1cu; return 0; }
r[2]=read(ram,0x0c096c8cu,4);
goto P_0c096b1e;
P_0c096b1e: /* original 420b, guest PC 0x0c096b1e */
if(!s->budget--) { s->failed_pc=0x0c096b1eu; return 0; }
target=r[2];
r[16]=code_base|0x0c096b22u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c096b22u) { target=s->pc; goto dispatch; }
goto P_0c096b22;
P_0c096b20: /* original 0009, guest PC 0x0c096b20 */
if(!s->budget--) { s->failed_pc=0x0c096b20u; return 0; }
goto P_0c096b22;
P_0c096b22: /* original d35c, guest PC 0x0c096b22 */
if(!s->budget--) { s->failed_pc=0x0c096b22u; return 0; }
r[3]=read(ram,0x0c096c94u,4);
goto P_0c096b24;
P_0c096b24: /* original d45a, guest PC 0x0c096b24 */
if(!s->budget--) { s->failed_pc=0x0c096b24u; return 0; }
r[4]=read(ram,0x0c096c90u,4);
goto P_0c096b26;
P_0c096b26: /* original 430b, guest PC 0x0c096b26 */
if(!s->budget--) { s->failed_pc=0x0c096b26u; return 0; }
target=r[3];
r[16]=code_base|0x0c096b2au;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c096b2au) { target=s->pc; goto dispatch; }
goto P_0c096b2a;
P_0c096b28: /* original 0009, guest PC 0x0c096b28 */
if(!s->budget--) { s->failed_pc=0x0c096b28u; return 0; }
goto P_0c096b2a;
P_0c096b2a: /* original d25b, guest PC 0x0c096b2a */
if(!s->budget--) { s->failed_pc=0x0c096b2au; return 0; }
r[2]=read(ram,0x0c096c98u,4);
goto P_0c096b2c;
P_0c096b2c: /* original 420b, guest PC 0x0c096b2c */
if(!s->budget--) { s->failed_pc=0x0c096b2cu; return 0; }
target=r[2];
r[16]=code_base|0x0c096b30u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c096b30u) { target=s->pc; goto dispatch; }
goto P_0c096b30;
P_0c096b2e: /* original 0009, guest PC 0x0c096b2e */
if(!s->budget--) { s->failed_pc=0x0c096b2eu; return 0; }
goto P_0c096b30;
P_0c096b30: /* original d35a, guest PC 0x0c096b30 */
if(!s->budget--) { s->failed_pc=0x0c096b30u; return 0; }
r[3]=read(ram,0x0c096c9cu,4);
goto P_0c096b32;
P_0c096b32: /* original 430b, guest PC 0x0c096b32 */
if(!s->budget--) { s->failed_pc=0x0c096b32u; return 0; }
target=r[3];
r[16]=code_base|0x0c096b36u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c096b36u) { target=s->pc; goto dispatch; }
goto P_0c096b36;
P_0c096b34: /* original 0009, guest PC 0x0c096b34 */
if(!s->budget--) { s->failed_pc=0x0c096b34u; return 0; }
goto P_0c096b36;
P_0c096b36: /* original bf05, guest PC 0x0c096b36 */
if(!s->budget--) { s->failed_pc=0x0c096b36u; return 0; }
target=code_base|0x0c096944u; r[16]=code_base|0x0c096b3au;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c096b3au) { target=s->pc; goto dispatch; }
goto P_0c096b3a;
P_0c096b38: /* original 0009, guest PC 0x0c096b38 */
if(!s->budget--) { s->failed_pc=0x0c096b38u; return 0; }
goto P_0c096b3a;
P_0c096b3a: /* original d359, guest PC 0x0c096b3a */
if(!s->budget--) { s->failed_pc=0x0c096b3au; return 0; }
r[3]=read(ram,0x0c096ca0u,4);
goto P_0c096b3c;
P_0c096b3c: /* original e500, guest PC 0x0c096b3c */
if(!s->budget--) { s->failed_pc=0x0c096b3cu; return 0; }
r[5]=0x00000000u;
goto P_0c096b3e;
P_0c096b3e: /* original 54f1, guest PC 0x0c096b3e */
if(!s->budget--) { s->failed_pc=0x0c096b3eu; return 0; }
r[4]=read(ram,r[15]+4,4);
goto P_0c096b40;
P_0c096b40: /* original 430b, guest PC 0x0c096b40 */
if(!s->budget--) { s->failed_pc=0x0c096b40u; return 0; }
target=r[3];
r[16]=code_base|0x0c096b44u;
r[4]+=0x00000030u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c096b44u) { target=s->pc; goto dispatch; }
goto P_0c096b44;
P_0c096b42: /* original 7430, guest PC 0x0c096b42 */
if(!s->budget--) { s->failed_pc=0x0c096b42u; return 0; }
r[4]+=0x00000030u;
goto P_0c096b44;
P_0c096b44: /* original dc57, guest PC 0x0c096b44 */
if(!s->budget--) { s->failed_pc=0x0c096b44u; return 0; }
r[12]=read(ram,0x0c096ca4u,4);
goto P_0c096b46;
P_0c096b46: /* original bed7, guest PC 0x0c096b46 */
if(!s->budget--) { s->failed_pc=0x0c096b46u; return 0; }
target=code_base|0x0c0968f8u; r[16]=code_base|0x0c096b4au;
r[4]=read(ram,r[12]+24,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c096b4au) { target=s->pc; goto dispatch; }
goto P_0c096b4a;
P_0c096b48: /* original 54c6, guest PC 0x0c096b48 */
if(!s->budget--) { s->failed_pc=0x0c096b48u; return 0; }
r[4]=read(ram,r[12]+24,4);
goto P_0c096b4a;
P_0c096b4a: /* original bed5, guest PC 0x0c096b4a */
if(!s->budget--) { s->failed_pc=0x0c096b4au; return 0; }
target=code_base|0x0c0968f8u; r[16]=code_base|0x0c096b4eu;
r[4]=read(ram,r[12]+28,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c096b4eu) { target=s->pc; goto dispatch; }
goto P_0c096b4e;
P_0c096b4c: /* original 54c7, guest PC 0x0c096b4c */
if(!s->budget--) { s->failed_pc=0x0c096b4cu; return 0; }
r[4]=read(ram,r[12]+28,4);
goto P_0c096b4e;
P_0c096b4e: /* original bed3, guest PC 0x0c096b4e */
if(!s->budget--) { s->failed_pc=0x0c096b4eu; return 0; }
target=code_base|0x0c0968f8u; r[16]=code_base|0x0c096b52u;
r[4]=read(ram,r[12]+16,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c096b52u) { target=s->pc; goto dispatch; }
goto P_0c096b52;
P_0c096b50: /* original 54c4, guest PC 0x0c096b50 */
if(!s->budget--) { s->failed_pc=0x0c096b50u; return 0; }
r[4]=read(ram,r[12]+16,4);
goto P_0c096b52;
P_0c096b52: /* original bed1, guest PC 0x0c096b52 */
if(!s->budget--) { s->failed_pc=0x0c096b52u; return 0; }
target=code_base|0x0c0968f8u; r[16]=code_base|0x0c096b56u;
r[4]=read(ram,r[12]+20,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c096b56u) { target=s->pc; goto dispatch; }
goto P_0c096b56;
P_0c096b54: /* original 54c5, guest PC 0x0c096b54 */
if(!s->budget--) { s->failed_pc=0x0c096b54u; return 0; }
r[4]=read(ram,r[12]+20,4);
goto P_0c096b56;
P_0c096b56: /* original e048, guest PC 0x0c096b56 */
if(!s->budget--) { s->failed_pc=0x0c096b56u; return 0; }
r[0]=0x00000048u;
goto P_0c096b58;
P_0c096b58: /* original bece, guest PC 0x0c096b58 */
if(!s->budget--) { s->failed_pc=0x0c096b58u; return 0; }
target=code_base|0x0c0968f8u; r[16]=code_base|0x0c096b5cu;
r[4]=read(ram,r[12]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c096b5cu) { target=s->pc; goto dispatch; }
goto P_0c096b5c;
P_0c096b5a: /* original 04ce, guest PC 0x0c096b5a */
if(!s->budget--) { s->failed_pc=0x0c096b5au; return 0; }
r[4]=read(ram,r[12]+r[0],4);
goto P_0c096b5c;
P_0c096b5c: /* original e05c, guest PC 0x0c096b5c */
if(!s->budget--) { s->failed_pc=0x0c096b5cu; return 0; }
r[0]=0x0000005cu;
goto P_0c096b5e;
P_0c096b5e: /* original becb, guest PC 0x0c096b5e */
if(!s->budget--) { s->failed_pc=0x0c096b5eu; return 0; }
target=code_base|0x0c0968f8u; r[16]=code_base|0x0c096b62u;
r[4]=read(ram,r[12]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c096b62u) { target=s->pc; goto dispatch; }
goto P_0c096b62;
P_0c096b60: /* original 04ce, guest PC 0x0c096b60 */
if(!s->budget--) { s->failed_pc=0x0c096b60u; return 0; }
r[4]=read(ram,r[12]+r[0],4);
goto P_0c096b62;
P_0c096b62: /* original e060, guest PC 0x0c096b62 */
if(!s->budget--) { s->failed_pc=0x0c096b62u; return 0; }
r[0]=0x00000060u;
goto P_0c096b64;
P_0c096b64: /* original bec8, guest PC 0x0c096b64 */
if(!s->budget--) { s->failed_pc=0x0c096b64u; return 0; }
target=code_base|0x0c0968f8u; r[16]=code_base|0x0c096b68u;
r[4]=read(ram,r[12]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c096b68u) { target=s->pc; goto dispatch; }
goto P_0c096b68;
P_0c096b66: /* original 04ce, guest PC 0x0c096b66 */
if(!s->budget--) { s->failed_pc=0x0c096b66u; return 0; }
r[4]=read(ram,r[12]+r[0],4);
goto P_0c096b68;
P_0c096b68: /* original e064, guest PC 0x0c096b68 */
if(!s->budget--) { s->failed_pc=0x0c096b68u; return 0; }
r[0]=0x00000064u;
goto P_0c096b6a;
P_0c096b6a: /* original bec5, guest PC 0x0c096b6a */
if(!s->budget--) { s->failed_pc=0x0c096b6au; return 0; }
target=code_base|0x0c0968f8u; r[16]=code_base|0x0c096b6eu;
r[4]=read(ram,r[12]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c096b6eu) { target=s->pc; goto dispatch; }
goto P_0c096b6e;
P_0c096b6c: /* original 04ce, guest PC 0x0c096b6c */
if(!s->budget--) { s->failed_pc=0x0c096b6cu; return 0; }
r[4]=read(ram,r[12]+r[0],4);
goto P_0c096b6e;
P_0c096b6e: /* original c74e, guest PC 0x0c096b6e */
if(!s->budget--) { s->failed_pc=0x0c096b6eu; return 0; }
r[0]=code_base|0x00096ca8u;
goto P_0c096b70;
P_0c096b70: /* original f308, guest PC 0x0c096b70 */
if(!s->budget--) { s->failed_pc=0x0c096b70u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c096b72;
P_0c096b72: /* original eaff, guest PC 0x0c096b72 */
if(!s->budget--) { s->failed_pc=0x0c096b72u; return 0; }
r[10]=0xffffffffu;
goto P_0c096b74;
P_0c096b74: /* original fe3a, guest PC 0x0c096b74 */
if(!s->budget--) { s->failed_pc=0x0c096b74u; return 0; }
vf3_matrix_store(s,ram,3,r[14]);
goto P_0c096b76;
P_0c096b76: /* original 9373, guest PC 0x0c096b76 */
if(!s->budget--) { s->failed_pc=0x0c096b76u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c096c60u,2);
goto P_0c096b78;
P_0c096b78: /* original 52e2, guest PC 0x0c096b78 */
if(!s->budget--) { s->failed_pc=0x0c096b78u; return 0; }
r[2]=read(ram,r[14]+8,4);
goto P_0c096b7a;
P_0c096b7a: /* original 2239, guest PC 0x0c096b7a */
if(!s->budget--) { s->failed_pc=0x0c096b7au; return 0; }
r[2]&=r[3];
goto P_0c096b7c;
P_0c096b7c: /* original 1e22, guest PC 0x0c096b7c */
if(!s->budget--) { s->failed_pc=0x0c096b7cu; return 0; }
write(ram,r[14]+8,r[2],4);
goto P_0c096b7e;
P_0c096b7e: /* original d14b, guest PC 0x0c096b7e */
if(!s->budget--) { s->failed_pc=0x0c096b7eu; return 0; }
r[1]=read(ram,0x0c096cacu,4);
goto P_0c096b80;
P_0c096b80: /* original 906f, guest PC 0x0c096b80 */
if(!s->budget--) { s->failed_pc=0x0c096b80u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c096c62u,2);
goto P_0c096b82;
P_0c096b82: /* original 54cc, guest PC 0x0c096b82 */
if(!s->budget--) { s->failed_pc=0x0c096b82u; return 0; }
r[4]=read(ram,r[12]+48,4);
goto P_0c096b84;
P_0c096b84: /* original 0416, guest PC 0x0c096b84 */
if(!s->budget--) { s->failed_pc=0x0c096b84u; return 0; }
write(ram,r[4]+r[0],r[1],4);
goto P_0c096b86;
P_0c096b86: /* original 52c8, guest PC 0x0c096b86 */
if(!s->budget--) { s->failed_pc=0x0c096b86u; return 0; }
r[2]=read(ram,r[12]+32,4);
goto P_0c096b88;
P_0c096b88: /* original 6123, guest PC 0x0c096b88 */
if(!s->budget--) { s->failed_pc=0x0c096b88u; return 0; }
r[1]=r[2];
goto P_0c096b8a;
P_0c096b8a: /* original 2f22, guest PC 0x0c096b8a */
if(!s->budget--) { s->failed_pc=0x0c096b8au; return 0; }
write(ram,r[15],r[2],4);
goto P_0c096b8c;
P_0c096b8c: /* original e201, guest PC 0x0c096b8c */
if(!s->budget--) { s->failed_pc=0x0c096b8cu; return 0; }
r[2]=0x00000001u;
goto P_0c096b8e;
P_0c096b8e: /* original 2122, guest PC 0x0c096b8e */
if(!s->budget--) { s->failed_pc=0x0c096b8eu; return 0; }
write(ram,r[1],r[2],4);
goto P_0c096b90;
P_0c096b90: /* original 9268, guest PC 0x0c096b90 */
if(!s->budget--) { s->failed_pc=0x0c096b90u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c096c64u,2);
goto P_0c096b92;
P_0c096b92: /* original 9068, guest PC 0x0c096b92 */
if(!s->budget--) { s->failed_pc=0x0c096b92u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c096c66u,2);
goto P_0c096b94;
P_0c096b94: /* original 61f2, guest PC 0x0c096b94 */
if(!s->budget--) { s->failed_pc=0x0c096b94u; return 0; }
tmp=read(ram,r[15],4);
r[1]=tmp;
goto P_0c096b96;
P_0c096b96: /* original 0125, guest PC 0x0c096b96 */
if(!s->budget--) { s->failed_pc=0x0c096b96u; return 0; }
write(ram,r[1]+r[0],r[2],2);
goto P_0c096b98;
P_0c096b98: /* original 58c4, guest PC 0x0c096b98 */
if(!s->budget--) { s->failed_pc=0x0c096b98u; return 0; }
r[8]=read(ram,r[12]+16,4);
goto P_0c096b9a;
P_0c096b9a: /* original 59c5, guest PC 0x0c096b9a */
if(!s->budget--) { s->failed_pc=0x0c096b9au; return 0; }
r[9]=read(ram,r[12]+20,4);
goto P_0c096b9c;
P_0c096b9c: /* original d444, guest PC 0x0c096b9c */
if(!s->budget--) { s->failed_pc=0x0c096b9cu; return 0; }
r[4]=read(ram,0x0c096cb0u,4);
goto P_0c096b9e;
P_0c096b9e: /* original 6282, guest PC 0x0c096b9e */
if(!s->budget--) { s->failed_pc=0x0c096b9eu; return 0; }
tmp=read(ram,r[8],4);
r[2]=tmp;
goto P_0c096ba0;
P_0c096ba0: /* original 55ca, guest PC 0x0c096ba0 */
if(!s->budget--) { s->failed_pc=0x0c096ba0u; return 0; }
r[5]=read(ram,r[12]+40,4);
goto P_0c096ba2;
P_0c096ba2: /* original 2249, guest PC 0x0c096ba2 */
if(!s->budget--) { s->failed_pc=0x0c096ba2u; return 0; }
r[2]&=r[4];
goto P_0c096ba4;
P_0c096ba4: /* original 56cb, guest PC 0x0c096ba4 */
if(!s->budget--) { s->failed_pc=0x0c096ba4u; return 0; }
r[6]=read(ram,r[12]+44,4);
goto P_0c096ba6;
P_0c096ba6: /* original 2822, guest PC 0x0c096ba6 */
if(!s->budget--) { s->failed_pc=0x0c096ba6u; return 0; }
write(ram,r[8],r[2],4);
goto P_0c096ba8;
P_0c096ba8: /* original 6192, guest PC 0x0c096ba8 */
if(!s->budget--) { s->failed_pc=0x0c096ba8u; return 0; }
tmp=read(ram,r[9],4);
r[1]=tmp;
goto P_0c096baa;
P_0c096baa: /* original 2149, guest PC 0x0c096baa */
if(!s->budget--) { s->failed_pc=0x0c096baau; return 0; }
r[1]&=r[4];
goto P_0c096bac;
P_0c096bac: /* original 2912, guest PC 0x0c096bac */
if(!s->budget--) { s->failed_pc=0x0c096bacu; return 0; }
write(ram,r[9],r[1],4);
goto P_0c096bae;
P_0c096bae: /* original ed00, guest PC 0x0c096bae */
if(!s->budget--) { s->failed_pc=0x0c096baeu; return 0; }
r[13]=0x00000000u;
goto P_0c096bb0;
P_0c096bb0: /* original 1ba8, guest PC 0x0c096bb0 */
if(!s->budget--) { s->failed_pc=0x0c096bb0u; return 0; }
write(ram,r[11]+32,r[10],4);
goto P_0c096bb2;
P_0c096bb2: /* original 62d3, guest PC 0x0c096bb2 */
if(!s->budget--) { s->failed_pc=0x0c096bb2u; return 0; }
r[2]=r[13];
goto P_0c096bb4;
P_0c096bb4: /* original 1baa, guest PC 0x0c096bb4 */
if(!s->budget--) { s->failed_pc=0x0c096bb4u; return 0; }
write(ram,r[11]+40,r[10],4);
goto P_0c096bb6;
P_0c096bb6: /* original 1ba9, guest PC 0x0c096bb6 */
if(!s->budget--) { s->failed_pc=0x0c096bb6u; return 0; }
write(ram,r[11]+36,r[10],4);
goto P_0c096bb8;
P_0c096bb8: /* original 1bab, guest PC 0x0c096bb8 */
if(!s->budget--) { s->failed_pc=0x0c096bb8u; return 0; }
write(ram,r[11]+44,r[10],4);
goto P_0c096bba;
P_0c096bba: /* original 9055, guest PC 0x0c096bba */
if(!s->budget--) { s->failed_pc=0x0c096bbau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c096c68u,2);
goto P_0c096bbc;
P_0c096bbc: /* original 0bd6, guest PC 0x0c096bbc */
if(!s->budget--) { s->failed_pc=0x0c096bbcu; return 0; }
write(ram,r[11]+r[0],r[13],4);
goto P_0c096bbe;
P_0c096bbe: /* original 70ac, guest PC 0x0c096bbe */
if(!s->budget--) { s->failed_pc=0x0c096bbeu; return 0; }
r[0]+=0xffffffacu;
goto P_0c096bc0;
P_0c096bc0: /* original 0bd6, guest PC 0x0c096bc0 */
if(!s->budget--) { s->failed_pc=0x0c096bc0u; return 0; }
write(ram,r[11]+r[0],r[13],4);
goto P_0c096bc2;
P_0c096bc2: /* original 703e, guest PC 0x0c096bc2 */
if(!s->budget--) { s->failed_pc=0x0c096bc2u; return 0; }
r[0]+=0x0000003eu;
goto P_0c096bc4;
P_0c096bc4: /* original 26d2, guest PC 0x0c096bc4 */
if(!s->budget--) { s->failed_pc=0x0c096bc4u; return 0; }
write(ram,r[6],r[13],4);
goto P_0c096bc6;
P_0c096bc6: /* original 2522, guest PC 0x0c096bc6 */
if(!s->budget--) { s->failed_pc=0x0c096bc6u; return 0; }
write(ram,r[5],r[2],4);
goto P_0c096bc8;
P_0c096bc8: /* original 0b24, guest PC 0x0c096bc8 */
if(!s->budget--) { s->failed_pc=0x0c096bc8u; return 0; }
write(ram,r[11]+r[0],r[2],1);
goto P_0c096bca;
P_0c096bca: /* original 70ff, guest PC 0x0c096bca */
if(!s->budget--) { s->failed_pc=0x0c096bcau; return 0; }
r[0]+=0xffffffffu;
goto P_0c096bcc;
P_0c096bcc: /* original 0b24, guest PC 0x0c096bcc */
if(!s->budget--) { s->failed_pc=0x0c096bccu; return 0; }
write(ram,r[11]+r[0],r[2],1);
goto P_0c096bce;
P_0c096bce: /* original 6023, guest PC 0x0c096bce */
if(!s->budget--) { s->failed_pc=0x0c096bceu; return 0; }
r[0]=r[2];
goto P_0c096bd0;
P_0c096bd0: /* original 944b, guest PC 0x0c096bd0 */
if(!s->budget--) { s->failed_pc=0x0c096bd0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c096c6au,2);
goto P_0c096bd2;
P_0c096bd2: /* original 34ec, guest PC 0x0c096bd2 */
if(!s->budget--) { s->failed_pc=0x0c096bd2u; return 0; }
r[4]+=r[14];
goto P_0c096bd4;
P_0c096bd4: /* original 804d, guest PC 0x0c096bd4 */
if(!s->budget--) { s->failed_pc=0x0c096bd4u; return 0; }
write(ram,r[4]+13,r[0],1);
goto P_0c096bd6;
P_0c096bd6: /* original 804c, guest PC 0x0c096bd6 */
if(!s->budget--) { s->failed_pc=0x0c096bd6u; return 0; }
write(ram,r[4]+12,r[0],1);
goto P_0c096bd8;
P_0c096bd8: /* original 804b, guest PC 0x0c096bd8 */
if(!s->budget--) { s->failed_pc=0x0c096bd8u; return 0; }
write(ram,r[4]+11,r[0],1);
goto P_0c096bda;
P_0c096bda: /* original 804a, guest PC 0x0c096bda */
if(!s->budget--) { s->failed_pc=0x0c096bdau; return 0; }
write(ram,r[4]+10,r[0],1);
goto P_0c096bdc;
P_0c096bdc: /* original 8049, guest PC 0x0c096bdc */
if(!s->budget--) { s->failed_pc=0x0c096bdcu; return 0; }
write(ram,r[4]+9,r[0],1);
goto P_0c096bde;
P_0c096bde: /* original 8048, guest PC 0x0c096bde */
if(!s->budget--) { s->failed_pc=0x0c096bdeu; return 0; }
write(ram,r[4]+8,r[0],1);
goto P_0c096be0;
P_0c096be0: /* original 8047, guest PC 0x0c096be0 */
if(!s->budget--) { s->failed_pc=0x0c096be0u; return 0; }
write(ram,r[4]+7,r[0],1);
goto P_0c096be2;
P_0c096be2: /* original 8046, guest PC 0x0c096be2 */
if(!s->budget--) { s->failed_pc=0x0c096be2u; return 0; }
write(ram,r[4]+6,r[0],1);
goto P_0c096be4;
P_0c096be4: /* original 8045, guest PC 0x0c096be4 */
if(!s->budget--) { s->failed_pc=0x0c096be4u; return 0; }
write(ram,r[4]+5,r[0],1);
goto P_0c096be6;
P_0c096be6: /* original 8044, guest PC 0x0c096be6 */
if(!s->budget--) { s->failed_pc=0x0c096be6u; return 0; }
write(ram,r[4]+4,r[0],1);
goto P_0c096be8;
P_0c096be8: /* original 8043, guest PC 0x0c096be8 */
if(!s->budget--) { s->failed_pc=0x0c096be8u; return 0; }
write(ram,r[4]+3,r[0],1);
goto P_0c096bea;
P_0c096bea: /* original 8042, guest PC 0x0c096bea */
if(!s->budget--) { s->failed_pc=0x0c096beau; return 0; }
write(ram,r[4]+2,r[0],1);
goto P_0c096bec;
P_0c096bec: /* original 8041, guest PC 0x0c096bec */
if(!s->budget--) { s->failed_pc=0x0c096becu; return 0; }
write(ram,r[4]+1,r[0],1);
goto P_0c096bee;
P_0c096bee: /* original 2400, guest PC 0x0c096bee */
if(!s->budget--) { s->failed_pc=0x0c096beeu; return 0; }
write(ram,r[4],r[0],1);
goto P_0c096bf0;
P_0c096bf0: /* original e061, guest PC 0x0c096bf0 */
if(!s->budget--) { s->failed_pc=0x0c096bf0u; return 0; }
r[0]=0x00000061u;
goto P_0c096bf2;
P_0c096bf2: /* original 0824, guest PC 0x0c096bf2 */
if(!s->budget--) { s->failed_pc=0x0c096bf2u; return 0; }
write(ram,r[8]+r[0],r[2],1);
goto P_0c096bf4;
P_0c096bf4: /* original e203, guest PC 0x0c096bf4 */
if(!s->budget--) { s->failed_pc=0x0c096bf4u; return 0; }
r[2]=0x00000003u;
goto P_0c096bf6;
P_0c096bf6: /* original 0924, guest PC 0x0c096bf6 */
if(!s->budget--) { s->failed_pc=0x0c096bf6u; return 0; }
write(ram,r[9]+r[0],r[2],1);
goto P_0c096bf8;
P_0c096bf8: /* original e410, guest PC 0x0c096bf8 */
if(!s->budget--) { s->failed_pc=0x0c096bf8u; return 0; }
r[4]=0x00000010u;
goto P_0c096bfa;
P_0c096bfa: /* original e032, guest PC 0x0c096bfa */
if(!s->budget--) { s->failed_pc=0x0c096bfau; return 0; }
r[0]=0x00000032u;
goto P_0c096bfc;
P_0c096bfc: /* original 05d4, guest PC 0x0c096bfc */
if(!s->budget--) { s->failed_pc=0x0c096bfcu; return 0; }
write(ram,r[5]+r[0],r[13],1);
goto P_0c096bfe;
P_0c096bfe: /* original e205, guest PC 0x0c096bfe */
if(!s->budget--) { s->failed_pc=0x0c096bfeu; return 0; }
r[2]=0x00000005u;
goto P_0c096c00;
P_0c096c00: /* original 0644, guest PC 0x0c096c00 */
if(!s->budget--) { s->failed_pc=0x0c096c00u; return 0; }
write(ram,r[6]+r[0],r[4],1);
goto P_0c096c02;
P_0c096c02: /* original e033, guest PC 0x0c096c02 */
if(!s->budget--) { s->failed_pc=0x0c096c02u; return 0; }
r[0]=0x00000033u;
goto P_0c096c04;
P_0c096c04: /* original 05d4, guest PC 0x0c096c04 */
if(!s->budget--) { s->failed_pc=0x0c096c04u; return 0; }
write(ram,r[5]+r[0],r[13],1);
goto P_0c096c06;
P_0c096c06: /* original 0644, guest PC 0x0c096c06 */
if(!s->budget--) { s->failed_pc=0x0c096c06u; return 0; }
write(ram,r[6]+r[0],r[4],1);
goto P_0c096c08;
P_0c096c08: /* original e068, guest PC 0x0c096c08 */
if(!s->budget--) { s->failed_pc=0x0c096c08u; return 0; }
r[0]=0x00000068u;
goto P_0c096c0a;
P_0c096c0a: /* original 05d4, guest PC 0x0c096c0a */
if(!s->budget--) { s->failed_pc=0x0c096c0au; return 0; }
write(ram,r[5]+r[0],r[13],1);
goto P_0c096c0c;
P_0c096c0c: /* original 0644, guest PC 0x0c096c0c */
if(!s->budget--) { s->failed_pc=0x0c096c0cu; return 0; }
write(ram,r[6]+r[0],r[4],1);
goto P_0c096c0e;
P_0c096c0e: /* original e034, guest PC 0x0c096c0e */
if(!s->budget--) { s->failed_pc=0x0c096c0eu; return 0; }
r[0]=0x00000034u;
goto P_0c096c10;
P_0c096c10: /* original 05d4, guest PC 0x0c096c10 */
if(!s->budget--) { s->failed_pc=0x0c096c10u; return 0; }
write(ram,r[5]+r[0],r[13],1);
goto P_0c096c12;
P_0c096c12: /* original 06d4, guest PC 0x0c096c12 */
if(!s->budget--) { s->failed_pc=0x0c096c12u; return 0; }
write(ram,r[6]+r[0],r[13],1);
goto P_0c096c14;
P_0c096c14: /* original e035, guest PC 0x0c096c14 */
if(!s->budget--) { s->failed_pc=0x0c096c14u; return 0; }
r[0]=0x00000035u;
goto P_0c096c16;
P_0c096c16: /* original 05d4, guest PC 0x0c096c16 */
if(!s->budget--) { s->failed_pc=0x0c096c16u; return 0; }
write(ram,r[5]+r[0],r[13],1);
goto P_0c096c18;
P_0c096c18: /* original 0624, guest PC 0x0c096c18 */
if(!s->budget--) { s->failed_pc=0x0c096c18u; return 0; }
write(ram,r[6]+r[0],r[2],1);
goto P_0c096c1a;
P_0c096c1a: /* original 62d3, guest PC 0x0c096c1a */
if(!s->budget--) { s->failed_pc=0x0c096c1au; return 0; }
r[2]=r[13];
goto P_0c096c1c;
P_0c096c1c: /* original 1edc, guest PC 0x0c096c1c */
if(!s->budget--) { s->failed_pc=0x0c096c1cu; return 0; }
write(ram,r[14]+48,r[13],4);
goto P_0c096c1e;
P_0c096c1e: /* original 1edd, guest PC 0x0c096c1e */
if(!s->budget--) { s->failed_pc=0x0c096c1eu; return 0; }
write(ram,r[14]+52,r[13],4);
goto P_0c096c20;
P_0c096c20: /* original 1ede, guest PC 0x0c096c20 */
if(!s->budget--) { s->failed_pc=0x0c096c20u; return 0; }
write(ram,r[14]+56,r[13],4);
goto P_0c096c22;
P_0c096c22: /* original 1ed5, guest PC 0x0c096c22 */
if(!s->budget--) { s->failed_pc=0x0c096c22u; return 0; }
write(ram,r[14]+20,r[13],4);
goto P_0c096c24;
P_0c096c24: /* original 9022, guest PC 0x0c096c24 */
if(!s->budget--) { s->failed_pc=0x0c096c24u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c096c6cu,2);
goto P_0c096c26;
P_0c096c26: /* original 0ed6, guest PC 0x0c096c26 */
if(!s->budget--) { s->failed_pc=0x0c096c26u; return 0; }
write(ram,r[14]+r[0],r[13],4);
goto P_0c096c28;
P_0c096c28: /* original e029, guest PC 0x0c096c28 */
if(!s->budget--) { s->failed_pc=0x0c096c28u; return 0; }
r[0]=0x00000029u;
goto P_0c096c2a;
P_0c096c2a: /* original 0ed4, guest PC 0x0c096c2a */
if(!s->budget--) { s->failed_pc=0x0c096c2au; return 0; }
write(ram,r[14]+r[0],r[13],1);
goto P_0c096c2c;
P_0c096c2c: /* original 7069, guest PC 0x0c096c2c */
if(!s->budget--) { s->failed_pc=0x0c096c2cu; return 0; }
r[0]+=0x00000069u;
goto P_0c096c2e;
P_0c096c2e: /* original 0e24, guest PC 0x0c096c2e */
if(!s->budget--) { s->failed_pc=0x0c096c2eu; return 0; }
write(ram,r[14]+r[0],r[2],1);
goto P_0c096c30;
P_0c096c30: /* original 6123, guest PC 0x0c096c30 */
if(!s->budget--) { s->failed_pc=0x0c096c30u; return 0; }
r[1]=r[2];
goto P_0c096c32;
P_0c096c32: /* original 901c, guest PC 0x0c096c32 */
if(!s->budget--) { s->failed_pc=0x0c096c32u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c096c6eu,2);
goto P_0c096c34;
P_0c096c34: /* original 0e14, guest PC 0x0c096c34 */
if(!s->budget--) { s->failed_pc=0x0c096c34u; return 0; }
write(ram,r[14]+r[0],r[1],1);
goto P_0c096c36;
P_0c096c36: /* original e02a, guest PC 0x0c096c36 */
if(!s->budget--) { s->failed_pc=0x0c096c36u; return 0; }
r[0]=0x0000002au;
goto P_0c096c38;
P_0c096c38: /* original 0e14, guest PC 0x0c096c38 */
if(!s->budget--) { s->failed_pc=0x0c096c38u; return 0; }
write(ram,r[14]+r[0],r[1],1);
goto P_0c096c3a;
P_0c096c3a: /* original 9019, guest PC 0x0c096c3a */
if(!s->budget--) { s->failed_pc=0x0c096c3au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c096c70u,2);
goto P_0c096c3c;
P_0c096c3c: /* original 0e14, guest PC 0x0c096c3c */
if(!s->budget--) { s->failed_pc=0x0c096c3cu; return 0; }
write(ram,r[14]+r[0],r[1],1);
goto P_0c096c3e;
P_0c096c3e: /* original 9018, guest PC 0x0c096c3e */
if(!s->budget--) { s->failed_pc=0x0c096c3eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c096c72u,2);
goto P_0c096c40;
P_0c096c40: /* original 0e14, guest PC 0x0c096c40 */
if(!s->budget--) { s->failed_pc=0x0c096c40u; return 0; }
write(ram,r[14]+r[0],r[1],1);
goto P_0c096c42;
P_0c096c42: /* original 9017, guest PC 0x0c096c42 */
if(!s->budget--) { s->failed_pc=0x0c096c42u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c096c74u,2);
goto P_0c096c44;
P_0c096c44: /* original 0e14, guest PC 0x0c096c44 */
if(!s->budget--) { s->failed_pc=0x0c096c44u; return 0; }
write(ram,r[14]+r[0],r[1],1);
goto P_0c096c46;
P_0c096c46: /* original 9016, guest PC 0x0c096c46 */
if(!s->budget--) { s->failed_pc=0x0c096c46u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c096c76u,2);
goto P_0c096c48;
P_0c096c48: /* original 0e16, guest PC 0x0c096c48 */
if(!s->budget--) { s->failed_pc=0x0c096c48u; return 0; }
write(ram,r[14]+r[0],r[1],4);
goto P_0c096c4a;
P_0c096c4a: /* original 7078, guest PC 0x0c096c4a */
if(!s->budget--) { s->failed_pc=0x0c096c4au; return 0; }
r[0]+=0x00000078u;
goto P_0c096c4c;
P_0c096c4c: /* original f49d, guest PC 0x0c096c4c */
if(!s->budget--) { s->failed_pc=0x0c096c4cu; return 0; }
fr[4]=0x3f800000u;
goto P_0c096c4e;
P_0c096c4e: /* original fb47, guest PC 0x0c096c4e */
if(!s->budget--) { s->failed_pc=0x0c096c4eu; return 0; }
vf3_matrix_store(s,ram,4,r[11]+r[0]);
goto P_0c096c50;
P_0c096c50: /* original 9012, guest PC 0x0c096c50 */
if(!s->budget--) { s->failed_pc=0x0c096c50u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c096c78u,2);
goto P_0c096c52;
P_0c096c52: /* original fb47, guest PC 0x0c096c52 */
if(!s->budget--) { s->failed_pc=0x0c096c52u; return 0; }
vf3_matrix_store(s,ram,4,r[11]+r[0]);
goto P_0c096c54;
P_0c096c54: /* original 9011, guest PC 0x0c096c54 */
if(!s->budget--) { s->failed_pc=0x0c096c54u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c096c7au,2);
goto P_0c096c56;
P_0c096c56: /* original 0e14, guest PC 0x0c096c56 */
if(!s->budget--) { s->failed_pc=0x0c096c56u; return 0; }
write(ram,r[14]+r[0],r[1],1);
goto P_0c096c58;
P_0c096c58: /* original 7001, guest PC 0x0c096c58 */
if(!s->budget--) { s->failed_pc=0x0c096c58u; return 0; }
r[0]+=0x00000001u;
goto P_0c096c5a;
P_0c096c5a: /* original 0e14, guest PC 0x0c096c5a */
if(!s->budget--) { s->failed_pc=0x0c096c5au; return 0; }
write(ram,r[14]+r[0],r[1],1);
goto P_0c096c5c;
P_0c096c5c: /* original a02a, guest PC 0x0c096c5c */
if(!s->budget--) { s->failed_pc=0x0c096c5cu; return 0; }
goto P_0c096cb4;
P_0c096c5e: /* original 0009, guest PC 0x0c096c5e */
if(!s->budget--) { s->failed_pc=0x0c096c5eu; return 0; }
if(!vf3_matrix_family(0x0c096c60u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c096c60u; return 0; } return 1;
P_0c096cb4: /* original 7001, guest PC 0x0c096cb4 */
if(!s->budget--) { s->failed_pc=0x0c096cb4u; return 0; }
r[0]+=0x00000001u;
goto P_0c096cb6;
P_0c096cb6: /* original 0e14, guest PC 0x0c096cb6 */
if(!s->budget--) { s->failed_pc=0x0c096cb6u; return 0; }
write(ram,r[14]+r[0],r[1],1);
goto P_0c096cb8;
P_0c096cb8: /* original 7001, guest PC 0x0c096cb8 */
if(!s->budget--) { s->failed_pc=0x0c096cb8u; return 0; }
r[0]+=0x00000001u;
goto P_0c096cba;
P_0c096cba: /* original 0e14, guest PC 0x0c096cba */
if(!s->budget--) { s->failed_pc=0x0c096cbau; return 0; }
write(ram,r[14]+r[0],r[1],1);
goto P_0c096cbc;
P_0c096cbc: /* original e201, guest PC 0x0c096cbc */
if(!s->budget--) { s->failed_pc=0x0c096cbcu; return 0; }
r[2]=0x00000001u;
goto P_0c096cbe;
P_0c096cbe: /* original 9090, guest PC 0x0c096cbe */
if(!s->budget--) { s->failed_pc=0x0c096cbeu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c096de2u,2);
goto P_0c096cc0;
P_0c096cc0: /* original 0b16, guest PC 0x0c096cc0 */
if(!s->budget--) { s->failed_pc=0x0c096cc0u; return 0; }
write(ram,r[11]+r[0],r[1],4);
goto P_0c096cc2;
P_0c096cc2: /* original e040, guest PC 0x0c096cc2 */
if(!s->budget--) { s->failed_pc=0x0c096cc2u; return 0; }
r[0]=0x00000040u;
goto P_0c096cc4;
P_0c096cc4: /* original 04ce, guest PC 0x0c096cc4 */
if(!s->budget--) { s->failed_pc=0x0c096cc4u; return 0; }
r[4]=read(ram,r[12]+r[0],4);
goto P_0c096cc6;
P_0c096cc6: /* original e020, guest PC 0x0c096cc6 */
if(!s->budget--) { s->failed_pc=0x0c096cc6u; return 0; }
r[0]=0x00000020u;
goto P_0c096cc8;
P_0c096cc8: /* original 55cf, guest PC 0x0c096cc8 */
if(!s->budget--) { s->failed_pc=0x0c096cc8u; return 0; }
r[5]=read(ram,r[12]+60,4);
goto P_0c096cca;
P_0c096cca: /* original 0515, guest PC 0x0c096cca */
if(!s->budget--) { s->failed_pc=0x0c096ccau; return 0; }
write(ram,r[5]+r[0],r[1],2);
goto P_0c096ccc;
P_0c096ccc: /* original 0415, guest PC 0x0c096ccc */
if(!s->budget--) { s->failed_pc=0x0c096cccu; return 0; }
write(ram,r[4]+r[0],r[1],2);
goto P_0c096cce;
P_0c096cce: /* original e01c, guest PC 0x0c096cce */
if(!s->budget--) { s->failed_pc=0x0c096cceu; return 0; }
r[0]=0x0000001cu;
goto P_0c096cd0;
P_0c096cd0: /* original 0e24, guest PC 0x0c096cd0 */
if(!s->budget--) { s->failed_pc=0x0c096cd0u; return 0; }
write(ram,r[14]+r[0],r[2],1);
goto P_0c096cd2;
P_0c096cd2: /* original 51e2, guest PC 0x0c096cd2 */
if(!s->budget--) { s->failed_pc=0x0c096cd2u; return 0; }
r[1]=read(ram,r[14]+8,4);
goto P_0c096cd4;
P_0c096cd4: /* original d246, guest PC 0x0c096cd4 */
if(!s->budget--) { s->failed_pc=0x0c096cd4u; return 0; }
r[2]=read(ram,0x0c096df0u,4);
goto P_0c096cd6;
P_0c096cd6: /* original 2129, guest PC 0x0c096cd6 */
if(!s->budget--) { s->failed_pc=0x0c096cd6u; return 0; }
r[1]&=r[2];
goto P_0c096cd8;
P_0c096cd8: /* original 1e12, guest PC 0x0c096cd8 */
if(!s->budget--) { s->failed_pc=0x0c096cd8u; return 0; }
write(ram,r[14]+8,r[1],4);
goto P_0c096cda;
P_0c096cda: /* original 54f1, guest PC 0x0c096cda */
if(!s->budget--) { s->failed_pc=0x0c096cdau; return 0; }
r[4]=read(ram,r[15]+4,4);
goto P_0c096cdc;
P_0c096cdc: /* original d345, guest PC 0x0c096cdc */
if(!s->budget--) { s->failed_pc=0x0c096cdcu; return 0; }
r[3]=read(ram,0x0c096df4u,4);
goto P_0c096cde;
P_0c096cde: /* original 430b, guest PC 0x0c096cde */
if(!s->budget--) { s->failed_pc=0x0c096cdeu; return 0; }
target=r[3];
r[16]=code_base|0x0c096ce2u;
r[4]+=0x00000013u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c096ce2u) { target=s->pc; goto dispatch; }
goto P_0c096ce2;
P_0c096ce0: /* original 7413, guest PC 0x0c096ce0 */
if(!s->budget--) { s->failed_pc=0x0c096ce0u; return 0; }
r[4]+=0x00000013u;
goto P_0c096ce2;
P_0c096ce2: /* original 640c, guest PC 0x0c096ce2 */
if(!s->budget--) { s->failed_pc=0x0c096ce2u; return 0; }
r[4]=r[0]&255u;
goto P_0c096ce4;
P_0c096ce4: /* original 2448, guest PC 0x0c096ce4 */
if(!s->budget--) { s->failed_pc=0x0c096ce4u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c096ce6;
P_0c096ce6: /* original 8b01, guest PC 0x0c096ce6 */
if(!s->budget--) { s->failed_pc=0x0c096ce6u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c096cec; }
goto P_0c096ce8;
P_0c096ce8: /* original 907c, guest PC 0x0c096ce8 */
if(!s->budget--) { s->failed_pc=0x0c096ce8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c096de4u,2);
goto P_0c096cea;
P_0c096cea: /* original 0e46, guest PC 0x0c096cea */
if(!s->budget--) { s->failed_pc=0x0c096ceau; return 0; }
write(ram,r[14]+r[0],r[4],4);
goto P_0c096cec;
P_0c096cec: /* original 907b, guest PC 0x0c096cec */
if(!s->budget--) { s->failed_pc=0x0c096cecu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c096de6u,2);
goto P_0c096cee;
P_0c096cee: /* original e202, guest PC 0x0c096cee */
if(!s->budget--) { s->failed_pc=0x0c096ceeu; return 0; }
r[2]=0x00000002u;
goto P_0c096cf0;
P_0c096cf0: /* original 63f2, guest PC 0x0c096cf0 */
if(!s->budget--) { s->failed_pc=0x0c096cf0u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c096cf2;
P_0c096cf2: /* original 03a4, guest PC 0x0c096cf2 */
if(!s->budget--) { s->failed_pc=0x0c096cf2u; return 0; }
write(ram,r[3]+r[0],r[10],1);
goto P_0c096cf4;
P_0c096cf4: /* original 9079, guest PC 0x0c096cf4 */
if(!s->budget--) { s->failed_pc=0x0c096cf4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c096deau,2);
goto P_0c096cf6;
P_0c096cf6: /* original 9377, guest PC 0x0c096cf6 */
if(!s->budget--) { s->failed_pc=0x0c096cf6u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c096de8u,2);
goto P_0c096cf8;
P_0c096cf8: /* original 0934, guest PC 0x0c096cf8 */
if(!s->budget--) { s->failed_pc=0x0c096cf8u; return 0; }
write(ram,r[9]+r[0],r[3],1);
goto P_0c096cfa;
P_0c096cfa: /* original 0834, guest PC 0x0c096cfa */
if(!s->budget--) { s->failed_pc=0x0c096cfau; return 0; }
write(ram,r[8]+r[0],r[3],1);
goto P_0c096cfc;
P_0c096cfc: /* original 9076, guest PC 0x0c096cfc */
if(!s->budget--) { s->failed_pc=0x0c096cfcu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c096decu,2);
goto P_0c096cfe;
P_0c096cfe: /* original d33e, guest PC 0x0c096cfe */
if(!s->budget--) { s->failed_pc=0x0c096cfeu; return 0; }
r[3]=read(ram,0x0c096df8u,4);
goto P_0c096d00;
P_0c096d00: /* original 430b, guest PC 0x0c096d00 */
if(!s->budget--) { s->failed_pc=0x0c096d00u; return 0; }
target=r[3];
r[16]=code_base|0x0c096d04u;
write(ram,r[14]+r[0],r[2],1);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c096d04u) { target=s->pc; goto dispatch; }
goto P_0c096d04;
P_0c096d02: /* original 0e24, guest PC 0x0c096d02 */
if(!s->budget--) { s->failed_pc=0x0c096d02u; return 0; }
write(ram,r[14]+r[0],r[2],1);
goto P_0c096d04;
P_0c096d04: /* original d23e, guest PC 0x0c096d04 */
if(!s->budget--) { s->failed_pc=0x0c096d04u; return 0; }
r[2]=read(ram,0x0c096e00u,4);
goto P_0c096d06;
P_0c096d06: /* original d43d, guest PC 0x0c096d06 */
if(!s->budget--) { s->failed_pc=0x0c096d06u; return 0; }
r[4]=read(ram,0x0c096dfcu,4);
goto P_0c096d08;
P_0c096d08: /* original 420b, guest PC 0x0c096d08 */
if(!s->budget--) { s->failed_pc=0x0c096d08u; return 0; }
target=r[2];
r[16]=code_base|0x0c096d0cu;
r[5]=0x00000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c096d0cu) { target=s->pc; goto dispatch; }
goto P_0c096d0c;
P_0c096d0a: /* original e500, guest PC 0x0c096d0a */
if(!s->budget--) { s->failed_pc=0x0c096d0au; return 0; }
r[5]=0x00000000u;
goto P_0c096d0c;
P_0c096d0c: /* original d33c, guest PC 0x0c096d0c */
if(!s->budget--) { s->failed_pc=0x0c096d0cu; return 0; }
r[3]=read(ram,0x0c096e00u,4);
goto P_0c096d0e;
P_0c096d0e: /* original e500, guest PC 0x0c096d0e */
if(!s->budget--) { s->failed_pc=0x0c096d0eu; return 0; }
r[5]=0x00000000u;
goto P_0c096d10;
P_0c096d10: /* original 430b, guest PC 0x0c096d10 */
if(!s->budget--) { s->failed_pc=0x0c096d10u; return 0; }
target=r[3];
r[16]=code_base|0x0c096d14u;
r[4]=0xffffffffu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c096d14u) { target=s->pc; goto dispatch; }
goto P_0c096d14;
P_0c096d12: /* original e4ff, guest PC 0x0c096d12 */
if(!s->budget--) { s->failed_pc=0x0c096d12u; return 0; }
r[4]=0xffffffffu;
goto P_0c096d14;
P_0c096d14: /* original 7f08, guest PC 0x0c096d14 */
if(!s->budget--) { s->failed_pc=0x0c096d14u; return 0; }
r[15]+=0x00000008u;
goto P_0c096d16;
P_0c096d16: /* original e07d, guest PC 0x0c096d16 */
if(!s->budget--) { s->failed_pc=0x0c096d16u; return 0; }
r[0]=0x0000007du;
goto P_0c096d18;
P_0c096d18: /* original 4f26, guest PC 0x0c096d18 */
if(!s->budget--) { s->failed_pc=0x0c096d18u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c096d1a;
P_0c096d1a: /* original 0ed4, guest PC 0x0c096d1a */
if(!s->budget--) { s->failed_pc=0x0c096d1au; return 0; }
write(ram,r[14]+r[0],r[13],1);
goto P_0c096d1c;
P_0c096d1c: /* original e301, guest PC 0x0c096d1c */
if(!s->budget--) { s->failed_pc=0x0c096d1cu; return 0; }
r[3]=0x00000001u;
goto P_0c096d1e;
P_0c096d1e: /* original e02b, guest PC 0x0c096d1e */
if(!s->budget--) { s->failed_pc=0x0c096d1eu; return 0; }
r[0]=0x0000002bu;
goto P_0c096d20;
P_0c096d20: /* original 0e34, guest PC 0x0c096d20 */
if(!s->budget--) { s->failed_pc=0x0c096d20u; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c096d22;
P_0c096d22: /* original 60d3, guest PC 0x0c096d22 */
if(!s->budget--) { s->failed_pc=0x0c096d22u; return 0; }
r[0]=r[13];
goto P_0c096d24;
P_0c096d24: /* original 80bb, guest PC 0x0c096d24 */
if(!s->budget--) { s->failed_pc=0x0c096d24u; return 0; }
write(ram,r[11]+11,r[0],1);
goto P_0c096d26;
P_0c096d26: /* original 84ba, guest PC 0x0c096d26 */
if(!s->budget--) { s->failed_pc=0x0c096d26u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[11]+10,1);
goto P_0c096d28;
P_0c096d28: /* original 7001, guest PC 0x0c096d28 */
if(!s->budget--) { s->failed_pc=0x0c096d28u; return 0; }
r[0]+=0x00000001u;
goto P_0c096d2a;
P_0c096d2a: /* original 80ba, guest PC 0x0c096d2a */
if(!s->budget--) { s->failed_pc=0x0c096d2au; return 0; }
write(ram,r[11]+10,r[0],1);
goto P_0c096d2c;
P_0c096d2c: /* original 68f6, guest PC 0x0c096d2c */
if(!s->budget--) { s->failed_pc=0x0c096d2cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c096d2e;
P_0c096d2e: /* original 69f6, guest PC 0x0c096d2e */
if(!s->budget--) { s->failed_pc=0x0c096d2eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c096d30;
P_0c096d30: /* original 6af6, guest PC 0x0c096d30 */
if(!s->budget--) { s->failed_pc=0x0c096d30u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c096d32;
P_0c096d32: /* original 6bf6, guest PC 0x0c096d32 */
if(!s->budget--) { s->failed_pc=0x0c096d32u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c096d34;
P_0c096d34: /* original 6cf6, guest PC 0x0c096d34 */
if(!s->budget--) { s->failed_pc=0x0c096d34u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c096d36;
P_0c096d36: /* original 6df6, guest PC 0x0c096d36 */
if(!s->budget--) { s->failed_pc=0x0c096d36u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c096d38;
P_0c096d38: /* original a000, guest PC 0x0c096d38 */
if(!s->budget--) { s->failed_pc=0x0c096d38u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c096d3c;
P_0c096d3a: /* original 6ef6, guest PC 0x0c096d3a */
if(!s->budget--) { s->failed_pc=0x0c096d3au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c096d3c;
P_0c096d3c: /* original d431, guest PC 0x0c096d3c */
if(!s->budget--) { s->failed_pc=0x0c096d3cu; return 0; }
r[4]=read(ram,0x0c096e04u,4);
goto P_0c096d3e;
P_0c096d3e: /* original 7ffc, guest PC 0x0c096d3e */
if(!s->budget--) { s->failed_pc=0x0c096d3eu; return 0; }
r[15]+=0xfffffffcu;
goto P_0c096d40;
P_0c096d40: /* original 844b, guest PC 0x0c096d40 */
if(!s->budget--) { s->failed_pc=0x0c096d40u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+11,1);
goto P_0c096d42;
P_0c096d42: /* original 650c, guest PC 0x0c096d42 */
if(!s->budget--) { s->failed_pc=0x0c096d42u; return 0; }
r[5]=r[0]&255u;
goto P_0c096d44;
P_0c096d44: /* original 6053, guest PC 0x0c096d44 */
if(!s->budget--) { s->failed_pc=0x0c096d44u; return 0; }
r[0]=r[5];
goto P_0c096d46;
P_0c096d46: /* original 8049, guest PC 0x0c096d46 */
if(!s->budget--) { s->failed_pc=0x0c096d46u; return 0; }
write(ram,r[4]+9,r[0],1);
goto P_0c096d48;
P_0c096d48: /* original d22f, guest PC 0x0c096d48 */
if(!s->budget--) { s->failed_pc=0x0c096d48u; return 0; }
r[2]=read(ram,0x0c096e08u,4);
goto P_0c096d4a;
P_0c096d4a: /* original 635b, guest PC 0x0c096d4a */
if(!s->budget--) { s->failed_pc=0x0c096d4au; return 0; }
r[3]=0u-r[5];
goto P_0c096d4c;
P_0c096d4c: /* original 4508, guest PC 0x0c096d4c */
if(!s->budget--) { s->failed_pc=0x0c096d4cu; return 0; }
r[5]<<=2;
goto P_0c096d4e;
P_0c096d4e: /* original 423d, guest PC 0x0c096d4e */
if(!s->budget--) { s->failed_pc=0x0c096d4eu; return 0; }
r[2]=(r[3]&0x80000000u)?((r[3]&31u)?r[2]>>((-r[3])&31u):0):r[2]<<(r[3]&31u);
goto P_0c096d50;
P_0c096d50: /* original 1421, guest PC 0x0c096d50 */
if(!s->budget--) { s->failed_pc=0x0c096d50u; return 0; }
write(ram,r[4]+4,r[2],4);
goto P_0c096d52;
P_0c096d52: /* original d02e, guest PC 0x0c096d52 */
if(!s->budget--) { s->failed_pc=0x0c096d52u; return 0; }
r[0]=read(ram,0x0c096e0cu,4);
goto P_0c096d54;
P_0c096d54: /* original 035e, guest PC 0x0c096d54 */
if(!s->budget--) { s->failed_pc=0x0c096d54u; return 0; }
r[3]=read(ram,r[5]+r[0],4);
goto P_0c096d56;
P_0c096d56: /* original 6233, guest PC 0x0c096d56 */
if(!s->budget--) { s->failed_pc=0x0c096d56u; return 0; }
r[2]=r[3];
goto P_0c096d58;
P_0c096d58: /* original 2f32, guest PC 0x0c096d58 */
if(!s->budget--) { s->failed_pc=0x0c096d58u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c096d5a;
P_0c096d5a: /* original 422b, guest PC 0x0c096d5a */
if(!s->budget--) { s->failed_pc=0x0c096d5au; return 0; }
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
P_0c096d5c: /* original 7f04, guest PC 0x0c096d5c */
if(!s->budget--) { s->failed_pc=0x0c096d5cu; return 0; }
r[15]+=0x00000004u;
if(!vf3_matrix_family(0x0c096d5eu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c096d5eu; return 0; } return 1;
P_0c0a2b98: /* original 2fe6, guest PC 0x0c0a2b98 */
if(!s->budget--) { s->failed_pc=0x0c0a2b98u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a2b9a;
P_0c0a2b9a: /* original 6e43, guest PC 0x0c0a2b9a */
if(!s->budget--) { s->failed_pc=0x0c0a2b9au; return 0; }
r[14]=r[4];
goto P_0c0a2b9c;
P_0c0a2b9c: /* original 2fd6, guest PC 0x0c0a2b9c */
if(!s->budget--) { s->failed_pc=0x0c0a2b9cu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a2b9e;
P_0c0a2b9e: /* original 2fc6, guest PC 0x0c0a2b9e */
if(!s->budget--) { s->failed_pc=0x0c0a2b9eu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a2ba0;
P_0c0a2ba0: /* original 2fb6, guest PC 0x0c0a2ba0 */
if(!s->budget--) { s->failed_pc=0x0c0a2ba0u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a2ba2;
P_0c0a2ba2: /* original 2fa6, guest PC 0x0c0a2ba2 */
if(!s->budget--) { s->failed_pc=0x0c0a2ba2u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a2ba4;
P_0c0a2ba4: /* original 2f96, guest PC 0x0c0a2ba4 */
if(!s->budget--) { s->failed_pc=0x0c0a2ba4u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a2ba6;
P_0c0a2ba6: /* original 2f86, guest PC 0x0c0a2ba6 */
if(!s->budget--) { s->failed_pc=0x0c0a2ba6u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a2ba8;
P_0c0a2ba8: /* original 60e2, guest PC 0x0c0a2ba8 */
if(!s->budget--) { s->failed_pc=0x0c0a2ba8u; return 0; }
tmp=read(ram,r[14],4);
r[0]=tmp;
goto P_0c0a2baa;
P_0c0a2baa: /* original 4f22, guest PC 0x0c0a2baa */
if(!s->budget--) { s->failed_pc=0x0c0a2baau; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0a2bac;
P_0c0a2bac: /* original c880, guest PC 0x0c0a2bac */
if(!s->budget--) { s->failed_pc=0x0c0a2bacu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&128u)==0)!=0);
goto P_0c0a2bae;
P_0c0a2bae: /* original 8938, guest PC 0x0c0a2bae */
if(!s->budget--) { s->failed_pc=0x0c0a2baeu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a2c22; }
goto P_0c0a2bb0;
P_0c0a2bb0: /* original 62e2, guest PC 0x0c0a2bb0 */
if(!s->budget--) { s->failed_pc=0x0c0a2bb0u; return 0; }
tmp=read(ram,r[14],4);
r[2]=tmp;
goto P_0c0a2bb2;
P_0c0a2bb2: /* original d33b, guest PC 0x0c0a2bb2 */
if(!s->budget--) { s->failed_pc=0x0c0a2bb2u; return 0; }
r[3]=read(ram,0x0c0a2ca0u,4);
goto P_0c0a2bb4;
P_0c0a2bb4: /* original 9173, guest PC 0x0c0a2bb4 */
if(!s->budget--) { s->failed_pc=0x0c0a2bb4u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a2c9eu,2);
goto P_0c0a2bb6;
P_0c0a2bb6: /* original 2239, guest PC 0x0c0a2bb6 */
if(!s->budget--) { s->failed_pc=0x0c0a2bb6u; return 0; }
r[2]&=r[3];
goto P_0c0a2bb8;
P_0c0a2bb8: /* original 3210, guest PC 0x0c0a2bb8 */
if(!s->budget--) { s->failed_pc=0x0c0a2bb8u; return 0; }
r[17]=(r[17]&~1u)|((r[2]==r[1])!=0);
goto P_0c0a2bba;
P_0c0a2bba: /* original 8905, guest PC 0x0c0a2bba */
if(!s->budget--) { s->failed_pc=0x0c0a2bbau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a2bc8; }
goto P_0c0a2bbc;
P_0c0a2bbc: /* original d239, guest PC 0x0c0a2bbc */
if(!s->budget--) { s->failed_pc=0x0c0a2bbcu; return 0; }
r[2]=read(ram,0x0c0a2ca4u,4);
goto P_0c0a2bbe;
P_0c0a2bbe: /* original e56a, guest PC 0x0c0a2bbe */
if(!s->budget--) { s->failed_pc=0x0c0a2bbeu; return 0; }
r[5]=0x0000006au;
goto P_0c0a2bc0;
P_0c0a2bc0: /* original 420b, guest PC 0x0c0a2bc0 */
if(!s->budget--) { s->failed_pc=0x0c0a2bc0u; return 0; }
target=r[2];
r[16]=code_base|0x0c0a2bc4u;
r[4]=0x00000001u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a2bc4u) { target=s->pc; goto dispatch; }
goto P_0c0a2bc4;
P_0c0a2bc2: /* original e401, guest PC 0x0c0a2bc2 */
if(!s->budget--) { s->failed_pc=0x0c0a2bc2u; return 0; }
r[4]=0x00000001u;
goto P_0c0a2bc4;
P_0c0a2bc4: /* original a02e, guest PC 0x0c0a2bc4 */
if(!s->budget--) { s->failed_pc=0x0c0a2bc4u; return 0; }
r[0]=0xffffffffu;
goto P_0c0a2c24;
P_0c0a2bc6: /* original e0ff, guest PC 0x0c0a2bc6 */
if(!s->budget--) { s->failed_pc=0x0c0a2bc6u; return 0; }
r[0]=0xffffffffu;
goto P_0c0a2bc8;
P_0c0a2bc8: /* original e020, guest PC 0x0c0a2bc8 */
if(!s->budget--) { s->failed_pc=0x0c0a2bc8u; return 0; }
r[0]=0x00000020u;
goto P_0c0a2bca;
P_0c0a2bca: /* original 03ed, guest PC 0x0c0a2bca */
if(!s->budget--) { s->failed_pc=0x0c0a2bcau; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0a2bcc;
P_0c0a2bcc: /* original e022, guest PC 0x0c0a2bcc */
if(!s->budget--) { s->failed_pc=0x0c0a2bccu; return 0; }
r[0]=0x00000022u;
goto P_0c0a2bce;
P_0c0a2bce: /* original 02ed, guest PC 0x0c0a2bce */
if(!s->budget--) { s->failed_pc=0x0c0a2bceu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0a2bd0;
P_0c0a2bd0: /* original 633d, guest PC 0x0c0a2bd0 */
if(!s->budget--) { s->failed_pc=0x0c0a2bd0u; return 0; }
r[3]=r[3]&65535u;
goto P_0c0a2bd2;
P_0c0a2bd2: /* original 622d, guest PC 0x0c0a2bd2 */
if(!s->budget--) { s->failed_pc=0x0c0a2bd2u; return 0; }
r[2]=r[2]&65535u;
goto P_0c0a2bd4;
P_0c0a2bd4: /* original 232b, guest PC 0x0c0a2bd4 */
if(!s->budget--) { s->failed_pc=0x0c0a2bd4u; return 0; }
r[3]|=r[2];
goto P_0c0a2bd6;
P_0c0a2bd6: /* original 2338, guest PC 0x0c0a2bd6 */
if(!s->budget--) { s->failed_pc=0x0c0a2bd6u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c0a2bd8;
P_0c0a2bd8: /* original 8923, guest PC 0x0c0a2bd8 */
if(!s->budget--) { s->failed_pc=0x0c0a2bd8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a2c22; }
goto P_0c0a2bda;
P_0c0a2bda: /* original e020, guest PC 0x0c0a2bda */
if(!s->budget--) { s->failed_pc=0x0c0a2bdau; return 0; }
r[0]=0x00000020u;
goto P_0c0a2bdc;
P_0c0a2bdc: /* original d332, guest PC 0x0c0a2bdc */
if(!s->budget--) { s->failed_pc=0x0c0a2bdcu; return 0; }
r[3]=read(ram,0x0c0a2ca8u,4);
goto P_0c0a2bde;
P_0c0a2bde: /* original 04ed, guest PC 0x0c0a2bde */
if(!s->budget--) { s->failed_pc=0x0c0a2bdeu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0a2be0;
P_0c0a2be0: /* original 430b, guest PC 0x0c0a2be0 */
if(!s->budget--) { s->failed_pc=0x0c0a2be0u; return 0; }
target=r[3];
r[16]=code_base|0x0c0a2be4u;
r[4]=r[4]&65535u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a2be4u) { target=s->pc; goto dispatch; }
goto P_0c0a2be4;
P_0c0a2be2: /* original 644d, guest PC 0x0c0a2be2 */
if(!s->budget--) { s->failed_pc=0x0c0a2be2u; return 0; }
r[4]=r[4]&65535u;
goto P_0c0a2be4;
P_0c0a2be4: /* original d932, guest PC 0x0c0a2be4 */
if(!s->budget--) { s->failed_pc=0x0c0a2be4u; return 0; }
r[9]=read(ram,0x0c0a2cb0u,4);
goto P_0c0a2be6;
P_0c0a2be6: /* original eb01, guest PC 0x0c0a2be6 */
if(!s->budget--) { s->failed_pc=0x0c0a2be6u; return 0; }
r[11]=0x00000001u;
goto P_0c0a2be8;
P_0c0a2be8: /* original d830, guest PC 0x0c0a2be8 */
if(!s->budget--) { s->failed_pc=0x0c0a2be8u; return 0; }
r[8]=read(ram,0x0c0a2cacu,4);
goto P_0c0a2bea;
P_0c0a2bea: /* original 5ae4, guest PC 0x0c0a2bea */
if(!s->budget--) { s->failed_pc=0x0c0a2beau; return 0; }
r[10]=read(ram,r[14]+16,4);
goto P_0c0a2bec;
P_0c0a2bec: /* original a010, guest PC 0x0c0a2bec */
if(!s->budget--) { s->failed_pc=0x0c0a2becu; return 0; }
r[12]=0x00000000u;
goto P_0c0a2c10;
P_0c0a2bee: /* original ec00, guest PC 0x0c0a2bee */
if(!s->budget--) { s->failed_pc=0x0c0a2beeu; return 0; }
r[12]=0x00000000u;
goto P_0c0a2bf0;
P_0c0a2bf0: /* original 6dc3, guest PC 0x0c0a2bf0 */
if(!s->budget--) { s->failed_pc=0x0c0a2bf0u; return 0; }
r[13]=r[12];
goto P_0c0a2bf2;
P_0c0a2bf2: /* original 4d08, guest PC 0x0c0a2bf2 */
if(!s->budget--) { s->failed_pc=0x0c0a2bf2u; return 0; }
r[13]<<=2;
goto P_0c0a2bf4;
P_0c0a2bf4: /* original 3dac, guest PC 0x0c0a2bf4 */
if(!s->budget--) { s->failed_pc=0x0c0a2bf4u; return 0; }
r[13]+=r[10];
goto P_0c0a2bf6;
P_0c0a2bf6: /* original 63d2, guest PC 0x0c0a2bf6 */
if(!s->budget--) { s->failed_pc=0x0c0a2bf6u; return 0; }
tmp=read(ram,r[13],4);
r[3]=tmp;
goto P_0c0a2bf8;
P_0c0a2bf8: /* original 5231, guest PC 0x0c0a2bf8 */
if(!s->budget--) { s->failed_pc=0x0c0a2bf8u; return 0; }
r[2]=read(ram,r[3]+4,4);
goto P_0c0a2bfa;
P_0c0a2bfa: /* original 22b8, guest PC 0x0c0a2bfa */
if(!s->budget--) { s->failed_pc=0x0c0a2bfau; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[11])==0)!=0);
goto P_0c0a2bfc;
P_0c0a2bfc: /* original 8903, guest PC 0x0c0a2bfc */
if(!s->budget--) { s->failed_pc=0x0c0a2bfcu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a2c06; }
goto P_0c0a2bfe;
P_0c0a2bfe: /* original 480b, guest PC 0x0c0a2bfe */
if(!s->budget--) { s->failed_pc=0x0c0a2bfeu; return 0; }
target=r[8];
r[16]=code_base|0x0c0a2c02u;
tmp=read(ram,r[13],4);
r[4]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a2c02u) { target=s->pc; goto dispatch; }
goto P_0c0a2c02;
P_0c0a2c00: /* original 64d2, guest PC 0x0c0a2c00 */
if(!s->budget--) { s->failed_pc=0x0c0a2c00u; return 0; }
tmp=read(ram,r[13],4);
r[4]=tmp;
goto P_0c0a2c02;
P_0c0a2c02: /* original a004, guest PC 0x0c0a2c02 */
if(!s->budget--) { s->failed_pc=0x0c0a2c02u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c0a2c0e;
P_0c0a2c04: /* original 2008, guest PC 0x0c0a2c04 */
if(!s->budget--) { s->failed_pc=0x0c0a2c04u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c0a2c06;
P_0c0a2c06: /* original 64d2, guest PC 0x0c0a2c06 */
if(!s->budget--) { s->failed_pc=0x0c0a2c06u; return 0; }
tmp=read(ram,r[13],4);
r[4]=tmp;
goto P_0c0a2c08;
P_0c0a2c08: /* original 490b, guest PC 0x0c0a2c08 */
if(!s->budget--) { s->failed_pc=0x0c0a2c08u; return 0; }
target=r[9];
r[16]=code_base|0x0c0a2c0cu;
r[4]=read(ram,r[4]+4,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a2c0cu) { target=s->pc; goto dispatch; }
goto P_0c0a2c0c;
P_0c0a2c0a: /* original 5441, guest PC 0x0c0a2c0a */
if(!s->budget--) { s->failed_pc=0x0c0a2c0au; return 0; }
r[4]=read(ram,r[4]+4,4);
goto P_0c0a2c0c;
P_0c0a2c0c: /* original 2008, guest PC 0x0c0a2c0c */
if(!s->budget--) { s->failed_pc=0x0c0a2c0cu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c0a2c0e;
P_0c0a2c0e: /* original 7c01, guest PC 0x0c0a2c0e */
if(!s->budget--) { s->failed_pc=0x0c0a2c0eu; return 0; }
r[12]+=0x00000001u;
goto P_0c0a2c10;
P_0c0a2c10: /* original 85e6, guest PC 0x0c0a2c10 */
if(!s->budget--) { s->failed_pc=0x0c0a2c10u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+12,2);
goto P_0c0a2c12;
P_0c0a2c12: /* original 600d, guest PC 0x0c0a2c12 */
if(!s->budget--) { s->failed_pc=0x0c0a2c12u; return 0; }
r[0]=r[0]&65535u;
goto P_0c0a2c14;
P_0c0a2c14: /* original 3c03, guest PC 0x0c0a2c14 */
if(!s->budget--) { s->failed_pc=0x0c0a2c14u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[12]>=(int32_t)r[0])!=0);
goto P_0c0a2c16;
P_0c0a2c16: /* original 8beb, guest PC 0x0c0a2c16 */
if(!s->budget--) { s->failed_pc=0x0c0a2c16u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a2bf0; }
goto P_0c0a2c18;
P_0c0a2c18: /* original e022, guest PC 0x0c0a2c18 */
if(!s->budget--) { s->failed_pc=0x0c0a2c18u; return 0; }
r[0]=0x00000022u;
goto P_0c0a2c1a;
P_0c0a2c1a: /* original e200, guest PC 0x0c0a2c1a */
if(!s->budget--) { s->failed_pc=0x0c0a2c1au; return 0; }
r[2]=0x00000000u;
goto P_0c0a2c1c;
P_0c0a2c1c: /* original 0e25, guest PC 0x0c0a2c1c */
if(!s->budget--) { s->failed_pc=0x0c0a2c1cu; return 0; }
write(ram,r[14]+r[0],r[2],2);
goto P_0c0a2c1e;
P_0c0a2c1e: /* original e020, guest PC 0x0c0a2c1e */
if(!s->budget--) { s->failed_pc=0x0c0a2c1eu; return 0; }
r[0]=0x00000020u;
goto P_0c0a2c20;
P_0c0a2c20: /* original 0e25, guest PC 0x0c0a2c20 */
if(!s->budget--) { s->failed_pc=0x0c0a2c20u; return 0; }
write(ram,r[14]+r[0],r[2],2);
goto P_0c0a2c22;
P_0c0a2c22: /* original e000, guest PC 0x0c0a2c22 */
if(!s->budget--) { s->failed_pc=0x0c0a2c22u; return 0; }
r[0]=0x00000000u;
goto P_0c0a2c24;
P_0c0a2c24: /* original 4f26, guest PC 0x0c0a2c24 */
if(!s->budget--) { s->failed_pc=0x0c0a2c24u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a2c26;
P_0c0a2c26: /* original 68f6, guest PC 0x0c0a2c26 */
if(!s->budget--) { s->failed_pc=0x0c0a2c26u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c0a2c28;
P_0c0a2c28: /* original 69f6, guest PC 0x0c0a2c28 */
if(!s->budget--) { s->failed_pc=0x0c0a2c28u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c0a2c2a;
P_0c0a2c2a: /* original 6af6, guest PC 0x0c0a2c2a */
if(!s->budget--) { s->failed_pc=0x0c0a2c2au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0a2c2c;
P_0c0a2c2c: /* original 6bf6, guest PC 0x0c0a2c2c */
if(!s->budget--) { s->failed_pc=0x0c0a2c2cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0a2c2e;
P_0c0a2c2e: /* original 6cf6, guest PC 0x0c0a2c2e */
if(!s->budget--) { s->failed_pc=0x0c0a2c2eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0a2c30;
P_0c0a2c30: /* original 6df6, guest PC 0x0c0a2c30 */
if(!s->budget--) { s->failed_pc=0x0c0a2c30u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0a2c32;
P_0c0a2c32: /* original 000b, guest PC 0x0c0a2c32 */
if(!s->budget--) { s->failed_pc=0x0c0a2c32u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0a2c34: /* original 6ef6, guest PC 0x0c0a2c34 */
if(!s->budget--) { s->failed_pc=0x0c0a2c34u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0a2c36u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0a2c36u; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
