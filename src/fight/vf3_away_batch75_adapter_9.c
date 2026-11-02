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
int vf3_away_batch75_adapter_9(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c09f6d0u: goto P_0c09f6d0;
case 0x0c09f6d2u: goto P_0c09f6d2;
case 0x0c09f6d4u: goto P_0c09f6d4;
case 0x0c09f6d6u: goto P_0c09f6d6;
case 0x0c09f6d8u: goto P_0c09f6d8;
case 0x0c09f6dau: goto P_0c09f6da;
case 0x0c09f6dcu: goto P_0c09f6dc;
case 0x0c09f6deu: goto P_0c09f6de;
case 0x0c09f6e0u: goto P_0c09f6e0;
case 0x0c09f6e2u: goto P_0c09f6e2;
case 0x0c09f6e4u: goto P_0c09f6e4;
case 0x0c09f6e6u: goto P_0c09f6e6;
case 0x0c09f6e8u: goto P_0c09f6e8;
case 0x0c09f6eau: goto P_0c09f6ea;
case 0x0c09f6ecu: goto P_0c09f6ec;
case 0x0c09f6eeu: goto P_0c09f6ee;
case 0x0c09f6f0u: goto P_0c09f6f0;
case 0x0c09f6f2u: goto P_0c09f6f2;
case 0x0c09f6f4u: goto P_0c09f6f4;
case 0x0c09f6f6u: goto P_0c09f6f6;
case 0x0c09f6f8u: goto P_0c09f6f8;
case 0x0c09f6fau: goto P_0c09f6fa;
case 0x0c09f6fcu: goto P_0c09f6fc;
case 0x0c09f6feu: goto P_0c09f6fe;
case 0x0c09f700u: goto P_0c09f700;
case 0x0c09f702u: goto P_0c09f702;
case 0x0c09f704u: goto P_0c09f704;
case 0x0c09f706u: goto P_0c09f706;
case 0x0c09f708u: goto P_0c09f708;
case 0x0c09f70au: goto P_0c09f70a;
case 0x0c09f70cu: goto P_0c09f70c;
case 0x0c09f70eu: goto P_0c09f70e;
case 0x0c09f710u: goto P_0c09f710;
case 0x0c09f712u: goto P_0c09f712;
case 0x0c09f714u: goto P_0c09f714;
case 0x0c09f716u: goto P_0c09f716;
case 0x0c09f718u: goto P_0c09f718;
case 0x0c09f71au: goto P_0c09f71a;
case 0x0c09f71cu: goto P_0c09f71c;
case 0x0c09f71eu: goto P_0c09f71e;
case 0x0c09f720u: goto P_0c09f720;
case 0x0c09f722u: goto P_0c09f722;
case 0x0c09f724u: goto P_0c09f724;
case 0x0c09f726u: goto P_0c09f726;
case 0x0c09f728u: goto P_0c09f728;
case 0x0c09f72au: goto P_0c09f72a;
case 0x0c09f72cu: goto P_0c09f72c;
case 0x0c09f72eu: goto P_0c09f72e;
case 0x0c09f730u: goto P_0c09f730;
case 0x0c09f732u: goto P_0c09f732;
case 0x0c09f734u: goto P_0c09f734;
case 0x0c09f736u: goto P_0c09f736;
case 0x0c09f738u: goto P_0c09f738;
case 0x0c09f73au: goto P_0c09f73a;
case 0x0c09f73cu: goto P_0c09f73c;
case 0x0c09f73eu: goto P_0c09f73e;
case 0x0c09f740u: goto P_0c09f740;
case 0x0c09f742u: goto P_0c09f742;
case 0x0c09f744u: goto P_0c09f744;
case 0x0c09f746u: goto P_0c09f746;
case 0x0c09f748u: goto P_0c09f748;
case 0x0c09f74au: goto P_0c09f74a;
case 0x0c09f74cu: goto P_0c09f74c;
case 0x0c09f74eu: goto P_0c09f74e;
case 0x0c09f750u: goto P_0c09f750;
case 0x0c09f752u: goto P_0c09f752;
case 0x0c09f754u: goto P_0c09f754;
case 0x0c09f756u: goto P_0c09f756;
case 0x0c09f758u: goto P_0c09f758;
case 0x0c09f75au: goto P_0c09f75a;
case 0x0c09f75cu: goto P_0c09f75c;
case 0x0c09f75eu: goto P_0c09f75e;
case 0x0c09f760u: goto P_0c09f760;
case 0x0c09f762u: goto P_0c09f762;
case 0x0c09f764u: goto P_0c09f764;
case 0x0c09f766u: goto P_0c09f766;
case 0x0c09f768u: goto P_0c09f768;
case 0x0c09f76au: goto P_0c09f76a;
case 0x0c09f76cu: goto P_0c09f76c;
case 0x0c09f76eu: goto P_0c09f76e;
case 0x0c09f770u: goto P_0c09f770;
case 0x0c09f772u: goto P_0c09f772;
case 0x0c09f774u: goto P_0c09f774;
case 0x0c09f776u: goto P_0c09f776;
case 0x0c09f778u: goto P_0c09f778;
case 0x0c09f77au: goto P_0c09f77a;
case 0x0c09f77cu: goto P_0c09f77c;
case 0x0c09f77eu: goto P_0c09f77e;
case 0x0c09f780u: goto P_0c09f780;
case 0x0c09f782u: goto P_0c09f782;
case 0x0c09f784u: goto P_0c09f784;
case 0x0c09f786u: goto P_0c09f786;
case 0x0c09f788u: goto P_0c09f788;
case 0x0c09f78au: goto P_0c09f78a;
case 0x0c09f78cu: goto P_0c09f78c;
case 0x0c09f78eu: goto P_0c09f78e;
case 0x0c09f790u: goto P_0c09f790;
case 0x0c09f792u: goto P_0c09f792;
case 0x0c09f794u: goto P_0c09f794;
case 0x0c09f796u: goto P_0c09f796;
case 0x0c09f798u: goto P_0c09f798;
case 0x0c09f79au: goto P_0c09f79a;
case 0x0c09f79cu: goto P_0c09f79c;
case 0x0c09f79eu: goto P_0c09f79e;
case 0x0c09f7a0u: goto P_0c09f7a0;
case 0x0c09f7a2u: goto P_0c09f7a2;
case 0x0c09f7a4u: goto P_0c09f7a4;
case 0x0c09f7a6u: goto P_0c09f7a6;
case 0x0c09f7a8u: goto P_0c09f7a8;
case 0x0c09f7aau: goto P_0c09f7aa;
case 0x0c09f7acu: goto P_0c09f7ac;
case 0x0c09f7aeu: goto P_0c09f7ae;
case 0x0c09f7b0u: goto P_0c09f7b0;
case 0x0c09f7b2u: goto P_0c09f7b2;
case 0x0c09f7d4u: goto P_0c09f7d4;
case 0x0c09f7d6u: goto P_0c09f7d6;
case 0x0c09f7d8u: goto P_0c09f7d8;
case 0x0c09f7dau: goto P_0c09f7da;
case 0x0c09f7dcu: goto P_0c09f7dc;
case 0x0c09f7deu: goto P_0c09f7de;
case 0x0c09f7e0u: goto P_0c09f7e0;
case 0x0c09f7e2u: goto P_0c09f7e2;
case 0x0c09f7e4u: goto P_0c09f7e4;
case 0x0c09f7e6u: goto P_0c09f7e6;
case 0x0c09f7e8u: goto P_0c09f7e8;
case 0x0c09f7eau: goto P_0c09f7ea;
case 0x0c09f7ecu: goto P_0c09f7ec;
case 0x0c09f7eeu: goto P_0c09f7ee;
case 0x0c09f7f0u: goto P_0c09f7f0;
case 0x0c09f7f2u: goto P_0c09f7f2;
case 0x0c09f7f4u: goto P_0c09f7f4;
case 0x0c09f7f6u: goto P_0c09f7f6;
case 0x0c09f7f8u: goto P_0c09f7f8;
case 0x0c09f7fau: goto P_0c09f7fa;
case 0x0c09f7fcu: goto P_0c09f7fc;
case 0x0c09f7feu: goto P_0c09f7fe;
case 0x0c09f800u: goto P_0c09f800;
case 0x0c09f802u: goto P_0c09f802;
case 0x0c09f804u: goto P_0c09f804;
case 0x0c09f806u: goto P_0c09f806;
case 0x0c09f808u: goto P_0c09f808;
case 0x0c09f80au: goto P_0c09f80a;
case 0x0c09f80cu: goto P_0c09f80c;
case 0x0c09f80eu: goto P_0c09f80e;
case 0x0c09f810u: goto P_0c09f810;
case 0x0c09f812u: goto P_0c09f812;
case 0x0c09f814u: goto P_0c09f814;
case 0x0c09f816u: goto P_0c09f816;
case 0x0c09f818u: goto P_0c09f818;
case 0x0c09f984u: goto P_0c09f984;
case 0x0c09f986u: goto P_0c09f986;
case 0x0c09f988u: goto P_0c09f988;
case 0x0c09f98au: goto P_0c09f98a;
case 0x0c09f98cu: goto P_0c09f98c;
case 0x0c09f98eu: goto P_0c09f98e;
case 0x0c09f990u: goto P_0c09f990;
case 0x0c09f992u: goto P_0c09f992;
case 0x0c09f994u: goto P_0c09f994;
case 0x0c09f996u: goto P_0c09f996;
case 0x0c09f998u: goto P_0c09f998;
case 0x0c09f99au: goto P_0c09f99a;
case 0x0c09f99cu: goto P_0c09f99c;
case 0x0c09f99eu: goto P_0c09f99e;
case 0x0c09f9a0u: goto P_0c09f9a0;
case 0x0c09f9a2u: goto P_0c09f9a2;
case 0x0c09f9a4u: goto P_0c09f9a4;
case 0x0c09f9a6u: goto P_0c09f9a6;
case 0x0c09f9a8u: goto P_0c09f9a8;
case 0x0c09f9aau: goto P_0c09f9aa;
case 0x0c09f9acu: goto P_0c09f9ac;
case 0x0c09f9aeu: goto P_0c09f9ae;
case 0x0c09f9b0u: goto P_0c09f9b0;
case 0x0c09f9b2u: goto P_0c09f9b2;
case 0x0c09f9b4u: goto P_0c09f9b4;
case 0x0c09f9b6u: goto P_0c09f9b6;
case 0x0c09f9b8u: goto P_0c09f9b8;
case 0x0c09f9bau: goto P_0c09f9ba;
case 0x0c09f9bcu: goto P_0c09f9bc;
case 0x0c09f9beu: goto P_0c09f9be;
case 0x0c09f9c0u: goto P_0c09f9c0;
case 0x0c09f9c2u: goto P_0c09f9c2;
case 0x0c09f9c4u: goto P_0c09f9c4;
case 0x0c09f9c6u: goto P_0c09f9c6;
case 0x0c09f9c8u: goto P_0c09f9c8;
case 0x0c09f9cau: goto P_0c09f9ca;
case 0x0c09f9ccu: goto P_0c09f9cc;
case 0x0c09f9ceu: goto P_0c09f9ce;
case 0x0c09f9d0u: goto P_0c09f9d0;
case 0x0c09f9d2u: goto P_0c09f9d2;
case 0x0c09f9d4u: goto P_0c09f9d4;
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
default: return vf3_matrix_family(target,s,ram);
}
P_0c09f6d0: /* original 2fe6, guest PC 0x0c09f6d0 */
if(!s->budget--) { s->failed_pc=0x0c09f6d0u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09f6d2;
P_0c09f6d2: /* original 2fd6, guest PC 0x0c09f6d2 */
if(!s->budget--) { s->failed_pc=0x0c09f6d2u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09f6d4;
P_0c09f6d4: /* original ed0e, guest PC 0x0c09f6d4 */
if(!s->budget--) { s->failed_pc=0x0c09f6d4u; return 0; }
r[13]=0x0000000eu;
goto P_0c09f6d6;
P_0c09f6d6: /* original 2fc6, guest PC 0x0c09f6d6 */
if(!s->budget--) { s->failed_pc=0x0c09f6d6u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09f6d8;
P_0c09f6d8: /* original 9c6d, guest PC 0x0c09f6d8 */
if(!s->budget--) { s->failed_pc=0x0c09f6d8u; return 0; }
r[12]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09f7b6u,2);
goto P_0c09f6da;
P_0c09f6da: /* original 9e6b, guest PC 0x0c09f6da */
if(!s->budget--) { s->failed_pc=0x0c09f6dau; return 0; }
r[14]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09f7b4u,2);
goto P_0c09f6dc;
P_0c09f6dc: /* original 4f22, guest PC 0x0c09f6dc */
if(!s->budget--) { s->failed_pc=0x0c09f6dcu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c09f6de;
P_0c09f6de: /* original 3c4c, guest PC 0x0c09f6de */
if(!s->budget--) { s->failed_pc=0x0c09f6deu; return 0; }
r[12]+=r[4];
goto P_0c09f6e0;
P_0c09f6e0: /* original 3e4c, guest PC 0x0c09f6e0 */
if(!s->budget--) { s->failed_pc=0x0c09f6e0u; return 0; }
r[14]+=r[4];
goto P_0c09f6e2;
P_0c09f6e2: /* original 65c3, guest PC 0x0c09f6e2 */
if(!s->budget--) { s->failed_pc=0x0c09f6e2u; return 0; }
r[5]=r[12];
goto P_0c09f6e4;
P_0c09f6e4: /* original b00a, guest PC 0x0c09f6e4 */
if(!s->budget--) { s->failed_pc=0x0c09f6e4u; return 0; }
target=code_base|0x0c09f6fcu; r[16]=code_base|0x0c09f6e8u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09f6e8u) { target=s->pc; goto dispatch; }
goto P_0c09f6e8;
P_0c09f6e6: /* original 64e3, guest PC 0x0c09f6e6 */
if(!s->budget--) { s->failed_pc=0x0c09f6e6u; return 0; }
r[4]=r[14];
goto P_0c09f6e8;
P_0c09f6e8: /* original 7dff, guest PC 0x0c09f6e8 */
if(!s->budget--) { s->failed_pc=0x0c09f6e8u; return 0; }
r[13]+=0xffffffffu;
goto P_0c09f6ea;
P_0c09f6ea: /* original 4d15, guest PC 0x0c09f6ea */
if(!s->budget--) { s->failed_pc=0x0c09f6eau; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[13]>0)!=0);
goto P_0c09f6ec;
P_0c09f6ec: /* original 7e0c, guest PC 0x0c09f6ec */
if(!s->budget--) { s->failed_pc=0x0c09f6ecu; return 0; }
r[14]+=0x0000000cu;
goto P_0c09f6ee;
P_0c09f6ee: /* original 8df8, guest PC 0x0c09f6ee */
if(!s->budget--) { s->failed_pc=0x0c09f6eeu; return 0; }
cond=r[17]&1u;
r[12]+=0x0000000cu;
if(cond) { goto P_0c09f6e2; }
goto P_0c09f6f2;
P_0c09f6f0: /* original 7c0c, guest PC 0x0c09f6f0 */
if(!s->budget--) { s->failed_pc=0x0c09f6f0u; return 0; }
r[12]+=0x0000000cu;
goto P_0c09f6f2;
P_0c09f6f2: /* original 4f26, guest PC 0x0c09f6f2 */
if(!s->budget--) { s->failed_pc=0x0c09f6f2u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c09f6f4;
P_0c09f6f4: /* original 6cf6, guest PC 0x0c09f6f4 */
if(!s->budget--) { s->failed_pc=0x0c09f6f4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c09f6f6;
P_0c09f6f6: /* original 6df6, guest PC 0x0c09f6f6 */
if(!s->budget--) { s->failed_pc=0x0c09f6f6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c09f6f8;
P_0c09f6f8: /* original 000b, guest PC 0x0c09f6f8 */
if(!s->budget--) { s->failed_pc=0x0c09f6f8u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c09f6fa: /* original 6ef6, guest PC 0x0c09f6fa */
if(!s->budget--) { s->failed_pc=0x0c09f6fau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c09f6fc;
P_0c09f6fc: /* original c72e, guest PC 0x0c09f6fc */
if(!s->budget--) { s->failed_pc=0x0c09f6fcu; return 0; }
r[0]=code_base|0x0009f7b8u;
goto P_0c09f6fe;
P_0c09f6fe: /* original ffdb, guest PC 0x0c09f6fe */
if(!s->budget--) { s->failed_pc=0x0c09f6feu; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,13,r[15]);
goto P_0c09f700;
P_0c09f700: /* original f908, guest PC 0x0c09f700 */
if(!s->budget--) { s->failed_pc=0x0c09f700u; return 0; }
vf3_matrix_load(s,ram,9,r[0]);
goto P_0c09f702;
P_0c09f702: /* original c72e, guest PC 0x0c09f702 */
if(!s->budget--) { s->failed_pc=0x0c09f702u; return 0; }
r[0]=code_base|0x0009f7bcu;
goto P_0c09f704;
P_0c09f704: /* original fa08, guest PC 0x0c09f704 */
if(!s->budget--) { s->failed_pc=0x0c09f704u; return 0; }
vf3_matrix_load(s,ram,10,r[0]);
goto P_0c09f706;
P_0c09f706: /* original c72e, guest PC 0x0c09f706 */
if(!s->budget--) { s->failed_pc=0x0c09f706u; return 0; }
r[0]=code_base|0x0009f7c0u;
goto P_0c09f708;
P_0c09f708: /* original fb08, guest PC 0x0c09f708 */
if(!s->budget--) { s->failed_pc=0x0c09f708u; return 0; }
vf3_matrix_load(s,ram,11,r[0]);
goto P_0c09f70a;
P_0c09f70a: /* original c72e, guest PC 0x0c09f70a */
if(!s->budget--) { s->failed_pc=0x0c09f70au; return 0; }
r[0]=code_base|0x0009f7c4u;
goto P_0c09f70c;
P_0c09f70c: /* original f808, guest PC 0x0c09f70c */
if(!s->budget--) { s->failed_pc=0x0c09f70cu; return 0; }
vf3_matrix_load(s,ram,8,r[0]);
goto P_0c09f70e;
P_0c09f70e: /* original c72e, guest PC 0x0c09f70e */
if(!s->budget--) { s->failed_pc=0x0c09f70eu; return 0; }
r[0]=code_base|0x0009f7c8u;
goto P_0c09f710;
P_0c09f710: /* original f708, guest PC 0x0c09f710 */
if(!s->budget--) { s->failed_pc=0x0c09f710u; return 0; }
vf3_matrix_load(s,ram,7,r[0]);
goto P_0c09f712;
P_0c09f712: /* original e004, guest PC 0x0c09f712 */
if(!s->budget--) { s->failed_pc=0x0c09f712u; return 0; }
r[0]=0x00000004u;
goto P_0c09f714;
P_0c09f714: /* original f348, guest PC 0x0c09f714 */
if(!s->budget--) { s->failed_pc=0x0c09f714u; return 0; }
vf3_matrix_load(s,ram,3,r[4]);
goto P_0c09f716;
P_0c09f716: /* original 7ff4, guest PC 0x0c09f716 */
if(!s->budget--) { s->failed_pc=0x0c09f716u; return 0; }
r[15]+=0xfffffff4u;
goto P_0c09f718;
P_0c09f718: /* original 6653, guest PC 0x0c09f718 */
if(!s->budget--) { s->failed_pc=0x0c09f718u; return 0; }
r[6]=r[5];
goto P_0c09f71a;
P_0c09f71a: /* original 7604, guest PC 0x0c09f71a */
if(!s->budget--) { s->failed_pc=0x0c09f71au; return 0; }
r[6]+=0x00000004u;
goto P_0c09f71c;
P_0c09f71c: /* original ff37, guest PC 0x0c09f71c */
if(!s->budget--) { s->failed_pc=0x0c09f71cu; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c09f71e;
P_0c09f71e: /* original e004, guest PC 0x0c09f71e */
if(!s->budget--) { s->failed_pc=0x0c09f71eu; return 0; }
r[0]=0x00000004u;
goto P_0c09f720;
P_0c09f720: /* original f346, guest PC 0x0c09f720 */
if(!s->budget--) { s->failed_pc=0x0c09f720u; return 0; }
vf3_matrix_load(s,ram,3,r[4]+r[0]);
goto P_0c09f722;
P_0c09f722: /* original e008, guest PC 0x0c09f722 */
if(!s->budget--) { s->failed_pc=0x0c09f722u; return 0; }
r[0]=0x00000008u;
goto P_0c09f724;
P_0c09f724: /* original f558, guest PC 0x0c09f724 */
if(!s->budget--) { s->failed_pc=0x0c09f724u; return 0; }
vf3_matrix_load(s,ram,5,r[5]);
goto P_0c09f726;
P_0c09f726: /* original ff3a, guest PC 0x0c09f726 */
if(!s->budget--) { s->failed_pc=0x0c09f726u; return 0; }
vf3_matrix_store(s,ram,3,r[15]);
goto P_0c09f728;
P_0c09f728: /* original f346, guest PC 0x0c09f728 */
if(!s->budget--) { s->failed_pc=0x0c09f728u; return 0; }
vf3_matrix_load(s,ram,3,r[4]+r[0]);
goto P_0c09f72a;
P_0c09f72a: /* original 6453, guest PC 0x0c09f72a */
if(!s->budget--) { s->failed_pc=0x0c09f72au; return 0; }
r[4]=r[5];
goto P_0c09f72c;
P_0c09f72c: /* original 7408, guest PC 0x0c09f72c */
if(!s->budget--) { s->failed_pc=0x0c09f72cu; return 0; }
r[4]+=0x00000008u;
goto P_0c09f72e;
P_0c09f72e: /* original f668, guest PC 0x0c09f72e */
if(!s->budget--) { s->failed_pc=0x0c09f72eu; return 0; }
vf3_matrix_load(s,ram,6,r[6]);
goto P_0c09f730;
P_0c09f730: /* original e008, guest PC 0x0c09f730 */
if(!s->budget--) { s->failed_pc=0x0c09f730u; return 0; }
r[0]=0x00000008u;
goto P_0c09f732;
P_0c09f732: /* original ff37, guest PC 0x0c09f732 */
if(!s->budget--) { s->failed_pc=0x0c09f732u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c09f734;
P_0c09f734: /* original f448, guest PC 0x0c09f734 */
if(!s->budget--) { s->failed_pc=0x0c09f734u; return 0; }
vf3_matrix_load(s,ram,4,r[4]);
goto P_0c09f736;
P_0c09f736: /* original e004, guest PC 0x0c09f736 */
if(!s->budget--) { s->failed_pc=0x0c09f736u; return 0; }
r[0]=0x00000004u;
goto P_0c09f738;
P_0c09f738: /* original f28d, guest PC 0x0c09f738 */
if(!s->budget--) { s->failed_pc=0x0c09f738u; return 0; }
fr[2]=0;
goto P_0c09f73a;
P_0c09f73a: /* original f1f6, guest PC 0x0c09f73a */
if(!s->budget--) { s->failed_pc=0x0c09f73au; return 0; }
vf3_matrix_load(s,ram,1,r[15]+r[0]);
goto P_0c09f73c;
P_0c09f73c: /* original c723, guest PC 0x0c09f73c */
if(!s->budget--) { s->failed_pc=0x0c09f73cu; return 0; }
r[0]=code_base|0x0009f7ccu;
goto P_0c09f73e;
P_0c09f73e: /* original f151, guest PC 0x0c09f73e */
if(!s->budget--) { s->failed_pc=0x0c09f73eu; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[5],r[18],'-');
goto P_0c09f740;
P_0c09f740: /* original f01c, guest PC 0x0c09f740 */
if(!s->budget--) { s->failed_pc=0x0c09f740u; return 0; }
vf3_matrix_move(s,0,1);
goto P_0c09f742;
P_0c09f742: /* original f05d, guest PC 0x0c09f742 */
if(!s->budget--) { s->failed_pc=0x0c09f742u; return 0; }
fr[0]&=0x7fffffffu;
goto P_0c09f744;
P_0c09f744: /* original f705, guest PC 0x0c09f744 */
if(!s->budget--) { s->failed_pc=0x0c09f744u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[7])>as_float(fr[0]))!=0);
goto P_0c09f746;
P_0c09f746: /* original 8f17, guest PC 0x0c09f746 */
if(!s->budget--) { s->failed_pc=0x0c09f746u; return 0; }
cond=r[17]&1u;
vf3_matrix_load(s,ram,13,r[0]);
if(!cond) { goto P_0c09f778; }
goto P_0c09f74a;
P_0c09f748: /* original fd08, guest PC 0x0c09f748 */
if(!s->budget--) { s->failed_pc=0x0c09f748u; return 0; }
vf3_matrix_load(s,ram,13,r[0]);
goto P_0c09f74a;
P_0c09f74a: /* original f805, guest PC 0x0c09f74a */
if(!s->budget--) { s->failed_pc=0x0c09f74au; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[8])>as_float(fr[0]))!=0);
goto P_0c09f74c;
P_0c09f74c: /* original 8b08, guest PC 0x0c09f74c */
if(!s->budget--) { s->failed_pc=0x0c09f74cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09f760; }
goto P_0c09f74e;
P_0c09f74e: /* original f905, guest PC 0x0c09f74e */
if(!s->budget--) { s->failed_pc=0x0c09f74eu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[9])>as_float(fr[0]))!=0);
goto P_0c09f750;
P_0c09f750: /* original 8913, guest PC 0x0c09f750 */
if(!s->budget--) { s->failed_pc=0x0c09f750u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09f77a; }
goto P_0c09f752;
P_0c09f752: /* original f38d, guest PC 0x0c09f752 */
if(!s->budget--) { s->failed_pc=0x0c09f752u; return 0; }
fr[3]=0;
goto P_0c09f754;
P_0c09f754: /* original f315, guest PC 0x0c09f754 */
if(!s->budget--) { s->failed_pc=0x0c09f754u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[1]))!=0);
goto P_0c09f756;
P_0c09f756: /* original 8901, guest PC 0x0c09f756 */
if(!s->budget--) { s->failed_pc=0x0c09f756u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09f75c; }
goto P_0c09f758;
P_0c09f758: /* original a009, guest PC 0x0c09f758 */
if(!s->budget--) { s->failed_pc=0x0c09f758u; return 0; }
vf3_matrix_move(s,1,10);
goto P_0c09f76e;
P_0c09f75a: /* original f1ac, guest PC 0x0c09f75a */
if(!s->budget--) { s->failed_pc=0x0c09f75au; return 0; }
vf3_matrix_move(s,1,10);
goto P_0c09f75c;
P_0c09f75c: /* original a007, guest PC 0x0c09f75c */
if(!s->budget--) { s->failed_pc=0x0c09f75cu; return 0; }
vf3_matrix_move(s,1,13);
goto P_0c09f76e;
P_0c09f75e: /* original f1dc, guest PC 0x0c09f75e */
if(!s->budget--) { s->failed_pc=0x0c09f75eu; return 0; }
vf3_matrix_move(s,1,13);
goto P_0c09f760;
P_0c09f760: /* original f38d, guest PC 0x0c09f760 */
if(!s->budget--) { s->failed_pc=0x0c09f760u; return 0; }
fr[3]=0;
goto P_0c09f762;
P_0c09f762: /* original f315, guest PC 0x0c09f762 */
if(!s->budget--) { s->failed_pc=0x0c09f762u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[1]))!=0);
goto P_0c09f764;
P_0c09f764: /* original 8901, guest PC 0x0c09f764 */
if(!s->budget--) { s->failed_pc=0x0c09f764u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09f76a; }
goto P_0c09f766;
P_0c09f766: /* original a002, guest PC 0x0c09f766 */
if(!s->budget--) { s->failed_pc=0x0c09f766u; return 0; }
vf3_matrix_move(s,1,11);
goto P_0c09f76e;
P_0c09f768: /* original f1bc, guest PC 0x0c09f768 */
if(!s->budget--) { s->failed_pc=0x0c09f768u; return 0; }
vf3_matrix_move(s,1,11);
goto P_0c09f76a;
P_0c09f76a: /* original c719, guest PC 0x0c09f76a */
if(!s->budget--) { s->failed_pc=0x0c09f76au; return 0; }
r[0]=code_base|0x0009f7d0u;
goto P_0c09f76c;
P_0c09f76c: /* original f108, guest PC 0x0c09f76c */
if(!s->budget--) { s->failed_pc=0x0c09f76cu; return 0; }
vf3_matrix_load(s,ram,1,r[0]);
goto P_0c09f76e;
P_0c09f76e: /* original f35c, guest PC 0x0c09f76e */
if(!s->budget--) { s->failed_pc=0x0c09f76eu; return 0; }
vf3_matrix_move(s,3,5);
goto P_0c09f770;
P_0c09f770: /* original f51c, guest PC 0x0c09f770 */
if(!s->budget--) { s->failed_pc=0x0c09f770u; return 0; }
vf3_matrix_move(s,5,1);
goto P_0c09f772;
P_0c09f772: /* original f530, guest PC 0x0c09f772 */
if(!s->budget--) { s->failed_pc=0x0c09f772u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[3],r[18],'+');
goto P_0c09f774;
P_0c09f774: /* original afdf, guest PC 0x0c09f774 */
if(!s->budget--) { s->failed_pc=0x0c09f774u; return 0; }
vf3_matrix_store(s,ram,5,r[5]);
goto P_0c09f736;
P_0c09f776: /* original f55a, guest PC 0x0c09f776 */
if(!s->budget--) { s->failed_pc=0x0c09f776u; return 0; }
vf3_matrix_store(s,ram,5,r[5]);
goto P_0c09f778;
P_0c09f778: /* original f52a, guest PC 0x0c09f778 */
if(!s->budget--) { s->failed_pc=0x0c09f778u; return 0; }
vf3_matrix_store(s,ram,2,r[5]);
goto P_0c09f77a;
P_0c09f77a: /* original f5f8, guest PC 0x0c09f77a */
if(!s->budget--) { s->failed_pc=0x0c09f77au; return 0; }
vf3_matrix_load(s,ram,5,r[15]);
goto P_0c09f77c;
P_0c09f77c: /* original f561, guest PC 0x0c09f77c */
if(!s->budget--) { s->failed_pc=0x0c09f77cu; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[6],r[18],'-');
goto P_0c09f77e;
P_0c09f77e: /* original f15c, guest PC 0x0c09f77e */
if(!s->budget--) { s->failed_pc=0x0c09f77eu; return 0; }
vf3_matrix_move(s,1,5);
goto P_0c09f780;
P_0c09f780: /* original f15d, guest PC 0x0c09f780 */
if(!s->budget--) { s->failed_pc=0x0c09f780u; return 0; }
fr[1]&=0x7fffffffu;
goto P_0c09f782;
P_0c09f782: /* original f715, guest PC 0x0c09f782 */
if(!s->budget--) { s->failed_pc=0x0c09f782u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[7])>as_float(fr[1]))!=0);
goto P_0c09f784;
P_0c09f784: /* original 8b26, guest PC 0x0c09f784 */
if(!s->budget--) { s->failed_pc=0x0c09f784u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09f7d4; }
goto P_0c09f786;
P_0c09f786: /* original f815, guest PC 0x0c09f786 */
if(!s->budget--) { s->failed_pc=0x0c09f786u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[8])>as_float(fr[1]))!=0);
goto P_0c09f788;
P_0c09f788: /* original 8b08, guest PC 0x0c09f788 */
if(!s->budget--) { s->failed_pc=0x0c09f788u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09f79c; }
goto P_0c09f78a;
P_0c09f78a: /* original f915, guest PC 0x0c09f78a */
if(!s->budget--) { s->failed_pc=0x0c09f78au; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[9])>as_float(fr[1]))!=0);
goto P_0c09f78c;
P_0c09f78c: /* original 8923, guest PC 0x0c09f78c */
if(!s->budget--) { s->failed_pc=0x0c09f78cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09f7d6; }
goto P_0c09f78e;
P_0c09f78e: /* original f38d, guest PC 0x0c09f78e */
if(!s->budget--) { s->failed_pc=0x0c09f78eu; return 0; }
fr[3]=0;
goto P_0c09f790;
P_0c09f790: /* original f355, guest PC 0x0c09f790 */
if(!s->budget--) { s->failed_pc=0x0c09f790u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[5]))!=0);
goto P_0c09f792;
P_0c09f792: /* original 8901, guest PC 0x0c09f792 */
if(!s->budget--) { s->failed_pc=0x0c09f792u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09f798; }
goto P_0c09f794;
P_0c09f794: /* original a009, guest PC 0x0c09f794 */
if(!s->budget--) { s->failed_pc=0x0c09f794u; return 0; }
vf3_matrix_move(s,5,10);
goto P_0c09f7aa;
P_0c09f796: /* original f5ac, guest PC 0x0c09f796 */
if(!s->budget--) { s->failed_pc=0x0c09f796u; return 0; }
vf3_matrix_move(s,5,10);
goto P_0c09f798;
P_0c09f798: /* original a007, guest PC 0x0c09f798 */
if(!s->budget--) { s->failed_pc=0x0c09f798u; return 0; }
vf3_matrix_move(s,5,13);
goto P_0c09f7aa;
P_0c09f79a: /* original f5dc, guest PC 0x0c09f79a */
if(!s->budget--) { s->failed_pc=0x0c09f79au; return 0; }
vf3_matrix_move(s,5,13);
goto P_0c09f79c;
P_0c09f79c: /* original f38d, guest PC 0x0c09f79c */
if(!s->budget--) { s->failed_pc=0x0c09f79cu; return 0; }
fr[3]=0;
goto P_0c09f79e;
P_0c09f79e: /* original f355, guest PC 0x0c09f79e */
if(!s->budget--) { s->failed_pc=0x0c09f79eu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[5]))!=0);
goto P_0c09f7a0;
P_0c09f7a0: /* original 8901, guest PC 0x0c09f7a0 */
if(!s->budget--) { s->failed_pc=0x0c09f7a0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09f7a6; }
goto P_0c09f7a2;
P_0c09f7a2: /* original a002, guest PC 0x0c09f7a2 */
if(!s->budget--) { s->failed_pc=0x0c09f7a2u; return 0; }
vf3_matrix_move(s,5,11);
goto P_0c09f7aa;
P_0c09f7a4: /* original f5bc, guest PC 0x0c09f7a4 */
if(!s->budget--) { s->failed_pc=0x0c09f7a4u; return 0; }
vf3_matrix_move(s,5,11);
goto P_0c09f7a6;
P_0c09f7a6: /* original c70a, guest PC 0x0c09f7a6 */
if(!s->budget--) { s->failed_pc=0x0c09f7a6u; return 0; }
r[0]=code_base|0x0009f7d0u;
goto P_0c09f7a8;
P_0c09f7a8: /* original f508, guest PC 0x0c09f7a8 */
if(!s->budget--) { s->failed_pc=0x0c09f7a8u; return 0; }
vf3_matrix_load(s,ram,5,r[0]);
goto P_0c09f7aa;
P_0c09f7aa: /* original f36c, guest PC 0x0c09f7aa */
if(!s->budget--) { s->failed_pc=0x0c09f7aau; return 0; }
vf3_matrix_move(s,3,6);
goto P_0c09f7ac;
P_0c09f7ac: /* original f65c, guest PC 0x0c09f7ac */
if(!s->budget--) { s->failed_pc=0x0c09f7acu; return 0; }
vf3_matrix_move(s,6,5);
goto P_0c09f7ae;
P_0c09f7ae: /* original f630, guest PC 0x0c09f7ae */
if(!s->budget--) { s->failed_pc=0x0c09f7aeu; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[3],r[18],'+');
goto P_0c09f7b0;
P_0c09f7b0: /* original afe3, guest PC 0x0c09f7b0 */
if(!s->budget--) { s->failed_pc=0x0c09f7b0u; return 0; }
vf3_matrix_store(s,ram,6,r[6]);
goto P_0c09f77a;
P_0c09f7b2: /* original f66a, guest PC 0x0c09f7b2 */
if(!s->budget--) { s->failed_pc=0x0c09f7b2u; return 0; }
vf3_matrix_store(s,ram,6,r[6]);
if(!vf3_matrix_family(0x0c09f7b4u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c09f7b4u; return 0; } return 1;
P_0c09f7d4: /* original f62a, guest PC 0x0c09f7d4 */
if(!s->budget--) { s->failed_pc=0x0c09f7d4u; return 0; }
vf3_matrix_store(s,ram,2,r[6]);
goto P_0c09f7d6;
P_0c09f7d6: /* original e008, guest PC 0x0c09f7d6 */
if(!s->budget--) { s->failed_pc=0x0c09f7d6u; return 0; }
r[0]=0x00000008u;
goto P_0c09f7d8;
P_0c09f7d8: /* original f6f6, guest PC 0x0c09f7d8 */
if(!s->budget--) { s->failed_pc=0x0c09f7d8u; return 0; }
vf3_matrix_load(s,ram,6,r[15]+r[0]);
goto P_0c09f7da;
P_0c09f7da: /* original f641, guest PC 0x0c09f7da */
if(!s->budget--) { s->failed_pc=0x0c09f7dau; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[4],r[18],'-');
goto P_0c09f7dc;
P_0c09f7dc: /* original f56c, guest PC 0x0c09f7dc */
if(!s->budget--) { s->failed_pc=0x0c09f7dcu; return 0; }
vf3_matrix_move(s,5,6);
goto P_0c09f7de;
P_0c09f7de: /* original f55d, guest PC 0x0c09f7de */
if(!s->budget--) { s->failed_pc=0x0c09f7deu; return 0; }
fr[5]&=0x7fffffffu;
goto P_0c09f7e0;
P_0c09f7e0: /* original f755, guest PC 0x0c09f7e0 */
if(!s->budget--) { s->failed_pc=0x0c09f7e0u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[7])>as_float(fr[5]))!=0);
goto P_0c09f7e2;
P_0c09f7e2: /* original 8b16, guest PC 0x0c09f7e2 */
if(!s->budget--) { s->failed_pc=0x0c09f7e2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09f812; }
goto P_0c09f7e4;
P_0c09f7e4: /* original f855, guest PC 0x0c09f7e4 */
if(!s->budget--) { s->failed_pc=0x0c09f7e4u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[8])>as_float(fr[5]))!=0);
goto P_0c09f7e6;
P_0c09f7e6: /* original 8b08, guest PC 0x0c09f7e6 */
if(!s->budget--) { s->failed_pc=0x0c09f7e6u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09f7fa; }
goto P_0c09f7e8;
P_0c09f7e8: /* original f955, guest PC 0x0c09f7e8 */
if(!s->budget--) { s->failed_pc=0x0c09f7e8u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[9])>as_float(fr[5]))!=0);
goto P_0c09f7ea;
P_0c09f7ea: /* original 8913, guest PC 0x0c09f7ea */
if(!s->budget--) { s->failed_pc=0x0c09f7eau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09f814; }
goto P_0c09f7ec;
P_0c09f7ec: /* original f38d, guest PC 0x0c09f7ec */
if(!s->budget--) { s->failed_pc=0x0c09f7ecu; return 0; }
fr[3]=0;
goto P_0c09f7ee;
P_0c09f7ee: /* original f365, guest PC 0x0c09f7ee */
if(!s->budget--) { s->failed_pc=0x0c09f7eeu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[6]))!=0);
goto P_0c09f7f0;
P_0c09f7f0: /* original 8901, guest PC 0x0c09f7f0 */
if(!s->budget--) { s->failed_pc=0x0c09f7f0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09f7f6; }
goto P_0c09f7f2;
P_0c09f7f2: /* original a009, guest PC 0x0c09f7f2 */
if(!s->budget--) { s->failed_pc=0x0c09f7f2u; return 0; }
vf3_matrix_move(s,5,10);
goto P_0c09f808;
P_0c09f7f4: /* original f5ac, guest PC 0x0c09f7f4 */
if(!s->budget--) { s->failed_pc=0x0c09f7f4u; return 0; }
vf3_matrix_move(s,5,10);
goto P_0c09f7f6;
P_0c09f7f6: /* original a007, guest PC 0x0c09f7f6 */
if(!s->budget--) { s->failed_pc=0x0c09f7f6u; return 0; }
vf3_matrix_move(s,5,13);
goto P_0c09f808;
P_0c09f7f8: /* original f5dc, guest PC 0x0c09f7f8 */
if(!s->budget--) { s->failed_pc=0x0c09f7f8u; return 0; }
vf3_matrix_move(s,5,13);
goto P_0c09f7fa;
P_0c09f7fa: /* original f38d, guest PC 0x0c09f7fa */
if(!s->budget--) { s->failed_pc=0x0c09f7fau; return 0; }
fr[3]=0;
goto P_0c09f7fc;
P_0c09f7fc: /* original f365, guest PC 0x0c09f7fc */
if(!s->budget--) { s->failed_pc=0x0c09f7fcu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[6]))!=0);
goto P_0c09f7fe;
P_0c09f7fe: /* original 8901, guest PC 0x0c09f7fe */
if(!s->budget--) { s->failed_pc=0x0c09f7feu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09f804; }
goto P_0c09f800;
P_0c09f800: /* original a002, guest PC 0x0c09f800 */
if(!s->budget--) { s->failed_pc=0x0c09f800u; return 0; }
vf3_matrix_move(s,5,11);
goto P_0c09f808;
P_0c09f802: /* original f5bc, guest PC 0x0c09f802 */
if(!s->budget--) { s->failed_pc=0x0c09f802u; return 0; }
vf3_matrix_move(s,5,11);
goto P_0c09f804;
P_0c09f804: /* original c733, guest PC 0x0c09f804 */
if(!s->budget--) { s->failed_pc=0x0c09f804u; return 0; }
r[0]=code_base|0x0009f8d4u;
goto P_0c09f806;
P_0c09f806: /* original f508, guest PC 0x0c09f806 */
if(!s->budget--) { s->failed_pc=0x0c09f806u; return 0; }
vf3_matrix_load(s,ram,5,r[0]);
goto P_0c09f808;
P_0c09f808: /* original f34c, guest PC 0x0c09f808 */
if(!s->budget--) { s->failed_pc=0x0c09f808u; return 0; }
vf3_matrix_move(s,3,4);
goto P_0c09f80a;
P_0c09f80a: /* original f45c, guest PC 0x0c09f80a */
if(!s->budget--) { s->failed_pc=0x0c09f80au; return 0; }
vf3_matrix_move(s,4,5);
goto P_0c09f80c;
P_0c09f80c: /* original f430, guest PC 0x0c09f80c */
if(!s->budget--) { s->failed_pc=0x0c09f80cu; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'+');
goto P_0c09f80e;
P_0c09f80e: /* original afe2, guest PC 0x0c09f80e */
if(!s->budget--) { s->failed_pc=0x0c09f80eu; return 0; }
vf3_matrix_store(s,ram,4,r[4]);
goto P_0c09f7d6;
P_0c09f810: /* original f44a, guest PC 0x0c09f810 */
if(!s->budget--) { s->failed_pc=0x0c09f810u; return 0; }
vf3_matrix_store(s,ram,4,r[4]);
goto P_0c09f812;
P_0c09f812: /* original f42a, guest PC 0x0c09f812 */
if(!s->budget--) { s->failed_pc=0x0c09f812u; return 0; }
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c09f814;
P_0c09f814: /* original 7f0c, guest PC 0x0c09f814 */
if(!s->budget--) { s->failed_pc=0x0c09f814u; return 0; }
r[15]+=0x0000000cu;
goto P_0c09f816;
P_0c09f816: /* original 000b, guest PC 0x0c09f816 */
if(!s->budget--) { s->failed_pc=0x0c09f816u; return 0; }
target=r[16];
vf3_matrix_load(s,ram,13,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
s->pc=target; return ram->oob==0;
P_0c09f818: /* original fdf9, guest PC 0x0c09f818 */
if(!s->budget--) { s->failed_pc=0x0c09f818u; return 0; }
vf3_matrix_load(s,ram,13,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
if(!vf3_matrix_family(0x0c09f81au,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c09f81au; return 0; } return 1;
P_0c09f984: /* original 2fe6, guest PC 0x0c09f984 */
if(!s->budget--) { s->failed_pc=0x0c09f984u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09f986;
P_0c09f986: /* original 6e43, guest PC 0x0c09f986 */
if(!s->budget--) { s->failed_pc=0x0c09f986u; return 0; }
r[14]=r[4];
goto P_0c09f988;
P_0c09f988: /* original 9027, guest PC 0x0c09f988 */
if(!s->budget--) { s->failed_pc=0x0c09f988u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09f9dau,2);
goto P_0c09f98a;
P_0c09f98a: /* original e3f8, guest PC 0x0c09f98a */
if(!s->budget--) { s->failed_pc=0x0c09f98au; return 0; }
r[3]=0xfffffff8u;
goto P_0c09f98c;
P_0c09f98c: /* original d218, guest PC 0x0c09f98c */
if(!s->budget--) { s->failed_pc=0x0c09f98cu; return 0; }
r[2]=read(ram,0x0c09f9f0u,4);
goto P_0c09f98e;
P_0c09f98e: /* original 04ed, guest PC 0x0c09f98e */
if(!s->budget--) { s->failed_pc=0x0c09f98eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c09f990;
P_0c09f990: /* original 7004, guest PC 0x0c09f990 */
if(!s->budget--) { s->failed_pc=0x0c09f990u; return 0; }
r[0]+=0x00000004u;
goto P_0c09f992;
P_0c09f992: /* original 06ed, guest PC 0x0c09f992 */
if(!s->budget--) { s->failed_pc=0x0c09f992u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c09f994;
P_0c09f994: /* original e03e, guest PC 0x0c09f994 */
if(!s->budget--) { s->failed_pc=0x0c09f994u; return 0; }
r[0]=0x0000003eu;
goto P_0c09f996;
P_0c09f996: /* original 05ed, guest PC 0x0c09f996 */
if(!s->budget--) { s->failed_pc=0x0c09f996u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c09f998;
P_0c09f998: /* original e040, guest PC 0x0c09f998 */
if(!s->budget--) { s->failed_pc=0x0c09f998u; return 0; }
r[0]=0x00000040u;
goto P_0c09f99a;
P_0c09f99a: /* original 07ed, guest PC 0x0c09f99a */
if(!s->budget--) { s->failed_pc=0x0c09f99au; return 0; }
r[7]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c09f99c;
P_0c09f99c: /* original 4418, guest PC 0x0c09f99c */
if(!s->budget--) { s->failed_pc=0x0c09f99cu; return 0; }
r[4]<<=8;
goto P_0c09f99e;
P_0c09f99e: /* original 655d, guest PC 0x0c09f99e */
if(!s->budget--) { s->failed_pc=0x0c09f99eu; return 0; }
r[5]=r[5]&65535u;
goto P_0c09f9a0;
P_0c09f9a0: /* original 677d, guest PC 0x0c09f9a0 */
if(!s->budget--) { s->failed_pc=0x0c09f9a0u; return 0; }
r[7]=r[7]&65535u;
goto P_0c09f9a2;
P_0c09f9a2: /* original 4528, guest PC 0x0c09f9a2 */
if(!s->budget--) { s->failed_pc=0x0c09f9a2u; return 0; }
r[5]<<=16;
goto P_0c09f9a4;
P_0c09f9a4: /* original 257b, guest PC 0x0c09f9a4 */
if(!s->budget--) { s->failed_pc=0x0c09f9a4u; return 0; }
r[5]|=r[7];
goto P_0c09f9a6;
P_0c09f9a6: /* original 453c, guest PC 0x0c09f9a6 */
if(!s->budget--) { s->failed_pc=0x0c09f9a6u; return 0; }
r[5]=(r[3]&0x80000000u)?((r[3]&31u)?(uint32_t)((int32_t)r[5]>>((-r[3])&31u)):((int32_t)r[5]<0?0xffffffffu:0)):r[5]<<(r[3]&31u);
goto P_0c09f9a8;
P_0c09f9a8: /* original 4f22, guest PC 0x0c09f9a8 */
if(!s->budget--) { s->failed_pc=0x0c09f9a8u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c09f9aa;
P_0c09f9aa: /* original 2529, guest PC 0x0c09f9aa */
if(!s->budget--) { s->failed_pc=0x0c09f9aau; return 0; }
r[5]&=r[2];
goto P_0c09f9ac;
P_0c09f9ac: /* original 3547, guest PC 0x0c09f9ac */
if(!s->budget--) { s->failed_pc=0x0c09f9acu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[5]>(int32_t)r[4])!=0);
goto P_0c09f9ae;
P_0c09f9ae: /* original 666d, guest PC 0x0c09f9ae */
if(!s->budget--) { s->failed_pc=0x0c09f9aeu; return 0; }
r[6]=r[6]&65535u;
goto P_0c09f9b0;
P_0c09f9b0: /* original 8d0e, guest PC 0x0c09f9b0 */
if(!s->budget--) { s->failed_pc=0x0c09f9b0u; return 0; }
cond=r[17]&1u;
r[6]<<=8;
if(cond) { goto P_0c09f9d0; }
goto P_0c09f9b4;
P_0c09f9b2: /* original 4618, guest PC 0x0c09f9b2 */
if(!s->budget--) { s->failed_pc=0x0c09f9b2u; return 0; }
r[6]<<=8;
goto P_0c09f9b4;
P_0c09f9b4: /* original 3468, guest PC 0x0c09f9b4 */
if(!s->budget--) { s->failed_pc=0x0c09f9b4u; return 0; }
r[4]-=r[6];
goto P_0c09f9b6;
P_0c09f9b6: /* original 445a, guest PC 0x0c09f9b6 */
if(!s->budget--) { s->failed_pc=0x0c09f9b6u; return 0; }
r[53]=r[4];
goto P_0c09f9b8;
P_0c09f9b8: /* original 3568, guest PC 0x0c09f9b8 */
if(!s->budget--) { s->failed_pc=0x0c09f9b8u; return 0; }
r[5]-=r[6];
goto P_0c09f9ba;
P_0c09f9ba: /* original 9410, guest PC 0x0c09f9ba */
if(!s->budget--) { s->failed_pc=0x0c09f9bau; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09f9deu,2);
goto P_0c09f9bc;
P_0c09f9bc: /* original f32d, guest PC 0x0c09f9bc */
if(!s->budget--) { s->failed_pc=0x0c09f9bcu; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c09f9be;
P_0c09f9be: /* original 455a, guest PC 0x0c09f9be */
if(!s->budget--) { s->failed_pc=0x0c09f9beu; return 0; }
r[53]=r[5];
goto P_0c09f9c0;
P_0c09f9c0: /* original 950c, guest PC 0x0c09f9c0 */
if(!s->budget--) { s->failed_pc=0x0c09f9c0u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09f9dcu,2);
goto P_0c09f9c2;
P_0c09f9c2: /* original f22d, guest PC 0x0c09f9c2 */
if(!s->budget--) { s->failed_pc=0x0c09f9c2u; return 0; }
fr[2]=vf3_fpu_float(r[53],r[18]);
goto P_0c09f9c4;
P_0c09f9c4: /* original 35ec, guest PC 0x0c09f9c4 */
if(!s->budget--) { s->failed_pc=0x0c09f9c4u; return 0; }
r[5]+=r[14];
goto P_0c09f9c6;
P_0c09f9c6: /* original f42c, guest PC 0x0c09f9c6 */
if(!s->budget--) { s->failed_pc=0x0c09f9c6u; return 0; }
vf3_matrix_move(s,4,2);
goto P_0c09f9c8;
P_0c09f9c8: /* original f433, guest PC 0x0c09f9c8 */
if(!s->budget--) { s->failed_pc=0x0c09f9c8u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'/');
goto P_0c09f9ca;
P_0c09f9ca: /* original f52c, guest PC 0x0c09f9ca */
if(!s->budget--) { s->failed_pc=0x0c09f9cau; return 0; }
vf3_matrix_move(s,5,2);
goto P_0c09f9cc;
P_0c09f9cc: /* original bcc2, guest PC 0x0c09f9cc */
if(!s->budget--) { s->failed_pc=0x0c09f9ccu; return 0; }
target=code_base|0x0c09f354u; r[16]=code_base|0x0c09f9d0u;
r[4]+=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09f9d0u) { target=s->pc; goto dispatch; }
goto P_0c09f9d0;
P_0c09f9ce: /* original 34ec, guest PC 0x0c09f9ce */
if(!s->budget--) { s->failed_pc=0x0c09f9ceu; return 0; }
r[4]+=r[14];
goto P_0c09f9d0;
P_0c09f9d0: /* original 4f26, guest PC 0x0c09f9d0 */
if(!s->budget--) { s->failed_pc=0x0c09f9d0u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c09f9d2;
P_0c09f9d2: /* original 000b, guest PC 0x0c09f9d2 */
if(!s->budget--) { s->failed_pc=0x0c09f9d2u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c09f9d4: /* original 6ef6, guest PC 0x0c09f9d4 */
if(!s->budget--) { s->failed_pc=0x0c09f9d4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c09f9d6u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c09f9d6u; return 0; } return 1;
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
unsupported: s->failed_pc=target; return 0;
}
