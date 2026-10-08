/* Static C ABI adapters. Generated with tools/oracle/translate_adapters.py.
 * Matrix operations are hand-written in matrix_family.c; unknown code fails.
 * Executed opcodes are checked against the untouched identity image. */
#include "fight/matrix_family.h"
#include "fight/sh4_fpu.h"
#include <math.h>
#include <string.h>
#define read vf3_matrix_read
#define write vf3_matrix_write
static float as_float(uint32_t u) { float f; memcpy(&f,&u,4); return f; }
static uint32_t as_bits(float f) { uint32_t u; memcpy(&u,&f,4); return u; }
static uint32_t truncate_float(uint32_t u) { double d=as_float(u); if(isnan(d) || d< -2147483648.0) return 0x80000000u; if(d>=2147483648.0) return 0x7fffffffu; return (uint32_t)(int32_t)d; }
static void divide_step(vf3_matrix_state*s,unsigned n,unsigned m) { uint32_t *r=s->v; unsigned oldq=(r[17]>>8)&1u,sign=(r[17]>>9)&1u,q=r[n]>>31; uint32_t divisor=r[m],shifted=(r[n]<<1)|(r[17]&1u); r[n]=oldq==sign?shifted-divisor:shifted+divisor; unsigned carry=oldq==sign?r[n]>shifted:r[n]<shifted; q^=carry^sign; r[17]=(r[17]&~0x101u)|(q<<8)|(q==sign); }
int vf3_motion_initialize_adapter(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
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
default: return vf3_matrix_family(target,s,ram);
}
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
return vf3_matrix_family(0x0c094b52u,s,ram);
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
target=0x0c09493cu; r[16]=0x0c094c86u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c094c86u) { target=s->pc; goto dispatch; }
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
return vf3_matrix_family(0x0c094cb0u,s,ram);
unsupported: s->failed_pc=target; return 0;
}
static const uint32_t owned_pcs[]={
0x0c094b2au,0x0c094b2cu,0x0c094b2eu,0x0c094b30u,0x0c094b32u,0x0c094b34u,0x0c094b36u,0x0c094b38u,0x0c094b3au,0x0c094b3cu,0x0c094b3eu,0x0c094b40u,0x0c094b42u,0x0c094b44u,0x0c094b46u,0x0c094b48u,
0x0c094b4au,0x0c094b4cu,0x0c094b4eu,0x0c094b50u,0x0c094b70u,0x0c094b72u,0x0c094b74u,0x0c094b76u,0x0c094b78u,0x0c094b7au,0x0c094b7cu,0x0c094b7eu,0x0c094b80u,0x0c094b82u,0x0c094b84u,0x0c094b86u,
0x0c094b88u,0x0c094b8au,0x0c094b8cu,0x0c094b8eu,0x0c094b90u,0x0c094b92u,0x0c094b94u,0x0c094b96u,0x0c094b98u,0x0c094b9au,0x0c094b9cu,0x0c094b9eu,0x0c094ba0u,0x0c094ba2u,0x0c094ba4u,0x0c094ba6u,
0x0c094ba8u,0x0c094baau,0x0c094bacu,0x0c094baeu,0x0c094bb0u,0x0c094bb2u,0x0c094bb4u,0x0c094bb6u,0x0c094bb8u,0x0c094bbau,0x0c094bbcu,0x0c094bbeu,0x0c094bc0u,0x0c094bc2u,0x0c094bc4u,0x0c094bc6u,
0x0c094bc8u,0x0c094bcau,0x0c094bccu,0x0c094bceu,0x0c094bd0u,0x0c094bd2u,0x0c094bd4u,0x0c094bd6u,0x0c094bd8u,0x0c094bdau,0x0c094bdcu,0x0c094bdeu,0x0c094be0u,0x0c094be2u,0x0c094be4u,0x0c094be6u,
0x0c094be8u,0x0c094beau,0x0c094becu,0x0c094beeu,0x0c094bf0u,0x0c094bf2u,0x0c094bf4u,0x0c094bf6u,0x0c094bf8u,0x0c094bfau,0x0c094bfcu,0x0c094bfeu,0x0c094c00u,0x0c094c02u,0x0c094c04u,0x0c094c06u,
0x0c094c08u,0x0c094c0au,0x0c094c0cu,0x0c094c0eu,0x0c094c10u,0x0c094c12u,0x0c094c14u,0x0c094c16u,0x0c094c18u,0x0c094c1au,0x0c094c1cu,0x0c094c1eu,0x0c094c20u,0x0c094c22u,0x0c094c24u,0x0c094c26u,
0x0c094c28u,0x0c094c2au,0x0c094c2cu,0x0c094c2eu,0x0c094c30u,0x0c094c32u,0x0c094c34u,0x0c094c36u,0x0c094c38u,0x0c094c3au,0x0c094c3cu,0x0c094c3eu,0x0c094c40u,0x0c094c42u,0x0c094c44u,0x0c094c46u,
0x0c094c48u,0x0c094c4au,0x0c094c4cu,0x0c094c4eu,0x0c094c50u,0x0c094c52u,0x0c094c54u,0x0c094c56u,0x0c094c58u,0x0c094c5au,0x0c094c5cu,0x0c094c5eu,0x0c094c60u,0x0c094c62u,0x0c094c64u,0x0c094c66u,
0x0c094c68u,0x0c094c6au,0x0c094c6cu,0x0c094c6eu,0x0c094c70u,0x0c094c72u,0x0c094c74u,0x0c094c76u,0x0c094c78u,0x0c094c7au,0x0c094c7cu,0x0c094c7eu,0x0c094c80u,0x0c094c82u,0x0c094c84u,0x0c094c86u,
0x0c094c88u,0x0c094c8au,0x0c094c8cu,0x0c094c8eu,0x0c094c90u,0x0c094c92u,0x0c094c94u,0x0c094c96u,0x0c094c98u,0x0c094c9au,0x0c094c9cu,0x0c094c9eu,0x0c094ca0u,0x0c094ca2u,0x0c094ca4u,0x0c094ca6u,
0x0c094ca8u,0x0c094caau,0x0c094cacu,0x0c094caeu,
};
int vf3_motion_initialize_adapter_contains(uint32_t pc) {
pc&=0x1fffffffu; unsigned lo=0,hi=sizeof(owned_pcs)/sizeof(owned_pcs[0]);
while(lo<hi) { unsigned mid=lo+(hi-lo)/2; if(owned_pcs[mid]<pc) lo=mid+1; else hi=mid; }
return lo<sizeof(owned_pcs)/sizeof(owned_pcs[0]) && owned_pcs[lo]==pc;
}
