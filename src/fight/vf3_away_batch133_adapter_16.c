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
int vf3_away_batch133_adapter_16(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c0a8952u: goto P_0c0a8952;
case 0x0c0a8954u: goto P_0c0a8954;
case 0x0c0a8956u: goto P_0c0a8956;
case 0x0c0a8958u: goto P_0c0a8958;
case 0x0c0a895au: goto P_0c0a895a;
case 0x0c0a895cu: goto P_0c0a895c;
case 0x0c0a895eu: goto P_0c0a895e;
case 0x0c0a8960u: goto P_0c0a8960;
case 0x0c0a8962u: goto P_0c0a8962;
case 0x0c0a8964u: goto P_0c0a8964;
case 0x0c0a8966u: goto P_0c0a8966;
case 0x0c0a8968u: goto P_0c0a8968;
case 0x0c0a896au: goto P_0c0a896a;
case 0x0c0a896cu: goto P_0c0a896c;
case 0x0c0a896eu: goto P_0c0a896e;
case 0x0c0a8970u: goto P_0c0a8970;
case 0x0c0a8972u: goto P_0c0a8972;
case 0x0c0a8974u: goto P_0c0a8974;
case 0x0c0a8976u: goto P_0c0a8976;
case 0x0c0a8978u: goto P_0c0a8978;
case 0x0c0a897au: goto P_0c0a897a;
case 0x0c0a897cu: goto P_0c0a897c;
case 0x0c0a897eu: goto P_0c0a897e;
case 0x0c0a8980u: goto P_0c0a8980;
case 0x0c0a8982u: goto P_0c0a8982;
case 0x0c0a8984u: goto P_0c0a8984;
case 0x0c0a8986u: goto P_0c0a8986;
case 0x0c0a8988u: goto P_0c0a8988;
case 0x0c0a898au: goto P_0c0a898a;
case 0x0c0a898cu: goto P_0c0a898c;
case 0x0c0a898eu: goto P_0c0a898e;
case 0x0c0a8990u: goto P_0c0a8990;
case 0x0c0a8992u: goto P_0c0a8992;
case 0x0c0a8994u: goto P_0c0a8994;
case 0x0c0a8996u: goto P_0c0a8996;
case 0x0c0a8998u: goto P_0c0a8998;
case 0x0c0a899au: goto P_0c0a899a;
case 0x0c0a899cu: goto P_0c0a899c;
case 0x0c0a899eu: goto P_0c0a899e;
case 0x0c0a89a0u: goto P_0c0a89a0;
case 0x0c0a89a2u: goto P_0c0a89a2;
case 0x0c0a89a4u: goto P_0c0a89a4;
case 0x0c0a89b4u: goto P_0c0a89b4;
case 0x0c0a89b6u: goto P_0c0a89b6;
case 0x0c0a89b8u: goto P_0c0a89b8;
case 0x0c0a89bau: goto P_0c0a89ba;
case 0x0c0a89bcu: goto P_0c0a89bc;
case 0x0c0a89beu: goto P_0c0a89be;
case 0x0c0a89c0u: goto P_0c0a89c0;
case 0x0c0a89c2u: goto P_0c0a89c2;
case 0x0c0a89c4u: goto P_0c0a89c4;
case 0x0c0a89c6u: goto P_0c0a89c6;
case 0x0c0a89c8u: goto P_0c0a89c8;
case 0x0c0a89cau: goto P_0c0a89ca;
case 0x0c0a89ccu: goto P_0c0a89cc;
case 0x0c0a89ceu: goto P_0c0a89ce;
case 0x0c0a89d0u: goto P_0c0a89d0;
case 0x0c0a89d2u: goto P_0c0a89d2;
case 0x0c0a89d4u: goto P_0c0a89d4;
case 0x0c0a89d6u: goto P_0c0a89d6;
case 0x0c0a89d8u: goto P_0c0a89d8;
case 0x0c0a89dau: goto P_0c0a89da;
case 0x0c0a89dcu: goto P_0c0a89dc;
case 0x0c0a89deu: goto P_0c0a89de;
case 0x0c0a89e0u: goto P_0c0a89e0;
case 0x0c0a89e2u: goto P_0c0a89e2;
case 0x0c0a89e4u: goto P_0c0a89e4;
case 0x0c0a89e6u: goto P_0c0a89e6;
case 0x0c0a89e8u: goto P_0c0a89e8;
case 0x0c0a89eau: goto P_0c0a89ea;
case 0x0c0a89ecu: goto P_0c0a89ec;
case 0x0c0a89eeu: goto P_0c0a89ee;
case 0x0c0a89f0u: goto P_0c0a89f0;
case 0x0c0a89f2u: goto P_0c0a89f2;
case 0x0c0a89f4u: goto P_0c0a89f4;
case 0x0c0a89f6u: goto P_0c0a89f6;
case 0x0c0a89f8u: goto P_0c0a89f8;
case 0x0c0a89fau: goto P_0c0a89fa;
case 0x0c0a89fcu: goto P_0c0a89fc;
case 0x0c0a89feu: goto P_0c0a89fe;
case 0x0c0a8a00u: goto P_0c0a8a00;
case 0x0c0a8a02u: goto P_0c0a8a02;
case 0x0c0a8a04u: goto P_0c0a8a04;
case 0x0c0a8a06u: goto P_0c0a8a06;
case 0x0c0a8a08u: goto P_0c0a8a08;
case 0x0c0a8a0au: goto P_0c0a8a0a;
case 0x0c0a8a0cu: goto P_0c0a8a0c;
case 0x0c0a8a0eu: goto P_0c0a8a0e;
case 0x0c0a8a10u: goto P_0c0a8a10;
case 0x0c0a8a12u: goto P_0c0a8a12;
case 0x0c0a8a14u: goto P_0c0a8a14;
case 0x0c0a8a16u: goto P_0c0a8a16;
case 0x0c0a8a18u: goto P_0c0a8a18;
case 0x0c0a8a1au: goto P_0c0a8a1a;
case 0x0c0a8a1cu: goto P_0c0a8a1c;
case 0x0c0a8a1eu: goto P_0c0a8a1e;
case 0x0c0a8a20u: goto P_0c0a8a20;
case 0x0c0a8a22u: goto P_0c0a8a22;
case 0x0c0a8a24u: goto P_0c0a8a24;
case 0x0c0a8a26u: goto P_0c0a8a26;
case 0x0c0a8a28u: goto P_0c0a8a28;
case 0x0c0a8a2au: goto P_0c0a8a2a;
case 0x0c0a8a2cu: goto P_0c0a8a2c;
case 0x0c0a8a2eu: goto P_0c0a8a2e;
case 0x0c0a8a30u: goto P_0c0a8a30;
case 0x0c0a8a32u: goto P_0c0a8a32;
case 0x0c0a8a34u: goto P_0c0a8a34;
case 0x0c0a8a36u: goto P_0c0a8a36;
case 0x0c0a8a38u: goto P_0c0a8a38;
case 0x0c0a8a3au: goto P_0c0a8a3a;
case 0x0c0a8a3cu: goto P_0c0a8a3c;
case 0x0c0a8a3eu: goto P_0c0a8a3e;
case 0x0c0a8a40u: goto P_0c0a8a40;
case 0x0c0a8a42u: goto P_0c0a8a42;
case 0x0c0a8a44u: goto P_0c0a8a44;
case 0x0c0a8a46u: goto P_0c0a8a46;
case 0x0c0a8a48u: goto P_0c0a8a48;
case 0x0c0a8a4au: goto P_0c0a8a4a;
case 0x0c0a8a4cu: goto P_0c0a8a4c;
case 0x0c0a8a4eu: goto P_0c0a8a4e;
case 0x0c0a8a50u: goto P_0c0a8a50;
case 0x0c0a8a52u: goto P_0c0a8a52;
case 0x0c0a8a54u: goto P_0c0a8a54;
case 0x0c0a8a56u: goto P_0c0a8a56;
case 0x0c0a8a58u: goto P_0c0a8a58;
case 0x0c0a8a5au: goto P_0c0a8a5a;
case 0x0c0a8a5cu: goto P_0c0a8a5c;
case 0x0c0a8a5eu: goto P_0c0a8a5e;
case 0x0c0a8a60u: goto P_0c0a8a60;
case 0x0c0a8a62u: goto P_0c0a8a62;
case 0x0c0a8a64u: goto P_0c0a8a64;
case 0x0c0a8a66u: goto P_0c0a8a66;
case 0x0c0a8a68u: goto P_0c0a8a68;
case 0x0c0a8a6au: goto P_0c0a8a6a;
case 0x0c0a8a6cu: goto P_0c0a8a6c;
case 0x0c0a8a6eu: goto P_0c0a8a6e;
case 0x0c0a8a70u: goto P_0c0a8a70;
case 0x0c0a8a72u: goto P_0c0a8a72;
case 0x0c0a8a74u: goto P_0c0a8a74;
case 0x0c0a8a76u: goto P_0c0a8a76;
case 0x0c0a8a78u: goto P_0c0a8a78;
case 0x0c0a8a7au: goto P_0c0a8a7a;
case 0x0c0a8a7cu: goto P_0c0a8a7c;
case 0x0c0a8a7eu: goto P_0c0a8a7e;
case 0x0c0a8a80u: goto P_0c0a8a80;
case 0x0c0a8a82u: goto P_0c0a8a82;
case 0x0c0a8a84u: goto P_0c0a8a84;
case 0x0c0a8a86u: goto P_0c0a8a86;
case 0x0c0a8a88u: goto P_0c0a8a88;
case 0x0c0a8a8au: goto P_0c0a8a8a;
case 0x0c0a8a8cu: goto P_0c0a8a8c;
case 0x0c0a8a8eu: goto P_0c0a8a8e;
case 0x0c0a8f10u: goto P_0c0a8f10;
case 0x0c0a8f12u: goto P_0c0a8f12;
case 0x0c0a8f14u: goto P_0c0a8f14;
case 0x0c0a8f16u: goto P_0c0a8f16;
case 0x0c0a8f18u: goto P_0c0a8f18;
case 0x0c0a8f1au: goto P_0c0a8f1a;
case 0x0c0a8f1cu: goto P_0c0a8f1c;
case 0x0c0a8f1eu: goto P_0c0a8f1e;
case 0x0c0a8f20u: goto P_0c0a8f20;
case 0x0c0a8f22u: goto P_0c0a8f22;
case 0x0c0a8f24u: goto P_0c0a8f24;
case 0x0c0a8f26u: goto P_0c0a8f26;
case 0x0c0a8f28u: goto P_0c0a8f28;
case 0x0c0a8f2au: goto P_0c0a8f2a;
case 0x0c0a8f2cu: goto P_0c0a8f2c;
case 0x0c0a8f2eu: goto P_0c0a8f2e;
case 0x0c0a8f30u: goto P_0c0a8f30;
case 0x0c0a8f32u: goto P_0c0a8f32;
case 0x0c0a8f34u: goto P_0c0a8f34;
case 0x0c0a8f36u: goto P_0c0a8f36;
case 0x0c0a8f38u: goto P_0c0a8f38;
case 0x0c0a8f3au: goto P_0c0a8f3a;
case 0x0c0a8f3cu: goto P_0c0a8f3c;
case 0x0c0a8f3eu: goto P_0c0a8f3e;
case 0x0c0a8f40u: goto P_0c0a8f40;
case 0x0c0a8f42u: goto P_0c0a8f42;
case 0x0c0a8f44u: goto P_0c0a8f44;
case 0x0c0a8f46u: goto P_0c0a8f46;
case 0x0c0a8f48u: goto P_0c0a8f48;
case 0x0c0a8f4au: goto P_0c0a8f4a;
case 0x0c0a8f8cu: goto P_0c0a8f8c;
case 0x0c0a8f8eu: goto P_0c0a8f8e;
case 0x0c0a8f90u: goto P_0c0a8f90;
case 0x0c0a8f92u: goto P_0c0a8f92;
case 0x0c0a8f94u: goto P_0c0a8f94;
case 0x0c0a8f96u: goto P_0c0a8f96;
case 0x0c0a8f98u: goto P_0c0a8f98;
case 0x0c0a8f9au: goto P_0c0a8f9a;
case 0x0c0a8f9cu: goto P_0c0a8f9c;
case 0x0c0a8f9eu: goto P_0c0a8f9e;
case 0x0c0a8fa0u: goto P_0c0a8fa0;
case 0x0c0a8fa2u: goto P_0c0a8fa2;
case 0x0c0a8fa4u: goto P_0c0a8fa4;
case 0x0c0a8fa6u: goto P_0c0a8fa6;
case 0x0c0a8fa8u: goto P_0c0a8fa8;
case 0x0c0a8faau: goto P_0c0a8faa;
case 0x0c0a8facu: goto P_0c0a8fac;
case 0x0c0a8faeu: goto P_0c0a8fae;
case 0x0c0a8fb0u: goto P_0c0a8fb0;
case 0x0c0a8fb2u: goto P_0c0a8fb2;
case 0x0c0a8fb4u: goto P_0c0a8fb4;
case 0x0c0a8fb6u: goto P_0c0a8fb6;
case 0x0c0a8fb8u: goto P_0c0a8fb8;
case 0x0c0a8fbau: goto P_0c0a8fba;
case 0x0c0a8fbcu: goto P_0c0a8fbc;
case 0x0c0a8fbeu: goto P_0c0a8fbe;
case 0x0c0a8fc0u: goto P_0c0a8fc0;
case 0x0c0a8fc2u: goto P_0c0a8fc2;
case 0x0c0a8fc4u: goto P_0c0a8fc4;
case 0x0c0a8fc6u: goto P_0c0a8fc6;
case 0x0c0a8fc8u: goto P_0c0a8fc8;
case 0x0c0a8fcau: goto P_0c0a8fca;
case 0x0c0a8fccu: goto P_0c0a8fcc;
case 0x0c0a8fceu: goto P_0c0a8fce;
case 0x0c0a8fd0u: goto P_0c0a8fd0;
case 0x0c0a8fd2u: goto P_0c0a8fd2;
case 0x0c0a8fd4u: goto P_0c0a8fd4;
case 0x0c0a8fd6u: goto P_0c0a8fd6;
case 0x0c0a8fd8u: goto P_0c0a8fd8;
case 0x0c0a8fdau: goto P_0c0a8fda;
case 0x0c0a8fdcu: goto P_0c0a8fdc;
case 0x0c0a8fdeu: goto P_0c0a8fde;
case 0x0c0a8fe0u: goto P_0c0a8fe0;
case 0x0c0a8fe2u: goto P_0c0a8fe2;
case 0x0c0a8fe4u: goto P_0c0a8fe4;
case 0x0c0a8fe6u: goto P_0c0a8fe6;
case 0x0c0a8fe8u: goto P_0c0a8fe8;
case 0x0c0a8feau: goto P_0c0a8fea;
case 0x0c0a8fecu: goto P_0c0a8fec;
case 0x0c0a8feeu: goto P_0c0a8fee;
case 0x0c0a8ff0u: goto P_0c0a8ff0;
case 0x0c0a8ff2u: goto P_0c0a8ff2;
case 0x0c0a8ff4u: goto P_0c0a8ff4;
case 0x0c0a8ff6u: goto P_0c0a8ff6;
case 0x0c0a8ff8u: goto P_0c0a8ff8;
case 0x0c0a8ffau: goto P_0c0a8ffa;
case 0x0c0a8ffcu: goto P_0c0a8ffc;
case 0x0c0a8ffeu: goto P_0c0a8ffe;
case 0x0c0a9000u: goto P_0c0a9000;
case 0x0c0a9002u: goto P_0c0a9002;
case 0x0c0a9004u: goto P_0c0a9004;
case 0x0c0a9006u: goto P_0c0a9006;
case 0x0c0a9008u: goto P_0c0a9008;
case 0x0c0a900au: goto P_0c0a900a;
case 0x0c0a900cu: goto P_0c0a900c;
case 0x0c0a900eu: goto P_0c0a900e;
case 0x0c0a9010u: goto P_0c0a9010;
case 0x0c0a9012u: goto P_0c0a9012;
case 0x0c0a9014u: goto P_0c0a9014;
case 0x0c0a9016u: goto P_0c0a9016;
case 0x0c0a9018u: goto P_0c0a9018;
case 0x0c0a901au: goto P_0c0a901a;
case 0x0c0a901cu: goto P_0c0a901c;
case 0x0c0a901eu: goto P_0c0a901e;
case 0x0c0a9020u: goto P_0c0a9020;
case 0x0c0a9022u: goto P_0c0a9022;
case 0x0c0a9024u: goto P_0c0a9024;
case 0x0c0a9026u: goto P_0c0a9026;
case 0x0c0a9028u: goto P_0c0a9028;
case 0x0c0a902au: goto P_0c0a902a;
case 0x0c0a902cu: goto P_0c0a902c;
case 0x0c0a902eu: goto P_0c0a902e;
case 0x0c0a9030u: goto P_0c0a9030;
case 0x0c0a9032u: goto P_0c0a9032;
case 0x0c0a9034u: goto P_0c0a9034;
default: return vf3_matrix_family(target,s,ram);
}
P_0c0a8952: /* original e004, guest PC 0x0c0a8952 */
if(!s->budget--) { s->failed_pc=0x0c0a8952u; return 0; }
r[0]=0x00000004u;
goto P_0c0a8954;
P_0c0a8954: /* original 5744, guest PC 0x0c0a8954 */
if(!s->budget--) { s->failed_pc=0x0c0a8954u; return 0; }
r[7]=read(ram,r[4]+16,4);
goto P_0c0a8956;
P_0c0a8956: /* original f446, guest PC 0x0c0a8956 */
if(!s->budget--) { s->failed_pc=0x0c0a8956u; return 0; }
vf3_matrix_load(s,ram,4,r[4]+r[0]);
goto P_0c0a8958;
P_0c0a8958: /* original e008, guest PC 0x0c0a8958 */
if(!s->budget--) { s->failed_pc=0x0c0a8958u; return 0; }
r[0]=0x00000008u;
goto P_0c0a895a;
P_0c0a895a: /* original f646, guest PC 0x0c0a895a */
if(!s->budget--) { s->failed_pc=0x0c0a895au; return 0; }
vf3_matrix_load(s,ram,6,r[4]+r[0]);
goto P_0c0a895c;
P_0c0a895c: /* original e00c, guest PC 0x0c0a895c */
if(!s->budget--) { s->failed_pc=0x0c0a895cu; return 0; }
r[0]=0x0000000cu;
goto P_0c0a895e;
P_0c0a895e: /* original f546, guest PC 0x0c0a895e */
if(!s->budget--) { s->failed_pc=0x0c0a895eu; return 0; }
vf3_matrix_load(s,ram,5,r[4]+r[0]);
goto P_0c0a8960;
P_0c0a8960: /* original e020, guest PC 0x0c0a8960 */
if(!s->budget--) { s->failed_pc=0x0c0a8960u; return 0; }
r[0]=0x00000020u;
goto P_0c0a8962;
P_0c0a8962: /* original 004d, guest PC 0x0c0a8962 */
if(!s->budget--) { s->failed_pc=0x0c0a8962u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c0a8964;
P_0c0a8964: /* original 7ff0, guest PC 0x0c0a8964 */
if(!s->budget--) { s->failed_pc=0x0c0a8964u; return 0; }
r[15]+=0xfffffff0u;
goto P_0c0a8966;
P_0c0a8966: /* original 6642, guest PC 0x0c0a8966 */
if(!s->budget--) { s->failed_pc=0x0c0a8966u; return 0; }
tmp=read(ram,r[4],4);
r[6]=tmp;
goto P_0c0a8968;
P_0c0a8968: /* original 81f6, guest PC 0x0c0a8968 */
if(!s->budget--) { s->failed_pc=0x0c0a8968u; return 0; }
write(ram,r[15]+12,r[0],2);
goto P_0c0a896a;
P_0c0a896a: /* original e022, guest PC 0x0c0a896a */
if(!s->budget--) { s->failed_pc=0x0c0a896au; return 0; }
r[0]=0x00000022u;
goto P_0c0a896c;
P_0c0a896c: /* original 004d, guest PC 0x0c0a896c */
if(!s->budget--) { s->failed_pc=0x0c0a896cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c0a896e;
P_0c0a896e: /* original 81f4, guest PC 0x0c0a896e */
if(!s->budget--) { s->failed_pc=0x0c0a896eu; return 0; }
write(ram,r[15]+8,r[0],2);
goto P_0c0a8970;
P_0c0a8970: /* original e024, guest PC 0x0c0a8970 */
if(!s->budget--) { s->failed_pc=0x0c0a8970u; return 0; }
r[0]=0x00000024u;
goto P_0c0a8972;
P_0c0a8972: /* original 004d, guest PC 0x0c0a8972 */
if(!s->budget--) { s->failed_pc=0x0c0a8972u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c0a8974;
P_0c0a8974: /* original 81f2, guest PC 0x0c0a8974 */
if(!s->budget--) { s->failed_pc=0x0c0a8974u; return 0; }
write(ram,r[15]+4,r[0],2);
goto P_0c0a8976;
P_0c0a8976: /* original e03b, guest PC 0x0c0a8976 */
if(!s->budget--) { s->failed_pc=0x0c0a8976u; return 0; }
r[0]=0x0000003bu;
goto P_0c0a8978;
P_0c0a8978: /* original 034c, guest PC 0x0c0a8978 */
if(!s->budget--) { s->failed_pc=0x0c0a8978u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c0a897a;
P_0c0a897a: /* original e004, guest PC 0x0c0a897a */
if(!s->budget--) { s->failed_pc=0x0c0a897au; return 0; }
r[0]=0x00000004u;
goto P_0c0a897c;
P_0c0a897c: /* original 2f30, guest PC 0x0c0a897c */
if(!s->budget--) { s->failed_pc=0x0c0a897cu; return 0; }
write(ram,r[15],r[3],1);
goto P_0c0a897e;
P_0c0a897e: /* original 544b, guest PC 0x0c0a897e */
if(!s->budget--) { s->failed_pc=0x0c0a897eu; return 0; }
r[4]=read(ram,r[4]+44,4);
goto P_0c0a8980;
P_0c0a8980: /* original f547, guest PC 0x0c0a8980 */
if(!s->budget--) { s->failed_pc=0x0c0a8980u; return 0; }
vf3_matrix_store(s,ram,4,r[5]+r[0]);
goto P_0c0a8982;
P_0c0a8982: /* original e008, guest PC 0x0c0a8982 */
if(!s->budget--) { s->failed_pc=0x0c0a8982u; return 0; }
r[0]=0x00000008u;
goto P_0c0a8984;
P_0c0a8984: /* original f567, guest PC 0x0c0a8984 */
if(!s->budget--) { s->failed_pc=0x0c0a8984u; return 0; }
vf3_matrix_store(s,ram,6,r[5]+r[0]);
goto P_0c0a8986;
P_0c0a8986: /* original e00c, guest PC 0x0c0a8986 */
if(!s->budget--) { s->failed_pc=0x0c0a8986u; return 0; }
r[0]=0x0000000cu;
goto P_0c0a8988;
P_0c0a8988: /* original f557, guest PC 0x0c0a8988 */
if(!s->budget--) { s->failed_pc=0x0c0a8988u; return 0; }
vf3_matrix_store(s,ram,5,r[5]+r[0]);
goto P_0c0a898a;
P_0c0a898a: /* original 2562, guest PC 0x0c0a898a */
if(!s->budget--) { s->failed_pc=0x0c0a898au; return 0; }
write(ram,r[5],r[6],4);
goto P_0c0a898c;
P_0c0a898c: /* original 1574, guest PC 0x0c0a898c */
if(!s->budget--) { s->failed_pc=0x0c0a898cu; return 0; }
write(ram,r[5]+16,r[7],4);
goto P_0c0a898e;
P_0c0a898e: /* original 85f6, guest PC 0x0c0a898e */
if(!s->budget--) { s->failed_pc=0x0c0a898eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[15]+12,2);
goto P_0c0a8990;
P_0c0a8990: /* original 815a, guest PC 0x0c0a8990 */
if(!s->budget--) { s->failed_pc=0x0c0a8990u; return 0; }
write(ram,r[5]+20,r[0],2);
goto P_0c0a8992;
P_0c0a8992: /* original 85f4, guest PC 0x0c0a8992 */
if(!s->budget--) { s->failed_pc=0x0c0a8992u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[15]+8,2);
goto P_0c0a8994;
P_0c0a8994: /* original 815b, guest PC 0x0c0a8994 */
if(!s->budget--) { s->failed_pc=0x0c0a8994u; return 0; }
write(ram,r[5]+22,r[0],2);
goto P_0c0a8996;
P_0c0a8996: /* original 85f2, guest PC 0x0c0a8996 */
if(!s->budget--) { s->failed_pc=0x0c0a8996u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[15]+4,2);
goto P_0c0a8998;
P_0c0a8998: /* original 815c, guest PC 0x0c0a8998 */
if(!s->budget--) { s->failed_pc=0x0c0a8998u; return 0; }
write(ram,r[5]+24,r[0],2);
goto P_0c0a899a;
P_0c0a899a: /* original e01a, guest PC 0x0c0a899a */
if(!s->budget--) { s->failed_pc=0x0c0a899au; return 0; }
r[0]=0x0000001au;
goto P_0c0a899c;
P_0c0a899c: /* original 63f0, guest PC 0x0c0a899c */
if(!s->budget--) { s->failed_pc=0x0c0a899cu; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[15],1);
r[3]=tmp;
goto P_0c0a899e;
P_0c0a899e: /* original 0534, guest PC 0x0c0a899e */
if(!s->budget--) { s->failed_pc=0x0c0a899eu; return 0; }
write(ram,r[5]+r[0],r[3],1);
goto P_0c0a89a0;
P_0c0a89a0: /* original 1547, guest PC 0x0c0a89a0 */
if(!s->budget--) { s->failed_pc=0x0c0a89a0u; return 0; }
write(ram,r[5]+28,r[4],4);
goto P_0c0a89a2;
P_0c0a89a2: /* original 000b, guest PC 0x0c0a89a2 */
if(!s->budget--) { s->failed_pc=0x0c0a89a2u; return 0; }
target=r[16];
r[15]+=0x00000010u;
s->pc=target; return ram->oob==0;
P_0c0a89a4: /* original 7f10, guest PC 0x0c0a89a4 */
if(!s->budget--) { s->failed_pc=0x0c0a89a4u; return 0; }
r[15]+=0x00000010u;
if(!vf3_matrix_family(0x0c0a89a6u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0a89a6u; return 0; } return 1;
P_0c0a89b4: /* original 2fe6, guest PC 0x0c0a89b4 */
if(!s->budget--) { s->failed_pc=0x0c0a89b4u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a89b6;
P_0c0a89b6: /* original e400, guest PC 0x0c0a89b6 */
if(!s->budget--) { s->failed_pc=0x0c0a89b6u; return 0; }
r[4]=0x00000000u;
goto P_0c0a89b8;
P_0c0a89b8: /* original 2fd6, guest PC 0x0c0a89b8 */
if(!s->budget--) { s->failed_pc=0x0c0a89b8u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a89ba;
P_0c0a89ba: /* original e70d, guest PC 0x0c0a89ba */
if(!s->budget--) { s->failed_pc=0x0c0a89bau; return 0; }
r[7]=0x0000000du;
goto P_0c0a89bc;
P_0c0a89bc: /* original 2fc6, guest PC 0x0c0a89bc */
if(!s->budget--) { s->failed_pc=0x0c0a89bcu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a89be;
P_0c0a89be: /* original de37, guest PC 0x0c0a89be */
if(!s->budget--) { s->failed_pc=0x0c0a89beu; return 0; }
r[14]=read(ram,0x0c0a8a9cu,4);
goto P_0c0a89c0;
P_0c0a89c0: /* original 9066, guest PC 0x0c0a89c0 */
if(!s->budget--) { s->failed_pc=0x0c0a89c0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a8a90u,2);
goto P_0c0a89c2;
P_0c0a89c2: /* original 4f22, guest PC 0x0c0a89c2 */
if(!s->budget--) { s->failed_pc=0x0c0a89c2u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0a89c4;
P_0c0a89c4: /* original 0e44, guest PC 0x0c0a89c4 */
if(!s->budget--) { s->failed_pc=0x0c0a89c4u; return 0; }
write(ram,r[14]+r[0],r[4],1);
goto P_0c0a89c6;
P_0c0a89c6: /* original 7001, guest PC 0x0c0a89c6 */
if(!s->budget--) { s->failed_pc=0x0c0a89c6u; return 0; }
r[0]+=0x00000001u;
goto P_0c0a89c8;
P_0c0a89c8: /* original 0e44, guest PC 0x0c0a89c8 */
if(!s->budget--) { s->failed_pc=0x0c0a89c8u; return 0; }
write(ram,r[14]+r[0],r[4],1);
goto P_0c0a89ca;
P_0c0a89ca: /* original 7001, guest PC 0x0c0a89ca */
if(!s->budget--) { s->failed_pc=0x0c0a89cau; return 0; }
r[0]+=0x00000001u;
goto P_0c0a89cc;
P_0c0a89cc: /* original 0e44, guest PC 0x0c0a89cc */
if(!s->budget--) { s->failed_pc=0x0c0a89ccu; return 0; }
write(ram,r[14]+r[0],r[4],1);
goto P_0c0a89ce;
P_0c0a89ce: /* original d434, guest PC 0x0c0a89ce */
if(!s->budget--) { s->failed_pc=0x0c0a89ceu; return 0; }
r[4]=read(ram,0x0c0a8aa0u,4);
goto P_0c0a89d0;
P_0c0a89d0: /* original 4f12, guest PC 0x0c0a89d0 */
if(!s->budget--) { s->failed_pc=0x0c0a89d0u; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c0a89d2;
P_0c0a89d2: /* original 5c44, guest PC 0x0c0a89d2 */
if(!s->budget--) { s->failed_pc=0x0c0a89d2u; return 0; }
r[12]=read(ram,r[4]+16,4);
goto P_0c0a89d4;
P_0c0a89d4: /* original 5d45, guest PC 0x0c0a89d4 */
if(!s->budget--) { s->failed_pc=0x0c0a89d4u; return 0; }
r[13]=read(ram,r[4]+20,4);
goto P_0c0a89d6;
P_0c0a89d6: /* original 945c, guest PC 0x0c0a89d6 */
if(!s->budget--) { s->failed_pc=0x0c0a89d6u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a8a92u,2);
goto P_0c0a89d8;
P_0c0a89d8: /* original 7ffc, guest PC 0x0c0a89d8 */
if(!s->budget--) { s->failed_pc=0x0c0a89d8u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c0a89da;
P_0c0a89da: /* original 34ec, guest PC 0x0c0a89da */
if(!s->budget--) { s->failed_pc=0x0c0a89dau; return 0; }
r[4]+=r[14];
goto P_0c0a89dc;
P_0c0a89dc: /* original 8441, guest PC 0x0c0a89dc */
if(!s->budget--) { s->failed_pc=0x0c0a89dcu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+1,1);
goto P_0c0a89de;
P_0c0a89de: /* original 6640, guest PC 0x0c0a89de */
if(!s->budget--) { s->failed_pc=0x0c0a89deu; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[4],1);
r[6]=tmp;
goto P_0c0a89e0;
P_0c0a89e0: /* original 6503, guest PC 0x0c0a89e0 */
if(!s->budget--) { s->failed_pc=0x0c0a89e0u; return 0; }
r[5]=r[0];
goto P_0c0a89e2;
P_0c0a89e2: /* original 8442, guest PC 0x0c0a89e2 */
if(!s->budget--) { s->failed_pc=0x0c0a89e2u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+2,1);
goto P_0c0a89e4;
P_0c0a89e4: /* original 635e, guest PC 0x0c0a89e4 */
if(!s->budget--) { s->failed_pc=0x0c0a89e4u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)r[5];
goto P_0c0a89e6;
P_0c0a89e6: /* original 6403, guest PC 0x0c0a89e6 */
if(!s->budget--) { s->failed_pc=0x0c0a89e6u; return 0; }
r[4]=r[0];
goto P_0c0a89e8;
P_0c0a89e8: /* original 3373, guest PC 0x0c0a89e8 */
if(!s->budget--) { s->failed_pc=0x0c0a89e8u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>=(int32_t)r[7])!=0);
goto P_0c0a89ea;
P_0c0a89ea: /* original e060, guest PC 0x0c0a89ea */
if(!s->budget--) { s->failed_pc=0x0c0a89eau; return 0; }
r[0]=0x00000060u;
goto P_0c0a89ec;
P_0c0a89ec: /* original 8f01, guest PC 0x0c0a89ec */
if(!s->budget--) { s->failed_pc=0x0c0a89ecu; return 0; }
cond=r[17]&1u;
write(ram,r[12]+r[0],r[5],1);
if(!cond) { goto P_0c0a89f2; }
goto P_0c0a89f0;
P_0c0a89ee: /* original 0c54, guest PC 0x0c0a89ee */
if(!s->budget--) { s->failed_pc=0x0c0a89eeu; return 0; }
write(ram,r[12]+r[0],r[5],1);
goto P_0c0a89f0;
P_0c0a89f0: /* original 75f3, guest PC 0x0c0a89f0 */
if(!s->budget--) { s->failed_pc=0x0c0a89f0u; return 0; }
r[5]+=0xfffffff3u;
goto P_0c0a89f2;
P_0c0a89f2: /* original e061, guest PC 0x0c0a89f2 */
if(!s->budget--) { s->failed_pc=0x0c0a89f2u; return 0; }
r[0]=0x00000061u;
goto P_0c0a89f4;
P_0c0a89f4: /* original 634e, guest PC 0x0c0a89f4 */
if(!s->budget--) { s->failed_pc=0x0c0a89f4u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)r[4];
goto P_0c0a89f6;
P_0c0a89f6: /* original 0c54, guest PC 0x0c0a89f6 */
if(!s->budget--) { s->failed_pc=0x0c0a89f6u; return 0; }
write(ram,r[12]+r[0],r[5],1);
goto P_0c0a89f8;
P_0c0a89f8: /* original 3373, guest PC 0x0c0a89f8 */
if(!s->budget--) { s->failed_pc=0x0c0a89f8u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>=(int32_t)r[7])!=0);
goto P_0c0a89fa;
P_0c0a89fa: /* original e060, guest PC 0x0c0a89fa */
if(!s->budget--) { s->failed_pc=0x0c0a89fau; return 0; }
r[0]=0x00000060u;
goto P_0c0a89fc;
P_0c0a89fc: /* original 8f01, guest PC 0x0c0a89fc */
if(!s->budget--) { s->failed_pc=0x0c0a89fcu; return 0; }
cond=r[17]&1u;
write(ram,r[13]+r[0],r[4],1);
if(!cond) { goto P_0c0a8a02; }
goto P_0c0a8a00;
P_0c0a89fe: /* original 0d44, guest PC 0x0c0a89fe */
if(!s->budget--) { s->failed_pc=0x0c0a89feu; return 0; }
write(ram,r[13]+r[0],r[4],1);
goto P_0c0a8a00;
P_0c0a8a00: /* original 74f3, guest PC 0x0c0a8a00 */
if(!s->budget--) { s->failed_pc=0x0c0a8a00u; return 0; }
r[4]+=0xfffffff3u;
goto P_0c0a8a02;
P_0c0a8a02: /* original e061, guest PC 0x0c0a8a02 */
if(!s->budget--) { s->failed_pc=0x0c0a8a02u; return 0; }
r[0]=0x00000061u;
goto P_0c0a8a04;
P_0c0a8a04: /* original 0d44, guest PC 0x0c0a8a04 */
if(!s->budget--) { s->failed_pc=0x0c0a8a04u; return 0; }
write(ram,r[13]+r[0],r[4],1);
goto P_0c0a8a06;
P_0c0a8a06: /* original d327, guest PC 0x0c0a8a06 */
if(!s->budget--) { s->failed_pc=0x0c0a8a06u; return 0; }
r[3]=read(ram,0x0c0a8aa4u,4);
goto P_0c0a8a08;
P_0c0a8a08: /* original d227, guest PC 0x0c0a8a08 */
if(!s->budget--) { s->failed_pc=0x0c0a8a08u; return 0; }
r[2]=read(ram,0x0c0a8aa8u,4);
goto P_0c0a8a0a;
P_0c0a8a0a: /* original 420b, guest PC 0x0c0a8a0a */
if(!s->budget--) { s->failed_pc=0x0c0a8a0au; return 0; }
target=r[2];
r[16]=code_base|0x0c0a8a0eu;
write(ram,r[3],r[6],1);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a8a0eu) { target=s->pc; goto dispatch; }
goto P_0c0a8a0e;
P_0c0a8a0c: /* original 2360, guest PC 0x0c0a8a0c */
if(!s->budget--) { s->failed_pc=0x0c0a8a0cu; return 0; }
write(ram,r[3],r[6],1);
goto P_0c0a8a0e;
P_0c0a8a0e: /* original d127, guest PC 0x0c0a8a0e */
if(!s->budget--) { s->failed_pc=0x0c0a8a0eu; return 0; }
r[1]=read(ram,0x0c0a8aacu,4);
goto P_0c0a8a10;
P_0c0a8a10: /* original 410b, guest PC 0x0c0a8a10 */
if(!s->budget--) { s->failed_pc=0x0c0a8a10u; return 0; }
target=r[1];
r[16]=code_base|0x0c0a8a14u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a8a14u) { target=s->pc; goto dispatch; }
goto P_0c0a8a14;
P_0c0a8a12: /* original 0009, guest PC 0x0c0a8a12 */
if(!s->budget--) { s->failed_pc=0x0c0a8a12u; return 0; }
goto P_0c0a8a14;
P_0c0a8a14: /* original d526, guest PC 0x0c0a8a14 */
if(!s->budget--) { s->failed_pc=0x0c0a8a14u; return 0; }
r[5]=read(ram,0x0c0a8ab0u,4);
goto P_0c0a8a16;
P_0c0a8a16: /* original e301, guest PC 0x0c0a8a16 */
if(!s->budget--) { s->failed_pc=0x0c0a8a16u; return 0; }
r[3]=0x00000001u;
goto P_0c0a8a18;
P_0c0a8a18: /* original 5451, guest PC 0x0c0a8a18 */
if(!s->budget--) { s->failed_pc=0x0c0a8a18u; return 0; }
r[4]=read(ram,r[5]+4,4);
goto P_0c0a8a1a;
P_0c0a8a1a: /* original 243b, guest PC 0x0c0a8a1a */
if(!s->budget--) { s->failed_pc=0x0c0a8a1au; return 0; }
r[4]|=r[3];
goto P_0c0a8a1c;
P_0c0a8a1c: /* original 1541, guest PC 0x0c0a8a1c */
if(!s->budget--) { s->failed_pc=0x0c0a8a1cu; return 0; }
write(ram,r[5]+4,r[4],4);
goto P_0c0a8a1e;
P_0c0a8a1e: /* original 9039, guest PC 0x0c0a8a1e */
if(!s->budget--) { s->failed_pc=0x0c0a8a1eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a8a94u,2);
goto P_0c0a8a20;
P_0c0a8a20: /* original 9239, guest PC 0x0c0a8a20 */
if(!s->budget--) { s->failed_pc=0x0c0a8a20u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a8a96u,2);
goto P_0c0a8a22;
P_0c0a8a22: /* original 04ec, guest PC 0x0c0a8a22 */
if(!s->budget--) { s->failed_pc=0x0c0a8a22u; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0a8a24;
P_0c0a8a24: /* original 70ff, guest PC 0x0c0a8a24 */
if(!s->budget--) { s->failed_pc=0x0c0a8a24u; return 0; }
r[0]+=0xffffffffu;
goto P_0c0a8a26;
P_0c0a8a26: /* original 32ec, guest PC 0x0c0a8a26 */
if(!s->budget--) { s->failed_pc=0x0c0a8a26u; return 0; }
r[2]+=r[14];
goto P_0c0a8a28;
P_0c0a8a28: /* original d122, guest PC 0x0c0a8a28 */
if(!s->budget--) { s->failed_pc=0x0c0a8a28u; return 0; }
r[1]=read(ram,0x0c0a8ab4u,4);
goto P_0c0a8a2a;
P_0c0a8a2a: /* original 4408, guest PC 0x0c0a8a2a */
if(!s->budget--) { s->failed_pc=0x0c0a8a2au; return 0; }
r[4]<<=2;
goto P_0c0a8a2c;
P_0c0a8a2c: /* original 342c, guest PC 0x0c0a8a2c */
if(!s->budget--) { s->failed_pc=0x0c0a8a2cu; return 0; }
r[4]+=r[2];
goto P_0c0a8a2e;
P_0c0a8a2e: /* original 6442, guest PC 0x0c0a8a2e */
if(!s->budget--) { s->failed_pc=0x0c0a8a2eu; return 0; }
tmp=read(ram,r[4],4);
r[4]=tmp;
goto P_0c0a8a30;
P_0c0a8a30: /* original 2142, guest PC 0x0c0a8a30 */
if(!s->budget--) { s->failed_pc=0x0c0a8a30u; return 0; }
write(ram,r[1],r[4],4);
goto P_0c0a8a32;
P_0c0a8a32: /* original 05ec, guest PC 0x0c0a8a32 */
if(!s->budget--) { s->failed_pc=0x0c0a8a32u; return 0; }
r[5]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0a8a34;
P_0c0a8a34: /* original 7001, guest PC 0x0c0a8a34 */
if(!s->budget--) { s->failed_pc=0x0c0a8a34u; return 0; }
r[0]+=0x00000001u;
goto P_0c0a8a36;
P_0c0a8a36: /* original 932f, guest PC 0x0c0a8a36 */
if(!s->budget--) { s->failed_pc=0x0c0a8a36u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a8a98u,2);
goto P_0c0a8a38;
P_0c0a8a38: /* original 04ec, guest PC 0x0c0a8a38 */
if(!s->budget--) { s->failed_pc=0x0c0a8a38u; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0a8a3a;
P_0c0a8a3a: /* original 655c, guest PC 0x0c0a8a3a */
if(!s->budget--) { s->failed_pc=0x0c0a8a3au; return 0; }
r[5]=r[5]&255u;
goto P_0c0a8a3c;
P_0c0a8a3c: /* original 4508, guest PC 0x0c0a8a3c */
if(!s->budget--) { s->failed_pc=0x0c0a8a3cu; return 0; }
r[5]<<=2;
goto P_0c0a8a3e;
P_0c0a8a3e: /* original d21e, guest PC 0x0c0a8a3e */
if(!s->budget--) { s->failed_pc=0x0c0a8a3eu; return 0; }
r[2]=read(ram,0x0c0a8ab8u,4);
goto P_0c0a8a40;
P_0c0a8a40: /* original 243f, guest PC 0x0c0a8a40 */
if(!s->budget--) { s->failed_pc=0x0c0a8a40u; return 0; }
r[19]=(uint32_t)((int32_t)(int16_t)r[4]*(int32_t)(int16_t)r[3]);
goto P_0c0a8a42;
P_0c0a8a42: /* original 4508, guest PC 0x0c0a8a42 */
if(!s->budget--) { s->failed_pc=0x0c0a8a42u; return 0; }
r[5]<<=2;
goto P_0c0a8a44;
P_0c0a8a44: /* original 4508, guest PC 0x0c0a8a44 */
if(!s->budget--) { s->failed_pc=0x0c0a8a44u; return 0; }
r[5]<<=2;
goto P_0c0a8a46;
P_0c0a8a46: /* original e004, guest PC 0x0c0a8a46 */
if(!s->budget--) { s->failed_pc=0x0c0a8a46u; return 0; }
r[0]=0x00000004u;
goto P_0c0a8a48;
P_0c0a8a48: /* original 041a, guest PC 0x0c0a8a48 */
if(!s->budget--) { s->failed_pc=0x0c0a8a48u; return 0; }
r[4]=r[19];
goto P_0c0a8a4a;
P_0c0a8a4a: /* original 6e43, guest PC 0x0c0a8a4a */
if(!s->budget--) { s->failed_pc=0x0c0a8a4au; return 0; }
r[14]=r[4];
goto P_0c0a8a4c;
P_0c0a8a4c: /* original 3e5c, guest PC 0x0c0a8a4c */
if(!s->budget--) { s->failed_pc=0x0c0a8a4cu; return 0; }
r[14]+=r[5];
goto P_0c0a8a4e;
P_0c0a8a4e: /* original 3e2c, guest PC 0x0c0a8a4e */
if(!s->budget--) { s->failed_pc=0x0c0a8a4eu; return 0; }
r[14]+=r[2];
goto P_0c0a8a50;
P_0c0a8a50: /* original f4e6, guest PC 0x0c0a8a50 */
if(!s->budget--) { s->failed_pc=0x0c0a8a50u; return 0; }
vf3_matrix_load(s,ram,4,r[14]+r[0]);
goto P_0c0a8a52;
P_0c0a8a52: /* original e008, guest PC 0x0c0a8a52 */
if(!s->budget--) { s->failed_pc=0x0c0a8a52u; return 0; }
r[0]=0x00000008u;
goto P_0c0a8a54;
P_0c0a8a54: /* original f5e6, guest PC 0x0c0a8a54 */
if(!s->budget--) { s->failed_pc=0x0c0a8a54u; return 0; }
vf3_matrix_load(s,ram,5,r[14]+r[0]);
goto P_0c0a8a56;
P_0c0a8a56: /* original e00c, guest PC 0x0c0a8a56 */
if(!s->budget--) { s->failed_pc=0x0c0a8a56u; return 0; }
r[0]=0x0000000cu;
goto P_0c0a8a58;
P_0c0a8a58: /* original f6e6, guest PC 0x0c0a8a58 */
if(!s->budget--) { s->failed_pc=0x0c0a8a58u; return 0; }
vf3_matrix_load(s,ram,6,r[14]+r[0]);
goto P_0c0a8a5a;
P_0c0a8a5a: /* original e500, guest PC 0x0c0a8a5a */
if(!s->budget--) { s->failed_pc=0x0c0a8a5au; return 0; }
r[5]=0x00000000u;
goto P_0c0a8a5c;
P_0c0a8a5c: /* original 85ea, guest PC 0x0c0a8a5c */
if(!s->budget--) { s->failed_pc=0x0c0a8a5cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+20,2);
goto P_0c0a8a5e;
P_0c0a8a5e: /* original 2f01, guest PC 0x0c0a8a5e */
if(!s->budget--) { s->failed_pc=0x0c0a8a5eu; return 0; }
write(ram,r[15],r[0],2);
goto P_0c0a8a60;
P_0c0a8a60: /* original d116, guest PC 0x0c0a8a60 */
if(!s->budget--) { s->failed_pc=0x0c0a8a60u; return 0; }
r[1]=read(ram,0x0c0a8abcu,4);
goto P_0c0a8a62;
P_0c0a8a62: /* original 66f1, guest PC 0x0c0a8a62 */
if(!s->budget--) { s->failed_pc=0x0c0a8a62u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[15],2);
r[6]=tmp;
goto P_0c0a8a64;
P_0c0a8a64: /* original 410b, guest PC 0x0c0a8a64 */
if(!s->budget--) { s->failed_pc=0x0c0a8a64u; return 0; }
target=r[1];
r[16]=code_base|0x0c0a8a68u;
r[4]=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a8a68u) { target=s->pc; goto dispatch; }
goto P_0c0a8a68;
P_0c0a8a66: /* original 64c3, guest PC 0x0c0a8a66 */
if(!s->budget--) { s->failed_pc=0x0c0a8a66u; return 0; }
r[4]=r[12];
goto P_0c0a8a68;
P_0c0a8a68: /* original e004, guest PC 0x0c0a8a68 */
if(!s->budget--) { s->failed_pc=0x0c0a8a68u; return 0; }
r[0]=0x00000004u;
goto P_0c0a8a6a;
P_0c0a8a6a: /* original 64d3, guest PC 0x0c0a8a6a */
if(!s->budget--) { s->failed_pc=0x0c0a8a6au; return 0; }
r[4]=r[13];
goto P_0c0a8a6c;
P_0c0a8a6c: /* original 7e20, guest PC 0x0c0a8a6c */
if(!s->budget--) { s->failed_pc=0x0c0a8a6cu; return 0; }
r[14]+=0x00000020u;
goto P_0c0a8a6e;
P_0c0a8a6e: /* original f4e6, guest PC 0x0c0a8a6e */
if(!s->budget--) { s->failed_pc=0x0c0a8a6eu; return 0; }
vf3_matrix_load(s,ram,4,r[14]+r[0]);
goto P_0c0a8a70;
P_0c0a8a70: /* original e008, guest PC 0x0c0a8a70 */
if(!s->budget--) { s->failed_pc=0x0c0a8a70u; return 0; }
r[0]=0x00000008u;
goto P_0c0a8a72;
P_0c0a8a72: /* original f5e6, guest PC 0x0c0a8a72 */
if(!s->budget--) { s->failed_pc=0x0c0a8a72u; return 0; }
vf3_matrix_load(s,ram,5,r[14]+r[0]);
goto P_0c0a8a74;
P_0c0a8a74: /* original e00c, guest PC 0x0c0a8a74 */
if(!s->budget--) { s->failed_pc=0x0c0a8a74u; return 0; }
r[0]=0x0000000cu;
goto P_0c0a8a76;
P_0c0a8a76: /* original f6e6, guest PC 0x0c0a8a76 */
if(!s->budget--) { s->failed_pc=0x0c0a8a76u; return 0; }
vf3_matrix_load(s,ram,6,r[14]+r[0]);
goto P_0c0a8a78;
P_0c0a8a78: /* original e501, guest PC 0x0c0a8a78 */
if(!s->budget--) { s->failed_pc=0x0c0a8a78u; return 0; }
r[5]=0x00000001u;
goto P_0c0a8a7a;
P_0c0a8a7a: /* original 85ea, guest PC 0x0c0a8a7a */
if(!s->budget--) { s->failed_pc=0x0c0a8a7au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+20,2);
goto P_0c0a8a7c;
P_0c0a8a7c: /* original 2f01, guest PC 0x0c0a8a7c */
if(!s->budget--) { s->failed_pc=0x0c0a8a7cu; return 0; }
write(ram,r[15],r[0],2);
goto P_0c0a8a7e;
P_0c0a8a7e: /* original 66f1, guest PC 0x0c0a8a7e */
if(!s->budget--) { s->failed_pc=0x0c0a8a7eu; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[15],2);
r[6]=tmp;
goto P_0c0a8a80;
P_0c0a8a80: /* original 7f04, guest PC 0x0c0a8a80 */
if(!s->budget--) { s->failed_pc=0x0c0a8a80u; return 0; }
r[15]+=0x00000004u;
goto P_0c0a8a82;
P_0c0a8a82: /* original 4f16, guest PC 0x0c0a8a82 */
if(!s->budget--) { s->failed_pc=0x0c0a8a82u; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a8a84;
P_0c0a8a84: /* original d30d, guest PC 0x0c0a8a84 */
if(!s->budget--) { s->failed_pc=0x0c0a8a84u; return 0; }
r[3]=read(ram,0x0c0a8abcu,4);
goto P_0c0a8a86;
P_0c0a8a86: /* original 4f26, guest PC 0x0c0a8a86 */
if(!s->budget--) { s->failed_pc=0x0c0a8a86u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a8a88;
P_0c0a8a88: /* original 6cf6, guest PC 0x0c0a8a88 */
if(!s->budget--) { s->failed_pc=0x0c0a8a88u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0a8a8a;
P_0c0a8a8a: /* original 6df6, guest PC 0x0c0a8a8a */
if(!s->budget--) { s->failed_pc=0x0c0a8a8au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0a8a8c;
P_0c0a8a8c: /* original 432b, guest PC 0x0c0a8a8c */
if(!s->budget--) { s->failed_pc=0x0c0a8a8cu; return 0; }
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
P_0c0a8a8e: /* original 6ef6, guest PC 0x0c0a8a8e */
if(!s->budget--) { s->failed_pc=0x0c0a8a8eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0a8a90u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0a8a90u; return 0; } return 1;
P_0c0a8f10: /* original c71d, guest PC 0x0c0a8f10 */
if(!s->budget--) { s->failed_pc=0x0c0a8f10u; return 0; }
r[0]=code_base|0x000a8f88u;
goto P_0c0a8f12;
P_0c0a8f12: /* original f558, guest PC 0x0c0a8f12 */
if(!s->budget--) { s->failed_pc=0x0c0a8f12u; return 0; }
vf3_matrix_load(s,ram,5,r[5]);
goto P_0c0a8f14;
P_0c0a8f14: /* original f408, guest PC 0x0c0a8f14 */
if(!s->budget--) { s->failed_pc=0x0c0a8f14u; return 0; }
vf3_matrix_load(s,ram,4,r[0]);
goto P_0c0a8f16;
P_0c0a8f16: /* original e010, guest PC 0x0c0a8f16 */
if(!s->budget--) { s->failed_pc=0x0c0a8f16u; return 0; }
r[0]=0x00000010u;
goto P_0c0a8f18;
P_0c0a8f18: /* original f346, guest PC 0x0c0a8f18 */
if(!s->budget--) { s->failed_pc=0x0c0a8f18u; return 0; }
vf3_matrix_load(s,ram,3,r[4]+r[0]);
goto P_0c0a8f1a;
P_0c0a8f1a: /* original e014, guest PC 0x0c0a8f1a */
if(!s->budget--) { s->failed_pc=0x0c0a8f1au; return 0; }
r[0]=0x00000014u;
goto P_0c0a8f1c;
P_0c0a8f1c: /* original f64c, guest PC 0x0c0a8f1c */
if(!s->budget--) { s->failed_pc=0x0c0a8f1cu; return 0; }
vf3_matrix_move(s,6,4);
goto P_0c0a8f1e;
P_0c0a8f1e: /* original f530, guest PC 0x0c0a8f1e */
if(!s->budget--) { s->failed_pc=0x0c0a8f1eu; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[3],r[18],'+');
goto P_0c0a8f20;
P_0c0a8f20: /* original f346, guest PC 0x0c0a8f20 */
if(!s->budget--) { s->failed_pc=0x0c0a8f20u; return 0; }
vf3_matrix_load(s,ram,3,r[4]+r[0]);
goto P_0c0a8f22;
P_0c0a8f22: /* original f74c, guest PC 0x0c0a8f22 */
if(!s->budget--) { s->failed_pc=0x0c0a8f22u; return 0; }
vf3_matrix_move(s,7,4);
goto P_0c0a8f24;
P_0c0a8f24: /* original e018, guest PC 0x0c0a8f24 */
if(!s->budget--) { s->failed_pc=0x0c0a8f24u; return 0; }
r[0]=0x00000018u;
goto P_0c0a8f26;
P_0c0a8f26: /* original f652, guest PC 0x0c0a8f26 */
if(!s->budget--) { s->failed_pc=0x0c0a8f26u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[5],r[18],'*');
goto P_0c0a8f28;
P_0c0a8f28: /* original f568, guest PC 0x0c0a8f28 */
if(!s->budget--) { s->failed_pc=0x0c0a8f28u; return 0; }
vf3_matrix_load(s,ram,5,r[6]);
goto P_0c0a8f2a;
P_0c0a8f2a: /* original f530, guest PC 0x0c0a8f2a */
if(!s->budget--) { s->failed_pc=0x0c0a8f2au; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[3],r[18],'+');
goto P_0c0a8f2c;
P_0c0a8f2c: /* original f346, guest PC 0x0c0a8f2c */
if(!s->budget--) { s->failed_pc=0x0c0a8f2cu; return 0; }
vf3_matrix_load(s,ram,3,r[4]+r[0]);
goto P_0c0a8f2e;
P_0c0a8f2e: /* original f752, guest PC 0x0c0a8f2e */
if(!s->budget--) { s->failed_pc=0x0c0a8f2eu; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[5],r[18],'*');
goto P_0c0a8f30;
P_0c0a8f30: /* original f578, guest PC 0x0c0a8f30 */
if(!s->budget--) { s->failed_pc=0x0c0a8f30u; return 0; }
vf3_matrix_load(s,ram,5,r[7]);
goto P_0c0a8f32;
P_0c0a8f32: /* original f56a, guest PC 0x0c0a8f32 */
if(!s->budget--) { s->failed_pc=0x0c0a8f32u; return 0; }
vf3_matrix_store(s,ram,6,r[5]);
goto P_0c0a8f34;
P_0c0a8f34: /* original f530, guest PC 0x0c0a8f34 */
if(!s->budget--) { s->failed_pc=0x0c0a8f34u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[3],r[18],'+');
goto P_0c0a8f36;
P_0c0a8f36: /* original f67a, guest PC 0x0c0a8f36 */
if(!s->budget--) { s->failed_pc=0x0c0a8f36u; return 0; }
vf3_matrix_store(s,ram,7,r[6]);
goto P_0c0a8f38;
P_0c0a8f38: /* original f452, guest PC 0x0c0a8f38 */
if(!s->budget--) { s->failed_pc=0x0c0a8f38u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[5],r[18],'*');
goto P_0c0a8f3a;
P_0c0a8f3a: /* original 000b, guest PC 0x0c0a8f3a */
if(!s->budget--) { s->failed_pc=0x0c0a8f3au; return 0; }
target=r[16];
vf3_matrix_store(s,ram,4,r[7]);
s->pc=target; return ram->oob==0;
P_0c0a8f3c: /* original f74a, guest PC 0x0c0a8f3c */
if(!s->budget--) { s->failed_pc=0x0c0a8f3cu; return 0; }
vf3_matrix_store(s,ram,4,r[7]);
goto P_0c0a8f3e;
P_0c0a8f3e: /* original 854f, guest PC 0x0c0a8f3e */
if(!s->budget--) { s->failed_pc=0x0c0a8f3eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+30,2);
goto P_0c0a8f40;
P_0c0a8f40: /* original 655f, guest PC 0x0c0a8f40 */
if(!s->budget--) { s->failed_pc=0x0c0a8f40u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)r[5];
goto P_0c0a8f42;
P_0c0a8f42: /* original 6403, guest PC 0x0c0a8f42 */
if(!s->budget--) { s->failed_pc=0x0c0a8f42u; return 0; }
r[4]=r[0];
goto P_0c0a8f44;
P_0c0a8f44: /* original 345c, guest PC 0x0c0a8f44 */
if(!s->budget--) { s->failed_pc=0x0c0a8f44u; return 0; }
r[4]+=r[5];
goto P_0c0a8f46;
P_0c0a8f46: /* original 4421, guest PC 0x0c0a8f46 */
if(!s->budget--) { s->failed_pc=0x0c0a8f46u; return 0; }
r[17]=(r[17]&~1u)|((r[4]&1)!=0);
r[4]=(uint32_t)((int32_t)r[4]>>1);
goto P_0c0a8f48;
P_0c0a8f48: /* original 000b, guest PC 0x0c0a8f48 */
if(!s->budget--) { s->failed_pc=0x0c0a8f48u; return 0; }
target=r[16];
r[0]=r[4];
s->pc=target; return ram->oob==0;
P_0c0a8f4a: /* original 6043, guest PC 0x0c0a8f4a */
if(!s->budget--) { s->failed_pc=0x0c0a8f4au; return 0; }
r[0]=r[4];
if(!vf3_matrix_family(0x0c0a8f4cu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0a8f4cu; return 0; } return 1;
P_0c0a8f8c: /* original 2fe6, guest PC 0x0c0a8f8c */
if(!s->budget--) { s->failed_pc=0x0c0a8f8cu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a8f8e;
P_0c0a8f8e: /* original 6e53, guest PC 0x0c0a8f8e */
if(!s->budget--) { s->failed_pc=0x0c0a8f8eu; return 0; }
r[14]=r[5];
goto P_0c0a8f90;
P_0c0a8f90: /* original 2fd6, guest PC 0x0c0a8f90 */
if(!s->budget--) { s->failed_pc=0x0c0a8f90u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a8f92;
P_0c0a8f92: /* original 6d43, guest PC 0x0c0a8f92 */
if(!s->budget--) { s->failed_pc=0x0c0a8f92u; return 0; }
r[13]=r[4];
goto P_0c0a8f94;
P_0c0a8f94: /* original 906b, guest PC 0x0c0a8f94 */
if(!s->budget--) { s->failed_pc=0x0c0a8f94u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a906eu,2);
goto P_0c0a8f96;
P_0c0a8f96: /* original e700, guest PC 0x0c0a8f96 */
if(!s->budget--) { s->failed_pc=0x0c0a8f96u; return 0; }
r[7]=0x00000000u;
goto P_0c0a8f98;
P_0c0a8f98: /* original 4f22, guest PC 0x0c0a8f98 */
if(!s->budget--) { s->failed_pc=0x0c0a8f98u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0a8f9a;
P_0c0a8f9a: /* original 04ee, guest PC 0x0c0a8f9a */
if(!s->budget--) { s->failed_pc=0x0c0a8f9au; return 0; }
r[4]=read(ram,r[14]+r[0],4);
goto P_0c0a8f9c;
P_0c0a8f9c: /* original e024, guest PC 0x0c0a8f9c */
if(!s->budget--) { s->failed_pc=0x0c0a8f9cu; return 0; }
r[0]=0x00000024u;
goto P_0c0a8f9e;
P_0c0a8f9e: /* original 00dd, guest PC 0x0c0a8f9e */
if(!s->budget--) { s->failed_pc=0x0c0a8f9eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[13]+r[0],2);
goto P_0c0a8fa0;
P_0c0a8fa0: /* original 7ff0, guest PC 0x0c0a8fa0 */
if(!s->budget--) { s->failed_pc=0x0c0a8fa0u; return 0; }
r[15]+=0xfffffff0u;
goto P_0c0a8fa2;
P_0c0a8fa2: /* original 81f6, guest PC 0x0c0a8fa2 */
if(!s->budget--) { s->failed_pc=0x0c0a8fa2u; return 0; }
write(ram,r[15]+12,r[0],2);
goto P_0c0a8fa4;
P_0c0a8fa4: /* original e03e, guest PC 0x0c0a8fa4 */
if(!s->budget--) { s->failed_pc=0x0c0a8fa4u; return 0; }
r[0]=0x0000003eu;
goto P_0c0a8fa6;
P_0c0a8fa6: /* original 0e45, guest PC 0x0c0a8fa6 */
if(!s->budget--) { s->failed_pc=0x0c0a8fa6u; return 0; }
write(ram,r[14]+r[0],r[4],2);
goto P_0c0a8fa8;
P_0c0a8fa8: /* original 85f6, guest PC 0x0c0a8fa8 */
if(!s->budget--) { s->failed_pc=0x0c0a8fa8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[15]+12,2);
goto P_0c0a8faa;
P_0c0a8faa: /* original 6503, guest PC 0x0c0a8faa */
if(!s->budget--) { s->failed_pc=0x0c0a8faau; return 0; }
r[5]=r[0];
goto P_0c0a8fac;
P_0c0a8fac: /* original 3450, guest PC 0x0c0a8fac */
if(!s->budget--) { s->failed_pc=0x0c0a8facu; return 0; }
r[17]=(r[17]&~1u)|((r[4]==r[5])!=0);
goto P_0c0a8fae;
P_0c0a8fae: /* original 8d01, guest PC 0x0c0a8fae */
if(!s->budget--) { s->failed_pc=0x0c0a8faeu; return 0; }
cond=r[17]&1u;
r[6]=r[7];
if(cond) { goto P_0c0a8fb4; }
goto P_0c0a8fb2;
P_0c0a8fb0: /* original 6673, guest PC 0x0c0a8fb0 */
if(!s->budget--) { s->failed_pc=0x0c0a8fb0u; return 0; }
r[6]=r[7];
goto P_0c0a8fb2;
P_0c0a8fb2: /* original 965d, guest PC 0x0c0a8fb2 */
if(!s->budget--) { s->failed_pc=0x0c0a8fb2u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a9070u,2);
goto P_0c0a8fb4;
P_0c0a8fb4: /* original 3457, guest PC 0x0c0a8fb4 */
if(!s->budget--) { s->failed_pc=0x0c0a8fb4u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>(int32_t)r[5])!=0);
goto P_0c0a8fb6;
P_0c0a8fb6: /* original e040, guest PC 0x0c0a8fb6 */
if(!s->budget--) { s->failed_pc=0x0c0a8fb6u; return 0; }
r[0]=0x00000040u;
goto P_0c0a8fb8;
P_0c0a8fb8: /* original 8d06, guest PC 0x0c0a8fb8 */
if(!s->budget--) { s->failed_pc=0x0c0a8fb8u; return 0; }
cond=r[17]&1u;
write(ram,r[14]+r[0],r[6],2);
if(cond) { goto P_0c0a8fc8; }
goto P_0c0a8fbc;
P_0c0a8fba: /* original 0e65, guest PC 0x0c0a8fba */
if(!s->budget--) { s->failed_pc=0x0c0a8fbau; return 0; }
write(ram,r[14]+r[0],r[6],2);
goto P_0c0a8fbc;
P_0c0a8fbc: /* original e03c, guest PC 0x0c0a8fbc */
if(!s->budget--) { s->failed_pc=0x0c0a8fbcu; return 0; }
r[0]=0x0000003cu;
goto P_0c0a8fbe;
P_0c0a8fbe: /* original 05ed, guest PC 0x0c0a8fbe */
if(!s->budget--) { s->failed_pc=0x0c0a8fbeu; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0a8fc0;
P_0c0a8fc0: /* original e022, guest PC 0x0c0a8fc0 */
if(!s->budget--) { s->failed_pc=0x0c0a8fc0u; return 0; }
r[0]=0x00000022u;
goto P_0c0a8fc2;
P_0c0a8fc2: /* original 04dd, guest PC 0x0c0a8fc2 */
if(!s->budget--) { s->failed_pc=0x0c0a8fc2u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[13]+r[0],2);
goto P_0c0a8fc4;
P_0c0a8fc4: /* original 3540, guest PC 0x0c0a8fc4 */
if(!s->budget--) { s->failed_pc=0x0c0a8fc4u; return 0; }
r[17]=(r[17]&~1u)|((r[5]==r[4])!=0);
goto P_0c0a8fc6;
P_0c0a8fc6: /* original 8902, guest PC 0x0c0a8fc6 */
if(!s->budget--) { s->failed_pc=0x0c0a8fc6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a8fce; }
goto P_0c0a8fc8;
P_0c0a8fc8: /* original e040, guest PC 0x0c0a8fc8 */
if(!s->budget--) { s->failed_pc=0x0c0a8fc8u; return 0; }
r[0]=0x00000040u;
goto P_0c0a8fca;
P_0c0a8fca: /* original a029, guest PC 0x0c0a8fca */
if(!s->budget--) { s->failed_pc=0x0c0a8fcau; return 0; }
write(ram,r[14]+r[0],r[7],2);
goto P_0c0a9020;
P_0c0a8fcc: /* original 0e75, guest PC 0x0c0a8fcc */
if(!s->budget--) { s->failed_pc=0x0c0a8fccu; return 0; }
write(ram,r[14]+r[0],r[7],2);
goto P_0c0a8fce;
P_0c0a8fce: /* original d62a, guest PC 0x0c0a8fce */
if(!s->budget--) { s->failed_pc=0x0c0a8fceu; return 0; }
r[6]=read(ram,0x0c0a9078u,4);
goto P_0c0a8fd0;
P_0c0a8fd0: /* original 65d2, guest PC 0x0c0a8fd0 */
if(!s->budget--) { s->failed_pc=0x0c0a8fd0u; return 0; }
tmp=read(ram,r[13],4);
r[5]=tmp;
goto P_0c0a8fd2;
P_0c0a8fd2: /* original 64e2, guest PC 0x0c0a8fd2 */
if(!s->budget--) { s->failed_pc=0x0c0a8fd2u; return 0; }
tmp=read(ram,r[14],4);
r[4]=tmp;
goto P_0c0a8fd4;
P_0c0a8fd4: /* original 2569, guest PC 0x0c0a8fd4 */
if(!s->budget--) { s->failed_pc=0x0c0a8fd4u; return 0; }
r[5]&=r[6];
goto P_0c0a8fd6;
P_0c0a8fd6: /* original 2469, guest PC 0x0c0a8fd6 */
if(!s->budget--) { s->failed_pc=0x0c0a8fd6u; return 0; }
r[4]&=r[6];
goto P_0c0a8fd8;
P_0c0a8fd8: /* original 3450, guest PC 0x0c0a8fd8 */
if(!s->budget--) { s->failed_pc=0x0c0a8fd8u; return 0; }
r[17]=(r[17]&~1u)|((r[4]==r[5])!=0);
goto P_0c0a8fda;
P_0c0a8fda: /* original 8b21, guest PC 0x0c0a8fda */
if(!s->budget--) { s->failed_pc=0x0c0a8fdau; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a9020; }
goto P_0c0a8fdc;
P_0c0a8fdc: /* original e004, guest PC 0x0c0a8fdc */
if(!s->budget--) { s->failed_pc=0x0c0a8fdcu; return 0; }
r[0]=0x00000004u;
goto P_0c0a8fde;
P_0c0a8fde: /* original 65f3, guest PC 0x0c0a8fde */
if(!s->budget--) { s->failed_pc=0x0c0a8fdeu; return 0; }
r[5]=r[15];
goto P_0c0a8fe0;
P_0c0a8fe0: /* original f3d6, guest PC 0x0c0a8fe0 */
if(!s->budget--) { s->failed_pc=0x0c0a8fe0u; return 0; }
vf3_matrix_load(s,ram,3,r[13]+r[0]);
goto P_0c0a8fe2;
P_0c0a8fe2: /* original e008, guest PC 0x0c0a8fe2 */
if(!s->budget--) { s->failed_pc=0x0c0a8fe2u; return 0; }
r[0]=0x00000008u;
goto P_0c0a8fe4;
P_0c0a8fe4: /* original 66f3, guest PC 0x0c0a8fe4 */
if(!s->budget--) { s->failed_pc=0x0c0a8fe4u; return 0; }
r[6]=r[15];
goto P_0c0a8fe6;
P_0c0a8fe6: /* original 7508, guest PC 0x0c0a8fe6 */
if(!s->budget--) { s->failed_pc=0x0c0a8fe6u; return 0; }
r[5]+=0x00000008u;
goto P_0c0a8fe8;
P_0c0a8fe8: /* original ff37, guest PC 0x0c0a8fe8 */
if(!s->budget--) { s->failed_pc=0x0c0a8fe8u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0a8fea;
P_0c0a8fea: /* original e008, guest PC 0x0c0a8fea */
if(!s->budget--) { s->failed_pc=0x0c0a8feau; return 0; }
r[0]=0x00000008u;
goto P_0c0a8fec;
P_0c0a8fec: /* original f3d6, guest PC 0x0c0a8fec */
if(!s->budget--) { s->failed_pc=0x0c0a8fecu; return 0; }
vf3_matrix_load(s,ram,3,r[13]+r[0]);
goto P_0c0a8fee;
P_0c0a8fee: /* original e004, guest PC 0x0c0a8fee */
if(!s->budget--) { s->failed_pc=0x0c0a8feeu; return 0; }
r[0]=0x00000004u;
goto P_0c0a8ff0;
P_0c0a8ff0: /* original 7604, guest PC 0x0c0a8ff0 */
if(!s->budget--) { s->failed_pc=0x0c0a8ff0u; return 0; }
r[6]+=0x00000004u;
goto P_0c0a8ff2;
P_0c0a8ff2: /* original 67f3, guest PC 0x0c0a8ff2 */
if(!s->budget--) { s->failed_pc=0x0c0a8ff2u; return 0; }
r[7]=r[15];
goto P_0c0a8ff4;
P_0c0a8ff4: /* original ff37, guest PC 0x0c0a8ff4 */
if(!s->budget--) { s->failed_pc=0x0c0a8ff4u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0a8ff6;
P_0c0a8ff6: /* original e00c, guest PC 0x0c0a8ff6 */
if(!s->budget--) { s->failed_pc=0x0c0a8ff6u; return 0; }
r[0]=0x0000000cu;
goto P_0c0a8ff8;
P_0c0a8ff8: /* original f3d6, guest PC 0x0c0a8ff8 */
if(!s->budget--) { s->failed_pc=0x0c0a8ff8u; return 0; }
vf3_matrix_load(s,ram,3,r[13]+r[0]);
goto P_0c0a8ffa;
P_0c0a8ffa: /* original ff3a, guest PC 0x0c0a8ffa */
if(!s->budget--) { s->failed_pc=0x0c0a8ffau; return 0; }
vf3_matrix_store(s,ram,3,r[15]);
goto P_0c0a8ffc;
P_0c0a8ffc: /* original bf88, guest PC 0x0c0a8ffc */
if(!s->budget--) { s->failed_pc=0x0c0a8ffcu; return 0; }
target=code_base|0x0c0a8f10u; r[16]=code_base|0x0c0a9000u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a9000u) { target=s->pc; goto dispatch; }
goto P_0c0a9000;
P_0c0a8ffe: /* original 64e3, guest PC 0x0c0a8ffe */
if(!s->budget--) { s->failed_pc=0x0c0a8ffeu; return 0; }
r[4]=r[14];
goto P_0c0a9000;
P_0c0a9000: /* original e008, guest PC 0x0c0a9000 */
if(!s->budget--) { s->failed_pc=0x0c0a9000u; return 0; }
r[0]=0x00000008u;
goto P_0c0a9002;
P_0c0a9002: /* original f6f8, guest PC 0x0c0a9002 */
if(!s->budget--) { s->failed_pc=0x0c0a9002u; return 0; }
vf3_matrix_load(s,ram,6,r[15]);
goto P_0c0a9004;
P_0c0a9004: /* original f4f6, guest PC 0x0c0a9004 */
if(!s->budget--) { s->failed_pc=0x0c0a9004u; return 0; }
vf3_matrix_load(s,ram,4,r[15]+r[0]);
goto P_0c0a9006;
P_0c0a9006: /* original e004, guest PC 0x0c0a9006 */
if(!s->budget--) { s->failed_pc=0x0c0a9006u; return 0; }
r[0]=0x00000004u;
goto P_0c0a9008;
P_0c0a9008: /* original f5f6, guest PC 0x0c0a9008 */
if(!s->budget--) { s->failed_pc=0x0c0a9008u; return 0; }
vf3_matrix_load(s,ram,5,r[15]+r[0]);
goto P_0c0a900a;
P_0c0a900a: /* original e010, guest PC 0x0c0a900a */
if(!s->budget--) { s->failed_pc=0x0c0a900au; return 0; }
r[0]=0x00000010u;
goto P_0c0a900c;
P_0c0a900c: /* original fe47, guest PC 0x0c0a900c */
if(!s->budget--) { s->failed_pc=0x0c0a900cu; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c0a900e;
P_0c0a900e: /* original e014, guest PC 0x0c0a900e */
if(!s->budget--) { s->failed_pc=0x0c0a900eu; return 0; }
r[0]=0x00000014u;
goto P_0c0a9010;
P_0c0a9010: /* original fe57, guest PC 0x0c0a9010 */
if(!s->budget--) { s->failed_pc=0x0c0a9010u; return 0; }
vf3_matrix_store(s,ram,5,r[14]+r[0]);
goto P_0c0a9012;
P_0c0a9012: /* original e018, guest PC 0x0c0a9012 */
if(!s->budget--) { s->failed_pc=0x0c0a9012u; return 0; }
r[0]=0x00000018u;
goto P_0c0a9014;
P_0c0a9014: /* original fe67, guest PC 0x0c0a9014 */
if(!s->budget--) { s->failed_pc=0x0c0a9014u; return 0; }
vf3_matrix_store(s,ram,6,r[14]+r[0]);
goto P_0c0a9016;
P_0c0a9016: /* original e020, guest PC 0x0c0a9016 */
if(!s->budget--) { s->failed_pc=0x0c0a9016u; return 0; }
r[0]=0x00000020u;
goto P_0c0a9018;
P_0c0a9018: /* original 05dd, guest PC 0x0c0a9018 */
if(!s->budget--) { s->failed_pc=0x0c0a9018u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,r[13]+r[0],2);
goto P_0c0a901a;
P_0c0a901a: /* original bf90, guest PC 0x0c0a901a */
if(!s->budget--) { s->failed_pc=0x0c0a901au; return 0; }
target=code_base|0x0c0a8f3eu; r[16]=code_base|0x0c0a901eu;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a901eu) { target=s->pc; goto dispatch; }
goto P_0c0a901e;
P_0c0a901c: /* original 64e3, guest PC 0x0c0a901c */
if(!s->budget--) { s->failed_pc=0x0c0a901cu; return 0; }
r[4]=r[14];
goto P_0c0a901e;
P_0c0a901e: /* original 81ef, guest PC 0x0c0a901e */
if(!s->budget--) { s->failed_pc=0x0c0a901eu; return 0; }
write(ram,r[14]+30,r[0],2);
goto P_0c0a9020;
P_0c0a9020: /* original d216, guest PC 0x0c0a9020 */
if(!s->budget--) { s->failed_pc=0x0c0a9020u; return 0; }
r[2]=read(ram,0x0c0a907cu,4);
goto P_0c0a9022;
P_0c0a9022: /* original 420b, guest PC 0x0c0a9022 */
if(!s->budget--) { s->failed_pc=0x0c0a9022u; return 0; }
target=r[2];
r[16]=code_base|0x0c0a9026u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a9026u) { target=s->pc; goto dispatch; }
goto P_0c0a9026;
P_0c0a9024: /* original 64e3, guest PC 0x0c0a9024 */
if(!s->budget--) { s->failed_pc=0x0c0a9024u; return 0; }
r[4]=r[14];
goto P_0c0a9026;
P_0c0a9026: /* original d316, guest PC 0x0c0a9026 */
if(!s->budget--) { s->failed_pc=0x0c0a9026u; return 0; }
r[3]=read(ram,0x0c0a9080u,4);
goto P_0c0a9028;
P_0c0a9028: /* original 430b, guest PC 0x0c0a9028 */
if(!s->budget--) { s->failed_pc=0x0c0a9028u; return 0; }
target=r[3];
r[16]=code_base|0x0c0a902cu;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a902cu) { target=s->pc; goto dispatch; }
goto P_0c0a902c;
P_0c0a902a: /* original 64e3, guest PC 0x0c0a902a */
if(!s->budget--) { s->failed_pc=0x0c0a902au; return 0; }
r[4]=r[14];
goto P_0c0a902c;
P_0c0a902c: /* original 7f10, guest PC 0x0c0a902c */
if(!s->budget--) { s->failed_pc=0x0c0a902cu; return 0; }
r[15]+=0x00000010u;
goto P_0c0a902e;
P_0c0a902e: /* original 4f26, guest PC 0x0c0a902e */
if(!s->budget--) { s->failed_pc=0x0c0a902eu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a9030;
P_0c0a9030: /* original 6df6, guest PC 0x0c0a9030 */
if(!s->budget--) { s->failed_pc=0x0c0a9030u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0a9032;
P_0c0a9032: /* original 000b, guest PC 0x0c0a9032 */
if(!s->budget--) { s->failed_pc=0x0c0a9032u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0a9034: /* original 6ef6, guest PC 0x0c0a9034 */
if(!s->budget--) { s->failed_pc=0x0c0a9034u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0a9036u,s,ram);
unsupported: s->failed_pc=target; return 0;
}
