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
int vf3_away_batch179_adapter_15(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c09a39cu: goto P_0c09a39c;
case 0x0c09a39eu: goto P_0c09a39e;
case 0x0c09a3a0u: goto P_0c09a3a0;
case 0x0c09a3a2u: goto P_0c09a3a2;
case 0x0c09a3a4u: goto P_0c09a3a4;
case 0x0c09a3a6u: goto P_0c09a3a6;
case 0x0c09a3a8u: goto P_0c09a3a8;
case 0x0c09a3aau: goto P_0c09a3aa;
case 0x0c09a3acu: goto P_0c09a3ac;
case 0x0c09a3aeu: goto P_0c09a3ae;
case 0x0c09a3b0u: goto P_0c09a3b0;
case 0x0c09a3b2u: goto P_0c09a3b2;
case 0x0c09a3b4u: goto P_0c09a3b4;
case 0x0c09a3b6u: goto P_0c09a3b6;
case 0x0c09a3b8u: goto P_0c09a3b8;
case 0x0c09a3bau: goto P_0c09a3ba;
case 0x0c09a3bcu: goto P_0c09a3bc;
case 0x0c09a3beu: goto P_0c09a3be;
case 0x0c09a3c0u: goto P_0c09a3c0;
case 0x0c09a3c2u: goto P_0c09a3c2;
case 0x0c09a3c4u: goto P_0c09a3c4;
case 0x0c09a3c6u: goto P_0c09a3c6;
case 0x0c09a3c8u: goto P_0c09a3c8;
case 0x0c09a3cau: goto P_0c09a3ca;
case 0x0c09a3ccu: goto P_0c09a3cc;
case 0x0c09a3ceu: goto P_0c09a3ce;
case 0x0c09a3d0u: goto P_0c09a3d0;
case 0x0c09a3d2u: goto P_0c09a3d2;
case 0x0c09a3d4u: goto P_0c09a3d4;
case 0x0c09a3d6u: goto P_0c09a3d6;
case 0x0c09a3d8u: goto P_0c09a3d8;
case 0x0c09a3dau: goto P_0c09a3da;
case 0x0c09a3dcu: goto P_0c09a3dc;
case 0x0c09a3deu: goto P_0c09a3de;
case 0x0c09a3e0u: goto P_0c09a3e0;
case 0x0c09a3e2u: goto P_0c09a3e2;
case 0x0c09a3e4u: goto P_0c09a3e4;
case 0x0c09a3e6u: goto P_0c09a3e6;
case 0x0c09a3e8u: goto P_0c09a3e8;
case 0x0c09a3eau: goto P_0c09a3ea;
case 0x0c09a3ecu: goto P_0c09a3ec;
case 0x0c09a3eeu: goto P_0c09a3ee;
case 0x0c09a3f0u: goto P_0c09a3f0;
case 0x0c09a3f2u: goto P_0c09a3f2;
case 0x0c09a3f4u: goto P_0c09a3f4;
case 0x0c09a3f6u: goto P_0c09a3f6;
case 0x0c09a3f8u: goto P_0c09a3f8;
case 0x0c09a3fau: goto P_0c09a3fa;
case 0x0c09a3fcu: goto P_0c09a3fc;
case 0x0c09a3feu: goto P_0c09a3fe;
case 0x0c09a400u: goto P_0c09a400;
case 0x0c09a402u: goto P_0c09a402;
case 0x0c09a404u: goto P_0c09a404;
case 0x0c09a406u: goto P_0c09a406;
case 0x0c09a408u: goto P_0c09a408;
case 0x0c09a40au: goto P_0c09a40a;
case 0x0c09a40cu: goto P_0c09a40c;
case 0x0c09a40eu: goto P_0c09a40e;
case 0x0c09a410u: goto P_0c09a410;
case 0x0c09a412u: goto P_0c09a412;
case 0x0c09a414u: goto P_0c09a414;
case 0x0c09a416u: goto P_0c09a416;
case 0x0c09a418u: goto P_0c09a418;
case 0x0c09a41au: goto P_0c09a41a;
case 0x0c09a41cu: goto P_0c09a41c;
case 0x0c09a41eu: goto P_0c09a41e;
case 0x0c09a420u: goto P_0c09a420;
case 0x0c09a422u: goto P_0c09a422;
case 0x0c09a424u: goto P_0c09a424;
case 0x0c09a426u: goto P_0c09a426;
case 0x0c09a428u: goto P_0c09a428;
case 0x0c09a42au: goto P_0c09a42a;
case 0x0c09a42cu: goto P_0c09a42c;
case 0x0c09a42eu: goto P_0c09a42e;
case 0x0c09a430u: goto P_0c09a430;
case 0x0c09a432u: goto P_0c09a432;
case 0x0c09a434u: goto P_0c09a434;
case 0x0c09a436u: goto P_0c09a436;
case 0x0c09a438u: goto P_0c09a438;
case 0x0c09a43au: goto P_0c09a43a;
case 0x0c09a43cu: goto P_0c09a43c;
case 0x0c09a43eu: goto P_0c09a43e;
case 0x0c09a440u: goto P_0c09a440;
case 0x0c09a442u: goto P_0c09a442;
case 0x0c09a444u: goto P_0c09a444;
case 0x0c09a446u: goto P_0c09a446;
case 0x0c09a448u: goto P_0c09a448;
case 0x0c09a44au: goto P_0c09a44a;
case 0x0c09a44cu: goto P_0c09a44c;
case 0x0c09a44eu: goto P_0c09a44e;
case 0x0c09a450u: goto P_0c09a450;
case 0x0c09a452u: goto P_0c09a452;
case 0x0c09a454u: goto P_0c09a454;
case 0x0c09a456u: goto P_0c09a456;
case 0x0c09a458u: goto P_0c09a458;
case 0x0c09a45au: goto P_0c09a45a;
case 0x0c09a45cu: goto P_0c09a45c;
case 0x0c09a45eu: goto P_0c09a45e;
case 0x0c09a460u: goto P_0c09a460;
case 0x0c09a462u: goto P_0c09a462;
case 0x0c09a464u: goto P_0c09a464;
case 0x0c09a466u: goto P_0c09a466;
case 0x0c09a468u: goto P_0c09a468;
case 0x0c09a46au: goto P_0c09a46a;
case 0x0c09a46cu: goto P_0c09a46c;
case 0x0c09a46eu: goto P_0c09a46e;
case 0x0c09a470u: goto P_0c09a470;
case 0x0c09a472u: goto P_0c09a472;
case 0x0c09a474u: goto P_0c09a474;
case 0x0c09a476u: goto P_0c09a476;
case 0x0c09a478u: goto P_0c09a478;
case 0x0c09a47au: goto P_0c09a47a;
case 0x0c09a47cu: goto P_0c09a47c;
case 0x0c09a47eu: goto P_0c09a47e;
case 0x0c09a480u: goto P_0c09a480;
case 0x0c09a482u: goto P_0c09a482;
case 0x0c09a484u: goto P_0c09a484;
case 0x0c09a486u: goto P_0c09a486;
case 0x0c09a488u: goto P_0c09a488;
case 0x0c09a48au: goto P_0c09a48a;
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
case 0x0c0a7a0cu: goto P_0c0a7a0c;
case 0x0c0a7a0eu: goto P_0c0a7a0e;
case 0x0c0a7a10u: goto P_0c0a7a10;
case 0x0c0a7a12u: goto P_0c0a7a12;
case 0x0c0a7a14u: goto P_0c0a7a14;
case 0x0c0a7a16u: goto P_0c0a7a16;
case 0x0c0a7a18u: goto P_0c0a7a18;
case 0x0c0a7a1au: goto P_0c0a7a1a;
case 0x0c0a7a1cu: goto P_0c0a7a1c;
case 0x0c0a7a1eu: goto P_0c0a7a1e;
case 0x0c0a7a20u: goto P_0c0a7a20;
case 0x0c0a7a22u: goto P_0c0a7a22;
case 0x0c0a7a24u: goto P_0c0a7a24;
case 0x0c0a7a26u: goto P_0c0a7a26;
case 0x0c0a7a28u: goto P_0c0a7a28;
case 0x0c0a7a2au: goto P_0c0a7a2a;
case 0x0c0a7a2cu: goto P_0c0a7a2c;
case 0x0c0a7a2eu: goto P_0c0a7a2e;
case 0x0c0a7a30u: goto P_0c0a7a30;
case 0x0c0a7a32u: goto P_0c0a7a32;
case 0x0c0a7a34u: goto P_0c0a7a34;
case 0x0c0a7a36u: goto P_0c0a7a36;
case 0x0c0a7a38u: goto P_0c0a7a38;
case 0x0c0a7a3au: goto P_0c0a7a3a;
case 0x0c0a7a3cu: goto P_0c0a7a3c;
case 0x0c0a7a3eu: goto P_0c0a7a3e;
case 0x0c0a7a40u: goto P_0c0a7a40;
case 0x0c0a7a42u: goto P_0c0a7a42;
case 0x0c0a7a44u: goto P_0c0a7a44;
case 0x0c0a7a46u: goto P_0c0a7a46;
case 0x0c0a7a48u: goto P_0c0a7a48;
case 0x0c0a7a4au: goto P_0c0a7a4a;
case 0x0c0a7a4cu: goto P_0c0a7a4c;
case 0x0c0a7a4eu: goto P_0c0a7a4e;
case 0x0c0a7a50u: goto P_0c0a7a50;
case 0x0c0a7a52u: goto P_0c0a7a52;
case 0x0c0a7a54u: goto P_0c0a7a54;
case 0x0c0a7a56u: goto P_0c0a7a56;
case 0x0c0a7a58u: goto P_0c0a7a58;
case 0x0c0a7a5au: goto P_0c0a7a5a;
case 0x0c0a7a5cu: goto P_0c0a7a5c;
case 0x0c0a7a5eu: goto P_0c0a7a5e;
case 0x0c0a7a60u: goto P_0c0a7a60;
case 0x0c0a7a62u: goto P_0c0a7a62;
case 0x0c0a7a64u: goto P_0c0a7a64;
case 0x0c0a7a66u: goto P_0c0a7a66;
case 0x0c0a7a68u: goto P_0c0a7a68;
case 0x0c0a7a6au: goto P_0c0a7a6a;
case 0x0c0a7a6cu: goto P_0c0a7a6c;
case 0x0c0a7a6eu: goto P_0c0a7a6e;
case 0x0c0a7a70u: goto P_0c0a7a70;
case 0x0c0a7a72u: goto P_0c0a7a72;
case 0x0c0a7a74u: goto P_0c0a7a74;
case 0x0c0a7a76u: goto P_0c0a7a76;
case 0x0c0a7a78u: goto P_0c0a7a78;
case 0x0c0a7a7au: goto P_0c0a7a7a;
case 0x0c0a7a7cu: goto P_0c0a7a7c;
case 0x0c0a7a7eu: goto P_0c0a7a7e;
case 0x0c0a7a80u: goto P_0c0a7a80;
case 0x0c0a7a82u: goto P_0c0a7a82;
case 0x0c0a7a84u: goto P_0c0a7a84;
case 0x0c0a7a86u: goto P_0c0a7a86;
case 0x0c0a7a88u: goto P_0c0a7a88;
case 0x0c0a7a8au: goto P_0c0a7a8a;
case 0x0c0a7a8cu: goto P_0c0a7a8c;
case 0x0c0a7a8eu: goto P_0c0a7a8e;
case 0x0c0a7a90u: goto P_0c0a7a90;
case 0x0c0a7a92u: goto P_0c0a7a92;
case 0x0c0a7a94u: goto P_0c0a7a94;
case 0x0c0a7a96u: goto P_0c0a7a96;
case 0x0c0a7a98u: goto P_0c0a7a98;
case 0x0c0a7a9au: goto P_0c0a7a9a;
case 0x0c0a7a9cu: goto P_0c0a7a9c;
case 0x0c0a7a9eu: goto P_0c0a7a9e;
case 0x0c0a7aa0u: goto P_0c0a7aa0;
case 0x0c0a7aa2u: goto P_0c0a7aa2;
case 0x0c0a7ae0u: goto P_0c0a7ae0;
case 0x0c0a7ae2u: goto P_0c0a7ae2;
case 0x0c0a7ae4u: goto P_0c0a7ae4;
case 0x0c0a7ae6u: goto P_0c0a7ae6;
case 0x0c0a7ae8u: goto P_0c0a7ae8;
case 0x0c0a7aeau: goto P_0c0a7aea;
case 0x0c0a7aecu: goto P_0c0a7aec;
case 0x0c0a7aeeu: goto P_0c0a7aee;
case 0x0c0a7af0u: goto P_0c0a7af0;
case 0x0c0a7af2u: goto P_0c0a7af2;
case 0x0c0a7af4u: goto P_0c0a7af4;
case 0x0c0a7af6u: goto P_0c0a7af6;
case 0x0c0a7af8u: goto P_0c0a7af8;
case 0x0c0a7afau: goto P_0c0a7afa;
case 0x0c0a7afcu: goto P_0c0a7afc;
case 0x0c0a7afeu: goto P_0c0a7afe;
case 0x0c0a7b00u: goto P_0c0a7b00;
case 0x0c0a7b02u: goto P_0c0a7b02;
case 0x0c0a7b04u: goto P_0c0a7b04;
case 0x0c0a7b06u: goto P_0c0a7b06;
case 0x0c0a7b08u: goto P_0c0a7b08;
case 0x0c0a7b0au: goto P_0c0a7b0a;
case 0x0c0a7b0cu: goto P_0c0a7b0c;
case 0x0c0a7b0eu: goto P_0c0a7b0e;
case 0x0c0a7b10u: goto P_0c0a7b10;
case 0x0c0a7b12u: goto P_0c0a7b12;
case 0x0c0a7b14u: goto P_0c0a7b14;
case 0x0c0a7b16u: goto P_0c0a7b16;
case 0x0c0a7b18u: goto P_0c0a7b18;
case 0x0c0a7f14u: goto P_0c0a7f14;
case 0x0c0a7f16u: goto P_0c0a7f16;
case 0x0c0a7f18u: goto P_0c0a7f18;
case 0x0c0a7f1au: goto P_0c0a7f1a;
case 0x0c0a7f1cu: goto P_0c0a7f1c;
case 0x0c0a7f1eu: goto P_0c0a7f1e;
case 0x0c0a7f20u: goto P_0c0a7f20;
case 0x0c0a7f22u: goto P_0c0a7f22;
case 0x0c0a7f24u: goto P_0c0a7f24;
case 0x0c0a7f26u: goto P_0c0a7f26;
case 0x0c0a7f28u: goto P_0c0a7f28;
case 0x0c0a7f2au: goto P_0c0a7f2a;
case 0x0c0a7f2cu: goto P_0c0a7f2c;
case 0x0c0a7f2eu: goto P_0c0a7f2e;
case 0x0c0a7f30u: goto P_0c0a7f30;
case 0x0c0a7f32u: goto P_0c0a7f32;
case 0x0c0a7f34u: goto P_0c0a7f34;
case 0x0c0a7f36u: goto P_0c0a7f36;
case 0x0c0a7f38u: goto P_0c0a7f38;
case 0x0c0a7f3au: goto P_0c0a7f3a;
case 0x0c0a7f3cu: goto P_0c0a7f3c;
case 0x0c0a7f3eu: goto P_0c0a7f3e;
case 0x0c0a7f40u: goto P_0c0a7f40;
case 0x0c0a7f42u: goto P_0c0a7f42;
case 0x0c0a7f44u: goto P_0c0a7f44;
case 0x0c0a7f46u: goto P_0c0a7f46;
case 0x0c0a7f48u: goto P_0c0a7f48;
case 0x0c0a7f4au: goto P_0c0a7f4a;
case 0x0c0a7f4cu: goto P_0c0a7f4c;
case 0x0c0a7f4eu: goto P_0c0a7f4e;
case 0x0c0a7f50u: goto P_0c0a7f50;
case 0x0c0a7f52u: goto P_0c0a7f52;
case 0x0c0a7f54u: goto P_0c0a7f54;
default: return vf3_matrix_family(target,s,ram);
}
P_0c09a39c: /* original 2fe6, guest PC 0x0c09a39c */
if(!s->budget--) { s->failed_pc=0x0c09a39cu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09a39e;
P_0c09a39e: /* original e600, guest PC 0x0c09a39e */
if(!s->budget--) { s->failed_pc=0x0c09a39eu; return 0; }
r[6]=0x00000000u;
goto P_0c09a3a0;
P_0c09a3a0: /* original 2fd6, guest PC 0x0c09a3a0 */
if(!s->budget--) { s->failed_pc=0x0c09a3a0u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09a3a2;
P_0c09a3a2: /* original 6563, guest PC 0x0c09a3a2 */
if(!s->budget--) { s->failed_pc=0x0c09a3a2u; return 0; }
r[5]=r[6];
goto P_0c09a3a4;
P_0c09a3a4: /* original 2fc6, guest PC 0x0c09a3a4 */
if(!s->budget--) { s->failed_pc=0x0c09a3a4u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09a3a6;
P_0c09a3a6: /* original 2fb6, guest PC 0x0c09a3a6 */
if(!s->budget--) { s->failed_pc=0x0c09a3a6u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09a3a8;
P_0c09a3a8: /* original fffb, guest PC 0x0c09a3a8 */
if(!s->budget--) { s->failed_pc=0x0c09a3a8u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c09a3aa;
P_0c09a3aa: /* original 4f22, guest PC 0x0c09a3aa */
if(!s->budget--) { s->failed_pc=0x0c09a3aau; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c09a3ac;
P_0c09a3ac: /* original d33d, guest PC 0x0c09a3ac */
if(!s->budget--) { s->failed_pc=0x0c09a3acu; return 0; }
r[3]=read(ram,0x0c09a4a4u,4);
goto P_0c09a3ae;
P_0c09a3ae: /* original db3c, guest PC 0x0c09a3ae */
if(!s->budget--) { s->failed_pc=0x0c09a3aeu; return 0; }
r[11]=read(ram,0x0c09a4a0u,4);
goto P_0c09a3b0;
P_0c09a3b0: /* original de39, guest PC 0x0c09a3b0 */
if(!s->budget--) { s->failed_pc=0x0c09a3b0u; return 0; }
r[14]=read(ram,0x0c09a498u,4);
goto P_0c09a3b2;
P_0c09a3b2: /* original dd3a, guest PC 0x0c09a3b2 */
if(!s->budget--) { s->failed_pc=0x0c09a3b2u; return 0; }
r[13]=read(ram,0x0c09a49cu,4);
goto P_0c09a3b4;
P_0c09a3b4: /* original 430b, guest PC 0x0c09a3b4 */
if(!s->budget--) { s->failed_pc=0x0c09a3b4u; return 0; }
target=r[3];
r[16]=code_base|0x0c09a3b8u;
r[4]=r[6];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09a3b8u) { target=s->pc; goto dispatch; }
goto P_0c09a3b8;
P_0c09a3b6: /* original 6463, guest PC 0x0c09a3b6 */
if(!s->budget--) { s->failed_pc=0x0c09a3b6u; return 0; }
r[4]=r[6];
goto P_0c09a3b8;
P_0c09a3b8: /* original e600, guest PC 0x0c09a3b8 */
if(!s->budget--) { s->failed_pc=0x0c09a3b8u; return 0; }
r[6]=0x00000000u;
goto P_0c09a3ba;
P_0c09a3ba: /* original d23b, guest PC 0x0c09a3ba */
if(!s->budget--) { s->failed_pc=0x0c09a3bau; return 0; }
r[2]=read(ram,0x0c09a4a8u,4);
goto P_0c09a3bc;
P_0c09a3bc: /* original ff8d, guest PC 0x0c09a3bc */
if(!s->budget--) { s->failed_pc=0x0c09a3bcu; return 0; }
fr[15]=0;
goto P_0c09a3be;
P_0c09a3be: /* original 6563, guest PC 0x0c09a3be */
if(!s->budget--) { s->failed_pc=0x0c09a3beu; return 0; }
r[5]=r[6];
goto P_0c09a3c0;
P_0c09a3c0: /* original f5fc, guest PC 0x0c09a3c0 */
if(!s->budget--) { s->failed_pc=0x0c09a3c0u; return 0; }
vf3_matrix_move(s,5,15);
goto P_0c09a3c2;
P_0c09a3c2: /* original f4fc, guest PC 0x0c09a3c2 */
if(!s->budget--) { s->failed_pc=0x0c09a3c2u; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c09a3c4;
P_0c09a3c4: /* original 420b, guest PC 0x0c09a3c4 */
if(!s->budget--) { s->failed_pc=0x0c09a3c4u; return 0; }
target=r[2];
r[16]=code_base|0x0c09a3c8u;
r[4]=r[6];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09a3c8u) { target=s->pc; goto dispatch; }
goto P_0c09a3c8;
P_0c09a3c6: /* original 6463, guest PC 0x0c09a3c6 */
if(!s->budget--) { s->failed_pc=0x0c09a3c6u; return 0; }
r[4]=r[6];
goto P_0c09a3c8;
P_0c09a3c8: /* original d338, guest PC 0x0c09a3c8 */
if(!s->budget--) { s->failed_pc=0x0c09a3c8u; return 0; }
r[3]=read(ram,0x0c09a4acu,4);
goto P_0c09a3ca;
P_0c09a3ca: /* original 430b, guest PC 0x0c09a3ca */
if(!s->budget--) { s->failed_pc=0x0c09a3cau; return 0; }
target=r[3];
r[16]=code_base|0x0c09a3ceu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09a3ceu) { target=s->pc; goto dispatch; }
goto P_0c09a3ce;
P_0c09a3cc: /* original 0009, guest PC 0x0c09a3cc */
if(!s->budget--) { s->failed_pc=0x0c09a3ccu; return 0; }
goto P_0c09a3ce;
P_0c09a3ce: /* original d238, guest PC 0x0c09a3ce */
if(!s->budget--) { s->failed_pc=0x0c09a3ceu; return 0; }
r[2]=read(ram,0x0c09a4b0u,4);
goto P_0c09a3d0;
P_0c09a3d0: /* original 420b, guest PC 0x0c09a3d0 */
if(!s->budget--) { s->failed_pc=0x0c09a3d0u; return 0; }
target=r[2];
r[16]=code_base|0x0c09a3d4u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09a3d4u) { target=s->pc; goto dispatch; }
goto P_0c09a3d4;
P_0c09a3d2: /* original 0009, guest PC 0x0c09a3d2 */
if(!s->budget--) { s->failed_pc=0x0c09a3d2u; return 0; }
goto P_0c09a3d4;
P_0c09a3d4: /* original 905a, guest PC 0x0c09a3d4 */
if(!s->budget--) { s->failed_pc=0x0c09a3d4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09a48cu,2);
goto P_0c09a3d6;
P_0c09a3d6: /* original e301, guest PC 0x0c09a3d6 */
if(!s->budget--) { s->failed_pc=0x0c09a3d6u; return 0; }
r[3]=0x00000001u;
goto P_0c09a3d8;
P_0c09a3d8: /* original ec00, guest PC 0x0c09a3d8 */
if(!s->budget--) { s->failed_pc=0x0c09a3d8u; return 0; }
r[12]=0x00000000u;
goto P_0c09a3da;
P_0c09a3da: /* original 0d36, guest PC 0x0c09a3da */
if(!s->budget--) { s->failed_pc=0x0c09a3dau; return 0; }
write(ram,r[13]+r[0],r[3],4);
goto P_0c09a3dc;
P_0c09a3dc: /* original c735, guest PC 0x0c09a3dc */
if(!s->budget--) { s->failed_pc=0x0c09a3dcu; return 0; }
r[0]=code_base|0x0009a4b4u;
goto P_0c09a3de;
P_0c09a3de: /* original f308, guest PC 0x0c09a3de */
if(!s->budget--) { s->failed_pc=0x0c09a3deu; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c09a3e0;
P_0c09a3e0: /* original fe3a, guest PC 0x0c09a3e0 */
if(!s->budget--) { s->failed_pc=0x0c09a3e0u; return 0; }
vf3_matrix_store(s,ram,3,r[14]);
goto P_0c09a3e2;
P_0c09a3e2: /* original 9054, guest PC 0x0c09a3e2 */
if(!s->budget--) { s->failed_pc=0x0c09a3e2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09a48eu,2);
goto P_0c09a3e4;
P_0c09a3e4: /* original 0dc4, guest PC 0x0c09a3e4 */
if(!s->budget--) { s->failed_pc=0x0c09a3e4u; return 0; }
write(ram,r[13]+r[0],r[12],1);
goto P_0c09a3e6;
P_0c09a3e6: /* original 52e2, guest PC 0x0c09a3e6 */
if(!s->budget--) { s->failed_pc=0x0c09a3e6u; return 0; }
r[2]=read(ram,r[14]+8,4);
goto P_0c09a3e8;
P_0c09a3e8: /* original 9352, guest PC 0x0c09a3e8 */
if(!s->budget--) { s->failed_pc=0x0c09a3e8u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09a490u,2);
goto P_0c09a3ea;
P_0c09a3ea: /* original 2239, guest PC 0x0c09a3ea */
if(!s->budget--) { s->failed_pc=0x0c09a3eau; return 0; }
r[2]&=r[3];
goto P_0c09a3ec;
P_0c09a3ec: /* original 1e22, guest PC 0x0c09a3ec */
if(!s->budget--) { s->failed_pc=0x0c09a3ecu; return 0; }
write(ram,r[14]+8,r[2],4);
goto P_0c09a3ee;
P_0c09a3ee: /* original d133, guest PC 0x0c09a3ee */
if(!s->budget--) { s->failed_pc=0x0c09a3eeu; return 0; }
r[1]=read(ram,0x0c09a4bcu,4);
goto P_0c09a3f0;
P_0c09a3f0: /* original de31, guest PC 0x0c09a3f0 */
if(!s->budget--) { s->failed_pc=0x0c09a3f0u; return 0; }
r[14]=read(ram,0x0c09a4b8u,4);
goto P_0c09a3f2;
P_0c09a3f2: /* original 410b, guest PC 0x0c09a3f2 */
if(!s->budget--) { s->failed_pc=0x0c09a3f2u; return 0; }
target=r[1];
r[16]=code_base|0x0c09a3f6u;
r[4]=read(ram,r[14]+24,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09a3f6u) { target=s->pc; goto dispatch; }
goto P_0c09a3f6;
P_0c09a3f4: /* original 54e6, guest PC 0x0c09a3f4 */
if(!s->budget--) { s->failed_pc=0x0c09a3f4u; return 0; }
r[4]=read(ram,r[14]+24,4);
goto P_0c09a3f6;
P_0c09a3f6: /* original d331, guest PC 0x0c09a3f6 */
if(!s->budget--) { s->failed_pc=0x0c09a3f6u; return 0; }
r[3]=read(ram,0x0c09a4bcu,4);
goto P_0c09a3f8;
P_0c09a3f8: /* original 430b, guest PC 0x0c09a3f8 */
if(!s->budget--) { s->failed_pc=0x0c09a3f8u; return 0; }
target=r[3];
r[16]=code_base|0x0c09a3fcu;
r[4]=read(ram,r[14]+16,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09a3fcu) { target=s->pc; goto dispatch; }
goto P_0c09a3fc;
P_0c09a3fa: /* original 54e4, guest PC 0x0c09a3fa */
if(!s->budget--) { s->failed_pc=0x0c09a3fau; return 0; }
r[4]=read(ram,r[14]+16,4);
goto P_0c09a3fc;
P_0c09a3fc: /* original d22f, guest PC 0x0c09a3fc */
if(!s->budget--) { s->failed_pc=0x0c09a3fcu; return 0; }
r[2]=read(ram,0x0c09a4bcu,4);
goto P_0c09a3fe;
P_0c09a3fe: /* original 420b, guest PC 0x0c09a3fe */
if(!s->budget--) { s->failed_pc=0x0c09a3feu; return 0; }
target=r[2];
r[16]=code_base|0x0c09a402u;
r[4]=read(ram,r[14]+20,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09a402u) { target=s->pc; goto dispatch; }
goto P_0c09a402;
P_0c09a400: /* original 54e5, guest PC 0x0c09a400 */
if(!s->budget--) { s->failed_pc=0x0c09a400u; return 0; }
r[4]=read(ram,r[14]+20,4);
goto P_0c09a402;
P_0c09a402: /* original d32e, guest PC 0x0c09a402 */
if(!s->budget--) { s->failed_pc=0x0c09a402u; return 0; }
r[3]=read(ram,0x0c09a4bcu,4);
goto P_0c09a404;
P_0c09a404: /* original 430b, guest PC 0x0c09a404 */
if(!s->budget--) { s->failed_pc=0x0c09a404u; return 0; }
target=r[3];
r[16]=code_base|0x0c09a408u;
r[4]=read(ram,r[14]+60,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09a408u) { target=s->pc; goto dispatch; }
goto P_0c09a408;
P_0c09a406: /* original 54ef, guest PC 0x0c09a406 */
if(!s->budget--) { s->failed_pc=0x0c09a406u; return 0; }
r[4]=read(ram,r[14]+60,4);
goto P_0c09a408;
P_0c09a408: /* original d32c, guest PC 0x0c09a408 */
if(!s->budget--) { s->failed_pc=0x0c09a408u; return 0; }
r[3]=read(ram,0x0c09a4bcu,4);
goto P_0c09a40a;
P_0c09a40a: /* original e040, guest PC 0x0c09a40a */
if(!s->budget--) { s->failed_pc=0x0c09a40au; return 0; }
r[0]=0x00000040u;
goto P_0c09a40c;
P_0c09a40c: /* original 430b, guest PC 0x0c09a40c */
if(!s->budget--) { s->failed_pc=0x0c09a40cu; return 0; }
target=r[3];
r[16]=code_base|0x0c09a410u;
r[4]=read(ram,r[14]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09a410u) { target=s->pc; goto dispatch; }
goto P_0c09a410;
P_0c09a40e: /* original 04ee, guest PC 0x0c09a40e */
if(!s->budget--) { s->failed_pc=0x0c09a40eu; return 0; }
r[4]=read(ram,r[14]+r[0],4);
goto P_0c09a410;
P_0c09a410: /* original d22a, guest PC 0x0c09a410 */
if(!s->budget--) { s->failed_pc=0x0c09a410u; return 0; }
r[2]=read(ram,0x0c09a4bcu,4);
goto P_0c09a412;
P_0c09a412: /* original 420b, guest PC 0x0c09a412 */
if(!s->budget--) { s->failed_pc=0x0c09a412u; return 0; }
target=r[2];
r[16]=code_base|0x0c09a416u;
r[4]=read(ram,r[14]+28,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09a416u) { target=s->pc; goto dispatch; }
goto P_0c09a416;
P_0c09a414: /* original 54e7, guest PC 0x0c09a414 */
if(!s->budget--) { s->failed_pc=0x0c09a414u; return 0; }
r[4]=read(ram,r[14]+28,4);
goto P_0c09a416;
P_0c09a416: /* original d329, guest PC 0x0c09a416 */
if(!s->budget--) { s->failed_pc=0x0c09a416u; return 0; }
r[3]=read(ram,0x0c09a4bcu,4);
goto P_0c09a418;
P_0c09a418: /* original 430b, guest PC 0x0c09a418 */
if(!s->budget--) { s->failed_pc=0x0c09a418u; return 0; }
target=r[3];
r[16]=code_base|0x0c09a41cu;
r[4]=read(ram,r[14]+52,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09a41cu) { target=s->pc; goto dispatch; }
goto P_0c09a41c;
P_0c09a41a: /* original 54ed, guest PC 0x0c09a41a */
if(!s->budget--) { s->failed_pc=0x0c09a41au; return 0; }
r[4]=read(ram,r[14]+52,4);
goto P_0c09a41c;
P_0c09a41c: /* original d227, guest PC 0x0c09a41c */
if(!s->budget--) { s->failed_pc=0x0c09a41cu; return 0; }
r[2]=read(ram,0x0c09a4bcu,4);
goto P_0c09a41e;
P_0c09a41e: /* original 420b, guest PC 0x0c09a41e */
if(!s->budget--) { s->failed_pc=0x0c09a41eu; return 0; }
target=r[2];
r[16]=code_base|0x0c09a422u;
r[4]=read(ram,r[14]+56,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09a422u) { target=s->pc; goto dispatch; }
goto P_0c09a422;
P_0c09a420: /* original 54ee, guest PC 0x0c09a420 */
if(!s->budget--) { s->failed_pc=0x0c09a420u; return 0; }
r[4]=read(ram,r[14]+56,4);
goto P_0c09a422;
P_0c09a422: /* original 9036, guest PC 0x0c09a422 */
if(!s->budget--) { s->failed_pc=0x0c09a422u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09a492u,2);
goto P_0c09a424;
P_0c09a424: /* original 63c3, guest PC 0x0c09a424 */
if(!s->budget--) { s->failed_pc=0x0c09a424u; return 0; }
r[3]=r[12];
goto P_0c09a426;
P_0c09a426: /* original 0bc6, guest PC 0x0c09a426 */
if(!s->budget--) { s->failed_pc=0x0c09a426u; return 0; }
write(ram,r[11]+r[0],r[12],4);
goto P_0c09a428;
P_0c09a428: /* original 70fc, guest PC 0x0c09a428 */
if(!s->budget--) { s->failed_pc=0x0c09a428u; return 0; }
r[0]+=0xfffffffcu;
goto P_0c09a42a;
P_0c09a42a: /* original 0b36, guest PC 0x0c09a42a */
if(!s->budget--) { s->failed_pc=0x0c09a42au; return 0; }
write(ram,r[11]+r[0],r[3],4);
goto P_0c09a42c;
P_0c09a42c: /* original 9032, guest PC 0x0c09a42c */
if(!s->budget--) { s->failed_pc=0x0c09a42cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09a494u,2);
goto P_0c09a42e;
P_0c09a42e: /* original 54e8, guest PC 0x0c09a42e */
if(!s->budget--) { s->failed_pc=0x0c09a42eu; return 0; }
r[4]=read(ram,r[14]+32,4);
goto P_0c09a430;
P_0c09a430: /* original 0434, guest PC 0x0c09a430 */
if(!s->budget--) { s->failed_pc=0x0c09a430u; return 0; }
write(ram,r[4]+r[0],r[3],1);
goto P_0c09a432;
P_0c09a432: /* original 7001, guest PC 0x0c09a432 */
if(!s->budget--) { s->failed_pc=0x0c09a432u; return 0; }
r[0]+=0x00000001u;
goto P_0c09a434;
P_0c09a434: /* original 0434, guest PC 0x0c09a434 */
if(!s->budget--) { s->failed_pc=0x0c09a434u; return 0; }
write(ram,r[4]+r[0],r[3],1);
goto P_0c09a436;
P_0c09a436: /* original 7001, guest PC 0x0c09a436 */
if(!s->budget--) { s->failed_pc=0x0c09a436u; return 0; }
r[0]+=0x00000001u;
goto P_0c09a438;
P_0c09a438: /* original 0434, guest PC 0x0c09a438 */
if(!s->budget--) { s->failed_pc=0x0c09a438u; return 0; }
write(ram,r[4]+r[0],r[3],1);
goto P_0c09a43a;
P_0c09a43a: /* original e010, guest PC 0x0c09a43a */
if(!s->budget--) { s->failed_pc=0x0c09a43au; return 0; }
r[0]=0x00000010u;
goto P_0c09a43c;
P_0c09a43c: /* original e329, guest PC 0x0c09a43c */
if(!s->budget--) { s->failed_pc=0x0c09a43cu; return 0; }
r[3]=0x00000029u;
goto P_0c09a43e;
P_0c09a43e: /* original 0d34, guest PC 0x0c09a43e */
if(!s->budget--) { s->failed_pc=0x0c09a43eu; return 0; }
write(ram,r[13]+r[0],r[3],1);
goto P_0c09a440;
P_0c09a440: /* original 9029, guest PC 0x0c09a440 */
if(!s->budget--) { s->failed_pc=0x0c09a440u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09a496u,2);
goto P_0c09a442;
P_0c09a442: /* original d31f, guest PC 0x0c09a442 */
if(!s->budget--) { s->failed_pc=0x0c09a442u; return 0; }
r[3]=read(ram,0x0c09a4c0u,4);
goto P_0c09a444;
P_0c09a444: /* original 54ec, guest PC 0x0c09a444 */
if(!s->budget--) { s->failed_pc=0x0c09a444u; return 0; }
r[4]=read(ram,r[14]+48,4);
goto P_0c09a446;
P_0c09a446: /* original 0436, guest PC 0x0c09a446 */
if(!s->budget--) { s->failed_pc=0x0c09a446u; return 0; }
write(ram,r[4]+r[0],r[3],4);
goto P_0c09a448;
P_0c09a448: /* original d31e, guest PC 0x0c09a448 */
if(!s->budget--) { s->failed_pc=0x0c09a448u; return 0; }
r[3]=read(ram,0x0c09a4c4u,4);
goto P_0c09a44a;
P_0c09a44a: /* original 430b, guest PC 0x0c09a44a */
if(!s->budget--) { s->failed_pc=0x0c09a44au; return 0; }
target=r[3];
r[16]=code_base|0x0c09a44eu;
r[4]=0x0000001eu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09a44eu) { target=s->pc; goto dispatch; }
goto P_0c09a44e;
P_0c09a44c: /* original e41e, guest PC 0x0c09a44c */
if(!s->budget--) { s->failed_pc=0x0c09a44cu; return 0; }
r[4]=0x0000001eu;
goto P_0c09a44e;
P_0c09a44e: /* original d21e, guest PC 0x0c09a44e */
if(!s->budget--) { s->failed_pc=0x0c09a44eu; return 0; }
r[2]=read(ram,0x0c09a4c8u,4);
goto P_0c09a450;
P_0c09a450: /* original 420b, guest PC 0x0c09a450 */
if(!s->budget--) { s->failed_pc=0x0c09a450u; return 0; }
target=r[2];
r[16]=code_base|0x0c09a454u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09a454u) { target=s->pc; goto dispatch; }
goto P_0c09a454;
P_0c09a452: /* original 0009, guest PC 0x0c09a452 */
if(!s->budget--) { s->failed_pc=0x0c09a452u; return 0; }
goto P_0c09a454;
P_0c09a454: /* original d31d, guest PC 0x0c09a454 */
if(!s->budget--) { s->failed_pc=0x0c09a454u; return 0; }
r[3]=read(ram,0x0c09a4ccu,4);
goto P_0c09a456;
P_0c09a456: /* original 430b, guest PC 0x0c09a456 */
if(!s->budget--) { s->failed_pc=0x0c09a456u; return 0; }
target=r[3];
r[16]=code_base|0x0c09a45au;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09a45au) { target=s->pc; goto dispatch; }
goto P_0c09a45a;
P_0c09a458: /* original 0009, guest PC 0x0c09a458 */
if(!s->budget--) { s->failed_pc=0x0c09a458u; return 0; }
goto P_0c09a45a;
P_0c09a45a: /* original d21d, guest PC 0x0c09a45a */
if(!s->budget--) { s->failed_pc=0x0c09a45au; return 0; }
r[2]=read(ram,0x0c09a4d0u,4);
goto P_0c09a45c;
P_0c09a45c: /* original 420b, guest PC 0x0c09a45c */
if(!s->budget--) { s->failed_pc=0x0c09a45cu; return 0; }
target=r[2];
r[16]=code_base|0x0c09a460u;
r[4]=0x0000001eu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09a460u) { target=s->pc; goto dispatch; }
goto P_0c09a460;
P_0c09a45e: /* original e41e, guest PC 0x0c09a45e */
if(!s->budget--) { s->failed_pc=0x0c09a45eu; return 0; }
r[4]=0x0000001eu;
goto P_0c09a460;
P_0c09a460: /* original d310, guest PC 0x0c09a460 */
if(!s->budget--) { s->failed_pc=0x0c09a460u; return 0; }
r[3]=read(ram,0x0c09a4a4u,4);
goto P_0c09a462;
P_0c09a462: /* original 65c3, guest PC 0x0c09a462 */
if(!s->budget--) { s->failed_pc=0x0c09a462u; return 0; }
r[5]=r[12];
goto P_0c09a464;
P_0c09a464: /* original 66c3, guest PC 0x0c09a464 */
if(!s->budget--) { s->failed_pc=0x0c09a464u; return 0; }
r[6]=r[12];
goto P_0c09a466;
P_0c09a466: /* original 430b, guest PC 0x0c09a466 */
if(!s->budget--) { s->failed_pc=0x0c09a466u; return 0; }
target=r[3];
r[16]=code_base|0x0c09a46au;
r[4]=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09a46au) { target=s->pc; goto dispatch; }
goto P_0c09a46a;
P_0c09a468: /* original 64c3, guest PC 0x0c09a468 */
if(!s->budget--) { s->failed_pc=0x0c09a468u; return 0; }
r[4]=r[12];
goto P_0c09a46a;
P_0c09a46a: /* original d20f, guest PC 0x0c09a46a */
if(!s->budget--) { s->failed_pc=0x0c09a46au; return 0; }
r[2]=read(ram,0x0c09a4a8u,4);
goto P_0c09a46c;
P_0c09a46c: /* original 65c3, guest PC 0x0c09a46c */
if(!s->budget--) { s->failed_pc=0x0c09a46cu; return 0; }
r[5]=r[12];
goto P_0c09a46e;
P_0c09a46e: /* original 66c3, guest PC 0x0c09a46e */
if(!s->budget--) { s->failed_pc=0x0c09a46eu; return 0; }
r[6]=r[12];
goto P_0c09a470;
P_0c09a470: /* original f5fc, guest PC 0x0c09a470 */
if(!s->budget--) { s->failed_pc=0x0c09a470u; return 0; }
vf3_matrix_move(s,5,15);
goto P_0c09a472;
P_0c09a472: /* original f4fc, guest PC 0x0c09a472 */
if(!s->budget--) { s->failed_pc=0x0c09a472u; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c09a474;
P_0c09a474: /* original 420b, guest PC 0x0c09a474 */
if(!s->budget--) { s->failed_pc=0x0c09a474u; return 0; }
target=r[2];
r[16]=code_base|0x0c09a478u;
r[4]=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09a478u) { target=s->pc; goto dispatch; }
goto P_0c09a478;
P_0c09a476: /* original 64c3, guest PC 0x0c09a476 */
if(!s->budget--) { s->failed_pc=0x0c09a476u; return 0; }
r[4]=r[12];
goto P_0c09a478;
P_0c09a478: /* original 4f26, guest PC 0x0c09a478 */
if(!s->budget--) { s->failed_pc=0x0c09a478u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c09a47a;
P_0c09a47a: /* original 84da, guest PC 0x0c09a47a */
if(!s->budget--) { s->failed_pc=0x0c09a47au; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+10,1);
goto P_0c09a47c;
P_0c09a47c: /* original 7001, guest PC 0x0c09a47c */
if(!s->budget--) { s->failed_pc=0x0c09a47cu; return 0; }
r[0]+=0x00000001u;
goto P_0c09a47e;
P_0c09a47e: /* original 80da, guest PC 0x0c09a47e */
if(!s->budget--) { s->failed_pc=0x0c09a47eu; return 0; }
write(ram,r[13]+10,r[0],1);
goto P_0c09a480;
P_0c09a480: /* original fff9, guest PC 0x0c09a480 */
if(!s->budget--) { s->failed_pc=0x0c09a480u; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c09a482;
P_0c09a482: /* original 6bf6, guest PC 0x0c09a482 */
if(!s->budget--) { s->failed_pc=0x0c09a482u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c09a484;
P_0c09a484: /* original 6cf6, guest PC 0x0c09a484 */
if(!s->budget--) { s->failed_pc=0x0c09a484u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c09a486;
P_0c09a486: /* original 6df6, guest PC 0x0c09a486 */
if(!s->budget--) { s->failed_pc=0x0c09a486u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c09a488;
P_0c09a488: /* original 000b, guest PC 0x0c09a488 */
if(!s->budget--) { s->failed_pc=0x0c09a488u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c09a48a: /* original 6ef6, guest PC 0x0c09a48a */
if(!s->budget--) { s->failed_pc=0x0c09a48au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c09a48cu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c09a48cu; return 0; } return 1;
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
P_0c0a7a0c: /* original 2fe6, guest PC 0x0c0a7a0c */
if(!s->budget--) { s->failed_pc=0x0c0a7a0cu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a7a0e;
P_0c0a7a0e: /* original 6743, guest PC 0x0c0a7a0e */
if(!s->budget--) { s->failed_pc=0x0c0a7a0eu; return 0; }
r[7]=r[4];
goto P_0c0a7a10;
P_0c0a7a10: /* original 2fd6, guest PC 0x0c0a7a10 */
if(!s->budget--) { s->failed_pc=0x0c0a7a10u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a7a12;
P_0c0a7a12: /* original 4728, guest PC 0x0c0a7a12 */
if(!s->budget--) { s->failed_pc=0x0c0a7a12u; return 0; }
r[7]<<=16;
goto P_0c0a7a14;
P_0c0a7a14: /* original fffb, guest PC 0x0c0a7a14 */
if(!s->budget--) { s->failed_pc=0x0c0a7a14u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c0a7a16;
P_0c0a7a16: /* original 6e73, guest PC 0x0c0a7a16 */
if(!s->budget--) { s->failed_pc=0x0c0a7a16u; return 0; }
r[14]=r[7];
goto P_0c0a7a18;
P_0c0a7a18: /* original 4518, guest PC 0x0c0a7a18 */
if(!s->budget--) { s->failed_pc=0x0c0a7a18u; return 0; }
r[5]<<=8;
goto P_0c0a7a1a;
P_0c0a7a1a: /* original 6463, guest PC 0x0c0a7a1a */
if(!s->budget--) { s->failed_pc=0x0c0a7a1au; return 0; }
r[4]=r[6];
goto P_0c0a7a1c;
P_0c0a7a1c: /* original 4f22, guest PC 0x0c0a7a1c */
if(!s->budget--) { s->failed_pc=0x0c0a7a1cu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0a7a1e;
P_0c0a7a1e: /* original 2e5b, guest PC 0x0c0a7a1e */
if(!s->budget--) { s->failed_pc=0x0c0a7a1eu; return 0; }
r[14]|=r[5];
goto P_0c0a7a20;
P_0c0a7a20: /* original 2e4b, guest PC 0x0c0a7a20 */
if(!s->budget--) { s->failed_pc=0x0c0a7a20u; return 0; }
r[14]|=r[4];
goto P_0c0a7a22;
P_0c0a7a22: /* original 7ffc, guest PC 0x0c0a7a22 */
if(!s->budget--) { s->failed_pc=0x0c0a7a22u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c0a7a24;
P_0c0a7a24: /* original ff4a, guest PC 0x0c0a7a24 */
if(!s->budget--) { s->failed_pc=0x0c0a7a24u; return 0; }
vf3_matrix_store(s,ram,4,r[15]);
goto P_0c0a7a26;
P_0c0a7a26: /* original d327, guest PC 0x0c0a7a26 */
if(!s->budget--) { s->failed_pc=0x0c0a7a26u; return 0; }
r[3]=read(ram,0x0c0a7ac4u,4);
goto P_0c0a7a28;
P_0c0a7a28: /* original 903c, guest PC 0x0c0a7a28 */
if(!s->budget--) { s->failed_pc=0x0c0a7a28u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a7aa4u,2);
goto P_0c0a7a2a;
P_0c0a7a2a: /* original dd27, guest PC 0x0c0a7a2a */
if(!s->budget--) { s->failed_pc=0x0c0a7a2au; return 0; }
r[13]=read(ram,0x0c0a7ac8u,4);
goto P_0c0a7a2c;
P_0c0a7a2c: /* original 2e3b, guest PC 0x0c0a7a2c */
if(!s->budget--) { s->failed_pc=0x0c0a7a2cu; return 0; }
r[14]|=r[3];
goto P_0c0a7a2e;
P_0c0a7a2e: /* original ff5c, guest PC 0x0c0a7a2e */
if(!s->budget--) { s->failed_pc=0x0c0a7a2eu; return 0; }
vf3_matrix_move(s,15,5);
goto P_0c0a7a30;
P_0c0a7a30: /* original 0de6, guest PC 0x0c0a7a30 */
if(!s->budget--) { s->failed_pc=0x0c0a7a30u; return 0; }
write(ram,r[13]+r[0],r[14],4);
goto P_0c0a7a32;
P_0c0a7a32: /* original d226, guest PC 0x0c0a7a32 */
if(!s->budget--) { s->failed_pc=0x0c0a7a32u; return 0; }
r[2]=read(ram,0x0c0a7accu,4);
goto P_0c0a7a34;
P_0c0a7a34: /* original 420b, guest PC 0x0c0a7a34 */
if(!s->budget--) { s->failed_pc=0x0c0a7a34u; return 0; }
target=r[2];
r[16]=code_base|0x0c0a7a38u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a7a38u) { target=s->pc; goto dispatch; }
goto P_0c0a7a38;
P_0c0a7a36: /* original 64e3, guest PC 0x0c0a7a36 */
if(!s->budget--) { s->failed_pc=0x0c0a7a36u; return 0; }
r[4]=r[14];
goto P_0c0a7a38;
P_0c0a7a38: /* original d325, guest PC 0x0c0a7a38 */
if(!s->budget--) { s->failed_pc=0x0c0a7a38u; return 0; }
r[3]=read(ram,0x0c0a7ad0u,4);
goto P_0c0a7a3a;
P_0c0a7a3a: /* original 65e3, guest PC 0x0c0a7a3a */
if(!s->budget--) { s->failed_pc=0x0c0a7a3au; return 0; }
r[5]=r[14];
goto P_0c0a7a3c;
P_0c0a7a3c: /* original 66e3, guest PC 0x0c0a7a3c */
if(!s->budget--) { s->failed_pc=0x0c0a7a3cu; return 0; }
r[6]=r[14];
goto P_0c0a7a3e;
P_0c0a7a3e: /* original 430b, guest PC 0x0c0a7a3e */
if(!s->budget--) { s->failed_pc=0x0c0a7a3eu; return 0; }
target=r[3];
r[16]=code_base|0x0c0a7a42u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a7a42u) { target=s->pc; goto dispatch; }
goto P_0c0a7a42;
P_0c0a7a40: /* original 64e3, guest PC 0x0c0a7a40 */
if(!s->budget--) { s->failed_pc=0x0c0a7a40u; return 0; }
r[4]=r[14];
goto P_0c0a7a42;
P_0c0a7a42: /* original f2f8, guest PC 0x0c0a7a42 */
if(!s->budget--) { s->failed_pc=0x0c0a7a42u; return 0; }
vf3_matrix_load(s,ram,2,r[15]);
goto P_0c0a7a44;
P_0c0a7a44: /* original e500, guest PC 0x0c0a7a44 */
if(!s->budget--) { s->failed_pc=0x0c0a7a44u; return 0; }
r[5]=0x00000000u;
goto P_0c0a7a46;
P_0c0a7a46: /* original f38d, guest PC 0x0c0a7a46 */
if(!s->budget--) { s->failed_pc=0x0c0a7a46u; return 0; }
fr[3]=0;
goto P_0c0a7a48;
P_0c0a7a48: /* original e100, guest PC 0x0c0a7a48 */
if(!s->budget--) { s->failed_pc=0x0c0a7a48u; return 0; }
r[1]=0x00000000u;
goto P_0c0a7a4a;
P_0c0a7a4a: /* original f235, guest PC 0x0c0a7a4a */
if(!s->budget--) { s->failed_pc=0x0c0a7a4au; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[2])>as_float(fr[3]))!=0);
goto P_0c0a7a4c;
P_0c0a7a4c: /* original 9e2b, guest PC 0x0c0a7a4c */
if(!s->budget--) { s->failed_pc=0x0c0a7a4cu; return 0; }
r[14]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a7aa6u,2);
goto P_0c0a7a4e;
P_0c0a7a4e: /* original 942b, guest PC 0x0c0a7a4e */
if(!s->budget--) { s->failed_pc=0x0c0a7a4eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a7aa8u,2);
goto P_0c0a7a50;
P_0c0a7a50: /* original 3edc, guest PC 0x0c0a7a50 */
if(!s->budget--) { s->failed_pc=0x0c0a7a50u; return 0; }
r[14]+=r[13];
goto P_0c0a7a52;
P_0c0a7a52: /* original f68d, guest PC 0x0c0a7a52 */
if(!s->budget--) { s->failed_pc=0x0c0a7a52u; return 0; }
fr[6]=0;
goto P_0c0a7a54;
P_0c0a7a54: /* original 8d0c, guest PC 0x0c0a7a54 */
if(!s->budget--) { s->failed_pc=0x0c0a7a54u; return 0; }
cond=r[17]&1u;
r[1]+=r[14];
if(cond) { goto P_0c0a7a70; }
goto P_0c0a7a58;
P_0c0a7a56: /* original 31ec, guest PC 0x0c0a7a56 */
if(!s->budget--) { s->failed_pc=0x0c0a7a56u; return 0; }
r[1]+=r[14];
goto P_0c0a7a58;
P_0c0a7a58: /* original 6653, guest PC 0x0c0a7a58 */
if(!s->budget--) { s->failed_pc=0x0c0a7a58u; return 0; }
r[6]=r[5];
goto P_0c0a7a5a;
P_0c0a7a5a: /* original 6513, guest PC 0x0c0a7a5a */
if(!s->budget--) { s->failed_pc=0x0c0a7a5au; return 0; }
r[5]=r[1];
goto P_0c0a7a5c;
P_0c0a7a5c: /* original 7601, guest PC 0x0c0a7a5c */
if(!s->budget--) { s->failed_pc=0x0c0a7a5cu; return 0; }
r[6]+=0x00000001u;
goto P_0c0a7a5e;
P_0c0a7a5e: /* original f56a, guest PC 0x0c0a7a5e */
if(!s->budget--) { s->failed_pc=0x0c0a7a5eu; return 0; }
vf3_matrix_store(s,ram,6,r[5]);
goto P_0c0a7a60;
P_0c0a7a60: /* original 3647, guest PC 0x0c0a7a60 */
if(!s->budget--) { s->failed_pc=0x0c0a7a60u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[6]>(int32_t)r[4])!=0);
goto P_0c0a7a62;
P_0c0a7a62: /* original 8ffb, guest PC 0x0c0a7a62 */
if(!s->budget--) { s->failed_pc=0x0c0a7a62u; return 0; }
cond=r[17]&1u;
r[5]+=0x00000004u;
if(!cond) { goto P_0c0a7a5c; }
goto P_0c0a7a66;
P_0c0a7a64: /* original 7504, guest PC 0x0c0a7a64 */
if(!s->budget--) { s->failed_pc=0x0c0a7a64u; return 0; }
r[5]+=0x00000004u;
goto P_0c0a7a66;
P_0c0a7a66: /* original c71b, guest PC 0x0c0a7a66 */
if(!s->budget--) { s->failed_pc=0x0c0a7a66u; return 0; }
r[0]=code_base|0x000a7ad4u;
goto P_0c0a7a68;
P_0c0a7a68: /* original f308, guest PC 0x0c0a7a68 */
if(!s->budget--) { s->failed_pc=0x0c0a7a68u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c0a7a6a;
P_0c0a7a6a: /* original 901e, guest PC 0x0c0a7a6a */
if(!s->budget--) { s->failed_pc=0x0c0a7a6au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a7aaau,2);
goto P_0c0a7a6c;
P_0c0a7a6c: /* original a049, guest PC 0x0c0a7a6c */
if(!s->budget--) { s->failed_pc=0x0c0a7a6cu; return 0; }
vf3_matrix_store(s,ram,3,r[13]+r[0]);
goto P_0c0a7b02;
P_0c0a7a6e: /* original fd37, guest PC 0x0c0a7a6e */
if(!s->budget--) { s->failed_pc=0x0c0a7a6eu; return 0; }
vf3_matrix_store(s,ram,3,r[13]+r[0]);
goto P_0c0a7a70;
P_0c0a7a70: /* original c719, guest PC 0x0c0a7a70 */
if(!s->budget--) { s->failed_pc=0x0c0a7a70u; return 0; }
r[0]=code_base|0x000a7ad8u;
goto P_0c0a7a72;
P_0c0a7a72: /* original f59d, guest PC 0x0c0a7a72 */
if(!s->budget--) { s->failed_pc=0x0c0a7a72u; return 0; }
fr[5]=0x3f800000u;
goto P_0c0a7a74;
P_0c0a7a74: /* original f308, guest PC 0x0c0a7a74 */
if(!s->budget--) { s->failed_pc=0x0c0a7a74u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c0a7a76;
P_0c0a7a76: /* original 6753, guest PC 0x0c0a7a76 */
if(!s->budget--) { s->failed_pc=0x0c0a7a76u; return 0; }
r[7]=r[5];
goto P_0c0a7a78;
P_0c0a7a78: /* original f75c, guest PC 0x0c0a7a78 */
if(!s->budget--) { s->failed_pc=0x0c0a7a78u; return 0; }
vf3_matrix_move(s,7,5);
goto P_0c0a7a7a;
P_0c0a7a7a: /* original f7f1, guest PC 0x0c0a7a7a */
if(!s->budget--) { s->failed_pc=0x0c0a7a7au; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[15],r[18],'-');
goto P_0c0a7a7c;
P_0c0a7a7c: /* original f232, guest PC 0x0c0a7a7c */
if(!s->budget--) { s->failed_pc=0x0c0a7a7cu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c0a7a7e;
P_0c0a7a7e: /* original 9014, guest PC 0x0c0a7a7e */
if(!s->budget--) { s->failed_pc=0x0c0a7a7eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a7aaau,2);
goto P_0c0a7a80;
P_0c0a7a80: /* original 6543, guest PC 0x0c0a7a80 */
if(!s->budget--) { s->failed_pc=0x0c0a7a80u; return 0; }
r[5]=r[4];
goto P_0c0a7a82;
P_0c0a7a82: /* original 6613, guest PC 0x0c0a7a82 */
if(!s->budget--) { s->failed_pc=0x0c0a7a82u; return 0; }
r[6]=r[1];
goto P_0c0a7a84;
P_0c0a7a84: /* original f47c, guest PC 0x0c0a7a84 */
if(!s->budget--) { s->failed_pc=0x0c0a7a84u; return 0; }
vf3_matrix_move(s,4,7);
goto P_0c0a7a86;
P_0c0a7a86: /* original f423, guest PC 0x0c0a7a86 */
if(!s->budget--) { s->failed_pc=0x0c0a7a86u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[2],r[18],'/');
goto P_0c0a7a88;
P_0c0a7a88: /* original fd47, guest PC 0x0c0a7a88 */
if(!s->budget--) { s->failed_pc=0x0c0a7a88u; return 0; }
vf3_matrix_store(s,ram,4,r[13]+r[0]);
goto P_0c0a7a8a;
P_0c0a7a8a: /* original c714, guest PC 0x0c0a7a8a */
if(!s->budget--) { s->failed_pc=0x0c0a7a8au; return 0; }
r[0]=code_base|0x000a7adcu;
goto P_0c0a7a8c;
P_0c0a7a8c: /* original f808, guest PC 0x0c0a7a8c */
if(!s->budget--) { s->failed_pc=0x0c0a7a8cu; return 0; }
vf3_matrix_load(s,ram,8,r[0]);
goto P_0c0a7a8e;
P_0c0a7a8e: /* original 455a, guest PC 0x0c0a7a8e */
if(!s->budget--) { s->failed_pc=0x0c0a7a8eu; return 0; }
r[53]=r[5];
goto P_0c0a7a90;
P_0c0a7a90: /* original f28d, guest PC 0x0c0a7a90 */
if(!s->budget--) { s->failed_pc=0x0c0a7a90u; return 0; }
fr[2]=0;
goto P_0c0a7a92;
P_0c0a7a92: /* original f32d, guest PC 0x0c0a7a92 */
if(!s->budget--) { s->failed_pc=0x0c0a7a92u; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c0a7a94;
P_0c0a7a94: /* original f372, guest PC 0x0c0a7a94 */
if(!s->budget--) { s->failed_pc=0x0c0a7a94u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[7],r[18],'*');
goto P_0c0a7a96;
P_0c0a7a96: /* original f383, guest PC 0x0c0a7a96 */
if(!s->budget--) { s->failed_pc=0x0c0a7a96u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[8],r[18],'/');
goto P_0c0a7a98;
P_0c0a7a98: /* original f43c, guest PC 0x0c0a7a98 */
if(!s->budget--) { s->failed_pc=0x0c0a7a98u; return 0; }
vf3_matrix_move(s,4,3);
goto P_0c0a7a9a;
P_0c0a7a9a: /* original f4f0, guest PC 0x0c0a7a9a */
if(!s->budget--) { s->failed_pc=0x0c0a7a9au; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[15],r[18],'+');
goto P_0c0a7a9c;
P_0c0a7a9c: /* original f245, guest PC 0x0c0a7a9c */
if(!s->budget--) { s->failed_pc=0x0c0a7a9cu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[2])>as_float(fr[4]))!=0);
goto P_0c0a7a9e;
P_0c0a7a9e: /* original 8b1f, guest PC 0x0c0a7a9e */
if(!s->budget--) { s->failed_pc=0x0c0a7a9eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a7ae0; }
goto P_0c0a7aa0;
P_0c0a7aa0: /* original a021, guest PC 0x0c0a7aa0 */
if(!s->budget--) { s->failed_pc=0x0c0a7aa0u; return 0; }
vf3_matrix_move(s,4,6);
goto P_0c0a7ae6;
P_0c0a7aa2: /* original f46c, guest PC 0x0c0a7aa2 */
if(!s->budget--) { s->failed_pc=0x0c0a7aa2u; return 0; }
vf3_matrix_move(s,4,6);
if(!vf3_matrix_family(0x0c0a7aa4u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0a7aa4u; return 0; } return 1;
P_0c0a7ae0: /* original f455, guest PC 0x0c0a7ae0 */
if(!s->budget--) { s->failed_pc=0x0c0a7ae0u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[4])>as_float(fr[5]))!=0);
goto P_0c0a7ae2;
P_0c0a7ae2: /* original 8b00, guest PC 0x0c0a7ae2 */
if(!s->budget--) { s->failed_pc=0x0c0a7ae2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a7ae6; }
goto P_0c0a7ae4;
P_0c0a7ae4: /* original f45c, guest PC 0x0c0a7ae4 */
if(!s->budget--) { s->failed_pc=0x0c0a7ae4u; return 0; }
vf3_matrix_move(s,4,5);
goto P_0c0a7ae6;
P_0c0a7ae6: /* original 7701, guest PC 0x0c0a7ae6 */
if(!s->budget--) { s->failed_pc=0x0c0a7ae6u; return 0; }
r[7]+=0x00000001u;
goto P_0c0a7ae8;
P_0c0a7ae8: /* original f64a, guest PC 0x0c0a7ae8 */
if(!s->budget--) { s->failed_pc=0x0c0a7ae8u; return 0; }
vf3_matrix_store(s,ram,4,r[6]);
goto P_0c0a7aea;
P_0c0a7aea: /* original 3743, guest PC 0x0c0a7aea */
if(!s->budget--) { s->failed_pc=0x0c0a7aeau; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[7]>=(int32_t)r[4])!=0);
goto P_0c0a7aec;
P_0c0a7aec: /* original 7604, guest PC 0x0c0a7aec */
if(!s->budget--) { s->failed_pc=0x0c0a7aecu; return 0; }
r[6]+=0x00000004u;
goto P_0c0a7aee;
P_0c0a7aee: /* original 8fce, guest PC 0x0c0a7aee */
if(!s->budget--) { s->failed_pc=0x0c0a7aeeu; return 0; }
cond=r[17]&1u;
r[5]+=0xffffffffu;
if(!cond) { goto P_0c0a7a8e; }
goto P_0c0a7af2;
P_0c0a7af0: /* original 75ff, guest PC 0x0c0a7af0 */
if(!s->budget--) { s->failed_pc=0x0c0a7af0u; return 0; }
r[5]+=0xffffffffu;
goto P_0c0a7af2;
P_0c0a7af2: /* original f28d, guest PC 0x0c0a7af2 */
if(!s->budget--) { s->failed_pc=0x0c0a7af2u; return 0; }
fr[2]=0;
goto P_0c0a7af4;
P_0c0a7af4: /* original f2f5, guest PC 0x0c0a7af4 */
if(!s->budget--) { s->failed_pc=0x0c0a7af4u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[2])>as_float(fr[15]))!=0);
goto P_0c0a7af6;
P_0c0a7af6: /* original 8b01, guest PC 0x0c0a7af6 */
if(!s->budget--) { s->failed_pc=0x0c0a7af6u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a7afc; }
goto P_0c0a7af8;
P_0c0a7af8: /* original a001, guest PC 0x0c0a7af8 */
if(!s->budget--) { s->failed_pc=0x0c0a7af8u; return 0; }
fr[3]=0;
goto P_0c0a7afe;
P_0c0a7afa: /* original f38d, guest PC 0x0c0a7afa */
if(!s->budget--) { s->failed_pc=0x0c0a7afau; return 0; }
fr[3]=0;
goto P_0c0a7afc;
P_0c0a7afc: /* original f3fc, guest PC 0x0c0a7afc */
if(!s->budget--) { s->failed_pc=0x0c0a7afcu; return 0; }
vf3_matrix_move(s,3,15);
goto P_0c0a7afe;
P_0c0a7afe: /* original 9042, guest PC 0x0c0a7afe */
if(!s->budget--) { s->failed_pc=0x0c0a7afeu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a7b86u,2);
goto P_0c0a7b00;
P_0c0a7b00: /* original fe37, guest PC 0x0c0a7b00 */
if(!s->budget--) { s->failed_pc=0x0c0a7b00u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c0a7b02;
P_0c0a7b02: /* original 7f04, guest PC 0x0c0a7b02 */
if(!s->budget--) { s->failed_pc=0x0c0a7b02u; return 0; }
r[15]+=0x00000004u;
goto P_0c0a7b04;
P_0c0a7b04: /* original 60d2, guest PC 0x0c0a7b04 */
if(!s->budget--) { s->failed_pc=0x0c0a7b04u; return 0; }
tmp=read(ram,r[13],4);
r[0]=tmp;
goto P_0c0a7b06;
P_0c0a7b06: /* original 4f26, guest PC 0x0c0a7b06 */
if(!s->budget--) { s->failed_pc=0x0c0a7b06u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a7b08;
P_0c0a7b08: /* original cb01, guest PC 0x0c0a7b08 */
if(!s->budget--) { s->failed_pc=0x0c0a7b08u; return 0; }
r[0]|=1u;
goto P_0c0a7b0a;
P_0c0a7b0a: /* original 2d02, guest PC 0x0c0a7b0a */
if(!s->budget--) { s->failed_pc=0x0c0a7b0au; return 0; }
write(ram,r[13],r[0],4);
goto P_0c0a7b0c;
P_0c0a7b0c: /* original e500, guest PC 0x0c0a7b0c */
if(!s->budget--) { s->failed_pc=0x0c0a7b0cu; return 0; }
r[5]=0x00000000u;
goto P_0c0a7b0e;
P_0c0a7b0e: /* original fff9, guest PC 0x0c0a7b0e */
if(!s->budget--) { s->failed_pc=0x0c0a7b0eu; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0a7b10;
P_0c0a7b10: /* original d320, guest PC 0x0c0a7b10 */
if(!s->budget--) { s->failed_pc=0x0c0a7b10u; return 0; }
r[3]=read(ram,0x0c0a7b94u,4);
goto P_0c0a7b12;
P_0c0a7b12: /* original 6df6, guest PC 0x0c0a7b12 */
if(!s->budget--) { s->failed_pc=0x0c0a7b12u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0a7b14;
P_0c0a7b14: /* original d41e, guest PC 0x0c0a7b14 */
if(!s->budget--) { s->failed_pc=0x0c0a7b14u; return 0; }
r[4]=read(ram,0x0c0a7b90u,4);
goto P_0c0a7b16;
P_0c0a7b16: /* original 432b, guest PC 0x0c0a7b16 */
if(!s->budget--) { s->failed_pc=0x0c0a7b16u; return 0; }
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
P_0c0a7b18: /* original 6ef6, guest PC 0x0c0a7b18 */
if(!s->budget--) { s->failed_pc=0x0c0a7b18u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0a7b1au,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0a7b1au; return 0; } return 1;
P_0c0a7f14: /* original 2fe6, guest PC 0x0c0a7f14 */
if(!s->budget--) { s->failed_pc=0x0c0a7f14u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a7f16;
P_0c0a7f16: /* original d324, guest PC 0x0c0a7f16 */
if(!s->budget--) { s->failed_pc=0x0c0a7f16u; return 0; }
r[3]=read(ram,0x0c0a7fa8u,4);
goto P_0c0a7f18;
P_0c0a7f18: /* original 4f12, guest PC 0x0c0a7f18 */
if(!s->budget--) { s->failed_pc=0x0c0a7f18u; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c0a7f1a;
P_0c0a7f1a: /* original 6632, guest PC 0x0c0a7f1a */
if(!s->budget--) { s->failed_pc=0x0c0a7f1au; return 0; }
tmp=read(ram,r[3],4);
r[6]=tmp;
goto P_0c0a7f1c;
P_0c0a7f1c: /* original 856d, guest PC 0x0c0a7f1c */
if(!s->budget--) { s->failed_pc=0x0c0a7f1cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[6]+26,2);
goto P_0c0a7f1e;
P_0c0a7f1e: /* original 670d, guest PC 0x0c0a7f1e */
if(!s->budget--) { s->failed_pc=0x0c0a7f1eu; return 0; }
r[7]=r[0]&65535u;
goto P_0c0a7f20;
P_0c0a7f20: /* original a012, guest PC 0x0c0a7f20 */
if(!s->budget--) { s->failed_pc=0x0c0a7f20u; return 0; }
r[14]=0x0000001fu;
goto P_0c0a7f48;
P_0c0a7f22: /* original ee1f, guest PC 0x0c0a7f22 */
if(!s->budget--) { s->failed_pc=0x0c0a7f22u; return 0; }
r[14]=0x0000001fu;
goto P_0c0a7f24;
P_0c0a7f24: /* original 856b, guest PC 0x0c0a7f24 */
if(!s->budget--) { s->failed_pc=0x0c0a7f24u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[6]+22,2);
goto P_0c0a7f26;
P_0c0a7f26: /* original 600d, guest PC 0x0c0a7f26 */
if(!s->budget--) { s->failed_pc=0x0c0a7f26u; return 0; }
r[0]=r[0]&65535u;
goto P_0c0a7f28;
P_0c0a7f28: /* original 3500, guest PC 0x0c0a7f28 */
if(!s->budget--) { s->failed_pc=0x0c0a7f28u; return 0; }
r[17]=(r[17]&~1u)|((r[5]==r[0])!=0);
goto P_0c0a7f2a;
P_0c0a7f2a: /* original 8910, guest PC 0x0c0a7f2a */
if(!s->budget--) { s->failed_pc=0x0c0a7f2au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a7f4e; }
goto P_0c0a7f2c;
P_0c0a7f2c: /* original e334, guest PC 0x0c0a7f2c */
if(!s->budget--) { s->failed_pc=0x0c0a7f2cu; return 0; }
r[3]=0x00000034u;
goto P_0c0a7f2e;
P_0c0a7f2e: /* original 6263, guest PC 0x0c0a7f2e */
if(!s->budget--) { s->failed_pc=0x0c0a7f2eu; return 0; }
r[2]=r[6];
goto P_0c0a7f30;
P_0c0a7f30: /* original 253f, guest PC 0x0c0a7f30 */
if(!s->budget--) { s->failed_pc=0x0c0a7f30u; return 0; }
r[19]=(uint32_t)((int32_t)(int16_t)r[5]*(int32_t)(int16_t)r[3]);
goto P_0c0a7f32;
P_0c0a7f32: /* original 721c, guest PC 0x0c0a7f32 */
if(!s->budget--) { s->failed_pc=0x0c0a7f32u; return 0; }
r[2]+=0x0000001cu;
goto P_0c0a7f34;
P_0c0a7f34: /* original e030, guest PC 0x0c0a7f34 */
if(!s->budget--) { s->failed_pc=0x0c0a7f34u; return 0; }
r[0]=0x00000030u;
goto P_0c0a7f36;
P_0c0a7f36: /* original 051a, guest PC 0x0c0a7f36 */
if(!s->budget--) { s->failed_pc=0x0c0a7f36u; return 0; }
r[5]=r[19];
goto P_0c0a7f38;
P_0c0a7f38: /* original 655f, guest PC 0x0c0a7f38 */
if(!s->budget--) { s->failed_pc=0x0c0a7f38u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)r[5];
goto P_0c0a7f3a;
P_0c0a7f3a: /* original 352c, guest PC 0x0c0a7f3a */
if(!s->budget--) { s->failed_pc=0x0c0a7f3au; return 0; }
r[5]+=r[2];
goto P_0c0a7f3c;
P_0c0a7f3c: /* original 015d, guest PC 0x0c0a7f3c */
if(!s->budget--) { s->failed_pc=0x0c0a7f3cu; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,r[5]+r[0],2);
goto P_0c0a7f3e;
P_0c0a7f3e: /* original 3140, guest PC 0x0c0a7f3e */
if(!s->budget--) { s->failed_pc=0x0c0a7f3eu; return 0; }
r[17]=(r[17]&~1u)|((r[1]==r[4])!=0);
goto P_0c0a7f40;
P_0c0a7f40: /* original 8b01, guest PC 0x0c0a7f40 */
if(!s->budget--) { s->failed_pc=0x0c0a7f40u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a7f46; }
goto P_0c0a7f42;
P_0c0a7f42: /* original a005, guest PC 0x0c0a7f42 */
if(!s->budget--) { s->failed_pc=0x0c0a7f42u; return 0; }
r[0]=0x00000001u;
goto P_0c0a7f50;
P_0c0a7f44: /* original e001, guest PC 0x0c0a7f44 */
if(!s->budget--) { s->failed_pc=0x0c0a7f44u; return 0; }
r[0]=0x00000001u;
goto P_0c0a7f46;
P_0c0a7f46: /* original 77ff, guest PC 0x0c0a7f46 */
if(!s->budget--) { s->failed_pc=0x0c0a7f46u; return 0; }
r[7]+=0xffffffffu;
goto P_0c0a7f48;
P_0c0a7f48: /* original 6573, guest PC 0x0c0a7f48 */
if(!s->budget--) { s->failed_pc=0x0c0a7f48u; return 0; }
r[5]=r[7];
goto P_0c0a7f4a;
P_0c0a7f4a: /* original afeb, guest PC 0x0c0a7f4a */
if(!s->budget--) { s->failed_pc=0x0c0a7f4au; return 0; }
r[5]&=r[14];
goto P_0c0a7f24;
P_0c0a7f4c: /* original 25e9, guest PC 0x0c0a7f4c */
if(!s->budget--) { s->failed_pc=0x0c0a7f4cu; return 0; }
r[5]&=r[14];
goto P_0c0a7f4e;
P_0c0a7f4e: /* original e000, guest PC 0x0c0a7f4e */
if(!s->budget--) { s->failed_pc=0x0c0a7f4eu; return 0; }
r[0]=0x00000000u;
goto P_0c0a7f50;
P_0c0a7f50: /* original 4f16, guest PC 0x0c0a7f50 */
if(!s->budget--) { s->failed_pc=0x0c0a7f50u; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a7f52;
P_0c0a7f52: /* original 000b, guest PC 0x0c0a7f52 */
if(!s->budget--) { s->failed_pc=0x0c0a7f52u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0a7f54: /* original 6ef6, guest PC 0x0c0a7f54 */
if(!s->budget--) { s->failed_pc=0x0c0a7f54u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0a7f56u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0a7f56u; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
