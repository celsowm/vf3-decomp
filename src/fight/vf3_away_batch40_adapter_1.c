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
int vf3_away_batch40_adapter_1(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c06f992u: goto P_0c06f992;
case 0x0c06f994u: goto P_0c06f994;
case 0x0c06f996u: goto P_0c06f996;
case 0x0c06f998u: goto P_0c06f998;
case 0x0c06f99au: goto P_0c06f99a;
case 0x0c06f99cu: goto P_0c06f99c;
case 0x0c06f99eu: goto P_0c06f99e;
case 0x0c06f9a0u: goto P_0c06f9a0;
case 0x0c06f9a2u: goto P_0c06f9a2;
case 0x0c06f9a4u: goto P_0c06f9a4;
case 0x0c06f9a6u: goto P_0c06f9a6;
case 0x0c06f9a8u: goto P_0c06f9a8;
case 0x0c06f9aau: goto P_0c06f9aa;
case 0x0c06f9acu: goto P_0c06f9ac;
case 0x0c06f9aeu: goto P_0c06f9ae;
case 0x0c06f9b0u: goto P_0c06f9b0;
case 0x0c06f9b2u: goto P_0c06f9b2;
case 0x0c06f9b4u: goto P_0c06f9b4;
case 0x0c06f9b6u: goto P_0c06f9b6;
case 0x0c06f9b8u: goto P_0c06f9b8;
case 0x0c06f9bau: goto P_0c06f9ba;
case 0x0c06f9bcu: goto P_0c06f9bc;
case 0x0c06f9beu: goto P_0c06f9be;
case 0x0c06f9c0u: goto P_0c06f9c0;
case 0x0c06f9c2u: goto P_0c06f9c2;
case 0x0c06f9c4u: goto P_0c06f9c4;
case 0x0c06f9c6u: goto P_0c06f9c6;
case 0x0c06f9c8u: goto P_0c06f9c8;
case 0x0c06f9cau: goto P_0c06f9ca;
case 0x0c06f9ccu: goto P_0c06f9cc;
case 0x0c06f9ceu: goto P_0c06f9ce;
case 0x0c06f9d0u: goto P_0c06f9d0;
case 0x0c06f9d2u: goto P_0c06f9d2;
case 0x0c06f9d4u: goto P_0c06f9d4;
case 0x0c06f9d6u: goto P_0c06f9d6;
case 0x0c06f9d8u: goto P_0c06f9d8;
case 0x0c06f9dau: goto P_0c06f9da;
case 0x0c06f9dcu: goto P_0c06f9dc;
case 0x0c06f9deu: goto P_0c06f9de;
case 0x0c06f9e0u: goto P_0c06f9e0;
case 0x0c06f9e2u: goto P_0c06f9e2;
case 0x0c06f9e4u: goto P_0c06f9e4;
case 0x0c06f9e6u: goto P_0c06f9e6;
case 0x0c06f9e8u: goto P_0c06f9e8;
case 0x0c06f9eau: goto P_0c06f9ea;
case 0x0c06f9ecu: goto P_0c06f9ec;
case 0x0c06f9eeu: goto P_0c06f9ee;
case 0x0c06f9f0u: goto P_0c06f9f0;
case 0x0c06f9f2u: goto P_0c06f9f2;
case 0x0c06f9f4u: goto P_0c06f9f4;
case 0x0c06f9f6u: goto P_0c06f9f6;
case 0x0c06f9f8u: goto P_0c06f9f8;
case 0x0c06f9fau: goto P_0c06f9fa;
case 0x0c06f9fcu: goto P_0c06f9fc;
case 0x0c06f9feu: goto P_0c06f9fe;
case 0x0c06fa00u: goto P_0c06fa00;
case 0x0c06fa40u: goto P_0c06fa40;
case 0x0c06fa42u: goto P_0c06fa42;
case 0x0c06fa44u: goto P_0c06fa44;
case 0x0c06fa46u: goto P_0c06fa46;
case 0x0c06fa48u: goto P_0c06fa48;
case 0x0c06fa4au: goto P_0c06fa4a;
case 0x0c06fa4cu: goto P_0c06fa4c;
case 0x0c06fa4eu: goto P_0c06fa4e;
case 0x0c06fa50u: goto P_0c06fa50;
case 0x0c06fa52u: goto P_0c06fa52;
case 0x0c06fa54u: goto P_0c06fa54;
case 0x0c06fa56u: goto P_0c06fa56;
case 0x0c06fa58u: goto P_0c06fa58;
case 0x0c06fa5au: goto P_0c06fa5a;
case 0x0c06fa5cu: goto P_0c06fa5c;
case 0x0c06fa5eu: goto P_0c06fa5e;
case 0x0c06fa60u: goto P_0c06fa60;
case 0x0c06fa62u: goto P_0c06fa62;
case 0x0c06fa64u: goto P_0c06fa64;
case 0x0c06fa66u: goto P_0c06fa66;
case 0x0c06fa68u: goto P_0c06fa68;
case 0x0c06fa6au: goto P_0c06fa6a;
case 0x0c06fa6cu: goto P_0c06fa6c;
case 0x0c06fa6eu: goto P_0c06fa6e;
case 0x0c06fa70u: goto P_0c06fa70;
case 0x0c06fa72u: goto P_0c06fa72;
case 0x0c06fa74u: goto P_0c06fa74;
case 0x0c06fa76u: goto P_0c06fa76;
case 0x0c06fa78u: goto P_0c06fa78;
case 0x0c06fa7au: goto P_0c06fa7a;
case 0x0c06fa7cu: goto P_0c06fa7c;
case 0x0c06fa7eu: goto P_0c06fa7e;
case 0x0c06fa80u: goto P_0c06fa80;
case 0x0c06fa82u: goto P_0c06fa82;
case 0x0c06fa84u: goto P_0c06fa84;
case 0x0c06fa86u: goto P_0c06fa86;
case 0x0c06fa88u: goto P_0c06fa88;
case 0x0c06fa94u: goto P_0c06fa94;
case 0x0c06fa96u: goto P_0c06fa96;
case 0x0c06fa98u: goto P_0c06fa98;
case 0x0c06fa9au: goto P_0c06fa9a;
case 0x0c06fa9cu: goto P_0c06fa9c;
case 0x0c06fa9eu: goto P_0c06fa9e;
case 0x0c06faa0u: goto P_0c06faa0;
case 0x0c06faa2u: goto P_0c06faa2;
case 0x0c06faa4u: goto P_0c06faa4;
case 0x0c06faa6u: goto P_0c06faa6;
case 0x0c06faa8u: goto P_0c06faa8;
case 0x0c06faaau: goto P_0c06faaa;
case 0x0c06faacu: goto P_0c06faac;
case 0x0c06faaeu: goto P_0c06faae;
case 0x0c06fab0u: goto P_0c06fab0;
case 0x0c06fab2u: goto P_0c06fab2;
case 0x0c06fab6u: goto P_0c06fab6;
case 0x0c06fab8u: goto P_0c06fab8;
case 0x0c06fabau: goto P_0c06faba;
case 0x0c06fabcu: goto P_0c06fabc;
case 0x0c06fabeu: goto P_0c06fabe;
case 0x0c06fac0u: goto P_0c06fac0;
case 0x0c06fac2u: goto P_0c06fac2;
case 0x0c06fac4u: goto P_0c06fac4;
case 0x0c06fac6u: goto P_0c06fac6;
case 0x0c06fac8u: goto P_0c06fac8;
case 0x0c06facau: goto P_0c06faca;
case 0x0c06faccu: goto P_0c06facc;
case 0x0c06faceu: goto P_0c06face;
case 0x0c06fad0u: goto P_0c06fad0;
case 0x0c06fad2u: goto P_0c06fad2;
case 0x0c06fad4u: goto P_0c06fad4;
case 0x0c06fad6u: goto P_0c06fad6;
case 0x0c06fad8u: goto P_0c06fad8;
case 0x0c06fadau: goto P_0c06fada;
case 0x0c06fadcu: goto P_0c06fadc;
case 0x0c06fadeu: goto P_0c06fade;
case 0x0c06fae0u: goto P_0c06fae0;
case 0x0c06fae2u: goto P_0c06fae2;
case 0x0c06fae4u: goto P_0c06fae4;
case 0x0c06fae6u: goto P_0c06fae6;
case 0x0c06fae8u: goto P_0c06fae8;
case 0x0c06faeau: goto P_0c06faea;
case 0x0c06faecu: goto P_0c06faec;
case 0x0c06faeeu: goto P_0c06faee;
case 0x0c06faf0u: goto P_0c06faf0;
case 0x0c06faf2u: goto P_0c06faf2;
case 0x0c06faf4u: goto P_0c06faf4;
case 0x0c06faf6u: goto P_0c06faf6;
case 0x0c06faf8u: goto P_0c06faf8;
case 0x0c06fafau: goto P_0c06fafa;
case 0x0c06fafcu: goto P_0c06fafc;
case 0x0c06fafeu: goto P_0c06fafe;
case 0x0c06fb00u: goto P_0c06fb00;
case 0x0c06fb02u: goto P_0c06fb02;
case 0x0c06fb04u: goto P_0c06fb04;
case 0x0c06fb06u: goto P_0c06fb06;
case 0x0c06fb08u: goto P_0c06fb08;
case 0x0c06fb0au: goto P_0c06fb0a;
case 0x0c06fb0cu: goto P_0c06fb0c;
case 0x0c06fb0eu: goto P_0c06fb0e;
case 0x0c06fb10u: goto P_0c06fb10;
case 0x0c06fb12u: goto P_0c06fb12;
case 0x0c06fb14u: goto P_0c06fb14;
case 0x0c06fb16u: goto P_0c06fb16;
case 0x0c06fb18u: goto P_0c06fb18;
case 0x0c06fb1au: goto P_0c06fb1a;
case 0x0c06fb1cu: goto P_0c06fb1c;
case 0x0c06fb1eu: goto P_0c06fb1e;
case 0x0c06fb20u: goto P_0c06fb20;
case 0x0c06fb22u: goto P_0c06fb22;
case 0x0c06fb24u: goto P_0c06fb24;
case 0x0c06fb26u: goto P_0c06fb26;
case 0x0c06fb28u: goto P_0c06fb28;
case 0x0c06fb2au: goto P_0c06fb2a;
case 0x0c06fb2cu: goto P_0c06fb2c;
case 0x0c06fb2eu: goto P_0c06fb2e;
case 0x0c06fb30u: goto P_0c06fb30;
case 0x0c06fb32u: goto P_0c06fb32;
case 0x0c06fb34u: goto P_0c06fb34;
case 0x0c06fb36u: goto P_0c06fb36;
case 0x0c06fb38u: goto P_0c06fb38;
case 0x0c06fb3au: goto P_0c06fb3a;
case 0x0c06fb3cu: goto P_0c06fb3c;
case 0x0c06fb3eu: goto P_0c06fb3e;
case 0x0c06fb40u: goto P_0c06fb40;
case 0x0c06fb42u: goto P_0c06fb42;
case 0x0c06fb44u: goto P_0c06fb44;
case 0x0c06fb46u: goto P_0c06fb46;
case 0x0c06fb48u: goto P_0c06fb48;
case 0x0c06fb4au: goto P_0c06fb4a;
case 0x0c06fb4cu: goto P_0c06fb4c;
case 0x0c06fb4eu: goto P_0c06fb4e;
case 0x0c06fb50u: goto P_0c06fb50;
case 0x0c06fb52u: goto P_0c06fb52;
case 0x0c06fb54u: goto P_0c06fb54;
case 0x0c06fb56u: goto P_0c06fb56;
case 0x0c06fb58u: goto P_0c06fb58;
case 0x0c06fb5au: goto P_0c06fb5a;
case 0x0c06fb5cu: goto P_0c06fb5c;
case 0x0c06fb5eu: goto P_0c06fb5e;
case 0x0c06fb60u: goto P_0c06fb60;
case 0x0c06fb62u: goto P_0c06fb62;
case 0x0c06fb90u: goto P_0c06fb90;
case 0x0c06fb92u: goto P_0c06fb92;
case 0x0c06fb94u: goto P_0c06fb94;
case 0x0c06fb96u: goto P_0c06fb96;
case 0x0c06fb98u: goto P_0c06fb98;
case 0x0c06fb9au: goto P_0c06fb9a;
case 0x0c06fb9cu: goto P_0c06fb9c;
case 0x0c06fb9eu: goto P_0c06fb9e;
case 0x0c06fba0u: goto P_0c06fba0;
case 0x0c06fba2u: goto P_0c06fba2;
case 0x0c06fba4u: goto P_0c06fba4;
case 0x0c06fba6u: goto P_0c06fba6;
case 0x0c06fba8u: goto P_0c06fba8;
case 0x0c06fbaau: goto P_0c06fbaa;
case 0x0c06fbacu: goto P_0c06fbac;
case 0x0c06fbaeu: goto P_0c06fbae;
case 0x0c06fbb0u: goto P_0c06fbb0;
case 0x0c06fbb2u: goto P_0c06fbb2;
case 0x0c06fbb4u: goto P_0c06fbb4;
case 0x0c06fbb6u: goto P_0c06fbb6;
case 0x0c06fbb8u: goto P_0c06fbb8;
case 0x0c06fbbau: goto P_0c06fbba;
case 0x0c06ffdeu: goto P_0c06ffde;
case 0x0c06ffe0u: goto P_0c06ffe0;
case 0x0c06ffe2u: goto P_0c06ffe2;
case 0x0c06ffe4u: goto P_0c06ffe4;
case 0x0c06ffe6u: goto P_0c06ffe6;
case 0x0c06ffe8u: goto P_0c06ffe8;
case 0x0c06ffeau: goto P_0c06ffea;
case 0x0c06ffecu: goto P_0c06ffec;
case 0x0c06ffeeu: goto P_0c06ffee;
case 0x0c06fff0u: goto P_0c06fff0;
case 0x0c06fff2u: goto P_0c06fff2;
case 0x0c06fff4u: goto P_0c06fff4;
case 0x0c06fff6u: goto P_0c06fff6;
case 0x0c06fff8u: goto P_0c06fff8;
case 0x0c06fffau: goto P_0c06fffa;
case 0x0c06fffcu: goto P_0c06fffc;
case 0x0c06fffeu: goto P_0c06fffe;
case 0x0c070000u: goto P_0c070000;
case 0x0c070002u: goto P_0c070002;
case 0x0c070004u: goto P_0c070004;
case 0x0c070006u: goto P_0c070006;
default: return vf3_matrix_family(target,s,ram);
}
P_0c06f992: /* original 2fe6, guest PC 0x0c06f992 */
if(!s->budget--) { s->failed_pc=0x0c06f992u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06f994;
P_0c06f994: /* original 2fd6, guest PC 0x0c06f994 */
if(!s->budget--) { s->failed_pc=0x0c06f994u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06f996;
P_0c06f996: /* original 6d53, guest PC 0x0c06f996 */
if(!s->budget--) { s->failed_pc=0x0c06f996u; return 0; }
r[13]=r[5];
goto P_0c06f998;
P_0c06f998: /* original 2fc6, guest PC 0x0c06f998 */
if(!s->budget--) { s->failed_pc=0x0c06f998u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06f99a;
P_0c06f99a: /* original 2fb6, guest PC 0x0c06f99a */
if(!s->budget--) { s->failed_pc=0x0c06f99au; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06f99c;
P_0c06f99c: /* original 2fa6, guest PC 0x0c06f99c */
if(!s->budget--) { s->failed_pc=0x0c06f99cu; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06f99e;
P_0c06f99e: /* original 6a43, guest PC 0x0c06f99e */
if(!s->budget--) { s->failed_pc=0x0c06f99eu; return 0; }
r[10]=r[4];
goto P_0c06f9a0;
P_0c06f9a0: /* original 2f96, guest PC 0x0c06f9a0 */
if(!s->budget--) { s->failed_pc=0x0c06f9a0u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06f9a2;
P_0c06f9a2: /* original 2f86, guest PC 0x0c06f9a2 */
if(!s->budget--) { s->failed_pc=0x0c06f9a2u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06f9a4;
P_0c06f9a4: /* original fffb, guest PC 0x0c06f9a4 */
if(!s->budget--) { s->failed_pc=0x0c06f9a4u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c06f9a6;
P_0c06f9a6: /* original ffeb, guest PC 0x0c06f9a6 */
if(!s->budget--) { s->failed_pc=0x0c06f9a6u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,14,r[15]);
goto P_0c06f9a8;
P_0c06f9a8: /* original ffdb, guest PC 0x0c06f9a8 */
if(!s->budget--) { s->failed_pc=0x0c06f9a8u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,13,r[15]);
goto P_0c06f9aa;
P_0c06f9aa: /* original ffcb, guest PC 0x0c06f9aa */
if(!s->budget--) { s->failed_pc=0x0c06f9aau; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,12,r[15]);
goto P_0c06f9ac;
P_0c06f9ac: /* original 4f22, guest PC 0x0c06f9ac */
if(!s->budget--) { s->failed_pc=0x0c06f9acu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c06f9ae;
P_0c06f9ae: /* original 9028, guest PC 0x0c06f9ae */
if(!s->budget--) { s->failed_pc=0x0c06f9aeu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06fa02u,2);
goto P_0c06f9b0;
P_0c06f9b0: /* original d31c, guest PC 0x0c06f9b0 */
if(!s->budget--) { s->failed_pc=0x0c06f9b0u; return 0; }
r[3]=read(ram,0x0c06fa24u,4);
goto P_0c06f9b2;
P_0c06f9b2: /* original 4f12, guest PC 0x0c06f9b2 */
if(!s->budget--) { s->failed_pc=0x0c06f9b2u; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c06f9b4;
P_0c06f9b4: /* original 3f0c, guest PC 0x0c06f9b4 */
if(!s->budget--) { s->failed_pc=0x0c06f9b4u; return 0; }
r[15]+=r[0];
goto P_0c06f9b6;
P_0c06f9b6: /* original 1f33, guest PC 0x0c06f9b6 */
if(!s->budget--) { s->failed_pc=0x0c06f9b6u; return 0; }
write(ram,r[15]+12,r[3],4);
goto P_0c06f9b8;
P_0c06f9b8: /* original 61f3, guest PC 0x0c06f9b8 */
if(!s->budget--) { s->failed_pc=0x0c06f9b8u; return 0; }
r[1]=r[15];
goto P_0c06f9ba;
P_0c06f9ba: /* original d21b, guest PC 0x0c06f9ba */
if(!s->budget--) { s->failed_pc=0x0c06f9bau; return 0; }
r[2]=read(ram,0x0c06fa28u,4);
goto P_0c06f9bc;
P_0c06f9bc: /* original 7110, guest PC 0x0c06f9bc */
if(!s->budget--) { s->failed_pc=0x0c06f9bcu; return 0; }
r[1]+=0x00000010u;
goto P_0c06f9be;
P_0c06f9be: /* original d31b, guest PC 0x0c06f9be */
if(!s->budget--) { s->failed_pc=0x0c06f9beu; return 0; }
r[3]=read(ram,0x0c06fa2cu,4);
goto P_0c06f9c0;
P_0c06f9c0: /* original 430b, guest PC 0x0c06f9c0 */
if(!s->budget--) { s->failed_pc=0x0c06f9c0u; return 0; }
target=r[3];
r[16]=code_base|0x0c06f9c4u;
r[0]=0x0000000cu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06f9c4u) { target=s->pc; goto dispatch; }
goto P_0c06f9c4;
P_0c06f9c2: /* original e00c, guest PC 0x0c06f9c2 */
if(!s->budget--) { s->failed_pc=0x0c06f9c2u; return 0; }
r[0]=0x0000000cu;
goto P_0c06f9c4;
P_0c06f9c4: /* original d11a, guest PC 0x0c06f9c4 */
if(!s->budget--) { s->failed_pc=0x0c06f9c4u; return 0; }
r[1]=read(ram,0x0c06fa30u,4);
goto P_0c06f9c6;
P_0c06f9c6: /* original 410b, guest PC 0x0c06f9c6 */
if(!s->budget--) { s->failed_pc=0x0c06f9c6u; return 0; }
target=r[1];
r[16]=code_base|0x0c06f9cau;
r[4]=0x00000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06f9cau) { target=s->pc; goto dispatch; }
goto P_0c06f9ca;
P_0c06f9c8: /* original e400, guest PC 0x0c06f9c8 */
if(!s->budget--) { s->failed_pc=0x0c06f9c8u; return 0; }
r[4]=0x00000000u;
goto P_0c06f9ca;
P_0c06f9ca: /* original d31a, guest PC 0x0c06f9ca */
if(!s->budget--) { s->failed_pc=0x0c06f9cau; return 0; }
r[3]=read(ram,0x0c06fa34u,4);
goto P_0c06f9cc;
P_0c06f9cc: /* original 430b, guest PC 0x0c06f9cc */
if(!s->budget--) { s->failed_pc=0x0c06f9ccu; return 0; }
target=r[3];
r[16]=code_base|0x0c06f9d0u;
r[4]=read(ram,r[13]+12,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06f9d0u) { target=s->pc; goto dispatch; }
goto P_0c06f9d0;
P_0c06f9ce: /* original 54d3, guest PC 0x0c06f9ce */
if(!s->budget--) { s->failed_pc=0x0c06f9ceu; return 0; }
r[4]=read(ram,r[13]+12,4);
goto P_0c06f9d0;
P_0c06f9d0: /* original d219, guest PC 0x0c06f9d0 */
if(!s->budget--) { s->failed_pc=0x0c06f9d0u; return 0; }
r[2]=read(ram,0x0c06fa38u,4);
goto P_0c06f9d2;
P_0c06f9d2: /* original 420b, guest PC 0x0c06f9d2 */
if(!s->budget--) { s->failed_pc=0x0c06f9d2u; return 0; }
target=r[2];
r[16]=code_base|0x0c06f9d6u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06f9d6u) { target=s->pc; goto dispatch; }
goto P_0c06f9d6;
P_0c06f9d4: /* original 0009, guest PC 0x0c06f9d4 */
if(!s->budget--) { s->failed_pc=0x0c06f9d4u; return 0; }
goto P_0c06f9d6;
P_0c06f9d6: /* original d316, guest PC 0x0c06f9d6 */
if(!s->budget--) { s->failed_pc=0x0c06f9d6u; return 0; }
r[3]=read(ram,0x0c06fa30u,4);
goto P_0c06f9d8;
P_0c06f9d8: /* original 430b, guest PC 0x0c06f9d8 */
if(!s->budget--) { s->failed_pc=0x0c06f9d8u; return 0; }
target=r[3];
r[16]=code_base|0x0c06f9dcu;
r[4]=0x00000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06f9dcu) { target=s->pc; goto dispatch; }
goto P_0c06f9dc;
P_0c06f9da: /* original e400, guest PC 0x0c06f9da */
if(!s->budget--) { s->failed_pc=0x0c06f9dau; return 0; }
r[4]=0x00000000u;
goto P_0c06f9dc;
P_0c06f9dc: /* original d317, guest PC 0x0c06f9dc */
if(!s->budget--) { s->failed_pc=0x0c06f9dcu; return 0; }
r[3]=read(ram,0x0c06fa3cu,4);
goto P_0c06f9de;
P_0c06f9de: /* original e06c, guest PC 0x0c06f9de */
if(!s->budget--) { s->failed_pc=0x0c06f9deu; return 0; }
r[0]=0x0000006cu;
goto P_0c06f9e0;
P_0c06f9e0: /* original 430b, guest PC 0x0c06f9e0 */
if(!s->budget--) { s->failed_pc=0x0c06f9e0u; return 0; }
target=r[3];
r[16]=code_base|0x0c06f9e4u;
r[4]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06f9e4u) { target=s->pc; goto dispatch; }
goto P_0c06f9e4;
P_0c06f9e2: /* original 04de, guest PC 0x0c06f9e2 */
if(!s->budget--) { s->failed_pc=0x0c06f9e2u; return 0; }
r[4]=read(ram,r[13]+r[0],4);
goto P_0c06f9e4;
P_0c06f9e4: /* original 900e, guest PC 0x0c06f9e4 */
if(!s->budget--) { s->failed_pc=0x0c06f9e4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06fa04u,2);
goto P_0c06f9e6;
P_0c06f9e6: /* original 64f3, guest PC 0x0c06f9e6 */
if(!s->budget--) { s->failed_pc=0x0c06f9e6u; return 0; }
r[4]=r[15];
goto P_0c06f9e8;
P_0c06f9e8: /* original 741c, guest PC 0x0c06f9e8 */
if(!s->budget--) { s->failed_pc=0x0c06f9e8u; return 0; }
r[4]+=0x0000001cu;
goto P_0c06f9ea;
P_0c06f9ea: /* original f3d6, guest PC 0x0c06f9ea */
if(!s->budget--) { s->failed_pc=0x0c06f9eau; return 0; }
vf3_matrix_load(s,ram,3,r[13]+r[0]);
goto P_0c06f9ec;
P_0c06f9ec: /* original e01c, guest PC 0x0c06f9ec */
if(!s->budget--) { s->failed_pc=0x0c06f9ecu; return 0; }
r[0]=0x0000001cu;
goto P_0c06f9ee;
P_0c06f9ee: /* original ff37, guest PC 0x0c06f9ee */
if(!s->budget--) { s->failed_pc=0x0c06f9eeu; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c06f9f0;
P_0c06f9f0: /* original e020, guest PC 0x0c06f9f0 */
if(!s->budget--) { s->failed_pc=0x0c06f9f0u; return 0; }
r[0]=0x00000020u;
goto P_0c06f9f2;
P_0c06f9f2: /* original ff8d, guest PC 0x0c06f9f2 */
if(!s->budget--) { s->failed_pc=0x0c06f9f2u; return 0; }
fr[15]=0;
goto P_0c06f9f4;
P_0c06f9f4: /* original fff7, guest PC 0x0c06f9f4 */
if(!s->budget--) { s->failed_pc=0x0c06f9f4u; return 0; }
vf3_matrix_store(s,ram,15,r[15]+r[0]);
goto P_0c06f9f6;
P_0c06f9f6: /* original e024, guest PC 0x0c06f9f6 */
if(!s->budget--) { s->failed_pc=0x0c06f9f6u; return 0; }
r[0]=0x00000024u;
goto P_0c06f9f8;
P_0c06f9f8: /* original fff7, guest PC 0x0c06f9f8 */
if(!s->budget--) { s->failed_pc=0x0c06f9f8u; return 0; }
vf3_matrix_store(s,ram,15,r[15]+r[0]);
goto P_0c06f9fa;
P_0c06f9fa: /* original 9504, guest PC 0x0c06f9fa */
if(!s->budget--) { s->failed_pc=0x0c06f9fau; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06fa06u,2);
goto P_0c06f9fc;
P_0c06f9fc: /* original 35dc, guest PC 0x0c06f9fc */
if(!s->budget--) { s->failed_pc=0x0c06f9fcu; return 0; }
r[5]+=r[13];
goto P_0c06f9fe;
P_0c06f9fe: /* original a01f, guest PC 0x0c06f9fe */
if(!s->budget--) { s->failed_pc=0x0c06f9feu; return 0; }
goto P_0c06fa40;
P_0c06fa00: /* original 0009, guest PC 0x0c06fa00 */
if(!s->budget--) { s->failed_pc=0x0c06fa00u; return 0; }
if(!vf3_matrix_family(0x0c06fa02u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c06fa02u; return 0; } return 1;
P_0c06fa40: /* original f449, guest PC 0x0c06fa40 */
if(!s->budget--) { s->failed_pc=0x0c06fa40u; return 0; }
vf3_matrix_load(s,ram,4,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c06fa42;
P_0c06fa42: /* original f549, guest PC 0x0c06fa42 */
if(!s->budget--) { s->failed_pc=0x0c06fa42u; return 0; }
vf3_matrix_load(s,ram,5,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c06fa44;
P_0c06fa44: /* original f648, guest PC 0x0c06fa44 */
if(!s->budget--) { s->failed_pc=0x0c06fa44u; return 0; }
vf3_matrix_load(s,ram,6,r[4]);
goto P_0c06fa46;
P_0c06fa46: /* original f79d, guest PC 0x0c06fa46 */
if(!s->budget--) { s->failed_pc=0x0c06fa46u; return 0; }
fr[7]=0x3f800000u;
goto P_0c06fa48;
P_0c06fa48: /* original f5fd, guest PC 0x0c06fa48 */
if(!s->budget--) { s->failed_pc=0x0c06fa48u; return 0; }
if(!vf3_fpu_ftrv(xf,fr+4,r[18],fr+4)) goto unsupported;
goto P_0c06fa4a;
P_0c06fa4a: /* original 750c, guest PC 0x0c06fa4a */
if(!s->budget--) { s->failed_pc=0x0c06fa4au; return 0; }
r[5]+=0x0000000cu;
goto P_0c06fa4c;
P_0c06fa4c: /* original f56b, guest PC 0x0c06fa4c */
if(!s->budget--) { s->failed_pc=0x0c06fa4cu; return 0; }
r[5]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,6,r[5]);
goto P_0c06fa4e;
P_0c06fa4e: /* original f55b, guest PC 0x0c06fa4e */
if(!s->budget--) { s->failed_pc=0x0c06fa4eu; return 0; }
r[5]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,5,r[5]);
goto P_0c06fa50;
P_0c06fa50: /* original f54b, guest PC 0x0c06fa50 */
if(!s->budget--) { s->failed_pc=0x0c06fa50u; return 0; }
r[5]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,4,r[5]);
goto P_0c06fa52;
P_0c06fa52: /* original 0009, guest PC 0x0c06fa52 */
if(!s->budget--) { s->failed_pc=0x0c06fa52u; return 0; }
goto P_0c06fa54;
P_0c06fa54: /* original 64f3, guest PC 0x0c06fa54 */
if(!s->budget--) { s->failed_pc=0x0c06fa54u; return 0; }
r[4]=r[15];
goto P_0c06fa56;
P_0c06fa56: /* original 65d3, guest PC 0x0c06fa56 */
if(!s->budget--) { s->failed_pc=0x0c06fa56u; return 0; }
r[5]=r[13];
goto P_0c06fa58;
P_0c06fa58: /* original 7410, guest PC 0x0c06fa58 */
if(!s->budget--) { s->failed_pc=0x0c06fa58u; return 0; }
r[4]+=0x00000010u;
goto P_0c06fa5a;
P_0c06fa5a: /* original 7574, guest PC 0x0c06fa5a */
if(!s->budget--) { s->failed_pc=0x0c06fa5au; return 0; }
r[5]+=0x00000074u;
goto P_0c06fa5c;
P_0c06fa5c: /* original f449, guest PC 0x0c06fa5c */
if(!s->budget--) { s->failed_pc=0x0c06fa5cu; return 0; }
vf3_matrix_load(s,ram,4,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c06fa5e;
P_0c06fa5e: /* original f549, guest PC 0x0c06fa5e */
if(!s->budget--) { s->failed_pc=0x0c06fa5eu; return 0; }
vf3_matrix_load(s,ram,5,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c06fa60;
P_0c06fa60: /* original f649, guest PC 0x0c06fa60 */
if(!s->budget--) { s->failed_pc=0x0c06fa60u; return 0; }
vf3_matrix_load(s,ram,6,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c06fa62;
P_0c06fa62: /* original f78d, guest PC 0x0c06fa62 */
if(!s->budget--) { s->failed_pc=0x0c06fa62u; return 0; }
fr[7]=0;
goto P_0c06fa64;
P_0c06fa64: /* original f5fd, guest PC 0x0c06fa64 */
if(!s->budget--) { s->failed_pc=0x0c06fa64u; return 0; }
if(!vf3_fpu_ftrv(xf,fr+4,r[18],fr+4)) goto unsupported;
goto P_0c06fa66;
P_0c06fa66: /* original 750c, guest PC 0x0c06fa66 */
if(!s->budget--) { s->failed_pc=0x0c06fa66u; return 0; }
r[5]+=0x0000000cu;
goto P_0c06fa68;
P_0c06fa68: /* original f56b, guest PC 0x0c06fa68 */
if(!s->budget--) { s->failed_pc=0x0c06fa68u; return 0; }
r[5]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,6,r[5]);
goto P_0c06fa6a;
P_0c06fa6a: /* original f55b, guest PC 0x0c06fa6a */
if(!s->budget--) { s->failed_pc=0x0c06fa6au; return 0; }
r[5]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,5,r[5]);
goto P_0c06fa6c;
P_0c06fa6c: /* original f54b, guest PC 0x0c06fa6c */
if(!s->budget--) { s->failed_pc=0x0c06fa6cu; return 0; }
r[5]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,4,r[5]);
goto P_0c06fa6e;
P_0c06fa6e: /* original 0009, guest PC 0x0c06fa6e */
if(!s->budget--) { s->failed_pc=0x0c06fa6eu; return 0; }
goto P_0c06fa70;
P_0c06fa70: /* original d806, guest PC 0x0c06fa70 */
if(!s->budget--) { s->failed_pc=0x0c06fa70u; return 0; }
r[8]=read(ram,0x0c06fa8cu,4);
goto P_0c06fa72;
P_0c06fa72: /* original 480b, guest PC 0x0c06fa72 */
if(!s->budget--) { s->failed_pc=0x0c06fa72u; return 0; }
target=r[8];
r[16]=code_base|0x0c06fa76u;
r[4]=0x00000001u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06fa76u) { target=s->pc; goto dispatch; }
goto P_0c06fa76;
P_0c06fa74: /* original e401, guest PC 0x0c06fa74 */
if(!s->budget--) { s->failed_pc=0x0c06fa74u; return 0; }
r[4]=0x00000001u;
goto P_0c06fa76;
P_0c06fa76: /* original d306, guest PC 0x0c06fa76 */
if(!s->budget--) { s->failed_pc=0x0c06fa76u; return 0; }
r[3]=read(ram,0x0c06fa90u,4);
goto P_0c06fa78;
P_0c06fa78: /* original e070, guest PC 0x0c06fa78 */
if(!s->budget--) { s->failed_pc=0x0c06fa78u; return 0; }
r[0]=0x00000070u;
goto P_0c06fa7a;
P_0c06fa7a: /* original 430b, guest PC 0x0c06fa7a */
if(!s->budget--) { s->failed_pc=0x0c06fa7au; return 0; }
target=r[3];
r[16]=code_base|0x0c06fa7eu;
r[4]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06fa7eu) { target=s->pc; goto dispatch; }
goto P_0c06fa7e;
P_0c06fa7c: /* original 04de, guest PC 0x0c06fa7c */
if(!s->budget--) { s->failed_pc=0x0c06fa7cu; return 0; }
r[4]=read(ram,r[13]+r[0],4);
goto P_0c06fa7e;
P_0c06fa7e: /* original 9504, guest PC 0x0c06fa7e */
if(!s->budget--) { s->failed_pc=0x0c06fa7eu; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06fa8au,2);
goto P_0c06fa80;
P_0c06fa80: /* original 64f3, guest PC 0x0c06fa80 */
if(!s->budget--) { s->failed_pc=0x0c06fa80u; return 0; }
r[4]=r[15];
goto P_0c06fa82;
P_0c06fa82: /* original 741c, guest PC 0x0c06fa82 */
if(!s->budget--) { s->failed_pc=0x0c06fa82u; return 0; }
r[4]+=0x0000001cu;
goto P_0c06fa84;
P_0c06fa84: /* original 35dc, guest PC 0x0c06fa84 */
if(!s->budget--) { s->failed_pc=0x0c06fa84u; return 0; }
r[5]+=r[13];
goto P_0c06fa86;
P_0c06fa86: /* original a005, guest PC 0x0c06fa86 */
if(!s->budget--) { s->failed_pc=0x0c06fa86u; return 0; }
goto P_0c06fa94;
P_0c06fa88: /* original 0009, guest PC 0x0c06fa88 */
if(!s->budget--) { s->failed_pc=0x0c06fa88u; return 0; }
if(!vf3_matrix_family(0x0c06fa8au,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c06fa8au; return 0; } return 1;
P_0c06fa94: /* original f449, guest PC 0x0c06fa94 */
if(!s->budget--) { s->failed_pc=0x0c06fa94u; return 0; }
vf3_matrix_load(s,ram,4,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c06fa96;
P_0c06fa96: /* original f549, guest PC 0x0c06fa96 */
if(!s->budget--) { s->failed_pc=0x0c06fa96u; return 0; }
vf3_matrix_load(s,ram,5,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c06fa98;
P_0c06fa98: /* original f648, guest PC 0x0c06fa98 */
if(!s->budget--) { s->failed_pc=0x0c06fa98u; return 0; }
vf3_matrix_load(s,ram,6,r[4]);
goto P_0c06fa9a;
P_0c06fa9a: /* original f79d, guest PC 0x0c06fa9a */
if(!s->budget--) { s->failed_pc=0x0c06fa9au; return 0; }
fr[7]=0x3f800000u;
goto P_0c06fa9c;
P_0c06fa9c: /* original f5fd, guest PC 0x0c06fa9c */
if(!s->budget--) { s->failed_pc=0x0c06fa9cu; return 0; }
if(!vf3_fpu_ftrv(xf,fr+4,r[18],fr+4)) goto unsupported;
goto P_0c06fa9e;
P_0c06fa9e: /* original 750c, guest PC 0x0c06fa9e */
if(!s->budget--) { s->failed_pc=0x0c06fa9eu; return 0; }
r[5]+=0x0000000cu;
goto P_0c06faa0;
P_0c06faa0: /* original f56b, guest PC 0x0c06faa0 */
if(!s->budget--) { s->failed_pc=0x0c06faa0u; return 0; }
r[5]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,6,r[5]);
goto P_0c06faa2;
P_0c06faa2: /* original f55b, guest PC 0x0c06faa2 */
if(!s->budget--) { s->failed_pc=0x0c06faa2u; return 0; }
r[5]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,5,r[5]);
goto P_0c06faa4;
P_0c06faa4: /* original f54b, guest PC 0x0c06faa4 */
if(!s->budget--) { s->failed_pc=0x0c06faa4u; return 0; }
r[5]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,4,r[5]);
goto P_0c06faa6;
P_0c06faa6: /* original 0009, guest PC 0x0c06faa6 */
if(!s->budget--) { s->failed_pc=0x0c06faa6u; return 0; }
goto P_0c06faa8;
P_0c06faa8: /* original 9504, guest PC 0x0c06faa8 */
if(!s->budget--) { s->failed_pc=0x0c06faa8u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06fab4u,2);
goto P_0c06faaa;
P_0c06faaa: /* original 64f3, guest PC 0x0c06faaa */
if(!s->budget--) { s->failed_pc=0x0c06faaau; return 0; }
r[4]=r[15];
goto P_0c06faac;
P_0c06faac: /* original 7410, guest PC 0x0c06faac */
if(!s->budget--) { s->failed_pc=0x0c06faacu; return 0; }
r[4]+=0x00000010u;
goto P_0c06faae;
P_0c06faae: /* original 35dc, guest PC 0x0c06faae */
if(!s->budget--) { s->failed_pc=0x0c06faaeu; return 0; }
r[5]+=r[13];
goto P_0c06fab0;
P_0c06fab0: /* original a001, guest PC 0x0c06fab0 */
if(!s->budget--) { s->failed_pc=0x0c06fab0u; return 0; }
goto P_0c06fab6;
P_0c06fab2: /* original 0009, guest PC 0x0c06fab2 */
if(!s->budget--) { s->failed_pc=0x0c06fab2u; return 0; }
if(!vf3_matrix_family(0x0c06fab4u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c06fab4u; return 0; } return 1;
P_0c06fab6: /* original f449, guest PC 0x0c06fab6 */
if(!s->budget--) { s->failed_pc=0x0c06fab6u; return 0; }
vf3_matrix_load(s,ram,4,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c06fab8;
P_0c06fab8: /* original f549, guest PC 0x0c06fab8 */
if(!s->budget--) { s->failed_pc=0x0c06fab8u; return 0; }
vf3_matrix_load(s,ram,5,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c06faba;
P_0c06faba: /* original f649, guest PC 0x0c06faba */
if(!s->budget--) { s->failed_pc=0x0c06fabau; return 0; }
vf3_matrix_load(s,ram,6,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c06fabc;
P_0c06fabc: /* original f78d, guest PC 0x0c06fabc */
if(!s->budget--) { s->failed_pc=0x0c06fabcu; return 0; }
fr[7]=0;
goto P_0c06fabe;
P_0c06fabe: /* original f5fd, guest PC 0x0c06fabe */
if(!s->budget--) { s->failed_pc=0x0c06fabeu; return 0; }
if(!vf3_fpu_ftrv(xf,fr+4,r[18],fr+4)) goto unsupported;
goto P_0c06fac0;
P_0c06fac0: /* original 750c, guest PC 0x0c06fac0 */
if(!s->budget--) { s->failed_pc=0x0c06fac0u; return 0; }
r[5]+=0x0000000cu;
goto P_0c06fac2;
P_0c06fac2: /* original f56b, guest PC 0x0c06fac2 */
if(!s->budget--) { s->failed_pc=0x0c06fac2u; return 0; }
r[5]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,6,r[5]);
goto P_0c06fac4;
P_0c06fac4: /* original f55b, guest PC 0x0c06fac4 */
if(!s->budget--) { s->failed_pc=0x0c06fac4u; return 0; }
r[5]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,5,r[5]);
goto P_0c06fac6;
P_0c06fac6: /* original f54b, guest PC 0x0c06fac6 */
if(!s->budget--) { s->failed_pc=0x0c06fac6u; return 0; }
r[5]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,4,r[5]);
goto P_0c06fac8;
P_0c06fac8: /* original 480b, guest PC 0x0c06fac8 */
if(!s->budget--) { s->failed_pc=0x0c06fac8u; return 0; }
target=r[8];
r[16]=code_base|0x0c06faccu;
r[4]=0x00000001u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06faccu) { target=s->pc; goto dispatch; }
goto P_0c06facc;
P_0c06faca: /* original e401, guest PC 0x0c06faca */
if(!s->budget--) { s->failed_pc=0x0c06facau; return 0; }
r[4]=0x00000001u;
goto P_0c06facc;
P_0c06facc: /* original e064, guest PC 0x0c06facc */
if(!s->budget--) { s->failed_pc=0x0c06faccu; return 0; }
r[0]=0x00000064u;
goto P_0c06face;
P_0c06face: /* original f28d, guest PC 0x0c06face */
if(!s->budget--) { s->failed_pc=0x0c06faceu; return 0; }
fr[2]=0;
goto P_0c06fad0;
P_0c06fad0: /* original fdd6, guest PC 0x0c06fad0 */
if(!s->budget--) { s->failed_pc=0x0c06fad0u; return 0; }
vf3_matrix_load(s,ram,13,r[13]+r[0]);
goto P_0c06fad2;
P_0c06fad2: /* original c727, guest PC 0x0c06fad2 */
if(!s->budget--) { s->failed_pc=0x0c06fad2u; return 0; }
r[0]=code_base|0x0006fb70u;
goto P_0c06fad4;
P_0c06fad4: /* original f308, guest PC 0x0c06fad4 */
if(!s->budget--) { s->failed_pc=0x0c06fad4u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c06fad6;
P_0c06fad6: /* original e054, guest PC 0x0c06fad6 */
if(!s->budget--) { s->failed_pc=0x0c06fad6u; return 0; }
r[0]=0x00000054u;
goto P_0c06fad8;
P_0c06fad8: /* original fed6, guest PC 0x0c06fad8 */
if(!s->budget--) { s->failed_pc=0x0c06fad8u; return 0; }
vf3_matrix_load(s,ram,14,r[13]+r[0]);
goto P_0c06fada;
P_0c06fada: /* original e050, guest PC 0x0c06fada */
if(!s->budget--) { s->failed_pc=0x0c06fadau; return 0; }
r[0]=0x00000050u;
goto P_0c06fadc;
P_0c06fadc: /* original f1d6, guest PC 0x0c06fadc */
if(!s->budget--) { s->failed_pc=0x0c06fadcu; return 0; }
vf3_matrix_load(s,ram,1,r[13]+r[0]);
goto P_0c06fade;
P_0c06fade: /* original f215, guest PC 0x0c06fade */
if(!s->budget--) { s->failed_pc=0x0c06fadeu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[2])>as_float(fr[1]))!=0);
goto P_0c06fae0;
P_0c06fae0: /* original 8f08, guest PC 0x0c06fae0 */
if(!s->budget--) { s->failed_pc=0x0c06fae0u; return 0; }
cond=r[17]&1u;
fr[14]=vf3_fpu_binary(fr[14],fr[3],r[18],'*');
if(!cond) { goto P_0c06faf4; }
goto P_0c06fae4;
P_0c06fae2: /* original fe32, guest PC 0x0c06fae2 */
if(!s->budget--) { s->failed_pc=0x0c06fae2u; return 0; }
fr[14]=vf3_fpu_binary(fr[14],fr[3],r[18],'*');
goto P_0c06fae4;
P_0c06fae4: /* original 84a4, guest PC 0x0c06fae4 */
if(!s->budget--) { s->failed_pc=0x0c06fae4u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[10]+4,1);
goto P_0c06fae6;
P_0c06fae6: /* original 9c3d, guest PC 0x0c06fae6 */
if(!s->budget--) { s->failed_pc=0x0c06fae6u; return 0; }
r[12]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06fb64u,2);
goto P_0c06fae8;
P_0c06fae8: /* original 600c, guest PC 0x0c06fae8 */
if(!s->budget--) { s->failed_pc=0x0c06fae8u; return 0; }
r[0]=r[0]&255u;
goto P_0c06faea;
P_0c06faea: /* original d322, guest PC 0x0c06faea */
if(!s->budget--) { s->failed_pc=0x0c06faeau; return 0; }
r[3]=read(ram,0x0c06fb74u,4);
goto P_0c06faec;
P_0c06faec: /* original 20cf, guest PC 0x0c06faec */
if(!s->budget--) { s->failed_pc=0x0c06faecu; return 0; }
r[19]=(uint32_t)((int32_t)(int16_t)r[0]*(int32_t)(int16_t)r[12]);
goto P_0c06faee;
P_0c06faee: /* original 0c1a, guest PC 0x0c06faee */
if(!s->budget--) { s->failed_pc=0x0c06faeeu; return 0; }
r[12]=r[19];
goto P_0c06faf0;
P_0c06faf0: /* original a007, guest PC 0x0c06faf0 */
if(!s->budget--) { s->failed_pc=0x0c06faf0u; return 0; }
r[12]=(uint32_t)(int32_t)(int16_t)r[12];
goto P_0c06fb02;
P_0c06faf2: /* original 6ccf, guest PC 0x0c06faf2 */
if(!s->budget--) { s->failed_pc=0x0c06faf2u; return 0; }
r[12]=(uint32_t)(int32_t)(int16_t)r[12];
goto P_0c06faf4;
P_0c06faf4: /* original 84a4, guest PC 0x0c06faf4 */
if(!s->budget--) { s->failed_pc=0x0c06faf4u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[10]+4,1);
goto P_0c06faf6;
P_0c06faf6: /* original 9c35, guest PC 0x0c06faf6 */
if(!s->budget--) { s->failed_pc=0x0c06faf6u; return 0; }
r[12]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06fb64u,2);
goto P_0c06faf8;
P_0c06faf8: /* original 600c, guest PC 0x0c06faf8 */
if(!s->budget--) { s->failed_pc=0x0c06faf8u; return 0; }
r[0]=r[0]&255u;
goto P_0c06fafa;
P_0c06fafa: /* original d31f, guest PC 0x0c06fafa */
if(!s->budget--) { s->failed_pc=0x0c06fafau; return 0; }
r[3]=read(ram,0x0c06fb78u,4);
goto P_0c06fafc;
P_0c06fafc: /* original 20cf, guest PC 0x0c06fafc */
if(!s->budget--) { s->failed_pc=0x0c06fafcu; return 0; }
r[19]=(uint32_t)((int32_t)(int16_t)r[0]*(int32_t)(int16_t)r[12]);
goto P_0c06fafe;
P_0c06fafe: /* original 0c1a, guest PC 0x0c06fafe */
if(!s->budget--) { s->failed_pc=0x0c06fafeu; return 0; }
r[12]=r[19];
goto P_0c06fb00;
P_0c06fb00: /* original 6ccf, guest PC 0x0c06fb00 */
if(!s->budget--) { s->failed_pc=0x0c06fb00u; return 0; }
r[12]=(uint32_t)(int32_t)(int16_t)r[12];
goto P_0c06fb02;
P_0c06fb02: /* original 9031, guest PC 0x0c06fb02 */
if(!s->budget--) { s->failed_pc=0x0c06fb02u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06fb68u,2);
goto P_0c06fb04;
P_0c06fb04: /* original 3c3c, guest PC 0x0c06fb04 */
if(!s->budget--) { s->failed_pc=0x0c06fb04u; return 0; }
r[12]+=r[3];
goto P_0c06fb06;
P_0c06fb06: /* original 9b2e, guest PC 0x0c06fb06 */
if(!s->budget--) { s->failed_pc=0x0c06fb06u; return 0; }
r[11]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06fb66u,2);
goto P_0c06fb08;
P_0c06fb08: /* original fff7, guest PC 0x0c06fb08 */
if(!s->budget--) { s->failed_pc=0x0c06fb08u; return 0; }
vf3_matrix_store(s,ram,15,r[15]+r[0]);
goto P_0c06fb0a;
P_0c06fb0a: /* original e07c, guest PC 0x0c06fb0a */
if(!s->budget--) { s->failed_pc=0x0c06fb0au; return 0; }
r[0]=0x0000007cu;
goto P_0c06fb0c;
P_0c06fb0c: /* original fff7, guest PC 0x0c06fb0c */
if(!s->budget--) { s->failed_pc=0x0c06fb0cu; return 0; }
vf3_matrix_store(s,ram,15,r[15]+r[0]);
goto P_0c06fb0e;
P_0c06fb0e: /* original c71b, guest PC 0x0c06fb0e */
if(!s->budget--) { s->failed_pc=0x0c06fb0eu; return 0; }
r[0]=code_base|0x0006fb7cu;
goto P_0c06fb10;
P_0c06fb10: /* original 53f3, guest PC 0x0c06fb10 */
if(!s->budget--) { s->failed_pc=0x0c06fb10u; return 0; }
r[3]=read(ram,r[15]+12,4);
goto P_0c06fb12;
P_0c06fb12: /* original 3bcc, guest PC 0x0c06fb12 */
if(!s->budget--) { s->failed_pc=0x0c06fb12u; return 0; }
r[11]+=r[12];
goto P_0c06fb14;
P_0c06fb14: /* original f308, guest PC 0x0c06fb14 */
if(!s->budget--) { s->failed_pc=0x0c06fb14u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c06fb16;
P_0c06fb16: /* original f238, guest PC 0x0c06fb16 */
if(!s->budget--) { s->failed_pc=0x0c06fb16u; return 0; }
vf3_matrix_load(s,ram,2,r[3]);
goto P_0c06fb18;
P_0c06fb18: /* original 9027, guest PC 0x0c06fb18 */
if(!s->budget--) { s->failed_pc=0x0c06fb18u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06fb6au,2);
goto P_0c06fb1a;
P_0c06fb1a: /* original f232, guest PC 0x0c06fb1a */
if(!s->budget--) { s->failed_pc=0x0c06fb1au; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c06fb1c;
P_0c06fb1c: /* original f24d, guest PC 0x0c06fb1c */
if(!s->budget--) { s->failed_pc=0x0c06fb1cu; return 0; }
fr[2]^=0x80000000u;
goto P_0c06fb1e;
P_0c06fb1e: /* original ff27, guest PC 0x0c06fb1e */
if(!s->budget--) { s->failed_pc=0x0c06fb1eu; return 0; }
vf3_matrix_store(s,ram,2,r[15]+r[0]);
goto P_0c06fb20;
P_0c06fb20: /* original e03e, guest PC 0x0c06fb20 */
if(!s->budget--) { s->failed_pc=0x0c06fb20u; return 0; }
r[0]=0x0000003eu;
goto P_0c06fb22;
P_0c06fb22: /* original 53d3, guest PC 0x0c06fb22 */
if(!s->budget--) { s->failed_pc=0x0c06fb22u; return 0; }
r[3]=read(ram,r[13]+12,4);
goto P_0c06fb24;
P_0c06fb24: /* original 54d1, guest PC 0x0c06fb24 */
if(!s->budget--) { s->failed_pc=0x0c06fb24u; return 0; }
r[4]=read(ram,r[13]+4,4);
goto P_0c06fb26;
P_0c06fb26: /* original 6233, guest PC 0x0c06fb26 */
if(!s->budget--) { s->failed_pc=0x0c06fb26u; return 0; }
r[2]=r[3];
goto P_0c06fb28;
P_0c06fb28: /* original 7240, guest PC 0x0c06fb28 */
if(!s->budget--) { s->failed_pc=0x0c06fb28u; return 0; }
r[2]+=0x00000040u;
goto P_0c06fb2a;
P_0c06fb2a: /* original 991f, guest PC 0x0c06fb2a */
if(!s->budget--) { s->failed_pc=0x0c06fb2au; return 0; }
r[9]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06fb6cu,2);
goto P_0c06fb2c;
P_0c06fb2c: /* original 6e43, guest PC 0x0c06fb2c */
if(!s->budget--) { s->failed_pc=0x0c06fb2cu; return 0; }
r[14]=r[4];
goto P_0c06fb2e;
P_0c06fb2e: /* original 1f33, guest PC 0x0c06fb2e */
if(!s->budget--) { s->failed_pc=0x0c06fb2eu; return 0; }
write(ram,r[15]+12,r[3],4);
goto P_0c06fb30;
P_0c06fb30: /* original 7e30, guest PC 0x0c06fb30 */
if(!s->budget--) { s->failed_pc=0x0c06fb30u; return 0; }
r[14]+=0x00000030u;
goto P_0c06fb32;
P_0c06fb32: /* original 1f21, guest PC 0x0c06fb32 */
if(!s->budget--) { s->failed_pc=0x0c06fb32u; return 0; }
write(ram,r[15]+4,r[2],4);
goto P_0c06fb34;
P_0c06fb34: /* original e202, guest PC 0x0c06fb34 */
if(!s->budget--) { s->failed_pc=0x0c06fb34u; return 0; }
r[2]=0x00000002u;
goto P_0c06fb36;
P_0c06fb36: /* original 03ad, guest PC 0x0c06fb36 */
if(!s->budget--) { s->failed_pc=0x0c06fb36u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[10]+r[0],2);
goto P_0c06fb38;
P_0c06fb38: /* original 633d, guest PC 0x0c06fb38 */
if(!s->budget--) { s->failed_pc=0x0c06fb38u; return 0; }
r[3]=r[3]&65535u;
goto P_0c06fb3a;
P_0c06fb3a: /* original 3323, guest PC 0x0c06fb3a */
if(!s->budget--) { s->failed_pc=0x0c06fb3au; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>=(int32_t)r[2])!=0);
goto P_0c06fb3c;
P_0c06fb3c: /* original 8d03, guest PC 0x0c06fb3c */
if(!s->budget--) { s->failed_pc=0x0c06fb3cu; return 0; }
cond=r[17]&1u;
r[9]+=r[14];
if(cond) { goto P_0c06fb46; }
goto P_0c06fb40;
P_0c06fb3e: /* original 39ec, guest PC 0x0c06fb3e */
if(!s->budget--) { s->failed_pc=0x0c06fb3eu; return 0; }
r[9]+=r[14];
goto P_0c06fb40;
P_0c06fb40: /* original d30f, guest PC 0x0c06fb40 */
if(!s->budget--) { s->failed_pc=0x0c06fb40u; return 0; }
r[3]=read(ram,0x0c06fb80u,4);
goto P_0c06fb42;
P_0c06fb42: /* original 432b, guest PC 0x0c06fb42 */
if(!s->budget--) { s->failed_pc=0x0c06fb42u; return 0; }
target=r[3];
code_base=target&0xff000000u;
switch(target&0x1fffffffu) {
case 0x0c06ffdeu: goto P_0c06ffde;
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
P_0c06fb44: /* original 0009, guest PC 0x0c06fb44 */
if(!s->budget--) { s->failed_pc=0x0c06fb44u; return 0; }
goto P_0c06fb46;
P_0c06fb46: /* original d30f, guest PC 0x0c06fb46 */
if(!s->budget--) { s->failed_pc=0x0c06fb46u; return 0; }
r[3]=read(ram,0x0c06fb84u,4);
goto P_0c06fb48;
P_0c06fb48: /* original 430b, guest PC 0x0c06fb48 */
if(!s->budget--) { s->failed_pc=0x0c06fb48u; return 0; }
target=r[3];
r[16]=code_base|0x0c06fb4cu;
r[4]=0x00000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06fb4cu) { target=s->pc; goto dispatch; }
goto P_0c06fb4c;
P_0c06fb4a: /* original e400, guest PC 0x0c06fb4a */
if(!s->budget--) { s->failed_pc=0x0c06fb4au; return 0; }
r[4]=0x00000000u;
goto P_0c06fb4c;
P_0c06fb4c: /* original d30e, guest PC 0x0c06fb4c */
if(!s->budget--) { s->failed_pc=0x0c06fb4cu; return 0; }
r[3]=read(ram,0x0c06fb88u,4);
goto P_0c06fb4e;
P_0c06fb4e: /* original 430b, guest PC 0x0c06fb4e */
if(!s->budget--) { s->failed_pc=0x0c06fb4eu; return 0; }
target=r[3];
r[16]=code_base|0x0c06fb52u;
r[4]=read(ram,r[15]+12,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06fb52u) { target=s->pc; goto dispatch; }
goto P_0c06fb52;
P_0c06fb50: /* original 54f3, guest PC 0x0c06fb50 */
if(!s->budget--) { s->failed_pc=0x0c06fb50u; return 0; }
r[4]=read(ram,r[15]+12,4);
goto P_0c06fb52;
P_0c06fb52: /* original d20e, guest PC 0x0c06fb52 */
if(!s->budget--) { s->failed_pc=0x0c06fb52u; return 0; }
r[2]=read(ram,0x0c06fb8cu,4);
goto P_0c06fb54;
P_0c06fb54: /* original 420b, guest PC 0x0c06fb54 */
if(!s->budget--) { s->failed_pc=0x0c06fb54u; return 0; }
target=r[2];
r[16]=code_base|0x0c06fb58u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06fb58u) { target=s->pc; goto dispatch; }
goto P_0c06fb58;
P_0c06fb56: /* original 0009, guest PC 0x0c06fb56 */
if(!s->budget--) { s->failed_pc=0x0c06fb56u; return 0; }
goto P_0c06fb58;
P_0c06fb58: /* original 9509, guest PC 0x0c06fb58 */
if(!s->budget--) { s->failed_pc=0x0c06fb58u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06fb6eu,2);
goto P_0c06fb5a;
P_0c06fb5a: /* original 64f3, guest PC 0x0c06fb5a */
if(!s->budget--) { s->failed_pc=0x0c06fb5au; return 0; }
r[4]=r[15];
goto P_0c06fb5c;
P_0c06fb5c: /* original 747c, guest PC 0x0c06fb5c */
if(!s->budget--) { s->failed_pc=0x0c06fb5cu; return 0; }
r[4]+=0x0000007cu;
goto P_0c06fb5e;
P_0c06fb5e: /* original 35fc, guest PC 0x0c06fb5e */
if(!s->budget--) { s->failed_pc=0x0c06fb5eu; return 0; }
r[5]+=r[15];
goto P_0c06fb60;
P_0c06fb60: /* original a016, guest PC 0x0c06fb60 */
if(!s->budget--) { s->failed_pc=0x0c06fb60u; return 0; }
goto P_0c06fb90;
P_0c06fb62: /* original 0009, guest PC 0x0c06fb62 */
if(!s->budget--) { s->failed_pc=0x0c06fb62u; return 0; }
if(!vf3_matrix_family(0x0c06fb64u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c06fb64u; return 0; } return 1;
P_0c06fb90: /* original f449, guest PC 0x0c06fb90 */
if(!s->budget--) { s->failed_pc=0x0c06fb90u; return 0; }
vf3_matrix_load(s,ram,4,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c06fb92;
P_0c06fb92: /* original f549, guest PC 0x0c06fb92 */
if(!s->budget--) { s->failed_pc=0x0c06fb92u; return 0; }
vf3_matrix_load(s,ram,5,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c06fb94;
P_0c06fb94: /* original f649, guest PC 0x0c06fb94 */
if(!s->budget--) { s->failed_pc=0x0c06fb94u; return 0; }
vf3_matrix_load(s,ram,6,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c06fb96;
P_0c06fb96: /* original f78d, guest PC 0x0c06fb96 */
if(!s->budget--) { s->failed_pc=0x0c06fb96u; return 0; }
fr[7]=0;
goto P_0c06fb98;
P_0c06fb98: /* original f5fd, guest PC 0x0c06fb98 */
if(!s->budget--) { s->failed_pc=0x0c06fb98u; return 0; }
if(!vf3_fpu_ftrv(xf,fr+4,r[18],fr+4)) goto unsupported;
goto P_0c06fb9a;
P_0c06fb9a: /* original 750c, guest PC 0x0c06fb9a */
if(!s->budget--) { s->failed_pc=0x0c06fb9au; return 0; }
r[5]+=0x0000000cu;
goto P_0c06fb9c;
P_0c06fb9c: /* original f56b, guest PC 0x0c06fb9c */
if(!s->budget--) { s->failed_pc=0x0c06fb9cu; return 0; }
r[5]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,6,r[5]);
goto P_0c06fb9e;
P_0c06fb9e: /* original f55b, guest PC 0x0c06fb9e */
if(!s->budget--) { s->failed_pc=0x0c06fb9eu; return 0; }
r[5]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,5,r[5]);
goto P_0c06fba0;
P_0c06fba0: /* original f54b, guest PC 0x0c06fba0 */
if(!s->budget--) { s->failed_pc=0x0c06fba0u; return 0; }
r[5]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,4,r[5]);
goto P_0c06fba2;
P_0c06fba2: /* original 0009, guest PC 0x0c06fba2 */
if(!s->budget--) { s->failed_pc=0x0c06fba2u; return 0; }
goto P_0c06fba4;
P_0c06fba4: /* original d207, guest PC 0x0c06fba4 */
if(!s->budget--) { s->failed_pc=0x0c06fba4u; return 0; }
r[2]=read(ram,0x0c06fbc4u,4);
goto P_0c06fba6;
P_0c06fba6: /* original 420b, guest PC 0x0c06fba6 */
if(!s->budget--) { s->failed_pc=0x0c06fba6u; return 0; }
target=r[2];
r[16]=code_base|0x0c06fbaau;
r[4]=0x00000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06fbaau) { target=s->pc; goto dispatch; }
goto P_0c06fbaa;
P_0c06fba8: /* original e400, guest PC 0x0c06fba8 */
if(!s->budget--) { s->failed_pc=0x0c06fba8u; return 0; }
r[4]=0x00000000u;
goto P_0c06fbaa;
P_0c06fbaa: /* original 1fe2, guest PC 0x0c06fbaa */
if(!s->budget--) { s->failed_pc=0x0c06fbaau; return 0; }
write(ram,r[15]+8,r[14],4);
goto P_0c06fbac;
P_0c06fbac: /* original 2f92, guest PC 0x0c06fbac */
if(!s->budget--) { s->failed_pc=0x0c06fbacu; return 0; }
write(ram,r[15],r[9],4);
goto P_0c06fbae;
P_0c06fbae: /* original d306, guest PC 0x0c06fbae */
if(!s->budget--) { s->failed_pc=0x0c06fbaeu; return 0; }
r[3]=read(ram,0x0c06fbc8u,4);
goto P_0c06fbb0;
P_0c06fbb0: /* original 430b, guest PC 0x0c06fbb0 */
if(!s->budget--) { s->failed_pc=0x0c06fbb0u; return 0; }
target=r[3];
r[16]=code_base|0x0c06fbb4u;
r[4]=read(ram,r[15]+4,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06fbb4u) { target=s->pc; goto dispatch; }
goto P_0c06fbb4;
P_0c06fbb2: /* original 54f1, guest PC 0x0c06fbb2 */
if(!s->budget--) { s->failed_pc=0x0c06fbb2u; return 0; }
r[4]=read(ram,r[15]+4,4);
goto P_0c06fbb4;
P_0c06fbb4: /* original d305, guest PC 0x0c06fbb4 */
if(!s->budget--) { s->failed_pc=0x0c06fbb4u; return 0; }
r[3]=read(ram,0x0c06fbccu,4);
goto P_0c06fbb6;
P_0c06fbb6: /* original e204, guest PC 0x0c06fbb6 */
if(!s->budget--) { s->failed_pc=0x0c06fbb6u; return 0; }
r[2]=0x00000004u;
goto P_0c06fbb8;
P_0c06fbb8: /* original 432b, guest PC 0x0c06fbb8 */
if(!s->budget--) { s->failed_pc=0x0c06fbb8u; return 0; }
target=r[3];
write(ram,r[15]+4,r[2],4);
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
P_0c06fbba: /* original 1f21, guest PC 0x0c06fbba */
if(!s->budget--) { s->failed_pc=0x0c06fbbau; return 0; }
write(ram,r[15]+4,r[2],4);
if(!vf3_matrix_family(0x0c06fbbcu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c06fbbcu; return 0; } return 1;
P_0c06ffde: /* original d328, guest PC 0x0c06ffde */
if(!s->budget--) { s->failed_pc=0x0c06ffdeu; return 0; }
r[3]=read(ram,0x0c070080u,4);
goto P_0c06ffe0;
P_0c06ffe0: /* original 64d3, guest PC 0x0c06ffe0 */
if(!s->budget--) { s->failed_pc=0x0c06ffe0u; return 0; }
r[4]=r[13];
goto P_0c06ffe2;
P_0c06ffe2: /* original 55f3, guest PC 0x0c06ffe2 */
if(!s->budget--) { s->failed_pc=0x0c06ffe2u; return 0; }
r[5]=read(ram,r[15]+12,4);
goto P_0c06ffe4;
P_0c06ffe4: /* original 430b, guest PC 0x0c06ffe4 */
if(!s->budget--) { s->failed_pc=0x0c06ffe4u; return 0; }
target=r[3];
r[16]=code_base|0x0c06ffe8u;
r[4]+=0x00000010u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06ffe8u) { target=s->pc; goto dispatch; }
goto P_0c06ffe8;
P_0c06ffe6: /* original 7410, guest PC 0x0c06ffe6 */
if(!s->budget--) { s->failed_pc=0x0c06ffe6u; return 0; }
r[4]+=0x00000010u;
goto P_0c06ffe8;
P_0c06ffe8: /* original 913c, guest PC 0x0c06ffe8 */
if(!s->budget--) { s->failed_pc=0x0c06ffe8u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c070064u,2);
goto P_0c06ffea;
P_0c06ffea: /* original 3f1c, guest PC 0x0c06ffea */
if(!s->budget--) { s->failed_pc=0x0c06ffeau; return 0; }
r[15]+=r[1];
goto P_0c06ffec;
P_0c06ffec: /* original 4f16, guest PC 0x0c06ffec */
if(!s->budget--) { s->failed_pc=0x0c06ffecu; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c06ffee;
P_0c06ffee: /* original 4f26, guest PC 0x0c06ffee */
if(!s->budget--) { s->failed_pc=0x0c06ffeeu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c06fff0;
P_0c06fff0: /* original fcf9, guest PC 0x0c06fff0 */
if(!s->budget--) { s->failed_pc=0x0c06fff0u; return 0; }
vf3_matrix_load(s,ram,12,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c06fff2;
P_0c06fff2: /* original fdf9, guest PC 0x0c06fff2 */
if(!s->budget--) { s->failed_pc=0x0c06fff2u; return 0; }
vf3_matrix_load(s,ram,13,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c06fff4;
P_0c06fff4: /* original fef9, guest PC 0x0c06fff4 */
if(!s->budget--) { s->failed_pc=0x0c06fff4u; return 0; }
vf3_matrix_load(s,ram,14,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c06fff6;
P_0c06fff6: /* original fff9, guest PC 0x0c06fff6 */
if(!s->budget--) { s->failed_pc=0x0c06fff6u; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c06fff8;
P_0c06fff8: /* original 68f6, guest PC 0x0c06fff8 */
if(!s->budget--) { s->failed_pc=0x0c06fff8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c06fffa;
P_0c06fffa: /* original 69f6, guest PC 0x0c06fffa */
if(!s->budget--) { s->failed_pc=0x0c06fffau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c06fffc;
P_0c06fffc: /* original 6af6, guest PC 0x0c06fffc */
if(!s->budget--) { s->failed_pc=0x0c06fffcu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c06fffe;
P_0c06fffe: /* original 6bf6, guest PC 0x0c06fffe */
if(!s->budget--) { s->failed_pc=0x0c06fffeu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c070000;
P_0c070000: /* original 6cf6, guest PC 0x0c070000 */
if(!s->budget--) { s->failed_pc=0x0c070000u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c070002;
P_0c070002: /* original 6df6, guest PC 0x0c070002 */
if(!s->budget--) { s->failed_pc=0x0c070002u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c070004;
P_0c070004: /* original 000b, guest PC 0x0c070004 */
if(!s->budget--) { s->failed_pc=0x0c070004u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c070006: /* original 6ef6, guest PC 0x0c070006 */
if(!s->budget--) { s->failed_pc=0x0c070006u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c070008u,s,ram);
unsupported: s->failed_pc=target; return 0;
}
