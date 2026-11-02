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
int vf3_away_batch108_adapter_6(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
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
default: return vf3_matrix_family(target,s,ram);
}
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
unsupported: s->failed_pc=target; return 0;
}
