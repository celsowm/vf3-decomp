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
int vf3_away_batch134_adapter_16(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c0a81eeu: goto P_0c0a81ee;
case 0x0c0a81f0u: goto P_0c0a81f0;
case 0x0c0a81f2u: goto P_0c0a81f2;
case 0x0c0a81f4u: goto P_0c0a81f4;
case 0x0c0a81f6u: goto P_0c0a81f6;
case 0x0c0a81f8u: goto P_0c0a81f8;
case 0x0c0a81fau: goto P_0c0a81fa;
case 0x0c0a81fcu: goto P_0c0a81fc;
case 0x0c0a81feu: goto P_0c0a81fe;
case 0x0c0a8200u: goto P_0c0a8200;
case 0x0c0a8202u: goto P_0c0a8202;
case 0x0c0a8204u: goto P_0c0a8204;
case 0x0c0a8206u: goto P_0c0a8206;
case 0x0c0a8208u: goto P_0c0a8208;
case 0x0c0a820au: goto P_0c0a820a;
case 0x0c0a820cu: goto P_0c0a820c;
case 0x0c0a820eu: goto P_0c0a820e;
case 0x0c0a8210u: goto P_0c0a8210;
case 0x0c0a8212u: goto P_0c0a8212;
case 0x0c0a8214u: goto P_0c0a8214;
case 0x0c0a8216u: goto P_0c0a8216;
case 0x0c0a8218u: goto P_0c0a8218;
case 0x0c0a821au: goto P_0c0a821a;
case 0x0c0a821cu: goto P_0c0a821c;
case 0x0c0a821eu: goto P_0c0a821e;
case 0x0c0a8220u: goto P_0c0a8220;
case 0x0c0a8222u: goto P_0c0a8222;
case 0x0c0a8224u: goto P_0c0a8224;
case 0x0c0a8226u: goto P_0c0a8226;
case 0x0c0a8228u: goto P_0c0a8228;
case 0x0c0a822au: goto P_0c0a822a;
case 0x0c0a822cu: goto P_0c0a822c;
case 0x0c0a822eu: goto P_0c0a822e;
case 0x0c0a8230u: goto P_0c0a8230;
case 0x0c0a8232u: goto P_0c0a8232;
case 0x0c0a8234u: goto P_0c0a8234;
case 0x0c0a8236u: goto P_0c0a8236;
case 0x0c0a8238u: goto P_0c0a8238;
case 0x0c0a823au: goto P_0c0a823a;
case 0x0c0a823cu: goto P_0c0a823c;
case 0x0c0a823eu: goto P_0c0a823e;
case 0x0c0a8240u: goto P_0c0a8240;
case 0x0c0a8242u: goto P_0c0a8242;
case 0x0c0a8244u: goto P_0c0a8244;
case 0x0c0a8246u: goto P_0c0a8246;
case 0x0c0a8248u: goto P_0c0a8248;
case 0x0c0a824au: goto P_0c0a824a;
case 0x0c0a824cu: goto P_0c0a824c;
case 0x0c0a824eu: goto P_0c0a824e;
case 0x0c0a8250u: goto P_0c0a8250;
case 0x0c0a8252u: goto P_0c0a8252;
case 0x0c0a8254u: goto P_0c0a8254;
case 0x0c0a8256u: goto P_0c0a8256;
case 0x0c0a8258u: goto P_0c0a8258;
case 0x0c0a825au: goto P_0c0a825a;
case 0x0c0a825cu: goto P_0c0a825c;
case 0x0c0a825eu: goto P_0c0a825e;
case 0x0c0a8260u: goto P_0c0a8260;
case 0x0c0a8262u: goto P_0c0a8262;
case 0x0c0a8264u: goto P_0c0a8264;
case 0x0c0a8266u: goto P_0c0a8266;
case 0x0c0a8268u: goto P_0c0a8268;
case 0x0c0a826au: goto P_0c0a826a;
case 0x0c0a826cu: goto P_0c0a826c;
case 0x0c0a826eu: goto P_0c0a826e;
case 0x0c0a8270u: goto P_0c0a8270;
case 0x0c0a8272u: goto P_0c0a8272;
case 0x0c0a8274u: goto P_0c0a8274;
case 0x0c0a8276u: goto P_0c0a8276;
case 0x0c0a8278u: goto P_0c0a8278;
case 0x0c0a827au: goto P_0c0a827a;
case 0x0c0a827cu: goto P_0c0a827c;
case 0x0c0a827eu: goto P_0c0a827e;
case 0x0c0a8280u: goto P_0c0a8280;
case 0x0c0a8282u: goto P_0c0a8282;
case 0x0c0a8284u: goto P_0c0a8284;
case 0x0c0a8286u: goto P_0c0a8286;
case 0x0c0a8288u: goto P_0c0a8288;
case 0x0c0a828au: goto P_0c0a828a;
case 0x0c0a828cu: goto P_0c0a828c;
case 0x0c0a828eu: goto P_0c0a828e;
case 0x0c0a8290u: goto P_0c0a8290;
case 0x0c0a8292u: goto P_0c0a8292;
case 0x0c0a8294u: goto P_0c0a8294;
case 0x0c0a8296u: goto P_0c0a8296;
case 0x0c0a8298u: goto P_0c0a8298;
case 0x0c0a829au: goto P_0c0a829a;
case 0x0c0a8ac0u: goto P_0c0a8ac0;
case 0x0c0a8ac2u: goto P_0c0a8ac2;
case 0x0c0a8ac4u: goto P_0c0a8ac4;
case 0x0c0a8ac6u: goto P_0c0a8ac6;
case 0x0c0a8ac8u: goto P_0c0a8ac8;
case 0x0c0a8acau: goto P_0c0a8aca;
case 0x0c0a8accu: goto P_0c0a8acc;
case 0x0c0a8aceu: goto P_0c0a8ace;
case 0x0c0a8ad0u: goto P_0c0a8ad0;
case 0x0c0a8ad2u: goto P_0c0a8ad2;
case 0x0c0a8ad4u: goto P_0c0a8ad4;
case 0x0c0a8ad6u: goto P_0c0a8ad6;
case 0x0c0a8ad8u: goto P_0c0a8ad8;
case 0x0c0a8adau: goto P_0c0a8ada;
case 0x0c0a8adcu: goto P_0c0a8adc;
case 0x0c0a8adeu: goto P_0c0a8ade;
case 0x0c0a8ae0u: goto P_0c0a8ae0;
case 0x0c0a8ae2u: goto P_0c0a8ae2;
case 0x0c0a8ae4u: goto P_0c0a8ae4;
case 0x0c0a8ae6u: goto P_0c0a8ae6;
case 0x0c0a8ae8u: goto P_0c0a8ae8;
case 0x0c0a8aeau: goto P_0c0a8aea;
case 0x0c0a8aecu: goto P_0c0a8aec;
case 0x0c0a8aeeu: goto P_0c0a8aee;
case 0x0c0a8af0u: goto P_0c0a8af0;
case 0x0c0a8af2u: goto P_0c0a8af2;
case 0x0c0a8af4u: goto P_0c0a8af4;
case 0x0c0a8af6u: goto P_0c0a8af6;
case 0x0c0a8af8u: goto P_0c0a8af8;
case 0x0c0a8afau: goto P_0c0a8afa;
case 0x0c0a8afcu: goto P_0c0a8afc;
case 0x0c0a8afeu: goto P_0c0a8afe;
case 0x0c0a8b00u: goto P_0c0a8b00;
case 0x0c0a8b02u: goto P_0c0a8b02;
case 0x0c0a8b04u: goto P_0c0a8b04;
case 0x0c0a8b06u: goto P_0c0a8b06;
case 0x0c0a8b08u: goto P_0c0a8b08;
case 0x0c0a8b0au: goto P_0c0a8b0a;
case 0x0c0a8b0cu: goto P_0c0a8b0c;
case 0x0c0a8b0eu: goto P_0c0a8b0e;
case 0x0c0a8b10u: goto P_0c0a8b10;
case 0x0c0a8b12u: goto P_0c0a8b12;
case 0x0c0a8b14u: goto P_0c0a8b14;
case 0x0c0a8b16u: goto P_0c0a8b16;
case 0x0c0a8b18u: goto P_0c0a8b18;
case 0x0c0a8b1au: goto P_0c0a8b1a;
case 0x0c0a8b1cu: goto P_0c0a8b1c;
case 0x0c0a8b1eu: goto P_0c0a8b1e;
case 0x0c0a8b20u: goto P_0c0a8b20;
case 0x0c0a8b22u: goto P_0c0a8b22;
case 0x0c0a8b24u: goto P_0c0a8b24;
case 0x0c0a8b26u: goto P_0c0a8b26;
case 0x0c0a8b28u: goto P_0c0a8b28;
case 0x0c0a8b2au: goto P_0c0a8b2a;
case 0x0c0a8b2cu: goto P_0c0a8b2c;
case 0x0c0a8b2eu: goto P_0c0a8b2e;
case 0x0c0a8b30u: goto P_0c0a8b30;
case 0x0c0a8b32u: goto P_0c0a8b32;
case 0x0c0a8b34u: goto P_0c0a8b34;
case 0x0c0a8b36u: goto P_0c0a8b36;
case 0x0c0a8b38u: goto P_0c0a8b38;
case 0x0c0a8b3au: goto P_0c0a8b3a;
case 0x0c0a8b3cu: goto P_0c0a8b3c;
case 0x0c0a8b3eu: goto P_0c0a8b3e;
case 0x0c0a8b40u: goto P_0c0a8b40;
case 0x0c0a8b42u: goto P_0c0a8b42;
case 0x0c0a8b44u: goto P_0c0a8b44;
case 0x0c0a8b46u: goto P_0c0a8b46;
case 0x0c0a8b48u: goto P_0c0a8b48;
case 0x0c0a8b4au: goto P_0c0a8b4a;
case 0x0c0a8b4cu: goto P_0c0a8b4c;
case 0x0c0a8b4eu: goto P_0c0a8b4e;
case 0x0c0a8b50u: goto P_0c0a8b50;
case 0x0c0a8b52u: goto P_0c0a8b52;
case 0x0c0a8b54u: goto P_0c0a8b54;
case 0x0c0a8b56u: goto P_0c0a8b56;
case 0x0c0a8b58u: goto P_0c0a8b58;
case 0x0c0a8b5au: goto P_0c0a8b5a;
case 0x0c0a8b5cu: goto P_0c0a8b5c;
case 0x0c0a8b5eu: goto P_0c0a8b5e;
case 0x0c0a8b60u: goto P_0c0a8b60;
case 0x0c0a8b62u: goto P_0c0a8b62;
case 0x0c0a8b64u: goto P_0c0a8b64;
case 0x0c0a8b66u: goto P_0c0a8b66;
case 0x0c0a8b68u: goto P_0c0a8b68;
case 0x0c0a8b6au: goto P_0c0a8b6a;
case 0x0c0a8b6cu: goto P_0c0a8b6c;
case 0x0c0a8b6eu: goto P_0c0a8b6e;
case 0x0c0a8b70u: goto P_0c0a8b70;
case 0x0c0a8b72u: goto P_0c0a8b72;
case 0x0c0a8b74u: goto P_0c0a8b74;
case 0x0c0a8b76u: goto P_0c0a8b76;
case 0x0c0a8b78u: goto P_0c0a8b78;
case 0x0c0a8b7au: goto P_0c0a8b7a;
case 0x0c0a8b7cu: goto P_0c0a8b7c;
case 0x0c0a8b7eu: goto P_0c0a8b7e;
case 0x0c0a8b80u: goto P_0c0a8b80;
case 0x0c0a8b82u: goto P_0c0a8b82;
case 0x0c0a8b84u: goto P_0c0a8b84;
case 0x0c0a8b86u: goto P_0c0a8b86;
case 0x0c0a8b88u: goto P_0c0a8b88;
case 0x0c0a8b8au: goto P_0c0a8b8a;
case 0x0c0a8b8cu: goto P_0c0a8b8c;
case 0x0c0a8b8eu: goto P_0c0a8b8e;
case 0x0c0a8b90u: goto P_0c0a8b90;
case 0x0c0a8b92u: goto P_0c0a8b92;
case 0x0c0a8b94u: goto P_0c0a8b94;
case 0x0c0a8b96u: goto P_0c0a8b96;
case 0x0c0a8b98u: goto P_0c0a8b98;
case 0x0c0a8b9au: goto P_0c0a8b9a;
case 0x0c0a8b9cu: goto P_0c0a8b9c;
case 0x0c0a8b9eu: goto P_0c0a8b9e;
case 0x0c0a8ba0u: goto P_0c0a8ba0;
case 0x0c0a8ba2u: goto P_0c0a8ba2;
case 0x0c0a8ba4u: goto P_0c0a8ba4;
case 0x0c0a8ba6u: goto P_0c0a8ba6;
case 0x0c0a8ba8u: goto P_0c0a8ba8;
case 0x0c0a8baau: goto P_0c0a8baa;
case 0x0c0a8bacu: goto P_0c0a8bac;
case 0x0c0a8baeu: goto P_0c0a8bae;
case 0x0c0a8bb0u: goto P_0c0a8bb0;
case 0x0c0a8bb2u: goto P_0c0a8bb2;
case 0x0c0a8bb4u: goto P_0c0a8bb4;
case 0x0c0a8bb6u: goto P_0c0a8bb6;
case 0x0c0a8bb8u: goto P_0c0a8bb8;
case 0x0c0a8bbau: goto P_0c0a8bba;
case 0x0c0a8bbcu: goto P_0c0a8bbc;
case 0x0c0a8bbeu: goto P_0c0a8bbe;
case 0x0c0a8bc0u: goto P_0c0a8bc0;
case 0x0c0a8bc2u: goto P_0c0a8bc2;
case 0x0c0a8bc4u: goto P_0c0a8bc4;
case 0x0c0a8bc6u: goto P_0c0a8bc6;
case 0x0c0a8bc8u: goto P_0c0a8bc8;
case 0x0c0a8bcau: goto P_0c0a8bca;
case 0x0c0a8bccu: goto P_0c0a8bcc;
case 0x0c0a8bceu: goto P_0c0a8bce;
case 0x0c0a8bd0u: goto P_0c0a8bd0;
case 0x0c0a8bd2u: goto P_0c0a8bd2;
case 0x0c0a8bd4u: goto P_0c0a8bd4;
case 0x0c0a8bd6u: goto P_0c0a8bd6;
case 0x0c0a8bd8u: goto P_0c0a8bd8;
case 0x0c0a8bdau: goto P_0c0a8bda;
case 0x0c0a8bdcu: goto P_0c0a8bdc;
case 0x0c0a8bdeu: goto P_0c0a8bde;
case 0x0c0a8be0u: goto P_0c0a8be0;
case 0x0c0a8be2u: goto P_0c0a8be2;
case 0x0c0a8be4u: goto P_0c0a8be4;
case 0x0c0a8be6u: goto P_0c0a8be6;
case 0x0c0a8be8u: goto P_0c0a8be8;
case 0x0c0a8beau: goto P_0c0a8bea;
case 0x0c0a8becu: goto P_0c0a8bec;
case 0x0c0a8beeu: goto P_0c0a8bee;
case 0x0c0a8bf0u: goto P_0c0a8bf0;
case 0x0c0a8bf2u: goto P_0c0a8bf2;
case 0x0c0a8bf4u: goto P_0c0a8bf4;
case 0x0c0a8bf6u: goto P_0c0a8bf6;
case 0x0c0a8c38u: goto P_0c0a8c38;
case 0x0c0a8c3au: goto P_0c0a8c3a;
case 0x0c0a8c3cu: goto P_0c0a8c3c;
case 0x0c0a8c3eu: goto P_0c0a8c3e;
case 0x0c0a8c40u: goto P_0c0a8c40;
case 0x0c0a8c42u: goto P_0c0a8c42;
case 0x0c0a8c44u: goto P_0c0a8c44;
case 0x0c0a8c46u: goto P_0c0a8c46;
case 0x0c0a8c48u: goto P_0c0a8c48;
case 0x0c0a8c4au: goto P_0c0a8c4a;
case 0x0c0a8c4cu: goto P_0c0a8c4c;
case 0x0c0a8c4eu: goto P_0c0a8c4e;
case 0x0c0a8c50u: goto P_0c0a8c50;
case 0x0c0a8c52u: goto P_0c0a8c52;
case 0x0c0a8c54u: goto P_0c0a8c54;
case 0x0c0a8c56u: goto P_0c0a8c56;
case 0x0c0a8c58u: goto P_0c0a8c58;
case 0x0c0a8c5au: goto P_0c0a8c5a;
case 0x0c0a8c5cu: goto P_0c0a8c5c;
case 0x0c0a8c5eu: goto P_0c0a8c5e;
case 0x0c0a8c60u: goto P_0c0a8c60;
case 0x0c0a8c62u: goto P_0c0a8c62;
case 0x0c0a8c64u: goto P_0c0a8c64;
case 0x0c0a8c66u: goto P_0c0a8c66;
case 0x0c0a8c68u: goto P_0c0a8c68;
case 0x0c0a8c6au: goto P_0c0a8c6a;
case 0x0c0a8c6cu: goto P_0c0a8c6c;
case 0x0c0a8c6eu: goto P_0c0a8c6e;
case 0x0c0a8c70u: goto P_0c0a8c70;
case 0x0c0a8c72u: goto P_0c0a8c72;
case 0x0c0a8c74u: goto P_0c0a8c74;
case 0x0c0a8c76u: goto P_0c0a8c76;
case 0x0c0a8c78u: goto P_0c0a8c78;
case 0x0c0a8c7au: goto P_0c0a8c7a;
case 0x0c0a8c7cu: goto P_0c0a8c7c;
case 0x0c0a8c7eu: goto P_0c0a8c7e;
case 0x0c0a8c80u: goto P_0c0a8c80;
case 0x0c0a8c82u: goto P_0c0a8c82;
case 0x0c0a8c84u: goto P_0c0a8c84;
case 0x0c0a8c86u: goto P_0c0a8c86;
case 0x0c0a8c88u: goto P_0c0a8c88;
case 0x0c0a8c8au: goto P_0c0a8c8a;
case 0x0c0a8c8cu: goto P_0c0a8c8c;
case 0x0c0a8c8eu: goto P_0c0a8c8e;
case 0x0c0a8c90u: goto P_0c0a8c90;
case 0x0c0a8c92u: goto P_0c0a8c92;
case 0x0c0a8c94u: goto P_0c0a8c94;
case 0x0c0a8c96u: goto P_0c0a8c96;
case 0x0c0a8c98u: goto P_0c0a8c98;
case 0x0c0a8c9au: goto P_0c0a8c9a;
case 0x0c0a8c9cu: goto P_0c0a8c9c;
case 0x0c0a8c9eu: goto P_0c0a8c9e;
case 0x0c0a8ca0u: goto P_0c0a8ca0;
case 0x0c0a8ca2u: goto P_0c0a8ca2;
case 0x0c0a8ca4u: goto P_0c0a8ca4;
case 0x0c0a8ca6u: goto P_0c0a8ca6;
case 0x0c0a8ca8u: goto P_0c0a8ca8;
case 0x0c0a8caau: goto P_0c0a8caa;
case 0x0c0a8cacu: goto P_0c0a8cac;
case 0x0c0a8caeu: goto P_0c0a8cae;
case 0x0c0a8cb0u: goto P_0c0a8cb0;
case 0x0c0a8cb2u: goto P_0c0a8cb2;
case 0x0c0a8cb4u: goto P_0c0a8cb4;
case 0x0c0a8cb6u: goto P_0c0a8cb6;
case 0x0c0a8cb8u: goto P_0c0a8cb8;
case 0x0c0a8cbau: goto P_0c0a8cba;
case 0x0c0a8cbcu: goto P_0c0a8cbc;
case 0x0c0a8cbeu: goto P_0c0a8cbe;
case 0x0c0a8cc0u: goto P_0c0a8cc0;
case 0x0c0a8cc2u: goto P_0c0a8cc2;
case 0x0c0a8cc4u: goto P_0c0a8cc4;
case 0x0c0a8cc6u: goto P_0c0a8cc6;
case 0x0c0a8cc8u: goto P_0c0a8cc8;
case 0x0c0a8ccau: goto P_0c0a8cca;
case 0x0c0a8cccu: goto P_0c0a8ccc;
case 0x0c0a8cceu: goto P_0c0a8cce;
case 0x0c0a8cd0u: goto P_0c0a8cd0;
case 0x0c0a8cd2u: goto P_0c0a8cd2;
case 0x0c0a8cd4u: goto P_0c0a8cd4;
case 0x0c0a8cd6u: goto P_0c0a8cd6;
case 0x0c0a8cd8u: goto P_0c0a8cd8;
case 0x0c0a8cdau: goto P_0c0a8cda;
case 0x0c0a8cdcu: goto P_0c0a8cdc;
case 0x0c0a8cdeu: goto P_0c0a8cde;
case 0x0c0a8ce0u: goto P_0c0a8ce0;
case 0x0c0a8ce2u: goto P_0c0a8ce2;
case 0x0c0a8ce4u: goto P_0c0a8ce4;
case 0x0c0a8ce6u: goto P_0c0a8ce6;
case 0x0c0a8ce8u: goto P_0c0a8ce8;
case 0x0c0a8ceau: goto P_0c0a8cea;
case 0x0c0a8cecu: goto P_0c0a8cec;
case 0x0c0a8ceeu: goto P_0c0a8cee;
case 0x0c0a8cf0u: goto P_0c0a8cf0;
case 0x0c0a8cf2u: goto P_0c0a8cf2;
case 0x0c0a8cf4u: goto P_0c0a8cf4;
case 0x0c0a8cf6u: goto P_0c0a8cf6;
case 0x0c0a8cf8u: goto P_0c0a8cf8;
case 0x0c0a8cfau: goto P_0c0a8cfa;
case 0x0c0a8cfcu: goto P_0c0a8cfc;
case 0x0c0a8cfeu: goto P_0c0a8cfe;
case 0x0c0a8d00u: goto P_0c0a8d00;
case 0x0c0a8d02u: goto P_0c0a8d02;
case 0x0c0a8d04u: goto P_0c0a8d04;
case 0x0c0a8d06u: goto P_0c0a8d06;
case 0x0c0a8d08u: goto P_0c0a8d08;
case 0x0c0a8d0au: goto P_0c0a8d0a;
case 0x0c0a8d0cu: goto P_0c0a8d0c;
case 0x0c0a8d0eu: goto P_0c0a8d0e;
case 0x0c0a8d10u: goto P_0c0a8d10;
case 0x0c0a8d12u: goto P_0c0a8d12;
case 0x0c0a8d14u: goto P_0c0a8d14;
case 0x0c0a8d16u: goto P_0c0a8d16;
case 0x0c0a8d18u: goto P_0c0a8d18;
case 0x0c0a8d1au: goto P_0c0a8d1a;
case 0x0c0a8d1cu: goto P_0c0a8d1c;
case 0x0c0a8d1eu: goto P_0c0a8d1e;
case 0x0c0a8d20u: goto P_0c0a8d20;
case 0x0c0a8d22u: goto P_0c0a8d22;
case 0x0c0a8d24u: goto P_0c0a8d24;
case 0x0c0a8d26u: goto P_0c0a8d26;
case 0x0c0a8d28u: goto P_0c0a8d28;
default: return vf3_matrix_family(target,s,ram);
}
P_0c0a81ee: /* original 2fe6, guest PC 0x0c0a81ee */
if(!s->budget--) { s->failed_pc=0x0c0a81eeu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a81f0;
P_0c0a81f0: /* original 2fd6, guest PC 0x0c0a81f0 */
if(!s->budget--) { s->failed_pc=0x0c0a81f0u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a81f2;
P_0c0a81f2: /* original 2fc6, guest PC 0x0c0a81f2 */
if(!s->budget--) { s->failed_pc=0x0c0a81f2u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a81f4;
P_0c0a81f4: /* original 2fb6, guest PC 0x0c0a81f4 */
if(!s->budget--) { s->failed_pc=0x0c0a81f4u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a81f6;
P_0c0a81f6: /* original 6b43, guest PC 0x0c0a81f6 */
if(!s->budget--) { s->failed_pc=0x0c0a81f6u; return 0; }
r[11]=r[4];
goto P_0c0a81f8;
P_0c0a81f8: /* original 2fa6, guest PC 0x0c0a81f8 */
if(!s->budget--) { s->failed_pc=0x0c0a81f8u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a81fa;
P_0c0a81fa: /* original eaff, guest PC 0x0c0a81fa */
if(!s->budget--) { s->failed_pc=0x0c0a81fau; return 0; }
r[10]=0xffffffffu;
goto P_0c0a81fc;
P_0c0a81fc: /* original 4f22, guest PC 0x0c0a81fc */
if(!s->budget--) { s->failed_pc=0x0c0a81fcu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0a81fe;
P_0c0a81fe: /* original 4f12, guest PC 0x0c0a81fe */
if(!s->budget--) { s->failed_pc=0x0c0a81feu; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c0a8200;
P_0c0a8200: /* original 7ff0, guest PC 0x0c0a8200 */
if(!s->budget--) { s->failed_pc=0x0c0a8200u; return 0; }
r[15]+=0xfffffff0u;
goto P_0c0a8202;
P_0c0a8202: /* original 1f51, guest PC 0x0c0a8202 */
if(!s->budget--) { s->failed_pc=0x0c0a8202u; return 0; }
write(ram,r[15]+4,r[5],4);
goto P_0c0a8204;
P_0c0a8204: /* original 2f62, guest PC 0x0c0a8204 */
if(!s->budget--) { s->failed_pc=0x0c0a8204u; return 0; }
write(ram,r[15],r[6],4);
goto P_0c0a8206;
P_0c0a8206: /* original 1f72, guest PC 0x0c0a8206 */
if(!s->budget--) { s->failed_pc=0x0c0a8206u; return 0; }
write(ram,r[15]+8,r[7],4);
goto P_0c0a8208;
P_0c0a8208: /* original d32a, guest PC 0x0c0a8208 */
if(!s->budget--) { s->failed_pc=0x0c0a8208u; return 0; }
r[3]=read(ram,0x0c0a82b4u,4);
goto P_0c0a820a;
P_0c0a820a: /* original 9249, guest PC 0x0c0a820a */
if(!s->budget--) { s->failed_pc=0x0c0a820au; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a82a0u,2);
goto P_0c0a820c;
P_0c0a820c: /* original 6e32, guest PC 0x0c0a820c */
if(!s->budget--) { s->failed_pc=0x0c0a820cu; return 0; }
tmp=read(ram,r[3],4);
r[14]=tmp;
goto P_0c0a820e;
P_0c0a820e: /* original 3b23, guest PC 0x0c0a820e */
if(!s->budget--) { s->failed_pc=0x0c0a820eu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[11]>=(int32_t)r[2])!=0);
goto P_0c0a8210;
P_0c0a8210: /* original 8f03, guest PC 0x0c0a8210 */
if(!s->budget--) { s->failed_pc=0x0c0a8210u; return 0; }
cond=r[17]&1u;
r[12]=r[10];
if(!cond) { goto P_0c0a821a; }
goto P_0c0a8214;
P_0c0a8212: /* original 6ca3, guest PC 0x0c0a8212 */
if(!s->budget--) { s->failed_pc=0x0c0a8212u; return 0; }
r[12]=r[10];
goto P_0c0a8214;
P_0c0a8214: /* original dc28, guest PC 0x0c0a8214 */
if(!s->budget--) { s->failed_pc=0x0c0a8214u; return 0; }
r[12]=read(ram,0x0c0a82b8u,4);
goto P_0c0a8216;
P_0c0a8216: /* original a037, guest PC 0x0c0a8216 */
if(!s->budget--) { s->failed_pc=0x0c0a8216u; return 0; }
goto P_0c0a8288;
P_0c0a8218: /* original 0009, guest PC 0x0c0a8218 */
if(!s->budget--) { s->failed_pc=0x0c0a8218u; return 0; }
goto P_0c0a821a;
P_0c0a821a: /* original d028, guest PC 0x0c0a821a */
if(!s->budget--) { s->failed_pc=0x0c0a821au; return 0; }
r[0]=read(ram,0x0c0a82bcu,4);
goto P_0c0a821c;
P_0c0a821c: /* original 63b3, guest PC 0x0c0a821c */
if(!s->budget--) { s->failed_pc=0x0c0a821cu; return 0; }
r[3]=r[11];
goto P_0c0a821e;
P_0c0a821e: /* original 4308, guest PC 0x0c0a821e */
if(!s->budget--) { s->failed_pc=0x0c0a821eu; return 0; }
r[3]<<=2;
goto P_0c0a8220;
P_0c0a8220: /* original 023e, guest PC 0x0c0a8220 */
if(!s->budget--) { s->failed_pc=0x0c0a8220u; return 0; }
r[2]=read(ram,r[3]+r[0],4);
goto P_0c0a8222;
P_0c0a8222: /* original 1f23, guest PC 0x0c0a8222 */
if(!s->budget--) { s->failed_pc=0x0c0a8222u; return 0; }
write(ram,r[15]+12,r[2],4);
goto P_0c0a8224;
P_0c0a8224: /* original 63f2, guest PC 0x0c0a8224 */
if(!s->budget--) { s->failed_pc=0x0c0a8224u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c0a8226;
P_0c0a8226: /* original 2338, guest PC 0x0c0a8226 */
if(!s->budget--) { s->failed_pc=0x0c0a8226u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c0a8228;
P_0c0a8228: /* original 892e, guest PC 0x0c0a8228 */
if(!s->budget--) { s->failed_pc=0x0c0a8228u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a8288; }
goto P_0c0a822a;
P_0c0a822a: /* original 50f1, guest PC 0x0c0a822a */
if(!s->budget--) { s->failed_pc=0x0c0a822au; return 0; }
r[0]=read(ram,r[15]+4,4);
goto P_0c0a822c;
P_0c0a822c: /* original c803, guest PC 0x0c0a822c */
if(!s->budget--) { s->failed_pc=0x0c0a822cu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&3u)==0)!=0);
goto P_0c0a822e;
P_0c0a822e: /* original 8b2b, guest PC 0x0c0a822e */
if(!s->budget--) { s->failed_pc=0x0c0a822eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a8288; }
goto P_0c0a8230;
P_0c0a8230: /* original 85ed, guest PC 0x0c0a8230 */
if(!s->budget--) { s->failed_pc=0x0c0a8230u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+26,2);
goto P_0c0a8232;
P_0c0a8232: /* original ed1f, guest PC 0x0c0a8232 */
if(!s->budget--) { s->failed_pc=0x0c0a8232u; return 0; }
r[13]=0x0000001fu;
goto P_0c0a8234;
P_0c0a8234: /* original 600d, guest PC 0x0c0a8234 */
if(!s->budget--) { s->failed_pc=0x0c0a8234u; return 0; }
r[0]=r[0]&65535u;
goto P_0c0a8236;
P_0c0a8236: /* original 7001, guest PC 0x0c0a8236 */
if(!s->budget--) { s->failed_pc=0x0c0a8236u; return 0; }
r[0]+=0x00000001u;
goto P_0c0a8238;
P_0c0a8238: /* original 2d09, guest PC 0x0c0a8238 */
if(!s->budget--) { s->failed_pc=0x0c0a8238u; return 0; }
r[13]&=r[0];
goto P_0c0a823a;
P_0c0a823a: /* original 85eb, guest PC 0x0c0a823a */
if(!s->budget--) { s->failed_pc=0x0c0a823au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+22,2);
goto P_0c0a823c;
P_0c0a823c: /* original 600d, guest PC 0x0c0a823c */
if(!s->budget--) { s->failed_pc=0x0c0a823cu; return 0; }
r[0]=r[0]&65535u;
goto P_0c0a823e;
P_0c0a823e: /* original 3d00, guest PC 0x0c0a823e */
if(!s->budget--) { s->failed_pc=0x0c0a823eu; return 0; }
r[17]=(r[17]&~1u)|((r[13]==r[0])!=0);
goto P_0c0a8240;
P_0c0a8240: /* original 8922, guest PC 0x0c0a8240 */
if(!s->budget--) { s->failed_pc=0x0c0a8240u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a8288; }
goto P_0c0a8242;
P_0c0a8242: /* original be67, guest PC 0x0c0a8242 */
if(!s->budget--) { s->failed_pc=0x0c0a8242u; return 0; }
target=code_base|0x0c0a7f14u; r[16]=code_base|0x0c0a8246u;
r[4]=r[11];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a8246u) { target=s->pc; goto dispatch; }
goto P_0c0a8246;
P_0c0a8244: /* original 64b3, guest PC 0x0c0a8244 */
if(!s->budget--) { s->failed_pc=0x0c0a8244u; return 0; }
r[4]=r[11];
goto P_0c0a8246;
P_0c0a8246: /* original 2008, guest PC 0x0c0a8246 */
if(!s->budget--) { s->failed_pc=0x0c0a8246u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c0a8248;
P_0c0a8248: /* original 8b1e, guest PC 0x0c0a8248 */
if(!s->budget--) { s->failed_pc=0x0c0a8248u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a8288; }
goto P_0c0a824a;
P_0c0a824a: /* original e434, guest PC 0x0c0a824a */
if(!s->budget--) { s->failed_pc=0x0c0a824au; return 0; }
r[4]=0x00000034u;
goto P_0c0a824c;
P_0c0a824c: /* original 63e3, guest PC 0x0c0a824c */
if(!s->budget--) { s->failed_pc=0x0c0a824cu; return 0; }
r[3]=r[14];
goto P_0c0a824e;
P_0c0a824e: /* original 2d4f, guest PC 0x0c0a824e */
if(!s->budget--) { s->failed_pc=0x0c0a824eu; return 0; }
r[19]=(uint32_t)((int32_t)(int16_t)r[13]*(int32_t)(int16_t)r[4]);
goto P_0c0a8250;
P_0c0a8250: /* original 731c, guest PC 0x0c0a8250 */
if(!s->budget--) { s->failed_pc=0x0c0a8250u; return 0; }
r[3]+=0x0000001cu;
goto P_0c0a8252;
P_0c0a8252: /* original 60d3, guest PC 0x0c0a8252 */
if(!s->budget--) { s->failed_pc=0x0c0a8252u; return 0; }
r[0]=r[13];
goto P_0c0a8254;
P_0c0a8254: /* original 81ed, guest PC 0x0c0a8254 */
if(!s->budget--) { s->failed_pc=0x0c0a8254u; return 0; }
write(ram,r[14]+26,r[0],2);
goto P_0c0a8256;
P_0c0a8256: /* original e030, guest PC 0x0c0a8256 */
if(!s->budget--) { s->failed_pc=0x0c0a8256u; return 0; }
r[0]=0x00000030u;
goto P_0c0a8258;
P_0c0a8258: /* original 62f2, guest PC 0x0c0a8258 */
if(!s->budget--) { s->failed_pc=0x0c0a8258u; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c0a825a;
P_0c0a825a: /* original 6cd3, guest PC 0x0c0a825a */
if(!s->budget--) { s->failed_pc=0x0c0a825au; return 0; }
r[12]=r[13];
goto P_0c0a825c;
P_0c0a825c: /* original 041a, guest PC 0x0c0a825c */
if(!s->budget--) { s->failed_pc=0x0c0a825cu; return 0; }
r[4]=r[19];
goto P_0c0a825e;
P_0c0a825e: /* original 644f, guest PC 0x0c0a825e */
if(!s->budget--) { s->failed_pc=0x0c0a825eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)r[4];
goto P_0c0a8260;
P_0c0a8260: /* original 343c, guest PC 0x0c0a8260 */
if(!s->budget--) { s->failed_pc=0x0c0a8260u; return 0; }
r[4]+=r[3];
goto P_0c0a8262;
P_0c0a8262: /* original 6323, guest PC 0x0c0a8262 */
if(!s->budget--) { s->failed_pc=0x0c0a8262u; return 0; }
r[3]=r[2];
goto P_0c0a8264;
P_0c0a8264: /* original 2422, guest PC 0x0c0a8264 */
if(!s->budget--) { s->failed_pc=0x0c0a8264u; return 0; }
write(ram,r[4],r[2],4);
goto P_0c0a8266;
P_0c0a8266: /* original e200, guest PC 0x0c0a8266 */
if(!s->budget--) { s->failed_pc=0x0c0a8266u; return 0; }
r[2]=0x00000000u;
goto P_0c0a8268;
P_0c0a8268: /* original 2322, guest PC 0x0c0a8268 */
if(!s->budget--) { s->failed_pc=0x0c0a8268u; return 0; }
write(ram,r[3],r[2],4);
goto P_0c0a826a;
P_0c0a826a: /* original 53f1, guest PC 0x0c0a826a */
if(!s->budget--) { s->failed_pc=0x0c0a826au; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c0a826c;
P_0c0a826c: /* original 1431, guest PC 0x0c0a826c */
if(!s->budget--) { s->failed_pc=0x0c0a826cu; return 0; }
write(ram,r[4]+4,r[3],4);
goto P_0c0a826e;
P_0c0a826e: /* original 14a7, guest PC 0x0c0a826e */
if(!s->budget--) { s->failed_pc=0x0c0a826eu; return 0; }
write(ram,r[4]+28,r[10],4);
goto P_0c0a8270;
P_0c0a8270: /* original 14a2, guest PC 0x0c0a8270 */
if(!s->budget--) { s->failed_pc=0x0c0a8270u; return 0; }
write(ram,r[4]+8,r[10],4);
goto P_0c0a8272;
P_0c0a8272: /* original 53f3, guest PC 0x0c0a8272 */
if(!s->budget--) { s->failed_pc=0x0c0a8272u; return 0; }
r[3]=read(ram,r[15]+12,4);
goto P_0c0a8274;
P_0c0a8274: /* original 1434, guest PC 0x0c0a8274 */
if(!s->budget--) { s->failed_pc=0x0c0a8274u; return 0; }
write(ram,r[4]+16,r[3],4);
goto P_0c0a8276;
P_0c0a8276: /* original 52f2, guest PC 0x0c0a8276 */
if(!s->budget--) { s->failed_pc=0x0c0a8276u; return 0; }
r[2]=read(ram,r[15]+8,4);
goto P_0c0a8278;
P_0c0a8278: /* original 1425, guest PC 0x0c0a8278 */
if(!s->budget--) { s->failed_pc=0x0c0a8278u; return 0; }
write(ram,r[4]+20,r[2],4);
goto P_0c0a827a;
P_0c0a827a: /* original 53fb, guest PC 0x0c0a827a */
if(!s->budget--) { s->failed_pc=0x0c0a827au; return 0; }
r[3]=read(ram,r[15]+44,4);
goto P_0c0a827c;
P_0c0a827c: /* original 1436, guest PC 0x0c0a827c */
if(!s->budget--) { s->failed_pc=0x0c0a827cu; return 0; }
write(ram,r[4]+24,r[3],4);
goto P_0c0a827e;
P_0c0a827e: /* original 52fc, guest PC 0x0c0a827e */
if(!s->budget--) { s->failed_pc=0x0c0a827eu; return 0; }
r[2]=read(ram,r[15]+48,4);
goto P_0c0a8280;
P_0c0a8280: /* original 142a, guest PC 0x0c0a8280 */
if(!s->budget--) { s->failed_pc=0x0c0a8280u; return 0; }
write(ram,r[4]+40,r[2],4);
goto P_0c0a8282;
P_0c0a8282: /* original 53fd, guest PC 0x0c0a8282 */
if(!s->budget--) { s->failed_pc=0x0c0a8282u; return 0; }
r[3]=read(ram,r[15]+52,4);
goto P_0c0a8284;
P_0c0a8284: /* original 143b, guest PC 0x0c0a8284 */
if(!s->budget--) { s->failed_pc=0x0c0a8284u; return 0; }
write(ram,r[4]+44,r[3],4);
goto P_0c0a8286;
P_0c0a8286: /* original 04b5, guest PC 0x0c0a8286 */
if(!s->budget--) { s->failed_pc=0x0c0a8286u; return 0; }
write(ram,r[4]+r[0],r[11],2);
goto P_0c0a8288;
P_0c0a8288: /* original 7f10, guest PC 0x0c0a8288 */
if(!s->budget--) { s->failed_pc=0x0c0a8288u; return 0; }
r[15]+=0x00000010u;
goto P_0c0a828a;
P_0c0a828a: /* original 60c3, guest PC 0x0c0a828a */
if(!s->budget--) { s->failed_pc=0x0c0a828au; return 0; }
r[0]=r[12];
goto P_0c0a828c;
P_0c0a828c: /* original 4f16, guest PC 0x0c0a828c */
if(!s->budget--) { s->failed_pc=0x0c0a828cu; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a828e;
P_0c0a828e: /* original 4f26, guest PC 0x0c0a828e */
if(!s->budget--) { s->failed_pc=0x0c0a828eu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a8290;
P_0c0a8290: /* original 6af6, guest PC 0x0c0a8290 */
if(!s->budget--) { s->failed_pc=0x0c0a8290u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0a8292;
P_0c0a8292: /* original 6bf6, guest PC 0x0c0a8292 */
if(!s->budget--) { s->failed_pc=0x0c0a8292u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0a8294;
P_0c0a8294: /* original 6cf6, guest PC 0x0c0a8294 */
if(!s->budget--) { s->failed_pc=0x0c0a8294u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0a8296;
P_0c0a8296: /* original 6df6, guest PC 0x0c0a8296 */
if(!s->budget--) { s->failed_pc=0x0c0a8296u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0a8298;
P_0c0a8298: /* original 000b, guest PC 0x0c0a8298 */
if(!s->budget--) { s->failed_pc=0x0c0a8298u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0a829a: /* original 6ef6, guest PC 0x0c0a829a */
if(!s->budget--) { s->failed_pc=0x0c0a829au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0a829cu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0a829cu; return 0; } return 1;
P_0c0a8ac0: /* original 2fe6, guest PC 0x0c0a8ac0 */
if(!s->budget--) { s->failed_pc=0x0c0a8ac0u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a8ac2;
P_0c0a8ac2: /* original 2fd6, guest PC 0x0c0a8ac2 */
if(!s->budget--) { s->failed_pc=0x0c0a8ac2u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a8ac4;
P_0c0a8ac4: /* original 2fc6, guest PC 0x0c0a8ac4 */
if(!s->budget--) { s->failed_pc=0x0c0a8ac4u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a8ac6;
P_0c0a8ac6: /* original 2fb6, guest PC 0x0c0a8ac6 */
if(!s->budget--) { s->failed_pc=0x0c0a8ac6u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a8ac8;
P_0c0a8ac8: /* original 2fa6, guest PC 0x0c0a8ac8 */
if(!s->budget--) { s->failed_pc=0x0c0a8ac8u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a8aca;
P_0c0a8aca: /* original 4f22, guest PC 0x0c0a8aca */
if(!s->budget--) { s->failed_pc=0x0c0a8acau; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0a8acc;
P_0c0a8acc: /* original d34f, guest PC 0x0c0a8acc */
if(!s->budget--) { s->failed_pc=0x0c0a8accu; return 0; }
r[3]=read(ram,0x0c0a8c0cu,4);
goto P_0c0a8ace;
P_0c0a8ace: /* original 4f12, guest PC 0x0c0a8ace */
if(!s->budget--) { s->failed_pc=0x0c0a8aceu; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c0a8ad0;
P_0c0a8ad0: /* original 7ff8, guest PC 0x0c0a8ad0 */
if(!s->budget--) { s->failed_pc=0x0c0a8ad0u; return 0; }
r[15]+=0xfffffff8u;
goto P_0c0a8ad2;
P_0c0a8ad2: /* original 430b, guest PC 0x0c0a8ad2 */
if(!s->budget--) { s->failed_pc=0x0c0a8ad2u; return 0; }
target=r[3];
r[16]=code_base|0x0c0a8ad6u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a8ad6u) { target=s->pc; goto dispatch; }
goto P_0c0a8ad6;
P_0c0a8ad4: /* original 0009, guest PC 0x0c0a8ad4 */
if(!s->budget--) { s->failed_pc=0x0c0a8ad4u; return 0; }
goto P_0c0a8ad6;
P_0c0a8ad6: /* original 2008, guest PC 0x0c0a8ad6 */
if(!s->budget--) { s->failed_pc=0x0c0a8ad6u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c0a8ad8;
P_0c0a8ad8: /* original 8b01, guest PC 0x0c0a8ad8 */
if(!s->budget--) { s->failed_pc=0x0c0a8ad8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a8ade; }
goto P_0c0a8ada;
P_0c0a8ada: /* original a11d, guest PC 0x0c0a8ada */
if(!s->budget--) { s->failed_pc=0x0c0a8adau; return 0; }
goto P_0c0a8d18;
P_0c0a8adc: /* original 0009, guest PC 0x0c0a8adc */
if(!s->budget--) { s->failed_pc=0x0c0a8adcu; return 0; }
goto P_0c0a8ade;
P_0c0a8ade: /* original de4c, guest PC 0x0c0a8ade */
if(!s->budget--) { s->failed_pc=0x0c0a8adeu; return 0; }
r[14]=read(ram,0x0c0a8c10u,4);
goto P_0c0a8ae0;
P_0c0a8ae0: /* original 53e4, guest PC 0x0c0a8ae0 */
if(!s->budget--) { s->failed_pc=0x0c0a8ae0u; return 0; }
r[3]=read(ram,r[14]+16,4);
goto P_0c0a8ae2;
P_0c0a8ae2: /* original 2f32, guest PC 0x0c0a8ae2 */
if(!s->budget--) { s->failed_pc=0x0c0a8ae2u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c0a8ae4;
P_0c0a8ae4: /* original 52e5, guest PC 0x0c0a8ae4 */
if(!s->budget--) { s->failed_pc=0x0c0a8ae4u; return 0; }
r[2]=read(ram,r[14]+20,4);
goto P_0c0a8ae6;
P_0c0a8ae6: /* original 1f21, guest PC 0x0c0a8ae6 */
if(!s->budget--) { s->failed_pc=0x0c0a8ae6u; return 0; }
write(ram,r[15]+4,r[2],4);
goto P_0c0a8ae8;
P_0c0a8ae8: /* original dd4a, guest PC 0x0c0a8ae8 */
if(!s->budget--) { s->failed_pc=0x0c0a8ae8u; return 0; }
r[13]=read(ram,0x0c0a8c14u,4);
goto P_0c0a8aea;
P_0c0a8aea: /* original 9085, guest PC 0x0c0a8aea */
if(!s->budget--) { s->failed_pc=0x0c0a8aeau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a8bf8u,2);
goto P_0c0a8aec;
P_0c0a8aec: /* original 0bdc, guest PC 0x0c0a8aec */
if(!s->budget--) { s->failed_pc=0x0c0a8aecu; return 0; }
r[11]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+r[0],1);
goto P_0c0a8aee;
P_0c0a8aee: /* original 64bc, guest PC 0x0c0a8aee */
if(!s->budget--) { s->failed_pc=0x0c0a8aeeu; return 0; }
r[4]=r[11]&255u;
goto P_0c0a8af0;
P_0c0a8af0: /* original 6043, guest PC 0x0c0a8af0 */
if(!s->budget--) { s->failed_pc=0x0c0a8af0u; return 0; }
r[0]=r[4];
goto P_0c0a8af2;
P_0c0a8af2: /* original 8802, guest PC 0x0c0a8af2 */
if(!s->budget--) { s->failed_pc=0x0c0a8af2u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c0a8af4;
P_0c0a8af4: /* original 8b03, guest PC 0x0c0a8af4 */
if(!s->budget--) { s->failed_pc=0x0c0a8af4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a8afe; }
goto P_0c0a8af6;
P_0c0a8af6: /* original 9080, guest PC 0x0c0a8af6 */
if(!s->budget--) { s->failed_pc=0x0c0a8af6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a8bfau,2);
goto P_0c0a8af8;
P_0c0a8af8: /* original e20e, guest PC 0x0c0a8af8 */
if(!s->budget--) { s->failed_pc=0x0c0a8af8u; return 0; }
r[2]=0x0000000eu;
goto P_0c0a8afa;
P_0c0a8afa: /* original 55e8, guest PC 0x0c0a8afa */
if(!s->budget--) { s->failed_pc=0x0c0a8afau; return 0; }
r[5]=read(ram,r[14]+32,4);
goto P_0c0a8afc;
P_0c0a8afc: /* original 0524, guest PC 0x0c0a8afc */
if(!s->budget--) { s->failed_pc=0x0c0a8afcu; return 0; }
write(ram,r[5]+r[0],r[2],1);
goto P_0c0a8afe;
P_0c0a8afe: /* original 6043, guest PC 0x0c0a8afe */
if(!s->budget--) { s->failed_pc=0x0c0a8afeu; return 0; }
r[0]=r[4];
goto P_0c0a8b00;
P_0c0a8b00: /* original dc46, guest PC 0x0c0a8b00 */
if(!s->budget--) { s->failed_pc=0x0c0a8b00u; return 0; }
r[12]=read(ram,0x0c0a8c1cu,4);
goto P_0c0a8b02;
P_0c0a8b02: /* original da45, guest PC 0x0c0a8b02 */
if(!s->budget--) { s->failed_pc=0x0c0a8b02u; return 0; }
r[10]=read(ram,0x0c0a8c18u,4);
goto P_0c0a8b04;
P_0c0a8b04: /* original 8804, guest PC 0x0c0a8b04 */
if(!s->budget--) { s->failed_pc=0x0c0a8b04u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000004u)!=0);
goto P_0c0a8b06;
P_0c0a8b06: /* original 8b04, guest PC 0x0c0a8b06 */
if(!s->budget--) { s->failed_pc=0x0c0a8b06u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a8b12; }
goto P_0c0a8b08;
P_0c0a8b08: /* original 9678, guest PC 0x0c0a8b08 */
if(!s->budget--) { s->failed_pc=0x0c0a8b08u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a8bfcu,2);
goto P_0c0a8b0a;
P_0c0a8b0a: /* original 9478, guest PC 0x0c0a8b0a */
if(!s->budget--) { s->failed_pc=0x0c0a8b0au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a8bfeu,2);
goto P_0c0a8b0c;
P_0c0a8b0c: /* original 36cc, guest PC 0x0c0a8b0c */
if(!s->budget--) { s->failed_pc=0x0c0a8b0cu; return 0; }
r[6]+=r[12];
goto P_0c0a8b0e;
P_0c0a8b0e: /* original 4a0b, guest PC 0x0c0a8b0e */
if(!s->budget--) { s->failed_pc=0x0c0a8b0eu; return 0; }
target=r[10];
r[16]=code_base|0x0c0a8b12u;
r[5]=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a8b12u) { target=s->pc; goto dispatch; }
goto P_0c0a8b12;
P_0c0a8b10: /* original 65c3, guest PC 0x0c0a8b10 */
if(!s->budget--) { s->failed_pc=0x0c0a8b10u; return 0; }
r[5]=r[12];
goto P_0c0a8b12;
P_0c0a8b12: /* original 9075, guest PC 0x0c0a8b12 */
if(!s->budget--) { s->failed_pc=0x0c0a8b12u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a8c00u,2);
goto P_0c0a8b14;
P_0c0a8b14: /* original e208, guest PC 0x0c0a8b14 */
if(!s->budget--) { s->failed_pc=0x0c0a8b14u; return 0; }
r[2]=0x00000008u;
goto P_0c0a8b16;
P_0c0a8b16: /* original 04dc, guest PC 0x0c0a8b16 */
if(!s->budget--) { s->failed_pc=0x0c0a8b16u; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+r[0],1);
goto P_0c0a8b18;
P_0c0a8b18: /* original 3423, guest PC 0x0c0a8b18 */
if(!s->budget--) { s->failed_pc=0x0c0a8b18u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=(int32_t)r[2])!=0);
goto P_0c0a8b1a;
P_0c0a8b1a: /* original 8b01, guest PC 0x0c0a8b1a */
if(!s->budget--) { s->failed_pc=0x0c0a8b1au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a8b20; }
goto P_0c0a8b1c;
P_0c0a8b1c: /* original a0f4, guest PC 0x0c0a8b1c */
if(!s->budget--) { s->failed_pc=0x0c0a8b1cu; return 0; }
goto P_0c0a8d08;
P_0c0a8b1e: /* original 0009, guest PC 0x0c0a8b1e */
if(!s->budget--) { s->failed_pc=0x0c0a8b1eu; return 0; }
goto P_0c0a8b20;
P_0c0a8b20: /* original 936f, guest PC 0x0c0a8b20 */
if(!s->budget--) { s->failed_pc=0x0c0a8b20u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a8c02u,2);
goto P_0c0a8b22;
P_0c0a8b22: /* original 644e, guest PC 0x0c0a8b22 */
if(!s->budget--) { s->failed_pc=0x0c0a8b22u; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)r[4];
goto P_0c0a8b24;
P_0c0a8b24: /* original 65bc, guest PC 0x0c0a8b24 */
if(!s->budget--) { s->failed_pc=0x0c0a8b24u; return 0; }
r[5]=r[11]&255u;
goto P_0c0a8b26;
P_0c0a8b26: /* original d23e, guest PC 0x0c0a8b26 */
if(!s->budget--) { s->failed_pc=0x0c0a8b26u; return 0; }
r[2]=read(ram,0x0c0a8c20u,4);
goto P_0c0a8b28;
P_0c0a8b28: /* original 243f, guest PC 0x0c0a8b28 */
if(!s->budget--) { s->failed_pc=0x0c0a8b28u; return 0; }
r[19]=(uint32_t)((int32_t)(int16_t)r[4]*(int32_t)(int16_t)r[3]);
goto P_0c0a8b2a;
P_0c0a8b2a: /* original 4508, guest PC 0x0c0a8b2a */
if(!s->budget--) { s->failed_pc=0x0c0a8b2au; return 0; }
r[5]<<=2;
goto P_0c0a8b2c;
P_0c0a8b2c: /* original 4508, guest PC 0x0c0a8b2c */
if(!s->budget--) { s->failed_pc=0x0c0a8b2cu; return 0; }
r[5]<<=2;
goto P_0c0a8b2e;
P_0c0a8b2e: /* original 4508, guest PC 0x0c0a8b2e */
if(!s->budget--) { s->failed_pc=0x0c0a8b2eu; return 0; }
r[5]<<=2;
goto P_0c0a8b30;
P_0c0a8b30: /* original 041a, guest PC 0x0c0a8b30 */
if(!s->budget--) { s->failed_pc=0x0c0a8b30u; return 0; }
r[4]=r[19];
goto P_0c0a8b32;
P_0c0a8b32: /* original e01a, guest PC 0x0c0a8b32 */
if(!s->budget--) { s->failed_pc=0x0c0a8b32u; return 0; }
r[0]=0x0000001au;
goto P_0c0a8b34;
P_0c0a8b34: /* original 6b43, guest PC 0x0c0a8b34 */
if(!s->budget--) { s->failed_pc=0x0c0a8b34u; return 0; }
r[11]=r[4];
goto P_0c0a8b36;
P_0c0a8b36: /* original 3b5c, guest PC 0x0c0a8b36 */
if(!s->budget--) { s->failed_pc=0x0c0a8b36u; return 0; }
r[11]+=r[5];
goto P_0c0a8b38;
P_0c0a8b38: /* original 3b2c, guest PC 0x0c0a8b38 */
if(!s->budget--) { s->failed_pc=0x0c0a8b38u; return 0; }
r[11]+=r[2];
goto P_0c0a8b3a;
P_0c0a8b3a: /* original 04bc, guest PC 0x0c0a8b3a */
if(!s->budget--) { s->failed_pc=0x0c0a8b3au; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[11]+r[0],1);
goto P_0c0a8b3c;
P_0c0a8b3c: /* original 644c, guest PC 0x0c0a8b3c */
if(!s->budget--) { s->failed_pc=0x0c0a8b3cu; return 0; }
r[4]=r[4]&255u;
goto P_0c0a8b3e;
P_0c0a8b3e: /* original 2448, guest PC 0x0c0a8b3e */
if(!s->budget--) { s->failed_pc=0x0c0a8b3eu; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c0a8b40;
P_0c0a8b40: /* original 8911, guest PC 0x0c0a8b40 */
if(!s->budget--) { s->failed_pc=0x0c0a8b40u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a8b66; }
goto P_0c0a8b42;
P_0c0a8b42: /* original 55f1, guest PC 0x0c0a8b42 */
if(!s->budget--) { s->failed_pc=0x0c0a8b42u; return 0; }
r[5]=read(ram,r[15]+4,4);
goto P_0c0a8b44;
P_0c0a8b44: /* original 66b3, guest PC 0x0c0a8b44 */
if(!s->budget--) { s->failed_pc=0x0c0a8b44u; return 0; }
r[6]=r[11];
goto P_0c0a8b46;
P_0c0a8b46: /* original b107, guest PC 0x0c0a8b46 */
if(!s->budget--) { s->failed_pc=0x0c0a8b46u; return 0; }
target=code_base|0x0c0a8d58u; r[16]=code_base|0x0c0a8b4au;
tmp=read(ram,r[15],4);
r[4]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a8b4au) { target=s->pc; goto dispatch; }
goto P_0c0a8b4a;
P_0c0a8b48: /* original 64f2, guest PC 0x0c0a8b48 */
if(!s->budget--) { s->failed_pc=0x0c0a8b48u; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c0a8b4a;
P_0c0a8b4a: /* original 54e5, guest PC 0x0c0a8b4a */
if(!s->budget--) { s->failed_pc=0x0c0a8b4au; return 0; }
r[4]=read(ram,r[14]+20,4);
goto P_0c0a8b4c;
P_0c0a8b4c: /* original 7b20, guest PC 0x0c0a8b4c */
if(!s->budget--) { s->failed_pc=0x0c0a8b4cu; return 0; }
r[11]+=0x00000020u;
goto P_0c0a8b4e;
P_0c0a8b4e: /* original 55e4, guest PC 0x0c0a8b4e */
if(!s->budget--) { s->failed_pc=0x0c0a8b4eu; return 0; }
r[5]=read(ram,r[14]+16,4);
goto P_0c0a8b50;
P_0c0a8b50: /* original b102, guest PC 0x0c0a8b50 */
if(!s->budget--) { s->failed_pc=0x0c0a8b50u; return 0; }
target=code_base|0x0c0a8d58u; r[16]=code_base|0x0c0a8b54u;
r[6]=r[11];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a8b54u) { target=s->pc; goto dispatch; }
goto P_0c0a8b54;
P_0c0a8b52: /* original 66b3, guest PC 0x0c0a8b52 */
if(!s->budget--) { s->failed_pc=0x0c0a8b52u; return 0; }
r[6]=r[11];
goto P_0c0a8b54;
P_0c0a8b54: /* original 9050, guest PC 0x0c0a8b54 */
if(!s->budget--) { s->failed_pc=0x0c0a8b54u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a8bf8u,2);
goto P_0c0a8b56;
P_0c0a8b56: /* original 9255, guest PC 0x0c0a8b56 */
if(!s->budget--) { s->failed_pc=0x0c0a8b56u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a8c04u,2);
goto P_0c0a8b58;
P_0c0a8b58: /* original 04dc, guest PC 0x0c0a8b58 */
if(!s->budget--) { s->failed_pc=0x0c0a8b58u; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+r[0],1);
goto P_0c0a8b5a;
P_0c0a8b5a: /* original 7401, guest PC 0x0c0a8b5a */
if(!s->budget--) { s->failed_pc=0x0c0a8b5au; return 0; }
r[4]+=0x00000001u;
goto P_0c0a8b5c;
P_0c0a8b5c: /* original 634c, guest PC 0x0c0a8b5c */
if(!s->budget--) { s->failed_pc=0x0c0a8b5cu; return 0; }
r[3]=r[4]&255u;
goto P_0c0a8b5e;
P_0c0a8b5e: /* original 3323, guest PC 0x0c0a8b5e */
if(!s->budget--) { s->failed_pc=0x0c0a8b5eu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>=(int32_t)r[2])!=0);
goto P_0c0a8b60;
P_0c0a8b60: /* original 8901, guest PC 0x0c0a8b60 */
if(!s->budget--) { s->failed_pc=0x0c0a8b60u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a8b66; }
goto P_0c0a8b62;
P_0c0a8b62: /* original a099, guest PC 0x0c0a8b62 */
if(!s->budget--) { s->failed_pc=0x0c0a8b62u; return 0; }
goto P_0c0a8c98;
P_0c0a8b64: /* original 0009, guest PC 0x0c0a8b64 */
if(!s->budget--) { s->failed_pc=0x0c0a8b64u; return 0; }
goto P_0c0a8b66;
P_0c0a8b66: /* original 944e, guest PC 0x0c0a8b66 */
if(!s->budget--) { s->failed_pc=0x0c0a8b66u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a8c06u,2);
goto P_0c0a8b68;
P_0c0a8b68: /* original 66c3, guest PC 0x0c0a8b68 */
if(!s->budget--) { s->failed_pc=0x0c0a8b68u; return 0; }
r[6]=r[12];
goto P_0c0a8b6a;
P_0c0a8b6a: /* original 7658, guest PC 0x0c0a8b6a */
if(!s->budget--) { s->failed_pc=0x0c0a8b6au; return 0; }
r[6]+=0x00000058u;
goto P_0c0a8b6c;
P_0c0a8b6c: /* original 4a0b, guest PC 0x0c0a8b6c */
if(!s->budget--) { s->failed_pc=0x0c0a8b6cu; return 0; }
target=r[10];
r[16]=code_base|0x0c0a8b70u;
r[5]=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a8b70u) { target=s->pc; goto dispatch; }
goto P_0c0a8b70;
P_0c0a8b6e: /* original 65c3, guest PC 0x0c0a8b6e */
if(!s->budget--) { s->failed_pc=0x0c0a8b6eu; return 0; }
r[5]=r[12];
goto P_0c0a8b70;
P_0c0a8b70: /* original 9046, guest PC 0x0c0a8b70 */
if(!s->budget--) { s->failed_pc=0x0c0a8b70u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a8c00u,2);
goto P_0c0a8b72;
P_0c0a8b72: /* original e208, guest PC 0x0c0a8b72 */
if(!s->budget--) { s->failed_pc=0x0c0a8b72u; return 0; }
r[2]=0x00000008u;
goto P_0c0a8b74;
P_0c0a8b74: /* original 04dc, guest PC 0x0c0a8b74 */
if(!s->budget--) { s->failed_pc=0x0c0a8b74u; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+r[0],1);
goto P_0c0a8b76;
P_0c0a8b76: /* original 7401, guest PC 0x0c0a8b76 */
if(!s->budget--) { s->failed_pc=0x0c0a8b76u; return 0; }
r[4]+=0x00000001u;
goto P_0c0a8b78;
P_0c0a8b78: /* original 634e, guest PC 0x0c0a8b78 */
if(!s->budget--) { s->failed_pc=0x0c0a8b78u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)r[4];
goto P_0c0a8b7a;
P_0c0a8b7a: /* original 3323, guest PC 0x0c0a8b7a */
if(!s->budget--) { s->failed_pc=0x0c0a8b7au; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>=(int32_t)r[2])!=0);
goto P_0c0a8b7c;
P_0c0a8b7c: /* original 8f02, guest PC 0x0c0a8b7c */
if(!s->budget--) { s->failed_pc=0x0c0a8b7cu; return 0; }
cond=r[17]&1u;
write(ram,r[13]+r[0],r[4],1);
if(!cond) { goto P_0c0a8b84; }
goto P_0c0a8b80;
P_0c0a8b7e: /* original 0d44, guest PC 0x0c0a8b7e */
if(!s->budget--) { s->failed_pc=0x0c0a8b7eu; return 0; }
write(ram,r[13]+r[0],r[4],1);
goto P_0c0a8b80;
P_0c0a8b80: /* original a0c2, guest PC 0x0c0a8b80 */
if(!s->budget--) { s->failed_pc=0x0c0a8b80u; return 0; }
goto P_0c0a8d08;
P_0c0a8b82: /* original 0009, guest PC 0x0c0a8b82 */
if(!s->budget--) { s->failed_pc=0x0c0a8b82u; return 0; }
goto P_0c0a8b84;
P_0c0a8b84: /* original 6c4e, guest PC 0x0c0a8b84 */
if(!s->budget--) { s->failed_pc=0x0c0a8b84u; return 0; }
r[12]=(uint32_t)(int32_t)(int8_t)r[4];
goto P_0c0a8b86;
P_0c0a8b86: /* original 923f, guest PC 0x0c0a8b86 */
if(!s->budget--) { s->failed_pc=0x0c0a8b86u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a8c08u,2);
goto P_0c0a8b88;
P_0c0a8b88: /* original 63c3, guest PC 0x0c0a8b88 */
if(!s->budget--) { s->failed_pc=0x0c0a8b88u; return 0; }
r[3]=r[12];
goto P_0c0a8b8a;
P_0c0a8b8a: /* original 4c00, guest PC 0x0c0a8b8a */
if(!s->budget--) { s->failed_pc=0x0c0a8b8au; return 0; }
r[17]=(r[17]&~1u)|((r[12]>>31)!=0);
r[12]<<=1;
goto P_0c0a8b8c;
P_0c0a8b8c: /* original 32dc, guest PC 0x0c0a8b8c */
if(!s->budget--) { s->failed_pc=0x0c0a8b8cu; return 0; }
r[2]+=r[13];
goto P_0c0a8b8e;
P_0c0a8b8e: /* original 57e5, guest PC 0x0c0a8b8e */
if(!s->budget--) { s->failed_pc=0x0c0a8b8eu; return 0; }
r[7]=read(ram,r[14]+20,4);
goto P_0c0a8b90;
P_0c0a8b90: /* original 3c3c, guest PC 0x0c0a8b90 */
if(!s->budget--) { s->failed_pc=0x0c0a8b90u; return 0; }
r[12]+=r[3];
goto P_0c0a8b92;
P_0c0a8b92: /* original 56e4, guest PC 0x0c0a8b92 */
if(!s->budget--) { s->failed_pc=0x0c0a8b92u; return 0; }
r[6]=read(ram,r[14]+16,4);
goto P_0c0a8b94;
P_0c0a8b94: /* original 3c2c, guest PC 0x0c0a8b94 */
if(!s->budget--) { s->failed_pc=0x0c0a8b94u; return 0; }
r[12]+=r[2];
goto P_0c0a8b96;
P_0c0a8b96: /* original 63c0, guest PC 0x0c0a8b96 */
if(!s->budget--) { s->failed_pc=0x0c0a8b96u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[12],1);
r[3]=tmp;
goto P_0c0a8b98;
P_0c0a8b98: /* original e20d, guest PC 0x0c0a8b98 */
if(!s->budget--) { s->failed_pc=0x0c0a8b98u; return 0; }
r[2]=0x0000000du;
goto P_0c0a8b9a;
P_0c0a8b9a: /* original 2f30, guest PC 0x0c0a8b9a */
if(!s->budget--) { s->failed_pc=0x0c0a8b9au; return 0; }
write(ram,r[15],r[3],1);
goto P_0c0a8b9c;
P_0c0a8b9c: /* original 84c1, guest PC 0x0c0a8b9c */
if(!s->budget--) { s->failed_pc=0x0c0a8b9cu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[12]+1,1);
goto P_0c0a8b9e;
P_0c0a8b9e: /* original 6503, guest PC 0x0c0a8b9e */
if(!s->budget--) { s->failed_pc=0x0c0a8b9eu; return 0; }
r[5]=r[0];
goto P_0c0a8ba0;
P_0c0a8ba0: /* original 84c2, guest PC 0x0c0a8ba0 */
if(!s->budget--) { s->failed_pc=0x0c0a8ba0u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[12]+2,1);
goto P_0c0a8ba2;
P_0c0a8ba2: /* original 635e, guest PC 0x0c0a8ba2 */
if(!s->budget--) { s->failed_pc=0x0c0a8ba2u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)r[5];
goto P_0c0a8ba4;
P_0c0a8ba4: /* original 6403, guest PC 0x0c0a8ba4 */
if(!s->budget--) { s->failed_pc=0x0c0a8ba4u; return 0; }
r[4]=r[0];
goto P_0c0a8ba6;
P_0c0a8ba6: /* original 3323, guest PC 0x0c0a8ba6 */
if(!s->budget--) { s->failed_pc=0x0c0a8ba6u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>=(int32_t)r[2])!=0);
goto P_0c0a8ba8;
P_0c0a8ba8: /* original e060, guest PC 0x0c0a8ba8 */
if(!s->budget--) { s->failed_pc=0x0c0a8ba8u; return 0; }
r[0]=0x00000060u;
goto P_0c0a8baa;
P_0c0a8baa: /* original 8f01, guest PC 0x0c0a8baa */
if(!s->budget--) { s->failed_pc=0x0c0a8baau; return 0; }
cond=r[17]&1u;
write(ram,r[6]+r[0],r[5],1);
if(!cond) { goto P_0c0a8bb0; }
goto P_0c0a8bae;
P_0c0a8bac: /* original 0654, guest PC 0x0c0a8bac */
if(!s->budget--) { s->failed_pc=0x0c0a8bacu; return 0; }
write(ram,r[6]+r[0],r[5],1);
goto P_0c0a8bae;
P_0c0a8bae: /* original 3528, guest PC 0x0c0a8bae */
if(!s->budget--) { s->failed_pc=0x0c0a8baeu; return 0; }
r[5]-=r[2];
goto P_0c0a8bb0;
P_0c0a8bb0: /* original e061, guest PC 0x0c0a8bb0 */
if(!s->budget--) { s->failed_pc=0x0c0a8bb0u; return 0; }
r[0]=0x00000061u;
goto P_0c0a8bb2;
P_0c0a8bb2: /* original 634e, guest PC 0x0c0a8bb2 */
if(!s->budget--) { s->failed_pc=0x0c0a8bb2u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)r[4];
goto P_0c0a8bb4;
P_0c0a8bb4: /* original 0654, guest PC 0x0c0a8bb4 */
if(!s->budget--) { s->failed_pc=0x0c0a8bb4u; return 0; }
write(ram,r[6]+r[0],r[5],1);
goto P_0c0a8bb6;
P_0c0a8bb6: /* original e20d, guest PC 0x0c0a8bb6 */
if(!s->budget--) { s->failed_pc=0x0c0a8bb6u; return 0; }
r[2]=0x0000000du;
goto P_0c0a8bb8;
P_0c0a8bb8: /* original 3323, guest PC 0x0c0a8bb8 */
if(!s->budget--) { s->failed_pc=0x0c0a8bb8u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>=(int32_t)r[2])!=0);
goto P_0c0a8bba;
P_0c0a8bba: /* original e060, guest PC 0x0c0a8bba */
if(!s->budget--) { s->failed_pc=0x0c0a8bbau; return 0; }
r[0]=0x00000060u;
goto P_0c0a8bbc;
P_0c0a8bbc: /* original 8f01, guest PC 0x0c0a8bbc */
if(!s->budget--) { s->failed_pc=0x0c0a8bbcu; return 0; }
cond=r[17]&1u;
write(ram,r[7]+r[0],r[4],1);
if(!cond) { goto P_0c0a8bc2; }
goto P_0c0a8bc0;
P_0c0a8bbe: /* original 0744, guest PC 0x0c0a8bbe */
if(!s->budget--) { s->failed_pc=0x0c0a8bbeu; return 0; }
write(ram,r[7]+r[0],r[4],1);
goto P_0c0a8bc0;
P_0c0a8bc0: /* original 3428, guest PC 0x0c0a8bc0 */
if(!s->budget--) { s->failed_pc=0x0c0a8bc0u; return 0; }
r[4]-=r[2];
goto P_0c0a8bc2;
P_0c0a8bc2: /* original e061, guest PC 0x0c0a8bc2 */
if(!s->budget--) { s->failed_pc=0x0c0a8bc2u; return 0; }
r[0]=0x00000061u;
goto P_0c0a8bc4;
P_0c0a8bc4: /* original 0744, guest PC 0x0c0a8bc4 */
if(!s->budget--) { s->failed_pc=0x0c0a8bc4u; return 0; }
write(ram,r[7]+r[0],r[4],1);
goto P_0c0a8bc6;
P_0c0a8bc6: /* original d217, guest PC 0x0c0a8bc6 */
if(!s->budget--) { s->failed_pc=0x0c0a8bc6u; return 0; }
r[2]=read(ram,0x0c0a8c24u,4);
goto P_0c0a8bc8;
P_0c0a8bc8: /* original d117, guest PC 0x0c0a8bc8 */
if(!s->budget--) { s->failed_pc=0x0c0a8bc8u; return 0; }
r[1]=read(ram,0x0c0a8c28u,4);
goto P_0c0a8bca;
P_0c0a8bca: /* original 63f0, guest PC 0x0c0a8bca */
if(!s->budget--) { s->failed_pc=0x0c0a8bcau; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[15],1);
r[3]=tmp;
goto P_0c0a8bcc;
P_0c0a8bcc: /* original 410b, guest PC 0x0c0a8bcc */
if(!s->budget--) { s->failed_pc=0x0c0a8bccu; return 0; }
target=r[1];
r[16]=code_base|0x0c0a8bd0u;
write(ram,r[2],r[3],1);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a8bd0u) { target=s->pc; goto dispatch; }
goto P_0c0a8bd0;
P_0c0a8bce: /* original 2230, guest PC 0x0c0a8bce */
if(!s->budget--) { s->failed_pc=0x0c0a8bceu; return 0; }
write(ram,r[2],r[3],1);
goto P_0c0a8bd0;
P_0c0a8bd0: /* original d316, guest PC 0x0c0a8bd0 */
if(!s->budget--) { s->failed_pc=0x0c0a8bd0u; return 0; }
r[3]=read(ram,0x0c0a8c2cu,4);
goto P_0c0a8bd2;
P_0c0a8bd2: /* original 430b, guest PC 0x0c0a8bd2 */
if(!s->budget--) { s->failed_pc=0x0c0a8bd2u; return 0; }
target=r[3];
r[16]=code_base|0x0c0a8bd6u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a8bd6u) { target=s->pc; goto dispatch; }
goto P_0c0a8bd6;
P_0c0a8bd4: /* original 0009, guest PC 0x0c0a8bd4 */
if(!s->budget--) { s->failed_pc=0x0c0a8bd4u; return 0; }
goto P_0c0a8bd6;
P_0c0a8bd6: /* original d516, guest PC 0x0c0a8bd6 */
if(!s->budget--) { s->failed_pc=0x0c0a8bd6u; return 0; }
r[5]=read(ram,0x0c0a8c30u,4);
goto P_0c0a8bd8;
P_0c0a8bd8: /* original e201, guest PC 0x0c0a8bd8 */
if(!s->budget--) { s->failed_pc=0x0c0a8bd8u; return 0; }
r[2]=0x00000001u;
goto P_0c0a8bda;
P_0c0a8bda: /* original 5451, guest PC 0x0c0a8bda */
if(!s->budget--) { s->failed_pc=0x0c0a8bdau; return 0; }
r[4]=read(ram,r[5]+4,4);
goto P_0c0a8bdc;
P_0c0a8bdc: /* original 242b, guest PC 0x0c0a8bdc */
if(!s->budget--) { s->failed_pc=0x0c0a8bdcu; return 0; }
r[4]|=r[2];
goto P_0c0a8bde;
P_0c0a8bde: /* original 1541, guest PC 0x0c0a8bde */
if(!s->budget--) { s->failed_pc=0x0c0a8bdeu; return 0; }
write(ram,r[5]+4,r[4],4);
goto P_0c0a8be0;
P_0c0a8be0: /* original 900e, guest PC 0x0c0a8be0 */
if(!s->budget--) { s->failed_pc=0x0c0a8be0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a8c00u,2);
goto P_0c0a8be2;
P_0c0a8be2: /* original 9312, guest PC 0x0c0a8be2 */
if(!s->budget--) { s->failed_pc=0x0c0a8be2u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a8c0au,2);
goto P_0c0a8be4;
P_0c0a8be4: /* original 04dc, guest PC 0x0c0a8be4 */
if(!s->budget--) { s->failed_pc=0x0c0a8be4u; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+r[0],1);
goto P_0c0a8be6;
P_0c0a8be6: /* original 33dc, guest PC 0x0c0a8be6 */
if(!s->budget--) { s->failed_pc=0x0c0a8be6u; return 0; }
r[3]+=r[13];
goto P_0c0a8be8;
P_0c0a8be8: /* original d112, guest PC 0x0c0a8be8 */
if(!s->budget--) { s->failed_pc=0x0c0a8be8u; return 0; }
r[1]=read(ram,0x0c0a8c34u,4);
goto P_0c0a8bea;
P_0c0a8bea: /* original 654e, guest PC 0x0c0a8bea */
if(!s->budget--) { s->failed_pc=0x0c0a8beau; return 0; }
r[5]=(uint32_t)(int32_t)(int8_t)r[4];
goto P_0c0a8bec;
P_0c0a8bec: /* original 4508, guest PC 0x0c0a8bec */
if(!s->budget--) { s->failed_pc=0x0c0a8becu; return 0; }
r[5]<<=2;
goto P_0c0a8bee;
P_0c0a8bee: /* original 353c, guest PC 0x0c0a8bee */
if(!s->budget--) { s->failed_pc=0x0c0a8beeu; return 0; }
r[5]+=r[3];
goto P_0c0a8bf0;
P_0c0a8bf0: /* original 6552, guest PC 0x0c0a8bf0 */
if(!s->budget--) { s->failed_pc=0x0c0a8bf0u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0a8bf2;
P_0c0a8bf2: /* original 2152, guest PC 0x0c0a8bf2 */
if(!s->budget--) { s->failed_pc=0x0c0a8bf2u; return 0; }
write(ram,r[1],r[5],4);
goto P_0c0a8bf4;
P_0c0a8bf4: /* original a020, guest PC 0x0c0a8bf4 */
if(!s->budget--) { s->failed_pc=0x0c0a8bf4u; return 0; }
goto P_0c0a8c38;
P_0c0a8bf6: /* original 0009, guest PC 0x0c0a8bf6 */
if(!s->budget--) { s->failed_pc=0x0c0a8bf6u; return 0; }
if(!vf3_matrix_family(0x0c0a8bf8u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0a8bf8u; return 0; } return 1;
P_0c0a8c38: /* original 9377, guest PC 0x0c0a8c38 */
if(!s->budget--) { s->failed_pc=0x0c0a8c38u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a8d2au,2);
goto P_0c0a8c3a;
P_0c0a8c3a: /* original 644e, guest PC 0x0c0a8c3a */
if(!s->budget--) { s->failed_pc=0x0c0a8c3au; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)r[4];
goto P_0c0a8c3c;
P_0c0a8c3c: /* original 70ff, guest PC 0x0c0a8c3c */
if(!s->budget--) { s->failed_pc=0x0c0a8c3cu; return 0; }
r[0]+=0xffffffffu;
goto P_0c0a8c3e;
P_0c0a8c3e: /* original d23d, guest PC 0x0c0a8c3e */
if(!s->budget--) { s->failed_pc=0x0c0a8c3eu; return 0; }
r[2]=read(ram,0x0c0a8d34u,4);
goto P_0c0a8c40;
P_0c0a8c40: /* original 243f, guest PC 0x0c0a8c40 */
if(!s->budget--) { s->failed_pc=0x0c0a8c40u; return 0; }
r[19]=(uint32_t)((int32_t)(int16_t)r[4]*(int32_t)(int16_t)r[3]);
goto P_0c0a8c42;
P_0c0a8c42: /* original 05dc, guest PC 0x0c0a8c42 */
if(!s->budget--) { s->failed_pc=0x0c0a8c42u; return 0; }
r[5]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+r[0],1);
goto P_0c0a8c44;
P_0c0a8c44: /* original e004, guest PC 0x0c0a8c44 */
if(!s->budget--) { s->failed_pc=0x0c0a8c44u; return 0; }
r[0]=0x00000004u;
goto P_0c0a8c46;
P_0c0a8c46: /* original 655c, guest PC 0x0c0a8c46 */
if(!s->budget--) { s->failed_pc=0x0c0a8c46u; return 0; }
r[5]=r[5]&255u;
goto P_0c0a8c48;
P_0c0a8c48: /* original 041a, guest PC 0x0c0a8c48 */
if(!s->budget--) { s->failed_pc=0x0c0a8c48u; return 0; }
r[4]=r[19];
goto P_0c0a8c4a;
P_0c0a8c4a: /* original 4508, guest PC 0x0c0a8c4a */
if(!s->budget--) { s->failed_pc=0x0c0a8c4au; return 0; }
r[5]<<=2;
goto P_0c0a8c4c;
P_0c0a8c4c: /* original 4508, guest PC 0x0c0a8c4c */
if(!s->budget--) { s->failed_pc=0x0c0a8c4cu; return 0; }
r[5]<<=2;
goto P_0c0a8c4e;
P_0c0a8c4e: /* original 6c43, guest PC 0x0c0a8c4e */
if(!s->budget--) { s->failed_pc=0x0c0a8c4eu; return 0; }
r[12]=r[4];
goto P_0c0a8c50;
P_0c0a8c50: /* original 4508, guest PC 0x0c0a8c50 */
if(!s->budget--) { s->failed_pc=0x0c0a8c50u; return 0; }
r[5]<<=2;
goto P_0c0a8c52;
P_0c0a8c52: /* original 3c5c, guest PC 0x0c0a8c52 */
if(!s->budget--) { s->failed_pc=0x0c0a8c52u; return 0; }
r[12]+=r[5];
goto P_0c0a8c54;
P_0c0a8c54: /* original 3c2c, guest PC 0x0c0a8c54 */
if(!s->budget--) { s->failed_pc=0x0c0a8c54u; return 0; }
r[12]+=r[2];
goto P_0c0a8c56;
P_0c0a8c56: /* original f4c6, guest PC 0x0c0a8c56 */
if(!s->budget--) { s->failed_pc=0x0c0a8c56u; return 0; }
vf3_matrix_load(s,ram,4,r[12]+r[0]);
goto P_0c0a8c58;
P_0c0a8c58: /* original e008, guest PC 0x0c0a8c58 */
if(!s->budget--) { s->failed_pc=0x0c0a8c58u; return 0; }
r[0]=0x00000008u;
goto P_0c0a8c5a;
P_0c0a8c5a: /* original f5c6, guest PC 0x0c0a8c5a */
if(!s->budget--) { s->failed_pc=0x0c0a8c5au; return 0; }
vf3_matrix_load(s,ram,5,r[12]+r[0]);
goto P_0c0a8c5c;
P_0c0a8c5c: /* original e00c, guest PC 0x0c0a8c5c */
if(!s->budget--) { s->failed_pc=0x0c0a8c5cu; return 0; }
r[0]=0x0000000cu;
goto P_0c0a8c5e;
P_0c0a8c5e: /* original f6c6, guest PC 0x0c0a8c5e */
if(!s->budget--) { s->failed_pc=0x0c0a8c5eu; return 0; }
vf3_matrix_load(s,ram,6,r[12]+r[0]);
goto P_0c0a8c60;
P_0c0a8c60: /* original 85ca, guest PC 0x0c0a8c60 */
if(!s->budget--) { s->failed_pc=0x0c0a8c60u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[12]+20,2);
goto P_0c0a8c62;
P_0c0a8c62: /* original 81f2, guest PC 0x0c0a8c62 */
if(!s->budget--) { s->failed_pc=0x0c0a8c62u; return 0; }
write(ram,r[15]+4,r[0],2);
goto P_0c0a8c64;
P_0c0a8c64: /* original 51e4, guest PC 0x0c0a8c64 */
if(!s->budget--) { s->failed_pc=0x0c0a8c64u; return 0; }
r[1]=read(ram,r[14]+16,4);
goto P_0c0a8c66;
P_0c0a8c66: /* original 6413, guest PC 0x0c0a8c66 */
if(!s->budget--) { s->failed_pc=0x0c0a8c66u; return 0; }
r[4]=r[1];
goto P_0c0a8c68;
P_0c0a8c68: /* original 2f12, guest PC 0x0c0a8c68 */
if(!s->budget--) { s->failed_pc=0x0c0a8c68u; return 0; }
write(ram,r[15],r[1],4);
goto P_0c0a8c6a;
P_0c0a8c6a: /* original 85f2, guest PC 0x0c0a8c6a */
if(!s->budget--) { s->failed_pc=0x0c0a8c6au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[15]+4,2);
goto P_0c0a8c6c;
P_0c0a8c6c: /* original d132, guest PC 0x0c0a8c6c */
if(!s->budget--) { s->failed_pc=0x0c0a8c6cu; return 0; }
r[1]=read(ram,0x0c0a8d38u,4);
goto P_0c0a8c6e;
P_0c0a8c6e: /* original 6603, guest PC 0x0c0a8c6e */
if(!s->budget--) { s->failed_pc=0x0c0a8c6eu; return 0; }
r[6]=r[0];
goto P_0c0a8c70;
P_0c0a8c70: /* original 410b, guest PC 0x0c0a8c70 */
if(!s->budget--) { s->failed_pc=0x0c0a8c70u; return 0; }
target=r[1];
r[16]=code_base|0x0c0a8c74u;
r[5]=0x00000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a8c74u) { target=s->pc; goto dispatch; }
goto P_0c0a8c74;
P_0c0a8c72: /* original e500, guest PC 0x0c0a8c72 */
if(!s->budget--) { s->failed_pc=0x0c0a8c72u; return 0; }
r[5]=0x00000000u;
goto P_0c0a8c74;
P_0c0a8c74: /* original e004, guest PC 0x0c0a8c74 */
if(!s->budget--) { s->failed_pc=0x0c0a8c74u; return 0; }
r[0]=0x00000004u;
goto P_0c0a8c76;
P_0c0a8c76: /* original 7c20, guest PC 0x0c0a8c76 */
if(!s->budget--) { s->failed_pc=0x0c0a8c76u; return 0; }
r[12]+=0x00000020u;
goto P_0c0a8c78;
P_0c0a8c78: /* original f4c6, guest PC 0x0c0a8c78 */
if(!s->budget--) { s->failed_pc=0x0c0a8c78u; return 0; }
vf3_matrix_load(s,ram,4,r[12]+r[0]);
goto P_0c0a8c7a;
P_0c0a8c7a: /* original e008, guest PC 0x0c0a8c7a */
if(!s->budget--) { s->failed_pc=0x0c0a8c7au; return 0; }
r[0]=0x00000008u;
goto P_0c0a8c7c;
P_0c0a8c7c: /* original f5c6, guest PC 0x0c0a8c7c */
if(!s->budget--) { s->failed_pc=0x0c0a8c7cu; return 0; }
vf3_matrix_load(s,ram,5,r[12]+r[0]);
goto P_0c0a8c7e;
P_0c0a8c7e: /* original e00c, guest PC 0x0c0a8c7e */
if(!s->budget--) { s->failed_pc=0x0c0a8c7eu; return 0; }
r[0]=0x0000000cu;
goto P_0c0a8c80;
P_0c0a8c80: /* original f6c6, guest PC 0x0c0a8c80 */
if(!s->budget--) { s->failed_pc=0x0c0a8c80u; return 0; }
vf3_matrix_load(s,ram,6,r[12]+r[0]);
goto P_0c0a8c82;
P_0c0a8c82: /* original 85ca, guest PC 0x0c0a8c82 */
if(!s->budget--) { s->failed_pc=0x0c0a8c82u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[12]+20,2);
goto P_0c0a8c84;
P_0c0a8c84: /* original 81f2, guest PC 0x0c0a8c84 */
if(!s->budget--) { s->failed_pc=0x0c0a8c84u; return 0; }
write(ram,r[15]+4,r[0],2);
goto P_0c0a8c86;
P_0c0a8c86: /* original 53e5, guest PC 0x0c0a8c86 */
if(!s->budget--) { s->failed_pc=0x0c0a8c86u; return 0; }
r[3]=read(ram,r[14]+20,4);
goto P_0c0a8c88;
P_0c0a8c88: /* original 6433, guest PC 0x0c0a8c88 */
if(!s->budget--) { s->failed_pc=0x0c0a8c88u; return 0; }
r[4]=r[3];
goto P_0c0a8c8a;
P_0c0a8c8a: /* original 2f32, guest PC 0x0c0a8c8a */
if(!s->budget--) { s->failed_pc=0x0c0a8c8au; return 0; }
write(ram,r[15],r[3],4);
goto P_0c0a8c8c;
P_0c0a8c8c: /* original 85f2, guest PC 0x0c0a8c8c */
if(!s->budget--) { s->failed_pc=0x0c0a8c8cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[15]+4,2);
goto P_0c0a8c8e;
P_0c0a8c8e: /* original d32a, guest PC 0x0c0a8c8e */
if(!s->budget--) { s->failed_pc=0x0c0a8c8eu; return 0; }
r[3]=read(ram,0x0c0a8d38u,4);
goto P_0c0a8c90;
P_0c0a8c90: /* original 6603, guest PC 0x0c0a8c90 */
if(!s->budget--) { s->failed_pc=0x0c0a8c90u; return 0; }
r[6]=r[0];
goto P_0c0a8c92;
P_0c0a8c92: /* original 430b, guest PC 0x0c0a8c92 */
if(!s->budget--) { s->failed_pc=0x0c0a8c92u; return 0; }
target=r[3];
r[16]=code_base|0x0c0a8c96u;
r[5]=0x00000001u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a8c96u) { target=s->pc; goto dispatch; }
goto P_0c0a8c96;
P_0c0a8c94: /* original e501, guest PC 0x0c0a8c94 */
if(!s->budget--) { s->failed_pc=0x0c0a8c94u; return 0; }
r[5]=0x00000001u;
goto P_0c0a8c96;
P_0c0a8c96: /* original e400, guest PC 0x0c0a8c96 */
if(!s->budget--) { s->failed_pc=0x0c0a8c96u; return 0; }
r[4]=0x00000000u;
goto P_0c0a8c98;
P_0c0a8c98: /* original 9048, guest PC 0x0c0a8c98 */
if(!s->budget--) { s->failed_pc=0x0c0a8c98u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a8d2cu,2);
goto P_0c0a8c9a;
P_0c0a8c9a: /* original 0d44, guest PC 0x0c0a8c9a */
if(!s->budget--) { s->failed_pc=0x0c0a8c9au; return 0; }
write(ram,r[13]+r[0],r[4],1);
goto P_0c0a8c9c;
P_0c0a8c9c: /* original d327, guest PC 0x0c0a8c9c */
if(!s->budget--) { s->failed_pc=0x0c0a8c9cu; return 0; }
r[3]=read(ram,0x0c0a8d3cu,4);
goto P_0c0a8c9e;
P_0c0a8c9e: /* original 54e4, guest PC 0x0c0a8c9e */
if(!s->budget--) { s->failed_pc=0x0c0a8c9eu; return 0; }
r[4]=read(ram,r[14]+16,4);
goto P_0c0a8ca0;
P_0c0a8ca0: /* original 430b, guest PC 0x0c0a8ca0 */
if(!s->budget--) { s->failed_pc=0x0c0a8ca0u; return 0; }
target=r[3];
r[16]=code_base|0x0c0a8ca4u;
r[5]=read(ram,r[14]+20,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a8ca4u) { target=s->pc; goto dispatch; }
goto P_0c0a8ca4;
P_0c0a8ca2: /* original 55e5, guest PC 0x0c0a8ca2 */
if(!s->budget--) { s->failed_pc=0x0c0a8ca2u; return 0; }
r[5]=read(ram,r[14]+20,4);
goto P_0c0a8ca4;
P_0c0a8ca4: /* original d225, guest PC 0x0c0a8ca4 */
if(!s->budget--) { s->failed_pc=0x0c0a8ca4u; return 0; }
r[2]=read(ram,0x0c0a8d3cu,4);
goto P_0c0a8ca6;
P_0c0a8ca6: /* original 54e5, guest PC 0x0c0a8ca6 */
if(!s->budget--) { s->failed_pc=0x0c0a8ca6u; return 0; }
r[4]=read(ram,r[14]+20,4);
goto P_0c0a8ca8;
P_0c0a8ca8: /* original 420b, guest PC 0x0c0a8ca8 */
if(!s->budget--) { s->failed_pc=0x0c0a8ca8u; return 0; }
target=r[2];
r[16]=code_base|0x0c0a8cacu;
r[5]=read(ram,r[14]+16,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a8cacu) { target=s->pc; goto dispatch; }
goto P_0c0a8cac;
P_0c0a8caa: /* original 55e4, guest PC 0x0c0a8caa */
if(!s->budget--) { s->failed_pc=0x0c0a8caau; return 0; }
r[5]=read(ram,r[14]+16,4);
goto P_0c0a8cac;
P_0c0a8cac: /* original 5de5, guest PC 0x0c0a8cac */
if(!s->budget--) { s->failed_pc=0x0c0a8cacu; return 0; }
r[13]=read(ram,r[14]+20,4);
goto P_0c0a8cae;
P_0c0a8cae: /* original d324, guest PC 0x0c0a8cae */
if(!s->budget--) { s->failed_pc=0x0c0a8caeu; return 0; }
r[3]=read(ram,0x0c0a8d40u,4);
goto P_0c0a8cb0;
P_0c0a8cb0: /* original 5ce4, guest PC 0x0c0a8cb0 */
if(!s->budget--) { s->failed_pc=0x0c0a8cb0u; return 0; }
r[12]=read(ram,r[14]+16,4);
goto P_0c0a8cb2;
P_0c0a8cb2: /* original 65d3, guest PC 0x0c0a8cb2 */
if(!s->budget--) { s->failed_pc=0x0c0a8cb2u; return 0; }
r[5]=r[13];
goto P_0c0a8cb4;
P_0c0a8cb4: /* original 430b, guest PC 0x0c0a8cb4 */
if(!s->budget--) { s->failed_pc=0x0c0a8cb4u; return 0; }
target=r[3];
r[16]=code_base|0x0c0a8cb8u;
r[4]=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a8cb8u) { target=s->pc; goto dispatch; }
goto P_0c0a8cb8;
P_0c0a8cb6: /* original 64c3, guest PC 0x0c0a8cb6 */
if(!s->budget--) { s->failed_pc=0x0c0a8cb6u; return 0; }
r[4]=r[12];
goto P_0c0a8cb8;
P_0c0a8cb8: /* original d222, guest PC 0x0c0a8cb8 */
if(!s->budget--) { s->failed_pc=0x0c0a8cb8u; return 0; }
r[2]=read(ram,0x0c0a8d44u,4);
goto P_0c0a8cba;
P_0c0a8cba: /* original 65d3, guest PC 0x0c0a8cba */
if(!s->budget--) { s->failed_pc=0x0c0a8cbau; return 0; }
r[5]=r[13];
goto P_0c0a8cbc;
P_0c0a8cbc: /* original 420b, guest PC 0x0c0a8cbc */
if(!s->budget--) { s->failed_pc=0x0c0a8cbcu; return 0; }
target=r[2];
r[16]=code_base|0x0c0a8cc0u;
r[4]=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a8cc0u) { target=s->pc; goto dispatch; }
goto P_0c0a8cc0;
P_0c0a8cbe: /* original 64c3, guest PC 0x0c0a8cbe */
if(!s->budget--) { s->failed_pc=0x0c0a8cbeu; return 0; }
r[4]=r[12];
goto P_0c0a8cc0;
P_0c0a8cc0: /* original d321, guest PC 0x0c0a8cc0 */
if(!s->budget--) { s->failed_pc=0x0c0a8cc0u; return 0; }
r[3]=read(ram,0x0c0a8d48u,4);
goto P_0c0a8cc2;
P_0c0a8cc2: /* original 65d3, guest PC 0x0c0a8cc2 */
if(!s->budget--) { s->failed_pc=0x0c0a8cc2u; return 0; }
r[5]=r[13];
goto P_0c0a8cc4;
P_0c0a8cc4: /* original 430b, guest PC 0x0c0a8cc4 */
if(!s->budget--) { s->failed_pc=0x0c0a8cc4u; return 0; }
target=r[3];
r[16]=code_base|0x0c0a8cc8u;
r[4]=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a8cc8u) { target=s->pc; goto dispatch; }
goto P_0c0a8cc8;
P_0c0a8cc6: /* original 64c3, guest PC 0x0c0a8cc6 */
if(!s->budget--) { s->failed_pc=0x0c0a8cc6u; return 0; }
r[4]=r[12];
goto P_0c0a8cc8;
P_0c0a8cc8: /* original d220, guest PC 0x0c0a8cc8 */
if(!s->budget--) { s->failed_pc=0x0c0a8cc8u; return 0; }
r[2]=read(ram,0x0c0a8d4cu,4);
goto P_0c0a8cca;
P_0c0a8cca: /* original 65d3, guest PC 0x0c0a8cca */
if(!s->budget--) { s->failed_pc=0x0c0a8ccau; return 0; }
r[5]=r[13];
goto P_0c0a8ccc;
P_0c0a8ccc: /* original 420b, guest PC 0x0c0a8ccc */
if(!s->budget--) { s->failed_pc=0x0c0a8cccu; return 0; }
target=r[2];
r[16]=code_base|0x0c0a8cd0u;
r[4]=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a8cd0u) { target=s->pc; goto dispatch; }
goto P_0c0a8cd0;
P_0c0a8cce: /* original 64c3, guest PC 0x0c0a8cce */
if(!s->budget--) { s->failed_pc=0x0c0a8cceu; return 0; }
r[4]=r[12];
goto P_0c0a8cd0;
P_0c0a8cd0: /* original 54e4, guest PC 0x0c0a8cd0 */
if(!s->budget--) { s->failed_pc=0x0c0a8cd0u; return 0; }
r[4]=read(ram,r[14]+16,4);
goto P_0c0a8cd2;
P_0c0a8cd2: /* original e061, guest PC 0x0c0a8cd2 */
if(!s->budget--) { s->failed_pc=0x0c0a8cd2u; return 0; }
r[0]=0x00000061u;
goto P_0c0a8cd4;
P_0c0a8cd4: /* original 054c, guest PC 0x0c0a8cd4 */
if(!s->budget--) { s->failed_pc=0x0c0a8cd4u; return 0; }
r[5]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c0a8cd6;
P_0c0a8cd6: /* original 605c, guest PC 0x0c0a8cd6 */
if(!s->budget--) { s->failed_pc=0x0c0a8cd6u; return 0; }
r[0]=r[5]&255u;
goto P_0c0a8cd8;
P_0c0a8cd8: /* original 880c, guest PC 0x0c0a8cd8 */
if(!s->budget--) { s->failed_pc=0x0c0a8cd8u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000cu)!=0);
goto P_0c0a8cda;
P_0c0a8cda: /* original 8906, guest PC 0x0c0a8cda */
if(!s->budget--) { s->failed_pc=0x0c0a8cdau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a8cea; }
goto P_0c0a8cdc;
P_0c0a8cdc: /* original d31c, guest PC 0x0c0a8cdc */
if(!s->budget--) { s->failed_pc=0x0c0a8cdcu; return 0; }
r[3]=read(ram,0x0c0a8d50u,4);
goto P_0c0a8cde;
P_0c0a8cde: /* original 6230, guest PC 0x0c0a8cde */
if(!s->budget--) { s->failed_pc=0x0c0a8cdeu; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[3],1);
r[2]=tmp;
goto P_0c0a8ce0;
P_0c0a8ce0: /* original 2228, guest PC 0x0c0a8ce0 */
if(!s->budget--) { s->failed_pc=0x0c0a8ce0u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c0a8ce2;
P_0c0a8ce2: /* original 8b02, guest PC 0x0c0a8ce2 */
if(!s->budget--) { s->failed_pc=0x0c0a8ce2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a8cea; }
goto P_0c0a8ce4;
P_0c0a8ce4: /* original d31b, guest PC 0x0c0a8ce4 */
if(!s->budget--) { s->failed_pc=0x0c0a8ce4u; return 0; }
r[3]=read(ram,0x0c0a8d54u,4);
goto P_0c0a8ce6;
P_0c0a8ce6: /* original 430b, guest PC 0x0c0a8ce6 */
if(!s->budget--) { s->failed_pc=0x0c0a8ce6u; return 0; }
target=r[3];
r[16]=code_base|0x0c0a8ceau;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a8ceau) { target=s->pc; goto dispatch; }
goto P_0c0a8cea;
P_0c0a8ce8: /* original 0009, guest PC 0x0c0a8ce8 */
if(!s->budget--) { s->failed_pc=0x0c0a8ce8u; return 0; }
goto P_0c0a8cea;
P_0c0a8cea: /* original 54e5, guest PC 0x0c0a8cea */
if(!s->budget--) { s->failed_pc=0x0c0a8ceau; return 0; }
r[4]=read(ram,r[14]+20,4);
goto P_0c0a8cec;
P_0c0a8cec: /* original e061, guest PC 0x0c0a8cec */
if(!s->budget--) { s->failed_pc=0x0c0a8cecu; return 0; }
r[0]=0x00000061u;
goto P_0c0a8cee;
P_0c0a8cee: /* original 054c, guest PC 0x0c0a8cee */
if(!s->budget--) { s->failed_pc=0x0c0a8ceeu; return 0; }
r[5]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c0a8cf0;
P_0c0a8cf0: /* original 605c, guest PC 0x0c0a8cf0 */
if(!s->budget--) { s->failed_pc=0x0c0a8cf0u; return 0; }
r[0]=r[5]&255u;
goto P_0c0a8cf2;
P_0c0a8cf2: /* original 880c, guest PC 0x0c0a8cf2 */
if(!s->budget--) { s->failed_pc=0x0c0a8cf2u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000cu)!=0);
goto P_0c0a8cf4;
P_0c0a8cf4: /* original 8910, guest PC 0x0c0a8cf4 */
if(!s->budget--) { s->failed_pc=0x0c0a8cf4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a8d18; }
goto P_0c0a8cf6;
P_0c0a8cf6: /* original d316, guest PC 0x0c0a8cf6 */
if(!s->budget--) { s->failed_pc=0x0c0a8cf6u; return 0; }
r[3]=read(ram,0x0c0a8d50u,4);
goto P_0c0a8cf8;
P_0c0a8cf8: /* original 6230, guest PC 0x0c0a8cf8 */
if(!s->budget--) { s->failed_pc=0x0c0a8cf8u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[3],1);
r[2]=tmp;
goto P_0c0a8cfa;
P_0c0a8cfa: /* original 2228, guest PC 0x0c0a8cfa */
if(!s->budget--) { s->failed_pc=0x0c0a8cfau; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c0a8cfc;
P_0c0a8cfc: /* original 8b0c, guest PC 0x0c0a8cfc */
if(!s->budget--) { s->failed_pc=0x0c0a8cfcu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a8d18; }
goto P_0c0a8cfe;
P_0c0a8cfe: /* original d315, guest PC 0x0c0a8cfe */
if(!s->budget--) { s->failed_pc=0x0c0a8cfeu; return 0; }
r[3]=read(ram,0x0c0a8d54u,4);
goto P_0c0a8d00;
P_0c0a8d00: /* original 430b, guest PC 0x0c0a8d00 */
if(!s->budget--) { s->failed_pc=0x0c0a8d00u; return 0; }
target=r[3];
r[16]=code_base|0x0c0a8d04u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a8d04u) { target=s->pc; goto dispatch; }
goto P_0c0a8d04;
P_0c0a8d02: /* original 0009, guest PC 0x0c0a8d02 */
if(!s->budget--) { s->failed_pc=0x0c0a8d02u; return 0; }
goto P_0c0a8d04;
P_0c0a8d04: /* original a008, guest PC 0x0c0a8d04 */
if(!s->budget--) { s->failed_pc=0x0c0a8d04u; return 0; }
goto P_0c0a8d18;
P_0c0a8d06: /* original 0009, guest PC 0x0c0a8d06 */
if(!s->budget--) { s->failed_pc=0x0c0a8d06u; return 0; }
goto P_0c0a8d08;
P_0c0a8d08: /* original 9011, guest PC 0x0c0a8d08 */
if(!s->budget--) { s->failed_pc=0x0c0a8d08u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a8d2eu,2);
goto P_0c0a8d0a;
P_0c0a8d0a: /* original 66c3, guest PC 0x0c0a8d0a */
if(!s->budget--) { s->failed_pc=0x0c0a8d0au; return 0; }
r[6]=r[12];
goto P_0c0a8d0c;
P_0c0a8d0c: /* original e201, guest PC 0x0c0a8d0c */
if(!s->budget--) { s->failed_pc=0x0c0a8d0cu; return 0; }
r[2]=0x00000001u;
goto P_0c0a8d0e;
P_0c0a8d0e: /* original 7658, guest PC 0x0c0a8d0e */
if(!s->budget--) { s->failed_pc=0x0c0a8d0eu; return 0; }
r[6]+=0x00000058u;
goto P_0c0a8d10;
P_0c0a8d10: /* original 0d24, guest PC 0x0c0a8d10 */
if(!s->budget--) { s->failed_pc=0x0c0a8d10u; return 0; }
write(ram,r[13]+r[0],r[2],1);
goto P_0c0a8d12;
P_0c0a8d12: /* original 940d, guest PC 0x0c0a8d12 */
if(!s->budget--) { s->failed_pc=0x0c0a8d12u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a8d30u,2);
goto P_0c0a8d14;
P_0c0a8d14: /* original 4a0b, guest PC 0x0c0a8d14 */
if(!s->budget--) { s->failed_pc=0x0c0a8d14u; return 0; }
target=r[10];
r[16]=code_base|0x0c0a8d18u;
r[5]=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a8d18u) { target=s->pc; goto dispatch; }
goto P_0c0a8d18;
P_0c0a8d16: /* original 65c3, guest PC 0x0c0a8d16 */
if(!s->budget--) { s->failed_pc=0x0c0a8d16u; return 0; }
r[5]=r[12];
goto P_0c0a8d18;
P_0c0a8d18: /* original 7f08, guest PC 0x0c0a8d18 */
if(!s->budget--) { s->failed_pc=0x0c0a8d18u; return 0; }
r[15]+=0x00000008u;
goto P_0c0a8d1a;
P_0c0a8d1a: /* original 4f16, guest PC 0x0c0a8d1a */
if(!s->budget--) { s->failed_pc=0x0c0a8d1au; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a8d1c;
P_0c0a8d1c: /* original 4f26, guest PC 0x0c0a8d1c */
if(!s->budget--) { s->failed_pc=0x0c0a8d1cu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a8d1e;
P_0c0a8d1e: /* original 6af6, guest PC 0x0c0a8d1e */
if(!s->budget--) { s->failed_pc=0x0c0a8d1eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0a8d20;
P_0c0a8d20: /* original 6bf6, guest PC 0x0c0a8d20 */
if(!s->budget--) { s->failed_pc=0x0c0a8d20u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0a8d22;
P_0c0a8d22: /* original 6cf6, guest PC 0x0c0a8d22 */
if(!s->budget--) { s->failed_pc=0x0c0a8d22u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0a8d24;
P_0c0a8d24: /* original 6df6, guest PC 0x0c0a8d24 */
if(!s->budget--) { s->failed_pc=0x0c0a8d24u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0a8d26;
P_0c0a8d26: /* original 000b, guest PC 0x0c0a8d26 */
if(!s->budget--) { s->failed_pc=0x0c0a8d26u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0a8d28: /* original 6ef6, guest PC 0x0c0a8d28 */
if(!s->budget--) { s->failed_pc=0x0c0a8d28u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0a8d2au,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0a8d2au; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
