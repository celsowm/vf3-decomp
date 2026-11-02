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
int vf3_away_batch250_adapter_10(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c05ee64u: goto P_0c05ee64;
case 0x0c05ee66u: goto P_0c05ee66;
case 0x0c05ee68u: goto P_0c05ee68;
case 0x0c05ee6au: goto P_0c05ee6a;
case 0x0c05ee6cu: goto P_0c05ee6c;
case 0x0c05ee6eu: goto P_0c05ee6e;
case 0x0c05ee70u: goto P_0c05ee70;
case 0x0c05ee72u: goto P_0c05ee72;
case 0x0c05ee74u: goto P_0c05ee74;
case 0x0c05ee76u: goto P_0c05ee76;
case 0x0c05ee78u: goto P_0c05ee78;
case 0x0c05ee7au: goto P_0c05ee7a;
case 0x0c05ee7cu: goto P_0c05ee7c;
case 0x0c05ee7eu: goto P_0c05ee7e;
case 0x0c05ee80u: goto P_0c05ee80;
case 0x0c05ee82u: goto P_0c05ee82;
case 0x0c05ee84u: goto P_0c05ee84;
case 0x0c05ee86u: goto P_0c05ee86;
case 0x0c05ee88u: goto P_0c05ee88;
case 0x0c05ee8au: goto P_0c05ee8a;
case 0x0c05ee8cu: goto P_0c05ee8c;
case 0x0c05ee8eu: goto P_0c05ee8e;
case 0x0c05ee90u: goto P_0c05ee90;
case 0x0c05ee92u: goto P_0c05ee92;
case 0x0c05ee94u: goto P_0c05ee94;
case 0x0c05ee96u: goto P_0c05ee96;
case 0x0c05ee98u: goto P_0c05ee98;
case 0x0c05ee9au: goto P_0c05ee9a;
case 0x0c05ee9cu: goto P_0c05ee9c;
case 0x0c05ee9eu: goto P_0c05ee9e;
case 0x0c05eea0u: goto P_0c05eea0;
case 0x0c05eea2u: goto P_0c05eea2;
case 0x0c05eea4u: goto P_0c05eea4;
case 0x0c05eea6u: goto P_0c05eea6;
case 0x0c05eea8u: goto P_0c05eea8;
case 0x0c05eeaau: goto P_0c05eeaa;
case 0x0c05eeacu: goto P_0c05eeac;
case 0x0c05eeaeu: goto P_0c05eeae;
case 0x0c05eeb0u: goto P_0c05eeb0;
case 0x0c05eeb2u: goto P_0c05eeb2;
case 0x0c05eeb4u: goto P_0c05eeb4;
case 0x0c05eeb6u: goto P_0c05eeb6;
case 0x0c05eeb8u: goto P_0c05eeb8;
case 0x0c05eebau: goto P_0c05eeba;
case 0x0c05eebcu: goto P_0c05eebc;
case 0x0c05eebeu: goto P_0c05eebe;
case 0x0c05eec0u: goto P_0c05eec0;
case 0x0c05eec2u: goto P_0c05eec2;
case 0x0c05eec4u: goto P_0c05eec4;
case 0x0c05eec6u: goto P_0c05eec6;
case 0x0c05eec8u: goto P_0c05eec8;
case 0x0c05eecau: goto P_0c05eeca;
case 0x0c05eeccu: goto P_0c05eecc;
case 0x0c05eeceu: goto P_0c05eece;
case 0x0c05eed0u: goto P_0c05eed0;
case 0x0c05eed2u: goto P_0c05eed2;
case 0x0c05eed4u: goto P_0c05eed4;
case 0x0c05eed6u: goto P_0c05eed6;
case 0x0c05eed8u: goto P_0c05eed8;
case 0x0c05eedau: goto P_0c05eeda;
case 0x0c05eedcu: goto P_0c05eedc;
case 0x0c05eedeu: goto P_0c05eede;
case 0x0c05eee0u: goto P_0c05eee0;
case 0x0c05eee2u: goto P_0c05eee2;
case 0x0c05eee4u: goto P_0c05eee4;
case 0x0c05eee6u: goto P_0c05eee6;
case 0x0c05eee8u: goto P_0c05eee8;
case 0x0c05eeeau: goto P_0c05eeea;
case 0x0c05eeecu: goto P_0c05eeec;
case 0x0c05eeeeu: goto P_0c05eeee;
case 0x0c05eef0u: goto P_0c05eef0;
case 0x0c05eef2u: goto P_0c05eef2;
case 0x0c05eef4u: goto P_0c05eef4;
case 0x0c05eef6u: goto P_0c05eef6;
case 0x0c05eef8u: goto P_0c05eef8;
case 0x0c05eefau: goto P_0c05eefa;
case 0x0c05eefcu: goto P_0c05eefc;
case 0x0c05eefeu: goto P_0c05eefe;
case 0x0c05ef00u: goto P_0c05ef00;
case 0x0c05ef02u: goto P_0c05ef02;
case 0x0c05ef04u: goto P_0c05ef04;
case 0x0c05ef06u: goto P_0c05ef06;
case 0x0c05ef08u: goto P_0c05ef08;
case 0x0c05ef0au: goto P_0c05ef0a;
case 0x0c05ef0cu: goto P_0c05ef0c;
case 0x0c05ef0eu: goto P_0c05ef0e;
case 0x0c05ef10u: goto P_0c05ef10;
case 0x0c05ef40u: goto P_0c05ef40;
case 0x0c05ef42u: goto P_0c05ef42;
case 0x0c05ef44u: goto P_0c05ef44;
case 0x0c05ef46u: goto P_0c05ef46;
case 0x0c05ef48u: goto P_0c05ef48;
case 0x0c05ef4au: goto P_0c05ef4a;
case 0x0c05ef4cu: goto P_0c05ef4c;
case 0x0c05ef4eu: goto P_0c05ef4e;
case 0x0c05ef50u: goto P_0c05ef50;
case 0x0c05ef52u: goto P_0c05ef52;
case 0x0c05ef54u: goto P_0c05ef54;
case 0x0c05ef56u: goto P_0c05ef56;
case 0x0c05ef58u: goto P_0c05ef58;
case 0x0c05ef5au: goto P_0c05ef5a;
case 0x0c05ef5cu: goto P_0c05ef5c;
case 0x0c05ef5eu: goto P_0c05ef5e;
case 0x0c05ef60u: goto P_0c05ef60;
case 0x0c05ef62u: goto P_0c05ef62;
case 0x0c05ef64u: goto P_0c05ef64;
case 0x0c05ef66u: goto P_0c05ef66;
case 0x0c05ef68u: goto P_0c05ef68;
case 0x0c05ef6au: goto P_0c05ef6a;
case 0x0c05ef6cu: goto P_0c05ef6c;
case 0x0c05ef6eu: goto P_0c05ef6e;
case 0x0c05ef70u: goto P_0c05ef70;
case 0x0c05ef72u: goto P_0c05ef72;
case 0x0c05ef74u: goto P_0c05ef74;
case 0x0c05ef76u: goto P_0c05ef76;
case 0x0c05ef78u: goto P_0c05ef78;
case 0x0c05ef7au: goto P_0c05ef7a;
case 0x0c05ef7cu: goto P_0c05ef7c;
case 0x0c05ef7eu: goto P_0c05ef7e;
case 0x0c05ef80u: goto P_0c05ef80;
case 0x0c05ef82u: goto P_0c05ef82;
case 0x0c05ef84u: goto P_0c05ef84;
case 0x0c05ef86u: goto P_0c05ef86;
case 0x0c05ef88u: goto P_0c05ef88;
case 0x0c05ef8au: goto P_0c05ef8a;
case 0x0c05ef8cu: goto P_0c05ef8c;
case 0x0c05ef8eu: goto P_0c05ef8e;
case 0x0c05ef90u: goto P_0c05ef90;
case 0x0c05ef92u: goto P_0c05ef92;
case 0x0c05ef94u: goto P_0c05ef94;
case 0x0c05ef96u: goto P_0c05ef96;
case 0x0c05ef98u: goto P_0c05ef98;
case 0x0c05ef9au: goto P_0c05ef9a;
case 0x0c05ef9cu: goto P_0c05ef9c;
case 0x0c05ef9eu: goto P_0c05ef9e;
case 0x0c05efa0u: goto P_0c05efa0;
case 0x0c05efa2u: goto P_0c05efa2;
case 0x0c05efa4u: goto P_0c05efa4;
case 0x0c05efa6u: goto P_0c05efa6;
case 0x0c05efa8u: goto P_0c05efa8;
case 0x0c05efaau: goto P_0c05efaa;
case 0x0c05efacu: goto P_0c05efac;
case 0x0c05efaeu: goto P_0c05efae;
case 0x0c05efb0u: goto P_0c05efb0;
case 0x0c05efb2u: goto P_0c05efb2;
case 0x0c05efb4u: goto P_0c05efb4;
case 0x0c05efb6u: goto P_0c05efb6;
case 0x0c05efb8u: goto P_0c05efb8;
case 0x0c05efbau: goto P_0c05efba;
case 0x0c05efbcu: goto P_0c05efbc;
case 0x0c05efbeu: goto P_0c05efbe;
case 0x0c05efc0u: goto P_0c05efc0;
case 0x0c05efc2u: goto P_0c05efc2;
case 0x0c05efc4u: goto P_0c05efc4;
case 0x0c05efc6u: goto P_0c05efc6;
case 0x0c05efc8u: goto P_0c05efc8;
case 0x0c05efcau: goto P_0c05efca;
case 0x0c05efccu: goto P_0c05efcc;
case 0x0c05efceu: goto P_0c05efce;
case 0x0c05efd0u: goto P_0c05efd0;
case 0x0c05efd2u: goto P_0c05efd2;
case 0x0c05efd4u: goto P_0c05efd4;
case 0x0c05efd6u: goto P_0c05efd6;
case 0x0c05efd8u: goto P_0c05efd8;
case 0x0c05efdau: goto P_0c05efda;
case 0x0c05efdcu: goto P_0c05efdc;
case 0x0c05efdeu: goto P_0c05efde;
case 0x0c05efe0u: goto P_0c05efe0;
case 0x0c05efe2u: goto P_0c05efe2;
case 0x0c05efe4u: goto P_0c05efe4;
case 0x0c05efe6u: goto P_0c05efe6;
case 0x0c05efe8u: goto P_0c05efe8;
case 0x0c05efeau: goto P_0c05efea;
case 0x0c05efecu: goto P_0c05efec;
case 0x0c05efeeu: goto P_0c05efee;
case 0x0c05eff0u: goto P_0c05eff0;
case 0x0c05eff2u: goto P_0c05eff2;
case 0x0c05eff4u: goto P_0c05eff4;
case 0x0c05eff6u: goto P_0c05eff6;
case 0x0c05eff8u: goto P_0c05eff8;
case 0x0c05effau: goto P_0c05effa;
case 0x0c05f018u: goto P_0c05f018;
case 0x0c05f01au: goto P_0c05f01a;
case 0x0c05f01cu: goto P_0c05f01c;
case 0x0c05f01eu: goto P_0c05f01e;
case 0x0c05f020u: goto P_0c05f020;
case 0x0c05f022u: goto P_0c05f022;
case 0x0c05f024u: goto P_0c05f024;
case 0x0c05f026u: goto P_0c05f026;
case 0x0c05f028u: goto P_0c05f028;
case 0x0c05f02au: goto P_0c05f02a;
case 0x0c05f02cu: goto P_0c05f02c;
case 0x0c05f02eu: goto P_0c05f02e;
case 0x0c05f030u: goto P_0c05f030;
case 0x0c05f032u: goto P_0c05f032;
case 0x0c05f034u: goto P_0c05f034;
case 0x0c05f036u: goto P_0c05f036;
case 0x0c05f038u: goto P_0c05f038;
case 0x0c05f03au: goto P_0c05f03a;
case 0x0c05f03cu: goto P_0c05f03c;
case 0x0c05f03eu: goto P_0c05f03e;
case 0x0c05f040u: goto P_0c05f040;
case 0x0c05f042u: goto P_0c05f042;
case 0x0c05f044u: goto P_0c05f044;
case 0x0c05f046u: goto P_0c05f046;
case 0x0c05f048u: goto P_0c05f048;
case 0x0c05f04au: goto P_0c05f04a;
case 0x0c05f04cu: goto P_0c05f04c;
case 0x0c05f04eu: goto P_0c05f04e;
case 0x0c05f050u: goto P_0c05f050;
case 0x0c05f052u: goto P_0c05f052;
case 0x0c05f054u: goto P_0c05f054;
case 0x0c05f056u: goto P_0c05f056;
case 0x0c05f058u: goto P_0c05f058;
case 0x0c05f05au: goto P_0c05f05a;
case 0x0c05f05cu: goto P_0c05f05c;
case 0x0c05f05eu: goto P_0c05f05e;
case 0x0c05f060u: goto P_0c05f060;
case 0x0c05f062u: goto P_0c05f062;
case 0x0c05f064u: goto P_0c05f064;
case 0x0c05f066u: goto P_0c05f066;
case 0x0c05f068u: goto P_0c05f068;
case 0x0c05f06au: goto P_0c05f06a;
case 0x0c05f06cu: goto P_0c05f06c;
case 0x0c05f06eu: goto P_0c05f06e;
case 0x0c05f070u: goto P_0c05f070;
case 0x0c05f072u: goto P_0c05f072;
case 0x0c05f074u: goto P_0c05f074;
case 0x0c05f076u: goto P_0c05f076;
case 0x0c05f078u: goto P_0c05f078;
case 0x0c05f07au: goto P_0c05f07a;
case 0x0c05f07cu: goto P_0c05f07c;
case 0x0c05f07eu: goto P_0c05f07e;
case 0x0c05f080u: goto P_0c05f080;
case 0x0c05f082u: goto P_0c05f082;
case 0x0c05f084u: goto P_0c05f084;
case 0x0c05f086u: goto P_0c05f086;
case 0x0c05f088u: goto P_0c05f088;
case 0x0c05f08au: goto P_0c05f08a;
case 0x0c05f08cu: goto P_0c05f08c;
case 0x0c05f08eu: goto P_0c05f08e;
case 0x0c05f090u: goto P_0c05f090;
case 0x0c05f092u: goto P_0c05f092;
case 0x0c05f094u: goto P_0c05f094;
case 0x0c05f096u: goto P_0c05f096;
case 0x0c05f098u: goto P_0c05f098;
case 0x0c05f09au: goto P_0c05f09a;
case 0x0c05f09cu: goto P_0c05f09c;
default: return vf3_matrix_family(target,s,ram);
}
P_0c05ee64: /* original 2fe6, guest PC 0x0c05ee64 */
if(!s->budget--) { s->failed_pc=0x0c05ee64u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05ee66;
P_0c05ee66: /* original 2fd6, guest PC 0x0c05ee66 */
if(!s->budget--) { s->failed_pc=0x0c05ee66u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05ee68;
P_0c05ee68: /* original 2fc6, guest PC 0x0c05ee68 */
if(!s->budget--) { s->failed_pc=0x0c05ee68u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05ee6a;
P_0c05ee6a: /* original ed00, guest PC 0x0c05ee6a */
if(!s->budget--) { s->failed_pc=0x0c05ee6au; return 0; }
r[13]=0x00000000u;
goto P_0c05ee6c;
P_0c05ee6c: /* original de2c, guest PC 0x0c05ee6c */
if(!s->budget--) { s->failed_pc=0x0c05ee6cu; return 0; }
r[14]=read(ram,0x0c05ef20u,4);
goto P_0c05ee6e;
P_0c05ee6e: /* original 4f22, guest PC 0x0c05ee6e */
if(!s->budget--) { s->failed_pc=0x0c05ee6eu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c05ee70;
P_0c05ee70: /* original 934f, guest PC 0x0c05ee70 */
if(!s->budget--) { s->failed_pc=0x0c05ee70u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c05ef12u,2);
goto P_0c05ee72;
P_0c05ee72: /* original 7ffc, guest PC 0x0c05ee72 */
if(!s->budget--) { s->failed_pc=0x0c05ee72u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c05ee74;
P_0c05ee74: /* original 2e79, guest PC 0x0c05ee74 */
if(!s->budget--) { s->failed_pc=0x0c05ee74u; return 0; }
r[14]&=r[7];
goto P_0c05ee76;
P_0c05ee76: /* original 677c, guest PC 0x0c05ee76 */
if(!s->budget--) { s->failed_pc=0x0c05ee76u; return 0; }
r[7]=r[7]&255u;
goto P_0c05ee78;
P_0c05ee78: /* original 2f72, guest PC 0x0c05ee78 */
if(!s->budget--) { s->failed_pc=0x0c05ee78u; return 0; }
write(ram,r[15],r[7],4);
goto P_0c05ee7a;
P_0c05ee7a: /* original 3e30, guest PC 0x0c05ee7a */
if(!s->budget--) { s->failed_pc=0x0c05ee7au; return 0; }
r[17]=(r[17]&~1u)|((r[14]==r[3])!=0);
goto P_0c05ee7c;
P_0c05ee7c: /* original 8d03, guest PC 0x0c05ee7c */
if(!s->budget--) { s->failed_pc=0x0c05ee7cu; return 0; }
cond=r[17]&1u;
r[12]=0x00000003u;
if(cond) { goto P_0c05ee86; }
goto P_0c05ee80;
P_0c05ee7e: /* original ec03, guest PC 0x0c05ee7e */
if(!s->budget--) { s->failed_pc=0x0c05ee7eu; return 0; }
r[12]=0x00000003u;
goto P_0c05ee80;
P_0c05ee80: /* original 9148, guest PC 0x0c05ee80 */
if(!s->budget--) { s->failed_pc=0x0c05ee80u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c05ef14u,2);
goto P_0c05ee82;
P_0c05ee82: /* original 3e10, guest PC 0x0c05ee82 */
if(!s->budget--) { s->failed_pc=0x0c05ee82u; return 0; }
r[17]=(r[17]&~1u)|((r[14]==r[1])!=0);
goto P_0c05ee84;
P_0c05ee84: /* original 8b01, guest PC 0x0c05ee84 */
if(!s->budget--) { s->failed_pc=0x0c05ee84u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c05ee8a; }
goto P_0c05ee86;
P_0c05ee86: /* original a002, guest PC 0x0c05ee86 */
if(!s->budget--) { s->failed_pc=0x0c05ee86u; return 0; }
write(ram,r[4],r[12],4);
goto P_0c05ee8e;
P_0c05ee88: /* original 24c2, guest PC 0x0c05ee88 */
if(!s->budget--) { s->failed_pc=0x0c05ee88u; return 0; }
write(ram,r[4],r[12],4);
goto P_0c05ee8a;
P_0c05ee8a: /* original e202, guest PC 0x0c05ee8a */
if(!s->budget--) { s->failed_pc=0x0c05ee8au; return 0; }
r[2]=0x00000002u;
goto P_0c05ee8c;
P_0c05ee8c: /* original 2422, guest PC 0x0c05ee8c */
if(!s->budget--) { s->failed_pc=0x0c05ee8cu; return 0; }
write(ram,r[4],r[2],4);
goto P_0c05ee8e;
P_0c05ee8e: /* original 9342, guest PC 0x0c05ee8e */
if(!s->budget--) { s->failed_pc=0x0c05ee8eu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c05ef16u,2);
goto P_0c05ee90;
P_0c05ee90: /* original 3e30, guest PC 0x0c05ee90 */
if(!s->budget--) { s->failed_pc=0x0c05ee90u; return 0; }
r[17]=(r[17]&~1u)|((r[14]==r[3])!=0);
goto P_0c05ee92;
P_0c05ee92: /* original 8d03, guest PC 0x0c05ee92 */
if(!s->budget--) { s->failed_pc=0x0c05ee92u; return 0; }
cond=r[17]&1u;
r[7]=0x00000001u;
if(cond) { goto P_0c05ee9c; }
goto P_0c05ee96;
P_0c05ee94: /* original e701, guest PC 0x0c05ee94 */
if(!s->budget--) { s->failed_pc=0x0c05ee94u; return 0; }
r[7]=0x00000001u;
goto P_0c05ee96;
P_0c05ee96: /* original 913f, guest PC 0x0c05ee96 */
if(!s->budget--) { s->failed_pc=0x0c05ee96u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c05ef18u,2);
goto P_0c05ee98;
P_0c05ee98: /* original 3e10, guest PC 0x0c05ee98 */
if(!s->budget--) { s->failed_pc=0x0c05ee98u; return 0; }
r[17]=(r[17]&~1u)|((r[14]==r[1])!=0);
goto P_0c05ee9a;
P_0c05ee9a: /* original 8b0b, guest PC 0x0c05ee9a */
if(!s->budget--) { s->failed_pc=0x0c05ee9au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c05eeb4; }
goto P_0c05ee9c;
P_0c05ee9c: /* original d321, guest PC 0x0c05ee9c */
if(!s->budget--) { s->failed_pc=0x0c05ee9cu; return 0; }
r[3]=read(ram,0x0c05ef24u,4);
goto P_0c05ee9e;
P_0c05ee9e: /* original 6032, guest PC 0x0c05ee9e */
if(!s->budget--) { s->failed_pc=0x0c05ee9eu; return 0; }
tmp=read(ram,r[3],4);
r[0]=tmp;
goto P_0c05eea0;
P_0c05eea0: /* original 913b, guest PC 0x0c05eea0 */
if(!s->budget--) { s->failed_pc=0x0c05eea0u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c05ef1au,2);
goto P_0c05eea2;
P_0c05eea2: /* original 001e, guest PC 0x0c05eea2 */
if(!s->budget--) { s->failed_pc=0x0c05eea2u; return 0; }
r[0]=read(ram,r[1]+r[0],4);
goto P_0c05eea4;
P_0c05eea4: /* original 8803, guest PC 0x0c05eea4 */
if(!s->budget--) { s->failed_pc=0x0c05eea4u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000003u)!=0);
goto P_0c05eea6;
P_0c05eea6: /* original 8b01, guest PC 0x0c05eea6 */
if(!s->budget--) { s->failed_pc=0x0c05eea6u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c05eeac; }
goto P_0c05eea8;
P_0c05eea8: /* original a001, guest PC 0x0c05eea8 */
if(!s->budget--) { s->failed_pc=0x0c05eea8u; return 0; }
write(ram,r[4]+4,r[12],4);
goto P_0c05eeae;
P_0c05eeaa: /* original 14c1, guest PC 0x0c05eeaa */
if(!s->budget--) { s->failed_pc=0x0c05eeaau; return 0; }
write(ram,r[4]+4,r[12],4);
goto P_0c05eeac;
P_0c05eeac: /* original 1471, guest PC 0x0c05eeac */
if(!s->budget--) { s->failed_pc=0x0c05eeacu; return 0; }
write(ram,r[4]+4,r[7],4);
goto P_0c05eeae;
P_0c05eeae: /* original d31e, guest PC 0x0c05eeae */
if(!s->budget--) { s->failed_pc=0x0c05eeaeu; return 0; }
r[3]=read(ram,0x0c05ef28u,4);
goto P_0c05eeb0;
P_0c05eeb0: /* original a021, guest PC 0x0c05eeb0 */
if(!s->budget--) { s->failed_pc=0x0c05eeb0u; return 0; }
goto P_0c05eef6;
P_0c05eeb2: /* original 0009, guest PC 0x0c05eeb2 */
if(!s->budget--) { s->failed_pc=0x0c05eeb2u; return 0; }
goto P_0c05eeb4;
P_0c05eeb4: /* original 9132, guest PC 0x0c05eeb4 */
if(!s->budget--) { s->failed_pc=0x0c05eeb4u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c05ef1cu,2);
goto P_0c05eeb6;
P_0c05eeb6: /* original 3e10, guest PC 0x0c05eeb6 */
if(!s->budget--) { s->failed_pc=0x0c05eeb6u; return 0; }
r[17]=(r[17]&~1u)|((r[14]==r[1])!=0);
goto P_0c05eeb8;
P_0c05eeb8: /* original 8902, guest PC 0x0c05eeb8 */
if(!s->budget--) { s->failed_pc=0x0c05eeb8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05eec0; }
goto P_0c05eeba;
P_0c05eeba: /* original 9230, guest PC 0x0c05eeba */
if(!s->budget--) { s->failed_pc=0x0c05eebau; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c05ef1eu,2);
goto P_0c05eebc;
P_0c05eebc: /* original 3e20, guest PC 0x0c05eebc */
if(!s->budget--) { s->failed_pc=0x0c05eebcu; return 0; }
r[17]=(r[17]&~1u)|((r[14]==r[2])!=0);
goto P_0c05eebe;
P_0c05eebe: /* original 8b0b, guest PC 0x0c05eebe */
if(!s->budget--) { s->failed_pc=0x0c05eebeu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c05eed8; }
goto P_0c05eec0;
P_0c05eec0: /* original d318, guest PC 0x0c05eec0 */
if(!s->budget--) { s->failed_pc=0x0c05eec0u; return 0; }
r[3]=read(ram,0x0c05ef24u,4);
goto P_0c05eec2;
P_0c05eec2: /* original 6032, guest PC 0x0c05eec2 */
if(!s->budget--) { s->failed_pc=0x0c05eec2u; return 0; }
tmp=read(ram,r[3],4);
r[0]=tmp;
goto P_0c05eec4;
P_0c05eec4: /* original 9129, guest PC 0x0c05eec4 */
if(!s->budget--) { s->failed_pc=0x0c05eec4u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c05ef1au,2);
goto P_0c05eec6;
P_0c05eec6: /* original 001e, guest PC 0x0c05eec6 */
if(!s->budget--) { s->failed_pc=0x0c05eec6u; return 0; }
r[0]=read(ram,r[1]+r[0],4);
goto P_0c05eec8;
P_0c05eec8: /* original 8803, guest PC 0x0c05eec8 */
if(!s->budget--) { s->failed_pc=0x0c05eec8u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000003u)!=0);
goto P_0c05eeca;
P_0c05eeca: /* original 8b01, guest PC 0x0c05eeca */
if(!s->budget--) { s->failed_pc=0x0c05eecau; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c05eed0; }
goto P_0c05eecc;
P_0c05eecc: /* original a001, guest PC 0x0c05eecc */
if(!s->budget--) { s->failed_pc=0x0c05eeccu; return 0; }
write(ram,r[4]+4,r[12],4);
goto P_0c05eed2;
P_0c05eece: /* original 14c1, guest PC 0x0c05eece */
if(!s->budget--) { s->failed_pc=0x0c05eeceu; return 0; }
write(ram,r[4]+4,r[12],4);
goto P_0c05eed0;
P_0c05eed0: /* original 1471, guest PC 0x0c05eed0 */
if(!s->budget--) { s->failed_pc=0x0c05eed0u; return 0; }
write(ram,r[4]+4,r[7],4);
goto P_0c05eed2;
P_0c05eed2: /* original d316, guest PC 0x0c05eed2 */
if(!s->budget--) { s->failed_pc=0x0c05eed2u; return 0; }
r[3]=read(ram,0x0c05ef2cu,4);
goto P_0c05eed4;
P_0c05eed4: /* original a00f, guest PC 0x0c05eed4 */
if(!s->budget--) { s->failed_pc=0x0c05eed4u; return 0; }
goto P_0c05eef6;
P_0c05eed6: /* original 0009, guest PC 0x0c05eed6 */
if(!s->budget--) { s->failed_pc=0x0c05eed6u; return 0; }
goto P_0c05eed8;
P_0c05eed8: /* original 1471, guest PC 0x0c05eed8 */
if(!s->budget--) { s->failed_pc=0x0c05eed8u; return 0; }
write(ram,r[4]+4,r[7],4);
goto P_0c05eeda;
P_0c05eeda: /* original 60f2, guest PC 0x0c05eeda */
if(!s->budget--) { s->failed_pc=0x0c05eedau; return 0; }
tmp=read(ram,r[15],4);
r[0]=tmp;
goto P_0c05eedc;
P_0c05eedc: /* original 8800, guest PC 0x0c05eedc */
if(!s->budget--) { s->failed_pc=0x0c05eedcu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000000u)!=0);
goto P_0c05eede;
P_0c05eede: /* original 8909, guest PC 0x0c05eede */
if(!s->budget--) { s->failed_pc=0x0c05eedeu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05eef4; }
goto P_0c05eee0;
P_0c05eee0: /* original 8801, guest PC 0x0c05eee0 */
if(!s->budget--) { s->failed_pc=0x0c05eee0u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c05eee2;
P_0c05eee2: /* original 890a, guest PC 0x0c05eee2 */
if(!s->budget--) { s->failed_pc=0x0c05eee2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05eefa; }
goto P_0c05eee4;
P_0c05eee4: /* original 8802, guest PC 0x0c05eee4 */
if(!s->budget--) { s->failed_pc=0x0c05eee4u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c05eee6;
P_0c05eee6: /* original 890b, guest PC 0x0c05eee6 */
if(!s->budget--) { s->failed_pc=0x0c05eee6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05ef00; }
goto P_0c05eee8;
P_0c05eee8: /* original 8803, guest PC 0x0c05eee8 */
if(!s->budget--) { s->failed_pc=0x0c05eee8u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000003u)!=0);
goto P_0c05eeea;
P_0c05eeea: /* original 890c, guest PC 0x0c05eeea */
if(!s->budget--) { s->failed_pc=0x0c05eeeau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05ef06; }
goto P_0c05eeec;
P_0c05eeec: /* original 8804, guest PC 0x0c05eeec */
if(!s->budget--) { s->failed_pc=0x0c05eeecu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000004u)!=0);
goto P_0c05eeee;
P_0c05eeee: /* original 890d, guest PC 0x0c05eeee */
if(!s->budget--) { s->failed_pc=0x0c05eeeeu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05ef0c; }
goto P_0c05eef0;
P_0c05eef0: /* original a026, guest PC 0x0c05eef0 */
if(!s->budget--) { s->failed_pc=0x0c05eef0u; return 0; }
goto P_0c05ef40;
P_0c05eef2: /* original 0009, guest PC 0x0c05eef2 */
if(!s->budget--) { s->failed_pc=0x0c05eef2u; return 0; }
goto P_0c05eef4;
P_0c05eef4: /* original e300, guest PC 0x0c05eef4 */
if(!s->budget--) { s->failed_pc=0x0c05eef4u; return 0; }
r[3]=0x00000000u;
goto P_0c05eef6;
P_0c05eef6: /* original a024, guest PC 0x0c05eef6 */
if(!s->budget--) { s->failed_pc=0x0c05eef6u; return 0; }
write(ram,r[4]+8,r[3],4);
goto P_0c05ef42;
P_0c05eef8: /* original 1432, guest PC 0x0c05eef8 */
if(!s->budget--) { s->failed_pc=0x0c05eef8u; return 0; }
write(ram,r[4]+8,r[3],4);
goto P_0c05eefa;
P_0c05eefa: /* original d10d, guest PC 0x0c05eefa */
if(!s->budget--) { s->failed_pc=0x0c05eefau; return 0; }
r[1]=read(ram,0x0c05ef30u,4);
goto P_0c05eefc;
P_0c05eefc: /* original a004, guest PC 0x0c05eefc */
if(!s->budget--) { s->failed_pc=0x0c05eefcu; return 0; }
goto P_0c05ef08;
P_0c05eefe: /* original 0009, guest PC 0x0c05eefe */
if(!s->budget--) { s->failed_pc=0x0c05eefeu; return 0; }
goto P_0c05ef00;
P_0c05ef00: /* original d20c, guest PC 0x0c05ef00 */
if(!s->budget--) { s->failed_pc=0x0c05ef00u; return 0; }
r[2]=read(ram,0x0c05ef34u,4);
goto P_0c05ef02;
P_0c05ef02: /* original a004, guest PC 0x0c05ef02 */
if(!s->budget--) { s->failed_pc=0x0c05ef02u; return 0; }
goto P_0c05ef0e;
P_0c05ef04: /* original 0009, guest PC 0x0c05ef04 */
if(!s->budget--) { s->failed_pc=0x0c05ef04u; return 0; }
goto P_0c05ef06;
P_0c05ef06: /* original d10c, guest PC 0x0c05ef06 */
if(!s->budget--) { s->failed_pc=0x0c05ef06u; return 0; }
r[1]=read(ram,0x0c05ef38u,4);
goto P_0c05ef08;
P_0c05ef08: /* original a01b, guest PC 0x0c05ef08 */
if(!s->budget--) { s->failed_pc=0x0c05ef08u; return 0; }
write(ram,r[4]+8,r[1],4);
goto P_0c05ef42;
P_0c05ef0a: /* original 1412, guest PC 0x0c05ef0a */
if(!s->budget--) { s->failed_pc=0x0c05ef0au; return 0; }
write(ram,r[4]+8,r[1],4);
goto P_0c05ef0c;
P_0c05ef0c: /* original d20b, guest PC 0x0c05ef0c */
if(!s->budget--) { s->failed_pc=0x0c05ef0cu; return 0; }
r[2]=read(ram,0x0c05ef3cu,4);
goto P_0c05ef0e;
P_0c05ef0e: /* original a018, guest PC 0x0c05ef0e */
if(!s->budget--) { s->failed_pc=0x0c05ef0eu; return 0; }
write(ram,r[4]+8,r[2],4);
goto P_0c05ef42;
P_0c05ef10: /* original 1422, guest PC 0x0c05ef10 */
if(!s->budget--) { s->failed_pc=0x0c05ef10u; return 0; }
write(ram,r[4]+8,r[2],4);
if(!vf3_matrix_family(0x0c05ef12u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c05ef12u; return 0; } return 1;
P_0c05ef40: /* original ed04, guest PC 0x0c05ef40 */
if(!s->budget--) { s->failed_pc=0x0c05ef40u; return 0; }
r[13]=0x00000004u;
goto P_0c05ef42;
P_0c05ef42: /* original 1453, guest PC 0x0c05ef42 */
if(!s->budget--) { s->failed_pc=0x0c05ef42u; return 0; }
write(ram,r[4]+12,r[5],4);
goto P_0c05ef44;
P_0c05ef44: /* original 6053, guest PC 0x0c05ef44 */
if(!s->budget--) { s->failed_pc=0x0c05ef44u; return 0; }
r[0]=r[5];
goto P_0c05ef46;
P_0c05ef46: /* original 0009, guest PC 0x0c05ef46 */
if(!s->budget--) { s->failed_pc=0x0c05ef46u; return 0; }
goto P_0c05ef48;
P_0c05ef48: /* original 8808, guest PC 0x0c05ef48 */
if(!s->budget--) { s->failed_pc=0x0c05ef48u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000008u)!=0);
goto P_0c05ef4a;
P_0c05ef4a: /* original 8d13, guest PC 0x0c05ef4a */
if(!s->budget--) { s->failed_pc=0x0c05ef4au; return 0; }
cond=r[17]&1u;
write(ram,r[4]+16,r[6],4);
if(cond) { goto P_0c05ef74; }
goto P_0c05ef4e;
P_0c05ef4c: /* original 1464, guest PC 0x0c05ef4c */
if(!s->budget--) { s->failed_pc=0x0c05ef4cu; return 0; }
write(ram,r[4]+16,r[6],4);
goto P_0c05ef4e;
P_0c05ef4e: /* original 8810, guest PC 0x0c05ef4e */
if(!s->budget--) { s->failed_pc=0x0c05ef4eu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000010u)!=0);
goto P_0c05ef50;
P_0c05ef50: /* original 8910, guest PC 0x0c05ef50 */
if(!s->budget--) { s->failed_pc=0x0c05ef50u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05ef74; }
goto P_0c05ef52;
P_0c05ef52: /* original 8820, guest PC 0x0c05ef52 */
if(!s->budget--) { s->failed_pc=0x0c05ef52u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000020u)!=0);
goto P_0c05ef54;
P_0c05ef54: /* original 890e, guest PC 0x0c05ef54 */
if(!s->budget--) { s->failed_pc=0x0c05ef54u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05ef74; }
goto P_0c05ef56;
P_0c05ef56: /* original 8840, guest PC 0x0c05ef56 */
if(!s->budget--) { s->failed_pc=0x0c05ef56u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000040u)!=0);
goto P_0c05ef58;
P_0c05ef58: /* original 890c, guest PC 0x0c05ef58 */
if(!s->budget--) { s->failed_pc=0x0c05ef58u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05ef74; }
goto P_0c05ef5a;
P_0c05ef5a: /* original 914f, guest PC 0x0c05ef5a */
if(!s->budget--) { s->failed_pc=0x0c05ef5au; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c05effcu,2);
goto P_0c05ef5c;
P_0c05ef5c: /* original 3010, guest PC 0x0c05ef5c */
if(!s->budget--) { s->failed_pc=0x0c05ef5cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==r[1])!=0);
goto P_0c05ef5e;
P_0c05ef5e: /* original 8909, guest PC 0x0c05ef5e */
if(!s->budget--) { s->failed_pc=0x0c05ef5eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05ef74; }
goto P_0c05ef60;
P_0c05ef60: /* original 914d, guest PC 0x0c05ef60 */
if(!s->budget--) { s->failed_pc=0x0c05ef60u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c05effeu,2);
goto P_0c05ef62;
P_0c05ef62: /* original 3010, guest PC 0x0c05ef62 */
if(!s->budget--) { s->failed_pc=0x0c05ef62u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==r[1])!=0);
goto P_0c05ef64;
P_0c05ef64: /* original 8906, guest PC 0x0c05ef64 */
if(!s->budget--) { s->failed_pc=0x0c05ef64u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05ef74; }
goto P_0c05ef66;
P_0c05ef66: /* original 914b, guest PC 0x0c05ef66 */
if(!s->budget--) { s->failed_pc=0x0c05ef66u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c05f000u,2);
goto P_0c05ef68;
P_0c05ef68: /* original 3010, guest PC 0x0c05ef68 */
if(!s->budget--) { s->failed_pc=0x0c05ef68u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==r[1])!=0);
goto P_0c05ef6a;
P_0c05ef6a: /* original 8903, guest PC 0x0c05ef6a */
if(!s->budget--) { s->failed_pc=0x0c05ef6au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05ef74; }
goto P_0c05ef6c;
P_0c05ef6c: /* original 9149, guest PC 0x0c05ef6c */
if(!s->budget--) { s->failed_pc=0x0c05ef6cu; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c05f002u,2);
goto P_0c05ef6e;
P_0c05ef6e: /* original 3010, guest PC 0x0c05ef6e */
if(!s->budget--) { s->failed_pc=0x0c05ef6eu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==r[1])!=0);
goto P_0c05ef70;
P_0c05ef70: /* original 8900, guest PC 0x0c05ef70 */
if(!s->budget--) { s->failed_pc=0x0c05ef70u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05ef74; }
goto P_0c05ef72;
P_0c05ef72: /* original ed04, guest PC 0x0c05ef72 */
if(!s->budget--) { s->failed_pc=0x0c05ef72u; return 0; }
r[13]=0x00000004u;
goto P_0c05ef74;
P_0c05ef74: /* original 6063, guest PC 0x0c05ef74 */
if(!s->budget--) { s->failed_pc=0x0c05ef74u; return 0; }
r[0]=r[6];
goto P_0c05ef76;
P_0c05ef76: /* original 0009, guest PC 0x0c05ef76 */
if(!s->budget--) { s->failed_pc=0x0c05ef76u; return 0; }
goto P_0c05ef78;
P_0c05ef78: /* original 8808, guest PC 0x0c05ef78 */
if(!s->budget--) { s->failed_pc=0x0c05ef78u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000008u)!=0);
goto P_0c05ef7a;
P_0c05ef7a: /* original 8912, guest PC 0x0c05ef7a */
if(!s->budget--) { s->failed_pc=0x0c05ef7au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05efa2; }
goto P_0c05ef7c;
P_0c05ef7c: /* original 8810, guest PC 0x0c05ef7c */
if(!s->budget--) { s->failed_pc=0x0c05ef7cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000010u)!=0);
goto P_0c05ef7e;
P_0c05ef7e: /* original 8910, guest PC 0x0c05ef7e */
if(!s->budget--) { s->failed_pc=0x0c05ef7eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05efa2; }
goto P_0c05ef80;
P_0c05ef80: /* original 8820, guest PC 0x0c05ef80 */
if(!s->budget--) { s->failed_pc=0x0c05ef80u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000020u)!=0);
goto P_0c05ef82;
P_0c05ef82: /* original 890e, guest PC 0x0c05ef82 */
if(!s->budget--) { s->failed_pc=0x0c05ef82u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05efa2; }
goto P_0c05ef84;
P_0c05ef84: /* original 8840, guest PC 0x0c05ef84 */
if(!s->budget--) { s->failed_pc=0x0c05ef84u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000040u)!=0);
goto P_0c05ef86;
P_0c05ef86: /* original 890c, guest PC 0x0c05ef86 */
if(!s->budget--) { s->failed_pc=0x0c05ef86u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05efa2; }
goto P_0c05ef88;
P_0c05ef88: /* original 9138, guest PC 0x0c05ef88 */
if(!s->budget--) { s->failed_pc=0x0c05ef88u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c05effcu,2);
goto P_0c05ef8a;
P_0c05ef8a: /* original 3010, guest PC 0x0c05ef8a */
if(!s->budget--) { s->failed_pc=0x0c05ef8au; return 0; }
r[17]=(r[17]&~1u)|((r[0]==r[1])!=0);
goto P_0c05ef8c;
P_0c05ef8c: /* original 8909, guest PC 0x0c05ef8c */
if(!s->budget--) { s->failed_pc=0x0c05ef8cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05efa2; }
goto P_0c05ef8e;
P_0c05ef8e: /* original 9136, guest PC 0x0c05ef8e */
if(!s->budget--) { s->failed_pc=0x0c05ef8eu; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c05effeu,2);
goto P_0c05ef90;
P_0c05ef90: /* original 3010, guest PC 0x0c05ef90 */
if(!s->budget--) { s->failed_pc=0x0c05ef90u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==r[1])!=0);
goto P_0c05ef92;
P_0c05ef92: /* original 8906, guest PC 0x0c05ef92 */
if(!s->budget--) { s->failed_pc=0x0c05ef92u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05efa2; }
goto P_0c05ef94;
P_0c05ef94: /* original 9134, guest PC 0x0c05ef94 */
if(!s->budget--) { s->failed_pc=0x0c05ef94u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c05f000u,2);
goto P_0c05ef96;
P_0c05ef96: /* original 3010, guest PC 0x0c05ef96 */
if(!s->budget--) { s->failed_pc=0x0c05ef96u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==r[1])!=0);
goto P_0c05ef98;
P_0c05ef98: /* original 8903, guest PC 0x0c05ef98 */
if(!s->budget--) { s->failed_pc=0x0c05ef98u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05efa2; }
goto P_0c05ef9a;
P_0c05ef9a: /* original 9132, guest PC 0x0c05ef9a */
if(!s->budget--) { s->failed_pc=0x0c05ef9au; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c05f002u,2);
goto P_0c05ef9c;
P_0c05ef9c: /* original 3010, guest PC 0x0c05ef9c */
if(!s->budget--) { s->failed_pc=0x0c05ef9cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==r[1])!=0);
goto P_0c05ef9e;
P_0c05ef9e: /* original 8900, guest PC 0x0c05ef9e */
if(!s->budget--) { s->failed_pc=0x0c05ef9eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05efa2; }
goto P_0c05efa0;
P_0c05efa0: /* original ed04, guest PC 0x0c05efa0 */
if(!s->budget--) { s->failed_pc=0x0c05efa0u; return 0; }
r[13]=0x00000004u;
goto P_0c05efa2;
P_0c05efa2: /* original 932f, guest PC 0x0c05efa2 */
if(!s->budget--) { s->failed_pc=0x0c05efa2u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c05f004u,2);
goto P_0c05efa4;
P_0c05efa4: /* original 3e30, guest PC 0x0c05efa4 */
if(!s->budget--) { s->failed_pc=0x0c05efa4u; return 0; }
r[17]=(r[17]&~1u)|((r[14]==r[3])!=0);
goto P_0c05efa6;
P_0c05efa6: /* original 890e, guest PC 0x0c05efa6 */
if(!s->budget--) { s->failed_pc=0x0c05efa6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05efc6; }
goto P_0c05efa8;
P_0c05efa8: /* original 912d, guest PC 0x0c05efa8 */
if(!s->budget--) { s->failed_pc=0x0c05efa8u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c05f006u,2);
goto P_0c05efaa;
P_0c05efaa: /* original 3e10, guest PC 0x0c05efaa */
if(!s->budget--) { s->failed_pc=0x0c05efaau; return 0; }
r[17]=(r[17]&~1u)|((r[14]==r[1])!=0);
goto P_0c05efac;
P_0c05efac: /* original 890b, guest PC 0x0c05efac */
if(!s->budget--) { s->failed_pc=0x0c05efacu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05efc6; }
goto P_0c05efae;
P_0c05efae: /* original 902b, guest PC 0x0c05efae */
if(!s->budget--) { s->failed_pc=0x0c05efaeu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c05f008u,2);
goto P_0c05efb0;
P_0c05efb0: /* original 3e00, guest PC 0x0c05efb0 */
if(!s->budget--) { s->failed_pc=0x0c05efb0u; return 0; }
r[17]=(r[17]&~1u)|((r[14]==r[0])!=0);
goto P_0c05efb2;
P_0c05efb2: /* original 8908, guest PC 0x0c05efb2 */
if(!s->budget--) { s->failed_pc=0x0c05efb2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05efc6; }
goto P_0c05efb4;
P_0c05efb4: /* original 9229, guest PC 0x0c05efb4 */
if(!s->budget--) { s->failed_pc=0x0c05efb4u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c05f00au,2);
goto P_0c05efb6;
P_0c05efb6: /* original 3e20, guest PC 0x0c05efb6 */
if(!s->budget--) { s->failed_pc=0x0c05efb6u; return 0; }
r[17]=(r[17]&~1u)|((r[14]==r[2])!=0);
goto P_0c05efb8;
P_0c05efb8: /* original 8905, guest PC 0x0c05efb8 */
if(!s->budget--) { s->failed_pc=0x0c05efb8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05efc6; }
goto P_0c05efba;
P_0c05efba: /* original 9127, guest PC 0x0c05efba */
if(!s->budget--) { s->failed_pc=0x0c05efbau; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c05f00cu,2);
goto P_0c05efbc;
P_0c05efbc: /* original 3e10, guest PC 0x0c05efbc */
if(!s->budget--) { s->failed_pc=0x0c05efbcu; return 0; }
r[17]=(r[17]&~1u)|((r[14]==r[1])!=0);
goto P_0c05efbe;
P_0c05efbe: /* original 8902, guest PC 0x0c05efbe */
if(!s->budget--) { s->failed_pc=0x0c05efbeu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05efc6; }
goto P_0c05efc0;
P_0c05efc0: /* original 3560, guest PC 0x0c05efc0 */
if(!s->budget--) { s->failed_pc=0x0c05efc0u; return 0; }
r[17]=(r[17]&~1u)|((r[5]==r[6])!=0);
goto P_0c05efc2;
P_0c05efc2: /* original 8900, guest PC 0x0c05efc2 */
if(!s->budget--) { s->failed_pc=0x0c05efc2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05efc6; }
goto P_0c05efc4;
P_0c05efc4: /* original ed04, guest PC 0x0c05efc4 */
if(!s->budget--) { s->failed_pc=0x0c05efc4u; return 0; }
r[13]=0x00000004u;
goto P_0c05efc6;
P_0c05efc6: /* original e300, guest PC 0x0c05efc6 */
if(!s->budget--) { s->failed_pc=0x0c05efc6u; return 0; }
r[3]=0x00000000u;
goto P_0c05efc8;
P_0c05efc8: /* original 9221, guest PC 0x0c05efc8 */
if(!s->budget--) { s->failed_pc=0x0c05efc8u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c05f00eu,2);
goto P_0c05efca;
P_0c05efca: /* original 1436, guest PC 0x0c05efca */
if(!s->budget--) { s->failed_pc=0x0c05efcau; return 0; }
write(ram,r[4]+24,r[3],4);
goto P_0c05efcc;
P_0c05efcc: /* original 3e20, guest PC 0x0c05efcc */
if(!s->budget--) { s->failed_pc=0x0c05efccu; return 0; }
r[17]=(r[17]&~1u)|((r[14]==r[2])!=0);
goto P_0c05efce;
P_0c05efce: /* original 890e, guest PC 0x0c05efce */
if(!s->budget--) { s->failed_pc=0x0c05efceu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05efee; }
goto P_0c05efd0;
P_0c05efd0: /* original 9116, guest PC 0x0c05efd0 */
if(!s->budget--) { s->failed_pc=0x0c05efd0u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c05f000u,2);
goto P_0c05efd2;
P_0c05efd2: /* original 3e10, guest PC 0x0c05efd2 */
if(!s->budget--) { s->failed_pc=0x0c05efd2u; return 0; }
r[17]=(r[17]&~1u)|((r[14]==r[1])!=0);
goto P_0c05efd4;
P_0c05efd4: /* original 890b, guest PC 0x0c05efd4 */
if(!s->budget--) { s->failed_pc=0x0c05efd4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05efee; }
goto P_0c05efd6;
P_0c05efd6: /* original 9014, guest PC 0x0c05efd6 */
if(!s->budget--) { s->failed_pc=0x0c05efd6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c05f002u,2);
goto P_0c05efd8;
P_0c05efd8: /* original 3e00, guest PC 0x0c05efd8 */
if(!s->budget--) { s->failed_pc=0x0c05efd8u; return 0; }
r[17]=(r[17]&~1u)|((r[14]==r[0])!=0);
goto P_0c05efda;
P_0c05efda: /* original 8908, guest PC 0x0c05efda */
if(!s->budget--) { s->failed_pc=0x0c05efdau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05efee; }
goto P_0c05efdc;
P_0c05efdc: /* original 9218, guest PC 0x0c05efdc */
if(!s->budget--) { s->failed_pc=0x0c05efdcu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c05f010u,2);
goto P_0c05efde;
P_0c05efde: /* original 3e20, guest PC 0x0c05efde */
if(!s->budget--) { s->failed_pc=0x0c05efdeu; return 0; }
r[17]=(r[17]&~1u)|((r[14]==r[2])!=0);
goto P_0c05efe0;
P_0c05efe0: /* original 8905, guest PC 0x0c05efe0 */
if(!s->budget--) { s->failed_pc=0x0c05efe0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05efee; }
goto P_0c05efe2;
P_0c05efe2: /* original 9116, guest PC 0x0c05efe2 */
if(!s->budget--) { s->failed_pc=0x0c05efe2u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c05f012u,2);
goto P_0c05efe4;
P_0c05efe4: /* original 3e10, guest PC 0x0c05efe4 */
if(!s->budget--) { s->failed_pc=0x0c05efe4u; return 0; }
r[17]=(r[17]&~1u)|((r[14]==r[1])!=0);
goto P_0c05efe6;
P_0c05efe6: /* original 8902, guest PC 0x0c05efe6 */
if(!s->budget--) { s->failed_pc=0x0c05efe6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05efee; }
goto P_0c05efe8;
P_0c05efe8: /* original 9214, guest PC 0x0c05efe8 */
if(!s->budget--) { s->failed_pc=0x0c05efe8u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c05f014u,2);
goto P_0c05efea;
P_0c05efea: /* original 3e20, guest PC 0x0c05efea */
if(!s->budget--) { s->failed_pc=0x0c05efeau; return 0; }
r[17]=(r[17]&~1u)|((r[14]==r[2])!=0);
goto P_0c05efec;
P_0c05efec: /* original 8b02, guest PC 0x0c05efec */
if(!s->budget--) { s->failed_pc=0x0c05efecu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c05eff4; }
goto P_0c05efee;
P_0c05efee: /* original 5146, guest PC 0x0c05efee */
if(!s->budget--) { s->failed_pc=0x0c05efeeu; return 0; }
r[1]=read(ram,r[4]+24,4);
goto P_0c05eff0;
P_0c05eff0: /* original 217b, guest PC 0x0c05eff0 */
if(!s->budget--) { s->failed_pc=0x0c05eff0u; return 0; }
r[1]|=r[7];
goto P_0c05eff2;
P_0c05eff2: /* original 1416, guest PC 0x0c05eff2 */
if(!s->budget--) { s->failed_pc=0x0c05eff2u; return 0; }
write(ram,r[4]+24,r[1],4);
goto P_0c05eff4;
P_0c05eff4: /* original 930f, guest PC 0x0c05eff4 */
if(!s->budget--) { s->failed_pc=0x0c05eff4u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c05f016u,2);
goto P_0c05eff6;
P_0c05eff6: /* original 3e30, guest PC 0x0c05eff6 */
if(!s->budget--) { s->failed_pc=0x0c05eff6u; return 0; }
r[17]=(r[17]&~1u)|((r[14]==r[3])!=0);
goto P_0c05eff8;
P_0c05eff8: /* original a00e, guest PC 0x0c05eff8 */
if(!s->budget--) { s->failed_pc=0x0c05eff8u; return 0; }
r[5]=0x00000004u;
goto P_0c05f018;
P_0c05effa: /* original e504, guest PC 0x0c05effa */
if(!s->budget--) { s->failed_pc=0x0c05effau; return 0; }
r[5]=0x00000004u;
if(!vf3_matrix_family(0x0c05effcu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c05effcu; return 0; } return 1;
P_0c05f018: /* original 8d0c, guest PC 0x0c05f018 */
if(!s->budget--) { s->failed_pc=0x0c05f018u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05f034; }
goto P_0c05f01c;
P_0c05f01a: /* original 0009, guest PC 0x0c05f01a */
if(!s->budget--) { s->failed_pc=0x0c05f01au; return 0; }
goto P_0c05f01c;
P_0c05f01c: /* original 913f, guest PC 0x0c05f01c */
if(!s->budget--) { s->failed_pc=0x0c05f01cu; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c05f09eu,2);
goto P_0c05f01e;
P_0c05f01e: /* original 3e10, guest PC 0x0c05f01e */
if(!s->budget--) { s->failed_pc=0x0c05f01eu; return 0; }
r[17]=(r[17]&~1u)|((r[14]==r[1])!=0);
goto P_0c05f020;
P_0c05f020: /* original 8908, guest PC 0x0c05f020 */
if(!s->budget--) { s->failed_pc=0x0c05f020u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05f034; }
goto P_0c05f022;
P_0c05f022: /* original 903d, guest PC 0x0c05f022 */
if(!s->budget--) { s->failed_pc=0x0c05f022u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c05f0a0u,2);
goto P_0c05f024;
P_0c05f024: /* original 3e00, guest PC 0x0c05f024 */
if(!s->budget--) { s->failed_pc=0x0c05f024u; return 0; }
r[17]=(r[17]&~1u)|((r[14]==r[0])!=0);
goto P_0c05f026;
P_0c05f026: /* original 8905, guest PC 0x0c05f026 */
if(!s->budget--) { s->failed_pc=0x0c05f026u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05f034; }
goto P_0c05f028;
P_0c05f028: /* original 923b, guest PC 0x0c05f028 */
if(!s->budget--) { s->failed_pc=0x0c05f028u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c05f0a2u,2);
goto P_0c05f02a;
P_0c05f02a: /* original 3e20, guest PC 0x0c05f02a */
if(!s->budget--) { s->failed_pc=0x0c05f02au; return 0; }
r[17]=(r[17]&~1u)|((r[14]==r[2])!=0);
goto P_0c05f02c;
P_0c05f02c: /* original 8902, guest PC 0x0c05f02c */
if(!s->budget--) { s->failed_pc=0x0c05f02cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05f034; }
goto P_0c05f02e;
P_0c05f02e: /* original 9139, guest PC 0x0c05f02e */
if(!s->budget--) { s->failed_pc=0x0c05f02eu; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c05f0a4u,2);
goto P_0c05f030;
P_0c05f030: /* original 3e10, guest PC 0x0c05f030 */
if(!s->budget--) { s->failed_pc=0x0c05f030u; return 0; }
r[17]=(r[17]&~1u)|((r[14]==r[1])!=0);
goto P_0c05f032;
P_0c05f032: /* original 8b02, guest PC 0x0c05f032 */
if(!s->budget--) { s->failed_pc=0x0c05f032u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c05f03a; }
goto P_0c05f034;
P_0c05f034: /* original 5246, guest PC 0x0c05f034 */
if(!s->budget--) { s->failed_pc=0x0c05f034u; return 0; }
r[2]=read(ram,r[4]+24,4);
goto P_0c05f036;
P_0c05f036: /* original 225b, guest PC 0x0c05f036 */
if(!s->budget--) { s->failed_pc=0x0c05f036u; return 0; }
r[2]|=r[5];
goto P_0c05f038;
P_0c05f038: /* original 1426, guest PC 0x0c05f038 */
if(!s->budget--) { s->failed_pc=0x0c05f038u; return 0; }
write(ram,r[4]+24,r[2],4);
goto P_0c05f03a;
P_0c05f03a: /* original 9334, guest PC 0x0c05f03a */
if(!s->budget--) { s->failed_pc=0x0c05f03au; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c05f0a6u,2);
goto P_0c05f03c;
P_0c05f03c: /* original 3e30, guest PC 0x0c05f03c */
if(!s->budget--) { s->failed_pc=0x0c05f03cu; return 0; }
r[17]=(r[17]&~1u)|((r[14]==r[3])!=0);
goto P_0c05f03e;
P_0c05f03e: /* original 8908, guest PC 0x0c05f03e */
if(!s->budget--) { s->failed_pc=0x0c05f03eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05f052; }
goto P_0c05f040;
P_0c05f040: /* original 9132, guest PC 0x0c05f040 */
if(!s->budget--) { s->failed_pc=0x0c05f040u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c05f0a8u,2);
goto P_0c05f042;
P_0c05f042: /* original 3e10, guest PC 0x0c05f042 */
if(!s->budget--) { s->failed_pc=0x0c05f042u; return 0; }
r[17]=(r[17]&~1u)|((r[14]==r[1])!=0);
goto P_0c05f044;
P_0c05f044: /* original 8905, guest PC 0x0c05f044 */
if(!s->budget--) { s->failed_pc=0x0c05f044u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05f052; }
goto P_0c05f046;
P_0c05f046: /* original 9030, guest PC 0x0c05f046 */
if(!s->budget--) { s->failed_pc=0x0c05f046u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c05f0aau,2);
goto P_0c05f048;
P_0c05f048: /* original 3e00, guest PC 0x0c05f048 */
if(!s->budget--) { s->failed_pc=0x0c05f048u; return 0; }
r[17]=(r[17]&~1u)|((r[14]==r[0])!=0);
goto P_0c05f04a;
P_0c05f04a: /* original 8902, guest PC 0x0c05f04a */
if(!s->budget--) { s->failed_pc=0x0c05f04au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05f052; }
goto P_0c05f04c;
P_0c05f04c: /* original 922e, guest PC 0x0c05f04c */
if(!s->budget--) { s->failed_pc=0x0c05f04cu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c05f0acu,2);
goto P_0c05f04e;
P_0c05f04e: /* original 3e20, guest PC 0x0c05f04e */
if(!s->budget--) { s->failed_pc=0x0c05f04eu; return 0; }
r[17]=(r[17]&~1u)|((r[14]==r[2])!=0);
goto P_0c05f050;
P_0c05f050: /* original 8b04, guest PC 0x0c05f050 */
if(!s->budget--) { s->failed_pc=0x0c05f050u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c05f05c; }
goto P_0c05f052;
P_0c05f052: /* original 5046, guest PC 0x0c05f052 */
if(!s->budget--) { s->failed_pc=0x0c05f052u; return 0; }
r[0]=read(ram,r[4]+24,4);
goto P_0c05f054;
P_0c05f054: /* original cb08, guest PC 0x0c05f054 */
if(!s->budget--) { s->failed_pc=0x0c05f054u; return 0; }
r[0]|=8u;
goto P_0c05f056;
P_0c05f056: /* original 6203, guest PC 0x0c05f056 */
if(!s->budget--) { s->failed_pc=0x0c05f056u; return 0; }
r[2]=r[0];
goto P_0c05f058;
P_0c05f058: /* original 225b, guest PC 0x0c05f058 */
if(!s->budget--) { s->failed_pc=0x0c05f058u; return 0; }
r[2]|=r[5];
goto P_0c05f05a;
P_0c05f05a: /* original 1426, guest PC 0x0c05f05a */
if(!s->budget--) { s->failed_pc=0x0c05f05au; return 0; }
write(ram,r[4]+24,r[2],4);
goto P_0c05f05c;
P_0c05f05c: /* original 9327, guest PC 0x0c05f05c */
if(!s->budget--) { s->failed_pc=0x0c05f05cu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c05f0aeu,2);
goto P_0c05f05e;
P_0c05f05e: /* original 3e30, guest PC 0x0c05f05e */
if(!s->budget--) { s->failed_pc=0x0c05f05eu; return 0; }
r[17]=(r[17]&~1u)|((r[14]==r[3])!=0);
goto P_0c05f060;
P_0c05f060: /* original 8b02, guest PC 0x0c05f060 */
if(!s->budget--) { s->failed_pc=0x0c05f060u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c05f068; }
goto P_0c05f062;
P_0c05f062: /* original 5046, guest PC 0x0c05f062 */
if(!s->budget--) { s->failed_pc=0x0c05f062u; return 0; }
r[0]=read(ram,r[4]+24,4);
goto P_0c05f064;
P_0c05f064: /* original cb10, guest PC 0x0c05f064 */
if(!s->budget--) { s->failed_pc=0x0c05f064u; return 0; }
r[0]|=16u;
goto P_0c05f066;
P_0c05f066: /* original 1406, guest PC 0x0c05f066 */
if(!s->budget--) { s->failed_pc=0x0c05f066u; return 0; }
write(ram,r[4]+24,r[0],4);
goto P_0c05f068;
P_0c05f068: /* original 9322, guest PC 0x0c05f068 */
if(!s->budget--) { s->failed_pc=0x0c05f068u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c05f0b0u,2);
goto P_0c05f06a;
P_0c05f06a: /* original 3e30, guest PC 0x0c05f06a */
if(!s->budget--) { s->failed_pc=0x0c05f06au; return 0; }
r[17]=(r[17]&~1u)|((r[14]==r[3])!=0);
goto P_0c05f06c;
P_0c05f06c: /* original 8908, guest PC 0x0c05f06c */
if(!s->budget--) { s->failed_pc=0x0c05f06cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05f080; }
goto P_0c05f06e;
P_0c05f06e: /* original 9120, guest PC 0x0c05f06e */
if(!s->budget--) { s->failed_pc=0x0c05f06eu; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c05f0b2u,2);
goto P_0c05f070;
P_0c05f070: /* original 3e10, guest PC 0x0c05f070 */
if(!s->budget--) { s->failed_pc=0x0c05f070u; return 0; }
r[17]=(r[17]&~1u)|((r[14]==r[1])!=0);
goto P_0c05f072;
P_0c05f072: /* original 8905, guest PC 0x0c05f072 */
if(!s->budget--) { s->failed_pc=0x0c05f072u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05f080; }
goto P_0c05f074;
P_0c05f074: /* original 901e, guest PC 0x0c05f074 */
if(!s->budget--) { s->failed_pc=0x0c05f074u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c05f0b4u,2);
goto P_0c05f076;
P_0c05f076: /* original 3e00, guest PC 0x0c05f076 */
if(!s->budget--) { s->failed_pc=0x0c05f076u; return 0; }
r[17]=(r[17]&~1u)|((r[14]==r[0])!=0);
goto P_0c05f078;
P_0c05f078: /* original 8902, guest PC 0x0c05f078 */
if(!s->budget--) { s->failed_pc=0x0c05f078u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05f080; }
goto P_0c05f07a;
P_0c05f07a: /* original 921c, guest PC 0x0c05f07a */
if(!s->budget--) { s->failed_pc=0x0c05f07au; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c05f0b6u,2);
goto P_0c05f07c;
P_0c05f07c: /* original 3e20, guest PC 0x0c05f07c */
if(!s->budget--) { s->failed_pc=0x0c05f07cu; return 0; }
r[17]=(r[17]&~1u)|((r[14]==r[2])!=0);
goto P_0c05f07e;
P_0c05f07e: /* original 8b04, guest PC 0x0c05f07e */
if(!s->budget--) { s->failed_pc=0x0c05f07eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c05f08a; }
goto P_0c05f080;
P_0c05f080: /* original 5046, guest PC 0x0c05f080 */
if(!s->budget--) { s->failed_pc=0x0c05f080u; return 0; }
r[0]=read(ram,r[4]+24,4);
goto P_0c05f082;
P_0c05f082: /* original cb20, guest PC 0x0c05f082 */
if(!s->budget--) { s->failed_pc=0x0c05f082u; return 0; }
r[0]|=32u;
goto P_0c05f084;
P_0c05f084: /* original 6203, guest PC 0x0c05f084 */
if(!s->budget--) { s->failed_pc=0x0c05f084u; return 0; }
r[2]=r[0];
goto P_0c05f086;
P_0c05f086: /* original 225b, guest PC 0x0c05f086 */
if(!s->budget--) { s->failed_pc=0x0c05f086u; return 0; }
r[2]|=r[5];
goto P_0c05f088;
P_0c05f088: /* original 1426, guest PC 0x0c05f088 */
if(!s->budget--) { s->failed_pc=0x0c05f088u; return 0; }
write(ram,r[4]+24,r[2],4);
goto P_0c05f08a;
P_0c05f08a: /* original b04d, guest PC 0x0c05f08a */
if(!s->budget--) { s->failed_pc=0x0c05f08au; return 0; }
target=code_base|0x0c05f128u; r[16]=code_base|0x0c05f08eu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c05f08eu) { target=s->pc; goto dispatch; }
goto P_0c05f08e;
P_0c05f08c: /* original 0009, guest PC 0x0c05f08c */
if(!s->budget--) { s->failed_pc=0x0c05f08cu; return 0; }
goto P_0c05f08e;
P_0c05f08e: /* original 60d3, guest PC 0x0c05f08e */
if(!s->budget--) { s->failed_pc=0x0c05f08eu; return 0; }
r[0]=r[13];
goto P_0c05f090;
P_0c05f090: /* original 0009, guest PC 0x0c05f090 */
if(!s->budget--) { s->failed_pc=0x0c05f090u; return 0; }
goto P_0c05f092;
P_0c05f092: /* original 7f04, guest PC 0x0c05f092 */
if(!s->budget--) { s->failed_pc=0x0c05f092u; return 0; }
r[15]+=0x00000004u;
goto P_0c05f094;
P_0c05f094: /* original 4f26, guest PC 0x0c05f094 */
if(!s->budget--) { s->failed_pc=0x0c05f094u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c05f096;
P_0c05f096: /* original 6cf6, guest PC 0x0c05f096 */
if(!s->budget--) { s->failed_pc=0x0c05f096u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c05f098;
P_0c05f098: /* original 6df6, guest PC 0x0c05f098 */
if(!s->budget--) { s->failed_pc=0x0c05f098u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c05f09a;
P_0c05f09a: /* original 000b, guest PC 0x0c05f09a */
if(!s->budget--) { s->failed_pc=0x0c05f09au; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c05f09c: /* original 6ef6, guest PC 0x0c05f09c */
if(!s->budget--) { s->failed_pc=0x0c05f09cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c05f09eu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c05f09eu; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
