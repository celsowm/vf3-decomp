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
int vf3_away_batch208_adapter_4(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c0abbfcu: goto P_0c0abbfc;
case 0x0c0abbfeu: goto P_0c0abbfe;
case 0x0c0abc00u: goto P_0c0abc00;
case 0x0c0abc02u: goto P_0c0abc02;
case 0x0c0abc04u: goto P_0c0abc04;
case 0x0c0abc06u: goto P_0c0abc06;
case 0x0c0abc08u: goto P_0c0abc08;
case 0x0c0abc0au: goto P_0c0abc0a;
case 0x0c0abc0cu: goto P_0c0abc0c;
case 0x0c0abc0eu: goto P_0c0abc0e;
case 0x0c0abc10u: goto P_0c0abc10;
case 0x0c0abc12u: goto P_0c0abc12;
case 0x0c0abc14u: goto P_0c0abc14;
case 0x0c0abc16u: goto P_0c0abc16;
case 0x0c0abc18u: goto P_0c0abc18;
case 0x0c0abc1au: goto P_0c0abc1a;
case 0x0c0abc1cu: goto P_0c0abc1c;
case 0x0c0abc1eu: goto P_0c0abc1e;
case 0x0c0abc20u: goto P_0c0abc20;
case 0x0c0abc22u: goto P_0c0abc22;
case 0x0c0abc24u: goto P_0c0abc24;
case 0x0c0abc26u: goto P_0c0abc26;
case 0x0c0abc28u: goto P_0c0abc28;
case 0x0c0abc2au: goto P_0c0abc2a;
case 0x0c0abc2cu: goto P_0c0abc2c;
case 0x0c0abc2eu: goto P_0c0abc2e;
case 0x0c0abc30u: goto P_0c0abc30;
case 0x0c0abc32u: goto P_0c0abc32;
case 0x0c0abc34u: goto P_0c0abc34;
case 0x0c0abc36u: goto P_0c0abc36;
case 0x0c0abc38u: goto P_0c0abc38;
case 0x0c0abc3au: goto P_0c0abc3a;
case 0x0c0abc3cu: goto P_0c0abc3c;
case 0x0c0abc3eu: goto P_0c0abc3e;
case 0x0c0abc40u: goto P_0c0abc40;
case 0x0c0abc42u: goto P_0c0abc42;
case 0x0c0abc44u: goto P_0c0abc44;
case 0x0c0abc46u: goto P_0c0abc46;
case 0x0c0abc48u: goto P_0c0abc48;
case 0x0c0abc4au: goto P_0c0abc4a;
case 0x0c0abc4cu: goto P_0c0abc4c;
case 0x0c0abc4eu: goto P_0c0abc4e;
case 0x0c0abc50u: goto P_0c0abc50;
case 0x0c0abc52u: goto P_0c0abc52;
case 0x0c0abc54u: goto P_0c0abc54;
case 0x0c0abc56u: goto P_0c0abc56;
case 0x0c0abc58u: goto P_0c0abc58;
case 0x0c0abc5au: goto P_0c0abc5a;
case 0x0c0abc5cu: goto P_0c0abc5c;
case 0x0c0abc5eu: goto P_0c0abc5e;
case 0x0c0abc60u: goto P_0c0abc60;
case 0x0c0abc62u: goto P_0c0abc62;
case 0x0c0abc64u: goto P_0c0abc64;
case 0x0c0abc66u: goto P_0c0abc66;
case 0x0c0abc68u: goto P_0c0abc68;
case 0x0c0abc6au: goto P_0c0abc6a;
case 0x0c0abc6cu: goto P_0c0abc6c;
case 0x0c0abc6eu: goto P_0c0abc6e;
case 0x0c0abc70u: goto P_0c0abc70;
case 0x0c0abc72u: goto P_0c0abc72;
case 0x0c0abc74u: goto P_0c0abc74;
case 0x0c0abc76u: goto P_0c0abc76;
case 0x0c0abc78u: goto P_0c0abc78;
case 0x0c0abc7au: goto P_0c0abc7a;
case 0x0c0abc7cu: goto P_0c0abc7c;
case 0x0c0abc7eu: goto P_0c0abc7e;
case 0x0c0abc80u: goto P_0c0abc80;
case 0x0c0abc82u: goto P_0c0abc82;
case 0x0c0abc84u: goto P_0c0abc84;
case 0x0c0abc86u: goto P_0c0abc86;
case 0x0c0abc88u: goto P_0c0abc88;
case 0x0c0abc8au: goto P_0c0abc8a;
case 0x0c0abc8cu: goto P_0c0abc8c;
case 0x0c0abc8eu: goto P_0c0abc8e;
case 0x0c0abc90u: goto P_0c0abc90;
case 0x0c0abc92u: goto P_0c0abc92;
case 0x0c0abc94u: goto P_0c0abc94;
case 0x0c0abc96u: goto P_0c0abc96;
case 0x0c0abc98u: goto P_0c0abc98;
case 0x0c0abc9au: goto P_0c0abc9a;
case 0x0c0abc9cu: goto P_0c0abc9c;
case 0x0c0abc9eu: goto P_0c0abc9e;
case 0x0c0abca0u: goto P_0c0abca0;
case 0x0c0abea8u: goto P_0c0abea8;
case 0x0c0abeaau: goto P_0c0abeaa;
case 0x0c0abeacu: goto P_0c0abeac;
case 0x0c0abeaeu: goto P_0c0abeae;
case 0x0c0abeb0u: goto P_0c0abeb0;
case 0x0c0abeb2u: goto P_0c0abeb2;
case 0x0c0abeb4u: goto P_0c0abeb4;
case 0x0c0abeb6u: goto P_0c0abeb6;
case 0x0c0abeb8u: goto P_0c0abeb8;
case 0x0c0abebau: goto P_0c0abeba;
case 0x0c0abebcu: goto P_0c0abebc;
case 0x0c0abebeu: goto P_0c0abebe;
case 0x0c0abec0u: goto P_0c0abec0;
case 0x0c0abec2u: goto P_0c0abec2;
case 0x0c0abec4u: goto P_0c0abec4;
case 0x0c0abec6u: goto P_0c0abec6;
case 0x0c0abec8u: goto P_0c0abec8;
case 0x0c0abecau: goto P_0c0abeca;
case 0x0c0abeccu: goto P_0c0abecc;
case 0x0c0abeceu: goto P_0c0abece;
case 0x0c0abed0u: goto P_0c0abed0;
case 0x0c0abed2u: goto P_0c0abed2;
case 0x0c0abed4u: goto P_0c0abed4;
case 0x0c0abed6u: goto P_0c0abed6;
case 0x0c0abed8u: goto P_0c0abed8;
case 0x0c0abedau: goto P_0c0abeda;
case 0x0c0abedcu: goto P_0c0abedc;
case 0x0c0abedeu: goto P_0c0abede;
case 0x0c0abee0u: goto P_0c0abee0;
case 0x0c0abee2u: goto P_0c0abee2;
case 0x0c0abee4u: goto P_0c0abee4;
case 0x0c0abee6u: goto P_0c0abee6;
case 0x0c0abee8u: goto P_0c0abee8;
case 0x0c0abeeau: goto P_0c0abeea;
case 0x0c0abeecu: goto P_0c0abeec;
case 0x0c0abeeeu: goto P_0c0abeee;
case 0x0c0abef0u: goto P_0c0abef0;
case 0x0c0abef2u: goto P_0c0abef2;
case 0x0c0abef4u: goto P_0c0abef4;
case 0x0c0abef6u: goto P_0c0abef6;
case 0x0c0abef8u: goto P_0c0abef8;
case 0x0c0abefau: goto P_0c0abefa;
case 0x0c0abefcu: goto P_0c0abefc;
case 0x0c0abefeu: goto P_0c0abefe;
case 0x0c0abf00u: goto P_0c0abf00;
case 0x0c0abf02u: goto P_0c0abf02;
case 0x0c0abf04u: goto P_0c0abf04;
case 0x0c0abf06u: goto P_0c0abf06;
case 0x0c0abf08u: goto P_0c0abf08;
case 0x0c0abf0au: goto P_0c0abf0a;
case 0x0c0abf0cu: goto P_0c0abf0c;
case 0x0c0abf0eu: goto P_0c0abf0e;
case 0x0c0abf10u: goto P_0c0abf10;
case 0x0c0abf12u: goto P_0c0abf12;
case 0x0c0abf14u: goto P_0c0abf14;
case 0x0c0abf16u: goto P_0c0abf16;
case 0x0c0abf18u: goto P_0c0abf18;
case 0x0c0abf1au: goto P_0c0abf1a;
case 0x0c0abf1cu: goto P_0c0abf1c;
case 0x0c0abf48u: goto P_0c0abf48;
case 0x0c0abf4au: goto P_0c0abf4a;
case 0x0c0abf4cu: goto P_0c0abf4c;
case 0x0c0abf4eu: goto P_0c0abf4e;
case 0x0c0abf50u: goto P_0c0abf50;
case 0x0c0abf52u: goto P_0c0abf52;
case 0x0c0abf54u: goto P_0c0abf54;
case 0x0c0abf56u: goto P_0c0abf56;
case 0x0c0abf58u: goto P_0c0abf58;
case 0x0c0abf5au: goto P_0c0abf5a;
case 0x0c0abf5cu: goto P_0c0abf5c;
case 0x0c0abf5eu: goto P_0c0abf5e;
case 0x0c0abf60u: goto P_0c0abf60;
case 0x0c0abf62u: goto P_0c0abf62;
case 0x0c0abf64u: goto P_0c0abf64;
case 0x0c0abf66u: goto P_0c0abf66;
case 0x0c0abf68u: goto P_0c0abf68;
case 0x0c0abf6au: goto P_0c0abf6a;
case 0x0c0abf6cu: goto P_0c0abf6c;
case 0x0c0abf6eu: goto P_0c0abf6e;
case 0x0c0abf70u: goto P_0c0abf70;
case 0x0c0abf72u: goto P_0c0abf72;
case 0x0c0abf74u: goto P_0c0abf74;
case 0x0c0abf76u: goto P_0c0abf76;
case 0x0c0abf78u: goto P_0c0abf78;
case 0x0c0abf7au: goto P_0c0abf7a;
case 0x0c0abf7cu: goto P_0c0abf7c;
case 0x0c0abf7eu: goto P_0c0abf7e;
case 0x0c0abf80u: goto P_0c0abf80;
case 0x0c0abf82u: goto P_0c0abf82;
case 0x0c0abf84u: goto P_0c0abf84;
case 0x0c0abf86u: goto P_0c0abf86;
case 0x0c0abf88u: goto P_0c0abf88;
case 0x0c0abf8au: goto P_0c0abf8a;
case 0x0c0abf8cu: goto P_0c0abf8c;
case 0x0c0abf8eu: goto P_0c0abf8e;
case 0x0c0abf90u: goto P_0c0abf90;
case 0x0c0abf92u: goto P_0c0abf92;
case 0x0c0abf94u: goto P_0c0abf94;
case 0x0c0abf96u: goto P_0c0abf96;
case 0x0c0abf98u: goto P_0c0abf98;
case 0x0c0abf9au: goto P_0c0abf9a;
case 0x0c0abf9cu: goto P_0c0abf9c;
case 0x0c0abf9eu: goto P_0c0abf9e;
case 0x0c0abfa0u: goto P_0c0abfa0;
case 0x0c0ac078u: goto P_0c0ac078;
case 0x0c0ac07au: goto P_0c0ac07a;
case 0x0c0ac07cu: goto P_0c0ac07c;
case 0x0c0ac07eu: goto P_0c0ac07e;
case 0x0c0ac080u: goto P_0c0ac080;
case 0x0c0ac082u: goto P_0c0ac082;
case 0x0c0ac084u: goto P_0c0ac084;
case 0x0c0ac086u: goto P_0c0ac086;
case 0x0c0ac088u: goto P_0c0ac088;
case 0x0c0ac08au: goto P_0c0ac08a;
case 0x0c0ac08cu: goto P_0c0ac08c;
case 0x0c0ac08eu: goto P_0c0ac08e;
case 0x0c0ac090u: goto P_0c0ac090;
case 0x0c0ac092u: goto P_0c0ac092;
case 0x0c0ac094u: goto P_0c0ac094;
case 0x0c0ac096u: goto P_0c0ac096;
case 0x0c0ac098u: goto P_0c0ac098;
case 0x0c0ac09au: goto P_0c0ac09a;
case 0x0c0ac09cu: goto P_0c0ac09c;
case 0x0c0ac09eu: goto P_0c0ac09e;
case 0x0c0ac0a0u: goto P_0c0ac0a0;
case 0x0c0ac0a2u: goto P_0c0ac0a2;
case 0x0c0ac0a4u: goto P_0c0ac0a4;
case 0x0c0ac0a6u: goto P_0c0ac0a6;
case 0x0c0ac0a8u: goto P_0c0ac0a8;
case 0x0c0ac0aau: goto P_0c0ac0aa;
case 0x0c0ac0acu: goto P_0c0ac0ac;
case 0x0c0ac0aeu: goto P_0c0ac0ae;
case 0x0c0ac0b0u: goto P_0c0ac0b0;
case 0x0c0ac0b2u: goto P_0c0ac0b2;
case 0x0c0ac0b4u: goto P_0c0ac0b4;
case 0x0c0ac0b6u: goto P_0c0ac0b6;
case 0x0c0ac0b8u: goto P_0c0ac0b8;
case 0x0c0ac0bau: goto P_0c0ac0ba;
case 0x0c0ac0bcu: goto P_0c0ac0bc;
case 0x0c0ac0beu: goto P_0c0ac0be;
case 0x0c0ac0c0u: goto P_0c0ac0c0;
case 0x0c0ac0c2u: goto P_0c0ac0c2;
case 0x0c0ac0c4u: goto P_0c0ac0c4;
case 0x0c0ac0c6u: goto P_0c0ac0c6;
case 0x0c0ac0c8u: goto P_0c0ac0c8;
case 0x0c0ac0cau: goto P_0c0ac0ca;
case 0x0c0ac0ccu: goto P_0c0ac0cc;
case 0x0c0ac0ceu: goto P_0c0ac0ce;
case 0x0c0ac0d0u: goto P_0c0ac0d0;
case 0x0c0ac0d2u: goto P_0c0ac0d2;
case 0x0c0ac0d4u: goto P_0c0ac0d4;
case 0x0c0ac0d6u: goto P_0c0ac0d6;
case 0x0c0ac0d8u: goto P_0c0ac0d8;
case 0x0c0ac0dau: goto P_0c0ac0da;
case 0x0c0ac0dcu: goto P_0c0ac0dc;
case 0x0c0ac0deu: goto P_0c0ac0de;
case 0x0c0ac0e0u: goto P_0c0ac0e0;
case 0x0c0ac0e2u: goto P_0c0ac0e2;
case 0x0c0ac0e4u: goto P_0c0ac0e4;
case 0x0c0ac0e6u: goto P_0c0ac0e6;
case 0x0c0ac0e8u: goto P_0c0ac0e8;
case 0x0c0ac0eau: goto P_0c0ac0ea;
case 0x0c0ac0ecu: goto P_0c0ac0ec;
case 0x0c0ac0eeu: goto P_0c0ac0ee;
case 0x0c0ac0f0u: goto P_0c0ac0f0;
case 0x0c0ac0f2u: goto P_0c0ac0f2;
case 0x0c0ac0f4u: goto P_0c0ac0f4;
case 0x0c0ac0f6u: goto P_0c0ac0f6;
case 0x0c0ac0f8u: goto P_0c0ac0f8;
case 0x0c0ac0fau: goto P_0c0ac0fa;
case 0x0c0ac0fcu: goto P_0c0ac0fc;
case 0x0c0ac0feu: goto P_0c0ac0fe;
case 0x0c0ac100u: goto P_0c0ac100;
case 0x0c0ac102u: goto P_0c0ac102;
default: return vf3_matrix_family(target,s,ram);
}
P_0c0abbfc: /* original 2fe6, guest PC 0x0c0abbfc */
if(!s->budget--) { s->failed_pc=0x0c0abbfcu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0abbfe;
P_0c0abbfe: /* original 6643, guest PC 0x0c0abbfe */
if(!s->budget--) { s->failed_pc=0x0c0abbfeu; return 0; }
r[6]=r[4];
goto P_0c0abc00;
P_0c0abc00: /* original 2fd6, guest PC 0x0c0abc00 */
if(!s->budget--) { s->failed_pc=0x0c0abc00u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0abc02;
P_0c0abc02: /* original 6e43, guest PC 0x0c0abc02 */
if(!s->budget--) { s->failed_pc=0x0c0abc02u; return 0; }
r[14]=r[4];
goto P_0c0abc04;
P_0c0abc04: /* original 2fc6, guest PC 0x0c0abc04 */
if(!s->budget--) { s->failed_pc=0x0c0abc04u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0abc06;
P_0c0abc06: /* original 6d53, guest PC 0x0c0abc06 */
if(!s->budget--) { s->failed_pc=0x0c0abc06u; return 0; }
r[13]=r[5];
goto P_0c0abc08;
P_0c0abc08: /* original 4f22, guest PC 0x0c0abc08 */
if(!s->budget--) { s->failed_pc=0x0c0abc08u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0abc0a;
P_0c0abc0a: /* original d344, guest PC 0x0c0abc0a */
if(!s->budget--) { s->failed_pc=0x0c0abc0au; return 0; }
r[3]=read(ram,0x0c0abd1cu,4);
goto P_0c0abc0c;
P_0c0abc0c: /* original 430b, guest PC 0x0c0abc0c */
if(!s->budget--) { s->failed_pc=0x0c0abc0cu; return 0; }
target=r[3];
r[16]=code_base|0x0c0abc10u;
r[6]+=0x00000048u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0abc10u) { target=s->pc; goto dispatch; }
goto P_0c0abc10;
P_0c0abc0e: /* original 7648, guest PC 0x0c0abc0e */
if(!s->budget--) { s->failed_pc=0x0c0abc0eu; return 0; }
r[6]+=0x00000048u;
goto P_0c0abc10;
P_0c0abc10: /* original 62d2, guest PC 0x0c0abc10 */
if(!s->budget--) { s->failed_pc=0x0c0abc10u; return 0; }
tmp=read(ram,r[13],4);
r[2]=tmp;
goto P_0c0abc12;
P_0c0abc12: /* original 6323, guest PC 0x0c0abc12 */
if(!s->budget--) { s->failed_pc=0x0c0abc12u; return 0; }
r[3]=r[2];
goto P_0c0abc14;
P_0c0abc14: /* original 2e22, guest PC 0x0c0abc14 */
if(!s->budget--) { s->failed_pc=0x0c0abc14u; return 0; }
write(ram,r[14],r[2],4);
goto P_0c0abc16;
P_0c0abc16: /* original d442, guest PC 0x0c0abc16 */
if(!s->budget--) { s->failed_pc=0x0c0abc16u; return 0; }
r[4]=read(ram,0x0c0abd20u,4);
goto P_0c0abc18;
P_0c0abc18: /* original 2348, guest PC 0x0c0abc18 */
if(!s->budget--) { s->failed_pc=0x0c0abc18u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[4])==0)!=0);
goto P_0c0abc1a;
P_0c0abc1a: /* original 8b07, guest PC 0x0c0abc1a */
if(!s->budget--) { s->failed_pc=0x0c0abc1au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0abc2c; }
goto P_0c0abc1c;
P_0c0abc1c: /* original 9075, guest PC 0x0c0abc1c */
if(!s->budget--) { s->failed_pc=0x0c0abc1cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0abd0au,2);
goto P_0c0abc1e;
P_0c0abc1e: /* original f3e6, guest PC 0x0c0abc1e */
if(!s->budget--) { s->failed_pc=0x0c0abc1eu; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c0abc20;
P_0c0abc20: /* original e024, guest PC 0x0c0abc20 */
if(!s->budget--) { s->failed_pc=0x0c0abc20u; return 0; }
r[0]=0x00000024u;
goto P_0c0abc22;
P_0c0abc22: /* original fe37, guest PC 0x0c0abc22 */
if(!s->budget--) { s->failed_pc=0x0c0abc22u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c0abc24;
P_0c0abc24: /* original 9072, guest PC 0x0c0abc24 */
if(!s->budget--) { s->failed_pc=0x0c0abc24u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0abd0cu,2);
goto P_0c0abc26;
P_0c0abc26: /* original f3e6, guest PC 0x0c0abc26 */
if(!s->budget--) { s->failed_pc=0x0c0abc26u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c0abc28;
P_0c0abc28: /* original e02c, guest PC 0x0c0abc28 */
if(!s->budget--) { s->failed_pc=0x0c0abc28u; return 0; }
r[0]=0x0000002cu;
goto P_0c0abc2a;
P_0c0abc2a: /* original fe37, guest PC 0x0c0abc2a */
if(!s->budget--) { s->failed_pc=0x0c0abc2au; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c0abc2c;
P_0c0abc2c: /* original 63d2, guest PC 0x0c0abc2c */
if(!s->budget--) { s->failed_pc=0x0c0abc2cu; return 0; }
tmp=read(ram,r[13],4);
r[3]=tmp;
goto P_0c0abc2e;
P_0c0abc2e: /* original 2438, guest PC 0x0c0abc2e */
if(!s->budget--) { s->failed_pc=0x0c0abc2eu; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[3])==0)!=0);
goto P_0c0abc30;
P_0c0abc30: /* original 892d, guest PC 0x0c0abc30 */
if(!s->budget--) { s->failed_pc=0x0c0abc30u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0abc8e; }
goto P_0c0abc32;
P_0c0abc32: /* original e03e, guest PC 0x0c0abc32 */
if(!s->budget--) { s->failed_pc=0x0c0abc32u; return 0; }
r[0]=0x0000003eu;
goto P_0c0abc34;
P_0c0abc34: /* original 01ed, guest PC 0x0c0abc34 */
if(!s->budget--) { s->failed_pc=0x0c0abc34u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0abc36;
P_0c0abc36: /* original 906a, guest PC 0x0c0abc36 */
if(!s->budget--) { s->failed_pc=0x0c0abc36u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0abd0eu,2);
goto P_0c0abc38;
P_0c0abc38: /* original 03ed, guest PC 0x0c0abc38 */
if(!s->budget--) { s->failed_pc=0x0c0abc38u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0abc3a;
P_0c0abc3a: /* original 3136, guest PC 0x0c0abc3a */
if(!s->budget--) { s->failed_pc=0x0c0abc3au; return 0; }
r[17]=(r[17]&~1u)|((r[1]>r[3])!=0);
goto P_0c0abc3c;
P_0c0abc3c: /* original 8906, guest PC 0x0c0abc3c */
if(!s->budget--) { s->failed_pc=0x0c0abc3cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0abc4c; }
goto P_0c0abc3e;
P_0c0abc3e: /* original e03e, guest PC 0x0c0abc3e */
if(!s->budget--) { s->failed_pc=0x0c0abc3eu; return 0; }
r[0]=0x0000003eu;
goto P_0c0abc40;
P_0c0abc40: /* original 03ed, guest PC 0x0c0abc40 */
if(!s->budget--) { s->failed_pc=0x0c0abc40u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0abc42;
P_0c0abc42: /* original 9065, guest PC 0x0c0abc42 */
if(!s->budget--) { s->failed_pc=0x0c0abc42u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0abd10u,2);
goto P_0c0abc44;
P_0c0abc44: /* original 633d, guest PC 0x0c0abc44 */
if(!s->budget--) { s->failed_pc=0x0c0abc44u; return 0; }
r[3]=r[3]&65535u;
goto P_0c0abc46;
P_0c0abc46: /* original 02ed, guest PC 0x0c0abc46 */
if(!s->budget--) { s->failed_pc=0x0c0abc46u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0abc48;
P_0c0abc48: /* original 3320, guest PC 0x0c0abc48 */
if(!s->budget--) { s->failed_pc=0x0c0abc48u; return 0; }
r[17]=(r[17]&~1u)|((r[3]==r[2])!=0);
goto P_0c0abc4a;
P_0c0abc4a: /* original 8b20, guest PC 0x0c0abc4a */
if(!s->budget--) { s->failed_pc=0x0c0abc4au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0abc8e; }
goto P_0c0abc4c;
P_0c0abc4c: /* original e206, guest PC 0x0c0abc4c */
if(!s->budget--) { s->failed_pc=0x0c0abc4cu; return 0; }
r[2]=0x00000006u;
goto P_0c0abc4e;
P_0c0abc4e: /* original 6323, guest PC 0x0c0abc4e */
if(!s->budget--) { s->failed_pc=0x0c0abc4eu; return 0; }
r[3]=r[2];
goto P_0c0abc50;
P_0c0abc50: /* original e062, guest PC 0x0c0abc50 */
if(!s->budget--) { s->failed_pc=0x0c0abc50u; return 0; }
r[0]=0x00000062u;
goto P_0c0abc52;
P_0c0abc52: /* original 1d22, guest PC 0x0c0abc52 */
if(!s->budget--) { s->failed_pc=0x0c0abc52u; return 0; }
write(ram,r[13]+8,r[2],4);
goto P_0c0abc54;
P_0c0abc54: /* original 0e34, guest PC 0x0c0abc54 */
if(!s->budget--) { s->failed_pc=0x0c0abc54u; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c0abc56;
P_0c0abc56: /* original 905c, guest PC 0x0c0abc56 */
if(!s->budget--) { s->failed_pc=0x0c0abc56u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0abd12u,2);
goto P_0c0abc58;
P_0c0abc58: /* original 00ec, guest PC 0x0c0abc58 */
if(!s->budget--) { s->failed_pc=0x0c0abc58u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0abc5a;
P_0c0abc5a: /* original 600c, guest PC 0x0c0abc5a */
if(!s->budget--) { s->failed_pc=0x0c0abc5au; return 0; }
r[0]=r[0]&255u;
goto P_0c0abc5c;
P_0c0abc5c: /* original c801, guest PC 0x0c0abc5c */
if(!s->budget--) { s->failed_pc=0x0c0abc5cu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&1u)==0)!=0);
goto P_0c0abc5e;
P_0c0abc5e: /* original 8b02, guest PC 0x0c0abc5e */
if(!s->budget--) { s->failed_pc=0x0c0abc5eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0abc66; }
goto P_0c0abc60;
P_0c0abc60: /* original 9c58, guest PC 0x0c0abc60 */
if(!s->budget--) { s->failed_pc=0x0c0abc60u; return 0; }
r[12]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0abd14u,2);
goto P_0c0abc62;
P_0c0abc62: /* original a001, guest PC 0x0c0abc62 */
if(!s->budget--) { s->failed_pc=0x0c0abc62u; return 0; }
goto P_0c0abc68;
P_0c0abc64: /* original 0009, guest PC 0x0c0abc64 */
if(!s->budget--) { s->failed_pc=0x0c0abc64u; return 0; }
goto P_0c0abc66;
P_0c0abc66: /* original 9c56, guest PC 0x0c0abc66 */
if(!s->budget--) { s->failed_pc=0x0c0abc66u; return 0; }
r[12]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0abd16u,2);
goto P_0c0abc68;
P_0c0abc68: /* original d22e, guest PC 0x0c0abc68 */
if(!s->budget--) { s->failed_pc=0x0c0abc68u; return 0; }
r[2]=read(ram,0x0c0abd24u,4);
goto P_0c0abc6a;
P_0c0abc6a: /* original 65c3, guest PC 0x0c0abc6a */
if(!s->budget--) { s->failed_pc=0x0c0abc6au; return 0; }
r[5]=r[12];
goto P_0c0abc6c;
P_0c0abc6c: /* original 420b, guest PC 0x0c0abc6c */
if(!s->budget--) { s->failed_pc=0x0c0abc6cu; return 0; }
target=r[2];
r[16]=code_base|0x0c0abc70u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0abc70u) { target=s->pc; goto dispatch; }
goto P_0c0abc70;
P_0c0abc6e: /* original 64e3, guest PC 0x0c0abc6e */
if(!s->budget--) { s->failed_pc=0x0c0abc6eu; return 0; }
r[4]=r[14];
goto P_0c0abc70;
P_0c0abc70: /* original d32a, guest PC 0x0c0abc70 */
if(!s->budget--) { s->failed_pc=0x0c0abc70u; return 0; }
r[3]=read(ram,0x0c0abd1cu,4);
goto P_0c0abc72;
P_0c0abc72: /* original 66e3, guest PC 0x0c0abc72 */
if(!s->budget--) { s->failed_pc=0x0c0abc72u; return 0; }
r[6]=r[14];
goto P_0c0abc74;
P_0c0abc74: /* original 65d3, guest PC 0x0c0abc74 */
if(!s->budget--) { s->failed_pc=0x0c0abc74u; return 0; }
r[5]=r[13];
goto P_0c0abc76;
P_0c0abc76: /* original 7648, guest PC 0x0c0abc76 */
if(!s->budget--) { s->failed_pc=0x0c0abc76u; return 0; }
r[6]+=0x00000048u;
goto P_0c0abc78;
P_0c0abc78: /* original 430b, guest PC 0x0c0abc78 */
if(!s->budget--) { s->failed_pc=0x0c0abc78u; return 0; }
target=r[3];
r[16]=code_base|0x0c0abc7cu;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0abc7cu) { target=s->pc; goto dispatch; }
goto P_0c0abc7c;
P_0c0abc7a: /* original 64e3, guest PC 0x0c0abc7a */
if(!s->budget--) { s->failed_pc=0x0c0abc7au; return 0; }
r[4]=r[14];
goto P_0c0abc7c;
P_0c0abc7c: /* original 4f26, guest PC 0x0c0abc7c */
if(!s->budget--) { s->failed_pc=0x0c0abc7cu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0abc7e;
P_0c0abc7e: /* original 65d3, guest PC 0x0c0abc7e */
if(!s->budget--) { s->failed_pc=0x0c0abc7eu; return 0; }
r[5]=r[13];
goto P_0c0abc80;
P_0c0abc80: /* original 62d2, guest PC 0x0c0abc80 */
if(!s->budget--) { s->failed_pc=0x0c0abc80u; return 0; }
tmp=read(ram,r[13],4);
r[2]=tmp;
goto P_0c0abc82;
P_0c0abc82: /* original 64e3, guest PC 0x0c0abc82 */
if(!s->budget--) { s->failed_pc=0x0c0abc82u; return 0; }
r[4]=r[14];
goto P_0c0abc84;
P_0c0abc84: /* original 2e22, guest PC 0x0c0abc84 */
if(!s->budget--) { s->failed_pc=0x0c0abc84u; return 0; }
write(ram,r[14],r[2],4);
goto P_0c0abc86;
P_0c0abc86: /* original 6cf6, guest PC 0x0c0abc86 */
if(!s->budget--) { s->failed_pc=0x0c0abc86u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0abc88;
P_0c0abc88: /* original 6df6, guest PC 0x0c0abc88 */
if(!s->budget--) { s->failed_pc=0x0c0abc88u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0abc8a;
P_0c0abc8a: /* original a005, guest PC 0x0c0abc8a */
if(!s->budget--) { s->failed_pc=0x0c0abc8au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0abc98;
P_0c0abc8c: /* original 6ef6, guest PC 0x0c0abc8c */
if(!s->budget--) { s->failed_pc=0x0c0abc8cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0abc8e;
P_0c0abc8e: /* original 4f26, guest PC 0x0c0abc8e */
if(!s->budget--) { s->failed_pc=0x0c0abc8eu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0abc90;
P_0c0abc90: /* original 6cf6, guest PC 0x0c0abc90 */
if(!s->budget--) { s->failed_pc=0x0c0abc90u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0abc92;
P_0c0abc92: /* original 6df6, guest PC 0x0c0abc92 */
if(!s->budget--) { s->failed_pc=0x0c0abc92u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0abc94;
P_0c0abc94: /* original 000b, guest PC 0x0c0abc94 */
if(!s->budget--) { s->failed_pc=0x0c0abc94u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0abc96: /* original 6ef6, guest PC 0x0c0abc96 */
if(!s->budget--) { s->failed_pc=0x0c0abc96u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0abc98;
P_0c0abc98: /* original d523, guest PC 0x0c0abc98 */
if(!s->budget--) { s->failed_pc=0x0c0abc98u; return 0; }
r[5]=read(ram,0x0c0abd28u,4);
goto P_0c0abc9a;
P_0c0abc9a: /* original e028, guest PC 0x0c0abc9a */
if(!s->budget--) { s->failed_pc=0x0c0abc9au; return 0; }
r[0]=0x00000028u;
goto P_0c0abc9c;
P_0c0abc9c: /* original f358, guest PC 0x0c0abc9c */
if(!s->budget--) { s->failed_pc=0x0c0abc9cu; return 0; }
vf3_matrix_load(s,ram,3,r[5]);
goto P_0c0abc9e;
P_0c0abc9e: /* original 000b, guest PC 0x0c0abc9e */
if(!s->budget--) { s->failed_pc=0x0c0abc9eu; return 0; }
target=r[16];
vf3_matrix_store(s,ram,3,r[4]+r[0]);
s->pc=target; return ram->oob==0;
P_0c0abca0: /* original f437, guest PC 0x0c0abca0 */
if(!s->budget--) { s->failed_pc=0x0c0abca0u; return 0; }
vf3_matrix_store(s,ram,3,r[4]+r[0]);
if(!vf3_matrix_family(0x0c0abca2u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0abca2u; return 0; } return 1;
P_0c0abea8: /* original 2fe6, guest PC 0x0c0abea8 */
if(!s->budget--) { s->failed_pc=0x0c0abea8u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0abeaa;
P_0c0abeaa: /* original 6e43, guest PC 0x0c0abeaa */
if(!s->budget--) { s->failed_pc=0x0c0abeaau; return 0; }
r[14]=r[4];
goto P_0c0abeac;
P_0c0abeac: /* original 2fd6, guest PC 0x0c0abeac */
if(!s->budget--) { s->failed_pc=0x0c0abeacu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0abeae;
P_0c0abeae: /* original 6d53, guest PC 0x0c0abeae */
if(!s->budget--) { s->failed_pc=0x0c0abeaeu; return 0; }
r[13]=r[5];
goto P_0c0abeb0;
P_0c0abeb0: /* original 2fc6, guest PC 0x0c0abeb0 */
if(!s->budget--) { s->failed_pc=0x0c0abeb0u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0abeb2;
P_0c0abeb2: /* original e028, guest PC 0x0c0abeb2 */
if(!s->budget--) { s->failed_pc=0x0c0abeb2u; return 0; }
r[0]=0x00000028u;
goto P_0c0abeb4;
P_0c0abeb4: /* original d322, guest PC 0x0c0abeb4 */
if(!s->budget--) { s->failed_pc=0x0c0abeb4u; return 0; }
r[3]=read(ram,0x0c0abf40u,4);
goto P_0c0abeb6;
P_0c0abeb6: /* original 62e2, guest PC 0x0c0abeb6 */
if(!s->budget--) { s->failed_pc=0x0c0abeb6u; return 0; }
tmp=read(ram,r[14],4);
r[2]=tmp;
goto P_0c0abeb8;
P_0c0abeb8: /* original 4f22, guest PC 0x0c0abeb8 */
if(!s->budget--) { s->failed_pc=0x0c0abeb8u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0abeba;
P_0c0abeba: /* original 223b, guest PC 0x0c0abeba */
if(!s->budget--) { s->failed_pc=0x0c0abebau; return 0; }
r[2]|=r[3];
goto P_0c0abebc;
P_0c0abebc: /* original 2e22, guest PC 0x0c0abebc */
if(!s->budget--) { s->failed_pc=0x0c0abebcu; return 0; }
write(ram,r[14],r[2],4);
goto P_0c0abebe;
P_0c0abebe: /* original f38d, guest PC 0x0c0abebe */
if(!s->budget--) { s->failed_pc=0x0c0abebeu; return 0; }
fr[3]=0;
goto P_0c0abec0;
P_0c0abec0: /* original 7ffc, guest PC 0x0c0abec0 */
if(!s->budget--) { s->failed_pc=0x0c0abec0u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c0abec2;
P_0c0abec2: /* original fe37, guest PC 0x0c0abec2 */
if(!s->budget--) { s->failed_pc=0x0c0abec2u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c0abec4;
P_0c0abec4: /* original 64d2, guest PC 0x0c0abec4 */
if(!s->budget--) { s->failed_pc=0x0c0abec4u; return 0; }
tmp=read(ram,r[13],4);
r[4]=tmp;
goto P_0c0abec6;
P_0c0abec6: /* original 624d, guest PC 0x0c0abec6 */
if(!s->budget--) { s->failed_pc=0x0c0abec6u; return 0; }
r[2]=r[4]&65535u;
goto P_0c0abec8;
P_0c0abec8: /* original 4429, guest PC 0x0c0abec8 */
if(!s->budget--) { s->failed_pc=0x0c0abec8u; return 0; }
r[4]>>=16;
goto P_0c0abeca;
P_0c0abeca: /* original 2f22, guest PC 0x0c0abeca */
if(!s->budget--) { s->failed_pc=0x0c0abecau; return 0; }
write(ram,r[15],r[2],4);
goto P_0c0abecc;
P_0c0abecc: /* original 6c4c, guest PC 0x0c0abecc */
if(!s->budget--) { s->failed_pc=0x0c0abeccu; return 0; }
r[12]=r[4]&255u;
goto P_0c0abece;
P_0c0abece: /* original 60c3, guest PC 0x0c0abece */
if(!s->budget--) { s->failed_pc=0x0c0abeceu; return 0; }
r[0]=r[12];
goto P_0c0abed0;
P_0c0abed0: /* original 8801, guest PC 0x0c0abed0 */
if(!s->budget--) { s->failed_pc=0x0c0abed0u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c0abed2;
P_0c0abed2: /* original 8b07, guest PC 0x0c0abed2 */
if(!s->budget--) { s->failed_pc=0x0c0abed2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0abee4; }
goto P_0c0abed4;
P_0c0abed4: /* original 7f04, guest PC 0x0c0abed4 */
if(!s->budget--) { s->failed_pc=0x0c0abed4u; return 0; }
r[15]+=0x00000004u;
goto P_0c0abed6;
P_0c0abed6: /* original 65d3, guest PC 0x0c0abed6 */
if(!s->budget--) { s->failed_pc=0x0c0abed6u; return 0; }
r[5]=r[13];
goto P_0c0abed8;
P_0c0abed8: /* original 4f26, guest PC 0x0c0abed8 */
if(!s->budget--) { s->failed_pc=0x0c0abed8u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0abeda;
P_0c0abeda: /* original 64e3, guest PC 0x0c0abeda */
if(!s->budget--) { s->failed_pc=0x0c0abedau; return 0; }
r[4]=r[14];
goto P_0c0abedc;
P_0c0abedc: /* original 6cf6, guest PC 0x0c0abedc */
if(!s->budget--) { s->failed_pc=0x0c0abedcu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0abede;
P_0c0abede: /* original 6df6, guest PC 0x0c0abede */
if(!s->budget--) { s->failed_pc=0x0c0abedeu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0abee0;
P_0c0abee0: /* original a154, guest PC 0x0c0abee0 */
if(!s->budget--) { s->failed_pc=0x0c0abee0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0ac18cu,s,ram);
P_0c0abee2: /* original 6ef6, guest PC 0x0c0abee2 */
if(!s->budget--) { s->failed_pc=0x0c0abee2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0abee4;
P_0c0abee4: /* original d317, guest PC 0x0c0abee4 */
if(!s->budget--) { s->failed_pc=0x0c0abee4u; return 0; }
r[3]=read(ram,0x0c0abf44u,4);
goto P_0c0abee6;
P_0c0abee6: /* original 65f2, guest PC 0x0c0abee6 */
if(!s->budget--) { s->failed_pc=0x0c0abee6u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0abee8;
P_0c0abee8: /* original 430b, guest PC 0x0c0abee8 */
if(!s->budget--) { s->failed_pc=0x0c0abee8u; return 0; }
target=r[3];
r[16]=code_base|0x0c0abeecu;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0abeecu) { target=s->pc; goto dispatch; }
goto P_0c0abeec;
P_0c0abeea: /* original 64e3, guest PC 0x0c0abeea */
if(!s->budget--) { s->failed_pc=0x0c0abeeau; return 0; }
r[4]=r[14];
goto P_0c0abeec;
P_0c0abeec: /* original 60c3, guest PC 0x0c0abeec */
if(!s->budget--) { s->failed_pc=0x0c0abeecu; return 0; }
r[0]=r[12];
goto P_0c0abeee;
P_0c0abeee: /* original 8802, guest PC 0x0c0abeee */
if(!s->budget--) { s->failed_pc=0x0c0abeeeu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c0abef0;
P_0c0abef0: /* original 8b07, guest PC 0x0c0abef0 */
if(!s->budget--) { s->failed_pc=0x0c0abef0u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0abf02; }
goto P_0c0abef2;
P_0c0abef2: /* original 7f04, guest PC 0x0c0abef2 */
if(!s->budget--) { s->failed_pc=0x0c0abef2u; return 0; }
r[15]+=0x00000004u;
goto P_0c0abef4;
P_0c0abef4: /* original 65d3, guest PC 0x0c0abef4 */
if(!s->budget--) { s->failed_pc=0x0c0abef4u; return 0; }
r[5]=r[13];
goto P_0c0abef6;
P_0c0abef6: /* original 4f26, guest PC 0x0c0abef6 */
if(!s->budget--) { s->failed_pc=0x0c0abef6u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0abef8;
P_0c0abef8: /* original 64e3, guest PC 0x0c0abef8 */
if(!s->budget--) { s->failed_pc=0x0c0abef8u; return 0; }
r[4]=r[14];
goto P_0c0abefa;
P_0c0abefa: /* original 6cf6, guest PC 0x0c0abefa */
if(!s->budget--) { s->failed_pc=0x0c0abefau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0abefc;
P_0c0abefc: /* original 6df6, guest PC 0x0c0abefc */
if(!s->budget--) { s->failed_pc=0x0c0abefcu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0abefe;
P_0c0abefe: /* original a101, guest PC 0x0c0abefe */
if(!s->budget--) { s->failed_pc=0x0c0abefeu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0ac104u,s,ram);
P_0c0abf00: /* original 6ef6, guest PC 0x0c0abf00 */
if(!s->budget--) { s->failed_pc=0x0c0abf00u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0abf02;
P_0c0abf02: /* original 7f04, guest PC 0x0c0abf02 */
if(!s->budget--) { s->failed_pc=0x0c0abf02u; return 0; }
r[15]+=0x00000004u;
goto P_0c0abf04;
P_0c0abf04: /* original 52d1, guest PC 0x0c0abf04 */
if(!s->budget--) { s->failed_pc=0x0c0abf04u; return 0; }
r[2]=read(ram,r[13]+4,4);
goto P_0c0abf06;
P_0c0abf06: /* original 4f26, guest PC 0x0c0abf06 */
if(!s->budget--) { s->failed_pc=0x0c0abf06u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0abf08;
P_0c0abf08: /* original 7201, guest PC 0x0c0abf08 */
if(!s->budget--) { s->failed_pc=0x0c0abf08u; return 0; }
r[2]+=0x00000001u;
goto P_0c0abf0a;
P_0c0abf0a: /* original 65d3, guest PC 0x0c0abf0a */
if(!s->budget--) { s->failed_pc=0x0c0abf0au; return 0; }
r[5]=r[13];
goto P_0c0abf0c;
P_0c0abf0c: /* original 1d21, guest PC 0x0c0abf0c */
if(!s->budget--) { s->failed_pc=0x0c0abf0cu; return 0; }
write(ram,r[13]+4,r[2],4);
goto P_0c0abf0e;
P_0c0abf0e: /* original 6323, guest PC 0x0c0abf0e */
if(!s->budget--) { s->failed_pc=0x0c0abf0eu; return 0; }
r[3]=r[2];
goto P_0c0abf10;
P_0c0abf10: /* original e062, guest PC 0x0c0abf10 */
if(!s->budget--) { s->failed_pc=0x0c0abf10u; return 0; }
r[0]=0x00000062u;
goto P_0c0abf12;
P_0c0abf12: /* original 64e3, guest PC 0x0c0abf12 */
if(!s->budget--) { s->failed_pc=0x0c0abf12u; return 0; }
r[4]=r[14];
goto P_0c0abf14;
P_0c0abf14: /* original 0e34, guest PC 0x0c0abf14 */
if(!s->budget--) { s->failed_pc=0x0c0abf14u; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c0abf16;
P_0c0abf16: /* original 6cf6, guest PC 0x0c0abf16 */
if(!s->budget--) { s->failed_pc=0x0c0abf16u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0abf18;
P_0c0abf18: /* original 6df6, guest PC 0x0c0abf18 */
if(!s->budget--) { s->failed_pc=0x0c0abf18u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0abf1a;
P_0c0abf1a: /* original a015, guest PC 0x0c0abf1a */
if(!s->budget--) { s->failed_pc=0x0c0abf1au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0abf48;
P_0c0abf1c: /* original 6ef6, guest PC 0x0c0abf1c */
if(!s->budget--) { s->failed_pc=0x0c0abf1cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0abf1eu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0abf1eu; return 0; } return 1;
P_0c0abf48: /* original 2fe6, guest PC 0x0c0abf48 */
if(!s->budget--) { s->failed_pc=0x0c0abf48u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0abf4a;
P_0c0abf4a: /* original 6e43, guest PC 0x0c0abf4a */
if(!s->budget--) { s->failed_pc=0x0c0abf4au; return 0; }
r[14]=r[4];
goto P_0c0abf4c;
P_0c0abf4c: /* original e03e, guest PC 0x0c0abf4c */
if(!s->budget--) { s->failed_pc=0x0c0abf4cu; return 0; }
r[0]=0x0000003eu;
goto P_0c0abf4e;
P_0c0abf4e: /* original 2fd6, guest PC 0x0c0abf4e */
if(!s->budget--) { s->failed_pc=0x0c0abf4eu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0abf50;
P_0c0abf50: /* original 03ed, guest PC 0x0c0abf50 */
if(!s->budget--) { s->failed_pc=0x0c0abf50u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0abf52;
P_0c0abf52: /* original 9080, guest PC 0x0c0abf52 */
if(!s->budget--) { s->failed_pc=0x0c0abf52u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ac056u,2);
goto P_0c0abf54;
P_0c0abf54: /* original 4f22, guest PC 0x0c0abf54 */
if(!s->budget--) { s->failed_pc=0x0c0abf54u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0abf56;
P_0c0abf56: /* original 02ed, guest PC 0x0c0abf56 */
if(!s->budget--) { s->failed_pc=0x0c0abf56u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0abf58;
P_0c0abf58: /* original 3322, guest PC 0x0c0abf58 */
if(!s->budget--) { s->failed_pc=0x0c0abf58u; return 0; }
r[17]=(r[17]&~1u)|((r[3]>=r[2])!=0);
goto P_0c0abf5a;
P_0c0abf5a: /* original 8f1e, guest PC 0x0c0abf5a */
if(!s->budget--) { s->failed_pc=0x0c0abf5au; return 0; }
cond=r[17]&1u;
r[13]=r[5];
if(!cond) { goto P_0c0abf9a; }
goto P_0c0abf5e;
P_0c0abf5c: /* original 6d53, guest PC 0x0c0abf5c */
if(!s->budget--) { s->failed_pc=0x0c0abf5cu; return 0; }
r[13]=r[5];
goto P_0c0abf5e;
P_0c0abf5e: /* original 907b, guest PC 0x0c0abf5e */
if(!s->budget--) { s->failed_pc=0x0c0abf5eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ac058u,2);
goto P_0c0abf60;
P_0c0abf60: /* original 66e3, guest PC 0x0c0abf60 */
if(!s->budget--) { s->failed_pc=0x0c0abf60u; return 0; }
r[6]=r[14];
goto P_0c0abf62;
P_0c0abf62: /* original 65e3, guest PC 0x0c0abf62 */
if(!s->budget--) { s->failed_pc=0x0c0abf62u; return 0; }
r[5]=r[14];
goto P_0c0abf64;
P_0c0abf64: /* original 7648, guest PC 0x0c0abf64 */
if(!s->budget--) { s->failed_pc=0x0c0abf64u; return 0; }
r[6]+=0x00000048u;
goto P_0c0abf66;
P_0c0abf66: /* original f3e6, guest PC 0x0c0abf66 */
if(!s->budget--) { s->failed_pc=0x0c0abf66u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c0abf68;
P_0c0abf68: /* original e024, guest PC 0x0c0abf68 */
if(!s->budget--) { s->failed_pc=0x0c0abf68u; return 0; }
r[0]=0x00000024u;
goto P_0c0abf6a;
P_0c0abf6a: /* original fe37, guest PC 0x0c0abf6a */
if(!s->budget--) { s->failed_pc=0x0c0abf6au; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c0abf6c;
P_0c0abf6c: /* original 9075, guest PC 0x0c0abf6c */
if(!s->budget--) { s->failed_pc=0x0c0abf6cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ac05au,2);
goto P_0c0abf6e;
P_0c0abf6e: /* original f3e6, guest PC 0x0c0abf6e */
if(!s->budget--) { s->failed_pc=0x0c0abf6eu; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c0abf70;
P_0c0abf70: /* original e028, guest PC 0x0c0abf70 */
if(!s->budget--) { s->failed_pc=0x0c0abf70u; return 0; }
r[0]=0x00000028u;
goto P_0c0abf72;
P_0c0abf72: /* original fe37, guest PC 0x0c0abf72 */
if(!s->budget--) { s->failed_pc=0x0c0abf72u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c0abf74;
P_0c0abf74: /* original 9072, guest PC 0x0c0abf74 */
if(!s->budget--) { s->failed_pc=0x0c0abf74u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ac05cu,2);
goto P_0c0abf76;
P_0c0abf76: /* original f3e6, guest PC 0x0c0abf76 */
if(!s->budget--) { s->failed_pc=0x0c0abf76u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c0abf78;
P_0c0abf78: /* original e02c, guest PC 0x0c0abf78 */
if(!s->budget--) { s->failed_pc=0x0c0abf78u; return 0; }
r[0]=0x0000002cu;
goto P_0c0abf7a;
P_0c0abf7a: /* original fe37, guest PC 0x0c0abf7a */
if(!s->budget--) { s->failed_pc=0x0c0abf7au; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c0abf7c;
P_0c0abf7c: /* original d339, guest PC 0x0c0abf7c */
if(!s->budget--) { s->failed_pc=0x0c0abf7cu; return 0; }
r[3]=read(ram,0x0c0ac064u,4);
goto P_0c0abf7e;
P_0c0abf7e: /* original 430b, guest PC 0x0c0abf7e */
if(!s->budget--) { s->failed_pc=0x0c0abf7eu; return 0; }
target=r[3];
r[16]=code_base|0x0c0abf82u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0abf82u) { target=s->pc; goto dispatch; }
goto P_0c0abf82;
P_0c0abf80: /* original 64e3, guest PC 0x0c0abf80 */
if(!s->budget--) { s->failed_pc=0x0c0abf80u; return 0; }
r[4]=r[14];
goto P_0c0abf82;
P_0c0abf82: /* original 52d1, guest PC 0x0c0abf82 */
if(!s->budget--) { s->failed_pc=0x0c0abf82u; return 0; }
r[2]=read(ram,r[13]+4,4);
goto P_0c0abf84;
P_0c0abf84: /* original 65d3, guest PC 0x0c0abf84 */
if(!s->budget--) { s->failed_pc=0x0c0abf84u; return 0; }
r[5]=r[13];
goto P_0c0abf86;
P_0c0abf86: /* original 4f26, guest PC 0x0c0abf86 */
if(!s->budget--) { s->failed_pc=0x0c0abf86u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0abf88;
P_0c0abf88: /* original 7201, guest PC 0x0c0abf88 */
if(!s->budget--) { s->failed_pc=0x0c0abf88u; return 0; }
r[2]+=0x00000001u;
goto P_0c0abf8a;
P_0c0abf8a: /* original 64e3, guest PC 0x0c0abf8a */
if(!s->budget--) { s->failed_pc=0x0c0abf8au; return 0; }
r[4]=r[14];
goto P_0c0abf8c;
P_0c0abf8c: /* original 1d21, guest PC 0x0c0abf8c */
if(!s->budget--) { s->failed_pc=0x0c0abf8cu; return 0; }
write(ram,r[13]+4,r[2],4);
goto P_0c0abf8e;
P_0c0abf8e: /* original e062, guest PC 0x0c0abf8e */
if(!s->budget--) { s->failed_pc=0x0c0abf8eu; return 0; }
r[0]=0x00000062u;
goto P_0c0abf90;
P_0c0abf90: /* original 6323, guest PC 0x0c0abf90 */
if(!s->budget--) { s->failed_pc=0x0c0abf90u; return 0; }
r[3]=r[2];
goto P_0c0abf92;
P_0c0abf92: /* original 0e34, guest PC 0x0c0abf92 */
if(!s->budget--) { s->failed_pc=0x0c0abf92u; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c0abf94;
P_0c0abf94: /* original 6df6, guest PC 0x0c0abf94 */
if(!s->budget--) { s->failed_pc=0x0c0abf94u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0abf96;
P_0c0abf96: /* original a06f, guest PC 0x0c0abf96 */
if(!s->budget--) { s->failed_pc=0x0c0abf96u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0ac078;
P_0c0abf98: /* original 6ef6, guest PC 0x0c0abf98 */
if(!s->budget--) { s->failed_pc=0x0c0abf98u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0abf9a;
P_0c0abf9a: /* original 4f26, guest PC 0x0c0abf9a */
if(!s->budget--) { s->failed_pc=0x0c0abf9au; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0abf9c;
P_0c0abf9c: /* original 6df6, guest PC 0x0c0abf9c */
if(!s->budget--) { s->failed_pc=0x0c0abf9cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0abf9e;
P_0c0abf9e: /* original 000b, guest PC 0x0c0abf9e */
if(!s->budget--) { s->failed_pc=0x0c0abf9eu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0abfa0: /* original 6ef6, guest PC 0x0c0abfa0 */
if(!s->budget--) { s->failed_pc=0x0c0abfa0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0abfa2u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0abfa2u; return 0; } return 1;
P_0c0ac078: /* original 2fe6, guest PC 0x0c0ac078 */
if(!s->budget--) { s->failed_pc=0x0c0ac078u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0ac07a;
P_0c0ac07a: /* original 6e43, guest PC 0x0c0ac07a */
if(!s->budget--) { s->failed_pc=0x0c0ac07au; return 0; }
r[14]=r[4];
goto P_0c0ac07c;
P_0c0ac07c: /* original 2fd6, guest PC 0x0c0ac07c */
if(!s->budget--) { s->failed_pc=0x0c0ac07cu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0ac07e;
P_0c0ac07e: /* original 9071, guest PC 0x0c0ac07e */
if(!s->budget--) { s->failed_pc=0x0c0ac07eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ac164u,2);
goto P_0c0ac080;
P_0c0ac080: /* original 4f22, guest PC 0x0c0ac080 */
if(!s->budget--) { s->failed_pc=0x0c0ac080u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0ac082;
P_0c0ac082: /* original 00ec, guest PC 0x0c0ac082 */
if(!s->budget--) { s->failed_pc=0x0c0ac082u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0ac084;
P_0c0ac084: /* original 600c, guest PC 0x0c0ac084 */
if(!s->budget--) { s->failed_pc=0x0c0ac084u; return 0; }
r[0]=r[0]&255u;
goto P_0c0ac086;
P_0c0ac086: /* original c840, guest PC 0x0c0ac086 */
if(!s->budget--) { s->failed_pc=0x0c0ac086u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&64u)==0)!=0);
goto P_0c0ac088;
P_0c0ac088: /* original 8d16, guest PC 0x0c0ac088 */
if(!s->budget--) { s->failed_pc=0x0c0ac088u; return 0; }
cond=r[17]&1u;
r[13]=r[5];
if(cond) { goto P_0c0ac0b8; }
goto P_0c0ac08c;
P_0c0ac08a: /* original 6d53, guest PC 0x0c0ac08a */
if(!s->budget--) { s->failed_pc=0x0c0ac08au; return 0; }
r[13]=r[5];
goto P_0c0ac08c;
P_0c0ac08c: /* original 906c, guest PC 0x0c0ac08c */
if(!s->budget--) { s->failed_pc=0x0c0ac08cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ac168u,2);
goto P_0c0ac08e;
P_0c0ac08e: /* original 936a, guest PC 0x0c0ac08e */
if(!s->budget--) { s->failed_pc=0x0c0ac08eu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ac166u,2);
goto P_0c0ac090;
P_0c0ac090: /* original 02ee, guest PC 0x0c0ac090 */
if(!s->budget--) { s->failed_pc=0x0c0ac090u; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c0ac092;
P_0c0ac092: /* original 2238, guest PC 0x0c0ac092 */
if(!s->budget--) { s->failed_pc=0x0c0ac092u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c0ac094;
P_0c0ac094: /* original 8910, guest PC 0x0c0ac094 */
if(!s->budget--) { s->failed_pc=0x0c0ac094u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0ac0b8; }
goto P_0c0ac096;
P_0c0ac096: /* original c737, guest PC 0x0c0ac096 */
if(!s->budget--) { s->failed_pc=0x0c0ac096u; return 0; }
r[0]=code_base|0x000ac174u;
goto P_0c0ac098;
P_0c0ac098: /* original f408, guest PC 0x0c0ac098 */
if(!s->budget--) { s->failed_pc=0x0c0ac098u; return 0; }
vf3_matrix_load(s,ram,4,r[0]);
goto P_0c0ac09a;
P_0c0ac09a: /* original e024, guest PC 0x0c0ac09a */
if(!s->budget--) { s->failed_pc=0x0c0ac09au; return 0; }
r[0]=0x00000024u;
goto P_0c0ac09c;
P_0c0ac09c: /* original f3e6, guest PC 0x0c0ac09c */
if(!s->budget--) { s->failed_pc=0x0c0ac09cu; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c0ac09e;
P_0c0ac09e: /* original 9064, guest PC 0x0c0ac09e */
if(!s->budget--) { s->failed_pc=0x0c0ac09eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ac16au,2);
goto P_0c0ac0a0;
P_0c0ac0a0: /* original f04c, guest PC 0x0c0ac0a0 */
if(!s->budget--) { s->failed_pc=0x0c0ac0a0u; return 0; }
vf3_matrix_move(s,0,4);
goto P_0c0ac0a2;
P_0c0ac0a2: /* original f2e6, guest PC 0x0c0ac0a2 */
if(!s->budget--) { s->failed_pc=0x0c0ac0a2u; return 0; }
vf3_matrix_load(s,ram,2,r[14]+r[0]);
goto P_0c0ac0a4;
P_0c0ac0a4: /* original e024, guest PC 0x0c0ac0a4 */
if(!s->budget--) { s->failed_pc=0x0c0ac0a4u; return 0; }
r[0]=0x00000024u;
goto P_0c0ac0a6;
P_0c0ac0a6: /* original f32e, guest PC 0x0c0ac0a6 */
if(!s->budget--) { s->failed_pc=0x0c0ac0a6u; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[2],fr[3],r[18]);
goto P_0c0ac0a8;
P_0c0ac0a8: /* original fe37, guest PC 0x0c0ac0a8 */
if(!s->budget--) { s->failed_pc=0x0c0ac0a8u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c0ac0aa;
P_0c0ac0aa: /* original e02c, guest PC 0x0c0ac0aa */
if(!s->budget--) { s->failed_pc=0x0c0ac0aau; return 0; }
r[0]=0x0000002cu;
goto P_0c0ac0ac;
P_0c0ac0ac: /* original f3e6, guest PC 0x0c0ac0ac */
if(!s->budget--) { s->failed_pc=0x0c0ac0acu; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c0ac0ae;
P_0c0ac0ae: /* original 905d, guest PC 0x0c0ac0ae */
if(!s->budget--) { s->failed_pc=0x0c0ac0aeu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ac16cu,2);
goto P_0c0ac0b0;
P_0c0ac0b0: /* original f2e6, guest PC 0x0c0ac0b0 */
if(!s->budget--) { s->failed_pc=0x0c0ac0b0u; return 0; }
vf3_matrix_load(s,ram,2,r[14]+r[0]);
goto P_0c0ac0b2;
P_0c0ac0b2: /* original e02c, guest PC 0x0c0ac0b2 */
if(!s->budget--) { s->failed_pc=0x0c0ac0b2u; return 0; }
r[0]=0x0000002cu;
goto P_0c0ac0b4;
P_0c0ac0b4: /* original f32e, guest PC 0x0c0ac0b4 */
if(!s->budget--) { s->failed_pc=0x0c0ac0b4u; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[2],fr[3],r[18]);
goto P_0c0ac0b6;
P_0c0ac0b6: /* original fe37, guest PC 0x0c0ac0b6 */
if(!s->budget--) { s->failed_pc=0x0c0ac0b6u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c0ac0b8;
P_0c0ac0b8: /* original d32f, guest PC 0x0c0ac0b8 */
if(!s->budget--) { s->failed_pc=0x0c0ac0b8u; return 0; }
r[3]=read(ram,0x0c0ac178u,4);
goto P_0c0ac0ba;
P_0c0ac0ba: /* original 430b, guest PC 0x0c0ac0ba */
if(!s->budget--) { s->failed_pc=0x0c0ac0bau; return 0; }
target=r[3];
r[16]=code_base|0x0c0ac0beu;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ac0beu) { target=s->pc; goto dispatch; }
goto P_0c0ac0be;
P_0c0ac0bc: /* original 64e3, guest PC 0x0c0ac0bc */
if(!s->budget--) { s->failed_pc=0x0c0ac0bcu; return 0; }
r[4]=r[14];
goto P_0c0ac0be;
P_0c0ac0be: /* original 6403, guest PC 0x0c0ac0be */
if(!s->budget--) { s->failed_pc=0x0c0ac0beu; return 0; }
r[4]=r[0];
goto P_0c0ac0c0;
P_0c0ac0c0: /* original 2448, guest PC 0x0c0ac0c0 */
if(!s->budget--) { s->failed_pc=0x0c0ac0c0u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c0ac0c2;
P_0c0ac0c2: /* original 8d05, guest PC 0x0c0ac0c2 */
if(!s->budget--) { s->failed_pc=0x0c0ac0c2u; return 0; }
cond=r[17]&1u;
r[5]=r[13];
if(cond) { goto P_0c0ac0d0; }
goto P_0c0ac0c6;
P_0c0ac0c4: /* original 65d3, guest PC 0x0c0ac0c4 */
if(!s->budget--) { s->failed_pc=0x0c0ac0c4u; return 0; }
r[5]=r[13];
goto P_0c0ac0c6;
P_0c0ac0c6: /* original e205, guest PC 0x0c0ac0c6 */
if(!s->budget--) { s->failed_pc=0x0c0ac0c6u; return 0; }
r[2]=0x00000005u;
goto P_0c0ac0c8;
P_0c0ac0c8: /* original e062, guest PC 0x0c0ac0c8 */
if(!s->budget--) { s->failed_pc=0x0c0ac0c8u; return 0; }
r[0]=0x00000062u;
goto P_0c0ac0ca;
P_0c0ac0ca: /* original 6323, guest PC 0x0c0ac0ca */
if(!s->budget--) { s->failed_pc=0x0c0ac0cau; return 0; }
r[3]=r[2];
goto P_0c0ac0cc;
P_0c0ac0cc: /* original 1d21, guest PC 0x0c0ac0cc */
if(!s->budget--) { s->failed_pc=0x0c0ac0ccu; return 0; }
write(ram,r[13]+4,r[2],4);
goto P_0c0ac0ce;
P_0c0ac0ce: /* original 0e34, guest PC 0x0c0ac0ce */
if(!s->budget--) { s->failed_pc=0x0c0ac0ceu; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c0ac0d0;
P_0c0ac0d0: /* original 4f26, guest PC 0x0c0ac0d0 */
if(!s->budget--) { s->failed_pc=0x0c0ac0d0u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0ac0d2;
P_0c0ac0d2: /* original 64e3, guest PC 0x0c0ac0d2 */
if(!s->budget--) { s->failed_pc=0x0c0ac0d2u; return 0; }
r[4]=r[14];
goto P_0c0ac0d4;
P_0c0ac0d4: /* original 6df6, guest PC 0x0c0ac0d4 */
if(!s->budget--) { s->failed_pc=0x0c0ac0d4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0ac0d6;
P_0c0ac0d6: /* original a000, guest PC 0x0c0ac0d6 */
if(!s->budget--) { s->failed_pc=0x0c0ac0d6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0ac0da;
P_0c0ac0d8: /* original 6ef6, guest PC 0x0c0ac0d8 */
if(!s->budget--) { s->failed_pc=0x0c0ac0d8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0ac0da;
P_0c0ac0da: /* original 6242, guest PC 0x0c0ac0da */
if(!s->budget--) { s->failed_pc=0x0c0ac0dau; return 0; }
tmp=read(ram,r[4],4);
r[2]=tmp;
goto P_0c0ac0dc;
P_0c0ac0dc: /* original d327, guest PC 0x0c0ac0dc */
if(!s->budget--) { s->failed_pc=0x0c0ac0dcu; return 0; }
r[3]=read(ram,0x0c0ac17cu,4);
goto P_0c0ac0de;
P_0c0ac0de: /* original 2238, guest PC 0x0c0ac0de */
if(!s->budget--) { s->failed_pc=0x0c0ac0deu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c0ac0e0;
P_0c0ac0e0: /* original 8b0e, guest PC 0x0c0ac0e0 */
if(!s->budget--) { s->failed_pc=0x0c0ac0e0u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0ac100; }
goto P_0c0ac0e2;
P_0c0ac0e2: /* original 9044, guest PC 0x0c0ac0e2 */
if(!s->budget--) { s->failed_pc=0x0c0ac0e2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ac16eu,2);
goto P_0c0ac0e4;
P_0c0ac0e4: /* original e13e, guest PC 0x0c0ac0e4 */
if(!s->budget--) { s->failed_pc=0x0c0ac0e4u; return 0; }
r[1]=0x0000003eu;
goto P_0c0ac0e6;
P_0c0ac0e6: /* original 314c, guest PC 0x0c0ac0e6 */
if(!s->budget--) { s->failed_pc=0x0c0ac0e6u; return 0; }
r[1]+=r[4];
goto P_0c0ac0e8;
P_0c0ac0e8: /* original 004d, guest PC 0x0c0ac0e8 */
if(!s->budget--) { s->failed_pc=0x0c0ac0e8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c0ac0ea;
P_0c0ac0ea: /* original 2101, guest PC 0x0c0ac0ea */
if(!s->budget--) { s->failed_pc=0x0c0ac0eau; return 0; }
write(ram,r[1],r[0],2);
goto P_0c0ac0ec;
P_0c0ac0ec: /* original 903c, guest PC 0x0c0ac0ec */
if(!s->budget--) { s->failed_pc=0x0c0ac0ecu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ac168u,2);
goto P_0c0ac0ee;
P_0c0ac0ee: /* original d624, guest PC 0x0c0ac0ee */
if(!s->budget--) { s->failed_pc=0x0c0ac0eeu; return 0; }
r[6]=read(ram,0x0c0ac180u,4);
goto P_0c0ac0f0;
P_0c0ac0f0: /* original 034e, guest PC 0x0c0ac0f0 */
if(!s->budget--) { s->failed_pc=0x0c0ac0f0u; return 0; }
r[3]=read(ram,r[4]+r[0],4);
goto P_0c0ac0f2;
P_0c0ac0f2: /* original 2638, guest PC 0x0c0ac0f2 */
if(!s->budget--) { s->failed_pc=0x0c0ac0f2u; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[3])==0)!=0);
goto P_0c0ac0f4;
P_0c0ac0f4: /* original 8902, guest PC 0x0c0ac0f4 */
if(!s->budget--) { s->failed_pc=0x0c0ac0f4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0ac0fc; }
goto P_0c0ac0f6;
P_0c0ac0f6: /* original 903b, guest PC 0x0c0ac0f6 */
if(!s->budget--) { s->failed_pc=0x0c0ac0f6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ac170u,2);
goto P_0c0ac0f8;
P_0c0ac0f8: /* original e101, guest PC 0x0c0ac0f8 */
if(!s->budget--) { s->failed_pc=0x0c0ac0f8u; return 0; }
r[1]=0x00000001u;
goto P_0c0ac0fa;
P_0c0ac0fa: /* original 0414, guest PC 0x0c0ac0fa */
if(!s->budget--) { s->failed_pc=0x0c0ac0fau; return 0; }
write(ram,r[4]+r[0],r[1],1);
goto P_0c0ac0fc;
P_0c0ac0fc: /* original a020, guest PC 0x0c0ac0fc */
if(!s->budget--) { s->failed_pc=0x0c0ac0fcu; return 0; }
return vf3_matrix_family(0x0c0ac140u,s,ram);
P_0c0ac0fe: /* original 0009, guest PC 0x0c0ac0fe */
if(!s->budget--) { s->failed_pc=0x0c0ac0feu; return 0; }
goto P_0c0ac100;
P_0c0ac100: /* original 000b, guest PC 0x0c0ac100 */
if(!s->budget--) { s->failed_pc=0x0c0ac100u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c0ac102: /* original 0009, guest PC 0x0c0ac102 */
if(!s->budget--) { s->failed_pc=0x0c0ac102u; return 0; }
return vf3_matrix_family(0x0c0ac104u,s,ram);
unsupported: s->failed_pc=target; return 0;
}
