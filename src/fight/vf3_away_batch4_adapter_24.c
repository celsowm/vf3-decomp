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
int vf3_away_batch4_adapter_24(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c053790u: goto P_0c053790;
case 0x0c053792u: goto P_0c053792;
case 0x0c053794u: goto P_0c053794;
case 0x0c053796u: goto P_0c053796;
case 0x0c053798u: goto P_0c053798;
case 0x0c05379au: goto P_0c05379a;
case 0x0c05379cu: goto P_0c05379c;
case 0x0c05379eu: goto P_0c05379e;
case 0x0c0537a0u: goto P_0c0537a0;
case 0x0c0537a2u: goto P_0c0537a2;
case 0x0c0537a4u: goto P_0c0537a4;
case 0x0c0537a6u: goto P_0c0537a6;
case 0x0c0537a8u: goto P_0c0537a8;
case 0x0c0537aau: goto P_0c0537aa;
case 0x0c0537acu: goto P_0c0537ac;
case 0x0c0537aeu: goto P_0c0537ae;
case 0x0c0537b0u: goto P_0c0537b0;
case 0x0c0537b2u: goto P_0c0537b2;
case 0x0c0537b4u: goto P_0c0537b4;
case 0x0c0537b6u: goto P_0c0537b6;
case 0x0c0537b8u: goto P_0c0537b8;
case 0x0c0537bau: goto P_0c0537ba;
case 0x0c0537bcu: goto P_0c0537bc;
case 0x0c0537beu: goto P_0c0537be;
case 0x0c0537c0u: goto P_0c0537c0;
case 0x0c0537c2u: goto P_0c0537c2;
case 0x0c0537c4u: goto P_0c0537c4;
case 0x0c0537c6u: goto P_0c0537c6;
case 0x0c0537c8u: goto P_0c0537c8;
case 0x0c0537cau: goto P_0c0537ca;
case 0x0c0537ccu: goto P_0c0537cc;
case 0x0c0537ceu: goto P_0c0537ce;
case 0x0c0537d0u: goto P_0c0537d0;
case 0x0c0537d2u: goto P_0c0537d2;
case 0x0c0537d4u: goto P_0c0537d4;
case 0x0c0537d6u: goto P_0c0537d6;
case 0x0c0537d8u: goto P_0c0537d8;
case 0x0c0537dau: goto P_0c0537da;
case 0x0c0537dcu: goto P_0c0537dc;
case 0x0c0537deu: goto P_0c0537de;
case 0x0c0537e0u: goto P_0c0537e0;
case 0x0c0537e2u: goto P_0c0537e2;
case 0x0c0537e4u: goto P_0c0537e4;
case 0x0c0537e6u: goto P_0c0537e6;
case 0x0c0537e8u: goto P_0c0537e8;
case 0x0c0537eau: goto P_0c0537ea;
case 0x0c0537ecu: goto P_0c0537ec;
case 0x0c0537eeu: goto P_0c0537ee;
case 0x0c0537f0u: goto P_0c0537f0;
case 0x0c0537f2u: goto P_0c0537f2;
case 0x0c0537f4u: goto P_0c0537f4;
case 0x0c0537f6u: goto P_0c0537f6;
case 0x0c0537f8u: goto P_0c0537f8;
case 0x0c0537fau: goto P_0c0537fa;
case 0x0c0537fcu: goto P_0c0537fc;
case 0x0c0537feu: goto P_0c0537fe;
case 0x0c053800u: goto P_0c053800;
case 0x0c053802u: goto P_0c053802;
case 0x0c053804u: goto P_0c053804;
case 0x0c053806u: goto P_0c053806;
case 0x0c053808u: goto P_0c053808;
case 0x0c05380au: goto P_0c05380a;
case 0x0c05380cu: goto P_0c05380c;
case 0x0c05380eu: goto P_0c05380e;
case 0x0c053810u: goto P_0c053810;
case 0x0c053812u: goto P_0c053812;
case 0x0c053814u: goto P_0c053814;
case 0x0c053816u: goto P_0c053816;
case 0x0c053818u: goto P_0c053818;
case 0x0c05381au: goto P_0c05381a;
case 0x0c05381cu: goto P_0c05381c;
case 0x0c05381eu: goto P_0c05381e;
case 0x0c053820u: goto P_0c053820;
case 0x0c053822u: goto P_0c053822;
case 0x0c053824u: goto P_0c053824;
case 0x0c053826u: goto P_0c053826;
case 0x0c053828u: goto P_0c053828;
case 0x0c05382au: goto P_0c05382a;
case 0x0c05382cu: goto P_0c05382c;
case 0x0c05382eu: goto P_0c05382e;
case 0x0c053830u: goto P_0c053830;
case 0x0c053832u: goto P_0c053832;
case 0x0c053834u: goto P_0c053834;
case 0x0c053836u: goto P_0c053836;
case 0x0c053838u: goto P_0c053838;
case 0x0c05383au: goto P_0c05383a;
case 0x0c05383cu: goto P_0c05383c;
case 0x0c05383eu: goto P_0c05383e;
case 0x0c053840u: goto P_0c053840;
case 0x0c053842u: goto P_0c053842;
case 0x0c053844u: goto P_0c053844;
case 0x0c053846u: goto P_0c053846;
case 0x0c053848u: goto P_0c053848;
case 0x0c05384au: goto P_0c05384a;
case 0x0c05384cu: goto P_0c05384c;
case 0x0c05384eu: goto P_0c05384e;
case 0x0c053850u: goto P_0c053850;
case 0x0c053852u: goto P_0c053852;
case 0x0c053854u: goto P_0c053854;
case 0x0c053856u: goto P_0c053856;
case 0x0c053858u: goto P_0c053858;
case 0x0c05385au: goto P_0c05385a;
case 0x0c0538a8u: goto P_0c0538a8;
case 0x0c0538aau: goto P_0c0538aa;
case 0x0c0538acu: goto P_0c0538ac;
case 0x0c0538aeu: goto P_0c0538ae;
case 0x0c0538b0u: goto P_0c0538b0;
case 0x0c0538b2u: goto P_0c0538b2;
case 0x0c0538b4u: goto P_0c0538b4;
case 0x0c0538b6u: goto P_0c0538b6;
case 0x0c0538b8u: goto P_0c0538b8;
case 0x0c0538bau: goto P_0c0538ba;
case 0x0c0538bcu: goto P_0c0538bc;
case 0x0c0538beu: goto P_0c0538be;
case 0x0c0538c0u: goto P_0c0538c0;
case 0x0c0538c2u: goto P_0c0538c2;
case 0x0c0538c4u: goto P_0c0538c4;
case 0x0c0538c6u: goto P_0c0538c6;
case 0x0c0538c8u: goto P_0c0538c8;
case 0x0c0538cau: goto P_0c0538ca;
case 0x0c0538ccu: goto P_0c0538cc;
case 0x0c0538ceu: goto P_0c0538ce;
case 0x0c0538d0u: goto P_0c0538d0;
case 0x0c0538d2u: goto P_0c0538d2;
case 0x0c0538d4u: goto P_0c0538d4;
case 0x0c0538d6u: goto P_0c0538d6;
case 0x0c0538d8u: goto P_0c0538d8;
case 0x0c0538dau: goto P_0c0538da;
case 0x0c0538dcu: goto P_0c0538dc;
case 0x0c0538deu: goto P_0c0538de;
case 0x0c0538e0u: goto P_0c0538e0;
case 0x0c0538e2u: goto P_0c0538e2;
case 0x0c0538e4u: goto P_0c0538e4;
case 0x0c0538e6u: goto P_0c0538e6;
case 0x0c0538e8u: goto P_0c0538e8;
case 0x0c0538eau: goto P_0c0538ea;
case 0x0c0538ecu: goto P_0c0538ec;
case 0x0c0538eeu: goto P_0c0538ee;
case 0x0c0538f0u: goto P_0c0538f0;
case 0x0c0538f2u: goto P_0c0538f2;
case 0x0c0538f4u: goto P_0c0538f4;
case 0x0c0538f6u: goto P_0c0538f6;
case 0x0c0538f8u: goto P_0c0538f8;
case 0x0c0538fau: goto P_0c0538fa;
case 0x0c0538fcu: goto P_0c0538fc;
case 0x0c0538feu: goto P_0c0538fe;
case 0x0c053900u: goto P_0c053900;
case 0x0c053902u: goto P_0c053902;
case 0x0c053904u: goto P_0c053904;
case 0x0c053906u: goto P_0c053906;
case 0x0c053908u: goto P_0c053908;
case 0x0c05390au: goto P_0c05390a;
case 0x0c05390cu: goto P_0c05390c;
case 0x0c05390eu: goto P_0c05390e;
case 0x0c053910u: goto P_0c053910;
case 0x0c053912u: goto P_0c053912;
case 0x0c053914u: goto P_0c053914;
case 0x0c053916u: goto P_0c053916;
case 0x0c053918u: goto P_0c053918;
case 0x0c05391au: goto P_0c05391a;
case 0x0c05391cu: goto P_0c05391c;
case 0x0c05391eu: goto P_0c05391e;
case 0x0c053920u: goto P_0c053920;
case 0x0c053922u: goto P_0c053922;
case 0x0c053924u: goto P_0c053924;
case 0x0c053926u: goto P_0c053926;
case 0x0c053928u: goto P_0c053928;
case 0x0c05392au: goto P_0c05392a;
case 0x0c05392cu: goto P_0c05392c;
case 0x0c05392eu: goto P_0c05392e;
case 0x0c053930u: goto P_0c053930;
case 0x0c053932u: goto P_0c053932;
case 0x0c053934u: goto P_0c053934;
case 0x0c053936u: goto P_0c053936;
case 0x0c053938u: goto P_0c053938;
case 0x0c05393au: goto P_0c05393a;
case 0x0c05393cu: goto P_0c05393c;
case 0x0c05393eu: goto P_0c05393e;
case 0x0c053940u: goto P_0c053940;
case 0x0c053942u: goto P_0c053942;
case 0x0c053944u: goto P_0c053944;
case 0x0c053946u: goto P_0c053946;
case 0x0c053948u: goto P_0c053948;
case 0x0c05394au: goto P_0c05394a;
case 0x0c05394cu: goto P_0c05394c;
case 0x0c05394eu: goto P_0c05394e;
case 0x0c053950u: goto P_0c053950;
case 0x0c053952u: goto P_0c053952;
case 0x0c053954u: goto P_0c053954;
case 0x0c053956u: goto P_0c053956;
case 0x0c053958u: goto P_0c053958;
case 0x0c05395au: goto P_0c05395a;
case 0x0c05395cu: goto P_0c05395c;
case 0x0c05395eu: goto P_0c05395e;
case 0x0c053960u: goto P_0c053960;
case 0x0c053962u: goto P_0c053962;
case 0x0c053964u: goto P_0c053964;
case 0x0c053966u: goto P_0c053966;
case 0x0c053ca4u: goto P_0c053ca4;
case 0x0c053ca6u: goto P_0c053ca6;
case 0x0c053ca8u: goto P_0c053ca8;
case 0x0c053caau: goto P_0c053caa;
case 0x0c053cacu: goto P_0c053cac;
case 0x0c053caeu: goto P_0c053cae;
case 0x0c053cb0u: goto P_0c053cb0;
case 0x0c053cb2u: goto P_0c053cb2;
case 0x0c053cb4u: goto P_0c053cb4;
case 0x0c053cb6u: goto P_0c053cb6;
case 0x0c053cb8u: goto P_0c053cb8;
case 0x0c053cbau: goto P_0c053cba;
case 0x0c053cbcu: goto P_0c053cbc;
case 0x0c053cbeu: goto P_0c053cbe;
case 0x0c053cc0u: goto P_0c053cc0;
case 0x0c053cc2u: goto P_0c053cc2;
case 0x0c053cc4u: goto P_0c053cc4;
case 0x0c053cc6u: goto P_0c053cc6;
case 0x0c053cc8u: goto P_0c053cc8;
case 0x0c053ccau: goto P_0c053cca;
case 0x0c053cccu: goto P_0c053ccc;
case 0x0c053cceu: goto P_0c053cce;
case 0x0c053cd0u: goto P_0c053cd0;
case 0x0c053cd2u: goto P_0c053cd2;
case 0x0c053cd4u: goto P_0c053cd4;
case 0x0c053cd6u: goto P_0c053cd6;
case 0x0c053cd8u: goto P_0c053cd8;
default: return vf3_matrix_family(target,s,ram);
}
P_0c053790: /* original 2fe6, guest PC 0x0c053790 */
if(!s->budget--) { s->failed_pc=0x0c053790u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c053792;
P_0c053792: /* original 2fd6, guest PC 0x0c053792 */
if(!s->budget--) { s->failed_pc=0x0c053792u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c053794;
P_0c053794: /* original 6d43, guest PC 0x0c053794 */
if(!s->budget--) { s->failed_pc=0x0c053794u; return 0; }
r[13]=r[4];
goto P_0c053796;
P_0c053796: /* original 2fc6, guest PC 0x0c053796 */
if(!s->budget--) { s->failed_pc=0x0c053796u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c053798;
P_0c053798: /* original 2fb6, guest PC 0x0c053798 */
if(!s->budget--) { s->failed_pc=0x0c053798u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05379a;
P_0c05379a: /* original 2fa6, guest PC 0x0c05379a */
if(!s->budget--) { s->failed_pc=0x0c05379au; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05379c;
P_0c05379c: /* original 2f96, guest PC 0x0c05379c */
if(!s->budget--) { s->failed_pc=0x0c05379cu; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05379e;
P_0c05379e: /* original 2f86, guest PC 0x0c05379e */
if(!s->budget--) { s->failed_pc=0x0c05379eu; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0537a0;
P_0c0537a0: /* original 4f22, guest PC 0x0c0537a0 */
if(!s->budget--) { s->failed_pc=0x0c0537a0u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0537a2;
P_0c0537a2: /* original 4f12, guest PC 0x0c0537a2 */
if(!s->budget--) { s->failed_pc=0x0c0537a2u; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c0537a4;
P_0c0537a4: /* original 7fec, guest PC 0x0c0537a4 */
if(!s->budget--) { s->failed_pc=0x0c0537a4u; return 0; }
r[15]+=0xffffffecu;
goto P_0c0537a6;
P_0c0537a6: /* original 1f51, guest PC 0x0c0537a6 */
if(!s->budget--) { s->failed_pc=0x0c0537a6u; return 0; }
write(ram,r[15]+4,r[5],4);
goto P_0c0537a8;
P_0c0537a8: /* original 2f62, guest PC 0x0c0537a8 */
if(!s->budget--) { s->failed_pc=0x0c0537a8u; return 0; }
write(ram,r[15],r[6],4);
goto P_0c0537aa;
P_0c0537aa: /* original 9358, guest PC 0x0c0537aa */
if(!s->budget--) { s->failed_pc=0x0c0537aau; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c05385eu,2);
goto P_0c0537ac;
P_0c0537ac: /* original d232, guest PC 0x0c0537ac */
if(!s->budget--) { s->failed_pc=0x0c0537acu; return 0; }
r[2]=read(ram,0x0c053878u,4);
goto P_0c0537ae;
P_0c0537ae: /* original 0d37, guest PC 0x0c0537ae */
if(!s->budget--) { s->failed_pc=0x0c0537aeu; return 0; }
r[19]=r[13]*r[3];
goto P_0c0537b0;
P_0c0537b0: /* original 031a, guest PC 0x0c0537b0 */
if(!s->budget--) { s->failed_pc=0x0c0537b0u; return 0; }
r[3]=r[19];
goto P_0c0537b2;
P_0c0537b2: /* original 332c, guest PC 0x0c0537b2 */
if(!s->budget--) { s->failed_pc=0x0c0537b2u; return 0; }
r[3]+=r[2];
goto P_0c0537b4;
P_0c0537b4: /* original 1f32, guest PC 0x0c0537b4 */
if(!s->budget--) { s->failed_pc=0x0c0537b4u; return 0; }
write(ram,r[15]+8,r[3],4);
goto P_0c0537b6;
P_0c0537b6: /* original 61f2, guest PC 0x0c0537b6 */
if(!s->budget--) { s->failed_pc=0x0c0537b6u; return 0; }
tmp=read(ram,r[15],4);
r[1]=tmp;
goto P_0c0537b8;
P_0c0537b8: /* original de30, guest PC 0x0c0537b8 */
if(!s->budget--) { s->failed_pc=0x0c0537b8u; return 0; }
r[14]=read(ram,0x0c05387cu,4);
goto P_0c0537ba;
P_0c0537ba: /* original 2f16, guest PC 0x0c0537ba */
if(!s->budget--) { s->failed_pc=0x0c0537bau; return 0; }
tmp=r[1]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0537bc;
P_0c0537bc: /* original 51f2, guest PC 0x0c0537bc */
if(!s->budget--) { s->failed_pc=0x0c0537bcu; return 0; }
r[1]=read(ram,r[15]+8,4);
goto P_0c0537be;
P_0c0537be: /* original 2f16, guest PC 0x0c0537be */
if(!s->budget--) { s->failed_pc=0x0c0537beu; return 0; }
tmp=r[1]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0537c0;
P_0c0537c0: /* original 2fd6, guest PC 0x0c0537c0 */
if(!s->budget--) { s->failed_pc=0x0c0537c0u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0537c2;
P_0c0537c2: /* original d12f, guest PC 0x0c0537c2 */
if(!s->budget--) { s->failed_pc=0x0c0537c2u; return 0; }
r[1]=read(ram,0x0c053880u,4);
goto P_0c0537c4;
P_0c0537c4: /* original 4e0b, guest PC 0x0c0537c4 */
if(!s->budget--) { s->failed_pc=0x0c0537c4u; return 0; }
target=r[14];
r[16]=code_base|0x0c0537c8u;
tmp=r[1]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0537c8u) { target=s->pc; goto dispatch; }
goto P_0c0537c8;
P_0c0537c6: /* original 2f16, guest PC 0x0c0537c6 */
if(!s->budget--) { s->failed_pc=0x0c0537c6u; return 0; }
tmp=r[1]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0537c8;
P_0c0537c8: /* original db2f, guest PC 0x0c0537c8 */
if(!s->budget--) { s->failed_pc=0x0c0537c8u; return 0; }
r[11]=read(ram,0x0c053888u,4);
goto P_0c0537ca;
P_0c0537ca: /* original 7f10, guest PC 0x0c0537ca */
if(!s->budget--) { s->failed_pc=0x0c0537cau; return 0; }
r[15]+=0x00000010u;
goto P_0c0537cc;
P_0c0537cc: /* original da2d, guest PC 0x0c0537cc */
if(!s->budget--) { s->failed_pc=0x0c0537ccu; return 0; }
r[10]=read(ram,0x0c053884u,4);
goto P_0c0537ce;
P_0c0537ce: /* original b289, guest PC 0x0c0537ce */
if(!s->budget--) { s->failed_pc=0x0c0537ceu; return 0; }
target=code_base|0x0c053ce4u; r[16]=code_base|0x0c0537d2u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0537d2u) { target=s->pc; goto dispatch; }
goto P_0c0537d2;
P_0c0537d0: /* original 64d3, guest PC 0x0c0537d0 */
if(!s->budget--) { s->failed_pc=0x0c0537d0u; return 0; }
r[4]=r[13];
goto P_0c0537d2;
P_0c0537d2: /* original 2008, guest PC 0x0c0537d2 */
if(!s->budget--) { s->failed_pc=0x0c0537d2u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c0537d4;
P_0c0537d4: /* original 8b05, guest PC 0x0c0537d4 */
if(!s->budget--) { s->failed_pc=0x0c0537d4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0537e2; }
goto P_0c0537d6;
P_0c0537d6: /* original 4e0b, guest PC 0x0c0537d6 */
if(!s->budget--) { s->failed_pc=0x0c0537d6u; return 0; }
target=r[14];
r[16]=code_base|0x0c0537dau;
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0537dau) { target=s->pc; goto dispatch; }
goto P_0c0537da;
P_0c0537d8: /* original 2fa6, guest PC 0x0c0537d8 */
if(!s->budget--) { s->failed_pc=0x0c0537d8u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0537da;
P_0c0537da: /* original 4b0b, guest PC 0x0c0537da */
if(!s->budget--) { s->failed_pc=0x0c0537dau; return 0; }
target=r[11];
r[16]=code_base|0x0c0537deu;
r[15]+=0x00000004u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0537deu) { target=s->pc; goto dispatch; }
goto P_0c0537de;
P_0c0537dc: /* original 7f04, guest PC 0x0c0537dc */
if(!s->budget--) { s->failed_pc=0x0c0537dcu; return 0; }
r[15]+=0x00000004u;
goto P_0c0537de;
P_0c0537de: /* original a098, guest PC 0x0c0537de */
if(!s->budget--) { s->failed_pc=0x0c0537deu; return 0; }
goto P_0c053912;
P_0c0537e0: /* original 0009, guest PC 0x0c0537e0 */
if(!s->budget--) { s->failed_pc=0x0c0537e0u; return 0; }
goto P_0c0537e2;
P_0c0537e2: /* original d02a, guest PC 0x0c0537e2 */
if(!s->budget--) { s->failed_pc=0x0c0537e2u; return 0; }
r[0]=read(ram,0x0c05388cu,4);
goto P_0c0537e4;
P_0c0537e4: /* original 4d08, guest PC 0x0c0537e4 */
if(!s->budget--) { s->failed_pc=0x0c0537e4u; return 0; }
r[13]<<=2;
goto P_0c0537e6;
P_0c0537e6: /* original d22a, guest PC 0x0c0537e6 */
if(!s->budget--) { s->failed_pc=0x0c0537e6u; return 0; }
r[2]=read(ram,0x0c053890u,4);
goto P_0c0537e8;
P_0c0537e8: /* original 0dde, guest PC 0x0c0537e8 */
if(!s->budget--) { s->failed_pc=0x0c0537e8u; return 0; }
r[13]=read(ram,r[13]+r[0],4);
goto P_0c0537ea;
P_0c0537ea: /* original 420b, guest PC 0x0c0537ea */
if(!s->budget--) { s->failed_pc=0x0c0537eau; return 0; }
target=r[2];
r[16]=code_base|0x0c0537eeu;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0537eeu) { target=s->pc; goto dispatch; }
goto P_0c0537ee;
P_0c0537ec: /* original 64d3, guest PC 0x0c0537ec */
if(!s->budget--) { s->failed_pc=0x0c0537ecu; return 0; }
r[4]=r[13];
goto P_0c0537ee;
P_0c0537ee: /* original 63f2, guest PC 0x0c0537ee */
if(!s->budget--) { s->failed_pc=0x0c0537eeu; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c0537f0;
P_0c0537f0: /* original e400, guest PC 0x0c0537f0 */
if(!s->budget--) { s->failed_pc=0x0c0537f0u; return 0; }
r[4]=0x00000000u;
goto P_0c0537f2;
P_0c0537f2: /* original 1f33, guest PC 0x0c0537f2 */
if(!s->budget--) { s->failed_pc=0x0c0537f2u; return 0; }
write(ram,r[15]+12,r[3],4);
goto P_0c0537f4;
P_0c0537f4: /* original 2f42, guest PC 0x0c0537f4 */
if(!s->budget--) { s->failed_pc=0x0c0537f4u; return 0; }
write(ram,r[15],r[4],4);
goto P_0c0537f6;
P_0c0537f6: /* original a0a3, guest PC 0x0c0537f6 */
if(!s->budget--) { s->failed_pc=0x0c0537f6u; return 0; }
r[9]=r[4];
goto P_0c053940;
P_0c0537f8: /* original 6943, guest PC 0x0c0537f8 */
if(!s->budget--) { s->failed_pc=0x0c0537f8u; return 0; }
r[9]=r[4];
goto P_0c0537fa;
P_0c0537fa: /* original 53f1, guest PC 0x0c0537fa */
if(!s->budget--) { s->failed_pc=0x0c0537fau; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c0537fc;
P_0c0537fc: /* original dc25, guest PC 0x0c0537fc */
if(!s->budget--) { s->failed_pc=0x0c0537fcu; return 0; }
r[12]=read(ram,0x0c053894u,4);
goto P_0c0537fe;
P_0c0537fe: /* original 2f36, guest PC 0x0c0537fe */
if(!s->budget--) { s->failed_pc=0x0c0537feu; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c053800;
P_0c053800: /* original 2f96, guest PC 0x0c053800 */
if(!s->budget--) { s->failed_pc=0x0c053800u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c053802;
P_0c053802: /* original 2fd6, guest PC 0x0c053802 */
if(!s->budget--) { s->failed_pc=0x0c053802u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c053804;
P_0c053804: /* original 4e0b, guest PC 0x0c053804 */
if(!s->budget--) { s->failed_pc=0x0c053804u; return 0; }
target=r[14];
r[16]=code_base|0x0c053808u;
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c053808u) { target=s->pc; goto dispatch; }
goto P_0c053808;
P_0c053806: /* original 2fc6, guest PC 0x0c053806 */
if(!s->budget--) { s->failed_pc=0x0c053806u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c053808;
P_0c053808: /* original d323, guest PC 0x0c053808 */
if(!s->budget--) { s->failed_pc=0x0c053808u; return 0; }
r[3]=read(ram,0x0c053898u,4);
goto P_0c05380a;
P_0c05380a: /* original 7f10, guest PC 0x0c05380a */
if(!s->budget--) { s->failed_pc=0x0c05380au; return 0; }
r[15]+=0x00000010u;
goto P_0c05380c;
P_0c05380c: /* original 430b, guest PC 0x0c05380c */
if(!s->budget--) { s->failed_pc=0x0c05380cu; return 0; }
target=r[3];
r[16]=code_base|0x0c053810u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c053810u) { target=s->pc; goto dispatch; }
goto P_0c053810;
P_0c05380e: /* original 64d3, guest PC 0x0c05380e */
if(!s->budget--) { s->failed_pc=0x0c05380eu; return 0; }
r[4]=r[13];
goto P_0c053810;
P_0c053810: /* original 2008, guest PC 0x0c053810 */
if(!s->budget--) { s->failed_pc=0x0c053810u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c053812;
P_0c053812: /* original 8b52, guest PC 0x0c053812 */
if(!s->budget--) { s->failed_pc=0x0c053812u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0538ba; }
goto P_0c053814;
P_0c053814: /* original 53f1, guest PC 0x0c053814 */
if(!s->budget--) { s->failed_pc=0x0c053814u; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c053816;
P_0c053816: /* original e600, guest PC 0x0c053816 */
if(!s->budget--) { s->failed_pc=0x0c053816u; return 0; }
r[6]=0x00000000u;
goto P_0c053818;
P_0c053818: /* original dc20, guest PC 0x0c053818 */
if(!s->budget--) { s->failed_pc=0x0c053818u; return 0; }
r[12]=read(ram,0x0c05389cu,4);
goto P_0c05381a;
P_0c05381a: /* original e502, guest PC 0x0c05381a */
if(!s->budget--) { s->failed_pc=0x0c05381au; return 0; }
r[5]=0x00000002u;
goto P_0c05381c;
P_0c05381c: /* original 2f36, guest PC 0x0c05381c */
if(!s->budget--) { s->failed_pc=0x0c05381cu; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05381e;
P_0c05381e: /* original 6793, guest PC 0x0c05381e */
if(!s->budget--) { s->failed_pc=0x0c05381eu; return 0; }
r[7]=r[9];
goto P_0c053820;
P_0c053820: /* original 4c0b, guest PC 0x0c053820 */
if(!s->budget--) { s->failed_pc=0x0c053820u; return 0; }
target=r[12];
r[16]=code_base|0x0c053824u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c053824u) { target=s->pc; goto dispatch; }
goto P_0c053824;
P_0c053822: /* original 64d3, guest PC 0x0c053822 */
if(!s->budget--) { s->failed_pc=0x0c053822u; return 0; }
r[4]=r[13];
goto P_0c053824;
P_0c053824: /* original 6c03, guest PC 0x0c053824 */
if(!s->budget--) { s->failed_pc=0x0c053824u; return 0; }
r[12]=r[0];
goto P_0c053826;
P_0c053826: /* original 4c11, guest PC 0x0c053826 */
if(!s->budget--) { s->failed_pc=0x0c053826u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[12]>=0)!=0);
goto P_0c053828;
P_0c053828: /* original 8d06, guest PC 0x0c053828 */
if(!s->budget--) { s->failed_pc=0x0c053828u; return 0; }
cond=r[17]&1u;
r[15]+=0x00000004u;
if(cond) { goto P_0c053838; }
goto P_0c05382c;
P_0c05382a: /* original 7f04, guest PC 0x0c05382a */
if(!s->budget--) { s->failed_pc=0x0c05382au; return 0; }
r[15]+=0x00000004u;
goto P_0c05382c;
P_0c05382c: /* original 4e0b, guest PC 0x0c05382c */
if(!s->budget--) { s->failed_pc=0x0c05382cu; return 0; }
target=r[14];
r[16]=code_base|0x0c053830u;
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c053830u) { target=s->pc; goto dispatch; }
goto P_0c053830;
P_0c05382e: /* original 2fa6, guest PC 0x0c05382e */
if(!s->budget--) { s->failed_pc=0x0c05382eu; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c053830;
P_0c053830: /* original 4b0b, guest PC 0x0c053830 */
if(!s->budget--) { s->failed_pc=0x0c053830u; return 0; }
target=r[11];
r[16]=code_base|0x0c053834u;
r[15]+=0x00000004u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c053834u) { target=s->pc; goto dispatch; }
goto P_0c053834;
P_0c053832: /* original 7f04, guest PC 0x0c053832 */
if(!s->budget--) { s->failed_pc=0x0c053832u; return 0; }
r[15]+=0x00000004u;
goto P_0c053834;
P_0c053834: /* original afe1, guest PC 0x0c053834 */
if(!s->budget--) { s->failed_pc=0x0c053834u; return 0; }
goto P_0c0537fa;
P_0c053836: /* original 0009, guest PC 0x0c053836 */
if(!s->budget--) { s->failed_pc=0x0c053836u; return 0; }
goto P_0c053838;
P_0c053838: /* original d819, guest PC 0x0c053838 */
if(!s->budget--) { s->failed_pc=0x0c053838u; return 0; }
r[8]=read(ram,0x0c0538a0u,4);
goto P_0c05383a;
P_0c05383a: /* original 2fc6, guest PC 0x0c05383a */
if(!s->budget--) { s->failed_pc=0x0c05383au; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05383c;
P_0c05383c: /* original 2fd6, guest PC 0x0c05383c */
if(!s->budget--) { s->failed_pc=0x0c05383cu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05383e;
P_0c05383e: /* original 4e0b, guest PC 0x0c05383e */
if(!s->budget--) { s->failed_pc=0x0c05383eu; return 0; }
target=r[14];
r[16]=code_base|0x0c053842u;
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c053842u) { target=s->pc; goto dispatch; }
goto P_0c053842;
P_0c053840: /* original 2f86, guest PC 0x0c053840 */
if(!s->budget--) { s->failed_pc=0x0c053840u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c053842;
P_0c053842: /* original d818, guest PC 0x0c053842 */
if(!s->budget--) { s->failed_pc=0x0c053842u; return 0; }
r[8]=read(ram,0x0c0538a4u,4);
goto P_0c053844;
P_0c053844: /* original 65c3, guest PC 0x0c053844 */
if(!s->budget--) { s->failed_pc=0x0c053844u; return 0; }
r[5]=r[12];
goto P_0c053846;
P_0c053846: /* original 7f0c, guest PC 0x0c053846 */
if(!s->budget--) { s->failed_pc=0x0c053846u; return 0; }
r[15]+=0x0000000cu;
goto P_0c053848;
P_0c053848: /* original 480b, guest PC 0x0c053848 */
if(!s->budget--) { s->failed_pc=0x0c053848u; return 0; }
target=r[8];
r[16]=code_base|0x0c05384cu;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c05384cu) { target=s->pc; goto dispatch; }
goto P_0c05384c;
P_0c05384a: /* original 64d3, guest PC 0x0c05384a */
if(!s->budget--) { s->failed_pc=0x0c05384au; return 0; }
r[4]=r[13];
goto P_0c05384c;
P_0c05384c: /* original 2008, guest PC 0x0c05384c */
if(!s->budget--) { s->failed_pc=0x0c05384cu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c05384e;
P_0c05384e: /* original 8b2b, guest PC 0x0c05384e */
if(!s->budget--) { s->failed_pc=0x0c05384eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0538a8; }
goto P_0c053850;
P_0c053850: /* original 4e0b, guest PC 0x0c053850 */
if(!s->budget--) { s->failed_pc=0x0c053850u; return 0; }
target=r[14];
r[16]=code_base|0x0c053854u;
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c053854u) { target=s->pc; goto dispatch; }
goto P_0c053854;
P_0c053852: /* original 2fa6, guest PC 0x0c053852 */
if(!s->budget--) { s->failed_pc=0x0c053852u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c053854;
P_0c053854: /* original 4b0b, guest PC 0x0c053854 */
if(!s->budget--) { s->failed_pc=0x0c053854u; return 0; }
target=r[11];
r[16]=code_base|0x0c053858u;
r[15]+=0x00000004u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c053858u) { target=s->pc; goto dispatch; }
goto P_0c053858;
P_0c053856: /* original 7f04, guest PC 0x0c053856 */
if(!s->budget--) { s->failed_pc=0x0c053856u; return 0; }
r[15]+=0x00000004u;
goto P_0c053858;
P_0c053858: /* original afee, guest PC 0x0c053858 */
if(!s->budget--) { s->failed_pc=0x0c053858u; return 0; }
goto P_0c053838;
P_0c05385a: /* original 0009, guest PC 0x0c05385a */
if(!s->budget--) { s->failed_pc=0x0c05385au; return 0; }
if(!vf3_matrix_family(0x0c05385cu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c05385cu; return 0; } return 1;
P_0c0538a8: /* original d346, guest PC 0x0c0538a8 */
if(!s->budget--) { s->failed_pc=0x0c0538a8u; return 0; }
r[3]=read(ram,0x0c0539c4u,4);
goto P_0c0538aa;
P_0c0538aa: /* original 430b, guest PC 0x0c0538aa */
if(!s->budget--) { s->failed_pc=0x0c0538aau; return 0; }
target=r[3];
r[16]=code_base|0x0c0538aeu;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0538aeu) { target=s->pc; goto dispatch; }
goto P_0c0538ae;
P_0c0538ac: /* original 64d3, guest PC 0x0c0538ac */
if(!s->budget--) { s->failed_pc=0x0c0538acu; return 0; }
r[4]=r[13];
goto P_0c0538ae;
P_0c0538ae: /* original d246, guest PC 0x0c0538ae */
if(!s->budget--) { s->failed_pc=0x0c0538aeu; return 0; }
r[2]=read(ram,0x0c0539c8u,4);
goto P_0c0538b0;
P_0c0538b0: /* original 6803, guest PC 0x0c0538b0 */
if(!s->budget--) { s->failed_pc=0x0c0538b0u; return 0; }
r[8]=r[0];
goto P_0c0538b2;
P_0c0538b2: /* original 420b, guest PC 0x0c0538b2 */
if(!s->budget--) { s->failed_pc=0x0c0538b2u; return 0; }
target=r[2];
r[16]=code_base|0x0c0538b6u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0538b6u) { target=s->pc; goto dispatch; }
goto P_0c0538b6;
P_0c0538b4: /* original 64d3, guest PC 0x0c0538b4 */
if(!s->budget--) { s->failed_pc=0x0c0538b4u; return 0; }
r[4]=r[13];
goto P_0c0538b6;
P_0c0538b6: /* original 2008, guest PC 0x0c0538b6 */
if(!s->budget--) { s->failed_pc=0x0c0538b6u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c0538b8;
P_0c0538b8: /* original 8904, guest PC 0x0c0538b8 */
if(!s->budget--) { s->failed_pc=0x0c0538b8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0538c4; }
goto P_0c0538ba;
P_0c0538ba: /* original dd44, guest PC 0x0c0538ba */
if(!s->budget--) { s->failed_pc=0x0c0538bau; return 0; }
r[13]=read(ram,0x0c0539ccu,4);
goto P_0c0538bc;
P_0c0538bc: /* original 4e0b, guest PC 0x0c0538bc */
if(!s->budget--) { s->failed_pc=0x0c0538bcu; return 0; }
target=r[14];
r[16]=code_base|0x0c0538c0u;
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0538c0u) { target=s->pc; goto dispatch; }
goto P_0c0538c0;
P_0c0538be: /* original 2fd6, guest PC 0x0c0538be */
if(!s->budget--) { s->failed_pc=0x0c0538beu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0538c0;
P_0c0538c0: /* original a027, guest PC 0x0c0538c0 */
if(!s->budget--) { s->failed_pc=0x0c0538c0u; return 0; }
r[15]+=0x00000004u;
goto P_0c053912;
P_0c0538c2: /* original 7f04, guest PC 0x0c0538c2 */
if(!s->budget--) { s->failed_pc=0x0c0538c2u; return 0; }
r[15]+=0x00000004u;
goto P_0c0538c4;
P_0c0538c4: /* original 5382, guest PC 0x0c0538c4 */
if(!s->budget--) { s->failed_pc=0x0c0538c4u; return 0; }
r[3]=read(ram,r[8]+8,4);
goto P_0c0538c6;
P_0c0538c6: /* original 1f34, guest PC 0x0c0538c6 */
if(!s->budget--) { s->failed_pc=0x0c0538c6u; return 0; }
write(ram,r[15]+16,r[3],4);
goto P_0c0538c8;
P_0c0538c8: /* original 8484, guest PC 0x0c0538c8 */
if(!s->budget--) { s->failed_pc=0x0c0538c8u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[8]+4,1);
goto P_0c0538ca;
P_0c0538ca: /* original 600c, guest PC 0x0c0538ca */
if(!s->budget--) { s->failed_pc=0x0c0538cau; return 0; }
r[0]=r[0]&255u;
goto P_0c0538cc;
P_0c0538cc: /* original 8808, guest PC 0x0c0538cc */
if(!s->budget--) { s->failed_pc=0x0c0538ccu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000008u)!=0);
goto P_0c0538ce;
P_0c0538ce: /* original 8907, guest PC 0x0c0538ce */
if(!s->budget--) { s->failed_pc=0x0c0538ceu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0538e0; }
goto P_0c0538d0;
P_0c0538d0: /* original 9173, guest PC 0x0c0538d0 */
if(!s->budget--) { s->failed_pc=0x0c0538d0u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0539bau,2);
goto P_0c0538d2;
P_0c0538d2: /* original 3010, guest PC 0x0c0538d2 */
if(!s->budget--) { s->failed_pc=0x0c0538d2u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==r[1])!=0);
goto P_0c0538d4;
P_0c0538d4: /* original 890e, guest PC 0x0c0538d4 */
if(!s->budget--) { s->failed_pc=0x0c0538d4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0538f4; }
goto P_0c0538d6;
P_0c0538d6: /* original 9171, guest PC 0x0c0538d6 */
if(!s->budget--) { s->failed_pc=0x0c0538d6u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0539bcu,2);
goto P_0c0538d8;
P_0c0538d8: /* original 3010, guest PC 0x0c0538d8 */
if(!s->budget--) { s->failed_pc=0x0c0538d8u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==r[1])!=0);
goto P_0c0538da;
P_0c0538da: /* original 8906, guest PC 0x0c0538da */
if(!s->budget--) { s->failed_pc=0x0c0538dau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0538ea; }
goto P_0c0538dc;
P_0c0538dc: /* original a012, guest PC 0x0c0538dc */
if(!s->budget--) { s->failed_pc=0x0c0538dcu; return 0; }
goto P_0c053904;
P_0c0538de: /* original 0009, guest PC 0x0c0538de */
if(!s->budget--) { s->failed_pc=0x0c0538deu; return 0; }
goto P_0c0538e0;
P_0c0538e0: /* original d83b, guest PC 0x0c0538e0 */
if(!s->budget--) { s->failed_pc=0x0c0538e0u; return 0; }
r[8]=read(ram,0x0c0539d0u,4);
goto P_0c0538e2;
P_0c0538e2: /* original 4e0b, guest PC 0x0c0538e2 */
if(!s->budget--) { s->failed_pc=0x0c0538e2u; return 0; }
target=r[14];
r[16]=code_base|0x0c0538e6u;
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0538e6u) { target=s->pc; goto dispatch; }
goto P_0c0538e6;
P_0c0538e4: /* original 2f86, guest PC 0x0c0538e4 */
if(!s->budget--) { s->failed_pc=0x0c0538e4u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0538e6;
P_0c0538e6: /* original a017, guest PC 0x0c0538e6 */
if(!s->budget--) { s->failed_pc=0x0c0538e6u; return 0; }
r[15]+=0x00000004u;
goto P_0c053918;
P_0c0538e8: /* original 7f04, guest PC 0x0c0538e8 */
if(!s->budget--) { s->failed_pc=0x0c0538e8u; return 0; }
r[15]+=0x00000004u;
goto P_0c0538ea;
P_0c0538ea: /* original d83a, guest PC 0x0c0538ea */
if(!s->budget--) { s->failed_pc=0x0c0538eau; return 0; }
r[8]=read(ram,0x0c0539d4u,4);
goto P_0c0538ec;
P_0c0538ec: /* original 4e0b, guest PC 0x0c0538ec */
if(!s->budget--) { s->failed_pc=0x0c0538ecu; return 0; }
target=r[14];
r[16]=code_base|0x0c0538f0u;
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0538f0u) { target=s->pc; goto dispatch; }
goto P_0c0538f0;
P_0c0538ee: /* original 2f86, guest PC 0x0c0538ee */
if(!s->budget--) { s->failed_pc=0x0c0538eeu; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0538f0;
P_0c0538f0: /* original af83, guest PC 0x0c0538f0 */
if(!s->budget--) { s->failed_pc=0x0c0538f0u; return 0; }
r[15]+=0x00000004u;
goto P_0c0537fa;
P_0c0538f2: /* original 7f04, guest PC 0x0c0538f2 */
if(!s->budget--) { s->failed_pc=0x0c0538f2u; return 0; }
r[15]+=0x00000004u;
goto P_0c0538f4;
P_0c0538f4: /* original 5283, guest PC 0x0c0538f4 */
if(!s->budget--) { s->failed_pc=0x0c0538f4u; return 0; }
r[2]=read(ram,r[8]+12,4);
goto P_0c0538f6;
P_0c0538f6: /* original dd38, guest PC 0x0c0538f6 */
if(!s->budget--) { s->failed_pc=0x0c0538f6u; return 0; }
r[13]=read(ram,0x0c0539d8u,4);
goto P_0c0538f8;
P_0c0538f8: /* original 2f26, guest PC 0x0c0538f8 */
if(!s->budget--) { s->failed_pc=0x0c0538f8u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0538fa;
P_0c0538fa: /* original 4e0b, guest PC 0x0c0538fa */
if(!s->budget--) { s->failed_pc=0x0c0538fau; return 0; }
target=r[14];
r[16]=code_base|0x0c0538feu;
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0538feu) { target=s->pc; goto dispatch; }
goto P_0c0538fe;
P_0c0538fc: /* original 2fd6, guest PC 0x0c0538fc */
if(!s->budget--) { s->failed_pc=0x0c0538fcu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0538fe;
P_0c0538fe: /* original d037, guest PC 0x0c0538fe */
if(!s->budget--) { s->failed_pc=0x0c0538feu; return 0; }
r[0]=read(ram,0x0c0539dcu,4);
goto P_0c053900;
P_0c053900: /* original a027, guest PC 0x0c053900 */
if(!s->budget--) { s->failed_pc=0x0c053900u; return 0; }
r[15]+=0x00000008u;
goto P_0c053952;
P_0c053902: /* original 7f08, guest PC 0x0c053902 */
if(!s->budget--) { s->failed_pc=0x0c053902u; return 0; }
r[15]+=0x00000008u;
goto P_0c053904;
P_0c053904: /* original 8484, guest PC 0x0c053904 */
if(!s->budget--) { s->failed_pc=0x0c053904u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[8]+4,1);
goto P_0c053906;
P_0c053906: /* original dd36, guest PC 0x0c053906 */
if(!s->budget--) { s->failed_pc=0x0c053906u; return 0; }
r[13]=read(ram,0x0c0539e0u,4);
goto P_0c053908;
P_0c053908: /* original 600c, guest PC 0x0c053908 */
if(!s->budget--) { s->failed_pc=0x0c053908u; return 0; }
r[0]=r[0]&255u;
goto P_0c05390a;
P_0c05390a: /* original 2f06, guest PC 0x0c05390a */
if(!s->budget--) { s->failed_pc=0x0c05390au; return 0; }
tmp=r[0]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05390c;
P_0c05390c: /* original 4e0b, guest PC 0x0c05390c */
if(!s->budget--) { s->failed_pc=0x0c05390cu; return 0; }
target=r[14];
r[16]=code_base|0x0c053910u;
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c053910u) { target=s->pc; goto dispatch; }
goto P_0c053910;
P_0c05390e: /* original 2fd6, guest PC 0x0c05390e */
if(!s->budget--) { s->failed_pc=0x0c05390eu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c053910;
P_0c053910: /* original 7f08, guest PC 0x0c053910 */
if(!s->budget--) { s->failed_pc=0x0c053910u; return 0; }
r[15]+=0x00000008u;
goto P_0c053912;
P_0c053912: /* original 9054, guest PC 0x0c053912 */
if(!s->budget--) { s->failed_pc=0x0c053912u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0539beu,2);
goto P_0c053914;
P_0c053914: /* original a01d, guest PC 0x0c053914 */
if(!s->budget--) { s->failed_pc=0x0c053914u; return 0; }
goto P_0c053952;
P_0c053916: /* original 0009, guest PC 0x0c053916 */
if(!s->budget--) { s->failed_pc=0x0c053916u; return 0; }
goto P_0c053918;
P_0c053918: /* original 56f2, guest PC 0x0c053918 */
if(!s->budget--) { s->failed_pc=0x0c053918u; return 0; }
r[6]=read(ram,r[15]+8,4);
goto P_0c05391a;
P_0c05391a: /* original e044, guest PC 0x0c05391a */
if(!s->budget--) { s->failed_pc=0x0c05391au; return 0; }
r[0]=0x00000044u;
goto P_0c05391c;
P_0c05391c: /* original 55f4, guest PC 0x0c05391c */
if(!s->budget--) { s->failed_pc=0x0c05391cu; return 0; }
r[5]=read(ram,r[15]+16,4);
goto P_0c05391e;
P_0c05391e: /* original 5667, guest PC 0x0c05391e */
if(!s->budget--) { s->failed_pc=0x0c05391eu; return 0; }
r[6]=read(ram,r[6]+28,4);
goto P_0c053920;
P_0c053920: /* original d830, guest PC 0x0c053920 */
if(!s->budget--) { s->failed_pc=0x0c053920u; return 0; }
r[8]=read(ram,0x0c0539e4u,4);
goto P_0c053922;
P_0c053922: /* original 750c, guest PC 0x0c053922 */
if(!s->budget--) { s->failed_pc=0x0c053922u; return 0; }
r[5]+=0x0000000cu;
goto P_0c053924;
P_0c053924: /* original 066e, guest PC 0x0c053924 */
if(!s->budget--) { s->failed_pc=0x0c053924u; return 0; }
r[6]=read(ram,r[6]+r[0],4);
goto P_0c053926;
P_0c053926: /* original 480b, guest PC 0x0c053926 */
if(!s->budget--) { s->failed_pc=0x0c053926u; return 0; }
target=r[8];
r[16]=code_base|0x0c05392au;
r[4]=read(ram,r[15]+12,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c05392au) { target=s->pc; goto dispatch; }
goto P_0c05392a;
P_0c053928: /* original 54f3, guest PC 0x0c053928 */
if(!s->budget--) { s->failed_pc=0x0c053928u; return 0; }
r[4]=read(ram,r[15]+12,4);
goto P_0c05392a;
P_0c05392a: /* original 53f2, guest PC 0x0c05392a */
if(!s->budget--) { s->failed_pc=0x0c05392au; return 0; }
r[3]=read(ram,r[15]+8,4);
goto P_0c05392c;
P_0c05392c: /* original e044, guest PC 0x0c05392c */
if(!s->budget--) { s->failed_pc=0x0c05392cu; return 0; }
r[0]=0x00000044u;
goto P_0c05392e;
P_0c05392e: /* original 51f3, guest PC 0x0c05392e */
if(!s->budget--) { s->failed_pc=0x0c05392eu; return 0; }
r[1]=read(ram,r[15]+12,4);
goto P_0c053930;
P_0c053930: /* original 7901, guest PC 0x0c053930 */
if(!s->budget--) { s->failed_pc=0x0c053930u; return 0; }
r[9]+=0x00000001u;
goto P_0c053932;
P_0c053932: /* original 5237, guest PC 0x0c053932 */
if(!s->budget--) { s->failed_pc=0x0c053932u; return 0; }
r[2]=read(ram,r[3]+28,4);
goto P_0c053934;
P_0c053934: /* original 032e, guest PC 0x0c053934 */
if(!s->budget--) { s->failed_pc=0x0c053934u; return 0; }
r[3]=read(ram,r[2]+r[0],4);
goto P_0c053936;
P_0c053936: /* original 313c, guest PC 0x0c053936 */
if(!s->budget--) { s->failed_pc=0x0c053936u; return 0; }
r[1]+=r[3];
goto P_0c053938;
P_0c053938: /* original 1f13, guest PC 0x0c053938 */
if(!s->budget--) { s->failed_pc=0x0c053938u; return 0; }
write(ram,r[15]+12,r[1],4);
goto P_0c05393a;
P_0c05393a: /* original 62f2, guest PC 0x0c05393a */
if(!s->budget--) { s->failed_pc=0x0c05393au; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c05393c;
P_0c05393c: /* original 7201, guest PC 0x0c05393c */
if(!s->budget--) { s->failed_pc=0x0c05393cu; return 0; }
r[2]+=0x00000001u;
goto P_0c05393e;
P_0c05393e: /* original 2f22, guest PC 0x0c05393e */
if(!s->budget--) { s->failed_pc=0x0c05393eu; return 0; }
write(ram,r[15],r[2],4);
goto P_0c053940;
P_0c053940: /* original 53f2, guest PC 0x0c053940 */
if(!s->budget--) { s->failed_pc=0x0c053940u; return 0; }
r[3]=read(ram,r[15]+8,4);
goto P_0c053942;
P_0c053942: /* original 60f2, guest PC 0x0c053942 */
if(!s->budget--) { s->failed_pc=0x0c053942u; return 0; }
tmp=read(ram,r[15],4);
r[0]=tmp;
goto P_0c053944;
P_0c053944: /* original 5237, guest PC 0x0c053944 */
if(!s->budget--) { s->failed_pc=0x0c053944u; return 0; }
r[2]=read(ram,r[3]+28,4);
goto P_0c053946;
P_0c053946: /* original 512f, guest PC 0x0c053946 */
if(!s->budget--) { s->failed_pc=0x0c053946u; return 0; }
r[1]=read(ram,r[2]+60,4);
goto P_0c053948;
P_0c053948: /* original 3013, guest PC 0x0c053948 */
if(!s->budget--) { s->failed_pc=0x0c053948u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[0]>=(int32_t)r[1])!=0);
goto P_0c05394a;
P_0c05394a: /* original 8901, guest PC 0x0c05394a */
if(!s->budget--) { s->failed_pc=0x0c05394au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c053950; }
goto P_0c05394c;
P_0c05394c: /* original af55, guest PC 0x0c05394c */
if(!s->budget--) { s->failed_pc=0x0c05394cu; return 0; }
goto P_0c0537fa;
P_0c05394e: /* original 0009, guest PC 0x0c05394e */
if(!s->budget--) { s->failed_pc=0x0c05394eu; return 0; }
goto P_0c053950;
P_0c053950: /* original e000, guest PC 0x0c053950 */
if(!s->budget--) { s->failed_pc=0x0c053950u; return 0; }
r[0]=0x00000000u;
goto P_0c053952;
P_0c053952: /* original 7f14, guest PC 0x0c053952 */
if(!s->budget--) { s->failed_pc=0x0c053952u; return 0; }
r[15]+=0x00000014u;
goto P_0c053954;
P_0c053954: /* original 4f16, guest PC 0x0c053954 */
if(!s->budget--) { s->failed_pc=0x0c053954u; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c053956;
P_0c053956: /* original 4f26, guest PC 0x0c053956 */
if(!s->budget--) { s->failed_pc=0x0c053956u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c053958;
P_0c053958: /* original 68f6, guest PC 0x0c053958 */
if(!s->budget--) { s->failed_pc=0x0c053958u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c05395a;
P_0c05395a: /* original 69f6, guest PC 0x0c05395a */
if(!s->budget--) { s->failed_pc=0x0c05395au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c05395c;
P_0c05395c: /* original 6af6, guest PC 0x0c05395c */
if(!s->budget--) { s->failed_pc=0x0c05395cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c05395e;
P_0c05395e: /* original 6bf6, guest PC 0x0c05395e */
if(!s->budget--) { s->failed_pc=0x0c05395eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c053960;
P_0c053960: /* original 6cf6, guest PC 0x0c053960 */
if(!s->budget--) { s->failed_pc=0x0c053960u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c053962;
P_0c053962: /* original 6df6, guest PC 0x0c053962 */
if(!s->budget--) { s->failed_pc=0x0c053962u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c053964;
P_0c053964: /* original 000b, guest PC 0x0c053964 */
if(!s->budget--) { s->failed_pc=0x0c053964u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c053966: /* original 6ef6, guest PC 0x0c053966 */
if(!s->budget--) { s->failed_pc=0x0c053966u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c053968u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c053968u; return 0; } return 1;
P_0c053ca4: /* original 2fe6, guest PC 0x0c053ca4 */
if(!s->budget--) { s->failed_pc=0x0c053ca4u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c053ca6;
P_0c053ca6: /* original 6e43, guest PC 0x0c053ca6 */
if(!s->budget--) { s->failed_pc=0x0c053ca6u; return 0; }
r[14]=r[4];
goto P_0c053ca8;
P_0c053ca8: /* original d026, guest PC 0x0c053ca8 */
if(!s->budget--) { s->failed_pc=0x0c053ca8u; return 0; }
r[0]=read(ram,0x0c053d44u,4);
goto P_0c053caa;
P_0c053caa: /* original 4e08, guest PC 0x0c053caa */
if(!s->budget--) { s->failed_pc=0x0c053caau; return 0; }
r[14]<<=2;
goto P_0c053cac;
P_0c053cac: /* original 4f22, guest PC 0x0c053cac */
if(!s->budget--) { s->failed_pc=0x0c053cacu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c053cae;
P_0c053cae: /* original 0eee, guest PC 0x0c053cae */
if(!s->budget--) { s->failed_pc=0x0c053caeu; return 0; }
r[14]=read(ram,r[14]+r[0],4);
goto P_0c053cb0;
P_0c053cb0: /* original d325, guest PC 0x0c053cb0 */
if(!s->budget--) { s->failed_pc=0x0c053cb0u; return 0; }
r[3]=read(ram,0x0c053d48u,4);
goto P_0c053cb2;
P_0c053cb2: /* original 7ffc, guest PC 0x0c053cb2 */
if(!s->budget--) { s->failed_pc=0x0c053cb2u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c053cb4;
P_0c053cb4: /* original 430b, guest PC 0x0c053cb4 */
if(!s->budget--) { s->failed_pc=0x0c053cb4u; return 0; }
target=r[3];
r[16]=code_base|0x0c053cb8u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c053cb8u) { target=s->pc; goto dispatch; }
goto P_0c053cb8;
P_0c053cb6: /* original 64e3, guest PC 0x0c053cb6 */
if(!s->budget--) { s->failed_pc=0x0c053cb6u; return 0; }
r[4]=r[14];
goto P_0c053cb8;
P_0c053cb8: /* original 2f02, guest PC 0x0c053cb8 */
if(!s->budget--) { s->failed_pc=0x0c053cb8u; return 0; }
write(ram,r[15],r[0],4);
goto P_0c053cba;
P_0c053cba: /* original d324, guest PC 0x0c053cba */
if(!s->budget--) { s->failed_pc=0x0c053cbau; return 0; }
r[3]=read(ram,0x0c053d4cu,4);
goto P_0c053cbc;
P_0c053cbc: /* original 430b, guest PC 0x0c053cbc */
if(!s->budget--) { s->failed_pc=0x0c053cbcu; return 0; }
target=r[3];
r[16]=code_base|0x0c053cc0u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c053cc0u) { target=s->pc; goto dispatch; }
goto P_0c053cc0;
P_0c053cbe: /* original 64e3, guest PC 0x0c053cbe */
if(!s->budget--) { s->failed_pc=0x0c053cbeu; return 0; }
r[4]=r[14];
goto P_0c053cc0;
P_0c053cc0: /* original 62f2, guest PC 0x0c053cc0 */
if(!s->budget--) { s->failed_pc=0x0c053cc0u; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c053cc2;
P_0c053cc2: /* original 6403, guest PC 0x0c053cc2 */
if(!s->budget--) { s->failed_pc=0x0c053cc2u; return 0; }
r[4]=r[0];
goto P_0c053cc4;
P_0c053cc4: /* original 6320, guest PC 0x0c053cc4 */
if(!s->budget--) { s->failed_pc=0x0c053cc4u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[2],1);
r[3]=tmp;
goto P_0c053cc6;
P_0c053cc6: /* original 2338, guest PC 0x0c053cc6 */
if(!s->budget--) { s->failed_pc=0x0c053cc6u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c053cc8;
P_0c053cc8: /* original 8902, guest PC 0x0c053cc8 */
if(!s->budget--) { s->failed_pc=0x0c053cc8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c053cd0; }
goto P_0c053cca;
P_0c053cca: /* original 6042, guest PC 0x0c053cca */
if(!s->budget--) { s->failed_pc=0x0c053ccau; return 0; }
tmp=read(ram,r[4],4);
r[0]=tmp;
goto P_0c053ccc;
P_0c053ccc: /* original c802, guest PC 0x0c053ccc */
if(!s->budget--) { s->failed_pc=0x0c053cccu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&2u)==0)!=0);
goto P_0c053cce;
P_0c053cce: /* original 8b04, guest PC 0x0c053cce */
if(!s->budget--) { s->failed_pc=0x0c053cceu; return 0; }
cond=r[17]&1u;
if(!cond) { return vf3_matrix_family(0x0c053cdau,s,ram); }
goto P_0c053cd0;
P_0c053cd0: /* original 7f04, guest PC 0x0c053cd0 */
if(!s->budget--) { s->failed_pc=0x0c053cd0u; return 0; }
r[15]+=0x00000004u;
goto P_0c053cd2;
P_0c053cd2: /* original 4f26, guest PC 0x0c053cd2 */
if(!s->budget--) { s->failed_pc=0x0c053cd2u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c053cd4;
P_0c053cd4: /* original e000, guest PC 0x0c053cd4 */
if(!s->budget--) { s->failed_pc=0x0c053cd4u; return 0; }
r[0]=0x00000000u;
goto P_0c053cd6;
P_0c053cd6: /* original 000b, guest PC 0x0c053cd6 */
if(!s->budget--) { s->failed_pc=0x0c053cd6u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c053cd8: /* original 6ef6, guest PC 0x0c053cd8 */
if(!s->budget--) { s->failed_pc=0x0c053cd8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c053cdau,s,ram);
unsupported: s->failed_pc=target; return 0;
}
