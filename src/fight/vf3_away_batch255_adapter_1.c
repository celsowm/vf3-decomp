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
int vf3_away_batch255_adapter_1(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c096718u: goto P_0c096718;
case 0x0c09671au: goto P_0c09671a;
case 0x0c09671cu: goto P_0c09671c;
case 0x0c09671eu: goto P_0c09671e;
case 0x0c096720u: goto P_0c096720;
case 0x0c096722u: goto P_0c096722;
case 0x0c096724u: goto P_0c096724;
case 0x0c096726u: goto P_0c096726;
case 0x0c096728u: goto P_0c096728;
case 0x0c09672au: goto P_0c09672a;
case 0x0c09672cu: goto P_0c09672c;
case 0x0c09672eu: goto P_0c09672e;
case 0x0c096730u: goto P_0c096730;
case 0x0c096732u: goto P_0c096732;
case 0x0c096734u: goto P_0c096734;
case 0x0c096736u: goto P_0c096736;
case 0x0c096738u: goto P_0c096738;
case 0x0c09673au: goto P_0c09673a;
case 0x0c09673cu: goto P_0c09673c;
case 0x0c09673eu: goto P_0c09673e;
case 0x0c096740u: goto P_0c096740;
case 0x0c096742u: goto P_0c096742;
case 0x0c096744u: goto P_0c096744;
case 0x0c096746u: goto P_0c096746;
case 0x0c0967e8u: goto P_0c0967e8;
case 0x0c0967eau: goto P_0c0967ea;
case 0x0c0967ecu: goto P_0c0967ec;
case 0x0c0967eeu: goto P_0c0967ee;
case 0x0c0967f0u: goto P_0c0967f0;
case 0x0c0967f2u: goto P_0c0967f2;
case 0x0c0967f4u: goto P_0c0967f4;
case 0x0c0967f6u: goto P_0c0967f6;
case 0x0c0967f8u: goto P_0c0967f8;
case 0x0c0967fau: goto P_0c0967fa;
case 0x0c0967fcu: goto P_0c0967fc;
case 0x0c0967feu: goto P_0c0967fe;
case 0x0c096800u: goto P_0c096800;
case 0x0c096802u: goto P_0c096802;
case 0x0c096804u: goto P_0c096804;
case 0x0c096806u: goto P_0c096806;
case 0x0c096808u: goto P_0c096808;
case 0x0c09680au: goto P_0c09680a;
case 0x0c09680cu: goto P_0c09680c;
case 0x0c09680eu: goto P_0c09680e;
case 0x0c096810u: goto P_0c096810;
case 0x0c096812u: goto P_0c096812;
case 0x0c096814u: goto P_0c096814;
case 0x0c09abc4u: goto P_0c09abc4;
case 0x0c09abc6u: goto P_0c09abc6;
case 0x0c09abc8u: goto P_0c09abc8;
case 0x0c09abcau: goto P_0c09abca;
case 0x0c09abccu: goto P_0c09abcc;
case 0x0c09abceu: goto P_0c09abce;
case 0x0c09abd0u: goto P_0c09abd0;
case 0x0c09abd2u: goto P_0c09abd2;
case 0x0c09abd4u: goto P_0c09abd4;
case 0x0c09abd6u: goto P_0c09abd6;
case 0x0c09abd8u: goto P_0c09abd8;
case 0x0c09abdau: goto P_0c09abda;
case 0x0c09abdcu: goto P_0c09abdc;
case 0x0c09abdeu: goto P_0c09abde;
case 0x0c09abe0u: goto P_0c09abe0;
case 0x0c09abe2u: goto P_0c09abe2;
case 0x0c09abe4u: goto P_0c09abe4;
case 0x0c09abe6u: goto P_0c09abe6;
case 0x0c09abe8u: goto P_0c09abe8;
case 0x0c09abeau: goto P_0c09abea;
case 0x0c09abecu: goto P_0c09abec;
case 0x0c09abeeu: goto P_0c09abee;
case 0x0c09abf0u: goto P_0c09abf0;
case 0x0c09abf2u: goto P_0c09abf2;
case 0x0c09abf4u: goto P_0c09abf4;
case 0x0c09abf6u: goto P_0c09abf6;
case 0x0c09abf8u: goto P_0c09abf8;
case 0x0c09abfau: goto P_0c09abfa;
case 0x0c09abfcu: goto P_0c09abfc;
case 0x0c09abfeu: goto P_0c09abfe;
case 0x0c09ac00u: goto P_0c09ac00;
case 0x0c09ac02u: goto P_0c09ac02;
case 0x0c09ac04u: goto P_0c09ac04;
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
case 0x0c0c66b8u: goto P_0c0c66b8;
case 0x0c0c66bau: goto P_0c0c66ba;
case 0x0c0c66d0u: goto P_0c0c66d0;
case 0x0c0c66d2u: goto P_0c0c66d2;
case 0x0c0c66d4u: goto P_0c0c66d4;
case 0x0c0c66d6u: goto P_0c0c66d6;
case 0x0c0c66d8u: goto P_0c0c66d8;
case 0x0c0c66dau: goto P_0c0c66da;
case 0x0c0c9ad0u: goto P_0c0c9ad0;
case 0x0c0c9ad2u: goto P_0c0c9ad2;
case 0x0c0c9ad4u: goto P_0c0c9ad4;
case 0x0c0c9ad6u: goto P_0c0c9ad6;
case 0x0c0c9ad8u: goto P_0c0c9ad8;
case 0x0c0c9adau: goto P_0c0c9ada;
case 0x0c0c9adcu: goto P_0c0c9adc;
case 0x0c0c9adeu: goto P_0c0c9ade;
case 0x0c0c9ae0u: goto P_0c0c9ae0;
case 0x0c0c9ae2u: goto P_0c0c9ae2;
case 0x0c0c9ae4u: goto P_0c0c9ae4;
case 0x0c0c9ae6u: goto P_0c0c9ae6;
case 0x0c0c9ae8u: goto P_0c0c9ae8;
case 0x0c0c9aeau: goto P_0c0c9aea;
case 0x0c0c9aecu: goto P_0c0c9aec;
case 0x0c0c9aeeu: goto P_0c0c9aee;
case 0x0c0c9af0u: goto P_0c0c9af0;
case 0x0c0c9af2u: goto P_0c0c9af2;
case 0x0c0c9af4u: goto P_0c0c9af4;
case 0x0c0c9af6u: goto P_0c0c9af6;
case 0x0c0c9af8u: goto P_0c0c9af8;
case 0x0c0c9afau: goto P_0c0c9afa;
case 0x0c0c9afcu: goto P_0c0c9afc;
case 0x0c0c9afeu: goto P_0c0c9afe;
case 0x0c0c9b00u: goto P_0c0c9b00;
case 0x0c0c9b02u: goto P_0c0c9b02;
case 0x0c0c9b04u: goto P_0c0c9b04;
case 0x0c0c9b06u: goto P_0c0c9b06;
case 0x0c0c9b08u: goto P_0c0c9b08;
case 0x0c0c9b0au: goto P_0c0c9b0a;
case 0x0c0c9b0cu: goto P_0c0c9b0c;
case 0x0c0c9b0eu: goto P_0c0c9b0e;
case 0x0c0c9b10u: goto P_0c0c9b10;
case 0x0c0c9b12u: goto P_0c0c9b12;
case 0x0c0c9b14u: goto P_0c0c9b14;
case 0x0c0c9b16u: goto P_0c0c9b16;
case 0x0c0c9b18u: goto P_0c0c9b18;
case 0x0c0c9b1au: goto P_0c0c9b1a;
case 0x0c0c9b1cu: goto P_0c0c9b1c;
case 0x0c0c9b1eu: goto P_0c0c9b1e;
case 0x0c0c9b20u: goto P_0c0c9b20;
case 0x0c0c9b22u: goto P_0c0c9b22;
case 0x0c0c9b24u: goto P_0c0c9b24;
case 0x0c0c9b26u: goto P_0c0c9b26;
case 0x0c0c9b28u: goto P_0c0c9b28;
case 0x0c0c9b2au: goto P_0c0c9b2a;
case 0x0c0c9b2cu: goto P_0c0c9b2c;
case 0x0c0c9b40u: goto P_0c0c9b40;
case 0x0c0c9b42u: goto P_0c0c9b42;
case 0x0c0c9b44u: goto P_0c0c9b44;
case 0x0c0c9b46u: goto P_0c0c9b46;
case 0x0c0c9b48u: goto P_0c0c9b48;
case 0x0c0c9b4au: goto P_0c0c9b4a;
case 0x0c0c9b4cu: goto P_0c0c9b4c;
case 0x0c0c9b4eu: goto P_0c0c9b4e;
case 0x0c0c9b50u: goto P_0c0c9b50;
case 0x0c0c9b52u: goto P_0c0c9b52;
case 0x0c0c9b54u: goto P_0c0c9b54;
case 0x0c0c9b56u: goto P_0c0c9b56;
case 0x0c0c9b58u: goto P_0c0c9b58;
case 0x0c0c9b5au: goto P_0c0c9b5a;
case 0x0c0c9b5cu: goto P_0c0c9b5c;
case 0x0c0c9b5eu: goto P_0c0c9b5e;
case 0x0c0c9b60u: goto P_0c0c9b60;
case 0x0c0c9b90u: goto P_0c0c9b90;
case 0x0c0c9b92u: goto P_0c0c9b92;
default: return vf3_matrix_family(target,s,ram);
}
P_0c096718: /* original 4f22, guest PC 0x0c096718 */
if(!s->budget--) { s->failed_pc=0x0c096718u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c09671a;
P_0c09671a: /* original d340, guest PC 0x0c09671a */
if(!s->budget--) { s->failed_pc=0x0c09671au; return 0; }
r[3]=read(ram,0x0c09681cu,4);
goto P_0c09671c;
P_0c09671c: /* original 430b, guest PC 0x0c09671c */
if(!s->budget--) { s->failed_pc=0x0c09671cu; return 0; }
target=r[3];
r[16]=code_base|0x0c096720u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c096720u) { target=s->pc; goto dispatch; }
goto P_0c096720;
P_0c09671e: /* original 0009, guest PC 0x0c09671e */
if(!s->budget--) { s->failed_pc=0x0c09671eu; return 0; }
goto P_0c096720;
P_0c096720: /* original d23f, guest PC 0x0c096720 */
if(!s->budget--) { s->failed_pc=0x0c096720u; return 0; }
r[2]=read(ram,0x0c096820u,4);
goto P_0c096722;
P_0c096722: /* original 420b, guest PC 0x0c096722 */
if(!s->budget--) { s->failed_pc=0x0c096722u; return 0; }
target=r[2];
r[16]=code_base|0x0c096726u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c096726u) { target=s->pc; goto dispatch; }
goto P_0c096726;
P_0c096724: /* original 0009, guest PC 0x0c096724 */
if(!s->budget--) { s->failed_pc=0x0c096724u; return 0; }
goto P_0c096726;
P_0c096726: /* original d33f, guest PC 0x0c096726 */
if(!s->budget--) { s->failed_pc=0x0c096726u; return 0; }
r[3]=read(ram,0x0c096824u,4);
goto P_0c096728;
P_0c096728: /* original 430b, guest PC 0x0c096728 */
if(!s->budget--) { s->failed_pc=0x0c096728u; return 0; }
target=r[3];
r[16]=code_base|0x0c09672cu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09672cu) { target=s->pc; goto dispatch; }
goto P_0c09672c;
P_0c09672a: /* original 0009, guest PC 0x0c09672a */
if(!s->budget--) { s->failed_pc=0x0c09672au; return 0; }
goto P_0c09672c;
P_0c09672c: /* original d23e, guest PC 0x0c09672c */
if(!s->budget--) { s->failed_pc=0x0c09672cu; return 0; }
r[2]=read(ram,0x0c096828u,4);
goto P_0c09672e;
P_0c09672e: /* original 420b, guest PC 0x0c09672e */
if(!s->budget--) { s->failed_pc=0x0c09672eu; return 0; }
target=r[2];
r[16]=code_base|0x0c096732u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c096732u) { target=s->pc; goto dispatch; }
goto P_0c096732;
P_0c096730: /* original 0009, guest PC 0x0c096730 */
if(!s->budget--) { s->failed_pc=0x0c096730u; return 0; }
goto P_0c096732;
P_0c096732: /* original d33e, guest PC 0x0c096732 */
if(!s->budget--) { s->failed_pc=0x0c096732u; return 0; }
r[3]=read(ram,0x0c09682cu,4);
goto P_0c096734;
P_0c096734: /* original 430b, guest PC 0x0c096734 */
if(!s->budget--) { s->failed_pc=0x0c096734u; return 0; }
target=r[3];
r[16]=code_base|0x0c096738u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c096738u) { target=s->pc; goto dispatch; }
goto P_0c096738;
P_0c096736: /* original 0009, guest PC 0x0c096736 */
if(!s->budget--) { s->failed_pc=0x0c096736u; return 0; }
goto P_0c096738;
P_0c096738: /* original d23d, guest PC 0x0c096738 */
if(!s->budget--) { s->failed_pc=0x0c096738u; return 0; }
r[2]=read(ram,0x0c096830u,4);
goto P_0c09673a;
P_0c09673a: /* original 420b, guest PC 0x0c09673a */
if(!s->budget--) { s->failed_pc=0x0c09673au; return 0; }
target=r[2];
r[16]=code_base|0x0c09673eu;
r[4]=0x00000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09673eu) { target=s->pc; goto dispatch; }
goto P_0c09673e;
P_0c09673c: /* original e400, guest PC 0x0c09673c */
if(!s->budget--) { s->failed_pc=0x0c09673cu; return 0; }
r[4]=0x00000000u;
goto P_0c09673e;
P_0c09673e: /* original d33d, guest PC 0x0c09673e */
if(!s->budget--) { s->failed_pc=0x0c09673eu; return 0; }
r[3]=read(ram,0x0c096834u,4);
goto P_0c096740;
P_0c096740: /* original 430b, guest PC 0x0c096740 */
if(!s->budget--) { s->failed_pc=0x0c096740u; return 0; }
target=r[3];
r[16]=code_base|0x0c096744u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c096744u) { target=s->pc; goto dispatch; }
goto P_0c096744;
P_0c096742: /* original 0009, guest PC 0x0c096742 */
if(!s->budget--) { s->failed_pc=0x0c096742u; return 0; }
goto P_0c096744;
P_0c096744: /* original a050, guest PC 0x0c096744 */
if(!s->budget--) { s->failed_pc=0x0c096744u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0967e8;
P_0c096746: /* original 4f26, guest PC 0x0c096746 */
if(!s->budget--) { s->failed_pc=0x0c096746u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
if(!vf3_matrix_family(0x0c096748u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c096748u; return 0; } return 1;
P_0c0967e8: /* original 2fe6, guest PC 0x0c0967e8 */
if(!s->budget--) { s->failed_pc=0x0c0967e8u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0967ea;
P_0c0967ea: /* original 2fd6, guest PC 0x0c0967ea */
if(!s->budget--) { s->failed_pc=0x0c0967eau; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0967ec;
P_0c0967ec: /* original de18, guest PC 0x0c0967ec */
if(!s->budget--) { s->failed_pc=0x0c0967ecu; return 0; }
r[14]=read(ram,0x0c096850u,4);
goto P_0c0967ee;
P_0c0967ee: /* original 4f22, guest PC 0x0c0967ee */
if(!s->budget--) { s->failed_pc=0x0c0967eeu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0967f0;
P_0c0967f0: /* original dd19, guest PC 0x0c0967f0 */
if(!s->budget--) { s->failed_pc=0x0c0967f0u; return 0; }
r[13]=read(ram,0x0c096858u,4);
goto P_0c0967f2;
P_0c0967f2: /* original 64e3, guest PC 0x0c0967f2 */
if(!s->budget--) { s->failed_pc=0x0c0967f2u; return 0; }
r[4]=r[14];
goto P_0c0967f4;
P_0c0967f4: /* original d517, guest PC 0x0c0967f4 */
if(!s->budget--) { s->failed_pc=0x0c0967f4u; return 0; }
r[5]=read(ram,0x0c096854u,4);
goto P_0c0967f6;
P_0c0967f6: /* original 4d0b, guest PC 0x0c0967f6 */
if(!s->budget--) { s->failed_pc=0x0c0967f6u; return 0; }
target=r[13];
r[16]=code_base|0x0c0967fau;
r[4]+=0x0000002cu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0967fau) { target=s->pc; goto dispatch; }
goto P_0c0967fa;
P_0c0967f8: /* original 742c, guest PC 0x0c0967f8 */
if(!s->budget--) { s->failed_pc=0x0c0967f8u; return 0; }
r[4]+=0x0000002cu;
goto P_0c0967fa;
P_0c0967fa: /* original d518, guest PC 0x0c0967fa */
if(!s->budget--) { s->failed_pc=0x0c0967fau; return 0; }
r[5]=read(ram,0x0c09685cu,4);
goto P_0c0967fc;
P_0c0967fc: /* original 64e3, guest PC 0x0c0967fc */
if(!s->budget--) { s->failed_pc=0x0c0967fcu; return 0; }
r[4]=r[14];
goto P_0c0967fe;
P_0c0967fe: /* original 6552, guest PC 0x0c0967fe */
if(!s->budget--) { s->failed_pc=0x0c0967feu; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c096800;
P_0c096800: /* original 4d0b, guest PC 0x0c096800 */
if(!s->budget--) { s->failed_pc=0x0c096800u; return 0; }
target=r[13];
r[16]=code_base|0x0c096804u;
r[4]+=0x00000034u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c096804u) { target=s->pc; goto dispatch; }
goto P_0c096804;
P_0c096802: /* original 7434, guest PC 0x0c096802 */
if(!s->budget--) { s->failed_pc=0x0c096802u; return 0; }
r[4]+=0x00000034u;
goto P_0c096804;
P_0c096804: /* original d516, guest PC 0x0c096804 */
if(!s->budget--) { s->failed_pc=0x0c096804u; return 0; }
r[5]=read(ram,0x0c096860u,4);
goto P_0c096806;
P_0c096806: /* original 64e3, guest PC 0x0c096806 */
if(!s->budget--) { s->failed_pc=0x0c096806u; return 0; }
r[4]=r[14];
goto P_0c096808;
P_0c096808: /* original 6552, guest PC 0x0c096808 */
if(!s->budget--) { s->failed_pc=0x0c096808u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c09680a;
P_0c09680a: /* original 4d0b, guest PC 0x0c09680a */
if(!s->budget--) { s->failed_pc=0x0c09680au; return 0; }
target=r[13];
r[16]=code_base|0x0c09680eu;
r[4]+=0x00000038u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09680eu) { target=s->pc; goto dispatch; }
goto P_0c09680e;
P_0c09680c: /* original 7438, guest PC 0x0c09680c */
if(!s->budget--) { s->failed_pc=0x0c09680cu; return 0; }
r[4]+=0x00000038u;
goto P_0c09680e;
P_0c09680e: /* original 4f26, guest PC 0x0c09680e */
if(!s->budget--) { s->failed_pc=0x0c09680eu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c096810;
P_0c096810: /* original 6df6, guest PC 0x0c096810 */
if(!s->budget--) { s->failed_pc=0x0c096810u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c096812;
P_0c096812: /* original 000b, guest PC 0x0c096812 */
if(!s->budget--) { s->failed_pc=0x0c096812u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c096814: /* original 6ef6, guest PC 0x0c096814 */
if(!s->budget--) { s->failed_pc=0x0c096814u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c096816u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c096816u; return 0; } return 1;
P_0c09abc4: /* original d512, guest PC 0x0c09abc4 */
if(!s->budget--) { s->failed_pc=0x0c09abc4u; return 0; }
r[5]=read(ram,0x0c09ac10u,4);
goto P_0c09abc6;
P_0c09abc6: /* original e620, guest PC 0x0c09abc6 */
if(!s->budget--) { s->failed_pc=0x0c09abc6u; return 0; }
r[6]=0x00000020u;
goto P_0c09abc8;
P_0c09abc8: /* original 845b, guest PC 0x0c09abc8 */
if(!s->budget--) { s->failed_pc=0x0c09abc8u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[5]+11,1);
goto P_0c09abca;
P_0c09abca: /* original 640c, guest PC 0x0c09abca */
if(!s->budget--) { s->failed_pc=0x0c09abcau; return 0; }
r[4]=r[0]&255u;
goto P_0c09abcc;
P_0c09abcc: /* original 3463, guest PC 0x0c09abcc */
if(!s->budget--) { s->failed_pc=0x0c09abccu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=(int32_t)r[6])!=0);
goto P_0c09abce;
P_0c09abce: /* original 8b18, guest PC 0x0c09abce */
if(!s->budget--) { s->failed_pc=0x0c09abceu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09ac02; }
goto P_0c09abd0;
P_0c09abd0: /* original 9019, guest PC 0x0c09abd0 */
if(!s->budget--) { s->failed_pc=0x0c09abd0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09ac06u,2);
goto P_0c09abd2;
P_0c09abd2: /* original 035e, guest PC 0x0c09abd2 */
if(!s->budget--) { s->failed_pc=0x0c09abd2u; return 0; }
r[3]=read(ram,r[5]+r[0],4);
goto P_0c09abd4;
P_0c09abd4: /* original 2368, guest PC 0x0c09abd4 */
if(!s->budget--) { s->failed_pc=0x0c09abd4u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[6])==0)!=0);
goto P_0c09abd6;
P_0c09abd6: /* original 8914, guest PC 0x0c09abd6 */
if(!s->budget--) { s->failed_pc=0x0c09abd6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09ac02; }
goto P_0c09abd8;
P_0c09abd8: /* original 9017, guest PC 0x0c09abd8 */
if(!s->budget--) { s->failed_pc=0x0c09abd8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09ac0au,2);
goto P_0c09abda;
P_0c09abda: /* original 9315, guest PC 0x0c09abda */
if(!s->budget--) { s->failed_pc=0x0c09abdau; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09ac08u,2);
goto P_0c09abdc;
P_0c09abdc: /* original 025e, guest PC 0x0c09abdc */
if(!s->budget--) { s->failed_pc=0x0c09abdcu; return 0; }
r[2]=read(ram,r[5]+r[0],4);
goto P_0c09abde;
P_0c09abde: /* original 2238, guest PC 0x0c09abde */
if(!s->budget--) { s->failed_pc=0x0c09abdeu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c09abe0;
P_0c09abe0: /* original 8f05, guest PC 0x0c09abe0 */
if(!s->budget--) { s->failed_pc=0x0c09abe0u; return 0; }
cond=r[17]&1u;
r[7]=0x00000032u;
if(!cond) { goto P_0c09abee; }
goto P_0c09abe4;
P_0c09abe2: /* original e732, guest PC 0x0c09abe2 */
if(!s->budget--) { s->failed_pc=0x0c09abe2u; return 0; }
r[7]=0x00000032u;
goto P_0c09abe4;
P_0c09abe4: /* original 7401, guest PC 0x0c09abe4 */
if(!s->budget--) { s->failed_pc=0x0c09abe4u; return 0; }
r[4]+=0x00000001u;
goto P_0c09abe6;
P_0c09abe6: /* original 3477, guest PC 0x0c09abe6 */
if(!s->budget--) { s->failed_pc=0x0c09abe6u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>(int32_t)r[7])!=0);
goto P_0c09abe8;
P_0c09abe8: /* original 8b09, guest PC 0x0c09abe8 */
if(!s->budget--) { s->failed_pc=0x0c09abe8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09abfe; }
goto P_0c09abea;
P_0c09abea: /* original a008, guest PC 0x0c09abea */
if(!s->budget--) { s->failed_pc=0x0c09abeau; return 0; }
r[4]=r[6];
goto P_0c09abfe;
P_0c09abec: /* original 6463, guest PC 0x0c09abec */
if(!s->budget--) { s->failed_pc=0x0c09abecu; return 0; }
r[4]=r[6];
goto P_0c09abee;
P_0c09abee: /* original 025e, guest PC 0x0c09abee */
if(!s->budget--) { s->failed_pc=0x0c09abeeu; return 0; }
r[2]=read(ram,r[5]+r[0],4);
goto P_0c09abf0;
P_0c09abf0: /* original 930c, guest PC 0x0c09abf0 */
if(!s->budget--) { s->failed_pc=0x0c09abf0u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09ac0cu,2);
goto P_0c09abf2;
P_0c09abf2: /* original 2238, guest PC 0x0c09abf2 */
if(!s->budget--) { s->failed_pc=0x0c09abf2u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c09abf4;
P_0c09abf4: /* original 8905, guest PC 0x0c09abf4 */
if(!s->budget--) { s->failed_pc=0x0c09abf4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09ac02; }
goto P_0c09abf6;
P_0c09abf6: /* original 74fd, guest PC 0x0c09abf6 */
if(!s->budget--) { s->failed_pc=0x0c09abf6u; return 0; }
r[4]+=0xfffffffdu;
goto P_0c09abf8;
P_0c09abf8: /* original 3463, guest PC 0x0c09abf8 */
if(!s->budget--) { s->failed_pc=0x0c09abf8u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=(int32_t)r[6])!=0);
goto P_0c09abfa;
P_0c09abfa: /* original 8900, guest PC 0x0c09abfa */
if(!s->budget--) { s->failed_pc=0x0c09abfau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09abfe; }
goto P_0c09abfc;
P_0c09abfc: /* original 6473, guest PC 0x0c09abfc */
if(!s->budget--) { s->failed_pc=0x0c09abfcu; return 0; }
r[4]=r[7];
goto P_0c09abfe;
P_0c09abfe: /* original 6043, guest PC 0x0c09abfe */
if(!s->budget--) { s->failed_pc=0x0c09abfeu; return 0; }
r[0]=r[4];
goto P_0c09ac00;
P_0c09ac00: /* original 805b, guest PC 0x0c09ac00 */
if(!s->budget--) { s->failed_pc=0x0c09ac00u; return 0; }
write(ram,r[5]+11,r[0],1);
goto P_0c09ac02;
P_0c09ac02: /* original 000b, guest PC 0x0c09ac02 */
if(!s->budget--) { s->failed_pc=0x0c09ac02u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c09ac04: /* original 0009, guest PC 0x0c09ac04 */
if(!s->budget--) { s->failed_pc=0x0c09ac04u; return 0; }
if(!vf3_matrix_family(0x0c09ac06u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c09ac06u; return 0; } return 1;
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
P_0c0c9ad0: /* original 2fe6, guest PC 0x0c0c9ad0 */
if(!s->budget--) { s->failed_pc=0x0c0c9ad0u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c9ad2;
P_0c0c9ad2: /* original 9046, guest PC 0x0c0c9ad2 */
if(!s->budget--) { s->failed_pc=0x0c0c9ad2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c9b62u,2);
goto P_0c0c9ad4;
P_0c0c9ad4: /* original de26, guest PC 0x0c0c9ad4 */
if(!s->budget--) { s->failed_pc=0x0c0c9ad4u; return 0; }
r[14]=read(ram,0x0c0c9b70u,4);
goto P_0c0c9ad6;
P_0c0c9ad6: /* original d525, guest PC 0x0c0c9ad6 */
if(!s->budget--) { s->failed_pc=0x0c0c9ad6u; return 0; }
r[5]=read(ram,0x0c0c9b6cu,4);
goto P_0c0c9ad8;
P_0c0c9ad8: /* original 03ec, guest PC 0x0c0c9ad8 */
if(!s->budget--) { s->failed_pc=0x0c0c9ad8u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0c9ada;
P_0c0c9ada: /* original 4f22, guest PC 0x0c0c9ada */
if(!s->budget--) { s->failed_pc=0x0c0c9adau; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0c9adc;
P_0c0c9adc: /* original 2338, guest PC 0x0c0c9adc */
if(!s->budget--) { s->failed_pc=0x0c0c9adcu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c0c9ade;
P_0c0c9ade: /* original 7ffc, guest PC 0x0c0c9ade */
if(!s->budget--) { s->failed_pc=0x0c0c9adeu; return 0; }
r[15]+=0xfffffffcu;
goto P_0c0c9ae0;
P_0c0c9ae0: /* original 2f32, guest PC 0x0c0c9ae0 */
if(!s->budget--) { s->failed_pc=0x0c0c9ae0u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c0c9ae2;
P_0c0c9ae2: /* original 903f, guest PC 0x0c0c9ae2 */
if(!s->budget--) { s->failed_pc=0x0c0c9ae2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c9b64u,2);
goto P_0c0c9ae4;
P_0c0c9ae4: /* original d723, guest PC 0x0c0c9ae4 */
if(!s->budget--) { s->failed_pc=0x0c0c9ae4u; return 0; }
r[7]=read(ram,0x0c0c9b74u,4);
goto P_0c0c9ae6;
P_0c0c9ae6: /* original 065e, guest PC 0x0c0c9ae6 */
if(!s->budget--) { s->failed_pc=0x0c0c9ae6u; return 0; }
r[6]=read(ram,r[5]+r[0],4);
goto P_0c0c9ae8;
P_0c0c9ae8: /* original 903d, guest PC 0x0c0c9ae8 */
if(!s->budget--) { s->failed_pc=0x0c0c9ae8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c9b66u,2);
goto P_0c0c9aea;
P_0c0c9aea: /* original 04ec, guest PC 0x0c0c9aea */
if(!s->budget--) { s->failed_pc=0x0c0c9aeau; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0c9aec;
P_0c0c9aec: /* original 8f16, guest PC 0x0c0c9aec */
if(!s->budget--) { s->failed_pc=0x0c0c9aecu; return 0; }
cond=r[17]&1u;
r[7]&=r[6];
if(!cond) { goto P_0c0c9b1c; }
goto P_0c0c9af0;
P_0c0c9aee: /* original 2769, guest PC 0x0c0c9aee */
if(!s->budget--) { s->failed_pc=0x0c0c9aeeu; return 0; }
r[7]&=r[6];
goto P_0c0c9af0;
P_0c0c9af0: /* original 2778, guest PC 0x0c0c9af0 */
if(!s->budget--) { s->failed_pc=0x0c0c9af0u; return 0; }
r[17]=(r[17]&~1u)|(((r[7]&r[7])==0)!=0);
goto P_0c0c9af2;
P_0c0c9af2: /* original 8b09, guest PC 0x0c0c9af2 */
if(!s->budget--) { s->failed_pc=0x0c0c9af2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c9b08; }
goto P_0c0c9af4;
P_0c0c9af4: /* original d220, guest PC 0x0c0c9af4 */
if(!s->budget--) { s->failed_pc=0x0c0c9af4u; return 0; }
r[2]=read(ram,0x0c0c9b78u,4);
goto P_0c0c9af6;
P_0c0c9af6: /* original 2628, guest PC 0x0c0c9af6 */
if(!s->budget--) { s->failed_pc=0x0c0c9af6u; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[2])==0)!=0);
goto P_0c0c9af8;
P_0c0c9af8: /* original 8914, guest PC 0x0c0c9af8 */
if(!s->budget--) { s->failed_pc=0x0c0c9af8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c9b24; }
goto P_0c0c9afa;
P_0c0c9afa: /* original 9035, guest PC 0x0c0c9afa */
if(!s->budget--) { s->failed_pc=0x0c0c9afau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c9b68u,2);
goto P_0c0c9afc;
P_0c0c9afc: /* original e301, guest PC 0x0c0c9afc */
if(!s->budget--) { s->failed_pc=0x0c0c9afcu; return 0; }
r[3]=0x00000001u;
goto P_0c0c9afe;
P_0c0c9afe: /* original 0e44, guest PC 0x0c0c9afe */
if(!s->budget--) { s->failed_pc=0x0c0c9afeu; return 0; }
write(ram,r[14]+r[0],r[4],1);
goto P_0c0c9b00;
P_0c0c9b00: /* original 70ff, guest PC 0x0c0c9b00 */
if(!s->budget--) { s->failed_pc=0x0c0c9b00u; return 0; }
r[0]+=0xffffffffu;
goto P_0c0c9b02;
P_0c0c9b02: /* original 243a, guest PC 0x0c0c9b02 */
if(!s->budget--) { s->failed_pc=0x0c0c9b02u; return 0; }
r[4]^=r[3];
goto P_0c0c9b04;
P_0c0c9b04: /* original a00e, guest PC 0x0c0c9b04 */
if(!s->budget--) { s->failed_pc=0x0c0c9b04u; return 0; }
write(ram,r[14]+r[0],r[4],1);
goto P_0c0c9b24;
P_0c0c9b06: /* original 0e44, guest PC 0x0c0c9b06 */
if(!s->budget--) { s->failed_pc=0x0c0c9b06u; return 0; }
write(ram,r[14]+r[0],r[4],1);
goto P_0c0c9b08;
P_0c0c9b08: /* original 2448, guest PC 0x0c0c9b08 */
if(!s->budget--) { s->failed_pc=0x0c0c9b08u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c0c9b0a;
P_0c0c9b0a: /* original 8b09, guest PC 0x0c0c9b0a */
if(!s->budget--) { s->failed_pc=0x0c0c9b0au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c9b20; }
goto P_0c0c9b0c;
P_0c0c9b0c: /* original d21b, guest PC 0x0c0c9b0c */
if(!s->budget--) { s->failed_pc=0x0c0c9b0cu; return 0; }
r[2]=read(ram,0x0c0c9b7cu,4);
goto P_0c0c9b0e;
P_0c0c9b0e: /* original 420b, guest PC 0x0c0c9b0e */
if(!s->budget--) { s->failed_pc=0x0c0c9b0eu; return 0; }
target=r[2];
r[16]=code_base|0x0c0c9b12u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c9b12u) { target=s->pc; goto dispatch; }
goto P_0c0c9b12;
P_0c0c9b10: /* original 0009, guest PC 0x0c0c9b10 */
if(!s->budget--) { s->failed_pc=0x0c0c9b10u; return 0; }
goto P_0c0c9b12;
P_0c0c9b12: /* original 9026, guest PC 0x0c0c9b12 */
if(!s->budget--) { s->failed_pc=0x0c0c9b12u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c9b62u,2);
goto P_0c0c9b14;
P_0c0c9b14: /* original 03ec, guest PC 0x0c0c9b14 */
if(!s->budget--) { s->failed_pc=0x0c0c9b14u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0c9b16;
P_0c0c9b16: /* original 7301, guest PC 0x0c0c9b16 */
if(!s->budget--) { s->failed_pc=0x0c0c9b16u; return 0; }
r[3]+=0x00000001u;
goto P_0c0c9b18;
P_0c0c9b18: /* original a004, guest PC 0x0c0c9b18 */
if(!s->budget--) { s->failed_pc=0x0c0c9b18u; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c0c9b24;
P_0c0c9b1a: /* original 0e34, guest PC 0x0c0c9b1a */
if(!s->budget--) { s->failed_pc=0x0c0c9b1au; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c0c9b1c;
P_0c0c9b1c: /* original 2778, guest PC 0x0c0c9b1c */
if(!s->budget--) { s->failed_pc=0x0c0c9b1cu; return 0; }
r[17]=(r[17]&~1u)|(((r[7]&r[7])==0)!=0);
goto P_0c0c9b1e;
P_0c0c9b1e: /* original 8901, guest PC 0x0c0c9b1e */
if(!s->budget--) { s->failed_pc=0x0c0c9b1eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c9b24; }
goto P_0c0c9b20;
P_0c0c9b20: /* original e000, guest PC 0x0c0c9b20 */
if(!s->budget--) { s->failed_pc=0x0c0c9b20u; return 0; }
r[0]=0x00000000u;
goto P_0c0c9b22;
P_0c0c9b22: /* original 805b, guest PC 0x0c0c9b22 */
if(!s->budget--) { s->failed_pc=0x0c0c9b22u; return 0; }
write(ram,r[5]+11,r[0],1);
goto P_0c0c9b24;
P_0c0c9b24: /* original 7f04, guest PC 0x0c0c9b24 */
if(!s->budget--) { s->failed_pc=0x0c0c9b24u; return 0; }
r[15]+=0x00000004u;
goto P_0c0c9b26;
P_0c0c9b26: /* original d316, guest PC 0x0c0c9b26 */
if(!s->budget--) { s->failed_pc=0x0c0c9b26u; return 0; }
r[3]=read(ram,0x0c0c9b80u,4);
goto P_0c0c9b28;
P_0c0c9b28: /* original 4f26, guest PC 0x0c0c9b28 */
if(!s->budget--) { s->failed_pc=0x0c0c9b28u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0c9b2a;
P_0c0c9b2a: /* original 432b, guest PC 0x0c0c9b2a */
if(!s->budget--) { s->failed_pc=0x0c0c9b2au; return 0; }
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
P_0c0c9b2c: /* original 6ef6, guest PC 0x0c0c9b2c */
if(!s->budget--) { s->failed_pc=0x0c0c9b2cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0c9b2eu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0c9b2eu; return 0; } return 1;
P_0c0c9b40: /* original 2fe6, guest PC 0x0c0c9b40 */
if(!s->budget--) { s->failed_pc=0x0c0c9b40u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c9b42;
P_0c0c9b42: /* original 900f, guest PC 0x0c0c9b42 */
if(!s->budget--) { s->failed_pc=0x0c0c9b42u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c9b64u,2);
goto P_0c0c9b44;
P_0c0c9b44: /* original de09, guest PC 0x0c0c9b44 */
if(!s->budget--) { s->failed_pc=0x0c0c9b44u; return 0; }
r[14]=read(ram,0x0c0c9b6cu,4);
goto P_0c0c9b46;
P_0c0c9b46: /* original d30b, guest PC 0x0c0c9b46 */
if(!s->budget--) { s->failed_pc=0x0c0c9b46u; return 0; }
r[3]=read(ram,0x0c0c9b74u,4);
goto P_0c0c9b48;
P_0c0c9b48: /* original 04ee, guest PC 0x0c0c9b48 */
if(!s->budget--) { s->failed_pc=0x0c0c9b48u; return 0; }
r[4]=read(ram,r[14]+r[0],4);
goto P_0c0c9b4a;
P_0c0c9b4a: /* original 4f22, guest PC 0x0c0c9b4a */
if(!s->budget--) { s->failed_pc=0x0c0c9b4au; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0c9b4c;
P_0c0c9b4c: /* original 2438, guest PC 0x0c0c9b4c */
if(!s->budget--) { s->failed_pc=0x0c0c9b4cu; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[3])==0)!=0);
goto P_0c0c9b4e;
P_0c0c9b4e: /* original 8904, guest PC 0x0c0c9b4e */
if(!s->budget--) { s->failed_pc=0x0c0c9b4eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c9b5a; }
goto P_0c0c9b50;
P_0c0c9b50: /* original d20c, guest PC 0x0c0c9b50 */
if(!s->budget--) { s->failed_pc=0x0c0c9b50u; return 0; }
r[2]=read(ram,0x0c0c9b84u,4);
goto P_0c0c9b52;
P_0c0c9b52: /* original 420b, guest PC 0x0c0c9b52 */
if(!s->budget--) { s->failed_pc=0x0c0c9b52u; return 0; }
target=r[2];
r[16]=code_base|0x0c0c9b56u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c9b56u) { target=s->pc; goto dispatch; }
goto P_0c0c9b56;
P_0c0c9b54: /* original 0009, guest PC 0x0c0c9b54 */
if(!s->budget--) { s->failed_pc=0x0c0c9b54u; return 0; }
goto P_0c0c9b56;
P_0c0c9b56: /* original e000, guest PC 0x0c0c9b56 */
if(!s->budget--) { s->failed_pc=0x0c0c9b56u; return 0; }
r[0]=0x00000000u;
goto P_0c0c9b58;
P_0c0c9b58: /* original 80eb, guest PC 0x0c0c9b58 */
if(!s->budget--) { s->failed_pc=0x0c0c9b58u; return 0; }
write(ram,r[14]+11,r[0],1);
goto P_0c0c9b5a;
P_0c0c9b5a: /* original 4f26, guest PC 0x0c0c9b5a */
if(!s->budget--) { s->failed_pc=0x0c0c9b5au; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0c9b5c;
P_0c0c9b5c: /* original d308, guest PC 0x0c0c9b5c */
if(!s->budget--) { s->failed_pc=0x0c0c9b5cu; return 0; }
r[3]=read(ram,0x0c0c9b80u,4);
goto P_0c0c9b5e;
P_0c0c9b5e: /* original 432b, guest PC 0x0c0c9b5e */
if(!s->budget--) { s->failed_pc=0x0c0c9b5eu; return 0; }
target=r[3];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
code_base=target&0xff000000u;
switch(target&0x1fffffffu) {
case 0x0c09abc4u: goto P_0c09abc4;
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
P_0c0c9b60: /* original 6ef6, guest PC 0x0c0c9b60 */
if(!s->budget--) { s->failed_pc=0x0c0c9b60u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0c9b62u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0c9b62u; return 0; } return 1;
P_0c0c9b90: /* original 000b, guest PC 0x0c0c9b90 */
if(!s->budget--) { s->failed_pc=0x0c0c9b90u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c0c9b92: /* original 0009, guest PC 0x0c0c9b92 */
if(!s->budget--) { s->failed_pc=0x0c0c9b92u; return 0; }
if(!vf3_matrix_family(0x0c0c9b94u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0c9b94u; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
