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
int vf3_away_batch53_adapter_9(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c087734u: goto P_0c087734;
case 0x0c087736u: goto P_0c087736;
case 0x0c087738u: goto P_0c087738;
case 0x0c08773au: goto P_0c08773a;
case 0x0c08773cu: goto P_0c08773c;
case 0x0c08773eu: goto P_0c08773e;
case 0x0c087740u: goto P_0c087740;
case 0x0c087742u: goto P_0c087742;
case 0x0c087744u: goto P_0c087744;
case 0x0c087746u: goto P_0c087746;
case 0x0c087748u: goto P_0c087748;
case 0x0c08774au: goto P_0c08774a;
case 0x0c08774cu: goto P_0c08774c;
case 0x0c08774eu: goto P_0c08774e;
case 0x0c087750u: goto P_0c087750;
case 0x0c087752u: goto P_0c087752;
case 0x0c087754u: goto P_0c087754;
case 0x0c087756u: goto P_0c087756;
case 0x0c087758u: goto P_0c087758;
case 0x0c08775au: goto P_0c08775a;
case 0x0c08775cu: goto P_0c08775c;
case 0x0c08775eu: goto P_0c08775e;
case 0x0c087760u: goto P_0c087760;
case 0x0c087762u: goto P_0c087762;
case 0x0c087764u: goto P_0c087764;
case 0x0c087766u: goto P_0c087766;
case 0x0c087768u: goto P_0c087768;
case 0x0c08776au: goto P_0c08776a;
case 0x0c08776cu: goto P_0c08776c;
case 0x0c08776eu: goto P_0c08776e;
case 0x0c087770u: goto P_0c087770;
case 0x0c087772u: goto P_0c087772;
case 0x0c087774u: goto P_0c087774;
case 0x0c087776u: goto P_0c087776;
case 0x0c087778u: goto P_0c087778;
case 0x0c08777au: goto P_0c08777a;
case 0x0c08777cu: goto P_0c08777c;
case 0x0c08777eu: goto P_0c08777e;
case 0x0c087780u: goto P_0c087780;
case 0x0c087a40u: goto P_0c087a40;
case 0x0c087a42u: goto P_0c087a42;
case 0x0c087a44u: goto P_0c087a44;
case 0x0c087a46u: goto P_0c087a46;
case 0x0c087a48u: goto P_0c087a48;
case 0x0c087a4au: goto P_0c087a4a;
case 0x0c087a4cu: goto P_0c087a4c;
case 0x0c087a4eu: goto P_0c087a4e;
case 0x0c087a50u: goto P_0c087a50;
case 0x0c087a52u: goto P_0c087a52;
case 0x0c087a54u: goto P_0c087a54;
case 0x0c087a56u: goto P_0c087a56;
case 0x0c087a58u: goto P_0c087a58;
case 0x0c087a5au: goto P_0c087a5a;
case 0x0c087a5cu: goto P_0c087a5c;
case 0x0c087a5eu: goto P_0c087a5e;
case 0x0c087a60u: goto P_0c087a60;
case 0x0c087a62u: goto P_0c087a62;
case 0x0c087a64u: goto P_0c087a64;
case 0x0c087a66u: goto P_0c087a66;
case 0x0c087a68u: goto P_0c087a68;
case 0x0c087a6au: goto P_0c087a6a;
case 0x0c087a6cu: goto P_0c087a6c;
case 0x0c087a6eu: goto P_0c087a6e;
case 0x0c087a70u: goto P_0c087a70;
case 0x0c087a72u: goto P_0c087a72;
case 0x0c087a74u: goto P_0c087a74;
case 0x0c087a76u: goto P_0c087a76;
case 0x0c087a78u: goto P_0c087a78;
case 0x0c087a7au: goto P_0c087a7a;
case 0x0c087a7cu: goto P_0c087a7c;
case 0x0c087a7eu: goto P_0c087a7e;
case 0x0c087a80u: goto P_0c087a80;
case 0x0c087a82u: goto P_0c087a82;
case 0x0c087a84u: goto P_0c087a84;
case 0x0c087a86u: goto P_0c087a86;
case 0x0c087a88u: goto P_0c087a88;
case 0x0c087a8au: goto P_0c087a8a;
case 0x0c087a8cu: goto P_0c087a8c;
case 0x0c087a8eu: goto P_0c087a8e;
case 0x0c087a90u: goto P_0c087a90;
case 0x0c087a92u: goto P_0c087a92;
case 0x0c087a94u: goto P_0c087a94;
case 0x0c087a96u: goto P_0c087a96;
case 0x0c087a98u: goto P_0c087a98;
case 0x0c087a9au: goto P_0c087a9a;
case 0x0c087a9cu: goto P_0c087a9c;
case 0x0c087a9eu: goto P_0c087a9e;
case 0x0c087aa0u: goto P_0c087aa0;
case 0x0c087aa2u: goto P_0c087aa2;
case 0x0c087aa4u: goto P_0c087aa4;
case 0x0c087aa6u: goto P_0c087aa6;
case 0x0c087aa8u: goto P_0c087aa8;
case 0x0c087aaau: goto P_0c087aaa;
case 0x0c087aacu: goto P_0c087aac;
case 0x0c087aaeu: goto P_0c087aae;
case 0x0c087ab0u: goto P_0c087ab0;
case 0x0c087ab2u: goto P_0c087ab2;
case 0x0c087ab4u: goto P_0c087ab4;
case 0x0c087ab6u: goto P_0c087ab6;
case 0x0c087ab8u: goto P_0c087ab8;
case 0x0c087abau: goto P_0c087aba;
case 0x0c087abcu: goto P_0c087abc;
case 0x0c087abeu: goto P_0c087abe;
case 0x0c087ac0u: goto P_0c087ac0;
case 0x0c087ac2u: goto P_0c087ac2;
case 0x0c087ac4u: goto P_0c087ac4;
case 0x0c087ac6u: goto P_0c087ac6;
case 0x0c087ac8u: goto P_0c087ac8;
case 0x0c087acau: goto P_0c087aca;
case 0x0c087accu: goto P_0c087acc;
case 0x0c087aceu: goto P_0c087ace;
case 0x0c087ad0u: goto P_0c087ad0;
case 0x0c087ad2u: goto P_0c087ad2;
case 0x0c087ad4u: goto P_0c087ad4;
case 0x0c087ad6u: goto P_0c087ad6;
case 0x0c087ad8u: goto P_0c087ad8;
case 0x0c087adau: goto P_0c087ada;
case 0x0c087adcu: goto P_0c087adc;
case 0x0c087adeu: goto P_0c087ade;
case 0x0c087ae0u: goto P_0c087ae0;
case 0x0c087ae2u: goto P_0c087ae2;
case 0x0c087ae4u: goto P_0c087ae4;
case 0x0c087ae6u: goto P_0c087ae6;
case 0x0c087ae8u: goto P_0c087ae8;
case 0x0c087aeau: goto P_0c087aea;
case 0x0c087aecu: goto P_0c087aec;
case 0x0c087aeeu: goto P_0c087aee;
case 0x0c087af0u: goto P_0c087af0;
case 0x0c087af2u: goto P_0c087af2;
case 0x0c087af4u: goto P_0c087af4;
case 0x0c087af6u: goto P_0c087af6;
case 0x0c087af8u: goto P_0c087af8;
case 0x0c087afau: goto P_0c087afa;
case 0x0c087afcu: goto P_0c087afc;
case 0x0c087afeu: goto P_0c087afe;
case 0x0c087b00u: goto P_0c087b00;
case 0x0c087b02u: goto P_0c087b02;
case 0x0c087b04u: goto P_0c087b04;
case 0x0c087b06u: goto P_0c087b06;
case 0x0c087b08u: goto P_0c087b08;
case 0x0c087b0au: goto P_0c087b0a;
case 0x0c087b0cu: goto P_0c087b0c;
case 0x0c087b0eu: goto P_0c087b0e;
case 0x0c087b10u: goto P_0c087b10;
case 0x0c087b12u: goto P_0c087b12;
case 0x0c087b14u: goto P_0c087b14;
case 0x0c087b16u: goto P_0c087b16;
case 0x0c087b18u: goto P_0c087b18;
case 0x0c087b1au: goto P_0c087b1a;
case 0x0c087b1cu: goto P_0c087b1c;
case 0x0c087b1eu: goto P_0c087b1e;
case 0x0c087b20u: goto P_0c087b20;
case 0x0c087b22u: goto P_0c087b22;
case 0x0c087b24u: goto P_0c087b24;
case 0x0c087b26u: goto P_0c087b26;
case 0x0c087b28u: goto P_0c087b28;
case 0x0c087b2au: goto P_0c087b2a;
case 0x0c087b2cu: goto P_0c087b2c;
case 0x0c087b2eu: goto P_0c087b2e;
case 0x0c087b30u: goto P_0c087b30;
case 0x0c087b32u: goto P_0c087b32;
case 0x0c087b34u: goto P_0c087b34;
case 0x0c087b36u: goto P_0c087b36;
case 0x0c087b38u: goto P_0c087b38;
case 0x0c087b3au: goto P_0c087b3a;
case 0x0c087b3cu: goto P_0c087b3c;
case 0x0c087b3eu: goto P_0c087b3e;
case 0x0c087b40u: goto P_0c087b40;
case 0x0c087b42u: goto P_0c087b42;
case 0x0c087b44u: goto P_0c087b44;
case 0x0c087b46u: goto P_0c087b46;
case 0x0c087b48u: goto P_0c087b48;
case 0x0c087b4au: goto P_0c087b4a;
case 0x0c087b4cu: goto P_0c087b4c;
case 0x0c087b4eu: goto P_0c087b4e;
case 0x0c087b50u: goto P_0c087b50;
case 0x0c087b52u: goto P_0c087b52;
case 0x0c087b54u: goto P_0c087b54;
case 0x0c087cdcu: goto P_0c087cdc;
case 0x0c087cdeu: goto P_0c087cde;
case 0x0c087ce0u: goto P_0c087ce0;
case 0x0c087ce2u: goto P_0c087ce2;
case 0x0c087ce4u: goto P_0c087ce4;
case 0x0c087ce6u: goto P_0c087ce6;
case 0x0c087ce8u: goto P_0c087ce8;
case 0x0c087ceau: goto P_0c087cea;
case 0x0c087cecu: goto P_0c087cec;
case 0x0c087ceeu: goto P_0c087cee;
case 0x0c087cf0u: goto P_0c087cf0;
case 0x0c087cf2u: goto P_0c087cf2;
case 0x0c087cf4u: goto P_0c087cf4;
case 0x0c087cf6u: goto P_0c087cf6;
case 0x0c087cf8u: goto P_0c087cf8;
case 0x0c087cfau: goto P_0c087cfa;
case 0x0c087cfcu: goto P_0c087cfc;
case 0x0c087cfeu: goto P_0c087cfe;
case 0x0c087d00u: goto P_0c087d00;
case 0x0c087d02u: goto P_0c087d02;
case 0x0c087d04u: goto P_0c087d04;
case 0x0c087d06u: goto P_0c087d06;
case 0x0c087d08u: goto P_0c087d08;
case 0x0c087d0au: goto P_0c087d0a;
case 0x0c087d0cu: goto P_0c087d0c;
case 0x0c087d0eu: goto P_0c087d0e;
case 0x0c087d10u: goto P_0c087d10;
case 0x0c087d12u: goto P_0c087d12;
case 0x0c087d14u: goto P_0c087d14;
case 0x0c087d16u: goto P_0c087d16;
case 0x0c087d18u: goto P_0c087d18;
case 0x0c087d1au: goto P_0c087d1a;
case 0x0c087d1cu: goto P_0c087d1c;
case 0x0c087d1eu: goto P_0c087d1e;
case 0x0c087d20u: goto P_0c087d20;
case 0x0c087d22u: goto P_0c087d22;
case 0x0c087d24u: goto P_0c087d24;
case 0x0c087d26u: goto P_0c087d26;
case 0x0c087d28u: goto P_0c087d28;
case 0x0c087d2au: goto P_0c087d2a;
case 0x0c087d2cu: goto P_0c087d2c;
case 0x0c087d2eu: goto P_0c087d2e;
case 0x0c087d30u: goto P_0c087d30;
case 0x0c087d32u: goto P_0c087d32;
case 0x0c087d34u: goto P_0c087d34;
case 0x0c087d36u: goto P_0c087d36;
case 0x0c087d38u: goto P_0c087d38;
case 0x0c087d3au: goto P_0c087d3a;
case 0x0c087d3cu: goto P_0c087d3c;
case 0x0c087d3eu: goto P_0c087d3e;
case 0x0c087d40u: goto P_0c087d40;
case 0x0c087d42u: goto P_0c087d42;
case 0x0c087d44u: goto P_0c087d44;
case 0x0c087d46u: goto P_0c087d46;
case 0x0c087d48u: goto P_0c087d48;
case 0x0c087d4au: goto P_0c087d4a;
case 0x0c087d4cu: goto P_0c087d4c;
case 0x0c087d4eu: goto P_0c087d4e;
case 0x0c087d50u: goto P_0c087d50;
case 0x0c087d52u: goto P_0c087d52;
case 0x0c087d54u: goto P_0c087d54;
case 0x0c087d56u: goto P_0c087d56;
case 0x0c087d58u: goto P_0c087d58;
case 0x0c087d5au: goto P_0c087d5a;
case 0x0c087d5cu: goto P_0c087d5c;
case 0x0c087d5eu: goto P_0c087d5e;
case 0x0c087d60u: goto P_0c087d60;
case 0x0c087d62u: goto P_0c087d62;
case 0x0c087d64u: goto P_0c087d64;
case 0x0c087d66u: goto P_0c087d66;
case 0x0c087d68u: goto P_0c087d68;
case 0x0c087d6au: goto P_0c087d6a;
case 0x0c087d6cu: goto P_0c087d6c;
case 0x0c087d6eu: goto P_0c087d6e;
case 0x0c087d70u: goto P_0c087d70;
case 0x0c087d72u: goto P_0c087d72;
case 0x0c087d74u: goto P_0c087d74;
case 0x0c087d76u: goto P_0c087d76;
case 0x0c087d78u: goto P_0c087d78;
case 0x0c087d7au: goto P_0c087d7a;
case 0x0c087d7cu: goto P_0c087d7c;
case 0x0c087d7eu: goto P_0c087d7e;
case 0x0c087d80u: goto P_0c087d80;
case 0x0c087d82u: goto P_0c087d82;
case 0x0c087d84u: goto P_0c087d84;
case 0x0c087d86u: goto P_0c087d86;
case 0x0c087d88u: goto P_0c087d88;
case 0x0c087d8au: goto P_0c087d8a;
case 0x0c087d8cu: goto P_0c087d8c;
case 0x0c087d8eu: goto P_0c087d8e;
case 0x0c087d90u: goto P_0c087d90;
case 0x0c087d92u: goto P_0c087d92;
case 0x0c087d94u: goto P_0c087d94;
case 0x0c087d96u: goto P_0c087d96;
case 0x0c087d98u: goto P_0c087d98;
case 0x0c087d9au: goto P_0c087d9a;
case 0x0c087d9cu: goto P_0c087d9c;
case 0x0c087d9eu: goto P_0c087d9e;
case 0x0c087da0u: goto P_0c087da0;
case 0x0c087da2u: goto P_0c087da2;
case 0x0c087da4u: goto P_0c087da4;
case 0x0c087da6u: goto P_0c087da6;
case 0x0c087da8u: goto P_0c087da8;
case 0x0c087daau: goto P_0c087daa;
case 0x0c087dacu: goto P_0c087dac;
case 0x0c087daeu: goto P_0c087dae;
case 0x0c087db0u: goto P_0c087db0;
case 0x0c087db2u: goto P_0c087db2;
case 0x0c087db4u: goto P_0c087db4;
case 0x0c087db6u: goto P_0c087db6;
case 0x0c087db8u: goto P_0c087db8;
case 0x0c087dbau: goto P_0c087dba;
case 0x0c087dbcu: goto P_0c087dbc;
case 0x0c087dbeu: goto P_0c087dbe;
case 0x0c087dc0u: goto P_0c087dc0;
case 0x0c087dc2u: goto P_0c087dc2;
case 0x0c087dc4u: goto P_0c087dc4;
case 0x0c087dc6u: goto P_0c087dc6;
case 0x0c087dc8u: goto P_0c087dc8;
case 0x0c087dcau: goto P_0c087dca;
default: return vf3_matrix_family(target,s,ram);
}
P_0c087734: /* original 4f22, guest PC 0x0c087734 */
if(!s->budget--) { s->failed_pc=0x0c087734u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c087736;
P_0c087736: /* original e018, guest PC 0x0c087736 */
if(!s->budget--) { s->failed_pc=0x0c087736u; return 0; }
r[0]=0x00000018u;
goto P_0c087738;
P_0c087738: /* original 7fdc, guest PC 0x0c087738 */
if(!s->budget--) { s->failed_pc=0x0c087738u; return 0; }
r[15]+=0xffffffdcu;
goto P_0c08773a;
P_0c08773a: /* original 1f42, guest PC 0x0c08773a */
if(!s->budget--) { s->failed_pc=0x0c08773au; return 0; }
write(ram,r[15]+8,r[4],4);
goto P_0c08773c;
P_0c08773c: /* original 64f3, guest PC 0x0c08773c */
if(!s->budget--) { s->failed_pc=0x0c08773cu; return 0; }
r[4]=r[15];
goto P_0c08773e;
P_0c08773e: /* original 1f51, guest PC 0x0c08773e */
if(!s->budget--) { s->failed_pc=0x0c08773eu; return 0; }
write(ram,r[15]+4,r[5],4);
goto P_0c087740;
P_0c087740: /* original 65f3, guest PC 0x0c087740 */
if(!s->budget--) { s->failed_pc=0x0c087740u; return 0; }
r[5]=r[15];
goto P_0c087742;
P_0c087742: /* original 750c, guest PC 0x0c087742 */
if(!s->budget--) { s->failed_pc=0x0c087742u; return 0; }
r[5]+=0x0000000cu;
goto P_0c087744;
P_0c087744: /* original 2f62, guest PC 0x0c087744 */
if(!s->budget--) { s->failed_pc=0x0c087744u; return 0; }
write(ram,r[15],r[6],4);
goto P_0c087746;
P_0c087746: /* original 53f2, guest PC 0x0c087746 */
if(!s->budget--) { s->failed_pc=0x0c087746u; return 0; }
r[3]=read(ram,r[15]+8,4);
goto P_0c087748;
P_0c087748: /* original f338, guest PC 0x0c087748 */
if(!s->budget--) { s->failed_pc=0x0c087748u; return 0; }
vf3_matrix_load(s,ram,3,r[3]);
goto P_0c08774a;
P_0c08774a: /* original ff37, guest PC 0x0c08774a */
if(!s->budget--) { s->failed_pc=0x0c08774au; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c08774c;
P_0c08774c: /* original e01c, guest PC 0x0c08774c */
if(!s->budget--) { s->failed_pc=0x0c08774cu; return 0; }
r[0]=0x0000001cu;
goto P_0c08774e;
P_0c08774e: /* original 53f1, guest PC 0x0c08774e */
if(!s->budget--) { s->failed_pc=0x0c08774eu; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c087750;
P_0c087750: /* original f338, guest PC 0x0c087750 */
if(!s->budget--) { s->failed_pc=0x0c087750u; return 0; }
vf3_matrix_load(s,ram,3,r[3]);
goto P_0c087752;
P_0c087752: /* original ff37, guest PC 0x0c087752 */
if(!s->budget--) { s->failed_pc=0x0c087752u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c087754;
P_0c087754: /* original e020, guest PC 0x0c087754 */
if(!s->budget--) { s->failed_pc=0x0c087754u; return 0; }
r[0]=0x00000020u;
goto P_0c087756;
P_0c087756: /* original 63f2, guest PC 0x0c087756 */
if(!s->budget--) { s->failed_pc=0x0c087756u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c087758;
P_0c087758: /* original f338, guest PC 0x0c087758 */
if(!s->budget--) { s->failed_pc=0x0c087758u; return 0; }
vf3_matrix_load(s,ram,3,r[3]);
goto P_0c08775a;
P_0c08775a: /* original ff37, guest PC 0x0c08775a */
if(!s->budget--) { s->failed_pc=0x0c08775au; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c08775c;
P_0c08775c: /* original d30e, guest PC 0x0c08775c */
if(!s->budget--) { s->failed_pc=0x0c08775cu; return 0; }
r[3]=read(ram,0x0c087798u,4);
goto P_0c08775e;
P_0c08775e: /* original 430b, guest PC 0x0c08775e */
if(!s->budget--) { s->failed_pc=0x0c08775eu; return 0; }
target=r[3];
r[16]=code_base|0x0c087762u;
r[4]+=0x00000018u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c087762u) { target=s->pc; goto dispatch; }
goto P_0c087762;
P_0c087760: /* original 7418, guest PC 0x0c087760 */
if(!s->budget--) { s->failed_pc=0x0c087760u; return 0; }
r[4]+=0x00000018u;
goto P_0c087762;
P_0c087762: /* original e00c, guest PC 0x0c087762 */
if(!s->budget--) { s->failed_pc=0x0c087762u; return 0; }
r[0]=0x0000000cu;
goto P_0c087764;
P_0c087764: /* original 52f2, guest PC 0x0c087764 */
if(!s->budget--) { s->failed_pc=0x0c087764u; return 0; }
r[2]=read(ram,r[15]+8,4);
goto P_0c087766;
P_0c087766: /* original f3f6, guest PC 0x0c087766 */
if(!s->budget--) { s->failed_pc=0x0c087766u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c087768;
P_0c087768: /* original e010, guest PC 0x0c087768 */
if(!s->budget--) { s->failed_pc=0x0c087768u; return 0; }
r[0]=0x00000010u;
goto P_0c08776a;
P_0c08776a: /* original f23a, guest PC 0x0c08776a */
if(!s->budget--) { s->failed_pc=0x0c08776au; return 0; }
vf3_matrix_store(s,ram,3,r[2]);
goto P_0c08776c;
P_0c08776c: /* original f3f6, guest PC 0x0c08776c */
if(!s->budget--) { s->failed_pc=0x0c08776cu; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c08776e;
P_0c08776e: /* original e014, guest PC 0x0c08776e */
if(!s->budget--) { s->failed_pc=0x0c08776eu; return 0; }
r[0]=0x00000014u;
goto P_0c087770;
P_0c087770: /* original 53f1, guest PC 0x0c087770 */
if(!s->budget--) { s->failed_pc=0x0c087770u; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c087772;
P_0c087772: /* original f33a, guest PC 0x0c087772 */
if(!s->budget--) { s->failed_pc=0x0c087772u; return 0; }
vf3_matrix_store(s,ram,3,r[3]);
goto P_0c087774;
P_0c087774: /* original f3f6, guest PC 0x0c087774 */
if(!s->budget--) { s->failed_pc=0x0c087774u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c087776;
P_0c087776: /* original 63f2, guest PC 0x0c087776 */
if(!s->budget--) { s->failed_pc=0x0c087776u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c087778;
P_0c087778: /* original 7f24, guest PC 0x0c087778 */
if(!s->budget--) { s->failed_pc=0x0c087778u; return 0; }
r[15]+=0x00000024u;
goto P_0c08777a;
P_0c08777a: /* original 4f26, guest PC 0x0c08777a */
if(!s->budget--) { s->failed_pc=0x0c08777au; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c08777c;
P_0c08777c: /* original f33a, guest PC 0x0c08777c */
if(!s->budget--) { s->failed_pc=0x0c08777cu; return 0; }
vf3_matrix_store(s,ram,3,r[3]);
goto P_0c08777e;
P_0c08777e: /* original 000b, guest PC 0x0c08777e */
if(!s->budget--) { s->failed_pc=0x0c08777eu; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c087780: /* original 0009, guest PC 0x0c087780 */
if(!s->budget--) { s->failed_pc=0x0c087780u; return 0; }
if(!vf3_matrix_family(0x0c087782u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c087782u; return 0; } return 1;
P_0c087a40: /* original d347, guest PC 0x0c087a40 */
if(!s->budget--) { s->failed_pc=0x0c087a40u; return 0; }
r[3]=read(ram,0x0c087b60u,4);
goto P_0c087a42;
P_0c087a42: /* original 9088, guest PC 0x0c087a42 */
if(!s->budget--) { s->failed_pc=0x0c087a42u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c087b56u,2);
goto P_0c087a44;
P_0c087a44: /* original 6432, guest PC 0x0c087a44 */
if(!s->budget--) { s->failed_pc=0x0c087a44u; return 0; }
tmp=read(ram,r[3],4);
r[4]=tmp;
goto P_0c087a46;
P_0c087a46: /* original 044e, guest PC 0x0c087a46 */
if(!s->budget--) { s->failed_pc=0x0c087a46u; return 0; }
r[4]=read(ram,r[4]+r[0],4);
goto P_0c087a48;
P_0c087a48: /* original 2448, guest PC 0x0c087a48 */
if(!s->budget--) { s->failed_pc=0x0c087a48u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c087a4a;
P_0c087a4a: /* original 893d, guest PC 0x0c087a4a */
if(!s->budget--) { s->failed_pc=0x0c087a4au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c087ac8; }
goto P_0c087a4c;
P_0c087a4c: /* original c745, guest PC 0x0c087a4c */
if(!s->budget--) { s->failed_pc=0x0c087a4cu; return 0; }
r[0]=code_base|0x00087b64u;
goto P_0c087a4e;
P_0c087a4e: /* original 9383, guest PC 0x0c087a4e */
if(!s->budget--) { s->failed_pc=0x0c087a4eu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c087b58u,2);
goto P_0c087a50;
P_0c087a50: /* original f908, guest PC 0x0c087a50 */
if(!s->budget--) { s->failed_pc=0x0c087a50u; return 0; }
vf3_matrix_load(s,ram,9,r[0]);
goto P_0c087a52;
P_0c087a52: /* original c745, guest PC 0x0c087a52 */
if(!s->budget--) { s->failed_pc=0x0c087a52u; return 0; }
r[0]=code_base|0x00087b68u;
goto P_0c087a54;
P_0c087a54: /* original f808, guest PC 0x0c087a54 */
if(!s->budget--) { s->failed_pc=0x0c087a54u; return 0; }
vf3_matrix_load(s,ram,8,r[0]);
goto P_0c087a56;
P_0c087a56: /* original e608, guest PC 0x0c087a56 */
if(!s->budget--) { s->failed_pc=0x0c087a56u; return 0; }
r[6]=0x00000008u;
goto P_0c087a58;
P_0c087a58: /* original 343c, guest PC 0x0c087a58 */
if(!s->budget--) { s->failed_pc=0x0c087a58u; return 0; }
r[4]+=r[3];
goto P_0c087a5a;
P_0c087a5a: /* original e500, guest PC 0x0c087a5a */
if(!s->budget--) { s->failed_pc=0x0c087a5au; return 0; }
r[5]=0x00000000u;
goto P_0c087a5c;
P_0c087a5c: /* original 907d, guest PC 0x0c087a5c */
if(!s->budget--) { s->failed_pc=0x0c087a5cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c087b5au,2);
goto P_0c087a5e;
P_0c087a5e: /* original f69c, guest PC 0x0c087a5e */
if(!s->budget--) { s->failed_pc=0x0c087a5eu; return 0; }
vf3_matrix_move(s,6,9);
goto P_0c087a60;
P_0c087a60: /* original f346, guest PC 0x0c087a60 */
if(!s->budget--) { s->failed_pc=0x0c087a60u; return 0; }
vf3_matrix_load(s,ram,3,r[4]+r[0]);
goto P_0c087a62;
P_0c087a62: /* original 7004, guest PC 0x0c087a62 */
if(!s->budget--) { s->failed_pc=0x0c087a62u; return 0; }
r[0]+=0x00000004u;
goto P_0c087a64;
P_0c087a64: /* original f746, guest PC 0x0c087a64 */
if(!s->budget--) { s->failed_pc=0x0c087a64u; return 0; }
vf3_matrix_load(s,ram,7,r[4]+r[0]);
goto P_0c087a66;
P_0c087a66: /* original 7004, guest PC 0x0c087a66 */
if(!s->budget--) { s->failed_pc=0x0c087a66u; return 0; }
r[0]+=0x00000004u;
goto P_0c087a68;
P_0c087a68: /* original f632, guest PC 0x0c087a68 */
if(!s->budget--) { s->failed_pc=0x0c087a68u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[3],r[18],'*');
goto P_0c087a6a;
P_0c087a6a: /* original fa46, guest PC 0x0c087a6a */
if(!s->budget--) { s->failed_pc=0x0c087a6au; return 0; }
vf3_matrix_load(s,ram,10,r[4]+r[0]);
goto P_0c087a6c;
P_0c087a6c: /* original f37c, guest PC 0x0c087a6c */
if(!s->budget--) { s->failed_pc=0x0c087a6cu; return 0; }
vf3_matrix_move(s,3,7);
goto P_0c087a6e;
P_0c087a6e: /* original 7008, guest PC 0x0c087a6e */
if(!s->budget--) { s->failed_pc=0x0c087a6eu; return 0; }
r[0]+=0x00000008u;
goto P_0c087a70;
P_0c087a70: /* original f79c, guest PC 0x0c087a70 */
if(!s->budget--) { s->failed_pc=0x0c087a70u; return 0; }
vf3_matrix_move(s,7,9);
goto P_0c087a72;
P_0c087a72: /* original f732, guest PC 0x0c087a72 */
if(!s->budget--) { s->failed_pc=0x0c087a72u; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[3],r[18],'*');
goto P_0c087a74;
P_0c087a74: /* original fb46, guest PC 0x0c087a74 */
if(!s->budget--) { s->failed_pc=0x0c087a74u; return 0; }
vf3_matrix_load(s,ram,11,r[4]+r[0]);
goto P_0c087a76;
P_0c087a76: /* original f16c, guest PC 0x0c087a76 */
if(!s->budget--) { s->failed_pc=0x0c087a76u; return 0; }
vf3_matrix_move(s,1,6);
goto P_0c087a78;
P_0c087a78: /* original f1a0, guest PC 0x0c087a78 */
if(!s->budget--) { s->failed_pc=0x0c087a78u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[10],r[18],'+');
goto P_0c087a7a;
P_0c087a7a: /* original f07c, guest PC 0x0c087a7a */
if(!s->budget--) { s->failed_pc=0x0c087a7au; return 0; }
vf3_matrix_move(s,0,7);
goto P_0c087a7c;
P_0c087a7c: /* original f0b0, guest PC 0x0c087a7c */
if(!s->budget--) { s->failed_pc=0x0c087a7cu; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[11],r[18],'+');
goto P_0c087a7e;
P_0c087a7e: /* original f31c, guest PC 0x0c087a7e */
if(!s->budget--) { s->failed_pc=0x0c087a7eu; return 0; }
vf3_matrix_move(s,3,1);
goto P_0c087a80;
P_0c087a80: /* original f14c, guest PC 0x0c087a80 */
if(!s->budget--) { s->failed_pc=0x0c087a80u; return 0; }
vf3_matrix_move(s,1,4);
goto P_0c087a82;
P_0c087a82: /* original f131, guest PC 0x0c087a82 */
if(!s->budget--) { s->failed_pc=0x0c087a82u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[3],r[18],'-');
goto P_0c087a84;
P_0c087a84: /* original f30c, guest PC 0x0c087a84 */
if(!s->budget--) { s->failed_pc=0x0c087a84u; return 0; }
vf3_matrix_move(s,3,0);
goto P_0c087a86;
P_0c087a86: /* original f05c, guest PC 0x0c087a86 */
if(!s->budget--) { s->failed_pc=0x0c087a86u; return 0; }
vf3_matrix_move(s,0,5);
goto P_0c087a88;
P_0c087a88: /* original f031, guest PC 0x0c087a88 */
if(!s->budget--) { s->failed_pc=0x0c087a88u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'-');
goto P_0c087a8a;
P_0c087a8a: /* original f36c, guest PC 0x0c087a8a */
if(!s->budget--) { s->failed_pc=0x0c087a8au; return 0; }
vf3_matrix_move(s,3,6);
goto P_0c087a8c;
P_0c087a8c: /* original f6ac, guest PC 0x0c087a8c */
if(!s->budget--) { s->failed_pc=0x0c087a8cu; return 0; }
vf3_matrix_move(s,6,10);
goto P_0c087a8e;
P_0c087a8e: /* original f631, guest PC 0x0c087a8e */
if(!s->budget--) { s->failed_pc=0x0c087a8eu; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[3],r[18],'-');
goto P_0c087a90;
P_0c087a90: /* original f37c, guest PC 0x0c087a90 */
if(!s->budget--) { s->failed_pc=0x0c087a90u; return 0; }
vf3_matrix_move(s,3,7);
goto P_0c087a92;
P_0c087a92: /* original f7bc, guest PC 0x0c087a92 */
if(!s->budget--) { s->failed_pc=0x0c087a92u; return 0; }
vf3_matrix_move(s,7,11);
goto P_0c087a94;
P_0c087a94: /* original f731, guest PC 0x0c087a94 */
if(!s->budget--) { s->failed_pc=0x0c087a94u; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[3],r[18],'-');
goto P_0c087a96;
P_0c087a96: /* original f36c, guest PC 0x0c087a96 */
if(!s->budget--) { s->failed_pc=0x0c087a96u; return 0; }
vf3_matrix_move(s,3,6);
goto P_0c087a98;
P_0c087a98: /* original f64c, guest PC 0x0c087a98 */
if(!s->budget--) { s->failed_pc=0x0c087a98u; return 0; }
vf3_matrix_move(s,6,4);
goto P_0c087a9a;
P_0c087a9a: /* original f631, guest PC 0x0c087a9a */
if(!s->budget--) { s->failed_pc=0x0c087a9au; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[3],r[18],'-');
goto P_0c087a9c;
P_0c087a9c: /* original f815, guest PC 0x0c087a9c */
if(!s->budget--) { s->failed_pc=0x0c087a9cu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[8])>as_float(fr[1]))!=0);
goto P_0c087a9e;
P_0c087a9e: /* original f37c, guest PC 0x0c087a9e */
if(!s->budget--) { s->failed_pc=0x0c087a9eu; return 0; }
vf3_matrix_move(s,3,7);
goto P_0c087aa0;
P_0c087aa0: /* original f75c, guest PC 0x0c087aa0 */
if(!s->budget--) { s->failed_pc=0x0c087aa0u; return 0; }
vf3_matrix_move(s,7,5);
goto P_0c087aa2;
P_0c087aa2: /* original 8f0c, guest PC 0x0c087aa2 */
if(!s->budget--) { s->failed_pc=0x0c087aa2u; return 0; }
cond=r[17]&1u;
fr[7]=vf3_fpu_binary(fr[7],fr[3],r[18],'-');
if(!cond) { goto P_0c087abe; }
goto P_0c087aa6;
P_0c087aa4: /* original f731, guest PC 0x0c087aa4 */
if(!s->budget--) { s->failed_pc=0x0c087aa4u; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[3],r[18],'-');
goto P_0c087aa6;
P_0c087aa6: /* original f805, guest PC 0x0c087aa6 */
if(!s->budget--) { s->failed_pc=0x0c087aa6u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[8])>as_float(fr[0]))!=0);
goto P_0c087aa8;
P_0c087aa8: /* original 8b09, guest PC 0x0c087aa8 */
if(!s->budget--) { s->failed_pc=0x0c087aa8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c087abe; }
goto P_0c087aaa;
P_0c087aaa: /* original c730, guest PC 0x0c087aaa */
if(!s->budget--) { s->failed_pc=0x0c087aaau; return 0; }
r[0]=code_base|0x00087b6cu;
goto P_0c087aac;
P_0c087aac: /* original f308, guest PC 0x0c087aac */
if(!s->budget--) { s->failed_pc=0x0c087aacu; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c087aae;
P_0c087aae: /* original f635, guest PC 0x0c087aae */
if(!s->budget--) { s->failed_pc=0x0c087aaeu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[6])>as_float(fr[3]))!=0);
goto P_0c087ab0;
P_0c087ab0: /* original 8b05, guest PC 0x0c087ab0 */
if(!s->budget--) { s->failed_pc=0x0c087ab0u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c087abe; }
goto P_0c087ab2;
P_0c087ab2: /* original c72e, guest PC 0x0c087ab2 */
if(!s->budget--) { s->failed_pc=0x0c087ab2u; return 0; }
r[0]=code_base|0x00087b6cu;
goto P_0c087ab4;
P_0c087ab4: /* original f308, guest PC 0x0c087ab4 */
if(!s->budget--) { s->failed_pc=0x0c087ab4u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c087ab6;
P_0c087ab6: /* original f735, guest PC 0x0c087ab6 */
if(!s->budget--) { s->failed_pc=0x0c087ab6u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[7])>as_float(fr[3]))!=0);
goto P_0c087ab8;
P_0c087ab8: /* original 8b01, guest PC 0x0c087ab8 */
if(!s->budget--) { s->failed_pc=0x0c087ab8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c087abe; }
goto P_0c087aba;
P_0c087aba: /* original 000b, guest PC 0x0c087aba */
if(!s->budget--) { s->failed_pc=0x0c087abau; return 0; }
target=r[16];
r[0]=r[4];
s->pc=target; return ram->oob==0;
P_0c087abc: /* original 6043, guest PC 0x0c087abc */
if(!s->budget--) { s->failed_pc=0x0c087abcu; return 0; }
r[0]=r[4];
goto P_0c087abe;
P_0c087abe: /* original 7501, guest PC 0x0c087abe */
if(!s->budget--) { s->failed_pc=0x0c087abeu; return 0; }
r[5]+=0x00000001u;
goto P_0c087ac0;
P_0c087ac0: /* original 924c, guest PC 0x0c087ac0 */
if(!s->budget--) { s->failed_pc=0x0c087ac0u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c087b5cu,2);
goto P_0c087ac2;
P_0c087ac2: /* original 3563, guest PC 0x0c087ac2 */
if(!s->budget--) { s->failed_pc=0x0c087ac2u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[5]>=(int32_t)r[6])!=0);
goto P_0c087ac4;
P_0c087ac4: /* original 8fca, guest PC 0x0c087ac4 */
if(!s->budget--) { s->failed_pc=0x0c087ac4u; return 0; }
cond=r[17]&1u;
r[4]+=r[2];
if(!cond) { goto P_0c087a5c; }
goto P_0c087ac8;
P_0c087ac6: /* original 342c, guest PC 0x0c087ac6 */
if(!s->budget--) { s->failed_pc=0x0c087ac6u; return 0; }
r[4]+=r[2];
goto P_0c087ac8;
P_0c087ac8: /* original e000, guest PC 0x0c087ac8 */
if(!s->budget--) { s->failed_pc=0x0c087ac8u; return 0; }
r[0]=0x00000000u;
goto P_0c087aca;
P_0c087aca: /* original 000b, guest PC 0x0c087aca */
if(!s->budget--) { s->failed_pc=0x0c087acau; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c087acc: /* original 0009, guest PC 0x0c087acc */
if(!s->budget--) { s->failed_pc=0x0c087accu; return 0; }
goto P_0c087ace;
P_0c087ace: /* original 2fe6, guest PC 0x0c087ace */
if(!s->budget--) { s->failed_pc=0x0c087aceu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c087ad0;
P_0c087ad0: /* original 2fd6, guest PC 0x0c087ad0 */
if(!s->budget--) { s->failed_pc=0x0c087ad0u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c087ad2;
P_0c087ad2: /* original 6d63, guest PC 0x0c087ad2 */
if(!s->budget--) { s->failed_pc=0x0c087ad2u; return 0; }
r[13]=r[6];
goto P_0c087ad4;
P_0c087ad4: /* original 2fc6, guest PC 0x0c087ad4 */
if(!s->budget--) { s->failed_pc=0x0c087ad4u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c087ad6;
P_0c087ad6: /* original 6c43, guest PC 0x0c087ad6 */
if(!s->budget--) { s->failed_pc=0x0c087ad6u; return 0; }
r[12]=r[4];
goto P_0c087ad8;
P_0c087ad8: /* original 2fb6, guest PC 0x0c087ad8 */
if(!s->budget--) { s->failed_pc=0x0c087ad8u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c087ada;
P_0c087ada: /* original 6b53, guest PC 0x0c087ada */
if(!s->budget--) { s->failed_pc=0x0c087adau; return 0; }
r[11]=r[5];
goto P_0c087adc;
P_0c087adc: /* original 4f22, guest PC 0x0c087adc */
if(!s->budget--) { s->failed_pc=0x0c087adcu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c087ade;
P_0c087ade: /* original 7ffc, guest PC 0x0c087ade */
if(!s->budget--) { s->failed_pc=0x0c087adeu; return 0; }
r[15]+=0xfffffffcu;
goto P_0c087ae0;
P_0c087ae0: /* original 2f72, guest PC 0x0c087ae0 */
if(!s->budget--) { s->failed_pc=0x0c087ae0u; return 0; }
write(ram,r[15],r[7],4);
goto P_0c087ae2;
P_0c087ae2: /* original f5d8, guest PC 0x0c087ae2 */
if(!s->budget--) { s->failed_pc=0x0c087ae2u; return 0; }
vf3_matrix_load(s,ram,5,r[13]);
goto P_0c087ae4;
P_0c087ae4: /* original bfac, guest PC 0x0c087ae4 */
if(!s->budget--) { s->failed_pc=0x0c087ae4u; return 0; }
target=code_base|0x0c087a40u; r[16]=code_base|0x0c087ae8u;
vf3_matrix_load(s,ram,4,r[12]);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c087ae8u) { target=s->pc; goto dispatch; }
goto P_0c087ae8;
P_0c087ae6: /* original f4c8, guest PC 0x0c087ae6 */
if(!s->budget--) { s->failed_pc=0x0c087ae6u; return 0; }
vf3_matrix_load(s,ram,4,r[12]);
goto P_0c087ae8;
P_0c087ae8: /* original 6e03, guest PC 0x0c087ae8 */
if(!s->budget--) { s->failed_pc=0x0c087ae8u; return 0; }
r[14]=r[0];
goto P_0c087aea;
P_0c087aea: /* original 2ee8, guest PC 0x0c087aea */
if(!s->budget--) { s->failed_pc=0x0c087aeau; return 0; }
r[17]=(r[17]&~1u)|(((r[14]&r[14])==0)!=0);
goto P_0c087aec;
P_0c087aec: /* original 892c, guest PC 0x0c087aec */
if(!s->budget--) { s->failed_pc=0x0c087aecu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c087b48; }
goto P_0c087aee;
P_0c087aee: /* original d320, guest PC 0x0c087aee */
if(!s->budget--) { s->failed_pc=0x0c087aeeu; return 0; }
r[3]=read(ram,0x0c087b70u,4);
goto P_0c087af0;
P_0c087af0: /* original 430b, guest PC 0x0c087af0 */
if(!s->budget--) { s->failed_pc=0x0c087af0u; return 0; }
target=r[3];
r[16]=code_base|0x0c087af4u;
r[4]=0x00000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c087af4u) { target=s->pc; goto dispatch; }
goto P_0c087af4;
P_0c087af2: /* original e400, guest PC 0x0c087af2 */
if(!s->budget--) { s->failed_pc=0x0c087af2u; return 0; }
r[4]=0x00000000u;
goto P_0c087af4;
P_0c087af4: /* original d21f, guest PC 0x0c087af4 */
if(!s->budget--) { s->failed_pc=0x0c087af4u; return 0; }
r[2]=read(ram,0x0c087b74u,4);
goto P_0c087af6;
P_0c087af6: /* original 420b, guest PC 0x0c087af6 */
if(!s->budget--) { s->failed_pc=0x0c087af6u; return 0; }
target=r[2];
r[16]=code_base|0x0c087afau;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c087afau) { target=s->pc; goto dispatch; }
goto P_0c087afa;
P_0c087af8: /* original 64e3, guest PC 0x0c087af8 */
if(!s->budget--) { s->failed_pc=0x0c087af8u; return 0; }
r[4]=r[14];
goto P_0c087afa;
P_0c087afa: /* original 9030, guest PC 0x0c087afa */
if(!s->budget--) { s->failed_pc=0x0c087afau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c087b5eu,2);
goto P_0c087afc;
P_0c087afc: /* original 66d3, guest PC 0x0c087afc */
if(!s->budget--) { s->failed_pc=0x0c087afcu; return 0; }
r[6]=r[13];
goto P_0c087afe;
P_0c087afe: /* original f2c8, guest PC 0x0c087afe */
if(!s->budget--) { s->failed_pc=0x0c087afeu; return 0; }
vf3_matrix_load(s,ram,2,r[12]);
goto P_0c087b00;
P_0c087b00: /* original 65b3, guest PC 0x0c087b00 */
if(!s->budget--) { s->failed_pc=0x0c087b00u; return 0; }
r[5]=r[11];
goto P_0c087b02;
P_0c087b02: /* original f3e6, guest PC 0x0c087b02 */
if(!s->budget--) { s->failed_pc=0x0c087b02u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c087b04;
P_0c087b04: /* original 7004, guest PC 0x0c087b04 */
if(!s->budget--) { s->failed_pc=0x0c087b04u; return 0; }
r[0]+=0x00000004u;
goto P_0c087b06;
P_0c087b06: /* original f231, guest PC 0x0c087b06 */
if(!s->budget--) { s->failed_pc=0x0c087b06u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'-');
goto P_0c087b08;
P_0c087b08: /* original fc2a, guest PC 0x0c087b08 */
if(!s->budget--) { s->failed_pc=0x0c087b08u; return 0; }
vf3_matrix_store(s,ram,2,r[12]);
goto P_0c087b0a;
P_0c087b0a: /* original f2b8, guest PC 0x0c087b0a */
if(!s->budget--) { s->failed_pc=0x0c087b0au; return 0; }
vf3_matrix_load(s,ram,2,r[11]);
goto P_0c087b0c;
P_0c087b0c: /* original f3e6, guest PC 0x0c087b0c */
if(!s->budget--) { s->failed_pc=0x0c087b0cu; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c087b0e;
P_0c087b0e: /* original 7004, guest PC 0x0c087b0e */
if(!s->budget--) { s->failed_pc=0x0c087b0eu; return 0; }
r[0]+=0x00000004u;
goto P_0c087b10;
P_0c087b10: /* original f231, guest PC 0x0c087b10 */
if(!s->budget--) { s->failed_pc=0x0c087b10u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'-');
goto P_0c087b12;
P_0c087b12: /* original fb2a, guest PC 0x0c087b12 */
if(!s->budget--) { s->failed_pc=0x0c087b12u; return 0; }
vf3_matrix_store(s,ram,2,r[11]);
goto P_0c087b14;
P_0c087b14: /* original f2d8, guest PC 0x0c087b14 */
if(!s->budget--) { s->failed_pc=0x0c087b14u; return 0; }
vf3_matrix_load(s,ram,2,r[13]);
goto P_0c087b16;
P_0c087b16: /* original f3e6, guest PC 0x0c087b16 */
if(!s->budget--) { s->failed_pc=0x0c087b16u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c087b18;
P_0c087b18: /* original c717, guest PC 0x0c087b18 */
if(!s->budget--) { s->failed_pc=0x0c087b18u; return 0; }
r[0]=code_base|0x00087b78u;
goto P_0c087b1a;
P_0c087b1a: /* original f231, guest PC 0x0c087b1a */
if(!s->budget--) { s->failed_pc=0x0c087b1au; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'-');
goto P_0c087b1c;
P_0c087b1c: /* original fd2a, guest PC 0x0c087b1c */
if(!s->budget--) { s->failed_pc=0x0c087b1cu; return 0; }
vf3_matrix_store(s,ram,2,r[13]);
goto P_0c087b1e;
P_0c087b1e: /* original f308, guest PC 0x0c087b1e */
if(!s->budget--) { s->failed_pc=0x0c087b1eu; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c087b20;
P_0c087b20: /* original f232, guest PC 0x0c087b20 */
if(!s->budget--) { s->failed_pc=0x0c087b20u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c087b22;
P_0c087b22: /* original fd2a, guest PC 0x0c087b22 */
if(!s->budget--) { s->failed_pc=0x0c087b22u; return 0; }
vf3_matrix_store(s,ram,2,r[13]);
goto P_0c087b24;
P_0c087b24: /* original f5b8, guest PC 0x0c087b24 */
if(!s->budget--) { s->failed_pc=0x0c087b24u; return 0; }
vf3_matrix_load(s,ram,5,r[11]);
goto P_0c087b26;
P_0c087b26: /* original f4c8, guest PC 0x0c087b26 */
if(!s->budget--) { s->failed_pc=0x0c087b26u; return 0; }
vf3_matrix_load(s,ram,4,r[12]);
goto P_0c087b28;
P_0c087b28: /* original f62c, guest PC 0x0c087b28 */
if(!s->budget--) { s->failed_pc=0x0c087b28u; return 0; }
vf3_matrix_move(s,6,2);
goto P_0c087b2a;
P_0c087b2a: /* original bde2, guest PC 0x0c087b2a */
if(!s->budget--) { s->failed_pc=0x0c087b2au; return 0; }
target=code_base|0x0c0876f2u; r[16]=code_base|0x0c087b2eu;
r[4]=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c087b2eu) { target=s->pc; goto dispatch; }
goto P_0c087b2e;
P_0c087b2c: /* original 64c3, guest PC 0x0c087b2c */
if(!s->budget--) { s->failed_pc=0x0c087b2cu; return 0; }
r[4]=r[12];
goto P_0c087b2e;
P_0c087b2e: /* original 55f6, guest PC 0x0c087b2e */
if(!s->budget--) { s->failed_pc=0x0c087b2eu; return 0; }
r[5]=read(ram,r[15]+24,4);
goto P_0c087b30;
P_0c087b30: /* original 56f7, guest PC 0x0c087b30 */
if(!s->budget--) { s->failed_pc=0x0c087b30u; return 0; }
r[6]=read(ram,r[15]+28,4);
goto P_0c087b32;
P_0c087b32: /* original bdff, guest PC 0x0c087b32 */
if(!s->budget--) { s->failed_pc=0x0c087b32u; return 0; }
target=code_base|0x0c087734u; r[16]=code_base|0x0c087b36u;
tmp=read(ram,r[15],4);
r[4]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c087b36u) { target=s->pc; goto dispatch; }
goto P_0c087b36;
P_0c087b34: /* original 64f2, guest PC 0x0c087b34 */
if(!s->budget--) { s->failed_pc=0x0c087b34u; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c087b36;
P_0c087b36: /* original 7f04, guest PC 0x0c087b36 */
if(!s->budget--) { s->failed_pc=0x0c087b36u; return 0; }
r[15]+=0x00000004u;
goto P_0c087b38;
P_0c087b38: /* original d210, guest PC 0x0c087b38 */
if(!s->budget--) { s->failed_pc=0x0c087b38u; return 0; }
r[2]=read(ram,0x0c087b7cu,4);
goto P_0c087b3a;
P_0c087b3a: /* original 4f26, guest PC 0x0c087b3a */
if(!s->budget--) { s->failed_pc=0x0c087b3au; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c087b3c;
P_0c087b3c: /* original e401, guest PC 0x0c087b3c */
if(!s->budget--) { s->failed_pc=0x0c087b3cu; return 0; }
r[4]=0x00000001u;
goto P_0c087b3e;
P_0c087b3e: /* original 6bf6, guest PC 0x0c087b3e */
if(!s->budget--) { s->failed_pc=0x0c087b3eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c087b40;
P_0c087b40: /* original 6cf6, guest PC 0x0c087b40 */
if(!s->budget--) { s->failed_pc=0x0c087b40u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c087b42;
P_0c087b42: /* original 6df6, guest PC 0x0c087b42 */
if(!s->budget--) { s->failed_pc=0x0c087b42u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c087b44;
P_0c087b44: /* original 422b, guest PC 0x0c087b44 */
if(!s->budget--) { s->failed_pc=0x0c087b44u; return 0; }
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
P_0c087b46: /* original 6ef6, guest PC 0x0c087b46 */
if(!s->budget--) { s->failed_pc=0x0c087b46u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c087b48;
P_0c087b48: /* original 7f04, guest PC 0x0c087b48 */
if(!s->budget--) { s->failed_pc=0x0c087b48u; return 0; }
r[15]+=0x00000004u;
goto P_0c087b4a;
P_0c087b4a: /* original 4f26, guest PC 0x0c087b4a */
if(!s->budget--) { s->failed_pc=0x0c087b4au; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c087b4c;
P_0c087b4c: /* original 6bf6, guest PC 0x0c087b4c */
if(!s->budget--) { s->failed_pc=0x0c087b4cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c087b4e;
P_0c087b4e: /* original 6cf6, guest PC 0x0c087b4e */
if(!s->budget--) { s->failed_pc=0x0c087b4eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c087b50;
P_0c087b50: /* original 6df6, guest PC 0x0c087b50 */
if(!s->budget--) { s->failed_pc=0x0c087b50u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c087b52;
P_0c087b52: /* original 000b, guest PC 0x0c087b52 */
if(!s->budget--) { s->failed_pc=0x0c087b52u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c087b54: /* original 6ef6, guest PC 0x0c087b54 */
if(!s->budget--) { s->failed_pc=0x0c087b54u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c087b56u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c087b56u; return 0; } return 1;
P_0c087cdc: /* original 2fe6, guest PC 0x0c087cdc */
if(!s->budget--) { s->failed_pc=0x0c087cdcu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c087cde;
P_0c087cde: /* original 2fd6, guest PC 0x0c087cde */
if(!s->budget--) { s->failed_pc=0x0c087cdeu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c087ce0;
P_0c087ce0: /* original 2fc6, guest PC 0x0c087ce0 */
if(!s->budget--) { s->failed_pc=0x0c087ce0u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c087ce2;
P_0c087ce2: /* original 6c43, guest PC 0x0c087ce2 */
if(!s->budget--) { s->failed_pc=0x0c087ce2u; return 0; }
r[12]=r[4];
goto P_0c087ce4;
P_0c087ce4: /* original 2fb6, guest PC 0x0c087ce4 */
if(!s->budget--) { s->failed_pc=0x0c087ce4u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c087ce6;
P_0c087ce6: /* original 2fa6, guest PC 0x0c087ce6 */
if(!s->budget--) { s->failed_pc=0x0c087ce6u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c087ce8;
P_0c087ce8: /* original 2f96, guest PC 0x0c087ce8 */
if(!s->budget--) { s->failed_pc=0x0c087ce8u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c087cea;
P_0c087cea: /* original 2f86, guest PC 0x0c087cea */
if(!s->budget--) { s->failed_pc=0x0c087ceau; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c087cec;
P_0c087cec: /* original fffb, guest PC 0x0c087cec */
if(!s->budget--) { s->failed_pc=0x0c087cecu; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c087cee;
P_0c087cee: /* original ffeb, guest PC 0x0c087cee */
if(!s->budget--) { s->failed_pc=0x0c087ceeu; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,14,r[15]);
goto P_0c087cf0;
P_0c087cf0: /* original 9e6c, guest PC 0x0c087cf0 */
if(!s->budget--) { s->failed_pc=0x0c087cf0u; return 0; }
r[14]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c087dccu,2);
goto P_0c087cf2;
P_0c087cf2: /* original 4f22, guest PC 0x0c087cf2 */
if(!s->budget--) { s->failed_pc=0x0c087cf2u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c087cf4;
P_0c087cf4: /* original dd3a, guest PC 0x0c087cf4 */
if(!s->budget--) { s->failed_pc=0x0c087cf4u; return 0; }
r[13]=read(ram,0x0c087de0u,4);
goto P_0c087cf6;
P_0c087cf6: /* original 3ecc, guest PC 0x0c087cf6 */
if(!s->budget--) { s->failed_pc=0x0c087cf6u; return 0; }
r[14]+=r[12];
goto P_0c087cf8;
P_0c087cf8: /* original d33a, guest PC 0x0c087cf8 */
if(!s->budget--) { s->failed_pc=0x0c087cf8u; return 0; }
r[3]=read(ram,0x0c087de4u,4);
goto P_0c087cfa;
P_0c087cfa: /* original 430b, guest PC 0x0c087cfa */
if(!s->budget--) { s->failed_pc=0x0c087cfau; return 0; }
target=r[3];
r[16]=code_base|0x0c087cfeu;
r[4]=0x00000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c087cfeu) { target=s->pc; goto dispatch; }
goto P_0c087cfe;
P_0c087cfc: /* original e400, guest PC 0x0c087cfc */
if(!s->budget--) { s->failed_pc=0x0c087cfcu; return 0; }
r[4]=0x00000000u;
goto P_0c087cfe;
P_0c087cfe: /* original da3b, guest PC 0x0c087cfe */
if(!s->budget--) { s->failed_pc=0x0c087cfeu; return 0; }
r[10]=read(ram,0x0c087decu,4);
goto P_0c087d00;
P_0c087d00: /* original e908, guest PC 0x0c087d00 */
if(!s->budget--) { s->failed_pc=0x0c087d00u; return 0; }
r[9]=0x00000008u;
goto P_0c087d02;
P_0c087d02: /* original db3b, guest PC 0x0c087d02 */
if(!s->budget--) { s->failed_pc=0x0c087d02u; return 0; }
r[11]=read(ram,0x0c087df0u,4);
goto P_0c087d04;
P_0c087d04: /* original d838, guest PC 0x0c087d04 */
if(!s->budget--) { s->failed_pc=0x0c087d04u; return 0; }
r[8]=read(ram,0x0c087de8u,4);
goto P_0c087d06;
P_0c087d06: /* original ff8d, guest PC 0x0c087d06 */
if(!s->budget--) { s->failed_pc=0x0c087d06u; return 0; }
fr[15]=0;
goto P_0c087d08;
P_0c087d08: /* original fe9d, guest PC 0x0c087d08 */
if(!s->budget--) { s->failed_pc=0x0c087d08u; return 0; }
fr[14]=0x3f800000u;
goto P_0c087d0a;
P_0c087d0a: /* original 4b0b, guest PC 0x0c087d0a */
if(!s->budget--) { s->failed_pc=0x0c087d0au; return 0; }
target=r[11];
r[16]=code_base|0x0c087d0eu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c087d0eu) { target=s->pc; goto dispatch; }
goto P_0c087d0e;
P_0c087d0c: /* original 0009, guest PC 0x0c087d0c */
if(!s->budget--) { s->failed_pc=0x0c087d0cu; return 0; }
goto P_0c087d0e;
P_0c087d0e: /* original e004, guest PC 0x0c087d0e */
if(!s->budget--) { s->failed_pc=0x0c087d0eu; return 0; }
r[0]=0x00000004u;
goto P_0c087d10;
P_0c087d10: /* original f4d8, guest PC 0x0c087d10 */
if(!s->budget--) { s->failed_pc=0x0c087d10u; return 0; }
vf3_matrix_load(s,ram,4,r[13]);
goto P_0c087d12;
P_0c087d12: /* original f5d6, guest PC 0x0c087d12 */
if(!s->budget--) { s->failed_pc=0x0c087d12u; return 0; }
vf3_matrix_load(s,ram,5,r[13]+r[0]);
goto P_0c087d14;
P_0c087d14: /* original e008, guest PC 0x0c087d14 */
if(!s->budget--) { s->failed_pc=0x0c087d14u; return 0; }
r[0]=0x00000008u;
goto P_0c087d16;
P_0c087d16: /* original f6d6, guest PC 0x0c087d16 */
if(!s->budget--) { s->failed_pc=0x0c087d16u; return 0; }
vf3_matrix_load(s,ram,6,r[13]+r[0]);
goto P_0c087d18;
P_0c087d18: /* original 9059, guest PC 0x0c087d18 */
if(!s->budget--) { s->failed_pc=0x0c087d18u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c087dceu,2);
goto P_0c087d1a;
P_0c087d1a: /* original fe47, guest PC 0x0c087d1a */
if(!s->budget--) { s->failed_pc=0x0c087d1au; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c087d1c;
P_0c087d1c: /* original 7004, guest PC 0x0c087d1c */
if(!s->budget--) { s->failed_pc=0x0c087d1cu; return 0; }
r[0]+=0x00000004u;
goto P_0c087d1e;
P_0c087d1e: /* original fe57, guest PC 0x0c087d1e */
if(!s->budget--) { s->failed_pc=0x0c087d1eu; return 0; }
vf3_matrix_store(s,ram,5,r[14]+r[0]);
goto P_0c087d20;
P_0c087d20: /* original 7004, guest PC 0x0c087d20 */
if(!s->budget--) { s->failed_pc=0x0c087d20u; return 0; }
r[0]+=0x00000004u;
goto P_0c087d22;
P_0c087d22: /* original 480b, guest PC 0x0c087d22 */
if(!s->budget--) { s->failed_pc=0x0c087d22u; return 0; }
target=r[8];
r[16]=code_base|0x0c087d26u;
vf3_matrix_store(s,ram,6,r[14]+r[0]);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c087d26u) { target=s->pc; goto dispatch; }
goto P_0c087d26;
P_0c087d24: /* original fe67, guest PC 0x0c087d24 */
if(!s->budget--) { s->failed_pc=0x0c087d24u; return 0; }
vf3_matrix_store(s,ram,6,r[14]+r[0]);
goto P_0c087d26;
P_0c087d26: /* original 4a0b, guest PC 0x0c087d26 */
if(!s->budget--) { s->failed_pc=0x0c087d26u; return 0; }
target=r[10];
r[16]=code_base|0x0c087d2au;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c087d2au) { target=s->pc; goto dispatch; }
goto P_0c087d2a;
P_0c087d28: /* original 64e3, guest PC 0x0c087d28 */
if(!s->budget--) { s->failed_pc=0x0c087d28u; return 0; }
r[4]=r[14];
goto P_0c087d2a;
P_0c087d2a: /* original 4b0b, guest PC 0x0c087d2a */
if(!s->budget--) { s->failed_pc=0x0c087d2au; return 0; }
target=r[11];
r[16]=code_base|0x0c087d2eu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c087d2eu) { target=s->pc; goto dispatch; }
goto P_0c087d2e;
P_0c087d2c: /* original 0009, guest PC 0x0c087d2c */
if(!s->budget--) { s->failed_pc=0x0c087d2cu; return 0; }
goto P_0c087d2e;
P_0c087d2e: /* original 64e3, guest PC 0x0c087d2e */
if(!s->budget--) { s->failed_pc=0x0c087d2eu; return 0; }
r[4]=r[14];
goto P_0c087d30;
P_0c087d30: /* original 4a0b, guest PC 0x0c087d30 */
if(!s->budget--) { s->failed_pc=0x0c087d30u; return 0; }
target=r[10];
r[16]=code_base|0x0c087d34u;
r[4]+=0x00000040u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c087d34u) { target=s->pc; goto dispatch; }
goto P_0c087d34;
P_0c087d32: /* original 7440, guest PC 0x0c087d32 */
if(!s->budget--) { s->failed_pc=0x0c087d32u; return 0; }
r[4]+=0x00000040u;
goto P_0c087d34;
P_0c087d34: /* original e00c, guest PC 0x0c087d34 */
if(!s->budget--) { s->failed_pc=0x0c087d34u; return 0; }
r[0]=0x0000000cu;
goto P_0c087d36;
P_0c087d36: /* original f3d6, guest PC 0x0c087d36 */
if(!s->budget--) { s->failed_pc=0x0c087d36u; return 0; }
vf3_matrix_load(s,ram,3,r[13]+r[0]);
goto P_0c087d38;
P_0c087d38: /* original 4910, guest PC 0x0c087d38 */
if(!s->budget--) { s->failed_pc=0x0c087d38u; return 0; }
--r[9];
r[17]=(r[17]&~1u)|((r[9]==0)!=0);
goto P_0c087d3a;
P_0c087d3a: /* original 9049, guest PC 0x0c087d3a */
if(!s->budget--) { s->failed_pc=0x0c087d3au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c087dd0u,2);
goto P_0c087d3c;
P_0c087d3c: /* original fe37, guest PC 0x0c087d3c */
if(!s->budget--) { s->failed_pc=0x0c087d3cu; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c087d3e;
P_0c087d3e: /* original e010, guest PC 0x0c087d3e */
if(!s->budget--) { s->failed_pc=0x0c087d3eu; return 0; }
r[0]=0x00000010u;
goto P_0c087d40;
P_0c087d40: /* original f3d6, guest PC 0x0c087d40 */
if(!s->budget--) { s->failed_pc=0x0c087d40u; return 0; }
vf3_matrix_load(s,ram,3,r[13]+r[0]);
goto P_0c087d42;
P_0c087d42: /* original 9046, guest PC 0x0c087d42 */
if(!s->budget--) { s->failed_pc=0x0c087d42u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c087dd2u,2);
goto P_0c087d44;
P_0c087d44: /* original fe37, guest PC 0x0c087d44 */
if(!s->budget--) { s->failed_pc=0x0c087d44u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c087d46;
P_0c087d46: /* original e014, guest PC 0x0c087d46 */
if(!s->budget--) { s->failed_pc=0x0c087d46u; return 0; }
r[0]=0x00000014u;
goto P_0c087d48;
P_0c087d48: /* original f3d6, guest PC 0x0c087d48 */
if(!s->budget--) { s->failed_pc=0x0c087d48u; return 0; }
vf3_matrix_load(s,ram,3,r[13]+r[0]);
goto P_0c087d4a;
P_0c087d4a: /* original 707c, guest PC 0x0c087d4a */
if(!s->budget--) { s->failed_pc=0x0c087d4au; return 0; }
r[0]+=0x0000007cu;
goto P_0c087d4c;
P_0c087d4c: /* original fe37, guest PC 0x0c087d4c */
if(!s->budget--) { s->failed_pc=0x0c087d4cu; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c087d4e;
P_0c087d4e: /* original e018, guest PC 0x0c087d4e */
if(!s->budget--) { s->failed_pc=0x0c087d4eu; return 0; }
r[0]=0x00000018u;
goto P_0c087d50;
P_0c087d50: /* original f3d6, guest PC 0x0c087d50 */
if(!s->budget--) { s->failed_pc=0x0c087d50u; return 0; }
vf3_matrix_load(s,ram,3,r[13]+r[0]);
goto P_0c087d52;
P_0c087d52: /* original 707c, guest PC 0x0c087d52 */
if(!s->budget--) { s->failed_pc=0x0c087d52u; return 0; }
r[0]+=0x0000007cu;
goto P_0c087d54;
P_0c087d54: /* original fe37, guest PC 0x0c087d54 */
if(!s->budget--) { s->failed_pc=0x0c087d54u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c087d56;
P_0c087d56: /* original 913d, guest PC 0x0c087d56 */
if(!s->budget--) { s->failed_pc=0x0c087d56u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c087dd4u,2);
goto P_0c087d58;
P_0c087d58: /* original 85de, guest PC 0x0c087d58 */
if(!s->budget--) { s->failed_pc=0x0c087d58u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[13]+28,2);
goto P_0c087d5a;
P_0c087d5a: /* original 7d20, guest PC 0x0c087d5a */
if(!s->budget--) { s->failed_pc=0x0c087d5au; return 0; }
r[13]+=0x00000020u;
goto P_0c087d5c;
P_0c087d5c: /* original 31ec, guest PC 0x0c087d5c */
if(!s->budget--) { s->failed_pc=0x0c087d5cu; return 0; }
r[1]+=r[14];
goto P_0c087d5e;
P_0c087d5e: /* original 2101, guest PC 0x0c087d5e */
if(!s->budget--) { s->failed_pc=0x0c087d5eu; return 0; }
write(ram,r[1],r[0],2);
goto P_0c087d60;
P_0c087d60: /* original 9039, guest PC 0x0c087d60 */
if(!s->budget--) { s->failed_pc=0x0c087d60u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c087dd6u,2);
goto P_0c087d62;
P_0c087d62: /* original fee7, guest PC 0x0c087d62 */
if(!s->budget--) { s->failed_pc=0x0c087d62u; return 0; }
vf3_matrix_store(s,ram,14,r[14]+r[0]);
goto P_0c087d64;
P_0c087d64: /* original 7004, guest PC 0x0c087d64 */
if(!s->budget--) { s->failed_pc=0x0c087d64u; return 0; }
r[0]+=0x00000004u;
goto P_0c087d66;
P_0c087d66: /* original fef7, guest PC 0x0c087d66 */
if(!s->budget--) { s->failed_pc=0x0c087d66u; return 0; }
vf3_matrix_store(s,ram,15,r[14]+r[0]);
goto P_0c087d68;
P_0c087d68: /* original 7004, guest PC 0x0c087d68 */
if(!s->budget--) { s->failed_pc=0x0c087d68u; return 0; }
r[0]+=0x00000004u;
goto P_0c087d6a;
P_0c087d6a: /* original fef7, guest PC 0x0c087d6a */
if(!s->budget--) { s->failed_pc=0x0c087d6au; return 0; }
vf3_matrix_store(s,ram,15,r[14]+r[0]);
goto P_0c087d6c;
P_0c087d6c: /* original 7004, guest PC 0x0c087d6c */
if(!s->budget--) { s->failed_pc=0x0c087d6cu; return 0; }
r[0]+=0x00000004u;
goto P_0c087d6e;
P_0c087d6e: /* original fef7, guest PC 0x0c087d6e */
if(!s->budget--) { s->failed_pc=0x0c087d6eu; return 0; }
vf3_matrix_store(s,ram,15,r[14]+r[0]);
goto P_0c087d70;
P_0c087d70: /* original 9332, guest PC 0x0c087d70 */
if(!s->budget--) { s->failed_pc=0x0c087d70u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c087dd8u,2);
goto P_0c087d72;
P_0c087d72: /* original 8fca, guest PC 0x0c087d72 */
if(!s->budget--) { s->failed_pc=0x0c087d72u; return 0; }
cond=r[17]&1u;
r[14]+=r[3];
if(!cond) { goto P_0c087d0a; }
goto P_0c087d76;
P_0c087d74: /* original 3e3c, guest PC 0x0c087d74 */
if(!s->budget--) { s->failed_pc=0x0c087d74u; return 0; }
r[14]+=r[3];
goto P_0c087d76;
P_0c087d76: /* original d31f, guest PC 0x0c087d76 */
if(!s->budget--) { s->failed_pc=0x0c087d76u; return 0; }
r[3]=read(ram,0x0c087df4u,4);
goto P_0c087d78;
P_0c087d78: /* original 430b, guest PC 0x0c087d78 */
if(!s->budget--) { s->failed_pc=0x0c087d78u; return 0; }
target=r[3];
r[16]=code_base|0x0c087d7cu;
r[4]=0x00000001u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c087d7cu) { target=s->pc; goto dispatch; }
goto P_0c087d7c;
P_0c087d7a: /* original e401, guest PC 0x0c087d7a */
if(!s->budget--) { s->failed_pc=0x0c087d7au; return 0; }
r[4]=0x00000001u;
goto P_0c087d7c;
P_0c087d7c: /* original c71e, guest PC 0x0c087d7c */
if(!s->budget--) { s->failed_pc=0x0c087d7cu; return 0; }
r[0]=code_base|0x00087df8u;
goto P_0c087d7e;
P_0c087d7e: /* original f308, guest PC 0x0c087d7e */
if(!s->budget--) { s->failed_pc=0x0c087d7eu; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c087d80;
P_0c087d80: /* original e344, guest PC 0x0c087d80 */
if(!s->budget--) { s->failed_pc=0x0c087d80u; return 0; }
r[3]=0x00000044u;
goto P_0c087d82;
P_0c087d82: /* original 902a, guest PC 0x0c087d82 */
if(!s->budget--) { s->failed_pc=0x0c087d82u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c087ddau,2);
goto P_0c087d84;
P_0c087d84: /* original e2f6, guest PC 0x0c087d84 */
if(!s->budget--) { s->failed_pc=0x0c087d84u; return 0; }
r[2]=0xfffffff6u;
goto P_0c087d86;
P_0c087d86: /* original e600, guest PC 0x0c087d86 */
if(!s->budget--) { s->failed_pc=0x0c087d86u; return 0; }
r[6]=0x00000000u;
goto P_0c087d88;
P_0c087d88: /* original fc37, guest PC 0x0c087d88 */
if(!s->budget--) { s->failed_pc=0x0c087d88u; return 0; }
vf3_matrix_store(s,ram,3,r[12]+r[0]);
goto P_0c087d8a;
P_0c087d8a: /* original c71c, guest PC 0x0c087d8a */
if(!s->budget--) { s->failed_pc=0x0c087d8au; return 0; }
r[0]=code_base|0x00087dfcu;
goto P_0c087d8c;
P_0c087d8c: /* original f308, guest PC 0x0c087d8c */
if(!s->budget--) { s->failed_pc=0x0c087d8cu; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c087d8e;
P_0c087d8e: /* original 9025, guest PC 0x0c087d8e */
if(!s->budget--) { s->failed_pc=0x0c087d8eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c087ddcu,2);
goto P_0c087d90;
P_0c087d90: /* original 4f26, guest PC 0x0c087d90 */
if(!s->budget--) { s->failed_pc=0x0c087d90u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c087d92;
P_0c087d92: /* original fc37, guest PC 0x0c087d92 */
if(!s->budget--) { s->failed_pc=0x0c087d92u; return 0; }
vf3_matrix_store(s,ram,3,r[12]+r[0]);
goto P_0c087d94;
P_0c087d94: /* original 7004, guest PC 0x0c087d94 */
if(!s->budget--) { s->failed_pc=0x0c087d94u; return 0; }
r[0]+=0x00000004u;
goto P_0c087d96;
P_0c087d96: /* original 0c36, guest PC 0x0c087d96 */
if(!s->budget--) { s->failed_pc=0x0c087d96u; return 0; }
write(ram,r[12]+r[0],r[3],4);
goto P_0c087d98;
P_0c087d98: /* original 7004, guest PC 0x0c087d98 */
if(!s->budget--) { s->failed_pc=0x0c087d98u; return 0; }
r[0]+=0x00000004u;
goto P_0c087d9a;
P_0c087d9a: /* original 0c26, guest PC 0x0c087d9a */
if(!s->budget--) { s->failed_pc=0x0c087d9au; return 0; }
write(ram,r[12]+r[0],r[2],4);
goto P_0c087d9c;
P_0c087d9c: /* original 7004, guest PC 0x0c087d9c */
if(!s->budget--) { s->failed_pc=0x0c087d9cu; return 0; }
r[0]+=0x00000004u;
goto P_0c087d9e;
P_0c087d9e: /* original 0c66, guest PC 0x0c087d9e */
if(!s->budget--) { s->failed_pc=0x0c087d9eu; return 0; }
write(ram,r[12]+r[0],r[6],4);
goto P_0c087da0;
P_0c087da0: /* original d517, guest PC 0x0c087da0 */
if(!s->budget--) { s->failed_pc=0x0c087da0u; return 0; }
r[5]=read(ram,0x0c087e00u,4);
goto P_0c087da2;
P_0c087da2: /* original 901c, guest PC 0x0c087da2 */
if(!s->budget--) { s->failed_pc=0x0c087da2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c087ddeu,2);
goto P_0c087da4;
P_0c087da4: /* original 5454, guest PC 0x0c087da4 */
if(!s->budget--) { s->failed_pc=0x0c087da4u; return 0; }
r[4]=read(ram,r[5]+16,4);
goto P_0c087da6;
P_0c087da6: /* original 5555, guest PC 0x0c087da6 */
if(!s->budget--) { s->failed_pc=0x0c087da6u; return 0; }
r[5]=read(ram,r[5]+20,4);
goto P_0c087da8;
P_0c087da8: /* original f5f7, guest PC 0x0c087da8 */
if(!s->budget--) { s->failed_pc=0x0c087da8u; return 0; }
vf3_matrix_store(s,ram,15,r[5]+r[0]);
goto P_0c087daa;
P_0c087daa: /* original f4f7, guest PC 0x0c087daa */
if(!s->budget--) { s->failed_pc=0x0c087daau; return 0; }
vf3_matrix_store(s,ram,15,r[4]+r[0]);
goto P_0c087dac;
P_0c087dac: /* original 70fc, guest PC 0x0c087dac */
if(!s->budget--) { s->failed_pc=0x0c087dacu; return 0; }
r[0]+=0xfffffffcu;
goto P_0c087dae;
P_0c087dae: /* original f5f7, guest PC 0x0c087dae */
if(!s->budget--) { s->failed_pc=0x0c087daeu; return 0; }
vf3_matrix_store(s,ram,15,r[5]+r[0]);
goto P_0c087db0;
P_0c087db0: /* original f4f7, guest PC 0x0c087db0 */
if(!s->budget--) { s->failed_pc=0x0c087db0u; return 0; }
vf3_matrix_store(s,ram,15,r[4]+r[0]);
goto P_0c087db2;
P_0c087db2: /* original 7008, guest PC 0x0c087db2 */
if(!s->budget--) { s->failed_pc=0x0c087db2u; return 0; }
r[0]+=0x00000008u;
goto P_0c087db4;
P_0c087db4: /* original 0566, guest PC 0x0c087db4 */
if(!s->budget--) { s->failed_pc=0x0c087db4u; return 0; }
write(ram,r[5]+r[0],r[6],4);
goto P_0c087db6;
P_0c087db6: /* original 0466, guest PC 0x0c087db6 */
if(!s->budget--) { s->failed_pc=0x0c087db6u; return 0; }
write(ram,r[4]+r[0],r[6],4);
goto P_0c087db8;
P_0c087db8: /* original fef9, guest PC 0x0c087db8 */
if(!s->budget--) { s->failed_pc=0x0c087db8u; return 0; }
vf3_matrix_load(s,ram,14,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c087dba;
P_0c087dba: /* original fff9, guest PC 0x0c087dba */
if(!s->budget--) { s->failed_pc=0x0c087dbau; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c087dbc;
P_0c087dbc: /* original 68f6, guest PC 0x0c087dbc */
if(!s->budget--) { s->failed_pc=0x0c087dbcu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c087dbe;
P_0c087dbe: /* original 69f6, guest PC 0x0c087dbe */
if(!s->budget--) { s->failed_pc=0x0c087dbeu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c087dc0;
P_0c087dc0: /* original 6af6, guest PC 0x0c087dc0 */
if(!s->budget--) { s->failed_pc=0x0c087dc0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c087dc2;
P_0c087dc2: /* original 6bf6, guest PC 0x0c087dc2 */
if(!s->budget--) { s->failed_pc=0x0c087dc2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c087dc4;
P_0c087dc4: /* original 6cf6, guest PC 0x0c087dc4 */
if(!s->budget--) { s->failed_pc=0x0c087dc4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c087dc6;
P_0c087dc6: /* original 6df6, guest PC 0x0c087dc6 */
if(!s->budget--) { s->failed_pc=0x0c087dc6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c087dc8;
P_0c087dc8: /* original 000b, guest PC 0x0c087dc8 */
if(!s->budget--) { s->failed_pc=0x0c087dc8u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c087dca: /* original 6ef6, guest PC 0x0c087dca */
if(!s->budget--) { s->failed_pc=0x0c087dcau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c087dccu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c087dccu; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
