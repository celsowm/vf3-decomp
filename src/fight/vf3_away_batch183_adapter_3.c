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
int vf3_away_batch183_adapter_3(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c09ce8cu: goto P_0c09ce8c;
case 0x0c09ce8eu: goto P_0c09ce8e;
case 0x0c09ce90u: goto P_0c09ce90;
case 0x0c09ce92u: goto P_0c09ce92;
case 0x0c09ce94u: goto P_0c09ce94;
case 0x0c09ce96u: goto P_0c09ce96;
case 0x0c09ce98u: goto P_0c09ce98;
case 0x0c09ce9au: goto P_0c09ce9a;
case 0x0c09ce9cu: goto P_0c09ce9c;
case 0x0c09ce9eu: goto P_0c09ce9e;
case 0x0c09cea0u: goto P_0c09cea0;
case 0x0c09cea2u: goto P_0c09cea2;
case 0x0c09cea4u: goto P_0c09cea4;
case 0x0c09cea6u: goto P_0c09cea6;
case 0x0c09cea8u: goto P_0c09cea8;
case 0x0c09ceaau: goto P_0c09ceaa;
case 0x0c09ceacu: goto P_0c09ceac;
case 0x0c09ceaeu: goto P_0c09ceae;
case 0x0c09ceb0u: goto P_0c09ceb0;
case 0x0c09ceb2u: goto P_0c09ceb2;
case 0x0c09ceb4u: goto P_0c09ceb4;
case 0x0c09ceb6u: goto P_0c09ceb6;
case 0x0c09ceb8u: goto P_0c09ceb8;
case 0x0c09cebau: goto P_0c09ceba;
case 0x0c09cebcu: goto P_0c09cebc;
case 0x0c09cebeu: goto P_0c09cebe;
case 0x0c09cec0u: goto P_0c09cec0;
case 0x0c09cec2u: goto P_0c09cec2;
case 0x0c09cec4u: goto P_0c09cec4;
case 0x0c09cec6u: goto P_0c09cec6;
case 0x0c09cec8u: goto P_0c09cec8;
case 0x0c09cecau: goto P_0c09ceca;
case 0x0c09ceccu: goto P_0c09cecc;
case 0x0c09ceceu: goto P_0c09cece;
case 0x0c09ced0u: goto P_0c09ced0;
case 0x0c09ced2u: goto P_0c09ced2;
case 0x0c09ced4u: goto P_0c09ced4;
case 0x0c09ced6u: goto P_0c09ced6;
case 0x0c09ced8u: goto P_0c09ced8;
case 0x0c09cedau: goto P_0c09ceda;
case 0x0c09cedcu: goto P_0c09cedc;
case 0x0c09cedeu: goto P_0c09cede;
case 0x0c09cee0u: goto P_0c09cee0;
case 0x0c09cee2u: goto P_0c09cee2;
case 0x0c09cee4u: goto P_0c09cee4;
case 0x0c09cee6u: goto P_0c09cee6;
case 0x0c09cee8u: goto P_0c09cee8;
case 0x0c09ceeau: goto P_0c09ceea;
case 0x0c09ceecu: goto P_0c09ceec;
case 0x0c09ceeeu: goto P_0c09ceee;
case 0x0c09cef0u: goto P_0c09cef0;
case 0x0c09cef2u: goto P_0c09cef2;
case 0x0c09cef4u: goto P_0c09cef4;
case 0x0c09cef6u: goto P_0c09cef6;
case 0x0c09cef8u: goto P_0c09cef8;
case 0x0c09cefau: goto P_0c09cefa;
case 0x0c09cefcu: goto P_0c09cefc;
case 0x0c09cefeu: goto P_0c09cefe;
case 0x0c09cf00u: goto P_0c09cf00;
case 0x0c09cf02u: goto P_0c09cf02;
case 0x0c09cf04u: goto P_0c09cf04;
case 0x0c09cf06u: goto P_0c09cf06;
case 0x0c09cf08u: goto P_0c09cf08;
case 0x0c09cf0au: goto P_0c09cf0a;
case 0x0c09cf0cu: goto P_0c09cf0c;
case 0x0c09cf0eu: goto P_0c09cf0e;
case 0x0c09cf10u: goto P_0c09cf10;
case 0x0c09cf12u: goto P_0c09cf12;
case 0x0c09cf14u: goto P_0c09cf14;
case 0x0c09cf16u: goto P_0c09cf16;
case 0x0c09cf18u: goto P_0c09cf18;
case 0x0c09cf1au: goto P_0c09cf1a;
case 0x0c09cf1cu: goto P_0c09cf1c;
case 0x0c09cf1eu: goto P_0c09cf1e;
case 0x0c09cf20u: goto P_0c09cf20;
case 0x0c09cf22u: goto P_0c09cf22;
case 0x0c09cf24u: goto P_0c09cf24;
case 0x0c09cf26u: goto P_0c09cf26;
case 0x0c09cf28u: goto P_0c09cf28;
case 0x0c09cf2au: goto P_0c09cf2a;
case 0x0c09cf2cu: goto P_0c09cf2c;
case 0x0c09cf2eu: goto P_0c09cf2e;
case 0x0c09cf30u: goto P_0c09cf30;
case 0x0c09cf32u: goto P_0c09cf32;
case 0x0c09cf34u: goto P_0c09cf34;
case 0x0c09cf36u: goto P_0c09cf36;
case 0x0c09cf38u: goto P_0c09cf38;
case 0x0c09cf3au: goto P_0c09cf3a;
case 0x0c09cf3cu: goto P_0c09cf3c;
case 0x0c09cf3eu: goto P_0c09cf3e;
case 0x0c09cf40u: goto P_0c09cf40;
case 0x0c09cf42u: goto P_0c09cf42;
case 0x0c09cf44u: goto P_0c09cf44;
case 0x0c09cf46u: goto P_0c09cf46;
case 0x0c09cf48u: goto P_0c09cf48;
case 0x0c09cf4au: goto P_0c09cf4a;
case 0x0c09cf4cu: goto P_0c09cf4c;
case 0x0c09cf4eu: goto P_0c09cf4e;
case 0x0c09cf50u: goto P_0c09cf50;
case 0x0c09cf52u: goto P_0c09cf52;
case 0x0c09cf54u: goto P_0c09cf54;
case 0x0c09cf56u: goto P_0c09cf56;
case 0x0c09cf58u: goto P_0c09cf58;
case 0x0c09cf5au: goto P_0c09cf5a;
case 0x0c09cf5cu: goto P_0c09cf5c;
case 0x0c09fe68u: goto P_0c09fe68;
case 0x0c09fe6au: goto P_0c09fe6a;
case 0x0c09fe6cu: goto P_0c09fe6c;
case 0x0c09fe6eu: goto P_0c09fe6e;
case 0x0c09fe70u: goto P_0c09fe70;
case 0x0c09fe72u: goto P_0c09fe72;
case 0x0c09fe74u: goto P_0c09fe74;
case 0x0c09fe76u: goto P_0c09fe76;
case 0x0c09fe78u: goto P_0c09fe78;
case 0x0c09fe7au: goto P_0c09fe7a;
case 0x0c09fe7cu: goto P_0c09fe7c;
case 0x0c09fe7eu: goto P_0c09fe7e;
case 0x0c09fe80u: goto P_0c09fe80;
case 0x0c09fe82u: goto P_0c09fe82;
case 0x0c09fe84u: goto P_0c09fe84;
case 0x0c09fe86u: goto P_0c09fe86;
case 0x0c09fe88u: goto P_0c09fe88;
case 0x0c09fe8au: goto P_0c09fe8a;
case 0x0c09fe8cu: goto P_0c09fe8c;
case 0x0c09fe8eu: goto P_0c09fe8e;
case 0x0c09fe90u: goto P_0c09fe90;
case 0x0c09fe92u: goto P_0c09fe92;
case 0x0c09fe94u: goto P_0c09fe94;
case 0x0c09fe96u: goto P_0c09fe96;
case 0x0c09fe98u: goto P_0c09fe98;
case 0x0c09fe9au: goto P_0c09fe9a;
case 0x0c09fe9cu: goto P_0c09fe9c;
case 0x0c09fe9eu: goto P_0c09fe9e;
case 0x0c09fea0u: goto P_0c09fea0;
case 0x0c09fea2u: goto P_0c09fea2;
case 0x0c09fea4u: goto P_0c09fea4;
case 0x0c09fea6u: goto P_0c09fea6;
case 0x0c09fea8u: goto P_0c09fea8;
case 0x0c09feaau: goto P_0c09feaa;
case 0x0c09feacu: goto P_0c09feac;
case 0x0c09feaeu: goto P_0c09feae;
case 0x0c09feb0u: goto P_0c09feb0;
case 0x0c09feb2u: goto P_0c09feb2;
case 0x0c09feb4u: goto P_0c09feb4;
case 0x0c09feb6u: goto P_0c09feb6;
case 0x0c09feb8u: goto P_0c09feb8;
case 0x0c09febau: goto P_0c09feba;
case 0x0c09febcu: goto P_0c09febc;
case 0x0c09febeu: goto P_0c09febe;
case 0x0c09fec0u: goto P_0c09fec0;
case 0x0c09fec2u: goto P_0c09fec2;
case 0x0c09fec4u: goto P_0c09fec4;
case 0x0c09fec6u: goto P_0c09fec6;
case 0x0c09fec8u: goto P_0c09fec8;
case 0x0c09fecau: goto P_0c09feca;
case 0x0c09feccu: goto P_0c09fecc;
case 0x0c09feceu: goto P_0c09fece;
case 0x0c09fed0u: goto P_0c09fed0;
case 0x0c09fed2u: goto P_0c09fed2;
case 0x0c09fed4u: goto P_0c09fed4;
case 0x0c09fed6u: goto P_0c09fed6;
case 0x0c09fed8u: goto P_0c09fed8;
case 0x0c09fedau: goto P_0c09feda;
case 0x0c09fedcu: goto P_0c09fedc;
case 0x0c09fedeu: goto P_0c09fede;
case 0x0c09fee0u: goto P_0c09fee0;
case 0x0c09fee2u: goto P_0c09fee2;
case 0x0c09fee4u: goto P_0c09fee4;
case 0x0c09fee6u: goto P_0c09fee6;
case 0x0c09fee8u: goto P_0c09fee8;
case 0x0c09feeau: goto P_0c09feea;
case 0x0c09feecu: goto P_0c09feec;
case 0x0c09feeeu: goto P_0c09feee;
case 0x0c09fef0u: goto P_0c09fef0;
case 0x0c09fef2u: goto P_0c09fef2;
case 0x0c09fef4u: goto P_0c09fef4;
case 0x0c09fef6u: goto P_0c09fef6;
case 0x0c09fef8u: goto P_0c09fef8;
case 0x0c09fefau: goto P_0c09fefa;
case 0x0c09fefcu: goto P_0c09fefc;
case 0x0c0a1282u: goto P_0c0a1282;
case 0x0c0a1284u: goto P_0c0a1284;
case 0x0c0a1286u: goto P_0c0a1286;
case 0x0c0a1288u: goto P_0c0a1288;
case 0x0c0a128au: goto P_0c0a128a;
case 0x0c0a128cu: goto P_0c0a128c;
case 0x0c0a128eu: goto P_0c0a128e;
case 0x0c0a1290u: goto P_0c0a1290;
case 0x0c0a1292u: goto P_0c0a1292;
case 0x0c0c66b8u: goto P_0c0c66b8;
case 0x0c0c66bau: goto P_0c0c66ba;
case 0x0c0c66d0u: goto P_0c0c66d0;
case 0x0c0c66d2u: goto P_0c0c66d2;
case 0x0c0c66d4u: goto P_0c0c66d4;
case 0x0c0c66d6u: goto P_0c0c66d6;
case 0x0c0c66d8u: goto P_0c0c66d8;
case 0x0c0c66dau: goto P_0c0c66da;
case 0x0c0c9b90u: goto P_0c0c9b90;
case 0x0c0c9b92u: goto P_0c0c9b92;
case 0x0c0c9bf8u: goto P_0c0c9bf8;
case 0x0c0c9bfau: goto P_0c0c9bfa;
default: return vf3_matrix_family(target,s,ram);
}
P_0c09ce8c: /* original 2fe6, guest PC 0x0c09ce8c */
if(!s->budget--) { s->failed_pc=0x0c09ce8cu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09ce8e;
P_0c09ce8e: /* original 2fd6, guest PC 0x0c09ce8e */
if(!s->budget--) { s->failed_pc=0x0c09ce8eu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09ce90;
P_0c09ce90: /* original 2fc6, guest PC 0x0c09ce90 */
if(!s->budget--) { s->failed_pc=0x0c09ce90u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09ce92;
P_0c09ce92: /* original 2fb6, guest PC 0x0c09ce92 */
if(!s->budget--) { s->failed_pc=0x0c09ce92u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09ce94;
P_0c09ce94: /* original 2fa6, guest PC 0x0c09ce94 */
if(!s->budget--) { s->failed_pc=0x0c09ce94u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09ce96;
P_0c09ce96: /* original 4f22, guest PC 0x0c09ce96 */
if(!s->budget--) { s->failed_pc=0x0c09ce96u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c09ce98;
P_0c09ce98: /* original d342, guest PC 0x0c09ce98 */
if(!s->budget--) { s->failed_pc=0x0c09ce98u; return 0; }
r[3]=read(ram,0x0c09cfa4u,4);
goto P_0c09ce9a;
P_0c09ce9a: /* original de41, guest PC 0x0c09ce9a */
if(!s->budget--) { s->failed_pc=0x0c09ce9au; return 0; }
r[14]=read(ram,0x0c09cfa0u,4);
goto P_0c09ce9c;
P_0c09ce9c: /* original 430b, guest PC 0x0c09ce9c */
if(!s->budget--) { s->failed_pc=0x0c09ce9cu; return 0; }
target=r[3];
r[16]=code_base|0x0c09cea0u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09cea0u) { target=s->pc; goto dispatch; }
goto P_0c09cea0;
P_0c09ce9e: /* original 0009, guest PC 0x0c09ce9e */
if(!s->budget--) { s->failed_pc=0x0c09ce9eu; return 0; }
goto P_0c09cea0;
P_0c09cea0: /* original 6d03, guest PC 0x0c09cea0 */
if(!s->budget--) { s->failed_pc=0x0c09cea0u; return 0; }
r[13]=r[0];
goto P_0c09cea2;
P_0c09cea2: /* original e07d, guest PC 0x0c09cea2 */
if(!s->budget--) { s->failed_pc=0x0c09cea2u; return 0; }
r[0]=0x0000007du;
goto P_0c09cea4;
P_0c09cea4: /* original e310, guest PC 0x0c09cea4 */
if(!s->budget--) { s->failed_pc=0x0c09cea4u; return 0; }
r[3]=0x00000010u;
goto P_0c09cea6;
P_0c09cea6: /* original eb00, guest PC 0x0c09cea6 */
if(!s->budget--) { s->failed_pc=0x0c09cea6u; return 0; }
r[11]=0x00000000u;
goto P_0c09cea8;
P_0c09cea8: /* original e240, guest PC 0x0c09cea8 */
if(!s->budget--) { s->failed_pc=0x0c09cea8u; return 0; }
r[2]=0x00000040u;
goto P_0c09ceaa;
P_0c09ceaa: /* original 23d8, guest PC 0x0c09ceaa */
if(!s->budget--) { s->failed_pc=0x0c09ceaau; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[13])==0)!=0);
goto P_0c09ceac;
P_0c09ceac: /* original 1e23, guest PC 0x0c09ceac */
if(!s->budget--) { s->failed_pc=0x0c09ceacu; return 0; }
write(ram,r[14]+12,r[2],4);
goto P_0c09ceae;
P_0c09ceae: /* original 1eb6, guest PC 0x0c09ceae */
if(!s->budget--) { s->failed_pc=0x0c09ceaeu; return 0; }
write(ram,r[14]+24,r[11],4);
goto P_0c09ceb0;
P_0c09ceb0: /* original 0eb4, guest PC 0x0c09ceb0 */
if(!s->budget--) { s->failed_pc=0x0c09ceb0u; return 0; }
write(ram,r[14]+r[0],r[11],1);
goto P_0c09ceb2;
P_0c09ceb2: /* original 9a6e, guest PC 0x0c09ceb2 */
if(!s->budget--) { s->failed_pc=0x0c09ceb2u; return 0; }
r[10]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09cf92u,2);
goto P_0c09ceb4;
P_0c09ceb4: /* original dc3c, guest PC 0x0c09ceb4 */
if(!s->budget--) { s->failed_pc=0x0c09ceb4u; return 0; }
r[12]=read(ram,0x0c09cfa8u,4);
goto P_0c09ceb6;
P_0c09ceb6: /* original 8d0b, guest PC 0x0c09ceb6 */
if(!s->budget--) { s->failed_pc=0x0c09ceb6u; return 0; }
cond=r[17]&1u;
write(ram,r[14]+20,r[11],4);
if(cond) { goto P_0c09ced0; }
goto P_0c09ceba;
P_0c09ceb8: /* original 1eb5, guest PC 0x0c09ceb8 */
if(!s->budget--) { s->failed_pc=0x0c09ceb8u; return 0; }
write(ram,r[14]+20,r[11],4);
goto P_0c09ceba;
P_0c09ceba: /* original 4c0b, guest PC 0x0c09ceba */
if(!s->budget--) { s->failed_pc=0x0c09cebau; return 0; }
target=r[12];
r[16]=code_base|0x0c09cebeu;
r[4]=r[10];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09cebeu) { target=s->pc; goto dispatch; }
goto P_0c09cebe;
P_0c09cebc: /* original 64a3, guest PC 0x0c09cebc */
if(!s->budget--) { s->failed_pc=0x0c09cebcu; return 0; }
r[4]=r[10];
goto P_0c09cebe;
P_0c09cebe: /* original 9069, guest PC 0x0c09cebe */
if(!s->budget--) { s->failed_pc=0x0c09cebeu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09cf94u,2);
goto P_0c09cec0;
P_0c09cec0: /* original 03ee, guest PC 0x0c09cec0 */
if(!s->budget--) { s->failed_pc=0x0c09cec0u; return 0; }
r[3]=read(ram,r[14]+r[0],4);
goto P_0c09cec2;
P_0c09cec2: /* original 73ff, guest PC 0x0c09cec2 */
if(!s->budget--) { s->failed_pc=0x0c09cec2u; return 0; }
r[3]+=0xffffffffu;
goto P_0c09cec4;
P_0c09cec4: /* original 0e36, guest PC 0x0c09cec4 */
if(!s->budget--) { s->failed_pc=0x0c09cec4u; return 0; }
write(ram,r[14]+r[0],r[3],4);
goto P_0c09cec6;
P_0c09cec6: /* original 02ee, guest PC 0x0c09cec6 */
if(!s->budget--) { s->failed_pc=0x0c09cec6u; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c09cec8;
P_0c09cec8: /* original 4211, guest PC 0x0c09cec8 */
if(!s->budget--) { s->failed_pc=0x0c09cec8u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[2]>=0)!=0);
goto P_0c09ceca;
P_0c09ceca: /* original 8901, guest PC 0x0c09ceca */
if(!s->budget--) { s->failed_pc=0x0c09cecau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09ced0; }
goto P_0c09cecc;
P_0c09cecc: /* original e103, guest PC 0x0c09cecc */
if(!s->budget--) { s->failed_pc=0x0c09ceccu; return 0; }
r[1]=0x00000003u;
goto P_0c09cece;
P_0c09cece: /* original 0e16, guest PC 0x0c09cece */
if(!s->budget--) { s->failed_pc=0x0c09ceceu; return 0; }
write(ram,r[14]+r[0],r[1],4);
goto P_0c09ced0;
P_0c09ced0: /* original e320, guest PC 0x0c09ced0 */
if(!s->budget--) { s->failed_pc=0x0c09ced0u; return 0; }
r[3]=0x00000020u;
goto P_0c09ced2;
P_0c09ced2: /* original 23d8, guest PC 0x0c09ced2 */
if(!s->budget--) { s->failed_pc=0x0c09ced2u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[13])==0)!=0);
goto P_0c09ced4;
P_0c09ced4: /* original 890a, guest PC 0x0c09ced4 */
if(!s->budget--) { s->failed_pc=0x0c09ced4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09ceec; }
goto P_0c09ced6;
P_0c09ced6: /* original 4c0b, guest PC 0x0c09ced6 */
if(!s->budget--) { s->failed_pc=0x0c09ced6u; return 0; }
target=r[12];
r[16]=code_base|0x0c09cedau;
r[4]=r[10];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09cedau) { target=s->pc; goto dispatch; }
goto P_0c09ceda;
P_0c09ced8: /* original 64a3, guest PC 0x0c09ced8 */
if(!s->budget--) { s->failed_pc=0x0c09ced8u; return 0; }
r[4]=r[10];
goto P_0c09ceda;
P_0c09ceda: /* original 905b, guest PC 0x0c09ceda */
if(!s->budget--) { s->failed_pc=0x0c09cedau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09cf94u,2);
goto P_0c09cedc;
P_0c09cedc: /* original e203, guest PC 0x0c09cedc */
if(!s->budget--) { s->failed_pc=0x0c09cedcu; return 0; }
r[2]=0x00000003u;
goto P_0c09cede;
P_0c09cede: /* original 03ee, guest PC 0x0c09cede */
if(!s->budget--) { s->failed_pc=0x0c09cedeu; return 0; }
r[3]=read(ram,r[14]+r[0],4);
goto P_0c09cee0;
P_0c09cee0: /* original 7301, guest PC 0x0c09cee0 */
if(!s->budget--) { s->failed_pc=0x0c09cee0u; return 0; }
r[3]+=0x00000001u;
goto P_0c09cee2;
P_0c09cee2: /* original 0e36, guest PC 0x0c09cee2 */
if(!s->budget--) { s->failed_pc=0x0c09cee2u; return 0; }
write(ram,r[14]+r[0],r[3],4);
goto P_0c09cee4;
P_0c09cee4: /* original 01ee, guest PC 0x0c09cee4 */
if(!s->budget--) { s->failed_pc=0x0c09cee4u; return 0; }
r[1]=read(ram,r[14]+r[0],4);
goto P_0c09cee6;
P_0c09cee6: /* original 3123, guest PC 0x0c09cee6 */
if(!s->budget--) { s->failed_pc=0x0c09cee6u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[1]>=(int32_t)r[2])!=0);
goto P_0c09cee8;
P_0c09cee8: /* original 8b00, guest PC 0x0c09cee8 */
if(!s->budget--) { s->failed_pc=0x0c09cee8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09ceec; }
goto P_0c09ceea;
P_0c09ceea: /* original 0eb6, guest PC 0x0c09ceea */
if(!s->budget--) { s->failed_pc=0x0c09ceeau; return 0; }
write(ram,r[14]+r[0],r[11],4);
goto P_0c09ceec;
P_0c09ceec: /* original e340, guest PC 0x0c09ceec */
if(!s->budget--) { s->failed_pc=0x0c09ceecu; return 0; }
r[3]=0x00000040u;
goto P_0c09ceee;
P_0c09ceee: /* original 23d8, guest PC 0x0c09ceee */
if(!s->budget--) { s->failed_pc=0x0c09ceeeu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[13])==0)!=0);
goto P_0c09cef0;
P_0c09cef0: /* original 8909, guest PC 0x0c09cef0 */
if(!s->budget--) { s->failed_pc=0x0c09cef0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09cf06; }
goto P_0c09cef2;
P_0c09cef2: /* original 4c0b, guest PC 0x0c09cef2 */
if(!s->budget--) { s->failed_pc=0x0c09cef2u; return 0; }
target=r[12];
r[16]=code_base|0x0c09cef6u;
r[4]=r[10];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09cef6u) { target=s->pc; goto dispatch; }
goto P_0c09cef6;
P_0c09cef4: /* original 64a3, guest PC 0x0c09cef4 */
if(!s->budget--) { s->failed_pc=0x0c09cef4u; return 0; }
r[4]=r[10];
goto P_0c09cef6;
P_0c09cef6: /* original 904e, guest PC 0x0c09cef6 */
if(!s->budget--) { s->failed_pc=0x0c09cef6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09cf96u,2);
goto P_0c09cef8;
P_0c09cef8: /* original 03ee, guest PC 0x0c09cef8 */
if(!s->budget--) { s->failed_pc=0x0c09cef8u; return 0; }
r[3]=read(ram,r[14]+r[0],4);
goto P_0c09cefa;
P_0c09cefa: /* original 73ff, guest PC 0x0c09cefa */
if(!s->budget--) { s->failed_pc=0x0c09cefau; return 0; }
r[3]+=0xffffffffu;
goto P_0c09cefc;
P_0c09cefc: /* original 0e36, guest PC 0x0c09cefc */
if(!s->budget--) { s->failed_pc=0x0c09cefcu; return 0; }
write(ram,r[14]+r[0],r[3],4);
goto P_0c09cefe;
P_0c09cefe: /* original 02ee, guest PC 0x0c09cefe */
if(!s->budget--) { s->failed_pc=0x0c09cefeu; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c09cf00;
P_0c09cf00: /* original 4211, guest PC 0x0c09cf00 */
if(!s->budget--) { s->failed_pc=0x0c09cf00u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[2]>=0)!=0);
goto P_0c09cf02;
P_0c09cf02: /* original 8900, guest PC 0x0c09cf02 */
if(!s->budget--) { s->failed_pc=0x0c09cf02u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09cf06; }
goto P_0c09cf04;
P_0c09cf04: /* original 0eb6, guest PC 0x0c09cf04 */
if(!s->budget--) { s->failed_pc=0x0c09cf04u; return 0; }
write(ram,r[14]+r[0],r[11],4);
goto P_0c09cf06;
P_0c09cf06: /* original 9347, guest PC 0x0c09cf06 */
if(!s->budget--) { s->failed_pc=0x0c09cf06u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09cf98u,2);
goto P_0c09cf08;
P_0c09cf08: /* original 23d8, guest PC 0x0c09cf08 */
if(!s->budget--) { s->failed_pc=0x0c09cf08u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[13])==0)!=0);
goto P_0c09cf0a;
P_0c09cf0a: /* original 890a, guest PC 0x0c09cf0a */
if(!s->budget--) { s->failed_pc=0x0c09cf0au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09cf22; }
goto P_0c09cf0c;
P_0c09cf0c: /* original 4c0b, guest PC 0x0c09cf0c */
if(!s->budget--) { s->failed_pc=0x0c09cf0cu; return 0; }
target=r[12];
r[16]=code_base|0x0c09cf10u;
r[4]=r[10];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09cf10u) { target=s->pc; goto dispatch; }
goto P_0c09cf10;
P_0c09cf0e: /* original 64a3, guest PC 0x0c09cf0e */
if(!s->budget--) { s->failed_pc=0x0c09cf0eu; return 0; }
r[4]=r[10];
goto P_0c09cf10;
P_0c09cf10: /* original 9041, guest PC 0x0c09cf10 */
if(!s->budget--) { s->failed_pc=0x0c09cf10u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09cf96u,2);
goto P_0c09cf12;
P_0c09cf12: /* original e401, guest PC 0x0c09cf12 */
if(!s->budget--) { s->failed_pc=0x0c09cf12u; return 0; }
r[4]=0x00000001u;
goto P_0c09cf14;
P_0c09cf14: /* original 03ee, guest PC 0x0c09cf14 */
if(!s->budget--) { s->failed_pc=0x0c09cf14u; return 0; }
r[3]=read(ram,r[14]+r[0],4);
goto P_0c09cf16;
P_0c09cf16: /* original 7301, guest PC 0x0c09cf16 */
if(!s->budget--) { s->failed_pc=0x0c09cf16u; return 0; }
r[3]+=0x00000001u;
goto P_0c09cf18;
P_0c09cf18: /* original 0e36, guest PC 0x0c09cf18 */
if(!s->budget--) { s->failed_pc=0x0c09cf18u; return 0; }
write(ram,r[14]+r[0],r[3],4);
goto P_0c09cf1a;
P_0c09cf1a: /* original 02ee, guest PC 0x0c09cf1a */
if(!s->budget--) { s->failed_pc=0x0c09cf1au; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c09cf1c;
P_0c09cf1c: /* original 3243, guest PC 0x0c09cf1c */
if(!s->budget--) { s->failed_pc=0x0c09cf1cu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[2]>=(int32_t)r[4])!=0);
goto P_0c09cf1e;
P_0c09cf1e: /* original 8b00, guest PC 0x0c09cf1e */
if(!s->budget--) { s->failed_pc=0x0c09cf1eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09cf22; }
goto P_0c09cf20;
P_0c09cf20: /* original 0e46, guest PC 0x0c09cf20 */
if(!s->budget--) { s->failed_pc=0x0c09cf20u; return 0; }
write(ram,r[14]+r[0],r[4],4);
goto P_0c09cf22;
P_0c09cf22: /* original e304, guest PC 0x0c09cf22 */
if(!s->budget--) { s->failed_pc=0x0c09cf22u; return 0; }
r[3]=0x00000004u;
goto P_0c09cf24;
P_0c09cf24: /* original 23d8, guest PC 0x0c09cf24 */
if(!s->budget--) { s->failed_pc=0x0c09cf24u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[13])==0)!=0);
goto P_0c09cf26;
P_0c09cf26: /* original 8902, guest PC 0x0c09cf26 */
if(!s->budget--) { s->failed_pc=0x0c09cf26u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09cf2e; }
goto P_0c09cf28;
P_0c09cf28: /* original 9437, guest PC 0x0c09cf28 */
if(!s->budget--) { s->failed_pc=0x0c09cf28u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09cf9au,2);
goto P_0c09cf2a;
P_0c09cf2a: /* original 4c0b, guest PC 0x0c09cf2a */
if(!s->budget--) { s->failed_pc=0x0c09cf2au; return 0; }
target=r[12];
r[16]=code_base|0x0c09cf2eu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09cf2eu) { target=s->pc; goto dispatch; }
goto P_0c09cf2e;
P_0c09cf2c: /* original 0009, guest PC 0x0c09cf2c */
if(!s->budget--) { s->failed_pc=0x0c09cf2cu; return 0; }
goto P_0c09cf2e;
P_0c09cf2e: /* original e30a, guest PC 0x0c09cf2e */
if(!s->budget--) { s->failed_pc=0x0c09cf2eu; return 0; }
r[3]=0x0000000au;
goto P_0c09cf30;
P_0c09cf30: /* original 23d8, guest PC 0x0c09cf30 */
if(!s->budget--) { s->failed_pc=0x0c09cf30u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[13])==0)!=0);
goto P_0c09cf32;
P_0c09cf32: /* original 890d, guest PC 0x0c09cf32 */
if(!s->budget--) { s->failed_pc=0x0c09cf32u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09cf50; }
goto P_0c09cf34;
P_0c09cf34: /* original e108, guest PC 0x0c09cf34 */
if(!s->budget--) { s->failed_pc=0x0c09cf34u; return 0; }
r[1]=0x00000008u;
goto P_0c09cf36;
P_0c09cf36: /* original 2d18, guest PC 0x0c09cf36 */
if(!s->budget--) { s->failed_pc=0x0c09cf36u; return 0; }
r[17]=(r[17]&~1u)|(((r[13]&r[1])==0)!=0);
goto P_0c09cf38;
P_0c09cf38: /* original 8902, guest PC 0x0c09cf38 */
if(!s->budget--) { s->failed_pc=0x0c09cf38u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09cf40; }
goto P_0c09cf3a;
P_0c09cf3a: /* original 942e, guest PC 0x0c09cf3a */
if(!s->budget--) { s->failed_pc=0x0c09cf3au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09cf9au,2);
goto P_0c09cf3c;
P_0c09cf3c: /* original a001, guest PC 0x0c09cf3c */
if(!s->budget--) { s->failed_pc=0x0c09cf3cu; return 0; }
goto P_0c09cf42;
P_0c09cf3e: /* original 0009, guest PC 0x0c09cf3e */
if(!s->budget--) { s->failed_pc=0x0c09cf3eu; return 0; }
goto P_0c09cf40;
P_0c09cf40: /* original 942c, guest PC 0x0c09cf40 */
if(!s->budget--) { s->failed_pc=0x0c09cf40u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09cf9cu,2);
goto P_0c09cf42;
P_0c09cf42: /* original 4c0b, guest PC 0x0c09cf42 */
if(!s->budget--) { s->failed_pc=0x0c09cf42u; return 0; }
target=r[12];
r[16]=code_base|0x0c09cf46u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09cf46u) { target=s->pc; goto dispatch; }
goto P_0c09cf46;
P_0c09cf44: /* original 0009, guest PC 0x0c09cf44 */
if(!s->budget--) { s->failed_pc=0x0c09cf44u; return 0; }
goto P_0c09cf46;
P_0c09cf46: /* original e005, guest PC 0x0c09cf46 */
if(!s->budget--) { s->failed_pc=0x0c09cf46u; return 0; }
r[0]=0x00000005u;
goto P_0c09cf48;
P_0c09cf48: /* original 80eb, guest PC 0x0c09cf48 */
if(!s->budget--) { s->failed_pc=0x0c09cf48u; return 0; }
write(ram,r[14]+11,r[0],1);
goto P_0c09cf4a;
P_0c09cf4a: /* original e010, guest PC 0x0c09cf4a */
if(!s->budget--) { s->failed_pc=0x0c09cf4au; return 0; }
r[0]=0x00000010u;
goto P_0c09cf4c;
P_0c09cf4c: /* original e374, guest PC 0x0c09cf4c */
if(!s->budget--) { s->failed_pc=0x0c09cf4cu; return 0; }
r[3]=0x00000074u;
goto P_0c09cf4e;
P_0c09cf4e: /* original 0e34, guest PC 0x0c09cf4e */
if(!s->budget--) { s->failed_pc=0x0c09cf4eu; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c09cf50;
P_0c09cf50: /* original 4f26, guest PC 0x0c09cf50 */
if(!s->budget--) { s->failed_pc=0x0c09cf50u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c09cf52;
P_0c09cf52: /* original 6af6, guest PC 0x0c09cf52 */
if(!s->budget--) { s->failed_pc=0x0c09cf52u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c09cf54;
P_0c09cf54: /* original 6bf6, guest PC 0x0c09cf54 */
if(!s->budget--) { s->failed_pc=0x0c09cf54u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c09cf56;
P_0c09cf56: /* original 6cf6, guest PC 0x0c09cf56 */
if(!s->budget--) { s->failed_pc=0x0c09cf56u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c09cf58;
P_0c09cf58: /* original 6df6, guest PC 0x0c09cf58 */
if(!s->budget--) { s->failed_pc=0x0c09cf58u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c09cf5a;
P_0c09cf5a: /* original 000b, guest PC 0x0c09cf5a */
if(!s->budget--) { s->failed_pc=0x0c09cf5au; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c09cf5c: /* original 6ef6, guest PC 0x0c09cf5c */
if(!s->budget--) { s->failed_pc=0x0c09cf5cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c09cf5eu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c09cf5eu; return 0; } return 1;
P_0c09fe68: /* original 2fe6, guest PC 0x0c09fe68 */
if(!s->budget--) { s->failed_pc=0x0c09fe68u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09fe6a;
P_0c09fe6a: /* original 2fd6, guest PC 0x0c09fe6a */
if(!s->budget--) { s->failed_pc=0x0c09fe6au; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09fe6c;
P_0c09fe6c: /* original 2fc6, guest PC 0x0c09fe6c */
if(!s->budget--) { s->failed_pc=0x0c09fe6cu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09fe6e;
P_0c09fe6e: /* original 2fb6, guest PC 0x0c09fe6e */
if(!s->budget--) { s->failed_pc=0x0c09fe6eu; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09fe70;
P_0c09fe70: /* original 2fa6, guest PC 0x0c09fe70 */
if(!s->budget--) { s->failed_pc=0x0c09fe70u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09fe72;
P_0c09fe72: /* original 2f96, guest PC 0x0c09fe72 */
if(!s->budget--) { s->failed_pc=0x0c09fe72u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09fe74;
P_0c09fe74: /* original e900, guest PC 0x0c09fe74 */
if(!s->budget--) { s->failed_pc=0x0c09fe74u; return 0; }
r[9]=0x00000000u;
goto P_0c09fe76;
P_0c09fe76: /* original 2f86, guest PC 0x0c09fe76 */
if(!s->budget--) { s->failed_pc=0x0c09fe76u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09fe78;
P_0c09fe78: /* original e812, guest PC 0x0c09fe78 */
if(!s->budget--) { s->failed_pc=0x0c09fe78u; return 0; }
r[8]=0x00000012u;
goto P_0c09fe7a;
P_0c09fe7a: /* original 4f22, guest PC 0x0c09fe7a */
if(!s->budget--) { s->failed_pc=0x0c09fe7au; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c09fe7c;
P_0c09fe7c: /* original d343, guest PC 0x0c09fe7c */
if(!s->budget--) { s->failed_pc=0x0c09fe7cu; return 0; }
r[3]=read(ram,0x0c09ff8cu,4);
goto P_0c09fe7e;
P_0c09fe7e: /* original 6e93, guest PC 0x0c09fe7e */
if(!s->budget--) { s->failed_pc=0x0c09fe7eu; return 0; }
r[14]=r[9];
goto P_0c09fe80;
P_0c09fe80: /* original dc41, guest PC 0x0c09fe80 */
if(!s->budget--) { s->failed_pc=0x0c09fe80u; return 0; }
r[12]=read(ram,0x0c09ff88u,4);
goto P_0c09fe82;
P_0c09fe82: /* original 7ff0, guest PC 0x0c09fe82 */
if(!s->budget--) { s->failed_pc=0x0c09fe82u; return 0; }
r[15]+=0xfffffff0u;
goto P_0c09fe84;
P_0c09fe84: /* original 2f32, guest PC 0x0c09fe84 */
if(!s->budget--) { s->failed_pc=0x0c09fe84u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c09fe86;
P_0c09fe86: /* original 6bc3, guest PC 0x0c09fe86 */
if(!s->budget--) { s->failed_pc=0x0c09fe86u; return 0; }
r[11]=r[12];
goto P_0c09fe88;
P_0c09fe88: /* original d241, guest PC 0x0c09fe88 */
if(!s->budget--) { s->failed_pc=0x0c09fe88u; return 0; }
r[2]=read(ram,0x0c09ff90u,4);
goto P_0c09fe8a;
P_0c09fe8a: /* original 1f23, guest PC 0x0c09fe8a */
if(!s->budget--) { s->failed_pc=0x0c09fe8au; return 0; }
write(ram,r[15]+12,r[2],4);
goto P_0c09fe8c;
P_0c09fe8c: /* original d341, guest PC 0x0c09fe8c */
if(!s->budget--) { s->failed_pc=0x0c09fe8cu; return 0; }
r[3]=read(ram,0x0c09ff94u,4);
goto P_0c09fe8e;
P_0c09fe8e: /* original 1f31, guest PC 0x0c09fe8e */
if(!s->budget--) { s->failed_pc=0x0c09fe8eu; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c09fe90;
P_0c09fe90: /* original d241, guest PC 0x0c09fe90 */
if(!s->budget--) { s->failed_pc=0x0c09fe90u; return 0; }
r[2]=read(ram,0x0c09ff98u,4);
goto P_0c09fe92;
P_0c09fe92: /* original 1f22, guest PC 0x0c09fe92 */
if(!s->budget--) { s->failed_pc=0x0c09fe92u; return 0; }
write(ram,r[15]+8,r[2],4);
goto P_0c09fe94;
P_0c09fe94: /* original 9a73, guest PC 0x0c09fe94 */
if(!s->budget--) { s->failed_pc=0x0c09fe94u; return 0; }
r[10]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09ff7eu,2);
goto P_0c09fe96;
P_0c09fe96: /* original dd41, guest PC 0x0c09fe96 */
if(!s->budget--) { s->failed_pc=0x0c09fe96u; return 0; }
r[13]=read(ram,0x0c09ff9cu,4);
goto P_0c09fe98;
P_0c09fe98: /* original 3acc, guest PC 0x0c09fe98 */
if(!s->budget--) { s->failed_pc=0x0c09fe98u; return 0; }
r[10]+=r[12];
goto P_0c09fe9a;
P_0c09fe9a: /* original 65f2, guest PC 0x0c09fe9a */
if(!s->budget--) { s->failed_pc=0x0c09fe9au; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c09fe9c;
P_0c09fe9c: /* original 7504, guest PC 0x0c09fe9c */
if(!s->budget--) { s->failed_pc=0x0c09fe9cu; return 0; }
r[5]+=0x00000004u;
goto P_0c09fe9e;
P_0c09fe9e: /* original 2f52, guest PC 0x0c09fe9e */
if(!s->budget--) { s->failed_pc=0x0c09fe9eu; return 0; }
write(ram,r[15],r[5],4);
goto P_0c09fea0;
P_0c09fea0: /* original 75fc, guest PC 0x0c09fea0 */
if(!s->budget--) { s->failed_pc=0x0c09fea0u; return 0; }
r[5]+=0xfffffffcu;
goto P_0c09fea2;
P_0c09fea2: /* original 6552, guest PC 0x0c09fea2 */
if(!s->budget--) { s->failed_pc=0x0c09fea2u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c09fea4;
P_0c09fea4: /* original 4d0b, guest PC 0x0c09fea4 */
if(!s->budget--) { s->failed_pc=0x0c09fea4u; return 0; }
target=r[13];
r[16]=code_base|0x0c09fea8u;
r[4]=r[11];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09fea8u) { target=s->pc; goto dispatch; }
goto P_0c09fea8;
P_0c09fea6: /* original 64b3, guest PC 0x0c09fea6 */
if(!s->budget--) { s->failed_pc=0x0c09fea6u; return 0; }
r[4]=r[11];
goto P_0c09fea8;
P_0c09fea8: /* original 55f3, guest PC 0x0c09fea8 */
if(!s->budget--) { s->failed_pc=0x0c09fea8u; return 0; }
r[5]=read(ram,r[15]+12,4);
goto P_0c09feaa;
P_0c09feaa: /* original 64c3, guest PC 0x0c09feaa */
if(!s->budget--) { s->failed_pc=0x0c09feaau; return 0; }
r[4]=r[12];
goto P_0c09feac;
P_0c09feac: /* original 7448, guest PC 0x0c09feac */
if(!s->budget--) { s->failed_pc=0x0c09feacu; return 0; }
r[4]+=0x00000048u;
goto P_0c09feae;
P_0c09feae: /* original 7504, guest PC 0x0c09feae */
if(!s->budget--) { s->failed_pc=0x0c09feaeu; return 0; }
r[5]+=0x00000004u;
goto P_0c09feb0;
P_0c09feb0: /* original 1f53, guest PC 0x0c09feb0 */
if(!s->budget--) { s->failed_pc=0x0c09feb0u; return 0; }
write(ram,r[15]+12,r[5],4);
goto P_0c09feb2;
P_0c09feb2: /* original 75fc, guest PC 0x0c09feb2 */
if(!s->budget--) { s->failed_pc=0x0c09feb2u; return 0; }
r[5]+=0xfffffffcu;
goto P_0c09feb4;
P_0c09feb4: /* original 6552, guest PC 0x0c09feb4 */
if(!s->budget--) { s->failed_pc=0x0c09feb4u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c09feb6;
P_0c09feb6: /* original 4d0b, guest PC 0x0c09feb6 */
if(!s->budget--) { s->failed_pc=0x0c09feb6u; return 0; }
target=r[13];
r[16]=code_base|0x0c09febau;
r[4]+=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09febau) { target=s->pc; goto dispatch; }
goto P_0c09feba;
P_0c09feb8: /* original 34ec, guest PC 0x0c09feb8 */
if(!s->budget--) { s->failed_pc=0x0c09feb8u; return 0; }
r[4]+=r[14];
goto P_0c09feba;
P_0c09feba: /* original 55f1, guest PC 0x0c09feba */
if(!s->budget--) { s->failed_pc=0x0c09febau; return 0; }
r[5]=read(ram,r[15]+4,4);
goto P_0c09febc;
P_0c09febc: /* original 7502, guest PC 0x0c09febc */
if(!s->budget--) { s->failed_pc=0x0c09febcu; return 0; }
r[5]+=0x00000002u;
goto P_0c09febe;
P_0c09febe: /* original 1f51, guest PC 0x0c09febe */
if(!s->budget--) { s->failed_pc=0x0c09febeu; return 0; }
write(ram,r[15]+4,r[5],4);
goto P_0c09fec0;
P_0c09fec0: /* original 75fe, guest PC 0x0c09fec0 */
if(!s->budget--) { s->failed_pc=0x0c09fec0u; return 0; }
r[5]+=0xfffffffeu;
goto P_0c09fec2;
P_0c09fec2: /* original 945d, guest PC 0x0c09fec2 */
if(!s->budget--) { s->failed_pc=0x0c09fec2u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09ff80u,2);
goto P_0c09fec4;
P_0c09fec4: /* original 6551, guest PC 0x0c09fec4 */
if(!s->budget--) { s->failed_pc=0x0c09fec4u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[5],2);
r[5]=tmp;
goto P_0c09fec6;
P_0c09fec6: /* original 34cc, guest PC 0x0c09fec6 */
if(!s->budget--) { s->failed_pc=0x0c09fec6u; return 0; }
r[4]+=r[12];
goto P_0c09fec8;
P_0c09fec8: /* original 655d, guest PC 0x0c09fec8 */
if(!s->budget--) { s->failed_pc=0x0c09fec8u; return 0; }
r[5]=r[5]&65535u;
goto P_0c09feca;
P_0c09feca: /* original 4d0b, guest PC 0x0c09feca */
if(!s->budget--) { s->failed_pc=0x0c09fecau; return 0; }
target=r[13];
r[16]=code_base|0x0c09feceu;
r[4]+=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09feceu) { target=s->pc; goto dispatch; }
goto P_0c09fece;
P_0c09fecc: /* original 34ec, guest PC 0x0c09fecc */
if(!s->budget--) { s->failed_pc=0x0c09feccu; return 0; }
r[4]+=r[14];
goto P_0c09fece;
P_0c09fece: /* original 55f2, guest PC 0x0c09fece */
if(!s->budget--) { s->failed_pc=0x0c09feceu; return 0; }
r[5]=read(ram,r[15]+8,4);
goto P_0c09fed0;
P_0c09fed0: /* original 7501, guest PC 0x0c09fed0 */
if(!s->budget--) { s->failed_pc=0x0c09fed0u; return 0; }
r[5]+=0x00000001u;
goto P_0c09fed2;
P_0c09fed2: /* original 1f52, guest PC 0x0c09fed2 */
if(!s->budget--) { s->failed_pc=0x0c09fed2u; return 0; }
write(ram,r[15]+8,r[5],4);
goto P_0c09fed4;
P_0c09fed4: /* original 75ff, guest PC 0x0c09fed4 */
if(!s->budget--) { s->failed_pc=0x0c09fed4u; return 0; }
r[5]+=0xffffffffu;
goto P_0c09fed6;
P_0c09fed6: /* original d332, guest PC 0x0c09fed6 */
if(!s->budget--) { s->failed_pc=0x0c09fed6u; return 0; }
r[3]=read(ram,0x0c09ffa0u,4);
goto P_0c09fed8;
P_0c09fed8: /* original 6550, guest PC 0x0c09fed8 */
if(!s->budget--) { s->failed_pc=0x0c09fed8u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[5],1);
r[5]=tmp;
goto P_0c09feda;
P_0c09feda: /* original 430b, guest PC 0x0c09feda */
if(!s->budget--) { s->failed_pc=0x0c09fedau; return 0; }
target=r[3];
r[16]=code_base|0x0c09fedeu;
r[4]=r[10];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09fedeu) { target=s->pc; goto dispatch; }
goto P_0c09fede;
P_0c09fedc: /* original 64a3, guest PC 0x0c09fedc */
if(!s->budget--) { s->failed_pc=0x0c09fedcu; return 0; }
r[4]=r[10];
goto P_0c09fede;
P_0c09fede: /* original 7901, guest PC 0x0c09fede */
if(!s->budget--) { s->failed_pc=0x0c09fedeu; return 0; }
r[9]+=0x00000001u;
goto P_0c09fee0;
P_0c09fee0: /* original 3983, guest PC 0x0c09fee0 */
if(!s->budget--) { s->failed_pc=0x0c09fee0u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[9]>=(int32_t)r[8])!=0);
goto P_0c09fee2;
P_0c09fee2: /* original 7e04, guest PC 0x0c09fee2 */
if(!s->budget--) { s->failed_pc=0x0c09fee2u; return 0; }
r[14]+=0x00000004u;
goto P_0c09fee4;
P_0c09fee4: /* original 7a01, guest PC 0x0c09fee4 */
if(!s->budget--) { s->failed_pc=0x0c09fee4u; return 0; }
r[10]+=0x00000001u;
goto P_0c09fee6;
P_0c09fee6: /* original 8fd8, guest PC 0x0c09fee6 */
if(!s->budget--) { s->failed_pc=0x0c09fee6u; return 0; }
cond=r[17]&1u;
r[11]+=0x00000004u;
if(!cond) { goto P_0c09fe9a; }
goto P_0c09feea;
P_0c09fee8: /* original 7b04, guest PC 0x0c09fee8 */
if(!s->budget--) { s->failed_pc=0x0c09fee8u; return 0; }
r[11]+=0x00000004u;
goto P_0c09feea;
P_0c09feea: /* original 7f10, guest PC 0x0c09feea */
if(!s->budget--) { s->failed_pc=0x0c09feeau; return 0; }
r[15]+=0x00000010u;
goto P_0c09feec;
P_0c09feec: /* original 4f26, guest PC 0x0c09feec */
if(!s->budget--) { s->failed_pc=0x0c09feecu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c09feee;
P_0c09feee: /* original 68f6, guest PC 0x0c09feee */
if(!s->budget--) { s->failed_pc=0x0c09feeeu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c09fef0;
P_0c09fef0: /* original 69f6, guest PC 0x0c09fef0 */
if(!s->budget--) { s->failed_pc=0x0c09fef0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c09fef2;
P_0c09fef2: /* original 6af6, guest PC 0x0c09fef2 */
if(!s->budget--) { s->failed_pc=0x0c09fef2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c09fef4;
P_0c09fef4: /* original 6bf6, guest PC 0x0c09fef4 */
if(!s->budget--) { s->failed_pc=0x0c09fef4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c09fef6;
P_0c09fef6: /* original 6cf6, guest PC 0x0c09fef6 */
if(!s->budget--) { s->failed_pc=0x0c09fef6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c09fef8;
P_0c09fef8: /* original 6df6, guest PC 0x0c09fef8 */
if(!s->budget--) { s->failed_pc=0x0c09fef8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c09fefa;
P_0c09fefa: /* original 000b, guest PC 0x0c09fefa */
if(!s->budget--) { s->failed_pc=0x0c09fefau; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c09fefc: /* original 6ef6, guest PC 0x0c09fefc */
if(!s->budget--) { s->failed_pc=0x0c09fefcu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c09fefeu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c09fefeu; return 0; } return 1;
P_0c0a1282: /* original 6043, guest PC 0x0c0a1282 */
if(!s->budget--) { s->failed_pc=0x0c0a1282u; return 0; }
r[0]=r[4];
goto P_0c0a1284;
P_0c0a1284: /* original 4008, guest PC 0x0c0a1284 */
if(!s->budget--) { s->failed_pc=0x0c0a1284u; return 0; }
r[0]<<=2;
goto P_0c0a1286;
P_0c0a1286: /* original 6343, guest PC 0x0c0a1286 */
if(!s->budget--) { s->failed_pc=0x0c0a1286u; return 0; }
r[3]=r[4];
goto P_0c0a1288;
P_0c0a1288: /* original 303c, guest PC 0x0c0a1288 */
if(!s->budget--) { s->failed_pc=0x0c0a1288u; return 0; }
r[0]+=r[3];
goto P_0c0a128a;
P_0c0a128a: /* original d21d, guest PC 0x0c0a128a */
if(!s->budget--) { s->failed_pc=0x0c0a128au; return 0; }
r[2]=read(ram,0x0c0a1300u,4);
goto P_0c0a128c;
P_0c0a128c: /* original 4008, guest PC 0x0c0a128c */
if(!s->budget--) { s->failed_pc=0x0c0a128cu; return 0; }
r[0]<<=2;
goto P_0c0a128e;
P_0c0a128e: /* original 600e, guest PC 0x0c0a128e */
if(!s->budget--) { s->failed_pc=0x0c0a128eu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)r[0];
goto P_0c0a1290;
P_0c0a1290: /* original 000b, guest PC 0x0c0a1290 */
if(!s->budget--) { s->failed_pc=0x0c0a1290u; return 0; }
target=r[16];
r[0]+=r[2];
s->pc=target; return ram->oob==0;
P_0c0a1292: /* original 302c, guest PC 0x0c0a1292 */
if(!s->budget--) { s->failed_pc=0x0c0a1292u; return 0; }
r[0]+=r[2];
if(!vf3_matrix_family(0x0c0a1294u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0a1294u; return 0; } return 1;
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
P_0c0c66d0: /* original 000b, guest PC 0x0c0c66d0 */
if(!s->budget--) { s->failed_pc=0x0c0c66d0u; return 0; }
target=r[16];
write(ram,r[4],r[5],1);
s->pc=target; return ram->oob==0;
P_0c0c66d2: /* original 2450, guest PC 0x0c0c66d2 */
if(!s->budget--) { s->failed_pc=0x0c0c66d2u; return 0; }
write(ram,r[4],r[5],1);
goto P_0c0c66d4;
P_0c0c66d4: /* original 000b, guest PC 0x0c0c66d4 */
if(!s->budget--) { s->failed_pc=0x0c0c66d4u; return 0; }
target=r[16];
write(ram,r[4],r[5],2);
s->pc=target; return ram->oob==0;
P_0c0c66d6: /* original 2451, guest PC 0x0c0c66d6 */
if(!s->budget--) { s->failed_pc=0x0c0c66d6u; return 0; }
write(ram,r[4],r[5],2);
goto P_0c0c66d8;
P_0c0c66d8: /* original 000b, guest PC 0x0c0c66d8 */
if(!s->budget--) { s->failed_pc=0x0c0c66d8u; return 0; }
target=r[16];
write(ram,r[4],r[5],4);
s->pc=target; return ram->oob==0;
P_0c0c66da: /* original 2452, guest PC 0x0c0c66da */
if(!s->budget--) { s->failed_pc=0x0c0c66dau; return 0; }
write(ram,r[4],r[5],4);
if(!vf3_matrix_family(0x0c0c66dcu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0c66dcu; return 0; } return 1;
P_0c0c9b90: /* original 000b, guest PC 0x0c0c9b90 */
if(!s->budget--) { s->failed_pc=0x0c0c9b90u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c0c9b92: /* original 0009, guest PC 0x0c0c9b92 */
if(!s->budget--) { s->failed_pc=0x0c0c9b92u; return 0; }
if(!vf3_matrix_family(0x0c0c9b94u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0c9b94u; return 0; } return 1;
P_0c0c9bf8: /* original 000b, guest PC 0x0c0c9bf8 */
if(!s->budget--) { s->failed_pc=0x0c0c9bf8u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c0c9bfa: /* original 0009, guest PC 0x0c0c9bfa */
if(!s->budget--) { s->failed_pc=0x0c0c9bfau; return 0; }
if(!vf3_matrix_family(0x0c0c9bfcu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0c9bfcu; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
