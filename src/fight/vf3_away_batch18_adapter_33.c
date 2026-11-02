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
int vf3_away_batch18_adapter_33(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
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
case 0x0c096d5eu: goto P_0c096d5e;
case 0x0c096d60u: goto P_0c096d60;
case 0x0c096d62u: goto P_0c096d62;
case 0x0c096d64u: goto P_0c096d64;
case 0x0c096d66u: goto P_0c096d66;
case 0x0c096d68u: goto P_0c096d68;
case 0x0c096d6au: goto P_0c096d6a;
case 0x0c096d6cu: goto P_0c096d6c;
case 0x0c096d6eu: goto P_0c096d6e;
case 0x0c096d70u: goto P_0c096d70;
case 0x0c096d72u: goto P_0c096d72;
case 0x0c096d74u: goto P_0c096d74;
case 0x0c096d76u: goto P_0c096d76;
case 0x0c096d78u: goto P_0c096d78;
case 0x0c096d7au: goto P_0c096d7a;
case 0x0c096d7cu: goto P_0c096d7c;
case 0x0c096d7eu: goto P_0c096d7e;
case 0x0c096d80u: goto P_0c096d80;
case 0x0c096d82u: goto P_0c096d82;
case 0x0c096d84u: goto P_0c096d84;
case 0x0c096d86u: goto P_0c096d86;
case 0x0c096d88u: goto P_0c096d88;
case 0x0c096d8au: goto P_0c096d8a;
case 0x0c096d8cu: goto P_0c096d8c;
case 0x0c096d8eu: goto P_0c096d8e;
case 0x0c096d90u: goto P_0c096d90;
case 0x0c096d92u: goto P_0c096d92;
case 0x0c096d94u: goto P_0c096d94;
case 0x0c096d96u: goto P_0c096d96;
case 0x0c096d98u: goto P_0c096d98;
case 0x0c096d9au: goto P_0c096d9a;
case 0x0c096d9cu: goto P_0c096d9c;
case 0x0c096d9eu: goto P_0c096d9e;
case 0x0c096da0u: goto P_0c096da0;
case 0x0c096da2u: goto P_0c096da2;
case 0x0c096da4u: goto P_0c096da4;
case 0x0c096da6u: goto P_0c096da6;
case 0x0c096da8u: goto P_0c096da8;
case 0x0c096daau: goto P_0c096daa;
case 0x0c096dacu: goto P_0c096dac;
case 0x0c096daeu: goto P_0c096dae;
case 0x0c096db0u: goto P_0c096db0;
case 0x0c096db2u: goto P_0c096db2;
case 0x0c096db4u: goto P_0c096db4;
case 0x0c096db6u: goto P_0c096db6;
case 0x0c096db8u: goto P_0c096db8;
case 0x0c096dbau: goto P_0c096dba;
case 0x0c096dbcu: goto P_0c096dbc;
case 0x0c096dbeu: goto P_0c096dbe;
default: return vf3_matrix_family(target,s,ram);
}
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
goto P_0c096d5e;
P_0c096d5e: /* original 2fe6, guest PC 0x0c096d5e */
if(!s->budget--) { s->failed_pc=0x0c096d5eu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c096d60;
P_0c096d60: /* original 2fd6, guest PC 0x0c096d60 */
if(!s->budget--) { s->failed_pc=0x0c096d60u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c096d62;
P_0c096d62: /* original 4f22, guest PC 0x0c096d62 */
if(!s->budget--) { s->failed_pc=0x0c096d62u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c096d64;
P_0c096d64: /* original d327, guest PC 0x0c096d64 */
if(!s->budget--) { s->failed_pc=0x0c096d64u; return 0; }
r[3]=read(ram,0x0c096e04u,4);
goto P_0c096d66;
P_0c096d66: /* original dd2a, guest PC 0x0c096d66 */
if(!s->budget--) { s->failed_pc=0x0c096d66u; return 0; }
r[13]=read(ram,0x0c096e10u,4);
goto P_0c096d68;
P_0c096d68: /* original 7ffc, guest PC 0x0c096d68 */
if(!s->budget--) { s->failed_pc=0x0c096d68u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c096d6a;
P_0c096d6a: /* original 2f32, guest PC 0x0c096d6a */
if(!s->budget--) { s->failed_pc=0x0c096d6au; return 0; }
write(ram,r[15],r[3],4);
goto P_0c096d6c;
P_0c096d6c: /* original 52d2, guest PC 0x0c096d6c */
if(!s->budget--) { s->failed_pc=0x0c096d6cu; return 0; }
r[2]=read(ram,r[13]+8,4);
goto P_0c096d6e;
P_0c096d6e: /* original d329, guest PC 0x0c096d6e */
if(!s->budget--) { s->failed_pc=0x0c096d6eu; return 0; }
r[3]=read(ram,0x0c096e14u,4);
goto P_0c096d70;
P_0c096d70: /* original 2238, guest PC 0x0c096d70 */
if(!s->budget--) { s->failed_pc=0x0c096d70u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c096d72;
P_0c096d72: /* original 8920, guest PC 0x0c096d72 */
if(!s->budget--) { s->failed_pc=0x0c096d72u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c096db6; }
goto P_0c096d74;
P_0c096d74: /* original de28, guest PC 0x0c096d74 */
if(!s->budget--) { s->failed_pc=0x0c096d74u; return 0; }
r[14]=read(ram,0x0c096e18u,4);
goto P_0c096d76;
P_0c096d76: /* original bdc4, guest PC 0x0c096d76 */
if(!s->budget--) { s->failed_pc=0x0c096d76u; return 0; }
target=code_base|0x0c096902u; r[16]=code_base|0x0c096d7au;
r[4]=read(ram,r[14]+32,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c096d7au) { target=s->pc; goto dispatch; }
goto P_0c096d7a;
P_0c096d78: /* original 54e8, guest PC 0x0c096d78 */
if(!s->budget--) { s->failed_pc=0x0c096d78u; return 0; }
r[4]=read(ram,r[14]+32,4);
goto P_0c096d7a;
P_0c096d7a: /* original e044, guest PC 0x0c096d7a */
if(!s->budget--) { s->failed_pc=0x0c096d7au; return 0; }
r[0]=0x00000044u;
goto P_0c096d7c;
P_0c096d7c: /* original bdc1, guest PC 0x0c096d7c */
if(!s->budget--) { s->failed_pc=0x0c096d7cu; return 0; }
target=code_base|0x0c096902u; r[16]=code_base|0x0c096d80u;
r[4]=read(ram,r[14]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c096d80u) { target=s->pc; goto dispatch; }
goto P_0c096d80;
P_0c096d7e: /* original 04ee, guest PC 0x0c096d7e */
if(!s->budget--) { s->failed_pc=0x0c096d7eu; return 0; }
r[4]=read(ram,r[14]+r[0],4);
goto P_0c096d80;
P_0c096d80: /* original 52d2, guest PC 0x0c096d80 */
if(!s->budget--) { s->failed_pc=0x0c096d80u; return 0; }
r[2]=read(ram,r[13]+8,4);
goto P_0c096d82;
P_0c096d82: /* original e044, guest PC 0x0c096d82 */
if(!s->budget--) { s->failed_pc=0x0c096d82u; return 0; }
r[0]=0x00000044u;
goto P_0c096d84;
P_0c096d84: /* original d325, guest PC 0x0c096d84 */
if(!s->budget--) { s->failed_pc=0x0c096d84u; return 0; }
r[3]=read(ram,0x0c096e1cu,4);
goto P_0c096d86;
P_0c096d86: /* original 223b, guest PC 0x0c096d86 */
if(!s->budget--) { s->failed_pc=0x0c096d86u; return 0; }
r[2]|=r[3];
goto P_0c096d88;
P_0c096d88: /* original 1d22, guest PC 0x0c096d88 */
if(!s->budget--) { s->failed_pc=0x0c096d88u; return 0; }
write(ram,r[13]+8,r[2],4);
goto P_0c096d8a;
P_0c096d8a: /* original e201, guest PC 0x0c096d8a */
if(!s->budget--) { s->failed_pc=0x0c096d8au; return 0; }
r[2]=0x00000001u;
goto P_0c096d8c;
P_0c096d8c: /* original d124, guest PC 0x0c096d8c */
if(!s->budget--) { s->failed_pc=0x0c096d8cu; return 0; }
r[1]=read(ram,0x0c096e20u,4);
goto P_0c096d8e;
P_0c096d8e: /* original 04ee, guest PC 0x0c096d8e */
if(!s->budget--) { s->failed_pc=0x0c096d8eu; return 0; }
r[4]=read(ram,r[14]+r[0],4);
goto P_0c096d90;
P_0c096d90: /* original 410b, guest PC 0x0c096d90 */
if(!s->budget--) { s->failed_pc=0x0c096d90u; return 0; }
target=r[1];
r[16]=code_base|0x0c096d94u;
write(ram,r[4],r[2],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c096d94u) { target=s->pc; goto dispatch; }
goto P_0c096d94;
P_0c096d92: /* original 2422, guest PC 0x0c096d92 */
if(!s->budget--) { s->failed_pc=0x0c096d92u; return 0; }
write(ram,r[4],r[2],4);
goto P_0c096d94;
P_0c096d94: /* original 55e5, guest PC 0x0c096d94 */
if(!s->budget--) { s->failed_pc=0x0c096d94u; return 0; }
r[5]=read(ram,r[14]+20,4);
goto P_0c096d96;
P_0c096d96: /* original e400, guest PC 0x0c096d96 */
if(!s->budget--) { s->failed_pc=0x0c096d96u; return 0; }
r[4]=0x00000000u;
goto P_0c096d98;
P_0c096d98: /* original 56e4, guest PC 0x0c096d98 */
if(!s->budget--) { s->failed_pc=0x0c096d98u; return 0; }
r[6]=read(ram,r[14]+16,4);
goto P_0c096d9a;
P_0c096d9a: /* original e061, guest PC 0x0c096d9a */
if(!s->budget--) { s->failed_pc=0x0c096d9au; return 0; }
r[0]=0x00000061u;
goto P_0c096d9c;
P_0c096d9c: /* original 0644, guest PC 0x0c096d9c */
if(!s->budget--) { s->failed_pc=0x0c096d9cu; return 0; }
write(ram,r[6]+r[0],r[4],1);
goto P_0c096d9e;
P_0c096d9e: /* original 0544, guest PC 0x0c096d9e */
if(!s->budget--) { s->failed_pc=0x0c096d9eu; return 0; }
write(ram,r[5]+r[0],r[4],1);
goto P_0c096da0;
P_0c096da0: /* original e060, guest PC 0x0c096da0 */
if(!s->budget--) { s->failed_pc=0x0c096da0u; return 0; }
r[0]=0x00000060u;
goto P_0c096da2;
P_0c096da2: /* original 0644, guest PC 0x0c096da2 */
if(!s->budget--) { s->failed_pc=0x0c096da2u; return 0; }
write(ram,r[6]+r[0],r[4],1);
goto P_0c096da4;
P_0c096da4: /* original 0544, guest PC 0x0c096da4 */
if(!s->budget--) { s->failed_pc=0x0c096da4u; return 0; }
write(ram,r[5]+r[0],r[4],1);
goto P_0c096da6;
P_0c096da6: /* original e016, guest PC 0x0c096da6 */
if(!s->budget--) { s->failed_pc=0x0c096da6u; return 0; }
r[0]=0x00000016u;
goto P_0c096da8;
P_0c096da8: /* original 63f2, guest PC 0x0c096da8 */
if(!s->budget--) { s->failed_pc=0x0c096da8u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c096daa;
P_0c096daa: /* original 7f04, guest PC 0x0c096daa */
if(!s->budget--) { s->failed_pc=0x0c096daau; return 0; }
r[15]+=0x00000004u;
goto P_0c096dac;
P_0c096dac: /* original 4f26, guest PC 0x0c096dac */
if(!s->budget--) { s->failed_pc=0x0c096dacu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c096dae;
P_0c096dae: /* original 803a, guest PC 0x0c096dae */
if(!s->budget--) { s->failed_pc=0x0c096daeu; return 0; }
write(ram,r[3]+10,r[0],1);
goto P_0c096db0;
P_0c096db0: /* original 6df6, guest PC 0x0c096db0 */
if(!s->budget--) { s->failed_pc=0x0c096db0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c096db2;
P_0c096db2: /* original ad8d, guest PC 0x0c096db2 */
if(!s->budget--) { s->failed_pc=0x0c096db2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0968d0u,s,ram);
P_0c096db4: /* original 6ef6, guest PC 0x0c096db4 */
if(!s->budget--) { s->failed_pc=0x0c096db4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c096db6;
P_0c096db6: /* original 7f04, guest PC 0x0c096db6 */
if(!s->budget--) { s->failed_pc=0x0c096db6u; return 0; }
r[15]+=0x00000004u;
goto P_0c096db8;
P_0c096db8: /* original 4f26, guest PC 0x0c096db8 */
if(!s->budget--) { s->failed_pc=0x0c096db8u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c096dba;
P_0c096dba: /* original 6df6, guest PC 0x0c096dba */
if(!s->budget--) { s->failed_pc=0x0c096dbau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c096dbc;
P_0c096dbc: /* original 000b, guest PC 0x0c096dbc */
if(!s->budget--) { s->failed_pc=0x0c096dbcu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c096dbe: /* original 6ef6, guest PC 0x0c096dbe */
if(!s->budget--) { s->failed_pc=0x0c096dbeu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c096dc0u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c096dc0u; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
