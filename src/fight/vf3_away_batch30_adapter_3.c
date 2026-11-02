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
int vf3_away_batch30_adapter_3(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c0609aeu: goto P_0c0609ae;
case 0x0c0609b0u: goto P_0c0609b0;
case 0x0c0609b2u: goto P_0c0609b2;
case 0x0c0609b4u: goto P_0c0609b4;
case 0x0c0609b6u: goto P_0c0609b6;
case 0x0c0609b8u: goto P_0c0609b8;
case 0x0c0609bau: goto P_0c0609ba;
case 0x0c0609bcu: goto P_0c0609bc;
case 0x0c0609beu: goto P_0c0609be;
case 0x0c0609c0u: goto P_0c0609c0;
case 0x0c0609c2u: goto P_0c0609c2;
case 0x0c0609c4u: goto P_0c0609c4;
case 0x0c0609c6u: goto P_0c0609c6;
case 0x0c0609c8u: goto P_0c0609c8;
case 0x0c0609cau: goto P_0c0609ca;
case 0x0c0609ccu: goto P_0c0609cc;
case 0x0c0609ceu: goto P_0c0609ce;
case 0x0c0609d0u: goto P_0c0609d0;
case 0x0c0609d2u: goto P_0c0609d2;
case 0x0c0609d4u: goto P_0c0609d4;
case 0x0c0609d6u: goto P_0c0609d6;
case 0x0c0609d8u: goto P_0c0609d8;
case 0x0c0609dau: goto P_0c0609da;
case 0x0c0609dcu: goto P_0c0609dc;
case 0x0c0609deu: goto P_0c0609de;
case 0x0c0609e0u: goto P_0c0609e0;
case 0x0c0609e2u: goto P_0c0609e2;
case 0x0c0609e4u: goto P_0c0609e4;
case 0x0c0609e6u: goto P_0c0609e6;
case 0x0c0609e8u: goto P_0c0609e8;
case 0x0c0609eau: goto P_0c0609ea;
case 0x0c0609ecu: goto P_0c0609ec;
case 0x0c0609eeu: goto P_0c0609ee;
case 0x0c0609f0u: goto P_0c0609f0;
case 0x0c0609f2u: goto P_0c0609f2;
case 0x0c0609f4u: goto P_0c0609f4;
case 0x0c0609f6u: goto P_0c0609f6;
case 0x0c0609f8u: goto P_0c0609f8;
case 0x0c0609fau: goto P_0c0609fa;
case 0x0c0609fcu: goto P_0c0609fc;
case 0x0c0609feu: goto P_0c0609fe;
case 0x0c060a00u: goto P_0c060a00;
case 0x0c060a02u: goto P_0c060a02;
case 0x0c060a04u: goto P_0c060a04;
case 0x0c060a06u: goto P_0c060a06;
case 0x0c060a08u: goto P_0c060a08;
case 0x0c060a0au: goto P_0c060a0a;
case 0x0c060a0cu: goto P_0c060a0c;
case 0x0c060a0eu: goto P_0c060a0e;
case 0x0c060a10u: goto P_0c060a10;
case 0x0c060a12u: goto P_0c060a12;
case 0x0c060a14u: goto P_0c060a14;
case 0x0c060a16u: goto P_0c060a16;
case 0x0c060a18u: goto P_0c060a18;
case 0x0c060a1au: goto P_0c060a1a;
case 0x0c060a1cu: goto P_0c060a1c;
case 0x0c060a1eu: goto P_0c060a1e;
case 0x0c060a20u: goto P_0c060a20;
case 0x0c060a22u: goto P_0c060a22;
case 0x0c060a24u: goto P_0c060a24;
case 0x0c060a26u: goto P_0c060a26;
case 0x0c060a28u: goto P_0c060a28;
case 0x0c060a2au: goto P_0c060a2a;
case 0x0c060a2cu: goto P_0c060a2c;
case 0x0c060a2eu: goto P_0c060a2e;
case 0x0c060a30u: goto P_0c060a30;
case 0x0c060a32u: goto P_0c060a32;
case 0x0c060a34u: goto P_0c060a34;
case 0x0c060a36u: goto P_0c060a36;
case 0x0c060a38u: goto P_0c060a38;
case 0x0c060a3au: goto P_0c060a3a;
case 0x0c060a3cu: goto P_0c060a3c;
case 0x0c060a3eu: goto P_0c060a3e;
case 0x0c060a40u: goto P_0c060a40;
case 0x0c060a42u: goto P_0c060a42;
case 0x0c060a44u: goto P_0c060a44;
case 0x0c060a46u: goto P_0c060a46;
case 0x0c060a48u: goto P_0c060a48;
case 0x0c060a4au: goto P_0c060a4a;
case 0x0c060a78u: goto P_0c060a78;
case 0x0c060a7au: goto P_0c060a7a;
case 0x0c060a7cu: goto P_0c060a7c;
case 0x0c060a7eu: goto P_0c060a7e;
case 0x0c060a80u: goto P_0c060a80;
case 0x0c060a82u: goto P_0c060a82;
case 0x0c060a84u: goto P_0c060a84;
case 0x0c060a86u: goto P_0c060a86;
case 0x0c060a88u: goto P_0c060a88;
case 0x0c060a8au: goto P_0c060a8a;
case 0x0c060a8cu: goto P_0c060a8c;
case 0x0c060a8eu: goto P_0c060a8e;
case 0x0c060a90u: goto P_0c060a90;
case 0x0c060a92u: goto P_0c060a92;
case 0x0c060a94u: goto P_0c060a94;
case 0x0c060a96u: goto P_0c060a96;
case 0x0c060a98u: goto P_0c060a98;
case 0x0c060a9au: goto P_0c060a9a;
case 0x0c060a9cu: goto P_0c060a9c;
case 0x0c060a9eu: goto P_0c060a9e;
case 0x0c060aa0u: goto P_0c060aa0;
case 0x0c060aa2u: goto P_0c060aa2;
case 0x0c060aa4u: goto P_0c060aa4;
case 0x0c060aa6u: goto P_0c060aa6;
case 0x0c060aa8u: goto P_0c060aa8;
case 0x0c060aaau: goto P_0c060aaa;
case 0x0c060aacu: goto P_0c060aac;
case 0x0c060aaeu: goto P_0c060aae;
case 0x0c060ab0u: goto P_0c060ab0;
case 0x0c060ab2u: goto P_0c060ab2;
case 0x0c060ab4u: goto P_0c060ab4;
case 0x0c060ab6u: goto P_0c060ab6;
case 0x0c060ab8u: goto P_0c060ab8;
case 0x0c060abau: goto P_0c060aba;
case 0x0c060abcu: goto P_0c060abc;
case 0x0c060abeu: goto P_0c060abe;
case 0x0c060ac0u: goto P_0c060ac0;
case 0x0c060ac2u: goto P_0c060ac2;
case 0x0c060ac4u: goto P_0c060ac4;
case 0x0c060ac6u: goto P_0c060ac6;
case 0x0c060ac8u: goto P_0c060ac8;
case 0x0c060acau: goto P_0c060aca;
case 0x0c060accu: goto P_0c060acc;
case 0x0c060aceu: goto P_0c060ace;
case 0x0c060ad0u: goto P_0c060ad0;
case 0x0c060ad2u: goto P_0c060ad2;
case 0x0c060ad4u: goto P_0c060ad4;
case 0x0c060ad6u: goto P_0c060ad6;
case 0x0c060ad8u: goto P_0c060ad8;
case 0x0c060adau: goto P_0c060ada;
case 0x0c060adcu: goto P_0c060adc;
case 0x0c060adeu: goto P_0c060ade;
case 0x0c060ae0u: goto P_0c060ae0;
case 0x0c060ae2u: goto P_0c060ae2;
case 0x0c060ae4u: goto P_0c060ae4;
case 0x0c060ae6u: goto P_0c060ae6;
case 0x0c060ae8u: goto P_0c060ae8;
case 0x0c060aeau: goto P_0c060aea;
case 0x0c060aecu: goto P_0c060aec;
case 0x0c060aeeu: goto P_0c060aee;
case 0x0c060af0u: goto P_0c060af0;
case 0x0c060af2u: goto P_0c060af2;
case 0x0c060af4u: goto P_0c060af4;
case 0x0c060af6u: goto P_0c060af6;
case 0x0c060af8u: goto P_0c060af8;
case 0x0c060afau: goto P_0c060afa;
case 0x0c060afcu: goto P_0c060afc;
case 0x0c060afeu: goto P_0c060afe;
case 0x0c060b00u: goto P_0c060b00;
case 0x0c060b02u: goto P_0c060b02;
case 0x0c060b04u: goto P_0c060b04;
case 0x0c060b06u: goto P_0c060b06;
case 0x0c060b08u: goto P_0c060b08;
case 0x0c060b0au: goto P_0c060b0a;
case 0x0c060b0cu: goto P_0c060b0c;
case 0x0c060b0eu: goto P_0c060b0e;
case 0x0c060b10u: goto P_0c060b10;
case 0x0c060b12u: goto P_0c060b12;
case 0x0c060b14u: goto P_0c060b14;
case 0x0c060b16u: goto P_0c060b16;
case 0x0c060b18u: goto P_0c060b18;
case 0x0c060b1au: goto P_0c060b1a;
case 0x0c060b1cu: goto P_0c060b1c;
case 0x0c060b2cu: goto P_0c060b2c;
case 0x0c060b2eu: goto P_0c060b2e;
case 0x0c060b30u: goto P_0c060b30;
case 0x0c060b32u: goto P_0c060b32;
case 0x0c060b34u: goto P_0c060b34;
case 0x0c060b36u: goto P_0c060b36;
case 0x0c060b38u: goto P_0c060b38;
case 0x0c060b3au: goto P_0c060b3a;
case 0x0c060b3cu: goto P_0c060b3c;
case 0x0c060b3eu: goto P_0c060b3e;
case 0x0c060b40u: goto P_0c060b40;
case 0x0c060b42u: goto P_0c060b42;
case 0x0c060b44u: goto P_0c060b44;
case 0x0c060b46u: goto P_0c060b46;
case 0x0c060b48u: goto P_0c060b48;
case 0x0c060b4au: goto P_0c060b4a;
case 0x0c060b4cu: goto P_0c060b4c;
case 0x0c060b4eu: goto P_0c060b4e;
case 0x0c060b50u: goto P_0c060b50;
case 0x0c060b52u: goto P_0c060b52;
case 0x0c060b54u: goto P_0c060b54;
case 0x0c060b56u: goto P_0c060b56;
case 0x0c060b58u: goto P_0c060b58;
case 0x0c060b5au: goto P_0c060b5a;
case 0x0c060b5cu: goto P_0c060b5c;
case 0x0c060b5eu: goto P_0c060b5e;
case 0x0c060b60u: goto P_0c060b60;
case 0x0c060b62u: goto P_0c060b62;
case 0x0c060b64u: goto P_0c060b64;
case 0x0c060b66u: goto P_0c060b66;
case 0x0c060b68u: goto P_0c060b68;
case 0x0c060b6au: goto P_0c060b6a;
case 0x0c060b6cu: goto P_0c060b6c;
case 0x0c060b6eu: goto P_0c060b6e;
case 0x0c060b70u: goto P_0c060b70;
case 0x0c060b72u: goto P_0c060b72;
case 0x0c060b74u: goto P_0c060b74;
case 0x0c060b76u: goto P_0c060b76;
case 0x0c060b78u: goto P_0c060b78;
case 0x0c060b7au: goto P_0c060b7a;
case 0x0c060b7cu: goto P_0c060b7c;
case 0x0c060b7eu: goto P_0c060b7e;
case 0x0c060b80u: goto P_0c060b80;
case 0x0c060b82u: goto P_0c060b82;
case 0x0c060b84u: goto P_0c060b84;
case 0x0c060b86u: goto P_0c060b86;
case 0x0c060b88u: goto P_0c060b88;
case 0x0c060b8au: goto P_0c060b8a;
case 0x0c060b8cu: goto P_0c060b8c;
case 0x0c060b8eu: goto P_0c060b8e;
case 0x0c060b90u: goto P_0c060b90;
case 0x0c060b92u: goto P_0c060b92;
case 0x0c060b94u: goto P_0c060b94;
case 0x0c060b96u: goto P_0c060b96;
case 0x0c060b98u: goto P_0c060b98;
case 0x0c060b9au: goto P_0c060b9a;
case 0x0c060b9cu: goto P_0c060b9c;
case 0x0c060b9eu: goto P_0c060b9e;
case 0x0c060ba0u: goto P_0c060ba0;
case 0x0c060ba2u: goto P_0c060ba2;
case 0x0c060ba4u: goto P_0c060ba4;
case 0x0c060ba6u: goto P_0c060ba6;
case 0x0c060ba8u: goto P_0c060ba8;
case 0x0c060baau: goto P_0c060baa;
case 0x0c060bacu: goto P_0c060bac;
case 0x0c060baeu: goto P_0c060bae;
case 0x0c060bb0u: goto P_0c060bb0;
case 0x0c060bb2u: goto P_0c060bb2;
case 0x0c060bb4u: goto P_0c060bb4;
case 0x0c060bb6u: goto P_0c060bb6;
case 0x0c060bb8u: goto P_0c060bb8;
case 0x0c060bbau: goto P_0c060bba;
case 0x0c060bbcu: goto P_0c060bbc;
case 0x0c060bbeu: goto P_0c060bbe;
case 0x0c060bc0u: goto P_0c060bc0;
case 0x0c060bc2u: goto P_0c060bc2;
case 0x0c060bc4u: goto P_0c060bc4;
case 0x0c060bc6u: goto P_0c060bc6;
case 0x0c060bc8u: goto P_0c060bc8;
case 0x0c060bcau: goto P_0c060bca;
case 0x0c060bccu: goto P_0c060bcc;
case 0x0c060bceu: goto P_0c060bce;
case 0x0c060bd0u: goto P_0c060bd0;
case 0x0c060bd2u: goto P_0c060bd2;
case 0x0c060bd4u: goto P_0c060bd4;
case 0x0c060bd6u: goto P_0c060bd6;
default: return vf3_matrix_family(target,s,ram);
}
P_0c0609ae: /* original 2fe6, guest PC 0x0c0609ae */
if(!s->budget--) { s->failed_pc=0x0c0609aeu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0609b0;
P_0c0609b0: /* original 2fd6, guest PC 0x0c0609b0 */
if(!s->budget--) { s->failed_pc=0x0c0609b0u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0609b2;
P_0c0609b2: /* original ed01, guest PC 0x0c0609b2 */
if(!s->budget--) { s->failed_pc=0x0c0609b2u; return 0; }
r[13]=0x00000001u;
goto P_0c0609b4;
P_0c0609b4: /* original 934e, guest PC 0x0c0609b4 */
if(!s->budget--) { s->failed_pc=0x0c0609b4u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c060a54u,2);
goto P_0c0609b6;
P_0c0609b6: /* original 2fc6, guest PC 0x0c0609b6 */
if(!s->budget--) { s->failed_pc=0x0c0609b6u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0609b8;
P_0c0609b8: /* original 4f22, guest PC 0x0c0609b8 */
if(!s->budget--) { s->failed_pc=0x0c0609b8u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0609ba;
P_0c0609ba: /* original 904a, guest PC 0x0c0609ba */
if(!s->budget--) { s->failed_pc=0x0c0609bau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c060a52u,2);
goto P_0c0609bc;
P_0c0609bc: /* original d22d, guest PC 0x0c0609bc */
if(!s->budget--) { s->failed_pc=0x0c0609bcu; return 0; }
r[2]=read(ram,0x0c060a74u,4);
goto P_0c0609be;
P_0c0609be: /* original 3f0c, guest PC 0x0c0609be */
if(!s->budget--) { s->failed_pc=0x0c0609beu; return 0; }
r[15]+=r[0];
goto P_0c0609c0;
P_0c0609c0: /* original 6ef3, guest PC 0x0c0609c0 */
if(!s->budget--) { s->failed_pc=0x0c0609c0u; return 0; }
r[14]=r[15];
goto P_0c0609c2;
P_0c0609c2: /* original 1e32, guest PC 0x0c0609c2 */
if(!s->budget--) { s->failed_pc=0x0c0609c2u; return 0; }
write(ram,r[14]+8,r[3],4);
goto P_0c0609c4;
P_0c0609c4: /* original 6022, guest PC 0x0c0609c4 */
if(!s->budget--) { s->failed_pc=0x0c0609c4u; return 0; }
tmp=read(ram,r[2],4);
r[0]=tmp;
goto P_0c0609c6;
P_0c0609c6: /* original 20d9, guest PC 0x0c0609c6 */
if(!s->budget--) { s->failed_pc=0x0c0609c6u; return 0; }
r[0]&=r[13];
goto P_0c0609c8;
P_0c0609c8: /* original 8801, guest PC 0x0c0609c8 */
if(!s->budget--) { s->failed_pc=0x0c0609c8u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c0609ca;
P_0c0609ca: /* original 8d09, guest PC 0x0c0609ca */
if(!s->budget--) { s->failed_pc=0x0c0609cau; return 0; }
cond=r[17]&1u;
r[12]=0x00000012u;
if(cond) { goto P_0c0609e0; }
goto P_0c0609ce;
P_0c0609cc: /* original ec12, guest PC 0x0c0609cc */
if(!s->budget--) { s->failed_pc=0x0c0609ccu; return 0; }
r[12]=0x00000012u;
goto P_0c0609ce;
P_0c0609ce: /* original d329, guest PC 0x0c0609ce */
if(!s->budget--) { s->failed_pc=0x0c0609ceu; return 0; }
r[3]=read(ram,0x0c060a74u,4);
goto P_0c0609d0;
P_0c0609d0: /* original 6032, guest PC 0x0c0609d0 */
if(!s->budget--) { s->failed_pc=0x0c0609d0u; return 0; }
tmp=read(ram,r[3],4);
r[0]=tmp;
goto P_0c0609d2;
P_0c0609d2: /* original c82c, guest PC 0x0c0609d2 */
if(!s->budget--) { s->failed_pc=0x0c0609d2u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&44u)==0)!=0);
goto P_0c0609d4;
P_0c0609d4: /* original 8904, guest PC 0x0c0609d4 */
if(!s->budget--) { s->failed_pc=0x0c0609d4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0609e0; }
goto P_0c0609d6;
P_0c0609d6: /* original 2dd8, guest PC 0x0c0609d6 */
if(!s->budget--) { s->failed_pc=0x0c0609d6u; return 0; }
r[17]=(r[17]&~1u)|(((r[13]&r[13])==0)!=0);
goto P_0c0609d8;
P_0c0609d8: /* original 8902, guest PC 0x0c0609d8 */
if(!s->budget--) { s->failed_pc=0x0c0609d8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0609e0; }
goto P_0c0609da;
P_0c0609da: /* original 923c, guest PC 0x0c0609da */
if(!s->budget--) { s->failed_pc=0x0c0609dau; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c060a56u,2);
goto P_0c0609dc;
P_0c0609dc: /* original a002, guest PC 0x0c0609dc */
if(!s->budget--) { s->failed_pc=0x0c0609dcu; return 0; }
write(ram,r[14]+20,r[2],4);
goto P_0c0609e4;
P_0c0609de: /* original 1e25, guest PC 0x0c0609de */
if(!s->budget--) { s->failed_pc=0x0c0609deu; return 0; }
write(ram,r[14]+20,r[2],4);
goto P_0c0609e0;
P_0c0609e0: /* original 913a, guest PC 0x0c0609e0 */
if(!s->budget--) { s->failed_pc=0x0c0609e0u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c060a58u,2);
goto P_0c0609e2;
P_0c0609e2: /* original 1e15, guest PC 0x0c0609e2 */
if(!s->budget--) { s->failed_pc=0x0c0609e2u; return 0; }
write(ram,r[14]+20,r[1],4);
goto P_0c0609e4;
P_0c0609e4: /* original 9239, guest PC 0x0c0609e4 */
if(!s->budget--) { s->failed_pc=0x0c0609e4u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c060a5au,2);
goto P_0c0609e6;
P_0c0609e6: /* original e37e, guest PC 0x0c0609e6 */
if(!s->budget--) { s->failed_pc=0x0c0609e6u; return 0; }
r[3]=0x0000007eu;
goto P_0c0609e8;
P_0c0609e8: /* original 9438, guest PC 0x0c0609e8 */
if(!s->budget--) { s->failed_pc=0x0c0609e8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c060a5cu,2);
goto P_0c0609ea;
P_0c0609ea: /* original 2e32, guest PC 0x0c0609ea */
if(!s->budget--) { s->failed_pc=0x0c0609eau; return 0; }
write(ram,r[14],r[3],4);
goto P_0c0609ec;
P_0c0609ec: /* original 1e21, guest PC 0x0c0609ec */
if(!s->budget--) { s->failed_pc=0x0c0609ecu; return 0; }
write(ram,r[14]+4,r[2],4);
goto P_0c0609ee;
P_0c0609ee: /* original d321, guest PC 0x0c0609ee */
if(!s->budget--) { s->failed_pc=0x0c0609eeu; return 0; }
r[3]=read(ram,0x0c060a74u,4);
goto P_0c0609f0;
P_0c0609f0: /* original 6032, guest PC 0x0c0609f0 */
if(!s->budget--) { s->failed_pc=0x0c0609f0u; return 0; }
tmp=read(ram,r[3],4);
r[0]=tmp;
goto P_0c0609f2;
P_0c0609f2: /* original 20d9, guest PC 0x0c0609f2 */
if(!s->budget--) { s->failed_pc=0x0c0609f2u; return 0; }
r[0]&=r[13];
goto P_0c0609f4;
P_0c0609f4: /* original 8801, guest PC 0x0c0609f4 */
if(!s->budget--) { s->failed_pc=0x0c0609f4u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c0609f6;
P_0c0609f6: /* original 890a, guest PC 0x0c0609f6 */
if(!s->budget--) { s->failed_pc=0x0c0609f6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c060a0e; }
goto P_0c0609f8;
P_0c0609f8: /* original d21e, guest PC 0x0c0609f8 */
if(!s->budget--) { s->failed_pc=0x0c0609f8u; return 0; }
r[2]=read(ram,0x0c060a74u,4);
goto P_0c0609fa;
P_0c0609fa: /* original 6022, guest PC 0x0c0609fa */
if(!s->budget--) { s->failed_pc=0x0c0609fau; return 0; }
tmp=read(ram,r[2],4);
r[0]=tmp;
goto P_0c0609fc;
P_0c0609fc: /* original c82c, guest PC 0x0c0609fc */
if(!s->budget--) { s->failed_pc=0x0c0609fcu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&44u)==0)!=0);
goto P_0c0609fe;
P_0c0609fe: /* original 8906, guest PC 0x0c0609fe */
if(!s->budget--) { s->failed_pc=0x0c0609feu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c060a0e; }
goto P_0c060a00;
P_0c060a00: /* original 2dd8, guest PC 0x0c060a00 */
if(!s->budget--) { s->failed_pc=0x0c060a00u; return 0; }
r[17]=(r[17]&~1u)|(((r[13]&r[13])==0)!=0);
goto P_0c060a02;
P_0c060a02: /* original 8904, guest PC 0x0c060a02 */
if(!s->budget--) { s->failed_pc=0x0c060a02u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c060a0e; }
goto P_0c060a04;
P_0c060a04: /* original 922b, guest PC 0x0c060a04 */
if(!s->budget--) { s->failed_pc=0x0c060a04u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c060a5eu,2);
goto P_0c060a06;
P_0c060a06: /* original e324, guest PC 0x0c060a06 */
if(!s->budget--) { s->failed_pc=0x0c060a06u; return 0; }
r[3]=0x00000024u;
goto P_0c060a08;
P_0c060a08: /* original 1e33, guest PC 0x0c060a08 */
if(!s->budget--) { s->failed_pc=0x0c060a08u; return 0; }
write(ram,r[14]+12,r[3],4);
goto P_0c060a0a;
P_0c060a0a: /* original a002, guest PC 0x0c060a0a */
if(!s->budget--) { s->failed_pc=0x0c060a0au; return 0; }
write(ram,r[14]+16,r[2],4);
goto P_0c060a12;
P_0c060a0c: /* original 1e24, guest PC 0x0c060a0c */
if(!s->budget--) { s->failed_pc=0x0c060a0cu; return 0; }
write(ram,r[14]+16,r[2],4);
goto P_0c060a0e;
P_0c060a0e: /* original 1ec3, guest PC 0x0c060a0e */
if(!s->budget--) { s->failed_pc=0x0c060a0eu; return 0; }
write(ram,r[14]+12,r[12],4);
goto P_0c060a10;
P_0c060a10: /* original 1e44, guest PC 0x0c060a10 */
if(!s->budget--) { s->failed_pc=0x0c060a10u; return 0; }
write(ram,r[14]+16,r[4],4);
goto P_0c060a12;
P_0c060a12: /* original e23f, guest PC 0x0c060a12 */
if(!s->budget--) { s->failed_pc=0x0c060a12u; return 0; }
r[2]=0x0000003fu;
goto P_0c060a14;
P_0c060a14: /* original d317, guest PC 0x0c060a14 */
if(!s->budget--) { s->failed_pc=0x0c060a14u; return 0; }
r[3]=read(ram,0x0c060a74u,4);
goto P_0c060a16;
P_0c060a16: /* original 1e26, guest PC 0x0c060a16 */
if(!s->budget--) { s->failed_pc=0x0c060a16u; return 0; }
write(ram,r[14]+24,r[2],4);
goto P_0c060a18;
P_0c060a18: /* original 6032, guest PC 0x0c060a18 */
if(!s->budget--) { s->failed_pc=0x0c060a18u; return 0; }
tmp=read(ram,r[3],4);
r[0]=tmp;
goto P_0c060a1a;
P_0c060a1a: /* original c820, guest PC 0x0c060a1a */
if(!s->budget--) { s->failed_pc=0x0c060a1au; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&32u)==0)!=0);
goto P_0c060a1c;
P_0c060a1c: /* original 8d04, guest PC 0x0c060a1c */
if(!s->budget--) { s->failed_pc=0x0c060a1cu; return 0; }
cond=r[17]&1u;
r[3]=0x00000015u;
if(cond) { goto P_0c060a28; }
goto P_0c060a20;
P_0c060a1e: /* original e315, guest PC 0x0c060a1e */
if(!s->budget--) { s->failed_pc=0x0c060a1eu; return 0; }
r[3]=0x00000015u;
goto P_0c060a20;
P_0c060a20: /* original 911e, guest PC 0x0c060a20 */
if(!s->budget--) { s->failed_pc=0x0c060a20u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c060a60u,2);
goto P_0c060a22;
P_0c060a22: /* original e074, guest PC 0x0c060a22 */
if(!s->budget--) { s->failed_pc=0x0c060a22u; return 0; }
r[0]=0x00000074u;
goto P_0c060a24;
P_0c060a24: /* original a002, guest PC 0x0c060a24 */
if(!s->budget--) { s->failed_pc=0x0c060a24u; return 0; }
write(ram,r[14]+r[0],r[1],4);
goto P_0c060a2c;
P_0c060a26: /* original 0e16, guest PC 0x0c060a26 */
if(!s->budget--) { s->failed_pc=0x0c060a26u; return 0; }
write(ram,r[14]+r[0],r[1],4);
goto P_0c060a28;
P_0c060a28: /* original e074, guest PC 0x0c060a28 */
if(!s->budget--) { s->failed_pc=0x0c060a28u; return 0; }
r[0]=0x00000074u;
goto P_0c060a2a;
P_0c060a2a: /* original 0e46, guest PC 0x0c060a2a */
if(!s->budget--) { s->failed_pc=0x0c060a2au; return 0; }
write(ram,r[14]+r[0],r[4],4);
goto P_0c060a2c;
P_0c060a2c: /* original d211, guest PC 0x0c060a2c */
if(!s->budget--) { s->failed_pc=0x0c060a2cu; return 0; }
r[2]=read(ram,0x0c060a74u,4);
goto P_0c060a2e;
P_0c060a2e: /* original e078, guest PC 0x0c060a2e */
if(!s->budget--) { s->failed_pc=0x0c060a2eu; return 0; }
r[0]=0x00000078u;
goto P_0c060a30;
P_0c060a30: /* original 0e36, guest PC 0x0c060a30 */
if(!s->budget--) { s->failed_pc=0x0c060a30u; return 0; }
write(ram,r[14]+r[0],r[3],4);
goto P_0c060a32;
P_0c060a32: /* original 6022, guest PC 0x0c060a32 */
if(!s->budget--) { s->failed_pc=0x0c060a32u; return 0; }
tmp=read(ram,r[2],4);
r[0]=tmp;
goto P_0c060a34;
P_0c060a34: /* original 20d9, guest PC 0x0c060a34 */
if(!s->budget--) { s->failed_pc=0x0c060a34u; return 0; }
r[0]&=r[13];
goto P_0c060a36;
P_0c060a36: /* original 8801, guest PC 0x0c060a36 */
if(!s->budget--) { s->failed_pc=0x0c060a36u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c060a38;
P_0c060a38: /* original 891e, guest PC 0x0c060a38 */
if(!s->budget--) { s->failed_pc=0x0c060a38u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c060a78; }
goto P_0c060a3a;
P_0c060a3a: /* original d30e, guest PC 0x0c060a3a */
if(!s->budget--) { s->failed_pc=0x0c060a3au; return 0; }
r[3]=read(ram,0x0c060a74u,4);
goto P_0c060a3c;
P_0c060a3c: /* original 6032, guest PC 0x0c060a3c */
if(!s->budget--) { s->failed_pc=0x0c060a3cu; return 0; }
tmp=read(ram,r[3],4);
r[0]=tmp;
goto P_0c060a3e;
P_0c060a3e: /* original c82c, guest PC 0x0c060a3e */
if(!s->budget--) { s->failed_pc=0x0c060a3eu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&44u)==0)!=0);
goto P_0c060a40;
P_0c060a40: /* original 891a, guest PC 0x0c060a40 */
if(!s->budget--) { s->failed_pc=0x0c060a40u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c060a78; }
goto P_0c060a42;
P_0c060a42: /* original 2dd8, guest PC 0x0c060a42 */
if(!s->budget--) { s->failed_pc=0x0c060a42u; return 0; }
r[17]=(r[17]&~1u)|(((r[13]&r[13])==0)!=0);
goto P_0c060a44;
P_0c060a44: /* original 8918, guest PC 0x0c060a44 */
if(!s->budget--) { s->failed_pc=0x0c060a44u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c060a78; }
goto P_0c060a46;
P_0c060a46: /* original e206, guest PC 0x0c060a46 */
if(!s->budget--) { s->failed_pc=0x0c060a46u; return 0; }
r[2]=0x00000006u;
goto P_0c060a48;
P_0c060a48: /* original a018, guest PC 0x0c060a48 */
if(!s->budget--) { s->failed_pc=0x0c060a48u; return 0; }
write(ram,r[14]+28,r[2],4);
goto P_0c060a7c;
P_0c060a4a: /* original 1e27, guest PC 0x0c060a4a */
if(!s->budget--) { s->failed_pc=0x0c060a4au; return 0; }
write(ram,r[14]+28,r[2],4);
if(!vf3_matrix_family(0x0c060a4cu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c060a4cu; return 0; } return 1;
P_0c060a78: /* original e103, guest PC 0x0c060a78 */
if(!s->budget--) { s->failed_pc=0x0c060a78u; return 0; }
r[1]=0x00000003u;
goto P_0c060a7a;
P_0c060a7a: /* original 1e17, guest PC 0x0c060a7a */
if(!s->budget--) { s->failed_pc=0x0c060a7au; return 0; }
write(ram,r[14]+28,r[1],4);
goto P_0c060a7c;
P_0c060a7c: /* original d329, guest PC 0x0c060a7c */
if(!s->budget--) { s->failed_pc=0x0c060a7cu; return 0; }
r[3]=read(ram,0x0c060b24u,4);
goto P_0c060a7e;
P_0c060a7e: /* original 6032, guest PC 0x0c060a7e */
if(!s->budget--) { s->failed_pc=0x0c060a7eu; return 0; }
tmp=read(ram,r[3],4);
r[0]=tmp;
goto P_0c060a80;
P_0c060a80: /* original 20d9, guest PC 0x0c060a80 */
if(!s->budget--) { s->failed_pc=0x0c060a80u; return 0; }
r[0]&=r[13];
goto P_0c060a82;
P_0c060a82: /* original 8801, guest PC 0x0c060a82 */
if(!s->budget--) { s->failed_pc=0x0c060a82u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c060a84;
P_0c060a84: /* original 8908, guest PC 0x0c060a84 */
if(!s->budget--) { s->failed_pc=0x0c060a84u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c060a98; }
goto P_0c060a86;
P_0c060a86: /* original d227, guest PC 0x0c060a86 */
if(!s->budget--) { s->failed_pc=0x0c060a86u; return 0; }
r[2]=read(ram,0x0c060b24u,4);
goto P_0c060a88;
P_0c060a88: /* original 6022, guest PC 0x0c060a88 */
if(!s->budget--) { s->failed_pc=0x0c060a88u; return 0; }
tmp=read(ram,r[2],4);
r[0]=tmp;
goto P_0c060a8a;
P_0c060a8a: /* original c82c, guest PC 0x0c060a8a */
if(!s->budget--) { s->failed_pc=0x0c060a8au; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&44u)==0)!=0);
goto P_0c060a8c;
P_0c060a8c: /* original 8904, guest PC 0x0c060a8c */
if(!s->budget--) { s->failed_pc=0x0c060a8cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c060a98; }
goto P_0c060a8e;
P_0c060a8e: /* original 2dd8, guest PC 0x0c060a8e */
if(!s->budget--) { s->failed_pc=0x0c060a8eu; return 0; }
r[17]=(r[17]&~1u)|(((r[13]&r[13])==0)!=0);
goto P_0c060a90;
P_0c060a90: /* original 8902, guest PC 0x0c060a90 */
if(!s->budget--) { s->failed_pc=0x0c060a90u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c060a98; }
goto P_0c060a92;
P_0c060a92: /* original 9344, guest PC 0x0c060a92 */
if(!s->budget--) { s->failed_pc=0x0c060a92u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c060b1eu,2);
goto P_0c060a94;
P_0c060a94: /* original a002, guest PC 0x0c060a94 */
if(!s->budget--) { s->failed_pc=0x0c060a94u; return 0; }
write(ram,r[14]+32,r[3],4);
goto P_0c060a9c;
P_0c060a96: /* original 1e38, guest PC 0x0c060a96 */
if(!s->budget--) { s->failed_pc=0x0c060a96u; return 0; }
write(ram,r[14]+32,r[3],4);
goto P_0c060a98;
P_0c060a98: /* original 9142, guest PC 0x0c060a98 */
if(!s->budget--) { s->failed_pc=0x0c060a98u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c060b20u,2);
goto P_0c060a9a;
P_0c060a9a: /* original 1e18, guest PC 0x0c060a9a */
if(!s->budget--) { s->failed_pc=0x0c060a9au; return 0; }
write(ram,r[14]+32,r[1],4);
goto P_0c060a9c;
P_0c060a9c: /* original d321, guest PC 0x0c060a9c */
if(!s->budget--) { s->failed_pc=0x0c060a9cu; return 0; }
r[3]=read(ram,0x0c060b24u,4);
goto P_0c060a9e;
P_0c060a9e: /* original 6032, guest PC 0x0c060a9e */
if(!s->budget--) { s->failed_pc=0x0c060a9eu; return 0; }
tmp=read(ram,r[3],4);
r[0]=tmp;
goto P_0c060aa0;
P_0c060aa0: /* original 20d9, guest PC 0x0c060aa0 */
if(!s->budget--) { s->failed_pc=0x0c060aa0u; return 0; }
r[0]&=r[13];
goto P_0c060aa2;
P_0c060aa2: /* original 8801, guest PC 0x0c060aa2 */
if(!s->budget--) { s->failed_pc=0x0c060aa2u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c060aa4;
P_0c060aa4: /* original 8d08, guest PC 0x0c060aa4 */
if(!s->budget--) { s->failed_pc=0x0c060aa4u; return 0; }
cond=r[17]&1u;
r[5]=0x0000001fu;
if(cond) { goto P_0c060ab8; }
goto P_0c060aa8;
P_0c060aa6: /* original e51f, guest PC 0x0c060aa6 */
if(!s->budget--) { s->failed_pc=0x0c060aa6u; return 0; }
r[5]=0x0000001fu;
goto P_0c060aa8;
P_0c060aa8: /* original d21e, guest PC 0x0c060aa8 */
if(!s->budget--) { s->failed_pc=0x0c060aa8u; return 0; }
r[2]=read(ram,0x0c060b24u,4);
goto P_0c060aaa;
P_0c060aaa: /* original 6022, guest PC 0x0c060aaa */
if(!s->budget--) { s->failed_pc=0x0c060aaau; return 0; }
tmp=read(ram,r[2],4);
r[0]=tmp;
goto P_0c060aac;
P_0c060aac: /* original c82c, guest PC 0x0c060aac */
if(!s->budget--) { s->failed_pc=0x0c060aacu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&44u)==0)!=0);
goto P_0c060aae;
P_0c060aae: /* original 8903, guest PC 0x0c060aae */
if(!s->budget--) { s->failed_pc=0x0c060aaeu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c060ab8; }
goto P_0c060ab0;
P_0c060ab0: /* original 2dd8, guest PC 0x0c060ab0 */
if(!s->budget--) { s->failed_pc=0x0c060ab0u; return 0; }
r[17]=(r[17]&~1u)|(((r[13]&r[13])==0)!=0);
goto P_0c060ab2;
P_0c060ab2: /* original 8901, guest PC 0x0c060ab2 */
if(!s->budget--) { s->failed_pc=0x0c060ab2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c060ab8; }
goto P_0c060ab4;
P_0c060ab4: /* original a002, guest PC 0x0c060ab4 */
if(!s->budget--) { s->failed_pc=0x0c060ab4u; return 0; }
write(ram,r[14]+36,r[5],4);
goto P_0c060abc;
P_0c060ab6: /* original 1e59, guest PC 0x0c060ab6 */
if(!s->budget--) { s->failed_pc=0x0c060ab6u; return 0; }
write(ram,r[14]+36,r[5],4);
goto P_0c060ab8;
P_0c060ab8: /* original e20f, guest PC 0x0c060ab8 */
if(!s->budget--) { s->failed_pc=0x0c060ab8u; return 0; }
r[2]=0x0000000fu;
goto P_0c060aba;
P_0c060aba: /* original 1e29, guest PC 0x0c060aba */
if(!s->budget--) { s->failed_pc=0x0c060abau; return 0; }
write(ram,r[14]+36,r[2],4);
goto P_0c060abc;
P_0c060abc: /* original 1eda, guest PC 0x0c060abc */
if(!s->budget--) { s->failed_pc=0x0c060abcu; return 0; }
write(ram,r[14]+40,r[13],4);
goto P_0c060abe;
P_0c060abe: /* original e400, guest PC 0x0c060abe */
if(!s->budget--) { s->failed_pc=0x0c060abeu; return 0; }
r[4]=0x00000000u;
goto P_0c060ac0;
P_0c060ac0: /* original d318, guest PC 0x0c060ac0 */
if(!s->budget--) { s->failed_pc=0x0c060ac0u; return 0; }
r[3]=read(ram,0x0c060b24u,4);
goto P_0c060ac2;
P_0c060ac2: /* original 1e4b, guest PC 0x0c060ac2 */
if(!s->budget--) { s->failed_pc=0x0c060ac2u; return 0; }
write(ram,r[14]+44,r[4],4);
goto P_0c060ac4;
P_0c060ac4: /* original 6032, guest PC 0x0c060ac4 */
if(!s->budget--) { s->failed_pc=0x0c060ac4u; return 0; }
tmp=read(ram,r[3],4);
r[0]=tmp;
goto P_0c060ac6;
P_0c060ac6: /* original 20d9, guest PC 0x0c060ac6 */
if(!s->budget--) { s->failed_pc=0x0c060ac6u; return 0; }
r[0]&=r[13];
goto P_0c060ac8;
P_0c060ac8: /* original 8801, guest PC 0x0c060ac8 */
if(!s->budget--) { s->failed_pc=0x0c060ac8u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c060aca;
P_0c060aca: /* original 8b03, guest PC 0x0c060aca */
if(!s->budget--) { s->failed_pc=0x0c060acau; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c060ad4; }
goto P_0c060acc;
P_0c060acc: /* original 2448, guest PC 0x0c060acc */
if(!s->budget--) { s->failed_pc=0x0c060accu; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c060ace;
P_0c060ace: /* original 890d, guest PC 0x0c060ace */
if(!s->budget--) { s->failed_pc=0x0c060aceu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c060aec; }
goto P_0c060ad0;
P_0c060ad0: /* original a00a, guest PC 0x0c060ad0 */
if(!s->budget--) { s->failed_pc=0x0c060ad0u; return 0; }
goto P_0c060ae8;
P_0c060ad2: /* original 0009, guest PC 0x0c060ad2 */
if(!s->budget--) { s->failed_pc=0x0c060ad2u; return 0; }
goto P_0c060ad4;
P_0c060ad4: /* original d213, guest PC 0x0c060ad4 */
if(!s->budget--) { s->failed_pc=0x0c060ad4u; return 0; }
r[2]=read(ram,0x0c060b24u,4);
goto P_0c060ad6;
P_0c060ad6: /* original 6022, guest PC 0x0c060ad6 */
if(!s->budget--) { s->failed_pc=0x0c060ad6u; return 0; }
tmp=read(ram,r[2],4);
r[0]=tmp;
goto P_0c060ad8;
P_0c060ad8: /* original c82c, guest PC 0x0c060ad8 */
if(!s->budget--) { s->failed_pc=0x0c060ad8u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&44u)==0)!=0);
goto P_0c060ada;
P_0c060ada: /* original 8903, guest PC 0x0c060ada */
if(!s->budget--) { s->failed_pc=0x0c060adau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c060ae4; }
goto P_0c060adc;
P_0c060adc: /* original 2dd8, guest PC 0x0c060adc */
if(!s->budget--) { s->failed_pc=0x0c060adcu; return 0; }
r[17]=(r[17]&~1u)|(((r[13]&r[13])==0)!=0);
goto P_0c060ade;
P_0c060ade: /* original 8905, guest PC 0x0c060ade */
if(!s->budget--) { s->failed_pc=0x0c060adeu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c060aec; }
goto P_0c060ae0;
P_0c060ae0: /* original a002, guest PC 0x0c060ae0 */
if(!s->budget--) { s->failed_pc=0x0c060ae0u; return 0; }
goto P_0c060ae8;
P_0c060ae2: /* original 0009, guest PC 0x0c060ae2 */
if(!s->budget--) { s->failed_pc=0x0c060ae2u; return 0; }
goto P_0c060ae4;
P_0c060ae4: /* original 2448, guest PC 0x0c060ae4 */
if(!s->budget--) { s->failed_pc=0x0c060ae4u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c060ae6;
P_0c060ae6: /* original 8901, guest PC 0x0c060ae6 */
if(!s->budget--) { s->failed_pc=0x0c060ae6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c060aec; }
goto P_0c060ae8;
P_0c060ae8: /* original a001, guest PC 0x0c060ae8 */
if(!s->budget--) { s->failed_pc=0x0c060ae8u; return 0; }
write(ram,r[14]+48,r[13],4);
goto P_0c060aee;
P_0c060aea: /* original 1edc, guest PC 0x0c060aea */
if(!s->budget--) { s->failed_pc=0x0c060aeau; return 0; }
write(ram,r[14]+48,r[13],4);
goto P_0c060aec;
P_0c060aec: /* original 1e4c, guest PC 0x0c060aec */
if(!s->budget--) { s->failed_pc=0x0c060aecu; return 0; }
write(ram,r[14]+48,r[4],4);
goto P_0c060aee;
P_0c060aee: /* original e040, guest PC 0x0c060aee */
if(!s->budget--) { s->failed_pc=0x0c060aeeu; return 0; }
r[0]=0x00000040u;
goto P_0c060af0;
P_0c060af0: /* original d30d, guest PC 0x0c060af0 */
if(!s->budget--) { s->failed_pc=0x0c060af0u; return 0; }
r[3]=read(ram,0x0c060b28u,4);
goto P_0c060af2;
P_0c060af2: /* original 1e4d, guest PC 0x0c060af2 */
if(!s->budget--) { s->failed_pc=0x0c060af2u; return 0; }
write(ram,r[14]+52,r[4],4);
goto P_0c060af4;
P_0c060af4: /* original 1e4e, guest PC 0x0c060af4 */
if(!s->budget--) { s->failed_pc=0x0c060af4u; return 0; }
write(ram,r[14]+56,r[4],4);
goto P_0c060af6;
P_0c060af6: /* original 1e4f, guest PC 0x0c060af6 */
if(!s->budget--) { s->failed_pc=0x0c060af6u; return 0; }
write(ram,r[14]+60,r[4],4);
goto P_0c060af8;
P_0c060af8: /* original 0e46, guest PC 0x0c060af8 */
if(!s->budget--) { s->failed_pc=0x0c060af8u; return 0; }
write(ram,r[14]+r[0],r[4],4);
goto P_0c060afa;
P_0c060afa: /* original e044, guest PC 0x0c060afa */
if(!s->budget--) { s->failed_pc=0x0c060afau; return 0; }
r[0]=0x00000044u;
goto P_0c060afc;
P_0c060afc: /* original 0e46, guest PC 0x0c060afc */
if(!s->budget--) { s->failed_pc=0x0c060afcu; return 0; }
write(ram,r[14]+r[0],r[4],4);
goto P_0c060afe;
P_0c060afe: /* original 6032, guest PC 0x0c060afe */
if(!s->budget--) { s->failed_pc=0x0c060afeu; return 0; }
tmp=read(ram,r[3],4);
r[0]=tmp;
goto P_0c060b00;
P_0c060b00: /* original 8806, guest PC 0x0c060b00 */
if(!s->budget--) { s->failed_pc=0x0c060b00u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000006u)!=0);
goto P_0c060b02;
P_0c060b02: /* original 8b03, guest PC 0x0c060b02 */
if(!s->budget--) { s->failed_pc=0x0c060b02u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c060b0c; }
goto P_0c060b04;
P_0c060b04: /* original e116, guest PC 0x0c060b04 */
if(!s->budget--) { s->failed_pc=0x0c060b04u; return 0; }
r[1]=0x00000016u;
goto P_0c060b06;
P_0c060b06: /* original e070, guest PC 0x0c060b06 */
if(!s->budget--) { s->failed_pc=0x0c060b06u; return 0; }
r[0]=0x00000070u;
goto P_0c060b08;
P_0c060b08: /* original a002, guest PC 0x0c060b08 */
if(!s->budget--) { s->failed_pc=0x0c060b08u; return 0; }
write(ram,r[14]+r[0],r[1],4);
goto P_0c060b10;
P_0c060b0a: /* original 0e16, guest PC 0x0c060b0a */
if(!s->budget--) { s->failed_pc=0x0c060b0au; return 0; }
write(ram,r[14]+r[0],r[1],4);
goto P_0c060b0c;
P_0c060b0c: /* original e070, guest PC 0x0c060b0c */
if(!s->budget--) { s->failed_pc=0x0c060b0cu; return 0; }
r[0]=0x00000070u;
goto P_0c060b0e;
P_0c060b0e: /* original 0e56, guest PC 0x0c060b0e */
if(!s->budget--) { s->failed_pc=0x0c060b0eu; return 0; }
write(ram,r[14]+r[0],r[5],4);
goto P_0c060b10;
P_0c060b10: /* original d304, guest PC 0x0c060b10 */
if(!s->budget--) { s->failed_pc=0x0c060b10u; return 0; }
r[3]=read(ram,0x0c060b24u,4);
goto P_0c060b12;
P_0c060b12: /* original 6032, guest PC 0x0c060b12 */
if(!s->budget--) { s->failed_pc=0x0c060b12u; return 0; }
tmp=read(ram,r[3],4);
r[0]=tmp;
goto P_0c060b14;
P_0c060b14: /* original c810, guest PC 0x0c060b14 */
if(!s->budget--) { s->failed_pc=0x0c060b14u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&16u)==0)!=0);
goto P_0c060b16;
P_0c060b16: /* original 8909, guest PC 0x0c060b16 */
if(!s->budget--) { s->failed_pc=0x0c060b16u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c060b2c; }
goto P_0c060b18;
P_0c060b18: /* original e06c, guest PC 0x0c060b18 */
if(!s->budget--) { s->failed_pc=0x0c060b18u; return 0; }
r[0]=0x0000006cu;
goto P_0c060b1a;
P_0c060b1a: /* original a009, guest PC 0x0c060b1a */
if(!s->budget--) { s->failed_pc=0x0c060b1au; return 0; }
write(ram,r[14]+r[0],r[4],4);
goto P_0c060b30;
P_0c060b1c: /* original 0e46, guest PC 0x0c060b1c */
if(!s->budget--) { s->failed_pc=0x0c060b1cu; return 0; }
write(ram,r[14]+r[0],r[4],4);
if(!vf3_matrix_family(0x0c060b1eu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c060b1eu; return 0; } return 1;
P_0c060b2c: /* original e06c, guest PC 0x0c060b2c */
if(!s->budget--) { s->failed_pc=0x0c060b2cu; return 0; }
r[0]=0x0000006cu;
goto P_0c060b2e;
P_0c060b2e: /* original 0ed6, guest PC 0x0c060b2e */
if(!s->budget--) { s->failed_pc=0x0c060b2eu; return 0; }
write(ram,r[14]+r[0],r[13],4);
goto P_0c060b30;
P_0c060b30: /* original 9380, guest PC 0x0c060b30 */
if(!s->budget--) { s->failed_pc=0x0c060b30u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c060c34u,2);
goto P_0c060b32;
P_0c060b32: /* original e048, guest PC 0x0c060b32 */
if(!s->budget--) { s->failed_pc=0x0c060b32u; return 0; }
r[0]=0x00000048u;
goto P_0c060b34;
P_0c060b34: /* original 0ed6, guest PC 0x0c060b34 */
if(!s->budget--) { s->failed_pc=0x0c060b34u; return 0; }
write(ram,r[14]+r[0],r[13],4);
goto P_0c060b36;
P_0c060b36: /* original e04c, guest PC 0x0c060b36 */
if(!s->budget--) { s->failed_pc=0x0c060b36u; return 0; }
r[0]=0x0000004cu;
goto P_0c060b38;
P_0c060b38: /* original 0e46, guest PC 0x0c060b38 */
if(!s->budget--) { s->failed_pc=0x0c060b38u; return 0; }
write(ram,r[14]+r[0],r[4],4);
goto P_0c060b3a;
P_0c060b3a: /* original e050, guest PC 0x0c060b3a */
if(!s->budget--) { s->failed_pc=0x0c060b3au; return 0; }
r[0]=0x00000050u;
goto P_0c060b3c;
P_0c060b3c: /* original 0e46, guest PC 0x0c060b3c */
if(!s->budget--) { s->failed_pc=0x0c060b3cu; return 0; }
write(ram,r[14]+r[0],r[4],4);
goto P_0c060b3e;
P_0c060b3e: /* original e054, guest PC 0x0c060b3e */
if(!s->budget--) { s->failed_pc=0x0c060b3eu; return 0; }
r[0]=0x00000054u;
goto P_0c060b40;
P_0c060b40: /* original 0e46, guest PC 0x0c060b40 */
if(!s->budget--) { s->failed_pc=0x0c060b40u; return 0; }
write(ram,r[14]+r[0],r[4],4);
goto P_0c060b42;
P_0c060b42: /* original e058, guest PC 0x0c060b42 */
if(!s->budget--) { s->failed_pc=0x0c060b42u; return 0; }
r[0]=0x00000058u;
goto P_0c060b44;
P_0c060b44: /* original 0e46, guest PC 0x0c060b44 */
if(!s->budget--) { s->failed_pc=0x0c060b44u; return 0; }
write(ram,r[14]+r[0],r[4],4);
goto P_0c060b46;
P_0c060b46: /* original e05c, guest PC 0x0c060b46 */
if(!s->budget--) { s->failed_pc=0x0c060b46u; return 0; }
r[0]=0x0000005cu;
goto P_0c060b48;
P_0c060b48: /* original 0e46, guest PC 0x0c060b48 */
if(!s->budget--) { s->failed_pc=0x0c060b48u; return 0; }
write(ram,r[14]+r[0],r[4],4);
goto P_0c060b4a;
P_0c060b4a: /* original e068, guest PC 0x0c060b4a */
if(!s->budget--) { s->failed_pc=0x0c060b4au; return 0; }
r[0]=0x00000068u;
goto P_0c060b4c;
P_0c060b4c: /* original 0e46, guest PC 0x0c060b4c */
if(!s->budget--) { s->failed_pc=0x0c060b4cu; return 0; }
write(ram,r[14]+r[0],r[4],4);
goto P_0c060b4e;
P_0c060b4e: /* original 6033, guest PC 0x0c060b4e */
if(!s->budget--) { s->failed_pc=0x0c060b4eu; return 0; }
r[0]=r[3];
goto P_0c060b50;
P_0c060b50: /* original 0009, guest PC 0x0c060b50 */
if(!s->budget--) { s->failed_pc=0x0c060b50u; return 0; }
goto P_0c060b52;
P_0c060b52: /* original 7054, guest PC 0x0c060b52 */
if(!s->budget--) { s->failed_pc=0x0c060b52u; return 0; }
r[0]+=0x00000054u;
goto P_0c060b54;
P_0c060b54: /* original 926f, guest PC 0x0c060b54 */
if(!s->budget--) { s->failed_pc=0x0c060b54u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c060c36u,2);
goto P_0c060b56;
P_0c060b56: /* original 0e36, guest PC 0x0c060b56 */
if(!s->budget--) { s->failed_pc=0x0c060b56u; return 0; }
write(ram,r[14]+r[0],r[3],4);
goto P_0c060b58;
P_0c060b58: /* original d33c, guest PC 0x0c060b58 */
if(!s->budget--) { s->failed_pc=0x0c060b58u; return 0; }
r[3]=read(ram,0x0c060c4cu,4);
goto P_0c060b5a;
P_0c060b5a: /* original e064, guest PC 0x0c060b5a */
if(!s->budget--) { s->failed_pc=0x0c060b5au; return 0; }
r[0]=0x00000064u;
goto P_0c060b5c;
P_0c060b5c: /* original 0e26, guest PC 0x0c060b5c */
if(!s->budget--) { s->failed_pc=0x0c060b5cu; return 0; }
write(ram,r[14]+r[0],r[2],4);
goto P_0c060b5e;
P_0c060b5e: /* original e060, guest PC 0x0c060b5e */
if(!s->budget--) { s->failed_pc=0x0c060b5eu; return 0; }
r[0]=0x00000060u;
goto P_0c060b60;
P_0c060b60: /* original 0e46, guest PC 0x0c060b60 */
if(!s->budget--) { s->failed_pc=0x0c060b60u; return 0; }
write(ram,r[14]+r[0],r[4],4);
goto P_0c060b62;
P_0c060b62: /* original 6032, guest PC 0x0c060b62 */
if(!s->budget--) { s->failed_pc=0x0c060b62u; return 0; }
tmp=read(ram,r[3],4);
r[0]=tmp;
goto P_0c060b64;
P_0c060b64: /* original 20d9, guest PC 0x0c060b64 */
if(!s->budget--) { s->failed_pc=0x0c060b64u; return 0; }
r[0]&=r[13];
goto P_0c060b66;
P_0c060b66: /* original 8801, guest PC 0x0c060b66 */
if(!s->budget--) { s->failed_pc=0x0c060b66u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c060b68;
P_0c060b68: /* original 8b03, guest PC 0x0c060b68 */
if(!s->budget--) { s->failed_pc=0x0c060b68u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c060b72; }
goto P_0c060b6a;
P_0c060b6a: /* original 2448, guest PC 0x0c060b6a */
if(!s->budget--) { s->failed_pc=0x0c060b6au; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c060b6c;
P_0c060b6c: /* original 890e, guest PC 0x0c060b6c */
if(!s->budget--) { s->failed_pc=0x0c060b6cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c060b8c; }
goto P_0c060b6e;
P_0c060b6e: /* original a00a, guest PC 0x0c060b6e */
if(!s->budget--) { s->failed_pc=0x0c060b6eu; return 0; }
goto P_0c060b86;
P_0c060b70: /* original 0009, guest PC 0x0c060b70 */
if(!s->budget--) { s->failed_pc=0x0c060b70u; return 0; }
goto P_0c060b72;
P_0c060b72: /* original d236, guest PC 0x0c060b72 */
if(!s->budget--) { s->failed_pc=0x0c060b72u; return 0; }
r[2]=read(ram,0x0c060c4cu,4);
goto P_0c060b74;
P_0c060b74: /* original 6022, guest PC 0x0c060b74 */
if(!s->budget--) { s->failed_pc=0x0c060b74u; return 0; }
tmp=read(ram,r[2],4);
r[0]=tmp;
goto P_0c060b76;
P_0c060b76: /* original c82c, guest PC 0x0c060b76 */
if(!s->budget--) { s->failed_pc=0x0c060b76u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&44u)==0)!=0);
goto P_0c060b78;
P_0c060b78: /* original 8903, guest PC 0x0c060b78 */
if(!s->budget--) { s->failed_pc=0x0c060b78u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c060b82; }
goto P_0c060b7a;
P_0c060b7a: /* original 2dd8, guest PC 0x0c060b7a */
if(!s->budget--) { s->failed_pc=0x0c060b7au; return 0; }
r[17]=(r[17]&~1u)|(((r[13]&r[13])==0)!=0);
goto P_0c060b7c;
P_0c060b7c: /* original 8906, guest PC 0x0c060b7c */
if(!s->budget--) { s->failed_pc=0x0c060b7cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c060b8c; }
goto P_0c060b7e;
P_0c060b7e: /* original a002, guest PC 0x0c060b7e */
if(!s->budget--) { s->failed_pc=0x0c060b7eu; return 0; }
goto P_0c060b86;
P_0c060b80: /* original 0009, guest PC 0x0c060b80 */
if(!s->budget--) { s->failed_pc=0x0c060b80u; return 0; }
goto P_0c060b82;
P_0c060b82: /* original 2448, guest PC 0x0c060b82 */
if(!s->budget--) { s->failed_pc=0x0c060b82u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c060b84;
P_0c060b84: /* original 8902, guest PC 0x0c060b84 */
if(!s->budget--) { s->failed_pc=0x0c060b84u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c060b8c; }
goto P_0c060b86;
P_0c060b86: /* original 9057, guest PC 0x0c060b86 */
if(!s->budget--) { s->failed_pc=0x0c060b86u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c060c38u,2);
goto P_0c060b88;
P_0c060b88: /* original a003, guest PC 0x0c060b88 */
if(!s->budget--) { s->failed_pc=0x0c060b88u; return 0; }
write(ram,r[14]+r[0],r[12],4);
goto P_0c060b92;
P_0c060b8a: /* original 0ec6, guest PC 0x0c060b8a */
if(!s->budget--) { s->failed_pc=0x0c060b8au; return 0; }
write(ram,r[14]+r[0],r[12],4);
goto P_0c060b8c;
P_0c060b8c: /* original 9054, guest PC 0x0c060b8c */
if(!s->budget--) { s->failed_pc=0x0c060b8cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c060c38u,2);
goto P_0c060b8e;
P_0c060b8e: /* original e311, guest PC 0x0c060b8e */
if(!s->budget--) { s->failed_pc=0x0c060b8eu; return 0; }
r[3]=0x00000011u;
goto P_0c060b90;
P_0c060b90: /* original 0e36, guest PC 0x0c060b90 */
if(!s->budget--) { s->failed_pc=0x0c060b90u; return 0; }
write(ram,r[14]+r[0],r[3],4);
goto P_0c060b92;
P_0c060b92: /* original 9052, guest PC 0x0c060b92 */
if(!s->budget--) { s->failed_pc=0x0c060b92u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c060c3au,2);
goto P_0c060b94;
P_0c060b94: /* original 9350, guest PC 0x0c060b94 */
if(!s->budget--) { s->failed_pc=0x0c060b94u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c060c38u,2);
goto P_0c060b96;
P_0c060b96: /* original 0ec6, guest PC 0x0c060b96 */
if(!s->budget--) { s->failed_pc=0x0c060b96u; return 0; }
write(ram,r[14]+r[0],r[12],4);
goto P_0c060b98;
P_0c060b98: /* original d22d, guest PC 0x0c060b98 */
if(!s->budget--) { s->failed_pc=0x0c060b98u; return 0; }
r[2]=read(ram,0x0c060c50u,4);
goto P_0c060b9a;
P_0c060b9a: /* original 2232, guest PC 0x0c060b9a */
if(!s->budget--) { s->failed_pc=0x0c060b9au; return 0; }
write(ram,r[2],r[3],4);
goto P_0c060b9c;
P_0c060b9c: /* original 51e3, guest PC 0x0c060b9c */
if(!s->budget--) { s->failed_pc=0x0c060b9cu; return 0; }
r[1]=read(ram,r[14]+12,4);
goto P_0c060b9e;
P_0c060b9e: /* original e300, guest PC 0x0c060b9e */
if(!s->budget--) { s->failed_pc=0x0c060b9eu; return 0; }
r[3]=0x00000000u;
goto P_0c060ba0;
P_0c060ba0: /* original 3317, guest PC 0x0c060ba0 */
if(!s->budget--) { s->failed_pc=0x0c060ba0u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>(int32_t)r[1])!=0);
goto P_0c060ba2;
P_0c060ba2: /* original 313e, guest PC 0x0c060ba2 */
if(!s->budget--) { s->failed_pc=0x0c060ba2u; return 0; }
wide=(uint64_t)r[1]+r[3]+(r[17]&1u); r[1]=(uint32_t)wide;
r[17]=(r[17]&~1u)|((wide>>32)!=0);
goto P_0c060ba4;
P_0c060ba4: /* original 4121, guest PC 0x0c060ba4 */
if(!s->budget--) { s->failed_pc=0x0c060ba4u; return 0; }
r[17]=(r[17]&~1u)|((r[1]&1)!=0);
r[1]=(uint32_t)((int32_t)r[1]>>1);
goto P_0c060ba6;
P_0c060ba6: /* original 6323, guest PC 0x0c060ba6 */
if(!s->budget--) { s->failed_pc=0x0c060ba6u; return 0; }
r[3]=r[2];
goto P_0c060ba8;
P_0c060ba8: /* original 6032, guest PC 0x0c060ba8 */
if(!s->budget--) { s->failed_pc=0x0c060ba8u; return 0; }
tmp=read(ram,r[3],4);
r[0]=tmp;
goto P_0c060baa;
P_0c060baa: /* original 310c, guest PC 0x0c060baa */
if(!s->budget--) { s->failed_pc=0x0c060baau; return 0; }
r[1]+=r[0];
goto P_0c060bac;
P_0c060bac: /* original d029, guest PC 0x0c060bac */
if(!s->budget--) { s->failed_pc=0x0c060bacu; return 0; }
r[0]=read(ram,0x0c060c54u,4);
goto P_0c060bae;
P_0c060bae: /* original 2012, guest PC 0x0c060bae */
if(!s->budget--) { s->failed_pc=0x0c060baeu; return 0; }
write(ram,r[0],r[1],4);
goto P_0c060bb0;
P_0c060bb0: /* original 52e3, guest PC 0x0c060bb0 */
if(!s->budget--) { s->failed_pc=0x0c060bb0u; return 0; }
r[2]=read(ram,r[14]+12,4);
goto P_0c060bb2;
P_0c060bb2: /* original d129, guest PC 0x0c060bb2 */
if(!s->budget--) { s->failed_pc=0x0c060bb2u; return 0; }
r[1]=read(ram,0x0c060c58u,4);
goto P_0c060bb4;
P_0c060bb4: /* original 2122, guest PC 0x0c060bb4 */
if(!s->budget--) { s->failed_pc=0x0c060bb4u; return 0; }
write(ram,r[1],r[2],4);
goto P_0c060bb6;
P_0c060bb6: /* original 62e3, guest PC 0x0c060bb6 */
if(!s->budget--) { s->failed_pc=0x0c060bb6u; return 0; }
r[2]=r[14];
goto P_0c060bb8;
P_0c060bb8: /* original 9040, guest PC 0x0c060bb8 */
if(!s->budget--) { s->failed_pc=0x0c060bb8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c060c3cu,2);
goto P_0c060bba;
P_0c060bba: /* original 3f08, guest PC 0x0c060bba */
if(!s->budget--) { s->failed_pc=0x0c060bbau; return 0; }
r[15]-=r[0];
goto P_0c060bbc;
P_0c060bbc: /* original d327, guest PC 0x0c060bbc */
if(!s->budget--) { s->failed_pc=0x0c060bbcu; return 0; }
r[3]=read(ram,0x0c060c5cu,4);
goto P_0c060bbe;
P_0c060bbe: /* original 430b, guest PC 0x0c060bbe */
if(!s->budget--) { s->failed_pc=0x0c060bbeu; return 0; }
target=r[3];
r[16]=code_base|0x0c060bc2u;
r[1]=r[15];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c060bc2u) { target=s->pc; goto dispatch; }
goto P_0c060bc2;
P_0c060bc0: /* original 61f3, guest PC 0x0c060bc0 */
if(!s->budget--) { s->failed_pc=0x0c060bc0u; return 0; }
r[1]=r[15];
goto P_0c060bc2;
P_0c060bc2: /* original bcc3, guest PC 0x0c060bc2 */
if(!s->budget--) { s->failed_pc=0x0c060bc2u; return 0; }
target=code_base|0x0c06054cu; r[16]=code_base|0x0c060bc6u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c060bc6u) { target=s->pc; goto dispatch; }
goto P_0c060bc6;
P_0c060bc4: /* original 0009, guest PC 0x0c060bc4 */
if(!s->budget--) { s->failed_pc=0x0c060bc4u; return 0; }
goto P_0c060bc6;
P_0c060bc6: /* original 9239, guest PC 0x0c060bc6 */
if(!s->budget--) { s->failed_pc=0x0c060bc6u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c060c3cu,2);
goto P_0c060bc8;
P_0c060bc8: /* original 9138, guest PC 0x0c060bc8 */
if(!s->budget--) { s->failed_pc=0x0c060bc8u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c060c3cu,2);
goto P_0c060bca;
P_0c060bca: /* original 3f2c, guest PC 0x0c060bca */
if(!s->budget--) { s->failed_pc=0x0c060bcau; return 0; }
r[15]+=r[2];
goto P_0c060bcc;
P_0c060bcc: /* original 3f1c, guest PC 0x0c060bcc */
if(!s->budget--) { s->failed_pc=0x0c060bccu; return 0; }
r[15]+=r[1];
goto P_0c060bce;
P_0c060bce: /* original 4f26, guest PC 0x0c060bce */
if(!s->budget--) { s->failed_pc=0x0c060bceu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c060bd0;
P_0c060bd0: /* original 6cf6, guest PC 0x0c060bd0 */
if(!s->budget--) { s->failed_pc=0x0c060bd0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c060bd2;
P_0c060bd2: /* original 6df6, guest PC 0x0c060bd2 */
if(!s->budget--) { s->failed_pc=0x0c060bd2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c060bd4;
P_0c060bd4: /* original 000b, guest PC 0x0c060bd4 */
if(!s->budget--) { s->failed_pc=0x0c060bd4u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c060bd6: /* original 6ef6, guest PC 0x0c060bd6 */
if(!s->budget--) { s->failed_pc=0x0c060bd6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c060bd8u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c060bd8u; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
