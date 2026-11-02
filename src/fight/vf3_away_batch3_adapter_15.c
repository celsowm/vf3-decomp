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
int vf3_away_batch3_adapter_15(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c043eb8u: goto P_0c043eb8;
case 0x0c043ebau: goto P_0c043eba;
case 0x0c043ebcu: goto P_0c043ebc;
case 0x0c043ebeu: goto P_0c043ebe;
case 0x0c043ec0u: goto P_0c043ec0;
case 0x0c043ec2u: goto P_0c043ec2;
case 0x0c043ec4u: goto P_0c043ec4;
case 0x0c043ec6u: goto P_0c043ec6;
case 0x0c043ec8u: goto P_0c043ec8;
case 0x0c043ecau: goto P_0c043eca;
case 0x0c043eccu: goto P_0c043ecc;
case 0x0c043eceu: goto P_0c043ece;
case 0x0c043ed0u: goto P_0c043ed0;
case 0x0c043ed2u: goto P_0c043ed2;
case 0x0c043ed4u: goto P_0c043ed4;
case 0x0c043ed6u: goto P_0c043ed6;
case 0x0c043ed8u: goto P_0c043ed8;
case 0x0c043ee8u: goto P_0c043ee8;
case 0x0c043eeau: goto P_0c043eea;
case 0x0c043eecu: goto P_0c043eec;
case 0x0c044a74u: goto P_0c044a74;
case 0x0c044a76u: goto P_0c044a76;
case 0x0c044a78u: goto P_0c044a78;
case 0x0c044a7au: goto P_0c044a7a;
case 0x0c044a7cu: goto P_0c044a7c;
case 0x0c044a7eu: goto P_0c044a7e;
case 0x0c044a80u: goto P_0c044a80;
case 0x0c044a82u: goto P_0c044a82;
case 0x0c044a84u: goto P_0c044a84;
case 0x0c044a86u: goto P_0c044a86;
case 0x0c044a88u: goto P_0c044a88;
case 0x0c044a8au: goto P_0c044a8a;
case 0x0c044a8cu: goto P_0c044a8c;
case 0x0c044a8eu: goto P_0c044a8e;
case 0x0c044a90u: goto P_0c044a90;
case 0x0c044a92u: goto P_0c044a92;
case 0x0c044a94u: goto P_0c044a94;
case 0x0c044a96u: goto P_0c044a96;
case 0x0c044a98u: goto P_0c044a98;
case 0x0c044a9au: goto P_0c044a9a;
case 0x0c044a9cu: goto P_0c044a9c;
case 0x0c044a9eu: goto P_0c044a9e;
case 0x0c044aa0u: goto P_0c044aa0;
case 0x0c044aa2u: goto P_0c044aa2;
case 0x0c044aa4u: goto P_0c044aa4;
case 0x0c044aa6u: goto P_0c044aa6;
case 0x0c044aa8u: goto P_0c044aa8;
case 0x0c044aaau: goto P_0c044aaa;
case 0x0c044aacu: goto P_0c044aac;
case 0x0c044aaeu: goto P_0c044aae;
case 0x0c044ab0u: goto P_0c044ab0;
case 0x0c044ab2u: goto P_0c044ab2;
case 0x0c044ab4u: goto P_0c044ab4;
case 0x0c044ab6u: goto P_0c044ab6;
case 0x0c044ab8u: goto P_0c044ab8;
case 0x0c044abau: goto P_0c044aba;
case 0x0c044abcu: goto P_0c044abc;
case 0x0c044abeu: goto P_0c044abe;
case 0x0c044ac0u: goto P_0c044ac0;
case 0x0c044ac2u: goto P_0c044ac2;
case 0x0c044ac4u: goto P_0c044ac4;
case 0x0c044ac6u: goto P_0c044ac6;
case 0x0c044ac8u: goto P_0c044ac8;
case 0x0c044acau: goto P_0c044aca;
case 0x0c044accu: goto P_0c044acc;
case 0x0c044aceu: goto P_0c044ace;
case 0x0c044ad0u: goto P_0c044ad0;
case 0x0c044ad2u: goto P_0c044ad2;
case 0x0c044ad4u: goto P_0c044ad4;
case 0x0c044ad6u: goto P_0c044ad6;
case 0x0c044ad8u: goto P_0c044ad8;
case 0x0c044adau: goto P_0c044ada;
case 0x0c044adcu: goto P_0c044adc;
case 0x0c044adeu: goto P_0c044ade;
case 0x0c044ae0u: goto P_0c044ae0;
case 0x0c044ae2u: goto P_0c044ae2;
case 0x0c044ae4u: goto P_0c044ae4;
case 0x0c044ae6u: goto P_0c044ae6;
case 0x0c044ae8u: goto P_0c044ae8;
case 0x0c044aeau: goto P_0c044aea;
case 0x0c044aecu: goto P_0c044aec;
case 0x0c044aeeu: goto P_0c044aee;
case 0x0c044af0u: goto P_0c044af0;
case 0x0c044af2u: goto P_0c044af2;
case 0x0c044af4u: goto P_0c044af4;
case 0x0c044af6u: goto P_0c044af6;
case 0x0c044af8u: goto P_0c044af8;
case 0x0c044afau: goto P_0c044afa;
case 0x0c044afcu: goto P_0c044afc;
case 0x0c044afeu: goto P_0c044afe;
case 0x0c044b00u: goto P_0c044b00;
case 0x0c044b02u: goto P_0c044b02;
case 0x0c044b04u: goto P_0c044b04;
case 0x0c044b06u: goto P_0c044b06;
case 0x0c044b08u: goto P_0c044b08;
case 0x0c044b0au: goto P_0c044b0a;
case 0x0c044b0cu: goto P_0c044b0c;
case 0x0c044b0eu: goto P_0c044b0e;
case 0x0c044b10u: goto P_0c044b10;
case 0x0c044b12u: goto P_0c044b12;
case 0x0c044b14u: goto P_0c044b14;
case 0x0c044b16u: goto P_0c044b16;
case 0x0c044b18u: goto P_0c044b18;
case 0x0c044b1au: goto P_0c044b1a;
case 0x0c044b1cu: goto P_0c044b1c;
case 0x0c044b1eu: goto P_0c044b1e;
case 0x0c044b20u: goto P_0c044b20;
case 0x0c044b22u: goto P_0c044b22;
case 0x0c044b24u: goto P_0c044b24;
case 0x0c044b26u: goto P_0c044b26;
case 0x0c044b28u: goto P_0c044b28;
case 0x0c044b2au: goto P_0c044b2a;
case 0x0c044b2cu: goto P_0c044b2c;
case 0x0c044b2eu: goto P_0c044b2e;
case 0x0c044b30u: goto P_0c044b30;
case 0x0c044b32u: goto P_0c044b32;
case 0x0c044b34u: goto P_0c044b34;
case 0x0c044b36u: goto P_0c044b36;
case 0x0c044b38u: goto P_0c044b38;
case 0x0c044b3au: goto P_0c044b3a;
case 0x0c044b3cu: goto P_0c044b3c;
case 0x0c044b3eu: goto P_0c044b3e;
case 0x0c044b40u: goto P_0c044b40;
case 0x0c044b42u: goto P_0c044b42;
case 0x0c044b44u: goto P_0c044b44;
case 0x0c044b46u: goto P_0c044b46;
case 0x0c044b48u: goto P_0c044b48;
case 0x0c044b4au: goto P_0c044b4a;
case 0x0c044b4cu: goto P_0c044b4c;
case 0x0c044b4eu: goto P_0c044b4e;
case 0x0c044b50u: goto P_0c044b50;
case 0x0c044b52u: goto P_0c044b52;
case 0x0c044b54u: goto P_0c044b54;
case 0x0c044b56u: goto P_0c044b56;
case 0x0c044b58u: goto P_0c044b58;
case 0x0c044b5au: goto P_0c044b5a;
case 0x0c044b5cu: goto P_0c044b5c;
case 0x0c044b5eu: goto P_0c044b5e;
case 0x0c044b60u: goto P_0c044b60;
case 0x0c044b62u: goto P_0c044b62;
case 0x0c044b64u: goto P_0c044b64;
case 0x0c044b66u: goto P_0c044b66;
case 0x0c044b68u: goto P_0c044b68;
case 0x0c044b6au: goto P_0c044b6a;
case 0x0c044b6cu: goto P_0c044b6c;
case 0x0c044b6eu: goto P_0c044b6e;
case 0x0c044b70u: goto P_0c044b70;
case 0x0c044b72u: goto P_0c044b72;
case 0x0c044b74u: goto P_0c044b74;
case 0x0c044b76u: goto P_0c044b76;
case 0x0c044b78u: goto P_0c044b78;
case 0x0c044b7au: goto P_0c044b7a;
case 0x0c044b7cu: goto P_0c044b7c;
case 0x0c044b7eu: goto P_0c044b7e;
case 0x0c044b80u: goto P_0c044b80;
case 0x0c044b82u: goto P_0c044b82;
case 0x0c044b84u: goto P_0c044b84;
case 0x0c044b86u: goto P_0c044b86;
case 0x0c044b88u: goto P_0c044b88;
case 0x0c044b8au: goto P_0c044b8a;
case 0x0c044b8cu: goto P_0c044b8c;
case 0x0c044b8eu: goto P_0c044b8e;
case 0x0c044b90u: goto P_0c044b90;
case 0x0c044b92u: goto P_0c044b92;
case 0x0c044b94u: goto P_0c044b94;
case 0x0c044b96u: goto P_0c044b96;
case 0x0c044b98u: goto P_0c044b98;
case 0x0c044b9au: goto P_0c044b9a;
case 0x0c044b9cu: goto P_0c044b9c;
case 0x0c044b9eu: goto P_0c044b9e;
case 0x0c044ba0u: goto P_0c044ba0;
case 0x0c044ba2u: goto P_0c044ba2;
case 0x0c044ba4u: goto P_0c044ba4;
case 0x0c044ba6u: goto P_0c044ba6;
case 0x0c044ba8u: goto P_0c044ba8;
case 0x0c044baau: goto P_0c044baa;
case 0x0c044bacu: goto P_0c044bac;
case 0x0c044baeu: goto P_0c044bae;
case 0x0c044bb0u: goto P_0c044bb0;
case 0x0c044bb2u: goto P_0c044bb2;
case 0x0c044bb4u: goto P_0c044bb4;
case 0x0c044bb6u: goto P_0c044bb6;
case 0x0c044bb8u: goto P_0c044bb8;
case 0x0c044bbau: goto P_0c044bba;
case 0x0c044bbcu: goto P_0c044bbc;
case 0x0c044bbeu: goto P_0c044bbe;
case 0x0c044bc0u: goto P_0c044bc0;
case 0x0c044bc2u: goto P_0c044bc2;
case 0x0c044bc4u: goto P_0c044bc4;
case 0x0c044bc6u: goto P_0c044bc6;
case 0x0c044bc8u: goto P_0c044bc8;
case 0x0c044bcau: goto P_0c044bca;
case 0x0c044bccu: goto P_0c044bcc;
case 0x0c044bceu: goto P_0c044bce;
case 0x0c044bd0u: goto P_0c044bd0;
case 0x0c044bd2u: goto P_0c044bd2;
case 0x0c044bd4u: goto P_0c044bd4;
case 0x0c044bd6u: goto P_0c044bd6;
case 0x0c044bd8u: goto P_0c044bd8;
case 0x0c044bdau: goto P_0c044bda;
case 0x0c044bdcu: goto P_0c044bdc;
case 0x0c044bdeu: goto P_0c044bde;
case 0x0c044be0u: goto P_0c044be0;
case 0x0c044be2u: goto P_0c044be2;
case 0x0c044be4u: goto P_0c044be4;
case 0x0c044be6u: goto P_0c044be6;
case 0x0c044be8u: goto P_0c044be8;
case 0x0c044c28u: goto P_0c044c28;
case 0x0c044c2au: goto P_0c044c2a;
case 0x0c044c2cu: goto P_0c044c2c;
case 0x0c044c2eu: goto P_0c044c2e;
case 0x0c044c30u: goto P_0c044c30;
case 0x0c044c32u: goto P_0c044c32;
case 0x0c044c34u: goto P_0c044c34;
case 0x0c044c36u: goto P_0c044c36;
case 0x0c044c38u: goto P_0c044c38;
case 0x0c044c3au: goto P_0c044c3a;
case 0x0c044c3cu: goto P_0c044c3c;
case 0x0c044c3eu: goto P_0c044c3e;
case 0x0c044c40u: goto P_0c044c40;
case 0x0c044c42u: goto P_0c044c42;
case 0x0c044c44u: goto P_0c044c44;
case 0x0c044c46u: goto P_0c044c46;
case 0x0c044c48u: goto P_0c044c48;
case 0x0c044c4au: goto P_0c044c4a;
case 0x0c044c4cu: goto P_0c044c4c;
case 0x0c044c4eu: goto P_0c044c4e;
case 0x0c044c50u: goto P_0c044c50;
case 0x0c044c52u: goto P_0c044c52;
case 0x0c044c54u: goto P_0c044c54;
case 0x0c044c56u: goto P_0c044c56;
case 0x0c044c58u: goto P_0c044c58;
case 0x0c044c5au: goto P_0c044c5a;
case 0x0c044c5cu: goto P_0c044c5c;
case 0x0c044c5eu: goto P_0c044c5e;
case 0x0c044c60u: goto P_0c044c60;
case 0x0c044c62u: goto P_0c044c62;
case 0x0c044c64u: goto P_0c044c64;
case 0x0c044c66u: goto P_0c044c66;
case 0x0c044c68u: goto P_0c044c68;
case 0x0c044c6au: goto P_0c044c6a;
case 0x0c044c6cu: goto P_0c044c6c;
case 0x0c044c6eu: goto P_0c044c6e;
case 0x0c044c70u: goto P_0c044c70;
case 0x0c044c72u: goto P_0c044c72;
case 0x0c044c74u: goto P_0c044c74;
case 0x0c044c76u: goto P_0c044c76;
case 0x0c044c78u: goto P_0c044c78;
case 0x0c044c7au: goto P_0c044c7a;
case 0x0c044c7cu: goto P_0c044c7c;
case 0x0c044c7eu: goto P_0c044c7e;
case 0x0c044c80u: goto P_0c044c80;
case 0x0c044c82u: goto P_0c044c82;
case 0x0c044c84u: goto P_0c044c84;
case 0x0c044c86u: goto P_0c044c86;
case 0x0c044c88u: goto P_0c044c88;
case 0x0c044c8au: goto P_0c044c8a;
case 0x0c044c8cu: goto P_0c044c8c;
case 0x0c044c8eu: goto P_0c044c8e;
case 0x0c044c90u: goto P_0c044c90;
case 0x0c044c92u: goto P_0c044c92;
case 0x0c044c94u: goto P_0c044c94;
case 0x0c044c96u: goto P_0c044c96;
case 0x0c044c98u: goto P_0c044c98;
case 0x0c044c9au: goto P_0c044c9a;
case 0x0c044c9cu: goto P_0c044c9c;
case 0x0c044c9eu: goto P_0c044c9e;
case 0x0c044ca0u: goto P_0c044ca0;
case 0x0c044ca2u: goto P_0c044ca2;
case 0x0c044ca4u: goto P_0c044ca4;
case 0x0c044ca6u: goto P_0c044ca6;
case 0x0c044ca8u: goto P_0c044ca8;
case 0x0c044caau: goto P_0c044caa;
case 0x0c044cacu: goto P_0c044cac;
case 0x0c044caeu: goto P_0c044cae;
case 0x0c044cb0u: goto P_0c044cb0;
case 0x0c044cb2u: goto P_0c044cb2;
case 0x0c044cb4u: goto P_0c044cb4;
case 0x0c044cb6u: goto P_0c044cb6;
case 0x0c044cb8u: goto P_0c044cb8;
case 0x0c044cbau: goto P_0c044cba;
case 0x0c044cbcu: goto P_0c044cbc;
case 0x0c044cbeu: goto P_0c044cbe;
default: return vf3_matrix_family(target,s,ram);
}
P_0c043eb8: /* original 6043, guest PC 0x0c043eb8 */
if(!s->budget--) { s->failed_pc=0x0c043eb8u; return 0; }
r[0]=r[4];
goto P_0c043eba;
P_0c043eba: /* original 4000, guest PC 0x0c043eba */
if(!s->budget--) { s->failed_pc=0x0c043ebau; return 0; }
r[17]=(r[17]&~1u)|((r[0]>>31)!=0);
r[0]<<=1;
goto P_0c043ebc;
P_0c043ebc: /* original 6343, guest PC 0x0c043ebc */
if(!s->budget--) { s->failed_pc=0x0c043ebcu; return 0; }
r[3]=r[4];
goto P_0c043ebe;
P_0c043ebe: /* original 303c, guest PC 0x0c043ebe */
if(!s->budget--) { s->failed_pc=0x0c043ebeu; return 0; }
r[0]+=r[3];
goto P_0c043ec0;
P_0c043ec0: /* original 4008, guest PC 0x0c043ec0 */
if(!s->budget--) { s->failed_pc=0x0c043ec0u; return 0; }
r[0]<<=2;
goto P_0c043ec2;
P_0c043ec2: /* original d218, guest PC 0x0c043ec2 */
if(!s->budget--) { s->failed_pc=0x0c043ec2u; return 0; }
r[2]=read(ram,0x0c043f24u,4);
goto P_0c043ec4;
P_0c043ec4: /* original 4000, guest PC 0x0c043ec4 */
if(!s->budget--) { s->failed_pc=0x0c043ec4u; return 0; }
r[17]=(r[17]&~1u)|((r[0]>>31)!=0);
r[0]<<=1;
goto P_0c043ec6;
P_0c043ec6: /* original 600f, guest PC 0x0c043ec6 */
if(!s->budget--) { s->failed_pc=0x0c043ec6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)r[0];
goto P_0c043ec8;
P_0c043ec8: /* original 000b, guest PC 0x0c043ec8 */
if(!s->budget--) { s->failed_pc=0x0c043ec8u; return 0; }
target=r[16];
r[0]+=r[2];
s->pc=target; return ram->oob==0;
P_0c043eca: /* original 302c, guest PC 0x0c043eca */
if(!s->budget--) { s->failed_pc=0x0c043ecau; return 0; }
r[0]+=r[2];
goto P_0c043ecc;
P_0c043ecc: /* original 4f22, guest PC 0x0c043ecc */
if(!s->budget--) { s->failed_pc=0x0c043eccu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c043ece;
P_0c043ece: /* original d317, guest PC 0x0c043ece */
if(!s->budget--) { s->failed_pc=0x0c043eceu; return 0; }
r[3]=read(ram,0x0c043f2cu,4);
goto P_0c043ed0;
P_0c043ed0: /* original 430b, guest PC 0x0c043ed0 */
if(!s->budget--) { s->failed_pc=0x0c043ed0u; return 0; }
target=r[3];
r[16]=code_base|0x0c043ed4u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c043ed4u) { target=s->pc; goto dispatch; }
goto P_0c043ed4;
P_0c043ed2: /* original 0009, guest PC 0x0c043ed2 */
if(!s->budget--) { s->failed_pc=0x0c043ed2u; return 0; }
goto P_0c043ed4;
P_0c043ed4: /* original 4f26, guest PC 0x0c043ed4 */
if(!s->budget--) { s->failed_pc=0x0c043ed4u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c043ed6;
P_0c043ed6: /* original 000b, guest PC 0x0c043ed6 */
if(!s->budget--) { s->failed_pc=0x0c043ed6u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c043ed8: /* original 0009, guest PC 0x0c043ed8 */
if(!s->budget--) { s->failed_pc=0x0c043ed8u; return 0; }
if(!vf3_matrix_family(0x0c043edau,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c043edau; return 0; } return 1;
P_0c043ee8: /* original d312, guest PC 0x0c043ee8 */
if(!s->budget--) { s->failed_pc=0x0c043ee8u; return 0; }
r[3]=read(ram,0x0c043f34u,4);
goto P_0c043eea;
P_0c043eea: /* original 432b, guest PC 0x0c043eea */
if(!s->budget--) { s->failed_pc=0x0c043eeau; return 0; }
target=r[3];
code_base=target&0xff000000u;
switch(target&0x1fffffffu) {
case 0x0c036610u: return vf3_matrix_family(0x0c036610u,s,ram);
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
P_0c043eec: /* original 0009, guest PC 0x0c043eec */
if(!s->budget--) { s->failed_pc=0x0c043eecu; return 0; }
if(!vf3_matrix_family(0x0c043eeeu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c043eeeu; return 0; } return 1;
P_0c044a74: /* original 2fe6, guest PC 0x0c044a74 */
if(!s->budget--) { s->failed_pc=0x0c044a74u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c044a76;
P_0c044a76: /* original 2fd6, guest PC 0x0c044a76 */
if(!s->budget--) { s->failed_pc=0x0c044a76u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c044a78;
P_0c044a78: /* original ed00, guest PC 0x0c044a78 */
if(!s->budget--) { s->failed_pc=0x0c044a78u; return 0; }
r[13]=0x00000000u;
goto P_0c044a7a;
P_0c044a7a: /* original 2fc6, guest PC 0x0c044a7a */
if(!s->budget--) { s->failed_pc=0x0c044a7au; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c044a7c;
P_0c044a7c: /* original 2fb6, guest PC 0x0c044a7c */
if(!s->budget--) { s->failed_pc=0x0c044a7cu; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c044a7e;
P_0c044a7e: /* original de65, guest PC 0x0c044a7e */
if(!s->budget--) { s->failed_pc=0x0c044a7eu; return 0; }
r[14]=read(ram,0x0c044c14u,4);
goto P_0c044a80;
P_0c044a80: /* original 90b3, guest PC 0x0c044a80 */
if(!s->budget--) { s->failed_pc=0x0c044a80u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c044beau,2);
goto P_0c044a82;
P_0c044a82: /* original 63e2, guest PC 0x0c044a82 */
if(!s->budget--) { s->failed_pc=0x0c044a82u; return 0; }
tmp=read(ram,r[14],4);
r[3]=tmp;
goto P_0c044a84;
P_0c044a84: /* original 4f22, guest PC 0x0c044a84 */
if(!s->budget--) { s->failed_pc=0x0c044a84u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c044a86;
P_0c044a86: /* original 03d6, guest PC 0x0c044a86 */
if(!s->budget--) { s->failed_pc=0x0c044a86u; return 0; }
write(ram,r[3]+r[0],r[13],4);
goto P_0c044a88;
P_0c044a88: /* original 7004, guest PC 0x0c044a88 */
if(!s->budget--) { s->failed_pc=0x0c044a88u; return 0; }
r[0]+=0x00000004u;
goto P_0c044a8a;
P_0c044a8a: /* original 63e2, guest PC 0x0c044a8a */
if(!s->budget--) { s->failed_pc=0x0c044a8au; return 0; }
tmp=read(ram,r[14],4);
r[3]=tmp;
goto P_0c044a8c;
P_0c044a8c: /* original 4f12, guest PC 0x0c044a8c */
if(!s->budget--) { s->failed_pc=0x0c044a8cu; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c044a8e;
P_0c044a8e: /* original 03d6, guest PC 0x0c044a8e */
if(!s->budget--) { s->failed_pc=0x0c044a8eu; return 0; }
write(ram,r[3]+r[0],r[13],4);
goto P_0c044a90;
P_0c044a90: /* original 63e2, guest PC 0x0c044a90 */
if(!s->budget--) { s->failed_pc=0x0c044a90u; return 0; }
tmp=read(ram,r[14],4);
r[3]=tmp;
goto P_0c044a92;
P_0c044a92: /* original 90ab, guest PC 0x0c044a92 */
if(!s->budget--) { s->failed_pc=0x0c044a92u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c044becu,2);
goto P_0c044a94;
P_0c044a94: /* original 6233, guest PC 0x0c044a94 */
if(!s->budget--) { s->failed_pc=0x0c044a94u; return 0; }
r[2]=r[3];
goto P_0c044a96;
P_0c044a96: /* original 012e, guest PC 0x0c044a96 */
if(!s->budget--) { s->failed_pc=0x0c044a96u; return 0; }
r[1]=read(ram,r[2]+r[0],4);
goto P_0c044a98;
P_0c044a98: /* original 7020, guest PC 0x0c044a98 */
if(!s->budget--) { s->failed_pc=0x0c044a98u; return 0; }
r[0]+=0x00000020u;
goto P_0c044a9a;
P_0c044a9a: /* original 0316, guest PC 0x0c044a9a */
if(!s->budget--) { s->failed_pc=0x0c044a9au; return 0; }
write(ram,r[3]+r[0],r[1],4);
goto P_0c044a9c;
P_0c044a9c: /* original 70e0, guest PC 0x0c044a9c */
if(!s->budget--) { s->failed_pc=0x0c044a9cu; return 0; }
r[0]+=0xffffffe0u;
goto P_0c044a9e;
P_0c044a9e: /* original 63e2, guest PC 0x0c044a9e */
if(!s->budget--) { s->failed_pc=0x0c044a9eu; return 0; }
tmp=read(ram,r[14],4);
r[3]=tmp;
goto P_0c044aa0;
P_0c044aa0: /* original 91a5, guest PC 0x0c044aa0 */
if(!s->budget--) { s->failed_pc=0x0c044aa0u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c044beeu,2);
goto P_0c044aa2;
P_0c044aa2: /* original 6233, guest PC 0x0c044aa2 */
if(!s->budget--) { s->failed_pc=0x0c044aa2u; return 0; }
r[2]=r[3];
goto P_0c044aa4;
P_0c044aa4: /* original 022e, guest PC 0x0c044aa4 */
if(!s->budget--) { s->failed_pc=0x0c044aa4u; return 0; }
r[2]=read(ram,r[2]+r[0],4);
goto P_0c044aa6;
P_0c044aa6: /* original 7024, guest PC 0x0c044aa6 */
if(!s->budget--) { s->failed_pc=0x0c044aa6u; return 0; }
r[0]+=0x00000024u;
goto P_0c044aa8;
P_0c044aa8: /* original 321c, guest PC 0x0c044aa8 */
if(!s->budget--) { s->failed_pc=0x0c044aa8u; return 0; }
r[2]+=r[1];
goto P_0c044aaa;
P_0c044aaa: /* original 0326, guest PC 0x0c044aaa */
if(!s->budget--) { s->failed_pc=0x0c044aaau; return 0; }
write(ram,r[3]+r[0],r[2],4);
goto P_0c044aac;
P_0c044aac: /* original 70dc, guest PC 0x0c044aac */
if(!s->budget--) { s->failed_pc=0x0c044aacu; return 0; }
r[0]+=0xffffffdcu;
goto P_0c044aae;
P_0c044aae: /* original 63e2, guest PC 0x0c044aae */
if(!s->budget--) { s->failed_pc=0x0c044aaeu; return 0; }
tmp=read(ram,r[14],4);
r[3]=tmp;
goto P_0c044ab0;
P_0c044ab0: /* original 919e, guest PC 0x0c044ab0 */
if(!s->budget--) { s->failed_pc=0x0c044ab0u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c044bf0u,2);
goto P_0c044ab2;
P_0c044ab2: /* original 6233, guest PC 0x0c044ab2 */
if(!s->budget--) { s->failed_pc=0x0c044ab2u; return 0; }
r[2]=r[3];
goto P_0c044ab4;
P_0c044ab4: /* original 022e, guest PC 0x0c044ab4 */
if(!s->budget--) { s->failed_pc=0x0c044ab4u; return 0; }
r[2]=read(ram,r[2]+r[0],4);
goto P_0c044ab6;
P_0c044ab6: /* original 7038, guest PC 0x0c044ab6 */
if(!s->budget--) { s->failed_pc=0x0c044ab6u; return 0; }
r[0]+=0x00000038u;
goto P_0c044ab8;
P_0c044ab8: /* original 321c, guest PC 0x0c044ab8 */
if(!s->budget--) { s->failed_pc=0x0c044ab8u; return 0; }
r[2]+=r[1];
goto P_0c044aba;
P_0c044aba: /* original 0326, guest PC 0x0c044aba */
if(!s->budget--) { s->failed_pc=0x0c044abau; return 0; }
write(ram,r[3]+r[0],r[2],4);
goto P_0c044abc;
P_0c044abc: /* original 70c8, guest PC 0x0c044abc */
if(!s->budget--) { s->failed_pc=0x0c044abcu; return 0; }
r[0]+=0xffffffc8u;
goto P_0c044abe;
P_0c044abe: /* original 63e2, guest PC 0x0c044abe */
if(!s->budget--) { s->failed_pc=0x0c044abeu; return 0; }
tmp=read(ram,r[14],4);
r[3]=tmp;
goto P_0c044ac0;
P_0c044ac0: /* original 9497, guest PC 0x0c044ac0 */
if(!s->budget--) { s->failed_pc=0x0c044ac0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c044bf2u,2);
goto P_0c044ac2;
P_0c044ac2: /* original 6233, guest PC 0x0c044ac2 */
if(!s->budget--) { s->failed_pc=0x0c044ac2u; return 0; }
r[2]=r[3];
goto P_0c044ac4;
P_0c044ac4: /* original 022e, guest PC 0x0c044ac4 */
if(!s->budget--) { s->failed_pc=0x0c044ac4u; return 0; }
r[2]=read(ram,r[2]+r[0],4);
goto P_0c044ac6;
P_0c044ac6: /* original 9095, guest PC 0x0c044ac6 */
if(!s->budget--) { s->failed_pc=0x0c044ac6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c044bf4u,2);
goto P_0c044ac8;
P_0c044ac8: /* original 324c, guest PC 0x0c044ac8 */
if(!s->budget--) { s->failed_pc=0x0c044ac8u; return 0; }
r[2]+=r[4];
goto P_0c044aca;
P_0c044aca: /* original 0326, guest PC 0x0c044aca */
if(!s->budget--) { s->failed_pc=0x0c044acau; return 0; }
write(ram,r[3]+r[0],r[2],4);
goto P_0c044acc;
P_0c044acc: /* original 7080, guest PC 0x0c044acc */
if(!s->budget--) { s->failed_pc=0x0c044accu; return 0; }
r[0]+=0xffffff80u;
goto P_0c044ace;
P_0c044ace: /* original 63e2, guest PC 0x0c044ace */
if(!s->budget--) { s->failed_pc=0x0c044aceu; return 0; }
tmp=read(ram,r[14],4);
r[3]=tmp;
goto P_0c044ad0;
P_0c044ad0: /* original 9191, guest PC 0x0c044ad0 */
if(!s->budget--) { s->failed_pc=0x0c044ad0u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c044bf6u,2);
goto P_0c044ad2;
P_0c044ad2: /* original 6233, guest PC 0x0c044ad2 */
if(!s->budget--) { s->failed_pc=0x0c044ad2u; return 0; }
r[2]=r[3];
goto P_0c044ad4;
P_0c044ad4: /* original 022e, guest PC 0x0c044ad4 */
if(!s->budget--) { s->failed_pc=0x0c044ad4u; return 0; }
r[2]=read(ram,r[2]+r[0],4);
goto P_0c044ad6;
P_0c044ad6: /* original 908f, guest PC 0x0c044ad6 */
if(!s->budget--) { s->failed_pc=0x0c044ad6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c044bf8u,2);
goto P_0c044ad8;
P_0c044ad8: /* original 321c, guest PC 0x0c044ad8 */
if(!s->budget--) { s->failed_pc=0x0c044ad8u; return 0; }
r[2]+=r[1];
goto P_0c044ada;
P_0c044ada: /* original 0326, guest PC 0x0c044ada */
if(!s->budget--) { s->failed_pc=0x0c044adau; return 0; }
write(ram,r[3]+r[0],r[2],4);
goto P_0c044adc;
P_0c044adc: /* original 63e2, guest PC 0x0c044adc */
if(!s->budget--) { s->failed_pc=0x0c044adcu; return 0; }
tmp=read(ram,r[14],4);
r[3]=tmp;
goto P_0c044ade;
P_0c044ade: /* original 9085, guest PC 0x0c044ade */
if(!s->budget--) { s->failed_pc=0x0c044adeu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c044becu,2);
goto P_0c044ae0;
P_0c044ae0: /* original 6233, guest PC 0x0c044ae0 */
if(!s->budget--) { s->failed_pc=0x0c044ae0u; return 0; }
r[2]=r[3];
goto P_0c044ae2;
P_0c044ae2: /* original 918a, guest PC 0x0c044ae2 */
if(!s->budget--) { s->failed_pc=0x0c044ae2u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c044bfau,2);
goto P_0c044ae4;
P_0c044ae4: /* original 022e, guest PC 0x0c044ae4 */
if(!s->budget--) { s->failed_pc=0x0c044ae4u; return 0; }
r[2]=read(ram,r[2]+r[0],4);
goto P_0c044ae6;
P_0c044ae6: /* original 9089, guest PC 0x0c044ae6 */
if(!s->budget--) { s->failed_pc=0x0c044ae6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c044bfcu,2);
goto P_0c044ae8;
P_0c044ae8: /* original 321c, guest PC 0x0c044ae8 */
if(!s->budget--) { s->failed_pc=0x0c044ae8u; return 0; }
r[2]+=r[1];
goto P_0c044aea;
P_0c044aea: /* original 0326, guest PC 0x0c044aea */
if(!s->budget--) { s->failed_pc=0x0c044aeau; return 0; }
write(ram,r[3]+r[0],r[2],4);
goto P_0c044aec;
P_0c044aec: /* original 63e2, guest PC 0x0c044aec */
if(!s->budget--) { s->failed_pc=0x0c044aecu; return 0; }
tmp=read(ram,r[14],4);
r[3]=tmp;
goto P_0c044aee;
P_0c044aee: /* original 9086, guest PC 0x0c044aee */
if(!s->budget--) { s->failed_pc=0x0c044aeeu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c044bfeu,2);
goto P_0c044af0;
P_0c044af0: /* original 6233, guest PC 0x0c044af0 */
if(!s->budget--) { s->failed_pc=0x0c044af0u; return 0; }
r[2]=r[3];
goto P_0c044af2;
P_0c044af2: /* original 022e, guest PC 0x0c044af2 */
if(!s->budget--) { s->failed_pc=0x0c044af2u; return 0; }
r[2]=read(ram,r[2]+r[0],4);
goto P_0c044af4;
P_0c044af4: /* original 9084, guest PC 0x0c044af4 */
if(!s->budget--) { s->failed_pc=0x0c044af4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c044c00u,2);
goto P_0c044af6;
P_0c044af6: /* original e608, guest PC 0x0c044af6 */
if(!s->budget--) { s->failed_pc=0x0c044af6u; return 0; }
r[6]=0x00000008u;
goto P_0c044af8;
P_0c044af8: /* original 65d3, guest PC 0x0c044af8 */
if(!s->budget--) { s->failed_pc=0x0c044af8u; return 0; }
r[5]=r[13];
goto P_0c044afa;
P_0c044afa: /* original 0326, guest PC 0x0c044afa */
if(!s->budget--) { s->failed_pc=0x0c044afau; return 0; }
write(ram,r[3]+r[0],r[2],4);
goto P_0c044afc;
P_0c044afc: /* original 63e2, guest PC 0x0c044afc */
if(!s->budget--) { s->failed_pc=0x0c044afcu; return 0; }
tmp=read(ram,r[14],4);
r[3]=tmp;
goto P_0c044afe;
P_0c044afe: /* original 907e, guest PC 0x0c044afe */
if(!s->budget--) { s->failed_pc=0x0c044afeu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c044bfeu,2);
goto P_0c044b00;
P_0c044b00: /* original 6233, guest PC 0x0c044b00 */
if(!s->budget--) { s->failed_pc=0x0c044b00u; return 0; }
r[2]=r[3];
goto P_0c044b02;
P_0c044b02: /* original 022e, guest PC 0x0c044b02 */
if(!s->budget--) { s->failed_pc=0x0c044b02u; return 0; }
r[2]=read(ram,r[2]+r[0],4);
goto P_0c044b04;
P_0c044b04: /* original 907d, guest PC 0x0c044b04 */
if(!s->budget--) { s->failed_pc=0x0c044b04u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c044c02u,2);
goto P_0c044b06;
P_0c044b06: /* original 342c, guest PC 0x0c044b06 */
if(!s->budget--) { s->failed_pc=0x0c044b06u; return 0; }
r[4]+=r[2];
goto P_0c044b08;
P_0c044b08: /* original 0346, guest PC 0x0c044b08 */
if(!s->budget--) { s->failed_pc=0x0c044b08u; return 0; }
write(ram,r[3]+r[0],r[4],4);
goto P_0c044b0a;
P_0c044b0a: /* original 70fc, guest PC 0x0c044b0a */
if(!s->budget--) { s->failed_pc=0x0c044b0au; return 0; }
r[0]+=0xfffffffcu;
goto P_0c044b0c;
P_0c044b0c: /* original 63e2, guest PC 0x0c044b0c */
if(!s->budget--) { s->failed_pc=0x0c044b0cu; return 0; }
tmp=read(ram,r[14],4);
r[3]=tmp;
goto P_0c044b0e;
P_0c044b0e: /* original 6233, guest PC 0x0c044b0e */
if(!s->budget--) { s->failed_pc=0x0c044b0eu; return 0; }
r[2]=r[3];
goto P_0c044b10;
P_0c044b10: /* original 022e, guest PC 0x0c044b10 */
if(!s->budget--) { s->failed_pc=0x0c044b10u; return 0; }
r[2]=read(ram,r[2]+r[0],4);
goto P_0c044b12;
P_0c044b12: /* original 9077, guest PC 0x0c044b12 */
if(!s->budget--) { s->failed_pc=0x0c044b12u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c044c04u,2);
goto P_0c044b14;
P_0c044b14: /* original 0326, guest PC 0x0c044b14 */
if(!s->budget--) { s->failed_pc=0x0c044b14u; return 0; }
write(ram,r[3]+r[0],r[2],4);
goto P_0c044b16;
P_0c044b16: /* original 64e2, guest PC 0x0c044b16 */
if(!s->budget--) { s->failed_pc=0x0c044b16u; return 0; }
tmp=read(ram,r[14],4);
r[4]=tmp;
goto P_0c044b18;
P_0c044b18: /* original d33f, guest PC 0x0c044b18 */
if(!s->budget--) { s->failed_pc=0x0c044b18u; return 0; }
r[3]=read(ram,0x0c044c18u,4);
goto P_0c044b1a;
P_0c044b1a: /* original 430b, guest PC 0x0c044b1a */
if(!s->budget--) { s->failed_pc=0x0c044b1au; return 0; }
target=r[3];
r[16]=code_base|0x0c044b1eu;
r[4]+=0x00000004u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c044b1eu) { target=s->pc; goto dispatch; }
goto P_0c044b1e;
P_0c044b1c: /* original 7404, guest PC 0x0c044b1c */
if(!s->budget--) { s->failed_pc=0x0c044b1cu; return 0; }
r[4]+=0x00000004u;
goto P_0c044b1e;
P_0c044b1e: /* original 64e2, guest PC 0x0c044b1e */
if(!s->budget--) { s->failed_pc=0x0c044b1eu; return 0; }
tmp=read(ram,r[14],4);
r[4]=tmp;
goto P_0c044b20;
P_0c044b20: /* original 65d3, guest PC 0x0c044b20 */
if(!s->budget--) { s->failed_pc=0x0c044b20u; return 0; }
r[5]=r[13];
goto P_0c044b22;
P_0c044b22: /* original d33d, guest PC 0x0c044b22 */
if(!s->budget--) { s->failed_pc=0x0c044b22u; return 0; }
r[3]=read(ram,0x0c044c18u,4);
goto P_0c044b24;
P_0c044b24: /* original 966f, guest PC 0x0c044b24 */
if(!s->budget--) { s->failed_pc=0x0c044b24u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c044c06u,2);
goto P_0c044b26;
P_0c044b26: /* original 430b, guest PC 0x0c044b26 */
if(!s->budget--) { s->failed_pc=0x0c044b26u; return 0; }
target=r[3];
r[16]=code_base|0x0c044b2au;
r[4]+=0x00000028u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c044b2au) { target=s->pc; goto dispatch; }
goto P_0c044b2a;
P_0c044b28: /* original 7428, guest PC 0x0c044b28 */
if(!s->budget--) { s->failed_pc=0x0c044b28u; return 0; }
r[4]+=0x00000028u;
goto P_0c044b2a;
P_0c044b2a: /* original 6bd3, guest PC 0x0c044b2a */
if(!s->budget--) { s->failed_pc=0x0c044b2au; return 0; }
r[11]=r[13];
goto P_0c044b2c;
P_0c044b2c: /* original ec18, guest PC 0x0c044b2c */
if(!s->budget--) { s->failed_pc=0x0c044b2cu; return 0; }
r[12]=0x00000018u;
goto P_0c044b2e;
P_0c044b2e: /* original e378, guest PC 0x0c044b2e */
if(!s->budget--) { s->failed_pc=0x0c044b2eu; return 0; }
r[3]=0x00000078u;
goto P_0c044b30;
P_0c044b30: /* original 926a, guest PC 0x0c044b30 */
if(!s->budget--) { s->failed_pc=0x0c044b30u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c044c08u,2);
goto P_0c044b32;
P_0c044b32: /* original 2b3f, guest PC 0x0c044b32 */
if(!s->budget--) { s->failed_pc=0x0c044b32u; return 0; }
r[19]=(uint32_t)((int32_t)(int16_t)r[11]*(int32_t)(int16_t)r[3]);
goto P_0c044b34;
P_0c044b34: /* original 64e2, guest PC 0x0c044b34 */
if(!s->budget--) { s->failed_pc=0x0c044b34u; return 0; }
tmp=read(ram,r[14],4);
r[4]=tmp;
goto P_0c044b36;
P_0c044b36: /* original 342c, guest PC 0x0c044b36 */
if(!s->budget--) { s->failed_pc=0x0c044b36u; return 0; }
r[4]+=r[2];
goto P_0c044b38;
P_0c044b38: /* original 031a, guest PC 0x0c044b38 */
if(!s->budget--) { s->failed_pc=0x0c044b38u; return 0; }
r[3]=r[19];
goto P_0c044b3a;
P_0c044b3a: /* original 633f, guest PC 0x0c044b3a */
if(!s->budget--) { s->failed_pc=0x0c044b3au; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)r[3];
goto P_0c044b3c;
P_0c044b3c: /* original 343c, guest PC 0x0c044b3c */
if(!s->budget--) { s->failed_pc=0x0c044b3cu; return 0; }
r[4]+=r[3];
goto P_0c044b3e;
P_0c044b3e: /* original b713, guest PC 0x0c044b3e */
if(!s->budget--) { s->failed_pc=0x0c044b3eu; return 0; }
target=code_base|0x0c045968u; r[16]=code_base|0x0c044b42u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c044b42u) { target=s->pc; goto dispatch; }
goto P_0c044b42;
P_0c044b40: /* original 0009, guest PC 0x0c044b40 */
if(!s->budget--) { s->failed_pc=0x0c044b40u; return 0; }
goto P_0c044b42;
P_0c044b42: /* original 7b01, guest PC 0x0c044b42 */
if(!s->budget--) { s->failed_pc=0x0c044b42u; return 0; }
r[11]+=0x00000001u;
goto P_0c044b44;
P_0c044b44: /* original 3bc3, guest PC 0x0c044b44 */
if(!s->budget--) { s->failed_pc=0x0c044b44u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[11]>=(int32_t)r[12])!=0);
goto P_0c044b46;
P_0c044b46: /* original 8bf2, guest PC 0x0c044b46 */
if(!s->budget--) { s->failed_pc=0x0c044b46u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c044b2e; }
goto P_0c044b48;
P_0c044b48: /* original 64d3, guest PC 0x0c044b48 */
if(!s->budget--) { s->failed_pc=0x0c044b48u; return 0; }
r[4]=r[13];
goto P_0c044b4a;
P_0c044b4a: /* original 935e, guest PC 0x0c044b4a */
if(!s->budget--) { s->failed_pc=0x0c044b4au; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c044c0au,2);
goto P_0c044b4c;
P_0c044b4c: /* original 60e2, guest PC 0x0c044b4c */
if(!s->budget--) { s->failed_pc=0x0c044b4cu; return 0; }
tmp=read(ram,r[14],4);
r[0]=tmp;
goto P_0c044b4e;
P_0c044b4e: /* original 330c, guest PC 0x0c044b4e */
if(!s->budget--) { s->failed_pc=0x0c044b4eu; return 0; }
r[3]+=r[0];
goto P_0c044b50;
P_0c044b50: /* original 334c, guest PC 0x0c044b50 */
if(!s->budget--) { s->failed_pc=0x0c044b50u; return 0; }
r[3]+=r[4];
goto P_0c044b52;
P_0c044b52: /* original 7401, guest PC 0x0c044b52 */
if(!s->budget--) { s->failed_pc=0x0c044b52u; return 0; }
r[4]+=0x00000001u;
goto P_0c044b54;
P_0c044b54: /* original 34c3, guest PC 0x0c044b54 */
if(!s->budget--) { s->failed_pc=0x0c044b54u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=(int32_t)r[12])!=0);
goto P_0c044b56;
P_0c044b56: /* original 8ff8, guest PC 0x0c044b56 */
if(!s->budget--) { s->failed_pc=0x0c044b56u; return 0; }
cond=r[17]&1u;
write(ram,r[3],r[13],1);
if(!cond) { goto P_0c044b4a; }
goto P_0c044b5a;
P_0c044b58: /* original 23d0, guest PC 0x0c044b58 */
if(!s->budget--) { s->failed_pc=0x0c044b58u; return 0; }
write(ram,r[3],r[13],1);
goto P_0c044b5a;
P_0c044b5a: /* original 9056, guest PC 0x0c044b5a */
if(!s->budget--) { s->failed_pc=0x0c044b5au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c044c0au,2);
goto P_0c044b5c;
P_0c044b5c: /* original e452, guest PC 0x0c044b5c */
if(!s->budget--) { s->failed_pc=0x0c044b5cu; return 0; }
r[4]=0x00000052u;
goto P_0c044b5e;
P_0c044b5e: /* original 63e2, guest PC 0x0c044b5e */
if(!s->budget--) { s->failed_pc=0x0c044b5eu; return 0; }
tmp=read(ram,r[14],4);
r[3]=tmp;
goto P_0c044b60;
P_0c044b60: /* original e245, guest PC 0x0c044b60 */
if(!s->budget--) { s->failed_pc=0x0c044b60u; return 0; }
r[2]=0x00000045u;
goto P_0c044b62;
P_0c044b62: /* original 0344, guest PC 0x0c044b62 */
if(!s->budget--) { s->failed_pc=0x0c044b62u; return 0; }
write(ram,r[3]+r[0],r[4],1);
goto P_0c044b64;
P_0c044b64: /* original 7001, guest PC 0x0c044b64 */
if(!s->budget--) { s->failed_pc=0x0c044b64u; return 0; }
r[0]+=0x00000001u;
goto P_0c044b66;
P_0c044b66: /* original 63e2, guest PC 0x0c044b66 */
if(!s->budget--) { s->failed_pc=0x0c044b66u; return 0; }
tmp=read(ram,r[14],4);
r[3]=tmp;
goto P_0c044b68;
P_0c044b68: /* original 0324, guest PC 0x0c044b68 */
if(!s->budget--) { s->failed_pc=0x0c044b68u; return 0; }
write(ram,r[3]+r[0],r[2],1);
goto P_0c044b6a;
P_0c044b6a: /* original 7005, guest PC 0x0c044b6a */
if(!s->budget--) { s->failed_pc=0x0c044b6au; return 0; }
r[0]+=0x00000005u;
goto P_0c044b6c;
P_0c044b6c: /* original 63e2, guest PC 0x0c044b6c */
if(!s->budget--) { s->failed_pc=0x0c044b6cu; return 0; }
tmp=read(ram,r[14],4);
r[3]=tmp;
goto P_0c044b6e;
P_0c044b6e: /* original 0344, guest PC 0x0c044b6e */
if(!s->budget--) { s->failed_pc=0x0c044b6eu; return 0; }
write(ram,r[3]+r[0],r[4],1);
goto P_0c044b70;
P_0c044b70: /* original 904c, guest PC 0x0c044b70 */
if(!s->budget--) { s->failed_pc=0x0c044b70u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c044c0cu,2);
goto P_0c044b72;
P_0c044b72: /* original d22a, guest PC 0x0c044b72 */
if(!s->budget--) { s->failed_pc=0x0c044b72u; return 0; }
r[2]=read(ram,0x0c044c1cu,4);
goto P_0c044b74;
P_0c044b74: /* original 63e2, guest PC 0x0c044b74 */
if(!s->budget--) { s->failed_pc=0x0c044b74u; return 0; }
tmp=read(ram,r[14],4);
r[3]=tmp;
goto P_0c044b76;
P_0c044b76: /* original 0326, guest PC 0x0c044b76 */
if(!s->budget--) { s->failed_pc=0x0c044b76u; return 0; }
write(ram,r[3]+r[0],r[2],4);
goto P_0c044b78;
P_0c044b78: /* original e201, guest PC 0x0c044b78 */
if(!s->budget--) { s->failed_pc=0x0c044b78u; return 0; }
r[2]=0x00000001u;
goto P_0c044b7a;
P_0c044b7a: /* original 9048, guest PC 0x0c044b7a */
if(!s->budget--) { s->failed_pc=0x0c044b7au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c044c0eu,2);
goto P_0c044b7c;
P_0c044b7c: /* original 63e2, guest PC 0x0c044b7c */
if(!s->budget--) { s->failed_pc=0x0c044b7cu; return 0; }
tmp=read(ram,r[14],4);
r[3]=tmp;
goto P_0c044b7e;
P_0c044b7e: /* original 03d6, guest PC 0x0c044b7e */
if(!s->budget--) { s->failed_pc=0x0c044b7eu; return 0; }
write(ram,r[3]+r[0],r[13],4);
goto P_0c044b80;
P_0c044b80: /* original 70fc, guest PC 0x0c044b80 */
if(!s->budget--) { s->failed_pc=0x0c044b80u; return 0; }
r[0]+=0xfffffffcu;
goto P_0c044b82;
P_0c044b82: /* original 63e2, guest PC 0x0c044b82 */
if(!s->budget--) { s->failed_pc=0x0c044b82u; return 0; }
tmp=read(ram,r[14],4);
r[3]=tmp;
goto P_0c044b84;
P_0c044b84: /* original 03d6, guest PC 0x0c044b84 */
if(!s->budget--) { s->failed_pc=0x0c044b84u; return 0; }
write(ram,r[3]+r[0],r[13],4);
goto P_0c044b86;
P_0c044b86: /* original 7008, guest PC 0x0c044b86 */
if(!s->budget--) { s->failed_pc=0x0c044b86u; return 0; }
r[0]+=0x00000008u;
goto P_0c044b88;
P_0c044b88: /* original 63e2, guest PC 0x0c044b88 */
if(!s->budget--) { s->failed_pc=0x0c044b88u; return 0; }
tmp=read(ram,r[14],4);
r[3]=tmp;
goto P_0c044b8a;
P_0c044b8a: /* original 0326, guest PC 0x0c044b8a */
if(!s->budget--) { s->failed_pc=0x0c044b8au; return 0; }
write(ram,r[3]+r[0],r[2],4);
goto P_0c044b8c;
P_0c044b8c: /* original 9040, guest PC 0x0c044b8c */
if(!s->budget--) { s->failed_pc=0x0c044b8cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c044c10u,2);
goto P_0c044b8e;
P_0c044b8e: /* original 63e2, guest PC 0x0c044b8e */
if(!s->budget--) { s->failed_pc=0x0c044b8eu; return 0; }
tmp=read(ram,r[14],4);
r[3]=tmp;
goto P_0c044b90;
P_0c044b90: /* original 03d6, guest PC 0x0c044b90 */
if(!s->budget--) { s->failed_pc=0x0c044b90u; return 0; }
write(ram,r[3]+r[0],r[13],4);
goto P_0c044b92;
P_0c044b92: /* original 7024, guest PC 0x0c044b92 */
if(!s->budget--) { s->failed_pc=0x0c044b92u; return 0; }
r[0]+=0x00000024u;
goto P_0c044b94;
P_0c044b94: /* original 63e2, guest PC 0x0c044b94 */
if(!s->budget--) { s->failed_pc=0x0c044b94u; return 0; }
tmp=read(ram,r[14],4);
r[3]=tmp;
goto P_0c044b96;
P_0c044b96: /* original 03d6, guest PC 0x0c044b96 */
if(!s->budget--) { s->failed_pc=0x0c044b96u; return 0; }
write(ram,r[3]+r[0],r[13],4);
goto P_0c044b98;
P_0c044b98: /* original 63e2, guest PC 0x0c044b98 */
if(!s->budget--) { s->failed_pc=0x0c044b98u; return 0; }
tmp=read(ram,r[14],4);
r[3]=tmp;
goto P_0c044b9a;
P_0c044b9a: /* original 70fc, guest PC 0x0c044b9a */
if(!s->budget--) { s->failed_pc=0x0c044b9au; return 0; }
r[0]+=0xfffffffcu;
goto P_0c044b9c;
P_0c044b9c: /* original 03d6, guest PC 0x0c044b9c */
if(!s->budget--) { s->failed_pc=0x0c044b9cu; return 0; }
write(ram,r[3]+r[0],r[13],4);
goto P_0c044b9e;
P_0c044b9e: /* original 70e4, guest PC 0x0c044b9e */
if(!s->budget--) { s->failed_pc=0x0c044b9eu; return 0; }
r[0]+=0xffffffe4u;
goto P_0c044ba0;
P_0c044ba0: /* original 63e2, guest PC 0x0c044ba0 */
if(!s->budget--) { s->failed_pc=0x0c044ba0u; return 0; }
tmp=read(ram,r[14],4);
r[3]=tmp;
goto P_0c044ba2;
P_0c044ba2: /* original e405, guest PC 0x0c044ba2 */
if(!s->budget--) { s->failed_pc=0x0c044ba2u; return 0; }
r[4]=0x00000005u;
goto P_0c044ba4;
P_0c044ba4: /* original e20a, guest PC 0x0c044ba4 */
if(!s->budget--) { s->failed_pc=0x0c044ba4u; return 0; }
r[2]=0x0000000au;
goto P_0c044ba6;
P_0c044ba6: /* original 0346, guest PC 0x0c044ba6 */
if(!s->budget--) { s->failed_pc=0x0c044ba6u; return 0; }
write(ram,r[3]+r[0],r[4],4);
goto P_0c044ba8;
P_0c044ba8: /* original 7004, guest PC 0x0c044ba8 */
if(!s->budget--) { s->failed_pc=0x0c044ba8u; return 0; }
r[0]+=0x00000004u;
goto P_0c044baa;
P_0c044baa: /* original 63e2, guest PC 0x0c044baa */
if(!s->budget--) { s->failed_pc=0x0c044baau; return 0; }
tmp=read(ram,r[14],4);
r[3]=tmp;
goto P_0c044bac;
P_0c044bac: /* original 03d6, guest PC 0x0c044bac */
if(!s->budget--) { s->failed_pc=0x0c044bacu; return 0; }
write(ram,r[3]+r[0],r[13],4);
goto P_0c044bae;
P_0c044bae: /* original 7008, guest PC 0x0c044bae */
if(!s->budget--) { s->failed_pc=0x0c044baeu; return 0; }
r[0]+=0x00000008u;
goto P_0c044bb0;
P_0c044bb0: /* original 63e2, guest PC 0x0c044bb0 */
if(!s->budget--) { s->failed_pc=0x0c044bb0u; return 0; }
tmp=read(ram,r[14],4);
r[3]=tmp;
goto P_0c044bb2;
P_0c044bb2: /* original 0326, guest PC 0x0c044bb2 */
if(!s->budget--) { s->failed_pc=0x0c044bb2u; return 0; }
write(ram,r[3]+r[0],r[2],4);
goto P_0c044bb4;
P_0c044bb4: /* original 7004, guest PC 0x0c044bb4 */
if(!s->budget--) { s->failed_pc=0x0c044bb4u; return 0; }
r[0]+=0x00000004u;
goto P_0c044bb6;
P_0c044bb6: /* original 63e2, guest PC 0x0c044bb6 */
if(!s->budget--) { s->failed_pc=0x0c044bb6u; return 0; }
tmp=read(ram,r[14],4);
r[3]=tmp;
goto P_0c044bb8;
P_0c044bb8: /* original 0346, guest PC 0x0c044bb8 */
if(!s->budget--) { s->failed_pc=0x0c044bb8u; return 0; }
write(ram,r[3]+r[0],r[4],4);
goto P_0c044bba;
P_0c044bba: /* original 7004, guest PC 0x0c044bba */
if(!s->budget--) { s->failed_pc=0x0c044bbau; return 0; }
r[0]+=0x00000004u;
goto P_0c044bbc;
P_0c044bbc: /* original 63e2, guest PC 0x0c044bbc */
if(!s->budget--) { s->failed_pc=0x0c044bbcu; return 0; }
tmp=read(ram,r[14],4);
r[3]=tmp;
goto P_0c044bbe;
P_0c044bbe: /* original 03d6, guest PC 0x0c044bbe */
if(!s->budget--) { s->failed_pc=0x0c044bbeu; return 0; }
write(ram,r[3]+r[0],r[13],4);
goto P_0c044bc0;
P_0c044bc0: /* original 7004, guest PC 0x0c044bc0 */
if(!s->budget--) { s->failed_pc=0x0c044bc0u; return 0; }
r[0]+=0x00000004u;
goto P_0c044bc2;
P_0c044bc2: /* original 63e2, guest PC 0x0c044bc2 */
if(!s->budget--) { s->failed_pc=0x0c044bc2u; return 0; }
tmp=read(ram,r[14],4);
r[3]=tmp;
goto P_0c044bc4;
P_0c044bc4: /* original 03d6, guest PC 0x0c044bc4 */
if(!s->budget--) { s->failed_pc=0x0c044bc4u; return 0; }
write(ram,r[3]+r[0],r[13],4);
goto P_0c044bc6;
P_0c044bc6: /* original 9024, guest PC 0x0c044bc6 */
if(!s->budget--) { s->failed_pc=0x0c044bc6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c044c12u,2);
goto P_0c044bc8;
P_0c044bc8: /* original 63e2, guest PC 0x0c044bc8 */
if(!s->budget--) { s->failed_pc=0x0c044bc8u; return 0; }
tmp=read(ram,r[14],4);
r[3]=tmp;
goto P_0c044bca;
P_0c044bca: /* original 03d6, guest PC 0x0c044bca */
if(!s->budget--) { s->failed_pc=0x0c044bcau; return 0; }
write(ram,r[3]+r[0],r[13],4);
goto P_0c044bcc;
P_0c044bcc: /* original 7004, guest PC 0x0c044bcc */
if(!s->budget--) { s->failed_pc=0x0c044bccu; return 0; }
r[0]+=0x00000004u;
goto P_0c044bce;
P_0c044bce: /* original 63e2, guest PC 0x0c044bce */
if(!s->budget--) { s->failed_pc=0x0c044bceu; return 0; }
tmp=read(ram,r[14],4);
r[3]=tmp;
goto P_0c044bd0;
P_0c044bd0: /* original 03d6, guest PC 0x0c044bd0 */
if(!s->budget--) { s->failed_pc=0x0c044bd0u; return 0; }
write(ram,r[3]+r[0],r[13],4);
goto P_0c044bd2;
P_0c044bd2: /* original 7004, guest PC 0x0c044bd2 */
if(!s->budget--) { s->failed_pc=0x0c044bd2u; return 0; }
r[0]+=0x00000004u;
goto P_0c044bd4;
P_0c044bd4: /* original 63e2, guest PC 0x0c044bd4 */
if(!s->budget--) { s->failed_pc=0x0c044bd4u; return 0; }
tmp=read(ram,r[14],4);
r[3]=tmp;
goto P_0c044bd6;
P_0c044bd6: /* original 03d6, guest PC 0x0c044bd6 */
if(!s->budget--) { s->failed_pc=0x0c044bd6u; return 0; }
write(ram,r[3]+r[0],r[13],4);
goto P_0c044bd8;
P_0c044bd8: /* original 63e2, guest PC 0x0c044bd8 */
if(!s->budget--) { s->failed_pc=0x0c044bd8u; return 0; }
tmp=read(ram,r[14],4);
r[3]=tmp;
goto P_0c044bda;
P_0c044bda: /* original d211, guest PC 0x0c044bda */
if(!s->budget--) { s->failed_pc=0x0c044bdau; return 0; }
r[2]=read(ram,0x0c044c20u,4);
goto P_0c044bdc;
P_0c044bdc: /* original 2322, guest PC 0x0c044bdc */
if(!s->budget--) { s->failed_pc=0x0c044bdcu; return 0; }
write(ram,r[3],r[2],4);
goto P_0c044bde;
P_0c044bde: /* original d211, guest PC 0x0c044bde */
if(!s->budget--) { s->failed_pc=0x0c044bdeu; return 0; }
r[2]=read(ram,0x0c044c24u,4);
goto P_0c044be0;
P_0c044be0: /* original 63e2, guest PC 0x0c044be0 */
if(!s->budget--) { s->failed_pc=0x0c044be0u; return 0; }
tmp=read(ram,r[14],4);
r[3]=tmp;
goto P_0c044be2;
P_0c044be2: /* original 1329, guest PC 0x0c044be2 */
if(!s->budget--) { s->failed_pc=0x0c044be2u; return 0; }
write(ram,r[3]+36,r[2],4);
goto P_0c044be4;
P_0c044be4: /* original 63e2, guest PC 0x0c044be4 */
if(!s->budget--) { s->failed_pc=0x0c044be4u; return 0; }
tmp=read(ram,r[14],4);
r[3]=tmp;
goto P_0c044be6;
P_0c044be6: /* original a01f, guest PC 0x0c044be6 */
if(!s->budget--) { s->failed_pc=0x0c044be6u; return 0; }
goto P_0c044c28;
P_0c044be8: /* original 0009, guest PC 0x0c044be8 */
if(!s->budget--) { s->failed_pc=0x0c044be8u; return 0; }
if(!vf3_matrix_family(0x0c044beau,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c044beau; return 0; } return 1;
P_0c044c28: /* original 9072, guest PC 0x0c044c28 */
if(!s->budget--) { s->failed_pc=0x0c044c28u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c044d10u,2);
goto P_0c044c2a;
P_0c044c2a: /* original d23c, guest PC 0x0c044c2a */
if(!s->budget--) { s->failed_pc=0x0c044c2au; return 0; }
r[2]=read(ram,0x0c044d1cu,4);
goto P_0c044c2c;
P_0c044c2c: /* original 0326, guest PC 0x0c044c2c */
if(!s->budget--) { s->failed_pc=0x0c044c2cu; return 0; }
write(ram,r[3]+r[0],r[2],4);
goto P_0c044c2e;
P_0c044c2e: /* original 9070, guest PC 0x0c044c2e */
if(!s->budget--) { s->failed_pc=0x0c044c2eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c044d12u,2);
goto P_0c044c30;
P_0c044c30: /* original d23b, guest PC 0x0c044c30 */
if(!s->budget--) { s->failed_pc=0x0c044c30u; return 0; }
r[2]=read(ram,0x0c044d20u,4);
goto P_0c044c32;
P_0c044c32: /* original 63e2, guest PC 0x0c044c32 */
if(!s->budget--) { s->failed_pc=0x0c044c32u; return 0; }
tmp=read(ram,r[14],4);
r[3]=tmp;
goto P_0c044c34;
P_0c044c34: /* original 0326, guest PC 0x0c044c34 */
if(!s->budget--) { s->failed_pc=0x0c044c34u; return 0; }
write(ram,r[3]+r[0],r[2],4);
goto P_0c044c36;
P_0c044c36: /* original 701c, guest PC 0x0c044c36 */
if(!s->budget--) { s->failed_pc=0x0c044c36u; return 0; }
r[0]+=0x0000001cu;
goto P_0c044c38;
P_0c044c38: /* original d23a, guest PC 0x0c044c38 */
if(!s->budget--) { s->failed_pc=0x0c044c38u; return 0; }
r[2]=read(ram,0x0c044d24u,4);
goto P_0c044c3a;
P_0c044c3a: /* original 63e2, guest PC 0x0c044c3a */
if(!s->budget--) { s->failed_pc=0x0c044c3au; return 0; }
tmp=read(ram,r[14],4);
r[3]=tmp;
goto P_0c044c3c;
P_0c044c3c: /* original 0326, guest PC 0x0c044c3c */
if(!s->budget--) { s->failed_pc=0x0c044c3cu; return 0; }
write(ram,r[3]+r[0],r[2],4);
goto P_0c044c3e;
P_0c044c3e: /* original 7034, guest PC 0x0c044c3e */
if(!s->budget--) { s->failed_pc=0x0c044c3eu; return 0; }
r[0]+=0x00000034u;
goto P_0c044c40;
P_0c044c40: /* original d239, guest PC 0x0c044c40 */
if(!s->budget--) { s->failed_pc=0x0c044c40u; return 0; }
r[2]=read(ram,0x0c044d28u,4);
goto P_0c044c42;
P_0c044c42: /* original 63e2, guest PC 0x0c044c42 */
if(!s->budget--) { s->failed_pc=0x0c044c42u; return 0; }
tmp=read(ram,r[14],4);
r[3]=tmp;
goto P_0c044c44;
P_0c044c44: /* original 0326, guest PC 0x0c044c44 */
if(!s->budget--) { s->failed_pc=0x0c044c44u; return 0; }
write(ram,r[3]+r[0],r[2],4);
goto P_0c044c46;
P_0c044c46: /* original 9065, guest PC 0x0c044c46 */
if(!s->budget--) { s->failed_pc=0x0c044c46u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c044d14u,2);
goto P_0c044c48;
P_0c044c48: /* original d238, guest PC 0x0c044c48 */
if(!s->budget--) { s->failed_pc=0x0c044c48u; return 0; }
r[2]=read(ram,0x0c044d2cu,4);
goto P_0c044c4a;
P_0c044c4a: /* original 63e2, guest PC 0x0c044c4a */
if(!s->budget--) { s->failed_pc=0x0c044c4au; return 0; }
tmp=read(ram,r[14],4);
r[3]=tmp;
goto P_0c044c4c;
P_0c044c4c: /* original 0326, guest PC 0x0c044c4c */
if(!s->budget--) { s->failed_pc=0x0c044c4cu; return 0; }
write(ram,r[3]+r[0],r[2],4);
goto P_0c044c4e;
P_0c044c4e: /* original 7018, guest PC 0x0c044c4e */
if(!s->budget--) { s->failed_pc=0x0c044c4eu; return 0; }
r[0]+=0x00000018u;
goto P_0c044c50;
P_0c044c50: /* original d237, guest PC 0x0c044c50 */
if(!s->budget--) { s->failed_pc=0x0c044c50u; return 0; }
r[2]=read(ram,0x0c044d30u,4);
goto P_0c044c52;
P_0c044c52: /* original 63e2, guest PC 0x0c044c52 */
if(!s->budget--) { s->failed_pc=0x0c044c52u; return 0; }
tmp=read(ram,r[14],4);
r[3]=tmp;
goto P_0c044c54;
P_0c044c54: /* original 0326, guest PC 0x0c044c54 */
if(!s->budget--) { s->failed_pc=0x0c044c54u; return 0; }
write(ram,r[3]+r[0],r[2],4);
goto P_0c044c56;
P_0c044c56: /* original 701c, guest PC 0x0c044c56 */
if(!s->budget--) { s->failed_pc=0x0c044c56u; return 0; }
r[0]+=0x0000001cu;
goto P_0c044c58;
P_0c044c58: /* original d236, guest PC 0x0c044c58 */
if(!s->budget--) { s->failed_pc=0x0c044c58u; return 0; }
r[2]=read(ram,0x0c044d34u,4);
goto P_0c044c5a;
P_0c044c5a: /* original 63e2, guest PC 0x0c044c5a */
if(!s->budget--) { s->failed_pc=0x0c044c5au; return 0; }
tmp=read(ram,r[14],4);
r[3]=tmp;
goto P_0c044c5c;
P_0c044c5c: /* original 0326, guest PC 0x0c044c5c */
if(!s->budget--) { s->failed_pc=0x0c044c5cu; return 0; }
write(ram,r[3]+r[0],r[2],4);
goto P_0c044c5e;
P_0c044c5e: /* original 7008, guest PC 0x0c044c5e */
if(!s->budget--) { s->failed_pc=0x0c044c5eu; return 0; }
r[0]+=0x00000008u;
goto P_0c044c60;
P_0c044c60: /* original d235, guest PC 0x0c044c60 */
if(!s->budget--) { s->failed_pc=0x0c044c60u; return 0; }
r[2]=read(ram,0x0c044d38u,4);
goto P_0c044c62;
P_0c044c62: /* original 63e2, guest PC 0x0c044c62 */
if(!s->budget--) { s->failed_pc=0x0c044c62u; return 0; }
tmp=read(ram,r[14],4);
r[3]=tmp;
goto P_0c044c64;
P_0c044c64: /* original 0326, guest PC 0x0c044c64 */
if(!s->budget--) { s->failed_pc=0x0c044c64u; return 0; }
write(ram,r[3]+r[0],r[2],4);
goto P_0c044c66;
P_0c044c66: /* original d335, guest PC 0x0c044c66 */
if(!s->budget--) { s->failed_pc=0x0c044c66u; return 0; }
r[3]=read(ram,0x0c044d3cu,4);
goto P_0c044c68;
P_0c044c68: /* original 430b, guest PC 0x0c044c68 */
if(!s->budget--) { s->failed_pc=0x0c044c68u; return 0; }
target=r[3];
r[16]=code_base|0x0c044c6cu;
r[4]=0x00000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c044c6cu) { target=s->pc; goto dispatch; }
goto P_0c044c6c;
P_0c044c6a: /* original e400, guest PC 0x0c044c6a */
if(!s->budget--) { s->failed_pc=0x0c044c6au; return 0; }
r[4]=0x00000000u;
goto P_0c044c6c;
P_0c044c6c: /* original 4f16, guest PC 0x0c044c6c */
if(!s->budget--) { s->failed_pc=0x0c044c6cu; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c044c6e;
P_0c044c6e: /* original d234, guest PC 0x0c044c6e */
if(!s->budget--) { s->failed_pc=0x0c044c6eu; return 0; }
r[2]=read(ram,0x0c044d40u,4);
goto P_0c044c70;
P_0c044c70: /* original 4f26, guest PC 0x0c044c70 */
if(!s->budget--) { s->failed_pc=0x0c044c70u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c044c72;
P_0c044c72: /* original 6bf6, guest PC 0x0c044c72 */
if(!s->budget--) { s->failed_pc=0x0c044c72u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c044c74;
P_0c044c74: /* original 6cf6, guest PC 0x0c044c74 */
if(!s->budget--) { s->failed_pc=0x0c044c74u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c044c76;
P_0c044c76: /* original 6df6, guest PC 0x0c044c76 */
if(!s->budget--) { s->failed_pc=0x0c044c76u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c044c78;
P_0c044c78: /* original 422b, guest PC 0x0c044c78 */
if(!s->budget--) { s->failed_pc=0x0c044c78u; return 0; }
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
P_0c044c7a: /* original 6ef6, guest PC 0x0c044c7a */
if(!s->budget--) { s->failed_pc=0x0c044c7au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c044c7c;
P_0c044c7c: /* original d531, guest PC 0x0c044c7c */
if(!s->budget--) { s->failed_pc=0x0c044c7cu; return 0; }
r[5]=read(ram,0x0c044d44u,4);
goto P_0c044c7e;
P_0c044c7e: /* original 4415, guest PC 0x0c044c7e */
if(!s->budget--) { s->failed_pc=0x0c044c7eu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>0)!=0);
goto P_0c044c80;
P_0c044c80: /* original 9049, guest PC 0x0c044c80 */
if(!s->budget--) { s->failed_pc=0x0c044c80u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c044d16u,2);
goto P_0c044c82;
P_0c044c82: /* original 6352, guest PC 0x0c044c82 */
if(!s->budget--) { s->failed_pc=0x0c044c82u; return 0; }
tmp=read(ram,r[5],4);
r[3]=tmp;
goto P_0c044c84;
P_0c044c84: /* original 6103, guest PC 0x0c044c84 */
if(!s->budget--) { s->failed_pc=0x0c044c84u; return 0; }
r[1]=r[0];
goto P_0c044c86;
P_0c044c86: /* original 710c, guest PC 0x0c044c86 */
if(!s->budget--) { s->failed_pc=0x0c044c86u; return 0; }
r[1]+=0x0000000cu;
goto P_0c044c88;
P_0c044c88: /* original 6233, guest PC 0x0c044c88 */
if(!s->budget--) { s->failed_pc=0x0c044c88u; return 0; }
r[2]=r[3];
goto P_0c044c8a;
P_0c044c8a: /* original 312c, guest PC 0x0c044c8a */
if(!s->budget--) { s->failed_pc=0x0c044c8au; return 0; }
r[1]+=r[2];
goto P_0c044c8c;
P_0c044c8c: /* original 6112, guest PC 0x0c044c8c */
if(!s->budget--) { s->failed_pc=0x0c044c8cu; return 0; }
tmp=read(ram,r[1],4);
r[1]=tmp;
goto P_0c044c8e;
P_0c044c8e: /* original 023e, guest PC 0x0c044c8e */
if(!s->budget--) { s->failed_pc=0x0c044c8eu; return 0; }
r[2]=read(ram,r[3]+r[0],4);
goto P_0c044c90;
P_0c044c90: /* original 4108, guest PC 0x0c044c90 */
if(!s->budget--) { s->failed_pc=0x0c044c90u; return 0; }
r[1]<<=2;
goto P_0c044c92;
P_0c044c92: /* original 321c, guest PC 0x0c044c92 */
if(!s->budget--) { s->failed_pc=0x0c044c92u; return 0; }
r[2]+=r[1];
goto P_0c044c94;
P_0c044c94: /* original 0326, guest PC 0x0c044c94 */
if(!s->budget--) { s->failed_pc=0x0c044c94u; return 0; }
write(ram,r[3]+r[0],r[2],4);
goto P_0c044c96;
P_0c044c96: /* original 6152, guest PC 0x0c044c96 */
if(!s->budget--) { s->failed_pc=0x0c044c96u; return 0; }
tmp=read(ram,r[5],4);
r[1]=tmp;
goto P_0c044c98;
P_0c044c98: /* original 973e, guest PC 0x0c044c98 */
if(!s->budget--) { s->failed_pc=0x0c044c98u; return 0; }
r[7]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c044d18u,2);
goto P_0c044c9a;
P_0c044c9a: /* original 011e, guest PC 0x0c044c9a */
if(!s->budget--) { s->failed_pc=0x0c044c9au; return 0; }
r[1]=read(ram,r[1]+r[0],4);
goto P_0c044c9c;
P_0c044c9c: /* original 8f05, guest PC 0x0c044c9c */
if(!s->budget--) { s->failed_pc=0x0c044c9cu; return 0; }
cond=r[17]&1u;
r[6]=0x00000000u;
if(!cond) { goto P_0c044caa; }
goto P_0c044ca0;
P_0c044c9e: /* original e600, guest PC 0x0c044c9e */
if(!s->budget--) { s->failed_pc=0x0c044c9eu; return 0; }
r[6]=0x00000000u;
goto P_0c044ca0;
P_0c044ca0: /* original 7601, guest PC 0x0c044ca0 */
if(!s->budget--) { s->failed_pc=0x0c044ca0u; return 0; }
r[6]+=0x00000001u;
goto P_0c044ca2;
P_0c044ca2: /* original 2172, guest PC 0x0c044ca2 */
if(!s->budget--) { s->failed_pc=0x0c044ca2u; return 0; }
write(ram,r[1],r[7],4);
goto P_0c044ca4;
P_0c044ca4: /* original 3643, guest PC 0x0c044ca4 */
if(!s->budget--) { s->failed_pc=0x0c044ca4u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[6]>=(int32_t)r[4])!=0);
goto P_0c044ca6;
P_0c044ca6: /* original 8ffb, guest PC 0x0c044ca6 */
if(!s->budget--) { s->failed_pc=0x0c044ca6u; return 0; }
cond=r[17]&1u;
r[1]+=0x00000004u;
if(!cond) { goto P_0c044ca0; }
goto P_0c044caa;
P_0c044ca8: /* original 7104, guest PC 0x0c044ca8 */
if(!s->budget--) { s->failed_pc=0x0c044ca8u; return 0; }
r[1]+=0x00000004u;
goto P_0c044caa;
P_0c044caa: /* original 9036, guest PC 0x0c044caa */
if(!s->budget--) { s->failed_pc=0x0c044caau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c044d1au,2);
goto P_0c044cac;
P_0c044cac: /* original 6252, guest PC 0x0c044cac */
if(!s->budget--) { s->failed_pc=0x0c044cacu; return 0; }
tmp=read(ram,r[5],4);
r[2]=tmp;
goto P_0c044cae;
P_0c044cae: /* original 0246, guest PC 0x0c044cae */
if(!s->budget--) { s->failed_pc=0x0c044caeu; return 0; }
write(ram,r[2]+r[0],r[4],4);
goto P_0c044cb0;
P_0c044cb0: /* original 7004, guest PC 0x0c044cb0 */
if(!s->budget--) { s->failed_pc=0x0c044cb0u; return 0; }
r[0]+=0x00000004u;
goto P_0c044cb2;
P_0c044cb2: /* original 6352, guest PC 0x0c044cb2 */
if(!s->budget--) { s->failed_pc=0x0c044cb2u; return 0; }
tmp=read(ram,r[5],4);
r[3]=tmp;
goto P_0c044cb4;
P_0c044cb4: /* original 4408, guest PC 0x0c044cb4 */
if(!s->budget--) { s->failed_pc=0x0c044cb4u; return 0; }
r[4]<<=2;
goto P_0c044cb6;
P_0c044cb6: /* original 023e, guest PC 0x0c044cb6 */
if(!s->budget--) { s->failed_pc=0x0c044cb6u; return 0; }
r[2]=read(ram,r[3]+r[0],4);
goto P_0c044cb8;
P_0c044cb8: /* original 324c, guest PC 0x0c044cb8 */
if(!s->budget--) { s->failed_pc=0x0c044cb8u; return 0; }
r[2]+=r[4];
goto P_0c044cba;
P_0c044cba: /* original 0326, guest PC 0x0c044cba */
if(!s->budget--) { s->failed_pc=0x0c044cbau; return 0; }
write(ram,r[3]+r[0],r[2],4);
goto P_0c044cbc;
P_0c044cbc: /* original 000b, guest PC 0x0c044cbc */
if(!s->budget--) { s->failed_pc=0x0c044cbcu; return 0; }
target=r[16];
r[0]=0x00000000u;
s->pc=target; return ram->oob==0;
P_0c044cbe: /* original e000, guest PC 0x0c044cbe */
if(!s->budget--) { s->failed_pc=0x0c044cbeu; return 0; }
r[0]=0x00000000u;
return vf3_matrix_family(0x0c044cc0u,s,ram);
unsupported: s->failed_pc=target; return 0;
}
