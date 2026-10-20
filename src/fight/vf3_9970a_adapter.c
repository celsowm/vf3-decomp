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
int vf3_9970a_adapter(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u;
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c040b7cu: goto P_0c040b7c;
case 0x0c08a068u: goto P_0c08a068;
case 0x0c08a06au: goto P_0c08a06a;
case 0x0c08a06cu: goto P_0c08a06c;
case 0x0c08a06eu: goto P_0c08a06e;
case 0x0c08a070u: goto P_0c08a070;
case 0x0c08a072u: goto P_0c08a072;
case 0x0c08a074u: goto P_0c08a074;
case 0x0c091eb8u: goto P_0c091eb8;
case 0x0c091ebau: goto P_0c091eba;
case 0x0c091ebcu: goto P_0c091ebc;
case 0x0c091ebeu: goto P_0c091ebe;
case 0x0c091ec0u: goto P_0c091ec0;
case 0x0c091ec2u: goto P_0c091ec2;
case 0x0c091ec4u: goto P_0c091ec4;
case 0x0c091ec6u: goto P_0c091ec6;
case 0x0c091ec8u: goto P_0c091ec8;
case 0x0c091ecau: goto P_0c091eca;
case 0x0c091eccu: goto P_0c091ecc;
case 0x0c091eceu: goto P_0c091ece;
case 0x0c091ed0u: goto P_0c091ed0;
case 0x0c091ed2u: goto P_0c091ed2;
case 0x0c091ed4u: goto P_0c091ed4;
case 0x0c091ed6u: goto P_0c091ed6;
case 0x0c091ed8u: goto P_0c091ed8;
case 0x0c091edau: goto P_0c091eda;
case 0x0c091edcu: goto P_0c091edc;
case 0x0c091edeu: goto P_0c091ede;
case 0x0c091ee0u: goto P_0c091ee0;
case 0x0c091ee2u: goto P_0c091ee2;
case 0x0c091ee4u: goto P_0c091ee4;
case 0x0c091ee6u: goto P_0c091ee6;
case 0x0c091ee8u: goto P_0c091ee8;
case 0x0c091eeau: goto P_0c091eea;
case 0x0c091eecu: goto P_0c091eec;
case 0x0c091eeeu: goto P_0c091eee;
case 0x0c091ef0u: goto P_0c091ef0;
case 0x0c091ef2u: goto P_0c091ef2;
case 0x0c091ef4u: goto P_0c091ef4;
case 0x0c091ef6u: goto P_0c091ef6;
case 0x0c091ef8u: goto P_0c091ef8;
case 0x0c091efau: goto P_0c091efa;
case 0x0c091efcu: goto P_0c091efc;
case 0x0c091efeu: goto P_0c091efe;
case 0x0c091f00u: goto P_0c091f00;
case 0x0c091f02u: goto P_0c091f02;
case 0x0c091f04u: goto P_0c091f04;
case 0x0c091f06u: goto P_0c091f06;
case 0x0c091f08u: goto P_0c091f08;
case 0x0c091f0au: goto P_0c091f0a;
case 0x0c091f0cu: goto P_0c091f0c;
case 0x0c091f0eu: goto P_0c091f0e;
case 0x0c091f10u: goto P_0c091f10;
case 0x0c091f12u: goto P_0c091f12;
case 0x0c091f14u: goto P_0c091f14;
case 0x0c091f16u: goto P_0c091f16;
case 0x0c091f18u: goto P_0c091f18;
case 0x0c091f1au: goto P_0c091f1a;
case 0x0c091f1cu: goto P_0c091f1c;
case 0x0c091f1eu: goto P_0c091f1e;
case 0x0c091f20u: goto P_0c091f20;
case 0x0c091f22u: goto P_0c091f22;
case 0x0c091f24u: goto P_0c091f24;
case 0x0c091f26u: goto P_0c091f26;
case 0x0c091f28u: goto P_0c091f28;
case 0x0c091f2au: goto P_0c091f2a;
case 0x0c091f2cu: goto P_0c091f2c;
case 0x0c091f2eu: goto P_0c091f2e;
case 0x0c091f30u: goto P_0c091f30;
case 0x0c091f32u: goto P_0c091f32;
case 0x0c091f34u: goto P_0c091f34;
case 0x0c0970beu: goto P_0c0970be;
case 0x0c0970c0u: goto P_0c0970c0;
case 0x0c0970c2u: goto P_0c0970c2;
case 0x0c0970c4u: goto P_0c0970c4;
case 0x0c0970c6u: goto P_0c0970c6;
case 0x0c0970c8u: goto P_0c0970c8;
case 0x0c0970cau: goto P_0c0970ca;
case 0x0c0970ccu: goto P_0c0970cc;
case 0x0c0970ceu: goto P_0c0970ce;
case 0x0c0978eau: goto P_0c0978ea;
case 0x0c0978ecu: goto P_0c0978ec;
case 0x0c097abcu: goto P_0c097abc;
case 0x0c097abeu: goto P_0c097abe;
case 0x0c097ac0u: goto P_0c097ac0;
case 0x0c097ac2u: goto P_0c097ac2;
case 0x0c097ac4u: goto P_0c097ac4;
case 0x0c097ac6u: goto P_0c097ac6;
case 0x0c097ac8u: goto P_0c097ac8;
case 0x0c097acau: goto P_0c097aca;
case 0x0c097accu: goto P_0c097acc;
case 0x0c097aceu: goto P_0c097ace;
case 0x0c097ad0u: goto P_0c097ad0;
case 0x0c097ad2u: goto P_0c097ad2;
case 0x0c097ad4u: goto P_0c097ad4;
case 0x0c097ad6u: goto P_0c097ad6;
case 0x0c097ad8u: goto P_0c097ad8;
case 0x0c097adau: goto P_0c097ada;
case 0x0c097adcu: goto P_0c097adc;
case 0x0c097adeu: goto P_0c097ade;
case 0x0c097ae0u: goto P_0c097ae0;
case 0x0c097ae2u: goto P_0c097ae2;
case 0x0c097ae4u: goto P_0c097ae4;
case 0x0c097ae6u: goto P_0c097ae6;
case 0x0c097ae8u: goto P_0c097ae8;
case 0x0c097aeau: goto P_0c097aea;
case 0x0c097aecu: goto P_0c097aec;
case 0x0c097aeeu: goto P_0c097aee;
case 0x0c097af0u: goto P_0c097af0;
case 0x0c097af2u: goto P_0c097af2;
case 0x0c097af4u: goto P_0c097af4;
case 0x0c097af6u: goto P_0c097af6;
case 0x0c097af8u: goto P_0c097af8;
case 0x0c097afau: goto P_0c097afa;
case 0x0c097afcu: goto P_0c097afc;
case 0x0c097afeu: goto P_0c097afe;
case 0x0c097b00u: goto P_0c097b00;
case 0x0c097b02u: goto P_0c097b02;
case 0x0c097b04u: goto P_0c097b04;
case 0x0c097b06u: goto P_0c097b06;
case 0x0c097b08u: goto P_0c097b08;
case 0x0c097b0au: goto P_0c097b0a;
case 0x0c097b0cu: goto P_0c097b0c;
case 0x0c097b0eu: goto P_0c097b0e;
case 0x0c097b10u: goto P_0c097b10;
case 0x0c097b12u: goto P_0c097b12;
case 0x0c097b14u: goto P_0c097b14;
case 0x0c097b16u: goto P_0c097b16;
case 0x0c097b18u: goto P_0c097b18;
case 0x0c097b1au: goto P_0c097b1a;
case 0x0c097b1cu: goto P_0c097b1c;
case 0x0c097b1eu: goto P_0c097b1e;
case 0x0c097b20u: goto P_0c097b20;
case 0x0c097b22u: goto P_0c097b22;
case 0x0c097b24u: goto P_0c097b24;
case 0x0c097b26u: goto P_0c097b26;
case 0x0c097b28u: goto P_0c097b28;
case 0x0c097b2au: goto P_0c097b2a;
case 0x0c097b2cu: goto P_0c097b2c;
case 0x0c097b2eu: goto P_0c097b2e;
case 0x0c097b30u: goto P_0c097b30;
case 0x0c097b32u: goto P_0c097b32;
case 0x0c097b34u: goto P_0c097b34;
case 0x0c097b36u: goto P_0c097b36;
case 0x0c097b38u: goto P_0c097b38;
case 0x0c097b3au: goto P_0c097b3a;
case 0x0c097b3cu: goto P_0c097b3c;
case 0x0c097b3eu: goto P_0c097b3e;
case 0x0c097b40u: goto P_0c097b40;
case 0x0c097b42u: goto P_0c097b42;
case 0x0c097b44u: goto P_0c097b44;
case 0x0c097b46u: goto P_0c097b46;
case 0x0c097b48u: goto P_0c097b48;
case 0x0c097b4au: goto P_0c097b4a;
case 0x0c097b4cu: goto P_0c097b4c;
case 0x0c097b4eu: goto P_0c097b4e;
case 0x0c097b50u: goto P_0c097b50;
case 0x0c097b52u: goto P_0c097b52;
case 0x0c097b54u: goto P_0c097b54;
case 0x0c097b56u: goto P_0c097b56;
case 0x0c097b58u: goto P_0c097b58;
case 0x0c097b5au: goto P_0c097b5a;
case 0x0c097b5cu: goto P_0c097b5c;
case 0x0c097b5eu: goto P_0c097b5e;
case 0x0c097b60u: goto P_0c097b60;
case 0x0c097b62u: goto P_0c097b62;
case 0x0c097b64u: goto P_0c097b64;
case 0x0c097b66u: goto P_0c097b66;
case 0x0c097b68u: goto P_0c097b68;
case 0x0c097b6au: goto P_0c097b6a;
case 0x0c097b6cu: goto P_0c097b6c;
case 0x0c097b6eu: goto P_0c097b6e;
case 0x0c097b70u: goto P_0c097b70;
case 0x0c097b9cu: goto P_0c097b9c;
case 0x0c097b9eu: goto P_0c097b9e;
case 0x0c097ba0u: goto P_0c097ba0;
case 0x0c097ba2u: goto P_0c097ba2;
case 0x0c097ba4u: goto P_0c097ba4;
case 0x0c097ba6u: goto P_0c097ba6;
case 0x0c097ba8u: goto P_0c097ba8;
case 0x0c097baau: goto P_0c097baa;
case 0x0c097bacu: goto P_0c097bac;
case 0x0c097baeu: goto P_0c097bae;
case 0x0c097bb0u: goto P_0c097bb0;
case 0x0c097bb2u: goto P_0c097bb2;
case 0x0c097bb4u: goto P_0c097bb4;
case 0x0c097bb6u: goto P_0c097bb6;
case 0x0c097bb8u: goto P_0c097bb8;
case 0x0c097bbau: goto P_0c097bba;
case 0x0c097bbcu: goto P_0c097bbc;
case 0x0c097bbeu: goto P_0c097bbe;
case 0x0c097bc0u: goto P_0c097bc0;
case 0x0c097bc2u: goto P_0c097bc2;
case 0x0c097bc4u: goto P_0c097bc4;
case 0x0c097bc6u: goto P_0c097bc6;
case 0x0c097bc8u: goto P_0c097bc8;
case 0x0c097bcau: goto P_0c097bca;
case 0x0c097bccu: goto P_0c097bcc;
case 0x0c097bceu: goto P_0c097bce;
case 0x0c097bd0u: goto P_0c097bd0;
case 0x0c097bd2u: goto P_0c097bd2;
case 0x0c097bd4u: goto P_0c097bd4;
case 0x0c097bd6u: goto P_0c097bd6;
case 0x0c097bd8u: goto P_0c097bd8;
case 0x0c097bdau: goto P_0c097bda;
case 0x0c097bdcu: goto P_0c097bdc;
case 0x0c097bdeu: goto P_0c097bde;
case 0x0c097be0u: goto P_0c097be0;
case 0x0c097be2u: goto P_0c097be2;
case 0x0c097be4u: goto P_0c097be4;
case 0x0c097be6u: goto P_0c097be6;
case 0x0c097be8u: goto P_0c097be8;
case 0x0c097beau: goto P_0c097bea;
case 0x0c097becu: goto P_0c097bec;
case 0x0c097beeu: goto P_0c097bee;
case 0x0c097bf0u: goto P_0c097bf0;
case 0x0c097bf2u: goto P_0c097bf2;
case 0x0c097bf4u: goto P_0c097bf4;
case 0x0c097bf6u: goto P_0c097bf6;
case 0x0c097bf8u: goto P_0c097bf8;
case 0x0c097bfau: goto P_0c097bfa;
case 0x0c097bfcu: goto P_0c097bfc;
case 0x0c097bfeu: goto P_0c097bfe;
case 0x0c097c00u: goto P_0c097c00;
case 0x0c097c02u: goto P_0c097c02;
case 0x0c097c04u: goto P_0c097c04;
case 0x0c097c06u: goto P_0c097c06;
case 0x0c097c08u: goto P_0c097c08;
case 0x0c097c0au: goto P_0c097c0a;
case 0x0c097c0cu: goto P_0c097c0c;
case 0x0c097c0eu: goto P_0c097c0e;
case 0x0c097c10u: goto P_0c097c10;
case 0x0c097c12u: goto P_0c097c12;
case 0x0c097c14u: goto P_0c097c14;
case 0x0c097c16u: goto P_0c097c16;
case 0x0c097c18u: goto P_0c097c18;
case 0x0c097c1au: goto P_0c097c1a;
case 0x0c097c1cu: goto P_0c097c1c;
case 0x0c097c1eu: goto P_0c097c1e;
case 0x0c097c20u: goto P_0c097c20;
case 0x0c097c22u: goto P_0c097c22;
case 0x0c097c24u: goto P_0c097c24;
case 0x0c097c26u: goto P_0c097c26;
case 0x0c097c28u: goto P_0c097c28;
case 0x0c097c2au: goto P_0c097c2a;
case 0x0c097c2cu: goto P_0c097c2c;
case 0x0c097c2eu: goto P_0c097c2e;
case 0x0c097c30u: goto P_0c097c30;
case 0x0c097c32u: goto P_0c097c32;
case 0x0c097c34u: goto P_0c097c34;
case 0x0c097c36u: goto P_0c097c36;
case 0x0c097c38u: goto P_0c097c38;
case 0x0c097c3au: goto P_0c097c3a;
case 0x0c097c3cu: goto P_0c097c3c;
case 0x0c097c3eu: goto P_0c097c3e;
case 0x0c097c40u: goto P_0c097c40;
case 0x0c097c42u: goto P_0c097c42;
case 0x0c097c44u: goto P_0c097c44;
case 0x0c097c46u: goto P_0c097c46;
case 0x0c097c48u: goto P_0c097c48;
case 0x0c097c4au: goto P_0c097c4a;
case 0x0c097c4cu: goto P_0c097c4c;
case 0x0c097c4eu: goto P_0c097c4e;
case 0x0c097c50u: goto P_0c097c50;
case 0x0c097c52u: goto P_0c097c52;
case 0x0c097c54u: goto P_0c097c54;
case 0x0c097c56u: goto P_0c097c56;
case 0x0c097c58u: goto P_0c097c58;
case 0x0c097c5au: goto P_0c097c5a;
case 0x0c097c5cu: goto P_0c097c5c;
case 0x0c097c5eu: goto P_0c097c5e;
case 0x0c097c60u: goto P_0c097c60;
case 0x0c097c62u: goto P_0c097c62;
case 0x0c097c64u: goto P_0c097c64;
case 0x0c097c66u: goto P_0c097c66;
case 0x0c097c68u: goto P_0c097c68;
case 0x0c097c6au: goto P_0c097c6a;
case 0x0c097c6cu: goto P_0c097c6c;
case 0x0c097c6eu: goto P_0c097c6e;
case 0x0c097c70u: goto P_0c097c70;
case 0x0c097c72u: goto P_0c097c72;
case 0x0c097c74u: goto P_0c097c74;
case 0x0c097c76u: goto P_0c097c76;
case 0x0c097c78u: goto P_0c097c78;
case 0x0c097c7au: goto P_0c097c7a;
case 0x0c097c7cu: goto P_0c097c7c;
case 0x0c097c7eu: goto P_0c097c7e;
case 0x0c097c80u: goto P_0c097c80;
case 0x0c097c82u: goto P_0c097c82;
case 0x0c097c84u: goto P_0c097c84;
case 0x0c097c86u: goto P_0c097c86;
case 0x0c097c88u: goto P_0c097c88;
case 0x0c097c8au: goto P_0c097c8a;
case 0x0c097c8cu: goto P_0c097c8c;
case 0x0c097c8eu: goto P_0c097c8e;
case 0x0c097c90u: goto P_0c097c90;
case 0x0c097c92u: goto P_0c097c92;
case 0x0c097c94u: goto P_0c097c94;
case 0x0c097c96u: goto P_0c097c96;
case 0x0c097c98u: goto P_0c097c98;
case 0x0c097c9au: goto P_0c097c9a;
case 0x0c097c9cu: goto P_0c097c9c;
case 0x0c097c9eu: goto P_0c097c9e;
case 0x0c097ca0u: goto P_0c097ca0;
case 0x0c097ca2u: goto P_0c097ca2;
case 0x0c097ca4u: goto P_0c097ca4;
case 0x0c097ca6u: goto P_0c097ca6;
case 0x0c097ca8u: goto P_0c097ca8;
case 0x0c097caau: goto P_0c097caa;
case 0x0c097cacu: goto P_0c097cac;
case 0x0c097caeu: goto P_0c097cae;
case 0x0c097cb0u: goto P_0c097cb0;
case 0x0c097cb2u: goto P_0c097cb2;
case 0x0c097cb4u: goto P_0c097cb4;
case 0x0c097cb6u: goto P_0c097cb6;
case 0x0c097cb8u: goto P_0c097cb8;
case 0x0c097cbau: goto P_0c097cba;
case 0x0c097cbcu: goto P_0c097cbc;
case 0x0c097cbeu: goto P_0c097cbe;
case 0x0c097cc0u: goto P_0c097cc0;
case 0x0c097cc2u: goto P_0c097cc2;
case 0x0c097d18u: goto P_0c097d18;
case 0x0c097d1au: goto P_0c097d1a;
case 0x0c097d1cu: goto P_0c097d1c;
case 0x0c097d1eu: goto P_0c097d1e;
case 0x0c097d20u: goto P_0c097d20;
case 0x0c097d22u: goto P_0c097d22;
case 0x0c097d24u: goto P_0c097d24;
case 0x0c097d26u: goto P_0c097d26;
case 0x0c097d28u: goto P_0c097d28;
case 0x0c097d2au: goto P_0c097d2a;
case 0x0c097d2cu: goto P_0c097d2c;
case 0x0c097d2eu: goto P_0c097d2e;
case 0x0c097d30u: goto P_0c097d30;
case 0x0c097d32u: goto P_0c097d32;
case 0x0c097d34u: goto P_0c097d34;
case 0x0c097d36u: goto P_0c097d36;
case 0x0c097d38u: goto P_0c097d38;
case 0x0c097d3au: goto P_0c097d3a;
case 0x0c097d3cu: goto P_0c097d3c;
case 0x0c097d3eu: goto P_0c097d3e;
case 0x0c097d40u: goto P_0c097d40;
case 0x0c097d42u: goto P_0c097d42;
case 0x0c097d44u: goto P_0c097d44;
case 0x0c097d46u: goto P_0c097d46;
case 0x0c097d48u: goto P_0c097d48;
case 0x0c097d4au: goto P_0c097d4a;
case 0x0c097d4cu: goto P_0c097d4c;
case 0x0c097d4eu: goto P_0c097d4e;
case 0x0c097d50u: goto P_0c097d50;
case 0x0c097d52u: goto P_0c097d52;
case 0x0c097d54u: goto P_0c097d54;
case 0x0c097d56u: goto P_0c097d56;
case 0x0c097d58u: goto P_0c097d58;
case 0x0c097d5au: goto P_0c097d5a;
case 0x0c097d5cu: goto P_0c097d5c;
case 0x0c097d5eu: goto P_0c097d5e;
case 0x0c097d60u: goto P_0c097d60;
case 0x0c097d62u: goto P_0c097d62;
case 0x0c097d64u: goto P_0c097d64;
case 0x0c097d66u: goto P_0c097d66;
case 0x0c097d68u: goto P_0c097d68;
case 0x0c097d6au: goto P_0c097d6a;
case 0x0c097d6cu: goto P_0c097d6c;
case 0x0c097d6eu: goto P_0c097d6e;
case 0x0c097d70u: goto P_0c097d70;
case 0x0c097d72u: goto P_0c097d72;
case 0x0c097d74u: goto P_0c097d74;
case 0x0c097d76u: goto P_0c097d76;
case 0x0c097d78u: goto P_0c097d78;
case 0x0c097d7au: goto P_0c097d7a;
case 0x0c097d7cu: goto P_0c097d7c;
case 0x0c097d7eu: goto P_0c097d7e;
case 0x0c097d80u: goto P_0c097d80;
case 0x0c097d82u: goto P_0c097d82;
case 0x0c097d84u: goto P_0c097d84;
case 0x0c097d86u: goto P_0c097d86;
case 0x0c097d88u: goto P_0c097d88;
case 0x0c097d8au: goto P_0c097d8a;
case 0x0c097d8cu: goto P_0c097d8c;
case 0x0c097d8eu: goto P_0c097d8e;
case 0x0c097d90u: goto P_0c097d90;
case 0x0c097d92u: goto P_0c097d92;
case 0x0c097d94u: goto P_0c097d94;
case 0x0c097d96u: goto P_0c097d96;
case 0x0c097d98u: goto P_0c097d98;
case 0x0c097d9au: goto P_0c097d9a;
case 0x0c097d9cu: goto P_0c097d9c;
case 0x0c097d9eu: goto P_0c097d9e;
case 0x0c097da0u: goto P_0c097da0;
case 0x0c097da2u: goto P_0c097da2;
case 0x0c097da4u: goto P_0c097da4;
case 0x0c097da6u: goto P_0c097da6;
case 0x0c097da8u: goto P_0c097da8;
case 0x0c097daau: goto P_0c097daa;
case 0x0c097dacu: goto P_0c097dac;
case 0x0c097daeu: goto P_0c097dae;
case 0x0c097db0u: goto P_0c097db0;
case 0x0c097db2u: goto P_0c097db2;
case 0x0c097db4u: goto P_0c097db4;
case 0x0c097db6u: goto P_0c097db6;
case 0x0c097db8u: goto P_0c097db8;
case 0x0c097dbau: goto P_0c097dba;
case 0x0c097dbcu: goto P_0c097dbc;
case 0x0c097dbeu: goto P_0c097dbe;
case 0x0c097dc0u: goto P_0c097dc0;
case 0x0c097dc2u: goto P_0c097dc2;
case 0x0c097dc4u: goto P_0c097dc4;
case 0x0c097dc6u: goto P_0c097dc6;
case 0x0c097dc8u: goto P_0c097dc8;
case 0x0c097dcau: goto P_0c097dca;
case 0x0c097dccu: goto P_0c097dcc;
case 0x0c097dceu: goto P_0c097dce;
case 0x0c097dd0u: goto P_0c097dd0;
case 0x0c097dd2u: goto P_0c097dd2;
case 0x0c097dd4u: goto P_0c097dd4;
case 0x0c097dd6u: goto P_0c097dd6;
case 0x0c097dd8u: goto P_0c097dd8;
case 0x0c097ddau: goto P_0c097dda;
case 0x0c097ddcu: goto P_0c097ddc;
case 0x0c097ddeu: goto P_0c097dde;
case 0x0c097de0u: goto P_0c097de0;
case 0x0c097de2u: goto P_0c097de2;
case 0x0c097de4u: goto P_0c097de4;
case 0x0c097de6u: goto P_0c097de6;
case 0x0c097de8u: goto P_0c097de8;
case 0x0c097deau: goto P_0c097dea;
case 0x0c097decu: goto P_0c097dec;
case 0x0c097deeu: goto P_0c097dee;
case 0x0c097e0cu: goto P_0c097e0c;
case 0x0c097e0eu: goto P_0c097e0e;
case 0x0c097e10u: goto P_0c097e10;
case 0x0c097e12u: goto P_0c097e12;
case 0x0c097e14u: goto P_0c097e14;
case 0x0c097e16u: goto P_0c097e16;
case 0x0c097e18u: goto P_0c097e18;
case 0x0c097e1au: goto P_0c097e1a;
case 0x0c097e1cu: goto P_0c097e1c;
case 0x0c097e1eu: goto P_0c097e1e;
case 0x0c097e20u: goto P_0c097e20;
case 0x0c097e22u: goto P_0c097e22;
case 0x0c097e24u: goto P_0c097e24;
case 0x0c097e26u: goto P_0c097e26;
case 0x0c097e28u: goto P_0c097e28;
case 0x0c097e2au: goto P_0c097e2a;
case 0x0c097e2cu: goto P_0c097e2c;
case 0x0c097e2eu: goto P_0c097e2e;
case 0x0c097e30u: goto P_0c097e30;
case 0x0c097e32u: goto P_0c097e32;
case 0x0c097e34u: goto P_0c097e34;
case 0x0c097e36u: goto P_0c097e36;
case 0x0c097e38u: goto P_0c097e38;
case 0x0c097e3au: goto P_0c097e3a;
case 0x0c097e3cu: goto P_0c097e3c;
case 0x0c097e3eu: goto P_0c097e3e;
case 0x0c097e40u: goto P_0c097e40;
case 0x0c097e42u: goto P_0c097e42;
case 0x0c097e44u: goto P_0c097e44;
case 0x0c097e46u: goto P_0c097e46;
case 0x0c097e48u: goto P_0c097e48;
case 0x0c097e4au: goto P_0c097e4a;
case 0x0c097e4cu: goto P_0c097e4c;
case 0x0c097e4eu: goto P_0c097e4e;
case 0x0c097e50u: goto P_0c097e50;
case 0x0c097e52u: goto P_0c097e52;
case 0x0c097e54u: goto P_0c097e54;
case 0x0c097e56u: goto P_0c097e56;
case 0x0c097e58u: goto P_0c097e58;
case 0x0c097e5au: goto P_0c097e5a;
case 0x0c097e5cu: goto P_0c097e5c;
case 0x0c097e5eu: goto P_0c097e5e;
case 0x0c097e60u: goto P_0c097e60;
case 0x0c097e62u: goto P_0c097e62;
case 0x0c097e64u: goto P_0c097e64;
case 0x0c097e66u: goto P_0c097e66;
case 0x0c097e68u: goto P_0c097e68;
case 0x0c097e6au: goto P_0c097e6a;
case 0x0c097e6cu: goto P_0c097e6c;
case 0x0c097e6eu: goto P_0c097e6e;
case 0x0c097e70u: goto P_0c097e70;
case 0x0c097e72u: goto P_0c097e72;
case 0x0c097e74u: goto P_0c097e74;
case 0x0c097e76u: goto P_0c097e76;
case 0x0c097e78u: goto P_0c097e78;
case 0x0c097e7au: goto P_0c097e7a;
case 0x0c097e7cu: goto P_0c097e7c;
case 0x0c097e7eu: goto P_0c097e7e;
case 0x0c097e80u: goto P_0c097e80;
case 0x0c097e82u: goto P_0c097e82;
case 0x0c097e84u: goto P_0c097e84;
case 0x0c097e86u: goto P_0c097e86;
case 0x0c097e88u: goto P_0c097e88;
case 0x0c097e8au: goto P_0c097e8a;
case 0x0c097e8cu: goto P_0c097e8c;
case 0x0c097e8eu: goto P_0c097e8e;
case 0x0c097e90u: goto P_0c097e90;
case 0x0c097e92u: goto P_0c097e92;
case 0x0c097e94u: goto P_0c097e94;
case 0x0c097e96u: goto P_0c097e96;
case 0x0c097e98u: goto P_0c097e98;
case 0x0c097e9au: goto P_0c097e9a;
case 0x0c097e9cu: goto P_0c097e9c;
case 0x0c097e9eu: goto P_0c097e9e;
case 0x0c097ea0u: goto P_0c097ea0;
case 0x0c097ea2u: goto P_0c097ea2;
case 0x0c097ea4u: goto P_0c097ea4;
case 0x0c097eb6u: goto P_0c097eb6;
case 0x0c097eb8u: goto P_0c097eb8;
case 0x0c097ebau: goto P_0c097eba;
case 0x0c097ebcu: goto P_0c097ebc;
case 0x0c097ebeu: goto P_0c097ebe;
case 0x0c097ec0u: goto P_0c097ec0;
case 0x0c097ec2u: goto P_0c097ec2;
case 0x0c097ec4u: goto P_0c097ec4;
case 0x0c097ec6u: goto P_0c097ec6;
case 0x0c097ec8u: goto P_0c097ec8;
case 0x0c097ecau: goto P_0c097eca;
case 0x0c097eccu: goto P_0c097ecc;
case 0x0c097eceu: goto P_0c097ece;
case 0x0c097ed0u: goto P_0c097ed0;
case 0x0c097ed2u: goto P_0c097ed2;
case 0x0c097ed4u: goto P_0c097ed4;
case 0x0c097ed6u: goto P_0c097ed6;
case 0x0c097ed8u: goto P_0c097ed8;
case 0x0c097edau: goto P_0c097eda;
case 0x0c097edcu: goto P_0c097edc;
case 0x0c097edeu: goto P_0c097ede;
case 0x0c097ee0u: goto P_0c097ee0;
case 0x0c097ee2u: goto P_0c097ee2;
case 0x0c097ee4u: goto P_0c097ee4;
case 0x0c097ee6u: goto P_0c097ee6;
case 0x0c097ee8u: goto P_0c097ee8;
case 0x0c097eeau: goto P_0c097eea;
case 0x0c097eecu: goto P_0c097eec;
case 0x0c097eeeu: goto P_0c097eee;
case 0x0c097ef0u: goto P_0c097ef0;
case 0x0c097ef2u: goto P_0c097ef2;
case 0x0c097ef4u: goto P_0c097ef4;
case 0x0c097ef6u: goto P_0c097ef6;
case 0x0c097ef8u: goto P_0c097ef8;
case 0x0c097efau: goto P_0c097efa;
case 0x0c097efcu: goto P_0c097efc;
case 0x0c097efeu: goto P_0c097efe;
case 0x0c097f00u: goto P_0c097f00;
case 0x0c097f02u: goto P_0c097f02;
case 0x0c097f04u: goto P_0c097f04;
case 0x0c097f06u: goto P_0c097f06;
case 0x0c097f08u: goto P_0c097f08;
case 0x0c097f0au: goto P_0c097f0a;
case 0x0c097f0cu: goto P_0c097f0c;
case 0x0c097f0eu: goto P_0c097f0e;
case 0x0c097f10u: goto P_0c097f10;
case 0x0c097f12u: goto P_0c097f12;
case 0x0c097f14u: goto P_0c097f14;
case 0x0c097f16u: goto P_0c097f16;
case 0x0c097f18u: goto P_0c097f18;
case 0x0c097f1au: goto P_0c097f1a;
case 0x0c097f1cu: goto P_0c097f1c;
case 0x0c097f1eu: goto P_0c097f1e;
case 0x0c097f20u: goto P_0c097f20;
case 0x0c097f22u: goto P_0c097f22;
case 0x0c097f24u: goto P_0c097f24;
case 0x0c097f26u: goto P_0c097f26;
case 0x0c097f28u: goto P_0c097f28;
case 0x0c097f2au: goto P_0c097f2a;
case 0x0c097f2cu: goto P_0c097f2c;
case 0x0c097f2eu: goto P_0c097f2e;
case 0x0c097f30u: goto P_0c097f30;
case 0x0c097f32u: goto P_0c097f32;
case 0x0c097f34u: goto P_0c097f34;
case 0x0c097f36u: goto P_0c097f36;
case 0x0c097f38u: goto P_0c097f38;
case 0x0c097f3au: goto P_0c097f3a;
case 0x0c097f3cu: goto P_0c097f3c;
case 0x0c097f3eu: goto P_0c097f3e;
case 0x0c097f40u: goto P_0c097f40;
case 0x0c097f42u: goto P_0c097f42;
case 0x0c097f44u: goto P_0c097f44;
case 0x0c097f46u: goto P_0c097f46;
case 0x0c097f48u: goto P_0c097f48;
case 0x0c097f4au: goto P_0c097f4a;
case 0x0c097f4cu: goto P_0c097f4c;
case 0x0c097f4eu: goto P_0c097f4e;
case 0x0c097f50u: goto P_0c097f50;
case 0x0c097f52u: goto P_0c097f52;
case 0x0c097f54u: goto P_0c097f54;
case 0x0c097f56u: goto P_0c097f56;
case 0x0c097f58u: goto P_0c097f58;
case 0x0c097f5au: goto P_0c097f5a;
case 0x0c097f5cu: goto P_0c097f5c;
case 0x0c097f5eu: goto P_0c097f5e;
case 0x0c097f60u: goto P_0c097f60;
case 0x0c097f62u: goto P_0c097f62;
case 0x0c097f64u: goto P_0c097f64;
case 0x0c097f66u: goto P_0c097f66;
case 0x0c097f68u: goto P_0c097f68;
case 0x0c097f6au: goto P_0c097f6a;
case 0x0c097f6cu: goto P_0c097f6c;
case 0x0c097f6eu: goto P_0c097f6e;
case 0x0c097f70u: goto P_0c097f70;
case 0x0c097f72u: goto P_0c097f72;
case 0x0c097f74u: goto P_0c097f74;
case 0x0c097f76u: goto P_0c097f76;
case 0x0c097f78u: goto P_0c097f78;
case 0x0c097f9cu: goto P_0c097f9c;
case 0x0c097f9eu: goto P_0c097f9e;
case 0x0c097fa0u: goto P_0c097fa0;
case 0x0c097fa2u: goto P_0c097fa2;
case 0x0c097fa4u: goto P_0c097fa4;
case 0x0c097fa6u: goto P_0c097fa6;
case 0x0c097fa8u: goto P_0c097fa8;
case 0x0c097faau: goto P_0c097faa;
case 0x0c097facu: goto P_0c097fac;
case 0x0c097faeu: goto P_0c097fae;
case 0x0c097fb0u: goto P_0c097fb0;
case 0x0c097fb2u: goto P_0c097fb2;
case 0x0c097fb4u: goto P_0c097fb4;
case 0x0c097fb6u: goto P_0c097fb6;
case 0x0c097fb8u: goto P_0c097fb8;
case 0x0c097fbau: goto P_0c097fba;
case 0x0c097fbcu: goto P_0c097fbc;
case 0x0c097fbeu: goto P_0c097fbe;
case 0x0c097fc0u: goto P_0c097fc0;
case 0x0c097fc2u: goto P_0c097fc2;
case 0x0c097fc4u: goto P_0c097fc4;
case 0x0c097fc6u: goto P_0c097fc6;
case 0x0c097fc8u: goto P_0c097fc8;
case 0x0c097fcau: goto P_0c097fca;
case 0x0c097fccu: goto P_0c097fcc;
case 0x0c097fceu: goto P_0c097fce;
case 0x0c097fd0u: goto P_0c097fd0;
case 0x0c097fd2u: goto P_0c097fd2;
case 0x0c097fd4u: goto P_0c097fd4;
case 0x0c097fd6u: goto P_0c097fd6;
case 0x0c097fd8u: goto P_0c097fd8;
case 0x0c097fdau: goto P_0c097fda;
case 0x0c097fdcu: goto P_0c097fdc;
case 0x0c097fdeu: goto P_0c097fde;
case 0x0c097fe0u: goto P_0c097fe0;
case 0x0c097fe2u: goto P_0c097fe2;
case 0x0c097fe4u: goto P_0c097fe4;
case 0x0c097fe6u: goto P_0c097fe6;
case 0x0c097fe8u: goto P_0c097fe8;
case 0x0c097feau: goto P_0c097fea;
case 0x0c097fecu: goto P_0c097fec;
case 0x0c097feeu: goto P_0c097fee;
case 0x0c097ff0u: goto P_0c097ff0;
case 0x0c097ff2u: goto P_0c097ff2;
case 0x0c097ff4u: goto P_0c097ff4;
case 0x0c097ff6u: goto P_0c097ff6;
case 0x0c097ff8u: goto P_0c097ff8;
case 0x0c097ffau: goto P_0c097ffa;
case 0x0c097ffcu: goto P_0c097ffc;
case 0x0c097ffeu: goto P_0c097ffe;
case 0x0c098000u: goto P_0c098000;
case 0x0c098002u: goto P_0c098002;
case 0x0c098004u: goto P_0c098004;
case 0x0c098006u: goto P_0c098006;
case 0x0c098008u: goto P_0c098008;
case 0x0c09800au: goto P_0c09800a;
case 0x0c09800cu: goto P_0c09800c;
case 0x0c09800eu: goto P_0c09800e;
case 0x0c098010u: goto P_0c098010;
case 0x0c098012u: goto P_0c098012;
case 0x0c098014u: goto P_0c098014;
case 0x0c098016u: goto P_0c098016;
case 0x0c098018u: goto P_0c098018;
case 0x0c09801au: goto P_0c09801a;
case 0x0c09801cu: goto P_0c09801c;
case 0x0c09801eu: goto P_0c09801e;
case 0x0c098020u: goto P_0c098020;
case 0x0c098022u: goto P_0c098022;
case 0x0c098024u: goto P_0c098024;
case 0x0c098026u: goto P_0c098026;
case 0x0c098028u: goto P_0c098028;
case 0x0c09802au: goto P_0c09802a;
case 0x0c09802cu: goto P_0c09802c;
case 0x0c09802eu: goto P_0c09802e;
case 0x0c098030u: goto P_0c098030;
case 0x0c098032u: goto P_0c098032;
case 0x0c098034u: goto P_0c098034;
case 0x0c098036u: goto P_0c098036;
case 0x0c098038u: goto P_0c098038;
case 0x0c09803au: goto P_0c09803a;
case 0x0c09803cu: goto P_0c09803c;
case 0x0c09803eu: goto P_0c09803e;
case 0x0c0983bcu: goto P_0c0983bc;
case 0x0c0983beu: goto P_0c0983be;
case 0x0c0983c0u: goto P_0c0983c0;
case 0x0c0983c2u: goto P_0c0983c2;
case 0x0c0983c4u: goto P_0c0983c4;
case 0x0c0983c6u: goto P_0c0983c6;
case 0x0c0983c8u: goto P_0c0983c8;
case 0x0c0983cau: goto P_0c0983ca;
case 0x0c0983ccu: goto P_0c0983cc;
case 0x0c0983ceu: goto P_0c0983ce;
case 0x0c0983d0u: goto P_0c0983d0;
case 0x0c0983d2u: goto P_0c0983d2;
case 0x0c0983d4u: goto P_0c0983d4;
case 0x0c0983d6u: goto P_0c0983d6;
case 0x0c0983d8u: goto P_0c0983d8;
case 0x0c0983dau: goto P_0c0983da;
case 0x0c0983dcu: goto P_0c0983dc;
case 0x0c0983deu: goto P_0c0983de;
case 0x0c0983e0u: goto P_0c0983e0;
case 0x0c0983e2u: goto P_0c0983e2;
case 0x0c0983e4u: goto P_0c0983e4;
case 0x0c0983e6u: goto P_0c0983e6;
case 0x0c0983e8u: goto P_0c0983e8;
case 0x0c0983eau: goto P_0c0983ea;
case 0x0c0983ecu: goto P_0c0983ec;
case 0x0c0983eeu: goto P_0c0983ee;
case 0x0c0983f0u: goto P_0c0983f0;
case 0x0c0983f2u: goto P_0c0983f2;
case 0x0c0983f4u: goto P_0c0983f4;
case 0x0c0983f6u: goto P_0c0983f6;
case 0x0c0983f8u: goto P_0c0983f8;
case 0x0c0983fau: goto P_0c0983fa;
case 0x0c0983fcu: goto P_0c0983fc;
case 0x0c0983feu: goto P_0c0983fe;
case 0x0c098400u: goto P_0c098400;
case 0x0c098402u: goto P_0c098402;
case 0x0c098404u: goto P_0c098404;
case 0x0c098406u: goto P_0c098406;
case 0x0c098408u: goto P_0c098408;
case 0x0c09840au: goto P_0c09840a;
case 0x0c09840cu: goto P_0c09840c;
case 0x0c09840eu: goto P_0c09840e;
case 0x0c098410u: goto P_0c098410;
case 0x0c098412u: goto P_0c098412;
case 0x0c098414u: goto P_0c098414;
case 0x0c098416u: goto P_0c098416;
case 0x0c098418u: goto P_0c098418;
case 0x0c09841au: goto P_0c09841a;
case 0x0c09841cu: goto P_0c09841c;
case 0x0c09841eu: goto P_0c09841e;
case 0x0c098420u: goto P_0c098420;
case 0x0c098422u: goto P_0c098422;
case 0x0c098424u: goto P_0c098424;
case 0x0c098426u: goto P_0c098426;
case 0x0c098428u: goto P_0c098428;
case 0x0c09842au: goto P_0c09842a;
case 0x0c09842cu: goto P_0c09842c;
case 0x0c09842eu: goto P_0c09842e;
case 0x0c098430u: goto P_0c098430;
case 0x0c098432u: goto P_0c098432;
case 0x0c09873eu: goto P_0c09873e;
case 0x0c098740u: goto P_0c098740;
case 0x0c098742u: goto P_0c098742;
case 0x0c098744u: goto P_0c098744;
case 0x0c098746u: goto P_0c098746;
case 0x0c098918u: goto P_0c098918;
case 0x0c09891au: goto P_0c09891a;
case 0x0c09891cu: goto P_0c09891c;
case 0x0c09891eu: goto P_0c09891e;
case 0x0c098920u: goto P_0c098920;
case 0x0c098922u: goto P_0c098922;
case 0x0c098924u: goto P_0c098924;
case 0x0c098926u: goto P_0c098926;
case 0x0c098928u: goto P_0c098928;
case 0x0c09892au: goto P_0c09892a;
case 0x0c09892cu: goto P_0c09892c;
case 0x0c09892eu: goto P_0c09892e;
case 0x0c098930u: goto P_0c098930;
case 0x0c098932u: goto P_0c098932;
case 0x0c098934u: goto P_0c098934;
case 0x0c098936u: goto P_0c098936;
case 0x0c098938u: goto P_0c098938;
case 0x0c09893au: goto P_0c09893a;
case 0x0c09893cu: goto P_0c09893c;
case 0x0c09893eu: goto P_0c09893e;
case 0x0c098940u: goto P_0c098940;
case 0x0c098942u: goto P_0c098942;
case 0x0c098944u: goto P_0c098944;
case 0x0c098946u: goto P_0c098946;
case 0x0c098948u: goto P_0c098948;
case 0x0c09894au: goto P_0c09894a;
case 0x0c09894cu: goto P_0c09894c;
case 0x0c09894eu: goto P_0c09894e;
case 0x0c098950u: goto P_0c098950;
case 0x0c098952u: goto P_0c098952;
case 0x0c098954u: goto P_0c098954;
case 0x0c098956u: goto P_0c098956;
case 0x0c098958u: goto P_0c098958;
case 0x0c09895au: goto P_0c09895a;
case 0x0c09895cu: goto P_0c09895c;
case 0x0c09895eu: goto P_0c09895e;
case 0x0c098960u: goto P_0c098960;
case 0x0c098962u: goto P_0c098962;
case 0x0c098964u: goto P_0c098964;
case 0x0c098966u: goto P_0c098966;
case 0x0c098968u: goto P_0c098968;
case 0x0c09896au: goto P_0c09896a;
case 0x0c09896cu: goto P_0c09896c;
case 0x0c09896eu: goto P_0c09896e;
case 0x0c098970u: goto P_0c098970;
case 0x0c098972u: goto P_0c098972;
case 0x0c098974u: goto P_0c098974;
case 0x0c098976u: goto P_0c098976;
case 0x0c098978u: goto P_0c098978;
case 0x0c09897au: goto P_0c09897a;
case 0x0c09897cu: goto P_0c09897c;
case 0x0c09897eu: goto P_0c09897e;
case 0x0c098980u: goto P_0c098980;
case 0x0c098982u: goto P_0c098982;
case 0x0c098984u: goto P_0c098984;
case 0x0c098986u: goto P_0c098986;
case 0x0c098988u: goto P_0c098988;
case 0x0c09898au: goto P_0c09898a;
case 0x0c09898cu: goto P_0c09898c;
case 0x0c09898eu: goto P_0c09898e;
case 0x0c098990u: goto P_0c098990;
case 0x0c098992u: goto P_0c098992;
case 0x0c098994u: goto P_0c098994;
case 0x0c098996u: goto P_0c098996;
case 0x0c098998u: goto P_0c098998;
case 0x0c09899au: goto P_0c09899a;
case 0x0c09899cu: goto P_0c09899c;
case 0x0c09899eu: goto P_0c09899e;
case 0x0c0989a0u: goto P_0c0989a0;
case 0x0c0989a2u: goto P_0c0989a2;
case 0x0c0989a4u: goto P_0c0989a4;
case 0x0c0989a6u: goto P_0c0989a6;
case 0x0c0989a8u: goto P_0c0989a8;
case 0x0c0989aau: goto P_0c0989aa;
case 0x0c0989acu: goto P_0c0989ac;
case 0x0c0989aeu: goto P_0c0989ae;
case 0x0c0989b0u: goto P_0c0989b0;
case 0x0c0989b2u: goto P_0c0989b2;
case 0x0c0989b4u: goto P_0c0989b4;
case 0x0c0989b6u: goto P_0c0989b6;
case 0x0c0989b8u: goto P_0c0989b8;
case 0x0c0989bau: goto P_0c0989ba;
case 0x0c0989bcu: goto P_0c0989bc;
case 0x0c0989beu: goto P_0c0989be;
case 0x0c0989c0u: goto P_0c0989c0;
case 0x0c0989c2u: goto P_0c0989c2;
case 0x0c0989fcu: goto P_0c0989fc;
case 0x0c0989feu: goto P_0c0989fe;
case 0x0c098a00u: goto P_0c098a00;
case 0x0c098a02u: goto P_0c098a02;
case 0x0c098a04u: goto P_0c098a04;
case 0x0c098a06u: goto P_0c098a06;
case 0x0c098a08u: goto P_0c098a08;
case 0x0c098a0au: goto P_0c098a0a;
case 0x0c098a0cu: goto P_0c098a0c;
case 0x0c098b3cu: goto P_0c098b3c;
case 0x0c098b3eu: goto P_0c098b3e;
case 0x0c098b40u: goto P_0c098b40;
case 0x0c098b42u: goto P_0c098b42;
case 0x0c098b44u: goto P_0c098b44;
case 0x0c098b46u: goto P_0c098b46;
case 0x0c098b48u: goto P_0c098b48;
case 0x0c098b4au: goto P_0c098b4a;
case 0x0c098b4cu: goto P_0c098b4c;
case 0x0c098b4eu: goto P_0c098b4e;
case 0x0c098b50u: goto P_0c098b50;
case 0x0c098b52u: goto P_0c098b52;
case 0x0c098b54u: goto P_0c098b54;
case 0x0c098b56u: goto P_0c098b56;
case 0x0c098b58u: goto P_0c098b58;
case 0x0c098b5au: goto P_0c098b5a;
case 0x0c098b5cu: goto P_0c098b5c;
case 0x0c098b5eu: goto P_0c098b5e;
case 0x0c098b60u: goto P_0c098b60;
case 0x0c098b62u: goto P_0c098b62;
case 0x0c098b64u: goto P_0c098b64;
case 0x0c098b66u: goto P_0c098b66;
case 0x0c098b68u: goto P_0c098b68;
case 0x0c098b6au: goto P_0c098b6a;
case 0x0c098b6cu: goto P_0c098b6c;
case 0x0c098b6eu: goto P_0c098b6e;
case 0x0c098b70u: goto P_0c098b70;
case 0x0c098b72u: goto P_0c098b72;
case 0x0c098b74u: goto P_0c098b74;
case 0x0c098b76u: goto P_0c098b76;
case 0x0c098b78u: goto P_0c098b78;
case 0x0c098b7au: goto P_0c098b7a;
case 0x0c098b7cu: goto P_0c098b7c;
case 0x0c098b7eu: goto P_0c098b7e;
case 0x0c098b80u: goto P_0c098b80;
case 0x0c098b82u: goto P_0c098b82;
case 0x0c098b84u: goto P_0c098b84;
case 0x0c098b86u: goto P_0c098b86;
case 0x0c098b88u: goto P_0c098b88;
case 0x0c098b8au: goto P_0c098b8a;
case 0x0c098b8cu: goto P_0c098b8c;
case 0x0c098b8eu: goto P_0c098b8e;
case 0x0c098b90u: goto P_0c098b90;
case 0x0c098b92u: goto P_0c098b92;
case 0x0c098b94u: goto P_0c098b94;
case 0x0c098b96u: goto P_0c098b96;
case 0x0c098b98u: goto P_0c098b98;
case 0x0c098b9au: goto P_0c098b9a;
case 0x0c098b9cu: goto P_0c098b9c;
case 0x0c098b9eu: goto P_0c098b9e;
case 0x0c098ba0u: goto P_0c098ba0;
case 0x0c098ba2u: goto P_0c098ba2;
case 0x0c098ba4u: goto P_0c098ba4;
case 0x0c098ba6u: goto P_0c098ba6;
case 0x0c098ba8u: goto P_0c098ba8;
case 0x0c098baau: goto P_0c098baa;
case 0x0c098bacu: goto P_0c098bac;
case 0x0c098baeu: goto P_0c098bae;
case 0x0c098bb0u: goto P_0c098bb0;
case 0x0c098bb2u: goto P_0c098bb2;
case 0x0c098bb4u: goto P_0c098bb4;
case 0x0c098bb6u: goto P_0c098bb6;
case 0x0c098bb8u: goto P_0c098bb8;
case 0x0c098bbau: goto P_0c098bba;
case 0x0c098bbcu: goto P_0c098bbc;
case 0x0c098bbeu: goto P_0c098bbe;
case 0x0c098bc0u: goto P_0c098bc0;
case 0x0c098bc2u: goto P_0c098bc2;
case 0x0c098bc4u: goto P_0c098bc4;
case 0x0c098bc6u: goto P_0c098bc6;
case 0x0c098bc8u: goto P_0c098bc8;
case 0x0c098bcau: goto P_0c098bca;
case 0x0c098c1cu: goto P_0c098c1c;
case 0x0c098c1eu: goto P_0c098c1e;
case 0x0c098c20u: goto P_0c098c20;
case 0x0c098c22u: goto P_0c098c22;
case 0x0c098c24u: goto P_0c098c24;
case 0x0c098c26u: goto P_0c098c26;
case 0x0c098c28u: goto P_0c098c28;
case 0x0c098c2au: goto P_0c098c2a;
case 0x0c098c2cu: goto P_0c098c2c;
case 0x0c098c2eu: goto P_0c098c2e;
case 0x0c098c30u: goto P_0c098c30;
case 0x0c098c32u: goto P_0c098c32;
case 0x0c098c34u: goto P_0c098c34;
case 0x0c098c36u: goto P_0c098c36;
case 0x0c098c38u: goto P_0c098c38;
case 0x0c098c3au: goto P_0c098c3a;
case 0x0c098c3cu: goto P_0c098c3c;
case 0x0c098c3eu: goto P_0c098c3e;
case 0x0c098c40u: goto P_0c098c40;
case 0x0c098c42u: goto P_0c098c42;
case 0x0c098c44u: goto P_0c098c44;
case 0x0c098c46u: goto P_0c098c46;
case 0x0c098c48u: goto P_0c098c48;
case 0x0c098c4au: goto P_0c098c4a;
case 0x0c098c4cu: goto P_0c098c4c;
case 0x0c098c4eu: goto P_0c098c4e;
case 0x0c098c50u: goto P_0c098c50;
case 0x0c098c52u: goto P_0c098c52;
case 0x0c098c54u: goto P_0c098c54;
case 0x0c098c56u: goto P_0c098c56;
case 0x0c098c58u: goto P_0c098c58;
case 0x0c098c5au: goto P_0c098c5a;
case 0x0c098c5cu: goto P_0c098c5c;
case 0x0c098c5eu: goto P_0c098c5e;
case 0x0c098c60u: goto P_0c098c60;
case 0x0c09970au: goto P_0c09970a;
case 0x0c09970cu: goto P_0c09970c;
case 0x0c09970eu: goto P_0c09970e;
case 0x0c099710u: goto P_0c099710;
case 0x0c099712u: goto P_0c099712;
case 0x0c099714u: goto P_0c099714;
case 0x0c099716u: goto P_0c099716;
case 0x0c099718u: goto P_0c099718;
case 0x0c09971au: goto P_0c09971a;
case 0x0c09971cu: goto P_0c09971c;
case 0x0c09971eu: goto P_0c09971e;
case 0x0c099720u: goto P_0c099720;
case 0x0c099722u: goto P_0c099722;
case 0x0c099724u: goto P_0c099724;
case 0x0c099726u: goto P_0c099726;
case 0x0c099728u: goto P_0c099728;
case 0x0c09972au: goto P_0c09972a;
case 0x0c09972cu: goto P_0c09972c;
case 0x0c09972eu: goto P_0c09972e;
case 0x0c099730u: goto P_0c099730;
case 0x0c099732u: goto P_0c099732;
case 0x0c099734u: goto P_0c099734;
case 0x0c099736u: goto P_0c099736;
case 0x0c099738u: goto P_0c099738;
case 0x0c09973au: goto P_0c09973a;
case 0x0c09973cu: goto P_0c09973c;
case 0x0c09973eu: goto P_0c09973e;
case 0x0c099740u: goto P_0c099740;
case 0x0c099742u: goto P_0c099742;
case 0x0c099744u: goto P_0c099744;
case 0x0c099746u: goto P_0c099746;
case 0x0c099748u: goto P_0c099748;
case 0x0c09974au: goto P_0c09974a;
case 0x0c09974cu: goto P_0c09974c;
case 0x0c09974eu: goto P_0c09974e;
case 0x0c099750u: goto P_0c099750;
case 0x0c099752u: goto P_0c099752;
case 0x0c099754u: goto P_0c099754;
case 0x0c099756u: goto P_0c099756;
case 0x0c099758u: goto P_0c099758;
case 0x0c09975au: goto P_0c09975a;
case 0x0c09975cu: goto P_0c09975c;
case 0x0c09975eu: goto P_0c09975e;
case 0x0c099760u: goto P_0c099760;
case 0x0c099762u: goto P_0c099762;
case 0x0c099764u: goto P_0c099764;
case 0x0c099766u: goto P_0c099766;
case 0x0c099768u: goto P_0c099768;
case 0x0c099784u: goto P_0c099784;
case 0x0c099786u: goto P_0c099786;
case 0x0c099788u: goto P_0c099788;
case 0x0c09978au: goto P_0c09978a;
case 0x0c09978cu: goto P_0c09978c;
case 0x0c09978eu: goto P_0c09978e;
case 0x0c099790u: goto P_0c099790;
case 0x0c099792u: goto P_0c099792;
case 0x0c099794u: goto P_0c099794;
case 0x0c099796u: goto P_0c099796;
case 0x0c099798u: goto P_0c099798;
case 0x0c09979au: goto P_0c09979a;
case 0x0c09979cu: goto P_0c09979c;
case 0x0c09979eu: goto P_0c09979e;
case 0x0c0997a0u: goto P_0c0997a0;
case 0x0c0997a2u: goto P_0c0997a2;
case 0x0c0997a4u: goto P_0c0997a4;
case 0x0c0997a6u: goto P_0c0997a6;
case 0x0c0997a8u: goto P_0c0997a8;
case 0x0c0997aau: goto P_0c0997aa;
case 0x0c0997acu: goto P_0c0997ac;
case 0x0c0997aeu: goto P_0c0997ae;
case 0x0c0997b0u: goto P_0c0997b0;
case 0x0c0997b2u: goto P_0c0997b2;
case 0x0c0997b4u: goto P_0c0997b4;
case 0x0c0997b6u: goto P_0c0997b6;
case 0x0c0997b8u: goto P_0c0997b8;
case 0x0c0997bau: goto P_0c0997ba;
case 0x0c0997bcu: goto P_0c0997bc;
case 0x0c0997beu: goto P_0c0997be;
case 0x0c0997c0u: goto P_0c0997c0;
case 0x0c0997c2u: goto P_0c0997c2;
case 0x0c0997c4u: goto P_0c0997c4;
case 0x0c0997c6u: goto P_0c0997c6;
case 0x0c0997c8u: goto P_0c0997c8;
case 0x0c0997cau: goto P_0c0997ca;
case 0x0c0997ccu: goto P_0c0997cc;
case 0x0c0997ceu: goto P_0c0997ce;
case 0x0c0997d0u: goto P_0c0997d0;
case 0x0c0997d2u: goto P_0c0997d2;
case 0x0c0997d4u: goto P_0c0997d4;
case 0x0c0997d6u: goto P_0c0997d6;
case 0x0c0997d8u: goto P_0c0997d8;
case 0x0c0997dau: goto P_0c0997da;
case 0x0c0997dcu: goto P_0c0997dc;
case 0x0c0997deu: goto P_0c0997de;
case 0x0c0997e0u: goto P_0c0997e0;
case 0x0c0997e2u: goto P_0c0997e2;
case 0x0c0997e4u: goto P_0c0997e4;
case 0x0c0997e6u: goto P_0c0997e6;
case 0x0c0997e8u: goto P_0c0997e8;
case 0x0c0997eau: goto P_0c0997ea;
case 0x0c0997ecu: goto P_0c0997ec;
case 0x0c0997eeu: goto P_0c0997ee;
case 0x0c0997f0u: goto P_0c0997f0;
case 0x0c0997f2u: goto P_0c0997f2;
case 0x0c0997f4u: goto P_0c0997f4;
case 0x0c0997f6u: goto P_0c0997f6;
case 0x0c0997f8u: goto P_0c0997f8;
case 0x0c0997fau: goto P_0c0997fa;
case 0x0c0997fcu: goto P_0c0997fc;
case 0x0c0997feu: goto P_0c0997fe;
case 0x0c099800u: goto P_0c099800;
case 0x0c099802u: goto P_0c099802;
case 0x0c099804u: goto P_0c099804;
case 0x0c099806u: goto P_0c099806;
case 0x0c099808u: goto P_0c099808;
case 0x0c09980au: goto P_0c09980a;
case 0x0c09980cu: goto P_0c09980c;
case 0x0c09980eu: goto P_0c09980e;
case 0x0c099810u: goto P_0c099810;
case 0x0c099812u: goto P_0c099812;
case 0x0c099814u: goto P_0c099814;
case 0x0c099816u: goto P_0c099816;
case 0x0c099818u: goto P_0c099818;
case 0x0c09981au: goto P_0c09981a;
case 0x0c09981cu: goto P_0c09981c;
case 0x0c09981eu: goto P_0c09981e;
case 0x0c099820u: goto P_0c099820;
case 0x0c099822u: goto P_0c099822;
case 0x0c099824u: goto P_0c099824;
case 0x0c099826u: goto P_0c099826;
case 0x0c099828u: goto P_0c099828;
case 0x0c09982au: goto P_0c09982a;
case 0x0c09982cu: goto P_0c09982c;
case 0x0c09982eu: goto P_0c09982e;
case 0x0c099830u: goto P_0c099830;
case 0x0c099832u: goto P_0c099832;
case 0x0c099834u: goto P_0c099834;
case 0x0c099836u: goto P_0c099836;
case 0x0c099838u: goto P_0c099838;
case 0x0c09983au: goto P_0c09983a;
case 0x0c09983cu: goto P_0c09983c;
case 0x0c09983eu: goto P_0c09983e;
case 0x0c099840u: goto P_0c099840;
case 0x0c099842u: goto P_0c099842;
case 0x0c099844u: goto P_0c099844;
case 0x0c099846u: goto P_0c099846;
case 0x0c099848u: goto P_0c099848;
case 0x0c09984au: goto P_0c09984a;
case 0x0c09984cu: goto P_0c09984c;
case 0x0c09984eu: goto P_0c09984e;
case 0x0c099850u: goto P_0c099850;
case 0x0c099852u: goto P_0c099852;
case 0x0c099854u: goto P_0c099854;
case 0x0c099856u: goto P_0c099856;
case 0x0c099858u: goto P_0c099858;
case 0x0c09985au: goto P_0c09985a;
case 0x0c09985cu: goto P_0c09985c;
case 0x0c09985eu: goto P_0c09985e;
case 0x0c099860u: goto P_0c099860;
case 0x0c099862u: goto P_0c099862;
case 0x0c099864u: goto P_0c099864;
case 0x0c099866u: goto P_0c099866;
case 0x0c099868u: goto P_0c099868;
case 0x0c09986au: goto P_0c09986a;
case 0x0c09986cu: goto P_0c09986c;
case 0x0c09986eu: goto P_0c09986e;
case 0x0c099870u: goto P_0c099870;
case 0x0c099872u: goto P_0c099872;
case 0x0c099874u: goto P_0c099874;
case 0x0c099876u: goto P_0c099876;
case 0x0c099878u: goto P_0c099878;
case 0x0c09987au: goto P_0c09987a;
case 0x0c09987cu: goto P_0c09987c;
case 0x0c09987eu: goto P_0c09987e;
case 0x0c099880u: goto P_0c099880;
case 0x0c099882u: goto P_0c099882;
case 0x0c099884u: goto P_0c099884;
case 0x0c099886u: goto P_0c099886;
case 0x0c099888u: goto P_0c099888;
case 0x0c09988au: goto P_0c09988a;
case 0x0c09988cu: goto P_0c09988c;
case 0x0c09988eu: goto P_0c09988e;
case 0x0c099890u: goto P_0c099890;
case 0x0c099892u: goto P_0c099892;
case 0x0c099894u: goto P_0c099894;
case 0x0c099896u: goto P_0c099896;
case 0x0c099898u: goto P_0c099898;
case 0x0c09989au: goto P_0c09989a;
case 0x0c09989cu: goto P_0c09989c;
case 0x0c09989eu: goto P_0c09989e;
case 0x0c0998a0u: goto P_0c0998a0;
case 0x0c0998a2u: goto P_0c0998a2;
case 0x0c0998a4u: goto P_0c0998a4;
case 0x0c0998a6u: goto P_0c0998a6;
case 0x0c0998a8u: goto P_0c0998a8;
case 0x0c0998aau: goto P_0c0998aa;
case 0x0c0998acu: goto P_0c0998ac;
case 0x0c0998aeu: goto P_0c0998ae;
case 0x0c0998b0u: goto P_0c0998b0;
case 0x0c0998b2u: goto P_0c0998b2;
case 0x0c0998b4u: goto P_0c0998b4;
case 0x0c0998b6u: goto P_0c0998b6;
case 0x0c0998b8u: goto P_0c0998b8;
case 0x0c0998bau: goto P_0c0998ba;
case 0x0c0998bcu: goto P_0c0998bc;
case 0x0c0998beu: goto P_0c0998be;
case 0x0c0998c0u: goto P_0c0998c0;
case 0x0c0998c2u: goto P_0c0998c2;
case 0x0c0998c4u: goto P_0c0998c4;
case 0x0c0998c6u: goto P_0c0998c6;
case 0x0c0998c8u: goto P_0c0998c8;
case 0x0c0998cau: goto P_0c0998ca;
case 0x0c099910u: goto P_0c099910;
case 0x0c099912u: goto P_0c099912;
case 0x0c099914u: goto P_0c099914;
case 0x0c099916u: goto P_0c099916;
case 0x0c099918u: goto P_0c099918;
case 0x0c09991au: goto P_0c09991a;
case 0x0c09991cu: goto P_0c09991c;
case 0x0c09991eu: goto P_0c09991e;
case 0x0c099920u: goto P_0c099920;
case 0x0c099922u: goto P_0c099922;
case 0x0c099924u: goto P_0c099924;
case 0x0c099926u: goto P_0c099926;
case 0x0c099928u: goto P_0c099928;
case 0x0c09992au: goto P_0c09992a;
case 0x0c09992cu: goto P_0c09992c;
case 0x0c09992eu: goto P_0c09992e;
case 0x0c099930u: goto P_0c099930;
case 0x0c099932u: goto P_0c099932;
case 0x0c099934u: goto P_0c099934;
case 0x0c099936u: goto P_0c099936;
case 0x0c099938u: goto P_0c099938;
case 0x0c09993au: goto P_0c09993a;
case 0x0c09993cu: goto P_0c09993c;
case 0x0c09993eu: goto P_0c09993e;
case 0x0c099940u: goto P_0c099940;
case 0x0c099942u: goto P_0c099942;
case 0x0c099944u: goto P_0c099944;
case 0x0c099946u: goto P_0c099946;
case 0x0c099948u: goto P_0c099948;
case 0x0c09994au: goto P_0c09994a;
case 0x0c09994cu: goto P_0c09994c;
case 0x0c09994eu: goto P_0c09994e;
case 0x0c099950u: goto P_0c099950;
case 0x0c099952u: goto P_0c099952;
case 0x0c099954u: goto P_0c099954;
case 0x0c099956u: goto P_0c099956;
case 0x0c099958u: goto P_0c099958;
case 0x0c09995au: goto P_0c09995a;
case 0x0c09995cu: goto P_0c09995c;
case 0x0c09995eu: goto P_0c09995e;
case 0x0c099960u: goto P_0c099960;
case 0x0c099962u: goto P_0c099962;
case 0x0c099964u: goto P_0c099964;
case 0x0c099966u: goto P_0c099966;
case 0x0c099968u: goto P_0c099968;
case 0x0c09996au: goto P_0c09996a;
case 0x0c09996cu: goto P_0c09996c;
case 0x0c09996eu: goto P_0c09996e;
case 0x0c099970u: goto P_0c099970;
case 0x0c099972u: goto P_0c099972;
case 0x0c099974u: goto P_0c099974;
case 0x0c099976u: goto P_0c099976;
case 0x0c099978u: goto P_0c099978;
case 0x0c09997au: goto P_0c09997a;
case 0x0c09997cu: goto P_0c09997c;
case 0x0c09997eu: goto P_0c09997e;
case 0x0c099980u: goto P_0c099980;
case 0x0c099982u: goto P_0c099982;
case 0x0c099984u: goto P_0c099984;
case 0x0c099986u: goto P_0c099986;
case 0x0c099988u: goto P_0c099988;
case 0x0c09998au: goto P_0c09998a;
case 0x0c09998cu: goto P_0c09998c;
case 0x0c09998eu: goto P_0c09998e;
case 0x0c099990u: goto P_0c099990;
case 0x0c099992u: goto P_0c099992;
case 0x0c099994u: goto P_0c099994;
case 0x0c099996u: goto P_0c099996;
case 0x0c099998u: goto P_0c099998;
case 0x0c09999au: goto P_0c09999a;
case 0x0c09999cu: goto P_0c09999c;
case 0x0c09999eu: goto P_0c09999e;
case 0x0c0999a0u: goto P_0c0999a0;
case 0x0c0999a2u: goto P_0c0999a2;
case 0x0c0999a4u: goto P_0c0999a4;
case 0x0c0999a6u: goto P_0c0999a6;
case 0x0c0999a8u: goto P_0c0999a8;
case 0x0c0999aau: goto P_0c0999aa;
case 0x0c0999acu: goto P_0c0999ac;
case 0x0c0999aeu: goto P_0c0999ae;
case 0x0c0999b0u: goto P_0c0999b0;
case 0x0c0999b2u: goto P_0c0999b2;
case 0x0c0999b4u: goto P_0c0999b4;
case 0x0c0999b6u: goto P_0c0999b6;
case 0x0c0999b8u: goto P_0c0999b8;
case 0x0c0999bau: goto P_0c0999ba;
case 0x0c0999bcu: goto P_0c0999bc;
case 0x0c0999beu: goto P_0c0999be;
case 0x0c0999c0u: goto P_0c0999c0;
case 0x0c0999c2u: goto P_0c0999c2;
case 0x0c0999c4u: goto P_0c0999c4;
case 0x0c0999c6u: goto P_0c0999c6;
case 0x0c0999c8u: goto P_0c0999c8;
case 0x0c0999cau: goto P_0c0999ca;
case 0x0c0999ccu: goto P_0c0999cc;
case 0x0c0999ceu: goto P_0c0999ce;
case 0x0c0999d0u: goto P_0c0999d0;
case 0x0c0999d2u: goto P_0c0999d2;
case 0x0c0999d4u: goto P_0c0999d4;
case 0x0c0999d6u: goto P_0c0999d6;
case 0x0c0999d8u: goto P_0c0999d8;
case 0x0c0999dau: goto P_0c0999da;
case 0x0c0999dcu: goto P_0c0999dc;
case 0x0c0999deu: goto P_0c0999de;
case 0x0c0999e0u: goto P_0c0999e0;
case 0x0c0999e2u: goto P_0c0999e2;
case 0x0c0999e4u: goto P_0c0999e4;
case 0x0c0999e6u: goto P_0c0999e6;
case 0x0c0999e8u: goto P_0c0999e8;
case 0x0c0999eau: goto P_0c0999ea;
case 0x0c0999ecu: goto P_0c0999ec;
case 0x0c0999eeu: goto P_0c0999ee;
case 0x0c0999f0u: goto P_0c0999f0;
case 0x0c0999f2u: goto P_0c0999f2;
case 0x0c0999f4u: goto P_0c0999f4;
case 0x0c0999f6u: goto P_0c0999f6;
case 0x0c0999f8u: goto P_0c0999f8;
case 0x0c0999fau: goto P_0c0999fa;
case 0x0c099a18u: goto P_0c099a18;
case 0x0c099a1au: goto P_0c099a1a;
case 0x0c099a1cu: goto P_0c099a1c;
case 0x0c099a1eu: goto P_0c099a1e;
case 0x0c099a20u: goto P_0c099a20;
case 0x0c099a22u: goto P_0c099a22;
case 0x0c099a24u: goto P_0c099a24;
case 0x0c099a26u: goto P_0c099a26;
case 0x0c099a28u: goto P_0c099a28;
case 0x0c099a2au: goto P_0c099a2a;
case 0x0c099a2cu: goto P_0c099a2c;
case 0x0c099a2eu: goto P_0c099a2e;
case 0x0c099a30u: goto P_0c099a30;
case 0x0c099a32u: goto P_0c099a32;
case 0x0c099a34u: goto P_0c099a34;
case 0x0c099a36u: goto P_0c099a36;
case 0x0c099a38u: goto P_0c099a38;
case 0x0c099a3au: goto P_0c099a3a;
case 0x0c099a3cu: goto P_0c099a3c;
case 0x0c099a3eu: goto P_0c099a3e;
case 0x0c099a40u: goto P_0c099a40;
case 0x0c099a42u: goto P_0c099a42;
case 0x0c099a44u: goto P_0c099a44;
case 0x0c099a46u: goto P_0c099a46;
case 0x0c099a48u: goto P_0c099a48;
case 0x0c099a4au: goto P_0c099a4a;
case 0x0c099a4cu: goto P_0c099a4c;
case 0x0c099a4eu: goto P_0c099a4e;
case 0x0c099a50u: goto P_0c099a50;
case 0x0c099a52u: goto P_0c099a52;
case 0x0c099a54u: goto P_0c099a54;
case 0x0c099a56u: goto P_0c099a56;
case 0x0c099a58u: goto P_0c099a58;
case 0x0c099a5au: goto P_0c099a5a;
case 0x0c099a5cu: goto P_0c099a5c;
case 0x0c099a5eu: goto P_0c099a5e;
case 0x0c099a60u: goto P_0c099a60;
case 0x0c099a62u: goto P_0c099a62;
case 0x0c099a64u: goto P_0c099a64;
case 0x0c099a66u: goto P_0c099a66;
case 0x0c099a68u: goto P_0c099a68;
case 0x0c099a6au: goto P_0c099a6a;
case 0x0c099a6cu: goto P_0c099a6c;
case 0x0c099a6eu: goto P_0c099a6e;
case 0x0c099a70u: goto P_0c099a70;
case 0x0c099a72u: goto P_0c099a72;
case 0x0c099a74u: goto P_0c099a74;
case 0x0c099a76u: goto P_0c099a76;
case 0x0c099a78u: goto P_0c099a78;
case 0x0c099a7au: goto P_0c099a7a;
case 0x0c099a7cu: goto P_0c099a7c;
case 0x0c099a7eu: goto P_0c099a7e;
case 0x0c099a80u: goto P_0c099a80;
case 0x0c099a82u: goto P_0c099a82;
case 0x0c099a84u: goto P_0c099a84;
case 0x0c099a86u: goto P_0c099a86;
case 0x0c099a88u: goto P_0c099a88;
case 0x0c099a8au: goto P_0c099a8a;
case 0x0c099a8cu: goto P_0c099a8c;
case 0x0c099a8eu: goto P_0c099a8e;
case 0x0c099a90u: goto P_0c099a90;
case 0x0c099a92u: goto P_0c099a92;
case 0x0c099a94u: goto P_0c099a94;
case 0x0c099a96u: goto P_0c099a96;
case 0x0c099a98u: goto P_0c099a98;
case 0x0c099a9au: goto P_0c099a9a;
case 0x0c099a9cu: goto P_0c099a9c;
case 0x0c099a9eu: goto P_0c099a9e;
case 0x0c099aa0u: goto P_0c099aa0;
case 0x0c099aa2u: goto P_0c099aa2;
case 0x0c099aa4u: goto P_0c099aa4;
case 0x0c099aa6u: goto P_0c099aa6;
case 0x0c099aa8u: goto P_0c099aa8;
case 0x0c099aaau: goto P_0c099aaa;
case 0x0c099aacu: goto P_0c099aac;
case 0x0c099aaeu: goto P_0c099aae;
case 0x0c099ab0u: goto P_0c099ab0;
case 0x0c099ab2u: goto P_0c099ab2;
case 0x0c099ab4u: goto P_0c099ab4;
case 0x0c099ab6u: goto P_0c099ab6;
case 0x0c099ab8u: goto P_0c099ab8;
case 0x0c099abau: goto P_0c099aba;
case 0x0c099abcu: goto P_0c099abc;
case 0x0c099abeu: goto P_0c099abe;
case 0x0c099ac0u: goto P_0c099ac0;
case 0x0c099ac2u: goto P_0c099ac2;
case 0x0c099ac4u: goto P_0c099ac4;
case 0x0c099ac6u: goto P_0c099ac6;
case 0x0c099ac8u: goto P_0c099ac8;
case 0x0c099acau: goto P_0c099aca;
case 0x0c099accu: goto P_0c099acc;
case 0x0c099aceu: goto P_0c099ace;
case 0x0c099ad0u: goto P_0c099ad0;
case 0x0c099ad2u: goto P_0c099ad2;
case 0x0c099ad4u: goto P_0c099ad4;
case 0x0c099ad6u: goto P_0c099ad6;
case 0x0c099ad8u: goto P_0c099ad8;
case 0x0c099adau: goto P_0c099ada;
case 0x0c099adcu: goto P_0c099adc;
case 0x0c099adeu: goto P_0c099ade;
case 0x0c099ae0u: goto P_0c099ae0;
case 0x0c099ae2u: goto P_0c099ae2;
case 0x0c099ae4u: goto P_0c099ae4;
case 0x0c099ae6u: goto P_0c099ae6;
case 0x0c099ae8u: goto P_0c099ae8;
case 0x0c099aeau: goto P_0c099aea;
case 0x0c099aecu: goto P_0c099aec;
case 0x0c099aeeu: goto P_0c099aee;
case 0x0c099af0u: goto P_0c099af0;
case 0x0c099af2u: goto P_0c099af2;
case 0x0c099af4u: goto P_0c099af4;
case 0x0c099af6u: goto P_0c099af6;
case 0x0c099af8u: goto P_0c099af8;
case 0x0c099afau: goto P_0c099afa;
case 0x0c099afcu: goto P_0c099afc;
case 0x0c099afeu: goto P_0c099afe;
case 0x0c099b00u: goto P_0c099b00;
case 0x0c099b02u: goto P_0c099b02;
case 0x0c099b04u: goto P_0c099b04;
case 0x0c099b06u: goto P_0c099b06;
case 0x0c099b08u: goto P_0c099b08;
case 0x0c099b0au: goto P_0c099b0a;
case 0x0c099b0cu: goto P_0c099b0c;
case 0x0c099b0eu: goto P_0c099b0e;
case 0x0c099b10u: goto P_0c099b10;
case 0x0c099b12u: goto P_0c099b12;
case 0x0c099b14u: goto P_0c099b14;
case 0x0c099b16u: goto P_0c099b16;
case 0x0c099b18u: goto P_0c099b18;
case 0x0c099b1au: goto P_0c099b1a;
case 0x0c099b1cu: goto P_0c099b1c;
case 0x0c099b1eu: goto P_0c099b1e;
case 0x0c099b20u: goto P_0c099b20;
case 0x0c099b22u: goto P_0c099b22;
case 0x0c099b24u: goto P_0c099b24;
case 0x0c099b26u: goto P_0c099b26;
case 0x0c099b28u: goto P_0c099b28;
case 0x0c099b2au: goto P_0c099b2a;
case 0x0c099b2cu: goto P_0c099b2c;
case 0x0c099b2eu: goto P_0c099b2e;
case 0x0c099b30u: goto P_0c099b30;
case 0x0c099b32u: goto P_0c099b32;
case 0x0c099b34u: goto P_0c099b34;
case 0x0c099b36u: goto P_0c099b36;
case 0x0c099b38u: goto P_0c099b38;
case 0x0c099b3au: goto P_0c099b3a;
case 0x0c099b3cu: goto P_0c099b3c;
case 0x0c099b3eu: goto P_0c099b3e;
case 0x0c099b40u: goto P_0c099b40;
case 0x0c099b42u: goto P_0c099b42;
case 0x0c099b44u: goto P_0c099b44;
case 0x0c099b46u: goto P_0c099b46;
case 0x0c099b48u: goto P_0c099b48;
case 0x0c099b4au: goto P_0c099b4a;
case 0x0c099b4cu: goto P_0c099b4c;
case 0x0c099b4eu: goto P_0c099b4e;
case 0x0c099b50u: goto P_0c099b50;
case 0x0c099b52u: goto P_0c099b52;
case 0x0c099b54u: goto P_0c099b54;
case 0x0c099b56u: goto P_0c099b56;
case 0x0c099b58u: goto P_0c099b58;
case 0x0c099b5au: goto P_0c099b5a;
case 0x0c099b5cu: goto P_0c099b5c;
case 0x0c099b5eu: goto P_0c099b5e;
case 0x0c099b60u: goto P_0c099b60;
case 0x0c099b62u: goto P_0c099b62;
case 0x0c099b64u: goto P_0c099b64;
case 0x0c099b66u: goto P_0c099b66;
case 0x0c099b68u: goto P_0c099b68;
case 0x0c099b6au: goto P_0c099b6a;
case 0x0c099b6cu: goto P_0c099b6c;
case 0x0c099b6eu: goto P_0c099b6e;
case 0x0c099b70u: goto P_0c099b70;
case 0x0c099b9cu: goto P_0c099b9c;
case 0x0c099b9eu: goto P_0c099b9e;
case 0x0c099ba0u: goto P_0c099ba0;
case 0x0c099ba2u: goto P_0c099ba2;
case 0x0c099ba4u: goto P_0c099ba4;
case 0x0c099ba6u: goto P_0c099ba6;
case 0x0c099ba8u: goto P_0c099ba8;
case 0x0c099baau: goto P_0c099baa;
case 0x0c099bacu: goto P_0c099bac;
case 0x0c099baeu: goto P_0c099bae;
case 0x0c099bb0u: goto P_0c099bb0;
case 0x0c099bb2u: goto P_0c099bb2;
case 0x0c099bb4u: goto P_0c099bb4;
case 0x0c099bb6u: goto P_0c099bb6;
case 0x0c099bb8u: goto P_0c099bb8;
case 0x0c099bbau: goto P_0c099bba;
case 0x0c099bbcu: goto P_0c099bbc;
case 0x0c099bbeu: goto P_0c099bbe;
case 0x0c099bc0u: goto P_0c099bc0;
case 0x0c099bc2u: goto P_0c099bc2;
case 0x0c099bc4u: goto P_0c099bc4;
case 0x0c099bc6u: goto P_0c099bc6;
case 0x0c099bc8u: goto P_0c099bc8;
case 0x0c099bcau: goto P_0c099bca;
case 0x0c099bccu: goto P_0c099bcc;
case 0x0c099bceu: goto P_0c099bce;
case 0x0c099bd0u: goto P_0c099bd0;
case 0x0c099bd2u: goto P_0c099bd2;
case 0x0c099bd4u: goto P_0c099bd4;
case 0x0c099bd6u: goto P_0c099bd6;
case 0x0c099bd8u: goto P_0c099bd8;
case 0x0c099bdau: goto P_0c099bda;
case 0x0c099bdcu: goto P_0c099bdc;
case 0x0c099bdeu: goto P_0c099bde;
case 0x0c099be0u: goto P_0c099be0;
case 0x0c099be2u: goto P_0c099be2;
case 0x0c099be4u: goto P_0c099be4;
case 0x0c099be6u: goto P_0c099be6;
case 0x0c099be8u: goto P_0c099be8;
case 0x0c099beau: goto P_0c099bea;
case 0x0c099becu: goto P_0c099bec;
case 0x0c099beeu: goto P_0c099bee;
case 0x0c099bf0u: goto P_0c099bf0;
case 0x0c099bf2u: goto P_0c099bf2;
case 0x0c099bf4u: goto P_0c099bf4;
case 0x0c099bf6u: goto P_0c099bf6;
case 0x0c099bf8u: goto P_0c099bf8;
case 0x0c099bfau: goto P_0c099bfa;
case 0x0c099bfcu: goto P_0c099bfc;
case 0x0c099bfeu: goto P_0c099bfe;
case 0x0c099c00u: goto P_0c099c00;
case 0x0c099c02u: goto P_0c099c02;
case 0x0c099c04u: goto P_0c099c04;
case 0x0c099c06u: goto P_0c099c06;
case 0x0c099c08u: goto P_0c099c08;
case 0x0c099c0au: goto P_0c099c0a;
case 0x0c099c0cu: goto P_0c099c0c;
case 0x0c099c0eu: goto P_0c099c0e;
case 0x0c099c10u: goto P_0c099c10;
case 0x0c099c12u: goto P_0c099c12;
case 0x0c099c14u: goto P_0c099c14;
case 0x0c099c16u: goto P_0c099c16;
case 0x0c099c18u: goto P_0c099c18;
case 0x0c099c1au: goto P_0c099c1a;
case 0x0c099c1cu: goto P_0c099c1c;
case 0x0c099c1eu: goto P_0c099c1e;
case 0x0c099c20u: goto P_0c099c20;
case 0x0c099c22u: goto P_0c099c22;
case 0x0c099c24u: goto P_0c099c24;
case 0x0c099c26u: goto P_0c099c26;
case 0x0c099c28u: goto P_0c099c28;
case 0x0c099c2au: goto P_0c099c2a;
case 0x0c099c2cu: goto P_0c099c2c;
case 0x0c099c2eu: goto P_0c099c2e;
case 0x0c099c30u: goto P_0c099c30;
case 0x0c099c32u: goto P_0c099c32;
case 0x0c099c34u: goto P_0c099c34;
case 0x0c099c36u: goto P_0c099c36;
case 0x0c099c38u: goto P_0c099c38;
case 0x0c099c3au: goto P_0c099c3a;
case 0x0c099c3cu: goto P_0c099c3c;
case 0x0c099c3eu: goto P_0c099c3e;
case 0x0c099c40u: goto P_0c099c40;
case 0x0c099c42u: goto P_0c099c42;
case 0x0c099c44u: goto P_0c099c44;
case 0x0c099c46u: goto P_0c099c46;
case 0x0c099c48u: goto P_0c099c48;
case 0x0c099c4au: goto P_0c099c4a;
case 0x0c099c4cu: goto P_0c099c4c;
case 0x0c099c4eu: goto P_0c099c4e;
case 0x0c099c50u: goto P_0c099c50;
case 0x0c099c52u: goto P_0c099c52;
case 0x0c099c54u: goto P_0c099c54;
case 0x0c099c56u: goto P_0c099c56;
case 0x0c099c58u: goto P_0c099c58;
case 0x0c099c5au: goto P_0c099c5a;
case 0x0c099c5cu: goto P_0c099c5c;
case 0x0c099c5eu: goto P_0c099c5e;
case 0x0c099c60u: goto P_0c099c60;
case 0x0c099c62u: goto P_0c099c62;
case 0x0c099c64u: goto P_0c099c64;
case 0x0c099c66u: goto P_0c099c66;
case 0x0c099c68u: goto P_0c099c68;
case 0x0c099c6au: goto P_0c099c6a;
case 0x0c099c6cu: goto P_0c099c6c;
case 0x0c099c6eu: goto P_0c099c6e;
case 0x0c099c70u: goto P_0c099c70;
case 0x0c099c72u: goto P_0c099c72;
case 0x0c099c74u: goto P_0c099c74;
case 0x0c099c76u: goto P_0c099c76;
case 0x0c099c78u: goto P_0c099c78;
case 0x0c099c7au: goto P_0c099c7a;
case 0x0c099c7cu: goto P_0c099c7c;
case 0x0c099c7eu: goto P_0c099c7e;
case 0x0c099c80u: goto P_0c099c80;
case 0x0c099c82u: goto P_0c099c82;
case 0x0c099cb0u: goto P_0c099cb0;
case 0x0c099cb2u: goto P_0c099cb2;
case 0x0c099cb4u: goto P_0c099cb4;
case 0x0c099cb6u: goto P_0c099cb6;
case 0x0c099cb8u: goto P_0c099cb8;
case 0x0c099cbau: goto P_0c099cba;
case 0x0c099cbcu: goto P_0c099cbc;
case 0x0c099cbeu: goto P_0c099cbe;
case 0x0c099cc0u: goto P_0c099cc0;
case 0x0c099cc2u: goto P_0c099cc2;
case 0x0c099cc4u: goto P_0c099cc4;
case 0x0c099cc6u: goto P_0c099cc6;
case 0x0c099cc8u: goto P_0c099cc8;
case 0x0c099ccau: goto P_0c099cca;
case 0x0c099cccu: goto P_0c099ccc;
case 0x0c099cceu: goto P_0c099cce;
case 0x0c099cd0u: goto P_0c099cd0;
case 0x0c099cd2u: goto P_0c099cd2;
case 0x0c099cd4u: goto P_0c099cd4;
case 0x0c099cd6u: goto P_0c099cd6;
case 0x0c099cd8u: goto P_0c099cd8;
case 0x0c099cdau: goto P_0c099cda;
case 0x0c099cdcu: goto P_0c099cdc;
case 0x0c099cdeu: goto P_0c099cde;
case 0x0c099ce0u: goto P_0c099ce0;
case 0x0c099ce2u: goto P_0c099ce2;
case 0x0c099ce4u: goto P_0c099ce4;
case 0x0c099ce6u: goto P_0c099ce6;
case 0x0c099ce8u: goto P_0c099ce8;
case 0x0c099ceau: goto P_0c099cea;
case 0x0c099cecu: goto P_0c099cec;
case 0x0c099ceeu: goto P_0c099cee;
case 0x0c099cf0u: goto P_0c099cf0;
case 0x0c099cf2u: goto P_0c099cf2;
case 0x0c099cf4u: goto P_0c099cf4;
case 0x0c099cf6u: goto P_0c099cf6;
case 0x0c099cf8u: goto P_0c099cf8;
case 0x0c099cfau: goto P_0c099cfa;
case 0x0c099cfcu: goto P_0c099cfc;
case 0x0c099cfeu: goto P_0c099cfe;
case 0x0c099d00u: goto P_0c099d00;
case 0x0c099d02u: goto P_0c099d02;
case 0x0c099d04u: goto P_0c099d04;
case 0x0c099d06u: goto P_0c099d06;
case 0x0c099d08u: goto P_0c099d08;
case 0x0c099d0au: goto P_0c099d0a;
case 0x0c099d0cu: goto P_0c099d0c;
case 0x0c099d0eu: goto P_0c099d0e;
case 0x0c099d10u: goto P_0c099d10;
case 0x0c099d12u: goto P_0c099d12;
case 0x0c099d14u: goto P_0c099d14;
case 0x0c099d16u: goto P_0c099d16;
case 0x0c099d18u: goto P_0c099d18;
case 0x0c099d1au: goto P_0c099d1a;
case 0x0c099d1cu: goto P_0c099d1c;
case 0x0c099d1eu: goto P_0c099d1e;
case 0x0c099d20u: goto P_0c099d20;
case 0x0c099d22u: goto P_0c099d22;
case 0x0c099d24u: goto P_0c099d24;
case 0x0c099d26u: goto P_0c099d26;
case 0x0c099d28u: goto P_0c099d28;
case 0x0c099d2au: goto P_0c099d2a;
case 0x0c099d2cu: goto P_0c099d2c;
case 0x0c099d2eu: goto P_0c099d2e;
case 0x0c099d30u: goto P_0c099d30;
case 0x0c099d32u: goto P_0c099d32;
case 0x0c099d34u: goto P_0c099d34;
case 0x0c099d36u: goto P_0c099d36;
case 0x0c099d38u: goto P_0c099d38;
case 0x0c099d3au: goto P_0c099d3a;
case 0x0c099d3cu: goto P_0c099d3c;
case 0x0c099d3eu: goto P_0c099d3e;
case 0x0c099d40u: goto P_0c099d40;
case 0x0c099d42u: goto P_0c099d42;
case 0x0c099d44u: goto P_0c099d44;
case 0x0c099d46u: goto P_0c099d46;
case 0x0c099d48u: goto P_0c099d48;
case 0x0c099d4au: goto P_0c099d4a;
case 0x0c099d4cu: goto P_0c099d4c;
case 0x0c099d4eu: goto P_0c099d4e;
case 0x0c099d50u: goto P_0c099d50;
case 0x0c099d52u: goto P_0c099d52;
case 0x0c099d54u: goto P_0c099d54;
case 0x0c099d56u: goto P_0c099d56;
case 0x0c099d58u: goto P_0c099d58;
case 0x0c099d5au: goto P_0c099d5a;
case 0x0c099d5cu: goto P_0c099d5c;
case 0x0c099d5eu: goto P_0c099d5e;
case 0x0c099d60u: goto P_0c099d60;
case 0x0c0c61a8u: goto P_0c0c61a8;
case 0x0c0c61aau: goto P_0c0c61aa;
case 0x0c0c61acu: goto P_0c0c61ac;
case 0x0c0c61aeu: goto P_0c0c61ae;
case 0x0c0c61b0u: goto P_0c0c61b0;
case 0x0c0c61b2u: goto P_0c0c61b2;
case 0x0c0c61b4u: goto P_0c0c61b4;
case 0x0c0c61b6u: goto P_0c0c61b6;
case 0x0c0c61b8u: goto P_0c0c61b8;
case 0x0c0c61bau: goto P_0c0c61ba;
case 0x0c0c61bcu: goto P_0c0c61bc;
case 0x0c0c61beu: goto P_0c0c61be;
case 0x0c0c61c0u: goto P_0c0c61c0;
case 0x0c0c61c2u: goto P_0c0c61c2;
case 0x0c0c61c4u: goto P_0c0c61c4;
case 0x0c0c61c6u: goto P_0c0c61c6;
case 0x0c0c61c8u: goto P_0c0c61c8;
case 0x0c0c61cau: goto P_0c0c61ca;
case 0x0c0c61ccu: goto P_0c0c61cc;
case 0x0c0c61ceu: goto P_0c0c61ce;
case 0x0c0c61d0u: goto P_0c0c61d0;
case 0x0c0c61d2u: goto P_0c0c61d2;
case 0x0c0c61d4u: goto P_0c0c61d4;
case 0x0c0c61d6u: goto P_0c0c61d6;
case 0x0c0c61d8u: goto P_0c0c61d8;
case 0x0c0c61dau: goto P_0c0c61da;
case 0x0c0c61dcu: goto P_0c0c61dc;
case 0x0c0c61deu: goto P_0c0c61de;
case 0x0c0c61e0u: goto P_0c0c61e0;
case 0x0c0c61e2u: goto P_0c0c61e2;
case 0x0c0c61e4u: goto P_0c0c61e4;
case 0x0c0c61e6u: goto P_0c0c61e6;
case 0x0c0c61e8u: goto P_0c0c61e8;
case 0x0c0c61eau: goto P_0c0c61ea;
case 0x0c0c61ecu: goto P_0c0c61ec;
case 0x0c0c61eeu: goto P_0c0c61ee;
case 0x0c0c61f0u: goto P_0c0c61f0;
case 0x0c0c61f2u: goto P_0c0c61f2;
case 0x0c0c61f4u: goto P_0c0c61f4;
case 0x0c0c61f6u: goto P_0c0c61f6;
case 0x0c0c61f8u: goto P_0c0c61f8;
case 0x0c0c61fau: goto P_0c0c61fa;
case 0x0c0c61fcu: goto P_0c0c61fc;
case 0x0c0c61feu: goto P_0c0c61fe;
case 0x0c0c6200u: goto P_0c0c6200;
case 0x0c0c6202u: goto P_0c0c6202;
case 0x0c0c6204u: goto P_0c0c6204;
case 0x0c0c623eu: goto P_0c0c623e;
case 0x0c0c6240u: goto P_0c0c6240;
case 0x0c0c99cau: goto P_0c0c99ca;
case 0x0c0c99ccu: goto P_0c0c99cc;
case 0x0c0c99ceu: goto P_0c0c99ce;
case 0x0c0c99d0u: goto P_0c0c99d0;
case 0x0c0c99d2u: goto P_0c0c99d2;
case 0x0c0c99d4u: goto P_0c0c99d4;
case 0x0c0c99d6u: goto P_0c0c99d6;
case 0x0c0c99d8u: goto P_0c0c99d8;
case 0x0c0c99dau: goto P_0c0c99da;
case 0x0c0c99dcu: goto P_0c0c99dc;
case 0x0c0c99deu: goto P_0c0c99de;
case 0x0c0c99e0u: goto P_0c0c99e0;
case 0x0c0c99e2u: goto P_0c0c99e2;
case 0x0c0c99e4u: goto P_0c0c99e4;
case 0x0c0c99e6u: goto P_0c0c99e6;
case 0x0c0c99e8u: goto P_0c0c99e8;
case 0x0c0c99eau: goto P_0c0c99ea;
case 0x0c0c99ecu: goto P_0c0c99ec;
case 0x0c0c99eeu: goto P_0c0c99ee;
case 0x0c0c99f0u: goto P_0c0c99f0;
case 0x0c0c99f2u: goto P_0c0c99f2;
case 0x0c0c99f4u: goto P_0c0c99f4;
case 0x0c0c99f6u: goto P_0c0c99f6;
case 0x0c0c99f8u: goto P_0c0c99f8;
case 0x0c0c99fau: goto P_0c0c99fa;
case 0x0c0c99fcu: goto P_0c0c99fc;
case 0x0c0c9a7au: goto P_0c0c9a7a;
case 0x0c0c9a7cu: goto P_0c0c9a7c;
case 0x0c0c9a7eu: goto P_0c0c9a7e;
case 0x0c0c9a80u: goto P_0c0c9a80;
case 0x0c0c9a82u: goto P_0c0c9a82;
case 0x0c0c9a84u: goto P_0c0c9a84;
case 0x0c0c9a86u: goto P_0c0c9a86;
case 0x0c0c9a88u: goto P_0c0c9a88;
case 0x0c0c9a8au: goto P_0c0c9a8a;
case 0x0c0c9a8cu: goto P_0c0c9a8c;
case 0x0c0c9a8eu: goto P_0c0c9a8e;
case 0x0c0c9a90u: goto P_0c0c9a90;
case 0x0c0c9a92u: goto P_0c0c9a92;
case 0x0c0c9a94u: goto P_0c0c9a94;
case 0x0c0c9a96u: goto P_0c0c9a96;
case 0x0c0c9a98u: goto P_0c0c9a98;
case 0x0c0c9a9au: goto P_0c0c9a9a;
case 0x0c0c9a9cu: goto P_0c0c9a9c;
case 0x0c0c9ad0u: goto P_0c0c9ad0;
case 0x0c0c9ad2u: goto P_0c0c9ad2;
case 0x0c0c9ad4u: goto P_0c0c9ad4;
case 0x0c0c9ad6u: goto P_0c0c9ad6;
case 0x0c0c9ad8u: goto P_0c0c9ad8;
case 0x0c0c9adau: goto P_0c0c9ada;
case 0x0c0c9adcu: goto P_0c0c9adc;
case 0x0c0c9adeu: goto P_0c0c9ade;
case 0x0c0c9ae0u: goto P_0c0c9ae0;
case 0x0c0c9ae2u: goto P_0c0c9ae2;
case 0x0c0c9ae4u: goto P_0c0c9ae4;
case 0x0c0c9ae6u: goto P_0c0c9ae6;
case 0x0c0c9ae8u: goto P_0c0c9ae8;
case 0x0c0c9aeau: goto P_0c0c9aea;
case 0x0c0c9aecu: goto P_0c0c9aec;
case 0x0c0c9aeeu: goto P_0c0c9aee;
case 0x0c0c9af0u: goto P_0c0c9af0;
case 0x0c0c9af2u: goto P_0c0c9af2;
case 0x0c0c9af4u: goto P_0c0c9af4;
case 0x0c0c9af6u: goto P_0c0c9af6;
case 0x0c0c9af8u: goto P_0c0c9af8;
case 0x0c0c9afau: goto P_0c0c9afa;
case 0x0c0c9afcu: goto P_0c0c9afc;
case 0x0c0c9afeu: goto P_0c0c9afe;
case 0x0c0c9b00u: goto P_0c0c9b00;
case 0x0c0c9b02u: goto P_0c0c9b02;
case 0x0c0c9b04u: goto P_0c0c9b04;
case 0x0c0c9b06u: goto P_0c0c9b06;
case 0x0c0c9b08u: goto P_0c0c9b08;
case 0x0c0c9b0au: goto P_0c0c9b0a;
case 0x0c0c9b0cu: goto P_0c0c9b0c;
case 0x0c0c9b0eu: goto P_0c0c9b0e;
case 0x0c0c9b10u: goto P_0c0c9b10;
case 0x0c0c9b12u: goto P_0c0c9b12;
case 0x0c0c9b14u: goto P_0c0c9b14;
case 0x0c0c9b16u: goto P_0c0c9b16;
case 0x0c0c9b18u: goto P_0c0c9b18;
case 0x0c0c9b1au: goto P_0c0c9b1a;
case 0x0c0c9b1cu: goto P_0c0c9b1c;
case 0x0c0c9b1eu: goto P_0c0c9b1e;
case 0x0c0c9b20u: goto P_0c0c9b20;
case 0x0c0c9b22u: goto P_0c0c9b22;
case 0x0c0c9b24u: goto P_0c0c9b24;
case 0x0c0c9b26u: goto P_0c0c9b26;
case 0x0c0c9b28u: goto P_0c0c9b28;
case 0x0c0c9b2au: goto P_0c0c9b2a;
case 0x0c0c9b2cu: goto P_0c0c9b2c;
case 0x0c0ca05cu: goto P_0c0ca05c;
case 0x0c0ca05eu: goto P_0c0ca05e;
case 0x0c0ca060u: goto P_0c0ca060;
case 0x0c0ca062u: goto P_0c0ca062;
case 0x0c0ca064u: goto P_0c0ca064;
case 0x0c0ca066u: goto P_0c0ca066;
case 0x0c0ca068u: goto P_0c0ca068;
case 0x0c0ca06au: goto P_0c0ca06a;
case 0x0c0ca06cu: goto P_0c0ca06c;
default: return vf3_matrix_family(target,s,ram);
}
P_0c040b7c: /* original 2fe6, guest PC 0x0c040b7c */
if(!s->budget--) { s->failed_pc=0x0c040b7cu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
return vf3_matrix_family(0x0c040b7eu,s,ram);
P_0c08a068: /* original 2fe6, guest PC 0x0c08a068 */
if(!s->budget--) { s->failed_pc=0x0c08a068u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08a06a;
P_0c08a06a: /* original e200, guest PC 0x0c08a06a */
if(!s->budget--) { s->failed_pc=0x0c08a06au; return 0; }
r[2]=0x00000000u;
goto P_0c08a06c;
P_0c08a06c: /* original 2fd6, guest PC 0x0c08a06c */
if(!s->budget--) { s->failed_pc=0x0c08a06cu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08a06e;
P_0c08a06e: /* original 2fc6, guest PC 0x0c08a06e */
if(!s->budget--) { s->failed_pc=0x0c08a06eu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08a070;
P_0c08a070: /* original 2fb6, guest PC 0x0c08a070 */
if(!s->budget--) { s->failed_pc=0x0c08a070u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08a072;
P_0c08a072: /* original fffb, guest PC 0x0c08a072 */
if(!s->budget--) { s->failed_pc=0x0c08a072u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c08a074;
P_0c08a074: /* original d35f, guest PC 0x0c08a074 */
if(!s->budget--) { s->failed_pc=0x0c08a074u; return 0; }
r[3]=read(ram,0x0c08a1f4u,4);
return vf3_matrix_family(0x0c08a076u,s,ram);
P_0c091eb8: /* original 2fd6, guest PC 0x0c091eb8 */
if(!s->budget--) { s->failed_pc=0x0c091eb8u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c091eba;
P_0c091eba: /* original 2fc6, guest PC 0x0c091eba */
if(!s->budget--) { s->failed_pc=0x0c091ebau; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c091ebc;
P_0c091ebc: /* original d123, guest PC 0x0c091ebc */
if(!s->budget--) { s->failed_pc=0x0c091ebcu; return 0; }
r[1]=read(ram,0x0c091f4cu,4);
goto P_0c091ebe;
P_0c091ebe: /* original 7ffc, guest PC 0x0c091ebe */
if(!s->budget--) { s->failed_pc=0x0c091ebeu; return 0; }
r[15]+=0xfffffffcu;
goto P_0c091ec0;
P_0c091ec0: /* original d321, guest PC 0x0c091ec0 */
if(!s->budget--) { s->failed_pc=0x0c091ec0u; return 0; }
r[3]=read(ram,0x0c091f48u,4);
goto P_0c091ec2;
P_0c091ec2: /* original 6212, guest PC 0x0c091ec2 */
if(!s->budget--) { s->failed_pc=0x0c091ec2u; return 0; }
tmp=read(ram,r[1],4);
r[2]=tmp;
goto P_0c091ec4;
P_0c091ec4: /* original 2238, guest PC 0x0c091ec4 */
if(!s->budget--) { s->failed_pc=0x0c091ec4u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c091ec6;
P_0c091ec6: /* original 8b32, guest PC 0x0c091ec6 */
if(!s->budget--) { s->failed_pc=0x0c091ec6u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c091f2e; }
goto P_0c091ec8;
P_0c091ec8: /* original d61d, guest PC 0x0c091ec8 */
if(!s->budget--) { s->failed_pc=0x0c091ec8u; return 0; }
r[6]=read(ram,0x0c091f40u,4);
goto P_0c091eca;
P_0c091eca: /* original 6043, guest PC 0x0c091eca */
if(!s->budget--) { s->failed_pc=0x0c091ecau; return 0; }
r[0]=r[4];
goto P_0c091ecc;
P_0c091ecc: /* original 8801, guest PC 0x0c091ecc */
if(!s->budget--) { s->failed_pc=0x0c091eccu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c091ece;
P_0c091ece: /* original 5564, guest PC 0x0c091ece */
if(!s->budget--) { s->failed_pc=0x0c091eceu; return 0; }
r[5]=read(ram,r[6]+16,4);
goto P_0c091ed0;
P_0c091ed0: /* original 8d01, guest PC 0x0c091ed0 */
if(!s->budget--) { s->failed_pc=0x0c091ed0u; return 0; }
cond=r[17]&1u;
r[6]=read(ram,r[6]+20,4);
if(cond) { goto P_0c091ed6; }
goto P_0c091ed4;
P_0c091ed2: /* original 5665, guest PC 0x0c091ed2 */
if(!s->budget--) { s->failed_pc=0x0c091ed2u; return 0; }
r[6]=read(ram,r[6]+20,4);
goto P_0c091ed4;
P_0c091ed4: /* original 6563, guest PC 0x0c091ed4 */
if(!s->budget--) { s->failed_pc=0x0c091ed4u; return 0; }
r[5]=r[6];
goto P_0c091ed6;
P_0c091ed6: /* original 8454, guest PC 0x0c091ed6 */
if(!s->budget--) { s->failed_pc=0x0c091ed6u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[5]+4,1);
goto P_0c091ed8;
P_0c091ed8: /* original d61a, guest PC 0x0c091ed8 */
if(!s->budget--) { s->failed_pc=0x0c091ed8u; return 0; }
r[6]=read(ram,0x0c091f44u,4);
goto P_0c091eda;
P_0c091eda: /* original 600c, guest PC 0x0c091eda */
if(!s->budget--) { s->failed_pc=0x0c091edau; return 0; }
r[0]=r[0]&255u;
goto P_0c091edc;
P_0c091edc: /* original 6303, guest PC 0x0c091edc */
if(!s->budget--) { s->failed_pc=0x0c091edcu; return 0; }
r[3]=r[0];
goto P_0c091ede;
P_0c091ede: /* original 4000, guest PC 0x0c091ede */
if(!s->budget--) { s->failed_pc=0x0c091edeu; return 0; }
r[17]=(r[17]&~1u)|((r[0]>>31)!=0);
r[0]<<=1;
goto P_0c091ee0;
P_0c091ee0: /* original 303c, guest PC 0x0c091ee0 */
if(!s->budget--) { s->failed_pc=0x0c091ee0u; return 0; }
r[0]+=r[3];
goto P_0c091ee2;
P_0c091ee2: /* original 4008, guest PC 0x0c091ee2 */
if(!s->budget--) { s->failed_pc=0x0c091ee2u; return 0; }
r[0]<<=2;
goto P_0c091ee4;
P_0c091ee4: /* original 4008, guest PC 0x0c091ee4 */
if(!s->budget--) { s->failed_pc=0x0c091ee4u; return 0; }
r[0]<<=2;
goto P_0c091ee6;
P_0c091ee6: /* original 4000, guest PC 0x0c091ee6 */
if(!s->budget--) { s->failed_pc=0x0c091ee6u; return 0; }
r[17]=(r[17]&~1u)|((r[0]>>31)!=0);
r[0]<<=1;
goto P_0c091ee8;
P_0c091ee8: /* original 360c, guest PC 0x0c091ee8 */
if(!s->budget--) { s->failed_pc=0x0c091ee8u; return 0; }
r[6]+=r[0];
goto P_0c091eea;
P_0c091eea: /* original 9026, guest PC 0x0c091eea */
if(!s->budget--) { s->failed_pc=0x0c091eeau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c091f3au,2);
goto P_0c091eec;
P_0c091eec: /* original 6d63, guest PC 0x0c091eec */
if(!s->budget--) { s->failed_pc=0x0c091eecu; return 0; }
r[13]=r[6];
goto P_0c091eee;
P_0c091eee: /* original 7d20, guest PC 0x0c091eee */
if(!s->budget--) { s->failed_pc=0x0c091eeeu; return 0; }
r[13]+=0x00000020u;
goto P_0c091ef0;
P_0c091ef0: /* original 045d, guest PC 0x0c091ef0 */
if(!s->budget--) { s->failed_pc=0x0c091ef0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[5]+r[0],2);
goto P_0c091ef2;
P_0c091ef2: /* original 9023, guest PC 0x0c091ef2 */
if(!s->budget--) { s->failed_pc=0x0c091ef2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c091f3cu,2);
goto P_0c091ef4;
P_0c091ef4: /* original 6743, guest PC 0x0c091ef4 */
if(!s->budget--) { s->failed_pc=0x0c091ef4u; return 0; }
r[7]=r[4];
goto P_0c091ef6;
P_0c091ef6: /* original 0545, guest PC 0x0c091ef6 */
if(!s->budget--) { s->failed_pc=0x0c091ef6u; return 0; }
write(ram,r[5]+r[0],r[4],2);
goto P_0c091ef8;
P_0c091ef8: /* original 9021, guest PC 0x0c091ef8 */
if(!s->budget--) { s->failed_pc=0x0c091ef8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c091f3eu,2);
goto P_0c091efa;
P_0c091efa: /* original 0c5c, guest PC 0x0c091efa */
if(!s->budget--) { s->failed_pc=0x0c091efau; return 0; }
r[12]=(uint32_t)(int32_t)(int8_t)read(ram,r[5]+r[0],1);
goto P_0c091efc;
P_0c091efc: /* original 6063, guest PC 0x0c091efc */
if(!s->budget--) { s->failed_pc=0x0c091efcu; return 0; }
r[0]=r[6];
goto P_0c091efe;
P_0c091efe: /* original 034c, guest PC 0x0c091efe */
if(!s->budget--) { s->failed_pc=0x0c091efeu; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c091f00;
P_0c091f00: /* original 6073, guest PC 0x0c091f00 */
if(!s->budget--) { s->failed_pc=0x0c091f00u; return 0; }
r[0]=r[7];
goto P_0c091f02;
P_0c091f02: /* original 4000, guest PC 0x0c091f02 */
if(!s->budget--) { s->failed_pc=0x0c091f02u; return 0; }
r[17]=(r[17]&~1u)|((r[0]>>31)!=0);
r[0]<<=1;
goto P_0c091f04;
P_0c091f04: /* original 633c, guest PC 0x0c091f04 */
if(!s->budget--) { s->failed_pc=0x0c091f04u; return 0; }
r[3]=r[3]&255u;
goto P_0c091f06;
P_0c091f06: /* original 2f31, guest PC 0x0c091f06 */
if(!s->budget--) { s->failed_pc=0x0c091f06u; return 0; }
write(ram,r[15],r[3],2);
goto P_0c091f08;
P_0c091f08: /* original 6ccc, guest PC 0x0c091f08 */
if(!s->budget--) { s->failed_pc=0x0c091f08u; return 0; }
r[12]=r[12]&255u;
goto P_0c091f0a;
P_0c091f0a: /* original 633d, guest PC 0x0c091f0a */
if(!s->budget--) { s->failed_pc=0x0c091f0au; return 0; }
r[3]=r[3]&65535u;
goto P_0c091f0c;
P_0c091f0c: /* original 01dd, guest PC 0x0c091f0c */
if(!s->budget--) { s->failed_pc=0x0c091f0cu; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,r[13]+r[0],2);
goto P_0c091f0e;
P_0c091f0e: /* original 62cd, guest PC 0x0c091f0e */
if(!s->budget--) { s->failed_pc=0x0c091f0eu; return 0; }
r[2]=r[12]&65535u;
goto P_0c091f10;
P_0c091f10: /* original 3230, guest PC 0x0c091f10 */
if(!s->budget--) { s->failed_pc=0x0c091f10u; return 0; }
r[17]=(r[17]&~1u)|((r[2]==r[3])!=0);
goto P_0c091f12;
P_0c091f12: /* original 8d09, guest PC 0x0c091f12 */
if(!s->budget--) { s->failed_pc=0x0c091f12u; return 0; }
cond=r[17]&1u;
r[1]+=0x00000001u;
if(cond) { goto P_0c091f28; }
goto P_0c091f16;
P_0c091f14: /* original 7101, guest PC 0x0c091f14 */
if(!s->budget--) { s->failed_pc=0x0c091f14u; return 0; }
r[1]+=0x00000001u;
goto P_0c091f16;
P_0c091f16: /* original 9010, guest PC 0x0c091f16 */
if(!s->budget--) { s->failed_pc=0x0c091f16u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c091f3au,2);
goto P_0c091f18;
P_0c091f18: /* original e31f, guest PC 0x0c091f18 */
if(!s->budget--) { s->failed_pc=0x0c091f18u; return 0; }
r[3]=0x0000001fu;
goto P_0c091f1a;
P_0c091f1a: /* original 7401, guest PC 0x0c091f1a */
if(!s->budget--) { s->failed_pc=0x0c091f1au; return 0; }
r[4]+=0x00000001u;
goto P_0c091f1c;
P_0c091f1c: /* original 2439, guest PC 0x0c091f1c */
if(!s->budget--) { s->failed_pc=0x0c091f1cu; return 0; }
r[4]&=r[3];
goto P_0c091f1e;
P_0c091f1e: /* original 0545, guest PC 0x0c091f1e */
if(!s->budget--) { s->failed_pc=0x0c091f1eu; return 0; }
write(ram,r[5]+r[0],r[4],2);
goto P_0c091f20;
P_0c091f20: /* original 6063, guest PC 0x0c091f20 */
if(!s->budget--) { s->failed_pc=0x0c091f20u; return 0; }
r[0]=r[6];
goto P_0c091f22;
P_0c091f22: /* original 04c4, guest PC 0x0c091f22 */
if(!s->budget--) { s->failed_pc=0x0c091f22u; return 0; }
write(ram,r[4]+r[0],r[12],1);
goto P_0c091f24;
P_0c091f24: /* original 6743, guest PC 0x0c091f24 */
if(!s->budget--) { s->failed_pc=0x0c091f24u; return 0; }
r[7]=r[4];
goto P_0c091f26;
P_0c091f26: /* original e101, guest PC 0x0c091f26 */
if(!s->budget--) { s->failed_pc=0x0c091f26u; return 0; }
r[1]=0x00000001u;
goto P_0c091f28;
P_0c091f28: /* original 6073, guest PC 0x0c091f28 */
if(!s->budget--) { s->failed_pc=0x0c091f28u; return 0; }
r[0]=r[7];
goto P_0c091f2a;
P_0c091f2a: /* original 4000, guest PC 0x0c091f2a */
if(!s->budget--) { s->failed_pc=0x0c091f2au; return 0; }
r[17]=(r[17]&~1u)|((r[0]>>31)!=0);
r[0]<<=1;
goto P_0c091f2c;
P_0c091f2c: /* original 0d15, guest PC 0x0c091f2c */
if(!s->budget--) { s->failed_pc=0x0c091f2cu; return 0; }
write(ram,r[13]+r[0],r[1],2);
goto P_0c091f2e;
P_0c091f2e: /* original 7f04, guest PC 0x0c091f2e */
if(!s->budget--) { s->failed_pc=0x0c091f2eu; return 0; }
r[15]+=0x00000004u;
goto P_0c091f30;
P_0c091f30: /* original 6cf6, guest PC 0x0c091f30 */
if(!s->budget--) { s->failed_pc=0x0c091f30u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c091f32;
P_0c091f32: /* original 000b, guest PC 0x0c091f32 */
if(!s->budget--) { s->failed_pc=0x0c091f32u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
s->pc=target; return ram->oob==0;
P_0c091f34: /* original 6df6, guest PC 0x0c091f34 */
if(!s->budget--) { s->failed_pc=0x0c091f34u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
return vf3_matrix_family(0x0c091f36u,s,ram);
P_0c0970be: /* original d415, guest PC 0x0c0970be */
if(!s->budget--) { s->failed_pc=0x0c0970beu; return 0; }
r[4]=read(ram,0x0c097114u,4);
goto P_0c0970c0;
P_0c0970c0: /* original 5343, guest PC 0x0c0970c0 */
if(!s->budget--) { s->failed_pc=0x0c0970c0u; return 0; }
r[3]=read(ram,r[4]+12,4);
goto P_0c0970c2;
P_0c0970c2: /* original 2338, guest PC 0x0c0970c2 */
if(!s->budget--) { s->failed_pc=0x0c0970c2u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c0970c4;
P_0c0970c4: /* original 8b02, guest PC 0x0c0970c4 */
if(!s->budget--) { s->failed_pc=0x0c0970c4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0970cc; }
goto P_0c0970c6;
P_0c0970c6: /* original 844b, guest PC 0x0c0970c6 */
if(!s->budget--) { s->failed_pc=0x0c0970c6u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+11,1);
goto P_0c0970c8;
P_0c0970c8: /* original 7001, guest PC 0x0c0970c8 */
if(!s->budget--) { s->failed_pc=0x0c0970c8u; return 0; }
r[0]+=0x00000001u;
goto P_0c0970ca;
P_0c0970ca: /* original 804b, guest PC 0x0c0970ca */
if(!s->budget--) { s->failed_pc=0x0c0970cau; return 0; }
write(ram,r[4]+11,r[0],1);
goto P_0c0970cc;
P_0c0970cc: /* original ae47, guest PC 0x0c0970cc */
if(!s->budget--) { s->failed_pc=0x0c0970ccu; return 0; }
return vf3_matrix_family(0x0c096d5eu,s,ram);
P_0c0970ce: /* original 0009, guest PC 0x0c0970ce */
if(!s->budget--) { s->failed_pc=0x0c0970ceu; return 0; }
return vf3_matrix_family(0x0c0970d0u,s,ram);
P_0c0978ea: /* original 2fe6, guest PC 0x0c0978ea */
if(!s->budget--) { s->failed_pc=0x0c0978eau; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0978ec;
P_0c0978ec: /* original e600, guest PC 0x0c0978ec */
if(!s->budget--) { s->failed_pc=0x0c0978ecu; return 0; }
r[6]=0x00000000u;
return vf3_matrix_family(0x0c0978eeu,s,ram);
P_0c097abc: /* original 4f22, guest PC 0x0c097abc */
if(!s->budget--) { s->failed_pc=0x0c097abcu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c097abe;
P_0c097abe: /* original 74ff, guest PC 0x0c097abe */
if(!s->budget--) { s->failed_pc=0x0c097abeu; return 0; }
r[4]+=0xffffffffu;
goto P_0c097ac0;
P_0c097ac0: /* original 0c44, guest PC 0x0c097ac0 */
if(!s->budget--) { s->failed_pc=0x0c097ac0u; return 0; }
write(ram,r[12]+r[0],r[4],1);
goto P_0c097ac2;
P_0c097ac2: /* original 52e1, guest PC 0x0c097ac2 */
if(!s->budget--) { s->failed_pc=0x0c097ac2u; return 0; }
r[2]=read(ram,r[14]+4,4);
goto P_0c097ac4;
P_0c097ac4: /* original 7ff4, guest PC 0x0c097ac4 */
if(!s->budget--) { s->failed_pc=0x0c097ac4u; return 0; }
r[15]+=0xfffffff4u;
goto P_0c097ac6;
P_0c097ac6: /* original d330, guest PC 0x0c097ac6 */
if(!s->budget--) { s->failed_pc=0x0c097ac6u; return 0; }
r[3]=read(ram,0x0c097b88u,4);
goto P_0c097ac8;
P_0c097ac8: /* original dd2e, guest PC 0x0c097ac8 */
if(!s->budget--) { s->failed_pc=0x0c097ac8u; return 0; }
r[13]=read(ram,0x0c097b84u,4);
goto P_0c097aca;
P_0c097aca: /* original 2238, guest PC 0x0c097aca */
if(!s->budget--) { s->failed_pc=0x0c097acau; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c097acc;
P_0c097acc: /* original 8917, guest PC 0x0c097acc */
if(!s->budget--) { s->failed_pc=0x0c097accu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c097afe; }
goto P_0c097ace;
P_0c097ace: /* original 9051, guest PC 0x0c097ace */
if(!s->budget--) { s->failed_pc=0x0c097aceu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c097b74u,2);
goto P_0c097ad0;
P_0c097ad0: /* original e304, guest PC 0x0c097ad0 */
if(!s->budget--) { s->failed_pc=0x0c097ad0u; return 0; }
r[3]=0x00000004u;
goto P_0c097ad2;
P_0c097ad2: /* original 55d4, guest PC 0x0c097ad2 */
if(!s->budget--) { s->failed_pc=0x0c097ad2u; return 0; }
r[5]=read(ram,r[13]+16,4);
goto P_0c097ad4;
P_0c097ad4: /* original 055e, guest PC 0x0c097ad4 */
if(!s->budget--) { s->failed_pc=0x0c097ad4u; return 0; }
r[5]=read(ram,r[5]+r[0],4);
goto P_0c097ad6;
P_0c097ad6: /* original 2538, guest PC 0x0c097ad6 */
if(!s->budget--) { s->failed_pc=0x0c097ad6u; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[3])==0)!=0);
goto P_0c097ad8;
P_0c097ad8: /* original 8f06, guest PC 0x0c097ad8 */
if(!s->budget--) { s->failed_pc=0x0c097ad8u; return 0; }
cond=r[17]&1u;
r[4]=read(ram,r[13]+20,4);
if(!cond) { goto P_0c097ae8; }
goto P_0c097adc;
P_0c097ada: /* original 54d5, guest PC 0x0c097ada */
if(!s->budget--) { s->failed_pc=0x0c097adau; return 0; }
r[4]=read(ram,r[13]+20,4);
goto P_0c097adc;
P_0c097adc: /* original 904b, guest PC 0x0c097adc */
if(!s->budget--) { s->failed_pc=0x0c097adcu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c097b76u,2);
goto P_0c097ade;
P_0c097ade: /* original 914a, guest PC 0x0c097ade */
if(!s->budget--) { s->failed_pc=0x0c097adeu; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c097b76u,2);
goto P_0c097ae0;
P_0c097ae0: /* original 00cc, guest PC 0x0c097ae0 */
if(!s->budget--) { s->failed_pc=0x0c097ae0u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[12]+r[0],1);
goto P_0c097ae2;
P_0c097ae2: /* original 31cc, guest PC 0x0c097ae2 */
if(!s->budget--) { s->failed_pc=0x0c097ae2u; return 0; }
r[1]+=r[12];
goto P_0c097ae4;
P_0c097ae4: /* original cb01, guest PC 0x0c097ae4 */
if(!s->budget--) { s->failed_pc=0x0c097ae4u; return 0; }
r[0]|=1u;
goto P_0c097ae6;
P_0c097ae6: /* original 2100, guest PC 0x0c097ae6 */
if(!s->budget--) { s->failed_pc=0x0c097ae6u; return 0; }
write(ram,r[1],r[0],1);
goto P_0c097ae8;
P_0c097ae8: /* original 9044, guest PC 0x0c097ae8 */
if(!s->budget--) { s->failed_pc=0x0c097ae8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c097b74u,2);
goto P_0c097aea;
P_0c097aea: /* original e304, guest PC 0x0c097aea */
if(!s->budget--) { s->failed_pc=0x0c097aeau; return 0; }
r[3]=0x00000004u;
goto P_0c097aec;
P_0c097aec: /* original 044e, guest PC 0x0c097aec */
if(!s->budget--) { s->failed_pc=0x0c097aecu; return 0; }
r[4]=read(ram,r[4]+r[0],4);
goto P_0c097aee;
P_0c097aee: /* original 2438, guest PC 0x0c097aee */
if(!s->budget--) { s->failed_pc=0x0c097aeeu; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[3])==0)!=0);
goto P_0c097af0;
P_0c097af0: /* original 8b05, guest PC 0x0c097af0 */
if(!s->budget--) { s->failed_pc=0x0c097af0u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c097afe; }
goto P_0c097af2;
P_0c097af2: /* original 9040, guest PC 0x0c097af2 */
if(!s->budget--) { s->failed_pc=0x0c097af2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c097b76u,2);
goto P_0c097af4;
P_0c097af4: /* original 913f, guest PC 0x0c097af4 */
if(!s->budget--) { s->failed_pc=0x0c097af4u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c097b76u,2);
goto P_0c097af6;
P_0c097af6: /* original 00cc, guest PC 0x0c097af6 */
if(!s->budget--) { s->failed_pc=0x0c097af6u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[12]+r[0],1);
goto P_0c097af8;
P_0c097af8: /* original 31cc, guest PC 0x0c097af8 */
if(!s->budget--) { s->failed_pc=0x0c097af8u; return 0; }
r[1]+=r[12];
goto P_0c097afa;
P_0c097afa: /* original cb02, guest PC 0x0c097afa */
if(!s->budget--) { s->failed_pc=0x0c097afau; return 0; }
r[0]|=2u;
goto P_0c097afc;
P_0c097afc: /* original 2100, guest PC 0x0c097afc */
if(!s->budget--) { s->failed_pc=0x0c097afcu; return 0; }
write(ram,r[1],r[0],1);
goto P_0c097afe;
P_0c097afe: /* original e301, guest PC 0x0c097afe */
if(!s->budget--) { s->failed_pc=0x0c097afeu; return 0; }
r[3]=0x00000001u;
goto P_0c097b00;
P_0c097b00: /* original eb00, guest PC 0x0c097b00 */
if(!s->budget--) { s->failed_pc=0x0c097b00u; return 0; }
r[11]=0x00000000u;
goto P_0c097b02;
P_0c097b02: /* original e01d, guest PC 0x0c097b02 */
if(!s->budget--) { s->failed_pc=0x0c097b02u; return 0; }
r[0]=0x0000001du;
goto P_0c097b04;
P_0c097b04: /* original 0eb4, guest PC 0x0c097b04 */
if(!s->budget--) { s->failed_pc=0x0c097b04u; return 0; }
write(ram,r[14]+r[0],r[11],1);
goto P_0c097b06;
P_0c097b06: /* original da21, guest PC 0x0c097b06 */
if(!s->budget--) { s->failed_pc=0x0c097b06u; return 0; }
r[10]=read(ram,0x0c097b8cu,4);
goto P_0c097b08;
P_0c097b08: /* original 64a2, guest PC 0x0c097b08 */
if(!s->budget--) { s->failed_pc=0x0c097b08u; return 0; }
tmp=read(ram,r[10],4);
r[4]=tmp;
goto P_0c097b0a;
P_0c097b0a: /* original 2348, guest PC 0x0c097b0a */
if(!s->budget--) { s->failed_pc=0x0c097b0au; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[4])==0)!=0);
goto P_0c097b0c;
P_0c097b0c: /* original 8b01, guest PC 0x0c097b0c */
if(!s->budget--) { s->failed_pc=0x0c097b0cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c097b12; }
goto P_0c097b0e;
P_0c097b0e: /* original a245, guest PC 0x0c097b0e */
if(!s->budget--) { s->failed_pc=0x0c097b0eu; return 0; }
goto P_0c097f9c;
P_0c097b10: /* original 0009, guest PC 0x0c097b10 */
if(!s->budget--) { s->failed_pc=0x0c097b10u; return 0; }
goto P_0c097b12;
P_0c097b12: /* original 53c2, guest PC 0x0c097b12 */
if(!s->budget--) { s->failed_pc=0x0c097b12u; return 0; }
r[3]=read(ram,r[12]+8,4);
goto P_0c097b14;
P_0c097b14: /* original d81e, guest PC 0x0c097b14 */
if(!s->budget--) { s->failed_pc=0x0c097b14u; return 0; }
r[8]=read(ram,0x0c097b90u,4);
goto P_0c097b16;
P_0c097b16: /* original 2388, guest PC 0x0c097b16 */
if(!s->budget--) { s->failed_pc=0x0c097b16u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[8])==0)!=0);
goto P_0c097b18;
P_0c097b18: /* original 8b05, guest PC 0x0c097b18 */
if(!s->budget--) { s->failed_pc=0x0c097b18u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c097b26; }
goto P_0c097b1a;
P_0c097b1a: /* original 902d, guest PC 0x0c097b1a */
if(!s->budget--) { s->failed_pc=0x0c097b1au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c097b78u,2);
goto P_0c097b1c;
P_0c097b1c: /* original 01ec, guest PC 0x0c097b1c */
if(!s->budget--) { s->failed_pc=0x0c097b1cu; return 0; }
r[1]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c097b1e;
P_0c097b1e: /* original 2118, guest PC 0x0c097b1e */
if(!s->budget--) { s->failed_pc=0x0c097b1eu; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[1])==0)!=0);
goto P_0c097b20;
P_0c097b20: /* original 8b01, guest PC 0x0c097b20 */
if(!s->budget--) { s->failed_pc=0x0c097b20u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c097b26; }
goto P_0c097b22;
P_0c097b22: /* original a244, guest PC 0x0c097b22 */
if(!s->budget--) { s->failed_pc=0x0c097b22u; return 0; }
goto P_0c097fae;
P_0c097b24: /* original 0009, guest PC 0x0c097b24 */
if(!s->budget--) { s->failed_pc=0x0c097b24u; return 0; }
goto P_0c097b26;
P_0c097b26: /* original 52da, guest PC 0x0c097b26 */
if(!s->budget--) { s->failed_pc=0x0c097b26u; return 0; }
r[2]=read(ram,r[13]+40,4);
goto P_0c097b28;
P_0c097b28: /* original 2f22, guest PC 0x0c097b28 */
if(!s->budget--) { s->failed_pc=0x0c097b28u; return 0; }
write(ram,r[15],r[2],4);
goto P_0c097b2a;
P_0c097b2a: /* original 53db, guest PC 0x0c097b2a */
if(!s->budget--) { s->failed_pc=0x0c097b2au; return 0; }
r[3]=read(ram,r[13]+44,4);
goto P_0c097b2c;
P_0c097b2c: /* original 1f32, guest PC 0x0c097b2c */
if(!s->budget--) { s->failed_pc=0x0c097b2cu; return 0; }
write(ram,r[15]+8,r[3],4);
goto P_0c097b2e;
P_0c097b2e: /* original 9023, guest PC 0x0c097b2e */
if(!s->budget--) { s->failed_pc=0x0c097b2eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c097b78u,2);
goto P_0c097b30;
P_0c097b30: /* original 03ec, guest PC 0x0c097b30 */
if(!s->budget--) { s->failed_pc=0x0c097b30u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c097b32;
P_0c097b32: /* original 2338, guest PC 0x0c097b32 */
if(!s->budget--) { s->failed_pc=0x0c097b32u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c097b34;
P_0c097b34: /* original 8d02, guest PC 0x0c097b34 */
if(!s->budget--) { s->failed_pc=0x0c097b34u; return 0; }
cond=r[17]&1u;
r[9]=0x00000002u;
if(cond) { goto P_0c097b3c; }
goto P_0c097b38;
P_0c097b36: /* original e902, guest PC 0x0c097b36 */
if(!s->budget--) { s->failed_pc=0x0c097b36u; return 0; }
r[9]=0x00000002u;
goto P_0c097b38;
P_0c097b38: /* original a0f1, guest PC 0x0c097b38 */
if(!s->budget--) { s->failed_pc=0x0c097b38u; return 0; }
goto P_0c097d1e;
P_0c097b3a: /* original 0009, guest PC 0x0c097b3a */
if(!s->budget--) { s->failed_pc=0x0c097b3au; return 0; }
goto P_0c097b3c;
P_0c097b3c: /* original 2488, guest PC 0x0c097b3c */
if(!s->budget--) { s->failed_pc=0x0c097b3cu; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[8])==0)!=0);
goto P_0c097b3e;
P_0c097b3e: /* original 8901, guest PC 0x0c097b3e */
if(!s->budget--) { s->failed_pc=0x0c097b3eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c097b44; }
goto P_0c097b40;
P_0c097b40: /* original a001, guest PC 0x0c097b40 */
if(!s->budget--) { s->failed_pc=0x0c097b40u; return 0; }
r[4]=0x00000000u;
goto P_0c097b46;
P_0c097b42: /* original e400, guest PC 0x0c097b42 */
if(!s->budget--) { s->failed_pc=0x0c097b42u; return 0; }
r[4]=0x00000000u;
goto P_0c097b44;
P_0c097b44: /* original e401, guest PC 0x0c097b44 */
if(!s->budget--) { s->failed_pc=0x0c097b44u; return 0; }
r[4]=0x00000001u;
goto P_0c097b46;
P_0c097b46: /* original d213, guest PC 0x0c097b46 */
if(!s->budget--) { s->failed_pc=0x0c097b46u; return 0; }
r[2]=read(ram,0x0c097b94u,4);
goto P_0c097b48;
P_0c097b48: /* original 420b, guest PC 0x0c097b48 */
if(!s->budget--) { s->failed_pc=0x0c097b48u; return 0; }
target=r[2];
r[16]=code_base|0x0c097b4cu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c097b4cu) { target=s->pc; goto dispatch; }
goto P_0c097b4c;
P_0c097b4a: /* original 0009, guest PC 0x0c097b4a */
if(!s->budget--) { s->failed_pc=0x0c097b4au; return 0; }
goto P_0c097b4c;
P_0c097b4c: /* original 6403, guest PC 0x0c097b4c */
if(!s->budget--) { s->failed_pc=0x0c097b4cu; return 0; }
r[4]=r[0];
goto P_0c097b4e;
P_0c097b4e: /* original 5242, guest PC 0x0c097b4e */
if(!s->budget--) { s->failed_pc=0x0c097b4eu; return 0; }
r[2]=read(ram,r[4]+8,4);
goto P_0c097b50;
P_0c097b50: /* original 9313, guest PC 0x0c097b50 */
if(!s->budget--) { s->failed_pc=0x0c097b50u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c097b7au,2);
goto P_0c097b52;
P_0c097b52: /* original 2238, guest PC 0x0c097b52 */
if(!s->budget--) { s->failed_pc=0x0c097b52u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c097b54;
P_0c097b54: /* original 8b01, guest PC 0x0c097b54 */
if(!s->budget--) { s->failed_pc=0x0c097b54u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c097b5a; }
goto P_0c097b56;
P_0c097b56: /* original a097, guest PC 0x0c097b56 */
if(!s->budget--) { s->failed_pc=0x0c097b56u; return 0; }
goto P_0c097c88;
P_0c097b58: /* original 0009, guest PC 0x0c097b58 */
if(!s->budget--) { s->failed_pc=0x0c097b58u; return 0; }
goto P_0c097b5a;
P_0c097b5a: /* original 51c2, guest PC 0x0c097b5a */
if(!s->budget--) { s->failed_pc=0x0c097b5au; return 0; }
r[1]=read(ram,r[12]+8,4);
goto P_0c097b5c;
P_0c097b5c: /* original e2fb, guest PC 0x0c097b5c */
if(!s->budget--) { s->failed_pc=0x0c097b5cu; return 0; }
r[2]=0xfffffffbu;
goto P_0c097b5e;
P_0c097b5e: /* original 2129, guest PC 0x0c097b5e */
if(!s->budget--) { s->failed_pc=0x0c097b5eu; return 0; }
r[1]&=r[2];
goto P_0c097b60;
P_0c097b60: /* original 6013, guest PC 0x0c097b60 */
if(!s->budget--) { s->failed_pc=0x0c097b60u; return 0; }
r[0]=r[1];
goto P_0c097b62;
P_0c097b62: /* original 208b, guest PC 0x0c097b62 */
if(!s->budget--) { s->failed_pc=0x0c097b62u; return 0; }
r[0]|=r[8];
goto P_0c097b64;
P_0c097b64: /* original 1c02, guest PC 0x0c097b64 */
if(!s->budget--) { s->failed_pc=0x0c097b64u; return 0; }
write(ram,r[12]+8,r[0],4);
goto P_0c097b66;
P_0c097b66: /* original 61a2, guest PC 0x0c097b66 */
if(!s->budget--) { s->failed_pc=0x0c097b66u; return 0; }
tmp=read(ram,r[10],4);
r[1]=tmp;
goto P_0c097b68;
P_0c097b68: /* original 2818, guest PC 0x0c097b68 */
if(!s->budget--) { s->failed_pc=0x0c097b68u; return 0; }
r[17]=(r[17]&~1u)|(((r[8]&r[1])==0)!=0);
goto P_0c097b6a;
P_0c097b6a: /* original 8917, guest PC 0x0c097b6a */
if(!s->budget--) { s->failed_pc=0x0c097b6au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c097b9c; }
goto P_0c097b6c;
P_0c097b6c: /* original d10a, guest PC 0x0c097b6c */
if(!s->budget--) { s->failed_pc=0x0c097b6cu; return 0; }
r[1]=read(ram,0x0c097b98u,4);
goto P_0c097b6e;
P_0c097b6e: /* original a016, guest PC 0x0c097b6e */
if(!s->budget--) { s->failed_pc=0x0c097b6eu; return 0; }
goto P_0c097b9e;
P_0c097b70: /* original 0009, guest PC 0x0c097b70 */
if(!s->budget--) { s->failed_pc=0x0c097b70u; return 0; }
return vf3_matrix_family(0x0c097b72u,s,ram);
P_0c097b9c: /* original d14c, guest PC 0x0c097b9c */
if(!s->budget--) { s->failed_pc=0x0c097b9cu; return 0; }
r[1]=read(ram,0x0c097cd0u,4);
goto P_0c097b9e;
P_0c097b9e: /* original 50c2, guest PC 0x0c097b9e */
if(!s->budget--) { s->failed_pc=0x0c097b9eu; return 0; }
r[0]=read(ram,r[12]+8,4);
goto P_0c097ba0;
P_0c097ba0: /* original e600, guest PC 0x0c097ba0 */
if(!s->budget--) { s->failed_pc=0x0c097ba0u; return 0; }
r[6]=0x00000000u;
goto P_0c097ba2;
P_0c097ba2: /* original 6563, guest PC 0x0c097ba2 */
if(!s->budget--) { s->failed_pc=0x0c097ba2u; return 0; }
r[5]=r[6];
goto P_0c097ba4;
P_0c097ba4: /* original 201b, guest PC 0x0c097ba4 */
if(!s->budget--) { s->failed_pc=0x0c097ba4u; return 0; }
r[0]|=r[1];
goto P_0c097ba6;
P_0c097ba6: /* original 1c02, guest PC 0x0c097ba6 */
if(!s->budget--) { s->failed_pc=0x0c097ba6u; return 0; }
write(ram,r[12]+8,r[0],4);
goto P_0c097ba8;
P_0c097ba8: /* original d34a, guest PC 0x0c097ba8 */
if(!s->budget--) { s->failed_pc=0x0c097ba8u; return 0; }
r[3]=read(ram,0x0c097cd4u,4);
goto P_0c097baa;
P_0c097baa: /* original 430b, guest PC 0x0c097baa */
if(!s->budget--) { s->failed_pc=0x0c097baau; return 0; }
target=r[3];
r[16]=code_base|0x0c097baeu;
r[4]=r[6];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c097baeu) { target=s->pc; goto dispatch; }
goto P_0c097bae;
P_0c097bac: /* original 6463, guest PC 0x0c097bac */
if(!s->budget--) { s->failed_pc=0x0c097bacu; return 0; }
r[4]=r[6];
goto P_0c097bae;
P_0c097bae: /* original e600, guest PC 0x0c097bae */
if(!s->budget--) { s->failed_pc=0x0c097baeu; return 0; }
r[6]=0x00000000u;
goto P_0c097bb0;
P_0c097bb0: /* original ff8d, guest PC 0x0c097bb0 */
if(!s->budget--) { s->failed_pc=0x0c097bb0u; return 0; }
fr[15]=0;
goto P_0c097bb2;
P_0c097bb2: /* original dc49, guest PC 0x0c097bb2 */
if(!s->budget--) { s->failed_pc=0x0c097bb2u; return 0; }
r[12]=read(ram,0x0c097cd8u,4);
goto P_0c097bb4;
P_0c097bb4: /* original 6563, guest PC 0x0c097bb4 */
if(!s->budget--) { s->failed_pc=0x0c097bb4u; return 0; }
r[5]=r[6];
goto P_0c097bb6;
P_0c097bb6: /* original f5fc, guest PC 0x0c097bb6 */
if(!s->budget--) { s->failed_pc=0x0c097bb6u; return 0; }
vf3_matrix_move(s,5,15);
goto P_0c097bb8;
P_0c097bb8: /* original f4fc, guest PC 0x0c097bb8 */
if(!s->budget--) { s->failed_pc=0x0c097bb8u; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c097bba;
P_0c097bba: /* original 4c0b, guest PC 0x0c097bba */
if(!s->budget--) { s->failed_pc=0x0c097bbau; return 0; }
target=r[12];
r[16]=code_base|0x0c097bbeu;
r[4]=r[6];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c097bbeu) { target=s->pc; goto dispatch; }
goto P_0c097bbe;
P_0c097bbc: /* original 6463, guest PC 0x0c097bbc */
if(!s->budget--) { s->failed_pc=0x0c097bbcu; return 0; }
r[4]=r[6];
goto P_0c097bbe;
P_0c097bbe: /* original d247, guest PC 0x0c097bbe */
if(!s->budget--) { s->failed_pc=0x0c097bbeu; return 0; }
r[2]=read(ram,0x0c097cdcu,4);
goto P_0c097bc0;
P_0c097bc0: /* original 420b, guest PC 0x0c097bc0 */
if(!s->budget--) { s->failed_pc=0x0c097bc0u; return 0; }
target=r[2];
r[16]=code_base|0x0c097bc4u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c097bc4u) { target=s->pc; goto dispatch; }
goto P_0c097bc4;
P_0c097bc2: /* original 0009, guest PC 0x0c097bc2 */
if(!s->budget--) { s->failed_pc=0x0c097bc2u; return 0; }
goto P_0c097bc4;
P_0c097bc4: /* original d346, guest PC 0x0c097bc4 */
if(!s->budget--) { s->failed_pc=0x0c097bc4u; return 0; }
r[3]=read(ram,0x0c097ce0u,4);
goto P_0c097bc6;
P_0c097bc6: /* original 430b, guest PC 0x0c097bc6 */
if(!s->budget--) { s->failed_pc=0x0c097bc6u; return 0; }
target=r[3];
r[16]=code_base|0x0c097bcau;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c097bcau) { target=s->pc; goto dispatch; }
goto P_0c097bca;
P_0c097bc8: /* original 0009, guest PC 0x0c097bc8 */
if(!s->budget--) { s->failed_pc=0x0c097bc8u; return 0; }
goto P_0c097bca;
P_0c097bca: /* original d246, guest PC 0x0c097bca */
if(!s->budget--) { s->failed_pc=0x0c097bcau; return 0; }
r[2]=read(ram,0x0c097ce4u,4);
goto P_0c097bcc;
P_0c097bcc: /* original 420b, guest PC 0x0c097bcc */
if(!s->budget--) { s->failed_pc=0x0c097bccu; return 0; }
target=r[2];
r[16]=code_base|0x0c097bd0u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c097bd0u) { target=s->pc; goto dispatch; }
goto P_0c097bd0;
P_0c097bce: /* original 0009, guest PC 0x0c097bce */
if(!s->budget--) { s->failed_pc=0x0c097bceu; return 0; }
goto P_0c097bd0;
P_0c097bd0: /* original d346, guest PC 0x0c097bd0 */
if(!s->budget--) { s->failed_pc=0x0c097bd0u; return 0; }
r[3]=read(ram,0x0c097cecu,4);
goto P_0c097bd2;
P_0c097bd2: /* original d445, guest PC 0x0c097bd2 */
if(!s->budget--) { s->failed_pc=0x0c097bd2u; return 0; }
r[4]=read(ram,0x0c097ce8u,4);
goto P_0c097bd4;
P_0c097bd4: /* original 430b, guest PC 0x0c097bd4 */
if(!s->budget--) { s->failed_pc=0x0c097bd4u; return 0; }
target=r[3];
r[16]=code_base|0x0c097bd8u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c097bd8u) { target=s->pc; goto dispatch; }
goto P_0c097bd8;
P_0c097bd6: /* original 0009, guest PC 0x0c097bd6 */
if(!s->budget--) { s->failed_pc=0x0c097bd6u; return 0; }
goto P_0c097bd8;
P_0c097bd8: /* original d245, guest PC 0x0c097bd8 */
if(!s->budget--) { s->failed_pc=0x0c097bd8u; return 0; }
r[2]=read(ram,0x0c097cf0u,4);
goto P_0c097bda;
P_0c097bda: /* original 420b, guest PC 0x0c097bda */
if(!s->budget--) { s->failed_pc=0x0c097bdau; return 0; }
target=r[2];
r[16]=code_base|0x0c097bdeu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c097bdeu) { target=s->pc; goto dispatch; }
goto P_0c097bde;
P_0c097bdc: /* original 0009, guest PC 0x0c097bdc */
if(!s->budget--) { s->failed_pc=0x0c097bdcu; return 0; }
goto P_0c097bde;
P_0c097bde: /* original d345, guest PC 0x0c097bde */
if(!s->budget--) { s->failed_pc=0x0c097bdeu; return 0; }
r[3]=read(ram,0x0c097cf4u,4);
goto P_0c097be0;
P_0c097be0: /* original 430b, guest PC 0x0c097be0 */
if(!s->budget--) { s->failed_pc=0x0c097be0u; return 0; }
target=r[3];
r[16]=code_base|0x0c097be4u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c097be4u) { target=s->pc; goto dispatch; }
goto P_0c097be4;
P_0c097be2: /* original 0009, guest PC 0x0c097be2 */
if(!s->budget--) { s->failed_pc=0x0c097be2u; return 0; }
goto P_0c097be4;
P_0c097be4: /* original d244, guest PC 0x0c097be4 */
if(!s->budget--) { s->failed_pc=0x0c097be4u; return 0; }
r[2]=read(ram,0x0c097cf8u,4);
goto P_0c097be6;
P_0c097be6: /* original 420b, guest PC 0x0c097be6 */
if(!s->budget--) { s->failed_pc=0x0c097be6u; return 0; }
target=r[2];
r[16]=code_base|0x0c097beau;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c097beau) { target=s->pc; goto dispatch; }
goto P_0c097bea;
P_0c097be8: /* original 0009, guest PC 0x0c097be8 */
if(!s->budget--) { s->failed_pc=0x0c097be8u; return 0; }
goto P_0c097bea;
P_0c097bea: /* original d844, guest PC 0x0c097bea */
if(!s->budget--) { s->failed_pc=0x0c097beau; return 0; }
r[8]=read(ram,0x0c097cfcu,4);
goto P_0c097bec;
P_0c097bec: /* original 480b, guest PC 0x0c097bec */
if(!s->budget--) { s->failed_pc=0x0c097becu; return 0; }
target=r[8];
r[16]=code_base|0x0c097bf0u;
r[4]=0x00000014u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c097bf0u) { target=s->pc; goto dispatch; }
goto P_0c097bf0;
P_0c097bee: /* original e414, guest PC 0x0c097bee */
if(!s->budget--) { s->failed_pc=0x0c097beeu; return 0; }
r[4]=0x00000014u;
goto P_0c097bf0;
P_0c097bf0: /* original 480b, guest PC 0x0c097bf0 */
if(!s->budget--) { s->failed_pc=0x0c097bf0u; return 0; }
target=r[8];
r[16]=code_base|0x0c097bf4u;
r[4]=0x00000016u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c097bf4u) { target=s->pc; goto dispatch; }
goto P_0c097bf4;
P_0c097bf2: /* original e416, guest PC 0x0c097bf2 */
if(!s->budget--) { s->failed_pc=0x0c097bf2u; return 0; }
r[4]=0x00000016u;
goto P_0c097bf4;
P_0c097bf4: /* original 480b, guest PC 0x0c097bf4 */
if(!s->budget--) { s->failed_pc=0x0c097bf4u; return 0; }
target=r[8];
r[16]=code_base|0x0c097bf8u;
r[4]=0x0000000fu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c097bf8u) { target=s->pc; goto dispatch; }
goto P_0c097bf8;
P_0c097bf6: /* original e40f, guest PC 0x0c097bf6 */
if(!s->budget--) { s->failed_pc=0x0c097bf6u; return 0; }
r[4]=0x0000000fu;
goto P_0c097bf8;
P_0c097bf8: /* original c741, guest PC 0x0c097bf8 */
if(!s->budget--) { s->failed_pc=0x0c097bf8u; return 0; }
r[0]=0x0c097d00u;
goto P_0c097bfa;
P_0c097bfa: /* original f5fc, guest PC 0x0c097bfa */
if(!s->budget--) { s->failed_pc=0x0c097bfau; return 0; }
vf3_matrix_move(s,5,15);
goto P_0c097bfc;
P_0c097bfc: /* original e600, guest PC 0x0c097bfc */
if(!s->budget--) { s->failed_pc=0x0c097bfcu; return 0; }
r[6]=0x00000000u;
goto P_0c097bfe;
P_0c097bfe: /* original f408, guest PC 0x0c097bfe */
if(!s->budget--) { s->failed_pc=0x0c097bfeu; return 0; }
vf3_matrix_load(s,ram,4,r[0]);
goto P_0c097c00;
P_0c097c00: /* original 6563, guest PC 0x0c097c00 */
if(!s->budget--) { s->failed_pc=0x0c097c00u; return 0; }
r[5]=r[6];
goto P_0c097c02;
P_0c097c02: /* original 4c0b, guest PC 0x0c097c02 */
if(!s->budget--) { s->failed_pc=0x0c097c02u; return 0; }
target=r[12];
r[16]=code_base|0x0c097c06u;
r[4]=r[6];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c097c06u) { target=s->pc; goto dispatch; }
goto P_0c097c06;
P_0c097c04: /* original 6463, guest PC 0x0c097c04 */
if(!s->budget--) { s->failed_pc=0x0c097c04u; return 0; }
r[4]=r[6];
goto P_0c097c06;
P_0c097c06: /* original c73f, guest PC 0x0c097c06 */
if(!s->budget--) { s->failed_pc=0x0c097c06u; return 0; }
r[0]=0x0c097d04u;
goto P_0c097c08;
P_0c097c08: /* original f5fc, guest PC 0x0c097c08 */
if(!s->budget--) { s->failed_pc=0x0c097c08u; return 0; }
vf3_matrix_move(s,5,15);
goto P_0c097c0a;
P_0c097c0a: /* original e600, guest PC 0x0c097c0a */
if(!s->budget--) { s->failed_pc=0x0c097c0au; return 0; }
r[6]=0x00000000u;
goto P_0c097c0c;
P_0c097c0c: /* original f408, guest PC 0x0c097c0c */
if(!s->budget--) { s->failed_pc=0x0c097c0cu; return 0; }
vf3_matrix_load(s,ram,4,r[0]);
goto P_0c097c0e;
P_0c097c0e: /* original 6563, guest PC 0x0c097c0e */
if(!s->budget--) { s->failed_pc=0x0c097c0eu; return 0; }
r[5]=r[6];
goto P_0c097c10;
P_0c097c10: /* original 4c0b, guest PC 0x0c097c10 */
if(!s->budget--) { s->failed_pc=0x0c097c10u; return 0; }
target=r[12];
r[16]=code_base|0x0c097c14u;
r[4]=r[6];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c097c14u) { target=s->pc; goto dispatch; }
goto P_0c097c14;
P_0c097c12: /* original 6463, guest PC 0x0c097c12 */
if(!s->budget--) { s->failed_pc=0x0c097c12u; return 0; }
r[4]=r[6];
goto P_0c097c14;
P_0c097c14: /* original d33c, guest PC 0x0c097c14 */
if(!s->budget--) { s->failed_pc=0x0c097c14u; return 0; }
r[3]=read(ram,0x0c097d08u,4);
goto P_0c097c16;
P_0c097c16: /* original 430b, guest PC 0x0c097c16 */
if(!s->budget--) { s->failed_pc=0x0c097c16u; return 0; }
target=r[3];
r[16]=code_base|0x0c097c1au;
r[4]=read(ram,r[13]+24,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c097c1au) { target=s->pc; goto dispatch; }
goto P_0c097c1a;
P_0c097c18: /* original 54d6, guest PC 0x0c097c18 */
if(!s->budget--) { s->failed_pc=0x0c097c18u; return 0; }
r[4]=read(ram,r[13]+24,4);
goto P_0c097c1a;
P_0c097c1a: /* original d23b, guest PC 0x0c097c1a */
if(!s->budget--) { s->failed_pc=0x0c097c1au; return 0; }
r[2]=read(ram,0x0c097d08u,4);
goto P_0c097c1c;
P_0c097c1c: /* original 420b, guest PC 0x0c097c1c */
if(!s->budget--) { s->failed_pc=0x0c097c1cu; return 0; }
target=r[2];
r[16]=code_base|0x0c097c20u;
r[4]=read(ram,r[13]+28,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c097c20u) { target=s->pc; goto dispatch; }
goto P_0c097c20;
P_0c097c1e: /* original 54d7, guest PC 0x0c097c1e */
if(!s->budget--) { s->failed_pc=0x0c097c1eu; return 0; }
r[4]=read(ram,r[13]+28,4);
goto P_0c097c20;
P_0c097c20: /* original d339, guest PC 0x0c097c20 */
if(!s->budget--) { s->failed_pc=0x0c097c20u; return 0; }
r[3]=read(ram,0x0c097d08u,4);
goto P_0c097c22;
P_0c097c22: /* original 430b, guest PC 0x0c097c22 */
if(!s->budget--) { s->failed_pc=0x0c097c22u; return 0; }
target=r[3];
r[16]=code_base|0x0c097c26u;
r[4]=read(ram,r[13]+60,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c097c26u) { target=s->pc; goto dispatch; }
goto P_0c097c26;
P_0c097c24: /* original 54df, guest PC 0x0c097c24 */
if(!s->budget--) { s->failed_pc=0x0c097c24u; return 0; }
r[4]=read(ram,r[13]+60,4);
goto P_0c097c26;
P_0c097c26: /* original d338, guest PC 0x0c097c26 */
if(!s->budget--) { s->failed_pc=0x0c097c26u; return 0; }
r[3]=read(ram,0x0c097d08u,4);
goto P_0c097c28;
P_0c097c28: /* original e040, guest PC 0x0c097c28 */
if(!s->budget--) { s->failed_pc=0x0c097c28u; return 0; }
r[0]=0x00000040u;
goto P_0c097c2a;
P_0c097c2a: /* original 430b, guest PC 0x0c097c2a */
if(!s->budget--) { s->failed_pc=0x0c097c2au; return 0; }
target=r[3];
r[16]=code_base|0x0c097c2eu;
r[4]=read(ram,r[13]+r[0],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c097c2eu) { target=s->pc; goto dispatch; }
goto P_0c097c2e;
P_0c097c2c: /* original 04de, guest PC 0x0c097c2c */
if(!s->budget--) { s->failed_pc=0x0c097c2cu; return 0; }
r[4]=read(ram,r[13]+r[0],4);
goto P_0c097c2e;
P_0c097c2e: /* original d236, guest PC 0x0c097c2e */
if(!s->budget--) { s->failed_pc=0x0c097c2eu; return 0; }
r[2]=read(ram,0x0c097d08u,4);
goto P_0c097c30;
P_0c097c30: /* original 420b, guest PC 0x0c097c30 */
if(!s->budget--) { s->failed_pc=0x0c097c30u; return 0; }
target=r[2];
r[16]=code_base|0x0c097c34u;
r[4]=read(ram,r[13]+16,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c097c34u) { target=s->pc; goto dispatch; }
goto P_0c097c34;
P_0c097c32: /* original 54d4, guest PC 0x0c097c32 */
if(!s->budget--) { s->failed_pc=0x0c097c32u; return 0; }
r[4]=read(ram,r[13]+16,4);
goto P_0c097c34;
P_0c097c34: /* original d334, guest PC 0x0c097c34 */
if(!s->budget--) { s->failed_pc=0x0c097c34u; return 0; }
r[3]=read(ram,0x0c097d08u,4);
goto P_0c097c36;
P_0c097c36: /* original 430b, guest PC 0x0c097c36 */
if(!s->budget--) { s->failed_pc=0x0c097c36u; return 0; }
target=r[3];
r[16]=code_base|0x0c097c3au;
r[4]=read(ram,r[13]+20,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c097c3au) { target=s->pc; goto dispatch; }
goto P_0c097c3a;
P_0c097c38: /* original 54d5, guest PC 0x0c097c38 */
if(!s->budget--) { s->failed_pc=0x0c097c38u; return 0; }
r[4]=read(ram,r[13]+20,4);
goto P_0c097c3a;
P_0c097c3a: /* original d333, guest PC 0x0c097c3a */
if(!s->budget--) { s->failed_pc=0x0c097c3au; return 0; }
r[3]=read(ram,0x0c097d08u,4);
goto P_0c097c3c;
P_0c097c3c: /* original e048, guest PC 0x0c097c3c */
if(!s->budget--) { s->failed_pc=0x0c097c3cu; return 0; }
r[0]=0x00000048u;
goto P_0c097c3e;
P_0c097c3e: /* original 430b, guest PC 0x0c097c3e */
if(!s->budget--) { s->failed_pc=0x0c097c3eu; return 0; }
target=r[3];
r[16]=code_base|0x0c097c42u;
r[4]=read(ram,r[13]+r[0],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c097c42u) { target=s->pc; goto dispatch; }
goto P_0c097c42;
P_0c097c40: /* original 04de, guest PC 0x0c097c40 */
if(!s->budget--) { s->failed_pc=0x0c097c40u; return 0; }
r[4]=read(ram,r[13]+r[0],4);
goto P_0c097c42;
P_0c097c42: /* original d331, guest PC 0x0c097c42 */
if(!s->budget--) { s->failed_pc=0x0c097c42u; return 0; }
r[3]=read(ram,0x0c097d08u,4);
goto P_0c097c44;
P_0c097c44: /* original e05c, guest PC 0x0c097c44 */
if(!s->budget--) { s->failed_pc=0x0c097c44u; return 0; }
r[0]=0x0000005cu;
goto P_0c097c46;
P_0c097c46: /* original 430b, guest PC 0x0c097c46 */
if(!s->budget--) { s->failed_pc=0x0c097c46u; return 0; }
target=r[3];
r[16]=code_base|0x0c097c4au;
r[4]=read(ram,r[13]+r[0],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c097c4au) { target=s->pc; goto dispatch; }
goto P_0c097c4a;
P_0c097c48: /* original 04de, guest PC 0x0c097c48 */
if(!s->budget--) { s->failed_pc=0x0c097c48u; return 0; }
r[4]=read(ram,r[13]+r[0],4);
goto P_0c097c4a;
P_0c097c4a: /* original d32f, guest PC 0x0c097c4a */
if(!s->budget--) { s->failed_pc=0x0c097c4au; return 0; }
r[3]=read(ram,0x0c097d08u,4);
goto P_0c097c4c;
P_0c097c4c: /* original e060, guest PC 0x0c097c4c */
if(!s->budget--) { s->failed_pc=0x0c097c4cu; return 0; }
r[0]=0x00000060u;
goto P_0c097c4e;
P_0c097c4e: /* original 430b, guest PC 0x0c097c4e */
if(!s->budget--) { s->failed_pc=0x0c097c4eu; return 0; }
target=r[3];
r[16]=code_base|0x0c097c52u;
r[4]=read(ram,r[13]+r[0],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c097c52u) { target=s->pc; goto dispatch; }
goto P_0c097c52;
P_0c097c50: /* original 04de, guest PC 0x0c097c50 */
if(!s->budget--) { s->failed_pc=0x0c097c50u; return 0; }
r[4]=read(ram,r[13]+r[0],4);
goto P_0c097c52;
P_0c097c52: /* original d32d, guest PC 0x0c097c52 */
if(!s->budget--) { s->failed_pc=0x0c097c52u; return 0; }
r[3]=read(ram,0x0c097d08u,4);
goto P_0c097c54;
P_0c097c54: /* original e064, guest PC 0x0c097c54 */
if(!s->budget--) { s->failed_pc=0x0c097c54u; return 0; }
r[0]=0x00000064u;
goto P_0c097c56;
P_0c097c56: /* original 430b, guest PC 0x0c097c56 */
if(!s->budget--) { s->failed_pc=0x0c097c56u; return 0; }
target=r[3];
r[16]=code_base|0x0c097c5au;
r[4]=read(ram,r[13]+r[0],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c097c5au) { target=s->pc; goto dispatch; }
goto P_0c097c5a;
P_0c097c58: /* original 04de, guest PC 0x0c097c58 */
if(!s->budget--) { s->failed_pc=0x0c097c58u; return 0; }
r[4]=read(ram,r[13]+r[0],4);
goto P_0c097c5a;
P_0c097c5a: /* original d32b, guest PC 0x0c097c5a */
if(!s->budget--) { s->failed_pc=0x0c097c5au; return 0; }
r[3]=read(ram,0x0c097d08u,4);
goto P_0c097c5c;
P_0c097c5c: /* original e060, guest PC 0x0c097c5c */
if(!s->budget--) { s->failed_pc=0x0c097c5cu; return 0; }
r[0]=0x00000060u;
goto P_0c097c5e;
P_0c097c5e: /* original 430b, guest PC 0x0c097c5e */
if(!s->budget--) { s->failed_pc=0x0c097c5eu; return 0; }
target=r[3];
r[16]=code_base|0x0c097c62u;
r[4]=read(ram,r[13]+r[0],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c097c62u) { target=s->pc; goto dispatch; }
goto P_0c097c62;
P_0c097c60: /* original 04de, guest PC 0x0c097c60 */
if(!s->budget--) { s->failed_pc=0x0c097c60u; return 0; }
r[4]=read(ram,r[13]+r[0],4);
goto P_0c097c62;
P_0c097c62: /* original d329, guest PC 0x0c097c62 */
if(!s->budget--) { s->failed_pc=0x0c097c62u; return 0; }
r[3]=read(ram,0x0c097d08u,4);
goto P_0c097c64;
P_0c097c64: /* original e064, guest PC 0x0c097c64 */
if(!s->budget--) { s->failed_pc=0x0c097c64u; return 0; }
r[0]=0x00000064u;
goto P_0c097c66;
P_0c097c66: /* original 430b, guest PC 0x0c097c66 */
if(!s->budget--) { s->failed_pc=0x0c097c66u; return 0; }
target=r[3];
r[16]=code_base|0x0c097c6au;
r[4]=read(ram,r[13]+r[0],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c097c6au) { target=s->pc; goto dispatch; }
goto P_0c097c6a;
P_0c097c68: /* original 04de, guest PC 0x0c097c68 */
if(!s->budget--) { s->failed_pc=0x0c097c68u; return 0; }
r[4]=read(ram,r[13]+r[0],4);
goto P_0c097c6a;
P_0c097c6a: /* original d327, guest PC 0x0c097c6a */
if(!s->budget--) { s->failed_pc=0x0c097c6au; return 0; }
r[3]=read(ram,0x0c097d08u,4);
goto P_0c097c6c;
P_0c097c6c: /* original e054, guest PC 0x0c097c6c */
if(!s->budget--) { s->failed_pc=0x0c097c6cu; return 0; }
r[0]=0x00000054u;
goto P_0c097c6e;
P_0c097c6e: /* original 430b, guest PC 0x0c097c6e */
if(!s->budget--) { s->failed_pc=0x0c097c6eu; return 0; }
target=r[3];
r[16]=code_base|0x0c097c72u;
r[4]=read(ram,r[13]+r[0],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c097c72u) { target=s->pc; goto dispatch; }
goto P_0c097c72;
P_0c097c70: /* original 04de, guest PC 0x0c097c70 */
if(!s->budget--) { s->failed_pc=0x0c097c70u; return 0; }
r[4]=read(ram,r[13]+r[0],4);
goto P_0c097c72;
P_0c097c72: /* original e017, guest PC 0x0c097c72 */
if(!s->budget--) { s->failed_pc=0x0c097c72u; return 0; }
r[0]=0x00000017u;
goto P_0c097c74;
P_0c097c74: /* original d325, guest PC 0x0c097c74 */
if(!s->budget--) { s->failed_pc=0x0c097c74u; return 0; }
r[3]=read(ram,0x0c097d0cu,4);
goto P_0c097c76;
P_0c097c76: /* original 62a2, guest PC 0x0c097c76 */
if(!s->budget--) { s->failed_pc=0x0c097c76u; return 0; }
tmp=read(ram,r[10],4);
r[2]=tmp;
goto P_0c097c78;
P_0c097c78: /* original 2239, guest PC 0x0c097c78 */
if(!s->budget--) { s->failed_pc=0x0c097c78u; return 0; }
r[2]&=r[3];
goto P_0c097c7a;
P_0c097c7a: /* original 2a22, guest PC 0x0c097c7a */
if(!s->budget--) { s->failed_pc=0x0c097c7au; return 0; }
write(ram,r[10],r[2],4);
goto P_0c097c7c;
P_0c097c7c: /* original 80ea, guest PC 0x0c097c7c */
if(!s->budget--) { s->failed_pc=0x0c097c7cu; return 0; }
write(ram,r[14]+10,r[0],1);
goto P_0c097c7e;
P_0c097c7e: /* original 6093, guest PC 0x0c097c7e */
if(!s->budget--) { s->failed_pc=0x0c097c7eu; return 0; }
r[0]=r[9];
goto P_0c097c80;
P_0c097c80: /* original 80eb, guest PC 0x0c097c80 */
if(!s->budget--) { s->failed_pc=0x0c097c80u; return 0; }
write(ram,r[14]+11,r[0],1);
goto P_0c097c82;
P_0c097c82: /* original 901f, guest PC 0x0c097c82 */
if(!s->budget--) { s->failed_pc=0x0c097c82u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c097cc4u,2);
goto P_0c097c84;
P_0c097c84: /* original a177, guest PC 0x0c097c84 */
if(!s->budget--) { s->failed_pc=0x0c097c84u; return 0; }
goto P_0c097f76;
P_0c097c86: /* original 0009, guest PC 0x0c097c86 */
if(!s->budget--) { s->failed_pc=0x0c097c86u; return 0; }
goto P_0c097c88;
P_0c097c88: /* original 63a2, guest PC 0x0c097c88 */
if(!s->budget--) { s->failed_pc=0x0c097c88u; return 0; }
tmp=read(ram,r[10],4);
r[3]=tmp;
goto P_0c097c8a;
P_0c097c8a: /* original 2388, guest PC 0x0c097c8a */
if(!s->budget--) { s->failed_pc=0x0c097c8au; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[8])==0)!=0);
goto P_0c097c8c;
P_0c097c8c: /* original 8902, guest PC 0x0c097c8c */
if(!s->budget--) { s->failed_pc=0x0c097c8cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c097c94; }
goto P_0c097c8e;
P_0c097c8e: /* original 9d1a, guest PC 0x0c097c8e */
if(!s->budget--) { s->failed_pc=0x0c097c8eu; return 0; }
r[13]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c097cc6u,2);
goto P_0c097c90;
P_0c097c90: /* original a002, guest PC 0x0c097c90 */
if(!s->budget--) { s->failed_pc=0x0c097c90u; return 0; }
r[5]=r[9];
goto P_0c097c98;
P_0c097c92: /* original 6593, guest PC 0x0c097c92 */
if(!s->budget--) { s->failed_pc=0x0c097c92u; return 0; }
r[5]=r[9];
goto P_0c097c94;
P_0c097c94: /* original 9d18, guest PC 0x0c097c94 */
if(!s->budget--) { s->failed_pc=0x0c097c94u; return 0; }
r[13]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c097cc8u,2);
goto P_0c097c96;
P_0c097c96: /* original e52c, guest PC 0x0c097c96 */
if(!s->budget--) { s->failed_pc=0x0c097c96u; return 0; }
r[5]=0x0000002cu;
goto P_0c097c98;
P_0c097c98: /* original 9017, guest PC 0x0c097c98 */
if(!s->budget--) { s->failed_pc=0x0c097c98u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c097ccau,2);
goto P_0c097c9a;
P_0c097c9a: /* original 02ec, guest PC 0x0c097c9a */
if(!s->budget--) { s->failed_pc=0x0c097c9au; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c097c9c;
P_0c097c9c: /* original 2228, guest PC 0x0c097c9c */
if(!s->budget--) { s->failed_pc=0x0c097c9cu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c097c9e;
P_0c097c9e: /* original 893b, guest PC 0x0c097c9e */
if(!s->budget--) { s->failed_pc=0x0c097c9eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c097d18; }
goto P_0c097ca0;
P_0c097ca0: /* original 9314, guest PC 0x0c097ca0 */
if(!s->budget--) { s->failed_pc=0x0c097ca0u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c097cccu,2);
goto P_0c097ca2;
P_0c097ca2: /* original 4500, guest PC 0x0c097ca2 */
if(!s->budget--) { s->failed_pc=0x0c097ca2u; return 0; }
r[17]=(r[17]&~1u)|((r[5]>>31)!=0);
r[5]<<=1;
goto P_0c097ca4;
P_0c097ca4: /* original e220, guest PC 0x0c097ca4 */
if(!s->budget--) { s->failed_pc=0x0c097ca4u; return 0; }
r[2]=0x00000020u;
goto P_0c097ca6;
P_0c097ca6: /* original d41a, guest PC 0x0c097ca6 */
if(!s->budget--) { s->failed_pc=0x0c097ca6u; return 0; }
r[4]=read(ram,0x0c097d10u,4);
goto P_0c097ca8;
P_0c097ca8: /* original 253b, guest PC 0x0c097ca8 */
if(!s->budget--) { s->failed_pc=0x0c097ca8u; return 0; }
r[5]|=r[3];
goto P_0c097caa;
P_0c097caa: /* original 6723, guest PC 0x0c097caa */
if(!s->budget--) { s->failed_pc=0x0c097caau; return 0; }
r[7]=r[2];
goto P_0c097cac;
P_0c097cac: /* original 1f51, guest PC 0x0c097cac */
if(!s->budget--) { s->failed_pc=0x0c097cacu; return 0; }
write(ram,r[15]+4,r[5],4);
goto P_0c097cae;
P_0c097cae: /* original e610, guest PC 0x0c097cae */
if(!s->budget--) { s->failed_pc=0x0c097caeu; return 0; }
r[6]=0x00000010u;
goto P_0c097cb0;
P_0c097cb0: /* original 2f26, guest PC 0x0c097cb0 */
if(!s->budget--) { s->failed_pc=0x0c097cb0u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c097cb2;
P_0c097cb2: /* original d118, guest PC 0x0c097cb2 */
if(!s->budget--) { s->failed_pc=0x0c097cb2u; return 0; }
r[1]=read(ram,0x0c097d14u,4);
goto P_0c097cb4;
P_0c097cb4: /* original 410b, guest PC 0x0c097cb4 */
if(!s->budget--) { s->failed_pc=0x0c097cb4u; return 0; }
target=r[1];
r[16]=code_base|0x0c097cb8u;
r[5]=read(ram,r[15]+8,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c097cb8u) { target=s->pc; goto dispatch; }
goto P_0c097cb8;
P_0c097cb6: /* original 55f2, guest PC 0x0c097cb6 */
if(!s->budget--) { s->failed_pc=0x0c097cb6u; return 0; }
r[5]=read(ram,r[15]+8,4);
goto P_0c097cb8;
P_0c097cb8: /* original 53c2, guest PC 0x0c097cb8 */
if(!s->budget--) { s->failed_pc=0x0c097cb8u; return 0; }
r[3]=read(ram,r[12]+8,4);
goto P_0c097cba;
P_0c097cba: /* original 6dd7, guest PC 0x0c097cba */
if(!s->budget--) { s->failed_pc=0x0c097cbau; return 0; }
r[13]=~r[13];
goto P_0c097cbc;
P_0c097cbc: /* original 7f04, guest PC 0x0c097cbc */
if(!s->budget--) { s->failed_pc=0x0c097cbcu; return 0; }
r[15]+=0x00000004u;
goto P_0c097cbe;
P_0c097cbe: /* original 23d9, guest PC 0x0c097cbe */
if(!s->budget--) { s->failed_pc=0x0c097cbeu; return 0; }
r[3]&=r[13];
goto P_0c097cc0;
P_0c097cc0: /* original a02d, guest PC 0x0c097cc0 */
if(!s->budget--) { s->failed_pc=0x0c097cc0u; return 0; }
write(ram,r[12]+8,r[3],4);
goto P_0c097d1e;
P_0c097cc2: /* original 1c32, guest PC 0x0c097cc2 */
if(!s->budget--) { s->failed_pc=0x0c097cc2u; return 0; }
write(ram,r[12]+8,r[3],4);
return vf3_matrix_family(0x0c097cc4u,s,ram);
P_0c097d18: /* original 51c2, guest PC 0x0c097d18 */
if(!s->budget--) { s->failed_pc=0x0c097d18u; return 0; }
r[1]=read(ram,r[12]+8,4);
goto P_0c097d1a;
P_0c097d1a: /* original 21db, guest PC 0x0c097d1a */
if(!s->budget--) { s->failed_pc=0x0c097d1au; return 0; }
r[1]|=r[13];
goto P_0c097d1c;
P_0c097d1c: /* original 1c12, guest PC 0x0c097d1c */
if(!s->budget--) { s->failed_pc=0x0c097d1cu; return 0; }
write(ram,r[12]+8,r[1],4);
goto P_0c097d1e;
P_0c097d1e: /* original 9067, guest PC 0x0c097d1e */
if(!s->budget--) { s->failed_pc=0x0c097d1eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c097df0u,2);
goto P_0c097d20;
P_0c097d20: /* original 03ec, guest PC 0x0c097d20 */
if(!s->budget--) { s->failed_pc=0x0c097d20u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c097d22;
P_0c097d22: /* original 2338, guest PC 0x0c097d22 */
if(!s->budget--) { s->failed_pc=0x0c097d22u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c097d24;
P_0c097d24: /* original 8d14, guest PC 0x0c097d24 */
if(!s->budget--) { s->failed_pc=0x0c097d24u; return 0; }
cond=r[17]&1u;
tmp=read(ram,r[10],4);
r[4]=tmp;
if(cond) { goto P_0c097d50; }
goto P_0c097d28;
P_0c097d26: /* original 64a2, guest PC 0x0c097d26 */
if(!s->budget--) { s->failed_pc=0x0c097d26u; return 0; }
tmp=read(ram,r[10],4);
r[4]=tmp;
goto P_0c097d28;
P_0c097d28: /* original 6343, guest PC 0x0c097d28 */
if(!s->budget--) { s->failed_pc=0x0c097d28u; return 0; }
r[3]=r[4];
goto P_0c097d2a;
P_0c097d2a: /* original 2388, guest PC 0x0c097d2a */
if(!s->budget--) { s->failed_pc=0x0c097d2au; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[8])==0)!=0);
goto P_0c097d2c;
P_0c097d2c: /* original 8906, guest PC 0x0c097d2c */
if(!s->budget--) { s->failed_pc=0x0c097d2cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c097d3c; }
goto P_0c097d2e;
P_0c097d2e: /* original 9060, guest PC 0x0c097d2e */
if(!s->budget--) { s->failed_pc=0x0c097d2eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c097df2u,2);
goto P_0c097d30;
P_0c097d30: /* original d332, guest PC 0x0c097d30 */
if(!s->budget--) { s->failed_pc=0x0c097d30u; return 0; }
r[3]=read(ram,0x0c097dfcu,4);
goto P_0c097d32;
P_0c097d32: /* original 02ee, guest PC 0x0c097d32 */
if(!s->budget--) { s->failed_pc=0x0c097d32u; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c097d34;
P_0c097d34: /* original 2238, guest PC 0x0c097d34 */
if(!s->budget--) { s->failed_pc=0x0c097d34u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c097d36;
P_0c097d36: /* original 8901, guest PC 0x0c097d36 */
if(!s->budget--) { s->failed_pc=0x0c097d36u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c097d3c; }
goto P_0c097d38;
P_0c097d38: /* original a151, guest PC 0x0c097d38 */
if(!s->budget--) { s->failed_pc=0x0c097d38u; return 0; }
goto P_0c097fde;
P_0c097d3a: /* original 0009, guest PC 0x0c097d3a */
if(!s->budget--) { s->failed_pc=0x0c097d3au; return 0; }
goto P_0c097d3c;
P_0c097d3c: /* original d330, guest PC 0x0c097d3c */
if(!s->budget--) { s->failed_pc=0x0c097d3cu; return 0; }
r[3]=read(ram,0x0c097e00u,4);
goto P_0c097d3e;
P_0c097d3e: /* original 2348, guest PC 0x0c097d3e */
if(!s->budget--) { s->failed_pc=0x0c097d3eu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[4])==0)!=0);
goto P_0c097d40;
P_0c097d40: /* original 891c, guest PC 0x0c097d40 */
if(!s->budget--) { s->failed_pc=0x0c097d40u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c097d7c; }
goto P_0c097d42;
P_0c097d42: /* original 9056, guest PC 0x0c097d42 */
if(!s->budget--) { s->failed_pc=0x0c097d42u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c097df2u,2);
goto P_0c097d44;
P_0c097d44: /* original 9356, guest PC 0x0c097d44 */
if(!s->budget--) { s->failed_pc=0x0c097d44u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c097df4u,2);
goto P_0c097d46;
P_0c097d46: /* original 02ee, guest PC 0x0c097d46 */
if(!s->budget--) { s->failed_pc=0x0c097d46u; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c097d48;
P_0c097d48: /* original 2238, guest PC 0x0c097d48 */
if(!s->budget--) { s->failed_pc=0x0c097d48u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c097d4a;
P_0c097d4a: /* original 8917, guest PC 0x0c097d4a */
if(!s->budget--) { s->failed_pc=0x0c097d4au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c097d7c; }
goto P_0c097d4c;
P_0c097d4c: /* original a147, guest PC 0x0c097d4c */
if(!s->budget--) { s->failed_pc=0x0c097d4cu; return 0; }
goto P_0c097fde;
P_0c097d4e: /* original 0009, guest PC 0x0c097d4e */
if(!s->budget--) { s->failed_pc=0x0c097d4eu; return 0; }
goto P_0c097d50;
P_0c097d50: /* original 61f2, guest PC 0x0c097d50 */
if(!s->budget--) { s->failed_pc=0x0c097d50u; return 0; }
tmp=read(ram,r[15],4);
r[1]=tmp;
goto P_0c097d52;
P_0c097d52: /* original 6312, guest PC 0x0c097d52 */
if(!s->budget--) { s->failed_pc=0x0c097d52u; return 0; }
tmp=read(ram,r[1],4);
r[3]=tmp;
goto P_0c097d54;
P_0c097d54: /* original 2398, guest PC 0x0c097d54 */
if(!s->budget--) { s->failed_pc=0x0c097d54u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[9])==0)!=0);
goto P_0c097d56;
P_0c097d56: /* original 8906, guest PC 0x0c097d56 */
if(!s->budget--) { s->failed_pc=0x0c097d56u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c097d66; }
goto P_0c097d58;
P_0c097d58: /* original 904b, guest PC 0x0c097d58 */
if(!s->budget--) { s->failed_pc=0x0c097d58u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c097df2u,2);
goto P_0c097d5a;
P_0c097d5a: /* original d328, guest PC 0x0c097d5a */
if(!s->budget--) { s->failed_pc=0x0c097d5au; return 0; }
r[3]=read(ram,0x0c097dfcu,4);
goto P_0c097d5c;
P_0c097d5c: /* original 02ee, guest PC 0x0c097d5c */
if(!s->budget--) { s->failed_pc=0x0c097d5cu; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c097d5e;
P_0c097d5e: /* original 2238, guest PC 0x0c097d5e */
if(!s->budget--) { s->failed_pc=0x0c097d5eu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c097d60;
P_0c097d60: /* original 8901, guest PC 0x0c097d60 */
if(!s->budget--) { s->failed_pc=0x0c097d60u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c097d66; }
goto P_0c097d62;
P_0c097d62: /* original a13c, guest PC 0x0c097d62 */
if(!s->budget--) { s->failed_pc=0x0c097d62u; return 0; }
goto P_0c097fde;
P_0c097d64: /* original 0009, guest PC 0x0c097d64 */
if(!s->budget--) { s->failed_pc=0x0c097d64u; return 0; }
goto P_0c097d66;
P_0c097d66: /* original 53f2, guest PC 0x0c097d66 */
if(!s->budget--) { s->failed_pc=0x0c097d66u; return 0; }
r[3]=read(ram,r[15]+8,4);
goto P_0c097d68;
P_0c097d68: /* original 6232, guest PC 0x0c097d68 */
if(!s->budget--) { s->failed_pc=0x0c097d68u; return 0; }
tmp=read(ram,r[3],4);
r[2]=tmp;
goto P_0c097d6a;
P_0c097d6a: /* original 2298, guest PC 0x0c097d6a */
if(!s->budget--) { s->failed_pc=0x0c097d6au; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[9])==0)!=0);
goto P_0c097d6c;
P_0c097d6c: /* original 8906, guest PC 0x0c097d6c */
if(!s->budget--) { s->failed_pc=0x0c097d6cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c097d7c; }
goto P_0c097d6e;
P_0c097d6e: /* original 9040, guest PC 0x0c097d6e */
if(!s->budget--) { s->failed_pc=0x0c097d6eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c097df2u,2);
goto P_0c097d70;
P_0c097d70: /* original 9340, guest PC 0x0c097d70 */
if(!s->budget--) { s->failed_pc=0x0c097d70u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c097df4u,2);
goto P_0c097d72;
P_0c097d72: /* original 01ee, guest PC 0x0c097d72 */
if(!s->budget--) { s->failed_pc=0x0c097d72u; return 0; }
r[1]=read(ram,r[14]+r[0],4);
goto P_0c097d74;
P_0c097d74: /* original 2138, guest PC 0x0c097d74 */
if(!s->budget--) { s->failed_pc=0x0c097d74u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[3])==0)!=0);
goto P_0c097d76;
P_0c097d76: /* original 8901, guest PC 0x0c097d76 */
if(!s->budget--) { s->failed_pc=0x0c097d76u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c097d7c; }
goto P_0c097d78;
P_0c097d78: /* original a131, guest PC 0x0c097d78 */
if(!s->budget--) { s->failed_pc=0x0c097d78u; return 0; }
goto P_0c097fde;
P_0c097d7a: /* original 0009, guest PC 0x0c097d7a */
if(!s->budget--) { s->failed_pc=0x0c097d7au; return 0; }
goto P_0c097d7c;
P_0c097d7c: /* original 2488, guest PC 0x0c097d7c */
if(!s->budget--) { s->failed_pc=0x0c097d7cu; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[8])==0)!=0);
goto P_0c097d7e;
P_0c097d7e: /* original 8901, guest PC 0x0c097d7e */
if(!s->budget--) { s->failed_pc=0x0c097d7eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c097d84; }
goto P_0c097d80;
P_0c097d80: /* original a001, guest PC 0x0c097d80 */
if(!s->budget--) { s->failed_pc=0x0c097d80u; return 0; }
r[4]=0x00000000u;
goto P_0c097d86;
P_0c097d82: /* original e400, guest PC 0x0c097d82 */
if(!s->budget--) { s->failed_pc=0x0c097d82u; return 0; }
r[4]=0x00000000u;
goto P_0c097d84;
P_0c097d84: /* original e401, guest PC 0x0c097d84 */
if(!s->budget--) { s->failed_pc=0x0c097d84u; return 0; }
r[4]=0x00000001u;
goto P_0c097d86;
P_0c097d86: /* original d21f, guest PC 0x0c097d86 */
if(!s->budget--) { s->failed_pc=0x0c097d86u; return 0; }
r[2]=read(ram,0x0c097e04u,4);
goto P_0c097d88;
P_0c097d88: /* original 420b, guest PC 0x0c097d88 */
if(!s->budget--) { s->failed_pc=0x0c097d88u; return 0; }
target=r[2];
r[16]=code_base|0x0c097d8cu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c097d8cu) { target=s->pc; goto dispatch; }
goto P_0c097d8c;
P_0c097d8a: /* original 0009, guest PC 0x0c097d8a */
if(!s->budget--) { s->failed_pc=0x0c097d8au; return 0; }
goto P_0c097d8c;
P_0c097d8c: /* original 6403, guest PC 0x0c097d8c */
if(!s->budget--) { s->failed_pc=0x0c097d8cu; return 0; }
r[4]=r[0];
goto P_0c097d8e;
P_0c097d8e: /* original 902f, guest PC 0x0c097d8e */
if(!s->budget--) { s->failed_pc=0x0c097d8eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c097df0u,2);
goto P_0c097d90;
P_0c097d90: /* original 03ec, guest PC 0x0c097d90 */
if(!s->budget--) { s->failed_pc=0x0c097d90u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c097d92;
P_0c097d92: /* original 2338, guest PC 0x0c097d92 */
if(!s->budget--) { s->failed_pc=0x0c097d92u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c097d94;
P_0c097d94: /* original 8d02, guest PC 0x0c097d94 */
if(!s->budget--) { s->failed_pc=0x0c097d94u; return 0; }
cond=r[17]&1u;
r[13]=read(ram,r[4]+8,4);
if(cond) { goto P_0c097d9c; }
goto P_0c097d98;
P_0c097d96: /* original 5d42, guest PC 0x0c097d96 */
if(!s->budget--) { s->failed_pc=0x0c097d96u; return 0; }
r[13]=read(ram,r[4]+8,4);
goto P_0c097d98;
P_0c097d98: /* original a0d7, guest PC 0x0c097d98 */
if(!s->budget--) { s->failed_pc=0x0c097d98u; return 0; }
goto P_0c097f4a;
P_0c097d9a: /* original 0009, guest PC 0x0c097d9a */
if(!s->budget--) { s->failed_pc=0x0c097d9au; return 0; }
goto P_0c097d9c;
P_0c097d9c: /* original e310, guest PC 0x0c097d9c */
if(!s->budget--) { s->failed_pc=0x0c097d9cu; return 0; }
r[3]=0x00000010u;
goto P_0c097d9e;
P_0c097d9e: /* original d81a, guest PC 0x0c097d9e */
if(!s->budget--) { s->failed_pc=0x0c097d9eu; return 0; }
r[8]=read(ram,0x0c097e08u,4);
goto P_0c097da0;
P_0c097da0: /* original 23d8, guest PC 0x0c097da0 */
if(!s->budget--) { s->failed_pc=0x0c097da0u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[13])==0)!=0);
goto P_0c097da2;
P_0c097da2: /* original 8915, guest PC 0x0c097da2 */
if(!s->budget--) { s->failed_pc=0x0c097da2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c097dd0; }
goto P_0c097da4;
P_0c097da4: /* original 9427, guest PC 0x0c097da4 */
if(!s->budget--) { s->failed_pc=0x0c097da4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c097df6u,2);
goto P_0c097da6;
P_0c097da6: /* original 480b, guest PC 0x0c097da6 */
if(!s->budget--) { s->failed_pc=0x0c097da6u; return 0; }
target=r[8];
r[16]=code_base|0x0c097daau;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c097daau) { target=s->pc; goto dispatch; }
goto P_0c097daa;
P_0c097da8: /* original 0009, guest PC 0x0c097da8 */
if(!s->budget--) { s->failed_pc=0x0c097da8u; return 0; }
goto P_0c097daa;
P_0c097daa: /* original 9025, guest PC 0x0c097daa */
if(!s->budget--) { s->failed_pc=0x0c097daau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c097df8u,2);
goto P_0c097dac;
P_0c097dac: /* original 00ec, guest PC 0x0c097dac */
if(!s->budget--) { s->failed_pc=0x0c097dacu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c097dae;
P_0c097dae: /* original 8801, guest PC 0x0c097dae */
if(!s->budget--) { s->failed_pc=0x0c097daeu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c097db0;
P_0c097db0: /* original 8905, guest PC 0x0c097db0 */
if(!s->budget--) { s->failed_pc=0x0c097db0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c097dbe; }
goto P_0c097db2;
P_0c097db2: /* original 9022, guest PC 0x0c097db2 */
if(!s->budget--) { s->failed_pc=0x0c097db2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c097dfau,2);
goto P_0c097db4;
P_0c097db4: /* original 02ec, guest PC 0x0c097db4 */
if(!s->budget--) { s->failed_pc=0x0c097db4u; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c097db6;
P_0c097db6: /* original 622b, guest PC 0x0c097db6 */
if(!s->budget--) { s->failed_pc=0x0c097db6u; return 0; }
r[2]=0u-r[2];
goto P_0c097db8;
P_0c097db8: /* original 7201, guest PC 0x0c097db8 */
if(!s->budget--) { s->failed_pc=0x0c097db8u; return 0; }
r[2]+=0x00000001u;
goto P_0c097dba;
P_0c097dba: /* original a009, guest PC 0x0c097dba */
if(!s->budget--) { s->failed_pc=0x0c097dbau; return 0; }
write(ram,r[14]+r[0],r[2],1);
goto P_0c097dd0;
P_0c097dbc: /* original 0e24, guest PC 0x0c097dbc */
if(!s->budget--) { s->failed_pc=0x0c097dbcu; return 0; }
write(ram,r[14]+r[0],r[2],1);
goto P_0c097dbe;
P_0c097dbe: /* original 901c, guest PC 0x0c097dbe */
if(!s->budget--) { s->failed_pc=0x0c097dbeu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c097dfau,2);
goto P_0c097dc0;
P_0c097dc0: /* original 01ec, guest PC 0x0c097dc0 */
if(!s->budget--) { s->failed_pc=0x0c097dc0u; return 0; }
r[1]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c097dc2;
P_0c097dc2: /* original 2118, guest PC 0x0c097dc2 */
if(!s->budget--) { s->failed_pc=0x0c097dc2u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[1])==0)!=0);
goto P_0c097dc4;
P_0c097dc4: /* original 8b01, guest PC 0x0c097dc4 */
if(!s->budget--) { s->failed_pc=0x0c097dc4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c097dca; }
goto P_0c097dc6;
P_0c097dc6: /* original a002, guest PC 0x0c097dc6 */
if(!s->budget--) { s->failed_pc=0x0c097dc6u; return 0; }
r[2]=0x00000003u;
goto P_0c097dce;
P_0c097dc8: /* original e203, guest PC 0x0c097dc8 */
if(!s->budget--) { s->failed_pc=0x0c097dc8u; return 0; }
r[2]=0x00000003u;
goto P_0c097dca;
P_0c097dca: /* original 02ec, guest PC 0x0c097dca */
if(!s->budget--) { s->failed_pc=0x0c097dcau; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c097dcc;
P_0c097dcc: /* original 72ff, guest PC 0x0c097dcc */
if(!s->budget--) { s->failed_pc=0x0c097dccu; return 0; }
r[2]+=0xffffffffu;
goto P_0c097dce;
P_0c097dce: /* original 0e24, guest PC 0x0c097dce */
if(!s->budget--) { s->failed_pc=0x0c097dceu; return 0; }
write(ram,r[14]+r[0],r[2],1);
goto P_0c097dd0;
P_0c097dd0: /* original e320, guest PC 0x0c097dd0 */
if(!s->budget--) { s->failed_pc=0x0c097dd0u; return 0; }
r[3]=0x00000020u;
goto P_0c097dd2;
P_0c097dd2: /* original 23d8, guest PC 0x0c097dd2 */
if(!s->budget--) { s->failed_pc=0x0c097dd2u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[13])==0)!=0);
goto P_0c097dd4;
P_0c097dd4: /* original 8923, guest PC 0x0c097dd4 */
if(!s->budget--) { s->failed_pc=0x0c097dd4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c097e1e; }
goto P_0c097dd6;
P_0c097dd6: /* original 940e, guest PC 0x0c097dd6 */
if(!s->budget--) { s->failed_pc=0x0c097dd6u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c097df6u,2);
goto P_0c097dd8;
P_0c097dd8: /* original 480b, guest PC 0x0c097dd8 */
if(!s->budget--) { s->failed_pc=0x0c097dd8u; return 0; }
target=r[8];
r[16]=code_base|0x0c097ddcu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c097ddcu) { target=s->pc; goto dispatch; }
goto P_0c097ddc;
P_0c097dda: /* original 0009, guest PC 0x0c097dda */
if(!s->budget--) { s->failed_pc=0x0c097ddau; return 0; }
goto P_0c097ddc;
P_0c097ddc: /* original 900c, guest PC 0x0c097ddc */
if(!s->budget--) { s->failed_pc=0x0c097ddcu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c097df8u,2);
goto P_0c097dde;
P_0c097dde: /* original 00ec, guest PC 0x0c097dde */
if(!s->budget--) { s->failed_pc=0x0c097ddeu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c097de0;
P_0c097de0: /* original 8801, guest PC 0x0c097de0 */
if(!s->budget--) { s->failed_pc=0x0c097de0u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c097de2;
P_0c097de2: /* original 8913, guest PC 0x0c097de2 */
if(!s->budget--) { s->failed_pc=0x0c097de2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c097e0c; }
goto P_0c097de4;
P_0c097de4: /* original 9009, guest PC 0x0c097de4 */
if(!s->budget--) { s->failed_pc=0x0c097de4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c097dfau,2);
goto P_0c097de6;
P_0c097de6: /* original 02ec, guest PC 0x0c097de6 */
if(!s->budget--) { s->failed_pc=0x0c097de6u; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c097de8;
P_0c097de8: /* original 622b, guest PC 0x0c097de8 */
if(!s->budget--) { s->failed_pc=0x0c097de8u; return 0; }
r[2]=0u-r[2];
goto P_0c097dea;
P_0c097dea: /* original 7201, guest PC 0x0c097dea */
if(!s->budget--) { s->failed_pc=0x0c097deau; return 0; }
r[2]+=0x00000001u;
goto P_0c097dec;
P_0c097dec: /* original a017, guest PC 0x0c097dec */
if(!s->budget--) { s->failed_pc=0x0c097decu; return 0; }
write(ram,r[14]+r[0],r[2],1);
goto P_0c097e1e;
P_0c097dee: /* original 0e24, guest PC 0x0c097dee */
if(!s->budget--) { s->failed_pc=0x0c097deeu; return 0; }
write(ram,r[14]+r[0],r[2],1);
return vf3_matrix_family(0x0c097df0u,s,ram);
P_0c097e0c: /* original 904b, guest PC 0x0c097e0c */
if(!s->budget--) { s->failed_pc=0x0c097e0cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c097ea6u,2);
goto P_0c097e0e;
P_0c097e0e: /* original e303, guest PC 0x0c097e0e */
if(!s->budget--) { s->failed_pc=0x0c097e0eu; return 0; }
r[3]=0x00000003u;
goto P_0c097e10;
P_0c097e10: /* original 01ec, guest PC 0x0c097e10 */
if(!s->budget--) { s->failed_pc=0x0c097e10u; return 0; }
r[1]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c097e12;
P_0c097e12: /* original 3133, guest PC 0x0c097e12 */
if(!s->budget--) { s->failed_pc=0x0c097e12u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[1]>=(int32_t)r[3])!=0);
goto P_0c097e14;
P_0c097e14: /* original 8b01, guest PC 0x0c097e14 */
if(!s->budget--) { s->failed_pc=0x0c097e14u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c097e1a; }
goto P_0c097e16;
P_0c097e16: /* original a002, guest PC 0x0c097e16 */
if(!s->budget--) { s->failed_pc=0x0c097e16u; return 0; }
write(ram,r[14]+r[0],r[11],1);
goto P_0c097e1e;
P_0c097e18: /* original 0eb4, guest PC 0x0c097e18 */
if(!s->budget--) { s->failed_pc=0x0c097e18u; return 0; }
write(ram,r[14]+r[0],r[11],1);
goto P_0c097e1a;
P_0c097e1a: /* original 7101, guest PC 0x0c097e1a */
if(!s->budget--) { s->failed_pc=0x0c097e1au; return 0; }
r[1]+=0x00000001u;
goto P_0c097e1c;
P_0c097e1c: /* original 0e14, guest PC 0x0c097e1c */
if(!s->budget--) { s->failed_pc=0x0c097e1cu; return 0; }
write(ram,r[14]+r[0],r[1],1);
goto P_0c097e1e;
P_0c097e1e: /* original 9343, guest PC 0x0c097e1e */
if(!s->budget--) { s->failed_pc=0x0c097e1eu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c097ea8u,2);
goto P_0c097e20;
P_0c097e20: /* original 23d8, guest PC 0x0c097e20 */
if(!s->budget--) { s->failed_pc=0x0c097e20u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[13])==0)!=0);
goto P_0c097e22;
P_0c097e22: /* original 894b, guest PC 0x0c097e22 */
if(!s->budget--) { s->failed_pc=0x0c097e22u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c097ebc; }
goto P_0c097e24;
P_0c097e24: /* original 480b, guest PC 0x0c097e24 */
if(!s->budget--) { s->failed_pc=0x0c097e24u; return 0; }
target=r[8];
r[16]=code_base|0x0c097e28u;
r[4]=0x0000007fu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c097e28u) { target=s->pc; goto dispatch; }
goto P_0c097e28;
P_0c097e26: /* original e47f, guest PC 0x0c097e26 */
if(!s->budget--) { s->failed_pc=0x0c097e26u; return 0; }
r[4]=0x0000007fu;
goto P_0c097e28;
P_0c097e28: /* original 903d, guest PC 0x0c097e28 */
if(!s->budget--) { s->failed_pc=0x0c097e28u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c097ea6u,2);
goto P_0c097e2a;
P_0c097e2a: /* original 00ec, guest PC 0x0c097e2a */
if(!s->budget--) { s->failed_pc=0x0c097e2au; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c097e2c;
P_0c097e2c: /* original 8800, guest PC 0x0c097e2c */
if(!s->budget--) { s->failed_pc=0x0c097e2cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000000u)!=0);
goto P_0c097e2e;
P_0c097e2e: /* original 8907, guest PC 0x0c097e2e */
if(!s->budget--) { s->failed_pc=0x0c097e2eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c097e40; }
goto P_0c097e30;
P_0c097e30: /* original 8801, guest PC 0x0c097e30 */
if(!s->budget--) { s->failed_pc=0x0c097e30u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c097e32;
P_0c097e32: /* original 890b, guest PC 0x0c097e32 */
if(!s->budget--) { s->failed_pc=0x0c097e32u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c097e4c; }
goto P_0c097e34;
P_0c097e34: /* original 8802, guest PC 0x0c097e34 */
if(!s->budget--) { s->failed_pc=0x0c097e34u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c097e36;
P_0c097e36: /* original 8926, guest PC 0x0c097e36 */
if(!s->budget--) { s->failed_pc=0x0c097e36u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c097e86; }
goto P_0c097e38;
P_0c097e38: /* original 8803, guest PC 0x0c097e38 */
if(!s->budget--) { s->failed_pc=0x0c097e38u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000003u)!=0);
goto P_0c097e3a;
P_0c097e3a: /* original 892c, guest PC 0x0c097e3a */
if(!s->budget--) { s->failed_pc=0x0c097e3au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c097e96; }
goto P_0c097e3c;
P_0c097e3c: /* original a03e, guest PC 0x0c097e3c */
if(!s->budget--) { s->failed_pc=0x0c097e3cu; return 0; }
goto P_0c097ebc;
P_0c097e3e: /* original 0009, guest PC 0x0c097e3e */
if(!s->budget--) { s->failed_pc=0x0c097e3eu; return 0; }
goto P_0c097e40;
P_0c097e40: /* original 9033, guest PC 0x0c097e40 */
if(!s->budget--) { s->failed_pc=0x0c097e40u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c097eaau,2);
goto P_0c097e42;
P_0c097e42: /* original 03ec, guest PC 0x0c097e42 */
if(!s->budget--) { s->failed_pc=0x0c097e42u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c097e44;
P_0c097e44: /* original 633b, guest PC 0x0c097e44 */
if(!s->budget--) { s->failed_pc=0x0c097e44u; return 0; }
r[3]=0u-r[3];
goto P_0c097e46;
P_0c097e46: /* original 7301, guest PC 0x0c097e46 */
if(!s->budget--) { s->failed_pc=0x0c097e46u; return 0; }
r[3]+=0x00000001u;
goto P_0c097e48;
P_0c097e48: /* original a038, guest PC 0x0c097e48 */
if(!s->budget--) { s->failed_pc=0x0c097e48u; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c097ebc;
P_0c097e4a: /* original 0e34, guest PC 0x0c097e4a */
if(!s->budget--) { s->failed_pc=0x0c097e4au; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c097e4c;
P_0c097e4c: /* original 902e, guest PC 0x0c097e4c */
if(!s->budget--) { s->failed_pc=0x0c097e4cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c097eacu,2);
goto P_0c097e4e;
P_0c097e4e: /* original e309, guest PC 0x0c097e4e */
if(!s->budget--) { s->failed_pc=0x0c097e4eu; return 0; }
r[3]=0x00000009u;
goto P_0c097e50;
P_0c097e50: /* original 01ec, guest PC 0x0c097e50 */
if(!s->budget--) { s->failed_pc=0x0c097e50u; return 0; }
r[1]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c097e52;
P_0c097e52: /* original 3137, guest PC 0x0c097e52 */
if(!s->budget--) { s->failed_pc=0x0c097e52u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[1]>(int32_t)r[3])!=0);
goto P_0c097e54;
P_0c097e54: /* original 8b01, guest PC 0x0c097e54 */
if(!s->budget--) { s->failed_pc=0x0c097e54u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c097e5a; }
goto P_0c097e56;
P_0c097e56: /* original a002, guest PC 0x0c097e56 */
if(!s->budget--) { s->failed_pc=0x0c097e56u; return 0; }
write(ram,r[14]+r[0],r[11],1);
goto P_0c097e5e;
P_0c097e58: /* original 0eb4, guest PC 0x0c097e58 */
if(!s->budget--) { s->failed_pc=0x0c097e58u; return 0; }
write(ram,r[14]+r[0],r[11],1);
goto P_0c097e5a;
P_0c097e5a: /* original 7101, guest PC 0x0c097e5a */
if(!s->budget--) { s->failed_pc=0x0c097e5au; return 0; }
r[1]+=0x00000001u;
goto P_0c097e5c;
P_0c097e5c: /* original 0e14, guest PC 0x0c097e5c */
if(!s->budget--) { s->failed_pc=0x0c097e5cu; return 0; }
write(ram,r[14]+r[0],r[1],1);
goto P_0c097e5e;
P_0c097e5e: /* original 00ec, guest PC 0x0c097e5e */
if(!s->budget--) { s->failed_pc=0x0c097e5eu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c097e60;
P_0c097e60: /* original 8800, guest PC 0x0c097e60 */
if(!s->budget--) { s->failed_pc=0x0c097e60u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000000u)!=0);
goto P_0c097e62;
P_0c097e62: /* original 8903, guest PC 0x0c097e62 */
if(!s->budget--) { s->failed_pc=0x0c097e62u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c097e6c; }
goto P_0c097e64;
P_0c097e64: /* original 880a, guest PC 0x0c097e64 */
if(!s->budget--) { s->failed_pc=0x0c097e64u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000au)!=0);
goto P_0c097e66;
P_0c097e66: /* original 8905, guest PC 0x0c097e66 */
if(!s->budget--) { s->failed_pc=0x0c097e66u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c097e74; }
goto P_0c097e68;
P_0c097e68: /* original a007, guest PC 0x0c097e68 */
if(!s->budget--) { s->failed_pc=0x0c097e68u; return 0; }
goto P_0c097e7a;
P_0c097e6a: /* original 0009, guest PC 0x0c097e6a */
if(!s->budget--) { s->failed_pc=0x0c097e6au; return 0; }
goto P_0c097e6c;
P_0c097e6c: /* original 901f, guest PC 0x0c097e6c */
if(!s->budget--) { s->failed_pc=0x0c097e6cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c097eaeu,2);
goto P_0c097e6e;
P_0c097e6e: /* original e301, guest PC 0x0c097e6e */
if(!s->budget--) { s->failed_pc=0x0c097e6eu; return 0; }
r[3]=0x00000001u;
goto P_0c097e70;
P_0c097e70: /* original a005, guest PC 0x0c097e70 */
if(!s->budget--) { s->failed_pc=0x0c097e70u; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c097e7e;
P_0c097e72: /* original 0e34, guest PC 0x0c097e72 */
if(!s->budget--) { s->failed_pc=0x0c097e72u; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c097e74;
P_0c097e74: /* original 901b, guest PC 0x0c097e74 */
if(!s->budget--) { s->failed_pc=0x0c097e74u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c097eaeu,2);
goto P_0c097e76;
P_0c097e76: /* original a002, guest PC 0x0c097e76 */
if(!s->budget--) { s->failed_pc=0x0c097e76u; return 0; }
write(ram,r[14]+r[0],r[9],1);
goto P_0c097e7e;
P_0c097e78: /* original 0e94, guest PC 0x0c097e78 */
if(!s->budget--) { s->failed_pc=0x0c097e78u; return 0; }
write(ram,r[14]+r[0],r[9],1);
goto P_0c097e7a;
P_0c097e7a: /* original 9018, guest PC 0x0c097e7a */
if(!s->budget--) { s->failed_pc=0x0c097e7au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c097eaeu,2);
goto P_0c097e7c;
P_0c097e7c: /* original 0eb4, guest PC 0x0c097e7c */
if(!s->budget--) { s->failed_pc=0x0c097e7cu; return 0; }
write(ram,r[14]+r[0],r[11],1);
goto P_0c097e7e;
P_0c097e7e: /* original 9017, guest PC 0x0c097e7e */
if(!s->budget--) { s->failed_pc=0x0c097e7eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c097eb0u,2);
goto P_0c097e80;
P_0c097e80: /* original e201, guest PC 0x0c097e80 */
if(!s->budget--) { s->failed_pc=0x0c097e80u; return 0; }
r[2]=0x00000001u;
goto P_0c097e82;
P_0c097e82: /* original a01b, guest PC 0x0c097e82 */
if(!s->budget--) { s->failed_pc=0x0c097e82u; return 0; }
write(ram,r[14]+r[0],r[2],1);
goto P_0c097ebc;
P_0c097e84: /* original 0e24, guest PC 0x0c097e84 */
if(!s->budget--) { s->failed_pc=0x0c097e84u; return 0; }
write(ram,r[14]+r[0],r[2],1);
goto P_0c097e86;
P_0c097e86: /* original 9014, guest PC 0x0c097e86 */
if(!s->budget--) { s->failed_pc=0x0c097e86u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c097eb2u,2);
goto P_0c097e88;
P_0c097e88: /* original e30b, guest PC 0x0c097e88 */
if(!s->budget--) { s->failed_pc=0x0c097e88u; return 0; }
r[3]=0x0000000bu;
goto P_0c097e8a;
P_0c097e8a: /* original 01ec, guest PC 0x0c097e8a */
if(!s->budget--) { s->failed_pc=0x0c097e8au; return 0; }
r[1]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c097e8c;
P_0c097e8c: /* original 3133, guest PC 0x0c097e8c */
if(!s->budget--) { s->failed_pc=0x0c097e8cu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[1]>=(int32_t)r[3])!=0);
goto P_0c097e8e;
P_0c097e8e: /* original 8908, guest PC 0x0c097e8e */
if(!s->budget--) { s->failed_pc=0x0c097e8eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c097ea2; }
goto P_0c097e90;
P_0c097e90: /* original 7101, guest PC 0x0c097e90 */
if(!s->budget--) { s->failed_pc=0x0c097e90u; return 0; }
r[1]+=0x00000001u;
goto P_0c097e92;
P_0c097e92: /* original a013, guest PC 0x0c097e92 */
if(!s->budget--) { s->failed_pc=0x0c097e92u; return 0; }
write(ram,r[14]+r[0],r[1],1);
goto P_0c097ebc;
P_0c097e94: /* original 0e14, guest PC 0x0c097e94 */
if(!s->budget--) { s->failed_pc=0x0c097e94u; return 0; }
write(ram,r[14]+r[0],r[1],1);
goto P_0c097e96;
P_0c097e96: /* original 900d, guest PC 0x0c097e96 */
if(!s->budget--) { s->failed_pc=0x0c097e96u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c097eb4u,2);
goto P_0c097e98;
P_0c097e98: /* original e304, guest PC 0x0c097e98 */
if(!s->budget--) { s->failed_pc=0x0c097e98u; return 0; }
r[3]=0x00000004u;
goto P_0c097e9a;
P_0c097e9a: /* original 02ec, guest PC 0x0c097e9a */
if(!s->budget--) { s->failed_pc=0x0c097e9au; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c097e9c;
P_0c097e9c: /* original 3233, guest PC 0x0c097e9c */
if(!s->budget--) { s->failed_pc=0x0c097e9cu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[2]>=(int32_t)r[3])!=0);
goto P_0c097e9e;
P_0c097e9e: /* original 8b0a, guest PC 0x0c097e9e */
if(!s->budget--) { s->failed_pc=0x0c097e9eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c097eb6; }
goto P_0c097ea0;
P_0c097ea0: /* original 9008, guest PC 0x0c097ea0 */
if(!s->budget--) { s->failed_pc=0x0c097ea0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c097eb4u,2);
goto P_0c097ea2;
P_0c097ea2: /* original a00b, guest PC 0x0c097ea2 */
if(!s->budget--) { s->failed_pc=0x0c097ea2u; return 0; }
write(ram,r[14]+r[0],r[11],1);
goto P_0c097ebc;
P_0c097ea4: /* original 0eb4, guest PC 0x0c097ea4 */
if(!s->budget--) { s->failed_pc=0x0c097ea4u; return 0; }
write(ram,r[14]+r[0],r[11],1);
return vf3_matrix_family(0x0c097ea6u,s,ram);
P_0c097eb6: /* original 01ec, guest PC 0x0c097eb6 */
if(!s->budget--) { s->failed_pc=0x0c097eb6u; return 0; }
r[1]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c097eb8;
P_0c097eb8: /* original 7101, guest PC 0x0c097eb8 */
if(!s->budget--) { s->failed_pc=0x0c097eb8u; return 0; }
r[1]+=0x00000001u;
goto P_0c097eba;
P_0c097eba: /* original 0e14, guest PC 0x0c097eba */
if(!s->budget--) { s->failed_pc=0x0c097ebau; return 0; }
write(ram,r[14]+r[0],r[1],1);
goto P_0c097ebc;
P_0c097ebc: /* original e240, guest PC 0x0c097ebc */
if(!s->budget--) { s->failed_pc=0x0c097ebcu; return 0; }
r[2]=0x00000040u;
goto P_0c097ebe;
P_0c097ebe: /* original 22d8, guest PC 0x0c097ebe */
if(!s->budget--) { s->failed_pc=0x0c097ebeu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[13])==0)!=0);
goto P_0c097ec0;
P_0c097ec0: /* original 8943, guest PC 0x0c097ec0 */
if(!s->budget--) { s->failed_pc=0x0c097ec0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c097f4a; }
goto P_0c097ec2;
P_0c097ec2: /* original 480b, guest PC 0x0c097ec2 */
if(!s->budget--) { s->failed_pc=0x0c097ec2u; return 0; }
target=r[8];
r[16]=code_base|0x0c097ec6u;
r[4]=0x0000007fu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c097ec6u) { target=s->pc; goto dispatch; }
goto P_0c097ec6;
P_0c097ec4: /* original e47f, guest PC 0x0c097ec4 */
if(!s->budget--) { s->failed_pc=0x0c097ec4u; return 0; }
r[4]=0x0000007fu;
goto P_0c097ec6;
P_0c097ec6: /* original 9058, guest PC 0x0c097ec6 */
if(!s->budget--) { s->failed_pc=0x0c097ec6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c097f7au,2);
goto P_0c097ec8;
P_0c097ec8: /* original 00ec, guest PC 0x0c097ec8 */
if(!s->budget--) { s->failed_pc=0x0c097ec8u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c097eca;
P_0c097eca: /* original 8800, guest PC 0x0c097eca */
if(!s->budget--) { s->failed_pc=0x0c097ecau; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000000u)!=0);
goto P_0c097ecc;
P_0c097ecc: /* original 8907, guest PC 0x0c097ecc */
if(!s->budget--) { s->failed_pc=0x0c097eccu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c097ede; }
goto P_0c097ece;
P_0c097ece: /* original 8801, guest PC 0x0c097ece */
if(!s->budget--) { s->failed_pc=0x0c097eceu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c097ed0;
P_0c097ed0: /* original 890b, guest PC 0x0c097ed0 */
if(!s->budget--) { s->failed_pc=0x0c097ed0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c097eea; }
goto P_0c097ed2;
P_0c097ed2: /* original 8802, guest PC 0x0c097ed2 */
if(!s->budget--) { s->failed_pc=0x0c097ed2u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c097ed4;
P_0c097ed4: /* original 8926, guest PC 0x0c097ed4 */
if(!s->budget--) { s->failed_pc=0x0c097ed4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c097f24; }
goto P_0c097ed6;
P_0c097ed6: /* original 8803, guest PC 0x0c097ed6 */
if(!s->budget--) { s->failed_pc=0x0c097ed6u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000003u)!=0);
goto P_0c097ed8;
P_0c097ed8: /* original 892e, guest PC 0x0c097ed8 */
if(!s->budget--) { s->failed_pc=0x0c097ed8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c097f38; }
goto P_0c097eda;
P_0c097eda: /* original a036, guest PC 0x0c097eda */
if(!s->budget--) { s->failed_pc=0x0c097edau; return 0; }
goto P_0c097f4a;
P_0c097edc: /* original 0009, guest PC 0x0c097edc */
if(!s->budget--) { s->failed_pc=0x0c097edcu; return 0; }
goto P_0c097ede;
P_0c097ede: /* original 904d, guest PC 0x0c097ede */
if(!s->budget--) { s->failed_pc=0x0c097edeu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c097f7cu,2);
goto P_0c097ee0;
P_0c097ee0: /* original 03ec, guest PC 0x0c097ee0 */
if(!s->budget--) { s->failed_pc=0x0c097ee0u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c097ee2;
P_0c097ee2: /* original 633b, guest PC 0x0c097ee2 */
if(!s->budget--) { s->failed_pc=0x0c097ee2u; return 0; }
r[3]=0u-r[3];
goto P_0c097ee4;
P_0c097ee4: /* original 7301, guest PC 0x0c097ee4 */
if(!s->budget--) { s->failed_pc=0x0c097ee4u; return 0; }
r[3]+=0x00000001u;
goto P_0c097ee6;
P_0c097ee6: /* original a030, guest PC 0x0c097ee6 */
if(!s->budget--) { s->failed_pc=0x0c097ee6u; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c097f4a;
P_0c097ee8: /* original 0e34, guest PC 0x0c097ee8 */
if(!s->budget--) { s->failed_pc=0x0c097ee8u; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c097eea;
P_0c097eea: /* original 9048, guest PC 0x0c097eea */
if(!s->budget--) { s->failed_pc=0x0c097eeau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c097f7eu,2);
goto P_0c097eec;
P_0c097eec: /* original 01ec, guest PC 0x0c097eec */
if(!s->budget--) { s->failed_pc=0x0c097eecu; return 0; }
r[1]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c097eee;
P_0c097eee: /* original 4115, guest PC 0x0c097eee */
if(!s->budget--) { s->failed_pc=0x0c097eeeu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[1]>0)!=0);
goto P_0c097ef0;
P_0c097ef0: /* original 8901, guest PC 0x0c097ef0 */
if(!s->budget--) { s->failed_pc=0x0c097ef0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c097ef6; }
goto P_0c097ef2;
P_0c097ef2: /* original a002, guest PC 0x0c097ef2 */
if(!s->budget--) { s->failed_pc=0x0c097ef2u; return 0; }
r[2]=0x0000000au;
goto P_0c097efa;
P_0c097ef4: /* original e20a, guest PC 0x0c097ef4 */
if(!s->budget--) { s->failed_pc=0x0c097ef4u; return 0; }
r[2]=0x0000000au;
goto P_0c097ef6;
P_0c097ef6: /* original 02ec, guest PC 0x0c097ef6 */
if(!s->budget--) { s->failed_pc=0x0c097ef6u; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c097ef8;
P_0c097ef8: /* original 72ff, guest PC 0x0c097ef8 */
if(!s->budget--) { s->failed_pc=0x0c097ef8u; return 0; }
r[2]+=0xffffffffu;
goto P_0c097efa;
P_0c097efa: /* original 0e24, guest PC 0x0c097efa */
if(!s->budget--) { s->failed_pc=0x0c097efau; return 0; }
write(ram,r[14]+r[0],r[2],1);
goto P_0c097efc;
P_0c097efc: /* original 00ec, guest PC 0x0c097efc */
if(!s->budget--) { s->failed_pc=0x0c097efcu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c097efe;
P_0c097efe: /* original 8800, guest PC 0x0c097efe */
if(!s->budget--) { s->failed_pc=0x0c097efeu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000000u)!=0);
goto P_0c097f00;
P_0c097f00: /* original 8903, guest PC 0x0c097f00 */
if(!s->budget--) { s->failed_pc=0x0c097f00u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c097f0a; }
goto P_0c097f02;
P_0c097f02: /* original 880a, guest PC 0x0c097f02 */
if(!s->budget--) { s->failed_pc=0x0c097f02u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000au)!=0);
goto P_0c097f04;
P_0c097f04: /* original 8905, guest PC 0x0c097f04 */
if(!s->budget--) { s->failed_pc=0x0c097f04u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c097f12; }
goto P_0c097f06;
P_0c097f06: /* original a007, guest PC 0x0c097f06 */
if(!s->budget--) { s->failed_pc=0x0c097f06u; return 0; }
goto P_0c097f18;
P_0c097f08: /* original 0009, guest PC 0x0c097f08 */
if(!s->budget--) { s->failed_pc=0x0c097f08u; return 0; }
goto P_0c097f0a;
P_0c097f0a: /* original 9039, guest PC 0x0c097f0a */
if(!s->budget--) { s->failed_pc=0x0c097f0au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c097f80u,2);
goto P_0c097f0c;
P_0c097f0c: /* original e301, guest PC 0x0c097f0c */
if(!s->budget--) { s->failed_pc=0x0c097f0cu; return 0; }
r[3]=0x00000001u;
goto P_0c097f0e;
P_0c097f0e: /* original a005, guest PC 0x0c097f0e */
if(!s->budget--) { s->failed_pc=0x0c097f0eu; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c097f1c;
P_0c097f10: /* original 0e34, guest PC 0x0c097f10 */
if(!s->budget--) { s->failed_pc=0x0c097f10u; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c097f12;
P_0c097f12: /* original 9035, guest PC 0x0c097f12 */
if(!s->budget--) { s->failed_pc=0x0c097f12u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c097f80u,2);
goto P_0c097f14;
P_0c097f14: /* original a002, guest PC 0x0c097f14 */
if(!s->budget--) { s->failed_pc=0x0c097f14u; return 0; }
write(ram,r[14]+r[0],r[9],1);
goto P_0c097f1c;
P_0c097f16: /* original 0e94, guest PC 0x0c097f16 */
if(!s->budget--) { s->failed_pc=0x0c097f16u; return 0; }
write(ram,r[14]+r[0],r[9],1);
goto P_0c097f18;
P_0c097f18: /* original 9032, guest PC 0x0c097f18 */
if(!s->budget--) { s->failed_pc=0x0c097f18u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c097f80u,2);
goto P_0c097f1a;
P_0c097f1a: /* original 0eb4, guest PC 0x0c097f1a */
if(!s->budget--) { s->failed_pc=0x0c097f1au; return 0; }
write(ram,r[14]+r[0],r[11],1);
goto P_0c097f1c;
P_0c097f1c: /* original 9031, guest PC 0x0c097f1c */
if(!s->budget--) { s->failed_pc=0x0c097f1cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c097f82u,2);
goto P_0c097f1e;
P_0c097f1e: /* original e201, guest PC 0x0c097f1e */
if(!s->budget--) { s->failed_pc=0x0c097f1eu; return 0; }
r[2]=0x00000001u;
goto P_0c097f20;
P_0c097f20: /* original a013, guest PC 0x0c097f20 */
if(!s->budget--) { s->failed_pc=0x0c097f20u; return 0; }
write(ram,r[14]+r[0],r[2],1);
goto P_0c097f4a;
P_0c097f22: /* original 0e24, guest PC 0x0c097f22 */
if(!s->budget--) { s->failed_pc=0x0c097f22u; return 0; }
write(ram,r[14]+r[0],r[2],1);
goto P_0c097f24;
P_0c097f24: /* original 902e, guest PC 0x0c097f24 */
if(!s->budget--) { s->failed_pc=0x0c097f24u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c097f84u,2);
goto P_0c097f26;
P_0c097f26: /* original 01ec, guest PC 0x0c097f26 */
if(!s->budget--) { s->failed_pc=0x0c097f26u; return 0; }
r[1]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c097f28;
P_0c097f28: /* original 4115, guest PC 0x0c097f28 */
if(!s->budget--) { s->failed_pc=0x0c097f28u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[1]>0)!=0);
goto P_0c097f2a;
P_0c097f2a: /* original 8901, guest PC 0x0c097f2a */
if(!s->budget--) { s->failed_pc=0x0c097f2au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c097f30; }
goto P_0c097f2c;
P_0c097f2c: /* original a002, guest PC 0x0c097f2c */
if(!s->budget--) { s->failed_pc=0x0c097f2cu; return 0; }
r[2]=0x0000000bu;
goto P_0c097f34;
P_0c097f2e: /* original e20b, guest PC 0x0c097f2e */
if(!s->budget--) { s->failed_pc=0x0c097f2eu; return 0; }
r[2]=0x0000000bu;
goto P_0c097f30;
P_0c097f30: /* original 02ec, guest PC 0x0c097f30 */
if(!s->budget--) { s->failed_pc=0x0c097f30u; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c097f32;
P_0c097f32: /* original 72ff, guest PC 0x0c097f32 */
if(!s->budget--) { s->failed_pc=0x0c097f32u; return 0; }
r[2]+=0xffffffffu;
goto P_0c097f34;
P_0c097f34: /* original a009, guest PC 0x0c097f34 */
if(!s->budget--) { s->failed_pc=0x0c097f34u; return 0; }
write(ram,r[14]+r[0],r[2],1);
goto P_0c097f4a;
P_0c097f36: /* original 0e24, guest PC 0x0c097f36 */
if(!s->budget--) { s->failed_pc=0x0c097f36u; return 0; }
write(ram,r[14]+r[0],r[2],1);
goto P_0c097f38;
P_0c097f38: /* original 9025, guest PC 0x0c097f38 */
if(!s->budget--) { s->failed_pc=0x0c097f38u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c097f86u,2);
goto P_0c097f3a;
P_0c097f3a: /* original 01ec, guest PC 0x0c097f3a */
if(!s->budget--) { s->failed_pc=0x0c097f3au; return 0; }
r[1]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c097f3c;
P_0c097f3c: /* original 4115, guest PC 0x0c097f3c */
if(!s->budget--) { s->failed_pc=0x0c097f3cu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[1]>0)!=0);
goto P_0c097f3e;
P_0c097f3e: /* original 8901, guest PC 0x0c097f3e */
if(!s->budget--) { s->failed_pc=0x0c097f3eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c097f44; }
goto P_0c097f40;
P_0c097f40: /* original a002, guest PC 0x0c097f40 */
if(!s->budget--) { s->failed_pc=0x0c097f40u; return 0; }
r[2]=0x00000004u;
goto P_0c097f48;
P_0c097f42: /* original e204, guest PC 0x0c097f42 */
if(!s->budget--) { s->failed_pc=0x0c097f42u; return 0; }
r[2]=0x00000004u;
goto P_0c097f44;
P_0c097f44: /* original 02ec, guest PC 0x0c097f44 */
if(!s->budget--) { s->failed_pc=0x0c097f44u; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c097f46;
P_0c097f46: /* original 72ff, guest PC 0x0c097f46 */
if(!s->budget--) { s->failed_pc=0x0c097f46u; return 0; }
r[2]+=0xffffffffu;
goto P_0c097f48;
P_0c097f48: /* original 0e24, guest PC 0x0c097f48 */
if(!s->budget--) { s->failed_pc=0x0c097f48u; return 0; }
write(ram,r[14]+r[0],r[2],1);
goto P_0c097f4a;
P_0c097f4a: /* original 2d98, guest PC 0x0c097f4a */
if(!s->budget--) { s->failed_pc=0x0c097f4au; return 0; }
r[17]=(r[17]&~1u)|(((r[13]&r[9])==0)!=0);
goto P_0c097f4c;
P_0c097f4c: /* original 892f, guest PC 0x0c097f4c */
if(!s->budget--) { s->failed_pc=0x0c097f4cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c097fae; }
goto P_0c097f4e;
P_0c097f4e: /* original d30f, guest PC 0x0c097f4e */
if(!s->budget--) { s->failed_pc=0x0c097f4eu; return 0; }
r[3]=read(ram,0x0c097f8cu,4);
goto P_0c097f50;
P_0c097f50: /* original 430b, guest PC 0x0c097f50 */
if(!s->budget--) { s->failed_pc=0x0c097f50u; return 0; }
target=r[3];
r[16]=code_base|0x0c097f54u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c097f54u) { target=s->pc; goto dispatch; }
goto P_0c097f54;
P_0c097f52: /* original 0009, guest PC 0x0c097f52 */
if(!s->budget--) { s->failed_pc=0x0c097f52u; return 0; }
goto P_0c097f54;
P_0c097f54: /* original e029, guest PC 0x0c097f54 */
if(!s->budget--) { s->failed_pc=0x0c097f54u; return 0; }
r[0]=0x00000029u;
goto P_0c097f56;
P_0c097f56: /* original 0cb4, guest PC 0x0c097f56 */
if(!s->budget--) { s->failed_pc=0x0c097f56u; return 0; }
write(ram,r[12]+r[0],r[11],1);
goto P_0c097f58;
P_0c097f58: /* original 6093, guest PC 0x0c097f58 */
if(!s->budget--) { s->failed_pc=0x0c097f58u; return 0; }
r[0]=r[9];
goto P_0c097f5a;
P_0c097f5a: /* original 54c2, guest PC 0x0c097f5a */
if(!s->budget--) { s->failed_pc=0x0c097f5au; return 0; }
r[4]=read(ram,r[12]+8,4);
goto P_0c097f5c;
P_0c097f5c: /* original d30c, guest PC 0x0c097f5c */
if(!s->budget--) { s->failed_pc=0x0c097f5cu; return 0; }
r[3]=read(ram,0x0c097f90u,4);
goto P_0c097f5e;
P_0c097f5e: /* original 2439, guest PC 0x0c097f5e */
if(!s->budget--) { s->failed_pc=0x0c097f5eu; return 0; }
r[4]&=r[3];
goto P_0c097f60;
P_0c097f60: /* original 1c42, guest PC 0x0c097f60 */
if(!s->budget--) { s->failed_pc=0x0c097f60u; return 0; }
write(ram,r[12]+8,r[4],4);
goto P_0c097f62;
P_0c097f62: /* original d20c, guest PC 0x0c097f62 */
if(!s->budget--) { s->failed_pc=0x0c097f62u; return 0; }
r[2]=read(ram,0x0c097f94u,4);
goto P_0c097f64;
P_0c097f64: /* original 420b, guest PC 0x0c097f64 */
if(!s->budget--) { s->failed_pc=0x0c097f64u; return 0; }
target=r[2];
r[16]=code_base|0x0c097f68u;
write(ram,r[14]+10,r[0],1);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c097f68u) { target=s->pc; goto dispatch; }
goto P_0c097f68;
P_0c097f66: /* original 80ea, guest PC 0x0c097f66 */
if(!s->budget--) { s->failed_pc=0x0c097f66u; return 0; }
write(ram,r[14]+10,r[0],1);
goto P_0c097f68;
P_0c097f68: /* original 62a2, guest PC 0x0c097f68 */
if(!s->budget--) { s->failed_pc=0x0c097f68u; return 0; }
tmp=read(ram,r[10],4);
r[2]=tmp;
goto P_0c097f6a;
P_0c097f6a: /* original d30b, guest PC 0x0c097f6a */
if(!s->budget--) { s->failed_pc=0x0c097f6au; return 0; }
r[3]=read(ram,0x0c097f98u,4);
goto P_0c097f6c;
P_0c097f6c: /* original 2239, guest PC 0x0c097f6c */
if(!s->budget--) { s->failed_pc=0x0c097f6cu; return 0; }
r[2]&=r[3];
goto P_0c097f6e;
P_0c097f6e: /* original 2a22, guest PC 0x0c097f6e */
if(!s->budget--) { s->failed_pc=0x0c097f6eu; return 0; }
write(ram,r[10],r[2],4);
goto P_0c097f70;
P_0c097f70: /* original 9006, guest PC 0x0c097f70 */
if(!s->budget--) { s->failed_pc=0x0c097f70u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c097f80u,2);
goto P_0c097f72;
P_0c097f72: /* original 0eb4, guest PC 0x0c097f72 */
if(!s->budget--) { s->failed_pc=0x0c097f72u; return 0; }
write(ram,r[14]+r[0],r[11],1);
goto P_0c097f74;
P_0c097f74: /* original 9008, guest PC 0x0c097f74 */
if(!s->budget--) { s->failed_pc=0x0c097f74u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c097f88u,2);
goto P_0c097f76;
P_0c097f76: /* original a032, guest PC 0x0c097f76 */
if(!s->budget--) { s->failed_pc=0x0c097f76u; return 0; }
write(ram,r[14]+r[0],r[11],1);
goto P_0c097fde;
P_0c097f78: /* original 0eb4, guest PC 0x0c097f78 */
if(!s->budget--) { s->failed_pc=0x0c097f78u; return 0; }
write(ram,r[14]+r[0],r[11],1);
return vf3_matrix_family(0x0c097f7au,s,ram);
P_0c097f9c: /* original 9075, guest PC 0x0c097f9c */
if(!s->budget--) { s->failed_pc=0x0c097f9cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09808au,2);
goto P_0c097f9e;
P_0c097f9e: /* original 02ec, guest PC 0x0c097f9e */
if(!s->budget--) { s->failed_pc=0x0c097f9eu; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c097fa0;
P_0c097fa0: /* original 2228, guest PC 0x0c097fa0 */
if(!s->budget--) { s->failed_pc=0x0c097fa0u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c097fa2;
P_0c097fa2: /* original 8904, guest PC 0x0c097fa2 */
if(!s->budget--) { s->failed_pc=0x0c097fa2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c097fae; }
goto P_0c097fa4;
P_0c097fa4: /* original e010, guest PC 0x0c097fa4 */
if(!s->budget--) { s->failed_pc=0x0c097fa4u; return 0; }
r[0]=0x00000010u;
goto P_0c097fa6;
P_0c097fa6: /* original b025, guest PC 0x0c097fa6 */
if(!s->budget--) { s->failed_pc=0x0c097fa6u; return 0; }
target=0x0c097ff4u; r[16]=code_base|0x0c097faau;
write(ram,r[14]+11,r[0],1);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c097faau) { target=s->pc; goto dispatch; }
goto P_0c097faa;
P_0c097fa8: /* original 80eb, guest PC 0x0c097fa8 */
if(!s->budget--) { s->failed_pc=0x0c097fa8u; return 0; }
write(ram,r[14]+11,r[0],1);
goto P_0c097faa;
P_0c097faa: /* original 906e, guest PC 0x0c097faa */
if(!s->budget--) { s->failed_pc=0x0c097faau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09808au,2);
goto P_0c097fac;
P_0c097fac: /* original 0eb4, guest PC 0x0c097fac */
if(!s->budget--) { s->failed_pc=0x0c097facu; return 0; }
write(ram,r[14]+r[0],r[11],1);
goto P_0c097fae;
P_0c097fae: /* original 84eb, guest PC 0x0c097fae */
if(!s->budget--) { s->failed_pc=0x0c097faeu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+11,1);
goto P_0c097fb0;
P_0c097fb0: /* original 640c, guest PC 0x0c097fb0 */
if(!s->budget--) { s->failed_pc=0x0c097fb0u; return 0; }
r[4]=r[0]&255u;
goto P_0c097fb2;
P_0c097fb2: /* original 6043, guest PC 0x0c097fb2 */
if(!s->budget--) { s->failed_pc=0x0c097fb2u; return 0; }
r[0]=r[4];
goto P_0c097fb4;
P_0c097fb4: /* original 80e9, guest PC 0x0c097fb4 */
if(!s->budget--) { s->failed_pc=0x0c097fb4u; return 0; }
write(ram,r[14]+9,r[0],1);
goto P_0c097fb6;
P_0c097fb6: /* original d235, guest PC 0x0c097fb6 */
if(!s->budget--) { s->failed_pc=0x0c097fb6u; return 0; }
r[2]=read(ram,0x0c09808cu,4);
goto P_0c097fb8;
P_0c097fb8: /* original 634b, guest PC 0x0c097fb8 */
if(!s->budget--) { s->failed_pc=0x0c097fb8u; return 0; }
r[3]=0u-r[4];
goto P_0c097fba;
P_0c097fba: /* original 4408, guest PC 0x0c097fba */
if(!s->budget--) { s->failed_pc=0x0c097fbau; return 0; }
r[4]<<=2;
goto P_0c097fbc;
P_0c097fbc: /* original 423d, guest PC 0x0c097fbc */
if(!s->budget--) { s->failed_pc=0x0c097fbcu; return 0; }
r[2]=(r[3]&0x80000000u)?((r[3]&31u)?r[2]>>((-r[3])&31u):0):r[2]<<(r[3]&31u);
goto P_0c097fbe;
P_0c097fbe: /* original 1e21, guest PC 0x0c097fbe */
if(!s->budget--) { s->failed_pc=0x0c097fbeu; return 0; }
write(ram,r[14]+4,r[2],4);
goto P_0c097fc0;
P_0c097fc0: /* original d033, guest PC 0x0c097fc0 */
if(!s->budget--) { s->failed_pc=0x0c097fc0u; return 0; }
r[0]=read(ram,0x0c098090u,4);
goto P_0c097fc2;
P_0c097fc2: /* original 034e, guest PC 0x0c097fc2 */
if(!s->budget--) { s->failed_pc=0x0c097fc2u; return 0; }
r[3]=read(ram,r[4]+r[0],4);
goto P_0c097fc4;
P_0c097fc4: /* original 2f32, guest PC 0x0c097fc4 */
if(!s->budget--) { s->failed_pc=0x0c097fc4u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c097fc6;
P_0c097fc6: /* original 7f0c, guest PC 0x0c097fc6 */
if(!s->budget--) { s->failed_pc=0x0c097fc6u; return 0; }
r[15]+=0x0000000cu;
goto P_0c097fc8;
P_0c097fc8: /* original 4f26, guest PC 0x0c097fc8 */
if(!s->budget--) { s->failed_pc=0x0c097fc8u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c097fca;
P_0c097fca: /* original 6233, guest PC 0x0c097fca */
if(!s->budget--) { s->failed_pc=0x0c097fcau; return 0; }
r[2]=r[3];
goto P_0c097fcc;
P_0c097fcc: /* original fff9, guest PC 0x0c097fcc */
if(!s->budget--) { s->failed_pc=0x0c097fccu; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c097fce;
P_0c097fce: /* original 68f6, guest PC 0x0c097fce */
if(!s->budget--) { s->failed_pc=0x0c097fceu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c097fd0;
P_0c097fd0: /* original 69f6, guest PC 0x0c097fd0 */
if(!s->budget--) { s->failed_pc=0x0c097fd0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c097fd2;
P_0c097fd2: /* original 6af6, guest PC 0x0c097fd2 */
if(!s->budget--) { s->failed_pc=0x0c097fd2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c097fd4;
P_0c097fd4: /* original 6bf6, guest PC 0x0c097fd4 */
if(!s->budget--) { s->failed_pc=0x0c097fd4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c097fd6;
P_0c097fd6: /* original 6cf6, guest PC 0x0c097fd6 */
if(!s->budget--) { s->failed_pc=0x0c097fd6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c097fd8;
P_0c097fd8: /* original 6df6, guest PC 0x0c097fd8 */
if(!s->budget--) { s->failed_pc=0x0c097fd8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c097fda;
P_0c097fda: /* original 422b, guest PC 0x0c097fda */
if(!s->budget--) { s->failed_pc=0x0c097fdau; return 0; }
target=r[2];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
switch(target&0x1fffffffu) {
case 0x0c03b450u: return vf3_matrix_family(target,s,ram);
case 0x0c03b4b0u: return vf3_matrix_family(target,s,ram);
case 0x0c03b530u: return vf3_matrix_family(target,s,ram);
case 0x0c03b620u: return vf3_matrix_family(target,s,ram);
case 0x0c03b820u: return vf3_matrix_family(target,s,ram);
case 0x0c03bd80u: return vf3_matrix_family(target,s,ram);
case 0x0c03c0e0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c4a0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c4f0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c610u: return vf3_matrix_family(target,s,ram);
case 0x0c03c6c0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c880u: return vf3_matrix_family(target,s,ram);
case 0x0c03c940u: return vf3_matrix_family(target,s,ram);
case 0x0c03c970u: return vf3_matrix_family(target,s,ram);
case 0x0c03cbd0u: return vf3_matrix_family(target,s,ram);
case 0x0c03cc60u: return vf3_matrix_family(target,s,ram);
case 0x0c03cc90u: return vf3_matrix_family(target,s,ram);
case 0x0c03ccb0u: return vf3_matrix_family(target,s,ram);
default: goto dispatch; }
P_0c097fdc: /* original 6ef6, guest PC 0x0c097fdc */
if(!s->budget--) { s->failed_pc=0x0c097fdcu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c097fde;
P_0c097fde: /* original 7f0c, guest PC 0x0c097fde */
if(!s->budget--) { s->failed_pc=0x0c097fdeu; return 0; }
r[15]+=0x0000000cu;
goto P_0c097fe0;
P_0c097fe0: /* original 4f26, guest PC 0x0c097fe0 */
if(!s->budget--) { s->failed_pc=0x0c097fe0u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c097fe2;
P_0c097fe2: /* original fff9, guest PC 0x0c097fe2 */
if(!s->budget--) { s->failed_pc=0x0c097fe2u; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c097fe4;
P_0c097fe4: /* original 68f6, guest PC 0x0c097fe4 */
if(!s->budget--) { s->failed_pc=0x0c097fe4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c097fe6;
P_0c097fe6: /* original 69f6, guest PC 0x0c097fe6 */
if(!s->budget--) { s->failed_pc=0x0c097fe6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c097fe8;
P_0c097fe8: /* original 6af6, guest PC 0x0c097fe8 */
if(!s->budget--) { s->failed_pc=0x0c097fe8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c097fea;
P_0c097fea: /* original 6bf6, guest PC 0x0c097fea */
if(!s->budget--) { s->failed_pc=0x0c097feau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c097fec;
P_0c097fec: /* original 6cf6, guest PC 0x0c097fec */
if(!s->budget--) { s->failed_pc=0x0c097fecu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c097fee;
P_0c097fee: /* original 6df6, guest PC 0x0c097fee */
if(!s->budget--) { s->failed_pc=0x0c097feeu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c097ff0;
P_0c097ff0: /* original 000b, guest PC 0x0c097ff0 */
if(!s->budget--) { s->failed_pc=0x0c097ff0u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c097ff2: /* original 6ef6, guest PC 0x0c097ff2 */
if(!s->budget--) { s->failed_pc=0x0c097ff2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c097ff4;
P_0c097ff4: /* original d427, guest PC 0x0c097ff4 */
if(!s->budget--) { s->failed_pc=0x0c097ff4u; return 0; }
r[4]=read(ram,0x0c098094u,4);
goto P_0c097ff6;
P_0c097ff6: /* original d329, guest PC 0x0c097ff6 */
if(!s->budget--) { s->failed_pc=0x0c097ff6u; return 0; }
r[3]=read(ram,0x0c09809cu,4);
goto P_0c097ff8;
P_0c097ff8: /* original 5242, guest PC 0x0c097ff8 */
if(!s->budget--) { s->failed_pc=0x0c097ff8u; return 0; }
r[2]=read(ram,r[4]+8,4);
goto P_0c097ffa;
P_0c097ffa: /* original d627, guest PC 0x0c097ffa */
if(!s->budget--) { s->failed_pc=0x0c097ffau; return 0; }
r[6]=read(ram,0x0c098098u,4);
goto P_0c097ffc;
P_0c097ffc: /* original 2238, guest PC 0x0c097ffc */
if(!s->budget--) { s->failed_pc=0x0c097ffcu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c097ffe;
P_0c097ffe: /* original 8b1d, guest PC 0x0c097ffe */
if(!s->budget--) { s->failed_pc=0x0c097ffeu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09803c; }
goto P_0c098000;
P_0c098000: /* original 5142, guest PC 0x0c098000 */
if(!s->budget--) { s->failed_pc=0x0c098000u; return 0; }
r[1]=read(ram,r[4]+8,4);
goto P_0c098002;
P_0c098002: /* original d327, guest PC 0x0c098002 */
if(!s->budget--) { s->failed_pc=0x0c098002u; return 0; }
r[3]=read(ram,0x0c0980a0u,4);
goto P_0c098004;
P_0c098004: /* original 2138, guest PC 0x0c098004 */
if(!s->budget--) { s->failed_pc=0x0c098004u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[3])==0)!=0);
goto P_0c098006;
P_0c098006: /* original 8919, guest PC 0x0c098006 */
if(!s->budget--) { s->failed_pc=0x0c098006u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09803c; }
goto P_0c098008;
P_0c098008: /* original 5242, guest PC 0x0c098008 */
if(!s->budget--) { s->failed_pc=0x0c098008u; return 0; }
r[2]=read(ram,r[4]+8,4);
goto P_0c09800a;
P_0c09800a: /* original d326, guest PC 0x0c09800a */
if(!s->budget--) { s->failed_pc=0x0c09800au; return 0; }
r[3]=read(ram,0x0c0980a4u,4);
goto P_0c09800c;
P_0c09800c: /* original 2238, guest PC 0x0c09800c */
if(!s->budget--) { s->failed_pc=0x0c09800cu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c09800e;
P_0c09800e: /* original 8d0f, guest PC 0x0c09800e */
if(!s->budget--) { s->failed_pc=0x0c09800eu; return 0; }
cond=r[17]&1u;
r[7]=0x00000000u;
if(cond) { goto P_0c098030; }
goto P_0c098012;
P_0c098010: /* original e700, guest PC 0x0c098010 */
if(!s->budget--) { s->failed_pc=0x0c098010u; return 0; }
r[7]=0x00000000u;
goto P_0c098012;
P_0c098012: /* original e029, guest PC 0x0c098012 */
if(!s->budget--) { s->failed_pc=0x0c098012u; return 0; }
r[0]=0x00000029u;
goto P_0c098014;
P_0c098014: /* original 004c, guest PC 0x0c098014 */
if(!s->budget--) { s->failed_pc=0x0c098014u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c098016;
P_0c098016: /* original 600c, guest PC 0x0c098016 */
if(!s->budget--) { s->failed_pc=0x0c098016u; return 0; }
r[0]=r[0]&255u;
goto P_0c098018;
P_0c098018: /* original 8803, guest PC 0x0c098018 */
if(!s->budget--) { s->failed_pc=0x0c098018u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000003u)!=0);
goto P_0c09801a;
P_0c09801a: /* original 8909, guest PC 0x0c09801a */
if(!s->budget--) { s->failed_pc=0x0c09801au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c098030; }
goto P_0c09801c;
P_0c09801c: /* original e02b, guest PC 0x0c09801c */
if(!s->budget--) { s->failed_pc=0x0c09801cu; return 0; }
r[0]=0x0000002bu;
goto P_0c09801e;
P_0c09801e: /* original 034c, guest PC 0x0c09801e */
if(!s->budget--) { s->failed_pc=0x0c09801eu; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c098020;
P_0c098020: /* original 7301, guest PC 0x0c098020 */
if(!s->budget--) { s->failed_pc=0x0c098020u; return 0; }
r[3]+=0x00000001u;
goto P_0c098022;
P_0c098022: /* original 0434, guest PC 0x0c098022 */
if(!s->budget--) { s->failed_pc=0x0c098022u; return 0; }
write(ram,r[4]+r[0],r[3],1);
goto P_0c098024;
P_0c098024: /* original 554d, guest PC 0x0c098024 */
if(!s->budget--) { s->failed_pc=0x0c098024u; return 0; }
r[5]=read(ram,r[4]+52,4);
goto P_0c098026;
P_0c098026: /* original 534e, guest PC 0x0c098026 */
if(!s->budget--) { s->failed_pc=0x0c098026u; return 0; }
r[3]=read(ram,r[4]+56,4);
goto P_0c098028;
P_0c098028: /* original 353c, guest PC 0x0c098028 */
if(!s->budget--) { s->failed_pc=0x0c098028u; return 0; }
r[5]+=r[3];
goto P_0c09802a;
P_0c09802a: /* original 145c, guest PC 0x0c09802a */
if(!s->budget--) { s->failed_pc=0x0c09802au; return 0; }
write(ram,r[4]+48,r[5],4);
goto P_0c09802c;
P_0c09802c: /* original 145d, guest PC 0x0c09802c */
if(!s->budget--) { s->failed_pc=0x0c09802cu; return 0; }
write(ram,r[4]+52,r[5],4);
goto P_0c09802e;
P_0c09802e: /* original 147e, guest PC 0x0c09802e */
if(!s->budget--) { s->failed_pc=0x0c09802eu; return 0; }
write(ram,r[4]+56,r[7],4);
goto P_0c098030;
P_0c098030: /* original e010, guest PC 0x0c098030 */
if(!s->budget--) { s->failed_pc=0x0c098030u; return 0; }
r[0]=0x00000010u;
goto P_0c098032;
P_0c098032: /* original 0674, guest PC 0x0c098032 */
if(!s->budget--) { s->failed_pc=0x0c098032u; return 0; }
write(ram,r[6]+r[0],r[7],1);
goto P_0c098034;
P_0c098034: /* original e00a, guest PC 0x0c098034 */
if(!s->budget--) { s->failed_pc=0x0c098034u; return 0; }
r[0]=0x0000000au;
goto P_0c098036;
P_0c098036: /* original d31c, guest PC 0x0c098036 */
if(!s->budget--) { s->failed_pc=0x0c098036u; return 0; }
r[3]=read(ram,0x0c0980a8u,4);
goto P_0c098038;
P_0c098038: /* original 432b, guest PC 0x0c098038 */
if(!s->budget--) { s->failed_pc=0x0c098038u; return 0; }
target=r[3];
write(ram,r[6]+10,r[0],1);
switch(target&0x1fffffffu) {
case 0x0c03b450u: return vf3_matrix_family(target,s,ram);
case 0x0c03b4b0u: return vf3_matrix_family(target,s,ram);
case 0x0c03b530u: return vf3_matrix_family(target,s,ram);
case 0x0c03b620u: return vf3_matrix_family(target,s,ram);
case 0x0c03b820u: return vf3_matrix_family(target,s,ram);
case 0x0c03bd80u: return vf3_matrix_family(target,s,ram);
case 0x0c03c0e0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c4a0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c4f0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c610u: return vf3_matrix_family(target,s,ram);
case 0x0c03c6c0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c880u: return vf3_matrix_family(target,s,ram);
case 0x0c03c940u: return vf3_matrix_family(target,s,ram);
case 0x0c03c970u: return vf3_matrix_family(target,s,ram);
case 0x0c03cbd0u: return vf3_matrix_family(target,s,ram);
case 0x0c03cc60u: return vf3_matrix_family(target,s,ram);
case 0x0c03cc90u: return vf3_matrix_family(target,s,ram);
case 0x0c03ccb0u: return vf3_matrix_family(target,s,ram);
default: goto dispatch; }
P_0c09803a: /* original 806a, guest PC 0x0c09803a */
if(!s->budget--) { s->failed_pc=0x0c09803au; return 0; }
write(ram,r[6]+10,r[0],1);
goto P_0c09803c;
P_0c09803c: /* original 000b, guest PC 0x0c09803c */
if(!s->budget--) { s->failed_pc=0x0c09803cu; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c09803e: /* original 0009, guest PC 0x0c09803e */
if(!s->budget--) { s->failed_pc=0x0c09803eu; return 0; }
return vf3_matrix_family(0x0c098040u,s,ram);
P_0c0983bc: /* original 2fe6, guest PC 0x0c0983bc */
if(!s->budget--) { s->failed_pc=0x0c0983bcu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0983be;
P_0c0983be: /* original 2fd6, guest PC 0x0c0983be */
if(!s->budget--) { s->failed_pc=0x0c0983beu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0983c0;
P_0c0983c0: /* original 2fc6, guest PC 0x0c0983c0 */
if(!s->budget--) { s->failed_pc=0x0c0983c0u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0983c2;
P_0c0983c2: /* original fffb, guest PC 0x0c0983c2 */
if(!s->budget--) { s->failed_pc=0x0c0983c2u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c0983c4;
P_0c0983c4: /* original de1f, guest PC 0x0c0983c4 */
if(!s->budget--) { s->failed_pc=0x0c0983c4u; return 0; }
r[14]=read(ram,0x0c098444u,4);
goto P_0c0983c6;
P_0c0983c6: /* original 4f22, guest PC 0x0c0983c6 */
if(!s->budget--) { s->failed_pc=0x0c0983c6u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0983c8;
P_0c0983c8: /* original 53e3, guest PC 0x0c0983c8 */
if(!s->budget--) { s->failed_pc=0x0c0983c8u; return 0; }
r[3]=read(ram,r[14]+12,4);
goto P_0c0983ca;
P_0c0983ca: /* original dc1d, guest PC 0x0c0983ca */
if(!s->budget--) { s->failed_pc=0x0c0983cau; return 0; }
r[12]=read(ram,0x0c098440u,4);
goto P_0c0983cc;
P_0c0983cc: /* original 4315, guest PC 0x0c0983cc */
if(!s->budget--) { s->failed_pc=0x0c0983ccu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>0)!=0);
goto P_0c0983ce;
P_0c0983ce: /* original 892b, guest PC 0x0c0983ce */
if(!s->budget--) { s->failed_pc=0x0c0983ceu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c098428; }
goto P_0c0983d0;
P_0c0983d0: /* original d21d, guest PC 0x0c0983d0 */
if(!s->budget--) { s->failed_pc=0x0c0983d0u; return 0; }
r[2]=read(ram,0x0c098448u,4);
goto P_0c0983d2;
P_0c0983d2: /* original 420b, guest PC 0x0c0983d2 */
if(!s->budget--) { s->failed_pc=0x0c0983d2u; return 0; }
target=r[2];
r[16]=code_base|0x0c0983d6u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0983d6u) { target=s->pc; goto dispatch; }
goto P_0c0983d6;
P_0c0983d4: /* original 0009, guest PC 0x0c0983d4 */
if(!s->budget--) { s->failed_pc=0x0c0983d4u; return 0; }
goto P_0c0983d6;
P_0c0983d6: /* original d31d, guest PC 0x0c0983d6 */
if(!s->budget--) { s->failed_pc=0x0c0983d6u; return 0; }
r[3]=read(ram,0x0c09844cu,4);
goto P_0c0983d8;
P_0c0983d8: /* original e500, guest PC 0x0c0983d8 */
if(!s->budget--) { s->failed_pc=0x0c0983d8u; return 0; }
r[5]=0x00000000u;
goto P_0c0983da;
P_0c0983da: /* original ff8d, guest PC 0x0c0983da */
if(!s->budget--) { s->failed_pc=0x0c0983dau; return 0; }
fr[15]=0;
goto P_0c0983dc;
P_0c0983dc: /* original f4fc, guest PC 0x0c0983dc */
if(!s->budget--) { s->failed_pc=0x0c0983dcu; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c0983de;
P_0c0983de: /* original f5fc, guest PC 0x0c0983de */
if(!s->budget--) { s->failed_pc=0x0c0983deu; return 0; }
vf3_matrix_move(s,5,15);
goto P_0c0983e0;
P_0c0983e0: /* original f6fc, guest PC 0x0c0983e0 */
if(!s->budget--) { s->failed_pc=0x0c0983e0u; return 0; }
vf3_matrix_move(s,6,15);
goto P_0c0983e2;
P_0c0983e2: /* original 430b, guest PC 0x0c0983e2 */
if(!s->budget--) { s->failed_pc=0x0c0983e2u; return 0; }
target=r[3];
r[16]=code_base|0x0c0983e6u;
r[4]=r[5];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0983e6u) { target=s->pc; goto dispatch; }
goto P_0c0983e6;
P_0c0983e4: /* original 6453, guest PC 0x0c0983e4 */
if(!s->budget--) { s->failed_pc=0x0c0983e4u; return 0; }
r[4]=r[5];
goto P_0c0983e6;
P_0c0983e6: /* original d219, guest PC 0x0c0983e6 */
if(!s->budget--) { s->failed_pc=0x0c0983e6u; return 0; }
r[2]=read(ram,0x0c09844cu,4);
goto P_0c0983e8;
P_0c0983e8: /* original e500, guest PC 0x0c0983e8 */
if(!s->budget--) { s->failed_pc=0x0c0983e8u; return 0; }
r[5]=0x00000000u;
goto P_0c0983ea;
P_0c0983ea: /* original f4fc, guest PC 0x0c0983ea */
if(!s->budget--) { s->failed_pc=0x0c0983eau; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c0983ec;
P_0c0983ec: /* original f5fc, guest PC 0x0c0983ec */
if(!s->budget--) { s->failed_pc=0x0c0983ecu; return 0; }
vf3_matrix_move(s,5,15);
goto P_0c0983ee;
P_0c0983ee: /* original f6fc, guest PC 0x0c0983ee */
if(!s->budget--) { s->failed_pc=0x0c0983eeu; return 0; }
vf3_matrix_move(s,6,15);
goto P_0c0983f0;
P_0c0983f0: /* original 420b, guest PC 0x0c0983f0 */
if(!s->budget--) { s->failed_pc=0x0c0983f0u; return 0; }
target=r[2];
r[16]=code_base|0x0c0983f4u;
r[4]=0x00000001u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0983f4u) { target=s->pc; goto dispatch; }
goto P_0c0983f4;
P_0c0983f2: /* original e401, guest PC 0x0c0983f2 */
if(!s->budget--) { s->failed_pc=0x0c0983f2u; return 0; }
r[4]=0x00000001u;
goto P_0c0983f4;
P_0c0983f4: /* original d316, guest PC 0x0c0983f4 */
if(!s->budget--) { s->failed_pc=0x0c0983f4u; return 0; }
r[3]=read(ram,0x0c098450u,4);
goto P_0c0983f6;
P_0c0983f6: /* original 430b, guest PC 0x0c0983f6 */
if(!s->budget--) { s->failed_pc=0x0c0983f6u; return 0; }
target=r[3];
r[16]=code_base|0x0c0983fau;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0983fau) { target=s->pc; goto dispatch; }
goto P_0c0983fa;
P_0c0983f8: /* original 0009, guest PC 0x0c0983f8 */
if(!s->budget--) { s->failed_pc=0x0c0983f8u; return 0; }
goto P_0c0983fa;
P_0c0983fa: /* original 2008, guest PC 0x0c0983fa */
if(!s->budget--) { s->failed_pc=0x0c0983fau; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c0983fc;
P_0c0983fc: /* original 8b02, guest PC 0x0c0983fc */
if(!s->budget--) { s->failed_pc=0x0c0983fcu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c098404; }
goto P_0c0983fe;
P_0c0983fe: /* original e301, guest PC 0x0c0983fe */
if(!s->budget--) { s->failed_pc=0x0c0983feu; return 0; }
r[3]=0x00000001u;
goto P_0c098400;
P_0c098400: /* original a012, guest PC 0x0c098400 */
if(!s->budget--) { s->failed_pc=0x0c098400u; return 0; }
write(ram,r[14]+12,r[3],4);
goto P_0c098428;
P_0c098402: /* original 1e33, guest PC 0x0c098402 */
if(!s->budget--) { s->failed_pc=0x0c098402u; return 0; }
write(ram,r[14]+12,r[3],4);
goto P_0c098404;
P_0c098404: /* original d314, guest PC 0x0c098404 */
if(!s->budget--) { s->failed_pc=0x0c098404u; return 0; }
r[3]=read(ram,0x0c098458u,4);
goto P_0c098406;
P_0c098406: /* original dd13, guest PC 0x0c098406 */
if(!s->budget--) { s->failed_pc=0x0c098406u; return 0; }
r[13]=read(ram,0x0c098454u,4);
goto P_0c098408;
P_0c098408: /* original 430b, guest PC 0x0c098408 */
if(!s->budget--) { s->failed_pc=0x0c098408u; return 0; }
target=r[3];
r[16]=code_base|0x0c09840cu;
r[4]=read(ram,r[13]+32,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09840cu) { target=s->pc; goto dispatch; }
goto P_0c09840c;
P_0c09840a: /* original 54d8, guest PC 0x0c09840a */
if(!s->budget--) { s->failed_pc=0x0c09840au; return 0; }
r[4]=read(ram,r[13]+32,4);
goto P_0c09840c;
P_0c09840c: /* original d312, guest PC 0x0c09840c */
if(!s->budget--) { s->failed_pc=0x0c09840cu; return 0; }
r[3]=read(ram,0x0c098458u,4);
goto P_0c09840e;
P_0c09840e: /* original e044, guest PC 0x0c09840e */
if(!s->budget--) { s->failed_pc=0x0c09840eu; return 0; }
r[0]=0x00000044u;
goto P_0c098410;
P_0c098410: /* original 430b, guest PC 0x0c098410 */
if(!s->budget--) { s->failed_pc=0x0c098410u; return 0; }
target=r[3];
r[16]=code_base|0x0c098414u;
r[4]=read(ram,r[13]+r[0],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c098414u) { target=s->pc; goto dispatch; }
goto P_0c098414;
P_0c098412: /* original 04de, guest PC 0x0c098412 */
if(!s->budget--) { s->failed_pc=0x0c098412u; return 0; }
r[4]=read(ram,r[13]+r[0],4);
goto P_0c098414;
P_0c098414: /* original e029, guest PC 0x0c098414 */
if(!s->budget--) { s->failed_pc=0x0c098414u; return 0; }
r[0]=0x00000029u;
goto P_0c098416;
P_0c098416: /* original 02cc, guest PC 0x0c098416 */
if(!s->budget--) { s->failed_pc=0x0c098416u; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[12]+r[0],1);
goto P_0c098418;
P_0c098418: /* original e300, guest PC 0x0c098418 */
if(!s->budget--) { s->failed_pc=0x0c098418u; return 0; }
r[3]=0x00000000u;
goto P_0c09841a;
P_0c09841a: /* original 900d, guest PC 0x0c09841a */
if(!s->budget--) { s->failed_pc=0x0c09841au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c098438u,2);
goto P_0c09841c;
P_0c09841c: /* original 0e24, guest PC 0x0c09841c */
if(!s->budget--) { s->failed_pc=0x0c09841cu; return 0; }
write(ram,r[14]+r[0],r[2],1);
goto P_0c09841e;
P_0c09841e: /* original 900c, guest PC 0x0c09841e */
if(!s->budget--) { s->failed_pc=0x0c09841eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09843au,2);
goto P_0c098420;
P_0c098420: /* original 0c34, guest PC 0x0c098420 */
if(!s->budget--) { s->failed_pc=0x0c098420u; return 0; }
write(ram,r[12]+r[0],r[3],1);
goto P_0c098422;
P_0c098422: /* original 84eb, guest PC 0x0c098422 */
if(!s->budget--) { s->failed_pc=0x0c098422u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+11,1);
goto P_0c098424;
P_0c098424: /* original 7001, guest PC 0x0c098424 */
if(!s->budget--) { s->failed_pc=0x0c098424u; return 0; }
r[0]+=0x00000001u;
goto P_0c098426;
P_0c098426: /* original 80eb, guest PC 0x0c098426 */
if(!s->budget--) { s->failed_pc=0x0c098426u; return 0; }
write(ram,r[14]+11,r[0],1);
goto P_0c098428;
P_0c098428: /* original 4f26, guest PC 0x0c098428 */
if(!s->budget--) { s->failed_pc=0x0c098428u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c09842a;
P_0c09842a: /* original fff9, guest PC 0x0c09842a */
if(!s->budget--) { s->failed_pc=0x0c09842au; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c09842c;
P_0c09842c: /* original 6cf6, guest PC 0x0c09842c */
if(!s->budget--) { s->failed_pc=0x0c09842cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c09842e;
P_0c09842e: /* original 6df6, guest PC 0x0c09842e */
if(!s->budget--) { s->failed_pc=0x0c09842eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c098430;
P_0c098430: /* original ade0, guest PC 0x0c098430 */
if(!s->budget--) { s->failed_pc=0x0c098430u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c097ff4;
P_0c098432: /* original 6ef6, guest PC 0x0c098432 */
if(!s->budget--) { s->failed_pc=0x0c098432u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c098434u,s,ram);
P_0c09873e: /* original d404, guest PC 0x0c09873e */
if(!s->budget--) { s->failed_pc=0x0c09873eu; return 0; }
r[4]=read(ram,0x0c098750u,4);
goto P_0c098740;
P_0c098740: /* original 844b, guest PC 0x0c098740 */
if(!s->budget--) { s->failed_pc=0x0c098740u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+11,1);
goto P_0c098742;
P_0c098742: /* original 7001, guest PC 0x0c098742 */
if(!s->budget--) { s->failed_pc=0x0c098742u; return 0; }
r[0]+=0x00000001u;
goto P_0c098744;
P_0c098744: /* original ac56, guest PC 0x0c098744 */
if(!s->budget--) { s->failed_pc=0x0c098744u; return 0; }
write(ram,r[4]+11,r[0],1);
goto P_0c097ff4;
P_0c098746: /* original 804b, guest PC 0x0c098746 */
if(!s->budget--) { s->failed_pc=0x0c098746u; return 0; }
write(ram,r[4]+11,r[0],1);
return vf3_matrix_family(0x0c098748u,s,ram);
P_0c098918: /* original 2fe6, guest PC 0x0c098918 */
if(!s->budget--) { s->failed_pc=0x0c098918u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09891a;
P_0c09891a: /* original 2fd6, guest PC 0x0c09891a */
if(!s->budget--) { s->failed_pc=0x0c09891au; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09891c;
P_0c09891c: /* original dd31, guest PC 0x0c09891c */
if(!s->budget--) { s->failed_pc=0x0c09891cu; return 0; }
r[13]=read(ram,0x0c0989e4u,4);
goto P_0c09891e;
P_0c09891e: /* original d430, guest PC 0x0c09891e */
if(!s->budget--) { s->failed_pc=0x0c09891eu; return 0; }
r[4]=read(ram,0x0c0989e0u,4);
goto P_0c098920;
P_0c098920: /* original d331, guest PC 0x0c098920 */
if(!s->budget--) { s->failed_pc=0x0c098920u; return 0; }
r[3]=read(ram,0x0c0989e8u,4);
goto P_0c098922;
P_0c098922: /* original 5242, guest PC 0x0c098922 */
if(!s->budget--) { s->failed_pc=0x0c098922u; return 0; }
r[2]=read(ram,r[4]+8,4);
goto P_0c098924;
P_0c098924: /* original 4f22, guest PC 0x0c098924 */
if(!s->budget--) { s->failed_pc=0x0c098924u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c098926;
P_0c098926: /* original 50d3, guest PC 0x0c098926 */
if(!s->budget--) { s->failed_pc=0x0c098926u; return 0; }
r[0]=read(ram,r[13]+12,4);
goto P_0c098928;
P_0c098928: /* original 883e, guest PC 0x0c098928 */
if(!s->budget--) { s->failed_pc=0x0c098928u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000003eu)!=0);
goto P_0c09892a;
P_0c09892a: /* original 2238, guest PC 0x0c09892a */
if(!s->budget--) { s->failed_pc=0x0c09892au; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c09892c;
P_0c09892c: /* original 8d0a, guest PC 0x0c09892c */
if(!s->budget--) { s->failed_pc=0x0c09892cu; return 0; }
cond=r[17]&1u;
r[14]=r[0];
if(cond) { goto P_0c098944; }
goto P_0c098930;
P_0c09892e: /* original 6e03, guest PC 0x0c09892e */
if(!s->budget--) { s->failed_pc=0x0c09892eu; return 0; }
r[14]=r[0];
goto P_0c098930;
P_0c098930: /* original d02e, guest PC 0x0c098930 */
if(!s->budget--) { s->failed_pc=0x0c098930u; return 0; }
r[0]=read(ram,0x0c0989ecu,4);
goto P_0c098932;
P_0c098932: /* original e300, guest PC 0x0c098932 */
if(!s->budget--) { s->failed_pc=0x0c098932u; return 0; }
r[3]=0x00000000u;
goto P_0c098934;
P_0c098934: /* original d22e, guest PC 0x0c098934 */
if(!s->budget--) { s->failed_pc=0x0c098934u; return 0; }
r[2]=read(ram,0x0c0989f0u,4);
goto P_0c098936;
P_0c098936: /* original 6502, guest PC 0x0c098936 */
if(!s->budget--) { s->failed_pc=0x0c098936u; return 0; }
tmp=read(ram,r[0],4);
r[5]=tmp;
goto P_0c098938;
P_0c098938: /* original e01c, guest PC 0x0c098938 */
if(!s->budget--) { s->failed_pc=0x0c098938u; return 0; }
r[0]=0x0000001cu;
goto P_0c09893a;
P_0c09893a: /* original 6152, guest PC 0x0c09893a */
if(!s->budget--) { s->failed_pc=0x0c09893au; return 0; }
tmp=read(ram,r[5],4);
r[1]=tmp;
goto P_0c09893c;
P_0c09893c: /* original 2129, guest PC 0x0c09893c */
if(!s->budget--) { s->failed_pc=0x0c09893cu; return 0; }
r[1]&=r[2];
goto P_0c09893e;
P_0c09893e: /* original 2512, guest PC 0x0c09893e */
if(!s->budget--) { s->failed_pc=0x0c09893eu; return 0; }
write(ram,r[5],r[1],4);
goto P_0c098940;
P_0c098940: /* original a017, guest PC 0x0c098940 */
if(!s->budget--) { s->failed_pc=0x0c098940u; return 0; }
write(ram,r[4]+r[0],r[3],1);
goto P_0c098972;
P_0c098942: /* original 0434, guest PC 0x0c098942 */
if(!s->budget--) { s->failed_pc=0x0c098942u; return 0; }
write(ram,r[4]+r[0],r[3],1);
goto P_0c098944;
P_0c098944: /* original 5242, guest PC 0x0c098944 */
if(!s->budget--) { s->failed_pc=0x0c098944u; return 0; }
r[2]=read(ram,r[4]+8,4);
goto P_0c098946;
P_0c098946: /* original d321, guest PC 0x0c098946 */
if(!s->budget--) { s->failed_pc=0x0c098946u; return 0; }
r[3]=read(ram,0x0c0989ccu,4);
goto P_0c098948;
P_0c098948: /* original 2238, guest PC 0x0c098948 */
if(!s->budget--) { s->failed_pc=0x0c098948u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c09894a;
P_0c09894a: /* original 8b12, guest PC 0x0c09894a */
if(!s->budget--) { s->failed_pc=0x0c09894au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c098972; }
goto P_0c09894c;
P_0c09894c: /* original e01c, guest PC 0x0c09894c */
if(!s->budget--) { s->failed_pc=0x0c09894cu; return 0; }
r[0]=0x0000001cu;
goto P_0c09894e;
P_0c09894e: /* original 044c, guest PC 0x0c09894e */
if(!s->budget--) { s->failed_pc=0x0c09894eu; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c098950;
P_0c098950: /* original 644c, guest PC 0x0c098950 */
if(!s->budget--) { s->failed_pc=0x0c098950u; return 0; }
r[4]=r[4]&255u;
goto P_0c098952;
P_0c098952: /* original 4410, guest PC 0x0c098952 */
if(!s->budget--) { s->failed_pc=0x0c098952u; return 0; }
--r[4];
r[17]=(r[17]&~1u)|((r[4]==0)!=0);
goto P_0c098954;
P_0c098954: /* original 8b04, guest PC 0x0c098954 */
if(!s->budget--) { s->failed_pc=0x0c098954u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c098960; }
goto P_0c098956;
P_0c098956: /* original 60e3, guest PC 0x0c098956 */
if(!s->budget--) { s->failed_pc=0x0c098956u; return 0; }
r[0]=r[14];
goto P_0c098958;
P_0c098958: /* original 881b, guest PC 0x0c098958 */
if(!s->budget--) { s->failed_pc=0x0c098958u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000001bu)!=0);
goto P_0c09895a;
P_0c09895a: /* original 8b0a, guest PC 0x0c09895a */
if(!s->budget--) { s->failed_pc=0x0c09895au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c098972; }
goto P_0c09895c;
P_0c09895c: /* original a003, guest PC 0x0c09895c */
if(!s->budget--) { s->failed_pc=0x0c09895cu; return 0; }
goto P_0c098966;
P_0c09895e: /* original 0009, guest PC 0x0c09895e */
if(!s->budget--) { s->failed_pc=0x0c09895eu; return 0; }
goto P_0c098960;
P_0c098960: /* original 60e3, guest PC 0x0c098960 */
if(!s->budget--) { s->failed_pc=0x0c098960u; return 0; }
r[0]=r[14];
goto P_0c098962;
P_0c098962: /* original 881b, guest PC 0x0c098962 */
if(!s->budget--) { s->failed_pc=0x0c098962u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000001bu)!=0);
goto P_0c098964;
P_0c098964: /* original 8b05, guest PC 0x0c098964 */
if(!s->budget--) { s->failed_pc=0x0c098964u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c098972; }
goto P_0c098966;
P_0c098966: /* original d023, guest PC 0x0c098966 */
if(!s->budget--) { s->failed_pc=0x0c098966u; return 0; }
r[0]=read(ram,0x0c0989f4u,4);
goto P_0c098968;
P_0c098968: /* original 7401, guest PC 0x0c098968 */
if(!s->budget--) { s->failed_pc=0x0c098968u; return 0; }
r[4]+=0x00000001u;
goto P_0c09896a;
P_0c09896a: /* original d21b, guest PC 0x0c09896a */
if(!s->budget--) { s->failed_pc=0x0c09896au; return 0; }
r[2]=read(ram,0x0c0989d8u,4);
goto P_0c09896c;
P_0c09896c: /* original 4408, guest PC 0x0c09896c */
if(!s->budget--) { s->failed_pc=0x0c09896cu; return 0; }
r[4]<<=2;
goto P_0c09896e;
P_0c09896e: /* original 420b, guest PC 0x0c09896e */
if(!s->budget--) { s->failed_pc=0x0c09896eu; return 0; }
target=r[2];
r[16]=code_base|0x0c098972u;
r[4]=read(ram,r[4]+r[0],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c098972u) { target=s->pc; goto dispatch; }
goto P_0c098972;
P_0c098970: /* original 044e, guest PC 0x0c098970 */
if(!s->budget--) { s->failed_pc=0x0c098970u; return 0; }
r[4]=read(ram,r[4]+r[0],4);
goto P_0c098972;
P_0c098972: /* original 2ee8, guest PC 0x0c098972 */
if(!s->budget--) { s->failed_pc=0x0c098972u; return 0; }
r[17]=(r[17]&~1u)|(((r[14]&r[14])==0)!=0);
goto P_0c098974;
P_0c098974: /* original 8b02, guest PC 0x0c098974 */
if(!s->budget--) { s->failed_pc=0x0c098974u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09897c; }
goto P_0c098976;
P_0c098976: /* original 84db, guest PC 0x0c098976 */
if(!s->budget--) { s->failed_pc=0x0c098976u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+11,1);
goto P_0c098978;
P_0c098978: /* original 7001, guest PC 0x0c098978 */
if(!s->budget--) { s->failed_pc=0x0c098978u; return 0; }
r[0]+=0x00000001u;
goto P_0c09897a;
P_0c09897a: /* original 80db, guest PC 0x0c09897a */
if(!s->budget--) { s->failed_pc=0x0c09897au; return 0; }
write(ram,r[13]+11,r[0],1);
goto P_0c09897c;
P_0c09897c: /* original 4f26, guest PC 0x0c09897c */
if(!s->budget--) { s->failed_pc=0x0c09897cu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c09897e;
P_0c09897e: /* original 6df6, guest PC 0x0c09897e */
if(!s->budget--) { s->failed_pc=0x0c09897eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c098980;
P_0c098980: /* original ab38, guest PC 0x0c098980 */
if(!s->budget--) { s->failed_pc=0x0c098980u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c097ff4;
P_0c098982: /* original 6ef6, guest PC 0x0c098982 */
if(!s->budget--) { s->failed_pc=0x0c098982u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c098984;
P_0c098984: /* original 2fe6, guest PC 0x0c098984 */
if(!s->budget--) { s->failed_pc=0x0c098984u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c098986;
P_0c098986: /* original e010, guest PC 0x0c098986 */
if(!s->budget--) { s->failed_pc=0x0c098986u; return 0; }
r[0]=0x00000010u;
goto P_0c098988;
P_0c098988: /* original 4f22, guest PC 0x0c098988 */
if(!s->budget--) { s->failed_pc=0x0c098988u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c09898a;
P_0c09898a: /* original d315, guest PC 0x0c09898a */
if(!s->budget--) { s->failed_pc=0x0c09898au; return 0; }
r[3]=read(ram,0x0c0989e0u,4);
goto P_0c09898c;
P_0c09898c: /* original e22a, guest PC 0x0c09898c */
if(!s->budget--) { s->failed_pc=0x0c09898cu; return 0; }
r[2]=0x0000002au;
goto P_0c09898e;
P_0c09898e: /* original de15, guest PC 0x0c09898e */
if(!s->budget--) { s->failed_pc=0x0c09898eu; return 0; }
r[14]=read(ram,0x0c0989e4u,4);
goto P_0c098990;
P_0c098990: /* original 7ffc, guest PC 0x0c098990 */
if(!s->budget--) { s->failed_pc=0x0c098990u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c098992;
P_0c098992: /* original 2f32, guest PC 0x0c098992 */
if(!s->budget--) { s->failed_pc=0x0c098992u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c098994;
P_0c098994: /* original e31b, guest PC 0x0c098994 */
if(!s->budget--) { s->failed_pc=0x0c098994u; return 0; }
r[3]=0x0000001bu;
goto P_0c098996;
P_0c098996: /* original 1e23, guest PC 0x0c098996 */
if(!s->budget--) { s->failed_pc=0x0c098996u; return 0; }
write(ram,r[14]+12,r[2],4);
goto P_0c098998;
P_0c098998: /* original 0e34, guest PC 0x0c098998 */
if(!s->budget--) { s->failed_pc=0x0c098998u; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c09899a;
P_0c09899a: /* original d30f, guest PC 0x0c09899a */
if(!s->budget--) { s->failed_pc=0x0c09899au; return 0; }
r[3]=read(ram,0x0c0989d8u,4);
goto P_0c09899c;
P_0c09899c: /* original 430b, guest PC 0x0c09899c */
if(!s->budget--) { s->failed_pc=0x0c09899cu; return 0; }
target=r[3];
r[16]=code_base|0x0c0989a0u;
r[4]=0x00000034u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0989a0u) { target=s->pc; goto dispatch; }
goto P_0c0989a0;
P_0c09899e: /* original e434, guest PC 0x0c09899e */
if(!s->budget--) { s->failed_pc=0x0c09899eu; return 0; }
r[4]=0x00000034u;
goto P_0c0989a0;
P_0c0989a0: /* original 9010, guest PC 0x0c0989a0 */
if(!s->budget--) { s->failed_pc=0x0c0989a0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0989c4u,2);
goto P_0c0989a2;
P_0c0989a2: /* original e300, guest PC 0x0c0989a2 */
if(!s->budget--) { s->failed_pc=0x0c0989a2u; return 0; }
r[3]=0x00000000u;
goto P_0c0989a4;
P_0c0989a4: /* original 62f2, guest PC 0x0c0989a4 */
if(!s->budget--) { s->failed_pc=0x0c0989a4u; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c0989a6;
P_0c0989a6: /* original e602, guest PC 0x0c0989a6 */
if(!s->budget--) { s->failed_pc=0x0c0989a6u; return 0; }
r[6]=0x00000002u;
goto P_0c0989a8;
P_0c0989a8: /* original 7f04, guest PC 0x0c0989a8 */
if(!s->budget--) { s->failed_pc=0x0c0989a8u; return 0; }
r[15]+=0x00000004u;
goto P_0c0989aa;
P_0c0989aa: /* original 0235, guest PC 0x0c0989aa */
if(!s->budget--) { s->failed_pc=0x0c0989aau; return 0; }
write(ram,r[2]+r[0],r[3],2);
goto P_0c0989ac;
P_0c0989ac: /* original d412, guest PC 0x0c0989ac */
if(!s->budget--) { s->failed_pc=0x0c0989acu; return 0; }
r[4]=read(ram,0x0c0989f8u,4);
goto P_0c0989ae;
P_0c0989ae: /* original 900a, guest PC 0x0c0989ae */
if(!s->budget--) { s->failed_pc=0x0c0989aeu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0989c6u,2);
goto P_0c0989b0;
P_0c0989b0: /* original 5544, guest PC 0x0c0989b0 */
if(!s->budget--) { s->failed_pc=0x0c0989b0u; return 0; }
r[5]=read(ram,r[4]+16,4);
goto P_0c0989b2;
P_0c0989b2: /* original 4f26, guest PC 0x0c0989b2 */
if(!s->budget--) { s->failed_pc=0x0c0989b2u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0989b4;
P_0c0989b4: /* original 0564, guest PC 0x0c0989b4 */
if(!s->budget--) { s->failed_pc=0x0c0989b4u; return 0; }
write(ram,r[5]+r[0],r[6],1);
goto P_0c0989b6;
P_0c0989b6: /* original 5445, guest PC 0x0c0989b6 */
if(!s->budget--) { s->failed_pc=0x0c0989b6u; return 0; }
r[4]=read(ram,r[4]+20,4);
goto P_0c0989b8;
P_0c0989b8: /* original 0464, guest PC 0x0c0989b8 */
if(!s->budget--) { s->failed_pc=0x0c0989b8u; return 0; }
write(ram,r[4]+r[0],r[6],1);
goto P_0c0989ba;
P_0c0989ba: /* original 84eb, guest PC 0x0c0989ba */
if(!s->budget--) { s->failed_pc=0x0c0989bau; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+11,1);
goto P_0c0989bc;
P_0c0989bc: /* original 7001, guest PC 0x0c0989bc */
if(!s->budget--) { s->failed_pc=0x0c0989bcu; return 0; }
r[0]+=0x00000001u;
goto P_0c0989be;
P_0c0989be: /* original 80eb, guest PC 0x0c0989be */
if(!s->budget--) { s->failed_pc=0x0c0989beu; return 0; }
write(ram,r[14]+11,r[0],1);
goto P_0c0989c0;
P_0c0989c0: /* original a01c, guest PC 0x0c0989c0 */
if(!s->budget--) { s->failed_pc=0x0c0989c0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0989fc;
P_0c0989c2: /* original 6ef6, guest PC 0x0c0989c2 */
if(!s->budget--) { s->failed_pc=0x0c0989c2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0989c4u,s,ram);
P_0c0989fc: /* original d42c, guest PC 0x0c0989fc */
if(!s->budget--) { s->failed_pc=0x0c0989fcu; return 0; }
r[4]=read(ram,0x0c098ab0u,4);
goto P_0c0989fe;
P_0c0989fe: /* original 5343, guest PC 0x0c0989fe */
if(!s->budget--) { s->failed_pc=0x0c0989feu; return 0; }
r[3]=read(ram,r[4]+12,4);
goto P_0c098a00;
P_0c098a00: /* original 2338, guest PC 0x0c098a00 */
if(!s->budget--) { s->failed_pc=0x0c098a00u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c098a02;
P_0c098a02: /* original 8b02, guest PC 0x0c098a02 */
if(!s->budget--) { s->failed_pc=0x0c098a02u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c098a0a; }
goto P_0c098a04;
P_0c098a04: /* original 844b, guest PC 0x0c098a04 */
if(!s->budget--) { s->failed_pc=0x0c098a04u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+11,1);
goto P_0c098a06;
P_0c098a06: /* original 7001, guest PC 0x0c098a06 */
if(!s->budget--) { s->failed_pc=0x0c098a06u; return 0; }
r[0]+=0x00000001u;
goto P_0c098a08;
P_0c098a08: /* original 804b, guest PC 0x0c098a08 */
if(!s->budget--) { s->failed_pc=0x0c098a08u; return 0; }
write(ram,r[4]+11,r[0],1);
goto P_0c098a0a;
P_0c098a0a: /* original aaf3, guest PC 0x0c098a0a */
if(!s->budget--) { s->failed_pc=0x0c098a0au; return 0; }
goto P_0c097ff4;
P_0c098a0c: /* original 0009, guest PC 0x0c098a0c */
if(!s->budget--) { s->failed_pc=0x0c098a0cu; return 0; }
return vf3_matrix_family(0x0c098a0eu,s,ram);
P_0c098b3c: /* original 2fe6, guest PC 0x0c098b3c */
if(!s->budget--) { s->failed_pc=0x0c098b3cu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c098b3e;
P_0c098b3e: /* original 2fd6, guest PC 0x0c098b3e */
if(!s->budget--) { s->failed_pc=0x0c098b3eu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c098b40;
P_0c098b40: /* original 4f22, guest PC 0x0c098b40 */
if(!s->budget--) { s->failed_pc=0x0c098b40u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c098b42;
P_0c098b42: /* original d32b, guest PC 0x0c098b42 */
if(!s->budget--) { s->failed_pc=0x0c098b42u; return 0; }
r[3]=read(ram,0x0c098bf0u,4);
goto P_0c098b44;
P_0c098b44: /* original de29, guest PC 0x0c098b44 */
if(!s->budget--) { s->failed_pc=0x0c098b44u; return 0; }
r[14]=read(ram,0x0c098becu,4);
goto P_0c098b46;
P_0c098b46: /* original 7ff8, guest PC 0x0c098b46 */
if(!s->budget--) { s->failed_pc=0x0c098b46u; return 0; }
r[15]+=0xfffffff8u;
goto P_0c098b48;
P_0c098b48: /* original 1f31, guest PC 0x0c098b48 */
if(!s->budget--) { s->failed_pc=0x0c098b48u; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c098b4a;
P_0c098b4a: /* original d22a, guest PC 0x0c098b4a */
if(!s->budget--) { s->failed_pc=0x0c098b4au; return 0; }
r[2]=read(ram,0x0c098bf4u,4);
goto P_0c098b4c;
P_0c098b4c: /* original 6423, guest PC 0x0c098b4c */
if(!s->budget--) { s->failed_pc=0x0c098b4cu; return 0; }
r[4]=r[2];
goto P_0c098b4e;
P_0c098b4e: /* original 2f22, guest PC 0x0c098b4e */
if(!s->budget--) { s->failed_pc=0x0c098b4eu; return 0; }
write(ram,r[15],r[2],4);
goto P_0c098b50;
P_0c098b50: /* original d329, guest PC 0x0c098b50 */
if(!s->budget--) { s->failed_pc=0x0c098b50u; return 0; }
r[3]=read(ram,0x0c098bf8u,4);
goto P_0c098b52;
P_0c098b52: /* original 430b, guest PC 0x0c098b52 */
if(!s->budget--) { s->failed_pc=0x0c098b52u; return 0; }
target=r[3];
r[16]=code_base|0x0c098b56u;
r[4]+=0x0000000cu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c098b56u) { target=s->pc; goto dispatch; }
goto P_0c098b56;
P_0c098b54: /* original 740c, guest PC 0x0c098b54 */
if(!s->budget--) { s->failed_pc=0x0c098b54u; return 0; }
r[4]+=0x0000000cu;
goto P_0c098b56;
P_0c098b56: /* original 640c, guest PC 0x0c098b56 */
if(!s->budget--) { s->failed_pc=0x0c098b56u; return 0; }
r[4]=r[0]&255u;
goto P_0c098b58;
P_0c098b58: /* original 2448, guest PC 0x0c098b58 */
if(!s->budget--) { s->failed_pc=0x0c098b58u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c098b5a;
P_0c098b5a: /* original 8b09, guest PC 0x0c098b5a */
if(!s->budget--) { s->failed_pc=0x0c098b5au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c098b70; }
goto P_0c098b5c;
P_0c098b5c: /* original 9036, guest PC 0x0c098b5c */
if(!s->budget--) { s->failed_pc=0x0c098b5cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c098bccu,2);
goto P_0c098b5e;
P_0c098b5e: /* original 00ec, guest PC 0x0c098b5e */
if(!s->budget--) { s->failed_pc=0x0c098b5eu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c098b60;
P_0c098b60: /* original 8801, guest PC 0x0c098b60 */
if(!s->budget--) { s->failed_pc=0x0c098b60u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c098b62;
P_0c098b62: /* original 8b05, guest PC 0x0c098b62 */
if(!s->budget--) { s->failed_pc=0x0c098b62u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c098b70; }
goto P_0c098b64;
P_0c098b64: /* original 9035, guest PC 0x0c098b64 */
if(!s->budget--) { s->failed_pc=0x0c098b64u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c098bd2u,2);
goto P_0c098b66;
P_0c098b66: /* original d325, guest PC 0x0c098b66 */
if(!s->budget--) { s->failed_pc=0x0c098b66u; return 0; }
r[3]=read(ram,0x0c098bfcu,4);
goto P_0c098b68;
P_0c098b68: /* original 9434, guest PC 0x0c098b68 */
if(!s->budget--) { s->failed_pc=0x0c098b68u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c098bd4u,2);
goto P_0c098b6a;
P_0c098b6a: /* original 05ec, guest PC 0x0c098b6a */
if(!s->budget--) { s->failed_pc=0x0c098b6au; return 0; }
r[5]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c098b6c;
P_0c098b6c: /* original 430b, guest PC 0x0c098b6c */
if(!s->budget--) { s->failed_pc=0x0c098b6cu; return 0; }
target=r[3];
r[16]=code_base|0x0c098b70u;
r[5]=r[5]&255u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c098b70u) { target=s->pc; goto dispatch; }
goto P_0c098b70;
P_0c098b6e: /* original 655c, guest PC 0x0c098b6e */
if(!s->budget--) { s->failed_pc=0x0c098b6eu; return 0; }
r[5]=r[5]&255u;
goto P_0c098b70;
P_0c098b70: /* original e029, guest PC 0x0c098b70 */
if(!s->budget--) { s->failed_pc=0x0c098b70u; return 0; }
r[0]=0x00000029u;
goto P_0c098b72;
P_0c098b72: /* original dd23, guest PC 0x0c098b72 */
if(!s->budget--) { s->failed_pc=0x0c098b72u; return 0; }
r[13]=read(ram,0x0c098c00u,4);
goto P_0c098b74;
P_0c098b74: /* original 00ec, guest PC 0x0c098b74 */
if(!s->budget--) { s->failed_pc=0x0c098b74u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c098b76;
P_0c098b76: /* original 600c, guest PC 0x0c098b76 */
if(!s->budget--) { s->failed_pc=0x0c098b76u; return 0; }
r[0]=r[0]&255u;
goto P_0c098b78;
P_0c098b78: /* original 8803, guest PC 0x0c098b78 */
if(!s->budget--) { s->failed_pc=0x0c098b78u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000003u)!=0);
goto P_0c098b7a;
P_0c098b7a: /* original 8902, guest PC 0x0c098b7a */
if(!s->budget--) { s->failed_pc=0x0c098b7au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c098b82; }
goto P_0c098b7c;
P_0c098b7c: /* original 902b, guest PC 0x0c098b7c */
if(!s->budget--) { s->failed_pc=0x0c098b7cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c098bd6u,2);
goto P_0c098b7e;
P_0c098b7e: /* original a003, guest PC 0x0c098b7e */
if(!s->budget--) { s->failed_pc=0x0c098b7eu; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c098b88;
P_0c098b80: /* original 04ec, guest PC 0x0c098b80 */
if(!s->budget--) { s->failed_pc=0x0c098b80u; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c098b82;
P_0c098b82: /* original 4d0b, guest PC 0x0c098b82 */
if(!s->budget--) { s->failed_pc=0x0c098b82u; return 0; }
target=r[13];
r[16]=code_base|0x0c098b86u;
r[4]=0x00000001u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c098b86u) { target=s->pc; goto dispatch; }
goto P_0c098b86;
P_0c098b84: /* original e401, guest PC 0x0c098b84 */
if(!s->budget--) { s->failed_pc=0x0c098b84u; return 0; }
r[4]=0x00000001u;
goto P_0c098b86;
P_0c098b86: /* original e402, guest PC 0x0c098b86 */
if(!s->budget--) { s->failed_pc=0x0c098b86u; return 0; }
r[4]=0x00000002u;
goto P_0c098b88;
P_0c098b88: /* original 4d0b, guest PC 0x0c098b88 */
if(!s->budget--) { s->failed_pc=0x0c098b88u; return 0; }
target=r[13];
r[16]=code_base|0x0c098b8cu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c098b8cu) { target=s->pc; goto dispatch; }
goto P_0c098b8c;
P_0c098b8a: /* original 0009, guest PC 0x0c098b8a */
if(!s->budget--) { s->failed_pc=0x0c098b8au; return 0; }
goto P_0c098b8c;
P_0c098b8c: /* original d41d, guest PC 0x0c098b8c */
if(!s->budget--) { s->failed_pc=0x0c098b8cu; return 0; }
r[4]=read(ram,0x0c098c04u,4);
goto P_0c098b8e;
P_0c098b8e: /* original d61e, guest PC 0x0c098b8e */
if(!s->budget--) { s->failed_pc=0x0c098b8eu; return 0; }
r[6]=read(ram,0x0c098c08u,4);
goto P_0c098b90;
P_0c098b90: /* original 5544, guest PC 0x0c098b90 */
if(!s->budget--) { s->failed_pc=0x0c098b90u; return 0; }
r[5]=read(ram,r[4]+16,4);
goto P_0c098b92;
P_0c098b92: /* original 6252, guest PC 0x0c098b92 */
if(!s->budget--) { s->failed_pc=0x0c098b92u; return 0; }
tmp=read(ram,r[5],4);
r[2]=tmp;
goto P_0c098b94;
P_0c098b94: /* original 2268, guest PC 0x0c098b94 */
if(!s->budget--) { s->failed_pc=0x0c098b94u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[6])==0)!=0);
goto P_0c098b96;
P_0c098b96: /* original 8b5a, guest PC 0x0c098b96 */
if(!s->budget--) { s->failed_pc=0x0c098b96u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c098c4e; }
goto P_0c098b98;
P_0c098b98: /* original 5445, guest PC 0x0c098b98 */
if(!s->budget--) { s->failed_pc=0x0c098b98u; return 0; }
r[4]=read(ram,r[4]+20,4);
goto P_0c098b9a;
P_0c098b9a: /* original 6342, guest PC 0x0c098b9a */
if(!s->budget--) { s->failed_pc=0x0c098b9au; return 0; }
tmp=read(ram,r[4],4);
r[3]=tmp;
goto P_0c098b9c;
P_0c098b9c: /* original 2638, guest PC 0x0c098b9c */
if(!s->budget--) { s->failed_pc=0x0c098b9cu; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[3])==0)!=0);
goto P_0c098b9e;
P_0c098b9e: /* original 8b56, guest PC 0x0c098b9e */
if(!s->budget--) { s->failed_pc=0x0c098b9eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c098c4e; }
goto P_0c098ba0;
P_0c098ba0: /* original d21b, guest PC 0x0c098ba0 */
if(!s->budget--) { s->failed_pc=0x0c098ba0u; return 0; }
r[2]=read(ram,0x0c098c10u,4);
goto P_0c098ba2;
P_0c098ba2: /* original 55e5, guest PC 0x0c098ba2 */
if(!s->budget--) { s->failed_pc=0x0c098ba2u; return 0; }
r[5]=read(ram,r[14]+20,4);
goto P_0c098ba4;
P_0c098ba4: /* original d11b, guest PC 0x0c098ba4 */
if(!s->budget--) { s->failed_pc=0x0c098ba4u; return 0; }
r[1]=read(ram,0x0c098c14u,4);
goto P_0c098ba6;
P_0c098ba6: /* original d319, guest PC 0x0c098ba6 */
if(!s->budget--) { s->failed_pc=0x0c098ba6u; return 0; }
r[3]=read(ram,0x0c098c0cu,4);
goto P_0c098ba8;
P_0c098ba8: /* original 6422, guest PC 0x0c098ba8 */
if(!s->budget--) { s->failed_pc=0x0c098ba8u; return 0; }
tmp=read(ram,r[2],4);
r[4]=tmp;
goto P_0c098baa;
P_0c098baa: /* original 3513, guest PC 0x0c098baa */
if(!s->budget--) { s->failed_pc=0x0c098baau; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[5]>=(int32_t)r[1])!=0);
goto P_0c098bac;
P_0c098bac: /* original 8d36, guest PC 0x0c098bac */
if(!s->budget--) { s->failed_pc=0x0c098bacu; return 0; }
cond=r[17]&1u;
r[4]&=r[3];
if(cond) { goto P_0c098c1c; }
goto P_0c098bb0;
P_0c098bae: /* original 2439, guest PC 0x0c098bae */
if(!s->budget--) { s->failed_pc=0x0c098baeu; return 0; }
r[4]&=r[3];
goto P_0c098bb0;
P_0c098bb0: /* original d019, guest PC 0x0c098bb0 */
if(!s->budget--) { s->failed_pc=0x0c098bb0u; return 0; }
r[0]=read(ram,0x0c098c18u,4);
goto P_0c098bb2;
P_0c098bb2: /* original 3507, guest PC 0x0c098bb2 */
if(!s->budget--) { s->failed_pc=0x0c098bb2u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[5]>(int32_t)r[0])!=0);
goto P_0c098bb4;
P_0c098bb4: /* original 8b32, guest PC 0x0c098bb4 */
if(!s->budget--) { s->failed_pc=0x0c098bb4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c098c1c; }
goto P_0c098bb6;
P_0c098bb6: /* original e029, guest PC 0x0c098bb6 */
if(!s->budget--) { s->failed_pc=0x0c098bb6u; return 0; }
r[0]=0x00000029u;
goto P_0c098bb8;
P_0c098bb8: /* original 00ec, guest PC 0x0c098bb8 */
if(!s->budget--) { s->failed_pc=0x0c098bb8u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c098bba;
P_0c098bba: /* original 600c, guest PC 0x0c098bba */
if(!s->budget--) { s->failed_pc=0x0c098bbau; return 0; }
r[0]=r[0]&255u;
goto P_0c098bbc;
P_0c098bbc: /* original 8803, guest PC 0x0c098bbc */
if(!s->budget--) { s->failed_pc=0x0c098bbcu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000003u)!=0);
goto P_0c098bbe;
P_0c098bbe: /* original 893d, guest PC 0x0c098bbe */
if(!s->budget--) { s->failed_pc=0x0c098bbeu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c098c3c; }
goto P_0c098bc0;
P_0c098bc0: /* original 2448, guest PC 0x0c098bc0 */
if(!s->budget--) { s->failed_pc=0x0c098bc0u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c098bc2;
P_0c098bc2: /* original 8b3b, guest PC 0x0c098bc2 */
if(!s->budget--) { s->failed_pc=0x0c098bc2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c098c3c; }
goto P_0c098bc4;
P_0c098bc4: /* original 52ee, guest PC 0x0c098bc4 */
if(!s->budget--) { s->failed_pc=0x0c098bc4u; return 0; }
r[2]=read(ram,r[14]+56,4);
goto P_0c098bc6;
P_0c098bc6: /* original 7201, guest PC 0x0c098bc6 */
if(!s->budget--) { s->failed_pc=0x0c098bc6u; return 0; }
r[2]+=0x00000001u;
goto P_0c098bc8;
P_0c098bc8: /* original a038, guest PC 0x0c098bc8 */
if(!s->budget--) { s->failed_pc=0x0c098bc8u; return 0; }
write(ram,r[14]+56,r[2],4);
goto P_0c098c3c;
P_0c098bca: /* original 1e2e, guest PC 0x0c098bca */
if(!s->budget--) { s->failed_pc=0x0c098bcau; return 0; }
write(ram,r[14]+56,r[2],4);
return vf3_matrix_family(0x0c098bccu,s,ram);
P_0c098c1c: /* original 2448, guest PC 0x0c098c1c */
if(!s->budget--) { s->failed_pc=0x0c098c1cu; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c098c1e;
P_0c098c1e: /* original 8b0d, guest PC 0x0c098c1e */
if(!s->budget--) { s->failed_pc=0x0c098c1eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c098c3c; }
goto P_0c098c20;
P_0c098c20: /* original e029, guest PC 0x0c098c20 */
if(!s->budget--) { s->failed_pc=0x0c098c20u; return 0; }
r[0]=0x00000029u;
goto P_0c098c22;
P_0c098c22: /* original 00ec, guest PC 0x0c098c22 */
if(!s->budget--) { s->failed_pc=0x0c098c22u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c098c24;
P_0c098c24: /* original 600c, guest PC 0x0c098c24 */
if(!s->budget--) { s->failed_pc=0x0c098c24u; return 0; }
r[0]=r[0]&255u;
goto P_0c098c26;
P_0c098c26: /* original 8803, guest PC 0x0c098c26 */
if(!s->budget--) { s->failed_pc=0x0c098c26u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000003u)!=0);
goto P_0c098c28;
P_0c098c28: /* original 8902, guest PC 0x0c098c28 */
if(!s->budget--) { s->failed_pc=0x0c098c28u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c098c30; }
goto P_0c098c2a;
P_0c098c2a: /* original 52ee, guest PC 0x0c098c2a */
if(!s->budget--) { s->failed_pc=0x0c098c2au; return 0; }
r[2]=read(ram,r[14]+56,4);
goto P_0c098c2c;
P_0c098c2c: /* original 7201, guest PC 0x0c098c2c */
if(!s->budget--) { s->failed_pc=0x0c098c2cu; return 0; }
r[2]+=0x00000001u;
goto P_0c098c2e;
P_0c098c2e: /* original 1e2e, guest PC 0x0c098c2e */
if(!s->budget--) { s->failed_pc=0x0c098c2eu; return 0; }
write(ram,r[14]+56,r[2],4);
goto P_0c098c30;
P_0c098c30: /* original 53e5, guest PC 0x0c098c30 */
if(!s->budget--) { s->failed_pc=0x0c098c30u; return 0; }
r[3]=read(ram,r[14]+20,4);
goto P_0c098c32;
P_0c098c32: /* original 73ff, guest PC 0x0c098c32 */
if(!s->budget--) { s->failed_pc=0x0c098c32u; return 0; }
r[3]+=0xffffffffu;
goto P_0c098c34;
P_0c098c34: /* original 6233, guest PC 0x0c098c34 */
if(!s->budget--) { s->failed_pc=0x0c098c34u; return 0; }
r[2]=r[3];
goto P_0c098c36;
P_0c098c36: /* original 4215, guest PC 0x0c098c36 */
if(!s->budget--) { s->failed_pc=0x0c098c36u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[2]>0)!=0);
goto P_0c098c38;
P_0c098c38: /* original 1e35, guest PC 0x0c098c38 */
if(!s->budget--) { s->failed_pc=0x0c098c38u; return 0; }
write(ram,r[14]+20,r[3],4);
goto P_0c098c3a;
P_0c098c3a: /* original 8b04, guest PC 0x0c098c3a */
if(!s->budget--) { s->failed_pc=0x0c098c3au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c098c46; }
goto P_0c098c3c;
P_0c098c3c: /* original 7f08, guest PC 0x0c098c3c */
if(!s->budget--) { s->failed_pc=0x0c098c3cu; return 0; }
r[15]+=0x00000008u;
goto P_0c098c3e;
P_0c098c3e: /* original 4f26, guest PC 0x0c098c3e */
if(!s->budget--) { s->failed_pc=0x0c098c3eu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c098c40;
P_0c098c40: /* original 6df6, guest PC 0x0c098c40 */
if(!s->budget--) { s->failed_pc=0x0c098c40u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c098c42;
P_0c098c42: /* original a9d7, guest PC 0x0c098c42 */
if(!s->budget--) { s->failed_pc=0x0c098c42u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c097ff4;
P_0c098c44: /* original 6ef6, guest PC 0x0c098c44 */
if(!s->budget--) { s->failed_pc=0x0c098c44u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c098c46;
P_0c098c46: /* original 51e2, guest PC 0x0c098c46 */
if(!s->budget--) { s->failed_pc=0x0c098c46u; return 0; }
r[1]=read(ram,r[14]+8,4);
goto P_0c098c48;
P_0c098c48: /* original d338, guest PC 0x0c098c48 */
if(!s->budget--) { s->failed_pc=0x0c098c48u; return 0; }
r[3]=read(ram,0x0c098d2cu,4);
goto P_0c098c4a;
P_0c098c4a: /* original 213b, guest PC 0x0c098c4a */
if(!s->budget--) { s->failed_pc=0x0c098c4au; return 0; }
r[1]|=r[3];
goto P_0c098c4c;
P_0c098c4c: /* original 1e12, guest PC 0x0c098c4c */
if(!s->budget--) { s->failed_pc=0x0c098c4cu; return 0; }
write(ram,r[14]+8,r[1],4);
goto P_0c098c4e;
P_0c098c4e: /* original 52f1, guest PC 0x0c098c4e */
if(!s->budget--) { s->failed_pc=0x0c098c4eu; return 0; }
r[2]=read(ram,r[15]+4,4);
goto P_0c098c50;
P_0c098c50: /* original 7f08, guest PC 0x0c098c50 */
if(!s->budget--) { s->failed_pc=0x0c098c50u; return 0; }
r[15]+=0x00000008u;
goto P_0c098c52;
P_0c098c52: /* original 4f26, guest PC 0x0c098c52 */
if(!s->budget--) { s->failed_pc=0x0c098c52u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c098c54;
P_0c098c54: /* original 842b, guest PC 0x0c098c54 */
if(!s->budget--) { s->failed_pc=0x0c098c54u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[2]+11,1);
goto P_0c098c56;
P_0c098c56: /* original 7001, guest PC 0x0c098c56 */
if(!s->budget--) { s->failed_pc=0x0c098c56u; return 0; }
r[0]+=0x00000001u;
goto P_0c098c58;
P_0c098c58: /* original 802b, guest PC 0x0c098c58 */
if(!s->budget--) { s->failed_pc=0x0c098c58u; return 0; }
write(ram,r[2]+11,r[0],1);
goto P_0c098c5a;
P_0c098c5a: /* original 6df6, guest PC 0x0c098c5a */
if(!s->budget--) { s->failed_pc=0x0c098c5au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c098c5c;
P_0c098c5c: /* original d334, guest PC 0x0c098c5c */
if(!s->budget--) { s->failed_pc=0x0c098c5cu; return 0; }
r[3]=read(ram,0x0c098d30u,4);
goto P_0c098c5e;
P_0c098c5e: /* original 432b, guest PC 0x0c098c5e */
if(!s->budget--) { s->failed_pc=0x0c098c5eu; return 0; }
target=r[3];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
switch(target&0x1fffffffu) {
case 0x0c03b450u: return vf3_matrix_family(target,s,ram);
case 0x0c03b4b0u: return vf3_matrix_family(target,s,ram);
case 0x0c03b530u: return vf3_matrix_family(target,s,ram);
case 0x0c03b620u: return vf3_matrix_family(target,s,ram);
case 0x0c03b820u: return vf3_matrix_family(target,s,ram);
case 0x0c03bd80u: return vf3_matrix_family(target,s,ram);
case 0x0c03c0e0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c4a0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c4f0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c610u: return vf3_matrix_family(target,s,ram);
case 0x0c03c6c0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c880u: return vf3_matrix_family(target,s,ram);
case 0x0c03c940u: return vf3_matrix_family(target,s,ram);
case 0x0c03c970u: return vf3_matrix_family(target,s,ram);
case 0x0c03cbd0u: return vf3_matrix_family(target,s,ram);
case 0x0c03cc60u: return vf3_matrix_family(target,s,ram);
case 0x0c03cc90u: return vf3_matrix_family(target,s,ram);
case 0x0c03ccb0u: return vf3_matrix_family(target,s,ram);
default: goto dispatch; }
P_0c098c60: /* original 6ef6, guest PC 0x0c098c60 */
if(!s->budget--) { s->failed_pc=0x0c098c60u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c098c62u,s,ram);
P_0c09970a: /* original 4f22, guest PC 0x0c09970a */
if(!s->budget--) { s->failed_pc=0x0c09970au; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c09970c;
P_0c09970c: /* original d31b, guest PC 0x0c09970c */
if(!s->budget--) { s->failed_pc=0x0c09970cu; return 0; }
r[3]=read(ram,0x0c09977cu,4);
goto P_0c09970e;
P_0c09970e: /* original dd18, guest PC 0x0c09970e */
if(!s->budget--) { s->failed_pc=0x0c09970eu; return 0; }
r[13]=read(ram,0x0c099770u,4);
goto P_0c099710;
P_0c099710: /* original 7fec, guest PC 0x0c099710 */
if(!s->budget--) { s->failed_pc=0x0c099710u; return 0; }
r[15]+=0xffffffecu;
goto P_0c099712;
P_0c099712: /* original de18, guest PC 0x0c099712 */
if(!s->budget--) { s->failed_pc=0x0c099712u; return 0; }
r[14]=read(ram,0x0c099774u,4);
goto P_0c099714;
P_0c099714: /* original d815, guest PC 0x0c099714 */
if(!s->budget--) { s->failed_pc=0x0c099714u; return 0; }
r[8]=read(ram,0x0c09976cu,4);
goto P_0c099716;
P_0c099716: /* original db18, guest PC 0x0c099716 */
if(!s->budget--) { s->failed_pc=0x0c099716u; return 0; }
r[11]=read(ram,0x0c099778u,4);
goto P_0c099718;
P_0c099718: /* original ff8d, guest PC 0x0c099718 */
if(!s->budget--) { s->failed_pc=0x0c099718u; return 0; }
fr[15]=0;
goto P_0c09971a;
P_0c09971a: /* original 1f34, guest PC 0x0c09971a */
if(!s->budget--) { s->failed_pc=0x0c09971au; return 0; }
write(ram,r[15]+16,r[3],4);
goto P_0c09971c;
P_0c09971c: /* original 53d5, guest PC 0x0c09971c */
if(!s->budget--) { s->failed_pc=0x0c09971cu; return 0; }
r[3]=read(ram,r[13]+20,4);
goto P_0c09971e;
P_0c09971e: /* original 5cd4, guest PC 0x0c09971e */
if(!s->budget--) { s->failed_pc=0x0c09971eu; return 0; }
r[12]=read(ram,r[13]+16,4);
goto P_0c099720;
P_0c099720: /* original 1f32, guest PC 0x0c099720 */
if(!s->budget--) { s->failed_pc=0x0c099720u; return 0; }
write(ram,r[15]+8,r[3],4);
goto P_0c099722;
P_0c099722: /* original 9022, guest PC 0x0c099722 */
if(!s->budget--) { s->failed_pc=0x0c099722u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09976au,2);
goto P_0c099724;
P_0c099724: /* original 0ea4, guest PC 0x0c099724 */
if(!s->budget--) { s->failed_pc=0x0c099724u; return 0; }
write(ram,r[14]+r[0],r[10],1);
goto P_0c099726;
P_0c099726: /* original 53e2, guest PC 0x0c099726 */
if(!s->budget--) { s->failed_pc=0x0c099726u; return 0; }
r[3]=read(ram,r[14]+8,4);
goto P_0c099728;
P_0c099728: /* original 1f33, guest PC 0x0c099728 */
if(!s->budget--) { s->failed_pc=0x0c099728u; return 0; }
write(ram,r[15]+12,r[3],4);
goto P_0c09972a;
P_0c09972a: /* original d315, guest PC 0x0c09972a */
if(!s->budget--) { s->failed_pc=0x0c09972au; return 0; }
r[3]=read(ram,0x0c099780u,4);
goto P_0c09972c;
P_0c09972c: /* original 54f4, guest PC 0x0c09972c */
if(!s->budget--) { s->failed_pc=0x0c09972cu; return 0; }
r[4]=read(ram,r[15]+16,4);
goto P_0c09972e;
P_0c09972e: /* original 430b, guest PC 0x0c09972e */
if(!s->budget--) { s->failed_pc=0x0c09972eu; return 0; }
target=r[3];
r[16]=code_base|0x0c099732u;
r[4]+=0x00000013u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c099732u) { target=s->pc; goto dispatch; }
goto P_0c099732;
P_0c099730: /* original 7413, guest PC 0x0c099730 */
if(!s->budget--) { s->failed_pc=0x0c099730u; return 0; }
r[4]+=0x00000013u;
goto P_0c099732;
P_0c099732: /* original 600c, guest PC 0x0c099732 */
if(!s->budget--) { s->failed_pc=0x0c099732u; return 0; }
r[0]=r[0]&255u;
goto P_0c099734;
P_0c099734: /* original 1f01, guest PC 0x0c099734 */
if(!s->budget--) { s->failed_pc=0x0c099734u; return 0; }
write(ram,r[15]+4,r[0],4);
goto P_0c099736;
P_0c099736: /* original e029, guest PC 0x0c099736 */
if(!s->budget--) { s->failed_pc=0x0c099736u; return 0; }
r[0]=0x00000029u;
goto P_0c099738;
P_0c099738: /* original 00ec, guest PC 0x0c099738 */
if(!s->budget--) { s->failed_pc=0x0c099738u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c09973a;
P_0c09973a: /* original 600c, guest PC 0x0c09973a */
if(!s->budget--) { s->failed_pc=0x0c09973au; return 0; }
r[0]=r[0]&255u;
goto P_0c09973c;
P_0c09973c: /* original 8803, guest PC 0x0c09973c */
if(!s->budget--) { s->failed_pc=0x0c09973cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000003u)!=0);
goto P_0c09973e;
P_0c09973e: /* original 8b21, guest PC 0x0c09973e */
if(!s->budget--) { s->failed_pc=0x0c09973eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c099784; }
goto P_0c099740;
P_0c099740: /* original 53f1, guest PC 0x0c099740 */
if(!s->budget--) { s->failed_pc=0x0c099740u; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c099742;
P_0c099742: /* original 2338, guest PC 0x0c099742 */
if(!s->budget--) { s->failed_pc=0x0c099742u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c099744;
P_0c099744: /* original 891e, guest PC 0x0c099744 */
if(!s->budget--) { s->failed_pc=0x0c099744u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c099784; }
goto P_0c099746;
P_0c099746: /* original 52f3, guest PC 0x0c099746 */
if(!s->budget--) { s->failed_pc=0x0c099746u; return 0; }
r[2]=read(ram,r[15]+12,4);
goto P_0c099748;
P_0c099748: /* original 2288, guest PC 0x0c099748 */
if(!s->budget--) { s->failed_pc=0x0c099748u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[8])==0)!=0);
goto P_0c09974a;
P_0c09974a: /* original 8b1b, guest PC 0x0c09974a */
if(!s->budget--) { s->failed_pc=0x0c09974au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c099784; }
goto P_0c09974c;
P_0c09974c: /* original 50f3, guest PC 0x0c09974c */
if(!s->budget--) { s->failed_pc=0x0c09974cu; return 0; }
r[0]=read(ram,r[15]+12,4);
goto P_0c09974e;
P_0c09974e: /* original c804, guest PC 0x0c09974e */
if(!s->budget--) { s->failed_pc=0x0c09974eu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&4u)==0)!=0);
goto P_0c099750;
P_0c099750: /* original 8b18, guest PC 0x0c099750 */
if(!s->budget--) { s->failed_pc=0x0c099750u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c099784; }
goto P_0c099752;
P_0c099752: /* original e019, guest PC 0x0c099752 */
if(!s->budget--) { s->failed_pc=0x0c099752u; return 0; }
r[0]=0x00000019u;
goto P_0c099754;
P_0c099754: /* original 00ec, guest PC 0x0c099754 */
if(!s->budget--) { s->failed_pc=0x0c099754u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c099756;
P_0c099756: /* original 600c, guest PC 0x0c099756 */
if(!s->budget--) { s->failed_pc=0x0c099756u; return 0; }
r[0]=r[0]&255u;
goto P_0c099758;
P_0c099758: /* original 8802, guest PC 0x0c099758 */
if(!s->budget--) { s->failed_pc=0x0c099758u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c09975a;
P_0c09975a: /* original 8b13, guest PC 0x0c09975a */
if(!s->budget--) { s->failed_pc=0x0c09975au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c099784; }
goto P_0c09975c;
P_0c09975c: /* original 84bb, guest PC 0x0c09975c */
if(!s->budget--) { s->failed_pc=0x0c09975cu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[11]+11,1);
goto P_0c09975e;
P_0c09975e: /* original 7001, guest PC 0x0c09975e */
if(!s->budget--) { s->failed_pc=0x0c09975eu; return 0; }
r[0]+=0x00000001u;
goto P_0c099760;
P_0c099760: /* original 80bb, guest PC 0x0c099760 */
if(!s->budget--) { s->failed_pc=0x0c099760u; return 0; }
write(ram,r[11]+11,r[0],1);
goto P_0c099762;
P_0c099762: /* original b2d4, guest PC 0x0c099762 */
if(!s->budget--) { s->failed_pc=0x0c099762u; return 0; }
target=0x0c099d0eu; r[16]=code_base|0x0c099766u;
r[4]=r[12];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c099766u) { target=s->pc; goto dispatch; }
goto P_0c099766;
P_0c099764: /* original 64c3, guest PC 0x0c099764 */
if(!s->budget--) { s->failed_pc=0x0c099764u; return 0; }
r[4]=r[12];
goto P_0c099766;
P_0c099766: /* original a260, guest PC 0x0c099766 */
if(!s->budget--) { s->failed_pc=0x0c099766u; return 0; }
goto P_0c099c2a;
P_0c099768: /* original 0009, guest PC 0x0c099768 */
if(!s->budget--) { s->failed_pc=0x0c099768u; return 0; }
return vf3_matrix_family(0x0c09976au,s,ram);
P_0c099784: /* original 54d8, guest PC 0x0c099784 */
if(!s->budget--) { s->failed_pc=0x0c099784u; return 0; }
r[4]=read(ram,r[13]+32,4);
goto P_0c099786;
P_0c099786: /* original d35b, guest PC 0x0c099786 */
if(!s->budget--) { s->failed_pc=0x0c099786u; return 0; }
r[3]=read(ram,0x0c0998f4u,4);
goto P_0c099788;
P_0c099788: /* original 6142, guest PC 0x0c099788 */
if(!s->budget--) { s->failed_pc=0x0c099788u; return 0; }
tmp=read(ram,r[4],4);
r[1]=tmp;
goto P_0c09978a;
P_0c09978a: /* original 2139, guest PC 0x0c09978a */
if(!s->budget--) { s->failed_pc=0x0c09978au; return 0; }
r[1]&=r[3];
goto P_0c09978c;
P_0c09978c: /* original 2f12, guest PC 0x0c09978c */
if(!s->budget--) { s->failed_pc=0x0c09978cu; return 0; }
write(ram,r[15],r[1],4);
goto P_0c09978e;
P_0c09978e: /* original 6213, guest PC 0x0c09978e */
if(!s->budget--) { s->failed_pc=0x0c09978eu; return 0; }
r[2]=r[1];
goto P_0c099790;
P_0c099790: /* original 2412, guest PC 0x0c099790 */
if(!s->budget--) { s->failed_pc=0x0c099790u; return 0; }
write(ram,r[4],r[1],4);
goto P_0c099792;
P_0c099792: /* original 909b, guest PC 0x0c099792 */
if(!s->budget--) { s->failed_pc=0x0c099792u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0998ccu,2);
goto P_0c099794;
P_0c099794: /* original 04a4, guest PC 0x0c099794 */
if(!s->budget--) { s->failed_pc=0x0c099794u; return 0; }
write(ram,r[4]+r[0],r[10],1);
goto P_0c099796;
P_0c099796: /* original d259, guest PC 0x0c099796 */
if(!s->budget--) { s->failed_pc=0x0c099796u; return 0; }
r[2]=read(ram,0x0c0998fcu,4);
goto P_0c099798;
P_0c099798: /* original d457, guest PC 0x0c099798 */
if(!s->budget--) { s->failed_pc=0x0c099798u; return 0; }
r[4]=read(ram,0x0c0998f8u,4);
goto P_0c09979a;
P_0c09979a: /* original 420b, guest PC 0x0c09979a */
if(!s->budget--) { s->failed_pc=0x0c09979au; return 0; }
target=r[2];
r[16]=code_base|0x0c09979eu;
r[5]=0x00000000u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09979eu) { target=s->pc; goto dispatch; }
goto P_0c09979e;
P_0c09979c: /* original e500, guest PC 0x0c09979c */
if(!s->budget--) { s->failed_pc=0x0c09979cu; return 0; }
r[5]=0x00000000u;
goto P_0c09979e;
P_0c09979e: /* original d358, guest PC 0x0c09979e */
if(!s->budget--) { s->failed_pc=0x0c09979eu; return 0; }
r[3]=read(ram,0x0c099900u,4);
goto P_0c0997a0;
P_0c0997a0: /* original 430b, guest PC 0x0c0997a0 */
if(!s->budget--) { s->failed_pc=0x0c0997a0u; return 0; }
target=r[3];
r[16]=code_base|0x0c0997a4u;
r[4]=read(ram,r[13]+16,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0997a4u) { target=s->pc; goto dispatch; }
goto P_0c0997a4;
P_0c0997a2: /* original 54d4, guest PC 0x0c0997a2 */
if(!s->budget--) { s->failed_pc=0x0c0997a2u; return 0; }
r[4]=read(ram,r[13]+16,4);
goto P_0c0997a4;
P_0c0997a4: /* original d256, guest PC 0x0c0997a4 */
if(!s->budget--) { s->failed_pc=0x0c0997a4u; return 0; }
r[2]=read(ram,0x0c099900u,4);
goto P_0c0997a6;
P_0c0997a6: /* original 420b, guest PC 0x0c0997a6 */
if(!s->budget--) { s->failed_pc=0x0c0997a6u; return 0; }
target=r[2];
r[16]=code_base|0x0c0997aau;
r[4]=read(ram,r[13]+20,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0997aau) { target=s->pc; goto dispatch; }
goto P_0c0997aa;
P_0c0997a8: /* original 54d5, guest PC 0x0c0997a8 */
if(!s->budget--) { s->failed_pc=0x0c0997a8u; return 0; }
r[4]=read(ram,r[13]+20,4);
goto P_0c0997aa;
P_0c0997aa: /* original c756, guest PC 0x0c0997aa */
if(!s->budget--) { s->failed_pc=0x0c0997aau; return 0; }
r[0]=0x0c099904u;
goto P_0c0997ac;
P_0c0997ac: /* original f308, guest PC 0x0c0997ac */
if(!s->budget--) { s->failed_pc=0x0c0997acu; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c0997ae;
P_0c0997ae: /* original e042, guest PC 0x0c0997ae */
if(!s->budget--) { s->failed_pc=0x0c0997aeu; return 0; }
r[0]=0x00000042u;
goto P_0c0997b0;
P_0c0997b0: /* original fe3a, guest PC 0x0c0997b0 */
if(!s->budget--) { s->failed_pc=0x0c0997b0u; return 0; }
vf3_matrix_store(s,ram,3,r[14]);
goto P_0c0997b2;
P_0c0997b2: /* original 938c, guest PC 0x0c0997b2 */
if(!s->budget--) { s->failed_pc=0x0c0997b2u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0998ceu,2);
goto P_0c0997b4;
P_0c0997b4: /* original 52e2, guest PC 0x0c0997b4 */
if(!s->budget--) { s->failed_pc=0x0c0997b4u; return 0; }
r[2]=read(ram,r[14]+8,4);
goto P_0c0997b6;
P_0c0997b6: /* original 2239, guest PC 0x0c0997b6 */
if(!s->budget--) { s->failed_pc=0x0c0997b6u; return 0; }
r[2]&=r[3];
goto P_0c0997b8;
P_0c0997b8: /* original 1e22, guest PC 0x0c0997b8 */
if(!s->budget--) { s->failed_pc=0x0c0997b8u; return 0; }
write(ram,r[14]+8,r[2],4);
goto P_0c0997ba;
P_0c0997ba: /* original 51f2, guest PC 0x0c0997ba */
if(!s->budget--) { s->failed_pc=0x0c0997bau; return 0; }
r[1]=read(ram,r[15]+8,4);
goto P_0c0997bc;
P_0c0997bc: /* original 9288, guest PC 0x0c0997bc */
if(!s->budget--) { s->failed_pc=0x0c0997bcu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0998d0u,2);
goto P_0c0997be;
P_0c0997be: /* original 0125, guest PC 0x0c0997be */
if(!s->budget--) { s->failed_pc=0x0c0997beu; return 0; }
write(ram,r[1]+r[0],r[2],2);
goto P_0c0997c0;
P_0c0997c0: /* original 0c25, guest PC 0x0c0997c0 */
if(!s->budget--) { s->failed_pc=0x0c0997c0u; return 0; }
write(ram,r[12]+r[0],r[2],2);
goto P_0c0997c2;
P_0c0997c2: /* original 9086, guest PC 0x0c0997c2 */
if(!s->budget--) { s->failed_pc=0x0c0997c2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0998d2u,2);
goto P_0c0997c4;
P_0c0997c4: /* original 01ed, guest PC 0x0c0997c4 */
if(!s->budget--) { s->failed_pc=0x0c0997c4u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0997c6;
P_0c0997c6: /* original e046, guest PC 0x0c0997c6 */
if(!s->budget--) { s->failed_pc=0x0c0997c6u; return 0; }
r[0]=0x00000046u;
goto P_0c0997c8;
P_0c0997c8: /* original 0c15, guest PC 0x0c0997c8 */
if(!s->budget--) { s->failed_pc=0x0c0997c8u; return 0; }
write(ram,r[12]+r[0],r[1],2);
goto P_0c0997ca;
P_0c0997ca: /* original 9083, guest PC 0x0c0997ca */
if(!s->budget--) { s->failed_pc=0x0c0997cau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0998d4u,2);
goto P_0c0997cc;
P_0c0997cc: /* original 52f2, guest PC 0x0c0997cc */
if(!s->budget--) { s->failed_pc=0x0c0997ccu; return 0; }
r[2]=read(ram,r[15]+8,4);
goto P_0c0997ce;
P_0c0997ce: /* original 01ed, guest PC 0x0c0997ce */
if(!s->budget--) { s->failed_pc=0x0c0997ceu; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0997d0;
P_0c0997d0: /* original e046, guest PC 0x0c0997d0 */
if(!s->budget--) { s->failed_pc=0x0c0997d0u; return 0; }
r[0]=0x00000046u;
goto P_0c0997d2;
P_0c0997d2: /* original 0215, guest PC 0x0c0997d2 */
if(!s->budget--) { s->failed_pc=0x0c0997d2u; return 0; }
write(ram,r[2]+r[0],r[1],2);
goto P_0c0997d4;
P_0c0997d4: /* original 907f, guest PC 0x0c0997d4 */
if(!s->budget--) { s->failed_pc=0x0c0997d4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0998d6u,2);
goto P_0c0997d6;
P_0c0997d6: /* original 02ec, guest PC 0x0c0997d6 */
if(!s->budget--) { s->failed_pc=0x0c0997d6u; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0997d8;
P_0c0997d8: /* original 907e, guest PC 0x0c0997d8 */
if(!s->budget--) { s->failed_pc=0x0c0997d8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0998d8u,2);
goto P_0c0997da;
P_0c0997da: /* original 0c24, guest PC 0x0c0997da */
if(!s->budget--) { s->failed_pc=0x0c0997dau; return 0; }
write(ram,r[12]+r[0],r[2],1);
goto P_0c0997dc;
P_0c0997dc: /* original 907d, guest PC 0x0c0997dc */
if(!s->budget--) { s->failed_pc=0x0c0997dcu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0998dau,2);
goto P_0c0997de;
P_0c0997de: /* original 51f2, guest PC 0x0c0997de */
if(!s->budget--) { s->failed_pc=0x0c0997deu; return 0; }
r[1]=read(ram,r[15]+8,4);
goto P_0c0997e0;
P_0c0997e0: /* original 02ec, guest PC 0x0c0997e0 */
if(!s->budget--) { s->failed_pc=0x0c0997e0u; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0997e2;
P_0c0997e2: /* original 9079, guest PC 0x0c0997e2 */
if(!s->budget--) { s->failed_pc=0x0c0997e2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0998d8u,2);
goto P_0c0997e4;
P_0c0997e4: /* original 0124, guest PC 0x0c0997e4 */
if(!s->budget--) { s->failed_pc=0x0c0997e4u; return 0; }
write(ram,r[1]+r[0],r[2],1);
goto P_0c0997e6;
P_0c0997e6: /* original d248, guest PC 0x0c0997e6 */
if(!s->budget--) { s->failed_pc=0x0c0997e6u; return 0; }
r[2]=read(ram,0x0c099908u,4);
goto P_0c0997e8;
P_0c0997e8: /* original 420b, guest PC 0x0c0997e8 */
if(!s->budget--) { s->failed_pc=0x0c0997e8u; return 0; }
target=r[2];
r[16]=code_base|0x0c0997ecu;
r[4]=read(ram,r[13]+24,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0997ecu) { target=s->pc; goto dispatch; }
goto P_0c0997ec;
P_0c0997ea: /* original 54d6, guest PC 0x0c0997ea */
if(!s->budget--) { s->failed_pc=0x0c0997eau; return 0; }
r[4]=read(ram,r[13]+24,4);
goto P_0c0997ec;
P_0c0997ec: /* original 9076, guest PC 0x0c0997ec */
if(!s->budget--) { s->failed_pc=0x0c0997ecu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0998dcu,2);
goto P_0c0997ee;
P_0c0997ee: /* original 04ee, guest PC 0x0c0997ee */
if(!s->budget--) { s->failed_pc=0x0c0997eeu; return 0; }
r[4]=read(ram,r[14]+r[0],4);
goto P_0c0997f0;
P_0c0997f0: /* original e024, guest PC 0x0c0997f0 */
if(!s->budget--) { s->failed_pc=0x0c0997f0u; return 0; }
r[0]=0x00000024u;
goto P_0c0997f2;
P_0c0997f2: /* original f4f7, guest PC 0x0c0997f2 */
if(!s->budget--) { s->failed_pc=0x0c0997f2u; return 0; }
vf3_matrix_store(s,ram,15,r[4]+r[0]);
goto P_0c0997f4;
P_0c0997f4: /* original e028, guest PC 0x0c0997f4 */
if(!s->budget--) { s->failed_pc=0x0c0997f4u; return 0; }
r[0]=0x00000028u;
goto P_0c0997f6;
P_0c0997f6: /* original f4f7, guest PC 0x0c0997f6 */
if(!s->budget--) { s->failed_pc=0x0c0997f6u; return 0; }
vf3_matrix_store(s,ram,15,r[4]+r[0]);
goto P_0c0997f8;
P_0c0997f8: /* original e02c, guest PC 0x0c0997f8 */
if(!s->budget--) { s->failed_pc=0x0c0997f8u; return 0; }
r[0]=0x0000002cu;
goto P_0c0997fa;
P_0c0997fa: /* original f4f7, guest PC 0x0c0997fa */
if(!s->budget--) { s->failed_pc=0x0c0997fau; return 0; }
vf3_matrix_store(s,ram,15,r[4]+r[0]);
goto P_0c0997fc;
P_0c0997fc: /* original 906f, guest PC 0x0c0997fc */
if(!s->budget--) { s->failed_pc=0x0c0997fcu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0998deu,2);
goto P_0c0997fe;
P_0c0997fe: /* original f4f7, guest PC 0x0c0997fe */
if(!s->budget--) { s->failed_pc=0x0c0997feu; return 0; }
vf3_matrix_store(s,ram,15,r[4]+r[0]);
goto P_0c099800;
P_0c099800: /* original 7004, guest PC 0x0c099800 */
if(!s->budget--) { s->failed_pc=0x0c099800u; return 0; }
r[0]+=0x00000004u;
goto P_0c099802;
P_0c099802: /* original f4f7, guest PC 0x0c099802 */
if(!s->budget--) { s->failed_pc=0x0c099802u; return 0; }
vf3_matrix_store(s,ram,15,r[4]+r[0]);
goto P_0c099804;
P_0c099804: /* original 906c, guest PC 0x0c099804 */
if(!s->budget--) { s->failed_pc=0x0c099804u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0998e0u,2);
goto P_0c099806;
P_0c099806: /* original f4f7, guest PC 0x0c099806 */
if(!s->budget--) { s->failed_pc=0x0c099806u; return 0; }
vf3_matrix_store(s,ram,15,r[4]+r[0]);
goto P_0c099808;
P_0c099808: /* original 7004, guest PC 0x0c099808 */
if(!s->budget--) { s->failed_pc=0x0c099808u; return 0; }
r[0]+=0x00000004u;
goto P_0c09980a;
P_0c09980a: /* original f4f7, guest PC 0x0c09980a */
if(!s->budget--) { s->failed_pc=0x0c09980au; return 0; }
vf3_matrix_store(s,ram,15,r[4]+r[0]);
goto P_0c09980c;
P_0c09980c: /* original 7004, guest PC 0x0c09980c */
if(!s->budget--) { s->failed_pc=0x0c09980cu; return 0; }
r[0]+=0x00000004u;
goto P_0c09980e;
P_0c09980e: /* original f4f7, guest PC 0x0c09980e */
if(!s->budget--) { s->failed_pc=0x0c09980eu; return 0; }
vf3_matrix_store(s,ram,15,r[4]+r[0]);
goto P_0c099810;
P_0c099810: /* original 9067, guest PC 0x0c099810 */
if(!s->budget--) { s->failed_pc=0x0c099810u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0998e2u,2);
goto P_0c099812;
P_0c099812: /* original 04ee, guest PC 0x0c099812 */
if(!s->budget--) { s->failed_pc=0x0c099812u; return 0; }
r[4]=read(ram,r[14]+r[0],4);
goto P_0c099814;
P_0c099814: /* original e024, guest PC 0x0c099814 */
if(!s->budget--) { s->failed_pc=0x0c099814u; return 0; }
r[0]=0x00000024u;
goto P_0c099816;
P_0c099816: /* original f4f7, guest PC 0x0c099816 */
if(!s->budget--) { s->failed_pc=0x0c099816u; return 0; }
vf3_matrix_store(s,ram,15,r[4]+r[0]);
goto P_0c099818;
P_0c099818: /* original e028, guest PC 0x0c099818 */
if(!s->budget--) { s->failed_pc=0x0c099818u; return 0; }
r[0]=0x00000028u;
goto P_0c09981a;
P_0c09981a: /* original f4f7, guest PC 0x0c09981a */
if(!s->budget--) { s->failed_pc=0x0c09981au; return 0; }
vf3_matrix_store(s,ram,15,r[4]+r[0]);
goto P_0c09981c;
P_0c09981c: /* original e02c, guest PC 0x0c09981c */
if(!s->budget--) { s->failed_pc=0x0c09981cu; return 0; }
r[0]=0x0000002cu;
goto P_0c09981e;
P_0c09981e: /* original f4f7, guest PC 0x0c09981e */
if(!s->budget--) { s->failed_pc=0x0c09981eu; return 0; }
vf3_matrix_store(s,ram,15,r[4]+r[0]);
goto P_0c099820;
P_0c099820: /* original 905d, guest PC 0x0c099820 */
if(!s->budget--) { s->failed_pc=0x0c099820u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0998deu,2);
goto P_0c099822;
P_0c099822: /* original f4f7, guest PC 0x0c099822 */
if(!s->budget--) { s->failed_pc=0x0c099822u; return 0; }
vf3_matrix_store(s,ram,15,r[4]+r[0]);
goto P_0c099824;
P_0c099824: /* original 7004, guest PC 0x0c099824 */
if(!s->budget--) { s->failed_pc=0x0c099824u; return 0; }
r[0]+=0x00000004u;
goto P_0c099826;
P_0c099826: /* original f4f7, guest PC 0x0c099826 */
if(!s->budget--) { s->failed_pc=0x0c099826u; return 0; }
vf3_matrix_store(s,ram,15,r[4]+r[0]);
goto P_0c099828;
P_0c099828: /* original 905a, guest PC 0x0c099828 */
if(!s->budget--) { s->failed_pc=0x0c099828u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0998e0u,2);
goto P_0c09982a;
P_0c09982a: /* original f4f7, guest PC 0x0c09982a */
if(!s->budget--) { s->failed_pc=0x0c09982au; return 0; }
vf3_matrix_store(s,ram,15,r[4]+r[0]);
goto P_0c09982c;
P_0c09982c: /* original 7004, guest PC 0x0c09982c */
if(!s->budget--) { s->failed_pc=0x0c09982cu; return 0; }
r[0]+=0x00000004u;
goto P_0c09982e;
P_0c09982e: /* original f4f7, guest PC 0x0c09982e */
if(!s->budget--) { s->failed_pc=0x0c09982eu; return 0; }
vf3_matrix_store(s,ram,15,r[4]+r[0]);
goto P_0c099830;
P_0c099830: /* original 7004, guest PC 0x0c099830 */
if(!s->budget--) { s->failed_pc=0x0c099830u; return 0; }
r[0]+=0x00000004u;
goto P_0c099832;
P_0c099832: /* original f4f7, guest PC 0x0c099832 */
if(!s->budget--) { s->failed_pc=0x0c099832u; return 0; }
vf3_matrix_store(s,ram,15,r[4]+r[0]);
goto P_0c099834;
P_0c099834: /* original 9055, guest PC 0x0c099834 */
if(!s->budget--) { s->failed_pc=0x0c099834u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0998e2u,2);
goto P_0c099836;
P_0c099836: /* original 0cee, guest PC 0x0c099836 */
if(!s->budget--) { s->failed_pc=0x0c099836u; return 0; }
r[12]=read(ram,r[14]+r[0],4);
goto P_0c099838;
P_0c099838: /* original 9054, guest PC 0x0c099838 */
if(!s->budget--) { s->failed_pc=0x0c099838u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0998e4u,2);
goto P_0c09983a;
P_0c09983a: /* original 03cd, guest PC 0x0c09983a */
if(!s->budget--) { s->failed_pc=0x0c09983au; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[12]+r[0],2);
goto P_0c09983c;
P_0c09983c: /* original e03c, guest PC 0x0c09983c */
if(!s->budget--) { s->failed_pc=0x0c09983cu; return 0; }
r[0]=0x0000003cu;
goto P_0c09983e;
P_0c09983e: /* original 623d, guest PC 0x0c09983e */
if(!s->budget--) { s->failed_pc=0x0c09983eu; return 0; }
r[2]=r[3]&65535u;
goto P_0c099840;
P_0c099840: /* original 7263, guest PC 0x0c099840 */
if(!s->budget--) { s->failed_pc=0x0c099840u; return 0; }
r[2]+=0x00000063u;
goto P_0c099842;
P_0c099842: /* original 2f22, guest PC 0x0c099842 */
if(!s->budget--) { s->failed_pc=0x0c099842u; return 0; }
write(ram,r[15],r[2],4);
goto P_0c099844;
P_0c099844: /* original 6323, guest PC 0x0c099844 */
if(!s->budget--) { s->failed_pc=0x0c099844u; return 0; }
r[3]=r[2];
goto P_0c099846;
P_0c099846: /* original 1b23, guest PC 0x0c099846 */
if(!s->budget--) { s->failed_pc=0x0c099846u; return 0; }
write(ram,r[11]+12,r[2],4);
goto P_0c099848;
P_0c099848: /* original 02cd, guest PC 0x0c099848 */
if(!s->budget--) { s->failed_pc=0x0c099848u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,r[12]+r[0],2);
goto P_0c09984a;
P_0c09984a: /* original 934c, guest PC 0x0c09984a */
if(!s->budget--) { s->failed_pc=0x0c09984au; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0998e6u,2);
goto P_0c09984c;
P_0c09984c: /* original 622d, guest PC 0x0c09984c */
if(!s->budget--) { s->failed_pc=0x0c09984cu; return 0; }
r[2]=r[2]&65535u;
goto P_0c09984e;
P_0c09984e: /* original 3230, guest PC 0x0c09984e */
if(!s->budget--) { s->failed_pc=0x0c09984eu; return 0; }
r[17]=(r[17]&~1u)|((r[2]==r[3])!=0);
goto P_0c099850;
P_0c099850: /* original 8b2f, guest PC 0x0c099850 */
if(!s->budget--) { s->failed_pc=0x0c099850u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0998b2; }
goto P_0c099852;
P_0c099852: /* original 9049, guest PC 0x0c099852 */
if(!s->budget--) { s->failed_pc=0x0c099852u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0998e8u,2);
goto P_0c099854;
P_0c099854: /* original 00ec, guest PC 0x0c099854 */
if(!s->budget--) { s->failed_pc=0x0c099854u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c099856;
P_0c099856: /* original 600c, guest PC 0x0c099856 */
if(!s->budget--) { s->failed_pc=0x0c099856u; return 0; }
r[0]=r[0]&255u;
goto P_0c099858;
P_0c099858: /* original 8802, guest PC 0x0c099858 */
if(!s->budget--) { s->failed_pc=0x0c099858u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c09985a;
P_0c09985a: /* original 8b2a, guest PC 0x0c09985a */
if(!s->budget--) { s->failed_pc=0x0c09985au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0998b2; }
goto P_0c09985c;
P_0c09985c: /* original e01c, guest PC 0x0c09985c */
if(!s->budget--) { s->failed_pc=0x0c09985cu; return 0; }
r[0]=0x0000001cu;
goto P_0c09985e;
P_0c09985e: /* original 00bc, guest PC 0x0c09985e */
if(!s->budget--) { s->failed_pc=0x0c09985eu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[11]+r[0],1);
goto P_0c099860;
P_0c099860: /* original 600c, guest PC 0x0c099860 */
if(!s->budget--) { s->failed_pc=0x0c099860u; return 0; }
r[0]=r[0]&255u;
goto P_0c099862;
P_0c099862: /* original c90f, guest PC 0x0c099862 */
if(!s->budget--) { s->failed_pc=0x0c099862u; return 0; }
r[0]&=15u;
goto P_0c099864;
P_0c099864: /* original 880e, guest PC 0x0c099864 */
if(!s->budget--) { s->failed_pc=0x0c099864u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000eu)!=0);
goto P_0c099866;
P_0c099866: /* original 8b24, guest PC 0x0c099866 */
if(!s->budget--) { s->failed_pc=0x0c099866u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0998b2; }
goto P_0c099868;
P_0c099868: /* original e060, guest PC 0x0c099868 */
if(!s->budget--) { s->failed_pc=0x0c099868u; return 0; }
r[0]=0x00000060u;
goto P_0c09986a;
P_0c09986a: /* original 00cc, guest PC 0x0c09986a */
if(!s->budget--) { s->failed_pc=0x0c09986au; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[12]+r[0],1);
goto P_0c09986c;
P_0c09986c: /* original 600c, guest PC 0x0c09986c */
if(!s->budget--) { s->failed_pc=0x0c09986cu; return 0; }
r[0]=r[0]&255u;
goto P_0c09986e;
P_0c09986e: /* original 8810, guest PC 0x0c09986e */
if(!s->budget--) { s->failed_pc=0x0c09986eu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000010u)!=0);
goto P_0c099870;
P_0c099870: /* original 8b1f, guest PC 0x0c099870 */
if(!s->budget--) { s->failed_pc=0x0c099870u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0998b2; }
goto P_0c099872;
P_0c099872: /* original e019, guest PC 0x0c099872 */
if(!s->budget--) { s->failed_pc=0x0c099872u; return 0; }
r[0]=0x00000019u;
goto P_0c099874;
P_0c099874: /* original 00ec, guest PC 0x0c099874 */
if(!s->budget--) { s->failed_pc=0x0c099874u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c099876;
P_0c099876: /* original 600c, guest PC 0x0c099876 */
if(!s->budget--) { s->failed_pc=0x0c099876u; return 0; }
r[0]=r[0]&255u;
goto P_0c099878;
P_0c099878: /* original 8802, guest PC 0x0c099878 */
if(!s->budget--) { s->failed_pc=0x0c099878u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c09987a;
P_0c09987a: /* original 891a, guest PC 0x0c09987a */
if(!s->budget--) { s->failed_pc=0x0c09987au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0998b2; }
goto P_0c09987c;
P_0c09987c: /* original e018, guest PC 0x0c09987c */
if(!s->budget--) { s->failed_pc=0x0c09987cu; return 0; }
r[0]=0x00000018u;
goto P_0c09987e;
P_0c09987e: /* original 03ec, guest PC 0x0c09987e */
if(!s->budget--) { s->failed_pc=0x0c09987eu; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c099880;
P_0c099880: /* original 2338, guest PC 0x0c099880 */
if(!s->budget--) { s->failed_pc=0x0c099880u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c099882;
P_0c099882: /* original 8b16, guest PC 0x0c099882 */
if(!s->budget--) { s->failed_pc=0x0c099882u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0998b2; }
goto P_0c099884;
P_0c099884: /* original e046, guest PC 0x0c099884 */
if(!s->budget--) { s->failed_pc=0x0c099884u; return 0; }
r[0]=0x00000046u;
goto P_0c099886;
P_0c099886: /* original 02cd, guest PC 0x0c099886 */
if(!s->budget--) { s->failed_pc=0x0c099886u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,r[12]+r[0],2);
goto P_0c099888;
P_0c099888: /* original 902f, guest PC 0x0c099888 */
if(!s->budget--) { s->failed_pc=0x0c099888u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0998eau,2);
goto P_0c09988a;
P_0c09988a: /* original 622d, guest PC 0x0c09988a */
if(!s->budget--) { s->failed_pc=0x0c09988au; return 0; }
r[2]=r[2]&65535u;
goto P_0c09988c;
P_0c09988c: /* original 03cd, guest PC 0x0c09988c */
if(!s->budget--) { s->failed_pc=0x0c09988cu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[12]+r[0],2);
goto P_0c09988e;
P_0c09988e: /* original 3230, guest PC 0x0c09988e */
if(!s->budget--) { s->failed_pc=0x0c09988eu; return 0; }
r[17]=(r[17]&~1u)|((r[2]==r[3])!=0);
goto P_0c099890;
P_0c099890: /* original 8b0f, guest PC 0x0c099890 */
if(!s->budget--) { s->failed_pc=0x0c099890u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0998b2; }
goto P_0c099892;
P_0c099892: /* original 902b, guest PC 0x0c099892 */
if(!s->budget--) { s->failed_pc=0x0c099892u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0998ecu,2);
goto P_0c099894;
P_0c099894: /* original 03ce, guest PC 0x0c099894 */
if(!s->budget--) { s->failed_pc=0x0c099894u; return 0; }
r[3]=read(ram,r[12]+r[0],4);
goto P_0c099896;
P_0c099896: /* original 1f91, guest PC 0x0c099896 */
if(!s->budget--) { s->failed_pc=0x0c099896u; return 0; }
write(ram,r[15]+4,r[9],4);
goto P_0c099898;
P_0c099898: /* original 9028, guest PC 0x0c099898 */
if(!s->budget--) { s->failed_pc=0x0c099898u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0998ecu,2);
goto P_0c09989a;
P_0c09989a: /* original 0c96, guest PC 0x0c09989a */
if(!s->budget--) { s->failed_pc=0x0c09989au; return 0; }
write(ram,r[12]+r[0],r[9],4);
goto P_0c09989c;
P_0c09989c: /* original 9022, guest PC 0x0c09989c */
if(!s->budget--) { s->failed_pc=0x0c09989cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0998e4u,2);
goto P_0c09989e;
P_0c09989e: /* original 9226, guest PC 0x0c09989e */
if(!s->budget--) { s->failed_pc=0x0c09989eu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0998eeu,2);
goto P_0c0998a0;
P_0c0998a0: /* original 03cd, guest PC 0x0c0998a0 */
if(!s->budget--) { s->failed_pc=0x0c0998a0u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[12]+r[0],2);
goto P_0c0998a2;
P_0c0998a2: /* original 613d, guest PC 0x0c0998a2 */
if(!s->budget--) { s->failed_pc=0x0c0998a2u; return 0; }
r[1]=r[3]&65535u;
goto P_0c0998a4;
P_0c0998a4: /* original 312c, guest PC 0x0c0998a4 */
if(!s->budget--) { s->failed_pc=0x0c0998a4u; return 0; }
r[1]+=r[2];
goto P_0c0998a6;
P_0c0998a6: /* original 6313, guest PC 0x0c0998a6 */
if(!s->budget--) { s->failed_pc=0x0c0998a6u; return 0; }
r[3]=r[1];
goto P_0c0998a8;
P_0c0998a8: /* original 2f12, guest PC 0x0c0998a8 */
if(!s->budget--) { s->failed_pc=0x0c0998a8u; return 0; }
write(ram,r[15],r[1],4);
goto P_0c0998aa;
P_0c0998aa: /* original 1b13, guest PC 0x0c0998aa */
if(!s->budget--) { s->failed_pc=0x0c0998aau; return 0; }
write(ram,r[11]+12,r[1],4);
goto P_0c0998ac;
P_0c0998ac: /* original d117, guest PC 0x0c0998ac */
if(!s->budget--) { s->failed_pc=0x0c0998acu; return 0; }
r[1]=read(ram,0x0c09990cu,4);
goto P_0c0998ae;
P_0c0998ae: /* original 410b, guest PC 0x0c0998ae */
if(!s->budget--) { s->failed_pc=0x0c0998aeu; return 0; }
target=r[1];
r[16]=code_base|0x0c0998b2u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0998b2u) { target=s->pc; goto dispatch; }
goto P_0c0998b2;
P_0c0998b0: /* original 0009, guest PC 0x0c0998b0 */
if(!s->budget--) { s->failed_pc=0x0c0998b0u; return 0; }
goto P_0c0998b2;
P_0c0998b2: /* original e054, guest PC 0x0c0998b2 */
if(!s->budget--) { s->failed_pc=0x0c0998b2u; return 0; }
r[0]=0x00000054u;
goto P_0c0998b4;
P_0c0998b4: /* original 02ce, guest PC 0x0c0998b4 */
if(!s->budget--) { s->failed_pc=0x0c0998b4u; return 0; }
r[2]=read(ram,r[12]+r[0],4);
goto P_0c0998b6;
P_0c0998b6: /* original e022, guest PC 0x0c0998b6 */
if(!s->budget--) { s->failed_pc=0x0c0998b6u; return 0; }
r[0]=0x00000022u;
goto P_0c0998b8;
P_0c0998b8: /* original 6323, guest PC 0x0c0998b8 */
if(!s->budget--) { s->failed_pc=0x0c0998b8u; return 0; }
r[3]=r[2];
goto P_0c0998ba;
P_0c0998ba: /* original 1f22, guest PC 0x0c0998ba */
if(!s->budget--) { s->failed_pc=0x0c0998bau; return 0; }
write(ram,r[15]+8,r[2],4);
goto P_0c0998bc;
P_0c0998bc: /* original 023d, guest PC 0x0c0998bc */
if(!s->budget--) { s->failed_pc=0x0c0998bcu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,r[3]+r[0],2);
goto P_0c0998be;
P_0c0998be: /* original 9017, guest PC 0x0c0998be */
if(!s->budget--) { s->failed_pc=0x0c0998beu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0998f0u,2);
goto P_0c0998c0;
P_0c0998c0: /* original 7208, guest PC 0x0c0998c0 */
if(!s->budget--) { s->failed_pc=0x0c0998c0u; return 0; }
r[2]+=0x00000008u;
goto P_0c0998c2;
P_0c0998c2: /* original 0c25, guest PC 0x0c0998c2 */
if(!s->budget--) { s->failed_pc=0x0c0998c2u; return 0; }
write(ram,r[12]+r[0],r[2],2);
goto P_0c0998c4;
P_0c0998c4: /* original 84c4, guest PC 0x0c0998c4 */
if(!s->budget--) { s->failed_pc=0x0c0998c4u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[12]+4,1);
goto P_0c0998c6;
P_0c0998c6: /* original 2008, guest PC 0x0c0998c6 */
if(!s->budget--) { s->failed_pc=0x0c0998c6u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c0998c8;
P_0c0998c8: /* original a022, guest PC 0x0c0998c8 */
if(!s->budget--) { s->failed_pc=0x0c0998c8u; return 0; }
goto P_0c099910;
P_0c0998ca: /* original 0009, guest PC 0x0c0998ca */
if(!s->budget--) { s->failed_pc=0x0c0998cau; return 0; }
return vf3_matrix_family(0x0c0998ccu,s,ram);
P_0c099910: /* original 8b07, guest PC 0x0c099910 */
if(!s->budget--) { s->failed_pc=0x0c099910u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c099922; }
goto P_0c099912;
P_0c099912: /* original d33c, guest PC 0x0c099912 */
if(!s->budget--) { s->failed_pc=0x0c099912u; return 0; }
r[3]=read(ram,0x0c099a04u,4);
goto P_0c099914;
P_0c099914: /* original e060, guest PC 0x0c099914 */
if(!s->budget--) { s->failed_pc=0x0c099914u; return 0; }
r[0]=0x00000060u;
goto P_0c099916;
P_0c099916: /* original d53a, guest PC 0x0c099916 */
if(!s->budget--) { s->failed_pc=0x0c099916u; return 0; }
r[5]=read(ram,0x0c099a00u,4);
goto P_0c099918;
P_0c099918: /* original 430b, guest PC 0x0c099918 */
if(!s->budget--) { s->failed_pc=0x0c099918u; return 0; }
target=r[3];
r[16]=code_base|0x0c09991cu;
r[4]=read(ram,r[13]+r[0],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09991cu) { target=s->pc; goto dispatch; }
goto P_0c09991c;
P_0c09991a: /* original 04de, guest PC 0x0c09991a */
if(!s->budget--) { s->failed_pc=0x0c09991au; return 0; }
r[4]=read(ram,r[13]+r[0],4);
goto P_0c09991c;
P_0c09991c: /* original d53a, guest PC 0x0c09991c */
if(!s->budget--) { s->failed_pc=0x0c09991cu; return 0; }
r[5]=read(ram,0x0c099a08u,4);
goto P_0c09991e;
P_0c09991e: /* original a007, guest PC 0x0c09991e */
if(!s->budget--) { s->failed_pc=0x0c09991eu; return 0; }
r[0]=0x00000068u;
goto P_0c099930;
P_0c099920: /* original e068, guest PC 0x0c099920 */
if(!s->budget--) { s->failed_pc=0x0c099920u; return 0; }
r[0]=0x00000068u;
goto P_0c099922;
P_0c099922: /* original d338, guest PC 0x0c099922 */
if(!s->budget--) { s->failed_pc=0x0c099922u; return 0; }
r[3]=read(ram,0x0c099a04u,4);
goto P_0c099924;
P_0c099924: /* original e064, guest PC 0x0c099924 */
if(!s->budget--) { s->failed_pc=0x0c099924u; return 0; }
r[0]=0x00000064u;
goto P_0c099926;
P_0c099926: /* original d536, guest PC 0x0c099926 */
if(!s->budget--) { s->failed_pc=0x0c099926u; return 0; }
r[5]=read(ram,0x0c099a00u,4);
goto P_0c099928;
P_0c099928: /* original 430b, guest PC 0x0c099928 */
if(!s->budget--) { s->failed_pc=0x0c099928u; return 0; }
target=r[3];
r[16]=code_base|0x0c09992cu;
r[4]=read(ram,r[13]+r[0],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09992cu) { target=s->pc; goto dispatch; }
goto P_0c09992c;
P_0c09992a: /* original 04de, guest PC 0x0c09992a */
if(!s->budget--) { s->failed_pc=0x0c09992au; return 0; }
r[4]=read(ram,r[13]+r[0],4);
goto P_0c09992c;
P_0c09992c: /* original d536, guest PC 0x0c09992c */
if(!s->budget--) { s->failed_pc=0x0c09992cu; return 0; }
r[5]=read(ram,0x0c099a08u,4);
goto P_0c09992e;
P_0c09992e: /* original e06c, guest PC 0x0c09992e */
if(!s->budget--) { s->failed_pc=0x0c09992eu; return 0; }
r[0]=0x0000006cu;
goto P_0c099930;
P_0c099930: /* original d334, guest PC 0x0c099930 */
if(!s->budget--) { s->failed_pc=0x0c099930u; return 0; }
r[3]=read(ram,0x0c099a04u,4);
goto P_0c099932;
P_0c099932: /* original 430b, guest PC 0x0c099932 */
if(!s->budget--) { s->failed_pc=0x0c099932u; return 0; }
target=r[3];
r[16]=code_base|0x0c099936u;
r[4]=read(ram,r[13]+r[0],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c099936u) { target=s->pc; goto dispatch; }
goto P_0c099936;
P_0c099934: /* original 04de, guest PC 0x0c099934 */
if(!s->budget--) { s->failed_pc=0x0c099934u; return 0; }
r[4]=read(ram,r[13]+r[0],4);
goto P_0c099936;
P_0c099936: /* original 9061, guest PC 0x0c099936 */
if(!s->budget--) { s->failed_pc=0x0c099936u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0999fcu,2);
goto P_0c099938;
P_0c099938: /* original d634, guest PC 0x0c099938 */
if(!s->budget--) { s->failed_pc=0x0c099938u; return 0; }
r[6]=read(ram,0x0c099a0cu,4);
goto P_0c09993a;
P_0c09993a: /* original 04cd, guest PC 0x0c09993a */
if(!s->budget--) { s->failed_pc=0x0c09993au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[12]+r[0],2);
goto P_0c09993c;
P_0c09993c: /* original 6543, guest PC 0x0c09993c */
if(!s->budget--) { s->failed_pc=0x0c09993cu; return 0; }
r[5]=r[4];
goto P_0c09993e;
P_0c09993e: /* original 75f9, guest PC 0x0c09993e */
if(!s->budget--) { s->failed_pc=0x0c09993eu; return 0; }
r[5]+=0xfffffff9u;
goto P_0c099940;
P_0c099940: /* original 6053, guest PC 0x0c099940 */
if(!s->budget--) { s->failed_pc=0x0c099940u; return 0; }
r[0]=r[5];
goto P_0c099942;
P_0c099942: /* original 4008, guest PC 0x0c099942 */
if(!s->budget--) { s->failed_pc=0x0c099942u; return 0; }
r[0]<<=2;
goto P_0c099944;
P_0c099944: /* original 056e, guest PC 0x0c099944 */
if(!s->budget--) { s->failed_pc=0x0c099944u; return 0; }
r[5]=read(ram,r[6]+r[0],4);
goto P_0c099946;
P_0c099946: /* original 6043, guest PC 0x0c099946 */
if(!s->budget--) { s->failed_pc=0x0c099946u; return 0; }
r[0]=r[4];
goto P_0c099948;
P_0c099948: /* original 4008, guest PC 0x0c099948 */
if(!s->budget--) { s->failed_pc=0x0c099948u; return 0; }
r[0]<<=2;
goto P_0c09994a;
P_0c09994a: /* original 2558, guest PC 0x0c09994a */
if(!s->budget--) { s->failed_pc=0x0c09994au; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[5])==0)!=0);
goto P_0c09994c;
P_0c09994c: /* original 8d08, guest PC 0x0c09994c */
if(!s->budget--) { s->failed_pc=0x0c09994cu; return 0; }
cond=r[17]&1u;
r[4]=read(ram,r[6]+r[0],4);
if(cond) { goto P_0c099960; }
goto P_0c099950;
P_0c09994e: /* original 046e, guest PC 0x0c09994e */
if(!s->budget--) { s->failed_pc=0x0c09994eu; return 0; }
r[4]=read(ram,r[6]+r[0],4);
goto P_0c099950;
P_0c099950: /* original 5551, guest PC 0x0c099950 */
if(!s->budget--) { s->failed_pc=0x0c099950u; return 0; }
r[5]=read(ram,r[5]+4,4);
goto P_0c099952;
P_0c099952: /* original 2558, guest PC 0x0c099952 */
if(!s->budget--) { s->failed_pc=0x0c099952u; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[5])==0)!=0);
goto P_0c099954;
P_0c099954: /* original 8904, guest PC 0x0c099954 */
if(!s->budget--) { s->failed_pc=0x0c099954u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c099960; }
goto P_0c099956;
P_0c099956: /* original 5652, guest PC 0x0c099956 */
if(!s->budget--) { s->failed_pc=0x0c099956u; return 0; }
r[6]=read(ram,r[5]+8,4);
goto P_0c099958;
P_0c099958: /* original 2448, guest PC 0x0c099958 */
if(!s->budget--) { s->failed_pc=0x0c099958u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c09995a;
P_0c09995a: /* original 8901, guest PC 0x0c09995a */
if(!s->budget--) { s->failed_pc=0x0c09995au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c099960; }
goto P_0c09995c;
P_0c09995c: /* original a00e, guest PC 0x0c09995c */
if(!s->budget--) { s->failed_pc=0x0c09995cu; return 0; }
r[7]=read(ram,r[4]+4,4);
goto P_0c09997c;
P_0c09995e: /* original 5741, guest PC 0x0c09995e */
if(!s->budget--) { s->failed_pc=0x0c09995eu; return 0; }
r[7]=read(ram,r[4]+4,4);
goto P_0c099960;
P_0c099960: /* original d32b, guest PC 0x0c099960 */
if(!s->budget--) { s->failed_pc=0x0c099960u; return 0; }
r[3]=read(ram,0x0c099a10u,4);
goto P_0c099962;
P_0c099962: /* original e060, guest PC 0x0c099962 */
if(!s->budget--) { s->failed_pc=0x0c099962u; return 0; }
r[0]=0x00000060u;
goto P_0c099964;
P_0c099964: /* original 430b, guest PC 0x0c099964 */
if(!s->budget--) { s->failed_pc=0x0c099964u; return 0; }
target=r[3];
r[16]=code_base|0x0c099968u;
r[4]=read(ram,r[13]+r[0],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c099968u) { target=s->pc; goto dispatch; }
goto P_0c099968;
P_0c099966: /* original 04de, guest PC 0x0c099966 */
if(!s->budget--) { s->failed_pc=0x0c099966u; return 0; }
r[4]=read(ram,r[13]+r[0],4);
goto P_0c099968;
P_0c099968: /* original d329, guest PC 0x0c099968 */
if(!s->budget--) { s->failed_pc=0x0c099968u; return 0; }
r[3]=read(ram,0x0c099a10u,4);
goto P_0c09996a;
P_0c09996a: /* original e064, guest PC 0x0c09996a */
if(!s->budget--) { s->failed_pc=0x0c09996au; return 0; }
r[0]=0x00000064u;
goto P_0c09996c;
P_0c09996c: /* original 430b, guest PC 0x0c09996c */
if(!s->budget--) { s->failed_pc=0x0c09996cu; return 0; }
target=r[3];
r[16]=code_base|0x0c099970u;
r[4]=read(ram,r[13]+r[0],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c099970u) { target=s->pc; goto dispatch; }
goto P_0c099970;
P_0c09996e: /* original 04de, guest PC 0x0c09996e */
if(!s->budget--) { s->failed_pc=0x0c09996eu; return 0; }
r[4]=read(ram,r[13]+r[0],4);
goto P_0c099970;
P_0c099970: /* original 52f2, guest PC 0x0c099970 */
if(!s->budget--) { s->failed_pc=0x0c099970u; return 0; }
r[2]=read(ram,r[15]+8,4);
goto P_0c099972;
P_0c099972: /* original e022, guest PC 0x0c099972 */
if(!s->budget--) { s->failed_pc=0x0c099972u; return 0; }
r[0]=0x00000022u;
goto P_0c099974;
P_0c099974: /* original 032d, guest PC 0x0c099974 */
if(!s->budget--) { s->failed_pc=0x0c099974u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[2]+r[0],2);
goto P_0c099976;
P_0c099976: /* original 9041, guest PC 0x0c099976 */
if(!s->budget--) { s->failed_pc=0x0c099976u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0999fcu,2);
goto P_0c099978;
P_0c099978: /* original a019, guest PC 0x0c099978 */
if(!s->budget--) { s->failed_pc=0x0c099978u; return 0; }
write(ram,r[12]+r[0],r[3],2);
goto P_0c0999ae;
P_0c09997a: /* original 0c35, guest PC 0x0c09997a */
if(!s->budget--) { s->failed_pc=0x0c09997au; return 0; }
write(ram,r[12]+r[0],r[3],2);
goto P_0c09997c;
P_0c09997c: /* original 5451, guest PC 0x0c09997c */
if(!s->budget--) { s->failed_pc=0x0c09997cu; return 0; }
r[4]=read(ram,r[5]+4,4);
goto P_0c09997e;
P_0c09997e: /* original 4615, guest PC 0x0c09997e */
if(!s->budget--) { s->failed_pc=0x0c09997eu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[6]>0)!=0);
goto P_0c099980;
P_0c099980: /* original 8f15, guest PC 0x0c099980 */
if(!s->budget--) { s->failed_pc=0x0c099980u; return 0; }
cond=r[17]&1u;
r[5]=read(ram,r[7]+4,4);
if(!cond) { goto P_0c0999ae; }
goto P_0c099984;
P_0c099982: /* original 5571, guest PC 0x0c099982 */
if(!s->budget--) { s->failed_pc=0x0c099982u; return 0; }
r[5]=read(ram,r[7]+4,4);
goto P_0c099984;
P_0c099984: /* original f349, guest PC 0x0c099984 */
if(!s->budget--) { s->failed_pc=0x0c099984u; return 0; }
vf3_matrix_load(s,ram,3,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c099986;
P_0c099986: /* original 76ff, guest PC 0x0c099986 */
if(!s->budget--) { s->failed_pc=0x0c099986u; return 0; }
r[6]+=0xffffffffu;
goto P_0c099988;
P_0c099988: /* original 4615, guest PC 0x0c099988 */
if(!s->budget--) { s->failed_pc=0x0c099988u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[6]>0)!=0);
goto P_0c09998a;
P_0c09998a: /* original f53a, guest PC 0x0c09998a */
if(!s->budget--) { s->failed_pc=0x0c09998au; return 0; }
vf3_matrix_store(s,ram,3,r[5]);
goto P_0c09998c;
P_0c09998c: /* original 7504, guest PC 0x0c09998c */
if(!s->budget--) { s->failed_pc=0x0c09998cu; return 0; }
r[5]+=0x00000004u;
goto P_0c09998e;
P_0c09998e: /* original f349, guest PC 0x0c09998e */
if(!s->budget--) { s->failed_pc=0x0c09998eu; return 0; }
vf3_matrix_load(s,ram,3,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c099990;
P_0c099990: /* original f53a, guest PC 0x0c099990 */
if(!s->budget--) { s->failed_pc=0x0c099990u; return 0; }
vf3_matrix_store(s,ram,3,r[5]);
goto P_0c099992;
P_0c099992: /* original 7504, guest PC 0x0c099992 */
if(!s->budget--) { s->failed_pc=0x0c099992u; return 0; }
r[5]+=0x00000004u;
goto P_0c099994;
P_0c099994: /* original f349, guest PC 0x0c099994 */
if(!s->budget--) { s->failed_pc=0x0c099994u; return 0; }
vf3_matrix_load(s,ram,3,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c099996;
P_0c099996: /* original f53a, guest PC 0x0c099996 */
if(!s->budget--) { s->failed_pc=0x0c099996u; return 0; }
vf3_matrix_store(s,ram,3,r[5]);
goto P_0c099998;
P_0c099998: /* original 7504, guest PC 0x0c099998 */
if(!s->budget--) { s->failed_pc=0x0c099998u; return 0; }
r[5]+=0x00000004u;
goto P_0c09999a;
P_0c09999a: /* original f349, guest PC 0x0c09999a */
if(!s->budget--) { s->failed_pc=0x0c09999au; return 0; }
vf3_matrix_load(s,ram,3,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c09999c;
P_0c09999c: /* original f53a, guest PC 0x0c09999c */
if(!s->budget--) { s->failed_pc=0x0c09999cu; return 0; }
vf3_matrix_store(s,ram,3,r[5]);
goto P_0c09999e;
P_0c09999e: /* original 7504, guest PC 0x0c09999e */
if(!s->budget--) { s->failed_pc=0x0c09999eu; return 0; }
r[5]+=0x00000004u;
goto P_0c0999a0;
P_0c0999a0: /* original f349, guest PC 0x0c0999a0 */
if(!s->budget--) { s->failed_pc=0x0c0999a0u; return 0; }
vf3_matrix_load(s,ram,3,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c0999a2;
P_0c0999a2: /* original f53a, guest PC 0x0c0999a2 */
if(!s->budget--) { s->failed_pc=0x0c0999a2u; return 0; }
vf3_matrix_store(s,ram,3,r[5]);
goto P_0c0999a4;
P_0c0999a4: /* original 7504, guest PC 0x0c0999a4 */
if(!s->budget--) { s->failed_pc=0x0c0999a4u; return 0; }
r[5]+=0x00000004u;
goto P_0c0999a6;
P_0c0999a6: /* original f349, guest PC 0x0c0999a6 */
if(!s->budget--) { s->failed_pc=0x0c0999a6u; return 0; }
vf3_matrix_load(s,ram,3,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c0999a8;
P_0c0999a8: /* original f53a, guest PC 0x0c0999a8 */
if(!s->budget--) { s->failed_pc=0x0c0999a8u; return 0; }
vf3_matrix_store(s,ram,3,r[5]);
goto P_0c0999aa;
P_0c0999aa: /* original 8deb, guest PC 0x0c0999aa */
if(!s->budget--) { s->failed_pc=0x0c0999aau; return 0; }
cond=r[17]&1u;
r[5]+=0x00000004u;
if(cond) { goto P_0c099984; }
goto P_0c0999ae;
P_0c0999ac: /* original 7504, guest PC 0x0c0999ac */
if(!s->budget--) { s->failed_pc=0x0c0999acu; return 0; }
r[5]+=0x00000004u;
goto P_0c0999ae;
P_0c0999ae: /* original e010, guest PC 0x0c0999ae */
if(!s->budget--) { s->failed_pc=0x0c0999aeu; return 0; }
r[0]=0x00000010u;
goto P_0c0999b0;
P_0c0999b0: /* original e221, guest PC 0x0c0999b0 */
if(!s->budget--) { s->failed_pc=0x0c0999b0u; return 0; }
r[2]=0x00000021u;
goto P_0c0999b2;
P_0c0999b2: /* original 0b24, guest PC 0x0c0999b2 */
if(!s->budget--) { s->failed_pc=0x0c0999b2u; return 0; }
write(ram,r[11]+r[0],r[2],1);
goto P_0c0999b4;
P_0c0999b4: /* original 9023, guest PC 0x0c0999b4 */
if(!s->budget--) { s->failed_pc=0x0c0999b4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0999feu,2);
goto P_0c0999b6;
P_0c0999b6: /* original 54d8, guest PC 0x0c0999b6 */
if(!s->budget--) { s->failed_pc=0x0c0999b6u; return 0; }
r[4]=read(ram,r[13]+32,4);
goto P_0c0999b8;
P_0c0999b8: /* original 0494, guest PC 0x0c0999b8 */
if(!s->budget--) { s->failed_pc=0x0c0999b8u; return 0; }
write(ram,r[4]+r[0],r[9],1);
goto P_0c0999ba;
P_0c0999ba: /* original 53e2, guest PC 0x0c0999ba */
if(!s->budget--) { s->failed_pc=0x0c0999bau; return 0; }
r[3]=read(ram,r[14]+8,4);
goto P_0c0999bc;
P_0c0999bc: /* original 2388, guest PC 0x0c0999bc */
if(!s->budget--) { s->failed_pc=0x0c0999bcu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[8])==0)!=0);
goto P_0c0999be;
P_0c0999be: /* original 8903, guest PC 0x0c0999be */
if(!s->budget--) { s->failed_pc=0x0c0999beu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0999c8; }
goto P_0c0999c0;
P_0c0999c0: /* original 0494, guest PC 0x0c0999c0 */
if(!s->budget--) { s->failed_pc=0x0c0999c0u; return 0; }
write(ram,r[4]+r[0],r[9],1);
goto P_0c0999c2;
P_0c0999c2: /* original d314, guest PC 0x0c0999c2 */
if(!s->budget--) { s->failed_pc=0x0c0999c2u; return 0; }
r[3]=read(ram,0x0c099a14u,4);
goto P_0c0999c4;
P_0c0999c4: /* original 430b, guest PC 0x0c0999c4 */
if(!s->budget--) { s->failed_pc=0x0c0999c4u; return 0; }
target=r[3];
r[16]=code_base|0x0c0999c8u;
r[4]=0x00000008u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0999c8u) { target=s->pc; goto dispatch; }
goto P_0c0999c8;
P_0c0999c6: /* original e408, guest PC 0x0c0999c6 */
if(!s->budget--) { s->failed_pc=0x0c0999c6u; return 0; }
r[4]=0x00000008u;
goto P_0c0999c8;
P_0c0999c8: /* original e029, guest PC 0x0c0999c8 */
if(!s->budget--) { s->failed_pc=0x0c0999c8u; return 0; }
r[0]=0x00000029u;
goto P_0c0999ca;
P_0c0999ca: /* original 00ec, guest PC 0x0c0999ca */
if(!s->budget--) { s->failed_pc=0x0c0999cau; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0999cc;
P_0c0999cc: /* original 600c, guest PC 0x0c0999cc */
if(!s->budget--) { s->failed_pc=0x0c0999ccu; return 0; }
r[0]=r[0]&255u;
goto P_0c0999ce;
P_0c0999ce: /* original 8803, guest PC 0x0c0999ce */
if(!s->budget--) { s->failed_pc=0x0c0999ceu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000003u)!=0);
goto P_0c0999d0;
P_0c0999d0: /* original 8b01, guest PC 0x0c0999d0 */
if(!s->budget--) { s->failed_pc=0x0c0999d0u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0999d6; }
goto P_0c0999d2;
P_0c0999d2: /* original a0fe, guest PC 0x0c0999d2 */
if(!s->budget--) { s->failed_pc=0x0c0999d2u; return 0; }
goto P_0c099bd2;
P_0c0999d4: /* original 0009, guest PC 0x0c0999d4 */
if(!s->budget--) { s->failed_pc=0x0c0999d4u; return 0; }
goto P_0c0999d6;
P_0c0999d6: /* original 53e2, guest PC 0x0c0999d6 */
if(!s->budget--) { s->failed_pc=0x0c0999d6u; return 0; }
r[3]=read(ram,r[14]+8,4);
goto P_0c0999d8;
P_0c0999d8: /* original 2388, guest PC 0x0c0999d8 */
if(!s->budget--) { s->failed_pc=0x0c0999d8u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[8])==0)!=0);
goto P_0c0999da;
P_0c0999da: /* original 8b01, guest PC 0x0c0999da */
if(!s->budget--) { s->failed_pc=0x0c0999dau; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0999e0; }
goto P_0c0999dc;
P_0c0999dc: /* original a0f9, guest PC 0x0c0999dc */
if(!s->budget--) { s->failed_pc=0x0c0999dcu; return 0; }
goto P_0c099bd2;
P_0c0999de: /* original 0009, guest PC 0x0c0999de */
if(!s->budget--) { s->failed_pc=0x0c0999deu; return 0; }
goto P_0c0999e0;
P_0c0999e0: /* original e029, guest PC 0x0c0999e0 */
if(!s->budget--) { s->failed_pc=0x0c0999e0u; return 0; }
r[0]=0x00000029u;
goto P_0c0999e2;
P_0c0999e2: /* original 00ec, guest PC 0x0c0999e2 */
if(!s->budget--) { s->failed_pc=0x0c0999e2u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0999e4;
P_0c0999e4: /* original 600c, guest PC 0x0c0999e4 */
if(!s->budget--) { s->failed_pc=0x0c0999e4u; return 0; }
r[0]=r[0]&255u;
goto P_0c0999e6;
P_0c0999e6: /* original 8801, guest PC 0x0c0999e6 */
if(!s->budget--) { s->failed_pc=0x0c0999e6u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c0999e8;
P_0c0999e8: /* original 8916, guest PC 0x0c0999e8 */
if(!s->budget--) { s->failed_pc=0x0c0999e8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c099a18; }
goto P_0c0999ea;
P_0c0999ea: /* original e01d, guest PC 0x0c0999ea */
if(!s->budget--) { s->failed_pc=0x0c0999eau; return 0; }
r[0]=0x0000001du;
goto P_0c0999ec;
P_0c0999ec: /* original 00ec, guest PC 0x0c0999ec */
if(!s->budget--) { s->failed_pc=0x0c0999ecu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0999ee;
P_0c0999ee: /* original 600c, guest PC 0x0c0999ee */
if(!s->budget--) { s->failed_pc=0x0c0999eeu; return 0; }
r[0]=r[0]&255u;
goto P_0c0999f0;
P_0c0999f0: /* original 8801, guest PC 0x0c0999f0 */
if(!s->budget--) { s->failed_pc=0x0c0999f0u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c0999f2;
P_0c0999f2: /* original 8b01, guest PC 0x0c0999f2 */
if(!s->budget--) { s->failed_pc=0x0c0999f2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0999f8; }
goto P_0c0999f4;
P_0c0999f4: /* original a0ed, guest PC 0x0c0999f4 */
if(!s->budget--) { s->failed_pc=0x0c0999f4u; return 0; }
goto P_0c099bd2;
P_0c0999f6: /* original 0009, guest PC 0x0c0999f6 */
if(!s->budget--) { s->failed_pc=0x0c0999f6u; return 0; }
goto P_0c0999f8;
P_0c0999f8: /* original a014, guest PC 0x0c0999f8 */
if(!s->budget--) { s->failed_pc=0x0c0999f8u; return 0; }
goto P_0c099a24;
P_0c0999fa: /* original 0009, guest PC 0x0c0999fa */
if(!s->budget--) { s->failed_pc=0x0c0999fau; return 0; }
return vf3_matrix_family(0x0c0999fcu,s,ram);
P_0c099a18: /* original e01d, guest PC 0x0c099a18 */
if(!s->budget--) { s->failed_pc=0x0c099a18u; return 0; }
r[0]=0x0000001du;
goto P_0c099a1a;
P_0c099a1a: /* original 02ec, guest PC 0x0c099a1a */
if(!s->budget--) { s->failed_pc=0x0c099a1au; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c099a1c;
P_0c099a1c: /* original 2228, guest PC 0x0c099a1c */
if(!s->budget--) { s->failed_pc=0x0c099a1cu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c099a1e;
P_0c099a1e: /* original 8b01, guest PC 0x0c099a1e */
if(!s->budget--) { s->failed_pc=0x0c099a1eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c099a24; }
goto P_0c099a20;
P_0c099a20: /* original a0d7, guest PC 0x0c099a20 */
if(!s->budget--) { s->failed_pc=0x0c099a20u; return 0; }
goto P_0c099bd2;
P_0c099a22: /* original 0009, guest PC 0x0c099a22 */
if(!s->budget--) { s->failed_pc=0x0c099a22u; return 0; }
goto P_0c099a24;
P_0c099a24: /* original 90a5, guest PC 0x0c099a24 */
if(!s->budget--) { s->failed_pc=0x0c099a24u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c099b72u,2);
goto P_0c099a26;
P_0c099a26: /* original 0cee, guest PC 0x0c099a26 */
if(!s->budget--) { s->failed_pc=0x0c099a26u; return 0; }
r[12]=read(ram,r[14]+r[0],4);
goto P_0c099a28;
P_0c099a28: /* original e018, guest PC 0x0c099a28 */
if(!s->budget--) { s->failed_pc=0x0c099a28u; return 0; }
r[0]=0x00000018u;
goto P_0c099a2a;
P_0c099a2a: /* original 00ec, guest PC 0x0c099a2a */
if(!s->budget--) { s->failed_pc=0x0c099a2au; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c099a2c;
P_0c099a2c: /* original 600c, guest PC 0x0c099a2c */
if(!s->budget--) { s->failed_pc=0x0c099a2cu; return 0; }
r[0]=r[0]&255u;
goto P_0c099a2e;
P_0c099a2e: /* original 8802, guest PC 0x0c099a2e */
if(!s->budget--) { s->failed_pc=0x0c099a2eu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c099a30;
P_0c099a30: /* original 8926, guest PC 0x0c099a30 */
if(!s->budget--) { s->failed_pc=0x0c099a30u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c099a80; }
goto P_0c099a32;
P_0c099a32: /* original e046, guest PC 0x0c099a32 */
if(!s->budget--) { s->failed_pc=0x0c099a32u; return 0; }
r[0]=0x00000046u;
goto P_0c099a34;
P_0c099a34: /* original 0ca5, guest PC 0x0c099a34 */
if(!s->budget--) { s->failed_pc=0x0c099a34u; return 0; }
write(ram,r[12]+r[0],r[10],2);
goto P_0c099a36;
P_0c099a36: /* original e024, guest PC 0x0c099a36 */
if(!s->budget--) { s->failed_pc=0x0c099a36u; return 0; }
r[0]=0x00000024u;
goto P_0c099a38;
P_0c099a38: /* original fcf7, guest PC 0x0c099a38 */
if(!s->budget--) { s->failed_pc=0x0c099a38u; return 0; }
vf3_matrix_store(s,ram,15,r[12]+r[0]);
goto P_0c099a3a;
P_0c099a3a: /* original e02c, guest PC 0x0c099a3a */
if(!s->budget--) { s->failed_pc=0x0c099a3au; return 0; }
r[0]=0x0000002cu;
goto P_0c099a3c;
P_0c099a3c: /* original fcf7, guest PC 0x0c099a3c */
if(!s->budget--) { s->failed_pc=0x0c099a3cu; return 0; }
vf3_matrix_store(s,ram,15,r[12]+r[0]);
goto P_0c099a3e;
P_0c099a3e: /* original 9099, guest PC 0x0c099a3e */
if(!s->budget--) { s->failed_pc=0x0c099a3eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c099b74u,2);
goto P_0c099a40;
P_0c099a40: /* original fcf7, guest PC 0x0c099a40 */
if(!s->budget--) { s->failed_pc=0x0c099a40u; return 0; }
vf3_matrix_store(s,ram,15,r[12]+r[0]);
goto P_0c099a42;
P_0c099a42: /* original 7004, guest PC 0x0c099a42 */
if(!s->budget--) { s->failed_pc=0x0c099a42u; return 0; }
r[0]+=0x00000004u;
goto P_0c099a44;
P_0c099a44: /* original fcf7, guest PC 0x0c099a44 */
if(!s->budget--) { s->failed_pc=0x0c099a44u; return 0; }
vf3_matrix_store(s,ram,15,r[12]+r[0]);
goto P_0c099a46;
P_0c099a46: /* original 7004, guest PC 0x0c099a46 */
if(!s->budget--) { s->failed_pc=0x0c099a46u; return 0; }
r[0]+=0x00000004u;
goto P_0c099a48;
P_0c099a48: /* original fcf7, guest PC 0x0c099a48 */
if(!s->budget--) { s->failed_pc=0x0c099a48u; return 0; }
vf3_matrix_store(s,ram,15,r[12]+r[0]);
goto P_0c099a4a;
P_0c099a4a: /* original e058, guest PC 0x0c099a4a */
if(!s->budget--) { s->failed_pc=0x0c099a4au; return 0; }
r[0]=0x00000058u;
goto P_0c099a4c;
P_0c099a4c: /* original 63c2, guest PC 0x0c099a4c */
if(!s->budget--) { s->failed_pc=0x0c099a4cu; return 0; }
tmp=read(ram,r[12],4);
r[3]=tmp;
goto P_0c099a4e;
P_0c099a4e: /* original 1f31, guest PC 0x0c099a4e */
if(!s->budget--) { s->failed_pc=0x0c099a4eu; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c099a50;
P_0c099a50: /* original 52f1, guest PC 0x0c099a50 */
if(!s->budget--) { s->failed_pc=0x0c099a50u; return 0; }
r[2]=read(ram,r[15]+4,4);
goto P_0c099a52;
P_0c099a52: /* original d34c, guest PC 0x0c099a52 */
if(!s->budget--) { s->failed_pc=0x0c099a52u; return 0; }
r[3]=read(ram,0x0c099b84u,4);
goto P_0c099a54;
P_0c099a54: /* original 223b, guest PC 0x0c099a54 */
if(!s->budget--) { s->failed_pc=0x0c099a54u; return 0; }
r[2]|=r[3];
goto P_0c099a56;
P_0c099a56: /* original 1f21, guest PC 0x0c099a56 */
if(!s->budget--) { s->failed_pc=0x0c099a56u; return 0; }
write(ram,r[15]+4,r[2],4);
goto P_0c099a58;
P_0c099a58: /* original 6123, guest PC 0x0c099a58 */
if(!s->budget--) { s->failed_pc=0x0c099a58u; return 0; }
r[1]=r[2];
goto P_0c099a5a;
P_0c099a5a: /* original 2c22, guest PC 0x0c099a5a */
if(!s->budget--) { s->failed_pc=0x0c099a5au; return 0; }
write(ram,r[12],r[2],4);
goto P_0c099a5c;
P_0c099a5c: /* original 04ce, guest PC 0x0c099a5c */
if(!s->budget--) { s->failed_pc=0x0c099a5cu; return 0; }
r[4]=read(ram,r[12]+r[0],4);
goto P_0c099a5e;
P_0c099a5e: /* original e048, guest PC 0x0c099a5e */
if(!s->budget--) { s->failed_pc=0x0c099a5eu; return 0; }
r[0]=0x00000048u;
goto P_0c099a60;
P_0c099a60: /* original 01ce, guest PC 0x0c099a60 */
if(!s->budget--) { s->failed_pc=0x0c099a60u; return 0; }
r[1]=read(ram,r[12]+r[0],4);
goto P_0c099a62;
P_0c099a62: /* original d249, guest PC 0x0c099a62 */
if(!s->budget--) { s->failed_pc=0x0c099a62u; return 0; }
r[2]=read(ram,0x0c099b88u,4);
goto P_0c099a64;
P_0c099a64: /* original 7452, guest PC 0x0c099a64 */
if(!s->budget--) { s->failed_pc=0x0c099a64u; return 0; }
r[4]+=0x00000052u;
goto P_0c099a66;
P_0c099a66: /* original 2128, guest PC 0x0c099a66 */
if(!s->budget--) { s->failed_pc=0x0c099a66u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[2])==0)!=0);
goto P_0c099a68;
P_0c099a68: /* original 8d04, guest PC 0x0c099a68 */
if(!s->budget--) { s->failed_pc=0x0c099a68u; return 0; }
cond=r[17]&1u;
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[4],2);
r[4]=tmp;
if(cond) { goto P_0c099a74; }
goto P_0c099a6c;
P_0c099a6a: /* original 6441, guest PC 0x0c099a6a */
if(!s->budget--) { s->failed_pc=0x0c099a6au; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[4],2);
r[4]=tmp;
goto P_0c099a6c;
P_0c099a6c: /* original e058, guest PC 0x0c099a6c */
if(!s->budget--) { s->failed_pc=0x0c099a6cu; return 0; }
r[0]=0x00000058u;
goto P_0c099a6e;
P_0c099a6e: /* original 04ce, guest PC 0x0c099a6e */
if(!s->budget--) { s->failed_pc=0x0c099a6eu; return 0; }
r[4]=read(ram,r[12]+r[0],4);
goto P_0c099a70;
P_0c099a70: /* original 7454, guest PC 0x0c099a70 */
if(!s->budget--) { s->failed_pc=0x0c099a70u; return 0; }
r[4]+=0x00000054u;
goto P_0c099a72;
P_0c099a72: /* original 6441, guest PC 0x0c099a72 */
if(!s->budget--) { s->failed_pc=0x0c099a72u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[4],2);
r[4]=tmp;
goto P_0c099a74;
P_0c099a74: /* original e03c, guest PC 0x0c099a74 */
if(!s->budget--) { s->failed_pc=0x0c099a74u; return 0; }
r[0]=0x0000003cu;
goto P_0c099a76;
P_0c099a76: /* original 0c45, guest PC 0x0c099a76 */
if(!s->budget--) { s->failed_pc=0x0c099a76u; return 0; }
write(ram,r[12]+r[0],r[4],2);
goto P_0c099a78;
P_0c099a78: /* original e301, guest PC 0x0c099a78 */
if(!s->budget--) { s->failed_pc=0x0c099a78u; return 0; }
r[3]=0x00000001u;
goto P_0c099a7a;
P_0c099a7a: /* original e03e, guest PC 0x0c099a7a */
if(!s->budget--) { s->failed_pc=0x0c099a7au; return 0; }
r[0]=0x0000003eu;
goto P_0c099a7c;
P_0c099a7c: /* original 1c4d, guest PC 0x0c099a7c */
if(!s->budget--) { s->failed_pc=0x0c099a7cu; return 0; }
write(ram,r[12]+52,r[4],4);
goto P_0c099a7e;
P_0c099a7e: /* original 0c35, guest PC 0x0c099a7e */
if(!s->budget--) { s->failed_pc=0x0c099a7eu; return 0; }
write(ram,r[12]+r[0],r[3],2);
goto P_0c099a80;
P_0c099a80: /* original 9079, guest PC 0x0c099a80 */
if(!s->budget--) { s->failed_pc=0x0c099a80u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c099b76u,2);
goto P_0c099a82;
P_0c099a82: /* original f4e6, guest PC 0x0c099a82 */
if(!s->budget--) { s->failed_pc=0x0c099a82u; return 0; }
vf3_matrix_load(s,ram,4,r[14]+r[0]);
goto P_0c099a84;
P_0c099a84: /* original 7004, guest PC 0x0c099a84 */
if(!s->budget--) { s->failed_pc=0x0c099a84u; return 0; }
r[0]+=0x00000004u;
goto P_0c099a86;
P_0c099a86: /* original fee6, guest PC 0x0c099a86 */
if(!s->budget--) { s->failed_pc=0x0c099a86u; return 0; }
vf3_matrix_load(s,ram,14,r[14]+r[0]);
goto P_0c099a88;
P_0c099a88: /* original e010, guest PC 0x0c099a88 */
if(!s->budget--) { s->failed_pc=0x0c099a88u; return 0; }
r[0]=0x00000010u;
goto P_0c099a8a;
P_0c099a8a: /* original fc47, guest PC 0x0c099a8a */
if(!s->budget--) { s->failed_pc=0x0c099a8au; return 0; }
vf3_matrix_store(s,ram,4,r[12]+r[0]);
goto P_0c099a8c;
P_0c099a8c: /* original e018, guest PC 0x0c099a8c */
if(!s->budget--) { s->failed_pc=0x0c099a8cu; return 0; }
r[0]=0x00000018u;
goto P_0c099a8e;
P_0c099a8e: /* original fce7, guest PC 0x0c099a8e */
if(!s->budget--) { s->failed_pc=0x0c099a8eu; return 0; }
vf3_matrix_store(s,ram,14,r[12]+r[0]);
goto P_0c099a90;
P_0c099a90: /* original 9072, guest PC 0x0c099a90 */
if(!s->budget--) { s->failed_pc=0x0c099a90u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c099b78u,2);
goto P_0c099a92;
P_0c099a92: /* original fc47, guest PC 0x0c099a92 */
if(!s->budget--) { s->failed_pc=0x0c099a92u; return 0; }
vf3_matrix_store(s,ram,4,r[12]+r[0]);
goto P_0c099a94;
P_0c099a94: /* original 7008, guest PC 0x0c099a94 */
if(!s->budget--) { s->failed_pc=0x0c099a94u; return 0; }
r[0]+=0x00000008u;
goto P_0c099a96;
P_0c099a96: /* original fce7, guest PC 0x0c099a96 */
if(!s->budget--) { s->failed_pc=0x0c099a96u; return 0; }
vf3_matrix_store(s,ram,14,r[12]+r[0]);
goto P_0c099a98;
P_0c099a98: /* original d33c, guest PC 0x0c099a98 */
if(!s->budget--) { s->failed_pc=0x0c099a98u; return 0; }
r[3]=read(ram,0x0c099b8cu,4);
goto P_0c099a9a;
P_0c099a9a: /* original f5ec, guest PC 0x0c099a9a */
if(!s->budget--) { s->failed_pc=0x0c099a9au; return 0; }
vf3_matrix_move(s,5,14);
goto P_0c099a9c;
P_0c099a9c: /* original 430b, guest PC 0x0c099a9c */
if(!s->budget--) { s->failed_pc=0x0c099a9cu; return 0; }
target=r[3];
r[16]=code_base|0x0c099aa0u;
fr[5]^=0x80000000u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c099aa0u) { target=s->pc; goto dispatch; }
goto P_0c099aa0;
P_0c099a9e: /* original f54d, guest PC 0x0c099a9e */
if(!s->budget--) { s->failed_pc=0x0c099a9eu; return 0; }
fr[5]^=0x80000000u;
goto P_0c099aa0;
P_0c099aa0: /* original e014, guest PC 0x0c099aa0 */
if(!s->budget--) { s->failed_pc=0x0c099aa0u; return 0; }
r[0]=0x00000014u;
goto P_0c099aa2;
P_0c099aa2: /* original f40c, guest PC 0x0c099aa2 */
if(!s->budget--) { s->failed_pc=0x0c099aa2u; return 0; }
vf3_matrix_move(s,4,0);
goto P_0c099aa4;
P_0c099aa4: /* original fc47, guest PC 0x0c099aa4 */
if(!s->budget--) { s->failed_pc=0x0c099aa4u; return 0; }
vf3_matrix_store(s,ram,4,r[12]+r[0]);
goto P_0c099aa6;
P_0c099aa6: /* original 9068, guest PC 0x0c099aa6 */
if(!s->budget--) { s->failed_pc=0x0c099aa6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c099b7au,2);
goto P_0c099aa8;
P_0c099aa8: /* original fc47, guest PC 0x0c099aa8 */
if(!s->budget--) { s->failed_pc=0x0c099aa8u; return 0; }
vf3_matrix_store(s,ram,4,r[12]+r[0]);
goto P_0c099aaa;
P_0c099aaa: /* original e01c, guest PC 0x0c099aaa */
if(!s->budget--) { s->failed_pc=0x0c099aaau; return 0; }
r[0]=0x0000001cu;
goto P_0c099aac;
P_0c099aac: /* original 00bc, guest PC 0x0c099aac */
if(!s->budget--) { s->failed_pc=0x0c099aacu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[11]+r[0],1);
goto P_0c099aae;
P_0c099aae: /* original 600c, guest PC 0x0c099aae */
if(!s->budget--) { s->failed_pc=0x0c099aaeu; return 0; }
r[0]=r[0]&255u;
goto P_0c099ab0;
P_0c099ab0: /* original c90f, guest PC 0x0c099ab0 */
if(!s->budget--) { s->failed_pc=0x0c099ab0u; return 0; }
r[0]&=15u;
goto P_0c099ab2;
P_0c099ab2: /* original 8807, guest PC 0x0c099ab2 */
if(!s->budget--) { s->failed_pc=0x0c099ab2u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000007u)!=0);
goto P_0c099ab4;
P_0c099ab4: /* original 8b4f, guest PC 0x0c099ab4 */
if(!s->budget--) { s->failed_pc=0x0c099ab4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c099b56; }
goto P_0c099ab6;
P_0c099ab6: /* original 905c, guest PC 0x0c099ab6 */
if(!s->budget--) { s->failed_pc=0x0c099ab6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c099b72u,2);
goto P_0c099ab8;
P_0c099ab8: /* original d335, guest PC 0x0c099ab8 */
if(!s->budget--) { s->failed_pc=0x0c099ab8u; return 0; }
r[3]=read(ram,0x0c099b90u,4);
goto P_0c099aba;
P_0c099aba: /* original 0cee, guest PC 0x0c099aba */
if(!s->budget--) { s->failed_pc=0x0c099abau; return 0; }
r[12]=read(ram,r[14]+r[0],4);
goto P_0c099abc;
P_0c099abc: /* original 62c2, guest PC 0x0c099abc */
if(!s->budget--) { s->failed_pc=0x0c099abcu; return 0; }
tmp=read(ram,r[12],4);
r[2]=tmp;
goto P_0c099abe;
P_0c099abe: /* original 2238, guest PC 0x0c099abe */
if(!s->budget--) { s->failed_pc=0x0c099abeu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c099ac0;
P_0c099ac0: /* original 8949, guest PC 0x0c099ac0 */
if(!s->budget--) { s->failed_pc=0x0c099ac0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c099b56; }
goto P_0c099ac2;
P_0c099ac2: /* original e048, guest PC 0x0c099ac2 */
if(!s->budget--) { s->failed_pc=0x0c099ac2u; return 0; }
r[0]=0x00000048u;
goto P_0c099ac4;
P_0c099ac4: /* original 61c2, guest PC 0x0c099ac4 */
if(!s->budget--) { s->failed_pc=0x0c099ac4u; return 0; }
tmp=read(ram,r[12],4);
r[1]=tmp;
goto P_0c099ac6;
P_0c099ac6: /* original 65f3, guest PC 0x0c099ac6 */
if(!s->budget--) { s->failed_pc=0x0c099ac6u; return 0; }
r[5]=r[15];
goto P_0c099ac8;
P_0c099ac8: /* original 7504, guest PC 0x0c099ac8 */
if(!s->budget--) { s->failed_pc=0x0c099ac8u; return 0; }
r[5]+=0x00000004u;
goto P_0c099aca;
P_0c099aca: /* original 1f11, guest PC 0x0c099aca */
if(!s->budget--) { s->failed_pc=0x0c099acau; return 0; }
write(ram,r[15]+4,r[1],4);
goto P_0c099acc;
P_0c099acc: /* original 66f3, guest PC 0x0c099acc */
if(!s->budget--) { s->failed_pc=0x0c099accu; return 0; }
r[6]=r[15];
goto P_0c099ace;
P_0c099ace: /* original 03ce, guest PC 0x0c099ace */
if(!s->budget--) { s->failed_pc=0x0c099aceu; return 0; }
r[3]=read(ram,r[12]+r[0],4);
goto P_0c099ad0;
P_0c099ad0: /* original 2f32, guest PC 0x0c099ad0 */
if(!s->budget--) { s->failed_pc=0x0c099ad0u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c099ad2;
P_0c099ad2: /* original d330, guest PC 0x0c099ad2 */
if(!s->budget--) { s->failed_pc=0x0c099ad2u; return 0; }
r[3]=read(ram,0x0c099b94u,4);
goto P_0c099ad4;
P_0c099ad4: /* original 430b, guest PC 0x0c099ad4 */
if(!s->budget--) { s->failed_pc=0x0c099ad4u; return 0; }
target=r[3];
r[16]=code_base|0x0c099ad8u;
r[4]=r[12];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c099ad8u) { target=s->pc; goto dispatch; }
goto P_0c099ad8;
P_0c099ad6: /* original 64c3, guest PC 0x0c099ad6 */
if(!s->budget--) { s->failed_pc=0x0c099ad6u; return 0; }
r[4]=r[12];
goto P_0c099ad8;
P_0c099ad8: /* original e048, guest PC 0x0c099ad8 */
if(!s->budget--) { s->failed_pc=0x0c099ad8u; return 0; }
r[0]=0x00000048u;
goto P_0c099ada;
P_0c099ada: /* original 52f1, guest PC 0x0c099ada */
if(!s->budget--) { s->failed_pc=0x0c099adau; return 0; }
r[2]=read(ram,r[15]+4,4);
goto P_0c099adc;
P_0c099adc: /* original 2c22, guest PC 0x0c099adc */
if(!s->budget--) { s->failed_pc=0x0c099adcu; return 0; }
write(ram,r[12],r[2],4);
goto P_0c099ade;
P_0c099ade: /* original e26d, guest PC 0x0c099ade */
if(!s->budget--) { s->failed_pc=0x0c099adeu; return 0; }
r[2]=0x0000006du;
goto P_0c099ae0;
P_0c099ae0: /* original 63f2, guest PC 0x0c099ae0 */
if(!s->budget--) { s->failed_pc=0x0c099ae0u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c099ae2;
P_0c099ae2: /* original 0c36, guest PC 0x0c099ae2 */
if(!s->budget--) { s->failed_pc=0x0c099ae2u; return 0; }
write(ram,r[12]+r[0],r[3],4);
goto P_0c099ae4;
P_0c099ae4: /* original e061, guest PC 0x0c099ae4 */
if(!s->budget--) { s->failed_pc=0x0c099ae4u; return 0; }
r[0]=0x00000061u;
goto P_0c099ae6;
P_0c099ae6: /* original 2f22, guest PC 0x0c099ae6 */
if(!s->budget--) { s->failed_pc=0x0c099ae6u; return 0; }
write(ram,r[15],r[2],4);
goto P_0c099ae8;
P_0c099ae8: /* original 00cc, guest PC 0x0c099ae8 */
if(!s->budget--) { s->failed_pc=0x0c099ae8u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[12]+r[0],1);
goto P_0c099aea;
P_0c099aea: /* original 600c, guest PC 0x0c099aea */
if(!s->budget--) { s->failed_pc=0x0c099aeau; return 0; }
r[0]=r[0]&255u;
goto P_0c099aec;
P_0c099aec: /* original 880c, guest PC 0x0c099aec */
if(!s->budget--) { s->failed_pc=0x0c099aecu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000cu)!=0);
goto P_0c099aee;
P_0c099aee: /* original 8b01, guest PC 0x0c099aee */
if(!s->budget--) { s->failed_pc=0x0c099aeeu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c099af4; }
goto P_0c099af0;
P_0c099af0: /* original 9344, guest PC 0x0c099af0 */
if(!s->budget--) { s->failed_pc=0x0c099af0u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c099b7cu,2);
goto P_0c099af2;
P_0c099af2: /* original 2f32, guest PC 0x0c099af2 */
if(!s->budget--) { s->failed_pc=0x0c099af2u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c099af4;
P_0c099af4: /* original 62f2, guest PC 0x0c099af4 */
if(!s->budget--) { s->failed_pc=0x0c099af4u; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c099af6;
P_0c099af6: /* original e03c, guest PC 0x0c099af6 */
if(!s->budget--) { s->failed_pc=0x0c099af6u; return 0; }
r[0]=0x0000003cu;
goto P_0c099af8;
P_0c099af8: /* original 0c25, guest PC 0x0c099af8 */
if(!s->budget--) { s->failed_pc=0x0c099af8u; return 0; }
write(ram,r[12]+r[0],r[2],2);
goto P_0c099afa;
P_0c099afa: /* original e201, guest PC 0x0c099afa */
if(!s->budget--) { s->failed_pc=0x0c099afau; return 0; }
r[2]=0x00000001u;
goto P_0c099afc;
P_0c099afc: /* original e03e, guest PC 0x0c099afc */
if(!s->budget--) { s->failed_pc=0x0c099afcu; return 0; }
r[0]=0x0000003eu;
goto P_0c099afe;
P_0c099afe: /* original 63f2, guest PC 0x0c099afe */
if(!s->budget--) { s->failed_pc=0x0c099afeu; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c099b00;
P_0c099b00: /* original 1c3d, guest PC 0x0c099b00 */
if(!s->budget--) { s->failed_pc=0x0c099b00u; return 0; }
write(ram,r[12]+52,r[3],4);
goto P_0c099b02;
P_0c099b02: /* original 0c25, guest PC 0x0c099b02 */
if(!s->budget--) { s->failed_pc=0x0c099b02u; return 0; }
write(ram,r[12]+r[0],r[2],2);
goto P_0c099b04;
P_0c099b04: /* original e010, guest PC 0x0c099b04 */
if(!s->budget--) { s->failed_pc=0x0c099b04u; return 0; }
r[0]=0x00000010u;
goto P_0c099b06;
P_0c099b06: /* original fcf7, guest PC 0x0c099b06 */
if(!s->budget--) { s->failed_pc=0x0c099b06u; return 0; }
vf3_matrix_store(s,ram,15,r[12]+r[0]);
goto P_0c099b08;
P_0c099b08: /* original e018, guest PC 0x0c099b08 */
if(!s->budget--) { s->failed_pc=0x0c099b08u; return 0; }
r[0]=0x00000018u;
goto P_0c099b0a;
P_0c099b0a: /* original fcf7, guest PC 0x0c099b0a */
if(!s->budget--) { s->failed_pc=0x0c099b0au; return 0; }
vf3_matrix_store(s,ram,15,r[12]+r[0]);
goto P_0c099b0c;
P_0c099b0c: /* original e024, guest PC 0x0c099b0c */
if(!s->budget--) { s->failed_pc=0x0c099b0cu; return 0; }
r[0]=0x00000024u;
goto P_0c099b0e;
P_0c099b0e: /* original fcf7, guest PC 0x0c099b0e */
if(!s->budget--) { s->failed_pc=0x0c099b0eu; return 0; }
vf3_matrix_store(s,ram,15,r[12]+r[0]);
goto P_0c099b10;
P_0c099b10: /* original e02c, guest PC 0x0c099b10 */
if(!s->budget--) { s->failed_pc=0x0c099b10u; return 0; }
r[0]=0x0000002cu;
goto P_0c099b12;
P_0c099b12: /* original fcf7, guest PC 0x0c099b12 */
if(!s->budget--) { s->failed_pc=0x0c099b12u; return 0; }
vf3_matrix_store(s,ram,15,r[12]+r[0]);
goto P_0c099b14;
P_0c099b14: /* original 9033, guest PC 0x0c099b14 */
if(!s->budget--) { s->failed_pc=0x0c099b14u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c099b7eu,2);
goto P_0c099b16;
P_0c099b16: /* original fcf7, guest PC 0x0c099b16 */
if(!s->budget--) { s->failed_pc=0x0c099b16u; return 0; }
vf3_matrix_store(s,ram,15,r[12]+r[0]);
goto P_0c099b18;
P_0c099b18: /* original 7004, guest PC 0x0c099b18 */
if(!s->budget--) { s->failed_pc=0x0c099b18u; return 0; }
r[0]+=0x00000004u;
goto P_0c099b1a;
P_0c099b1a: /* original fcf7, guest PC 0x0c099b1a */
if(!s->budget--) { s->failed_pc=0x0c099b1au; return 0; }
vf3_matrix_store(s,ram,15,r[12]+r[0]);
goto P_0c099b1c;
P_0c099b1c: /* original 902a, guest PC 0x0c099b1c */
if(!s->budget--) { s->failed_pc=0x0c099b1cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c099b74u,2);
goto P_0c099b1e;
P_0c099b1e: /* original fcf7, guest PC 0x0c099b1e */
if(!s->budget--) { s->failed_pc=0x0c099b1eu; return 0; }
vf3_matrix_store(s,ram,15,r[12]+r[0]);
goto P_0c099b20;
P_0c099b20: /* original 7004, guest PC 0x0c099b20 */
if(!s->budget--) { s->failed_pc=0x0c099b20u; return 0; }
r[0]+=0x00000004u;
goto P_0c099b22;
P_0c099b22: /* original fcf7, guest PC 0x0c099b22 */
if(!s->budget--) { s->failed_pc=0x0c099b22u; return 0; }
vf3_matrix_store(s,ram,15,r[12]+r[0]);
goto P_0c099b24;
P_0c099b24: /* original 7004, guest PC 0x0c099b24 */
if(!s->budget--) { s->failed_pc=0x0c099b24u; return 0; }
r[0]+=0x00000004u;
goto P_0c099b26;
P_0c099b26: /* original fcf7, guest PC 0x0c099b26 */
if(!s->budget--) { s->failed_pc=0x0c099b26u; return 0; }
vf3_matrix_store(s,ram,15,r[12]+r[0]);
goto P_0c099b28;
P_0c099b28: /* original 9026, guest PC 0x0c099b28 */
if(!s->budget--) { s->failed_pc=0x0c099b28u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c099b78u,2);
goto P_0c099b2a;
P_0c099b2a: /* original fcf7, guest PC 0x0c099b2a */
if(!s->budget--) { s->failed_pc=0x0c099b2au; return 0; }
vf3_matrix_store(s,ram,15,r[12]+r[0]);
goto P_0c099b2c;
P_0c099b2c: /* original 7008, guest PC 0x0c099b2c */
if(!s->budget--) { s->failed_pc=0x0c099b2cu; return 0; }
r[0]+=0x00000008u;
goto P_0c099b2e;
P_0c099b2e: /* original fcf7, guest PC 0x0c099b2e */
if(!s->budget--) { s->failed_pc=0x0c099b2eu; return 0; }
vf3_matrix_store(s,ram,15,r[12]+r[0]);
goto P_0c099b30;
P_0c099b30: /* original 9026, guest PC 0x0c099b30 */
if(!s->budget--) { s->failed_pc=0x0c099b30u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c099b80u,2);
goto P_0c099b32;
P_0c099b32: /* original fcf7, guest PC 0x0c099b32 */
if(!s->budget--) { s->failed_pc=0x0c099b32u; return 0; }
vf3_matrix_store(s,ram,15,r[12]+r[0]);
goto P_0c099b34;
P_0c099b34: /* original 7008, guest PC 0x0c099b34 */
if(!s->budget--) { s->failed_pc=0x0c099b34u; return 0; }
r[0]+=0x00000008u;
goto P_0c099b36;
P_0c099b36: /* original fcf7, guest PC 0x0c099b36 */
if(!s->budget--) { s->failed_pc=0x0c099b36u; return 0; }
vf3_matrix_store(s,ram,15,r[12]+r[0]);
goto P_0c099b38;
P_0c099b38: /* original 901e, guest PC 0x0c099b38 */
if(!s->budget--) { s->failed_pc=0x0c099b38u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c099b78u,2);
goto P_0c099b3a;
P_0c099b3a: /* original fcf7, guest PC 0x0c099b3a */
if(!s->budget--) { s->failed_pc=0x0c099b3au; return 0; }
vf3_matrix_store(s,ram,15,r[12]+r[0]);
goto P_0c099b3c;
P_0c099b3c: /* original 7008, guest PC 0x0c099b3c */
if(!s->budget--) { s->failed_pc=0x0c099b3cu; return 0; }
r[0]+=0x00000008u;
goto P_0c099b3e;
P_0c099b3e: /* original fcf7, guest PC 0x0c099b3e */
if(!s->budget--) { s->failed_pc=0x0c099b3eu; return 0; }
vf3_matrix_store(s,ram,15,r[12]+r[0]);
goto P_0c099b40;
P_0c099b40: /* original e010, guest PC 0x0c099b40 */
if(!s->budget--) { s->failed_pc=0x0c099b40u; return 0; }
r[0]=0x00000010u;
goto P_0c099b42;
P_0c099b42: /* original d312, guest PC 0x0c099b42 */
if(!s->budget--) { s->failed_pc=0x0c099b42u; return 0; }
r[3]=read(ram,0x0c099b8cu,4);
goto P_0c099b44;
P_0c099b44: /* original f4c6, guest PC 0x0c099b44 */
if(!s->budget--) { s->failed_pc=0x0c099b44u; return 0; }
vf3_matrix_load(s,ram,4,r[12]+r[0]);
goto P_0c099b46;
P_0c099b46: /* original e018, guest PC 0x0c099b46 */
if(!s->budget--) { s->failed_pc=0x0c099b46u; return 0; }
r[0]=0x00000018u;
goto P_0c099b48;
P_0c099b48: /* original 430b, guest PC 0x0c099b48 */
if(!s->budget--) { s->failed_pc=0x0c099b48u; return 0; }
target=r[3];
r[16]=code_base|0x0c099b4cu;
vf3_matrix_load(s,ram,5,r[12]+r[0]);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c099b4cu) { target=s->pc; goto dispatch; }
goto P_0c099b4c;
P_0c099b4a: /* original f5c6, guest PC 0x0c099b4a */
if(!s->budget--) { s->failed_pc=0x0c099b4au; return 0; }
vf3_matrix_load(s,ram,5,r[12]+r[0]);
goto P_0c099b4c;
P_0c099b4c: /* original e014, guest PC 0x0c099b4c */
if(!s->budget--) { s->failed_pc=0x0c099b4cu; return 0; }
r[0]=0x00000014u;
goto P_0c099b4e;
P_0c099b4e: /* original f40c, guest PC 0x0c099b4e */
if(!s->budget--) { s->failed_pc=0x0c099b4eu; return 0; }
vf3_matrix_move(s,4,0);
goto P_0c099b50;
P_0c099b50: /* original fc47, guest PC 0x0c099b50 */
if(!s->budget--) { s->failed_pc=0x0c099b50u; return 0; }
vf3_matrix_store(s,ram,4,r[12]+r[0]);
goto P_0c099b52;
P_0c099b52: /* original 9012, guest PC 0x0c099b52 */
if(!s->budget--) { s->failed_pc=0x0c099b52u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c099b7au,2);
goto P_0c099b54;
P_0c099b54: /* original fc47, guest PC 0x0c099b54 */
if(!s->budget--) { s->failed_pc=0x0c099b54u; return 0; }
vf3_matrix_store(s,ram,4,r[12]+r[0]);
goto P_0c099b56;
P_0c099b56: /* original 9014, guest PC 0x0c099b56 */
if(!s->budget--) { s->failed_pc=0x0c099b56u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c099b82u,2);
goto P_0c099b58;
P_0c099b58: /* original 53d4, guest PC 0x0c099b58 */
if(!s->budget--) { s->failed_pc=0x0c099b58u; return 0; }
r[3]=read(ram,r[13]+16,4);
goto P_0c099b5a;
P_0c099b5a: /* original 02ee, guest PC 0x0c099b5a */
if(!s->budget--) { s->failed_pc=0x0c099b5au; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c099b5c;
P_0c099b5c: /* original 3230, guest PC 0x0c099b5c */
if(!s->budget--) { s->failed_pc=0x0c099b5cu; return 0; }
r[17]=(r[17]&~1u)|((r[2]==r[3])!=0);
goto P_0c099b5e;
P_0c099b5e: /* original 891d, guest PC 0x0c099b5e */
if(!s->budget--) { s->failed_pc=0x0c099b5eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c099b9c; }
goto P_0c099b60;
P_0c099b60: /* original d20d, guest PC 0x0c099b60 */
if(!s->budget--) { s->failed_pc=0x0c099b60u; return 0; }
r[2]=read(ram,0x0c099b98u,4);
goto P_0c099b62;
P_0c099b62: /* original 420b, guest PC 0x0c099b62 */
if(!s->budget--) { s->failed_pc=0x0c099b62u; return 0; }
target=r[2];
r[16]=code_base|0x0c099b66u;
r[4]=read(ram,r[13]+20,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c099b66u) { target=s->pc; goto dispatch; }
goto P_0c099b66;
P_0c099b64: /* original 54d5, guest PC 0x0c099b64 */
if(!s->budget--) { s->failed_pc=0x0c099b64u; return 0; }
r[4]=read(ram,r[13]+20,4);
goto P_0c099b66;
P_0c099b66: /* original d30c, guest PC 0x0c099b66 */
if(!s->budget--) { s->failed_pc=0x0c099b66u; return 0; }
r[3]=read(ram,0x0c099b98u,4);
goto P_0c099b68;
P_0c099b68: /* original e05c, guest PC 0x0c099b68 */
if(!s->budget--) { s->failed_pc=0x0c099b68u; return 0; }
r[0]=0x0000005cu;
goto P_0c099b6a;
P_0c099b6a: /* original 430b, guest PC 0x0c099b6a */
if(!s->budget--) { s->failed_pc=0x0c099b6au; return 0; }
target=r[3];
r[16]=code_base|0x0c099b6eu;
r[4]=read(ram,r[13]+r[0],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c099b6eu) { target=s->pc; goto dispatch; }
goto P_0c099b6e;
P_0c099b6c: /* original 04de, guest PC 0x0c099b6c */
if(!s->budget--) { s->failed_pc=0x0c099b6cu; return 0; }
r[4]=read(ram,r[13]+r[0],4);
goto P_0c099b6e;
P_0c099b6e: /* original a01d, guest PC 0x0c099b6e */
if(!s->budget--) { s->failed_pc=0x0c099b6eu; return 0; }
r[0]=0x00000064u;
goto P_0c099bac;
P_0c099b70: /* original e064, guest PC 0x0c099b70 */
if(!s->budget--) { s->failed_pc=0x0c099b70u; return 0; }
r[0]=0x00000064u;
return vf3_matrix_family(0x0c099b72u,s,ram);
P_0c099b9c: /* original d33c, guest PC 0x0c099b9c */
if(!s->budget--) { s->failed_pc=0x0c099b9cu; return 0; }
r[3]=read(ram,0x0c099c90u,4);
goto P_0c099b9e;
P_0c099b9e: /* original 430b, guest PC 0x0c099b9e */
if(!s->budget--) { s->failed_pc=0x0c099b9eu; return 0; }
target=r[3];
r[16]=code_base|0x0c099ba2u;
r[4]=read(ram,r[13]+16,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c099ba2u) { target=s->pc; goto dispatch; }
goto P_0c099ba2;
P_0c099ba0: /* original 54d4, guest PC 0x0c099ba0 */
if(!s->budget--) { s->failed_pc=0x0c099ba0u; return 0; }
r[4]=read(ram,r[13]+16,4);
goto P_0c099ba2;
P_0c099ba2: /* original d33b, guest PC 0x0c099ba2 */
if(!s->budget--) { s->failed_pc=0x0c099ba2u; return 0; }
r[3]=read(ram,0x0c099c90u,4);
goto P_0c099ba4;
P_0c099ba4: /* original e048, guest PC 0x0c099ba4 */
if(!s->budget--) { s->failed_pc=0x0c099ba4u; return 0; }
r[0]=0x00000048u;
goto P_0c099ba6;
P_0c099ba6: /* original 430b, guest PC 0x0c099ba6 */
if(!s->budget--) { s->failed_pc=0x0c099ba6u; return 0; }
target=r[3];
r[16]=code_base|0x0c099baau;
r[4]=read(ram,r[13]+r[0],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c099baau) { target=s->pc; goto dispatch; }
goto P_0c099baa;
P_0c099ba8: /* original 04de, guest PC 0x0c099ba8 */
if(!s->budget--) { s->failed_pc=0x0c099ba8u; return 0; }
r[4]=read(ram,r[13]+r[0],4);
goto P_0c099baa;
P_0c099baa: /* original e060, guest PC 0x0c099baa */
if(!s->budget--) { s->failed_pc=0x0c099baau; return 0; }
r[0]=0x00000060u;
goto P_0c099bac;
P_0c099bac: /* original d338, guest PC 0x0c099bac */
if(!s->budget--) { s->failed_pc=0x0c099bacu; return 0; }
r[3]=read(ram,0x0c099c90u,4);
goto P_0c099bae;
P_0c099bae: /* original 430b, guest PC 0x0c099bae */
if(!s->budget--) { s->failed_pc=0x0c099baeu; return 0; }
target=r[3];
r[16]=code_base|0x0c099bb2u;
r[4]=read(ram,r[13]+r[0],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c099bb2u) { target=s->pc; goto dispatch; }
goto P_0c099bb2;
P_0c099bb0: /* original 04de, guest PC 0x0c099bb0 */
if(!s->budget--) { s->failed_pc=0x0c099bb0u; return 0; }
r[4]=read(ram,r[13]+r[0],4);
goto P_0c099bb2;
P_0c099bb2: /* original 9067, guest PC 0x0c099bb2 */
if(!s->budget--) { s->failed_pc=0x0c099bb2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c099c84u,2);
goto P_0c099bb4;
P_0c099bb4: /* original e30a, guest PC 0x0c099bb4 */
if(!s->budget--) { s->failed_pc=0x0c099bb4u; return 0; }
r[3]=0x0000000au;
goto P_0c099bb6;
P_0c099bb6: /* original 55d8, guest PC 0x0c099bb6 */
if(!s->budget--) { s->failed_pc=0x0c099bb6u; return 0; }
r[5]=read(ram,r[13]+32,4);
goto P_0c099bb8;
P_0c099bb8: /* original 04ee, guest PC 0x0c099bb8 */
if(!s->budget--) { s->failed_pc=0x0c099bb8u; return 0; }
r[4]=read(ram,r[14]+r[0],4);
goto P_0c099bba;
P_0c099bba: /* original e048, guest PC 0x0c099bba */
if(!s->budget--) { s->failed_pc=0x0c099bbau; return 0; }
r[0]=0x00000048u;
goto P_0c099bbc;
P_0c099bbc: /* original 2f32, guest PC 0x0c099bbc */
if(!s->budget--) { s->failed_pc=0x0c099bbcu; return 0; }
write(ram,r[15],r[3],4);
goto P_0c099bbe;
P_0c099bbe: /* original 024e, guest PC 0x0c099bbe */
if(!s->budget--) { s->failed_pc=0x0c099bbeu; return 0; }
r[2]=read(ram,r[4]+r[0],4);
goto P_0c099bc0;
P_0c099bc0: /* original d334, guest PC 0x0c099bc0 */
if(!s->budget--) { s->failed_pc=0x0c099bc0u; return 0; }
r[3]=read(ram,0x0c099c94u,4);
goto P_0c099bc2;
P_0c099bc2: /* original 2238, guest PC 0x0c099bc2 */
if(!s->budget--) { s->failed_pc=0x0c099bc2u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c099bc4;
P_0c099bc4: /* original 8901, guest PC 0x0c099bc4 */
if(!s->budget--) { s->failed_pc=0x0c099bc4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c099bca; }
goto P_0c099bc6;
P_0c099bc6: /* original e10c, guest PC 0x0c099bc6 */
if(!s->budget--) { s->failed_pc=0x0c099bc6u; return 0; }
r[1]=0x0000000cu;
goto P_0c099bc8;
P_0c099bc8: /* original 2f12, guest PC 0x0c099bc8 */
if(!s->budget--) { s->failed_pc=0x0c099bc8u; return 0; }
write(ram,r[15],r[1],4);
goto P_0c099bca;
P_0c099bca: /* original 905c, guest PC 0x0c099bca */
if(!s->budget--) { s->failed_pc=0x0c099bcau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c099c86u,2);
goto P_0c099bcc;
P_0c099bcc: /* original 63f2, guest PC 0x0c099bcc */
if(!s->budget--) { s->failed_pc=0x0c099bccu; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c099bce;
P_0c099bce: /* original a023, guest PC 0x0c099bce */
if(!s->budget--) { s->failed_pc=0x0c099bceu; return 0; }
write(ram,r[5]+r[0],r[3],1);
goto P_0c099c18;
P_0c099bd0: /* original 0534, guest PC 0x0c099bd0 */
if(!s->budget--) { s->failed_pc=0x0c099bd0u; return 0; }
write(ram,r[5]+r[0],r[3],1);
goto P_0c099bd2;
P_0c099bd2: /* original 9057, guest PC 0x0c099bd2 */
if(!s->budget--) { s->failed_pc=0x0c099bd2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c099c84u,2);
goto P_0c099bd4;
P_0c099bd4: /* original 04ee, guest PC 0x0c099bd4 */
if(!s->budget--) { s->failed_pc=0x0c099bd4u; return 0; }
r[4]=read(ram,r[14]+r[0],4);
goto P_0c099bd6;
P_0c099bd6: /* original e048, guest PC 0x0c099bd6 */
if(!s->budget--) { s->failed_pc=0x0c099bd6u; return 0; }
r[0]=0x00000048u;
goto P_0c099bd8;
P_0c099bd8: /* original 034e, guest PC 0x0c099bd8 */
if(!s->budget--) { s->failed_pc=0x0c099bd8u; return 0; }
r[3]=read(ram,r[4]+r[0],4);
goto P_0c099bda;
P_0c099bda: /* original e048, guest PC 0x0c099bda */
if(!s->budget--) { s->failed_pc=0x0c099bdau; return 0; }
r[0]=0x00000048u;
goto P_0c099bdc;
P_0c099bdc: /* original 2f32, guest PC 0x0c099bdc */
if(!s->budget--) { s->failed_pc=0x0c099bdcu; return 0; }
write(ram,r[15],r[3],4);
goto P_0c099bde;
P_0c099bde: /* original 024e, guest PC 0x0c099bde */
if(!s->budget--) { s->failed_pc=0x0c099bdeu; return 0; }
r[2]=read(ram,r[4]+r[0],4);
goto P_0c099be0;
P_0c099be0: /* original d32d, guest PC 0x0c099be0 */
if(!s->budget--) { s->failed_pc=0x0c099be0u; return 0; }
r[3]=read(ram,0x0c099c98u,4);
goto P_0c099be2;
P_0c099be2: /* original 2239, guest PC 0x0c099be2 */
if(!s->budget--) { s->failed_pc=0x0c099be2u; return 0; }
r[2]&=r[3];
goto P_0c099be4;
P_0c099be4: /* original 0426, guest PC 0x0c099be4 */
if(!s->budget--) { s->failed_pc=0x0c099be4u; return 0; }
write(ram,r[4]+r[0],r[2],4);
goto P_0c099be6;
P_0c099be6: /* original 904d, guest PC 0x0c099be6 */
if(!s->budget--) { s->failed_pc=0x0c099be6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c099c84u,2);
goto P_0c099be8;
P_0c099be8: /* original 51d4, guest PC 0x0c099be8 */
if(!s->budget--) { s->failed_pc=0x0c099be8u; return 0; }
r[1]=read(ram,r[13]+16,4);
goto P_0c099bea;
P_0c099bea: /* original 00ee, guest PC 0x0c099bea */
if(!s->budget--) { s->failed_pc=0x0c099beau; return 0; }
r[0]=read(ram,r[14]+r[0],4);
goto P_0c099bec;
P_0c099bec: /* original 3010, guest PC 0x0c099bec */
if(!s->budget--) { s->failed_pc=0x0c099becu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==r[1])!=0);
goto P_0c099bee;
P_0c099bee: /* original 8908, guest PC 0x0c099bee */
if(!s->budget--) { s->failed_pc=0x0c099beeu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c099c02; }
goto P_0c099bf0;
P_0c099bf0: /* original d327, guest PC 0x0c099bf0 */
if(!s->budget--) { s->failed_pc=0x0c099bf0u; return 0; }
r[3]=read(ram,0x0c099c90u,4);
goto P_0c099bf2;
P_0c099bf2: /* original 430b, guest PC 0x0c099bf2 */
if(!s->budget--) { s->failed_pc=0x0c099bf2u; return 0; }
target=r[3];
r[16]=code_base|0x0c099bf6u;
r[4]=read(ram,r[13]+20,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c099bf6u) { target=s->pc; goto dispatch; }
goto P_0c099bf6;
P_0c099bf4: /* original 54d5, guest PC 0x0c099bf4 */
if(!s->budget--) { s->failed_pc=0x0c099bf4u; return 0; }
r[4]=read(ram,r[13]+20,4);
goto P_0c099bf6;
P_0c099bf6: /* original d326, guest PC 0x0c099bf6 */
if(!s->budget--) { s->failed_pc=0x0c099bf6u; return 0; }
r[3]=read(ram,0x0c099c90u,4);
goto P_0c099bf8;
P_0c099bf8: /* original e05c, guest PC 0x0c099bf8 */
if(!s->budget--) { s->failed_pc=0x0c099bf8u; return 0; }
r[0]=0x0000005cu;
goto P_0c099bfa;
P_0c099bfa: /* original 430b, guest PC 0x0c099bfa */
if(!s->budget--) { s->failed_pc=0x0c099bfau; return 0; }
target=r[3];
r[16]=code_base|0x0c099bfeu;
r[4]=read(ram,r[13]+r[0],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c099bfeu) { target=s->pc; goto dispatch; }
goto P_0c099bfe;
P_0c099bfc: /* original 04de, guest PC 0x0c099bfc */
if(!s->budget--) { s->failed_pc=0x0c099bfcu; return 0; }
r[4]=read(ram,r[13]+r[0],4);
goto P_0c099bfe;
P_0c099bfe: /* original a008, guest PC 0x0c099bfe */
if(!s->budget--) { s->failed_pc=0x0c099bfeu; return 0; }
r[0]=0x00000064u;
goto P_0c099c12;
P_0c099c00: /* original e064, guest PC 0x0c099c00 */
if(!s->budget--) { s->failed_pc=0x0c099c00u; return 0; }
r[0]=0x00000064u;
goto P_0c099c02;
P_0c099c02: /* original d323, guest PC 0x0c099c02 */
if(!s->budget--) { s->failed_pc=0x0c099c02u; return 0; }
r[3]=read(ram,0x0c099c90u,4);
goto P_0c099c04;
P_0c099c04: /* original 430b, guest PC 0x0c099c04 */
if(!s->budget--) { s->failed_pc=0x0c099c04u; return 0; }
target=r[3];
r[16]=code_base|0x0c099c08u;
r[4]=read(ram,r[13]+16,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c099c08u) { target=s->pc; goto dispatch; }
goto P_0c099c08;
P_0c099c06: /* original 54d4, guest PC 0x0c099c06 */
if(!s->budget--) { s->failed_pc=0x0c099c06u; return 0; }
r[4]=read(ram,r[13]+16,4);
goto P_0c099c08;
P_0c099c08: /* original d321, guest PC 0x0c099c08 */
if(!s->budget--) { s->failed_pc=0x0c099c08u; return 0; }
r[3]=read(ram,0x0c099c90u,4);
goto P_0c099c0a;
P_0c099c0a: /* original e048, guest PC 0x0c099c0a */
if(!s->budget--) { s->failed_pc=0x0c099c0au; return 0; }
r[0]=0x00000048u;
goto P_0c099c0c;
P_0c099c0c: /* original 430b, guest PC 0x0c099c0c */
if(!s->budget--) { s->failed_pc=0x0c099c0cu; return 0; }
target=r[3];
r[16]=code_base|0x0c099c10u;
r[4]=read(ram,r[13]+r[0],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c099c10u) { target=s->pc; goto dispatch; }
goto P_0c099c10;
P_0c099c0e: /* original 04de, guest PC 0x0c099c0e */
if(!s->budget--) { s->failed_pc=0x0c099c0eu; return 0; }
r[4]=read(ram,r[13]+r[0],4);
goto P_0c099c10;
P_0c099c10: /* original e060, guest PC 0x0c099c10 */
if(!s->budget--) { s->failed_pc=0x0c099c10u; return 0; }
r[0]=0x00000060u;
goto P_0c099c12;
P_0c099c12: /* original d31f, guest PC 0x0c099c12 */
if(!s->budget--) { s->failed_pc=0x0c099c12u; return 0; }
r[3]=read(ram,0x0c099c90u,4);
goto P_0c099c14;
P_0c099c14: /* original 430b, guest PC 0x0c099c14 */
if(!s->budget--) { s->failed_pc=0x0c099c14u; return 0; }
target=r[3];
r[16]=code_base|0x0c099c18u;
r[4]=read(ram,r[13]+r[0],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c099c18u) { target=s->pc; goto dispatch; }
goto P_0c099c18;
P_0c099c16: /* original 04de, guest PC 0x0c099c16 */
if(!s->budget--) { s->failed_pc=0x0c099c16u; return 0; }
r[4]=read(ram,r[13]+r[0],4);
goto P_0c099c18;
P_0c099c18: /* original 9036, guest PC 0x0c099c18 */
if(!s->budget--) { s->failed_pc=0x0c099c18u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c099c88u,2);
goto P_0c099c1a;
P_0c099c1a: /* original 54d4, guest PC 0x0c099c1a */
if(!s->budget--) { s->failed_pc=0x0c099c1au; return 0; }
r[4]=read(ram,r[13]+16,4);
goto P_0c099c1c;
P_0c099c1c: /* original 04a4, guest PC 0x0c099c1c */
if(!s->budget--) { s->failed_pc=0x0c099c1cu; return 0; }
write(ram,r[4]+r[0],r[10],1);
goto P_0c099c1e;
P_0c099c1e: /* original 54d5, guest PC 0x0c099c1e */
if(!s->budget--) { s->failed_pc=0x0c099c1eu; return 0; }
r[4]=read(ram,r[13]+20,4);
goto P_0c099c20;
P_0c099c20: /* original 04a4, guest PC 0x0c099c20 */
if(!s->budget--) { s->failed_pc=0x0c099c20u; return 0; }
write(ram,r[4]+r[0],r[10],1);
goto P_0c099c22;
P_0c099c22: /* original 84bb, guest PC 0x0c099c22 */
if(!s->budget--) { s->failed_pc=0x0c099c22u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[11]+11,1);
goto P_0c099c24;
P_0c099c24: /* original 7001, guest PC 0x0c099c24 */
if(!s->budget--) { s->failed_pc=0x0c099c24u; return 0; }
r[0]+=0x00000001u;
goto P_0c099c26;
P_0c099c26: /* original b00c, guest PC 0x0c099c26 */
if(!s->budget--) { s->failed_pc=0x0c099c26u; return 0; }
target=0x0c099c42u; r[16]=code_base|0x0c099c2au;
write(ram,r[11]+11,r[0],1);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c099c2au) { target=s->pc; goto dispatch; }
goto P_0c099c2a;
P_0c099c28: /* original 80bb, guest PC 0x0c099c28 */
if(!s->budget--) { s->failed_pc=0x0c099c28u; return 0; }
write(ram,r[11]+11,r[0],1);
goto P_0c099c2a;
P_0c099c2a: /* original 7f14, guest PC 0x0c099c2a */
if(!s->budget--) { s->failed_pc=0x0c099c2au; return 0; }
r[15]+=0x00000014u;
goto P_0c099c2c;
P_0c099c2c: /* original 4f26, guest PC 0x0c099c2c */
if(!s->budget--) { s->failed_pc=0x0c099c2cu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c099c2e;
P_0c099c2e: /* original fef9, guest PC 0x0c099c2e */
if(!s->budget--) { s->failed_pc=0x0c099c2eu; return 0; }
vf3_matrix_load(s,ram,14,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c099c30;
P_0c099c30: /* original fff9, guest PC 0x0c099c30 */
if(!s->budget--) { s->failed_pc=0x0c099c30u; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c099c32;
P_0c099c32: /* original 68f6, guest PC 0x0c099c32 */
if(!s->budget--) { s->failed_pc=0x0c099c32u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c099c34;
P_0c099c34: /* original 69f6, guest PC 0x0c099c34 */
if(!s->budget--) { s->failed_pc=0x0c099c34u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c099c36;
P_0c099c36: /* original 6af6, guest PC 0x0c099c36 */
if(!s->budget--) { s->failed_pc=0x0c099c36u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c099c38;
P_0c099c38: /* original 6bf6, guest PC 0x0c099c38 */
if(!s->budget--) { s->failed_pc=0x0c099c38u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c099c3a;
P_0c099c3a: /* original 6cf6, guest PC 0x0c099c3a */
if(!s->budget--) { s->failed_pc=0x0c099c3au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c099c3c;
P_0c099c3c: /* original 6df6, guest PC 0x0c099c3c */
if(!s->budget--) { s->failed_pc=0x0c099c3cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c099c3e;
P_0c099c3e: /* original 000b, guest PC 0x0c099c3e */
if(!s->budget--) { s->failed_pc=0x0c099c3eu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c099c40: /* original 6ef6, guest PC 0x0c099c40 */
if(!s->budget--) { s->failed_pc=0x0c099c40u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c099c42;
P_0c099c42: /* original 2fe6, guest PC 0x0c099c42 */
if(!s->budget--) { s->failed_pc=0x0c099c42u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c099c44;
P_0c099c44: /* original 2fd6, guest PC 0x0c099c44 */
if(!s->budget--) { s->failed_pc=0x0c099c44u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c099c46;
P_0c099c46: /* original 2fc6, guest PC 0x0c099c46 */
if(!s->budget--) { s->failed_pc=0x0c099c46u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c099c48;
P_0c099c48: /* original 2fb6, guest PC 0x0c099c48 */
if(!s->budget--) { s->failed_pc=0x0c099c48u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c099c4a;
P_0c099c4a: /* original dd14, guest PC 0x0c099c4a */
if(!s->budget--) { s->failed_pc=0x0c099c4au; return 0; }
r[13]=read(ram,0x0c099c9cu,4);
goto P_0c099c4c;
P_0c099c4c: /* original 4f22, guest PC 0x0c099c4c */
if(!s->budget--) { s->failed_pc=0x0c099c4cu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c099c4e;
P_0c099c4e: /* original d315, guest PC 0x0c099c4e */
if(!s->budget--) { s->failed_pc=0x0c099c4eu; return 0; }
r[3]=read(ram,0x0c099ca4u,4);
goto P_0c099c50;
P_0c099c50: /* original de13, guest PC 0x0c099c50 */
if(!s->budget--) { s->failed_pc=0x0c099c50u; return 0; }
r[14]=read(ram,0x0c099ca0u,4);
goto P_0c099c52;
P_0c099c52: /* original 7ffc, guest PC 0x0c099c52 */
if(!s->budget--) { s->failed_pc=0x0c099c52u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c099c54;
P_0c099c54: /* original 2f32, guest PC 0x0c099c54 */
if(!s->budget--) { s->failed_pc=0x0c099c54u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c099c56;
P_0c099c56: /* original 9018, guest PC 0x0c099c56 */
if(!s->budget--) { s->failed_pc=0x0c099c56u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c099c8au,2);
goto P_0c099c58;
P_0c099c58: /* original 0cde, guest PC 0x0c099c58 */
if(!s->budget--) { s->failed_pc=0x0c099c58u; return 0; }
r[12]=read(ram,r[13]+r[0],4);
goto P_0c099c5a;
P_0c099c5a: /* original 9017, guest PC 0x0c099c5a */
if(!s->budget--) { s->failed_pc=0x0c099c5au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c099c8cu,2);
goto P_0c099c5c;
P_0c099c5c: /* original 00ce, guest PC 0x0c099c5c */
if(!s->budget--) { s->failed_pc=0x0c099c5cu; return 0; }
r[0]=read(ram,r[12]+r[0],4);
goto P_0c099c5e;
P_0c099c5e: /* original c808, guest PC 0x0c099c5e */
if(!s->budget--) { s->failed_pc=0x0c099c5eu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&8u)==0)!=0);
goto P_0c099c60;
P_0c099c60: /* original 8926, guest PC 0x0c099c60 */
if(!s->budget--) { s->failed_pc=0x0c099c60u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c099cb0; }
goto P_0c099c62;
P_0c099c62: /* original 53e3, guest PC 0x0c099c62 */
if(!s->budget--) { s->failed_pc=0x0c099c62u; return 0; }
r[3]=read(ram,r[14]+12,4);
goto P_0c099c64;
P_0c099c64: /* original 9413, guest PC 0x0c099c64 */
if(!s->budget--) { s->failed_pc=0x0c099c64u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c099c8eu,2);
goto P_0c099c66;
P_0c099c66: /* original 3347, guest PC 0x0c099c66 */
if(!s->budget--) { s->failed_pc=0x0c099c66u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>(int32_t)r[4])!=0);
goto P_0c099c68;
P_0c099c68: /* original 893e, guest PC 0x0c099c68 */
if(!s->budget--) { s->failed_pc=0x0c099c68u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c099ce8; }
goto P_0c099c6a;
P_0c099c6a: /* original 52e3, guest PC 0x0c099c6a */
if(!s->budget--) { s->failed_pc=0x0c099c6au; return 0; }
r[2]=read(ram,r[14]+12,4);
goto P_0c099c6c;
P_0c099c6c: /* original 3243, guest PC 0x0c099c6c */
if(!s->budget--) { s->failed_pc=0x0c099c6cu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[2]>=(int32_t)r[4])!=0);
goto P_0c099c6e;
P_0c099c6e: /* original 8b04, guest PC 0x0c099c6e */
if(!s->budget--) { s->failed_pc=0x0c099c6eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c099c7a; }
goto P_0c099c70;
P_0c099c70: /* original d30d, guest PC 0x0c099c70 */
if(!s->budget--) { s->failed_pc=0x0c099c70u; return 0; }
r[3]=read(ram,0x0c099ca8u,4);
goto P_0c099c72;
P_0c099c72: /* original 430b, guest PC 0x0c099c72 */
if(!s->budget--) { s->failed_pc=0x0c099c72u; return 0; }
target=r[3];
r[16]=code_base|0x0c099c76u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c099c76u) { target=s->pc; goto dispatch; }
goto P_0c099c76;
P_0c099c74: /* original 0009, guest PC 0x0c099c74 */
if(!s->budget--) { s->failed_pc=0x0c099c74u; return 0; }
goto P_0c099c76;
P_0c099c76: /* original a037, guest PC 0x0c099c76 */
if(!s->budget--) { s->failed_pc=0x0c099c76u; return 0; }
goto P_0c099ce8;
P_0c099c78: /* original 0009, guest PC 0x0c099c78 */
if(!s->budget--) { s->failed_pc=0x0c099c78u; return 0; }
goto P_0c099c7a;
P_0c099c7a: /* original d30c, guest PC 0x0c099c7a */
if(!s->budget--) { s->failed_pc=0x0c099c7au; return 0; }
r[3]=read(ram,0x0c099cacu,4);
goto P_0c099c7c;
P_0c099c7c: /* original 430b, guest PC 0x0c099c7c */
if(!s->budget--) { s->failed_pc=0x0c099c7cu; return 0; }
target=r[3];
r[16]=code_base|0x0c099c80u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c099c80u) { target=s->pc; goto dispatch; }
goto P_0c099c80;
P_0c099c7e: /* original 0009, guest PC 0x0c099c7e */
if(!s->budget--) { s->failed_pc=0x0c099c7eu; return 0; }
goto P_0c099c80;
P_0c099c80: /* original a032, guest PC 0x0c099c80 */
if(!s->budget--) { s->failed_pc=0x0c099c80u; return 0; }
goto P_0c099ce8;
P_0c099c82: /* original 0009, guest PC 0x0c099c82 */
if(!s->budget--) { s->failed_pc=0x0c099c82u; return 0; }
return vf3_matrix_family(0x0c099c84u,s,ram);
P_0c099cb0: /* original d03e, guest PC 0x0c099cb0 */
if(!s->budget--) { s->failed_pc=0x0c099cb0u; return 0; }
r[0]=read(ram,0x0c099dacu,4);
goto P_0c099cb2;
P_0c099cb2: /* original d33d, guest PC 0x0c099cb2 */
if(!s->budget--) { s->failed_pc=0x0c099cb2u; return 0; }
r[3]=read(ram,0x0c099da8u,4);
goto P_0c099cb4;
P_0c099cb4: /* original 6102, guest PC 0x0c099cb4 */
if(!s->budget--) { s->failed_pc=0x0c099cb4u; return 0; }
tmp=read(ram,r[0],4);
r[1]=tmp;
goto P_0c099cb6;
P_0c099cb6: /* original 2138, guest PC 0x0c099cb6 */
if(!s->budget--) { s->failed_pc=0x0c099cb6u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[3])==0)!=0);
goto P_0c099cb8;
P_0c099cb8: /* original 8b19, guest PC 0x0c099cb8 */
if(!s->budget--) { s->failed_pc=0x0c099cb8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c099cee; }
goto P_0c099cba;
P_0c099cba: /* original d33d, guest PC 0x0c099cba */
if(!s->budget--) { s->failed_pc=0x0c099cbau; return 0; }
r[3]=read(ram,0x0c099db0u,4);
goto P_0c099cbc;
P_0c099cbc: /* original 64f2, guest PC 0x0c099cbc */
if(!s->budget--) { s->failed_pc=0x0c099cbcu; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c099cbe;
P_0c099cbe: /* original 5bd2, guest PC 0x0c099cbe */
if(!s->budget--) { s->failed_pc=0x0c099cbeu; return 0; }
r[11]=read(ram,r[13]+8,4);
goto P_0c099cc0;
P_0c099cc0: /* original 430b, guest PC 0x0c099cc0 */
if(!s->budget--) { s->failed_pc=0x0c099cc0u; return 0; }
target=r[3];
r[16]=code_base|0x0c099cc4u;
r[4]+=0x00000013u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c099cc4u) { target=s->pc; goto dispatch; }
goto P_0c099cc4;
P_0c099cc2: /* original 7413, guest PC 0x0c099cc2 */
if(!s->budget--) { s->failed_pc=0x0c099cc2u; return 0; }
r[4]+=0x00000013u;
goto P_0c099cc4;
P_0c099cc4: /* original 640c, guest PC 0x0c099cc4 */
if(!s->budget--) { s->failed_pc=0x0c099cc4u; return 0; }
r[4]=r[0]&255u;
goto P_0c099cc6;
P_0c099cc6: /* original e029, guest PC 0x0c099cc6 */
if(!s->budget--) { s->failed_pc=0x0c099cc6u; return 0; }
r[0]=0x00000029u;
goto P_0c099cc8;
P_0c099cc8: /* original 00dc, guest PC 0x0c099cc8 */
if(!s->budget--) { s->failed_pc=0x0c099cc8u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+r[0],1);
goto P_0c099cca;
P_0c099cca: /* original 600c, guest PC 0x0c099cca */
if(!s->budget--) { s->failed_pc=0x0c099ccau; return 0; }
r[0]=r[0]&255u;
goto P_0c099ccc;
P_0c099ccc: /* original 8803, guest PC 0x0c099ccc */
if(!s->budget--) { s->failed_pc=0x0c099cccu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000003u)!=0);
goto P_0c099cce;
P_0c099cce: /* original 8b07, guest PC 0x0c099cce */
if(!s->budget--) { s->failed_pc=0x0c099cceu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c099ce0; }
goto P_0c099cd0;
P_0c099cd0: /* original 2448, guest PC 0x0c099cd0 */
if(!s->budget--) { s->failed_pc=0x0c099cd0u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c099cd2;
P_0c099cd2: /* original 8905, guest PC 0x0c099cd2 */
if(!s->budget--) { s->failed_pc=0x0c099cd2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c099ce0; }
goto P_0c099cd4;
P_0c099cd4: /* original d337, guest PC 0x0c099cd4 */
if(!s->budget--) { s->failed_pc=0x0c099cd4u; return 0; }
r[3]=read(ram,0x0c099db4u,4);
goto P_0c099cd6;
P_0c099cd6: /* original 23b8, guest PC 0x0c099cd6 */
if(!s->budget--) { s->failed_pc=0x0c099cd6u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[11])==0)!=0);
goto P_0c099cd8;
P_0c099cd8: /* original 8b02, guest PC 0x0c099cd8 */
if(!s->budget--) { s->failed_pc=0x0c099cd8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c099ce0; }
goto P_0c099cda;
P_0c099cda: /* original e204, guest PC 0x0c099cda */
if(!s->budget--) { s->failed_pc=0x0c099cdau; return 0; }
r[2]=0x00000004u;
goto P_0c099cdc;
P_0c099cdc: /* original 2b28, guest PC 0x0c099cdc */
if(!s->budget--) { s->failed_pc=0x0c099cdcu; return 0; }
r[17]=(r[17]&~1u)|(((r[11]&r[2])==0)!=0);
goto P_0c099cde;
P_0c099cde: /* original 8b03, guest PC 0x0c099cde */
if(!s->budget--) { s->failed_pc=0x0c099cdeu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c099ce8; }
goto P_0c099ce0;
P_0c099ce0: /* original 905e, guest PC 0x0c099ce0 */
if(!s->budget--) { s->failed_pc=0x0c099ce0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c099da0u,2);
goto P_0c099ce2;
P_0c099ce2: /* original 00ee, guest PC 0x0c099ce2 */
if(!s->budget--) { s->failed_pc=0x0c099ce2u; return 0; }
r[0]=read(ram,r[14]+r[0],4);
goto P_0c099ce4;
P_0c099ce4: /* original c830, guest PC 0x0c099ce4 */
if(!s->budget--) { s->failed_pc=0x0c099ce4u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&48u)==0)!=0);
goto P_0c099ce6;
P_0c099ce6: /* original 8b0a, guest PC 0x0c099ce6 */
if(!s->budget--) { s->failed_pc=0x0c099ce6u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c099cfe; }
goto P_0c099ce8;
P_0c099ce8: /* original 53e3, guest PC 0x0c099ce8 */
if(!s->budget--) { s->failed_pc=0x0c099ce8u; return 0; }
r[3]=read(ram,r[14]+12,4);
goto P_0c099cea;
P_0c099cea: /* original 4315, guest PC 0x0c099cea */
if(!s->budget--) { s->failed_pc=0x0c099ceau; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>0)!=0);
goto P_0c099cec;
P_0c099cec: /* original 8b07, guest PC 0x0c099cec */
if(!s->budget--) { s->failed_pc=0x0c099cecu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c099cfe; }
goto P_0c099cee;
P_0c099cee: /* original 7f04, guest PC 0x0c099cee */
if(!s->budget--) { s->failed_pc=0x0c099ceeu; return 0; }
r[15]+=0x00000004u;
goto P_0c099cf0;
P_0c099cf0: /* original d131, guest PC 0x0c099cf0 */
if(!s->budget--) { s->failed_pc=0x0c099cf0u; return 0; }
r[1]=read(ram,0x0c099db8u,4);
goto P_0c099cf2;
P_0c099cf2: /* original 4f26, guest PC 0x0c099cf2 */
if(!s->budget--) { s->failed_pc=0x0c099cf2u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c099cf4;
P_0c099cf4: /* original 6bf6, guest PC 0x0c099cf4 */
if(!s->budget--) { s->failed_pc=0x0c099cf4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c099cf6;
P_0c099cf6: /* original 6cf6, guest PC 0x0c099cf6 */
if(!s->budget--) { s->failed_pc=0x0c099cf6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c099cf8;
P_0c099cf8: /* original 6df6, guest PC 0x0c099cf8 */
if(!s->budget--) { s->failed_pc=0x0c099cf8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c099cfa;
P_0c099cfa: /* original 412b, guest PC 0x0c099cfa */
if(!s->budget--) { s->failed_pc=0x0c099cfau; return 0; }
target=r[1];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
switch(target&0x1fffffffu) {
case 0x0c03b450u: return vf3_matrix_family(target,s,ram);
case 0x0c03b4b0u: return vf3_matrix_family(target,s,ram);
case 0x0c03b530u: return vf3_matrix_family(target,s,ram);
case 0x0c03b620u: return vf3_matrix_family(target,s,ram);
case 0x0c03b820u: return vf3_matrix_family(target,s,ram);
case 0x0c03bd80u: return vf3_matrix_family(target,s,ram);
case 0x0c03c0e0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c4a0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c4f0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c610u: return vf3_matrix_family(target,s,ram);
case 0x0c03c6c0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c880u: return vf3_matrix_family(target,s,ram);
case 0x0c03c940u: return vf3_matrix_family(target,s,ram);
case 0x0c03c970u: return vf3_matrix_family(target,s,ram);
case 0x0c03cbd0u: return vf3_matrix_family(target,s,ram);
case 0x0c03cc60u: return vf3_matrix_family(target,s,ram);
case 0x0c03cc90u: return vf3_matrix_family(target,s,ram);
case 0x0c03ccb0u: return vf3_matrix_family(target,s,ram);
default: goto dispatch; }
P_0c099cfc: /* original 6ef6, guest PC 0x0c099cfc */
if(!s->budget--) { s->failed_pc=0x0c099cfcu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c099cfe;
P_0c099cfe: /* original 7f04, guest PC 0x0c099cfe */
if(!s->budget--) { s->failed_pc=0x0c099cfeu; return 0; }
r[15]+=0x00000004u;
goto P_0c099d00;
P_0c099d00: /* original 64c3, guest PC 0x0c099d00 */
if(!s->budget--) { s->failed_pc=0x0c099d00u; return 0; }
r[4]=r[12];
goto P_0c099d02;
P_0c099d02: /* original 4f26, guest PC 0x0c099d02 */
if(!s->budget--) { s->failed_pc=0x0c099d02u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c099d04;
P_0c099d04: /* original 6bf6, guest PC 0x0c099d04 */
if(!s->budget--) { s->failed_pc=0x0c099d04u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c099d06;
P_0c099d06: /* original 6cf6, guest PC 0x0c099d06 */
if(!s->budget--) { s->failed_pc=0x0c099d06u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c099d08;
P_0c099d08: /* original 6df6, guest PC 0x0c099d08 */
if(!s->budget--) { s->failed_pc=0x0c099d08u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c099d0a;
P_0c099d0a: /* original a000, guest PC 0x0c099d0a */
if(!s->budget--) { s->failed_pc=0x0c099d0au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c099d0e;
P_0c099d0c: /* original 6ef6, guest PC 0x0c099d0c */
if(!s->budget--) { s->failed_pc=0x0c099d0cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c099d0e;
P_0c099d0e: /* original 2fe6, guest PC 0x0c099d0e */
if(!s->budget--) { s->failed_pc=0x0c099d0eu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c099d10;
P_0c099d10: /* original 2fd6, guest PC 0x0c099d10 */
if(!s->budget--) { s->failed_pc=0x0c099d10u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c099d12;
P_0c099d12: /* original 4f22, guest PC 0x0c099d12 */
if(!s->budget--) { s->failed_pc=0x0c099d12u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c099d14;
P_0c099d14: /* original d32a, guest PC 0x0c099d14 */
if(!s->budget--) { s->failed_pc=0x0c099d14u; return 0; }
r[3]=read(ram,0x0c099dc0u,4);
goto P_0c099d16;
P_0c099d16: /* original dd29, guest PC 0x0c099d16 */
if(!s->budget--) { s->failed_pc=0x0c099d16u; return 0; }
r[13]=read(ram,0x0c099dbcu,4);
goto P_0c099d18;
P_0c099d18: /* original 7ffc, guest PC 0x0c099d18 */
if(!s->budget--) { s->failed_pc=0x0c099d18u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c099d1a;
P_0c099d1a: /* original 2f32, guest PC 0x0c099d1a */
if(!s->budget--) { s->failed_pc=0x0c099d1au; return 0; }
write(ram,r[15],r[3],4);
goto P_0c099d1c;
P_0c099d1c: /* original e3f7, guest PC 0x0c099d1c */
if(!s->budget--) { s->failed_pc=0x0c099d1cu; return 0; }
r[3]=0xfffffff7u;
goto P_0c099d1e;
P_0c099d1e: /* original 9040, guest PC 0x0c099d1e */
if(!s->budget--) { s->failed_pc=0x0c099d1eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c099da2u,2);
goto P_0c099d20;
P_0c099d20: /* original 024e, guest PC 0x0c099d20 */
if(!s->budget--) { s->failed_pc=0x0c099d20u; return 0; }
r[2]=read(ram,r[4]+r[0],4);
goto P_0c099d22;
P_0c099d22: /* original 2239, guest PC 0x0c099d22 */
if(!s->budget--) { s->failed_pc=0x0c099d22u; return 0; }
r[2]&=r[3];
goto P_0c099d24;
P_0c099d24: /* original 0426, guest PC 0x0c099d24 */
if(!s->budget--) { s->failed_pc=0x0c099d24u; return 0; }
write(ram,r[4]+r[0],r[2],4);
goto P_0c099d26;
P_0c099d26: /* original d128, guest PC 0x0c099d26 */
if(!s->budget--) { s->failed_pc=0x0c099d26u; return 0; }
r[1]=read(ram,0x0c099dc8u,4);
goto P_0c099d28;
P_0c099d28: /* original d426, guest PC 0x0c099d28 */
if(!s->budget--) { s->failed_pc=0x0c099d28u; return 0; }
r[4]=read(ram,0x0c099dc4u,4);
goto P_0c099d2a;
P_0c099d2a: /* original 410b, guest PC 0x0c099d2a */
if(!s->budget--) { s->failed_pc=0x0c099d2au; return 0; }
target=r[1];
r[16]=code_base|0x0c099d2eu;
r[5]=0x00000000u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c099d2eu) { target=s->pc; goto dispatch; }
goto P_0c099d2e;
P_0c099d2c: /* original e500, guest PC 0x0c099d2c */
if(!s->budget--) { s->failed_pc=0x0c099d2cu; return 0; }
r[5]=0x00000000u;
goto P_0c099d2e;
P_0c099d2e: /* original d328, guest PC 0x0c099d2e */
if(!s->budget--) { s->failed_pc=0x0c099d2eu; return 0; }
r[3]=read(ram,0x0c099dd0u,4);
goto P_0c099d30;
P_0c099d30: /* original de26, guest PC 0x0c099d30 */
if(!s->budget--) { s->failed_pc=0x0c099d30u; return 0; }
r[14]=read(ram,0x0c099dccu,4);
goto P_0c099d32;
P_0c099d32: /* original 430b, guest PC 0x0c099d32 */
if(!s->budget--) { s->failed_pc=0x0c099d32u; return 0; }
target=r[3];
r[16]=code_base|0x0c099d36u;
r[4]=read(ram,r[14]+16,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c099d36u) { target=s->pc; goto dispatch; }
goto P_0c099d36;
P_0c099d34: /* original 54e4, guest PC 0x0c099d34 */
if(!s->budget--) { s->failed_pc=0x0c099d34u; return 0; }
r[4]=read(ram,r[14]+16,4);
goto P_0c099d36;
P_0c099d36: /* original d226, guest PC 0x0c099d36 */
if(!s->budget--) { s->failed_pc=0x0c099d36u; return 0; }
r[2]=read(ram,0x0c099dd0u,4);
goto P_0c099d38;
P_0c099d38: /* original 420b, guest PC 0x0c099d38 */
if(!s->budget--) { s->failed_pc=0x0c099d38u; return 0; }
target=r[2];
r[16]=code_base|0x0c099d3cu;
r[4]=read(ram,r[14]+20,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c099d3cu) { target=s->pc; goto dispatch; }
goto P_0c099d3c;
P_0c099d3a: /* original 54e5, guest PC 0x0c099d3a */
if(!s->budget--) { s->failed_pc=0x0c099d3au; return 0; }
r[4]=read(ram,r[14]+20,4);
goto P_0c099d3c;
P_0c099d3c: /* original 9032, guest PC 0x0c099d3c */
if(!s->budget--) { s->failed_pc=0x0c099d3cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c099da4u,2);
goto P_0c099d3e;
P_0c099d3e: /* original e400, guest PC 0x0c099d3e */
if(!s->budget--) { s->failed_pc=0x0c099d3eu; return 0; }
r[4]=0x00000000u;
goto P_0c099d40;
P_0c099d40: /* original 0d44, guest PC 0x0c099d40 */
if(!s->budget--) { s->failed_pc=0x0c099d40u; return 0; }
write(ram,r[13]+r[0],r[4],1);
goto P_0c099d42;
P_0c099d42: /* original 7003, guest PC 0x0c099d42 */
if(!s->budget--) { s->failed_pc=0x0c099d42u; return 0; }
r[0]+=0x00000003u;
goto P_0c099d44;
P_0c099d44: /* original 0d44, guest PC 0x0c099d44 */
if(!s->budget--) { s->failed_pc=0x0c099d44u; return 0; }
write(ram,r[13]+r[0],r[4],1);
goto P_0c099d46;
P_0c099d46: /* original 7089, guest PC 0x0c099d46 */
if(!s->budget--) { s->failed_pc=0x0c099d46u; return 0; }
r[0]+=0xffffff89u;
goto P_0c099d48;
P_0c099d48: /* original d322, guest PC 0x0c099d48 */
if(!s->budget--) { s->failed_pc=0x0c099d48u; return 0; }
r[3]=read(ram,0x0c099dd4u,4);
goto P_0c099d4a;
P_0c099d4a: /* original 54ec, guest PC 0x0c099d4a */
if(!s->budget--) { s->failed_pc=0x0c099d4au; return 0; }
r[4]=read(ram,r[14]+48,4);
goto P_0c099d4c;
P_0c099d4c: /* original 0436, guest PC 0x0c099d4c */
if(!s->budget--) { s->failed_pc=0x0c099d4cu; return 0; }
write(ram,r[4]+r[0],r[3],4);
goto P_0c099d4e;
P_0c099d4e: /* original 62f2, guest PC 0x0c099d4e */
if(!s->budget--) { s->failed_pc=0x0c099d4eu; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c099d50;
P_0c099d50: /* original 7f04, guest PC 0x0c099d50 */
if(!s->budget--) { s->failed_pc=0x0c099d50u; return 0; }
r[15]+=0x00000004u;
goto P_0c099d52;
P_0c099d52: /* original 4f26, guest PC 0x0c099d52 */
if(!s->budget--) { s->failed_pc=0x0c099d52u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c099d54;
P_0c099d54: /* original 842b, guest PC 0x0c099d54 */
if(!s->budget--) { s->failed_pc=0x0c099d54u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[2]+11,1);
goto P_0c099d56;
P_0c099d56: /* original 7001, guest PC 0x0c099d56 */
if(!s->budget--) { s->failed_pc=0x0c099d56u; return 0; }
r[0]+=0x00000001u;
goto P_0c099d58;
P_0c099d58: /* original 802b, guest PC 0x0c099d58 */
if(!s->budget--) { s->failed_pc=0x0c099d58u; return 0; }
write(ram,r[2]+11,r[0],1);
goto P_0c099d5a;
P_0c099d5a: /* original 6df6, guest PC 0x0c099d5a */
if(!s->budget--) { s->failed_pc=0x0c099d5au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c099d5c;
P_0c099d5c: /* original d316, guest PC 0x0c099d5c */
if(!s->budget--) { s->failed_pc=0x0c099d5cu; return 0; }
r[3]=read(ram,0x0c099db8u,4);
goto P_0c099d5e;
P_0c099d5e: /* original 432b, guest PC 0x0c099d5e */
if(!s->budget--) { s->failed_pc=0x0c099d5eu; return 0; }
target=r[3];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
switch(target&0x1fffffffu) {
case 0x0c03b450u: return vf3_matrix_family(target,s,ram);
case 0x0c03b4b0u: return vf3_matrix_family(target,s,ram);
case 0x0c03b530u: return vf3_matrix_family(target,s,ram);
case 0x0c03b620u: return vf3_matrix_family(target,s,ram);
case 0x0c03b820u: return vf3_matrix_family(target,s,ram);
case 0x0c03bd80u: return vf3_matrix_family(target,s,ram);
case 0x0c03c0e0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c4a0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c4f0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c610u: return vf3_matrix_family(target,s,ram);
case 0x0c03c6c0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c880u: return vf3_matrix_family(target,s,ram);
case 0x0c03c940u: return vf3_matrix_family(target,s,ram);
case 0x0c03c970u: return vf3_matrix_family(target,s,ram);
case 0x0c03cbd0u: return vf3_matrix_family(target,s,ram);
case 0x0c03cc60u: return vf3_matrix_family(target,s,ram);
case 0x0c03cc90u: return vf3_matrix_family(target,s,ram);
case 0x0c03ccb0u: return vf3_matrix_family(target,s,ram);
default: goto dispatch; }
P_0c099d60: /* original 6ef6, guest PC 0x0c099d60 */
if(!s->budget--) { s->failed_pc=0x0c099d60u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c099d62u,s,ram);
P_0c0c61a8: /* original 2fe6, guest PC 0x0c0c61a8 */
if(!s->budget--) { s->failed_pc=0x0c0c61a8u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c61aa;
P_0c0c61aa: /* original 4411, guest PC 0x0c0c61aa */
if(!s->budget--) { s->failed_pc=0x0c0c61aau; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=0)!=0);
goto P_0c0c61ac;
P_0c0c61ac: /* original 2fd6, guest PC 0x0c0c61ac */
if(!s->budget--) { s->failed_pc=0x0c0c61acu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c61ae;
P_0c0c61ae: /* original 2fc6, guest PC 0x0c0c61ae */
if(!s->budget--) { s->failed_pc=0x0c0c61aeu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c61b0;
P_0c0c61b0: /* original 2fb6, guest PC 0x0c0c61b0 */
if(!s->budget--) { s->failed_pc=0x0c0c61b0u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c61b2;
P_0c0c61b2: /* original 2fa6, guest PC 0x0c0c61b2 */
if(!s->budget--) { s->failed_pc=0x0c0c61b2u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c61b4;
P_0c0c61b4: /* original 2f96, guest PC 0x0c0c61b4 */
if(!s->budget--) { s->failed_pc=0x0c0c61b4u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c61b6;
P_0c0c61b6: /* original 2f86, guest PC 0x0c0c61b6 */
if(!s->budget--) { s->failed_pc=0x0c0c61b6u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c61b8;
P_0c0c61b8: /* original 4f22, guest PC 0x0c0c61b8 */
if(!s->budget--) { s->failed_pc=0x0c0c61b8u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0c61ba;
P_0c0c61ba: /* original 7ffc, guest PC 0x0c0c61ba */
if(!s->budget--) { s->failed_pc=0x0c0c61bau; return 0; }
r[15]+=0xfffffffcu;
goto P_0c0c61bc;
P_0c0c61bc: /* original 8b41, guest PC 0x0c0c61bc */
if(!s->budget--) { s->failed_pc=0x0c0c61bcu; return 0; }
cond=r[17]&1u;
if(!cond) { return vf3_matrix_family(0x0c0c6242u,s,ram); }
goto P_0c0c61be;
P_0c0c61be: /* original 924a, guest PC 0x0c0c61be */
if(!s->budget--) { s->failed_pc=0x0c0c61beu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c6256u,2);
goto P_0c0c61c0;
P_0c0c61c0: /* original 3423, guest PC 0x0c0c61c0 */
if(!s->budget--) { s->failed_pc=0x0c0c61c0u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=(int32_t)r[2])!=0);
goto P_0c0c61c2;
P_0c0c61c2: /* original 893e, guest PC 0x0c0c61c2 */
if(!s->budget--) { s->failed_pc=0x0c0c61c2u; return 0; }
cond=r[17]&1u;
if(cond) { return vf3_matrix_family(0x0c0c6242u,s,ram); }
goto P_0c0c61c4;
P_0c0c61c4: /* original d325, guest PC 0x0c0c61c4 */
if(!s->budget--) { s->failed_pc=0x0c0c61c4u; return 0; }
r[3]=read(ram,0x0c0c625cu,4);
goto P_0c0c61c6;
P_0c0c61c6: /* original 6143, guest PC 0x0c0c61c6 */
if(!s->budget--) { s->failed_pc=0x0c0c61c6u; return 0; }
r[1]=r[4];
goto P_0c0c61c8;
P_0c0c61c8: /* original 4108, guest PC 0x0c0c61c8 */
if(!s->budget--) { s->failed_pc=0x0c0c61c8u; return 0; }
r[1]<<=2;
goto P_0c0c61ca;
P_0c0c61ca: /* original 313c, guest PC 0x0c0c61ca */
if(!s->budget--) { s->failed_pc=0x0c0c61cau; return 0; }
r[1]+=r[3];
goto P_0c0c61cc;
P_0c0c61cc: /* original 2f12, guest PC 0x0c0c61cc */
if(!s->budget--) { s->failed_pc=0x0c0c61ccu; return 0; }
write(ram,r[15],r[1],4);
goto P_0c0c61ce;
P_0c0c61ce: /* original 6212, guest PC 0x0c0c61ce */
if(!s->budget--) { s->failed_pc=0x0c0c61ceu; return 0; }
tmp=read(ram,r[1],4);
r[2]=tmp;
goto P_0c0c61d0;
P_0c0c61d0: /* original 4211, guest PC 0x0c0c61d0 */
if(!s->budget--) { s->failed_pc=0x0c0c61d0u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[2]>=0)!=0);
goto P_0c0c61d2;
P_0c0c61d2: /* original 8b36, guest PC 0x0c0c61d2 */
if(!s->budget--) { s->failed_pc=0x0c0c61d2u; return 0; }
cond=r[17]&1u;
if(!cond) { return vf3_matrix_family(0x0c0c6242u,s,ram); }
goto P_0c0c61d4;
P_0c0c61d4: /* original da23, guest PC 0x0c0c61d4 */
if(!s->budget--) { s->failed_pc=0x0c0c61d4u; return 0; }
r[10]=read(ram,0x0c0c6264u,4);
goto P_0c0c61d6;
P_0c0c61d6: /* original ec00, guest PC 0x0c0c61d6 */
if(!s->budget--) { s->failed_pc=0x0c0c61d6u; return 0; }
r[12]=0x00000000u;
goto P_0c0c61d8;
P_0c0c61d8: /* original db23, guest PC 0x0c0c61d8 */
if(!s->budget--) { s->failed_pc=0x0c0c61d8u; return 0; }
r[11]=read(ram,0x0c0c6268u,4);
goto P_0c0c61da;
P_0c0c61da: /* original dd24, guest PC 0x0c0c61da */
if(!s->budget--) { s->failed_pc=0x0c0c61dau; return 0; }
r[13]=read(ram,0x0c0c626cu,4);
goto P_0c0c61dc;
P_0c0c61dc: /* original d920, guest PC 0x0c0c61dc */
if(!s->budget--) { s->failed_pc=0x0c0c61dcu; return 0; }
r[9]=read(ram,0x0c0c6260u,4);
goto P_0c0c61de;
P_0c0c61de: /* original 983b, guest PC 0x0c0c61de */
if(!s->budget--) { s->failed_pc=0x0c0c61deu; return 0; }
r[8]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c6258u,2);
goto P_0c0c61e0;
P_0c0c61e0: /* original 6ec3, guest PC 0x0c0c61e0 */
if(!s->budget--) { s->failed_pc=0x0c0c61e0u; return 0; }
r[14]=r[12];
goto P_0c0c61e2;
P_0c0c61e2: /* original 4e08, guest PC 0x0c0c61e2 */
if(!s->budget--) { s->failed_pc=0x0c0c61e2u; return 0; }
r[14]<<=2;
goto P_0c0c61e4;
P_0c0c61e4: /* original 4e00, guest PC 0x0c0c61e4 */
if(!s->budget--) { s->failed_pc=0x0c0c61e4u; return 0; }
r[17]=(r[17]&~1u)|((r[14]>>31)!=0);
r[14]<<=1;
goto P_0c0c61e6;
P_0c0c61e6: /* original 3ebc, guest PC 0x0c0c61e6 */
if(!s->budget--) { s->failed_pc=0x0c0c61e6u; return 0; }
r[14]+=r[11];
goto P_0c0c61e8;
P_0c0c61e8: /* original 53e1, guest PC 0x0c0c61e8 */
if(!s->budget--) { s->failed_pc=0x0c0c61e8u; return 0; }
r[3]=read(ram,r[14]+4,4);
goto P_0c0c61ea;
P_0c0c61ea: /* original 2338, guest PC 0x0c0c61ea */
if(!s->budget--) { s->failed_pc=0x0c0c61eau; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c0c61ec;
P_0c0c61ec: /* original 8929, guest PC 0x0c0c61ec */
if(!s->budget--) { s->failed_pc=0x0c0c61ecu; return 0; }
cond=r[17]&1u;
if(cond) { return vf3_matrix_family(0x0c0c6242u,s,ram); }
goto P_0c0c61ee;
P_0c0c61ee: /* original 52e1, guest PC 0x0c0c61ee */
if(!s->budget--) { s->failed_pc=0x0c0c61eeu; return 0; }
r[2]=read(ram,r[14]+4,4);
goto P_0c0c61f0;
P_0c0c61f0: /* original 3420, guest PC 0x0c0c61f0 */
if(!s->budget--) { s->failed_pc=0x0c0c61f0u; return 0; }
r[17]=(r[17]&~1u)|((r[4]==r[2])!=0);
goto P_0c0c61f2;
P_0c0c61f2: /* original 8b24, guest PC 0x0c0c61f2 */
if(!s->budget--) { s->failed_pc=0x0c0c61f2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c623e; }
goto P_0c0c61f4;
P_0c0c61f4: /* original 6392, guest PC 0x0c0c61f4 */
if(!s->budget--) { s->failed_pc=0x0c0c61f4u; return 0; }
tmp=read(ram,r[9],4);
r[3]=tmp;
goto P_0c0c61f6;
P_0c0c61f6: /* original 61e2, guest PC 0x0c0c61f6 */
if(!s->budget--) { s->failed_pc=0x0c0c61f6u; return 0; }
tmp=read(ram,r[14],4);
r[1]=tmp;
goto P_0c0c61f8;
P_0c0c61f8: /* original 3310, guest PC 0x0c0c61f8 */
if(!s->budget--) { s->failed_pc=0x0c0c61f8u; return 0; }
r[17]=(r[17]&~1u)|((r[3]==r[1])!=0);
goto P_0c0c61fa;
P_0c0c61fa: /* original 891a, guest PC 0x0c0c61fa */
if(!s->budget--) { s->failed_pc=0x0c0c61fau; return 0; }
cond=r[17]&1u;
if(cond) { return vf3_matrix_family(0x0c0c6232u,s,ram); }
goto P_0c0c61fc;
P_0c0c61fc: /* original 65a2, guest PC 0x0c0c61fc */
if(!s->budget--) { s->failed_pc=0x0c0c61fcu; return 0; }
tmp=read(ram,r[10],4);
r[5]=tmp;
goto P_0c0c61fe;
P_0c0c61fe: /* original d31c, guest PC 0x0c0c61fe */
if(!s->budget--) { s->failed_pc=0x0c0c61feu; return 0; }
r[3]=read(ram,0x0c0c6270u,4);
goto P_0c0c6200;
P_0c0c6200: /* original 35dc, guest PC 0x0c0c6200 */
if(!s->budget--) { s->failed_pc=0x0c0c6200u; return 0; }
r[5]+=r[13];
goto P_0c0c6202;
P_0c0c6202: /* original 430b, guest PC 0x0c0c6202 */
if(!s->budget--) { s->failed_pc=0x0c0c6202u; return 0; }
target=r[3];
r[16]=code_base|0x0c0c6206u;
tmp=read(ram,r[14],4);
r[4]=tmp;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c6206u) { target=s->pc; goto dispatch; }
return vf3_matrix_family(0x0c0c6206u,s,ram);
P_0c0c6204: /* original 64e2, guest PC 0x0c0c6204 */
if(!s->budget--) { s->failed_pc=0x0c0c6204u; return 0; }
tmp=read(ram,r[14],4);
r[4]=tmp;
return vf3_matrix_family(0x0c0c6206u,s,ram);
P_0c0c623e: /* original afcf, guest PC 0x0c0c623e */
if(!s->budget--) { s->failed_pc=0x0c0c623eu; return 0; }
r[12]+=0x00000001u;
goto P_0c0c61e0;
P_0c0c6240: /* original 7c01, guest PC 0x0c0c6240 */
if(!s->budget--) { s->failed_pc=0x0c0c6240u; return 0; }
r[12]+=0x00000001u;
return vf3_matrix_family(0x0c0c6242u,s,ram);
P_0c0c99ca: /* original d539, guest PC 0x0c0c99ca */
if(!s->budget--) { s->failed_pc=0x0c0c99cau; return 0; }
r[5]=read(ram,0x0c0c9ab0u,4);
goto P_0c0c99cc;
P_0c0c99cc: /* original e010, guest PC 0x0c0c99cc */
if(!s->budget--) { s->failed_pc=0x0c0c99ccu; return 0; }
r[0]=0x00000010u;
goto P_0c0c99ce;
P_0c0c99ce: /* original e365, guest PC 0x0c0c99ce */
if(!s->budget--) { s->failed_pc=0x0c0c99ceu; return 0; }
r[3]=0x00000065u;
goto P_0c0c99d0;
P_0c0c99d0: /* original d438, guest PC 0x0c0c99d0 */
if(!s->budget--) { s->failed_pc=0x0c0c99d0u; return 0; }
r[4]=read(ram,0x0c0c9ab4u,4);
goto P_0c0c99d2;
P_0c0c99d2: /* original 0534, guest PC 0x0c0c99d2 */
if(!s->budget--) { s->failed_pc=0x0c0c99d2u; return 0; }
write(ram,r[5]+r[0],r[3],1);
goto P_0c0c99d4;
P_0c0c99d4: /* original e601, guest PC 0x0c0c99d4 */
if(!s->budget--) { s->failed_pc=0x0c0c99d4u; return 0; }
r[6]=0x00000001u;
goto P_0c0c99d6;
P_0c0c99d6: /* original 9062, guest PC 0x0c0c99d6 */
if(!s->budget--) { s->failed_pc=0x0c0c99d6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c9a9eu,2);
goto P_0c0c99d8;
P_0c0c99d8: /* original e300, guest PC 0x0c0c99d8 */
if(!s->budget--) { s->failed_pc=0x0c0c99d8u; return 0; }
r[3]=0x00000000u;
goto P_0c0c99da;
P_0c0c99da: /* original 0464, guest PC 0x0c0c99da */
if(!s->budget--) { s->failed_pc=0x0c0c99dau; return 0; }
write(ram,r[4]+r[0],r[6],1);
goto P_0c0c99dc;
P_0c0c99dc: /* original 7001, guest PC 0x0c0c99dc */
if(!s->budget--) { s->failed_pc=0x0c0c99dcu; return 0; }
r[0]+=0x00000001u;
goto P_0c0c99de;
P_0c0c99de: /* original 0464, guest PC 0x0c0c99de */
if(!s->budget--) { s->failed_pc=0x0c0c99deu; return 0; }
write(ram,r[4]+r[0],r[6],1);
goto P_0c0c99e0;
P_0c0c99e0: /* original 70fd, guest PC 0x0c0c99e0 */
if(!s->budget--) { s->failed_pc=0x0c0c99e0u; return 0; }
r[0]+=0xfffffffdu;
goto P_0c0c99e2;
P_0c0c99e2: /* original 0434, guest PC 0x0c0c99e2 */
if(!s->budget--) { s->failed_pc=0x0c0c99e2u; return 0; }
write(ram,r[4]+r[0],r[3],1);
goto P_0c0c99e4;
P_0c0c99e4: /* original 845b, guest PC 0x0c0c99e4 */
if(!s->budget--) { s->failed_pc=0x0c0c99e4u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[5]+11,1);
goto P_0c0c99e6;
P_0c0c99e6: /* original d331, guest PC 0x0c0c99e6 */
if(!s->budget--) { s->failed_pc=0x0c0c99e6u; return 0; }
r[3]=read(ram,0x0c0c9aacu,4);
goto P_0c0c99e8;
P_0c0c99e8: /* original 7001, guest PC 0x0c0c99e8 */
if(!s->budget--) { s->failed_pc=0x0c0c99e8u; return 0; }
r[0]+=0x00000001u;
goto P_0c0c99ea;
P_0c0c99ea: /* original 432b, guest PC 0x0c0c99ea */
if(!s->budget--) { s->failed_pc=0x0c0c99eau; return 0; }
target=r[3];
write(ram,r[5]+11,r[0],1);
switch(target&0x1fffffffu) {
case 0x0c03b450u: return vf3_matrix_family(target,s,ram);
case 0x0c03b4b0u: return vf3_matrix_family(target,s,ram);
case 0x0c03b530u: return vf3_matrix_family(target,s,ram);
case 0x0c03b620u: return vf3_matrix_family(target,s,ram);
case 0x0c03b820u: return vf3_matrix_family(target,s,ram);
case 0x0c03bd80u: return vf3_matrix_family(target,s,ram);
case 0x0c03c0e0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c4a0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c4f0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c610u: return vf3_matrix_family(target,s,ram);
case 0x0c03c6c0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c880u: return vf3_matrix_family(target,s,ram);
case 0x0c03c940u: return vf3_matrix_family(target,s,ram);
case 0x0c03c970u: return vf3_matrix_family(target,s,ram);
case 0x0c03cbd0u: return vf3_matrix_family(target,s,ram);
case 0x0c03cc60u: return vf3_matrix_family(target,s,ram);
case 0x0c03cc90u: return vf3_matrix_family(target,s,ram);
case 0x0c03ccb0u: return vf3_matrix_family(target,s,ram);
default: goto dispatch; }
P_0c0c99ec: /* original 805b, guest PC 0x0c0c99ec */
if(!s->budget--) { s->failed_pc=0x0c0c99ecu; return 0; }
write(ram,r[5]+11,r[0],1);
goto P_0c0c99ee;
P_0c0c99ee: /* original 2fe6, guest PC 0x0c0c99ee */
if(!s->budget--) { s->failed_pc=0x0c0c99eeu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c99f0;
P_0c0c99f0: /* original 2fd6, guest PC 0x0c0c99f0 */
if(!s->budget--) { s->failed_pc=0x0c0c99f0u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c99f2;
P_0c0c99f2: /* original ed00, guest PC 0x0c0c99f2 */
if(!s->budget--) { s->failed_pc=0x0c0c99f2u; return 0; }
r[13]=0x00000000u;
goto P_0c0c99f4;
P_0c0c99f4: /* original 2fc6, guest PC 0x0c0c99f4 */
if(!s->budget--) { s->failed_pc=0x0c0c99f4u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c99f6;
P_0c0c99f6: /* original de2f, guest PC 0x0c0c99f6 */
if(!s->budget--) { s->failed_pc=0x0c0c99f6u; return 0; }
r[14]=read(ram,0x0c0c9ab4u,4);
goto P_0c0c99f8;
P_0c0c99f8: /* original 9052, guest PC 0x0c0c99f8 */
if(!s->budget--) { s->failed_pc=0x0c0c99f8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c9aa0u,2);
goto P_0c0c99fa;
P_0c0c99fa: /* original d52d, guest PC 0x0c0c99fa */
if(!s->budget--) { s->failed_pc=0x0c0c99fau; return 0; }
r[5]=read(ram,0x0c0c9ab0u,4);
goto P_0c0c99fc;
P_0c0c99fc: /* original 03ec, guest PC 0x0c0c99fc */
if(!s->budget--) { s->failed_pc=0x0c0c99fcu; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
return vf3_matrix_family(0x0c0c99feu,s,ram);
P_0c0c9a7a: /* original d50d, guest PC 0x0c0c9a7a */
if(!s->budget--) { s->failed_pc=0x0c0c9a7au; return 0; }
r[5]=read(ram,0x0c0c9ab0u,4);
goto P_0c0c9a7c;
P_0c0c9a7c: /* original e010, guest PC 0x0c0c9a7c */
if(!s->budget--) { s->failed_pc=0x0c0c9a7cu; return 0; }
r[0]=0x00000010u;
goto P_0c0c9a7e;
P_0c0c9a7e: /* original e367, guest PC 0x0c0c9a7e */
if(!s->budget--) { s->failed_pc=0x0c0c9a7eu; return 0; }
r[3]=0x00000067u;
goto P_0c0c9a80;
P_0c0c9a80: /* original d40c, guest PC 0x0c0c9a80 */
if(!s->budget--) { s->failed_pc=0x0c0c9a80u; return 0; }
r[4]=read(ram,0x0c0c9ab4u,4);
goto P_0c0c9a82;
P_0c0c9a82: /* original 0534, guest PC 0x0c0c9a82 */
if(!s->budget--) { s->failed_pc=0x0c0c9a82u; return 0; }
write(ram,r[5]+r[0],r[3],1);
goto P_0c0c9a84;
P_0c0c9a84: /* original e601, guest PC 0x0c0c9a84 */
if(!s->budget--) { s->failed_pc=0x0c0c9a84u; return 0; }
r[6]=0x00000001u;
goto P_0c0c9a86;
P_0c0c9a86: /* original 900a, guest PC 0x0c0c9a86 */
if(!s->budget--) { s->failed_pc=0x0c0c9a86u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c9a9eu,2);
goto P_0c0c9a88;
P_0c0c9a88: /* original e300, guest PC 0x0c0c9a88 */
if(!s->budget--) { s->failed_pc=0x0c0c9a88u; return 0; }
r[3]=0x00000000u;
goto P_0c0c9a8a;
P_0c0c9a8a: /* original 0464, guest PC 0x0c0c9a8a */
if(!s->budget--) { s->failed_pc=0x0c0c9a8au; return 0; }
write(ram,r[4]+r[0],r[6],1);
goto P_0c0c9a8c;
P_0c0c9a8c: /* original 7001, guest PC 0x0c0c9a8c */
if(!s->budget--) { s->failed_pc=0x0c0c9a8cu; return 0; }
r[0]+=0x00000001u;
goto P_0c0c9a8e;
P_0c0c9a8e: /* original 0464, guest PC 0x0c0c9a8e */
if(!s->budget--) { s->failed_pc=0x0c0c9a8eu; return 0; }
write(ram,r[4]+r[0],r[6],1);
goto P_0c0c9a90;
P_0c0c9a90: /* original 70fd, guest PC 0x0c0c9a90 */
if(!s->budget--) { s->failed_pc=0x0c0c9a90u; return 0; }
r[0]+=0xfffffffdu;
goto P_0c0c9a92;
P_0c0c9a92: /* original 0434, guest PC 0x0c0c9a92 */
if(!s->budget--) { s->failed_pc=0x0c0c9a92u; return 0; }
write(ram,r[4]+r[0],r[3],1);
goto P_0c0c9a94;
P_0c0c9a94: /* original 845b, guest PC 0x0c0c9a94 */
if(!s->budget--) { s->failed_pc=0x0c0c9a94u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[5]+11,1);
goto P_0c0c9a96;
P_0c0c9a96: /* original d305, guest PC 0x0c0c9a96 */
if(!s->budget--) { s->failed_pc=0x0c0c9a96u; return 0; }
r[3]=read(ram,0x0c0c9aacu,4);
goto P_0c0c9a98;
P_0c0c9a98: /* original 7001, guest PC 0x0c0c9a98 */
if(!s->budget--) { s->failed_pc=0x0c0c9a98u; return 0; }
r[0]+=0x00000001u;
goto P_0c0c9a9a;
P_0c0c9a9a: /* original 432b, guest PC 0x0c0c9a9a */
if(!s->budget--) { s->failed_pc=0x0c0c9a9au; return 0; }
target=r[3];
write(ram,r[5]+11,r[0],1);
switch(target&0x1fffffffu) {
case 0x0c03b450u: return vf3_matrix_family(target,s,ram);
case 0x0c03b4b0u: return vf3_matrix_family(target,s,ram);
case 0x0c03b530u: return vf3_matrix_family(target,s,ram);
case 0x0c03b620u: return vf3_matrix_family(target,s,ram);
case 0x0c03b820u: return vf3_matrix_family(target,s,ram);
case 0x0c03bd80u: return vf3_matrix_family(target,s,ram);
case 0x0c03c0e0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c4a0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c4f0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c610u: return vf3_matrix_family(target,s,ram);
case 0x0c03c6c0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c880u: return vf3_matrix_family(target,s,ram);
case 0x0c03c940u: return vf3_matrix_family(target,s,ram);
case 0x0c03c970u: return vf3_matrix_family(target,s,ram);
case 0x0c03cbd0u: return vf3_matrix_family(target,s,ram);
case 0x0c03cc60u: return vf3_matrix_family(target,s,ram);
case 0x0c03cc90u: return vf3_matrix_family(target,s,ram);
case 0x0c03ccb0u: return vf3_matrix_family(target,s,ram);
default: goto dispatch; }
P_0c0c9a9c: /* original 805b, guest PC 0x0c0c9a9c */
if(!s->budget--) { s->failed_pc=0x0c0c9a9cu; return 0; }
write(ram,r[5]+11,r[0],1);
return vf3_matrix_family(0x0c0c9a9eu,s,ram);
P_0c0c9ad0: /* original 2fe6, guest PC 0x0c0c9ad0 */
if(!s->budget--) { s->failed_pc=0x0c0c9ad0u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c9ad2;
P_0c0c9ad2: /* original 9046, guest PC 0x0c0c9ad2 */
if(!s->budget--) { s->failed_pc=0x0c0c9ad2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c9b62u,2);
goto P_0c0c9ad4;
P_0c0c9ad4: /* original de26, guest PC 0x0c0c9ad4 */
if(!s->budget--) { s->failed_pc=0x0c0c9ad4u; return 0; }
r[14]=read(ram,0x0c0c9b70u,4);
goto P_0c0c9ad6;
P_0c0c9ad6: /* original d525, guest PC 0x0c0c9ad6 */
if(!s->budget--) { s->failed_pc=0x0c0c9ad6u; return 0; }
r[5]=read(ram,0x0c0c9b6cu,4);
goto P_0c0c9ad8;
P_0c0c9ad8: /* original 03ec, guest PC 0x0c0c9ad8 */
if(!s->budget--) { s->failed_pc=0x0c0c9ad8u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0c9ada;
P_0c0c9ada: /* original 4f22, guest PC 0x0c0c9ada */
if(!s->budget--) { s->failed_pc=0x0c0c9adau; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0c9adc;
P_0c0c9adc: /* original 2338, guest PC 0x0c0c9adc */
if(!s->budget--) { s->failed_pc=0x0c0c9adcu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c0c9ade;
P_0c0c9ade: /* original 7ffc, guest PC 0x0c0c9ade */
if(!s->budget--) { s->failed_pc=0x0c0c9adeu; return 0; }
r[15]+=0xfffffffcu;
goto P_0c0c9ae0;
P_0c0c9ae0: /* original 2f32, guest PC 0x0c0c9ae0 */
if(!s->budget--) { s->failed_pc=0x0c0c9ae0u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c0c9ae2;
P_0c0c9ae2: /* original 903f, guest PC 0x0c0c9ae2 */
if(!s->budget--) { s->failed_pc=0x0c0c9ae2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c9b64u,2);
goto P_0c0c9ae4;
P_0c0c9ae4: /* original d723, guest PC 0x0c0c9ae4 */
if(!s->budget--) { s->failed_pc=0x0c0c9ae4u; return 0; }
r[7]=read(ram,0x0c0c9b74u,4);
goto P_0c0c9ae6;
P_0c0c9ae6: /* original 065e, guest PC 0x0c0c9ae6 */
if(!s->budget--) { s->failed_pc=0x0c0c9ae6u; return 0; }
r[6]=read(ram,r[5]+r[0],4);
goto P_0c0c9ae8;
P_0c0c9ae8: /* original 903d, guest PC 0x0c0c9ae8 */
if(!s->budget--) { s->failed_pc=0x0c0c9ae8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c9b66u,2);
goto P_0c0c9aea;
P_0c0c9aea: /* original 04ec, guest PC 0x0c0c9aea */
if(!s->budget--) { s->failed_pc=0x0c0c9aeau; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0c9aec;
P_0c0c9aec: /* original 8f16, guest PC 0x0c0c9aec */
if(!s->budget--) { s->failed_pc=0x0c0c9aecu; return 0; }
cond=r[17]&1u;
r[7]&=r[6];
if(!cond) { goto P_0c0c9b1c; }
goto P_0c0c9af0;
P_0c0c9aee: /* original 2769, guest PC 0x0c0c9aee */
if(!s->budget--) { s->failed_pc=0x0c0c9aeeu; return 0; }
r[7]&=r[6];
goto P_0c0c9af0;
P_0c0c9af0: /* original 2778, guest PC 0x0c0c9af0 */
if(!s->budget--) { s->failed_pc=0x0c0c9af0u; return 0; }
r[17]=(r[17]&~1u)|(((r[7]&r[7])==0)!=0);
goto P_0c0c9af2;
P_0c0c9af2: /* original 8b09, guest PC 0x0c0c9af2 */
if(!s->budget--) { s->failed_pc=0x0c0c9af2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c9b08; }
goto P_0c0c9af4;
P_0c0c9af4: /* original d220, guest PC 0x0c0c9af4 */
if(!s->budget--) { s->failed_pc=0x0c0c9af4u; return 0; }
r[2]=read(ram,0x0c0c9b78u,4);
goto P_0c0c9af6;
P_0c0c9af6: /* original 2628, guest PC 0x0c0c9af6 */
if(!s->budget--) { s->failed_pc=0x0c0c9af6u; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[2])==0)!=0);
goto P_0c0c9af8;
P_0c0c9af8: /* original 8914, guest PC 0x0c0c9af8 */
if(!s->budget--) { s->failed_pc=0x0c0c9af8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c9b24; }
goto P_0c0c9afa;
P_0c0c9afa: /* original 9035, guest PC 0x0c0c9afa */
if(!s->budget--) { s->failed_pc=0x0c0c9afau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c9b68u,2);
goto P_0c0c9afc;
P_0c0c9afc: /* original e301, guest PC 0x0c0c9afc */
if(!s->budget--) { s->failed_pc=0x0c0c9afcu; return 0; }
r[3]=0x00000001u;
goto P_0c0c9afe;
P_0c0c9afe: /* original 0e44, guest PC 0x0c0c9afe */
if(!s->budget--) { s->failed_pc=0x0c0c9afeu; return 0; }
write(ram,r[14]+r[0],r[4],1);
goto P_0c0c9b00;
P_0c0c9b00: /* original 70ff, guest PC 0x0c0c9b00 */
if(!s->budget--) { s->failed_pc=0x0c0c9b00u; return 0; }
r[0]+=0xffffffffu;
goto P_0c0c9b02;
P_0c0c9b02: /* original 243a, guest PC 0x0c0c9b02 */
if(!s->budget--) { s->failed_pc=0x0c0c9b02u; return 0; }
r[4]^=r[3];
goto P_0c0c9b04;
P_0c0c9b04: /* original a00e, guest PC 0x0c0c9b04 */
if(!s->budget--) { s->failed_pc=0x0c0c9b04u; return 0; }
write(ram,r[14]+r[0],r[4],1);
goto P_0c0c9b24;
P_0c0c9b06: /* original 0e44, guest PC 0x0c0c9b06 */
if(!s->budget--) { s->failed_pc=0x0c0c9b06u; return 0; }
write(ram,r[14]+r[0],r[4],1);
goto P_0c0c9b08;
P_0c0c9b08: /* original 2448, guest PC 0x0c0c9b08 */
if(!s->budget--) { s->failed_pc=0x0c0c9b08u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c0c9b0a;
P_0c0c9b0a: /* original 8b09, guest PC 0x0c0c9b0a */
if(!s->budget--) { s->failed_pc=0x0c0c9b0au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c9b20; }
goto P_0c0c9b0c;
P_0c0c9b0c: /* original d21b, guest PC 0x0c0c9b0c */
if(!s->budget--) { s->failed_pc=0x0c0c9b0cu; return 0; }
r[2]=read(ram,0x0c0c9b7cu,4);
goto P_0c0c9b0e;
P_0c0c9b0e: /* original 420b, guest PC 0x0c0c9b0e */
if(!s->budget--) { s->failed_pc=0x0c0c9b0eu; return 0; }
target=r[2];
r[16]=code_base|0x0c0c9b12u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c9b12u) { target=s->pc; goto dispatch; }
goto P_0c0c9b12;
P_0c0c9b10: /* original 0009, guest PC 0x0c0c9b10 */
if(!s->budget--) { s->failed_pc=0x0c0c9b10u; return 0; }
goto P_0c0c9b12;
P_0c0c9b12: /* original 9026, guest PC 0x0c0c9b12 */
if(!s->budget--) { s->failed_pc=0x0c0c9b12u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c9b62u,2);
goto P_0c0c9b14;
P_0c0c9b14: /* original 03ec, guest PC 0x0c0c9b14 */
if(!s->budget--) { s->failed_pc=0x0c0c9b14u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0c9b16;
P_0c0c9b16: /* original 7301, guest PC 0x0c0c9b16 */
if(!s->budget--) { s->failed_pc=0x0c0c9b16u; return 0; }
r[3]+=0x00000001u;
goto P_0c0c9b18;
P_0c0c9b18: /* original a004, guest PC 0x0c0c9b18 */
if(!s->budget--) { s->failed_pc=0x0c0c9b18u; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c0c9b24;
P_0c0c9b1a: /* original 0e34, guest PC 0x0c0c9b1a */
if(!s->budget--) { s->failed_pc=0x0c0c9b1au; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c0c9b1c;
P_0c0c9b1c: /* original 2778, guest PC 0x0c0c9b1c */
if(!s->budget--) { s->failed_pc=0x0c0c9b1cu; return 0; }
r[17]=(r[17]&~1u)|(((r[7]&r[7])==0)!=0);
goto P_0c0c9b1e;
P_0c0c9b1e: /* original 8901, guest PC 0x0c0c9b1e */
if(!s->budget--) { s->failed_pc=0x0c0c9b1eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c9b24; }
goto P_0c0c9b20;
P_0c0c9b20: /* original e000, guest PC 0x0c0c9b20 */
if(!s->budget--) { s->failed_pc=0x0c0c9b20u; return 0; }
r[0]=0x00000000u;
goto P_0c0c9b22;
P_0c0c9b22: /* original 805b, guest PC 0x0c0c9b22 */
if(!s->budget--) { s->failed_pc=0x0c0c9b22u; return 0; }
write(ram,r[5]+11,r[0],1);
goto P_0c0c9b24;
P_0c0c9b24: /* original 7f04, guest PC 0x0c0c9b24 */
if(!s->budget--) { s->failed_pc=0x0c0c9b24u; return 0; }
r[15]+=0x00000004u;
goto P_0c0c9b26;
P_0c0c9b26: /* original d316, guest PC 0x0c0c9b26 */
if(!s->budget--) { s->failed_pc=0x0c0c9b26u; return 0; }
r[3]=read(ram,0x0c0c9b80u,4);
goto P_0c0c9b28;
P_0c0c9b28: /* original 4f26, guest PC 0x0c0c9b28 */
if(!s->budget--) { s->failed_pc=0x0c0c9b28u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0c9b2a;
P_0c0c9b2a: /* original 432b, guest PC 0x0c0c9b2a */
if(!s->budget--) { s->failed_pc=0x0c0c9b2au; return 0; }
target=r[3];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
switch(target&0x1fffffffu) {
case 0x0c03b450u: return vf3_matrix_family(target,s,ram);
case 0x0c03b4b0u: return vf3_matrix_family(target,s,ram);
case 0x0c03b530u: return vf3_matrix_family(target,s,ram);
case 0x0c03b620u: return vf3_matrix_family(target,s,ram);
case 0x0c03b820u: return vf3_matrix_family(target,s,ram);
case 0x0c03bd80u: return vf3_matrix_family(target,s,ram);
case 0x0c03c0e0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c4a0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c4f0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c610u: return vf3_matrix_family(target,s,ram);
case 0x0c03c6c0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c880u: return vf3_matrix_family(target,s,ram);
case 0x0c03c940u: return vf3_matrix_family(target,s,ram);
case 0x0c03c970u: return vf3_matrix_family(target,s,ram);
case 0x0c03cbd0u: return vf3_matrix_family(target,s,ram);
case 0x0c03cc60u: return vf3_matrix_family(target,s,ram);
case 0x0c03cc90u: return vf3_matrix_family(target,s,ram);
case 0x0c03ccb0u: return vf3_matrix_family(target,s,ram);
default: goto dispatch; }
P_0c0c9b2c: /* original 6ef6, guest PC 0x0c0c9b2c */
if(!s->budget--) { s->failed_pc=0x0c0c9b2cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0c9b2eu,s,ram);
P_0c0ca05c: /* original e061, guest PC 0x0c0ca05c */
if(!s->budget--) { s->failed_pc=0x0c0ca05cu; return 0; }
r[0]=0x00000061u;
goto P_0c0ca05e;
P_0c0ca05e: /* original 034c, guest PC 0x0c0ca05e */
if(!s->budget--) { s->failed_pc=0x0c0ca05eu; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c0ca060;
P_0c0ca060: /* original d003, guest PC 0x0c0ca060 */
if(!s->budget--) { s->failed_pc=0x0c0ca060u; return 0; }
r[0]=read(ram,0x0c0ca070u,4);
goto P_0c0ca062;
P_0c0ca062: /* original 633c, guest PC 0x0c0ca062 */
if(!s->budget--) { s->failed_pc=0x0c0ca062u; return 0; }
r[3]=r[3]&255u;
goto P_0c0ca064;
P_0c0ca064: /* original 4308, guest PC 0x0c0ca064 */
if(!s->budget--) { s->failed_pc=0x0c0ca064u; return 0; }
r[3]<<=2;
goto P_0c0ca066;
P_0c0ca066: /* original 043e, guest PC 0x0c0ca066 */
if(!s->budget--) { s->failed_pc=0x0c0ca066u; return 0; }
r[4]=read(ram,r[3]+r[0],4);
goto P_0c0ca068;
P_0c0ca068: /* original d302, guest PC 0x0c0ca068 */
if(!s->budget--) { s->failed_pc=0x0c0ca068u; return 0; }
r[3]=read(ram,0x0c0ca074u,4);
goto P_0c0ca06a;
P_0c0ca06a: /* original 432b, guest PC 0x0c0ca06a */
if(!s->budget--) { s->failed_pc=0x0c0ca06au; return 0; }
target=r[3];
switch(target&0x1fffffffu) {
case 0x0c03b450u: return vf3_matrix_family(target,s,ram);
case 0x0c03b4b0u: return vf3_matrix_family(target,s,ram);
case 0x0c03b530u: return vf3_matrix_family(target,s,ram);
case 0x0c03b620u: return vf3_matrix_family(target,s,ram);
case 0x0c03b820u: return vf3_matrix_family(target,s,ram);
case 0x0c03bd80u: return vf3_matrix_family(target,s,ram);
case 0x0c03c0e0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c4a0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c4f0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c610u: return vf3_matrix_family(target,s,ram);
case 0x0c03c6c0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c880u: return vf3_matrix_family(target,s,ram);
case 0x0c03c940u: return vf3_matrix_family(target,s,ram);
case 0x0c03c970u: return vf3_matrix_family(target,s,ram);
case 0x0c03cbd0u: return vf3_matrix_family(target,s,ram);
case 0x0c03cc60u: return vf3_matrix_family(target,s,ram);
case 0x0c03cc90u: return vf3_matrix_family(target,s,ram);
case 0x0c03ccb0u: return vf3_matrix_family(target,s,ram);
default: goto dispatch; }
P_0c0ca06c: /* original 0009, guest PC 0x0c0ca06c */
if(!s->budget--) { s->failed_pc=0x0c0ca06cu; return 0; }
return vf3_matrix_family(0x0c0ca06eu,s,ram);
unsupported: s->failed_pc=target; return 0;
}
static const uint32_t owned_pcs[]={
0x0c040b7cu,0x0c08a068u,0x0c08a06au,0x0c08a06cu,0x0c08a06eu,0x0c08a070u,0x0c08a072u,0x0c08a074u,0x0c091eb8u,0x0c091ebau,0x0c091ebcu,0x0c091ebeu,0x0c091ec0u,0x0c091ec2u,0x0c091ec4u,0x0c091ec6u,
0x0c091ec8u,0x0c091ecau,0x0c091eccu,0x0c091eceu,0x0c091ed0u,0x0c091ed2u,0x0c091ed4u,0x0c091ed6u,0x0c091ed8u,0x0c091edau,0x0c091edcu,0x0c091edeu,0x0c091ee0u,0x0c091ee2u,0x0c091ee4u,0x0c091ee6u,
0x0c091ee8u,0x0c091eeau,0x0c091eecu,0x0c091eeeu,0x0c091ef0u,0x0c091ef2u,0x0c091ef4u,0x0c091ef6u,0x0c091ef8u,0x0c091efau,0x0c091efcu,0x0c091efeu,0x0c091f00u,0x0c091f02u,0x0c091f04u,0x0c091f06u,
0x0c091f08u,0x0c091f0au,0x0c091f0cu,0x0c091f0eu,0x0c091f10u,0x0c091f12u,0x0c091f14u,0x0c091f16u,0x0c091f18u,0x0c091f1au,0x0c091f1cu,0x0c091f1eu,0x0c091f20u,0x0c091f22u,0x0c091f24u,0x0c091f26u,
0x0c091f28u,0x0c091f2au,0x0c091f2cu,0x0c091f2eu,0x0c091f30u,0x0c091f32u,0x0c091f34u,0x0c0970beu,0x0c0970c0u,0x0c0970c2u,0x0c0970c4u,0x0c0970c6u,0x0c0970c8u,0x0c0970cau,0x0c0970ccu,0x0c0970ceu,
0x0c0978eau,0x0c0978ecu,0x0c097abcu,0x0c097abeu,0x0c097ac0u,0x0c097ac2u,0x0c097ac4u,0x0c097ac6u,0x0c097ac8u,0x0c097acau,0x0c097accu,0x0c097aceu,0x0c097ad0u,0x0c097ad2u,0x0c097ad4u,0x0c097ad6u,
0x0c097ad8u,0x0c097adau,0x0c097adcu,0x0c097adeu,0x0c097ae0u,0x0c097ae2u,0x0c097ae4u,0x0c097ae6u,0x0c097ae8u,0x0c097aeau,0x0c097aecu,0x0c097aeeu,0x0c097af0u,0x0c097af2u,0x0c097af4u,0x0c097af6u,
0x0c097af8u,0x0c097afau,0x0c097afcu,0x0c097afeu,0x0c097b00u,0x0c097b02u,0x0c097b04u,0x0c097b06u,0x0c097b08u,0x0c097b0au,0x0c097b0cu,0x0c097b0eu,0x0c097b10u,0x0c097b12u,0x0c097b14u,0x0c097b16u,
0x0c097b18u,0x0c097b1au,0x0c097b1cu,0x0c097b1eu,0x0c097b20u,0x0c097b22u,0x0c097b24u,0x0c097b26u,0x0c097b28u,0x0c097b2au,0x0c097b2cu,0x0c097b2eu,0x0c097b30u,0x0c097b32u,0x0c097b34u,0x0c097b36u,
0x0c097b38u,0x0c097b3au,0x0c097b3cu,0x0c097b3eu,0x0c097b40u,0x0c097b42u,0x0c097b44u,0x0c097b46u,0x0c097b48u,0x0c097b4au,0x0c097b4cu,0x0c097b4eu,0x0c097b50u,0x0c097b52u,0x0c097b54u,0x0c097b56u,
0x0c097b58u,0x0c097b5au,0x0c097b5cu,0x0c097b5eu,0x0c097b60u,0x0c097b62u,0x0c097b64u,0x0c097b66u,0x0c097b68u,0x0c097b6au,0x0c097b6cu,0x0c097b6eu,0x0c097b70u,0x0c097b9cu,0x0c097b9eu,0x0c097ba0u,
0x0c097ba2u,0x0c097ba4u,0x0c097ba6u,0x0c097ba8u,0x0c097baau,0x0c097bacu,0x0c097baeu,0x0c097bb0u,0x0c097bb2u,0x0c097bb4u,0x0c097bb6u,0x0c097bb8u,0x0c097bbau,0x0c097bbcu,0x0c097bbeu,0x0c097bc0u,
0x0c097bc2u,0x0c097bc4u,0x0c097bc6u,0x0c097bc8u,0x0c097bcau,0x0c097bccu,0x0c097bceu,0x0c097bd0u,0x0c097bd2u,0x0c097bd4u,0x0c097bd6u,0x0c097bd8u,0x0c097bdau,0x0c097bdcu,0x0c097bdeu,0x0c097be0u,
0x0c097be2u,0x0c097be4u,0x0c097be6u,0x0c097be8u,0x0c097beau,0x0c097becu,0x0c097beeu,0x0c097bf0u,0x0c097bf2u,0x0c097bf4u,0x0c097bf6u,0x0c097bf8u,0x0c097bfau,0x0c097bfcu,0x0c097bfeu,0x0c097c00u,
0x0c097c02u,0x0c097c04u,0x0c097c06u,0x0c097c08u,0x0c097c0au,0x0c097c0cu,0x0c097c0eu,0x0c097c10u,0x0c097c12u,0x0c097c14u,0x0c097c16u,0x0c097c18u,0x0c097c1au,0x0c097c1cu,0x0c097c1eu,0x0c097c20u,
0x0c097c22u,0x0c097c24u,0x0c097c26u,0x0c097c28u,0x0c097c2au,0x0c097c2cu,0x0c097c2eu,0x0c097c30u,0x0c097c32u,0x0c097c34u,0x0c097c36u,0x0c097c38u,0x0c097c3au,0x0c097c3cu,0x0c097c3eu,0x0c097c40u,
0x0c097c42u,0x0c097c44u,0x0c097c46u,0x0c097c48u,0x0c097c4au,0x0c097c4cu,0x0c097c4eu,0x0c097c50u,0x0c097c52u,0x0c097c54u,0x0c097c56u,0x0c097c58u,0x0c097c5au,0x0c097c5cu,0x0c097c5eu,0x0c097c60u,
0x0c097c62u,0x0c097c64u,0x0c097c66u,0x0c097c68u,0x0c097c6au,0x0c097c6cu,0x0c097c6eu,0x0c097c70u,0x0c097c72u,0x0c097c74u,0x0c097c76u,0x0c097c78u,0x0c097c7au,0x0c097c7cu,0x0c097c7eu,0x0c097c80u,
0x0c097c82u,0x0c097c84u,0x0c097c86u,0x0c097c88u,0x0c097c8au,0x0c097c8cu,0x0c097c8eu,0x0c097c90u,0x0c097c92u,0x0c097c94u,0x0c097c96u,0x0c097c98u,0x0c097c9au,0x0c097c9cu,0x0c097c9eu,0x0c097ca0u,
0x0c097ca2u,0x0c097ca4u,0x0c097ca6u,0x0c097ca8u,0x0c097caau,0x0c097cacu,0x0c097caeu,0x0c097cb0u,0x0c097cb2u,0x0c097cb4u,0x0c097cb6u,0x0c097cb8u,0x0c097cbau,0x0c097cbcu,0x0c097cbeu,0x0c097cc0u,
0x0c097cc2u,0x0c097d18u,0x0c097d1au,0x0c097d1cu,0x0c097d1eu,0x0c097d20u,0x0c097d22u,0x0c097d24u,0x0c097d26u,0x0c097d28u,0x0c097d2au,0x0c097d2cu,0x0c097d2eu,0x0c097d30u,0x0c097d32u,0x0c097d34u,
0x0c097d36u,0x0c097d38u,0x0c097d3au,0x0c097d3cu,0x0c097d3eu,0x0c097d40u,0x0c097d42u,0x0c097d44u,0x0c097d46u,0x0c097d48u,0x0c097d4au,0x0c097d4cu,0x0c097d4eu,0x0c097d50u,0x0c097d52u,0x0c097d54u,
0x0c097d56u,0x0c097d58u,0x0c097d5au,0x0c097d5cu,0x0c097d5eu,0x0c097d60u,0x0c097d62u,0x0c097d64u,0x0c097d66u,0x0c097d68u,0x0c097d6au,0x0c097d6cu,0x0c097d6eu,0x0c097d70u,0x0c097d72u,0x0c097d74u,
0x0c097d76u,0x0c097d78u,0x0c097d7au,0x0c097d7cu,0x0c097d7eu,0x0c097d80u,0x0c097d82u,0x0c097d84u,0x0c097d86u,0x0c097d88u,0x0c097d8au,0x0c097d8cu,0x0c097d8eu,0x0c097d90u,0x0c097d92u,0x0c097d94u,
0x0c097d96u,0x0c097d98u,0x0c097d9au,0x0c097d9cu,0x0c097d9eu,0x0c097da0u,0x0c097da2u,0x0c097da4u,0x0c097da6u,0x0c097da8u,0x0c097daau,0x0c097dacu,0x0c097daeu,0x0c097db0u,0x0c097db2u,0x0c097db4u,
0x0c097db6u,0x0c097db8u,0x0c097dbau,0x0c097dbcu,0x0c097dbeu,0x0c097dc0u,0x0c097dc2u,0x0c097dc4u,0x0c097dc6u,0x0c097dc8u,0x0c097dcau,0x0c097dccu,0x0c097dceu,0x0c097dd0u,0x0c097dd2u,0x0c097dd4u,
0x0c097dd6u,0x0c097dd8u,0x0c097ddau,0x0c097ddcu,0x0c097ddeu,0x0c097de0u,0x0c097de2u,0x0c097de4u,0x0c097de6u,0x0c097de8u,0x0c097deau,0x0c097decu,0x0c097deeu,0x0c097e0cu,0x0c097e0eu,0x0c097e10u,
0x0c097e12u,0x0c097e14u,0x0c097e16u,0x0c097e18u,0x0c097e1au,0x0c097e1cu,0x0c097e1eu,0x0c097e20u,0x0c097e22u,0x0c097e24u,0x0c097e26u,0x0c097e28u,0x0c097e2au,0x0c097e2cu,0x0c097e2eu,0x0c097e30u,
0x0c097e32u,0x0c097e34u,0x0c097e36u,0x0c097e38u,0x0c097e3au,0x0c097e3cu,0x0c097e3eu,0x0c097e40u,0x0c097e42u,0x0c097e44u,0x0c097e46u,0x0c097e48u,0x0c097e4au,0x0c097e4cu,0x0c097e4eu,0x0c097e50u,
0x0c097e52u,0x0c097e54u,0x0c097e56u,0x0c097e58u,0x0c097e5au,0x0c097e5cu,0x0c097e5eu,0x0c097e60u,0x0c097e62u,0x0c097e64u,0x0c097e66u,0x0c097e68u,0x0c097e6au,0x0c097e6cu,0x0c097e6eu,0x0c097e70u,
0x0c097e72u,0x0c097e74u,0x0c097e76u,0x0c097e78u,0x0c097e7au,0x0c097e7cu,0x0c097e7eu,0x0c097e80u,0x0c097e82u,0x0c097e84u,0x0c097e86u,0x0c097e88u,0x0c097e8au,0x0c097e8cu,0x0c097e8eu,0x0c097e90u,
0x0c097e92u,0x0c097e94u,0x0c097e96u,0x0c097e98u,0x0c097e9au,0x0c097e9cu,0x0c097e9eu,0x0c097ea0u,0x0c097ea2u,0x0c097ea4u,0x0c097eb6u,0x0c097eb8u,0x0c097ebau,0x0c097ebcu,0x0c097ebeu,0x0c097ec0u,
0x0c097ec2u,0x0c097ec4u,0x0c097ec6u,0x0c097ec8u,0x0c097ecau,0x0c097eccu,0x0c097eceu,0x0c097ed0u,0x0c097ed2u,0x0c097ed4u,0x0c097ed6u,0x0c097ed8u,0x0c097edau,0x0c097edcu,0x0c097edeu,0x0c097ee0u,
0x0c097ee2u,0x0c097ee4u,0x0c097ee6u,0x0c097ee8u,0x0c097eeau,0x0c097eecu,0x0c097eeeu,0x0c097ef0u,0x0c097ef2u,0x0c097ef4u,0x0c097ef6u,0x0c097ef8u,0x0c097efau,0x0c097efcu,0x0c097efeu,0x0c097f00u,
0x0c097f02u,0x0c097f04u,0x0c097f06u,0x0c097f08u,0x0c097f0au,0x0c097f0cu,0x0c097f0eu,0x0c097f10u,0x0c097f12u,0x0c097f14u,0x0c097f16u,0x0c097f18u,0x0c097f1au,0x0c097f1cu,0x0c097f1eu,0x0c097f20u,
0x0c097f22u,0x0c097f24u,0x0c097f26u,0x0c097f28u,0x0c097f2au,0x0c097f2cu,0x0c097f2eu,0x0c097f30u,0x0c097f32u,0x0c097f34u,0x0c097f36u,0x0c097f38u,0x0c097f3au,0x0c097f3cu,0x0c097f3eu,0x0c097f40u,
0x0c097f42u,0x0c097f44u,0x0c097f46u,0x0c097f48u,0x0c097f4au,0x0c097f4cu,0x0c097f4eu,0x0c097f50u,0x0c097f52u,0x0c097f54u,0x0c097f56u,0x0c097f58u,0x0c097f5au,0x0c097f5cu,0x0c097f5eu,0x0c097f60u,
0x0c097f62u,0x0c097f64u,0x0c097f66u,0x0c097f68u,0x0c097f6au,0x0c097f6cu,0x0c097f6eu,0x0c097f70u,0x0c097f72u,0x0c097f74u,0x0c097f76u,0x0c097f78u,0x0c097f9cu,0x0c097f9eu,0x0c097fa0u,0x0c097fa2u,
0x0c097fa4u,0x0c097fa6u,0x0c097fa8u,0x0c097faau,0x0c097facu,0x0c097faeu,0x0c097fb0u,0x0c097fb2u,0x0c097fb4u,0x0c097fb6u,0x0c097fb8u,0x0c097fbau,0x0c097fbcu,0x0c097fbeu,0x0c097fc0u,0x0c097fc2u,
0x0c097fc4u,0x0c097fc6u,0x0c097fc8u,0x0c097fcau,0x0c097fccu,0x0c097fceu,0x0c097fd0u,0x0c097fd2u,0x0c097fd4u,0x0c097fd6u,0x0c097fd8u,0x0c097fdau,0x0c097fdcu,0x0c097fdeu,0x0c097fe0u,0x0c097fe2u,
0x0c097fe4u,0x0c097fe6u,0x0c097fe8u,0x0c097feau,0x0c097fecu,0x0c097feeu,0x0c097ff0u,0x0c097ff2u,0x0c097ff4u,0x0c097ff6u,0x0c097ff8u,0x0c097ffau,0x0c097ffcu,0x0c097ffeu,0x0c098000u,0x0c098002u,
0x0c098004u,0x0c098006u,0x0c098008u,0x0c09800au,0x0c09800cu,0x0c09800eu,0x0c098010u,0x0c098012u,0x0c098014u,0x0c098016u,0x0c098018u,0x0c09801au,0x0c09801cu,0x0c09801eu,0x0c098020u,0x0c098022u,
0x0c098024u,0x0c098026u,0x0c098028u,0x0c09802au,0x0c09802cu,0x0c09802eu,0x0c098030u,0x0c098032u,0x0c098034u,0x0c098036u,0x0c098038u,0x0c09803au,0x0c09803cu,0x0c09803eu,0x0c0983bcu,0x0c0983beu,
0x0c0983c0u,0x0c0983c2u,0x0c0983c4u,0x0c0983c6u,0x0c0983c8u,0x0c0983cau,0x0c0983ccu,0x0c0983ceu,0x0c0983d0u,0x0c0983d2u,0x0c0983d4u,0x0c0983d6u,0x0c0983d8u,0x0c0983dau,0x0c0983dcu,0x0c0983deu,
0x0c0983e0u,0x0c0983e2u,0x0c0983e4u,0x0c0983e6u,0x0c0983e8u,0x0c0983eau,0x0c0983ecu,0x0c0983eeu,0x0c0983f0u,0x0c0983f2u,0x0c0983f4u,0x0c0983f6u,0x0c0983f8u,0x0c0983fau,0x0c0983fcu,0x0c0983feu,
0x0c098400u,0x0c098402u,0x0c098404u,0x0c098406u,0x0c098408u,0x0c09840au,0x0c09840cu,0x0c09840eu,0x0c098410u,0x0c098412u,0x0c098414u,0x0c098416u,0x0c098418u,0x0c09841au,0x0c09841cu,0x0c09841eu,
0x0c098420u,0x0c098422u,0x0c098424u,0x0c098426u,0x0c098428u,0x0c09842au,0x0c09842cu,0x0c09842eu,0x0c098430u,0x0c098432u,0x0c09873eu,0x0c098740u,0x0c098742u,0x0c098744u,0x0c098746u,0x0c098918u,
0x0c09891au,0x0c09891cu,0x0c09891eu,0x0c098920u,0x0c098922u,0x0c098924u,0x0c098926u,0x0c098928u,0x0c09892au,0x0c09892cu,0x0c09892eu,0x0c098930u,0x0c098932u,0x0c098934u,0x0c098936u,0x0c098938u,
0x0c09893au,0x0c09893cu,0x0c09893eu,0x0c098940u,0x0c098942u,0x0c098944u,0x0c098946u,0x0c098948u,0x0c09894au,0x0c09894cu,0x0c09894eu,0x0c098950u,0x0c098952u,0x0c098954u,0x0c098956u,0x0c098958u,
0x0c09895au,0x0c09895cu,0x0c09895eu,0x0c098960u,0x0c098962u,0x0c098964u,0x0c098966u,0x0c098968u,0x0c09896au,0x0c09896cu,0x0c09896eu,0x0c098970u,0x0c098972u,0x0c098974u,0x0c098976u,0x0c098978u,
0x0c09897au,0x0c09897cu,0x0c09897eu,0x0c098980u,0x0c098982u,0x0c098984u,0x0c098986u,0x0c098988u,0x0c09898au,0x0c09898cu,0x0c09898eu,0x0c098990u,0x0c098992u,0x0c098994u,0x0c098996u,0x0c098998u,
0x0c09899au,0x0c09899cu,0x0c09899eu,0x0c0989a0u,0x0c0989a2u,0x0c0989a4u,0x0c0989a6u,0x0c0989a8u,0x0c0989aau,0x0c0989acu,0x0c0989aeu,0x0c0989b0u,0x0c0989b2u,0x0c0989b4u,0x0c0989b6u,0x0c0989b8u,
0x0c0989bau,0x0c0989bcu,0x0c0989beu,0x0c0989c0u,0x0c0989c2u,0x0c0989fcu,0x0c0989feu,0x0c098a00u,0x0c098a02u,0x0c098a04u,0x0c098a06u,0x0c098a08u,0x0c098a0au,0x0c098a0cu,0x0c098b3cu,0x0c098b3eu,
0x0c098b40u,0x0c098b42u,0x0c098b44u,0x0c098b46u,0x0c098b48u,0x0c098b4au,0x0c098b4cu,0x0c098b4eu,0x0c098b50u,0x0c098b52u,0x0c098b54u,0x0c098b56u,0x0c098b58u,0x0c098b5au,0x0c098b5cu,0x0c098b5eu,
0x0c098b60u,0x0c098b62u,0x0c098b64u,0x0c098b66u,0x0c098b68u,0x0c098b6au,0x0c098b6cu,0x0c098b6eu,0x0c098b70u,0x0c098b72u,0x0c098b74u,0x0c098b76u,0x0c098b78u,0x0c098b7au,0x0c098b7cu,0x0c098b7eu,
0x0c098b80u,0x0c098b82u,0x0c098b84u,0x0c098b86u,0x0c098b88u,0x0c098b8au,0x0c098b8cu,0x0c098b8eu,0x0c098b90u,0x0c098b92u,0x0c098b94u,0x0c098b96u,0x0c098b98u,0x0c098b9au,0x0c098b9cu,0x0c098b9eu,
0x0c098ba0u,0x0c098ba2u,0x0c098ba4u,0x0c098ba6u,0x0c098ba8u,0x0c098baau,0x0c098bacu,0x0c098baeu,0x0c098bb0u,0x0c098bb2u,0x0c098bb4u,0x0c098bb6u,0x0c098bb8u,0x0c098bbau,0x0c098bbcu,0x0c098bbeu,
0x0c098bc0u,0x0c098bc2u,0x0c098bc4u,0x0c098bc6u,0x0c098bc8u,0x0c098bcau,0x0c098c1cu,0x0c098c1eu,0x0c098c20u,0x0c098c22u,0x0c098c24u,0x0c098c26u,0x0c098c28u,0x0c098c2au,0x0c098c2cu,0x0c098c2eu,
0x0c098c30u,0x0c098c32u,0x0c098c34u,0x0c098c36u,0x0c098c38u,0x0c098c3au,0x0c098c3cu,0x0c098c3eu,0x0c098c40u,0x0c098c42u,0x0c098c44u,0x0c098c46u,0x0c098c48u,0x0c098c4au,0x0c098c4cu,0x0c098c4eu,
0x0c098c50u,0x0c098c52u,0x0c098c54u,0x0c098c56u,0x0c098c58u,0x0c098c5au,0x0c098c5cu,0x0c098c5eu,0x0c098c60u,0x0c09970au,0x0c09970cu,0x0c09970eu,0x0c099710u,0x0c099712u,0x0c099714u,0x0c099716u,
0x0c099718u,0x0c09971au,0x0c09971cu,0x0c09971eu,0x0c099720u,0x0c099722u,0x0c099724u,0x0c099726u,0x0c099728u,0x0c09972au,0x0c09972cu,0x0c09972eu,0x0c099730u,0x0c099732u,0x0c099734u,0x0c099736u,
0x0c099738u,0x0c09973au,0x0c09973cu,0x0c09973eu,0x0c099740u,0x0c099742u,0x0c099744u,0x0c099746u,0x0c099748u,0x0c09974au,0x0c09974cu,0x0c09974eu,0x0c099750u,0x0c099752u,0x0c099754u,0x0c099756u,
0x0c099758u,0x0c09975au,0x0c09975cu,0x0c09975eu,0x0c099760u,0x0c099762u,0x0c099764u,0x0c099766u,0x0c099768u,0x0c099784u,0x0c099786u,0x0c099788u,0x0c09978au,0x0c09978cu,0x0c09978eu,0x0c099790u,
0x0c099792u,0x0c099794u,0x0c099796u,0x0c099798u,0x0c09979au,0x0c09979cu,0x0c09979eu,0x0c0997a0u,0x0c0997a2u,0x0c0997a4u,0x0c0997a6u,0x0c0997a8u,0x0c0997aau,0x0c0997acu,0x0c0997aeu,0x0c0997b0u,
0x0c0997b2u,0x0c0997b4u,0x0c0997b6u,0x0c0997b8u,0x0c0997bau,0x0c0997bcu,0x0c0997beu,0x0c0997c0u,0x0c0997c2u,0x0c0997c4u,0x0c0997c6u,0x0c0997c8u,0x0c0997cau,0x0c0997ccu,0x0c0997ceu,0x0c0997d0u,
0x0c0997d2u,0x0c0997d4u,0x0c0997d6u,0x0c0997d8u,0x0c0997dau,0x0c0997dcu,0x0c0997deu,0x0c0997e0u,0x0c0997e2u,0x0c0997e4u,0x0c0997e6u,0x0c0997e8u,0x0c0997eau,0x0c0997ecu,0x0c0997eeu,0x0c0997f0u,
0x0c0997f2u,0x0c0997f4u,0x0c0997f6u,0x0c0997f8u,0x0c0997fau,0x0c0997fcu,0x0c0997feu,0x0c099800u,0x0c099802u,0x0c099804u,0x0c099806u,0x0c099808u,0x0c09980au,0x0c09980cu,0x0c09980eu,0x0c099810u,
0x0c099812u,0x0c099814u,0x0c099816u,0x0c099818u,0x0c09981au,0x0c09981cu,0x0c09981eu,0x0c099820u,0x0c099822u,0x0c099824u,0x0c099826u,0x0c099828u,0x0c09982au,0x0c09982cu,0x0c09982eu,0x0c099830u,
0x0c099832u,0x0c099834u,0x0c099836u,0x0c099838u,0x0c09983au,0x0c09983cu,0x0c09983eu,0x0c099840u,0x0c099842u,0x0c099844u,0x0c099846u,0x0c099848u,0x0c09984au,0x0c09984cu,0x0c09984eu,0x0c099850u,
0x0c099852u,0x0c099854u,0x0c099856u,0x0c099858u,0x0c09985au,0x0c09985cu,0x0c09985eu,0x0c099860u,0x0c099862u,0x0c099864u,0x0c099866u,0x0c099868u,0x0c09986au,0x0c09986cu,0x0c09986eu,0x0c099870u,
0x0c099872u,0x0c099874u,0x0c099876u,0x0c099878u,0x0c09987au,0x0c09987cu,0x0c09987eu,0x0c099880u,0x0c099882u,0x0c099884u,0x0c099886u,0x0c099888u,0x0c09988au,0x0c09988cu,0x0c09988eu,0x0c099890u,
0x0c099892u,0x0c099894u,0x0c099896u,0x0c099898u,0x0c09989au,0x0c09989cu,0x0c09989eu,0x0c0998a0u,0x0c0998a2u,0x0c0998a4u,0x0c0998a6u,0x0c0998a8u,0x0c0998aau,0x0c0998acu,0x0c0998aeu,0x0c0998b0u,
0x0c0998b2u,0x0c0998b4u,0x0c0998b6u,0x0c0998b8u,0x0c0998bau,0x0c0998bcu,0x0c0998beu,0x0c0998c0u,0x0c0998c2u,0x0c0998c4u,0x0c0998c6u,0x0c0998c8u,0x0c0998cau,0x0c099910u,0x0c099912u,0x0c099914u,
0x0c099916u,0x0c099918u,0x0c09991au,0x0c09991cu,0x0c09991eu,0x0c099920u,0x0c099922u,0x0c099924u,0x0c099926u,0x0c099928u,0x0c09992au,0x0c09992cu,0x0c09992eu,0x0c099930u,0x0c099932u,0x0c099934u,
0x0c099936u,0x0c099938u,0x0c09993au,0x0c09993cu,0x0c09993eu,0x0c099940u,0x0c099942u,0x0c099944u,0x0c099946u,0x0c099948u,0x0c09994au,0x0c09994cu,0x0c09994eu,0x0c099950u,0x0c099952u,0x0c099954u,
0x0c099956u,0x0c099958u,0x0c09995au,0x0c09995cu,0x0c09995eu,0x0c099960u,0x0c099962u,0x0c099964u,0x0c099966u,0x0c099968u,0x0c09996au,0x0c09996cu,0x0c09996eu,0x0c099970u,0x0c099972u,0x0c099974u,
0x0c099976u,0x0c099978u,0x0c09997au,0x0c09997cu,0x0c09997eu,0x0c099980u,0x0c099982u,0x0c099984u,0x0c099986u,0x0c099988u,0x0c09998au,0x0c09998cu,0x0c09998eu,0x0c099990u,0x0c099992u,0x0c099994u,
0x0c099996u,0x0c099998u,0x0c09999au,0x0c09999cu,0x0c09999eu,0x0c0999a0u,0x0c0999a2u,0x0c0999a4u,0x0c0999a6u,0x0c0999a8u,0x0c0999aau,0x0c0999acu,0x0c0999aeu,0x0c0999b0u,0x0c0999b2u,0x0c0999b4u,
0x0c0999b6u,0x0c0999b8u,0x0c0999bau,0x0c0999bcu,0x0c0999beu,0x0c0999c0u,0x0c0999c2u,0x0c0999c4u,0x0c0999c6u,0x0c0999c8u,0x0c0999cau,0x0c0999ccu,0x0c0999ceu,0x0c0999d0u,0x0c0999d2u,0x0c0999d4u,
0x0c0999d6u,0x0c0999d8u,0x0c0999dau,0x0c0999dcu,0x0c0999deu,0x0c0999e0u,0x0c0999e2u,0x0c0999e4u,0x0c0999e6u,0x0c0999e8u,0x0c0999eau,0x0c0999ecu,0x0c0999eeu,0x0c0999f0u,0x0c0999f2u,0x0c0999f4u,
0x0c0999f6u,0x0c0999f8u,0x0c0999fau,0x0c099a18u,0x0c099a1au,0x0c099a1cu,0x0c099a1eu,0x0c099a20u,0x0c099a22u,0x0c099a24u,0x0c099a26u,0x0c099a28u,0x0c099a2au,0x0c099a2cu,0x0c099a2eu,0x0c099a30u,
0x0c099a32u,0x0c099a34u,0x0c099a36u,0x0c099a38u,0x0c099a3au,0x0c099a3cu,0x0c099a3eu,0x0c099a40u,0x0c099a42u,0x0c099a44u,0x0c099a46u,0x0c099a48u,0x0c099a4au,0x0c099a4cu,0x0c099a4eu,0x0c099a50u,
0x0c099a52u,0x0c099a54u,0x0c099a56u,0x0c099a58u,0x0c099a5au,0x0c099a5cu,0x0c099a5eu,0x0c099a60u,0x0c099a62u,0x0c099a64u,0x0c099a66u,0x0c099a68u,0x0c099a6au,0x0c099a6cu,0x0c099a6eu,0x0c099a70u,
0x0c099a72u,0x0c099a74u,0x0c099a76u,0x0c099a78u,0x0c099a7au,0x0c099a7cu,0x0c099a7eu,0x0c099a80u,0x0c099a82u,0x0c099a84u,0x0c099a86u,0x0c099a88u,0x0c099a8au,0x0c099a8cu,0x0c099a8eu,0x0c099a90u,
0x0c099a92u,0x0c099a94u,0x0c099a96u,0x0c099a98u,0x0c099a9au,0x0c099a9cu,0x0c099a9eu,0x0c099aa0u,0x0c099aa2u,0x0c099aa4u,0x0c099aa6u,0x0c099aa8u,0x0c099aaau,0x0c099aacu,0x0c099aaeu,0x0c099ab0u,
0x0c099ab2u,0x0c099ab4u,0x0c099ab6u,0x0c099ab8u,0x0c099abau,0x0c099abcu,0x0c099abeu,0x0c099ac0u,0x0c099ac2u,0x0c099ac4u,0x0c099ac6u,0x0c099ac8u,0x0c099acau,0x0c099accu,0x0c099aceu,0x0c099ad0u,
0x0c099ad2u,0x0c099ad4u,0x0c099ad6u,0x0c099ad8u,0x0c099adau,0x0c099adcu,0x0c099adeu,0x0c099ae0u,0x0c099ae2u,0x0c099ae4u,0x0c099ae6u,0x0c099ae8u,0x0c099aeau,0x0c099aecu,0x0c099aeeu,0x0c099af0u,
0x0c099af2u,0x0c099af4u,0x0c099af6u,0x0c099af8u,0x0c099afau,0x0c099afcu,0x0c099afeu,0x0c099b00u,0x0c099b02u,0x0c099b04u,0x0c099b06u,0x0c099b08u,0x0c099b0au,0x0c099b0cu,0x0c099b0eu,0x0c099b10u,
0x0c099b12u,0x0c099b14u,0x0c099b16u,0x0c099b18u,0x0c099b1au,0x0c099b1cu,0x0c099b1eu,0x0c099b20u,0x0c099b22u,0x0c099b24u,0x0c099b26u,0x0c099b28u,0x0c099b2au,0x0c099b2cu,0x0c099b2eu,0x0c099b30u,
0x0c099b32u,0x0c099b34u,0x0c099b36u,0x0c099b38u,0x0c099b3au,0x0c099b3cu,0x0c099b3eu,0x0c099b40u,0x0c099b42u,0x0c099b44u,0x0c099b46u,0x0c099b48u,0x0c099b4au,0x0c099b4cu,0x0c099b4eu,0x0c099b50u,
0x0c099b52u,0x0c099b54u,0x0c099b56u,0x0c099b58u,0x0c099b5au,0x0c099b5cu,0x0c099b5eu,0x0c099b60u,0x0c099b62u,0x0c099b64u,0x0c099b66u,0x0c099b68u,0x0c099b6au,0x0c099b6cu,0x0c099b6eu,0x0c099b70u,
0x0c099b9cu,0x0c099b9eu,0x0c099ba0u,0x0c099ba2u,0x0c099ba4u,0x0c099ba6u,0x0c099ba8u,0x0c099baau,0x0c099bacu,0x0c099baeu,0x0c099bb0u,0x0c099bb2u,0x0c099bb4u,0x0c099bb6u,0x0c099bb8u,0x0c099bbau,
0x0c099bbcu,0x0c099bbeu,0x0c099bc0u,0x0c099bc2u,0x0c099bc4u,0x0c099bc6u,0x0c099bc8u,0x0c099bcau,0x0c099bccu,0x0c099bceu,0x0c099bd0u,0x0c099bd2u,0x0c099bd4u,0x0c099bd6u,0x0c099bd8u,0x0c099bdau,
0x0c099bdcu,0x0c099bdeu,0x0c099be0u,0x0c099be2u,0x0c099be4u,0x0c099be6u,0x0c099be8u,0x0c099beau,0x0c099becu,0x0c099beeu,0x0c099bf0u,0x0c099bf2u,0x0c099bf4u,0x0c099bf6u,0x0c099bf8u,0x0c099bfau,
0x0c099bfcu,0x0c099bfeu,0x0c099c00u,0x0c099c02u,0x0c099c04u,0x0c099c06u,0x0c099c08u,0x0c099c0au,0x0c099c0cu,0x0c099c0eu,0x0c099c10u,0x0c099c12u,0x0c099c14u,0x0c099c16u,0x0c099c18u,0x0c099c1au,
0x0c099c1cu,0x0c099c1eu,0x0c099c20u,0x0c099c22u,0x0c099c24u,0x0c099c26u,0x0c099c28u,0x0c099c2au,0x0c099c2cu,0x0c099c2eu,0x0c099c30u,0x0c099c32u,0x0c099c34u,0x0c099c36u,0x0c099c38u,0x0c099c3au,
0x0c099c3cu,0x0c099c3eu,0x0c099c40u,0x0c099c42u,0x0c099c44u,0x0c099c46u,0x0c099c48u,0x0c099c4au,0x0c099c4cu,0x0c099c4eu,0x0c099c50u,0x0c099c52u,0x0c099c54u,0x0c099c56u,0x0c099c58u,0x0c099c5au,
0x0c099c5cu,0x0c099c5eu,0x0c099c60u,0x0c099c62u,0x0c099c64u,0x0c099c66u,0x0c099c68u,0x0c099c6au,0x0c099c6cu,0x0c099c6eu,0x0c099c70u,0x0c099c72u,0x0c099c74u,0x0c099c76u,0x0c099c78u,0x0c099c7au,
0x0c099c7cu,0x0c099c7eu,0x0c099c80u,0x0c099c82u,0x0c099cb0u,0x0c099cb2u,0x0c099cb4u,0x0c099cb6u,0x0c099cb8u,0x0c099cbau,0x0c099cbcu,0x0c099cbeu,0x0c099cc0u,0x0c099cc2u,0x0c099cc4u,0x0c099cc6u,
0x0c099cc8u,0x0c099ccau,0x0c099cccu,0x0c099cceu,0x0c099cd0u,0x0c099cd2u,0x0c099cd4u,0x0c099cd6u,0x0c099cd8u,0x0c099cdau,0x0c099cdcu,0x0c099cdeu,0x0c099ce0u,0x0c099ce2u,0x0c099ce4u,0x0c099ce6u,
0x0c099ce8u,0x0c099ceau,0x0c099cecu,0x0c099ceeu,0x0c099cf0u,0x0c099cf2u,0x0c099cf4u,0x0c099cf6u,0x0c099cf8u,0x0c099cfau,0x0c099cfcu,0x0c099cfeu,0x0c099d00u,0x0c099d02u,0x0c099d04u,0x0c099d06u,
0x0c099d08u,0x0c099d0au,0x0c099d0cu,0x0c099d0eu,0x0c099d10u,0x0c099d12u,0x0c099d14u,0x0c099d16u,0x0c099d18u,0x0c099d1au,0x0c099d1cu,0x0c099d1eu,0x0c099d20u,0x0c099d22u,0x0c099d24u,0x0c099d26u,
0x0c099d28u,0x0c099d2au,0x0c099d2cu,0x0c099d2eu,0x0c099d30u,0x0c099d32u,0x0c099d34u,0x0c099d36u,0x0c099d38u,0x0c099d3au,0x0c099d3cu,0x0c099d3eu,0x0c099d40u,0x0c099d42u,0x0c099d44u,0x0c099d46u,
0x0c099d48u,0x0c099d4au,0x0c099d4cu,0x0c099d4eu,0x0c099d50u,0x0c099d52u,0x0c099d54u,0x0c099d56u,0x0c099d58u,0x0c099d5au,0x0c099d5cu,0x0c099d5eu,0x0c099d60u,0x0c0c61a8u,0x0c0c61aau,0x0c0c61acu,
0x0c0c61aeu,0x0c0c61b0u,0x0c0c61b2u,0x0c0c61b4u,0x0c0c61b6u,0x0c0c61b8u,0x0c0c61bau,0x0c0c61bcu,0x0c0c61beu,0x0c0c61c0u,0x0c0c61c2u,0x0c0c61c4u,0x0c0c61c6u,0x0c0c61c8u,0x0c0c61cau,0x0c0c61ccu,
0x0c0c61ceu,0x0c0c61d0u,0x0c0c61d2u,0x0c0c61d4u,0x0c0c61d6u,0x0c0c61d8u,0x0c0c61dau,0x0c0c61dcu,0x0c0c61deu,0x0c0c61e0u,0x0c0c61e2u,0x0c0c61e4u,0x0c0c61e6u,0x0c0c61e8u,0x0c0c61eau,0x0c0c61ecu,
0x0c0c61eeu,0x0c0c61f0u,0x0c0c61f2u,0x0c0c61f4u,0x0c0c61f6u,0x0c0c61f8u,0x0c0c61fau,0x0c0c61fcu,0x0c0c61feu,0x0c0c6200u,0x0c0c6202u,0x0c0c6204u,0x0c0c623eu,0x0c0c6240u,0x0c0c99cau,0x0c0c99ccu,
0x0c0c99ceu,0x0c0c99d0u,0x0c0c99d2u,0x0c0c99d4u,0x0c0c99d6u,0x0c0c99d8u,0x0c0c99dau,0x0c0c99dcu,0x0c0c99deu,0x0c0c99e0u,0x0c0c99e2u,0x0c0c99e4u,0x0c0c99e6u,0x0c0c99e8u,0x0c0c99eau,0x0c0c99ecu,
0x0c0c99eeu,0x0c0c99f0u,0x0c0c99f2u,0x0c0c99f4u,0x0c0c99f6u,0x0c0c99f8u,0x0c0c99fau,0x0c0c99fcu,0x0c0c9a7au,0x0c0c9a7cu,0x0c0c9a7eu,0x0c0c9a80u,0x0c0c9a82u,0x0c0c9a84u,0x0c0c9a86u,0x0c0c9a88u,
0x0c0c9a8au,0x0c0c9a8cu,0x0c0c9a8eu,0x0c0c9a90u,0x0c0c9a92u,0x0c0c9a94u,0x0c0c9a96u,0x0c0c9a98u,0x0c0c9a9au,0x0c0c9a9cu,0x0c0c9ad0u,0x0c0c9ad2u,0x0c0c9ad4u,0x0c0c9ad6u,0x0c0c9ad8u,0x0c0c9adau,
0x0c0c9adcu,0x0c0c9adeu,0x0c0c9ae0u,0x0c0c9ae2u,0x0c0c9ae4u,0x0c0c9ae6u,0x0c0c9ae8u,0x0c0c9aeau,0x0c0c9aecu,0x0c0c9aeeu,0x0c0c9af0u,0x0c0c9af2u,0x0c0c9af4u,0x0c0c9af6u,0x0c0c9af8u,0x0c0c9afau,
0x0c0c9afcu,0x0c0c9afeu,0x0c0c9b00u,0x0c0c9b02u,0x0c0c9b04u,0x0c0c9b06u,0x0c0c9b08u,0x0c0c9b0au,0x0c0c9b0cu,0x0c0c9b0eu,0x0c0c9b10u,0x0c0c9b12u,0x0c0c9b14u,0x0c0c9b16u,0x0c0c9b18u,0x0c0c9b1au,
0x0c0c9b1cu,0x0c0c9b1eu,0x0c0c9b20u,0x0c0c9b22u,0x0c0c9b24u,0x0c0c9b26u,0x0c0c9b28u,0x0c0c9b2au,0x0c0c9b2cu,0x0c0ca05cu,0x0c0ca05eu,0x0c0ca060u,0x0c0ca062u,0x0c0ca064u,0x0c0ca066u,0x0c0ca068u,
0x0c0ca06au,0x0c0ca06cu,
};
int vf3_9970a_adapter_contains(uint32_t pc) {
pc&=0x1fffffffu; unsigned lo=0,hi=sizeof(owned_pcs)/sizeof(owned_pcs[0]);
while(lo<hi) { unsigned mid=lo+(hi-lo)/2; if(owned_pcs[mid]<pc) lo=mid+1; else hi=mid; }
return lo<sizeof(owned_pcs)/sizeof(owned_pcs[0]) && owned_pcs[lo]==pc;
}
