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
int vf3_away_batch13_adapter_14(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c085830u: goto P_0c085830;
case 0x0c085832u: goto P_0c085832;
case 0x0c085834u: goto P_0c085834;
case 0x0c085836u: goto P_0c085836;
case 0x0c085838u: goto P_0c085838;
case 0x0c08583au: goto P_0c08583a;
case 0x0c08583cu: goto P_0c08583c;
case 0x0c08583eu: goto P_0c08583e;
case 0x0c085840u: goto P_0c085840;
case 0x0c085842u: goto P_0c085842;
case 0x0c085844u: goto P_0c085844;
case 0x0c085846u: goto P_0c085846;
case 0x0c085848u: goto P_0c085848;
case 0x0c08584au: goto P_0c08584a;
case 0x0c08584cu: goto P_0c08584c;
case 0x0c08584eu: goto P_0c08584e;
case 0x0c085850u: goto P_0c085850;
case 0x0c085852u: goto P_0c085852;
case 0x0c085854u: goto P_0c085854;
case 0x0c085856u: goto P_0c085856;
case 0x0c085858u: goto P_0c085858;
case 0x0c08585au: goto P_0c08585a;
case 0x0c08585cu: goto P_0c08585c;
case 0x0c08585eu: goto P_0c08585e;
case 0x0c085860u: goto P_0c085860;
case 0x0c085862u: goto P_0c085862;
case 0x0c085864u: goto P_0c085864;
case 0x0c085866u: goto P_0c085866;
case 0x0c085868u: goto P_0c085868;
case 0x0c08586au: goto P_0c08586a;
case 0x0c08586cu: goto P_0c08586c;
case 0x0c08586eu: goto P_0c08586e;
case 0x0c085870u: goto P_0c085870;
case 0x0c085872u: goto P_0c085872;
case 0x0c085874u: goto P_0c085874;
case 0x0c085876u: goto P_0c085876;
case 0x0c085878u: goto P_0c085878;
case 0x0c08587au: goto P_0c08587a;
case 0x0c08587cu: goto P_0c08587c;
case 0x0c08587eu: goto P_0c08587e;
case 0x0c085880u: goto P_0c085880;
case 0x0c085882u: goto P_0c085882;
case 0x0c085884u: goto P_0c085884;
case 0x0c085886u: goto P_0c085886;
case 0x0c085888u: goto P_0c085888;
case 0x0c08588au: goto P_0c08588a;
case 0x0c08588cu: goto P_0c08588c;
case 0x0c08588eu: goto P_0c08588e;
case 0x0c085890u: goto P_0c085890;
case 0x0c085892u: goto P_0c085892;
case 0x0c085894u: goto P_0c085894;
case 0x0c085896u: goto P_0c085896;
case 0x0c085898u: goto P_0c085898;
case 0x0c08589au: goto P_0c08589a;
case 0x0c08589cu: goto P_0c08589c;
case 0x0c08589eu: goto P_0c08589e;
case 0x0c0858a0u: goto P_0c0858a0;
case 0x0c0858a2u: goto P_0c0858a2;
case 0x0c0858a4u: goto P_0c0858a4;
case 0x0c0858a6u: goto P_0c0858a6;
case 0x0c0858a8u: goto P_0c0858a8;
case 0x0c0858aau: goto P_0c0858aa;
case 0x0c0858acu: goto P_0c0858ac;
case 0x0c0858aeu: goto P_0c0858ae;
case 0x0c0858b0u: goto P_0c0858b0;
case 0x0c0858b2u: goto P_0c0858b2;
case 0x0c0858b4u: goto P_0c0858b4;
case 0x0c0858b6u: goto P_0c0858b6;
case 0x0c0858b8u: goto P_0c0858b8;
case 0x0c0858bau: goto P_0c0858ba;
case 0x0c0858bcu: goto P_0c0858bc;
case 0x0c0858beu: goto P_0c0858be;
case 0x0c0858c0u: goto P_0c0858c0;
case 0x0c0858c2u: goto P_0c0858c2;
case 0x0c0858c4u: goto P_0c0858c4;
case 0x0c0858c6u: goto P_0c0858c6;
case 0x0c0858c8u: goto P_0c0858c8;
case 0x0c0858cau: goto P_0c0858ca;
case 0x0c0858ccu: goto P_0c0858cc;
case 0x0c0858ceu: goto P_0c0858ce;
case 0x0c0858d0u: goto P_0c0858d0;
case 0x0c0858d2u: goto P_0c0858d2;
case 0x0c0858d4u: goto P_0c0858d4;
case 0x0c0858d6u: goto P_0c0858d6;
case 0x0c0858d8u: goto P_0c0858d8;
case 0x0c0858e8u: goto P_0c0858e8;
case 0x0c0858eau: goto P_0c0858ea;
case 0x0c0858ecu: goto P_0c0858ec;
case 0x0c0858eeu: goto P_0c0858ee;
case 0x0c0858f0u: goto P_0c0858f0;
case 0x0c0858f2u: goto P_0c0858f2;
case 0x0c0858f4u: goto P_0c0858f4;
case 0x0c0858f6u: goto P_0c0858f6;
case 0x0c0858f8u: goto P_0c0858f8;
case 0x0c0858fau: goto P_0c0858fa;
case 0x0c0858fcu: goto P_0c0858fc;
case 0x0c0858feu: goto P_0c0858fe;
case 0x0c085900u: goto P_0c085900;
case 0x0c085902u: goto P_0c085902;
case 0x0c085904u: goto P_0c085904;
case 0x0c085906u: goto P_0c085906;
case 0x0c085908u: goto P_0c085908;
case 0x0c08590au: goto P_0c08590a;
case 0x0c08590cu: goto P_0c08590c;
case 0x0c08590eu: goto P_0c08590e;
case 0x0c085910u: goto P_0c085910;
case 0x0c085912u: goto P_0c085912;
case 0x0c085914u: goto P_0c085914;
case 0x0c085916u: goto P_0c085916;
case 0x0c085918u: goto P_0c085918;
case 0x0c08591au: goto P_0c08591a;
case 0x0c08591cu: goto P_0c08591c;
case 0x0c08591eu: goto P_0c08591e;
case 0x0c085920u: goto P_0c085920;
case 0x0c085922u: goto P_0c085922;
case 0x0c085924u: goto P_0c085924;
case 0x0c085926u: goto P_0c085926;
case 0x0c085928u: goto P_0c085928;
case 0x0c08592au: goto P_0c08592a;
case 0x0c08592cu: goto P_0c08592c;
case 0x0c08592eu: goto P_0c08592e;
case 0x0c085930u: goto P_0c085930;
case 0x0c085932u: goto P_0c085932;
case 0x0c085934u: goto P_0c085934;
case 0x0c085936u: goto P_0c085936;
case 0x0c085938u: goto P_0c085938;
case 0x0c08593au: goto P_0c08593a;
case 0x0c08593cu: goto P_0c08593c;
case 0x0c08593eu: goto P_0c08593e;
case 0x0c085940u: goto P_0c085940;
case 0x0c085942u: goto P_0c085942;
case 0x0c085944u: goto P_0c085944;
case 0x0c085946u: goto P_0c085946;
case 0x0c085948u: goto P_0c085948;
case 0x0c08594au: goto P_0c08594a;
case 0x0c08594cu: goto P_0c08594c;
case 0x0c08594eu: goto P_0c08594e;
case 0x0c085950u: goto P_0c085950;
case 0x0c085952u: goto P_0c085952;
case 0x0c085954u: goto P_0c085954;
case 0x0c085956u: goto P_0c085956;
case 0x0c085958u: goto P_0c085958;
case 0x0c08595au: goto P_0c08595a;
case 0x0c08595cu: goto P_0c08595c;
case 0x0c08595eu: goto P_0c08595e;
case 0x0c085960u: goto P_0c085960;
case 0x0c085962u: goto P_0c085962;
case 0x0c085964u: goto P_0c085964;
case 0x0c085966u: goto P_0c085966;
case 0x0c085968u: goto P_0c085968;
case 0x0c08596au: goto P_0c08596a;
case 0x0c08596cu: goto P_0c08596c;
case 0x0c08596eu: goto P_0c08596e;
case 0x0c085970u: goto P_0c085970;
case 0x0c085972u: goto P_0c085972;
case 0x0c085974u: goto P_0c085974;
case 0x0c085976u: goto P_0c085976;
case 0x0c085978u: goto P_0c085978;
case 0x0c08597au: goto P_0c08597a;
case 0x0c08597cu: goto P_0c08597c;
case 0x0c08597eu: goto P_0c08597e;
case 0x0c085980u: goto P_0c085980;
case 0x0c085982u: goto P_0c085982;
case 0x0c085984u: goto P_0c085984;
case 0x0c085986u: goto P_0c085986;
case 0x0c085988u: goto P_0c085988;
case 0x0c08598au: goto P_0c08598a;
case 0x0c08598cu: goto P_0c08598c;
case 0x0c08598eu: goto P_0c08598e;
case 0x0c085990u: goto P_0c085990;
case 0x0c085992u: goto P_0c085992;
case 0x0c085994u: goto P_0c085994;
case 0x0c085996u: goto P_0c085996;
case 0x0c085998u: goto P_0c085998;
case 0x0c08599au: goto P_0c08599a;
case 0x0c08599cu: goto P_0c08599c;
case 0x0c08599eu: goto P_0c08599e;
case 0x0c0859a0u: goto P_0c0859a0;
case 0x0c0859a2u: goto P_0c0859a2;
case 0x0c0859a4u: goto P_0c0859a4;
case 0x0c0859a6u: goto P_0c0859a6;
case 0x0c0859a8u: goto P_0c0859a8;
case 0x0c0859aau: goto P_0c0859aa;
case 0x0c0859acu: goto P_0c0859ac;
case 0x0c0859aeu: goto P_0c0859ae;
case 0x0c0859b0u: goto P_0c0859b0;
case 0x0c0859b2u: goto P_0c0859b2;
case 0x0c0859b4u: goto P_0c0859b4;
case 0x0c0859b6u: goto P_0c0859b6;
case 0x0c0859b8u: goto P_0c0859b8;
case 0x0c0859bau: goto P_0c0859ba;
case 0x0c0859bcu: goto P_0c0859bc;
case 0x0c0859beu: goto P_0c0859be;
case 0x0c0859c0u: goto P_0c0859c0;
case 0x0c0859c2u: goto P_0c0859c2;
case 0x0c0859c4u: goto P_0c0859c4;
case 0x0c0859c6u: goto P_0c0859c6;
case 0x0c0859c8u: goto P_0c0859c8;
case 0x0c0859cau: goto P_0c0859ca;
case 0x0c0859ccu: goto P_0c0859cc;
case 0x0c0859ceu: goto P_0c0859ce;
case 0x0c0859d0u: goto P_0c0859d0;
case 0x0c0859d2u: goto P_0c0859d2;
default: return vf3_matrix_family(target,s,ram);
}
P_0c085830: /* original 2fe6, guest PC 0x0c085830 */
if(!s->budget--) { s->failed_pc=0x0c085830u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c085832;
P_0c085832: /* original 6043, guest PC 0x0c085832 */
if(!s->budget--) { s->failed_pc=0x0c085832u; return 0; }
r[0]=r[4];
goto P_0c085834;
P_0c085834: /* original 2fd6, guest PC 0x0c085834 */
if(!s->budget--) { s->failed_pc=0x0c085834u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c085836;
P_0c085836: /* original 2fc6, guest PC 0x0c085836 */
if(!s->budget--) { s->failed_pc=0x0c085836u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c085838;
P_0c085838: /* original 6c73, guest PC 0x0c085838 */
if(!s->budget--) { s->failed_pc=0x0c085838u; return 0; }
r[12]=r[7];
goto P_0c08583a;
P_0c08583a: /* original fffb, guest PC 0x0c08583a */
if(!s->budget--) { s->failed_pc=0x0c08583au; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c08583c;
P_0c08583c: /* original 4f22, guest PC 0x0c08583c */
if(!s->budget--) { s->failed_pc=0x0c08583cu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c08583e;
P_0c08583e: /* original 7fe0, guest PC 0x0c08583e */
if(!s->budget--) { s->failed_pc=0x0c08583eu; return 0; }
r[15]+=0xffffffe0u;
goto P_0c085840;
P_0c085840: /* original 81f8, guest PC 0x0c085840 */
if(!s->budget--) { s->failed_pc=0x0c085840u; return 0; }
write(ram,r[15]+16,r[0],2);
goto P_0c085842;
P_0c085842: /* original 6053, guest PC 0x0c085842 */
if(!s->budget--) { s->failed_pc=0x0c085842u; return 0; }
r[0]=r[5];
goto P_0c085844;
P_0c085844: /* original 81f2, guest PC 0x0c085844 */
if(!s->budget--) { s->failed_pc=0x0c085844u; return 0; }
write(ram,r[15]+4,r[0],2);
goto P_0c085846;
P_0c085846: /* original 6063, guest PC 0x0c085846 */
if(!s->budget--) { s->failed_pc=0x0c085846u; return 0; }
r[0]=r[6];
goto P_0c085848;
P_0c085848: /* original 81fa, guest PC 0x0c085848 */
if(!s->budget--) { s->failed_pc=0x0c085848u; return 0; }
write(ram,r[15]+20,r[0],2);
goto P_0c08584a;
P_0c08584a: /* original e008, guest PC 0x0c08584a */
if(!s->budget--) { s->failed_pc=0x0c08584au; return 0; }
r[0]=0x00000008u;
goto P_0c08584c;
P_0c08584c: /* original 5dfd, guest PC 0x0c08584c */
if(!s->budget--) { s->failed_pc=0x0c08584cu; return 0; }
r[13]=read(ram,r[15]+52,4);
goto P_0c08584e;
P_0c08584e: /* original ff4a, guest PC 0x0c08584e */
if(!s->budget--) { s->failed_pc=0x0c08584eu; return 0; }
vf3_matrix_store(s,ram,4,r[15]);
goto P_0c085850;
P_0c085850: /* original ff57, guest PC 0x0c085850 */
if(!s->budget--) { s->failed_pc=0x0c085850u; return 0; }
vf3_matrix_store(s,ram,5,r[15]+r[0]);
goto P_0c085852;
P_0c085852: /* original e00c, guest PC 0x0c085852 */
if(!s->budget--) { s->failed_pc=0x0c085852u; return 0; }
r[0]=0x0000000cu;
goto P_0c085854;
P_0c085854: /* original 5efe, guest PC 0x0c085854 */
if(!s->budget--) { s->failed_pc=0x0c085854u; return 0; }
r[14]=read(ram,r[15]+56,4);
goto P_0c085856;
P_0c085856: /* original ff67, guest PC 0x0c085856 */
if(!s->budget--) { s->failed_pc=0x0c085856u; return 0; }
vf3_matrix_store(s,ram,6,r[15]+r[0]);
goto P_0c085858;
P_0c085858: /* original c720, guest PC 0x0c085858 */
if(!s->budget--) { s->failed_pc=0x0c085858u; return 0; }
r[0]=code_base|0x000858dcu;
goto P_0c08585a;
P_0c08585a: /* original ff08, guest PC 0x0c08585a */
if(!s->budget--) { s->failed_pc=0x0c08585au; return 0; }
vf3_matrix_load(s,ram,15,r[0]);
goto P_0c08585c;
P_0c08585c: /* original d320, guest PC 0x0c08585c */
if(!s->budget--) { s->failed_pc=0x0c08585cu; return 0; }
r[3]=read(ram,0x0c0858e0u,4);
goto P_0c08585e;
P_0c08585e: /* original 85f8, guest PC 0x0c08585e */
if(!s->budget--) { s->failed_pc=0x0c08585eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[15]+16,2);
goto P_0c085860;
P_0c085860: /* original 430b, guest PC 0x0c085860 */
if(!s->budget--) { s->failed_pc=0x0c085860u; return 0; }
target=r[3];
r[16]=code_base|0x0c085864u;
r[4]=r[0];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c085864u) { target=s->pc; goto dispatch; }
goto P_0c085864;
P_0c085862: /* original 6403, guest PC 0x0c085862 */
if(!s->budget--) { s->failed_pc=0x0c085862u; return 0; }
r[4]=r[0];
goto P_0c085864;
P_0c085864: /* original f3fc, guest PC 0x0c085864 */
if(!s->budget--) { s->failed_pc=0x0c085864u; return 0; }
vf3_matrix_move(s,3,15);
goto P_0c085866;
P_0c085866: /* original f302, guest PC 0x0c085866 */
if(!s->budget--) { s->failed_pc=0x0c085866u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[0],r[18],'*');
goto P_0c085868;
P_0c085868: /* original e01c, guest PC 0x0c085868 */
if(!s->budget--) { s->failed_pc=0x0c085868u; return 0; }
r[0]=0x0000001cu;
goto P_0c08586a;
P_0c08586a: /* original ff37, guest PC 0x0c08586a */
if(!s->budget--) { s->failed_pc=0x0c08586au; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c08586c;
P_0c08586c: /* original d31d, guest PC 0x0c08586c */
if(!s->budget--) { s->failed_pc=0x0c08586cu; return 0; }
r[3]=read(ram,0x0c0858e4u,4);
goto P_0c08586e;
P_0c08586e: /* original 85fa, guest PC 0x0c08586e */
if(!s->budget--) { s->failed_pc=0x0c08586eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[15]+20,2);
goto P_0c085870;
P_0c085870: /* original 430b, guest PC 0x0c085870 */
if(!s->budget--) { s->failed_pc=0x0c085870u; return 0; }
target=r[3];
r[16]=code_base|0x0c085874u;
r[4]=r[0];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c085874u) { target=s->pc; goto dispatch; }
goto P_0c085874;
P_0c085872: /* original 6403, guest PC 0x0c085872 */
if(!s->budget--) { s->failed_pc=0x0c085872u; return 0; }
r[4]=r[0];
goto P_0c085874;
P_0c085874: /* original e01c, guest PC 0x0c085874 */
if(!s->budget--) { s->failed_pc=0x0c085874u; return 0; }
r[0]=0x0000001cu;
goto P_0c085876;
P_0c085876: /* original f2c8, guest PC 0x0c085876 */
if(!s->budget--) { s->failed_pc=0x0c085876u; return 0; }
vf3_matrix_load(s,ram,2,r[12]);
goto P_0c085878;
P_0c085878: /* original f3f6, guest PC 0x0c085878 */
if(!s->budget--) { s->failed_pc=0x0c085878u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c08587a;
P_0c08587a: /* original f4fc, guest PC 0x0c08587a */
if(!s->budget--) { s->failed_pc=0x0c08587au; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c08587c;
P_0c08587c: /* original f402, guest PC 0x0c08587c */
if(!s->budget--) { s->failed_pc=0x0c08587cu; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[0],r[18],'*');
goto P_0c08587e;
P_0c08587e: /* original f230, guest PC 0x0c08587e */
if(!s->budget--) { s->failed_pc=0x0c08587eu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'+');
goto P_0c085880;
P_0c085880: /* original fc2a, guest PC 0x0c085880 */
if(!s->budget--) { s->failed_pc=0x0c085880u; return 0; }
vf3_matrix_store(s,ram,2,r[12]);
goto P_0c085882;
P_0c085882: /* original f3f8, guest PC 0x0c085882 */
if(!s->budget--) { s->failed_pc=0x0c085882u; return 0; }
vf3_matrix_load(s,ram,3,r[15]);
goto P_0c085884;
P_0c085884: /* original f230, guest PC 0x0c085884 */
if(!s->budget--) { s->failed_pc=0x0c085884u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'+');
goto P_0c085886;
P_0c085886: /* original fc2a, guest PC 0x0c085886 */
if(!s->budget--) { s->failed_pc=0x0c085886u; return 0; }
vf3_matrix_store(s,ram,2,r[12]);
goto P_0c085888;
P_0c085888: /* original f3d8, guest PC 0x0c085888 */
if(!s->budget--) { s->failed_pc=0x0c085888u; return 0; }
vf3_matrix_load(s,ram,3,r[13]);
goto P_0c08588a;
P_0c08588a: /* original f340, guest PC 0x0c08588a */
if(!s->budget--) { s->failed_pc=0x0c08588au; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'+');
goto P_0c08588c;
P_0c08588c: /* original fd3a, guest PC 0x0c08588c */
if(!s->budget--) { s->failed_pc=0x0c08588cu; return 0; }
vf3_matrix_store(s,ram,3,r[13]);
goto P_0c08588e;
P_0c08588e: /* original f2d8, guest PC 0x0c08588e */
if(!s->budget--) { s->failed_pc=0x0c08588eu; return 0; }
vf3_matrix_load(s,ram,2,r[13]);
goto P_0c085890;
P_0c085890: /* original f3f8, guest PC 0x0c085890 */
if(!s->budget--) { s->failed_pc=0x0c085890u; return 0; }
vf3_matrix_load(s,ram,3,r[15]);
goto P_0c085892;
P_0c085892: /* original f230, guest PC 0x0c085892 */
if(!s->budget--) { s->failed_pc=0x0c085892u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'+');
goto P_0c085894;
P_0c085894: /* original fd2a, guest PC 0x0c085894 */
if(!s->budget--) { s->failed_pc=0x0c085894u; return 0; }
vf3_matrix_store(s,ram,2,r[13]);
goto P_0c085896;
P_0c085896: /* original 53ff, guest PC 0x0c085896 */
if(!s->budget--) { s->failed_pc=0x0c085896u; return 0; }
r[3]=read(ram,r[15]+60,4);
goto P_0c085898;
P_0c085898: /* original 901f, guest PC 0x0c085898 */
if(!s->budget--) { s->failed_pc=0x0c085898u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0858dau,2);
goto P_0c08589a;
P_0c08589a: /* original f336, guest PC 0x0c08589a */
if(!s->budget--) { s->failed_pc=0x0c08589au; return 0; }
vf3_matrix_load(s,ram,3,r[3]+r[0]);
goto P_0c08589c;
P_0c08589c: /* original e018, guest PC 0x0c08589c */
if(!s->budget--) { s->failed_pc=0x0c08589cu; return 0; }
r[0]=0x00000018u;
goto P_0c08589e;
P_0c08589e: /* original ff37, guest PC 0x0c08589e */
if(!s->budget--) { s->failed_pc=0x0c08589eu; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0858a0;
P_0c0858a0: /* original d30f, guest PC 0x0c0858a0 */
if(!s->budget--) { s->failed_pc=0x0c0858a0u; return 0; }
r[3]=read(ram,0x0c0858e0u,4);
goto P_0c0858a2;
P_0c0858a2: /* original 85f2, guest PC 0x0c0858a2 */
if(!s->budget--) { s->failed_pc=0x0c0858a2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[15]+4,2);
goto P_0c0858a4;
P_0c0858a4: /* original 430b, guest PC 0x0c0858a4 */
if(!s->budget--) { s->failed_pc=0x0c0858a4u; return 0; }
target=r[3];
r[16]=code_base|0x0c0858a8u;
r[4]=r[0];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0858a8u) { target=s->pc; goto dispatch; }
goto P_0c0858a8;
P_0c0858a6: /* original 6403, guest PC 0x0c0858a6 */
if(!s->budget--) { s->failed_pc=0x0c0858a6u; return 0; }
r[4]=r[0];
goto P_0c0858a8;
P_0c0858a8: /* original e018, guest PC 0x0c0858a8 */
if(!s->budget--) { s->failed_pc=0x0c0858a8u; return 0; }
r[0]=0x00000018u;
goto P_0c0858aa;
P_0c0858aa: /* original f4f6, guest PC 0x0c0858aa */
if(!s->budget--) { s->failed_pc=0x0c0858aau; return 0; }
vf3_matrix_load(s,ram,4,r[15]+r[0]);
goto P_0c0858ac;
P_0c0858ac: /* original e008, guest PC 0x0c0858ac */
if(!s->budget--) { s->failed_pc=0x0c0858acu; return 0; }
r[0]=0x00000008u;
goto P_0c0858ae;
P_0c0858ae: /* original f402, guest PC 0x0c0858ae */
if(!s->budget--) { s->failed_pc=0x0c0858aeu; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[0],r[18],'*');
goto P_0c0858b0;
P_0c0858b0: /* original f34c, guest PC 0x0c0858b0 */
if(!s->budget--) { s->failed_pc=0x0c0858b0u; return 0; }
vf3_matrix_move(s,3,4);
goto P_0c0858b2;
P_0c0858b2: /* original f4f6, guest PC 0x0c0858b2 */
if(!s->budget--) { s->failed_pc=0x0c0858b2u; return 0; }
vf3_matrix_load(s,ram,4,r[15]+r[0]);
goto P_0c0858b4;
P_0c0858b4: /* original e00c, guest PC 0x0c0858b4 */
if(!s->budget--) { s->failed_pc=0x0c0858b4u; return 0; }
r[0]=0x0000000cu;
goto P_0c0858b6;
P_0c0858b6: /* original f430, guest PC 0x0c0858b6 */
if(!s->budget--) { s->failed_pc=0x0c0858b6u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'+');
goto P_0c0858b8;
P_0c0858b8: /* original f3f6, guest PC 0x0c0858b8 */
if(!s->budget--) { s->failed_pc=0x0c0858b8u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0858ba;
P_0c0858ba: /* original 7f20, guest PC 0x0c0858ba */
if(!s->budget--) { s->failed_pc=0x0c0858bau; return 0; }
r[15]+=0x00000020u;
goto P_0c0858bc;
P_0c0858bc: /* original 4f26, guest PC 0x0c0858bc */
if(!s->budget--) { s->failed_pc=0x0c0858bcu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0858be;
P_0c0858be: /* original fe3a, guest PC 0x0c0858be */
if(!s->budget--) { s->failed_pc=0x0c0858beu; return 0; }
vf3_matrix_store(s,ram,3,r[14]);
goto P_0c0858c0;
P_0c0858c0: /* original e004, guest PC 0x0c0858c0 */
if(!s->budget--) { s->failed_pc=0x0c0858c0u; return 0; }
r[0]=0x00000004u;
goto P_0c0858c2;
P_0c0858c2: /* original f3c8, guest PC 0x0c0858c2 */
if(!s->budget--) { s->failed_pc=0x0c0858c2u; return 0; }
vf3_matrix_load(s,ram,3,r[12]);
goto P_0c0858c4;
P_0c0858c4: /* original fe37, guest PC 0x0c0858c4 */
if(!s->budget--) { s->failed_pc=0x0c0858c4u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c0858c6;
P_0c0858c6: /* original e008, guest PC 0x0c0858c6 */
if(!s->budget--) { s->failed_pc=0x0c0858c6u; return 0; }
r[0]=0x00000008u;
goto P_0c0858c8;
P_0c0858c8: /* original fe47, guest PC 0x0c0858c8 */
if(!s->budget--) { s->failed_pc=0x0c0858c8u; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c0858ca;
P_0c0858ca: /* original e00c, guest PC 0x0c0858ca */
if(!s->budget--) { s->failed_pc=0x0c0858cau; return 0; }
r[0]=0x0000000cu;
goto P_0c0858cc;
P_0c0858cc: /* original f3d8, guest PC 0x0c0858cc */
if(!s->budget--) { s->failed_pc=0x0c0858ccu; return 0; }
vf3_matrix_load(s,ram,3,r[13]);
goto P_0c0858ce;
P_0c0858ce: /* original fe37, guest PC 0x0c0858ce */
if(!s->budget--) { s->failed_pc=0x0c0858ceu; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c0858d0;
P_0c0858d0: /* original fff9, guest PC 0x0c0858d0 */
if(!s->budget--) { s->failed_pc=0x0c0858d0u; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0858d2;
P_0c0858d2: /* original 6cf6, guest PC 0x0c0858d2 */
if(!s->budget--) { s->failed_pc=0x0c0858d2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0858d4;
P_0c0858d4: /* original 6df6, guest PC 0x0c0858d4 */
if(!s->budget--) { s->failed_pc=0x0c0858d4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0858d6;
P_0c0858d6: /* original 000b, guest PC 0x0c0858d6 */
if(!s->budget--) { s->failed_pc=0x0c0858d6u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0858d8: /* original 6ef6, guest PC 0x0c0858d8 */
if(!s->budget--) { s->failed_pc=0x0c0858d8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0858dau,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0858dau; return 0; } return 1;
P_0c0858e8: /* original 2fe6, guest PC 0x0c0858e8 */
if(!s->budget--) { s->failed_pc=0x0c0858e8u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0858ea;
P_0c0858ea: /* original 6e43, guest PC 0x0c0858ea */
if(!s->budget--) { s->failed_pc=0x0c0858eau; return 0; }
r[14]=r[4];
goto P_0c0858ec;
P_0c0858ec: /* original 2fd6, guest PC 0x0c0858ec */
if(!s->budget--) { s->failed_pc=0x0c0858ecu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0858ee;
P_0c0858ee: /* original fffb, guest PC 0x0c0858ee */
if(!s->budget--) { s->failed_pc=0x0c0858eeu; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c0858f0;
P_0c0858f0: /* original 9070, guest PC 0x0c0858f0 */
if(!s->budget--) { s->failed_pc=0x0c0858f0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0859d4u,2);
goto P_0c0858f2;
P_0c0858f2: /* original 4f22, guest PC 0x0c0858f2 */
if(!s->budget--) { s->failed_pc=0x0c0858f2u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0858f4;
P_0c0858f4: /* original 00ed, guest PC 0x0c0858f4 */
if(!s->budget--) { s->failed_pc=0x0c0858f4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0858f6;
P_0c0858f6: /* original 7fec, guest PC 0x0c0858f6 */
if(!s->budget--) { s->failed_pc=0x0c0858f6u; return 0; }
r[15]+=0xffffffecu;
goto P_0c0858f8;
P_0c0858f8: /* original 81f2, guest PC 0x0c0858f8 */
if(!s->budget--) { s->failed_pc=0x0c0858f8u; return 0; }
write(ram,r[15]+4,r[0],2);
goto P_0c0858fa;
P_0c0858fa: /* original c73b, guest PC 0x0c0858fa */
if(!s->budget--) { s->failed_pc=0x0c0858fau; return 0; }
r[0]=code_base|0x000859e8u;
goto P_0c0858fc;
P_0c0858fc: /* original f308, guest PC 0x0c0858fc */
if(!s->budget--) { s->failed_pc=0x0c0858fcu; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c0858fe;
P_0c0858fe: /* original e008, guest PC 0x0c0858fe */
if(!s->budget--) { s->failed_pc=0x0c0858feu; return 0; }
r[0]=0x00000008u;
goto P_0c085900;
P_0c085900: /* original ff37, guest PC 0x0c085900 */
if(!s->budget--) { s->failed_pc=0x0c085900u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c085902;
P_0c085902: /* original 85f2, guest PC 0x0c085902 */
if(!s->budget--) { s->failed_pc=0x0c085902u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[15]+4,2);
goto P_0c085904;
P_0c085904: /* original dd39, guest PC 0x0c085904 */
if(!s->budget--) { s->failed_pc=0x0c085904u; return 0; }
r[13]=read(ram,0x0c0859ecu,4);
goto P_0c085906;
P_0c085906: /* original 4d0b, guest PC 0x0c085906 */
if(!s->budget--) { s->failed_pc=0x0c085906u; return 0; }
target=r[13];
r[16]=code_base|0x0c08590au;
r[4]=r[0];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08590au) { target=s->pc; goto dispatch; }
goto P_0c08590a;
P_0c085908: /* original 6403, guest PC 0x0c085908 */
if(!s->budget--) { s->failed_pc=0x0c085908u; return 0; }
r[4]=r[0];
goto P_0c08590a;
P_0c08590a: /* original e008, guest PC 0x0c08590a */
if(!s->budget--) { s->failed_pc=0x0c08590au; return 0; }
r[0]=0x00000008u;
goto P_0c08590c;
P_0c08590c: /* original f4f6, guest PC 0x0c08590c */
if(!s->budget--) { s->failed_pc=0x0c08590cu; return 0; }
vf3_matrix_load(s,ram,4,r[15]+r[0]);
goto P_0c08590e;
P_0c08590e: /* original 9062, guest PC 0x0c08590e */
if(!s->budget--) { s->failed_pc=0x0c08590eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0859d6u,2);
goto P_0c085910;
P_0c085910: /* original f402, guest PC 0x0c085910 */
if(!s->budget--) { s->failed_pc=0x0c085910u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[0],r[18],'*');
goto P_0c085912;
P_0c085912: /* original f43d, guest PC 0x0c085912 */
if(!s->budget--) { s->failed_pc=0x0c085912u; return 0; }
r[53]=truncate_float(fr[4]);
goto P_0c085914;
P_0c085914: /* original 035a, guest PC 0x0c085914 */
if(!s->budget--) { s->failed_pc=0x0c085914u; return 0; }
r[3]=r[53];
goto P_0c085916;
P_0c085916: /* original 0e35, guest PC 0x0c085916 */
if(!s->budget--) { s->failed_pc=0x0c085916u; return 0; }
write(ram,r[14]+r[0],r[3],2);
goto P_0c085918;
P_0c085918: /* original 70f8, guest PC 0x0c085918 */
if(!s->budget--) { s->failed_pc=0x0c085918u; return 0; }
r[0]+=0xfffffff8u;
goto P_0c08591a;
P_0c08591a: /* original 00ed, guest PC 0x0c08591a */
if(!s->budget--) { s->failed_pc=0x0c08591au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c08591c;
P_0c08591c: /* original 81f6, guest PC 0x0c08591c */
if(!s->budget--) { s->failed_pc=0x0c08591cu; return 0; }
write(ram,r[15]+12,r[0],2);
goto P_0c08591e;
P_0c08591e: /* original 905b, guest PC 0x0c08591e */
if(!s->budget--) { s->failed_pc=0x0c08591eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0859d8u,2);
goto P_0c085920;
P_0c085920: /* original 00ed, guest PC 0x0c085920 */
if(!s->budget--) { s->failed_pc=0x0c085920u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c085922;
P_0c085922: /* original 81f2, guest PC 0x0c085922 */
if(!s->budget--) { s->failed_pc=0x0c085922u; return 0; }
write(ram,r[15]+4,r[0],2);
goto P_0c085924;
P_0c085924: /* original c732, guest PC 0x0c085924 */
if(!s->budget--) { s->failed_pc=0x0c085924u; return 0; }
r[0]=code_base|0x000859f0u;
goto P_0c085926;
P_0c085926: /* original ff08, guest PC 0x0c085926 */
if(!s->budget--) { s->failed_pc=0x0c085926u; return 0; }
vf3_matrix_load(s,ram,15,r[0]);
goto P_0c085928;
P_0c085928: /* original 85f6, guest PC 0x0c085928 */
if(!s->budget--) { s->failed_pc=0x0c085928u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[15]+12,2);
goto P_0c08592a;
P_0c08592a: /* original 4d0b, guest PC 0x0c08592a */
if(!s->budget--) { s->failed_pc=0x0c08592au; return 0; }
target=r[13];
r[16]=code_base|0x0c08592eu;
r[4]=r[0];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08592eu) { target=s->pc; goto dispatch; }
goto P_0c08592e;
P_0c08592c: /* original 6403, guest PC 0x0c08592c */
if(!s->budget--) { s->failed_pc=0x0c08592cu; return 0; }
r[4]=r[0];
goto P_0c08592e;
P_0c08592e: /* original f3fc, guest PC 0x0c08592e */
if(!s->budget--) { s->failed_pc=0x0c08592eu; return 0; }
vf3_matrix_move(s,3,15);
goto P_0c085930;
P_0c085930: /* original f302, guest PC 0x0c085930 */
if(!s->budget--) { s->failed_pc=0x0c085930u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[0],r[18],'*');
goto P_0c085932;
P_0c085932: /* original e010, guest PC 0x0c085932 */
if(!s->budget--) { s->failed_pc=0x0c085932u; return 0; }
r[0]=0x00000010u;
goto P_0c085934;
P_0c085934: /* original ff37, guest PC 0x0c085934 */
if(!s->budget--) { s->failed_pc=0x0c085934u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c085936;
P_0c085936: /* original d32f, guest PC 0x0c085936 */
if(!s->budget--) { s->failed_pc=0x0c085936u; return 0; }
r[3]=read(ram,0x0c0859f4u,4);
goto P_0c085938;
P_0c085938: /* original 85f2, guest PC 0x0c085938 */
if(!s->budget--) { s->failed_pc=0x0c085938u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[15]+4,2);
goto P_0c08593a;
P_0c08593a: /* original 430b, guest PC 0x0c08593a */
if(!s->budget--) { s->failed_pc=0x0c08593au; return 0; }
target=r[3];
r[16]=code_base|0x0c08593eu;
r[4]=r[0];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08593eu) { target=s->pc; goto dispatch; }
goto P_0c08593e;
P_0c08593c: /* original 6403, guest PC 0x0c08593c */
if(!s->budget--) { s->failed_pc=0x0c08593cu; return 0; }
r[4]=r[0];
goto P_0c08593e;
P_0c08593e: /* original f4fc, guest PC 0x0c08593e */
if(!s->budget--) { s->failed_pc=0x0c08593eu; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c085940;
P_0c085940: /* original f402, guest PC 0x0c085940 */
if(!s->budget--) { s->failed_pc=0x0c085940u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[0],r[18],'*');
goto P_0c085942;
P_0c085942: /* original e010, guest PC 0x0c085942 */
if(!s->budget--) { s->failed_pc=0x0c085942u; return 0; }
r[0]=0x00000010u;
goto P_0c085944;
P_0c085944: /* original f34c, guest PC 0x0c085944 */
if(!s->budget--) { s->failed_pc=0x0c085944u; return 0; }
vf3_matrix_move(s,3,4);
goto P_0c085946;
P_0c085946: /* original f4f6, guest PC 0x0c085946 */
if(!s->budget--) { s->failed_pc=0x0c085946u; return 0; }
vf3_matrix_load(s,ram,4,r[15]+r[0]);
goto P_0c085948;
P_0c085948: /* original f430, guest PC 0x0c085948 */
if(!s->budget--) { s->failed_pc=0x0c085948u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'+');
goto P_0c08594a;
P_0c08594a: /* original f43d, guest PC 0x0c08594a */
if(!s->budget--) { s->failed_pc=0x0c08594au; return 0; }
r[53]=truncate_float(fr[4]);
goto P_0c08594c;
P_0c08594c: /* original 035a, guest PC 0x0c08594c */
if(!s->budget--) { s->failed_pc=0x0c08594cu; return 0; }
r[3]=r[53];
goto P_0c08594e;
P_0c08594e: /* original 633f, guest PC 0x0c08594e */
if(!s->budget--) { s->failed_pc=0x0c08594eu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)r[3];
goto P_0c085950;
P_0c085950: /* original 6233, guest PC 0x0c085950 */
if(!s->budget--) { s->failed_pc=0x0c085950u; return 0; }
r[2]=r[3];
goto P_0c085952;
P_0c085952: /* original 2f32, guest PC 0x0c085952 */
if(!s->budget--) { s->failed_pc=0x0c085952u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c085954;
P_0c085954: /* original 9041, guest PC 0x0c085954 */
if(!s->budget--) { s->failed_pc=0x0c085954u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0859dau,2);
goto P_0c085956;
P_0c085956: /* original 0e25, guest PC 0x0c085956 */
if(!s->budget--) { s->failed_pc=0x0c085956u; return 0; }
write(ram,r[14]+r[0],r[2],2);
goto P_0c085958;
P_0c085958: /* original c727, guest PC 0x0c085958 */
if(!s->budget--) { s->failed_pc=0x0c085958u; return 0; }
r[0]=code_base|0x000859f8u;
goto P_0c08595a;
P_0c08595a: /* original f308, guest PC 0x0c08595a */
if(!s->budget--) { s->failed_pc=0x0c08595au; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c08595c;
P_0c08595c: /* original 903e, guest PC 0x0c08595c */
if(!s->budget--) { s->failed_pc=0x0c08595cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0859dcu,2);
goto P_0c08595e;
P_0c08595e: /* original fe37, guest PC 0x0c08595e */
if(!s->budget--) { s->failed_pc=0x0c08595eu; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c085960;
P_0c085960: /* original 903d, guest PC 0x0c085960 */
if(!s->budget--) { s->failed_pc=0x0c085960u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0859deu,2);
goto P_0c085962;
P_0c085962: /* original 03ed, guest PC 0x0c085962 */
if(!s->budget--) { s->failed_pc=0x0c085962u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c085964;
P_0c085964: /* original 2f32, guest PC 0x0c085964 */
if(!s->budget--) { s->failed_pc=0x0c085964u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c085966;
P_0c085966: /* original d126, guest PC 0x0c085966 */
if(!s->budget--) { s->failed_pc=0x0c085966u; return 0; }
r[1]=read(ram,0x0c085a00u,4);
goto P_0c085968;
P_0c085968: /* original 903a, guest PC 0x0c085968 */
if(!s->budget--) { s->failed_pc=0x0c085968u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0859e0u,2);
goto P_0c08596a;
P_0c08596a: /* original 6212, guest PC 0x0c08596a */
if(!s->budget--) { s->failed_pc=0x0c08596au; return 0; }
tmp=read(ram,r[1],4);
r[2]=tmp;
goto P_0c08596c;
P_0c08596c: /* original d323, guest PC 0x0c08596c */
if(!s->budget--) { s->failed_pc=0x0c08596cu; return 0; }
r[3]=read(ram,0x0c0859fcu,4);
goto P_0c08596e;
P_0c08596e: /* original 04ed, guest PC 0x0c08596e */
if(!s->budget--) { s->failed_pc=0x0c08596eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c085970;
P_0c085970: /* original 2238, guest PC 0x0c085970 */
if(!s->budget--) { s->failed_pc=0x0c085970u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c085972;
P_0c085972: /* original 8b0f, guest PC 0x0c085972 */
if(!s->budget--) { s->failed_pc=0x0c085972u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c085994; }
goto P_0c085974;
P_0c085974: /* original 9035, guest PC 0x0c085974 */
if(!s->budget--) { s->failed_pc=0x0c085974u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0859e2u,2);
goto P_0c085976;
P_0c085976: /* original 05ed, guest PC 0x0c085976 */
if(!s->budget--) { s->failed_pc=0x0c085976u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c085978;
P_0c085978: /* original 2558, guest PC 0x0c085978 */
if(!s->budget--) { s->failed_pc=0x0c085978u; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[5])==0)!=0);
goto P_0c08597a;
P_0c08597a: /* original 8904, guest PC 0x0c08597a */
if(!s->budget--) { s->failed_pc=0x0c08597au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c085986; }
goto P_0c08597c;
P_0c08597c: /* original 65f3, guest PC 0x0c08597c */
if(!s->budget--) { s->failed_pc=0x0c08597cu; return 0; }
r[5]=r[15];
goto P_0c08597e;
P_0c08597e: /* original b103, guest PC 0x0c08597e */
if(!s->budget--) { s->failed_pc=0x0c08597eu; return 0; }
target=code_base|0x0c085b88u; r[16]=code_base|0x0c085982u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c085982u) { target=s->pc; goto dispatch; }
goto P_0c085982;
P_0c085980: /* original 64e3, guest PC 0x0c085980 */
if(!s->budget--) { s->failed_pc=0x0c085980u; return 0; }
r[4]=r[14];
goto P_0c085982;
P_0c085982: /* original a007, guest PC 0x0c085982 */
if(!s->budget--) { s->failed_pc=0x0c085982u; return 0; }
goto P_0c085994;
P_0c085984: /* original 0009, guest PC 0x0c085984 */
if(!s->budget--) { s->failed_pc=0x0c085984u; return 0; }
goto P_0c085986;
P_0c085986: /* original 63f2, guest PC 0x0c085986 */
if(!s->budget--) { s->failed_pc=0x0c085986u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c085988;
P_0c085988: /* original 644f, guest PC 0x0c085988 */
if(!s->budget--) { s->failed_pc=0x0c085988u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)r[4];
goto P_0c08598a;
P_0c08598a: /* original 334c, guest PC 0x0c08598a */
if(!s->budget--) { s->failed_pc=0x0c08598au; return 0; }
r[3]+=r[4];
goto P_0c08598c;
P_0c08598c: /* original 6233, guest PC 0x0c08598c */
if(!s->budget--) { s->failed_pc=0x0c08598cu; return 0; }
r[2]=r[3];
goto P_0c08598e;
P_0c08598e: /* original 2f32, guest PC 0x0c08598e */
if(!s->budget--) { s->failed_pc=0x0c08598eu; return 0; }
write(ram,r[15],r[3],4);
goto P_0c085990;
P_0c085990: /* original 9025, guest PC 0x0c085990 */
if(!s->budget--) { s->failed_pc=0x0c085990u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0859deu,2);
goto P_0c085992;
P_0c085992: /* original 0e25, guest PC 0x0c085992 */
if(!s->budget--) { s->failed_pc=0x0c085992u; return 0; }
write(ram,r[14]+r[0],r[2],2);
goto P_0c085994;
P_0c085994: /* original 63f2, guest PC 0x0c085994 */
if(!s->budget--) { s->failed_pc=0x0c085994u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c085996;
P_0c085996: /* original 4311, guest PC 0x0c085996 */
if(!s->budget--) { s->failed_pc=0x0c085996u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>=0)!=0);
goto P_0c085998;
P_0c085998: /* original 8b02, guest PC 0x0c085998 */
if(!s->budget--) { s->failed_pc=0x0c085998u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0859a0; }
goto P_0c08599a;
P_0c08599a: /* original 65f3, guest PC 0x0c08599a */
if(!s->budget--) { s->failed_pc=0x0c08599au; return 0; }
r[5]=r[15];
goto P_0c08599c;
P_0c08599c: /* original b0f4, guest PC 0x0c08599c */
if(!s->budget--) { s->failed_pc=0x0c08599cu; return 0; }
target=code_base|0x0c085b88u; r[16]=code_base|0x0c0859a0u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0859a0u) { target=s->pc; goto dispatch; }
goto P_0c0859a0;
P_0c08599e: /* original 64e3, guest PC 0x0c08599e */
if(!s->budget--) { s->failed_pc=0x0c08599eu; return 0; }
r[4]=r[14];
goto P_0c0859a0;
P_0c0859a0: /* original 64f2, guest PC 0x0c0859a0 */
if(!s->budget--) { s->failed_pc=0x0c0859a0u; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c0859a2;
P_0c0859a2: /* original 4d0b, guest PC 0x0c0859a2 */
if(!s->budget--) { s->failed_pc=0x0c0859a2u; return 0; }
target=r[13];
r[16]=code_base|0x0c0859a6u;
r[4]=(uint32_t)(int32_t)(int16_t)r[4];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0859a6u) { target=s->pc; goto dispatch; }
goto P_0c0859a6;
P_0c0859a4: /* original 644f, guest PC 0x0c0859a4 */
if(!s->budget--) { s->failed_pc=0x0c0859a4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)r[4];
goto P_0c0859a6;
P_0c0859a6: /* original c717, guest PC 0x0c0859a6 */
if(!s->budget--) { s->failed_pc=0x0c0859a6u; return 0; }
r[0]=code_base|0x00085a04u;
goto P_0c0859a8;
P_0c0859a8: /* original f40c, guest PC 0x0c0859a8 */
if(!s->budget--) { s->failed_pc=0x0c0859a8u; return 0; }
vf3_matrix_move(s,4,0);
goto P_0c0859aa;
P_0c0859aa: /* original f308, guest PC 0x0c0859aa */
if(!s->budget--) { s->failed_pc=0x0c0859aau; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c0859ac;
P_0c0859ac: /* original f28d, guest PC 0x0c0859ac */
if(!s->budget--) { s->failed_pc=0x0c0859acu; return 0; }
fr[2]=0;
goto P_0c0859ae;
P_0c0859ae: /* original f432, guest PC 0x0c0859ae */
if(!s->budget--) { s->failed_pc=0x0c0859aeu; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'*');
goto P_0c0859b0;
P_0c0859b0: /* original f245, guest PC 0x0c0859b0 */
if(!s->budget--) { s->failed_pc=0x0c0859b0u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[2])>as_float(fr[4]))!=0);
goto P_0c0859b2;
P_0c0859b2: /* original 8b04, guest PC 0x0c0859b2 */
if(!s->budget--) { s->failed_pc=0x0c0859b2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0859be; }
goto P_0c0859b4;
P_0c0859b4: /* original f14c, guest PC 0x0c0859b4 */
if(!s->budget--) { s->failed_pc=0x0c0859b4u; return 0; }
vf3_matrix_move(s,1,4);
goto P_0c0859b6;
P_0c0859b6: /* original f29d, guest PC 0x0c0859b6 */
if(!s->budget--) { s->failed_pc=0x0c0859b6u; return 0; }
fr[2]=0x3f800000u;
goto P_0c0859b8;
P_0c0859b8: /* original f122, guest PC 0x0c0859b8 */
if(!s->budget--) { s->failed_pc=0x0c0859b8u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[2],r[18],'*');
goto P_0c0859ba;
P_0c0859ba: /* original f41c, guest PC 0x0c0859ba */
if(!s->budget--) { s->failed_pc=0x0c0859bau; return 0; }
vf3_matrix_move(s,4,1);
goto P_0c0859bc;
P_0c0859bc: /* original f44d, guest PC 0x0c0859bc */
if(!s->budget--) { s->failed_pc=0x0c0859bcu; return 0; }
fr[4]^=0x80000000u;
goto P_0c0859be;
P_0c0859be: /* original 7f14, guest PC 0x0c0859be */
if(!s->budget--) { s->failed_pc=0x0c0859beu; return 0; }
r[15]+=0x00000014u;
goto P_0c0859c0;
P_0c0859c0: /* original c711, guest PC 0x0c0859c0 */
if(!s->budget--) { s->failed_pc=0x0c0859c0u; return 0; }
r[0]=code_base|0x00085a08u;
goto P_0c0859c2;
P_0c0859c2: /* original 4f26, guest PC 0x0c0859c2 */
if(!s->budget--) { s->failed_pc=0x0c0859c2u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0859c4;
P_0c0859c4: /* original f308, guest PC 0x0c0859c4 */
if(!s->budget--) { s->failed_pc=0x0c0859c4u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c0859c6;
P_0c0859c6: /* original 900d, guest PC 0x0c0859c6 */
if(!s->budget--) { s->failed_pc=0x0c0859c6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0859e4u,2);
goto P_0c0859c8;
P_0c0859c8: /* original f430, guest PC 0x0c0859c8 */
if(!s->budget--) { s->failed_pc=0x0c0859c8u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'+');
goto P_0c0859ca;
P_0c0859ca: /* original fe47, guest PC 0x0c0859ca */
if(!s->budget--) { s->failed_pc=0x0c0859cau; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c0859cc;
P_0c0859cc: /* original fff9, guest PC 0x0c0859cc */
if(!s->budget--) { s->failed_pc=0x0c0859ccu; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0859ce;
P_0c0859ce: /* original 6df6, guest PC 0x0c0859ce */
if(!s->budget--) { s->failed_pc=0x0c0859ceu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0859d0;
P_0c0859d0: /* original 000b, guest PC 0x0c0859d0 */
if(!s->budget--) { s->failed_pc=0x0c0859d0u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0859d2: /* original 6ef6, guest PC 0x0c0859d2 */
if(!s->budget--) { s->failed_pc=0x0c0859d2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0859d4u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0859d4u; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
