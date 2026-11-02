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
int vf3_away_batch1_adapter_0(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c034800u: goto P_0c034800;
case 0x0c034802u: goto P_0c034802;
case 0x0c034804u: goto P_0c034804;
case 0x0c034806u: goto P_0c034806;
case 0x0c034808u: goto P_0c034808;
case 0x0c03480au: goto P_0c03480a;
case 0x0c03480cu: goto P_0c03480c;
case 0x0c03480eu: goto P_0c03480e;
case 0x0c034810u: goto P_0c034810;
case 0x0c034812u: goto P_0c034812;
case 0x0c034814u: goto P_0c034814;
case 0x0c034816u: goto P_0c034816;
case 0x0c034818u: goto P_0c034818;
case 0x0c03481au: goto P_0c03481a;
case 0x0c03481cu: goto P_0c03481c;
case 0x0c03481eu: goto P_0c03481e;
case 0x0c034820u: goto P_0c034820;
case 0x0c034822u: goto P_0c034822;
case 0x0c034824u: goto P_0c034824;
case 0x0c034826u: goto P_0c034826;
case 0x0c034828u: goto P_0c034828;
case 0x0c03482au: goto P_0c03482a;
case 0x0c03482cu: goto P_0c03482c;
case 0x0c03482eu: goto P_0c03482e;
case 0x0c034830u: goto P_0c034830;
case 0x0c034832u: goto P_0c034832;
case 0x0c034834u: goto P_0c034834;
case 0x0c034836u: goto P_0c034836;
case 0x0c034838u: goto P_0c034838;
case 0x0c03483au: goto P_0c03483a;
case 0x0c03483cu: goto P_0c03483c;
case 0x0c03483eu: goto P_0c03483e;
case 0x0c034840u: goto P_0c034840;
case 0x0c034842u: goto P_0c034842;
case 0x0c034844u: goto P_0c034844;
case 0x0c034846u: goto P_0c034846;
case 0x0c034a64u: goto P_0c034a64;
case 0x0c034a66u: goto P_0c034a66;
case 0x0c034a68u: goto P_0c034a68;
case 0x0c034a6au: goto P_0c034a6a;
case 0x0c034a6cu: goto P_0c034a6c;
case 0x0c034a6eu: goto P_0c034a6e;
case 0x0c034a70u: goto P_0c034a70;
case 0x0c034a72u: goto P_0c034a72;
case 0x0c034a74u: goto P_0c034a74;
case 0x0c034a76u: goto P_0c034a76;
case 0x0c034a78u: goto P_0c034a78;
case 0x0c034a7au: goto P_0c034a7a;
case 0x0c034a7cu: goto P_0c034a7c;
case 0x0c034a7eu: goto P_0c034a7e;
case 0x0c034a80u: goto P_0c034a80;
case 0x0c034a82u: goto P_0c034a82;
case 0x0c034a84u: goto P_0c034a84;
case 0x0c034a86u: goto P_0c034a86;
case 0x0c034a88u: goto P_0c034a88;
case 0x0c034a8au: goto P_0c034a8a;
case 0x0c034a8cu: goto P_0c034a8c;
case 0x0c034a8eu: goto P_0c034a8e;
case 0x0c034a90u: goto P_0c034a90;
case 0x0c034a92u: goto P_0c034a92;
case 0x0c034a94u: goto P_0c034a94;
case 0x0c034a9cu: goto P_0c034a9c;
case 0x0c034a9eu: goto P_0c034a9e;
case 0x0c034aa0u: goto P_0c034aa0;
case 0x0c034aa2u: goto P_0c034aa2;
case 0x0c034aa4u: goto P_0c034aa4;
case 0x0c034aa6u: goto P_0c034aa6;
case 0x0c034aa8u: goto P_0c034aa8;
case 0x0c034aaau: goto P_0c034aaa;
case 0x0c034aacu: goto P_0c034aac;
case 0x0c034aaeu: goto P_0c034aae;
case 0x0c034ab0u: goto P_0c034ab0;
case 0x0c034ab2u: goto P_0c034ab2;
case 0x0c034ab4u: goto P_0c034ab4;
case 0x0c034ab6u: goto P_0c034ab6;
case 0x0c034ab8u: goto P_0c034ab8;
case 0x0c034abau: goto P_0c034aba;
case 0x0c034abcu: goto P_0c034abc;
case 0x0c034abeu: goto P_0c034abe;
case 0x0c034ac0u: goto P_0c034ac0;
case 0x0c034ac2u: goto P_0c034ac2;
case 0x0c034ac4u: goto P_0c034ac4;
case 0x0c034ac6u: goto P_0c034ac6;
case 0x0c034ac8u: goto P_0c034ac8;
case 0x0c034acau: goto P_0c034aca;
case 0x0c034accu: goto P_0c034acc;
case 0x0c034aceu: goto P_0c034ace;
case 0x0c034ad0u: goto P_0c034ad0;
case 0x0c034ad2u: goto P_0c034ad2;
case 0x0c034ad4u: goto P_0c034ad4;
case 0x0c034ad6u: goto P_0c034ad6;
case 0x0c034ad8u: goto P_0c034ad8;
case 0x0c034adau: goto P_0c034ada;
case 0x0c034adcu: goto P_0c034adc;
case 0x0c034adeu: goto P_0c034ade;
case 0x0c034ae0u: goto P_0c034ae0;
case 0x0c034ae2u: goto P_0c034ae2;
case 0x0c034ae4u: goto P_0c034ae4;
case 0x0c034ae6u: goto P_0c034ae6;
case 0x0c034ae8u: goto P_0c034ae8;
case 0x0c034aeau: goto P_0c034aea;
case 0x0c034aecu: goto P_0c034aec;
case 0x0c034aeeu: goto P_0c034aee;
case 0x0c034af0u: goto P_0c034af0;
case 0x0c034af2u: goto P_0c034af2;
case 0x0c034af4u: goto P_0c034af4;
case 0x0c034af6u: goto P_0c034af6;
case 0x0c034af8u: goto P_0c034af8;
case 0x0c034afau: goto P_0c034afa;
case 0x0c034afcu: goto P_0c034afc;
case 0x0c034afeu: goto P_0c034afe;
case 0x0c034b00u: goto P_0c034b00;
case 0x0c034b02u: goto P_0c034b02;
case 0x0c034b04u: goto P_0c034b04;
case 0x0c034b06u: goto P_0c034b06;
case 0x0c034b08u: goto P_0c034b08;
case 0x0c034b0au: goto P_0c034b0a;
case 0x0c034b0cu: goto P_0c034b0c;
case 0x0c034b0eu: goto P_0c034b0e;
case 0x0c034b10u: goto P_0c034b10;
case 0x0c034b12u: goto P_0c034b12;
case 0x0c034b14u: goto P_0c034b14;
case 0x0c034b16u: goto P_0c034b16;
case 0x0c034b18u: goto P_0c034b18;
case 0x0c034b1au: goto P_0c034b1a;
case 0x0c034b1cu: goto P_0c034b1c;
case 0x0c034b1eu: goto P_0c034b1e;
case 0x0c034b20u: goto P_0c034b20;
case 0x0c034b22u: goto P_0c034b22;
case 0x0c034b24u: goto P_0c034b24;
case 0x0c034b26u: goto P_0c034b26;
case 0x0c034b28u: goto P_0c034b28;
case 0x0c034b2au: goto P_0c034b2a;
case 0x0c034b2cu: goto P_0c034b2c;
case 0x0c034b2eu: goto P_0c034b2e;
case 0x0c034b30u: goto P_0c034b30;
case 0x0c034b32u: goto P_0c034b32;
case 0x0c034b34u: goto P_0c034b34;
case 0x0c034b36u: goto P_0c034b36;
case 0x0c034b38u: goto P_0c034b38;
case 0x0c034b3au: goto P_0c034b3a;
case 0x0c034b3cu: goto P_0c034b3c;
case 0x0c034b3eu: goto P_0c034b3e;
case 0x0c034b40u: goto P_0c034b40;
case 0x0c034b42u: goto P_0c034b42;
case 0x0c034b44u: goto P_0c034b44;
case 0x0c034b46u: goto P_0c034b46;
case 0x0c034b48u: goto P_0c034b48;
case 0x0c034b4au: goto P_0c034b4a;
case 0x0c034b4cu: goto P_0c034b4c;
case 0x0c034b4eu: goto P_0c034b4e;
case 0x0c034b50u: goto P_0c034b50;
case 0x0c034b52u: goto P_0c034b52;
case 0x0c034b54u: goto P_0c034b54;
case 0x0c034b56u: goto P_0c034b56;
case 0x0c034b58u: goto P_0c034b58;
case 0x0c034b5au: goto P_0c034b5a;
case 0x0c034b5cu: goto P_0c034b5c;
case 0x0c034b5eu: goto P_0c034b5e;
case 0x0c034b60u: goto P_0c034b60;
case 0x0c034b62u: goto P_0c034b62;
case 0x0c034b64u: goto P_0c034b64;
case 0x0c034b66u: goto P_0c034b66;
case 0x0c034b68u: goto P_0c034b68;
case 0x0c034b6au: goto P_0c034b6a;
case 0x0c034b6cu: goto P_0c034b6c;
case 0x0c034b6eu: goto P_0c034b6e;
case 0x0c034b70u: goto P_0c034b70;
case 0x0c034b72u: goto P_0c034b72;
case 0x0c034b74u: goto P_0c034b74;
case 0x0c034b76u: goto P_0c034b76;
case 0x0c034b78u: goto P_0c034b78;
case 0x0c034b7au: goto P_0c034b7a;
case 0x0c034b7cu: goto P_0c034b7c;
case 0x0c034b7eu: goto P_0c034b7e;
case 0x0c034b80u: goto P_0c034b80;
case 0x0c034b82u: goto P_0c034b82;
case 0x0c034b84u: goto P_0c034b84;
case 0x0c034b86u: goto P_0c034b86;
case 0x0c034b88u: goto P_0c034b88;
case 0x0c034b8au: goto P_0c034b8a;
case 0x0c034b8cu: goto P_0c034b8c;
case 0x0c034b8eu: goto P_0c034b8e;
case 0x0c034b90u: goto P_0c034b90;
case 0x0c034b92u: goto P_0c034b92;
case 0x0c034b94u: goto P_0c034b94;
case 0x0c034b96u: goto P_0c034b96;
case 0x0c034b98u: goto P_0c034b98;
case 0x0c034b9au: goto P_0c034b9a;
case 0x0c034b9cu: goto P_0c034b9c;
case 0x0c034b9eu: goto P_0c034b9e;
case 0x0c034ba0u: goto P_0c034ba0;
case 0x0c034ba2u: goto P_0c034ba2;
case 0x0c034ba4u: goto P_0c034ba4;
case 0x0c034ba6u: goto P_0c034ba6;
case 0x0c034ba8u: goto P_0c034ba8;
case 0x0c034baau: goto P_0c034baa;
case 0x0c034bacu: goto P_0c034bac;
case 0x0c034baeu: goto P_0c034bae;
case 0x0c034bb0u: goto P_0c034bb0;
case 0x0c034bb2u: goto P_0c034bb2;
case 0x0c034bb4u: goto P_0c034bb4;
case 0x0c034bb6u: goto P_0c034bb6;
case 0x0c034bb8u: goto P_0c034bb8;
case 0x0c034bbau: goto P_0c034bba;
case 0x0c034bbcu: goto P_0c034bbc;
case 0x0c034bbeu: goto P_0c034bbe;
case 0x0c034bc0u: goto P_0c034bc0;
case 0x0c034bc2u: goto P_0c034bc2;
case 0x0c034bc4u: goto P_0c034bc4;
case 0x0c034bc6u: goto P_0c034bc6;
case 0x0c034bc8u: goto P_0c034bc8;
case 0x0c034bcau: goto P_0c034bca;
case 0x0c034bccu: goto P_0c034bcc;
case 0x0c034bceu: goto P_0c034bce;
case 0x0c034bd0u: goto P_0c034bd0;
case 0x0c034bd2u: goto P_0c034bd2;
case 0x0c034bd4u: goto P_0c034bd4;
case 0x0c034bd6u: goto P_0c034bd6;
case 0x0c034bd8u: goto P_0c034bd8;
case 0x0c034bdau: goto P_0c034bda;
case 0x0c034bdcu: goto P_0c034bdc;
case 0x0c034c18u: goto P_0c034c18;
case 0x0c034c1au: goto P_0c034c1a;
case 0x0c034c1cu: goto P_0c034c1c;
case 0x0c034c1eu: goto P_0c034c1e;
case 0x0c034c20u: goto P_0c034c20;
case 0x0c034c22u: goto P_0c034c22;
case 0x0c034c24u: goto P_0c034c24;
case 0x0c034c26u: goto P_0c034c26;
case 0x0c034c28u: goto P_0c034c28;
case 0x0c034c2au: goto P_0c034c2a;
case 0x0c034c2cu: goto P_0c034c2c;
case 0x0c034c2eu: goto P_0c034c2e;
case 0x0c034c30u: goto P_0c034c30;
case 0x0c034c32u: goto P_0c034c32;
case 0x0c034c34u: goto P_0c034c34;
case 0x0c034c36u: goto P_0c034c36;
case 0x0c034c38u: goto P_0c034c38;
case 0x0c034c3au: goto P_0c034c3a;
case 0x0c034c3cu: goto P_0c034c3c;
case 0x0c034c3eu: goto P_0c034c3e;
case 0x0c034c40u: goto P_0c034c40;
case 0x0c034c42u: goto P_0c034c42;
case 0x0c034c44u: goto P_0c034c44;
case 0x0c034c46u: goto P_0c034c46;
case 0x0c034c48u: goto P_0c034c48;
case 0x0c034c4au: goto P_0c034c4a;
case 0x0c034c4cu: goto P_0c034c4c;
case 0x0c034c4eu: goto P_0c034c4e;
case 0x0c034c50u: goto P_0c034c50;
case 0x0c034c52u: goto P_0c034c52;
case 0x0c034c54u: goto P_0c034c54;
case 0x0c034c56u: goto P_0c034c56;
case 0x0c034c58u: goto P_0c034c58;
case 0x0c034c5au: goto P_0c034c5a;
case 0x0c034c5cu: goto P_0c034c5c;
case 0x0c034c5eu: goto P_0c034c5e;
case 0x0c034c60u: goto P_0c034c60;
case 0x0c034c62u: goto P_0c034c62;
case 0x0c034c64u: goto P_0c034c64;
case 0x0c034c66u: goto P_0c034c66;
case 0x0c034c68u: goto P_0c034c68;
case 0x0c034c6au: goto P_0c034c6a;
case 0x0c034c6cu: goto P_0c034c6c;
case 0x0c034c6eu: goto P_0c034c6e;
case 0x0c034c70u: goto P_0c034c70;
case 0x0c034c72u: goto P_0c034c72;
case 0x0c034c74u: goto P_0c034c74;
case 0x0c034c76u: goto P_0c034c76;
case 0x0c034c78u: goto P_0c034c78;
case 0x0c034c7au: goto P_0c034c7a;
case 0x0c034c7cu: goto P_0c034c7c;
case 0x0c034c7eu: goto P_0c034c7e;
case 0x0c034c80u: goto P_0c034c80;
case 0x0c034c82u: goto P_0c034c82;
case 0x0c034c84u: goto P_0c034c84;
case 0x0c034c86u: goto P_0c034c86;
case 0x0c034c88u: goto P_0c034c88;
case 0x0c034c8au: goto P_0c034c8a;
case 0x0c034c8cu: goto P_0c034c8c;
case 0x0c034c8eu: goto P_0c034c8e;
case 0x0c034c90u: goto P_0c034c90;
case 0x0c034c92u: goto P_0c034c92;
case 0x0c034c94u: goto P_0c034c94;
case 0x0c034c96u: goto P_0c034c96;
case 0x0c034c98u: goto P_0c034c98;
case 0x0c034c9au: goto P_0c034c9a;
case 0x0c034c9cu: goto P_0c034c9c;
case 0x0c034c9eu: goto P_0c034c9e;
case 0x0c034ca0u: goto P_0c034ca0;
case 0x0c034ca2u: goto P_0c034ca2;
case 0x0c034ca4u: goto P_0c034ca4;
case 0x0c034ca6u: goto P_0c034ca6;
case 0x0c034ca8u: goto P_0c034ca8;
case 0x0c034caau: goto P_0c034caa;
case 0x0c034cacu: goto P_0c034cac;
case 0x0c034caeu: goto P_0c034cae;
case 0x0c034cb0u: goto P_0c034cb0;
case 0x0c034cb2u: goto P_0c034cb2;
case 0x0c034cb4u: goto P_0c034cb4;
case 0x0c034cb6u: goto P_0c034cb6;
case 0x0c034cb8u: goto P_0c034cb8;
case 0x0c034cbau: goto P_0c034cba;
case 0x0c034cbcu: goto P_0c034cbc;
case 0x0c034cbeu: goto P_0c034cbe;
case 0x0c034cc0u: goto P_0c034cc0;
case 0x0c034cc2u: goto P_0c034cc2;
case 0x0c034cc4u: goto P_0c034cc4;
case 0x0c034cc6u: goto P_0c034cc6;
case 0x0c034cc8u: goto P_0c034cc8;
case 0x0c034ccau: goto P_0c034cca;
case 0x0c034cccu: goto P_0c034ccc;
case 0x0c034cceu: goto P_0c034cce;
case 0x0c034cd0u: goto P_0c034cd0;
case 0x0c034cd2u: goto P_0c034cd2;
case 0x0c034cd4u: goto P_0c034cd4;
case 0x0c034cd6u: goto P_0c034cd6;
case 0x0c034cd8u: goto P_0c034cd8;
case 0x0c034cdau: goto P_0c034cda;
case 0x0c034cdcu: goto P_0c034cdc;
case 0x0c034cdeu: goto P_0c034cde;
default: return vf3_matrix_family(target,s,ram);
}
P_0c034800: /* original 8441, guest PC 0x0c034800 */
if(!s->budget--) { s->failed_pc=0x0c034800u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+1,1);
goto P_0c034802;
P_0c034802: /* original 6240, guest PC 0x0c034802 */
if(!s->budget--) { s->failed_pc=0x0c034802u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[4],1);
r[2]=tmp;
goto P_0c034804;
P_0c034804: /* original 600c, guest PC 0x0c034804 */
if(!s->budget--) { s->failed_pc=0x0c034804u; return 0; }
r[0]=r[0]&255u;
goto P_0c034806;
P_0c034806: /* original 4018, guest PC 0x0c034806 */
if(!s->budget--) { s->failed_pc=0x0c034806u; return 0; }
r[0]<<=8;
goto P_0c034808;
P_0c034808: /* original 6303, guest PC 0x0c034808 */
if(!s->budget--) { s->failed_pc=0x0c034808u; return 0; }
r[3]=r[0];
goto P_0c03480a;
P_0c03480a: /* original 8442, guest PC 0x0c03480a */
if(!s->budget--) { s->failed_pc=0x0c03480au; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+2,1);
goto P_0c03480c;
P_0c03480c: /* original 622c, guest PC 0x0c03480c */
if(!s->budget--) { s->failed_pc=0x0c03480cu; return 0; }
r[2]=r[2]&255u;
goto P_0c03480e;
P_0c03480e: /* original 600c, guest PC 0x0c03480e */
if(!s->budget--) { s->failed_pc=0x0c03480eu; return 0; }
r[0]=r[0]&255u;
goto P_0c034810;
P_0c034810: /* original 4028, guest PC 0x0c034810 */
if(!s->budget--) { s->failed_pc=0x0c034810u; return 0; }
r[0]<<=16;
goto P_0c034812;
P_0c034812: /* original 230b, guest PC 0x0c034812 */
if(!s->budget--) { s->failed_pc=0x0c034812u; return 0; }
r[3]|=r[0];
goto P_0c034814;
P_0c034814: /* original 8443, guest PC 0x0c034814 */
if(!s->budget--) { s->failed_pc=0x0c034814u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+3,1);
goto P_0c034816;
P_0c034816: /* original 600c, guest PC 0x0c034816 */
if(!s->budget--) { s->failed_pc=0x0c034816u; return 0; }
r[0]=r[0]&255u;
goto P_0c034818;
P_0c034818: /* original 4028, guest PC 0x0c034818 */
if(!s->budget--) { s->failed_pc=0x0c034818u; return 0; }
r[0]<<=16;
goto P_0c03481a;
P_0c03481a: /* original 4018, guest PC 0x0c03481a */
if(!s->budget--) { s->failed_pc=0x0c03481au; return 0; }
r[0]<<=8;
goto P_0c03481c;
P_0c03481c: /* original 230b, guest PC 0x0c03481c */
if(!s->budget--) { s->failed_pc=0x0c03481cu; return 0; }
r[3]|=r[0];
goto P_0c03481e;
P_0c03481e: /* original 6433, guest PC 0x0c03481e */
if(!s->budget--) { s->failed_pc=0x0c03481eu; return 0; }
r[4]=r[3];
goto P_0c034820;
P_0c034820: /* original 242b, guest PC 0x0c034820 */
if(!s->budget--) { s->failed_pc=0x0c034820u; return 0; }
r[4]|=r[2];
goto P_0c034822;
P_0c034822: /* original 000b, guest PC 0x0c034822 */
if(!s->budget--) { s->failed_pc=0x0c034822u; return 0; }
target=r[16];
r[0]=r[4];
s->pc=target; return ram->oob==0;
P_0c034824: /* original 6043, guest PC 0x0c034824 */
if(!s->budget--) { s->failed_pc=0x0c034824u; return 0; }
r[0]=r[4];
goto P_0c034826;
P_0c034826: /* original 6743, guest PC 0x0c034826 */
if(!s->budget--) { s->failed_pc=0x0c034826u; return 0; }
r[7]=r[4];
goto P_0c034828;
P_0c034828: /* original d686, guest PC 0x0c034828 */
if(!s->budget--) { s->failed_pc=0x0c034828u; return 0; }
r[6]=read(ram,0x0c034a44u,4);
goto P_0c03482a;
P_0c03482a: /* original e505, guest PC 0x0c03482a */
if(!s->budget--) { s->failed_pc=0x0c03482au; return 0; }
r[5]=0x00000005u;
goto P_0c03482c;
P_0c03482c: /* original e400, guest PC 0x0c03482c */
if(!s->budget--) { s->failed_pc=0x0c03482cu; return 0; }
r[4]=0x00000000u;
goto P_0c03482e;
P_0c03482e: /* original 7701, guest PC 0x0c03482e */
if(!s->budget--) { s->failed_pc=0x0c03482eu; return 0; }
r[7]+=0x00000001u;
goto P_0c034830;
P_0c034830: /* original 6274, guest PC 0x0c034830 */
if(!s->budget--) { s->failed_pc=0x0c034830u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[7],1);
r[7]+=1;
r[2]=tmp;
goto P_0c034832;
P_0c034832: /* original 6364, guest PC 0x0c034832 */
if(!s->budget--) { s->failed_pc=0x0c034832u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[6],1);
r[6]+=1;
r[3]=tmp;
goto P_0c034834;
P_0c034834: /* original 3320, guest PC 0x0c034834 */
if(!s->budget--) { s->failed_pc=0x0c034834u; return 0; }
r[17]=(r[17]&~1u)|((r[3]==r[2])!=0);
goto P_0c034836;
P_0c034836: /* original 8901, guest PC 0x0c034836 */
if(!s->budget--) { s->failed_pc=0x0c034836u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c03483c; }
goto P_0c034838;
P_0c034838: /* original 000b, guest PC 0x0c034838 */
if(!s->budget--) { s->failed_pc=0x0c034838u; return 0; }
target=r[16];
r[0]=0x00000000u;
s->pc=target; return ram->oob==0;
P_0c03483a: /* original e000, guest PC 0x0c03483a */
if(!s->budget--) { s->failed_pc=0x0c03483au; return 0; }
r[0]=0x00000000u;
goto P_0c03483c;
P_0c03483c: /* original 7401, guest PC 0x0c03483c */
if(!s->budget--) { s->failed_pc=0x0c03483cu; return 0; }
r[4]+=0x00000001u;
goto P_0c03483e;
P_0c03483e: /* original 3453, guest PC 0x0c03483e */
if(!s->budget--) { s->failed_pc=0x0c03483eu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=(int32_t)r[5])!=0);
goto P_0c034840;
P_0c034840: /* original 8bf6, guest PC 0x0c034840 */
if(!s->budget--) { s->failed_pc=0x0c034840u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c034830; }
goto P_0c034842;
P_0c034842: /* original e001, guest PC 0x0c034842 */
if(!s->budget--) { s->failed_pc=0x0c034842u; return 0; }
r[0]=0x00000001u;
goto P_0c034844;
P_0c034844: /* original 000b, guest PC 0x0c034844 */
if(!s->budget--) { s->failed_pc=0x0c034844u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c034846: /* original 0009, guest PC 0x0c034846 */
if(!s->budget--) { s->failed_pc=0x0c034846u; return 0; }
if(!vf3_matrix_family(0x0c034848u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c034848u; return 0; } return 1;
P_0c034a64: /* original 2fe6, guest PC 0x0c034a64 */
if(!s->budget--) { s->failed_pc=0x0c034a64u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c034a66;
P_0c034a66: /* original 2fd6, guest PC 0x0c034a66 */
if(!s->budget--) { s->failed_pc=0x0c034a66u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c034a68;
P_0c034a68: /* original 2fc6, guest PC 0x0c034a68 */
if(!s->budget--) { s->failed_pc=0x0c034a68u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c034a6a;
P_0c034a6a: /* original 2fb6, guest PC 0x0c034a6a */
if(!s->budget--) { s->failed_pc=0x0c034a6au; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c034a6c;
P_0c034a6c: /* original 2f86, guest PC 0x0c034a6c */
if(!s->budget--) { s->failed_pc=0x0c034a6cu; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c034a6e;
P_0c034a6e: /* original 4f22, guest PC 0x0c034a6e */
if(!s->budget--) { s->failed_pc=0x0c034a6eu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c034a70;
P_0c034a70: /* original 7fe4, guest PC 0x0c034a70 */
if(!s->budget--) { s->failed_pc=0x0c034a70u; return 0; }
r[15]+=0xffffffe4u;
goto P_0c034a72;
P_0c034a72: /* original 1f42, guest PC 0x0c034a72 */
if(!s->budget--) { s->failed_pc=0x0c034a72u; return 0; }
write(ram,r[15]+8,r[4],4);
goto P_0c034a74;
P_0c034a74: /* original 2f52, guest PC 0x0c034a74 */
if(!s->budget--) { s->failed_pc=0x0c034a74u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c034a76;
P_0c034a76: /* original 1f61, guest PC 0x0c034a76 */
if(!s->budget--) { s->failed_pc=0x0c034a76u; return 0; }
write(ram,r[15]+4,r[6],4);
goto P_0c034a78;
P_0c034a78: /* original 1f73, guest PC 0x0c034a78 */
if(!s->budget--) { s->failed_pc=0x0c034a78u; return 0; }
write(ram,r[15]+12,r[7],4);
goto P_0c034a7a;
P_0c034a7a: /* original de07, guest PC 0x0c034a7a */
if(!s->budget--) { s->failed_pc=0x0c034a7au; return 0; }
r[14]=read(ram,0x0c034a98u,4);
goto P_0c034a7c;
P_0c034a7c: /* original 64e2, guest PC 0x0c034a7c */
if(!s->budget--) { s->failed_pc=0x0c034a7cu; return 0; }
tmp=read(ram,r[14],4);
r[4]=tmp;
goto P_0c034a7e;
P_0c034a7e: /* original 2448, guest PC 0x0c034a7e */
if(!s->budget--) { s->failed_pc=0x0c034a7eu; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c034a80;
P_0c034a80: /* original 8904, guest PC 0x0c034a80 */
if(!s->budget--) { s->failed_pc=0x0c034a80u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c034a8c; }
goto P_0c034a82;
P_0c034a82: /* original 5048, guest PC 0x0c034a82 */
if(!s->budget--) { s->failed_pc=0x0c034a82u; return 0; }
r[0]=read(ram,r[4]+32,4);
goto P_0c034a84;
P_0c034a84: /* original 8801, guest PC 0x0c034a84 */
if(!s->budget--) { s->failed_pc=0x0c034a84u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c034a86;
P_0c034a86: /* original 8b01, guest PC 0x0c034a86 */
if(!s->budget--) { s->failed_pc=0x0c034a86u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c034a8c; }
goto P_0c034a88;
P_0c034a88: /* original a121, guest PC 0x0c034a88 */
if(!s->budget--) { s->failed_pc=0x0c034a88u; return 0; }
goto P_0c034cce;
P_0c034a8a: /* original 0009, guest PC 0x0c034a8a */
if(!s->budget--) { s->failed_pc=0x0c034a8au; return 0; }
goto P_0c034a8c;
P_0c034a8c: /* original 60f2, guest PC 0x0c034a8c */
if(!s->budget--) { s->failed_pc=0x0c034a8cu; return 0; }
tmp=read(ram,r[15],4);
r[0]=tmp;
goto P_0c034a8e;
P_0c034a8e: /* original c81f, guest PC 0x0c034a8e */
if(!s->budget--) { s->failed_pc=0x0c034a8eu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&31u)==0)!=0);
goto P_0c034a90;
P_0c034a90: /* original 8904, guest PC 0x0c034a90 */
if(!s->budget--) { s->failed_pc=0x0c034a90u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c034a9c; }
goto P_0c034a92;
P_0c034a92: /* original a11d, guest PC 0x0c034a92 */
if(!s->budget--) { s->failed_pc=0x0c034a92u; return 0; }
r[0]=0xfffffff2u;
goto P_0c034cd0;
P_0c034a94: /* original e0f2, guest PC 0x0c034a94 */
if(!s->budget--) { s->failed_pc=0x0c034a94u; return 0; }
r[0]=0xfffffff2u;
if(!vf3_matrix_family(0x0c034a96u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c034a96u; return 0; } return 1;
P_0c034a9c: /* original d252, guest PC 0x0c034a9c */
if(!s->budget--) { s->failed_pc=0x0c034a9cu; return 0; }
r[2]=read(ram,0x0c034be8u,4);
goto P_0c034a9e;
P_0c034a9e: /* original 420b, guest PC 0x0c034a9e */
if(!s->budget--) { s->failed_pc=0x0c034a9eu; return 0; }
target=r[2];
r[16]=code_base|0x0c034aa2u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c034aa2u) { target=s->pc; goto dispatch; }
goto P_0c034aa2;
P_0c034aa0: /* original 0009, guest PC 0x0c034aa0 */
if(!s->budget--) { s->failed_pc=0x0c034aa0u; return 0; }
goto P_0c034aa2;
P_0c034aa2: /* original dd53, guest PC 0x0c034aa2 */
if(!s->budget--) { s->failed_pc=0x0c034aa2u; return 0; }
r[13]=read(ram,0x0c034bf0u,4);
goto P_0c034aa4;
P_0c034aa4: /* original 6b03, guest PC 0x0c034aa4 */
if(!s->budget--) { s->failed_pc=0x0c034aa4u; return 0; }
r[11]=r[0];
goto P_0c034aa6;
P_0c034aa6: /* original 949a, guest PC 0x0c034aa6 */
if(!s->budget--) { s->failed_pc=0x0c034aa6u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c034bdeu,2);
goto P_0c034aa8;
P_0c034aa8: /* original e610, guest PC 0x0c034aa8 */
if(!s->budget--) { s->failed_pc=0x0c034aa8u; return 0; }
r[6]=0x00000010u;
goto P_0c034aaa;
P_0c034aaa: /* original dc50, guest PC 0x0c034aaa */
if(!s->budget--) { s->failed_pc=0x0c034aaau; return 0; }
r[12]=read(ram,0x0c034becu,4);
goto P_0c034aac;
P_0c034aac: /* original e700, guest PC 0x0c034aac */
if(!s->budget--) { s->failed_pc=0x0c034aacu; return 0; }
r[7]=0x00000000u;
goto P_0c034aae;
P_0c034aae: /* original 4c0b, guest PC 0x0c034aae */
if(!s->budget--) { s->failed_pc=0x0c034aaeu; return 0; }
target=r[12];
r[16]=code_base|0x0c034ab2u;
r[5]=r[7];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c034ab2u) { target=s->pc; goto dispatch; }
goto P_0c034ab2;
P_0c034ab0: /* original 6573, guest PC 0x0c034ab0 */
if(!s->budget--) { s->failed_pc=0x0c034ab0u; return 0; }
r[5]=r[7];
goto P_0c034ab2;
P_0c034ab2: /* original 2d02, guest PC 0x0c034ab2 */
if(!s->budget--) { s->failed_pc=0x0c034ab2u; return 0; }
write(ram,r[13],r[0],4);
goto P_0c034ab4;
P_0c034ab4: /* original 63b2, guest PC 0x0c034ab4 */
if(!s->budget--) { s->failed_pc=0x0c034ab4u; return 0; }
tmp=read(ram,r[11],4);
r[3]=tmp;
goto P_0c034ab6;
P_0c034ab6: /* original 430b, guest PC 0x0c034ab6 */
if(!s->budget--) { s->failed_pc=0x0c034ab6u; return 0; }
target=r[3];
r[16]=code_base|0x0c034abau;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c034abau) { target=s->pc; goto dispatch; }
goto P_0c034aba;
P_0c034ab8: /* original 0009, guest PC 0x0c034ab8 */
if(!s->budget--) { s->failed_pc=0x0c034ab8u; return 0; }
goto P_0c034aba;
P_0c034aba: /* original 0002, guest PC 0x0c034aba */
if(!s->budget--) { s->failed_pc=0x0c034abau; return 0; }
r[0]=r[17];
goto P_0c034abc;
P_0c034abc: /* original 4009, guest PC 0x0c034abc */
if(!s->budget--) { s->failed_pc=0x0c034abcu; return 0; }
r[0]>>=2;
goto P_0c034abe;
P_0c034abe: /* original 4009, guest PC 0x0c034abe */
if(!s->budget--) { s->failed_pc=0x0c034abeu; return 0; }
r[0]>>=2;
goto P_0c034ac0;
P_0c034ac0: /* original c90f, guest PC 0x0c034ac0 */
if(!s->budget--) { s->failed_pc=0x0c034ac0u; return 0; }
r[0]&=15u;
goto P_0c034ac2;
P_0c034ac2: /* original 1f04, guest PC 0x0c034ac2 */
if(!s->budget--) { s->failed_pc=0x0c034ac2u; return 0; }
write(ram,r[15]+16,r[0],4);
goto P_0c034ac4;
P_0c034ac4: /* original 0002, guest PC 0x0c034ac4 */
if(!s->budget--) { s->failed_pc=0x0c034ac4u; return 0; }
r[0]=r[17];
goto P_0c034ac6;
P_0c034ac6: /* original 938b, guest PC 0x0c034ac6 */
if(!s->budget--) { s->failed_pc=0x0c034ac6u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c034be0u,2);
goto P_0c034ac8;
P_0c034ac8: /* original 2039, guest PC 0x0c034ac8 */
if(!s->budget--) { s->failed_pc=0x0c034ac8u; return 0; }
r[0]&=r[3];
goto P_0c034aca;
P_0c034aca: /* original cbf0, guest PC 0x0c034aca */
if(!s->budget--) { s->failed_pc=0x0c034acau; return 0; }
r[0]|=240u;
goto P_0c034acc;
P_0c034acc: /* original 400e, guest PC 0x0c034acc */
if(!s->budget--) { s->failed_pc=0x0c034accu; return 0; }
r[17]=r[0];
goto P_0c034ace;
P_0c034ace: /* original 62f2, guest PC 0x0c034ace */
if(!s->budget--) { s->failed_pc=0x0c034aceu; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c034ad0;
P_0c034ad0: /* original 6323, guest PC 0x0c034ad0 */
if(!s->budget--) { s->failed_pc=0x0c034ad0u; return 0; }
r[3]=r[2];
goto P_0c034ad2;
P_0c034ad2: /* original 2e22, guest PC 0x0c034ad2 */
if(!s->budget--) { s->failed_pc=0x0c034ad2u; return 0; }
write(ram,r[14],r[2],4);
goto P_0c034ad4;
P_0c034ad4: /* original e200, guest PC 0x0c034ad4 */
if(!s->budget--) { s->failed_pc=0x0c034ad4u; return 0; }
r[2]=0x00000000u;
goto P_0c034ad6;
P_0c034ad6: /* original 1328, guest PC 0x0c034ad6 */
if(!s->budget--) { s->failed_pc=0x0c034ad6u; return 0; }
write(ram,r[3]+32,r[2],4);
goto P_0c034ad8;
P_0c034ad8: /* original 63e2, guest PC 0x0c034ad8 */
if(!s->budget--) { s->failed_pc=0x0c034ad8u; return 0; }
tmp=read(ram,r[14],4);
r[3]=tmp;
goto P_0c034ada;
P_0c034ada: /* original 1329, guest PC 0x0c034ada */
if(!s->budget--) { s->failed_pc=0x0c034adau; return 0; }
write(ram,r[3]+36,r[2],4);
goto P_0c034adc;
P_0c034adc: /* original 52f2, guest PC 0x0c034adc */
if(!s->budget--) { s->failed_pc=0x0c034adcu; return 0; }
r[2]=read(ram,r[15]+8,4);
goto P_0c034ade;
P_0c034ade: /* original 63e2, guest PC 0x0c034ade */
if(!s->budget--) { s->failed_pc=0x0c034adeu; return 0; }
tmp=read(ram,r[14],4);
r[3]=tmp;
goto P_0c034ae0;
P_0c034ae0: /* original 2322, guest PC 0x0c034ae0 */
if(!s->budget--) { s->failed_pc=0x0c034ae0u; return 0; }
write(ram,r[3],r[2],4);
goto P_0c034ae2;
P_0c034ae2: /* original 68e2, guest PC 0x0c034ae2 */
if(!s->budget--) { s->failed_pc=0x0c034ae2u; return 0; }
tmp=read(ram,r[14],4);
r[8]=tmp;
goto P_0c034ae4;
P_0c034ae4: /* original 55f1, guest PC 0x0c034ae4 */
if(!s->budget--) { s->failed_pc=0x0c034ae4u; return 0; }
r[5]=read(ram,r[15]+4,4);
goto P_0c034ae6;
P_0c034ae6: /* original d343, guest PC 0x0c034ae6 */
if(!s->budget--) { s->failed_pc=0x0c034ae6u; return 0; }
r[3]=read(ram,0x0c034bf4u,4);
goto P_0c034ae8;
P_0c034ae8: /* original 7818, guest PC 0x0c034ae8 */
if(!s->budget--) { s->failed_pc=0x0c034ae8u; return 0; }
r[8]+=0x00000018u;
goto P_0c034aea;
P_0c034aea: /* original 430b, guest PC 0x0c034aea */
if(!s->budget--) { s->failed_pc=0x0c034aeau; return 0; }
target=r[3];
r[16]=code_base|0x0c034aeeu;
r[4]=read(ram,r[15]+12,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c034aeeu) { target=s->pc; goto dispatch; }
goto P_0c034aee;
P_0c034aec: /* original 54f3, guest PC 0x0c034aec */
if(!s->budget--) { s->failed_pc=0x0c034aecu; return 0; }
r[4]=read(ram,r[15]+12,4);
goto P_0c034aee;
P_0c034aee: /* original 2802, guest PC 0x0c034aee */
if(!s->budget--) { s->failed_pc=0x0c034aeeu; return 0; }
write(ram,r[8],r[0],4);
goto P_0c034af0;
P_0c034af0: /* original d141, guest PC 0x0c034af0 */
if(!s->budget--) { s->failed_pc=0x0c034af0u; return 0; }
r[1]=read(ram,0x0c034bf8u,4);
goto P_0c034af2;
P_0c034af2: /* original 63e2, guest PC 0x0c034af2 */
if(!s->budget--) { s->failed_pc=0x0c034af2u; return 0; }
tmp=read(ram,r[14],4);
r[3]=tmp;
goto P_0c034af4;
P_0c034af4: /* original 6212, guest PC 0x0c034af4 */
if(!s->budget--) { s->failed_pc=0x0c034af4u; return 0; }
tmp=read(ram,r[1],4);
r[2]=tmp;
goto P_0c034af6;
P_0c034af6: /* original 1321, guest PC 0x0c034af6 */
if(!s->budget--) { s->failed_pc=0x0c034af6u; return 0; }
write(ram,r[3]+4,r[2],4);
goto P_0c034af8;
P_0c034af8: /* original d040, guest PC 0x0c034af8 */
if(!s->budget--) { s->failed_pc=0x0c034af8u; return 0; }
r[0]=read(ram,0x0c034bfcu,4);
goto P_0c034afa;
P_0c034afa: /* original 63e2, guest PC 0x0c034afa */
if(!s->budget--) { s->failed_pc=0x0c034afau; return 0; }
tmp=read(ram,r[14],4);
r[3]=tmp;
goto P_0c034afc;
P_0c034afc: /* original 6202, guest PC 0x0c034afc */
if(!s->budget--) { s->failed_pc=0x0c034afcu; return 0; }
tmp=read(ram,r[0],4);
r[2]=tmp;
goto P_0c034afe;
P_0c034afe: /* original 1322, guest PC 0x0c034afe */
if(!s->budget--) { s->failed_pc=0x0c034afeu; return 0; }
write(ram,r[3]+8,r[2],4);
goto P_0c034b00;
P_0c034b00: /* original 63e2, guest PC 0x0c034b00 */
if(!s->budget--) { s->failed_pc=0x0c034b00u; return 0; }
tmp=read(ram,r[14],4);
r[3]=tmp;
goto P_0c034b02;
P_0c034b02: /* original 13b5, guest PC 0x0c034b02 */
if(!s->budget--) { s->failed_pc=0x0c034b02u; return 0; }
write(ram,r[3]+20,r[11],4);
goto P_0c034b04;
P_0c034b04: /* original e300, guest PC 0x0c034b04 */
if(!s->budget--) { s->failed_pc=0x0c034b04u; return 0; }
r[3]=0x00000000u;
goto P_0c034b06;
P_0c034b06: /* original 62e2, guest PC 0x0c034b06 */
if(!s->budget--) { s->failed_pc=0x0c034b06u; return 0; }
tmp=read(ram,r[14],4);
r[2]=tmp;
goto P_0c034b08;
P_0c034b08: /* original 123a, guest PC 0x0c034b08 */
if(!s->budget--) { s->failed_pc=0x0c034b08u; return 0; }
write(ram,r[2]+40,r[3],4);
goto P_0c034b0a;
P_0c034b0a: /* original 62e2, guest PC 0x0c034b0a */
if(!s->budget--) { s->failed_pc=0x0c034b0au; return 0; }
tmp=read(ram,r[14],4);
r[2]=tmp;
goto P_0c034b0c;
P_0c034b0c: /* original 6533, guest PC 0x0c034b0c */
if(!s->budget--) { s->failed_pc=0x0c034b0cu; return 0; }
r[5]=r[3];
goto P_0c034b0e;
P_0c034b0e: /* original 64e2, guest PC 0x0c034b0e */
if(!s->budget--) { s->failed_pc=0x0c034b0eu; return 0; }
tmp=read(ram,r[14],4);
r[4]=tmp;
goto P_0c034b10;
P_0c034b10: /* original 6122, guest PC 0x0c034b10 */
if(!s->budget--) { s->failed_pc=0x0c034b10u; return 0; }
tmp=read(ram,r[2],4);
r[1]=tmp;
goto P_0c034b12;
P_0c034b12: /* original 9366, guest PC 0x0c034b12 */
if(!s->budget--) { s->failed_pc=0x0c034b12u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c034be2u,2);
goto P_0c034b14;
P_0c034b14: /* original 7101, guest PC 0x0c034b14 */
if(!s->budget--) { s->failed_pc=0x0c034b14u; return 0; }
r[1]+=0x00000001u;
goto P_0c034b16;
P_0c034b16: /* original 4115, guest PC 0x0c034b16 */
if(!s->budget--) { s->failed_pc=0x0c034b16u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[1]>0)!=0);
goto P_0c034b18;
P_0c034b18: /* original 343c, guest PC 0x0c034b18 */
if(!s->budget--) { s->failed_pc=0x0c034b18u; return 0; }
r[4]+=r[3];
goto P_0c034b1a;
P_0c034b1a: /* original 8f09, guest PC 0x0c034b1a */
if(!s->budget--) { s->failed_pc=0x0c034b1au; return 0; }
cond=r[17]&1u;
r[6]=0x00000000u;
if(!cond) { goto P_0c034b30; }
goto P_0c034b1e;
P_0c034b1c: /* original e600, guest PC 0x0c034b1c */
if(!s->budget--) { s->failed_pc=0x0c034b1cu; return 0; }
r[6]=0x00000000u;
goto P_0c034b1e;
P_0c034b1e: /* original e048, guest PC 0x0c034b1e */
if(!s->budget--) { s->failed_pc=0x0c034b1eu; return 0; }
r[0]=0x00000048u;
goto P_0c034b20;
P_0c034b20: /* original 7501, guest PC 0x0c034b20 */
if(!s->budget--) { s->failed_pc=0x0c034b20u; return 0; }
r[5]+=0x00000001u;
goto P_0c034b22;
P_0c034b22: /* original 0465, guest PC 0x0c034b22 */
if(!s->budget--) { s->failed_pc=0x0c034b22u; return 0; }
write(ram,r[4]+r[0],r[6],2);
goto P_0c034b24;
P_0c034b24: /* original 63e2, guest PC 0x0c034b24 */
if(!s->budget--) { s->failed_pc=0x0c034b24u; return 0; }
tmp=read(ram,r[14],4);
r[3]=tmp;
goto P_0c034b26;
P_0c034b26: /* original 6232, guest PC 0x0c034b26 */
if(!s->budget--) { s->failed_pc=0x0c034b26u; return 0; }
tmp=read(ram,r[3],4);
r[2]=tmp;
goto P_0c034b28;
P_0c034b28: /* original 7201, guest PC 0x0c034b28 */
if(!s->budget--) { s->failed_pc=0x0c034b28u; return 0; }
r[2]+=0x00000001u;
goto P_0c034b2a;
P_0c034b2a: /* original 3523, guest PC 0x0c034b2a */
if(!s->budget--) { s->failed_pc=0x0c034b2au; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[5]>=(int32_t)r[2])!=0);
goto P_0c034b2c;
P_0c034b2c: /* original 8ff7, guest PC 0x0c034b2c */
if(!s->budget--) { s->failed_pc=0x0c034b2cu; return 0; }
cond=r[17]&1u;
r[4]+=0x00000050u;
if(!cond) { goto P_0c034b1e; }
goto P_0c034b30;
P_0c034b2e: /* original 7450, guest PC 0x0c034b2e */
if(!s->budget--) { s->failed_pc=0x0c034b2eu; return 0; }
r[4]+=0x00000050u;
goto P_0c034b30;
P_0c034b30: /* original 62e2, guest PC 0x0c034b30 */
if(!s->budget--) { s->failed_pc=0x0c034b30u; return 0; }
tmp=read(ram,r[14],4);
r[2]=tmp;
goto P_0c034b32;
P_0c034b32: /* original 9156, guest PC 0x0c034b32 */
if(!s->budget--) { s->failed_pc=0x0c034b32u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c034be2u,2);
goto P_0c034b34;
P_0c034b34: /* original 6323, guest PC 0x0c034b34 */
if(!s->budget--) { s->failed_pc=0x0c034b34u; return 0; }
r[3]=r[2];
goto P_0c034b36;
P_0c034b36: /* original 313c, guest PC 0x0c034b36 */
if(!s->budget--) { s->failed_pc=0x0c034b36u; return 0; }
r[1]+=r[3];
goto P_0c034b38;
P_0c034b38: /* original 121b, guest PC 0x0c034b38 */
if(!s->budget--) { s->failed_pc=0x0c034b38u; return 0; }
write(ram,r[2]+44,r[1],4);
goto P_0c034b3a;
P_0c034b3a: /* original 63e2, guest PC 0x0c034b3a */
if(!s->budget--) { s->failed_pc=0x0c034b3au; return 0; }
tmp=read(ram,r[14],4);
r[3]=tmp;
goto P_0c034b3c;
P_0c034b3c: /* original 9151, guest PC 0x0c034b3c */
if(!s->budget--) { s->failed_pc=0x0c034b3cu; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c034be2u,2);
goto P_0c034b3e;
P_0c034b3e: /* original 6233, guest PC 0x0c034b3e */
if(!s->budget--) { s->failed_pc=0x0c034b3eu; return 0; }
r[2]=r[3];
goto P_0c034b40;
P_0c034b40: /* original 312c, guest PC 0x0c034b40 */
if(!s->budget--) { s->failed_pc=0x0c034b40u; return 0; }
r[1]+=r[2];
goto P_0c034b42;
P_0c034b42: /* original 7150, guest PC 0x0c034b42 */
if(!s->budget--) { s->failed_pc=0x0c034b42u; return 0; }
r[1]+=0x00000050u;
goto P_0c034b44;
P_0c034b44: /* original 131c, guest PC 0x0c034b44 */
if(!s->budget--) { s->failed_pc=0x0c034b44u; return 0; }
write(ram,r[3]+48,r[1],4);
goto P_0c034b46;
P_0c034b46: /* original d22e, guest PC 0x0c034b46 */
if(!s->budget--) { s->failed_pc=0x0c034b46u; return 0; }
r[2]=read(ram,0x0c034c00u,4);
goto P_0c034b48;
P_0c034b48: /* original 6322, guest PC 0x0c034b48 */
if(!s->budget--) { s->failed_pc=0x0c034b48u; return 0; }
tmp=read(ram,r[2],4);
r[3]=tmp;
goto P_0c034b4a;
P_0c034b4a: /* original 2338, guest PC 0x0c034b4a */
if(!s->budget--) { s->failed_pc=0x0c034b4au; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c034b4c;
P_0c034b4c: /* original 8b06, guest PC 0x0c034b4c */
if(!s->budget--) { s->failed_pc=0x0c034b4cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c034b5c; }
goto P_0c034b4e;
P_0c034b4e: /* original 9449, guest PC 0x0c034b4e */
if(!s->budget--) { s->failed_pc=0x0c034b4eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c034be4u,2);
goto P_0c034b50;
P_0c034b50: /* original e700, guest PC 0x0c034b50 */
if(!s->budget--) { s->failed_pc=0x0c034b50u; return 0; }
r[7]=0x00000000u;
goto P_0c034b52;
P_0c034b52: /* original d52c, guest PC 0x0c034b52 */
if(!s->budget--) { s->failed_pc=0x0c034b52u; return 0; }
r[5]=read(ram,0x0c034c04u,4);
goto P_0c034b54;
P_0c034b54: /* original 4c0b, guest PC 0x0c034b54 */
if(!s->budget--) { s->failed_pc=0x0c034b54u; return 0; }
target=r[12];
r[16]=code_base|0x0c034b58u;
r[6]=0x00000050u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c034b58u) { target=s->pc; goto dispatch; }
goto P_0c034b58;
P_0c034b56: /* original e650, guest PC 0x0c034b56 */
if(!s->budget--) { s->failed_pc=0x0c034b56u; return 0; }
r[6]=0x00000050u;
goto P_0c034b58;
P_0c034b58: /* original d329, guest PC 0x0c034b58 */
if(!s->budget--) { s->failed_pc=0x0c034b58u; return 0; }
r[3]=read(ram,0x0c034c00u,4);
goto P_0c034b5a;
P_0c034b5a: /* original 2302, guest PC 0x0c034b5a */
if(!s->budget--) { s->failed_pc=0x0c034b5au; return 0; }
write(ram,r[3],r[0],4);
goto P_0c034b5c;
P_0c034b5c: /* original 62d2, guest PC 0x0c034b5c */
if(!s->budget--) { s->failed_pc=0x0c034b5cu; return 0; }
tmp=read(ram,r[13],4);
r[2]=tmp;
goto P_0c034b5e;
P_0c034b5e: /* original 2228, guest PC 0x0c034b5e */
if(!s->budget--) { s->failed_pc=0x0c034b5eu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c034b60;
P_0c034b60: /* original 8b05, guest PC 0x0c034b60 */
if(!s->budget--) { s->failed_pc=0x0c034b60u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c034b6e; }
goto P_0c034b62;
P_0c034b62: /* original 943c, guest PC 0x0c034b62 */
if(!s->budget--) { s->failed_pc=0x0c034b62u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c034bdeu,2);
goto P_0c034b64;
P_0c034b64: /* original e700, guest PC 0x0c034b64 */
if(!s->budget--) { s->failed_pc=0x0c034b64u; return 0; }
r[7]=0x00000000u;
goto P_0c034b66;
P_0c034b66: /* original d528, guest PC 0x0c034b66 */
if(!s->budget--) { s->failed_pc=0x0c034b66u; return 0; }
r[5]=read(ram,0x0c034c08u,4);
goto P_0c034b68;
P_0c034b68: /* original 4c0b, guest PC 0x0c034b68 */
if(!s->budget--) { s->failed_pc=0x0c034b68u; return 0; }
target=r[12];
r[16]=code_base|0x0c034b6cu;
r[6]=0x00000010u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c034b6cu) { target=s->pc; goto dispatch; }
goto P_0c034b6c;
P_0c034b6a: /* original e610, guest PC 0x0c034b6a */
if(!s->budget--) { s->failed_pc=0x0c034b6au; return 0; }
r[6]=0x00000010u;
goto P_0c034b6c;
P_0c034b6c: /* original 2d02, guest PC 0x0c034b6c */
if(!s->budget--) { s->failed_pc=0x0c034b6cu; return 0; }
write(ram,r[13],r[0],4);
goto P_0c034b6e;
P_0c034b6e: /* original 50f4, guest PC 0x0c034b6e */
if(!s->budget--) { s->failed_pc=0x0c034b6eu; return 0; }
r[0]=read(ram,r[15]+16,4);
goto P_0c034b70;
P_0c034b70: /* original 0302, guest PC 0x0c034b70 */
if(!s->budget--) { s->failed_pc=0x0c034b70u; return 0; }
r[3]=r[17];
goto P_0c034b72;
P_0c034b72: /* original 9235, guest PC 0x0c034b72 */
if(!s->budget--) { s->failed_pc=0x0c034b72u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c034be0u,2);
goto P_0c034b74;
P_0c034b74: /* original c90f, guest PC 0x0c034b74 */
if(!s->budget--) { s->failed_pc=0x0c034b74u; return 0; }
r[0]&=15u;
goto P_0c034b76;
P_0c034b76: /* original 4008, guest PC 0x0c034b76 */
if(!s->budget--) { s->failed_pc=0x0c034b76u; return 0; }
r[0]<<=2;
goto P_0c034b78;
P_0c034b78: /* original 2329, guest PC 0x0c034b78 */
if(!s->budget--) { s->failed_pc=0x0c034b78u; return 0; }
r[3]&=r[2];
goto P_0c034b7a;
P_0c034b7a: /* original 4008, guest PC 0x0c034b7a */
if(!s->budget--) { s->failed_pc=0x0c034b7au; return 0; }
r[0]<<=2;
goto P_0c034b7c;
P_0c034b7c: /* original 203b, guest PC 0x0c034b7c */
if(!s->budget--) { s->failed_pc=0x0c034b7cu; return 0; }
r[0]|=r[3];
goto P_0c034b7e;
P_0c034b7e: /* original 400e, guest PC 0x0c034b7e */
if(!s->budget--) { s->failed_pc=0x0c034b7eu; return 0; }
r[17]=r[0];
goto P_0c034b80;
P_0c034b80: /* original 64e2, guest PC 0x0c034b80 */
if(!s->budget--) { s->failed_pc=0x0c034b80u; return 0; }
tmp=read(ram,r[14],4);
r[4]=tmp;
goto P_0c034b82;
P_0c034b82: /* original e700, guest PC 0x0c034b82 */
if(!s->budget--) { s->failed_pc=0x0c034b82u; return 0; }
r[7]=0x00000000u;
goto P_0c034b84;
P_0c034b84: /* original d321, guest PC 0x0c034b84 */
if(!s->budget--) { s->failed_pc=0x0c034b84u; return 0; }
r[3]=read(ram,0x0c034c0cu,4);
goto P_0c034b86;
P_0c034b86: /* original 6673, guest PC 0x0c034b86 */
if(!s->budget--) { s->failed_pc=0x0c034b86u; return 0; }
r[6]=r[7];
goto P_0c034b88;
P_0c034b88: /* original 6573, guest PC 0x0c034b88 */
if(!s->budget--) { s->failed_pc=0x0c034b88u; return 0; }
r[5]=r[7];
goto P_0c034b8a;
P_0c034b8a: /* original 430b, guest PC 0x0c034b8a */
if(!s->budget--) { s->failed_pc=0x0c034b8au; return 0; }
target=r[3];
r[16]=code_base|0x0c034b8eu;
r[4]=read(ram,r[4]+44,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c034b8eu) { target=s->pc; goto dispatch; }
goto P_0c034b8e;
P_0c034b8c: /* original 544b, guest PC 0x0c034b8c */
if(!s->budget--) { s->failed_pc=0x0c034b8cu; return 0; }
r[4]=read(ram,r[4]+44,4);
goto P_0c034b8e;
P_0c034b8e: /* original 62e2, guest PC 0x0c034b8e */
if(!s->budget--) { s->failed_pc=0x0c034b8eu; return 0; }
tmp=read(ram,r[14],4);
r[2]=tmp;
goto P_0c034b90;
P_0c034b90: /* original 5325, guest PC 0x0c034b90 */
if(!s->budget--) { s->failed_pc=0x0c034b90u; return 0; }
r[3]=read(ram,r[2]+20,4);
goto P_0c034b92;
P_0c034b92: /* original 5137, guest PC 0x0c034b92 */
if(!s->budget--) { s->failed_pc=0x0c034b92u; return 0; }
r[1]=read(ram,r[3]+28,4);
goto P_0c034b94;
P_0c034b94: /* original 410b, guest PC 0x0c034b94 */
if(!s->budget--) { s->failed_pc=0x0c034b94u; return 0; }
target=r[1];
r[16]=code_base|0x0c034b98u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c034b98u) { target=s->pc; goto dispatch; }
goto P_0c034b98;
P_0c034b96: /* original 0009, guest PC 0x0c034b96 */
if(!s->budget--) { s->failed_pc=0x0c034b96u; return 0; }
goto P_0c034b98;
P_0c034b98: /* original 6403, guest PC 0x0c034b98 */
if(!s->budget--) { s->failed_pc=0x0c034b98u; return 0; }
r[4]=r[0];
goto P_0c034b9a;
P_0c034b9a: /* original 2448, guest PC 0x0c034b9a */
if(!s->budget--) { s->failed_pc=0x0c034b9au; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c034b9c;
P_0c034b9c: /* original 891d, guest PC 0x0c034b9c */
if(!s->budget--) { s->failed_pc=0x0c034b9cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c034bda; }
goto P_0c034b9e;
P_0c034b9e: /* original 62e2, guest PC 0x0c034b9e */
if(!s->budget--) { s->failed_pc=0x0c034b9eu; return 0; }
tmp=read(ram,r[14],4);
r[2]=tmp;
goto P_0c034ba0;
P_0c034ba0: /* original e04c, guest PC 0x0c034ba0 */
if(!s->budget--) { s->failed_pc=0x0c034ba0u; return 0; }
r[0]=0x0000004cu;
goto P_0c034ba2;
P_0c034ba2: /* original e104, guest PC 0x0c034ba2 */
if(!s->budget--) { s->failed_pc=0x0c034ba2u; return 0; }
r[1]=0x00000004u;
goto P_0c034ba4;
P_0c034ba4: /* original 532b, guest PC 0x0c034ba4 */
if(!s->budget--) { s->failed_pc=0x0c034ba4u; return 0; }
r[3]=read(ram,r[2]+44,4);
goto P_0c034ba6;
P_0c034ba6: /* original 134f, guest PC 0x0c034ba6 */
if(!s->budget--) { s->failed_pc=0x0c034ba6u; return 0; }
write(ram,r[3]+60,r[4],4);
goto P_0c034ba8;
P_0c034ba8: /* original 62e2, guest PC 0x0c034ba8 */
if(!s->budget--) { s->failed_pc=0x0c034ba8u; return 0; }
tmp=read(ram,r[14],4);
r[2]=tmp;
goto P_0c034baa;
P_0c034baa: /* original 532b, guest PC 0x0c034baa */
if(!s->budget--) { s->failed_pc=0x0c034baau; return 0; }
r[3]=read(ram,r[2]+44,4);
goto P_0c034bac;
P_0c034bac: /* original 0315, guest PC 0x0c034bac */
if(!s->budget--) { s->failed_pc=0x0c034bacu; return 0; }
write(ram,r[3]+r[0],r[1],2);
goto P_0c034bae;
P_0c034bae: /* original 63e2, guest PC 0x0c034bae */
if(!s->budget--) { s->failed_pc=0x0c034baeu; return 0; }
tmp=read(ram,r[14],4);
r[3]=tmp;
goto P_0c034bb0;
P_0c034bb0: /* original 6233, guest PC 0x0c034bb0 */
if(!s->budget--) { s->failed_pc=0x0c034bb0u; return 0; }
r[2]=r[3];
goto P_0c034bb2;
P_0c034bb2: /* original 512b, guest PC 0x0c034bb2 */
if(!s->budget--) { s->failed_pc=0x0c034bb2u; return 0; }
r[1]=read(ram,r[2]+44,4);
goto P_0c034bb4;
P_0c034bb4: /* original 131a, guest PC 0x0c034bb4 */
if(!s->budget--) { s->failed_pc=0x0c034bb4u; return 0; }
write(ram,r[3]+40,r[1],4);
goto P_0c034bb6;
P_0c034bb6: /* original d316, guest PC 0x0c034bb6 */
if(!s->budget--) { s->failed_pc=0x0c034bb6u; return 0; }
r[3]=read(ram,0x0c034c10u,4);
goto P_0c034bb8;
P_0c034bb8: /* original 64e2, guest PC 0x0c034bb8 */
if(!s->budget--) { s->failed_pc=0x0c034bb8u; return 0; }
tmp=read(ram,r[14],4);
r[4]=tmp;
goto P_0c034bba;
P_0c034bba: /* original 430b, guest PC 0x0c034bba */
if(!s->budget--) { s->failed_pc=0x0c034bbau; return 0; }
target=r[3];
r[16]=code_base|0x0c034bbeu;
r[4]=read(ram,r[4]+44,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c034bbeu) { target=s->pc; goto dispatch; }
goto P_0c034bbe;
P_0c034bbc: /* original 544b, guest PC 0x0c034bbc */
if(!s->budget--) { s->failed_pc=0x0c034bbcu; return 0; }
r[4]=read(ram,r[4]+44,4);
goto P_0c034bbe;
P_0c034bbe: /* original d315, guest PC 0x0c034bbe */
if(!s->budget--) { s->failed_pc=0x0c034bbeu; return 0; }
r[3]=read(ram,0x0c034c14u,4);
goto P_0c034bc0;
P_0c034bc0: /* original 6d03, guest PC 0x0c034bc0 */
if(!s->budget--) { s->failed_pc=0x0c034bc0u; return 0; }
r[13]=r[0];
goto P_0c034bc2;
P_0c034bc2: /* original 64e2, guest PC 0x0c034bc2 */
if(!s->budget--) { s->failed_pc=0x0c034bc2u; return 0; }
tmp=read(ram,r[14],4);
r[4]=tmp;
goto P_0c034bc4;
P_0c034bc4: /* original 430b, guest PC 0x0c034bc4 */
if(!s->budget--) { s->failed_pc=0x0c034bc4u; return 0; }
target=r[3];
r[16]=code_base|0x0c034bc8u;
r[4]=read(ram,r[4]+44,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c034bc8u) { target=s->pc; goto dispatch; }
goto P_0c034bc8;
P_0c034bc6: /* original 544b, guest PC 0x0c034bc6 */
if(!s->budget--) { s->failed_pc=0x0c034bc6u; return 0; }
r[4]=read(ram,r[4]+44,4);
goto P_0c034bc8;
P_0c034bc8: /* original 62e2, guest PC 0x0c034bc8 */
if(!s->budget--) { s->failed_pc=0x0c034bc8u; return 0; }
tmp=read(ram,r[14],4);
r[2]=tmp;
goto P_0c034bca;
P_0c034bca: /* original 6cf3, guest PC 0x0c034bca */
if(!s->budget--) { s->failed_pc=0x0c034bcau; return 0; }
r[12]=r[15];
goto P_0c034bcc;
P_0c034bcc: /* original 7c14, guest PC 0x0c034bcc */
if(!s->budget--) { s->failed_pc=0x0c034bccu; return 0; }
r[12]+=0x00000014u;
goto P_0c034bce;
P_0c034bce: /* original 5325, guest PC 0x0c034bce */
if(!s->budget--) { s->failed_pc=0x0c034bceu; return 0; }
r[3]=read(ram,r[2]+20,4);
goto P_0c034bd0;
P_0c034bd0: /* original 5138, guest PC 0x0c034bd0 */
if(!s->budget--) { s->failed_pc=0x0c034bd0u; return 0; }
r[1]=read(ram,r[3]+32,4);
goto P_0c034bd2;
P_0c034bd2: /* original 410b, guest PC 0x0c034bd2 */
if(!s->budget--) { s->failed_pc=0x0c034bd2u; return 0; }
target=r[1];
r[16]=code_base|0x0c034bd6u;
r[4]=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c034bd6u) { target=s->pc; goto dispatch; }
goto P_0c034bd6;
P_0c034bd4: /* original 64c3, guest PC 0x0c034bd4 */
if(!s->budget--) { s->failed_pc=0x0c034bd4u; return 0; }
r[4]=r[12];
goto P_0c034bd6;
P_0c034bd6: /* original 2008, guest PC 0x0c034bd6 */
if(!s->budget--) { s->failed_pc=0x0c034bd6u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c034bd8;
P_0c034bd8: /* original 8b1e, guest PC 0x0c034bd8 */
if(!s->budget--) { s->failed_pc=0x0c034bd8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c034c18; }
goto P_0c034bda;
P_0c034bda: /* original a079, guest PC 0x0c034bda */
if(!s->budget--) { s->failed_pc=0x0c034bdau; return 0; }
r[0]=0xfffffffeu;
goto P_0c034cd0;
P_0c034bdc: /* original e0fe, guest PC 0x0c034bdc */
if(!s->budget--) { s->failed_pc=0x0c034bdcu; return 0; }
r[0]=0xfffffffeu;
if(!vf3_matrix_family(0x0c034bdeu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c034bdeu; return 0; } return 1;
P_0c034c18: /* original 2dd8, guest PC 0x0c034c18 */
if(!s->budget--) { s->failed_pc=0x0c034c18u; return 0; }
r[17]=(r[17]&~1u)|(((r[13]&r[13])==0)!=0);
goto P_0c034c1a;
P_0c034c1a: /* original 8909, guest PC 0x0c034c1a */
if(!s->budget--) { s->failed_pc=0x0c034c1au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c034c30; }
goto P_0c034c1c;
P_0c034c1c: /* original 60d3, guest PC 0x0c034c1c */
if(!s->budget--) { s->failed_pc=0x0c034c1cu; return 0; }
r[0]=r[13];
goto P_0c034c1e;
P_0c034c1e: /* original 88e3, guest PC 0x0c034c1e */
if(!s->budget--) { s->failed_pc=0x0c034c1eu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xffffffe3u)!=0);
goto P_0c034c20;
P_0c034c20: /* original 8b04, guest PC 0x0c034c20 */
if(!s->budget--) { s->failed_pc=0x0c034c20u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c034c2c; }
goto P_0c034c22;
P_0c034c22: /* original 60c2, guest PC 0x0c034c22 */
if(!s->budget--) { s->failed_pc=0x0c034c22u; return 0; }
tmp=read(ram,r[12],4);
r[0]=tmp;
goto P_0c034c24;
P_0c034c24: /* original 8806, guest PC 0x0c034c24 */
if(!s->budget--) { s->failed_pc=0x0c034c24u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000006u)!=0);
goto P_0c034c26;
P_0c034c26: /* original 8b01, guest PC 0x0c034c26 */
if(!s->budget--) { s->failed_pc=0x0c034c26u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c034c2c; }
goto P_0c034c28;
P_0c034c28: /* original a052, guest PC 0x0c034c28 */
if(!s->budget--) { s->failed_pc=0x0c034c28u; return 0; }
r[0]=0xffffffe9u;
goto P_0c034cd0;
P_0c034c2a: /* original e0e9, guest PC 0x0c034c2a */
if(!s->budget--) { s->failed_pc=0x0c034c2au; return 0; }
r[0]=0xffffffe9u;
goto P_0c034c2c;
P_0c034c2c: /* original a050, guest PC 0x0c034c2c */
if(!s->budget--) { s->failed_pc=0x0c034c2cu; return 0; }
r[0]=r[13];
goto P_0c034cd0;
P_0c034c2e: /* original 60d3, guest PC 0x0c034c2e */
if(!s->budget--) { s->failed_pc=0x0c034c2eu; return 0; }
r[0]=r[13];
goto P_0c034c30;
P_0c034c30: /* original 52c1, guest PC 0x0c034c30 */
if(!s->budget--) { s->failed_pc=0x0c034c30u; return 0; }
r[2]=read(ram,r[12]+4,4);
goto P_0c034c32;
P_0c034c32: /* original 9362, guest PC 0x0c034c32 */
if(!s->budget--) { s->failed_pc=0x0c034c32u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c034cfau,2);
goto P_0c034c34;
P_0c034c34: /* original 3230, guest PC 0x0c034c34 */
if(!s->budget--) { s->failed_pc=0x0c034c34u; return 0; }
r[17]=(r[17]&~1u)|((r[2]==r[3])!=0);
goto P_0c034c36;
P_0c034c36: /* original 8b46, guest PC 0x0c034c36 */
if(!s->budget--) { s->failed_pc=0x0c034c36u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c034cc6; }
goto P_0c034c38;
P_0c034c38: /* original 66e2, guest PC 0x0c034c38 */
if(!s->budget--) { s->failed_pc=0x0c034c38u; return 0; }
tmp=read(ram,r[14],4);
r[6]=tmp;
goto P_0c034c3a;
P_0c034c3a: /* original e501, guest PC 0x0c034c3a */
if(!s->budget--) { s->failed_pc=0x0c034c3au; return 0; }
r[5]=0x00000001u;
goto P_0c034c3c;
P_0c034c3c: /* original 64e2, guest PC 0x0c034c3c */
if(!s->budget--) { s->failed_pc=0x0c034c3cu; return 0; }
tmp=read(ram,r[14],4);
r[4]=tmp;
goto P_0c034c3e;
P_0c034c3e: /* original d332, guest PC 0x0c034c3e */
if(!s->budget--) { s->failed_pc=0x0c034c3eu; return 0; }
r[3]=read(ram,0x0c034d08u,4);
goto P_0c034c40;
P_0c034c40: /* original 7640, guest PC 0x0c034c40 */
if(!s->budget--) { s->failed_pc=0x0c034c40u; return 0; }
r[6]+=0x00000040u;
goto P_0c034c42;
P_0c034c42: /* original 430b, guest PC 0x0c034c42 */
if(!s->budget--) { s->failed_pc=0x0c034c42u; return 0; }
target=r[3];
r[16]=code_base|0x0c034c46u;
r[4]=read(ram,r[4]+4,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c034c46u) { target=s->pc; goto dispatch; }
goto P_0c034c46;
P_0c034c44: /* original 5441, guest PC 0x0c034c44 */
if(!s->budget--) { s->failed_pc=0x0c034c44u; return 0; }
r[4]=read(ram,r[4]+4,4);
goto P_0c034c46;
P_0c034c46: /* original 6403, guest PC 0x0c034c46 */
if(!s->budget--) { s->failed_pc=0x0c034c46u; return 0; }
r[4]=r[0];
goto P_0c034c48;
P_0c034c48: /* original 2448, guest PC 0x0c034c48 */
if(!s->budget--) { s->failed_pc=0x0c034c48u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c034c4a;
P_0c034c4a: /* original 8b35, guest PC 0x0c034c4a */
if(!s->budget--) { s->failed_pc=0x0c034c4au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c034cb8; }
goto P_0c034c4c;
P_0c034c4c: /* original 64e2, guest PC 0x0c034c4c */
if(!s->budget--) { s->failed_pc=0x0c034c4cu; return 0; }
tmp=read(ram,r[14],4);
r[4]=tmp;
goto P_0c034c4e;
P_0c034c4e: /* original bdea, guest PC 0x0c034c4e */
if(!s->budget--) { s->failed_pc=0x0c034c4eu; return 0; }
target=code_base|0x0c034826u; r[16]=code_base|0x0c034c52u;
r[4]+=0x00000040u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c034c52u) { target=s->pc; goto dispatch; }
goto P_0c034c52;
P_0c034c50: /* original 7440, guest PC 0x0c034c50 */
if(!s->budget--) { s->failed_pc=0x0c034c50u; return 0; }
r[4]+=0x00000040u;
goto P_0c034c52;
P_0c034c52: /* original 2008, guest PC 0x0c034c52 */
if(!s->budget--) { s->failed_pc=0x0c034c52u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c034c54;
P_0c034c54: /* original 8937, guest PC 0x0c034c54 */
if(!s->budget--) { s->failed_pc=0x0c034c54u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c034cc6; }
goto P_0c034c56;
P_0c034c56: /* original 64e2, guest PC 0x0c034c56 */
if(!s->budget--) { s->failed_pc=0x0c034c56u; return 0; }
tmp=read(ram,r[14],4);
r[4]=tmp;
goto P_0c034c58;
P_0c034c58: /* original 68e2, guest PC 0x0c034c58 */
if(!s->budget--) { s->failed_pc=0x0c034c58u; return 0; }
tmp=read(ram,r[14],4);
r[8]=tmp;
goto P_0c034c5a;
P_0c034c5a: /* original 934f, guest PC 0x0c034c5a */
if(!s->budget--) { s->failed_pc=0x0c034c5au; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c034cfcu,2);
goto P_0c034c5c;
P_0c034c5c: /* original 7440, guest PC 0x0c034c5c */
if(!s->budget--) { s->failed_pc=0x0c034c5cu; return 0; }
r[4]+=0x00000040u;
goto P_0c034c5e;
P_0c034c5e: /* original 780c, guest PC 0x0c034c5e */
if(!s->budget--) { s->failed_pc=0x0c034c5eu; return 0; }
r[8]+=0x0000000cu;
goto P_0c034c60;
P_0c034c60: /* original bdce, guest PC 0x0c034c60 */
if(!s->budget--) { s->failed_pc=0x0c034c60u; return 0; }
target=code_base|0x0c034800u; r[16]=code_base|0x0c034c64u;
r[4]+=r[3];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c034c64u) { target=s->pc; goto dispatch; }
goto P_0c034c64;
P_0c034c62: /* original 343c, guest PC 0x0c034c62 */
if(!s->budget--) { s->failed_pc=0x0c034c62u; return 0; }
r[4]+=r[3];
goto P_0c034c64;
P_0c034c64: /* original 2802, guest PC 0x0c034c64 */
if(!s->budget--) { s->failed_pc=0x0c034c64u; return 0; }
write(ram,r[8],r[0],4);
goto P_0c034c66;
P_0c034c66: /* original 63e2, guest PC 0x0c034c66 */
if(!s->budget--) { s->failed_pc=0x0c034c66u; return 0; }
tmp=read(ram,r[14],4);
r[3]=tmp;
goto P_0c034c68;
P_0c034c68: /* original 9249, guest PC 0x0c034c68 */
if(!s->budget--) { s->failed_pc=0x0c034c68u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c034cfeu,2);
goto P_0c034c6a;
P_0c034c6a: /* original 5133, guest PC 0x0c034c6a */
if(!s->budget--) { s->failed_pc=0x0c034c6au; return 0; }
r[1]=read(ram,r[3]+12,4);
goto P_0c034c6c;
P_0c034c6c: /* original 312c, guest PC 0x0c034c6c */
if(!s->budget--) { s->failed_pc=0x0c034c6cu; return 0; }
r[1]+=r[2];
goto P_0c034c6e;
P_0c034c6e: /* original 1313, guest PC 0x0c034c6e */
if(!s->budget--) { s->failed_pc=0x0c034c6eu; return 0; }
write(ram,r[3]+12,r[1],4);
goto P_0c034c70;
P_0c034c70: /* original 64e2, guest PC 0x0c034c70 */
if(!s->budget--) { s->failed_pc=0x0c034c70u; return 0; }
tmp=read(ram,r[14],4);
r[4]=tmp;
goto P_0c034c72;
P_0c034c72: /* original 68e2, guest PC 0x0c034c72 */
if(!s->budget--) { s->failed_pc=0x0c034c72u; return 0; }
tmp=read(ram,r[14],4);
r[8]=tmp;
goto P_0c034c74;
P_0c034c74: /* original 9344, guest PC 0x0c034c74 */
if(!s->budget--) { s->failed_pc=0x0c034c74u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c034d00u,2);
goto P_0c034c76;
P_0c034c76: /* original 7440, guest PC 0x0c034c76 */
if(!s->budget--) { s->failed_pc=0x0c034c76u; return 0; }
r[4]+=0x00000040u;
goto P_0c034c78;
P_0c034c78: /* original 7810, guest PC 0x0c034c78 */
if(!s->budget--) { s->failed_pc=0x0c034c78u; return 0; }
r[8]+=0x00000010u;
goto P_0c034c7a;
P_0c034c7a: /* original bdc1, guest PC 0x0c034c7a */
if(!s->budget--) { s->failed_pc=0x0c034c7au; return 0; }
target=code_base|0x0c034800u; r[16]=code_base|0x0c034c7eu;
r[4]+=r[3];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c034c7eu) { target=s->pc; goto dispatch; }
goto P_0c034c7e;
P_0c034c7c: /* original 343c, guest PC 0x0c034c7c */
if(!s->budget--) { s->failed_pc=0x0c034c7cu; return 0; }
r[4]+=r[3];
goto P_0c034c7e;
P_0c034c7e: /* original 2802, guest PC 0x0c034c7e */
if(!s->budget--) { s->failed_pc=0x0c034c7eu; return 0; }
write(ram,r[8],r[0],4);
goto P_0c034c80;
P_0c034c80: /* original 64e2, guest PC 0x0c034c80 */
if(!s->budget--) { s->failed_pc=0x0c034c80u; return 0; }
tmp=read(ram,r[14],4);
r[4]=tmp;
goto P_0c034c82;
P_0c034c82: /* original 933e, guest PC 0x0c034c82 */
if(!s->budget--) { s->failed_pc=0x0c034c82u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c034d02u,2);
goto P_0c034c84;
P_0c034c84: /* original 7440, guest PC 0x0c034c84 */
if(!s->budget--) { s->failed_pc=0x0c034c84u; return 0; }
r[4]+=0x00000040u;
goto P_0c034c86;
P_0c034c86: /* original bdbb, guest PC 0x0c034c86 */
if(!s->budget--) { s->failed_pc=0x0c034c86u; return 0; }
target=code_base|0x0c034800u; r[16]=code_base|0x0c034c8au;
r[4]+=r[3];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c034c8au) { target=s->pc; goto dispatch; }
goto P_0c034c8a;
P_0c034c88: /* original 343c, guest PC 0x0c034c88 */
if(!s->budget--) { s->failed_pc=0x0c034c88u; return 0; }
r[4]+=r[3];
goto P_0c034c8a;
P_0c034c8a: /* original 64e2, guest PC 0x0c034c8a */
if(!s->budget--) { s->failed_pc=0x0c034c8au; return 0; }
tmp=read(ram,r[14],4);
r[4]=tmp;
goto P_0c034c8c;
P_0c034c8c: /* original 6d03, guest PC 0x0c034c8c */
if(!s->budget--) { s->failed_pc=0x0c034c8cu; return 0; }
r[13]=r[0];
goto P_0c034c8e;
P_0c034c8e: /* original 9336, guest PC 0x0c034c8e */
if(!s->budget--) { s->failed_pc=0x0c034c8eu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c034cfeu,2);
goto P_0c034c90;
P_0c034c90: /* original 9238, guest PC 0x0c034c90 */
if(!s->budget--) { s->failed_pc=0x0c034c90u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c034d04u,2);
goto P_0c034c92;
P_0c034c92: /* original 7440, guest PC 0x0c034c92 */
if(!s->budget--) { s->failed_pc=0x0c034c92u; return 0; }
r[4]+=0x00000040u;
goto P_0c034c94;
P_0c034c94: /* original 3d3c, guest PC 0x0c034c94 */
if(!s->budget--) { s->failed_pc=0x0c034c94u; return 0; }
r[13]+=r[3];
goto P_0c034c96;
P_0c034c96: /* original bdb3, guest PC 0x0c034c96 */
if(!s->budget--) { s->failed_pc=0x0c034c96u; return 0; }
target=code_base|0x0c034800u; r[16]=code_base|0x0c034c9au;
r[4]+=r[2];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c034c9au) { target=s->pc; goto dispatch; }
goto P_0c034c9a;
P_0c034c98: /* original 342c, guest PC 0x0c034c98 */
if(!s->budget--) { s->failed_pc=0x0c034c98u; return 0; }
r[4]+=r[2];
goto P_0c034c9a;
P_0c034c9a: /* original 66e2, guest PC 0x0c034c9a */
if(!s->budget--) { s->failed_pc=0x0c034c9au; return 0; }
tmp=read(ram,r[14],4);
r[6]=tmp;
goto P_0c034c9c;
P_0c034c9c: /* original 6703, guest PC 0x0c034c9c */
if(!s->budget--) { s->failed_pc=0x0c034c9cu; return 0; }
r[7]=r[0];
goto P_0c034c9e;
P_0c034c9e: /* original 64e2, guest PC 0x0c034c9e */
if(!s->budget--) { s->failed_pc=0x0c034c9eu; return 0; }
tmp=read(ram,r[14],4);
r[4]=tmp;
goto P_0c034ca0;
P_0c034ca0: /* original 65d3, guest PC 0x0c034ca0 */
if(!s->budget--) { s->failed_pc=0x0c034ca0u; return 0; }
r[5]=r[13];
goto P_0c034ca2;
P_0c034ca2: /* original d31a, guest PC 0x0c034ca2 */
if(!s->budget--) { s->failed_pc=0x0c034ca2u; return 0; }
r[3]=read(ram,0x0c034d0cu,4);
goto P_0c034ca4;
P_0c034ca4: /* original 5666, guest PC 0x0c034ca4 */
if(!s->budget--) { s->failed_pc=0x0c034ca4u; return 0; }
r[6]=read(ram,r[6]+24,4);
goto P_0c034ca6;
P_0c034ca6: /* original 430b, guest PC 0x0c034ca6 */
if(!s->budget--) { s->failed_pc=0x0c034ca6u; return 0; }
target=r[3];
r[16]=code_base|0x0c034caau;
r[4]+=0x00000040u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c034caau) { target=s->pc; goto dispatch; }
goto P_0c034caa;
P_0c034ca8: /* original 7440, guest PC 0x0c034ca8 */
if(!s->budget--) { s->failed_pc=0x0c034ca8u; return 0; }
r[4]+=0x00000040u;
goto P_0c034caa;
P_0c034caa: /* original 88f4, guest PC 0x0c034caa */
if(!s->budget--) { s->failed_pc=0x0c034caau; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xfffffff4u)!=0);
goto P_0c034cac;
P_0c034cac: /* original 8f02, guest PC 0x0c034cac */
if(!s->budget--) { s->failed_pc=0x0c034cacu; return 0; }
cond=r[17]&1u;
r[4]=r[0];
if(!cond) { goto P_0c034cb4; }
goto P_0c034cb0;
P_0c034cae: /* original 6403, guest PC 0x0c034cae */
if(!s->budget--) { s->failed_pc=0x0c034caeu; return 0; }
r[4]=r[0];
goto P_0c034cb0;
P_0c034cb0: /* original a00e, guest PC 0x0c034cb0 */
if(!s->budget--) { s->failed_pc=0x0c034cb0u; return 0; }
r[0]=r[4];
goto P_0c034cd0;
P_0c034cb2: /* original 6043, guest PC 0x0c034cb2 */
if(!s->budget--) { s->failed_pc=0x0c034cb2u; return 0; }
r[0]=r[4];
goto P_0c034cb4;
P_0c034cb4: /* original 2448, guest PC 0x0c034cb4 */
if(!s->budget--) { s->failed_pc=0x0c034cb4u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c034cb6;
P_0c034cb6: /* original 8901, guest PC 0x0c034cb6 */
if(!s->budget--) { s->failed_pc=0x0c034cb6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c034cbc; }
goto P_0c034cb8;
P_0c034cb8: /* original a00a, guest PC 0x0c034cb8 */
if(!s->budget--) { s->failed_pc=0x0c034cb8u; return 0; }
r[0]=0xfffffffcu;
goto P_0c034cd0;
P_0c034cba: /* original e0fc, guest PC 0x0c034cba */
if(!s->budget--) { s->failed_pc=0x0c034cbau; return 0; }
r[0]=0xfffffffcu;
goto P_0c034cbc;
P_0c034cbc: /* original 64e2, guest PC 0x0c034cbc */
if(!s->budget--) { s->failed_pc=0x0c034cbcu; return 0; }
tmp=read(ram,r[14],4);
r[4]=tmp;
goto P_0c034cbe;
P_0c034cbe: /* original 5346, guest PC 0x0c034cbe */
if(!s->budget--) { s->failed_pc=0x0c034cbeu; return 0; }
r[3]=read(ram,r[4]+24,4);
goto P_0c034cc0;
P_0c034cc0: /* original 6232, guest PC 0x0c034cc0 */
if(!s->budget--) { s->failed_pc=0x0c034cc0u; return 0; }
tmp=read(ram,r[3],4);
r[2]=tmp;
goto P_0c034cc2;
P_0c034cc2: /* original 2228, guest PC 0x0c034cc2 */
if(!s->budget--) { s->failed_pc=0x0c034cc2u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c034cc4;
P_0c034cc4: /* original 8b01, guest PC 0x0c034cc4 */
if(!s->budget--) { s->failed_pc=0x0c034cc4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c034cca; }
goto P_0c034cc6;
P_0c034cc6: /* original a003, guest PC 0x0c034cc6 */
if(!s->budget--) { s->failed_pc=0x0c034cc6u; return 0; }
r[0]=0xfffffffbu;
goto P_0c034cd0;
P_0c034cc8: /* original e0fb, guest PC 0x0c034cc8 */
if(!s->budget--) { s->failed_pc=0x0c034cc8u; return 0; }
r[0]=0xfffffffbu;
goto P_0c034cca;
P_0c034cca: /* original e301, guest PC 0x0c034cca */
if(!s->budget--) { s->failed_pc=0x0c034ccau; return 0; }
r[3]=0x00000001u;
goto P_0c034ccc;
P_0c034ccc: /* original 1438, guest PC 0x0c034ccc */
if(!s->budget--) { s->failed_pc=0x0c034cccu; return 0; }
write(ram,r[4]+32,r[3],4);
goto P_0c034cce;
P_0c034cce: /* original e000, guest PC 0x0c034cce */
if(!s->budget--) { s->failed_pc=0x0c034cceu; return 0; }
r[0]=0x00000000u;
goto P_0c034cd0;
P_0c034cd0: /* original 7f1c, guest PC 0x0c034cd0 */
if(!s->budget--) { s->failed_pc=0x0c034cd0u; return 0; }
r[15]+=0x0000001cu;
goto P_0c034cd2;
P_0c034cd2: /* original 4f26, guest PC 0x0c034cd2 */
if(!s->budget--) { s->failed_pc=0x0c034cd2u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c034cd4;
P_0c034cd4: /* original 68f6, guest PC 0x0c034cd4 */
if(!s->budget--) { s->failed_pc=0x0c034cd4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c034cd6;
P_0c034cd6: /* original 6bf6, guest PC 0x0c034cd6 */
if(!s->budget--) { s->failed_pc=0x0c034cd6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c034cd8;
P_0c034cd8: /* original 6cf6, guest PC 0x0c034cd8 */
if(!s->budget--) { s->failed_pc=0x0c034cd8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c034cda;
P_0c034cda: /* original 6df6, guest PC 0x0c034cda */
if(!s->budget--) { s->failed_pc=0x0c034cdau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c034cdc;
P_0c034cdc: /* original 000b, guest PC 0x0c034cdc */
if(!s->budget--) { s->failed_pc=0x0c034cdcu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c034cde: /* original 6ef6, guest PC 0x0c034cde */
if(!s->budget--) { s->failed_pc=0x0c034cdeu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c034ce0u,s,ram);
unsupported: s->failed_pc=target; return 0;
}
