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
int vf3_away_batch54_adapter_2(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c0879dau: goto P_0c0879da;
case 0x0c0879dcu: goto P_0c0879dc;
case 0x0c0879deu: goto P_0c0879de;
case 0x0c0879e0u: goto P_0c0879e0;
case 0x0c0879e2u: goto P_0c0879e2;
case 0x0c0879e4u: goto P_0c0879e4;
case 0x0c0879e6u: goto P_0c0879e6;
case 0x0c0879e8u: goto P_0c0879e8;
case 0x0c0879eau: goto P_0c0879ea;
case 0x0c0879ecu: goto P_0c0879ec;
case 0x0c0879eeu: goto P_0c0879ee;
case 0x0c0879f0u: goto P_0c0879f0;
case 0x0c0879f2u: goto P_0c0879f2;
case 0x0c0879f4u: goto P_0c0879f4;
case 0x0c0879f6u: goto P_0c0879f6;
case 0x0c0879f8u: goto P_0c0879f8;
case 0x0c0879fau: goto P_0c0879fa;
case 0x0c0879fcu: goto P_0c0879fc;
case 0x0c0879feu: goto P_0c0879fe;
case 0x0c087a00u: goto P_0c087a00;
case 0x0c087a02u: goto P_0c087a02;
case 0x0c087a04u: goto P_0c087a04;
case 0x0c087a06u: goto P_0c087a06;
case 0x0c087a08u: goto P_0c087a08;
case 0x0c087a0au: goto P_0c087a0a;
case 0x0c087a0cu: goto P_0c087a0c;
case 0x0c087a0eu: goto P_0c087a0e;
case 0x0c087a10u: goto P_0c087a10;
case 0x0c087a12u: goto P_0c087a12;
case 0x0c087a14u: goto P_0c087a14;
case 0x0c087a16u: goto P_0c087a16;
case 0x0c087a18u: goto P_0c087a18;
case 0x0c087a1au: goto P_0c087a1a;
case 0x0c087a1cu: goto P_0c087a1c;
case 0x0c087a1eu: goto P_0c087a1e;
case 0x0c087a20u: goto P_0c087a20;
case 0x0c087a22u: goto P_0c087a22;
case 0x0c087a40u: goto P_0c087a40;
case 0x0c087a42u: goto P_0c087a42;
case 0x0c087a44u: goto P_0c087a44;
case 0x0c087a46u: goto P_0c087a46;
case 0x0c087a48u: goto P_0c087a48;
case 0x0c087a4au: goto P_0c087a4a;
case 0x0c087a4cu: goto P_0c087a4c;
case 0x0c087a4eu: goto P_0c087a4e;
case 0x0c087a50u: goto P_0c087a50;
case 0x0c087a52u: goto P_0c087a52;
case 0x0c087a54u: goto P_0c087a54;
case 0x0c087a56u: goto P_0c087a56;
case 0x0c087a58u: goto P_0c087a58;
case 0x0c087a5au: goto P_0c087a5a;
case 0x0c087a5cu: goto P_0c087a5c;
case 0x0c087a5eu: goto P_0c087a5e;
case 0x0c087a60u: goto P_0c087a60;
case 0x0c087a62u: goto P_0c087a62;
case 0x0c087a64u: goto P_0c087a64;
case 0x0c087a66u: goto P_0c087a66;
case 0x0c087a68u: goto P_0c087a68;
case 0x0c087a6au: goto P_0c087a6a;
case 0x0c087a6cu: goto P_0c087a6c;
case 0x0c087a6eu: goto P_0c087a6e;
case 0x0c087a70u: goto P_0c087a70;
case 0x0c087a72u: goto P_0c087a72;
case 0x0c087a74u: goto P_0c087a74;
case 0x0c087a76u: goto P_0c087a76;
case 0x0c087a78u: goto P_0c087a78;
case 0x0c087a7au: goto P_0c087a7a;
case 0x0c087a7cu: goto P_0c087a7c;
case 0x0c087a7eu: goto P_0c087a7e;
case 0x0c087a80u: goto P_0c087a80;
case 0x0c087a82u: goto P_0c087a82;
case 0x0c087a84u: goto P_0c087a84;
case 0x0c087a86u: goto P_0c087a86;
case 0x0c087a88u: goto P_0c087a88;
case 0x0c087a8au: goto P_0c087a8a;
case 0x0c087a8cu: goto P_0c087a8c;
case 0x0c087a8eu: goto P_0c087a8e;
case 0x0c087a90u: goto P_0c087a90;
case 0x0c087a92u: goto P_0c087a92;
case 0x0c087a94u: goto P_0c087a94;
case 0x0c087a96u: goto P_0c087a96;
case 0x0c087a98u: goto P_0c087a98;
case 0x0c087a9au: goto P_0c087a9a;
case 0x0c087a9cu: goto P_0c087a9c;
case 0x0c087a9eu: goto P_0c087a9e;
case 0x0c087aa0u: goto P_0c087aa0;
case 0x0c087aa2u: goto P_0c087aa2;
case 0x0c087aa4u: goto P_0c087aa4;
case 0x0c087aa6u: goto P_0c087aa6;
case 0x0c087aa8u: goto P_0c087aa8;
case 0x0c087aaau: goto P_0c087aaa;
case 0x0c087aacu: goto P_0c087aac;
case 0x0c087aaeu: goto P_0c087aae;
case 0x0c087ab0u: goto P_0c087ab0;
case 0x0c087ab2u: goto P_0c087ab2;
case 0x0c087ab4u: goto P_0c087ab4;
case 0x0c087ab6u: goto P_0c087ab6;
case 0x0c087ab8u: goto P_0c087ab8;
case 0x0c087abau: goto P_0c087aba;
case 0x0c087abcu: goto P_0c087abc;
case 0x0c087abeu: goto P_0c087abe;
case 0x0c087ac0u: goto P_0c087ac0;
case 0x0c087ac2u: goto P_0c087ac2;
case 0x0c087ac4u: goto P_0c087ac4;
case 0x0c087ac6u: goto P_0c087ac6;
case 0x0c087ac8u: goto P_0c087ac8;
case 0x0c087acau: goto P_0c087aca;
case 0x0c087accu: goto P_0c087acc;
case 0x0c087b80u: goto P_0c087b80;
case 0x0c087b82u: goto P_0c087b82;
case 0x0c087b84u: goto P_0c087b84;
case 0x0c087b86u: goto P_0c087b86;
case 0x0c087b88u: goto P_0c087b88;
case 0x0c087b8au: goto P_0c087b8a;
case 0x0c087b8cu: goto P_0c087b8c;
case 0x0c087b8eu: goto P_0c087b8e;
case 0x0c087b90u: goto P_0c087b90;
case 0x0c087b92u: goto P_0c087b92;
case 0x0c087b94u: goto P_0c087b94;
case 0x0c087b96u: goto P_0c087b96;
case 0x0c087b98u: goto P_0c087b98;
case 0x0c087b9au: goto P_0c087b9a;
case 0x0c087b9cu: goto P_0c087b9c;
case 0x0c087b9eu: goto P_0c087b9e;
case 0x0c087ba0u: goto P_0c087ba0;
case 0x0c087ba2u: goto P_0c087ba2;
case 0x0c087ba4u: goto P_0c087ba4;
case 0x0c087ba6u: goto P_0c087ba6;
case 0x0c087ba8u: goto P_0c087ba8;
case 0x0c087baau: goto P_0c087baa;
case 0x0c087bacu: goto P_0c087bac;
case 0x0c087baeu: goto P_0c087bae;
case 0x0c087bb0u: goto P_0c087bb0;
case 0x0c087bb2u: goto P_0c087bb2;
case 0x0c087bb4u: goto P_0c087bb4;
case 0x0c087bb6u: goto P_0c087bb6;
case 0x0c087bb8u: goto P_0c087bb8;
case 0x0c087bbau: goto P_0c087bba;
case 0x0c087bbcu: goto P_0c087bbc;
case 0x0c087bbeu: goto P_0c087bbe;
case 0x0c087bc0u: goto P_0c087bc0;
case 0x0c087bc2u: goto P_0c087bc2;
case 0x0c087bc4u: goto P_0c087bc4;
case 0x0c087bc6u: goto P_0c087bc6;
case 0x0c087bc8u: goto P_0c087bc8;
case 0x0c087bcau: goto P_0c087bca;
case 0x0c087bccu: goto P_0c087bcc;
case 0x0c087bceu: goto P_0c087bce;
case 0x0c087bd0u: goto P_0c087bd0;
case 0x0c087bd2u: goto P_0c087bd2;
case 0x0c087bd4u: goto P_0c087bd4;
case 0x0c087bd6u: goto P_0c087bd6;
case 0x0c087bd8u: goto P_0c087bd8;
case 0x0c087bf8u: goto P_0c087bf8;
case 0x0c087bfau: goto P_0c087bfa;
case 0x0c087bfcu: goto P_0c087bfc;
case 0x0c087bfeu: goto P_0c087bfe;
case 0x0c087c00u: goto P_0c087c00;
case 0x0c087c02u: goto P_0c087c02;
case 0x0c087c04u: goto P_0c087c04;
case 0x0c087c06u: goto P_0c087c06;
case 0x0c087c08u: goto P_0c087c08;
case 0x0c087c0au: goto P_0c087c0a;
case 0x0c087c0cu: goto P_0c087c0c;
case 0x0c087c0eu: goto P_0c087c0e;
case 0x0c087c10u: goto P_0c087c10;
case 0x0c087c12u: goto P_0c087c12;
case 0x0c087c14u: goto P_0c087c14;
case 0x0c087c16u: goto P_0c087c16;
case 0x0c087c18u: goto P_0c087c18;
case 0x0c087c1au: goto P_0c087c1a;
case 0x0c087c1cu: goto P_0c087c1c;
case 0x0c087c1eu: goto P_0c087c1e;
case 0x0c087c20u: goto P_0c087c20;
case 0x0c087c22u: goto P_0c087c22;
case 0x0c087c24u: goto P_0c087c24;
case 0x0c087c26u: goto P_0c087c26;
case 0x0c087c28u: goto P_0c087c28;
case 0x0c087c2au: goto P_0c087c2a;
case 0x0c087c2cu: goto P_0c087c2c;
case 0x0c087c2eu: goto P_0c087c2e;
case 0x0c087c30u: goto P_0c087c30;
case 0x0c087c32u: goto P_0c087c32;
case 0x0c087c34u: goto P_0c087c34;
case 0x0c087c36u: goto P_0c087c36;
case 0x0c087c38u: goto P_0c087c38;
case 0x0c087c3au: goto P_0c087c3a;
case 0x0c087c3cu: goto P_0c087c3c;
case 0x0c087c3eu: goto P_0c087c3e;
case 0x0c087c40u: goto P_0c087c40;
case 0x0c087c42u: goto P_0c087c42;
case 0x0c087c44u: goto P_0c087c44;
case 0x0c087c46u: goto P_0c087c46;
case 0x0c087c48u: goto P_0c087c48;
case 0x0c087c4au: goto P_0c087c4a;
case 0x0c087c4cu: goto P_0c087c4c;
case 0x0c087c4eu: goto P_0c087c4e;
case 0x0c087c50u: goto P_0c087c50;
case 0x0c087c52u: goto P_0c087c52;
case 0x0c087c54u: goto P_0c087c54;
case 0x0c087c56u: goto P_0c087c56;
case 0x0c087c58u: goto P_0c087c58;
case 0x0c087c5au: goto P_0c087c5a;
case 0x0c087c5cu: goto P_0c087c5c;
case 0x0c087c5eu: goto P_0c087c5e;
case 0x0c087c60u: goto P_0c087c60;
case 0x0c087c62u: goto P_0c087c62;
case 0x0c087c64u: goto P_0c087c64;
case 0x0c087c66u: goto P_0c087c66;
case 0x0c087c68u: goto P_0c087c68;
case 0x0c087c6au: goto P_0c087c6a;
case 0x0c087c6cu: goto P_0c087c6c;
case 0x0c087c6eu: goto P_0c087c6e;
case 0x0c087c70u: goto P_0c087c70;
case 0x0c087c72u: goto P_0c087c72;
case 0x0c087c74u: goto P_0c087c74;
case 0x0c087c76u: goto P_0c087c76;
case 0x0c087c78u: goto P_0c087c78;
case 0x0c087c7au: goto P_0c087c7a;
case 0x0c087c7cu: goto P_0c087c7c;
case 0x0c087c7eu: goto P_0c087c7e;
case 0x0c087c80u: goto P_0c087c80;
case 0x0c087c82u: goto P_0c087c82;
case 0x0c087c84u: goto P_0c087c84;
case 0x0c087c86u: goto P_0c087c86;
case 0x0c087c88u: goto P_0c087c88;
case 0x0c087c8au: goto P_0c087c8a;
case 0x0c087c8cu: goto P_0c087c8c;
case 0x0c087c8eu: goto P_0c087c8e;
case 0x0c087c90u: goto P_0c087c90;
case 0x0c087c92u: goto P_0c087c92;
case 0x0c087c94u: goto P_0c087c94;
case 0x0c087c96u: goto P_0c087c96;
case 0x0c087c98u: goto P_0c087c98;
case 0x0c087c9au: goto P_0c087c9a;
case 0x0c087c9cu: goto P_0c087c9c;
case 0x0c087c9eu: goto P_0c087c9e;
case 0x0c087ca0u: goto P_0c087ca0;
case 0x0c087ca2u: goto P_0c087ca2;
case 0x0c087ca4u: goto P_0c087ca4;
case 0x0c087ca6u: goto P_0c087ca6;
case 0x0c087ca8u: goto P_0c087ca8;
case 0x0c087caau: goto P_0c087caa;
case 0x0c087cacu: goto P_0c087cac;
case 0x0c087caeu: goto P_0c087cae;
case 0x0c087cb0u: goto P_0c087cb0;
case 0x0c087cb2u: goto P_0c087cb2;
case 0x0c087cb4u: goto P_0c087cb4;
case 0x0c087cb6u: goto P_0c087cb6;
case 0x0c087cb8u: goto P_0c087cb8;
case 0x0c087cbau: goto P_0c087cba;
case 0x0c087cbcu: goto P_0c087cbc;
case 0x0c087cbeu: goto P_0c087cbe;
case 0x0c087cc0u: goto P_0c087cc0;
case 0x0c087cc2u: goto P_0c087cc2;
case 0x0c087cc4u: goto P_0c087cc4;
default: return vf3_matrix_family(target,s,ram);
}
P_0c0879da: /* original 4f22, guest PC 0x0c0879da */
if(!s->budget--) { s->failed_pc=0x0c0879dau; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0879dc;
P_0c0879dc: /* original 9024, guest PC 0x0c0879dc */
if(!s->budget--) { s->failed_pc=0x0c0879dcu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c087a28u,2);
goto P_0c0879de;
P_0c0879de: /* original 4f12, guest PC 0x0c0879de */
if(!s->budget--) { s->failed_pc=0x0c0879deu; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c0879e0;
P_0c0879e0: /* original f346, guest PC 0x0c0879e0 */
if(!s->budget--) { s->failed_pc=0x0c0879e0u; return 0; }
vf3_matrix_load(s,ram,3,r[4]+r[0]);
goto P_0c0879e2;
P_0c0879e2: /* original e008, guest PC 0x0c0879e2 */
if(!s->budget--) { s->failed_pc=0x0c0879e2u; return 0; }
r[0]=0x00000008u;
goto P_0c0879e4;
P_0c0879e4: /* original 7ff4, guest PC 0x0c0879e4 */
if(!s->budget--) { s->failed_pc=0x0c0879e4u; return 0; }
r[15]+=0xfffffff4u;
goto P_0c0879e6;
P_0c0879e6: /* original ff37, guest PC 0x0c0879e6 */
if(!s->budget--) { s->failed_pc=0x0c0879e6u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0879e8;
P_0c0879e8: /* original 901f, guest PC 0x0c0879e8 */
if(!s->budget--) { s->failed_pc=0x0c0879e8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c087a2au,2);
goto P_0c0879ea;
P_0c0879ea: /* original f346, guest PC 0x0c0879ea */
if(!s->budget--) { s->failed_pc=0x0c0879eau; return 0; }
vf3_matrix_load(s,ram,3,r[4]+r[0]);
goto P_0c0879ec;
P_0c0879ec: /* original ff3a, guest PC 0x0c0879ec */
if(!s->budget--) { s->failed_pc=0x0c0879ecu; return 0; }
vf3_matrix_store(s,ram,3,r[15]);
goto P_0c0879ee;
P_0c0879ee: /* original 901d, guest PC 0x0c0879ee */
if(!s->budget--) { s->failed_pc=0x0c0879eeu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c087a2cu,2);
goto P_0c0879f0;
P_0c0879f0: /* original 054e, guest PC 0x0c0879f0 */
if(!s->budget--) { s->failed_pc=0x0c0879f0u; return 0; }
r[5]=read(ram,r[4]+r[0],4);
goto P_0c0879f2;
P_0c0879f2: /* original 7008, guest PC 0x0c0879f2 */
if(!s->budget--) { s->failed_pc=0x0c0879f2u; return 0; }
r[0]+=0x00000008u;
goto P_0c0879f4;
P_0c0879f4: /* original 044e, guest PC 0x0c0879f4 */
if(!s->budget--) { s->failed_pc=0x0c0879f4u; return 0; }
r[4]=read(ram,r[4]+r[0],4);
goto P_0c0879f6;
P_0c0879f6: /* original c710, guest PC 0x0c0879f6 */
if(!s->budget--) { s->failed_pc=0x0c0879f6u; return 0; }
r[0]=code_base|0x00087a38u;
goto P_0c0879f8;
P_0c0879f8: /* original f308, guest PC 0x0c0879f8 */
if(!s->budget--) { s->failed_pc=0x0c0879f8u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c0879fa;
P_0c0879fa: /* original f432, guest PC 0x0c0879fa */
if(!s->budget--) { s->failed_pc=0x0c0879fau; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'*');
goto P_0c0879fc;
P_0c0879fc: /* original f43d, guest PC 0x0c0879fc */
if(!s->budget--) { s->failed_pc=0x0c0879fcu; return 0; }
r[53]=truncate_float(fr[4]);
goto P_0c0879fe;
P_0c0879fe: /* original 065a, guest PC 0x0c0879fe */
if(!s->budget--) { s->failed_pc=0x0c0879feu; return 0; }
r[6]=r[53];
goto P_0c087a00;
P_0c087a00: /* original 346c, guest PC 0x0c087a00 */
if(!s->budget--) { s->failed_pc=0x0c087a00u; return 0; }
r[4]+=r[6];
goto P_0c087a02;
P_0c087a02: /* original 0547, guest PC 0x0c087a02 */
if(!s->budget--) { s->failed_pc=0x0c087a02u; return 0; }
r[19]=r[5]*r[4];
goto P_0c087a04;
P_0c087a04: /* original 041a, guest PC 0x0c087a04 */
if(!s->budget--) { s->failed_pc=0x0c087a04u; return 0; }
r[4]=r[19];
goto P_0c087a06;
P_0c087a06: /* original 644d, guest PC 0x0c087a06 */
if(!s->budget--) { s->failed_pc=0x0c087a06u; return 0; }
r[4]=r[4]&65535u;
goto P_0c087a08;
P_0c087a08: /* original 1f41, guest PC 0x0c087a08 */
if(!s->budget--) { s->failed_pc=0x0c087a08u; return 0; }
write(ram,r[15]+4,r[4],4);
goto P_0c087a0a;
P_0c087a0a: /* original d30c, guest PC 0x0c087a0a */
if(!s->budget--) { s->failed_pc=0x0c087a0au; return 0; }
r[3]=read(ram,0x0c087a3cu,4);
goto P_0c087a0c;
P_0c087a0c: /* original 430b, guest PC 0x0c087a0c */
if(!s->budget--) { s->failed_pc=0x0c087a0cu; return 0; }
target=r[3];
r[16]=code_base|0x0c087a10u;
r[4]=(uint32_t)(int32_t)(int16_t)r[4];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c087a10u) { target=s->pc; goto dispatch; }
goto P_0c087a10;
P_0c087a0e: /* original 644f, guest PC 0x0c087a0e */
if(!s->budget--) { s->failed_pc=0x0c087a0eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)r[4];
goto P_0c087a10;
P_0c087a10: /* original e008, guest PC 0x0c087a10 */
if(!s->budget--) { s->failed_pc=0x0c087a10u; return 0; }
r[0]=0x00000008u;
goto P_0c087a12;
P_0c087a12: /* original f2f8, guest PC 0x0c087a12 */
if(!s->budget--) { s->failed_pc=0x0c087a12u; return 0; }
vf3_matrix_load(s,ram,2,r[15]);
goto P_0c087a14;
P_0c087a14: /* original f3f6, guest PC 0x0c087a14 */
if(!s->budget--) { s->failed_pc=0x0c087a14u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c087a16;
P_0c087a16: /* original 7f0c, guest PC 0x0c087a16 */
if(!s->budget--) { s->failed_pc=0x0c087a16u; return 0; }
r[15]+=0x0000000cu;
goto P_0c087a18;
P_0c087a18: /* original 4f16, guest PC 0x0c087a18 */
if(!s->budget--) { s->failed_pc=0x0c087a18u; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c087a1a;
P_0c087a1a: /* original f32e, guest PC 0x0c087a1a */
if(!s->budget--) { s->failed_pc=0x0c087a1au; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[2],fr[3],r[18]);
goto P_0c087a1c;
P_0c087a1c: /* original 4f26, guest PC 0x0c087a1c */
if(!s->budget--) { s->failed_pc=0x0c087a1cu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c087a1e;
P_0c087a1e: /* original f03c, guest PC 0x0c087a1e */
if(!s->budget--) { s->failed_pc=0x0c087a1eu; return 0; }
vf3_matrix_move(s,0,3);
goto P_0c087a20;
P_0c087a20: /* original 000b, guest PC 0x0c087a20 */
if(!s->budget--) { s->failed_pc=0x0c087a20u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c087a22: /* original 0009, guest PC 0x0c087a22 */
if(!s->budget--) { s->failed_pc=0x0c087a22u; return 0; }
if(!vf3_matrix_family(0x0c087a24u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c087a24u; return 0; } return 1;
P_0c087a40: /* original d347, guest PC 0x0c087a40 */
if(!s->budget--) { s->failed_pc=0x0c087a40u; return 0; }
r[3]=read(ram,0x0c087b60u,4);
goto P_0c087a42;
P_0c087a42: /* original 9088, guest PC 0x0c087a42 */
if(!s->budget--) { s->failed_pc=0x0c087a42u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c087b56u,2);
goto P_0c087a44;
P_0c087a44: /* original 6432, guest PC 0x0c087a44 */
if(!s->budget--) { s->failed_pc=0x0c087a44u; return 0; }
tmp=read(ram,r[3],4);
r[4]=tmp;
goto P_0c087a46;
P_0c087a46: /* original 044e, guest PC 0x0c087a46 */
if(!s->budget--) { s->failed_pc=0x0c087a46u; return 0; }
r[4]=read(ram,r[4]+r[0],4);
goto P_0c087a48;
P_0c087a48: /* original 2448, guest PC 0x0c087a48 */
if(!s->budget--) { s->failed_pc=0x0c087a48u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c087a4a;
P_0c087a4a: /* original 893d, guest PC 0x0c087a4a */
if(!s->budget--) { s->failed_pc=0x0c087a4au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c087ac8; }
goto P_0c087a4c;
P_0c087a4c: /* original c745, guest PC 0x0c087a4c */
if(!s->budget--) { s->failed_pc=0x0c087a4cu; return 0; }
r[0]=code_base|0x00087b64u;
goto P_0c087a4e;
P_0c087a4e: /* original 9383, guest PC 0x0c087a4e */
if(!s->budget--) { s->failed_pc=0x0c087a4eu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c087b58u,2);
goto P_0c087a50;
P_0c087a50: /* original f908, guest PC 0x0c087a50 */
if(!s->budget--) { s->failed_pc=0x0c087a50u; return 0; }
vf3_matrix_load(s,ram,9,r[0]);
goto P_0c087a52;
P_0c087a52: /* original c745, guest PC 0x0c087a52 */
if(!s->budget--) { s->failed_pc=0x0c087a52u; return 0; }
r[0]=code_base|0x00087b68u;
goto P_0c087a54;
P_0c087a54: /* original f808, guest PC 0x0c087a54 */
if(!s->budget--) { s->failed_pc=0x0c087a54u; return 0; }
vf3_matrix_load(s,ram,8,r[0]);
goto P_0c087a56;
P_0c087a56: /* original e608, guest PC 0x0c087a56 */
if(!s->budget--) { s->failed_pc=0x0c087a56u; return 0; }
r[6]=0x00000008u;
goto P_0c087a58;
P_0c087a58: /* original 343c, guest PC 0x0c087a58 */
if(!s->budget--) { s->failed_pc=0x0c087a58u; return 0; }
r[4]+=r[3];
goto P_0c087a5a;
P_0c087a5a: /* original e500, guest PC 0x0c087a5a */
if(!s->budget--) { s->failed_pc=0x0c087a5au; return 0; }
r[5]=0x00000000u;
goto P_0c087a5c;
P_0c087a5c: /* original 907d, guest PC 0x0c087a5c */
if(!s->budget--) { s->failed_pc=0x0c087a5cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c087b5au,2);
goto P_0c087a5e;
P_0c087a5e: /* original f69c, guest PC 0x0c087a5e */
if(!s->budget--) { s->failed_pc=0x0c087a5eu; return 0; }
vf3_matrix_move(s,6,9);
goto P_0c087a60;
P_0c087a60: /* original f346, guest PC 0x0c087a60 */
if(!s->budget--) { s->failed_pc=0x0c087a60u; return 0; }
vf3_matrix_load(s,ram,3,r[4]+r[0]);
goto P_0c087a62;
P_0c087a62: /* original 7004, guest PC 0x0c087a62 */
if(!s->budget--) { s->failed_pc=0x0c087a62u; return 0; }
r[0]+=0x00000004u;
goto P_0c087a64;
P_0c087a64: /* original f746, guest PC 0x0c087a64 */
if(!s->budget--) { s->failed_pc=0x0c087a64u; return 0; }
vf3_matrix_load(s,ram,7,r[4]+r[0]);
goto P_0c087a66;
P_0c087a66: /* original 7004, guest PC 0x0c087a66 */
if(!s->budget--) { s->failed_pc=0x0c087a66u; return 0; }
r[0]+=0x00000004u;
goto P_0c087a68;
P_0c087a68: /* original f632, guest PC 0x0c087a68 */
if(!s->budget--) { s->failed_pc=0x0c087a68u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[3],r[18],'*');
goto P_0c087a6a;
P_0c087a6a: /* original fa46, guest PC 0x0c087a6a */
if(!s->budget--) { s->failed_pc=0x0c087a6au; return 0; }
vf3_matrix_load(s,ram,10,r[4]+r[0]);
goto P_0c087a6c;
P_0c087a6c: /* original f37c, guest PC 0x0c087a6c */
if(!s->budget--) { s->failed_pc=0x0c087a6cu; return 0; }
vf3_matrix_move(s,3,7);
goto P_0c087a6e;
P_0c087a6e: /* original 7008, guest PC 0x0c087a6e */
if(!s->budget--) { s->failed_pc=0x0c087a6eu; return 0; }
r[0]+=0x00000008u;
goto P_0c087a70;
P_0c087a70: /* original f79c, guest PC 0x0c087a70 */
if(!s->budget--) { s->failed_pc=0x0c087a70u; return 0; }
vf3_matrix_move(s,7,9);
goto P_0c087a72;
P_0c087a72: /* original f732, guest PC 0x0c087a72 */
if(!s->budget--) { s->failed_pc=0x0c087a72u; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[3],r[18],'*');
goto P_0c087a74;
P_0c087a74: /* original fb46, guest PC 0x0c087a74 */
if(!s->budget--) { s->failed_pc=0x0c087a74u; return 0; }
vf3_matrix_load(s,ram,11,r[4]+r[0]);
goto P_0c087a76;
P_0c087a76: /* original f16c, guest PC 0x0c087a76 */
if(!s->budget--) { s->failed_pc=0x0c087a76u; return 0; }
vf3_matrix_move(s,1,6);
goto P_0c087a78;
P_0c087a78: /* original f1a0, guest PC 0x0c087a78 */
if(!s->budget--) { s->failed_pc=0x0c087a78u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[10],r[18],'+');
goto P_0c087a7a;
P_0c087a7a: /* original f07c, guest PC 0x0c087a7a */
if(!s->budget--) { s->failed_pc=0x0c087a7au; return 0; }
vf3_matrix_move(s,0,7);
goto P_0c087a7c;
P_0c087a7c: /* original f0b0, guest PC 0x0c087a7c */
if(!s->budget--) { s->failed_pc=0x0c087a7cu; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[11],r[18],'+');
goto P_0c087a7e;
P_0c087a7e: /* original f31c, guest PC 0x0c087a7e */
if(!s->budget--) { s->failed_pc=0x0c087a7eu; return 0; }
vf3_matrix_move(s,3,1);
goto P_0c087a80;
P_0c087a80: /* original f14c, guest PC 0x0c087a80 */
if(!s->budget--) { s->failed_pc=0x0c087a80u; return 0; }
vf3_matrix_move(s,1,4);
goto P_0c087a82;
P_0c087a82: /* original f131, guest PC 0x0c087a82 */
if(!s->budget--) { s->failed_pc=0x0c087a82u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[3],r[18],'-');
goto P_0c087a84;
P_0c087a84: /* original f30c, guest PC 0x0c087a84 */
if(!s->budget--) { s->failed_pc=0x0c087a84u; return 0; }
vf3_matrix_move(s,3,0);
goto P_0c087a86;
P_0c087a86: /* original f05c, guest PC 0x0c087a86 */
if(!s->budget--) { s->failed_pc=0x0c087a86u; return 0; }
vf3_matrix_move(s,0,5);
goto P_0c087a88;
P_0c087a88: /* original f031, guest PC 0x0c087a88 */
if(!s->budget--) { s->failed_pc=0x0c087a88u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'-');
goto P_0c087a8a;
P_0c087a8a: /* original f36c, guest PC 0x0c087a8a */
if(!s->budget--) { s->failed_pc=0x0c087a8au; return 0; }
vf3_matrix_move(s,3,6);
goto P_0c087a8c;
P_0c087a8c: /* original f6ac, guest PC 0x0c087a8c */
if(!s->budget--) { s->failed_pc=0x0c087a8cu; return 0; }
vf3_matrix_move(s,6,10);
goto P_0c087a8e;
P_0c087a8e: /* original f631, guest PC 0x0c087a8e */
if(!s->budget--) { s->failed_pc=0x0c087a8eu; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[3],r[18],'-');
goto P_0c087a90;
P_0c087a90: /* original f37c, guest PC 0x0c087a90 */
if(!s->budget--) { s->failed_pc=0x0c087a90u; return 0; }
vf3_matrix_move(s,3,7);
goto P_0c087a92;
P_0c087a92: /* original f7bc, guest PC 0x0c087a92 */
if(!s->budget--) { s->failed_pc=0x0c087a92u; return 0; }
vf3_matrix_move(s,7,11);
goto P_0c087a94;
P_0c087a94: /* original f731, guest PC 0x0c087a94 */
if(!s->budget--) { s->failed_pc=0x0c087a94u; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[3],r[18],'-');
goto P_0c087a96;
P_0c087a96: /* original f36c, guest PC 0x0c087a96 */
if(!s->budget--) { s->failed_pc=0x0c087a96u; return 0; }
vf3_matrix_move(s,3,6);
goto P_0c087a98;
P_0c087a98: /* original f64c, guest PC 0x0c087a98 */
if(!s->budget--) { s->failed_pc=0x0c087a98u; return 0; }
vf3_matrix_move(s,6,4);
goto P_0c087a9a;
P_0c087a9a: /* original f631, guest PC 0x0c087a9a */
if(!s->budget--) { s->failed_pc=0x0c087a9au; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[3],r[18],'-');
goto P_0c087a9c;
P_0c087a9c: /* original f815, guest PC 0x0c087a9c */
if(!s->budget--) { s->failed_pc=0x0c087a9cu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[8])>as_float(fr[1]))!=0);
goto P_0c087a9e;
P_0c087a9e: /* original f37c, guest PC 0x0c087a9e */
if(!s->budget--) { s->failed_pc=0x0c087a9eu; return 0; }
vf3_matrix_move(s,3,7);
goto P_0c087aa0;
P_0c087aa0: /* original f75c, guest PC 0x0c087aa0 */
if(!s->budget--) { s->failed_pc=0x0c087aa0u; return 0; }
vf3_matrix_move(s,7,5);
goto P_0c087aa2;
P_0c087aa2: /* original 8f0c, guest PC 0x0c087aa2 */
if(!s->budget--) { s->failed_pc=0x0c087aa2u; return 0; }
cond=r[17]&1u;
fr[7]=vf3_fpu_binary(fr[7],fr[3],r[18],'-');
if(!cond) { goto P_0c087abe; }
goto P_0c087aa6;
P_0c087aa4: /* original f731, guest PC 0x0c087aa4 */
if(!s->budget--) { s->failed_pc=0x0c087aa4u; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[3],r[18],'-');
goto P_0c087aa6;
P_0c087aa6: /* original f805, guest PC 0x0c087aa6 */
if(!s->budget--) { s->failed_pc=0x0c087aa6u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[8])>as_float(fr[0]))!=0);
goto P_0c087aa8;
P_0c087aa8: /* original 8b09, guest PC 0x0c087aa8 */
if(!s->budget--) { s->failed_pc=0x0c087aa8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c087abe; }
goto P_0c087aaa;
P_0c087aaa: /* original c730, guest PC 0x0c087aaa */
if(!s->budget--) { s->failed_pc=0x0c087aaau; return 0; }
r[0]=code_base|0x00087b6cu;
goto P_0c087aac;
P_0c087aac: /* original f308, guest PC 0x0c087aac */
if(!s->budget--) { s->failed_pc=0x0c087aacu; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c087aae;
P_0c087aae: /* original f635, guest PC 0x0c087aae */
if(!s->budget--) { s->failed_pc=0x0c087aaeu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[6])>as_float(fr[3]))!=0);
goto P_0c087ab0;
P_0c087ab0: /* original 8b05, guest PC 0x0c087ab0 */
if(!s->budget--) { s->failed_pc=0x0c087ab0u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c087abe; }
goto P_0c087ab2;
P_0c087ab2: /* original c72e, guest PC 0x0c087ab2 */
if(!s->budget--) { s->failed_pc=0x0c087ab2u; return 0; }
r[0]=code_base|0x00087b6cu;
goto P_0c087ab4;
P_0c087ab4: /* original f308, guest PC 0x0c087ab4 */
if(!s->budget--) { s->failed_pc=0x0c087ab4u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c087ab6;
P_0c087ab6: /* original f735, guest PC 0x0c087ab6 */
if(!s->budget--) { s->failed_pc=0x0c087ab6u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[7])>as_float(fr[3]))!=0);
goto P_0c087ab8;
P_0c087ab8: /* original 8b01, guest PC 0x0c087ab8 */
if(!s->budget--) { s->failed_pc=0x0c087ab8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c087abe; }
goto P_0c087aba;
P_0c087aba: /* original 000b, guest PC 0x0c087aba */
if(!s->budget--) { s->failed_pc=0x0c087abau; return 0; }
target=r[16];
r[0]=r[4];
s->pc=target; return ram->oob==0;
P_0c087abc: /* original 6043, guest PC 0x0c087abc */
if(!s->budget--) { s->failed_pc=0x0c087abcu; return 0; }
r[0]=r[4];
goto P_0c087abe;
P_0c087abe: /* original 7501, guest PC 0x0c087abe */
if(!s->budget--) { s->failed_pc=0x0c087abeu; return 0; }
r[5]+=0x00000001u;
goto P_0c087ac0;
P_0c087ac0: /* original 924c, guest PC 0x0c087ac0 */
if(!s->budget--) { s->failed_pc=0x0c087ac0u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c087b5cu,2);
goto P_0c087ac2;
P_0c087ac2: /* original 3563, guest PC 0x0c087ac2 */
if(!s->budget--) { s->failed_pc=0x0c087ac2u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[5]>=(int32_t)r[6])!=0);
goto P_0c087ac4;
P_0c087ac4: /* original 8fca, guest PC 0x0c087ac4 */
if(!s->budget--) { s->failed_pc=0x0c087ac4u; return 0; }
cond=r[17]&1u;
r[4]+=r[2];
if(!cond) { goto P_0c087a5c; }
goto P_0c087ac8;
P_0c087ac6: /* original 342c, guest PC 0x0c087ac6 */
if(!s->budget--) { s->failed_pc=0x0c087ac6u; return 0; }
r[4]+=r[2];
goto P_0c087ac8;
P_0c087ac8: /* original e000, guest PC 0x0c087ac8 */
if(!s->budget--) { s->failed_pc=0x0c087ac8u; return 0; }
r[0]=0x00000000u;
goto P_0c087aca;
P_0c087aca: /* original 000b, guest PC 0x0c087aca */
if(!s->budget--) { s->failed_pc=0x0c087acau; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c087acc: /* original 0009, guest PC 0x0c087acc */
if(!s->budget--) { s->failed_pc=0x0c087accu; return 0; }
if(!vf3_matrix_family(0x0c087aceu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c087aceu; return 0; } return 1;
P_0c087b80: /* original c718, guest PC 0x0c087b80 */
if(!s->budget--) { s->failed_pc=0x0c087b80u; return 0; }
r[0]=code_base|0x00087be4u;
goto P_0c087b82;
P_0c087b82: /* original d319, guest PC 0x0c087b82 */
if(!s->budget--) { s->failed_pc=0x0c087b82u; return 0; }
r[3]=read(ram,0x0c087be8u,4);
goto P_0c087b84;
P_0c087b84: /* original f608, guest PC 0x0c087b84 */
if(!s->budget--) { s->failed_pc=0x0c087b84u; return 0; }
vf3_matrix_load(s,ram,6,r[0]);
goto P_0c087b86;
P_0c087b86: /* original e048, guest PC 0x0c087b86 */
if(!s->budget--) { s->failed_pc=0x0c087b86u; return 0; }
r[0]=0x00000048u;
goto P_0c087b88;
P_0c087b88: /* original 054e, guest PC 0x0c087b88 */
if(!s->budget--) { s->failed_pc=0x0c087b88u; return 0; }
r[5]=read(ram,r[4]+r[0],4);
goto P_0c087b8a;
P_0c087b8a: /* original 2358, guest PC 0x0c087b8a */
if(!s->budget--) { s->failed_pc=0x0c087b8au; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[5])==0)!=0);
goto P_0c087b8c;
P_0c087b8c: /* original 8d05, guest PC 0x0c087b8c */
if(!s->budget--) { s->failed_pc=0x0c087b8cu; return 0; }
cond=r[17]&1u;
vf3_matrix_move(s,4,6);
if(cond) { goto P_0c087b9a; }
goto P_0c087b90;
P_0c087b8e: /* original f46c, guest PC 0x0c087b8e */
if(!s->budget--) { s->failed_pc=0x0c087b8eu; return 0; }
vf3_matrix_move(s,4,6);
goto P_0c087b90;
P_0c087b90: /* original d116, guest PC 0x0c087b90 */
if(!s->budget--) { s->failed_pc=0x0c087b90u; return 0; }
r[1]=read(ram,0x0c087becu,4);
goto P_0c087b92;
P_0c087b92: /* original 2158, guest PC 0x0c087b92 */
if(!s->budget--) { s->failed_pc=0x0c087b92u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[5])==0)!=0);
goto P_0c087b94;
P_0c087b94: /* original 8b01, guest PC 0x0c087b94 */
if(!s->budget--) { s->failed_pc=0x0c087b94u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c087b9a; }
goto P_0c087b96;
P_0c087b96: /* original c716, guest PC 0x0c087b96 */
if(!s->budget--) { s->failed_pc=0x0c087b96u; return 0; }
r[0]=code_base|0x00087bf0u;
goto P_0c087b98;
P_0c087b98: /* original f408, guest PC 0x0c087b98 */
if(!s->budget--) { s->failed_pc=0x0c087b98u; return 0; }
vf3_matrix_load(s,ram,4,r[0]);
goto P_0c087b9a;
P_0c087b9a: /* original 901e, guest PC 0x0c087b9a */
if(!s->budget--) { s->failed_pc=0x0c087b9au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c087bdau,2);
goto P_0c087b9c;
P_0c087b9c: /* original 064e, guest PC 0x0c087b9c */
if(!s->budget--) { s->failed_pc=0x0c087b9cu; return 0; }
r[6]=read(ram,r[4]+r[0],4);
goto P_0c087b9e;
P_0c087b9e: /* original 7004, guest PC 0x0c087b9e */
if(!s->budget--) { s->failed_pc=0x0c087b9eu; return 0; }
r[0]+=0x00000004u;
goto P_0c087ba0;
P_0c087ba0: /* original 2668, guest PC 0x0c087ba0 */
if(!s->budget--) { s->failed_pc=0x0c087ba0u; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[6])==0)!=0);
goto P_0c087ba2;
P_0c087ba2: /* original 8d09, guest PC 0x0c087ba2 */
if(!s->budget--) { s->failed_pc=0x0c087ba2u; return 0; }
cond=r[17]&1u;
r[5]=read(ram,r[4]+r[0],4);
if(cond) { goto P_0c087bb8; }
goto P_0c087ba6;
P_0c087ba4: /* original 054e, guest PC 0x0c087ba4 */
if(!s->budget--) { s->failed_pc=0x0c087ba4u; return 0; }
r[5]=read(ram,r[4]+r[0],4);
goto P_0c087ba6;
P_0c087ba6: /* original 2558, guest PC 0x0c087ba6 */
if(!s->budget--) { s->failed_pc=0x0c087ba6u; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[5])==0)!=0);
goto P_0c087ba8;
P_0c087ba8: /* original 8b06, guest PC 0x0c087ba8 */
if(!s->budget--) { s->failed_pc=0x0c087ba8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c087bb8; }
goto P_0c087baa;
P_0c087baa: /* original 9017, guest PC 0x0c087baa */
if(!s->budget--) { s->failed_pc=0x0c087baau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c087bdcu,2);
goto P_0c087bac;
P_0c087bac: /* original e303, guest PC 0x0c087bac */
if(!s->budget--) { s->failed_pc=0x0c087bacu; return 0; }
r[3]=0x00000003u;
goto P_0c087bae;
P_0c087bae: /* original f346, guest PC 0x0c087bae */
if(!s->budget--) { s->failed_pc=0x0c087baeu; return 0; }
vf3_matrix_load(s,ram,3,r[4]+r[0]);
goto P_0c087bb0;
P_0c087bb0: /* original 7004, guest PC 0x0c087bb0 */
if(!s->budget--) { s->failed_pc=0x0c087bb0u; return 0; }
r[0]+=0x00000004u;
goto P_0c087bb2;
P_0c087bb2: /* original f437, guest PC 0x0c087bb2 */
if(!s->budget--) { s->failed_pc=0x0c087bb2u; return 0; }
vf3_matrix_store(s,ram,3,r[4]+r[0]);
goto P_0c087bb4;
P_0c087bb4: /* original 7004, guest PC 0x0c087bb4 */
if(!s->budget--) { s->failed_pc=0x0c087bb4u; return 0; }
r[0]+=0x00000004u;
goto P_0c087bb6;
P_0c087bb6: /* original 0436, guest PC 0x0c087bb6 */
if(!s->budget--) { s->failed_pc=0x0c087bb6u; return 0; }
write(ram,r[4]+r[0],r[3],4);
goto P_0c087bb8;
P_0c087bb8: /* original 9011, guest PC 0x0c087bb8 */
if(!s->budget--) { s->failed_pc=0x0c087bb8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c087bdeu,2);
goto P_0c087bba;
P_0c087bba: /* original 054e, guest PC 0x0c087bba */
if(!s->budget--) { s->failed_pc=0x0c087bbau; return 0; }
r[5]=read(ram,r[4]+r[0],4);
goto P_0c087bbc;
P_0c087bbc: /* original 2558, guest PC 0x0c087bbc */
if(!s->budget--) { s->failed_pc=0x0c087bbcu; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[5])==0)!=0);
goto P_0c087bbe;
P_0c087bbe: /* original 890a, guest PC 0x0c087bbe */
if(!s->budget--) { s->failed_pc=0x0c087bbeu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c087bd6; }
goto P_0c087bc0;
P_0c087bc0: /* original 75ff, guest PC 0x0c087bc0 */
if(!s->budget--) { s->failed_pc=0x0c087bc0u; return 0; }
r[5]+=0xffffffffu;
goto P_0c087bc2;
P_0c087bc2: /* original 2558, guest PC 0x0c087bc2 */
if(!s->budget--) { s->failed_pc=0x0c087bc2u; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[5])==0)!=0);
goto P_0c087bc4;
P_0c087bc4: /* original 625c, guest PC 0x0c087bc4 */
if(!s->budget--) { s->failed_pc=0x0c087bc4u; return 0; }
r[2]=r[5]&255u;
goto P_0c087bc6;
P_0c087bc6: /* original 8f06, guest PC 0x0c087bc6 */
if(!s->budget--) { s->failed_pc=0x0c087bc6u; return 0; }
cond=r[17]&1u;
write(ram,r[4]+r[0],r[2],4);
if(!cond) { goto P_0c087bd6; }
goto P_0c087bca;
P_0c087bc8: /* original 0426, guest PC 0x0c087bc8 */
if(!s->budget--) { s->failed_pc=0x0c087bc8u; return 0; }
write(ram,r[4]+r[0],r[2],4);
goto P_0c087bca;
P_0c087bca: /* original 9009, guest PC 0x0c087bca */
if(!s->budget--) { s->failed_pc=0x0c087bcau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c087be0u,2);
goto P_0c087bcc;
P_0c087bcc: /* original f546, guest PC 0x0c087bcc */
if(!s->budget--) { s->failed_pc=0x0c087bccu; return 0; }
vf3_matrix_load(s,ram,5,r[4]+r[0]);
goto P_0c087bce;
P_0c087bce: /* original c709, guest PC 0x0c087bce */
if(!s->budget--) { s->failed_pc=0x0c087bceu; return 0; }
r[0]=code_base|0x00087bf4u;
goto P_0c087bd0;
P_0c087bd0: /* original f008, guest PC 0x0c087bd0 */
if(!s->budget--) { s->failed_pc=0x0c087bd0u; return 0; }
vf3_matrix_load(s,ram,0,r[0]);
goto P_0c087bd2;
P_0c087bd2: /* original f65e, guest PC 0x0c087bd2 */
if(!s->budget--) { s->failed_pc=0x0c087bd2u; return 0; }
fr[6]=vf3_fpu_mac(fr[0],fr[5],fr[6],r[18]);
goto P_0c087bd4;
P_0c087bd4: /* original f46c, guest PC 0x0c087bd4 */
if(!s->budget--) { s->failed_pc=0x0c087bd4u; return 0; }
vf3_matrix_move(s,4,6);
goto P_0c087bd6;
P_0c087bd6: /* original 000b, guest PC 0x0c087bd6 */
if(!s->budget--) { s->failed_pc=0x0c087bd6u; return 0; }
target=r[16];
vf3_matrix_move(s,0,4);
s->pc=target; return ram->oob==0;
P_0c087bd8: /* original f04c, guest PC 0x0c087bd8 */
if(!s->budget--) { s->failed_pc=0x0c087bd8u; return 0; }
vf3_matrix_move(s,0,4);
if(!vf3_matrix_family(0x0c087bdau,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c087bdau; return 0; } return 1;
P_0c087bf8: /* original 2fe6, guest PC 0x0c087bf8 */
if(!s->budget--) { s->failed_pc=0x0c087bf8u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c087bfa;
P_0c087bfa: /* original 2fd6, guest PC 0x0c087bfa */
if(!s->budget--) { s->failed_pc=0x0c087bfau; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c087bfc;
P_0c087bfc: /* original 2fc6, guest PC 0x0c087bfc */
if(!s->budget--) { s->failed_pc=0x0c087bfcu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c087bfe;
P_0c087bfe: /* original 2fb6, guest PC 0x0c087bfe */
if(!s->budget--) { s->failed_pc=0x0c087bfeu; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c087c00;
P_0c087c00: /* original 2fa6, guest PC 0x0c087c00 */
if(!s->budget--) { s->failed_pc=0x0c087c00u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c087c02;
P_0c087c02: /* original fffb, guest PC 0x0c087c02 */
if(!s->budget--) { s->failed_pc=0x0c087c02u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c087c04;
P_0c087c04: /* original ffeb, guest PC 0x0c087c04 */
if(!s->budget--) { s->failed_pc=0x0c087c04u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,14,r[15]);
goto P_0c087c06;
P_0c087c06: /* original ffdb, guest PC 0x0c087c06 */
if(!s->budget--) { s->failed_pc=0x0c087c06u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,13,r[15]);
goto P_0c087c08;
P_0c087c08: /* original ffcb, guest PC 0x0c087c08 */
if(!s->budget--) { s->failed_pc=0x0c087c08u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,12,r[15]);
goto P_0c087c0a;
P_0c087c0a: /* original 905c, guest PC 0x0c087c0a */
if(!s->budget--) { s->failed_pc=0x0c087c0au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c087cc6u,2);
goto P_0c087c0c;
P_0c087c0c: /* original f38d, guest PC 0x0c087c0c */
if(!s->budget--) { s->failed_pc=0x0c087c0cu; return 0; }
fr[3]=0;
goto P_0c087c0e;
P_0c087c0e: /* original 0c4e, guest PC 0x0c087c0e */
if(!s->budget--) { s->failed_pc=0x0c087c0eu; return 0; }
r[12]=read(ram,r[4]+r[0],4);
goto P_0c087c10;
P_0c087c10: /* original 905a, guest PC 0x0c087c10 */
if(!s->budget--) { s->failed_pc=0x0c087c10u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c087cc8u,2);
goto P_0c087c12;
P_0c087c12: /* original 4f22, guest PC 0x0c087c12 */
if(!s->budget--) { s->failed_pc=0x0c087c12u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c087c14;
P_0c087c14: /* original fe46, guest PC 0x0c087c14 */
if(!s->budget--) { s->failed_pc=0x0c087c14u; return 0; }
vf3_matrix_load(s,ram,14,r[4]+r[0]);
goto P_0c087c16;
P_0c087c16: /* original c72d, guest PC 0x0c087c16 */
if(!s->budget--) { s->failed_pc=0x0c087c16u; return 0; }
r[0]=code_base|0x00087cccu;
goto P_0c087c18;
P_0c087c18: /* original f408, guest PC 0x0c087c18 */
if(!s->budget--) { s->failed_pc=0x0c087c18u; return 0; }
vf3_matrix_load(s,ram,4,r[0]);
goto P_0c087c1a;
P_0c087c1a: /* original f5ec, guest PC 0x0c087c1a */
if(!s->budget--) { s->failed_pc=0x0c087c1au; return 0; }
vf3_matrix_move(s,5,14);
goto P_0c087c1c;
P_0c087c1c: /* original 7ffc, guest PC 0x0c087c1c */
if(!s->budget--) { s->failed_pc=0x0c087c1cu; return 0; }
r[15]+=0xfffffffcu;
goto P_0c087c1e;
P_0c087c1e: /* original f541, guest PC 0x0c087c1e */
if(!s->budget--) { s->failed_pc=0x0c087c1eu; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[4],r[18],'-');
goto P_0c087c20;
P_0c087c20: /* original f355, guest PC 0x0c087c20 */
if(!s->budget--) { s->failed_pc=0x0c087c20u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[5]))!=0);
goto P_0c087c22;
P_0c087c22: /* original 8900, guest PC 0x0c087c22 */
if(!s->budget--) { s->failed_pc=0x0c087c22u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c087c26; }
goto P_0c087c24;
P_0c087c24: /* original fe4c, guest PC 0x0c087c24 */
if(!s->budget--) { s->failed_pc=0x0c087c24u; return 0; }
vf3_matrix_move(s,14,4);
goto P_0c087c26;
P_0c087c26: /* original 9050, guest PC 0x0c087c26 */
if(!s->budget--) { s->failed_pc=0x0c087c26u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c087ccau,2);
goto P_0c087c28;
P_0c087c28: /* original 65c3, guest PC 0x0c087c28 */
if(!s->budget--) { s->failed_pc=0x0c087c28u; return 0; }
r[5]=r[12];
goto P_0c087c2a;
P_0c087c2a: /* original dd29, guest PC 0x0c087c2a */
if(!s->budget--) { s->failed_pc=0x0c087c2au; return 0; }
r[13]=read(ram,0x0c087cd0u,4);
goto P_0c087c2c;
P_0c087c2c: /* original e61c, guest PC 0x0c087c2c */
if(!s->budget--) { s->failed_pc=0x0c087c2cu; return 0; }
r[6]=0x0000001cu;
goto P_0c087c2e;
P_0c087c2e: /* original f68d, guest PC 0x0c087c2e */
if(!s->budget--) { s->failed_pc=0x0c087c2eu; return 0; }
fr[6]=0;
goto P_0c087c30;
P_0c087c30: /* original eefe, guest PC 0x0c087c30 */
if(!s->budget--) { s->failed_pc=0x0c087c30u; return 0; }
r[14]=0xfffffffeu;
goto P_0c087c32;
P_0c087c32: /* original 0b4e, guest PC 0x0c087c32 */
if(!s->budget--) { s->failed_pc=0x0c087c32u; return 0; }
r[11]=read(ram,r[4]+r[0],4);
goto P_0c087c34;
P_0c087c34: /* original e700, guest PC 0x0c087c34 */
if(!s->budget--) { s->failed_pc=0x0c087c34u; return 0; }
r[7]=0x00000000u;
goto P_0c087c36;
P_0c087c36: /* original f59d, guest PC 0x0c087c36 */
if(!s->budget--) { s->failed_pc=0x0c087c36u; return 0; }
fr[5]=0x3f800000u;
goto P_0c087c38;
P_0c087c38: /* original fd6c, guest PC 0x0c087c38 */
if(!s->budget--) { s->failed_pc=0x0c087c38u; return 0; }
vf3_matrix_move(s,13,6);
goto P_0c087c3a;
P_0c087c3a: /* original f46c, guest PC 0x0c087c3a */
if(!s->budget--) { s->failed_pc=0x0c087c3au; return 0; }
vf3_matrix_move(s,4,6);
goto P_0c087c3c;
P_0c087c3c: /* original 6353, guest PC 0x0c087c3c */
if(!s->budget--) { s->failed_pc=0x0c087c3cu; return 0; }
r[3]=r[5];
goto P_0c087c3e;
P_0c087c3e: /* original 6a53, guest PC 0x0c087c3e */
if(!s->budget--) { s->failed_pc=0x0c087c3eu; return 0; }
r[10]=r[5];
goto P_0c087c40;
P_0c087c40: /* original 4300, guest PC 0x0c087c40 */
if(!s->budget--) { s->failed_pc=0x0c087c40u; return 0; }
r[17]=(r[17]&~1u)|((r[3]>>31)!=0);
r[3]<<=1;
goto P_0c087c42;
P_0c087c42: /* original 2ad9, guest PC 0x0c087c42 */
if(!s->budget--) { s->failed_pc=0x0c087c42u; return 0; }
r[10]&=r[13];
goto P_0c087c44;
P_0c087c44: /* original 6533, guest PC 0x0c087c44 */
if(!s->budget--) { s->failed_pc=0x0c087c44u; return 0; }
r[5]=r[3];
goto P_0c087c46;
P_0c087c46: /* original 2aa8, guest PC 0x0c087c46 */
if(!s->budget--) { s->failed_pc=0x0c087c46u; return 0; }
r[17]=(r[17]&~1u)|(((r[10]&r[10])==0)!=0);
goto P_0c087c48;
P_0c087c48: /* original 8d02, guest PC 0x0c087c48 */
if(!s->budget--) { s->failed_pc=0x0c087c48u; return 0; }
cond=r[17]&1u;
r[5]&=r[14];
if(cond) { goto P_0c087c50; }
goto P_0c087c4c;
P_0c087c4a: /* original 25e9, guest PC 0x0c087c4a */
if(!s->budget--) { s->failed_pc=0x0c087c4au; return 0; }
r[5]&=r[14];
goto P_0c087c4c;
P_0c087c4c: /* original f450, guest PC 0x0c087c4c */
if(!s->budget--) { s->failed_pc=0x0c087c4cu; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[5],r[18],'+');
goto P_0c087c4e;
P_0c087c4e: /* original 7701, guest PC 0x0c087c4e */
if(!s->budget--) { s->failed_pc=0x0c087c4eu; return 0; }
r[7]+=0x00000001u;
goto P_0c087c50;
P_0c087c50: /* original 4610, guest PC 0x0c087c50 */
if(!s->budget--) { s->failed_pc=0x0c087c50u; return 0; }
--r[6];
r[17]=(r[17]&~1u)|((r[6]==0)!=0);
goto P_0c087c52;
P_0c087c52: /* original 8bf3, guest PC 0x0c087c52 */
if(!s->budget--) { s->failed_pc=0x0c087c52u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c087c3c; }
goto P_0c087c54;
P_0c087c54: /* original 2778, guest PC 0x0c087c54 */
if(!s->budget--) { s->failed_pc=0x0c087c54u; return 0; }
r[17]=(r[17]&~1u)|(((r[7]&r[7])==0)!=0);
goto P_0c087c56;
P_0c087c56: /* original 892a, guest PC 0x0c087c56 */
if(!s->budget--) { s->failed_pc=0x0c087c56u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c087cae; }
goto P_0c087c58;
P_0c087c58: /* original bf92, guest PC 0x0c087c58 */
if(!s->budget--) { s->failed_pc=0x0c087c58u; return 0; }
target=code_base|0x0c087b80u; r[16]=code_base|0x0c087c5cu;
fr[14]=vf3_fpu_binary(fr[14],fr[4],r[18],'/');
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c087c5cu) { target=s->pc; goto dispatch; }
goto P_0c087c5c;
P_0c087c5a: /* original fe43, guest PC 0x0c087c5a */
if(!s->budget--) { s->failed_pc=0x0c087c5au; return 0; }
fr[14]=vf3_fpu_binary(fr[14],fr[4],r[18],'/');
goto P_0c087c5c;
P_0c087c5c: /* original f40c, guest PC 0x0c087c5c */
if(!s->budget--) { s->failed_pc=0x0c087c5cu; return 0; }
vf3_matrix_move(s,4,0);
goto P_0c087c5e;
P_0c087c5e: /* original fe42, guest PC 0x0c087c5e */
if(!s->budget--) { s->failed_pc=0x0c087c5eu; return 0; }
fr[14]=vf3_fpu_binary(fr[14],fr[4],r[18],'*');
goto P_0c087c60;
P_0c087c60: /* original ea1c, guest PC 0x0c087c60 */
if(!s->budget--) { s->failed_pc=0x0c087c60u; return 0; }
r[10]=0x0000001cu;
goto P_0c087c62;
P_0c087c62: /* original 62c3, guest PC 0x0c087c62 */
if(!s->budget--) { s->failed_pc=0x0c087c62u; return 0; }
r[2]=r[12];
goto P_0c087c64;
P_0c087c64: /* original 64c3, guest PC 0x0c087c64 */
if(!s->budget--) { s->failed_pc=0x0c087c64u; return 0; }
r[4]=r[12];
goto P_0c087c66;
P_0c087c66: /* original 4200, guest PC 0x0c087c66 */
if(!s->budget--) { s->failed_pc=0x0c087c66u; return 0; }
r[17]=(r[17]&~1u)|((r[2]>>31)!=0);
r[2]<<=1;
goto P_0c087c68;
P_0c087c68: /* original 24d9, guest PC 0x0c087c68 */
if(!s->budget--) { s->failed_pc=0x0c087c68u; return 0; }
r[4]&=r[13];
goto P_0c087c6a;
P_0c087c6a: /* original 6c23, guest PC 0x0c087c6a */
if(!s->budget--) { s->failed_pc=0x0c087c6au; return 0; }
r[12]=r[2];
goto P_0c087c6c;
P_0c087c6c: /* original 2448, guest PC 0x0c087c6c */
if(!s->budget--) { s->failed_pc=0x0c087c6cu; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c087c6e;
P_0c087c6e: /* original 8d1c, guest PC 0x0c087c6e */
if(!s->budget--) { s->failed_pc=0x0c087c6eu; return 0; }
cond=r[17]&1u;
r[12]&=r[14];
if(cond) { goto P_0c087caa; }
goto P_0c087c72;
P_0c087c70: /* original 2ce9, guest PC 0x0c087c70 */
if(!s->budget--) { s->failed_pc=0x0c087c70u; return 0; }
r[12]&=r[14];
goto P_0c087c72;
P_0c087c72: /* original fcb9, guest PC 0x0c087c72 */
if(!s->budget--) { s->failed_pc=0x0c087c72u; return 0; }
vf3_matrix_load(s,ram,12,r[11]);
r[11]+=(r[18]&0x100000u)?8:4;
goto P_0c087c74;
P_0c087c74: /* original c717, guest PC 0x0c087c74 */
if(!s->budget--) { s->failed_pc=0x0c087c74u; return 0; }
r[0]=code_base|0x00087cd4u;
goto P_0c087c76;
P_0c087c76: /* original f3b9, guest PC 0x0c087c76 */
if(!s->budget--) { s->failed_pc=0x0c087c76u; return 0; }
vf3_matrix_load(s,ram,3,r[11]);
r[11]+=(r[18]&0x100000u)?8:4;
goto P_0c087c78;
P_0c087c78: /* original ff3a, guest PC 0x0c087c78 */
if(!s->budget--) { s->failed_pc=0x0c087c78u; return 0; }
vf3_matrix_store(s,ram,3,r[15]);
goto P_0c087c7a;
P_0c087c7a: /* original f308, guest PC 0x0c087c7a */
if(!s->budget--) { s->failed_pc=0x0c087c7au; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c087c7c;
P_0c087c7c: /* original ffb9, guest PC 0x0c087c7c */
if(!s->budget--) { s->failed_pc=0x0c087c7cu; return 0; }
vf3_matrix_load(s,ram,15,r[11]);
r[11]+=(r[18]&0x100000u)?8:4;
goto P_0c087c7e;
P_0c087c7e: /* original ff32, guest PC 0x0c087c7e */
if(!s->budget--) { s->failed_pc=0x0c087c7eu; return 0; }
fr[15]=vf3_fpu_binary(fr[15],fr[3],r[18],'*');
goto P_0c087c80;
P_0c087c80: /* original f5fc, guest PC 0x0c087c80 */
if(!s->budget--) { s->failed_pc=0x0c087c80u; return 0; }
vf3_matrix_move(s,5,15);
goto P_0c087c82;
P_0c087c82: /* original bedd, guest PC 0x0c087c82 */
if(!s->budget--) { s->failed_pc=0x0c087c82u; return 0; }
target=code_base|0x0c087a40u; r[16]=code_base|0x0c087c86u;
vf3_matrix_move(s,4,12);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c087c86u) { target=s->pc; goto dispatch; }
goto P_0c087c86;
P_0c087c84: /* original f4cc, guest PC 0x0c087c84 */
if(!s->budget--) { s->failed_pc=0x0c087c84u; return 0; }
vf3_matrix_move(s,4,12);
goto P_0c087c86;
P_0c087c86: /* original 6403, guest PC 0x0c087c86 */
if(!s->budget--) { s->failed_pc=0x0c087c86u; return 0; }
r[4]=r[0];
goto P_0c087c88;
P_0c087c88: /* original 2448, guest PC 0x0c087c88 */
if(!s->budget--) { s->failed_pc=0x0c087c88u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c087c8a;
P_0c087c8a: /* original 890e, guest PC 0x0c087c8a */
if(!s->budget--) { s->failed_pc=0x0c087c8au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c087caa; }
goto P_0c087c8c;
P_0c087c8c: /* original c712, guest PC 0x0c087c8c */
if(!s->budget--) { s->failed_pc=0x0c087c8cu; return 0; }
r[0]=code_base|0x00087cd8u;
goto P_0c087c8e;
P_0c087c8e: /* original f1fc, guest PC 0x0c087c8e */
if(!s->budget--) { s->failed_pc=0x0c087c8eu; return 0; }
vf3_matrix_move(s,1,15);
goto P_0c087c90;
P_0c087c90: /* original f308, guest PC 0x0c087c90 */
if(!s->budget--) { s->failed_pc=0x0c087c90u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c087c92;
P_0c087c92: /* original e038, guest PC 0x0c087c92 */
if(!s->budget--) { s->failed_pc=0x0c087c92u; return 0; }
r[0]=0x00000038u;
goto P_0c087c94;
P_0c087c94: /* original f246, guest PC 0x0c087c94 */
if(!s->budget--) { s->failed_pc=0x0c087c94u; return 0; }
vf3_matrix_load(s,ram,2,r[4]+r[0]);
goto P_0c087c96;
P_0c087c96: /* original f5f8, guest PC 0x0c087c96 */
if(!s->budget--) { s->failed_pc=0x0c087c96u; return 0; }
vf3_matrix_load(s,ram,5,r[15]);
goto P_0c087c98;
P_0c087c98: /* original f232, guest PC 0x0c087c98 */
if(!s->budget--) { s->failed_pc=0x0c087c98u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c087c9a;
P_0c087c9a: /* original f7dc, guest PC 0x0c087c9a */
if(!s->budget--) { s->failed_pc=0x0c087c9au; return 0; }
vf3_matrix_move(s,7,13);
goto P_0c087c9c;
P_0c087c9c: /* original f9dc, guest PC 0x0c087c9c */
if(!s->budget--) { s->failed_pc=0x0c087c9cu; return 0; }
vf3_matrix_move(s,9,13);
goto P_0c087c9e;
P_0c087c9e: /* original f8ec, guest PC 0x0c087c9e */
if(!s->budget--) { s->failed_pc=0x0c087c9eu; return 0; }
vf3_matrix_move(s,8,14);
goto P_0c087ca0;
P_0c087ca0: /* original ff2c, guest PC 0x0c087ca0 */
if(!s->budget--) { s->failed_pc=0x0c087ca0u; return 0; }
vf3_matrix_move(s,15,2);
goto P_0c087ca2;
P_0c087ca2: /* original ff11, guest PC 0x0c087ca2 */
if(!s->budget--) { s->failed_pc=0x0c087ca2u; return 0; }
fr[15]=vf3_fpu_binary(fr[15],fr[1],r[18],'-');
goto P_0c087ca4;
P_0c087ca4: /* original f6fc, guest PC 0x0c087ca4 */
if(!s->budget--) { s->failed_pc=0x0c087ca4u; return 0; }
vf3_matrix_move(s,6,15);
goto P_0c087ca6;
P_0c087ca6: /* original be1f, guest PC 0x0c087ca6 */
if(!s->budget--) { s->failed_pc=0x0c087ca6u; return 0; }
target=code_base|0x0c0878e8u; r[16]=code_base|0x0c087caau;
vf3_matrix_move(s,4,12);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c087caau) { target=s->pc; goto dispatch; }
goto P_0c087caa;
P_0c087ca8: /* original f4cc, guest PC 0x0c087ca8 */
if(!s->budget--) { s->failed_pc=0x0c087ca8u; return 0; }
vf3_matrix_move(s,4,12);
goto P_0c087caa;
P_0c087caa: /* original 4a10, guest PC 0x0c087caa */
if(!s->budget--) { s->failed_pc=0x0c087caau; return 0; }
--r[10];
r[17]=(r[17]&~1u)|((r[10]==0)!=0);
goto P_0c087cac;
P_0c087cac: /* original 8bd9, guest PC 0x0c087cac */
if(!s->budget--) { s->failed_pc=0x0c087cacu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c087c62; }
goto P_0c087cae;
P_0c087cae: /* original 7f04, guest PC 0x0c087cae */
if(!s->budget--) { s->failed_pc=0x0c087caeu; return 0; }
r[15]+=0x00000004u;
goto P_0c087cb0;
P_0c087cb0: /* original 4f26, guest PC 0x0c087cb0 */
if(!s->budget--) { s->failed_pc=0x0c087cb0u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c087cb2;
P_0c087cb2: /* original fcf9, guest PC 0x0c087cb2 */
if(!s->budget--) { s->failed_pc=0x0c087cb2u; return 0; }
vf3_matrix_load(s,ram,12,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c087cb4;
P_0c087cb4: /* original fdf9, guest PC 0x0c087cb4 */
if(!s->budget--) { s->failed_pc=0x0c087cb4u; return 0; }
vf3_matrix_load(s,ram,13,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c087cb6;
P_0c087cb6: /* original fef9, guest PC 0x0c087cb6 */
if(!s->budget--) { s->failed_pc=0x0c087cb6u; return 0; }
vf3_matrix_load(s,ram,14,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c087cb8;
P_0c087cb8: /* original fff9, guest PC 0x0c087cb8 */
if(!s->budget--) { s->failed_pc=0x0c087cb8u; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c087cba;
P_0c087cba: /* original 6af6, guest PC 0x0c087cba */
if(!s->budget--) { s->failed_pc=0x0c087cbau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c087cbc;
P_0c087cbc: /* original 6bf6, guest PC 0x0c087cbc */
if(!s->budget--) { s->failed_pc=0x0c087cbcu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c087cbe;
P_0c087cbe: /* original 6cf6, guest PC 0x0c087cbe */
if(!s->budget--) { s->failed_pc=0x0c087cbeu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c087cc0;
P_0c087cc0: /* original 6df6, guest PC 0x0c087cc0 */
if(!s->budget--) { s->failed_pc=0x0c087cc0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c087cc2;
P_0c087cc2: /* original 000b, guest PC 0x0c087cc2 */
if(!s->budget--) { s->failed_pc=0x0c087cc2u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c087cc4: /* original 6ef6, guest PC 0x0c087cc4 */
if(!s->budget--) { s->failed_pc=0x0c087cc4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c087cc6u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c087cc6u; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
