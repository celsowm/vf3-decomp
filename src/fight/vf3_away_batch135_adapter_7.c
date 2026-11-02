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
int vf3_away_batch135_adapter_7(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c0ad578u: goto P_0c0ad578;
case 0x0c0ad57au: goto P_0c0ad57a;
case 0x0c0ad57cu: goto P_0c0ad57c;
case 0x0c0ad57eu: goto P_0c0ad57e;
case 0x0c0ad580u: goto P_0c0ad580;
case 0x0c0ad582u: goto P_0c0ad582;
case 0x0c0ad584u: goto P_0c0ad584;
case 0x0c0ad586u: goto P_0c0ad586;
case 0x0c0ad588u: goto P_0c0ad588;
case 0x0c0ae0a4u: goto P_0c0ae0a4;
case 0x0c0ae0a6u: goto P_0c0ae0a6;
case 0x0c0ae0a8u: goto P_0c0ae0a8;
case 0x0c0ae0aau: goto P_0c0ae0aa;
case 0x0c0ae0acu: goto P_0c0ae0ac;
case 0x0c0ae0aeu: goto P_0c0ae0ae;
case 0x0c0ae0b0u: goto P_0c0ae0b0;
case 0x0c0ae0b2u: goto P_0c0ae0b2;
case 0x0c0ae0b4u: goto P_0c0ae0b4;
case 0x0c0ae0b6u: goto P_0c0ae0b6;
case 0x0c0ae0b8u: goto P_0c0ae0b8;
case 0x0c0ae0bau: goto P_0c0ae0ba;
case 0x0c0ae0bcu: goto P_0c0ae0bc;
case 0x0c0ae0beu: goto P_0c0ae0be;
case 0x0c0ae0c0u: goto P_0c0ae0c0;
case 0x0c0ae0c2u: goto P_0c0ae0c2;
case 0x0c0ae0c4u: goto P_0c0ae0c4;
case 0x0c0ae0c6u: goto P_0c0ae0c6;
case 0x0c0ae0c8u: goto P_0c0ae0c8;
case 0x0c0ae0cau: goto P_0c0ae0ca;
case 0x0c0ae0ccu: goto P_0c0ae0cc;
case 0x0c0ae0ceu: goto P_0c0ae0ce;
case 0x0c0ae0d0u: goto P_0c0ae0d0;
case 0x0c0ae0d2u: goto P_0c0ae0d2;
case 0x0c0ae0d4u: goto P_0c0ae0d4;
case 0x0c0ae0d6u: goto P_0c0ae0d6;
case 0x0c0ae0d8u: goto P_0c0ae0d8;
case 0x0c0ae0dau: goto P_0c0ae0da;
case 0x0c0ae0dcu: goto P_0c0ae0dc;
case 0x0c0ae0deu: goto P_0c0ae0de;
case 0x0c0ae0e0u: goto P_0c0ae0e0;
case 0x0c0ae0e2u: goto P_0c0ae0e2;
case 0x0c0ae0e4u: goto P_0c0ae0e4;
case 0x0c0ae0e6u: goto P_0c0ae0e6;
case 0x0c0ae0e8u: goto P_0c0ae0e8;
case 0x0c0ae0eau: goto P_0c0ae0ea;
case 0x0c0c66b8u: goto P_0c0c66b8;
case 0x0c0c66bau: goto P_0c0c66ba;
case 0x0c0c6742u: goto P_0c0c6742;
case 0x0c0c6744u: goto P_0c0c6744;
case 0x0c0c6746u: goto P_0c0c6746;
case 0x0c0c6748u: goto P_0c0c6748;
default: return vf3_matrix_family(target,s,ram);
}
P_0c0ad578: /* original 6360, guest PC 0x0c0ad578 */
if(!s->budget--) { s->failed_pc=0x0c0ad578u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[6],1);
r[3]=tmp;
goto P_0c0ad57a;
P_0c0ad57a: /* original 7ffc, guest PC 0x0c0ad57a */
if(!s->budget--) { s->failed_pc=0x0c0ad57au; return 0; }
r[15]+=0xfffffffcu;
goto P_0c0ad57c;
P_0c0ad57c: /* original d007, guest PC 0x0c0ad57c */
if(!s->budget--) { s->failed_pc=0x0c0ad57cu; return 0; }
r[0]=read(ram,0x0c0ad59cu,4);
goto P_0c0ad57e;
P_0c0ad57e: /* original 633c, guest PC 0x0c0ad57e */
if(!s->budget--) { s->failed_pc=0x0c0ad57eu; return 0; }
r[3]=r[3]&255u;
goto P_0c0ad580;
P_0c0ad580: /* original 4308, guest PC 0x0c0ad580 */
if(!s->budget--) { s->failed_pc=0x0c0ad580u; return 0; }
r[3]<<=2;
goto P_0c0ad582;
P_0c0ad582: /* original 023e, guest PC 0x0c0ad582 */
if(!s->budget--) { s->failed_pc=0x0c0ad582u; return 0; }
r[2]=read(ram,r[3]+r[0],4);
goto P_0c0ad584;
P_0c0ad584: /* original 2f22, guest PC 0x0c0ad584 */
if(!s->budget--) { s->failed_pc=0x0c0ad584u; return 0; }
write(ram,r[15],r[2],4);
goto P_0c0ad586;
P_0c0ad586: /* original 422b, guest PC 0x0c0ad586 */
if(!s->budget--) { s->failed_pc=0x0c0ad586u; return 0; }
target=r[2];
r[15]+=0x00000004u;
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
P_0c0ad588: /* original 7f04, guest PC 0x0c0ad588 */
if(!s->budget--) { s->failed_pc=0x0c0ad588u; return 0; }
r[15]+=0x00000004u;
if(!vf3_matrix_family(0x0c0ad58au,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0ad58au; return 0; } return 1;
P_0c0ae0a4: /* original 925d, guest PC 0x0c0ae0a4 */
if(!s->budget--) { s->failed_pc=0x0c0ae0a4u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ae162u,2);
goto P_0c0ae0a6;
P_0c0ae0a6: /* original d333, guest PC 0x0c0ae0a6 */
if(!s->budget--) { s->failed_pc=0x0c0ae0a6u; return 0; }
r[3]=read(ram,0x0c0ae174u,4);
goto P_0c0ae0a8;
P_0c0ae0a8: /* original 915c, guest PC 0x0c0ae0a8 */
if(!s->budget--) { s->failed_pc=0x0c0ae0a8u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ae164u,2);
goto P_0c0ae0aa;
P_0c0ae0aa: /* original 2429, guest PC 0x0c0ae0aa */
if(!s->budget--) { s->failed_pc=0x0c0ae0aau; return 0; }
r[4]&=r[2];
goto P_0c0ae0ac;
P_0c0ae0ac: /* original 6632, guest PC 0x0c0ae0ac */
if(!s->budget--) { s->failed_pc=0x0c0ae0acu; return 0; }
tmp=read(ram,r[3],4);
r[6]=tmp;
goto P_0c0ae0ae;
P_0c0ae0ae: /* original 3412, guest PC 0x0c0ae0ae */
if(!s->budget--) { s->failed_pc=0x0c0ae0aeu; return 0; }
r[17]=(r[17]&~1u)|((r[4]>=r[1])!=0);
goto P_0c0ae0b0;
P_0c0ae0b0: /* original 8919, guest PC 0x0c0ae0b0 */
if(!s->budget--) { s->failed_pc=0x0c0ae0b0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0ae0e6; }
goto P_0c0ae0b2;
P_0c0ae0b2: /* original 6043, guest PC 0x0c0ae0b2 */
if(!s->budget--) { s->failed_pc=0x0c0ae0b2u; return 0; }
r[0]=r[4];
goto P_0c0ae0b4;
P_0c0ae0b4: /* original 70ff, guest PC 0x0c0ae0b4 */
if(!s->budget--) { s->failed_pc=0x0c0ae0b4u; return 0; }
r[0]+=0xffffffffu;
goto P_0c0ae0b6;
P_0c0ae0b6: /* original 4008, guest PC 0x0c0ae0b6 */
if(!s->budget--) { s->failed_pc=0x0c0ae0b6u; return 0; }
r[0]<<=2;
goto P_0c0ae0b8;
P_0c0ae0b8: /* original 036e, guest PC 0x0c0ae0b8 */
if(!s->budget--) { s->failed_pc=0x0c0ae0b8u; return 0; }
r[3]=read(ram,r[6]+r[0],4);
goto P_0c0ae0ba;
P_0c0ae0ba: /* original 6433, guest PC 0x0c0ae0ba */
if(!s->budget--) { s->failed_pc=0x0c0ae0bau; return 0; }
r[4]=r[3];
goto P_0c0ae0bc;
P_0c0ae0bc: /* original 346c, guest PC 0x0c0ae0bc */
if(!s->budget--) { s->failed_pc=0x0c0ae0bcu; return 0; }
r[4]+=r[6];
goto P_0c0ae0be;
P_0c0ae0be: /* original 6643, guest PC 0x0c0ae0be */
if(!s->budget--) { s->failed_pc=0x0c0ae0beu; return 0; }
r[6]=r[4];
goto P_0c0ae0c0;
P_0c0ae0c0: /* original 760c, guest PC 0x0c0ae0c0 */
if(!s->budget--) { s->failed_pc=0x0c0ae0c0u; return 0; }
r[6]+=0x0000000cu;
goto P_0c0ae0c2;
P_0c0ae0c2: /* original 6460, guest PC 0x0c0ae0c2 */
if(!s->budget--) { s->failed_pc=0x0c0ae0c2u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[6],1);
r[4]=tmp;
goto P_0c0ae0c4;
P_0c0ae0c4: /* original 644c, guest PC 0x0c0ae0c4 */
if(!s->budget--) { s->failed_pc=0x0c0ae0c4u; return 0; }
r[4]=r[4]&255u;
goto P_0c0ae0c6;
P_0c0ae0c6: /* original 3450, guest PC 0x0c0ae0c6 */
if(!s->budget--) { s->failed_pc=0x0c0ae0c6u; return 0; }
r[17]=(r[17]&~1u)|((r[4]==r[5])!=0);
goto P_0c0ae0c8;
P_0c0ae0c8: /* original 8b01, guest PC 0x0c0ae0c8 */
if(!s->budget--) { s->failed_pc=0x0c0ae0c8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0ae0ce; }
goto P_0c0ae0ca;
P_0c0ae0ca: /* original 000b, guest PC 0x0c0ae0ca */
if(!s->budget--) { s->failed_pc=0x0c0ae0cau; return 0; }
target=r[16];
r[0]=r[6];
s->pc=target; return ram->oob==0;
P_0c0ae0cc: /* original 6063, guest PC 0x0c0ae0cc */
if(!s->budget--) { s->failed_pc=0x0c0ae0ccu; return 0; }
r[0]=r[6];
goto P_0c0ae0ce;
P_0c0ae0ce: /* original 2448, guest PC 0x0c0ae0ce */
if(!s->budget--) { s->failed_pc=0x0c0ae0ceu; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c0ae0d0;
P_0c0ae0d0: /* original 8909, guest PC 0x0c0ae0d0 */
if(!s->budget--) { s->failed_pc=0x0c0ae0d0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0ae0e6; }
goto P_0c0ae0d2;
P_0c0ae0d2: /* original 6043, guest PC 0x0c0ae0d2 */
if(!s->budget--) { s->failed_pc=0x0c0ae0d2u; return 0; }
r[0]=r[4];
goto P_0c0ae0d4;
P_0c0ae0d4: /* original 8808, guest PC 0x0c0ae0d4 */
if(!s->budget--) { s->failed_pc=0x0c0ae0d4u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000008u)!=0);
goto P_0c0ae0d6;
P_0c0ae0d6: /* original 8906, guest PC 0x0c0ae0d6 */
if(!s->budget--) { s->failed_pc=0x0c0ae0d6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0ae0e6; }
goto P_0c0ae0d8;
P_0c0ae0d8: /* original e316, guest PC 0x0c0ae0d8 */
if(!s->budget--) { s->failed_pc=0x0c0ae0d8u; return 0; }
r[3]=0x00000016u;
goto P_0c0ae0da;
P_0c0ae0da: /* original 3436, guest PC 0x0c0ae0da */
if(!s->budget--) { s->failed_pc=0x0c0ae0dau; return 0; }
r[17]=(r[17]&~1u)|((r[4]>r[3])!=0);
goto P_0c0ae0dc;
P_0c0ae0dc: /* original 8903, guest PC 0x0c0ae0dc */
if(!s->budget--) { s->failed_pc=0x0c0ae0dcu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0ae0e6; }
goto P_0c0ae0de;
P_0c0ae0de: /* original d026, guest PC 0x0c0ae0de */
if(!s->budget--) { s->failed_pc=0x0c0ae0deu; return 0; }
r[0]=read(ram,0x0c0ae178u,4);
goto P_0c0ae0e0;
P_0c0ae0e0: /* original 034c, guest PC 0x0c0ae0e0 */
if(!s->budget--) { s->failed_pc=0x0c0ae0e0u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c0ae0e2;
P_0c0ae0e2: /* original afee, guest PC 0x0c0ae0e2 */
if(!s->budget--) { s->failed_pc=0x0c0ae0e2u; return 0; }
r[6]+=r[3];
goto P_0c0ae0c2;
P_0c0ae0e4: /* original 363c, guest PC 0x0c0ae0e4 */
if(!s->budget--) { s->failed_pc=0x0c0ae0e4u; return 0; }
r[6]+=r[3];
goto P_0c0ae0e6;
P_0c0ae0e6: /* original e000, guest PC 0x0c0ae0e6 */
if(!s->budget--) { s->failed_pc=0x0c0ae0e6u; return 0; }
r[0]=0x00000000u;
goto P_0c0ae0e8;
P_0c0ae0e8: /* original 000b, guest PC 0x0c0ae0e8 */
if(!s->budget--) { s->failed_pc=0x0c0ae0e8u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c0ae0ea: /* original 0009, guest PC 0x0c0ae0ea */
if(!s->budget--) { s->failed_pc=0x0c0ae0eau; return 0; }
if(!vf3_matrix_family(0x0c0ae0ecu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0ae0ecu; return 0; } return 1;
P_0c0c66b8: /* original 000b, guest PC 0x0c0c66b8 */
if(!s->budget--) { s->failed_pc=0x0c0c66b8u; return 0; }
target=r[16];
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[4],1);
r[0]=tmp;
s->pc=target; return ram->oob==0;
P_0c0c66ba: /* original 6040, guest PC 0x0c0c66ba */
if(!s->budget--) { s->failed_pc=0x0c0c66bau; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[4],1);
r[0]=tmp;
if(!vf3_matrix_family(0x0c0c66bcu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0c66bcu; return 0; } return 1;
P_0c0c6742: /* original 9049, guest PC 0x0c0c6742 */
if(!s->budget--) { s->failed_pc=0x0c0c6742u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c67d8u,2);
goto P_0c0c6744;
P_0c0c6744: /* original d426, guest PC 0x0c0c6744 */
if(!s->budget--) { s->failed_pc=0x0c0c6744u; return 0; }
r[4]=read(ram,0x0c0c67e0u,4);
goto P_0c0c6746;
P_0c0c6746: /* original 000b, guest PC 0x0c0c6746 */
if(!s->budget--) { s->failed_pc=0x0c0c6746u; return 0; }
target=r[16];
r[0]=read(ram,r[4]+r[0],4);
s->pc=target; return ram->oob==0;
P_0c0c6748: /* original 004e, guest PC 0x0c0c6748 */
if(!s->budget--) { s->failed_pc=0x0c0c6748u; return 0; }
r[0]=read(ram,r[4]+r[0],4);
if(!vf3_matrix_family(0x0c0c674au,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0c674au; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
