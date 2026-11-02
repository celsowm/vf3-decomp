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
int vf3_away_batch113_adapter_2(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c094b20u: goto P_0c094b20;
case 0x0c094b22u: goto P_0c094b22;
case 0x0c094b24u: goto P_0c094b24;
case 0x0c094b26u: goto P_0c094b26;
case 0x0c094b28u: goto P_0c094b28;
case 0x0c094b2au: goto P_0c094b2a;
case 0x0c094b2cu: goto P_0c094b2c;
case 0x0c094b2eu: goto P_0c094b2e;
case 0x0c094b30u: goto P_0c094b30;
case 0x0c094b32u: goto P_0c094b32;
case 0x0c094b34u: goto P_0c094b34;
case 0x0c094b36u: goto P_0c094b36;
case 0x0c094b38u: goto P_0c094b38;
case 0x0c094b3au: goto P_0c094b3a;
case 0x0c094b3cu: goto P_0c094b3c;
case 0x0c094b3eu: goto P_0c094b3e;
case 0x0c094b40u: goto P_0c094b40;
case 0x0c094b42u: goto P_0c094b42;
case 0x0c094b44u: goto P_0c094b44;
case 0x0c094b46u: goto P_0c094b46;
case 0x0c094b48u: goto P_0c094b48;
case 0x0c094b4au: goto P_0c094b4a;
case 0x0c094b4cu: goto P_0c094b4c;
case 0x0c094b4eu: goto P_0c094b4e;
case 0x0c094b50u: goto P_0c094b50;
case 0x0c094b70u: goto P_0c094b70;
case 0x0c094b72u: goto P_0c094b72;
case 0x0c094b74u: goto P_0c094b74;
case 0x0c094b76u: goto P_0c094b76;
case 0x0c094b78u: goto P_0c094b78;
case 0x0c094b7au: goto P_0c094b7a;
case 0x0c094b7cu: goto P_0c094b7c;
case 0x0c094b7eu: goto P_0c094b7e;
case 0x0c094b80u: goto P_0c094b80;
case 0x0c094b82u: goto P_0c094b82;
case 0x0c094b84u: goto P_0c094b84;
case 0x0c094b86u: goto P_0c094b86;
case 0x0c094b88u: goto P_0c094b88;
case 0x0c094b8au: goto P_0c094b8a;
case 0x0c094b8cu: goto P_0c094b8c;
case 0x0c094b8eu: goto P_0c094b8e;
case 0x0c094b90u: goto P_0c094b90;
case 0x0c094b92u: goto P_0c094b92;
case 0x0c094b94u: goto P_0c094b94;
case 0x0c094b96u: goto P_0c094b96;
case 0x0c094b98u: goto P_0c094b98;
case 0x0c094b9au: goto P_0c094b9a;
case 0x0c094b9cu: goto P_0c094b9c;
case 0x0c094b9eu: goto P_0c094b9e;
case 0x0c094ba0u: goto P_0c094ba0;
case 0x0c094ba2u: goto P_0c094ba2;
case 0x0c094ba4u: goto P_0c094ba4;
case 0x0c094ba6u: goto P_0c094ba6;
case 0x0c094ba8u: goto P_0c094ba8;
case 0x0c094baau: goto P_0c094baa;
case 0x0c094bacu: goto P_0c094bac;
case 0x0c094baeu: goto P_0c094bae;
case 0x0c094bb0u: goto P_0c094bb0;
case 0x0c094bb2u: goto P_0c094bb2;
case 0x0c094bb4u: goto P_0c094bb4;
case 0x0c094bb6u: goto P_0c094bb6;
case 0x0c094bb8u: goto P_0c094bb8;
case 0x0c094bbau: goto P_0c094bba;
case 0x0c094bbcu: goto P_0c094bbc;
case 0x0c094bbeu: goto P_0c094bbe;
case 0x0c094bc0u: goto P_0c094bc0;
case 0x0c094bc2u: goto P_0c094bc2;
case 0x0c094bc4u: goto P_0c094bc4;
case 0x0c094bc6u: goto P_0c094bc6;
case 0x0c094bc8u: goto P_0c094bc8;
case 0x0c094bcau: goto P_0c094bca;
case 0x0c094bccu: goto P_0c094bcc;
case 0x0c094bceu: goto P_0c094bce;
case 0x0c094bd0u: goto P_0c094bd0;
case 0x0c094bd2u: goto P_0c094bd2;
case 0x0c094bd4u: goto P_0c094bd4;
case 0x0c094bd6u: goto P_0c094bd6;
case 0x0c094bd8u: goto P_0c094bd8;
case 0x0c094bdau: goto P_0c094bda;
case 0x0c094bdcu: goto P_0c094bdc;
case 0x0c094bdeu: goto P_0c094bde;
case 0x0c094be0u: goto P_0c094be0;
case 0x0c094be2u: goto P_0c094be2;
case 0x0c094be4u: goto P_0c094be4;
case 0x0c094be6u: goto P_0c094be6;
case 0x0c094be8u: goto P_0c094be8;
case 0x0c094beau: goto P_0c094bea;
case 0x0c094becu: goto P_0c094bec;
case 0x0c094beeu: goto P_0c094bee;
case 0x0c094bf0u: goto P_0c094bf0;
case 0x0c094bf2u: goto P_0c094bf2;
case 0x0c094bf4u: goto P_0c094bf4;
case 0x0c094bf6u: goto P_0c094bf6;
case 0x0c094bf8u: goto P_0c094bf8;
case 0x0c094bfau: goto P_0c094bfa;
case 0x0c094bfcu: goto P_0c094bfc;
case 0x0c094bfeu: goto P_0c094bfe;
case 0x0c094c00u: goto P_0c094c00;
case 0x0c094c02u: goto P_0c094c02;
case 0x0c094c04u: goto P_0c094c04;
case 0x0c094c06u: goto P_0c094c06;
case 0x0c094c08u: goto P_0c094c08;
case 0x0c094c0au: goto P_0c094c0a;
case 0x0c094c0cu: goto P_0c094c0c;
case 0x0c094c0eu: goto P_0c094c0e;
case 0x0c094c10u: goto P_0c094c10;
case 0x0c094c12u: goto P_0c094c12;
case 0x0c094c14u: goto P_0c094c14;
case 0x0c094c16u: goto P_0c094c16;
case 0x0c094c18u: goto P_0c094c18;
case 0x0c094c1au: goto P_0c094c1a;
case 0x0c094c1cu: goto P_0c094c1c;
case 0x0c094c1eu: goto P_0c094c1e;
case 0x0c094c20u: goto P_0c094c20;
case 0x0c094c22u: goto P_0c094c22;
case 0x0c094c24u: goto P_0c094c24;
case 0x0c094c26u: goto P_0c094c26;
case 0x0c094c28u: goto P_0c094c28;
case 0x0c094c2au: goto P_0c094c2a;
case 0x0c094c2cu: goto P_0c094c2c;
case 0x0c094c2eu: goto P_0c094c2e;
case 0x0c094c30u: goto P_0c094c30;
case 0x0c094c32u: goto P_0c094c32;
case 0x0c094c34u: goto P_0c094c34;
case 0x0c094c36u: goto P_0c094c36;
case 0x0c094c38u: goto P_0c094c38;
case 0x0c094c3au: goto P_0c094c3a;
case 0x0c094c3cu: goto P_0c094c3c;
case 0x0c094c3eu: goto P_0c094c3e;
case 0x0c094c40u: goto P_0c094c40;
case 0x0c094c42u: goto P_0c094c42;
case 0x0c094c44u: goto P_0c094c44;
case 0x0c094c46u: goto P_0c094c46;
case 0x0c094c48u: goto P_0c094c48;
case 0x0c094c4au: goto P_0c094c4a;
case 0x0c094c4cu: goto P_0c094c4c;
case 0x0c094c4eu: goto P_0c094c4e;
case 0x0c094c50u: goto P_0c094c50;
case 0x0c094c52u: goto P_0c094c52;
case 0x0c094c54u: goto P_0c094c54;
case 0x0c094c56u: goto P_0c094c56;
case 0x0c094c58u: goto P_0c094c58;
case 0x0c094c5au: goto P_0c094c5a;
case 0x0c094c5cu: goto P_0c094c5c;
case 0x0c094c5eu: goto P_0c094c5e;
case 0x0c094c60u: goto P_0c094c60;
case 0x0c094c62u: goto P_0c094c62;
case 0x0c094c64u: goto P_0c094c64;
case 0x0c094c66u: goto P_0c094c66;
case 0x0c094c68u: goto P_0c094c68;
case 0x0c094c6au: goto P_0c094c6a;
case 0x0c094c6cu: goto P_0c094c6c;
case 0x0c094c6eu: goto P_0c094c6e;
case 0x0c094c70u: goto P_0c094c70;
case 0x0c094c72u: goto P_0c094c72;
case 0x0c094c74u: goto P_0c094c74;
case 0x0c094c76u: goto P_0c094c76;
case 0x0c094c78u: goto P_0c094c78;
case 0x0c094c7au: goto P_0c094c7a;
case 0x0c094c7cu: goto P_0c094c7c;
case 0x0c094c7eu: goto P_0c094c7e;
case 0x0c094c80u: goto P_0c094c80;
case 0x0c094c82u: goto P_0c094c82;
case 0x0c094c84u: goto P_0c094c84;
case 0x0c094c86u: goto P_0c094c86;
case 0x0c094c88u: goto P_0c094c88;
case 0x0c094c8au: goto P_0c094c8a;
case 0x0c094c8cu: goto P_0c094c8c;
case 0x0c094c8eu: goto P_0c094c8e;
case 0x0c094c90u: goto P_0c094c90;
case 0x0c094c92u: goto P_0c094c92;
case 0x0c094c94u: goto P_0c094c94;
case 0x0c094c96u: goto P_0c094c96;
case 0x0c094c98u: goto P_0c094c98;
case 0x0c094c9au: goto P_0c094c9a;
case 0x0c094c9cu: goto P_0c094c9c;
case 0x0c094c9eu: goto P_0c094c9e;
case 0x0c094ca0u: goto P_0c094ca0;
case 0x0c094ca2u: goto P_0c094ca2;
case 0x0c094ca4u: goto P_0c094ca4;
case 0x0c094ca6u: goto P_0c094ca6;
case 0x0c094ca8u: goto P_0c094ca8;
case 0x0c094caau: goto P_0c094caa;
case 0x0c094cacu: goto P_0c094cac;
case 0x0c094caeu: goto P_0c094cae;
case 0x0c094da8u: goto P_0c094da8;
case 0x0c094daau: goto P_0c094daa;
case 0x0c094dacu: goto P_0c094dac;
case 0x0c094daeu: goto P_0c094dae;
case 0x0c094db0u: goto P_0c094db0;
case 0x0c094db2u: goto P_0c094db2;
case 0x0c094db4u: goto P_0c094db4;
case 0x0c094db6u: goto P_0c094db6;
case 0x0c094db8u: goto P_0c094db8;
case 0x0c094dbau: goto P_0c094dba;
case 0x0c094dbcu: goto P_0c094dbc;
case 0x0c094dbeu: goto P_0c094dbe;
case 0x0c094dc0u: goto P_0c094dc0;
case 0x0c094dc2u: goto P_0c094dc2;
case 0x0c094dc4u: goto P_0c094dc4;
case 0x0c094dc6u: goto P_0c094dc6;
case 0x0c094dc8u: goto P_0c094dc8;
case 0x0c094dcau: goto P_0c094dca;
case 0x0c094dccu: goto P_0c094dcc;
case 0x0c094dceu: goto P_0c094dce;
case 0x0c094dd0u: goto P_0c094dd0;
case 0x0c094dd2u: goto P_0c094dd2;
case 0x0c094dd4u: goto P_0c094dd4;
case 0x0c094dd6u: goto P_0c094dd6;
case 0x0c094dd8u: goto P_0c094dd8;
case 0x0c094ddau: goto P_0c094dda;
case 0x0c094ddcu: goto P_0c094ddc;
case 0x0c094ddeu: goto P_0c094dde;
case 0x0c094de0u: goto P_0c094de0;
case 0x0c094de2u: goto P_0c094de2;
case 0x0c094de4u: goto P_0c094de4;
case 0x0c094de6u: goto P_0c094de6;
case 0x0c094de8u: goto P_0c094de8;
case 0x0c094deau: goto P_0c094dea;
case 0x0c094decu: goto P_0c094dec;
case 0x0c094deeu: goto P_0c094dee;
case 0x0c094df0u: goto P_0c094df0;
case 0x0c094df2u: goto P_0c094df2;
case 0x0c094df4u: goto P_0c094df4;
case 0x0c094df6u: goto P_0c094df6;
case 0x0c094df8u: goto P_0c094df8;
case 0x0c094dfau: goto P_0c094dfa;
case 0x0c094dfcu: goto P_0c094dfc;
case 0x0c094dfeu: goto P_0c094dfe;
case 0x0c094e00u: goto P_0c094e00;
case 0x0c094e02u: goto P_0c094e02;
case 0x0c094e04u: goto P_0c094e04;
case 0x0c094e06u: goto P_0c094e06;
case 0x0c094e08u: goto P_0c094e08;
case 0x0c094e0au: goto P_0c094e0a;
case 0x0c094e0cu: goto P_0c094e0c;
case 0x0c094e0eu: goto P_0c094e0e;
case 0x0c094e10u: goto P_0c094e10;
case 0x0c094e12u: goto P_0c094e12;
case 0x0c094e14u: goto P_0c094e14;
case 0x0c094e16u: goto P_0c094e16;
case 0x0c094e18u: goto P_0c094e18;
case 0x0c094e1au: goto P_0c094e1a;
case 0x0c094e1cu: goto P_0c094e1c;
case 0x0c094e1eu: goto P_0c094e1e;
case 0x0c094e20u: goto P_0c094e20;
case 0x0c094e22u: goto P_0c094e22;
case 0x0c094e24u: goto P_0c094e24;
case 0x0c094e26u: goto P_0c094e26;
case 0x0c094e28u: goto P_0c094e28;
case 0x0c094e2au: goto P_0c094e2a;
case 0x0c094e2cu: goto P_0c094e2c;
case 0x0c094e2eu: goto P_0c094e2e;
case 0x0c094e30u: goto P_0c094e30;
case 0x0c094e32u: goto P_0c094e32;
case 0x0c094e34u: goto P_0c094e34;
case 0x0c094e36u: goto P_0c094e36;
case 0x0c094e38u: goto P_0c094e38;
case 0x0c094e3au: goto P_0c094e3a;
case 0x0c094e3cu: goto P_0c094e3c;
case 0x0c094e3eu: goto P_0c094e3e;
case 0x0c094e40u: goto P_0c094e40;
case 0x0c094e42u: goto P_0c094e42;
case 0x0c094e44u: goto P_0c094e44;
case 0x0c094e46u: goto P_0c094e46;
case 0x0c094e48u: goto P_0c094e48;
case 0x0c094e4au: goto P_0c094e4a;
case 0x0c094e4cu: goto P_0c094e4c;
case 0x0c094e4eu: goto P_0c094e4e;
case 0x0c094e50u: goto P_0c094e50;
case 0x0c094e52u: goto P_0c094e52;
case 0x0c094e54u: goto P_0c094e54;
case 0x0c094e56u: goto P_0c094e56;
case 0x0c094e58u: goto P_0c094e58;
case 0x0c094e5au: goto P_0c094e5a;
case 0x0c094e5cu: goto P_0c094e5c;
case 0x0c094e5eu: goto P_0c094e5e;
case 0x0c094e60u: goto P_0c094e60;
case 0x0c094e62u: goto P_0c094e62;
case 0x0c094e64u: goto P_0c094e64;
case 0x0c094e66u: goto P_0c094e66;
case 0x0c094e68u: goto P_0c094e68;
case 0x0c094e6au: goto P_0c094e6a;
default: return vf3_matrix_family(target,s,ram);
}
P_0c094b20: /* original 2fe6, guest PC 0x0c094b20 */
if(!s->budget--) { s->failed_pc=0x0c094b20u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c094b22;
P_0c094b22: /* original 6e43, guest PC 0x0c094b22 */
if(!s->budget--) { s->failed_pc=0x0c094b22u; return 0; }
r[14]=r[4];
goto P_0c094b24;
P_0c094b24: /* original 2fd6, guest PC 0x0c094b24 */
if(!s->budget--) { s->failed_pc=0x0c094b24u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c094b26;
P_0c094b26: /* original 2fc6, guest PC 0x0c094b26 */
if(!s->budget--) { s->failed_pc=0x0c094b26u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c094b28;
P_0c094b28: /* original d70f, guest PC 0x0c094b28 */
if(!s->budget--) { s->failed_pc=0x0c094b28u; return 0; }
r[7]=read(ram,0x0c094b68u,4);
goto P_0c094b2a;
P_0c094b2a: /* original 4f22, guest PC 0x0c094b2a */
if(!s->budget--) { s->failed_pc=0x0c094b2au; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c094b2c;
P_0c094b2c: /* original 8478, guest PC 0x0c094b2c */
if(!s->budget--) { s->failed_pc=0x0c094b2cu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[7]+8,1);
goto P_0c094b2e;
P_0c094b2e: /* original 54e4, guest PC 0x0c094b2e */
if(!s->budget--) { s->failed_pc=0x0c094b2eu; return 0; }
r[4]=read(ram,r[14]+16,4);
goto P_0c094b30;
P_0c094b30: /* original 650c, guest PC 0x0c094b30 */
if(!s->budget--) { s->failed_pc=0x0c094b30u; return 0; }
r[5]=r[0]&255u;
goto P_0c094b32;
P_0c094b32: /* original 6053, guest PC 0x0c094b32 */
if(!s->budget--) { s->failed_pc=0x0c094b32u; return 0; }
r[0]=r[5];
goto P_0c094b34;
P_0c094b34: /* original 8804, guest PC 0x0c094b34 */
if(!s->budget--) { s->failed_pc=0x0c094b34u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000004u)!=0);
goto P_0c094b36;
P_0c094b36: /* original 8d05, guest PC 0x0c094b36 */
if(!s->budget--) { s->failed_pc=0x0c094b36u; return 0; }
cond=r[17]&1u;
r[13]=0x00000000u;
if(cond) { goto P_0c094b44; }
goto P_0c094b3a;
P_0c094b38: /* original ed00, guest PC 0x0c094b38 */
if(!s->budget--) { s->failed_pc=0x0c094b38u; return 0; }
r[13]=0x00000000u;
goto P_0c094b3a;
P_0c094b3a: /* original 6053, guest PC 0x0c094b3a */
if(!s->budget--) { s->failed_pc=0x0c094b3au; return 0; }
r[0]=r[5];
goto P_0c094b3c;
P_0c094b3c: /* original 8805, guest PC 0x0c094b3c */
if(!s->budget--) { s->failed_pc=0x0c094b3cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000005u)!=0);
goto P_0c094b3e;
P_0c094b3e: /* original 8901, guest PC 0x0c094b3e */
if(!s->budget--) { s->failed_pc=0x0c094b3eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c094b44; }
goto P_0c094b40;
P_0c094b40: /* original a001, guest PC 0x0c094b40 */
if(!s->budget--) { s->failed_pc=0x0c094b40u; return 0; }
r[5]=0x00000001u;
goto P_0c094b46;
P_0c094b42: /* original e501, guest PC 0x0c094b42 */
if(!s->budget--) { s->failed_pc=0x0c094b42u; return 0; }
r[5]=0x00000001u;
goto P_0c094b44;
P_0c094b44: /* original 65d3, guest PC 0x0c094b44 */
if(!s->budget--) { s->failed_pc=0x0c094b44u; return 0; }
r[5]=r[13];
goto P_0c094b46;
P_0c094b46: /* original 84e4, guest PC 0x0c094b46 */
if(!s->budget--) { s->failed_pc=0x0c094b46u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+4,1);
goto P_0c094b48;
P_0c094b48: /* original 2008, guest PC 0x0c094b48 */
if(!s->budget--) { s->failed_pc=0x0c094b48u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c094b4a;
P_0c094b4a: /* original 8b11, guest PC 0x0c094b4a */
if(!s->budget--) { s->failed_pc=0x0c094b4au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c094b70; }
goto P_0c094b4c;
P_0c094b4c: /* original d207, guest PC 0x0c094b4c */
if(!s->budget--) { s->failed_pc=0x0c094b4cu; return 0; }
r[2]=read(ram,0x0c094b6cu,4);
goto P_0c094b4e;
P_0c094b4e: /* original a011, guest PC 0x0c094b4e */
if(!s->budget--) { s->failed_pc=0x0c094b4eu; return 0; }
tmp=read(ram,r[2],4);
r[6]=tmp;
goto P_0c094b74;
P_0c094b50: /* original 6622, guest PC 0x0c094b50 */
if(!s->budget--) { s->failed_pc=0x0c094b50u; return 0; }
tmp=read(ram,r[2],4);
r[6]=tmp;
if(!vf3_matrix_family(0x0c094b52u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c094b52u; return 0; } return 1;
P_0c094b70: /* original d153, guest PC 0x0c094b70 */
if(!s->budget--) { s->failed_pc=0x0c094b70u; return 0; }
r[1]=read(ram,0x0c094cc0u,4);
goto P_0c094b72;
P_0c094b72: /* original 6612, guest PC 0x0c094b72 */
if(!s->budget--) { s->failed_pc=0x0c094b72u; return 0; }
tmp=read(ram,r[1],4);
r[6]=tmp;
goto P_0c094b74;
P_0c094b74: /* original 909c, guest PC 0x0c094b74 */
if(!s->budget--) { s->failed_pc=0x0c094b74u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c094cb0u,2);
goto P_0c094b76;
P_0c094b76: /* original ec08, guest PC 0x0c094b76 */
if(!s->budget--) { s->failed_pc=0x0c094b76u; return 0; }
r[12]=0x00000008u;
goto P_0c094b78;
P_0c094b78: /* original 0e66, guest PC 0x0c094b78 */
if(!s->budget--) { s->failed_pc=0x0c094b78u; return 0; }
write(ram,r[14]+r[0],r[6],4);
goto P_0c094b7a;
P_0c094b7a: /* original 70fa, guest PC 0x0c094b7a */
if(!s->budget--) { s->failed_pc=0x0c094b7au; return 0; }
r[0]+=0xfffffffau;
goto P_0c094b7c;
P_0c094b7c: /* original 0e54, guest PC 0x0c094b7c */
if(!s->budget--) { s->failed_pc=0x0c094b7cu; return 0; }
write(ram,r[14]+r[0],r[5],1);
goto P_0c094b7e;
P_0c094b7e: /* original e022, guest PC 0x0c094b7e */
if(!s->budget--) { s->failed_pc=0x0c094b7eu; return 0; }
r[0]=0x00000022u;
goto P_0c094b80;
P_0c094b80: /* original 53e5, guest PC 0x0c094b80 */
if(!s->budget--) { s->failed_pc=0x0c094b80u; return 0; }
r[3]=read(ram,r[14]+20,4);
goto P_0c094b82;
P_0c094b82: /* original 65d3, guest PC 0x0c094b82 */
if(!s->budget--) { s->failed_pc=0x0c094b82u; return 0; }
r[5]=r[13];
goto P_0c094b84;
P_0c094b84: /* original 0e35, guest PC 0x0c094b84 */
if(!s->budget--) { s->failed_pc=0x0c094b84u; return 0; }
write(ram,r[14]+r[0],r[3],2);
goto P_0c094b86;
P_0c094b86: /* original d64f, guest PC 0x0c094b86 */
if(!s->budget--) { s->failed_pc=0x0c094b86u; return 0; }
r[6]=read(ram,0x0c094cc4u,4);
goto P_0c094b88;
P_0c094b88: /* original 6042, guest PC 0x0c094b88 */
if(!s->budget--) { s->failed_pc=0x0c094b88u; return 0; }
tmp=read(ram,r[4],4);
r[0]=tmp;
goto P_0c094b8a;
P_0c094b8a: /* original 305c, guest PC 0x0c094b8a */
if(!s->budget--) { s->failed_pc=0x0c094b8au; return 0; }
r[0]+=r[5];
goto P_0c094b8c;
P_0c094b8c: /* original 4008, guest PC 0x0c094b8c */
if(!s->budget--) { s->failed_pc=0x0c094b8cu; return 0; }
r[0]<<=2;
goto P_0c094b8e;
P_0c094b8e: /* original 036e, guest PC 0x0c094b8e */
if(!s->budget--) { s->failed_pc=0x0c094b8eu; return 0; }
r[3]=read(ram,r[6]+r[0],4);
goto P_0c094b90;
P_0c094b90: /* original 2338, guest PC 0x0c094b90 */
if(!s->budget--) { s->failed_pc=0x0c094b90u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c094b92;
P_0c094b92: /* original 893e, guest PC 0x0c094b92 */
if(!s->budget--) { s->failed_pc=0x0c094b92u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c094c12; }
goto P_0c094b94;
P_0c094b94: /* original 6042, guest PC 0x0c094b94 */
if(!s->budget--) { s->failed_pc=0x0c094b94u; return 0; }
tmp=read(ram,r[4],4);
r[0]=tmp;
goto P_0c094b96;
P_0c094b96: /* original 63e3, guest PC 0x0c094b96 */
if(!s->budget--) { s->failed_pc=0x0c094b96u; return 0; }
r[3]=r[14];
goto P_0c094b98;
P_0c094b98: /* original 6153, guest PC 0x0c094b98 */
if(!s->budget--) { s->failed_pc=0x0c094b98u; return 0; }
r[1]=r[5];
goto P_0c094b9a;
P_0c094b9a: /* original 4108, guest PC 0x0c094b9a */
if(!s->budget--) { s->failed_pc=0x0c094b9au; return 0; }
r[1]<<=2;
goto P_0c094b9c;
P_0c094b9c: /* original 305c, guest PC 0x0c094b9c */
if(!s->budget--) { s->failed_pc=0x0c094b9cu; return 0; }
r[0]+=r[5];
goto P_0c094b9e;
P_0c094b9e: /* original 734c, guest PC 0x0c094b9e */
if(!s->budget--) { s->failed_pc=0x0c094b9eu; return 0; }
r[3]+=0x0000004cu;
goto P_0c094ba0;
P_0c094ba0: /* original 4008, guest PC 0x0c094ba0 */
if(!s->budget--) { s->failed_pc=0x0c094ba0u; return 0; }
r[0]<<=2;
goto P_0c094ba2;
P_0c094ba2: /* original 313c, guest PC 0x0c094ba2 */
if(!s->budget--) { s->failed_pc=0x0c094ba2u; return 0; }
r[1]+=r[3];
goto P_0c094ba4;
P_0c094ba4: /* original 036e, guest PC 0x0c094ba4 */
if(!s->budget--) { s->failed_pc=0x0c094ba4u; return 0; }
r[3]=read(ram,r[6]+r[0],4);
goto P_0c094ba6;
P_0c094ba6: /* original 7501, guest PC 0x0c094ba6 */
if(!s->budget--) { s->failed_pc=0x0c094ba6u; return 0; }
r[5]+=0x00000001u;
goto P_0c094ba8;
P_0c094ba8: /* original 5231, guest PC 0x0c094ba8 */
if(!s->budget--) { s->failed_pc=0x0c094ba8u; return 0; }
r[2]=read(ram,r[3]+4,4);
goto P_0c094baa;
P_0c094baa: /* original 35c3, guest PC 0x0c094baa */
if(!s->budget--) { s->failed_pc=0x0c094baau; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[5]>=(int32_t)r[12])!=0);
goto P_0c094bac;
P_0c094bac: /* original 5021, guest PC 0x0c094bac */
if(!s->budget--) { s->failed_pc=0x0c094bacu; return 0; }
r[0]=read(ram,r[2]+4,4);
goto P_0c094bae;
P_0c094bae: /* original 2102, guest PC 0x0c094bae */
if(!s->budget--) { s->failed_pc=0x0c094baeu; return 0; }
write(ram,r[1],r[0],4);
goto P_0c094bb0;
P_0c094bb0: /* original 8bea, guest PC 0x0c094bb0 */
if(!s->budget--) { s->failed_pc=0x0c094bb0u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c094b88; }
goto P_0c094bb2;
P_0c094bb2: /* original 6242, guest PC 0x0c094bb2 */
if(!s->budget--) { s->failed_pc=0x0c094bb2u; return 0; }
tmp=read(ram,r[4],4);
r[2]=tmp;
goto P_0c094bb4;
P_0c094bb4: /* original e024, guest PC 0x0c094bb4 */
if(!s->budget--) { s->failed_pc=0x0c094bb4u; return 0; }
r[0]=0x00000024u;
goto P_0c094bb6;
P_0c094bb6: /* original 0e25, guest PC 0x0c094bb6 */
if(!s->budget--) { s->failed_pc=0x0c094bb6u; return 0; }
write(ram,r[14]+r[0],r[2],2);
goto P_0c094bb8;
P_0c094bb8: /* original 7076, guest PC 0x0c094bb8 */
if(!s->budget--) { s->failed_pc=0x0c094bb8u; return 0; }
r[0]+=0x00000076u;
goto P_0c094bba;
P_0c094bba: /* original 5341, guest PC 0x0c094bba */
if(!s->budget--) { s->failed_pc=0x0c094bbau; return 0; }
r[3]=read(ram,r[4]+4,4);
goto P_0c094bbc;
P_0c094bbc: /* original 62e3, guest PC 0x0c094bbc */
if(!s->budget--) { s->failed_pc=0x0c094bbcu; return 0; }
r[2]=r[14];
goto P_0c094bbe;
P_0c094bbe: /* original 7248, guest PC 0x0c094bbe */
if(!s->budget--) { s->failed_pc=0x0c094bbeu; return 0; }
r[2]+=0x00000048u;
goto P_0c094bc0;
P_0c094bc0: /* original 1e3d, guest PC 0x0c094bc0 */
if(!s->budget--) { s->failed_pc=0x0c094bc0u; return 0; }
write(ram,r[14]+52,r[3],4);
goto P_0c094bc2;
P_0c094bc2: /* original 5342, guest PC 0x0c094bc2 */
if(!s->budget--) { s->failed_pc=0x0c094bc2u; return 0; }
r[3]=read(ram,r[4]+8,4);
goto P_0c094bc4;
P_0c094bc4: /* original 2231, guest PC 0x0c094bc4 */
if(!s->budget--) { s->failed_pc=0x0c094bc4u; return 0; }
write(ram,r[2],r[3],2);
goto P_0c094bc6;
P_0c094bc6: /* original 00ec, guest PC 0x0c094bc6 */
if(!s->budget--) { s->failed_pc=0x0c094bc6u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c094bc8;
P_0c094bc8: /* original 8801, guest PC 0x0c094bc8 */
if(!s->budget--) { s->failed_pc=0x0c094bc8u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c094bca;
P_0c094bca: /* original 8b08, guest PC 0x0c094bca */
if(!s->budget--) { s->failed_pc=0x0c094bcau; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c094bde; }
goto P_0c094bcc;
P_0c094bcc: /* original 9071, guest PC 0x0c094bcc */
if(!s->budget--) { s->failed_pc=0x0c094bccu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c094cb2u,2);
goto P_0c094bce;
P_0c094bce: /* original 5344, guest PC 0x0c094bce */
if(!s->budget--) { s->failed_pc=0x0c094bceu; return 0; }
r[3]=read(ram,r[4]+16,4);
goto P_0c094bd0;
P_0c094bd0: /* original 027c, guest PC 0x0c094bd0 */
if(!s->budget--) { s->failed_pc=0x0c094bd0u; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[7]+r[0],1);
goto P_0c094bd2;
P_0c094bd2: /* original 70d0, guest PC 0x0c094bd2 */
if(!s->budget--) { s->failed_pc=0x0c094bd2u; return 0; }
r[0]+=0xffffffd0u;
goto P_0c094bd4;
P_0c094bd4: /* original 622c, guest PC 0x0c094bd4 */
if(!s->budget--) { s->failed_pc=0x0c094bd4u; return 0; }
r[2]=r[2]&255u;
goto P_0c094bd6;
P_0c094bd6: /* original 4208, guest PC 0x0c094bd6 */
if(!s->budget--) { s->failed_pc=0x0c094bd6u; return 0; }
r[2]<<=2;
goto P_0c094bd8;
P_0c094bd8: /* original 323c, guest PC 0x0c094bd8 */
if(!s->budget--) { s->failed_pc=0x0c094bd8u; return 0; }
r[2]+=r[3];
goto P_0c094bda;
P_0c094bda: /* original a003, guest PC 0x0c094bda */
if(!s->budget--) { s->failed_pc=0x0c094bdau; return 0; }
write(ram,r[14]+r[0],r[2],4);
goto P_0c094be4;
P_0c094bdc: /* original 0e26, guest PC 0x0c094bdc */
if(!s->budget--) { s->failed_pc=0x0c094bdcu; return 0; }
write(ram,r[14]+r[0],r[2],4);
goto P_0c094bde;
P_0c094bde: /* original 9069, guest PC 0x0c094bde */
if(!s->budget--) { s->failed_pc=0x0c094bdeu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c094cb4u,2);
goto P_0c094be0;
P_0c094be0: /* original 5144, guest PC 0x0c094be0 */
if(!s->budget--) { s->failed_pc=0x0c094be0u; return 0; }
r[1]=read(ram,r[4]+16,4);
goto P_0c094be2;
P_0c094be2: /* original 0e16, guest PC 0x0c094be2 */
if(!s->budget--) { s->failed_pc=0x0c094be2u; return 0; }
write(ram,r[14]+r[0],r[1],4);
goto P_0c094be4;
P_0c094be4: /* original 9066, guest PC 0x0c094be4 */
if(!s->budget--) { s->failed_pc=0x0c094be4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c094cb4u,2);
goto P_0c094be6;
P_0c094be6: /* original 05ee, guest PC 0x0c094be6 */
if(!s->budget--) { s->failed_pc=0x0c094be6u; return 0; }
r[5]=read(ram,r[14]+r[0],4);
goto P_0c094be8;
P_0c094be8: /* original 70e8, guest PC 0x0c094be8 */
if(!s->budget--) { s->failed_pc=0x0c094be8u; return 0; }
r[0]+=0xffffffe8u;
goto P_0c094bea;
P_0c094bea: /* original 6552, guest PC 0x0c094bea */
if(!s->budget--) { s->failed_pc=0x0c094beau; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c094bec;
P_0c094bec: /* original 0e56, guest PC 0x0c094bec */
if(!s->budget--) { s->failed_pc=0x0c094becu; return 0; }
write(ram,r[14]+r[0],r[5],4);
goto P_0c094bee;
P_0c094bee: /* original e042, guest PC 0x0c094bee */
if(!s->budget--) { s->failed_pc=0x0c094beeu; return 0; }
r[0]=0x00000042u;
goto P_0c094bf0;
P_0c094bf0: /* original 1edf, guest PC 0x0c094bf0 */
if(!s->budget--) { s->failed_pc=0x0c094bf0u; return 0; }
write(ram,r[14]+60,r[13],4);
goto P_0c094bf2;
P_0c094bf2: /* original 0ed5, guest PC 0x0c094bf2 */
if(!s->budget--) { s->failed_pc=0x0c094bf2u; return 0; }
write(ram,r[14]+r[0],r[13],2);
goto P_0c094bf4;
P_0c094bf4: /* original 7056, guest PC 0x0c094bf4 */
if(!s->budget--) { s->failed_pc=0x0c094bf4u; return 0; }
r[0]+=0x00000056u;
goto P_0c094bf6;
P_0c094bf6: /* original 1ede, guest PC 0x0c094bf6 */
if(!s->budget--) { s->failed_pc=0x0c094bf6u; return 0; }
write(ram,r[14]+56,r[13],4);
goto P_0c094bf8;
P_0c094bf8: /* original 0ed5, guest PC 0x0c094bf8 */
if(!s->budget--) { s->failed_pc=0x0c094bf8u; return 0; }
write(ram,r[14]+r[0],r[13],2);
goto P_0c094bfa;
P_0c094bfa: /* original 6042, guest PC 0x0c094bfa */
if(!s->budget--) { s->failed_pc=0x0c094bfau; return 0; }
tmp=read(ram,r[4],4);
r[0]=tmp;
goto P_0c094bfc;
P_0c094bfc: /* original 4008, guest PC 0x0c094bfc */
if(!s->budget--) { s->failed_pc=0x0c094bfcu; return 0; }
r[0]<<=2;
goto P_0c094bfe;
P_0c094bfe: /* original 036e, guest PC 0x0c094bfe */
if(!s->budget--) { s->failed_pc=0x0c094bfeu; return 0; }
r[3]=read(ram,r[6]+r[0],4);
goto P_0c094c00;
P_0c094c00: /* original 2338, guest PC 0x0c094c00 */
if(!s->budget--) { s->failed_pc=0x0c094c00u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c094c02;
P_0c094c02: /* original 8906, guest PC 0x0c094c02 */
if(!s->budget--) { s->failed_pc=0x0c094c02u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c094c12; }
goto P_0c094c04;
P_0c094c04: /* original 6042, guest PC 0x0c094c04 */
if(!s->budget--) { s->failed_pc=0x0c094c04u; return 0; }
tmp=read(ram,r[4],4);
r[0]=tmp;
goto P_0c094c06;
P_0c094c06: /* original 4008, guest PC 0x0c094c06 */
if(!s->budget--) { s->failed_pc=0x0c094c06u; return 0; }
r[0]<<=2;
goto P_0c094c08;
P_0c094c08: /* original 006e, guest PC 0x0c094c08 */
if(!s->budget--) { s->failed_pc=0x0c094c08u; return 0; }
r[0]=read(ram,r[6]+r[0],4);
goto P_0c094c0a;
P_0c094c0a: /* original 5001, guest PC 0x0c094c0a */
if(!s->budget--) { s->failed_pc=0x0c094c0au; return 0; }
r[0]=read(ram,r[0]+4,4);
goto P_0c094c0c;
P_0c094c0c: /* original 8504, guest PC 0x0c094c0c */
if(!s->budget--) { s->failed_pc=0x0c094c0cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[0]+8,2);
goto P_0c094c0e;
P_0c094c0e: /* original a005, guest PC 0x0c094c0e */
if(!s->budget--) { s->failed_pc=0x0c094c0eu; return 0; }
write(ram,r[14]+30,r[0],2);
goto P_0c094c1c;
P_0c094c10: /* original 81ef, guest PC 0x0c094c10 */
if(!s->budget--) { s->failed_pc=0x0c094c10u; return 0; }
write(ram,r[14]+30,r[0],2);
goto P_0c094c12;
P_0c094c12: /* original 62e2, guest PC 0x0c094c12 */
if(!s->budget--) { s->failed_pc=0x0c094c12u; return 0; }
tmp=read(ram,r[14],4);
r[2]=tmp;
goto P_0c094c14;
P_0c094c14: /* original e3fe, guest PC 0x0c094c14 */
if(!s->budget--) { s->failed_pc=0x0c094c14u; return 0; }
r[3]=0xfffffffeu;
goto P_0c094c16;
P_0c094c16: /* original 2239, guest PC 0x0c094c16 */
if(!s->budget--) { s->failed_pc=0x0c094c16u; return 0; }
r[2]&=r[3];
goto P_0c094c18;
P_0c094c18: /* original a045, guest PC 0x0c094c18 */
if(!s->budget--) { s->failed_pc=0x0c094c18u; return 0; }
write(ram,r[14],r[2],4);
goto P_0c094ca6;
P_0c094c1a: /* original 2e22, guest PC 0x0c094c1a */
if(!s->budget--) { s->failed_pc=0x0c094c1au; return 0; }
write(ram,r[14],r[2],4);
goto P_0c094c1c;
P_0c094c1c: /* original 904b, guest PC 0x0c094c1c */
if(!s->budget--) { s->failed_pc=0x0c094c1cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c094cb6u,2);
goto P_0c094c1e;
P_0c094c1e: /* original 0ed4, guest PC 0x0c094c1e */
if(!s->budget--) { s->failed_pc=0x0c094c1eu; return 0; }
write(ram,r[14]+r[0],r[13],1);
goto P_0c094c20;
P_0c094c20: /* original 8451, guest PC 0x0c094c20 */
if(!s->budget--) { s->failed_pc=0x0c094c20u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[5]+1,1);
goto P_0c094c22;
P_0c094c22: /* original 6450, guest PC 0x0c094c22 */
if(!s->budget--) { s->failed_pc=0x0c094c22u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[5],1);
r[4]=tmp;
goto P_0c094c24;
P_0c094c24: /* original 660c, guest PC 0x0c094c24 */
if(!s->budget--) { s->failed_pc=0x0c094c24u; return 0; }
r[6]=r[0]&255u;
goto P_0c094c26;
P_0c094c26: /* original 8551, guest PC 0x0c094c26 */
if(!s->budget--) { s->failed_pc=0x0c094c26u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[5]+2,2);
goto P_0c094c28;
P_0c094c28: /* original 644c, guest PC 0x0c094c28 */
if(!s->budget--) { s->failed_pc=0x0c094c28u; return 0; }
r[4]=r[4]&255u;
goto P_0c094c2a;
P_0c094c2a: /* original 6303, guest PC 0x0c094c2a */
if(!s->budget--) { s->failed_pc=0x0c094c2au; return 0; }
r[3]=r[0];
goto P_0c094c2c;
P_0c094c2c: /* original 9044, guest PC 0x0c094c2c */
if(!s->budget--) { s->failed_pc=0x0c094c2cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c094cb8u,2);
goto P_0c094c2e;
P_0c094c2e: /* original 0e34, guest PC 0x0c094c2e */
if(!s->budget--) { s->failed_pc=0x0c094c2eu; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c094c30;
P_0c094c30: /* original 7003, guest PC 0x0c094c30 */
if(!s->budget--) { s->failed_pc=0x0c094c30u; return 0; }
r[0]+=0x00000003u;
goto P_0c094c32;
P_0c094c32: /* original 465a, guest PC 0x0c094c32 */
if(!s->budget--) { s->failed_pc=0x0c094c32u; return 0; }
r[53]=r[6];
goto P_0c094c34;
P_0c094c34: /* original f32d, guest PC 0x0c094c34 */
if(!s->budget--) { s->failed_pc=0x0c094c34u; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c094c36;
P_0c094c36: /* original f43c, guest PC 0x0c094c36 */
if(!s->budget--) { s->failed_pc=0x0c094c36u; return 0; }
vf3_matrix_move(s,4,3);
goto P_0c094c38;
P_0c094c38: /* original f49d, guest PC 0x0c094c38 */
if(!s->budget--) { s->failed_pc=0x0c094c38u; return 0; }
fr[4]=0x3f800000u;
goto P_0c094c3a;
P_0c094c3a: /* original f433, guest PC 0x0c094c3a */
if(!s->budget--) { s->failed_pc=0x0c094c3au; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'/');
goto P_0c094c3c;
P_0c094c3c: /* original fe47, guest PC 0x0c094c3c */
if(!s->budget--) { s->failed_pc=0x0c094c3cu; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c094c3e;
P_0c094c3e: /* original 7004, guest PC 0x0c094c3e */
if(!s->budget--) { s->failed_pc=0x0c094c3eu; return 0; }
r[0]+=0x00000004u;
goto P_0c094c40;
P_0c094c40: /* original f38d, guest PC 0x0c094c40 */
if(!s->budget--) { s->failed_pc=0x0c094c40u; return 0; }
fr[3]=0;
goto P_0c094c42;
P_0c094c42: /* original fe37, guest PC 0x0c094c42 */
if(!s->budget--) { s->failed_pc=0x0c094c42u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c094c44;
P_0c094c44: /* original e068, guest PC 0x0c094c44 */
if(!s->budget--) { s->failed_pc=0x0c094c44u; return 0; }
r[0]=0x00000068u;
goto P_0c094c46;
P_0c094c46: /* original 03ee, guest PC 0x0c094c46 */
if(!s->budget--) { s->failed_pc=0x0c094c46u; return 0; }
r[3]=read(ram,r[14]+r[0],4);
goto P_0c094c48;
P_0c094c48: /* original e074, guest PC 0x0c094c48 */
if(!s->budget--) { s->failed_pc=0x0c094c48u; return 0; }
r[0]=0x00000074u;
goto P_0c094c4a;
P_0c094c4a: /* original 0e36, guest PC 0x0c094c4a */
if(!s->budget--) { s->failed_pc=0x0c094c4au; return 0; }
write(ram,r[14]+r[0],r[3],4);
goto P_0c094c4c;
P_0c094c4c: /* original 85ef, guest PC 0x0c094c4c */
if(!s->budget--) { s->failed_pc=0x0c094c4cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+30,2);
goto P_0c094c4e;
P_0c094c4e: /* original 9134, guest PC 0x0c094c4e */
if(!s->budget--) { s->failed_pc=0x0c094c4eu; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c094cbau,2);
goto P_0c094c50;
P_0c094c50: /* original 6303, guest PC 0x0c094c50 */
if(!s->budget--) { s->failed_pc=0x0c094c50u; return 0; }
r[3]=r[0];
goto P_0c094c52;
P_0c094c52: /* original 4000, guest PC 0x0c094c52 */
if(!s->budget--) { s->failed_pc=0x0c094c52u; return 0; }
r[17]=(r[17]&~1u)|((r[0]>>31)!=0);
r[0]<<=1;
goto P_0c094c54;
P_0c094c54: /* original 303c, guest PC 0x0c094c54 */
if(!s->budget--) { s->failed_pc=0x0c094c54u; return 0; }
r[0]+=r[3];
goto P_0c094c56;
P_0c094c56: /* original 4008, guest PC 0x0c094c56 */
if(!s->budget--) { s->failed_pc=0x0c094c56u; return 0; }
r[0]<<=2;
goto P_0c094c58;
P_0c094c58: /* original 31ec, guest PC 0x0c094c58 */
if(!s->budget--) { s->failed_pc=0x0c094c58u; return 0; }
r[1]+=r[14];
goto P_0c094c5a;
P_0c094c5a: /* original 4000, guest PC 0x0c094c5a */
if(!s->budget--) { s->failed_pc=0x0c094c5au; return 0; }
r[17]=(r[17]&~1u)|((r[0]>>31)!=0);
r[0]<<=1;
goto P_0c094c5c;
P_0c094c5c: /* original 63e3, guest PC 0x0c094c5c */
if(!s->budget--) { s->failed_pc=0x0c094c5cu; return 0; }
r[3]=r[14];
goto P_0c094c5e;
P_0c094c5e: /* original 734c, guest PC 0x0c094c5e */
if(!s->budget--) { s->failed_pc=0x0c094c5eu; return 0; }
r[3]+=0x0000004cu;
goto P_0c094c60;
P_0c094c60: /* original 4408, guest PC 0x0c094c60 */
if(!s->budget--) { s->failed_pc=0x0c094c60u; return 0; }
r[4]<<=2;
goto P_0c094c62;
P_0c094c62: /* original 2102, guest PC 0x0c094c62 */
if(!s->budget--) { s->failed_pc=0x0c094c62u; return 0; }
write(ram,r[1],r[0],4);
goto P_0c094c64;
P_0c094c64: /* original 343c, guest PC 0x0c094c64 */
if(!s->budget--) { s->failed_pc=0x0c094c64u; return 0; }
r[4]+=r[3];
goto P_0c094c66;
P_0c094c66: /* original 63e3, guest PC 0x0c094c66 */
if(!s->budget--) { s->failed_pc=0x0c094c66u; return 0; }
r[3]=r[14];
goto P_0c094c68;
P_0c094c68: /* original 6242, guest PC 0x0c094c68 */
if(!s->budget--) { s->failed_pc=0x0c094c68u; return 0; }
tmp=read(ram,r[4],4);
r[2]=tmp;
goto P_0c094c6a;
P_0c094c6a: /* original e07c, guest PC 0x0c094c6a */
if(!s->budget--) { s->failed_pc=0x0c094c6au; return 0; }
r[0]=0x0000007cu;
goto P_0c094c6c;
P_0c094c6c: /* original 734c, guest PC 0x0c094c6c */
if(!s->budget--) { s->failed_pc=0x0c094c6cu; return 0; }
r[3]+=0x0000004cu;
goto P_0c094c6e;
P_0c094c6e: /* original 0e26, guest PC 0x0c094c6e */
if(!s->budget--) { s->failed_pc=0x0c094c6eu; return 0; }
write(ram,r[14]+r[0],r[2],4);
goto P_0c094c70;
P_0c094c70: /* original e078, guest PC 0x0c094c70 */
if(!s->budget--) { s->failed_pc=0x0c094c70u; return 0; }
r[0]=0x00000078u;
goto P_0c094c72;
P_0c094c72: /* original 6232, guest PC 0x0c094c72 */
if(!s->budget--) { s->failed_pc=0x0c094c72u; return 0; }
tmp=read(ram,r[3],4);
r[2]=tmp;
goto P_0c094c74;
P_0c094c74: /* original 0e26, guest PC 0x0c094c74 */
if(!s->budget--) { s->failed_pc=0x0c094c74u; return 0; }
write(ram,r[14]+r[0],r[2],4);
goto P_0c094c76;
P_0c094c76: /* original 85ef, guest PC 0x0c094c76 */
if(!s->budget--) { s->failed_pc=0x0c094c76u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+30,2);
goto P_0c094c78;
P_0c094c78: /* original 6703, guest PC 0x0c094c78 */
if(!s->budget--) { s->failed_pc=0x0c094c78u; return 0; }
r[7]=r[0];
goto P_0c094c7a;
P_0c094c7a: /* original e074, guest PC 0x0c094c7a */
if(!s->budget--) { s->failed_pc=0x0c094c7au; return 0; }
r[0]=0x00000074u;
goto P_0c094c7c;
P_0c094c7c: /* original 06ee, guest PC 0x0c094c7c */
if(!s->budget--) { s->failed_pc=0x0c094c7cu; return 0; }
r[6]=read(ram,r[14]+r[0],4);
goto P_0c094c7e;
P_0c094c7e: /* original e078, guest PC 0x0c094c7e */
if(!s->budget--) { s->failed_pc=0x0c094c7eu; return 0; }
r[0]=0x00000078u;
goto P_0c094c80;
P_0c094c80: /* original 05ee, guest PC 0x0c094c80 */
if(!s->budget--) { s->failed_pc=0x0c094c80u; return 0; }
r[5]=read(ram,r[14]+r[0],4);
goto P_0c094c82;
P_0c094c82: /* original be5b, guest PC 0x0c094c82 */
if(!s->budget--) { s->failed_pc=0x0c094c82u; return 0; }
target=code_base|0x0c09493cu; r[16]=code_base|0x0c094c86u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c094c86u) { target=s->pc; goto dispatch; }
goto P_0c094c86;
P_0c094c84: /* original 64e3, guest PC 0x0c094c84 */
if(!s->budget--) { s->failed_pc=0x0c094c84u; return 0; }
r[4]=r[14];
goto P_0c094c86;
P_0c094c86: /* original e050, guest PC 0x0c094c86 */
if(!s->budget--) { s->failed_pc=0x0c094c86u; return 0; }
r[0]=0x00000050u;
goto P_0c094c88;
P_0c094c88: /* original 02ee, guest PC 0x0c094c88 */
if(!s->budget--) { s->failed_pc=0x0c094c88u; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c094c8a;
P_0c094c8a: /* original e070, guest PC 0x0c094c8a */
if(!s->budget--) { s->failed_pc=0x0c094c8au; return 0; }
r[0]=0x00000070u;
goto P_0c094c8c;
P_0c094c8c: /* original 0e26, guest PC 0x0c094c8c */
if(!s->budget--) { s->failed_pc=0x0c094c8cu; return 0; }
write(ram,r[14]+r[0],r[2],4);
goto P_0c094c8e;
P_0c094c8e: /* original e050, guest PC 0x0c094c8e */
if(!s->budget--) { s->failed_pc=0x0c094c8eu; return 0; }
r[0]=0x00000050u;
goto P_0c094c90;
P_0c094c90: /* original 03ee, guest PC 0x0c094c90 */
if(!s->budget--) { s->failed_pc=0x0c094c90u; return 0; }
r[3]=read(ram,r[14]+r[0],4);
goto P_0c094c92;
P_0c094c92: /* original e06c, guest PC 0x0c094c92 */
if(!s->budget--) { s->failed_pc=0x0c094c92u; return 0; }
r[0]=0x0000006cu;
goto P_0c094c94;
P_0c094c94: /* original 0e36, guest PC 0x0c094c94 */
if(!s->budget--) { s->failed_pc=0x0c094c94u; return 0; }
write(ram,r[14]+r[0],r[3],4);
goto P_0c094c96;
P_0c094c96: /* original 50ed, guest PC 0x0c094c96 */
if(!s->budget--) { s->failed_pc=0x0c094c96u; return 0; }
r[0]=read(ram,r[14]+52,4);
goto P_0c094c98;
P_0c094c98: /* original 881c, guest PC 0x0c094c98 */
if(!s->budget--) { s->failed_pc=0x0c094c98u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000001cu)!=0);
goto P_0c094c9a;
P_0c094c9a: /* original 8f02, guest PC 0x0c094c9a */
if(!s->budget--) { s->failed_pc=0x0c094c9au; return 0; }
cond=r[17]&1u;
r[4]=r[0];
if(!cond) { goto P_0c094ca2; }
goto P_0c094c9e;
P_0c094c9c: /* original 6403, guest PC 0x0c094c9c */
if(!s->budget--) { s->failed_pc=0x0c094c9cu; return 0; }
r[4]=r[0];
goto P_0c094c9e;
P_0c094c9e: /* original d20a, guest PC 0x0c094c9e */
if(!s->budget--) { s->failed_pc=0x0c094c9eu; return 0; }
r[2]=read(ram,0x0c094cc8u,4);
goto P_0c094ca0;
P_0c094ca0: /* original 1e23, guest PC 0x0c094ca0 */
if(!s->budget--) { s->failed_pc=0x0c094ca0u; return 0; }
write(ram,r[14]+12,r[2],4);
goto P_0c094ca2;
P_0c094ca2: /* original 900b, guest PC 0x0c094ca2 */
if(!s->budget--) { s->failed_pc=0x0c094ca2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c094cbcu,2);
goto P_0c094ca4;
P_0c094ca4: /* original 0ed6, guest PC 0x0c094ca4 */
if(!s->budget--) { s->failed_pc=0x0c094ca4u; return 0; }
write(ram,r[14]+r[0],r[13],4);
goto P_0c094ca6;
P_0c094ca6: /* original 4f26, guest PC 0x0c094ca6 */
if(!s->budget--) { s->failed_pc=0x0c094ca6u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c094ca8;
P_0c094ca8: /* original 6cf6, guest PC 0x0c094ca8 */
if(!s->budget--) { s->failed_pc=0x0c094ca8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c094caa;
P_0c094caa: /* original 6df6, guest PC 0x0c094caa */
if(!s->budget--) { s->failed_pc=0x0c094caau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c094cac;
P_0c094cac: /* original 000b, guest PC 0x0c094cac */
if(!s->budget--) { s->failed_pc=0x0c094cacu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c094cae: /* original 6ef6, guest PC 0x0c094cae */
if(!s->budget--) { s->failed_pc=0x0c094caeu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c094cb0u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c094cb0u; return 0; } return 1;
P_0c094da8: /* original 2fe6, guest PC 0x0c094da8 */
if(!s->budget--) { s->failed_pc=0x0c094da8u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c094daa;
P_0c094daa: /* original 6643, guest PC 0x0c094daa */
if(!s->budget--) { s->failed_pc=0x0c094daau; return 0; }
r[6]=r[4];
goto P_0c094dac;
P_0c094dac: /* original 2fd6, guest PC 0x0c094dac */
if(!s->budget--) { s->failed_pc=0x0c094dacu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c094dae;
P_0c094dae: /* original 2fc6, guest PC 0x0c094dae */
if(!s->budget--) { s->failed_pc=0x0c094daeu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c094db0;
P_0c094db0: /* original 6c43, guest PC 0x0c094db0 */
if(!s->budget--) { s->failed_pc=0x0c094db0u; return 0; }
r[12]=r[4];
goto P_0c094db2;
P_0c094db2: /* original 9072, guest PC 0x0c094db2 */
if(!s->budget--) { s->failed_pc=0x0c094db2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c094e9au,2);
goto P_0c094db4;
P_0c094db4: /* original d73a, guest PC 0x0c094db4 */
if(!s->budget--) { s->failed_pc=0x0c094db4u; return 0; }
r[7]=read(ram,0x0c094ea0u,4);
goto P_0c094db6;
P_0c094db6: /* original 956f, guest PC 0x0c094db6 */
if(!s->budget--) { s->failed_pc=0x0c094db6u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c094e98u,2);
goto P_0c094db8;
P_0c094db8: /* original 077e, guest PC 0x0c094db8 */
if(!s->budget--) { s->failed_pc=0x0c094db8u; return 0; }
r[7]=read(ram,r[7]+r[0],4);
goto P_0c094dba;
P_0c094dba: /* original 8464, guest PC 0x0c094dba */
if(!s->budget--) { s->failed_pc=0x0c094dbau; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[6]+4,1);
goto P_0c094dbc;
P_0c094dbc: /* original 3c5c, guest PC 0x0c094dbc */
if(!s->budget--) { s->failed_pc=0x0c094dbcu; return 0; }
r[12]+=r[5];
goto P_0c094dbe;
P_0c094dbe: /* original 6dc3, guest PC 0x0c094dbe */
if(!s->budget--) { s->failed_pc=0x0c094dbeu; return 0; }
r[13]=r[12];
goto P_0c094dc0;
P_0c094dc0: /* original 3d5c, guest PC 0x0c094dc0 */
if(!s->budget--) { s->failed_pc=0x0c094dc0u; return 0; }
r[13]+=r[5];
goto P_0c094dc2;
P_0c094dc2: /* original 6303, guest PC 0x0c094dc2 */
if(!s->budget--) { s->failed_pc=0x0c094dc2u; return 0; }
r[3]=r[0];
goto P_0c094dc4;
P_0c094dc4: /* original 8474, guest PC 0x0c094dc4 */
if(!s->budget--) { s->failed_pc=0x0c094dc4u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[7]+4,1);
goto P_0c094dc6;
P_0c094dc6: /* original 4f22, guest PC 0x0c094dc6 */
if(!s->budget--) { s->failed_pc=0x0c094dc6u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c094dc8;
P_0c094dc8: /* original 6ed3, guest PC 0x0c094dc8 */
if(!s->budget--) { s->failed_pc=0x0c094dc8u; return 0; }
r[14]=r[13];
goto P_0c094dca;
P_0c094dca: /* original 3e5c, guest PC 0x0c094dca */
if(!s->budget--) { s->failed_pc=0x0c094dcau; return 0; }
r[14]+=r[5];
goto P_0c094dcc;
P_0c094dcc: /* original 3300, guest PC 0x0c094dcc */
if(!s->budget--) { s->failed_pc=0x0c094dccu; return 0; }
r[17]=(r[17]&~1u)|((r[3]==r[0])!=0);
goto P_0c094dce;
P_0c094dce: /* original 61e3, guest PC 0x0c094dce */
if(!s->budget--) { s->failed_pc=0x0c094dceu; return 0; }
r[1]=r[14];
goto P_0c094dd0;
P_0c094dd0: /* original 8f47, guest PC 0x0c094dd0 */
if(!s->budget--) { s->failed_pc=0x0c094dd0u; return 0; }
cond=r[17]&1u;
r[1]+=r[5];
if(!cond) { goto P_0c094e62; }
goto P_0c094dd4;
P_0c094dd2: /* original 315c, guest PC 0x0c094dd2 */
if(!s->budget--) { s->failed_pc=0x0c094dd2u; return 0; }
r[1]+=r[5];
goto P_0c094dd4;
P_0c094dd4: /* original e060, guest PC 0x0c094dd4 */
if(!s->budget--) { s->failed_pc=0x0c094dd4u; return 0; }
r[0]=0x00000060u;
goto P_0c094dd6;
P_0c094dd6: /* original 057c, guest PC 0x0c094dd6 */
if(!s->budget--) { s->failed_pc=0x0c094dd6u; return 0; }
r[5]=(uint32_t)(int32_t)(int8_t)read(ram,r[7]+r[0],1);
goto P_0c094dd8;
P_0c094dd8: /* original 605c, guest PC 0x0c094dd8 */
if(!s->budget--) { s->failed_pc=0x0c094dd8u; return 0; }
r[0]=r[5]&255u;
goto P_0c094dda;
P_0c094dda: /* original 8807, guest PC 0x0c094dda */
if(!s->budget--) { s->failed_pc=0x0c094ddau; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000007u)!=0);
goto P_0c094ddc;
P_0c094ddc: /* original 8d0a, guest PC 0x0c094ddc */
if(!s->budget--) { s->failed_pc=0x0c094ddcu; return 0; }
cond=r[17]&1u;
r[5]=r[0];
if(cond) { goto P_0c094df4; }
goto P_0c094de0;
P_0c094dde: /* original 6503, guest PC 0x0c094dde */
if(!s->budget--) { s->failed_pc=0x0c094ddeu; return 0; }
r[5]=r[0];
goto P_0c094de0;
P_0c094de0: /* original 6053, guest PC 0x0c094de0 */
if(!s->budget--) { s->failed_pc=0x0c094de0u; return 0; }
r[0]=r[5];
goto P_0c094de2;
P_0c094de2: /* original 8805, guest PC 0x0c094de2 */
if(!s->budget--) { s->failed_pc=0x0c094de2u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000005u)!=0);
goto P_0c094de4;
P_0c094de4: /* original 8906, guest PC 0x0c094de4 */
if(!s->budget--) { s->failed_pc=0x0c094de4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c094df4; }
goto P_0c094de6;
P_0c094de6: /* original 6053, guest PC 0x0c094de6 */
if(!s->budget--) { s->failed_pc=0x0c094de6u; return 0; }
r[0]=r[5];
goto P_0c094de8;
P_0c094de8: /* original 8812, guest PC 0x0c094de8 */
if(!s->budget--) { s->failed_pc=0x0c094de8u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000012u)!=0);
goto P_0c094dea;
P_0c094dea: /* original 8903, guest PC 0x0c094dea */
if(!s->budget--) { s->failed_pc=0x0c094deau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c094df4; }
goto P_0c094dec;
P_0c094dec: /* original 6262, guest PC 0x0c094dec */
if(!s->budget--) { s->failed_pc=0x0c094decu; return 0; }
tmp=read(ram,r[6],4);
r[2]=tmp;
goto P_0c094dee;
P_0c094dee: /* original e3fe, guest PC 0x0c094dee */
if(!s->budget--) { s->failed_pc=0x0c094deeu; return 0; }
r[3]=0xfffffffeu;
goto P_0c094df0;
P_0c094df0: /* original 2239, guest PC 0x0c094df0 */
if(!s->budget--) { s->failed_pc=0x0c094df0u; return 0; }
r[2]&=r[3];
goto P_0c094df2;
P_0c094df2: /* original 2622, guest PC 0x0c094df2 */
if(!s->budget--) { s->failed_pc=0x0c094df2u; return 0; }
write(ram,r[6],r[2],4);
goto P_0c094df4;
P_0c094df4: /* original 6053, guest PC 0x0c094df4 */
if(!s->budget--) { s->failed_pc=0x0c094df4u; return 0; }
r[0]=r[5];
goto P_0c094df6;
P_0c094df6: /* original 8807, guest PC 0x0c094df6 */
if(!s->budget--) { s->failed_pc=0x0c094df6u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000007u)!=0);
goto P_0c094df8;
P_0c094df8: /* original 8b08, guest PC 0x0c094df8 */
if(!s->budget--) { s->failed_pc=0x0c094df8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c094e0c; }
goto P_0c094dfa;
P_0c094dfa: /* original 904f, guest PC 0x0c094dfa */
if(!s->budget--) { s->failed_pc=0x0c094dfau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c094e9cu,2);
goto P_0c094dfc;
P_0c094dfc: /* original 007c, guest PC 0x0c094dfc */
if(!s->budget--) { s->failed_pc=0x0c094dfcu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[7]+r[0],1);
goto P_0c094dfe;
P_0c094dfe: /* original 600c, guest PC 0x0c094dfe */
if(!s->budget--) { s->failed_pc=0x0c094dfeu; return 0; }
r[0]=r[0]&255u;
goto P_0c094e00;
P_0c094e00: /* original 8801, guest PC 0x0c094e00 */
if(!s->budget--) { s->failed_pc=0x0c094e00u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c094e02;
P_0c094e02: /* original 8b03, guest PC 0x0c094e02 */
if(!s->budget--) { s->failed_pc=0x0c094e02u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c094e0c; }
goto P_0c094e04;
P_0c094e04: /* original 6262, guest PC 0x0c094e04 */
if(!s->budget--) { s->failed_pc=0x0c094e04u; return 0; }
tmp=read(ram,r[6],4);
r[2]=tmp;
goto P_0c094e06;
P_0c094e06: /* original e3fe, guest PC 0x0c094e06 */
if(!s->budget--) { s->failed_pc=0x0c094e06u; return 0; }
r[3]=0xfffffffeu;
goto P_0c094e08;
P_0c094e08: /* original 2239, guest PC 0x0c094e08 */
if(!s->budget--) { s->failed_pc=0x0c094e08u; return 0; }
r[2]&=r[3];
goto P_0c094e0a;
P_0c094e0a: /* original 2622, guest PC 0x0c094e0a */
if(!s->budget--) { s->failed_pc=0x0c094e0au; return 0; }
write(ram,r[6],r[2],4);
goto P_0c094e0c;
P_0c094e0c: /* original d025, guest PC 0x0c094e0c */
if(!s->budget--) { s->failed_pc=0x0c094e0cu; return 0; }
r[0]=read(ram,0x0c094ea4u,4);
goto P_0c094e0e;
P_0c094e0e: /* original 6753, guest PC 0x0c094e0e */
if(!s->budget--) { s->failed_pc=0x0c094e0eu; return 0; }
r[7]=r[5];
goto P_0c094e10;
P_0c094e10: /* original 4708, guest PC 0x0c094e10 */
if(!s->budget--) { s->failed_pc=0x0c094e10u; return 0; }
r[7]<<=2;
goto P_0c094e12;
P_0c094e12: /* original 077e, guest PC 0x0c094e12 */
if(!s->budget--) { s->failed_pc=0x0c094e12u; return 0; }
r[7]=read(ram,r[7]+r[0],4);
goto P_0c094e14;
P_0c094e14: /* original 2778, guest PC 0x0c094e14 */
if(!s->budget--) { s->failed_pc=0x0c094e14u; return 0; }
r[17]=(r[17]&~1u)|(((r[7]&r[7])==0)!=0);
goto P_0c094e16;
P_0c094e16: /* original 8924, guest PC 0x0c094e16 */
if(!s->budget--) { s->failed_pc=0x0c094e16u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c094e62; }
goto P_0c094e18;
P_0c094e18: /* original 6376, guest PC 0x0c094e18 */
if(!s->budget--) { s->failed_pc=0x0c094e18u; return 0; }
tmp=read(ram,r[7],4);
r[7]+=4;
r[3]=tmp;
goto P_0c094e1a;
P_0c094e1a: /* original 1634, guest PC 0x0c094e1a */
if(!s->budget--) { s->failed_pc=0x0c094e1au; return 0; }
write(ram,r[6]+16,r[3],4);
goto P_0c094e1c;
P_0c094e1c: /* original 6376, guest PC 0x0c094e1c */
if(!s->budget--) { s->failed_pc=0x0c094e1cu; return 0; }
tmp=read(ram,r[7],4);
r[7]+=4;
r[3]=tmp;
goto P_0c094e1e;
P_0c094e1e: /* original 1c34, guest PC 0x0c094e1e */
if(!s->budget--) { s->failed_pc=0x0c094e1eu; return 0; }
write(ram,r[12]+16,r[3],4);
goto P_0c094e20;
P_0c094e20: /* original 6376, guest PC 0x0c094e20 */
if(!s->budget--) { s->failed_pc=0x0c094e20u; return 0; }
tmp=read(ram,r[7],4);
r[7]+=4;
r[3]=tmp;
goto P_0c094e22;
P_0c094e22: /* original 1d34, guest PC 0x0c094e22 */
if(!s->budget--) { s->failed_pc=0x0c094e22u; return 0; }
write(ram,r[13]+16,r[3],4);
goto P_0c094e24;
P_0c094e24: /* original 6376, guest PC 0x0c094e24 */
if(!s->budget--) { s->failed_pc=0x0c094e24u; return 0; }
tmp=read(ram,r[7],4);
r[7]+=4;
r[3]=tmp;
goto P_0c094e26;
P_0c094e26: /* original 1e34, guest PC 0x0c094e26 */
if(!s->budget--) { s->failed_pc=0x0c094e26u; return 0; }
write(ram,r[14]+16,r[3],4);
goto P_0c094e28;
P_0c094e28: /* original 6272, guest PC 0x0c094e28 */
if(!s->budget--) { s->failed_pc=0x0c094e28u; return 0; }
tmp=read(ram,r[7],4);
r[2]=tmp;
goto P_0c094e2a;
P_0c094e2a: /* original 6713, guest PC 0x0c094e2a */
if(!s->budget--) { s->failed_pc=0x0c094e2au; return 0; }
r[7]=r[1];
goto P_0c094e2c;
P_0c094e2c: /* original 1124, guest PC 0x0c094e2c */
if(!s->budget--) { s->failed_pc=0x0c094e2cu; return 0; }
write(ram,r[1]+16,r[2],4);
goto P_0c094e2e;
P_0c094e2e: /* original 1655, guest PC 0x0c094e2e */
if(!s->budget--) { s->failed_pc=0x0c094e2eu; return 0; }
write(ram,r[6]+20,r[5],4);
goto P_0c094e30;
P_0c094e30: /* original 1c55, guest PC 0x0c094e30 */
if(!s->budget--) { s->failed_pc=0x0c094e30u; return 0; }
write(ram,r[12]+20,r[5],4);
goto P_0c094e32;
P_0c094e32: /* original 1d55, guest PC 0x0c094e32 */
if(!s->budget--) { s->failed_pc=0x0c094e32u; return 0; }
write(ram,r[13]+20,r[5],4);
goto P_0c094e34;
P_0c094e34: /* original 1e55, guest PC 0x0c094e34 */
if(!s->budget--) { s->failed_pc=0x0c094e34u; return 0; }
write(ram,r[14]+20,r[5],4);
goto P_0c094e36;
P_0c094e36: /* original 1155, guest PC 0x0c094e36 */
if(!s->budget--) { s->failed_pc=0x0c094e36u; return 0; }
write(ram,r[1]+20,r[5],4);
goto P_0c094e38;
P_0c094e38: /* original 6563, guest PC 0x0c094e38 */
if(!s->budget--) { s->failed_pc=0x0c094e38u; return 0; }
r[5]=r[6];
goto P_0c094e3a;
P_0c094e3a: /* original d31b, guest PC 0x0c094e3a */
if(!s->budget--) { s->failed_pc=0x0c094e3au; return 0; }
r[3]=read(ram,0x0c094ea8u,4);
goto P_0c094e3c;
P_0c094e3c: /* original 1633, guest PC 0x0c094e3c */
if(!s->budget--) { s->failed_pc=0x0c094e3cu; return 0; }
write(ram,r[6]+12,r[3],4);
goto P_0c094e3e;
P_0c094e3e: /* original e610, guest PC 0x0c094e3e */
if(!s->budget--) { s->failed_pc=0x0c094e3eu; return 0; }
r[6]=0x00000010u;
goto P_0c094e40;
P_0c094e40: /* original 6352, guest PC 0x0c094e40 */
if(!s->budget--) { s->failed_pc=0x0c094e40u; return 0; }
tmp=read(ram,r[5],4);
r[3]=tmp;
goto P_0c094e42;
P_0c094e42: /* original 76ff, guest PC 0x0c094e42 */
if(!s->budget--) { s->failed_pc=0x0c094e42u; return 0; }
r[6]+=0xffffffffu;
goto P_0c094e44;
P_0c094e44: /* original 2668, guest PC 0x0c094e44 */
if(!s->budget--) { s->failed_pc=0x0c094e44u; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[6])==0)!=0);
goto P_0c094e46;
P_0c094e46: /* original 2c32, guest PC 0x0c094e46 */
if(!s->budget--) { s->failed_pc=0x0c094e46u; return 0; }
write(ram,r[12],r[3],4);
goto P_0c094e48;
P_0c094e48: /* original 7c04, guest PC 0x0c094e48 */
if(!s->budget--) { s->failed_pc=0x0c094e48u; return 0; }
r[12]+=0x00000004u;
goto P_0c094e4a;
P_0c094e4a: /* original 6352, guest PC 0x0c094e4a */
if(!s->budget--) { s->failed_pc=0x0c094e4au; return 0; }
tmp=read(ram,r[5],4);
r[3]=tmp;
goto P_0c094e4c;
P_0c094e4c: /* original 2d32, guest PC 0x0c094e4c */
if(!s->budget--) { s->failed_pc=0x0c094e4cu; return 0; }
write(ram,r[13],r[3],4);
goto P_0c094e4e;
P_0c094e4e: /* original 7d04, guest PC 0x0c094e4e */
if(!s->budget--) { s->failed_pc=0x0c094e4eu; return 0; }
r[13]+=0x00000004u;
goto P_0c094e50;
P_0c094e50: /* original 6352, guest PC 0x0c094e50 */
if(!s->budget--) { s->failed_pc=0x0c094e50u; return 0; }
tmp=read(ram,r[5],4);
r[3]=tmp;
goto P_0c094e52;
P_0c094e52: /* original 2e32, guest PC 0x0c094e52 */
if(!s->budget--) { s->failed_pc=0x0c094e52u; return 0; }
write(ram,r[14],r[3],4);
goto P_0c094e54;
P_0c094e54: /* original 7e04, guest PC 0x0c094e54 */
if(!s->budget--) { s->failed_pc=0x0c094e54u; return 0; }
r[14]+=0x00000004u;
goto P_0c094e56;
P_0c094e56: /* original 6356, guest PC 0x0c094e56 */
if(!s->budget--) { s->failed_pc=0x0c094e56u; return 0; }
tmp=read(ram,r[5],4);
r[5]+=4;
r[3]=tmp;
goto P_0c094e58;
P_0c094e58: /* original 2732, guest PC 0x0c094e58 */
if(!s->budget--) { s->failed_pc=0x0c094e58u; return 0; }
write(ram,r[7],r[3],4);
goto P_0c094e5a;
P_0c094e5a: /* original 8ff1, guest PC 0x0c094e5a */
if(!s->budget--) { s->failed_pc=0x0c094e5au; return 0; }
cond=r[17]&1u;
r[7]+=0x00000004u;
if(!cond) { goto P_0c094e40; }
goto P_0c094e5e;
P_0c094e5c: /* original 7704, guest PC 0x0c094e5c */
if(!s->budget--) { s->failed_pc=0x0c094e5cu; return 0; }
r[7]+=0x00000004u;
goto P_0c094e5e;
P_0c094e5e: /* original b005, guest PC 0x0c094e5e */
if(!s->budget--) { s->failed_pc=0x0c094e5eu; return 0; }
target=code_base|0x0c094e6cu; r[16]=code_base|0x0c094e62u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c094e62u) { target=s->pc; goto dispatch; }
goto P_0c094e62;
P_0c094e60: /* original 0009, guest PC 0x0c094e60 */
if(!s->budget--) { s->failed_pc=0x0c094e60u; return 0; }
goto P_0c094e62;
P_0c094e62: /* original 4f26, guest PC 0x0c094e62 */
if(!s->budget--) { s->failed_pc=0x0c094e62u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c094e64;
P_0c094e64: /* original 6cf6, guest PC 0x0c094e64 */
if(!s->budget--) { s->failed_pc=0x0c094e64u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c094e66;
P_0c094e66: /* original 6df6, guest PC 0x0c094e66 */
if(!s->budget--) { s->failed_pc=0x0c094e66u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c094e68;
P_0c094e68: /* original 000b, guest PC 0x0c094e68 */
if(!s->budget--) { s->failed_pc=0x0c094e68u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c094e6a: /* original 6ef6, guest PC 0x0c094e6a */
if(!s->budget--) { s->failed_pc=0x0c094e6au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c094e6cu,s,ram);
unsupported: s->failed_pc=target; return 0;
}
