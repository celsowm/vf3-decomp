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
int vf3_away_batch17_adapter_15(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c094884u: goto P_0c094884;
case 0x0c094886u: goto P_0c094886;
case 0x0c094888u: goto P_0c094888;
case 0x0c09488au: goto P_0c09488a;
case 0x0c09488cu: goto P_0c09488c;
case 0x0c09488eu: goto P_0c09488e;
case 0x0c094890u: goto P_0c094890;
case 0x0c094892u: goto P_0c094892;
case 0x0c094894u: goto P_0c094894;
case 0x0c094896u: goto P_0c094896;
case 0x0c094898u: goto P_0c094898;
case 0x0c09489au: goto P_0c09489a;
case 0x0c09489cu: goto P_0c09489c;
case 0x0c09489eu: goto P_0c09489e;
case 0x0c0948a0u: goto P_0c0948a0;
case 0x0c0948a2u: goto P_0c0948a2;
case 0x0c0948a4u: goto P_0c0948a4;
case 0x0c0948a6u: goto P_0c0948a6;
case 0x0c0948a8u: goto P_0c0948a8;
case 0x0c0948aau: goto P_0c0948aa;
case 0x0c0948acu: goto P_0c0948ac;
case 0x0c0948aeu: goto P_0c0948ae;
case 0x0c0948b0u: goto P_0c0948b0;
case 0x0c0948b2u: goto P_0c0948b2;
case 0x0c0948b4u: goto P_0c0948b4;
case 0x0c0948b6u: goto P_0c0948b6;
case 0x0c0948b8u: goto P_0c0948b8;
case 0x0c0948bau: goto P_0c0948ba;
case 0x0c0948bcu: goto P_0c0948bc;
case 0x0c0948beu: goto P_0c0948be;
case 0x0c0948c0u: goto P_0c0948c0;
case 0x0c0948c2u: goto P_0c0948c2;
case 0x0c0948c4u: goto P_0c0948c4;
case 0x0c0948c6u: goto P_0c0948c6;
case 0x0c0948c8u: goto P_0c0948c8;
case 0x0c0948cau: goto P_0c0948ca;
case 0x0c0948ccu: goto P_0c0948cc;
case 0x0c0948ceu: goto P_0c0948ce;
case 0x0c0948d0u: goto P_0c0948d0;
case 0x0c0948d2u: goto P_0c0948d2;
case 0x0c0948d4u: goto P_0c0948d4;
case 0x0c0948d6u: goto P_0c0948d6;
case 0x0c0948d8u: goto P_0c0948d8;
case 0x0c0948dau: goto P_0c0948da;
case 0x0c0948dcu: goto P_0c0948dc;
case 0x0c0948deu: goto P_0c0948de;
case 0x0c0948e0u: goto P_0c0948e0;
case 0x0c0948e2u: goto P_0c0948e2;
case 0x0c0948e4u: goto P_0c0948e4;
case 0x0c0948e6u: goto P_0c0948e6;
case 0x0c0948e8u: goto P_0c0948e8;
case 0x0c0948eau: goto P_0c0948ea;
case 0x0c0948ecu: goto P_0c0948ec;
case 0x0c0948eeu: goto P_0c0948ee;
case 0x0c0948f0u: goto P_0c0948f0;
case 0x0c0948f2u: goto P_0c0948f2;
case 0x0c0948f4u: goto P_0c0948f4;
case 0x0c0948f6u: goto P_0c0948f6;
case 0x0c0948f8u: goto P_0c0948f8;
case 0x0c0948fau: goto P_0c0948fa;
case 0x0c0948fcu: goto P_0c0948fc;
case 0x0c0948feu: goto P_0c0948fe;
case 0x0c094900u: goto P_0c094900;
case 0x0c094902u: goto P_0c094902;
case 0x0c094904u: goto P_0c094904;
case 0x0c094906u: goto P_0c094906;
case 0x0c094908u: goto P_0c094908;
case 0x0c09490au: goto P_0c09490a;
case 0x0c09490cu: goto P_0c09490c;
case 0x0c09490eu: goto P_0c09490e;
case 0x0c094910u: goto P_0c094910;
case 0x0c094912u: goto P_0c094912;
case 0x0c094914u: goto P_0c094914;
case 0x0c094916u: goto P_0c094916;
case 0x0c09493cu: goto P_0c09493c;
case 0x0c09493eu: goto P_0c09493e;
case 0x0c094940u: goto P_0c094940;
case 0x0c094942u: goto P_0c094942;
case 0x0c094944u: goto P_0c094944;
case 0x0c094946u: goto P_0c094946;
case 0x0c094948u: goto P_0c094948;
case 0x0c09494au: goto P_0c09494a;
case 0x0c09494cu: goto P_0c09494c;
case 0x0c09494eu: goto P_0c09494e;
case 0x0c094950u: goto P_0c094950;
case 0x0c094952u: goto P_0c094952;
case 0x0c094954u: goto P_0c094954;
case 0x0c094956u: goto P_0c094956;
case 0x0c094958u: goto P_0c094958;
case 0x0c09495au: goto P_0c09495a;
case 0x0c09495cu: goto P_0c09495c;
case 0x0c09495eu: goto P_0c09495e;
case 0x0c094960u: goto P_0c094960;
case 0x0c094962u: goto P_0c094962;
case 0x0c094964u: goto P_0c094964;
case 0x0c094966u: goto P_0c094966;
case 0x0c094968u: goto P_0c094968;
case 0x0c09496au: goto P_0c09496a;
case 0x0c09496cu: goto P_0c09496c;
case 0x0c09496eu: goto P_0c09496e;
case 0x0c094970u: goto P_0c094970;
case 0x0c094b20u: goto P_0c094b20;
case 0x0c094b22u: goto P_0c094b22;
case 0x0c094b24u: goto P_0c094b24;
case 0x0c094b26u: goto P_0c094b26;
case 0x0c094b28u: goto P_0c094b28;
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
P_0c094884: /* original 2fe6, guest PC 0x0c094884 */
if(!s->budget--) { s->failed_pc=0x0c094884u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c094886;
P_0c094886: /* original e061, guest PC 0x0c094886 */
if(!s->budget--) { s->failed_pc=0x0c094886u; return 0; }
r[0]=0x00000061u;
goto P_0c094888;
P_0c094888: /* original 2fd6, guest PC 0x0c094888 */
if(!s->budget--) { s->failed_pc=0x0c094888u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09488a;
P_0c09488a: /* original 2fc6, guest PC 0x0c09488a */
if(!s->budget--) { s->failed_pc=0x0c09488au; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09488c;
P_0c09488c: /* original 2fb6, guest PC 0x0c09488c */
if(!s->budget--) { s->failed_pc=0x0c09488cu; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09488e;
P_0c09488e: /* original 2fa6, guest PC 0x0c09488e */
if(!s->budget--) { s->failed_pc=0x0c09488eu; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c094890;
P_0c094890: /* original 2f96, guest PC 0x0c094890 */
if(!s->budget--) { s->failed_pc=0x0c094890u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c094892;
P_0c094892: /* original 2f86, guest PC 0x0c094892 */
if(!s->budget--) { s->failed_pc=0x0c094892u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c094894;
P_0c094894: /* original d621, guest PC 0x0c094894 */
if(!s->budget--) { s->failed_pc=0x0c094894u; return 0; }
r[6]=read(ram,0x0c09491cu,4);
goto P_0c094896;
P_0c094896: /* original 4f22, guest PC 0x0c094896 */
if(!s->budget--) { s->failed_pc=0x0c094896u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c094898;
P_0c094898: /* original 5564, guest PC 0x0c094898 */
if(!s->budget--) { s->failed_pc=0x0c094898u; return 0; }
r[5]=read(ram,r[6]+16,4);
goto P_0c09489a;
P_0c09489a: /* original 005c, guest PC 0x0c09489a */
if(!s->budget--) { s->failed_pc=0x0c09489au; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[5]+r[0],1);
goto P_0c09489c;
P_0c09489c: /* original 600c, guest PC 0x0c09489c */
if(!s->budget--) { s->failed_pc=0x0c09489cu; return 0; }
r[0]=r[0]&255u;
goto P_0c09489e;
P_0c09489e: /* original 880b, guest PC 0x0c09489e */
if(!s->budget--) { s->failed_pc=0x0c09489eu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000bu)!=0);
goto P_0c0948a0;
P_0c0948a0: /* original 8f05, guest PC 0x0c0948a0 */
if(!s->budget--) { s->failed_pc=0x0c0948a0u; return 0; }
cond=r[17]&1u;
r[6]=read(ram,r[6]+20,4);
if(!cond) { goto P_0c0948ae; }
goto P_0c0948a4;
P_0c0948a2: /* original 5665, guest PC 0x0c0948a2 */
if(!s->budget--) { s->failed_pc=0x0c0948a2u; return 0; }
r[6]=read(ram,r[6]+20,4);
goto P_0c0948a4;
P_0c0948a4: /* original e061, guest PC 0x0c0948a4 */
if(!s->budget--) { s->failed_pc=0x0c0948a4u; return 0; }
r[0]=0x00000061u;
goto P_0c0948a6;
P_0c0948a6: /* original 006c, guest PC 0x0c0948a6 */
if(!s->budget--) { s->failed_pc=0x0c0948a6u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[6]+r[0],1);
goto P_0c0948a8;
P_0c0948a8: /* original 600c, guest PC 0x0c0948a8 */
if(!s->budget--) { s->failed_pc=0x0c0948a8u; return 0; }
r[0]=r[0]&255u;
goto P_0c0948aa;
P_0c0948aa: /* original 8806, guest PC 0x0c0948aa */
if(!s->budget--) { s->failed_pc=0x0c0948aau; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000006u)!=0);
goto P_0c0948ac;
P_0c0948ac: /* original 892b, guest PC 0x0c0948ac */
if(!s->budget--) { s->failed_pc=0x0c0948acu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c094906; }
goto P_0c0948ae;
P_0c0948ae: /* original d21c, guest PC 0x0c0948ae */
if(!s->budget--) { s->failed_pc=0x0c0948aeu; return 0; }
r[2]=read(ram,0x0c094920u,4);
goto P_0c0948b0;
P_0c0948b0: /* original 6e43, guest PC 0x0c0948b0 */
if(!s->budget--) { s->failed_pc=0x0c0948b0u; return 0; }
r[14]=r[4];
goto P_0c0948b2;
P_0c0948b2: /* original 420b, guest PC 0x0c0948b2 */
if(!s->budget--) { s->failed_pc=0x0c0948b2u; return 0; }
target=r[2];
r[16]=code_base|0x0c0948b6u;
r[4]=0x00000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0948b6u) { target=s->pc; goto dispatch; }
goto P_0c0948b6;
P_0c0948b4: /* original e400, guest PC 0x0c0948b4 */
if(!s->budget--) { s->failed_pc=0x0c0948b4u; return 0; }
r[4]=0x00000000u;
goto P_0c0948b6;
P_0c0948b6: /* original 9a2f, guest PC 0x0c0948b6 */
if(!s->budget--) { s->failed_pc=0x0c0948b6u; return 0; }
r[10]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c094918u,2);
goto P_0c0948b8;
P_0c0948b8: /* original ed32, guest PC 0x0c0948b8 */
if(!s->budget--) { s->failed_pc=0x0c0948b8u; return 0; }
r[13]=0x00000032u;
goto P_0c0948ba;
P_0c0948ba: /* original d91b, guest PC 0x0c0948ba */
if(!s->budget--) { s->failed_pc=0x0c0948bau; return 0; }
r[9]=read(ram,0x0c094928u,4);
goto P_0c0948bc;
P_0c0948bc: /* original d819, guest PC 0x0c0948bc */
if(!s->budget--) { s->failed_pc=0x0c0948bcu; return 0; }
r[8]=read(ram,0x0c094924u,4);
goto P_0c0948be;
P_0c0948be: /* original 490b, guest PC 0x0c0948be */
if(!s->budget--) { s->failed_pc=0x0c0948beu; return 0; }
target=r[9];
r[16]=code_base|0x0c0948c2u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0948c2u) { target=s->pc; goto dispatch; }
goto P_0c0948c2;
P_0c0948c0: /* original 0009, guest PC 0x0c0948c0 */
if(!s->budget--) { s->failed_pc=0x0c0948c0u; return 0; }
goto P_0c0948c2;
P_0c0948c2: /* original e004, guest PC 0x0c0948c2 */
if(!s->budget--) { s->failed_pc=0x0c0948c2u; return 0; }
r[0]=0x00000004u;
goto P_0c0948c4;
P_0c0948c4: /* original f4e8, guest PC 0x0c0948c4 */
if(!s->budget--) { s->failed_pc=0x0c0948c4u; return 0; }
vf3_matrix_load(s,ram,4,r[14]);
goto P_0c0948c6;
P_0c0948c6: /* original f5e6, guest PC 0x0c0948c6 */
if(!s->budget--) { s->failed_pc=0x0c0948c6u; return 0; }
vf3_matrix_load(s,ram,5,r[14]+r[0]);
goto P_0c0948c8;
P_0c0948c8: /* original e008, guest PC 0x0c0948c8 */
if(!s->budget--) { s->failed_pc=0x0c0948c8u; return 0; }
r[0]=0x00000008u;
goto P_0c0948ca;
P_0c0948ca: /* original f6e6, guest PC 0x0c0948ca */
if(!s->budget--) { s->failed_pc=0x0c0948cau; return 0; }
vf3_matrix_load(s,ram,6,r[14]+r[0]);
goto P_0c0948cc;
P_0c0948cc: /* original 85e8, guest PC 0x0c0948cc */
if(!s->budget--) { s->failed_pc=0x0c0948ccu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+16,2);
goto P_0c0948ce;
P_0c0948ce: /* original 6c03, guest PC 0x0c0948ce */
if(!s->budget--) { s->failed_pc=0x0c0948ceu; return 0; }
r[12]=r[0];
goto P_0c0948d0;
P_0c0948d0: /* original e016, guest PC 0x0c0948d0 */
if(!s->budget--) { s->failed_pc=0x0c0948d0u; return 0; }
r[0]=0x00000016u;
goto P_0c0948d2;
P_0c0948d2: /* original 480b, guest PC 0x0c0948d2 */
if(!s->budget--) { s->failed_pc=0x0c0948d2u; return 0; }
target=r[8];
r[16]=code_base|0x0c0948d6u;
r[11]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0948d6u) { target=s->pc; goto dispatch; }
goto P_0c0948d6;
P_0c0948d4: /* original 0bec, guest PC 0x0c0948d4 */
if(!s->budget--) { s->failed_pc=0x0c0948d4u; return 0; }
r[11]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0948d6;
P_0c0948d6: /* original d315, guest PC 0x0c0948d6 */
if(!s->budget--) { s->failed_pc=0x0c0948d6u; return 0; }
r[3]=read(ram,0x0c09492cu,4);
goto P_0c0948d8;
P_0c0948d8: /* original 64cf, guest PC 0x0c0948d8 */
if(!s->budget--) { s->failed_pc=0x0c0948d8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)r[12];
goto P_0c0948da;
P_0c0948da: /* original 430b, guest PC 0x0c0948da */
if(!s->budget--) { s->failed_pc=0x0c0948dau; return 0; }
target=r[3];
r[16]=code_base|0x0c0948deu;
r[4]+=r[10];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0948deu) { target=s->pc; goto dispatch; }
goto P_0c0948de;
P_0c0948dc: /* original 34ac, guest PC 0x0c0948dc */
if(!s->budget--) { s->failed_pc=0x0c0948dcu; return 0; }
r[4]+=r[10];
goto P_0c0948de;
P_0c0948de: /* original d014, guest PC 0x0c0948de */
if(!s->budget--) { s->failed_pc=0x0c0948deu; return 0; }
r[0]=read(ram,0x0c094930u,4);
goto P_0c0948e0;
P_0c0948e0: /* original 64be, guest PC 0x0c0948e0 */
if(!s->budget--) { s->failed_pc=0x0c0948e0u; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)r[11];
goto P_0c0948e2;
P_0c0948e2: /* original d314, guest PC 0x0c0948e2 */
if(!s->budget--) { s->failed_pc=0x0c0948e2u; return 0; }
r[3]=read(ram,0x0c094934u,4);
goto P_0c0948e4;
P_0c0948e4: /* original 4400, guest PC 0x0c0948e4 */
if(!s->budget--) { s->failed_pc=0x0c0948e4u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c0948e6;
P_0c0948e6: /* original 430b, guest PC 0x0c0948e6 */
if(!s->budget--) { s->failed_pc=0x0c0948e6u; return 0; }
target=r[3];
r[16]=code_base|0x0c0948eau;
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0948eau) { target=s->pc; goto dispatch; }
goto P_0c0948ea;
P_0c0948e8: /* original 044d, guest PC 0x0c0948e8 */
if(!s->budget--) { s->failed_pc=0x0c0948e8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c0948ea;
P_0c0948ea: /* original 4d10, guest PC 0x0c0948ea */
if(!s->budget--) { s->failed_pc=0x0c0948eau; return 0; }
--r[13];
r[17]=(r[17]&~1u)|((r[13]==0)!=0);
goto P_0c0948ec;
P_0c0948ec: /* original 8fe7, guest PC 0x0c0948ec */
if(!s->budget--) { s->failed_pc=0x0c0948ecu; return 0; }
cond=r[17]&1u;
r[14]+=0x00000018u;
if(!cond) { goto P_0c0948be; }
goto P_0c0948f0;
P_0c0948ee: /* original 7e18, guest PC 0x0c0948ee */
if(!s->budget--) { s->failed_pc=0x0c0948eeu; return 0; }
r[14]+=0x00000018u;
goto P_0c0948f0;
P_0c0948f0: /* original 4f26, guest PC 0x0c0948f0 */
if(!s->budget--) { s->failed_pc=0x0c0948f0u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0948f2;
P_0c0948f2: /* original d311, guest PC 0x0c0948f2 */
if(!s->budget--) { s->failed_pc=0x0c0948f2u; return 0; }
r[3]=read(ram,0x0c094938u,4);
goto P_0c0948f4;
P_0c0948f4: /* original e401, guest PC 0x0c0948f4 */
if(!s->budget--) { s->failed_pc=0x0c0948f4u; return 0; }
r[4]=0x00000001u;
goto P_0c0948f6;
P_0c0948f6: /* original 68f6, guest PC 0x0c0948f6 */
if(!s->budget--) { s->failed_pc=0x0c0948f6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c0948f8;
P_0c0948f8: /* original 69f6, guest PC 0x0c0948f8 */
if(!s->budget--) { s->failed_pc=0x0c0948f8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c0948fa;
P_0c0948fa: /* original 6af6, guest PC 0x0c0948fa */
if(!s->budget--) { s->failed_pc=0x0c0948fau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0948fc;
P_0c0948fc: /* original 6bf6, guest PC 0x0c0948fc */
if(!s->budget--) { s->failed_pc=0x0c0948fcu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0948fe;
P_0c0948fe: /* original 6cf6, guest PC 0x0c0948fe */
if(!s->budget--) { s->failed_pc=0x0c0948feu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c094900;
P_0c094900: /* original 6df6, guest PC 0x0c094900 */
if(!s->budget--) { s->failed_pc=0x0c094900u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c094902;
P_0c094902: /* original 432b, guest PC 0x0c094902 */
if(!s->budget--) { s->failed_pc=0x0c094902u; return 0; }
target=r[3];
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
P_0c094904: /* original 6ef6, guest PC 0x0c094904 */
if(!s->budget--) { s->failed_pc=0x0c094904u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c094906;
P_0c094906: /* original 4f26, guest PC 0x0c094906 */
if(!s->budget--) { s->failed_pc=0x0c094906u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c094908;
P_0c094908: /* original 68f6, guest PC 0x0c094908 */
if(!s->budget--) { s->failed_pc=0x0c094908u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c09490a;
P_0c09490a: /* original 69f6, guest PC 0x0c09490a */
if(!s->budget--) { s->failed_pc=0x0c09490au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c09490c;
P_0c09490c: /* original 6af6, guest PC 0x0c09490c */
if(!s->budget--) { s->failed_pc=0x0c09490cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c09490e;
P_0c09490e: /* original 6bf6, guest PC 0x0c09490e */
if(!s->budget--) { s->failed_pc=0x0c09490eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c094910;
P_0c094910: /* original 6cf6, guest PC 0x0c094910 */
if(!s->budget--) { s->failed_pc=0x0c094910u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c094912;
P_0c094912: /* original 6df6, guest PC 0x0c094912 */
if(!s->budget--) { s->failed_pc=0x0c094912u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c094914;
P_0c094914: /* original 000b, guest PC 0x0c094914 */
if(!s->budget--) { s->failed_pc=0x0c094914u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c094916: /* original 6ef6, guest PC 0x0c094916 */
if(!s->budget--) { s->failed_pc=0x0c094916u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c094918u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c094918u; return 0; } return 1;
P_0c09493c: /* original 4715, guest PC 0x0c09493c */
if(!s->budget--) { s->failed_pc=0x0c09493cu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[7]>0)!=0);
goto P_0c09493e;
P_0c09493e: /* original 6453, guest PC 0x0c09493e */
if(!s->budget--) { s->failed_pc=0x0c09493eu; return 0; }
r[4]=r[5];
goto P_0c094940;
P_0c094940: /* original 8f15, guest PC 0x0c094940 */
if(!s->budget--) { s->failed_pc=0x0c094940u; return 0; }
cond=r[17]&1u;
r[5]=r[6];
if(!cond) { goto P_0c09496e; }
goto P_0c094944;
P_0c094942: /* original 6563, guest PC 0x0c094942 */
if(!s->budget--) { s->failed_pc=0x0c094942u; return 0; }
r[5]=r[6];
goto P_0c094944;
P_0c094944: /* original f549, guest PC 0x0c094944 */
if(!s->budget--) { s->failed_pc=0x0c094944u; return 0; }
vf3_matrix_load(s,ram,5,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c094946;
P_0c094946: /* original 77ff, guest PC 0x0c094946 */
if(!s->budget--) { s->failed_pc=0x0c094946u; return 0; }
r[7]+=0xffffffffu;
goto P_0c094948;
P_0c094948: /* original 4715, guest PC 0x0c094948 */
if(!s->budget--) { s->failed_pc=0x0c094948u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[7]>0)!=0);
goto P_0c09494a;
P_0c09494a: /* original f649, guest PC 0x0c09494a */
if(!s->budget--) { s->failed_pc=0x0c09494au; return 0; }
vf3_matrix_load(s,ram,6,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c09494c;
P_0c09494c: /* original f749, guest PC 0x0c09494c */
if(!s->budget--) { s->failed_pc=0x0c09494cu; return 0; }
vf3_matrix_load(s,ram,7,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c09494e;
P_0c09494e: /* original f849, guest PC 0x0c09494e */
if(!s->budget--) { s->failed_pc=0x0c09494eu; return 0; }
vf3_matrix_load(s,ram,8,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c094950;
P_0c094950: /* original f949, guest PC 0x0c094950 */
if(!s->budget--) { s->failed_pc=0x0c094950u; return 0; }
vf3_matrix_load(s,ram,9,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c094952;
P_0c094952: /* original f449, guest PC 0x0c094952 */
if(!s->budget--) { s->failed_pc=0x0c094952u; return 0; }
vf3_matrix_load(s,ram,4,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c094954;
P_0c094954: /* original f55a, guest PC 0x0c094954 */
if(!s->budget--) { s->failed_pc=0x0c094954u; return 0; }
vf3_matrix_store(s,ram,5,r[5]);
goto P_0c094956;
P_0c094956: /* original 7504, guest PC 0x0c094956 */
if(!s->budget--) { s->failed_pc=0x0c094956u; return 0; }
r[5]+=0x00000004u;
goto P_0c094958;
P_0c094958: /* original f56a, guest PC 0x0c094958 */
if(!s->budget--) { s->failed_pc=0x0c094958u; return 0; }
vf3_matrix_store(s,ram,6,r[5]);
goto P_0c09495a;
P_0c09495a: /* original 7504, guest PC 0x0c09495a */
if(!s->budget--) { s->failed_pc=0x0c09495au; return 0; }
r[5]+=0x00000004u;
goto P_0c09495c;
P_0c09495c: /* original f57a, guest PC 0x0c09495c */
if(!s->budget--) { s->failed_pc=0x0c09495cu; return 0; }
vf3_matrix_store(s,ram,7,r[5]);
goto P_0c09495e;
P_0c09495e: /* original 7504, guest PC 0x0c09495e */
if(!s->budget--) { s->failed_pc=0x0c09495eu; return 0; }
r[5]+=0x00000004u;
goto P_0c094960;
P_0c094960: /* original f58a, guest PC 0x0c094960 */
if(!s->budget--) { s->failed_pc=0x0c094960u; return 0; }
vf3_matrix_store(s,ram,8,r[5]);
goto P_0c094962;
P_0c094962: /* original 7504, guest PC 0x0c094962 */
if(!s->budget--) { s->failed_pc=0x0c094962u; return 0; }
r[5]+=0x00000004u;
goto P_0c094964;
P_0c094964: /* original f59a, guest PC 0x0c094964 */
if(!s->budget--) { s->failed_pc=0x0c094964u; return 0; }
vf3_matrix_store(s,ram,9,r[5]);
goto P_0c094966;
P_0c094966: /* original 7504, guest PC 0x0c094966 */
if(!s->budget--) { s->failed_pc=0x0c094966u; return 0; }
r[5]+=0x00000004u;
goto P_0c094968;
P_0c094968: /* original f54a, guest PC 0x0c094968 */
if(!s->budget--) { s->failed_pc=0x0c094968u; return 0; }
vf3_matrix_store(s,ram,4,r[5]);
goto P_0c09496a;
P_0c09496a: /* original 8deb, guest PC 0x0c09496a */
if(!s->budget--) { s->failed_pc=0x0c09496au; return 0; }
cond=r[17]&1u;
r[5]+=0x00000004u;
if(cond) { goto P_0c094944; }
goto P_0c09496e;
P_0c09496c: /* original 7504, guest PC 0x0c09496c */
if(!s->budget--) { s->failed_pc=0x0c09496cu; return 0; }
r[5]+=0x00000004u;
goto P_0c09496e;
P_0c09496e: /* original 000b, guest PC 0x0c09496e */
if(!s->budget--) { s->failed_pc=0x0c09496eu; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c094970: /* original 0009, guest PC 0x0c094970 */
if(!s->budget--) { s->failed_pc=0x0c094970u; return 0; }
if(!vf3_matrix_family(0x0c094972u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c094972u; return 0; } return 1;
P_0c094b20: /* original 2fe6, guest PC 0x0c094b20 */
if(!s->budget--) { s->failed_pc=0x0c094b20u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c094b22;
P_0c094b22: /* original 6e43, guest PC 0x0c094b22 */
if(!s->budget--) { s->failed_pc=0x0c094b22u; return 0; }
r[14]=r[4];
goto P_0c094b24;
P_0c094b24: /* original 2fd6, guest PC 0x0c094b24 */
if(!s->budget--) { s->failed_pc=0x0c094b24u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c094b26;
P_0c094b26: /* original 2fc6, guest PC 0x0c094b26 */
if(!s->budget--) { s->failed_pc=0x0c094b26u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c094b28;
P_0c094b28: /* original d70f, guest PC 0x0c094b28 */
if(!s->budget--) { s->failed_pc=0x0c094b28u; return 0; }
r[7]=read(ram,0x0c094b68u,4);
goto P_0c094b2a;
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
if(!vf3_matrix_family(0x0c094b52u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c094b52u; return 0; } return 1;
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
target=code_base|0x0c09493cu; r[16]=code_base|0x0c094c86u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c094c86u) { target=s->pc; goto dispatch; }
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
if(!vf3_matrix_family(0x0c094cb0u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c094cb0u; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
