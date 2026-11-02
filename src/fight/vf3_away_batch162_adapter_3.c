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
int vf3_away_batch162_adapter_3(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c0c3b40u: goto P_0c0c3b40;
case 0x0c0c3b42u: goto P_0c0c3b42;
case 0x0c0c3b44u: goto P_0c0c3b44;
case 0x0c0c3b46u: goto P_0c0c3b46;
case 0x0c0c3b48u: goto P_0c0c3b48;
case 0x0c0c3b4au: goto P_0c0c3b4a;
case 0x0c0c3b4cu: goto P_0c0c3b4c;
case 0x0c0c3b4eu: goto P_0c0c3b4e;
case 0x0c0c3b50u: goto P_0c0c3b50;
case 0x0c0c3b52u: goto P_0c0c3b52;
case 0x0c0c3b54u: goto P_0c0c3b54;
case 0x0c0c3b56u: goto P_0c0c3b56;
case 0x0c0c3b58u: goto P_0c0c3b58;
case 0x0c0c3b5au: goto P_0c0c3b5a;
case 0x0c0c3b5cu: goto P_0c0c3b5c;
case 0x0c0c3b5eu: goto P_0c0c3b5e;
case 0x0c0c3b60u: goto P_0c0c3b60;
case 0x0c0c3b62u: goto P_0c0c3b62;
case 0x0c0c3b64u: goto P_0c0c3b64;
case 0x0c0c3b66u: goto P_0c0c3b66;
case 0x0c0c3b68u: goto P_0c0c3b68;
case 0x0c0c3b6au: goto P_0c0c3b6a;
case 0x0c0c3b6cu: goto P_0c0c3b6c;
case 0x0c0c3b6eu: goto P_0c0c3b6e;
case 0x0c0c3b70u: goto P_0c0c3b70;
case 0x0c0c3b72u: goto P_0c0c3b72;
case 0x0c0c3b74u: goto P_0c0c3b74;
case 0x0c0c3b76u: goto P_0c0c3b76;
case 0x0c0c3b78u: goto P_0c0c3b78;
case 0x0c0c3b7au: goto P_0c0c3b7a;
case 0x0c0c3b7cu: goto P_0c0c3b7c;
case 0x0c0c3b7eu: goto P_0c0c3b7e;
case 0x0c0c3b80u: goto P_0c0c3b80;
case 0x0c0c3b82u: goto P_0c0c3b82;
case 0x0c0c3ba4u: goto P_0c0c3ba4;
case 0x0c0c3ba6u: goto P_0c0c3ba6;
case 0x0c0c3ba8u: goto P_0c0c3ba8;
case 0x0c0c3baau: goto P_0c0c3baa;
case 0x0c0c3bacu: goto P_0c0c3bac;
case 0x0c0c3baeu: goto P_0c0c3bae;
case 0x0c0c3bb0u: goto P_0c0c3bb0;
case 0x0c0c3bb2u: goto P_0c0c3bb2;
case 0x0c0c3bb4u: goto P_0c0c3bb4;
case 0x0c0c3bb6u: goto P_0c0c3bb6;
case 0x0c0c3bb8u: goto P_0c0c3bb8;
case 0x0c0c3bbau: goto P_0c0c3bba;
case 0x0c0c3bbcu: goto P_0c0c3bbc;
case 0x0c0c3bbeu: goto P_0c0c3bbe;
case 0x0c0c3bc0u: goto P_0c0c3bc0;
case 0x0c0c3bc2u: goto P_0c0c3bc2;
case 0x0c0c3bc4u: goto P_0c0c3bc4;
case 0x0c0c3bc6u: goto P_0c0c3bc6;
case 0x0c0c3bc8u: goto P_0c0c3bc8;
case 0x0c0c3bcau: goto P_0c0c3bca;
case 0x0c0c3bccu: goto P_0c0c3bcc;
case 0x0c0c3bceu: goto P_0c0c3bce;
case 0x0c0c3bd0u: goto P_0c0c3bd0;
case 0x0c0c3bd2u: goto P_0c0c3bd2;
case 0x0c0c3bd4u: goto P_0c0c3bd4;
case 0x0c0c3bd6u: goto P_0c0c3bd6;
case 0x0c0c3bd8u: goto P_0c0c3bd8;
case 0x0c0c3bdau: goto P_0c0c3bda;
case 0x0c0c3bdcu: goto P_0c0c3bdc;
case 0x0c0c3bdeu: goto P_0c0c3bde;
case 0x0c0c3be0u: goto P_0c0c3be0;
case 0x0c0c3be2u: goto P_0c0c3be2;
case 0x0c0c3be4u: goto P_0c0c3be4;
case 0x0c0c3be6u: goto P_0c0c3be6;
case 0x0c0c3be8u: goto P_0c0c3be8;
case 0x0c0c3beau: goto P_0c0c3bea;
case 0x0c0c3becu: goto P_0c0c3bec;
case 0x0c0c3beeu: goto P_0c0c3bee;
case 0x0c0c3bf0u: goto P_0c0c3bf0;
case 0x0c0c3bf2u: goto P_0c0c3bf2;
case 0x0c0c3bf4u: goto P_0c0c3bf4;
case 0x0c0c3bf6u: goto P_0c0c3bf6;
case 0x0c0c3bf8u: goto P_0c0c3bf8;
case 0x0c0c3bfau: goto P_0c0c3bfa;
case 0x0c0c3bfcu: goto P_0c0c3bfc;
case 0x0c0c3bfeu: goto P_0c0c3bfe;
case 0x0c0c3c00u: goto P_0c0c3c00;
case 0x0c0c3c02u: goto P_0c0c3c02;
case 0x0c0c3c04u: goto P_0c0c3c04;
case 0x0c0c3c06u: goto P_0c0c3c06;
case 0x0c0c3c08u: goto P_0c0c3c08;
case 0x0c0c3c0au: goto P_0c0c3c0a;
case 0x0c0c3c0cu: goto P_0c0c3c0c;
case 0x0c0c3c0eu: goto P_0c0c3c0e;
case 0x0c0c3c10u: goto P_0c0c3c10;
case 0x0c0c3c12u: goto P_0c0c3c12;
case 0x0c0c3c14u: goto P_0c0c3c14;
case 0x0c0c3c16u: goto P_0c0c3c16;
case 0x0c0c3c18u: goto P_0c0c3c18;
case 0x0c0c3c1au: goto P_0c0c3c1a;
case 0x0c0c3c1cu: goto P_0c0c3c1c;
case 0x0c0c3c1eu: goto P_0c0c3c1e;
case 0x0c0c3c20u: goto P_0c0c3c20;
case 0x0c0c3c22u: goto P_0c0c3c22;
case 0x0c0c3c24u: goto P_0c0c3c24;
case 0x0c0c3c26u: goto P_0c0c3c26;
case 0x0c0c3c28u: goto P_0c0c3c28;
case 0x0c0c3c2au: goto P_0c0c3c2a;
case 0x0c0c3c2cu: goto P_0c0c3c2c;
case 0x0c0c3c2eu: goto P_0c0c3c2e;
default: return vf3_matrix_family(target,s,ram);
}
P_0c0c3b40: /* original 2fe6, guest PC 0x0c0c3b40 */
if(!s->budget--) { s->failed_pc=0x0c0c3b40u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c3b42;
P_0c0c3b42: /* original 2fd6, guest PC 0x0c0c3b42 */
if(!s->budget--) { s->failed_pc=0x0c0c3b42u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c3b44;
P_0c0c3b44: /* original 2fc6, guest PC 0x0c0c3b44 */
if(!s->budget--) { s->failed_pc=0x0c0c3b44u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c3b46;
P_0c0c3b46: /* original d613, guest PC 0x0c0c3b46 */
if(!s->budget--) { s->failed_pc=0x0c0c3b46u; return 0; }
r[6]=read(ram,0x0c0c3b94u,4);
goto P_0c0c3b48;
P_0c0c3b48: /* original 7ff8, guest PC 0x0c0c3b48 */
if(!s->budget--) { s->failed_pc=0x0c0c3b48u; return 0; }
r[15]+=0xfffffff8u;
goto P_0c0c3b4a;
P_0c0c3b4a: /* original 901b, guest PC 0x0c0c3b4a */
if(!s->budget--) { s->failed_pc=0x0c0c3b4au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c3b84u,2);
goto P_0c0c3b4c;
P_0c0c3b4c: /* original d412, guest PC 0x0c0c3b4c */
if(!s->budget--) { s->failed_pc=0x0c0c3b4cu; return 0; }
r[4]=read(ram,0x0c0c3b98u,4);
goto P_0c0c3b4e;
P_0c0c3b4e: /* original 056e, guest PC 0x0c0c3b4e */
if(!s->budget--) { s->failed_pc=0x0c0c3b4eu; return 0; }
r[5]=read(ram,r[6]+r[0],4);
goto P_0c0c3b50;
P_0c0c3b50: /* original e029, guest PC 0x0c0c3b50 */
if(!s->budget--) { s->failed_pc=0x0c0c3b50u; return 0; }
r[0]=0x00000029u;
goto P_0c0c3b52;
P_0c0c3b52: /* original 6743, guest PC 0x0c0c3b52 */
if(!s->budget--) { s->failed_pc=0x0c0c3b52u; return 0; }
r[7]=r[4];
goto P_0c0c3b54;
P_0c0c3b54: /* original 0c7c, guest PC 0x0c0c3b54 */
if(!s->budget--) { s->failed_pc=0x0c0c3b54u; return 0; }
r[12]=(uint32_t)(int32_t)(int8_t)read(ram,r[7]+r[0],1);
goto P_0c0c3b56;
P_0c0c3b56: /* original e02a, guest PC 0x0c0c3b56 */
if(!s->budget--) { s->failed_pc=0x0c0c3b56u; return 0; }
r[0]=0x0000002au;
goto P_0c0c3b58;
P_0c0c3b58: /* original 9d15, guest PC 0x0c0c3b58 */
if(!s->budget--) { s->failed_pc=0x0c0c3b58u; return 0; }
r[13]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c3b86u,2);
goto P_0c0c3b5a;
P_0c0c3b5a: /* original 6ccc, guest PC 0x0c0c3b5a */
if(!s->budget--) { s->failed_pc=0x0c0c3b5au; return 0; }
r[12]=r[12]&255u;
goto P_0c0c3b5c;
P_0c0c3b5c: /* original 077c, guest PC 0x0c0c3b5c */
if(!s->budget--) { s->failed_pc=0x0c0c3b5cu; return 0; }
r[7]=(uint32_t)(int32_t)(int8_t)read(ram,r[7]+r[0],1);
goto P_0c0c3b5e;
P_0c0c3b5e: /* original 6ec3, guest PC 0x0c0c3b5e */
if(!s->budget--) { s->failed_pc=0x0c0c3b5eu; return 0; }
r[14]=r[12];
goto P_0c0c3b60;
P_0c0c3b60: /* original 7efd, guest PC 0x0c0c3b60 */
if(!s->budget--) { s->failed_pc=0x0c0c3b60u; return 0; }
r[14]+=0xfffffffdu;
goto P_0c0c3b62;
P_0c0c3b62: /* original 2ee8, guest PC 0x0c0c3b62 */
if(!s->budget--) { s->failed_pc=0x0c0c3b62u; return 0; }
r[17]=(r[17]&~1u)|(((r[14]&r[14])==0)!=0);
goto P_0c0c3b64;
P_0c0c3b64: /* original 3d4c, guest PC 0x0c0c3b64 */
if(!s->budget--) { s->failed_pc=0x0c0c3b64u; return 0; }
r[13]+=r[4];
goto P_0c0c3b66;
P_0c0c3b66: /* original 677c, guest PC 0x0c0c3b66 */
if(!s->budget--) { s->failed_pc=0x0c0c3b66u; return 0; }
r[7]=r[7]&255u;
goto P_0c0c3b68;
P_0c0c3b68: /* original 8d02, guest PC 0x0c0c3b68 */
if(!s->budget--) { s->failed_pc=0x0c0c3b68u; return 0; }
cond=r[17]&1u;
r[7]+=0xfffffffeu;
if(cond) { goto P_0c0c3b70; }
goto P_0c0c3b6c;
P_0c0c3b6a: /* original 77fe, guest PC 0x0c0c3b6a */
if(!s->budget--) { s->failed_pc=0x0c0c3b6au; return 0; }
r[7]+=0xfffffffeu;
goto P_0c0c3b6c;
P_0c0c3b6c: /* original 67c3, guest PC 0x0c0c3b6c */
if(!s->budget--) { s->failed_pc=0x0c0c3b6cu; return 0; }
r[7]=r[12];
goto P_0c0c3b6e;
P_0c0c3b6e: /* original 77fe, guest PC 0x0c0c3b6e */
if(!s->budget--) { s->failed_pc=0x0c0c3b6eu; return 0; }
r[7]+=0xfffffffeu;
goto P_0c0c3b70;
P_0c0c3b70: /* original 5342, guest PC 0x0c0c3b70 */
if(!s->budget--) { s->failed_pc=0x0c0c3b70u; return 0; }
r[3]=read(ram,r[4]+8,4);
goto P_0c0c3b72;
P_0c0c3b72: /* original 6033, guest PC 0x0c0c3b72 */
if(!s->budget--) { s->failed_pc=0x0c0c3b72u; return 0; }
r[0]=r[3];
goto P_0c0c3b74;
P_0c0c3b74: /* original c804, guest PC 0x0c0c3b74 */
if(!s->budget--) { s->failed_pc=0x0c0c3b74u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&4u)==0)!=0);
goto P_0c0c3b76;
P_0c0c3b76: /* original 2f32, guest PC 0x0c0c3b76 */
if(!s->budget--) { s->failed_pc=0x0c0c3b76u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c0c3b78;
P_0c0c3b78: /* original 8939, guest PC 0x0c0c3b78 */
if(!s->budget--) { s->failed_pc=0x0c0c3b78u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c3bee; }
goto P_0c0c3b7a;
P_0c0c3b7a: /* original 2778, guest PC 0x0c0c3b7a */
if(!s->budget--) { s->failed_pc=0x0c0c3b7au; return 0; }
r[17]=(r[17]&~1u)|(((r[7]&r[7])==0)!=0);
goto P_0c0c3b7c;
P_0c0c3b7c: /* original 8b12, guest PC 0x0c0c3b7c */
if(!s->budget--) { s->failed_pc=0x0c0c3b7cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c3ba4; }
goto P_0c0c3b7e;
P_0c0c3b7e: /* original 9c03, guest PC 0x0c0c3b7e */
if(!s->budget--) { s->failed_pc=0x0c0c3b7eu; return 0; }
r[12]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c3b88u,2);
goto P_0c0c3b80;
P_0c0c3b80: /* original a011, guest PC 0x0c0c3b80 */
if(!s->budget--) { s->failed_pc=0x0c0c3b80u; return 0; }
goto P_0c0c3ba6;
P_0c0c3b82: /* original 0009, guest PC 0x0c0c3b82 */
if(!s->budget--) { s->failed_pc=0x0c0c3b82u; return 0; }
if(!vf3_matrix_family(0x0c0c3b84u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0c3b84u; return 0; } return 1;
P_0c0c3ba4: /* original 9c75, guest PC 0x0c0c3ba4 */
if(!s->budget--) { s->failed_pc=0x0c0c3ba4u; return 0; }
r[12]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c3c92u,2);
goto P_0c0c3ba6;
P_0c0c3ba6: /* original 9075, guest PC 0x0c0c3ba6 */
if(!s->budget--) { s->failed_pc=0x0c0c3ba6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c3c94u,2);
goto P_0c0c3ba8;
P_0c0c3ba8: /* original ee00, guest PC 0x0c0c3ba8 */
if(!s->budget--) { s->failed_pc=0x0c0c3ba8u; return 0; }
r[14]=0x00000000u;
goto P_0c0c3baa;
P_0c0c3baa: /* original 3c4c, guest PC 0x0c0c3baa */
if(!s->budget--) { s->failed_pc=0x0c0c3baau; return 0; }
r[12]+=r[4];
goto P_0c0c3bac;
P_0c0c3bac: /* original 034c, guest PC 0x0c0c3bac */
if(!s->budget--) { s->failed_pc=0x0c0c3bacu; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c0c3bae;
P_0c0c3bae: /* original 2f32, guest PC 0x0c0c3bae */
if(!s->budget--) { s->failed_pc=0x0c0c3baeu; return 0; }
write(ram,r[15],r[3],4);
goto P_0c0c3bb0;
P_0c0c3bb0: /* original 60e3, guest PC 0x0c0c3bb0 */
if(!s->budget--) { s->failed_pc=0x0c0c3bb0u; return 0; }
r[0]=r[14];
goto P_0c0c3bb2;
P_0c0c3bb2: /* original 04cc, guest PC 0x0c0c3bb2 */
if(!s->budget--) { s->failed_pc=0x0c0c3bb2u; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[12]+r[0],1);
goto P_0c0c3bb4;
P_0c0c3bb4: /* original e30d, guest PC 0x0c0c3bb4 */
if(!s->budget--) { s->failed_pc=0x0c0c3bb4u; return 0; }
r[3]=0x0000000du;
goto P_0c0c3bb6;
P_0c0c3bb6: /* original 644c, guest PC 0x0c0c3bb6 */
if(!s->budget--) { s->failed_pc=0x0c0c3bb6u; return 0; }
r[4]=r[4]&255u;
goto P_0c0c3bb8;
P_0c0c3bb8: /* original 3432, guest PC 0x0c0c3bb8 */
if(!s->budget--) { s->failed_pc=0x0c0c3bb8u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>=r[3])!=0);
goto P_0c0c3bba;
P_0c0c3bba: /* original 8b00, guest PC 0x0c0c3bba */
if(!s->budget--) { s->failed_pc=0x0c0c3bbau; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c3bbe; }
goto P_0c0c3bbc;
P_0c0c3bbc: /* original 74f3, guest PC 0x0c0c3bbc */
if(!s->budget--) { s->failed_pc=0x0c0c3bbcu; return 0; }
r[4]+=0xfffffff3u;
goto P_0c0c3bbe;
P_0c0c3bbe: /* original 6743, guest PC 0x0c0c3bbe */
if(!s->budget--) { s->failed_pc=0x0c0c3bbeu; return 0; }
r[7]=r[4];
goto P_0c0c3bc0;
P_0c0c3bc0: /* original 37dc, guest PC 0x0c0c3bc0 */
if(!s->budget--) { s->failed_pc=0x0c0c3bc0u; return 0; }
r[7]+=r[13];
goto P_0c0c3bc2;
P_0c0c3bc2: /* original 1f71, guest PC 0x0c0c3bc2 */
if(!s->budget--) { s->failed_pc=0x0c0c3bc2u; return 0; }
write(ram,r[15]+4,r[7],4);
goto P_0c0c3bc4;
P_0c0c3bc4: /* original 6770, guest PC 0x0c0c3bc4 */
if(!s->budget--) { s->failed_pc=0x0c0c3bc4u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[7],1);
r[7]=tmp;
goto P_0c0c3bc6;
P_0c0c3bc6: /* original 53f1, guest PC 0x0c0c3bc6 */
if(!s->budget--) { s->failed_pc=0x0c0c3bc6u; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c0c3bc8;
P_0c0c3bc8: /* original 677c, guest PC 0x0c0c3bc8 */
if(!s->budget--) { s->failed_pc=0x0c0c3bc8u; return 0; }
r[7]=r[7]&255u;
goto P_0c0c3bca;
P_0c0c3bca: /* original 77ff, guest PC 0x0c0c3bca */
if(!s->budget--) { s->failed_pc=0x0c0c3bcau; return 0; }
r[7]+=0xffffffffu;
goto P_0c0c3bcc;
P_0c0c3bcc: /* original 2370, guest PC 0x0c0c3bcc */
if(!s->budget--) { s->failed_pc=0x0c0c3bccu; return 0; }
write(ram,r[3],r[7],1);
goto P_0c0c3bce;
P_0c0c3bce: /* original e300, guest PC 0x0c0c3bce */
if(!s->budget--) { s->failed_pc=0x0c0c3bceu; return 0; }
r[3]=0x00000000u;
goto P_0c0c3bd0;
P_0c0c3bd0: /* original 3736, guest PC 0x0c0c3bd0 */
if(!s->budget--) { s->failed_pc=0x0c0c3bd0u; return 0; }
r[17]=(r[17]&~1u)|((r[7]>r[3])!=0);
goto P_0c0c3bd2;
P_0c0c3bd2: /* original 8d07, guest PC 0x0c0c3bd2 */
if(!s->budget--) { s->failed_pc=0x0c0c3bd2u; return 0; }
cond=r[17]&1u;
r[14]+=0x00000001u;
if(cond) { goto P_0c0c3be4; }
goto P_0c0c3bd6;
P_0c0c3bd4: /* original 7e01, guest PC 0x0c0c3bd4 */
if(!s->budget--) { s->failed_pc=0x0c0c3bd4u; return 0; }
r[14]+=0x00000001u;
goto P_0c0c3bd6;
P_0c0c3bd6: /* original d231, guest PC 0x0c0c3bd6 */
if(!s->budget--) { s->failed_pc=0x0c0c3bd6u; return 0; }
r[2]=read(ram,0x0c0c3c9cu,4);
goto P_0c0c3bd8;
P_0c0c3bd8: /* original 644b, guest PC 0x0c0c3bd8 */
if(!s->budget--) { s->failed_pc=0x0c0c3bd8u; return 0; }
r[4]=0u-r[4];
goto P_0c0c3bda;
P_0c0c3bda: /* original 905c, guest PC 0x0c0c3bda */
if(!s->budget--) { s->failed_pc=0x0c0c3bdau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c3c96u,2);
goto P_0c0c3bdc;
P_0c0c3bdc: /* original 424d, guest PC 0x0c0c3bdc */
if(!s->budget--) { s->failed_pc=0x0c0c3bdcu; return 0; }
r[2]=(r[4]&0x80000000u)?((r[4]&31u)?r[2]>>((-r[4])&31u):0):r[2]<<(r[4]&31u);
goto P_0c0c3bde;
P_0c0c3bde: /* original 6227, guest PC 0x0c0c3bde */
if(!s->budget--) { s->failed_pc=0x0c0c3bdeu; return 0; }
r[2]=~r[2];
goto P_0c0c3be0;
P_0c0c3be0: /* original 2529, guest PC 0x0c0c3be0 */
if(!s->budget--) { s->failed_pc=0x0c0c3be0u; return 0; }
r[5]&=r[2];
goto P_0c0c3be2;
P_0c0c3be2: /* original 0656, guest PC 0x0c0c3be2 */
if(!s->budget--) { s->failed_pc=0x0c0c3be2u; return 0; }
write(ram,r[6]+r[0],r[5],4);
goto P_0c0c3be4;
P_0c0c3be4: /* original 63f2, guest PC 0x0c0c3be4 */
if(!s->budget--) { s->failed_pc=0x0c0c3be4u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c0c3be6;
P_0c0c3be6: /* original 3e32, guest PC 0x0c0c3be6 */
if(!s->budget--) { s->failed_pc=0x0c0c3be6u; return 0; }
r[17]=(r[17]&~1u)|((r[14]>=r[3])!=0);
goto P_0c0c3be8;
P_0c0c3be8: /* original 8be2, guest PC 0x0c0c3be8 */
if(!s->budget--) { s->failed_pc=0x0c0c3be8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c3bb0; }
goto P_0c0c3bea;
P_0c0c3bea: /* original a01c, guest PC 0x0c0c3bea */
if(!s->budget--) { s->failed_pc=0x0c0c3beau; return 0; }
goto P_0c0c3c26;
P_0c0c3bec: /* original 0009, guest PC 0x0c0c3bec */
if(!s->budget--) { s->failed_pc=0x0c0c3becu; return 0; }
goto P_0c0c3bee;
P_0c0c3bee: /* original 2ee8, guest PC 0x0c0c3bee */
if(!s->budget--) { s->failed_pc=0x0c0c3beeu; return 0; }
r[17]=(r[17]&~1u)|(((r[14]&r[14])==0)!=0);
goto P_0c0c3bf0;
P_0c0c3bf0: /* original 8b19, guest PC 0x0c0c3bf0 */
if(!s->budget--) { s->failed_pc=0x0c0c3bf0u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c3c26; }
goto P_0c0c3bf2;
P_0c0c3bf2: /* original d12b, guest PC 0x0c0c3bf2 */
if(!s->budget--) { s->failed_pc=0x0c0c3bf2u; return 0; }
r[1]=read(ram,0x0c0c3ca0u,4);
goto P_0c0c3bf4;
P_0c0c3bf4: /* original 2778, guest PC 0x0c0c3bf4 */
if(!s->budget--) { s->failed_pc=0x0c0c3bf4u; return 0; }
r[17]=(r[17]&~1u)|(((r[7]&r[7])==0)!=0);
goto P_0c0c3bf6;
P_0c0c3bf6: /* original 8d02, guest PC 0x0c0c3bf6 */
if(!s->budget--) { s->failed_pc=0x0c0c3bf6u; return 0; }
cond=r[17]&1u;
tmp=read(ram,r[1],4);
r[4]=tmp;
if(cond) { goto P_0c0c3bfe; }
goto P_0c0c3bfa;
P_0c0c3bf8: /* original 6412, guest PC 0x0c0c3bf8 */
if(!s->budget--) { s->failed_pc=0x0c0c3bf8u; return 0; }
tmp=read(ram,r[1],4);
r[4]=tmp;
goto P_0c0c3bfa;
P_0c0c3bfa: /* original d22a, guest PC 0x0c0c3bfa */
if(!s->budget--) { s->failed_pc=0x0c0c3bfau; return 0; }
r[2]=read(ram,0x0c0c3ca4u,4);
goto P_0c0c3bfc;
P_0c0c3bfc: /* original 6422, guest PC 0x0c0c3bfc */
if(!s->budget--) { s->failed_pc=0x0c0c3bfcu; return 0; }
tmp=read(ram,r[2],4);
r[4]=tmp;
goto P_0c0c3bfe;
P_0c0c3bfe: /* original e061, guest PC 0x0c0c3bfe */
if(!s->budget--) { s->failed_pc=0x0c0c3bfeu; return 0; }
r[0]=0x00000061u;
goto P_0c0c3c00;
P_0c0c3c00: /* original 074c, guest PC 0x0c0c3c00 */
if(!s->budget--) { s->failed_pc=0x0c0c3c00u; return 0; }
r[7]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c0c3c02;
P_0c0c3c02: /* original 677c, guest PC 0x0c0c3c02 */
if(!s->budget--) { s->failed_pc=0x0c0c3c02u; return 0; }
r[7]=r[7]&255u;
goto P_0c0c3c04;
P_0c0c3c04: /* original 6473, guest PC 0x0c0c3c04 */
if(!s->budget--) { s->failed_pc=0x0c0c3c04u; return 0; }
r[4]=r[7];
goto P_0c0c3c06;
P_0c0c3c06: /* original 34dc, guest PC 0x0c0c3c06 */
if(!s->budget--) { s->failed_pc=0x0c0c3c06u; return 0; }
r[4]+=r[13];
goto P_0c0c3c08;
P_0c0c3c08: /* original 2f42, guest PC 0x0c0c3c08 */
if(!s->budget--) { s->failed_pc=0x0c0c3c08u; return 0; }
write(ram,r[15],r[4],4);
goto P_0c0c3c0a;
P_0c0c3c0a: /* original 6440, guest PC 0x0c0c3c0a */
if(!s->budget--) { s->failed_pc=0x0c0c3c0au; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[4],1);
r[4]=tmp;
goto P_0c0c3c0c;
P_0c0c3c0c: /* original 63f2, guest PC 0x0c0c3c0c */
if(!s->budget--) { s->failed_pc=0x0c0c3c0cu; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c0c3c0e;
P_0c0c3c0e: /* original 644c, guest PC 0x0c0c3c0e */
if(!s->budget--) { s->failed_pc=0x0c0c3c0eu; return 0; }
r[4]=r[4]&255u;
goto P_0c0c3c10;
P_0c0c3c10: /* original 74ff, guest PC 0x0c0c3c10 */
if(!s->budget--) { s->failed_pc=0x0c0c3c10u; return 0; }
r[4]+=0xffffffffu;
goto P_0c0c3c12;
P_0c0c3c12: /* original 2448, guest PC 0x0c0c3c12 */
if(!s->budget--) { s->failed_pc=0x0c0c3c12u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c0c3c14;
P_0c0c3c14: /* original 2340, guest PC 0x0c0c3c14 */
if(!s->budget--) { s->failed_pc=0x0c0c3c14u; return 0; }
write(ram,r[3],r[4],1);
goto P_0c0c3c16;
P_0c0c3c16: /* original 8b06, guest PC 0x0c0c3c16 */
if(!s->budget--) { s->failed_pc=0x0c0c3c16u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c3c26; }
goto P_0c0c3c18;
P_0c0c3c18: /* original d320, guest PC 0x0c0c3c18 */
if(!s->budget--) { s->failed_pc=0x0c0c3c18u; return 0; }
r[3]=read(ram,0x0c0c3c9cu,4);
goto P_0c0c3c1a;
P_0c0c3c1a: /* original 677b, guest PC 0x0c0c3c1a */
if(!s->budget--) { s->failed_pc=0x0c0c3c1au; return 0; }
r[7]=0u-r[7];
goto P_0c0c3c1c;
P_0c0c3c1c: /* original 903b, guest PC 0x0c0c3c1c */
if(!s->budget--) { s->failed_pc=0x0c0c3c1cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c3c96u,2);
goto P_0c0c3c1e;
P_0c0c3c1e: /* original 437d, guest PC 0x0c0c3c1e */
if(!s->budget--) { s->failed_pc=0x0c0c3c1eu; return 0; }
r[3]=(r[7]&0x80000000u)?((r[7]&31u)?r[3]>>((-r[7])&31u):0):r[3]<<(r[7]&31u);
goto P_0c0c3c20;
P_0c0c3c20: /* original 6337, guest PC 0x0c0c3c20 */
if(!s->budget--) { s->failed_pc=0x0c0c3c20u; return 0; }
r[3]=~r[3];
goto P_0c0c3c22;
P_0c0c3c22: /* original 2539, guest PC 0x0c0c3c22 */
if(!s->budget--) { s->failed_pc=0x0c0c3c22u; return 0; }
r[5]&=r[3];
goto P_0c0c3c24;
P_0c0c3c24: /* original 0656, guest PC 0x0c0c3c24 */
if(!s->budget--) { s->failed_pc=0x0c0c3c24u; return 0; }
write(ram,r[6]+r[0],r[5],4);
goto P_0c0c3c26;
P_0c0c3c26: /* original 7f08, guest PC 0x0c0c3c26 */
if(!s->budget--) { s->failed_pc=0x0c0c3c26u; return 0; }
r[15]+=0x00000008u;
goto P_0c0c3c28;
P_0c0c3c28: /* original 6cf6, guest PC 0x0c0c3c28 */
if(!s->budget--) { s->failed_pc=0x0c0c3c28u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0c3c2a;
P_0c0c3c2a: /* original 6df6, guest PC 0x0c0c3c2a */
if(!s->budget--) { s->failed_pc=0x0c0c3c2au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0c3c2c;
P_0c0c3c2c: /* original 000b, guest PC 0x0c0c3c2c */
if(!s->budget--) { s->failed_pc=0x0c0c3c2cu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0c3c2e: /* original 6ef6, guest PC 0x0c0c3c2e */
if(!s->budget--) { s->failed_pc=0x0c0c3c2eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0c3c30u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0c3c30u; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
