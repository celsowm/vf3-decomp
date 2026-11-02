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
int vf3_away_batch3_adapter_14(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c043a7cu: goto P_0c043a7c;
case 0x0c043a7eu: goto P_0c043a7e;
case 0x0c043a80u: goto P_0c043a80;
case 0x0c043a82u: goto P_0c043a82;
case 0x0c043a84u: goto P_0c043a84;
case 0x0c043a86u: goto P_0c043a86;
case 0x0c043a88u: goto P_0c043a88;
case 0x0c043a8au: goto P_0c043a8a;
case 0x0c043a8cu: goto P_0c043a8c;
case 0x0c043a8eu: goto P_0c043a8e;
case 0x0c043a90u: goto P_0c043a90;
case 0x0c043a92u: goto P_0c043a92;
case 0x0c043a94u: goto P_0c043a94;
case 0x0c043a96u: goto P_0c043a96;
case 0x0c043a98u: goto P_0c043a98;
case 0x0c043a9au: goto P_0c043a9a;
case 0x0c043a9cu: goto P_0c043a9c;
case 0x0c043a9eu: goto P_0c043a9e;
case 0x0c043aa0u: goto P_0c043aa0;
case 0x0c043aa2u: goto P_0c043aa2;
case 0x0c043aa4u: goto P_0c043aa4;
case 0x0c043aa6u: goto P_0c043aa6;
case 0x0c043aa8u: goto P_0c043aa8;
case 0x0c043aaau: goto P_0c043aaa;
case 0x0c043aacu: goto P_0c043aac;
case 0x0c043aaeu: goto P_0c043aae;
case 0x0c043ab0u: goto P_0c043ab0;
case 0x0c043ab2u: goto P_0c043ab2;
case 0x0c043ab4u: goto P_0c043ab4;
case 0x0c043ab6u: goto P_0c043ab6;
case 0x0c043ab8u: goto P_0c043ab8;
case 0x0c043abau: goto P_0c043aba;
case 0x0c043abcu: goto P_0c043abc;
case 0x0c043bb4u: goto P_0c043bb4;
case 0x0c043bb6u: goto P_0c043bb6;
case 0x0c043bb8u: goto P_0c043bb8;
case 0x0c043bbau: goto P_0c043bba;
case 0x0c043bbcu: goto P_0c043bbc;
case 0x0c043bbeu: goto P_0c043bbe;
case 0x0c043bc0u: goto P_0c043bc0;
case 0x0c043bc2u: goto P_0c043bc2;
case 0x0c043bc4u: goto P_0c043bc4;
case 0x0c043bc6u: goto P_0c043bc6;
case 0x0c043bc8u: goto P_0c043bc8;
case 0x0c043bcau: goto P_0c043bca;
case 0x0c043bccu: goto P_0c043bcc;
case 0x0c043bceu: goto P_0c043bce;
case 0x0c043bd0u: goto P_0c043bd0;
case 0x0c043bd2u: goto P_0c043bd2;
case 0x0c043bd4u: goto P_0c043bd4;
case 0x0c043bd6u: goto P_0c043bd6;
case 0x0c043bd8u: goto P_0c043bd8;
case 0x0c043bdau: goto P_0c043bda;
case 0x0c043bdcu: goto P_0c043bdc;
case 0x0c043bdeu: goto P_0c043bde;
case 0x0c043be0u: goto P_0c043be0;
case 0x0c043be2u: goto P_0c043be2;
case 0x0c043be4u: goto P_0c043be4;
case 0x0c043be6u: goto P_0c043be6;
case 0x0c043be8u: goto P_0c043be8;
case 0x0c043beau: goto P_0c043bea;
case 0x0c043becu: goto P_0c043bec;
case 0x0c043beeu: goto P_0c043bee;
case 0x0c043bf0u: goto P_0c043bf0;
case 0x0c043bf2u: goto P_0c043bf2;
case 0x0c043bf4u: goto P_0c043bf4;
case 0x0c043bf6u: goto P_0c043bf6;
case 0x0c043bf8u: goto P_0c043bf8;
case 0x0c043bfau: goto P_0c043bfa;
case 0x0c043bfcu: goto P_0c043bfc;
case 0x0c043bfeu: goto P_0c043bfe;
case 0x0c043c00u: goto P_0c043c00;
case 0x0c043c02u: goto P_0c043c02;
case 0x0c043c04u: goto P_0c043c04;
case 0x0c043c06u: goto P_0c043c06;
case 0x0c043c08u: goto P_0c043c08;
case 0x0c043c0au: goto P_0c043c0a;
case 0x0c043c0cu: goto P_0c043c0c;
case 0x0c043c0eu: goto P_0c043c0e;
case 0x0c043c10u: goto P_0c043c10;
case 0x0c043c12u: goto P_0c043c12;
case 0x0c043c14u: goto P_0c043c14;
case 0x0c043c16u: goto P_0c043c16;
case 0x0c043c18u: goto P_0c043c18;
case 0x0c043c1au: goto P_0c043c1a;
case 0x0c043c1cu: goto P_0c043c1c;
case 0x0c043c1eu: goto P_0c043c1e;
case 0x0c043c20u: goto P_0c043c20;
case 0x0c043c22u: goto P_0c043c22;
case 0x0c043c24u: goto P_0c043c24;
case 0x0c043c26u: goto P_0c043c26;
case 0x0c043c28u: goto P_0c043c28;
case 0x0c043c2au: goto P_0c043c2a;
case 0x0c043c2cu: goto P_0c043c2c;
case 0x0c043c2eu: goto P_0c043c2e;
case 0x0c043c30u: goto P_0c043c30;
case 0x0c043c32u: goto P_0c043c32;
case 0x0c043c34u: goto P_0c043c34;
case 0x0c043c36u: goto P_0c043c36;
case 0x0c043c38u: goto P_0c043c38;
case 0x0c043c3au: goto P_0c043c3a;
case 0x0c043c3cu: goto P_0c043c3c;
case 0x0c043c3eu: goto P_0c043c3e;
case 0x0c043c40u: goto P_0c043c40;
case 0x0c043c42u: goto P_0c043c42;
case 0x0c043c44u: goto P_0c043c44;
case 0x0c043c46u: goto P_0c043c46;
case 0x0c043c48u: goto P_0c043c48;
case 0x0c043c4au: goto P_0c043c4a;
case 0x0c043c4cu: goto P_0c043c4c;
case 0x0c043c4eu: goto P_0c043c4e;
case 0x0c043c50u: goto P_0c043c50;
case 0x0c043c52u: goto P_0c043c52;
case 0x0c043c54u: goto P_0c043c54;
case 0x0c043c56u: goto P_0c043c56;
case 0x0c043c58u: goto P_0c043c58;
case 0x0c043c5au: goto P_0c043c5a;
case 0x0c043c5cu: goto P_0c043c5c;
case 0x0c043c5eu: goto P_0c043c5e;
case 0x0c043c60u: goto P_0c043c60;
case 0x0c043c62u: goto P_0c043c62;
case 0x0c043c64u: goto P_0c043c64;
case 0x0c043c66u: goto P_0c043c66;
case 0x0c043c68u: goto P_0c043c68;
case 0x0c043c6au: goto P_0c043c6a;
case 0x0c043c6cu: goto P_0c043c6c;
case 0x0c043c6eu: goto P_0c043c6e;
case 0x0c043c70u: goto P_0c043c70;
case 0x0c043c72u: goto P_0c043c72;
case 0x0c043c74u: goto P_0c043c74;
case 0x0c043c76u: goto P_0c043c76;
case 0x0c043c78u: goto P_0c043c78;
case 0x0c043c7au: goto P_0c043c7a;
case 0x0c043c7cu: goto P_0c043c7c;
case 0x0c043c7eu: goto P_0c043c7e;
case 0x0c043c80u: goto P_0c043c80;
case 0x0c043ca4u: goto P_0c043ca4;
case 0x0c043ca6u: goto P_0c043ca6;
case 0x0c043ca8u: goto P_0c043ca8;
case 0x0c043caau: goto P_0c043caa;
case 0x0c043cacu: goto P_0c043cac;
case 0x0c043caeu: goto P_0c043cae;
case 0x0c043cb0u: goto P_0c043cb0;
case 0x0c043cb2u: goto P_0c043cb2;
case 0x0c043cb4u: goto P_0c043cb4;
case 0x0c043cb6u: goto P_0c043cb6;
case 0x0c043cb8u: goto P_0c043cb8;
case 0x0c043cbau: goto P_0c043cba;
case 0x0c043cbcu: goto P_0c043cbc;
case 0x0c043cbeu: goto P_0c043cbe;
case 0x0c043cc0u: goto P_0c043cc0;
case 0x0c043cc2u: goto P_0c043cc2;
case 0x0c043cc4u: goto P_0c043cc4;
case 0x0c043cc6u: goto P_0c043cc6;
case 0x0c043cc8u: goto P_0c043cc8;
case 0x0c043ccau: goto P_0c043cca;
case 0x0c043cccu: goto P_0c043ccc;
case 0x0c043cceu: goto P_0c043cce;
case 0x0c043cd0u: goto P_0c043cd0;
case 0x0c043cd2u: goto P_0c043cd2;
case 0x0c043cd4u: goto P_0c043cd4;
case 0x0c043cd6u: goto P_0c043cd6;
case 0x0c043cd8u: goto P_0c043cd8;
case 0x0c043cdau: goto P_0c043cda;
case 0x0c043cdcu: goto P_0c043cdc;
case 0x0c043cdeu: goto P_0c043cde;
case 0x0c043ce0u: goto P_0c043ce0;
case 0x0c043ce2u: goto P_0c043ce2;
case 0x0c043ce4u: goto P_0c043ce4;
case 0x0c043ce6u: goto P_0c043ce6;
case 0x0c043ce8u: goto P_0c043ce8;
case 0x0c043ceau: goto P_0c043cea;
case 0x0c043cecu: goto P_0c043cec;
case 0x0c043ceeu: goto P_0c043cee;
case 0x0c043cf0u: goto P_0c043cf0;
case 0x0c043cf2u: goto P_0c043cf2;
case 0x0c043cf4u: goto P_0c043cf4;
case 0x0c043cf6u: goto P_0c043cf6;
case 0x0c043cf8u: goto P_0c043cf8;
case 0x0c043cfau: goto P_0c043cfa;
case 0x0c043cfcu: goto P_0c043cfc;
case 0x0c043cfeu: goto P_0c043cfe;
case 0x0c043d00u: goto P_0c043d00;
case 0x0c043d02u: goto P_0c043d02;
case 0x0c043d04u: goto P_0c043d04;
case 0x0c043d06u: goto P_0c043d06;
case 0x0c043d08u: goto P_0c043d08;
case 0x0c043d0au: goto P_0c043d0a;
case 0x0c043d0cu: goto P_0c043d0c;
case 0x0c043d0eu: goto P_0c043d0e;
case 0x0c043d10u: goto P_0c043d10;
case 0x0c043d12u: goto P_0c043d12;
case 0x0c043d14u: goto P_0c043d14;
case 0x0c043d16u: goto P_0c043d16;
case 0x0c043d18u: goto P_0c043d18;
case 0x0c043d1au: goto P_0c043d1a;
case 0x0c043d1cu: goto P_0c043d1c;
case 0x0c043d1eu: goto P_0c043d1e;
case 0x0c043d20u: goto P_0c043d20;
case 0x0c043d22u: goto P_0c043d22;
case 0x0c043d24u: goto P_0c043d24;
case 0x0c043d26u: goto P_0c043d26;
case 0x0c043d28u: goto P_0c043d28;
case 0x0c043d2au: goto P_0c043d2a;
case 0x0c043d2cu: goto P_0c043d2c;
case 0x0c043d2eu: goto P_0c043d2e;
case 0x0c043d30u: goto P_0c043d30;
case 0x0c043d32u: goto P_0c043d32;
case 0x0c043d34u: goto P_0c043d34;
case 0x0c043d36u: goto P_0c043d36;
case 0x0c043d38u: goto P_0c043d38;
case 0x0c043d3au: goto P_0c043d3a;
case 0x0c043d3cu: goto P_0c043d3c;
case 0x0c043d3eu: goto P_0c043d3e;
case 0x0c043d40u: goto P_0c043d40;
case 0x0c043d42u: goto P_0c043d42;
case 0x0c043d44u: goto P_0c043d44;
case 0x0c043d46u: goto P_0c043d46;
case 0x0c043d48u: goto P_0c043d48;
case 0x0c043d4au: goto P_0c043d4a;
case 0x0c043d4cu: goto P_0c043d4c;
case 0x0c043d4eu: goto P_0c043d4e;
case 0x0c043d50u: goto P_0c043d50;
case 0x0c043d52u: goto P_0c043d52;
case 0x0c043d54u: goto P_0c043d54;
case 0x0c043d56u: goto P_0c043d56;
case 0x0c043d58u: goto P_0c043d58;
case 0x0c043d5au: goto P_0c043d5a;
case 0x0c043d5cu: goto P_0c043d5c;
case 0x0c043d5eu: goto P_0c043d5e;
case 0x0c043d60u: goto P_0c043d60;
case 0x0c043d62u: goto P_0c043d62;
case 0x0c043d64u: goto P_0c043d64;
case 0x0c043d66u: goto P_0c043d66;
case 0x0c043d68u: goto P_0c043d68;
case 0x0c043d6au: goto P_0c043d6a;
case 0x0c043d6cu: goto P_0c043d6c;
case 0x0c043d6eu: goto P_0c043d6e;
case 0x0c043d70u: goto P_0c043d70;
case 0x0c043d72u: goto P_0c043d72;
case 0x0c043d74u: goto P_0c043d74;
case 0x0c043d76u: goto P_0c043d76;
case 0x0c043d78u: goto P_0c043d78;
case 0x0c043d7au: goto P_0c043d7a;
case 0x0c043d7cu: goto P_0c043d7c;
case 0x0c043d7eu: goto P_0c043d7e;
case 0x0c043db4u: goto P_0c043db4;
case 0x0c043db6u: goto P_0c043db6;
case 0x0c043db8u: goto P_0c043db8;
case 0x0c043dbau: goto P_0c043dba;
case 0x0c043dbcu: goto P_0c043dbc;
case 0x0c043dbeu: goto P_0c043dbe;
case 0x0c043dc0u: goto P_0c043dc0;
case 0x0c043dc2u: goto P_0c043dc2;
case 0x0c043dc4u: goto P_0c043dc4;
case 0x0c043dc6u: goto P_0c043dc6;
case 0x0c043dc8u: goto P_0c043dc8;
case 0x0c043dcau: goto P_0c043dca;
case 0x0c043dccu: goto P_0c043dcc;
case 0x0c043dceu: goto P_0c043dce;
case 0x0c043dd0u: goto P_0c043dd0;
case 0x0c043dd2u: goto P_0c043dd2;
case 0x0c043dd4u: goto P_0c043dd4;
case 0x0c043dd6u: goto P_0c043dd6;
case 0x0c043dd8u: goto P_0c043dd8;
case 0x0c043ddau: goto P_0c043dda;
case 0x0c043ddcu: goto P_0c043ddc;
case 0x0c043ddeu: goto P_0c043dde;
case 0x0c043de0u: goto P_0c043de0;
case 0x0c043de2u: goto P_0c043de2;
case 0x0c043de4u: goto P_0c043de4;
case 0x0c043de6u: goto P_0c043de6;
case 0x0c043de8u: goto P_0c043de8;
case 0x0c043deau: goto P_0c043dea;
case 0x0c043decu: goto P_0c043dec;
case 0x0c043deeu: goto P_0c043dee;
case 0x0c043df0u: goto P_0c043df0;
case 0x0c043df2u: goto P_0c043df2;
case 0x0c043df4u: goto P_0c043df4;
case 0x0c043df6u: goto P_0c043df6;
case 0x0c043df8u: goto P_0c043df8;
case 0x0c043dfau: goto P_0c043dfa;
case 0x0c043dfcu: goto P_0c043dfc;
case 0x0c043dfeu: goto P_0c043dfe;
case 0x0c043e00u: goto P_0c043e00;
case 0x0c043e02u: goto P_0c043e02;
case 0x0c043e04u: goto P_0c043e04;
case 0x0c043e06u: goto P_0c043e06;
case 0x0c043e08u: goto P_0c043e08;
case 0x0c043e0au: goto P_0c043e0a;
case 0x0c043e0cu: goto P_0c043e0c;
case 0x0c043e0eu: goto P_0c043e0e;
case 0x0c043e10u: goto P_0c043e10;
case 0x0c043e12u: goto P_0c043e12;
case 0x0c043e14u: goto P_0c043e14;
case 0x0c043e16u: goto P_0c043e16;
case 0x0c043e18u: goto P_0c043e18;
case 0x0c043e1au: goto P_0c043e1a;
case 0x0c043e1cu: goto P_0c043e1c;
case 0x0c043e1eu: goto P_0c043e1e;
case 0x0c043e20u: goto P_0c043e20;
case 0x0c043e22u: goto P_0c043e22;
case 0x0c043e24u: goto P_0c043e24;
case 0x0c043e26u: goto P_0c043e26;
case 0x0c043e28u: goto P_0c043e28;
case 0x0c043e2au: goto P_0c043e2a;
case 0x0c043e2cu: goto P_0c043e2c;
case 0x0c043e2eu: goto P_0c043e2e;
case 0x0c043e30u: goto P_0c043e30;
case 0x0c043e32u: goto P_0c043e32;
case 0x0c043e34u: goto P_0c043e34;
case 0x0c043e36u: goto P_0c043e36;
case 0x0c043e38u: goto P_0c043e38;
case 0x0c043e3au: goto P_0c043e3a;
case 0x0c043e3cu: goto P_0c043e3c;
case 0x0c043e3eu: goto P_0c043e3e;
case 0x0c043e40u: goto P_0c043e40;
case 0x0c043e42u: goto P_0c043e42;
case 0x0c043e44u: goto P_0c043e44;
case 0x0c043e46u: goto P_0c043e46;
case 0x0c043e48u: goto P_0c043e48;
case 0x0c043e4au: goto P_0c043e4a;
case 0x0c043e4cu: goto P_0c043e4c;
case 0x0c043e4eu: goto P_0c043e4e;
case 0x0c043e50u: goto P_0c043e50;
default: return vf3_matrix_family(target,s,ram);
}
P_0c043a7c: /* original d33e, guest PC 0x0c043a7c */
if(!s->budget--) { s->failed_pc=0x0c043a7cu; return 0; }
r[3]=read(ram,0x0c043b78u,4);
goto P_0c043a7e;
P_0c043a7e: /* original e600, guest PC 0x0c043a7e */
if(!s->budget--) { s->failed_pc=0x0c043a7eu; return 0; }
r[6]=0x00000000u;
goto P_0c043a80;
P_0c043a80: /* original d53c, guest PC 0x0c043a80 */
if(!s->budget--) { s->failed_pc=0x0c043a80u; return 0; }
r[5]=read(ram,0x0c043b74u,4);
goto P_0c043a82;
P_0c043a82: /* original e718, guest PC 0x0c043a82 */
if(!s->budget--) { s->failed_pc=0x0c043a82u; return 0; }
r[7]=0x00000018u;
goto P_0c043a84;
P_0c043a84: /* original 6432, guest PC 0x0c043a84 */
if(!s->budget--) { s->failed_pc=0x0c043a84u; return 0; }
tmp=read(ram,r[3],4);
r[4]=tmp;
goto P_0c043a86;
P_0c043a86: /* original 7428, guest PC 0x0c043a86 */
if(!s->budget--) { s->failed_pc=0x0c043a86u; return 0; }
r[4]+=0x00000028u;
goto P_0c043a88;
P_0c043a88: /* original 6240, guest PC 0x0c043a88 */
if(!s->budget--) { s->failed_pc=0x0c043a88u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[4],1);
r[2]=tmp;
goto P_0c043a8a;
P_0c043a8a: /* original 7601, guest PC 0x0c043a8a */
if(!s->budget--) { s->failed_pc=0x0c043a8au; return 0; }
r[6]+=0x00000001u;
goto P_0c043a8c;
P_0c043a8c: /* original 3673, guest PC 0x0c043a8c */
if(!s->budget--) { s->failed_pc=0x0c043a8cu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[6]>=(int32_t)r[7])!=0);
goto P_0c043a8e;
P_0c043a8e: /* original 2520, guest PC 0x0c043a8e */
if(!s->budget--) { s->failed_pc=0x0c043a8eu; return 0; }
write(ram,r[5],r[2],1);
goto P_0c043a90;
P_0c043a90: /* original 8441, guest PC 0x0c043a90 */
if(!s->budget--) { s->failed_pc=0x0c043a90u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+1,1);
goto P_0c043a92;
P_0c043a92: /* original 8051, guest PC 0x0c043a92 */
if(!s->budget--) { s->failed_pc=0x0c043a92u; return 0; }
write(ram,r[5]+1,r[0],1);
goto P_0c043a94;
P_0c043a94: /* original 8442, guest PC 0x0c043a94 */
if(!s->budget--) { s->failed_pc=0x0c043a94u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+2,1);
goto P_0c043a96;
P_0c043a96: /* original 8052, guest PC 0x0c043a96 */
if(!s->budget--) { s->failed_pc=0x0c043a96u; return 0; }
write(ram,r[5]+2,r[0],1);
goto P_0c043a98;
P_0c043a98: /* original 8443, guest PC 0x0c043a98 */
if(!s->budget--) { s->failed_pc=0x0c043a98u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+3,1);
goto P_0c043a9a;
P_0c043a9a: /* original 8053, guest PC 0x0c043a9a */
if(!s->budget--) { s->failed_pc=0x0c043a9au; return 0; }
write(ram,r[5]+3,r[0],1);
goto P_0c043a9c;
P_0c043a9c: /* original 5344, guest PC 0x0c043a9c */
if(!s->budget--) { s->failed_pc=0x0c043a9cu; return 0; }
r[3]=read(ram,r[4]+16,4);
goto P_0c043a9e;
P_0c043a9e: /* original 1532, guest PC 0x0c043a9e */
if(!s->budget--) { s->failed_pc=0x0c043a9eu; return 0; }
write(ram,r[5]+8,r[3],4);
goto P_0c043aa0;
P_0c043aa0: /* original 8448, guest PC 0x0c043aa0 */
if(!s->budget--) { s->failed_pc=0x0c043aa0u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+8,1);
goto P_0c043aa2;
P_0c043aa2: /* original 8054, guest PC 0x0c043aa2 */
if(!s->budget--) { s->failed_pc=0x0c043aa2u; return 0; }
write(ram,r[5]+4,r[0],1);
goto P_0c043aa4;
P_0c043aa4: /* original 8449, guest PC 0x0c043aa4 */
if(!s->budget--) { s->failed_pc=0x0c043aa4u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+9,1);
goto P_0c043aa6;
P_0c043aa6: /* original 8055, guest PC 0x0c043aa6 */
if(!s->budget--) { s->failed_pc=0x0c043aa6u; return 0; }
write(ram,r[5]+5,r[0],1);
goto P_0c043aa8;
P_0c043aa8: /* original 844a, guest PC 0x0c043aa8 */
if(!s->budget--) { s->failed_pc=0x0c043aa8u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+10,1);
goto P_0c043aaa;
P_0c043aaa: /* original 8056, guest PC 0x0c043aaa */
if(!s->budget--) { s->failed_pc=0x0c043aaau; return 0; }
write(ram,r[5]+6,r[0],1);
goto P_0c043aac;
P_0c043aac: /* original 844b, guest PC 0x0c043aac */
if(!s->budget--) { s->failed_pc=0x0c043aacu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+11,1);
goto P_0c043aae;
P_0c043aae: /* original 8057, guest PC 0x0c043aae */
if(!s->budget--) { s->failed_pc=0x0c043aaeu; return 0; }
write(ram,r[5]+7,r[0],1);
goto P_0c043ab0;
P_0c043ab0: /* original 5345, guest PC 0x0c043ab0 */
if(!s->budget--) { s->failed_pc=0x0c043ab0u; return 0; }
r[3]=read(ram,r[4]+20,4);
goto P_0c043ab2;
P_0c043ab2: /* original 1533, guest PC 0x0c043ab2 */
if(!s->budget--) { s->failed_pc=0x0c043ab2u; return 0; }
write(ram,r[5]+12,r[3],4);
goto P_0c043ab4;
P_0c043ab4: /* original 7518, guest PC 0x0c043ab4 */
if(!s->budget--) { s->failed_pc=0x0c043ab4u; return 0; }
r[5]+=0x00000018u;
goto P_0c043ab6;
P_0c043ab6: /* original 8fe7, guest PC 0x0c043ab6 */
if(!s->budget--) { s->failed_pc=0x0c043ab6u; return 0; }
cond=r[17]&1u;
r[4]+=0x0000002cu;
if(!cond) { goto P_0c043a88; }
goto P_0c043aba;
P_0c043ab8: /* original 742c, guest PC 0x0c043ab8 */
if(!s->budget--) { s->failed_pc=0x0c043ab8u; return 0; }
r[4]+=0x0000002cu;
goto P_0c043aba;
P_0c043aba: /* original 000b, guest PC 0x0c043aba */
if(!s->budget--) { s->failed_pc=0x0c043abau; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c043abc: /* original 0009, guest PC 0x0c043abc */
if(!s->budget--) { s->failed_pc=0x0c043abcu; return 0; }
if(!vf3_matrix_family(0x0c043abeu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c043abeu; return 0; } return 1;
P_0c043bb4: /* original 2fe6, guest PC 0x0c043bb4 */
if(!s->budget--) { s->failed_pc=0x0c043bb4u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c043bb6;
P_0c043bb6: /* original 2fd6, guest PC 0x0c043bb6 */
if(!s->budget--) { s->failed_pc=0x0c043bb6u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c043bb8;
P_0c043bb8: /* original 2fc6, guest PC 0x0c043bb8 */
if(!s->budget--) { s->failed_pc=0x0c043bb8u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c043bba;
P_0c043bba: /* original 4f22, guest PC 0x0c043bba */
if(!s->budget--) { s->failed_pc=0x0c043bbau; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c043bbc;
P_0c043bbc: /* original de35, guest PC 0x0c043bbc */
if(!s->budget--) { s->failed_pc=0x0c043bbcu; return 0; }
r[14]=read(ram,0x0c043c94u,4);
goto P_0c043bbe;
P_0c043bbe: /* original 9360, guest PC 0x0c043bbe */
if(!s->budget--) { s->failed_pc=0x0c043bbeu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c043c82u,2);
goto P_0c043bc0;
P_0c043bc0: /* original dc32, guest PC 0x0c043bc0 */
if(!s->budget--) { s->failed_pc=0x0c043bc0u; return 0; }
r[12]=read(ram,0x0c043c8cu,4);
goto P_0c043bc2;
P_0c043bc2: /* original dd33, guest PC 0x0c043bc2 */
if(!s->budget--) { s->failed_pc=0x0c043bc2u; return 0; }
r[13]=read(ram,0x0c043c90u,4);
goto P_0c043bc4;
P_0c043bc4: /* original 62c2, guest PC 0x0c043bc4 */
if(!s->budget--) { s->failed_pc=0x0c043bc4u; return 0; }
tmp=read(ram,r[12],4);
r[2]=tmp;
goto P_0c043bc6;
P_0c043bc6: /* original 2238, guest PC 0x0c043bc6 */
if(!s->budget--) { s->failed_pc=0x0c043bc6u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c043bc8;
P_0c043bc8: /* original 896c, guest PC 0x0c043bc8 */
if(!s->budget--) { s->failed_pc=0x0c043bc8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c043ca4; }
goto P_0c043bca;
P_0c043bca: /* original 925b, guest PC 0x0c043bca */
if(!s->budget--) { s->failed_pc=0x0c043bcau; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c043c84u,2);
goto P_0c043bcc;
P_0c043bcc: /* original 61c2, guest PC 0x0c043bcc */
if(!s->budget--) { s->failed_pc=0x0c043bccu; return 0; }
tmp=read(ram,r[12],4);
r[1]=tmp;
goto P_0c043bce;
P_0c043bce: /* original 2128, guest PC 0x0c043bce */
if(!s->budget--) { s->failed_pc=0x0c043bceu; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[2])==0)!=0);
goto P_0c043bd0;
P_0c043bd0: /* original 890b, guest PC 0x0c043bd0 */
if(!s->budget--) { s->failed_pc=0x0c043bd0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c043bea; }
goto P_0c043bd2;
P_0c043bd2: /* original 51e7, guest PC 0x0c043bd2 */
if(!s->budget--) { s->failed_pc=0x0c043bd2u; return 0; }
r[1]=read(ram,r[14]+28,4);
goto P_0c043bd4;
P_0c043bd4: /* original 7101, guest PC 0x0c043bd4 */
if(!s->budget--) { s->failed_pc=0x0c043bd4u; return 0; }
r[1]+=0x00000001u;
goto P_0c043bd6;
P_0c043bd6: /* original 1e17, guest PC 0x0c043bd6 */
if(!s->budget--) { s->failed_pc=0x0c043bd6u; return 0; }
write(ram,r[14]+28,r[1],4);
goto P_0c043bd8;
P_0c043bd8: /* original 60d2, guest PC 0x0c043bd8 */
if(!s->budget--) { s->failed_pc=0x0c043bd8u; return 0; }
tmp=read(ram,r[13],4);
r[0]=tmp;
goto P_0c043bda;
P_0c043bda: /* original 2008, guest PC 0x0c043bda */
if(!s->budget--) { s->failed_pc=0x0c043bdau; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c043bdc;
P_0c043bdc: /* original 8905, guest PC 0x0c043bdc */
if(!s->budget--) { s->failed_pc=0x0c043bdcu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c043bea; }
goto P_0c043bde;
P_0c043bde: /* original 60d2, guest PC 0x0c043bde */
if(!s->budget--) { s->failed_pc=0x0c043bdeu; return 0; }
tmp=read(ram,r[13],4);
r[0]=tmp;
goto P_0c043be0;
P_0c043be0: /* original 67c2, guest PC 0x0c043be0 */
if(!s->budget--) { s->failed_pc=0x0c043be0u; return 0; }
tmp=read(ram,r[12],4);
r[7]=tmp;
goto P_0c043be2;
P_0c043be2: /* original 56e2, guest PC 0x0c043be2 */
if(!s->budget--) { s->failed_pc=0x0c043be2u; return 0; }
r[6]=read(ram,r[14]+8,4);
goto P_0c043be4;
P_0c043be4: /* original e5fe, guest PC 0x0c043be4 */
if(!s->budget--) { s->failed_pc=0x0c043be4u; return 0; }
r[5]=0xfffffffeu;
goto P_0c043be6;
P_0c043be6: /* original 400b, guest PC 0x0c043be6 */
if(!s->budget--) { s->failed_pc=0x0c043be6u; return 0; }
target=r[0];
r[16]=code_base|0x0c043beau;
r[4]=0x00000001u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c043beau) { target=s->pc; goto dispatch; }
goto P_0c043bea;
P_0c043be8: /* original e401, guest PC 0x0c043be8 */
if(!s->budget--) { s->failed_pc=0x0c043be8u; return 0; }
r[4]=0x00000001u;
goto P_0c043bea;
P_0c043bea: /* original 934c, guest PC 0x0c043bea */
if(!s->budget--) { s->failed_pc=0x0c043beau; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c043c86u,2);
goto P_0c043bec;
P_0c043bec: /* original 62c2, guest PC 0x0c043bec */
if(!s->budget--) { s->failed_pc=0x0c043becu; return 0; }
tmp=read(ram,r[12],4);
r[2]=tmp;
goto P_0c043bee;
P_0c043bee: /* original 2238, guest PC 0x0c043bee */
if(!s->budget--) { s->failed_pc=0x0c043beeu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c043bf0;
P_0c043bf0: /* original 890b, guest PC 0x0c043bf0 */
if(!s->budget--) { s->failed_pc=0x0c043bf0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c043c0a; }
goto P_0c043bf2;
P_0c043bf2: /* original 50e8, guest PC 0x0c043bf2 */
if(!s->budget--) { s->failed_pc=0x0c043bf2u; return 0; }
r[0]=read(ram,r[14]+32,4);
goto P_0c043bf4;
P_0c043bf4: /* original 7001, guest PC 0x0c043bf4 */
if(!s->budget--) { s->failed_pc=0x0c043bf4u; return 0; }
r[0]+=0x00000001u;
goto P_0c043bf6;
P_0c043bf6: /* original 1e08, guest PC 0x0c043bf6 */
if(!s->budget--) { s->failed_pc=0x0c043bf6u; return 0; }
write(ram,r[14]+32,r[0],4);
goto P_0c043bf8;
P_0c043bf8: /* original 62d2, guest PC 0x0c043bf8 */
if(!s->budget--) { s->failed_pc=0x0c043bf8u; return 0; }
tmp=read(ram,r[13],4);
r[2]=tmp;
goto P_0c043bfa;
P_0c043bfa: /* original 2228, guest PC 0x0c043bfa */
if(!s->budget--) { s->failed_pc=0x0c043bfau; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c043bfc;
P_0c043bfc: /* original 8905, guest PC 0x0c043bfc */
if(!s->budget--) { s->failed_pc=0x0c043bfcu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c043c0a; }
goto P_0c043bfe;
P_0c043bfe: /* original 62d2, guest PC 0x0c043bfe */
if(!s->budget--) { s->failed_pc=0x0c043bfeu; return 0; }
tmp=read(ram,r[13],4);
r[2]=tmp;
goto P_0c043c00;
P_0c043c00: /* original 67c2, guest PC 0x0c043c00 */
if(!s->budget--) { s->failed_pc=0x0c043c00u; return 0; }
tmp=read(ram,r[12],4);
r[7]=tmp;
goto P_0c043c02;
P_0c043c02: /* original 56e2, guest PC 0x0c043c02 */
if(!s->budget--) { s->failed_pc=0x0c043c02u; return 0; }
r[6]=read(ram,r[14]+8,4);
goto P_0c043c04;
P_0c043c04: /* original e5fd, guest PC 0x0c043c04 */
if(!s->budget--) { s->failed_pc=0x0c043c04u; return 0; }
r[5]=0xfffffffdu;
goto P_0c043c06;
P_0c043c06: /* original 420b, guest PC 0x0c043c06 */
if(!s->budget--) { s->failed_pc=0x0c043c06u; return 0; }
target=r[2];
r[16]=code_base|0x0c043c0au;
r[4]=0x00000001u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c043c0au) { target=s->pc; goto dispatch; }
goto P_0c043c0a;
P_0c043c08: /* original e401, guest PC 0x0c043c08 */
if(!s->budget--) { s->failed_pc=0x0c043c08u; return 0; }
r[4]=0x00000001u;
goto P_0c043c0a;
P_0c043c0a: /* original 933d, guest PC 0x0c043c0a */
if(!s->budget--) { s->failed_pc=0x0c043c0au; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c043c88u,2);
goto P_0c043c0c;
P_0c043c0c: /* original 62c2, guest PC 0x0c043c0c */
if(!s->budget--) { s->failed_pc=0x0c043c0cu; return 0; }
tmp=read(ram,r[12],4);
r[2]=tmp;
goto P_0c043c0e;
P_0c043c0e: /* original 2238, guest PC 0x0c043c0e */
if(!s->budget--) { s->failed_pc=0x0c043c0eu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c043c10;
P_0c043c10: /* original 890b, guest PC 0x0c043c10 */
if(!s->budget--) { s->failed_pc=0x0c043c10u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c043c2a; }
goto P_0c043c12;
P_0c043c12: /* original 50e9, guest PC 0x0c043c12 */
if(!s->budget--) { s->failed_pc=0x0c043c12u; return 0; }
r[0]=read(ram,r[14]+36,4);
goto P_0c043c14;
P_0c043c14: /* original 7001, guest PC 0x0c043c14 */
if(!s->budget--) { s->failed_pc=0x0c043c14u; return 0; }
r[0]+=0x00000001u;
goto P_0c043c16;
P_0c043c16: /* original 1e09, guest PC 0x0c043c16 */
if(!s->budget--) { s->failed_pc=0x0c043c16u; return 0; }
write(ram,r[14]+36,r[0],4);
goto P_0c043c18;
P_0c043c18: /* original 62d2, guest PC 0x0c043c18 */
if(!s->budget--) { s->failed_pc=0x0c043c18u; return 0; }
tmp=read(ram,r[13],4);
r[2]=tmp;
goto P_0c043c1a;
P_0c043c1a: /* original 2228, guest PC 0x0c043c1a */
if(!s->budget--) { s->failed_pc=0x0c043c1au; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c043c1c;
P_0c043c1c: /* original 8905, guest PC 0x0c043c1c */
if(!s->budget--) { s->failed_pc=0x0c043c1cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c043c2a; }
goto P_0c043c1e;
P_0c043c1e: /* original 62d2, guest PC 0x0c043c1e */
if(!s->budget--) { s->failed_pc=0x0c043c1eu; return 0; }
tmp=read(ram,r[13],4);
r[2]=tmp;
goto P_0c043c20;
P_0c043c20: /* original 67c2, guest PC 0x0c043c20 */
if(!s->budget--) { s->failed_pc=0x0c043c20u; return 0; }
tmp=read(ram,r[12],4);
r[7]=tmp;
goto P_0c043c22;
P_0c043c22: /* original 56e2, guest PC 0x0c043c22 */
if(!s->budget--) { s->failed_pc=0x0c043c22u; return 0; }
r[6]=read(ram,r[14]+8,4);
goto P_0c043c24;
P_0c043c24: /* original e5fc, guest PC 0x0c043c24 */
if(!s->budget--) { s->failed_pc=0x0c043c24u; return 0; }
r[5]=0xfffffffcu;
goto P_0c043c26;
P_0c043c26: /* original 420b, guest PC 0x0c043c26 */
if(!s->budget--) { s->failed_pc=0x0c043c26u; return 0; }
target=r[2];
r[16]=code_base|0x0c043c2au;
r[4]=0x00000001u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c043c2au) { target=s->pc; goto dispatch; }
goto P_0c043c2a;
P_0c043c28: /* original e401, guest PC 0x0c043c28 */
if(!s->budget--) { s->failed_pc=0x0c043c28u; return 0; }
r[4]=0x00000001u;
goto P_0c043c2a;
P_0c043c2a: /* original 932e, guest PC 0x0c043c2a */
if(!s->budget--) { s->failed_pc=0x0c043c2au; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c043c8au,2);
goto P_0c043c2c;
P_0c043c2c: /* original 62c2, guest PC 0x0c043c2c */
if(!s->budget--) { s->failed_pc=0x0c043c2cu; return 0; }
tmp=read(ram,r[12],4);
r[2]=tmp;
goto P_0c043c2e;
P_0c043c2e: /* original 2238, guest PC 0x0c043c2e */
if(!s->budget--) { s->failed_pc=0x0c043c2eu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c043c30;
P_0c043c30: /* original 890b, guest PC 0x0c043c30 */
if(!s->budget--) { s->failed_pc=0x0c043c30u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c043c4a; }
goto P_0c043c32;
P_0c043c32: /* original 50ea, guest PC 0x0c043c32 */
if(!s->budget--) { s->failed_pc=0x0c043c32u; return 0; }
r[0]=read(ram,r[14]+40,4);
goto P_0c043c34;
P_0c043c34: /* original 7001, guest PC 0x0c043c34 */
if(!s->budget--) { s->failed_pc=0x0c043c34u; return 0; }
r[0]+=0x00000001u;
goto P_0c043c36;
P_0c043c36: /* original 1e0a, guest PC 0x0c043c36 */
if(!s->budget--) { s->failed_pc=0x0c043c36u; return 0; }
write(ram,r[14]+40,r[0],4);
goto P_0c043c38;
P_0c043c38: /* original 62d2, guest PC 0x0c043c38 */
if(!s->budget--) { s->failed_pc=0x0c043c38u; return 0; }
tmp=read(ram,r[13],4);
r[2]=tmp;
goto P_0c043c3a;
P_0c043c3a: /* original 2228, guest PC 0x0c043c3a */
if(!s->budget--) { s->failed_pc=0x0c043c3au; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c043c3c;
P_0c043c3c: /* original 8905, guest PC 0x0c043c3c */
if(!s->budget--) { s->failed_pc=0x0c043c3cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c043c4a; }
goto P_0c043c3e;
P_0c043c3e: /* original 62d2, guest PC 0x0c043c3e */
if(!s->budget--) { s->failed_pc=0x0c043c3eu; return 0; }
tmp=read(ram,r[13],4);
r[2]=tmp;
goto P_0c043c40;
P_0c043c40: /* original 67c2, guest PC 0x0c043c40 */
if(!s->budget--) { s->failed_pc=0x0c043c40u; return 0; }
tmp=read(ram,r[12],4);
r[7]=tmp;
goto P_0c043c42;
P_0c043c42: /* original 56e2, guest PC 0x0c043c42 */
if(!s->budget--) { s->failed_pc=0x0c043c42u; return 0; }
r[6]=read(ram,r[14]+8,4);
goto P_0c043c44;
P_0c043c44: /* original e5fb, guest PC 0x0c043c44 */
if(!s->budget--) { s->failed_pc=0x0c043c44u; return 0; }
r[5]=0xfffffffbu;
goto P_0c043c46;
P_0c043c46: /* original 420b, guest PC 0x0c043c46 */
if(!s->budget--) { s->failed_pc=0x0c043c46u; return 0; }
target=r[2];
r[16]=code_base|0x0c043c4au;
r[4]=0x00000001u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c043c4au) { target=s->pc; goto dispatch; }
goto P_0c043c4a;
P_0c043c48: /* original e401, guest PC 0x0c043c48 */
if(!s->budget--) { s->failed_pc=0x0c043c48u; return 0; }
r[4]=0x00000001u;
goto P_0c043c4a;
P_0c043c4a: /* original d314, guest PC 0x0c043c4a */
if(!s->budget--) { s->failed_pc=0x0c043c4au; return 0; }
r[3]=read(ram,0x0c043c9cu,4);
goto P_0c043c4c;
P_0c043c4c: /* original d412, guest PC 0x0c043c4c */
if(!s->budget--) { s->failed_pc=0x0c043c4cu; return 0; }
r[4]=read(ram,0x0c043c98u,4);
goto P_0c043c4e;
P_0c043c4e: /* original 430b, guest PC 0x0c043c4e */
if(!s->budget--) { s->failed_pc=0x0c043c4eu; return 0; }
target=r[3];
r[16]=code_base|0x0c043c52u;
tmp=read(ram,r[12],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c043c52u) { target=s->pc; goto dispatch; }
goto P_0c043c52;
P_0c043c50: /* original 65c2, guest PC 0x0c043c50 */
if(!s->budget--) { s->failed_pc=0x0c043c50u; return 0; }
tmp=read(ram,r[12],4);
r[5]=tmp;
goto P_0c043c52;
P_0c043c52: /* original 9216, guest PC 0x0c043c52 */
if(!s->budget--) { s->failed_pc=0x0c043c52u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c043c82u,2);
goto P_0c043c54;
P_0c043c54: /* original b056, guest PC 0x0c043c54 */
if(!s->budget--) { s->failed_pc=0x0c043c54u; return 0; }
target=code_base|0x0c043d04u; r[16]=code_base|0x0c043c58u;
write(ram,r[12],r[2],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c043c58u) { target=s->pc; goto dispatch; }
goto P_0c043c58;
P_0c043c56: /* original 2c22, guest PC 0x0c043c56 */
if(!s->budget--) { s->failed_pc=0x0c043c56u; return 0; }
write(ram,r[12],r[2],4);
goto P_0c043c58;
P_0c043c58: /* original d111, guest PC 0x0c043c58 */
if(!s->budget--) { s->failed_pc=0x0c043c58u; return 0; }
r[1]=read(ram,0x0c043ca0u,4);
goto P_0c043c5a;
P_0c043c5a: /* original 410b, guest PC 0x0c043c5a */
if(!s->budget--) { s->failed_pc=0x0c043c5au; return 0; }
target=r[1];
r[16]=code_base|0x0c043c5eu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c043c5eu) { target=s->pc; goto dispatch; }
goto P_0c043c5e;
P_0c043c5c: /* original 0009, guest PC 0x0c043c5c */
if(!s->budget--) { s->failed_pc=0x0c043c5cu; return 0; }
goto P_0c043c5e;
P_0c043c5e: /* original 6c03, guest PC 0x0c043c5e */
if(!s->budget--) { s->failed_pc=0x0c043c5eu; return 0; }
r[12]=r[0];
goto P_0c043c60;
P_0c043c60: /* original 4c11, guest PC 0x0c043c60 */
if(!s->budget--) { s->failed_pc=0x0c043c60u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[12]>=0)!=0);
goto P_0c043c62;
P_0c043c62: /* original 8b03, guest PC 0x0c043c62 */
if(!s->budget--) { s->failed_pc=0x0c043c62u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c043c6c; }
goto P_0c043c64;
P_0c043c64: /* original bf0a, guest PC 0x0c043c64 */
if(!s->budget--) { s->failed_pc=0x0c043c64u; return 0; }
target=code_base|0x0c043a7cu; r[16]=code_base|0x0c043c68u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c043c68u) { target=s->pc; goto dispatch; }
goto P_0c043c68;
P_0c043c66: /* original 0009, guest PC 0x0c043c66 */
if(!s->budget--) { s->failed_pc=0x0c043c66u; return 0; }
goto P_0c043c68;
P_0c043c68: /* original a046, guest PC 0x0c043c68 */
if(!s->budget--) { s->failed_pc=0x0c043c68u; return 0; }
goto P_0c043cf8;
P_0c043c6a: /* original 0009, guest PC 0x0c043c6a */
if(!s->budget--) { s->failed_pc=0x0c043c6au; return 0; }
goto P_0c043c6c;
P_0c043c6c: /* original 62d2, guest PC 0x0c043c6c */
if(!s->budget--) { s->failed_pc=0x0c043c6cu; return 0; }
tmp=read(ram,r[13],4);
r[2]=tmp;
goto P_0c043c6e;
P_0c043c6e: /* original 2228, guest PC 0x0c043c6e */
if(!s->budget--) { s->failed_pc=0x0c043c6eu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c043c70;
P_0c043c70: /* original 8942, guest PC 0x0c043c70 */
if(!s->budget--) { s->failed_pc=0x0c043c70u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c043cf8; }
goto P_0c043c72;
P_0c043c72: /* original 56e2, guest PC 0x0c043c72 */
if(!s->budget--) { s->failed_pc=0x0c043c72u; return 0; }
r[6]=read(ram,r[14]+8,4);
goto P_0c043c74;
P_0c043c74: /* original e5fa, guest PC 0x0c043c74 */
if(!s->budget--) { s->failed_pc=0x0c043c74u; return 0; }
r[5]=0xfffffffau;
goto P_0c043c76;
P_0c043c76: /* original 63d2, guest PC 0x0c043c76 */
if(!s->budget--) { s->failed_pc=0x0c043c76u; return 0; }
tmp=read(ram,r[13],4);
r[3]=tmp;
goto P_0c043c78;
P_0c043c78: /* original 67c3, guest PC 0x0c043c78 */
if(!s->budget--) { s->failed_pc=0x0c043c78u; return 0; }
r[7]=r[12];
goto P_0c043c7a;
P_0c043c7a: /* original 430b, guest PC 0x0c043c7a */
if(!s->budget--) { s->failed_pc=0x0c043c7au; return 0; }
target=r[3];
r[16]=code_base|0x0c043c7eu;
r[4]=0x00000001u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c043c7eu) { target=s->pc; goto dispatch; }
goto P_0c043c7e;
P_0c043c7c: /* original e401, guest PC 0x0c043c7c */
if(!s->budget--) { s->failed_pc=0x0c043c7cu; return 0; }
r[4]=0x00000001u;
goto P_0c043c7e;
P_0c043c7e: /* original a03b, guest PC 0x0c043c7e */
if(!s->budget--) { s->failed_pc=0x0c043c7eu; return 0; }
goto P_0c043cf8;
P_0c043c80: /* original 0009, guest PC 0x0c043c80 */
if(!s->budget--) { s->failed_pc=0x0c043c80u; return 0; }
if(!vf3_matrix_family(0x0c043c82u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c043c82u; return 0; } return 1;
P_0c043ca4: /* original d137, guest PC 0x0c043ca4 */
if(!s->budget--) { s->failed_pc=0x0c043ca4u; return 0; }
r[1]=read(ram,0x0c043d84u,4);
goto P_0c043ca6;
P_0c043ca6: /* original 410b, guest PC 0x0c043ca6 */
if(!s->budget--) { s->failed_pc=0x0c043ca6u; return 0; }
target=r[1];
r[16]=code_base|0x0c043caau;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c043caau) { target=s->pc; goto dispatch; }
goto P_0c043caa;
P_0c043ca8: /* original 0009, guest PC 0x0c043ca8 */
if(!s->budget--) { s->failed_pc=0x0c043ca8u; return 0; }
goto P_0c043caa;
P_0c043caa: /* original 6c03, guest PC 0x0c043caa */
if(!s->budget--) { s->failed_pc=0x0c043caau; return 0; }
r[12]=r[0];
goto P_0c043cac;
P_0c043cac: /* original 4c11, guest PC 0x0c043cac */
if(!s->budget--) { s->failed_pc=0x0c043cacu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[12]>=0)!=0);
goto P_0c043cae;
P_0c043cae: /* original 8b17, guest PC 0x0c043cae */
if(!s->budget--) { s->failed_pc=0x0c043caeu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c043ce0; }
goto P_0c043cb0;
P_0c043cb0: /* original d435, guest PC 0x0c043cb0 */
if(!s->budget--) { s->failed_pc=0x0c043cb0u; return 0; }
r[4]=read(ram,0x0c043d88u,4);
goto P_0c043cb2;
P_0c043cb2: /* original 63e3, guest PC 0x0c043cb2 */
if(!s->budget--) { s->failed_pc=0x0c043cb2u; return 0; }
r[3]=r[14];
goto P_0c043cb4;
P_0c043cb4: /* original 7334, guest PC 0x0c043cb4 */
if(!s->budget--) { s->failed_pc=0x0c043cb4u; return 0; }
r[3]+=0x00000034u;
goto P_0c043cb6;
P_0c043cb6: /* original 6242, guest PC 0x0c043cb6 */
if(!s->budget--) { s->failed_pc=0x0c043cb6u; return 0; }
tmp=read(ram,r[4],4);
r[2]=tmp;
goto P_0c043cb8;
P_0c043cb8: /* original e100, guest PC 0x0c043cb8 */
if(!s->budget--) { s->failed_pc=0x0c043cb8u; return 0; }
r[1]=0x00000000u;
goto P_0c043cba;
P_0c043cba: /* original 4200, guest PC 0x0c043cba */
if(!s->budget--) { s->failed_pc=0x0c043cbau; return 0; }
r[17]=(r[17]&~1u)|((r[2]>>31)!=0);
r[2]<<=1;
goto P_0c043cbc;
P_0c043cbc: /* original 323c, guest PC 0x0c043cbc */
if(!s->budget--) { s->failed_pc=0x0c043cbcu; return 0; }
r[2]+=r[3];
goto P_0c043cbe;
P_0c043cbe: /* original 2211, guest PC 0x0c043cbe */
if(!s->budget--) { s->failed_pc=0x0c043cbeu; return 0; }
write(ram,r[2],r[1],2);
goto P_0c043cc0;
P_0c043cc0: /* original 62e3, guest PC 0x0c043cc0 */
if(!s->budget--) { s->failed_pc=0x0c043cc0u; return 0; }
r[2]=r[14];
goto P_0c043cc2;
P_0c043cc2: /* original 6342, guest PC 0x0c043cc2 */
if(!s->budget--) { s->failed_pc=0x0c043cc2u; return 0; }
tmp=read(ram,r[4],4);
r[3]=tmp;
goto P_0c043cc4;
P_0c043cc4: /* original 722c, guest PC 0x0c043cc4 */
if(!s->budget--) { s->failed_pc=0x0c043cc4u; return 0; }
r[2]+=0x0000002cu;
goto P_0c043cc6;
P_0c043cc6: /* original d031, guest PC 0x0c043cc6 */
if(!s->budget--) { s->failed_pc=0x0c043cc6u; return 0; }
r[0]=read(ram,0x0c043d8cu,4);
goto P_0c043cc8;
P_0c043cc8: /* original 4300, guest PC 0x0c043cc8 */
if(!s->budget--) { s->failed_pc=0x0c043cc8u; return 0; }
r[17]=(r[17]&~1u)|((r[3]>>31)!=0);
r[3]<<=1;
goto P_0c043cca;
P_0c043cca: /* original 332c, guest PC 0x0c043cca */
if(!s->budget--) { s->failed_pc=0x0c043ccau; return 0; }
r[3]+=r[2];
goto P_0c043ccc;
P_0c043ccc: /* original 6102, guest PC 0x0c043ccc */
if(!s->budget--) { s->failed_pc=0x0c043cccu; return 0; }
tmp=read(ram,r[0],4);
r[1]=tmp;
goto P_0c043cce;
P_0c043cce: /* original 9257, guest PC 0x0c043cce */
if(!s->budget--) { s->failed_pc=0x0c043cceu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c043d80u,2);
goto P_0c043cd0;
P_0c043cd0: /* original 2129, guest PC 0x0c043cd0 */
if(!s->budget--) { s->failed_pc=0x0c043cd0u; return 0; }
r[1]&=r[2];
goto P_0c043cd2;
P_0c043cd2: /* original 2311, guest PC 0x0c043cd2 */
if(!s->budget--) { s->failed_pc=0x0c043cd2u; return 0; }
write(ram,r[3],r[1],2);
goto P_0c043cd4;
P_0c043cd4: /* original bed2, guest PC 0x0c043cd4 */
if(!s->budget--) { s->failed_pc=0x0c043cd4u; return 0; }
target=code_base|0x0c043a7cu; r[16]=code_base|0x0c043cd8u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c043cd8u) { target=s->pc; goto dispatch; }
goto P_0c043cd8;
P_0c043cd6: /* original 0009, guest PC 0x0c043cd6 */
if(!s->budget--) { s->failed_pc=0x0c043cd6u; return 0; }
goto P_0c043cd8;
P_0c043cd8: /* original 62e2, guest PC 0x0c043cd8 */
if(!s->budget--) { s->failed_pc=0x0c043cd8u; return 0; }
tmp=read(ram,r[14],4);
r[2]=tmp;
goto P_0c043cda;
P_0c043cda: /* original 7201, guest PC 0x0c043cda */
if(!s->budget--) { s->failed_pc=0x0c043cdau; return 0; }
r[2]+=0x00000001u;
goto P_0c043cdc;
P_0c043cdc: /* original a00c, guest PC 0x0c043cdc */
if(!s->budget--) { s->failed_pc=0x0c043cdcu; return 0; }
write(ram,r[14],r[2],4);
goto P_0c043cf8;
P_0c043cde: /* original 2e22, guest PC 0x0c043cde */
if(!s->budget--) { s->failed_pc=0x0c043cdeu; return 0; }
write(ram,r[14],r[2],4);
goto P_0c043ce0;
P_0c043ce0: /* original 51e4, guest PC 0x0c043ce0 */
if(!s->budget--) { s->failed_pc=0x0c043ce0u; return 0; }
r[1]=read(ram,r[14]+16,4);
goto P_0c043ce2;
P_0c043ce2: /* original 7101, guest PC 0x0c043ce2 */
if(!s->budget--) { s->failed_pc=0x0c043ce2u; return 0; }
r[1]+=0x00000001u;
goto P_0c043ce4;
P_0c043ce4: /* original 1e14, guest PC 0x0c043ce4 */
if(!s->budget--) { s->failed_pc=0x0c043ce4u; return 0; }
write(ram,r[14]+16,r[1],4);
goto P_0c043ce6;
P_0c043ce6: /* original 63d2, guest PC 0x0c043ce6 */
if(!s->budget--) { s->failed_pc=0x0c043ce6u; return 0; }
tmp=read(ram,r[13],4);
r[3]=tmp;
goto P_0c043ce8;
P_0c043ce8: /* original 2338, guest PC 0x0c043ce8 */
if(!s->budget--) { s->failed_pc=0x0c043ce8u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c043cea;
P_0c043cea: /* original 8905, guest PC 0x0c043cea */
if(!s->budget--) { s->failed_pc=0x0c043ceau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c043cf8; }
goto P_0c043cec;
P_0c043cec: /* original 56e2, guest PC 0x0c043cec */
if(!s->budget--) { s->failed_pc=0x0c043cecu; return 0; }
r[6]=read(ram,r[14]+8,4);
goto P_0c043cee;
P_0c043cee: /* original e5f9, guest PC 0x0c043cee */
if(!s->budget--) { s->failed_pc=0x0c043ceeu; return 0; }
r[5]=0xfffffff9u;
goto P_0c043cf0;
P_0c043cf0: /* original 63d2, guest PC 0x0c043cf0 */
if(!s->budget--) { s->failed_pc=0x0c043cf0u; return 0; }
tmp=read(ram,r[13],4);
r[3]=tmp;
goto P_0c043cf2;
P_0c043cf2: /* original 67c3, guest PC 0x0c043cf2 */
if(!s->budget--) { s->failed_pc=0x0c043cf2u; return 0; }
r[7]=r[12];
goto P_0c043cf4;
P_0c043cf4: /* original 430b, guest PC 0x0c043cf4 */
if(!s->budget--) { s->failed_pc=0x0c043cf4u; return 0; }
target=r[3];
r[16]=code_base|0x0c043cf8u;
r[4]=0x00000001u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c043cf8u) { target=s->pc; goto dispatch; }
goto P_0c043cf8;
P_0c043cf6: /* original e401, guest PC 0x0c043cf6 */
if(!s->budget--) { s->failed_pc=0x0c043cf6u; return 0; }
r[4]=0x00000001u;
goto P_0c043cf8;
P_0c043cf8: /* original 4f26, guest PC 0x0c043cf8 */
if(!s->budget--) { s->failed_pc=0x0c043cf8u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c043cfa;
P_0c043cfa: /* original 60c3, guest PC 0x0c043cfa */
if(!s->budget--) { s->failed_pc=0x0c043cfau; return 0; }
r[0]=r[12];
goto P_0c043cfc;
P_0c043cfc: /* original 6cf6, guest PC 0x0c043cfc */
if(!s->budget--) { s->failed_pc=0x0c043cfcu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c043cfe;
P_0c043cfe: /* original 6df6, guest PC 0x0c043cfe */
if(!s->budget--) { s->failed_pc=0x0c043cfeu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c043d00;
P_0c043d00: /* original 000b, guest PC 0x0c043d00 */
if(!s->budget--) { s->failed_pc=0x0c043d00u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c043d02: /* original 6ef6, guest PC 0x0c043d02 */
if(!s->budget--) { s->failed_pc=0x0c043d02u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c043d04;
P_0c043d04: /* original 2fe6, guest PC 0x0c043d04 */
if(!s->budget--) { s->failed_pc=0x0c043d04u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c043d06;
P_0c043d06: /* original e301, guest PC 0x0c043d06 */
if(!s->budget--) { s->failed_pc=0x0c043d06u; return 0; }
r[3]=0x00000001u;
goto P_0c043d08;
P_0c043d08: /* original 2fd6, guest PC 0x0c043d08 */
if(!s->budget--) { s->failed_pc=0x0c043d08u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c043d0a;
P_0c043d0a: /* original 2fc6, guest PC 0x0c043d0a */
if(!s->budget--) { s->failed_pc=0x0c043d0au; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c043d0c;
P_0c043d0c: /* original 2fb6, guest PC 0x0c043d0c */
if(!s->budget--) { s->failed_pc=0x0c043d0cu; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c043d0e;
P_0c043d0e: /* original 2fa6, guest PC 0x0c043d0e */
if(!s->budget--) { s->failed_pc=0x0c043d0eu; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c043d10;
P_0c043d10: /* original 2f96, guest PC 0x0c043d10 */
if(!s->budget--) { s->failed_pc=0x0c043d10u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c043d12;
P_0c043d12: /* original 2f86, guest PC 0x0c043d12 */
if(!s->budget--) { s->failed_pc=0x0c043d12u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c043d14;
P_0c043d14: /* original 4f22, guest PC 0x0c043d14 */
if(!s->budget--) { s->failed_pc=0x0c043d14u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c043d16;
P_0c043d16: /* original d11f, guest PC 0x0c043d16 */
if(!s->budget--) { s->failed_pc=0x0c043d16u; return 0; }
r[1]=read(ram,0x0c043d94u,4);
goto P_0c043d18;
P_0c043d18: /* original d21d, guest PC 0x0c043d18 */
if(!s->budget--) { s->failed_pc=0x0c043d18u; return 0; }
r[2]=read(ram,0x0c043d90u,4);
goto P_0c043d1a;
P_0c043d1a: /* original 4f12, guest PC 0x0c043d1a */
if(!s->budget--) { s->failed_pc=0x0c043d1au; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c043d1c;
P_0c043d1c: /* original 410b, guest PC 0x0c043d1c */
if(!s->budget--) { s->failed_pc=0x0c043d1cu; return 0; }
target=r[1];
r[16]=code_base|0x0c043d20u;
write(ram,r[2],r[3],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c043d20u) { target=s->pc; goto dispatch; }
goto P_0c043d20;
P_0c043d1e: /* original 2232, guest PC 0x0c043d1e */
if(!s->budget--) { s->failed_pc=0x0c043d1eu; return 0; }
write(ram,r[2],r[3],4);
goto P_0c043d20;
P_0c043d20: /* original 88fe, guest PC 0x0c043d20 */
if(!s->budget--) { s->failed_pc=0x0c043d20u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xfffffffeu)!=0);
goto P_0c043d22;
P_0c043d22: /* original 8f07, guest PC 0x0c043d22 */
if(!s->budget--) { s->failed_pc=0x0c043d22u; return 0; }
cond=r[17]&1u;
r[10]=r[0];
if(!cond) { goto P_0c043d34; }
goto P_0c043d26;
P_0c043d24: /* original 6a03, guest PC 0x0c043d24 */
if(!s->budget--) { s->failed_pc=0x0c043d24u; return 0; }
r[10]=r[0];
goto P_0c043d26;
P_0c043d26: /* original d31c, guest PC 0x0c043d26 */
if(!s->budget--) { s->failed_pc=0x0c043d26u; return 0; }
r[3]=read(ram,0x0c043d98u,4);
goto P_0c043d28;
P_0c043d28: /* original e101, guest PC 0x0c043d28 */
if(!s->budget--) { s->failed_pc=0x0c043d28u; return 0; }
r[1]=0x00000001u;
goto P_0c043d2a;
P_0c043d2a: /* original 902a, guest PC 0x0c043d2a */
if(!s->budget--) { s->failed_pc=0x0c043d2au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c043d82u,2);
goto P_0c043d2c;
P_0c043d2c: /* original 6232, guest PC 0x0c043d2c */
if(!s->budget--) { s->failed_pc=0x0c043d2cu; return 0; }
tmp=read(ram,r[3],4);
r[2]=tmp;
goto P_0c043d2e;
P_0c043d2e: /* original 0216, guest PC 0x0c043d2e */
if(!s->budget--) { s->failed_pc=0x0c043d2eu; return 0; }
write(ram,r[2]+r[0],r[1],4);
goto P_0c043d30;
P_0c043d30: /* original a084, guest PC 0x0c043d30 */
if(!s->budget--) { s->failed_pc=0x0c043d30u; return 0; }
goto P_0c043e3c;
P_0c043d32: /* original 0009, guest PC 0x0c043d32 */
if(!s->budget--) { s->failed_pc=0x0c043d32u; return 0; }
goto P_0c043d34;
P_0c043d34: /* original d819, guest PC 0x0c043d34 */
if(!s->budget--) { s->failed_pc=0x0c043d34u; return 0; }
r[8]=read(ram,0x0c043d9cu,4);
goto P_0c043d36;
P_0c043d36: /* original 4a11, guest PC 0x0c043d36 */
if(!s->budget--) { s->failed_pc=0x0c043d36u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[10]>=0)!=0);
goto P_0c043d38;
P_0c043d38: /* original 8f75, guest PC 0x0c043d38 */
if(!s->budget--) { s->failed_pc=0x0c043d38u; return 0; }
cond=r[17]&1u;
r[12]=0x00000000u;
if(!cond) { goto P_0c043e26; }
goto P_0c043d3c;
P_0c043d3a: /* original ec00, guest PC 0x0c043d3a */
if(!s->budget--) { s->failed_pc=0x0c043d3au; return 0; }
r[12]=0x00000000u;
goto P_0c043d3c;
P_0c043d3c: /* original d218, guest PC 0x0c043d3c */
if(!s->budget--) { s->failed_pc=0x0c043d3cu; return 0; }
r[2]=read(ram,0x0c043da0u,4);
goto P_0c043d3e;
P_0c043d3e: /* original 420b, guest PC 0x0c043d3e */
if(!s->budget--) { s->failed_pc=0x0c043d3eu; return 0; }
target=r[2];
r[16]=code_base|0x0c043d42u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c043d42u) { target=s->pc; goto dispatch; }
goto P_0c043d42;
P_0c043d40: /* original 0009, guest PC 0x0c043d40 */
if(!s->budget--) { s->failed_pc=0x0c043d40u; return 0; }
goto P_0c043d42;
P_0c043d42: /* original d311, guest PC 0x0c043d42 */
if(!s->budget--) { s->failed_pc=0x0c043d42u; return 0; }
r[3]=read(ram,0x0c043d88u,4);
goto P_0c043d44;
P_0c043d44: /* original 6283, guest PC 0x0c043d44 */
if(!s->budget--) { s->failed_pc=0x0c043d44u; return 0; }
r[2]=r[8];
goto P_0c043d46;
P_0c043d46: /* original 7230, guest PC 0x0c043d46 */
if(!s->budget--) { s->failed_pc=0x0c043d46u; return 0; }
r[2]+=0x00000030u;
goto P_0c043d48;
P_0c043d48: /* original 951a, guest PC 0x0c043d48 */
if(!s->budget--) { s->failed_pc=0x0c043d48u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c043d80u,2);
goto P_0c043d4a;
P_0c043d4a: /* original 6432, guest PC 0x0c043d4a */
if(!s->budget--) { s->failed_pc=0x0c043d4au; return 0; }
tmp=read(ram,r[3],4);
r[4]=tmp;
goto P_0c043d4c;
P_0c043d4c: /* original 4400, guest PC 0x0c043d4c */
if(!s->budget--) { s->failed_pc=0x0c043d4cu; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c043d4e;
P_0c043d4e: /* original 324c, guest PC 0x0c043d4e */
if(!s->budget--) { s->failed_pc=0x0c043d4eu; return 0; }
r[2]+=r[4];
goto P_0c043d50;
P_0c043d50: /* original 2f26, guest PC 0x0c043d50 */
if(!s->budget--) { s->failed_pc=0x0c043d50u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c043d52;
P_0c043d52: /* original d00e, guest PC 0x0c043d52 */
if(!s->budget--) { s->failed_pc=0x0c043d52u; return 0; }
r[0]=read(ram,0x0c043d8cu,4);
goto P_0c043d54;
P_0c043d54: /* original 6102, guest PC 0x0c043d54 */
if(!s->budget--) { s->failed_pc=0x0c043d54u; return 0; }
tmp=read(ram,r[0],4);
r[1]=tmp;
goto P_0c043d56;
P_0c043d56: /* original 6383, guest PC 0x0c043d56 */
if(!s->budget--) { s->failed_pc=0x0c043d56u; return 0; }
r[3]=r[8];
goto P_0c043d58;
P_0c043d58: /* original d212, guest PC 0x0c043d58 */
if(!s->budget--) { s->failed_pc=0x0c043d58u; return 0; }
r[2]=read(ram,0x0c043da4u,4);
goto P_0c043d5a;
P_0c043d5a: /* original 7334, guest PC 0x0c043d5a */
if(!s->budget--) { s->failed_pc=0x0c043d5au; return 0; }
r[3]+=0x00000034u;
goto P_0c043d5c;
P_0c043d5c: /* original 2159, guest PC 0x0c043d5c */
if(!s->budget--) { s->failed_pc=0x0c043d5cu; return 0; }
r[1]&=r[5];
goto P_0c043d5e;
P_0c043d5e: /* original 334c, guest PC 0x0c043d5e */
if(!s->budget--) { s->failed_pc=0x0c043d5eu; return 0; }
r[3]+=r[4];
goto P_0c043d60;
P_0c043d60: /* original 6022, guest PC 0x0c043d60 */
if(!s->budget--) { s->failed_pc=0x0c043d60u; return 0; }
tmp=read(ram,r[2],4);
r[0]=tmp;
goto P_0c043d62;
P_0c043d62: /* original 6331, guest PC 0x0c043d62 */
if(!s->budget--) { s->failed_pc=0x0c043d62u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[3],2);
r[3]=tmp;
goto P_0c043d64;
P_0c043d64: /* original 2059, guest PC 0x0c043d64 */
if(!s->budget--) { s->failed_pc=0x0c043d64u; return 0; }
r[0]&=r[5];
goto P_0c043d66;
P_0c043d66: /* original 230e, guest PC 0x0c043d66 */
if(!s->budget--) { s->failed_pc=0x0c043d66u; return 0; }
r[19]=(r[3]&65535u)*(r[0]&65535u);
goto P_0c043d68;
P_0c043d68: /* original 001a, guest PC 0x0c043d68 */
if(!s->budget--) { s->failed_pc=0x0c043d68u; return 0; }
r[0]=r[19];
goto P_0c043d6a;
P_0c043d6a: /* original 310c, guest PC 0x0c043d6a */
if(!s->budget--) { s->failed_pc=0x0c043d6au; return 0; }
r[1]+=r[0];
goto P_0c043d6c;
P_0c043d6c: /* original 60f6, guest PC 0x0c043d6c */
if(!s->budget--) { s->failed_pc=0x0c043d6cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[0]=tmp;
goto P_0c043d6e;
P_0c043d6e: /* original be85, guest PC 0x0c043d6e */
if(!s->budget--) { s->failed_pc=0x0c043d6eu; return 0; }
target=code_base|0x0c043a7cu; r[16]=code_base|0x0c043d72u;
write(ram,r[0],r[1],2);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c043d72u) { target=s->pc; goto dispatch; }
goto P_0c043d72;
P_0c043d70: /* original 2011, guest PC 0x0c043d70 */
if(!s->budget--) { s->failed_pc=0x0c043d70u; return 0; }
write(ram,r[0],r[1],2);
goto P_0c043d72;
P_0c043d72: /* original d20d, guest PC 0x0c043d72 */
if(!s->budget--) { s->failed_pc=0x0c043d72u; return 0; }
r[2]=read(ram,0x0c043da8u,4);
goto P_0c043d74;
P_0c043d74: /* original 420b, guest PC 0x0c043d74 */
if(!s->budget--) { s->failed_pc=0x0c043d74u; return 0; }
target=r[2];
r[16]=code_base|0x0c043d78u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c043d78u) { target=s->pc; goto dispatch; }
goto P_0c043d78;
P_0c043d76: /* original 0009, guest PC 0x0c043d76 */
if(!s->budget--) { s->failed_pc=0x0c043d76u; return 0; }
goto P_0c043d78;
P_0c043d78: /* original dd0d, guest PC 0x0c043d78 */
if(!s->budget--) { s->failed_pc=0x0c043d78u; return 0; }
r[13]=read(ram,0x0c043db0u,4);
goto P_0c043d7a;
P_0c043d7a: /* original de0c, guest PC 0x0c043d7a */
if(!s->budget--) { s->failed_pc=0x0c043d7au; return 0; }
r[14]=read(ram,0x0c043dacu,4);
goto P_0c043d7c;
P_0c043d7c: /* original a044, guest PC 0x0c043d7c */
if(!s->budget--) { s->failed_pc=0x0c043d7cu; return 0; }
r[11]=r[12];
goto P_0c043e08;
P_0c043d7e: /* original 6bc3, guest PC 0x0c043d7e */
if(!s->budget--) { s->failed_pc=0x0c043d7eu; return 0; }
r[11]=r[12];
if(!vf3_matrix_family(0x0c043d80u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c043d80u; return 0; } return 1;
P_0c043db4: /* original 52e2, guest PC 0x0c043db4 */
if(!s->budget--) { s->failed_pc=0x0c043db4u; return 0; }
r[2]=read(ram,r[14]+8,4);
goto P_0c043db6;
P_0c043db6: /* original 2228, guest PC 0x0c043db6 */
if(!s->budget--) { s->failed_pc=0x0c043db6u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c043db8;
P_0c043db8: /* original 8924, guest PC 0x0c043db8 */
if(!s->budget--) { s->failed_pc=0x0c043db8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c043e04; }
goto P_0c043dba;
P_0c043dba: /* original d44f, guest PC 0x0c043dba */
if(!s->budget--) { s->failed_pc=0x0c043dbau; return 0; }
r[4]=read(ram,0x0c043ef8u,4);
goto P_0c043dbc;
P_0c043dbc: /* original 56e2, guest PC 0x0c043dbc */
if(!s->budget--) { s->failed_pc=0x0c043dbcu; return 0; }
r[6]=read(ram,r[14]+8,4);
goto P_0c043dbe;
P_0c043dbe: /* original 4d0b, guest PC 0x0c043dbe */
if(!s->budget--) { s->failed_pc=0x0c043dbeu; return 0; }
target=r[13];
r[16]=code_base|0x0c043dc2u;
r[5]=r[11];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c043dc2u) { target=s->pc; goto dispatch; }
goto P_0c043dc2;
P_0c043dc0: /* original 65b3, guest PC 0x0c043dc0 */
if(!s->budget--) { s->failed_pc=0x0c043dc0u; return 0; }
r[5]=r[11];
goto P_0c043dc2;
P_0c043dc2: /* original d44e, guest PC 0x0c043dc2 */
if(!s->budget--) { s->failed_pc=0x0c043dc2u; return 0; }
r[4]=read(ram,0x0c043efcu,4);
goto P_0c043dc4;
P_0c043dc4: /* original 56e1, guest PC 0x0c043dc4 */
if(!s->budget--) { s->failed_pc=0x0c043dc4u; return 0; }
r[6]=read(ram,r[14]+4,4);
goto P_0c043dc6;
P_0c043dc6: /* original 4d0b, guest PC 0x0c043dc6 */
if(!s->budget--) { s->failed_pc=0x0c043dc6u; return 0; }
target=r[13];
r[16]=code_base|0x0c043dcau;
tmp=read(ram,r[14],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c043dcau) { target=s->pc; goto dispatch; }
goto P_0c043dca;
P_0c043dc8: /* original 65e2, guest PC 0x0c043dc8 */
if(!s->budget--) { s->failed_pc=0x0c043dc8u; return 0; }
tmp=read(ram,r[14],4);
r[5]=tmp;
goto P_0c043dca;
P_0c043dca: /* original 55e1, guest PC 0x0c043dca */
if(!s->budget--) { s->failed_pc=0x0c043dcau; return 0; }
r[5]=read(ram,r[14]+4,4);
goto P_0c043dcc;
P_0c043dcc: /* original b08c, guest PC 0x0c043dcc */
if(!s->budget--) { s->failed_pc=0x0c043dccu; return 0; }
target=code_base|0x0c043ee8u; r[16]=code_base|0x0c043dd0u;
tmp=read(ram,r[14],4);
r[4]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c043dd0u) { target=s->pc; goto dispatch; }
goto P_0c043dd0;
P_0c043dce: /* original 64e2, guest PC 0x0c043dce */
if(!s->budget--) { s->failed_pc=0x0c043dceu; return 0; }
tmp=read(ram,r[14],4);
r[4]=tmp;
goto P_0c043dd0;
P_0c043dd0: /* original 2008, guest PC 0x0c043dd0 */
if(!s->budget--) { s->failed_pc=0x0c043dd0u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c043dd2;
P_0c043dd2: /* original 8917, guest PC 0x0c043dd2 */
if(!s->budget--) { s->failed_pc=0x0c043dd2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c043e04; }
goto P_0c043dd4;
P_0c043dd4: /* original 59e2, guest PC 0x0c043dd4 */
if(!s->budget--) { s->failed_pc=0x0c043dd4u; return 0; }
r[9]=read(ram,r[14]+8,4);
goto P_0c043dd6;
P_0c043dd6: /* original 1ec2, guest PC 0x0c043dd6 */
if(!s->budget--) { s->failed_pc=0x0c043dd6u; return 0; }
write(ram,r[14]+8,r[12],4);
goto P_0c043dd8;
P_0c043dd8: /* original b078, guest PC 0x0c043dd8 */
if(!s->budget--) { s->failed_pc=0x0c043dd8u; return 0; }
target=code_base|0x0c043eccu; r[16]=code_base|0x0c043ddcu;
tmp=read(ram,r[14],4);
r[4]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c043ddcu) { target=s->pc; goto dispatch; }
goto P_0c043ddc;
P_0c043dda: /* original 64e2, guest PC 0x0c043dda */
if(!s->budget--) { s->failed_pc=0x0c043ddau; return 0; }
tmp=read(ram,r[14],4);
r[4]=tmp;
goto P_0c043ddc;
P_0c043ddc: /* original 2f06, guest PC 0x0c043ddc */
if(!s->budget--) { s->failed_pc=0x0c043ddcu; return 0; }
tmp=r[0]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c043dde;
P_0c043dde: /* original b06b, guest PC 0x0c043dde */
if(!s->budget--) { s->failed_pc=0x0c043ddeu; return 0; }
target=code_base|0x0c043eb8u; r[16]=code_base|0x0c043de2u;
tmp=read(ram,r[14],4);
r[4]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c043de2u) { target=s->pc; goto dispatch; }
goto P_0c043de2;
P_0c043de0: /* original 64e2, guest PC 0x0c043de0 */
if(!s->budget--) { s->failed_pc=0x0c043de0u; return 0; }
tmp=read(ram,r[14],4);
r[4]=tmp;
goto P_0c043de2;
P_0c043de2: /* original 2f06, guest PC 0x0c043de2 */
if(!s->budget--) { s->failed_pc=0x0c043de2u; return 0; }
tmp=r[0]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c043de4;
P_0c043de4: /* original 66e2, guest PC 0x0c043de4 */
if(!s->budget--) { s->failed_pc=0x0c043de4u; return 0; }
tmp=read(ram,r[14],4);
r[6]=tmp;
goto P_0c043de6;
P_0c043de6: /* original d446, guest PC 0x0c043de6 */
if(!s->budget--) { s->failed_pc=0x0c043de6u; return 0; }
r[4]=read(ram,0x0c043f00u,4);
goto P_0c043de8;
P_0c043de8: /* original 57e1, guest PC 0x0c043de8 */
if(!s->budget--) { s->failed_pc=0x0c043de8u; return 0; }
r[7]=read(ram,r[14]+4,4);
goto P_0c043dea;
P_0c043dea: /* original 4d0b, guest PC 0x0c043dea */
if(!s->budget--) { s->failed_pc=0x0c043deau; return 0; }
target=r[13];
r[16]=code_base|0x0c043deeu;
r[5]=r[9];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c043deeu) { target=s->pc; goto dispatch; }
goto P_0c043dee;
P_0c043dec: /* original 6593, guest PC 0x0c043dec */
if(!s->budget--) { s->failed_pc=0x0c043decu; return 0; }
r[5]=r[9];
goto P_0c043dee;
P_0c043dee: /* original 7f08, guest PC 0x0c043dee */
if(!s->budget--) { s->failed_pc=0x0c043deeu; return 0; }
r[15]+=0x00000008u;
goto P_0c043df0;
P_0c043df0: /* original b06c, guest PC 0x0c043df0 */
if(!s->budget--) { s->failed_pc=0x0c043df0u; return 0; }
target=code_base|0x0c043eccu; r[16]=code_base|0x0c043df4u;
tmp=read(ram,r[14],4);
r[4]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c043df4u) { target=s->pc; goto dispatch; }
goto P_0c043df4;
P_0c043df2: /* original 64e2, guest PC 0x0c043df2 */
if(!s->budget--) { s->failed_pc=0x0c043df2u; return 0; }
tmp=read(ram,r[14],4);
r[4]=tmp;
goto P_0c043df4;
P_0c043df4: /* original 2f06, guest PC 0x0c043df4 */
if(!s->budget--) { s->failed_pc=0x0c043df4u; return 0; }
tmp=r[0]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c043df6;
P_0c043df6: /* original b05f, guest PC 0x0c043df6 */
if(!s->budget--) { s->failed_pc=0x0c043df6u; return 0; }
target=code_base|0x0c043eb8u; r[16]=code_base|0x0c043dfau;
tmp=read(ram,r[14],4);
r[4]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c043dfau) { target=s->pc; goto dispatch; }
goto P_0c043dfa;
P_0c043df8: /* original 64e2, guest PC 0x0c043df8 */
if(!s->budget--) { s->failed_pc=0x0c043df8u; return 0; }
tmp=read(ram,r[14],4);
r[4]=tmp;
goto P_0c043dfa;
P_0c043dfa: /* original 64e2, guest PC 0x0c043dfa */
if(!s->budget--) { s->failed_pc=0x0c043dfau; return 0; }
tmp=read(ram,r[14],4);
r[4]=tmp;
goto P_0c043dfc;
P_0c043dfc: /* original 6603, guest PC 0x0c043dfc */
if(!s->budget--) { s->failed_pc=0x0c043dfcu; return 0; }
r[6]=r[0];
goto P_0c043dfe;
P_0c043dfe: /* original 55e1, guest PC 0x0c043dfe */
if(!s->budget--) { s->failed_pc=0x0c043dfeu; return 0; }
r[5]=read(ram,r[14]+4,4);
goto P_0c043e00;
P_0c043e00: /* original 490b, guest PC 0x0c043e00 */
if(!s->budget--) { s->failed_pc=0x0c043e00u; return 0; }
target=r[9];
r[16]=code_base|0x0c043e04u;
tmp=read(ram,r[15],4);
r[15]+=4;
r[7]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c043e04u) { target=s->pc; goto dispatch; }
goto P_0c043e04;
P_0c043e02: /* original 67f6, guest PC 0x0c043e02 */
if(!s->budget--) { s->failed_pc=0x0c043e02u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[7]=tmp;
goto P_0c043e04;
P_0c043e04: /* original 7e0c, guest PC 0x0c043e04 */
if(!s->budget--) { s->failed_pc=0x0c043e04u; return 0; }
r[14]+=0x0000000cu;
goto P_0c043e06;
P_0c043e06: /* original 7b01, guest PC 0x0c043e06 */
if(!s->budget--) { s->failed_pc=0x0c043e06u; return 0; }
r[11]+=0x00000001u;
goto P_0c043e08;
P_0c043e08: /* original e330, guest PC 0x0c043e08 */
if(!s->budget--) { s->failed_pc=0x0c043e08u; return 0; }
r[3]=0x00000030u;
goto P_0c043e0a;
P_0c043e0a: /* original 3b33, guest PC 0x0c043e0a */
if(!s->budget--) { s->failed_pc=0x0c043e0au; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[11]>=(int32_t)r[3])!=0);
goto P_0c043e0c;
P_0c043e0c: /* original 8bd2, guest PC 0x0c043e0c */
if(!s->budget--) { s->failed_pc=0x0c043e0cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c043db4; }
goto P_0c043e0e;
P_0c043e0e: /* original d23d, guest PC 0x0c043e0e */
if(!s->budget--) { s->failed_pc=0x0c043e0eu; return 0; }
r[2]=read(ram,0x0c043f04u,4);
goto P_0c043e10;
P_0c043e10: /* original 906d, guest PC 0x0c043e10 */
if(!s->budget--) { s->failed_pc=0x0c043e10u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c043eeeu,2);
goto P_0c043e12;
P_0c043e12: /* original 6122, guest PC 0x0c043e12 */
if(!s->budget--) { s->failed_pc=0x0c043e12u; return 0; }
tmp=read(ram,r[2],4);
r[1]=tmp;
goto P_0c043e14;
P_0c043e14: /* original 01c6, guest PC 0x0c043e14 */
if(!s->budget--) { s->failed_pc=0x0c043e14u; return 0; }
write(ram,r[1]+r[0],r[12],4);
goto P_0c043e16;
P_0c043e16: /* original d33c, guest PC 0x0c043e16 */
if(!s->budget--) { s->failed_pc=0x0c043e16u; return 0; }
r[3]=read(ram,0x0c043f08u,4);
goto P_0c043e18;
P_0c043e18: /* original 6032, guest PC 0x0c043e18 */
if(!s->budget--) { s->failed_pc=0x0c043e18u; return 0; }
tmp=read(ram,r[3],4);
r[0]=tmp;
goto P_0c043e1a;
P_0c043e1a: /* original ca01, guest PC 0x0c043e1a */
if(!s->budget--) { s->failed_pc=0x0c043e1au; return 0; }
r[0]^=1u;
goto P_0c043e1c;
P_0c043e1c: /* original 2302, guest PC 0x0c043e1c */
if(!s->budget--) { s->failed_pc=0x0c043e1cu; return 0; }
write(ram,r[3],r[0],4);
goto P_0c043e1e;
P_0c043e1e: /* original 5181, guest PC 0x0c043e1e */
if(!s->budget--) { s->failed_pc=0x0c043e1eu; return 0; }
r[1]=read(ram,r[8]+4,4);
goto P_0c043e20;
P_0c043e20: /* original 7101, guest PC 0x0c043e20 */
if(!s->budget--) { s->failed_pc=0x0c043e20u; return 0; }
r[1]+=0x00000001u;
goto P_0c043e22;
P_0c043e22: /* original a009, guest PC 0x0c043e22 */
if(!s->budget--) { s->failed_pc=0x0c043e22u; return 0; }
write(ram,r[8]+4,r[1],4);
goto P_0c043e38;
P_0c043e24: /* original 1811, guest PC 0x0c043e24 */
if(!s->budget--) { s->failed_pc=0x0c043e24u; return 0; }
write(ram,r[8]+4,r[1],4);
goto P_0c043e26;
P_0c043e26: /* original d239, guest PC 0x0c043e26 */
if(!s->budget--) { s->failed_pc=0x0c043e26u; return 0; }
r[2]=read(ram,0x0c043f0cu,4);
goto P_0c043e28;
P_0c043e28: /* original 6e22, guest PC 0x0c043e28 */
if(!s->budget--) { s->failed_pc=0x0c043e28u; return 0; }
tmp=read(ram,r[2],4);
r[14]=tmp;
goto P_0c043e2a;
P_0c043e2a: /* original 2ee8, guest PC 0x0c043e2a */
if(!s->budget--) { s->failed_pc=0x0c043e2au; return 0; }
r[17]=(r[17]&~1u)|(((r[14]&r[14])==0)!=0);
goto P_0c043e2c;
P_0c043e2c: /* original 8904, guest PC 0x0c043e2c */
if(!s->budget--) { s->failed_pc=0x0c043e2cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c043e38; }
goto P_0c043e2e;
P_0c043e2e: /* original 5682, guest PC 0x0c043e2e */
if(!s->budget--) { s->failed_pc=0x0c043e2eu; return 0; }
r[6]=read(ram,r[8]+8,4);
goto P_0c043e30;
P_0c043e30: /* original e5f8, guest PC 0x0c043e30 */
if(!s->budget--) { s->failed_pc=0x0c043e30u; return 0; }
r[5]=0xfffffff8u;
goto P_0c043e32;
P_0c043e32: /* original 67a3, guest PC 0x0c043e32 */
if(!s->budget--) { s->failed_pc=0x0c043e32u; return 0; }
r[7]=r[10];
goto P_0c043e34;
P_0c043e34: /* original 4e0b, guest PC 0x0c043e34 */
if(!s->budget--) { s->failed_pc=0x0c043e34u; return 0; }
target=r[14];
r[16]=code_base|0x0c043e38u;
r[4]=0x00000002u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c043e38u) { target=s->pc; goto dispatch; }
goto P_0c043e38;
P_0c043e36: /* original e402, guest PC 0x0c043e36 */
if(!s->budget--) { s->failed_pc=0x0c043e36u; return 0; }
r[4]=0x00000002u;
goto P_0c043e38;
P_0c043e38: /* original d235, guest PC 0x0c043e38 */
if(!s->budget--) { s->failed_pc=0x0c043e38u; return 0; }
r[2]=read(ram,0x0c043f10u,4);
goto P_0c043e3a;
P_0c043e3a: /* original 22c2, guest PC 0x0c043e3a */
if(!s->budget--) { s->failed_pc=0x0c043e3au; return 0; }
write(ram,r[2],r[12],4);
goto P_0c043e3c;
P_0c043e3c: /* original 4f16, guest PC 0x0c043e3c */
if(!s->budget--) { s->failed_pc=0x0c043e3cu; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c043e3e;
P_0c043e3e: /* original 60a3, guest PC 0x0c043e3e */
if(!s->budget--) { s->failed_pc=0x0c043e3eu; return 0; }
r[0]=r[10];
goto P_0c043e40;
P_0c043e40: /* original 4f26, guest PC 0x0c043e40 */
if(!s->budget--) { s->failed_pc=0x0c043e40u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c043e42;
P_0c043e42: /* original 68f6, guest PC 0x0c043e42 */
if(!s->budget--) { s->failed_pc=0x0c043e42u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c043e44;
P_0c043e44: /* original 69f6, guest PC 0x0c043e44 */
if(!s->budget--) { s->failed_pc=0x0c043e44u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c043e46;
P_0c043e46: /* original 6af6, guest PC 0x0c043e46 */
if(!s->budget--) { s->failed_pc=0x0c043e46u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c043e48;
P_0c043e48: /* original 6bf6, guest PC 0x0c043e48 */
if(!s->budget--) { s->failed_pc=0x0c043e48u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c043e4a;
P_0c043e4a: /* original 6cf6, guest PC 0x0c043e4a */
if(!s->budget--) { s->failed_pc=0x0c043e4au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c043e4c;
P_0c043e4c: /* original 6df6, guest PC 0x0c043e4c */
if(!s->budget--) { s->failed_pc=0x0c043e4cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c043e4e;
P_0c043e4e: /* original 000b, guest PC 0x0c043e4e */
if(!s->budget--) { s->failed_pc=0x0c043e4eu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c043e50: /* original 6ef6, guest PC 0x0c043e50 */
if(!s->budget--) { s->failed_pc=0x0c043e50u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c043e52u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c043e52u; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
