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
int vf3_away_batch13_adapter_10(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c084a96u: goto P_0c084a96;
case 0x0c084a98u: goto P_0c084a98;
case 0x0c084a9au: goto P_0c084a9a;
case 0x0c084a9cu: goto P_0c084a9c;
case 0x0c084a9eu: goto P_0c084a9e;
case 0x0c084aa0u: goto P_0c084aa0;
case 0x0c084aa2u: goto P_0c084aa2;
case 0x0c084aa4u: goto P_0c084aa4;
case 0x0c084aa6u: goto P_0c084aa6;
case 0x0c084aa8u: goto P_0c084aa8;
case 0x0c084aaau: goto P_0c084aaa;
case 0x0c084aacu: goto P_0c084aac;
case 0x0c084aaeu: goto P_0c084aae;
case 0x0c084ab0u: goto P_0c084ab0;
case 0x0c084ab2u: goto P_0c084ab2;
case 0x0c084ab4u: goto P_0c084ab4;
case 0x0c084ab6u: goto P_0c084ab6;
case 0x0c084ab8u: goto P_0c084ab8;
case 0x0c084abau: goto P_0c084aba;
case 0x0c084abcu: goto P_0c084abc;
case 0x0c084abeu: goto P_0c084abe;
case 0x0c084ac0u: goto P_0c084ac0;
case 0x0c084ac2u: goto P_0c084ac2;
case 0x0c084ac4u: goto P_0c084ac4;
case 0x0c084ac6u: goto P_0c084ac6;
case 0x0c084ac8u: goto P_0c084ac8;
case 0x0c084acau: goto P_0c084aca;
case 0x0c084accu: goto P_0c084acc;
case 0x0c084aceu: goto P_0c084ace;
case 0x0c084ad0u: goto P_0c084ad0;
case 0x0c084ad2u: goto P_0c084ad2;
case 0x0c084ad4u: goto P_0c084ad4;
case 0x0c084ad6u: goto P_0c084ad6;
case 0x0c084ad8u: goto P_0c084ad8;
case 0x0c084adau: goto P_0c084ada;
case 0x0c084adcu: goto P_0c084adc;
case 0x0c084b00u: goto P_0c084b00;
case 0x0c084b02u: goto P_0c084b02;
case 0x0c084b04u: goto P_0c084b04;
case 0x0c084b06u: goto P_0c084b06;
case 0x0c084b08u: goto P_0c084b08;
case 0x0c084b0au: goto P_0c084b0a;
case 0x0c084b0cu: goto P_0c084b0c;
case 0x0c084b0eu: goto P_0c084b0e;
case 0x0c084b10u: goto P_0c084b10;
case 0x0c084b12u: goto P_0c084b12;
case 0x0c084b14u: goto P_0c084b14;
case 0x0c084b16u: goto P_0c084b16;
case 0x0c084b18u: goto P_0c084b18;
case 0x0c084b1au: goto P_0c084b1a;
case 0x0c084b1cu: goto P_0c084b1c;
case 0x0c084b1eu: goto P_0c084b1e;
case 0x0c084b20u: goto P_0c084b20;
case 0x0c084b22u: goto P_0c084b22;
case 0x0c084b24u: goto P_0c084b24;
case 0x0c084b26u: goto P_0c084b26;
case 0x0c084b28u: goto P_0c084b28;
case 0x0c084b2au: goto P_0c084b2a;
case 0x0c084b2cu: goto P_0c084b2c;
case 0x0c084b2eu: goto P_0c084b2e;
case 0x0c084b30u: goto P_0c084b30;
case 0x0c084b32u: goto P_0c084b32;
case 0x0c084b34u: goto P_0c084b34;
case 0x0c084b36u: goto P_0c084b36;
case 0x0c084b38u: goto P_0c084b38;
case 0x0c084b3au: goto P_0c084b3a;
case 0x0c084b3cu: goto P_0c084b3c;
case 0x0c084b3eu: goto P_0c084b3e;
case 0x0c084b40u: goto P_0c084b40;
case 0x0c084b42u: goto P_0c084b42;
case 0x0c084b44u: goto P_0c084b44;
case 0x0c084b46u: goto P_0c084b46;
case 0x0c084b48u: goto P_0c084b48;
case 0x0c084b4au: goto P_0c084b4a;
case 0x0c084b4cu: goto P_0c084b4c;
case 0x0c084b4eu: goto P_0c084b4e;
case 0x0c084b50u: goto P_0c084b50;
case 0x0c084b52u: goto P_0c084b52;
case 0x0c084b54u: goto P_0c084b54;
case 0x0c084b56u: goto P_0c084b56;
case 0x0c084b58u: goto P_0c084b58;
case 0x0c084b5au: goto P_0c084b5a;
case 0x0c084b5cu: goto P_0c084b5c;
case 0x0c084b5eu: goto P_0c084b5e;
case 0x0c084b60u: goto P_0c084b60;
case 0x0c084b62u: goto P_0c084b62;
case 0x0c084b64u: goto P_0c084b64;
case 0x0c084b66u: goto P_0c084b66;
case 0x0c084b68u: goto P_0c084b68;
case 0x0c084b6au: goto P_0c084b6a;
case 0x0c084b6cu: goto P_0c084b6c;
case 0x0c084b6eu: goto P_0c084b6e;
case 0x0c084b70u: goto P_0c084b70;
case 0x0c084b72u: goto P_0c084b72;
case 0x0c084b74u: goto P_0c084b74;
case 0x0c084b76u: goto P_0c084b76;
case 0x0c084b78u: goto P_0c084b78;
case 0x0c084b7au: goto P_0c084b7a;
case 0x0c084b7cu: goto P_0c084b7c;
case 0x0c084b7eu: goto P_0c084b7e;
case 0x0c084b80u: goto P_0c084b80;
case 0x0c084b82u: goto P_0c084b82;
case 0x0c084b84u: goto P_0c084b84;
case 0x0c084b86u: goto P_0c084b86;
case 0x0c084b88u: goto P_0c084b88;
case 0x0c084b8au: goto P_0c084b8a;
case 0x0c084b8cu: goto P_0c084b8c;
case 0x0c084b8eu: goto P_0c084b8e;
case 0x0c084b90u: goto P_0c084b90;
case 0x0c084b92u: goto P_0c084b92;
case 0x0c084b94u: goto P_0c084b94;
case 0x0c084b96u: goto P_0c084b96;
case 0x0c084b98u: goto P_0c084b98;
case 0x0c084b9au: goto P_0c084b9a;
case 0x0c084b9cu: goto P_0c084b9c;
case 0x0c084b9eu: goto P_0c084b9e;
case 0x0c084ba0u: goto P_0c084ba0;
case 0x0c084ba2u: goto P_0c084ba2;
case 0x0c084ba4u: goto P_0c084ba4;
case 0x0c084ba6u: goto P_0c084ba6;
case 0x0c084ba8u: goto P_0c084ba8;
case 0x0c084baau: goto P_0c084baa;
case 0x0c084bacu: goto P_0c084bac;
case 0x0c084baeu: goto P_0c084bae;
case 0x0c084bb0u: goto P_0c084bb0;
case 0x0c084bb2u: goto P_0c084bb2;
case 0x0c084bb4u: goto P_0c084bb4;
case 0x0c084bb6u: goto P_0c084bb6;
case 0x0c084bb8u: goto P_0c084bb8;
case 0x0c084bbau: goto P_0c084bba;
case 0x0c084bbcu: goto P_0c084bbc;
case 0x0c084bbeu: goto P_0c084bbe;
case 0x0c084bc0u: goto P_0c084bc0;
case 0x0c084bc2u: goto P_0c084bc2;
case 0x0c084bc4u: goto P_0c084bc4;
case 0x0c084bc6u: goto P_0c084bc6;
case 0x0c084bc8u: goto P_0c084bc8;
case 0x0c084bcau: goto P_0c084bca;
case 0x0c084bccu: goto P_0c084bcc;
case 0x0c084bceu: goto P_0c084bce;
case 0x0c084bd0u: goto P_0c084bd0;
case 0x0c084bd2u: goto P_0c084bd2;
case 0x0c084bd4u: goto P_0c084bd4;
case 0x0c084bd6u: goto P_0c084bd6;
case 0x0c084bd8u: goto P_0c084bd8;
case 0x0c084bdau: goto P_0c084bda;
case 0x0c084bdcu: goto P_0c084bdc;
case 0x0c084bdeu: goto P_0c084bde;
case 0x0c084be0u: goto P_0c084be0;
case 0x0c084be2u: goto P_0c084be2;
case 0x0c084be4u: goto P_0c084be4;
case 0x0c084be6u: goto P_0c084be6;
case 0x0c084be8u: goto P_0c084be8;
case 0x0c084beau: goto P_0c084bea;
case 0x0c084becu: goto P_0c084bec;
case 0x0c084beeu: goto P_0c084bee;
case 0x0c084bf0u: goto P_0c084bf0;
case 0x0c084bf2u: goto P_0c084bf2;
case 0x0c084bf4u: goto P_0c084bf4;
case 0x0c084bf6u: goto P_0c084bf6;
case 0x0c084bf8u: goto P_0c084bf8;
case 0x0c084bfau: goto P_0c084bfa;
case 0x0c084bfcu: goto P_0c084bfc;
case 0x0c084bfeu: goto P_0c084bfe;
case 0x0c084c00u: goto P_0c084c00;
case 0x0c084c02u: goto P_0c084c02;
case 0x0c084c04u: goto P_0c084c04;
case 0x0c084c06u: goto P_0c084c06;
case 0x0c084c08u: goto P_0c084c08;
case 0x0c084c0au: goto P_0c084c0a;
case 0x0c084c0cu: goto P_0c084c0c;
case 0x0c084c0eu: goto P_0c084c0e;
case 0x0c084c10u: goto P_0c084c10;
case 0x0c084c12u: goto P_0c084c12;
case 0x0c084c14u: goto P_0c084c14;
case 0x0c084c16u: goto P_0c084c16;
case 0x0c084c18u: goto P_0c084c18;
case 0x0c084c1au: goto P_0c084c1a;
case 0x0c084c1cu: goto P_0c084c1c;
case 0x0c084c1eu: goto P_0c084c1e;
case 0x0c084c20u: goto P_0c084c20;
case 0x0c084c22u: goto P_0c084c22;
case 0x0c084c24u: goto P_0c084c24;
case 0x0c084c26u: goto P_0c084c26;
case 0x0c084c28u: goto P_0c084c28;
case 0x0c084c48u: goto P_0c084c48;
case 0x0c084c4au: goto P_0c084c4a;
case 0x0c084c4cu: goto P_0c084c4c;
case 0x0c084c4eu: goto P_0c084c4e;
case 0x0c084c50u: goto P_0c084c50;
case 0x0c084c52u: goto P_0c084c52;
case 0x0c084c54u: goto P_0c084c54;
case 0x0c084c56u: goto P_0c084c56;
case 0x0c084c58u: goto P_0c084c58;
case 0x0c084c5au: goto P_0c084c5a;
case 0x0c084c5cu: goto P_0c084c5c;
case 0x0c084c5eu: goto P_0c084c5e;
case 0x0c084c60u: goto P_0c084c60;
case 0x0c084c62u: goto P_0c084c62;
case 0x0c084c64u: goto P_0c084c64;
case 0x0c084c66u: goto P_0c084c66;
case 0x0c084c68u: goto P_0c084c68;
case 0x0c084c6au: goto P_0c084c6a;
case 0x0c084c6cu: goto P_0c084c6c;
case 0x0c084c6eu: goto P_0c084c6e;
case 0x0c084c70u: goto P_0c084c70;
case 0x0c084c72u: goto P_0c084c72;
case 0x0c084c74u: goto P_0c084c74;
case 0x0c084c76u: goto P_0c084c76;
case 0x0c084c78u: goto P_0c084c78;
case 0x0c084c7au: goto P_0c084c7a;
case 0x0c084c7cu: goto P_0c084c7c;
case 0x0c084c7eu: goto P_0c084c7e;
case 0x0c084c80u: goto P_0c084c80;
case 0x0c084c82u: goto P_0c084c82;
case 0x0c084c84u: goto P_0c084c84;
case 0x0c084c86u: goto P_0c084c86;
case 0x0c084c88u: goto P_0c084c88;
case 0x0c084c8au: goto P_0c084c8a;
case 0x0c084c8cu: goto P_0c084c8c;
case 0x0c084c8eu: goto P_0c084c8e;
case 0x0c084c90u: goto P_0c084c90;
case 0x0c084c92u: goto P_0c084c92;
case 0x0c084c94u: goto P_0c084c94;
case 0x0c084c96u: goto P_0c084c96;
case 0x0c084c98u: goto P_0c084c98;
case 0x0c084c9au: goto P_0c084c9a;
case 0x0c084c9cu: goto P_0c084c9c;
case 0x0c084c9eu: goto P_0c084c9e;
case 0x0c084ca0u: goto P_0c084ca0;
case 0x0c084ca2u: goto P_0c084ca2;
case 0x0c084ca4u: goto P_0c084ca4;
case 0x0c084ca6u: goto P_0c084ca6;
case 0x0c084ca8u: goto P_0c084ca8;
case 0x0c084caau: goto P_0c084caa;
case 0x0c084cacu: goto P_0c084cac;
case 0x0c084caeu: goto P_0c084cae;
case 0x0c084cb0u: goto P_0c084cb0;
case 0x0c084cb2u: goto P_0c084cb2;
case 0x0c084cb4u: goto P_0c084cb4;
case 0x0c084cb6u: goto P_0c084cb6;
case 0x0c084cb8u: goto P_0c084cb8;
case 0x0c084cbau: goto P_0c084cba;
case 0x0c084cbcu: goto P_0c084cbc;
case 0x0c084cbeu: goto P_0c084cbe;
case 0x0c084cc0u: goto P_0c084cc0;
case 0x0c084cc2u: goto P_0c084cc2;
case 0x0c084cc4u: goto P_0c084cc4;
case 0x0c084cc6u: goto P_0c084cc6;
case 0x0c084cc8u: goto P_0c084cc8;
case 0x0c084ccau: goto P_0c084cca;
case 0x0c084cccu: goto P_0c084ccc;
case 0x0c084cceu: goto P_0c084cce;
case 0x0c084cd0u: goto P_0c084cd0;
case 0x0c084cd2u: goto P_0c084cd2;
case 0x0c084cd4u: goto P_0c084cd4;
case 0x0c084cd6u: goto P_0c084cd6;
case 0x0c084cd8u: goto P_0c084cd8;
case 0x0c084cdau: goto P_0c084cda;
case 0x0c084cdcu: goto P_0c084cdc;
case 0x0c084cdeu: goto P_0c084cde;
case 0x0c084ce0u: goto P_0c084ce0;
case 0x0c084ce2u: goto P_0c084ce2;
case 0x0c084ce4u: goto P_0c084ce4;
case 0x0c084ce6u: goto P_0c084ce6;
case 0x0c084ce8u: goto P_0c084ce8;
case 0x0c084ceau: goto P_0c084cea;
case 0x0c084cecu: goto P_0c084cec;
case 0x0c084ceeu: goto P_0c084cee;
case 0x0c084cf0u: goto P_0c084cf0;
case 0x0c084cf2u: goto P_0c084cf2;
case 0x0c084cf4u: goto P_0c084cf4;
case 0x0c084cf6u: goto P_0c084cf6;
case 0x0c084cf8u: goto P_0c084cf8;
case 0x0c084cfau: goto P_0c084cfa;
case 0x0c084cfcu: goto P_0c084cfc;
case 0x0c084cfeu: goto P_0c084cfe;
case 0x0c084d00u: goto P_0c084d00;
case 0x0c084d02u: goto P_0c084d02;
case 0x0c084d04u: goto P_0c084d04;
case 0x0c084d06u: goto P_0c084d06;
case 0x0c084d08u: goto P_0c084d08;
case 0x0c084d0au: goto P_0c084d0a;
case 0x0c084d0cu: goto P_0c084d0c;
case 0x0c084d0eu: goto P_0c084d0e;
case 0x0c084d10u: goto P_0c084d10;
case 0x0c084d12u: goto P_0c084d12;
case 0x0c084d4cu: goto P_0c084d4c;
case 0x0c084d4eu: goto P_0c084d4e;
case 0x0c084d50u: goto P_0c084d50;
case 0x0c084d52u: goto P_0c084d52;
case 0x0c084d54u: goto P_0c084d54;
case 0x0c084d56u: goto P_0c084d56;
case 0x0c084d58u: goto P_0c084d58;
case 0x0c084d5au: goto P_0c084d5a;
case 0x0c084d5cu: goto P_0c084d5c;
case 0x0c084d5eu: goto P_0c084d5e;
case 0x0c084d60u: goto P_0c084d60;
case 0x0c084d62u: goto P_0c084d62;
case 0x0c084d64u: goto P_0c084d64;
case 0x0c084d66u: goto P_0c084d66;
case 0x0c084d68u: goto P_0c084d68;
case 0x0c084d6au: goto P_0c084d6a;
case 0x0c084d6cu: goto P_0c084d6c;
case 0x0c084d6eu: goto P_0c084d6e;
case 0x0c084d70u: goto P_0c084d70;
case 0x0c084d72u: goto P_0c084d72;
case 0x0c084d74u: goto P_0c084d74;
case 0x0c084d76u: goto P_0c084d76;
case 0x0c084d78u: goto P_0c084d78;
case 0x0c084d7au: goto P_0c084d7a;
case 0x0c084d7cu: goto P_0c084d7c;
case 0x0c084d7eu: goto P_0c084d7e;
case 0x0c084d80u: goto P_0c084d80;
case 0x0c084d82u: goto P_0c084d82;
case 0x0c084d84u: goto P_0c084d84;
case 0x0c084d86u: goto P_0c084d86;
case 0x0c084d88u: goto P_0c084d88;
case 0x0c084d8au: goto P_0c084d8a;
case 0x0c084d8cu: goto P_0c084d8c;
case 0x0c084d8eu: goto P_0c084d8e;
case 0x0c084d90u: goto P_0c084d90;
case 0x0c084d92u: goto P_0c084d92;
case 0x0c084d94u: goto P_0c084d94;
case 0x0c084d96u: goto P_0c084d96;
case 0x0c084d98u: goto P_0c084d98;
case 0x0c084d9au: goto P_0c084d9a;
case 0x0c084d9cu: goto P_0c084d9c;
case 0x0c084d9eu: goto P_0c084d9e;
case 0x0c084da0u: goto P_0c084da0;
case 0x0c084da2u: goto P_0c084da2;
case 0x0c084da4u: goto P_0c084da4;
case 0x0c084da6u: goto P_0c084da6;
case 0x0c084da8u: goto P_0c084da8;
case 0x0c084daau: goto P_0c084daa;
case 0x0c084dacu: goto P_0c084dac;
case 0x0c084daeu: goto P_0c084dae;
case 0x0c084db0u: goto P_0c084db0;
case 0x0c084db2u: goto P_0c084db2;
case 0x0c084db4u: goto P_0c084db4;
case 0x0c084db6u: goto P_0c084db6;
case 0x0c084db8u: goto P_0c084db8;
case 0x0c084dbau: goto P_0c084dba;
case 0x0c084dbcu: goto P_0c084dbc;
case 0x0c084dbeu: goto P_0c084dbe;
default: return vf3_matrix_family(target,s,ram);
}
P_0c084a96: /* original 2fe6, guest PC 0x0c084a96 */
if(!s->budget--) { s->failed_pc=0x0c084a96u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c084a98;
P_0c084a98: /* original e300, guest PC 0x0c084a98 */
if(!s->budget--) { s->failed_pc=0x0c084a98u; return 0; }
r[3]=0x00000000u;
goto P_0c084a9a;
P_0c084a9a: /* original 2fd6, guest PC 0x0c084a9a */
if(!s->budget--) { s->failed_pc=0x0c084a9au; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c084a9c;
P_0c084a9c: /* original 6e43, guest PC 0x0c084a9c */
if(!s->budget--) { s->failed_pc=0x0c084a9cu; return 0; }
r[14]=r[4];
goto P_0c084a9e;
P_0c084a9e: /* original 2fc6, guest PC 0x0c084a9e */
if(!s->budget--) { s->failed_pc=0x0c084a9eu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c084aa0;
P_0c084aa0: /* original 6de3, guest PC 0x0c084aa0 */
if(!s->budget--) { s->failed_pc=0x0c084aa0u; return 0; }
r[13]=r[14];
goto P_0c084aa2;
P_0c084aa2: /* original 4f22, guest PC 0x0c084aa2 */
if(!s->budget--) { s->failed_pc=0x0c084aa2u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c084aa4;
P_0c084aa4: /* original 1e32, guest PC 0x0c084aa4 */
if(!s->budget--) { s->failed_pc=0x0c084aa4u; return 0; }
write(ram,r[14]+8,r[3],4);
goto P_0c084aa6;
P_0c084aa6: /* original d211, guest PC 0x0c084aa6 */
if(!s->budget--) { s->failed_pc=0x0c084aa6u; return 0; }
r[2]=read(ram,0x0c084aecu,4);
goto P_0c084aa8;
P_0c084aa8: /* original 420b, guest PC 0x0c084aa8 */
if(!s->budget--) { s->failed_pc=0x0c084aa8u; return 0; }
target=r[2];
r[16]=code_base|0x0c084aacu;
r[13]+=0x00000014u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c084aacu) { target=s->pc; goto dispatch; }
goto P_0c084aac;
P_0c084aaa: /* original 7d14, guest PC 0x0c084aaa */
if(!s->budget--) { s->failed_pc=0x0c084aaau; return 0; }
r[13]+=0x00000014u;
goto P_0c084aac;
P_0c084aac: /* original e3f9, guest PC 0x0c084aac */
if(!s->budget--) { s->failed_pc=0x0c084aacu; return 0; }
r[3]=0xfffffff9u;
goto P_0c084aae;
P_0c084aae: /* original 6403, guest PC 0x0c084aae */
if(!s->budget--) { s->failed_pc=0x0c084aaeu; return 0; }
r[4]=r[0];
goto P_0c084ab0;
P_0c084ab0: /* original 443c, guest PC 0x0c084ab0 */
if(!s->budget--) { s->failed_pc=0x0c084ab0u; return 0; }
r[4]=(r[3]&0x80000000u)?((r[3]&31u)?(uint32_t)((int32_t)r[4]>>((-r[3])&31u)):((int32_t)r[4]<0?0xffffffffu:0)):r[4]<<(r[3]&31u);
goto P_0c084ab2;
P_0c084ab2: /* original e20e, guest PC 0x0c084ab2 */
if(!s->budget--) { s->failed_pc=0x0c084ab2u; return 0; }
r[2]=0x0000000eu;
goto P_0c084ab4;
P_0c084ab4: /* original 2429, guest PC 0x0c084ab4 */
if(!s->budget--) { s->failed_pc=0x0c084ab4u; return 0; }
r[4]&=r[2];
goto P_0c084ab6;
P_0c084ab6: /* original e001, guest PC 0x0c084ab6 */
if(!s->budget--) { s->failed_pc=0x0c084ab6u; return 0; }
r[0]=0x00000001u;
goto P_0c084ab8;
P_0c084ab8: /* original 4401, guest PC 0x0c084ab8 */
if(!s->budget--) { s->failed_pc=0x0c084ab8u; return 0; }
r[17]=(r[17]&~1u)|((r[4]&1)!=0);
r[4]>>=1;
goto P_0c084aba;
P_0c084aba: /* original 81e2, guest PC 0x0c084aba */
if(!s->budget--) { s->failed_pc=0x0c084abau; return 0; }
write(ram,r[14]+4,r[0],2);
goto P_0c084abc;
P_0c084abc: /* original d10f, guest PC 0x0c084abc */
if(!s->budget--) { s->failed_pc=0x0c084abcu; return 0; }
r[1]=read(ram,0x0c084afcu,4);
goto P_0c084abe;
P_0c084abe: /* original 6043, guest PC 0x0c084abe */
if(!s->budget--) { s->failed_pc=0x0c084abeu; return 0; }
r[0]=r[4];
goto P_0c084ac0;
P_0c084ac0: /* original 4000, guest PC 0x0c084ac0 */
if(!s->budget--) { s->failed_pc=0x0c084ac0u; return 0; }
r[17]=(r[17]&~1u)|((r[0]>>31)!=0);
r[0]<<=1;
goto P_0c084ac2;
P_0c084ac2: /* original 001d, guest PC 0x0c084ac2 */
if(!s->budget--) { s->failed_pc=0x0c084ac2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[1]+r[0],2);
goto P_0c084ac4;
P_0c084ac4: /* original ec0a, guest PC 0x0c084ac4 */
if(!s->budget--) { s->failed_pc=0x0c084ac4u; return 0; }
r[12]=0x0000000au;
goto P_0c084ac6;
P_0c084ac6: /* original 81e1, guest PC 0x0c084ac6 */
if(!s->budget--) { s->failed_pc=0x0c084ac6u; return 0; }
write(ram,r[14]+2,r[0],2);
goto P_0c084ac8;
P_0c084ac8: /* original 65d3, guest PC 0x0c084ac8 */
if(!s->budget--) { s->failed_pc=0x0c084ac8u; return 0; }
r[5]=r[13];
goto P_0c084aca;
P_0c084aca: /* original bf57, guest PC 0x0c084aca */
if(!s->budget--) { s->failed_pc=0x0c084acau; return 0; }
target=code_base|0x0c08497cu; r[16]=code_base|0x0c084aceu;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c084aceu) { target=s->pc; goto dispatch; }
goto P_0c084ace;
P_0c084acc: /* original 64e3, guest PC 0x0c084acc */
if(!s->budget--) { s->failed_pc=0x0c084accu; return 0; }
r[4]=r[14];
goto P_0c084ace;
P_0c084ace: /* original 4c10, guest PC 0x0c084ace */
if(!s->budget--) { s->failed_pc=0x0c084aceu; return 0; }
--r[12];
r[17]=(r[17]&~1u)|((r[12]==0)!=0);
goto P_0c084ad0;
P_0c084ad0: /* original 8ffa, guest PC 0x0c084ad0 */
if(!s->budget--) { s->failed_pc=0x0c084ad0u; return 0; }
cond=r[17]&1u;
r[13]+=0x0000002cu;
if(!cond) { goto P_0c084ac8; }
goto P_0c084ad4;
P_0c084ad2: /* original 7d2c, guest PC 0x0c084ad2 */
if(!s->budget--) { s->failed_pc=0x0c084ad2u; return 0; }
r[13]+=0x0000002cu;
goto P_0c084ad4;
P_0c084ad4: /* original 4f26, guest PC 0x0c084ad4 */
if(!s->budget--) { s->failed_pc=0x0c084ad4u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c084ad6;
P_0c084ad6: /* original 6cf6, guest PC 0x0c084ad6 */
if(!s->budget--) { s->failed_pc=0x0c084ad6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c084ad8;
P_0c084ad8: /* original 6df6, guest PC 0x0c084ad8 */
if(!s->budget--) { s->failed_pc=0x0c084ad8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c084ada;
P_0c084ada: /* original 000b, guest PC 0x0c084ada */
if(!s->budget--) { s->failed_pc=0x0c084adau; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c084adc: /* original 6ef6, guest PC 0x0c084adc */
if(!s->budget--) { s->failed_pc=0x0c084adcu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c084adeu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c084adeu; return 0; } return 1;
P_0c084b00: /* original 2fe6, guest PC 0x0c084b00 */
if(!s->budget--) { s->failed_pc=0x0c084b00u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c084b02;
P_0c084b02: /* original 2fd6, guest PC 0x0c084b02 */
if(!s->budget--) { s->failed_pc=0x0c084b02u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c084b04;
P_0c084b04: /* original 2fc6, guest PC 0x0c084b04 */
if(!s->budget--) { s->failed_pc=0x0c084b04u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c084b06;
P_0c084b06: /* original 2fb6, guest PC 0x0c084b06 */
if(!s->budget--) { s->failed_pc=0x0c084b06u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c084b08;
P_0c084b08: /* original 2fa6, guest PC 0x0c084b08 */
if(!s->budget--) { s->failed_pc=0x0c084b08u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c084b0a;
P_0c084b0a: /* original 2f96, guest PC 0x0c084b0a */
if(!s->budget--) { s->failed_pc=0x0c084b0au; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c084b0c;
P_0c084b0c: /* original fffb, guest PC 0x0c084b0c */
if(!s->budget--) { s->failed_pc=0x0c084b0cu; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c084b0e;
P_0c084b0e: /* original ffeb, guest PC 0x0c084b0e */
if(!s->budget--) { s->failed_pc=0x0c084b0eu; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,14,r[15]);
goto P_0c084b10;
P_0c084b10: /* original ffdb, guest PC 0x0c084b10 */
if(!s->budget--) { s->failed_pc=0x0c084b10u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,13,r[15]);
goto P_0c084b12;
P_0c084b12: /* original ffcb, guest PC 0x0c084b12 */
if(!s->budget--) { s->failed_pc=0x0c084b12u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,12,r[15]);
goto P_0c084b14;
P_0c084b14: /* original d146, guest PC 0x0c084b14 */
if(!s->budget--) { s->failed_pc=0x0c084b14u; return 0; }
r[1]=read(ram,0x0c084c30u,4);
goto P_0c084b16;
P_0c084b16: /* original 4f22, guest PC 0x0c084b16 */
if(!s->budget--) { s->failed_pc=0x0c084b16u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c084b18;
P_0c084b18: /* original d344, guest PC 0x0c084b18 */
if(!s->budget--) { s->failed_pc=0x0c084b18u; return 0; }
r[3]=read(ram,0x0c084c2cu,4);
goto P_0c084b1a;
P_0c084b1a: /* original 6212, guest PC 0x0c084b1a */
if(!s->budget--) { s->failed_pc=0x0c084b1au; return 0; }
tmp=read(ram,r[1],4);
r[2]=tmp;
goto P_0c084b1c;
P_0c084b1c: /* original 7ffc, guest PC 0x0c084b1c */
if(!s->budget--) { s->failed_pc=0x0c084b1cu; return 0; }
r[15]+=0xfffffffcu;
goto P_0c084b1e;
P_0c084b1e: /* original 2238, guest PC 0x0c084b1e */
if(!s->budget--) { s->failed_pc=0x0c084b1eu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c084b20;
P_0c084b20: /* original 8b76, guest PC 0x0c084b20 */
if(!s->budget--) { s->failed_pc=0x0c084b20u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c084c10; }
goto P_0c084b22;
P_0c084b22: /* original 6d43, guest PC 0x0c084b22 */
if(!s->budget--) { s->failed_pc=0x0c084b22u; return 0; }
r[13]=r[4];
goto P_0c084b24;
P_0c084b24: /* original 85d1, guest PC 0x0c084b24 */
if(!s->budget--) { s->failed_pc=0x0c084b24u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[13]+2,2);
goto P_0c084b26;
P_0c084b26: /* original 6403, guest PC 0x0c084b26 */
if(!s->budget--) { s->failed_pc=0x0c084b26u; return 0; }
r[4]=r[0];
goto P_0c084b28;
P_0c084b28: /* original 74ff, guest PC 0x0c084b28 */
if(!s->budget--) { s->failed_pc=0x0c084b28u; return 0; }
r[4]+=0xffffffffu;
goto P_0c084b2a;
P_0c084b2a: /* original 4415, guest PC 0x0c084b2a */
if(!s->budget--) { s->failed_pc=0x0c084b2au; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>0)!=0);
goto P_0c084b2c;
P_0c084b2c: /* original 6043, guest PC 0x0c084b2c */
if(!s->budget--) { s->failed_pc=0x0c084b2cu; return 0; }
r[0]=r[4];
goto P_0c084b2e;
P_0c084b2e: /* original 8d16, guest PC 0x0c084b2e */
if(!s->budget--) { s->failed_pc=0x0c084b2eu; return 0; }
cond=r[17]&1u;
write(ram,r[13]+2,r[0],2);
if(cond) { goto P_0c084b5e; }
goto P_0c084b32;
P_0c084b30: /* original 81d1, guest PC 0x0c084b30 */
if(!s->budget--) { s->failed_pc=0x0c084b30u; return 0; }
write(ram,r[13]+2,r[0],2);
goto P_0c084b32;
P_0c084b32: /* original d240, guest PC 0x0c084b32 */
if(!s->budget--) { s->failed_pc=0x0c084b32u; return 0; }
r[2]=read(ram,0x0c084c34u,4);
goto P_0c084b34;
P_0c084b34: /* original 420b, guest PC 0x0c084b34 */
if(!s->budget--) { s->failed_pc=0x0c084b34u; return 0; }
target=r[2];
r[16]=code_base|0x0c084b38u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c084b38u) { target=s->pc; goto dispatch; }
goto P_0c084b38;
P_0c084b36: /* original 0009, guest PC 0x0c084b36 */
if(!s->budget--) { s->failed_pc=0x0c084b36u; return 0; }
goto P_0c084b38;
P_0c084b38: /* original 6503, guest PC 0x0c084b38 */
if(!s->budget--) { s->failed_pc=0x0c084b38u; return 0; }
r[5]=r[0];
goto P_0c084b3a;
P_0c084b3a: /* original e60e, guest PC 0x0c084b3a */
if(!s->budget--) { s->failed_pc=0x0c084b3au; return 0; }
r[6]=0x0000000eu;
goto P_0c084b3c;
P_0c084b3c: /* original 2569, guest PC 0x0c084b3c */
if(!s->budget--) { s->failed_pc=0x0c084b3cu; return 0; }
r[5]&=r[6];
goto P_0c084b3e;
P_0c084b3e: /* original 6403, guest PC 0x0c084b3e */
if(!s->budget--) { s->failed_pc=0x0c084b3eu; return 0; }
r[4]=r[0];
goto P_0c084b40;
P_0c084b40: /* original 4501, guest PC 0x0c084b40 */
if(!s->budget--) { s->failed_pc=0x0c084b40u; return 0; }
r[17]=(r[17]&~1u)|((r[5]&1)!=0);
r[5]>>=1;
goto P_0c084b42;
P_0c084b42: /* original d13d, guest PC 0x0c084b42 */
if(!s->budget--) { s->failed_pc=0x0c084b42u; return 0; }
r[1]=read(ram,0x0c084c38u,4);
goto P_0c084b44;
P_0c084b44: /* original 6053, guest PC 0x0c084b44 */
if(!s->budget--) { s->failed_pc=0x0c084b44u; return 0; }
r[0]=r[5];
goto P_0c084b46;
P_0c084b46: /* original e3f9, guest PC 0x0c084b46 */
if(!s->budget--) { s->failed_pc=0x0c084b46u; return 0; }
r[3]=0xfffffff9u;
goto P_0c084b48;
P_0c084b48: /* original 4000, guest PC 0x0c084b48 */
if(!s->budget--) { s->failed_pc=0x0c084b48u; return 0; }
r[17]=(r[17]&~1u)|((r[0]>>31)!=0);
r[0]<<=1;
goto P_0c084b4a;
P_0c084b4a: /* original 443c, guest PC 0x0c084b4a */
if(!s->budget--) { s->failed_pc=0x0c084b4au; return 0; }
r[4]=(r[3]&0x80000000u)?((r[3]&31u)?(uint32_t)((int32_t)r[4]>>((-r[3])&31u)):((int32_t)r[4]<0?0xffffffffu:0)):r[4]<<(r[3]&31u);
goto P_0c084b4c;
P_0c084b4c: /* original 001d, guest PC 0x0c084b4c */
if(!s->budget--) { s->failed_pc=0x0c084b4cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[1]+r[0],2);
goto P_0c084b4e;
P_0c084b4e: /* original 2469, guest PC 0x0c084b4e */
if(!s->budget--) { s->failed_pc=0x0c084b4eu; return 0; }
r[4]&=r[6];
goto P_0c084b50;
P_0c084b50: /* original 4401, guest PC 0x0c084b50 */
if(!s->budget--) { s->failed_pc=0x0c084b50u; return 0; }
r[17]=(r[17]&~1u)|((r[4]&1)!=0);
r[4]>>=1;
goto P_0c084b52;
P_0c084b52: /* original 81d2, guest PC 0x0c084b52 */
if(!s->budget--) { s->failed_pc=0x0c084b52u; return 0; }
write(ram,r[13]+4,r[0],2);
goto P_0c084b54;
P_0c084b54: /* original d239, guest PC 0x0c084b54 */
if(!s->budget--) { s->failed_pc=0x0c084b54u; return 0; }
r[2]=read(ram,0x0c084c3cu,4);
goto P_0c084b56;
P_0c084b56: /* original 6043, guest PC 0x0c084b56 */
if(!s->budget--) { s->failed_pc=0x0c084b56u; return 0; }
r[0]=r[4];
goto P_0c084b58;
P_0c084b58: /* original 4000, guest PC 0x0c084b58 */
if(!s->budget--) { s->failed_pc=0x0c084b58u; return 0; }
r[17]=(r[17]&~1u)|((r[0]>>31)!=0);
r[0]<<=1;
goto P_0c084b5a;
P_0c084b5a: /* original 002d, guest PC 0x0c084b5a */
if(!s->budget--) { s->failed_pc=0x0c084b5au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[2]+r[0],2);
goto P_0c084b5c;
P_0c084b5c: /* original 81d1, guest PC 0x0c084b5c */
if(!s->budget--) { s->failed_pc=0x0c084b5cu; return 0; }
write(ram,r[13]+2,r[0],2);
goto P_0c084b5e;
P_0c084b5e: /* original c738, guest PC 0x0c084b5e */
if(!s->budget--) { s->failed_pc=0x0c084b5eu; return 0; }
r[0]=code_base|0x00084c40u;
goto P_0c084b60;
P_0c084b60: /* original da38, guest PC 0x0c084b60 */
if(!s->budget--) { s->failed_pc=0x0c084b60u; return 0; }
r[10]=read(ram,0x0c084c44u,4);
goto P_0c084b62;
P_0c084b62: /* original fc08, guest PC 0x0c084b62 */
if(!s->budget--) { s->failed_pc=0x0c084b62u; return 0; }
vf3_matrix_load(s,ram,12,r[0]);
goto P_0c084b64;
P_0c084b64: /* original 6ed3, guest PC 0x0c084b64 */
if(!s->budget--) { s->failed_pc=0x0c084b64u; return 0; }
r[14]=r[13];
goto P_0c084b66;
P_0c084b66: /* original 7e14, guest PC 0x0c084b66 */
if(!s->budget--) { s->failed_pc=0x0c084b66u; return 0; }
r[14]+=0x00000014u;
goto P_0c084b68;
P_0c084b68: /* original fd9d, guest PC 0x0c084b68 */
if(!s->budget--) { s->failed_pc=0x0c084b68u; return 0; }
fr[13]=0x3f800000u;
goto P_0c084b6a;
P_0c084b6a: /* original a04a, guest PC 0x0c084b6a */
if(!s->budget--) { s->failed_pc=0x0c084b6au; return 0; }
r[9]=0x0000000au;
goto P_0c084c02;
P_0c084b6c: /* original e90a, guest PC 0x0c084b6c */
if(!s->budget--) { s->failed_pc=0x0c084b6cu; return 0; }
r[9]=0x0000000au;
goto P_0c084b6e;
P_0c084b6e: /* original e010, guest PC 0x0c084b6e */
if(!s->budget--) { s->failed_pc=0x0c084b6eu; return 0; }
r[0]=0x00000010u;
goto P_0c084b70;
P_0c084b70: /* original f3e6, guest PC 0x0c084b70 */
if(!s->budget--) { s->failed_pc=0x0c084b70u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c084b72;
P_0c084b72: /* original e024, guest PC 0x0c084b72 */
if(!s->budget--) { s->failed_pc=0x0c084b72u; return 0; }
r[0]=0x00000024u;
goto P_0c084b74;
P_0c084b74: /* original ff3a, guest PC 0x0c084b74 */
if(!s->budget--) { s->failed_pc=0x0c084b74u; return 0; }
vf3_matrix_store(s,ram,3,r[15]);
goto P_0c084b76;
P_0c084b76: /* original 0bed, guest PC 0x0c084b76 */
if(!s->budget--) { s->failed_pc=0x0c084b76u; return 0; }
r[11]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c084b78;
P_0c084b78: /* original e028, guest PC 0x0c084b78 */
if(!s->budget--) { s->failed_pc=0x0c084b78u; return 0; }
r[0]=0x00000028u;
goto P_0c084b7a;
P_0c084b7a: /* original 03ed, guest PC 0x0c084b7a */
if(!s->budget--) { s->failed_pc=0x0c084b7au; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c084b7c;
P_0c084b7c: /* original e024, guest PC 0x0c084b7c */
if(!s->budget--) { s->failed_pc=0x0c084b7cu; return 0; }
r[0]=0x00000024u;
goto P_0c084b7e;
P_0c084b7e: /* original 3b3c, guest PC 0x0c084b7e */
if(!s->budget--) { s->failed_pc=0x0c084b7eu; return 0; }
r[11]+=r[3];
goto P_0c084b80;
P_0c084b80: /* original 0eb5, guest PC 0x0c084b80 */
if(!s->budget--) { s->failed_pc=0x0c084b80u; return 0; }
write(ram,r[14]+r[0],r[11],2);
goto P_0c084b82;
P_0c084b82: /* original e026, guest PC 0x0c084b82 */
if(!s->budget--) { s->failed_pc=0x0c084b82u; return 0; }
r[0]=0x00000026u;
goto P_0c084b84;
P_0c084b84: /* original 0ced, guest PC 0x0c084b84 */
if(!s->budget--) { s->failed_pc=0x0c084b84u; return 0; }
r[12]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c084b86;
P_0c084b86: /* original e02a, guest PC 0x0c084b86 */
if(!s->budget--) { s->failed_pc=0x0c084b86u; return 0; }
r[0]=0x0000002au;
goto P_0c084b88;
P_0c084b88: /* original 03ed, guest PC 0x0c084b88 */
if(!s->budget--) { s->failed_pc=0x0c084b88u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c084b8a;
P_0c084b8a: /* original e026, guest PC 0x0c084b8a */
if(!s->budget--) { s->failed_pc=0x0c084b8au; return 0; }
r[0]=0x00000026u;
goto P_0c084b8c;
P_0c084b8c: /* original 3c3c, guest PC 0x0c084b8c */
if(!s->budget--) { s->failed_pc=0x0c084b8cu; return 0; }
r[12]+=r[3];
goto P_0c084b8e;
P_0c084b8e: /* original 0ec5, guest PC 0x0c084b8e */
if(!s->budget--) { s->failed_pc=0x0c084b8eu; return 0; }
write(ram,r[14]+r[0],r[12],2);
goto P_0c084b90;
P_0c084b90: /* original e020, guest PC 0x0c084b90 */
if(!s->budget--) { s->failed_pc=0x0c084b90u; return 0; }
r[0]=0x00000020u;
goto P_0c084b92;
P_0c084b92: /* original ffe6, guest PC 0x0c084b92 */
if(!s->budget--) { s->failed_pc=0x0c084b92u; return 0; }
vf3_matrix_load(s,ram,15,r[14]+r[0]);
goto P_0c084b94;
P_0c084b94: /* original 4a0b, guest PC 0x0c084b94 */
if(!s->budget--) { s->failed_pc=0x0c084b94u; return 0; }
target=r[10];
r[16]=code_base|0x0c084b98u;
r[4]=(uint32_t)(int32_t)(int16_t)r[11];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c084b98u) { target=s->pc; goto dispatch; }
goto P_0c084b98;
P_0c084b96: /* original 64bf, guest PC 0x0c084b96 */
if(!s->budget--) { s->failed_pc=0x0c084b96u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)r[11];
goto P_0c084b98;
P_0c084b98: /* original fe0c, guest PC 0x0c084b98 */
if(!s->budget--) { s->failed_pc=0x0c084b98u; return 0; }
vf3_matrix_move(s,14,0);
goto P_0c084b9a;
P_0c084b9a: /* original fef2, guest PC 0x0c084b9a */
if(!s->budget--) { s->failed_pc=0x0c084b9au; return 0; }
fr[14]=vf3_fpu_binary(fr[14],fr[15],r[18],'*');
goto P_0c084b9c;
P_0c084b9c: /* original 4a0b, guest PC 0x0c084b9c */
if(!s->budget--) { s->failed_pc=0x0c084b9cu; return 0; }
target=r[10];
r[16]=code_base|0x0c084ba0u;
r[4]=(uint32_t)(int32_t)(int16_t)r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c084ba0u) { target=s->pc; goto dispatch; }
goto P_0c084ba0;
P_0c084b9e: /* original 64cf, guest PC 0x0c084b9e */
if(!s->budget--) { s->failed_pc=0x0c084b9eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)r[12];
goto P_0c084ba0;
P_0c084ba0: /* original e004, guest PC 0x0c084ba0 */
if(!s->budget--) { s->failed_pc=0x0c084ba0u; return 0; }
r[0]=0x00000004u;
goto P_0c084ba2;
P_0c084ba2: /* original f3f8, guest PC 0x0c084ba2 */
if(!s->budget--) { s->failed_pc=0x0c084ba2u; return 0; }
vf3_matrix_load(s,ram,3,r[15]);
goto P_0c084ba4;
P_0c084ba4: /* original f6e6, guest PC 0x0c084ba4 */
if(!s->budget--) { s->failed_pc=0x0c084ba4u; return 0; }
vf3_matrix_load(s,ram,6,r[14]+r[0]);
goto P_0c084ba6;
P_0c084ba6: /* original e008, guest PC 0x0c084ba6 */
if(!s->budget--) { s->failed_pc=0x0c084ba6u; return 0; }
r[0]=0x00000008u;
goto P_0c084ba8;
P_0c084ba8: /* original f8e6, guest PC 0x0c084ba8 */
if(!s->budget--) { s->failed_pc=0x0c084ba8u; return 0; }
vf3_matrix_load(s,ram,8,r[14]+r[0]);
goto P_0c084baa;
P_0c084baa: /* original e014, guest PC 0x0c084baa */
if(!s->budget--) { s->failed_pc=0x0c084baau; return 0; }
r[0]=0x00000014u;
goto P_0c084bac;
P_0c084bac: /* original f5e6, guest PC 0x0c084bac */
if(!s->budget--) { s->failed_pc=0x0c084bacu; return 0; }
vf3_matrix_load(s,ram,5,r[14]+r[0]);
goto P_0c084bae;
P_0c084bae: /* original e00c, guest PC 0x0c084bae */
if(!s->budget--) { s->failed_pc=0x0c084baeu; return 0; }
r[0]=0x0000000cu;
goto P_0c084bb0;
P_0c084bb0: /* original f4e6, guest PC 0x0c084bb0 */
if(!s->budget--) { s->failed_pc=0x0c084bb0u; return 0; }
vf3_matrix_load(s,ram,4,r[14]+r[0]);
goto P_0c084bb2;
P_0c084bb2: /* original e018, guest PC 0x0c084bb2 */
if(!s->budget--) { s->failed_pc=0x0c084bb2u; return 0; }
r[0]=0x00000018u;
goto P_0c084bb4;
P_0c084bb4: /* original fa0c, guest PC 0x0c084bb4 */
if(!s->budget--) { s->failed_pc=0x0c084bb4u; return 0; }
vf3_matrix_move(s,10,0);
goto P_0c084bb6;
P_0c084bb6: /* original faf2, guest PC 0x0c084bb6 */
if(!s->budget--) { s->failed_pc=0x0c084bb6u; return 0; }
fr[10]=vf3_fpu_binary(fr[10],fr[15],r[18],'*');
goto P_0c084bb8;
P_0c084bb8: /* original f640, guest PC 0x0c084bb8 */
if(!s->budget--) { s->failed_pc=0x0c084bb8u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[4],r[18],'+');
goto P_0c084bba;
P_0c084bba: /* original f9e6, guest PC 0x0c084bba */
if(!s->budget--) { s->failed_pc=0x0c084bbau; return 0; }
vf3_matrix_load(s,ram,9,r[14]+r[0]);
goto P_0c084bbc;
P_0c084bbc: /* original f431, guest PC 0x0c084bbc */
if(!s->budget--) { s->failed_pc=0x0c084bbcu; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'-');
goto P_0c084bbe;
P_0c084bbe: /* original f7e8, guest PC 0x0c084bbe */
if(!s->budget--) { s->failed_pc=0x0c084bbeu; return 0; }
vf3_matrix_load(s,ram,7,r[14]);
goto P_0c084bc0;
P_0c084bc0: /* original f591, guest PC 0x0c084bc0 */
if(!s->budget--) { s->failed_pc=0x0c084bc0u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[9],r[18],'-');
goto P_0c084bc2;
P_0c084bc2: /* original f9cc, guest PC 0x0c084bc2 */
if(!s->budget--) { s->failed_pc=0x0c084bc2u; return 0; }
vf3_matrix_move(s,9,12);
goto P_0c084bc4;
P_0c084bc4: /* original f7e0, guest PC 0x0c084bc4 */
if(!s->budget--) { s->failed_pc=0x0c084bc4u; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[14],r[18],'+');
goto P_0c084bc6;
P_0c084bc6: /* original f8a0, guest PC 0x0c084bc6 */
if(!s->budget--) { s->failed_pc=0x0c084bc6u; return 0; }
fr[8]=vf3_fpu_binary(fr[8],fr[10],r[18],'+');
goto P_0c084bc8;
P_0c084bc8: /* original f945, guest PC 0x0c084bc8 */
if(!s->budget--) { s->failed_pc=0x0c084bc8u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[9])>as_float(fr[4]))!=0);
goto P_0c084bca;
P_0c084bca: /* original 8f02, guest PC 0x0c084bca */
if(!s->budget--) { s->failed_pc=0x0c084bcau; return 0; }
cond=r[17]&1u;
vf3_matrix_move(s,10,13);
if(!cond) { goto P_0c084bd2; }
goto P_0c084bce;
P_0c084bcc: /* original fadc, guest PC 0x0c084bcc */
if(!s->budget--) { s->failed_pc=0x0c084bccu; return 0; }
vf3_matrix_move(s,10,13);
goto P_0c084bce;
P_0c084bce: /* original a003, guest PC 0x0c084bce */
if(!s->budget--) { s->failed_pc=0x0c084bceu; return 0; }
vf3_matrix_move(s,4,9);
goto P_0c084bd8;
P_0c084bd0: /* original f49c, guest PC 0x0c084bd0 */
if(!s->budget--) { s->failed_pc=0x0c084bd0u; return 0; }
vf3_matrix_move(s,4,9);
goto P_0c084bd2;
P_0c084bd2: /* original f4a5, guest PC 0x0c084bd2 */
if(!s->budget--) { s->failed_pc=0x0c084bd2u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[4])>as_float(fr[10]))!=0);
goto P_0c084bd4;
P_0c084bd4: /* original 8b00, guest PC 0x0c084bd4 */
if(!s->budget--) { s->failed_pc=0x0c084bd4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c084bd8; }
goto P_0c084bd6;
P_0c084bd6: /* original f4ac, guest PC 0x0c084bd6 */
if(!s->budget--) { s->failed_pc=0x0c084bd6u; return 0; }
vf3_matrix_move(s,4,10);
goto P_0c084bd8;
P_0c084bd8: /* original e004, guest PC 0x0c084bd8 */
if(!s->budget--) { s->failed_pc=0x0c084bd8u; return 0; }
r[0]=0x00000004u;
goto P_0c084bda;
P_0c084bda: /* original fe7a, guest PC 0x0c084bda */
if(!s->budget--) { s->failed_pc=0x0c084bdau; return 0; }
vf3_matrix_store(s,ram,7,r[14]);
goto P_0c084bdc;
P_0c084bdc: /* original fe67, guest PC 0x0c084bdc */
if(!s->budget--) { s->failed_pc=0x0c084bdcu; return 0; }
vf3_matrix_store(s,ram,6,r[14]+r[0]);
goto P_0c084bde;
P_0c084bde: /* original e008, guest PC 0x0c084bde */
if(!s->budget--) { s->failed_pc=0x0c084bdeu; return 0; }
r[0]=0x00000008u;
goto P_0c084be0;
P_0c084be0: /* original fe87, guest PC 0x0c084be0 */
if(!s->budget--) { s->failed_pc=0x0c084be0u; return 0; }
vf3_matrix_store(s,ram,8,r[14]+r[0]);
goto P_0c084be2;
P_0c084be2: /* original e014, guest PC 0x0c084be2 */
if(!s->budget--) { s->failed_pc=0x0c084be2u; return 0; }
r[0]=0x00000014u;
goto P_0c084be4;
P_0c084be4: /* original fe57, guest PC 0x0c084be4 */
if(!s->budget--) { s->failed_pc=0x0c084be4u; return 0; }
vf3_matrix_store(s,ram,5,r[14]+r[0]);
goto P_0c084be6;
P_0c084be6: /* original e00c, guest PC 0x0c084be6 */
if(!s->budget--) { s->failed_pc=0x0c084be6u; return 0; }
r[0]=0x0000000cu;
goto P_0c084be8;
P_0c084be8: /* original f38d, guest PC 0x0c084be8 */
if(!s->budget--) { s->failed_pc=0x0c084be8u; return 0; }
fr[3]=0;
goto P_0c084bea;
P_0c084bea: /* original f355, guest PC 0x0c084bea */
if(!s->budget--) { s->failed_pc=0x0c084beau; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[5]))!=0);
goto P_0c084bec;
P_0c084bec: /* original 8d04, guest PC 0x0c084bec */
if(!s->budget--) { s->failed_pc=0x0c084becu; return 0; }
cond=r[17]&1u;
vf3_matrix_store(s,ram,4,r[14]+r[0]);
if(cond) { goto P_0c084bf8; }
goto P_0c084bf0;
P_0c084bee: /* original fe47, guest PC 0x0c084bee */
if(!s->budget--) { s->failed_pc=0x0c084beeu; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c084bf0;
P_0c084bf0: /* original e01c, guest PC 0x0c084bf0 */
if(!s->budget--) { s->failed_pc=0x0c084bf0u; return 0; }
r[0]=0x0000001cu;
goto P_0c084bf2;
P_0c084bf2: /* original f3e6, guest PC 0x0c084bf2 */
if(!s->budget--) { s->failed_pc=0x0c084bf2u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c084bf4;
P_0c084bf4: /* original f365, guest PC 0x0c084bf4 */
if(!s->budget--) { s->failed_pc=0x0c084bf4u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[6]))!=0);
goto P_0c084bf6;
P_0c084bf6: /* original 8902, guest PC 0x0c084bf6 */
if(!s->budget--) { s->failed_pc=0x0c084bf6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c084bfe; }
goto P_0c084bf8;
P_0c084bf8: /* original 65e3, guest PC 0x0c084bf8 */
if(!s->budget--) { s->failed_pc=0x0c084bf8u; return 0; }
r[5]=r[14];
goto P_0c084bfa;
P_0c084bfa: /* original bebf, guest PC 0x0c084bfa */
if(!s->budget--) { s->failed_pc=0x0c084bfau; return 0; }
target=code_base|0x0c08497cu; r[16]=code_base|0x0c084bfeu;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c084bfeu) { target=s->pc; goto dispatch; }
goto P_0c084bfe;
P_0c084bfc: /* original 64d3, guest PC 0x0c084bfc */
if(!s->budget--) { s->failed_pc=0x0c084bfcu; return 0; }
r[4]=r[13];
goto P_0c084bfe;
P_0c084bfe: /* original 79ff, guest PC 0x0c084bfe */
if(!s->budget--) { s->failed_pc=0x0c084bfeu; return 0; }
r[9]+=0xffffffffu;
goto P_0c084c00;
P_0c084c00: /* original 7e2c, guest PC 0x0c084c00 */
if(!s->budget--) { s->failed_pc=0x0c084c00u; return 0; }
r[14]+=0x0000002cu;
goto P_0c084c02;
P_0c084c02: /* original 2998, guest PC 0x0c084c02 */
if(!s->budget--) { s->failed_pc=0x0c084c02u; return 0; }
r[17]=(r[17]&~1u)|(((r[9]&r[9])==0)!=0);
goto P_0c084c04;
P_0c084c04: /* original 8bb3, guest PC 0x0c084c04 */
if(!s->budget--) { s->failed_pc=0x0c084c04u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c084b6e; }
goto P_0c084c06;
P_0c084c06: /* original 52d2, guest PC 0x0c084c06 */
if(!s->budget--) { s->failed_pc=0x0c084c06u; return 0; }
r[2]=read(ram,r[13]+8,4);
goto P_0c084c08;
P_0c084c08: /* original 7201, guest PC 0x0c084c08 */
if(!s->budget--) { s->failed_pc=0x0c084c08u; return 0; }
r[2]+=0x00000001u;
goto P_0c084c0a;
P_0c084c0a: /* original 6023, guest PC 0x0c084c0a */
if(!s->budget--) { s->failed_pc=0x0c084c0au; return 0; }
r[0]=r[2];
goto P_0c084c0c;
P_0c084c0c: /* original c97f, guest PC 0x0c084c0c */
if(!s->budget--) { s->failed_pc=0x0c084c0cu; return 0; }
r[0]&=127u;
goto P_0c084c0e;
P_0c084c0e: /* original 1d02, guest PC 0x0c084c0e */
if(!s->budget--) { s->failed_pc=0x0c084c0eu; return 0; }
write(ram,r[13]+8,r[0],4);
goto P_0c084c10;
P_0c084c10: /* original 7f04, guest PC 0x0c084c10 */
if(!s->budget--) { s->failed_pc=0x0c084c10u; return 0; }
r[15]+=0x00000004u;
goto P_0c084c12;
P_0c084c12: /* original 4f26, guest PC 0x0c084c12 */
if(!s->budget--) { s->failed_pc=0x0c084c12u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c084c14;
P_0c084c14: /* original fcf9, guest PC 0x0c084c14 */
if(!s->budget--) { s->failed_pc=0x0c084c14u; return 0; }
vf3_matrix_load(s,ram,12,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c084c16;
P_0c084c16: /* original fdf9, guest PC 0x0c084c16 */
if(!s->budget--) { s->failed_pc=0x0c084c16u; return 0; }
vf3_matrix_load(s,ram,13,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c084c18;
P_0c084c18: /* original fef9, guest PC 0x0c084c18 */
if(!s->budget--) { s->failed_pc=0x0c084c18u; return 0; }
vf3_matrix_load(s,ram,14,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c084c1a;
P_0c084c1a: /* original fff9, guest PC 0x0c084c1a */
if(!s->budget--) { s->failed_pc=0x0c084c1au; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c084c1c;
P_0c084c1c: /* original 69f6, guest PC 0x0c084c1c */
if(!s->budget--) { s->failed_pc=0x0c084c1cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c084c1e;
P_0c084c1e: /* original 6af6, guest PC 0x0c084c1e */
if(!s->budget--) { s->failed_pc=0x0c084c1eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c084c20;
P_0c084c20: /* original 6bf6, guest PC 0x0c084c20 */
if(!s->budget--) { s->failed_pc=0x0c084c20u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c084c22;
P_0c084c22: /* original 6cf6, guest PC 0x0c084c22 */
if(!s->budget--) { s->failed_pc=0x0c084c22u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c084c24;
P_0c084c24: /* original 6df6, guest PC 0x0c084c24 */
if(!s->budget--) { s->failed_pc=0x0c084c24u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c084c26;
P_0c084c26: /* original 000b, guest PC 0x0c084c26 */
if(!s->budget--) { s->failed_pc=0x0c084c26u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c084c28: /* original 6ef6, guest PC 0x0c084c28 */
if(!s->budget--) { s->failed_pc=0x0c084c28u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c084c2au,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c084c2au; return 0; } return 1;
P_0c084c48: /* original 2fe6, guest PC 0x0c084c48 */
if(!s->budget--) { s->failed_pc=0x0c084c48u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c084c4a;
P_0c084c4a: /* original c735, guest PC 0x0c084c4a */
if(!s->budget--) { s->failed_pc=0x0c084c4au; return 0; }
r[0]=code_base|0x00084d20u;
goto P_0c084c4c;
P_0c084c4c: /* original 2fd6, guest PC 0x0c084c4c */
if(!s->budget--) { s->failed_pc=0x0c084c4cu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c084c4e;
P_0c084c4e: /* original 6e43, guest PC 0x0c084c4e */
if(!s->budget--) { s->failed_pc=0x0c084c4eu; return 0; }
r[14]=r[4];
goto P_0c084c50;
P_0c084c50: /* original 2fc6, guest PC 0x0c084c50 */
if(!s->budget--) { s->failed_pc=0x0c084c50u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c084c52;
P_0c084c52: /* original 7e14, guest PC 0x0c084c52 */
if(!s->budget--) { s->failed_pc=0x0c084c52u; return 0; }
r[14]+=0x00000014u;
goto P_0c084c54;
P_0c084c54: /* original 2fb6, guest PC 0x0c084c54 */
if(!s->budget--) { s->failed_pc=0x0c084c54u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c084c56;
P_0c084c56: /* original 2fa6, guest PC 0x0c084c56 */
if(!s->budget--) { s->failed_pc=0x0c084c56u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c084c58;
P_0c084c58: /* original 2f96, guest PC 0x0c084c58 */
if(!s->budget--) { s->failed_pc=0x0c084c58u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c084c5a;
P_0c084c5a: /* original 2f86, guest PC 0x0c084c5a */
if(!s->budget--) { s->failed_pc=0x0c084c5au; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c084c5c;
P_0c084c5c: /* original fffb, guest PC 0x0c084c5c */
if(!s->budget--) { s->failed_pc=0x0c084c5cu; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c084c5e;
P_0c084c5e: /* original ffeb, guest PC 0x0c084c5e */
if(!s->budget--) { s->failed_pc=0x0c084c5eu; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,14,r[15]);
goto P_0c084c60;
P_0c084c60: /* original ffdb, guest PC 0x0c084c60 */
if(!s->budget--) { s->failed_pc=0x0c084c60u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,13,r[15]);
goto P_0c084c62;
P_0c084c62: /* original ffcb, guest PC 0x0c084c62 */
if(!s->budget--) { s->failed_pc=0x0c084c62u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,12,r[15]);
goto P_0c084c64;
P_0c084c64: /* original 4f22, guest PC 0x0c084c64 */
if(!s->budget--) { s->failed_pc=0x0c084c64u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c084c66;
P_0c084c66: /* original 7fd8, guest PC 0x0c084c66 */
if(!s->budget--) { s->failed_pc=0x0c084c66u; return 0; }
r[15]+=0xffffffd8u;
goto P_0c084c68;
P_0c084c68: /* original 1f43, guest PC 0x0c084c68 */
if(!s->budget--) { s->failed_pc=0x0c084c68u; return 0; }
write(ram,r[15]+12,r[4],4);
goto P_0c084c6a;
P_0c084c6a: /* original f308, guest PC 0x0c084c6a */
if(!s->budget--) { s->failed_pc=0x0c084c6au; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c084c6c;
P_0c084c6c: /* original e008, guest PC 0x0c084c6c */
if(!s->budget--) { s->failed_pc=0x0c084c6cu; return 0; }
r[0]=0x00000008u;
goto P_0c084c6e;
P_0c084c6e: /* original d32b, guest PC 0x0c084c6e */
if(!s->budget--) { s->failed_pc=0x0c084c6eu; return 0; }
r[3]=read(ram,0x0c084d1cu,4);
goto P_0c084c70;
P_0c084c70: /* original 6d32, guest PC 0x0c084c70 */
if(!s->budget--) { s->failed_pc=0x0c084c70u; return 0; }
tmp=read(ram,r[3],4);
r[13]=tmp;
goto P_0c084c72;
P_0c084c72: /* original ff37, guest PC 0x0c084c72 */
if(!s->budget--) { s->failed_pc=0x0c084c72u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c084c74;
P_0c084c74: /* original c72b, guest PC 0x0c084c74 */
if(!s->budget--) { s->failed_pc=0x0c084c74u; return 0; }
r[0]=code_base|0x00084d24u;
goto P_0c084c76;
P_0c084c76: /* original f308, guest PC 0x0c084c76 */
if(!s->budget--) { s->failed_pc=0x0c084c76u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c084c78;
P_0c084c78: /* original c72b, guest PC 0x0c084c78 */
if(!s->budget--) { s->failed_pc=0x0c084c78u; return 0; }
r[0]=code_base|0x00084d28u;
goto P_0c084c7a;
P_0c084c7a: /* original ff3a, guest PC 0x0c084c7a */
if(!s->budget--) { s->failed_pc=0x0c084c7au; return 0; }
vf3_matrix_store(s,ram,3,r[15]);
goto P_0c084c7c;
P_0c084c7c: /* original f308, guest PC 0x0c084c7c */
if(!s->budget--) { s->failed_pc=0x0c084c7cu; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c084c7e;
P_0c084c7e: /* original e004, guest PC 0x0c084c7e */
if(!s->budget--) { s->failed_pc=0x0c084c7eu; return 0; }
r[0]=0x00000004u;
goto P_0c084c80;
P_0c084c80: /* original ff37, guest PC 0x0c084c80 */
if(!s->budget--) { s->failed_pc=0x0c084c80u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c084c82;
P_0c084c82: /* original d22a, guest PC 0x0c084c82 */
if(!s->budget--) { s->failed_pc=0x0c084c82u; return 0; }
r[2]=read(ram,0x0c084d2cu,4);
goto P_0c084c84;
P_0c084c84: /* original 420b, guest PC 0x0c084c84 */
if(!s->budget--) { s->failed_pc=0x0c084c84u; return 0; }
target=r[2];
r[16]=code_base|0x0c084c88u;
r[4]=0x00000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c084c88u) { target=s->pc; goto dispatch; }
goto P_0c084c88;
P_0c084c86: /* original e400, guest PC 0x0c084c86 */
if(!s->budget--) { s->failed_pc=0x0c084c86u; return 0; }
r[4]=0x00000000u;
goto P_0c084c88;
P_0c084c88: /* original da2b, guest PC 0x0c084c88 */
if(!s->budget--) { s->failed_pc=0x0c084c88u; return 0; }
r[10]=read(ram,0x0c084d38u,4);
goto P_0c084c8a;
P_0c084c8a: /* original ec0a, guest PC 0x0c084c8a */
if(!s->budget--) { s->failed_pc=0x0c084c8au; return 0; }
r[12]=0x0000000au;
goto P_0c084c8c;
P_0c084c8c: /* original d929, guest PC 0x0c084c8c */
if(!s->budget--) { s->failed_pc=0x0c084c8cu; return 0; }
r[9]=read(ram,0x0c084d34u,4);
goto P_0c084c8e;
P_0c084c8e: /* original d828, guest PC 0x0c084c8e */
if(!s->budget--) { s->failed_pc=0x0c084c8eu; return 0; }
r[8]=read(ram,0x0c084d30u,4);
goto P_0c084c90;
P_0c084c90: /* original e004, guest PC 0x0c084c90 */
if(!s->budget--) { s->failed_pc=0x0c084c90u; return 0; }
r[0]=0x00000004u;
goto P_0c084c92;
P_0c084c92: /* original fde8, guest PC 0x0c084c92 */
if(!s->budget--) { s->failed_pc=0x0c084c92u; return 0; }
vf3_matrix_load(s,ram,13,r[14]);
goto P_0c084c94;
P_0c084c94: /* original f3e6, guest PC 0x0c084c94 */
if(!s->budget--) { s->failed_pc=0x0c084c94u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c084c96;
P_0c084c96: /* original e010, guest PC 0x0c084c96 */
if(!s->budget--) { s->failed_pc=0x0c084c96u; return 0; }
r[0]=0x00000010u;
goto P_0c084c98;
P_0c084c98: /* original ff37, guest PC 0x0c084c98 */
if(!s->budget--) { s->failed_pc=0x0c084c98u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c084c9a;
P_0c084c9a: /* original e008, guest PC 0x0c084c9a */
if(!s->budget--) { s->failed_pc=0x0c084c9au; return 0; }
r[0]=0x00000008u;
goto P_0c084c9c;
P_0c084c9c: /* original f2e6, guest PC 0x0c084c9c */
if(!s->budget--) { s->failed_pc=0x0c084c9cu; return 0; }
vf3_matrix_load(s,ram,2,r[14]+r[0]);
goto P_0c084c9e;
P_0c084c9e: /* original e010, guest PC 0x0c084c9e */
if(!s->budget--) { s->failed_pc=0x0c084c9eu; return 0; }
r[0]=0x00000010u;
goto P_0c084ca0;
P_0c084ca0: /* original f39d, guest PC 0x0c084ca0 */
if(!s->budget--) { s->failed_pc=0x0c084ca0u; return 0; }
fr[3]=0x3f800000u;
goto P_0c084ca2;
P_0c084ca2: /* original f232, guest PC 0x0c084ca2 */
if(!s->budget--) { s->failed_pc=0x0c084ca2u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c084ca4;
P_0c084ca4: /* original f4d6, guest PC 0x0c084ca4 */
if(!s->budget--) { s->failed_pc=0x0c084ca4u; return 0; }
vf3_matrix_load(s,ram,4,r[13]+r[0]);
goto P_0c084ca6;
P_0c084ca6: /* original e018, guest PC 0x0c084ca6 */
if(!s->budget--) { s->failed_pc=0x0c084ca6u; return 0; }
r[0]=0x00000018u;
goto P_0c084ca8;
P_0c084ca8: /* original fcd6, guest PC 0x0c084ca8 */
if(!s->budget--) { s->failed_pc=0x0c084ca8u; return 0; }
vf3_matrix_load(s,ram,12,r[13]+r[0]);
goto P_0c084caa;
P_0c084caa: /* original fe2c, guest PC 0x0c084caa */
if(!s->budget--) { s->failed_pc=0x0c084caau; return 0; }
vf3_matrix_move(s,14,2);
goto P_0c084cac;
P_0c084cac: /* original f5cc, guest PC 0x0c084cac */
if(!s->budget--) { s->failed_pc=0x0c084cacu; return 0; }
vf3_matrix_move(s,5,12);
goto P_0c084cae;
P_0c084cae: /* original fe4d, guest PC 0x0c084cae */
if(!s->budget--) { s->failed_pc=0x0c084caeu; return 0; }
fr[14]^=0x80000000u;
goto P_0c084cb0;
P_0c084cb0: /* original f5e1, guest PC 0x0c084cb0 */
if(!s->budget--) { s->failed_pc=0x0c084cb0u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[14],r[18],'-');
goto P_0c084cb2;
P_0c084cb2: /* original 490b, guest PC 0x0c084cb2 */
if(!s->budget--) { s->failed_pc=0x0c084cb2u; return 0; }
target=r[9];
r[16]=code_base|0x0c084cb6u;
fr[4]=vf3_fpu_binary(fr[4],fr[13],r[18],'-');
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c084cb6u) { target=s->pc; goto dispatch; }
goto P_0c084cb6;
P_0c084cb4: /* original f4d1, guest PC 0x0c084cb4 */
if(!s->budget--) { s->failed_pc=0x0c084cb4u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[13],r[18],'-');
goto P_0c084cb6;
P_0c084cb6: /* original d321, guest PC 0x0c084cb6 */
if(!s->budget--) { s->failed_pc=0x0c084cb6u; return 0; }
r[3]=read(ram,0x0c084d3cu,4);
goto P_0c084cb8;
P_0c084cb8: /* original 6b0f, guest PC 0x0c084cb8 */
if(!s->budget--) { s->failed_pc=0x0c084cb8u; return 0; }
r[11]=(uint32_t)(int32_t)(int16_t)r[0];
goto P_0c084cba;
P_0c084cba: /* original e014, guest PC 0x0c084cba */
if(!s->budget--) { s->failed_pc=0x0c084cbau; return 0; }
r[0]=0x00000014u;
goto P_0c084cbc;
P_0c084cbc: /* original 430b, guest PC 0x0c084cbc */
if(!s->budget--) { s->failed_pc=0x0c084cbcu; return 0; }
target=r[3];
r[16]=code_base|0x0c084cc0u;
vf3_matrix_load(s,ram,15,r[14]+r[0]);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c084cc0u) { target=s->pc; goto dispatch; }
goto P_0c084cc0;
P_0c084cbe: /* original ffe6, guest PC 0x0c084cbe */
if(!s->budget--) { s->failed_pc=0x0c084cbeu; return 0; }
vf3_matrix_load(s,ram,15,r[14]+r[0]);
goto P_0c084cc0;
P_0c084cc0: /* original d21f, guest PC 0x0c084cc0 */
if(!s->budget--) { s->failed_pc=0x0c084cc0u; return 0; }
r[2]=read(ram,0x0c084d40u,4);
goto P_0c084cc2;
P_0c084cc2: /* original f5fc, guest PC 0x0c084cc2 */
if(!s->budget--) { s->failed_pc=0x0c084cc2u; return 0; }
vf3_matrix_move(s,5,15);
goto P_0c084cc4;
P_0c084cc4: /* original f6fc, guest PC 0x0c084cc4 */
if(!s->budget--) { s->failed_pc=0x0c084cc4u; return 0; }
vf3_matrix_move(s,6,15);
goto P_0c084cc6;
P_0c084cc6: /* original 420b, guest PC 0x0c084cc6 */
if(!s->budget--) { s->failed_pc=0x0c084cc6u; return 0; }
target=r[2];
r[16]=code_base|0x0c084ccau;
vf3_matrix_move(s,4,15);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c084ccau) { target=s->pc; goto dispatch; }
goto P_0c084cca;
P_0c084cc8: /* original f4fc, guest PC 0x0c084cc8 */
if(!s->budget--) { s->failed_pc=0x0c084cc8u; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c084cca;
P_0c084cca: /* original e01c, guest PC 0x0c084cca */
if(!s->budget--) { s->failed_pc=0x0c084ccau; return 0; }
r[0]=0x0000001cu;
goto P_0c084ccc;
P_0c084ccc: /* original 64f3, guest PC 0x0c084ccc */
if(!s->budget--) { s->failed_pc=0x0c084cccu; return 0; }
r[4]=r[15];
goto P_0c084cce;
P_0c084cce: /* original ffd7, guest PC 0x0c084cce */
if(!s->budget--) { s->failed_pc=0x0c084cceu; return 0; }
vf3_matrix_store(s,ram,13,r[15]+r[0]);
goto P_0c084cd0;
P_0c084cd0: /* original e010, guest PC 0x0c084cd0 */
if(!s->budget--) { s->failed_pc=0x0c084cd0u; return 0; }
r[0]=0x00000010u;
goto P_0c084cd2;
P_0c084cd2: /* original f3f6, guest PC 0x0c084cd2 */
if(!s->budget--) { s->failed_pc=0x0c084cd2u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c084cd4;
P_0c084cd4: /* original e020, guest PC 0x0c084cd4 */
if(!s->budget--) { s->failed_pc=0x0c084cd4u; return 0; }
r[0]=0x00000020u;
goto P_0c084cd6;
P_0c084cd6: /* original ff37, guest PC 0x0c084cd6 */
if(!s->budget--) { s->failed_pc=0x0c084cd6u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c084cd8;
P_0c084cd8: /* original e024, guest PC 0x0c084cd8 */
if(!s->budget--) { s->failed_pc=0x0c084cd8u; return 0; }
r[0]=0x00000024u;
goto P_0c084cda;
P_0c084cda: /* original ffe7, guest PC 0x0c084cda */
if(!s->budget--) { s->failed_pc=0x0c084cdau; return 0; }
vf3_matrix_store(s,ram,14,r[15]+r[0]);
goto P_0c084cdc;
P_0c084cdc: /* original d319, guest PC 0x0c084cdc */
if(!s->budget--) { s->failed_pc=0x0c084cdcu; return 0; }
r[3]=read(ram,0x0c084d44u,4);
goto P_0c084cde;
P_0c084cde: /* original 430b, guest PC 0x0c084cde */
if(!s->budget--) { s->failed_pc=0x0c084cdeu; return 0; }
target=r[3];
r[16]=code_base|0x0c084ce2u;
r[4]+=0x0000001cu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c084ce2u) { target=s->pc; goto dispatch; }
goto P_0c084ce2;
P_0c084ce0: /* original 741c, guest PC 0x0c084ce0 */
if(!s->budget--) { s->failed_pc=0x0c084ce0u; return 0; }
r[4]+=0x0000001cu;
goto P_0c084ce2;
P_0c084ce2: /* original d219, guest PC 0x0c084ce2 */
if(!s->budget--) { s->failed_pc=0x0c084ce2u; return 0; }
r[2]=read(ram,0x0c084d48u,4);
goto P_0c084ce4;
P_0c084ce4: /* original 420b, guest PC 0x0c084ce4 */
if(!s->budget--) { s->failed_pc=0x0c084ce4u; return 0; }
target=r[2];
r[16]=code_base|0x0c084ce8u;
vf3_matrix_move(s,4,15);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c084ce8u) { target=s->pc; goto dispatch; }
goto P_0c084ce8;
P_0c084ce6: /* original f4fc, guest PC 0x0c084ce6 */
if(!s->budget--) { s->failed_pc=0x0c084ce6u; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c084ce8;
P_0c084ce8: /* original 4a0b, guest PC 0x0c084ce8 */
if(!s->budget--) { s->failed_pc=0x0c084ce8u; return 0; }
target=r[10];
r[16]=code_base|0x0c084cecu;
r[4]=r[11];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c084cecu) { target=s->pc; goto dispatch; }
goto P_0c084cec;
P_0c084cea: /* original 64b3, guest PC 0x0c084cea */
if(!s->budget--) { s->failed_pc=0x0c084ceau; return 0; }
r[4]=r[11];
goto P_0c084cec;
P_0c084cec: /* original e008, guest PC 0x0c084cec */
if(!s->budget--) { s->failed_pc=0x0c084cecu; return 0; }
r[0]=0x00000008u;
goto P_0c084cee;
P_0c084cee: /* original f3f6, guest PC 0x0c084cee */
if(!s->budget--) { s->failed_pc=0x0c084ceeu; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c084cf0;
P_0c084cf0: /* original f3f5, guest PC 0x0c084cf0 */
if(!s->budget--) { s->failed_pc=0x0c084cf0u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[15]))!=0);
goto P_0c084cf2;
P_0c084cf2: /* original 8902, guest PC 0x0c084cf2 */
if(!s->budget--) { s->failed_pc=0x0c084cf2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c084cfa; }
goto P_0c084cf4;
P_0c084cf4: /* original 940e, guest PC 0x0c084cf4 */
if(!s->budget--) { s->failed_pc=0x0c084cf4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c084d14u,2);
goto P_0c084cf6;
P_0c084cf6: /* original a02a, guest PC 0x0c084cf6 */
if(!s->budget--) { s->failed_pc=0x0c084cf6u; return 0; }
goto P_0c084d4e;
P_0c084cf8: /* original 0009, guest PC 0x0c084cf8 */
if(!s->budget--) { s->failed_pc=0x0c084cf8u; return 0; }
goto P_0c084cfa;
P_0c084cfa: /* original f3f8, guest PC 0x0c084cfa */
if(!s->budget--) { s->failed_pc=0x0c084cfau; return 0; }
vf3_matrix_load(s,ram,3,r[15]);
goto P_0c084cfc;
P_0c084cfc: /* original f3f5, guest PC 0x0c084cfc */
if(!s->budget--) { s->failed_pc=0x0c084cfcu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[15]))!=0);
goto P_0c084cfe;
P_0c084cfe: /* original 8902, guest PC 0x0c084cfe */
if(!s->budget--) { s->failed_pc=0x0c084cfeu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c084d06; }
goto P_0c084d00;
P_0c084d00: /* original 9409, guest PC 0x0c084d00 */
if(!s->budget--) { s->failed_pc=0x0c084d00u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c084d16u,2);
goto P_0c084d02;
P_0c084d02: /* original a024, guest PC 0x0c084d02 */
if(!s->budget--) { s->failed_pc=0x0c084d02u; return 0; }
goto P_0c084d4e;
P_0c084d04: /* original 0009, guest PC 0x0c084d04 */
if(!s->budget--) { s->failed_pc=0x0c084d04u; return 0; }
goto P_0c084d06;
P_0c084d06: /* original e004, guest PC 0x0c084d06 */
if(!s->budget--) { s->failed_pc=0x0c084d06u; return 0; }
r[0]=0x00000004u;
goto P_0c084d08;
P_0c084d08: /* original f3f6, guest PC 0x0c084d08 */
if(!s->budget--) { s->failed_pc=0x0c084d08u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c084d0a;
P_0c084d0a: /* original f3f5, guest PC 0x0c084d0a */
if(!s->budget--) { s->failed_pc=0x0c084d0au; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[15]))!=0);
goto P_0c084d0c;
P_0c084d0c: /* original 891e, guest PC 0x0c084d0c */
if(!s->budget--) { s->failed_pc=0x0c084d0cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c084d4c; }
goto P_0c084d0e;
P_0c084d0e: /* original 9403, guest PC 0x0c084d0e */
if(!s->budget--) { s->failed_pc=0x0c084d0eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c084d18u,2);
goto P_0c084d10;
P_0c084d10: /* original a01d, guest PC 0x0c084d10 */
if(!s->budget--) { s->failed_pc=0x0c084d10u; return 0; }
goto P_0c084d4e;
P_0c084d12: /* original 0009, guest PC 0x0c084d12 */
if(!s->budget--) { s->failed_pc=0x0c084d12u; return 0; }
if(!vf3_matrix_family(0x0c084d14u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c084d14u; return 0; } return 1;
P_0c084d4c: /* original 9438, guest PC 0x0c084d4c */
if(!s->budget--) { s->failed_pc=0x0c084d4cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c084dc0u,2);
goto P_0c084d4e;
P_0c084d4e: /* original f38d, guest PC 0x0c084d4e */
if(!s->budget--) { s->failed_pc=0x0c084d4eu; return 0; }
fr[3]=0;
goto P_0c084d50;
P_0c084d50: /* original ff35, guest PC 0x0c084d50 */
if(!s->budget--) { s->failed_pc=0x0c084d50u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[15])>as_float(fr[3]))!=0);
goto P_0c084d52;
P_0c084d52: /* original 8b01, guest PC 0x0c084d52 */
if(!s->budget--) { s->failed_pc=0x0c084d52u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c084d58; }
goto P_0c084d54;
P_0c084d54: /* original 480b, guest PC 0x0c084d54 */
if(!s->budget--) { s->failed_pc=0x0c084d54u; return 0; }
target=r[8];
r[16]=code_base|0x0c084d58u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c084d58u) { target=s->pc; goto dispatch; }
goto P_0c084d58;
P_0c084d56: /* original 0009, guest PC 0x0c084d56 */
if(!s->budget--) { s->failed_pc=0x0c084d56u; return 0; }
goto P_0c084d58;
P_0c084d58: /* original 4c10, guest PC 0x0c084d58 */
if(!s->budget--) { s->failed_pc=0x0c084d58u; return 0; }
--r[12];
r[17]=(r[17]&~1u)|((r[12]==0)!=0);
goto P_0c084d5a;
P_0c084d5a: /* original 8f99, guest PC 0x0c084d5a */
if(!s->budget--) { s->failed_pc=0x0c084d5au; return 0; }
cond=r[17]&1u;
r[14]+=0x0000002cu;
if(!cond) { goto P_0c084c90; }
goto P_0c084d5e;
P_0c084d5c: /* original 7e2c, guest PC 0x0c084d5c */
if(!s->budget--) { s->failed_pc=0x0c084d5cu; return 0; }
r[14]+=0x0000002cu;
goto P_0c084d5e;
P_0c084d5e: /* original c719, guest PC 0x0c084d5e */
if(!s->budget--) { s->failed_pc=0x0c084d5eu; return 0; }
r[0]=code_base|0x00084dc4u;
goto P_0c084d60;
P_0c084d60: /* original fe08, guest PC 0x0c084d60 */
if(!s->budget--) { s->failed_pc=0x0c084d60u; return 0; }
vf3_matrix_load(s,ram,14,r[0]);
goto P_0c084d62;
P_0c084d62: /* original c719, guest PC 0x0c084d62 */
if(!s->budget--) { s->failed_pc=0x0c084d62u; return 0; }
r[0]=code_base|0x00084dc8u;
goto P_0c084d64;
P_0c084d64: /* original f308, guest PC 0x0c084d64 */
if(!s->budget--) { s->failed_pc=0x0c084d64u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c084d66;
P_0c084d66: /* original e014, guest PC 0x0c084d66 */
if(!s->budget--) { s->failed_pc=0x0c084d66u; return 0; }
r[0]=0x00000014u;
goto P_0c084d68;
P_0c084d68: /* original ff37, guest PC 0x0c084d68 */
if(!s->budget--) { s->failed_pc=0x0c084d68u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c084d6a;
P_0c084d6a: /* original c718, guest PC 0x0c084d6a */
if(!s->budget--) { s->failed_pc=0x0c084d6au; return 0; }
r[0]=code_base|0x00084dccu;
goto P_0c084d6c;
P_0c084d6c: /* original ff08, guest PC 0x0c084d6c */
if(!s->budget--) { s->failed_pc=0x0c084d6cu; return 0; }
vf3_matrix_load(s,ram,15,r[0]);
goto P_0c084d6e;
P_0c084d6e: /* original e018, guest PC 0x0c084d6e */
if(!s->budget--) { s->failed_pc=0x0c084d6eu; return 0; }
r[0]=0x00000018u;
goto P_0c084d70;
P_0c084d70: /* original f5d6, guest PC 0x0c084d70 */
if(!s->budget--) { s->failed_pc=0x0c084d70u; return 0; }
vf3_matrix_load(s,ram,5,r[13]+r[0]);
goto P_0c084d72;
P_0c084d72: /* original e010, guest PC 0x0c084d72 */
if(!s->budget--) { s->failed_pc=0x0c084d72u; return 0; }
r[0]=0x00000010u;
goto P_0c084d74;
P_0c084d74: /* original f4d6, guest PC 0x0c084d74 */
if(!s->budget--) { s->failed_pc=0x0c084d74u; return 0; }
vf3_matrix_load(s,ram,4,r[13]+r[0]);
goto P_0c084d76;
P_0c084d76: /* original f5f1, guest PC 0x0c084d76 */
if(!s->budget--) { s->failed_pc=0x0c084d76u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[15],r[18],'-');
goto P_0c084d78;
P_0c084d78: /* original 490b, guest PC 0x0c084d78 */
if(!s->budget--) { s->failed_pc=0x0c084d78u; return 0; }
target=r[9];
r[16]=code_base|0x0c084d7cu;
fr[4]=vf3_fpu_binary(fr[4],fr[14],r[18],'-');
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c084d7cu) { target=s->pc; goto dispatch; }
goto P_0c084d7c;
P_0c084d7a: /* original f4e1, guest PC 0x0c084d7a */
if(!s->budget--) { s->failed_pc=0x0c084d7au; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[14],r[18],'-');
goto P_0c084d7c;
P_0c084d7c: /* original d314, guest PC 0x0c084d7c */
if(!s->budget--) { s->failed_pc=0x0c084d7cu; return 0; }
r[3]=read(ram,0x0c084dd0u,4);
goto P_0c084d7e;
P_0c084d7e: /* original 600f, guest PC 0x0c084d7e */
if(!s->budget--) { s->failed_pc=0x0c084d7eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)r[0];
goto P_0c084d80;
P_0c084d80: /* original 430b, guest PC 0x0c084d80 */
if(!s->budget--) { s->failed_pc=0x0c084d80u; return 0; }
target=r[3];
r[16]=code_base|0x0c084d84u;
write(ram,r[15]+24,r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c084d84u) { target=s->pc; goto dispatch; }
goto P_0c084d84;
P_0c084d82: /* original 1f06, guest PC 0x0c084d82 */
if(!s->budget--) { s->failed_pc=0x0c084d82u; return 0; }
write(ram,r[15]+24,r[0],4);
goto P_0c084d84;
P_0c084d84: /* original e014, guest PC 0x0c084d84 */
if(!s->budget--) { s->failed_pc=0x0c084d84u; return 0; }
r[0]=0x00000014u;
goto P_0c084d86;
P_0c084d86: /* original d313, guest PC 0x0c084d86 */
if(!s->budget--) { s->failed_pc=0x0c084d86u; return 0; }
r[3]=read(ram,0x0c084dd4u,4);
goto P_0c084d88;
P_0c084d88: /* original f5f6, guest PC 0x0c084d88 */
if(!s->budget--) { s->failed_pc=0x0c084d88u; return 0; }
vf3_matrix_load(s,ram,5,r[15]+r[0]);
goto P_0c084d8a;
P_0c084d8a: /* original f6fc, guest PC 0x0c084d8a */
if(!s->budget--) { s->failed_pc=0x0c084d8au; return 0; }
vf3_matrix_move(s,6,15);
goto P_0c084d8c;
P_0c084d8c: /* original 430b, guest PC 0x0c084d8c */
if(!s->budget--) { s->failed_pc=0x0c084d8cu; return 0; }
target=r[3];
r[16]=code_base|0x0c084d90u;
vf3_matrix_move(s,4,14);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c084d90u) { target=s->pc; goto dispatch; }
goto P_0c084d90;
P_0c084d8e: /* original f4ec, guest PC 0x0c084d8e */
if(!s->budget--) { s->failed_pc=0x0c084d8eu; return 0; }
vf3_matrix_move(s,4,14);
goto P_0c084d90;
P_0c084d90: /* original 4a0b, guest PC 0x0c084d90 */
if(!s->budget--) { s->failed_pc=0x0c084d90u; return 0; }
target=r[10];
r[16]=code_base|0x0c084d94u;
r[4]=read(ram,r[15]+24,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c084d94u) { target=s->pc; goto dispatch; }
goto P_0c084d94;
P_0c084d92: /* original 54f6, guest PC 0x0c084d92 */
if(!s->budget--) { s->failed_pc=0x0c084d92u; return 0; }
r[4]=read(ram,r[15]+24,4);
goto P_0c084d94;
P_0c084d94: /* original 54f3, guest PC 0x0c084d94 */
if(!s->budget--) { s->failed_pc=0x0c084d94u; return 0; }
r[4]=read(ram,r[15]+12,4);
goto P_0c084d96;
P_0c084d96: /* original 9314, guest PC 0x0c084d96 */
if(!s->budget--) { s->failed_pc=0x0c084d96u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c084dc2u,2);
goto P_0c084d98;
P_0c084d98: /* original 5442, guest PC 0x0c084d98 */
if(!s->budget--) { s->failed_pc=0x0c084d98u; return 0; }
r[4]=read(ram,r[4]+8,4);
goto P_0c084d9a;
P_0c084d9a: /* original 480b, guest PC 0x0c084d9a */
if(!s->budget--) { s->failed_pc=0x0c084d9au; return 0; }
target=r[8];
r[16]=code_base|0x0c084d9eu;
r[4]+=r[3];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c084d9eu) { target=s->pc; goto dispatch; }
goto P_0c084d9e;
P_0c084d9c: /* original 343c, guest PC 0x0c084d9c */
if(!s->budget--) { s->failed_pc=0x0c084d9cu; return 0; }
r[4]+=r[3];
goto P_0c084d9e;
P_0c084d9e: /* original d20e, guest PC 0x0c084d9e */
if(!s->budget--) { s->failed_pc=0x0c084d9eu; return 0; }
r[2]=read(ram,0x0c084dd8u,4);
goto P_0c084da0;
P_0c084da0: /* original 420b, guest PC 0x0c084da0 */
if(!s->budget--) { s->failed_pc=0x0c084da0u; return 0; }
target=r[2];
r[16]=code_base|0x0c084da4u;
r[4]=0x00000001u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c084da4u) { target=s->pc; goto dispatch; }
goto P_0c084da4;
P_0c084da2: /* original e401, guest PC 0x0c084da2 */
if(!s->budget--) { s->failed_pc=0x0c084da2u; return 0; }
r[4]=0x00000001u;
goto P_0c084da4;
P_0c084da4: /* original 7f28, guest PC 0x0c084da4 */
if(!s->budget--) { s->failed_pc=0x0c084da4u; return 0; }
r[15]+=0x00000028u;
goto P_0c084da6;
P_0c084da6: /* original 4f26, guest PC 0x0c084da6 */
if(!s->budget--) { s->failed_pc=0x0c084da6u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c084da8;
P_0c084da8: /* original fcf9, guest PC 0x0c084da8 */
if(!s->budget--) { s->failed_pc=0x0c084da8u; return 0; }
vf3_matrix_load(s,ram,12,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c084daa;
P_0c084daa: /* original fdf9, guest PC 0x0c084daa */
if(!s->budget--) { s->failed_pc=0x0c084daau; return 0; }
vf3_matrix_load(s,ram,13,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c084dac;
P_0c084dac: /* original fef9, guest PC 0x0c084dac */
if(!s->budget--) { s->failed_pc=0x0c084dacu; return 0; }
vf3_matrix_load(s,ram,14,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c084dae;
P_0c084dae: /* original fff9, guest PC 0x0c084dae */
if(!s->budget--) { s->failed_pc=0x0c084daeu; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c084db0;
P_0c084db0: /* original 68f6, guest PC 0x0c084db0 */
if(!s->budget--) { s->failed_pc=0x0c084db0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c084db2;
P_0c084db2: /* original 69f6, guest PC 0x0c084db2 */
if(!s->budget--) { s->failed_pc=0x0c084db2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c084db4;
P_0c084db4: /* original 6af6, guest PC 0x0c084db4 */
if(!s->budget--) { s->failed_pc=0x0c084db4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c084db6;
P_0c084db6: /* original 6bf6, guest PC 0x0c084db6 */
if(!s->budget--) { s->failed_pc=0x0c084db6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c084db8;
P_0c084db8: /* original 6cf6, guest PC 0x0c084db8 */
if(!s->budget--) { s->failed_pc=0x0c084db8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c084dba;
P_0c084dba: /* original 6df6, guest PC 0x0c084dba */
if(!s->budget--) { s->failed_pc=0x0c084dbau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c084dbc;
P_0c084dbc: /* original 000b, guest PC 0x0c084dbc */
if(!s->budget--) { s->failed_pc=0x0c084dbcu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c084dbe: /* original 6ef6, guest PC 0x0c084dbe */
if(!s->budget--) { s->failed_pc=0x0c084dbeu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c084dc0u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c084dc0u; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
