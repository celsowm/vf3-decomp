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
int vf3_away_batch5_adapter_22(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c04fde8u: goto P_0c04fde8;
case 0x0c04fdeau: goto P_0c04fdea;
case 0x0c04fdecu: goto P_0c04fdec;
case 0x0c04fdeeu: goto P_0c04fdee;
case 0x0c04fdf0u: goto P_0c04fdf0;
case 0x0c04fdf2u: goto P_0c04fdf2;
case 0x0c04fdf4u: goto P_0c04fdf4;
case 0x0c04fdf6u: goto P_0c04fdf6;
case 0x0c04fdf8u: goto P_0c04fdf8;
case 0x0c04fdfau: goto P_0c04fdfa;
case 0x0c04fdfcu: goto P_0c04fdfc;
case 0x0c04fdfeu: goto P_0c04fdfe;
case 0x0c04fe00u: goto P_0c04fe00;
case 0x0c04fe02u: goto P_0c04fe02;
case 0x0c04fe04u: goto P_0c04fe04;
case 0x0c04fe06u: goto P_0c04fe06;
case 0x0c04fe08u: goto P_0c04fe08;
case 0x0c04fe0au: goto P_0c04fe0a;
case 0x0c04fe0cu: goto P_0c04fe0c;
case 0x0c04fe0eu: goto P_0c04fe0e;
case 0x0c04fe10u: goto P_0c04fe10;
case 0x0c04fe12u: goto P_0c04fe12;
case 0x0c04fe14u: goto P_0c04fe14;
case 0x0c04fe16u: goto P_0c04fe16;
case 0x0c04fe18u: goto P_0c04fe18;
case 0x0c04fe1au: goto P_0c04fe1a;
case 0x0c04fe1cu: goto P_0c04fe1c;
case 0x0c04fe1eu: goto P_0c04fe1e;
case 0x0c04fe20u: goto P_0c04fe20;
case 0x0c04fe22u: goto P_0c04fe22;
case 0x0c04fe24u: goto P_0c04fe24;
case 0x0c04fe26u: goto P_0c04fe26;
case 0x0c04fe28u: goto P_0c04fe28;
case 0x0c04fe2au: goto P_0c04fe2a;
case 0x0c04fe2cu: goto P_0c04fe2c;
case 0x0c04fe2eu: goto P_0c04fe2e;
case 0x0c04fe30u: goto P_0c04fe30;
case 0x0c04fe32u: goto P_0c04fe32;
case 0x0c04fe34u: goto P_0c04fe34;
case 0x0c04fe36u: goto P_0c04fe36;
case 0x0c04fe38u: goto P_0c04fe38;
case 0x0c04fe3au: goto P_0c04fe3a;
case 0x0c04fe3cu: goto P_0c04fe3c;
case 0x0c04fe3eu: goto P_0c04fe3e;
case 0x0c04fe40u: goto P_0c04fe40;
case 0x0c04fe42u: goto P_0c04fe42;
case 0x0c04fe44u: goto P_0c04fe44;
case 0x0c04fe46u: goto P_0c04fe46;
case 0x0c04fe48u: goto P_0c04fe48;
case 0x0c04fe4au: goto P_0c04fe4a;
case 0x0c04fe4cu: goto P_0c04fe4c;
case 0x0c04fe4eu: goto P_0c04fe4e;
case 0x0c04fe50u: goto P_0c04fe50;
case 0x0c04fe52u: goto P_0c04fe52;
case 0x0c04fe54u: goto P_0c04fe54;
case 0x0c04fe56u: goto P_0c04fe56;
case 0x0c04fe58u: goto P_0c04fe58;
case 0x0c04fe5au: goto P_0c04fe5a;
case 0x0c04fe5cu: goto P_0c04fe5c;
case 0x0c04fe5eu: goto P_0c04fe5e;
case 0x0c04fe60u: goto P_0c04fe60;
case 0x0c04fe62u: goto P_0c04fe62;
case 0x0c04fe64u: goto P_0c04fe64;
case 0x0c04fe66u: goto P_0c04fe66;
case 0x0c04fe68u: goto P_0c04fe68;
case 0x0c04fe6au: goto P_0c04fe6a;
case 0x0c04fe6cu: goto P_0c04fe6c;
case 0x0c04fe6eu: goto P_0c04fe6e;
case 0x0c04fe70u: goto P_0c04fe70;
case 0x0c04fe72u: goto P_0c04fe72;
case 0x0c04fe74u: goto P_0c04fe74;
case 0x0c04fe76u: goto P_0c04fe76;
case 0x0c04fe78u: goto P_0c04fe78;
case 0x0c04fe7au: goto P_0c04fe7a;
case 0x0c04fe7cu: goto P_0c04fe7c;
case 0x0c04fe7eu: goto P_0c04fe7e;
case 0x0c04fe80u: goto P_0c04fe80;
case 0x0c04fe82u: goto P_0c04fe82;
case 0x0c04fe84u: goto P_0c04fe84;
case 0x0c04fe86u: goto P_0c04fe86;
case 0x0c04fe88u: goto P_0c04fe88;
case 0x0c04fe8au: goto P_0c04fe8a;
case 0x0c04fe8cu: goto P_0c04fe8c;
case 0x0c04fe8eu: goto P_0c04fe8e;
case 0x0c04fe90u: goto P_0c04fe90;
case 0x0c04fe92u: goto P_0c04fe92;
case 0x0c04fe94u: goto P_0c04fe94;
case 0x0c04fe96u: goto P_0c04fe96;
case 0x0c04fe98u: goto P_0c04fe98;
case 0x0c04fe9au: goto P_0c04fe9a;
case 0x0c04fe9cu: goto P_0c04fe9c;
case 0x0c04fe9eu: goto P_0c04fe9e;
case 0x0c04fea0u: goto P_0c04fea0;
case 0x0c04fea2u: goto P_0c04fea2;
case 0x0c04fea4u: goto P_0c04fea4;
case 0x0c04fea6u: goto P_0c04fea6;
case 0x0c04fea8u: goto P_0c04fea8;
case 0x0c04feaau: goto P_0c04feaa;
case 0x0c04feacu: goto P_0c04feac;
case 0x0c04feaeu: goto P_0c04feae;
case 0x0c04feb0u: goto P_0c04feb0;
case 0x0c04feb2u: goto P_0c04feb2;
case 0x0c04feb4u: goto P_0c04feb4;
case 0x0c04feb6u: goto P_0c04feb6;
case 0x0c04feb8u: goto P_0c04feb8;
case 0x0c04febau: goto P_0c04feba;
case 0x0c04febcu: goto P_0c04febc;
case 0x0c04febeu: goto P_0c04febe;
case 0x0c04fec0u: goto P_0c04fec0;
case 0x0c04fec2u: goto P_0c04fec2;
case 0x0c04fed8u: goto P_0c04fed8;
case 0x0c04fedau: goto P_0c04feda;
case 0x0c04fedcu: goto P_0c04fedc;
case 0x0c04fedeu: goto P_0c04fede;
case 0x0c04fee0u: goto P_0c04fee0;
case 0x0c04fee2u: goto P_0c04fee2;
case 0x0c04fee4u: goto P_0c04fee4;
case 0x0c04fee6u: goto P_0c04fee6;
case 0x0c04fee8u: goto P_0c04fee8;
case 0x0c04feeau: goto P_0c04feea;
case 0x0c04feecu: goto P_0c04feec;
case 0x0c04feeeu: goto P_0c04feee;
case 0x0c04fef0u: goto P_0c04fef0;
case 0x0c04fef2u: goto P_0c04fef2;
case 0x0c04fef4u: goto P_0c04fef4;
case 0x0c04fef6u: goto P_0c04fef6;
case 0x0c04fef8u: goto P_0c04fef8;
case 0x0c04fefau: goto P_0c04fefa;
case 0x0c04fefcu: goto P_0c04fefc;
case 0x0c04fefeu: goto P_0c04fefe;
case 0x0c04ff00u: goto P_0c04ff00;
case 0x0c04ff02u: goto P_0c04ff02;
case 0x0c04ff04u: goto P_0c04ff04;
case 0x0c04ff06u: goto P_0c04ff06;
case 0x0c04ff08u: goto P_0c04ff08;
case 0x0c04ff0au: goto P_0c04ff0a;
case 0x0c04ff0cu: goto P_0c04ff0c;
case 0x0c04ff0eu: goto P_0c04ff0e;
case 0x0c04ff10u: goto P_0c04ff10;
case 0x0c04ff12u: goto P_0c04ff12;
case 0x0c04ff14u: goto P_0c04ff14;
case 0x0c04ff16u: goto P_0c04ff16;
case 0x0c04ff18u: goto P_0c04ff18;
case 0x0c04ff1au: goto P_0c04ff1a;
case 0x0c04ff1cu: goto P_0c04ff1c;
case 0x0c04ff1eu: goto P_0c04ff1e;
case 0x0c04ff20u: goto P_0c04ff20;
case 0x0c04ff22u: goto P_0c04ff22;
case 0x0c04ff24u: goto P_0c04ff24;
case 0x0c04ff26u: goto P_0c04ff26;
case 0x0c04ff28u: goto P_0c04ff28;
case 0x0c04ff2au: goto P_0c04ff2a;
case 0x0c04ff2cu: goto P_0c04ff2c;
case 0x0c04ff2eu: goto P_0c04ff2e;
case 0x0c04ff30u: goto P_0c04ff30;
case 0x0c04ff32u: goto P_0c04ff32;
case 0x0c04ff34u: goto P_0c04ff34;
case 0x0c04ff36u: goto P_0c04ff36;
case 0x0c04ff38u: goto P_0c04ff38;
case 0x0c04ff3au: goto P_0c04ff3a;
case 0x0c04ff3cu: goto P_0c04ff3c;
case 0x0c04ff3eu: goto P_0c04ff3e;
case 0x0c04ff40u: goto P_0c04ff40;
case 0x0c04ff42u: goto P_0c04ff42;
case 0x0c04ff44u: goto P_0c04ff44;
case 0x0c04ff46u: goto P_0c04ff46;
case 0x0c04ff48u: goto P_0c04ff48;
case 0x0c04ff4au: goto P_0c04ff4a;
case 0x0c04ff4cu: goto P_0c04ff4c;
case 0x0c04ff4eu: goto P_0c04ff4e;
case 0x0c04ff50u: goto P_0c04ff50;
case 0x0c04ff52u: goto P_0c04ff52;
case 0x0c04ff54u: goto P_0c04ff54;
case 0x0c04ff56u: goto P_0c04ff56;
case 0x0c04ff58u: goto P_0c04ff58;
case 0x0c04ff5au: goto P_0c04ff5a;
case 0x0c04ff5cu: goto P_0c04ff5c;
case 0x0c04ff5eu: goto P_0c04ff5e;
case 0x0c04ff60u: goto P_0c04ff60;
case 0x0c04ff62u: goto P_0c04ff62;
case 0x0c04ff64u: goto P_0c04ff64;
case 0x0c04ff66u: goto P_0c04ff66;
case 0x0c04ff68u: goto P_0c04ff68;
case 0x0c04ff6au: goto P_0c04ff6a;
case 0x0c04ff6cu: goto P_0c04ff6c;
case 0x0c04ff6eu: goto P_0c04ff6e;
case 0x0c04ff70u: goto P_0c04ff70;
case 0x0c04ff72u: goto P_0c04ff72;
case 0x0c04ff74u: goto P_0c04ff74;
case 0x0c04ff76u: goto P_0c04ff76;
case 0x0c04ff78u: goto P_0c04ff78;
case 0x0c04ff7au: goto P_0c04ff7a;
case 0x0c04ff7cu: goto P_0c04ff7c;
case 0x0c04ff7eu: goto P_0c04ff7e;
case 0x0c04ff80u: goto P_0c04ff80;
case 0x0c04ff82u: goto P_0c04ff82;
case 0x0c04ff84u: goto P_0c04ff84;
case 0x0c04ff86u: goto P_0c04ff86;
case 0x0c04ff88u: goto P_0c04ff88;
case 0x0c04ff8au: goto P_0c04ff8a;
case 0x0c04ff8cu: goto P_0c04ff8c;
case 0x0c04ff8eu: goto P_0c04ff8e;
case 0x0c04ff90u: goto P_0c04ff90;
case 0x0c04ff92u: goto P_0c04ff92;
case 0x0c04ff94u: goto P_0c04ff94;
case 0x0c04ff96u: goto P_0c04ff96;
case 0x0c04ff98u: goto P_0c04ff98;
case 0x0c04ff9au: goto P_0c04ff9a;
case 0x0c04ff9cu: goto P_0c04ff9c;
case 0x0c04ff9eu: goto P_0c04ff9e;
default: return vf3_matrix_family(target,s,ram);
}
P_0c04fde8: /* original 2fe6, guest PC 0x0c04fde8 */
if(!s->budget--) { s->failed_pc=0x0c04fde8u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04fdea;
P_0c04fdea: /* original 2fd6, guest PC 0x0c04fdea */
if(!s->budget--) { s->failed_pc=0x0c04fdeau; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04fdec;
P_0c04fdec: /* original 2fc6, guest PC 0x0c04fdec */
if(!s->budget--) { s->failed_pc=0x0c04fdecu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04fdee;
P_0c04fdee: /* original 4f22, guest PC 0x0c04fdee */
if(!s->budget--) { s->failed_pc=0x0c04fdeeu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c04fdf0;
P_0c04fdf0: /* original 4f12, guest PC 0x0c04fdf0 */
if(!s->budget--) { s->failed_pc=0x0c04fdf0u; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c04fdf2;
P_0c04fdf2: /* original 7ffc, guest PC 0x0c04fdf2 */
if(!s->budget--) { s->failed_pc=0x0c04fdf2u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c04fdf4;
P_0c04fdf4: /* original 2f51, guest PC 0x0c04fdf4 */
if(!s->budget--) { s->failed_pc=0x0c04fdf4u; return 0; }
write(ram,r[15],r[5],2);
goto P_0c04fdf6;
P_0c04fdf6: /* original 9d65, guest PC 0x0c04fdf6 */
if(!s->budget--) { s->failed_pc=0x0c04fdf6u; return 0; }
r[13]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04fec4u,2);
goto P_0c04fdf8;
P_0c04fdf8: /* original d333, guest PC 0x0c04fdf8 */
if(!s->budget--) { s->failed_pc=0x0c04fdf8u; return 0; }
r[3]=read(ram,0x0c04fec8u,4);
goto P_0c04fdfa;
P_0c04fdfa: /* original 24df, guest PC 0x0c04fdfa */
if(!s->budget--) { s->failed_pc=0x0c04fdfau; return 0; }
r[19]=(uint32_t)((int32_t)(int16_t)r[4]*(int32_t)(int16_t)r[13]);
goto P_0c04fdfc;
P_0c04fdfc: /* original dc33, guest PC 0x0c04fdfc */
if(!s->budget--) { s->failed_pc=0x0c04fdfcu; return 0; }
r[12]=read(ram,0x0c04feccu,4);
goto P_0c04fdfe;
P_0c04fdfe: /* original 0d1a, guest PC 0x0c04fdfe */
if(!s->budget--) { s->failed_pc=0x0c04fdfeu; return 0; }
r[13]=r[19];
goto P_0c04fe00;
P_0c04fe00: /* original 6ddf, guest PC 0x0c04fe00 */
if(!s->budget--) { s->failed_pc=0x0c04fe00u; return 0; }
r[13]=(uint32_t)(int32_t)(int16_t)r[13];
goto P_0c04fe02;
P_0c04fe02: /* original 3d3c, guest PC 0x0c04fe02 */
if(!s->budget--) { s->failed_pc=0x0c04fe02u; return 0; }
r[13]+=r[3];
goto P_0c04fe04;
P_0c04fe04: /* original 54d7, guest PC 0x0c04fe04 */
if(!s->budget--) { s->failed_pc=0x0c04fe04u; return 0; }
r[4]=read(ram,r[13]+28,4);
goto P_0c04fe06;
P_0c04fe06: /* original 544c, guest PC 0x0c04fe06 */
if(!s->budget--) { s->failed_pc=0x0c04fe06u; return 0; }
r[4]=read(ram,r[4]+48,4);
goto P_0c04fe08;
P_0c04fe08: /* original 6e43, guest PC 0x0c04fe08 */
if(!s->budget--) { s->failed_pc=0x0c04fe08u; return 0; }
r[14]=r[4];
goto P_0c04fe0a;
P_0c04fe0a: /* original 7eff, guest PC 0x0c04fe0a */
if(!s->budget--) { s->failed_pc=0x0c04fe0au; return 0; }
r[14]+=0xffffffffu;
goto P_0c04fe0c;
P_0c04fe0c: /* original 4e11, guest PC 0x0c04fe0c */
if(!s->budget--) { s->failed_pc=0x0c04fe0cu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[14]>=0)!=0);
goto P_0c04fe0e;
P_0c04fe0e: /* original 8b0f, guest PC 0x0c04fe0e */
if(!s->budget--) { s->failed_pc=0x0c04fe0eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04fe30; }
goto P_0c04fe10;
P_0c04fe10: /* original 63c2, guest PC 0x0c04fe10 */
if(!s->budget--) { s->failed_pc=0x0c04fe10u; return 0; }
tmp=read(ram,r[12],4);
r[3]=tmp;
goto P_0c04fe12;
P_0c04fe12: /* original 65e3, guest PC 0x0c04fe12 */
if(!s->budget--) { s->failed_pc=0x0c04fe12u; return 0; }
r[5]=r[14];
goto P_0c04fe14;
P_0c04fe14: /* original 4500, guest PC 0x0c04fe14 */
if(!s->budget--) { s->failed_pc=0x0c04fe14u; return 0; }
r[17]=(r[17]&~1u)|((r[5]>>31)!=0);
r[5]<<=1;
goto P_0c04fe16;
P_0c04fe16: /* original 5233, guest PC 0x0c04fe16 */
if(!s->budget--) { s->failed_pc=0x0c04fe16u; return 0; }
r[2]=read(ram,r[3]+12,4);
goto P_0c04fe18;
P_0c04fe18: /* original 420b, guest PC 0x0c04fe18 */
if(!s->budget--) { s->failed_pc=0x0c04fe18u; return 0; }
target=r[2];
r[16]=code_base|0x0c04fe1cu;
r[4]=read(ram,r[13]+36,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04fe1cu) { target=s->pc; goto dispatch; }
goto P_0c04fe1c;
P_0c04fe1a: /* original 54d9, guest PC 0x0c04fe1a */
if(!s->budget--) { s->failed_pc=0x0c04fe1au; return 0; }
r[4]=read(ram,r[13]+36,4);
goto P_0c04fe1c;
P_0c04fe1c: /* original 63f1, guest PC 0x0c04fe1c */
if(!s->budget--) { s->failed_pc=0x0c04fe1cu; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[15],2);
r[3]=tmp;
goto P_0c04fe1e;
P_0c04fe1e: /* original 600d, guest PC 0x0c04fe1e */
if(!s->budget--) { s->failed_pc=0x0c04fe1eu; return 0; }
r[0]=r[0]&65535u;
goto P_0c04fe20;
P_0c04fe20: /* original 633d, guest PC 0x0c04fe20 */
if(!s->budget--) { s->failed_pc=0x0c04fe20u; return 0; }
r[3]=r[3]&65535u;
goto P_0c04fe22;
P_0c04fe22: /* original 3030, guest PC 0x0c04fe22 */
if(!s->budget--) { s->failed_pc=0x0c04fe22u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==r[3])!=0);
goto P_0c04fe24;
P_0c04fe24: /* original 8b01, guest PC 0x0c04fe24 */
if(!s->budget--) { s->failed_pc=0x0c04fe24u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04fe2a; }
goto P_0c04fe26;
P_0c04fe26: /* original a004, guest PC 0x0c04fe26 */
if(!s->budget--) { s->failed_pc=0x0c04fe26u; return 0; }
r[0]=r[14];
goto P_0c04fe32;
P_0c04fe28: /* original 60e3, guest PC 0x0c04fe28 */
if(!s->budget--) { s->failed_pc=0x0c04fe28u; return 0; }
r[0]=r[14];
goto P_0c04fe2a;
P_0c04fe2a: /* original 7eff, guest PC 0x0c04fe2a */
if(!s->budget--) { s->failed_pc=0x0c04fe2au; return 0; }
r[14]+=0xffffffffu;
goto P_0c04fe2c;
P_0c04fe2c: /* original 4e11, guest PC 0x0c04fe2c */
if(!s->budget--) { s->failed_pc=0x0c04fe2cu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[14]>=0)!=0);
goto P_0c04fe2e;
P_0c04fe2e: /* original 89ef, guest PC 0x0c04fe2e */
if(!s->budget--) { s->failed_pc=0x0c04fe2eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04fe10; }
goto P_0c04fe30;
P_0c04fe30: /* original e0ff, guest PC 0x0c04fe30 */
if(!s->budget--) { s->failed_pc=0x0c04fe30u; return 0; }
r[0]=0xffffffffu;
goto P_0c04fe32;
P_0c04fe32: /* original 7f04, guest PC 0x0c04fe32 */
if(!s->budget--) { s->failed_pc=0x0c04fe32u; return 0; }
r[15]+=0x00000004u;
goto P_0c04fe34;
P_0c04fe34: /* original 4f16, guest PC 0x0c04fe34 */
if(!s->budget--) { s->failed_pc=0x0c04fe34u; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c04fe36;
P_0c04fe36: /* original 4f26, guest PC 0x0c04fe36 */
if(!s->budget--) { s->failed_pc=0x0c04fe36u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c04fe38;
P_0c04fe38: /* original 6cf6, guest PC 0x0c04fe38 */
if(!s->budget--) { s->failed_pc=0x0c04fe38u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c04fe3a;
P_0c04fe3a: /* original 6df6, guest PC 0x0c04fe3a */
if(!s->budget--) { s->failed_pc=0x0c04fe3au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c04fe3c;
P_0c04fe3c: /* original 000b, guest PC 0x0c04fe3c */
if(!s->budget--) { s->failed_pc=0x0c04fe3cu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c04fe3e: /* original 6ef6, guest PC 0x0c04fe3e */
if(!s->budget--) { s->failed_pc=0x0c04fe3eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c04fe40;
P_0c04fe40: /* original 2fe6, guest PC 0x0c04fe40 */
if(!s->budget--) { s->failed_pc=0x0c04fe40u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04fe42;
P_0c04fe42: /* original 2fd6, guest PC 0x0c04fe42 */
if(!s->budget--) { s->failed_pc=0x0c04fe42u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04fe44;
P_0c04fe44: /* original 6d53, guest PC 0x0c04fe44 */
if(!s->budget--) { s->failed_pc=0x0c04fe44u; return 0; }
r[13]=r[5];
goto P_0c04fe46;
P_0c04fe46: /* original 4f22, guest PC 0x0c04fe46 */
if(!s->budget--) { s->failed_pc=0x0c04fe46u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c04fe48;
P_0c04fe48: /* original 4f12, guest PC 0x0c04fe48 */
if(!s->budget--) { s->failed_pc=0x0c04fe48u; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c04fe4a;
P_0c04fe4a: /* original 7ffc, guest PC 0x0c04fe4a */
if(!s->budget--) { s->failed_pc=0x0c04fe4au; return 0; }
r[15]+=0xfffffffcu;
goto P_0c04fe4c;
P_0c04fe4c: /* original 2f61, guest PC 0x0c04fe4c */
if(!s->budget--) { s->failed_pc=0x0c04fe4cu; return 0; }
write(ram,r[15],r[6],2);
goto P_0c04fe4e;
P_0c04fe4e: /* original 9e39, guest PC 0x0c04fe4e */
if(!s->budget--) { s->failed_pc=0x0c04fe4eu; return 0; }
r[14]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04fec4u,2);
goto P_0c04fe50;
P_0c04fe50: /* original d31d, guest PC 0x0c04fe50 */
if(!s->budget--) { s->failed_pc=0x0c04fe50u; return 0; }
r[3]=read(ram,0x0c04fec8u,4);
goto P_0c04fe52;
P_0c04fe52: /* original 24ef, guest PC 0x0c04fe52 */
if(!s->budget--) { s->failed_pc=0x0c04fe52u; return 0; }
r[19]=(uint32_t)((int32_t)(int16_t)r[4]*(int32_t)(int16_t)r[14]);
goto P_0c04fe54;
P_0c04fe54: /* original 0e1a, guest PC 0x0c04fe54 */
if(!s->budget--) { s->failed_pc=0x0c04fe54u; return 0; }
r[14]=r[19];
goto P_0c04fe56;
P_0c04fe56: /* original 6eef, guest PC 0x0c04fe56 */
if(!s->budget--) { s->failed_pc=0x0c04fe56u; return 0; }
r[14]=(uint32_t)(int32_t)(int16_t)r[14];
goto P_0c04fe58;
P_0c04fe58: /* original 3e3c, guest PC 0x0c04fe58 */
if(!s->budget--) { s->failed_pc=0x0c04fe58u; return 0; }
r[14]+=r[3];
goto P_0c04fe5a;
P_0c04fe5a: /* original 52e7, guest PC 0x0c04fe5a */
if(!s->budget--) { s->failed_pc=0x0c04fe5au; return 0; }
r[2]=read(ram,r[14]+28,4);
goto P_0c04fe5c;
P_0c04fe5c: /* original 6122, guest PC 0x0c04fe5c */
if(!s->budget--) { s->failed_pc=0x0c04fe5cu; return 0; }
tmp=read(ram,r[2],4);
r[1]=tmp;
goto P_0c04fe5e;
P_0c04fe5e: /* original 3d17, guest PC 0x0c04fe5e */
if(!s->budget--) { s->failed_pc=0x0c04fe5eu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[13]>(int32_t)r[1])!=0);
goto P_0c04fe60;
P_0c04fe60: /* original 8b0a, guest PC 0x0c04fe60 */
if(!s->budget--) { s->failed_pc=0x0c04fe60u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04fe78; }
goto P_0c04fe62;
P_0c04fe62: /* original 60f1, guest PC 0x0c04fe62 */
if(!s->budget--) { s->failed_pc=0x0c04fe62u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[15],2);
r[0]=tmp;
goto P_0c04fe64;
P_0c04fe64: /* original 600d, guest PC 0x0c04fe64 */
if(!s->budget--) { s->failed_pc=0x0c04fe64u; return 0; }
r[0]=r[0]&65535u;
goto P_0c04fe66;
P_0c04fe66: /* original 2f06, guest PC 0x0c04fe66 */
if(!s->budget--) { s->failed_pc=0x0c04fe66u; return 0; }
tmp=r[0]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04fe68;
P_0c04fe68: /* original 2fd6, guest PC 0x0c04fe68 */
if(!s->budget--) { s->failed_pc=0x0c04fe68u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04fe6a;
P_0c04fe6a: /* original 2f46, guest PC 0x0c04fe6a */
if(!s->budget--) { s->failed_pc=0x0c04fe6au; return 0; }
tmp=r[4]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04fe6c;
P_0c04fe6c: /* original d218, guest PC 0x0c04fe6c */
if(!s->budget--) { s->failed_pc=0x0c04fe6cu; return 0; }
r[2]=read(ram,0x0c04fed0u,4);
goto P_0c04fe6e;
P_0c04fe6e: /* original d119, guest PC 0x0c04fe6e */
if(!s->budget--) { s->failed_pc=0x0c04fe6eu; return 0; }
r[1]=read(ram,0x0c04fed4u,4);
goto P_0c04fe70;
P_0c04fe70: /* original 410b, guest PC 0x0c04fe70 */
if(!s->budget--) { s->failed_pc=0x0c04fe70u; return 0; }
target=r[1];
r[16]=code_base|0x0c04fe74u;
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04fe74u) { target=s->pc; goto dispatch; }
goto P_0c04fe74;
P_0c04fe72: /* original 2f26, guest PC 0x0c04fe72 */
if(!s->budget--) { s->failed_pc=0x0c04fe72u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04fe74;
P_0c04fe74: /* original a00d, guest PC 0x0c04fe74 */
if(!s->budget--) { s->failed_pc=0x0c04fe74u; return 0; }
r[15]+=0x00000010u;
goto P_0c04fe92;
P_0c04fe76: /* original 7f10, guest PC 0x0c04fe76 */
if(!s->budget--) { s->failed_pc=0x0c04fe76u; return 0; }
r[15]+=0x00000010u;
goto P_0c04fe78;
P_0c04fe78: /* original 66f1, guest PC 0x0c04fe78 */
if(!s->budget--) { s->failed_pc=0x0c04fe78u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[15],2);
r[6]=tmp;
goto P_0c04fe7a;
P_0c04fe7a: /* original 7f04, guest PC 0x0c04fe7a */
if(!s->budget--) { s->failed_pc=0x0c04fe7au; return 0; }
r[15]+=0x00000004u;
goto P_0c04fe7c;
P_0c04fe7c: /* original 4f16, guest PC 0x0c04fe7c */
if(!s->budget--) { s->failed_pc=0x0c04fe7cu; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c04fe7e;
P_0c04fe7e: /* original d113, guest PC 0x0c04fe7e */
if(!s->budget--) { s->failed_pc=0x0c04fe7eu; return 0; }
r[1]=read(ram,0x0c04feccu,4);
goto P_0c04fe80;
P_0c04fe80: /* original 65d3, guest PC 0x0c04fe80 */
if(!s->budget--) { s->failed_pc=0x0c04fe80u; return 0; }
r[5]=r[13];
goto P_0c04fe82;
P_0c04fe82: /* original 54e9, guest PC 0x0c04fe82 */
if(!s->budget--) { s->failed_pc=0x0c04fe82u; return 0; }
r[4]=read(ram,r[14]+36,4);
goto P_0c04fe84;
P_0c04fe84: /* original 4500, guest PC 0x0c04fe84 */
if(!s->budget--) { s->failed_pc=0x0c04fe84u; return 0; }
r[17]=(r[17]&~1u)|((r[5]>>31)!=0);
r[5]<<=1;
goto P_0c04fe86;
P_0c04fe86: /* original 4f26, guest PC 0x0c04fe86 */
if(!s->budget--) { s->failed_pc=0x0c04fe86u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c04fe88;
P_0c04fe88: /* original 6312, guest PC 0x0c04fe88 */
if(!s->budget--) { s->failed_pc=0x0c04fe88u; return 0; }
tmp=read(ram,r[1],4);
r[3]=tmp;
goto P_0c04fe8a;
P_0c04fe8a: /* original 5234, guest PC 0x0c04fe8a */
if(!s->budget--) { s->failed_pc=0x0c04fe8au; return 0; }
r[2]=read(ram,r[3]+16,4);
goto P_0c04fe8c;
P_0c04fe8c: /* original 6df6, guest PC 0x0c04fe8c */
if(!s->budget--) { s->failed_pc=0x0c04fe8cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c04fe8e;
P_0c04fe8e: /* original 422b, guest PC 0x0c04fe8e */
if(!s->budget--) { s->failed_pc=0x0c04fe8eu; return 0; }
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
P_0c04fe90: /* original 6ef6, guest PC 0x0c04fe90 */
if(!s->budget--) { s->failed_pc=0x0c04fe90u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c04fe92;
P_0c04fe92: /* original 7f04, guest PC 0x0c04fe92 */
if(!s->budget--) { s->failed_pc=0x0c04fe92u; return 0; }
r[15]+=0x00000004u;
goto P_0c04fe94;
P_0c04fe94: /* original 4f16, guest PC 0x0c04fe94 */
if(!s->budget--) { s->failed_pc=0x0c04fe94u; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c04fe96;
P_0c04fe96: /* original 4f26, guest PC 0x0c04fe96 */
if(!s->budget--) { s->failed_pc=0x0c04fe96u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c04fe98;
P_0c04fe98: /* original 6df6, guest PC 0x0c04fe98 */
if(!s->budget--) { s->failed_pc=0x0c04fe98u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c04fe9a;
P_0c04fe9a: /* original 000b, guest PC 0x0c04fe9a */
if(!s->budget--) { s->failed_pc=0x0c04fe9au; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c04fe9c: /* original 6ef6, guest PC 0x0c04fe9c */
if(!s->budget--) { s->failed_pc=0x0c04fe9cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c04fe9e;
P_0c04fe9e: /* original 4f12, guest PC 0x0c04fe9e */
if(!s->budget--) { s->failed_pc=0x0c04fe9eu; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c04fea0;
P_0c04fea0: /* original 7ff8, guest PC 0x0c04fea0 */
if(!s->budget--) { s->failed_pc=0x0c04fea0u; return 0; }
r[15]+=0xfffffff8u;
goto P_0c04fea2;
P_0c04fea2: /* original 2f52, guest PC 0x0c04fea2 */
if(!s->budget--) { s->failed_pc=0x0c04fea2u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c04fea4;
P_0c04fea4: /* original 930e, guest PC 0x0c04fea4 */
if(!s->budget--) { s->failed_pc=0x0c04fea4u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04fec4u,2);
goto P_0c04fea6;
P_0c04fea6: /* original d208, guest PC 0x0c04fea6 */
if(!s->budget--) { s->failed_pc=0x0c04fea6u; return 0; }
r[2]=read(ram,0x0c04fec8u,4);
goto P_0c04fea8;
P_0c04fea8: /* original 243f, guest PC 0x0c04fea8 */
if(!s->budget--) { s->failed_pc=0x0c04fea8u; return 0; }
r[19]=(uint32_t)((int32_t)(int16_t)r[4]*(int32_t)(int16_t)r[3]);
goto P_0c04feaa;
P_0c04feaa: /* original 041a, guest PC 0x0c04feaa */
if(!s->budget--) { s->failed_pc=0x0c04feaau; return 0; }
r[4]=r[19];
goto P_0c04feac;
P_0c04feac: /* original 644f, guest PC 0x0c04feac */
if(!s->budget--) { s->failed_pc=0x0c04feacu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)r[4];
goto P_0c04feae;
P_0c04feae: /* original 342c, guest PC 0x0c04feae */
if(!s->budget--) { s->failed_pc=0x0c04feaeu; return 0; }
r[4]+=r[2];
goto P_0c04feb0;
P_0c04feb0: /* original 1f41, guest PC 0x0c04feb0 */
if(!s->budget--) { s->failed_pc=0x0c04feb0u; return 0; }
write(ram,r[15]+4,r[4],4);
goto P_0c04feb2;
P_0c04feb2: /* original d106, guest PC 0x0c04feb2 */
if(!s->budget--) { s->failed_pc=0x0c04feb2u; return 0; }
r[1]=read(ram,0x0c04feccu,4);
goto P_0c04feb4;
P_0c04feb4: /* original 65f2, guest PC 0x0c04feb4 */
if(!s->budget--) { s->failed_pc=0x0c04feb4u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c04feb6;
P_0c04feb6: /* original 7f08, guest PC 0x0c04feb6 */
if(!s->budget--) { s->failed_pc=0x0c04feb6u; return 0; }
r[15]+=0x00000008u;
goto P_0c04feb8;
P_0c04feb8: /* original 6012, guest PC 0x0c04feb8 */
if(!s->budget--) { s->failed_pc=0x0c04feb8u; return 0; }
tmp=read(ram,r[1],4);
r[0]=tmp;
goto P_0c04feba;
P_0c04feba: /* original 5449, guest PC 0x0c04feba */
if(!s->budget--) { s->failed_pc=0x0c04febau; return 0; }
r[4]=read(ram,r[4]+36,4);
goto P_0c04febc;
P_0c04febc: /* original 4500, guest PC 0x0c04febc */
if(!s->budget--) { s->failed_pc=0x0c04febcu; return 0; }
r[17]=(r[17]&~1u)|((r[5]>>31)!=0);
r[5]<<=1;
goto P_0c04febe;
P_0c04febe: /* original 5003, guest PC 0x0c04febe */
if(!s->budget--) { s->failed_pc=0x0c04febeu; return 0; }
r[0]=read(ram,r[0]+12,4);
goto P_0c04fec0;
P_0c04fec0: /* original 402b, guest PC 0x0c04fec0 */
if(!s->budget--) { s->failed_pc=0x0c04fec0u; return 0; }
target=r[0];
r[19]=read(ram,r[15],4); r[15]+=4;
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
P_0c04fec2: /* original 4f16, guest PC 0x0c04fec2 */
if(!s->budget--) { s->failed_pc=0x0c04fec2u; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
if(!vf3_matrix_family(0x0c04fec4u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c04fec4u; return 0; } return 1;
P_0c04fed8: /* original 2fe6, guest PC 0x0c04fed8 */
if(!s->budget--) { s->failed_pc=0x0c04fed8u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04feda;
P_0c04feda: /* original 6243, guest PC 0x0c04feda */
if(!s->budget--) { s->failed_pc=0x0c04fedau; return 0; }
r[2]=r[4];
goto P_0c04fedc;
P_0c04fedc: /* original 2fd6, guest PC 0x0c04fedc */
if(!s->budget--) { s->failed_pc=0x0c04fedcu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04fede;
P_0c04fede: /* original 6d43, guest PC 0x0c04fede */
if(!s->budget--) { s->failed_pc=0x0c04fedeu; return 0; }
r[13]=r[4];
goto P_0c04fee0;
P_0c04fee0: /* original 2fc6, guest PC 0x0c04fee0 */
if(!s->budget--) { s->failed_pc=0x0c04fee0u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04fee2;
P_0c04fee2: /* original 4208, guest PC 0x0c04fee2 */
if(!s->budget--) { s->failed_pc=0x0c04fee2u; return 0; }
r[2]<<=2;
goto P_0c04fee4;
P_0c04fee4: /* original 4f22, guest PC 0x0c04fee4 */
if(!s->budget--) { s->failed_pc=0x0c04fee4u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c04fee6;
P_0c04fee6: /* original 9e78, guest PC 0x0c04fee6 */
if(!s->budget--) { s->failed_pc=0x0c04fee6u; return 0; }
r[14]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04ffdau,2);
goto P_0c04fee8;
P_0c04fee8: /* original d33d, guest PC 0x0c04fee8 */
if(!s->budget--) { s->failed_pc=0x0c04fee8u; return 0; }
r[3]=read(ram,0x0c04ffe0u,4);
goto P_0c04feea;
P_0c04feea: /* original 4f12, guest PC 0x0c04feea */
if(!s->budget--) { s->failed_pc=0x0c04feeau; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c04feec;
P_0c04feec: /* original 2def, guest PC 0x0c04feec */
if(!s->budget--) { s->failed_pc=0x0c04feecu; return 0; }
r[19]=(uint32_t)((int32_t)(int16_t)r[13]*(int32_t)(int16_t)r[14]);
goto P_0c04feee;
P_0c04feee: /* original 7ffc, guest PC 0x0c04feee */
if(!s->budget--) { s->failed_pc=0x0c04feeeu; return 0; }
r[15]+=0xfffffffcu;
goto P_0c04fef0;
P_0c04fef0: /* original 2f22, guest PC 0x0c04fef0 */
if(!s->budget--) { s->failed_pc=0x0c04fef0u; return 0; }
write(ram,r[15],r[2],4);
goto P_0c04fef2;
P_0c04fef2: /* original 0e1a, guest PC 0x0c04fef2 */
if(!s->budget--) { s->failed_pc=0x0c04fef2u; return 0; }
r[14]=r[19];
goto P_0c04fef4;
P_0c04fef4: /* original d03b, guest PC 0x0c04fef4 */
if(!s->budget--) { s->failed_pc=0x0c04fef4u; return 0; }
r[0]=read(ram,0x0c04ffe4u,4);
goto P_0c04fef6;
P_0c04fef6: /* original 6eef, guest PC 0x0c04fef6 */
if(!s->budget--) { s->failed_pc=0x0c04fef6u; return 0; }
r[14]=(uint32_t)(int32_t)(int16_t)r[14];
goto P_0c04fef8;
P_0c04fef8: /* original 3e3c, guest PC 0x0c04fef8 */
if(!s->budget--) { s->failed_pc=0x0c04fef8u; return 0; }
r[14]+=r[3];
goto P_0c04fefa;
P_0c04fefa: /* original e300, guest PC 0x0c04fefa */
if(!s->budget--) { s->failed_pc=0x0c04fefau; return 0; }
r[3]=0x00000000u;
goto P_0c04fefc;
P_0c04fefc: /* original 0236, guest PC 0x0c04fefc */
if(!s->budget--) { s->failed_pc=0x0c04fefcu; return 0; }
write(ram,r[2]+r[0],r[3],4);
goto P_0c04fefe;
P_0c04fefe: /* original 84ea, guest PC 0x0c04fefe */
if(!s->budget--) { s->failed_pc=0x0c04fefeu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+10,1);
goto P_0c04ff00;
P_0c04ff00: /* original 2008, guest PC 0x0c04ff00 */
if(!s->budget--) { s->failed_pc=0x0c04ff00u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c04ff02;
P_0c04ff02: /* original 8f05, guest PC 0x0c04ff02 */
if(!s->budget--) { s->failed_pc=0x0c04ff02u; return 0; }
cond=r[17]&1u;
r[12]=0x00000001u;
if(!cond) { goto P_0c04ff10; }
goto P_0c04ff06;
P_0c04ff04: /* original ec01, guest PC 0x0c04ff04 */
if(!s->budget--) { s->failed_pc=0x0c04ff04u; return 0; }
r[12]=0x00000001u;
goto P_0c04ff06;
P_0c04ff06: /* original bdd3, guest PC 0x0c04ff06 */
if(!s->budget--) { s->failed_pc=0x0c04ff06u; return 0; }
target=code_base|0x0c04fab0u; r[16]=code_base|0x0c04ff0au;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04ff0au) { target=s->pc; goto dispatch; }
goto P_0c04ff0a;
P_0c04ff08: /* original 64d3, guest PC 0x0c04ff08 */
if(!s->budget--) { s->failed_pc=0x0c04ff08u; return 0; }
r[4]=r[13];
goto P_0c04ff0a;
P_0c04ff0a: /* original 4011, guest PC 0x0c04ff0a */
if(!s->budget--) { s->failed_pc=0x0c04ff0au; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[0]>=0)!=0);
goto P_0c04ff0c;
P_0c04ff0c: /* original 8f1b, guest PC 0x0c04ff0c */
if(!s->budget--) { s->failed_pc=0x0c04ff0cu; return 0; }
cond=r[17]&1u;
r[4]=r[0];
if(!cond) { goto P_0c04ff46; }
goto P_0c04ff10;
P_0c04ff0e: /* original 6403, guest PC 0x0c04ff0e */
if(!s->budget--) { s->failed_pc=0x0c04ff0eu; return 0; }
r[4]=r[0];
goto P_0c04ff10;
P_0c04ff10: /* original b89e, guest PC 0x0c04ff10 */
if(!s->budget--) { s->failed_pc=0x0c04ff10u; return 0; }
target=code_base|0x0c04f050u; r[16]=code_base|0x0c04ff14u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04ff14u) { target=s->pc; goto dispatch; }
goto P_0c04ff14;
P_0c04ff12: /* original 64d3, guest PC 0x0c04ff12 */
if(!s->budget--) { s->failed_pc=0x0c04ff12u; return 0; }
r[4]=r[13];
goto P_0c04ff14;
P_0c04ff14: /* original 4011, guest PC 0x0c04ff14 */
if(!s->budget--) { s->failed_pc=0x0c04ff14u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[0]>=0)!=0);
goto P_0c04ff16;
P_0c04ff16: /* original 8b1c, guest PC 0x0c04ff16 */
if(!s->budget--) { s->failed_pc=0x0c04ff16u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04ff52; }
goto P_0c04ff18;
P_0c04ff18: /* original 84eb, guest PC 0x0c04ff18 */
if(!s->budget--) { s->failed_pc=0x0c04ff18u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+11,1);
goto P_0c04ff1a;
P_0c04ff1a: /* original 2008, guest PC 0x0c04ff1a */
if(!s->budget--) { s->failed_pc=0x0c04ff1au; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c04ff1c;
P_0c04ff1c: /* original 8b04, guest PC 0x0c04ff1c */
if(!s->budget--) { s->failed_pc=0x0c04ff1cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04ff28; }
goto P_0c04ff1e;
P_0c04ff1e: /* original be07, guest PC 0x0c04ff1e */
if(!s->budget--) { s->failed_pc=0x0c04ff1eu; return 0; }
target=code_base|0x0c04fb30u; r[16]=code_base|0x0c04ff22u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04ff22u) { target=s->pc; goto dispatch; }
goto P_0c04ff22;
P_0c04ff20: /* original 64d3, guest PC 0x0c04ff20 */
if(!s->budget--) { s->failed_pc=0x0c04ff20u; return 0; }
r[4]=r[13];
goto P_0c04ff22;
P_0c04ff22: /* original 4011, guest PC 0x0c04ff22 */
if(!s->budget--) { s->failed_pc=0x0c04ff22u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[0]>=0)!=0);
goto P_0c04ff24;
P_0c04ff24: /* original 8f08, guest PC 0x0c04ff24 */
if(!s->budget--) { s->failed_pc=0x0c04ff24u; return 0; }
cond=r[17]&1u;
r[4]=r[0];
if(!cond) { goto P_0c04ff38; }
goto P_0c04ff28;
P_0c04ff26: /* original 6403, guest PC 0x0c04ff26 */
if(!s->budget--) { s->failed_pc=0x0c04ff26u; return 0; }
r[4]=r[0];
goto P_0c04ff28;
P_0c04ff28: /* original 84ec, guest PC 0x0c04ff28 */
if(!s->budget--) { s->failed_pc=0x0c04ff28u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+12,1);
goto P_0c04ff2a;
P_0c04ff2a: /* original 2008, guest PC 0x0c04ff2a */
if(!s->budget--) { s->failed_pc=0x0c04ff2au; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c04ff2c;
P_0c04ff2c: /* original 8b0d, guest PC 0x0c04ff2c */
if(!s->budget--) { s->failed_pc=0x0c04ff2cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04ff4a; }
goto P_0c04ff2e;
P_0c04ff2e: /* original bb2b, guest PC 0x0c04ff2e */
if(!s->budget--) { s->failed_pc=0x0c04ff2eu; return 0; }
target=code_base|0x0c04f588u; r[16]=code_base|0x0c04ff32u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04ff32u) { target=s->pc; goto dispatch; }
goto P_0c04ff32;
P_0c04ff30: /* original 64d3, guest PC 0x0c04ff30 */
if(!s->budget--) { s->failed_pc=0x0c04ff30u; return 0; }
r[4]=r[13];
goto P_0c04ff32;
P_0c04ff32: /* original 4011, guest PC 0x0c04ff32 */
if(!s->budget--) { s->failed_pc=0x0c04ff32u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[0]>=0)!=0);
goto P_0c04ff34;
P_0c04ff34: /* original 8d09, guest PC 0x0c04ff34 */
if(!s->budget--) { s->failed_pc=0x0c04ff34u; return 0; }
cond=r[17]&1u;
r[4]=r[0];
if(cond) { goto P_0c04ff4a; }
goto P_0c04ff38;
P_0c04ff36: /* original 6403, guest PC 0x0c04ff36 */
if(!s->budget--) { s->failed_pc=0x0c04ff36u; return 0; }
r[4]=r[0];
goto P_0c04ff38;
P_0c04ff38: /* original d32b, guest PC 0x0c04ff38 */
if(!s->budget--) { s->failed_pc=0x0c04ff38u; return 0; }
r[3]=read(ram,0x0c04ffe8u,4);
goto P_0c04ff3a;
P_0c04ff3a: /* original 3430, guest PC 0x0c04ff3a */
if(!s->budget--) { s->failed_pc=0x0c04ff3au; return 0; }
r[17]=(r[17]&~1u)|((r[4]==r[3])!=0);
goto P_0c04ff3c;
P_0c04ff3c: /* original 8b03, guest PC 0x0c04ff3c */
if(!s->budget--) { s->failed_pc=0x0c04ff3cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04ff46; }
goto P_0c04ff3e;
P_0c04ff3e: /* original d029, guest PC 0x0c04ff3e */
if(!s->budget--) { s->failed_pc=0x0c04ff3eu; return 0; }
r[0]=read(ram,0x0c04ffe4u,4);
goto P_0c04ff40;
P_0c04ff40: /* original 61f2, guest PC 0x0c04ff40 */
if(!s->budget--) { s->failed_pc=0x0c04ff40u; return 0; }
tmp=read(ram,r[15],4);
r[1]=tmp;
goto P_0c04ff42;
P_0c04ff42: /* original a006, guest PC 0x0c04ff42 */
if(!s->budget--) { s->failed_pc=0x0c04ff42u; return 0; }
write(ram,r[1]+r[0],r[12],4);
goto P_0c04ff52;
P_0c04ff44: /* original 01c6, guest PC 0x0c04ff44 */
if(!s->budget--) { s->failed_pc=0x0c04ff44u; return 0; }
write(ram,r[1]+r[0],r[12],4);
goto P_0c04ff46;
P_0c04ff46: /* original a005, guest PC 0x0c04ff46 */
if(!s->budget--) { s->failed_pc=0x0c04ff46u; return 0; }
r[0]=r[4];
goto P_0c04ff54;
P_0c04ff48: /* original 6043, guest PC 0x0c04ff48 */
if(!s->budget--) { s->failed_pc=0x0c04ff48u; return 0; }
r[0]=r[4];
goto P_0c04ff4a;
P_0c04ff4a: /* original 60c3, guest PC 0x0c04ff4a */
if(!s->budget--) { s->failed_pc=0x0c04ff4au; return 0; }
r[0]=r[12];
goto P_0c04ff4c;
P_0c04ff4c: /* original 80ea, guest PC 0x0c04ff4c */
if(!s->budget--) { s->failed_pc=0x0c04ff4cu; return 0; }
write(ram,r[14]+10,r[0],1);
goto P_0c04ff4e;
P_0c04ff4e: /* original 80eb, guest PC 0x0c04ff4e */
if(!s->budget--) { s->failed_pc=0x0c04ff4eu; return 0; }
write(ram,r[14]+11,r[0],1);
goto P_0c04ff50;
P_0c04ff50: /* original 80ec, guest PC 0x0c04ff50 */
if(!s->budget--) { s->failed_pc=0x0c04ff50u; return 0; }
write(ram,r[14]+12,r[0],1);
goto P_0c04ff52;
P_0c04ff52: /* original e000, guest PC 0x0c04ff52 */
if(!s->budget--) { s->failed_pc=0x0c04ff52u; return 0; }
r[0]=0x00000000u;
goto P_0c04ff54;
P_0c04ff54: /* original 7f04, guest PC 0x0c04ff54 */
if(!s->budget--) { s->failed_pc=0x0c04ff54u; return 0; }
r[15]+=0x00000004u;
goto P_0c04ff56;
P_0c04ff56: /* original 4f16, guest PC 0x0c04ff56 */
if(!s->budget--) { s->failed_pc=0x0c04ff56u; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c04ff58;
P_0c04ff58: /* original 4f26, guest PC 0x0c04ff58 */
if(!s->budget--) { s->failed_pc=0x0c04ff58u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c04ff5a;
P_0c04ff5a: /* original 6cf6, guest PC 0x0c04ff5a */
if(!s->budget--) { s->failed_pc=0x0c04ff5au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c04ff5c;
P_0c04ff5c: /* original 6df6, guest PC 0x0c04ff5c */
if(!s->budget--) { s->failed_pc=0x0c04ff5cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c04ff5e;
P_0c04ff5e: /* original 000b, guest PC 0x0c04ff5e */
if(!s->budget--) { s->failed_pc=0x0c04ff5eu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c04ff60: /* original 6ef6, guest PC 0x0c04ff60 */
if(!s->budget--) { s->failed_pc=0x0c04ff60u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c04ff62;
P_0c04ff62: /* original 933a, guest PC 0x0c04ff62 */
if(!s->budget--) { s->failed_pc=0x0c04ff62u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04ffdau,2);
goto P_0c04ff64;
P_0c04ff64: /* original 6053, guest PC 0x0c04ff64 */
if(!s->budget--) { s->failed_pc=0x0c04ff64u; return 0; }
r[0]=r[5];
goto P_0c04ff66;
P_0c04ff66: /* original 4f12, guest PC 0x0c04ff66 */
if(!s->budget--) { s->failed_pc=0x0c04ff66u; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c04ff68;
P_0c04ff68: /* original 243f, guest PC 0x0c04ff68 */
if(!s->budget--) { s->failed_pc=0x0c04ff68u; return 0; }
r[19]=(uint32_t)((int32_t)(int16_t)r[4]*(int32_t)(int16_t)r[3]);
goto P_0c04ff6a;
P_0c04ff6a: /* original d21d, guest PC 0x0c04ff6a */
if(!s->budget--) { s->failed_pc=0x0c04ff6au; return 0; }
r[2]=read(ram,0x0c04ffe0u,4);
goto P_0c04ff6c;
P_0c04ff6c: /* original 4008, guest PC 0x0c04ff6c */
if(!s->budget--) { s->failed_pc=0x0c04ff6cu; return 0; }
r[0]<<=2;
goto P_0c04ff6e;
P_0c04ff6e: /* original 4008, guest PC 0x0c04ff6e */
if(!s->budget--) { s->failed_pc=0x0c04ff6eu; return 0; }
r[0]<<=2;
goto P_0c04ff70;
P_0c04ff70: /* original 4000, guest PC 0x0c04ff70 */
if(!s->budget--) { s->failed_pc=0x0c04ff70u; return 0; }
r[17]=(r[17]&~1u)|((r[0]>>31)!=0);
r[0]<<=1;
goto P_0c04ff72;
P_0c04ff72: /* original 041a, guest PC 0x0c04ff72 */
if(!s->budget--) { s->failed_pc=0x0c04ff72u; return 0; }
r[4]=r[19];
goto P_0c04ff74;
P_0c04ff74: /* original 644f, guest PC 0x0c04ff74 */
if(!s->budget--) { s->failed_pc=0x0c04ff74u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)r[4];
goto P_0c04ff76;
P_0c04ff76: /* original 342c, guest PC 0x0c04ff76 */
if(!s->budget--) { s->failed_pc=0x0c04ff76u; return 0; }
r[4]+=r[2];
goto P_0c04ff78;
P_0c04ff78: /* original 514a, guest PC 0x0c04ff78 */
if(!s->budget--) { s->failed_pc=0x0c04ff78u; return 0; }
r[1]=read(ram,r[4]+40,4);
goto P_0c04ff7a;
P_0c04ff7a: /* original 301c, guest PC 0x0c04ff7a */
if(!s->budget--) { s->failed_pc=0x0c04ff7au; return 0; }
r[0]+=r[1];
goto P_0c04ff7c;
P_0c04ff7c: /* original 000b, guest PC 0x0c04ff7c */
if(!s->budget--) { s->failed_pc=0x0c04ff7cu; return 0; }
target=r[16];
r[19]=read(ram,r[15],4); r[15]+=4;
s->pc=target; return ram->oob==0;
P_0c04ff7e: /* original 4f16, guest PC 0x0c04ff7e */
if(!s->budget--) { s->failed_pc=0x0c04ff7eu; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c04ff80;
P_0c04ff80: /* original 932b, guest PC 0x0c04ff80 */
if(!s->budget--) { s->failed_pc=0x0c04ff80u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04ffdau,2);
goto P_0c04ff82;
P_0c04ff82: /* original e1fc, guest PC 0x0c04ff82 */
if(!s->budget--) { s->failed_pc=0x0c04ff82u; return 0; }
r[1]=0xfffffffcu;
goto P_0c04ff84;
P_0c04ff84: /* original 4f12, guest PC 0x0c04ff84 */
if(!s->budget--) { s->failed_pc=0x0c04ff84u; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c04ff86;
P_0c04ff86: /* original 243f, guest PC 0x0c04ff86 */
if(!s->budget--) { s->failed_pc=0x0c04ff86u; return 0; }
r[19]=(uint32_t)((int32_t)(int16_t)r[4]*(int32_t)(int16_t)r[3]);
goto P_0c04ff88;
P_0c04ff88: /* original d215, guest PC 0x0c04ff88 */
if(!s->budget--) { s->failed_pc=0x0c04ff88u; return 0; }
r[2]=read(ram,0x0c04ffe0u,4);
goto P_0c04ff8a;
P_0c04ff8a: /* original 451c, guest PC 0x0c04ff8a */
if(!s->budget--) { s->failed_pc=0x0c04ff8au; return 0; }
r[5]=(r[1]&0x80000000u)?((r[1]&31u)?(uint32_t)((int32_t)r[5]>>((-r[1])&31u)):((int32_t)r[5]<0?0xffffffffu:0)):r[5]<<(r[1]&31u);
goto P_0c04ff8c;
P_0c04ff8c: /* original e101, guest PC 0x0c04ff8c */
if(!s->budget--) { s->failed_pc=0x0c04ff8cu; return 0; }
r[1]=0x00000001u;
goto P_0c04ff8e;
P_0c04ff8e: /* original 041a, guest PC 0x0c04ff8e */
if(!s->budget--) { s->failed_pc=0x0c04ff8eu; return 0; }
r[4]=r[19];
goto P_0c04ff90;
P_0c04ff90: /* original 644f, guest PC 0x0c04ff90 */
if(!s->budget--) { s->failed_pc=0x0c04ff90u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)r[4];
goto P_0c04ff92;
P_0c04ff92: /* original 342c, guest PC 0x0c04ff92 */
if(!s->budget--) { s->failed_pc=0x0c04ff92u; return 0; }
r[4]+=r[2];
goto P_0c04ff94;
P_0c04ff94: /* original 6043, guest PC 0x0c04ff94 */
if(!s->budget--) { s->failed_pc=0x0c04ff94u; return 0; }
r[0]=r[4];
goto P_0c04ff96;
P_0c04ff96: /* original 7048, guest PC 0x0c04ff96 */
if(!s->budget--) { s->failed_pc=0x0c04ff96u; return 0; }
r[0]+=0x00000048u;
goto P_0c04ff98;
P_0c04ff98: /* original 350c, guest PC 0x0c04ff98 */
if(!s->budget--) { s->failed_pc=0x0c04ff98u; return 0; }
r[5]+=r[0];
goto P_0c04ff9a;
P_0c04ff9a: /* original 2510, guest PC 0x0c04ff9a */
if(!s->budget--) { s->failed_pc=0x0c04ff9au; return 0; }
write(ram,r[5],r[1],1);
goto P_0c04ff9c;
P_0c04ff9c: /* original 000b, guest PC 0x0c04ff9c */
if(!s->budget--) { s->failed_pc=0x0c04ff9cu; return 0; }
target=r[16];
r[19]=read(ram,r[15],4); r[15]+=4;
s->pc=target; return ram->oob==0;
P_0c04ff9e: /* original 4f16, guest PC 0x0c04ff9e */
if(!s->budget--) { s->failed_pc=0x0c04ff9eu; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
if(!vf3_matrix_family(0x0c04ffa0u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c04ffa0u; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
