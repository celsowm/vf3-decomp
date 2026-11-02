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
int vf3_away_batch43_adapter_17(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c06c6d6u: goto P_0c06c6d6;
case 0x0c06c6d8u: goto P_0c06c6d8;
case 0x0c06c6dau: goto P_0c06c6da;
case 0x0c06c6dcu: goto P_0c06c6dc;
case 0x0c06c6deu: goto P_0c06c6de;
case 0x0c06c720u: goto P_0c06c720;
case 0x0c06c722u: goto P_0c06c722;
case 0x0c06c724u: goto P_0c06c724;
case 0x0c06c726u: goto P_0c06c726;
case 0x0c06c728u: goto P_0c06c728;
case 0x0c06c72au: goto P_0c06c72a;
case 0x0c06c72cu: goto P_0c06c72c;
case 0x0c06c72eu: goto P_0c06c72e;
case 0x0c06c730u: goto P_0c06c730;
case 0x0c06c732u: goto P_0c06c732;
case 0x0c06c734u: goto P_0c06c734;
case 0x0c06c736u: goto P_0c06c736;
case 0x0c06c738u: goto P_0c06c738;
case 0x0c06c73au: goto P_0c06c73a;
case 0x0c06c73cu: goto P_0c06c73c;
case 0x0c06c73eu: goto P_0c06c73e;
case 0x0c06c740u: goto P_0c06c740;
case 0x0c06c742u: goto P_0c06c742;
case 0x0c06c744u: goto P_0c06c744;
case 0x0c06c746u: goto P_0c06c746;
case 0x0c06c748u: goto P_0c06c748;
case 0x0c06c74au: goto P_0c06c74a;
case 0x0c06c74cu: goto P_0c06c74c;
case 0x0c06c74eu: goto P_0c06c74e;
case 0x0c06c750u: goto P_0c06c750;
case 0x0c06c752u: goto P_0c06c752;
case 0x0c06c754u: goto P_0c06c754;
case 0x0c06c756u: goto P_0c06c756;
case 0x0c06c758u: goto P_0c06c758;
case 0x0c06c75au: goto P_0c06c75a;
case 0x0c06c75cu: goto P_0c06c75c;
case 0x0c06c75eu: goto P_0c06c75e;
case 0x0c06c760u: goto P_0c06c760;
case 0x0c06c762u: goto P_0c06c762;
case 0x0c06c764u: goto P_0c06c764;
case 0x0c06c766u: goto P_0c06c766;
case 0x0c06c768u: goto P_0c06c768;
case 0x0c06c76au: goto P_0c06c76a;
case 0x0c06c76cu: goto P_0c06c76c;
case 0x0c06c76eu: goto P_0c06c76e;
case 0x0c06c770u: goto P_0c06c770;
case 0x0c06c772u: goto P_0c06c772;
case 0x0c06c774u: goto P_0c06c774;
case 0x0c06c776u: goto P_0c06c776;
case 0x0c06c778u: goto P_0c06c778;
case 0x0c06c77au: goto P_0c06c77a;
case 0x0c06c77cu: goto P_0c06c77c;
case 0x0c06c77eu: goto P_0c06c77e;
case 0x0c06c780u: goto P_0c06c780;
case 0x0c06c782u: goto P_0c06c782;
case 0x0c06c784u: goto P_0c06c784;
case 0x0c06c786u: goto P_0c06c786;
case 0x0c06c788u: goto P_0c06c788;
case 0x0c06c78au: goto P_0c06c78a;
case 0x0c06c78cu: goto P_0c06c78c;
case 0x0c06c78eu: goto P_0c06c78e;
case 0x0c06c790u: goto P_0c06c790;
case 0x0c06c792u: goto P_0c06c792;
case 0x0c06c794u: goto P_0c06c794;
case 0x0c06c796u: goto P_0c06c796;
case 0x0c06c798u: goto P_0c06c798;
case 0x0c06c79au: goto P_0c06c79a;
case 0x0c06c79cu: goto P_0c06c79c;
case 0x0c06c79eu: goto P_0c06c79e;
case 0x0c06c7a0u: goto P_0c06c7a0;
case 0x0c06c7a2u: goto P_0c06c7a2;
case 0x0c06c7a4u: goto P_0c06c7a4;
case 0x0c06c7a6u: goto P_0c06c7a6;
case 0x0c06c7a8u: goto P_0c06c7a8;
case 0x0c06c7aau: goto P_0c06c7aa;
case 0x0c06c7acu: goto P_0c06c7ac;
case 0x0c06c7aeu: goto P_0c06c7ae;
case 0x0c06c7b0u: goto P_0c06c7b0;
case 0x0c06c7b2u: goto P_0c06c7b2;
case 0x0c06c7b4u: goto P_0c06c7b4;
case 0x0c06c7b6u: goto P_0c06c7b6;
case 0x0c06c7b8u: goto P_0c06c7b8;
case 0x0c06c7bau: goto P_0c06c7ba;
case 0x0c06c7bcu: goto P_0c06c7bc;
case 0x0c06c7beu: goto P_0c06c7be;
case 0x0c06c7c0u: goto P_0c06c7c0;
case 0x0c06c7c2u: goto P_0c06c7c2;
case 0x0c06c7c4u: goto P_0c06c7c4;
case 0x0c06c7c6u: goto P_0c06c7c6;
case 0x0c06c7c8u: goto P_0c06c7c8;
case 0x0c06c7cau: goto P_0c06c7ca;
case 0x0c07a7e8u: goto P_0c07a7e8;
case 0x0c07a7eau: goto P_0c07a7ea;
case 0x0c07a7ecu: goto P_0c07a7ec;
case 0x0c07a7eeu: goto P_0c07a7ee;
case 0x0c07a7f0u: goto P_0c07a7f0;
case 0x0c07a7f2u: goto P_0c07a7f2;
case 0x0c07a7f4u: goto P_0c07a7f4;
case 0x0c07a7f6u: goto P_0c07a7f6;
case 0x0c07a7f8u: goto P_0c07a7f8;
case 0x0c07a7fau: goto P_0c07a7fa;
case 0x0c07a7fcu: goto P_0c07a7fc;
case 0x0c07a7feu: goto P_0c07a7fe;
case 0x0c07a800u: goto P_0c07a800;
case 0x0c07a802u: goto P_0c07a802;
case 0x0c07a804u: goto P_0c07a804;
case 0x0c07a806u: goto P_0c07a806;
case 0x0c07a808u: goto P_0c07a808;
case 0x0c07a80au: goto P_0c07a80a;
case 0x0c07a80cu: goto P_0c07a80c;
case 0x0c07a80eu: goto P_0c07a80e;
case 0x0c07a810u: goto P_0c07a810;
case 0x0c07a812u: goto P_0c07a812;
case 0x0c07a814u: goto P_0c07a814;
case 0x0c07a816u: goto P_0c07a816;
case 0x0c07a818u: goto P_0c07a818;
case 0x0c07a81au: goto P_0c07a81a;
case 0x0c07a81cu: goto P_0c07a81c;
case 0x0c07a81eu: goto P_0c07a81e;
case 0x0c07a820u: goto P_0c07a820;
case 0x0c07a822u: goto P_0c07a822;
case 0x0c07a824u: goto P_0c07a824;
case 0x0c07a826u: goto P_0c07a826;
case 0x0c07a828u: goto P_0c07a828;
case 0x0c07a82au: goto P_0c07a82a;
case 0x0c07a82cu: goto P_0c07a82c;
case 0x0c07a82eu: goto P_0c07a82e;
case 0x0c07a830u: goto P_0c07a830;
case 0x0c07a832u: goto P_0c07a832;
case 0x0c07a834u: goto P_0c07a834;
case 0x0c07a836u: goto P_0c07a836;
case 0x0c07a838u: goto P_0c07a838;
case 0x0c07a83au: goto P_0c07a83a;
case 0x0c07a83cu: goto P_0c07a83c;
case 0x0c07a83eu: goto P_0c07a83e;
case 0x0c07a840u: goto P_0c07a840;
case 0x0c07a842u: goto P_0c07a842;
case 0x0c07af6cu: goto P_0c07af6c;
case 0x0c07af6eu: goto P_0c07af6e;
case 0x0c07af70u: goto P_0c07af70;
case 0x0c07af72u: goto P_0c07af72;
case 0x0c07af74u: goto P_0c07af74;
case 0x0c07af76u: goto P_0c07af76;
case 0x0c07af78u: goto P_0c07af78;
case 0x0c07af7au: goto P_0c07af7a;
case 0x0c07af7cu: goto P_0c07af7c;
case 0x0c07af7eu: goto P_0c07af7e;
case 0x0c07af80u: goto P_0c07af80;
case 0x0c07af82u: goto P_0c07af82;
case 0x0c07af84u: goto P_0c07af84;
case 0x0c07af86u: goto P_0c07af86;
case 0x0c07af88u: goto P_0c07af88;
case 0x0c07af8au: goto P_0c07af8a;
case 0x0c07af8cu: goto P_0c07af8c;
case 0x0c07af8eu: goto P_0c07af8e;
case 0x0c07af90u: goto P_0c07af90;
case 0x0c07af92u: goto P_0c07af92;
case 0x0c07af94u: goto P_0c07af94;
case 0x0c07af96u: goto P_0c07af96;
case 0x0c07af98u: goto P_0c07af98;
case 0x0c07af9au: goto P_0c07af9a;
case 0x0c07af9cu: goto P_0c07af9c;
case 0x0c07af9eu: goto P_0c07af9e;
case 0x0c07afa0u: goto P_0c07afa0;
case 0x0c07afa2u: goto P_0c07afa2;
case 0x0c07afa4u: goto P_0c07afa4;
case 0x0c07afa6u: goto P_0c07afa6;
case 0x0c07afa8u: goto P_0c07afa8;
case 0x0c07afaau: goto P_0c07afaa;
case 0x0c07afacu: goto P_0c07afac;
case 0x0c07afaeu: goto P_0c07afae;
case 0x0c07afb0u: goto P_0c07afb0;
case 0x0c07afb2u: goto P_0c07afb2;
case 0x0c07afb4u: goto P_0c07afb4;
case 0x0c07afb6u: goto P_0c07afb6;
case 0x0c07afb8u: goto P_0c07afb8;
case 0x0c07afbau: goto P_0c07afba;
case 0x0c07afbcu: goto P_0c07afbc;
case 0x0c07afbeu: goto P_0c07afbe;
case 0x0c07afc0u: goto P_0c07afc0;
case 0x0c07afc2u: goto P_0c07afc2;
case 0x0c07afc4u: goto P_0c07afc4;
case 0x0c07afc6u: goto P_0c07afc6;
case 0x0c07afc8u: goto P_0c07afc8;
case 0x0c07afcau: goto P_0c07afca;
case 0x0c07afccu: goto P_0c07afcc;
case 0x0c07afceu: goto P_0c07afce;
case 0x0c07afd0u: goto P_0c07afd0;
case 0x0c07afd2u: goto P_0c07afd2;
case 0x0c07afd4u: goto P_0c07afd4;
case 0x0c07afd6u: goto P_0c07afd6;
case 0x0c07afd8u: goto P_0c07afd8;
case 0x0c07afdau: goto P_0c07afda;
case 0x0c07afdcu: goto P_0c07afdc;
case 0x0c07afdeu: goto P_0c07afde;
case 0x0c07afe0u: goto P_0c07afe0;
case 0x0c07afe2u: goto P_0c07afe2;
case 0x0c07afe4u: goto P_0c07afe4;
case 0x0c07afe6u: goto P_0c07afe6;
case 0x0c07afe8u: goto P_0c07afe8;
case 0x0c07afeau: goto P_0c07afea;
case 0x0c07afecu: goto P_0c07afec;
case 0x0c07afeeu: goto P_0c07afee;
case 0x0c07aff0u: goto P_0c07aff0;
case 0x0c07aff2u: goto P_0c07aff2;
case 0x0c07aff4u: goto P_0c07aff4;
case 0x0c07aff6u: goto P_0c07aff6;
case 0x0c07aff8u: goto P_0c07aff8;
case 0x0c07affau: goto P_0c07affa;
case 0x0c07affcu: goto P_0c07affc;
case 0x0c07affeu: goto P_0c07affe;
default: return vf3_matrix_family(target,s,ram);
}
P_0c06c6d6: /* original 4f22, guest PC 0x0c06c6d6 */
if(!s->budget--) { s->failed_pc=0x0c06c6d6u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c06c6d8;
P_0c06c6d8: /* original bf76, guest PC 0x0c06c6d8 */
if(!s->budget--) { s->failed_pc=0x0c06c6d8u; return 0; }
target=code_base|0x0c06c5c8u; r[16]=code_base|0x0c06c6dcu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06c6dcu) { target=s->pc; goto dispatch; }
goto P_0c06c6dc;
P_0c06c6da: /* original 0009, guest PC 0x0c06c6da */
if(!s->budget--) { s->failed_pc=0x0c06c6dau; return 0; }
goto P_0c06c6dc;
P_0c06c6dc: /* original a020, guest PC 0x0c06c6dc */
if(!s->budget--) { s->failed_pc=0x0c06c6dcu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c06c720;
P_0c06c6de: /* original 4f26, guest PC 0x0c06c6de */
if(!s->budget--) { s->failed_pc=0x0c06c6deu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
if(!vf3_matrix_family(0x0c06c6e0u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c06c6e0u; return 0; } return 1;
P_0c06c720: /* original 2fe6, guest PC 0x0c06c720 */
if(!s->budget--) { s->failed_pc=0x0c06c720u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06c722;
P_0c06c722: /* original 9053, guest PC 0x0c06c722 */
if(!s->budget--) { s->failed_pc=0x0c06c722u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06c7ccu,2);
goto P_0c06c724;
P_0c06c724: /* original 7ffc, guest PC 0x0c06c724 */
if(!s->budget--) { s->failed_pc=0x0c06c724u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c06c726;
P_0c06c726: /* original de2c, guest PC 0x0c06c726 */
if(!s->budget--) { s->failed_pc=0x0c06c726u; return 0; }
r[14]=read(ram,0x0c06c7d8u,4);
goto P_0c06c728;
P_0c06c728: /* original 00ec, guest PC 0x0c06c728 */
if(!s->budget--) { s->failed_pc=0x0c06c728u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c06c72a;
P_0c06c72a: /* original 8801, guest PC 0x0c06c72a */
if(!s->budget--) { s->failed_pc=0x0c06c72au; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c06c72c;
P_0c06c72c: /* original 8d12, guest PC 0x0c06c72c */
if(!s->budget--) { s->failed_pc=0x0c06c72cu; return 0; }
cond=r[17]&1u;
r[4]=r[0];
if(cond) { goto P_0c06c754; }
goto P_0c06c730;
P_0c06c72e: /* original 6403, guest PC 0x0c06c72e */
if(!s->budget--) { s->failed_pc=0x0c06c72eu; return 0; }
r[4]=r[0];
goto P_0c06c730;
P_0c06c730: /* original 904d, guest PC 0x0c06c730 */
if(!s->budget--) { s->failed_pc=0x0c06c730u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06c7ceu,2);
goto P_0c06c732;
P_0c06c732: /* original 04ec, guest PC 0x0c06c732 */
if(!s->budget--) { s->failed_pc=0x0c06c732u; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c06c734;
P_0c06c734: /* original 70ff, guest PC 0x0c06c734 */
if(!s->budget--) { s->failed_pc=0x0c06c734u; return 0; }
r[0]+=0xffffffffu;
goto P_0c06c736;
P_0c06c736: /* original 03ec, guest PC 0x0c06c736 */
if(!s->budget--) { s->failed_pc=0x0c06c736u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c06c738;
P_0c06c738: /* original 2338, guest PC 0x0c06c738 */
if(!s->budget--) { s->failed_pc=0x0c06c738u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c06c73a;
P_0c06c73a: /* original 8f02, guest PC 0x0c06c73a */
if(!s->budget--) { s->failed_pc=0x0c06c73au; return 0; }
cond=r[17]&1u;
write(ram,r[15],r[3],4);
if(!cond) { goto P_0c06c742; }
goto P_0c06c73e;
P_0c06c73c: /* original 2f32, guest PC 0x0c06c73c */
if(!s->budget--) { s->failed_pc=0x0c06c73cu; return 0; }
write(ram,r[15],r[3],4);
goto P_0c06c73e;
P_0c06c73e: /* original 2448, guest PC 0x0c06c73e */
if(!s->budget--) { s->failed_pc=0x0c06c73eu; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c06c740;
P_0c06c740: /* original 890c, guest PC 0x0c06c740 */
if(!s->budget--) { s->failed_pc=0x0c06c740u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c06c75c; }
goto P_0c06c742;
P_0c06c742: /* original 9045, guest PC 0x0c06c742 */
if(!s->budget--) { s->failed_pc=0x0c06c742u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06c7d0u,2);
goto P_0c06c744;
P_0c06c744: /* original 63f2, guest PC 0x0c06c744 */
if(!s->budget--) { s->failed_pc=0x0c06c744u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c06c746;
P_0c06c746: /* original 04ec, guest PC 0x0c06c746 */
if(!s->budget--) { s->failed_pc=0x0c06c746u; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c06c748;
P_0c06c748: /* original 3342, guest PC 0x0c06c748 */
if(!s->budget--) { s->failed_pc=0x0c06c748u; return 0; }
r[17]=(r[17]&~1u)|((r[3]>=r[4])!=0);
goto P_0c06c74a;
P_0c06c74a: /* original 8903, guest PC 0x0c06c74a */
if(!s->budget--) { s->failed_pc=0x0c06c74au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c06c754; }
goto P_0c06c74c;
P_0c06c74c: /* original 9041, guest PC 0x0c06c74c */
if(!s->budget--) { s->failed_pc=0x0c06c74cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06c7d2u,2);
goto P_0c06c74e;
P_0c06c74e: /* original e102, guest PC 0x0c06c74e */
if(!s->budget--) { s->failed_pc=0x0c06c74eu; return 0; }
r[1]=0x00000002u;
goto P_0c06c750;
P_0c06c750: /* original a007, guest PC 0x0c06c750 */
if(!s->budget--) { s->failed_pc=0x0c06c750u; return 0; }
write(ram,r[14]+r[0],r[1],1);
goto P_0c06c762;
P_0c06c752: /* original 0e14, guest PC 0x0c06c752 */
if(!s->budget--) { s->failed_pc=0x0c06c752u; return 0; }
write(ram,r[14]+r[0],r[1],1);
goto P_0c06c754;
P_0c06c754: /* original 903d, guest PC 0x0c06c754 */
if(!s->budget--) { s->failed_pc=0x0c06c754u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06c7d2u,2);
goto P_0c06c756;
P_0c06c756: /* original e303, guest PC 0x0c06c756 */
if(!s->budget--) { s->failed_pc=0x0c06c756u; return 0; }
r[3]=0x00000003u;
goto P_0c06c758;
P_0c06c758: /* original a003, guest PC 0x0c06c758 */
if(!s->budget--) { s->failed_pc=0x0c06c758u; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c06c762;
P_0c06c75a: /* original 0e34, guest PC 0x0c06c75a */
if(!s->budget--) { s->failed_pc=0x0c06c75au; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c06c75c;
P_0c06c75c: /* original 9039, guest PC 0x0c06c75c */
if(!s->budget--) { s->failed_pc=0x0c06c75cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06c7d2u,2);
goto P_0c06c75e;
P_0c06c75e: /* original e101, guest PC 0x0c06c75e */
if(!s->budget--) { s->failed_pc=0x0c06c75eu; return 0; }
r[1]=0x00000001u;
goto P_0c06c760;
P_0c06c760: /* original 0e14, guest PC 0x0c06c760 */
if(!s->budget--) { s->failed_pc=0x0c06c760u; return 0; }
write(ram,r[14]+r[0],r[1],1);
goto P_0c06c762;
P_0c06c762: /* original 9036, guest PC 0x0c06c762 */
if(!s->budget--) { s->failed_pc=0x0c06c762u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06c7d2u,2);
goto P_0c06c764;
P_0c06c764: /* original 00ec, guest PC 0x0c06c764 */
if(!s->budget--) { s->failed_pc=0x0c06c764u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c06c766;
P_0c06c766: /* original 8803, guest PC 0x0c06c766 */
if(!s->budget--) { s->failed_pc=0x0c06c766u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000003u)!=0);
goto P_0c06c768;
P_0c06c768: /* original 8f03, guest PC 0x0c06c768 */
if(!s->budget--) { s->failed_pc=0x0c06c768u; return 0; }
cond=r[17]&1u;
r[4]=r[0];
if(!cond) { goto P_0c06c772; }
goto P_0c06c76c;
P_0c06c76a: /* original 6403, guest PC 0x0c06c76a */
if(!s->budget--) { s->failed_pc=0x0c06c76au; return 0; }
r[4]=r[0];
goto P_0c06c76c;
P_0c06c76c: /* original 7f04, guest PC 0x0c06c76c */
if(!s->budget--) { s->failed_pc=0x0c06c76cu; return 0; }
r[15]+=0x00000004u;
goto P_0c06c76e;
P_0c06c76e: /* original a018, guest PC 0x0c06c76e */
if(!s->budget--) { s->failed_pc=0x0c06c76eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c06c7a2;
P_0c06c770: /* original 6ef6, guest PC 0x0c06c770 */
if(!s->budget--) { s->failed_pc=0x0c06c770u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c06c772;
P_0c06c772: /* original d31a, guest PC 0x0c06c772 */
if(!s->budget--) { s->failed_pc=0x0c06c772u; return 0; }
r[3]=read(ram,0x0c06c7dcu,4);
goto P_0c06c774;
P_0c06c774: /* original e23f, guest PC 0x0c06c774 */
if(!s->budget--) { s->failed_pc=0x0c06c774u; return 0; }
r[2]=0x0000003fu;
goto P_0c06c776;
P_0c06c776: /* original 902d, guest PC 0x0c06c776 */
if(!s->budget--) { s->failed_pc=0x0c06c776u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06c7d4u,2);
goto P_0c06c778;
P_0c06c778: /* original 6532, guest PC 0x0c06c778 */
if(!s->budget--) { s->failed_pc=0x0c06c778u; return 0; }
tmp=read(ram,r[3],4);
r[5]=tmp;
goto P_0c06c77a;
P_0c06c77a: /* original e303, guest PC 0x0c06c77a */
if(!s->budget--) { s->failed_pc=0x0c06c77au; return 0; }
r[3]=0x00000003u;
goto P_0c06c77c;
P_0c06c77c: /* original 04ec, guest PC 0x0c06c77c */
if(!s->budget--) { s->failed_pc=0x0c06c77cu; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c06c77e;
P_0c06c77e: /* original 2529, guest PC 0x0c06c77e */
if(!s->budget--) { s->failed_pc=0x0c06c77eu; return 0; }
r[5]&=r[2];
goto P_0c06c780;
P_0c06c780: /* original 2558, guest PC 0x0c06c780 */
if(!s->budget--) { s->failed_pc=0x0c06c780u; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[5])==0)!=0);
goto P_0c06c782;
P_0c06c782: /* original 8f01, guest PC 0x0c06c782 */
if(!s->budget--) { s->failed_pc=0x0c06c782u; return 0; }
cond=r[17]&1u;
r[4]&=r[3];
if(!cond) { goto P_0c06c788; }
goto P_0c06c786;
P_0c06c784: /* original 2439, guest PC 0x0c06c784 */
if(!s->budget--) { s->failed_pc=0x0c06c784u; return 0; }
r[4]&=r[3];
goto P_0c06c786;
P_0c06c786: /* original 7401, guest PC 0x0c06c786 */
if(!s->budget--) { s->failed_pc=0x0c06c786u; return 0; }
r[4]+=0x00000001u;
goto P_0c06c788;
P_0c06c788: /* original e302, guest PC 0x0c06c788 */
if(!s->budget--) { s->failed_pc=0x0c06c788u; return 0; }
r[3]=0x00000002u;
goto P_0c06c78a;
P_0c06c78a: /* original 3436, guest PC 0x0c06c78a */
if(!s->budget--) { s->failed_pc=0x0c06c78au; return 0; }
r[17]=(r[17]&~1u)|((r[4]>r[3])!=0);
goto P_0c06c78c;
P_0c06c78c: /* original 8b00, guest PC 0x0c06c78c */
if(!s->budget--) { s->failed_pc=0x0c06c78cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06c790; }
goto P_0c06c78e;
P_0c06c78e: /* original e400, guest PC 0x0c06c78e */
if(!s->budget--) { s->failed_pc=0x0c06c78eu; return 0; }
r[4]=0x00000000u;
goto P_0c06c790;
P_0c06c790: /* original 0e44, guest PC 0x0c06c790 */
if(!s->budget--) { s->failed_pc=0x0c06c790u; return 0; }
write(ram,r[14]+r[0],r[4],1);
goto P_0c06c792;
P_0c06c792: /* original 4408, guest PC 0x0c06c792 */
if(!s->budget--) { s->failed_pc=0x0c06c792u; return 0; }
r[4]<<=2;
goto P_0c06c794;
P_0c06c794: /* original d012, guest PC 0x0c06c794 */
if(!s->budget--) { s->failed_pc=0x0c06c794u; return 0; }
r[0]=read(ram,0x0c06c7e0u,4);
goto P_0c06c796;
P_0c06c796: /* original 034e, guest PC 0x0c06c796 */
if(!s->budget--) { s->failed_pc=0x0c06c796u; return 0; }
r[3]=read(ram,r[4]+r[0],4);
goto P_0c06c798;
P_0c06c798: /* original 2f32, guest PC 0x0c06c798 */
if(!s->budget--) { s->failed_pc=0x0c06c798u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c06c79a;
P_0c06c79a: /* original 7f04, guest PC 0x0c06c79a */
if(!s->budget--) { s->failed_pc=0x0c06c79au; return 0; }
r[15]+=0x00000004u;
goto P_0c06c79c;
P_0c06c79c: /* original 6233, guest PC 0x0c06c79c */
if(!s->budget--) { s->failed_pc=0x0c06c79cu; return 0; }
r[2]=r[3];
goto P_0c06c79e;
P_0c06c79e: /* original 422b, guest PC 0x0c06c79e */
if(!s->budget--) { s->failed_pc=0x0c06c79eu; return 0; }
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
P_0c06c7a0: /* original 6ef6, guest PC 0x0c06c7a0 */
if(!s->budget--) { s->failed_pc=0x0c06c7a0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c06c7a2;
P_0c06c7a2: /* original d30e, guest PC 0x0c06c7a2 */
if(!s->budget--) { s->failed_pc=0x0c06c7a2u; return 0; }
r[3]=read(ram,0x0c06c7dcu,4);
goto P_0c06c7a4;
P_0c06c7a4: /* original e23f, guest PC 0x0c06c7a4 */
if(!s->budget--) { s->failed_pc=0x0c06c7a4u; return 0; }
r[2]=0x0000003fu;
goto P_0c06c7a6;
P_0c06c7a6: /* original 9015, guest PC 0x0c06c7a6 */
if(!s->budget--) { s->failed_pc=0x0c06c7a6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06c7d4u,2);
goto P_0c06c7a8;
P_0c06c7a8: /* original e601, guest PC 0x0c06c7a8 */
if(!s->budget--) { s->failed_pc=0x0c06c7a8u; return 0; }
r[6]=0x00000001u;
goto P_0c06c7aa;
P_0c06c7aa: /* original d70b, guest PC 0x0c06c7aa */
if(!s->budget--) { s->failed_pc=0x0c06c7aau; return 0; }
r[7]=read(ram,0x0c06c7d8u,4);
goto P_0c06c7ac;
P_0c06c7ac: /* original 7ffc, guest PC 0x0c06c7ac */
if(!s->budget--) { s->failed_pc=0x0c06c7acu; return 0; }
r[15]+=0xfffffffcu;
goto P_0c06c7ae;
P_0c06c7ae: /* original 6532, guest PC 0x0c06c7ae */
if(!s->budget--) { s->failed_pc=0x0c06c7aeu; return 0; }
tmp=read(ram,r[3],4);
r[5]=tmp;
goto P_0c06c7b0;
P_0c06c7b0: /* original 047c, guest PC 0x0c06c7b0 */
if(!s->budget--) { s->failed_pc=0x0c06c7b0u; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[7]+r[0],1);
goto P_0c06c7b2;
P_0c06c7b2: /* original 2529, guest PC 0x0c06c7b2 */
if(!s->budget--) { s->failed_pc=0x0c06c7b2u; return 0; }
r[5]&=r[2];
goto P_0c06c7b4;
P_0c06c7b4: /* original 2558, guest PC 0x0c06c7b4 */
if(!s->budget--) { s->failed_pc=0x0c06c7b4u; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[5])==0)!=0);
goto P_0c06c7b6;
P_0c06c7b6: /* original 8f02, guest PC 0x0c06c7b6 */
if(!s->budget--) { s->failed_pc=0x0c06c7b6u; return 0; }
cond=r[17]&1u;
r[4]&=r[6];
if(!cond) { goto P_0c06c7be; }
goto P_0c06c7ba;
P_0c06c7b8: /* original 2469, guest PC 0x0c06c7b8 */
if(!s->budget--) { s->failed_pc=0x0c06c7b8u; return 0; }
r[4]&=r[6];
goto P_0c06c7ba;
P_0c06c7ba: /* original 246a, guest PC 0x0c06c7ba */
if(!s->budget--) { s->failed_pc=0x0c06c7bau; return 0; }
r[4]^=r[6];
goto P_0c06c7bc;
P_0c06c7bc: /* original 0744, guest PC 0x0c06c7bc */
if(!s->budget--) { s->failed_pc=0x0c06c7bcu; return 0; }
write(ram,r[7]+r[0],r[4],1);
goto P_0c06c7be;
P_0c06c7be: /* original d008, guest PC 0x0c06c7be */
if(!s->budget--) { s->failed_pc=0x0c06c7beu; return 0; }
r[0]=read(ram,0x0c06c7e0u,4);
goto P_0c06c7c0;
P_0c06c7c0: /* original 4408, guest PC 0x0c06c7c0 */
if(!s->budget--) { s->failed_pc=0x0c06c7c0u; return 0; }
r[4]<<=2;
goto P_0c06c7c2;
P_0c06c7c2: /* original 034e, guest PC 0x0c06c7c2 */
if(!s->budget--) { s->failed_pc=0x0c06c7c2u; return 0; }
r[3]=read(ram,r[4]+r[0],4);
goto P_0c06c7c4;
P_0c06c7c4: /* original 6233, guest PC 0x0c06c7c4 */
if(!s->budget--) { s->failed_pc=0x0c06c7c4u; return 0; }
r[2]=r[3];
goto P_0c06c7c6;
P_0c06c7c6: /* original 2f32, guest PC 0x0c06c7c6 */
if(!s->budget--) { s->failed_pc=0x0c06c7c6u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c06c7c8;
P_0c06c7c8: /* original 422b, guest PC 0x0c06c7c8 */
if(!s->budget--) { s->failed_pc=0x0c06c7c8u; return 0; }
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
P_0c06c7ca: /* original 7f04, guest PC 0x0c06c7ca */
if(!s->budget--) { s->failed_pc=0x0c06c7cau; return 0; }
r[15]+=0x00000004u;
if(!vf3_matrix_family(0x0c06c7ccu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c06c7ccu; return 0; } return 1;
P_0c07a7e8: /* original 6341, guest PC 0x0c07a7e8 */
if(!s->budget--) { s->failed_pc=0x0c07a7e8u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[4],2);
r[3]=tmp;
goto P_0c07a7ea;
P_0c07a7ea: /* original d676, guest PC 0x0c07a7ea */
if(!s->budget--) { s->failed_pc=0x0c07a7eau; return 0; }
r[6]=read(ram,0x0c07a9c4u,4);
goto P_0c07a7ec;
P_0c07a7ec: /* original 2631, guest PC 0x0c07a7ec */
if(!s->budget--) { s->failed_pc=0x0c07a7ecu; return 0; }
write(ram,r[6],r[3],2);
goto P_0c07a7ee;
P_0c07a7ee: /* original 8541, guest PC 0x0c07a7ee */
if(!s->budget--) { s->failed_pc=0x0c07a7eeu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+2,2);
goto P_0c07a7f0;
P_0c07a7f0: /* original 8161, guest PC 0x0c07a7f0 */
if(!s->budget--) { s->failed_pc=0x0c07a7f0u; return 0; }
write(ram,r[6]+2,r[0],2);
goto P_0c07a7f2;
P_0c07a7f2: /* original 5341, guest PC 0x0c07a7f2 */
if(!s->budget--) { s->failed_pc=0x0c07a7f2u; return 0; }
r[3]=read(ram,r[4]+4,4);
goto P_0c07a7f4;
P_0c07a7f4: /* original 1631, guest PC 0x0c07a7f4 */
if(!s->budget--) { s->failed_pc=0x0c07a7f4u; return 0; }
write(ram,r[6]+4,r[3],4);
goto P_0c07a7f6;
P_0c07a7f6: /* original 5242, guest PC 0x0c07a7f6 */
if(!s->budget--) { s->failed_pc=0x0c07a7f6u; return 0; }
r[2]=read(ram,r[4]+8,4);
goto P_0c07a7f8;
P_0c07a7f8: /* original 352c, guest PC 0x0c07a7f8 */
if(!s->budget--) { s->failed_pc=0x0c07a7f8u; return 0; }
r[5]+=r[2];
goto P_0c07a7fa;
P_0c07a7fa: /* original 1652, guest PC 0x0c07a7fa */
if(!s->budget--) { s->failed_pc=0x0c07a7fau; return 0; }
write(ram,r[6]+8,r[5],4);
goto P_0c07a7fc;
P_0c07a7fc: /* original 5343, guest PC 0x0c07a7fc */
if(!s->budget--) { s->failed_pc=0x0c07a7fcu; return 0; }
r[3]=read(ram,r[4]+12,4);
goto P_0c07a7fe;
P_0c07a7fe: /* original 1633, guest PC 0x0c07a7fe */
if(!s->budget--) { s->failed_pc=0x0c07a7feu; return 0; }
write(ram,r[6]+12,r[3],4);
goto P_0c07a800;
P_0c07a800: /* original d271, guest PC 0x0c07a800 */
if(!s->budget--) { s->failed_pc=0x0c07a800u; return 0; }
r[2]=read(ram,0x0c07a9c8u,4);
goto P_0c07a802;
P_0c07a802: /* original 422b, guest PC 0x0c07a802 */
if(!s->budget--) { s->failed_pc=0x0c07a802u; return 0; }
target=r[2];
r[4]=r[6];
code_base=target&0xff000000u;
switch(target&0x1fffffffu) {
case 0x0c03f5a0u: return vf3_matrix_family(0x0c03f5a0u,s,ram);
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
P_0c07a804: /* original 6463, guest PC 0x0c07a804 */
if(!s->budget--) { s->failed_pc=0x0c07a804u; return 0; }
r[4]=r[6];
goto P_0c07a806;
P_0c07a806: /* original 2fe6, guest PC 0x0c07a806 */
if(!s->budget--) { s->failed_pc=0x0c07a806u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07a808;
P_0c07a808: /* original 6e53, guest PC 0x0c07a808 */
if(!s->budget--) { s->failed_pc=0x0c07a808u; return 0; }
r[14]=r[5];
goto P_0c07a80a;
P_0c07a80a: /* original 2fd6, guest PC 0x0c07a80a */
if(!s->budget--) { s->failed_pc=0x0c07a80au; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07a80c;
P_0c07a80c: /* original 6d43, guest PC 0x0c07a80c */
if(!s->budget--) { s->failed_pc=0x0c07a80cu; return 0; }
r[13]=r[4];
goto P_0c07a80e;
P_0c07a80e: /* original 4f22, guest PC 0x0c07a80e */
if(!s->budget--) { s->failed_pc=0x0c07a80eu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c07a810;
P_0c07a810: /* original 5041, guest PC 0x0c07a810 */
if(!s->budget--) { s->failed_pc=0x0c07a810u; return 0; }
r[0]=read(ram,r[4]+4,4);
goto P_0c07a812;
P_0c07a812: /* original 88ff, guest PC 0x0c07a812 */
if(!s->budget--) { s->failed_pc=0x0c07a812u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xffffffffu)!=0);
goto P_0c07a814;
P_0c07a814: /* original 8904, guest PC 0x0c07a814 */
if(!s->budget--) { s->failed_pc=0x0c07a814u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07a820; }
goto P_0c07a816;
P_0c07a816: /* original 5242, guest PC 0x0c07a816 */
if(!s->budget--) { s->failed_pc=0x0c07a816u; return 0; }
r[2]=read(ram,r[4]+8,4);
goto P_0c07a818;
P_0c07a818: /* original 32ec, guest PC 0x0c07a818 */
if(!s->budget--) { s->failed_pc=0x0c07a818u; return 0; }
r[2]+=r[14];
goto P_0c07a81a;
P_0c07a81a: /* original 1422, guest PC 0x0c07a81a */
if(!s->budget--) { s->failed_pc=0x0c07a81au; return 0; }
write(ram,r[4]+8,r[2],4);
goto P_0c07a81c;
P_0c07a81c: /* original aff8, guest PC 0x0c07a81c */
if(!s->budget--) { s->failed_pc=0x0c07a81cu; return 0; }
r[4]+=0x00000010u;
goto P_0c07a810;
P_0c07a81e: /* original 7410, guest PC 0x0c07a81e */
if(!s->budget--) { s->failed_pc=0x0c07a81eu; return 0; }
r[4]+=0x00000010u;
goto P_0c07a820;
P_0c07a820: /* original d369, guest PC 0x0c07a820 */
if(!s->budget--) { s->failed_pc=0x0c07a820u; return 0; }
r[3]=read(ram,0x0c07a9c8u,4);
goto P_0c07a822;
P_0c07a822: /* original 430b, guest PC 0x0c07a822 */
if(!s->budget--) { s->failed_pc=0x0c07a822u; return 0; }
target=r[3];
r[16]=code_base|0x0c07a826u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07a826u) { target=s->pc; goto dispatch; }
goto P_0c07a826;
P_0c07a824: /* original 64d3, guest PC 0x0c07a824 */
if(!s->budget--) { s->failed_pc=0x0c07a824u; return 0; }
r[4]=r[13];
goto P_0c07a826;
P_0c07a826: /* original 64d3, guest PC 0x0c07a826 */
if(!s->budget--) { s->failed_pc=0x0c07a826u; return 0; }
r[4]=r[13];
goto P_0c07a828;
P_0c07a828: /* original 6503, guest PC 0x0c07a828 */
if(!s->budget--) { s->failed_pc=0x0c07a828u; return 0; }
r[5]=r[0];
goto P_0c07a82a;
P_0c07a82a: /* original 5041, guest PC 0x0c07a82a */
if(!s->budget--) { s->failed_pc=0x0c07a82au; return 0; }
r[0]=read(ram,r[4]+4,4);
goto P_0c07a82c;
P_0c07a82c: /* original 88ff, guest PC 0x0c07a82c */
if(!s->budget--) { s->failed_pc=0x0c07a82cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xffffffffu)!=0);
goto P_0c07a82e;
P_0c07a82e: /* original 8904, guest PC 0x0c07a82e */
if(!s->budget--) { s->failed_pc=0x0c07a82eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07a83a; }
goto P_0c07a830;
P_0c07a830: /* original 5342, guest PC 0x0c07a830 */
if(!s->budget--) { s->failed_pc=0x0c07a830u; return 0; }
r[3]=read(ram,r[4]+8,4);
goto P_0c07a832;
P_0c07a832: /* original 33e8, guest PC 0x0c07a832 */
if(!s->budget--) { s->failed_pc=0x0c07a832u; return 0; }
r[3]-=r[14];
goto P_0c07a834;
P_0c07a834: /* original 1432, guest PC 0x0c07a834 */
if(!s->budget--) { s->failed_pc=0x0c07a834u; return 0; }
write(ram,r[4]+8,r[3],4);
goto P_0c07a836;
P_0c07a836: /* original aff8, guest PC 0x0c07a836 */
if(!s->budget--) { s->failed_pc=0x0c07a836u; return 0; }
r[4]+=0x00000010u;
goto P_0c07a82a;
P_0c07a838: /* original 7410, guest PC 0x0c07a838 */
if(!s->budget--) { s->failed_pc=0x0c07a838u; return 0; }
r[4]+=0x00000010u;
goto P_0c07a83a;
P_0c07a83a: /* original 4f26, guest PC 0x0c07a83a */
if(!s->budget--) { s->failed_pc=0x0c07a83au; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c07a83c;
P_0c07a83c: /* original 6053, guest PC 0x0c07a83c */
if(!s->budget--) { s->failed_pc=0x0c07a83cu; return 0; }
r[0]=r[5];
goto P_0c07a83e;
P_0c07a83e: /* original 6df6, guest PC 0x0c07a83e */
if(!s->budget--) { s->failed_pc=0x0c07a83eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c07a840;
P_0c07a840: /* original 000b, guest PC 0x0c07a840 */
if(!s->budget--) { s->failed_pc=0x0c07a840u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c07a842: /* original 6ef6, guest PC 0x0c07a842 */
if(!s->budget--) { s->failed_pc=0x0c07a842u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c07a844u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c07a844u; return 0; } return 1;
P_0c07af6c: /* original 2fe6, guest PC 0x0c07af6c */
if(!s->budget--) { s->failed_pc=0x0c07af6cu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07af6e;
P_0c07af6e: /* original 4511, guest PC 0x0c07af6e */
if(!s->budget--) { s->failed_pc=0x0c07af6eu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[5]>=0)!=0);
goto P_0c07af70;
P_0c07af70: /* original 2fd6, guest PC 0x0c07af70 */
if(!s->budget--) { s->failed_pc=0x0c07af70u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07af72;
P_0c07af72: /* original 2fc6, guest PC 0x0c07af72 */
if(!s->budget--) { s->failed_pc=0x0c07af72u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07af74;
P_0c07af74: /* original 2fb6, guest PC 0x0c07af74 */
if(!s->budget--) { s->failed_pc=0x0c07af74u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07af76;
P_0c07af76: /* original 2fa6, guest PC 0x0c07af76 */
if(!s->budget--) { s->failed_pc=0x0c07af76u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07af78;
P_0c07af78: /* original 4f22, guest PC 0x0c07af78 */
if(!s->budget--) { s->failed_pc=0x0c07af78u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c07af7a;
P_0c07af7a: /* original d323, guest PC 0x0c07af7a */
if(!s->budget--) { s->failed_pc=0x0c07af7au; return 0; }
r[3]=read(ram,0x0c07b008u,4);
goto P_0c07af7c;
P_0c07af7c: /* original dd21, guest PC 0x0c07af7c */
if(!s->budget--) { s->failed_pc=0x0c07af7cu; return 0; }
r[13]=read(ram,0x0c07b004u,4);
goto P_0c07af7e;
P_0c07af7e: /* original 7ffc, guest PC 0x0c07af7e */
if(!s->budget--) { s->failed_pc=0x0c07af7eu; return 0; }
r[15]+=0xfffffffcu;
goto P_0c07af80;
P_0c07af80: /* original 2f32, guest PC 0x0c07af80 */
if(!s->budget--) { s->failed_pc=0x0c07af80u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c07af82;
P_0c07af82: /* original 5e46, guest PC 0x0c07af82 */
if(!s->budget--) { s->failed_pc=0x0c07af82u; return 0; }
r[14]=read(ram,r[4]+24,4);
goto P_0c07af84;
P_0c07af84: /* original 6ce3, guest PC 0x0c07af84 */
if(!s->budget--) { s->failed_pc=0x0c07af84u; return 0; }
r[12]=r[14];
goto P_0c07af86;
P_0c07af86: /* original 8d0f, guest PC 0x0c07af86 */
if(!s->budget--) { s->failed_pc=0x0c07af86u; return 0; }
cond=r[17]&1u;
r[12]+=0x00000001u;
if(cond) { goto P_0c07afa8; }
goto P_0c07af8a;
P_0c07af88: /* original 7c01, guest PC 0x0c07af88 */
if(!s->budget--) { s->failed_pc=0x0c07af88u; return 0; }
r[12]+=0x00000001u;
goto P_0c07af8a;
P_0c07af8a: /* original 60e3, guest PC 0x0c07af8a */
if(!s->budget--) { s->failed_pc=0x0c07af8au; return 0; }
r[0]=r[14];
goto P_0c07af8c;
P_0c07af8c: /* original 882c, guest PC 0x0c07af8c */
if(!s->budget--) { s->failed_pc=0x0c07af8cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000002cu)!=0);
goto P_0c07af8e;
P_0c07af8e: /* original 8902, guest PC 0x0c07af8e */
if(!s->budget--) { s->failed_pc=0x0c07af8eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07af96; }
goto P_0c07af90;
P_0c07af90: /* original 60e3, guest PC 0x0c07af90 */
if(!s->budget--) { s->failed_pc=0x0c07af90u; return 0; }
r[0]=r[14];
goto P_0c07af92;
P_0c07af92: /* original 8834, guest PC 0x0c07af92 */
if(!s->budget--) { s->failed_pc=0x0c07af92u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000034u)!=0);
goto P_0c07af94;
P_0c07af94: /* original 8b03, guest PC 0x0c07af94 */
if(!s->budget--) { s->failed_pc=0x0c07af94u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07af9e; }
goto P_0c07af96;
P_0c07af96: /* original 60c3, guest PC 0x0c07af96 */
if(!s->budget--) { s->failed_pc=0x0c07af96u; return 0; }
r[0]=r[12];
goto P_0c07af98;
P_0c07af98: /* original e300, guest PC 0x0c07af98 */
if(!s->budget--) { s->failed_pc=0x0c07af98u; return 0; }
r[3]=0x00000000u;
goto P_0c07af9a;
P_0c07af9a: /* original 4000, guest PC 0x0c07af9a */
if(!s->budget--) { s->failed_pc=0x0c07af9au; return 0; }
r[17]=(r[17]&~1u)|((r[0]>>31)!=0);
r[0]<<=1;
goto P_0c07af9c;
P_0c07af9c: /* original 0d35, guest PC 0x0c07af9c */
if(!s->budget--) { s->failed_pc=0x0c07af9cu; return 0; }
write(ram,r[13]+r[0],r[3],2);
goto P_0c07af9e;
P_0c07af9e: /* original 60e3, guest PC 0x0c07af9e */
if(!s->budget--) { s->failed_pc=0x0c07af9eu; return 0; }
r[0]=r[14];
goto P_0c07afa0;
P_0c07afa0: /* original e300, guest PC 0x0c07afa0 */
if(!s->budget--) { s->failed_pc=0x0c07afa0u; return 0; }
r[3]=0x00000000u;
goto P_0c07afa2;
P_0c07afa2: /* original 4000, guest PC 0x0c07afa2 */
if(!s->budget--) { s->failed_pc=0x0c07afa2u; return 0; }
r[17]=(r[17]&~1u)|((r[0]>>31)!=0);
r[0]<<=1;
goto P_0c07afa4;
P_0c07afa4: /* original a01f, guest PC 0x0c07afa4 */
if(!s->budget--) { s->failed_pc=0x0c07afa4u; return 0; }
write(ram,r[13]+r[0],r[3],2);
goto P_0c07afe6;
P_0c07afa6: /* original 0d35, guest PC 0x0c07afa6 */
if(!s->budget--) { s->failed_pc=0x0c07afa6u; return 0; }
write(ram,r[13]+r[0],r[3],2);
goto P_0c07afa8;
P_0c07afa8: /* original 60e3, guest PC 0x0c07afa8 */
if(!s->budget--) { s->failed_pc=0x0c07afa8u; return 0; }
r[0]=r[14];
goto P_0c07afaa;
P_0c07afaa: /* original db19, guest PC 0x0c07afaa */
if(!s->budget--) { s->failed_pc=0x0c07afaau; return 0; }
r[11]=read(ram,0x0c07b010u,4);
goto P_0c07afac;
P_0c07afac: /* original da17, guest PC 0x0c07afac */
if(!s->budget--) { s->failed_pc=0x0c07afacu; return 0; }
r[10]=read(ram,0x0c07b00cu,4);
goto P_0c07afae;
P_0c07afae: /* original 882c, guest PC 0x0c07afae */
if(!s->budget--) { s->failed_pc=0x0c07afaeu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000002cu)!=0);
goto P_0c07afb0;
P_0c07afb0: /* original 8b06, guest PC 0x0c07afb0 */
if(!s->budget--) { s->failed_pc=0x0c07afb0u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07afc0; }
goto P_0c07afb2;
P_0c07afb2: /* original 4a0b, guest PC 0x0c07afb2 */
if(!s->budget--) { s->failed_pc=0x0c07afb2u; return 0; }
target=r[10];
r[16]=code_base|0x0c07afb6u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07afb6u) { target=s->pc; goto dispatch; }
goto P_0c07afb6;
P_0c07afb4: /* original 64e3, guest PC 0x0c07afb4 */
if(!s->budget--) { s->failed_pc=0x0c07afb4u; return 0; }
r[4]=r[14];
goto P_0c07afb6;
P_0c07afb6: /* original d417, guest PC 0x0c07afb6 */
if(!s->budget--) { s->failed_pc=0x0c07afb6u; return 0; }
r[4]=read(ram,0x0c07b014u,4);
goto P_0c07afb8;
P_0c07afb8: /* original bc25, guest PC 0x0c07afb8 */
if(!s->budget--) { s->failed_pc=0x0c07afb8u; return 0; }
target=code_base|0x0c07a806u; r[16]=code_base|0x0c07afbcu;
tmp=read(ram,r[11],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07afbcu) { target=s->pc; goto dispatch; }
goto P_0c07afbc;
P_0c07afba: /* original 65b2, guest PC 0x0c07afba */
if(!s->budget--) { s->failed_pc=0x0c07afbau; return 0; }
tmp=read(ram,r[11],4);
r[5]=tmp;
goto P_0c07afbc;
P_0c07afbc: /* original a007, guest PC 0x0c07afbc */
if(!s->budget--) { s->failed_pc=0x0c07afbcu; return 0; }
goto P_0c07afce;
P_0c07afbe: /* original 0009, guest PC 0x0c07afbe */
if(!s->budget--) { s->failed_pc=0x0c07afbeu; return 0; }
goto P_0c07afc0;
P_0c07afc0: /* original 8834, guest PC 0x0c07afc0 */
if(!s->budget--) { s->failed_pc=0x0c07afc0u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000034u)!=0);
goto P_0c07afc2;
P_0c07afc2: /* original 8b08, guest PC 0x0c07afc2 */
if(!s->budget--) { s->failed_pc=0x0c07afc2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07afd6; }
goto P_0c07afc4;
P_0c07afc4: /* original 4a0b, guest PC 0x0c07afc4 */
if(!s->budget--) { s->failed_pc=0x0c07afc4u; return 0; }
target=r[10];
r[16]=code_base|0x0c07afc8u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07afc8u) { target=s->pc; goto dispatch; }
goto P_0c07afc8;
P_0c07afc6: /* original 64e3, guest PC 0x0c07afc6 */
if(!s->budget--) { s->failed_pc=0x0c07afc6u; return 0; }
r[4]=r[14];
goto P_0c07afc8;
P_0c07afc8: /* original d413, guest PC 0x0c07afc8 */
if(!s->budget--) { s->failed_pc=0x0c07afc8u; return 0; }
r[4]=read(ram,0x0c07b018u,4);
goto P_0c07afca;
P_0c07afca: /* original bc1c, guest PC 0x0c07afca */
if(!s->budget--) { s->failed_pc=0x0c07afcau; return 0; }
target=code_base|0x0c07a806u; r[16]=code_base|0x0c07afceu;
tmp=read(ram,r[11],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07afceu) { target=s->pc; goto dispatch; }
goto P_0c07afce;
P_0c07afcc: /* original 65b2, guest PC 0x0c07afcc */
if(!s->budget--) { s->failed_pc=0x0c07afccu; return 0; }
tmp=read(ram,r[11],4);
r[5]=tmp;
goto P_0c07afce;
P_0c07afce: /* original 60c3, guest PC 0x0c07afce */
if(!s->budget--) { s->failed_pc=0x0c07afceu; return 0; }
r[0]=r[12];
goto P_0c07afd0;
P_0c07afd0: /* original 4000, guest PC 0x0c07afd0 */
if(!s->budget--) { s->failed_pc=0x0c07afd0u; return 0; }
r[17]=(r[17]&~1u)|((r[0]>>31)!=0);
r[0]<<=1;
goto P_0c07afd2;
P_0c07afd2: /* original a005, guest PC 0x0c07afd2 */
if(!s->budget--) { s->failed_pc=0x0c07afd2u; return 0; }
write(ram,r[13]+r[0],r[12],2);
goto P_0c07afe0;
P_0c07afd4: /* original 0dc5, guest PC 0x0c07afd4 */
if(!s->budget--) { s->failed_pc=0x0c07afd4u; return 0; }
write(ram,r[13]+r[0],r[12],2);
goto P_0c07afd6;
P_0c07afd6: /* original 4a0b, guest PC 0x0c07afd6 */
if(!s->budget--) { s->failed_pc=0x0c07afd6u; return 0; }
target=r[10];
r[16]=code_base|0x0c07afdau;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07afdau) { target=s->pc; goto dispatch; }
goto P_0c07afda;
P_0c07afd8: /* original 64e3, guest PC 0x0c07afd8 */
if(!s->budget--) { s->failed_pc=0x0c07afd8u; return 0; }
r[4]=r[14];
goto P_0c07afda;
P_0c07afda: /* original d410, guest PC 0x0c07afda */
if(!s->budget--) { s->failed_pc=0x0c07afdau; return 0; }
r[4]=read(ram,0x0c07b01cu,4);
goto P_0c07afdc;
P_0c07afdc: /* original bc04, guest PC 0x0c07afdc */
if(!s->budget--) { s->failed_pc=0x0c07afdcu; return 0; }
target=code_base|0x0c07a7e8u; r[16]=code_base|0x0c07afe0u;
tmp=read(ram,r[11],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07afe0u) { target=s->pc; goto dispatch; }
goto P_0c07afe0;
P_0c07afde: /* original 65b2, guest PC 0x0c07afde */
if(!s->budget--) { s->failed_pc=0x0c07afdeu; return 0; }
tmp=read(ram,r[11],4);
r[5]=tmp;
goto P_0c07afe0;
P_0c07afe0: /* original 60e3, guest PC 0x0c07afe0 */
if(!s->budget--) { s->failed_pc=0x0c07afe0u; return 0; }
r[0]=r[14];
goto P_0c07afe2;
P_0c07afe2: /* original 4000, guest PC 0x0c07afe2 */
if(!s->budget--) { s->failed_pc=0x0c07afe2u; return 0; }
r[17]=(r[17]&~1u)|((r[0]>>31)!=0);
r[0]<<=1;
goto P_0c07afe4;
P_0c07afe4: /* original 0de5, guest PC 0x0c07afe4 */
if(!s->budget--) { s->failed_pc=0x0c07afe4u; return 0; }
write(ram,r[13]+r[0],r[14],2);
goto P_0c07afe6;
P_0c07afe6: /* original 63f2, guest PC 0x0c07afe6 */
if(!s->budget--) { s->failed_pc=0x0c07afe6u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c07afe8;
P_0c07afe8: /* original 7f04, guest PC 0x0c07afe8 */
if(!s->budget--) { s->failed_pc=0x0c07afe8u; return 0; }
r[15]+=0x00000004u;
goto P_0c07afea;
P_0c07afea: /* original 4f26, guest PC 0x0c07afea */
if(!s->budget--) { s->failed_pc=0x0c07afeau; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c07afec;
P_0c07afec: /* original 9008, guest PC 0x0c07afec */
if(!s->budget--) { s->failed_pc=0x0c07afecu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07b000u,2);
goto P_0c07afee;
P_0c07afee: /* original e2ff, guest PC 0x0c07afee */
if(!s->budget--) { s->failed_pc=0x0c07afeeu; return 0; }
r[2]=0xffffffffu;
goto P_0c07aff0;
P_0c07aff0: /* original 0326, guest PC 0x0c07aff0 */
if(!s->budget--) { s->failed_pc=0x0c07aff0u; return 0; }
write(ram,r[3]+r[0],r[2],4);
goto P_0c07aff2;
P_0c07aff2: /* original e000, guest PC 0x0c07aff2 */
if(!s->budget--) { s->failed_pc=0x0c07aff2u; return 0; }
r[0]=0x00000000u;
goto P_0c07aff4;
P_0c07aff4: /* original 6af6, guest PC 0x0c07aff4 */
if(!s->budget--) { s->failed_pc=0x0c07aff4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c07aff6;
P_0c07aff6: /* original 6bf6, guest PC 0x0c07aff6 */
if(!s->budget--) { s->failed_pc=0x0c07aff6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c07aff8;
P_0c07aff8: /* original 6cf6, guest PC 0x0c07aff8 */
if(!s->budget--) { s->failed_pc=0x0c07aff8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c07affa;
P_0c07affa: /* original 6df6, guest PC 0x0c07affa */
if(!s->budget--) { s->failed_pc=0x0c07affau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c07affc;
P_0c07affc: /* original 000b, guest PC 0x0c07affc */
if(!s->budget--) { s->failed_pc=0x0c07affcu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c07affe: /* original 6ef6, guest PC 0x0c07affe */
if(!s->budget--) { s->failed_pc=0x0c07affeu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c07b000u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c07b000u; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
