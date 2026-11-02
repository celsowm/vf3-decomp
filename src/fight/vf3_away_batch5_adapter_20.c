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
int vf3_away_batch5_adapter_20(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c04f98eu: goto P_0c04f98e;
case 0x0c04f990u: goto P_0c04f990;
case 0x0c04f992u: goto P_0c04f992;
case 0x0c04f994u: goto P_0c04f994;
case 0x0c04f996u: goto P_0c04f996;
case 0x0c04f998u: goto P_0c04f998;
case 0x0c04f99au: goto P_0c04f99a;
case 0x0c04f99cu: goto P_0c04f99c;
case 0x0c04f99eu: goto P_0c04f99e;
case 0x0c04f9a0u: goto P_0c04f9a0;
case 0x0c04f9a2u: goto P_0c04f9a2;
case 0x0c04f9a4u: goto P_0c04f9a4;
case 0x0c04f9a6u: goto P_0c04f9a6;
case 0x0c04f9a8u: goto P_0c04f9a8;
case 0x0c04f9aau: goto P_0c04f9aa;
case 0x0c04f9acu: goto P_0c04f9ac;
case 0x0c04f9aeu: goto P_0c04f9ae;
case 0x0c04f9b0u: goto P_0c04f9b0;
case 0x0c04f9b2u: goto P_0c04f9b2;
case 0x0c04f9b4u: goto P_0c04f9b4;
case 0x0c04f9b6u: goto P_0c04f9b6;
case 0x0c04f9b8u: goto P_0c04f9b8;
case 0x0c04f9bau: goto P_0c04f9ba;
case 0x0c04f9bcu: goto P_0c04f9bc;
case 0x0c04f9beu: goto P_0c04f9be;
case 0x0c04f9c0u: goto P_0c04f9c0;
case 0x0c04f9c2u: goto P_0c04f9c2;
case 0x0c04f9c4u: goto P_0c04f9c4;
case 0x0c04f9c6u: goto P_0c04f9c6;
case 0x0c04f9c8u: goto P_0c04f9c8;
case 0x0c04f9cau: goto P_0c04f9ca;
case 0x0c04f9ccu: goto P_0c04f9cc;
case 0x0c04f9ceu: goto P_0c04f9ce;
case 0x0c04f9d0u: goto P_0c04f9d0;
case 0x0c04f9d2u: goto P_0c04f9d2;
case 0x0c04f9d4u: goto P_0c04f9d4;
case 0x0c04f9d6u: goto P_0c04f9d6;
case 0x0c04f9f0u: goto P_0c04f9f0;
case 0x0c04f9f2u: goto P_0c04f9f2;
case 0x0c04f9f4u: goto P_0c04f9f4;
case 0x0c04f9f6u: goto P_0c04f9f6;
case 0x0c04f9f8u: goto P_0c04f9f8;
case 0x0c04f9fau: goto P_0c04f9fa;
case 0x0c04f9fcu: goto P_0c04f9fc;
case 0x0c04f9feu: goto P_0c04f9fe;
case 0x0c04fa00u: goto P_0c04fa00;
case 0x0c04fa02u: goto P_0c04fa02;
case 0x0c04fa04u: goto P_0c04fa04;
case 0x0c04fa06u: goto P_0c04fa06;
case 0x0c04fa08u: goto P_0c04fa08;
case 0x0c04fa0au: goto P_0c04fa0a;
case 0x0c04fa0cu: goto P_0c04fa0c;
case 0x0c04fa0eu: goto P_0c04fa0e;
case 0x0c04fa10u: goto P_0c04fa10;
case 0x0c04fa12u: goto P_0c04fa12;
case 0x0c04fa14u: goto P_0c04fa14;
case 0x0c04fa16u: goto P_0c04fa16;
case 0x0c04fa18u: goto P_0c04fa18;
case 0x0c04fa1au: goto P_0c04fa1a;
case 0x0c04fa1cu: goto P_0c04fa1c;
case 0x0c04fa1eu: goto P_0c04fa1e;
case 0x0c04fa20u: goto P_0c04fa20;
case 0x0c04fa22u: goto P_0c04fa22;
case 0x0c04fa24u: goto P_0c04fa24;
case 0x0c04fa26u: goto P_0c04fa26;
case 0x0c04fa28u: goto P_0c04fa28;
case 0x0c04fa2au: goto P_0c04fa2a;
case 0x0c04fa2cu: goto P_0c04fa2c;
case 0x0c04fa2eu: goto P_0c04fa2e;
case 0x0c04fa30u: goto P_0c04fa30;
case 0x0c04fa32u: goto P_0c04fa32;
case 0x0c04fa34u: goto P_0c04fa34;
case 0x0c04fa36u: goto P_0c04fa36;
case 0x0c04fa38u: goto P_0c04fa38;
case 0x0c04fa3au: goto P_0c04fa3a;
case 0x0c04fa3cu: goto P_0c04fa3c;
case 0x0c04fa3eu: goto P_0c04fa3e;
case 0x0c04fa40u: goto P_0c04fa40;
case 0x0c04fa42u: goto P_0c04fa42;
case 0x0c04fa44u: goto P_0c04fa44;
case 0x0c04fa46u: goto P_0c04fa46;
case 0x0c04fa48u: goto P_0c04fa48;
case 0x0c04fa4au: goto P_0c04fa4a;
case 0x0c04fa4cu: goto P_0c04fa4c;
case 0x0c04fa4eu: goto P_0c04fa4e;
case 0x0c04fa50u: goto P_0c04fa50;
case 0x0c04fa52u: goto P_0c04fa52;
case 0x0c04fa54u: goto P_0c04fa54;
case 0x0c04fa56u: goto P_0c04fa56;
case 0x0c04fa58u: goto P_0c04fa58;
case 0x0c04fa5au: goto P_0c04fa5a;
case 0x0c04fa5cu: goto P_0c04fa5c;
case 0x0c04fa5eu: goto P_0c04fa5e;
case 0x0c04fa60u: goto P_0c04fa60;
case 0x0c04fa62u: goto P_0c04fa62;
case 0x0c04fa64u: goto P_0c04fa64;
case 0x0c04fa66u: goto P_0c04fa66;
case 0x0c04fa68u: goto P_0c04fa68;
case 0x0c04fa6au: goto P_0c04fa6a;
case 0x0c04fa6cu: goto P_0c04fa6c;
case 0x0c04fa6eu: goto P_0c04fa6e;
case 0x0c04fa70u: goto P_0c04fa70;
case 0x0c04fa72u: goto P_0c04fa72;
case 0x0c04fa74u: goto P_0c04fa74;
case 0x0c04fa76u: goto P_0c04fa76;
case 0x0c04fa78u: goto P_0c04fa78;
case 0x0c04fa7au: goto P_0c04fa7a;
case 0x0c04fab0u: goto P_0c04fab0;
case 0x0c04fab2u: goto P_0c04fab2;
case 0x0c04fab4u: goto P_0c04fab4;
case 0x0c04fab6u: goto P_0c04fab6;
case 0x0c04fab8u: goto P_0c04fab8;
case 0x0c04fabau: goto P_0c04faba;
case 0x0c04fabcu: goto P_0c04fabc;
case 0x0c04fabeu: goto P_0c04fabe;
case 0x0c04fac0u: goto P_0c04fac0;
case 0x0c04fac2u: goto P_0c04fac2;
case 0x0c04fac4u: goto P_0c04fac4;
case 0x0c04fac6u: goto P_0c04fac6;
case 0x0c04fac8u: goto P_0c04fac8;
case 0x0c04facau: goto P_0c04faca;
case 0x0c04faccu: goto P_0c04facc;
case 0x0c04faceu: goto P_0c04face;
case 0x0c04fad0u: goto P_0c04fad0;
case 0x0c04fad2u: goto P_0c04fad2;
case 0x0c04fad4u: goto P_0c04fad4;
case 0x0c04fad6u: goto P_0c04fad6;
case 0x0c04fad8u: goto P_0c04fad8;
case 0x0c04fadau: goto P_0c04fada;
case 0x0c04fadcu: goto P_0c04fadc;
case 0x0c04fadeu: goto P_0c04fade;
case 0x0c04fae0u: goto P_0c04fae0;
case 0x0c04fae2u: goto P_0c04fae2;
case 0x0c04fafcu: goto P_0c04fafc;
case 0x0c04fafeu: goto P_0c04fafe;
case 0x0c04fb00u: goto P_0c04fb00;
case 0x0c04fb02u: goto P_0c04fb02;
case 0x0c04fb04u: goto P_0c04fb04;
case 0x0c04fb06u: goto P_0c04fb06;
case 0x0c04fb08u: goto P_0c04fb08;
case 0x0c04fb0au: goto P_0c04fb0a;
case 0x0c04fb0cu: goto P_0c04fb0c;
case 0x0c04fb0eu: goto P_0c04fb0e;
case 0x0c04fb10u: goto P_0c04fb10;
case 0x0c04fb12u: goto P_0c04fb12;
case 0x0c04fb14u: goto P_0c04fb14;
case 0x0c04fb16u: goto P_0c04fb16;
case 0x0c04fb18u: goto P_0c04fb18;
case 0x0c04fb1au: goto P_0c04fb1a;
case 0x0c04fb1cu: goto P_0c04fb1c;
case 0x0c04fb1eu: goto P_0c04fb1e;
case 0x0c04fb20u: goto P_0c04fb20;
case 0x0c04fb22u: goto P_0c04fb22;
case 0x0c04fb24u: goto P_0c04fb24;
case 0x0c04fb26u: goto P_0c04fb26;
case 0x0c04fb28u: goto P_0c04fb28;
case 0x0c04fb2au: goto P_0c04fb2a;
case 0x0c04fb2cu: goto P_0c04fb2c;
case 0x0c04fb2eu: goto P_0c04fb2e;
case 0x0c04fb30u: goto P_0c04fb30;
case 0x0c04fb32u: goto P_0c04fb32;
case 0x0c04fb34u: goto P_0c04fb34;
case 0x0c04fb36u: goto P_0c04fb36;
case 0x0c04fb38u: goto P_0c04fb38;
case 0x0c04fb3au: goto P_0c04fb3a;
case 0x0c04fb3cu: goto P_0c04fb3c;
case 0x0c04fb3eu: goto P_0c04fb3e;
case 0x0c04fb40u: goto P_0c04fb40;
case 0x0c04fb42u: goto P_0c04fb42;
case 0x0c04fb44u: goto P_0c04fb44;
case 0x0c04fb46u: goto P_0c04fb46;
case 0x0c04fb48u: goto P_0c04fb48;
case 0x0c04fb4au: goto P_0c04fb4a;
case 0x0c04fb4cu: goto P_0c04fb4c;
case 0x0c04fb4eu: goto P_0c04fb4e;
case 0x0c04fb50u: goto P_0c04fb50;
case 0x0c04fb52u: goto P_0c04fb52;
case 0x0c04fb54u: goto P_0c04fb54;
case 0x0c04fb56u: goto P_0c04fb56;
case 0x0c04fb58u: goto P_0c04fb58;
case 0x0c04fb5au: goto P_0c04fb5a;
case 0x0c04fb5cu: goto P_0c04fb5c;
case 0x0c04fb5eu: goto P_0c04fb5e;
case 0x0c04fb60u: goto P_0c04fb60;
case 0x0c04fb62u: goto P_0c04fb62;
case 0x0c04fb64u: goto P_0c04fb64;
case 0x0c04fb66u: goto P_0c04fb66;
case 0x0c04fb68u: goto P_0c04fb68;
case 0x0c04fb6au: goto P_0c04fb6a;
case 0x0c04fb6cu: goto P_0c04fb6c;
case 0x0c04fb6eu: goto P_0c04fb6e;
case 0x0c04fb70u: goto P_0c04fb70;
case 0x0c04fb72u: goto P_0c04fb72;
case 0x0c04fb74u: goto P_0c04fb74;
case 0x0c04fb76u: goto P_0c04fb76;
case 0x0c04fb78u: goto P_0c04fb78;
case 0x0c04fb7au: goto P_0c04fb7a;
case 0x0c04fb7cu: goto P_0c04fb7c;
case 0x0c04fb7eu: goto P_0c04fb7e;
case 0x0c04fb80u: goto P_0c04fb80;
case 0x0c04fb82u: goto P_0c04fb82;
case 0x0c04fb84u: goto P_0c04fb84;
case 0x0c04fb86u: goto P_0c04fb86;
case 0x0c04fb88u: goto P_0c04fb88;
case 0x0c04fb8au: goto P_0c04fb8a;
case 0x0c04fb8cu: goto P_0c04fb8c;
case 0x0c04fb8eu: goto P_0c04fb8e;
case 0x0c04fb90u: goto P_0c04fb90;
case 0x0c04fb92u: goto P_0c04fb92;
case 0x0c04fb94u: goto P_0c04fb94;
case 0x0c04fb96u: goto P_0c04fb96;
case 0x0c04fb98u: goto P_0c04fb98;
case 0x0c04fb9au: goto P_0c04fb9a;
case 0x0c04fb9cu: goto P_0c04fb9c;
case 0x0c04fb9eu: goto P_0c04fb9e;
case 0x0c04fba0u: goto P_0c04fba0;
case 0x0c04fba2u: goto P_0c04fba2;
case 0x0c04fba4u: goto P_0c04fba4;
case 0x0c04fba6u: goto P_0c04fba6;
case 0x0c04fba8u: goto P_0c04fba8;
case 0x0c04fbaau: goto P_0c04fbaa;
case 0x0c04fbacu: goto P_0c04fbac;
case 0x0c04fbaeu: goto P_0c04fbae;
case 0x0c04fbb0u: goto P_0c04fbb0;
case 0x0c04fbb2u: goto P_0c04fbb2;
case 0x0c04fbb4u: goto P_0c04fbb4;
case 0x0c04fbb6u: goto P_0c04fbb6;
default: return vf3_matrix_family(target,s,ram);
}
P_0c04f98e: /* original 2fe6, guest PC 0x0c04f98e */
if(!s->budget--) { s->failed_pc=0x0c04f98eu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04f990;
P_0c04f990: /* original 2fd6, guest PC 0x0c04f990 */
if(!s->budget--) { s->failed_pc=0x0c04f990u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04f992;
P_0c04f992: /* original 2fc6, guest PC 0x0c04f992 */
if(!s->budget--) { s->failed_pc=0x0c04f992u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04f994;
P_0c04f994: /* original 2fb6, guest PC 0x0c04f994 */
if(!s->budget--) { s->failed_pc=0x0c04f994u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04f996;
P_0c04f996: /* original 6b53, guest PC 0x0c04f996 */
if(!s->budget--) { s->failed_pc=0x0c04f996u; return 0; }
r[11]=r[5];
goto P_0c04f998;
P_0c04f998: /* original 2fa6, guest PC 0x0c04f998 */
if(!s->budget--) { s->failed_pc=0x0c04f998u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04f99a;
P_0c04f99a: /* original 4f22, guest PC 0x0c04f99a */
if(!s->budget--) { s->failed_pc=0x0c04f99au; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c04f99c;
P_0c04f99c: /* original 4f12, guest PC 0x0c04f99c */
if(!s->budget--) { s->failed_pc=0x0c04f99cu; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c04f99e;
P_0c04f99e: /* original 7ffc, guest PC 0x0c04f99e */
if(!s->budget--) { s->failed_pc=0x0c04f99eu; return 0; }
r[15]+=0xfffffffcu;
goto P_0c04f9a0;
P_0c04f9a0: /* original 2f62, guest PC 0x0c04f9a0 */
if(!s->budget--) { s->failed_pc=0x0c04f9a0u; return 0; }
write(ram,r[15],r[6],4);
goto P_0c04f9a2;
P_0c04f9a2: /* original 9c19, guest PC 0x0c04f9a2 */
if(!s->budget--) { s->failed_pc=0x0c04f9a2u; return 0; }
r[12]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04f9d8u,2);
goto P_0c04f9a4;
P_0c04f9a4: /* original d30e, guest PC 0x0c04f9a4 */
if(!s->budget--) { s->failed_pc=0x0c04f9a4u; return 0; }
r[3]=read(ram,0x0c04f9e0u,4);
goto P_0c04f9a6;
P_0c04f9a6: /* original 24cf, guest PC 0x0c04f9a6 */
if(!s->budget--) { s->failed_pc=0x0c04f9a6u; return 0; }
r[19]=(uint32_t)((int32_t)(int16_t)r[4]*(int32_t)(int16_t)r[12]);
goto P_0c04f9a8;
P_0c04f9a8: /* original 2fb6, guest PC 0x0c04f9a8 */
if(!s->budget--) { s->failed_pc=0x0c04f9a8u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04f9aa;
P_0c04f9aa: /* original d10f, guest PC 0x0c04f9aa */
if(!s->budget--) { s->failed_pc=0x0c04f9aau; return 0; }
r[1]=read(ram,0x0c04f9e8u,4);
goto P_0c04f9ac;
P_0c04f9ac: /* original d20d, guest PC 0x0c04f9ac */
if(!s->budget--) { s->failed_pc=0x0c04f9acu; return 0; }
r[2]=read(ram,0x0c04f9e4u,4);
goto P_0c04f9ae;
P_0c04f9ae: /* original 0c1a, guest PC 0x0c04f9ae */
if(!s->budget--) { s->failed_pc=0x0c04f9aeu; return 0; }
r[12]=r[19];
goto P_0c04f9b0;
P_0c04f9b0: /* original 6ccf, guest PC 0x0c04f9b0 */
if(!s->budget--) { s->failed_pc=0x0c04f9b0u; return 0; }
r[12]=(uint32_t)(int32_t)(int16_t)r[12];
goto P_0c04f9b2;
P_0c04f9b2: /* original 3c3c, guest PC 0x0c04f9b2 */
if(!s->budget--) { s->failed_pc=0x0c04f9b2u; return 0; }
r[12]+=r[3];
goto P_0c04f9b4;
P_0c04f9b4: /* original 410b, guest PC 0x0c04f9b4 */
if(!s->budget--) { s->failed_pc=0x0c04f9b4u; return 0; }
target=r[1];
r[16]=code_base|0x0c04f9b8u;
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04f9b8u) { target=s->pc; goto dispatch; }
goto P_0c04f9b8;
P_0c04f9b6: /* original 2f26, guest PC 0x0c04f9b6 */
if(!s->budget--) { s->failed_pc=0x0c04f9b6u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04f9b8;
P_0c04f9b8: /* original da0c, guest PC 0x0c04f9b8 */
if(!s->budget--) { s->failed_pc=0x0c04f9b8u; return 0; }
r[10]=read(ram,0x0c04f9ecu,4);
goto P_0c04f9ba;
P_0c04f9ba: /* original 7f08, guest PC 0x0c04f9ba */
if(!s->budget--) { s->failed_pc=0x0c04f9bau; return 0; }
r[15]+=0x00000008u;
goto P_0c04f9bc;
P_0c04f9bc: /* original 5eca, guest PC 0x0c04f9bc */
if(!s->budget--) { s->failed_pc=0x0c04f9bcu; return 0; }
r[14]=read(ram,r[12]+40,4);
goto P_0c04f9be;
P_0c04f9be: /* original a028, guest PC 0x0c04f9be */
if(!s->budget--) { s->failed_pc=0x0c04f9beu; return 0; }
r[13]=0x00000000u;
goto P_0c04fa12;
P_0c04f9c0: /* original ed00, guest PC 0x0c04f9c0 */
if(!s->budget--) { s->failed_pc=0x0c04f9c0u; return 0; }
r[13]=0x00000000u;
goto P_0c04f9c2;
P_0c04f9c2: /* original 64e0, guest PC 0x0c04f9c2 */
if(!s->budget--) { s->failed_pc=0x0c04f9c2u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[14],1);
r[4]=tmp;
goto P_0c04f9c4;
P_0c04f9c4: /* original 604c, guest PC 0x0c04f9c4 */
if(!s->budget--) { s->failed_pc=0x0c04f9c4u; return 0; }
r[0]=r[4]&255u;
goto P_0c04f9c6;
P_0c04f9c6: /* original 8800, guest PC 0x0c04f9c6 */
if(!s->budget--) { s->failed_pc=0x0c04f9c6u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000000u)!=0);
goto P_0c04f9c8;
P_0c04f9c8: /* original 8921, guest PC 0x0c04f9c8 */
if(!s->budget--) { s->failed_pc=0x0c04f9c8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04fa0e; }
goto P_0c04f9ca;
P_0c04f9ca: /* original 8833, guest PC 0x0c04f9ca */
if(!s->budget--) { s->failed_pc=0x0c04f9cau; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000033u)!=0);
goto P_0c04f9cc;
P_0c04f9cc: /* original 8910, guest PC 0x0c04f9cc */
if(!s->budget--) { s->failed_pc=0x0c04f9ccu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04f9f0; }
goto P_0c04f9ce;
P_0c04f9ce: /* original 9104, guest PC 0x0c04f9ce */
if(!s->budget--) { s->failed_pc=0x0c04f9ceu; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04f9dau,2);
goto P_0c04f9d0;
P_0c04f9d0: /* original 3010, guest PC 0x0c04f9d0 */
if(!s->budget--) { s->failed_pc=0x0c04f9d0u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==r[1])!=0);
goto P_0c04f9d2;
P_0c04f9d2: /* original 890d, guest PC 0x0c04f9d2 */
if(!s->budget--) { s->failed_pc=0x0c04f9d2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04f9f0; }
goto P_0c04f9d4;
P_0c04f9d4: /* original a01b, guest PC 0x0c04f9d4 */
if(!s->budget--) { s->failed_pc=0x0c04f9d4u; return 0; }
goto P_0c04fa0e;
P_0c04f9d6: /* original 0009, guest PC 0x0c04f9d6 */
if(!s->budget--) { s->failed_pc=0x0c04f9d6u; return 0; }
if(!vf3_matrix_family(0x0c04f9d8u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c04f9d8u; return 0; } return 1;
P_0c04f9f0: /* original 65e3, guest PC 0x0c04f9f0 */
if(!s->budget--) { s->failed_pc=0x0c04f9f0u; return 0; }
r[5]=r[14];
goto P_0c04f9f2;
P_0c04f9f2: /* original 7504, guest PC 0x0c04f9f2 */
if(!s->budget--) { s->failed_pc=0x0c04f9f2u; return 0; }
r[5]+=0x00000004u;
goto P_0c04f9f4;
P_0c04f9f4: /* original bf62, guest PC 0x0c04f9f4 */
if(!s->budget--) { s->failed_pc=0x0c04f9f4u; return 0; }
target=code_base|0x0c04f8bcu; r[16]=code_base|0x0c04f9f8u;
r[4]=r[11];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04f9f8u) { target=s->pc; goto dispatch; }
goto P_0c04f9f8;
P_0c04f9f6: /* original 64b3, guest PC 0x0c04f9f6 */
if(!s->budget--) { s->failed_pc=0x0c04f9f6u; return 0; }
r[4]=r[11];
goto P_0c04f9f8;
P_0c04f9f8: /* original 2008, guest PC 0x0c04f9f8 */
if(!s->budget--) { s->failed_pc=0x0c04f9f8u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c04f9fa;
P_0c04f9fa: /* original 8908, guest PC 0x0c04f9fa */
if(!s->budget--) { s->failed_pc=0x0c04f9fau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04fa0e; }
goto P_0c04f9fc;
P_0c04f9fc: /* original 65f2, guest PC 0x0c04f9fc */
if(!s->budget--) { s->failed_pc=0x0c04f9fcu; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c04f9fe;
P_0c04f9fe: /* original bf82, guest PC 0x0c04f9fe */
if(!s->budget--) { s->failed_pc=0x0c04f9feu; return 0; }
target=code_base|0x0c04f906u; r[16]=code_base|0x0c04fa02u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04fa02u) { target=s->pc; goto dispatch; }
goto P_0c04fa02;
P_0c04fa00: /* original 64e3, guest PC 0x0c04fa00 */
if(!s->budget--) { s->failed_pc=0x0c04fa00u; return 0; }
r[4]=r[14];
goto P_0c04fa02;
P_0c04fa02: /* original d239, guest PC 0x0c04fa02 */
if(!s->budget--) { s->failed_pc=0x0c04fa02u; return 0; }
r[2]=read(ram,0x0c04fae8u,4);
goto P_0c04fa04;
P_0c04fa04: /* original 420b, guest PC 0x0c04fa04 */
if(!s->budget--) { s->failed_pc=0x0c04fa04u; return 0; }
target=r[2];
r[16]=code_base|0x0c04fa08u;
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04fa08u) { target=s->pc; goto dispatch; }
goto P_0c04fa08;
P_0c04fa06: /* original 2fa6, guest PC 0x0c04fa06 */
if(!s->budget--) { s->failed_pc=0x0c04fa06u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04fa08;
P_0c04fa08: /* original 7f04, guest PC 0x0c04fa08 */
if(!s->budget--) { s->failed_pc=0x0c04fa08u; return 0; }
r[15]+=0x00000004u;
goto P_0c04fa0a;
P_0c04fa0a: /* original a00c, guest PC 0x0c04fa0a */
if(!s->budget--) { s->failed_pc=0x0c04fa0au; return 0; }
r[0]=r[13];
goto P_0c04fa26;
P_0c04fa0c: /* original 60d3, guest PC 0x0c04fa0c */
if(!s->budget--) { s->failed_pc=0x0c04fa0cu; return 0; }
r[0]=r[13];
goto P_0c04fa0e;
P_0c04fa0e: /* original 7e20, guest PC 0x0c04fa0e */
if(!s->budget--) { s->failed_pc=0x0c04fa0eu; return 0; }
r[14]+=0x00000020u;
goto P_0c04fa10;
P_0c04fa10: /* original 7d01, guest PC 0x0c04fa10 */
if(!s->budget--) { s->failed_pc=0x0c04fa10u; return 0; }
r[13]+=0x00000001u;
goto P_0c04fa12;
P_0c04fa12: /* original 52c7, guest PC 0x0c04fa12 */
if(!s->budget--) { s->failed_pc=0x0c04fa12u; return 0; }
r[2]=read(ram,r[12]+28,4);
goto P_0c04fa14;
P_0c04fa14: /* original 532c, guest PC 0x0c04fa14 */
if(!s->budget--) { s->failed_pc=0x0c04fa14u; return 0; }
r[3]=read(ram,r[2]+48,4);
goto P_0c04fa16;
P_0c04fa16: /* original 3d33, guest PC 0x0c04fa16 */
if(!s->budget--) { s->failed_pc=0x0c04fa16u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[13]>=(int32_t)r[3])!=0);
goto P_0c04fa18;
P_0c04fa18: /* original 8bd3, guest PC 0x0c04fa18 */
if(!s->budget--) { s->failed_pc=0x0c04fa18u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04f9c2; }
goto P_0c04fa1a;
P_0c04fa1a: /* original d333, guest PC 0x0c04fa1a */
if(!s->budget--) { s->failed_pc=0x0c04fa1au; return 0; }
r[3]=read(ram,0x0c04fae8u,4);
goto P_0c04fa1c;
P_0c04fa1c: /* original d133, guest PC 0x0c04fa1c */
if(!s->budget--) { s->failed_pc=0x0c04fa1cu; return 0; }
r[1]=read(ram,0x0c04faecu,4);
goto P_0c04fa1e;
P_0c04fa1e: /* original 430b, guest PC 0x0c04fa1e */
if(!s->budget--) { s->failed_pc=0x0c04fa1eu; return 0; }
target=r[3];
r[16]=code_base|0x0c04fa22u;
tmp=r[1]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04fa22u) { target=s->pc; goto dispatch; }
goto P_0c04fa22;
P_0c04fa20: /* original 2f16, guest PC 0x0c04fa20 */
if(!s->budget--) { s->failed_pc=0x0c04fa20u; return 0; }
tmp=r[1]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04fa22;
P_0c04fa22: /* original e0ff, guest PC 0x0c04fa22 */
if(!s->budget--) { s->failed_pc=0x0c04fa22u; return 0; }
r[0]=0xffffffffu;
goto P_0c04fa24;
P_0c04fa24: /* original 7f04, guest PC 0x0c04fa24 */
if(!s->budget--) { s->failed_pc=0x0c04fa24u; return 0; }
r[15]+=0x00000004u;
goto P_0c04fa26;
P_0c04fa26: /* original 7f04, guest PC 0x0c04fa26 */
if(!s->budget--) { s->failed_pc=0x0c04fa26u; return 0; }
r[15]+=0x00000004u;
goto P_0c04fa28;
P_0c04fa28: /* original 4f16, guest PC 0x0c04fa28 */
if(!s->budget--) { s->failed_pc=0x0c04fa28u; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c04fa2a;
P_0c04fa2a: /* original 4f26, guest PC 0x0c04fa2a */
if(!s->budget--) { s->failed_pc=0x0c04fa2au; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c04fa2c;
P_0c04fa2c: /* original 6af6, guest PC 0x0c04fa2c */
if(!s->budget--) { s->failed_pc=0x0c04fa2cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c04fa2e;
P_0c04fa2e: /* original 6bf6, guest PC 0x0c04fa2e */
if(!s->budget--) { s->failed_pc=0x0c04fa2eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c04fa30;
P_0c04fa30: /* original 6cf6, guest PC 0x0c04fa30 */
if(!s->budget--) { s->failed_pc=0x0c04fa30u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c04fa32;
P_0c04fa32: /* original 6df6, guest PC 0x0c04fa32 */
if(!s->budget--) { s->failed_pc=0x0c04fa32u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c04fa34;
P_0c04fa34: /* original 000b, guest PC 0x0c04fa34 */
if(!s->budget--) { s->failed_pc=0x0c04fa34u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c04fa36: /* original 6ef6, guest PC 0x0c04fa36 */
if(!s->budget--) { s->failed_pc=0x0c04fa36u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c04fa38;
P_0c04fa38: /* original 2fe6, guest PC 0x0c04fa38 */
if(!s->budget--) { s->failed_pc=0x0c04fa38u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04fa3a;
P_0c04fa3a: /* original 2fd6, guest PC 0x0c04fa3a */
if(!s->budget--) { s->failed_pc=0x0c04fa3au; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04fa3c;
P_0c04fa3c: /* original 4f22, guest PC 0x0c04fa3c */
if(!s->budget--) { s->failed_pc=0x0c04fa3cu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c04fa3e;
P_0c04fa3e: /* original 9651, guest PC 0x0c04fa3e */
if(!s->budget--) { s->failed_pc=0x0c04fa3eu; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04fae4u,2);
goto P_0c04fa40;
P_0c04fa40: /* original d32b, guest PC 0x0c04fa40 */
if(!s->budget--) { s->failed_pc=0x0c04fa40u; return 0; }
r[3]=read(ram,0x0c04faf0u,4);
goto P_0c04fa42;
P_0c04fa42: /* original 4f12, guest PC 0x0c04fa42 */
if(!s->budget--) { s->failed_pc=0x0c04fa42u; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c04fa44;
P_0c04fa44: /* original 246f, guest PC 0x0c04fa44 */
if(!s->budget--) { s->failed_pc=0x0c04fa44u; return 0; }
r[19]=(uint32_t)((int32_t)(int16_t)r[4]*(int32_t)(int16_t)r[6]);
goto P_0c04fa46;
P_0c04fa46: /* original 944e, guest PC 0x0c04fa46 */
if(!s->budget--) { s->failed_pc=0x0c04fa46u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04fae6u,2);
goto P_0c04fa48;
P_0c04fa48: /* original 061a, guest PC 0x0c04fa48 */
if(!s->budget--) { s->failed_pc=0x0c04fa48u; return 0; }
r[6]=r[19];
goto P_0c04fa4a;
P_0c04fa4a: /* original 666f, guest PC 0x0c04fa4a */
if(!s->budget--) { s->failed_pc=0x0c04fa4au; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)r[6];
goto P_0c04fa4c;
P_0c04fa4c: /* original 363c, guest PC 0x0c04fa4c */
if(!s->budget--) { s->failed_pc=0x0c04fa4cu; return 0; }
r[6]+=r[3];
goto P_0c04fa4e;
P_0c04fa4e: /* original 5d6a, guest PC 0x0c04fa4e */
if(!s->budget--) { s->failed_pc=0x0c04fa4eu; return 0; }
r[13]=read(ram,r[6]+40,4);
goto P_0c04fa50;
P_0c04fa50: /* original a00a, guest PC 0x0c04fa50 */
if(!s->budget--) { s->failed_pc=0x0c04fa50u; return 0; }
r[14]=0x00000000u;
goto P_0c04fa68;
P_0c04fa52: /* original ee00, guest PC 0x0c04fa52 */
if(!s->budget--) { s->failed_pc=0x0c04fa52u; return 0; }
r[14]=0x00000000u;
goto P_0c04fa54;
P_0c04fa54: /* original 67d0, guest PC 0x0c04fa54 */
if(!s->budget--) { s->failed_pc=0x0c04fa54u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[13],1);
r[7]=tmp;
goto P_0c04fa56;
P_0c04fa56: /* original 677c, guest PC 0x0c04fa56 */
if(!s->budget--) { s->failed_pc=0x0c04fa56u; return 0; }
r[7]=r[7]&255u;
goto P_0c04fa58;
P_0c04fa58: /* original 3740, guest PC 0x0c04fa58 */
if(!s->budget--) { s->failed_pc=0x0c04fa58u; return 0; }
r[17]=(r[17]&~1u)|((r[7]==r[4])!=0);
goto P_0c04fa5a;
P_0c04fa5a: /* original 8b03, guest PC 0x0c04fa5a */
if(!s->budget--) { s->failed_pc=0x0c04fa5au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04fa64; }
goto P_0c04fa5c;
P_0c04fa5c: /* original bf53, guest PC 0x0c04fa5c */
if(!s->budget--) { s->failed_pc=0x0c04fa5cu; return 0; }
target=code_base|0x0c04f906u; r[16]=code_base|0x0c04fa60u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04fa60u) { target=s->pc; goto dispatch; }
goto P_0c04fa60;
P_0c04fa5e: /* original 64d3, guest PC 0x0c04fa5e */
if(!s->budget--) { s->failed_pc=0x0c04fa5eu; return 0; }
r[4]=r[13];
goto P_0c04fa60;
P_0c04fa60: /* original a007, guest PC 0x0c04fa60 */
if(!s->budget--) { s->failed_pc=0x0c04fa60u; return 0; }
r[0]=r[14];
goto P_0c04fa72;
P_0c04fa62: /* original 60e3, guest PC 0x0c04fa62 */
if(!s->budget--) { s->failed_pc=0x0c04fa62u; return 0; }
r[0]=r[14];
goto P_0c04fa64;
P_0c04fa64: /* original 7d20, guest PC 0x0c04fa64 */
if(!s->budget--) { s->failed_pc=0x0c04fa64u; return 0; }
r[13]+=0x00000020u;
goto P_0c04fa66;
P_0c04fa66: /* original 7e01, guest PC 0x0c04fa66 */
if(!s->budget--) { s->failed_pc=0x0c04fa66u; return 0; }
r[14]+=0x00000001u;
goto P_0c04fa68;
P_0c04fa68: /* original 5367, guest PC 0x0c04fa68 */
if(!s->budget--) { s->failed_pc=0x0c04fa68u; return 0; }
r[3]=read(ram,r[6]+28,4);
goto P_0c04fa6a;
P_0c04fa6a: /* original 523c, guest PC 0x0c04fa6a */
if(!s->budget--) { s->failed_pc=0x0c04fa6au; return 0; }
r[2]=read(ram,r[3]+48,4);
goto P_0c04fa6c;
P_0c04fa6c: /* original 3e23, guest PC 0x0c04fa6c */
if(!s->budget--) { s->failed_pc=0x0c04fa6cu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[14]>=(int32_t)r[2])!=0);
goto P_0c04fa6e;
P_0c04fa6e: /* original 8bf1, guest PC 0x0c04fa6e */
if(!s->budget--) { s->failed_pc=0x0c04fa6eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04fa54; }
goto P_0c04fa70;
P_0c04fa70: /* original e0ff, guest PC 0x0c04fa70 */
if(!s->budget--) { s->failed_pc=0x0c04fa70u; return 0; }
r[0]=0xffffffffu;
goto P_0c04fa72;
P_0c04fa72: /* original 4f16, guest PC 0x0c04fa72 */
if(!s->budget--) { s->failed_pc=0x0c04fa72u; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c04fa74;
P_0c04fa74: /* original 4f26, guest PC 0x0c04fa74 */
if(!s->budget--) { s->failed_pc=0x0c04fa74u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c04fa76;
P_0c04fa76: /* original 6df6, guest PC 0x0c04fa76 */
if(!s->budget--) { s->failed_pc=0x0c04fa76u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c04fa78;
P_0c04fa78: /* original 000b, guest PC 0x0c04fa78 */
if(!s->budget--) { s->failed_pc=0x0c04fa78u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c04fa7a: /* original 6ef6, guest PC 0x0c04fa7a */
if(!s->budget--) { s->failed_pc=0x0c04fa7au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c04fa7cu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c04fa7cu; return 0; } return 1;
P_0c04fab0: /* original 2fe6, guest PC 0x0c04fab0 */
if(!s->budget--) { s->failed_pc=0x0c04fab0u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04fab2;
P_0c04fab2: /* original 6e43, guest PC 0x0c04fab2 */
if(!s->budget--) { s->failed_pc=0x0c04fab2u; return 0; }
r[14]=r[4];
goto P_0c04fab4;
P_0c04fab4: /* original 4f22, guest PC 0x0c04fab4 */
if(!s->budget--) { s->failed_pc=0x0c04fab4u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c04fab6;
P_0c04fab6: /* original 4f12, guest PC 0x0c04fab6 */
if(!s->budget--) { s->failed_pc=0x0c04fab6u; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c04fab8;
P_0c04fab8: /* original 7ffc, guest PC 0x0c04fab8 */
if(!s->budget--) { s->failed_pc=0x0c04fab8u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c04faba;
P_0c04faba: /* original 2f42, guest PC 0x0c04faba */
if(!s->budget--) { s->failed_pc=0x0c04fabau; return 0; }
write(ram,r[15],r[4],4);
goto P_0c04fabc;
P_0c04fabc: /* original 9312, guest PC 0x0c04fabc */
if(!s->budget--) { s->failed_pc=0x0c04fabcu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04fae4u,2);
goto P_0c04fabe;
P_0c04fabe: /* original d20c, guest PC 0x0c04fabe */
if(!s->budget--) { s->failed_pc=0x0c04fabeu; return 0; }
r[2]=read(ram,0x0c04faf0u,4);
goto P_0c04fac0;
P_0c04fac0: /* original 2e3f, guest PC 0x0c04fac0 */
if(!s->budget--) { s->failed_pc=0x0c04fac0u; return 0; }
r[19]=(uint32_t)((int32_t)(int16_t)r[14]*(int32_t)(int16_t)r[3]);
goto P_0c04fac2;
P_0c04fac2: /* original d309, guest PC 0x0c04fac2 */
if(!s->budget--) { s->failed_pc=0x0c04fac2u; return 0; }
r[3]=read(ram,0x0c04fae8u,4);
goto P_0c04fac4;
P_0c04fac4: /* original d10b, guest PC 0x0c04fac4 */
if(!s->budget--) { s->failed_pc=0x0c04fac4u; return 0; }
r[1]=read(ram,0x0c04faf4u,4);
goto P_0c04fac6;
P_0c04fac6: /* original 0e1a, guest PC 0x0c04fac6 */
if(!s->budget--) { s->failed_pc=0x0c04fac6u; return 0; }
r[14]=r[19];
goto P_0c04fac8;
P_0c04fac8: /* original 6eef, guest PC 0x0c04fac8 */
if(!s->budget--) { s->failed_pc=0x0c04fac8u; return 0; }
r[14]=(uint32_t)(int32_t)(int16_t)r[14];
goto P_0c04faca;
P_0c04faca: /* original 3e2c, guest PC 0x0c04faca */
if(!s->budget--) { s->failed_pc=0x0c04facau; return 0; }
r[14]+=r[2];
goto P_0c04facc;
P_0c04facc: /* original 430b, guest PC 0x0c04facc */
if(!s->budget--) { s->failed_pc=0x0c04faccu; return 0; }
target=r[3];
r[16]=code_base|0x0c04fad0u;
tmp=r[1]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04fad0u) { target=s->pc; goto dispatch; }
goto P_0c04fad0;
P_0c04face: /* original 2f16, guest PC 0x0c04face */
if(!s->budget--) { s->failed_pc=0x0c04faceu; return 0; }
tmp=r[1]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04fad0;
P_0c04fad0: /* original 54f1, guest PC 0x0c04fad0 */
if(!s->budget--) { s->failed_pc=0x0c04fad0u; return 0; }
r[4]=read(ram,r[15]+4,4);
goto P_0c04fad2;
P_0c04fad2: /* original 7f08, guest PC 0x0c04fad2 */
if(!s->budget--) { s->failed_pc=0x0c04fad2u; return 0; }
r[15]+=0x00000008u;
goto P_0c04fad4;
P_0c04fad4: /* original 4f16, guest PC 0x0c04fad4 */
if(!s->budget--) { s->failed_pc=0x0c04fad4u; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c04fad6;
P_0c04fad6: /* original 55e7, guest PC 0x0c04fad6 */
if(!s->budget--) { s->failed_pc=0x0c04fad6u; return 0; }
r[5]=read(ram,r[14]+28,4);
goto P_0c04fad8;
P_0c04fad8: /* original d307, guest PC 0x0c04fad8 */
if(!s->budget--) { s->failed_pc=0x0c04fad8u; return 0; }
r[3]=read(ram,0x0c04faf8u,4);
goto P_0c04fada;
P_0c04fada: /* original 4f26, guest PC 0x0c04fada */
if(!s->budget--) { s->failed_pc=0x0c04fadau; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c04fadc;
P_0c04fadc: /* original 56e8, guest PC 0x0c04fadc */
if(!s->budget--) { s->failed_pc=0x0c04fadcu; return 0; }
r[6]=read(ram,r[14]+32,4);
goto P_0c04fade;
P_0c04fade: /* original 5552, guest PC 0x0c04fade */
if(!s->budget--) { s->failed_pc=0x0c04fadeu; return 0; }
r[5]=read(ram,r[5]+8,4);
goto P_0c04fae0;
P_0c04fae0: /* original 432b, guest PC 0x0c04fae0 */
if(!s->budget--) { s->failed_pc=0x0c04fae0u; return 0; }
target=r[3];
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
P_0c04fae2: /* original 6ef6, guest PC 0x0c04fae2 */
if(!s->budget--) { s->failed_pc=0x0c04fae2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c04fae4u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c04fae4u; return 0; } return 1;
P_0c04fafc: /* original 2fe6, guest PC 0x0c04fafc */
if(!s->budget--) { s->failed_pc=0x0c04fafcu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04fafe;
P_0c04fafe: /* original 6e43, guest PC 0x0c04fafe */
if(!s->budget--) { s->failed_pc=0x0c04fafeu; return 0; }
r[14]=r[4];
goto P_0c04fb00;
P_0c04fb00: /* original 4f22, guest PC 0x0c04fb00 */
if(!s->budget--) { s->failed_pc=0x0c04fb00u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c04fb02;
P_0c04fb02: /* original 4f12, guest PC 0x0c04fb02 */
if(!s->budget--) { s->failed_pc=0x0c04fb02u; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c04fb04;
P_0c04fb04: /* original 7ffc, guest PC 0x0c04fb04 */
if(!s->budget--) { s->failed_pc=0x0c04fb04u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c04fb06;
P_0c04fb06: /* original 2f42, guest PC 0x0c04fb06 */
if(!s->budget--) { s->failed_pc=0x0c04fb06u; return 0; }
write(ram,r[15],r[4],4);
goto P_0c04fb08;
P_0c04fb08: /* original 9356, guest PC 0x0c04fb08 */
if(!s->budget--) { s->failed_pc=0x0c04fb08u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04fbb8u,2);
goto P_0c04fb0a;
P_0c04fb0a: /* original d22c, guest PC 0x0c04fb0a */
if(!s->budget--) { s->failed_pc=0x0c04fb0au; return 0; }
r[2]=read(ram,0x0c04fbbcu,4);
goto P_0c04fb0c;
P_0c04fb0c: /* original 2e3f, guest PC 0x0c04fb0c */
if(!s->budget--) { s->failed_pc=0x0c04fb0cu; return 0; }
r[19]=(uint32_t)((int32_t)(int16_t)r[14]*(int32_t)(int16_t)r[3]);
goto P_0c04fb0e;
P_0c04fb0e: /* original d32d, guest PC 0x0c04fb0e */
if(!s->budget--) { s->failed_pc=0x0c04fb0eu; return 0; }
r[3]=read(ram,0x0c04fbc4u,4);
goto P_0c04fb10;
P_0c04fb10: /* original d12b, guest PC 0x0c04fb10 */
if(!s->budget--) { s->failed_pc=0x0c04fb10u; return 0; }
r[1]=read(ram,0x0c04fbc0u,4);
goto P_0c04fb12;
P_0c04fb12: /* original 0e1a, guest PC 0x0c04fb12 */
if(!s->budget--) { s->failed_pc=0x0c04fb12u; return 0; }
r[14]=r[19];
goto P_0c04fb14;
P_0c04fb14: /* original 6eef, guest PC 0x0c04fb14 */
if(!s->budget--) { s->failed_pc=0x0c04fb14u; return 0; }
r[14]=(uint32_t)(int32_t)(int16_t)r[14];
goto P_0c04fb16;
P_0c04fb16: /* original 3e2c, guest PC 0x0c04fb16 */
if(!s->budget--) { s->failed_pc=0x0c04fb16u; return 0; }
r[14]+=r[2];
goto P_0c04fb18;
P_0c04fb18: /* original 430b, guest PC 0x0c04fb18 */
if(!s->budget--) { s->failed_pc=0x0c04fb18u; return 0; }
target=r[3];
r[16]=code_base|0x0c04fb1cu;
tmp=r[1]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04fb1cu) { target=s->pc; goto dispatch; }
goto P_0c04fb1c;
P_0c04fb1a: /* original 2f16, guest PC 0x0c04fb1a */
if(!s->budget--) { s->failed_pc=0x0c04fb1au; return 0; }
tmp=r[1]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04fb1c;
P_0c04fb1c: /* original 54f1, guest PC 0x0c04fb1c */
if(!s->budget--) { s->failed_pc=0x0c04fb1cu; return 0; }
r[4]=read(ram,r[15]+4,4);
goto P_0c04fb1e;
P_0c04fb1e: /* original 7f08, guest PC 0x0c04fb1e */
if(!s->budget--) { s->failed_pc=0x0c04fb1eu; return 0; }
r[15]+=0x00000008u;
goto P_0c04fb20;
P_0c04fb20: /* original 4f16, guest PC 0x0c04fb20 */
if(!s->budget--) { s->failed_pc=0x0c04fb20u; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c04fb22;
P_0c04fb22: /* original 55e7, guest PC 0x0c04fb22 */
if(!s->budget--) { s->failed_pc=0x0c04fb22u; return 0; }
r[5]=read(ram,r[14]+28,4);
goto P_0c04fb24;
P_0c04fb24: /* original d328, guest PC 0x0c04fb24 */
if(!s->budget--) { s->failed_pc=0x0c04fb24u; return 0; }
r[3]=read(ram,0x0c04fbc8u,4);
goto P_0c04fb26;
P_0c04fb26: /* original 4f26, guest PC 0x0c04fb26 */
if(!s->budget--) { s->failed_pc=0x0c04fb26u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c04fb28;
P_0c04fb28: /* original 56e8, guest PC 0x0c04fb28 */
if(!s->budget--) { s->failed_pc=0x0c04fb28u; return 0; }
r[6]=read(ram,r[14]+32,4);
goto P_0c04fb2a;
P_0c04fb2a: /* original 5552, guest PC 0x0c04fb2a */
if(!s->budget--) { s->failed_pc=0x0c04fb2au; return 0; }
r[5]=read(ram,r[5]+8,4);
goto P_0c04fb2c;
P_0c04fb2c: /* original 432b, guest PC 0x0c04fb2c */
if(!s->budget--) { s->failed_pc=0x0c04fb2cu; return 0; }
target=r[3];
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
P_0c04fb2e: /* original 6ef6, guest PC 0x0c04fb2e */
if(!s->budget--) { s->failed_pc=0x0c04fb2eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c04fb30;
P_0c04fb30: /* original 2fe6, guest PC 0x0c04fb30 */
if(!s->budget--) { s->failed_pc=0x0c04fb30u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04fb32;
P_0c04fb32: /* original 2fd6, guest PC 0x0c04fb32 */
if(!s->budget--) { s->failed_pc=0x0c04fb32u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04fb34;
P_0c04fb34: /* original 2fc6, guest PC 0x0c04fb34 */
if(!s->budget--) { s->failed_pc=0x0c04fb34u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04fb36;
P_0c04fb36: /* original 2fb6, guest PC 0x0c04fb36 */
if(!s->budget--) { s->failed_pc=0x0c04fb36u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04fb38;
P_0c04fb38: /* original 6b43, guest PC 0x0c04fb38 */
if(!s->budget--) { s->failed_pc=0x0c04fb38u; return 0; }
r[11]=r[4];
goto P_0c04fb3a;
P_0c04fb3a: /* original 2fa6, guest PC 0x0c04fb3a */
if(!s->budget--) { s->failed_pc=0x0c04fb3au; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04fb3c;
P_0c04fb3c: /* original 2f96, guest PC 0x0c04fb3c */
if(!s->budget--) { s->failed_pc=0x0c04fb3cu; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04fb3e;
P_0c04fb3e: /* original 4f22, guest PC 0x0c04fb3e */
if(!s->budget--) { s->failed_pc=0x0c04fb3eu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c04fb40;
P_0c04fb40: /* original 9d3a, guest PC 0x0c04fb40 */
if(!s->budget--) { s->failed_pc=0x0c04fb40u; return 0; }
r[13]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04fbb8u,2);
goto P_0c04fb42;
P_0c04fb42: /* original d31e, guest PC 0x0c04fb42 */
if(!s->budget--) { s->failed_pc=0x0c04fb42u; return 0; }
r[3]=read(ram,0x0c04fbbcu,4);
goto P_0c04fb44;
P_0c04fb44: /* original 4f12, guest PC 0x0c04fb44 */
if(!s->budget--) { s->failed_pc=0x0c04fb44u; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c04fb46;
P_0c04fb46: /* original 2bdf, guest PC 0x0c04fb46 */
if(!s->budget--) { s->failed_pc=0x0c04fb46u; return 0; }
r[19]=(uint32_t)((int32_t)(int16_t)r[11]*(int32_t)(int16_t)r[13]);
goto P_0c04fb48;
P_0c04fb48: /* original d220, guest PC 0x0c04fb48 */
if(!s->budget--) { s->failed_pc=0x0c04fb48u; return 0; }
r[2]=read(ram,0x0c04fbccu,4);
goto P_0c04fb4a;
P_0c04fb4a: /* original d11e, guest PC 0x0c04fb4a */
if(!s->budget--) { s->failed_pc=0x0c04fb4au; return 0; }
r[1]=read(ram,0x0c04fbc4u,4);
goto P_0c04fb4c;
P_0c04fb4c: /* original 0d1a, guest PC 0x0c04fb4c */
if(!s->budget--) { s->failed_pc=0x0c04fb4cu; return 0; }
r[13]=r[19];
goto P_0c04fb4e;
P_0c04fb4e: /* original 6ddf, guest PC 0x0c04fb4e */
if(!s->budget--) { s->failed_pc=0x0c04fb4eu; return 0; }
r[13]=(uint32_t)(int32_t)(int16_t)r[13];
goto P_0c04fb50;
P_0c04fb50: /* original 3d3c, guest PC 0x0c04fb50 */
if(!s->budget--) { s->failed_pc=0x0c04fb50u; return 0; }
r[13]+=r[3];
goto P_0c04fb52;
P_0c04fb52: /* original 410b, guest PC 0x0c04fb52 */
if(!s->budget--) { s->failed_pc=0x0c04fb52u; return 0; }
target=r[1];
r[16]=code_base|0x0c04fb56u;
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04fb56u) { target=s->pc; goto dispatch; }
goto P_0c04fb56;
P_0c04fb54: /* original 2f26, guest PC 0x0c04fb54 */
if(!s->budget--) { s->failed_pc=0x0c04fb54u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04fb56;
P_0c04fb56: /* original 5cd7, guest PC 0x0c04fb56 */
if(!s->budget--) { s->failed_pc=0x0c04fb56u; return 0; }
r[12]=read(ram,r[13]+28,4);
goto P_0c04fb58;
P_0c04fb58: /* original 5cc4, guest PC 0x0c04fb58 */
if(!s->budget--) { s->failed_pc=0x0c04fb58u; return 0; }
r[12]=read(ram,r[12]+16,4);
goto P_0c04fb5a;
P_0c04fb5a: /* original 2fc6, guest PC 0x0c04fb5a */
if(!s->budget--) { s->failed_pc=0x0c04fb5au; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04fb5c;
P_0c04fb5c: /* original d31c, guest PC 0x0c04fb5c */
if(!s->budget--) { s->failed_pc=0x0c04fb5cu; return 0; }
r[3]=read(ram,0x0c04fbd0u,4);
goto P_0c04fb5e;
P_0c04fb5e: /* original d219, guest PC 0x0c04fb5e */
if(!s->budget--) { s->failed_pc=0x0c04fb5eu; return 0; }
r[2]=read(ram,0x0c04fbc4u,4);
goto P_0c04fb60;
P_0c04fb60: /* original 420b, guest PC 0x0c04fb60 */
if(!s->budget--) { s->failed_pc=0x0c04fb60u; return 0; }
target=r[2];
r[16]=code_base|0x0c04fb64u;
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04fb64u) { target=s->pc; goto dispatch; }
goto P_0c04fb64;
P_0c04fb62: /* original 2f36, guest PC 0x0c04fb62 */
if(!s->budget--) { s->failed_pc=0x0c04fb62u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04fb64;
P_0c04fb64: /* original da1c, guest PC 0x0c04fb64 */
if(!s->budget--) { s->failed_pc=0x0c04fb64u; return 0; }
r[10]=read(ram,0x0c04fbd8u,4);
goto P_0c04fb66;
P_0c04fb66: /* original 4c15, guest PC 0x0c04fb66 */
if(!s->budget--) { s->failed_pc=0x0c04fb66u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[12]>0)!=0);
goto P_0c04fb68;
P_0c04fb68: /* original d91a, guest PC 0x0c04fb68 */
if(!s->budget--) { s->failed_pc=0x0c04fb68u; return 0; }
r[9]=read(ram,0x0c04fbd4u,4);
goto P_0c04fb6a;
P_0c04fb6a: /* original 7f0c, guest PC 0x0c04fb6a */
if(!s->budget--) { s->failed_pc=0x0c04fb6au; return 0; }
r[15]+=0x0000000cu;
goto P_0c04fb6c;
P_0c04fb6c: /* original 8f1a, guest PC 0x0c04fb6c */
if(!s->budget--) { s->failed_pc=0x0c04fb6cu; return 0; }
cond=r[17]&1u;
r[14]=0x00000000u;
if(!cond) { goto P_0c04fba4; }
goto P_0c04fb70;
P_0c04fb6e: /* original ee00, guest PC 0x0c04fb6e */
if(!s->budget--) { s->failed_pc=0x0c04fb6eu; return 0; }
r[14]=0x00000000u;
goto P_0c04fb70;
P_0c04fb70: /* original 52d7, guest PC 0x0c04fb70 */
if(!s->budget--) { s->failed_pc=0x0c04fb70u; return 0; }
r[2]=read(ram,r[13]+28,4);
goto P_0c04fb72;
P_0c04fb72: /* original 5323, guest PC 0x0c04fb72 */
if(!s->budget--) { s->failed_pc=0x0c04fb72u; return 0; }
r[3]=read(ram,r[2]+12,4);
goto P_0c04fb74;
P_0c04fb74: /* original 33ec, guest PC 0x0c04fb74 */
if(!s->budget--) { s->failed_pc=0x0c04fb74u; return 0; }
r[3]+=r[14];
goto P_0c04fb76;
P_0c04fb76: /* original 2f36, guest PC 0x0c04fb76 */
if(!s->budget--) { s->failed_pc=0x0c04fb76u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04fb78;
P_0c04fb78: /* original d212, guest PC 0x0c04fb78 */
if(!s->budget--) { s->failed_pc=0x0c04fb78u; return 0; }
r[2]=read(ram,0x0c04fbc4u,4);
goto P_0c04fb7a;
P_0c04fb7a: /* original 420b, guest PC 0x0c04fb7a */
if(!s->budget--) { s->failed_pc=0x0c04fb7au; return 0; }
target=r[2];
r[16]=code_base|0x0c04fb7eu;
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04fb7eu) { target=s->pc; goto dispatch; }
goto P_0c04fb7e;
P_0c04fb7c: /* original 2fa6, guest PC 0x0c04fb7c */
if(!s->budget--) { s->failed_pc=0x0c04fb7cu; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04fb7e;
P_0c04fb7e: /* original 55d7, guest PC 0x0c04fb7e */
if(!s->budget--) { s->failed_pc=0x0c04fb7eu; return 0; }
r[5]=read(ram,r[13]+28,4);
goto P_0c04fb80;
P_0c04fb80: /* original 66e3, guest PC 0x0c04fb80 */
if(!s->budget--) { s->failed_pc=0x0c04fb80u; return 0; }
r[6]=r[14];
goto P_0c04fb82;
P_0c04fb82: /* original 53d9, guest PC 0x0c04fb82 */
if(!s->budget--) { s->failed_pc=0x0c04fb82u; return 0; }
r[3]=read(ram,r[13]+36,4);
goto P_0c04fb84;
P_0c04fb84: /* original 4618, guest PC 0x0c04fb84 */
if(!s->budget--) { s->failed_pc=0x0c04fb84u; return 0; }
r[6]<<=8;
goto P_0c04fb86;
P_0c04fb86: /* original 5553, guest PC 0x0c04fb86 */
if(!s->budget--) { s->failed_pc=0x0c04fb86u; return 0; }
r[5]=read(ram,r[5]+12,4);
goto P_0c04fb88;
P_0c04fb88: /* original 4600, guest PC 0x0c04fb88 */
if(!s->budget--) { s->failed_pc=0x0c04fb88u; return 0; }
r[17]=(r[17]&~1u)|((r[6]>>31)!=0);
r[6]<<=1;
goto P_0c04fb8a;
P_0c04fb8a: /* original 7f08, guest PC 0x0c04fb8a */
if(!s->budget--) { s->failed_pc=0x0c04fb8au; return 0; }
r[15]+=0x00000008u;
goto P_0c04fb8c;
P_0c04fb8c: /* original 35ec, guest PC 0x0c04fb8c */
if(!s->budget--) { s->failed_pc=0x0c04fb8cu; return 0; }
r[5]+=r[14];
goto P_0c04fb8e;
P_0c04fb8e: /* original 363c, guest PC 0x0c04fb8e */
if(!s->budget--) { s->failed_pc=0x0c04fb8eu; return 0; }
r[6]+=r[3];
goto P_0c04fb90;
P_0c04fb90: /* original 490b, guest PC 0x0c04fb90 */
if(!s->budget--) { s->failed_pc=0x0c04fb90u; return 0; }
target=r[9];
r[16]=code_base|0x0c04fb94u;
r[4]=r[11];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04fb94u) { target=s->pc; goto dispatch; }
goto P_0c04fb94;
P_0c04fb92: /* original 64b3, guest PC 0x0c04fb92 */
if(!s->budget--) { s->failed_pc=0x0c04fb92u; return 0; }
r[4]=r[11];
goto P_0c04fb94;
P_0c04fb94: /* original 6403, guest PC 0x0c04fb94 */
if(!s->budget--) { s->failed_pc=0x0c04fb94u; return 0; }
r[4]=r[0];
goto P_0c04fb96;
P_0c04fb96: /* original 4411, guest PC 0x0c04fb96 */
if(!s->budget--) { s->failed_pc=0x0c04fb96u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=0)!=0);
goto P_0c04fb98;
P_0c04fb98: /* original 8901, guest PC 0x0c04fb98 */
if(!s->budget--) { s->failed_pc=0x0c04fb98u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04fb9e; }
goto P_0c04fb9a;
P_0c04fb9a: /* original a004, guest PC 0x0c04fb9a */
if(!s->budget--) { s->failed_pc=0x0c04fb9au; return 0; }
r[0]=r[4];
goto P_0c04fba6;
P_0c04fb9c: /* original 6043, guest PC 0x0c04fb9c */
if(!s->budget--) { s->failed_pc=0x0c04fb9cu; return 0; }
r[0]=r[4];
goto P_0c04fb9e;
P_0c04fb9e: /* original 7e01, guest PC 0x0c04fb9e */
if(!s->budget--) { s->failed_pc=0x0c04fb9eu; return 0; }
r[14]+=0x00000001u;
goto P_0c04fba0;
P_0c04fba0: /* original 3ec3, guest PC 0x0c04fba0 */
if(!s->budget--) { s->failed_pc=0x0c04fba0u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[14]>=(int32_t)r[12])!=0);
goto P_0c04fba2;
P_0c04fba2: /* original 8be5, guest PC 0x0c04fba2 */
if(!s->budget--) { s->failed_pc=0x0c04fba2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04fb70; }
goto P_0c04fba4;
P_0c04fba4: /* original e000, guest PC 0x0c04fba4 */
if(!s->budget--) { s->failed_pc=0x0c04fba4u; return 0; }
r[0]=0x00000000u;
goto P_0c04fba6;
P_0c04fba6: /* original 4f16, guest PC 0x0c04fba6 */
if(!s->budget--) { s->failed_pc=0x0c04fba6u; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c04fba8;
P_0c04fba8: /* original 4f26, guest PC 0x0c04fba8 */
if(!s->budget--) { s->failed_pc=0x0c04fba8u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c04fbaa;
P_0c04fbaa: /* original 69f6, guest PC 0x0c04fbaa */
if(!s->budget--) { s->failed_pc=0x0c04fbaau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c04fbac;
P_0c04fbac: /* original 6af6, guest PC 0x0c04fbac */
if(!s->budget--) { s->failed_pc=0x0c04fbacu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c04fbae;
P_0c04fbae: /* original 6bf6, guest PC 0x0c04fbae */
if(!s->budget--) { s->failed_pc=0x0c04fbaeu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c04fbb0;
P_0c04fbb0: /* original 6cf6, guest PC 0x0c04fbb0 */
if(!s->budget--) { s->failed_pc=0x0c04fbb0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c04fbb2;
P_0c04fbb2: /* original 6df6, guest PC 0x0c04fbb2 */
if(!s->budget--) { s->failed_pc=0x0c04fbb2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c04fbb4;
P_0c04fbb4: /* original 000b, guest PC 0x0c04fbb4 */
if(!s->budget--) { s->failed_pc=0x0c04fbb4u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c04fbb6: /* original 6ef6, guest PC 0x0c04fbb6 */
if(!s->budget--) { s->failed_pc=0x0c04fbb6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c04fbb8u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c04fbb8u; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
