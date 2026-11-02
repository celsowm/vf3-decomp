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
int vf3_away_batch67_adapter_1(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c03cba0u: goto P_0c03cba0;
case 0x0c03cba2u: goto P_0c03cba2;
case 0x0c03cba4u: goto P_0c03cba4;
case 0x0c03cba6u: goto P_0c03cba6;
case 0x0c03cba8u: goto P_0c03cba8;
case 0x0c03cbaau: goto P_0c03cbaa;
case 0x0c03cbacu: goto P_0c03cbac;
case 0x0c03cbaeu: goto P_0c03cbae;
case 0x0c03cbb0u: goto P_0c03cbb0;
case 0x0c03cbb2u: goto P_0c03cbb2;
case 0x0c03cbb4u: goto P_0c03cbb4;
case 0x0c03cbb6u: goto P_0c03cbb6;
case 0x0c03cbb8u: goto P_0c03cbb8;
case 0x0c03cbbau: goto P_0c03cbba;
case 0x0c03cbbcu: goto P_0c03cbbc;
case 0x0c03cbbeu: goto P_0c03cbbe;
case 0x0c03cbc0u: goto P_0c03cbc0;
case 0x0c03cbc2u: goto P_0c03cbc2;
case 0x0c03cbc4u: goto P_0c03cbc4;
case 0x0c03cbc6u: goto P_0c03cbc6;
case 0x0c03cbc8u: goto P_0c03cbc8;
case 0x0c03cbcau: goto P_0c03cbca;
case 0x0c03cd70u: goto P_0c03cd70;
case 0x0c03cd72u: goto P_0c03cd72;
case 0x0c03cd74u: goto P_0c03cd74;
case 0x0c03cd76u: goto P_0c03cd76;
case 0x0c03cd78u: goto P_0c03cd78;
case 0x0c03cd7au: goto P_0c03cd7a;
case 0x0c03cd7cu: goto P_0c03cd7c;
case 0x0c03cd7eu: goto P_0c03cd7e;
case 0x0c03cd80u: goto P_0c03cd80;
case 0x0c03cd82u: goto P_0c03cd82;
case 0x0c03cd84u: goto P_0c03cd84;
case 0x0c03cd86u: goto P_0c03cd86;
case 0x0c03cdb0u: goto P_0c03cdb0;
case 0x0c03cdb2u: goto P_0c03cdb2;
case 0x0c03cdb4u: goto P_0c03cdb4;
case 0x0c03cdb6u: goto P_0c03cdb6;
case 0x0c03cdb8u: goto P_0c03cdb8;
case 0x0c03cdbau: goto P_0c03cdba;
case 0x0c03cdbcu: goto P_0c03cdbc;
case 0x0c03cdbeu: goto P_0c03cdbe;
case 0x0c03cdc0u: goto P_0c03cdc0;
case 0x0c03cdc2u: goto P_0c03cdc2;
case 0x0c03cdc4u: goto P_0c03cdc4;
case 0x0c03cdc6u: goto P_0c03cdc6;
case 0x0c03cdc8u: goto P_0c03cdc8;
case 0x0c03cdcau: goto P_0c03cdca;
case 0x0c03cdccu: goto P_0c03cdcc;
case 0x0c03cdceu: goto P_0c03cdce;
case 0x0c03cdd0u: goto P_0c03cdd0;
case 0x0c03cdd2u: goto P_0c03cdd2;
case 0x0c03cdd4u: goto P_0c03cdd4;
case 0x0c03cdd6u: goto P_0c03cdd6;
case 0x0c03cdd8u: goto P_0c03cdd8;
case 0x0c03cddau: goto P_0c03cdda;
case 0x0c03cddcu: goto P_0c03cddc;
case 0x0c03cddeu: goto P_0c03cdde;
case 0x0c03cde0u: goto P_0c03cde0;
case 0x0c03cde2u: goto P_0c03cde2;
case 0x0c03d040u: goto P_0c03d040;
case 0x0c03d042u: goto P_0c03d042;
case 0x0c03d044u: goto P_0c03d044;
case 0x0c03d046u: goto P_0c03d046;
case 0x0c03d048u: goto P_0c03d048;
case 0x0c03d060u: goto P_0c03d060;
case 0x0c03d062u: goto P_0c03d062;
case 0x0c03d064u: goto P_0c03d064;
case 0x0c03d066u: goto P_0c03d066;
case 0x0c03d068u: goto P_0c03d068;
case 0x0c03d06au: goto P_0c03d06a;
case 0x0c03d06cu: goto P_0c03d06c;
case 0x0c03d06eu: goto P_0c03d06e;
case 0x0c03d070u: goto P_0c03d070;
case 0x0c03d072u: goto P_0c03d072;
case 0x0c03d074u: goto P_0c03d074;
case 0x0c03d076u: goto P_0c03d076;
case 0x0c03d078u: goto P_0c03d078;
case 0x0c03d07au: goto P_0c03d07a;
case 0x0c03d07cu: goto P_0c03d07c;
case 0x0c03d07eu: goto P_0c03d07e;
case 0x0c03d080u: goto P_0c03d080;
case 0x0c03d082u: goto P_0c03d082;
case 0x0c093a9cu: goto P_0c093a9c;
case 0x0c093a9eu: goto P_0c093a9e;
case 0x0c093aa0u: goto P_0c093aa0;
case 0x0c093aa2u: goto P_0c093aa2;
case 0x0c093aa4u: goto P_0c093aa4;
case 0x0c093aa6u: goto P_0c093aa6;
case 0x0c093aa8u: goto P_0c093aa8;
case 0x0c093aaau: goto P_0c093aaa;
case 0x0c093aacu: goto P_0c093aac;
case 0x0c093aaeu: goto P_0c093aae;
case 0x0c093ab0u: goto P_0c093ab0;
case 0x0c093ab2u: goto P_0c093ab2;
case 0x0c093ab4u: goto P_0c093ab4;
case 0x0c093ab8u: goto P_0c093ab8;
case 0x0c093abau: goto P_0c093aba;
case 0x0c093abcu: goto P_0c093abc;
case 0x0c093abeu: goto P_0c093abe;
case 0x0c093ac0u: goto P_0c093ac0;
case 0x0c093ac2u: goto P_0c093ac2;
case 0x0c093ac4u: goto P_0c093ac4;
case 0x0c093ac6u: goto P_0c093ac6;
case 0x0c093ac8u: goto P_0c093ac8;
case 0x0c093acau: goto P_0c093aca;
case 0x0c093accu: goto P_0c093acc;
case 0x0c093aceu: goto P_0c093ace;
case 0x0c093ad0u: goto P_0c093ad0;
case 0x0c093ad2u: goto P_0c093ad2;
case 0x0c093ad4u: goto P_0c093ad4;
case 0x0c093ad6u: goto P_0c093ad6;
case 0x0c093ad8u: goto P_0c093ad8;
case 0x0c093adau: goto P_0c093ada;
case 0x0c093adcu: goto P_0c093adc;
case 0x0c093adeu: goto P_0c093ade;
case 0x0c093ae0u: goto P_0c093ae0;
case 0x0c093ae2u: goto P_0c093ae2;
case 0x0c093ae4u: goto P_0c093ae4;
case 0x0c093ae6u: goto P_0c093ae6;
case 0x0c093ae8u: goto P_0c093ae8;
case 0x0c093aeau: goto P_0c093aea;
case 0x0c093aecu: goto P_0c093aec;
case 0x0c093aeeu: goto P_0c093aee;
case 0x0c093af0u: goto P_0c093af0;
case 0x0c093af2u: goto P_0c093af2;
case 0x0c093af4u: goto P_0c093af4;
case 0x0c093af6u: goto P_0c093af6;
case 0x0c093af8u: goto P_0c093af8;
case 0x0c093afau: goto P_0c093afa;
case 0x0c093afcu: goto P_0c093afc;
case 0x0c093afeu: goto P_0c093afe;
case 0x0c093b00u: goto P_0c093b00;
case 0x0c093b02u: goto P_0c093b02;
case 0x0c093b04u: goto P_0c093b04;
case 0x0c093b06u: goto P_0c093b06;
case 0x0c093b08u: goto P_0c093b08;
case 0x0c093b10u: goto P_0c093b10;
case 0x0c093b12u: goto P_0c093b12;
case 0x0c093b14u: goto P_0c093b14;
case 0x0c093b16u: goto P_0c093b16;
case 0x0c093b18u: goto P_0c093b18;
case 0x0c093b1au: goto P_0c093b1a;
case 0x0c093b1cu: goto P_0c093b1c;
case 0x0c093b1eu: goto P_0c093b1e;
case 0x0c093b20u: goto P_0c093b20;
case 0x0c093b22u: goto P_0c093b22;
case 0x0c093b24u: goto P_0c093b24;
case 0x0c093b26u: goto P_0c093b26;
case 0x0c093b28u: goto P_0c093b28;
case 0x0c093b2au: goto P_0c093b2a;
case 0x0c093b2cu: goto P_0c093b2c;
case 0x0c093b2eu: goto P_0c093b2e;
case 0x0c093b30u: goto P_0c093b30;
case 0x0c093b32u: goto P_0c093b32;
case 0x0c093b34u: goto P_0c093b34;
case 0x0c093b36u: goto P_0c093b36;
case 0x0c093b38u: goto P_0c093b38;
case 0x0c093b3au: goto P_0c093b3a;
case 0x0c093b3cu: goto P_0c093b3c;
case 0x0c093b3eu: goto P_0c093b3e;
case 0x0c093b40u: goto P_0c093b40;
case 0x0c093b42u: goto P_0c093b42;
case 0x0c093b44u: goto P_0c093b44;
case 0x0c093b46u: goto P_0c093b46;
case 0x0c093b48u: goto P_0c093b48;
case 0x0c093b4au: goto P_0c093b4a;
case 0x0c093b4cu: goto P_0c093b4c;
case 0x0c093b4eu: goto P_0c093b4e;
case 0x0c093b50u: goto P_0c093b50;
case 0x0c093b52u: goto P_0c093b52;
case 0x0c093beau: goto P_0c093bea;
case 0x0c093becu: goto P_0c093bec;
case 0x0c093beeu: goto P_0c093bee;
case 0x0c093bf0u: goto P_0c093bf0;
case 0x0c093bf2u: goto P_0c093bf2;
case 0x0c093bf4u: goto P_0c093bf4;
case 0x0c093bf6u: goto P_0c093bf6;
case 0x0c093bf8u: goto P_0c093bf8;
case 0x0c093bfau: goto P_0c093bfa;
case 0x0c093bfcu: goto P_0c093bfc;
case 0x0c093bfeu: goto P_0c093bfe;
case 0x0c093c00u: goto P_0c093c00;
case 0x0c093c02u: goto P_0c093c02;
case 0x0c093c04u: goto P_0c093c04;
case 0x0c093c06u: goto P_0c093c06;
case 0x0c093c08u: goto P_0c093c08;
case 0x0c093c0au: goto P_0c093c0a;
case 0x0c093c0cu: goto P_0c093c0c;
case 0x0c093c0eu: goto P_0c093c0e;
case 0x0c093c10u: goto P_0c093c10;
case 0x0c093c12u: goto P_0c093c12;
case 0x0c093c14u: goto P_0c093c14;
case 0x0c093c16u: goto P_0c093c16;
case 0x0c093c18u: goto P_0c093c18;
case 0x0c093c1au: goto P_0c093c1a;
case 0x0c093c1cu: goto P_0c093c1c;
case 0x0c093c1eu: goto P_0c093c1e;
case 0x0c093c20u: goto P_0c093c20;
case 0x0c093c22u: goto P_0c093c22;
case 0x0c093c24u: goto P_0c093c24;
case 0x0c093c26u: goto P_0c093c26;
case 0x0c093c28u: goto P_0c093c28;
case 0x0c093c2au: goto P_0c093c2a;
case 0x0c093c2cu: goto P_0c093c2c;
case 0x0c093c2eu: goto P_0c093c2e;
case 0x0c093c30u: goto P_0c093c30;
case 0x0c093c4cu: goto P_0c093c4c;
case 0x0c093c4eu: goto P_0c093c4e;
case 0x0c093c50u: goto P_0c093c50;
case 0x0c093c52u: goto P_0c093c52;
case 0x0c093c54u: goto P_0c093c54;
case 0x0c093c56u: goto P_0c093c56;
case 0x0c093c58u: goto P_0c093c58;
case 0x0c093c5au: goto P_0c093c5a;
case 0x0c093c5cu: goto P_0c093c5c;
case 0x0c093c5eu: goto P_0c093c5e;
case 0x0c093c60u: goto P_0c093c60;
case 0x0c093c62u: goto P_0c093c62;
case 0x0c093c64u: goto P_0c093c64;
case 0x0c093c66u: goto P_0c093c66;
case 0x0c093c68u: goto P_0c093c68;
case 0x0c093c6au: goto P_0c093c6a;
case 0x0c093c6cu: goto P_0c093c6c;
case 0x0c093c6eu: goto P_0c093c6e;
case 0x0c093c70u: goto P_0c093c70;
case 0x0c093c72u: goto P_0c093c72;
case 0x0c093c74u: goto P_0c093c74;
case 0x0c093c76u: goto P_0c093c76;
case 0x0c093c78u: goto P_0c093c78;
case 0x0c093c7au: goto P_0c093c7a;
case 0x0c093c7cu: goto P_0c093c7c;
case 0x0c093c7eu: goto P_0c093c7e;
case 0x0c093c80u: goto P_0c093c80;
case 0x0c093c82u: goto P_0c093c82;
case 0x0c093c84u: goto P_0c093c84;
case 0x0c093c86u: goto P_0c093c86;
case 0x0c093c88u: goto P_0c093c88;
case 0x0c093c8au: goto P_0c093c8a;
case 0x0c093c8cu: goto P_0c093c8c;
case 0x0c093c8eu: goto P_0c093c8e;
case 0x0c093c90u: goto P_0c093c90;
case 0x0c093c92u: goto P_0c093c92;
case 0x0c093c94u: goto P_0c093c94;
case 0x0c093c96u: goto P_0c093c96;
case 0x0c093c98u: goto P_0c093c98;
case 0x0c093c9au: goto P_0c093c9a;
case 0x0c093c9cu: goto P_0c093c9c;
case 0x0c093c9eu: goto P_0c093c9e;
case 0x0c093ca0u: goto P_0c093ca0;
case 0x0c093ca2u: goto P_0c093ca2;
case 0x0c093ca4u: goto P_0c093ca4;
case 0x0c093ca6u: goto P_0c093ca6;
case 0x0c093ca8u: goto P_0c093ca8;
case 0x0c093caau: goto P_0c093caa;
default: return vf3_matrix_family(target,s,ram);
}
P_0c03cba0: /* original fbfd, guest PC 0x0c03cba0 */
if(!s->budget--) { s->failed_pc=0x0c03cba0u; return 0; }
vf3_matrix_swap(s);
goto P_0c03cba2;
P_0c03cba2: /* original ff1d, guest PC 0x0c03cba2 */
if(!s->budget--) { s->failed_pc=0x0c03cba2u; return 0; }
r[53]=fr[15];
goto P_0c03cba4;
P_0c03cba4: /* original ff49, guest PC 0x0c03cba4 */
if(!s->budget--) { s->failed_pc=0x0c03cba4u; return 0; }
vf3_matrix_load(s,ram,15,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c03cba6;
P_0c03cba6: /* original f0f2, guest PC 0x0c03cba6 */
if(!s->budget--) { s->failed_pc=0x0c03cba6u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[15],r[18],'*');
goto P_0c03cba8;
P_0c03cba8: /* original f1f2, guest PC 0x0c03cba8 */
if(!s->budget--) { s->failed_pc=0x0c03cba8u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[15],r[18],'*');
goto P_0c03cbaa;
P_0c03cbaa: /* original f2f2, guest PC 0x0c03cbaa */
if(!s->budget--) { s->failed_pc=0x0c03cbaau; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[15],r[18],'*');
goto P_0c03cbac;
P_0c03cbac: /* original f3f2, guest PC 0x0c03cbac */
if(!s->budget--) { s->failed_pc=0x0c03cbacu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[15],r[18],'*');
goto P_0c03cbae;
P_0c03cbae: /* original ff49, guest PC 0x0c03cbae */
if(!s->budget--) { s->failed_pc=0x0c03cbaeu; return 0; }
vf3_matrix_load(s,ram,15,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c03cbb0;
P_0c03cbb0: /* original f4f2, guest PC 0x0c03cbb0 */
if(!s->budget--) { s->failed_pc=0x0c03cbb0u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[15],r[18],'*');
goto P_0c03cbb2;
P_0c03cbb2: /* original f5f2, guest PC 0x0c03cbb2 */
if(!s->budget--) { s->failed_pc=0x0c03cbb2u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[15],r[18],'*');
goto P_0c03cbb4;
P_0c03cbb4: /* original f6f2, guest PC 0x0c03cbb4 */
if(!s->budget--) { s->failed_pc=0x0c03cbb4u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[15],r[18],'*');
goto P_0c03cbb6;
P_0c03cbb6: /* original f7f2, guest PC 0x0c03cbb6 */
if(!s->budget--) { s->failed_pc=0x0c03cbb6u; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[15],r[18],'*');
goto P_0c03cbb8;
P_0c03cbb8: /* original ff49, guest PC 0x0c03cbb8 */
if(!s->budget--) { s->failed_pc=0x0c03cbb8u; return 0; }
vf3_matrix_load(s,ram,15,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c03cbba;
P_0c03cbba: /* original f8f2, guest PC 0x0c03cbba */
if(!s->budget--) { s->failed_pc=0x0c03cbbau; return 0; }
fr[8]=vf3_fpu_binary(fr[8],fr[15],r[18],'*');
goto P_0c03cbbc;
P_0c03cbbc: /* original f9f2, guest PC 0x0c03cbbc */
if(!s->budget--) { s->failed_pc=0x0c03cbbcu; return 0; }
fr[9]=vf3_fpu_binary(fr[9],fr[15],r[18],'*');
goto P_0c03cbbe;
P_0c03cbbe: /* original faf2, guest PC 0x0c03cbbe */
if(!s->budget--) { s->failed_pc=0x0c03cbbeu; return 0; }
fr[10]=vf3_fpu_binary(fr[10],fr[15],r[18],'*');
goto P_0c03cbc0;
P_0c03cbc0: /* original fbf2, guest PC 0x0c03cbc0 */
if(!s->budget--) { s->failed_pc=0x0c03cbc0u; return 0; }
fr[11]=vf3_fpu_binary(fr[11],fr[15],r[18],'*');
goto P_0c03cbc2;
P_0c03cbc2: /* original ff0d, guest PC 0x0c03cbc2 */
if(!s->budget--) { s->failed_pc=0x0c03cbc2u; return 0; }
fr[15]=r[53];
goto P_0c03cbc4;
P_0c03cbc4: /* original fbfd, guest PC 0x0c03cbc4 */
if(!s->budget--) { s->failed_pc=0x0c03cbc4u; return 0; }
vf3_matrix_swap(s);
goto P_0c03cbc6;
P_0c03cbc6: /* original 0009, guest PC 0x0c03cbc6 */
if(!s->budget--) { s->failed_pc=0x0c03cbc6u; return 0; }
goto P_0c03cbc8;
P_0c03cbc8: /* original 000b, guest PC 0x0c03cbc8 */
if(!s->budget--) { s->failed_pc=0x0c03cbc8u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c03cbca: /* original 0009, guest PC 0x0c03cbca */
if(!s->budget--) { s->failed_pc=0x0c03cbcau; return 0; }
if(!vf3_matrix_family(0x0c03cbccu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c03cbccu; return 0; } return 1;
P_0c03cd70: /* original f049, guest PC 0x0c03cd70 */
if(!s->budget--) { s->failed_pc=0x0c03cd70u; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c03cd72;
P_0c03cd72: /* original f149, guest PC 0x0c03cd72 */
if(!s->budget--) { s->failed_pc=0x0c03cd72u; return 0; }
vf3_matrix_load(s,ram,1,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c03cd74;
P_0c03cd74: /* original f249, guest PC 0x0c03cd74 */
if(!s->budget--) { s->failed_pc=0x0c03cd74u; return 0; }
vf3_matrix_load(s,ram,2,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c03cd76;
P_0c03cd76: /* original f38d, guest PC 0x0c03cd76 */
if(!s->budget--) { s->failed_pc=0x0c03cd76u; return 0; }
fr[3]=0;
goto P_0c03cd78;
P_0c03cd78: /* original f459, guest PC 0x0c03cd78 */
if(!s->budget--) { s->failed_pc=0x0c03cd78u; return 0; }
vf3_matrix_load(s,ram,4,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c03cd7a;
P_0c03cd7a: /* original f559, guest PC 0x0c03cd7a */
if(!s->budget--) { s->failed_pc=0x0c03cd7au; return 0; }
vf3_matrix_load(s,ram,5,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c03cd7c;
P_0c03cd7c: /* original f659, guest PC 0x0c03cd7c */
if(!s->budget--) { s->failed_pc=0x0c03cd7cu; return 0; }
vf3_matrix_load(s,ram,6,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c03cd7e;
P_0c03cd7e: /* original f78d, guest PC 0x0c03cd7e */
if(!s->budget--) { s->failed_pc=0x0c03cd7eu; return 0; }
fr[7]=0;
goto P_0c03cd80;
P_0c03cd80: /* original f4ed, guest PC 0x0c03cd80 */
if(!s->budget--) { s->failed_pc=0x0c03cd80u; return 0; }
if(!vf3_fpu_fipr(fr+0,fr+4,r[18],fr+7)) goto unsupported;
goto P_0c03cd82;
P_0c03cd82: /* original f07c, guest PC 0x0c03cd82 */
if(!s->budget--) { s->failed_pc=0x0c03cd82u; return 0; }
vf3_matrix_move(s,0,7);
goto P_0c03cd84;
P_0c03cd84: /* original 000b, guest PC 0x0c03cd84 */
if(!s->budget--) { s->failed_pc=0x0c03cd84u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c03cd86: /* original 0009, guest PC 0x0c03cd86 */
if(!s->budget--) { s->failed_pc=0x0c03cd86u; return 0; }
if(!vf3_matrix_family(0x0c03cd88u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c03cd88u; return 0; } return 1;
P_0c03cdb0: /* original f049, guest PC 0x0c03cdb0 */
if(!s->budget--) { s->failed_pc=0x0c03cdb0u; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c03cdb2;
P_0c03cdb2: /* original f549, guest PC 0x0c03cdb2 */
if(!s->budget--) { s->failed_pc=0x0c03cdb2u; return 0; }
vf3_matrix_load(s,ram,5,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c03cdb4;
P_0c03cdb4: /* original f648, guest PC 0x0c03cdb4 */
if(!s->budget--) { s->failed_pc=0x0c03cdb4u; return 0; }
vf3_matrix_load(s,ram,6,r[4]);
goto P_0c03cdb6;
P_0c03cdb6: /* original f859, guest PC 0x0c03cdb6 */
if(!s->budget--) { s->failed_pc=0x0c03cdb6u; return 0; }
vf3_matrix_load(s,ram,8,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c03cdb8;
P_0c03cdb8: /* original f959, guest PC 0x0c03cdb8 */
if(!s->budget--) { s->failed_pc=0x0c03cdb8u; return 0; }
vf3_matrix_load(s,ram,9,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c03cdba;
P_0c03cdba: /* original fa58, guest PC 0x0c03cdba */
if(!s->budget--) { s->failed_pc=0x0c03cdbau; return 0; }
vf3_matrix_load(s,ram,10,r[5]);
goto P_0c03cdbc;
P_0c03cdbc: /* original 760c, guest PC 0x0c03cdbc */
if(!s->budget--) { s->failed_pc=0x0c03cdbcu; return 0; }
r[6]+=0x0000000cu;
goto P_0c03cdbe;
P_0c03cdbe: /* original f35c, guest PC 0x0c03cdbe */
if(!s->budget--) { s->failed_pc=0x0c03cdbeu; return 0; }
vf3_matrix_move(s,3,5);
goto P_0c03cdc0;
P_0c03cdc0: /* original f382, guest PC 0x0c03cdc0 */
if(!s->budget--) { s->failed_pc=0x0c03cdc0u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[8],r[18],'*');
goto P_0c03cdc2;
P_0c03cdc2: /* original f20c, guest PC 0x0c03cdc2 */
if(!s->budget--) { s->failed_pc=0x0c03cdc2u; return 0; }
vf3_matrix_move(s,2,0);
goto P_0c03cdc4;
P_0c03cdc4: /* original f2a2, guest PC 0x0c03cdc4 */
if(!s->budget--) { s->failed_pc=0x0c03cdc4u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[10],r[18],'*');
goto P_0c03cdc6;
P_0c03cdc6: /* original f16c, guest PC 0x0c03cdc6 */
if(!s->budget--) { s->failed_pc=0x0c03cdc6u; return 0; }
vf3_matrix_move(s,1,6);
goto P_0c03cdc8;
P_0c03cdc8: /* original f192, guest PC 0x0c03cdc8 */
if(!s->budget--) { s->failed_pc=0x0c03cdc8u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[9],r[18],'*');
goto P_0c03cdca;
P_0c03cdca: /* original f34d, guest PC 0x0c03cdca */
if(!s->budget--) { s->failed_pc=0x0c03cdcau; return 0; }
fr[3]^=0x80000000u;
goto P_0c03cdcc;
P_0c03cdcc: /* original f39e, guest PC 0x0c03cdcc */
if(!s->budget--) { s->failed_pc=0x0c03cdccu; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[9],fr[3],r[18]);
goto P_0c03cdce;
P_0c03cdce: /* original f24d, guest PC 0x0c03cdce */
if(!s->budget--) { s->failed_pc=0x0c03cdceu; return 0; }
fr[2]^=0x80000000u;
goto P_0c03cdd0;
P_0c03cdd0: /* original f06c, guest PC 0x0c03cdd0 */
if(!s->budget--) { s->failed_pc=0x0c03cdd0u; return 0; }
vf3_matrix_move(s,0,6);
goto P_0c03cdd2;
P_0c03cdd2: /* original f28e, guest PC 0x0c03cdd2 */
if(!s->budget--) { s->failed_pc=0x0c03cdd2u; return 0; }
fr[2]=vf3_fpu_mac(fr[0],fr[8],fr[2],r[18]);
goto P_0c03cdd4;
P_0c03cdd4: /* original f14d, guest PC 0x0c03cdd4 */
if(!s->budget--) { s->failed_pc=0x0c03cdd4u; return 0; }
fr[1]^=0x80000000u;
goto P_0c03cdd6;
P_0c03cdd6: /* original f63b, guest PC 0x0c03cdd6 */
if(!s->budget--) { s->failed_pc=0x0c03cdd6u; return 0; }
r[6]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,3,r[6]);
goto P_0c03cdd8;
P_0c03cdd8: /* original f05c, guest PC 0x0c03cdd8 */
if(!s->budget--) { s->failed_pc=0x0c03cdd8u; return 0; }
vf3_matrix_move(s,0,5);
goto P_0c03cdda;
P_0c03cdda: /* original f1ae, guest PC 0x0c03cdda */
if(!s->budget--) { s->failed_pc=0x0c03cddau; return 0; }
fr[1]=vf3_fpu_mac(fr[0],fr[10],fr[1],r[18]);
goto P_0c03cddc;
P_0c03cddc: /* original f62b, guest PC 0x0c03cddc */
if(!s->budget--) { s->failed_pc=0x0c03cddcu; return 0; }
r[6]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[6]);
goto P_0c03cdde;
P_0c03cdde: /* original f61b, guest PC 0x0c03cdde */
if(!s->budget--) { s->failed_pc=0x0c03cddeu; return 0; }
r[6]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[6]);
goto P_0c03cde0;
P_0c03cde0: /* original 000b, guest PC 0x0c03cde0 */
if(!s->budget--) { s->failed_pc=0x0c03cde0u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c03cde2: /* original 0009, guest PC 0x0c03cde2 */
if(!s->budget--) { s->failed_pc=0x0c03cde2u; return 0; }
if(!vf3_matrix_family(0x0c03cde4u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c03cde4u; return 0; } return 1;
P_0c03d040: /* original 7ffc, guest PC 0x0c03d040 */
if(!s->budget--) { s->failed_pc=0x0c03d040u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c03d042;
P_0c03d042: /* original 6543, guest PC 0x0c03d042 */
if(!s->budget--) { s->failed_pc=0x0c03d042u; return 0; }
r[5]=r[4];
goto P_0c03d044;
P_0c03d044: /* original 2f42, guest PC 0x0c03d044 */
if(!s->budget--) { s->failed_pc=0x0c03d044u; return 0; }
write(ram,r[15],r[4],4);
goto P_0c03d046;
P_0c03d046: /* original a00b, guest PC 0x0c03d046 */
if(!s->budget--) { s->failed_pc=0x0c03d046u; return 0; }
goto P_0c03d060;
P_0c03d048: /* original 0009, guest PC 0x0c03d048 */
if(!s->budget--) { s->failed_pc=0x0c03d048u; return 0; }
if(!vf3_matrix_family(0x0c03d04au,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c03d04au; return 0; } return 1;
P_0c03d060: /* original f449, guest PC 0x0c03d060 */
if(!s->budget--) { s->failed_pc=0x0c03d060u; return 0; }
vf3_matrix_load(s,ram,4,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c03d062;
P_0c03d062: /* original f549, guest PC 0x0c03d062 */
if(!s->budget--) { s->failed_pc=0x0c03d062u; return 0; }
vf3_matrix_load(s,ram,5,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c03d064;
P_0c03d064: /* original f649, guest PC 0x0c03d064 */
if(!s->budget--) { s->failed_pc=0x0c03d064u; return 0; }
vf3_matrix_load(s,ram,6,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c03d066;
P_0c03d066: /* original f78d, guest PC 0x0c03d066 */
if(!s->budget--) { s->failed_pc=0x0c03d066u; return 0; }
fr[7]=0;
goto P_0c03d068;
P_0c03d068: /* original 750c, guest PC 0x0c03d068 */
if(!s->budget--) { s->failed_pc=0x0c03d068u; return 0; }
r[5]+=0x0000000cu;
goto P_0c03d06a;
P_0c03d06a: /* original f5ed, guest PC 0x0c03d06a */
if(!s->budget--) { s->failed_pc=0x0c03d06au; return 0; }
if(!vf3_fpu_fipr(fr+4,fr+4,r[18],fr+7)) goto unsupported;
goto P_0c03d06c;
P_0c03d06c: /* original f07c, guest PC 0x0c03d06c */
if(!s->budget--) { s->failed_pc=0x0c03d06cu; return 0; }
vf3_matrix_move(s,0,7);
goto P_0c03d06e;
P_0c03d06e: /* original f06d, guest PC 0x0c03d06e */
if(!s->budget--) { s->failed_pc=0x0c03d06eu; return 0; }
fr[0]=vf3_fpu_sqrt(fr[0],r[18]);
goto P_0c03d070;
P_0c03d070: /* original f77d, guest PC 0x0c03d070 */
if(!s->budget--) { s->failed_pc=0x0c03d070u; return 0; }
if(!vf3_fpu_fsrra(fr[7],r[18],&fr[7])) goto unsupported;
goto P_0c03d072;
P_0c03d072: /* original f672, guest PC 0x0c03d072 */
if(!s->budget--) { s->failed_pc=0x0c03d072u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[7],r[18],'*');
goto P_0c03d074;
P_0c03d074: /* original f572, guest PC 0x0c03d074 */
if(!s->budget--) { s->failed_pc=0x0c03d074u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[7],r[18],'*');
goto P_0c03d076;
P_0c03d076: /* original f472, guest PC 0x0c03d076 */
if(!s->budget--) { s->failed_pc=0x0c03d076u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[7],r[18],'*');
goto P_0c03d078;
P_0c03d078: /* original f56b, guest PC 0x0c03d078 */
if(!s->budget--) { s->failed_pc=0x0c03d078u; return 0; }
r[5]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,6,r[5]);
goto P_0c03d07a;
P_0c03d07a: /* original f55b, guest PC 0x0c03d07a */
if(!s->budget--) { s->failed_pc=0x0c03d07au; return 0; }
r[5]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,5,r[5]);
goto P_0c03d07c;
P_0c03d07c: /* original f54b, guest PC 0x0c03d07c */
if(!s->budget--) { s->failed_pc=0x0c03d07cu; return 0; }
r[5]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,4,r[5]);
goto P_0c03d07e;
P_0c03d07e: /* original 0009, guest PC 0x0c03d07e */
if(!s->budget--) { s->failed_pc=0x0c03d07eu; return 0; }
goto P_0c03d080;
P_0c03d080: /* original 000b, guest PC 0x0c03d080 */
if(!s->budget--) { s->failed_pc=0x0c03d080u; return 0; }
target=r[16];
r[15]+=0x00000004u;
s->pc=target; return ram->oob==0;
P_0c03d082: /* original 7f04, guest PC 0x0c03d082 */
if(!s->budget--) { s->failed_pc=0x0c03d082u; return 0; }
r[15]+=0x00000004u;
if(!vf3_matrix_family(0x0c03d084u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c03d084u; return 0; } return 1;
P_0c093a9c: /* original 2fe6, guest PC 0x0c093a9c */
if(!s->budget--) { s->failed_pc=0x0c093a9cu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c093a9e;
P_0c093a9e: /* original 6e43, guest PC 0x0c093a9e */
if(!s->budget--) { s->failed_pc=0x0c093a9eu; return 0; }
r[14]=r[4];
goto P_0c093aa0;
P_0c093aa0: /* original 7fe8, guest PC 0x0c093aa0 */
if(!s->budget--) { s->failed_pc=0x0c093aa0u; return 0; }
r[15]+=0xffffffe8u;
goto P_0c093aa2;
P_0c093aa2: /* original 64f3, guest PC 0x0c093aa2 */
if(!s->budget--) { s->failed_pc=0x0c093aa2u; return 0; }
r[4]=r[15];
goto P_0c093aa4;
P_0c093aa4: /* original 1f52, guest PC 0x0c093aa4 */
if(!s->budget--) { s->failed_pc=0x0c093aa4u; return 0; }
write(ram,r[15]+8,r[5],4);
goto P_0c093aa6;
P_0c093aa6: /* original e004, guest PC 0x0c093aa6 */
if(!s->budget--) { s->failed_pc=0x0c093aa6u; return 0; }
r[0]=0x00000004u;
goto P_0c093aa8;
P_0c093aa8: /* original 65e3, guest PC 0x0c093aa8 */
if(!s->budget--) { s->failed_pc=0x0c093aa8u; return 0; }
r[5]=r[14];
goto P_0c093aaa;
P_0c093aaa: /* original 740c, guest PC 0x0c093aaa */
if(!s->budget--) { s->failed_pc=0x0c093aaau; return 0; }
r[4]+=0x0000000cu;
goto P_0c093aac;
P_0c093aac: /* original ff47, guest PC 0x0c093aac */
if(!s->budget--) { s->failed_pc=0x0c093aacu; return 0; }
vf3_matrix_store(s,ram,4,r[15]+r[0]);
goto P_0c093aae;
P_0c093aae: /* original 2f62, guest PC 0x0c093aae */
if(!s->budget--) { s->failed_pc=0x0c093aaeu; return 0; }
write(ram,r[15],r[6],4);
goto P_0c093ab0;
P_0c093ab0: /* original 56f2, guest PC 0x0c093ab0 */
if(!s->budget--) { s->failed_pc=0x0c093ab0u; return 0; }
r[6]=read(ram,r[15]+8,4);
goto P_0c093ab2;
P_0c093ab2: /* original a001, guest PC 0x0c093ab2 */
if(!s->budget--) { s->failed_pc=0x0c093ab2u; return 0; }
goto P_0c093ab8;
P_0c093ab4: /* original 0009, guest PC 0x0c093ab4 */
if(!s->budget--) { s->failed_pc=0x0c093ab4u; return 0; }
if(!vf3_matrix_family(0x0c093ab6u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c093ab6u; return 0; } return 1;
P_0c093ab8: /* original f059, guest PC 0x0c093ab8 */
if(!s->budget--) { s->failed_pc=0x0c093ab8u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c093aba;
P_0c093aba: /* original f369, guest PC 0x0c093aba */
if(!s->budget--) { s->failed_pc=0x0c093abau; return 0; }
vf3_matrix_load(s,ram,3,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c093abc;
P_0c093abc: /* original f159, guest PC 0x0c093abc */
if(!s->budget--) { s->failed_pc=0x0c093abcu; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c093abe;
P_0c093abe: /* original f469, guest PC 0x0c093abe */
if(!s->budget--) { s->failed_pc=0x0c093abeu; return 0; }
vf3_matrix_load(s,ram,4,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c093ac0;
P_0c093ac0: /* original f031, guest PC 0x0c093ac0 */
if(!s->budget--) { s->failed_pc=0x0c093ac0u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'-');
goto P_0c093ac2;
P_0c093ac2: /* original f258, guest PC 0x0c093ac2 */
if(!s->budget--) { s->failed_pc=0x0c093ac2u; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
goto P_0c093ac4;
P_0c093ac4: /* original f568, guest PC 0x0c093ac4 */
if(!s->budget--) { s->failed_pc=0x0c093ac4u; return 0; }
vf3_matrix_load(s,ram,5,r[6]);
goto P_0c093ac6;
P_0c093ac6: /* original f141, guest PC 0x0c093ac6 */
if(!s->budget--) { s->failed_pc=0x0c093ac6u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'-');
goto P_0c093ac8;
P_0c093ac8: /* original f251, guest PC 0x0c093ac8 */
if(!s->budget--) { s->failed_pc=0x0c093ac8u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'-');
goto P_0c093aca;
P_0c093aca: /* original 7408, guest PC 0x0c093aca */
if(!s->budget--) { s->failed_pc=0x0c093acau; return 0; }
r[4]+=0x00000008u;
goto P_0c093acc;
P_0c093acc: /* original f42a, guest PC 0x0c093acc */
if(!s->budget--) { s->failed_pc=0x0c093accu; return 0; }
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c093ace;
P_0c093ace: /* original f41b, guest PC 0x0c093ace */
if(!s->budget--) { s->failed_pc=0x0c093aceu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c093ad0;
P_0c093ad0: /* original f40b, guest PC 0x0c093ad0 */
if(!s->budget--) { s->failed_pc=0x0c093ad0u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c093ad2;
P_0c093ad2: /* original 0009, guest PC 0x0c093ad2 */
if(!s->budget--) { s->failed_pc=0x0c093ad2u; return 0; }
goto P_0c093ad4;
P_0c093ad4: /* original 64f3, guest PC 0x0c093ad4 */
if(!s->budget--) { s->failed_pc=0x0c093ad4u; return 0; }
r[4]=r[15];
goto P_0c093ad6;
P_0c093ad6: /* original 740c, guest PC 0x0c093ad6 */
if(!s->budget--) { s->failed_pc=0x0c093ad6u; return 0; }
r[4]+=0x0000000cu;
goto P_0c093ad8;
P_0c093ad8: /* original f049, guest PC 0x0c093ad8 */
if(!s->budget--) { s->failed_pc=0x0c093ad8u; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c093ada;
P_0c093ada: /* original f149, guest PC 0x0c093ada */
if(!s->budget--) { s->failed_pc=0x0c093adau; return 0; }
vf3_matrix_load(s,ram,1,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c093adc;
P_0c093adc: /* original f249, guest PC 0x0c093adc */
if(!s->budget--) { s->failed_pc=0x0c093adcu; return 0; }
vf3_matrix_load(s,ram,2,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c093ade;
P_0c093ade: /* original f38d, guest PC 0x0c093ade */
if(!s->budget--) { s->failed_pc=0x0c093adeu; return 0; }
fr[3]=0;
goto P_0c093ae0;
P_0c093ae0: /* original f0ed, guest PC 0x0c093ae0 */
if(!s->budget--) { s->failed_pc=0x0c093ae0u; return 0; }
if(!vf3_fpu_fipr(fr+0,fr+0,r[18],fr+3)) goto unsupported;
goto P_0c093ae2;
P_0c093ae2: /* original f03c, guest PC 0x0c093ae2 */
if(!s->budget--) { s->failed_pc=0x0c093ae2u; return 0; }
vf3_matrix_move(s,0,3);
goto P_0c093ae4;
P_0c093ae4: /* original f06d, guest PC 0x0c093ae4 */
if(!s->budget--) { s->failed_pc=0x0c093ae4u; return 0; }
fr[0]=vf3_fpu_sqrt(fr[0],r[18]);
goto P_0c093ae6;
P_0c093ae6: /* original 0009, guest PC 0x0c093ae6 */
if(!s->budget--) { s->failed_pc=0x0c093ae6u; return 0; }
goto P_0c093ae8;
P_0c093ae8: /* original e004, guest PC 0x0c093ae8 */
if(!s->budget--) { s->failed_pc=0x0c093ae8u; return 0; }
r[0]=0x00000004u;
goto P_0c093aea;
P_0c093aea: /* original f40c, guest PC 0x0c093aea */
if(!s->budget--) { s->failed_pc=0x0c093aeau; return 0; }
vf3_matrix_move(s,4,0);
goto P_0c093aec;
P_0c093aec: /* original f3f6, guest PC 0x0c093aec */
if(!s->budget--) { s->failed_pc=0x0c093aecu; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c093aee;
P_0c093aee: /* original f345, guest PC 0x0c093aee */
if(!s->budget--) { s->failed_pc=0x0c093aeeu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[4]))!=0);
goto P_0c093af0;
P_0c093af0: /* original 8902, guest PC 0x0c093af0 */
if(!s->budget--) { s->failed_pc=0x0c093af0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c093af8; }
goto P_0c093af2;
P_0c093af2: /* original d306, guest PC 0x0c093af2 */
if(!s->budget--) { s->failed_pc=0x0c093af2u; return 0; }
r[3]=read(ram,0x0c093b0cu,4);
goto P_0c093af4;
P_0c093af4: /* original 432b, guest PC 0x0c093af4 */
if(!s->budget--) { s->failed_pc=0x0c093af4u; return 0; }
target=r[3];
code_base=target&0xff000000u;
switch(target&0x1fffffffu) {
case 0x0c093b4au: goto P_0c093b4a;
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
P_0c093af6: /* original 0009, guest PC 0x0c093af6 */
if(!s->budget--) { s->failed_pc=0x0c093af6u; return 0; }
goto P_0c093af8;
P_0c093af8: /* original e004, guest PC 0x0c093af8 */
if(!s->budget--) { s->failed_pc=0x0c093af8u; return 0; }
r[0]=0x00000004u;
goto P_0c093afa;
P_0c093afa: /* original f34c, guest PC 0x0c093afa */
if(!s->budget--) { s->failed_pc=0x0c093afau; return 0; }
vf3_matrix_move(s,3,4);
goto P_0c093afc;
P_0c093afc: /* original f4f6, guest PC 0x0c093afc */
if(!s->budget--) { s->failed_pc=0x0c093afcu; return 0; }
vf3_matrix_load(s,ram,4,r[15]+r[0]);
goto P_0c093afe;
P_0c093afe: /* original 65f3, guest PC 0x0c093afe */
if(!s->budget--) { s->failed_pc=0x0c093afeu; return 0; }
r[5]=r[15];
goto P_0c093b00;
P_0c093b00: /* original 64e3, guest PC 0x0c093b00 */
if(!s->budget--) { s->failed_pc=0x0c093b00u; return 0; }
r[4]=r[14];
goto P_0c093b02;
P_0c093b02: /* original 750c, guest PC 0x0c093b02 */
if(!s->budget--) { s->failed_pc=0x0c093b02u; return 0; }
r[5]+=0x0000000cu;
goto P_0c093b04;
P_0c093b04: /* original f433, guest PC 0x0c093b04 */
if(!s->budget--) { s->failed_pc=0x0c093b04u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'/');
goto P_0c093b06;
P_0c093b06: /* original a003, guest PC 0x0c093b06 */
if(!s->budget--) { s->failed_pc=0x0c093b06u; return 0; }
goto P_0c093b10;
P_0c093b08: /* original 0009, guest PC 0x0c093b08 */
if(!s->budget--) { s->failed_pc=0x0c093b08u; return 0; }
if(!vf3_matrix_family(0x0c093b0au,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c093b0au; return 0; } return 1;
P_0c093b10: /* original f059, guest PC 0x0c093b10 */
if(!s->budget--) { s->failed_pc=0x0c093b10u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c093b12;
P_0c093b12: /* original f159, guest PC 0x0c093b12 */
if(!s->budget--) { s->failed_pc=0x0c093b12u; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c093b14;
P_0c093b14: /* original f259, guest PC 0x0c093b14 */
if(!s->budget--) { s->failed_pc=0x0c093b14u; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c093b16;
P_0c093b16: /* original 740c, guest PC 0x0c093b16 */
if(!s->budget--) { s->failed_pc=0x0c093b16u; return 0; }
r[4]+=0x0000000cu;
goto P_0c093b18;
P_0c093b18: /* original f242, guest PC 0x0c093b18 */
if(!s->budget--) { s->failed_pc=0x0c093b18u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[4],r[18],'*');
goto P_0c093b1a;
P_0c093b1a: /* original f142, guest PC 0x0c093b1a */
if(!s->budget--) { s->failed_pc=0x0c093b1au; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'*');
goto P_0c093b1c;
P_0c093b1c: /* original f042, guest PC 0x0c093b1c */
if(!s->budget--) { s->failed_pc=0x0c093b1cu; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[4],r[18],'*');
goto P_0c093b1e;
P_0c093b1e: /* original f42b, guest PC 0x0c093b1e */
if(!s->budget--) { s->failed_pc=0x0c093b1eu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c093b20;
P_0c093b20: /* original f41b, guest PC 0x0c093b20 */
if(!s->budget--) { s->failed_pc=0x0c093b20u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c093b22;
P_0c093b22: /* original f40b, guest PC 0x0c093b22 */
if(!s->budget--) { s->failed_pc=0x0c093b22u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c093b24;
P_0c093b24: /* original 55f2, guest PC 0x0c093b24 */
if(!s->budget--) { s->failed_pc=0x0c093b24u; return 0; }
r[5]=read(ram,r[15]+8,4);
goto P_0c093b26;
P_0c093b26: /* original 64e3, guest PC 0x0c093b26 */
if(!s->budget--) { s->failed_pc=0x0c093b26u; return 0; }
r[4]=r[14];
goto P_0c093b28;
P_0c093b28: /* original f049, guest PC 0x0c093b28 */
if(!s->budget--) { s->failed_pc=0x0c093b28u; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c093b2a;
P_0c093b2a: /* original f359, guest PC 0x0c093b2a */
if(!s->budget--) { s->failed_pc=0x0c093b2au; return 0; }
vf3_matrix_load(s,ram,3,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c093b2c;
P_0c093b2c: /* original f149, guest PC 0x0c093b2c */
if(!s->budget--) { s->failed_pc=0x0c093b2cu; return 0; }
vf3_matrix_load(s,ram,1,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c093b2e;
P_0c093b2e: /* original f459, guest PC 0x0c093b2e */
if(!s->budget--) { s->failed_pc=0x0c093b2eu; return 0; }
vf3_matrix_load(s,ram,4,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c093b30;
P_0c093b30: /* original f249, guest PC 0x0c093b30 */
if(!s->budget--) { s->failed_pc=0x0c093b30u; return 0; }
vf3_matrix_load(s,ram,2,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c093b32;
P_0c093b32: /* original f559, guest PC 0x0c093b32 */
if(!s->budget--) { s->failed_pc=0x0c093b32u; return 0; }
vf3_matrix_load(s,ram,5,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c093b34;
P_0c093b34: /* original f030, guest PC 0x0c093b34 */
if(!s->budget--) { s->failed_pc=0x0c093b34u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'+');
goto P_0c093b36;
P_0c093b36: /* original f250, guest PC 0x0c093b36 */
if(!s->budget--) { s->failed_pc=0x0c093b36u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'+');
goto P_0c093b38;
P_0c093b38: /* original f140, guest PC 0x0c093b38 */
if(!s->budget--) { s->failed_pc=0x0c093b38u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'+');
goto P_0c093b3a;
P_0c093b3a: /* original f42b, guest PC 0x0c093b3a */
if(!s->budget--) { s->failed_pc=0x0c093b3au; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c093b3c;
P_0c093b3c: /* original f41b, guest PC 0x0c093b3c */
if(!s->budget--) { s->failed_pc=0x0c093b3cu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c093b3e;
P_0c093b3e: /* original f40b, guest PC 0x0c093b3e */
if(!s->budget--) { s->failed_pc=0x0c093b3eu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c093b40;
P_0c093b40: /* original 63f2, guest PC 0x0c093b40 */
if(!s->budget--) { s->failed_pc=0x0c093b40u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c093b42;
P_0c093b42: /* original 9276, guest PC 0x0c093b42 */
if(!s->budget--) { s->failed_pc=0x0c093b42u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c093c32u,2);
goto P_0c093b44;
P_0c093b44: /* original 6132, guest PC 0x0c093b44 */
if(!s->budget--) { s->failed_pc=0x0c093b44u; return 0; }
tmp=read(ram,r[3],4);
r[1]=tmp;
goto P_0c093b46;
P_0c093b46: /* original 212b, guest PC 0x0c093b46 */
if(!s->budget--) { s->failed_pc=0x0c093b46u; return 0; }
r[1]|=r[2];
goto P_0c093b48;
P_0c093b48: /* original 2312, guest PC 0x0c093b48 */
if(!s->budget--) { s->failed_pc=0x0c093b48u; return 0; }
write(ram,r[3],r[1],4);
goto P_0c093b4a;
P_0c093b4a: /* original 60f2, guest PC 0x0c093b4a */
if(!s->budget--) { s->failed_pc=0x0c093b4au; return 0; }
tmp=read(ram,r[15],4);
r[0]=tmp;
goto P_0c093b4c;
P_0c093b4c: /* original 7f18, guest PC 0x0c093b4c */
if(!s->budget--) { s->failed_pc=0x0c093b4cu; return 0; }
r[15]+=0x00000018u;
goto P_0c093b4e;
P_0c093b4e: /* original 6002, guest PC 0x0c093b4e */
if(!s->budget--) { s->failed_pc=0x0c093b4eu; return 0; }
tmp=read(ram,r[0],4);
r[0]=tmp;
goto P_0c093b50;
P_0c093b50: /* original 000b, guest PC 0x0c093b50 */
if(!s->budget--) { s->failed_pc=0x0c093b50u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c093b52: /* original 6ef6, guest PC 0x0c093b52 */
if(!s->budget--) { s->failed_pc=0x0c093b52u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c093b54u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c093b54u; return 0; } return 1;
P_0c093bea: /* original 2fe6, guest PC 0x0c093bea */
if(!s->budget--) { s->failed_pc=0x0c093beau; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c093bec;
P_0c093bec: /* original 6e43, guest PC 0x0c093bec */
if(!s->budget--) { s->failed_pc=0x0c093becu; return 0; }
r[14]=r[4];
goto P_0c093bee;
P_0c093bee: /* original 2fd6, guest PC 0x0c093bee */
if(!s->budget--) { s->failed_pc=0x0c093beeu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c093bf0;
P_0c093bf0: /* original 6d53, guest PC 0x0c093bf0 */
if(!s->budget--) { s->failed_pc=0x0c093bf0u; return 0; }
r[13]=r[5];
goto P_0c093bf2;
P_0c093bf2: /* original 2fc6, guest PC 0x0c093bf2 */
if(!s->budget--) { s->failed_pc=0x0c093bf2u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c093bf4;
P_0c093bf4: /* original 2fb6, guest PC 0x0c093bf4 */
if(!s->budget--) { s->failed_pc=0x0c093bf4u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c093bf6;
P_0c093bf6: /* original 2fa6, guest PC 0x0c093bf6 */
if(!s->budget--) { s->failed_pc=0x0c093bf6u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c093bf8;
P_0c093bf8: /* original 84d4, guest PC 0x0c093bf8 */
if(!s->budget--) { s->failed_pc=0x0c093bf8u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+4,1);
goto P_0c093bfa;
P_0c093bfa: /* original 4f22, guest PC 0x0c093bfa */
if(!s->budget--) { s->failed_pc=0x0c093bfau; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c093bfc;
P_0c093bfc: /* original 2008, guest PC 0x0c093bfc */
if(!s->budget--) { s->failed_pc=0x0c093bfcu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c093bfe;
P_0c093bfe: /* original 8f25, guest PC 0x0c093bfe */
if(!s->budget--) { s->failed_pc=0x0c093bfeu; return 0; }
cond=r[17]&1u;
r[5]=0x00000001u;
if(!cond) { goto P_0c093c4c; }
goto P_0c093c02;
P_0c093c00: /* original e501, guest PC 0x0c093c00 */
if(!s->budget--) { s->failed_pc=0x0c093c00u; return 0; }
r[5]=0x00000001u;
goto P_0c093c02;
P_0c093c02: /* original 84d4, guest PC 0x0c093c02 */
if(!s->budget--) { s->failed_pc=0x0c093c02u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+4,1);
goto P_0c093c04;
P_0c093c04: /* original 9218, guest PC 0x0c093c04 */
if(!s->budget--) { s->failed_pc=0x0c093c04u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c093c38u,2);
goto P_0c093c06;
P_0c093c06: /* original 6403, guest PC 0x0c093c06 */
if(!s->budget--) { s->failed_pc=0x0c093c06u; return 0; }
r[4]=r[0];
goto P_0c093c08;
P_0c093c08: /* original 6b4c, guest PC 0x0c093c08 */
if(!s->budget--) { s->failed_pc=0x0c093c08u; return 0; }
r[11]=r[4]&255u;
goto P_0c093c0a;
P_0c093c0a: /* original 63b3, guest PC 0x0c093c0a */
if(!s->budget--) { s->failed_pc=0x0c093c0au; return 0; }
r[3]=r[11];
goto P_0c093c0c;
P_0c093c0c: /* original 4b00, guest PC 0x0c093c0c */
if(!s->budget--) { s->failed_pc=0x0c093c0cu; return 0; }
r[17]=(r[17]&~1u)|((r[11]>>31)!=0);
r[11]<<=1;
goto P_0c093c0e;
P_0c093c0e: /* original 3b3c, guest PC 0x0c093c0e */
if(!s->budget--) { s->failed_pc=0x0c093c0eu; return 0; }
r[11]+=r[3];
goto P_0c093c10;
P_0c093c10: /* original 6c03, guest PC 0x0c093c10 */
if(!s->budget--) { s->failed_pc=0x0c093c10u; return 0; }
r[12]=r[0];
goto P_0c093c12;
P_0c093c12: /* original 4b18, guest PC 0x0c093c12 */
if(!s->budget--) { s->failed_pc=0x0c093c12u; return 0; }
r[11]<<=8;
goto P_0c093c14;
P_0c093c14: /* original 6303, guest PC 0x0c093c14 */
if(!s->budget--) { s->failed_pc=0x0c093c14u; return 0; }
r[3]=r[0];
goto P_0c093c16;
P_0c093c16: /* original 4b08, guest PC 0x0c093c16 */
if(!s->budget--) { s->failed_pc=0x0c093c16u; return 0; }
r[11]<<=2;
goto P_0c093c18;
P_0c093c18: /* original 4b08, guest PC 0x0c093c18 */
if(!s->budget--) { s->failed_pc=0x0c093c18u; return 0; }
r[11]<<=2;
goto P_0c093c1a;
P_0c093c1a: /* original 32ec, guest PC 0x0c093c1a */
if(!s->budget--) { s->failed_pc=0x0c093c1au; return 0; }
r[2]+=r[14];
goto P_0c093c1c;
P_0c093c1c: /* original 6bbf, guest PC 0x0c093c1c */
if(!s->budget--) { s->failed_pc=0x0c093c1cu; return 0; }
r[11]=(uint32_t)(int32_t)(int16_t)r[11];
goto P_0c093c1e;
P_0c093c1e: /* original 4c08, guest PC 0x0c093c1e */
if(!s->budget--) { s->failed_pc=0x0c093c1eu; return 0; }
r[12]<<=2;
goto P_0c093c20;
P_0c093c20: /* original 3b2c, guest PC 0x0c093c20 */
if(!s->budget--) { s->failed_pc=0x0c093c20u; return 0; }
r[11]+=r[2];
goto P_0c093c22;
P_0c093c22: /* original 920a, guest PC 0x0c093c22 */
if(!s->budget--) { s->failed_pc=0x0c093c22u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c093c3au,2);
goto P_0c093c24;
P_0c093c24: /* original 3c3c, guest PC 0x0c093c24 */
if(!s->budget--) { s->failed_pc=0x0c093c24u; return 0; }
r[12]+=r[3];
goto P_0c093c26;
P_0c093c26: /* original 4c08, guest PC 0x0c093c26 */
if(!s->budget--) { s->failed_pc=0x0c093c26u; return 0; }
r[12]<<=2;
goto P_0c093c28;
P_0c093c28: /* original 32ec, guest PC 0x0c093c28 */
if(!s->budget--) { s->failed_pc=0x0c093c28u; return 0; }
r[2]+=r[14];
goto P_0c093c2a;
P_0c093c2a: /* original 6cce, guest PC 0x0c093c2a */
if(!s->budget--) { s->failed_pc=0x0c093c2au; return 0; }
r[12]=(uint32_t)(int32_t)(int8_t)r[12];
goto P_0c093c2c;
P_0c093c2c: /* original 3c2c, guest PC 0x0c093c2c */
if(!s->budget--) { s->failed_pc=0x0c093c2cu; return 0; }
r[12]+=r[2];
goto P_0c093c2e;
P_0c093c2e: /* original a023, guest PC 0x0c093c2e */
if(!s->budget--) { s->failed_pc=0x0c093c2eu; return 0; }
r[0]=0x0000002cu;
goto P_0c093c78;
P_0c093c30: /* original e02c, guest PC 0x0c093c30 */
if(!s->budget--) { s->failed_pc=0x0c093c30u; return 0; }
r[0]=0x0000002cu;
if(!vf3_matrix_family(0x0c093c32u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c093c32u; return 0; } return 1;
P_0c093c4c: /* original 6403, guest PC 0x0c093c4c */
if(!s->budget--) { s->failed_pc=0x0c093c4cu; return 0; }
r[4]=r[0];
goto P_0c093c4e;
P_0c093c4e: /* original 6b4c, guest PC 0x0c093c4e */
if(!s->budget--) { s->failed_pc=0x0c093c4eu; return 0; }
r[11]=r[4]&255u;
goto P_0c093c50;
P_0c093c50: /* original 63b3, guest PC 0x0c093c50 */
if(!s->budget--) { s->failed_pc=0x0c093c50u; return 0; }
r[3]=r[11];
goto P_0c093c52;
P_0c093c52: /* original 4b00, guest PC 0x0c093c52 */
if(!s->budget--) { s->failed_pc=0x0c093c52u; return 0; }
r[17]=(r[17]&~1u)|((r[11]>>31)!=0);
r[11]<<=1;
goto P_0c093c54;
P_0c093c54: /* original 3b3c, guest PC 0x0c093c54 */
if(!s->budget--) { s->failed_pc=0x0c093c54u; return 0; }
r[11]+=r[3];
goto P_0c093c56;
P_0c093c56: /* original 9277, guest PC 0x0c093c56 */
if(!s->budget--) { s->failed_pc=0x0c093c56u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c093d48u,2);
goto P_0c093c58;
P_0c093c58: /* original 4b18, guest PC 0x0c093c58 */
if(!s->budget--) { s->failed_pc=0x0c093c58u; return 0; }
r[11]<<=8;
goto P_0c093c5a;
P_0c093c5a: /* original 6c03, guest PC 0x0c093c5a */
if(!s->budget--) { s->failed_pc=0x0c093c5au; return 0; }
r[12]=r[0];
goto P_0c093c5c;
P_0c093c5c: /* original 4b08, guest PC 0x0c093c5c */
if(!s->budget--) { s->failed_pc=0x0c093c5cu; return 0; }
r[11]<<=2;
goto P_0c093c5e;
P_0c093c5e: /* original 6303, guest PC 0x0c093c5e */
if(!s->budget--) { s->failed_pc=0x0c093c5eu; return 0; }
r[3]=r[0];
goto P_0c093c60;
P_0c093c60: /* original 4b08, guest PC 0x0c093c60 */
if(!s->budget--) { s->failed_pc=0x0c093c60u; return 0; }
r[11]<<=2;
goto P_0c093c62;
P_0c093c62: /* original 32ec, guest PC 0x0c093c62 */
if(!s->budget--) { s->failed_pc=0x0c093c62u; return 0; }
r[2]+=r[14];
goto P_0c093c64;
P_0c093c64: /* original 6bbf, guest PC 0x0c093c64 */
if(!s->budget--) { s->failed_pc=0x0c093c64u; return 0; }
r[11]=(uint32_t)(int32_t)(int16_t)r[11];
goto P_0c093c66;
P_0c093c66: /* original 4c08, guest PC 0x0c093c66 */
if(!s->budget--) { s->failed_pc=0x0c093c66u; return 0; }
r[12]<<=2;
goto P_0c093c68;
P_0c093c68: /* original 3b2c, guest PC 0x0c093c68 */
if(!s->budget--) { s->failed_pc=0x0c093c68u; return 0; }
r[11]+=r[2];
goto P_0c093c6a;
P_0c093c6a: /* original 926e, guest PC 0x0c093c6a */
if(!s->budget--) { s->failed_pc=0x0c093c6au; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c093d4au,2);
goto P_0c093c6c;
P_0c093c6c: /* original 3c3c, guest PC 0x0c093c6c */
if(!s->budget--) { s->failed_pc=0x0c093c6cu; return 0; }
r[12]+=r[3];
goto P_0c093c6e;
P_0c093c6e: /* original 4c08, guest PC 0x0c093c6e */
if(!s->budget--) { s->failed_pc=0x0c093c6eu; return 0; }
r[12]<<=2;
goto P_0c093c70;
P_0c093c70: /* original 32ec, guest PC 0x0c093c70 */
if(!s->budget--) { s->failed_pc=0x0c093c70u; return 0; }
r[2]+=r[14];
goto P_0c093c72;
P_0c093c72: /* original 6cce, guest PC 0x0c093c72 */
if(!s->budget--) { s->failed_pc=0x0c093c72u; return 0; }
r[12]=(uint32_t)(int32_t)(int8_t)r[12];
goto P_0c093c74;
P_0c093c74: /* original e02e, guest PC 0x0c093c74 */
if(!s->budget--) { s->failed_pc=0x0c093c74u; return 0; }
r[0]=0x0000002eu;
goto P_0c093c76;
P_0c093c76: /* original 3c2c, guest PC 0x0c093c76 */
if(!s->budget--) { s->failed_pc=0x0c093c76u; return 0; }
r[12]+=r[2];
goto P_0c093c78;
P_0c093c78: /* original 0e55, guest PC 0x0c093c78 */
if(!s->budget--) { s->failed_pc=0x0c093c78u; return 0; }
write(ram,r[14]+r[0],r[5],2);
goto P_0c093c7a;
P_0c093c7a: /* original e060, guest PC 0x0c093c7a */
if(!s->budget--) { s->failed_pc=0x0c093c7au; return 0; }
r[0]=0x00000060u;
goto P_0c093c7c;
P_0c093c7c: /* original 0adc, guest PC 0x0c093c7c */
if(!s->budget--) { s->failed_pc=0x0c093c7cu; return 0; }
r[10]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+r[0],1);
goto P_0c093c7e;
P_0c093c7e: /* original 65c3, guest PC 0x0c093c7e */
if(!s->budget--) { s->failed_pc=0x0c093c7eu; return 0; }
r[5]=r[12];
goto P_0c093c80;
P_0c093c80: /* original 6aac, guest PC 0x0c093c80 */
if(!s->budget--) { s->failed_pc=0x0c093c80u; return 0; }
r[10]=r[10]&255u;
goto P_0c093c82;
P_0c093c82: /* original 66a3, guest PC 0x0c093c82 */
if(!s->budget--) { s->failed_pc=0x0c093c82u; return 0; }
r[6]=r[10];
goto P_0c093c84;
P_0c093c84: /* original b012, guest PC 0x0c093c84 */
if(!s->budget--) { s->failed_pc=0x0c093c84u; return 0; }
target=code_base|0x0c093cacu; r[16]=code_base|0x0c093c88u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c093c88u) { target=s->pc; goto dispatch; }
goto P_0c093c88;
P_0c093c86: /* original 64e3, guest PC 0x0c093c86 */
if(!s->budget--) { s->failed_pc=0x0c093c86u; return 0; }
r[4]=r[14];
goto P_0c093c88;
P_0c093c88: /* original 66c3, guest PC 0x0c093c88 */
if(!s->budget--) { s->failed_pc=0x0c093c88u; return 0; }
r[6]=r[12];
goto P_0c093c8a;
P_0c093c8a: /* original 65d3, guest PC 0x0c093c8a */
if(!s->budget--) { s->failed_pc=0x0c093c8au; return 0; }
r[5]=r[13];
goto P_0c093c8c;
P_0c093c8c: /* original 2fa6, guest PC 0x0c093c8c */
if(!s->budget--) { s->failed_pc=0x0c093c8cu; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c093c8e;
P_0c093c8e: /* original 67b3, guest PC 0x0c093c8e */
if(!s->budget--) { s->failed_pc=0x0c093c8eu; return 0; }
r[7]=r[11];
goto P_0c093c90;
P_0c093c90: /* original b026, guest PC 0x0c093c90 */
if(!s->budget--) { s->failed_pc=0x0c093c90u; return 0; }
target=code_base|0x0c093ce0u; r[16]=code_base|0x0c093c94u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c093c94u) { target=s->pc; goto dispatch; }
goto P_0c093c94;
P_0c093c92: /* original 64e3, guest PC 0x0c093c92 */
if(!s->budget--) { s->failed_pc=0x0c093c92u; return 0; }
r[4]=r[14];
goto P_0c093c94;
P_0c093c94: /* original 7f04, guest PC 0x0c093c94 */
if(!s->budget--) { s->failed_pc=0x0c093c94u; return 0; }
r[15]+=0x00000004u;
goto P_0c093c96;
P_0c093c96: /* original 9459, guest PC 0x0c093c96 */
if(!s->budget--) { s->failed_pc=0x0c093c96u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c093d4cu,2);
goto P_0c093c98;
P_0c093c98: /* original 4f26, guest PC 0x0c093c98 */
if(!s->budget--) { s->failed_pc=0x0c093c98u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c093c9a;
P_0c093c9a: /* original e300, guest PC 0x0c093c9a */
if(!s->budget--) { s->failed_pc=0x0c093c9au; return 0; }
r[3]=0x00000000u;
goto P_0c093c9c;
P_0c093c9c: /* original 34ec, guest PC 0x0c093c9c */
if(!s->budget--) { s->failed_pc=0x0c093c9cu; return 0; }
r[4]+=r[14];
goto P_0c093c9e;
P_0c093c9e: /* original 2432, guest PC 0x0c093c9e */
if(!s->budget--) { s->failed_pc=0x0c093c9eu; return 0; }
write(ram,r[4],r[3],4);
goto P_0c093ca0;
P_0c093ca0: /* original 6af6, guest PC 0x0c093ca0 */
if(!s->budget--) { s->failed_pc=0x0c093ca0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c093ca2;
P_0c093ca2: /* original 6bf6, guest PC 0x0c093ca2 */
if(!s->budget--) { s->failed_pc=0x0c093ca2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c093ca4;
P_0c093ca4: /* original 6cf6, guest PC 0x0c093ca4 */
if(!s->budget--) { s->failed_pc=0x0c093ca4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c093ca6;
P_0c093ca6: /* original 6df6, guest PC 0x0c093ca6 */
if(!s->budget--) { s->failed_pc=0x0c093ca6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c093ca8;
P_0c093ca8: /* original 000b, guest PC 0x0c093ca8 */
if(!s->budget--) { s->failed_pc=0x0c093ca8u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c093caa: /* original 6ef6, guest PC 0x0c093caa */
if(!s->budget--) { s->failed_pc=0x0c093caau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c093cacu,s,ram);
unsupported: s->failed_pc=target; return 0;
}
