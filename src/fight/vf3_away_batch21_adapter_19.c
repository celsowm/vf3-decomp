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
int vf3_away_batch21_adapter_19(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c0abc98u: goto P_0c0abc98;
case 0x0c0abc9au: goto P_0c0abc9a;
case 0x0c0abc9cu: goto P_0c0abc9c;
case 0x0c0abc9eu: goto P_0c0abc9e;
case 0x0c0abca0u: goto P_0c0abca0;
case 0x0c0abca2u: goto P_0c0abca2;
case 0x0c0abca4u: goto P_0c0abca4;
case 0x0c0abca6u: goto P_0c0abca6;
case 0x0c0abca8u: goto P_0c0abca8;
case 0x0c0abcaau: goto P_0c0abcaa;
case 0x0c0abcacu: goto P_0c0abcac;
case 0x0c0abcaeu: goto P_0c0abcae;
case 0x0c0abcb0u: goto P_0c0abcb0;
case 0x0c0abcb2u: goto P_0c0abcb2;
case 0x0c0abcb4u: goto P_0c0abcb4;
case 0x0c0abcb6u: goto P_0c0abcb6;
case 0x0c0abcb8u: goto P_0c0abcb8;
case 0x0c0abcbau: goto P_0c0abcba;
case 0x0c0abcbcu: goto P_0c0abcbc;
case 0x0c0abcbeu: goto P_0c0abcbe;
case 0x0c0abcc0u: goto P_0c0abcc0;
case 0x0c0abcc2u: goto P_0c0abcc2;
case 0x0c0abcc4u: goto P_0c0abcc4;
case 0x0c0abcc6u: goto P_0c0abcc6;
case 0x0c0abcc8u: goto P_0c0abcc8;
case 0x0c0abccau: goto P_0c0abcca;
case 0x0c0abcccu: goto P_0c0abccc;
case 0x0c0abcceu: goto P_0c0abcce;
case 0x0c0abcd0u: goto P_0c0abcd0;
case 0x0c0abcd2u: goto P_0c0abcd2;
case 0x0c0abcd4u: goto P_0c0abcd4;
case 0x0c0abcd6u: goto P_0c0abcd6;
case 0x0c0abcd8u: goto P_0c0abcd8;
case 0x0c0abcdau: goto P_0c0abcda;
case 0x0c0abcecu: goto P_0c0abcec;
case 0x0c0abceeu: goto P_0c0abcee;
case 0x0c0abcf0u: goto P_0c0abcf0;
case 0x0c0abcf2u: goto P_0c0abcf2;
case 0x0c0abcf4u: goto P_0c0abcf4;
case 0x0c0abcf6u: goto P_0c0abcf6;
case 0x0c0abcf8u: goto P_0c0abcf8;
case 0x0c0abcfau: goto P_0c0abcfa;
case 0x0c0abcfcu: goto P_0c0abcfc;
case 0x0c0abcfeu: goto P_0c0abcfe;
case 0x0c0abd00u: goto P_0c0abd00;
case 0x0c0abd02u: goto P_0c0abd02;
case 0x0c0abd04u: goto P_0c0abd04;
case 0x0c0abd06u: goto P_0c0abd06;
case 0x0c0abd08u: goto P_0c0abd08;
case 0x0c0abd2cu: goto P_0c0abd2c;
case 0x0c0abd2eu: goto P_0c0abd2e;
case 0x0c0abd30u: goto P_0c0abd30;
case 0x0c0abd32u: goto P_0c0abd32;
case 0x0c0abd34u: goto P_0c0abd34;
case 0x0c0abd36u: goto P_0c0abd36;
case 0x0c0abd38u: goto P_0c0abd38;
case 0x0c0abd3au: goto P_0c0abd3a;
case 0x0c0abd3cu: goto P_0c0abd3c;
case 0x0c0abd3eu: goto P_0c0abd3e;
case 0x0c0abd40u: goto P_0c0abd40;
case 0x0c0abd42u: goto P_0c0abd42;
case 0x0c0abd44u: goto P_0c0abd44;
case 0x0c0abd46u: goto P_0c0abd46;
case 0x0c0abd48u: goto P_0c0abd48;
case 0x0c0abd4au: goto P_0c0abd4a;
case 0x0c0abd4cu: goto P_0c0abd4c;
case 0x0c0abd4eu: goto P_0c0abd4e;
case 0x0c0abd50u: goto P_0c0abd50;
case 0x0c0abd52u: goto P_0c0abd52;
case 0x0c0abd54u: goto P_0c0abd54;
case 0x0c0abd56u: goto P_0c0abd56;
case 0x0c0abd58u: goto P_0c0abd58;
case 0x0c0abd5au: goto P_0c0abd5a;
case 0x0c0abd5cu: goto P_0c0abd5c;
case 0x0c0abd5eu: goto P_0c0abd5e;
case 0x0c0abd60u: goto P_0c0abd60;
case 0x0c0abd62u: goto P_0c0abd62;
case 0x0c0abd64u: goto P_0c0abd64;
case 0x0c0abd66u: goto P_0c0abd66;
case 0x0c0abd68u: goto P_0c0abd68;
case 0x0c0abd6au: goto P_0c0abd6a;
case 0x0c0abd6cu: goto P_0c0abd6c;
case 0x0c0abd6eu: goto P_0c0abd6e;
case 0x0c0abd70u: goto P_0c0abd70;
case 0x0c0abd72u: goto P_0c0abd72;
case 0x0c0abd74u: goto P_0c0abd74;
case 0x0c0abd76u: goto P_0c0abd76;
case 0x0c0abd78u: goto P_0c0abd78;
case 0x0c0abd7au: goto P_0c0abd7a;
case 0x0c0abd7cu: goto P_0c0abd7c;
case 0x0c0abd7eu: goto P_0c0abd7e;
case 0x0c0abd80u: goto P_0c0abd80;
case 0x0c0abd82u: goto P_0c0abd82;
case 0x0c0abd84u: goto P_0c0abd84;
case 0x0c0abd86u: goto P_0c0abd86;
case 0x0c0abd88u: goto P_0c0abd88;
case 0x0c0abd8au: goto P_0c0abd8a;
case 0x0c0abd8cu: goto P_0c0abd8c;
case 0x0c0abd8eu: goto P_0c0abd8e;
case 0x0c0abd90u: goto P_0c0abd90;
case 0x0c0abd92u: goto P_0c0abd92;
case 0x0c0abd94u: goto P_0c0abd94;
case 0x0c0abd96u: goto P_0c0abd96;
case 0x0c0abd98u: goto P_0c0abd98;
case 0x0c0abd9au: goto P_0c0abd9a;
case 0x0c0abd9cu: goto P_0c0abd9c;
case 0x0c0abd9eu: goto P_0c0abd9e;
case 0x0c0abda0u: goto P_0c0abda0;
case 0x0c0abda2u: goto P_0c0abda2;
case 0x0c0abda4u: goto P_0c0abda4;
case 0x0c0abda6u: goto P_0c0abda6;
case 0x0c0abda8u: goto P_0c0abda8;
case 0x0c0abdaau: goto P_0c0abdaa;
case 0x0c0abdacu: goto P_0c0abdac;
case 0x0c0abdaeu: goto P_0c0abdae;
case 0x0c0abdb0u: goto P_0c0abdb0;
case 0x0c0abdb2u: goto P_0c0abdb2;
case 0x0c0abdb4u: goto P_0c0abdb4;
case 0x0c0abdb6u: goto P_0c0abdb6;
case 0x0c0abdb8u: goto P_0c0abdb8;
case 0x0c0abdbau: goto P_0c0abdba;
case 0x0c0abdbcu: goto P_0c0abdbc;
case 0x0c0abdbeu: goto P_0c0abdbe;
case 0x0c0abdc0u: goto P_0c0abdc0;
case 0x0c0abdc2u: goto P_0c0abdc2;
case 0x0c0abdc4u: goto P_0c0abdc4;
case 0x0c0abdc6u: goto P_0c0abdc6;
case 0x0c0abdc8u: goto P_0c0abdc8;
case 0x0c0abdcau: goto P_0c0abdca;
case 0x0c0abdccu: goto P_0c0abdcc;
case 0x0c0abdceu: goto P_0c0abdce;
case 0x0c0abdd0u: goto P_0c0abdd0;
case 0x0c0abdd2u: goto P_0c0abdd2;
case 0x0c0abdd4u: goto P_0c0abdd4;
case 0x0c0abdd6u: goto P_0c0abdd6;
case 0x0c0abdd8u: goto P_0c0abdd8;
case 0x0c0abddau: goto P_0c0abdda;
case 0x0c0abddcu: goto P_0c0abddc;
case 0x0c0abddeu: goto P_0c0abdde;
case 0x0c0abde0u: goto P_0c0abde0;
case 0x0c0abde2u: goto P_0c0abde2;
case 0x0c0abde4u: goto P_0c0abde4;
case 0x0c0abde6u: goto P_0c0abde6;
case 0x0c0abde8u: goto P_0c0abde8;
case 0x0c0abdeau: goto P_0c0abdea;
case 0x0c0abdecu: goto P_0c0abdec;
case 0x0c0abdeeu: goto P_0c0abdee;
case 0x0c0abdf0u: goto P_0c0abdf0;
case 0x0c0abdf2u: goto P_0c0abdf2;
case 0x0c0abdf4u: goto P_0c0abdf4;
case 0x0c0abdf6u: goto P_0c0abdf6;
case 0x0c0abdf8u: goto P_0c0abdf8;
case 0x0c0abdfau: goto P_0c0abdfa;
case 0x0c0abe20u: goto P_0c0abe20;
case 0x0c0abe22u: goto P_0c0abe22;
case 0x0c0abe24u: goto P_0c0abe24;
case 0x0c0abe26u: goto P_0c0abe26;
case 0x0c0abe28u: goto P_0c0abe28;
case 0x0c0abe2au: goto P_0c0abe2a;
case 0x0c0abe2cu: goto P_0c0abe2c;
case 0x0c0abe2eu: goto P_0c0abe2e;
case 0x0c0abe30u: goto P_0c0abe30;
case 0x0c0abe32u: goto P_0c0abe32;
case 0x0c0abe34u: goto P_0c0abe34;
case 0x0c0abe36u: goto P_0c0abe36;
case 0x0c0abe38u: goto P_0c0abe38;
case 0x0c0abe3au: goto P_0c0abe3a;
case 0x0c0abe3cu: goto P_0c0abe3c;
case 0x0c0abe3eu: goto P_0c0abe3e;
case 0x0c0abe40u: goto P_0c0abe40;
case 0x0c0abe42u: goto P_0c0abe42;
case 0x0c0abe44u: goto P_0c0abe44;
case 0x0c0abe46u: goto P_0c0abe46;
case 0x0c0abe48u: goto P_0c0abe48;
case 0x0c0abe4au: goto P_0c0abe4a;
case 0x0c0abe4cu: goto P_0c0abe4c;
case 0x0c0abe4eu: goto P_0c0abe4e;
case 0x0c0abe50u: goto P_0c0abe50;
case 0x0c0abe52u: goto P_0c0abe52;
case 0x0c0abe54u: goto P_0c0abe54;
case 0x0c0abe56u: goto P_0c0abe56;
case 0x0c0abe58u: goto P_0c0abe58;
case 0x0c0abe5au: goto P_0c0abe5a;
case 0x0c0abe5cu: goto P_0c0abe5c;
case 0x0c0abe5eu: goto P_0c0abe5e;
case 0x0c0abe60u: goto P_0c0abe60;
case 0x0c0abe62u: goto P_0c0abe62;
case 0x0c0abe64u: goto P_0c0abe64;
case 0x0c0abe66u: goto P_0c0abe66;
case 0x0c0abe68u: goto P_0c0abe68;
case 0x0c0abe6au: goto P_0c0abe6a;
case 0x0c0abe6cu: goto P_0c0abe6c;
case 0x0c0abe6eu: goto P_0c0abe6e;
case 0x0c0abe70u: goto P_0c0abe70;
case 0x0c0abe72u: goto P_0c0abe72;
case 0x0c0abe74u: goto P_0c0abe74;
case 0x0c0abe76u: goto P_0c0abe76;
case 0x0c0abe78u: goto P_0c0abe78;
case 0x0c0abe7au: goto P_0c0abe7a;
case 0x0c0abe7cu: goto P_0c0abe7c;
case 0x0c0abe7eu: goto P_0c0abe7e;
case 0x0c0abe80u: goto P_0c0abe80;
case 0x0c0abe82u: goto P_0c0abe82;
default: return vf3_matrix_family(target,s,ram);
}
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
goto P_0c0abca2;
P_0c0abca2: /* original e307, guest PC 0x0c0abca2 */
if(!s->budget--) { s->failed_pc=0x0c0abca2u; return 0; }
r[3]=0x00000007u;
goto P_0c0abca4;
P_0c0abca4: /* original e062, guest PC 0x0c0abca4 */
if(!s->budget--) { s->failed_pc=0x0c0abca4u; return 0; }
r[0]=0x00000062u;
goto P_0c0abca6;
P_0c0abca6: /* original 6233, guest PC 0x0c0abca6 */
if(!s->budget--) { s->failed_pc=0x0c0abca6u; return 0; }
r[2]=r[3];
goto P_0c0abca8;
P_0c0abca8: /* original 1532, guest PC 0x0c0abca8 */
if(!s->budget--) { s->failed_pc=0x0c0abca8u; return 0; }
write(ram,r[5]+8,r[3],4);
goto P_0c0abcaa;
P_0c0abcaa: /* original a000, guest PC 0x0c0abcaa */
if(!s->budget--) { s->failed_pc=0x0c0abcaau; return 0; }
write(ram,r[4]+r[0],r[2],1);
goto P_0c0abcae;
P_0c0abcac: /* original 0424, guest PC 0x0c0abcac */
if(!s->budget--) { s->failed_pc=0x0c0abcacu; return 0; }
write(ram,r[4]+r[0],r[2],1);
goto P_0c0abcae;
P_0c0abcae: /* original 2fe6, guest PC 0x0c0abcae */
if(!s->budget--) { s->failed_pc=0x0c0abcaeu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0abcb0;
P_0c0abcb0: /* original 6e43, guest PC 0x0c0abcb0 */
if(!s->budget--) { s->failed_pc=0x0c0abcb0u; return 0; }
r[14]=r[4];
goto P_0c0abcb2;
P_0c0abcb2: /* original e03e, guest PC 0x0c0abcb2 */
if(!s->budget--) { s->failed_pc=0x0c0abcb2u; return 0; }
r[0]=0x0000003eu;
goto P_0c0abcb4;
P_0c0abcb4: /* original 04ed, guest PC 0x0c0abcb4 */
if(!s->budget--) { s->failed_pc=0x0c0abcb4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0abcb6;
P_0c0abcb6: /* original 902a, guest PC 0x0c0abcb6 */
if(!s->budget--) { s->failed_pc=0x0c0abcb6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0abd0eu,2);
goto P_0c0abcb8;
P_0c0abcb8: /* original 4f22, guest PC 0x0c0abcb8 */
if(!s->budget--) { s->failed_pc=0x0c0abcb8u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0abcba;
P_0c0abcba: /* original 05ed, guest PC 0x0c0abcba */
if(!s->budget--) { s->failed_pc=0x0c0abcbau; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0abcbc;
P_0c0abcbc: /* original 644d, guest PC 0x0c0abcbc */
if(!s->budget--) { s->failed_pc=0x0c0abcbcu; return 0; }
r[4]=r[4]&65535u;
goto P_0c0abcbe;
P_0c0abcbe: /* original 655d, guest PC 0x0c0abcbe */
if(!s->budget--) { s->failed_pc=0x0c0abcbeu; return 0; }
r[5]=r[5]&65535u;
goto P_0c0abcc0;
P_0c0abcc0: /* original 3453, guest PC 0x0c0abcc0 */
if(!s->budget--) { s->failed_pc=0x0c0abcc0u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=(int32_t)r[5])!=0);
goto P_0c0abcc2;
P_0c0abcc2: /* original 8903, guest PC 0x0c0abcc2 */
if(!s->budget--) { s->failed_pc=0x0c0abcc2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0abccc; }
goto P_0c0abcc4;
P_0c0abcc4: /* original e03e, guest PC 0x0c0abcc4 */
if(!s->budget--) { s->failed_pc=0x0c0abcc4u; return 0; }
r[0]=0x0000003eu;
goto P_0c0abcc6;
P_0c0abcc6: /* original 7401, guest PC 0x0c0abcc6 */
if(!s->budget--) { s->failed_pc=0x0c0abcc6u; return 0; }
r[4]+=0x00000001u;
goto P_0c0abcc8;
P_0c0abcc8: /* original a002, guest PC 0x0c0abcc8 */
if(!s->budget--) { s->failed_pc=0x0c0abcc8u; return 0; }
write(ram,r[14]+r[0],r[4],2);
goto P_0c0abcd0;
P_0c0abcca: /* original 0e45, guest PC 0x0c0abcca */
if(!s->budget--) { s->failed_pc=0x0c0abccau; return 0; }
write(ram,r[14]+r[0],r[4],2);
goto P_0c0abccc;
P_0c0abccc: /* original e03e, guest PC 0x0c0abccc */
if(!s->budget--) { s->failed_pc=0x0c0abcccu; return 0; }
r[0]=0x0000003eu;
goto P_0c0abcce;
P_0c0abcce: /* original 0e55, guest PC 0x0c0abcce */
if(!s->budget--) { s->failed_pc=0x0c0abcceu; return 0; }
write(ram,r[14]+r[0],r[5],2);
goto P_0c0abcd0;
P_0c0abcd0: /* original b02c, guest PC 0x0c0abcd0 */
if(!s->budget--) { s->failed_pc=0x0c0abcd0u; return 0; }
target=code_base|0x0c0abd2cu; r[16]=code_base|0x0c0abcd4u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0abcd4u) { target=s->pc; goto dispatch; }
goto P_0c0abcd4;
P_0c0abcd2: /* original 64e3, guest PC 0x0c0abcd2 */
if(!s->budget--) { s->failed_pc=0x0c0abcd2u; return 0; }
r[4]=r[14];
goto P_0c0abcd4;
P_0c0abcd4: /* original 4f26, guest PC 0x0c0abcd4 */
if(!s->budget--) { s->failed_pc=0x0c0abcd4u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0abcd6;
P_0c0abcd6: /* original 64e3, guest PC 0x0c0abcd6 */
if(!s->budget--) { s->failed_pc=0x0c0abcd6u; return 0; }
r[4]=r[14];
goto P_0c0abcd8;
P_0c0abcd8: /* original a074, guest PC 0x0c0abcd8 */
if(!s->budget--) { s->failed_pc=0x0c0abcd8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0abdc4;
P_0c0abcda: /* original 6ef6, guest PC 0x0c0abcda */
if(!s->budget--) { s->failed_pc=0x0c0abcdau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0abcdcu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0abcdcu; return 0; } return 1;
P_0c0abcec: /* original 9014, guest PC 0x0c0abcec */
if(!s->budget--) { s->failed_pc=0x0c0abcecu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0abd18u,2);
goto P_0c0abcee;
P_0c0abcee: /* original f346, guest PC 0x0c0abcee */
if(!s->budget--) { s->failed_pc=0x0c0abceeu; return 0; }
vf3_matrix_load(s,ram,3,r[4]+r[0]);
goto P_0c0abcf0;
P_0c0abcf0: /* original 9013, guest PC 0x0c0abcf0 */
if(!s->budget--) { s->failed_pc=0x0c0abcf0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0abd1au,2);
goto P_0c0abcf2;
P_0c0abcf2: /* original f446, guest PC 0x0c0abcf2 */
if(!s->budget--) { s->failed_pc=0x0c0abcf2u; return 0; }
vf3_matrix_load(s,ram,4,r[4]+r[0]);
goto P_0c0abcf4;
P_0c0abcf4: /* original e014, guest PC 0x0c0abcf4 */
if(!s->budget--) { s->failed_pc=0x0c0abcf4u; return 0; }
r[0]=0x00000014u;
goto P_0c0abcf6;
P_0c0abcf6: /* original f430, guest PC 0x0c0abcf6 */
if(!s->budget--) { s->failed_pc=0x0c0abcf6u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'+');
goto P_0c0abcf8;
P_0c0abcf8: /* original f346, guest PC 0x0c0abcf8 */
if(!s->budget--) { s->failed_pc=0x0c0abcf8u; return 0; }
vf3_matrix_load(s,ram,3,r[4]+r[0]);
goto P_0c0abcfa;
P_0c0abcfa: /* original f345, guest PC 0x0c0abcfa */
if(!s->budget--) { s->failed_pc=0x0c0abcfau; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[4]))!=0);
goto P_0c0abcfc;
P_0c0abcfc: /* original 8903, guest PC 0x0c0abcfc */
if(!s->budget--) { s->failed_pc=0x0c0abcfcu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0abd06; }
goto P_0c0abcfe;
P_0c0abcfe: /* original f447, guest PC 0x0c0abcfe */
if(!s->budget--) { s->failed_pc=0x0c0abcfeu; return 0; }
vf3_matrix_store(s,ram,4,r[4]+r[0]);
goto P_0c0abd00;
P_0c0abd00: /* original e028, guest PC 0x0c0abd00 */
if(!s->budget--) { s->failed_pc=0x0c0abd00u; return 0; }
r[0]=0x00000028u;
goto P_0c0abd02;
P_0c0abd02: /* original f38d, guest PC 0x0c0abd02 */
if(!s->budget--) { s->failed_pc=0x0c0abd02u; return 0; }
fr[3]=0;
goto P_0c0abd04;
P_0c0abd04: /* original f437, guest PC 0x0c0abd04 */
if(!s->budget--) { s->failed_pc=0x0c0abd04u; return 0; }
vf3_matrix_store(s,ram,3,r[4]+r[0]);
goto P_0c0abd06;
P_0c0abd06: /* original 000b, guest PC 0x0c0abd06 */
if(!s->budget--) { s->failed_pc=0x0c0abd06u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c0abd08: /* original 0009, guest PC 0x0c0abd08 */
if(!s->budget--) { s->failed_pc=0x0c0abd08u; return 0; }
if(!vf3_matrix_family(0x0c0abd0au,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0abd0au; return 0; } return 1;
P_0c0abd2c: /* original c737, guest PC 0x0c0abd2c */
if(!s->budget--) { s->failed_pc=0x0c0abd2cu; return 0; }
r[0]=code_base|0x000abe0cu;
goto P_0c0abd2e;
P_0c0abd2e: /* original d636, guest PC 0x0c0abd2e */
if(!s->budget--) { s->failed_pc=0x0c0abd2eu; return 0; }
r[6]=read(ram,0x0c0abe08u,4);
goto P_0c0abd30;
P_0c0abd30: /* original f708, guest PC 0x0c0abd30 */
if(!s->budget--) { s->failed_pc=0x0c0abd30u; return 0; }
vf3_matrix_load(s,ram,7,r[0]);
goto P_0c0abd32;
P_0c0abd32: /* original e01c, guest PC 0x0c0abd32 */
if(!s->budget--) { s->failed_pc=0x0c0abd32u; return 0; }
r[0]=0x0000001cu;
goto P_0c0abd34;
P_0c0abd34: /* original 006c, guest PC 0x0c0abd34 */
if(!s->budget--) { s->failed_pc=0x0c0abd34u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[6]+r[0],1);
goto P_0c0abd36;
P_0c0abd36: /* original e71b, guest PC 0x0c0abd36 */
if(!s->budget--) { s->failed_pc=0x0c0abd36u; return 0; }
r[7]=0x0000001bu;
goto P_0c0abd38;
P_0c0abd38: /* original 9560, guest PC 0x0c0abd38 */
if(!s->budget--) { s->failed_pc=0x0c0abd38u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0abdfcu,2);
goto P_0c0abd3a;
P_0c0abd3a: /* original 600c, guest PC 0x0c0abd3a */
if(!s->budget--) { s->failed_pc=0x0c0abd3au; return 0; }
r[0]=r[0]&255u;
goto P_0c0abd3c;
P_0c0abd3c: /* original 354c, guest PC 0x0c0abd3c */
if(!s->budget--) { s->failed_pc=0x0c0abd3cu; return 0; }
r[5]+=r[4];
goto P_0c0abd3e;
P_0c0abd3e: /* original c90f, guest PC 0x0c0abd3e */
if(!s->budget--) { s->failed_pc=0x0c0abd3eu; return 0; }
r[0]&=15u;
goto P_0c0abd40;
P_0c0abd40: /* original f459, guest PC 0x0c0abd40 */
if(!s->budget--) { s->failed_pc=0x0c0abd40u; return 0; }
vf3_matrix_load(s,ram,4,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c0abd42;
P_0c0abd42: /* original 880c, guest PC 0x0c0abd42 */
if(!s->budget--) { s->failed_pc=0x0c0abd42u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000cu)!=0);
goto P_0c0abd44;
P_0c0abd44: /* original 8f06, guest PC 0x0c0abd44 */
if(!s->budget--) { s->failed_pc=0x0c0abd44u; return 0; }
cond=r[17]&1u;
vf3_matrix_move(s,6,4);
if(!cond) { goto P_0c0abd54; }
goto P_0c0abd48;
P_0c0abd46: /* original f64c, guest PC 0x0c0abd46 */
if(!s->budget--) { s->failed_pc=0x0c0abd46u; return 0; }
vf3_matrix_move(s,6,4);
goto P_0c0abd48;
P_0c0abd48: /* original c731, guest PC 0x0c0abd48 */
if(!s->budget--) { s->failed_pc=0x0c0abd48u; return 0; }
r[0]=code_base|0x000abe10u;
goto P_0c0abd4a;
P_0c0abd4a: /* original f308, guest PC 0x0c0abd4a */
if(!s->budget--) { s->failed_pc=0x0c0abd4au; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c0abd4c;
P_0c0abd4c: /* original 9057, guest PC 0x0c0abd4c */
if(!s->budget--) { s->failed_pc=0x0c0abd4cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0abdfeu,2);
goto P_0c0abd4e;
P_0c0abd4e: /* original f246, guest PC 0x0c0abd4e */
if(!s->budget--) { s->failed_pc=0x0c0abd4eu; return 0; }
vf3_matrix_load(s,ram,2,r[4]+r[0]);
goto P_0c0abd50;
P_0c0abd50: /* original f325, guest PC 0x0c0abd50 */
if(!s->budget--) { s->failed_pc=0x0c0abd50u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[2]))!=0);
goto P_0c0abd52;
P_0c0abd52: /* original 892b, guest PC 0x0c0abd52 */
if(!s->budget--) { s->failed_pc=0x0c0abd52u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0abdac; }
goto P_0c0abd54;
P_0c0abd54: /* original f559, guest PC 0x0c0abd54 */
if(!s->budget--) { s->failed_pc=0x0c0abd54u; return 0; }
vf3_matrix_load(s,ram,5,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c0abd56;
P_0c0abd56: /* original f545, guest PC 0x0c0abd56 */
if(!s->budget--) { s->failed_pc=0x0c0abd56u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[5])>as_float(fr[4]))!=0);
goto P_0c0abd58;
P_0c0abd58: /* original 8b00, guest PC 0x0c0abd58 */
if(!s->budget--) { s->failed_pc=0x0c0abd58u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0abd5c; }
goto P_0c0abd5a;
P_0c0abd5a: /* original f45c, guest PC 0x0c0abd5a */
if(!s->budget--) { s->failed_pc=0x0c0abd5au; return 0; }
vf3_matrix_move(s,4,5);
goto P_0c0abd5c;
P_0c0abd5c: /* original f655, guest PC 0x0c0abd5c */
if(!s->budget--) { s->failed_pc=0x0c0abd5cu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[6])>as_float(fr[5]))!=0);
goto P_0c0abd5e;
P_0c0abd5e: /* original 8b00, guest PC 0x0c0abd5e */
if(!s->budget--) { s->failed_pc=0x0c0abd5eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0abd62; }
goto P_0c0abd60;
P_0c0abd60: /* original f65c, guest PC 0x0c0abd60 */
if(!s->budget--) { s->failed_pc=0x0c0abd60u; return 0; }
vf3_matrix_move(s,6,5);
goto P_0c0abd62;
P_0c0abd62: /* original 4710, guest PC 0x0c0abd62 */
if(!s->budget--) { s->failed_pc=0x0c0abd62u; return 0; }
--r[7];
r[17]=(r[17]&~1u)|((r[7]==0)!=0);
goto P_0c0abd64;
P_0c0abd64: /* original 8bf6, guest PC 0x0c0abd64 */
if(!s->budget--) { s->failed_pc=0x0c0abd64u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0abd54; }
goto P_0c0abd66;
P_0c0abd66: /* original f461, guest PC 0x0c0abd66 */
if(!s->budget--) { s->failed_pc=0x0c0abd66u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[6],r[18],'-');
goto P_0c0abd68;
P_0c0abd68: /* original f475, guest PC 0x0c0abd68 */
if(!s->budget--) { s->failed_pc=0x0c0abd68u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[4])>as_float(fr[7]))!=0);
goto P_0c0abd6a;
P_0c0abd6a: /* original 8915, guest PC 0x0c0abd6a */
if(!s->budget--) { s->failed_pc=0x0c0abd6au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0abd98; }
goto P_0c0abd6c;
P_0c0abd6c: /* original e01c, guest PC 0x0c0abd6c */
if(!s->budget--) { s->failed_pc=0x0c0abd6cu; return 0; }
r[0]=0x0000001cu;
goto P_0c0abd6e;
P_0c0abd6e: /* original 006c, guest PC 0x0c0abd6e */
if(!s->budget--) { s->failed_pc=0x0c0abd6eu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[6]+r[0],1);
goto P_0c0abd70;
P_0c0abd70: /* original e50f, guest PC 0x0c0abd70 */
if(!s->budget--) { s->failed_pc=0x0c0abd70u; return 0; }
r[5]=0x0000000fu;
goto P_0c0abd72;
P_0c0abd72: /* original 600c, guest PC 0x0c0abd72 */
if(!s->budget--) { s->failed_pc=0x0c0abd72u; return 0; }
r[0]=r[0]&255u;
goto P_0c0abd74;
P_0c0abd74: /* original 2509, guest PC 0x0c0abd74 */
if(!s->budget--) { s->failed_pc=0x0c0abd74u; return 0; }
r[5]&=r[0];
goto P_0c0abd76;
P_0c0abd76: /* original 6053, guest PC 0x0c0abd76 */
if(!s->budget--) { s->failed_pc=0x0c0abd76u; return 0; }
r[0]=r[5];
goto P_0c0abd78;
P_0c0abd78: /* original 8801, guest PC 0x0c0abd78 */
if(!s->budget--) { s->failed_pc=0x0c0abd78u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c0abd7a;
P_0c0abd7a: /* original 8917, guest PC 0x0c0abd7a */
if(!s->budget--) { s->failed_pc=0x0c0abd7au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0abdac; }
goto P_0c0abd7c;
P_0c0abd7c: /* original 6053, guest PC 0x0c0abd7c */
if(!s->budget--) { s->failed_pc=0x0c0abd7cu; return 0; }
r[0]=r[5];
goto P_0c0abd7e;
P_0c0abd7e: /* original 8804, guest PC 0x0c0abd7e */
if(!s->budget--) { s->failed_pc=0x0c0abd7eu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000004u)!=0);
goto P_0c0abd80;
P_0c0abd80: /* original 8914, guest PC 0x0c0abd80 */
if(!s->budget--) { s->failed_pc=0x0c0abd80u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0abdac; }
goto P_0c0abd82;
P_0c0abd82: /* original 6053, guest PC 0x0c0abd82 */
if(!s->budget--) { s->failed_pc=0x0c0abd82u; return 0; }
r[0]=r[5];
goto P_0c0abd84;
P_0c0abd84: /* original 8806, guest PC 0x0c0abd84 */
if(!s->budget--) { s->failed_pc=0x0c0abd84u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000006u)!=0);
goto P_0c0abd86;
P_0c0abd86: /* original 8911, guest PC 0x0c0abd86 */
if(!s->budget--) { s->failed_pc=0x0c0abd86u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0abdac; }
goto P_0c0abd88;
P_0c0abd88: /* original 6053, guest PC 0x0c0abd88 */
if(!s->budget--) { s->failed_pc=0x0c0abd88u; return 0; }
r[0]=r[5];
goto P_0c0abd8a;
P_0c0abd8a: /* original 880c, guest PC 0x0c0abd8a */
if(!s->budget--) { s->failed_pc=0x0c0abd8au; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000cu)!=0);
goto P_0c0abd8c;
P_0c0abd8c: /* original 890e, guest PC 0x0c0abd8c */
if(!s->budget--) { s->failed_pc=0x0c0abd8cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0abdac; }
goto P_0c0abd8e;
P_0c0abd8e: /* original 9037, guest PC 0x0c0abd8e */
if(!s->budget--) { s->failed_pc=0x0c0abd8eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0abe00u,2);
goto P_0c0abd90;
P_0c0abd90: /* original 004c, guest PC 0x0c0abd90 */
if(!s->budget--) { s->failed_pc=0x0c0abd90u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c0abd92;
P_0c0abd92: /* original 600c, guest PC 0x0c0abd92 */
if(!s->budget--) { s->failed_pc=0x0c0abd92u; return 0; }
r[0]=r[0]&255u;
goto P_0c0abd94;
P_0c0abd94: /* original c810, guest PC 0x0c0abd94 */
if(!s->budget--) { s->failed_pc=0x0c0abd94u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&16u)==0)!=0);
goto P_0c0abd96;
P_0c0abd96: /* original 8909, guest PC 0x0c0abd96 */
if(!s->budget--) { s->failed_pc=0x0c0abd96u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0abdac; }
goto P_0c0abd98;
P_0c0abd98: /* original 9033, guest PC 0x0c0abd98 */
if(!s->budget--) { s->failed_pc=0x0c0abd98u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0abe02u,2);
goto P_0c0abd9a;
P_0c0abd9a: /* original f446, guest PC 0x0c0abd9a */
if(!s->budget--) { s->failed_pc=0x0c0abd9au; return 0; }
vf3_matrix_load(s,ram,4,r[4]+r[0]);
goto P_0c0abd9c;
P_0c0abd9c: /* original 7004, guest PC 0x0c0abd9c */
if(!s->budget--) { s->failed_pc=0x0c0abd9cu; return 0; }
r[0]+=0x00000004u;
goto P_0c0abd9e;
P_0c0abd9e: /* original f546, guest PC 0x0c0abd9e */
if(!s->budget--) { s->failed_pc=0x0c0abd9eu; return 0; }
vf3_matrix_load(s,ram,5,r[4]+r[0]);
goto P_0c0abda0;
P_0c0abda0: /* original e024, guest PC 0x0c0abda0 */
if(!s->budget--) { s->failed_pc=0x0c0abda0u; return 0; }
r[0]=0x00000024u;
goto P_0c0abda2;
P_0c0abda2: /* original f447, guest PC 0x0c0abda2 */
if(!s->budget--) { s->failed_pc=0x0c0abda2u; return 0; }
vf3_matrix_store(s,ram,4,r[4]+r[0]);
goto P_0c0abda4;
P_0c0abda4: /* original e02c, guest PC 0x0c0abda4 */
if(!s->budget--) { s->failed_pc=0x0c0abda4u; return 0; }
r[0]=0x0000002cu;
goto P_0c0abda6;
P_0c0abda6: /* original f457, guest PC 0x0c0abda6 */
if(!s->budget--) { s->failed_pc=0x0c0abda6u; return 0; }
vf3_matrix_store(s,ram,5,r[4]+r[0]);
goto P_0c0abda8;
P_0c0abda8: /* original a00a, guest PC 0x0c0abda8 */
if(!s->budget--) { s->failed_pc=0x0c0abda8u; return 0; }
r[5]=0x00000001u;
goto P_0c0abdc0;
P_0c0abdaa: /* original e501, guest PC 0x0c0abdaa */
if(!s->budget--) { s->failed_pc=0x0c0abdaau; return 0; }
r[5]=0x00000001u;
goto P_0c0abdac;
P_0c0abdac: /* original e024, guest PC 0x0c0abdac */
if(!s->budget--) { s->failed_pc=0x0c0abdacu; return 0; }
r[0]=0x00000024u;
goto P_0c0abdae;
P_0c0abdae: /* original f48d, guest PC 0x0c0abdae */
if(!s->budget--) { s->failed_pc=0x0c0abdaeu; return 0; }
fr[4]=0;
goto P_0c0abdb0;
P_0c0abdb0: /* original f447, guest PC 0x0c0abdb0 */
if(!s->budget--) { s->failed_pc=0x0c0abdb0u; return 0; }
vf3_matrix_store(s,ram,4,r[4]+r[0]);
goto P_0c0abdb2;
P_0c0abdb2: /* original e02c, guest PC 0x0c0abdb2 */
if(!s->budget--) { s->failed_pc=0x0c0abdb2u; return 0; }
r[0]=0x0000002cu;
goto P_0c0abdb4;
P_0c0abdb4: /* original f447, guest PC 0x0c0abdb4 */
if(!s->budget--) { s->failed_pc=0x0c0abdb4u; return 0; }
vf3_matrix_store(s,ram,4,r[4]+r[0]);
goto P_0c0abdb6;
P_0c0abdb6: /* original e500, guest PC 0x0c0abdb6 */
if(!s->budget--) { s->failed_pc=0x0c0abdb6u; return 0; }
r[5]=0x00000000u;
goto P_0c0abdb8;
P_0c0abdb8: /* original 9024, guest PC 0x0c0abdb8 */
if(!s->budget--) { s->failed_pc=0x0c0abdb8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0abe04u,2);
goto P_0c0abdba;
P_0c0abdba: /* original f447, guest PC 0x0c0abdba */
if(!s->budget--) { s->failed_pc=0x0c0abdbau; return 0; }
vf3_matrix_store(s,ram,4,r[4]+r[0]);
goto P_0c0abdbc;
P_0c0abdbc: /* original 7008, guest PC 0x0c0abdbc */
if(!s->budget--) { s->failed_pc=0x0c0abdbcu; return 0; }
r[0]+=0x00000008u;
goto P_0c0abdbe;
P_0c0abdbe: /* original f447, guest PC 0x0c0abdbe */
if(!s->budget--) { s->failed_pc=0x0c0abdbeu; return 0; }
vf3_matrix_store(s,ram,4,r[4]+r[0]);
goto P_0c0abdc0;
P_0c0abdc0: /* original 000b, guest PC 0x0c0abdc0 */
if(!s->budget--) { s->failed_pc=0x0c0abdc0u; return 0; }
target=r[16];
r[0]=r[5];
s->pc=target; return ram->oob==0;
P_0c0abdc2: /* original 6053, guest PC 0x0c0abdc2 */
if(!s->budget--) { s->failed_pc=0x0c0abdc2u; return 0; }
r[0]=r[5];
goto P_0c0abdc4;
P_0c0abdc4: /* original 901b, guest PC 0x0c0abdc4 */
if(!s->budget--) { s->failed_pc=0x0c0abdc4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0abdfeu,2);
goto P_0c0abdc6;
P_0c0abdc6: /* original d510, guest PC 0x0c0abdc6 */
if(!s->budget--) { s->failed_pc=0x0c0abdc6u; return 0; }
r[5]=read(ram,0x0c0abe08u,4);
goto P_0c0abdc8;
P_0c0abdc8: /* original f546, guest PC 0x0c0abdc8 */
if(!s->budget--) { s->failed_pc=0x0c0abdc8u; return 0; }
vf3_matrix_load(s,ram,5,r[4]+r[0]);
goto P_0c0abdca;
P_0c0abdca: /* original 70fc, guest PC 0x0c0abdca */
if(!s->budget--) { s->failed_pc=0x0c0abdcau; return 0; }
r[0]+=0xfffffffcu;
goto P_0c0abdcc;
P_0c0abdcc: /* original f446, guest PC 0x0c0abdcc */
if(!s->budget--) { s->failed_pc=0x0c0abdccu; return 0; }
vf3_matrix_load(s,ram,4,r[4]+r[0]);
goto P_0c0abdce;
P_0c0abdce: /* original e01c, guest PC 0x0c0abdce */
if(!s->budget--) { s->failed_pc=0x0c0abdceu; return 0; }
r[0]=0x0000001cu;
goto P_0c0abdd0;
P_0c0abdd0: /* original 005c, guest PC 0x0c0abdd0 */
if(!s->budget--) { s->failed_pc=0x0c0abdd0u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[5]+r[0],1);
goto P_0c0abdd2;
P_0c0abdd2: /* original e50f, guest PC 0x0c0abdd2 */
if(!s->budget--) { s->failed_pc=0x0c0abdd2u; return 0; }
r[5]=0x0000000fu;
goto P_0c0abdd4;
P_0c0abdd4: /* original 600c, guest PC 0x0c0abdd4 */
if(!s->budget--) { s->failed_pc=0x0c0abdd4u; return 0; }
r[0]=r[0]&255u;
goto P_0c0abdd6;
P_0c0abdd6: /* original 2509, guest PC 0x0c0abdd6 */
if(!s->budget--) { s->failed_pc=0x0c0abdd6u; return 0; }
r[5]&=r[0];
goto P_0c0abdd8;
P_0c0abdd8: /* original c70e, guest PC 0x0c0abdd8 */
if(!s->budget--) { s->failed_pc=0x0c0abdd8u; return 0; }
r[0]=code_base|0x000abe14u;
goto P_0c0abdda;
P_0c0abdda: /* original f608, guest PC 0x0c0abdda */
if(!s->budget--) { s->failed_pc=0x0c0abddau; return 0; }
vf3_matrix_load(s,ram,6,r[0]);
goto P_0c0abddc;
P_0c0abddc: /* original 6053, guest PC 0x0c0abddc */
if(!s->budget--) { s->failed_pc=0x0c0abddcu; return 0; }
r[0]=r[5];
goto P_0c0abdde;
P_0c0abdde: /* original 8807, guest PC 0x0c0abdde */
if(!s->budget--) { s->failed_pc=0x0c0abddeu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000007u)!=0);
goto P_0c0abde0;
P_0c0abde0: /* original 891e, guest PC 0x0c0abde0 */
if(!s->budget--) { s->failed_pc=0x0c0abde0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0abe20; }
goto P_0c0abde2;
P_0c0abde2: /* original 6053, guest PC 0x0c0abde2 */
if(!s->budget--) { s->failed_pc=0x0c0abde2u; return 0; }
r[0]=r[5];
goto P_0c0abde4;
P_0c0abde4: /* original 8805, guest PC 0x0c0abde4 */
if(!s->budget--) { s->failed_pc=0x0c0abde4u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000005u)!=0);
goto P_0c0abde6;
P_0c0abde6: /* original 8b31, guest PC 0x0c0abde6 */
if(!s->budget--) { s->failed_pc=0x0c0abde6u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0abe4c; }
goto P_0c0abde8;
P_0c0abde8: /* original c70b, guest PC 0x0c0abde8 */
if(!s->budget--) { s->failed_pc=0x0c0abde8u; return 0; }
r[0]=code_base|0x000abe18u;
goto P_0c0abdea;
P_0c0abdea: /* original f308, guest PC 0x0c0abdea */
if(!s->budget--) { s->failed_pc=0x0c0abdeau; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c0abdec;
P_0c0abdec: /* original f435, guest PC 0x0c0abdec */
if(!s->budget--) { s->failed_pc=0x0c0abdecu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[4])>as_float(fr[3]))!=0);
goto P_0c0abdee;
P_0c0abdee: /* original 892d, guest PC 0x0c0abdee */
if(!s->budget--) { s->failed_pc=0x0c0abdeeu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0abe4c; }
goto P_0c0abdf0;
P_0c0abdf0: /* original c70a, guest PC 0x0c0abdf0 */
if(!s->budget--) { s->failed_pc=0x0c0abdf0u; return 0; }
r[0]=code_base|0x000abe1cu;
goto P_0c0abdf2;
P_0c0abdf2: /* original f308, guest PC 0x0c0abdf2 */
if(!s->budget--) { s->failed_pc=0x0c0abdf2u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c0abdf4;
P_0c0abdf4: /* original f345, guest PC 0x0c0abdf4 */
if(!s->budget--) { s->failed_pc=0x0c0abdf4u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[4]))!=0);
goto P_0c0abdf6;
P_0c0abdf6: /* original 8929, guest PC 0x0c0abdf6 */
if(!s->budget--) { s->failed_pc=0x0c0abdf6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0abe4c; }
goto P_0c0abdf8;
P_0c0abdf8: /* original a026, guest PC 0x0c0abdf8 */
if(!s->budget--) { s->failed_pc=0x0c0abdf8u; return 0; }
goto P_0c0abe48;
P_0c0abdfa: /* original 0009, guest PC 0x0c0abdfa */
if(!s->budget--) { s->failed_pc=0x0c0abdfau; return 0; }
if(!vf3_matrix_family(0x0c0abdfcu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0abdfcu; return 0; } return 1;
P_0c0abe20: /* original c740, guest PC 0x0c0abe20 */
if(!s->budget--) { s->failed_pc=0x0c0abe20u; return 0; }
r[0]=code_base|0x000abf24u;
goto P_0c0abe22;
P_0c0abe22: /* original f308, guest PC 0x0c0abe22 */
if(!s->budget--) { s->failed_pc=0x0c0abe22u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c0abe24;
P_0c0abe24: /* original f355, guest PC 0x0c0abe24 */
if(!s->budget--) { s->failed_pc=0x0c0abe24u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[5]))!=0);
goto P_0c0abe26;
P_0c0abe26: /* original 8911, guest PC 0x0c0abe26 */
if(!s->budget--) { s->failed_pc=0x0c0abe26u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0abe4c; }
goto P_0c0abe28;
P_0c0abe28: /* original c73f, guest PC 0x0c0abe28 */
if(!s->budget--) { s->failed_pc=0x0c0abe28u; return 0; }
r[0]=code_base|0x000abf28u;
goto P_0c0abe2a;
P_0c0abe2a: /* original f308, guest PC 0x0c0abe2a */
if(!s->budget--) { s->failed_pc=0x0c0abe2au; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c0abe2c;
P_0c0abe2c: /* original f435, guest PC 0x0c0abe2c */
if(!s->budget--) { s->failed_pc=0x0c0abe2cu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[4])>as_float(fr[3]))!=0);
goto P_0c0abe2e;
P_0c0abe2e: /* original 8906, guest PC 0x0c0abe2e */
if(!s->budget--) { s->failed_pc=0x0c0abe2eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0abe3e; }
goto P_0c0abe30;
P_0c0abe30: /* original c73e, guest PC 0x0c0abe30 */
if(!s->budget--) { s->failed_pc=0x0c0abe30u; return 0; }
r[0]=code_base|0x000abf2cu;
goto P_0c0abe32;
P_0c0abe32: /* original f308, guest PC 0x0c0abe32 */
if(!s->budget--) { s->failed_pc=0x0c0abe32u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c0abe34;
P_0c0abe34: /* original f345, guest PC 0x0c0abe34 */
if(!s->budget--) { s->failed_pc=0x0c0abe34u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[4]))!=0);
goto P_0c0abe36;
P_0c0abe36: /* original 8907, guest PC 0x0c0abe36 */
if(!s->budget--) { s->failed_pc=0x0c0abe36u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0abe48; }
goto P_0c0abe38;
P_0c0abe38: /* original f38d, guest PC 0x0c0abe38 */
if(!s->budget--) { s->failed_pc=0x0c0abe38u; return 0; }
fr[3]=0;
goto P_0c0abe3a;
P_0c0abe3a: /* original f435, guest PC 0x0c0abe3a */
if(!s->budget--) { s->failed_pc=0x0c0abe3au; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[4])>as_float(fr[3]))!=0);
goto P_0c0abe3c;
P_0c0abe3c: /* original 8904, guest PC 0x0c0abe3c */
if(!s->budget--) { s->failed_pc=0x0c0abe3cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0abe48; }
goto P_0c0abe3e;
P_0c0abe3e: /* original c73c, guest PC 0x0c0abe3e */
if(!s->budget--) { s->failed_pc=0x0c0abe3eu; return 0; }
r[0]=code_base|0x000abf30u;
goto P_0c0abe40;
P_0c0abe40: /* original f308, guest PC 0x0c0abe40 */
if(!s->budget--) { s->failed_pc=0x0c0abe40u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c0abe42;
P_0c0abe42: /* original e024, guest PC 0x0c0abe42 */
if(!s->budget--) { s->failed_pc=0x0c0abe42u; return 0; }
r[0]=0x00000024u;
goto P_0c0abe44;
P_0c0abe44: /* original 000b, guest PC 0x0c0abe44 */
if(!s->budget--) { s->failed_pc=0x0c0abe44u; return 0; }
target=r[16];
vf3_matrix_store(s,ram,3,r[4]+r[0]);
s->pc=target; return ram->oob==0;
P_0c0abe46: /* original f437, guest PC 0x0c0abe46 */
if(!s->budget--) { s->failed_pc=0x0c0abe46u; return 0; }
vf3_matrix_store(s,ram,3,r[4]+r[0]);
goto P_0c0abe48;
P_0c0abe48: /* original e024, guest PC 0x0c0abe48 */
if(!s->budget--) { s->failed_pc=0x0c0abe48u; return 0; }
r[0]=0x00000024u;
goto P_0c0abe4a;
P_0c0abe4a: /* original f467, guest PC 0x0c0abe4a */
if(!s->budget--) { s->failed_pc=0x0c0abe4au; return 0; }
vf3_matrix_store(s,ram,6,r[4]+r[0]);
goto P_0c0abe4c;
P_0c0abe4c: /* original 000b, guest PC 0x0c0abe4c */
if(!s->budget--) { s->failed_pc=0x0c0abe4cu; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c0abe4e: /* original 0009, guest PC 0x0c0abe4e */
if(!s->budget--) { s->failed_pc=0x0c0abe4eu; return 0; }
goto P_0c0abe50;
P_0c0abe50: /* original d538, guest PC 0x0c0abe50 */
if(!s->budget--) { s->failed_pc=0x0c0abe50u; return 0; }
r[5]=read(ram,0x0c0abf34u,4);
goto P_0c0abe52;
P_0c0abe52: /* original e01c, guest PC 0x0c0abe52 */
if(!s->budget--) { s->failed_pc=0x0c0abe52u; return 0; }
r[0]=0x0000001cu;
goto P_0c0abe54;
P_0c0abe54: /* original 005c, guest PC 0x0c0abe54 */
if(!s->budget--) { s->failed_pc=0x0c0abe54u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[5]+r[0],1);
goto P_0c0abe56;
P_0c0abe56: /* original 600c, guest PC 0x0c0abe56 */
if(!s->budget--) { s->failed_pc=0x0c0abe56u; return 0; }
r[0]=r[0]&255u;
goto P_0c0abe58;
P_0c0abe58: /* original c90f, guest PC 0x0c0abe58 */
if(!s->budget--) { s->failed_pc=0x0c0abe58u; return 0; }
r[0]&=15u;
goto P_0c0abe5a;
P_0c0abe5a: /* original 8807, guest PC 0x0c0abe5a */
if(!s->budget--) { s->failed_pc=0x0c0abe5au; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000007u)!=0);
goto P_0c0abe5c;
P_0c0abe5c: /* original 8b10, guest PC 0x0c0abe5c */
if(!s->budget--) { s->failed_pc=0x0c0abe5cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0abe80; }
goto P_0c0abe5e;
P_0c0abe5e: /* original 905e, guest PC 0x0c0abe5e */
if(!s->budget--) { s->failed_pc=0x0c0abe5eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0abf1eu,2);
goto P_0c0abe60;
P_0c0abe60: /* original 024e, guest PC 0x0c0abe60 */
if(!s->budget--) { s->failed_pc=0x0c0abe60u; return 0; }
r[2]=read(ram,r[4]+r[0],4);
goto P_0c0abe62;
P_0c0abe62: /* original 2228, guest PC 0x0c0abe62 */
if(!s->budget--) { s->failed_pc=0x0c0abe62u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c0abe64;
P_0c0abe64: /* original 890c, guest PC 0x0c0abe64 */
if(!s->budget--) { s->failed_pc=0x0c0abe64u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0abe80; }
goto P_0c0abe66;
P_0c0abe66: /* original c734, guest PC 0x0c0abe66 */
if(!s->budget--) { s->failed_pc=0x0c0abe66u; return 0; }
r[0]=code_base|0x000abf38u;
goto P_0c0abe68;
P_0c0abe68: /* original f308, guest PC 0x0c0abe68 */
if(!s->budget--) { s->failed_pc=0x0c0abe68u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c0abe6a;
P_0c0abe6a: /* original 9059, guest PC 0x0c0abe6a */
if(!s->budget--) { s->failed_pc=0x0c0abe6au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0abf20u,2);
goto P_0c0abe6c;
P_0c0abe6c: /* original f246, guest PC 0x0c0abe6c */
if(!s->budget--) { s->failed_pc=0x0c0abe6cu; return 0; }
vf3_matrix_load(s,ram,2,r[4]+r[0]);
goto P_0c0abe6e;
P_0c0abe6e: /* original f235, guest PC 0x0c0abe6e */
if(!s->budget--) { s->failed_pc=0x0c0abe6eu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[2])>as_float(fr[3]))!=0);
goto P_0c0abe70;
P_0c0abe70: /* original 8906, guest PC 0x0c0abe70 */
if(!s->budget--) { s->failed_pc=0x0c0abe70u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0abe80; }
goto P_0c0abe72;
P_0c0abe72: /* original e024, guest PC 0x0c0abe72 */
if(!s->budget--) { s->failed_pc=0x0c0abe72u; return 0; }
r[0]=0x00000024u;
goto P_0c0abe74;
P_0c0abe74: /* original f546, guest PC 0x0c0abe74 */
if(!s->budget--) { s->failed_pc=0x0c0abe74u; return 0; }
vf3_matrix_load(s,ram,5,r[4]+r[0]);
goto P_0c0abe76;
P_0c0abe76: /* original e02c, guest PC 0x0c0abe76 */
if(!s->budget--) { s->failed_pc=0x0c0abe76u; return 0; }
r[0]=0x0000002cu;
goto P_0c0abe78;
P_0c0abe78: /* original f446, guest PC 0x0c0abe78 */
if(!s->budget--) { s->failed_pc=0x0c0abe78u; return 0; }
vf3_matrix_load(s,ram,4,r[4]+r[0]);
goto P_0c0abe7a;
P_0c0abe7a: /* original f457, guest PC 0x0c0abe7a */
if(!s->budget--) { s->failed_pc=0x0c0abe7au; return 0; }
vf3_matrix_store(s,ram,5,r[4]+r[0]);
goto P_0c0abe7c;
P_0c0abe7c: /* original e024, guest PC 0x0c0abe7c */
if(!s->budget--) { s->failed_pc=0x0c0abe7cu; return 0; }
r[0]=0x00000024u;
goto P_0c0abe7e;
P_0c0abe7e: /* original f447, guest PC 0x0c0abe7e */
if(!s->budget--) { s->failed_pc=0x0c0abe7eu; return 0; }
vf3_matrix_store(s,ram,4,r[4]+r[0]);
goto P_0c0abe80;
P_0c0abe80: /* original 000b, guest PC 0x0c0abe80 */
if(!s->budget--) { s->failed_pc=0x0c0abe80u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c0abe82: /* original 0009, guest PC 0x0c0abe82 */
if(!s->budget--) { s->failed_pc=0x0c0abe82u; return 0; }
if(!vf3_matrix_family(0x0c0abe84u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0abe84u; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
