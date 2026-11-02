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
int vf3_away_batch135_adapter_3(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c0a9c3cu: goto P_0c0a9c3c;
case 0x0c0a9c3eu: goto P_0c0a9c3e;
case 0x0c0a9c40u: goto P_0c0a9c40;
case 0x0c0a9c42u: goto P_0c0a9c42;
case 0x0c0a9c44u: goto P_0c0a9c44;
case 0x0c0a9c46u: goto P_0c0a9c46;
case 0x0c0a9c48u: goto P_0c0a9c48;
case 0x0c0a9c4au: goto P_0c0a9c4a;
case 0x0c0a9c4cu: goto P_0c0a9c4c;
case 0x0c0a9c4eu: goto P_0c0a9c4e;
case 0x0c0a9c50u: goto P_0c0a9c50;
case 0x0c0a9c52u: goto P_0c0a9c52;
case 0x0c0a9c54u: goto P_0c0a9c54;
case 0x0c0a9c56u: goto P_0c0a9c56;
case 0x0c0a9c58u: goto P_0c0a9c58;
case 0x0c0a9c5au: goto P_0c0a9c5a;
case 0x0c0a9c5cu: goto P_0c0a9c5c;
case 0x0c0a9c5eu: goto P_0c0a9c5e;
case 0x0c0a9c60u: goto P_0c0a9c60;
case 0x0c0a9c62u: goto P_0c0a9c62;
case 0x0c0a9c64u: goto P_0c0a9c64;
case 0x0c0a9c66u: goto P_0c0a9c66;
case 0x0c0a9c68u: goto P_0c0a9c68;
case 0x0c0a9c6au: goto P_0c0a9c6a;
case 0x0c0a9c6cu: goto P_0c0a9c6c;
case 0x0c0a9c6eu: goto P_0c0a9c6e;
case 0x0c0a9c70u: goto P_0c0a9c70;
case 0x0c0a9c72u: goto P_0c0a9c72;
case 0x0c0a9c74u: goto P_0c0a9c74;
case 0x0c0a9c76u: goto P_0c0a9c76;
case 0x0c0a9c78u: goto P_0c0a9c78;
case 0x0c0a9c7au: goto P_0c0a9c7a;
case 0x0c0a9c7cu: goto P_0c0a9c7c;
case 0x0c0a9c7eu: goto P_0c0a9c7e;
case 0x0c0a9c80u: goto P_0c0a9c80;
case 0x0c0a9c82u: goto P_0c0a9c82;
case 0x0c0a9c84u: goto P_0c0a9c84;
case 0x0c0a9c86u: goto P_0c0a9c86;
case 0x0c0a9c88u: goto P_0c0a9c88;
case 0x0c0a9c8au: goto P_0c0a9c8a;
case 0x0c0a9c8cu: goto P_0c0a9c8c;
case 0x0c0a9c8eu: goto P_0c0a9c8e;
case 0x0c0a9c90u: goto P_0c0a9c90;
case 0x0c0a9c92u: goto P_0c0a9c92;
case 0x0c0a9c94u: goto P_0c0a9c94;
case 0x0c0a9c96u: goto P_0c0a9c96;
case 0x0c0a9c98u: goto P_0c0a9c98;
case 0x0c0a9c9au: goto P_0c0a9c9a;
case 0x0c0a9c9cu: goto P_0c0a9c9c;
case 0x0c0a9c9eu: goto P_0c0a9c9e;
case 0x0c0a9ca0u: goto P_0c0a9ca0;
case 0x0c0a9ca2u: goto P_0c0a9ca2;
case 0x0c0a9ca4u: goto P_0c0a9ca4;
case 0x0c0a9ca6u: goto P_0c0a9ca6;
case 0x0c0a9ca8u: goto P_0c0a9ca8;
case 0x0c0a9caau: goto P_0c0a9caa;
case 0x0c0a9cacu: goto P_0c0a9cac;
case 0x0c0a9caeu: goto P_0c0a9cae;
case 0x0c0a9cb0u: goto P_0c0a9cb0;
case 0x0c0a9cb2u: goto P_0c0a9cb2;
case 0x0c0a9cb4u: goto P_0c0a9cb4;
case 0x0c0a9cb6u: goto P_0c0a9cb6;
case 0x0c0a9cb8u: goto P_0c0a9cb8;
case 0x0c0a9cbau: goto P_0c0a9cba;
case 0x0c0a9cbcu: goto P_0c0a9cbc;
case 0x0c0a9cbeu: goto P_0c0a9cbe;
case 0x0c0a9cc0u: goto P_0c0a9cc0;
case 0x0c0a9cc2u: goto P_0c0a9cc2;
case 0x0c0a9cc4u: goto P_0c0a9cc4;
case 0x0c0a9cc6u: goto P_0c0a9cc6;
case 0x0c0a9cc8u: goto P_0c0a9cc8;
case 0x0c0a9ccau: goto P_0c0a9cca;
case 0x0c0a9cccu: goto P_0c0a9ccc;
case 0x0c0a9cceu: goto P_0c0a9cce;
case 0x0c0a9cd0u: goto P_0c0a9cd0;
case 0x0c0a9cd2u: goto P_0c0a9cd2;
case 0x0c0a9cd4u: goto P_0c0a9cd4;
case 0x0c0a9cd6u: goto P_0c0a9cd6;
case 0x0c0a9cd8u: goto P_0c0a9cd8;
case 0x0c0a9cdau: goto P_0c0a9cda;
case 0x0c0a9cdcu: goto P_0c0a9cdc;
case 0x0c0a9cdeu: goto P_0c0a9cde;
case 0x0c0a9ce0u: goto P_0c0a9ce0;
case 0x0c0a9ce2u: goto P_0c0a9ce2;
case 0x0c0a9ce4u: goto P_0c0a9ce4;
case 0x0c0a9ce6u: goto P_0c0a9ce6;
case 0x0c0a9ce8u: goto P_0c0a9ce8;
case 0x0c0a9ceau: goto P_0c0a9cea;
case 0x0c0a9cecu: goto P_0c0a9cec;
case 0x0c0a9ceeu: goto P_0c0a9cee;
case 0x0c0a9cf0u: goto P_0c0a9cf0;
case 0x0c0a9cf2u: goto P_0c0a9cf2;
case 0x0c0a9cf4u: goto P_0c0a9cf4;
case 0x0c0a9cf6u: goto P_0c0a9cf6;
case 0x0c0a9cf8u: goto P_0c0a9cf8;
case 0x0c0a9cfau: goto P_0c0a9cfa;
case 0x0c0a9cfcu: goto P_0c0a9cfc;
case 0x0c0a9cfeu: goto P_0c0a9cfe;
case 0x0c0a9d00u: goto P_0c0a9d00;
case 0x0c0a9d02u: goto P_0c0a9d02;
case 0x0c0a9d04u: goto P_0c0a9d04;
case 0x0c0a9d06u: goto P_0c0a9d06;
case 0x0c0a9d08u: goto P_0c0a9d08;
case 0x0c0a9d0au: goto P_0c0a9d0a;
case 0x0c0a9d0cu: goto P_0c0a9d0c;
case 0x0c0a9d0eu: goto P_0c0a9d0e;
case 0x0c0a9d10u: goto P_0c0a9d10;
case 0x0c0a9d12u: goto P_0c0a9d12;
case 0x0c0a9d14u: goto P_0c0a9d14;
case 0x0c0a9d16u: goto P_0c0a9d16;
case 0x0c0a9d18u: goto P_0c0a9d18;
case 0x0c0a9d1au: goto P_0c0a9d1a;
case 0x0c0a9d1cu: goto P_0c0a9d1c;
case 0x0c0a9d1eu: goto P_0c0a9d1e;
case 0x0c0a9d20u: goto P_0c0a9d20;
case 0x0c0a9d22u: goto P_0c0a9d22;
case 0x0c0a9d24u: goto P_0c0a9d24;
case 0x0c0a9d26u: goto P_0c0a9d26;
case 0x0c0a9d28u: goto P_0c0a9d28;
case 0x0c0a9d2au: goto P_0c0a9d2a;
case 0x0c0a9d2cu: goto P_0c0a9d2c;
case 0x0c0a9d2eu: goto P_0c0a9d2e;
case 0x0c0a9d30u: goto P_0c0a9d30;
case 0x0c0a9d32u: goto P_0c0a9d32;
case 0x0c0a9d34u: goto P_0c0a9d34;
case 0x0c0a9d36u: goto P_0c0a9d36;
case 0x0c0a9d38u: goto P_0c0a9d38;
case 0x0c0a9d3au: goto P_0c0a9d3a;
case 0x0c0a9d3cu: goto P_0c0a9d3c;
case 0x0c0a9d3eu: goto P_0c0a9d3e;
case 0x0c0a9d70u: goto P_0c0a9d70;
case 0x0c0a9d72u: goto P_0c0a9d72;
case 0x0c0a9d74u: goto P_0c0a9d74;
case 0x0c0a9d76u: goto P_0c0a9d76;
case 0x0c0a9d78u: goto P_0c0a9d78;
case 0x0c0a9d7au: goto P_0c0a9d7a;
case 0x0c0a9d7cu: goto P_0c0a9d7c;
case 0x0c0a9d7eu: goto P_0c0a9d7e;
case 0x0c0a9d80u: goto P_0c0a9d80;
case 0x0c0a9d82u: goto P_0c0a9d82;
case 0x0c0a9d84u: goto P_0c0a9d84;
case 0x0c0a9d86u: goto P_0c0a9d86;
case 0x0c0a9d88u: goto P_0c0a9d88;
case 0x0c0a9d8au: goto P_0c0a9d8a;
case 0x0c0a9d8cu: goto P_0c0a9d8c;
case 0x0c0a9d8eu: goto P_0c0a9d8e;
case 0x0c0a9d90u: goto P_0c0a9d90;
case 0x0c0a9d92u: goto P_0c0a9d92;
case 0x0c0a9d94u: goto P_0c0a9d94;
case 0x0c0a9d96u: goto P_0c0a9d96;
case 0x0c0a9d98u: goto P_0c0a9d98;
case 0x0c0a9d9au: goto P_0c0a9d9a;
case 0x0c0a9d9cu: goto P_0c0a9d9c;
case 0x0c0a9d9eu: goto P_0c0a9d9e;
case 0x0c0a9da0u: goto P_0c0a9da0;
case 0x0c0a9da2u: goto P_0c0a9da2;
case 0x0c0a9da4u: goto P_0c0a9da4;
case 0x0c0a9da6u: goto P_0c0a9da6;
case 0x0c0a9da8u: goto P_0c0a9da8;
case 0x0c0a9daau: goto P_0c0a9daa;
case 0x0c0a9dacu: goto P_0c0a9dac;
case 0x0c0a9daeu: goto P_0c0a9dae;
case 0x0c0a9db0u: goto P_0c0a9db0;
case 0x0c0a9db2u: goto P_0c0a9db2;
case 0x0c0a9db4u: goto P_0c0a9db4;
case 0x0c0a9db6u: goto P_0c0a9db6;
case 0x0c0a9db8u: goto P_0c0a9db8;
case 0x0c0a9dbau: goto P_0c0a9dba;
case 0x0c0a9dbcu: goto P_0c0a9dbc;
case 0x0c0a9dbeu: goto P_0c0a9dbe;
case 0x0c0a9dc0u: goto P_0c0a9dc0;
case 0x0c0a9dc2u: goto P_0c0a9dc2;
case 0x0c0a9dc4u: goto P_0c0a9dc4;
case 0x0c0a9dc6u: goto P_0c0a9dc6;
case 0x0c0a9dc8u: goto P_0c0a9dc8;
case 0x0c0a9dcau: goto P_0c0a9dca;
case 0x0c0a9dccu: goto P_0c0a9dcc;
case 0x0c0a9dceu: goto P_0c0a9dce;
case 0x0c0a9dd0u: goto P_0c0a9dd0;
case 0x0c0a9dd2u: goto P_0c0a9dd2;
case 0x0c0a9dd4u: goto P_0c0a9dd4;
case 0x0c0a9dd6u: goto P_0c0a9dd6;
case 0x0c0a9dd8u: goto P_0c0a9dd8;
case 0x0c0a9ddau: goto P_0c0a9dda;
case 0x0c0a9ddcu: goto P_0c0a9ddc;
case 0x0c0a9ddeu: goto P_0c0a9dde;
case 0x0c0a9de0u: goto P_0c0a9de0;
case 0x0c0a9de2u: goto P_0c0a9de2;
case 0x0c0a9de4u: goto P_0c0a9de4;
case 0x0c0a9de6u: goto P_0c0a9de6;
case 0x0c0a9de8u: goto P_0c0a9de8;
case 0x0c0a9deau: goto P_0c0a9dea;
case 0x0c0a9decu: goto P_0c0a9dec;
case 0x0c0a9deeu: goto P_0c0a9dee;
case 0x0c0a9df0u: goto P_0c0a9df0;
case 0x0c0a9df2u: goto P_0c0a9df2;
case 0x0c0a9df4u: goto P_0c0a9df4;
case 0x0c0a9df6u: goto P_0c0a9df6;
case 0x0c0a9df8u: goto P_0c0a9df8;
case 0x0c0a9dfau: goto P_0c0a9dfa;
case 0x0c0a9dfcu: goto P_0c0a9dfc;
case 0x0c0a9dfeu: goto P_0c0a9dfe;
case 0x0c0a9e00u: goto P_0c0a9e00;
case 0x0c0a9e02u: goto P_0c0a9e02;
case 0x0c0a9e04u: goto P_0c0a9e04;
case 0x0c0a9e06u: goto P_0c0a9e06;
case 0x0c0a9e08u: goto P_0c0a9e08;
case 0x0c0a9e0au: goto P_0c0a9e0a;
case 0x0c0a9e0cu: goto P_0c0a9e0c;
case 0x0c0a9e0eu: goto P_0c0a9e0e;
case 0x0c0a9e10u: goto P_0c0a9e10;
case 0x0c0a9e12u: goto P_0c0a9e12;
case 0x0c0a9e14u: goto P_0c0a9e14;
case 0x0c0a9e16u: goto P_0c0a9e16;
case 0x0c0a9e18u: goto P_0c0a9e18;
case 0x0c0a9e1au: goto P_0c0a9e1a;
case 0x0c0a9e1cu: goto P_0c0a9e1c;
case 0x0c0a9e1eu: goto P_0c0a9e1e;
case 0x0c0a9e20u: goto P_0c0a9e20;
case 0x0c0a9e22u: goto P_0c0a9e22;
case 0x0c0a9e24u: goto P_0c0a9e24;
case 0x0c0a9e26u: goto P_0c0a9e26;
case 0x0c0a9e28u: goto P_0c0a9e28;
case 0x0c0a9e2au: goto P_0c0a9e2a;
case 0x0c0a9e2cu: goto P_0c0a9e2c;
case 0x0c0a9e2eu: goto P_0c0a9e2e;
case 0x0c0a9e30u: goto P_0c0a9e30;
case 0x0c0a9e32u: goto P_0c0a9e32;
case 0x0c0a9e34u: goto P_0c0a9e34;
case 0x0c0a9e36u: goto P_0c0a9e36;
case 0x0c0a9e38u: goto P_0c0a9e38;
case 0x0c0a9e3au: goto P_0c0a9e3a;
case 0x0c0a9e3cu: goto P_0c0a9e3c;
case 0x0c0a9e3eu: goto P_0c0a9e3e;
case 0x0c0a9e40u: goto P_0c0a9e40;
case 0x0c0a9e42u: goto P_0c0a9e42;
case 0x0c0a9e44u: goto P_0c0a9e44;
case 0x0c0a9e46u: goto P_0c0a9e46;
case 0x0c0a9e48u: goto P_0c0a9e48;
case 0x0c0a9e4au: goto P_0c0a9e4a;
case 0x0c0a9e4cu: goto P_0c0a9e4c;
case 0x0c0a9e4eu: goto P_0c0a9e4e;
case 0x0c0a9e50u: goto P_0c0a9e50;
case 0x0c0a9e52u: goto P_0c0a9e52;
case 0x0c0a9e54u: goto P_0c0a9e54;
case 0x0c0a9e56u: goto P_0c0a9e56;
case 0x0c0a9e58u: goto P_0c0a9e58;
case 0x0c0a9e5au: goto P_0c0a9e5a;
case 0x0c0a9e5cu: goto P_0c0a9e5c;
case 0x0c0a9e5eu: goto P_0c0a9e5e;
default: return vf3_matrix_family(target,s,ram);
}
P_0c0a9c3c: /* original 2fe6, guest PC 0x0c0a9c3c */
if(!s->budget--) { s->failed_pc=0x0c0a9c3cu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a9c3e;
P_0c0a9c3e: /* original 6e53, guest PC 0x0c0a9c3e */
if(!s->budget--) { s->failed_pc=0x0c0a9c3eu; return 0; }
r[14]=r[5];
goto P_0c0a9c40;
P_0c0a9c40: /* original 2fd6, guest PC 0x0c0a9c40 */
if(!s->budget--) { s->failed_pc=0x0c0a9c40u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a9c42;
P_0c0a9c42: /* original 6d43, guest PC 0x0c0a9c42 */
if(!s->budget--) { s->failed_pc=0x0c0a9c42u; return 0; }
r[13]=r[4];
goto P_0c0a9c44;
P_0c0a9c44: /* original 2fc6, guest PC 0x0c0a9c44 */
if(!s->budget--) { s->failed_pc=0x0c0a9c44u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a9c46;
P_0c0a9c46: /* original 6cd3, guest PC 0x0c0a9c46 */
if(!s->budget--) { s->failed_pc=0x0c0a9c46u; return 0; }
r[12]=r[13];
goto P_0c0a9c48;
P_0c0a9c48: /* original 2fb6, guest PC 0x0c0a9c48 */
if(!s->budget--) { s->failed_pc=0x0c0a9c48u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a9c4a;
P_0c0a9c4a: /* original 6be3, guest PC 0x0c0a9c4a */
if(!s->budget--) { s->failed_pc=0x0c0a9c4au; return 0; }
r[11]=r[14];
goto P_0c0a9c4c;
P_0c0a9c4c: /* original 2fa6, guest PC 0x0c0a9c4c */
if(!s->budget--) { s->failed_pc=0x0c0a9c4cu; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a9c4e;
P_0c0a9c4e: /* original 2f96, guest PC 0x0c0a9c4e */
if(!s->budget--) { s->failed_pc=0x0c0a9c4eu; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a9c50;
P_0c0a9c50: /* original 2f86, guest PC 0x0c0a9c50 */
if(!s->budget--) { s->failed_pc=0x0c0a9c50u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a9c52;
P_0c0a9c52: /* original 4f22, guest PC 0x0c0a9c52 */
if(!s->budget--) { s->failed_pc=0x0c0a9c52u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0a9c54;
P_0c0a9c54: /* original d33c, guest PC 0x0c0a9c54 */
if(!s->budget--) { s->failed_pc=0x0c0a9c54u; return 0; }
r[3]=read(ram,0x0c0a9d48u,4);
goto P_0c0a9c56;
P_0c0a9c56: /* original 4f12, guest PC 0x0c0a9c56 */
if(!s->budget--) { s->failed_pc=0x0c0a9c56u; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c0a9c58;
P_0c0a9c58: /* original 7ffc, guest PC 0x0c0a9c58 */
if(!s->budget--) { s->failed_pc=0x0c0a9c58u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c0a9c5a;
P_0c0a9c5a: /* original 2f32, guest PC 0x0c0a9c5a */
if(!s->budget--) { s->failed_pc=0x0c0a9c5au; return 0; }
write(ram,r[15],r[3],4);
goto P_0c0a9c5c;
P_0c0a9c5c: /* original b100, guest PC 0x0c0a9c5c */
if(!s->budget--) { s->failed_pc=0x0c0a9c5cu; return 0; }
target=code_base|0x0c0a9e60u; r[16]=code_base|0x0c0a9c60u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a9c60u) { target=s->pc; goto dispatch; }
goto P_0c0a9c60;
P_0c0a9c5e: /* original 64d3, guest PC 0x0c0a9c5e */
if(!s->budget--) { s->failed_pc=0x0c0a9c5eu; return 0; }
r[4]=r[13];
goto P_0c0a9c60;
P_0c0a9c60: /* original b0fe, guest PC 0x0c0a9c60 */
if(!s->budget--) { s->failed_pc=0x0c0a9c60u; return 0; }
target=code_base|0x0c0a9e60u; r[16]=code_base|0x0c0a9c64u;
r[4]=r[11];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a9c64u) { target=s->pc; goto dispatch; }
goto P_0c0a9c64;
P_0c0a9c62: /* original 64b3, guest PC 0x0c0a9c62 */
if(!s->budget--) { s->failed_pc=0x0c0a9c62u; return 0; }
r[4]=r[11];
goto P_0c0a9c64;
P_0c0a9c64: /* original 64c3, guest PC 0x0c0a9c64 */
if(!s->budget--) { s->failed_pc=0x0c0a9c64u; return 0; }
r[4]=r[12];
goto P_0c0a9c66;
P_0c0a9c66: /* original 7434, guest PC 0x0c0a9c66 */
if(!s->budget--) { s->failed_pc=0x0c0a9c66u; return 0; }
r[4]+=0x00000034u;
goto P_0c0a9c68;
P_0c0a9c68: /* original 8443, guest PC 0x0c0a9c68 */
if(!s->budget--) { s->failed_pc=0x0c0a9c68u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+3,1);
goto P_0c0a9c6a;
P_0c0a9c6a: /* original 65b3, guest PC 0x0c0a9c6a */
if(!s->budget--) { s->failed_pc=0x0c0a9c6au; return 0; }
r[5]=r[11];
goto P_0c0a9c6c;
P_0c0a9c6c: /* original 7534, guest PC 0x0c0a9c6c */
if(!s->budget--) { s->failed_pc=0x0c0a9c6cu; return 0; }
r[5]+=0x00000034u;
goto P_0c0a9c6e;
P_0c0a9c6e: /* original 6403, guest PC 0x0c0a9c6e */
if(!s->budget--) { s->failed_pc=0x0c0a9c6eu; return 0; }
r[4]=r[0];
goto P_0c0a9c70;
P_0c0a9c70: /* original 8453, guest PC 0x0c0a9c70 */
if(!s->budget--) { s->failed_pc=0x0c0a9c70u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[5]+3,1);
goto P_0c0a9c72;
P_0c0a9c72: /* original 6503, guest PC 0x0c0a9c72 */
if(!s->budget--) { s->failed_pc=0x0c0a9c72u; return 0; }
r[5]=r[0];
goto P_0c0a9c74;
P_0c0a9c74: /* original 604c, guest PC 0x0c0a9c74 */
if(!s->budget--) { s->failed_pc=0x0c0a9c74u; return 0; }
r[0]=r[4]&255u;
goto P_0c0a9c76;
P_0c0a9c76: /* original 880c, guest PC 0x0c0a9c76 */
if(!s->budget--) { s->failed_pc=0x0c0a9c76u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000cu)!=0);
goto P_0c0a9c78;
P_0c0a9c78: /* original 8b01, guest PC 0x0c0a9c78 */
if(!s->budget--) { s->failed_pc=0x0c0a9c78u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a9c7e; }
goto P_0c0a9c7a;
P_0c0a9c7a: /* original a0e3, guest PC 0x0c0a9c7a */
if(!s->budget--) { s->failed_pc=0x0c0a9c7au; return 0; }
goto P_0c0a9e44;
P_0c0a9c7c: /* original 0009, guest PC 0x0c0a9c7c */
if(!s->budget--) { s->failed_pc=0x0c0a9c7cu; return 0; }
goto P_0c0a9c7e;
P_0c0a9c7e: /* original 605c, guest PC 0x0c0a9c7e */
if(!s->budget--) { s->failed_pc=0x0c0a9c7eu; return 0; }
r[0]=r[5]&255u;
goto P_0c0a9c80;
P_0c0a9c80: /* original 880c, guest PC 0x0c0a9c80 */
if(!s->budget--) { s->failed_pc=0x0c0a9c80u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000cu)!=0);
goto P_0c0a9c82;
P_0c0a9c82: /* original 8b01, guest PC 0x0c0a9c82 */
if(!s->budget--) { s->failed_pc=0x0c0a9c82u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a9c88; }
goto P_0c0a9c84;
P_0c0a9c84: /* original a0de, guest PC 0x0c0a9c84 */
if(!s->budget--) { s->failed_pc=0x0c0a9c84u; return 0; }
goto P_0c0a9e44;
P_0c0a9c86: /* original 0009, guest PC 0x0c0a9c86 */
if(!s->budget--) { s->failed_pc=0x0c0a9c86u; return 0; }
goto P_0c0a9c88;
P_0c0a9c88: /* original 69d3, guest PC 0x0c0a9c88 */
if(!s->budget--) { s->failed_pc=0x0c0a9c88u; return 0; }
r[9]=r[13];
goto P_0c0a9c8a;
P_0c0a9c8a: /* original 7930, guest PC 0x0c0a9c8a */
if(!s->budget--) { s->failed_pc=0x0c0a9c8au; return 0; }
r[9]+=0x00000030u;
goto P_0c0a9c8c;
P_0c0a9c8c: /* original 8493, guest PC 0x0c0a9c8c */
if(!s->budget--) { s->failed_pc=0x0c0a9c8cu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[9]+3,1);
goto P_0c0a9c8e;
P_0c0a9c8e: /* original 6ae3, guest PC 0x0c0a9c8e */
if(!s->budget--) { s->failed_pc=0x0c0a9c8eu; return 0; }
r[10]=r[14];
goto P_0c0a9c90;
P_0c0a9c90: /* original 7a30, guest PC 0x0c0a9c90 */
if(!s->budget--) { s->failed_pc=0x0c0a9c90u; return 0; }
r[10]+=0x00000030u;
goto P_0c0a9c92;
P_0c0a9c92: /* original 690c, guest PC 0x0c0a9c92 */
if(!s->budget--) { s->failed_pc=0x0c0a9c92u; return 0; }
r[9]=r[0]&255u;
goto P_0c0a9c94;
P_0c0a9c94: /* original 84a3, guest PC 0x0c0a9c94 */
if(!s->budget--) { s->failed_pc=0x0c0a9c94u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[10]+3,1);
goto P_0c0a9c96;
P_0c0a9c96: /* original 6a0c, guest PC 0x0c0a9c96 */
if(!s->budget--) { s->failed_pc=0x0c0a9c96u; return 0; }
r[10]=r[0]&255u;
goto P_0c0a9c98;
P_0c0a9c98: /* original 6093, guest PC 0x0c0a9c98 */
if(!s->budget--) { s->failed_pc=0x0c0a9c98u; return 0; }
r[0]=r[9];
goto P_0c0a9c9a;
P_0c0a9c9a: /* original 881a, guest PC 0x0c0a9c9a */
if(!s->budget--) { s->failed_pc=0x0c0a9c9au; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000001au)!=0);
goto P_0c0a9c9c;
P_0c0a9c9c: /* original 8903, guest PC 0x0c0a9c9c */
if(!s->budget--) { s->failed_pc=0x0c0a9c9cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a9ca6; }
goto P_0c0a9c9e;
P_0c0a9c9e: /* original 60a3, guest PC 0x0c0a9c9e */
if(!s->budget--) { s->failed_pc=0x0c0a9c9eu; return 0; }
r[0]=r[10];
goto P_0c0a9ca0;
P_0c0a9ca0: /* original 881a, guest PC 0x0c0a9ca0 */
if(!s->budget--) { s->failed_pc=0x0c0a9ca0u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000001au)!=0);
goto P_0c0a9ca2;
P_0c0a9ca2: /* original 8b15, guest PC 0x0c0a9ca2 */
if(!s->budget--) { s->failed_pc=0x0c0a9ca2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a9cd0; }
goto P_0c0a9ca4;
P_0c0a9ca4: /* original 6ec3, guest PC 0x0c0a9ca4 */
if(!s->budget--) { s->failed_pc=0x0c0a9ca4u; return 0; }
r[14]=r[12];
goto P_0c0a9ca6;
P_0c0a9ca6: /* original 65e3, guest PC 0x0c0a9ca6 */
if(!s->budget--) { s->failed_pc=0x0c0a9ca6u; return 0; }
r[5]=r[14];
goto P_0c0a9ca8;
P_0c0a9ca8: /* original 7538, guest PC 0x0c0a9ca8 */
if(!s->budget--) { s->failed_pc=0x0c0a9ca8u; return 0; }
r[5]+=0x00000038u;
goto P_0c0a9caa;
P_0c0a9caa: /* original 8453, guest PC 0x0c0a9caa */
if(!s->budget--) { s->failed_pc=0x0c0a9caau; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[5]+3,1);
goto P_0c0a9cac;
P_0c0a9cac: /* original 6503, guest PC 0x0c0a9cac */
if(!s->budget--) { s->failed_pc=0x0c0a9cacu; return 0; }
r[5]=r[0];
goto P_0c0a9cae;
P_0c0a9cae: /* original 645c, guest PC 0x0c0a9cae */
if(!s->budget--) { s->failed_pc=0x0c0a9caeu; return 0; }
r[4]=r[5]&255u;
goto P_0c0a9cb0;
P_0c0a9cb0: /* original 6043, guest PC 0x0c0a9cb0 */
if(!s->budget--) { s->failed_pc=0x0c0a9cb0u; return 0; }
r[0]=r[4];
goto P_0c0a9cb2;
P_0c0a9cb2: /* original 8816, guest PC 0x0c0a9cb2 */
if(!s->budget--) { s->failed_pc=0x0c0a9cb2u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000016u)!=0);
goto P_0c0a9cb4;
P_0c0a9cb4: /* original 8902, guest PC 0x0c0a9cb4 */
if(!s->budget--) { s->failed_pc=0x0c0a9cb4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a9cbc; }
goto P_0c0a9cb6;
P_0c0a9cb6: /* original 6043, guest PC 0x0c0a9cb6 */
if(!s->budget--) { s->failed_pc=0x0c0a9cb6u; return 0; }
r[0]=r[4];
goto P_0c0a9cb8;
P_0c0a9cb8: /* original 8814, guest PC 0x0c0a9cb8 */
if(!s->budget--) { s->failed_pc=0x0c0a9cb8u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000014u)!=0);
goto P_0c0a9cba;
P_0c0a9cba: /* original 8b07, guest PC 0x0c0a9cba */
if(!s->budget--) { s->failed_pc=0x0c0a9cbau; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a9ccc; }
goto P_0c0a9cbc;
P_0c0a9cbc: /* original d323, guest PC 0x0c0a9cbc */
if(!s->budget--) { s->failed_pc=0x0c0a9cbcu; return 0; }
r[3]=read(ram,0x0c0a9d4cu,4);
goto P_0c0a9cbe;
P_0c0a9cbe: /* original e048, guest PC 0x0c0a9cbe */
if(!s->budget--) { s->failed_pc=0x0c0a9cbeu; return 0; }
r[0]=0x00000048u;
goto P_0c0a9cc0;
P_0c0a9cc0: /* original 1e3c, guest PC 0x0c0a9cc0 */
if(!s->budget--) { s->failed_pc=0x0c0a9cc0u; return 0; }
write(ram,r[14]+48,r[3],4);
goto P_0c0a9cc2;
P_0c0a9cc2: /* original 02ee, guest PC 0x0c0a9cc2 */
if(!s->budget--) { s->failed_pc=0x0c0a9cc2u; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c0a9cc4;
P_0c0a9cc4: /* original d322, guest PC 0x0c0a9cc4 */
if(!s->budget--) { s->failed_pc=0x0c0a9cc4u; return 0; }
r[3]=read(ram,0x0c0a9d50u,4);
goto P_0c0a9cc6;
P_0c0a9cc6: /* original 2239, guest PC 0x0c0a9cc6 */
if(!s->budget--) { s->failed_pc=0x0c0a9cc6u; return 0; }
r[2]&=r[3];
goto P_0c0a9cc8;
P_0c0a9cc8: /* original a0bc, guest PC 0x0c0a9cc8 */
if(!s->budget--) { s->failed_pc=0x0c0a9cc8u; return 0; }
write(ram,r[14]+r[0],r[2],4);
goto P_0c0a9e44;
P_0c0a9cca: /* original 0e26, guest PC 0x0c0a9cca */
if(!s->budget--) { s->failed_pc=0x0c0a9ccau; return 0; }
write(ram,r[14]+r[0],r[2],4);
goto P_0c0a9ccc;
P_0c0a9ccc: /* original 6eb3, guest PC 0x0c0a9ccc */
if(!s->budget--) { s->failed_pc=0x0c0a9cccu; return 0; }
r[14]=r[11];
goto P_0c0a9cce;
P_0c0a9cce: /* original 6dc3, guest PC 0x0c0a9cce */
if(!s->budget--) { s->failed_pc=0x0c0a9cceu; return 0; }
r[13]=r[12];
goto P_0c0a9cd0;
P_0c0a9cd0: /* original 6093, guest PC 0x0c0a9cd0 */
if(!s->budget--) { s->failed_pc=0x0c0a9cd0u; return 0; }
r[0]=r[9];
goto P_0c0a9cd2;
P_0c0a9cd2: /* original d820, guest PC 0x0c0a9cd2 */
if(!s->budget--) { s->failed_pc=0x0c0a9cd2u; return 0; }
r[8]=read(ram,0x0c0a9d54u,4);
goto P_0c0a9cd4;
P_0c0a9cd4: /* original 8816, guest PC 0x0c0a9cd4 */
if(!s->budget--) { s->failed_pc=0x0c0a9cd4u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000016u)!=0);
goto P_0c0a9cd6;
P_0c0a9cd6: /* original 8904, guest PC 0x0c0a9cd6 */
if(!s->budget--) { s->failed_pc=0x0c0a9cd6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a9ce2; }
goto P_0c0a9cd8;
P_0c0a9cd8: /* original 60a3, guest PC 0x0c0a9cd8 */
if(!s->budget--) { s->failed_pc=0x0c0a9cd8u; return 0; }
r[0]=r[10];
goto P_0c0a9cda;
P_0c0a9cda: /* original 8816, guest PC 0x0c0a9cda */
if(!s->budget--) { s->failed_pc=0x0c0a9cdau; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000016u)!=0);
goto P_0c0a9cdc;
P_0c0a9cdc: /* original 8b4e, guest PC 0x0c0a9cdc */
if(!s->budget--) { s->failed_pc=0x0c0a9cdcu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a9d7c; }
goto P_0c0a9cde;
P_0c0a9cde: /* original 6ec3, guest PC 0x0c0a9cde */
if(!s->budget--) { s->failed_pc=0x0c0a9cdeu; return 0; }
r[14]=r[12];
goto P_0c0a9ce0;
P_0c0a9ce0: /* original 6db3, guest PC 0x0c0a9ce0 */
if(!s->budget--) { s->failed_pc=0x0c0a9ce0u; return 0; }
r[13]=r[11];
goto P_0c0a9ce2;
P_0c0a9ce2: /* original e030, guest PC 0x0c0a9ce2 */
if(!s->budget--) { s->failed_pc=0x0c0a9ce2u; return 0; }
r[0]=0x00000030u;
goto P_0c0a9ce4;
P_0c0a9ce4: /* original d31c, guest PC 0x0c0a9ce4 */
if(!s->budget--) { s->failed_pc=0x0c0a9ce4u; return 0; }
r[3]=read(ram,0x0c0a9d58u,4);
goto P_0c0a9ce6;
P_0c0a9ce6: /* original 05dd, guest PC 0x0c0a9ce6 */
if(!s->budget--) { s->failed_pc=0x0c0a9ce6u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,r[13]+r[0],2);
goto P_0c0a9ce8;
P_0c0a9ce8: /* original 655d, guest PC 0x0c0a9ce8 */
if(!s->budget--) { s->failed_pc=0x0c0a9ce8u; return 0; }
r[5]=r[5]&65535u;
goto P_0c0a9cea;
P_0c0a9cea: /* original 430b, guest PC 0x0c0a9cea */
if(!s->budget--) { s->failed_pc=0x0c0a9ceau; return 0; }
target=r[3];
r[16]=code_base|0x0c0a9ceeu;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a9ceeu) { target=s->pc; goto dispatch; }
goto P_0c0a9cee;
P_0c0a9cec: /* original 64d3, guest PC 0x0c0a9cec */
if(!s->budget--) { s->failed_pc=0x0c0a9cecu; return 0; }
r[4]=r[13];
goto P_0c0a9cee;
P_0c0a9cee: /* original e03c, guest PC 0x0c0a9cee */
if(!s->budget--) { s->failed_pc=0x0c0a9ceeu; return 0; }
r[0]=0x0000003cu;
goto P_0c0a9cf0;
P_0c0a9cf0: /* original 02ed, guest PC 0x0c0a9cf0 */
if(!s->budget--) { s->failed_pc=0x0c0a9cf0u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0a9cf2;
P_0c0a9cf2: /* original 9025, guest PC 0x0c0a9cf2 */
if(!s->budget--) { s->failed_pc=0x0c0a9cf2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a9d40u,2);
goto P_0c0a9cf4;
P_0c0a9cf4: /* original 0d25, guest PC 0x0c0a9cf4 */
if(!s->budget--) { s->failed_pc=0x0c0a9cf4u; return 0; }
write(ram,r[13]+r[0],r[2],2);
goto P_0c0a9cf6;
P_0c0a9cf6: /* original 9024, guest PC 0x0c0a9cf6 */
if(!s->budget--) { s->failed_pc=0x0c0a9cf6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a9d42u,2);
goto P_0c0a9cf8;
P_0c0a9cf8: /* original 03dd, guest PC 0x0c0a9cf8 */
if(!s->budget--) { s->failed_pc=0x0c0a9cf8u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[13]+r[0],2);
goto P_0c0a9cfa;
P_0c0a9cfa: /* original 70ce, guest PC 0x0c0a9cfa */
if(!s->budget--) { s->failed_pc=0x0c0a9cfau; return 0; }
r[0]+=0xffffffceu;
goto P_0c0a9cfc;
P_0c0a9cfc: /* original 05ed, guest PC 0x0c0a9cfc */
if(!s->budget--) { s->failed_pc=0x0c0a9cfcu; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0a9cfe;
P_0c0a9cfe: /* original 9021, guest PC 0x0c0a9cfe */
if(!s->budget--) { s->failed_pc=0x0c0a9cfeu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a9d44u,2);
goto P_0c0a9d00;
P_0c0a9d00: /* original 3538, guest PC 0x0c0a9d00 */
if(!s->budget--) { s->failed_pc=0x0c0a9d00u; return 0; }
r[5]-=r[3];
goto P_0c0a9d02;
P_0c0a9d02: /* original 0d55, guest PC 0x0c0a9d02 */
if(!s->budget--) { s->failed_pc=0x0c0a9d02u; return 0; }
write(ram,r[13]+r[0],r[5],2);
goto P_0c0a9d04;
P_0c0a9d04: /* original 901f, guest PC 0x0c0a9d04 */
if(!s->budget--) { s->failed_pc=0x0c0a9d04u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a9d46u,2);
goto P_0c0a9d06;
P_0c0a9d06: /* original 64d2, guest PC 0x0c0a9d06 */
if(!s->budget--) { s->failed_pc=0x0c0a9d06u; return 0; }
tmp=read(ram,r[13],4);
r[4]=tmp;
goto P_0c0a9d08;
P_0c0a9d08: /* original d215, guest PC 0x0c0a9d08 */
if(!s->budget--) { s->failed_pc=0x0c0a9d08u; return 0; }
r[2]=read(ram,0x0c0a9d60u,4);
goto P_0c0a9d0a;
P_0c0a9d0a: /* original d314, guest PC 0x0c0a9d0a */
if(!s->budget--) { s->failed_pc=0x0c0a9d0au; return 0; }
r[3]=read(ram,0x0c0a9d5cu,4);
goto P_0c0a9d0c;
P_0c0a9d0c: /* original 06de, guest PC 0x0c0a9d0c */
if(!s->budget--) { s->failed_pc=0x0c0a9d0cu; return 0; }
r[6]=read(ram,r[13]+r[0],4);
goto P_0c0a9d0e;
P_0c0a9d0e: /* original 2248, guest PC 0x0c0a9d0e */
if(!s->budget--) { s->failed_pc=0x0c0a9d0eu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[4])==0)!=0);
goto P_0c0a9d10;
P_0c0a9d10: /* original 8d02, guest PC 0x0c0a9d10 */
if(!s->budget--) { s->failed_pc=0x0c0a9d10u; return 0; }
cond=r[17]&1u;
r[6]+=r[3];
if(cond) { goto P_0c0a9d18; }
goto P_0c0a9d14;
P_0c0a9d12: /* original 363c, guest PC 0x0c0a9d12 */
if(!s->budget--) { s->failed_pc=0x0c0a9d12u; return 0; }
r[6]+=r[3];
goto P_0c0a9d14;
P_0c0a9d14: /* original a002, guest PC 0x0c0a9d14 */
if(!s->budget--) { s->failed_pc=0x0c0a9d14u; return 0; }
r[4]|=r[8];
goto P_0c0a9d1c;
P_0c0a9d16: /* original 248b, guest PC 0x0c0a9d16 */
if(!s->budget--) { s->failed_pc=0x0c0a9d16u; return 0; }
r[4]|=r[8];
goto P_0c0a9d18;
P_0c0a9d18: /* original d112, guest PC 0x0c0a9d18 */
if(!s->budget--) { s->failed_pc=0x0c0a9d18u; return 0; }
r[1]=read(ram,0x0c0a9d64u,4);
goto P_0c0a9d1a;
P_0c0a9d1a: /* original 2419, guest PC 0x0c0a9d1a */
if(!s->budget--) { s->failed_pc=0x0c0a9d1au; return 0; }
r[4]&=r[1];
goto P_0c0a9d1c;
P_0c0a9d1c: /* original 63e2, guest PC 0x0c0a9d1c */
if(!s->budget--) { s->failed_pc=0x0c0a9d1cu; return 0; }
tmp=read(ram,r[14],4);
r[3]=tmp;
goto P_0c0a9d1e;
P_0c0a9d1e: /* original 243a, guest PC 0x0c0a9d1e */
if(!s->budget--) { s->failed_pc=0x0c0a9d1eu; return 0; }
r[4]^=r[3];
goto P_0c0a9d20;
P_0c0a9d20: /* original 2488, guest PC 0x0c0a9d20 */
if(!s->budget--) { s->failed_pc=0x0c0a9d20u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[8])==0)!=0);
goto P_0c0a9d22;
P_0c0a9d22: /* original 8d03, guest PC 0x0c0a9d22 */
if(!s->budget--) { s->failed_pc=0x0c0a9d22u; return 0; }
cond=r[17]&1u;
r[5]+=0xffffffffu;
if(cond) { goto P_0c0a9d2c; }
goto P_0c0a9d26;
P_0c0a9d24: /* original 75ff, guest PC 0x0c0a9d24 */
if(!s->budget--) { s->failed_pc=0x0c0a9d24u; return 0; }
r[5]+=0xffffffffu;
goto P_0c0a9d26;
P_0c0a9d26: /* original d310, guest PC 0x0c0a9d26 */
if(!s->budget--) { s->failed_pc=0x0c0a9d26u; return 0; }
r[3]=read(ram,0x0c0a9d68u,4);
goto P_0c0a9d28;
P_0c0a9d28: /* original a002, guest PC 0x0c0a9d28 */
if(!s->budget--) { s->failed_pc=0x0c0a9d28u; return 0; }
r[6]|=r[3];
goto P_0c0a9d30;
P_0c0a9d2a: /* original 263b, guest PC 0x0c0a9d2a */
if(!s->budget--) { s->failed_pc=0x0c0a9d2au; return 0; }
r[6]|=r[3];
goto P_0c0a9d2c;
P_0c0a9d2c: /* original d10f, guest PC 0x0c0a9d2c */
if(!s->budget--) { s->failed_pc=0x0c0a9d2cu; return 0; }
r[1]=read(ram,0x0c0a9d6cu,4);
goto P_0c0a9d2e;
P_0c0a9d2e: /* original 2619, guest PC 0x0c0a9d2e */
if(!s->budget--) { s->failed_pc=0x0c0a9d2eu; return 0; }
r[6]&=r[1];
goto P_0c0a9d30;
P_0c0a9d30: /* original e03e, guest PC 0x0c0a9d30 */
if(!s->budget--) { s->failed_pc=0x0c0a9d30u; return 0; }
r[0]=0x0000003eu;
goto P_0c0a9d32;
P_0c0a9d32: /* original 03ed, guest PC 0x0c0a9d32 */
if(!s->budget--) { s->failed_pc=0x0c0a9d32u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0a9d34;
P_0c0a9d34: /* original 625f, guest PC 0x0c0a9d34 */
if(!s->budget--) { s->failed_pc=0x0c0a9d34u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)r[5];
goto P_0c0a9d36;
P_0c0a9d36: /* original 633d, guest PC 0x0c0a9d36 */
if(!s->budget--) { s->failed_pc=0x0c0a9d36u; return 0; }
r[3]=r[3]&65535u;
goto P_0c0a9d38;
P_0c0a9d38: /* original 3323, guest PC 0x0c0a9d38 */
if(!s->budget--) { s->failed_pc=0x0c0a9d38u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>=(int32_t)r[2])!=0);
goto P_0c0a9d3a;
P_0c0a9d3a: /* original 8b19, guest PC 0x0c0a9d3a */
if(!s->budget--) { s->failed_pc=0x0c0a9d3au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a9d70; }
goto P_0c0a9d3c;
P_0c0a9d3c: /* original a082, guest PC 0x0c0a9d3c */
if(!s->budget--) { s->failed_pc=0x0c0a9d3cu; return 0; }
write(ram,r[14]+48,r[6],4);
goto P_0c0a9e44;
P_0c0a9d3e: /* original 1e6c, guest PC 0x0c0a9d3e */
if(!s->budget--) { s->failed_pc=0x0c0a9d3eu; return 0; }
write(ram,r[14]+48,r[6],4);
if(!vf3_matrix_family(0x0c0a9d40u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0a9d40u; return 0; } return 1;
P_0c0a9d70: /* original 9085, guest PC 0x0c0a9d70 */
if(!s->budget--) { s->failed_pc=0x0c0a9d70u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a9e7eu,2);
goto P_0c0a9d72;
P_0c0a9d72: /* original 6dc3, guest PC 0x0c0a9d72 */
if(!s->budget--) { s->failed_pc=0x0c0a9d72u; return 0; }
r[13]=r[12];
goto P_0c0a9d74;
P_0c0a9d74: /* original 0e66, guest PC 0x0c0a9d74 */
if(!s->budget--) { s->failed_pc=0x0c0a9d74u; return 0; }
write(ram,r[14]+r[0],r[6],4);
goto P_0c0a9d76;
P_0c0a9d76: /* original 7004, guest PC 0x0c0a9d76 */
if(!s->budget--) { s->failed_pc=0x0c0a9d76u; return 0; }
r[0]+=0x00000004u;
goto P_0c0a9d78;
P_0c0a9d78: /* original 0e55, guest PC 0x0c0a9d78 */
if(!s->budget--) { s->failed_pc=0x0c0a9d78u; return 0; }
write(ram,r[14]+r[0],r[5],2);
goto P_0c0a9d7a;
P_0c0a9d7a: /* original 6eb3, guest PC 0x0c0a9d7a */
if(!s->budget--) { s->failed_pc=0x0c0a9d7au; return 0; }
r[14]=r[11];
goto P_0c0a9d7c;
P_0c0a9d7c: /* original 6093, guest PC 0x0c0a9d7c */
if(!s->budget--) { s->failed_pc=0x0c0a9d7cu; return 0; }
r[0]=r[9];
goto P_0c0a9d7e;
P_0c0a9d7e: /* original 8817, guest PC 0x0c0a9d7e */
if(!s->budget--) { s->failed_pc=0x0c0a9d7eu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000017u)!=0);
goto P_0c0a9d80;
P_0c0a9d80: /* original 8904, guest PC 0x0c0a9d80 */
if(!s->budget--) { s->failed_pc=0x0c0a9d80u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a9d8c; }
goto P_0c0a9d82;
P_0c0a9d82: /* original 60a3, guest PC 0x0c0a9d82 */
if(!s->budget--) { s->failed_pc=0x0c0a9d82u; return 0; }
r[0]=r[10];
goto P_0c0a9d84;
P_0c0a9d84: /* original 8817, guest PC 0x0c0a9d84 */
if(!s->budget--) { s->failed_pc=0x0c0a9d84u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000017u)!=0);
goto P_0c0a9d86;
P_0c0a9d86: /* original 8b07, guest PC 0x0c0a9d86 */
if(!s->budget--) { s->failed_pc=0x0c0a9d86u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a9d98; }
goto P_0c0a9d88;
P_0c0a9d88: /* original 6ec3, guest PC 0x0c0a9d88 */
if(!s->budget--) { s->failed_pc=0x0c0a9d88u; return 0; }
r[14]=r[12];
goto P_0c0a9d8a;
P_0c0a9d8a: /* original 6db3, guest PC 0x0c0a9d8a */
if(!s->budget--) { s->failed_pc=0x0c0a9d8au; return 0; }
r[13]=r[11];
goto P_0c0a9d8c;
P_0c0a9d8c: /* original 63d3, guest PC 0x0c0a9d8c */
if(!s->budget--) { s->failed_pc=0x0c0a9d8cu; return 0; }
r[3]=r[13];
goto P_0c0a9d8e;
P_0c0a9d8e: /* original e00c, guest PC 0x0c0a9d8e */
if(!s->budget--) { s->failed_pc=0x0c0a9d8eu; return 0; }
r[0]=0x0000000cu;
goto P_0c0a9d90;
P_0c0a9d90: /* original 7330, guest PC 0x0c0a9d90 */
if(!s->budget--) { s->failed_pc=0x0c0a9d90u; return 0; }
r[3]+=0x00000030u;
goto P_0c0a9d92;
P_0c0a9d92: /* original 8033, guest PC 0x0c0a9d92 */
if(!s->budget--) { s->failed_pc=0x0c0a9d92u; return 0; }
write(ram,r[3]+3,r[0],1);
goto P_0c0a9d94;
P_0c0a9d94: /* original a011, guest PC 0x0c0a9d94 */
if(!s->budget--) { s->failed_pc=0x0c0a9d94u; return 0; }
goto P_0c0a9dba;
P_0c0a9d96: /* original 0009, guest PC 0x0c0a9d96 */
if(!s->budget--) { s->failed_pc=0x0c0a9d96u; return 0; }
goto P_0c0a9d98;
P_0c0a9d98: /* original 6093, guest PC 0x0c0a9d98 */
if(!s->budget--) { s->failed_pc=0x0c0a9d98u; return 0; }
r[0]=r[9];
goto P_0c0a9d9a;
P_0c0a9d9a: /* original 880c, guest PC 0x0c0a9d9a */
if(!s->budget--) { s->failed_pc=0x0c0a9d9au; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000cu)!=0);
goto P_0c0a9d9c;
P_0c0a9d9c: /* original 8904, guest PC 0x0c0a9d9c */
if(!s->budget--) { s->failed_pc=0x0c0a9d9cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a9da8; }
goto P_0c0a9d9e;
P_0c0a9d9e: /* original 60a3, guest PC 0x0c0a9d9e */
if(!s->budget--) { s->failed_pc=0x0c0a9d9eu; return 0; }
r[0]=r[10];
goto P_0c0a9da0;
P_0c0a9da0: /* original 880c, guest PC 0x0c0a9da0 */
if(!s->budget--) { s->failed_pc=0x0c0a9da0u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000cu)!=0);
goto P_0c0a9da2;
P_0c0a9da2: /* original 8b4f, guest PC 0x0c0a9da2 */
if(!s->budget--) { s->failed_pc=0x0c0a9da2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a9e44; }
goto P_0c0a9da4;
P_0c0a9da4: /* original a007, guest PC 0x0c0a9da4 */
if(!s->budget--) { s->failed_pc=0x0c0a9da4u; return 0; }
goto P_0c0a9db6;
P_0c0a9da6: /* original 0009, guest PC 0x0c0a9da6 */
if(!s->budget--) { s->failed_pc=0x0c0a9da6u; return 0; }
goto P_0c0a9da8;
P_0c0a9da8: /* original 60a3, guest PC 0x0c0a9da8 */
if(!s->budget--) { s->failed_pc=0x0c0a9da8u; return 0; }
r[0]=r[10];
goto P_0c0a9daa;
P_0c0a9daa: /* original 880c, guest PC 0x0c0a9daa */
if(!s->budget--) { s->failed_pc=0x0c0a9daau; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000cu)!=0);
goto P_0c0a9dac;
P_0c0a9dac: /* original 8b05, guest PC 0x0c0a9dac */
if(!s->budget--) { s->failed_pc=0x0c0a9dacu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a9dba; }
goto P_0c0a9dae;
P_0c0a9dae: /* original 60f2, guest PC 0x0c0a9dae */
if(!s->budget--) { s->failed_pc=0x0c0a9daeu; return 0; }
tmp=read(ram,r[15],4);
r[0]=tmp;
goto P_0c0a9db0;
P_0c0a9db0: /* original 6002, guest PC 0x0c0a9db0 */
if(!s->budget--) { s->failed_pc=0x0c0a9db0u; return 0; }
tmp=read(ram,r[0],4);
r[0]=tmp;
goto P_0c0a9db2;
P_0c0a9db2: /* original c801, guest PC 0x0c0a9db2 */
if(!s->budget--) { s->failed_pc=0x0c0a9db2u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&1u)==0)!=0);
goto P_0c0a9db4;
P_0c0a9db4: /* original 8901, guest PC 0x0c0a9db4 */
if(!s->budget--) { s->failed_pc=0x0c0a9db4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a9dba; }
goto P_0c0a9db6;
P_0c0a9db6: /* original 6ec3, guest PC 0x0c0a9db6 */
if(!s->budget--) { s->failed_pc=0x0c0a9db6u; return 0; }
r[14]=r[12];
goto P_0c0a9db8;
P_0c0a9db8: /* original 6db3, guest PC 0x0c0a9db8 */
if(!s->budget--) { s->failed_pc=0x0c0a9db8u; return 0; }
r[13]=r[11];
goto P_0c0a9dba;
P_0c0a9dba: /* original 54dc, guest PC 0x0c0a9dba */
if(!s->budget--) { s->failed_pc=0x0c0a9dbau; return 0; }
r[4]=read(ram,r[13]+48,4);
goto P_0c0a9dbc;
P_0c0a9dbc: /* original d333, guest PC 0x0c0a9dbc */
if(!s->budget--) { s->failed_pc=0x0c0a9dbcu; return 0; }
r[3]=read(ram,0x0c0a9e8cu,4);
goto P_0c0a9dbe;
P_0c0a9dbe: /* original 644d, guest PC 0x0c0a9dbe */
if(!s->budget--) { s->failed_pc=0x0c0a9dbeu; return 0; }
r[4]=r[4]&65535u;
goto P_0c0a9dc0;
P_0c0a9dc0: /* original 430b, guest PC 0x0c0a9dc0 */
if(!s->budget--) { s->failed_pc=0x0c0a9dc0u; return 0; }
target=r[3];
r[16]=code_base|0x0c0a9dc4u;
r[5]=0x00000005u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a9dc4u) { target=s->pc; goto dispatch; }
goto P_0c0a9dc4;
P_0c0a9dc2: /* original e505, guest PC 0x0c0a9dc2 */
if(!s->budget--) { s->failed_pc=0x0c0a9dc2u; return 0; }
r[5]=0x00000005u;
goto P_0c0a9dc4;
P_0c0a9dc4: /* original 6403, guest PC 0x0c0a9dc4 */
if(!s->budget--) { s->failed_pc=0x0c0a9dc4u; return 0; }
r[4]=r[0];
goto P_0c0a9dc6;
P_0c0a9dc6: /* original 8442, guest PC 0x0c0a9dc6 */
if(!s->budget--) { s->failed_pc=0x0c0a9dc6u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+2,1);
goto P_0c0a9dc8;
P_0c0a9dc8: /* original d631, guest PC 0x0c0a9dc8 */
if(!s->budget--) { s->failed_pc=0x0c0a9dc8u; return 0; }
r[6]=read(ram,0x0c0a9e90u,4);
goto P_0c0a9dca;
P_0c0a9dca: /* original 600c, guest PC 0x0c0a9dca */
if(!s->budget--) { s->failed_pc=0x0c0a9dcau; return 0; }
r[0]=r[0]&255u;
goto P_0c0a9dcc;
P_0c0a9dcc: /* original d331, guest PC 0x0c0a9dcc */
if(!s->budget--) { s->failed_pc=0x0c0a9dccu; return 0; }
r[3]=read(ram,0x0c0a9e94u,4);
goto P_0c0a9dce;
P_0c0a9dce: /* original 4018, guest PC 0x0c0a9dce */
if(!s->budget--) { s->failed_pc=0x0c0a9dceu; return 0; }
r[0]<<=8;
goto P_0c0a9dd0;
P_0c0a9dd0: /* original 6503, guest PC 0x0c0a9dd0 */
if(!s->budget--) { s->failed_pc=0x0c0a9dd0u; return 0; }
r[5]=r[0];
goto P_0c0a9dd2;
P_0c0a9dd2: /* original 8441, guest PC 0x0c0a9dd2 */
if(!s->budget--) { s->failed_pc=0x0c0a9dd2u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+1,1);
goto P_0c0a9dd4;
P_0c0a9dd4: /* original 2569, guest PC 0x0c0a9dd4 */
if(!s->budget--) { s->failed_pc=0x0c0a9dd4u; return 0; }
r[5]&=r[6];
goto P_0c0a9dd6;
P_0c0a9dd6: /* original 600c, guest PC 0x0c0a9dd6 */
if(!s->budget--) { s->failed_pc=0x0c0a9dd6u; return 0; }
r[0]=r[0]&255u;
goto P_0c0a9dd8;
P_0c0a9dd8: /* original 250b, guest PC 0x0c0a9dd8 */
if(!s->budget--) { s->failed_pc=0x0c0a9dd8u; return 0; }
r[5]|=r[0];
goto P_0c0a9dda;
P_0c0a9dda: /* original e050, guest PC 0x0c0a9dda */
if(!s->budget--) { s->failed_pc=0x0c0a9ddau; return 0; }
r[0]=0x00000050u;
goto P_0c0a9ddc;
P_0c0a9ddc: /* original 02de, guest PC 0x0c0a9ddc */
if(!s->budget--) { s->failed_pc=0x0c0a9ddcu; return 0; }
r[2]=read(ram,r[13]+r[0],4);
goto P_0c0a9dde;
P_0c0a9dde: /* original 2238, guest PC 0x0c0a9dde */
if(!s->budget--) { s->failed_pc=0x0c0a9ddeu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c0a9de0;
P_0c0a9de0: /* original 8907, guest PC 0x0c0a9de0 */
if(!s->budget--) { s->failed_pc=0x0c0a9de0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a9df2; }
goto P_0c0a9de2;
P_0c0a9de2: /* original 8447, guest PC 0x0c0a9de2 */
if(!s->budget--) { s->failed_pc=0x0c0a9de2u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+7,1);
goto P_0c0a9de4;
P_0c0a9de4: /* original 600c, guest PC 0x0c0a9de4 */
if(!s->budget--) { s->failed_pc=0x0c0a9de4u; return 0; }
r[0]=r[0]&255u;
goto P_0c0a9de6;
P_0c0a9de6: /* original 4018, guest PC 0x0c0a9de6 */
if(!s->budget--) { s->failed_pc=0x0c0a9de6u; return 0; }
r[0]<<=8;
goto P_0c0a9de8;
P_0c0a9de8: /* original 6503, guest PC 0x0c0a9de8 */
if(!s->budget--) { s->failed_pc=0x0c0a9de8u; return 0; }
r[5]=r[0];
goto P_0c0a9dea;
P_0c0a9dea: /* original 8446, guest PC 0x0c0a9dea */
if(!s->budget--) { s->failed_pc=0x0c0a9deau; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+6,1);
goto P_0c0a9dec;
P_0c0a9dec: /* original 2569, guest PC 0x0c0a9dec */
if(!s->budget--) { s->failed_pc=0x0c0a9decu; return 0; }
r[5]&=r[6];
goto P_0c0a9dee;
P_0c0a9dee: /* original 600c, guest PC 0x0c0a9dee */
if(!s->budget--) { s->failed_pc=0x0c0a9deeu; return 0; }
r[0]=r[0]&255u;
goto P_0c0a9df0;
P_0c0a9df0: /* original 250b, guest PC 0x0c0a9df0 */
if(!s->budget--) { s->failed_pc=0x0c0a9df0u; return 0; }
r[5]|=r[0];
goto P_0c0a9df2;
P_0c0a9df2: /* original d329, guest PC 0x0c0a9df2 */
if(!s->budget--) { s->failed_pc=0x0c0a9df2u; return 0; }
r[3]=read(ram,0x0c0a9e98u,4);
goto P_0c0a9df4;
P_0c0a9df4: /* original 353c, guest PC 0x0c0a9df4 */
if(!s->budget--) { s->failed_pc=0x0c0a9df4u; return 0; }
r[5]+=r[3];
goto P_0c0a9df6;
P_0c0a9df6: /* original 1e5c, guest PC 0x0c0a9df6 */
if(!s->budget--) { s->failed_pc=0x0c0a9df6u; return 0; }
write(ram,r[14]+48,r[5],4);
goto P_0c0a9df8;
P_0c0a9df8: /* original 8443, guest PC 0x0c0a9df8 */
if(!s->budget--) { s->failed_pc=0x0c0a9df8u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+3,1);
goto P_0c0a9dfa;
P_0c0a9dfa: /* original 640c, guest PC 0x0c0a9dfa */
if(!s->budget--) { s->failed_pc=0x0c0a9dfau; return 0; }
r[4]=r[0]&255u;
goto P_0c0a9dfc;
P_0c0a9dfc: /* original 9040, guest PC 0x0c0a9dfc */
if(!s->budget--) { s->failed_pc=0x0c0a9dfcu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a9e80u,2);
goto P_0c0a9dfe;
P_0c0a9dfe: /* original 02dc, guest PC 0x0c0a9dfe */
if(!s->budget--) { s->failed_pc=0x0c0a9dfeu; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+r[0],1);
goto P_0c0a9e00;
P_0c0a9e00: /* original e064, guest PC 0x0c0a9e00 */
if(!s->budget--) { s->failed_pc=0x0c0a9e00u; return 0; }
r[0]=0x00000064u;
goto P_0c0a9e02;
P_0c0a9e02: /* original 622c, guest PC 0x0c0a9e02 */
if(!s->budget--) { s->failed_pc=0x0c0a9e02u; return 0; }
r[2]=r[2]&255u;
goto P_0c0a9e04;
P_0c0a9e04: /* original 7264, guest PC 0x0c0a9e04 */
if(!s->budget--) { s->failed_pc=0x0c0a9e04u; return 0; }
r[2]+=0x00000064u;
goto P_0c0a9e06;
P_0c0a9e06: /* original 0427, guest PC 0x0c0a9e06 */
if(!s->budget--) { s->failed_pc=0x0c0a9e06u; return 0; }
r[19]=r[4]*r[2];
goto P_0c0a9e08;
P_0c0a9e08: /* original d224, guest PC 0x0c0a9e08 */
if(!s->budget--) { s->failed_pc=0x0c0a9e08u; return 0; }
r[2]=read(ram,0x0c0a9e9cu,4);
goto P_0c0a9e0a;
P_0c0a9e0a: /* original 041a, guest PC 0x0c0a9e0a */
if(!s->budget--) { s->failed_pc=0x0c0a9e0au; return 0; }
r[4]=r[19];
goto P_0c0a9e0c;
P_0c0a9e0c: /* original 420b, guest PC 0x0c0a9e0c */
if(!s->budget--) { s->failed_pc=0x0c0a9e0cu; return 0; }
target=r[2];
r[16]=code_base|0x0c0a9e10u;
r[1]=r[4];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a9e10u) { target=s->pc; goto dispatch; }
goto P_0c0a9e10;
P_0c0a9e0e: /* original 6143, guest PC 0x0c0a9e0e */
if(!s->budget--) { s->failed_pc=0x0c0a9e0eu; return 0; }
r[1]=r[4];
goto P_0c0a9e10;
P_0c0a9e10: /* original 6403, guest PC 0x0c0a9e10 */
if(!s->budget--) { s->failed_pc=0x0c0a9e10u; return 0; }
r[4]=r[0];
goto P_0c0a9e12;
P_0c0a9e12: /* original 9036, guest PC 0x0c0a9e12 */
if(!s->budget--) { s->failed_pc=0x0c0a9e12u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a9e82u,2);
goto P_0c0a9e14;
P_0c0a9e14: /* original 0e44, guest PC 0x0c0a9e14 */
if(!s->budget--) { s->failed_pc=0x0c0a9e14u; return 0; }
write(ram,r[14]+r[0],r[4],1);
goto P_0c0a9e16;
P_0c0a9e16: /* original e048, guest PC 0x0c0a9e16 */
if(!s->budget--) { s->failed_pc=0x0c0a9e16u; return 0; }
r[0]=0x00000048u;
goto P_0c0a9e18;
P_0c0a9e18: /* original 9335, guest PC 0x0c0a9e18 */
if(!s->budget--) { s->failed_pc=0x0c0a9e18u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a9e86u,2);
goto P_0c0a9e1a;
P_0c0a9e1a: /* original 06de, guest PC 0x0c0a9e1a */
if(!s->budget--) { s->failed_pc=0x0c0a9e1au; return 0; }
r[6]=read(ram,r[13]+r[0],4);
goto P_0c0a9e1c;
P_0c0a9e1c: /* original 9232, guest PC 0x0c0a9e1c */
if(!s->budget--) { s->failed_pc=0x0c0a9e1cu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a9e84u,2);
goto P_0c0a9e1e;
P_0c0a9e1e: /* original 07ee, guest PC 0x0c0a9e1e */
if(!s->budget--) { s->failed_pc=0x0c0a9e1eu; return 0; }
r[7]=read(ram,r[14]+r[0],4);
goto P_0c0a9e20;
P_0c0a9e20: /* original 2368, guest PC 0x0c0a9e20 */
if(!s->budget--) { s->failed_pc=0x0c0a9e20u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[6])==0)!=0);
goto P_0c0a9e22;
P_0c0a9e22: /* original 64d2, guest PC 0x0c0a9e22 */
if(!s->budget--) { s->failed_pc=0x0c0a9e22u; return 0; }
tmp=read(ram,r[13],4);
r[4]=tmp;
goto P_0c0a9e24;
P_0c0a9e24: /* original 65e2, guest PC 0x0c0a9e24 */
if(!s->budget--) { s->failed_pc=0x0c0a9e24u; return 0; }
tmp=read(ram,r[14],4);
r[5]=tmp;
goto P_0c0a9e26;
P_0c0a9e26: /* original 8d02, guest PC 0x0c0a9e26 */
if(!s->budget--) { s->failed_pc=0x0c0a9e26u; return 0; }
cond=r[17]&1u;
r[7]&=r[2];
if(cond) { goto P_0c0a9e2e; }
goto P_0c0a9e2a;
P_0c0a9e28: /* original 2729, guest PC 0x0c0a9e28 */
if(!s->budget--) { s->failed_pc=0x0c0a9e28u; return 0; }
r[7]&=r[2];
goto P_0c0a9e2a;
P_0c0a9e2a: /* original a002, guest PC 0x0c0a9e2a */
if(!s->budget--) { s->failed_pc=0x0c0a9e2au; return 0; }
r[6]|=r[8];
goto P_0c0a9e32;
P_0c0a9e2c: /* original 268b, guest PC 0x0c0a9e2c */
if(!s->budget--) { s->failed_pc=0x0c0a9e2cu; return 0; }
r[6]|=r[8];
goto P_0c0a9e2e;
P_0c0a9e2e: /* original d11c, guest PC 0x0c0a9e2e */
if(!s->budget--) { s->failed_pc=0x0c0a9e2eu; return 0; }
r[1]=read(ram,0x0c0a9ea0u,4);
goto P_0c0a9e30;
P_0c0a9e30: /* original 2619, guest PC 0x0c0a9e30 */
if(!s->budget--) { s->failed_pc=0x0c0a9e30u; return 0; }
r[6]&=r[1];
goto P_0c0a9e32;
P_0c0a9e32: /* original 246a, guest PC 0x0c0a9e32 */
if(!s->budget--) { s->failed_pc=0x0c0a9e32u; return 0; }
r[4]^=r[6];
goto P_0c0a9e34;
P_0c0a9e34: /* original 2488, guest PC 0x0c0a9e34 */
if(!s->budget--) { s->failed_pc=0x0c0a9e34u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[8])==0)!=0);
goto P_0c0a9e36;
P_0c0a9e36: /* original 8d02, guest PC 0x0c0a9e36 */
if(!s->budget--) { s->failed_pc=0x0c0a9e36u; return 0; }
cond=r[17]&1u;
write(ram,r[14]+r[0],r[7],4);
if(cond) { goto P_0c0a9e3e; }
goto P_0c0a9e3a;
P_0c0a9e38: /* original 0e76, guest PC 0x0c0a9e38 */
if(!s->budget--) { s->failed_pc=0x0c0a9e38u; return 0; }
write(ram,r[14]+r[0],r[7],4);
goto P_0c0a9e3a;
P_0c0a9e3a: /* original a002, guest PC 0x0c0a9e3a */
if(!s->budget--) { s->failed_pc=0x0c0a9e3au; return 0; }
r[5]|=r[8];
goto P_0c0a9e42;
P_0c0a9e3c: /* original 258b, guest PC 0x0c0a9e3c */
if(!s->budget--) { s->failed_pc=0x0c0a9e3cu; return 0; }
r[5]|=r[8];
goto P_0c0a9e3e;
P_0c0a9e3e: /* original d318, guest PC 0x0c0a9e3e */
if(!s->budget--) { s->failed_pc=0x0c0a9e3eu; return 0; }
r[3]=read(ram,0x0c0a9ea0u,4);
goto P_0c0a9e40;
P_0c0a9e40: /* original 2539, guest PC 0x0c0a9e40 */
if(!s->budget--) { s->failed_pc=0x0c0a9e40u; return 0; }
r[5]&=r[3];
goto P_0c0a9e42;
P_0c0a9e42: /* original 2e52, guest PC 0x0c0a9e42 */
if(!s->budget--) { s->failed_pc=0x0c0a9e42u; return 0; }
write(ram,r[14],r[5],4);
goto P_0c0a9e44;
P_0c0a9e44: /* original 7f04, guest PC 0x0c0a9e44 */
if(!s->budget--) { s->failed_pc=0x0c0a9e44u; return 0; }
r[15]+=0x00000004u;
goto P_0c0a9e46;
P_0c0a9e46: /* original 4f16, guest PC 0x0c0a9e46 */
if(!s->budget--) { s->failed_pc=0x0c0a9e46u; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a9e48;
P_0c0a9e48: /* original e400, guest PC 0x0c0a9e48 */
if(!s->budget--) { s->failed_pc=0x0c0a9e48u; return 0; }
r[4]=0x00000000u;
goto P_0c0a9e4a;
P_0c0a9e4a: /* original 1c4d, guest PC 0x0c0a9e4a */
if(!s->budget--) { s->failed_pc=0x0c0a9e4au; return 0; }
write(ram,r[12]+52,r[4],4);
goto P_0c0a9e4c;
P_0c0a9e4c: /* original 4f26, guest PC 0x0c0a9e4c */
if(!s->budget--) { s->failed_pc=0x0c0a9e4cu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a9e4e;
P_0c0a9e4e: /* original 1b4d, guest PC 0x0c0a9e4e */
if(!s->budget--) { s->failed_pc=0x0c0a9e4eu; return 0; }
write(ram,r[11]+52,r[4],4);
goto P_0c0a9e50;
P_0c0a9e50: /* original 68f6, guest PC 0x0c0a9e50 */
if(!s->budget--) { s->failed_pc=0x0c0a9e50u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c0a9e52;
P_0c0a9e52: /* original 69f6, guest PC 0x0c0a9e52 */
if(!s->budget--) { s->failed_pc=0x0c0a9e52u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c0a9e54;
P_0c0a9e54: /* original 6af6, guest PC 0x0c0a9e54 */
if(!s->budget--) { s->failed_pc=0x0c0a9e54u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0a9e56;
P_0c0a9e56: /* original 6bf6, guest PC 0x0c0a9e56 */
if(!s->budget--) { s->failed_pc=0x0c0a9e56u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0a9e58;
P_0c0a9e58: /* original 6cf6, guest PC 0x0c0a9e58 */
if(!s->budget--) { s->failed_pc=0x0c0a9e58u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0a9e5a;
P_0c0a9e5a: /* original 6df6, guest PC 0x0c0a9e5a */
if(!s->budget--) { s->failed_pc=0x0c0a9e5au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0a9e5c;
P_0c0a9e5c: /* original 000b, guest PC 0x0c0a9e5c */
if(!s->budget--) { s->failed_pc=0x0c0a9e5cu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0a9e5e: /* original 6ef6, guest PC 0x0c0a9e5e */
if(!s->budget--) { s->failed_pc=0x0c0a9e5eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0a9e60u,s,ram);
unsupported: s->failed_pc=target; return 0;
}
