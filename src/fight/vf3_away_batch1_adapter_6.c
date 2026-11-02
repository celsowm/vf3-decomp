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
int vf3_away_batch1_adapter_6(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c036b92u: goto P_0c036b92;
case 0x0c036b94u: goto P_0c036b94;
case 0x0c036b96u: goto P_0c036b96;
case 0x0c036b98u: goto P_0c036b98;
case 0x0c036b9au: goto P_0c036b9a;
case 0x0c036b9cu: goto P_0c036b9c;
case 0x0c036b9eu: goto P_0c036b9e;
case 0x0c036ba0u: goto P_0c036ba0;
case 0x0c036ba2u: goto P_0c036ba2;
case 0x0c036ba4u: goto P_0c036ba4;
case 0x0c036ba6u: goto P_0c036ba6;
case 0x0c036ba8u: goto P_0c036ba8;
case 0x0c036baau: goto P_0c036baa;
case 0x0c036bacu: goto P_0c036bac;
case 0x0c036baeu: goto P_0c036bae;
case 0x0c036bb0u: goto P_0c036bb0;
case 0x0c036bb2u: goto P_0c036bb2;
case 0x0c036bb4u: goto P_0c036bb4;
case 0x0c036bb6u: goto P_0c036bb6;
case 0x0c036bb8u: goto P_0c036bb8;
case 0x0c036bbau: goto P_0c036bba;
case 0x0c036bbcu: goto P_0c036bbc;
case 0x0c036bbeu: goto P_0c036bbe;
case 0x0c036bc0u: goto P_0c036bc0;
case 0x0c036bc2u: goto P_0c036bc2;
case 0x0c036bc4u: goto P_0c036bc4;
case 0x0c036bc6u: goto P_0c036bc6;
case 0x0c036bc8u: goto P_0c036bc8;
case 0x0c036bcau: goto P_0c036bca;
case 0x0c036bccu: goto P_0c036bcc;
case 0x0c036bceu: goto P_0c036bce;
case 0x0c036bd0u: goto P_0c036bd0;
case 0x0c036bd2u: goto P_0c036bd2;
case 0x0c036bd4u: goto P_0c036bd4;
case 0x0c036bd6u: goto P_0c036bd6;
case 0x0c036bd8u: goto P_0c036bd8;
case 0x0c036bdau: goto P_0c036bda;
case 0x0c036bdcu: goto P_0c036bdc;
case 0x0c036bdeu: goto P_0c036bde;
case 0x0c036be0u: goto P_0c036be0;
case 0x0c036be2u: goto P_0c036be2;
case 0x0c036be4u: goto P_0c036be4;
case 0x0c036be6u: goto P_0c036be6;
case 0x0c036be8u: goto P_0c036be8;
case 0x0c036beau: goto P_0c036bea;
case 0x0c036c14u: goto P_0c036c14;
case 0x0c036c16u: goto P_0c036c16;
case 0x0c036c18u: goto P_0c036c18;
case 0x0c036c1au: goto P_0c036c1a;
case 0x0c036c1cu: goto P_0c036c1c;
case 0x0c036c1eu: goto P_0c036c1e;
case 0x0c036c20u: goto P_0c036c20;
case 0x0c036c22u: goto P_0c036c22;
case 0x0c036c24u: goto P_0c036c24;
case 0x0c036c26u: goto P_0c036c26;
case 0x0c036c28u: goto P_0c036c28;
case 0x0c036c2au: goto P_0c036c2a;
case 0x0c036c2cu: goto P_0c036c2c;
case 0x0c036c2eu: goto P_0c036c2e;
case 0x0c036c30u: goto P_0c036c30;
case 0x0c036c32u: goto P_0c036c32;
case 0x0c036c34u: goto P_0c036c34;
case 0x0c036c36u: goto P_0c036c36;
case 0x0c036c38u: goto P_0c036c38;
case 0x0c036c3au: goto P_0c036c3a;
case 0x0c036c3cu: goto P_0c036c3c;
case 0x0c036c3eu: goto P_0c036c3e;
case 0x0c036c40u: goto P_0c036c40;
case 0x0c036c42u: goto P_0c036c42;
case 0x0c036c44u: goto P_0c036c44;
case 0x0c036c46u: goto P_0c036c46;
case 0x0c036c48u: goto P_0c036c48;
case 0x0c036c4au: goto P_0c036c4a;
case 0x0c036c4cu: goto P_0c036c4c;
case 0x0c036c4eu: goto P_0c036c4e;
case 0x0c036c50u: goto P_0c036c50;
case 0x0c036c52u: goto P_0c036c52;
case 0x0c036c54u: goto P_0c036c54;
case 0x0c036c56u: goto P_0c036c56;
case 0x0c036c58u: goto P_0c036c58;
case 0x0c036c5au: goto P_0c036c5a;
case 0x0c036c5cu: goto P_0c036c5c;
case 0x0c036c5eu: goto P_0c036c5e;
case 0x0c036c60u: goto P_0c036c60;
case 0x0c036c62u: goto P_0c036c62;
case 0x0c036c64u: goto P_0c036c64;
case 0x0c036c66u: goto P_0c036c66;
case 0x0c036c68u: goto P_0c036c68;
case 0x0c036c6au: goto P_0c036c6a;
case 0x0c036c6cu: goto P_0c036c6c;
case 0x0c036c6eu: goto P_0c036c6e;
case 0x0c036c70u: goto P_0c036c70;
case 0x0c036c72u: goto P_0c036c72;
case 0x0c036c74u: goto P_0c036c74;
case 0x0c036c76u: goto P_0c036c76;
case 0x0c036c78u: goto P_0c036c78;
case 0x0c036c7au: goto P_0c036c7a;
case 0x0c036c7cu: goto P_0c036c7c;
case 0x0c036c7eu: goto P_0c036c7e;
case 0x0c036c80u: goto P_0c036c80;
case 0x0c036c82u: goto P_0c036c82;
case 0x0c036c84u: goto P_0c036c84;
case 0x0c036c86u: goto P_0c036c86;
case 0x0c036c88u: goto P_0c036c88;
case 0x0c036c8au: goto P_0c036c8a;
case 0x0c036c8cu: goto P_0c036c8c;
case 0x0c036c8eu: goto P_0c036c8e;
case 0x0c036c90u: goto P_0c036c90;
case 0x0c036c92u: goto P_0c036c92;
case 0x0c036c94u: goto P_0c036c94;
case 0x0c036c96u: goto P_0c036c96;
case 0x0c036c98u: goto P_0c036c98;
case 0x0c036c9au: goto P_0c036c9a;
case 0x0c036c9cu: goto P_0c036c9c;
case 0x0c036c9eu: goto P_0c036c9e;
case 0x0c036ca0u: goto P_0c036ca0;
case 0x0c036ca2u: goto P_0c036ca2;
case 0x0c036ca4u: goto P_0c036ca4;
case 0x0c036ca6u: goto P_0c036ca6;
case 0x0c036ca8u: goto P_0c036ca8;
case 0x0c036caau: goto P_0c036caa;
case 0x0c036cacu: goto P_0c036cac;
case 0x0c036caeu: goto P_0c036cae;
case 0x0c036cb0u: goto P_0c036cb0;
case 0x0c036cb2u: goto P_0c036cb2;
case 0x0c036cb4u: goto P_0c036cb4;
case 0x0c036cb6u: goto P_0c036cb6;
case 0x0c036cb8u: goto P_0c036cb8;
case 0x0c036cbau: goto P_0c036cba;
case 0x0c036cbcu: goto P_0c036cbc;
case 0x0c036cbeu: goto P_0c036cbe;
case 0x0c036cc0u: goto P_0c036cc0;
case 0x0c036cc2u: goto P_0c036cc2;
case 0x0c036cc4u: goto P_0c036cc4;
case 0x0c036cc6u: goto P_0c036cc6;
case 0x0c036cc8u: goto P_0c036cc8;
case 0x0c036ccau: goto P_0c036cca;
case 0x0c036cccu: goto P_0c036ccc;
case 0x0c036cceu: goto P_0c036cce;
case 0x0c036cd0u: goto P_0c036cd0;
case 0x0c036cd2u: goto P_0c036cd2;
case 0x0c036cd4u: goto P_0c036cd4;
case 0x0c036cd6u: goto P_0c036cd6;
case 0x0c036cd8u: goto P_0c036cd8;
case 0x0c036cdau: goto P_0c036cda;
case 0x0c036cdcu: goto P_0c036cdc;
case 0x0c036cdeu: goto P_0c036cde;
case 0x0c036ce0u: goto P_0c036ce0;
case 0x0c036ce2u: goto P_0c036ce2;
case 0x0c036ce4u: goto P_0c036ce4;
case 0x0c036ce6u: goto P_0c036ce6;
case 0x0c036ce8u: goto P_0c036ce8;
case 0x0c036ceau: goto P_0c036cea;
case 0x0c036cecu: goto P_0c036cec;
case 0x0c036ceeu: goto P_0c036cee;
case 0x0c036cf0u: goto P_0c036cf0;
case 0x0c036cf2u: goto P_0c036cf2;
case 0x0c036cf4u: goto P_0c036cf4;
case 0x0c036cf6u: goto P_0c036cf6;
case 0x0c036cf8u: goto P_0c036cf8;
case 0x0c036cfau: goto P_0c036cfa;
case 0x0c036cfcu: goto P_0c036cfc;
case 0x0c036cfeu: goto P_0c036cfe;
case 0x0c036d2cu: goto P_0c036d2c;
case 0x0c036d2eu: goto P_0c036d2e;
case 0x0c036d30u: goto P_0c036d30;
case 0x0c036d32u: goto P_0c036d32;
case 0x0c036d34u: goto P_0c036d34;
case 0x0c036d36u: goto P_0c036d36;
case 0x0c036d38u: goto P_0c036d38;
case 0x0c036d3au: goto P_0c036d3a;
case 0x0c036d3cu: goto P_0c036d3c;
case 0x0c036d3eu: goto P_0c036d3e;
case 0x0c036d40u: goto P_0c036d40;
case 0x0c036d42u: goto P_0c036d42;
case 0x0c036d44u: goto P_0c036d44;
case 0x0c036d46u: goto P_0c036d46;
case 0x0c036d48u: goto P_0c036d48;
case 0x0c036d4au: goto P_0c036d4a;
case 0x0c036d4cu: goto P_0c036d4c;
case 0x0c036d4eu: goto P_0c036d4e;
case 0x0c036d50u: goto P_0c036d50;
case 0x0c036d52u: goto P_0c036d52;
case 0x0c036d54u: goto P_0c036d54;
case 0x0c036d56u: goto P_0c036d56;
case 0x0c036d58u: goto P_0c036d58;
case 0x0c036d5au: goto P_0c036d5a;
case 0x0c036d5cu: goto P_0c036d5c;
case 0x0c036d5eu: goto P_0c036d5e;
case 0x0c036d60u: goto P_0c036d60;
case 0x0c036d62u: goto P_0c036d62;
case 0x0c036d64u: goto P_0c036d64;
case 0x0c036d66u: goto P_0c036d66;
case 0x0c036d68u: goto P_0c036d68;
case 0x0c036d6au: goto P_0c036d6a;
case 0x0c036d6cu: goto P_0c036d6c;
case 0x0c036d6eu: goto P_0c036d6e;
case 0x0c036d70u: goto P_0c036d70;
case 0x0c036d72u: goto P_0c036d72;
case 0x0c036d74u: goto P_0c036d74;
case 0x0c036d76u: goto P_0c036d76;
case 0x0c036d78u: goto P_0c036d78;
case 0x0c036d7au: goto P_0c036d7a;
case 0x0c036d7cu: goto P_0c036d7c;
case 0x0c036d7eu: goto P_0c036d7e;
case 0x0c036d80u: goto P_0c036d80;
case 0x0c036d82u: goto P_0c036d82;
case 0x0c036d84u: goto P_0c036d84;
case 0x0c036d86u: goto P_0c036d86;
case 0x0c036d88u: goto P_0c036d88;
case 0x0c036d8au: goto P_0c036d8a;
case 0x0c036d8cu: goto P_0c036d8c;
case 0x0c036d8eu: goto P_0c036d8e;
case 0x0c036d90u: goto P_0c036d90;
case 0x0c036d92u: goto P_0c036d92;
case 0x0c036d94u: goto P_0c036d94;
case 0x0c036d96u: goto P_0c036d96;
case 0x0c036d98u: goto P_0c036d98;
case 0x0c036d9au: goto P_0c036d9a;
case 0x0c036d9cu: goto P_0c036d9c;
case 0x0c036d9eu: goto P_0c036d9e;
case 0x0c036da0u: goto P_0c036da0;
case 0x0c036da2u: goto P_0c036da2;
case 0x0c036da4u: goto P_0c036da4;
case 0x0c036da6u: goto P_0c036da6;
case 0x0c036da8u: goto P_0c036da8;
case 0x0c036daau: goto P_0c036daa;
case 0x0c036dacu: goto P_0c036dac;
case 0x0c036daeu: goto P_0c036dae;
case 0x0c036db0u: goto P_0c036db0;
case 0x0c036db2u: goto P_0c036db2;
case 0x0c036db4u: goto P_0c036db4;
case 0x0c036db6u: goto P_0c036db6;
default: return vf3_matrix_family(target,s,ram);
}
P_0c036b92: /* original d217, guest PC 0x0c036b92 */
if(!s->budget--) { s->failed_pc=0x0c036b92u; return 0; }
r[2]=read(ram,0x0c036bf0u,4);
goto P_0c036b94;
P_0c036b94: /* original 6543, guest PC 0x0c036b94 */
if(!s->budget--) { s->failed_pc=0x0c036b94u; return 0; }
r[5]=r[4];
goto P_0c036b96;
P_0c036b96: /* original d31b, guest PC 0x0c036b96 */
if(!s->budget--) { s->failed_pc=0x0c036b96u; return 0; }
r[3]=read(ram,0x0c036c04u,4);
goto P_0c036b98;
P_0c036b98: /* original 4519, guest PC 0x0c036b98 */
if(!s->budget--) { s->failed_pc=0x0c036b98u; return 0; }
r[5]>>=8;
goto P_0c036b9a;
P_0c036b9a: /* original 2248, guest PC 0x0c036b9a */
if(!s->budget--) { s->failed_pc=0x0c036b9au; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[4])==0)!=0);
goto P_0c036b9c;
P_0c036b9c: /* original 4509, guest PC 0x0c036b9c */
if(!s->budget--) { s->failed_pc=0x0c036b9cu; return 0; }
r[5]>>=2;
goto P_0c036b9e;
P_0c036b9e: /* original 8d02, guest PC 0x0c036b9e */
if(!s->budget--) { s->failed_pc=0x0c036b9eu; return 0; }
cond=r[17]&1u;
r[5]&=r[3];
if(cond) { goto P_0c036ba6; }
goto P_0c036ba2;
P_0c036ba0: /* original 2539, guest PC 0x0c036ba0 */
if(!s->budget--) { s->failed_pc=0x0c036ba0u; return 0; }
r[5]&=r[3];
goto P_0c036ba2;
P_0c036ba2: /* original 9023, guest PC 0x0c036ba2 */
if(!s->budget--) { s->failed_pc=0x0c036ba2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c036becu,2);
goto P_0c036ba4;
P_0c036ba4: /* original 250b, guest PC 0x0c036ba4 */
if(!s->budget--) { s->failed_pc=0x0c036ba4u; return 0; }
r[5]|=r[0];
goto P_0c036ba6;
P_0c036ba6: /* original d318, guest PC 0x0c036ba6 */
if(!s->budget--) { s->failed_pc=0x0c036ba6u; return 0; }
r[3]=read(ram,0x0c036c08u,4);
goto P_0c036ba8;
P_0c036ba8: /* original 2438, guest PC 0x0c036ba8 */
if(!s->budget--) { s->failed_pc=0x0c036ba8u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[3])==0)!=0);
goto P_0c036baa;
P_0c036baa: /* original 8901, guest PC 0x0c036baa */
if(!s->budget--) { s->failed_pc=0x0c036baau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c036bb0; }
goto P_0c036bac;
P_0c036bac: /* original e10f, guest PC 0x0c036bac */
if(!s->budget--) { s->failed_pc=0x0c036bacu; return 0; }
r[1]=0x0000000fu;
goto P_0c036bae;
P_0c036bae: /* original 251b, guest PC 0x0c036bae */
if(!s->budget--) { s->failed_pc=0x0c036baeu; return 0; }
r[5]|=r[1];
goto P_0c036bb0;
P_0c036bb0: /* original 000b, guest PC 0x0c036bb0 */
if(!s->budget--) { s->failed_pc=0x0c036bb0u; return 0; }
target=r[16];
r[0]=r[5];
s->pc=target; return ram->oob==0;
P_0c036bb2: /* original 6053, guest PC 0x0c036bb2 */
if(!s->budget--) { s->failed_pc=0x0c036bb2u; return 0; }
r[0]=r[5];
goto P_0c036bb4;
P_0c036bb4: /* original 2fe6, guest PC 0x0c036bb4 */
if(!s->budget--) { s->failed_pc=0x0c036bb4u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c036bb6;
P_0c036bb6: /* original 2fd6, guest PC 0x0c036bb6 */
if(!s->budget--) { s->failed_pc=0x0c036bb6u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c036bb8;
P_0c036bb8: /* original 6d53, guest PC 0x0c036bb8 */
if(!s->budget--) { s->failed_pc=0x0c036bb8u; return 0; }
r[13]=r[5];
goto P_0c036bba;
P_0c036bba: /* original 4f22, guest PC 0x0c036bba */
if(!s->budget--) { s->failed_pc=0x0c036bbau; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c036bbc;
P_0c036bbc: /* original 60d2, guest PC 0x0c036bbc */
if(!s->budget--) { s->failed_pc=0x0c036bbcu; return 0; }
tmp=read(ram,r[13],4);
r[0]=tmp;
goto P_0c036bbe;
P_0c036bbe: /* original c801, guest PC 0x0c036bbe */
if(!s->budget--) { s->failed_pc=0x0c036bbeu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&1u)==0)!=0);
goto P_0c036bc0;
P_0c036bc0: /* original 7ffc, guest PC 0x0c036bc0 */
if(!s->budget--) { s->failed_pc=0x0c036bc0u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c036bc2;
P_0c036bc2: /* original 8d0a, guest PC 0x0c036bc2 */
if(!s->budget--) { s->failed_pc=0x0c036bc2u; return 0; }
cond=r[17]&1u;
r[14]=r[4];
if(cond) { goto P_0c036bda; }
goto P_0c036bc6;
P_0c036bc4: /* original 6e43, guest PC 0x0c036bc4 */
if(!s->budget--) { s->failed_pc=0x0c036bc4u; return 0; }
r[14]=r[4];
goto P_0c036bc6;
P_0c036bc6: /* original d211, guest PC 0x0c036bc6 */
if(!s->budget--) { s->failed_pc=0x0c036bc6u; return 0; }
r[2]=read(ram,0x0c036c0cu,4);
goto P_0c036bc8;
P_0c036bc8: /* original 65d3, guest PC 0x0c036bc8 */
if(!s->budget--) { s->failed_pc=0x0c036bc8u; return 0; }
r[5]=r[13];
goto P_0c036bca;
P_0c036bca: /* original 420b, guest PC 0x0c036bca */
if(!s->budget--) { s->failed_pc=0x0c036bcau; return 0; }
target=r[2];
r[16]=code_base|0x0c036bceu;
r[4]=r[15];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c036bceu) { target=s->pc; goto dispatch; }
goto P_0c036bce;
P_0c036bcc: /* original 64f3, guest PC 0x0c036bcc */
if(!s->budget--) { s->failed_pc=0x0c036bccu; return 0; }
r[4]=r[15];
goto P_0c036bce;
P_0c036bce: /* original 4011, guest PC 0x0c036bce */
if(!s->budget--) { s->failed_pc=0x0c036bceu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[0]>=0)!=0);
goto P_0c036bd0;
P_0c036bd0: /* original 8903, guest PC 0x0c036bd0 */
if(!s->budget--) { s->failed_pc=0x0c036bd0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c036bda; }
goto P_0c036bd2;
P_0c036bd2: /* original e400, guest PC 0x0c036bd2 */
if(!s->budget--) { s->failed_pc=0x0c036bd2u; return 0; }
r[4]=0x00000000u;
goto P_0c036bd4;
P_0c036bd4: /* original 1e41, guest PC 0x0c036bd4 */
if(!s->budget--) { s->failed_pc=0x0c036bd4u; return 0; }
write(ram,r[14]+4,r[4],4);
goto P_0c036bd6;
P_0c036bd6: /* original a02a, guest PC 0x0c036bd6 */
if(!s->budget--) { s->failed_pc=0x0c036bd6u; return 0; }
write(ram,r[14],r[4],4);
goto P_0c036c2e;
P_0c036bd8: /* original 2e42, guest PC 0x0c036bd8 */
if(!s->budget--) { s->failed_pc=0x0c036bd8u; return 0; }
write(ram,r[14],r[4],4);
goto P_0c036bda;
P_0c036bda: /* original d30d, guest PC 0x0c036bda */
if(!s->budget--) { s->failed_pc=0x0c036bdau; return 0; }
r[3]=read(ram,0x0c036c10u,4);
goto P_0c036bdc;
P_0c036bdc: /* original 430b, guest PC 0x0c036bdc */
if(!s->budget--) { s->failed_pc=0x0c036bdcu; return 0; }
target=r[3];
r[16]=code_base|0x0c036be0u;
r[4]=0x00000005u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c036be0u) { target=s->pc; goto dispatch; }
goto P_0c036be0;
P_0c036bde: /* original e405, guest PC 0x0c036bde */
if(!s->budget--) { s->failed_pc=0x0c036bdeu; return 0; }
r[4]=0x00000005u;
goto P_0c036be0;
P_0c036be0: /* original 8801, guest PC 0x0c036be0 */
if(!s->budget--) { s->failed_pc=0x0c036be0u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c036be2;
P_0c036be2: /* original 8b17, guest PC 0x0c036be2 */
if(!s->budget--) { s->failed_pc=0x0c036be2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c036c14; }
goto P_0c036be4;
P_0c036be4: /* original bfd5, guest PC 0x0c036be4 */
if(!s->budget--) { s->failed_pc=0x0c036be4u; return 0; }
target=code_base|0x0c036b92u; r[16]=code_base|0x0c036be8u;
tmp=read(ram,r[15],4);
r[4]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c036be8u) { target=s->pc; goto dispatch; }
goto P_0c036be8;
P_0c036be6: /* original 64f2, guest PC 0x0c036be6 */
if(!s->budget--) { s->failed_pc=0x0c036be6u; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c036be8;
P_0c036be8: /* original a016, guest PC 0x0c036be8 */
if(!s->budget--) { s->failed_pc=0x0c036be8u; return 0; }
write(ram,r[14]+4,r[0],4);
goto P_0c036c18;
P_0c036bea: /* original 1e01, guest PC 0x0c036bea */
if(!s->budget--) { s->failed_pc=0x0c036beau; return 0; }
write(ram,r[14]+4,r[0],4);
if(!vf3_matrix_family(0x0c036becu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c036becu; return 0; } return 1;
P_0c036c14: /* original 63f2, guest PC 0x0c036c14 */
if(!s->budget--) { s->failed_pc=0x0c036c14u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c036c16;
P_0c036c16: /* original 1e31, guest PC 0x0c036c16 */
if(!s->budget--) { s->failed_pc=0x0c036c16u; return 0; }
write(ram,r[14]+4,r[3],4);
goto P_0c036c18;
P_0c036c18: /* original 54e1, guest PC 0x0c036c18 */
if(!s->budget--) { s->failed_pc=0x0c036c18u; return 0; }
r[4]=read(ram,r[14]+4,4);
goto P_0c036c1a;
P_0c036c1a: /* original d53b, guest PC 0x0c036c1a */
if(!s->budget--) { s->failed_pc=0x0c036c1au; return 0; }
r[5]=read(ram,0x0c036d08u,4);
goto P_0c036c1c;
P_0c036c1c: /* original 6343, guest PC 0x0c036c1c */
if(!s->budget--) { s->failed_pc=0x0c036c1cu; return 0; }
r[3]=r[4];
goto P_0c036c1e;
P_0c036c1e: /* original 2359, guest PC 0x0c036c1e */
if(!s->budget--) { s->failed_pc=0x0c036c1eu; return 0; }
r[3]&=r[5];
goto P_0c036c20;
P_0c036c20: /* original 3350, guest PC 0x0c036c20 */
if(!s->budget--) { s->failed_pc=0x0c036c20u; return 0; }
r[17]=(r[17]&~1u)|((r[3]==r[5])!=0);
goto P_0c036c22;
P_0c036c22: /* original 8906, guest PC 0x0c036c22 */
if(!s->budget--) { s->failed_pc=0x0c036c22u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c036c32; }
goto P_0c036c24;
P_0c036c24: /* original 936c, guest PC 0x0c036c24 */
if(!s->budget--) { s->failed_pc=0x0c036c24u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c036d00u,2);
goto P_0c036c26;
P_0c036c26: /* original 926b, guest PC 0x0c036c26 */
if(!s->budget--) { s->failed_pc=0x0c036c26u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c036d00u,2);
goto P_0c036c28;
P_0c036c28: /* original 2349, guest PC 0x0c036c28 */
if(!s->budget--) { s->failed_pc=0x0c036c28u; return 0; }
r[3]&=r[4];
goto P_0c036c2a;
P_0c036c2a: /* original 3320, guest PC 0x0c036c2a */
if(!s->budget--) { s->failed_pc=0x0c036c2au; return 0; }
r[17]=(r[17]&~1u)|((r[3]==r[2])!=0);
goto P_0c036c2c;
P_0c036c2c: /* original 8901, guest PC 0x0c036c2c */
if(!s->budget--) { s->failed_pc=0x0c036c2cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c036c32; }
goto P_0c036c2e;
P_0c036c2e: /* original a006, guest PC 0x0c036c2e */
if(!s->budget--) { s->failed_pc=0x0c036c2eu; return 0; }
r[0]=0x00000000u;
goto P_0c036c3e;
P_0c036c30: /* original e000, guest PC 0x0c036c30 */
if(!s->budget--) { s->failed_pc=0x0c036c30u; return 0; }
r[0]=0x00000000u;
goto P_0c036c32;
P_0c036c32: /* original 63d3, guest PC 0x0c036c32 */
if(!s->budget--) { s->failed_pc=0x0c036c32u; return 0; }
r[3]=r[13];
goto P_0c036c34;
P_0c036c34: /* original 52e1, guest PC 0x0c036c34 */
if(!s->budget--) { s->failed_pc=0x0c036c34u; return 0; }
r[2]=read(ram,r[14]+4,4);
goto P_0c036c36;
P_0c036c36: /* original 7314, guest PC 0x0c036c36 */
if(!s->budget--) { s->failed_pc=0x0c036c36u; return 0; }
r[3]+=0x00000014u;
goto P_0c036c38;
P_0c036c38: /* original e001, guest PC 0x0c036c38 */
if(!s->budget--) { s->failed_pc=0x0c036c38u; return 0; }
r[0]=0x00000001u;
goto P_0c036c3a;
P_0c036c3a: /* original 2e22, guest PC 0x0c036c3a */
if(!s->budget--) { s->failed_pc=0x0c036c3au; return 0; }
write(ram,r[14],r[2],4);
goto P_0c036c3c;
P_0c036c3c: /* original 1e39, guest PC 0x0c036c3c */
if(!s->budget--) { s->failed_pc=0x0c036c3cu; return 0; }
write(ram,r[14]+36,r[3],4);
goto P_0c036c3e;
P_0c036c3e: /* original 7f04, guest PC 0x0c036c3e */
if(!s->budget--) { s->failed_pc=0x0c036c3eu; return 0; }
r[15]+=0x00000004u;
goto P_0c036c40;
P_0c036c40: /* original 4f26, guest PC 0x0c036c40 */
if(!s->budget--) { s->failed_pc=0x0c036c40u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c036c42;
P_0c036c42: /* original 6df6, guest PC 0x0c036c42 */
if(!s->budget--) { s->failed_pc=0x0c036c42u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c036c44;
P_0c036c44: /* original 000b, guest PC 0x0c036c44 */
if(!s->budget--) { s->failed_pc=0x0c036c44u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c036c46: /* original 6ef6, guest PC 0x0c036c46 */
if(!s->budget--) { s->failed_pc=0x0c036c46u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c036c48;
P_0c036c48: /* original 8464, guest PC 0x0c036c48 */
if(!s->budget--) { s->failed_pc=0x0c036c48u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[6]+4,1);
goto P_0c036c4a;
P_0c036c4a: /* original 600c, guest PC 0x0c036c4a */
if(!s->budget--) { s->failed_pc=0x0c036c4au; return 0; }
r[0]=r[0]&255u;
goto P_0c036c4c;
P_0c036c4c: /* original 8800, guest PC 0x0c036c4c */
if(!s->budget--) { s->failed_pc=0x0c036c4cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000000u)!=0);
goto P_0c036c4e;
P_0c036c4e: /* original 8910, guest PC 0x0c036c4e */
if(!s->budget--) { s->failed_pc=0x0c036c4eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c036c72; }
goto P_0c036c50;
P_0c036c50: /* original 8805, guest PC 0x0c036c50 */
if(!s->budget--) { s->failed_pc=0x0c036c50u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000005u)!=0);
goto P_0c036c52;
P_0c036c52: /* original 890e, guest PC 0x0c036c52 */
if(!s->budget--) { s->failed_pc=0x0c036c52u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c036c72; }
goto P_0c036c54;
P_0c036c54: /* original 8806, guest PC 0x0c036c54 */
if(!s->budget--) { s->failed_pc=0x0c036c54u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000006u)!=0);
goto P_0c036c56;
P_0c036c56: /* original 890c, guest PC 0x0c036c56 */
if(!s->budget--) { s->failed_pc=0x0c036c56u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c036c72; }
goto P_0c036c58;
P_0c036c58: /* original 8808, guest PC 0x0c036c58 */
if(!s->budget--) { s->failed_pc=0x0c036c58u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000008u)!=0);
goto P_0c036c5a;
P_0c036c5a: /* original 890a, guest PC 0x0c036c5a */
if(!s->budget--) { s->failed_pc=0x0c036c5au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c036c72; }
goto P_0c036c5c;
P_0c036c5c: /* original 9151, guest PC 0x0c036c5c */
if(!s->budget--) { s->failed_pc=0x0c036c5cu; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c036d02u,2);
goto P_0c036c5e;
P_0c036c5e: /* original 3010, guest PC 0x0c036c5e */
if(!s->budget--) { s->failed_pc=0x0c036c5eu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==r[1])!=0);
goto P_0c036c60;
P_0c036c60: /* original 8904, guest PC 0x0c036c60 */
if(!s->budget--) { s->failed_pc=0x0c036c60u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c036c6c; }
goto P_0c036c62;
P_0c036c62: /* original 914f, guest PC 0x0c036c62 */
if(!s->budget--) { s->failed_pc=0x0c036c62u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c036d04u,2);
goto P_0c036c64;
P_0c036c64: /* original 3010, guest PC 0x0c036c64 */
if(!s->budget--) { s->failed_pc=0x0c036c64u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==r[1])!=0);
goto P_0c036c66;
P_0c036c66: /* original 8904, guest PC 0x0c036c66 */
if(!s->budget--) { s->failed_pc=0x0c036c66u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c036c72; }
goto P_0c036c68;
P_0c036c68: /* original a005, guest PC 0x0c036c68 */
if(!s->budget--) { s->failed_pc=0x0c036c68u; return 0; }
goto P_0c036c76;
P_0c036c6a: /* original 0009, guest PC 0x0c036c6a */
if(!s->budget--) { s->failed_pc=0x0c036c6au; return 0; }
goto P_0c036c6c;
P_0c036c6c: /* original d027, guest PC 0x0c036c6c */
if(!s->budget--) { s->failed_pc=0x0c036c6cu; return 0; }
r[0]=read(ram,0x0c036d0cu,4);
goto P_0c036c6e;
P_0c036c6e: /* original 000b, guest PC 0x0c036c6e */
if(!s->budget--) { s->failed_pc=0x0c036c6eu; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c036c70: /* original 0009, guest PC 0x0c036c70 */
if(!s->budget--) { s->failed_pc=0x0c036c70u; return 0; }
goto P_0c036c72;
P_0c036c72: /* original 000b, guest PC 0x0c036c72 */
if(!s->budget--) { s->failed_pc=0x0c036c72u; return 0; }
target=r[16];
r[0]=0x00000000u;
s->pc=target; return ram->oob==0;
P_0c036c74: /* original e000, guest PC 0x0c036c74 */
if(!s->budget--) { s->failed_pc=0x0c036c74u; return 0; }
r[0]=0x00000000u;
goto P_0c036c76;
P_0c036c76: /* original d026, guest PC 0x0c036c76 */
if(!s->budget--) { s->failed_pc=0x0c036c76u; return 0; }
r[0]=read(ram,0x0c036d10u,4);
goto P_0c036c78;
P_0c036c78: /* original 000b, guest PC 0x0c036c78 */
if(!s->budget--) { s->failed_pc=0x0c036c78u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c036c7a: /* original 0009, guest PC 0x0c036c7a */
if(!s->budget--) { s->failed_pc=0x0c036c7au; return 0; }
goto P_0c036c7c;
P_0c036c7c: /* original 2fe6, guest PC 0x0c036c7c */
if(!s->budget--) { s->failed_pc=0x0c036c7cu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c036c7e;
P_0c036c7e: /* original e300, guest PC 0x0c036c7e */
if(!s->budget--) { s->failed_pc=0x0c036c7eu; return 0; }
r[3]=0x00000000u;
goto P_0c036c80;
P_0c036c80: /* original 2fd6, guest PC 0x0c036c80 */
if(!s->budget--) { s->failed_pc=0x0c036c80u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c036c82;
P_0c036c82: /* original 2fc6, guest PC 0x0c036c82 */
if(!s->budget--) { s->failed_pc=0x0c036c82u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c036c84;
P_0c036c84: /* original 2fb6, guest PC 0x0c036c84 */
if(!s->budget--) { s->failed_pc=0x0c036c84u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c036c86;
P_0c036c86: /* original 2fa6, guest PC 0x0c036c86 */
if(!s->budget--) { s->failed_pc=0x0c036c86u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c036c88;
P_0c036c88: /* original 2f96, guest PC 0x0c036c88 */
if(!s->budget--) { s->failed_pc=0x0c036c88u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c036c8a;
P_0c036c8a: /* original 2f86, guest PC 0x0c036c8a */
if(!s->budget--) { s->failed_pc=0x0c036c8au; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c036c8c;
P_0c036c8c: /* original 4f22, guest PC 0x0c036c8c */
if(!s->budget--) { s->failed_pc=0x0c036c8cu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c036c8e;
P_0c036c8e: /* original 4f12, guest PC 0x0c036c8e */
if(!s->budget--) { s->failed_pc=0x0c036c8eu; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c036c90;
P_0c036c90: /* original 7ff8, guest PC 0x0c036c90 */
if(!s->budget--) { s->failed_pc=0x0c036c90u; return 0; }
r[15]+=0xfffffff8u;
goto P_0c036c92;
P_0c036c92: /* original 2f32, guest PC 0x0c036c92 */
if(!s->budget--) { s->failed_pc=0x0c036c92u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c036c94;
P_0c036c94: /* original d41f, guest PC 0x0c036c94 */
if(!s->budget--) { s->failed_pc=0x0c036c94u; return 0; }
r[4]=read(ram,0x0c036d14u,4);
goto P_0c036c96;
P_0c036c96: /* original 6943, guest PC 0x0c036c96 */
if(!s->budget--) { s->failed_pc=0x0c036c96u; return 0; }
r[9]=r[4];
goto P_0c036c98;
P_0c036c98: /* original 6a43, guest PC 0x0c036c98 */
if(!s->budget--) { s->failed_pc=0x0c036c98u; return 0; }
r[10]=r[4];
goto P_0c036c9a;
P_0c036c9a: /* original 6843, guest PC 0x0c036c9a */
if(!s->budget--) { s->failed_pc=0x0c036c9au; return 0; }
r[8]=r[4];
goto P_0c036c9c;
P_0c036c9c: /* original 6cf2, guest PC 0x0c036c9c */
if(!s->budget--) { s->failed_pc=0x0c036c9cu; return 0; }
tmp=read(ram,r[15],4);
r[12]=tmp;
goto P_0c036c9e;
P_0c036c9e: /* original 4c08, guest PC 0x0c036c9e */
if(!s->budget--) { s->failed_pc=0x0c036c9eu; return 0; }
r[12]<<=2;
goto P_0c036ca0;
P_0c036ca0: /* original 1fc1, guest PC 0x0c036ca0 */
if(!s->budget--) { s->failed_pc=0x0c036ca0u; return 0; }
write(ram,r[15]+4,r[12],4);
goto P_0c036ca2;
P_0c036ca2: /* original d01d, guest PC 0x0c036ca2 */
if(!s->budget--) { s->failed_pc=0x0c036ca2u; return 0; }
r[0]=read(ram,0x0c036d18u,4);
goto P_0c036ca4;
P_0c036ca4: /* original d31d, guest PC 0x0c036ca4 */
if(!s->budget--) { s->failed_pc=0x0c036ca4u; return 0; }
r[3]=read(ram,0x0c036d1cu,4);
goto P_0c036ca6;
P_0c036ca6: /* original 0cce, guest PC 0x0c036ca6 */
if(!s->budget--) { s->failed_pc=0x0c036ca6u; return 0; }
r[12]=read(ram,r[12]+r[0],4);
goto P_0c036ca8;
P_0c036ca8: /* original 430b, guest PC 0x0c036ca8 */
if(!s->budget--) { s->failed_pc=0x0c036ca8u; return 0; }
target=r[3];
r[16]=code_base|0x0c036cacu;
r[4]=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c036cacu) { target=s->pc; goto dispatch; }
goto P_0c036cac;
P_0c036caa: /* original 64c3, guest PC 0x0c036caa */
if(!s->budget--) { s->failed_pc=0x0c036caau; return 0; }
r[4]=r[12];
goto P_0c036cac;
P_0c036cac: /* original d21c, guest PC 0x0c036cac */
if(!s->budget--) { s->failed_pc=0x0c036cacu; return 0; }
r[2]=read(ram,0x0c036d20u,4);
goto P_0c036cae;
P_0c036cae: /* original 6d03, guest PC 0x0c036cae */
if(!s->budget--) { s->failed_pc=0x0c036caeu; return 0; }
r[13]=r[0];
goto P_0c036cb0;
P_0c036cb0: /* original 420b, guest PC 0x0c036cb0 */
if(!s->budget--) { s->failed_pc=0x0c036cb0u; return 0; }
target=r[2];
r[16]=code_base|0x0c036cb4u;
r[4]=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c036cb4u) { target=s->pc; goto dispatch; }
goto P_0c036cb4;
P_0c036cb2: /* original 64c3, guest PC 0x0c036cb2 */
if(!s->budget--) { s->failed_pc=0x0c036cb2u; return 0; }
r[4]=r[12];
goto P_0c036cb4;
P_0c036cb4: /* original ee34, guest PC 0x0c036cb4 */
if(!s->budget--) { s->failed_pc=0x0c036cb4u; return 0; }
r[14]=0x00000034u;
goto P_0c036cb6;
P_0c036cb6: /* original d31b, guest PC 0x0c036cb6 */
if(!s->budget--) { s->failed_pc=0x0c036cb6u; return 0; }
r[3]=read(ram,0x0c036d24u,4);
goto P_0c036cb8;
P_0c036cb8: /* original 2cef, guest PC 0x0c036cb8 */
if(!s->budget--) { s->failed_pc=0x0c036cb8u; return 0; }
r[19]=(uint32_t)((int32_t)(int16_t)r[12]*(int32_t)(int16_t)r[14]);
goto P_0c036cba;
P_0c036cba: /* original 6b03, guest PC 0x0c036cba */
if(!s->budget--) { s->failed_pc=0x0c036cbau; return 0; }
r[11]=r[0];
goto P_0c036cbc;
P_0c036cbc: /* original 66d3, guest PC 0x0c036cbc */
if(!s->budget--) { s->failed_pc=0x0c036cbcu; return 0; }
r[6]=r[13];
goto P_0c036cbe;
P_0c036cbe: /* original 65b3, guest PC 0x0c036cbe */
if(!s->budget--) { s->failed_pc=0x0c036cbeu; return 0; }
r[5]=r[11];
goto P_0c036cc0;
P_0c036cc0: /* original 4c08, guest PC 0x0c036cc0 */
if(!s->budget--) { s->failed_pc=0x0c036cc0u; return 0; }
r[12]<<=2;
goto P_0c036cc2;
P_0c036cc2: /* original 0e1a, guest PC 0x0c036cc2 */
if(!s->budget--) { s->failed_pc=0x0c036cc2u; return 0; }
r[14]=r[19];
goto P_0c036cc4;
P_0c036cc4: /* original 6eef, guest PC 0x0c036cc4 */
if(!s->budget--) { s->failed_pc=0x0c036cc4u; return 0; }
r[14]=(uint32_t)(int32_t)(int16_t)r[14];
goto P_0c036cc6;
P_0c036cc6: /* original 3e3c, guest PC 0x0c036cc6 */
if(!s->budget--) { s->failed_pc=0x0c036cc6u; return 0; }
r[14]+=r[3];
goto P_0c036cc8;
P_0c036cc8: /* original 1e0c, guest PC 0x0c036cc8 */
if(!s->budget--) { s->failed_pc=0x0c036cc8u; return 0; }
write(ram,r[14]+48,r[0],4);
goto P_0c036cca;
P_0c036cca: /* original 52e2, guest PC 0x0c036cca */
if(!s->budget--) { s->failed_pc=0x0c036ccau; return 0; }
r[2]=read(ram,r[14]+8,4);
goto P_0c036ccc;
P_0c036ccc: /* original 1e2b, guest PC 0x0c036ccc */
if(!s->budget--) { s->failed_pc=0x0c036cccu; return 0; }
write(ram,r[14]+44,r[2],4);
goto P_0c036cce;
P_0c036cce: /* original bfbb, guest PC 0x0c036cce */
if(!s->budget--) { s->failed_pc=0x0c036cceu; return 0; }
target=code_base|0x0c036c48u; r[16]=code_base|0x0c036cd2u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c036cd2u) { target=s->pc; goto dispatch; }
goto P_0c036cd2;
P_0c036cd0: /* original 64e3, guest PC 0x0c036cd0 */
if(!s->budget--) { s->failed_pc=0x0c036cd0u; return 0; }
r[4]=r[14];
goto P_0c036cd2;
P_0c036cd2: /* original d115, guest PC 0x0c036cd2 */
if(!s->budget--) { s->failed_pc=0x0c036cd2u; return 0; }
r[1]=read(ram,0x0c036d28u,4);
goto P_0c036cd4;
P_0c036cd4: /* original 31cc, guest PC 0x0c036cd4 */
if(!s->budget--) { s->failed_pc=0x0c036cd4u; return 0; }
r[1]+=r[12];
goto P_0c036cd6;
P_0c036cd6: /* original 2102, guest PC 0x0c036cd6 */
if(!s->budget--) { s->failed_pc=0x0c036cd6u; return 0; }
write(ram,r[1],r[0],4);
goto P_0c036cd8;
P_0c036cd8: /* original 60b2, guest PC 0x0c036cd8 */
if(!s->budget--) { s->failed_pc=0x0c036cd8u; return 0; }
tmp=read(ram,r[11],4);
r[0]=tmp;
goto P_0c036cda;
P_0c036cda: /* original c801, guest PC 0x0c036cda */
if(!s->budget--) { s->failed_pc=0x0c036cdau; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&1u)==0)!=0);
goto P_0c036cdc;
P_0c036cdc: /* original 8926, guest PC 0x0c036cdc */
if(!s->budget--) { s->failed_pc=0x0c036cdcu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c036d2c; }
goto P_0c036cde;
P_0c036cde: /* original 84d2, guest PC 0x0c036cde */
if(!s->budget--) { s->failed_pc=0x0c036cdeu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+2,1);
goto P_0c036ce0;
P_0c036ce0: /* original 2008, guest PC 0x0c036ce0 */
if(!s->budget--) { s->failed_pc=0x0c036ce0u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c036ce2;
P_0c036ce2: /* original 8b23, guest PC 0x0c036ce2 */
if(!s->budget--) { s->failed_pc=0x0c036ce2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c036d2c; }
goto P_0c036ce4;
P_0c036ce4: /* original 84d4, guest PC 0x0c036ce4 */
if(!s->budget--) { s->failed_pc=0x0c036ce4u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+4,1);
goto P_0c036ce6;
P_0c036ce6: /* original 600c, guest PC 0x0c036ce6 */
if(!s->budget--) { s->failed_pc=0x0c036ce6u; return 0; }
r[0]=r[0]&255u;
goto P_0c036ce8;
P_0c036ce8: /* original 8808, guest PC 0x0c036ce8 */
if(!s->budget--) { s->failed_pc=0x0c036ce8u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000008u)!=0);
goto P_0c036cea;
P_0c036cea: /* original 8b1f, guest PC 0x0c036cea */
if(!s->budget--) { s->failed_pc=0x0c036ceau; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c036d2c; }
goto P_0c036cec;
P_0c036cec: /* original 65b3, guest PC 0x0c036cec */
if(!s->budget--) { s->failed_pc=0x0c036cecu; return 0; }
r[5]=r[11];
goto P_0c036cee;
P_0c036cee: /* original bf61, guest PC 0x0c036cee */
if(!s->budget--) { s->failed_pc=0x0c036ceeu; return 0; }
target=code_base|0x0c036bb4u; r[16]=code_base|0x0c036cf2u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c036cf2u) { target=s->pc; goto dispatch; }
goto P_0c036cf2;
P_0c036cf0: /* original 64e3, guest PC 0x0c036cf0 */
if(!s->budget--) { s->failed_pc=0x0c036cf0u; return 0; }
r[4]=r[14];
goto P_0c036cf2;
P_0c036cf2: /* original 8801, guest PC 0x0c036cf2 */
if(!s->budget--) { s->failed_pc=0x0c036cf2u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c036cf4;
P_0c036cf4: /* original 8b1a, guest PC 0x0c036cf4 */
if(!s->budget--) { s->failed_pc=0x0c036cf4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c036d2c; }
goto P_0c036cf6;
P_0c036cf6: /* original 65d3, guest PC 0x0c036cf6 */
if(!s->budget--) { s->failed_pc=0x0c036cf6u; return 0; }
r[5]=r[13];
goto P_0c036cf8;
P_0c036cf8: /* original becd, guest PC 0x0c036cf8 */
if(!s->budget--) { s->failed_pc=0x0c036cf8u; return 0; }
target=code_base|0x0c036a96u; r[16]=code_base|0x0c036cfcu;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c036cfcu) { target=s->pc; goto dispatch; }
goto P_0c036cfc;
P_0c036cfa: /* original 64e3, guest PC 0x0c036cfa */
if(!s->budget--) { s->failed_pc=0x0c036cfau; return 0; }
r[4]=r[14];
goto P_0c036cfc;
P_0c036cfc: /* original a018, guest PC 0x0c036cfc */
if(!s->budget--) { s->failed_pc=0x0c036cfcu; return 0; }
goto P_0c036d30;
P_0c036cfe: /* original 0009, guest PC 0x0c036cfe */
if(!s->budget--) { s->failed_pc=0x0c036cfeu; return 0; }
if(!vf3_matrix_family(0x0c036d00u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c036d00u; return 0; } return 1;
P_0c036d2c: /* original be94, guest PC 0x0c036d2c */
if(!s->budget--) { s->failed_pc=0x0c036d2cu; return 0; }
target=code_base|0x0c036a58u; r[16]=code_base|0x0c036d30u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c036d30u) { target=s->pc; goto dispatch; }
goto P_0c036d30;
P_0c036d2e: /* original 64e3, guest PC 0x0c036d2e */
if(!s->budget--) { s->failed_pc=0x0c036d2eu; return 0; }
r[4]=r[14];
goto P_0c036d30;
P_0c036d30: /* original 53e2, guest PC 0x0c036d30 */
if(!s->budget--) { s->failed_pc=0x0c036d30u; return 0; }
r[3]=read(ram,r[14]+8,4);
goto P_0c036d32;
P_0c036d32: /* original 6337, guest PC 0x0c036d32 */
if(!s->budget--) { s->failed_pc=0x0c036d32u; return 0; }
r[3]=~r[3];
goto P_0c036d34;
P_0c036d34: /* original 1e33, guest PC 0x0c036d34 */
if(!s->budget--) { s->failed_pc=0x0c036d34u; return 0; }
write(ram,r[14]+12,r[3],4);
goto P_0c036d36;
P_0c036d36: /* original d145, guest PC 0x0c036d36 */
if(!s->budget--) { s->failed_pc=0x0c036d36u; return 0; }
r[1]=read(ram,0x0c036e4cu,4);
goto P_0c036d38;
P_0c036d38: /* original 6212, guest PC 0x0c036d38 */
if(!s->budget--) { s->failed_pc=0x0c036d38u; return 0; }
tmp=read(ram,r[1],4);
r[2]=tmp;
goto P_0c036d3a;
P_0c036d3a: /* original 2228, guest PC 0x0c036d3a */
if(!s->budget--) { s->failed_pc=0x0c036d3au; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c036d3c;
P_0c036d3c: /* original 8b07, guest PC 0x0c036d3c */
if(!s->budget--) { s->failed_pc=0x0c036d3cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c036d4e; }
goto P_0c036d3e;
P_0c036d3e: /* original 54eb, guest PC 0x0c036d3e */
if(!s->budget--) { s->failed_pc=0x0c036d3eu; return 0; }
r[4]=read(ram,r[14]+44,4);
goto P_0c036d40;
P_0c036d40: /* original 55e2, guest PC 0x0c036d40 */
if(!s->budget--) { s->failed_pc=0x0c036d40u; return 0; }
r[5]=read(ram,r[14]+8,4);
goto P_0c036d42;
P_0c036d42: /* original 245a, guest PC 0x0c036d42 */
if(!s->budget--) { s->failed_pc=0x0c036d42u; return 0; }
r[4]^=r[5];
goto P_0c036d44;
P_0c036d44: /* original 2549, guest PC 0x0c036d44 */
if(!s->budget--) { s->failed_pc=0x0c036d44u; return 0; }
r[5]&=r[4];
goto P_0c036d46;
P_0c036d46: /* original 1e54, guest PC 0x0c036d46 */
if(!s->budget--) { s->failed_pc=0x0c036d46u; return 0; }
write(ram,r[14]+16,r[5],4);
goto P_0c036d48;
P_0c036d48: /* original 53e3, guest PC 0x0c036d48 */
if(!s->budget--) { s->failed_pc=0x0c036d48u; return 0; }
r[3]=read(ram,r[14]+12,4);
goto P_0c036d4a;
P_0c036d4a: /* original a009, guest PC 0x0c036d4a */
if(!s->budget--) { s->failed_pc=0x0c036d4au; return 0; }
r[4]&=r[3];
goto P_0c036d60;
P_0c036d4c: /* original 2439, guest PC 0x0c036d4c */
if(!s->budget--) { s->failed_pc=0x0c036d4cu; return 0; }
r[4]&=r[3];
goto P_0c036d4e;
P_0c036d4e: /* original 54eb, guest PC 0x0c036d4e */
if(!s->budget--) { s->failed_pc=0x0c036d4eu; return 0; }
r[4]=read(ram,r[14]+44,4);
goto P_0c036d50;
P_0c036d50: /* original e3ff, guest PC 0x0c036d50 */
if(!s->budget--) { s->failed_pc=0x0c036d50u; return 0; }
r[3]=0xffffffffu;
goto P_0c036d52;
P_0c036d52: /* original 55e2, guest PC 0x0c036d52 */
if(!s->budget--) { s->failed_pc=0x0c036d52u; return 0; }
r[5]=read(ram,r[14]+8,4);
goto P_0c036d54;
P_0c036d54: /* original 245a, guest PC 0x0c036d54 */
if(!s->budget--) { s->failed_pc=0x0c036d54u; return 0; }
r[4]^=r[5];
goto P_0c036d56;
P_0c036d56: /* original 243a, guest PC 0x0c036d56 */
if(!s->budget--) { s->failed_pc=0x0c036d56u; return 0; }
r[4]^=r[3];
goto P_0c036d58;
P_0c036d58: /* original 254b, guest PC 0x0c036d58 */
if(!s->budget--) { s->failed_pc=0x0c036d58u; return 0; }
r[5]|=r[4];
goto P_0c036d5a;
P_0c036d5a: /* original 1e54, guest PC 0x0c036d5a */
if(!s->budget--) { s->failed_pc=0x0c036d5au; return 0; }
write(ram,r[14]+16,r[5],4);
goto P_0c036d5c;
P_0c036d5c: /* original 52e3, guest PC 0x0c036d5c */
if(!s->budget--) { s->failed_pc=0x0c036d5cu; return 0; }
r[2]=read(ram,r[14]+12,4);
goto P_0c036d5e;
P_0c036d5e: /* original 242b, guest PC 0x0c036d5e */
if(!s->budget--) { s->failed_pc=0x0c036d5eu; return 0; }
r[4]|=r[2];
goto P_0c036d60;
P_0c036d60: /* original 1e45, guest PC 0x0c036d60 */
if(!s->budget--) { s->failed_pc=0x0c036d60u; return 0; }
write(ram,r[14]+20,r[4],4);
goto P_0c036d62;
P_0c036d62: /* original d03b, guest PC 0x0c036d62 */
if(!s->budget--) { s->failed_pc=0x0c036d62u; return 0; }
r[0]=read(ram,0x0c036e50u,4);
goto P_0c036d64;
P_0c036d64: /* original 53f1, guest PC 0x0c036d64 */
if(!s->budget--) { s->failed_pc=0x0c036d64u; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c036d66;
P_0c036d66: /* original 023e, guest PC 0x0c036d66 */
if(!s->budget--) { s->failed_pc=0x0c036d66u; return 0; }
r[2]=read(ram,r[3]+r[0],4);
goto P_0c036d68;
P_0c036d68: /* original 4215, guest PC 0x0c036d68 */
if(!s->budget--) { s->failed_pc=0x0c036d68u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[2]>0)!=0);
goto P_0c036d6a;
P_0c036d6a: /* original 8b03, guest PC 0x0c036d6a */
if(!s->budget--) { s->failed_pc=0x0c036d6au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c036d74; }
goto P_0c036d6c;
P_0c036d6c: /* original 51e4, guest PC 0x0c036d6c */
if(!s->budget--) { s->failed_pc=0x0c036d6cu; return 0; }
r[1]=read(ram,r[14]+16,4);
goto P_0c036d6e;
P_0c036d6e: /* original e3f7, guest PC 0x0c036d6e */
if(!s->budget--) { s->failed_pc=0x0c036d6eu; return 0; }
r[3]=0xfffffff7u;
goto P_0c036d70;
P_0c036d70: /* original 2139, guest PC 0x0c036d70 */
if(!s->budget--) { s->failed_pc=0x0c036d70u; return 0; }
r[1]&=r[3];
goto P_0c036d72;
P_0c036d72: /* original 1e14, guest PC 0x0c036d72 */
if(!s->budget--) { s->failed_pc=0x0c036d72u; return 0; }
write(ram,r[14]+16,r[1],4);
goto P_0c036d74;
P_0c036d74: /* original 50e4, guest PC 0x0c036d74 */
if(!s->budget--) { s->failed_pc=0x0c036d74u; return 0; }
r[0]=read(ram,r[14]+16,4);
goto P_0c036d76;
P_0c036d76: /* original c808, guest PC 0x0c036d76 */
if(!s->budget--) { s->failed_pc=0x0c036d76u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&8u)==0)!=0);
goto P_0c036d78;
P_0c036d78: /* original 8902, guest PC 0x0c036d78 */
if(!s->budget--) { s->failed_pc=0x0c036d78u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c036d80; }
goto P_0c036d7a;
P_0c036d7a: /* original d336, guest PC 0x0c036d7a */
if(!s->budget--) { s->failed_pc=0x0c036d7au; return 0; }
r[3]=read(ram,0x0c036e54u,4);
goto P_0c036d7c;
P_0c036d7c: /* original 6232, guest PC 0x0c036d7c */
if(!s->budget--) { s->failed_pc=0x0c036d7cu; return 0; }
tmp=read(ram,r[3],4);
r[2]=tmp;
goto P_0c036d7e;
P_0c036d7e: /* original 2a22, guest PC 0x0c036d7e */
if(!s->budget--) { s->failed_pc=0x0c036d7eu; return 0; }
write(ram,r[10],r[2],4);
goto P_0c036d80;
P_0c036d80: /* original 6192, guest PC 0x0c036d80 */
if(!s->budget--) { s->failed_pc=0x0c036d80u; return 0; }
tmp=read(ram,r[9],4);
r[1]=tmp;
goto P_0c036d82;
P_0c036d82: /* original 4115, guest PC 0x0c036d82 */
if(!s->budget--) { s->failed_pc=0x0c036d82u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[1]>0)!=0);
goto P_0c036d84;
P_0c036d84: /* original 8b02, guest PC 0x0c036d84 */
if(!s->budget--) { s->failed_pc=0x0c036d84u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c036d8c; }
goto P_0c036d86;
P_0c036d86: /* original 6282, guest PC 0x0c036d86 */
if(!s->budget--) { s->failed_pc=0x0c036d86u; return 0; }
tmp=read(ram,r[8],4);
r[2]=tmp;
goto P_0c036d88;
P_0c036d88: /* original 72ff, guest PC 0x0c036d88 */
if(!s->budget--) { s->failed_pc=0x0c036d88u; return 0; }
r[2]+=0xffffffffu;
goto P_0c036d8a;
P_0c036d8a: /* original 2822, guest PC 0x0c036d8a */
if(!s->budget--) { s->failed_pc=0x0c036d8au; return 0; }
write(ram,r[8],r[2],4);
goto P_0c036d8c;
P_0c036d8c: /* original 63f2, guest PC 0x0c036d8c */
if(!s->budget--) { s->failed_pc=0x0c036d8cu; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c036d8e;
P_0c036d8e: /* original e202, guest PC 0x0c036d8e */
if(!s->budget--) { s->failed_pc=0x0c036d8eu; return 0; }
r[2]=0x00000002u;
goto P_0c036d90;
P_0c036d90: /* original 7904, guest PC 0x0c036d90 */
if(!s->budget--) { s->failed_pc=0x0c036d90u; return 0; }
r[9]+=0x00000004u;
goto P_0c036d92;
P_0c036d92: /* original 7301, guest PC 0x0c036d92 */
if(!s->budget--) { s->failed_pc=0x0c036d92u; return 0; }
r[3]+=0x00000001u;
goto P_0c036d94;
P_0c036d94: /* original 3323, guest PC 0x0c036d94 */
if(!s->budget--) { s->failed_pc=0x0c036d94u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>=(int32_t)r[2])!=0);
goto P_0c036d96;
P_0c036d96: /* original 2f32, guest PC 0x0c036d96 */
if(!s->budget--) { s->failed_pc=0x0c036d96u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c036d98;
P_0c036d98: /* original 7804, guest PC 0x0c036d98 */
if(!s->budget--) { s->failed_pc=0x0c036d98u; return 0; }
r[8]+=0x00000004u;
goto P_0c036d9a;
P_0c036d9a: /* original 8d02, guest PC 0x0c036d9a */
if(!s->budget--) { s->failed_pc=0x0c036d9au; return 0; }
cond=r[17]&1u;
r[10]+=0x00000004u;
if(cond) { goto P_0c036da2; }
goto P_0c036d9e;
P_0c036d9c: /* original 7a04, guest PC 0x0c036d9c */
if(!s->budget--) { s->failed_pc=0x0c036d9cu; return 0; }
r[10]+=0x00000004u;
goto P_0c036d9e;
P_0c036d9e: /* original af7d, guest PC 0x0c036d9e */
if(!s->budget--) { s->failed_pc=0x0c036d9eu; return 0; }
goto P_0c036c9c;
P_0c036da0: /* original 0009, guest PC 0x0c036da0 */
if(!s->budget--) { s->failed_pc=0x0c036da0u; return 0; }
goto P_0c036da2;
P_0c036da2: /* original 7f08, guest PC 0x0c036da2 */
if(!s->budget--) { s->failed_pc=0x0c036da2u; return 0; }
r[15]+=0x00000008u;
goto P_0c036da4;
P_0c036da4: /* original 4f16, guest PC 0x0c036da4 */
if(!s->budget--) { s->failed_pc=0x0c036da4u; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c036da6;
P_0c036da6: /* original 4f26, guest PC 0x0c036da6 */
if(!s->budget--) { s->failed_pc=0x0c036da6u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c036da8;
P_0c036da8: /* original 68f6, guest PC 0x0c036da8 */
if(!s->budget--) { s->failed_pc=0x0c036da8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c036daa;
P_0c036daa: /* original 69f6, guest PC 0x0c036daa */
if(!s->budget--) { s->failed_pc=0x0c036daau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c036dac;
P_0c036dac: /* original 6af6, guest PC 0x0c036dac */
if(!s->budget--) { s->failed_pc=0x0c036dacu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c036dae;
P_0c036dae: /* original 6bf6, guest PC 0x0c036dae */
if(!s->budget--) { s->failed_pc=0x0c036daeu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c036db0;
P_0c036db0: /* original 6cf6, guest PC 0x0c036db0 */
if(!s->budget--) { s->failed_pc=0x0c036db0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c036db2;
P_0c036db2: /* original 6df6, guest PC 0x0c036db2 */
if(!s->budget--) { s->failed_pc=0x0c036db2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c036db4;
P_0c036db4: /* original 000b, guest PC 0x0c036db4 */
if(!s->budget--) { s->failed_pc=0x0c036db4u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c036db6: /* original 6ef6, guest PC 0x0c036db6 */
if(!s->budget--) { s->failed_pc=0x0c036db6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c036db8u,s,ram);
unsupported: s->failed_pc=target; return 0;
}
