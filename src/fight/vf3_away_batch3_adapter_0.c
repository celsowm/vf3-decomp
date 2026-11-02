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
int vf3_away_batch3_adapter_0(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c034800u: goto P_0c034800;
case 0x0c034802u: goto P_0c034802;
case 0x0c034804u: goto P_0c034804;
case 0x0c034806u: goto P_0c034806;
case 0x0c034808u: goto P_0c034808;
case 0x0c03480au: goto P_0c03480a;
case 0x0c03480cu: goto P_0c03480c;
case 0x0c03480eu: goto P_0c03480e;
case 0x0c034810u: goto P_0c034810;
case 0x0c034812u: goto P_0c034812;
case 0x0c034814u: goto P_0c034814;
case 0x0c034816u: goto P_0c034816;
case 0x0c034818u: goto P_0c034818;
case 0x0c03481au: goto P_0c03481a;
case 0x0c03481cu: goto P_0c03481c;
case 0x0c03481eu: goto P_0c03481e;
case 0x0c034820u: goto P_0c034820;
case 0x0c034822u: goto P_0c034822;
case 0x0c034824u: goto P_0c034824;
case 0x0c035b1cu: goto P_0c035b1c;
case 0x0c035b1eu: goto P_0c035b1e;
case 0x0c035b20u: goto P_0c035b20;
case 0x0c035b22u: goto P_0c035b22;
case 0x0c035b24u: goto P_0c035b24;
case 0x0c035b26u: goto P_0c035b26;
case 0x0c035b28u: goto P_0c035b28;
case 0x0c035b2au: goto P_0c035b2a;
case 0x0c035b2cu: goto P_0c035b2c;
case 0x0c035b2eu: goto P_0c035b2e;
case 0x0c035b30u: goto P_0c035b30;
case 0x0c035e90u: goto P_0c035e90;
case 0x0c035e92u: goto P_0c035e92;
case 0x0c035e94u: goto P_0c035e94;
case 0x0c035e96u: goto P_0c035e96;
case 0x0c035e98u: goto P_0c035e98;
case 0x0c035e9au: goto P_0c035e9a;
case 0x0c035e9cu: goto P_0c035e9c;
case 0x0c035e9eu: goto P_0c035e9e;
case 0x0c035ea0u: goto P_0c035ea0;
case 0x0c035ea2u: goto P_0c035ea2;
case 0x0c035ed8u: goto P_0c035ed8;
case 0x0c035edau: goto P_0c035eda;
case 0x0c035edcu: goto P_0c035edc;
case 0x0c035edeu: goto P_0c035ede;
case 0x0c035ee0u: goto P_0c035ee0;
case 0x0c035ee2u: goto P_0c035ee2;
case 0x0c035ee4u: goto P_0c035ee4;
case 0x0c035ee6u: goto P_0c035ee6;
case 0x0c035ee8u: goto P_0c035ee8;
case 0x0c035eeau: goto P_0c035eea;
case 0x0c035eecu: goto P_0c035eec;
case 0x0c035eeeu: goto P_0c035eee;
case 0x0c035ef0u: goto P_0c035ef0;
case 0x0c035ef2u: goto P_0c035ef2;
case 0x0c035ef4u: goto P_0c035ef4;
case 0x0c035ef6u: goto P_0c035ef6;
case 0x0c035ef8u: goto P_0c035ef8;
case 0x0c035efau: goto P_0c035efa;
case 0x0c035efcu: goto P_0c035efc;
case 0x0c035efeu: goto P_0c035efe;
case 0x0c035f00u: goto P_0c035f00;
case 0x0c035f02u: goto P_0c035f02;
case 0x0c035f04u: goto P_0c035f04;
case 0x0c035f06u: goto P_0c035f06;
case 0x0c035f08u: goto P_0c035f08;
case 0x0c035f0au: goto P_0c035f0a;
case 0x0c035f0cu: goto P_0c035f0c;
case 0x0c035f0eu: goto P_0c035f0e;
case 0x0c035f10u: goto P_0c035f10;
case 0x0c035f12u: goto P_0c035f12;
case 0x0c035f14u: goto P_0c035f14;
case 0x0c035f16u: goto P_0c035f16;
case 0x0c035f18u: goto P_0c035f18;
case 0x0c035f1au: goto P_0c035f1a;
case 0x0c035f1cu: goto P_0c035f1c;
case 0x0c035f1eu: goto P_0c035f1e;
case 0x0c035f20u: goto P_0c035f20;
case 0x0c035f22u: goto P_0c035f22;
case 0x0c035f24u: goto P_0c035f24;
case 0x0c035f26u: goto P_0c035f26;
case 0x0c035f28u: goto P_0c035f28;
case 0x0c035f2au: goto P_0c035f2a;
case 0x0c035f2cu: goto P_0c035f2c;
case 0x0c035f2eu: goto P_0c035f2e;
case 0x0c035f30u: goto P_0c035f30;
case 0x0c035f32u: goto P_0c035f32;
case 0x0c035f34u: goto P_0c035f34;
case 0x0c035f36u: goto P_0c035f36;
case 0x0c035f38u: goto P_0c035f38;
case 0x0c035f3au: goto P_0c035f3a;
case 0x0c035f3cu: goto P_0c035f3c;
case 0x0c035f3eu: goto P_0c035f3e;
case 0x0c035f40u: goto P_0c035f40;
case 0x0c035f42u: goto P_0c035f42;
case 0x0c035f44u: goto P_0c035f44;
case 0x0c035f46u: goto P_0c035f46;
case 0x0c035f48u: goto P_0c035f48;
case 0x0c035f4au: goto P_0c035f4a;
case 0x0c035f4cu: goto P_0c035f4c;
case 0x0c035f4eu: goto P_0c035f4e;
case 0x0c035f50u: goto P_0c035f50;
case 0x0c035f52u: goto P_0c035f52;
case 0x0c035f54u: goto P_0c035f54;
case 0x0c035f56u: goto P_0c035f56;
case 0x0c035f58u: goto P_0c035f58;
case 0x0c035f5au: goto P_0c035f5a;
case 0x0c035f5cu: goto P_0c035f5c;
case 0x0c035f5eu: goto P_0c035f5e;
case 0x0c035f60u: goto P_0c035f60;
case 0x0c035f62u: goto P_0c035f62;
case 0x0c035f64u: goto P_0c035f64;
case 0x0c035f66u: goto P_0c035f66;
case 0x0c035f68u: goto P_0c035f68;
case 0x0c035f6au: goto P_0c035f6a;
case 0x0c035f6cu: goto P_0c035f6c;
case 0x0c035f6eu: goto P_0c035f6e;
case 0x0c035f70u: goto P_0c035f70;
case 0x0c035f72u: goto P_0c035f72;
case 0x0c035f74u: goto P_0c035f74;
case 0x0c035f76u: goto P_0c035f76;
case 0x0c035f78u: goto P_0c035f78;
case 0x0c035f7au: goto P_0c035f7a;
case 0x0c035f7cu: goto P_0c035f7c;
case 0x0c035f7eu: goto P_0c035f7e;
case 0x0c035f80u: goto P_0c035f80;
case 0x0c035f82u: goto P_0c035f82;
case 0x0c035f84u: goto P_0c035f84;
case 0x0c035f86u: goto P_0c035f86;
case 0x0c035f88u: goto P_0c035f88;
case 0x0c035f8au: goto P_0c035f8a;
case 0x0c035f8cu: goto P_0c035f8c;
case 0x0c035f8eu: goto P_0c035f8e;
case 0x0c035f90u: goto P_0c035f90;
case 0x0c035f92u: goto P_0c035f92;
case 0x0c035f94u: goto P_0c035f94;
case 0x0c035f96u: goto P_0c035f96;
case 0x0c035f98u: goto P_0c035f98;
case 0x0c035f9au: goto P_0c035f9a;
case 0x0c035f9cu: goto P_0c035f9c;
case 0x0c035f9eu: goto P_0c035f9e;
case 0x0c035fa0u: goto P_0c035fa0;
case 0x0c035fa2u: goto P_0c035fa2;
case 0x0c035fa4u: goto P_0c035fa4;
case 0x0c035fa6u: goto P_0c035fa6;
case 0x0c035fa8u: goto P_0c035fa8;
case 0x0c035faau: goto P_0c035faa;
case 0x0c035facu: goto P_0c035fac;
case 0x0c035faeu: goto P_0c035fae;
case 0x0c035fb0u: goto P_0c035fb0;
case 0x0c035fb2u: goto P_0c035fb2;
case 0x0c035fb4u: goto P_0c035fb4;
case 0x0c035fb6u: goto P_0c035fb6;
case 0x0c035fb8u: goto P_0c035fb8;
case 0x0c035fbau: goto P_0c035fba;
case 0x0c035fbcu: goto P_0c035fbc;
case 0x0c035fbeu: goto P_0c035fbe;
case 0x0c035fc0u: goto P_0c035fc0;
case 0x0c035fc2u: goto P_0c035fc2;
case 0x0c035fc4u: goto P_0c035fc4;
case 0x0c035fc6u: goto P_0c035fc6;
case 0x0c035ff8u: goto P_0c035ff8;
case 0x0c035ffau: goto P_0c035ffa;
case 0x0c035ffcu: goto P_0c035ffc;
case 0x0c035ffeu: goto P_0c035ffe;
case 0x0c036000u: goto P_0c036000;
case 0x0c036002u: goto P_0c036002;
case 0x0c036004u: goto P_0c036004;
case 0x0c036006u: goto P_0c036006;
case 0x0c036008u: goto P_0c036008;
case 0x0c03600au: goto P_0c03600a;
case 0x0c03600cu: goto P_0c03600c;
case 0x0c03600eu: goto P_0c03600e;
case 0x0c036010u: goto P_0c036010;
case 0x0c036012u: goto P_0c036012;
case 0x0c036014u: goto P_0c036014;
case 0x0c036016u: goto P_0c036016;
case 0x0c036018u: goto P_0c036018;
case 0x0c03601au: goto P_0c03601a;
case 0x0c03601cu: goto P_0c03601c;
case 0x0c03601eu: goto P_0c03601e;
case 0x0c036020u: goto P_0c036020;
case 0x0c036022u: goto P_0c036022;
case 0x0c036024u: goto P_0c036024;
case 0x0c036026u: goto P_0c036026;
case 0x0c036028u: goto P_0c036028;
case 0x0c03602au: goto P_0c03602a;
case 0x0c03602cu: goto P_0c03602c;
case 0x0c03602eu: goto P_0c03602e;
case 0x0c036030u: goto P_0c036030;
case 0x0c036032u: goto P_0c036032;
case 0x0c036034u: goto P_0c036034;
case 0x0c036036u: goto P_0c036036;
case 0x0c036038u: goto P_0c036038;
case 0x0c03603au: goto P_0c03603a;
case 0x0c03603cu: goto P_0c03603c;
case 0x0c03603eu: goto P_0c03603e;
case 0x0c036040u: goto P_0c036040;
case 0x0c036042u: goto P_0c036042;
case 0x0c036044u: goto P_0c036044;
case 0x0c036046u: goto P_0c036046;
case 0x0c036048u: goto P_0c036048;
case 0x0c03604au: goto P_0c03604a;
case 0x0c03604cu: goto P_0c03604c;
case 0x0c03604eu: goto P_0c03604e;
case 0x0c036050u: goto P_0c036050;
case 0x0c036052u: goto P_0c036052;
case 0x0c036054u: goto P_0c036054;
case 0x0c036056u: goto P_0c036056;
case 0x0c036058u: goto P_0c036058;
case 0x0c03605au: goto P_0c03605a;
case 0x0c03605cu: goto P_0c03605c;
case 0x0c03605eu: goto P_0c03605e;
case 0x0c036060u: goto P_0c036060;
case 0x0c036062u: goto P_0c036062;
case 0x0c036064u: goto P_0c036064;
case 0x0c036066u: goto P_0c036066;
case 0x0c036068u: goto P_0c036068;
case 0x0c03606au: goto P_0c03606a;
case 0x0c03606cu: goto P_0c03606c;
case 0x0c03606eu: goto P_0c03606e;
case 0x0c036070u: goto P_0c036070;
case 0x0c036072u: goto P_0c036072;
case 0x0c036074u: goto P_0c036074;
case 0x0c036076u: goto P_0c036076;
case 0x0c036078u: goto P_0c036078;
case 0x0c03607au: goto P_0c03607a;
case 0x0c03607cu: goto P_0c03607c;
case 0x0c03607eu: goto P_0c03607e;
case 0x0c036080u: goto P_0c036080;
case 0x0c036082u: goto P_0c036082;
case 0x0c036084u: goto P_0c036084;
case 0x0c036086u: goto P_0c036086;
case 0x0c036088u: goto P_0c036088;
case 0x0c03608au: goto P_0c03608a;
case 0x0c03608cu: goto P_0c03608c;
case 0x0c03608eu: goto P_0c03608e;
case 0x0c036090u: goto P_0c036090;
case 0x0c036092u: goto P_0c036092;
case 0x0c036094u: goto P_0c036094;
case 0x0c036096u: goto P_0c036096;
case 0x0c036098u: goto P_0c036098;
case 0x0c03609au: goto P_0c03609a;
case 0x0c03609cu: goto P_0c03609c;
case 0x0c03609eu: goto P_0c03609e;
case 0x0c0360a0u: goto P_0c0360a0;
case 0x0c0360a2u: goto P_0c0360a2;
case 0x0c0360a4u: goto P_0c0360a4;
case 0x0c0360a6u: goto P_0c0360a6;
case 0x0c0360a8u: goto P_0c0360a8;
case 0x0c0360aau: goto P_0c0360aa;
case 0x0c0360acu: goto P_0c0360ac;
case 0x0c0360aeu: goto P_0c0360ae;
case 0x0c0360b0u: goto P_0c0360b0;
case 0x0c0360b2u: goto P_0c0360b2;
case 0x0c0360b4u: goto P_0c0360b4;
case 0x0c0360b6u: goto P_0c0360b6;
case 0x0c0360b8u: goto P_0c0360b8;
case 0x0c0360bau: goto P_0c0360ba;
case 0x0c0360bcu: goto P_0c0360bc;
case 0x0c0360beu: goto P_0c0360be;
case 0x0c0360c0u: goto P_0c0360c0;
case 0x0c0360c2u: goto P_0c0360c2;
case 0x0c0360c4u: goto P_0c0360c4;
case 0x0c0360c6u: goto P_0c0360c6;
case 0x0c0360c8u: goto P_0c0360c8;
case 0x0c0360fcu: goto P_0c0360fc;
case 0x0c0360feu: goto P_0c0360fe;
case 0x0c036100u: goto P_0c036100;
case 0x0c036102u: goto P_0c036102;
case 0x0c036104u: goto P_0c036104;
case 0x0c036106u: goto P_0c036106;
case 0x0c036108u: goto P_0c036108;
case 0x0c03610au: goto P_0c03610a;
case 0x0c03610cu: goto P_0c03610c;
case 0x0c03610eu: goto P_0c03610e;
case 0x0c036110u: goto P_0c036110;
case 0x0c036112u: goto P_0c036112;
case 0x0c036114u: goto P_0c036114;
case 0x0c036116u: goto P_0c036116;
case 0x0c036118u: goto P_0c036118;
case 0x0c03611au: goto P_0c03611a;
case 0x0c03611cu: goto P_0c03611c;
case 0x0c03611eu: goto P_0c03611e;
case 0x0c036120u: goto P_0c036120;
case 0x0c036122u: goto P_0c036122;
case 0x0c036124u: goto P_0c036124;
case 0x0c036126u: goto P_0c036126;
case 0x0c036128u: goto P_0c036128;
case 0x0c03612au: goto P_0c03612a;
case 0x0c03612cu: goto P_0c03612c;
case 0x0c03612eu: goto P_0c03612e;
case 0x0c036130u: goto P_0c036130;
default: return vf3_matrix_family(target,s,ram);
}
P_0c034800: /* original 8441, guest PC 0x0c034800 */
if(!s->budget--) { s->failed_pc=0x0c034800u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+1,1);
goto P_0c034802;
P_0c034802: /* original 6240, guest PC 0x0c034802 */
if(!s->budget--) { s->failed_pc=0x0c034802u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[4],1);
r[2]=tmp;
goto P_0c034804;
P_0c034804: /* original 600c, guest PC 0x0c034804 */
if(!s->budget--) { s->failed_pc=0x0c034804u; return 0; }
r[0]=r[0]&255u;
goto P_0c034806;
P_0c034806: /* original 4018, guest PC 0x0c034806 */
if(!s->budget--) { s->failed_pc=0x0c034806u; return 0; }
r[0]<<=8;
goto P_0c034808;
P_0c034808: /* original 6303, guest PC 0x0c034808 */
if(!s->budget--) { s->failed_pc=0x0c034808u; return 0; }
r[3]=r[0];
goto P_0c03480a;
P_0c03480a: /* original 8442, guest PC 0x0c03480a */
if(!s->budget--) { s->failed_pc=0x0c03480au; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+2,1);
goto P_0c03480c;
P_0c03480c: /* original 622c, guest PC 0x0c03480c */
if(!s->budget--) { s->failed_pc=0x0c03480cu; return 0; }
r[2]=r[2]&255u;
goto P_0c03480e;
P_0c03480e: /* original 600c, guest PC 0x0c03480e */
if(!s->budget--) { s->failed_pc=0x0c03480eu; return 0; }
r[0]=r[0]&255u;
goto P_0c034810;
P_0c034810: /* original 4028, guest PC 0x0c034810 */
if(!s->budget--) { s->failed_pc=0x0c034810u; return 0; }
r[0]<<=16;
goto P_0c034812;
P_0c034812: /* original 230b, guest PC 0x0c034812 */
if(!s->budget--) { s->failed_pc=0x0c034812u; return 0; }
r[3]|=r[0];
goto P_0c034814;
P_0c034814: /* original 8443, guest PC 0x0c034814 */
if(!s->budget--) { s->failed_pc=0x0c034814u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+3,1);
goto P_0c034816;
P_0c034816: /* original 600c, guest PC 0x0c034816 */
if(!s->budget--) { s->failed_pc=0x0c034816u; return 0; }
r[0]=r[0]&255u;
goto P_0c034818;
P_0c034818: /* original 4028, guest PC 0x0c034818 */
if(!s->budget--) { s->failed_pc=0x0c034818u; return 0; }
r[0]<<=16;
goto P_0c03481a;
P_0c03481a: /* original 4018, guest PC 0x0c03481a */
if(!s->budget--) { s->failed_pc=0x0c03481au; return 0; }
r[0]<<=8;
goto P_0c03481c;
P_0c03481c: /* original 230b, guest PC 0x0c03481c */
if(!s->budget--) { s->failed_pc=0x0c03481cu; return 0; }
r[3]|=r[0];
goto P_0c03481e;
P_0c03481e: /* original 6433, guest PC 0x0c03481e */
if(!s->budget--) { s->failed_pc=0x0c03481eu; return 0; }
r[4]=r[3];
goto P_0c034820;
P_0c034820: /* original 242b, guest PC 0x0c034820 */
if(!s->budget--) { s->failed_pc=0x0c034820u; return 0; }
r[4]|=r[2];
goto P_0c034822;
P_0c034822: /* original 000b, guest PC 0x0c034822 */
if(!s->budget--) { s->failed_pc=0x0c034822u; return 0; }
target=r[16];
r[0]=r[4];
s->pc=target; return ram->oob==0;
P_0c034824: /* original 6043, guest PC 0x0c034824 */
if(!s->budget--) { s->failed_pc=0x0c034824u; return 0; }
r[0]=r[4];
if(!vf3_matrix_family(0x0c034826u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c034826u; return 0; } return 1;
P_0c035b1c: /* original 2fe6, guest PC 0x0c035b1c */
if(!s->budget--) { s->failed_pc=0x0c035b1cu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c035b1e;
P_0c035b1e: /* original d390, guest PC 0x0c035b1e */
if(!s->budget--) { s->failed_pc=0x0c035b1eu; return 0; }
r[3]=read(ram,0x0c035d60u,4);
goto P_0c035b20;
P_0c035b20: /* original 6e32, guest PC 0x0c035b20 */
if(!s->budget--) { s->failed_pc=0x0c035b20u; return 0; }
tmp=read(ram,r[3],4);
r[14]=tmp;
goto P_0c035b22;
P_0c035b22: /* original 2ee8, guest PC 0x0c035b22 */
if(!s->budget--) { s->failed_pc=0x0c035b22u; return 0; }
r[17]=(r[17]&~1u)|(((r[14]&r[14])==0)!=0);
goto P_0c035b24;
P_0c035b24: /* original 8902, guest PC 0x0c035b24 */
if(!s->budget--) { s->failed_pc=0x0c035b24u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c035b2c; }
goto P_0c035b26;
P_0c035b26: /* original 50e7, guest PC 0x0c035b26 */
if(!s->budget--) { s->failed_pc=0x0c035b26u; return 0; }
r[0]=read(ram,r[14]+28,4);
goto P_0c035b28;
P_0c035b28: /* original 402b, guest PC 0x0c035b28 */
if(!s->budget--) { s->failed_pc=0x0c035b28u; return 0; }
target=r[0];
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
P_0c035b2a: /* original 6ef6, guest PC 0x0c035b2a */
if(!s->budget--) { s->failed_pc=0x0c035b2au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c035b2c;
P_0c035b2c: /* original e000, guest PC 0x0c035b2c */
if(!s->budget--) { s->failed_pc=0x0c035b2cu; return 0; }
r[0]=0x00000000u;
goto P_0c035b2e;
P_0c035b2e: /* original 000b, guest PC 0x0c035b2e */
if(!s->budget--) { s->failed_pc=0x0c035b2eu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c035b30: /* original 6ef6, guest PC 0x0c035b30 */
if(!s->budget--) { s->failed_pc=0x0c035b30u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c035b32u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c035b32u; return 0; } return 1;
P_0c035e90: /* original d208, guest PC 0x0c035e90 */
if(!s->budget--) { s->failed_pc=0x0c035e90u; return 0; }
r[2]=read(ram,0x0c035eb4u,4);
goto P_0c035e92;
P_0c035e92: /* original 900e, guest PC 0x0c035e92 */
if(!s->budget--) { s->failed_pc=0x0c035e92u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c035eb2u,2);
goto P_0c035e94;
P_0c035e94: /* original 6322, guest PC 0x0c035e94 */
if(!s->budget--) { s->failed_pc=0x0c035e94u; return 0; }
tmp=read(ram,r[2],4);
r[3]=tmp;
goto P_0c035e96;
P_0c035e96: /* original 013e, guest PC 0x0c035e96 */
if(!s->budget--) { s->failed_pc=0x0c035e96u; return 0; }
r[1]=read(ram,r[3]+r[0],4);
goto P_0c035e98;
P_0c035e98: /* original 2118, guest PC 0x0c035e98 */
if(!s->budget--) { s->failed_pc=0x0c035e98u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[1])==0)!=0);
goto P_0c035e9a;
P_0c035e9a: /* original 8b01, guest PC 0x0c035e9a */
if(!s->budget--) { s->failed_pc=0x0c035e9au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c035ea0; }
goto P_0c035e9c;
P_0c035e9c: /* original a0ac, guest PC 0x0c035e9c */
if(!s->budget--) { s->failed_pc=0x0c035e9cu; return 0; }
goto P_0c035ff8;
P_0c035e9e: /* original 0009, guest PC 0x0c035e9e */
if(!s->budget--) { s->failed_pc=0x0c035e9eu; return 0; }
goto P_0c035ea0;
P_0c035ea0: /* original a01a, guest PC 0x0c035ea0 */
if(!s->budget--) { s->failed_pc=0x0c035ea0u; return 0; }
goto P_0c035ed8;
P_0c035ea2: /* original 0009, guest PC 0x0c035ea2 */
if(!s->budget--) { s->failed_pc=0x0c035ea2u; return 0; }
if(!vf3_matrix_family(0x0c035ea4u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c035ea4u; return 0; } return 1;
P_0c035ed8: /* original 2fe6, guest PC 0x0c035ed8 */
if(!s->budget--) { s->failed_pc=0x0c035ed8u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c035eda;
P_0c035eda: /* original 2fd6, guest PC 0x0c035eda */
if(!s->budget--) { s->failed_pc=0x0c035edau; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c035edc;
P_0c035edc: /* original 2fc6, guest PC 0x0c035edc */
if(!s->budget--) { s->failed_pc=0x0c035edcu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c035ede;
P_0c035ede: /* original 2fb6, guest PC 0x0c035ede */
if(!s->budget--) { s->failed_pc=0x0c035edeu; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c035ee0;
P_0c035ee0: /* original 4f22, guest PC 0x0c035ee0 */
if(!s->budget--) { s->failed_pc=0x0c035ee0u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c035ee2;
P_0c035ee2: /* original d13b, guest PC 0x0c035ee2 */
if(!s->budget--) { s->failed_pc=0x0c035ee2u; return 0; }
r[1]=read(ram,0x0c035fd0u,4);
goto P_0c035ee4;
P_0c035ee4: /* original 4f12, guest PC 0x0c035ee4 */
if(!s->budget--) { s->failed_pc=0x0c035ee4u; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c035ee6;
P_0c035ee6: /* original b351, guest PC 0x0c035ee6 */
if(!s->budget--) { s->failed_pc=0x0c035ee6u; return 0; }
target=code_base|0x0c03658cu; r[16]=code_base|0x0c035eeau;
tmp=r[1]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c035eeau) { target=s->pc; goto dispatch; }
goto P_0c035eea;
P_0c035ee8: /* original 2f16, guest PC 0x0c035ee8 */
if(!s->budget--) { s->failed_pc=0x0c035ee8u; return 0; }
tmp=r[1]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c035eea;
P_0c035eea: /* original dc3a, guest PC 0x0c035eea */
if(!s->budget--) { s->failed_pc=0x0c035eeau; return 0; }
r[12]=read(ram,0x0c035fd4u,4);
goto P_0c035eec;
P_0c035eec: /* original e22c, guest PC 0x0c035eec */
if(!s->budget--) { s->failed_pc=0x0c035eecu; return 0; }
r[2]=0x0000002cu;
goto P_0c035eee;
P_0c035eee: /* original 906c, guest PC 0x0c035eee */
if(!s->budget--) { s->failed_pc=0x0c035eeeu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c035fcau,2);
goto P_0c035ef0;
P_0c035ef0: /* original e678, guest PC 0x0c035ef0 */
if(!s->budget--) { s->failed_pc=0x0c035ef0u; return 0; }
r[6]=0x00000078u;
goto P_0c035ef2;
P_0c035ef2: /* original 6ec2, guest PC 0x0c035ef2 */
if(!s->budget--) { s->failed_pc=0x0c035ef2u; return 0; }
tmp=read(ram,r[12],4);
r[14]=tmp;
goto P_0c035ef4;
P_0c035ef4: /* original 7f04, guest PC 0x0c035ef4 */
if(!s->budget--) { s->failed_pc=0x0c035ef4u; return 0; }
r[15]+=0x00000004u;
goto P_0c035ef6;
P_0c035ef6: /* original 65c2, guest PC 0x0c035ef6 */
if(!s->budget--) { s->failed_pc=0x0c035ef6u; return 0; }
tmp=read(ram,r[12],4);
r[5]=tmp;
goto P_0c035ef8;
P_0c035ef8: /* original 0eee, guest PC 0x0c035ef8 */
if(!s->budget--) { s->failed_pc=0x0c035ef8u; return 0; }
r[14]=read(ram,r[14]+r[0],4);
goto P_0c035efa;
P_0c035efa: /* original d037, guest PC 0x0c035efa */
if(!s->budget--) { s->failed_pc=0x0c035efau; return 0; }
r[0]=read(ram,0x0c035fd8u,4);
goto P_0c035efc;
P_0c035efc: /* original 7528, guest PC 0x0c035efc */
if(!s->budget--) { s->failed_pc=0x0c035efcu; return 0; }
r[5]+=0x00000028u;
goto P_0c035efe;
P_0c035efe: /* original 4e08, guest PC 0x0c035efe */
if(!s->budget--) { s->failed_pc=0x0c035efeu; return 0; }
r[14]<<=2;
goto P_0c035f00;
P_0c035f00: /* original 9362, guest PC 0x0c035f00 */
if(!s->budget--) { s->failed_pc=0x0c035f00u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c035fc8u,2);
goto P_0c035f02;
P_0c035f02: /* original 0eee, guest PC 0x0c035f02 */
if(!s->budget--) { s->failed_pc=0x0c035f02u; return 0; }
r[14]=read(ram,r[14]+r[0],4);
goto P_0c035f04;
P_0c035f04: /* original 64c2, guest PC 0x0c035f04 */
if(!s->budget--) { s->failed_pc=0x0c035f04u; return 0; }
tmp=read(ram,r[12],4);
r[4]=tmp;
goto P_0c035f06;
P_0c035f06: /* original 2e2f, guest PC 0x0c035f06 */
if(!s->budget--) { s->failed_pc=0x0c035f06u; return 0; }
r[19]=(uint32_t)((int32_t)(int16_t)r[14]*(int32_t)(int16_t)r[2]);
goto P_0c035f08;
P_0c035f08: /* original 343c, guest PC 0x0c035f08 */
if(!s->budget--) { s->failed_pc=0x0c035f08u; return 0; }
r[4]+=r[3];
goto P_0c035f0a;
P_0c035f0a: /* original 021a, guest PC 0x0c035f0a */
if(!s->budget--) { s->failed_pc=0x0c035f0au; return 0; }
r[2]=r[19];
goto P_0c035f0c;
P_0c035f0c: /* original 2e6f, guest PC 0x0c035f0c */
if(!s->budget--) { s->failed_pc=0x0c035f0cu; return 0; }
r[19]=(uint32_t)((int32_t)(int16_t)r[14]*(int32_t)(int16_t)r[6]);
goto P_0c035f0e;
P_0c035f0e: /* original 622f, guest PC 0x0c035f0e */
if(!s->budget--) { s->failed_pc=0x0c035f0eu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)r[2];
goto P_0c035f10;
P_0c035f10: /* original 352c, guest PC 0x0c035f10 */
if(!s->budget--) { s->failed_pc=0x0c035f10u; return 0; }
r[5]+=r[2];
goto P_0c035f12;
P_0c035f12: /* original 061a, guest PC 0x0c035f12 */
if(!s->budget--) { s->failed_pc=0x0c035f12u; return 0; }
r[6]=r[19];
goto P_0c035f14;
P_0c035f14: /* original 8456, guest PC 0x0c035f14 */
if(!s->budget--) { s->failed_pc=0x0c035f14u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[5]+6,1);
goto P_0c035f16;
P_0c035f16: /* original 2008, guest PC 0x0c035f16 */
if(!s->budget--) { s->failed_pc=0x0c035f16u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c035f18;
P_0c035f18: /* original 666f, guest PC 0x0c035f18 */
if(!s->budget--) { s->failed_pc=0x0c035f18u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)r[6];
goto P_0c035f1a;
P_0c035f1a: /* original 8f45, guest PC 0x0c035f1a */
if(!s->budget--) { s->failed_pc=0x0c035f1au; return 0; }
cond=r[17]&1u;
r[6]+=r[4];
if(!cond) { goto P_0c035fa8; }
goto P_0c035f1e;
P_0c035f1c: /* original 364c, guest PC 0x0c035f1c */
if(!s->budget--) { s->failed_pc=0x0c035f1cu; return 0; }
r[6]+=r[4];
goto P_0c035f1e;
P_0c035f1e: /* original 8454, guest PC 0x0c035f1e */
if(!s->budget--) { s->failed_pc=0x0c035f1eu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[5]+4,1);
goto P_0c035f20;
P_0c035f20: /* original 64e3, guest PC 0x0c035f20 */
if(!s->budget--) { s->failed_pc=0x0c035f20u; return 0; }
r[4]=r[14];
goto P_0c035f22;
P_0c035f22: /* original dd2e, guest PC 0x0c035f22 */
if(!s->budget--) { s->failed_pc=0x0c035f22u; return 0; }
r[13]=read(ram,0x0c035fdcu,4);
goto P_0c035f24;
P_0c035f24: /* original 600c, guest PC 0x0c035f24 */
if(!s->budget--) { s->failed_pc=0x0c035f24u; return 0; }
r[0]=r[0]&255u;
goto P_0c035f26;
P_0c035f26: /* original 8800, guest PC 0x0c035f26 */
if(!s->budget--) { s->failed_pc=0x0c035f26u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000000u)!=0);
goto P_0c035f28;
P_0c035f28: /* original 8d3e, guest PC 0x0c035f28 */
if(!s->budget--) { s->failed_pc=0x0c035f28u; return 0; }
cond=r[17]&1u;
r[4]+=0x00000001u;
if(cond) { goto P_0c035fa8; }
goto P_0c035f2c;
P_0c035f2a: /* original 7401, guest PC 0x0c035f2a */
if(!s->budget--) { s->failed_pc=0x0c035f2au; return 0; }
r[4]+=0x00000001u;
goto P_0c035f2c;
P_0c035f2c: /* original 8801, guest PC 0x0c035f2c */
if(!s->budget--) { s->failed_pc=0x0c035f2cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c035f2e;
P_0c035f2e: /* original 8914, guest PC 0x0c035f2e */
if(!s->budget--) { s->failed_pc=0x0c035f2eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c035f5a; }
goto P_0c035f30;
P_0c035f30: /* original 8802, guest PC 0x0c035f30 */
if(!s->budget--) { s->failed_pc=0x0c035f30u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c035f32;
P_0c035f32: /* original 8919, guest PC 0x0c035f32 */
if(!s->budget--) { s->failed_pc=0x0c035f32u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c035f68; }
goto P_0c035f34;
P_0c035f34: /* original 8803, guest PC 0x0c035f34 */
if(!s->budget--) { s->failed_pc=0x0c035f34u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000003u)!=0);
goto P_0c035f36;
P_0c035f36: /* original 891e, guest PC 0x0c035f36 */
if(!s->budget--) { s->failed_pc=0x0c035f36u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c035f76; }
goto P_0c035f38;
P_0c035f38: /* original 8804, guest PC 0x0c035f38 */
if(!s->budget--) { s->failed_pc=0x0c035f38u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000004u)!=0);
goto P_0c035f3a;
P_0c035f3a: /* original 8923, guest PC 0x0c035f3a */
if(!s->budget--) { s->failed_pc=0x0c035f3au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c035f84; }
goto P_0c035f3c;
P_0c035f3c: /* original 8809, guest PC 0x0c035f3c */
if(!s->budget--) { s->failed_pc=0x0c035f3cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000009u)!=0);
goto P_0c035f3e;
P_0c035f3e: /* original 8927, guest PC 0x0c035f3e */
if(!s->budget--) { s->failed_pc=0x0c035f3eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c035f90; }
goto P_0c035f40;
P_0c035f40: /* original 880a, guest PC 0x0c035f40 */
if(!s->budget--) { s->failed_pc=0x0c035f40u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000au)!=0);
goto P_0c035f42;
P_0c035f42: /* original 8931, guest PC 0x0c035f42 */
if(!s->budget--) { s->failed_pc=0x0c035f42u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c035fa8; }
goto P_0c035f44;
P_0c035f44: /* original 880b, guest PC 0x0c035f44 */
if(!s->budget--) { s->failed_pc=0x0c035f44u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000bu)!=0);
goto P_0c035f46;
P_0c035f46: /* original 892f, guest PC 0x0c035f46 */
if(!s->budget--) { s->failed_pc=0x0c035f46u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c035fa8; }
goto P_0c035f48;
P_0c035f48: /* original 880c, guest PC 0x0c035f48 */
if(!s->budget--) { s->failed_pc=0x0c035f48u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000cu)!=0);
goto P_0c035f4a;
P_0c035f4a: /* original 892d, guest PC 0x0c035f4a */
if(!s->budget--) { s->failed_pc=0x0c035f4au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c035fa8; }
goto P_0c035f4c;
P_0c035f4c: /* original 880d, guest PC 0x0c035f4c */
if(!s->budget--) { s->failed_pc=0x0c035f4cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000du)!=0);
goto P_0c035f4e;
P_0c035f4e: /* original 892b, guest PC 0x0c035f4e */
if(!s->budget--) { s->failed_pc=0x0c035f4eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c035fa8; }
goto P_0c035f50;
P_0c035f50: /* original 913c, guest PC 0x0c035f50 */
if(!s->budget--) { s->failed_pc=0x0c035f50u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c035fccu,2);
goto P_0c035f52;
P_0c035f52: /* original 3010, guest PC 0x0c035f52 */
if(!s->budget--) { s->failed_pc=0x0c035f52u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==r[1])!=0);
goto P_0c035f54;
P_0c035f54: /* original 8928, guest PC 0x0c035f54 */
if(!s->budget--) { s->failed_pc=0x0c035f54u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c035fa8; }
goto P_0c035f56;
P_0c035f56: /* original a027, guest PC 0x0c035f56 */
if(!s->budget--) { s->failed_pc=0x0c035f56u; return 0; }
goto P_0c035fa8;
P_0c035f58: /* original 0009, guest PC 0x0c035f58 */
if(!s->budget--) { s->failed_pc=0x0c035f58u; return 0; }
goto P_0c035f5a;
P_0c035f5a: /* original 4d0b, guest PC 0x0c035f5a */
if(!s->budget--) { s->failed_pc=0x0c035f5au; return 0; }
target=r[13];
r[16]=code_base|0x0c035f5eu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c035f5eu) { target=s->pc; goto dispatch; }
goto P_0c035f5e;
P_0c035f5c: /* original 0009, guest PC 0x0c035f5c */
if(!s->budget--) { s->failed_pc=0x0c035f5cu; return 0; }
goto P_0c035f5e;
P_0c035f5e: /* original d320, guest PC 0x0c035f5e */
if(!s->budget--) { s->failed_pc=0x0c035f5eu; return 0; }
r[3]=read(ram,0x0c035fe0u,4);
goto P_0c035f60;
P_0c035f60: /* original 430b, guest PC 0x0c035f60 */
if(!s->budget--) { s->failed_pc=0x0c035f60u; return 0; }
target=r[3];
r[16]=code_base|0x0c035f64u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c035f64u) { target=s->pc; goto dispatch; }
goto P_0c035f64;
P_0c035f62: /* original 64e3, guest PC 0x0c035f62 */
if(!s->budget--) { s->failed_pc=0x0c035f62u; return 0; }
r[4]=r[14];
goto P_0c035f64;
P_0c035f64: /* original a020, guest PC 0x0c035f64 */
if(!s->budget--) { s->failed_pc=0x0c035f64u; return 0; }
goto P_0c035fa8;
P_0c035f66: /* original 0009, guest PC 0x0c035f66 */
if(!s->budget--) { s->failed_pc=0x0c035f66u; return 0; }
goto P_0c035f68;
P_0c035f68: /* original 4d0b, guest PC 0x0c035f68 */
if(!s->budget--) { s->failed_pc=0x0c035f68u; return 0; }
target=r[13];
r[16]=code_base|0x0c035f6cu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c035f6cu) { target=s->pc; goto dispatch; }
goto P_0c035f6c;
P_0c035f6a: /* original 0009, guest PC 0x0c035f6a */
if(!s->budget--) { s->failed_pc=0x0c035f6au; return 0; }
goto P_0c035f6c;
P_0c035f6c: /* original d31d, guest PC 0x0c035f6c */
if(!s->budget--) { s->failed_pc=0x0c035f6cu; return 0; }
r[3]=read(ram,0x0c035fe4u,4);
goto P_0c035f6e;
P_0c035f6e: /* original 430b, guest PC 0x0c035f6e */
if(!s->budget--) { s->failed_pc=0x0c035f6eu; return 0; }
target=r[3];
r[16]=code_base|0x0c035f72u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c035f72u) { target=s->pc; goto dispatch; }
goto P_0c035f72;
P_0c035f70: /* original 64e3, guest PC 0x0c035f70 */
if(!s->budget--) { s->failed_pc=0x0c035f70u; return 0; }
r[4]=r[14];
goto P_0c035f72;
P_0c035f72: /* original a019, guest PC 0x0c035f72 */
if(!s->budget--) { s->failed_pc=0x0c035f72u; return 0; }
goto P_0c035fa8;
P_0c035f74: /* original 0009, guest PC 0x0c035f74 */
if(!s->budget--) { s->failed_pc=0x0c035f74u; return 0; }
goto P_0c035f76;
P_0c035f76: /* original 4d0b, guest PC 0x0c035f76 */
if(!s->budget--) { s->failed_pc=0x0c035f76u; return 0; }
target=r[13];
r[16]=code_base|0x0c035f7au;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c035f7au) { target=s->pc; goto dispatch; }
goto P_0c035f7a;
P_0c035f78: /* original 0009, guest PC 0x0c035f78 */
if(!s->budget--) { s->failed_pc=0x0c035f78u; return 0; }
goto P_0c035f7a;
P_0c035f7a: /* original d31b, guest PC 0x0c035f7a */
if(!s->budget--) { s->failed_pc=0x0c035f7au; return 0; }
r[3]=read(ram,0x0c035fe8u,4);
goto P_0c035f7c;
P_0c035f7c: /* original 430b, guest PC 0x0c035f7c */
if(!s->budget--) { s->failed_pc=0x0c035f7cu; return 0; }
target=r[3];
r[16]=code_base|0x0c035f80u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c035f80u) { target=s->pc; goto dispatch; }
goto P_0c035f80;
P_0c035f7e: /* original 64e3, guest PC 0x0c035f7e */
if(!s->budget--) { s->failed_pc=0x0c035f7eu; return 0; }
r[4]=r[14];
goto P_0c035f80;
P_0c035f80: /* original a012, guest PC 0x0c035f80 */
if(!s->budget--) { s->failed_pc=0x0c035f80u; return 0; }
goto P_0c035fa8;
P_0c035f82: /* original 0009, guest PC 0x0c035f82 */
if(!s->budget--) { s->failed_pc=0x0c035f82u; return 0; }
goto P_0c035f84;
P_0c035f84: /* original 4d0b, guest PC 0x0c035f84 */
if(!s->budget--) { s->failed_pc=0x0c035f84u; return 0; }
target=r[13];
r[16]=code_base|0x0c035f88u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c035f88u) { target=s->pc; goto dispatch; }
goto P_0c035f88;
P_0c035f86: /* original 0009, guest PC 0x0c035f86 */
if(!s->budget--) { s->failed_pc=0x0c035f86u; return 0; }
goto P_0c035f88;
P_0c035f88: /* original 4d0b, guest PC 0x0c035f88 */
if(!s->budget--) { s->failed_pc=0x0c035f88u; return 0; }
target=r[13];
r[16]=code_base|0x0c035f8cu;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c035f8cu) { target=s->pc; goto dispatch; }
goto P_0c035f8c;
P_0c035f8a: /* original 64e3, guest PC 0x0c035f8a */
if(!s->budget--) { s->failed_pc=0x0c035f8au; return 0; }
r[4]=r[14];
goto P_0c035f8c;
P_0c035f8c: /* original a00c, guest PC 0x0c035f8c */
if(!s->budget--) { s->failed_pc=0x0c035f8cu; return 0; }
goto P_0c035fa8;
P_0c035f8e: /* original 0009, guest PC 0x0c035f8e */
if(!s->budget--) { s->failed_pc=0x0c035f8eu; return 0; }
goto P_0c035f90;
P_0c035f90: /* original 6b62, guest PC 0x0c035f90 */
if(!s->budget--) { s->failed_pc=0x0c035f90u; return 0; }
tmp=read(ram,r[6],4);
r[11]=tmp;
goto P_0c035f92;
P_0c035f92: /* original e501, guest PC 0x0c035f92 */
if(!s->budget--) { s->failed_pc=0x0c035f92u; return 0; }
r[5]=0x00000001u;
goto P_0c035f94;
P_0c035f94: /* original 62b3, guest PC 0x0c035f94 */
if(!s->budget--) { s->failed_pc=0x0c035f94u; return 0; }
r[2]=r[11];
goto P_0c035f96;
P_0c035f96: /* original 2258, guest PC 0x0c035f96 */
if(!s->budget--) { s->failed_pc=0x0c035f96u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[5])==0)!=0);
goto P_0c035f98;
P_0c035f98: /* original 8900, guest PC 0x0c035f98 */
if(!s->budget--) { s->failed_pc=0x0c035f98u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c035f9c; }
goto P_0c035f9a;
P_0c035f9a: /* original 6b53, guest PC 0x0c035f9a */
if(!s->budget--) { s->failed_pc=0x0c035f9au; return 0; }
r[11]=r[5];
goto P_0c035f9c;
P_0c035f9c: /* original 4d0b, guest PC 0x0c035f9c */
if(!s->budget--) { s->failed_pc=0x0c035f9cu; return 0; }
target=r[13];
r[16]=code_base|0x0c035fa0u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c035fa0u) { target=s->pc; goto dispatch; }
goto P_0c035fa0;
P_0c035f9e: /* original 0009, guest PC 0x0c035f9e */
if(!s->budget--) { s->failed_pc=0x0c035f9eu; return 0; }
goto P_0c035fa0;
P_0c035fa0: /* original d212, guest PC 0x0c035fa0 */
if(!s->budget--) { s->failed_pc=0x0c035fa0u; return 0; }
r[2]=read(ram,0x0c035fecu,4);
goto P_0c035fa2;
P_0c035fa2: /* original 65b3, guest PC 0x0c035fa2 */
if(!s->budget--) { s->failed_pc=0x0c035fa2u; return 0; }
r[5]=r[11];
goto P_0c035fa4;
P_0c035fa4: /* original 420b, guest PC 0x0c035fa4 */
if(!s->budget--) { s->failed_pc=0x0c035fa4u; return 0; }
target=r[2];
r[16]=code_base|0x0c035fa8u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c035fa8u) { target=s->pc; goto dispatch; }
goto P_0c035fa8;
P_0c035fa6: /* original 64e3, guest PC 0x0c035fa6 */
if(!s->budget--) { s->failed_pc=0x0c035fa6u; return 0; }
r[4]=r[14];
goto P_0c035fa8;
P_0c035fa8: /* original d311, guest PC 0x0c035fa8 */
if(!s->budget--) { s->failed_pc=0x0c035fa8u; return 0; }
r[3]=read(ram,0x0c035ff0u,4);
goto P_0c035faa;
P_0c035faa: /* original 900e, guest PC 0x0c035faa */
if(!s->budget--) { s->failed_pc=0x0c035faau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c035fcau,2);
goto P_0c035fac;
P_0c035fac: /* original 64c2, guest PC 0x0c035fac */
if(!s->budget--) { s->failed_pc=0x0c035facu; return 0; }
tmp=read(ram,r[12],4);
r[4]=tmp;
goto P_0c035fae;
P_0c035fae: /* original 430b, guest PC 0x0c035fae */
if(!s->budget--) { s->failed_pc=0x0c035faeu; return 0; }
target=r[3];
r[16]=code_base|0x0c035fb2u;
r[4]=read(ram,r[4]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c035fb2u) { target=s->pc; goto dispatch; }
goto P_0c035fb2;
P_0c035fb0: /* original 044e, guest PC 0x0c035fb0 */
if(!s->budget--) { s->failed_pc=0x0c035fb0u; return 0; }
r[4]=read(ram,r[4]+r[0],4);
goto P_0c035fb2;
P_0c035fb2: /* original d210, guest PC 0x0c035fb2 */
if(!s->budget--) { s->failed_pc=0x0c035fb2u; return 0; }
r[2]=read(ram,0x0c035ff4u,4);
goto P_0c035fb4;
P_0c035fb4: /* original 420b, guest PC 0x0c035fb4 */
if(!s->budget--) { s->failed_pc=0x0c035fb4u; return 0; }
target=r[2];
r[16]=code_base|0x0c035fb8u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c035fb8u) { target=s->pc; goto dispatch; }
goto P_0c035fb8;
P_0c035fb6: /* original 0009, guest PC 0x0c035fb6 */
if(!s->budget--) { s->failed_pc=0x0c035fb6u; return 0; }
goto P_0c035fb8;
P_0c035fb8: /* original 4f16, guest PC 0x0c035fb8 */
if(!s->budget--) { s->failed_pc=0x0c035fb8u; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c035fba;
P_0c035fba: /* original e000, guest PC 0x0c035fba */
if(!s->budget--) { s->failed_pc=0x0c035fbau; return 0; }
r[0]=0x00000000u;
goto P_0c035fbc;
P_0c035fbc: /* original 4f26, guest PC 0x0c035fbc */
if(!s->budget--) { s->failed_pc=0x0c035fbcu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c035fbe;
P_0c035fbe: /* original 6bf6, guest PC 0x0c035fbe */
if(!s->budget--) { s->failed_pc=0x0c035fbeu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c035fc0;
P_0c035fc0: /* original 6cf6, guest PC 0x0c035fc0 */
if(!s->budget--) { s->failed_pc=0x0c035fc0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c035fc2;
P_0c035fc2: /* original 6df6, guest PC 0x0c035fc2 */
if(!s->budget--) { s->failed_pc=0x0c035fc2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c035fc4;
P_0c035fc4: /* original 000b, guest PC 0x0c035fc4 */
if(!s->budget--) { s->failed_pc=0x0c035fc4u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c035fc6: /* original 6ef6, guest PC 0x0c035fc6 */
if(!s->budget--) { s->failed_pc=0x0c035fc6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c035fc8u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c035fc8u; return 0; } return 1;
P_0c035ff8: /* original 2fe6, guest PC 0x0c035ff8 */
if(!s->budget--) { s->failed_pc=0x0c035ff8u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c035ffa;
P_0c035ffa: /* original 2fd6, guest PC 0x0c035ffa */
if(!s->budget--) { s->failed_pc=0x0c035ffau; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c035ffc;
P_0c035ffc: /* original 2fc6, guest PC 0x0c035ffc */
if(!s->budget--) { s->failed_pc=0x0c035ffcu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c035ffe;
P_0c035ffe: /* original 2fb6, guest PC 0x0c035ffe */
if(!s->budget--) { s->failed_pc=0x0c035ffeu; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c036000;
P_0c036000: /* original 2fa6, guest PC 0x0c036000 */
if(!s->budget--) { s->failed_pc=0x0c036000u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c036002;
P_0c036002: /* original 2f96, guest PC 0x0c036002 */
if(!s->budget--) { s->failed_pc=0x0c036002u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c036004;
P_0c036004: /* original 2f86, guest PC 0x0c036004 */
if(!s->budget--) { s->failed_pc=0x0c036004u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c036006;
P_0c036006: /* original 4f22, guest PC 0x0c036006 */
if(!s->budget--) { s->failed_pc=0x0c036006u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c036008;
P_0c036008: /* original d332, guest PC 0x0c036008 */
if(!s->budget--) { s->failed_pc=0x0c036008u; return 0; }
r[3]=read(ram,0x0c0360d4u,4);
goto P_0c03600a;
P_0c03600a: /* original 7ffc, guest PC 0x0c03600a */
if(!s->budget--) { s->failed_pc=0x0c03600au; return 0; }
r[15]+=0xfffffffcu;
goto P_0c03600c;
P_0c03600c: /* original b2be, guest PC 0x0c03600c */
if(!s->budget--) { s->failed_pc=0x0c03600cu; return 0; }
target=code_base|0x0c03658cu; r[16]=code_base|0x0c036010u;
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c036010u) { target=s->pc; goto dispatch; }
goto P_0c036010;
P_0c03600e: /* original 2f36, guest PC 0x0c03600e */
if(!s->budget--) { s->failed_pc=0x0c03600eu; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c036010;
P_0c036010: /* original dc31, guest PC 0x0c036010 */
if(!s->budget--) { s->failed_pc=0x0c036010u; return 0; }
r[12]=read(ram,0x0c0360d8u,4);
goto P_0c036012;
P_0c036012: /* original 7f04, guest PC 0x0c036012 */
if(!s->budget--) { s->failed_pc=0x0c036012u; return 0; }
r[15]+=0x00000004u;
goto P_0c036014;
P_0c036014: /* original 6bc2, guest PC 0x0c036014 */
if(!s->budget--) { s->failed_pc=0x0c036014u; return 0; }
tmp=read(ram,r[12],4);
r[11]=tmp;
goto P_0c036016;
P_0c036016: /* original 2fb2, guest PC 0x0c036016 */
if(!s->budget--) { s->failed_pc=0x0c036016u; return 0; }
write(ram,r[15],r[11],4);
goto P_0c036018;
P_0c036018: /* original 7b28, guest PC 0x0c036018 */
if(!s->budget--) { s->failed_pc=0x0c036018u; return 0; }
r[11]+=0x00000028u;
goto P_0c03601a;
P_0c03601a: /* original 9057, guest PC 0x0c03601a */
if(!s->budget--) { s->failed_pc=0x0c03601au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0360ccu,2);
goto P_0c03601c;
P_0c03601c: /* original 62c2, guest PC 0x0c03601c */
if(!s->budget--) { s->failed_pc=0x0c03601cu; return 0; }
tmp=read(ram,r[12],4);
r[2]=tmp;
goto P_0c03601e;
P_0c03601e: /* original 9354, guest PC 0x0c03601e */
if(!s->budget--) { s->failed_pc=0x0c03601eu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0360cau,2);
goto P_0c036020;
P_0c036020: /* original 012e, guest PC 0x0c036020 */
if(!s->budget--) { s->failed_pc=0x0c036020u; return 0; }
r[1]=read(ram,r[2]+r[0],4);
goto P_0c036022;
P_0c036022: /* original 6ac2, guest PC 0x0c036022 */
if(!s->budget--) { s->failed_pc=0x0c036022u; return 0; }
tmp=read(ram,r[12],4);
r[10]=tmp;
goto P_0c036024;
P_0c036024: /* original 4115, guest PC 0x0c036024 */
if(!s->budget--) { s->failed_pc=0x0c036024u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[1]>0)!=0);
goto P_0c036026;
P_0c036026: /* original 8f0d, guest PC 0x0c036026 */
if(!s->budget--) { s->failed_pc=0x0c036026u; return 0; }
cond=r[17]&1u;
r[10]+=r[3];
if(!cond) { goto P_0c036044; }
goto P_0c03602a;
P_0c036028: /* original 3a3c, guest PC 0x0c036028 */
if(!s->budget--) { s->failed_pc=0x0c036028u; return 0; }
r[10]+=r[3];
goto P_0c03602a;
P_0c03602a: /* original 904f, guest PC 0x0c03602a */
if(!s->budget--) { s->failed_pc=0x0c03602au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0360ccu,2);
goto P_0c03602c;
P_0c03602c: /* original 62f2, guest PC 0x0c03602c */
if(!s->budget--) { s->failed_pc=0x0c03602cu; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c03602e;
P_0c03602e: /* original 012e, guest PC 0x0c03602e */
if(!s->budget--) { s->failed_pc=0x0c03602eu; return 0; }
r[1]=read(ram,r[2]+r[0],4);
goto P_0c036030;
P_0c036030: /* original 2f16, guest PC 0x0c036030 */
if(!s->budget--) { s->failed_pc=0x0c036030u; return 0; }
tmp=r[1]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c036032;
P_0c036032: /* original d22a, guest PC 0x0c036032 */
if(!s->budget--) { s->failed_pc=0x0c036032u; return 0; }
r[2]=read(ram,0x0c0360dcu,4);
goto P_0c036034;
P_0c036034: /* original b2aa, guest PC 0x0c036034 */
if(!s->budget--) { s->failed_pc=0x0c036034u; return 0; }
target=code_base|0x0c03658cu; r[16]=code_base|0x0c036038u;
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c036038u) { target=s->pc; goto dispatch; }
goto P_0c036038;
P_0c036036: /* original 2f26, guest PC 0x0c036036 */
if(!s->budget--) { s->failed_pc=0x0c036036u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c036038;
P_0c036038: /* original 9048, guest PC 0x0c036038 */
if(!s->budget--) { s->failed_pc=0x0c036038u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0360ccu,2);
goto P_0c03603a;
P_0c03603a: /* original 7f08, guest PC 0x0c03603a */
if(!s->budget--) { s->failed_pc=0x0c03603au; return 0; }
r[15]+=0x00000008u;
goto P_0c03603c;
P_0c03603c: /* original d328, guest PC 0x0c03603c */
if(!s->budget--) { s->failed_pc=0x0c03603cu; return 0; }
r[3]=read(ram,0x0c0360e0u,4);
goto P_0c03603e;
P_0c03603e: /* original 64c2, guest PC 0x0c03603e */
if(!s->budget--) { s->failed_pc=0x0c03603eu; return 0; }
tmp=read(ram,r[12],4);
r[4]=tmp;
goto P_0c036040;
P_0c036040: /* original 430b, guest PC 0x0c036040 */
if(!s->budget--) { s->failed_pc=0x0c036040u; return 0; }
target=r[3];
r[16]=code_base|0x0c036044u;
r[4]=read(ram,r[4]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c036044u) { target=s->pc; goto dispatch; }
goto P_0c036044;
P_0c036042: /* original 044e, guest PC 0x0c036042 */
if(!s->budget--) { s->failed_pc=0x0c036042u; return 0; }
r[4]=read(ram,r[4]+r[0],4);
goto P_0c036044;
P_0c036044: /* original d827, guest PC 0x0c036044 */
if(!s->budget--) { s->failed_pc=0x0c036044u; return 0; }
r[8]=read(ram,0x0c0360e4u,4);
goto P_0c036046;
P_0c036046: /* original ed01, guest PC 0x0c036046 */
if(!s->budget--) { s->failed_pc=0x0c036046u; return 0; }
r[13]=0x00000001u;
goto P_0c036048;
P_0c036048: /* original e907, guest PC 0x0c036048 */
if(!s->budget--) { s->failed_pc=0x0c036048u; return 0; }
r[9]=0x00000007u;
goto P_0c03604a;
P_0c03604a: /* original a062, guest PC 0x0c03604a */
if(!s->budget--) { s->failed_pc=0x0c03604au; return 0; }
r[14]=0x00000000u;
goto P_0c036112;
P_0c03604c: /* original ee00, guest PC 0x0c03604c */
if(!s->budget--) { s->failed_pc=0x0c03604cu; return 0; }
r[14]=0x00000000u;
goto P_0c03604e;
P_0c03604e: /* original 933e, guest PC 0x0c03604e */
if(!s->budget--) { s->failed_pc=0x0c03604eu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0360ceu,2);
goto P_0c036050;
P_0c036050: /* original 60c2, guest PC 0x0c036050 */
if(!s->budget--) { s->failed_pc=0x0c036050u; return 0; }
tmp=read(ram,r[12],4);
r[0]=tmp;
goto P_0c036052;
P_0c036052: /* original 330c, guest PC 0x0c036052 */
if(!s->budget--) { s->failed_pc=0x0c036052u; return 0; }
r[3]+=r[0];
goto P_0c036054;
P_0c036054: /* original 33ec, guest PC 0x0c036054 */
if(!s->budget--) { s->failed_pc=0x0c036054u; return 0; }
r[3]+=r[14];
goto P_0c036056;
P_0c036056: /* original 6230, guest PC 0x0c036056 */
if(!s->budget--) { s->failed_pc=0x0c036056u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[3],1);
r[2]=tmp;
goto P_0c036058;
P_0c036058: /* original 2228, guest PC 0x0c036058 */
if(!s->budget--) { s->failed_pc=0x0c036058u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c03605a;
P_0c03605a: /* original 8957, guest PC 0x0c03605a */
if(!s->budget--) { s->failed_pc=0x0c03605au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c03610c; }
goto P_0c03605c;
P_0c03605c: /* original 84b6, guest PC 0x0c03605c */
if(!s->budget--) { s->failed_pc=0x0c03605cu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[11]+6,1);
goto P_0c03605e;
P_0c03605e: /* original 2008, guest PC 0x0c03605e */
if(!s->budget--) { s->failed_pc=0x0c03605eu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c036060;
P_0c036060: /* original 8b54, guest PC 0x0c036060 */
if(!s->budget--) { s->failed_pc=0x0c036060u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c03610c; }
goto P_0c036062;
P_0c036062: /* original 2fe6, guest PC 0x0c036062 */
if(!s->budget--) { s->failed_pc=0x0c036062u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c036064;
P_0c036064: /* original d220, guest PC 0x0c036064 */
if(!s->budget--) { s->failed_pc=0x0c036064u; return 0; }
r[2]=read(ram,0x0c0360e8u,4);
goto P_0c036066;
P_0c036066: /* original b291, guest PC 0x0c036066 */
if(!s->budget--) { s->failed_pc=0x0c036066u; return 0; }
target=code_base|0x0c03658cu; r[16]=code_base|0x0c03606au;
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c03606au) { target=s->pc; goto dispatch; }
goto P_0c03606a;
P_0c036068: /* original 2f26, guest PC 0x0c036068 */
if(!s->budget--) { s->failed_pc=0x0c036068u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03606a;
P_0c03606a: /* original 84b4, guest PC 0x0c03606a */
if(!s->budget--) { s->failed_pc=0x0c03606au; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[11]+4,1);
goto P_0c03606c;
P_0c03606c: /* original 600c, guest PC 0x0c03606c */
if(!s->budget--) { s->failed_pc=0x0c03606cu; return 0; }
r[0]=r[0]&255u;
goto P_0c03606e;
P_0c03606e: /* original 8800, guest PC 0x0c03606e */
if(!s->budget--) { s->failed_pc=0x0c03606eu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000000u)!=0);
goto P_0c036070;
P_0c036070: /* original 8d4c, guest PC 0x0c036070 */
if(!s->budget--) { s->failed_pc=0x0c036070u; return 0; }
cond=r[17]&1u;
r[15]+=0x00000008u;
if(cond) { goto P_0c03610c; }
goto P_0c036074;
P_0c036072: /* original 7f08, guest PC 0x0c036072 */
if(!s->budget--) { s->failed_pc=0x0c036072u; return 0; }
r[15]+=0x00000008u;
goto P_0c036074;
P_0c036074: /* original 8801, guest PC 0x0c036074 */
if(!s->budget--) { s->failed_pc=0x0c036074u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c036076;
P_0c036076: /* original 8914, guest PC 0x0c036076 */
if(!s->budget--) { s->failed_pc=0x0c036076u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0360a2; }
goto P_0c036078;
P_0c036078: /* original 8802, guest PC 0x0c036078 */
if(!s->budget--) { s->failed_pc=0x0c036078u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c03607a;
P_0c03607a: /* original 8917, guest PC 0x0c03607a */
if(!s->budget--) { s->failed_pc=0x0c03607au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0360ac; }
goto P_0c03607c;
P_0c03607c: /* original 8803, guest PC 0x0c03607c */
if(!s->budget--) { s->failed_pc=0x0c03607cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000003u)!=0);
goto P_0c03607e;
P_0c03607e: /* original 891a, guest PC 0x0c03607e */
if(!s->budget--) { s->failed_pc=0x0c03607eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0360b6; }
goto P_0c036080;
P_0c036080: /* original 8804, guest PC 0x0c036080 */
if(!s->budget--) { s->failed_pc=0x0c036080u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000004u)!=0);
goto P_0c036082;
P_0c036082: /* original 891d, guest PC 0x0c036082 */
if(!s->budget--) { s->failed_pc=0x0c036082u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0360c0; }
goto P_0c036084;
P_0c036084: /* original 8809, guest PC 0x0c036084 */
if(!s->budget--) { s->failed_pc=0x0c036084u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000009u)!=0);
goto P_0c036086;
P_0c036086: /* original 8939, guest PC 0x0c036086 */
if(!s->budget--) { s->failed_pc=0x0c036086u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0360fc; }
goto P_0c036088;
P_0c036088: /* original 880a, guest PC 0x0c036088 */
if(!s->budget--) { s->failed_pc=0x0c036088u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000au)!=0);
goto P_0c03608a;
P_0c03608a: /* original 893f, guest PC 0x0c03608a */
if(!s->budget--) { s->failed_pc=0x0c03608au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c03610c; }
goto P_0c03608c;
P_0c03608c: /* original 880b, guest PC 0x0c03608c */
if(!s->budget--) { s->failed_pc=0x0c03608cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000bu)!=0);
goto P_0c03608e;
P_0c03608e: /* original 893d, guest PC 0x0c03608e */
if(!s->budget--) { s->failed_pc=0x0c03608eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c03610c; }
goto P_0c036090;
P_0c036090: /* original 880c, guest PC 0x0c036090 */
if(!s->budget--) { s->failed_pc=0x0c036090u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000cu)!=0);
goto P_0c036092;
P_0c036092: /* original 893b, guest PC 0x0c036092 */
if(!s->budget--) { s->failed_pc=0x0c036092u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c03610c; }
goto P_0c036094;
P_0c036094: /* original 880d, guest PC 0x0c036094 */
if(!s->budget--) { s->failed_pc=0x0c036094u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000du)!=0);
goto P_0c036096;
P_0c036096: /* original 8939, guest PC 0x0c036096 */
if(!s->budget--) { s->failed_pc=0x0c036096u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c03610c; }
goto P_0c036098;
P_0c036098: /* original 911a, guest PC 0x0c036098 */
if(!s->budget--) { s->failed_pc=0x0c036098u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0360d0u,2);
goto P_0c03609a;
P_0c03609a: /* original 3010, guest PC 0x0c03609a */
if(!s->budget--) { s->failed_pc=0x0c03609au; return 0; }
r[17]=(r[17]&~1u)|((r[0]==r[1])!=0);
goto P_0c03609c;
P_0c03609c: /* original 8936, guest PC 0x0c03609c */
if(!s->budget--) { s->failed_pc=0x0c03609cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c03610c; }
goto P_0c03609e;
P_0c03609e: /* original a035, guest PC 0x0c03609e */
if(!s->budget--) { s->failed_pc=0x0c03609eu; return 0; }
goto P_0c03610c;
P_0c0360a0: /* original 0009, guest PC 0x0c0360a0 */
if(!s->budget--) { s->failed_pc=0x0c0360a0u; return 0; }
goto P_0c0360a2;
P_0c0360a2: /* original d312, guest PC 0x0c0360a2 */
if(!s->budget--) { s->failed_pc=0x0c0360a2u; return 0; }
r[3]=read(ram,0x0c0360ecu,4);
goto P_0c0360a4;
P_0c0360a4: /* original 430b, guest PC 0x0c0360a4 */
if(!s->budget--) { s->failed_pc=0x0c0360a4u; return 0; }
target=r[3];
r[16]=code_base|0x0c0360a8u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0360a8u) { target=s->pc; goto dispatch; }
goto P_0c0360a8;
P_0c0360a6: /* original 64e3, guest PC 0x0c0360a6 */
if(!s->budget--) { s->failed_pc=0x0c0360a6u; return 0; }
r[4]=r[14];
goto P_0c0360a8;
P_0c0360a8: /* original a030, guest PC 0x0c0360a8 */
if(!s->budget--) { s->failed_pc=0x0c0360a8u; return 0; }
goto P_0c03610c;
P_0c0360aa: /* original 0009, guest PC 0x0c0360aa */
if(!s->budget--) { s->failed_pc=0x0c0360aau; return 0; }
goto P_0c0360ac;
P_0c0360ac: /* original d310, guest PC 0x0c0360ac */
if(!s->budget--) { s->failed_pc=0x0c0360acu; return 0; }
r[3]=read(ram,0x0c0360f0u,4);
goto P_0c0360ae;
P_0c0360ae: /* original 430b, guest PC 0x0c0360ae */
if(!s->budget--) { s->failed_pc=0x0c0360aeu; return 0; }
target=r[3];
r[16]=code_base|0x0c0360b2u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0360b2u) { target=s->pc; goto dispatch; }
goto P_0c0360b2;
P_0c0360b0: /* original 64e3, guest PC 0x0c0360b0 */
if(!s->budget--) { s->failed_pc=0x0c0360b0u; return 0; }
r[4]=r[14];
goto P_0c0360b2;
P_0c0360b2: /* original a02b, guest PC 0x0c0360b2 */
if(!s->budget--) { s->failed_pc=0x0c0360b2u; return 0; }
goto P_0c03610c;
P_0c0360b4: /* original 0009, guest PC 0x0c0360b4 */
if(!s->budget--) { s->failed_pc=0x0c0360b4u; return 0; }
goto P_0c0360b6;
P_0c0360b6: /* original d30f, guest PC 0x0c0360b6 */
if(!s->budget--) { s->failed_pc=0x0c0360b6u; return 0; }
r[3]=read(ram,0x0c0360f4u,4);
goto P_0c0360b8;
P_0c0360b8: /* original 430b, guest PC 0x0c0360b8 */
if(!s->budget--) { s->failed_pc=0x0c0360b8u; return 0; }
target=r[3];
r[16]=code_base|0x0c0360bcu;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0360bcu) { target=s->pc; goto dispatch; }
goto P_0c0360bc;
P_0c0360ba: /* original 64e3, guest PC 0x0c0360ba */
if(!s->budget--) { s->failed_pc=0x0c0360bau; return 0; }
r[4]=r[14];
goto P_0c0360bc;
P_0c0360bc: /* original a026, guest PC 0x0c0360bc */
if(!s->budget--) { s->failed_pc=0x0c0360bcu; return 0; }
goto P_0c03610c;
P_0c0360be: /* original 0009, guest PC 0x0c0360be */
if(!s->budget--) { s->failed_pc=0x0c0360beu; return 0; }
goto P_0c0360c0;
P_0c0360c0: /* original d30d, guest PC 0x0c0360c0 */
if(!s->budget--) { s->failed_pc=0x0c0360c0u; return 0; }
r[3]=read(ram,0x0c0360f8u,4);
goto P_0c0360c2;
P_0c0360c2: /* original 430b, guest PC 0x0c0360c2 */
if(!s->budget--) { s->failed_pc=0x0c0360c2u; return 0; }
target=r[3];
r[16]=code_base|0x0c0360c6u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0360c6u) { target=s->pc; goto dispatch; }
goto P_0c0360c6;
P_0c0360c4: /* original 64e3, guest PC 0x0c0360c4 */
if(!s->budget--) { s->failed_pc=0x0c0360c4u; return 0; }
r[4]=r[14];
goto P_0c0360c6;
P_0c0360c6: /* original a021, guest PC 0x0c0360c6 */
if(!s->budget--) { s->failed_pc=0x0c0360c6u; return 0; }
goto P_0c03610c;
P_0c0360c8: /* original 0009, guest PC 0x0c0360c8 */
if(!s->budget--) { s->failed_pc=0x0c0360c8u; return 0; }
if(!vf3_matrix_family(0x0c0360cau,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0360cau; return 0; } return 1;
P_0c0360fc: /* original 65a2, guest PC 0x0c0360fc */
if(!s->budget--) { s->failed_pc=0x0c0360fcu; return 0; }
tmp=read(ram,r[10],4);
r[5]=tmp;
goto P_0c0360fe;
P_0c0360fe: /* original 6353, guest PC 0x0c0360fe */
if(!s->budget--) { s->failed_pc=0x0c0360feu; return 0; }
r[3]=r[5];
goto P_0c036100;
P_0c036100: /* original 23d8, guest PC 0x0c036100 */
if(!s->budget--) { s->failed_pc=0x0c036100u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[13])==0)!=0);
goto P_0c036102;
P_0c036102: /* original 8d01, guest PC 0x0c036102 */
if(!s->budget--) { s->failed_pc=0x0c036102u; return 0; }
cond=r[17]&1u;
r[4]=r[14];
if(cond) { goto P_0c036108; }
goto P_0c036106;
P_0c036104: /* original 64e3, guest PC 0x0c036104 */
if(!s->budget--) { s->failed_pc=0x0c036104u; return 0; }
r[4]=r[14];
goto P_0c036106;
P_0c036106: /* original 65d3, guest PC 0x0c036106 */
if(!s->budget--) { s->failed_pc=0x0c036106u; return 0; }
r[5]=r[13];
goto P_0c036108;
P_0c036108: /* original 480b, guest PC 0x0c036108 */
if(!s->budget--) { s->failed_pc=0x0c036108u; return 0; }
target=r[8];
r[16]=code_base|0x0c03610cu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c03610cu) { target=s->pc; goto dispatch; }
goto P_0c03610c;
P_0c03610a: /* original 0009, guest PC 0x0c03610a */
if(!s->budget--) { s->failed_pc=0x0c03610au; return 0; }
goto P_0c03610c;
P_0c03610c: /* original 7a78, guest PC 0x0c03610c */
if(!s->budget--) { s->failed_pc=0x0c03610cu; return 0; }
r[10]+=0x00000078u;
goto P_0c03610e;
P_0c03610e: /* original 7b2c, guest PC 0x0c03610e */
if(!s->budget--) { s->failed_pc=0x0c03610eu; return 0; }
r[11]+=0x0000002cu;
goto P_0c036110;
P_0c036110: /* original 7e01, guest PC 0x0c036110 */
if(!s->budget--) { s->failed_pc=0x0c036110u; return 0; }
r[14]+=0x00000001u;
goto P_0c036112;
P_0c036112: /* original 3e93, guest PC 0x0c036112 */
if(!s->budget--) { s->failed_pc=0x0c036112u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[14]>=(int32_t)r[9])!=0);
goto P_0c036114;
P_0c036114: /* original 8b9b, guest PC 0x0c036114 */
if(!s->budget--) { s->failed_pc=0x0c036114u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c03604e; }
goto P_0c036116;
P_0c036116: /* original d31d, guest PC 0x0c036116 */
if(!s->budget--) { s->failed_pc=0x0c036116u; return 0; }
r[3]=read(ram,0x0c03618cu,4);
goto P_0c036118;
P_0c036118: /* original 430b, guest PC 0x0c036118 */
if(!s->budget--) { s->failed_pc=0x0c036118u; return 0; }
target=r[3];
r[16]=code_base|0x0c03611cu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c03611cu) { target=s->pc; goto dispatch; }
goto P_0c03611c;
P_0c03611a: /* original 0009, guest PC 0x0c03611a */
if(!s->budget--) { s->failed_pc=0x0c03611au; return 0; }
goto P_0c03611c;
P_0c03611c: /* original 7f04, guest PC 0x0c03611c */
if(!s->budget--) { s->failed_pc=0x0c03611cu; return 0; }
r[15]+=0x00000004u;
goto P_0c03611e;
P_0c03611e: /* original 4f26, guest PC 0x0c03611e */
if(!s->budget--) { s->failed_pc=0x0c03611eu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c036120;
P_0c036120: /* original e000, guest PC 0x0c036120 */
if(!s->budget--) { s->failed_pc=0x0c036120u; return 0; }
r[0]=0x00000000u;
goto P_0c036122;
P_0c036122: /* original 68f6, guest PC 0x0c036122 */
if(!s->budget--) { s->failed_pc=0x0c036122u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c036124;
P_0c036124: /* original 69f6, guest PC 0x0c036124 */
if(!s->budget--) { s->failed_pc=0x0c036124u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c036126;
P_0c036126: /* original 6af6, guest PC 0x0c036126 */
if(!s->budget--) { s->failed_pc=0x0c036126u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c036128;
P_0c036128: /* original 6bf6, guest PC 0x0c036128 */
if(!s->budget--) { s->failed_pc=0x0c036128u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c03612a;
P_0c03612a: /* original 6cf6, guest PC 0x0c03612a */
if(!s->budget--) { s->failed_pc=0x0c03612au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c03612c;
P_0c03612c: /* original 6df6, guest PC 0x0c03612c */
if(!s->budget--) { s->failed_pc=0x0c03612cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c03612e;
P_0c03612e: /* original 000b, guest PC 0x0c03612e */
if(!s->budget--) { s->failed_pc=0x0c03612eu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c036130: /* original 6ef6, guest PC 0x0c036130 */
if(!s->budget--) { s->failed_pc=0x0c036130u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c036132u,s,ram);
unsupported: s->failed_pc=target; return 0;
}
