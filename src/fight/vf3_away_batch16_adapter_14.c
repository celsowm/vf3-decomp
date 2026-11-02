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
int vf3_away_batch16_adapter_14(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c08ef4cu: goto P_0c08ef4c;
case 0x0c08ef4eu: goto P_0c08ef4e;
case 0x0c08ef50u: goto P_0c08ef50;
case 0x0c08ef52u: goto P_0c08ef52;
case 0x0c08ef54u: goto P_0c08ef54;
case 0x0c08ef56u: goto P_0c08ef56;
case 0x0c08ef58u: goto P_0c08ef58;
case 0x0c08ef5au: goto P_0c08ef5a;
case 0x0c08ef5cu: goto P_0c08ef5c;
case 0x0c08ef5eu: goto P_0c08ef5e;
case 0x0c08ef60u: goto P_0c08ef60;
case 0x0c08ef62u: goto P_0c08ef62;
case 0x0c08ef64u: goto P_0c08ef64;
case 0x0c08ef66u: goto P_0c08ef66;
case 0x0c08ef68u: goto P_0c08ef68;
case 0x0c08ef6au: goto P_0c08ef6a;
case 0x0c08ef6cu: goto P_0c08ef6c;
case 0x0c08ef6eu: goto P_0c08ef6e;
case 0x0c08ef70u: goto P_0c08ef70;
case 0x0c08ef72u: goto P_0c08ef72;
case 0x0c08ef74u: goto P_0c08ef74;
case 0x0c08ef76u: goto P_0c08ef76;
case 0x0c08ef78u: goto P_0c08ef78;
case 0x0c08ef7au: goto P_0c08ef7a;
case 0x0c08ef7cu: goto P_0c08ef7c;
case 0x0c08ef7eu: goto P_0c08ef7e;
case 0x0c08ef80u: goto P_0c08ef80;
case 0x0c08ef82u: goto P_0c08ef82;
case 0x0c08ef84u: goto P_0c08ef84;
case 0x0c08ef86u: goto P_0c08ef86;
case 0x0c08ef88u: goto P_0c08ef88;
case 0x0c08ef8au: goto P_0c08ef8a;
case 0x0c08ef8cu: goto P_0c08ef8c;
case 0x0c08ef8eu: goto P_0c08ef8e;
case 0x0c08ef90u: goto P_0c08ef90;
case 0x0c08ef92u: goto P_0c08ef92;
case 0x0c08ef94u: goto P_0c08ef94;
case 0x0c08ef96u: goto P_0c08ef96;
case 0x0c08ef98u: goto P_0c08ef98;
case 0x0c08ef9au: goto P_0c08ef9a;
case 0x0c08ef9cu: goto P_0c08ef9c;
case 0x0c08ef9eu: goto P_0c08ef9e;
case 0x0c08efa0u: goto P_0c08efa0;
case 0x0c08efa2u: goto P_0c08efa2;
case 0x0c08efa4u: goto P_0c08efa4;
case 0x0c08efa6u: goto P_0c08efa6;
case 0x0c08efa8u: goto P_0c08efa8;
case 0x0c08efaau: goto P_0c08efaa;
case 0x0c08efacu: goto P_0c08efac;
case 0x0c08efaeu: goto P_0c08efae;
case 0x0c08efb0u: goto P_0c08efb0;
case 0x0c08efb2u: goto P_0c08efb2;
case 0x0c08efb4u: goto P_0c08efb4;
case 0x0c08efb6u: goto P_0c08efb6;
case 0x0c08efb8u: goto P_0c08efb8;
case 0x0c08efbau: goto P_0c08efba;
case 0x0c08efbcu: goto P_0c08efbc;
case 0x0c08efbeu: goto P_0c08efbe;
case 0x0c08efc0u: goto P_0c08efc0;
case 0x0c08efc2u: goto P_0c08efc2;
case 0x0c08efc4u: goto P_0c08efc4;
case 0x0c08efc6u: goto P_0c08efc6;
case 0x0c08efc8u: goto P_0c08efc8;
case 0x0c08efcau: goto P_0c08efca;
case 0x0c08efccu: goto P_0c08efcc;
case 0x0c08efceu: goto P_0c08efce;
case 0x0c08efd0u: goto P_0c08efd0;
case 0x0c08efd2u: goto P_0c08efd2;
case 0x0c08efd4u: goto P_0c08efd4;
case 0x0c08efd6u: goto P_0c08efd6;
case 0x0c08efd8u: goto P_0c08efd8;
case 0x0c08efdau: goto P_0c08efda;
case 0x0c08efdcu: goto P_0c08efdc;
case 0x0c08efdeu: goto P_0c08efde;
case 0x0c08efe0u: goto P_0c08efe0;
case 0x0c08efe2u: goto P_0c08efe2;
case 0x0c08efe4u: goto P_0c08efe4;
case 0x0c08efe6u: goto P_0c08efe6;
case 0x0c08efe8u: goto P_0c08efe8;
case 0x0c08efeau: goto P_0c08efea;
case 0x0c08efecu: goto P_0c08efec;
case 0x0c08efeeu: goto P_0c08efee;
case 0x0c08eff0u: goto P_0c08eff0;
case 0x0c08eff2u: goto P_0c08eff2;
case 0x0c08eff4u: goto P_0c08eff4;
case 0x0c08eff6u: goto P_0c08eff6;
case 0x0c08eff8u: goto P_0c08eff8;
case 0x0c08effau: goto P_0c08effa;
case 0x0c08effcu: goto P_0c08effc;
case 0x0c08effeu: goto P_0c08effe;
case 0x0c08f000u: goto P_0c08f000;
case 0x0c08f002u: goto P_0c08f002;
case 0x0c08f004u: goto P_0c08f004;
case 0x0c08f006u: goto P_0c08f006;
case 0x0c08f008u: goto P_0c08f008;
case 0x0c08f00au: goto P_0c08f00a;
case 0x0c08f00cu: goto P_0c08f00c;
case 0x0c08f00eu: goto P_0c08f00e;
case 0x0c08f010u: goto P_0c08f010;
case 0x0c08f012u: goto P_0c08f012;
case 0x0c08f014u: goto P_0c08f014;
case 0x0c08f016u: goto P_0c08f016;
case 0x0c08f018u: goto P_0c08f018;
case 0x0c08f01au: goto P_0c08f01a;
case 0x0c08f01cu: goto P_0c08f01c;
case 0x0c08f01eu: goto P_0c08f01e;
case 0x0c08f020u: goto P_0c08f020;
case 0x0c08f022u: goto P_0c08f022;
case 0x0c08f024u: goto P_0c08f024;
case 0x0c08f026u: goto P_0c08f026;
case 0x0c08f028u: goto P_0c08f028;
case 0x0c08f02au: goto P_0c08f02a;
case 0x0c08f02cu: goto P_0c08f02c;
case 0x0c08f02eu: goto P_0c08f02e;
case 0x0c08f030u: goto P_0c08f030;
case 0x0c08f032u: goto P_0c08f032;
case 0x0c08f034u: goto P_0c08f034;
case 0x0c08f036u: goto P_0c08f036;
case 0x0c08f038u: goto P_0c08f038;
case 0x0c08f03au: goto P_0c08f03a;
case 0x0c08f03cu: goto P_0c08f03c;
case 0x0c08f03eu: goto P_0c08f03e;
case 0x0c08f040u: goto P_0c08f040;
case 0x0c08f042u: goto P_0c08f042;
case 0x0c08f044u: goto P_0c08f044;
case 0x0c08f046u: goto P_0c08f046;
case 0x0c08f048u: goto P_0c08f048;
case 0x0c08f04au: goto P_0c08f04a;
case 0x0c08f04cu: goto P_0c08f04c;
case 0x0c08f04eu: goto P_0c08f04e;
case 0x0c08f050u: goto P_0c08f050;
case 0x0c08f052u: goto P_0c08f052;
case 0x0c08f054u: goto P_0c08f054;
case 0x0c08f056u: goto P_0c08f056;
case 0x0c08f058u: goto P_0c08f058;
case 0x0c08f05au: goto P_0c08f05a;
case 0x0c08f05cu: goto P_0c08f05c;
case 0x0c08f05eu: goto P_0c08f05e;
case 0x0c08f060u: goto P_0c08f060;
case 0x0c08f062u: goto P_0c08f062;
case 0x0c08f064u: goto P_0c08f064;
case 0x0c08f066u: goto P_0c08f066;
case 0x0c08f068u: goto P_0c08f068;
case 0x0c08f06au: goto P_0c08f06a;
case 0x0c08f06cu: goto P_0c08f06c;
case 0x0c08f06eu: goto P_0c08f06e;
case 0x0c08f070u: goto P_0c08f070;
case 0x0c08f072u: goto P_0c08f072;
case 0x0c08f074u: goto P_0c08f074;
case 0x0c08f076u: goto P_0c08f076;
case 0x0c08f078u: goto P_0c08f078;
case 0x0c08f07au: goto P_0c08f07a;
case 0x0c08f07cu: goto P_0c08f07c;
case 0x0c08f07eu: goto P_0c08f07e;
case 0x0c08f080u: goto P_0c08f080;
case 0x0c08f082u: goto P_0c08f082;
case 0x0c08f084u: goto P_0c08f084;
case 0x0c08f086u: goto P_0c08f086;
case 0x0c08f088u: goto P_0c08f088;
case 0x0c08f08au: goto P_0c08f08a;
case 0x0c08f08cu: goto P_0c08f08c;
case 0x0c08f08eu: goto P_0c08f08e;
case 0x0c08f090u: goto P_0c08f090;
case 0x0c08f092u: goto P_0c08f092;
case 0x0c08f094u: goto P_0c08f094;
case 0x0c08f096u: goto P_0c08f096;
case 0x0c08f098u: goto P_0c08f098;
case 0x0c08f09au: goto P_0c08f09a;
case 0x0c08f09cu: goto P_0c08f09c;
case 0x0c08f09eu: goto P_0c08f09e;
case 0x0c08f0a0u: goto P_0c08f0a0;
case 0x0c08f0a2u: goto P_0c08f0a2;
case 0x0c08f0a4u: goto P_0c08f0a4;
case 0x0c08f0a6u: goto P_0c08f0a6;
case 0x0c08f0a8u: goto P_0c08f0a8;
case 0x0c08f0aau: goto P_0c08f0aa;
case 0x0c08f0acu: goto P_0c08f0ac;
case 0x0c08f0aeu: goto P_0c08f0ae;
case 0x0c08f0b0u: goto P_0c08f0b0;
case 0x0c08f0b2u: goto P_0c08f0b2;
case 0x0c08f0b4u: goto P_0c08f0b4;
case 0x0c08f0b6u: goto P_0c08f0b6;
case 0x0c08f0b8u: goto P_0c08f0b8;
case 0x0c08f0bau: goto P_0c08f0ba;
case 0x0c08f0bcu: goto P_0c08f0bc;
case 0x0c08f0beu: goto P_0c08f0be;
case 0x0c08f0c0u: goto P_0c08f0c0;
case 0x0c08f0c2u: goto P_0c08f0c2;
case 0x0c08f0c4u: goto P_0c08f0c4;
case 0x0c08f0c6u: goto P_0c08f0c6;
case 0x0c08f0c8u: goto P_0c08f0c8;
case 0x0c08f0cau: goto P_0c08f0ca;
case 0x0c08f0ccu: goto P_0c08f0cc;
case 0x0c08f0ceu: goto P_0c08f0ce;
case 0x0c08f0d0u: goto P_0c08f0d0;
case 0x0c08f0d2u: goto P_0c08f0d2;
case 0x0c08f0d4u: goto P_0c08f0d4;
case 0x0c08f0d6u: goto P_0c08f0d6;
case 0x0c08f0d8u: goto P_0c08f0d8;
case 0x0c08f0dau: goto P_0c08f0da;
case 0x0c08f0dcu: goto P_0c08f0dc;
case 0x0c08f0deu: goto P_0c08f0de;
case 0x0c08f0e0u: goto P_0c08f0e0;
case 0x0c08f0e2u: goto P_0c08f0e2;
case 0x0c08f0e4u: goto P_0c08f0e4;
default: return vf3_matrix_family(target,s,ram);
}
P_0c08ef4c: /* original 2fe6, guest PC 0x0c08ef4c */
if(!s->budget--) { s->failed_pc=0x0c08ef4cu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08ef4e;
P_0c08ef4e: /* original e004, guest PC 0x0c08ef4e */
if(!s->budget--) { s->failed_pc=0x0c08ef4eu; return 0; }
r[0]=0x00000004u;
goto P_0c08ef50;
P_0c08ef50: /* original 2fd6, guest PC 0x0c08ef50 */
if(!s->budget--) { s->failed_pc=0x0c08ef50u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08ef52;
P_0c08ef52: /* original 6e43, guest PC 0x0c08ef52 */
if(!s->budget--) { s->failed_pc=0x0c08ef52u; return 0; }
r[14]=r[4];
goto P_0c08ef54;
P_0c08ef54: /* original 2fc6, guest PC 0x0c08ef54 */
if(!s->budget--) { s->failed_pc=0x0c08ef54u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08ef56;
P_0c08ef56: /* original 2fb6, guest PC 0x0c08ef56 */
if(!s->budget--) { s->failed_pc=0x0c08ef56u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08ef58;
P_0c08ef58: /* original 2fa6, guest PC 0x0c08ef58 */
if(!s->budget--) { s->failed_pc=0x0c08ef58u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08ef5a;
P_0c08ef5a: /* original 2f96, guest PC 0x0c08ef5a */
if(!s->budget--) { s->failed_pc=0x0c08ef5au; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08ef5c;
P_0c08ef5c: /* original 2f86, guest PC 0x0c08ef5c */
if(!s->budget--) { s->failed_pc=0x0c08ef5cu; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08ef5e;
P_0c08ef5e: /* original fffb, guest PC 0x0c08ef5e */
if(!s->budget--) { s->failed_pc=0x0c08ef5eu; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c08ef60;
P_0c08ef60: /* original ffeb, guest PC 0x0c08ef60 */
if(!s->budget--) { s->failed_pc=0x0c08ef60u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,14,r[15]);
goto P_0c08ef62;
P_0c08ef62: /* original 4f22, guest PC 0x0c08ef62 */
if(!s->budget--) { s->failed_pc=0x0c08ef62u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c08ef64;
P_0c08ef64: /* original 7fdc, guest PC 0x0c08ef64 */
if(!s->budget--) { s->failed_pc=0x0c08ef64u; return 0; }
r[15]+=0xffffffdcu;
goto P_0c08ef66;
P_0c08ef66: /* original ff47, guest PC 0x0c08ef66 */
if(!s->budget--) { s->failed_pc=0x0c08ef66u; return 0; }
vf3_matrix_store(s,ram,4,r[15]+r[0]);
goto P_0c08ef68;
P_0c08ef68: /* original e008, guest PC 0x0c08ef68 */
if(!s->budget--) { s->failed_pc=0x0c08ef68u; return 0; }
r[0]=0x00000008u;
goto P_0c08ef6a;
P_0c08ef6a: /* original ff5a, guest PC 0x0c08ef6a */
if(!s->budget--) { s->failed_pc=0x0c08ef6au; return 0; }
vf3_matrix_store(s,ram,5,r[15]);
goto P_0c08ef6c;
P_0c08ef6c: /* original ff67, guest PC 0x0c08ef6c */
if(!s->budget--) { s->failed_pc=0x0c08ef6cu; return 0; }
vf3_matrix_store(s,ram,6,r[15]+r[0]);
goto P_0c08ef6e;
P_0c08ef6e: /* original d361, guest PC 0x0c08ef6e */
if(!s->budget--) { s->failed_pc=0x0c08ef6eu; return 0; }
r[3]=read(ram,0x0c08f0f4u,4);
goto P_0c08ef70;
P_0c08ef70: /* original 430b, guest PC 0x0c08ef70 */
if(!s->budget--) { s->failed_pc=0x0c08ef70u; return 0; }
target=r[3];
r[16]=code_base|0x0c08ef74u;
r[4]=0x00000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08ef74u) { target=s->pc; goto dispatch; }
goto P_0c08ef74;
P_0c08ef72: /* original e400, guest PC 0x0c08ef72 */
if(!s->budget--) { s->failed_pc=0x0c08ef72u; return 0; }
r[4]=0x00000000u;
goto P_0c08ef74;
P_0c08ef74: /* original da61, guest PC 0x0c08ef74 */
if(!s->budget--) { s->failed_pc=0x0c08ef74u; return 0; }
r[10]=read(ram,0x0c08f0fcu,4);
goto P_0c08ef76;
P_0c08ef76: /* original c760, guest PC 0x0c08ef76 */
if(!s->budget--) { s->failed_pc=0x0c08ef76u; return 0; }
r[0]=code_base|0x0008f0f8u;
goto P_0c08ef78;
P_0c08ef78: /* original 4a0b, guest PC 0x0c08ef78 */
if(!s->budget--) { s->failed_pc=0x0c08ef78u; return 0; }
target=r[10];
r[16]=code_base|0x0c08ef7cu;
vf3_matrix_load(s,ram,15,r[0]);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08ef7cu) { target=s->pc; goto dispatch; }
goto P_0c08ef7c;
P_0c08ef7a: /* original ff08, guest PC 0x0c08ef7a */
if(!s->budget--) { s->failed_pc=0x0c08ef7au; return 0; }
vf3_matrix_load(s,ram,15,r[0]);
goto P_0c08ef7c;
P_0c08ef7c: /* original e07c, guest PC 0x0c08ef7c */
if(!s->budget--) { s->failed_pc=0x0c08ef7cu; return 0; }
r[0]=0x0000007cu;
goto P_0c08ef7e;
P_0c08ef7e: /* original f4e6, guest PC 0x0c08ef7e */
if(!s->budget--) { s->failed_pc=0x0c08ef7eu; return 0; }
vf3_matrix_load(s,ram,4,r[14]+r[0]);
goto P_0c08ef80;
P_0c08ef80: /* original 7004, guest PC 0x0c08ef80 */
if(!s->budget--) { s->failed_pc=0x0c08ef80u; return 0; }
r[0]+=0x00000004u;
goto P_0c08ef82;
P_0c08ef82: /* original f5e6, guest PC 0x0c08ef82 */
if(!s->budget--) { s->failed_pc=0x0c08ef82u; return 0; }
vf3_matrix_load(s,ram,5,r[14]+r[0]);
goto P_0c08ef84;
P_0c08ef84: /* original 7004, guest PC 0x0c08ef84 */
if(!s->budget--) { s->failed_pc=0x0c08ef84u; return 0; }
r[0]+=0x00000004u;
goto P_0c08ef86;
P_0c08ef86: /* original f3e6, guest PC 0x0c08ef86 */
if(!s->budget--) { s->failed_pc=0x0c08ef86u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c08ef88;
P_0c08ef88: /* original e01c, guest PC 0x0c08ef88 */
if(!s->budget--) { s->failed_pc=0x0c08ef88u; return 0; }
r[0]=0x0000001cu;
goto P_0c08ef8a;
P_0c08ef8a: /* original ff37, guest PC 0x0c08ef8a */
if(!s->budget--) { s->failed_pc=0x0c08ef8au; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c08ef8c;
P_0c08ef8c: /* original dd5c, guest PC 0x0c08ef8c */
if(!s->budget--) { s->failed_pc=0x0c08ef8cu; return 0; }
r[13]=read(ram,0x0c08f100u,4);
goto P_0c08ef8e;
P_0c08ef8e: /* original f63c, guest PC 0x0c08ef8e */
if(!s->budget--) { s->failed_pc=0x0c08ef8eu; return 0; }
vf3_matrix_move(s,6,3);
goto P_0c08ef90;
P_0c08ef90: /* original 4d0b, guest PC 0x0c08ef90 */
if(!s->budget--) { s->failed_pc=0x0c08ef90u; return 0; }
target=r[13];
r[16]=code_base|0x0c08ef94u;
fr[6]^=0x80000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08ef94u) { target=s->pc; goto dispatch; }
goto P_0c08ef94;
P_0c08ef92: /* original f64d, guest PC 0x0c08ef92 */
if(!s->budget--) { s->failed_pc=0x0c08ef92u; return 0; }
fr[6]^=0x80000000u;
goto P_0c08ef94;
P_0c08ef94: /* original dc5b, guest PC 0x0c08ef94 */
if(!s->budget--) { s->failed_pc=0x0c08ef94u; return 0; }
r[12]=read(ram,0x0c08f104u,4);
goto P_0c08ef96;
P_0c08ef96: /* original f5fc, guest PC 0x0c08ef96 */
if(!s->budget--) { s->failed_pc=0x0c08ef96u; return 0; }
vf3_matrix_move(s,5,15);
goto P_0c08ef98;
P_0c08ef98: /* original f6fc, guest PC 0x0c08ef98 */
if(!s->budget--) { s->failed_pc=0x0c08ef98u; return 0; }
vf3_matrix_move(s,6,15);
goto P_0c08ef9a;
P_0c08ef9a: /* original 4c0b, guest PC 0x0c08ef9a */
if(!s->budget--) { s->failed_pc=0x0c08ef9au; return 0; }
target=r[12];
r[16]=code_base|0x0c08ef9eu;
vf3_matrix_move(s,4,15);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08ef9eu) { target=s->pc; goto dispatch; }
goto P_0c08ef9e;
P_0c08ef9c: /* original f4fc, guest PC 0x0c08ef9c */
if(!s->budget--) { s->failed_pc=0x0c08ef9cu; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c08ef9e;
P_0c08ef9e: /* original db5a, guest PC 0x0c08ef9e */
if(!s->budget--) { s->failed_pc=0x0c08ef9eu; return 0; }
r[11]=read(ram,0x0c08f108u,4);
goto P_0c08efa0;
P_0c08efa0: /* original 99a1, guest PC 0x0c08efa0 */
if(!s->budget--) { s->failed_pc=0x0c08efa0u; return 0; }
r[9]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08f0e6u,2);
goto P_0c08efa2;
P_0c08efa2: /* original 4b0b, guest PC 0x0c08efa2 */
if(!s->budget--) { s->failed_pc=0x0c08efa2u; return 0; }
target=r[11];
r[16]=code_base|0x0c08efa6u;
r[4]=r[9];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08efa6u) { target=s->pc; goto dispatch; }
goto P_0c08efa6;
P_0c08efa4: /* original 6493, guest PC 0x0c08efa4 */
if(!s->budget--) { s->failed_pc=0x0c08efa4u; return 0; }
r[4]=r[9];
goto P_0c08efa6;
P_0c08efa6: /* original 4a0b, guest PC 0x0c08efa6 */
if(!s->budget--) { s->failed_pc=0x0c08efa6u; return 0; }
target=r[10];
r[16]=code_base|0x0c08efaau;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08efaau) { target=s->pc; goto dispatch; }
goto P_0c08efaa;
P_0c08efa8: /* original 0009, guest PC 0x0c08efa8 */
if(!s->budget--) { s->failed_pc=0x0c08efa8u; return 0; }
goto P_0c08efaa;
P_0c08efaa: /* original 909d, guest PC 0x0c08efaa */
if(!s->budget--) { s->failed_pc=0x0c08efaau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08f0e8u,2);
goto P_0c08efac;
P_0c08efac: /* original f4e6, guest PC 0x0c08efac */
if(!s->budget--) { s->failed_pc=0x0c08efacu; return 0; }
vf3_matrix_load(s,ram,4,r[14]+r[0]);
goto P_0c08efae;
P_0c08efae: /* original 7004, guest PC 0x0c08efae */
if(!s->budget--) { s->failed_pc=0x0c08efaeu; return 0; }
r[0]+=0x00000004u;
goto P_0c08efb0;
P_0c08efb0: /* original f5e6, guest PC 0x0c08efb0 */
if(!s->budget--) { s->failed_pc=0x0c08efb0u; return 0; }
vf3_matrix_load(s,ram,5,r[14]+r[0]);
goto P_0c08efb2;
P_0c08efb2: /* original 7004, guest PC 0x0c08efb2 */
if(!s->budget--) { s->failed_pc=0x0c08efb2u; return 0; }
r[0]+=0x00000004u;
goto P_0c08efb4;
P_0c08efb4: /* original f3e6, guest PC 0x0c08efb4 */
if(!s->budget--) { s->failed_pc=0x0c08efb4u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c08efb6;
P_0c08efb6: /* original e014, guest PC 0x0c08efb6 */
if(!s->budget--) { s->failed_pc=0x0c08efb6u; return 0; }
r[0]=0x00000014u;
goto P_0c08efb8;
P_0c08efb8: /* original ff37, guest PC 0x0c08efb8 */
if(!s->budget--) { s->failed_pc=0x0c08efb8u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c08efba;
P_0c08efba: /* original f63c, guest PC 0x0c08efba */
if(!s->budget--) { s->failed_pc=0x0c08efbau; return 0; }
vf3_matrix_move(s,6,3);
goto P_0c08efbc;
P_0c08efbc: /* original 4d0b, guest PC 0x0c08efbc */
if(!s->budget--) { s->failed_pc=0x0c08efbcu; return 0; }
target=r[13];
r[16]=code_base|0x0c08efc0u;
fr[6]^=0x80000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08efc0u) { target=s->pc; goto dispatch; }
goto P_0c08efc0;
P_0c08efbe: /* original f64d, guest PC 0x0c08efbe */
if(!s->budget--) { s->failed_pc=0x0c08efbeu; return 0; }
fr[6]^=0x80000000u;
goto P_0c08efc0;
P_0c08efc0: /* original f5fc, guest PC 0x0c08efc0 */
if(!s->budget--) { s->failed_pc=0x0c08efc0u; return 0; }
vf3_matrix_move(s,5,15);
goto P_0c08efc2;
P_0c08efc2: /* original f6fc, guest PC 0x0c08efc2 */
if(!s->budget--) { s->failed_pc=0x0c08efc2u; return 0; }
vf3_matrix_move(s,6,15);
goto P_0c08efc4;
P_0c08efc4: /* original 4c0b, guest PC 0x0c08efc4 */
if(!s->budget--) { s->failed_pc=0x0c08efc4u; return 0; }
target=r[12];
r[16]=code_base|0x0c08efc8u;
vf3_matrix_move(s,4,15);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08efc8u) { target=s->pc; goto dispatch; }
goto P_0c08efc8;
P_0c08efc6: /* original f4fc, guest PC 0x0c08efc6 */
if(!s->budget--) { s->failed_pc=0x0c08efc6u; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c08efc8;
P_0c08efc8: /* original 4b0b, guest PC 0x0c08efc8 */
if(!s->budget--) { s->failed_pc=0x0c08efc8u; return 0; }
target=r[11];
r[16]=code_base|0x0c08efccu;
r[4]=r[9];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08efccu) { target=s->pc; goto dispatch; }
goto P_0c08efcc;
P_0c08efca: /* original 6493, guest PC 0x0c08efca */
if(!s->budget--) { s->failed_pc=0x0c08efcau; return 0; }
r[4]=r[9];
goto P_0c08efcc;
P_0c08efcc: /* original 4a0b, guest PC 0x0c08efcc */
if(!s->budget--) { s->failed_pc=0x0c08efccu; return 0; }
target=r[10];
r[16]=code_base|0x0c08efd0u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08efd0u) { target=s->pc; goto dispatch; }
goto P_0c08efd0;
P_0c08efce: /* original 0009, guest PC 0x0c08efce */
if(!s->budget--) { s->failed_pc=0x0c08efceu; return 0; }
goto P_0c08efd0;
P_0c08efd0: /* original 85ef, guest PC 0x0c08efd0 */
if(!s->budget--) { s->failed_pc=0x0c08efd0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+30,2);
goto P_0c08efd2;
P_0c08efd2: /* original d84e, guest PC 0x0c08efd2 */
if(!s->budget--) { s->failed_pc=0x0c08efd2u; return 0; }
r[8]=read(ram,0x0c08f10cu,4);
goto P_0c08efd4;
P_0c08efd4: /* original 480b, guest PC 0x0c08efd4 */
if(!s->budget--) { s->failed_pc=0x0c08efd4u; return 0; }
target=r[8];
r[16]=code_base|0x0c08efd8u;
r[4]=r[0];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08efd8u) { target=s->pc; goto dispatch; }
goto P_0c08efd8;
P_0c08efd6: /* original 6403, guest PC 0x0c08efd6 */
if(!s->budget--) { s->failed_pc=0x0c08efd6u; return 0; }
r[4]=r[0];
goto P_0c08efd8;
P_0c08efd8: /* original d34d, guest PC 0x0c08efd8 */
if(!s->budget--) { s->failed_pc=0x0c08efd8u; return 0; }
r[3]=read(ram,0x0c08f110u,4);
goto P_0c08efda;
P_0c08efda: /* original 85ee, guest PC 0x0c08efda */
if(!s->budget--) { s->failed_pc=0x0c08efdau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+28,2);
goto P_0c08efdc;
P_0c08efdc: /* original 430b, guest PC 0x0c08efdc */
if(!s->budget--) { s->failed_pc=0x0c08efdcu; return 0; }
target=r[3];
r[16]=code_base|0x0c08efe0u;
r[4]=r[0];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08efe0u) { target=s->pc; goto dispatch; }
goto P_0c08efe0;
P_0c08efde: /* original 6403, guest PC 0x0c08efde */
if(!s->budget--) { s->failed_pc=0x0c08efdeu; return 0; }
r[4]=r[0];
goto P_0c08efe0;
P_0c08efe0: /* original e004, guest PC 0x0c08efe0 */
if(!s->budget--) { s->failed_pc=0x0c08efe0u; return 0; }
r[0]=0x00000004u;
goto P_0c08efe2;
P_0c08efe2: /* original f5f8, guest PC 0x0c08efe2 */
if(!s->budget--) { s->failed_pc=0x0c08efe2u; return 0; }
vf3_matrix_load(s,ram,5,r[15]);
goto P_0c08efe4;
P_0c08efe4: /* original f4f6, guest PC 0x0c08efe4 */
if(!s->budget--) { s->failed_pc=0x0c08efe4u; return 0; }
vf3_matrix_load(s,ram,4,r[15]+r[0]);
goto P_0c08efe6;
P_0c08efe6: /* original e008, guest PC 0x0c08efe6 */
if(!s->budget--) { s->failed_pc=0x0c08efe6u; return 0; }
r[0]=0x00000008u;
goto P_0c08efe8;
P_0c08efe8: /* original f3f6, guest PC 0x0c08efe8 */
if(!s->budget--) { s->failed_pc=0x0c08efe8u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c08efea;
P_0c08efea: /* original e020, guest PC 0x0c08efea */
if(!s->budget--) { s->failed_pc=0x0c08efeau; return 0; }
r[0]=0x00000020u;
goto P_0c08efec;
P_0c08efec: /* original ff37, guest PC 0x0c08efec */
if(!s->budget--) { s->failed_pc=0x0c08efecu; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c08efee;
P_0c08efee: /* original f63c, guest PC 0x0c08efee */
if(!s->budget--) { s->failed_pc=0x0c08efeeu; return 0; }
vf3_matrix_move(s,6,3);
goto P_0c08eff0;
P_0c08eff0: /* original 4d0b, guest PC 0x0c08eff0 */
if(!s->budget--) { s->failed_pc=0x0c08eff0u; return 0; }
target=r[13];
r[16]=code_base|0x0c08eff4u;
fr[6]^=0x80000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08eff4u) { target=s->pc; goto dispatch; }
goto P_0c08eff4;
P_0c08eff2: /* original f64d, guest PC 0x0c08eff2 */
if(!s->budget--) { s->failed_pc=0x0c08eff2u; return 0; }
fr[6]^=0x80000000u;
goto P_0c08eff4;
P_0c08eff4: /* original d346, guest PC 0x0c08eff4 */
if(!s->budget--) { s->failed_pc=0x0c08eff4u; return 0; }
r[3]=read(ram,0x0c08f110u,4);
goto P_0c08eff6;
P_0c08eff6: /* original 85ee, guest PC 0x0c08eff6 */
if(!s->budget--) { s->failed_pc=0x0c08eff6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+28,2);
goto P_0c08eff8;
P_0c08eff8: /* original 430b, guest PC 0x0c08eff8 */
if(!s->budget--) { s->failed_pc=0x0c08eff8u; return 0; }
target=r[3];
r[16]=code_base|0x0c08effcu;
r[4]=0u-r[0];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08effcu) { target=s->pc; goto dispatch; }
goto P_0c08effc;
P_0c08effa: /* original 640b, guest PC 0x0c08effa */
if(!s->budget--) { s->failed_pc=0x0c08effau; return 0; }
r[4]=0u-r[0];
goto P_0c08effc;
P_0c08effc: /* original 85ef, guest PC 0x0c08effc */
if(!s->budget--) { s->failed_pc=0x0c08effcu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+30,2);
goto P_0c08effe;
P_0c08effe: /* original 480b, guest PC 0x0c08effe */
if(!s->budget--) { s->failed_pc=0x0c08effeu; return 0; }
target=r[8];
r[16]=code_base|0x0c08f002u;
r[4]=0u-r[0];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08f002u) { target=s->pc; goto dispatch; }
goto P_0c08f002;
P_0c08f000: /* original 640b, guest PC 0x0c08f000 */
if(!s->budget--) { s->failed_pc=0x0c08f000u; return 0; }
r[4]=0u-r[0];
goto P_0c08f002;
P_0c08f002: /* original 9072, guest PC 0x0c08f002 */
if(!s->budget--) { s->failed_pc=0x0c08f002u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08f0eau,2);
goto P_0c08f004;
P_0c08f004: /* original f6e6, guest PC 0x0c08f004 */
if(!s->budget--) { s->failed_pc=0x0c08f004u; return 0; }
vf3_matrix_load(s,ram,6,r[14]+r[0]);
goto P_0c08f006;
P_0c08f006: /* original 70fc, guest PC 0x0c08f006 */
if(!s->budget--) { s->failed_pc=0x0c08f006u; return 0; }
r[0]+=0xfffffffcu;
goto P_0c08f008;
P_0c08f008: /* original f5e6, guest PC 0x0c08f008 */
if(!s->budget--) { s->failed_pc=0x0c08f008u; return 0; }
vf3_matrix_load(s,ram,5,r[14]+r[0]);
goto P_0c08f00a;
P_0c08f00a: /* original 70fc, guest PC 0x0c08f00a */
if(!s->budget--) { s->failed_pc=0x0c08f00au; return 0; }
r[0]+=0xfffffffcu;
goto P_0c08f00c;
P_0c08f00c: /* original f64d, guest PC 0x0c08f00c */
if(!s->budget--) { s->failed_pc=0x0c08f00cu; return 0; }
fr[6]^=0x80000000u;
goto P_0c08f00e;
P_0c08f00e: /* original 4d0b, guest PC 0x0c08f00e */
if(!s->budget--) { s->failed_pc=0x0c08f00eu; return 0; }
target=r[13];
r[16]=code_base|0x0c08f012u;
vf3_matrix_load(s,ram,4,r[14]+r[0]);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08f012u) { target=s->pc; goto dispatch; }
goto P_0c08f012;
P_0c08f010: /* original f4e6, guest PC 0x0c08f010 */
if(!s->budget--) { s->failed_pc=0x0c08f010u; return 0; }
vf3_matrix_load(s,ram,4,r[14]+r[0]);
goto P_0c08f012;
P_0c08f012: /* original f5fc, guest PC 0x0c08f012 */
if(!s->budget--) { s->failed_pc=0x0c08f012u; return 0; }
vf3_matrix_move(s,5,15);
goto P_0c08f014;
P_0c08f014: /* original f6fc, guest PC 0x0c08f014 */
if(!s->budget--) { s->failed_pc=0x0c08f014u; return 0; }
vf3_matrix_move(s,6,15);
goto P_0c08f016;
P_0c08f016: /* original 4c0b, guest PC 0x0c08f016 */
if(!s->budget--) { s->failed_pc=0x0c08f016u; return 0; }
target=r[12];
r[16]=code_base|0x0c08f01au;
vf3_matrix_move(s,4,15);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08f01au) { target=s->pc; goto dispatch; }
goto P_0c08f01a;
P_0c08f018: /* original f4fc, guest PC 0x0c08f018 */
if(!s->budget--) { s->failed_pc=0x0c08f018u; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c08f01a;
P_0c08f01a: /* original c73e, guest PC 0x0c08f01a */
if(!s->budget--) { s->failed_pc=0x0c08f01au; return 0; }
r[0]=code_base|0x0008f114u;
goto P_0c08f01c;
P_0c08f01c: /* original fe08, guest PC 0x0c08f01c */
if(!s->budget--) { s->failed_pc=0x0c08f01cu; return 0; }
vf3_matrix_load(s,ram,14,r[0]);
goto P_0c08f01e;
P_0c08f01e: /* original f5ec, guest PC 0x0c08f01e */
if(!s->budget--) { s->failed_pc=0x0c08f01eu; return 0; }
vf3_matrix_move(s,5,14);
goto P_0c08f020;
P_0c08f020: /* original f6ec, guest PC 0x0c08f020 */
if(!s->budget--) { s->failed_pc=0x0c08f020u; return 0; }
vf3_matrix_move(s,6,14);
goto P_0c08f022;
P_0c08f022: /* original 4c0b, guest PC 0x0c08f022 */
if(!s->budget--) { s->failed_pc=0x0c08f022u; return 0; }
target=r[12];
r[16]=code_base|0x0c08f026u;
vf3_matrix_move(s,4,14);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08f026u) { target=s->pc; goto dispatch; }
goto P_0c08f026;
P_0c08f024: /* original f4ec, guest PC 0x0c08f024 */
if(!s->budget--) { s->failed_pc=0x0c08f024u; return 0; }
vf3_matrix_move(s,4,14);
goto P_0c08f026;
P_0c08f026: /* original 9461, guest PC 0x0c08f026 */
if(!s->budget--) { s->failed_pc=0x0c08f026u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08f0ecu,2);
goto P_0c08f028;
P_0c08f028: /* original 4b0b, guest PC 0x0c08f028 */
if(!s->budget--) { s->failed_pc=0x0c08f028u; return 0; }
target=r[11];
r[16]=code_base|0x0c08f02cu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08f02cu) { target=s->pc; goto dispatch; }
goto P_0c08f02c;
P_0c08f02a: /* original 0009, guest PC 0x0c08f02a */
if(!s->budget--) { s->failed_pc=0x0c08f02au; return 0; }
goto P_0c08f02c;
P_0c08f02c: /* original 4a0b, guest PC 0x0c08f02c */
if(!s->budget--) { s->failed_pc=0x0c08f02cu; return 0; }
target=r[10];
r[16]=code_base|0x0c08f030u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08f030u) { target=s->pc; goto dispatch; }
goto P_0c08f030;
P_0c08f02e: /* original 0009, guest PC 0x0c08f02e */
if(!s->budget--) { s->failed_pc=0x0c08f02eu; return 0; }
goto P_0c08f030;
P_0c08f030: /* original 905d, guest PC 0x0c08f030 */
if(!s->budget--) { s->failed_pc=0x0c08f030u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08f0eeu,2);
goto P_0c08f032;
P_0c08f032: /* original f6e6, guest PC 0x0c08f032 */
if(!s->budget--) { s->failed_pc=0x0c08f032u; return 0; }
vf3_matrix_load(s,ram,6,r[14]+r[0]);
goto P_0c08f034;
P_0c08f034: /* original 70fc, guest PC 0x0c08f034 */
if(!s->budget--) { s->failed_pc=0x0c08f034u; return 0; }
r[0]+=0xfffffffcu;
goto P_0c08f036;
P_0c08f036: /* original f5e6, guest PC 0x0c08f036 */
if(!s->budget--) { s->failed_pc=0x0c08f036u; return 0; }
vf3_matrix_load(s,ram,5,r[14]+r[0]);
goto P_0c08f038;
P_0c08f038: /* original 70fc, guest PC 0x0c08f038 */
if(!s->budget--) { s->failed_pc=0x0c08f038u; return 0; }
r[0]+=0xfffffffcu;
goto P_0c08f03a;
P_0c08f03a: /* original f64d, guest PC 0x0c08f03a */
if(!s->budget--) { s->failed_pc=0x0c08f03au; return 0; }
fr[6]^=0x80000000u;
goto P_0c08f03c;
P_0c08f03c: /* original 4d0b, guest PC 0x0c08f03c */
if(!s->budget--) { s->failed_pc=0x0c08f03cu; return 0; }
target=r[13];
r[16]=code_base|0x0c08f040u;
vf3_matrix_load(s,ram,4,r[14]+r[0]);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08f040u) { target=s->pc; goto dispatch; }
goto P_0c08f040;
P_0c08f03e: /* original f4e6, guest PC 0x0c08f03e */
if(!s->budget--) { s->failed_pc=0x0c08f03eu; return 0; }
vf3_matrix_load(s,ram,4,r[14]+r[0]);
goto P_0c08f040;
P_0c08f040: /* original f5fc, guest PC 0x0c08f040 */
if(!s->budget--) { s->failed_pc=0x0c08f040u; return 0; }
vf3_matrix_move(s,5,15);
goto P_0c08f042;
P_0c08f042: /* original f6fc, guest PC 0x0c08f042 */
if(!s->budget--) { s->failed_pc=0x0c08f042u; return 0; }
vf3_matrix_move(s,6,15);
goto P_0c08f044;
P_0c08f044: /* original 4c0b, guest PC 0x0c08f044 */
if(!s->budget--) { s->failed_pc=0x0c08f044u; return 0; }
target=r[12];
r[16]=code_base|0x0c08f048u;
vf3_matrix_move(s,4,15);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08f048u) { target=s->pc; goto dispatch; }
goto P_0c08f048;
P_0c08f046: /* original f4fc, guest PC 0x0c08f046 */
if(!s->budget--) { s->failed_pc=0x0c08f046u; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c08f048;
P_0c08f048: /* original 4b0b, guest PC 0x0c08f048 */
if(!s->budget--) { s->failed_pc=0x0c08f048u; return 0; }
target=r[11];
r[16]=code_base|0x0c08f04cu;
r[4]=r[9];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08f04cu) { target=s->pc; goto dispatch; }
goto P_0c08f04c;
P_0c08f04a: /* original 6493, guest PC 0x0c08f04a */
if(!s->budget--) { s->failed_pc=0x0c08f04au; return 0; }
r[4]=r[9];
goto P_0c08f04c;
P_0c08f04c: /* original 4a0b, guest PC 0x0c08f04c */
if(!s->budget--) { s->failed_pc=0x0c08f04cu; return 0; }
target=r[10];
r[16]=code_base|0x0c08f050u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08f050u) { target=s->pc; goto dispatch; }
goto P_0c08f050;
P_0c08f04e: /* original 0009, guest PC 0x0c08f04e */
if(!s->budget--) { s->failed_pc=0x0c08f04eu; return 0; }
goto P_0c08f050;
P_0c08f050: /* original 85ef, guest PC 0x0c08f050 */
if(!s->budget--) { s->failed_pc=0x0c08f050u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+30,2);
goto P_0c08f052;
P_0c08f052: /* original 480b, guest PC 0x0c08f052 */
if(!s->budget--) { s->failed_pc=0x0c08f052u; return 0; }
target=r[8];
r[16]=code_base|0x0c08f056u;
r[4]=r[0];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08f056u) { target=s->pc; goto dispatch; }
goto P_0c08f056;
P_0c08f054: /* original 6403, guest PC 0x0c08f054 */
if(!s->budget--) { s->failed_pc=0x0c08f054u; return 0; }
r[4]=r[0];
goto P_0c08f056;
P_0c08f056: /* original d32e, guest PC 0x0c08f056 */
if(!s->budget--) { s->failed_pc=0x0c08f056u; return 0; }
r[3]=read(ram,0x0c08f110u,4);
goto P_0c08f058;
P_0c08f058: /* original 85ee, guest PC 0x0c08f058 */
if(!s->budget--) { s->failed_pc=0x0c08f058u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+28,2);
goto P_0c08f05a;
P_0c08f05a: /* original 430b, guest PC 0x0c08f05a */
if(!s->budget--) { s->failed_pc=0x0c08f05au; return 0; }
target=r[3];
r[16]=code_base|0x0c08f05eu;
r[4]=r[0];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08f05eu) { target=s->pc; goto dispatch; }
goto P_0c08f05e;
P_0c08f05c: /* original 6403, guest PC 0x0c08f05c */
if(!s->budget--) { s->failed_pc=0x0c08f05cu; return 0; }
r[4]=r[0];
goto P_0c08f05e;
P_0c08f05e: /* original e004, guest PC 0x0c08f05e */
if(!s->budget--) { s->failed_pc=0x0c08f05eu; return 0; }
r[0]=0x00000004u;
goto P_0c08f060;
P_0c08f060: /* original f5f8, guest PC 0x0c08f060 */
if(!s->budget--) { s->failed_pc=0x0c08f060u; return 0; }
vf3_matrix_load(s,ram,5,r[15]);
goto P_0c08f062;
P_0c08f062: /* original f4f6, guest PC 0x0c08f062 */
if(!s->budget--) { s->failed_pc=0x0c08f062u; return 0; }
vf3_matrix_load(s,ram,4,r[15]+r[0]);
goto P_0c08f064;
P_0c08f064: /* original e008, guest PC 0x0c08f064 */
if(!s->budget--) { s->failed_pc=0x0c08f064u; return 0; }
r[0]=0x00000008u;
goto P_0c08f066;
P_0c08f066: /* original f3f6, guest PC 0x0c08f066 */
if(!s->budget--) { s->failed_pc=0x0c08f066u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c08f068;
P_0c08f068: /* original e010, guest PC 0x0c08f068 */
if(!s->budget--) { s->failed_pc=0x0c08f068u; return 0; }
r[0]=0x00000010u;
goto P_0c08f06a;
P_0c08f06a: /* original ff37, guest PC 0x0c08f06a */
if(!s->budget--) { s->failed_pc=0x0c08f06au; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c08f06c;
P_0c08f06c: /* original f63c, guest PC 0x0c08f06c */
if(!s->budget--) { s->failed_pc=0x0c08f06cu; return 0; }
vf3_matrix_move(s,6,3);
goto P_0c08f06e;
P_0c08f06e: /* original 4d0b, guest PC 0x0c08f06e */
if(!s->budget--) { s->failed_pc=0x0c08f06eu; return 0; }
target=r[13];
r[16]=code_base|0x0c08f072u;
fr[6]^=0x80000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08f072u) { target=s->pc; goto dispatch; }
goto P_0c08f072;
P_0c08f070: /* original f64d, guest PC 0x0c08f070 */
if(!s->budget--) { s->failed_pc=0x0c08f070u; return 0; }
fr[6]^=0x80000000u;
goto P_0c08f072;
P_0c08f072: /* original d327, guest PC 0x0c08f072 */
if(!s->budget--) { s->failed_pc=0x0c08f072u; return 0; }
r[3]=read(ram,0x0c08f110u,4);
goto P_0c08f074;
P_0c08f074: /* original 85ee, guest PC 0x0c08f074 */
if(!s->budget--) { s->failed_pc=0x0c08f074u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+28,2);
goto P_0c08f076;
P_0c08f076: /* original 430b, guest PC 0x0c08f076 */
if(!s->budget--) { s->failed_pc=0x0c08f076u; return 0; }
target=r[3];
r[16]=code_base|0x0c08f07au;
r[4]=0u-r[0];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08f07au) { target=s->pc; goto dispatch; }
goto P_0c08f07a;
P_0c08f078: /* original 640b, guest PC 0x0c08f078 */
if(!s->budget--) { s->failed_pc=0x0c08f078u; return 0; }
r[4]=0u-r[0];
goto P_0c08f07a;
P_0c08f07a: /* original 85ef, guest PC 0x0c08f07a */
if(!s->budget--) { s->failed_pc=0x0c08f07au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+30,2);
goto P_0c08f07c;
P_0c08f07c: /* original 480b, guest PC 0x0c08f07c */
if(!s->budget--) { s->failed_pc=0x0c08f07cu; return 0; }
target=r[8];
r[16]=code_base|0x0c08f080u;
r[4]=0u-r[0];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08f080u) { target=s->pc; goto dispatch; }
goto P_0c08f080;
P_0c08f07e: /* original 640b, guest PC 0x0c08f07e */
if(!s->budget--) { s->failed_pc=0x0c08f07eu; return 0; }
r[4]=0u-r[0];
goto P_0c08f080;
P_0c08f080: /* original 9036, guest PC 0x0c08f080 */
if(!s->budget--) { s->failed_pc=0x0c08f080u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08f0f0u,2);
goto P_0c08f082;
P_0c08f082: /* original f4e6, guest PC 0x0c08f082 */
if(!s->budget--) { s->failed_pc=0x0c08f082u; return 0; }
vf3_matrix_load(s,ram,4,r[14]+r[0]);
goto P_0c08f084;
P_0c08f084: /* original 7004, guest PC 0x0c08f084 */
if(!s->budget--) { s->failed_pc=0x0c08f084u; return 0; }
r[0]+=0x00000004u;
goto P_0c08f086;
P_0c08f086: /* original f5e6, guest PC 0x0c08f086 */
if(!s->budget--) { s->failed_pc=0x0c08f086u; return 0; }
vf3_matrix_load(s,ram,5,r[14]+r[0]);
goto P_0c08f088;
P_0c08f088: /* original 7004, guest PC 0x0c08f088 */
if(!s->budget--) { s->failed_pc=0x0c08f088u; return 0; }
r[0]+=0x00000004u;
goto P_0c08f08a;
P_0c08f08a: /* original f3e6, guest PC 0x0c08f08a */
if(!s->budget--) { s->failed_pc=0x0c08f08au; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c08f08c;
P_0c08f08c: /* original e00c, guest PC 0x0c08f08c */
if(!s->budget--) { s->failed_pc=0x0c08f08cu; return 0; }
r[0]=0x0000000cu;
goto P_0c08f08e;
P_0c08f08e: /* original ff37, guest PC 0x0c08f08e */
if(!s->budget--) { s->failed_pc=0x0c08f08eu; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c08f090;
P_0c08f090: /* original f63c, guest PC 0x0c08f090 */
if(!s->budget--) { s->failed_pc=0x0c08f090u; return 0; }
vf3_matrix_move(s,6,3);
goto P_0c08f092;
P_0c08f092: /* original 4d0b, guest PC 0x0c08f092 */
if(!s->budget--) { s->failed_pc=0x0c08f092u; return 0; }
target=r[13];
r[16]=code_base|0x0c08f096u;
fr[6]^=0x80000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08f096u) { target=s->pc; goto dispatch; }
goto P_0c08f096;
P_0c08f094: /* original f64d, guest PC 0x0c08f094 */
if(!s->budget--) { s->failed_pc=0x0c08f094u; return 0; }
fr[6]^=0x80000000u;
goto P_0c08f096;
P_0c08f096: /* original f5fc, guest PC 0x0c08f096 */
if(!s->budget--) { s->failed_pc=0x0c08f096u; return 0; }
vf3_matrix_move(s,5,15);
goto P_0c08f098;
P_0c08f098: /* original f6fc, guest PC 0x0c08f098 */
if(!s->budget--) { s->failed_pc=0x0c08f098u; return 0; }
vf3_matrix_move(s,6,15);
goto P_0c08f09a;
P_0c08f09a: /* original 4c0b, guest PC 0x0c08f09a */
if(!s->budget--) { s->failed_pc=0x0c08f09au; return 0; }
target=r[12];
r[16]=code_base|0x0c08f09eu;
vf3_matrix_move(s,4,15);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08f09eu) { target=s->pc; goto dispatch; }
goto P_0c08f09e;
P_0c08f09c: /* original f4fc, guest PC 0x0c08f09c */
if(!s->budget--) { s->failed_pc=0x0c08f09cu; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c08f09e;
P_0c08f09e: /* original 4b0b, guest PC 0x0c08f09e */
if(!s->budget--) { s->failed_pc=0x0c08f09eu; return 0; }
target=r[11];
r[16]=code_base|0x0c08f0a2u;
r[4]=r[9];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08f0a2u) { target=s->pc; goto dispatch; }
goto P_0c08f0a2;
P_0c08f0a0: /* original 6493, guest PC 0x0c08f0a0 */
if(!s->budget--) { s->failed_pc=0x0c08f0a0u; return 0; }
r[4]=r[9];
goto P_0c08f0a2;
P_0c08f0a2: /* original 4a0b, guest PC 0x0c08f0a2 */
if(!s->budget--) { s->failed_pc=0x0c08f0a2u; return 0; }
target=r[10];
r[16]=code_base|0x0c08f0a6u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08f0a6u) { target=s->pc; goto dispatch; }
goto P_0c08f0a6;
P_0c08f0a4: /* original 0009, guest PC 0x0c08f0a4 */
if(!s->budget--) { s->failed_pc=0x0c08f0a4u; return 0; }
goto P_0c08f0a6;
P_0c08f0a6: /* original 9024, guest PC 0x0c08f0a6 */
if(!s->budget--) { s->failed_pc=0x0c08f0a6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08f0f2u,2);
goto P_0c08f0a8;
P_0c08f0a8: /* original f4e6, guest PC 0x0c08f0a8 */
if(!s->budget--) { s->failed_pc=0x0c08f0a8u; return 0; }
vf3_matrix_load(s,ram,4,r[14]+r[0]);
goto P_0c08f0aa;
P_0c08f0aa: /* original 7004, guest PC 0x0c08f0aa */
if(!s->budget--) { s->failed_pc=0x0c08f0aau; return 0; }
r[0]+=0x00000004u;
goto P_0c08f0ac;
P_0c08f0ac: /* original f5e6, guest PC 0x0c08f0ac */
if(!s->budget--) { s->failed_pc=0x0c08f0acu; return 0; }
vf3_matrix_load(s,ram,5,r[14]+r[0]);
goto P_0c08f0ae;
P_0c08f0ae: /* original 7004, guest PC 0x0c08f0ae */
if(!s->budget--) { s->failed_pc=0x0c08f0aeu; return 0; }
r[0]+=0x00000004u;
goto P_0c08f0b0;
P_0c08f0b0: /* original f3e6, guest PC 0x0c08f0b0 */
if(!s->budget--) { s->failed_pc=0x0c08f0b0u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c08f0b2;
P_0c08f0b2: /* original e018, guest PC 0x0c08f0b2 */
if(!s->budget--) { s->failed_pc=0x0c08f0b2u; return 0; }
r[0]=0x00000018u;
goto P_0c08f0b4;
P_0c08f0b4: /* original ff37, guest PC 0x0c08f0b4 */
if(!s->budget--) { s->failed_pc=0x0c08f0b4u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c08f0b6;
P_0c08f0b6: /* original f63c, guest PC 0x0c08f0b6 */
if(!s->budget--) { s->failed_pc=0x0c08f0b6u; return 0; }
vf3_matrix_move(s,6,3);
goto P_0c08f0b8;
P_0c08f0b8: /* original 4d0b, guest PC 0x0c08f0b8 */
if(!s->budget--) { s->failed_pc=0x0c08f0b8u; return 0; }
target=r[13];
r[16]=code_base|0x0c08f0bcu;
fr[6]^=0x80000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08f0bcu) { target=s->pc; goto dispatch; }
goto P_0c08f0bc;
P_0c08f0ba: /* original f64d, guest PC 0x0c08f0ba */
if(!s->budget--) { s->failed_pc=0x0c08f0bau; return 0; }
fr[6]^=0x80000000u;
goto P_0c08f0bc;
P_0c08f0bc: /* original f5fc, guest PC 0x0c08f0bc */
if(!s->budget--) { s->failed_pc=0x0c08f0bcu; return 0; }
vf3_matrix_move(s,5,15);
goto P_0c08f0be;
P_0c08f0be: /* original f6fc, guest PC 0x0c08f0be */
if(!s->budget--) { s->failed_pc=0x0c08f0beu; return 0; }
vf3_matrix_move(s,6,15);
goto P_0c08f0c0;
P_0c08f0c0: /* original 4c0b, guest PC 0x0c08f0c0 */
if(!s->budget--) { s->failed_pc=0x0c08f0c0u; return 0; }
target=r[12];
r[16]=code_base|0x0c08f0c4u;
vf3_matrix_move(s,4,15);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08f0c4u) { target=s->pc; goto dispatch; }
goto P_0c08f0c4;
P_0c08f0c2: /* original f4fc, guest PC 0x0c08f0c2 */
if(!s->budget--) { s->failed_pc=0x0c08f0c2u; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c08f0c4;
P_0c08f0c4: /* original 4b0b, guest PC 0x0c08f0c4 */
if(!s->budget--) { s->failed_pc=0x0c08f0c4u; return 0; }
target=r[11];
r[16]=code_base|0x0c08f0c8u;
r[4]=r[9];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08f0c8u) { target=s->pc; goto dispatch; }
goto P_0c08f0c8;
P_0c08f0c6: /* original 6493, guest PC 0x0c08f0c6 */
if(!s->budget--) { s->failed_pc=0x0c08f0c6u; return 0; }
r[4]=r[9];
goto P_0c08f0c8;
P_0c08f0c8: /* original d313, guest PC 0x0c08f0c8 */
if(!s->budget--) { s->failed_pc=0x0c08f0c8u; return 0; }
r[3]=read(ram,0x0c08f118u,4);
goto P_0c08f0ca;
P_0c08f0ca: /* original 430b, guest PC 0x0c08f0ca */
if(!s->budget--) { s->failed_pc=0x0c08f0cau; return 0; }
target=r[3];
r[16]=code_base|0x0c08f0ceu;
r[4]=0x00000001u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08f0ceu) { target=s->pc; goto dispatch; }
goto P_0c08f0ce;
P_0c08f0cc: /* original e401, guest PC 0x0c08f0cc */
if(!s->budget--) { s->failed_pc=0x0c08f0ccu; return 0; }
r[4]=0x00000001u;
goto P_0c08f0ce;
P_0c08f0ce: /* original 7f24, guest PC 0x0c08f0ce */
if(!s->budget--) { s->failed_pc=0x0c08f0ceu; return 0; }
r[15]+=0x00000024u;
goto P_0c08f0d0;
P_0c08f0d0: /* original 4f26, guest PC 0x0c08f0d0 */
if(!s->budget--) { s->failed_pc=0x0c08f0d0u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c08f0d2;
P_0c08f0d2: /* original fef9, guest PC 0x0c08f0d2 */
if(!s->budget--) { s->failed_pc=0x0c08f0d2u; return 0; }
vf3_matrix_load(s,ram,14,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c08f0d4;
P_0c08f0d4: /* original fff9, guest PC 0x0c08f0d4 */
if(!s->budget--) { s->failed_pc=0x0c08f0d4u; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c08f0d6;
P_0c08f0d6: /* original 68f6, guest PC 0x0c08f0d6 */
if(!s->budget--) { s->failed_pc=0x0c08f0d6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c08f0d8;
P_0c08f0d8: /* original 69f6, guest PC 0x0c08f0d8 */
if(!s->budget--) { s->failed_pc=0x0c08f0d8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c08f0da;
P_0c08f0da: /* original 6af6, guest PC 0x0c08f0da */
if(!s->budget--) { s->failed_pc=0x0c08f0dau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c08f0dc;
P_0c08f0dc: /* original 6bf6, guest PC 0x0c08f0dc */
if(!s->budget--) { s->failed_pc=0x0c08f0dcu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c08f0de;
P_0c08f0de: /* original 6cf6, guest PC 0x0c08f0de */
if(!s->budget--) { s->failed_pc=0x0c08f0deu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c08f0e0;
P_0c08f0e0: /* original 6df6, guest PC 0x0c08f0e0 */
if(!s->budget--) { s->failed_pc=0x0c08f0e0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c08f0e2;
P_0c08f0e2: /* original 000b, guest PC 0x0c08f0e2 */
if(!s->budget--) { s->failed_pc=0x0c08f0e2u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c08f0e4: /* original 6ef6, guest PC 0x0c08f0e4 */
if(!s->budget--) { s->failed_pc=0x0c08f0e4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c08f0e6u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c08f0e6u; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
