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
int vf3_away_batch24_adapter_2(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c07b398u: goto P_0c07b398;
case 0x0c07b39au: goto P_0c07b39a;
case 0x0c07b39cu: goto P_0c07b39c;
case 0x0c07b39eu: goto P_0c07b39e;
case 0x0c07b3a0u: goto P_0c07b3a0;
case 0x0c07b3a2u: goto P_0c07b3a2;
case 0x0c07b3a4u: goto P_0c07b3a4;
case 0x0c07b3a6u: goto P_0c07b3a6;
case 0x0c07b3a8u: goto P_0c07b3a8;
case 0x0c07b3aau: goto P_0c07b3aa;
case 0x0c07b3acu: goto P_0c07b3ac;
case 0x0c07b3aeu: goto P_0c07b3ae;
case 0x0c07b3b0u: goto P_0c07b3b0;
case 0x0c07b3b2u: goto P_0c07b3b2;
case 0x0c07b3b4u: goto P_0c07b3b4;
case 0x0c07b3b6u: goto P_0c07b3b6;
case 0x0c07b3b8u: goto P_0c07b3b8;
case 0x0c07b3bau: goto P_0c07b3ba;
case 0x0c07b3bcu: goto P_0c07b3bc;
case 0x0c07b3beu: goto P_0c07b3be;
case 0x0c07b3c0u: goto P_0c07b3c0;
case 0x0c07b3c2u: goto P_0c07b3c2;
case 0x0c07b3c4u: goto P_0c07b3c4;
case 0x0c07b3c6u: goto P_0c07b3c6;
case 0x0c07b3c8u: goto P_0c07b3c8;
case 0x0c07b3cau: goto P_0c07b3ca;
case 0x0c07b3ccu: goto P_0c07b3cc;
case 0x0c07b3ceu: goto P_0c07b3ce;
case 0x0c07b3d0u: goto P_0c07b3d0;
case 0x0c07b4d4u: goto P_0c07b4d4;
case 0x0c07b4d6u: goto P_0c07b4d6;
case 0x0c07b4d8u: goto P_0c07b4d8;
case 0x0c07b4dau: goto P_0c07b4da;
case 0x0c07b4dcu: goto P_0c07b4dc;
case 0x0c07b4deu: goto P_0c07b4de;
case 0x0c07b4e0u: goto P_0c07b4e0;
case 0x0c07b4e2u: goto P_0c07b4e2;
case 0x0c07b4e4u: goto P_0c07b4e4;
case 0x0c07b4e6u: goto P_0c07b4e6;
case 0x0c07b4e8u: goto P_0c07b4e8;
case 0x0c07b4eau: goto P_0c07b4ea;
case 0x0c07b4ecu: goto P_0c07b4ec;
case 0x0c07b4eeu: goto P_0c07b4ee;
case 0x0c07b4f0u: goto P_0c07b4f0;
case 0x0c07b4f2u: goto P_0c07b4f2;
case 0x0c07b4f4u: goto P_0c07b4f4;
case 0x0c07b4f6u: goto P_0c07b4f6;
case 0x0c07b4f8u: goto P_0c07b4f8;
case 0x0c07b4fau: goto P_0c07b4fa;
case 0x0c07b4fcu: goto P_0c07b4fc;
case 0x0c07b4feu: goto P_0c07b4fe;
case 0x0c07b500u: goto P_0c07b500;
case 0x0c07b502u: goto P_0c07b502;
case 0x0c07b504u: goto P_0c07b504;
case 0x0c07b506u: goto P_0c07b506;
case 0x0c07b508u: goto P_0c07b508;
case 0x0c07b50au: goto P_0c07b50a;
case 0x0c07b50cu: goto P_0c07b50c;
case 0x0c07b50eu: goto P_0c07b50e;
case 0x0c07b510u: goto P_0c07b510;
case 0x0c07b512u: goto P_0c07b512;
case 0x0c07b514u: goto P_0c07b514;
case 0x0c07b516u: goto P_0c07b516;
case 0x0c07b518u: goto P_0c07b518;
case 0x0c07b51au: goto P_0c07b51a;
case 0x0c07b51cu: goto P_0c07b51c;
case 0x0c07b51eu: goto P_0c07b51e;
case 0x0c07b520u: goto P_0c07b520;
case 0x0c07b522u: goto P_0c07b522;
case 0x0c07b524u: goto P_0c07b524;
case 0x0c07b526u: goto P_0c07b526;
case 0x0c07b528u: goto P_0c07b528;
case 0x0c07b52au: goto P_0c07b52a;
case 0x0c07b52cu: goto P_0c07b52c;
case 0x0c07b52eu: goto P_0c07b52e;
case 0x0c07b530u: goto P_0c07b530;
case 0x0c07b532u: goto P_0c07b532;
case 0x0c07b534u: goto P_0c07b534;
case 0x0c07b536u: goto P_0c07b536;
case 0x0c07b538u: goto P_0c07b538;
case 0x0c07b53au: goto P_0c07b53a;
case 0x0c07b53cu: goto P_0c07b53c;
case 0x0c07b53eu: goto P_0c07b53e;
case 0x0c07b540u: goto P_0c07b540;
case 0x0c07b542u: goto P_0c07b542;
case 0x0c07b544u: goto P_0c07b544;
case 0x0c07b546u: goto P_0c07b546;
case 0x0c07b548u: goto P_0c07b548;
case 0x0c07b54au: goto P_0c07b54a;
case 0x0c07b54cu: goto P_0c07b54c;
case 0x0c07b54eu: goto P_0c07b54e;
case 0x0c07b550u: goto P_0c07b550;
case 0x0c07b552u: goto P_0c07b552;
case 0x0c07b554u: goto P_0c07b554;
case 0x0c07b556u: goto P_0c07b556;
case 0x0c07b558u: goto P_0c07b558;
case 0x0c07b55au: goto P_0c07b55a;
case 0x0c07b55cu: goto P_0c07b55c;
case 0x0c07b55eu: goto P_0c07b55e;
case 0x0c07b560u: goto P_0c07b560;
case 0x0c07b562u: goto P_0c07b562;
case 0x0c07b564u: goto P_0c07b564;
case 0x0c07b566u: goto P_0c07b566;
case 0x0c07b568u: goto P_0c07b568;
case 0x0c07b56au: goto P_0c07b56a;
case 0x0c07b56cu: goto P_0c07b56c;
case 0x0c07b56eu: goto P_0c07b56e;
case 0x0c07b570u: goto P_0c07b570;
case 0x0c07b572u: goto P_0c07b572;
case 0x0c07b574u: goto P_0c07b574;
case 0x0c07b576u: goto P_0c07b576;
case 0x0c07b578u: goto P_0c07b578;
case 0x0c07b57au: goto P_0c07b57a;
case 0x0c07b57cu: goto P_0c07b57c;
case 0x0c07b57eu: goto P_0c07b57e;
case 0x0c07b580u: goto P_0c07b580;
case 0x0c07b582u: goto P_0c07b582;
case 0x0c07b584u: goto P_0c07b584;
case 0x0c07b586u: goto P_0c07b586;
case 0x0c07b588u: goto P_0c07b588;
case 0x0c07b58au: goto P_0c07b58a;
case 0x0c07b58cu: goto P_0c07b58c;
case 0x0c07b58eu: goto P_0c07b58e;
case 0x0c07b590u: goto P_0c07b590;
case 0x0c07b592u: goto P_0c07b592;
case 0x0c07b594u: goto P_0c07b594;
case 0x0c07b596u: goto P_0c07b596;
case 0x0c07b598u: goto P_0c07b598;
case 0x0c07b59au: goto P_0c07b59a;
case 0x0c07b59cu: goto P_0c07b59c;
case 0x0c07b59eu: goto P_0c07b59e;
case 0x0c07b5a0u: goto P_0c07b5a0;
case 0x0c07b5a2u: goto P_0c07b5a2;
case 0x0c07b5a4u: goto P_0c07b5a4;
case 0x0c07b5a6u: goto P_0c07b5a6;
case 0x0c07b5a8u: goto P_0c07b5a8;
case 0x0c07b5aau: goto P_0c07b5aa;
case 0x0c07b5acu: goto P_0c07b5ac;
case 0x0c07b5aeu: goto P_0c07b5ae;
case 0x0c0a2e06u: goto P_0c0a2e06;
case 0x0c0a2e08u: goto P_0c0a2e08;
case 0x0c0a2e0au: goto P_0c0a2e0a;
case 0x0c0a2e0cu: goto P_0c0a2e0c;
case 0x0c0a2e0eu: goto P_0c0a2e0e;
case 0x0c0a2e10u: goto P_0c0a2e10;
case 0x0c0a2e12u: goto P_0c0a2e12;
case 0x0c0a2e14u: goto P_0c0a2e14;
case 0x0c0a2e16u: goto P_0c0a2e16;
case 0x0c0a2e18u: goto P_0c0a2e18;
case 0x0c0a2e1au: goto P_0c0a2e1a;
case 0x0c0a2e1cu: goto P_0c0a2e1c;
case 0x0c0a2e1eu: goto P_0c0a2e1e;
case 0x0c0a2e20u: goto P_0c0a2e20;
case 0x0c0a2e22u: goto P_0c0a2e22;
case 0x0c0a2e24u: goto P_0c0a2e24;
case 0x0c0a2e26u: goto P_0c0a2e26;
case 0x0c0a2e28u: goto P_0c0a2e28;
case 0x0c0a2e2au: goto P_0c0a2e2a;
case 0x0c0a7be2u: goto P_0c0a7be2;
case 0x0c0a7be4u: goto P_0c0a7be4;
case 0x0c0a7be6u: goto P_0c0a7be6;
case 0x0c0a7be8u: goto P_0c0a7be8;
case 0x0c0a7beau: goto P_0c0a7bea;
case 0x0c0a7becu: goto P_0c0a7bec;
case 0x0c0a7beeu: goto P_0c0a7bee;
case 0x0c0a7bf0u: goto P_0c0a7bf0;
case 0x0c0a7bf2u: goto P_0c0a7bf2;
case 0x0c0a7bf4u: goto P_0c0a7bf4;
case 0x0c0a7bf6u: goto P_0c0a7bf6;
case 0x0c0a7bf8u: goto P_0c0a7bf8;
case 0x0c0a7bfau: goto P_0c0a7bfa;
case 0x0c0a7bfcu: goto P_0c0a7bfc;
case 0x0c0a7bfeu: goto P_0c0a7bfe;
case 0x0c0a7c00u: goto P_0c0a7c00;
case 0x0c0a7c02u: goto P_0c0a7c02;
case 0x0c0a7c04u: goto P_0c0a7c04;
case 0x0c0a7c1cu: goto P_0c0a7c1c;
case 0x0c0a7c1eu: goto P_0c0a7c1e;
case 0x0c0a7c20u: goto P_0c0a7c20;
case 0x0c0a7c22u: goto P_0c0a7c22;
case 0x0c0a7c24u: goto P_0c0a7c24;
case 0x0c0a7c26u: goto P_0c0a7c26;
case 0x0c0a7c28u: goto P_0c0a7c28;
case 0x0c0a7c2au: goto P_0c0a7c2a;
case 0x0c0a7c2cu: goto P_0c0a7c2c;
case 0x0c0a7c2eu: goto P_0c0a7c2e;
case 0x0c0a7c30u: goto P_0c0a7c30;
case 0x0c0a7c32u: goto P_0c0a7c32;
case 0x0c0a7c34u: goto P_0c0a7c34;
case 0x0c0a7c36u: goto P_0c0a7c36;
case 0x0c0a7c38u: goto P_0c0a7c38;
case 0x0c0a7c3au: goto P_0c0a7c3a;
case 0x0c0a7c3cu: goto P_0c0a7c3c;
case 0x0c0a7c3eu: goto P_0c0a7c3e;
case 0x0c0a7c40u: goto P_0c0a7c40;
case 0x0c0a7c42u: goto P_0c0a7c42;
case 0x0c0a7c44u: goto P_0c0a7c44;
case 0x0c0a7c46u: goto P_0c0a7c46;
case 0x0c0a7c48u: goto P_0c0a7c48;
case 0x0c0a7c4au: goto P_0c0a7c4a;
case 0x0c0a7c4cu: goto P_0c0a7c4c;
case 0x0c0a7c4eu: goto P_0c0a7c4e;
case 0x0c0a7c50u: goto P_0c0a7c50;
case 0x0c0a7c52u: goto P_0c0a7c52;
case 0x0c0a7c54u: goto P_0c0a7c54;
case 0x0c0a7c56u: goto P_0c0a7c56;
case 0x0c0a7c58u: goto P_0c0a7c58;
case 0x0c0a7c5au: goto P_0c0a7c5a;
case 0x0c0a7c5cu: goto P_0c0a7c5c;
case 0x0c0a7c5eu: goto P_0c0a7c5e;
case 0x0c0a7c60u: goto P_0c0a7c60;
case 0x0c0a7c62u: goto P_0c0a7c62;
case 0x0c0a7c64u: goto P_0c0a7c64;
case 0x0c0a7c66u: goto P_0c0a7c66;
case 0x0c0a7c68u: goto P_0c0a7c68;
case 0x0c0a7c6au: goto P_0c0a7c6a;
case 0x0c0a7c6cu: goto P_0c0a7c6c;
case 0x0c0a7c6eu: goto P_0c0a7c6e;
case 0x0c0a7c70u: goto P_0c0a7c70;
case 0x0c0a7c72u: goto P_0c0a7c72;
case 0x0c0a7c74u: goto P_0c0a7c74;
case 0x0c0a7c76u: goto P_0c0a7c76;
case 0x0c0a7c78u: goto P_0c0a7c78;
case 0x0c0a7c7au: goto P_0c0a7c7a;
case 0x0c0a7c7cu: goto P_0c0a7c7c;
case 0x0c0a7c7eu: goto P_0c0a7c7e;
case 0x0c0a7c80u: goto P_0c0a7c80;
case 0x0c0a7c82u: goto P_0c0a7c82;
case 0x0c0a7c84u: goto P_0c0a7c84;
case 0x0c0a7c86u: goto P_0c0a7c86;
case 0x0c0a7c88u: goto P_0c0a7c88;
case 0x0c0a7c8au: goto P_0c0a7c8a;
case 0x0c0a7c8cu: goto P_0c0a7c8c;
case 0x0c0a7c8eu: goto P_0c0a7c8e;
case 0x0c0a7c90u: goto P_0c0a7c90;
case 0x0c0a7c92u: goto P_0c0a7c92;
case 0x0c0a7c94u: goto P_0c0a7c94;
case 0x0c0a7c96u: goto P_0c0a7c96;
case 0x0c0a7c98u: goto P_0c0a7c98;
case 0x0c0a7c9au: goto P_0c0a7c9a;
case 0x0c0a7c9cu: goto P_0c0a7c9c;
case 0x0c0a7c9eu: goto P_0c0a7c9e;
case 0x0c0a7ca0u: goto P_0c0a7ca0;
case 0x0c0a7ca2u: goto P_0c0a7ca2;
case 0x0c0a7ca4u: goto P_0c0a7ca4;
case 0x0c0a7ca6u: goto P_0c0a7ca6;
case 0x0c0a7ca8u: goto P_0c0a7ca8;
case 0x0c0a7caau: goto P_0c0a7caa;
case 0x0c0a7cacu: goto P_0c0a7cac;
case 0x0c0a7caeu: goto P_0c0a7cae;
case 0x0c0a7cb0u: goto P_0c0a7cb0;
case 0x0c0a7cb2u: goto P_0c0a7cb2;
case 0x0c0a7cb4u: goto P_0c0a7cb4;
case 0x0c0a7cb6u: goto P_0c0a7cb6;
case 0x0c0a7cb8u: goto P_0c0a7cb8;
case 0x0c0a7cbau: goto P_0c0a7cba;
case 0x0c0a7cbcu: goto P_0c0a7cbc;
case 0x0c0a7cbeu: goto P_0c0a7cbe;
case 0x0c0a7cc0u: goto P_0c0a7cc0;
case 0x0c0a7cc2u: goto P_0c0a7cc2;
case 0x0c0a7cc4u: goto P_0c0a7cc4;
case 0x0c0a7cc6u: goto P_0c0a7cc6;
case 0x0c0a7cc8u: goto P_0c0a7cc8;
case 0x0c0a7ccau: goto P_0c0a7cca;
case 0x0c0a7cccu: goto P_0c0a7ccc;
case 0x0c0a7cceu: goto P_0c0a7cce;
case 0x0c0a7cd0u: goto P_0c0a7cd0;
case 0x0c0a7cd2u: goto P_0c0a7cd2;
case 0x0c0a7cd4u: goto P_0c0a7cd4;
case 0x0c0a7cd6u: goto P_0c0a7cd6;
case 0x0c0a7cd8u: goto P_0c0a7cd8;
case 0x0c0a7cdau: goto P_0c0a7cda;
case 0x0c0a7cdcu: goto P_0c0a7cdc;
case 0x0c0a7cdeu: goto P_0c0a7cde;
case 0x0c0a7ce0u: goto P_0c0a7ce0;
case 0x0c0a7ce2u: goto P_0c0a7ce2;
case 0x0c0a7ce4u: goto P_0c0a7ce4;
case 0x0c0a7ce6u: goto P_0c0a7ce6;
case 0x0c0a7ce8u: goto P_0c0a7ce8;
case 0x0c0a7ceau: goto P_0c0a7cea;
case 0x0c0a7cecu: goto P_0c0a7cec;
case 0x0c0a7ceeu: goto P_0c0a7cee;
case 0x0c0a7cf0u: goto P_0c0a7cf0;
case 0x0c0a7cf2u: goto P_0c0a7cf2;
case 0x0c0a7cf4u: goto P_0c0a7cf4;
case 0x0c0a7cf6u: goto P_0c0a7cf6;
case 0x0c0a7cf8u: goto P_0c0a7cf8;
case 0x0c0a7cfau: goto P_0c0a7cfa;
case 0x0c0a7cfcu: goto P_0c0a7cfc;
case 0x0c0a7cfeu: goto P_0c0a7cfe;
case 0x0c0a7d00u: goto P_0c0a7d00;
case 0x0c0a7d02u: goto P_0c0a7d02;
case 0x0c0a7d04u: goto P_0c0a7d04;
case 0x0c0a7d06u: goto P_0c0a7d06;
case 0x0c0a7d08u: goto P_0c0a7d08;
case 0x0c0a7d0au: goto P_0c0a7d0a;
case 0x0c0a7d0cu: goto P_0c0a7d0c;
case 0x0c0a7d0eu: goto P_0c0a7d0e;
case 0x0c0a7d10u: goto P_0c0a7d10;
case 0x0c0a7d12u: goto P_0c0a7d12;
case 0x0c0a7d14u: goto P_0c0a7d14;
case 0x0c0a7d16u: goto P_0c0a7d16;
case 0x0c0a7d18u: goto P_0c0a7d18;
case 0x0c0a7d1au: goto P_0c0a7d1a;
case 0x0c0a7d1cu: goto P_0c0a7d1c;
case 0x0c0a7d1eu: goto P_0c0a7d1e;
case 0x0c0a7d5cu: goto P_0c0a7d5c;
case 0x0c0a7d5eu: goto P_0c0a7d5e;
case 0x0c0a7d60u: goto P_0c0a7d60;
case 0x0c0a7d62u: goto P_0c0a7d62;
case 0x0c0a7d64u: goto P_0c0a7d64;
case 0x0c0a7d66u: goto P_0c0a7d66;
case 0x0c0a7d68u: goto P_0c0a7d68;
case 0x0c0a7d6au: goto P_0c0a7d6a;
case 0x0c0a7d6cu: goto P_0c0a7d6c;
case 0x0c0a7d6eu: goto P_0c0a7d6e;
case 0x0c0a7d70u: goto P_0c0a7d70;
case 0x0c0a7d72u: goto P_0c0a7d72;
case 0x0c0a7d74u: goto P_0c0a7d74;
case 0x0c0a7d76u: goto P_0c0a7d76;
case 0x0c0a7d78u: goto P_0c0a7d78;
case 0x0c0a7d7au: goto P_0c0a7d7a;
case 0x0c0a7d7cu: goto P_0c0a7d7c;
case 0x0c0a7d7eu: goto P_0c0a7d7e;
case 0x0c0a7d80u: goto P_0c0a7d80;
case 0x0c0a7d82u: goto P_0c0a7d82;
case 0x0c0a7d84u: goto P_0c0a7d84;
case 0x0c0a7d86u: goto P_0c0a7d86;
case 0x0c0a7d88u: goto P_0c0a7d88;
case 0x0c0a7d8au: goto P_0c0a7d8a;
case 0x0c0a7d8cu: goto P_0c0a7d8c;
case 0x0c0a7d8eu: goto P_0c0a7d8e;
case 0x0c0a7d90u: goto P_0c0a7d90;
case 0x0c0a7d92u: goto P_0c0a7d92;
case 0x0c0a7d94u: goto P_0c0a7d94;
case 0x0c0a7d96u: goto P_0c0a7d96;
case 0x0c0a7d98u: goto P_0c0a7d98;
case 0x0c0a7d9au: goto P_0c0a7d9a;
case 0x0c0a7d9cu: goto P_0c0a7d9c;
case 0x0c0a7d9eu: goto P_0c0a7d9e;
case 0x0c0a7da0u: goto P_0c0a7da0;
case 0x0c0a7da2u: goto P_0c0a7da2;
case 0x0c0a7da4u: goto P_0c0a7da4;
case 0x0c0a7da6u: goto P_0c0a7da6;
case 0x0c0a7da8u: goto P_0c0a7da8;
case 0x0c0a7daau: goto P_0c0a7daa;
case 0x0c0a7dacu: goto P_0c0a7dac;
case 0x0c0a7daeu: goto P_0c0a7dae;
case 0x0c0a7db0u: goto P_0c0a7db0;
case 0x0c0a7db2u: goto P_0c0a7db2;
case 0x0c0a7db4u: goto P_0c0a7db4;
case 0x0c0a7db6u: goto P_0c0a7db6;
case 0x0c0a7db8u: goto P_0c0a7db8;
case 0x0c0a7dbau: goto P_0c0a7dba;
case 0x0c0a7dbcu: goto P_0c0a7dbc;
case 0x0c0a7dbeu: goto P_0c0a7dbe;
case 0x0c0a7dc0u: goto P_0c0a7dc0;
case 0x0c0a7dc2u: goto P_0c0a7dc2;
case 0x0c0a7dc4u: goto P_0c0a7dc4;
case 0x0c0a7dc6u: goto P_0c0a7dc6;
case 0x0c0a7dc8u: goto P_0c0a7dc8;
case 0x0c0a7dcau: goto P_0c0a7dca;
case 0x0c0a7dccu: goto P_0c0a7dcc;
case 0x0c0a7dceu: goto P_0c0a7dce;
case 0x0c0a7dd0u: goto P_0c0a7dd0;
case 0x0c0a7dd2u: goto P_0c0a7dd2;
case 0x0c0a7dd4u: goto P_0c0a7dd4;
case 0x0c0a7dd6u: goto P_0c0a7dd6;
case 0x0c0a7dd8u: goto P_0c0a7dd8;
case 0x0c0a7ddau: goto P_0c0a7dda;
case 0x0c0a7ddcu: goto P_0c0a7ddc;
case 0x0c0a7ddeu: goto P_0c0a7dde;
case 0x0c0a7de0u: goto P_0c0a7de0;
case 0x0c0a7de2u: goto P_0c0a7de2;
case 0x0c0a7de4u: goto P_0c0a7de4;
case 0x0c0a7de6u: goto P_0c0a7de6;
case 0x0c0a7de8u: goto P_0c0a7de8;
case 0x0c0a7deau: goto P_0c0a7dea;
case 0x0c0a7decu: goto P_0c0a7dec;
case 0x0c0a7deeu: goto P_0c0a7dee;
case 0x0c0a7df0u: goto P_0c0a7df0;
case 0x0c0a7df2u: goto P_0c0a7df2;
case 0x0c0a7df4u: goto P_0c0a7df4;
case 0x0c0a7df6u: goto P_0c0a7df6;
case 0x0c0a7df8u: goto P_0c0a7df8;
case 0x0c0a7dfau: goto P_0c0a7dfa;
case 0x0c0a7dfcu: goto P_0c0a7dfc;
case 0x0c0a7dfeu: goto P_0c0a7dfe;
case 0x0c0a7e00u: goto P_0c0a7e00;
case 0x0c0a7e02u: goto P_0c0a7e02;
case 0x0c0a7e04u: goto P_0c0a7e04;
case 0x0c0a7e06u: goto P_0c0a7e06;
case 0x0c0a7e08u: goto P_0c0a7e08;
case 0x0c0a7e0au: goto P_0c0a7e0a;
case 0x0c0a7e0cu: goto P_0c0a7e0c;
case 0x0c0a7e0eu: goto P_0c0a7e0e;
case 0x0c0a7e10u: goto P_0c0a7e10;
case 0x0c0a7e12u: goto P_0c0a7e12;
case 0x0c0a7e14u: goto P_0c0a7e14;
case 0x0c0a7e16u: goto P_0c0a7e16;
case 0x0c0a7e18u: goto P_0c0a7e18;
case 0x0c0a7e1au: goto P_0c0a7e1a;
case 0x0c0a7e1cu: goto P_0c0a7e1c;
case 0x0c0a7e1eu: goto P_0c0a7e1e;
case 0x0c0a7e20u: goto P_0c0a7e20;
case 0x0c0a7e22u: goto P_0c0a7e22;
case 0x0c0a7e24u: goto P_0c0a7e24;
case 0x0c0a7e26u: goto P_0c0a7e26;
case 0x0c0a7e28u: goto P_0c0a7e28;
case 0x0c0a7e2au: goto P_0c0a7e2a;
case 0x0c0a7e2cu: goto P_0c0a7e2c;
case 0x0c0a7e2eu: goto P_0c0a7e2e;
case 0x0c0a7e30u: goto P_0c0a7e30;
case 0x0c0a7e32u: goto P_0c0a7e32;
case 0x0c0a7e34u: goto P_0c0a7e34;
case 0x0c0a7e36u: goto P_0c0a7e36;
case 0x0c0a7e38u: goto P_0c0a7e38;
case 0x0c0a7e3au: goto P_0c0a7e3a;
case 0x0c0a7e3cu: goto P_0c0a7e3c;
default: return vf3_matrix_family(target,s,ram);
}
P_0c07b398: /* original c748, guest PC 0x0c07b398 */
if(!s->budget--) { s->failed_pc=0x0c07b398u; return 0; }
r[0]=code_base|0x0007b4bcu;
goto P_0c07b39a;
P_0c07b39a: /* original f24c, guest PC 0x0c07b39a */
if(!s->budget--) { s->failed_pc=0x0c07b39au; return 0; }
vf3_matrix_move(s,2,4);
goto P_0c07b39c;
P_0c07b39c: /* original f308, guest PC 0x0c07b39c */
if(!s->budget--) { s->failed_pc=0x0c07b39cu; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c07b39e;
P_0c07b39e: /* original e018, guest PC 0x0c07b39e */
if(!s->budget--) { s->failed_pc=0x0c07b39eu; return 0; }
r[0]=0x00000018u;
goto P_0c07b3a0;
P_0c07b3a0: /* original f460, guest PC 0x0c07b3a0 */
if(!s->budget--) { s->failed_pc=0x0c07b3a0u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[6],r[18],'+');
goto P_0c07b3a2;
P_0c07b3a2: /* original f230, guest PC 0x0c07b3a2 */
if(!s->budget--) { s->failed_pc=0x0c07b3a2u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'+');
goto P_0c07b3a4;
P_0c07b3a4: /* original f282, guest PC 0x0c07b3a4 */
if(!s->budget--) { s->failed_pc=0x0c07b3a4u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[8],r[18],'*');
goto P_0c07b3a6;
P_0c07b3a6: /* original f427, guest PC 0x0c07b3a6 */
if(!s->budget--) { s->failed_pc=0x0c07b3a6u; return 0; }
vf3_matrix_store(s,ram,2,r[4]+r[0]);
goto P_0c07b3a8;
P_0c07b3a8: /* original c745, guest PC 0x0c07b3a8 */
if(!s->budget--) { s->failed_pc=0x0c07b3a8u; return 0; }
r[0]=code_base|0x0007b4c0u;
goto P_0c07b3aa;
P_0c07b3aa: /* original f208, guest PC 0x0c07b3aa */
if(!s->budget--) { s->failed_pc=0x0c07b3aau; return 0; }
vf3_matrix_load(s,ram,2,r[0]);
goto P_0c07b3ac;
P_0c07b3ac: /* original e01c, guest PC 0x0c07b3ac */
if(!s->budget--) { s->failed_pc=0x0c07b3acu; return 0; }
r[0]=0x0000001cu;
goto P_0c07b3ae;
P_0c07b3ae: /* original f15c, guest PC 0x0c07b3ae */
if(!s->budget--) { s->failed_pc=0x0c07b3aeu; return 0; }
vf3_matrix_move(s,1,5);
goto P_0c07b3b0;
P_0c07b3b0: /* original f570, guest PC 0x0c07b3b0 */
if(!s->budget--) { s->failed_pc=0x0c07b3b0u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[7],r[18],'+');
goto P_0c07b3b2;
P_0c07b3b2: /* original f120, guest PC 0x0c07b3b2 */
if(!s->budget--) { s->failed_pc=0x0c07b3b2u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[2],r[18],'+');
goto P_0c07b3b4;
P_0c07b3b4: /* original f192, guest PC 0x0c07b3b4 */
if(!s->budget--) { s->failed_pc=0x0c07b3b4u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[9],r[18],'*');
goto P_0c07b3b6;
P_0c07b3b6: /* original f417, guest PC 0x0c07b3b6 */
if(!s->budget--) { s->failed_pc=0x0c07b3b6u; return 0; }
vf3_matrix_store(s,ram,1,r[4]+r[0]);
goto P_0c07b3b8;
P_0c07b3b8: /* original c742, guest PC 0x0c07b3b8 */
if(!s->budget--) { s->failed_pc=0x0c07b3b8u; return 0; }
r[0]=code_base|0x0007b4c4u;
goto P_0c07b3ba;
P_0c07b3ba: /* original f108, guest PC 0x0c07b3ba */
if(!s->budget--) { s->failed_pc=0x0c07b3bau; return 0; }
vf3_matrix_load(s,ram,1,r[0]);
goto P_0c07b3bc;
P_0c07b3bc: /* original e020, guest PC 0x0c07b3bc */
if(!s->budget--) { s->failed_pc=0x0c07b3bcu; return 0; }
r[0]=0x00000020u;
goto P_0c07b3be;
P_0c07b3be: /* original f410, guest PC 0x0c07b3be */
if(!s->budget--) { s->failed_pc=0x0c07b3beu; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[1],r[18],'+');
goto P_0c07b3c0;
P_0c07b3c0: /* original f482, guest PC 0x0c07b3c0 */
if(!s->budget--) { s->failed_pc=0x0c07b3c0u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[8],r[18],'*');
goto P_0c07b3c2;
P_0c07b3c2: /* original f447, guest PC 0x0c07b3c2 */
if(!s->budget--) { s->failed_pc=0x0c07b3c2u; return 0; }
vf3_matrix_store(s,ram,4,r[4]+r[0]);
goto P_0c07b3c4;
P_0c07b3c4: /* original c740, guest PC 0x0c07b3c4 */
if(!s->budget--) { s->failed_pc=0x0c07b3c4u; return 0; }
r[0]=code_base|0x0007b4c8u;
goto P_0c07b3c6;
P_0c07b3c6: /* original f308, guest PC 0x0c07b3c6 */
if(!s->budget--) { s->failed_pc=0x0c07b3c6u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c07b3c8;
P_0c07b3c8: /* original e024, guest PC 0x0c07b3c8 */
if(!s->budget--) { s->failed_pc=0x0c07b3c8u; return 0; }
r[0]=0x00000024u;
goto P_0c07b3ca;
P_0c07b3ca: /* original f530, guest PC 0x0c07b3ca */
if(!s->budget--) { s->failed_pc=0x0c07b3cau; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[3],r[18],'+');
goto P_0c07b3cc;
P_0c07b3cc: /* original f592, guest PC 0x0c07b3cc */
if(!s->budget--) { s->failed_pc=0x0c07b3ccu; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[9],r[18],'*');
goto P_0c07b3ce;
P_0c07b3ce: /* original 000b, guest PC 0x0c07b3ce */
if(!s->budget--) { s->failed_pc=0x0c07b3ceu; return 0; }
target=r[16];
vf3_matrix_store(s,ram,5,r[4]+r[0]);
s->pc=target; return ram->oob==0;
P_0c07b3d0: /* original f457, guest PC 0x0c07b3d0 */
if(!s->budget--) { s->failed_pc=0x0c07b3d0u; return 0; }
vf3_matrix_store(s,ram,5,r[4]+r[0]);
if(!vf3_matrix_family(0x0c07b3d2u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c07b3d2u; return 0; } return 1;
P_0c07b4d4: /* original 654d, guest PC 0x0c07b4d4 */
if(!s->budget--) { s->failed_pc=0x0c07b4d4u; return 0; }
r[5]=r[4]&65535u;
goto P_0c07b4d6;
P_0c07b4d6: /* original 2fe6, guest PC 0x0c07b4d6 */
if(!s->budget--) { s->failed_pc=0x0c07b4d6u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07b4d8;
P_0c07b4d8: /* original 2fd6, guest PC 0x0c07b4d8 */
if(!s->budget--) { s->failed_pc=0x0c07b4d8u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07b4da;
P_0c07b4da: /* original 9378, guest PC 0x0c07b4da */
if(!s->budget--) { s->failed_pc=0x0c07b4dau; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07b5ceu,2);
goto P_0c07b4dc;
P_0c07b4dc: /* original 2358, guest PC 0x0c07b4dc */
if(!s->budget--) { s->failed_pc=0x0c07b4dcu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[5])==0)!=0);
goto P_0c07b4de;
P_0c07b4de: /* original 8912, guest PC 0x0c07b4de */
if(!s->budget--) { s->failed_pc=0x0c07b4deu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07b506; }
goto P_0c07b4e0;
P_0c07b4e0: /* original 9476, guest PC 0x0c07b4e0 */
if(!s->budget--) { s->failed_pc=0x0c07b4e0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07b5d0u,2);
goto P_0c07b4e2;
P_0c07b4e2: /* original d23c, guest PC 0x0c07b4e2 */
if(!s->budget--) { s->failed_pc=0x0c07b4e2u; return 0; }
r[2]=read(ram,0x0c07b5d4u,4);
goto P_0c07b4e4;
P_0c07b4e4: /* original 2459, guest PC 0x0c07b4e4 */
if(!s->budget--) { s->failed_pc=0x0c07b4e4u; return 0; }
r[4]&=r[5];
goto P_0c07b4e6;
P_0c07b4e6: /* original 6343, guest PC 0x0c07b4e6 */
if(!s->budget--) { s->failed_pc=0x0c07b4e6u; return 0; }
r[3]=r[4];
goto P_0c07b4e8;
P_0c07b4e8: /* original 6543, guest PC 0x0c07b4e8 */
if(!s->budget--) { s->failed_pc=0x0c07b4e8u; return 0; }
r[5]=r[4];
goto P_0c07b4ea;
P_0c07b4ea: /* original 4308, guest PC 0x0c07b4ea */
if(!s->budget--) { s->failed_pc=0x0c07b4eau; return 0; }
r[3]<<=2;
goto P_0c07b4ec;
P_0c07b4ec: /* original 4500, guest PC 0x0c07b4ec */
if(!s->budget--) { s->failed_pc=0x0c07b4ecu; return 0; }
r[17]=(r[17]&~1u)|((r[5]>>31)!=0);
r[5]<<=1;
goto P_0c07b4ee;
P_0c07b4ee: /* original 353c, guest PC 0x0c07b4ee */
if(!s->budget--) { s->failed_pc=0x0c07b4eeu; return 0; }
r[5]+=r[3];
goto P_0c07b4f0;
P_0c07b4f0: /* original 352c, guest PC 0x0c07b4f0 */
if(!s->budget--) { s->failed_pc=0x0c07b4f0u; return 0; }
r[5]+=r[2];
goto P_0c07b4f2;
P_0c07b4f2: /* original 8452, guest PC 0x0c07b4f2 */
if(!s->budget--) { s->failed_pc=0x0c07b4f2u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[5]+2,1);
goto P_0c07b4f4;
P_0c07b4f4: /* original 6451, guest PC 0x0c07b4f4 */
if(!s->budget--) { s->failed_pc=0x0c07b4f4u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[5],2);
r[4]=tmp;
goto P_0c07b4f6;
P_0c07b4f6: /* original 660c, guest PC 0x0c07b4f6 */
if(!s->budget--) { s->failed_pc=0x0c07b4f6u; return 0; }
r[6]=r[0]&255u;
goto P_0c07b4f8;
P_0c07b4f8: /* original 8453, guest PC 0x0c07b4f8 */
if(!s->budget--) { s->failed_pc=0x0c07b4f8u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[5]+3,1);
goto P_0c07b4fa;
P_0c07b4fa: /* original 670c, guest PC 0x0c07b4fa */
if(!s->budget--) { s->failed_pc=0x0c07b4fau; return 0; }
r[7]=r[0]&255u;
goto P_0c07b4fc;
P_0c07b4fc: /* original 8454, guest PC 0x0c07b4fc */
if(!s->budget--) { s->failed_pc=0x0c07b4fcu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[5]+4,1);
goto P_0c07b4fe;
P_0c07b4fe: /* original 6e0c, guest PC 0x0c07b4fe */
if(!s->budget--) { s->failed_pc=0x0c07b4feu; return 0; }
r[14]=r[0]&255u;
goto P_0c07b500;
P_0c07b500: /* original 8455, guest PC 0x0c07b500 */
if(!s->budget--) { s->failed_pc=0x0c07b500u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[5]+5,1);
goto P_0c07b502;
P_0c07b502: /* original a00a, guest PC 0x0c07b502 */
if(!s->budget--) { s->failed_pc=0x0c07b502u; return 0; }
r[13]=r[0]&255u;
goto P_0c07b51a;
P_0c07b504: /* original 6d0c, guest PC 0x0c07b504 */
if(!s->budget--) { s->failed_pc=0x0c07b504u; return 0; }
r[13]=r[0]&255u;
goto P_0c07b506;
P_0c07b506: /* original e500, guest PC 0x0c07b506 */
if(!s->budget--) { s->failed_pc=0x0c07b506u; return 0; }
r[5]=0x00000000u;
goto P_0c07b508;
P_0c07b508: /* original d333, guest PC 0x0c07b508 */
if(!s->budget--) { s->failed_pc=0x0c07b508u; return 0; }
r[3]=read(ram,0x0c07b5d8u,4);
goto P_0c07b50a;
P_0c07b50a: /* original 6753, guest PC 0x0c07b50a */
if(!s->budget--) { s->failed_pc=0x0c07b50au; return 0; }
r[7]=r[5];
goto P_0c07b50c;
P_0c07b50c: /* original 6653, guest PC 0x0c07b50c */
if(!s->budget--) { s->failed_pc=0x0c07b50cu; return 0; }
r[6]=r[5];
goto P_0c07b50e;
P_0c07b50e: /* original 654d, guest PC 0x0c07b50e */
if(!s->budget--) { s->failed_pc=0x0c07b50eu; return 0; }
r[5]=r[4]&65535u;
goto P_0c07b510;
P_0c07b510: /* original 4508, guest PC 0x0c07b510 */
if(!s->budget--) { s->failed_pc=0x0c07b510u; return 0; }
r[5]<<=2;
goto P_0c07b512;
P_0c07b512: /* original 353c, guest PC 0x0c07b512 */
if(!s->budget--) { s->failed_pc=0x0c07b512u; return 0; }
r[5]+=r[3];
goto P_0c07b514;
P_0c07b514: /* original 8551, guest PC 0x0c07b514 */
if(!s->budget--) { s->failed_pc=0x0c07b514u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[5]+2,2);
goto P_0c07b516;
P_0c07b516: /* original 6e51, guest PC 0x0c07b516 */
if(!s->budget--) { s->failed_pc=0x0c07b516u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[5],2);
r[14]=tmp;
goto P_0c07b518;
P_0c07b518: /* original 6d03, guest PC 0x0c07b518 */
if(!s->budget--) { s->failed_pc=0x0c07b518u; return 0; }
r[13]=r[0];
goto P_0c07b51a;
P_0c07b51a: /* original 666d, guest PC 0x0c07b51a */
if(!s->budget--) { s->failed_pc=0x0c07b51au; return 0; }
r[6]=r[6]&65535u;
goto P_0c07b51c;
P_0c07b51c: /* original d22f, guest PC 0x0c07b51c */
if(!s->budget--) { s->failed_pc=0x0c07b51cu; return 0; }
r[2]=read(ram,0x0c07b5dcu,4);
goto P_0c07b51e;
P_0c07b51e: /* original 4608, guest PC 0x0c07b51e */
if(!s->budget--) { s->failed_pc=0x0c07b51eu; return 0; }
r[6]<<=2;
goto P_0c07b520;
P_0c07b520: /* original 4600, guest PC 0x0c07b520 */
if(!s->budget--) { s->failed_pc=0x0c07b520u; return 0; }
r[17]=(r[17]&~1u)|((r[6]>>31)!=0);
r[6]<<=1;
goto P_0c07b522;
P_0c07b522: /* original 677d, guest PC 0x0c07b522 */
if(!s->budget--) { s->failed_pc=0x0c07b522u; return 0; }
r[7]=r[7]&65535u;
goto P_0c07b524;
P_0c07b524: /* original 4708, guest PC 0x0c07b524 */
if(!s->budget--) { s->failed_pc=0x0c07b524u; return 0; }
r[7]<<=2;
goto P_0c07b526;
P_0c07b526: /* original 634d, guest PC 0x0c07b526 */
if(!s->budget--) { s->failed_pc=0x0c07b526u; return 0; }
r[3]=r[4]&65535u;
goto P_0c07b528;
P_0c07b528: /* original 2232, guest PC 0x0c07b528 */
if(!s->budget--) { s->failed_pc=0x0c07b528u; return 0; }
write(ram,r[2],r[3],4);
goto P_0c07b52a;
P_0c07b52a: /* original 4700, guest PC 0x0c07b52a */
if(!s->budget--) { s->failed_pc=0x0c07b52au; return 0; }
r[17]=(r[17]&~1u)|((r[7]>>31)!=0);
r[7]<<=1;
goto P_0c07b52c;
P_0c07b52c: /* original 465a, guest PC 0x0c07b52c */
if(!s->budget--) { s->failed_pc=0x0c07b52cu; return 0; }
r[53]=r[6];
goto P_0c07b52e;
P_0c07b52e: /* original 6eed, guest PC 0x0c07b52e */
if(!s->budget--) { s->failed_pc=0x0c07b52eu; return 0; }
r[14]=r[14]&65535u;
goto P_0c07b530;
P_0c07b530: /* original d32b, guest PC 0x0c07b530 */
if(!s->budget--) { s->failed_pc=0x0c07b530u; return 0; }
r[3]=read(ram,0x0c07b5e0u,4);
goto P_0c07b532;
P_0c07b532: /* original 4e08, guest PC 0x0c07b532 */
if(!s->budget--) { s->failed_pc=0x0c07b532u; return 0; }
r[14]<<=2;
goto P_0c07b534;
P_0c07b534: /* original 4e00, guest PC 0x0c07b534 */
if(!s->budget--) { s->failed_pc=0x0c07b534u; return 0; }
r[17]=(r[17]&~1u)|((r[14]>>31)!=0);
r[14]<<=1;
goto P_0c07b536;
P_0c07b536: /* original f32d, guest PC 0x0c07b536 */
if(!s->budget--) { s->failed_pc=0x0c07b536u; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c07b538;
P_0c07b538: /* original 6ddd, guest PC 0x0c07b538 */
if(!s->budget--) { s->failed_pc=0x0c07b538u; return 0; }
r[13]=r[13]&65535u;
goto P_0c07b53a;
P_0c07b53a: /* original 4d08, guest PC 0x0c07b53a */
if(!s->budget--) { s->failed_pc=0x0c07b53au; return 0; }
r[13]<<=2;
goto P_0c07b53c;
P_0c07b53c: /* original 4d00, guest PC 0x0c07b53c */
if(!s->budget--) { s->failed_pc=0x0c07b53cu; return 0; }
r[17]=(r[17]&~1u)|((r[13]>>31)!=0);
r[13]<<=1;
goto P_0c07b53e;
P_0c07b53e: /* original 72e8, guest PC 0x0c07b53e */
if(!s->budget--) { s->failed_pc=0x0c07b53eu; return 0; }
r[2]+=0xffffffe8u;
goto P_0c07b540;
P_0c07b540: /* original 654d, guest PC 0x0c07b540 */
if(!s->budget--) { s->failed_pc=0x0c07b540u; return 0; }
r[5]=r[4]&65535u;
goto P_0c07b542;
P_0c07b542: /* original f33a, guest PC 0x0c07b542 */
if(!s->budget--) { s->failed_pc=0x0c07b542u; return 0; }
vf3_matrix_store(s,ram,3,r[3]);
goto P_0c07b544;
P_0c07b544: /* original 730c, guest PC 0x0c07b544 */
if(!s->budget--) { s->failed_pc=0x0c07b544u; return 0; }
r[3]+=0x0000000cu;
goto P_0c07b546;
P_0c07b546: /* original 475a, guest PC 0x0c07b546 */
if(!s->budget--) { s->failed_pc=0x0c07b546u; return 0; }
r[53]=r[7];
goto P_0c07b548;
P_0c07b548: /* original d126, guest PC 0x0c07b548 */
if(!s->budget--) { s->failed_pc=0x0c07b548u; return 0; }
r[1]=read(ram,0x0c07b5e4u,4);
goto P_0c07b54a;
P_0c07b54a: /* original f32d, guest PC 0x0c07b54a */
if(!s->budget--) { s->failed_pc=0x0c07b54au; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c07b54c;
P_0c07b54c: /* original f13a, guest PC 0x0c07b54c */
if(!s->budget--) { s->failed_pc=0x0c07b54cu; return 0; }
vf3_matrix_store(s,ram,3,r[1]);
goto P_0c07b54e;
P_0c07b54e: /* original 4e5a, guest PC 0x0c07b54e */
if(!s->budget--) { s->failed_pc=0x0c07b54eu; return 0; }
r[53]=r[14];
goto P_0c07b550;
P_0c07b550: /* original f32d, guest PC 0x0c07b550 */
if(!s->budget--) { s->failed_pc=0x0c07b550u; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c07b552;
P_0c07b552: /* original f23a, guest PC 0x0c07b552 */
if(!s->budget--) { s->failed_pc=0x0c07b552u; return 0; }
vf3_matrix_store(s,ram,3,r[2]);
goto P_0c07b554;
P_0c07b554: /* original 4d5a, guest PC 0x0c07b554 */
if(!s->budget--) { s->failed_pc=0x0c07b554u; return 0; }
r[53]=r[13];
goto P_0c07b556;
P_0c07b556: /* original f32d, guest PC 0x0c07b556 */
if(!s->budget--) { s->failed_pc=0x0c07b556u; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c07b558;
P_0c07b558: /* original f33a, guest PC 0x0c07b558 */
if(!s->budget--) { s->failed_pc=0x0c07b558u; return 0; }
vf3_matrix_store(s,ram,3,r[3]);
goto P_0c07b55a;
P_0c07b55a: /* original d11f, guest PC 0x0c07b55a */
if(!s->budget--) { s->failed_pc=0x0c07b55au; return 0; }
r[1]=read(ram,0x0c07b5d8u,4);
goto P_0c07b55c;
P_0c07b55c: /* original 4508, guest PC 0x0c07b55c */
if(!s->budget--) { s->failed_pc=0x0c07b55cu; return 0; }
r[5]<<=2;
goto P_0c07b55e;
P_0c07b55e: /* original f49d, guest PC 0x0c07b55e */
if(!s->budget--) { s->failed_pc=0x0c07b55eu; return 0; }
fr[4]=0x3f800000u;
goto P_0c07b560;
P_0c07b560: /* original 7308, guest PC 0x0c07b560 */
if(!s->budget--) { s->failed_pc=0x0c07b560u; return 0; }
r[3]+=0x00000008u;
goto P_0c07b562;
P_0c07b562: /* original 351c, guest PC 0x0c07b562 */
if(!s->budget--) { s->failed_pc=0x0c07b562u; return 0; }
r[5]+=r[1];
goto P_0c07b564;
P_0c07b564: /* original f24c, guest PC 0x0c07b564 */
if(!s->budget--) { s->failed_pc=0x0c07b564u; return 0; }
vf3_matrix_move(s,2,4);
goto P_0c07b566;
P_0c07b566: /* original 6251, guest PC 0x0c07b566 */
if(!s->budget--) { s->failed_pc=0x0c07b566u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[5],2);
r[2]=tmp;
goto P_0c07b568;
P_0c07b568: /* original 8551, guest PC 0x0c07b568 */
if(!s->budget--) { s->failed_pc=0x0c07b568u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[5]+2,2);
goto P_0c07b56a;
P_0c07b56a: /* original 642d, guest PC 0x0c07b56a */
if(!s->budget--) { s->failed_pc=0x0c07b56au; return 0; }
r[4]=r[2]&65535u;
goto P_0c07b56c;
P_0c07b56c: /* original d21e, guest PC 0x0c07b56c */
if(!s->budget--) { s->failed_pc=0x0c07b56cu; return 0; }
r[2]=read(ram,0x0c07b5e8u,4);
goto P_0c07b56e;
P_0c07b56e: /* original 4408, guest PC 0x0c07b56e */
if(!s->budget--) { s->failed_pc=0x0c07b56eu; return 0; }
r[4]<<=2;
goto P_0c07b570;
P_0c07b570: /* original 4400, guest PC 0x0c07b570 */
if(!s->budget--) { s->failed_pc=0x0c07b570u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c07b572;
P_0c07b572: /* original 6123, guest PC 0x0c07b572 */
if(!s->budget--) { s->failed_pc=0x0c07b572u; return 0; }
r[1]=r[2];
goto P_0c07b574;
P_0c07b574: /* original 644d, guest PC 0x0c07b574 */
if(!s->budget--) { s->failed_pc=0x0c07b574u; return 0; }
r[4]=r[4]&65535u;
goto P_0c07b576;
P_0c07b576: /* original 445a, guest PC 0x0c07b576 */
if(!s->budget--) { s->failed_pc=0x0c07b576u; return 0; }
r[53]=r[4];
goto P_0c07b578;
P_0c07b578: /* original 650d, guest PC 0x0c07b578 */
if(!s->budget--) { s->failed_pc=0x0c07b578u; return 0; }
r[5]=r[0]&65535u;
goto P_0c07b57a;
P_0c07b57a: /* original 4508, guest PC 0x0c07b57a */
if(!s->budget--) { s->failed_pc=0x0c07b57au; return 0; }
r[5]<<=2;
goto P_0c07b57c;
P_0c07b57c: /* original 4500, guest PC 0x0c07b57c */
if(!s->budget--) { s->failed_pc=0x0c07b57cu; return 0; }
r[17]=(r[17]&~1u)|((r[5]>>31)!=0);
r[5]<<=1;
goto P_0c07b57e;
P_0c07b57e: /* original f32d, guest PC 0x0c07b57e */
if(!s->budget--) { s->failed_pc=0x0c07b57eu; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c07b580;
P_0c07b580: /* original 655d, guest PC 0x0c07b580 */
if(!s->budget--) { s->failed_pc=0x0c07b580u; return 0; }
r[5]=r[5]&65535u;
goto P_0c07b582;
P_0c07b582: /* original f233, guest PC 0x0c07b582 */
if(!s->budget--) { s->failed_pc=0x0c07b582u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'/');
goto P_0c07b584;
P_0c07b584: /* original f22a, guest PC 0x0c07b584 */
if(!s->budget--) { s->failed_pc=0x0c07b584u; return 0; }
vf3_matrix_store(s,ram,2,r[2]);
goto P_0c07b586;
P_0c07b586: /* original 72f8, guest PC 0x0c07b586 */
if(!s->budget--) { s->failed_pc=0x0c07b586u; return 0; }
r[2]+=0xfffffff8u;
goto P_0c07b588;
P_0c07b588: /* original 455a, guest PC 0x0c07b588 */
if(!s->budget--) { s->failed_pc=0x0c07b588u; return 0; }
r[53]=r[5];
goto P_0c07b58a;
P_0c07b58a: /* original f32d, guest PC 0x0c07b58a */
if(!s->budget--) { s->failed_pc=0x0c07b58au; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c07b58c;
P_0c07b58c: /* original f433, guest PC 0x0c07b58c */
if(!s->budget--) { s->failed_pc=0x0c07b58cu; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'/');
goto P_0c07b58e;
P_0c07b58e: /* original f34a, guest PC 0x0c07b58e */
if(!s->budget--) { s->failed_pc=0x0c07b58eu; return 0; }
vf3_matrix_store(s,ram,4,r[3]);
goto P_0c07b590;
P_0c07b590: /* original 7304, guest PC 0x0c07b590 */
if(!s->budget--) { s->failed_pc=0x0c07b590u; return 0; }
r[3]+=0x00000004u;
goto P_0c07b592;
P_0c07b592: /* original f318, guest PC 0x0c07b592 */
if(!s->budget--) { s->failed_pc=0x0c07b592u; return 0; }
vf3_matrix_load(s,ram,3,r[1]);
goto P_0c07b594;
P_0c07b594: /* original f228, guest PC 0x0c07b594 */
if(!s->budget--) { s->failed_pc=0x0c07b594u; return 0; }
vf3_matrix_load(s,ram,2,r[2]);
goto P_0c07b596;
P_0c07b596: /* original f232, guest PC 0x0c07b596 */
if(!s->budget--) { s->failed_pc=0x0c07b596u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c07b598;
P_0c07b598: /* original f32a, guest PC 0x0c07b598 */
if(!s->budget--) { s->failed_pc=0x0c07b598u; return 0; }
vf3_matrix_store(s,ram,2,r[3]);
goto P_0c07b59a;
P_0c07b59a: /* original d014, guest PC 0x0c07b59a */
if(!s->budget--) { s->failed_pc=0x0c07b59au; return 0; }
r[0]=read(ram,0x0c07b5ecu,4);
goto P_0c07b59c;
P_0c07b59c: /* original 720c, guest PC 0x0c07b59c */
if(!s->budget--) { s->failed_pc=0x0c07b59cu; return 0; }
r[2]+=0x0000000cu;
goto P_0c07b59e;
P_0c07b59e: /* original f328, guest PC 0x0c07b59e */
if(!s->budget--) { s->failed_pc=0x0c07b59eu; return 0; }
vf3_matrix_load(s,ram,3,r[2]);
goto P_0c07b5a0;
P_0c07b5a0: /* original 7304, guest PC 0x0c07b5a0 */
if(!s->budget--) { s->failed_pc=0x0c07b5a0u; return 0; }
r[3]+=0x00000004u;
goto P_0c07b5a2;
P_0c07b5a2: /* original f208, guest PC 0x0c07b5a2 */
if(!s->budget--) { s->failed_pc=0x0c07b5a2u; return 0; }
vf3_matrix_load(s,ram,2,r[0]);
goto P_0c07b5a4;
P_0c07b5a4: /* original 70f4, guest PC 0x0c07b5a4 */
if(!s->budget--) { s->failed_pc=0x0c07b5a4u; return 0; }
r[0]+=0xfffffff4u;
goto P_0c07b5a6;
P_0c07b5a6: /* original f232, guest PC 0x0c07b5a6 */
if(!s->budget--) { s->failed_pc=0x0c07b5a6u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c07b5a8;
P_0c07b5a8: /* original f32a, guest PC 0x0c07b5a8 */
if(!s->budget--) { s->failed_pc=0x0c07b5a8u; return 0; }
vf3_matrix_store(s,ram,2,r[3]);
goto P_0c07b5aa;
P_0c07b5aa: /* original 6df6, guest PC 0x0c07b5aa */
if(!s->budget--) { s->failed_pc=0x0c07b5aau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c07b5ac;
P_0c07b5ac: /* original 000b, guest PC 0x0c07b5ac */
if(!s->budget--) { s->failed_pc=0x0c07b5acu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c07b5ae: /* original 6ef6, guest PC 0x0c07b5ae */
if(!s->budget--) { s->failed_pc=0x0c07b5aeu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c07b5b0u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c07b5b0u; return 0; } return 1;
P_0c0a2e06: /* original d359, guest PC 0x0c0a2e06 */
if(!s->budget--) { s->failed_pc=0x0c0a2e06u; return 0; }
r[3]=read(ram,0x0c0a2f6cu,4);
goto P_0c0a2e08;
P_0c0a2e08: /* original 6643, guest PC 0x0c0a2e08 */
if(!s->budget--) { s->failed_pc=0x0c0a2e08u; return 0; }
r[6]=r[4];
goto P_0c0a2e0a;
P_0c0a2e0a: /* original 4608, guest PC 0x0c0a2e0a */
if(!s->budget--) { s->failed_pc=0x0c0a2e0au; return 0; }
r[6]<<=2;
goto P_0c0a2e0c;
P_0c0a2e0c: /* original 363c, guest PC 0x0c0a2e0c */
if(!s->budget--) { s->failed_pc=0x0c0a2e0cu; return 0; }
r[6]+=r[3];
goto P_0c0a2e0e;
P_0c0a2e0e: /* original 6262, guest PC 0x0c0a2e0e */
if(!s->budget--) { s->failed_pc=0x0c0a2e0eu; return 0; }
tmp=read(ram,r[6],4);
r[2]=tmp;
goto P_0c0a2e10;
P_0c0a2e10: /* original 2228, guest PC 0x0c0a2e10 */
if(!s->budget--) { s->failed_pc=0x0c0a2e10u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c0a2e12;
P_0c0a2e12: /* original 8b09, guest PC 0x0c0a2e12 */
if(!s->budget--) { s->failed_pc=0x0c0a2e12u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a2e28; }
goto P_0c0a2e14;
P_0c0a2e14: /* original 6062, guest PC 0x0c0a2e14 */
if(!s->budget--) { s->failed_pc=0x0c0a2e14u; return 0; }
tmp=read(ram,r[6],4);
r[0]=tmp;
goto P_0c0a2e16;
P_0c0a2e16: /* original 88ff, guest PC 0x0c0a2e16 */
if(!s->budget--) { s->failed_pc=0x0c0a2e16u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xffffffffu)!=0);
goto P_0c0a2e18;
P_0c0a2e18: /* original 8906, guest PC 0x0c0a2e18 */
if(!s->budget--) { s->failed_pc=0x0c0a2e18u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a2e28; }
goto P_0c0a2e1a;
P_0c0a2e1a: /* original 5051, guest PC 0x0c0a2e1a */
if(!s->budget--) { s->failed_pc=0x0c0a2e1au; return 0; }
r[0]=read(ram,r[5]+4,4);
goto P_0c0a2e1c;
P_0c0a2e1c: /* original c801, guest PC 0x0c0a2e1c */
if(!s->budget--) { s->failed_pc=0x0c0a2e1cu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&1u)==0)!=0);
goto P_0c0a2e1e;
P_0c0a2e1e: /* original 8901, guest PC 0x0c0a2e1e */
if(!s->budget--) { s->failed_pc=0x0c0a2e1eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a2e24; }
goto P_0c0a2e20;
P_0c0a2e20: /* original a002, guest PC 0x0c0a2e20 */
if(!s->budget--) { s->failed_pc=0x0c0a2e20u; return 0; }
write(ram,r[6],r[5],4);
goto P_0c0a2e28;
P_0c0a2e22: /* original 2652, guest PC 0x0c0a2e22 */
if(!s->budget--) { s->failed_pc=0x0c0a2e22u; return 0; }
write(ram,r[6],r[5],4);
goto P_0c0a2e24;
P_0c0a2e24: /* original 6152, guest PC 0x0c0a2e24 */
if(!s->budget--) { s->failed_pc=0x0c0a2e24u; return 0; }
tmp=read(ram,r[5],4);
r[1]=tmp;
goto P_0c0a2e26;
P_0c0a2e26: /* original 2612, guest PC 0x0c0a2e26 */
if(!s->budget--) { s->failed_pc=0x0c0a2e26u; return 0; }
write(ram,r[6],r[1],4);
goto P_0c0a2e28;
P_0c0a2e28: /* original 000b, guest PC 0x0c0a2e28 */
if(!s->budget--) { s->failed_pc=0x0c0a2e28u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c0a2e2a: /* original 0009, guest PC 0x0c0a2e2a */
if(!s->budget--) { s->failed_pc=0x0c0a2e2au; return 0; }
if(!vf3_matrix_family(0x0c0a2e2cu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0a2e2cu; return 0; } return 1;
P_0c0a7be2: /* original 2fe6, guest PC 0x0c0a7be2 */
if(!s->budget--) { s->failed_pc=0x0c0a7be2u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a7be4;
P_0c0a7be4: /* original 2fd6, guest PC 0x0c0a7be4 */
if(!s->budget--) { s->failed_pc=0x0c0a7be4u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a7be6;
P_0c0a7be6: /* original 2fc6, guest PC 0x0c0a7be6 */
if(!s->budget--) { s->failed_pc=0x0c0a7be6u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a7be8;
P_0c0a7be8: /* original 2fb6, guest PC 0x0c0a7be8 */
if(!s->budget--) { s->failed_pc=0x0c0a7be8u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a7bea;
P_0c0a7bea: /* original 2fa6, guest PC 0x0c0a7bea */
if(!s->budget--) { s->failed_pc=0x0c0a7beau; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a7bec;
P_0c0a7bec: /* original 4f22, guest PC 0x0c0a7bec */
if(!s->budget--) { s->failed_pc=0x0c0a7becu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0a7bee;
P_0c0a7bee: /* original de07, guest PC 0x0c0a7bee */
if(!s->budget--) { s->failed_pc=0x0c0a7beeu; return 0; }
r[14]=read(ram,0x0c0a7c0cu,4);
goto P_0c0a7bf0;
P_0c0a7bf0: /* original 900a, guest PC 0x0c0a7bf0 */
if(!s->budget--) { s->failed_pc=0x0c0a7bf0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a7c08u,2);
goto P_0c0a7bf2;
P_0c0a7bf2: /* original 4f12, guest PC 0x0c0a7bf2 */
if(!s->budget--) { s->failed_pc=0x0c0a7bf2u; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c0a7bf4;
P_0c0a7bf4: /* original 00ec, guest PC 0x0c0a7bf4 */
if(!s->budget--) { s->failed_pc=0x0c0a7bf4u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0a7bf6;
P_0c0a7bf6: /* original dc07, guest PC 0x0c0a7bf6 */
if(!s->budget--) { s->failed_pc=0x0c0a7bf6u; return 0; }
r[12]=read(ram,0x0c0a7c14u,4);
goto P_0c0a7bf8;
P_0c0a7bf8: /* original 8801, guest PC 0x0c0a7bf8 */
if(!s->budget--) { s->failed_pc=0x0c0a7bf8u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c0a7bfa;
P_0c0a7bfa: /* original 7ff8, guest PC 0x0c0a7bfa */
if(!s->budget--) { s->failed_pc=0x0c0a7bfau; return 0; }
r[15]+=0xfffffff8u;
goto P_0c0a7bfc;
P_0c0a7bfc: /* original 8f0e, guest PC 0x0c0a7bfc */
if(!s->budget--) { s->failed_pc=0x0c0a7bfcu; return 0; }
cond=r[17]&1u;
r[11]=0x00000000u;
if(!cond) { goto P_0c0a7c1c; }
goto P_0c0a7c00;
P_0c0a7bfe: /* original eb00, guest PC 0x0c0a7bfe */
if(!s->budget--) { s->failed_pc=0x0c0a7bfeu; return 0; }
r[11]=0x00000000u;
goto P_0c0a7c00;
P_0c0a7c00: /* original d205, guest PC 0x0c0a7c00 */
if(!s->budget--) { s->failed_pc=0x0c0a7c00u; return 0; }
r[2]=read(ram,0x0c0a7c18u,4);
goto P_0c0a7c02;
P_0c0a7c02: /* original a00d, guest PC 0x0c0a7c02 */
if(!s->budget--) { s->failed_pc=0x0c0a7c02u; return 0; }
tmp=read(ram,r[2],4);
r[13]=tmp;
goto P_0c0a7c20;
P_0c0a7c04: /* original 6d22, guest PC 0x0c0a7c04 */
if(!s->budget--) { s->failed_pc=0x0c0a7c04u; return 0; }
tmp=read(ram,r[2],4);
r[13]=tmp;
if(!vf3_matrix_family(0x0c0a7c06u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0a7c06u; return 0; } return 1;
P_0c0a7c1c: /* original d144, guest PC 0x0c0a7c1c */
if(!s->budget--) { s->failed_pc=0x0c0a7c1cu; return 0; }
r[1]=read(ram,0x0c0a7d30u,4);
goto P_0c0a7c1e;
P_0c0a7c1e: /* original 6d12, guest PC 0x0c0a7c1e */
if(!s->budget--) { s->failed_pc=0x0c0a7c1eu; return 0; }
tmp=read(ram,r[1],4);
r[13]=tmp;
goto P_0c0a7c20;
P_0c0a7c20: /* original 3d40, guest PC 0x0c0a7c20 */
if(!s->budget--) { s->failed_pc=0x0c0a7c20u; return 0; }
r[17]=(r[17]&~1u)|((r[13]==r[4])!=0);
goto P_0c0a7c22;
P_0c0a7c22: /* original 8901, guest PC 0x0c0a7c22 */
if(!s->budget--) { s->failed_pc=0x0c0a7c22u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a7c28; }
goto P_0c0a7c24;
P_0c0a7c24: /* original a100, guest PC 0x0c0a7c24 */
if(!s->budget--) { s->failed_pc=0x0c0a7c24u; return 0; }
goto P_0c0a7e28;
P_0c0a7c26: /* original 0009, guest PC 0x0c0a7c26 */
if(!s->budget--) { s->failed_pc=0x0c0a7c26u; return 0; }
goto P_0c0a7c28;
P_0c0a7c28: /* original 5de2, guest PC 0x0c0a7c28 */
if(!s->budget--) { s->failed_pc=0x0c0a7c28u; return 0; }
r[13]=read(ram,r[14]+8,4);
goto P_0c0a7c2a;
P_0c0a7c2a: /* original e308, guest PC 0x0c0a7c2a */
if(!s->budget--) { s->failed_pc=0x0c0a7c2au; return 0; }
r[3]=0x00000008u;
goto P_0c0a7c2c;
P_0c0a7c2c: /* original 23d8, guest PC 0x0c0a7c2c */
if(!s->budget--) { s->failed_pc=0x0c0a7c2cu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[13])==0)!=0);
goto P_0c0a7c2e;
P_0c0a7c2e: /* original 8b01, guest PC 0x0c0a7c2e */
if(!s->budget--) { s->failed_pc=0x0c0a7c2eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a7c34; }
goto P_0c0a7c30;
P_0c0a7c30: /* original a0fa, guest PC 0x0c0a7c30 */
if(!s->budget--) { s->failed_pc=0x0c0a7c30u; return 0; }
goto P_0c0a7e28;
P_0c0a7c32: /* original 0009, guest PC 0x0c0a7c32 */
if(!s->budget--) { s->failed_pc=0x0c0a7c32u; return 0; }
goto P_0c0a7c34;
P_0c0a7c34: /* original d23f, guest PC 0x0c0a7c34 */
if(!s->budget--) { s->failed_pc=0x0c0a7c34u; return 0; }
r[2]=read(ram,0x0c0a7d34u,4);
goto P_0c0a7c36;
P_0c0a7c36: /* original 22d8, guest PC 0x0c0a7c36 */
if(!s->budget--) { s->failed_pc=0x0c0a7c36u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[13])==0)!=0);
goto P_0c0a7c38;
P_0c0a7c38: /* original 8901, guest PC 0x0c0a7c38 */
if(!s->budget--) { s->failed_pc=0x0c0a7c38u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a7c3e; }
goto P_0c0a7c3a;
P_0c0a7c3a: /* original a0f5, guest PC 0x0c0a7c3a */
if(!s->budget--) { s->failed_pc=0x0c0a7c3au; return 0; }
goto P_0c0a7e28;
P_0c0a7c3c: /* original 0009, guest PC 0x0c0a7c3c */
if(!s->budget--) { s->failed_pc=0x0c0a7c3cu; return 0; }
goto P_0c0a7c3e;
P_0c0a7c3e: /* original 936f, guest PC 0x0c0a7c3e */
if(!s->budget--) { s->failed_pc=0x0c0a7c3eu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a7d20u,2);
goto P_0c0a7c40;
P_0c0a7c40: /* original 23d8, guest PC 0x0c0a7c40 */
if(!s->budget--) { s->failed_pc=0x0c0a7c40u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[13])==0)!=0);
goto P_0c0a7c42;
P_0c0a7c42: /* original 8901, guest PC 0x0c0a7c42 */
if(!s->budget--) { s->failed_pc=0x0c0a7c42u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a7c48; }
goto P_0c0a7c44;
P_0c0a7c44: /* original a0f0, guest PC 0x0c0a7c44 */
if(!s->budget--) { s->failed_pc=0x0c0a7c44u; return 0; }
goto P_0c0a7e28;
P_0c0a7c46: /* original 0009, guest PC 0x0c0a7c46 */
if(!s->budget--) { s->failed_pc=0x0c0a7c46u; return 0; }
goto P_0c0a7c48;
P_0c0a7c48: /* original d23b, guest PC 0x0c0a7c48 */
if(!s->budget--) { s->failed_pc=0x0c0a7c48u; return 0; }
r[2]=read(ram,0x0c0a7d38u,4);
goto P_0c0a7c4a;
P_0c0a7c4a: /* original 22d8, guest PC 0x0c0a7c4a */
if(!s->budget--) { s->failed_pc=0x0c0a7c4au; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[13])==0)!=0);
goto P_0c0a7c4c;
P_0c0a7c4c: /* original 8901, guest PC 0x0c0a7c4c */
if(!s->budget--) { s->failed_pc=0x0c0a7c4cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a7c52; }
goto P_0c0a7c4e;
P_0c0a7c4e: /* original a0eb, guest PC 0x0c0a7c4e */
if(!s->budget--) { s->failed_pc=0x0c0a7c4eu; return 0; }
goto P_0c0a7e28;
P_0c0a7c50: /* original 0009, guest PC 0x0c0a7c50 */
if(!s->budget--) { s->failed_pc=0x0c0a7c50u; return 0; }
goto P_0c0a7c52;
P_0c0a7c52: /* original d33a, guest PC 0x0c0a7c52 */
if(!s->budget--) { s->failed_pc=0x0c0a7c52u; return 0; }
r[3]=read(ram,0x0c0a7d3cu,4);
goto P_0c0a7c54;
P_0c0a7c54: /* original 2d38, guest PC 0x0c0a7c54 */
if(!s->budget--) { s->failed_pc=0x0c0a7c54u; return 0; }
r[17]=(r[17]&~1u)|(((r[13]&r[3])==0)!=0);
goto P_0c0a7c56;
P_0c0a7c56: /* original 8901, guest PC 0x0c0a7c56 */
if(!s->budget--) { s->failed_pc=0x0c0a7c56u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a7c5c; }
goto P_0c0a7c58;
P_0c0a7c58: /* original a0e6, guest PC 0x0c0a7c58 */
if(!s->budget--) { s->failed_pc=0x0c0a7c58u; return 0; }
goto P_0c0a7e28;
P_0c0a7c5a: /* original 0009, guest PC 0x0c0a7c5a */
if(!s->budget--) { s->failed_pc=0x0c0a7c5au; return 0; }
goto P_0c0a7c5c;
P_0c0a7c5c: /* original 62c2, guest PC 0x0c0a7c5c */
if(!s->budget--) { s->failed_pc=0x0c0a7c5cu; return 0; }
tmp=read(ram,r[12],4);
r[2]=tmp;
goto P_0c0a7c5e;
P_0c0a7c5e: /* original 6123, guest PC 0x0c0a7c5e */
if(!s->budget--) { s->failed_pc=0x0c0a7c5eu; return 0; }
r[1]=r[2];
goto P_0c0a7c60;
P_0c0a7c60: /* original 2f22, guest PC 0x0c0a7c60 */
if(!s->budget--) { s->failed_pc=0x0c0a7c60u; return 0; }
write(ram,r[15],r[2],4);
goto P_0c0a7c62;
P_0c0a7c62: /* original d337, guest PC 0x0c0a7c62 */
if(!s->budget--) { s->failed_pc=0x0c0a7c62u; return 0; }
r[3]=read(ram,0x0c0a7d40u,4);
goto P_0c0a7c64;
P_0c0a7c64: /* original 2138, guest PC 0x0c0a7c64 */
if(!s->budget--) { s->failed_pc=0x0c0a7c64u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[3])==0)!=0);
goto P_0c0a7c66;
P_0c0a7c66: /* original 8b01, guest PC 0x0c0a7c66 */
if(!s->budget--) { s->failed_pc=0x0c0a7c66u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a7c6c; }
goto P_0c0a7c68;
P_0c0a7c68: /* original a0de, guest PC 0x0c0a7c68 */
if(!s->budget--) { s->failed_pc=0x0c0a7c68u; return 0; }
goto P_0c0a7e28;
P_0c0a7c6a: /* original 0009, guest PC 0x0c0a7c6a */
if(!s->budget--) { s->failed_pc=0x0c0a7c6au; return 0; }
goto P_0c0a7c6c;
P_0c0a7c6c: /* original e029, guest PC 0x0c0a7c6c */
if(!s->budget--) { s->failed_pc=0x0c0a7c6cu; return 0; }
r[0]=0x00000029u;
goto P_0c0a7c6e;
P_0c0a7c6e: /* original 00ec, guest PC 0x0c0a7c6e */
if(!s->budget--) { s->failed_pc=0x0c0a7c6eu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0a7c70;
P_0c0a7c70: /* original 600c, guest PC 0x0c0a7c70 */
if(!s->budget--) { s->failed_pc=0x0c0a7c70u; return 0; }
r[0]=r[0]&255u;
goto P_0c0a7c72;
P_0c0a7c72: /* original 8803, guest PC 0x0c0a7c72 */
if(!s->budget--) { s->failed_pc=0x0c0a7c72u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000003u)!=0);
goto P_0c0a7c74;
P_0c0a7c74: /* original 8b01, guest PC 0x0c0a7c74 */
if(!s->budget--) { s->failed_pc=0x0c0a7c74u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a7c7a; }
goto P_0c0a7c76;
P_0c0a7c76: /* original a0d5, guest PC 0x0c0a7c76 */
if(!s->budget--) { s->failed_pc=0x0c0a7c76u; return 0; }
goto P_0c0a7e24;
P_0c0a7c78: /* original 0009, guest PC 0x0c0a7c78 */
if(!s->budget--) { s->failed_pc=0x0c0a7c78u; return 0; }
goto P_0c0a7c7a;
P_0c0a7c7a: /* original d332, guest PC 0x0c0a7c7a */
if(!s->budget--) { s->failed_pc=0x0c0a7c7au; return 0; }
r[3]=read(ram,0x0c0a7d44u,4);
goto P_0c0a7c7c;
P_0c0a7c7c: /* original 5cc1, guest PC 0x0c0a7c7c */
if(!s->budget--) { s->failed_pc=0x0c0a7c7cu; return 0; }
r[12]=read(ram,r[12]+4,4);
goto P_0c0a7c7e;
P_0c0a7c7e: /* original 9050, guest PC 0x0c0a7c7e */
if(!s->budget--) { s->failed_pc=0x0c0a7c7eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a7d22u,2);
goto P_0c0a7c80;
P_0c0a7c80: /* original 23c8, guest PC 0x0c0a7c80 */
if(!s->budget--) { s->failed_pc=0x0c0a7c80u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[12])==0)!=0);
goto P_0c0a7c82;
P_0c0a7c82: /* original 8f6b, guest PC 0x0c0a7c82 */
if(!s->budget--) { s->failed_pc=0x0c0a7c82u; return 0; }
cond=r[17]&1u;
r[13]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
if(!cond) { goto P_0c0a7d5c; }
goto P_0c0a7c86;
P_0c0a7c84: /* original 0ded, guest PC 0x0c0a7c84 */
if(!s->budget--) { s->failed_pc=0x0c0a7c84u; return 0; }
r[13]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0a7c86;
P_0c0a7c86: /* original d230, guest PC 0x0c0a7c86 */
if(!s->budget--) { s->failed_pc=0x0c0a7c86u; return 0; }
r[2]=read(ram,0x0c0a7d48u,4);
goto P_0c0a7c88;
P_0c0a7c88: /* original 22c8, guest PC 0x0c0a7c88 */
if(!s->budget--) { s->failed_pc=0x0c0a7c88u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[12])==0)!=0);
goto P_0c0a7c8a;
P_0c0a7c8a: /* original 8b04, guest PC 0x0c0a7c8a */
if(!s->budget--) { s->failed_pc=0x0c0a7c8au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a7c96; }
goto P_0c0a7c8c;
P_0c0a7c8c: /* original d32f, guest PC 0x0c0a7c8c */
if(!s->budget--) { s->failed_pc=0x0c0a7c8cu; return 0; }
r[3]=read(ram,0x0c0a7d4cu,4);
goto P_0c0a7c8e;
P_0c0a7c8e: /* original 2c38, guest PC 0x0c0a7c8e */
if(!s->budget--) { s->failed_pc=0x0c0a7c8eu; return 0; }
r[17]=(r[17]&~1u)|(((r[12]&r[3])==0)!=0);
goto P_0c0a7c90;
P_0c0a7c90: /* original 8b01, guest PC 0x0c0a7c90 */
if(!s->budget--) { s->failed_pc=0x0c0a7c90u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a7c96; }
goto P_0c0a7c92;
P_0c0a7c92: /* original a0c9, guest PC 0x0c0a7c92 */
if(!s->budget--) { s->failed_pc=0x0c0a7c92u; return 0; }
goto P_0c0a7e28;
P_0c0a7c94: /* original 0009, guest PC 0x0c0a7c94 */
if(!s->budget--) { s->failed_pc=0x0c0a7c94u; return 0; }
goto P_0c0a7c96;
P_0c0a7c96: /* original d32e, guest PC 0x0c0a7c96 */
if(!s->budget--) { s->failed_pc=0x0c0a7c96u; return 0; }
r[3]=read(ram,0x0c0a7d50u,4);
goto P_0c0a7c98;
P_0c0a7c98: /* original 9c44, guest PC 0x0c0a7c98 */
if(!s->budget--) { s->failed_pc=0x0c0a7c98u; return 0; }
r[12]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a7d24u,2);
goto P_0c0a7c9a;
P_0c0a7c9a: /* original 2638, guest PC 0x0c0a7c9a */
if(!s->budget--) { s->failed_pc=0x0c0a7c9au; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[3])==0)!=0);
goto P_0c0a7c9c;
P_0c0a7c9c: /* original 892a, guest PC 0x0c0a7c9c */
if(!s->budget--) { s->failed_pc=0x0c0a7c9cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a7cf4; }
goto P_0c0a7c9e;
P_0c0a7c9e: /* original 9042, guest PC 0x0c0a7c9e */
if(!s->budget--) { s->failed_pc=0x0c0a7c9eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a7d26u,2);
goto P_0c0a7ca0;
P_0c0a7ca0: /* original 065d, guest PC 0x0c0a7ca0 */
if(!s->budget--) { s->failed_pc=0x0c0a7ca0u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,r[5]+r[0],2);
goto P_0c0a7ca2;
P_0c0a7ca2: /* original 05b5, guest PC 0x0c0a7ca2 */
if(!s->budget--) { s->failed_pc=0x0c0a7ca2u; return 0; }
write(ram,r[5]+r[0],r[11],2);
goto P_0c0a7ca4;
P_0c0a7ca4: /* original 9040, guest PC 0x0c0a7ca4 */
if(!s->budget--) { s->failed_pc=0x0c0a7ca4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a7d28u,2);
goto P_0c0a7ca6;
P_0c0a7ca6: /* original 0a5c, guest PC 0x0c0a7ca6 */
if(!s->budget--) { s->failed_pc=0x0c0a7ca6u; return 0; }
r[10]=(uint32_t)(int32_t)(int8_t)read(ram,r[5]+r[0],1);
goto P_0c0a7ca8;
P_0c0a7ca8: /* original 903f, guest PC 0x0c0a7ca8 */
if(!s->budget--) { s->failed_pc=0x0c0a7ca8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a7d2au,2);
goto P_0c0a7caa;
P_0c0a7caa: /* original 6aac, guest PC 0x0c0a7caa */
if(!s->budget--) { s->failed_pc=0x0c0a7caau; return 0; }
r[10]=r[10]&255u;
goto P_0c0a7cac;
P_0c0a7cac: /* original 7a03, guest PC 0x0c0a7cac */
if(!s->budget--) { s->failed_pc=0x0c0a7cacu; return 0; }
r[10]+=0x00000003u;
goto P_0c0a7cae;
P_0c0a7cae: /* original 06a7, guest PC 0x0c0a7cae */
if(!s->budget--) { s->failed_pc=0x0c0a7caeu; return 0; }
r[19]=r[6]*r[10];
goto P_0c0a7cb0;
P_0c0a7cb0: /* original 0a4d, guest PC 0x0c0a7cb0 */
if(!s->budget--) { s->failed_pc=0x0c0a7cb0u; return 0; }
r[10]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c0a7cb2;
P_0c0a7cb2: /* original 7a01, guest PC 0x0c0a7cb2 */
if(!s->budget--) { s->failed_pc=0x0c0a7cb2u; return 0; }
r[10]+=0x00000001u;
goto P_0c0a7cb4;
P_0c0a7cb4: /* original 061a, guest PC 0x0c0a7cb4 */
if(!s->budget--) { s->failed_pc=0x0c0a7cb4u; return 0; }
r[6]=r[19];
goto P_0c0a7cb6;
P_0c0a7cb6: /* original 4621, guest PC 0x0c0a7cb6 */
if(!s->budget--) { s->failed_pc=0x0c0a7cb6u; return 0; }
r[17]=(r[17]&~1u)|((r[6]&1)!=0);
r[6]=(uint32_t)((int32_t)r[6]>>1);
goto P_0c0a7cb8;
P_0c0a7cb8: /* original 4621, guest PC 0x0c0a7cb8 */
if(!s->budget--) { s->failed_pc=0x0c0a7cb8u; return 0; }
r[17]=(r[17]&~1u)|((r[6]&1)!=0);
r[6]=(uint32_t)((int32_t)r[6]>>1);
goto P_0c0a7cba;
P_0c0a7cba: /* original 3ac3, guest PC 0x0c0a7cba */
if(!s->budget--) { s->failed_pc=0x0c0a7cbau; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[10]>=(int32_t)r[12])!=0);
goto P_0c0a7cbc;
P_0c0a7cbc: /* original 06c7, guest PC 0x0c0a7cbc */
if(!s->budget--) { s->failed_pc=0x0c0a7cbcu; return 0; }
r[19]=r[6]*r[12];
goto P_0c0a7cbe;
P_0c0a7cbe: /* original 8f01, guest PC 0x0c0a7cbe */
if(!s->budget--) { s->failed_pc=0x0c0a7cbeu; return 0; }
cond=r[17]&1u;
r[6]=r[19];
if(!cond) { goto P_0c0a7cc4; }
goto P_0c0a7cc2;
P_0c0a7cc0: /* original 061a, guest PC 0x0c0a7cc0 */
if(!s->budget--) { s->failed_pc=0x0c0a7cc0u; return 0; }
r[6]=r[19];
goto P_0c0a7cc2;
P_0c0a7cc2: /* original 6ac3, guest PC 0x0c0a7cc2 */
if(!s->budget--) { s->failed_pc=0x0c0a7cc2u; return 0; }
r[10]=r[12];
goto P_0c0a7cc4;
P_0c0a7cc4: /* original d223, guest PC 0x0c0a7cc4 */
if(!s->budget--) { s->failed_pc=0x0c0a7cc4u; return 0; }
r[2]=read(ram,0x0c0a7d54u,4);
goto P_0c0a7cc6;
P_0c0a7cc6: /* original 6163, guest PC 0x0c0a7cc6 */
if(!s->budget--) { s->failed_pc=0x0c0a7cc6u; return 0; }
r[1]=r[6];
goto P_0c0a7cc8;
P_0c0a7cc8: /* original 420b, guest PC 0x0c0a7cc8 */
if(!s->budget--) { s->failed_pc=0x0c0a7cc8u; return 0; }
target=r[2];
r[16]=code_base|0x0c0a7cccu;
r[0]=r[10];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a7cccu) { target=s->pc; goto dispatch; }
goto P_0c0a7ccc;
P_0c0a7cca: /* original 60a3, guest PC 0x0c0a7cca */
if(!s->budget--) { s->failed_pc=0x0c0a7ccau; return 0; }
r[0]=r[10];
goto P_0c0a7ccc;
P_0c0a7ccc: /* original 6603, guest PC 0x0c0a7ccc */
if(!s->budget--) { s->failed_pc=0x0c0a7cccu; return 0; }
r[6]=r[0];
goto P_0c0a7cce;
P_0c0a7cce: /* original 7601, guest PC 0x0c0a7cce */
if(!s->budget--) { s->failed_pc=0x0c0a7cceu; return 0; }
r[6]+=0x00000001u;
goto P_0c0a7cd0;
P_0c0a7cd0: /* original 3d6c, guest PC 0x0c0a7cd0 */
if(!s->budget--) { s->failed_pc=0x0c0a7cd0u; return 0; }
r[13]+=r[6];
goto P_0c0a7cd2;
P_0c0a7cd2: /* original 667e, guest PC 0x0c0a7cd2 */
if(!s->budget--) { s->failed_pc=0x0c0a7cd2u; return 0; }
r[6]=(uint32_t)(int32_t)(int8_t)r[7];
goto P_0c0a7cd4;
P_0c0a7cd4: /* original 4608, guest PC 0x0c0a7cd4 */
if(!s->budget--) { s->failed_pc=0x0c0a7cd4u; return 0; }
r[6]<<=2;
goto P_0c0a7cd6;
P_0c0a7cd6: /* original e03c, guest PC 0x0c0a7cd6 */
if(!s->budget--) { s->failed_pc=0x0c0a7cd6u; return 0; }
r[0]=0x0000003cu;
goto P_0c0a7cd8;
P_0c0a7cd8: /* original 034d, guest PC 0x0c0a7cd8 */
if(!s->budget--) { s->failed_pc=0x0c0a7cd8u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c0a7cda;
P_0c0a7cda: /* original 633d, guest PC 0x0c0a7cda */
if(!s->budget--) { s->failed_pc=0x0c0a7cdau; return 0; }
r[3]=r[3]&65535u;
goto P_0c0a7cdc;
P_0c0a7cdc: /* original 2f32, guest PC 0x0c0a7cdc */
if(!s->budget--) { s->failed_pc=0x0c0a7cdcu; return 0; }
write(ram,r[15],r[3],4);
goto P_0c0a7cde;
P_0c0a7cde: /* original d21e, guest PC 0x0c0a7cde */
if(!s->budget--) { s->failed_pc=0x0c0a7cdeu; return 0; }
r[2]=read(ram,0x0c0a7d58u,4);
goto P_0c0a7ce0;
P_0c0a7ce0: /* original 362c, guest PC 0x0c0a7ce0 */
if(!s->budget--) { s->failed_pc=0x0c0a7ce0u; return 0; }
r[6]+=r[2];
goto P_0c0a7ce2;
P_0c0a7ce2: /* original 6161, guest PC 0x0c0a7ce2 */
if(!s->budget--) { s->failed_pc=0x0c0a7ce2u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[6],2);
r[1]=tmp;
goto P_0c0a7ce4;
P_0c0a7ce4: /* original 3310, guest PC 0x0c0a7ce4 */
if(!s->budget--) { s->failed_pc=0x0c0a7ce4u; return 0; }
r[17]=(r[17]&~1u)|((r[3]==r[1])!=0);
goto P_0c0a7ce6;
P_0c0a7ce6: /* original 8b05, guest PC 0x0c0a7ce6 */
if(!s->budget--) { s->failed_pc=0x0c0a7ce6u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a7cf4; }
goto P_0c0a7ce8;
P_0c0a7ce8: /* original 8561, guest PC 0x0c0a7ce8 */
if(!s->budget--) { s->failed_pc=0x0c0a7ce8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[6]+2,2);
goto P_0c0a7cea;
P_0c0a7cea: /* original 3d0c, guest PC 0x0c0a7cea */
if(!s->budget--) { s->failed_pc=0x0c0a7ceau; return 0; }
r[13]+=r[0];
goto P_0c0a7cec;
P_0c0a7cec: /* original 901e, guest PC 0x0c0a7cec */
if(!s->budget--) { s->failed_pc=0x0c0a7cecu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a7d2cu,2);
goto P_0c0a7cee;
P_0c0a7cee: /* original 03ed, guest PC 0x0c0a7cee */
if(!s->budget--) { s->failed_pc=0x0c0a7ceeu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0a7cf0;
P_0c0a7cf0: /* original 7301, guest PC 0x0c0a7cf0 */
if(!s->budget--) { s->failed_pc=0x0c0a7cf0u; return 0; }
r[3]+=0x00000001u;
goto P_0c0a7cf2;
P_0c0a7cf2: /* original 0e35, guest PC 0x0c0a7cf2 */
if(!s->budget--) { s->failed_pc=0x0c0a7cf2u; return 0; }
write(ram,r[14]+r[0],r[3],2);
goto P_0c0a7cf4;
P_0c0a7cf4: /* original 9017, guest PC 0x0c0a7cf4 */
if(!s->budget--) { s->failed_pc=0x0c0a7cf4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a7d26u,2);
goto P_0c0a7cf6;
P_0c0a7cf6: /* original 065d, guest PC 0x0c0a7cf6 */
if(!s->budget--) { s->failed_pc=0x0c0a7cf6u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,r[5]+r[0],2);
goto P_0c0a7cf8;
P_0c0a7cf8: /* original 2668, guest PC 0x0c0a7cf8 */
if(!s->budget--) { s->failed_pc=0x0c0a7cf8u; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[6])==0)!=0);
goto P_0c0a7cfa;
P_0c0a7cfa: /* original 890d, guest PC 0x0c0a7cfa */
if(!s->budget--) { s->failed_pc=0x0c0a7cfau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a7d18; }
goto P_0c0a7cfc;
P_0c0a7cfc: /* original 9015, guest PC 0x0c0a7cfc */
if(!s->budget--) { s->failed_pc=0x0c0a7cfcu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a7d2au,2);
goto P_0c0a7cfe;
P_0c0a7cfe: /* original 06c7, guest PC 0x0c0a7cfe */
if(!s->budget--) { s->failed_pc=0x0c0a7cfeu; return 0; }
r[19]=r[6]*r[12];
goto P_0c0a7d00;
P_0c0a7d00: /* original 044d, guest PC 0x0c0a7d00 */
if(!s->budget--) { s->failed_pc=0x0c0a7d00u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c0a7d02;
P_0c0a7d02: /* original 7401, guest PC 0x0c0a7d02 */
if(!s->budget--) { s->failed_pc=0x0c0a7d02u; return 0; }
r[4]+=0x00000001u;
goto P_0c0a7d04;
P_0c0a7d04: /* original 34c3, guest PC 0x0c0a7d04 */
if(!s->budget--) { s->failed_pc=0x0c0a7d04u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=(int32_t)r[12])!=0);
goto P_0c0a7d06;
P_0c0a7d06: /* original 8f01, guest PC 0x0c0a7d06 */
if(!s->budget--) { s->failed_pc=0x0c0a7d06u; return 0; }
cond=r[17]&1u;
r[6]=r[19];
if(!cond) { goto P_0c0a7d0c; }
goto P_0c0a7d0a;
P_0c0a7d08: /* original 061a, guest PC 0x0c0a7d08 */
if(!s->budget--) { s->failed_pc=0x0c0a7d08u; return 0; }
r[6]=r[19];
goto P_0c0a7d0a;
P_0c0a7d0a: /* original 64c3, guest PC 0x0c0a7d0a */
if(!s->budget--) { s->failed_pc=0x0c0a7d0au; return 0; }
r[4]=r[12];
goto P_0c0a7d0c;
P_0c0a7d0c: /* original d211, guest PC 0x0c0a7d0c */
if(!s->budget--) { s->failed_pc=0x0c0a7d0cu; return 0; }
r[2]=read(ram,0x0c0a7d54u,4);
goto P_0c0a7d0e;
P_0c0a7d0e: /* original 6163, guest PC 0x0c0a7d0e */
if(!s->budget--) { s->failed_pc=0x0c0a7d0eu; return 0; }
r[1]=r[6];
goto P_0c0a7d10;
P_0c0a7d10: /* original 420b, guest PC 0x0c0a7d10 */
if(!s->budget--) { s->failed_pc=0x0c0a7d10u; return 0; }
target=r[2];
r[16]=code_base|0x0c0a7d14u;
r[0]=r[4];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a7d14u) { target=s->pc; goto dispatch; }
goto P_0c0a7d14;
P_0c0a7d12: /* original 6043, guest PC 0x0c0a7d12 */
if(!s->budget--) { s->failed_pc=0x0c0a7d12u; return 0; }
r[0]=r[4];
goto P_0c0a7d14;
P_0c0a7d14: /* original 6603, guest PC 0x0c0a7d14 */
if(!s->budget--) { s->failed_pc=0x0c0a7d14u; return 0; }
r[6]=r[0];
goto P_0c0a7d16;
P_0c0a7d16: /* original 7601, guest PC 0x0c0a7d16 */
if(!s->budget--) { s->failed_pc=0x0c0a7d16u; return 0; }
r[6]+=0x00000001u;
goto P_0c0a7d18;
P_0c0a7d18: /* original 9003, guest PC 0x0c0a7d18 */
if(!s->budget--) { s->failed_pc=0x0c0a7d18u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a7d22u,2);
goto P_0c0a7d1a;
P_0c0a7d1a: /* original 3d6c, guest PC 0x0c0a7d1a */
if(!s->budget--) { s->failed_pc=0x0c0a7d1au; return 0; }
r[13]+=r[6];
goto P_0c0a7d1c;
P_0c0a7d1c: /* original a084, guest PC 0x0c0a7d1c */
if(!s->budget--) { s->failed_pc=0x0c0a7d1cu; return 0; }
write(ram,r[14]+r[0],r[13],2);
goto P_0c0a7e28;
P_0c0a7d1e: /* original 0ed5, guest PC 0x0c0a7d1e */
if(!s->budget--) { s->failed_pc=0x0c0a7d1eu; return 0; }
write(ram,r[14]+r[0],r[13],2);
if(!vf3_matrix_family(0x0c0a7d20u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0a7d20u; return 0; } return 1;
P_0c0a7d5c: /* original e019, guest PC 0x0c0a7d5c */
if(!s->budget--) { s->failed_pc=0x0c0a7d5cu; return 0; }
r[0]=0x00000019u;
goto P_0c0a7d5e;
P_0c0a7d5e: /* original 07ec, guest PC 0x0c0a7d5e */
if(!s->budget--) { s->failed_pc=0x0c0a7d5eu; return 0; }
r[7]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0a7d60;
P_0c0a7d60: /* original 677c, guest PC 0x0c0a7d60 */
if(!s->budget--) { s->failed_pc=0x0c0a7d60u; return 0; }
r[7]=r[7]&255u;
goto P_0c0a7d62;
P_0c0a7d62: /* original 6073, guest PC 0x0c0a7d62 */
if(!s->budget--) { s->failed_pc=0x0c0a7d62u; return 0; }
r[0]=r[7];
goto P_0c0a7d64;
P_0c0a7d64: /* original 8802, guest PC 0x0c0a7d64 */
if(!s->budget--) { s->failed_pc=0x0c0a7d64u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c0a7d66;
P_0c0a7d66: /* original 8d28, guest PC 0x0c0a7d66 */
if(!s->budget--) { s->failed_pc=0x0c0a7d66u; return 0; }
cond=r[17]&1u;
r[6]=0x00000020u;
if(cond) { goto P_0c0a7dba; }
goto P_0c0a7d6a;
P_0c0a7d68: /* original e620, guest PC 0x0c0a7d68 */
if(!s->budget--) { s->failed_pc=0x0c0a7d68u; return 0; }
r[6]=0x00000020u;
goto P_0c0a7d6a;
P_0c0a7d6a: /* original 9068, guest PC 0x0c0a7d6a */
if(!s->budget--) { s->failed_pc=0x0c0a7d6au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a7e3eu,2);
goto P_0c0a7d6c;
P_0c0a7d6c: /* original 03ee, guest PC 0x0c0a7d6c */
if(!s->budget--) { s->failed_pc=0x0c0a7d6cu; return 0; }
r[3]=read(ram,r[14]+r[0],4);
goto P_0c0a7d6e;
P_0c0a7d6e: /* original 3430, guest PC 0x0c0a7d6e */
if(!s->budget--) { s->failed_pc=0x0c0a7d6eu; return 0; }
r[17]=(r[17]&~1u)|((r[4]==r[3])!=0);
goto P_0c0a7d70;
P_0c0a7d70: /* original 8b23, guest PC 0x0c0a7d70 */
if(!s->budget--) { s->failed_pc=0x0c0a7d70u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a7dba; }
goto P_0c0a7d72;
P_0c0a7d72: /* original e046, guest PC 0x0c0a7d72 */
if(!s->budget--) { s->failed_pc=0x0c0a7d72u; return 0; }
r[0]=0x00000046u;
goto P_0c0a7d74;
P_0c0a7d74: /* original 074d, guest PC 0x0c0a7d74 */
if(!s->budget--) { s->failed_pc=0x0c0a7d74u; return 0; }
r[7]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c0a7d76;
P_0c0a7d76: /* original e018, guest PC 0x0c0a7d76 */
if(!s->budget--) { s->failed_pc=0x0c0a7d76u; return 0; }
r[0]=0x00000018u;
goto P_0c0a7d78;
P_0c0a7d78: /* original 00ec, guest PC 0x0c0a7d78 */
if(!s->budget--) { s->failed_pc=0x0c0a7d78u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0a7d7a;
P_0c0a7d7a: /* original 600c, guest PC 0x0c0a7d7a */
if(!s->budget--) { s->failed_pc=0x0c0a7d7au; return 0; }
r[0]=r[0]&255u;
goto P_0c0a7d7c;
P_0c0a7d7c: /* original 8801, guest PC 0x0c0a7d7c */
if(!s->budget--) { s->failed_pc=0x0c0a7d7cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c0a7d7e;
P_0c0a7d7e: /* original 8f04, guest PC 0x0c0a7d7e */
if(!s->budget--) { s->failed_pc=0x0c0a7d7eu; return 0; }
cond=r[17]&1u;
r[7]=r[7]&65535u;
if(!cond) { goto P_0c0a7d8a; }
goto P_0c0a7d82;
P_0c0a7d80: /* original 677d, guest PC 0x0c0a7d80 */
if(!s->budget--) { s->failed_pc=0x0c0a7d80u; return 0; }
r[7]=r[7]&65535u;
goto P_0c0a7d82;
P_0c0a7d82: /* original e300, guest PC 0x0c0a7d82 */
if(!s->budget--) { s->failed_pc=0x0c0a7d82u; return 0; }
r[3]=0x00000000u;
goto P_0c0a7d84;
P_0c0a7d84: /* original 3377, guest PC 0x0c0a7d84 */
if(!s->budget--) { s->failed_pc=0x0c0a7d84u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>(int32_t)r[7])!=0);
goto P_0c0a7d86;
P_0c0a7d86: /* original 373e, guest PC 0x0c0a7d86 */
if(!s->budget--) { s->failed_pc=0x0c0a7d86u; return 0; }
wide=(uint64_t)r[7]+r[3]+(r[17]&1u); r[7]=(uint32_t)wide;
r[17]=(r[17]&~1u)|((wide>>32)!=0);
goto P_0c0a7d88;
P_0c0a7d88: /* original 4721, guest PC 0x0c0a7d88 */
if(!s->budget--) { s->failed_pc=0x0c0a7d88u; return 0; }
r[17]=(r[17]&~1u)|((r[7]&1)!=0);
r[7]=(uint32_t)((int32_t)r[7]>>1);
goto P_0c0a7d8a;
P_0c0a7d8a: /* original e018, guest PC 0x0c0a7d8a */
if(!s->budget--) { s->failed_pc=0x0c0a7d8au; return 0; }
r[0]=0x00000018u;
goto P_0c0a7d8c;
P_0c0a7d8c: /* original 02ec, guest PC 0x0c0a7d8c */
if(!s->budget--) { s->failed_pc=0x0c0a7d8cu; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0a7d8e;
P_0c0a7d8e: /* original 2228, guest PC 0x0c0a7d8e */
if(!s->budget--) { s->failed_pc=0x0c0a7d8eu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c0a7d90;
P_0c0a7d90: /* original 8f08, guest PC 0x0c0a7d90 */
if(!s->budget--) { s->failed_pc=0x0c0a7d90u; return 0; }
cond=r[17]&1u;
r[13]+=r[7];
if(!cond) { goto P_0c0a7da4; }
goto P_0c0a7d94;
P_0c0a7d92: /* original 3d7c, guest PC 0x0c0a7d92 */
if(!s->budget--) { s->failed_pc=0x0c0a7d92u; return 0; }
r[13]+=r[7];
goto P_0c0a7d94;
P_0c0a7d94: /* original e046, guest PC 0x0c0a7d94 */
if(!s->budget--) { s->failed_pc=0x0c0a7d94u; return 0; }
r[0]=0x00000046u;
goto P_0c0a7d96;
P_0c0a7d96: /* original 014d, guest PC 0x0c0a7d96 */
if(!s->budget--) { s->failed_pc=0x0c0a7d96u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c0a7d98;
P_0c0a7d98: /* original 9052, guest PC 0x0c0a7d98 */
if(!s->budget--) { s->failed_pc=0x0c0a7d98u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a7e40u,2);
goto P_0c0a7d9a;
P_0c0a7d9a: /* original 611d, guest PC 0x0c0a7d9a */
if(!s->budget--) { s->failed_pc=0x0c0a7d9au; return 0; }
r[1]=r[1]&65535u;
goto P_0c0a7d9c;
P_0c0a7d9c: /* original 034d, guest PC 0x0c0a7d9c */
if(!s->budget--) { s->failed_pc=0x0c0a7d9cu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c0a7d9e;
P_0c0a7d9e: /* original 3130, guest PC 0x0c0a7d9e */
if(!s->budget--) { s->failed_pc=0x0c0a7d9eu; return 0; }
r[17]=(r[17]&~1u)|((r[1]==r[3])!=0);
goto P_0c0a7da0;
P_0c0a7da0: /* original 8b00, guest PC 0x0c0a7da0 */
if(!s->budget--) { s->failed_pc=0x0c0a7da0u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a7da4; }
goto P_0c0a7da2;
P_0c0a7da2: /* original 7d64, guest PC 0x0c0a7da2 */
if(!s->budget--) { s->failed_pc=0x0c0a7da2u; return 0; }
r[13]+=0x00000064u;
goto P_0c0a7da4;
P_0c0a7da4: /* original e21e, guest PC 0x0c0a7da4 */
if(!s->budget--) { s->failed_pc=0x0c0a7da4u; return 0; }
r[2]=0x0000001eu;
goto P_0c0a7da6;
P_0c0a7da6: /* original 3278, guest PC 0x0c0a7da6 */
if(!s->budget--) { s->failed_pc=0x0c0a7da6u; return 0; }
r[2]-=r[7];
goto P_0c0a7da8;
P_0c0a7da8: /* original 4215, guest PC 0x0c0a7da8 */
if(!s->budget--) { s->failed_pc=0x0c0a7da8u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[2]>0)!=0);
goto P_0c0a7daa;
P_0c0a7daa: /* original 8b06, guest PC 0x0c0a7daa */
if(!s->budget--) { s->failed_pc=0x0c0a7daau; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a7dba; }
goto P_0c0a7dac;
P_0c0a7dac: /* original d228, guest PC 0x0c0a7dac */
if(!s->budget--) { s->failed_pc=0x0c0a7dacu; return 0; }
r[2]=read(ram,0x0c0a7e50u,4);
goto P_0c0a7dae;
P_0c0a7dae: /* original 51e5, guest PC 0x0c0a7dae */
if(!s->budget--) { s->failed_pc=0x0c0a7daeu; return 0; }
r[1]=read(ram,r[14]+20,4);
goto P_0c0a7db0;
P_0c0a7db0: /* original 420b, guest PC 0x0c0a7db0 */
if(!s->budget--) { s->failed_pc=0x0c0a7db0u; return 0; }
target=r[2];
r[16]=code_base|0x0c0a7db4u;
r[0]=r[6];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a7db4u) { target=s->pc; goto dispatch; }
goto P_0c0a7db4;
P_0c0a7db2: /* original 6063, guest PC 0x0c0a7db2 */
if(!s->budget--) { s->failed_pc=0x0c0a7db2u; return 0; }
r[0]=r[6];
goto P_0c0a7db4;
P_0c0a7db4: /* original d727, guest PC 0x0c0a7db4 */
if(!s->budget--) { s->failed_pc=0x0c0a7db4u; return 0; }
r[7]=read(ram,0x0c0a7e54u,4);
goto P_0c0a7db6;
P_0c0a7db6: /* original 2709, guest PC 0x0c0a7db6 */
if(!s->budget--) { s->failed_pc=0x0c0a7db6u; return 0; }
r[7]&=r[0];
goto P_0c0a7db8;
P_0c0a7db8: /* original 3d7c, guest PC 0x0c0a7db8 */
if(!s->budget--) { s->failed_pc=0x0c0a7db8u; return 0; }
r[13]+=r[7];
goto P_0c0a7dba;
P_0c0a7dba: /* original 9042, guest PC 0x0c0a7dba */
if(!s->budget--) { s->failed_pc=0x0c0a7dbau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a7e42u,2);
goto P_0c0a7dbc;
P_0c0a7dbc: /* original 0ed5, guest PC 0x0c0a7dbc */
if(!s->budget--) { s->failed_pc=0x0c0a7dbcu; return 0; }
write(ram,r[14]+r[0],r[13],2);
goto P_0c0a7dbe;
P_0c0a7dbe: /* original 5ce2, guest PC 0x0c0a7dbe */
if(!s->budget--) { s->failed_pc=0x0c0a7dbeu; return 0; }
r[12]=read(ram,r[14]+8,4);
goto P_0c0a7dc0;
P_0c0a7dc0: /* original d325, guest PC 0x0c0a7dc0 */
if(!s->budget--) { s->failed_pc=0x0c0a7dc0u; return 0; }
r[3]=read(ram,0x0c0a7e58u,4);
goto P_0c0a7dc2;
P_0c0a7dc2: /* original 23c8, guest PC 0x0c0a7dc2 */
if(!s->budget--) { s->failed_pc=0x0c0a7dc2u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[12])==0)!=0);
goto P_0c0a7dc4;
P_0c0a7dc4: /* original 8930, guest PC 0x0c0a7dc4 */
if(!s->budget--) { s->failed_pc=0x0c0a7dc4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a7e28; }
goto P_0c0a7dc6;
P_0c0a7dc6: /* original e01c, guest PC 0x0c0a7dc6 */
if(!s->budget--) { s->failed_pc=0x0c0a7dc6u; return 0; }
r[0]=0x0000001cu;
goto P_0c0a7dc8;
P_0c0a7dc8: /* original 0aec, guest PC 0x0c0a7dc8 */
if(!s->budget--) { s->failed_pc=0x0c0a7dc8u; return 0; }
r[10]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0a7dca;
P_0c0a7dca: /* original 4d00, guest PC 0x0c0a7dca */
if(!s->budget--) { s->failed_pc=0x0c0a7dcau; return 0; }
r[17]=(r[17]&~1u)|((r[13]>>31)!=0);
r[13]<<=1;
goto P_0c0a7dcc;
P_0c0a7dcc: /* original 6aac, guest PC 0x0c0a7dcc */
if(!s->budget--) { s->failed_pc=0x0c0a7dccu; return 0; }
r[10]=r[10]&255u;
goto P_0c0a7dce;
P_0c0a7dce: /* original 60a3, guest PC 0x0c0a7dce */
if(!s->budget--) { s->failed_pc=0x0c0a7dceu; return 0; }
r[0]=r[10];
goto P_0c0a7dd0;
P_0c0a7dd0: /* original 8801, guest PC 0x0c0a7dd0 */
if(!s->budget--) { s->failed_pc=0x0c0a7dd0u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c0a7dd2;
P_0c0a7dd2: /* original 8f01, guest PC 0x0c0a7dd2 */
if(!s->budget--) { s->failed_pc=0x0c0a7dd2u; return 0; }
cond=r[17]&1u;
r[7]=r[10];
if(!cond) { goto P_0c0a7dd8; }
goto P_0c0a7dd6;
P_0c0a7dd4: /* original 67a3, guest PC 0x0c0a7dd4 */
if(!s->budget--) { s->failed_pc=0x0c0a7dd4u; return 0; }
r[7]=r[10];
goto P_0c0a7dd6;
P_0c0a7dd6: /* original 7701, guest PC 0x0c0a7dd6 */
if(!s->budget--) { s->failed_pc=0x0c0a7dd6u; return 0; }
r[7]+=0x00000001u;
goto P_0c0a7dd8;
P_0c0a7dd8: /* original d21d, guest PC 0x0c0a7dd8 */
if(!s->budget--) { s->failed_pc=0x0c0a7dd8u; return 0; }
r[2]=read(ram,0x0c0a7e50u,4);
goto P_0c0a7dda;
P_0c0a7dda: /* original 61d3, guest PC 0x0c0a7dda */
if(!s->budget--) { s->failed_pc=0x0c0a7ddau; return 0; }
r[1]=r[13];
goto P_0c0a7ddc;
P_0c0a7ddc: /* original 420b, guest PC 0x0c0a7ddc */
if(!s->budget--) { s->failed_pc=0x0c0a7ddcu; return 0; }
target=r[2];
r[16]=code_base|0x0c0a7de0u;
r[0]=r[7];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a7de0u) { target=s->pc; goto dispatch; }
goto P_0c0a7de0;
P_0c0a7dde: /* original 6073, guest PC 0x0c0a7dde */
if(!s->budget--) { s->failed_pc=0x0c0a7ddeu; return 0; }
r[0]=r[7];
goto P_0c0a7de0;
P_0c0a7de0: /* original 6d03, guest PC 0x0c0a7de0 */
if(!s->budget--) { s->failed_pc=0x0c0a7de0u; return 0; }
r[13]=r[0];
goto P_0c0a7de2;
P_0c0a7de2: /* original e02b, guest PC 0x0c0a7de2 */
if(!s->budget--) { s->failed_pc=0x0c0a7de2u; return 0; }
r[0]=0x0000002bu;
goto P_0c0a7de4;
P_0c0a7de4: /* original 53ef, guest PC 0x0c0a7de4 */
if(!s->budget--) { s->failed_pc=0x0c0a7de4u; return 0; }
r[3]=read(ram,r[14]+60,4);
goto P_0c0a7de6;
P_0c0a7de6: /* original 2f32, guest PC 0x0c0a7de6 */
if(!s->budget--) { s->failed_pc=0x0c0a7de6u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c0a7de8;
P_0c0a7de8: /* original 07ec, guest PC 0x0c0a7de8 */
if(!s->budget--) { s->failed_pc=0x0c0a7de8u; return 0; }
r[7]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0a7dea;
P_0c0a7dea: /* original 3678, guest PC 0x0c0a7dea */
if(!s->budget--) { s->failed_pc=0x0c0a7deau; return 0; }
r[6]-=r[7];
goto P_0c0a7dec;
P_0c0a7dec: /* original 1f61, guest PC 0x0c0a7dec */
if(!s->budget--) { s->failed_pc=0x0c0a7decu; return 0; }
write(ram,r[15]+4,r[6],4);
goto P_0c0a7dee;
P_0c0a7dee: /* original 9029, guest PC 0x0c0a7dee */
if(!s->budget--) { s->failed_pc=0x0c0a7deeu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a7e44u,2);
goto P_0c0a7df0;
P_0c0a7df0: /* original 63f2, guest PC 0x0c0a7df0 */
if(!s->budget--) { s->failed_pc=0x0c0a7df0u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c0a7df2;
P_0c0a7df2: /* original 06ed, guest PC 0x0c0a7df2 */
if(!s->budget--) { s->failed_pc=0x0c0a7df2u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0a7df4;
P_0c0a7df4: /* original 3a30, guest PC 0x0c0a7df4 */
if(!s->budget--) { s->failed_pc=0x0c0a7df4u; return 0; }
r[17]=(r[17]&~1u)|((r[10]==r[3])!=0);
goto P_0c0a7df6;
P_0c0a7df6: /* original 8b04, guest PC 0x0c0a7df6 */
if(!s->budget--) { s->failed_pc=0x0c0a7df6u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a7e02; }
goto P_0c0a7df8;
P_0c0a7df8: /* original 53f1, guest PC 0x0c0a7df8 */
if(!s->budget--) { s->failed_pc=0x0c0a7df8u; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c0a7dfa;
P_0c0a7dfa: /* original d218, guest PC 0x0c0a7dfa */
if(!s->budget--) { s->failed_pc=0x0c0a7dfau; return 0; }
r[2]=read(ram,0x0c0a7e5cu,4);
goto P_0c0a7dfc;
P_0c0a7dfc: /* original 633b, guest PC 0x0c0a7dfc */
if(!s->budget--) { s->failed_pc=0x0c0a7dfcu; return 0; }
r[3]=0u-r[3];
goto P_0c0a7dfe;
P_0c0a7dfe: /* original 423d, guest PC 0x0c0a7dfe */
if(!s->budget--) { s->failed_pc=0x0c0a7dfeu; return 0; }
r[2]=(r[3]&0x80000000u)?((r[3]&31u)?r[2]>>((-r[3])&31u):0):r[2]<<(r[3]&31u);
goto P_0c0a7e00;
P_0c0a7e00: /* original 262b, guest PC 0x0c0a7e00 */
if(!s->budget--) { s->failed_pc=0x0c0a7e00u; return 0; }
r[6]|=r[2];
goto P_0c0a7e02;
P_0c0a7e02: /* original e310, guest PC 0x0c0a7e02 */
if(!s->budget--) { s->failed_pc=0x0c0a7e02u; return 0; }
r[3]=0x00000010u;
goto P_0c0a7e04;
P_0c0a7e04: /* original 901e, guest PC 0x0c0a7e04 */
if(!s->budget--) { s->failed_pc=0x0c0a7e04u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a7e44u,2);
goto P_0c0a7e06;
P_0c0a7e06: /* original 2c38, guest PC 0x0c0a7e06 */
if(!s->budget--) { s->failed_pc=0x0c0a7e06u; return 0; }
r[17]=(r[17]&~1u)|(((r[12]&r[3])==0)!=0);
goto P_0c0a7e08;
P_0c0a7e08: /* original 8d02, guest PC 0x0c0a7e08 */
if(!s->budget--) { s->failed_pc=0x0c0a7e08u; return 0; }
cond=r[17]&1u;
write(ram,r[14]+r[0],r[6],2);
if(cond) { goto P_0c0a7e10; }
goto P_0c0a7e0c;
P_0c0a7e0a: /* original 0e65, guest PC 0x0c0a7e0a */
if(!s->budget--) { s->failed_pc=0x0c0a7e0au; return 0; }
write(ram,r[14]+r[0],r[6],2);
goto P_0c0a7e0c;
P_0c0a7e0c: /* original 921b, guest PC 0x0c0a7e0c */
if(!s->budget--) { s->failed_pc=0x0c0a7e0cu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a7e46u,2);
goto P_0c0a7e0e;
P_0c0a7e0e: /* original 3d2c, guest PC 0x0c0a7e0e */
if(!s->budget--) { s->failed_pc=0x0c0a7e0eu; return 0; }
r[13]+=r[2];
goto P_0c0a7e10;
P_0c0a7e10: /* original 9015, guest PC 0x0c0a7e10 */
if(!s->budget--) { s->failed_pc=0x0c0a7e10u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a7e3eu,2);
goto P_0c0a7e12;
P_0c0a7e12: /* original 03ee, guest PC 0x0c0a7e12 */
if(!s->budget--) { s->failed_pc=0x0c0a7e12u; return 0; }
r[3]=read(ram,r[14]+r[0],4);
goto P_0c0a7e14;
P_0c0a7e14: /* original 3340, guest PC 0x0c0a7e14 */
if(!s->budget--) { s->failed_pc=0x0c0a7e14u; return 0; }
r[17]=(r[17]&~1u)|((r[3]==r[4])!=0);
goto P_0c0a7e16;
P_0c0a7e16: /* original 8b01, guest PC 0x0c0a7e16 */
if(!s->budget--) { s->failed_pc=0x0c0a7e16u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a7e1c; }
goto P_0c0a7e18;
P_0c0a7e18: /* original 9016, guest PC 0x0c0a7e18 */
if(!s->budget--) { s->failed_pc=0x0c0a7e18u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a7e48u,2);
goto P_0c0a7e1a;
P_0c0a7e1a: /* original 0e74, guest PC 0x0c0a7e1a */
if(!s->budget--) { s->failed_pc=0x0c0a7e1au; return 0; }
write(ram,r[14]+r[0],r[7],1);
goto P_0c0a7e1c;
P_0c0a7e1c: /* original 9015, guest PC 0x0c0a7e1c */
if(!s->budget--) { s->failed_pc=0x0c0a7e1cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a7e4au,2);
goto P_0c0a7e1e;
P_0c0a7e1e: /* original 03ed, guest PC 0x0c0a7e1e */
if(!s->budget--) { s->failed_pc=0x0c0a7e1eu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0a7e20;
P_0c0a7e20: /* original 3d3c, guest PC 0x0c0a7e20 */
if(!s->budget--) { s->failed_pc=0x0c0a7e20u; return 0; }
r[13]+=r[3];
goto P_0c0a7e22;
P_0c0a7e22: /* original 0ed5, guest PC 0x0c0a7e22 */
if(!s->budget--) { s->failed_pc=0x0c0a7e22u; return 0; }
write(ram,r[14]+r[0],r[13],2);
goto P_0c0a7e24;
P_0c0a7e24: /* original 900d, guest PC 0x0c0a7e24 */
if(!s->budget--) { s->failed_pc=0x0c0a7e24u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a7e42u,2);
goto P_0c0a7e26;
P_0c0a7e26: /* original 0eb5, guest PC 0x0c0a7e26 */
if(!s->budget--) { s->failed_pc=0x0c0a7e26u; return 0; }
write(ram,r[14]+r[0],r[11],2);
goto P_0c0a7e28;
P_0c0a7e28: /* original 7f08, guest PC 0x0c0a7e28 */
if(!s->budget--) { s->failed_pc=0x0c0a7e28u; return 0; }
r[15]+=0x00000008u;
goto P_0c0a7e2a;
P_0c0a7e2a: /* original 900f, guest PC 0x0c0a7e2a */
if(!s->budget--) { s->failed_pc=0x0c0a7e2au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a7e4cu,2);
goto P_0c0a7e2c;
P_0c0a7e2c: /* original 4f16, guest PC 0x0c0a7e2c */
if(!s->budget--) { s->failed_pc=0x0c0a7e2cu; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a7e2e;
P_0c0a7e2e: /* original 05b5, guest PC 0x0c0a7e2e */
if(!s->budget--) { s->failed_pc=0x0c0a7e2eu; return 0; }
write(ram,r[5]+r[0],r[11],2);
goto P_0c0a7e30;
P_0c0a7e30: /* original 4f26, guest PC 0x0c0a7e30 */
if(!s->budget--) { s->failed_pc=0x0c0a7e30u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a7e32;
P_0c0a7e32: /* original 6af6, guest PC 0x0c0a7e32 */
if(!s->budget--) { s->failed_pc=0x0c0a7e32u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0a7e34;
P_0c0a7e34: /* original 6bf6, guest PC 0x0c0a7e34 */
if(!s->budget--) { s->failed_pc=0x0c0a7e34u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0a7e36;
P_0c0a7e36: /* original 6cf6, guest PC 0x0c0a7e36 */
if(!s->budget--) { s->failed_pc=0x0c0a7e36u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0a7e38;
P_0c0a7e38: /* original 6df6, guest PC 0x0c0a7e38 */
if(!s->budget--) { s->failed_pc=0x0c0a7e38u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0a7e3a;
P_0c0a7e3a: /* original 000b, guest PC 0x0c0a7e3a */
if(!s->budget--) { s->failed_pc=0x0c0a7e3au; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0a7e3c: /* original 6ef6, guest PC 0x0c0a7e3c */
if(!s->budget--) { s->failed_pc=0x0c0a7e3cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0a7e3eu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0a7e3eu; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
