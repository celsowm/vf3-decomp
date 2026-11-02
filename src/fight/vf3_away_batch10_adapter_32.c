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
int vf3_away_batch10_adapter_32(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c07b5b0u: goto P_0c07b5b0;
case 0x0c07b5b2u: goto P_0c07b5b2;
case 0x0c07b5b4u: goto P_0c07b5b4;
case 0x0c07b5b6u: goto P_0c07b5b6;
case 0x0c07b5b8u: goto P_0c07b5b8;
case 0x0c07b5bau: goto P_0c07b5ba;
case 0x0c07b5bcu: goto P_0c07b5bc;
case 0x0c07b5beu: goto P_0c07b5be;
case 0x0c07b5c0u: goto P_0c07b5c0;
case 0x0c07b5c2u: goto P_0c07b5c2;
case 0x0c07b5c4u: goto P_0c07b5c4;
case 0x0c07b5c6u: goto P_0c07b5c6;
case 0x0c07b5c8u: goto P_0c07b5c8;
case 0x0c07b5cau: goto P_0c07b5ca;
case 0x0c07b5ccu: goto P_0c07b5cc;
case 0x0c07b6c4u: goto P_0c07b6c4;
case 0x0c07b6c6u: goto P_0c07b6c6;
case 0x0c07b6c8u: goto P_0c07b6c8;
case 0x0c07b6cau: goto P_0c07b6ca;
case 0x0c07b6ccu: goto P_0c07b6cc;
case 0x0c07b6ceu: goto P_0c07b6ce;
case 0x0c07b6d0u: goto P_0c07b6d0;
case 0x0c07b6d2u: goto P_0c07b6d2;
case 0x0c07b6d4u: goto P_0c07b6d4;
case 0x0c07b6d6u: goto P_0c07b6d6;
case 0x0c07b6d8u: goto P_0c07b6d8;
case 0x0c07b6dau: goto P_0c07b6da;
case 0x0c07b6dcu: goto P_0c07b6dc;
case 0x0c07b6deu: goto P_0c07b6de;
case 0x0c07b6e0u: goto P_0c07b6e0;
case 0x0c07b6e2u: goto P_0c07b6e2;
case 0x0c07b6e4u: goto P_0c07b6e4;
case 0x0c07b6e6u: goto P_0c07b6e6;
case 0x0c07b6e8u: goto P_0c07b6e8;
case 0x0c07b6eau: goto P_0c07b6ea;
case 0x0c07b6ecu: goto P_0c07b6ec;
case 0x0c07b6eeu: goto P_0c07b6ee;
case 0x0c07b6f0u: goto P_0c07b6f0;
case 0x0c07b6f2u: goto P_0c07b6f2;
case 0x0c091dbeu: goto P_0c091dbe;
case 0x0c091dc0u: goto P_0c091dc0;
case 0x0c091dc2u: goto P_0c091dc2;
case 0x0c091dc4u: goto P_0c091dc4;
case 0x0c091dc6u: goto P_0c091dc6;
case 0x0c091dc8u: goto P_0c091dc8;
case 0x0c091dcau: goto P_0c091dca;
case 0x0c091dccu: goto P_0c091dcc;
case 0x0c091dceu: goto P_0c091dce;
case 0x0c091dd0u: goto P_0c091dd0;
case 0x0c091dd2u: goto P_0c091dd2;
case 0x0c091dd4u: goto P_0c091dd4;
case 0x0c091dd6u: goto P_0c091dd6;
case 0x0c091dd8u: goto P_0c091dd8;
case 0x0c091ddau: goto P_0c091dda;
case 0x0c091ddcu: goto P_0c091ddc;
case 0x0c091ddeu: goto P_0c091dde;
case 0x0c091de0u: goto P_0c091de0;
case 0x0c091de2u: goto P_0c091de2;
case 0x0c091de4u: goto P_0c091de4;
case 0x0c091de6u: goto P_0c091de6;
case 0x0c091de8u: goto P_0c091de8;
case 0x0c091deau: goto P_0c091dea;
case 0x0c091decu: goto P_0c091dec;
case 0x0c091deeu: goto P_0c091dee;
case 0x0c091df0u: goto P_0c091df0;
case 0x0c091df2u: goto P_0c091df2;
case 0x0c091df4u: goto P_0c091df4;
case 0x0c091df6u: goto P_0c091df6;
case 0x0c091df8u: goto P_0c091df8;
case 0x0c091dfau: goto P_0c091dfa;
case 0x0c091dfcu: goto P_0c091dfc;
case 0x0c091dfeu: goto P_0c091dfe;
case 0x0c091e00u: goto P_0c091e00;
case 0x0c091e02u: goto P_0c091e02;
case 0x0c091e04u: goto P_0c091e04;
case 0x0c091e06u: goto P_0c091e06;
case 0x0c091e08u: goto P_0c091e08;
case 0x0c091e0au: goto P_0c091e0a;
case 0x0c091e0cu: goto P_0c091e0c;
case 0x0c091e0eu: goto P_0c091e0e;
case 0x0c091e10u: goto P_0c091e10;
case 0x0c091e12u: goto P_0c091e12;
case 0x0c091e14u: goto P_0c091e14;
case 0x0c091e16u: goto P_0c091e16;
case 0x0c091e18u: goto P_0c091e18;
case 0x0c091e1au: goto P_0c091e1a;
case 0x0c091e1cu: goto P_0c091e1c;
case 0x0c091e1eu: goto P_0c091e1e;
case 0x0c091e20u: goto P_0c091e20;
case 0x0c091e22u: goto P_0c091e22;
case 0x0c091e24u: goto P_0c091e24;
case 0x0c091e26u: goto P_0c091e26;
case 0x0c091e28u: goto P_0c091e28;
case 0x0c091e2au: goto P_0c091e2a;
case 0x0c091e2cu: goto P_0c091e2c;
case 0x0c091e2eu: goto P_0c091e2e;
case 0x0c091e30u: goto P_0c091e30;
case 0x0c091e32u: goto P_0c091e32;
case 0x0c091e34u: goto P_0c091e34;
case 0x0c091e36u: goto P_0c091e36;
case 0x0c091e38u: goto P_0c091e38;
case 0x0c091e3au: goto P_0c091e3a;
case 0x0c091e3cu: goto P_0c091e3c;
case 0x0c091e3eu: goto P_0c091e3e;
case 0x0c091e40u: goto P_0c091e40;
case 0x0c091e42u: goto P_0c091e42;
case 0x0c091e44u: goto P_0c091e44;
case 0x0c091e46u: goto P_0c091e46;
case 0x0c091e48u: goto P_0c091e48;
case 0x0c091e4au: goto P_0c091e4a;
case 0x0c0955b0u: goto P_0c0955b0;
case 0x0c0955b2u: goto P_0c0955b2;
case 0x0c0955b4u: goto P_0c0955b4;
case 0x0c0955b6u: goto P_0c0955b6;
case 0x0c0955b8u: goto P_0c0955b8;
case 0x0c0955bau: goto P_0c0955ba;
case 0x0c0955bcu: goto P_0c0955bc;
case 0x0c0955beu: goto P_0c0955be;
case 0x0c0955c0u: goto P_0c0955c0;
case 0x0c0955c2u: goto P_0c0955c2;
case 0x0c0955c4u: goto P_0c0955c4;
case 0x0c0955c6u: goto P_0c0955c6;
case 0x0c0955c8u: goto P_0c0955c8;
case 0x0c0955cau: goto P_0c0955ca;
case 0x0c0955ccu: goto P_0c0955cc;
case 0x0c0955ceu: goto P_0c0955ce;
case 0x0c0955d0u: goto P_0c0955d0;
case 0x0c0955d2u: goto P_0c0955d2;
case 0x0c0955d4u: goto P_0c0955d4;
case 0x0c0955d6u: goto P_0c0955d6;
case 0x0c0955d8u: goto P_0c0955d8;
case 0x0c0955dau: goto P_0c0955da;
case 0x0c0955dcu: goto P_0c0955dc;
case 0x0c0955deu: goto P_0c0955de;
case 0x0c0955e0u: goto P_0c0955e0;
case 0x0c0955e2u: goto P_0c0955e2;
case 0x0c0955e4u: goto P_0c0955e4;
case 0x0c0955e6u: goto P_0c0955e6;
case 0x0c0955e8u: goto P_0c0955e8;
case 0x0c0955eau: goto P_0c0955ea;
case 0x0c0955ecu: goto P_0c0955ec;
case 0x0c0955eeu: goto P_0c0955ee;
case 0x0c0955f0u: goto P_0c0955f0;
case 0x0c0955f2u: goto P_0c0955f2;
case 0x0c0955f4u: goto P_0c0955f4;
case 0x0c0955f6u: goto P_0c0955f6;
case 0x0c0955f8u: goto P_0c0955f8;
case 0x0c0955fau: goto P_0c0955fa;
case 0x0c0955fcu: goto P_0c0955fc;
case 0x0c0955feu: goto P_0c0955fe;
case 0x0c095600u: goto P_0c095600;
case 0x0c095602u: goto P_0c095602;
case 0x0c09571cu: goto P_0c09571c;
case 0x0c09571eu: goto P_0c09571e;
case 0x0c095720u: goto P_0c095720;
case 0x0c095722u: goto P_0c095722;
case 0x0c096864u: goto P_0c096864;
case 0x0c096866u: goto P_0c096866;
case 0x0c096868u: goto P_0c096868;
case 0x0c09686au: goto P_0c09686a;
case 0x0c09686cu: goto P_0c09686c;
case 0x0c09686eu: goto P_0c09686e;
case 0x0c096870u: goto P_0c096870;
case 0x0c096872u: goto P_0c096872;
case 0x0c096874u: goto P_0c096874;
case 0x0c096876u: goto P_0c096876;
case 0x0c096878u: goto P_0c096878;
case 0x0c09687au: goto P_0c09687a;
case 0x0c09687cu: goto P_0c09687c;
case 0x0c09687eu: goto P_0c09687e;
case 0x0c096880u: goto P_0c096880;
case 0x0c096882u: goto P_0c096882;
case 0x0c096884u: goto P_0c096884;
case 0x0c096886u: goto P_0c096886;
case 0x0c096888u: goto P_0c096888;
case 0x0c09688au: goto P_0c09688a;
case 0x0c09688cu: goto P_0c09688c;
case 0x0c09688eu: goto P_0c09688e;
case 0x0c096890u: goto P_0c096890;
case 0x0c096892u: goto P_0c096892;
case 0x0c096894u: goto P_0c096894;
case 0x0c096896u: goto P_0c096896;
case 0x0c096898u: goto P_0c096898;
case 0x0c09689au: goto P_0c09689a;
case 0x0c09689cu: goto P_0c09689c;
case 0x0c09689eu: goto P_0c09689e;
case 0x0c0968a0u: goto P_0c0968a0;
case 0x0c0968a2u: goto P_0c0968a2;
case 0x0c0968a4u: goto P_0c0968a4;
case 0x0c0968a6u: goto P_0c0968a6;
case 0x0c0968a8u: goto P_0c0968a8;
case 0x0c0968aau: goto P_0c0968aa;
case 0x0c0968acu: goto P_0c0968ac;
case 0x0c0968aeu: goto P_0c0968ae;
case 0x0c0a71acu: goto P_0c0a71ac;
case 0x0c0a71aeu: goto P_0c0a71ae;
case 0x0c0a71b0u: goto P_0c0a71b0;
case 0x0c0a71b2u: goto P_0c0a71b2;
case 0x0c0a71b4u: goto P_0c0a71b4;
case 0x0c0a71b6u: goto P_0c0a71b6;
case 0x0c0a71b8u: goto P_0c0a71b8;
case 0x0c0a71bau: goto P_0c0a71ba;
case 0x0c0a71bcu: goto P_0c0a71bc;
case 0x0c0a71beu: goto P_0c0a71be;
case 0x0c0a71c0u: goto P_0c0a71c0;
case 0x0c0a71c2u: goto P_0c0a71c2;
case 0x0c0a71c4u: goto P_0c0a71c4;
case 0x0c0a71c6u: goto P_0c0a71c6;
case 0x0c0a71c8u: goto P_0c0a71c8;
case 0x0c0a71cau: goto P_0c0a71ca;
case 0x0c0a71ccu: goto P_0c0a71cc;
case 0x0c0a71ceu: goto P_0c0a71ce;
case 0x0c0a71d0u: goto P_0c0a71d0;
case 0x0c0a71d2u: goto P_0c0a71d2;
case 0x0c0a7204u: goto P_0c0a7204;
case 0x0c0a7206u: goto P_0c0a7206;
case 0x0c0a7208u: goto P_0c0a7208;
case 0x0c0a720au: goto P_0c0a720a;
case 0x0c0a720cu: goto P_0c0a720c;
case 0x0c0a720eu: goto P_0c0a720e;
case 0x0c0a7210u: goto P_0c0a7210;
case 0x0c0a7212u: goto P_0c0a7212;
case 0x0c0a7214u: goto P_0c0a7214;
case 0x0c0a7216u: goto P_0c0a7216;
case 0x0c0a7218u: goto P_0c0a7218;
default: return vf3_matrix_family(target,s,ram);
}
P_0c07b5b0: /* original 920d, guest PC 0x0c07b5b0 */
if(!s->budget--) { s->failed_pc=0x0c07b5b0u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07b5ceu,2);
goto P_0c07b5b2;
P_0c07b5b2: /* original 634d, guest PC 0x0c07b5b2 */
if(!s->budget--) { s->failed_pc=0x0c07b5b2u; return 0; }
r[3]=r[4]&65535u;
goto P_0c07b5b4;
P_0c07b5b4: /* original 2328, guest PC 0x0c07b5b4 */
if(!s->budget--) { s->failed_pc=0x0c07b5b4u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[2])==0)!=0);
goto P_0c07b5b6;
P_0c07b5b6: /* original 8908, guest PC 0x0c07b5b6 */
if(!s->budget--) { s->failed_pc=0x0c07b5b6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07b5ca; }
goto P_0c07b5b8;
P_0c07b5b8: /* original 900a, guest PC 0x0c07b5b8 */
if(!s->budget--) { s->failed_pc=0x0c07b5b8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07b5d0u,2);
goto P_0c07b5ba;
P_0c07b5ba: /* original 2409, guest PC 0x0c07b5ba */
if(!s->budget--) { s->failed_pc=0x0c07b5bau; return 0; }
r[4]&=r[0];
goto P_0c07b5bc;
P_0c07b5bc: /* original d005, guest PC 0x0c07b5bc */
if(!s->budget--) { s->failed_pc=0x0c07b5bcu; return 0; }
r[0]=read(ram,0x0c07b5d4u,4);
goto P_0c07b5be;
P_0c07b5be: /* original 634d, guest PC 0x0c07b5be */
if(!s->budget--) { s->failed_pc=0x0c07b5beu; return 0; }
r[3]=r[4]&65535u;
goto P_0c07b5c0;
P_0c07b5c0: /* original 6133, guest PC 0x0c07b5c0 */
if(!s->budget--) { s->failed_pc=0x0c07b5c0u; return 0; }
r[1]=r[3];
goto P_0c07b5c2;
P_0c07b5c2: /* original 4108, guest PC 0x0c07b5c2 */
if(!s->budget--) { s->failed_pc=0x0c07b5c2u; return 0; }
r[1]<<=2;
goto P_0c07b5c4;
P_0c07b5c4: /* original 4300, guest PC 0x0c07b5c4 */
if(!s->budget--) { s->failed_pc=0x0c07b5c4u; return 0; }
r[17]=(r[17]&~1u)|((r[3]>>31)!=0);
r[3]<<=1;
goto P_0c07b5c6;
P_0c07b5c6: /* original 331c, guest PC 0x0c07b5c6 */
if(!s->budget--) { s->failed_pc=0x0c07b5c6u; return 0; }
r[3]+=r[1];
goto P_0c07b5c8;
P_0c07b5c8: /* original 043d, guest PC 0x0c07b5c8 */
if(!s->budget--) { s->failed_pc=0x0c07b5c8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[3]+r[0],2);
goto P_0c07b5ca;
P_0c07b5ca: /* original 000b, guest PC 0x0c07b5ca */
if(!s->budget--) { s->failed_pc=0x0c07b5cau; return 0; }
target=r[16];
r[0]=r[4];
s->pc=target; return ram->oob==0;
P_0c07b5cc: /* original 6043, guest PC 0x0c07b5cc */
if(!s->budget--) { s->failed_pc=0x0c07b5ccu; return 0; }
r[0]=r[4];
if(!vf3_matrix_family(0x0c07b5ceu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c07b5ceu; return 0; } return 1;
P_0c07b6c4: /* original 4f22, guest PC 0x0c07b6c4 */
if(!s->budget--) { s->failed_pc=0x0c07b6c4u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c07b6c6;
P_0c07b6c6: /* original 7ffc, guest PC 0x0c07b6c6 */
if(!s->budget--) { s->failed_pc=0x0c07b6c6u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c07b6c8;
P_0c07b6c8: /* original 2f72, guest PC 0x0c07b6c8 */
if(!s->budget--) { s->failed_pc=0x0c07b6c8u; return 0; }
write(ram,r[15],r[7],4);
goto P_0c07b6ca;
P_0c07b6ca: /* original 53f2, guest PC 0x0c07b6ca */
if(!s->budget--) { s->failed_pc=0x0c07b6cau; return 0; }
r[3]=read(ram,r[15]+8,4);
goto P_0c07b6cc;
P_0c07b6cc: /* original 2f36, guest PC 0x0c07b6cc */
if(!s->budget--) { s->failed_pc=0x0c07b6ccu; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07b6ce;
P_0c07b6ce: /* original 52f1, guest PC 0x0c07b6ce */
if(!s->budget--) { s->failed_pc=0x0c07b6ceu; return 0; }
r[2]=read(ram,r[15]+4,4);
goto P_0c07b6d0;
P_0c07b6d0: /* original 2f26, guest PC 0x0c07b6d0 */
if(!s->budget--) { s->failed_pc=0x0c07b6d0u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07b6d2;
P_0c07b6d2: /* original b004, guest PC 0x0c07b6d2 */
if(!s->budget--) { s->failed_pc=0x0c07b6d2u; return 0; }
target=code_base|0x0c07b6deu; r[16]=code_base|0x0c07b6d6u;
r[7]=0x00000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07b6d6u) { target=s->pc; goto dispatch; }
goto P_0c07b6d6;
P_0c07b6d4: /* original e700, guest PC 0x0c07b6d4 */
if(!s->budget--) { s->failed_pc=0x0c07b6d4u; return 0; }
r[7]=0x00000000u;
goto P_0c07b6d6;
P_0c07b6d6: /* original 7f0c, guest PC 0x0c07b6d6 */
if(!s->budget--) { s->failed_pc=0x0c07b6d6u; return 0; }
r[15]+=0x0000000cu;
goto P_0c07b6d8;
P_0c07b6d8: /* original 4f26, guest PC 0x0c07b6d8 */
if(!s->budget--) { s->failed_pc=0x0c07b6d8u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c07b6da;
P_0c07b6da: /* original 000b, guest PC 0x0c07b6da */
if(!s->budget--) { s->failed_pc=0x0c07b6dau; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c07b6dc: /* original 0009, guest PC 0x0c07b6dc */
if(!s->budget--) { s->failed_pc=0x0c07b6dcu; return 0; }
goto P_0c07b6de;
P_0c07b6de: /* original 4f22, guest PC 0x0c07b6de */
if(!s->budget--) { s->failed_pc=0x0c07b6deu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c07b6e0;
P_0c07b6e0: /* original 53f2, guest PC 0x0c07b6e0 */
if(!s->budget--) { s->failed_pc=0x0c07b6e0u; return 0; }
r[3]=read(ram,r[15]+8,4);
goto P_0c07b6e2;
P_0c07b6e2: /* original 2f36, guest PC 0x0c07b6e2 */
if(!s->budget--) { s->failed_pc=0x0c07b6e2u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07b6e4;
P_0c07b6e4: /* original d311, guest PC 0x0c07b6e4 */
if(!s->budget--) { s->failed_pc=0x0c07b6e4u; return 0; }
r[3]=read(ram,0x0c07b72cu,4);
goto P_0c07b6e6;
P_0c07b6e6: /* original 52f2, guest PC 0x0c07b6e6 */
if(!s->budget--) { s->failed_pc=0x0c07b6e6u; return 0; }
r[2]=read(ram,r[15]+8,4);
goto P_0c07b6e8;
P_0c07b6e8: /* original 430b, guest PC 0x0c07b6e8 */
if(!s->budget--) { s->failed_pc=0x0c07b6e8u; return 0; }
target=r[3];
r[16]=code_base|0x0c07b6ecu;
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07b6ecu) { target=s->pc; goto dispatch; }
goto P_0c07b6ec;
P_0c07b6ea: /* original 2f26, guest PC 0x0c07b6ea */
if(!s->budget--) { s->failed_pc=0x0c07b6eau; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07b6ec;
P_0c07b6ec: /* original 7f08, guest PC 0x0c07b6ec */
if(!s->budget--) { s->failed_pc=0x0c07b6ecu; return 0; }
r[15]+=0x00000008u;
goto P_0c07b6ee;
P_0c07b6ee: /* original 4f26, guest PC 0x0c07b6ee */
if(!s->budget--) { s->failed_pc=0x0c07b6eeu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c07b6f0;
P_0c07b6f0: /* original 000b, guest PC 0x0c07b6f0 */
if(!s->budget--) { s->failed_pc=0x0c07b6f0u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c07b6f2: /* original 0009, guest PC 0x0c07b6f2 */
if(!s->budget--) { s->failed_pc=0x0c07b6f2u; return 0; }
if(!vf3_matrix_family(0x0c07b6f4u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c07b6f4u; return 0; } return 1;
P_0c091dbe: /* original 4f22, guest PC 0x0c091dbe */
if(!s->budget--) { s->failed_pc=0x0c091dbeu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c091dc0;
P_0c091dc0: /* original 7ffc, guest PC 0x0c091dc0 */
if(!s->budget--) { s->failed_pc=0x0c091dc0u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c091dc2;
P_0c091dc2: /* original 2f42, guest PC 0x0c091dc2 */
if(!s->budget--) { s->failed_pc=0x0c091dc2u; return 0; }
write(ram,r[15],r[4],4);
goto P_0c091dc4;
P_0c091dc4: /* original d12b, guest PC 0x0c091dc4 */
if(!s->budget--) { s->failed_pc=0x0c091dc4u; return 0; }
r[1]=read(ram,0x0c091e74u,4);
goto P_0c091dc6;
P_0c091dc6: /* original d32a, guest PC 0x0c091dc6 */
if(!s->budget--) { s->failed_pc=0x0c091dc6u; return 0; }
r[3]=read(ram,0x0c091e70u,4);
goto P_0c091dc8;
P_0c091dc8: /* original 6212, guest PC 0x0c091dc8 */
if(!s->budget--) { s->failed_pc=0x0c091dc8u; return 0; }
tmp=read(ram,r[1],4);
r[2]=tmp;
goto P_0c091dca;
P_0c091dca: /* original 2238, guest PC 0x0c091dca */
if(!s->budget--) { s->failed_pc=0x0c091dcau; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c091dcc;
P_0c091dcc: /* original 8b07, guest PC 0x0c091dcc */
if(!s->budget--) { s->failed_pc=0x0c091dccu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c091dde; }
goto P_0c091dce;
P_0c091dce: /* original 9348, guest PC 0x0c091dce */
if(!s->budget--) { s->failed_pc=0x0c091dceu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c091e62u,2);
goto P_0c091dd0;
P_0c091dd0: /* original 64f2, guest PC 0x0c091dd0 */
if(!s->budget--) { s->failed_pc=0x0c091dd0u; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c091dd2;
P_0c091dd2: /* original b008, guest PC 0x0c091dd2 */
if(!s->budget--) { s->failed_pc=0x0c091dd2u; return 0; }
target=code_base|0x0c091de6u; r[16]=code_base|0x0c091dd6u;
r[4]+=r[3];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c091dd6u) { target=s->pc; goto dispatch; }
goto P_0c091dd6;
P_0c091dd4: /* original 343c, guest PC 0x0c091dd4 */
if(!s->budget--) { s->failed_pc=0x0c091dd4u; return 0; }
r[4]+=r[3];
goto P_0c091dd6;
P_0c091dd6: /* original 9345, guest PC 0x0c091dd6 */
if(!s->budget--) { s->failed_pc=0x0c091dd6u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c091e64u,2);
goto P_0c091dd8;
P_0c091dd8: /* original 64f2, guest PC 0x0c091dd8 */
if(!s->budget--) { s->failed_pc=0x0c091dd8u; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c091dda;
P_0c091dda: /* original b004, guest PC 0x0c091dda */
if(!s->budget--) { s->failed_pc=0x0c091ddau; return 0; }
target=code_base|0x0c091de6u; r[16]=code_base|0x0c091ddeu;
r[4]+=r[3];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c091ddeu) { target=s->pc; goto dispatch; }
goto P_0c091dde;
P_0c091ddc: /* original 343c, guest PC 0x0c091ddc */
if(!s->budget--) { s->failed_pc=0x0c091ddcu; return 0; }
r[4]+=r[3];
goto P_0c091dde;
P_0c091dde: /* original 7f04, guest PC 0x0c091dde */
if(!s->budget--) { s->failed_pc=0x0c091ddeu; return 0; }
r[15]+=0x00000004u;
goto P_0c091de0;
P_0c091de0: /* original 4f26, guest PC 0x0c091de0 */
if(!s->budget--) { s->failed_pc=0x0c091de0u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c091de2;
P_0c091de2: /* original 000b, guest PC 0x0c091de2 */
if(!s->budget--) { s->failed_pc=0x0c091de2u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c091de4: /* original 0009, guest PC 0x0c091de4 */
if(!s->budget--) { s->failed_pc=0x0c091de4u; return 0; }
goto P_0c091de6;
P_0c091de6: /* original 2fe6, guest PC 0x0c091de6 */
if(!s->budget--) { s->failed_pc=0x0c091de6u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c091de8;
P_0c091de8: /* original 6e43, guest PC 0x0c091de8 */
if(!s->budget--) { s->failed_pc=0x0c091de8u; return 0; }
r[14]=r[4];
goto P_0c091dea;
P_0c091dea: /* original 903c, guest PC 0x0c091dea */
if(!s->budget--) { s->failed_pc=0x0c091deau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c091e66u,2);
goto P_0c091dec;
P_0c091dec: /* original f4e6, guest PC 0x0c091dec */
if(!s->budget--) { s->failed_pc=0x0c091decu; return 0; }
vf3_matrix_load(s,ram,4,r[14]+r[0]);
goto P_0c091dee;
P_0c091dee: /* original 7004, guest PC 0x0c091dee */
if(!s->budget--) { s->failed_pc=0x0c091deeu; return 0; }
r[0]+=0x00000004u;
goto P_0c091df0;
P_0c091df0: /* original f5e6, guest PC 0x0c091df0 */
if(!s->budget--) { s->failed_pc=0x0c091df0u; return 0; }
vf3_matrix_load(s,ram,5,r[14]+r[0]);
goto P_0c091df2;
P_0c091df2: /* original f450, guest PC 0x0c091df2 */
if(!s->budget--) { s->failed_pc=0x0c091df2u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[5],r[18],'+');
goto P_0c091df4;
P_0c091df4: /* original f59d, guest PC 0x0c091df4 */
if(!s->budget--) { s->failed_pc=0x0c091df4u; return 0; }
fr[5]=0x3f800000u;
goto P_0c091df6;
P_0c091df6: /* original f455, guest PC 0x0c091df6 */
if(!s->budget--) { s->failed_pc=0x0c091df6u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[4])>as_float(fr[5]))!=0);
goto P_0c091df8;
P_0c091df8: /* original 8b00, guest PC 0x0c091df8 */
if(!s->budget--) { s->failed_pc=0x0c091df8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c091dfc; }
goto P_0c091dfa;
P_0c091dfa: /* original f45c, guest PC 0x0c091dfa */
if(!s->budget--) { s->failed_pc=0x0c091dfau; return 0; }
vf3_matrix_move(s,4,5);
goto P_0c091dfc;
P_0c091dfc: /* original 9033, guest PC 0x0c091dfc */
if(!s->budget--) { s->failed_pc=0x0c091dfcu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c091e66u,2);
goto P_0c091dfe;
P_0c091dfe: /* original 65e3, guest PC 0x0c091dfe */
if(!s->budget--) { s->failed_pc=0x0c091dfeu; return 0; }
r[5]=r[14];
goto P_0c091e00;
P_0c091e00: /* original 66e3, guest PC 0x0c091e00 */
if(!s->budget--) { s->failed_pc=0x0c091e00u; return 0; }
r[6]=r[14];
goto P_0c091e02;
P_0c091e02: /* original 64e3, guest PC 0x0c091e02 */
if(!s->budget--) { s->failed_pc=0x0c091e02u; return 0; }
r[4]=r[14];
goto P_0c091e04;
P_0c091e04: /* original 7534, guest PC 0x0c091e04 */
if(!s->budget--) { s->failed_pc=0x0c091e04u; return 0; }
r[5]+=0x00000034u;
goto P_0c091e06;
P_0c091e06: /* original fe47, guest PC 0x0c091e06 */
if(!s->budget--) { s->failed_pc=0x0c091e06u; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c091e08;
P_0c091e08: /* original 7668, guest PC 0x0c091e08 */
if(!s->budget--) { s->failed_pc=0x0c091e08u; return 0; }
r[6]+=0x00000068u;
goto P_0c091e0a;
P_0c091e0a: /* original a000, guest PC 0x0c091e0a */
if(!s->budget--) { s->failed_pc=0x0c091e0au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c091e0e;
P_0c091e0c: /* original 6ef6, guest PC 0x0c091e0c */
if(!s->budget--) { s->failed_pc=0x0c091e0cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c091e0e;
P_0c091e0e: /* original c71a, guest PC 0x0c091e0e */
if(!s->budget--) { s->failed_pc=0x0c091e0eu; return 0; }
r[0]=code_base|0x00091e78u;
goto P_0c091e10;
P_0c091e10: /* original 2fd6, guest PC 0x0c091e10 */
if(!s->budget--) { s->failed_pc=0x0c091e10u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c091e12;
P_0c091e12: /* original 2fc6, guest PC 0x0c091e12 */
if(!s->budget--) { s->failed_pc=0x0c091e12u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c091e14;
P_0c091e14: /* original 6163, guest PC 0x0c091e14 */
if(!s->budget--) { s->failed_pc=0x0c091e14u; return 0; }
r[1]=r[6];
goto P_0c091e16;
P_0c091e16: /* original f308, guest PC 0x0c091e16 */
if(!s->budget--) { s->failed_pc=0x0c091e16u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c091e18;
P_0c091e18: /* original e61a, guest PC 0x0c091e18 */
if(!s->budget--) { s->failed_pc=0x0c091e18u; return 0; }
r[6]=0x0000001au;
goto P_0c091e1a;
P_0c091e1a: /* original 4f12, guest PC 0x0c091e1a */
if(!s->budget--) { s->failed_pc=0x0c091e1au; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c091e1c;
P_0c091e1c: /* original f432, guest PC 0x0c091e1c */
if(!s->budget--) { s->failed_pc=0x0c091e1cu; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'*');
goto P_0c091e1e;
P_0c091e1e: /* original 9023, guest PC 0x0c091e1e */
if(!s->budget--) { s->failed_pc=0x0c091e1eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c091e68u,2);
goto P_0c091e20;
P_0c091e20: /* original 6d53, guest PC 0x0c091e20 */
if(!s->budget--) { s->failed_pc=0x0c091e20u; return 0; }
r[13]=r[5];
goto P_0c091e22;
P_0c091e22: /* original 6c43, guest PC 0x0c091e22 */
if(!s->budget--) { s->failed_pc=0x0c091e22u; return 0; }
r[12]=r[4];
goto P_0c091e24;
P_0c091e24: /* original f43d, guest PC 0x0c091e24 */
if(!s->budget--) { s->failed_pc=0x0c091e24u; return 0; }
r[53]=truncate_float(fr[4]);
goto P_0c091e26;
P_0c091e26: /* original 075a, guest PC 0x0c091e26 */
if(!s->budget--) { s->failed_pc=0x0c091e26u; return 0; }
r[7]=r[53];
goto P_0c091e28;
P_0c091e28: /* original 3078, guest PC 0x0c091e28 */
if(!s->budget--) { s->failed_pc=0x0c091e28u; return 0; }
r[0]-=r[7];
goto P_0c091e2a;
P_0c091e2a: /* original 64c5, guest PC 0x0c091e2a */
if(!s->budget--) { s->failed_pc=0x0c091e2au; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[12],2);
r[12]+=2;
r[4]=tmp;
goto P_0c091e2c;
P_0c091e2c: /* original e3f2, guest PC 0x0c091e2c */
if(!s->budget--) { s->failed_pc=0x0c091e2cu; return 0; }
r[3]=0xfffffff2u;
goto P_0c091e2e;
P_0c091e2e: /* original 65d5, guest PC 0x0c091e2e */
if(!s->budget--) { s->failed_pc=0x0c091e2eu; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[13],2);
r[13]+=2;
r[5]=tmp;
goto P_0c091e30;
P_0c091e30: /* original 4610, guest PC 0x0c091e30 */
if(!s->budget--) { s->failed_pc=0x0c091e30u; return 0; }
--r[6];
r[17]=(r[17]&~1u)|((r[6]==0)!=0);
goto P_0c091e32;
P_0c091e32: /* original 0047, guest PC 0x0c091e32 */
if(!s->budget--) { s->failed_pc=0x0c091e32u; return 0; }
r[19]=r[0]*r[4];
goto P_0c091e34;
P_0c091e34: /* original 041a, guest PC 0x0c091e34 */
if(!s->budget--) { s->failed_pc=0x0c091e34u; return 0; }
r[4]=r[19];
goto P_0c091e36;
P_0c091e36: /* original 0757, guest PC 0x0c091e36 */
if(!s->budget--) { s->failed_pc=0x0c091e36u; return 0; }
r[19]=r[7]*r[5];
goto P_0c091e38;
P_0c091e38: /* original 051a, guest PC 0x0c091e38 */
if(!s->budget--) { s->failed_pc=0x0c091e38u; return 0; }
r[5]=r[19];
goto P_0c091e3a;
P_0c091e3a: /* original 345c, guest PC 0x0c091e3a */
if(!s->budget--) { s->failed_pc=0x0c091e3au; return 0; }
r[4]+=r[5];
goto P_0c091e3c;
P_0c091e3c: /* original 443c, guest PC 0x0c091e3c */
if(!s->budget--) { s->failed_pc=0x0c091e3cu; return 0; }
r[4]=(r[3]&0x80000000u)?((r[3]&31u)?(uint32_t)((int32_t)r[4]>>((-r[3])&31u)):((int32_t)r[4]<0?0xffffffffu:0)):r[4]<<(r[3]&31u);
goto P_0c091e3e;
P_0c091e3e: /* original 2141, guest PC 0x0c091e3e */
if(!s->budget--) { s->failed_pc=0x0c091e3eu; return 0; }
write(ram,r[1],r[4],2);
goto P_0c091e40;
P_0c091e40: /* original 8ff3, guest PC 0x0c091e40 */
if(!s->budget--) { s->failed_pc=0x0c091e40u; return 0; }
cond=r[17]&1u;
r[1]+=0x00000002u;
if(!cond) { goto P_0c091e2a; }
goto P_0c091e44;
P_0c091e42: /* original 7102, guest PC 0x0c091e42 */
if(!s->budget--) { s->failed_pc=0x0c091e42u; return 0; }
r[1]+=0x00000002u;
goto P_0c091e44;
P_0c091e44: /* original 4f16, guest PC 0x0c091e44 */
if(!s->budget--) { s->failed_pc=0x0c091e44u; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c091e46;
P_0c091e46: /* original 6cf6, guest PC 0x0c091e46 */
if(!s->budget--) { s->failed_pc=0x0c091e46u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c091e48;
P_0c091e48: /* original 000b, guest PC 0x0c091e48 */
if(!s->budget--) { s->failed_pc=0x0c091e48u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
s->pc=target; return ram->oob==0;
P_0c091e4a: /* original 6df6, guest PC 0x0c091e4a */
if(!s->budget--) { s->failed_pc=0x0c091e4au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
if(!vf3_matrix_family(0x0c091e4cu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c091e4cu; return 0; } return 1;
P_0c0955b0: /* original 4f22, guest PC 0x0c0955b0 */
if(!s->budget--) { s->failed_pc=0x0c0955b0u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0955b2;
P_0c0955b2: /* original 7ff0, guest PC 0x0c0955b2 */
if(!s->budget--) { s->failed_pc=0x0c0955b2u; return 0; }
r[15]+=0xfffffff0u;
goto P_0c0955b4;
P_0c0955b4: /* original 1f42, guest PC 0x0c0955b4 */
if(!s->budget--) { s->failed_pc=0x0c0955b4u; return 0; }
write(ram,r[15]+8,r[4],4);
goto P_0c0955b6;
P_0c0955b6: /* original 1f51, guest PC 0x0c0955b6 */
if(!s->budget--) { s->failed_pc=0x0c0955b6u; return 0; }
write(ram,r[15]+4,r[5],4);
goto P_0c0955b8;
P_0c0955b8: /* original 2f62, guest PC 0x0c0955b8 */
if(!s->budget--) { s->failed_pc=0x0c0955b8u; return 0; }
write(ram,r[15],r[6],4);
goto P_0c0955ba;
P_0c0955ba: /* original 1f73, guest PC 0x0c0955ba */
if(!s->budget--) { s->failed_pc=0x0c0955bau; return 0; }
write(ram,r[15]+12,r[7],4);
goto P_0c0955bc;
P_0c0955bc: /* original d34e, guest PC 0x0c0955bc */
if(!s->budget--) { s->failed_pc=0x0c0955bcu; return 0; }
r[3]=read(ram,0x0c0956f8u,4);
goto P_0c0955be;
P_0c0955be: /* original 430b, guest PC 0x0c0955be */
if(!s->budget--) { s->failed_pc=0x0c0955beu; return 0; }
target=r[3];
r[16]=code_base|0x0c0955c2u;
r[4]=0x00000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0955c2u) { target=s->pc; goto dispatch; }
goto P_0c0955c2;
P_0c0955c0: /* original e400, guest PC 0x0c0955c0 */
if(!s->budget--) { s->failed_pc=0x0c0955c0u; return 0; }
r[4]=0x00000000u;
goto P_0c0955c2;
P_0c0955c2: /* original d24e, guest PC 0x0c0955c2 */
if(!s->budget--) { s->failed_pc=0x0c0955c2u; return 0; }
r[2]=read(ram,0x0c0956fcu,4);
goto P_0c0955c4;
P_0c0955c4: /* original 420b, guest PC 0x0c0955c4 */
if(!s->budget--) { s->failed_pc=0x0c0955c4u; return 0; }
target=r[2];
r[16]=code_base|0x0c0955c8u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0955c8u) { target=s->pc; goto dispatch; }
goto P_0c0955c8;
P_0c0955c6: /* original 0009, guest PC 0x0c0955c6 */
if(!s->budget--) { s->failed_pc=0x0c0955c6u; return 0; }
goto P_0c0955c8;
P_0c0955c8: /* original d34d, guest PC 0x0c0955c8 */
if(!s->budget--) { s->failed_pc=0x0c0955c8u; return 0; }
r[3]=read(ram,0x0c095700u,4);
goto P_0c0955ca;
P_0c0955ca: /* original 430b, guest PC 0x0c0955ca */
if(!s->budget--) { s->failed_pc=0x0c0955cau; return 0; }
target=r[3];
r[16]=code_base|0x0c0955ceu;
r[4]=read(ram,r[15]+24,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0955ceu) { target=s->pc; goto dispatch; }
goto P_0c0955ce;
P_0c0955cc: /* original 54f6, guest PC 0x0c0955cc */
if(!s->budget--) { s->failed_pc=0x0c0955ccu; return 0; }
r[4]=read(ram,r[15]+24,4);
goto P_0c0955ce;
P_0c0955ce: /* original d34d, guest PC 0x0c0955ce */
if(!s->budget--) { s->failed_pc=0x0c0955ceu; return 0; }
r[3]=read(ram,0x0c095704u,4);
goto P_0c0955d0;
P_0c0955d0: /* original 430b, guest PC 0x0c0955d0 */
if(!s->budget--) { s->failed_pc=0x0c0955d0u; return 0; }
target=r[3];
r[16]=code_base|0x0c0955d4u;
r[4]=read(ram,r[15]+20,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0955d4u) { target=s->pc; goto dispatch; }
goto P_0c0955d4;
P_0c0955d2: /* original 54f5, guest PC 0x0c0955d2 */
if(!s->budget--) { s->failed_pc=0x0c0955d2u; return 0; }
r[4]=read(ram,r[15]+20,4);
goto P_0c0955d4;
P_0c0955d4: /* original d34c, guest PC 0x0c0955d4 */
if(!s->budget--) { s->failed_pc=0x0c0955d4u; return 0; }
r[3]=read(ram,0x0c095708u,4);
goto P_0c0955d6;
P_0c0955d6: /* original 430b, guest PC 0x0c0955d6 */
if(!s->budget--) { s->failed_pc=0x0c0955d6u; return 0; }
target=r[3];
r[16]=code_base|0x0c0955dau;
r[4]=read(ram,r[15]+12,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0955dau) { target=s->pc; goto dispatch; }
goto P_0c0955da;
P_0c0955d8: /* original 54f3, guest PC 0x0c0955d8 */
if(!s->budget--) { s->failed_pc=0x0c0955d8u; return 0; }
r[4]=read(ram,r[15]+12,4);
goto P_0c0955da;
P_0c0955da: /* original d24c, guest PC 0x0c0955da */
if(!s->budget--) { s->failed_pc=0x0c0955dau; return 0; }
r[2]=read(ram,0x0c09570cu,4);
goto P_0c0955dc;
P_0c0955dc: /* original 420b, guest PC 0x0c0955dc */
if(!s->budget--) { s->failed_pc=0x0c0955dcu; return 0; }
target=r[2];
r[16]=code_base|0x0c0955e0u;
r[4]=0x00000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0955e0u) { target=s->pc; goto dispatch; }
goto P_0c0955e0;
P_0c0955de: /* original e400, guest PC 0x0c0955de */
if(!s->budget--) { s->failed_pc=0x0c0955deu; return 0; }
r[4]=0x00000000u;
goto P_0c0955e0;
P_0c0955e0: /* original 6403, guest PC 0x0c0955e0 */
if(!s->budget--) { s->failed_pc=0x0c0955e0u; return 0; }
r[4]=r[0];
goto P_0c0955e2;
P_0c0955e2: /* original e020, guest PC 0x0c0955e2 */
if(!s->budget--) { s->failed_pc=0x0c0955e2u; return 0; }
r[0]=0x00000020u;
goto P_0c0955e4;
P_0c0955e4: /* original f346, guest PC 0x0c0955e4 */
if(!s->budget--) { s->failed_pc=0x0c0955e4u; return 0; }
vf3_matrix_load(s,ram,3,r[4]+r[0]);
goto P_0c0955e6;
P_0c0955e6: /* original e024, guest PC 0x0c0955e6 */
if(!s->budget--) { s->failed_pc=0x0c0955e6u; return 0; }
r[0]=0x00000024u;
goto P_0c0955e8;
P_0c0955e8: /* original 53f2, guest PC 0x0c0955e8 */
if(!s->budget--) { s->failed_pc=0x0c0955e8u; return 0; }
r[3]=read(ram,r[15]+8,4);
goto P_0c0955ea;
P_0c0955ea: /* original f33a, guest PC 0x0c0955ea */
if(!s->budget--) { s->failed_pc=0x0c0955eau; return 0; }
vf3_matrix_store(s,ram,3,r[3]);
goto P_0c0955ec;
P_0c0955ec: /* original f346, guest PC 0x0c0955ec */
if(!s->budget--) { s->failed_pc=0x0c0955ecu; return 0; }
vf3_matrix_load(s,ram,3,r[4]+r[0]);
goto P_0c0955ee;
P_0c0955ee: /* original e028, guest PC 0x0c0955ee */
if(!s->budget--) { s->failed_pc=0x0c0955eeu; return 0; }
r[0]=0x00000028u;
goto P_0c0955f0;
P_0c0955f0: /* original 53f1, guest PC 0x0c0955f0 */
if(!s->budget--) { s->failed_pc=0x0c0955f0u; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c0955f2;
P_0c0955f2: /* original f33a, guest PC 0x0c0955f2 */
if(!s->budget--) { s->failed_pc=0x0c0955f2u; return 0; }
vf3_matrix_store(s,ram,3,r[3]);
goto P_0c0955f4;
P_0c0955f4: /* original f346, guest PC 0x0c0955f4 */
if(!s->budget--) { s->failed_pc=0x0c0955f4u; return 0; }
vf3_matrix_load(s,ram,3,r[4]+r[0]);
goto P_0c0955f6;
P_0c0955f6: /* original e401, guest PC 0x0c0955f6 */
if(!s->budget--) { s->failed_pc=0x0c0955f6u; return 0; }
r[4]=0x00000001u;
goto P_0c0955f8;
P_0c0955f8: /* original 63f2, guest PC 0x0c0955f8 */
if(!s->budget--) { s->failed_pc=0x0c0955f8u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c0955fa;
P_0c0955fa: /* original 7f10, guest PC 0x0c0955fa */
if(!s->budget--) { s->failed_pc=0x0c0955fau; return 0; }
r[15]+=0x00000010u;
goto P_0c0955fc;
P_0c0955fc: /* original f33a, guest PC 0x0c0955fc */
if(!s->budget--) { s->failed_pc=0x0c0955fcu; return 0; }
vf3_matrix_store(s,ram,3,r[3]);
goto P_0c0955fe;
P_0c0955fe: /* original d344, guest PC 0x0c0955fe */
if(!s->budget--) { s->failed_pc=0x0c0955feu; return 0; }
r[3]=read(ram,0x0c095710u,4);
goto P_0c095600;
P_0c095600: /* original 432b, guest PC 0x0c095600 */
if(!s->budget--) { s->failed_pc=0x0c095600u; return 0; }
target=r[3];
r[16]=read(ram,r[15],4); r[15]+=4;
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
P_0c095602: /* original 4f26, guest PC 0x0c095602 */
if(!s->budget--) { s->failed_pc=0x0c095602u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
if(!vf3_matrix_family(0x0c095604u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c095604u; return 0; } return 1;
P_0c09571c: /* original d21c, guest PC 0x0c09571c */
if(!s->budget--) { s->failed_pc=0x0c09571cu; return 0; }
r[2]=read(ram,0x0c095790u,4);
goto P_0c09571e;
P_0c09571e: /* original 6322, guest PC 0x0c09571e */
if(!s->budget--) { s->failed_pc=0x0c09571eu; return 0; }
tmp=read(ram,r[2],4);
r[3]=tmp;
goto P_0c095720;
P_0c095720: /* original 432b, guest PC 0x0c095720 */
if(!s->budget--) { s->failed_pc=0x0c095720u; return 0; }
target=r[3];
r[4]=0x00000001u;
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
P_0c095722: /* original e401, guest PC 0x0c095722 */
if(!s->budget--) { s->failed_pc=0x0c095722u; return 0; }
r[4]=0x00000001u;
if(!vf3_matrix_family(0x0c095724u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c095724u; return 0; } return 1;
P_0c096864: /* original 2fe6, guest PC 0x0c096864 */
if(!s->budget--) { s->failed_pc=0x0c096864u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c096866;
P_0c096866: /* original 4f22, guest PC 0x0c096866 */
if(!s->budget--) { s->failed_pc=0x0c096866u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c096868;
P_0c096868: /* original 7ff8, guest PC 0x0c096868 */
if(!s->budget--) { s->failed_pc=0x0c096868u; return 0; }
r[15]+=0xfffffff8u;
goto P_0c09686a;
P_0c09686a: /* original 2f42, guest PC 0x0c09686a */
if(!s->budget--) { s->failed_pc=0x0c09686au; return 0; }
write(ram,r[15],r[4],4);
goto P_0c09686c;
P_0c09686c: /* original d311, guest PC 0x0c09686c */
if(!s->budget--) { s->failed_pc=0x0c09686cu; return 0; }
r[3]=read(ram,0x0c0968b4u,4);
goto P_0c09686e;
P_0c09686e: /* original 430b, guest PC 0x0c09686e */
if(!s->budget--) { s->failed_pc=0x0c09686eu; return 0; }
target=r[3];
r[16]=code_base|0x0c096872u;
write(ram,r[15]+4,r[5],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c096872u) { target=s->pc; goto dispatch; }
goto P_0c096872;
P_0c096870: /* original 1f51, guest PC 0x0c096870 */
if(!s->budget--) { s->failed_pc=0x0c096870u; return 0; }
write(ram,r[15]+4,r[5],4);
goto P_0c096872;
P_0c096872: /* original 6e03, guest PC 0x0c096872 */
if(!s->budget--) { s->failed_pc=0x0c096872u; return 0; }
r[14]=r[0];
goto P_0c096874;
P_0c096874: /* original 2ee8, guest PC 0x0c096874 */
if(!s->budget--) { s->failed_pc=0x0c096874u; return 0; }
r[17]=(r[17]&~1u)|(((r[14]&r[14])==0)!=0);
goto P_0c096876;
P_0c096876: /* original 8905, guest PC 0x0c096876 */
if(!s->budget--) { s->failed_pc=0x0c096876u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c096884; }
goto P_0c096878;
P_0c096878: /* original d30f, guest PC 0x0c096878 */
if(!s->budget--) { s->failed_pc=0x0c096878u; return 0; }
r[3]=read(ram,0x0c0968b8u,4);
goto P_0c09687a;
P_0c09687a: /* original 430b, guest PC 0x0c09687a */
if(!s->budget--) { s->failed_pc=0x0c09687au; return 0; }
target=r[3];
r[16]=code_base|0x0c09687eu;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09687eu) { target=s->pc; goto dispatch; }
goto P_0c09687e;
P_0c09687c: /* original 64e3, guest PC 0x0c09687c */
if(!s->budget--) { s->failed_pc=0x0c09687cu; return 0; }
r[4]=r[14];
goto P_0c09687e;
P_0c09687e: /* original d20f, guest PC 0x0c09687e */
if(!s->budget--) { s->failed_pc=0x0c09687eu; return 0; }
r[2]=read(ram,0x0c0968bcu,4);
goto P_0c096880;
P_0c096880: /* original 420b, guest PC 0x0c096880 */
if(!s->budget--) { s->failed_pc=0x0c096880u; return 0; }
target=r[2];
r[16]=code_base|0x0c096884u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c096884u) { target=s->pc; goto dispatch; }
goto P_0c096884;
P_0c096882: /* original 64e3, guest PC 0x0c096882 */
if(!s->budget--) { s->failed_pc=0x0c096882u; return 0; }
r[4]=r[14];
goto P_0c096884;
P_0c096884: /* original 0002, guest PC 0x0c096884 */
if(!s->budget--) { s->failed_pc=0x0c096884u; return 0; }
r[0]=r[17];
goto P_0c096886;
P_0c096886: /* original 9313, guest PC 0x0c096886 */
if(!s->budget--) { s->failed_pc=0x0c096886u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0968b0u,2);
goto P_0c096888;
P_0c096888: /* original 2039, guest PC 0x0c096888 */
if(!s->budget--) { s->failed_pc=0x0c096888u; return 0; }
r[0]&=r[3];
goto P_0c09688a;
P_0c09688a: /* original cbe0, guest PC 0x0c09688a */
if(!s->budget--) { s->failed_pc=0x0c09688au; return 0; }
r[0]|=224u;
goto P_0c09688c;
P_0c09688c: /* original 400e, guest PC 0x0c09688c */
if(!s->budget--) { s->failed_pc=0x0c09688cu; return 0; }
r[17]=r[0];
goto P_0c09688e;
P_0c09688e: /* original d20c, guest PC 0x0c09688e */
if(!s->budget--) { s->failed_pc=0x0c09688eu; return 0; }
r[2]=read(ram,0x0c0968c0u,4);
goto P_0c096890;
P_0c096890: /* original 420b, guest PC 0x0c096890 */
if(!s->budget--) { s->failed_pc=0x0c096890u; return 0; }
target=r[2];
r[16]=code_base|0x0c096894u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c096894u) { target=s->pc; goto dispatch; }
goto P_0c096894;
P_0c096892: /* original 0009, guest PC 0x0c096892 */
if(!s->budget--) { s->failed_pc=0x0c096892u; return 0; }
goto P_0c096894;
P_0c096894: /* original d10b, guest PC 0x0c096894 */
if(!s->budget--) { s->failed_pc=0x0c096894u; return 0; }
r[1]=read(ram,0x0c0968c4u,4);
goto P_0c096896;
P_0c096896: /* original 410b, guest PC 0x0c096896 */
if(!s->budget--) { s->failed_pc=0x0c096896u; return 0; }
target=r[1];
r[16]=code_base|0x0c09689au;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09689au) { target=s->pc; goto dispatch; }
goto P_0c09689a;
P_0c096898: /* original 0009, guest PC 0x0c096898 */
if(!s->budget--) { s->failed_pc=0x0c096898u; return 0; }
goto P_0c09689a;
P_0c09689a: /* original 0002, guest PC 0x0c09689a */
if(!s->budget--) { s->failed_pc=0x0c09689au; return 0; }
r[0]=r[17];
goto P_0c09689c;
P_0c09689c: /* original 9208, guest PC 0x0c09689c */
if(!s->budget--) { s->failed_pc=0x0c09689cu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0968b0u,2);
goto P_0c09689e;
P_0c09689e: /* original 2029, guest PC 0x0c09689e */
if(!s->budget--) { s->failed_pc=0x0c09689eu; return 0; }
r[0]&=r[2];
goto P_0c0968a0;
P_0c0968a0: /* original 400e, guest PC 0x0c0968a0 */
if(!s->budget--) { s->failed_pc=0x0c0968a0u; return 0; }
r[17]=r[0];
goto P_0c0968a2;
P_0c0968a2: /* original 64f2, guest PC 0x0c0968a2 */
if(!s->budget--) { s->failed_pc=0x0c0968a2u; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c0968a4;
P_0c0968a4: /* original 55f1, guest PC 0x0c0968a4 */
if(!s->budget--) { s->failed_pc=0x0c0968a4u; return 0; }
r[5]=read(ram,r[15]+4,4);
goto P_0c0968a6;
P_0c0968a6: /* original 7f08, guest PC 0x0c0968a6 */
if(!s->budget--) { s->failed_pc=0x0c0968a6u; return 0; }
r[15]+=0x00000008u;
goto P_0c0968a8;
P_0c0968a8: /* original 4f26, guest PC 0x0c0968a8 */
if(!s->budget--) { s->failed_pc=0x0c0968a8u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0968aa;
P_0c0968aa: /* original d307, guest PC 0x0c0968aa */
if(!s->budget--) { s->failed_pc=0x0c0968aau; return 0; }
r[3]=read(ram,0x0c0968c8u,4);
goto P_0c0968ac;
P_0c0968ac: /* original 432b, guest PC 0x0c0968ac */
if(!s->budget--) { s->failed_pc=0x0c0968acu; return 0; }
target=r[3];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
code_base=target&0xff000000u;
switch(target&0x1fffffffu) {
case 0x0c09571cu: goto P_0c09571c;
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
P_0c0968ae: /* original 6ef6, guest PC 0x0c0968ae */
if(!s->budget--) { s->failed_pc=0x0c0968aeu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0968b0u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0968b0u; return 0; } return 1;
P_0c0a71ac: /* original 4f22, guest PC 0x0c0a71ac */
if(!s->budget--) { s->failed_pc=0x0c0a71acu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0a71ae;
P_0c0a71ae: /* original d31e, guest PC 0x0c0a71ae */
if(!s->budget--) { s->failed_pc=0x0c0a71aeu; return 0; }
r[3]=read(ram,0x0c0a7228u,4);
goto P_0c0a71b0;
P_0c0a71b0: /* original 430b, guest PC 0x0c0a71b0 */
if(!s->budget--) { s->failed_pc=0x0c0a71b0u; return 0; }
target=r[3];
r[16]=code_base|0x0c0a71b4u;
r[4]=0x00000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a71b4u) { target=s->pc; goto dispatch; }
goto P_0c0a71b4;
P_0c0a71b2: /* original e400, guest PC 0x0c0a71b2 */
if(!s->budget--) { s->failed_pc=0x0c0a71b2u; return 0; }
r[4]=0x00000000u;
goto P_0c0a71b4;
P_0c0a71b4: /* original d31d, guest PC 0x0c0a71b4 */
if(!s->budget--) { s->failed_pc=0x0c0a71b4u; return 0; }
r[3]=read(ram,0x0c0a722cu,4);
goto P_0c0a71b6;
P_0c0a71b6: /* original d21e, guest PC 0x0c0a71b6 */
if(!s->budget--) { s->failed_pc=0x0c0a71b6u; return 0; }
r[2]=read(ram,0x0c0a7230u,4);
goto P_0c0a71b8;
P_0c0a71b8: /* original 6132, guest PC 0x0c0a71b8 */
if(!s->budget--) { s->failed_pc=0x0c0a71b8u; return 0; }
tmp=read(ram,r[3],4);
r[1]=tmp;
goto P_0c0a71ba;
P_0c0a71ba: /* original 212b, guest PC 0x0c0a71ba */
if(!s->budget--) { s->failed_pc=0x0c0a71bau; return 0; }
r[1]|=r[2];
goto P_0c0a71bc;
P_0c0a71bc: /* original 2312, guest PC 0x0c0a71bc */
if(!s->budget--) { s->failed_pc=0x0c0a71bcu; return 0; }
write(ram,r[3],r[1],4);
goto P_0c0a71be;
P_0c0a71be: /* original d31e, guest PC 0x0c0a71be */
if(!s->budget--) { s->failed_pc=0x0c0a71beu; return 0; }
r[3]=read(ram,0x0c0a7238u,4);
goto P_0c0a71c0;
P_0c0a71c0: /* original d41c, guest PC 0x0c0a71c0 */
if(!s->budget--) { s->failed_pc=0x0c0a71c0u; return 0; }
r[4]=read(ram,0x0c0a7234u,4);
goto P_0c0a71c2;
P_0c0a71c2: /* original 430b, guest PC 0x0c0a71c2 */
if(!s->budget--) { s->failed_pc=0x0c0a71c2u; return 0; }
target=r[3];
r[16]=code_base|0x0c0a71c6u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a71c6u) { target=s->pc; goto dispatch; }
goto P_0c0a71c6;
P_0c0a71c4: /* original 0009, guest PC 0x0c0a71c4 */
if(!s->budget--) { s->failed_pc=0x0c0a71c4u; return 0; }
goto P_0c0a71c6;
P_0c0a71c6: /* original d21d, guest PC 0x0c0a71c6 */
if(!s->budget--) { s->failed_pc=0x0c0a71c6u; return 0; }
r[2]=read(ram,0x0c0a723cu,4);
goto P_0c0a71c8;
P_0c0a71c8: /* original 420b, guest PC 0x0c0a71c8 */
if(!s->budget--) { s->failed_pc=0x0c0a71c8u; return 0; }
target=r[2];
r[16]=code_base|0x0c0a71ccu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a71ccu) { target=s->pc; goto dispatch; }
goto P_0c0a71cc;
P_0c0a71ca: /* original 0009, guest PC 0x0c0a71ca */
if(!s->budget--) { s->failed_pc=0x0c0a71cau; return 0; }
goto P_0c0a71cc;
P_0c0a71cc: /* original d31c, guest PC 0x0c0a71cc */
if(!s->budget--) { s->failed_pc=0x0c0a71ccu; return 0; }
r[3]=read(ram,0x0c0a7240u,4);
goto P_0c0a71ce;
P_0c0a71ce: /* original e401, guest PC 0x0c0a71ce */
if(!s->budget--) { s->failed_pc=0x0c0a71ceu; return 0; }
r[4]=0x00000001u;
goto P_0c0a71d0;
P_0c0a71d0: /* original 432b, guest PC 0x0c0a71d0 */
if(!s->budget--) { s->failed_pc=0x0c0a71d0u; return 0; }
target=r[3];
r[16]=read(ram,r[15],4); r[15]+=4;
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
P_0c0a71d2: /* original 4f26, guest PC 0x0c0a71d2 */
if(!s->budget--) { s->failed_pc=0x0c0a71d2u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
if(!vf3_matrix_family(0x0c0a71d4u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0a71d4u; return 0; } return 1;
P_0c0a7204: /* original d509, guest PC 0x0c0a7204 */
if(!s->budget--) { s->failed_pc=0x0c0a7204u; return 0; }
r[5]=read(ram,0x0c0a722cu,4);
goto P_0c0a7206;
P_0c0a7206: /* original d30f, guest PC 0x0c0a7206 */
if(!s->budget--) { s->failed_pc=0x0c0a7206u; return 0; }
r[3]=read(ram,0x0c0a7244u,4);
goto P_0c0a7208;
P_0c0a7208: /* original 6252, guest PC 0x0c0a7208 */
if(!s->budget--) { s->failed_pc=0x0c0a7208u; return 0; }
tmp=read(ram,r[5],4);
r[2]=tmp;
goto P_0c0a720a;
P_0c0a720a: /* original 223b, guest PC 0x0c0a720a */
if(!s->budget--) { s->failed_pc=0x0c0a720au; return 0; }
r[2]|=r[3];
goto P_0c0a720c;
P_0c0a720c: /* original 2522, guest PC 0x0c0a720c */
if(!s->budget--) { s->failed_pc=0x0c0a720cu; return 0; }
write(ram,r[5],r[2],4);
goto P_0c0a720e;
P_0c0a720e: /* original 6152, guest PC 0x0c0a720e */
if(!s->budget--) { s->failed_pc=0x0c0a720eu; return 0; }
tmp=read(ram,r[5],4);
r[1]=tmp;
goto P_0c0a7210;
P_0c0a7210: /* original d20d, guest PC 0x0c0a7210 */
if(!s->budget--) { s->failed_pc=0x0c0a7210u; return 0; }
r[2]=read(ram,0x0c0a7248u,4);
goto P_0c0a7212;
P_0c0a7212: /* original 2129, guest PC 0x0c0a7212 */
if(!s->budget--) { s->failed_pc=0x0c0a7212u; return 0; }
r[1]&=r[2];
goto P_0c0a7214;
P_0c0a7214: /* original 2512, guest PC 0x0c0a7214 */
if(!s->budget--) { s->failed_pc=0x0c0a7214u; return 0; }
write(ram,r[5],r[1],4);
goto P_0c0a7216;
P_0c0a7216: /* original 000b, guest PC 0x0c0a7216 */
if(!s->budget--) { s->failed_pc=0x0c0a7216u; return 0; }
target=r[16];
write(ram,r[5]+24,r[4],4);
s->pc=target; return ram->oob==0;
P_0c0a7218: /* original 1546, guest PC 0x0c0a7218 */
if(!s->budget--) { s->failed_pc=0x0c0a7218u; return 0; }
write(ram,r[5]+24,r[4],4);
if(!vf3_matrix_family(0x0c0a721au,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0a721au; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
