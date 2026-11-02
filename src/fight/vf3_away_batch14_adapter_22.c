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
int vf3_away_batch14_adapter_22(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c089aa0u: goto P_0c089aa0;
case 0x0c089aa2u: goto P_0c089aa2;
case 0x0c089aa4u: goto P_0c089aa4;
case 0x0c089aa6u: goto P_0c089aa6;
case 0x0c089aa8u: goto P_0c089aa8;
case 0x0c089aaau: goto P_0c089aaa;
case 0x0c089aacu: goto P_0c089aac;
case 0x0c089aaeu: goto P_0c089aae;
case 0x0c089ab0u: goto P_0c089ab0;
case 0x0c089ab2u: goto P_0c089ab2;
case 0x0c089ab4u: goto P_0c089ab4;
case 0x0c089ab6u: goto P_0c089ab6;
case 0x0c089ab8u: goto P_0c089ab8;
case 0x0c089abau: goto P_0c089aba;
case 0x0c089abcu: goto P_0c089abc;
case 0x0c089abeu: goto P_0c089abe;
case 0x0c089ac0u: goto P_0c089ac0;
case 0x0c089ac2u: goto P_0c089ac2;
case 0x0c089ac4u: goto P_0c089ac4;
case 0x0c089ac6u: goto P_0c089ac6;
case 0x0c089ac8u: goto P_0c089ac8;
case 0x0c089acau: goto P_0c089aca;
case 0x0c089accu: goto P_0c089acc;
case 0x0c089aceu: goto P_0c089ace;
case 0x0c089ad0u: goto P_0c089ad0;
case 0x0c089ad2u: goto P_0c089ad2;
case 0x0c089ad4u: goto P_0c089ad4;
case 0x0c089ad6u: goto P_0c089ad6;
case 0x0c089ad8u: goto P_0c089ad8;
case 0x0c089adau: goto P_0c089ada;
case 0x0c089adcu: goto P_0c089adc;
case 0x0c089adeu: goto P_0c089ade;
case 0x0c089ae0u: goto P_0c089ae0;
case 0x0c089ae2u: goto P_0c089ae2;
case 0x0c089ae4u: goto P_0c089ae4;
case 0x0c089ae6u: goto P_0c089ae6;
case 0x0c089ae8u: goto P_0c089ae8;
case 0x0c089aeau: goto P_0c089aea;
case 0x0c089aecu: goto P_0c089aec;
case 0x0c089aeeu: goto P_0c089aee;
case 0x0c089af0u: goto P_0c089af0;
case 0x0c089af2u: goto P_0c089af2;
case 0x0c089af4u: goto P_0c089af4;
case 0x0c089af6u: goto P_0c089af6;
case 0x0c089af8u: goto P_0c089af8;
case 0x0c089afau: goto P_0c089afa;
case 0x0c089afcu: goto P_0c089afc;
case 0x0c089afeu: goto P_0c089afe;
case 0x0c089b00u: goto P_0c089b00;
case 0x0c089b02u: goto P_0c089b02;
case 0x0c089b04u: goto P_0c089b04;
case 0x0c089b06u: goto P_0c089b06;
case 0x0c089b08u: goto P_0c089b08;
case 0x0c089b0au: goto P_0c089b0a;
case 0x0c089b0cu: goto P_0c089b0c;
case 0x0c089b0eu: goto P_0c089b0e;
case 0x0c089b10u: goto P_0c089b10;
case 0x0c089b12u: goto P_0c089b12;
case 0x0c089b14u: goto P_0c089b14;
case 0x0c089b16u: goto P_0c089b16;
case 0x0c089b18u: goto P_0c089b18;
case 0x0c089b1au: goto P_0c089b1a;
case 0x0c089b1cu: goto P_0c089b1c;
case 0x0c089b50u: goto P_0c089b50;
case 0x0c089b52u: goto P_0c089b52;
case 0x0c089b54u: goto P_0c089b54;
case 0x0c089b56u: goto P_0c089b56;
case 0x0c089b58u: goto P_0c089b58;
case 0x0c089b5au: goto P_0c089b5a;
case 0x0c089b5cu: goto P_0c089b5c;
case 0x0c089b5eu: goto P_0c089b5e;
case 0x0c089b60u: goto P_0c089b60;
case 0x0c089b62u: goto P_0c089b62;
case 0x0c089b64u: goto P_0c089b64;
case 0x0c089b66u: goto P_0c089b66;
case 0x0c089b68u: goto P_0c089b68;
case 0x0c089b6au: goto P_0c089b6a;
case 0x0c089b6cu: goto P_0c089b6c;
case 0x0c089b6eu: goto P_0c089b6e;
case 0x0c089b70u: goto P_0c089b70;
case 0x0c089b72u: goto P_0c089b72;
case 0x0c089b74u: goto P_0c089b74;
case 0x0c089b76u: goto P_0c089b76;
case 0x0c089b78u: goto P_0c089b78;
case 0x0c089b7au: goto P_0c089b7a;
case 0x0c089b7cu: goto P_0c089b7c;
case 0x0c089b7eu: goto P_0c089b7e;
case 0x0c089b80u: goto P_0c089b80;
case 0x0c089b82u: goto P_0c089b82;
case 0x0c089b84u: goto P_0c089b84;
case 0x0c089b86u: goto P_0c089b86;
case 0x0c089b88u: goto P_0c089b88;
case 0x0c089b8au: goto P_0c089b8a;
case 0x0c089b8cu: goto P_0c089b8c;
case 0x0c089b8eu: goto P_0c089b8e;
case 0x0c089b90u: goto P_0c089b90;
case 0x0c089b92u: goto P_0c089b92;
case 0x0c089b94u: goto P_0c089b94;
case 0x0c089b96u: goto P_0c089b96;
case 0x0c089b98u: goto P_0c089b98;
case 0x0c089b9au: goto P_0c089b9a;
case 0x0c089b9cu: goto P_0c089b9c;
case 0x0c089b9eu: goto P_0c089b9e;
case 0x0c089ba0u: goto P_0c089ba0;
case 0x0c089ba2u: goto P_0c089ba2;
case 0x0c089ba4u: goto P_0c089ba4;
case 0x0c089ba6u: goto P_0c089ba6;
case 0x0c089ba8u: goto P_0c089ba8;
case 0x0c089baau: goto P_0c089baa;
case 0x0c089bacu: goto P_0c089bac;
case 0x0c089baeu: goto P_0c089bae;
case 0x0c089bb0u: goto P_0c089bb0;
case 0x0c089bb2u: goto P_0c089bb2;
case 0x0c089bb4u: goto P_0c089bb4;
case 0x0c089bb6u: goto P_0c089bb6;
case 0x0c089bb8u: goto P_0c089bb8;
case 0x0c089bbau: goto P_0c089bba;
case 0x0c089bbcu: goto P_0c089bbc;
case 0x0c089bbeu: goto P_0c089bbe;
case 0x0c089bc0u: goto P_0c089bc0;
case 0x0c089bc2u: goto P_0c089bc2;
case 0x0c089bc4u: goto P_0c089bc4;
case 0x0c089bc6u: goto P_0c089bc6;
case 0x0c089bc8u: goto P_0c089bc8;
case 0x0c089bcau: goto P_0c089bca;
case 0x0c089bccu: goto P_0c089bcc;
case 0x0c089bceu: goto P_0c089bce;
case 0x0c089bd0u: goto P_0c089bd0;
case 0x0c089bd2u: goto P_0c089bd2;
case 0x0c089bd4u: goto P_0c089bd4;
case 0x0c089bd6u: goto P_0c089bd6;
case 0x0c089bd8u: goto P_0c089bd8;
case 0x0c089bdau: goto P_0c089bda;
case 0x0c089bdcu: goto P_0c089bdc;
case 0x0c089bdeu: goto P_0c089bde;
case 0x0c089be0u: goto P_0c089be0;
case 0x0c089be2u: goto P_0c089be2;
case 0x0c089be4u: goto P_0c089be4;
case 0x0c089be6u: goto P_0c089be6;
case 0x0c089be8u: goto P_0c089be8;
case 0x0c089beau: goto P_0c089bea;
case 0x0c089becu: goto P_0c089bec;
case 0x0c089beeu: goto P_0c089bee;
case 0x0c089bf0u: goto P_0c089bf0;
case 0x0c089bf2u: goto P_0c089bf2;
case 0x0c089bf4u: goto P_0c089bf4;
case 0x0c089bf6u: goto P_0c089bf6;
case 0x0c089bf8u: goto P_0c089bf8;
case 0x0c089bfau: goto P_0c089bfa;
case 0x0c089bfcu: goto P_0c089bfc;
case 0x0c089bfeu: goto P_0c089bfe;
case 0x0c089c00u: goto P_0c089c00;
case 0x0c089c02u: goto P_0c089c02;
case 0x0c089c04u: goto P_0c089c04;
case 0x0c089c38u: goto P_0c089c38;
case 0x0c089c3au: goto P_0c089c3a;
case 0x0c089c3cu: goto P_0c089c3c;
case 0x0c089c3eu: goto P_0c089c3e;
case 0x0c089c40u: goto P_0c089c40;
case 0x0c089c42u: goto P_0c089c42;
case 0x0c089c44u: goto P_0c089c44;
case 0x0c089c46u: goto P_0c089c46;
case 0x0c089c48u: goto P_0c089c48;
case 0x0c089c4au: goto P_0c089c4a;
case 0x0c089c4cu: goto P_0c089c4c;
case 0x0c089c4eu: goto P_0c089c4e;
case 0x0c089c50u: goto P_0c089c50;
case 0x0c089c52u: goto P_0c089c52;
case 0x0c089c54u: goto P_0c089c54;
case 0x0c089c56u: goto P_0c089c56;
case 0x0c089c58u: goto P_0c089c58;
case 0x0c089c5au: goto P_0c089c5a;
case 0x0c089c5cu: goto P_0c089c5c;
case 0x0c089c5eu: goto P_0c089c5e;
case 0x0c089c60u: goto P_0c089c60;
case 0x0c089c62u: goto P_0c089c62;
case 0x0c089c64u: goto P_0c089c64;
case 0x0c089c66u: goto P_0c089c66;
case 0x0c089c68u: goto P_0c089c68;
case 0x0c089c6au: goto P_0c089c6a;
case 0x0c089c6cu: goto P_0c089c6c;
case 0x0c089c6eu: goto P_0c089c6e;
case 0x0c089c70u: goto P_0c089c70;
case 0x0c089c72u: goto P_0c089c72;
case 0x0c089c74u: goto P_0c089c74;
case 0x0c089c76u: goto P_0c089c76;
case 0x0c089c78u: goto P_0c089c78;
case 0x0c089c7au: goto P_0c089c7a;
case 0x0c089c7cu: goto P_0c089c7c;
case 0x0c089c7eu: goto P_0c089c7e;
case 0x0c089c80u: goto P_0c089c80;
case 0x0c089c82u: goto P_0c089c82;
case 0x0c089c84u: goto P_0c089c84;
case 0x0c089c86u: goto P_0c089c86;
case 0x0c089c88u: goto P_0c089c88;
case 0x0c089c8au: goto P_0c089c8a;
case 0x0c089c8cu: goto P_0c089c8c;
case 0x0c089c8eu: goto P_0c089c8e;
case 0x0c089c90u: goto P_0c089c90;
case 0x0c089c92u: goto P_0c089c92;
case 0x0c089c94u: goto P_0c089c94;
case 0x0c089c96u: goto P_0c089c96;
case 0x0c089c98u: goto P_0c089c98;
case 0x0c089c9au: goto P_0c089c9a;
case 0x0c089c9cu: goto P_0c089c9c;
case 0x0c089c9eu: goto P_0c089c9e;
case 0x0c089ca0u: goto P_0c089ca0;
case 0x0c089ca2u: goto P_0c089ca2;
case 0x0c089ca4u: goto P_0c089ca4;
case 0x0c089ca6u: goto P_0c089ca6;
case 0x0c089ca8u: goto P_0c089ca8;
case 0x0c089caau: goto P_0c089caa;
case 0x0c089cacu: goto P_0c089cac;
case 0x0c089caeu: goto P_0c089cae;
case 0x0c089cb0u: goto P_0c089cb0;
case 0x0c089cb2u: goto P_0c089cb2;
case 0x0c089cb4u: goto P_0c089cb4;
case 0x0c089cb6u: goto P_0c089cb6;
case 0x0c089cb8u: goto P_0c089cb8;
case 0x0c089cbau: goto P_0c089cba;
case 0x0c089cbcu: goto P_0c089cbc;
case 0x0c089cbeu: goto P_0c089cbe;
case 0x0c089cc0u: goto P_0c089cc0;
case 0x0c089cc2u: goto P_0c089cc2;
case 0x0c089cc4u: goto P_0c089cc4;
case 0x0c089cc6u: goto P_0c089cc6;
case 0x0c089cc8u: goto P_0c089cc8;
case 0x0c089ccau: goto P_0c089cca;
case 0x0c089cccu: goto P_0c089ccc;
case 0x0c089cceu: goto P_0c089cce;
case 0x0c089cd0u: goto P_0c089cd0;
case 0x0c089cd2u: goto P_0c089cd2;
case 0x0c089cd4u: goto P_0c089cd4;
case 0x0c089cd6u: goto P_0c089cd6;
case 0x0c089cd8u: goto P_0c089cd8;
case 0x0c089cdau: goto P_0c089cda;
case 0x0c089cdcu: goto P_0c089cdc;
case 0x0c089cdeu: goto P_0c089cde;
case 0x0c089ce0u: goto P_0c089ce0;
case 0x0c089ce2u: goto P_0c089ce2;
case 0x0c089ce4u: goto P_0c089ce4;
case 0x0c089ce6u: goto P_0c089ce6;
case 0x0c089ce8u: goto P_0c089ce8;
case 0x0c089ceau: goto P_0c089cea;
case 0x0c089cecu: goto P_0c089cec;
case 0x0c089ceeu: goto P_0c089cee;
case 0x0c089cf0u: goto P_0c089cf0;
case 0x0c089cf2u: goto P_0c089cf2;
case 0x0c089cf4u: goto P_0c089cf4;
case 0x0c089cf6u: goto P_0c089cf6;
case 0x0c089cf8u: goto P_0c089cf8;
case 0x0c089cfau: goto P_0c089cfa;
case 0x0c089cfcu: goto P_0c089cfc;
case 0x0c089cfeu: goto P_0c089cfe;
case 0x0c089d00u: goto P_0c089d00;
case 0x0c089d02u: goto P_0c089d02;
case 0x0c089d04u: goto P_0c089d04;
case 0x0c089d06u: goto P_0c089d06;
case 0x0c089d08u: goto P_0c089d08;
case 0x0c089d0au: goto P_0c089d0a;
case 0x0c089d0cu: goto P_0c089d0c;
case 0x0c089d0eu: goto P_0c089d0e;
case 0x0c089d10u: goto P_0c089d10;
case 0x0c089d12u: goto P_0c089d12;
case 0x0c089d14u: goto P_0c089d14;
case 0x0c089d16u: goto P_0c089d16;
case 0x0c089d18u: goto P_0c089d18;
case 0x0c089d1au: goto P_0c089d1a;
case 0x0c089d1cu: goto P_0c089d1c;
case 0x0c089d1eu: goto P_0c089d1e;
case 0x0c089d20u: goto P_0c089d20;
case 0x0c089d22u: goto P_0c089d22;
case 0x0c089d24u: goto P_0c089d24;
case 0x0c089d26u: goto P_0c089d26;
default: return vf3_matrix_family(target,s,ram);
}
P_0c089aa0: /* original 2fe6, guest PC 0x0c089aa0 */
if(!s->budget--) { s->failed_pc=0x0c089aa0u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c089aa2;
P_0c089aa2: /* original 6e43, guest PC 0x0c089aa2 */
if(!s->budget--) { s->failed_pc=0x0c089aa2u; return 0; }
r[14]=r[4];
goto P_0c089aa4;
P_0c089aa4: /* original 2fd6, guest PC 0x0c089aa4 */
if(!s->budget--) { s->failed_pc=0x0c089aa4u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c089aa6;
P_0c089aa6: /* original 7e18, guest PC 0x0c089aa6 */
if(!s->budget--) { s->failed_pc=0x0c089aa6u; return 0; }
r[14]+=0x00000018u;
goto P_0c089aa8;
P_0c089aa8: /* original 2fc6, guest PC 0x0c089aa8 */
if(!s->budget--) { s->failed_pc=0x0c089aa8u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c089aaa;
P_0c089aaa: /* original 2fb6, guest PC 0x0c089aaa */
if(!s->budget--) { s->failed_pc=0x0c089aaau; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c089aac;
P_0c089aac: /* original 2fa6, guest PC 0x0c089aac */
if(!s->budget--) { s->failed_pc=0x0c089aacu; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c089aae;
P_0c089aae: /* original 2f96, guest PC 0x0c089aae */
if(!s->budget--) { s->failed_pc=0x0c089aaeu; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c089ab0;
P_0c089ab0: /* original 2f86, guest PC 0x0c089ab0 */
if(!s->budget--) { s->failed_pc=0x0c089ab0u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c089ab2;
P_0c089ab2: /* original 4f22, guest PC 0x0c089ab2 */
if(!s->budget--) { s->failed_pc=0x0c089ab2u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c089ab4;
P_0c089ab4: /* original d31c, guest PC 0x0c089ab4 */
if(!s->budget--) { s->failed_pc=0x0c089ab4u; return 0; }
r[3]=read(ram,0x0c089b28u,4);
goto P_0c089ab6;
P_0c089ab6: /* original 430b, guest PC 0x0c089ab6 */
if(!s->budget--) { s->failed_pc=0x0c089ab6u; return 0; }
target=r[3];
r[16]=code_base|0x0c089abau;
r[4]=0x00000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c089abau) { target=s->pc; goto dispatch; }
goto P_0c089aba;
P_0c089ab8: /* original e400, guest PC 0x0c089ab8 */
if(!s->budget--) { s->failed_pc=0x0c089ab8u; return 0; }
r[4]=0x00000000u;
goto P_0c089aba;
P_0c089aba: /* original d21c, guest PC 0x0c089aba */
if(!s->budget--) { s->failed_pc=0x0c089abau; return 0; }
r[2]=read(ram,0x0c089b2cu,4);
goto P_0c089abc;
P_0c089abc: /* original 420b, guest PC 0x0c089abc */
if(!s->budget--) { s->failed_pc=0x0c089abcu; return 0; }
target=r[2];
r[16]=code_base|0x0c089ac0u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c089ac0u) { target=s->pc; goto dispatch; }
goto P_0c089ac0;
P_0c089abe: /* original 0009, guest PC 0x0c089abe */
if(!s->budget--) { s->failed_pc=0x0c089abeu; return 0; }
goto P_0c089ac0;
P_0c089ac0: /* original da1d, guest PC 0x0c089ac0 */
if(!s->budget--) { s->failed_pc=0x0c089ac0u; return 0; }
r[10]=read(ram,0x0c089b38u,4);
goto P_0c089ac2;
P_0c089ac2: /* original ed20, guest PC 0x0c089ac2 */
if(!s->budget--) { s->failed_pc=0x0c089ac2u; return 0; }
r[13]=0x00000020u;
goto P_0c089ac4;
P_0c089ac4: /* original d91b, guest PC 0x0c089ac4 */
if(!s->budget--) { s->failed_pc=0x0c089ac4u; return 0; }
r[9]=read(ram,0x0c089b34u,4);
goto P_0c089ac6;
P_0c089ac6: /* original eb0f, guest PC 0x0c089ac6 */
if(!s->budget--) { s->failed_pc=0x0c089ac6u; return 0; }
r[11]=0x0000000fu;
goto P_0c089ac8;
P_0c089ac8: /* original d819, guest PC 0x0c089ac8 */
if(!s->budget--) { s->failed_pc=0x0c089ac8u; return 0; }
r[8]=read(ram,0x0c089b30u,4);
goto P_0c089aca;
P_0c089aca: /* original 84eb, guest PC 0x0c089aca */
if(!s->budget--) { s->failed_pc=0x0c089acau; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+11,1);
goto P_0c089acc;
P_0c089acc: /* original 64a3, guest PC 0x0c089acc */
if(!s->budget--) { s->failed_pc=0x0c089accu; return 0; }
r[4]=r[10];
goto P_0c089ace;
P_0c089ace: /* original 6603, guest PC 0x0c089ace */
if(!s->budget--) { s->failed_pc=0x0c089aceu; return 0; }
r[6]=r[0];
goto P_0c089ad0;
P_0c089ad0: /* original 666e, guest PC 0x0c089ad0 */
if(!s->budget--) { s->failed_pc=0x0c089ad0u; return 0; }
r[6]=(uint32_t)(int32_t)(int8_t)r[6];
goto P_0c089ad2;
P_0c089ad2: /* original 2668, guest PC 0x0c089ad2 */
if(!s->budget--) { s->failed_pc=0x0c089ad2u; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[6])==0)!=0);
goto P_0c089ad4;
P_0c089ad4: /* original 8d06, guest PC 0x0c089ad4 */
if(!s->budget--) { s->failed_pc=0x0c089ad4u; return 0; }
cond=r[17]&1u;
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[14],2);
r[5]=tmp;
if(cond) { goto P_0c089ae4; }
goto P_0c089ad8;
P_0c089ad6: /* original 65e1, guest PC 0x0c089ad6 */
if(!s->budget--) { s->failed_pc=0x0c089ad6u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[14],2);
r[5]=tmp;
goto P_0c089ad8;
P_0c089ad8: /* original 85e4, guest PC 0x0c089ad8 */
if(!s->budget--) { s->failed_pc=0x0c089ad8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+8,2);
goto P_0c089ada;
P_0c089ada: /* original d418, guest PC 0x0c089ada */
if(!s->budget--) { s->failed_pc=0x0c089adau; return 0; }
r[4]=read(ram,0x0c089b3cu,4);
goto P_0c089adc;
P_0c089adc: /* original 4015, guest PC 0x0c089adc */
if(!s->budget--) { s->failed_pc=0x0c089adcu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[0]>0)!=0);
goto P_0c089ade;
P_0c089ade: /* original 8d01, guest PC 0x0c089ade */
if(!s->budget--) { s->failed_pc=0x0c089adeu; return 0; }
cond=r[17]&1u;
r[5]&=r[11];
if(cond) { goto P_0c089ae4; }
goto P_0c089ae2;
P_0c089ae0: /* original 25b9, guest PC 0x0c089ae0 */
if(!s->budget--) { s->failed_pc=0x0c089ae0u; return 0; }
r[5]&=r[11];
goto P_0c089ae2;
P_0c089ae2: /* original 6493, guest PC 0x0c089ae2 */
if(!s->budget--) { s->failed_pc=0x0c089ae2u; return 0; }
r[4]=r[9];
goto P_0c089ae4;
P_0c089ae4: /* original 6053, guest PC 0x0c089ae4 */
if(!s->budget--) { s->failed_pc=0x0c089ae4u; return 0; }
r[0]=r[5];
goto P_0c089ae6;
P_0c089ae6: /* original 4000, guest PC 0x0c089ae6 */
if(!s->budget--) { s->failed_pc=0x0c089ae6u; return 0; }
r[17]=(r[17]&~1u)|((r[0]>>31)!=0);
r[0]<<=1;
goto P_0c089ae8;
P_0c089ae8: /* original 480b, guest PC 0x0c089ae8 */
if(!s->budget--) { s->failed_pc=0x0c089ae8u; return 0; }
target=r[8];
r[16]=code_base|0x0c089aecu;
r[12]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c089aecu) { target=s->pc; goto dispatch; }
goto P_0c089aec;
P_0c089aea: /* original 0c4d, guest PC 0x0c089aea */
if(!s->budget--) { s->failed_pc=0x0c089aeau; return 0; }
r[12]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c089aec;
P_0c089aec: /* original d314, guest PC 0x0c089aec */
if(!s->budget--) { s->failed_pc=0x0c089aecu; return 0; }
r[3]=read(ram,0x0c089b40u,4);
goto P_0c089aee;
P_0c089aee: /* original 64e3, guest PC 0x0c089aee */
if(!s->budget--) { s->failed_pc=0x0c089aeeu; return 0; }
r[4]=r[14];
goto P_0c089af0;
P_0c089af0: /* original 430b, guest PC 0x0c089af0 */
if(!s->budget--) { s->failed_pc=0x0c089af0u; return 0; }
target=r[3];
r[16]=code_base|0x0c089af4u;
r[4]+=0x0000000cu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c089af4u) { target=s->pc; goto dispatch; }
goto P_0c089af4;
P_0c089af2: /* original 740c, guest PC 0x0c089af2 */
if(!s->budget--) { s->failed_pc=0x0c089af2u; return 0; }
r[4]+=0x0000000cu;
goto P_0c089af4;
P_0c089af4: /* original d313, guest PC 0x0c089af4 */
if(!s->budget--) { s->failed_pc=0x0c089af4u; return 0; }
r[3]=read(ram,0x0c089b44u,4);
goto P_0c089af6;
P_0c089af6: /* original 85e3, guest PC 0x0c089af6 */
if(!s->budget--) { s->failed_pc=0x0c089af6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+6,2);
goto P_0c089af8;
P_0c089af8: /* original 430b, guest PC 0x0c089af8 */
if(!s->budget--) { s->failed_pc=0x0c089af8u; return 0; }
target=r[3];
r[16]=code_base|0x0c089afcu;
r[4]=r[0];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c089afcu) { target=s->pc; goto dispatch; }
goto P_0c089afc;
P_0c089afa: /* original 6403, guest PC 0x0c089afa */
if(!s->budget--) { s->failed_pc=0x0c089afau; return 0; }
r[4]=r[0];
goto P_0c089afc;
P_0c089afc: /* original d212, guest PC 0x0c089afc */
if(!s->budget--) { s->failed_pc=0x0c089afcu; return 0; }
r[2]=read(ram,0x0c089b48u,4);
goto P_0c089afe;
P_0c089afe: /* original 420b, guest PC 0x0c089afe */
if(!s->budget--) { s->failed_pc=0x0c089afeu; return 0; }
target=r[2];
r[16]=code_base|0x0c089b02u;
r[4]=(uint32_t)(int32_t)(int16_t)r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c089b02u) { target=s->pc; goto dispatch; }
goto P_0c089b02;
P_0c089b00: /* original 64cf, guest PC 0x0c089b00 */
if(!s->budget--) { s->failed_pc=0x0c089b00u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)r[12];
goto P_0c089b02;
P_0c089b02: /* original 4d10, guest PC 0x0c089b02 */
if(!s->budget--) { s->failed_pc=0x0c089b02u; return 0; }
--r[13];
r[17]=(r[17]&~1u)|((r[13]==0)!=0);
goto P_0c089b04;
P_0c089b04: /* original 8fe1, guest PC 0x0c089b04 */
if(!s->budget--) { s->failed_pc=0x0c089b04u; return 0; }
cond=r[17]&1u;
r[14]+=0x00000028u;
if(!cond) { goto P_0c089aca; }
goto P_0c089b08;
P_0c089b06: /* original 7e28, guest PC 0x0c089b06 */
if(!s->budget--) { s->failed_pc=0x0c089b06u; return 0; }
r[14]+=0x00000028u;
goto P_0c089b08;
P_0c089b08: /* original 4f26, guest PC 0x0c089b08 */
if(!s->budget--) { s->failed_pc=0x0c089b08u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c089b0a;
P_0c089b0a: /* original d210, guest PC 0x0c089b0a */
if(!s->budget--) { s->failed_pc=0x0c089b0au; return 0; }
r[2]=read(ram,0x0c089b4cu,4);
goto P_0c089b0c;
P_0c089b0c: /* original e401, guest PC 0x0c089b0c */
if(!s->budget--) { s->failed_pc=0x0c089b0cu; return 0; }
r[4]=0x00000001u;
goto P_0c089b0e;
P_0c089b0e: /* original 68f6, guest PC 0x0c089b0e */
if(!s->budget--) { s->failed_pc=0x0c089b0eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c089b10;
P_0c089b10: /* original 69f6, guest PC 0x0c089b10 */
if(!s->budget--) { s->failed_pc=0x0c089b10u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c089b12;
P_0c089b12: /* original 6af6, guest PC 0x0c089b12 */
if(!s->budget--) { s->failed_pc=0x0c089b12u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c089b14;
P_0c089b14: /* original 6bf6, guest PC 0x0c089b14 */
if(!s->budget--) { s->failed_pc=0x0c089b14u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c089b16;
P_0c089b16: /* original 6cf6, guest PC 0x0c089b16 */
if(!s->budget--) { s->failed_pc=0x0c089b16u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c089b18;
P_0c089b18: /* original 6df6, guest PC 0x0c089b18 */
if(!s->budget--) { s->failed_pc=0x0c089b18u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c089b1a;
P_0c089b1a: /* original 422b, guest PC 0x0c089b1a */
if(!s->budget--) { s->failed_pc=0x0c089b1au; return 0; }
target=r[2];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
code_base=target&0xff000000u;
switch(target&0x1fffffffu) {
case 0x0c03b450u: vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); return vf3_matrix_family(target,s,ram);
case 0x0c03b4b0u: vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); return vf3_matrix_family(target,s,ram);
case 0x0c03b530u: vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); return vf3_matrix_family(target,s,ram);
case 0x0c03b620u: vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); return vf3_matrix_family(target,s,ram);
case 0x0c03b820u: vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); return vf3_matrix_family(target,s,ram);
case 0x0c03bd80u: vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); return vf3_matrix_family(target,s,ram);
case 0x0c03c0e0u: vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); return vf3_matrix_family(target,s,ram);
case 0x0c03c4a0u: vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); return vf3_matrix_family(target,s,ram);
case 0x0c03c4f0u: vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); return vf3_matrix_family(target,s,ram);
case 0x0c03c610u: vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); return vf3_matrix_family(target,s,ram);
case 0x0c03c6c0u: vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); return vf3_matrix_family(target,s,ram);
case 0x0c03c880u: vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); return vf3_matrix_family(target,s,ram);
case 0x0c03c940u: vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); return vf3_matrix_family(target,s,ram);
case 0x0c03c970u: vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); return vf3_matrix_family(target,s,ram);
case 0x0c03cbd0u: vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); return vf3_matrix_family(target,s,ram);
case 0x0c03cc60u: vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); return vf3_matrix_family(target,s,ram);
case 0x0c03cc90u: vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); return vf3_matrix_family(target,s,ram);
case 0x0c03ccb0u: vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); return vf3_matrix_family(target,s,ram);
default: goto dispatch; }
P_0c089b1c: /* original 6ef6, guest PC 0x0c089b1c */
if(!s->budget--) { s->failed_pc=0x0c089b1cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c089b1eu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c089b1eu; return 0; } return 1;
P_0c089b50: /* original e031, guest PC 0x0c089b50 */
if(!s->budget--) { s->failed_pc=0x0c089b50u; return 0; }
r[0]=0x00000031u;
goto P_0c089b52;
P_0c089b52: /* original 61f2, guest PC 0x0c089b52 */
if(!s->budget--) { s->failed_pc=0x0c089b52u; return 0; }
tmp=read(ram,r[15],4);
r[1]=tmp;
goto P_0c089b54;
P_0c089b54: /* original e300, guest PC 0x0c089b54 */
if(!s->budget--) { s->failed_pc=0x0c089b54u; return 0; }
r[3]=0x00000000u;
goto P_0c089b56;
P_0c089b56: /* original 0434, guest PC 0x0c089b56 */
if(!s->budget--) { s->failed_pc=0x0c089b56u; return 0; }
write(ram,r[4]+r[0],r[3],1);
goto P_0c089b58;
P_0c089b58: /* original c72c, guest PC 0x0c089b58 */
if(!s->budget--) { s->failed_pc=0x0c089b58u; return 0; }
r[0]=code_base|0x00089c0cu;
goto P_0c089b5a;
P_0c089b5a: /* original f408, guest PC 0x0c089b5a */
if(!s->budget--) { s->failed_pc=0x0c089b5au; return 0; }
vf3_matrix_load(s,ram,4,r[0]);
goto P_0c089b5c;
P_0c089b5c: /* original c72c, guest PC 0x0c089b5c */
if(!s->budget--) { s->failed_pc=0x0c089b5cu; return 0; }
r[0]=code_base|0x00089c10u;
goto P_0c089b5e;
P_0c089b5e: /* original f208, guest PC 0x0c089b5e */
if(!s->budget--) { s->failed_pc=0x0c089b5eu; return 0; }
vf3_matrix_load(s,ram,2,r[0]);
goto P_0c089b60;
P_0c089b60: /* original f368, guest PC 0x0c089b60 */
if(!s->budget--) { s->failed_pc=0x0c089b60u; return 0; }
vf3_matrix_load(s,ram,3,r[6]);
goto P_0c089b62;
P_0c089b62: /* original f235, guest PC 0x0c089b62 */
if(!s->budget--) { s->failed_pc=0x0c089b62u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[2])>as_float(fr[3]))!=0);
goto P_0c089b64;
P_0c089b64: /* original 8902, guest PC 0x0c089b64 */
if(!s->budget--) { s->failed_pc=0x0c089b64u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c089b6c; }
goto P_0c089b66;
P_0c089b66: /* original f368, guest PC 0x0c089b66 */
if(!s->budget--) { s->failed_pc=0x0c089b66u; return 0; }
vf3_matrix_load(s,ram,3,r[6]);
goto P_0c089b68;
P_0c089b68: /* original a006, guest PC 0x0c089b68 */
if(!s->budget--) { s->failed_pc=0x0c089b68u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'-');
goto P_0c089b78;
P_0c089b6a: /* original f341, guest PC 0x0c089b6a */
if(!s->budget--) { s->failed_pc=0x0c089b6au; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'-');
goto P_0c089b6c;
P_0c089b6c: /* original c729, guest PC 0x0c089b6c */
if(!s->budget--) { s->failed_pc=0x0c089b6cu; return 0; }
r[0]=code_base|0x00089c14u;
goto P_0c089b6e;
P_0c089b6e: /* original f108, guest PC 0x0c089b6e */
if(!s->budget--) { s->failed_pc=0x0c089b6eu; return 0; }
vf3_matrix_load(s,ram,1,r[0]);
goto P_0c089b70;
P_0c089b70: /* original f315, guest PC 0x0c089b70 */
if(!s->budget--) { s->failed_pc=0x0c089b70u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[1]))!=0);
goto P_0c089b72;
P_0c089b72: /* original 8905, guest PC 0x0c089b72 */
if(!s->budget--) { s->failed_pc=0x0c089b72u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c089b80; }
goto P_0c089b74;
P_0c089b74: /* original f368, guest PC 0x0c089b74 */
if(!s->budget--) { s->failed_pc=0x0c089b74u; return 0; }
vf3_matrix_load(s,ram,3,r[6]);
goto P_0c089b76;
P_0c089b76: /* original f340, guest PC 0x0c089b76 */
if(!s->budget--) { s->failed_pc=0x0c089b76u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'+');
goto P_0c089b78;
P_0c089b78: /* original e031, guest PC 0x0c089b78 */
if(!s->budget--) { s->failed_pc=0x0c089b78u; return 0; }
r[0]=0x00000031u;
goto P_0c089b7a;
P_0c089b7a: /* original f63a, guest PC 0x0c089b7a */
if(!s->budget--) { s->failed_pc=0x0c089b7au; return 0; }
vf3_matrix_store(s,ram,3,r[6]);
goto P_0c089b7c;
P_0c089b7c: /* original e303, guest PC 0x0c089b7c */
if(!s->budget--) { s->failed_pc=0x0c089b7cu; return 0; }
r[3]=0x00000003u;
goto P_0c089b7e;
P_0c089b7e: /* original 0434, guest PC 0x0c089b7e */
if(!s->budget--) { s->failed_pc=0x0c089b7eu; return 0; }
write(ram,r[4]+r[0],r[3],1);
goto P_0c089b80;
P_0c089b80: /* original f318, guest PC 0x0c089b80 */
if(!s->budget--) { s->failed_pc=0x0c089b80u; return 0; }
vf3_matrix_load(s,ram,3,r[1]);
goto P_0c089b82;
P_0c089b82: /* original f28d, guest PC 0x0c089b82 */
if(!s->budget--) { s->failed_pc=0x0c089b82u; return 0; }
fr[2]=0;
goto P_0c089b84;
P_0c089b84: /* original f235, guest PC 0x0c089b84 */
if(!s->budget--) { s->failed_pc=0x0c089b84u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[2])>as_float(fr[3]))!=0);
goto P_0c089b86;
P_0c089b86: /* original 8902, guest PC 0x0c089b86 */
if(!s->budget--) { s->failed_pc=0x0c089b86u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c089b8e; }
goto P_0c089b88;
P_0c089b88: /* original f318, guest PC 0x0c089b88 */
if(!s->budget--) { s->failed_pc=0x0c089b88u; return 0; }
vf3_matrix_load(s,ram,3,r[1]);
goto P_0c089b8a;
P_0c089b8a: /* original a006, guest PC 0x0c089b8a */
if(!s->budget--) { s->failed_pc=0x0c089b8au; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'-');
goto P_0c089b9a;
P_0c089b8c: /* original f341, guest PC 0x0c089b8c */
if(!s->budget--) { s->failed_pc=0x0c089b8cu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'-');
goto P_0c089b8e;
P_0c089b8e: /* original c722, guest PC 0x0c089b8e */
if(!s->budget--) { s->failed_pc=0x0c089b8eu; return 0; }
r[0]=code_base|0x00089c18u;
goto P_0c089b90;
P_0c089b90: /* original f108, guest PC 0x0c089b90 */
if(!s->budget--) { s->failed_pc=0x0c089b90u; return 0; }
vf3_matrix_load(s,ram,1,r[0]);
goto P_0c089b92;
P_0c089b92: /* original f315, guest PC 0x0c089b92 */
if(!s->budget--) { s->failed_pc=0x0c089b92u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[1]))!=0);
goto P_0c089b94;
P_0c089b94: /* original 8905, guest PC 0x0c089b94 */
if(!s->budget--) { s->failed_pc=0x0c089b94u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c089ba2; }
goto P_0c089b96;
P_0c089b96: /* original f318, guest PC 0x0c089b96 */
if(!s->budget--) { s->failed_pc=0x0c089b96u; return 0; }
vf3_matrix_load(s,ram,3,r[1]);
goto P_0c089b98;
P_0c089b98: /* original f340, guest PC 0x0c089b98 */
if(!s->budget--) { s->failed_pc=0x0c089b98u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'+');
goto P_0c089b9a;
P_0c089b9a: /* original e031, guest PC 0x0c089b9a */
if(!s->budget--) { s->failed_pc=0x0c089b9au; return 0; }
r[0]=0x00000031u;
goto P_0c089b9c;
P_0c089b9c: /* original f13a, guest PC 0x0c089b9c */
if(!s->budget--) { s->failed_pc=0x0c089b9cu; return 0; }
vf3_matrix_store(s,ram,3,r[1]);
goto P_0c089b9e;
P_0c089b9e: /* original e303, guest PC 0x0c089b9e */
if(!s->budget--) { s->failed_pc=0x0c089b9eu; return 0; }
r[3]=0x00000003u;
goto P_0c089ba0;
P_0c089ba0: /* original 0434, guest PC 0x0c089ba0 */
if(!s->budget--) { s->failed_pc=0x0c089ba0u; return 0; }
write(ram,r[4]+r[0],r[3],1);
goto P_0c089ba2;
P_0c089ba2: /* original c71e, guest PC 0x0c089ba2 */
if(!s->budget--) { s->failed_pc=0x0c089ba2u; return 0; }
r[0]=code_base|0x00089c1cu;
goto P_0c089ba4;
P_0c089ba4: /* original f378, guest PC 0x0c089ba4 */
if(!s->budget--) { s->failed_pc=0x0c089ba4u; return 0; }
vf3_matrix_load(s,ram,3,r[7]);
goto P_0c089ba6;
P_0c089ba6: /* original f408, guest PC 0x0c089ba6 */
if(!s->budget--) { s->failed_pc=0x0c089ba6u; return 0; }
vf3_matrix_load(s,ram,4,r[0]);
goto P_0c089ba8;
P_0c089ba8: /* original c71d, guest PC 0x0c089ba8 */
if(!s->budget--) { s->failed_pc=0x0c089ba8u; return 0; }
r[0]=code_base|0x00089c20u;
goto P_0c089baa;
P_0c089baa: /* original f208, guest PC 0x0c089baa */
if(!s->budget--) { s->failed_pc=0x0c089baau; return 0; }
vf3_matrix_load(s,ram,2,r[0]);
goto P_0c089bac;
P_0c089bac: /* original f235, guest PC 0x0c089bac */
if(!s->budget--) { s->failed_pc=0x0c089bacu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[2])>as_float(fr[3]))!=0);
goto P_0c089bae;
P_0c089bae: /* original 890b, guest PC 0x0c089bae */
if(!s->budget--) { s->failed_pc=0x0c089baeu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c089bc8; }
goto P_0c089bb0;
P_0c089bb0: /* original c71c, guest PC 0x0c089bb0 */
if(!s->budget--) { s->failed_pc=0x0c089bb0u; return 0; }
r[0]=code_base|0x00089c24u;
goto P_0c089bb2;
P_0c089bb2: /* original f158, guest PC 0x0c089bb2 */
if(!s->budget--) { s->failed_pc=0x0c089bb2u; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
goto P_0c089bb4;
P_0c089bb4: /* original f308, guest PC 0x0c089bb4 */
if(!s->budget--) { s->failed_pc=0x0c089bb4u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c089bb6;
P_0c089bb6: /* original c71c, guest PC 0x0c089bb6 */
if(!s->budget--) { s->failed_pc=0x0c089bb6u; return 0; }
r[0]=code_base|0x00089c28u;
goto P_0c089bb8;
P_0c089bb8: /* original f131, guest PC 0x0c089bb8 */
if(!s->budget--) { s->failed_pc=0x0c089bb8u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[3],r[18],'-');
goto P_0c089bba;
P_0c089bba: /* original f51a, guest PC 0x0c089bba */
if(!s->budget--) { s->failed_pc=0x0c089bbau; return 0; }
vf3_matrix_store(s,ram,1,r[5]);
goto P_0c089bbc;
P_0c089bbc: /* original f058, guest PC 0x0c089bbc */
if(!s->budget--) { s->failed_pc=0x0c089bbcu; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
goto P_0c089bbe;
P_0c089bbe: /* original f108, guest PC 0x0c089bbe */
if(!s->budget--) { s->failed_pc=0x0c089bbeu; return 0; }
vf3_matrix_load(s,ram,1,r[0]);
goto P_0c089bc0;
P_0c089bc0: /* original f105, guest PC 0x0c089bc0 */
if(!s->budget--) { s->failed_pc=0x0c089bc0u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[1])>as_float(fr[0]))!=0);
goto P_0c089bc2;
P_0c089bc2: /* original 8b0d, guest PC 0x0c089bc2 */
if(!s->budget--) { s->failed_pc=0x0c089bc2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c089be0; }
goto P_0c089bc4;
P_0c089bc4: /* original a00f, guest PC 0x0c089bc4 */
if(!s->budget--) { s->failed_pc=0x0c089bc4u; return 0; }
goto P_0c089be6;
P_0c089bc6: /* original 0009, guest PC 0x0c089bc6 */
if(!s->budget--) { s->failed_pc=0x0c089bc6u; return 0; }
goto P_0c089bc8;
P_0c089bc8: /* original f345, guest PC 0x0c089bc8 */
if(!s->budget--) { s->failed_pc=0x0c089bc8u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[4]))!=0);
goto P_0c089bca;
P_0c089bca: /* original 890c, guest PC 0x0c089bca */
if(!s->budget--) { s->failed_pc=0x0c089bcau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c089be6; }
goto P_0c089bcc;
P_0c089bcc: /* original c717, guest PC 0x0c089bcc */
if(!s->budget--) { s->failed_pc=0x0c089bccu; return 0; }
r[0]=code_base|0x00089c2cu;
goto P_0c089bce;
P_0c089bce: /* original f158, guest PC 0x0c089bce */
if(!s->budget--) { s->failed_pc=0x0c089bceu; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
goto P_0c089bd0;
P_0c089bd0: /* original f308, guest PC 0x0c089bd0 */
if(!s->budget--) { s->failed_pc=0x0c089bd0u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c089bd2;
P_0c089bd2: /* original c717, guest PC 0x0c089bd2 */
if(!s->budget--) { s->failed_pc=0x0c089bd2u; return 0; }
r[0]=code_base|0x00089c30u;
goto P_0c089bd4;
P_0c089bd4: /* original f130, guest PC 0x0c089bd4 */
if(!s->budget--) { s->failed_pc=0x0c089bd4u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[3],r[18],'+');
goto P_0c089bd6;
P_0c089bd6: /* original f51a, guest PC 0x0c089bd6 */
if(!s->budget--) { s->failed_pc=0x0c089bd6u; return 0; }
vf3_matrix_store(s,ram,1,r[5]);
goto P_0c089bd8;
P_0c089bd8: /* original f058, guest PC 0x0c089bd8 */
if(!s->budget--) { s->failed_pc=0x0c089bd8u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
goto P_0c089bda;
P_0c089bda: /* original f108, guest PC 0x0c089bda */
if(!s->budget--) { s->failed_pc=0x0c089bdau; return 0; }
vf3_matrix_load(s,ram,1,r[0]);
goto P_0c089bdc;
P_0c089bdc: /* original f015, guest PC 0x0c089bdc */
if(!s->budget--) { s->failed_pc=0x0c089bdcu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[0])>as_float(fr[1]))!=0);
goto P_0c089bde;
P_0c089bde: /* original 8902, guest PC 0x0c089bde */
if(!s->budget--) { s->failed_pc=0x0c089bdeu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c089be6; }
goto P_0c089be0;
P_0c089be0: /* original f358, guest PC 0x0c089be0 */
if(!s->budget--) { s->failed_pc=0x0c089be0u; return 0; }
vf3_matrix_load(s,ram,3,r[5]);
goto P_0c089be2;
P_0c089be2: /* original e01c, guest PC 0x0c089be2 */
if(!s->budget--) { s->failed_pc=0x0c089be2u; return 0; }
r[0]=0x0000001cu;
goto P_0c089be4;
P_0c089be4: /* original f437, guest PC 0x0c089be4 */
if(!s->budget--) { s->failed_pc=0x0c089be4u; return 0; }
vf3_matrix_store(s,ram,3,r[4]+r[0]);
goto P_0c089be6;
P_0c089be6: /* original 000b, guest PC 0x0c089be6 */
if(!s->budget--) { s->failed_pc=0x0c089be6u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c089be8: /* original 0009, guest PC 0x0c089be8 */
if(!s->budget--) { s->failed_pc=0x0c089be8u; return 0; }
goto P_0c089bea;
P_0c089bea: /* original f38d, guest PC 0x0c089bea */
if(!s->budget--) { s->failed_pc=0x0c089beau; return 0; }
fr[3]=0;
goto P_0c089bec;
P_0c089bec: /* original f345, guest PC 0x0c089bec */
if(!s->budget--) { s->failed_pc=0x0c089becu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[4]))!=0);
goto P_0c089bee;
P_0c089bee: /* original d711, guest PC 0x0c089bee */
if(!s->budget--) { s->failed_pc=0x0c089beeu; return 0; }
r[7]=read(ram,0x0c089c34u,4);
goto P_0c089bf0;
P_0c089bf0: /* original 7ff8, guest PC 0x0c089bf0 */
if(!s->budget--) { s->failed_pc=0x0c089bf0u; return 0; }
r[15]+=0xfffffff8u;
goto P_0c089bf2;
P_0c089bf2: /* original e034, guest PC 0x0c089bf2 */
if(!s->budget--) { s->failed_pc=0x0c089bf2u; return 0; }
r[0]=0x00000034u;
goto P_0c089bf4;
P_0c089bf4: /* original 8d20, guest PC 0x0c089bf4 */
if(!s->budget--) { s->failed_pc=0x0c089bf4u; return 0; }
cond=r[17]&1u;
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
if(cond) { goto P_0c089c38; }
goto P_0c089bf8;
P_0c089bf6: /* original 064d, guest PC 0x0c089bf6 */
if(!s->budget--) { s->failed_pc=0x0c089bf6u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c089bf8;
P_0c089bf8: /* original 9205, guest PC 0x0c089bf8 */
if(!s->budget--) { s->failed_pc=0x0c089bf8u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c089c06u,2);
goto P_0c089bfa;
P_0c089bfa: /* original 9305, guest PC 0x0c089bfa */
if(!s->budget--) { s->failed_pc=0x0c089bfau; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c089c08u,2);
goto P_0c089bfc;
P_0c089bfc: /* original 362c, guest PC 0x0c089bfc */
if(!s->budget--) { s->failed_pc=0x0c089bfcu; return 0; }
r[6]+=r[2];
goto P_0c089bfe;
P_0c089bfe: /* original 3633, guest PC 0x0c089bfe */
if(!s->budget--) { s->failed_pc=0x0c089bfeu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[6]>=(int32_t)r[3])!=0);
goto P_0c089c00;
P_0c089c00: /* original 8923, guest PC 0x0c089c00 */
if(!s->budget--) { s->failed_pc=0x0c089c00u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c089c4a; }
goto P_0c089c02;
P_0c089c02: /* original a024, guest PC 0x0c089c02 */
if(!s->budget--) { s->failed_pc=0x0c089c02u; return 0; }
goto P_0c089c4e;
P_0c089c04: /* original 0009, guest PC 0x0c089c04 */
if(!s->budget--) { s->failed_pc=0x0c089c04u; return 0; }
if(!vf3_matrix_family(0x0c089c06u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c089c06u; return 0; } return 1;
P_0c089c38: /* original 9176, guest PC 0x0c089c38 */
if(!s->budget--) { s->failed_pc=0x0c089c38u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c089d28u,2);
goto P_0c089c3a;
P_0c089c3a: /* original 6373, guest PC 0x0c089c3a */
if(!s->budget--) { s->failed_pc=0x0c089c3au; return 0; }
r[3]=r[7];
goto P_0c089c3c;
P_0c089c3c: /* original 3618, guest PC 0x0c089c3c */
if(!s->budget--) { s->failed_pc=0x0c089c3cu; return 0; }
r[6]-=r[1];
goto P_0c089c3e;
P_0c089c3e: /* original 2369, guest PC 0x0c089c3e */
if(!s->budget--) { s->failed_pc=0x0c089c3eu; return 0; }
r[3]&=r[6];
goto P_0c089c40;
P_0c089c40: /* original 2f32, guest PC 0x0c089c40 */
if(!s->budget--) { s->failed_pc=0x0c089c40u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c089c42;
P_0c089c42: /* original d23a, guest PC 0x0c089c42 */
if(!s->budget--) { s->failed_pc=0x0c089c42u; return 0; }
r[2]=read(ram,0x0c089d2cu,4);
goto P_0c089c44;
P_0c089c44: /* original 3320, guest PC 0x0c089c44 */
if(!s->budget--) { s->failed_pc=0x0c089c44u; return 0; }
r[17]=(r[17]&~1u)|((r[3]==r[2])!=0);
goto P_0c089c46;
P_0c089c46: /* original 1f21, guest PC 0x0c089c46 */
if(!s->budget--) { s->failed_pc=0x0c089c46u; return 0; }
write(ram,r[15]+4,r[2],4);
goto P_0c089c48;
P_0c089c48: /* original 8901, guest PC 0x0c089c48 */
if(!s->budget--) { s->failed_pc=0x0c089c48u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c089c4e; }
goto P_0c089c4a;
P_0c089c4a: /* original e034, guest PC 0x0c089c4a */
if(!s->budget--) { s->failed_pc=0x0c089c4au; return 0; }
r[0]=0x00000034u;
goto P_0c089c4c;
P_0c089c4c: /* original 0465, guest PC 0x0c089c4c */
if(!s->budget--) { s->failed_pc=0x0c089c4cu; return 0; }
write(ram,r[4]+r[0],r[6],2);
goto P_0c089c4e;
P_0c089c4e: /* original 2558, guest PC 0x0c089c4e */
if(!s->budget--) { s->failed_pc=0x0c089c4eu; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[5])==0)!=0);
goto P_0c089c50;
P_0c089c50: /* original e036, guest PC 0x0c089c50 */
if(!s->budget--) { s->failed_pc=0x0c089c50u; return 0; }
r[0]=0x00000036u;
goto P_0c089c52;
P_0c089c52: /* original 8d06, guest PC 0x0c089c52 */
if(!s->budget--) { s->failed_pc=0x0c089c52u; return 0; }
cond=r[17]&1u;
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
if(cond) { goto P_0c089c62; }
goto P_0c089c56;
P_0c089c54: /* original 064d, guest PC 0x0c089c54 */
if(!s->budget--) { s->failed_pc=0x0c089c54u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c089c56;
P_0c089c56: /* original 6053, guest PC 0x0c089c56 */
if(!s->budget--) { s->failed_pc=0x0c089c56u; return 0; }
r[0]=r[5];
goto P_0c089c58;
P_0c089c58: /* original 8802, guest PC 0x0c089c58 */
if(!s->budget--) { s->failed_pc=0x0c089c58u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c089c5a;
P_0c089c5a: /* original 8902, guest PC 0x0c089c5a */
if(!s->budget--) { s->failed_pc=0x0c089c5au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c089c62; }
goto P_0c089c5c;
P_0c089c5c: /* original 6053, guest PC 0x0c089c5c */
if(!s->budget--) { s->failed_pc=0x0c089c5cu; return 0; }
r[0]=r[5];
goto P_0c089c5e;
P_0c089c5e: /* original 8804, guest PC 0x0c089c5e */
if(!s->budget--) { s->failed_pc=0x0c089c5eu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000004u)!=0);
goto P_0c089c60;
P_0c089c60: /* original 8b09, guest PC 0x0c089c60 */
if(!s->budget--) { s->failed_pc=0x0c089c60u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c089c76; }
goto P_0c089c62;
P_0c089c62: /* original d233, guest PC 0x0c089c62 */
if(!s->budget--) { s->failed_pc=0x0c089c62u; return 0; }
r[2]=read(ram,0x0c089d30u,4);
goto P_0c089c64;
P_0c089c64: /* original 76e0, guest PC 0x0c089c64 */
if(!s->budget--) { s->failed_pc=0x0c089c64u; return 0; }
r[6]+=0xffffffe0u;
goto P_0c089c66;
P_0c089c66: /* original 6573, guest PC 0x0c089c66 */
if(!s->budget--) { s->failed_pc=0x0c089c66u; return 0; }
r[5]=r[7];
goto P_0c089c68;
P_0c089c68: /* original 2569, guest PC 0x0c089c68 */
if(!s->budget--) { s->failed_pc=0x0c089c68u; return 0; }
r[5]&=r[6];
goto P_0c089c6a;
P_0c089c6a: /* original 6323, guest PC 0x0c089c6a */
if(!s->budget--) { s->failed_pc=0x0c089c6au; return 0; }
r[3]=r[2];
goto P_0c089c6c;
P_0c089c6c: /* original 3530, guest PC 0x0c089c6c */
if(!s->budget--) { s->failed_pc=0x0c089c6cu; return 0; }
r[17]=(r[17]&~1u)|((r[5]==r[3])!=0);
goto P_0c089c6e;
P_0c089c6e: /* original 2f22, guest PC 0x0c089c6e */
if(!s->budget--) { s->failed_pc=0x0c089c6eu; return 0; }
write(ram,r[15],r[2],4);
goto P_0c089c70;
P_0c089c70: /* original 8b05, guest PC 0x0c089c70 */
if(!s->budget--) { s->failed_pc=0x0c089c70u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c089c7e; }
goto P_0c089c72;
P_0c089c72: /* original a006, guest PC 0x0c089c72 */
if(!s->budget--) { s->failed_pc=0x0c089c72u; return 0; }
goto P_0c089c82;
P_0c089c74: /* original 0009, guest PC 0x0c089c74 */
if(!s->budget--) { s->failed_pc=0x0c089c74u; return 0; }
goto P_0c089c76;
P_0c089c76: /* original 9358, guest PC 0x0c089c76 */
if(!s->budget--) { s->failed_pc=0x0c089c76u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c089d2au,2);
goto P_0c089c78;
P_0c089c78: /* original 7620, guest PC 0x0c089c78 */
if(!s->budget--) { s->failed_pc=0x0c089c78u; return 0; }
r[6]+=0x00000020u;
goto P_0c089c7a;
P_0c089c7a: /* original 3633, guest PC 0x0c089c7a */
if(!s->budget--) { s->failed_pc=0x0c089c7au; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[6]>=(int32_t)r[3])!=0);
goto P_0c089c7c;
P_0c089c7c: /* original 8b01, guest PC 0x0c089c7c */
if(!s->budget--) { s->failed_pc=0x0c089c7cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c089c82; }
goto P_0c089c7e;
P_0c089c7e: /* original e036, guest PC 0x0c089c7e */
if(!s->budget--) { s->failed_pc=0x0c089c7eu; return 0; }
r[0]=0x00000036u;
goto P_0c089c80;
P_0c089c80: /* original 0465, guest PC 0x0c089c80 */
if(!s->budget--) { s->failed_pc=0x0c089c80u; return 0; }
write(ram,r[4]+r[0],r[6],2);
goto P_0c089c82;
P_0c089c82: /* original 000b, guest PC 0x0c089c82 */
if(!s->budget--) { s->failed_pc=0x0c089c82u; return 0; }
target=r[16];
r[15]+=0x00000008u;
s->pc=target; return ram->oob==0;
P_0c089c84: /* original 7f08, guest PC 0x0c089c84 */
if(!s->budget--) { s->failed_pc=0x0c089c84u; return 0; }
r[15]+=0x00000008u;
goto P_0c089c86;
P_0c089c86: /* original 2fe6, guest PC 0x0c089c86 */
if(!s->budget--) { s->failed_pc=0x0c089c86u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c089c88;
P_0c089c88: /* original e301, guest PC 0x0c089c88 */
if(!s->budget--) { s->failed_pc=0x0c089c88u; return 0; }
r[3]=0x00000001u;
goto P_0c089c8a;
P_0c089c8a: /* original 2fd6, guest PC 0x0c089c8a */
if(!s->budget--) { s->failed_pc=0x0c089c8au; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c089c8c;
P_0c089c8c: /* original e02c, guest PC 0x0c089c8c */
if(!s->budget--) { s->failed_pc=0x0c089c8cu; return 0; }
r[0]=0x0000002cu;
goto P_0c089c8e;
P_0c089c8e: /* original 2fc6, guest PC 0x0c089c8e */
if(!s->budget--) { s->failed_pc=0x0c089c8eu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c089c90;
P_0c089c90: /* original 6d43, guest PC 0x0c089c90 */
if(!s->budget--) { s->failed_pc=0x0c089c90u; return 0; }
r[13]=r[4];
goto P_0c089c92;
P_0c089c92: /* original 2fb6, guest PC 0x0c089c92 */
if(!s->budget--) { s->failed_pc=0x0c089c92u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c089c94;
P_0c089c94: /* original 2fa6, guest PC 0x0c089c94 */
if(!s->budget--) { s->failed_pc=0x0c089c94u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c089c96;
P_0c089c96: /* original 6a53, guest PC 0x0c089c96 */
if(!s->budget--) { s->failed_pc=0x0c089c96u; return 0; }
r[10]=r[5];
goto P_0c089c98;
P_0c089c98: /* original 2f96, guest PC 0x0c089c98 */
if(!s->budget--) { s->failed_pc=0x0c089c98u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c089c9a;
P_0c089c9a: /* original 6963, guest PC 0x0c089c9a */
if(!s->budget--) { s->failed_pc=0x0c089c9au; return 0; }
r[9]=r[6];
goto P_0c089c9c;
P_0c089c9c: /* original 4f22, guest PC 0x0c089c9c */
if(!s->budget--) { s->failed_pc=0x0c089c9cu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c089c9e;
P_0c089c9e: /* original 7ff8, guest PC 0x0c089c9e */
if(!s->budget--) { s->failed_pc=0x0c089c9eu; return 0; }
r[15]+=0xfffffff8u;
goto P_0c089ca0;
P_0c089ca0: /* original 5cf9, guest PC 0x0c089ca0 */
if(!s->budget--) { s->failed_pc=0x0c089ca0u; return 0; }
r[12]=read(ram,r[15]+36,4);
goto P_0c089ca2;
P_0c089ca2: /* original 0d35, guest PC 0x0c089ca2 */
if(!s->budget--) { s->failed_pc=0x0c089ca2u; return 0; }
write(ram,r[13]+r[0],r[3],2);
goto P_0c089ca4;
P_0c089ca4: /* original e031, guest PC 0x0c089ca4 */
if(!s->budget--) { s->failed_pc=0x0c089ca4u; return 0; }
r[0]=0x00000031u;
goto P_0c089ca6;
P_0c089ca6: /* original 0edc, guest PC 0x0c089ca6 */
if(!s->budget--) { s->failed_pc=0x0c089ca6u; return 0; }
r[14]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+r[0],1);
goto P_0c089ca8;
P_0c089ca8: /* original 2ee8, guest PC 0x0c089ca8 */
if(!s->budget--) { s->failed_pc=0x0c089ca8u; return 0; }
r[17]=(r[17]&~1u)|(((r[14]&r[14])==0)!=0);
goto P_0c089caa;
P_0c089caa: /* original 8f05, guest PC 0x0c089caa */
if(!s->budget--) { s->failed_pc=0x0c089caau; return 0; }
cond=r[17]&1u;
r[11]=r[7];
if(!cond) { goto P_0c089cb8; }
goto P_0c089cae;
P_0c089cac: /* original 6b73, guest PC 0x0c089cac */
if(!s->budget--) { s->failed_pc=0x0c089cacu; return 0; }
r[11]=r[7];
goto P_0c089cae;
P_0c089cae: /* original d221, guest PC 0x0c089cae */
if(!s->budget--) { s->failed_pc=0x0c089caeu; return 0; }
r[2]=read(ram,0x0c089d34u,4);
goto P_0c089cb0;
P_0c089cb0: /* original 420b, guest PC 0x0c089cb0 */
if(!s->budget--) { s->failed_pc=0x0c089cb0u; return 0; }
target=r[2];
r[16]=code_base|0x0c089cb4u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c089cb4u) { target=s->pc; goto dispatch; }
goto P_0c089cb4;
P_0c089cb2: /* original 0009, guest PC 0x0c089cb2 */
if(!s->budget--) { s->failed_pc=0x0c089cb2u; return 0; }
goto P_0c089cb4;
P_0c089cb4: /* original ee07, guest PC 0x0c089cb4 */
if(!s->budget--) { s->failed_pc=0x0c089cb4u; return 0; }
r[14]=0x00000007u;
goto P_0c089cb6;
P_0c089cb6: /* original 2e09, guest PC 0x0c089cb6 */
if(!s->budget--) { s->failed_pc=0x0c089cb6u; return 0; }
r[14]&=r[0];
goto P_0c089cb8;
P_0c089cb8: /* original e030, guest PC 0x0c089cb8 */
if(!s->budget--) { s->failed_pc=0x0c089cb8u; return 0; }
r[0]=0x00000030u;
goto P_0c089cba;
P_0c089cba: /* original 0de4, guest PC 0x0c089cba */
if(!s->budget--) { s->failed_pc=0x0c089cbau; return 0; }
write(ram,r[13]+r[0],r[14],1);
goto P_0c089cbc;
P_0c089cbc: /* original e038, guest PC 0x0c089cbc */
if(!s->budget--) { s->failed_pc=0x0c089cbcu; return 0; }
r[0]=0x00000038u;
goto P_0c089cbe;
P_0c089cbe: /* original 03dd, guest PC 0x0c089cbe */
if(!s->budget--) { s->failed_pc=0x0c089cbeu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[13]+r[0],2);
goto P_0c089cc0;
P_0c089cc0: /* original c71d, guest PC 0x0c089cc0 */
if(!s->budget--) { s->failed_pc=0x0c089cc0u; return 0; }
r[0]=code_base|0x00089d38u;
goto P_0c089cc2;
P_0c089cc2: /* original 2c32, guest PC 0x0c089cc2 */
if(!s->budget--) { s->failed_pc=0x0c089cc2u; return 0; }
write(ram,r[12],r[3],4);
goto P_0c089cc4;
P_0c089cc4: /* original e301, guest PC 0x0c089cc4 */
if(!s->budget--) { s->failed_pc=0x0c089cc4u; return 0; }
r[3]=0x00000001u;
goto P_0c089cc6;
P_0c089cc6: /* original f48d, guest PC 0x0c089cc6 */
if(!s->budget--) { s->failed_pc=0x0c089cc6u; return 0; }
fr[4]=0;
goto P_0c089cc8;
P_0c089cc8: /* original 23e8, guest PC 0x0c089cc8 */
if(!s->budget--) { s->failed_pc=0x0c089cc8u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[14])==0)!=0);
goto P_0c089cca;
P_0c089cca: /* original fb4a, guest PC 0x0c089cca */
if(!s->budget--) { s->failed_pc=0x0c089ccau; return 0; }
vf3_matrix_store(s,ram,4,r[11]);
goto P_0c089ccc;
P_0c089ccc: /* original f308, guest PC 0x0c089ccc */
if(!s->budget--) { s->failed_pc=0x0c089cccu; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c089cce;
P_0c089cce: /* original fa3a, guest PC 0x0c089cce */
if(!s->budget--) { s->failed_pc=0x0c089cceu; return 0; }
vf3_matrix_store(s,ram,3,r[10]);
goto P_0c089cd0;
P_0c089cd0: /* original f3b8, guest PC 0x0c089cd0 */
if(!s->budget--) { s->failed_pc=0x0c089cd0u; return 0; }
vf3_matrix_load(s,ram,3,r[11]);
goto P_0c089cd2;
P_0c089cd2: /* original 8d19, guest PC 0x0c089cd2 */
if(!s->budget--) { s->failed_pc=0x0c089cd2u; return 0; }
cond=r[17]&1u;
vf3_matrix_store(s,ram,3,r[9]);
if(cond) { goto P_0c089d08; }
goto P_0c089cd6;
P_0c089cd4: /* original f93a, guest PC 0x0c089cd4 */
if(!s->budget--) { s->failed_pc=0x0c089cd4u; return 0; }
vf3_matrix_store(s,ram,3,r[9]);
goto P_0c089cd6;
P_0c089cd6: /* original 60e3, guest PC 0x0c089cd6 */
if(!s->budget--) { s->failed_pc=0x0c089cd6u; return 0; }
r[0]=r[14];
goto P_0c089cd8;
P_0c089cd8: /* original 8803, guest PC 0x0c089cd8 */
if(!s->budget--) { s->failed_pc=0x0c089cd8u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000003u)!=0);
goto P_0c089cda;
P_0c089cda: /* original 891b, guest PC 0x0c089cda */
if(!s->budget--) { s->failed_pc=0x0c089cdau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c089d14; }
goto P_0c089cdc;
P_0c089cdc: /* original e028, guest PC 0x0c089cdc */
if(!s->budget--) { s->failed_pc=0x0c089cdcu; return 0; }
r[0]=0x00000028u;
goto P_0c089cde;
P_0c089cde: /* original 6693, guest PC 0x0c089cde */
if(!s->budget--) { s->failed_pc=0x0c089cdeu; return 0; }
r[6]=r[9];
goto P_0c089ce0;
P_0c089ce0: /* original 02dd, guest PC 0x0c089ce0 */
if(!s->budget--) { s->failed_pc=0x0c089ce0u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,r[13]+r[0],2);
goto P_0c089ce2;
P_0c089ce2: /* original c716, guest PC 0x0c089ce2 */
if(!s->budget--) { s->failed_pc=0x0c089ce2u; return 0; }
r[0]=code_base|0x00089d3cu;
goto P_0c089ce4;
P_0c089ce4: /* original e300, guest PC 0x0c089ce4 */
if(!s->budget--) { s->failed_pc=0x0c089ce4u; return 0; }
r[3]=0x00000000u;
goto P_0c089ce6;
P_0c089ce6: /* original 65f3, guest PC 0x0c089ce6 */
if(!s->budget--) { s->failed_pc=0x0c089ce6u; return 0; }
r[5]=r[15];
goto P_0c089ce8;
P_0c089ce8: /* original 2c22, guest PC 0x0c089ce8 */
if(!s->budget--) { s->failed_pc=0x0c089ce8u; return 0; }
write(ram,r[12],r[2],4);
goto P_0c089cea;
P_0c089cea: /* original 1f31, guest PC 0x0c089cea */
if(!s->budget--) { s->failed_pc=0x0c089ceau; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c089cec;
P_0c089cec: /* original f308, guest PC 0x0c089cec */
if(!s->budget--) { s->failed_pc=0x0c089cecu; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c089cee;
P_0c089cee: /* original c714, guest PC 0x0c089cee */
if(!s->budget--) { s->failed_pc=0x0c089ceeu; return 0; }
r[0]=code_base|0x00089d40u;
goto P_0c089cf0;
P_0c089cf0: /* original f93a, guest PC 0x0c089cf0 */
if(!s->budget--) { s->failed_pc=0x0c089cf0u; return 0; }
vf3_matrix_store(s,ram,3,r[9]);
goto P_0c089cf2;
P_0c089cf2: /* original ff4a, guest PC 0x0c089cf2 */
if(!s->budget--) { s->failed_pc=0x0c089cf2u; return 0; }
vf3_matrix_store(s,ram,4,r[15]);
goto P_0c089cf4;
P_0c089cf4: /* original f308, guest PC 0x0c089cf4 */
if(!s->budget--) { s->failed_pc=0x0c089cf4u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c089cf6;
P_0c089cf6: /* original fa3a, guest PC 0x0c089cf6 */
if(!s->budget--) { s->failed_pc=0x0c089cf6u; return 0; }
vf3_matrix_store(s,ram,3,r[10]);
goto P_0c089cf8;
P_0c089cf8: /* original d312, guest PC 0x0c089cf8 */
if(!s->budget--) { s->failed_pc=0x0c089cf8u; return 0; }
r[3]=read(ram,0x0c089d44u,4);
goto P_0c089cfa;
P_0c089cfa: /* original 430b, guest PC 0x0c089cfa */
if(!s->budget--) { s->failed_pc=0x0c089cfau; return 0; }
target=r[3];
r[16]=code_base|0x0c089cfeu;
tmp=read(ram,r[12],4);
r[4]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c089cfeu) { target=s->pc; goto dispatch; }
goto P_0c089cfe;
P_0c089cfc: /* original 64c2, guest PC 0x0c089cfc */
if(!s->budget--) { s->failed_pc=0x0c089cfcu; return 0; }
tmp=read(ram,r[12],4);
r[4]=tmp;
goto P_0c089cfe;
P_0c089cfe: /* original f3f8, guest PC 0x0c089cfe */
if(!s->budget--) { s->failed_pc=0x0c089cfeu; return 0; }
vf3_matrix_load(s,ram,3,r[15]);
goto P_0c089d00;
P_0c089d00: /* original fb3a, guest PC 0x0c089d00 */
if(!s->budget--) { s->failed_pc=0x0c089d00u; return 0; }
vf3_matrix_store(s,ram,3,r[11]);
goto P_0c089d02;
P_0c089d02: /* original 53f1, guest PC 0x0c089d02 */
if(!s->budget--) { s->failed_pc=0x0c089d02u; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c089d04;
P_0c089d04: /* original a006, guest PC 0x0c089d04 */
if(!s->budget--) { s->failed_pc=0x0c089d04u; return 0; }
write(ram,r[12],r[3],4);
goto P_0c089d14;
P_0c089d06: /* original 2c32, guest PC 0x0c089d06 */
if(!s->budget--) { s->failed_pc=0x0c089d06u; return 0; }
write(ram,r[12],r[3],4);
goto P_0c089d08;
P_0c089d08: /* original 60e3, guest PC 0x0c089d08 */
if(!s->budget--) { s->failed_pc=0x0c089d08u; return 0; }
r[0]=r[14];
goto P_0c089d0a;
P_0c089d0a: /* original 8802, guest PC 0x0c089d0a */
if(!s->budget--) { s->failed_pc=0x0c089d0au; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c089d0c;
P_0c089d0c: /* original 8b02, guest PC 0x0c089d0c */
if(!s->budget--) { s->failed_pc=0x0c089d0cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c089d14; }
goto P_0c089d0e;
P_0c089d0e: /* original c70e, guest PC 0x0c089d0e */
if(!s->budget--) { s->failed_pc=0x0c089d0eu; return 0; }
r[0]=code_base|0x00089d48u;
goto P_0c089d10;
P_0c089d10: /* original f308, guest PC 0x0c089d10 */
if(!s->budget--) { s->failed_pc=0x0c089d10u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c089d12;
P_0c089d12: /* original fa3a, guest PC 0x0c089d12 */
if(!s->budget--) { s->failed_pc=0x0c089d12u; return 0; }
vf3_matrix_store(s,ram,3,r[10]);
goto P_0c089d14;
P_0c089d14: /* original 7f08, guest PC 0x0c089d14 */
if(!s->budget--) { s->failed_pc=0x0c089d14u; return 0; }
r[15]+=0x00000008u;
goto P_0c089d16;
P_0c089d16: /* original 60e3, guest PC 0x0c089d16 */
if(!s->budget--) { s->failed_pc=0x0c089d16u; return 0; }
r[0]=r[14];
goto P_0c089d18;
P_0c089d18: /* original 4f26, guest PC 0x0c089d18 */
if(!s->budget--) { s->failed_pc=0x0c089d18u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c089d1a;
P_0c089d1a: /* original 69f6, guest PC 0x0c089d1a */
if(!s->budget--) { s->failed_pc=0x0c089d1au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c089d1c;
P_0c089d1c: /* original 6af6, guest PC 0x0c089d1c */
if(!s->budget--) { s->failed_pc=0x0c089d1cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c089d1e;
P_0c089d1e: /* original 6bf6, guest PC 0x0c089d1e */
if(!s->budget--) { s->failed_pc=0x0c089d1eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c089d20;
P_0c089d20: /* original 6cf6, guest PC 0x0c089d20 */
if(!s->budget--) { s->failed_pc=0x0c089d20u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c089d22;
P_0c089d22: /* original 6df6, guest PC 0x0c089d22 */
if(!s->budget--) { s->failed_pc=0x0c089d22u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c089d24;
P_0c089d24: /* original 000b, guest PC 0x0c089d24 */
if(!s->budget--) { s->failed_pc=0x0c089d24u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c089d26: /* original 6ef6, guest PC 0x0c089d26 */
if(!s->budget--) { s->failed_pc=0x0c089d26u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c089d28u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c089d28u; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
