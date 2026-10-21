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
int vf3_c102_adapter(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* The code base is the mirror the code runs under: 0x0c, 0x8c or 0xac.  A call hands the callee the mirror it jumped to (the router masks the entry PC to 29 bits, which loses it); a direct entry falls back to the alias the caller left in the link register. */
uint32_t code_base=(vf3_matrix_call_alias_pc==(entry&0x1fffffffu))?vf3_matrix_call_alias:(((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u));
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c011090u: goto P_0c011090;
case 0x0c011092u: goto P_0c011092;
case 0x0c011094u: goto P_0c011094;
case 0x0c011096u: goto P_0c011096;
case 0x0c011098u: goto P_0c011098;
case 0x0c01109au: goto P_0c01109a;
case 0x0c01109cu: goto P_0c01109c;
case 0x0c01109eu: goto P_0c01109e;
case 0x0c0110a0u: goto P_0c0110a0;
case 0x0c0110a2u: goto P_0c0110a2;
case 0x0c0110a4u: goto P_0c0110a4;
case 0x0c0110a6u: goto P_0c0110a6;
case 0x0c0110a8u: goto P_0c0110a8;
case 0x0c0110aau: goto P_0c0110aa;
case 0x0c0110acu: goto P_0c0110ac;
case 0x0c0110aeu: goto P_0c0110ae;
case 0x0c0110b0u: goto P_0c0110b0;
case 0x0c0110b2u: goto P_0c0110b2;
case 0x0c0110b4u: goto P_0c0110b4;
case 0x0c0110b6u: goto P_0c0110b6;
case 0x0c0110b8u: goto P_0c0110b8;
case 0x0c0110bau: goto P_0c0110ba;
case 0x0c0110bcu: goto P_0c0110bc;
case 0x0c0110beu: goto P_0c0110be;
case 0x0c0110c0u: goto P_0c0110c0;
case 0x0c0110c2u: goto P_0c0110c2;
case 0x0c0110c4u: goto P_0c0110c4;
case 0x0c0110c6u: goto P_0c0110c6;
case 0x0c0110c8u: goto P_0c0110c8;
case 0x0c0110cau: goto P_0c0110ca;
case 0x0c0110ccu: goto P_0c0110cc;
case 0x0c0110ceu: goto P_0c0110ce;
case 0x0c0110d0u: goto P_0c0110d0;
case 0x0c0110d2u: goto P_0c0110d2;
case 0x0c0110d4u: goto P_0c0110d4;
case 0x0c0110d6u: goto P_0c0110d6;
case 0x0c0110d8u: goto P_0c0110d8;
case 0x0c0110dau: goto P_0c0110da;
case 0x0c0110dcu: goto P_0c0110dc;
case 0x0c0110deu: goto P_0c0110de;
case 0x0c0110e0u: goto P_0c0110e0;
case 0x0c0110e2u: goto P_0c0110e2;
case 0x0c0110e4u: goto P_0c0110e4;
case 0x0c0512dcu: goto P_0c0512dc;
case 0x0c0512deu: goto P_0c0512de;
case 0x0c0512e0u: goto P_0c0512e0;
case 0x0c058780u: goto P_0c058780;
case 0x0c058782u: goto P_0c058782;
case 0x0c058784u: goto P_0c058784;
case 0x0c058788u: goto P_0c058788;
case 0x0c05878au: goto P_0c05878a;
case 0x0c05878cu: goto P_0c05878c;
case 0x0c0587d8u: goto P_0c0587d8;
case 0x0c0587dau: goto P_0c0587da;
case 0x0c0587dcu: goto P_0c0587dc;
case 0x0c0587deu: goto P_0c0587de;
case 0x0c0587e0u: goto P_0c0587e0;
case 0x0c0587e2u: goto P_0c0587e2;
case 0x0c0587e4u: goto P_0c0587e4;
case 0x0c0587e6u: goto P_0c0587e6;
case 0x0c0587e8u: goto P_0c0587e8;
case 0x0c0587eau: goto P_0c0587ea;
case 0x0c0587ecu: goto P_0c0587ec;
case 0x0c0587eeu: goto P_0c0587ee;
case 0x0c0587f0u: goto P_0c0587f0;
case 0x0c0587f2u: goto P_0c0587f2;
case 0x0c0587f4u: goto P_0c0587f4;
case 0x0c0587f6u: goto P_0c0587f6;
case 0x0c0587f8u: goto P_0c0587f8;
case 0x0c0587fau: goto P_0c0587fa;
case 0x0c0587fcu: goto P_0c0587fc;
case 0x0c0587feu: goto P_0c0587fe;
case 0x0c058800u: goto P_0c058800;
case 0x0c058802u: goto P_0c058802;
case 0x0c058804u: goto P_0c058804;
case 0x0c058806u: goto P_0c058806;
case 0x0c058808u: goto P_0c058808;
case 0x0c05880au: goto P_0c05880a;
case 0x0c05880cu: goto P_0c05880c;
case 0x0c05880eu: goto P_0c05880e;
case 0x0c058810u: goto P_0c058810;
case 0x0c058812u: goto P_0c058812;
case 0x0c058814u: goto P_0c058814;
case 0x0c058816u: goto P_0c058816;
case 0x0c058818u: goto P_0c058818;
case 0x0c05881au: goto P_0c05881a;
case 0x0c05881cu: goto P_0c05881c;
case 0x0c05881eu: goto P_0c05881e;
case 0x0c058820u: goto P_0c058820;
case 0x0c058822u: goto P_0c058822;
case 0x0c058824u: goto P_0c058824;
case 0x0c058826u: goto P_0c058826;
case 0x0c058828u: goto P_0c058828;
case 0x0c05882au: goto P_0c05882a;
case 0x0c05882cu: goto P_0c05882c;
case 0x0c05882eu: goto P_0c05882e;
case 0x0c058830u: goto P_0c058830;
case 0x0c058832u: goto P_0c058832;
case 0x0c058834u: goto P_0c058834;
case 0x0c058836u: goto P_0c058836;
case 0x0c058838u: goto P_0c058838;
case 0x0c05883au: goto P_0c05883a;
case 0x0c05883cu: goto P_0c05883c;
case 0x0c05883eu: goto P_0c05883e;
case 0x0c058840u: goto P_0c058840;
case 0x0c058842u: goto P_0c058842;
case 0x0c058844u: goto P_0c058844;
case 0x0c058846u: goto P_0c058846;
case 0x0c058848u: goto P_0c058848;
case 0x0c05884au: goto P_0c05884a;
case 0x0c05884cu: goto P_0c05884c;
case 0x0c05884eu: goto P_0c05884e;
case 0x0c058850u: goto P_0c058850;
case 0x0c058852u: goto P_0c058852;
case 0x0c058854u: goto P_0c058854;
case 0x0c058856u: goto P_0c058856;
case 0x0c058858u: goto P_0c058858;
case 0x0c05885au: goto P_0c05885a;
case 0x0c05885cu: goto P_0c05885c;
case 0x0c05885eu: goto P_0c05885e;
case 0x0c058860u: goto P_0c058860;
case 0x0c058862u: goto P_0c058862;
case 0x0c058864u: goto P_0c058864;
case 0x0c058866u: goto P_0c058866;
case 0x0c058868u: goto P_0c058868;
case 0x0c05886au: goto P_0c05886a;
case 0x0c05886cu: goto P_0c05886c;
case 0x0c05886eu: goto P_0c05886e;
case 0x0c058870u: goto P_0c058870;
case 0x0c058872u: goto P_0c058872;
case 0x0c058874u: goto P_0c058874;
case 0x0c058876u: goto P_0c058876;
case 0x0c058878u: goto P_0c058878;
case 0x0c05887au: goto P_0c05887a;
case 0x0c05887cu: goto P_0c05887c;
case 0x0c05887eu: goto P_0c05887e;
case 0x0c058880u: goto P_0c058880;
case 0x0c058882u: goto P_0c058882;
case 0x0c058884u: goto P_0c058884;
case 0x0c058886u: goto P_0c058886;
case 0x0c058888u: goto P_0c058888;
case 0x0c05888au: goto P_0c05888a;
case 0x0c05888cu: goto P_0c05888c;
case 0x0c05888eu: goto P_0c05888e;
case 0x0c058890u: goto P_0c058890;
case 0x0c058892u: goto P_0c058892;
case 0x0c058894u: goto P_0c058894;
case 0x0c058896u: goto P_0c058896;
case 0x0c058898u: goto P_0c058898;
case 0x0c05889au: goto P_0c05889a;
case 0x0c05889cu: goto P_0c05889c;
case 0x0c05889eu: goto P_0c05889e;
case 0x0c0588a0u: goto P_0c0588a0;
case 0x0c0588a2u: goto P_0c0588a2;
case 0x0c0588a4u: goto P_0c0588a4;
case 0x0c0588a6u: goto P_0c0588a6;
case 0x0c0588a8u: goto P_0c0588a8;
case 0x0c0588aau: goto P_0c0588aa;
case 0x0c0588acu: goto P_0c0588ac;
case 0x0c0588aeu: goto P_0c0588ae;
case 0x0c0588b0u: goto P_0c0588b0;
case 0x0c0588b2u: goto P_0c0588b2;
case 0x0c0588b4u: goto P_0c0588b4;
case 0x0c0588b6u: goto P_0c0588b6;
case 0x0c0588b8u: goto P_0c0588b8;
case 0x0c0588bau: goto P_0c0588ba;
case 0x0c0588bcu: goto P_0c0588bc;
case 0x0c0588beu: goto P_0c0588be;
case 0x0c0588c0u: goto P_0c0588c0;
case 0x0c0588c2u: goto P_0c0588c2;
case 0x0c0588c4u: goto P_0c0588c4;
case 0x0c0588c6u: goto P_0c0588c6;
case 0x0c0588c8u: goto P_0c0588c8;
case 0x0c0588cau: goto P_0c0588ca;
case 0x0c0588ccu: goto P_0c0588cc;
case 0x0c0588ceu: goto P_0c0588ce;
case 0x0c0588d0u: goto P_0c0588d0;
case 0x0c0588d2u: goto P_0c0588d2;
case 0x0c0588d4u: goto P_0c0588d4;
case 0x0c0588d6u: goto P_0c0588d6;
case 0x0c0588d8u: goto P_0c0588d8;
case 0x0c0588dau: goto P_0c0588da;
case 0x0c0588dcu: goto P_0c0588dc;
case 0x0c0588deu: goto P_0c0588de;
case 0x0c0588e0u: goto P_0c0588e0;
case 0x0c0588e2u: goto P_0c0588e2;
case 0x0c0588e4u: goto P_0c0588e4;
case 0x0c0588e6u: goto P_0c0588e6;
case 0x0c0588e8u: goto P_0c0588e8;
case 0x0c0588eau: goto P_0c0588ea;
case 0x0c0588ecu: goto P_0c0588ec;
case 0x0c0588eeu: goto P_0c0588ee;
default: vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!s->lost_pc) s->lost_pc=target; if(!vf3_matrix_family(target,s,ram)) return 0; return 1;
}
P_0c011090: /* original 4f22, guest PC 0x0c011090 */
if(!s->budget--) { s->failed_pc=0x0c011090u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c011092;
P_0c011092: /* original 64d2, guest PC 0x0c011092 */
if(!s->budget--) { s->failed_pc=0x0c011092u; return 0; }
tmp=read(ram,r[13],4);
r[4]=tmp;
goto P_0c011094;
P_0c011094: /* original e308, guest PC 0x0c011094 */
if(!s->budget--) { s->failed_pc=0x0c011094u; return 0; }
r[3]=0x00000008u;
goto P_0c011096;
P_0c011096: /* original 334c, guest PC 0x0c011096 */
if(!s->budget--) { s->failed_pc=0x0c011096u; return 0; }
r[3]+=r[4];
goto P_0c011098;
P_0c011098: /* original 6330, guest PC 0x0c011098 */
if(!s->budget--) { s->failed_pc=0x0c011098u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[3],1);
r[3]=tmp;
goto P_0c01109a;
P_0c01109a: /* original e210, guest PC 0x0c01109a */
if(!s->budget--) { s->failed_pc=0x0c01109au; return 0; }
r[2]=0x00000010u;
goto P_0c01109c;
P_0c01109c: /* original 324c, guest PC 0x0c01109c */
if(!s->budget--) { s->failed_pc=0x0c01109cu; return 0; }
r[2]+=r[4];
goto P_0c01109e;
P_0c01109e: /* original 6220, guest PC 0x0c01109e */
if(!s->budget--) { s->failed_pc=0x0c01109eu; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[2],1);
r[2]=tmp;
goto P_0c0110a0;
P_0c0110a0: /* original e314, guest PC 0x0c0110a0 */
if(!s->budget--) { s->failed_pc=0x0c0110a0u; return 0; }
r[3]=0x00000014u;
goto P_0c0110a2;
P_0c0110a2: /* original 4510, guest PC 0x0c0110a2 */
if(!s->budget--) { s->failed_pc=0x0c0110a2u; return 0; }
--r[5];
r[17]=(r[17]&~1u)|((r[5]==0)!=0);
goto P_0c0110a4;
P_0c0110a4: /* original 334c, guest PC 0x0c0110a4 */
if(!s->budget--) { s->failed_pc=0x0c0110a4u; return 0; }
r[3]+=r[4];
goto P_0c0110a6;
P_0c0110a6: /* original 8ff5, guest PC 0x0c0110a6 */
if(!s->budget--) { s->failed_pc=0x0c0110a6u; return 0; }
cond=r[17]&1u;
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[3],1);
r[3]=tmp;
if(!cond) { goto P_0c011094; }
goto P_0c0110aa;
P_0c0110a8: /* original 6330, guest PC 0x0c0110a8 */
if(!s->budget--) { s->failed_pc=0x0c0110a8u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[3],1);
r[3]=tmp;
goto P_0c0110aa;
P_0c0110aa: /* original e03c, guest PC 0x0c0110aa */
if(!s->budget--) { s->failed_pc=0x0c0110aau; return 0; }
r[0]=0x0000003cu;
goto P_0c0110ac;
P_0c0110ac: /* original e3c0, guest PC 0x0c0110ac */
if(!s->budget--) { s->failed_pc=0x0c0110acu; return 0; }
r[3]=0xffffffc0u;
goto P_0c0110ae;
P_0c0110ae: /* original 0434, guest PC 0x0c0110ae */
if(!s->budget--) { s->failed_pc=0x0c0110aeu; return 0; }
write(ram,r[4]+r[0],r[3],1);
goto P_0c0110b0;
P_0c0110b0: /* original d446, guest PC 0x0c0110b0 */
if(!s->budget--) { s->failed_pc=0x0c0110b0u; return 0; }
r[4]=read(ram,0x0c0111ccu,4);
goto P_0c0110b2;
P_0c0110b2: /* original ee00, guest PC 0x0c0110b2 */
if(!s->budget--) { s->failed_pc=0x0c0110b2u; return 0; }
r[14]=0x00000000u;
goto P_0c0110b4;
P_0c0110b4: /* original 60e3, guest PC 0x0c0110b4 */
if(!s->budget--) { s->failed_pc=0x0c0110b4u; return 0; }
r[0]=r[14];
goto P_0c0110b6;
P_0c0110b6: /* original 6342, guest PC 0x0c0110b6 */
if(!s->budget--) { s->failed_pc=0x0c0110b6u; return 0; }
tmp=read(ram,r[4],4);
r[3]=tmp;
goto P_0c0110b8;
P_0c0110b8: /* original 803c, guest PC 0x0c0110b8 */
if(!s->budget--) { s->failed_pc=0x0c0110b8u; return 0; }
write(ram,r[3]+12,r[0],1);
goto P_0c0110ba;
P_0c0110ba: /* original 6342, guest PC 0x0c0110ba */
if(!s->budget--) { s->failed_pc=0x0c0110bau; return 0; }
tmp=read(ram,r[4],4);
r[3]=tmp;
goto P_0c0110bc;
P_0c0110bc: /* original e024, guest PC 0x0c0110bc */
if(!s->budget--) { s->failed_pc=0x0c0110bcu; return 0; }
r[0]=0x00000024u;
goto P_0c0110be;
P_0c0110be: /* original 03e4, guest PC 0x0c0110be */
if(!s->budget--) { s->failed_pc=0x0c0110beu; return 0; }
write(ram,r[3]+r[0],r[14],1);
goto P_0c0110c0;
P_0c0110c0: /* original 63d2, guest PC 0x0c0110c0 */
if(!s->budget--) { s->failed_pc=0x0c0110c0u; return 0; }
tmp=read(ram,r[13],4);
r[3]=tmp;
goto P_0c0110c2;
P_0c0110c2: /* original e014, guest PC 0x0c0110c2 */
if(!s->budget--) { s->failed_pc=0x0c0110c2u; return 0; }
r[0]=0x00000014u;
goto P_0c0110c4;
P_0c0110c4: /* original e243, guest PC 0x0c0110c4 */
if(!s->budget--) { s->failed_pc=0x0c0110c4u; return 0; }
r[2]=0x00000043u;
goto P_0c0110c6;
P_0c0110c6: /* original 0324, guest PC 0x0c0110c6 */
if(!s->budget--) { s->failed_pc=0x0c0110c6u; return 0; }
write(ram,r[3]+r[0],r[2],1);
goto P_0c0110c8;
P_0c0110c8: /* original d341, guest PC 0x0c0110c8 */
if(!s->budget--) { s->failed_pc=0x0c0110c8u; return 0; }
r[3]=read(ram,0x0c0111d0u,4);
goto P_0c0110ca;
P_0c0110ca: /* original c700, guest PC 0x0c0110ca */
if(!s->budget--) { s->failed_pc=0x0c0110cau; return 0; }
r[0]=code_base|0x000110ccu;
goto P_0c0110cc;
P_0c0110cc: /* original d241, guest PC 0x0c0110cc */
if(!s->budget--) { s->failed_pc=0x0c0110ccu; return 0; }
r[2]=read(ram,0x0c0111d4u,4);
goto P_0c0110ce;
P_0c0110ce: /* original 330c, guest PC 0x0c0110ce */
if(!s->budget--) { s->failed_pc=0x0c0110ceu; return 0; }
r[3]+=r[0];
goto P_0c0110d0;
P_0c0110d0: /* original 6133, guest PC 0x0c0110d0 */
if(!s->budget--) { s->failed_pc=0x0c0110d0u; return 0; }
r[1]=r[3];
goto P_0c0110d2;
P_0c0110d2: /* original 212b, guest PC 0x0c0110d2 */
if(!s->budget--) { s->failed_pc=0x0c0110d2u; return 0; }
r[1]|=r[2];
goto P_0c0110d4;
P_0c0110d4: /* original 410b, guest PC 0x0c0110d4 */
if(!s->budget--) { s->failed_pc=0x0c0110d4u; return 0; }
target=r[1];
r[16]=code_base|0x0c0110d8u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0110d8u) { target=s->pc; goto dispatch; }
goto P_0c0110d8;
P_0c0110d6: /* original 0009, guest PC 0x0c0110d6 */
if(!s->budget--) { s->failed_pc=0x0c0110d6u; return 0; }
goto P_0c0110d8;
P_0c0110d8: /* original 63d2, guest PC 0x0c0110d8 */
if(!s->budget--) { s->failed_pc=0x0c0110d8u; return 0; }
tmp=read(ram,r[13],4);
r[3]=tmp;
goto P_0c0110da;
P_0c0110da: /* original e03c, guest PC 0x0c0110da */
if(!s->budget--) { s->failed_pc=0x0c0110dau; return 0; }
r[0]=0x0000003cu;
goto P_0c0110dc;
P_0c0110dc: /* original 03e4, guest PC 0x0c0110dc */
if(!s->budget--) { s->failed_pc=0x0c0110dcu; return 0; }
write(ram,r[3]+r[0],r[14],1);
goto P_0c0110de;
P_0c0110de: /* original 4f26, guest PC 0x0c0110de */
if(!s->budget--) { s->failed_pc=0x0c0110deu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0110e0;
P_0c0110e0: /* original 6df6, guest PC 0x0c0110e0 */
if(!s->budget--) { s->failed_pc=0x0c0110e0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0110e2;
P_0c0110e2: /* original 000b, guest PC 0x0c0110e2 */
if(!s->budget--) { s->failed_pc=0x0c0110e2u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0110e4: /* original 6ef6, guest PC 0x0c0110e4 */
if(!s->budget--) { s->failed_pc=0x0c0110e4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0110e6u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0110e6u; return 0; } return 1;
P_0c0512dc: /* original 7f24, guest PC 0x0c0512dc */
if(!s->budget--) { s->failed_pc=0x0c0512dcu; return 0; }
r[15]+=0x00000024u;
goto P_0c0512de;
P_0c0512de: /* original 000b, guest PC 0x0c0512de */
if(!s->budget--) { s->failed_pc=0x0c0512deu; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c0512e0: /* original 0009, guest PC 0x0c0512e0 */
if(!s->budget--) { s->failed_pc=0x0c0512e0u; return 0; }
if(!vf3_matrix_family(0x0c0512e2u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0512e2u; return 0; } return 1;
P_0c058780: /* original 4f22, guest PC 0x0c058780 */
if(!s->budget--) { s->failed_pc=0x0c058780u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c058782;
P_0c058782: /* original a048, guest PC 0x0c058782 */
if(!s->budget--) { s->failed_pc=0x0c058782u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c058816;
P_0c058784: /* original 4f22, guest PC 0x0c058784 */
if(!s->budget--) { s->failed_pc=0x0c058784u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
if(!vf3_matrix_family(0x0c058786u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c058786u; return 0; } return 1;
P_0c058788: /* original 4f22, guest PC 0x0c058788 */
if(!s->budget--) { s->failed_pc=0x0c058788u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c05878a;
P_0c05878a: /* original a025, guest PC 0x0c05878a */
if(!s->budget--) { s->failed_pc=0x0c05878au; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0587d8;
P_0c05878c: /* original 4f22, guest PC 0x0c05878c */
if(!s->budget--) { s->failed_pc=0x0c05878cu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
if(!vf3_matrix_family(0x0c05878eu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c05878eu; return 0; } return 1;
P_0c0587d8: /* original bf40, guest PC 0x0c0587d8 */
if(!s->budget--) { s->failed_pc=0x0c0587d8u; return 0; }
target=code_base|0x0c05865cu; r[16]=code_base|0x0c0587dcu;
r[5]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0587dcu) { target=s->pc; goto dispatch; }
goto P_0c0587dc;
P_0c0587da: /* original 65e3, guest PC 0x0c0587da */
if(!s->budget--) { s->failed_pc=0x0c0587dau; return 0; }
r[5]=r[14];
goto P_0c0587dc;
P_0c0587dc: /* original 2f06, guest PC 0x0c0587dc */
if(!s->budget--) { s->failed_pc=0x0c0587dcu; return 0; }
tmp=r[0]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0587de;
P_0c0587de: /* original e008, guest PC 0x0c0587de */
if(!s->budget--) { s->failed_pc=0x0c0587deu; return 0; }
r[0]=0x00000008u;
goto P_0c0587e0;
P_0c0587e0: /* original f096, guest PC 0x0c0587e0 */
if(!s->budget--) { s->failed_pc=0x0c0587e0u; return 0; }
vf3_matrix_load(s,ram,0,r[9]+r[0]);
goto P_0c0587e2;
P_0c0587e2: /* original 62e3, guest PC 0x0c0587e2 */
if(!s->budget--) { s->failed_pc=0x0c0587e2u; return 0; }
r[2]=r[14];
goto P_0c0587e4;
P_0c0587e4: /* original 72d0, guest PC 0x0c0587e4 */
if(!s->budget--) { s->failed_pc=0x0c0587e4u; return 0; }
r[2]+=0xffffffd0u;
goto P_0c0587e6;
P_0c0587e6: /* original 6583, guest PC 0x0c0587e6 */
if(!s->budget--) { s->failed_pc=0x0c0587e6u; return 0; }
r[5]=r[8];
goto P_0c0587e8;
P_0c0587e8: /* original f79d, guest PC 0x0c0587e8 */
if(!s->budget--) { s->failed_pc=0x0c0587e8u; return 0; }
fr[7]=0x3f800000u;
goto P_0c0587ea;
P_0c0587ea: /* original be89, guest PC 0x0c0587ea */
if(!s->budget--) { s->failed_pc=0x0c0587eau; return 0; }
target=code_base|0x0c058500u; r[16]=code_base|0x0c0587eeu;
fr[7]=vf3_fpu_binary(fr[7],fr[0],r[18],'/');
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0587eeu) { target=s->pc; goto dispatch; }
goto P_0c0587ee;
P_0c0587ec: /* original f703, guest PC 0x0c0587ec */
if(!s->budget--) { s->failed_pc=0x0c0587ecu; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[0],r[18],'/');
goto P_0c0587ee;
P_0c0587ee: /* original 0c83, guest PC 0x0c0587ee */
if(!s->budget--) { s->failed_pc=0x0c0587eeu; return 0; }
if((r[12]&0xFC000000u)==0xE0000000u) pref(ram,r[12]);
goto P_0c0587f0;
P_0c0587f0: /* original 7c20, guest PC 0x0c0587f0 */
if(!s->budget--) { s->failed_pc=0x0c0587f0u; return 0; }
r[12]+=0x00000020u;
goto P_0c0587f2;
P_0c0587f2: /* original fa9d, guest PC 0x0c0587f2 */
if(!s->budget--) { s->failed_pc=0x0c0587f2u; return 0; }
fr[10]=0x3f800000u;
goto P_0c0587f4;
P_0c0587f4: /* original fa23, guest PC 0x0c0587f4 */
if(!s->budget--) { s->failed_pc=0x0c0587f4u; return 0; }
fr[10]=vf3_fpu_binary(fr[10],fr[2],r[18],'/');
goto P_0c0587f6;
P_0c0587f6: /* original f80c, guest PC 0x0c0587f6 */
if(!s->budget--) { s->failed_pc=0x0c0587f6u; return 0; }
vf3_matrix_move(s,8,0);
goto P_0c0587f8;
P_0c0587f8: /* original 62e3, guest PC 0x0c0587f8 */
if(!s->budget--) { s->failed_pc=0x0c0587f8u; return 0; }
r[2]=r[14];
goto P_0c0587fa;
P_0c0587fa: /* original fc4c, guest PC 0x0c0587fa */
if(!s->budget--) { s->failed_pc=0x0c0587fau; return 0; }
vf3_matrix_move(s,12,4);
goto P_0c0587fc;
P_0c0587fc: /* original be80, guest PC 0x0c0587fc */
if(!s->budget--) { s->failed_pc=0x0c0587fcu; return 0; }
target=code_base|0x0c058500u; r[16]=code_base|0x0c058800u;
r[5]=r[6];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c058800u) { target=s->pc; goto dispatch; }
goto P_0c058800;
P_0c0587fe: /* original 6563, guest PC 0x0c0587fe */
if(!s->budget--) { s->failed_pc=0x0c0587feu; return 0; }
r[5]=r[6];
goto P_0c058800;
P_0c058800: /* original 0c83, guest PC 0x0c058800 */
if(!s->budget--) { s->failed_pc=0x0c058800u; return 0; }
if((r[12]&0xFC000000u)==0xE0000000u) pref(ram,r[12]);
goto P_0c058802;
P_0c058802: /* original fb9d, guest PC 0x0c058802 */
if(!s->budget--) { s->failed_pc=0x0c058802u; return 0; }
fr[11]=0x3f800000u;
goto P_0c058804;
P_0c058804: /* original 62e3, guest PC 0x0c058804 */
if(!s->budget--) { s->failed_pc=0x0c058804u; return 0; }
r[2]=r[14];
goto P_0c058806;
P_0c058806: /* original fb23, guest PC 0x0c058806 */
if(!s->budget--) { s->failed_pc=0x0c058806u; return 0; }
fr[11]=vf3_fpu_binary(fr[11],fr[2],r[18],'/');
goto P_0c058808;
P_0c058808: /* original f298, guest PC 0x0c058808 */
if(!s->budget--) { s->failed_pc=0x0c058808u; return 0; }
vf3_matrix_load(s,ram,2,r[9]);
goto P_0c05880a;
P_0c05880a: /* original 72e8, guest PC 0x0c05880a */
if(!s->budget--) { s->failed_pc=0x0c05880au; return 0; }
r[2]+=0xffffffe8u;
goto P_0c05880c;
P_0c05880c: /* original 6125, guest PC 0x0c05880c */
if(!s->budget--) { s->failed_pc=0x0c05880cu; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[2],2);
r[2]+=2;
r[1]=tmp;
goto P_0c05880e;
P_0c05880e: /* original f3fd, guest PC 0x0c05880e */
if(!s->budget--) { s->failed_pc=0x0c05880eu; return 0; }
r[18]^=0x100000u;
goto P_0c058810;
P_0c058810: /* original 6221, guest PC 0x0c058810 */
if(!s->budget--) { s->failed_pc=0x0c058810u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[2],2);
r[2]=tmp;
goto P_0c058812;
P_0c058812: /* original a01e, guest PC 0x0c058812 */
if(!s->budget--) { s->failed_pc=0x0c058812u; return 0; }
vf3_matrix_move(s,6,0);
goto P_0c058852;
P_0c058814: /* original f60c, guest PC 0x0c058814 */
if(!s->budget--) { s->failed_pc=0x0c058814u; return 0; }
vf3_matrix_move(s,6,0);
goto P_0c058816;
P_0c058816: /* original bf21, guest PC 0x0c058816 */
if(!s->budget--) { s->failed_pc=0x0c058816u; return 0; }
target=code_base|0x0c05865cu; r[16]=code_base|0x0c05881au;
r[5]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c05881au) { target=s->pc; goto dispatch; }
goto P_0c05881a;
P_0c058818: /* original 65e3, guest PC 0x0c058818 */
if(!s->budget--) { s->failed_pc=0x0c058818u; return 0; }
r[5]=r[14];
goto P_0c05881a;
P_0c05881a: /* original 2f06, guest PC 0x0c05881a */
if(!s->budget--) { s->failed_pc=0x0c05881au; return 0; }
tmp=r[0]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05881c;
P_0c05881c: /* original e008, guest PC 0x0c05881c */
if(!s->budget--) { s->failed_pc=0x0c05881cu; return 0; }
r[0]=0x00000008u;
goto P_0c05881e;
P_0c05881e: /* original f086, guest PC 0x0c05881e */
if(!s->budget--) { s->failed_pc=0x0c05881eu; return 0; }
vf3_matrix_load(s,ram,0,r[8]+r[0]);
goto P_0c058820;
P_0c058820: /* original 62e3, guest PC 0x0c058820 */
if(!s->budget--) { s->failed_pc=0x0c058820u; return 0; }
r[2]=r[14];
goto P_0c058822;
P_0c058822: /* original 72e8, guest PC 0x0c058822 */
if(!s->budget--) { s->failed_pc=0x0c058822u; return 0; }
r[2]+=0xffffffe8u;
goto P_0c058824;
P_0c058824: /* original 6593, guest PC 0x0c058824 */
if(!s->budget--) { s->failed_pc=0x0c058824u; return 0; }
r[5]=r[9];
goto P_0c058826;
P_0c058826: /* original f79d, guest PC 0x0c058826 */
if(!s->budget--) { s->failed_pc=0x0c058826u; return 0; }
fr[7]=0x3f800000u;
goto P_0c058828;
P_0c058828: /* original be6a, guest PC 0x0c058828 */
if(!s->budget--) { s->failed_pc=0x0c058828u; return 0; }
target=code_base|0x0c058500u; r[16]=code_base|0x0c05882cu;
fr[7]=vf3_fpu_binary(fr[7],fr[0],r[18],'/');
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c05882cu) { target=s->pc; goto dispatch; }
goto P_0c05882c;
P_0c05882a: /* original f703, guest PC 0x0c05882a */
if(!s->budget--) { s->failed_pc=0x0c05882au; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[0],r[18],'/');
goto P_0c05882c;
P_0c05882c: /* original 0c83, guest PC 0x0c05882c */
if(!s->budget--) { s->failed_pc=0x0c05882cu; return 0; }
if((r[12]&0xFC000000u)==0xE0000000u) pref(ram,r[12]);
goto P_0c05882e;
P_0c05882e: /* original 7c20, guest PC 0x0c05882e */
if(!s->budget--) { s->failed_pc=0x0c05882eu; return 0; }
r[12]+=0x00000020u;
goto P_0c058830;
P_0c058830: /* original f80c, guest PC 0x0c058830 */
if(!s->budget--) { s->failed_pc=0x0c058830u; return 0; }
vf3_matrix_move(s,8,0);
goto P_0c058832;
P_0c058832: /* original fa9d, guest PC 0x0c058832 */
if(!s->budget--) { s->failed_pc=0x0c058832u; return 0; }
fr[10]=0x3f800000u;
goto P_0c058834;
P_0c058834: /* original fa23, guest PC 0x0c058834 */
if(!s->budget--) { s->failed_pc=0x0c058834u; return 0; }
fr[10]=vf3_fpu_binary(fr[10],fr[2],r[18],'/');
goto P_0c058836;
P_0c058836: /* original fc4c, guest PC 0x0c058836 */
if(!s->budget--) { s->failed_pc=0x0c058836u; return 0; }
vf3_matrix_move(s,12,4);
goto P_0c058838;
P_0c058838: /* original 62e3, guest PC 0x0c058838 */
if(!s->budget--) { s->failed_pc=0x0c058838u; return 0; }
r[2]=r[14];
goto P_0c05883a;
P_0c05883a: /* original be61, guest PC 0x0c05883a */
if(!s->budget--) { s->failed_pc=0x0c05883au; return 0; }
target=code_base|0x0c058500u; r[16]=code_base|0x0c05883eu;
r[5]=r[6];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c05883eu) { target=s->pc; goto dispatch; }
goto P_0c05883e;
P_0c05883c: /* original 6563, guest PC 0x0c05883c */
if(!s->budget--) { s->failed_pc=0x0c05883cu; return 0; }
r[5]=r[6];
goto P_0c05883e;
P_0c05883e: /* original 0c83, guest PC 0x0c05883e */
if(!s->budget--) { s->failed_pc=0x0c05883eu; return 0; }
if((r[12]&0xFC000000u)==0xE0000000u) pref(ram,r[12]);
goto P_0c058840;
P_0c058840: /* original fb9d, guest PC 0x0c058840 */
if(!s->budget--) { s->failed_pc=0x0c058840u; return 0; }
fr[11]=0x3f800000u;
goto P_0c058842;
P_0c058842: /* original 62e3, guest PC 0x0c058842 */
if(!s->budget--) { s->failed_pc=0x0c058842u; return 0; }
r[2]=r[14];
goto P_0c058844;
P_0c058844: /* original fb23, guest PC 0x0c058844 */
if(!s->budget--) { s->failed_pc=0x0c058844u; return 0; }
fr[11]=vf3_fpu_binary(fr[11],fr[2],r[18],'/');
goto P_0c058846;
P_0c058846: /* original 72d0, guest PC 0x0c058846 */
if(!s->budget--) { s->failed_pc=0x0c058846u; return 0; }
r[2]+=0xffffffd0u;
goto P_0c058848;
P_0c058848: /* original f288, guest PC 0x0c058848 */
if(!s->budget--) { s->failed_pc=0x0c058848u; return 0; }
vf3_matrix_load(s,ram,2,r[8]);
goto P_0c05884a;
P_0c05884a: /* original 6125, guest PC 0x0c05884a */
if(!s->budget--) { s->failed_pc=0x0c05884au; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[2],2);
r[2]+=2;
r[1]=tmp;
goto P_0c05884c;
P_0c05884c: /* original f3fd, guest PC 0x0c05884c */
if(!s->budget--) { s->failed_pc=0x0c05884cu; return 0; }
r[18]^=0x100000u;
goto P_0c05884e;
P_0c05884e: /* original 6221, guest PC 0x0c05884e */
if(!s->budget--) { s->failed_pc=0x0c05884eu; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[2],2);
r[2]=tmp;
goto P_0c058850;
P_0c058850: /* original f60c, guest PC 0x0c058850 */
if(!s->budget--) { s->failed_pc=0x0c058850u; return 0; }
vf3_matrix_move(s,6,0);
goto P_0c058852;
P_0c058852: /* original c607, guest PC 0x0c058852 */
if(!s->budget--) { s->failed_pc=0x0c058852u; return 0; }
if(!s->gbr_known) goto unsupported;
r[0]=read(ram,s->gbr+28,4);
goto P_0c058854;
P_0c058854: /* original f8a2, guest PC 0x0c058854 */
if(!s->budget--) { s->failed_pc=0x0c058854u; return 0; }
fr[8]=vf3_fpu_binary(fr[8],fr[10],r[18],'*');
goto P_0c058856;
P_0c058856: /* original f9a2, guest PC 0x0c058856 */
if(!s->budget--) { s->failed_pc=0x0c058856u; return 0; }
fr[9]=vf3_fpu_binary(fr[9],fr[10],r[18],'*');
goto P_0c058858;
P_0c058858: /* original f272, guest PC 0x0c058858 */
if(!s->budget--) { s->failed_pc=0x0c058858u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[7],r[18],'*');
goto P_0c05885a;
P_0c05885a: /* original f372, guest PC 0x0c05885a */
if(!s->budget--) { s->failed_pc=0x0c05885au; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[7],r[18],'*');
goto P_0c05885c;
P_0c05885c: /* original 405a, guest PC 0x0c05885c */
if(!s->budget--) { s->failed_pc=0x0c05885cu; return 0; }
r[53]=r[0];
goto P_0c05885e;
P_0c05885e: /* original fa71, guest PC 0x0c05885e */
if(!s->budget--) { s->failed_pc=0x0c05885eu; return 0; }
fr[10]=vf3_fpu_binary(fr[10],fr[7],r[18],'-');
goto P_0c058860;
P_0c058860: /* original f00d, guest PC 0x0c058860 */
if(!s->budget--) { s->failed_pc=0x0c058860u; return 0; }
fr[0]=r[53];
goto P_0c058862;
P_0c058862: /* original f071, guest PC 0x0c058862 */
if(!s->budget--) { s->failed_pc=0x0c058862u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[7],r[18],'-');
goto P_0c058864;
P_0c058864: /* original f6b2, guest PC 0x0c058864 */
if(!s->budget--) { s->failed_pc=0x0c058864u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[11],r[18],'*');
goto P_0c058866;
P_0c058866: /* original f1b2, guest PC 0x0c058866 */
if(!s->budget--) { s->failed_pc=0x0c058866u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[11],r[18],'*');
goto P_0c058868;
P_0c058868: /* original fb71, guest PC 0x0c058868 */
if(!s->budget--) { s->failed_pc=0x0c058868u; return 0; }
fr[11]=vf3_fpu_binary(fr[11],fr[7],r[18],'-');
goto P_0c05886a;
P_0c05886a: /* original ff0b, guest PC 0x0c05886a */
if(!s->budget--) { s->failed_pc=0x0c05886au; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[15]);
goto P_0c05886c;
P_0c05886c: /* original f0a3, guest PC 0x0c05886c */
if(!s->budget--) { s->failed_pc=0x0c05886cu; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[10],r[18],'/');
goto P_0c05886e;
P_0c05886e: /* original f821, guest PC 0x0c05886e */
if(!s->budget--) { s->failed_pc=0x0c05886eu; return 0; }
fr[8]=vf3_fpu_binary(fr[8],fr[2],r[18],'-');
goto P_0c058870;
P_0c058870: /* original f931, guest PC 0x0c058870 */
if(!s->budget--) { s->failed_pc=0x0c058870u; return 0; }
fr[9]=vf3_fpu_binary(fr[9],fr[3],r[18],'-');
goto P_0c058872;
P_0c058872: /* original 425a, guest PC 0x0c058872 */
if(!s->budget--) { s->failed_pc=0x0c058872u; return 0; }
r[53]=r[2];
goto P_0c058874;
P_0c058874: /* original fe2d, guest PC 0x0c058874 */
if(!s->budget--) { s->failed_pc=0x0c058874u; return 0; }
fr[14]=vf3_fpu_float(r[53],r[18]);
goto P_0c058876;
P_0c058876: /* original 415a, guest PC 0x0c058876 */
if(!s->budget--) { s->failed_pc=0x0c058876u; return 0; }
r[53]=r[1];
goto P_0c058878;
P_0c058878: /* original fa2d, guest PC 0x0c058878 */
if(!s->budget--) { s->failed_pc=0x0c058878u; return 0; }
fr[10]=vf3_fpu_float(r[53],r[18]);
goto P_0c05887a;
P_0c05887a: /* original f621, guest PC 0x0c05887a */
if(!s->budget--) { s->failed_pc=0x0c05887au; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[2],r[18],'-');
goto P_0c05887c;
P_0c05887c: /* original 60f6, guest PC 0x0c05887c */
if(!s->budget--) { s->failed_pc=0x0c05887cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[0]=tmp;
goto P_0c05887e;
P_0c05887e: /* original f131, guest PC 0x0c05887e */
if(!s->budget--) { s->failed_pc=0x0c05887eu; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[3],r[18],'-');
goto P_0c058880;
P_0c058880: /* original 61f6, guest PC 0x0c058880 */
if(!s->budget--) { s->failed_pc=0x0c058880u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[1]=tmp;
goto P_0c058882;
P_0c058882: /* original fef2, guest PC 0x0c058882 */
if(!s->budget--) { s->failed_pc=0x0c058882u; return 0; }
fr[14]=vf3_fpu_binary(fr[14],fr[15],r[18],'*');
goto P_0c058884;
P_0c058884: /* original faf2, guest PC 0x0c058884 */
if(!s->budget--) { s->failed_pc=0x0c058884u; return 0; }
fr[10]=vf3_fpu_binary(fr[10],fr[15],r[18],'*');
goto P_0c058886;
P_0c058886: /* original 4f26, guest PC 0x0c058886 */
if(!s->budget--) { s->failed_pc=0x0c058886u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c058888;
P_0c058888: /* original fde1, guest PC 0x0c058888 */
if(!s->budget--) { s->failed_pc=0x0c058888u; return 0; }
fr[13]=vf3_fpu_binary(fr[13],fr[14],r[18],'-');
goto P_0c05888a;
P_0c05888a: /* original fca1, guest PC 0x0c05888a */
if(!s->budget--) { s->failed_pc=0x0c05888au; return 0; }
fr[12]=vf3_fpu_binary(fr[12],fr[10],r[18],'-');
goto P_0c05888c;
P_0c05888c: /* original 405a, guest PC 0x0c05888c */
if(!s->budget--) { s->failed_pc=0x0c05888cu; return 0; }
r[53]=r[0];
goto P_0c05888e;
P_0c05888e: /* original f5e1, guest PC 0x0c05888e */
if(!s->budget--) { s->failed_pc=0x0c05888eu; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[14],r[18],'-');
goto P_0c058890;
P_0c058890: /* original 7c3c, guest PC 0x0c058890 */
if(!s->budget--) { s->failed_pc=0x0c058890u; return 0; }
r[12]+=0x0000003cu;
goto P_0c058892;
P_0c058892: /* original f4a1, guest PC 0x0c058892 */
if(!s->budget--) { s->failed_pc=0x0c058892u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[10],r[18],'-');
goto P_0c058894;
P_0c058894: /* original ff3c, guest PC 0x0c058894 */
if(!s->budget--) { s->failed_pc=0x0c058894u; return 0; }
vf3_matrix_move(s,15,3);
goto P_0c058896;
P_0c058896: /* original ff9e, guest PC 0x0c058896 */
if(!s->budget--) { s->failed_pc=0x0c058896u; return 0; }
fr[15]=vf3_fpu_mac(fr[0],fr[9],fr[15],r[18]);
goto P_0c058898;
P_0c058898: /* original f92c, guest PC 0x0c058898 */
if(!s->budget--) { s->failed_pc=0x0c058898u; return 0; }
vf3_matrix_move(s,9,2);
goto P_0c05889a;
P_0c05889a: /* original f98e, guest PC 0x0c05889a */
if(!s->budget--) { s->failed_pc=0x0c05889au; return 0; }
fr[9]=vf3_fpu_mac(fr[0],fr[8],fr[9],r[18]);
goto P_0c05889c;
P_0c05889c: /* original f8ec, guest PC 0x0c05889c */
if(!s->budget--) { s->failed_pc=0x0c05889cu; return 0; }
vf3_matrix_move(s,8,14);
goto P_0c05889e;
P_0c05889e: /* original f8de, guest PC 0x0c05889e */
if(!s->budget--) { s->failed_pc=0x0c05889eu; return 0; }
fr[8]=vf3_fpu_mac(fr[0],fr[13],fr[8],r[18]);
goto P_0c0588a0;
P_0c0588a0: /* original fdac, guest PC 0x0c0588a0 */
if(!s->budget--) { s->failed_pc=0x0c0588a0u; return 0; }
vf3_matrix_move(s,13,10);
goto P_0c0588a2;
P_0c0588a2: /* original fdce, guest PC 0x0c0588a2 */
if(!s->budget--) { s->failed_pc=0x0c0588a2u; return 0; }
fr[13]=vf3_fpu_mac(fr[0],fr[12],fr[13],r[18]);
goto P_0c0588a4;
P_0c0588a4: /* original f00d, guest PC 0x0c0588a4 */
if(!s->budget--) { s->failed_pc=0x0c0588a4u; return 0; }
fr[0]=r[53];
goto P_0c0588a6;
P_0c0588a6: /* original f0b3, guest PC 0x0c0588a6 */
if(!s->budget--) { s->failed_pc=0x0c0588a6u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[11],r[18],'/');
goto P_0c0588a8;
P_0c0588a8: /* original 4a5a, guest PC 0x0c0588a8 */
if(!s->budget--) { s->failed_pc=0x0c0588a8u; return 0; }
r[53]=r[10];
goto P_0c0588aa;
P_0c0588aa: /* original fc0d, guest PC 0x0c0588aa */
if(!s->budget--) { s->failed_pc=0x0c0588aau; return 0; }
fr[12]=r[53];
goto P_0c0588ac;
P_0c0588ac: /* original ffc2, guest PC 0x0c0588ac */
if(!s->budget--) { s->failed_pc=0x0c0588acu; return 0; }
fr[15]=vf3_fpu_binary(fr[15],fr[12],r[18],'*');
goto P_0c0588ae;
P_0c0588ae: /* original c618, guest PC 0x0c0588ae */
if(!s->budget--) { s->failed_pc=0x0c0588aeu; return 0; }
if(!s->gbr_known) goto unsupported;
r[0]=read(ram,s->gbr+96,4);
goto P_0c0588b0;
P_0c0588b0: /* original f9c2, guest PC 0x0c0588b0 */
if(!s->budget--) { s->failed_pc=0x0c0588b0u; return 0; }
fr[9]=vf3_fpu_binary(fr[9],fr[12],r[18],'*');
goto P_0c0588b2;
P_0c0588b2: /* original 2c12, guest PC 0x0c0588b2 */
if(!s->budget--) { s->failed_pc=0x0c0588b2u; return 0; }
write(ram,r[12],r[1],4);
goto P_0c0588b4;
P_0c0588b4: /* original 2c06, guest PC 0x0c0588b4 */
if(!s->budget--) { s->failed_pc=0x0c0588b4u; return 0; }
tmp=r[0]; r[12]-=4; write(ram,r[12],tmp,4);
goto P_0c0588b6;
P_0c0588b6: /* original fc8b, guest PC 0x0c0588b6 */
if(!s->budget--) { s->failed_pc=0x0c0588b6u; return 0; }
r[12]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,8,r[12]);
goto P_0c0588b8;
P_0c0588b8: /* original fcdb, guest PC 0x0c0588b8 */
if(!s->budget--) { s->failed_pc=0x0c0588b8u; return 0; }
r[12]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,13,r[12]);
goto P_0c0588ba;
P_0c0588ba: /* original 2ca6, guest PC 0x0c0588ba */
if(!s->budget--) { s->failed_pc=0x0c0588bau; return 0; }
tmp=r[10]; r[12]-=4; write(ram,r[12],tmp,4);
goto P_0c0588bc;
P_0c0588bc: /* original fcfb, guest PC 0x0c0588bc */
if(!s->budget--) { s->failed_pc=0x0c0588bcu; return 0; }
r[12]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[12]);
goto P_0c0588be;
P_0c0588be: /* original fc9b, guest PC 0x0c0588be */
if(!s->budget--) { s->failed_pc=0x0c0588beu; return 0; }
r[12]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,9,r[12]);
goto P_0c0588c0;
P_0c0588c0: /* original 2cc6, guest PC 0x0c0588c0 */
if(!s->budget--) { s->failed_pc=0x0c0588c0u; return 0; }
tmp=r[12]; r[12]-=4; write(ram,r[12],tmp,4);
goto P_0c0588c2;
P_0c0588c2: /* original 0c83, guest PC 0x0c0588c2 */
if(!s->budget--) { s->failed_pc=0x0c0588c2u; return 0; }
if((r[12]&0xFC000000u)==0xE0000000u) pref(ram,r[12]);
goto P_0c0588c4;
P_0c0588c4: /* original 7c2c, guest PC 0x0c0588c4 */
if(!s->budget--) { s->failed_pc=0x0c0588c4u; return 0; }
r[12]+=0x0000002cu;
goto P_0c0588c6;
P_0c0588c6: /* original f31e, guest PC 0x0c0588c6 */
if(!s->budget--) { s->failed_pc=0x0c0588c6u; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[1],fr[3],r[18]);
goto P_0c0588c8;
P_0c0588c8: /* original 2ca2, guest PC 0x0c0588c8 */
if(!s->budget--) { s->failed_pc=0x0c0588c8u; return 0; }
write(ram,r[12],r[10],4);
goto P_0c0588ca;
P_0c0588ca: /* original f26e, guest PC 0x0c0588ca */
if(!s->budget--) { s->failed_pc=0x0c0588cau; return 0; }
fr[2]=vf3_fpu_mac(fr[0],fr[6],fr[2],r[18]);
goto P_0c0588cc;
P_0c0588cc: /* original 7c04, guest PC 0x0c0588cc */
if(!s->budget--) { s->failed_pc=0x0c0588ccu; return 0; }
r[12]+=0x00000004u;
goto P_0c0588ce;
P_0c0588ce: /* original fe5e, guest PC 0x0c0588ce */
if(!s->budget--) { s->failed_pc=0x0c0588ceu; return 0; }
fr[14]=vf3_fpu_mac(fr[0],fr[5],fr[14],r[18]);
goto P_0c0588d0;
P_0c0588d0: /* original 1c02, guest PC 0x0c0588d0 */
if(!s->budget--) { s->failed_pc=0x0c0588d0u; return 0; }
write(ram,r[12]+8,r[0],4);
goto P_0c0588d2;
P_0c0588d2: /* original fa4e, guest PC 0x0c0588d2 */
if(!s->budget--) { s->failed_pc=0x0c0588d2u; return 0; }
fr[10]=vf3_fpu_mac(fr[0],fr[4],fr[10],r[18]);
goto P_0c0588d4;
P_0c0588d4: /* original e004, guest PC 0x0c0588d4 */
if(!s->budget--) { s->failed_pc=0x0c0588d4u; return 0; }
r[0]=0x00000004u;
goto P_0c0588d6;
P_0c0588d6: /* original f3c2, guest PC 0x0c0588d6 */
if(!s->budget--) { s->failed_pc=0x0c0588d6u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[12],r[18],'*');
goto P_0c0588d8;
P_0c0588d8: /* original 1c13, guest PC 0x0c0588d8 */
if(!s->budget--) { s->failed_pc=0x0c0588d8u; return 0; }
write(ram,r[12]+12,r[1],4);
goto P_0c0588da;
P_0c0588da: /* original f2c2, guest PC 0x0c0588da */
if(!s->budget--) { s->failed_pc=0x0c0588dau; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[12],r[18],'*');
goto P_0c0588dc;
P_0c0588dc: /* original fce7, guest PC 0x0c0588dc */
if(!s->budget--) { s->failed_pc=0x0c0588dcu; return 0; }
vf3_matrix_store(s,ram,14,r[12]+r[0]);
goto P_0c0588de;
P_0c0588de: /* original fcaa, guest PC 0x0c0588de */
if(!s->budget--) { s->failed_pc=0x0c0588deu; return 0; }
vf3_matrix_store(s,ram,10,r[12]);
goto P_0c0588e0;
P_0c0588e0: /* original 7cf8, guest PC 0x0c0588e0 */
if(!s->budget--) { s->failed_pc=0x0c0588e0u; return 0; }
r[12]+=0xfffffff8u;
goto P_0c0588e2;
P_0c0588e2: /* original fc3a, guest PC 0x0c0588e2 */
if(!s->budget--) { s->failed_pc=0x0c0588e2u; return 0; }
vf3_matrix_store(s,ram,3,r[12]);
goto P_0c0588e4;
P_0c0588e4: /* original fc2b, guest PC 0x0c0588e4 */
if(!s->budget--) { s->failed_pc=0x0c0588e4u; return 0; }
r[12]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[12]);
goto P_0c0588e6;
P_0c0588e6: /* original f3fd, guest PC 0x0c0588e6 */
if(!s->budget--) { s->failed_pc=0x0c0588e6u; return 0; }
r[18]^=0x100000u;
goto P_0c0588e8;
P_0c0588e8: /* original 7cfc, guest PC 0x0c0588e8 */
if(!s->budget--) { s->failed_pc=0x0c0588e8u; return 0; }
r[12]+=0xfffffffcu;
goto P_0c0588ea;
P_0c0588ea: /* original f498, guest PC 0x0c0588ea */
if(!s->budget--) { s->failed_pc=0x0c0588eau; return 0; }
vf3_matrix_load(s,ram,4,r[9]);
goto P_0c0588ec;
P_0c0588ec: /* original 000b, guest PC 0x0c0588ec */
if(!s->budget--) { s->failed_pc=0x0c0588ecu; return 0; }
target=r[16];
vf3_matrix_load(s,ram,8,r[6]);
s->pc=target; return ram->oob==0;
P_0c0588ee: /* original f868, guest PC 0x0c0588ee */
if(!s->budget--) { s->failed_pc=0x0c0588eeu; return 0; }
vf3_matrix_load(s,ram,8,r[6]);
if(!vf3_matrix_family(0x0c0588f0u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0588f0u; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
static const uint32_t owned_pcs[]={
0x0c011090u,0x0c011092u,0x0c011094u,0x0c011096u,0x0c011098u,0x0c01109au,0x0c01109cu,0x0c01109eu,0x0c0110a0u,0x0c0110a2u,0x0c0110a4u,0x0c0110a6u,0x0c0110a8u,0x0c0110aau,0x0c0110acu,0x0c0110aeu,
0x0c0110b0u,0x0c0110b2u,0x0c0110b4u,0x0c0110b6u,0x0c0110b8u,0x0c0110bau,0x0c0110bcu,0x0c0110beu,0x0c0110c0u,0x0c0110c2u,0x0c0110c4u,0x0c0110c6u,0x0c0110c8u,0x0c0110cau,0x0c0110ccu,0x0c0110ceu,
0x0c0110d0u,0x0c0110d2u,0x0c0110d4u,0x0c0110d6u,0x0c0110d8u,0x0c0110dau,0x0c0110dcu,0x0c0110deu,0x0c0110e0u,0x0c0110e2u,0x0c0110e4u,0x0c0512dcu,0x0c0512deu,0x0c0512e0u,0x0c058780u,0x0c058782u,
0x0c058784u,0x0c058788u,0x0c05878au,0x0c05878cu,0x0c0587d8u,0x0c0587dau,0x0c0587dcu,0x0c0587deu,0x0c0587e0u,0x0c0587e2u,0x0c0587e4u,0x0c0587e6u,0x0c0587e8u,0x0c0587eau,0x0c0587ecu,0x0c0587eeu,
0x0c0587f0u,0x0c0587f2u,0x0c0587f4u,0x0c0587f6u,0x0c0587f8u,0x0c0587fau,0x0c0587fcu,0x0c0587feu,0x0c058800u,0x0c058802u,0x0c058804u,0x0c058806u,0x0c058808u,0x0c05880au,0x0c05880cu,0x0c05880eu,
0x0c058810u,0x0c058812u,0x0c058814u,0x0c058816u,0x0c058818u,0x0c05881au,0x0c05881cu,0x0c05881eu,0x0c058820u,0x0c058822u,0x0c058824u,0x0c058826u,0x0c058828u,0x0c05882au,0x0c05882cu,0x0c05882eu,
0x0c058830u,0x0c058832u,0x0c058834u,0x0c058836u,0x0c058838u,0x0c05883au,0x0c05883cu,0x0c05883eu,0x0c058840u,0x0c058842u,0x0c058844u,0x0c058846u,0x0c058848u,0x0c05884au,0x0c05884cu,0x0c05884eu,
0x0c058850u,0x0c058852u,0x0c058854u,0x0c058856u,0x0c058858u,0x0c05885au,0x0c05885cu,0x0c05885eu,0x0c058860u,0x0c058862u,0x0c058864u,0x0c058866u,0x0c058868u,0x0c05886au,0x0c05886cu,0x0c05886eu,
0x0c058870u,0x0c058872u,0x0c058874u,0x0c058876u,0x0c058878u,0x0c05887au,0x0c05887cu,0x0c05887eu,0x0c058880u,0x0c058882u,0x0c058884u,0x0c058886u,0x0c058888u,0x0c05888au,0x0c05888cu,0x0c05888eu,
0x0c058890u,0x0c058892u,0x0c058894u,0x0c058896u,0x0c058898u,0x0c05889au,0x0c05889cu,0x0c05889eu,0x0c0588a0u,0x0c0588a2u,0x0c0588a4u,0x0c0588a6u,0x0c0588a8u,0x0c0588aau,0x0c0588acu,0x0c0588aeu,
0x0c0588b0u,0x0c0588b2u,0x0c0588b4u,0x0c0588b6u,0x0c0588b8u,0x0c0588bau,0x0c0588bcu,0x0c0588beu,0x0c0588c0u,0x0c0588c2u,0x0c0588c4u,0x0c0588c6u,0x0c0588c8u,0x0c0588cau,0x0c0588ccu,0x0c0588ceu,
0x0c0588d0u,0x0c0588d2u,0x0c0588d4u,0x0c0588d6u,0x0c0588d8u,0x0c0588dau,0x0c0588dcu,0x0c0588deu,0x0c0588e0u,0x0c0588e2u,0x0c0588e4u,0x0c0588e6u,0x0c0588e8u,0x0c0588eau,0x0c0588ecu,0x0c0588eeu,
};
static const uint32_t claim_pcs[]={
0x0c011090u,0x0c011092u,0x0c011094u,0x0c011096u,0x0c011098u,0x0c01109au,0x0c01109cu,0x0c01109eu,0x0c0110a0u,0x0c0110a2u,0x0c0110a4u,0x0c0110a6u,0x0c0110a8u,0x0c0110aau,0x0c0110acu,0x0c0110aeu,
0x0c0110b0u,0x0c0110b2u,0x0c0110b4u,0x0c0110b6u,0x0c0110b8u,0x0c0110bau,0x0c0110bcu,0x0c0110beu,0x0c0110c0u,0x0c0110c2u,0x0c0110c4u,0x0c0110c6u,0x0c0110c8u,0x0c0110cau,0x0c0110ccu,0x0c0110ceu,
0x0c0110d0u,0x0c0110d2u,0x0c0110d4u,0x0c0110d6u,0x0c0110d8u,0x0c0110dau,0x0c0110dcu,0x0c0110deu,0x0c0110e0u,0x0c0110e2u,0x0c0110e4u,0x0c0512dcu,0x0c058780u,0x0c058784u,0x0c058788u,0x0c05878cu,
};
int vf3_c102_adapter_contains(uint32_t pc) {
pc&=0x1fffffffu; unsigned lo=0,hi=sizeof(claim_pcs)/sizeof(claim_pcs[0]);
while(lo<hi) { unsigned mid=lo+(hi-lo)/2; if(claim_pcs[mid]<pc) lo=mid+1; else hi=mid; }
return lo<sizeof(claim_pcs)/sizeof(claim_pcs[0]) && claim_pcs[lo]==pc;
}
