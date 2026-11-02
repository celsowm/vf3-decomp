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
int vf3_away_batch19_adapter_4(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c042cc0u: goto P_0c042cc0;
case 0x0c042cc2u: goto P_0c042cc2;
case 0x0c042cc4u: goto P_0c042cc4;
case 0x0c042cc6u: goto P_0c042cc6;
case 0x0c042cc8u: goto P_0c042cc8;
case 0x0c042ccau: goto P_0c042cca;
case 0x0c042d7cu: goto P_0c042d7c;
case 0x0c042d7eu: goto P_0c042d7e;
case 0x0c042d80u: goto P_0c042d80;
case 0x0c042d82u: goto P_0c042d82;
case 0x0c042d84u: goto P_0c042d84;
case 0x0c042d86u: goto P_0c042d86;
case 0x0c042d88u: goto P_0c042d88;
case 0x0c042d8au: goto P_0c042d8a;
case 0x0c042d8cu: goto P_0c042d8c;
case 0x0c042d8eu: goto P_0c042d8e;
case 0x0c042d90u: goto P_0c042d90;
case 0x0c042d92u: goto P_0c042d92;
case 0x0c042d94u: goto P_0c042d94;
case 0x0c042d96u: goto P_0c042d96;
case 0x0c042d98u: goto P_0c042d98;
case 0x0c042d9au: goto P_0c042d9a;
case 0x0c042d9cu: goto P_0c042d9c;
case 0x0c042d9eu: goto P_0c042d9e;
case 0x0c042da0u: goto P_0c042da0;
case 0x0c042da2u: goto P_0c042da2;
case 0x0c042da4u: goto P_0c042da4;
case 0x0c042da6u: goto P_0c042da6;
case 0x0c042da8u: goto P_0c042da8;
case 0x0c042daau: goto P_0c042daa;
case 0x0c042dacu: goto P_0c042dac;
case 0x0c042daeu: goto P_0c042dae;
case 0x0c042db0u: goto P_0c042db0;
case 0x0c042db2u: goto P_0c042db2;
case 0x0c042db4u: goto P_0c042db4;
case 0x0c042db6u: goto P_0c042db6;
case 0x0c042db8u: goto P_0c042db8;
case 0x0c042dbau: goto P_0c042dba;
case 0x0c042dbcu: goto P_0c042dbc;
case 0x0c042dbeu: goto P_0c042dbe;
case 0x0c042dc0u: goto P_0c042dc0;
case 0x0c042dc2u: goto P_0c042dc2;
case 0x0c042dc4u: goto P_0c042dc4;
case 0x0c042dc6u: goto P_0c042dc6;
case 0x0c042dc8u: goto P_0c042dc8;
case 0x0c042dcau: goto P_0c042dca;
case 0x0c042dccu: goto P_0c042dcc;
case 0x0c042dceu: goto P_0c042dce;
case 0x0c042dd0u: goto P_0c042dd0;
case 0x0c042dd2u: goto P_0c042dd2;
case 0x0c042dd4u: goto P_0c042dd4;
case 0x0c042dd6u: goto P_0c042dd6;
case 0x0c042dd8u: goto P_0c042dd8;
case 0x0c042ddau: goto P_0c042dda;
case 0x0c042ddcu: goto P_0c042ddc;
case 0x0c042ddeu: goto P_0c042dde;
case 0x0c042de0u: goto P_0c042de0;
case 0x0c042de2u: goto P_0c042de2;
case 0x0c042de4u: goto P_0c042de4;
case 0x0c042de6u: goto P_0c042de6;
case 0x0c042de8u: goto P_0c042de8;
case 0x0c042deau: goto P_0c042dea;
case 0x0c042decu: goto P_0c042dec;
case 0x0c042deeu: goto P_0c042dee;
case 0x0c042df0u: goto P_0c042df0;
case 0x0c042df2u: goto P_0c042df2;
case 0x0c042df4u: goto P_0c042df4;
case 0x0c042df6u: goto P_0c042df6;
case 0x0c042df8u: goto P_0c042df8;
case 0x0c042dfau: goto P_0c042dfa;
case 0x0c042dfcu: goto P_0c042dfc;
case 0x0c042dfeu: goto P_0c042dfe;
case 0x0c042e00u: goto P_0c042e00;
case 0x0c042e02u: goto P_0c042e02;
case 0x0c042e04u: goto P_0c042e04;
case 0x0c042e06u: goto P_0c042e06;
case 0x0c042e08u: goto P_0c042e08;
case 0x0c042e0au: goto P_0c042e0a;
case 0x0c042e0cu: goto P_0c042e0c;
case 0x0c042e0eu: goto P_0c042e0e;
case 0x0c042e10u: goto P_0c042e10;
case 0x0c042e12u: goto P_0c042e12;
case 0x0c042e14u: goto P_0c042e14;
case 0x0c042e16u: goto P_0c042e16;
case 0x0c042e18u: goto P_0c042e18;
case 0x0c042e1au: goto P_0c042e1a;
case 0x0c042e1cu: goto P_0c042e1c;
case 0x0c042e1eu: goto P_0c042e1e;
case 0x0c042e20u: goto P_0c042e20;
case 0x0c042e22u: goto P_0c042e22;
case 0x0c042e24u: goto P_0c042e24;
case 0x0c042e26u: goto P_0c042e26;
case 0x0c042e28u: goto P_0c042e28;
case 0x0c042e2au: goto P_0c042e2a;
case 0x0c042e2cu: goto P_0c042e2c;
case 0x0c042e2eu: goto P_0c042e2e;
case 0x0c042e30u: goto P_0c042e30;
case 0x0c042e32u: goto P_0c042e32;
case 0x0c042e34u: goto P_0c042e34;
case 0x0c042e36u: goto P_0c042e36;
case 0x0c042e38u: goto P_0c042e38;
case 0x0c042e3au: goto P_0c042e3a;
case 0x0c042efcu: goto P_0c042efc;
case 0x0c042efeu: goto P_0c042efe;
case 0x0c042f00u: goto P_0c042f00;
case 0x0c042f02u: goto P_0c042f02;
case 0x0c042f04u: goto P_0c042f04;
case 0x0c042f06u: goto P_0c042f06;
case 0x0c059840u: goto P_0c059840;
case 0x0c059842u: goto P_0c059842;
case 0x0c059844u: goto P_0c059844;
case 0x0c059846u: goto P_0c059846;
case 0x0c059848u: goto P_0c059848;
case 0x0c05984au: goto P_0c05984a;
case 0x0c05984cu: goto P_0c05984c;
case 0x0c05984eu: goto P_0c05984e;
case 0x0c059850u: goto P_0c059850;
case 0x0c059852u: goto P_0c059852;
case 0x0c059854u: goto P_0c059854;
case 0x0c059856u: goto P_0c059856;
case 0x0c059858u: goto P_0c059858;
case 0x0c05985au: goto P_0c05985a;
case 0x0c05985cu: goto P_0c05985c;
case 0x0c05985eu: goto P_0c05985e;
case 0x0c059860u: goto P_0c059860;
case 0x0c059862u: goto P_0c059862;
case 0x0c059864u: goto P_0c059864;
case 0x0c059866u: goto P_0c059866;
case 0x0c059868u: goto P_0c059868;
case 0x0c05986au: goto P_0c05986a;
case 0x0c05986cu: goto P_0c05986c;
case 0x0c05986eu: goto P_0c05986e;
case 0x0c059870u: goto P_0c059870;
case 0x0c059872u: goto P_0c059872;
case 0x0c059874u: goto P_0c059874;
case 0x0c059876u: goto P_0c059876;
case 0x0c059878u: goto P_0c059878;
case 0x0c05987au: goto P_0c05987a;
case 0x0c05987cu: goto P_0c05987c;
case 0x0c05987eu: goto P_0c05987e;
case 0x0c059880u: goto P_0c059880;
case 0x0c059882u: goto P_0c059882;
case 0x0c059884u: goto P_0c059884;
case 0x0c059886u: goto P_0c059886;
case 0x0c059888u: goto P_0c059888;
case 0x0c05988au: goto P_0c05988a;
case 0x0c05988cu: goto P_0c05988c;
case 0x0c05988eu: goto P_0c05988e;
case 0x0c059890u: goto P_0c059890;
case 0x0c059892u: goto P_0c059892;
case 0x0c059894u: goto P_0c059894;
case 0x0c059a20u: goto P_0c059a20;
case 0x0c059a22u: goto P_0c059a22;
case 0x0c059a24u: goto P_0c059a24;
case 0x0c059a26u: goto P_0c059a26;
case 0x0c059a28u: goto P_0c059a28;
case 0x0c059a2au: goto P_0c059a2a;
case 0x0c059a2cu: goto P_0c059a2c;
case 0x0c059a2eu: goto P_0c059a2e;
case 0x0c059a30u: goto P_0c059a30;
case 0x0c059a32u: goto P_0c059a32;
case 0x0c059a34u: goto P_0c059a34;
case 0x0c059a36u: goto P_0c059a36;
case 0x0c059a38u: goto P_0c059a38;
case 0x0c059a3au: goto P_0c059a3a;
case 0x0c059a3cu: goto P_0c059a3c;
case 0x0c059a3eu: goto P_0c059a3e;
case 0x0c059a40u: goto P_0c059a40;
case 0x0c059a42u: goto P_0c059a42;
case 0x0c059a44u: goto P_0c059a44;
case 0x0c059a46u: goto P_0c059a46;
case 0x0c059a48u: goto P_0c059a48;
case 0x0c059a4au: goto P_0c059a4a;
case 0x0c059a4cu: goto P_0c059a4c;
case 0x0c059a4eu: goto P_0c059a4e;
case 0x0c059a50u: goto P_0c059a50;
case 0x0c059a52u: goto P_0c059a52;
case 0x0c059a54u: goto P_0c059a54;
case 0x0c059a56u: goto P_0c059a56;
case 0x0c059a58u: goto P_0c059a58;
case 0x0c059a5au: goto P_0c059a5a;
case 0x0c059a5cu: goto P_0c059a5c;
case 0x0c059a5eu: goto P_0c059a5e;
case 0x0c059a60u: goto P_0c059a60;
case 0x0c059a62u: goto P_0c059a62;
case 0x0c059a64u: goto P_0c059a64;
case 0x0c059a66u: goto P_0c059a66;
case 0x0c059a68u: goto P_0c059a68;
case 0x0c059a6au: goto P_0c059a6a;
case 0x0c059a6cu: goto P_0c059a6c;
case 0x0c059a6eu: goto P_0c059a6e;
case 0x0c059a70u: goto P_0c059a70;
case 0x0c059a72u: goto P_0c059a72;
case 0x0c059a74u: goto P_0c059a74;
case 0x0c059a76u: goto P_0c059a76;
case 0x0c059a78u: goto P_0c059a78;
case 0x0c059a7au: goto P_0c059a7a;
case 0x0c059a7cu: goto P_0c059a7c;
case 0x0c059a7eu: goto P_0c059a7e;
case 0x0c059a80u: goto P_0c059a80;
case 0x0c059a82u: goto P_0c059a82;
case 0x0c059a84u: goto P_0c059a84;
case 0x0c059a86u: goto P_0c059a86;
case 0x0c059a88u: goto P_0c059a88;
case 0x0c059a8au: goto P_0c059a8a;
case 0x0c059a8cu: goto P_0c059a8c;
case 0x0c059a8eu: goto P_0c059a8e;
case 0x0c059a90u: goto P_0c059a90;
case 0x0c059a92u: goto P_0c059a92;
case 0x0c059a94u: goto P_0c059a94;
case 0x0c059a96u: goto P_0c059a96;
case 0x0c059a98u: goto P_0c059a98;
case 0x0c059a9au: goto P_0c059a9a;
case 0x0c059a9cu: goto P_0c059a9c;
case 0x0c059a9eu: goto P_0c059a9e;
case 0x0c059aa0u: goto P_0c059aa0;
case 0x0c059aa2u: goto P_0c059aa2;
case 0x0c059aa4u: goto P_0c059aa4;
case 0x0c059aa6u: goto P_0c059aa6;
case 0x0c059aa8u: goto P_0c059aa8;
case 0x0c059aaau: goto P_0c059aaa;
case 0x0c059aacu: goto P_0c059aac;
case 0x0c059aaeu: goto P_0c059aae;
case 0x0c059ab0u: goto P_0c059ab0;
case 0x0c059ab2u: goto P_0c059ab2;
case 0x0c059ab4u: goto P_0c059ab4;
case 0x0c059ab6u: goto P_0c059ab6;
case 0x0c059ab8u: goto P_0c059ab8;
case 0x0c059abau: goto P_0c059aba;
case 0x0c059abcu: goto P_0c059abc;
case 0x0c059abeu: goto P_0c059abe;
case 0x0c059ac0u: goto P_0c059ac0;
case 0x0c059ac2u: goto P_0c059ac2;
case 0x0c059ac4u: goto P_0c059ac4;
case 0x0c059ac6u: goto P_0c059ac6;
case 0x0c059ac8u: goto P_0c059ac8;
case 0x0c059acau: goto P_0c059aca;
case 0x0c059accu: goto P_0c059acc;
case 0x0c059aceu: goto P_0c059ace;
case 0x0c059ad0u: goto P_0c059ad0;
case 0x0c059ad2u: goto P_0c059ad2;
case 0x0c059ad4u: goto P_0c059ad4;
case 0x0c059ad6u: goto P_0c059ad6;
default: return vf3_matrix_family(target,s,ram);
}
P_0c042cc0: /* original d102, guest PC 0x0c042cc0 */
if(!s->budget--) { s->failed_pc=0x0c042cc0u; return 0; }
r[1]=read(ram,0x0c042cccu,4);
goto P_0c042cc2;
P_0c042cc2: /* original d203, guest PC 0x0c042cc2 */
if(!s->budget--) { s->failed_pc=0x0c042cc2u; return 0; }
r[2]=read(ram,0x0c042cd0u,4);
goto P_0c042cc4;
P_0c042cc4: /* original e000, guest PC 0x0c042cc4 */
if(!s->budget--) { s->failed_pc=0x0c042cc4u; return 0; }
r[0]=0x00000000u;
goto P_0c042cc6;
P_0c042cc6: /* original 2122, guest PC 0x0c042cc6 */
if(!s->budget--) { s->failed_pc=0x0c042cc6u; return 0; }
write(ram,r[1],r[2],4);
goto P_0c042cc8;
P_0c042cc8: /* original 000b, guest PC 0x0c042cc8 */
if(!s->budget--) { s->failed_pc=0x0c042cc8u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[2]=tmp;
s->pc=target; return ram->oob==0;
P_0c042cca: /* original 62f6, guest PC 0x0c042cca */
if(!s->budget--) { s->failed_pc=0x0c042ccau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[2]=tmp;
if(!vf3_matrix_family(0x0c042cccu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c042cccu; return 0; } return 1;
P_0c042d7c: /* original 2008, guest PC 0x0c042d7c */
if(!s->budget--) { s->failed_pc=0x0c042d7cu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c042d7e;
P_0c042d7e: /* original 2f26, guest PC 0x0c042d7e */
if(!s->budget--) { s->failed_pc=0x0c042d7eu; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c042d80;
P_0c042d80: /* original 8d56, guest PC 0x0c042d80 */
if(!s->budget--) { s->failed_pc=0x0c042d80u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c042e30; }
goto P_0c042d84;
P_0c042d82: /* original 0009, guest PC 0x0c042d82 */
if(!s->budget--) { s->failed_pc=0x0c042d82u; return 0; }
goto P_0c042d84;
P_0c042d84: /* original 2f36, guest PC 0x0c042d84 */
if(!s->budget--) { s->failed_pc=0x0c042d84u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c042d86;
P_0c042d86: /* original e200, guest PC 0x0c042d86 */
if(!s->budget--) { s->failed_pc=0x0c042d86u; return 0; }
r[2]=0x00000000u;
goto P_0c042d88;
P_0c042d88: /* original 2f46, guest PC 0x0c042d88 */
if(!s->budget--) { s->failed_pc=0x0c042d88u; return 0; }
tmp=r[4]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c042d8a;
P_0c042d8a: /* original 2127, guest PC 0x0c042d8a */
if(!s->budget--) { s->failed_pc=0x0c042d8au; return 0; }
r[17]=(r[17]&~0x301u)|((r[1]>>31)<<8)|((r[2]>>31)<<9)|(((r[1]^r[2])>>31)&1u);
goto P_0c042d8c;
P_0c042d8c: /* original 0429, guest PC 0x0c042d8c */
if(!s->budget--) { s->failed_pc=0x0c042d8cu; return 0; }
r[4]=r[17]&1u;
goto P_0c042d8e;
P_0c042d8e: /* original 333a, guest PC 0x0c042d8e */
if(!s->budget--) { s->failed_pc=0x0c042d8eu; return 0; }
wide=(uint64_t)r[3]-r[3]-(r[17]&1u); r[3]=(uint32_t)wide;
r[17]=(r[17]&~1u)|((wide>>32)!=0);
goto P_0c042d90;
P_0c042d90: /* original 312a, guest PC 0x0c042d90 */
if(!s->budget--) { s->failed_pc=0x0c042d90u; return 0; }
wide=(uint64_t)r[1]-r[2]-(r[17]&1u); r[1]=(uint32_t)wide;
r[17]=(r[17]&~1u)|((wide>>32)!=0);
goto P_0c042d92;
P_0c042d92: /* original 2307, guest PC 0x0c042d92 */
if(!s->budget--) { s->failed_pc=0x0c042d92u; return 0; }
r[17]=(r[17]&~0x301u)|((r[3]>>31)<<8)|((r[0]>>31)<<9)|(((r[3]^r[0])>>31)&1u);
goto P_0c042d94;
P_0c042d94: /* original 4124, guest PC 0x0c042d94 */
if(!s->budget--) { s->failed_pc=0x0c042d94u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042d96;
P_0c042d96: /* original 3304, guest PC 0x0c042d96 */
if(!s->budget--) { s->failed_pc=0x0c042d96u; return 0; }
divide_step(s,3,0);
goto P_0c042d98;
P_0c042d98: /* original 4124, guest PC 0x0c042d98 */
if(!s->budget--) { s->failed_pc=0x0c042d98u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042d9a;
P_0c042d9a: /* original 3304, guest PC 0x0c042d9a */
if(!s->budget--) { s->failed_pc=0x0c042d9au; return 0; }
divide_step(s,3,0);
goto P_0c042d9c;
P_0c042d9c: /* original 4124, guest PC 0x0c042d9c */
if(!s->budget--) { s->failed_pc=0x0c042d9cu; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042d9e;
P_0c042d9e: /* original 3304, guest PC 0x0c042d9e */
if(!s->budget--) { s->failed_pc=0x0c042d9eu; return 0; }
divide_step(s,3,0);
goto P_0c042da0;
P_0c042da0: /* original 4124, guest PC 0x0c042da0 */
if(!s->budget--) { s->failed_pc=0x0c042da0u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042da2;
P_0c042da2: /* original 3304, guest PC 0x0c042da2 */
if(!s->budget--) { s->failed_pc=0x0c042da2u; return 0; }
divide_step(s,3,0);
goto P_0c042da4;
P_0c042da4: /* original 4124, guest PC 0x0c042da4 */
if(!s->budget--) { s->failed_pc=0x0c042da4u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042da6;
P_0c042da6: /* original 3304, guest PC 0x0c042da6 */
if(!s->budget--) { s->failed_pc=0x0c042da6u; return 0; }
divide_step(s,3,0);
goto P_0c042da8;
P_0c042da8: /* original 4124, guest PC 0x0c042da8 */
if(!s->budget--) { s->failed_pc=0x0c042da8u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042daa;
P_0c042daa: /* original 3304, guest PC 0x0c042daa */
if(!s->budget--) { s->failed_pc=0x0c042daau; return 0; }
divide_step(s,3,0);
goto P_0c042dac;
P_0c042dac: /* original 4124, guest PC 0x0c042dac */
if(!s->budget--) { s->failed_pc=0x0c042dacu; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042dae;
P_0c042dae: /* original 3304, guest PC 0x0c042dae */
if(!s->budget--) { s->failed_pc=0x0c042daeu; return 0; }
divide_step(s,3,0);
goto P_0c042db0;
P_0c042db0: /* original 4124, guest PC 0x0c042db0 */
if(!s->budget--) { s->failed_pc=0x0c042db0u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042db2;
P_0c042db2: /* original 3304, guest PC 0x0c042db2 */
if(!s->budget--) { s->failed_pc=0x0c042db2u; return 0; }
divide_step(s,3,0);
goto P_0c042db4;
P_0c042db4: /* original 4124, guest PC 0x0c042db4 */
if(!s->budget--) { s->failed_pc=0x0c042db4u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042db6;
P_0c042db6: /* original 3304, guest PC 0x0c042db6 */
if(!s->budget--) { s->failed_pc=0x0c042db6u; return 0; }
divide_step(s,3,0);
goto P_0c042db8;
P_0c042db8: /* original 4124, guest PC 0x0c042db8 */
if(!s->budget--) { s->failed_pc=0x0c042db8u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042dba;
P_0c042dba: /* original 3304, guest PC 0x0c042dba */
if(!s->budget--) { s->failed_pc=0x0c042dbau; return 0; }
divide_step(s,3,0);
goto P_0c042dbc;
P_0c042dbc: /* original 4124, guest PC 0x0c042dbc */
if(!s->budget--) { s->failed_pc=0x0c042dbcu; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042dbe;
P_0c042dbe: /* original 3304, guest PC 0x0c042dbe */
if(!s->budget--) { s->failed_pc=0x0c042dbeu; return 0; }
divide_step(s,3,0);
goto P_0c042dc0;
P_0c042dc0: /* original 4124, guest PC 0x0c042dc0 */
if(!s->budget--) { s->failed_pc=0x0c042dc0u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042dc2;
P_0c042dc2: /* original 3304, guest PC 0x0c042dc2 */
if(!s->budget--) { s->failed_pc=0x0c042dc2u; return 0; }
divide_step(s,3,0);
goto P_0c042dc4;
P_0c042dc4: /* original 4124, guest PC 0x0c042dc4 */
if(!s->budget--) { s->failed_pc=0x0c042dc4u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042dc6;
P_0c042dc6: /* original 3304, guest PC 0x0c042dc6 */
if(!s->budget--) { s->failed_pc=0x0c042dc6u; return 0; }
divide_step(s,3,0);
goto P_0c042dc8;
P_0c042dc8: /* original 4124, guest PC 0x0c042dc8 */
if(!s->budget--) { s->failed_pc=0x0c042dc8u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042dca;
P_0c042dca: /* original 3304, guest PC 0x0c042dca */
if(!s->budget--) { s->failed_pc=0x0c042dcau; return 0; }
divide_step(s,3,0);
goto P_0c042dcc;
P_0c042dcc: /* original 4124, guest PC 0x0c042dcc */
if(!s->budget--) { s->failed_pc=0x0c042dccu; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042dce;
P_0c042dce: /* original 3304, guest PC 0x0c042dce */
if(!s->budget--) { s->failed_pc=0x0c042dceu; return 0; }
divide_step(s,3,0);
goto P_0c042dd0;
P_0c042dd0: /* original 4124, guest PC 0x0c042dd0 */
if(!s->budget--) { s->failed_pc=0x0c042dd0u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042dd2;
P_0c042dd2: /* original 3304, guest PC 0x0c042dd2 */
if(!s->budget--) { s->failed_pc=0x0c042dd2u; return 0; }
divide_step(s,3,0);
goto P_0c042dd4;
P_0c042dd4: /* original 4124, guest PC 0x0c042dd4 */
if(!s->budget--) { s->failed_pc=0x0c042dd4u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042dd6;
P_0c042dd6: /* original 3304, guest PC 0x0c042dd6 */
if(!s->budget--) { s->failed_pc=0x0c042dd6u; return 0; }
divide_step(s,3,0);
goto P_0c042dd8;
P_0c042dd8: /* original 4124, guest PC 0x0c042dd8 */
if(!s->budget--) { s->failed_pc=0x0c042dd8u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042dda;
P_0c042dda: /* original 3304, guest PC 0x0c042dda */
if(!s->budget--) { s->failed_pc=0x0c042ddau; return 0; }
divide_step(s,3,0);
goto P_0c042ddc;
P_0c042ddc: /* original 4124, guest PC 0x0c042ddc */
if(!s->budget--) { s->failed_pc=0x0c042ddcu; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042dde;
P_0c042dde: /* original 3304, guest PC 0x0c042dde */
if(!s->budget--) { s->failed_pc=0x0c042ddeu; return 0; }
divide_step(s,3,0);
goto P_0c042de0;
P_0c042de0: /* original 4124, guest PC 0x0c042de0 */
if(!s->budget--) { s->failed_pc=0x0c042de0u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042de2;
P_0c042de2: /* original 3304, guest PC 0x0c042de2 */
if(!s->budget--) { s->failed_pc=0x0c042de2u; return 0; }
divide_step(s,3,0);
goto P_0c042de4;
P_0c042de4: /* original 4124, guest PC 0x0c042de4 */
if(!s->budget--) { s->failed_pc=0x0c042de4u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042de6;
P_0c042de6: /* original 3304, guest PC 0x0c042de6 */
if(!s->budget--) { s->failed_pc=0x0c042de6u; return 0; }
divide_step(s,3,0);
goto P_0c042de8;
P_0c042de8: /* original 4124, guest PC 0x0c042de8 */
if(!s->budget--) { s->failed_pc=0x0c042de8u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042dea;
P_0c042dea: /* original 3304, guest PC 0x0c042dea */
if(!s->budget--) { s->failed_pc=0x0c042deau; return 0; }
divide_step(s,3,0);
goto P_0c042dec;
P_0c042dec: /* original 4124, guest PC 0x0c042dec */
if(!s->budget--) { s->failed_pc=0x0c042decu; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042dee;
P_0c042dee: /* original 3304, guest PC 0x0c042dee */
if(!s->budget--) { s->failed_pc=0x0c042deeu; return 0; }
divide_step(s,3,0);
goto P_0c042df0;
P_0c042df0: /* original 4124, guest PC 0x0c042df0 */
if(!s->budget--) { s->failed_pc=0x0c042df0u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042df2;
P_0c042df2: /* original 3304, guest PC 0x0c042df2 */
if(!s->budget--) { s->failed_pc=0x0c042df2u; return 0; }
divide_step(s,3,0);
goto P_0c042df4;
P_0c042df4: /* original 4124, guest PC 0x0c042df4 */
if(!s->budget--) { s->failed_pc=0x0c042df4u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042df6;
P_0c042df6: /* original 3304, guest PC 0x0c042df6 */
if(!s->budget--) { s->failed_pc=0x0c042df6u; return 0; }
divide_step(s,3,0);
goto P_0c042df8;
P_0c042df8: /* original 4124, guest PC 0x0c042df8 */
if(!s->budget--) { s->failed_pc=0x0c042df8u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042dfa;
P_0c042dfa: /* original 3304, guest PC 0x0c042dfa */
if(!s->budget--) { s->failed_pc=0x0c042dfau; return 0; }
divide_step(s,3,0);
goto P_0c042dfc;
P_0c042dfc: /* original 4124, guest PC 0x0c042dfc */
if(!s->budget--) { s->failed_pc=0x0c042dfcu; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042dfe;
P_0c042dfe: /* original 3304, guest PC 0x0c042dfe */
if(!s->budget--) { s->failed_pc=0x0c042dfeu; return 0; }
divide_step(s,3,0);
goto P_0c042e00;
P_0c042e00: /* original 4124, guest PC 0x0c042e00 */
if(!s->budget--) { s->failed_pc=0x0c042e00u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042e02;
P_0c042e02: /* original 3304, guest PC 0x0c042e02 */
if(!s->budget--) { s->failed_pc=0x0c042e02u; return 0; }
divide_step(s,3,0);
goto P_0c042e04;
P_0c042e04: /* original 4124, guest PC 0x0c042e04 */
if(!s->budget--) { s->failed_pc=0x0c042e04u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042e06;
P_0c042e06: /* original 3304, guest PC 0x0c042e06 */
if(!s->budget--) { s->failed_pc=0x0c042e06u; return 0; }
divide_step(s,3,0);
goto P_0c042e08;
P_0c042e08: /* original 4124, guest PC 0x0c042e08 */
if(!s->budget--) { s->failed_pc=0x0c042e08u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042e0a;
P_0c042e0a: /* original 3304, guest PC 0x0c042e0a */
if(!s->budget--) { s->failed_pc=0x0c042e0au; return 0; }
divide_step(s,3,0);
goto P_0c042e0c;
P_0c042e0c: /* original 4124, guest PC 0x0c042e0c */
if(!s->budget--) { s->failed_pc=0x0c042e0cu; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042e0e;
P_0c042e0e: /* original 3304, guest PC 0x0c042e0e */
if(!s->budget--) { s->failed_pc=0x0c042e0eu; return 0; }
divide_step(s,3,0);
goto P_0c042e10;
P_0c042e10: /* original 4124, guest PC 0x0c042e10 */
if(!s->budget--) { s->failed_pc=0x0c042e10u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042e12;
P_0c042e12: /* original 3304, guest PC 0x0c042e12 */
if(!s->budget--) { s->failed_pc=0x0c042e12u; return 0; }
divide_step(s,3,0);
goto P_0c042e14;
P_0c042e14: /* original 2327, guest PC 0x0c042e14 */
if(!s->budget--) { s->failed_pc=0x0c042e14u; return 0; }
r[17]=(r[17]&~0x301u)|((r[3]>>31)<<8)|((r[2]>>31)<<9)|(((r[3]^r[2])>>31)&1u);
goto P_0c042e16;
P_0c042e16: /* original 0229, guest PC 0x0c042e16 */
if(!s->budget--) { s->failed_pc=0x0c042e16u; return 0; }
r[2]=r[17]&1u;
goto P_0c042e18;
P_0c042e18: /* original 224a, guest PC 0x0c042e18 */
if(!s->budget--) { s->failed_pc=0x0c042e18u; return 0; }
r[2]^=r[4];
goto P_0c042e1a;
P_0c042e1a: /* original 4225, guest PC 0x0c042e1a */
if(!s->budget--) { s->failed_pc=0x0c042e1au; return 0; }
tmp=r[2]&1u; r[2]=(r[2]>>1)|((r[17]&1u)<<31);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042e1c;
P_0c042e1c: /* original 8b02, guest PC 0x0c042e1c */
if(!s->budget--) { s->failed_pc=0x0c042e1cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c042e24; }
goto P_0c042e1e;
P_0c042e1e: /* original 2307, guest PC 0x0c042e1e */
if(!s->budget--) { s->failed_pc=0x0c042e1eu; return 0; }
r[17]=(r[17]&~0x301u)|((r[3]>>31)<<8)|((r[0]>>31)<<9)|(((r[3]^r[0])>>31)&1u);
goto P_0c042e20;
P_0c042e20: /* original 4321, guest PC 0x0c042e20 */
if(!s->budget--) { s->failed_pc=0x0c042e20u; return 0; }
r[17]=(r[17]&~1u)|((r[3]&1)!=0);
r[3]=(uint32_t)((int32_t)r[3]>>1);
goto P_0c042e22;
P_0c042e22: /* original 3304, guest PC 0x0c042e22 */
if(!s->budget--) { s->failed_pc=0x0c042e22u; return 0; }
divide_step(s,3,0);
goto P_0c042e24;
P_0c042e24: /* original 334c, guest PC 0x0c042e24 */
if(!s->budget--) { s->failed_pc=0x0c042e24u; return 0; }
r[3]+=r[4];
goto P_0c042e26;
P_0c042e26: /* original 6033, guest PC 0x0c042e26 */
if(!s->budget--) { s->failed_pc=0x0c042e26u; return 0; }
r[0]=r[3];
goto P_0c042e28;
P_0c042e28: /* original 64f6, guest PC 0x0c042e28 */
if(!s->budget--) { s->failed_pc=0x0c042e28u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[4]=tmp;
goto P_0c042e2a;
P_0c042e2a: /* original 63f6, guest PC 0x0c042e2a */
if(!s->budget--) { s->failed_pc=0x0c042e2au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[3]=tmp;
goto P_0c042e2c;
P_0c042e2c: /* original 000b, guest PC 0x0c042e2c */
if(!s->budget--) { s->failed_pc=0x0c042e2cu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[2]=tmp;
s->pc=target; return ram->oob==0;
P_0c042e2e: /* original 62f6, guest PC 0x0c042e2e */
if(!s->budget--) { s->failed_pc=0x0c042e2eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[2]=tmp;
goto P_0c042e30;
P_0c042e30: /* original d102, guest PC 0x0c042e30 */
if(!s->budget--) { s->failed_pc=0x0c042e30u; return 0; }
r[1]=read(ram,0x0c042e3cu,4);
goto P_0c042e32;
P_0c042e32: /* original d203, guest PC 0x0c042e32 */
if(!s->budget--) { s->failed_pc=0x0c042e32u; return 0; }
r[2]=read(ram,0x0c042e40u,4);
goto P_0c042e34;
P_0c042e34: /* original e000, guest PC 0x0c042e34 */
if(!s->budget--) { s->failed_pc=0x0c042e34u; return 0; }
r[0]=0x00000000u;
goto P_0c042e36;
P_0c042e36: /* original 2122, guest PC 0x0c042e36 */
if(!s->budget--) { s->failed_pc=0x0c042e36u; return 0; }
write(ram,r[1],r[2],4);
goto P_0c042e38;
P_0c042e38: /* original 000b, guest PC 0x0c042e38 */
if(!s->budget--) { s->failed_pc=0x0c042e38u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[2]=tmp;
s->pc=target; return ram->oob==0;
P_0c042e3a: /* original 62f6, guest PC 0x0c042e3a */
if(!s->budget--) { s->failed_pc=0x0c042e3au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[2]=tmp;
if(!vf3_matrix_family(0x0c042e3cu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c042e3cu; return 0; } return 1;
P_0c042efc: /* original 2f36, guest PC 0x0c042efc */
if(!s->budget--) { s->failed_pc=0x0c042efcu; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c042efe;
P_0c042efe: /* original d305, guest PC 0x0c042efe */
if(!s->budget--) { s->failed_pc=0x0c042efeu; return 0; }
r[3]=read(ram,0x0c042f14u,4);
goto P_0c042f00;
P_0c042f00: /* original 033e, guest PC 0x0c042f00 */
if(!s->budget--) { s->failed_pc=0x0c042f00u; return 0; }
r[3]=read(ram,r[3]+r[0],4);
goto P_0c042f02;
P_0c042f02: /* original 70fc, guest PC 0x0c042f02 */
if(!s->budget--) { s->failed_pc=0x0c042f02u; return 0; }
r[0]+=0xfffffffcu;
goto P_0c042f04;
P_0c042f04: /* original 432b, guest PC 0x0c042f04 */
if(!s->budget--) { s->failed_pc=0x0c042f04u; return 0; }
target=r[3];
r[0]=read(ram,r[2]+r[0],4);
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
P_0c042f06: /* original 002e, guest PC 0x0c042f06 */
if(!s->budget--) { s->failed_pc=0x0c042f06u; return 0; }
r[0]=read(ram,r[2]+r[0],4);
if(!vf3_matrix_family(0x0c042f08u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c042f08u; return 0; } return 1;
P_0c059840: /* original 2fe6, guest PC 0x0c059840 */
if(!s->budget--) { s->failed_pc=0x0c059840u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c059842;
P_0c059842: /* original 2fd6, guest PC 0x0c059842 */
if(!s->budget--) { s->failed_pc=0x0c059842u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c059844;
P_0c059844: /* original 2fc6, guest PC 0x0c059844 */
if(!s->budget--) { s->failed_pc=0x0c059844u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c059846;
P_0c059846: /* original 2fb6, guest PC 0x0c059846 */
if(!s->budget--) { s->failed_pc=0x0c059846u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c059848;
P_0c059848: /* original 4f22, guest PC 0x0c059848 */
if(!s->budget--) { s->failed_pc=0x0c059848u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c05984a;
P_0c05984a: /* original d32a, guest PC 0x0c05984a */
if(!s->budget--) { s->failed_pc=0x0c05984au; return 0; }
r[3]=read(ram,0x0c0598f4u,4);
goto P_0c05984c;
P_0c05984c: /* original de2a, guest PC 0x0c05984c */
if(!s->budget--) { s->failed_pc=0x0c05984cu; return 0; }
r[14]=read(ram,0x0c0598f8u,4);
goto P_0c05984e;
P_0c05984e: /* original 6432, guest PC 0x0c05984e */
if(!s->budget--) { s->failed_pc=0x0c05984eu; return 0; }
tmp=read(ram,r[3],4);
r[4]=tmp;
goto P_0c059850;
P_0c059850: /* original d22a, guest PC 0x0c059850 */
if(!s->budget--) { s->failed_pc=0x0c059850u; return 0; }
r[2]=read(ram,0x0c0598fcu,4);
goto P_0c059852;
P_0c059852: /* original 6442, guest PC 0x0c059852 */
if(!s->budget--) { s->failed_pc=0x0c059852u; return 0; }
tmp=read(ram,r[4],4);
r[4]=tmp;
goto P_0c059854;
P_0c059854: /* original 6543, guest PC 0x0c059854 */
if(!s->budget--) { s->failed_pc=0x0c059854u; return 0; }
r[5]=r[4];
goto P_0c059856;
P_0c059856: /* original 4529, guest PC 0x0c059856 */
if(!s->budget--) { s->failed_pc=0x0c059856u; return 0; }
r[5]>>=16;
goto P_0c059858;
P_0c059858: /* original 4519, guest PC 0x0c059858 */
if(!s->budget--) { s->failed_pc=0x0c059858u; return 0; }
r[5]>>=8;
goto P_0c05985a;
P_0c05985a: /* original 2252, guest PC 0x0c05985a */
if(!s->budget--) { s->failed_pc=0x0c05985au; return 0; }
write(ram,r[2],r[5],4);
goto P_0c05985c;
P_0c05985c: /* original d128, guest PC 0x0c05985c */
if(!s->budget--) { s->failed_pc=0x0c05985cu; return 0; }
r[1]=read(ram,0x0c059900u,4);
goto P_0c05985e;
P_0c05985e: /* original 2152, guest PC 0x0c05985e */
if(!s->budget--) { s->failed_pc=0x0c05985eu; return 0; }
write(ram,r[1],r[5],4);
goto P_0c059860;
P_0c059860: /* original dd28, guest PC 0x0c059860 */
if(!s->budget--) { s->failed_pc=0x0c059860u; return 0; }
r[13]=read(ram,0x0c059904u,4);
goto P_0c059862;
P_0c059862: /* original ec04, guest PC 0x0c059862 */
if(!s->budget--) { s->failed_pc=0x0c059862u; return 0; }
r[12]=0x00000004u;
goto P_0c059864;
P_0c059864: /* original d328, guest PC 0x0c059864 */
if(!s->budget--) { s->failed_pc=0x0c059864u; return 0; }
r[3]=read(ram,0x0c059908u,4);
goto P_0c059866;
P_0c059866: /* original 2d49, guest PC 0x0c059866 */
if(!s->budget--) { s->failed_pc=0x0c059866u; return 0; }
r[13]&=r[4];
goto P_0c059868;
P_0c059868: /* original db28, guest PC 0x0c059868 */
if(!s->budget--) { s->failed_pc=0x0c059868u; return 0; }
r[11]=read(ram,0x0c05990cu,4);
goto P_0c05986a;
P_0c05986a: /* original 2d3b, guest PC 0x0c05986a */
if(!s->budget--) { s->failed_pc=0x0c05986au; return 0; }
r[13]|=r[3];
goto P_0c05986c;
P_0c05986c: /* original e620, guest PC 0x0c05986c */
if(!s->budget--) { s->failed_pc=0x0c05986cu; return 0; }
r[6]=0x00000020u;
goto P_0c05986e;
P_0c05986e: /* original 65e3, guest PC 0x0c05986e */
if(!s->budget--) { s->failed_pc=0x0c05986eu; return 0; }
r[5]=r[14];
goto P_0c059870;
P_0c059870: /* original 4b0b, guest PC 0x0c059870 */
if(!s->budget--) { s->failed_pc=0x0c059870u; return 0; }
target=r[11];
r[16]=code_base|0x0c059874u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c059874u) { target=s->pc; goto dispatch; }
goto P_0c059874;
P_0c059872: /* original 64d3, guest PC 0x0c059872 */
if(!s->budget--) { s->failed_pc=0x0c059872u; return 0; }
r[4]=r[13];
goto P_0c059874;
P_0c059874: /* original 0d83, guest PC 0x0c059874 */
if(!s->budget--) { s->failed_pc=0x0c059874u; return 0; }
if((r[13]&0xFC000000u)==0xE0000000u) pref(ram,r[13]);
goto P_0c059876;
P_0c059876: /* original 7d20, guest PC 0x0c059876 */
if(!s->budget--) { s->failed_pc=0x0c059876u; return 0; }
r[13]+=0x00000020u;
goto P_0c059878;
P_0c059878: /* original 4c10, guest PC 0x0c059878 */
if(!s->budget--) { s->failed_pc=0x0c059878u; return 0; }
--r[12];
r[17]=(r[17]&~1u)|((r[12]==0)!=0);
goto P_0c05987a;
P_0c05987a: /* original 8ff7, guest PC 0x0c05987a */
if(!s->budget--) { s->failed_pc=0x0c05987au; return 0; }
cond=r[17]&1u;
r[14]+=0x00000020u;
if(!cond) { goto P_0c05986c; }
goto P_0c05987e;
P_0c05987c: /* original 7e20, guest PC 0x0c05987c */
if(!s->budget--) { s->failed_pc=0x0c05987cu; return 0; }
r[14]+=0x00000020u;
goto P_0c05987e;
P_0c05987e: /* original d21d, guest PC 0x0c05987e */
if(!s->budget--) { s->failed_pc=0x0c05987eu; return 0; }
r[2]=read(ram,0x0c0598f4u,4);
goto P_0c059880;
P_0c059880: /* original 9136, guest PC 0x0c059880 */
if(!s->budget--) { s->failed_pc=0x0c059880u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0598f0u,2);
goto P_0c059882;
P_0c059882: /* original 6322, guest PC 0x0c059882 */
if(!s->budget--) { s->failed_pc=0x0c059882u; return 0; }
tmp=read(ram,r[2],4);
r[3]=tmp;
goto P_0c059884;
P_0c059884: /* original 6032, guest PC 0x0c059884 */
if(!s->budget--) { s->failed_pc=0x0c059884u; return 0; }
tmp=read(ram,r[3],4);
r[0]=tmp;
goto P_0c059886;
P_0c059886: /* original 301c, guest PC 0x0c059886 */
if(!s->budget--) { s->failed_pc=0x0c059886u; return 0; }
r[0]+=r[1];
goto P_0c059888;
P_0c059888: /* original 2302, guest PC 0x0c059888 */
if(!s->budget--) { s->failed_pc=0x0c059888u; return 0; }
write(ram,r[3],r[0],4);
goto P_0c05988a;
P_0c05988a: /* original 4f26, guest PC 0x0c05988a */
if(!s->budget--) { s->failed_pc=0x0c05988au; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c05988c;
P_0c05988c: /* original 6bf6, guest PC 0x0c05988c */
if(!s->budget--) { s->failed_pc=0x0c05988cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c05988e;
P_0c05988e: /* original 6cf6, guest PC 0x0c05988e */
if(!s->budget--) { s->failed_pc=0x0c05988eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c059890;
P_0c059890: /* original 6df6, guest PC 0x0c059890 */
if(!s->budget--) { s->failed_pc=0x0c059890u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c059892;
P_0c059892: /* original 000b, guest PC 0x0c059892 */
if(!s->budget--) { s->failed_pc=0x0c059892u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c059894: /* original 6ef6, guest PC 0x0c059894 */
if(!s->budget--) { s->failed_pc=0x0c059894u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c059896u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c059896u; return 0; } return 1;
P_0c059a20: /* original 2fe6, guest PC 0x0c059a20 */
if(!s->budget--) { s->failed_pc=0x0c059a20u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c059a22;
P_0c059a22: /* original 2fd6, guest PC 0x0c059a22 */
if(!s->budget--) { s->failed_pc=0x0c059a22u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c059a24;
P_0c059a24: /* original 2fc6, guest PC 0x0c059a24 */
if(!s->budget--) { s->failed_pc=0x0c059a24u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c059a26;
P_0c059a26: /* original 2fb6, guest PC 0x0c059a26 */
if(!s->budget--) { s->failed_pc=0x0c059a26u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c059a28;
P_0c059a28: /* original 2fa6, guest PC 0x0c059a28 */
if(!s->budget--) { s->failed_pc=0x0c059a28u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c059a2a;
P_0c059a2a: /* original 2f96, guest PC 0x0c059a2a */
if(!s->budget--) { s->failed_pc=0x0c059a2au; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c059a2c;
P_0c059a2c: /* original 2f86, guest PC 0x0c059a2c */
if(!s->budget--) { s->failed_pc=0x0c059a2cu; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c059a2e;
P_0c059a2e: /* original 4f22, guest PC 0x0c059a2e */
if(!s->budget--) { s->failed_pc=0x0c059a2eu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c059a30;
P_0c059a30: /* original d337, guest PC 0x0c059a30 */
if(!s->budget--) { s->failed_pc=0x0c059a30u; return 0; }
r[3]=read(ram,0x0c059b10u,4);
goto P_0c059a32;
P_0c059a32: /* original 7ff8, guest PC 0x0c059a32 */
if(!s->budget--) { s->failed_pc=0x0c059a32u; return 0; }
r[15]+=0xfffffff8u;
goto P_0c059a34;
P_0c059a34: /* original 1f41, guest PC 0x0c059a34 */
if(!s->budget--) { s->failed_pc=0x0c059a34u; return 0; }
write(ram,r[15]+4,r[4],4);
goto P_0c059a36;
P_0c059a36: /* original 6432, guest PC 0x0c059a36 */
if(!s->budget--) { s->failed_pc=0x0c059a36u; return 0; }
tmp=read(ram,r[3],4);
r[4]=tmp;
goto P_0c059a38;
P_0c059a38: /* original 6543, guest PC 0x0c059a38 */
if(!s->budget--) { s->failed_pc=0x0c059a38u; return 0; }
r[5]=r[4];
goto P_0c059a3a;
P_0c059a3a: /* original 4508, guest PC 0x0c059a3a */
if(!s->budget--) { s->failed_pc=0x0c059a3au; return 0; }
r[5]<<=2;
goto P_0c059a3c;
P_0c059a3c: /* original d935, guest PC 0x0c059a3c */
if(!s->budget--) { s->failed_pc=0x0c059a3cu; return 0; }
r[9]=read(ram,0x0c059b14u,4);
goto P_0c059a3e;
P_0c059a3e: /* original ee00, guest PC 0x0c059a3e */
if(!s->budget--) { s->failed_pc=0x0c059a3eu; return 0; }
r[14]=0x00000000u;
goto P_0c059a40;
P_0c059a40: /* original db35, guest PC 0x0c059a40 */
if(!s->budget--) { s->failed_pc=0x0c059a40u; return 0; }
r[11]=read(ram,0x0c059b18u,4);
goto P_0c059a42;
P_0c059a42: /* original 395c, guest PC 0x0c059a42 */
if(!s->budget--) { s->failed_pc=0x0c059a42u; return 0; }
r[9]+=r[5];
goto P_0c059a44;
P_0c059a44: /* original d835, guest PC 0x0c059a44 */
if(!s->budget--) { s->failed_pc=0x0c059a44u; return 0; }
r[8]=read(ram,0x0c059b1cu,4);
goto P_0c059a46;
P_0c059a46: /* original 3b5c, guest PC 0x0c059a46 */
if(!s->budget--) { s->failed_pc=0x0c059a46u; return 0; }
r[11]+=r[5];
goto P_0c059a48;
P_0c059a48: /* original da35, guest PC 0x0c059a48 */
if(!s->budget--) { s->failed_pc=0x0c059a48u; return 0; }
r[10]=read(ram,0x0c059b20u,4);
goto P_0c059a4a;
P_0c059a4a: /* original dc36, guest PC 0x0c059a4a */
if(!s->budget--) { s->failed_pc=0x0c059a4au; return 0; }
r[12]=read(ram,0x0c059b24u,4);
goto P_0c059a4c;
P_0c059a4c: /* original 9d5f, guest PC 0x0c059a4c */
if(!s->budget--) { s->failed_pc=0x0c059a4cu; return 0; }
r[13]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c059b0eu,2);
goto P_0c059a4e;
P_0c059a4e: /* original 62b2, guest PC 0x0c059a4e */
if(!s->budget--) { s->failed_pc=0x0c059a4eu; return 0; }
tmp=read(ram,r[11],4);
r[2]=tmp;
goto P_0c059a50;
P_0c059a50: /* original 2228, guest PC 0x0c059a50 */
if(!s->budget--) { s->failed_pc=0x0c059a50u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c059a52;
P_0c059a52: /* original 8931, guest PC 0x0c059a52 */
if(!s->budget--) { s->failed_pc=0x0c059a52u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c059ab8; }
goto P_0c059a54;
P_0c059a54: /* original 53f1, guest PC 0x0c059a54 */
if(!s->budget--) { s->failed_pc=0x0c059a54u; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c059a56;
P_0c059a56: /* original 33e0, guest PC 0x0c059a56 */
if(!s->budget--) { s->failed_pc=0x0c059a56u; return 0; }
r[17]=(r[17]&~1u)|((r[3]==r[14])!=0);
goto P_0c059a58;
P_0c059a58: /* original 892e, guest PC 0x0c059a58 */
if(!s->budget--) { s->failed_pc=0x0c059a58u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c059ab8; }
goto P_0c059a5a;
P_0c059a5a: /* original d133, guest PC 0x0c059a5a */
if(!s->budget--) { s->failed_pc=0x0c059a5au; return 0; }
r[1]=read(ram,0x0c059b28u,4);
goto P_0c059a5c;
P_0c059a5c: /* original 6012, guest PC 0x0c059a5c */
if(!s->budget--) { s->failed_pc=0x0c059a5cu; return 0; }
tmp=read(ram,r[1],4);
r[0]=tmp;
goto P_0c059a5e;
P_0c059a5e: /* original 8801, guest PC 0x0c059a5e */
if(!s->budget--) { s->failed_pc=0x0c059a5eu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c059a60;
P_0c059a60: /* original 8b1f, guest PC 0x0c059a60 */
if(!s->budget--) { s->failed_pc=0x0c059a60u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c059aa2; }
goto P_0c059a62;
P_0c059a62: /* original 60e3, guest PC 0x0c059a62 */
if(!s->budget--) { s->failed_pc=0x0c059a62u; return 0; }
r[0]=r[14];
goto P_0c059a64;
P_0c059a64: /* original 0009, guest PC 0x0c059a64 */
if(!s->budget--) { s->failed_pc=0x0c059a64u; return 0; }
goto P_0c059a66;
P_0c059a66: /* original 8801, guest PC 0x0c059a66 */
if(!s->budget--) { s->failed_pc=0x0c059a66u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c059a68;
P_0c059a68: /* original 8903, guest PC 0x0c059a68 */
if(!s->budget--) { s->failed_pc=0x0c059a68u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c059a72; }
goto P_0c059a6a;
P_0c059a6a: /* original 60e3, guest PC 0x0c059a6a */
if(!s->budget--) { s->failed_pc=0x0c059a6au; return 0; }
r[0]=r[14];
goto P_0c059a6c;
P_0c059a6c: /* original 0009, guest PC 0x0c059a6c */
if(!s->budget--) { s->failed_pc=0x0c059a6cu; return 0; }
goto P_0c059a6e;
P_0c059a6e: /* original 8803, guest PC 0x0c059a6e */
if(!s->budget--) { s->failed_pc=0x0c059a6eu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000003u)!=0);
goto P_0c059a70;
P_0c059a70: /* original 8b17, guest PC 0x0c059a70 */
if(!s->budget--) { s->failed_pc=0x0c059a70u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c059aa2; }
goto P_0c059a72;
P_0c059a72: /* original d32e, guest PC 0x0c059a72 */
if(!s->budget--) { s->failed_pc=0x0c059a72u; return 0; }
r[3]=read(ram,0x0c059b2cu,4);
goto P_0c059a74;
P_0c059a74: /* original 6232, guest PC 0x0c059a74 */
if(!s->budget--) { s->failed_pc=0x0c059a74u; return 0; }
tmp=read(ram,r[3],4);
r[2]=tmp;
goto P_0c059a76;
P_0c059a76: /* original 6033, guest PC 0x0c059a76 */
if(!s->budget--) { s->failed_pc=0x0c059a76u; return 0; }
r[0]=r[3];
goto P_0c059a78;
P_0c059a78: /* original 0009, guest PC 0x0c059a78 */
if(!s->budget--) { s->failed_pc=0x0c059a78u; return 0; }
goto P_0c059a7a;
P_0c059a7a: /* original 6102, guest PC 0x0c059a7a */
if(!s->budget--) { s->failed_pc=0x0c059a7au; return 0; }
tmp=read(ram,r[0],4);
r[1]=tmp;
goto P_0c059a7c;
P_0c059a7c: /* original 6112, guest PC 0x0c059a7c */
if(!s->budget--) { s->failed_pc=0x0c059a7cu; return 0; }
tmp=read(ram,r[1],4);
r[1]=tmp;
goto P_0c059a7e;
P_0c059a7e: /* original 63e3, guest PC 0x0c059a7e */
if(!s->budget--) { s->failed_pc=0x0c059a7eu; return 0; }
r[3]=r[14];
goto P_0c059a80;
P_0c059a80: /* original 2189, guest PC 0x0c059a80 */
if(!s->budget--) { s->failed_pc=0x0c059a80u; return 0; }
r[1]&=r[8];
goto P_0c059a82;
P_0c059a82: /* original 4328, guest PC 0x0c059a82 */
if(!s->budget--) { s->failed_pc=0x0c059a82u; return 0; }
r[3]<<=16;
goto P_0c059a84;
P_0c059a84: /* original 4318, guest PC 0x0c059a84 */
if(!s->budget--) { s->failed_pc=0x0c059a84u; return 0; }
r[3]<<=8;
goto P_0c059a86;
P_0c059a86: /* original 213b, guest PC 0x0c059a86 */
if(!s->budget--) { s->failed_pc=0x0c059a86u; return 0; }
r[1]|=r[3];
goto P_0c059a88;
P_0c059a88: /* original 2212, guest PC 0x0c059a88 */
if(!s->budget--) { s->failed_pc=0x0c059a88u; return 0; }
write(ram,r[2],r[1],4);
goto P_0c059a8a;
P_0c059a8a: /* original 63f3, guest PC 0x0c059a8a */
if(!s->budget--) { s->failed_pc=0x0c059a8au; return 0; }
r[3]=r[15];
goto P_0c059a8c;
P_0c059a8c: /* original d228, guest PC 0x0c059a8c */
if(!s->budget--) { s->failed_pc=0x0c059a8cu; return 0; }
r[2]=read(ram,0x0c059b30u,4);
goto P_0c059a8e;
P_0c059a8e: /* original e710, guest PC 0x0c059a8e */
if(!s->budget--) { s->failed_pc=0x0c059a8eu; return 0; }
r[7]=0x00000010u;
goto P_0c059a90;
P_0c059a90: /* original 2f36, guest PC 0x0c059a90 */
if(!s->budget--) { s->failed_pc=0x0c059a90u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c059a92;
P_0c059a92: /* original 6622, guest PC 0x0c059a92 */
if(!s->budget--) { s->failed_pc=0x0c059a92u; return 0; }
tmp=read(ram,r[2],4);
r[6]=tmp;
goto P_0c059a94;
P_0c059a94: /* original d325, guest PC 0x0c059a94 */
if(!s->budget--) { s->failed_pc=0x0c059a94u; return 0; }
r[3]=read(ram,0x0c059b2cu,4);
goto P_0c059a96;
P_0c059a96: /* original 6532, guest PC 0x0c059a96 */
if(!s->budget--) { s->failed_pc=0x0c059a96u; return 0; }
tmp=read(ram,r[3],4);
r[5]=tmp;
goto P_0c059a98;
P_0c059a98: /* original 4a0b, guest PC 0x0c059a98 */
if(!s->budget--) { s->failed_pc=0x0c059a98u; return 0; }
target=r[10];
r[16]=code_base|0x0c059a9cu;
r[4]=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c059a9cu) { target=s->pc; goto dispatch; }
goto P_0c059a9c;
P_0c059a9a: /* original 64c3, guest PC 0x0c059a9a */
if(!s->budget--) { s->failed_pc=0x0c059a9au; return 0; }
r[4]=r[12];
goto P_0c059a9c;
P_0c059a9c: /* original 30d0, guest PC 0x0c059a9c */
if(!s->budget--) { s->failed_pc=0x0c059a9cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==r[13])!=0);
goto P_0c059a9e;
P_0c059a9e: /* original 8df4, guest PC 0x0c059a9e */
if(!s->budget--) { s->failed_pc=0x0c059a9eu; return 0; }
cond=r[17]&1u;
r[15]+=0x00000004u;
if(cond) { goto P_0c059a8a; }
goto P_0c059aa2;
P_0c059aa0: /* original 7f04, guest PC 0x0c059aa0 */
if(!s->budget--) { s->failed_pc=0x0c059aa0u; return 0; }
r[15]+=0x00000004u;
goto P_0c059aa2;
P_0c059aa2: /* original 62f3, guest PC 0x0c059aa2 */
if(!s->budget--) { s->failed_pc=0x0c059aa2u; return 0; }
r[2]=r[15];
goto P_0c059aa4;
P_0c059aa4: /* original 2f26, guest PC 0x0c059aa4 */
if(!s->budget--) { s->failed_pc=0x0c059aa4u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c059aa6;
P_0c059aa6: /* original e710, guest PC 0x0c059aa6 */
if(!s->budget--) { s->failed_pc=0x0c059aa6u; return 0; }
r[7]=0x00000010u;
goto P_0c059aa8;
P_0c059aa8: /* original 66b2, guest PC 0x0c059aa8 */
if(!s->budget--) { s->failed_pc=0x0c059aa8u; return 0; }
tmp=read(ram,r[11],4);
r[6]=tmp;
goto P_0c059aaa;
P_0c059aaa: /* original 7620, guest PC 0x0c059aaa */
if(!s->budget--) { s->failed_pc=0x0c059aaau; return 0; }
r[6]+=0x00000020u;
goto P_0c059aac;
P_0c059aac: /* original 6592, guest PC 0x0c059aac */
if(!s->budget--) { s->failed_pc=0x0c059aacu; return 0; }
tmp=read(ram,r[9],4);
r[5]=tmp;
goto P_0c059aae;
P_0c059aae: /* original 4a0b, guest PC 0x0c059aae */
if(!s->budget--) { s->failed_pc=0x0c059aaeu; return 0; }
target=r[10];
r[16]=code_base|0x0c059ab2u;
r[4]=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c059ab2u) { target=s->pc; goto dispatch; }
goto P_0c059ab2;
P_0c059ab0: /* original 64c3, guest PC 0x0c059ab0 */
if(!s->budget--) { s->failed_pc=0x0c059ab0u; return 0; }
r[4]=r[12];
goto P_0c059ab2;
P_0c059ab2: /* original 30d0, guest PC 0x0c059ab2 */
if(!s->budget--) { s->failed_pc=0x0c059ab2u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==r[13])!=0);
goto P_0c059ab4;
P_0c059ab4: /* original 8df5, guest PC 0x0c059ab4 */
if(!s->budget--) { s->failed_pc=0x0c059ab4u; return 0; }
cond=r[17]&1u;
r[15]+=0x00000004u;
if(cond) { goto P_0c059aa2; }
goto P_0c059ab8;
P_0c059ab6: /* original 7f04, guest PC 0x0c059ab6 */
if(!s->budget--) { s->failed_pc=0x0c059ab6u; return 0; }
r[15]+=0x00000004u;
goto P_0c059ab8;
P_0c059ab8: /* original 7b10, guest PC 0x0c059ab8 */
if(!s->budget--) { s->failed_pc=0x0c059ab8u; return 0; }
r[11]+=0x00000010u;
goto P_0c059aba;
P_0c059aba: /* original 7e01, guest PC 0x0c059aba */
if(!s->budget--) { s->failed_pc=0x0c059abau; return 0; }
r[14]+=0x00000001u;
goto P_0c059abc;
P_0c059abc: /* original e205, guest PC 0x0c059abc */
if(!s->budget--) { s->failed_pc=0x0c059abcu; return 0; }
r[2]=0x00000005u;
goto P_0c059abe;
P_0c059abe: /* original 3e22, guest PC 0x0c059abe */
if(!s->budget--) { s->failed_pc=0x0c059abeu; return 0; }
r[17]=(r[17]&~1u)|((r[14]>=r[2])!=0);
goto P_0c059ac0;
P_0c059ac0: /* original 8fc5, guest PC 0x0c059ac0 */
if(!s->budget--) { s->failed_pc=0x0c059ac0u; return 0; }
cond=r[17]&1u;
r[9]+=0x00000010u;
if(!cond) { goto P_0c059a4e; }
goto P_0c059ac4;
P_0c059ac2: /* original 7910, guest PC 0x0c059ac2 */
if(!s->budget--) { s->failed_pc=0x0c059ac2u; return 0; }
r[9]+=0x00000010u;
goto P_0c059ac4;
P_0c059ac4: /* original 7f08, guest PC 0x0c059ac4 */
if(!s->budget--) { s->failed_pc=0x0c059ac4u; return 0; }
r[15]+=0x00000008u;
goto P_0c059ac6;
P_0c059ac6: /* original 4f26, guest PC 0x0c059ac6 */
if(!s->budget--) { s->failed_pc=0x0c059ac6u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c059ac8;
P_0c059ac8: /* original 68f6, guest PC 0x0c059ac8 */
if(!s->budget--) { s->failed_pc=0x0c059ac8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c059aca;
P_0c059aca: /* original 69f6, guest PC 0x0c059aca */
if(!s->budget--) { s->failed_pc=0x0c059acau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c059acc;
P_0c059acc: /* original 6af6, guest PC 0x0c059acc */
if(!s->budget--) { s->failed_pc=0x0c059accu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c059ace;
P_0c059ace: /* original 6bf6, guest PC 0x0c059ace */
if(!s->budget--) { s->failed_pc=0x0c059aceu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c059ad0;
P_0c059ad0: /* original 6cf6, guest PC 0x0c059ad0 */
if(!s->budget--) { s->failed_pc=0x0c059ad0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c059ad2;
P_0c059ad2: /* original 6df6, guest PC 0x0c059ad2 */
if(!s->budget--) { s->failed_pc=0x0c059ad2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c059ad4;
P_0c059ad4: /* original 000b, guest PC 0x0c059ad4 */
if(!s->budget--) { s->failed_pc=0x0c059ad4u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c059ad6: /* original 6ef6, guest PC 0x0c059ad6 */
if(!s->budget--) { s->failed_pc=0x0c059ad6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c059ad8u,s,ram);
unsupported: s->failed_pc=target; return 0;
}
