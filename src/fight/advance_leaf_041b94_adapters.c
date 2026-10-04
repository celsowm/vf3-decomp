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
int vf3_advance_leaf_ranked_remainder_adapter(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c041b94u: goto P_0c041b94;
case 0x0c041b96u: goto P_0c041b96;
case 0x0c041b98u: goto P_0c041b98;
case 0x0c041b9au: goto P_0c041b9a;
case 0x0c041b9cu: goto P_0c041b9c;
case 0x0c041b9eu: goto P_0c041b9e;
case 0x0c041ba0u: goto P_0c041ba0;
case 0x0c041ba2u: goto P_0c041ba2;
case 0x0c041ba4u: goto P_0c041ba4;
case 0x0c041ba6u: goto P_0c041ba6;
case 0x0c041ba8u: goto P_0c041ba8;
case 0x0c041baau: goto P_0c041baa;
case 0x0c041bacu: goto P_0c041bac;
case 0x0c041baeu: goto P_0c041bae;
case 0x0c041bb0u: goto P_0c041bb0;
case 0x0c041bb2u: goto P_0c041bb2;
case 0x0c041bb4u: goto P_0c041bb4;
case 0x0c041bb6u: goto P_0c041bb6;
case 0x0c041bb8u: goto P_0c041bb8;
case 0x0c041bbau: goto P_0c041bba;
case 0x0c041bbcu: goto P_0c041bbc;
case 0x0c041bbeu: goto P_0c041bbe;
case 0x0c041bc0u: goto P_0c041bc0;
case 0x0c041bc2u: goto P_0c041bc2;
case 0x0c041bc4u: goto P_0c041bc4;
case 0x0c041bc6u: goto P_0c041bc6;
case 0x0c041bc8u: goto P_0c041bc8;
case 0x0c041bcau: goto P_0c041bca;
case 0x0c041bccu: goto P_0c041bcc;
case 0x0c041bceu: goto P_0c041bce;
case 0x0c041bd0u: goto P_0c041bd0;
case 0x0c041bd2u: goto P_0c041bd2;
case 0x0c041bd4u: goto P_0c041bd4;
case 0x0c041bd6u: goto P_0c041bd6;
case 0x0c041bd8u: goto P_0c041bd8;
case 0x0c041bdau: goto P_0c041bda;
case 0x0c041bdcu: goto P_0c041bdc;
case 0x0c041bdeu: goto P_0c041bde;
case 0x0c041be0u: goto P_0c041be0;
case 0x0c041be2u: goto P_0c041be2;
case 0x0c041be4u: goto P_0c041be4;
case 0x0c041be6u: goto P_0c041be6;
case 0x0c041be8u: goto P_0c041be8;
case 0x0c041beau: goto P_0c041bea;
case 0x0c041becu: goto P_0c041bec;
case 0x0c041beeu: goto P_0c041bee;
case 0x0c041bf0u: goto P_0c041bf0;
case 0x0c041bf2u: goto P_0c041bf2;
case 0x0c041bf4u: goto P_0c041bf4;
case 0x0c041bf6u: goto P_0c041bf6;
case 0x0c041bf8u: goto P_0c041bf8;
case 0x0c041bfau: goto P_0c041bfa;
case 0x0c041bfcu: goto P_0c041bfc;
case 0x0c041bfeu: goto P_0c041bfe;
case 0x0c041c00u: goto P_0c041c00;
case 0x0c041c02u: goto P_0c041c02;
case 0x0c041c04u: goto P_0c041c04;
case 0x0c041c06u: goto P_0c041c06;
case 0x0c041c08u: goto P_0c041c08;
case 0x0c041c0au: goto P_0c041c0a;
case 0x0c041c0cu: goto P_0c041c0c;
case 0x0c041c0eu: goto P_0c041c0e;
case 0x0c041c10u: goto P_0c041c10;
case 0x0c041c12u: goto P_0c041c12;
case 0x0c041c14u: goto P_0c041c14;
case 0x0c041c16u: goto P_0c041c16;
case 0x0c041c18u: goto P_0c041c18;
case 0x0c041c1au: goto P_0c041c1a;
case 0x0c041c1cu: goto P_0c041c1c;
case 0x0c041c1eu: goto P_0c041c1e;
case 0x0c041c20u: goto P_0c041c20;
case 0x0c041c22u: goto P_0c041c22;
case 0x0c041c24u: goto P_0c041c24;
case 0x0c041c26u: goto P_0c041c26;
case 0x0c041c28u: goto P_0c041c28;
case 0x0c041c2au: goto P_0c041c2a;
case 0x0c041c2cu: goto P_0c041c2c;
case 0x0c041c2eu: goto P_0c041c2e;
case 0x0c041c30u: goto P_0c041c30;
case 0x0c041c32u: goto P_0c041c32;
case 0x0c041c34u: goto P_0c041c34;
case 0x0c041c36u: goto P_0c041c36;
case 0x0c041c38u: goto P_0c041c38;
case 0x0c041c3au: goto P_0c041c3a;
case 0x0c041c3cu: goto P_0c041c3c;
case 0x0c041c3eu: goto P_0c041c3e;
case 0x0c041c40u: goto P_0c041c40;
case 0x0c041c42u: goto P_0c041c42;
case 0x0c041c44u: goto P_0c041c44;
case 0x0c041c46u: goto P_0c041c46;
case 0x0c041c48u: goto P_0c041c48;
case 0x0c041c4au: goto P_0c041c4a;
case 0x0c041c4cu: goto P_0c041c4c;
case 0x0c041c4eu: goto P_0c041c4e;
case 0x0c041c50u: goto P_0c041c50;
case 0x0c041c52u: goto P_0c041c52;
case 0x0c041c54u: goto P_0c041c54;
case 0x0c041c56u: goto P_0c041c56;
case 0x0c041c58u: goto P_0c041c58;
case 0x0c041c5au: goto P_0c041c5a;
case 0x0c041c5cu: goto P_0c041c5c;
case 0x0c041c5eu: goto P_0c041c5e;
case 0x0c041c60u: goto P_0c041c60;
case 0x0c041c62u: goto P_0c041c62;
case 0x0c041c64u: goto P_0c041c64;
case 0x0c041c66u: goto P_0c041c66;
case 0x0c041c68u: goto P_0c041c68;
case 0x0c041c6au: goto P_0c041c6a;
case 0x0c041c6cu: goto P_0c041c6c;
case 0x0c041c6eu: goto P_0c041c6e;
case 0x0c041c70u: goto P_0c041c70;
case 0x0c041c72u: goto P_0c041c72;
case 0x0c041c74u: goto P_0c041c74;
case 0x0c041c76u: goto P_0c041c76;
case 0x0c041c78u: goto P_0c041c78;
case 0x0c041c7au: goto P_0c041c7a;
case 0x0c041c7cu: goto P_0c041c7c;
case 0x0c041c84u: goto P_0c041c84;
case 0x0c041c86u: goto P_0c041c86;
case 0x0c041c88u: goto P_0c041c88;
case 0x0c041c8au: goto P_0c041c8a;
case 0x0c041c8cu: goto P_0c041c8c;
case 0x0c041c8eu: goto P_0c041c8e;
case 0x0c041c90u: goto P_0c041c90;
case 0x0c041c92u: goto P_0c041c92;
case 0x0c041c94u: goto P_0c041c94;
case 0x0c041c96u: goto P_0c041c96;
case 0x0c041c98u: goto P_0c041c98;
case 0x0c041c9au: goto P_0c041c9a;
case 0x0c041c9cu: goto P_0c041c9c;
case 0x0c041c9eu: goto P_0c041c9e;
case 0x0c041ca0u: goto P_0c041ca0;
case 0x0c041ca2u: goto P_0c041ca2;
case 0x0c041ca4u: goto P_0c041ca4;
case 0x0c041ca6u: goto P_0c041ca6;
case 0x0c041ca8u: goto P_0c041ca8;
case 0x0c041caau: goto P_0c041caa;
case 0x0c041cacu: goto P_0c041cac;
case 0x0c041caeu: goto P_0c041cae;
case 0x0c041cb0u: goto P_0c041cb0;
case 0x0c041cb2u: goto P_0c041cb2;
case 0x0c041cb4u: goto P_0c041cb4;
case 0x0c041cb6u: goto P_0c041cb6;
case 0x0c041cb8u: goto P_0c041cb8;
case 0x0c041cbau: goto P_0c041cba;
case 0x0c041cbcu: goto P_0c041cbc;
case 0x0c041cbeu: goto P_0c041cbe;
case 0x0c041cc0u: goto P_0c041cc0;
case 0x0c041cc2u: goto P_0c041cc2;
case 0x0c041cc4u: goto P_0c041cc4;
case 0x0c041cc6u: goto P_0c041cc6;
case 0x0c041cc8u: goto P_0c041cc8;
case 0x0c041ccau: goto P_0c041cca;
case 0x0c041cccu: goto P_0c041ccc;
case 0x0c041cceu: goto P_0c041cce;
case 0x0c041cd0u: goto P_0c041cd0;
case 0x0c041cd2u: goto P_0c041cd2;
case 0x0c041cd4u: goto P_0c041cd4;
case 0x0c041cd6u: goto P_0c041cd6;
case 0x0c041cd8u: goto P_0c041cd8;
case 0x0c041cdau: goto P_0c041cda;
case 0x0c041cdcu: goto P_0c041cdc;
case 0x0c041cdeu: goto P_0c041cde;
case 0x0c041ce0u: goto P_0c041ce0;
case 0x0c041ce2u: goto P_0c041ce2;
case 0x0c041ce4u: goto P_0c041ce4;
case 0x0c041ce6u: goto P_0c041ce6;
case 0x0c041ce8u: goto P_0c041ce8;
case 0x0c041ceau: goto P_0c041cea;
case 0x0c041cecu: goto P_0c041cec;
case 0x0c041ceeu: goto P_0c041cee;
case 0x0c041cf0u: goto P_0c041cf0;
case 0x0c041cf2u: goto P_0c041cf2;
case 0x0c041cf4u: goto P_0c041cf4;
case 0x0c041cf6u: goto P_0c041cf6;
case 0x0c041cf8u: goto P_0c041cf8;
case 0x0c041cfau: goto P_0c041cfa;
case 0x0c041cfcu: goto P_0c041cfc;
case 0x0c041cfeu: goto P_0c041cfe;
case 0x0c041d00u: goto P_0c041d00;
case 0x0c041d02u: goto P_0c041d02;
default: return vf3_matrix_family(target,s,ram);
}
P_0c041b94: /* original 4f22, guest PC 0x0c041b94 */
if(!s->budget--) { s->failed_pc=0x0c041b94u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c041b96;
P_0c041b96: /* original 7ff4, guest PC 0x0c041b96 */
if(!s->budget--) { s->failed_pc=0x0c041b96u; return 0; }
r[15]+=0xfffffff4u;
goto P_0c041b98;
P_0c041b98: /* original 1f42, guest PC 0x0c041b98 */
if(!s->budget--) { s->failed_pc=0x0c041b98u; return 0; }
write(ram,r[15]+8,r[4],4);
goto P_0c041b9a;
P_0c041b9a: /* original 1f51, guest PC 0x0c041b9a */
if(!s->budget--) { s->failed_pc=0x0c041b9au; return 0; }
write(ram,r[15]+4,r[5],4);
goto P_0c041b9c;
P_0c041b9c: /* original 63f3, guest PC 0x0c041b9c */
if(!s->budget--) { s->failed_pc=0x0c041b9cu; return 0; }
r[3]=r[15];
goto P_0c041b9e;
P_0c041b9e: /* original 7302, guest PC 0x0c041b9e */
if(!s->budget--) { s->failed_pc=0x0c041b9eu; return 0; }
r[3]+=0x00000002u;
goto P_0c041ba0;
P_0c041ba0: /* original 2361, guest PC 0x0c041ba0 */
if(!s->budget--) { s->failed_pc=0x0c041ba0u; return 0; }
write(ram,r[3],r[6],2);
goto P_0c041ba2;
P_0c041ba2: /* original 53f2, guest PC 0x0c041ba2 */
if(!s->budget--) { s->failed_pc=0x0c041ba2u; return 0; }
r[3]=read(ram,r[15]+8,4);
goto P_0c041ba4;
P_0c041ba4: /* original 5e33, guest PC 0x0c041ba4 */
if(!s->budget--) { s->failed_pc=0x0c041ba4u; return 0; }
r[14]=read(ram,r[3]+12,4);
goto P_0c041ba6;
P_0c041ba6: /* original 8439, guest PC 0x0c041ba6 */
if(!s->budget--) { s->failed_pc=0x0c041ba6u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[3]+9,1);
goto P_0c041ba8;
P_0c041ba8: /* original c903, guest PC 0x0c041ba8 */
if(!s->budget--) { s->failed_pc=0x0c041ba8u; return 0; }
r[0]&=3u;
goto P_0c041baa;
P_0c041baa: /* original 8800, guest PC 0x0c041baa */
if(!s->budget--) { s->failed_pc=0x0c041baau; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000000u)!=0);
goto P_0c041bac;
P_0c041bac: /* original 8905, guest PC 0x0c041bac */
if(!s->budget--) { s->failed_pc=0x0c041bacu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c041bba; }
goto P_0c041bae;
P_0c041bae: /* original 8801, guest PC 0x0c041bae */
if(!s->budget--) { s->failed_pc=0x0c041baeu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c041bb0;
P_0c041bb0: /* original 8906, guest PC 0x0c041bb0 */
if(!s->budget--) { s->failed_pc=0x0c041bb0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c041bc0; }
goto P_0c041bb2;
P_0c041bb2: /* original 8802, guest PC 0x0c041bb2 */
if(!s->budget--) { s->failed_pc=0x0c041bb2u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c041bb4;
P_0c041bb4: /* original 8907, guest PC 0x0c041bb4 */
if(!s->budget--) { s->failed_pc=0x0c041bb4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c041bc6; }
goto P_0c041bb6;
P_0c041bb6: /* original a009, guest PC 0x0c041bb6 */
if(!s->budget--) { s->failed_pc=0x0c041bb6u; return 0; }
goto P_0c041bcc;
P_0c041bb8: /* original 0009, guest PC 0x0c041bb8 */
if(!s->budget--) { s->failed_pc=0x0c041bb8u; return 0; }
goto P_0c041bba;
P_0c041bba: /* original ed01, guest PC 0x0c041bba */
if(!s->budget--) { s->failed_pc=0x0c041bbau; return 0; }
r[13]=0x00000001u;
goto P_0c041bbc;
P_0c041bbc: /* original a006, guest PC 0x0c041bbc */
if(!s->budget--) { s->failed_pc=0x0c041bbcu; return 0; }
goto P_0c041bcc;
P_0c041bbe: /* original 0009, guest PC 0x0c041bbe */
if(!s->budget--) { s->failed_pc=0x0c041bbeu; return 0; }
goto P_0c041bc0;
P_0c041bc0: /* original ed02, guest PC 0x0c041bc0 */
if(!s->budget--) { s->failed_pc=0x0c041bc0u; return 0; }
r[13]=0x00000002u;
goto P_0c041bc2;
P_0c041bc2: /* original a003, guest PC 0x0c041bc2 */
if(!s->budget--) { s->failed_pc=0x0c041bc2u; return 0; }
goto P_0c041bcc;
P_0c041bc4: /* original 0009, guest PC 0x0c041bc4 */
if(!s->budget--) { s->failed_pc=0x0c041bc4u; return 0; }
goto P_0c041bc6;
P_0c041bc6: /* original ed04, guest PC 0x0c041bc6 */
if(!s->budget--) { s->failed_pc=0x0c041bc6u; return 0; }
r[13]=0x00000004u;
goto P_0c041bc8;
P_0c041bc8: /* original a000, guest PC 0x0c041bc8 */
if(!s->budget--) { s->failed_pc=0x0c041bc8u; return 0; }
goto P_0c041bcc;
P_0c041bca: /* original 0009, guest PC 0x0c041bca */
if(!s->budget--) { s->failed_pc=0x0c041bcau; return 0; }
goto P_0c041bcc;
P_0c041bcc: /* original 53f2, guest PC 0x0c041bcc */
if(!s->budget--) { s->failed_pc=0x0c041bccu; return 0; }
r[3]=read(ram,r[15]+8,4);
goto P_0c041bce;
P_0c041bce: /* original 8438, guest PC 0x0c041bce */
if(!s->budget--) { s->failed_pc=0x0c041bceu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[3]+8,1);
goto P_0c041bd0;
P_0c041bd0: /* original 8800, guest PC 0x0c041bd0 */
if(!s->budget--) { s->failed_pc=0x0c041bd0u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000000u)!=0);
goto P_0c041bd2;
P_0c041bd2: /* original 8907, guest PC 0x0c041bd2 */
if(!s->budget--) { s->failed_pc=0x0c041bd2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c041be4; }
goto P_0c041bd4;
P_0c041bd4: /* original 8801, guest PC 0x0c041bd4 */
if(!s->budget--) { s->failed_pc=0x0c041bd4u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c041bd6;
P_0c041bd6: /* original 8908, guest PC 0x0c041bd6 */
if(!s->budget--) { s->failed_pc=0x0c041bd6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c041bea; }
goto P_0c041bd8;
P_0c041bd8: /* original 8802, guest PC 0x0c041bd8 */
if(!s->budget--) { s->failed_pc=0x0c041bd8u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c041bda;
P_0c041bda: /* original 8909, guest PC 0x0c041bda */
if(!s->budget--) { s->failed_pc=0x0c041bdau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c041bf0; }
goto P_0c041bdc;
P_0c041bdc: /* original 8803, guest PC 0x0c041bdc */
if(!s->budget--) { s->failed_pc=0x0c041bdcu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000003u)!=0);
goto P_0c041bde;
P_0c041bde: /* original 8907, guest PC 0x0c041bde */
if(!s->budget--) { s->failed_pc=0x0c041bdeu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c041bf0; }
goto P_0c041be0;
P_0c041be0: /* original a009, guest PC 0x0c041be0 */
if(!s->budget--) { s->failed_pc=0x0c041be0u; return 0; }
goto P_0c041bf6;
P_0c041be2: /* original 0009, guest PC 0x0c041be2 */
if(!s->budget--) { s->failed_pc=0x0c041be2u; return 0; }
goto P_0c041be4;
P_0c041be4: /* original ec10, guest PC 0x0c041be4 */
if(!s->budget--) { s->failed_pc=0x0c041be4u; return 0; }
r[12]=0x00000010u;
goto P_0c041be6;
P_0c041be6: /* original a006, guest PC 0x0c041be6 */
if(!s->budget--) { s->failed_pc=0x0c041be6u; return 0; }
goto P_0c041bf6;
P_0c041be8: /* original 0009, guest PC 0x0c041be8 */
if(!s->budget--) { s->failed_pc=0x0c041be8u; return 0; }
goto P_0c041bea;
P_0c041bea: /* original ec08, guest PC 0x0c041bea */
if(!s->budget--) { s->failed_pc=0x0c041beau; return 0; }
r[12]=0x00000008u;
goto P_0c041bec;
P_0c041bec: /* original a003, guest PC 0x0c041bec */
if(!s->budget--) { s->failed_pc=0x0c041becu; return 0; }
goto P_0c041bf6;
P_0c041bee: /* original 0009, guest PC 0x0c041bee */
if(!s->budget--) { s->failed_pc=0x0c041beeu; return 0; }
goto P_0c041bf0;
P_0c041bf0: /* original ec04, guest PC 0x0c041bf0 */
if(!s->budget--) { s->failed_pc=0x0c041bf0u; return 0; }
r[12]=0x00000004u;
goto P_0c041bf2;
P_0c041bf2: /* original a000, guest PC 0x0c041bf2 */
if(!s->budget--) { s->failed_pc=0x0c041bf2u; return 0; }
goto P_0c041bf6;
P_0c041bf4: /* original 0009, guest PC 0x0c041bf4 */
if(!s->budget--) { s->failed_pc=0x0c041bf4u; return 0; }
goto P_0c041bf6;
P_0c041bf6: /* original 50f1, guest PC 0x0c041bf6 */
if(!s->budget--) { s->failed_pc=0x0c041bf6u; return 0; }
r[0]=read(ram,r[15]+4,4);
goto P_0c041bf8;
P_0c041bf8: /* original 8800, guest PC 0x0c041bf8 */
if(!s->budget--) { s->failed_pc=0x0c041bf8u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000000u)!=0);
goto P_0c041bfa;
P_0c041bfa: /* original 8915, guest PC 0x0c041bfa */
if(!s->budget--) { s->failed_pc=0x0c041bfau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c041c28; }
goto P_0c041bfc;
P_0c041bfc: /* original 8801, guest PC 0x0c041bfc */
if(!s->budget--) { s->failed_pc=0x0c041bfcu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c041bfe;
P_0c041bfe: /* original 8919, guest PC 0x0c041bfe */
if(!s->budget--) { s->failed_pc=0x0c041bfeu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c041c34; }
goto P_0c041c00;
P_0c041c00: /* original 8802, guest PC 0x0c041c00 */
if(!s->budget--) { s->failed_pc=0x0c041c00u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c041c02;
P_0c041c02: /* original 891b, guest PC 0x0c041c02 */
if(!s->budget--) { s->failed_pc=0x0c041c02u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c041c3c; }
goto P_0c041c04;
P_0c041c04: /* original 8803, guest PC 0x0c041c04 */
if(!s->budget--) { s->failed_pc=0x0c041c04u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000003u)!=0);
goto P_0c041c06;
P_0c041c06: /* original 8929, guest PC 0x0c041c06 */
if(!s->budget--) { s->failed_pc=0x0c041c06u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c041c5c; }
goto P_0c041c08;
P_0c041c08: /* original 8804, guest PC 0x0c041c08 */
if(!s->budget--) { s->failed_pc=0x0c041c08u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000004u)!=0);
goto P_0c041c0a;
P_0c041c0a: /* original 892b, guest PC 0x0c041c0a */
if(!s->budget--) { s->failed_pc=0x0c041c0au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c041c64; }
goto P_0c041c0c;
P_0c041c0c: /* original 8805, guest PC 0x0c041c0c */
if(!s->budget--) { s->failed_pc=0x0c041c0cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000005u)!=0);
goto P_0c041c0e;
P_0c041c0e: /* original 892d, guest PC 0x0c041c0e */
if(!s->budget--) { s->failed_pc=0x0c041c0eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c041c6c; }
goto P_0c041c10;
P_0c041c10: /* original 8806, guest PC 0x0c041c10 */
if(!s->budget--) { s->failed_pc=0x0c041c10u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000006u)!=0);
goto P_0c041c12;
P_0c041c12: /* original 8937, guest PC 0x0c041c12 */
if(!s->budget--) { s->failed_pc=0x0c041c12u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c041c84; }
goto P_0c041c14;
P_0c041c14: /* original 8807, guest PC 0x0c041c14 */
if(!s->budget--) { s->failed_pc=0x0c041c14u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000007u)!=0);
goto P_0c041c16;
P_0c041c16: /* original 893e, guest PC 0x0c041c16 */
if(!s->budget--) { s->failed_pc=0x0c041c16u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c041c96; }
goto P_0c041c18;
P_0c041c18: /* original 8808, guest PC 0x0c041c18 */
if(!s->budget--) { s->failed_pc=0x0c041c18u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000008u)!=0);
goto P_0c041c1a;
P_0c041c1a: /* original 8943, guest PC 0x0c041c1a */
if(!s->budget--) { s->failed_pc=0x0c041c1au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c041ca4; }
goto P_0c041c1c;
P_0c041c1c: /* original 8809, guest PC 0x0c041c1c */
if(!s->budget--) { s->failed_pc=0x0c041c1cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000009u)!=0);
goto P_0c041c1e;
P_0c041c1e: /* original 894a, guest PC 0x0c041c1e */
if(!s->budget--) { s->failed_pc=0x0c041c1eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c041cb6; }
goto P_0c041c20;
P_0c041c20: /* original 880a, guest PC 0x0c041c20 */
if(!s->budget--) { s->failed_pc=0x0c041c20u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000au)!=0);
goto P_0c041c22;
P_0c041c22: /* original 895f, guest PC 0x0c041c22 */
if(!s->budget--) { s->failed_pc=0x0c041c22u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c041ce4; }
goto P_0c041c24;
P_0c041c24: /* original a064, guest PC 0x0c041c24 */
if(!s->budget--) { s->failed_pc=0x0c041c24u; return 0; }
goto P_0c041cf0;
P_0c041c26: /* original 0009, guest PC 0x0c041c26 */
if(!s->budget--) { s->failed_pc=0x0c041c26u; return 0; }
goto P_0c041c28;
P_0c041c28: /* original 53f2, guest PC 0x0c041c28 */
if(!s->budget--) { s->failed_pc=0x0c041c28u; return 0; }
r[3]=read(ram,r[15]+8,4);
goto P_0c041c2a;
P_0c041c2a: /* original e02a, guest PC 0x0c041c2a */
if(!s->budget--) { s->failed_pc=0x0c041c2au; return 0; }
r[0]=0x0000002au;
goto P_0c041c2c;
P_0c041c2c: /* original 003d, guest PC 0x0c041c2c */
if(!s->budget--) { s->failed_pc=0x0c041c2cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[3]+r[0],2);
goto P_0c041c2e;
P_0c041c2e: /* original 600d, guest PC 0x0c041c2e */
if(!s->budget--) { s->failed_pc=0x0c041c2eu; return 0; }
r[0]=r[0]&65535u;
goto P_0c041c30;
P_0c041c30: /* original a061, guest PC 0x0c041c30 */
if(!s->budget--) { s->failed_pc=0x0c041c30u; return 0; }
goto P_0c041cf6;
P_0c041c32: /* original 0009, guest PC 0x0c041c32 */
if(!s->budget--) { s->failed_pc=0x0c041c32u; return 0; }
goto P_0c041c34;
P_0c041c34: /* original 60c3, guest PC 0x0c041c34 */
if(!s->budget--) { s->failed_pc=0x0c041c34u; return 0; }
r[0]=r[12];
goto P_0c041c36;
P_0c041c36: /* original 0009, guest PC 0x0c041c36 */
if(!s->budget--) { s->failed_pc=0x0c041c36u; return 0; }
goto P_0c041c38;
P_0c041c38: /* original a05d, guest PC 0x0c041c38 */
if(!s->budget--) { s->failed_pc=0x0c041c38u; return 0; }
goto P_0c041cf6;
P_0c041c3a: /* original 0009, guest PC 0x0c041c3a */
if(!s->budget--) { s->failed_pc=0x0c041c3au; return 0; }
goto P_0c041c3c;
P_0c041c3c: /* original 61e3, guest PC 0x0c041c3c */
if(!s->budget--) { s->failed_pc=0x0c041c3cu; return 0; }
r[1]=r[14];
goto P_0c041c3e;
P_0c041c3e: /* original 4108, guest PC 0x0c041c3e */
if(!s->budget--) { s->failed_pc=0x0c041c3eu; return 0; }
r[1]<<=2;
goto P_0c041c40;
P_0c041c40: /* original 4100, guest PC 0x0c041c40 */
if(!s->budget--) { s->failed_pc=0x0c041c40u; return 0; }
r[17]=(r[17]&~1u)|((r[1]>>31)!=0);
r[1]<<=1;
goto P_0c041c42;
P_0c041c42: /* original 60c3, guest PC 0x0c041c42 */
if(!s->budget--) { s->failed_pc=0x0c041c42u; return 0; }
r[0]=r[12];
goto P_0c041c44;
P_0c041c44: /* original 0009, guest PC 0x0c041c44 */
if(!s->budget--) { s->failed_pc=0x0c041c44u; return 0; }
goto P_0c041c46;
P_0c041c46: /* original d30e, guest PC 0x0c041c46 */
if(!s->budget--) { s->failed_pc=0x0c041c46u; return 0; }
r[3]=read(ram,0x0c041c80u,4);
goto P_0c041c48;
P_0c041c48: /* original 430b, guest PC 0x0c041c48 */
if(!s->budget--) { s->failed_pc=0x0c041c48u; return 0; }
target=r[3];
r[16]=0x0c041c4cu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c041c4cu) { target=s->pc; goto dispatch; }
goto P_0c041c4c;
P_0c041c4a: /* original 0009, guest PC 0x0c041c4a */
if(!s->budget--) { s->failed_pc=0x0c041c4au; return 0; }
goto P_0c041c4c;
P_0c041c4c: /* original 6103, guest PC 0x0c041c4c */
if(!s->budget--) { s->failed_pc=0x0c041c4cu; return 0; }
r[1]=r[0];
goto P_0c041c4e;
P_0c041c4e: /* original 60d3, guest PC 0x0c041c4e */
if(!s->budget--) { s->failed_pc=0x0c041c4eu; return 0; }
r[0]=r[13];
goto P_0c041c50;
P_0c041c50: /* original 0009, guest PC 0x0c041c50 */
if(!s->budget--) { s->failed_pc=0x0c041c50u; return 0; }
goto P_0c041c52;
P_0c041c52: /* original d20b, guest PC 0x0c041c52 */
if(!s->budget--) { s->failed_pc=0x0c041c52u; return 0; }
r[2]=read(ram,0x0c041c80u,4);
goto P_0c041c54;
P_0c041c54: /* original 420b, guest PC 0x0c041c54 */
if(!s->budget--) { s->failed_pc=0x0c041c54u; return 0; }
target=r[2];
r[16]=0x0c041c58u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c041c58u) { target=s->pc; goto dispatch; }
goto P_0c041c58;
P_0c041c56: /* original 0009, guest PC 0x0c041c56 */
if(!s->budget--) { s->failed_pc=0x0c041c56u; return 0; }
goto P_0c041c58;
P_0c041c58: /* original a04d, guest PC 0x0c041c58 */
if(!s->budget--) { s->failed_pc=0x0c041c58u; return 0; }
goto P_0c041cf6;
P_0c041c5a: /* original 0009, guest PC 0x0c041c5a */
if(!s->budget--) { s->failed_pc=0x0c041c5au; return 0; }
goto P_0c041c5c;
P_0c041c5c: /* original 60e3, guest PC 0x0c041c5c */
if(!s->budget--) { s->failed_pc=0x0c041c5cu; return 0; }
r[0]=r[14];
goto P_0c041c5e;
P_0c041c5e: /* original 0009, guest PC 0x0c041c5e */
if(!s->budget--) { s->failed_pc=0x0c041c5eu; return 0; }
goto P_0c041c60;
P_0c041c60: /* original a049, guest PC 0x0c041c60 */
if(!s->budget--) { s->failed_pc=0x0c041c60u; return 0; }
goto P_0c041cf6;
P_0c041c62: /* original 0009, guest PC 0x0c041c62 */
if(!s->budget--) { s->failed_pc=0x0c041c62u; return 0; }
goto P_0c041c64;
P_0c041c64: /* original 60d3, guest PC 0x0c041c64 */
if(!s->budget--) { s->failed_pc=0x0c041c64u; return 0; }
r[0]=r[13];
goto P_0c041c66;
P_0c041c66: /* original 0009, guest PC 0x0c041c66 */
if(!s->budget--) { s->failed_pc=0x0c041c66u; return 0; }
goto P_0c041c68;
P_0c041c68: /* original a045, guest PC 0x0c041c68 */
if(!s->budget--) { s->failed_pc=0x0c041c68u; return 0; }
goto P_0c041cf6;
P_0c041c6a: /* original 0009, guest PC 0x0c041c6a */
if(!s->budget--) { s->failed_pc=0x0c041c6au; return 0; }
goto P_0c041c6c;
P_0c041c6c: /* original 85f1, guest PC 0x0c041c6c */
if(!s->budget--) { s->failed_pc=0x0c041c6cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[15]+2,2);
goto P_0c041c6e;
P_0c041c6e: /* original 4008, guest PC 0x0c041c6e */
if(!s->budget--) { s->failed_pc=0x0c041c6eu; return 0; }
r[0]<<=2;
goto P_0c041c70;
P_0c041c70: /* original 53f2, guest PC 0x0c041c70 */
if(!s->budget--) { s->failed_pc=0x0c041c70u; return 0; }
r[3]=read(ram,r[15]+8,4);
goto P_0c041c72;
P_0c041c72: /* original 303c, guest PC 0x0c041c72 */
if(!s->budget--) { s->failed_pc=0x0c041c72u; return 0; }
r[0]+=r[3];
goto P_0c041c74;
P_0c041c74: /* original 7031, guest PC 0x0c041c74 */
if(!s->budget--) { s->failed_pc=0x0c041c74u; return 0; }
r[0]+=0x00000031u;
goto P_0c041c76;
P_0c041c76: /* original 6000, guest PC 0x0c041c76 */
if(!s->budget--) { s->failed_pc=0x0c041c76u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[0],1);
r[0]=tmp;
goto P_0c041c78;
P_0c041c78: /* original 600c, guest PC 0x0c041c78 */
if(!s->budget--) { s->failed_pc=0x0c041c78u; return 0; }
r[0]=r[0]&255u;
goto P_0c041c7a;
P_0c041c7a: /* original a03c, guest PC 0x0c041c7a */
if(!s->budget--) { s->failed_pc=0x0c041c7au; return 0; }
goto P_0c041cf6;
P_0c041c7c: /* original 0009, guest PC 0x0c041c7c */
if(!s->budget--) { s->failed_pc=0x0c041c7cu; return 0; }
return vf3_matrix_family(0x0c041c7eu,s,ram);
P_0c041c84: /* original 85f1, guest PC 0x0c041c84 */
if(!s->budget--) { s->failed_pc=0x0c041c84u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[15]+2,2);
goto P_0c041c86;
P_0c041c86: /* original 4008, guest PC 0x0c041c86 */
if(!s->budget--) { s->failed_pc=0x0c041c86u; return 0; }
r[0]<<=2;
goto P_0c041c88;
P_0c041c88: /* original 53f2, guest PC 0x0c041c88 */
if(!s->budget--) { s->failed_pc=0x0c041c88u; return 0; }
r[3]=read(ram,r[15]+8,4);
goto P_0c041c8a;
P_0c041c8a: /* original 303c, guest PC 0x0c041c8a */
if(!s->budget--) { s->failed_pc=0x0c041c8au; return 0; }
r[0]+=r[3];
goto P_0c041c8c;
P_0c041c8c: /* original 7032, guest PC 0x0c041c8c */
if(!s->budget--) { s->failed_pc=0x0c041c8cu; return 0; }
r[0]+=0x00000032u;
goto P_0c041c8e;
P_0c041c8e: /* original 6000, guest PC 0x0c041c8e */
if(!s->budget--) { s->failed_pc=0x0c041c8eu; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[0],1);
r[0]=tmp;
goto P_0c041c90;
P_0c041c90: /* original 600c, guest PC 0x0c041c90 */
if(!s->budget--) { s->failed_pc=0x0c041c90u; return 0; }
r[0]=r[0]&255u;
goto P_0c041c92;
P_0c041c92: /* original a030, guest PC 0x0c041c92 */
if(!s->budget--) { s->failed_pc=0x0c041c92u; return 0; }
goto P_0c041cf6;
P_0c041c94: /* original 0009, guest PC 0x0c041c94 */
if(!s->budget--) { s->failed_pc=0x0c041c94u; return 0; }
goto P_0c041c96;
P_0c041c96: /* original 53f2, guest PC 0x0c041c96 */
if(!s->budget--) { s->failed_pc=0x0c041c96u; return 0; }
r[3]=read(ram,r[15]+8,4);
goto P_0c041c98;
P_0c041c98: /* original e033, guest PC 0x0c041c98 */
if(!s->budget--) { s->failed_pc=0x0c041c98u; return 0; }
r[0]=0x00000033u;
goto P_0c041c9a;
P_0c041c9a: /* original 003c, guest PC 0x0c041c9a */
if(!s->budget--) { s->failed_pc=0x0c041c9au; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[3]+r[0],1);
goto P_0c041c9c;
P_0c041c9c: /* original 600c, guest PC 0x0c041c9c */
if(!s->budget--) { s->failed_pc=0x0c041c9cu; return 0; }
r[0]=r[0]&255u;
goto P_0c041c9e;
P_0c041c9e: /* original c90f, guest PC 0x0c041c9e */
if(!s->budget--) { s->failed_pc=0x0c041c9eu; return 0; }
r[0]&=15u;
goto P_0c041ca0;
P_0c041ca0: /* original a029, guest PC 0x0c041ca0 */
if(!s->budget--) { s->failed_pc=0x0c041ca0u; return 0; }
goto P_0c041cf6;
P_0c041ca2: /* original 0009, guest PC 0x0c041ca2 */
if(!s->budget--) { s->failed_pc=0x0c041ca2u; return 0; }
goto P_0c041ca4;
P_0c041ca4: /* original 53f2, guest PC 0x0c041ca4 */
if(!s->budget--) { s->failed_pc=0x0c041ca4u; return 0; }
r[3]=read(ram,r[15]+8,4);
goto P_0c041ca6;
P_0c041ca6: /* original e033, guest PC 0x0c041ca6 */
if(!s->budget--) { s->failed_pc=0x0c041ca6u; return 0; }
r[0]=0x00000033u;
goto P_0c041ca8;
P_0c041ca8: /* original 003c, guest PC 0x0c041ca8 */
if(!s->budget--) { s->failed_pc=0x0c041ca8u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[3]+r[0],1);
goto P_0c041caa;
P_0c041caa: /* original 600c, guest PC 0x0c041caa */
if(!s->budget--) { s->failed_pc=0x0c041caau; return 0; }
r[0]=r[0]&255u;
goto P_0c041cac;
P_0c041cac: /* original c9f0, guest PC 0x0c041cac */
if(!s->budget--) { s->failed_pc=0x0c041cacu; return 0; }
r[0]&=240u;
goto P_0c041cae;
P_0c041cae: /* original e2fc, guest PC 0x0c041cae */
if(!s->budget--) { s->failed_pc=0x0c041caeu; return 0; }
r[2]=0xfffffffcu;
goto P_0c041cb0;
P_0c041cb0: /* original 402c, guest PC 0x0c041cb0 */
if(!s->budget--) { s->failed_pc=0x0c041cb0u; return 0; }
r[0]=(r[2]&0x80000000u)?((r[2]&31u)?(uint32_t)((int32_t)r[0]>>((-r[2])&31u)):((int32_t)r[0]<0?0xffffffffu:0)):r[0]<<(r[2]&31u);
goto P_0c041cb2;
P_0c041cb2: /* original a020, guest PC 0x0c041cb2 */
if(!s->budget--) { s->failed_pc=0x0c041cb2u; return 0; }
goto P_0c041cf6;
P_0c041cb4: /* original 0009, guest PC 0x0c041cb4 */
if(!s->budget--) { s->failed_pc=0x0c041cb4u; return 0; }
goto P_0c041cb6;
P_0c041cb6: /* original 53f2, guest PC 0x0c041cb6 */
if(!s->budget--) { s->failed_pc=0x0c041cb6u; return 0; }
r[3]=read(ram,r[15]+8,4);
goto P_0c041cb8;
P_0c041cb8: /* original e01f, guest PC 0x0c041cb8 */
if(!s->budget--) { s->failed_pc=0x0c041cb8u; return 0; }
r[0]=0x0000001fu;
goto P_0c041cba;
P_0c041cba: /* original 023c, guest PC 0x0c041cba */
if(!s->budget--) { s->failed_pc=0x0c041cbau; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[3]+r[0],1);
goto P_0c041cbc;
P_0c041cbc: /* original 2228, guest PC 0x0c041cbc */
if(!s->budget--) { s->failed_pc=0x0c041cbcu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c041cbe;
P_0c041cbe: /* original 8902, guest PC 0x0c041cbe */
if(!s->budget--) { s->failed_pc=0x0c041cbeu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c041cc6; }
goto P_0c041cc0;
P_0c041cc0: /* original e000, guest PC 0x0c041cc0 */
if(!s->budget--) { s->failed_pc=0x0c041cc0u; return 0; }
r[0]=0x00000000u;
goto P_0c041cc2;
P_0c041cc2: /* original a018, guest PC 0x0c041cc2 */
if(!s->budget--) { s->failed_pc=0x0c041cc2u; return 0; }
goto P_0c041cf6;
P_0c041cc4: /* original 0009, guest PC 0x0c041cc4 */
if(!s->budget--) { s->failed_pc=0x0c041cc4u; return 0; }
goto P_0c041cc6;
P_0c041cc6: /* original 853b, guest PC 0x0c041cc6 */
if(!s->budget--) { s->failed_pc=0x0c041cc6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[3]+22,2);
goto P_0c041cc8;
P_0c041cc8: /* original 600d, guest PC 0x0c041cc8 */
if(!s->budget--) { s->failed_pc=0x0c041cc8u; return 0; }
r[0]=r[0]&65535u;
goto P_0c041cca;
P_0c041cca: /* original 6e03, guest PC 0x0c041cca */
if(!s->budget--) { s->failed_pc=0x0c041ccau; return 0; }
r[14]=r[0];
goto P_0c041ccc;
P_0c041ccc: /* original 4e09, guest PC 0x0c041ccc */
if(!s->budget--) { s->failed_pc=0x0c041cccu; return 0; }
r[14]>>=2;
goto P_0c041cce;
P_0c041cce: /* original 4e09, guest PC 0x0c041cce */
if(!s->budget--) { s->failed_pc=0x0c041cceu; return 0; }
r[14]>>=2;
goto P_0c041cd0;
P_0c041cd0: /* original 4e09, guest PC 0x0c041cd0 */
if(!s->budget--) { s->failed_pc=0x0c041cd0u; return 0; }
r[14]>>=2;
goto P_0c041cd2;
P_0c041cd2: /* original 2ee8, guest PC 0x0c041cd2 */
if(!s->budget--) { s->failed_pc=0x0c041cd2u; return 0; }
r[17]=(r[17]&~1u)|(((r[14]&r[14])==0)!=0);
goto P_0c041cd4;
P_0c041cd4: /* original 8b02, guest PC 0x0c041cd4 */
if(!s->budget--) { s->failed_pc=0x0c041cd4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c041cdc; }
goto P_0c041cd6;
P_0c041cd6: /* original e001, guest PC 0x0c041cd6 */
if(!s->budget--) { s->failed_pc=0x0c041cd6u; return 0; }
r[0]=0x00000001u;
goto P_0c041cd8;
P_0c041cd8: /* original a00d, guest PC 0x0c041cd8 */
if(!s->budget--) { s->failed_pc=0x0c041cd8u; return 0; }
goto P_0c041cf6;
P_0c041cda: /* original 0009, guest PC 0x0c041cda */
if(!s->budget--) { s->failed_pc=0x0c041cdau; return 0; }
goto P_0c041cdc;
P_0c041cdc: /* original 60e3, guest PC 0x0c041cdc */
if(!s->budget--) { s->failed_pc=0x0c041cdcu; return 0; }
r[0]=r[14];
goto P_0c041cde;
P_0c041cde: /* original 0009, guest PC 0x0c041cde */
if(!s->budget--) { s->failed_pc=0x0c041cdeu; return 0; }
goto P_0c041ce0;
P_0c041ce0: /* original a009, guest PC 0x0c041ce0 */
if(!s->budget--) { s->failed_pc=0x0c041ce0u; return 0; }
goto P_0c041cf6;
P_0c041ce2: /* original 0009, guest PC 0x0c041ce2 */
if(!s->budget--) { s->failed_pc=0x0c041ce2u; return 0; }
goto P_0c041ce4;
P_0c041ce4: /* original 52f2, guest PC 0x0c041ce4 */
if(!s->budget--) { s->failed_pc=0x0c041ce4u; return 0; }
r[2]=read(ram,r[15]+8,4);
goto P_0c041ce6;
P_0c041ce6: /* original e01e, guest PC 0x0c041ce6 */
if(!s->budget--) { s->failed_pc=0x0c041ce6u; return 0; }
r[0]=0x0000001eu;
goto P_0c041ce8;
P_0c041ce8: /* original 002c, guest PC 0x0c041ce8 */
if(!s->budget--) { s->failed_pc=0x0c041ce8u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[2]+r[0],1);
goto P_0c041cea;
P_0c041cea: /* original 600c, guest PC 0x0c041cea */
if(!s->budget--) { s->failed_pc=0x0c041ceau; return 0; }
r[0]=r[0]&255u;
goto P_0c041cec;
P_0c041cec: /* original a003, guest PC 0x0c041cec */
if(!s->budget--) { s->failed_pc=0x0c041cecu; return 0; }
goto P_0c041cf6;
P_0c041cee: /* original 0009, guest PC 0x0c041cee */
if(!s->budget--) { s->failed_pc=0x0c041ceeu; return 0; }
goto P_0c041cf0;
P_0c041cf0: /* original e0ff, guest PC 0x0c041cf0 */
if(!s->budget--) { s->failed_pc=0x0c041cf0u; return 0; }
r[0]=0xffffffffu;
goto P_0c041cf2;
P_0c041cf2: /* original a000, guest PC 0x0c041cf2 */
if(!s->budget--) { s->failed_pc=0x0c041cf2u; return 0; }
goto P_0c041cf6;
P_0c041cf4: /* original 0009, guest PC 0x0c041cf4 */
if(!s->budget--) { s->failed_pc=0x0c041cf4u; return 0; }
goto P_0c041cf6;
P_0c041cf6: /* original 7f0c, guest PC 0x0c041cf6 */
if(!s->budget--) { s->failed_pc=0x0c041cf6u; return 0; }
r[15]+=0x0000000cu;
goto P_0c041cf8;
P_0c041cf8: /* original 4f26, guest PC 0x0c041cf8 */
if(!s->budget--) { s->failed_pc=0x0c041cf8u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c041cfa;
P_0c041cfa: /* original 6cf6, guest PC 0x0c041cfa */
if(!s->budget--) { s->failed_pc=0x0c041cfau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c041cfc;
P_0c041cfc: /* original 6df6, guest PC 0x0c041cfc */
if(!s->budget--) { s->failed_pc=0x0c041cfcu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c041cfe;
P_0c041cfe: /* original 6ef6, guest PC 0x0c041cfe */
if(!s->budget--) { s->failed_pc=0x0c041cfeu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c041d00;
P_0c041d00: /* original 000b, guest PC 0x0c041d00 */
if(!s->budget--) { s->failed_pc=0x0c041d00u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c041d02: /* original 0009, guest PC 0x0c041d02 */
if(!s->budget--) { s->failed_pc=0x0c041d02u; return 0; }
return vf3_matrix_family(0x0c041d04u,s,ram);
unsupported: s->failed_pc=target; return 0;
}
static const uint32_t owned_pcs[]={
0x0c041b94u,0x0c041b96u,0x0c041b98u,0x0c041b9au,0x0c041b9cu,0x0c041b9eu,0x0c041ba0u,0x0c041ba2u,0x0c041ba4u,0x0c041ba6u,0x0c041ba8u,0x0c041baau,0x0c041bacu,0x0c041baeu,0x0c041bb0u,0x0c041bb2u,
0x0c041bb4u,0x0c041bb6u,0x0c041bb8u,0x0c041bbau,0x0c041bbcu,0x0c041bbeu,0x0c041bc0u,0x0c041bc2u,0x0c041bc4u,0x0c041bc6u,0x0c041bc8u,0x0c041bcau,0x0c041bccu,0x0c041bceu,0x0c041bd0u,0x0c041bd2u,
0x0c041bd4u,0x0c041bd6u,0x0c041bd8u,0x0c041bdau,0x0c041bdcu,0x0c041bdeu,0x0c041be0u,0x0c041be2u,0x0c041be4u,0x0c041be6u,0x0c041be8u,0x0c041beau,0x0c041becu,0x0c041beeu,0x0c041bf0u,0x0c041bf2u,
0x0c041bf4u,0x0c041bf6u,0x0c041bf8u,0x0c041bfau,0x0c041bfcu,0x0c041bfeu,0x0c041c00u,0x0c041c02u,0x0c041c04u,0x0c041c06u,0x0c041c08u,0x0c041c0au,0x0c041c0cu,0x0c041c0eu,0x0c041c10u,0x0c041c12u,
0x0c041c14u,0x0c041c16u,0x0c041c18u,0x0c041c1au,0x0c041c1cu,0x0c041c1eu,0x0c041c20u,0x0c041c22u,0x0c041c24u,0x0c041c26u,0x0c041c28u,0x0c041c2au,0x0c041c2cu,0x0c041c2eu,0x0c041c30u,0x0c041c32u,
0x0c041c34u,0x0c041c36u,0x0c041c38u,0x0c041c3au,0x0c041c3cu,0x0c041c3eu,0x0c041c40u,0x0c041c42u,0x0c041c44u,0x0c041c46u,0x0c041c48u,0x0c041c4au,0x0c041c4cu,0x0c041c4eu,0x0c041c50u,0x0c041c52u,
0x0c041c54u,0x0c041c56u,0x0c041c58u,0x0c041c5au,0x0c041c5cu,0x0c041c5eu,0x0c041c60u,0x0c041c62u,0x0c041c64u,0x0c041c66u,0x0c041c68u,0x0c041c6au,0x0c041c6cu,0x0c041c6eu,0x0c041c70u,0x0c041c72u,
0x0c041c74u,0x0c041c76u,0x0c041c78u,0x0c041c7au,0x0c041c7cu,0x0c041c84u,0x0c041c86u,0x0c041c88u,0x0c041c8au,0x0c041c8cu,0x0c041c8eu,0x0c041c90u,0x0c041c92u,0x0c041c94u,0x0c041c96u,0x0c041c98u,
0x0c041c9au,0x0c041c9cu,0x0c041c9eu,0x0c041ca0u,0x0c041ca2u,0x0c041ca4u,0x0c041ca6u,0x0c041ca8u,0x0c041caau,0x0c041cacu,0x0c041caeu,0x0c041cb0u,0x0c041cb2u,0x0c041cb4u,0x0c041cb6u,0x0c041cb8u,
0x0c041cbau,0x0c041cbcu,0x0c041cbeu,0x0c041cc0u,0x0c041cc2u,0x0c041cc4u,0x0c041cc6u,0x0c041cc8u,0x0c041ccau,0x0c041cccu,0x0c041cceu,0x0c041cd0u,0x0c041cd2u,0x0c041cd4u,0x0c041cd6u,0x0c041cd8u,
0x0c041cdau,0x0c041cdcu,0x0c041cdeu,0x0c041ce0u,0x0c041ce2u,0x0c041ce4u,0x0c041ce6u,0x0c041ce8u,0x0c041ceau,0x0c041cecu,0x0c041ceeu,0x0c041cf0u,0x0c041cf2u,0x0c041cf4u,0x0c041cf6u,0x0c041cf8u,
0x0c041cfau,0x0c041cfcu,0x0c041cfeu,0x0c041d00u,0x0c041d02u,
};
int vf3_advance_leaf_ranked_remainder_adapter_contains(uint32_t pc) {
pc&=0x1fffffffu; unsigned lo=0,hi=sizeof(owned_pcs)/sizeof(owned_pcs[0]);
while(lo<hi) { unsigned mid=lo+(hi-lo)/2; if(owned_pcs[mid]<pc) lo=mid+1; else hi=mid; }
return lo<sizeof(owned_pcs)/sizeof(owned_pcs[0]) && owned_pcs[lo]==pc;
}
