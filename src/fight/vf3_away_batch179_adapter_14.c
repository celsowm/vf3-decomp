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
int vf3_away_batch179_adapter_14(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c062bfau: goto P_0c062bfa;
case 0x0c062bfcu: goto P_0c062bfc;
case 0x0c062bfeu: goto P_0c062bfe;
case 0x0c062c00u: goto P_0c062c00;
case 0x0c062c02u: goto P_0c062c02;
case 0x0c062c04u: goto P_0c062c04;
case 0x0c062c06u: goto P_0c062c06;
case 0x0c062c08u: goto P_0c062c08;
case 0x0c062c0au: goto P_0c062c0a;
case 0x0c062c0cu: goto P_0c062c0c;
case 0x0c062c0eu: goto P_0c062c0e;
case 0x0c062c10u: goto P_0c062c10;
case 0x0c062c12u: goto P_0c062c12;
case 0x0c062c14u: goto P_0c062c14;
case 0x0c062c16u: goto P_0c062c16;
case 0x0c062c18u: goto P_0c062c18;
case 0x0c062c1au: goto P_0c062c1a;
case 0x0c062c1cu: goto P_0c062c1c;
case 0x0c062c1eu: goto P_0c062c1e;
case 0x0c062c20u: goto P_0c062c20;
case 0x0c062c22u: goto P_0c062c22;
case 0x0c062c24u: goto P_0c062c24;
case 0x0c062c26u: goto P_0c062c26;
case 0x0c062c28u: goto P_0c062c28;
case 0x0c062c2au: goto P_0c062c2a;
case 0x0c062c2cu: goto P_0c062c2c;
case 0x0c062c2eu: goto P_0c062c2e;
case 0x0c062c30u: goto P_0c062c30;
case 0x0c062c32u: goto P_0c062c32;
case 0x0c062c34u: goto P_0c062c34;
case 0x0c062c36u: goto P_0c062c36;
case 0x0c062c38u: goto P_0c062c38;
case 0x0c062c3au: goto P_0c062c3a;
case 0x0c062c3cu: goto P_0c062c3c;
case 0x0c062c3eu: goto P_0c062c3e;
case 0x0c062c40u: goto P_0c062c40;
case 0x0c062c42u: goto P_0c062c42;
case 0x0c062c44u: goto P_0c062c44;
case 0x0c062c46u: goto P_0c062c46;
case 0x0c062c48u: goto P_0c062c48;
case 0x0c062c4au: goto P_0c062c4a;
case 0x0c062c4cu: goto P_0c062c4c;
case 0x0c062c4eu: goto P_0c062c4e;
case 0x0c062c50u: goto P_0c062c50;
case 0x0c062c52u: goto P_0c062c52;
case 0x0c062c54u: goto P_0c062c54;
case 0x0c062c56u: goto P_0c062c56;
case 0x0c062c58u: goto P_0c062c58;
case 0x0c062c5au: goto P_0c062c5a;
case 0x0c062c5cu: goto P_0c062c5c;
case 0x0c062c5eu: goto P_0c062c5e;
case 0x0c062c60u: goto P_0c062c60;
case 0x0c062e7eu: goto P_0c062e7e;
case 0x0c062e80u: goto P_0c062e80;
case 0x0c062e82u: goto P_0c062e82;
case 0x0c062e84u: goto P_0c062e84;
case 0x0c062e86u: goto P_0c062e86;
case 0x0c062e88u: goto P_0c062e88;
case 0x0c062e8au: goto P_0c062e8a;
case 0x0c062e8cu: goto P_0c062e8c;
case 0x0c0644bcu: goto P_0c0644bc;
case 0x0c0644beu: goto P_0c0644be;
case 0x0c0644c0u: goto P_0c0644c0;
case 0x0c0644c2u: goto P_0c0644c2;
case 0x0c0644c4u: goto P_0c0644c4;
case 0x0c0644c6u: goto P_0c0644c6;
case 0x0c0644c8u: goto P_0c0644c8;
case 0x0c0644cau: goto P_0c0644ca;
case 0x0c0644ccu: goto P_0c0644cc;
case 0x0c0644ceu: goto P_0c0644ce;
case 0x0c0644d0u: goto P_0c0644d0;
case 0x0c0644d2u: goto P_0c0644d2;
case 0x0c0644d4u: goto P_0c0644d4;
case 0x0c068c58u: goto P_0c068c58;
case 0x0c068c5au: goto P_0c068c5a;
case 0x0c068c5cu: goto P_0c068c5c;
case 0x0c068c5eu: goto P_0c068c5e;
case 0x0c068c60u: goto P_0c068c60;
case 0x0c068c62u: goto P_0c068c62;
case 0x0c068c64u: goto P_0c068c64;
case 0x0c068c66u: goto P_0c068c66;
case 0x0c068c68u: goto P_0c068c68;
case 0x0c068c6au: goto P_0c068c6a;
case 0x0c068c6cu: goto P_0c068c6c;
case 0x0c068c6eu: goto P_0c068c6e;
case 0x0c068c70u: goto P_0c068c70;
case 0x0c068c72u: goto P_0c068c72;
case 0x0c068c74u: goto P_0c068c74;
case 0x0c068c76u: goto P_0c068c76;
case 0x0c068c78u: goto P_0c068c78;
case 0x0c068c7au: goto P_0c068c7a;
case 0x0c068c7cu: goto P_0c068c7c;
case 0x0c068c7eu: goto P_0c068c7e;
case 0x0c068c80u: goto P_0c068c80;
case 0x0c068c82u: goto P_0c068c82;
case 0x0c068c84u: goto P_0c068c84;
case 0x0c068c86u: goto P_0c068c86;
case 0x0c068c88u: goto P_0c068c88;
case 0x0c068c8au: goto P_0c068c8a;
case 0x0c068c8cu: goto P_0c068c8c;
case 0x0c068c8eu: goto P_0c068c8e;
case 0x0c068c90u: goto P_0c068c90;
case 0x0c068c92u: goto P_0c068c92;
case 0x0c068c94u: goto P_0c068c94;
case 0x0c068c96u: goto P_0c068c96;
case 0x0c068c98u: goto P_0c068c98;
case 0x0c068c9au: goto P_0c068c9a;
case 0x0c068c9cu: goto P_0c068c9c;
case 0x0c068c9eu: goto P_0c068c9e;
case 0x0c068ca0u: goto P_0c068ca0;
case 0x0c068ca2u: goto P_0c068ca2;
case 0x0c068ca4u: goto P_0c068ca4;
case 0x0c068ca6u: goto P_0c068ca6;
case 0x0c068ca8u: goto P_0c068ca8;
case 0x0c068caau: goto P_0c068caa;
case 0x0c068cacu: goto P_0c068cac;
case 0x0c068caeu: goto P_0c068cae;
case 0x0c068cb0u: goto P_0c068cb0;
case 0x0c068cb2u: goto P_0c068cb2;
case 0x0c068cb4u: goto P_0c068cb4;
case 0x0c068cb6u: goto P_0c068cb6;
case 0x0c068cb8u: goto P_0c068cb8;
case 0x0c068cbau: goto P_0c068cba;
case 0x0c068cbcu: goto P_0c068cbc;
case 0x0c068cbeu: goto P_0c068cbe;
case 0x0c068cc0u: goto P_0c068cc0;
case 0x0c068cc2u: goto P_0c068cc2;
case 0x0c068cc4u: goto P_0c068cc4;
case 0x0c068cc6u: goto P_0c068cc6;
case 0x0c068cc8u: goto P_0c068cc8;
case 0x0c068ccau: goto P_0c068cca;
case 0x0c068cccu: goto P_0c068ccc;
case 0x0c068cceu: goto P_0c068cce;
case 0x0c068cd0u: goto P_0c068cd0;
case 0x0c068cd2u: goto P_0c068cd2;
case 0x0c068cd4u: goto P_0c068cd4;
case 0x0c068cd6u: goto P_0c068cd6;
case 0x0c068cd8u: goto P_0c068cd8;
case 0x0c068cdau: goto P_0c068cda;
case 0x0c068cdcu: goto P_0c068cdc;
case 0x0c068cdeu: goto P_0c068cde;
case 0x0c068ce0u: goto P_0c068ce0;
case 0x0c068ce2u: goto P_0c068ce2;
case 0x0c068ce4u: goto P_0c068ce4;
case 0x0c068ce6u: goto P_0c068ce6;
case 0x0c068ce8u: goto P_0c068ce8;
case 0x0c068ceau: goto P_0c068cea;
case 0x0c068cecu: goto P_0c068cec;
case 0x0c068ceeu: goto P_0c068cee;
case 0x0c068cf0u: goto P_0c068cf0;
case 0x0c068cf2u: goto P_0c068cf2;
case 0x0c068cf4u: goto P_0c068cf4;
case 0x0c068cf6u: goto P_0c068cf6;
case 0x0c068cf8u: goto P_0c068cf8;
case 0x0c068cfau: goto P_0c068cfa;
case 0x0c068cfcu: goto P_0c068cfc;
case 0x0c068cfeu: goto P_0c068cfe;
case 0x0c068d00u: goto P_0c068d00;
case 0x0c068d02u: goto P_0c068d02;
case 0x0c068d04u: goto P_0c068d04;
case 0x0c068d06u: goto P_0c068d06;
case 0x0c068d08u: goto P_0c068d08;
case 0x0c068d0au: goto P_0c068d0a;
case 0x0c068d0cu: goto P_0c068d0c;
case 0x0c07a7e8u: goto P_0c07a7e8;
case 0x0c07a7eau: goto P_0c07a7ea;
case 0x0c07a7ecu: goto P_0c07a7ec;
case 0x0c07a7eeu: goto P_0c07a7ee;
case 0x0c07a7f0u: goto P_0c07a7f0;
case 0x0c07a7f2u: goto P_0c07a7f2;
case 0x0c07a7f4u: goto P_0c07a7f4;
case 0x0c07a7f6u: goto P_0c07a7f6;
case 0x0c07a7f8u: goto P_0c07a7f8;
case 0x0c07a7fau: goto P_0c07a7fa;
case 0x0c07a7fcu: goto P_0c07a7fc;
case 0x0c07a7feu: goto P_0c07a7fe;
case 0x0c07a800u: goto P_0c07a800;
case 0x0c07a802u: goto P_0c07a802;
case 0x0c07a804u: goto P_0c07a804;
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
case 0x0c099d62u: goto P_0c099d62;
case 0x0c099d64u: goto P_0c099d64;
case 0x0c099d66u: goto P_0c099d66;
case 0x0c099d68u: goto P_0c099d68;
case 0x0c099d6au: goto P_0c099d6a;
case 0x0c099d6cu: goto P_0c099d6c;
case 0x0c099d6eu: goto P_0c099d6e;
case 0x0c099d70u: goto P_0c099d70;
case 0x0c099d72u: goto P_0c099d72;
case 0x0c099d74u: goto P_0c099d74;
case 0x0c099d76u: goto P_0c099d76;
case 0x0c099d78u: goto P_0c099d78;
case 0x0c099d7au: goto P_0c099d7a;
case 0x0c099d7cu: goto P_0c099d7c;
case 0x0c099d7eu: goto P_0c099d7e;
case 0x0c099d80u: goto P_0c099d80;
case 0x0c099d82u: goto P_0c099d82;
case 0x0c099d84u: goto P_0c099d84;
case 0x0c099d86u: goto P_0c099d86;
case 0x0c099d88u: goto P_0c099d88;
case 0x0c099d8au: goto P_0c099d8a;
case 0x0c099d8cu: goto P_0c099d8c;
case 0x0c099d8eu: goto P_0c099d8e;
case 0x0c099d90u: goto P_0c099d90;
case 0x0c099d92u: goto P_0c099d92;
case 0x0c099d94u: goto P_0c099d94;
case 0x0c099d96u: goto P_0c099d96;
case 0x0c099d98u: goto P_0c099d98;
case 0x0c099d9au: goto P_0c099d9a;
case 0x0c099d9cu: goto P_0c099d9c;
case 0x0c099d9eu: goto P_0c099d9e;
case 0x0c099de0u: goto P_0c099de0;
case 0x0c099de2u: goto P_0c099de2;
case 0x0c099de4u: goto P_0c099de4;
case 0x0c099de6u: goto P_0c099de6;
case 0x0c099de8u: goto P_0c099de8;
case 0x0c099deau: goto P_0c099dea;
case 0x0c099decu: goto P_0c099dec;
case 0x0c099deeu: goto P_0c099dee;
case 0x0c099df0u: goto P_0c099df0;
case 0x0c099df2u: goto P_0c099df2;
case 0x0c099df4u: goto P_0c099df4;
case 0x0c099df6u: goto P_0c099df6;
case 0x0c099df8u: goto P_0c099df8;
case 0x0c099dfau: goto P_0c099dfa;
case 0x0c099dfcu: goto P_0c099dfc;
case 0x0c099dfeu: goto P_0c099dfe;
case 0x0c099e00u: goto P_0c099e00;
case 0x0c099e02u: goto P_0c099e02;
case 0x0c099e04u: goto P_0c099e04;
case 0x0c099e06u: goto P_0c099e06;
case 0x0c099e08u: goto P_0c099e08;
case 0x0c099e0au: goto P_0c099e0a;
case 0x0c099e0cu: goto P_0c099e0c;
case 0x0c099e0eu: goto P_0c099e0e;
case 0x0c099e10u: goto P_0c099e10;
case 0x0c099e12u: goto P_0c099e12;
case 0x0c099e14u: goto P_0c099e14;
case 0x0c099e16u: goto P_0c099e16;
case 0x0c099e18u: goto P_0c099e18;
case 0x0c099e1au: goto P_0c099e1a;
case 0x0c099e1cu: goto P_0c099e1c;
case 0x0c099e1eu: goto P_0c099e1e;
case 0x0c099e20u: goto P_0c099e20;
case 0x0c099e22u: goto P_0c099e22;
case 0x0c099e24u: goto P_0c099e24;
case 0x0c099e26u: goto P_0c099e26;
case 0x0c099e28u: goto P_0c099e28;
case 0x0c099e2au: goto P_0c099e2a;
case 0x0c099e2cu: goto P_0c099e2c;
case 0x0c099e2eu: goto P_0c099e2e;
case 0x0c099e30u: goto P_0c099e30;
case 0x0c099e32u: goto P_0c099e32;
case 0x0c099e34u: goto P_0c099e34;
case 0x0c099e36u: goto P_0c099e36;
case 0x0c099e38u: goto P_0c099e38;
case 0x0c099e3au: goto P_0c099e3a;
case 0x0c099e3cu: goto P_0c099e3c;
case 0x0c099e3eu: goto P_0c099e3e;
case 0x0c099e40u: goto P_0c099e40;
case 0x0c099e42u: goto P_0c099e42;
case 0x0c099e44u: goto P_0c099e44;
case 0x0c099e46u: goto P_0c099e46;
case 0x0c099e48u: goto P_0c099e48;
case 0x0c099e4au: goto P_0c099e4a;
case 0x0c099e4cu: goto P_0c099e4c;
case 0x0c099e4eu: goto P_0c099e4e;
case 0x0c099e50u: goto P_0c099e50;
case 0x0c099e52u: goto P_0c099e52;
case 0x0c099e54u: goto P_0c099e54;
case 0x0c099e56u: goto P_0c099e56;
case 0x0c099e58u: goto P_0c099e58;
case 0x0c099e5au: goto P_0c099e5a;
case 0x0c099e5cu: goto P_0c099e5c;
case 0x0c099e5eu: goto P_0c099e5e;
case 0x0c099e60u: goto P_0c099e60;
case 0x0c099e62u: goto P_0c099e62;
case 0x0c099e64u: goto P_0c099e64;
case 0x0c099e66u: goto P_0c099e66;
case 0x0c099e68u: goto P_0c099e68;
case 0x0c099e6au: goto P_0c099e6a;
case 0x0c099e6cu: goto P_0c099e6c;
case 0x0c099e6eu: goto P_0c099e6e;
case 0x0c099e70u: goto P_0c099e70;
case 0x0c099e72u: goto P_0c099e72;
case 0x0c099e74u: goto P_0c099e74;
case 0x0c099e76u: goto P_0c099e76;
case 0x0c099e78u: goto P_0c099e78;
case 0x0c099e7au: goto P_0c099e7a;
case 0x0c099e7cu: goto P_0c099e7c;
case 0x0c099e7eu: goto P_0c099e7e;
case 0x0c099e80u: goto P_0c099e80;
case 0x0c099e82u: goto P_0c099e82;
case 0x0c099e84u: goto P_0c099e84;
case 0x0c099e86u: goto P_0c099e86;
case 0x0c099e88u: goto P_0c099e88;
case 0x0c099e8au: goto P_0c099e8a;
case 0x0c099e8cu: goto P_0c099e8c;
case 0x0c099e8eu: goto P_0c099e8e;
case 0x0c099e90u: goto P_0c099e90;
case 0x0c099e92u: goto P_0c099e92;
case 0x0c099e94u: goto P_0c099e94;
case 0x0c099e96u: goto P_0c099e96;
case 0x0c099e98u: goto P_0c099e98;
case 0x0c099e9au: goto P_0c099e9a;
case 0x0c099e9cu: goto P_0c099e9c;
case 0x0c099e9eu: goto P_0c099e9e;
case 0x0c099ea0u: goto P_0c099ea0;
case 0x0c099ea2u: goto P_0c099ea2;
case 0x0c099ea4u: goto P_0c099ea4;
case 0x0c099ea6u: goto P_0c099ea6;
case 0x0c099ea8u: goto P_0c099ea8;
case 0x0c099eaau: goto P_0c099eaa;
case 0x0c099eacu: goto P_0c099eac;
case 0x0c099eaeu: goto P_0c099eae;
case 0x0c099eb0u: goto P_0c099eb0;
case 0x0c099eb2u: goto P_0c099eb2;
case 0x0c099eb4u: goto P_0c099eb4;
case 0x0c099eb6u: goto P_0c099eb6;
case 0x0c099eb8u: goto P_0c099eb8;
case 0x0c099ebau: goto P_0c099eba;
case 0x0c099ebcu: goto P_0c099ebc;
case 0x0c099ebeu: goto P_0c099ebe;
case 0x0c099ec0u: goto P_0c099ec0;
case 0x0c099ec2u: goto P_0c099ec2;
case 0x0c099ec4u: goto P_0c099ec4;
case 0x0c099ec6u: goto P_0c099ec6;
case 0x0c099ec8u: goto P_0c099ec8;
case 0x0c099ecau: goto P_0c099eca;
case 0x0c099eccu: goto P_0c099ecc;
case 0x0c099eceu: goto P_0c099ece;
case 0x0c099ed0u: goto P_0c099ed0;
case 0x0c099ed2u: goto P_0c099ed2;
case 0x0c099ed4u: goto P_0c099ed4;
case 0x0c099ed6u: goto P_0c099ed6;
case 0x0c099f00u: goto P_0c099f00;
case 0x0c099f02u: goto P_0c099f02;
case 0x0c099f04u: goto P_0c099f04;
case 0x0c099f06u: goto P_0c099f06;
case 0x0c099f08u: goto P_0c099f08;
case 0x0c099f0au: goto P_0c099f0a;
case 0x0c099f0cu: goto P_0c099f0c;
case 0x0c099f0eu: goto P_0c099f0e;
case 0x0c099f10u: goto P_0c099f10;
case 0x0c099f12u: goto P_0c099f12;
case 0x0c099f14u: goto P_0c099f14;
case 0x0c099f16u: goto P_0c099f16;
case 0x0c099f18u: goto P_0c099f18;
case 0x0c099f1au: goto P_0c099f1a;
case 0x0c099f1cu: goto P_0c099f1c;
case 0x0c099f1eu: goto P_0c099f1e;
case 0x0c099f20u: goto P_0c099f20;
case 0x0c099f22u: goto P_0c099f22;
case 0x0c099f24u: goto P_0c099f24;
case 0x0c099f26u: goto P_0c099f26;
case 0x0c099f28u: goto P_0c099f28;
case 0x0c099f2au: goto P_0c099f2a;
case 0x0c099f2cu: goto P_0c099f2c;
case 0x0c099f2eu: goto P_0c099f2e;
case 0x0c099f30u: goto P_0c099f30;
case 0x0c099f32u: goto P_0c099f32;
case 0x0c099f34u: goto P_0c099f34;
case 0x0c099f36u: goto P_0c099f36;
case 0x0c099f38u: goto P_0c099f38;
case 0x0c099f3au: goto P_0c099f3a;
case 0x0c099f3cu: goto P_0c099f3c;
case 0x0c099f3eu: goto P_0c099f3e;
case 0x0c099f40u: goto P_0c099f40;
case 0x0c099f42u: goto P_0c099f42;
case 0x0c099f44u: goto P_0c099f44;
case 0x0c099f46u: goto P_0c099f46;
case 0x0c099f48u: goto P_0c099f48;
case 0x0c099f4au: goto P_0c099f4a;
case 0x0c099f4cu: goto P_0c099f4c;
case 0x0c099f4eu: goto P_0c099f4e;
case 0x0c099f50u: goto P_0c099f50;
case 0x0c099f52u: goto P_0c099f52;
case 0x0c099f54u: goto P_0c099f54;
case 0x0c099f56u: goto P_0c099f56;
case 0x0c099f58u: goto P_0c099f58;
case 0x0c099f5au: goto P_0c099f5a;
case 0x0c099f5cu: goto P_0c099f5c;
case 0x0c099f5eu: goto P_0c099f5e;
case 0x0c099f60u: goto P_0c099f60;
case 0x0c099f62u: goto P_0c099f62;
case 0x0c099f64u: goto P_0c099f64;
case 0x0c099f66u: goto P_0c099f66;
case 0x0c099f68u: goto P_0c099f68;
case 0x0c099f6au: goto P_0c099f6a;
case 0x0c099f6cu: goto P_0c099f6c;
case 0x0c099f6eu: goto P_0c099f6e;
case 0x0c099f70u: goto P_0c099f70;
case 0x0c099f72u: goto P_0c099f72;
case 0x0c099f74u: goto P_0c099f74;
case 0x0c099f76u: goto P_0c099f76;
case 0x0c099f78u: goto P_0c099f78;
case 0x0c099f7au: goto P_0c099f7a;
case 0x0c099f7cu: goto P_0c099f7c;
case 0x0c099f7eu: goto P_0c099f7e;
case 0x0c099f80u: goto P_0c099f80;
case 0x0c099f82u: goto P_0c099f82;
case 0x0c099f84u: goto P_0c099f84;
case 0x0c099f86u: goto P_0c099f86;
case 0x0c099f88u: goto P_0c099f88;
case 0x0c099f8au: goto P_0c099f8a;
case 0x0c099f8cu: goto P_0c099f8c;
case 0x0c099f8eu: goto P_0c099f8e;
case 0x0c099f90u: goto P_0c099f90;
case 0x0c099f92u: goto P_0c099f92;
case 0x0c099f94u: goto P_0c099f94;
case 0x0c099f96u: goto P_0c099f96;
case 0x0c099f98u: goto P_0c099f98;
case 0x0c099f9au: goto P_0c099f9a;
case 0x0c099f9cu: goto P_0c099f9c;
case 0x0c099f9eu: goto P_0c099f9e;
case 0x0c099fa0u: goto P_0c099fa0;
case 0x0c099fa2u: goto P_0c099fa2;
case 0x0c099fa4u: goto P_0c099fa4;
case 0x0c099fa6u: goto P_0c099fa6;
case 0x0c099fa8u: goto P_0c099fa8;
case 0x0c099faau: goto P_0c099faa;
case 0x0c099facu: goto P_0c099fac;
case 0x0c099faeu: goto P_0c099fae;
case 0x0c099fb0u: goto P_0c099fb0;
case 0x0c099fb2u: goto P_0c099fb2;
case 0x0c099fb4u: goto P_0c099fb4;
case 0x0c099fb6u: goto P_0c099fb6;
case 0x0c099fb8u: goto P_0c099fb8;
case 0x0c099fbau: goto P_0c099fba;
case 0x0c099fbcu: goto P_0c099fbc;
case 0x0c099fbeu: goto P_0c099fbe;
case 0x0c099fc0u: goto P_0c099fc0;
case 0x0c099fc2u: goto P_0c099fc2;
case 0x0c099fc4u: goto P_0c099fc4;
case 0x0c099fc6u: goto P_0c099fc6;
case 0x0c099fc8u: goto P_0c099fc8;
case 0x0c099fcau: goto P_0c099fca;
case 0x0c099fccu: goto P_0c099fcc;
case 0x0c099fceu: goto P_0c099fce;
case 0x0c099fd0u: goto P_0c099fd0;
case 0x0c099fd2u: goto P_0c099fd2;
case 0x0c099fd4u: goto P_0c099fd4;
case 0x0c099fd6u: goto P_0c099fd6;
case 0x0c099fd8u: goto P_0c099fd8;
case 0x0c099fdau: goto P_0c099fda;
case 0x0c099fdcu: goto P_0c099fdc;
case 0x0c099fdeu: goto P_0c099fde;
case 0x0c099fe0u: goto P_0c099fe0;
case 0x0c099fe2u: goto P_0c099fe2;
case 0x0c099fe4u: goto P_0c099fe4;
case 0x0c099fe6u: goto P_0c099fe6;
case 0x0c099fe8u: goto P_0c099fe8;
case 0x0c099feau: goto P_0c099fea;
case 0x0c099fecu: goto P_0c099fec;
case 0x0c099feeu: goto P_0c099fee;
case 0x0c099ff0u: goto P_0c099ff0;
case 0x0c099ff2u: goto P_0c099ff2;
case 0x0c099ff4u: goto P_0c099ff4;
case 0x0c099ff6u: goto P_0c099ff6;
case 0x0c099ff8u: goto P_0c099ff8;
case 0x0c09a01cu: goto P_0c09a01c;
case 0x0c09a01eu: goto P_0c09a01e;
case 0x0c09a020u: goto P_0c09a020;
case 0x0c09a022u: goto P_0c09a022;
case 0x0c09a024u: goto P_0c09a024;
case 0x0c09a026u: goto P_0c09a026;
case 0x0c09a028u: goto P_0c09a028;
case 0x0c09a02au: goto P_0c09a02a;
case 0x0c09a02cu: goto P_0c09a02c;
case 0x0c09a02eu: goto P_0c09a02e;
case 0x0c09a030u: goto P_0c09a030;
case 0x0c09a032u: goto P_0c09a032;
case 0x0c09a034u: goto P_0c09a034;
case 0x0c09a036u: goto P_0c09a036;
case 0x0c09a038u: goto P_0c09a038;
case 0x0c09a03au: goto P_0c09a03a;
case 0x0c09a03cu: goto P_0c09a03c;
case 0x0c09a03eu: goto P_0c09a03e;
case 0x0c09a040u: goto P_0c09a040;
case 0x0c09a042u: goto P_0c09a042;
case 0x0c09a044u: goto P_0c09a044;
case 0x0c09a046u: goto P_0c09a046;
case 0x0c09a048u: goto P_0c09a048;
case 0x0c09a04au: goto P_0c09a04a;
case 0x0c09a04cu: goto P_0c09a04c;
case 0x0c09a04eu: goto P_0c09a04e;
case 0x0c09a050u: goto P_0c09a050;
case 0x0c09a052u: goto P_0c09a052;
case 0x0c09a054u: goto P_0c09a054;
case 0x0c09a056u: goto P_0c09a056;
case 0x0c09a058u: goto P_0c09a058;
case 0x0c09a05au: goto P_0c09a05a;
case 0x0c09a05cu: goto P_0c09a05c;
case 0x0c09a05eu: goto P_0c09a05e;
case 0x0c09a060u: goto P_0c09a060;
case 0x0c09a062u: goto P_0c09a062;
case 0x0c09a064u: goto P_0c09a064;
case 0x0c09a066u: goto P_0c09a066;
case 0x0c09a068u: goto P_0c09a068;
case 0x0c09a06au: goto P_0c09a06a;
case 0x0c09a06cu: goto P_0c09a06c;
case 0x0c09a06eu: goto P_0c09a06e;
case 0x0c09a070u: goto P_0c09a070;
case 0x0c09a072u: goto P_0c09a072;
case 0x0c09a074u: goto P_0c09a074;
case 0x0c09a076u: goto P_0c09a076;
case 0x0c09a078u: goto P_0c09a078;
case 0x0c09a07au: goto P_0c09a07a;
case 0x0c09a07cu: goto P_0c09a07c;
case 0x0c09a07eu: goto P_0c09a07e;
case 0x0c09a080u: goto P_0c09a080;
case 0x0c09a082u: goto P_0c09a082;
case 0x0c09a084u: goto P_0c09a084;
default: return vf3_matrix_family(target,s,ram);
}
P_0c062bfa: /* original e700, guest PC 0x0c062bfa */
if(!s->budget--) { s->failed_pc=0x0c062bfau; return 0; }
r[7]=0x00000000u;
goto P_0c062bfc;
P_0c062bfc: /* original d526, guest PC 0x0c062bfc */
if(!s->budget--) { s->failed_pc=0x0c062bfcu; return 0; }
r[5]=read(ram,0x0c062c98u,4);
goto P_0c062bfe;
P_0c062bfe: /* original 6453, guest PC 0x0c062bfe */
if(!s->budget--) { s->failed_pc=0x0c062bfeu; return 0; }
r[4]=r[5];
goto P_0c062c00;
P_0c062c00: /* original 9047, guest PC 0x0c062c00 */
if(!s->budget--) { s->failed_pc=0x0c062c00u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c062c92u,2);
goto P_0c062c02;
P_0c062c02: /* original 6653, guest PC 0x0c062c02 */
if(!s->budget--) { s->failed_pc=0x0c062c02u; return 0; }
r[6]=r[5];
goto P_0c062c04;
P_0c062c04: /* original e501, guest PC 0x0c062c04 */
if(!s->budget--) { s->failed_pc=0x0c062c04u; return 0; }
r[5]=0x00000001u;
goto P_0c062c06;
P_0c062c06: /* original 6361, guest PC 0x0c062c06 */
if(!s->budget--) { s->failed_pc=0x0c062c06u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[6],2);
r[3]=tmp;
goto P_0c062c08;
P_0c062c08: /* original 633d, guest PC 0x0c062c08 */
if(!s->budget--) { s->failed_pc=0x0c062c08u; return 0; }
r[3]=r[3]&65535u;
goto P_0c062c0a;
P_0c062c0a: /* original 2358, guest PC 0x0c062c0a */
if(!s->budget--) { s->failed_pc=0x0c062c0au; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[5])==0)!=0);
goto P_0c062c0c;
P_0c062c0c: /* original 8b02, guest PC 0x0c062c0c */
if(!s->budget--) { s->failed_pc=0x0c062c0cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c062c14; }
goto P_0c062c0e;
P_0c062c0e: /* original 2451, guest PC 0x0c062c0e */
if(!s->budget--) { s->failed_pc=0x0c062c0eu; return 0; }
write(ram,r[4],r[5],2);
goto P_0c062c10;
P_0c062c10: /* original 000b, guest PC 0x0c062c10 */
if(!s->budget--) { s->failed_pc=0x0c062c10u; return 0; }
target=r[16];
r[0]=r[4];
s->pc=target; return ram->oob==0;
P_0c062c12: /* original 6043, guest PC 0x0c062c12 */
if(!s->budget--) { s->failed_pc=0x0c062c12u; return 0; }
r[0]=r[4];
goto P_0c062c14;
P_0c062c14: /* original 7701, guest PC 0x0c062c14 */
if(!s->budget--) { s->failed_pc=0x0c062c14u; return 0; }
r[7]+=0x00000001u;
goto P_0c062c16;
P_0c062c16: /* original 744c, guest PC 0x0c062c16 */
if(!s->budget--) { s->failed_pc=0x0c062c16u; return 0; }
r[4]+=0x0000004cu;
goto P_0c062c18;
P_0c062c18: /* original 3703, guest PC 0x0c062c18 */
if(!s->budget--) { s->failed_pc=0x0c062c18u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[7]>=(int32_t)r[0])!=0);
goto P_0c062c1a;
P_0c062c1a: /* original 8ff4, guest PC 0x0c062c1a */
if(!s->budget--) { s->failed_pc=0x0c062c1au; return 0; }
cond=r[17]&1u;
r[6]+=0x0000004cu;
if(!cond) { goto P_0c062c06; }
goto P_0c062c1e;
P_0c062c1c: /* original 764c, guest PC 0x0c062c1c */
if(!s->budget--) { s->failed_pc=0x0c062c1cu; return 0; }
r[6]+=0x0000004cu;
goto P_0c062c1e;
P_0c062c1e: /* original e000, guest PC 0x0c062c1e */
if(!s->budget--) { s->failed_pc=0x0c062c1eu; return 0; }
r[0]=0x00000000u;
goto P_0c062c20;
P_0c062c20: /* original 000b, guest PC 0x0c062c20 */
if(!s->budget--) { s->failed_pc=0x0c062c20u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c062c22: /* original 0009, guest PC 0x0c062c22 */
if(!s->budget--) { s->failed_pc=0x0c062c22u; return 0; }
goto P_0c062c24;
P_0c062c24: /* original 2fd6, guest PC 0x0c062c24 */
if(!s->budget--) { s->failed_pc=0x0c062c24u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c062c26;
P_0c062c26: /* original e700, guest PC 0x0c062c26 */
if(!s->budget--) { s->failed_pc=0x0c062c26u; return 0; }
r[7]=0x00000000u;
goto P_0c062c28;
P_0c062c28: /* original d51b, guest PC 0x0c062c28 */
if(!s->budget--) { s->failed_pc=0x0c062c28u; return 0; }
r[5]=read(ram,0x0c062c98u,4);
goto P_0c062c2a;
P_0c062c2a: /* original 7ffc, guest PC 0x0c062c2a */
if(!s->budget--) { s->failed_pc=0x0c062c2au; return 0; }
r[15]+=0xfffffffcu;
goto P_0c062c2c;
P_0c062c2c: /* original dd1b, guest PC 0x0c062c2c */
if(!s->budget--) { s->failed_pc=0x0c062c2cu; return 0; }
r[13]=read(ram,0x0c062c9cu,4);
goto P_0c062c2e;
P_0c062c2e: /* original 6653, guest PC 0x0c062c2e */
if(!s->budget--) { s->failed_pc=0x0c062c2eu; return 0; }
r[6]=r[5];
goto P_0c062c30;
P_0c062c30: /* original 912f, guest PC 0x0c062c30 */
if(!s->budget--) { s->failed_pc=0x0c062c30u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c062c92u,2);
goto P_0c062c32;
P_0c062c32: /* original 2f52, guest PC 0x0c062c32 */
if(!s->budget--) { s->failed_pc=0x0c062c32u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c062c34;
P_0c062c34: /* original 3640, guest PC 0x0c062c34 */
if(!s->budget--) { s->failed_pc=0x0c062c34u; return 0; }
r[17]=(r[17]&~1u)|((r[6]==r[4])!=0);
goto P_0c062c36;
P_0c062c36: /* original 8f03, guest PC 0x0c062c36 */
if(!s->budget--) { s->failed_pc=0x0c062c36u; return 0; }
cond=r[17]&1u;
r[7]+=0x00000001u;
if(!cond) { goto P_0c062c40; }
goto P_0c062c3a;
P_0c062c38: /* original 7701, guest PC 0x0c062c38 */
if(!s->budget--) { s->failed_pc=0x0c062c38u; return 0; }
r[7]+=0x00000001u;
goto P_0c062c3a;
P_0c062c3a: /* original 6251, guest PC 0x0c062c3a */
if(!s->budget--) { s->failed_pc=0x0c062c3au; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[5],2);
r[2]=tmp;
goto P_0c062c3c;
P_0c062c3c: /* original 22d9, guest PC 0x0c062c3c */
if(!s->budget--) { s->failed_pc=0x0c062c3cu; return 0; }
r[2]&=r[13];
goto P_0c062c3e;
P_0c062c3e: /* original 2521, guest PC 0x0c062c3e */
if(!s->budget--) { s->failed_pc=0x0c062c3eu; return 0; }
write(ram,r[5],r[2],2);
goto P_0c062c40;
P_0c062c40: /* original 754c, guest PC 0x0c062c40 */
if(!s->budget--) { s->failed_pc=0x0c062c40u; return 0; }
r[5]+=0x0000004cu;
goto P_0c062c42;
P_0c062c42: /* original 3713, guest PC 0x0c062c42 */
if(!s->budget--) { s->failed_pc=0x0c062c42u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[7]>=(int32_t)r[1])!=0);
goto P_0c062c44;
P_0c062c44: /* original 8ff6, guest PC 0x0c062c44 */
if(!s->budget--) { s->failed_pc=0x0c062c44u; return 0; }
cond=r[17]&1u;
r[6]+=0x0000004cu;
if(!cond) { goto P_0c062c34; }
goto P_0c062c48;
P_0c062c46: /* original 764c, guest PC 0x0c062c46 */
if(!s->budget--) { s->failed_pc=0x0c062c46u; return 0; }
r[6]+=0x0000004cu;
goto P_0c062c48;
P_0c062c48: /* original 7f04, guest PC 0x0c062c48 */
if(!s->budget--) { s->failed_pc=0x0c062c48u; return 0; }
r[15]+=0x00000004u;
goto P_0c062c4a;
P_0c062c4a: /* original 000b, guest PC 0x0c062c4a */
if(!s->budget--) { s->failed_pc=0x0c062c4au; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
s->pc=target; return ram->oob==0;
P_0c062c4c: /* original 6df6, guest PC 0x0c062c4c */
if(!s->budget--) { s->failed_pc=0x0c062c4cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c062c4e;
P_0c062c4e: /* original 6342, guest PC 0x0c062c4e */
if(!s->budget--) { s->failed_pc=0x0c062c4eu; return 0; }
tmp=read(ram,r[4],4);
r[3]=tmp;
goto P_0c062c50;
P_0c062c50: /* original 2338, guest PC 0x0c062c50 */
if(!s->budget--) { s->failed_pc=0x0c062c50u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c062c52;
P_0c062c52: /* original 8b02, guest PC 0x0c062c52 */
if(!s->budget--) { s->failed_pc=0x0c062c52u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c062c5a; }
goto P_0c062c54;
P_0c062c54: /* original e300, guest PC 0x0c062c54 */
if(!s->budget--) { s->failed_pc=0x0c062c54u; return 0; }
r[3]=0x00000000u;
goto P_0c062c56;
P_0c062c56: /* original a002, guest PC 0x0c062c56 */
if(!s->budget--) { s->failed_pc=0x0c062c56u; return 0; }
write(ram,r[5]+4,r[3],4);
goto P_0c062c5e;
P_0c062c58: /* original 1531, guest PC 0x0c062c58 */
if(!s->budget--) { s->failed_pc=0x0c062c58u; return 0; }
write(ram,r[5]+4,r[3],4);
goto P_0c062c5a;
P_0c062c5a: /* original 6242, guest PC 0x0c062c5a */
if(!s->budget--) { s->failed_pc=0x0c062c5au; return 0; }
tmp=read(ram,r[4],4);
r[2]=tmp;
goto P_0c062c5c;
P_0c062c5c: /* original 1521, guest PC 0x0c062c5c */
if(!s->budget--) { s->failed_pc=0x0c062c5cu; return 0; }
write(ram,r[5]+4,r[2],4);
goto P_0c062c5e;
P_0c062c5e: /* original 000b, guest PC 0x0c062c5e */
if(!s->budget--) { s->failed_pc=0x0c062c5eu; return 0; }
target=r[16];
write(ram,r[4],r[5],4);
s->pc=target; return ram->oob==0;
P_0c062c60: /* original 2452, guest PC 0x0c062c60 */
if(!s->budget--) { s->failed_pc=0x0c062c60u; return 0; }
write(ram,r[4],r[5],4);
if(!vf3_matrix_family(0x0c062c62u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c062c62u; return 0; } return 1;
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
P_0c0644bc: /* original d009, guest PC 0x0c0644bc */
if(!s->budget--) { s->failed_pc=0x0c0644bcu; return 0; }
r[0]=read(ram,0x0c0644e4u,4);
goto P_0c0644be;
P_0c0644be: /* original 7ff8, guest PC 0x0c0644be */
if(!s->budget--) { s->failed_pc=0x0c0644beu; return 0; }
r[15]+=0xfffffff8u;
goto P_0c0644c0;
P_0c0644c0: /* original 2f42, guest PC 0x0c0644c0 */
if(!s->budget--) { s->failed_pc=0x0c0644c0u; return 0; }
write(ram,r[15],r[4],4);
goto P_0c0644c2;
P_0c0644c2: /* original 6343, guest PC 0x0c0644c2 */
if(!s->budget--) { s->failed_pc=0x0c0644c2u; return 0; }
r[3]=r[4];
goto P_0c0644c4;
P_0c0644c4: /* original 4308, guest PC 0x0c0644c4 */
if(!s->budget--) { s->failed_pc=0x0c0644c4u; return 0; }
r[3]<<=2;
goto P_0c0644c6;
P_0c0644c6: /* original 4300, guest PC 0x0c0644c6 */
if(!s->budget--) { s->failed_pc=0x0c0644c6u; return 0; }
r[17]=(r[17]&~1u)|((r[3]>>31)!=0);
r[3]<<=1;
goto P_0c0644c8;
P_0c0644c8: /* original 1f31, guest PC 0x0c0644c8 */
if(!s->budget--) { s->failed_pc=0x0c0644c8u; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c0644ca;
P_0c0644ca: /* original 023e, guest PC 0x0c0644ca */
if(!s->budget--) { s->failed_pc=0x0c0644cau; return 0; }
r[2]=read(ram,r[3]+r[0],4);
goto P_0c0644cc;
P_0c0644cc: /* original 6403, guest PC 0x0c0644cc */
if(!s->budget--) { s->failed_pc=0x0c0644ccu; return 0; }
r[4]=r[0];
goto P_0c0644ce;
P_0c0644ce: /* original 343c, guest PC 0x0c0644ce */
if(!s->budget--) { s->failed_pc=0x0c0644ceu; return 0; }
r[4]+=r[3];
goto P_0c0644d0;
P_0c0644d0: /* original 5441, guest PC 0x0c0644d0 */
if(!s->budget--) { s->failed_pc=0x0c0644d0u; return 0; }
r[4]=read(ram,r[4]+4,4);
goto P_0c0644d2;
P_0c0644d2: /* original 422b, guest PC 0x0c0644d2 */
if(!s->budget--) { s->failed_pc=0x0c0644d2u; return 0; }
target=r[2];
r[15]+=0x00000008u;
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
P_0c0644d4: /* original 7f08, guest PC 0x0c0644d4 */
if(!s->budget--) { s->failed_pc=0x0c0644d4u; return 0; }
r[15]+=0x00000008u;
if(!vf3_matrix_family(0x0c0644d6u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0644d6u; return 0; } return 1;
P_0c068c58: /* original 2fe6, guest PC 0x0c068c58 */
if(!s->budget--) { s->failed_pc=0x0c068c58u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c068c5a;
P_0c068c5a: /* original 2fd6, guest PC 0x0c068c5a */
if(!s->budget--) { s->failed_pc=0x0c068c5au; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c068c5c;
P_0c068c5c: /* original 2fc6, guest PC 0x0c068c5c */
if(!s->budget--) { s->failed_pc=0x0c068c5cu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c068c5e;
P_0c068c5e: /* original ec0f, guest PC 0x0c068c5e */
if(!s->budget--) { s->failed_pc=0x0c068c5eu; return 0; }
r[12]=0x0000000fu;
goto P_0c068c60;
P_0c068c60: /* original 2fb6, guest PC 0x0c068c60 */
if(!s->budget--) { s->failed_pc=0x0c068c60u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c068c62;
P_0c068c62: /* original 2fa6, guest PC 0x0c068c62 */
if(!s->budget--) { s->failed_pc=0x0c068c62u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c068c64;
P_0c068c64: /* original 2f96, guest PC 0x0c068c64 */
if(!s->budget--) { s->failed_pc=0x0c068c64u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c068c66;
P_0c068c66: /* original 2f86, guest PC 0x0c068c66 */
if(!s->budget--) { s->failed_pc=0x0c068c66u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c068c68;
P_0c068c68: /* original d92b, guest PC 0x0c068c68 */
if(!s->budget--) { s->failed_pc=0x0c068c68u; return 0; }
r[9]=read(ram,0x0c068d18u,4);
goto P_0c068c6a;
P_0c068c6a: /* original d833, guest PC 0x0c068c6a */
if(!s->budget--) { s->failed_pc=0x0c068c6au; return 0; }
r[8]=read(ram,0x0c068d38u,4);
goto P_0c068c6c;
P_0c068c6c: /* original 6393, guest PC 0x0c068c6c */
if(!s->budget--) { s->failed_pc=0x0c068c6cu; return 0; }
r[3]=r[9];
goto P_0c068c6e;
P_0c068c6e: /* original 731c, guest PC 0x0c068c6e */
if(!s->budget--) { s->failed_pc=0x0c068c6eu; return 0; }
r[3]+=0x0000001cu;
goto P_0c068c70;
P_0c068c70: /* original 6030, guest PC 0x0c068c70 */
if(!s->budget--) { s->failed_pc=0x0c068c70u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[3],1);
r[0]=tmp;
goto P_0c068c72;
P_0c068c72: /* original 4f22, guest PC 0x0c068c72 */
if(!s->budget--) { s->failed_pc=0x0c068c72u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c068c74;
P_0c068c74: /* original 600c, guest PC 0x0c068c74 */
if(!s->budget--) { s->failed_pc=0x0c068c74u; return 0; }
r[0]=r[0]&255u;
goto P_0c068c76;
P_0c068c76: /* original da31, guest PC 0x0c068c76 */
if(!s->budget--) { s->failed_pc=0x0c068c76u; return 0; }
r[10]=read(ram,0x0c068d3cu,4);
goto P_0c068c78;
P_0c068c78: /* original 2c09, guest PC 0x0c068c78 */
if(!s->budget--) { s->failed_pc=0x0c068c78u; return 0; }
r[12]&=r[0];
goto P_0c068c7a;
P_0c068c7a: /* original de2a, guest PC 0x0c068c7a */
if(!s->budget--) { s->failed_pc=0x0c068c7au; return 0; }
r[14]=read(ram,0x0c068d24u,4);
goto P_0c068c7c;
P_0c068c7c: /* original 6bc3, guest PC 0x0c068c7c */
if(!s->budget--) { s->failed_pc=0x0c068c7cu; return 0; }
r[11]=r[12];
goto P_0c068c7e;
P_0c068c7e: /* original 4b08, guest PC 0x0c068c7e */
if(!s->budget--) { s->failed_pc=0x0c068c7eu; return 0; }
r[11]<<=2;
goto P_0c068c80;
P_0c068c80: /* original 60b3, guest PC 0x0c068c80 */
if(!s->budget--) { s->failed_pc=0x0c068c80u; return 0; }
r[0]=r[11];
goto P_0c068c82;
P_0c068c82: /* original 008e, guest PC 0x0c068c82 */
if(!s->budget--) { s->failed_pc=0x0c068c82u; return 0; }
r[0]=read(ram,r[8]+r[0],4);
goto P_0c068c84;
P_0c068c84: /* original 88ff, guest PC 0x0c068c84 */
if(!s->budget--) { s->failed_pc=0x0c068c84u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xffffffffu)!=0);
goto P_0c068c86;
P_0c068c86: /* original 8d36, guest PC 0x0c068c86 */
if(!s->budget--) { s->failed_pc=0x0c068c86u; return 0; }
cond=r[17]&1u;
r[4]=0x00000000u;
if(cond) { goto P_0c068cf6; }
goto P_0c068c8a;
P_0c068c88: /* original e400, guest PC 0x0c068c88 */
if(!s->budget--) { s->failed_pc=0x0c068c88u; return 0; }
r[4]=0x00000000u;
goto P_0c068c8a;
P_0c068c8a: /* original 6192, guest PC 0x0c068c8a */
if(!s->budget--) { s->failed_pc=0x0c068c8au; return 0; }
tmp=read(ram,r[9],4);
r[1]=tmp;
goto P_0c068c8c;
P_0c068c8c: /* original d22c, guest PC 0x0c068c8c */
if(!s->budget--) { s->failed_pc=0x0c068c8cu; return 0; }
r[2]=read(ram,0x0c068d40u,4);
goto P_0c068c8e;
P_0c068c8e: /* original dd23, guest PC 0x0c068c8e */
if(!s->budget--) { s->failed_pc=0x0c068c8eu; return 0; }
r[13]=read(ram,0x0c068d1cu,4);
goto P_0c068c90;
P_0c068c90: /* original 2128, guest PC 0x0c068c90 */
if(!s->budget--) { s->failed_pc=0x0c068c90u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[2])==0)!=0);
goto P_0c068c92;
P_0c068c92: /* original 8912, guest PC 0x0c068c92 */
if(!s->budget--) { s->failed_pc=0x0c068c92u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c068cba; }
goto P_0c068c94;
P_0c068c94: /* original 903d, guest PC 0x0c068c94 */
if(!s->budget--) { s->failed_pc=0x0c068c94u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c068d12u,2);
goto P_0c068c96;
P_0c068c96: /* original 0a46, guest PC 0x0c068c96 */
if(!s->budget--) { s->failed_pc=0x0c068c96u; return 0; }
write(ram,r[10]+r[0],r[4],4);
goto P_0c068c98;
P_0c068c98: /* original 60b3, guest PC 0x0c068c98 */
if(!s->budget--) { s->failed_pc=0x0c068c98u; return 0; }
r[0]=r[11];
goto P_0c068c9a;
P_0c068c9a: /* original 2e42, guest PC 0x0c068c9a */
if(!s->budget--) { s->failed_pc=0x0c068c9au; return 0; }
write(ram,r[14],r[4],4);
goto P_0c068c9c;
P_0c068c9c: /* original 933a, guest PC 0x0c068c9c */
if(!s->budget--) { s->failed_pc=0x0c068c9cu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c068d14u,2);
goto P_0c068c9e;
P_0c068c9e: /* original 2f36, guest PC 0x0c068c9e */
if(!s->budget--) { s->failed_pc=0x0c068c9eu; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c068ca0;
P_0c068ca0: /* original d228, guest PC 0x0c068ca0 */
if(!s->budget--) { s->failed_pc=0x0c068ca0u; return 0; }
r[2]=read(ram,0x0c068d44u,4);
goto P_0c068ca2;
P_0c068ca2: /* original 2f26, guest PC 0x0c068ca2 */
if(!s->budget--) { s->failed_pc=0x0c068ca2u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c068ca4;
P_0c068ca4: /* original 2fc6, guest PC 0x0c068ca4 */
if(!s->budget--) { s->failed_pc=0x0c068ca4u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c068ca6;
P_0c068ca6: /* original 9636, guest PC 0x0c068ca6 */
if(!s->budget--) { s->failed_pc=0x0c068ca6u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c068d16u,2);
goto P_0c068ca8;
P_0c068ca8: /* original d727, guest PC 0x0c068ca8 */
if(!s->budget--) { s->failed_pc=0x0c068ca8u; return 0; }
r[7]=read(ram,0x0c068d48u,4);
goto P_0c068caa;
P_0c068caa: /* original 369c, guest PC 0x0c068caa */
if(!s->budget--) { s->failed_pc=0x0c068caau; return 0; }
r[6]+=r[9];
goto P_0c068cac;
P_0c068cac: /* original 65d2, guest PC 0x0c068cac */
if(!s->budget--) { s->failed_pc=0x0c068cacu; return 0; }
tmp=read(ram,r[13],4);
r[5]=tmp;
goto P_0c068cae;
P_0c068cae: /* original d327, guest PC 0x0c068cae */
if(!s->budget--) { s->failed_pc=0x0c068caeu; return 0; }
r[3]=read(ram,0x0c068d4cu,4);
goto P_0c068cb0;
P_0c068cb0: /* original 7608, guest PC 0x0c068cb0 */
if(!s->budget--) { s->failed_pc=0x0c068cb0u; return 0; }
r[6]+=0x00000008u;
goto P_0c068cb2;
P_0c068cb2: /* original 430b, guest PC 0x0c068cb2 */
if(!s->budget--) { s->failed_pc=0x0c068cb2u; return 0; }
target=r[3];
r[16]=code_base|0x0c068cb6u;
r[4]=read(ram,r[8]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c068cb6u) { target=s->pc; goto dispatch; }
goto P_0c068cb6;
P_0c068cb4: /* original 048e, guest PC 0x0c068cb4 */
if(!s->budget--) { s->failed_pc=0x0c068cb4u; return 0; }
r[4]=read(ram,r[8]+r[0],4);
goto P_0c068cb6;
P_0c068cb6: /* original a021, guest PC 0x0c068cb6 */
if(!s->budget--) { s->failed_pc=0x0c068cb6u; return 0; }
r[15]+=0x0000000cu;
goto P_0c068cfc;
P_0c068cb8: /* original 7f0c, guest PC 0x0c068cb8 */
if(!s->budget--) { s->failed_pc=0x0c068cb8u; return 0; }
r[15]+=0x0000000cu;
goto P_0c068cba;
P_0c068cba: /* original d325, guest PC 0x0c068cba */
if(!s->budget--) { s->failed_pc=0x0c068cbau; return 0; }
r[3]=read(ram,0x0c068d50u,4);
goto P_0c068cbc;
P_0c068cbc: /* original 60b3, guest PC 0x0c068cbc */
if(!s->budget--) { s->failed_pc=0x0c068cbcu; return 0; }
r[0]=r[11];
goto P_0c068cbe;
P_0c068cbe: /* original 65d2, guest PC 0x0c068cbe */
if(!s->budget--) { s->failed_pc=0x0c068cbeu; return 0; }
tmp=read(ram,r[13],4);
r[5]=tmp;
goto P_0c068cc0;
P_0c068cc0: /* original 430b, guest PC 0x0c068cc0 */
if(!s->budget--) { s->failed_pc=0x0c068cc0u; return 0; }
target=r[3];
r[16]=code_base|0x0c068cc4u;
r[4]=read(ram,r[8]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c068cc4u) { target=s->pc; goto dispatch; }
goto P_0c068cc4;
P_0c068cc2: /* original 048e, guest PC 0x0c068cc2 */
if(!s->budget--) { s->failed_pc=0x0c068cc2u; return 0; }
r[4]=read(ram,r[8]+r[0],4);
goto P_0c068cc4;
P_0c068cc4: /* original 64d2, guest PC 0x0c068cc4 */
if(!s->budget--) { s->failed_pc=0x0c068cc4u; return 0; }
tmp=read(ram,r[13],4);
r[4]=tmp;
goto P_0c068cc6;
P_0c068cc6: /* original 9024, guest PC 0x0c068cc6 */
if(!s->budget--) { s->failed_pc=0x0c068cc6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c068d12u,2);
goto P_0c068cc8;
P_0c068cc8: /* original 6542, guest PC 0x0c068cc8 */
if(!s->budget--) { s->failed_pc=0x0c068cc8u; return 0; }
tmp=read(ram,r[4],4);
r[5]=tmp;
goto P_0c068cca;
P_0c068cca: /* original 6343, guest PC 0x0c068cca */
if(!s->budget--) { s->failed_pc=0x0c068ccau; return 0; }
r[3]=r[4];
goto P_0c068ccc;
P_0c068ccc: /* original 353c, guest PC 0x0c068ccc */
if(!s->budget--) { s->failed_pc=0x0c068cccu; return 0; }
r[5]+=r[3];
goto P_0c068cce;
P_0c068cce: /* original 0a56, guest PC 0x0c068cce */
if(!s->budget--) { s->failed_pc=0x0c068cceu; return 0; }
write(ram,r[10]+r[0],r[5],4);
goto P_0c068cd0;
P_0c068cd0: /* original 60c3, guest PC 0x0c068cd0 */
if(!s->budget--) { s->failed_pc=0x0c068cd0u; return 0; }
r[0]=r[12];
goto P_0c068cd2;
P_0c068cd2: /* original 5441, guest PC 0x0c068cd2 */
if(!s->budget--) { s->failed_pc=0x0c068cd2u; return 0; }
r[4]=read(ram,r[4]+4,4);
goto P_0c068cd4;
P_0c068cd4: /* original 880c, guest PC 0x0c068cd4 */
if(!s->budget--) { s->failed_pc=0x0c068cd4u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000cu)!=0);
goto P_0c068cd6;
P_0c068cd6: /* original 63d2, guest PC 0x0c068cd6 */
if(!s->budget--) { s->failed_pc=0x0c068cd6u; return 0; }
tmp=read(ram,r[13],4);
r[3]=tmp;
goto P_0c068cd8;
P_0c068cd8: /* original 343c, guest PC 0x0c068cd8 */
if(!s->budget--) { s->failed_pc=0x0c068cd8u; return 0; }
r[4]+=r[3];
goto P_0c068cda;
P_0c068cda: /* original 8f0f, guest PC 0x0c068cda */
if(!s->budget--) { s->failed_pc=0x0c068cdau; return 0; }
cond=r[17]&1u;
write(ram,r[14],r[4],4);
if(!cond) { goto P_0c068cfc; }
goto P_0c068cde;
P_0c068cdc: /* original 2e42, guest PC 0x0c068cdc */
if(!s->budget--) { s->failed_pc=0x0c068cdcu; return 0; }
write(ram,r[14],r[4],4);
goto P_0c068cde;
P_0c068cde: /* original c713, guest PC 0x0c068cde */
if(!s->budget--) { s->failed_pc=0x0c068cdeu; return 0; }
r[0]=code_base|0x00068d2cu;
goto P_0c068ce0;
P_0c068ce0: /* original 63e2, guest PC 0x0c068ce0 */
if(!s->budget--) { s->failed_pc=0x0c068ce0u; return 0; }
tmp=read(ram,r[14],4);
r[3]=tmp;
goto P_0c068ce2;
P_0c068ce2: /* original f308, guest PC 0x0c068ce2 */
if(!s->budget--) { s->failed_pc=0x0c068ce2u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c068ce4;
P_0c068ce4: /* original d012, guest PC 0x0c068ce4 */
if(!s->budget--) { s->failed_pc=0x0c068ce4u; return 0; }
r[0]=read(ram,0x0c068d30u,4);
goto P_0c068ce6;
P_0c068ce6: /* original f337, guest PC 0x0c068ce6 */
if(!s->budget--) { s->failed_pc=0x0c068ce6u; return 0; }
vf3_matrix_store(s,ram,3,r[3]+r[0]);
goto P_0c068ce8;
P_0c068ce8: /* original c712, guest PC 0x0c068ce8 */
if(!s->budget--) { s->failed_pc=0x0c068ce8u; return 0; }
r[0]=code_base|0x00068d34u;
goto P_0c068cea;
P_0c068cea: /* original f308, guest PC 0x0c068cea */
if(!s->budget--) { s->failed_pc=0x0c068ceau; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c068cec;
P_0c068cec: /* original 900f, guest PC 0x0c068cec */
if(!s->budget--) { s->failed_pc=0x0c068cecu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c068d0eu,2);
goto P_0c068cee;
P_0c068cee: /* original 63e2, guest PC 0x0c068cee */
if(!s->budget--) { s->failed_pc=0x0c068ceeu; return 0; }
tmp=read(ram,r[14],4);
r[3]=tmp;
goto P_0c068cf0;
P_0c068cf0: /* original f337, guest PC 0x0c068cf0 */
if(!s->budget--) { s->failed_pc=0x0c068cf0u; return 0; }
vf3_matrix_store(s,ram,3,r[3]+r[0]);
goto P_0c068cf2;
P_0c068cf2: /* original a003, guest PC 0x0c068cf2 */
if(!s->budget--) { s->failed_pc=0x0c068cf2u; return 0; }
goto P_0c068cfc;
P_0c068cf4: /* original 0009, guest PC 0x0c068cf4 */
if(!s->budget--) { s->failed_pc=0x0c068cf4u; return 0; }
goto P_0c068cf6;
P_0c068cf6: /* original 900c, guest PC 0x0c068cf6 */
if(!s->budget--) { s->failed_pc=0x0c068cf6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c068d12u,2);
goto P_0c068cf8;
P_0c068cf8: /* original 0a46, guest PC 0x0c068cf8 */
if(!s->budget--) { s->failed_pc=0x0c068cf8u; return 0; }
write(ram,r[10]+r[0],r[4],4);
goto P_0c068cfa;
P_0c068cfa: /* original 2e42, guest PC 0x0c068cfa */
if(!s->budget--) { s->failed_pc=0x0c068cfau; return 0; }
write(ram,r[14],r[4],4);
goto P_0c068cfc;
P_0c068cfc: /* original 4f26, guest PC 0x0c068cfc */
if(!s->budget--) { s->failed_pc=0x0c068cfcu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c068cfe;
P_0c068cfe: /* original 68f6, guest PC 0x0c068cfe */
if(!s->budget--) { s->failed_pc=0x0c068cfeu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c068d00;
P_0c068d00: /* original 69f6, guest PC 0x0c068d00 */
if(!s->budget--) { s->failed_pc=0x0c068d00u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c068d02;
P_0c068d02: /* original 6af6, guest PC 0x0c068d02 */
if(!s->budget--) { s->failed_pc=0x0c068d02u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c068d04;
P_0c068d04: /* original 6bf6, guest PC 0x0c068d04 */
if(!s->budget--) { s->failed_pc=0x0c068d04u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c068d06;
P_0c068d06: /* original 6cf6, guest PC 0x0c068d06 */
if(!s->budget--) { s->failed_pc=0x0c068d06u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c068d08;
P_0c068d08: /* original 6df6, guest PC 0x0c068d08 */
if(!s->budget--) { s->failed_pc=0x0c068d08u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c068d0a;
P_0c068d0a: /* original 000b, guest PC 0x0c068d0a */
if(!s->budget--) { s->failed_pc=0x0c068d0au; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c068d0c: /* original 6ef6, guest PC 0x0c068d0c */
if(!s->budget--) { s->failed_pc=0x0c068d0cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c068d0eu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c068d0eu; return 0; } return 1;
P_0c07a7e8: /* original 6341, guest PC 0x0c07a7e8 */
if(!s->budget--) { s->failed_pc=0x0c07a7e8u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[4],2);
r[3]=tmp;
goto P_0c07a7ea;
P_0c07a7ea: /* original d676, guest PC 0x0c07a7ea */
if(!s->budget--) { s->failed_pc=0x0c07a7eau; return 0; }
r[6]=read(ram,0x0c07a9c4u,4);
goto P_0c07a7ec;
P_0c07a7ec: /* original 2631, guest PC 0x0c07a7ec */
if(!s->budget--) { s->failed_pc=0x0c07a7ecu; return 0; }
write(ram,r[6],r[3],2);
goto P_0c07a7ee;
P_0c07a7ee: /* original 8541, guest PC 0x0c07a7ee */
if(!s->budget--) { s->failed_pc=0x0c07a7eeu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+2,2);
goto P_0c07a7f0;
P_0c07a7f0: /* original 8161, guest PC 0x0c07a7f0 */
if(!s->budget--) { s->failed_pc=0x0c07a7f0u; return 0; }
write(ram,r[6]+2,r[0],2);
goto P_0c07a7f2;
P_0c07a7f2: /* original 5341, guest PC 0x0c07a7f2 */
if(!s->budget--) { s->failed_pc=0x0c07a7f2u; return 0; }
r[3]=read(ram,r[4]+4,4);
goto P_0c07a7f4;
P_0c07a7f4: /* original 1631, guest PC 0x0c07a7f4 */
if(!s->budget--) { s->failed_pc=0x0c07a7f4u; return 0; }
write(ram,r[6]+4,r[3],4);
goto P_0c07a7f6;
P_0c07a7f6: /* original 5242, guest PC 0x0c07a7f6 */
if(!s->budget--) { s->failed_pc=0x0c07a7f6u; return 0; }
r[2]=read(ram,r[4]+8,4);
goto P_0c07a7f8;
P_0c07a7f8: /* original 352c, guest PC 0x0c07a7f8 */
if(!s->budget--) { s->failed_pc=0x0c07a7f8u; return 0; }
r[5]+=r[2];
goto P_0c07a7fa;
P_0c07a7fa: /* original 1652, guest PC 0x0c07a7fa */
if(!s->budget--) { s->failed_pc=0x0c07a7fau; return 0; }
write(ram,r[6]+8,r[5],4);
goto P_0c07a7fc;
P_0c07a7fc: /* original 5343, guest PC 0x0c07a7fc */
if(!s->budget--) { s->failed_pc=0x0c07a7fcu; return 0; }
r[3]=read(ram,r[4]+12,4);
goto P_0c07a7fe;
P_0c07a7fe: /* original 1633, guest PC 0x0c07a7fe */
if(!s->budget--) { s->failed_pc=0x0c07a7feu; return 0; }
write(ram,r[6]+12,r[3],4);
goto P_0c07a800;
P_0c07a800: /* original d271, guest PC 0x0c07a800 */
if(!s->budget--) { s->failed_pc=0x0c07a800u; return 0; }
r[2]=read(ram,0x0c07a9c8u,4);
goto P_0c07a802;
P_0c07a802: /* original 422b, guest PC 0x0c07a802 */
if(!s->budget--) { s->failed_pc=0x0c07a802u; return 0; }
target=r[2];
r[4]=r[6];
code_base=target&0xff000000u;
switch(target&0x1fffffffu) {
case 0x0c03f5a0u: return vf3_matrix_family(0x0c03f5a0u,s,ram);
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
P_0c07a804: /* original 6463, guest PC 0x0c07a804 */
if(!s->budget--) { s->failed_pc=0x0c07a804u; return 0; }
r[4]=r[6];
if(!vf3_matrix_family(0x0c07a806u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c07a806u; return 0; } return 1;
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
P_0c099d62: /* original 2fe6, guest PC 0x0c099d62 */
if(!s->budget--) { s->failed_pc=0x0c099d62u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c099d64;
P_0c099d64: /* original e060, guest PC 0x0c099d64 */
if(!s->budget--) { s->failed_pc=0x0c099d64u; return 0; }
r[0]=0x00000060u;
goto P_0c099d66;
P_0c099d66: /* original 2fd6, guest PC 0x0c099d66 */
if(!s->budget--) { s->failed_pc=0x0c099d66u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c099d68;
P_0c099d68: /* original e601, guest PC 0x0c099d68 */
if(!s->budget--) { s->failed_pc=0x0c099d68u; return 0; }
r[6]=0x00000001u;
goto P_0c099d6a;
P_0c099d6a: /* original 2fc6, guest PC 0x0c099d6a */
if(!s->budget--) { s->failed_pc=0x0c099d6au; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c099d6c;
P_0c099d6c: /* original 2fb6, guest PC 0x0c099d6c */
if(!s->budget--) { s->failed_pc=0x0c099d6cu; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c099d6e;
P_0c099d6e: /* original 2fa6, guest PC 0x0c099d6e */
if(!s->budget--) { s->failed_pc=0x0c099d6eu; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c099d70;
P_0c099d70: /* original 2f96, guest PC 0x0c099d70 */
if(!s->budget--) { s->failed_pc=0x0c099d70u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c099d72;
P_0c099d72: /* original 2f86, guest PC 0x0c099d72 */
if(!s->budget--) { s->failed_pc=0x0c099d72u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c099d74;
P_0c099d74: /* original 4f22, guest PC 0x0c099d74 */
if(!s->budget--) { s->failed_pc=0x0c099d74u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c099d76;
P_0c099d76: /* original d318, guest PC 0x0c099d76 */
if(!s->budget--) { s->failed_pc=0x0c099d76u; return 0; }
r[3]=read(ram,0x0c099dd8u,4);
goto P_0c099d78;
P_0c099d78: /* original de10, guest PC 0x0c099d78 */
if(!s->budget--) { s->failed_pc=0x0c099d78u; return 0; }
r[14]=read(ram,0x0c099dbcu,4);
goto P_0c099d7a;
P_0c099d7a: /* original 7ff8, guest PC 0x0c099d7a */
if(!s->budget--) { s->failed_pc=0x0c099d7au; return 0; }
r[15]+=0xfffffff8u;
goto P_0c099d7c;
P_0c099d7c: /* original dd10, guest PC 0x0c099d7c */
if(!s->budget--) { s->failed_pc=0x0c099d7cu; return 0; }
r[13]=read(ram,0x0c099dc0u,4);
goto P_0c099d7e;
P_0c099d7e: /* original 1f31, guest PC 0x0c099d7e */
if(!s->budget--) { s->failed_pc=0x0c099d7eu; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c099d80;
P_0c099d80: /* original d216, guest PC 0x0c099d80 */
if(!s->budget--) { s->failed_pc=0x0c099d80u; return 0; }
r[2]=read(ram,0x0c099ddcu,4);
goto P_0c099d82;
P_0c099d82: /* original 2f22, guest PC 0x0c099d82 */
if(!s->budget--) { s->failed_pc=0x0c099d82u; return 0; }
write(ram,r[15],r[2],4);
goto P_0c099d84;
P_0c099d84: /* original db11, guest PC 0x0c099d84 */
if(!s->budget--) { s->failed_pc=0x0c099d84u; return 0; }
r[11]=read(ram,0x0c099dccu,4);
goto P_0c099d86;
P_0c099d86: /* original 03be, guest PC 0x0c099d86 */
if(!s->budget--) { s->failed_pc=0x0c099d86u; return 0; }
r[3]=read(ram,r[11]+r[0],4);
goto P_0c099d88;
P_0c099d88: /* original 54b4, guest PC 0x0c099d88 */
if(!s->budget--) { s->failed_pc=0x0c099d88u; return 0; }
r[4]=read(ram,r[11]+16,4);
goto P_0c099d8a;
P_0c099d8a: /* original 6232, guest PC 0x0c099d8a */
if(!s->budget--) { s->failed_pc=0x0c099d8au; return 0; }
tmp=read(ram,r[3],4);
r[2]=tmp;
goto P_0c099d8c;
P_0c099d8c: /* original 2268, guest PC 0x0c099d8c */
if(!s->budget--) { s->failed_pc=0x0c099d8cu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[6])==0)!=0);
goto P_0c099d8e;
P_0c099d8e: /* original 8d27, guest PC 0x0c099d8e */
if(!s->budget--) { s->failed_pc=0x0c099d8eu; return 0; }
cond=r[17]&1u;
r[5]=read(ram,r[11]+20,4);
if(cond) { goto P_0c099de0; }
goto P_0c099d92;
P_0c099d90: /* original 55b5, guest PC 0x0c099d90 */
if(!s->budget--) { s->failed_pc=0x0c099d90u; return 0; }
r[5]=read(ram,r[11]+20,4);
goto P_0c099d92;
P_0c099d92: /* original e054, guest PC 0x0c099d92 */
if(!s->budget--) { s->failed_pc=0x0c099d92u; return 0; }
r[0]=0x00000054u;
goto P_0c099d94;
P_0c099d94: /* original 054e, guest PC 0x0c099d94 */
if(!s->budget--) { s->failed_pc=0x0c099d94u; return 0; }
r[5]=read(ram,r[4]+r[0],4);
goto P_0c099d96;
P_0c099d96: /* original e022, guest PC 0x0c099d96 */
if(!s->budget--) { s->failed_pc=0x0c099d96u; return 0; }
r[0]=0x00000022u;
goto P_0c099d98;
P_0c099d98: /* original 035d, guest PC 0x0c099d98 */
if(!s->budget--) { s->failed_pc=0x0c099d98u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[5]+r[0],2);
goto P_0c099d9a;
P_0c099d9a: /* original 9004, guest PC 0x0c099d9a */
if(!s->budget--) { s->failed_pc=0x0c099d9au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c099da6u,2);
goto P_0c099d9c;
P_0c099d9c: /* original a02b, guest PC 0x0c099d9c */
if(!s->budget--) { s->failed_pc=0x0c099d9cu; return 0; }
write(ram,r[4]+r[0],r[3],2);
goto P_0c099df6;
P_0c099d9e: /* original 0435, guest PC 0x0c099d9e */
if(!s->budget--) { s->failed_pc=0x0c099d9eu; return 0; }
write(ram,r[4]+r[0],r[3],2);
if(!vf3_matrix_family(0x0c099da0u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c099da0u; return 0; } return 1;
P_0c099de0: /* original e064, guest PC 0x0c099de0 */
if(!s->budget--) { s->failed_pc=0x0c099de0u; return 0; }
r[0]=0x00000064u;
goto P_0c099de2;
P_0c099de2: /* original 01be, guest PC 0x0c099de2 */
if(!s->budget--) { s->failed_pc=0x0c099de2u; return 0; }
r[1]=read(ram,r[11]+r[0],4);
goto P_0c099de4;
P_0c099de4: /* original 6312, guest PC 0x0c099de4 */
if(!s->budget--) { s->failed_pc=0x0c099de4u; return 0; }
tmp=read(ram,r[1],4);
r[3]=tmp;
goto P_0c099de6;
P_0c099de6: /* original 2638, guest PC 0x0c099de6 */
if(!s->budget--) { s->failed_pc=0x0c099de6u; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[3])==0)!=0);
goto P_0c099de8;
P_0c099de8: /* original 8905, guest PC 0x0c099de8 */
if(!s->budget--) { s->failed_pc=0x0c099de8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c099df6; }
goto P_0c099dea;
P_0c099dea: /* original e054, guest PC 0x0c099dea */
if(!s->budget--) { s->failed_pc=0x0c099deau; return 0; }
r[0]=0x00000054u;
goto P_0c099dec;
P_0c099dec: /* original 045e, guest PC 0x0c099dec */
if(!s->budget--) { s->failed_pc=0x0c099decu; return 0; }
r[4]=read(ram,r[5]+r[0],4);
goto P_0c099dee;
P_0c099dee: /* original e022, guest PC 0x0c099dee */
if(!s->budget--) { s->failed_pc=0x0c099deeu; return 0; }
r[0]=0x00000022u;
goto P_0c099df0;
P_0c099df0: /* original 034d, guest PC 0x0c099df0 */
if(!s->budget--) { s->failed_pc=0x0c099df0u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c099df2;
P_0c099df2: /* original 9071, guest PC 0x0c099df2 */
if(!s->budget--) { s->failed_pc=0x0c099df2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c099ed8u,2);
goto P_0c099df4;
P_0c099df4: /* original 0535, guest PC 0x0c099df4 */
if(!s->budget--) { s->failed_pc=0x0c099df4u; return 0; }
write(ram,r[5]+r[0],r[3],2);
goto P_0c099df6;
P_0c099df6: /* original d33c, guest PC 0x0c099df6 */
if(!s->budget--) { s->failed_pc=0x0c099df6u; return 0; }
r[3]=read(ram,0x0c099ee8u,4);
goto P_0c099df8;
P_0c099df8: /* original e060, guest PC 0x0c099df8 */
if(!s->budget--) { s->failed_pc=0x0c099df8u; return 0; }
r[0]=0x00000060u;
goto P_0c099dfa;
P_0c099dfa: /* original 430b, guest PC 0x0c099dfa */
if(!s->budget--) { s->failed_pc=0x0c099dfau; return 0; }
target=r[3];
r[16]=code_base|0x0c099dfeu;
r[4]=read(ram,r[11]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c099dfeu) { target=s->pc; goto dispatch; }
goto P_0c099dfe;
P_0c099dfc: /* original 04be, guest PC 0x0c099dfc */
if(!s->budget--) { s->failed_pc=0x0c099dfcu; return 0; }
r[4]=read(ram,r[11]+r[0],4);
goto P_0c099dfe;
P_0c099dfe: /* original d33a, guest PC 0x0c099dfe */
if(!s->budget--) { s->failed_pc=0x0c099dfeu; return 0; }
r[3]=read(ram,0x0c099ee8u,4);
goto P_0c099e00;
P_0c099e00: /* original e064, guest PC 0x0c099e00 */
if(!s->budget--) { s->failed_pc=0x0c099e00u; return 0; }
r[0]=0x00000064u;
goto P_0c099e02;
P_0c099e02: /* original 430b, guest PC 0x0c099e02 */
if(!s->budget--) { s->failed_pc=0x0c099e02u; return 0; }
target=r[3];
r[16]=code_base|0x0c099e06u;
r[4]=read(ram,r[11]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c099e06u) { target=s->pc; goto dispatch; }
goto P_0c099e06;
P_0c099e04: /* original 04be, guest PC 0x0c099e04 */
if(!s->budget--) { s->failed_pc=0x0c099e04u; return 0; }
r[4]=read(ram,r[11]+r[0],4);
goto P_0c099e06;
P_0c099e06: /* original d338, guest PC 0x0c099e06 */
if(!s->budget--) { s->failed_pc=0x0c099e06u; return 0; }
r[3]=read(ram,0x0c099ee8u,4);
goto P_0c099e08;
P_0c099e08: /* original e068, guest PC 0x0c099e08 */
if(!s->budget--) { s->failed_pc=0x0c099e08u; return 0; }
r[0]=0x00000068u;
goto P_0c099e0a;
P_0c099e0a: /* original 430b, guest PC 0x0c099e0a */
if(!s->budget--) { s->failed_pc=0x0c099e0au; return 0; }
target=r[3];
r[16]=code_base|0x0c099e0eu;
r[4]=read(ram,r[11]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c099e0eu) { target=s->pc; goto dispatch; }
goto P_0c099e0e;
P_0c099e0c: /* original 04be, guest PC 0x0c099e0c */
if(!s->budget--) { s->failed_pc=0x0c099e0cu; return 0; }
r[4]=read(ram,r[11]+r[0],4);
goto P_0c099e0e;
P_0c099e0e: /* original d336, guest PC 0x0c099e0e */
if(!s->budget--) { s->failed_pc=0x0c099e0eu; return 0; }
r[3]=read(ram,0x0c099ee8u,4);
goto P_0c099e10;
P_0c099e10: /* original e06c, guest PC 0x0c099e10 */
if(!s->budget--) { s->failed_pc=0x0c099e10u; return 0; }
r[0]=0x0000006cu;
goto P_0c099e12;
P_0c099e12: /* original 430b, guest PC 0x0c099e12 */
if(!s->budget--) { s->failed_pc=0x0c099e12u; return 0; }
target=r[3];
r[16]=code_base|0x0c099e16u;
r[4]=read(ram,r[11]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c099e16u) { target=s->pc; goto dispatch; }
goto P_0c099e16;
P_0c099e14: /* original 04be, guest PC 0x0c099e14 */
if(!s->budget--) { s->failed_pc=0x0c099e14u; return 0; }
r[4]=read(ram,r[11]+r[0],4);
goto P_0c099e16;
P_0c099e16: /* original 59e2, guest PC 0x0c099e16 */
if(!s->budget--) { s->failed_pc=0x0c099e16u; return 0; }
r[9]=read(ram,r[14]+8,4);
goto P_0c099e18;
P_0c099e18: /* original e210, guest PC 0x0c099e18 */
if(!s->budget--) { s->failed_pc=0x0c099e18u; return 0; }
r[2]=0x00000010u;
goto P_0c099e1a;
P_0c099e1a: /* original 2298, guest PC 0x0c099e1a */
if(!s->budget--) { s->failed_pc=0x0c099e1au; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[9])==0)!=0);
goto P_0c099e1c;
P_0c099e1c: /* original 8d02, guest PC 0x0c099e1c */
if(!s->budget--) { s->failed_pc=0x0c099e1cu; return 0; }
cond=r[17]&1u;
r[12]=0x00000000u;
if(cond) { goto P_0c099e24; }
goto P_0c099e20;
P_0c099e1e: /* original ec00, guest PC 0x0c099e1e */
if(!s->budget--) { s->failed_pc=0x0c099e1eu; return 0; }
r[12]=0x00000000u;
goto P_0c099e20;
P_0c099e20: /* original a102, guest PC 0x0c099e20 */
if(!s->budget--) { s->failed_pc=0x0c099e20u; return 0; }
goto P_0c09a028;
P_0c099e22: /* original 0009, guest PC 0x0c099e22 */
if(!s->budget--) { s->failed_pc=0x0c099e22u; return 0; }
goto P_0c099e24;
P_0c099e24: /* original d331, guest PC 0x0c099e24 */
if(!s->budget--) { s->failed_pc=0x0c099e24u; return 0; }
r[3]=read(ram,0x0c099eecu,4);
goto P_0c099e26;
P_0c099e26: /* original 2398, guest PC 0x0c099e26 */
if(!s->budget--) { s->failed_pc=0x0c099e26u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[9])==0)!=0);
goto P_0c099e28;
P_0c099e28: /* original 8f02, guest PC 0x0c099e28 */
if(!s->budget--) { s->failed_pc=0x0c099e28u; return 0; }
cond=r[17]&1u;
r[8]=0x00000004u;
if(!cond) { goto P_0c099e30; }
goto P_0c099e2c;
P_0c099e2a: /* original e804, guest PC 0x0c099e2a */
if(!s->budget--) { s->failed_pc=0x0c099e2au; return 0; }
r[8]=0x00000004u;
goto P_0c099e2c;
P_0c099e2c: /* original a0dc, guest PC 0x0c099e2c */
if(!s->budget--) { s->failed_pc=0x0c099e2cu; return 0; }
goto P_0c099fe8;
P_0c099e2e: /* original 0009, guest PC 0x0c099e2e */
if(!s->budget--) { s->failed_pc=0x0c099e2eu; return 0; }
goto P_0c099e30;
P_0c099e30: /* original e029, guest PC 0x0c099e30 */
if(!s->budget--) { s->failed_pc=0x0c099e30u; return 0; }
r[0]=0x00000029u;
goto P_0c099e32;
P_0c099e32: /* original 0aec, guest PC 0x0c099e32 */
if(!s->budget--) { s->failed_pc=0x0c099e32u; return 0; }
r[10]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c099e34;
P_0c099e34: /* original 60ac, guest PC 0x0c099e34 */
if(!s->budget--) { s->failed_pc=0x0c099e34u; return 0; }
r[0]=r[10]&255u;
goto P_0c099e36;
P_0c099e36: /* original 8803, guest PC 0x0c099e36 */
if(!s->budget--) { s->failed_pc=0x0c099e36u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000003u)!=0);
goto P_0c099e38;
P_0c099e38: /* original 8d2c, guest PC 0x0c099e38 */
if(!s->budget--) { s->failed_pc=0x0c099e38u; return 0; }
cond=r[17]&1u;
r[10]=r[0];
if(cond) { goto P_0c099e94; }
goto P_0c099e3c;
P_0c099e3a: /* original 6a03, guest PC 0x0c099e3a */
if(!s->budget--) { s->failed_pc=0x0c099e3au; return 0; }
r[10]=r[0];
goto P_0c099e3c;
P_0c099e3c: /* original 2aa8, guest PC 0x0c099e3c */
if(!s->budget--) { s->failed_pc=0x0c099e3cu; return 0; }
r[17]=(r[17]&~1u)|(((r[10]&r[10])==0)!=0);
goto P_0c099e3e;
P_0c099e3e: /* original 8b01, guest PC 0x0c099e3e */
if(!s->budget--) { s->failed_pc=0x0c099e3eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c099e44; }
goto P_0c099e40;
P_0c099e40: /* original a0c2, guest PC 0x0c099e40 */
if(!s->budget--) { s->failed_pc=0x0c099e40u; return 0; }
goto P_0c099fc8;
P_0c099e42: /* original 0009, guest PC 0x0c099e42 */
if(!s->budget--) { s->failed_pc=0x0c099e42u; return 0; }
goto P_0c099e44;
P_0c099e44: /* original e02b, guest PC 0x0c099e44 */
if(!s->budget--) { s->failed_pc=0x0c099e44u; return 0; }
r[0]=0x0000002bu;
goto P_0c099e46;
P_0c099e46: /* original 00ec, guest PC 0x0c099e46 */
if(!s->budget--) { s->failed_pc=0x0c099e46u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c099e48;
P_0c099e48: /* original 8809, guest PC 0x0c099e48 */
if(!s->budget--) { s->failed_pc=0x0c099e48u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000009u)!=0);
goto P_0c099e4a;
P_0c099e4a: /* original 8b01, guest PC 0x0c099e4a */
if(!s->budget--) { s->failed_pc=0x0c099e4au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c099e50; }
goto P_0c099e4c;
P_0c099e4c: /* original a0ec, guest PC 0x0c099e4c */
if(!s->budget--) { s->failed_pc=0x0c099e4cu; return 0; }
goto P_0c09a028;
P_0c099e4e: /* original 0009, guest PC 0x0c099e4e */
if(!s->budget--) { s->failed_pc=0x0c099e4eu; return 0; }
goto P_0c099e50;
P_0c099e50: /* original e01d, guest PC 0x0c099e50 */
if(!s->budget--) { s->failed_pc=0x0c099e50u; return 0; }
r[0]=0x0000001du;
goto P_0c099e52;
P_0c099e52: /* original 04ec, guest PC 0x0c099e52 */
if(!s->budget--) { s->failed_pc=0x0c099e52u; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c099e54;
P_0c099e54: /* original 644c, guest PC 0x0c099e54 */
if(!s->budget--) { s->failed_pc=0x0c099e54u; return 0; }
r[4]=r[4]&255u;
goto P_0c099e56;
P_0c099e56: /* original 7401, guest PC 0x0c099e56 */
if(!s->budget--) { s->failed_pc=0x0c099e56u; return 0; }
r[4]+=0x00000001u;
goto P_0c099e58;
P_0c099e58: /* original 3a40, guest PC 0x0c099e58 */
if(!s->budget--) { s->failed_pc=0x0c099e58u; return 0; }
r[17]=(r[17]&~1u)|((r[10]==r[4])!=0);
goto P_0c099e5a;
P_0c099e5a: /* original 8901, guest PC 0x0c099e5a */
if(!s->budget--) { s->failed_pc=0x0c099e5au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c099e60; }
goto P_0c099e5c;
P_0c099e5c: /* original a0b4, guest PC 0x0c099e5c */
if(!s->budget--) { s->failed_pc=0x0c099e5cu; return 0; }
goto P_0c099fc8;
P_0c099e5e: /* original 0009, guest PC 0x0c099e5e */
if(!s->budget--) { s->failed_pc=0x0c099e5eu; return 0; }
goto P_0c099e60;
P_0c099e60: /* original e02b, guest PC 0x0c099e60 */
if(!s->budget--) { s->failed_pc=0x0c099e60u; return 0; }
r[0]=0x0000002bu;
goto P_0c099e62;
P_0c099e62: /* original 923a, guest PC 0x0c099e62 */
if(!s->budget--) { s->failed_pc=0x0c099e62u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c099edau,2);
goto P_0c099e64;
P_0c099e64: /* original 03ec, guest PC 0x0c099e64 */
if(!s->budget--) { s->failed_pc=0x0c099e64u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c099e66;
P_0c099e66: /* original 706d, guest PC 0x0c099e66 */
if(!s->budget--) { s->failed_pc=0x0c099e66u; return 0; }
r[0]+=0x0000006du;
goto P_0c099e68;
P_0c099e68: /* original 01de, guest PC 0x0c099e68 */
if(!s->budget--) { s->failed_pc=0x0c099e68u; return 0; }
r[1]=read(ram,r[13]+r[0],4);
goto P_0c099e6a;
P_0c099e6a: /* original 32ec, guest PC 0x0c099e6a */
if(!s->budget--) { s->failed_pc=0x0c099e6au; return 0; }
r[2]+=r[14];
goto P_0c099e6c;
P_0c099e6c: /* original 73ff, guest PC 0x0c099e6c */
if(!s->budget--) { s->failed_pc=0x0c099e6cu; return 0; }
r[3]+=0xffffffffu;
goto P_0c099e6e;
P_0c099e6e: /* original 4308, guest PC 0x0c099e6e */
if(!s->budget--) { s->failed_pc=0x0c099e6eu; return 0; }
r[3]<<=2;
goto P_0c099e70;
P_0c099e70: /* original 332c, guest PC 0x0c099e70 */
if(!s->budget--) { s->failed_pc=0x0c099e70u; return 0; }
r[3]+=r[2];
goto P_0c099e72;
P_0c099e72: /* original 2312, guest PC 0x0c099e72 */
if(!s->budget--) { s->failed_pc=0x0c099e72u; return 0; }
write(ram,r[3],r[1],4);
goto P_0c099e74;
P_0c099e74: /* original d31e, guest PC 0x0c099e74 */
if(!s->budget--) { s->failed_pc=0x0c099e74u; return 0; }
r[3]=read(ram,0x0c099ef0u,4);
goto P_0c099e76;
P_0c099e76: /* original 430b, guest PC 0x0c099e76 */
if(!s->budget--) { s->failed_pc=0x0c099e76u; return 0; }
target=r[3];
r[16]=code_base|0x0c099e7au;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c099e7au) { target=s->pc; goto dispatch; }
goto P_0c099e7a;
P_0c099e78: /* original 0009, guest PC 0x0c099e78 */
if(!s->budget--) { s->failed_pc=0x0c099e78u; return 0; }
goto P_0c099e7a;
P_0c099e7a: /* original e02b, guest PC 0x0c099e7a */
if(!s->budget--) { s->failed_pc=0x0c099e7au; return 0; }
r[0]=0x0000002bu;
goto P_0c099e7c;
P_0c099e7c: /* original 02ec, guest PC 0x0c099e7c */
if(!s->budget--) { s->failed_pc=0x0c099e7cu; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c099e7e;
P_0c099e7e: /* original 7201, guest PC 0x0c099e7e */
if(!s->budget--) { s->failed_pc=0x0c099e7eu; return 0; }
r[2]+=0x00000001u;
goto P_0c099e80;
P_0c099e80: /* original 0e24, guest PC 0x0c099e80 */
if(!s->budget--) { s->failed_pc=0x0c099e80u; return 0; }
write(ram,r[14]+r[0],r[2],1);
goto P_0c099e82;
P_0c099e82: /* original 54ed, guest PC 0x0c099e82 */
if(!s->budget--) { s->failed_pc=0x0c099e82u; return 0; }
r[4]=read(ram,r[14]+52,4);
goto P_0c099e84;
P_0c099e84: /* original 53ee, guest PC 0x0c099e84 */
if(!s->budget--) { s->failed_pc=0x0c099e84u; return 0; }
r[3]=read(ram,r[14]+56,4);
goto P_0c099e86;
P_0c099e86: /* original 343c, guest PC 0x0c099e86 */
if(!s->budget--) { s->failed_pc=0x0c099e86u; return 0; }
r[4]+=r[3];
goto P_0c099e88;
P_0c099e88: /* original 1e4c, guest PC 0x0c099e88 */
if(!s->budget--) { s->failed_pc=0x0c099e88u; return 0; }
write(ram,r[14]+48,r[4],4);
goto P_0c099e8a;
P_0c099e8a: /* original 1e4d, guest PC 0x0c099e8a */
if(!s->budget--) { s->failed_pc=0x0c099e8au; return 0; }
write(ram,r[14]+52,r[4],4);
goto P_0c099e8c;
P_0c099e8c: /* original 1ece, guest PC 0x0c099e8c */
if(!s->budget--) { s->failed_pc=0x0c099e8cu; return 0; }
write(ram,r[14]+56,r[12],4);
goto P_0c099e8e;
P_0c099e8e: /* original 60c3, guest PC 0x0c099e8e */
if(!s->budget--) { s->failed_pc=0x0c099e8eu; return 0; }
r[0]=r[12];
goto P_0c099e90;
P_0c099e90: /* original a0ef, guest PC 0x0c099e90 */
if(!s->budget--) { s->failed_pc=0x0c099e90u; return 0; }
write(ram,r[13]+11,r[0],1);
goto P_0c09a072;
P_0c099e92: /* original 80db, guest PC 0x0c099e92 */
if(!s->budget--) { s->failed_pc=0x0c099e92u; return 0; }
write(ram,r[13]+11,r[0],1);
goto P_0c099e94;
P_0c099e94: /* original 9022, guest PC 0x0c099e94 */
if(!s->budget--) { s->failed_pc=0x0c099e94u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c099edcu,2);
goto P_0c099e96;
P_0c099e96: /* original 02dc, guest PC 0x0c099e96 */
if(!s->budget--) { s->failed_pc=0x0c099e96u; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+r[0],1);
goto P_0c099e98;
P_0c099e98: /* original 2228, guest PC 0x0c099e98 */
if(!s->budget--) { s->failed_pc=0x0c099e98u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c099e9a;
P_0c099e9a: /* original 8901, guest PC 0x0c099e9a */
if(!s->budget--) { s->failed_pc=0x0c099e9au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c099ea0; }
goto P_0c099e9c;
P_0c099e9c: /* original a0d3, guest PC 0x0c099e9c */
if(!s->budget--) { s->failed_pc=0x0c099e9cu; return 0; }
goto P_0c09a046;
P_0c099e9e: /* original 0009, guest PC 0x0c099e9e */
if(!s->budget--) { s->failed_pc=0x0c099e9eu; return 0; }
goto P_0c099ea0;
P_0c099ea0: /* original 901d, guest PC 0x0c099ea0 */
if(!s->budget--) { s->failed_pc=0x0c099ea0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c099edeu,2);
goto P_0c099ea2;
P_0c099ea2: /* original 02ec, guest PC 0x0c099ea2 */
if(!s->budget--) { s->failed_pc=0x0c099ea2u; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c099ea4;
P_0c099ea4: /* original 901c, guest PC 0x0c099ea4 */
if(!s->budget--) { s->failed_pc=0x0c099ea4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c099ee0u,2);
goto P_0c099ea6;
P_0c099ea6: /* original 0e24, guest PC 0x0c099ea6 */
if(!s->budget--) { s->failed_pc=0x0c099ea6u; return 0; }
write(ram,r[14]+r[0],r[2],1);
goto P_0c099ea8;
P_0c099ea8: /* original d312, guest PC 0x0c099ea8 */
if(!s->budget--) { s->failed_pc=0x0c099ea8u; return 0; }
r[3]=read(ram,0x0c099ef4u,4);
goto P_0c099eaa;
P_0c099eaa: /* original 64f2, guest PC 0x0c099eaa */
if(!s->budget--) { s->failed_pc=0x0c099eaau; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c099eac;
P_0c099eac: /* original 430b, guest PC 0x0c099eac */
if(!s->budget--) { s->failed_pc=0x0c099eacu; return 0; }
target=r[3];
r[16]=code_base|0x0c099eb0u;
r[4]+=0x00000013u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c099eb0u) { target=s->pc; goto dispatch; }
goto P_0c099eb0;
P_0c099eae: /* original 7413, guest PC 0x0c099eae */
if(!s->budget--) { s->failed_pc=0x0c099eaeu; return 0; }
r[4]+=0x00000013u;
goto P_0c099eb0;
P_0c099eb0: /* original 640c, guest PC 0x0c099eb0 */
if(!s->budget--) { s->failed_pc=0x0c099eb0u; return 0; }
r[4]=r[0]&255u;
goto P_0c099eb2;
P_0c099eb2: /* original 2448, guest PC 0x0c099eb2 */
if(!s->budget--) { s->failed_pc=0x0c099eb2u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c099eb4;
P_0c099eb4: /* original 8905, guest PC 0x0c099eb4 */
if(!s->budget--) { s->failed_pc=0x0c099eb4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c099ec2; }
goto P_0c099eb6;
P_0c099eb6: /* original 9014, guest PC 0x0c099eb6 */
if(!s->budget--) { s->failed_pc=0x0c099eb6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c099ee2u,2);
goto P_0c099eb8;
P_0c099eb8: /* original 0aee, guest PC 0x0c099eb8 */
if(!s->budget--) { s->failed_pc=0x0c099eb8u; return 0; }
r[10]=read(ram,r[14]+r[0],4);
goto P_0c099eba;
P_0c099eba: /* original 3a43, guest PC 0x0c099eba */
if(!s->budget--) { s->failed_pc=0x0c099ebau; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[10]>=(int32_t)r[4])!=0);
goto P_0c099ebc;
P_0c099ebc: /* original 8b01, guest PC 0x0c099ebc */
if(!s->budget--) { s->failed_pc=0x0c099ebcu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c099ec2; }
goto P_0c099ebe;
P_0c099ebe: /* original a0c2, guest PC 0x0c099ebe */
if(!s->budget--) { s->failed_pc=0x0c099ebeu; return 0; }
goto P_0c09a046;
P_0c099ec0: /* original 0009, guest PC 0x0c099ec0 */
if(!s->budget--) { s->failed_pc=0x0c099ec0u; return 0; }
goto P_0c099ec2;
P_0c099ec2: /* original 900f, guest PC 0x0c099ec2 */
if(!s->budget--) { s->failed_pc=0x0c099ec2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c099ee4u,2);
goto P_0c099ec4;
P_0c099ec4: /* original 00ec, guest PC 0x0c099ec4 */
if(!s->budget--) { s->failed_pc=0x0c099ec4u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c099ec6;
P_0c099ec6: /* original 8801, guest PC 0x0c099ec6 */
if(!s->budget--) { s->failed_pc=0x0c099ec6u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c099ec8;
P_0c099ec8: /* original 891a, guest PC 0x0c099ec8 */
if(!s->budget--) { s->failed_pc=0x0c099ec8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c099f00; }
goto P_0c099eca;
P_0c099eca: /* original d30b, guest PC 0x0c099eca */
if(!s->budget--) { s->failed_pc=0x0c099ecau; return 0; }
r[3]=read(ram,0x0c099ef8u,4);
goto P_0c099ecc;
P_0c099ecc: /* original 2398, guest PC 0x0c099ecc */
if(!s->budget--) { s->failed_pc=0x0c099eccu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[9])==0)!=0);
goto P_0c099ece;
P_0c099ece: /* original 8920, guest PC 0x0c099ece */
if(!s->budget--) { s->failed_pc=0x0c099eceu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c099f12; }
goto P_0c099ed0;
P_0c099ed0: /* original d20a, guest PC 0x0c099ed0 */
if(!s->budget--) { s->failed_pc=0x0c099ed0u; return 0; }
r[2]=read(ram,0x0c099efcu,4);
goto P_0c099ed2;
P_0c099ed2: /* original 2929, guest PC 0x0c099ed2 */
if(!s->budget--) { s->failed_pc=0x0c099ed2u; return 0; }
r[9]&=r[2];
goto P_0c099ed4;
P_0c099ed4: /* original a01a, guest PC 0x0c099ed4 */
if(!s->budget--) { s->failed_pc=0x0c099ed4u; return 0; }
r[10]+=0xffffffffu;
goto P_0c099f0c;
P_0c099ed6: /* original 7aff, guest PC 0x0c099ed6 */
if(!s->budget--) { s->failed_pc=0x0c099ed6u; return 0; }
r[10]+=0xffffffffu;
if(!vf3_matrix_family(0x0c099ed8u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c099ed8u; return 0; } return 1;
P_0c099f00: /* original d242, guest PC 0x0c099f00 */
if(!s->budget--) { s->failed_pc=0x0c099f00u; return 0; }
r[2]=read(ram,0x0c09a00cu,4);
goto P_0c099f02;
P_0c099f02: /* original 2298, guest PC 0x0c099f02 */
if(!s->budget--) { s->failed_pc=0x0c099f02u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[9])==0)!=0);
goto P_0c099f04;
P_0c099f04: /* original 8905, guest PC 0x0c099f04 */
if(!s->budget--) { s->failed_pc=0x0c099f04u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c099f12; }
goto P_0c099f06;
P_0c099f06: /* original d342, guest PC 0x0c099f06 */
if(!s->budget--) { s->failed_pc=0x0c099f06u; return 0; }
r[3]=read(ram,0x0c09a010u,4);
goto P_0c099f08;
P_0c099f08: /* original 7afe, guest PC 0x0c099f08 */
if(!s->budget--) { s->failed_pc=0x0c099f08u; return 0; }
r[10]+=0xfffffffeu;
goto P_0c099f0a;
P_0c099f0a: /* original 2939, guest PC 0x0c099f0a */
if(!s->budget--) { s->failed_pc=0x0c099f0au; return 0; }
r[9]&=r[3];
goto P_0c099f0c;
P_0c099f0c: /* original 9075, guest PC 0x0c099f0c */
if(!s->budget--) { s->failed_pc=0x0c099f0cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c099ffau,2);
goto P_0c099f0e;
P_0c099f0e: /* original 0ea4, guest PC 0x0c099f0e */
if(!s->budget--) { s->failed_pc=0x0c099f0eu; return 0; }
write(ram,r[14]+r[0],r[10],1);
goto P_0c099f10;
P_0c099f10: /* original 1e92, guest PC 0x0c099f10 */
if(!s->budget--) { s->failed_pc=0x0c099f10u; return 0; }
write(ram,r[14]+8,r[9],4);
goto P_0c099f12;
P_0c099f12: /* original 9073, guest PC 0x0c099f12 */
if(!s->budget--) { s->failed_pc=0x0c099f12u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c099ffcu,2);
goto P_0c099f14;
P_0c099f14: /* original 00ec, guest PC 0x0c099f14 */
if(!s->budget--) { s->failed_pc=0x0c099f14u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c099f16;
P_0c099f16: /* original 8801, guest PC 0x0c099f16 */
if(!s->budget--) { s->failed_pc=0x0c099f16u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c099f18;
P_0c099f18: /* original 8905, guest PC 0x0c099f18 */
if(!s->budget--) { s->failed_pc=0x0c099f18u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c099f26; }
goto P_0c099f1a;
P_0c099f1a: /* original 9070, guest PC 0x0c099f1a */
if(!s->budget--) { s->failed_pc=0x0c099f1au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c099ffeu,2);
goto P_0c099f1c;
P_0c099f1c: /* original 05ec, guest PC 0x0c099f1c */
if(!s->budget--) { s->failed_pc=0x0c099f1cu; return 0; }
r[5]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c099f1e;
P_0c099f1e: /* original 7002, guest PC 0x0c099f1e */
if(!s->budget--) { s->failed_pc=0x0c099f1eu; return 0; }
r[0]+=0x00000002u;
goto P_0c099f20;
P_0c099f20: /* original 04ec, guest PC 0x0c099f20 */
if(!s->budget--) { s->failed_pc=0x0c099f20u; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c099f22;
P_0c099f22: /* original 3540, guest PC 0x0c099f22 */
if(!s->budget--) { s->failed_pc=0x0c099f22u; return 0; }
r[17]=(r[17]&~1u)|((r[5]==r[4])!=0);
goto P_0c099f24;
P_0c099f24: /* original 8b5a, guest PC 0x0c099f24 */
if(!s->budget--) { s->failed_pc=0x0c099f24u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c099fdc; }
goto P_0c099f26;
P_0c099f26: /* original 53e2, guest PC 0x0c099f26 */
if(!s->budget--) { s->failed_pc=0x0c099f26u; return 0; }
r[3]=read(ram,r[14]+8,4);
goto P_0c099f28;
P_0c099f28: /* original d73a, guest PC 0x0c099f28 */
if(!s->budget--) { s->failed_pc=0x0c099f28u; return 0; }
r[7]=read(ram,0x0c09a014u,4);
goto P_0c099f2a;
P_0c099f2a: /* original 9069, guest PC 0x0c099f2a */
if(!s->budget--) { s->failed_pc=0x0c099f2au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09a000u,2);
goto P_0c099f2c;
P_0c099f2c: /* original 2838, guest PC 0x0c099f2c */
if(!s->budget--) { s->failed_pc=0x0c099f2cu; return 0; }
r[17]=(r[17]&~1u)|(((r[8]&r[3])==0)!=0);
goto P_0c099f2e;
P_0c099f2e: /* original 8d2b, guest PC 0x0c099f2e */
if(!s->budget--) { s->failed_pc=0x0c099f2eu; return 0; }
cond=r[17]&1u;
r[4]=read(ram,r[13]+r[0],4);
if(cond) { goto P_0c099f88; }
goto P_0c099f32;
P_0c099f30: /* original 04de, guest PC 0x0c099f30 */
if(!s->budget--) { s->failed_pc=0x0c099f30u; return 0; }
r[4]=read(ram,r[13]+r[0],4);
goto P_0c099f32;
P_0c099f32: /* original e02a, guest PC 0x0c099f32 */
if(!s->budget--) { s->failed_pc=0x0c099f32u; return 0; }
r[0]=0x0000002au;
goto P_0c099f34;
P_0c099f34: /* original 00ec, guest PC 0x0c099f34 */
if(!s->budget--) { s->failed_pc=0x0c099f34u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c099f36;
P_0c099f36: /* original 600c, guest PC 0x0c099f36 */
if(!s->budget--) { s->failed_pc=0x0c099f36u; return 0; }
r[0]=r[0]&255u;
goto P_0c099f38;
P_0c099f38: /* original 8802, guest PC 0x0c099f38 */
if(!s->budget--) { s->failed_pc=0x0c099f38u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c099f3a;
P_0c099f3a: /* original 8b02, guest PC 0x0c099f3a */
if(!s->budget--) { s->failed_pc=0x0c099f3au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c099f42; }
goto P_0c099f3c;
P_0c099f3c: /* original 9b61, guest PC 0x0c099f3c */
if(!s->budget--) { s->failed_pc=0x0c099f3cu; return 0; }
r[11]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09a002u,2);
goto P_0c099f3e;
P_0c099f3e: /* original a001, guest PC 0x0c099f3e */
if(!s->budget--) { s->failed_pc=0x0c099f3eu; return 0; }
goto P_0c099f44;
P_0c099f40: /* original 0009, guest PC 0x0c099f40 */
if(!s->budget--) { s->failed_pc=0x0c099f40u; return 0; }
goto P_0c099f42;
P_0c099f42: /* original 9b5f, guest PC 0x0c099f42 */
if(!s->budget--) { s->failed_pc=0x0c099f42u; return 0; }
r[11]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09a004u,2);
goto P_0c099f44;
P_0c099f44: /* original 66c3, guest PC 0x0c099f44 */
if(!s->budget--) { s->failed_pc=0x0c099f44u; return 0; }
r[6]=r[12];
goto P_0c099f46;
P_0c099f46: /* original 3bec, guest PC 0x0c099f46 */
if(!s->budget--) { s->failed_pc=0x0c099f46u; return 0; }
r[11]+=r[14];
goto P_0c099f48;
P_0c099f48: /* original 6063, guest PC 0x0c099f48 */
if(!s->budget--) { s->failed_pc=0x0c099f48u; return 0; }
r[0]=r[6];
goto P_0c099f4a;
P_0c099f4a: /* original 05bc, guest PC 0x0c099f4a */
if(!s->budget--) { s->failed_pc=0x0c099f4au; return 0; }
r[5]=(uint32_t)(int32_t)(int8_t)read(ram,r[11]+r[0],1);
goto P_0c099f4c;
P_0c099f4c: /* original e30d, guest PC 0x0c099f4c */
if(!s->budget--) { s->failed_pc=0x0c099f4cu; return 0; }
r[3]=0x0000000du;
goto P_0c099f4e;
P_0c099f4e: /* original 655c, guest PC 0x0c099f4e */
if(!s->budget--) { s->failed_pc=0x0c099f4eu; return 0; }
r[5]=r[5]&255u;
goto P_0c099f50;
P_0c099f50: /* original 3533, guest PC 0x0c099f50 */
if(!s->budget--) { s->failed_pc=0x0c099f50u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[5]>=(int32_t)r[3])!=0);
goto P_0c099f52;
P_0c099f52: /* original 8b00, guest PC 0x0c099f52 */
if(!s->budget--) { s->failed_pc=0x0c099f52u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c099f56; }
goto P_0c099f54;
P_0c099f54: /* original 75f3, guest PC 0x0c099f54 */
if(!s->budget--) { s->failed_pc=0x0c099f54u; return 0; }
r[5]+=0xfffffff3u;
goto P_0c099f56;
P_0c099f56: /* original 9a56, guest PC 0x0c099f56 */
if(!s->budget--) { s->failed_pc=0x0c099f56u; return 0; }
r[10]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09a006u,2);
goto P_0c099f58;
P_0c099f58: /* original 3aec, guest PC 0x0c099f58 */
if(!s->budget--) { s->failed_pc=0x0c099f58u; return 0; }
r[10]+=r[14];
goto P_0c099f5a;
P_0c099f5a: /* original 3a5c, guest PC 0x0c099f5a */
if(!s->budget--) { s->failed_pc=0x0c099f5au; return 0; }
r[10]+=r[5];
goto P_0c099f5c;
P_0c099f5c: /* original 2fa2, guest PC 0x0c099f5c */
if(!s->budget--) { s->failed_pc=0x0c099f5cu; return 0; }
write(ram,r[15],r[10],4);
goto P_0c099f5e;
P_0c099f5e: /* original 6aa0, guest PC 0x0c099f5e */
if(!s->budget--) { s->failed_pc=0x0c099f5eu; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[10],1);
r[10]=tmp;
goto P_0c099f60;
P_0c099f60: /* original 63f2, guest PC 0x0c099f60 */
if(!s->budget--) { s->failed_pc=0x0c099f60u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c099f62;
P_0c099f62: /* original 7aff, guest PC 0x0c099f62 */
if(!s->budget--) { s->failed_pc=0x0c099f62u; return 0; }
r[10]+=0xffffffffu;
goto P_0c099f64;
P_0c099f64: /* original 23a0, guest PC 0x0c099f64 */
if(!s->budget--) { s->failed_pc=0x0c099f64u; return 0; }
write(ram,r[3],r[10],1);
goto P_0c099f66;
P_0c099f66: /* original 6aae, guest PC 0x0c099f66 */
if(!s->budget--) { s->failed_pc=0x0c099f66u; return 0; }
r[10]=(uint32_t)(int32_t)(int8_t)r[10];
goto P_0c099f68;
P_0c099f68: /* original 4a15, guest PC 0x0c099f68 */
if(!s->budget--) { s->failed_pc=0x0c099f68u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[10]>0)!=0);
goto P_0c099f6a;
P_0c099f6a: /* original 8d07, guest PC 0x0c099f6a */
if(!s->budget--) { s->failed_pc=0x0c099f6au; return 0; }
cond=r[17]&1u;
r[6]+=0x00000001u;
if(cond) { goto P_0c099f7c; }
goto P_0c099f6e;
P_0c099f6c: /* original 7601, guest PC 0x0c099f6c */
if(!s->budget--) { s->failed_pc=0x0c099f6cu; return 0; }
r[6]+=0x00000001u;
goto P_0c099f6e;
P_0c099f6e: /* original 655b, guest PC 0x0c099f6e */
if(!s->budget--) { s->failed_pc=0x0c099f6eu; return 0; }
r[5]=0u-r[5];
goto P_0c099f70;
P_0c099f70: /* original 6a73, guest PC 0x0c099f70 */
if(!s->budget--) { s->failed_pc=0x0c099f70u; return 0; }
r[10]=r[7];
goto P_0c099f72;
P_0c099f72: /* original 4a5d, guest PC 0x0c099f72 */
if(!s->budget--) { s->failed_pc=0x0c099f72u; return 0; }
r[10]=(r[5]&0x80000000u)?((r[5]&31u)?r[10]>>((-r[5])&31u):0):r[10]<<(r[5]&31u);
goto P_0c099f74;
P_0c099f74: /* original 9044, guest PC 0x0c099f74 */
if(!s->budget--) { s->failed_pc=0x0c099f74u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09a000u,2);
goto P_0c099f76;
P_0c099f76: /* original 6aa7, guest PC 0x0c099f76 */
if(!s->budget--) { s->failed_pc=0x0c099f76u; return 0; }
r[10]=~r[10];
goto P_0c099f78;
P_0c099f78: /* original 24a9, guest PC 0x0c099f78 */
if(!s->budget--) { s->failed_pc=0x0c099f78u; return 0; }
r[4]&=r[10];
goto P_0c099f7a;
P_0c099f7a: /* original 0d46, guest PC 0x0c099f7a */
if(!s->budget--) { s->failed_pc=0x0c099f7au; return 0; }
write(ram,r[13]+r[0],r[4],4);
goto P_0c099f7c;
P_0c099f7c: /* original 9044, guest PC 0x0c099f7c */
if(!s->budget--) { s->failed_pc=0x0c099f7cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09a008u,2);
goto P_0c099f7e;
P_0c099f7e: /* original 03ec, guest PC 0x0c099f7e */
if(!s->budget--) { s->failed_pc=0x0c099f7eu; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c099f80;
P_0c099f80: /* original 3633, guest PC 0x0c099f80 */
if(!s->budget--) { s->failed_pc=0x0c099f80u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[6]>=(int32_t)r[3])!=0);
goto P_0c099f82;
P_0c099f82: /* original 8be1, guest PC 0x0c099f82 */
if(!s->budget--) { s->failed_pc=0x0c099f82u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c099f48; }
goto P_0c099f84;
P_0c099f84: /* original af83, guest PC 0x0c099f84 */
if(!s->budget--) { s->failed_pc=0x0c099f84u; return 0; }
goto P_0c099e8e;
P_0c099f86: /* original 0009, guest PC 0x0c099f86 */
if(!s->budget--) { s->failed_pc=0x0c099f86u; return 0; }
goto P_0c099f88;
P_0c099f88: /* original e02a, guest PC 0x0c099f88 */
if(!s->budget--) { s->failed_pc=0x0c099f88u; return 0; }
r[0]=0x0000002au;
goto P_0c099f8a;
P_0c099f8a: /* original 00ec, guest PC 0x0c099f8a */
if(!s->budget--) { s->failed_pc=0x0c099f8au; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c099f8c;
P_0c099f8c: /* original 600c, guest PC 0x0c099f8c */
if(!s->budget--) { s->failed_pc=0x0c099f8cu; return 0; }
r[0]=r[0]&255u;
goto P_0c099f8e;
P_0c099f8e: /* original 8802, guest PC 0x0c099f8e */
if(!s->budget--) { s->failed_pc=0x0c099f8eu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c099f90;
P_0c099f90: /* original 8f02, guest PC 0x0c099f90 */
if(!s->budget--) { s->failed_pc=0x0c099f90u; return 0; }
cond=r[17]&1u;
r[0]=0x00000061u;
if(!cond) { goto P_0c099f98; }
goto P_0c099f94;
P_0c099f92: /* original e061, guest PC 0x0c099f92 */
if(!s->budget--) { s->failed_pc=0x0c099f92u; return 0; }
r[0]=0x00000061u;
goto P_0c099f94;
P_0c099f94: /* original a001, guest PC 0x0c099f94 */
if(!s->budget--) { s->failed_pc=0x0c099f94u; return 0; }
r[5]=read(ram,r[11]+16,4);
goto P_0c099f9a;
P_0c099f96: /* original 55b4, guest PC 0x0c099f96 */
if(!s->budget--) { s->failed_pc=0x0c099f96u; return 0; }
r[5]=read(ram,r[11]+16,4);
goto P_0c099f98;
P_0c099f98: /* original 55b5, guest PC 0x0c099f98 */
if(!s->budget--) { s->failed_pc=0x0c099f98u; return 0; }
r[5]=read(ram,r[11]+20,4);
goto P_0c099f9a;
P_0c099f9a: /* original 065c, guest PC 0x0c099f9a */
if(!s->budget--) { s->failed_pc=0x0c099f9au; return 0; }
r[6]=(uint32_t)(int32_t)(int8_t)read(ram,r[5]+r[0],1);
goto P_0c099f9c;
P_0c099f9c: /* original 9533, guest PC 0x0c099f9c */
if(!s->budget--) { s->failed_pc=0x0c099f9cu; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09a006u,2);
goto P_0c099f9e;
P_0c099f9e: /* original 666c, guest PC 0x0c099f9e */
if(!s->budget--) { s->failed_pc=0x0c099f9eu; return 0; }
r[6]=r[6]&255u;
goto P_0c099fa0;
P_0c099fa0: /* original 35ec, guest PC 0x0c099fa0 */
if(!s->budget--) { s->failed_pc=0x0c099fa0u; return 0; }
r[5]+=r[14];
goto P_0c099fa2;
P_0c099fa2: /* original 356c, guest PC 0x0c099fa2 */
if(!s->budget--) { s->failed_pc=0x0c099fa2u; return 0; }
r[5]+=r[6];
goto P_0c099fa4;
P_0c099fa4: /* original 2f52, guest PC 0x0c099fa4 */
if(!s->budget--) { s->failed_pc=0x0c099fa4u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c099fa6;
P_0c099fa6: /* original 6550, guest PC 0x0c099fa6 */
if(!s->budget--) { s->failed_pc=0x0c099fa6u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[5],1);
r[5]=tmp;
goto P_0c099fa8;
P_0c099fa8: /* original 63f2, guest PC 0x0c099fa8 */
if(!s->budget--) { s->failed_pc=0x0c099fa8u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c099faa;
P_0c099faa: /* original 75ff, guest PC 0x0c099faa */
if(!s->budget--) { s->failed_pc=0x0c099faau; return 0; }
r[5]+=0xffffffffu;
goto P_0c099fac;
P_0c099fac: /* original 2350, guest PC 0x0c099fac */
if(!s->budget--) { s->failed_pc=0x0c099facu; return 0; }
write(ram,r[3],r[5],1);
goto P_0c099fae;
P_0c099fae: /* original 655e, guest PC 0x0c099fae */
if(!s->budget--) { s->failed_pc=0x0c099faeu; return 0; }
r[5]=(uint32_t)(int32_t)(int8_t)r[5];
goto P_0c099fb0;
P_0c099fb0: /* original 2558, guest PC 0x0c099fb0 */
if(!s->budget--) { s->failed_pc=0x0c099fb0u; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[5])==0)!=0);
goto P_0c099fb2;
P_0c099fb2: /* original 8901, guest PC 0x0c099fb2 */
if(!s->budget--) { s->failed_pc=0x0c099fb2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c099fb8; }
goto P_0c099fb4;
P_0c099fb4: /* original af6b, guest PC 0x0c099fb4 */
if(!s->budget--) { s->failed_pc=0x0c099fb4u; return 0; }
goto P_0c099e8e;
P_0c099fb6: /* original 0009, guest PC 0x0c099fb6 */
if(!s->budget--) { s->failed_pc=0x0c099fb6u; return 0; }
goto P_0c099fb8;
P_0c099fb8: /* original 666b, guest PC 0x0c099fb8 */
if(!s->budget--) { s->failed_pc=0x0c099fb8u; return 0; }
r[6]=0u-r[6];
goto P_0c099fba;
P_0c099fba: /* original 6573, guest PC 0x0c099fba */
if(!s->budget--) { s->failed_pc=0x0c099fbau; return 0; }
r[5]=r[7];
goto P_0c099fbc;
P_0c099fbc: /* original 456d, guest PC 0x0c099fbc */
if(!s->budget--) { s->failed_pc=0x0c099fbcu; return 0; }
r[5]=(r[6]&0x80000000u)?((r[6]&31u)?r[5]>>((-r[6])&31u):0):r[5]<<(r[6]&31u);
goto P_0c099fbe;
P_0c099fbe: /* original 901f, guest PC 0x0c099fbe */
if(!s->budget--) { s->failed_pc=0x0c099fbeu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09a000u,2);
goto P_0c099fc0;
P_0c099fc0: /* original 6557, guest PC 0x0c099fc0 */
if(!s->budget--) { s->failed_pc=0x0c099fc0u; return 0; }
r[5]=~r[5];
goto P_0c099fc2;
P_0c099fc2: /* original 2459, guest PC 0x0c099fc2 */
if(!s->budget--) { s->failed_pc=0x0c099fc2u; return 0; }
r[4]&=r[5];
goto P_0c099fc4;
P_0c099fc4: /* original af63, guest PC 0x0c099fc4 */
if(!s->budget--) { s->failed_pc=0x0c099fc4u; return 0; }
write(ram,r[13]+r[0],r[4],4);
goto P_0c099e8e;
P_0c099fc6: /* original 0d46, guest PC 0x0c099fc6 */
if(!s->budget--) { s->failed_pc=0x0c099fc6u; return 0; }
write(ram,r[13]+r[0],r[4],4);
goto P_0c099fc8;
P_0c099fc8: /* original 54ed, guest PC 0x0c099fc8 */
if(!s->budget--) { s->failed_pc=0x0c099fc8u; return 0; }
r[4]=read(ram,r[14]+52,4);
goto P_0c099fca;
P_0c099fca: /* original 52ee, guest PC 0x0c099fca */
if(!s->budget--) { s->failed_pc=0x0c099fcau; return 0; }
r[2]=read(ram,r[14]+56,4);
goto P_0c099fcc;
P_0c099fcc: /* original 342c, guest PC 0x0c099fcc */
if(!s->budget--) { s->failed_pc=0x0c099fccu; return 0; }
r[4]+=r[2];
goto P_0c099fce;
P_0c099fce: /* original 1e4c, guest PC 0x0c099fce */
if(!s->budget--) { s->failed_pc=0x0c099fceu; return 0; }
write(ram,r[14]+48,r[4],4);
goto P_0c099fd0;
P_0c099fd0: /* original 1e4d, guest PC 0x0c099fd0 */
if(!s->budget--) { s->failed_pc=0x0c099fd0u; return 0; }
write(ram,r[14]+52,r[4],4);
goto P_0c099fd2;
P_0c099fd2: /* original 1ece, guest PC 0x0c099fd2 */
if(!s->budget--) { s->failed_pc=0x0c099fd2u; return 0; }
write(ram,r[14]+56,r[12],4);
goto P_0c099fd4;
P_0c099fd4: /* original 9011, guest PC 0x0c099fd4 */
if(!s->budget--) { s->failed_pc=0x0c099fd4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c099ffau,2);
goto P_0c099fd6;
P_0c099fd6: /* original 03ec, guest PC 0x0c099fd6 */
if(!s->budget--) { s->failed_pc=0x0c099fd6u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c099fd8;
P_0c099fd8: /* original 9017, guest PC 0x0c099fd8 */
if(!s->budget--) { s->failed_pc=0x0c099fd8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09a00au,2);
goto P_0c099fda;
P_0c099fda: /* original 0e34, guest PC 0x0c099fda */
if(!s->budget--) { s->failed_pc=0x0c099fdau; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c099fdc;
P_0c099fdc: /* original d20e, guest PC 0x0c099fdc */
if(!s->budget--) { s->failed_pc=0x0c099fdcu; return 0; }
r[2]=read(ram,0x0c09a018u,4);
goto P_0c099fde;
P_0c099fde: /* original 420b, guest PC 0x0c099fde */
if(!s->budget--) { s->failed_pc=0x0c099fdeu; return 0; }
target=r[2];
r[16]=code_base|0x0c099fe2u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c099fe2u) { target=s->pc; goto dispatch; }
goto P_0c099fe2;
P_0c099fe0: /* original 0009, guest PC 0x0c099fe0 */
if(!s->budget--) { s->failed_pc=0x0c099fe0u; return 0; }
goto P_0c099fe2;
P_0c099fe2: /* original e008, guest PC 0x0c099fe2 */
if(!s->budget--) { s->failed_pc=0x0c099fe2u; return 0; }
r[0]=0x00000008u;
goto P_0c099fe4;
P_0c099fe4: /* original a045, guest PC 0x0c099fe4 */
if(!s->budget--) { s->failed_pc=0x0c099fe4u; return 0; }
write(ram,r[13]+10,r[0],1);
goto P_0c09a072;
P_0c099fe6: /* original 80da, guest PC 0x0c099fe6 */
if(!s->budget--) { s->failed_pc=0x0c099fe6u; return 0; }
write(ram,r[13]+10,r[0],1);
goto P_0c099fe8;
P_0c099fe8: /* original e01c, guest PC 0x0c099fe8 */
if(!s->budget--) { s->failed_pc=0x0c099fe8u; return 0; }
r[0]=0x0000001cu;
goto P_0c099fea;
P_0c099fea: /* original 03ec, guest PC 0x0c099fea */
if(!s->budget--) { s->failed_pc=0x0c099feau; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c099fec;
P_0c099fec: /* original 7301, guest PC 0x0c099fec */
if(!s->budget--) { s->failed_pc=0x0c099fecu; return 0; }
r[3]+=0x00000001u;
goto P_0c099fee;
P_0c099fee: /* original 0e34, guest PC 0x0c099fee */
if(!s->budget--) { s->failed_pc=0x0c099feeu; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c099ff0;
P_0c099ff0: /* original 52e2, guest PC 0x0c099ff0 */
if(!s->budget--) { s->failed_pc=0x0c099ff0u; return 0; }
r[2]=read(ram,r[14]+8,4);
goto P_0c099ff2;
P_0c099ff2: /* original 2288, guest PC 0x0c099ff2 */
if(!s->budget--) { s->failed_pc=0x0c099ff2u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[8])==0)!=0);
goto P_0c099ff4;
P_0c099ff4: /* original 8912, guest PC 0x0c099ff4 */
if(!s->budget--) { s->failed_pc=0x0c099ff4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09a01c; }
goto P_0c099ff6;
P_0c099ff6: /* original a012, guest PC 0x0c099ff6 */
if(!s->budget--) { s->failed_pc=0x0c099ff6u; return 0; }
r[0]=0x00000011u;
goto P_0c09a01e;
P_0c099ff8: /* original e011, guest PC 0x0c099ff8 */
if(!s->budget--) { s->failed_pc=0x0c099ff8u; return 0; }
r[0]=0x00000011u;
if(!vf3_matrix_family(0x0c099ffau,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c099ffau; return 0; } return 1;
P_0c09a01c: /* original 6083, guest PC 0x0c09a01c */
if(!s->budget--) { s->failed_pc=0x0c09a01cu; return 0; }
r[0]=r[8];
goto P_0c09a01e;
P_0c09a01e: /* original d345, guest PC 0x0c09a01e */
if(!s->budget--) { s->failed_pc=0x0c09a01eu; return 0; }
r[3]=read(ram,0x0c09a134u,4);
goto P_0c09a020;
P_0c09a020: /* original 430b, guest PC 0x0c09a020 */
if(!s->budget--) { s->failed_pc=0x0c09a020u; return 0; }
target=r[3];
r[16]=code_base|0x0c09a024u;
write(ram,r[13]+11,r[0],1);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09a024u) { target=s->pc; goto dispatch; }
goto P_0c09a024;
P_0c09a022: /* original 80db, guest PC 0x0c09a022 */
if(!s->budget--) { s->failed_pc=0x0c09a022u; return 0; }
write(ram,r[13]+11,r[0],1);
goto P_0c09a024;
P_0c09a024: /* original a025, guest PC 0x0c09a024 */
if(!s->budget--) { s->failed_pc=0x0c09a024u; return 0; }
goto P_0c09a072;
P_0c09a026: /* original 0009, guest PC 0x0c09a026 */
if(!s->budget--) { s->failed_pc=0x0c09a026u; return 0; }
goto P_0c09a028;
P_0c09a028: /* original e00c, guest PC 0x0c09a028 */
if(!s->budget--) { s->failed_pc=0x0c09a028u; return 0; }
r[0]=0x0000000cu;
goto P_0c09a02a;
P_0c09a02a: /* original e500, guest PC 0x0c09a02a */
if(!s->budget--) { s->failed_pc=0x0c09a02au; return 0; }
r[5]=0x00000000u;
goto P_0c09a02c;
P_0c09a02c: /* original 80da, guest PC 0x0c09a02c */
if(!s->budget--) { s->failed_pc=0x0c09a02cu; return 0; }
write(ram,r[13]+10,r[0],1);
goto P_0c09a02e;
P_0c09a02e: /* original 2fc6, guest PC 0x0c09a02e */
if(!s->budget--) { s->failed_pc=0x0c09a02eu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09a030;
P_0c09a030: /* original e731, guest PC 0x0c09a030 */
if(!s->budget--) { s->failed_pc=0x0c09a030u; return 0; }
r[7]=0x00000031u;
goto P_0c09a032;
P_0c09a032: /* original 54f2, guest PC 0x0c09a032 */
if(!s->budget--) { s->failed_pc=0x0c09a032u; return 0; }
r[4]=read(ram,r[15]+8,4);
goto P_0c09a034;
P_0c09a034: /* original e63f, guest PC 0x0c09a034 */
if(!s->budget--) { s->failed_pc=0x0c09a034u; return 0; }
r[6]=0x0000003fu;
goto P_0c09a036;
P_0c09a036: /* original d340, guest PC 0x0c09a036 */
if(!s->budget--) { s->failed_pc=0x0c09a036u; return 0; }
r[3]=read(ram,0x0c09a138u,4);
goto P_0c09a038;
P_0c09a038: /* original 430b, guest PC 0x0c09a038 */
if(!s->budget--) { s->failed_pc=0x0c09a038u; return 0; }
target=r[3];
r[16]=code_base|0x0c09a03cu;
r[4]+=0x0000002cu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09a03cu) { target=s->pc; goto dispatch; }
goto P_0c09a03c;
P_0c09a03a: /* original 742c, guest PC 0x0c09a03a */
if(!s->budget--) { s->failed_pc=0x0c09a03au; return 0; }
r[4]+=0x0000002cu;
goto P_0c09a03c;
P_0c09a03c: /* original d23f, guest PC 0x0c09a03c */
if(!s->budget--) { s->failed_pc=0x0c09a03cu; return 0; }
r[2]=read(ram,0x0c09a13cu,4);
goto P_0c09a03e;
P_0c09a03e: /* original 420b, guest PC 0x0c09a03e */
if(!s->budget--) { s->failed_pc=0x0c09a03eu; return 0; }
target=r[2];
r[16]=code_base|0x0c09a042u;
r[15]+=0x00000004u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09a042u) { target=s->pc; goto dispatch; }
goto P_0c09a042;
P_0c09a040: /* original 7f04, guest PC 0x0c09a040 */
if(!s->budget--) { s->failed_pc=0x0c09a040u; return 0; }
r[15]+=0x00000004u;
goto P_0c09a042;
P_0c09a042: /* original a016, guest PC 0x0c09a042 */
if(!s->budget--) { s->failed_pc=0x0c09a042u; return 0; }
goto P_0c09a072;
P_0c09a044: /* original 0009, guest PC 0x0c09a044 */
if(!s->budget--) { s->failed_pc=0x0c09a044u; return 0; }
goto P_0c09a046;
P_0c09a046: /* original 9071, guest PC 0x0c09a046 */
if(!s->budget--) { s->failed_pc=0x0c09a046u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09a12cu,2);
goto P_0c09a048;
P_0c09a048: /* original 03dc, guest PC 0x0c09a048 */
if(!s->budget--) { s->failed_pc=0x0c09a048u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+r[0],1);
goto P_0c09a04a;
P_0c09a04a: /* original 2338, guest PC 0x0c09a04a */
if(!s->budget--) { s->failed_pc=0x0c09a04au; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c09a04c;
P_0c09a04c: /* original 890f, guest PC 0x0c09a04c */
if(!s->budget--) { s->failed_pc=0x0c09a04cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09a06e; }
goto P_0c09a04e;
P_0c09a04e: /* original 6083, guest PC 0x0c09a04e */
if(!s->budget--) { s->failed_pc=0x0c09a04eu; return 0; }
r[0]=r[8];
goto P_0c09a050;
P_0c09a050: /* original 80da, guest PC 0x0c09a050 */
if(!s->budget--) { s->failed_pc=0x0c09a050u; return 0; }
write(ram,r[13]+10,r[0],1);
goto P_0c09a052;
P_0c09a052: /* original 906c, guest PC 0x0c09a052 */
if(!s->budget--) { s->failed_pc=0x0c09a052u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09a12eu,2);
goto P_0c09a054;
P_0c09a054: /* original 0dc6, guest PC 0x0c09a054 */
if(!s->budget--) { s->failed_pc=0x0c09a054u; return 0; }
write(ram,r[13]+r[0],r[12],4);
goto P_0c09a056;
P_0c09a056: /* original 60c3, guest PC 0x0c09a056 */
if(!s->budget--) { s->failed_pc=0x0c09a056u; return 0; }
r[0]=r[12];
goto P_0c09a058;
P_0c09a058: /* original d439, guest PC 0x0c09a058 */
if(!s->budget--) { s->failed_pc=0x0c09a058u; return 0; }
r[4]=read(ram,0x0c09a140u,4);
goto P_0c09a05a;
P_0c09a05a: /* original 24c0, guest PC 0x0c09a05a */
if(!s->budget--) { s->failed_pc=0x0c09a05au; return 0; }
write(ram,r[4],r[12],1);
goto P_0c09a05c;
P_0c09a05c: /* original 8041, guest PC 0x0c09a05c */
if(!s->budget--) { s->failed_pc=0x0c09a05cu; return 0; }
write(ram,r[4]+1,r[0],1);
goto P_0c09a05e;
P_0c09a05e: /* original 54bb, guest PC 0x0c09a05e */
if(!s->budget--) { s->failed_pc=0x0c09a05eu; return 0; }
r[4]=read(ram,r[11]+44,4);
goto P_0c09a060;
P_0c09a060: /* original 55ba, guest PC 0x0c09a060 */
if(!s->budget--) { s->failed_pc=0x0c09a060u; return 0; }
r[5]=read(ram,r[11]+40,4);
goto P_0c09a062;
P_0c09a062: /* original 2502, guest PC 0x0c09a062 */
if(!s->budget--) { s->failed_pc=0x0c09a062u; return 0; }
write(ram,r[5],r[0],4);
goto P_0c09a064;
P_0c09a064: /* original 2402, guest PC 0x0c09a064 */
if(!s->budget--) { s->failed_pc=0x0c09a064u; return 0; }
write(ram,r[4],r[0],4);
goto P_0c09a066;
P_0c09a066: /* original e06c, guest PC 0x0c09a066 */
if(!s->budget--) { s->failed_pc=0x0c09a066u; return 0; }
r[0]=0x0000006cu;
goto P_0c09a068;
P_0c09a068: /* original 05c6, guest PC 0x0c09a068 */
if(!s->budget--) { s->failed_pc=0x0c09a068u; return 0; }
write(ram,r[5]+r[0],r[12],4);
goto P_0c09a06a;
P_0c09a06a: /* original a002, guest PC 0x0c09a06a */
if(!s->budget--) { s->failed_pc=0x0c09a06au; return 0; }
write(ram,r[4]+r[0],r[12],4);
goto P_0c09a072;
P_0c09a06c: /* original 04c6, guest PC 0x0c09a06c */
if(!s->budget--) { s->failed_pc=0x0c09a06cu; return 0; }
write(ram,r[4]+r[0],r[12],4);
goto P_0c09a06e;
P_0c09a06e: /* original e012, guest PC 0x0c09a06e */
if(!s->budget--) { s->failed_pc=0x0c09a06eu; return 0; }
r[0]=0x00000012u;
goto P_0c09a070;
P_0c09a070: /* original 80da, guest PC 0x0c09a070 */
if(!s->budget--) { s->failed_pc=0x0c09a070u; return 0; }
write(ram,r[13]+10,r[0],1);
goto P_0c09a072;
P_0c09a072: /* original 7f08, guest PC 0x0c09a072 */
if(!s->budget--) { s->failed_pc=0x0c09a072u; return 0; }
r[15]+=0x00000008u;
goto P_0c09a074;
P_0c09a074: /* original 4f26, guest PC 0x0c09a074 */
if(!s->budget--) { s->failed_pc=0x0c09a074u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c09a076;
P_0c09a076: /* original 68f6, guest PC 0x0c09a076 */
if(!s->budget--) { s->failed_pc=0x0c09a076u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c09a078;
P_0c09a078: /* original 69f6, guest PC 0x0c09a078 */
if(!s->budget--) { s->failed_pc=0x0c09a078u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c09a07a;
P_0c09a07a: /* original 6af6, guest PC 0x0c09a07a */
if(!s->budget--) { s->failed_pc=0x0c09a07au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c09a07c;
P_0c09a07c: /* original 6bf6, guest PC 0x0c09a07c */
if(!s->budget--) { s->failed_pc=0x0c09a07cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c09a07e;
P_0c09a07e: /* original 6cf6, guest PC 0x0c09a07e */
if(!s->budget--) { s->failed_pc=0x0c09a07eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c09a080;
P_0c09a080: /* original 6df6, guest PC 0x0c09a080 */
if(!s->budget--) { s->failed_pc=0x0c09a080u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c09a082;
P_0c09a082: /* original 000b, guest PC 0x0c09a082 */
if(!s->budget--) { s->failed_pc=0x0c09a082u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c09a084: /* original 6ef6, guest PC 0x0c09a084 */
if(!s->budget--) { s->failed_pc=0x0c09a084u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c09a086u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c09a086u; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
