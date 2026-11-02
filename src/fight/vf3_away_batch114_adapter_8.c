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
int vf3_away_batch114_adapter_8(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
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
case 0x0c0a1282u: goto P_0c0a1282;
case 0x0c0a1284u: goto P_0c0a1284;
case 0x0c0a1286u: goto P_0c0a1286;
case 0x0c0a1288u: goto P_0c0a1288;
case 0x0c0a128au: goto P_0c0a128a;
case 0x0c0a128cu: goto P_0c0a128c;
case 0x0c0a128eu: goto P_0c0a128e;
case 0x0c0a1290u: goto P_0c0a1290;
case 0x0c0a1292u: goto P_0c0a1292;
case 0x0c0a82c0u: goto P_0c0a82c0;
case 0x0c0a82c2u: goto P_0c0a82c2;
case 0x0c0a82c4u: goto P_0c0a82c4;
case 0x0c0a82c6u: goto P_0c0a82c6;
case 0x0c0a82c8u: goto P_0c0a82c8;
case 0x0c0a82cau: goto P_0c0a82ca;
case 0x0c0a82ccu: goto P_0c0a82cc;
case 0x0c0a82ceu: goto P_0c0a82ce;
case 0x0c0a82d0u: goto P_0c0a82d0;
case 0x0c0a82d2u: goto P_0c0a82d2;
case 0x0c0a82d4u: goto P_0c0a82d4;
case 0x0c0a82d6u: goto P_0c0a82d6;
case 0x0c0a82d8u: goto P_0c0a82d8;
case 0x0c0a82dau: goto P_0c0a82da;
case 0x0c0a82dcu: goto P_0c0a82dc;
case 0x0c0a82deu: goto P_0c0a82de;
case 0x0c0a82e0u: goto P_0c0a82e0;
case 0x0c0a82e2u: goto P_0c0a82e2;
case 0x0c0a82e4u: goto P_0c0a82e4;
case 0x0c0a82e6u: goto P_0c0a82e6;
case 0x0c0a82e8u: goto P_0c0a82e8;
case 0x0c0a82eau: goto P_0c0a82ea;
case 0x0c0a82ecu: goto P_0c0a82ec;
case 0x0c0a82eeu: goto P_0c0a82ee;
case 0x0c0a82f0u: goto P_0c0a82f0;
case 0x0c0a82f2u: goto P_0c0a82f2;
case 0x0c0a82f4u: goto P_0c0a82f4;
case 0x0c0a82f6u: goto P_0c0a82f6;
case 0x0c0a82f8u: goto P_0c0a82f8;
case 0x0c0a82fau: goto P_0c0a82fa;
case 0x0c0a82fcu: goto P_0c0a82fc;
case 0x0c0a82feu: goto P_0c0a82fe;
case 0x0c0a8300u: goto P_0c0a8300;
case 0x0c0a8302u: goto P_0c0a8302;
case 0x0c0a8304u: goto P_0c0a8304;
case 0x0c0a8306u: goto P_0c0a8306;
case 0x0c0a8308u: goto P_0c0a8308;
case 0x0c0a830au: goto P_0c0a830a;
case 0x0c0a830cu: goto P_0c0a830c;
case 0x0c0a830eu: goto P_0c0a830e;
case 0x0c0a8310u: goto P_0c0a8310;
case 0x0c0a8312u: goto P_0c0a8312;
case 0x0c0a8314u: goto P_0c0a8314;
case 0x0c0a8316u: goto P_0c0a8316;
case 0x0c0a8318u: goto P_0c0a8318;
case 0x0c0a831au: goto P_0c0a831a;
case 0x0c0a831cu: goto P_0c0a831c;
case 0x0c0a831eu: goto P_0c0a831e;
case 0x0c0a8320u: goto P_0c0a8320;
case 0x0c0a8322u: goto P_0c0a8322;
case 0x0c0a8324u: goto P_0c0a8324;
case 0x0c0a8326u: goto P_0c0a8326;
case 0x0c0a8328u: goto P_0c0a8328;
case 0x0c0a832au: goto P_0c0a832a;
case 0x0c0a832cu: goto P_0c0a832c;
case 0x0c0a832eu: goto P_0c0a832e;
case 0x0c0a8330u: goto P_0c0a8330;
case 0x0c0a8332u: goto P_0c0a8332;
case 0x0c0a8334u: goto P_0c0a8334;
case 0x0c0a8336u: goto P_0c0a8336;
case 0x0c0a8338u: goto P_0c0a8338;
case 0x0c0a833au: goto P_0c0a833a;
case 0x0c0a833cu: goto P_0c0a833c;
case 0x0c0a833eu: goto P_0c0a833e;
case 0x0c0a8340u: goto P_0c0a8340;
case 0x0c0a8342u: goto P_0c0a8342;
case 0x0c0a8344u: goto P_0c0a8344;
case 0x0c0a8346u: goto P_0c0a8346;
case 0x0c0a8348u: goto P_0c0a8348;
case 0x0c0a834au: goto P_0c0a834a;
case 0x0c0a834cu: goto P_0c0a834c;
case 0x0c0a834eu: goto P_0c0a834e;
case 0x0c0a8350u: goto P_0c0a8350;
case 0x0c0a8352u: goto P_0c0a8352;
case 0x0c0a8354u: goto P_0c0a8354;
default: return vf3_matrix_family(target,s,ram);
}
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
case 0x0c09571cu: return vf3_matrix_family(0x0c09571cu,s,ram);
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
P_0c0a1282: /* original 6043, guest PC 0x0c0a1282 */
if(!s->budget--) { s->failed_pc=0x0c0a1282u; return 0; }
r[0]=r[4];
goto P_0c0a1284;
P_0c0a1284: /* original 4008, guest PC 0x0c0a1284 */
if(!s->budget--) { s->failed_pc=0x0c0a1284u; return 0; }
r[0]<<=2;
goto P_0c0a1286;
P_0c0a1286: /* original 6343, guest PC 0x0c0a1286 */
if(!s->budget--) { s->failed_pc=0x0c0a1286u; return 0; }
r[3]=r[4];
goto P_0c0a1288;
P_0c0a1288: /* original 303c, guest PC 0x0c0a1288 */
if(!s->budget--) { s->failed_pc=0x0c0a1288u; return 0; }
r[0]+=r[3];
goto P_0c0a128a;
P_0c0a128a: /* original d21d, guest PC 0x0c0a128a */
if(!s->budget--) { s->failed_pc=0x0c0a128au; return 0; }
r[2]=read(ram,0x0c0a1300u,4);
goto P_0c0a128c;
P_0c0a128c: /* original 4008, guest PC 0x0c0a128c */
if(!s->budget--) { s->failed_pc=0x0c0a128cu; return 0; }
r[0]<<=2;
goto P_0c0a128e;
P_0c0a128e: /* original 600e, guest PC 0x0c0a128e */
if(!s->budget--) { s->failed_pc=0x0c0a128eu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)r[0];
goto P_0c0a1290;
P_0c0a1290: /* original 000b, guest PC 0x0c0a1290 */
if(!s->budget--) { s->failed_pc=0x0c0a1290u; return 0; }
target=r[16];
r[0]+=r[2];
s->pc=target; return ram->oob==0;
P_0c0a1292: /* original 302c, guest PC 0x0c0a1292 */
if(!s->budget--) { s->failed_pc=0x0c0a1292u; return 0; }
r[0]+=r[2];
if(!vf3_matrix_family(0x0c0a1294u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0a1294u; return 0; } return 1;
P_0c0a82c0: /* original 2fe6, guest PC 0x0c0a82c0 */
if(!s->budget--) { s->failed_pc=0x0c0a82c0u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a82c2;
P_0c0a82c2: /* original 2fd6, guest PC 0x0c0a82c2 */
if(!s->budget--) { s->failed_pc=0x0c0a82c2u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a82c4;
P_0c0a82c4: /* original 2fc6, guest PC 0x0c0a82c4 */
if(!s->budget--) { s->failed_pc=0x0c0a82c4u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a82c6;
P_0c0a82c6: /* original d324, guest PC 0x0c0a82c6 */
if(!s->budget--) { s->failed_pc=0x0c0a82c6u; return 0; }
r[3]=read(ram,0x0c0a8358u,4);
goto P_0c0a82c8;
P_0c0a82c8: /* original 4f22, guest PC 0x0c0a82c8 */
if(!s->budget--) { s->failed_pc=0x0c0a82c8u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0a82ca;
P_0c0a82ca: /* original 6e32, guest PC 0x0c0a82ca */
if(!s->budget--) { s->failed_pc=0x0c0a82cau; return 0; }
tmp=read(ram,r[3],4);
r[14]=tmp;
goto P_0c0a82cc;
P_0c0a82cc: /* original d223, guest PC 0x0c0a82cc */
if(!s->budget--) { s->failed_pc=0x0c0a82ccu; return 0; }
r[2]=read(ram,0x0c0a835cu,4);
goto P_0c0a82ce;
P_0c0a82ce: /* original 61e2, guest PC 0x0c0a82ce */
if(!s->budget--) { s->failed_pc=0x0c0a82ceu; return 0; }
tmp=read(ram,r[14],4);
r[1]=tmp;
goto P_0c0a82d0;
P_0c0a82d0: /* original 4f12, guest PC 0x0c0a82d0 */
if(!s->budget--) { s->failed_pc=0x0c0a82d0u; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c0a82d2;
P_0c0a82d2: /* original 2128, guest PC 0x0c0a82d2 */
if(!s->budget--) { s->failed_pc=0x0c0a82d2u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[2])==0)!=0);
goto P_0c0a82d4;
P_0c0a82d4: /* original 8934, guest PC 0x0c0a82d4 */
if(!s->budget--) { s->failed_pc=0x0c0a82d4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a8340; }
goto P_0c0a82d6;
P_0c0a82d6: /* original 85eb, guest PC 0x0c0a82d6 */
if(!s->budget--) { s->failed_pc=0x0c0a82d6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+22,2);
goto P_0c0a82d8;
P_0c0a82d8: /* original ed34, guest PC 0x0c0a82d8 */
if(!s->budget--) { s->failed_pc=0x0c0a82d8u; return 0; }
r[13]=0x00000034u;
goto P_0c0a82da;
P_0c0a82da: /* original 61e3, guest PC 0x0c0a82da */
if(!s->budget--) { s->failed_pc=0x0c0a82dau; return 0; }
r[1]=r[14];
goto P_0c0a82dc;
P_0c0a82dc: /* original 711c, guest PC 0x0c0a82dc */
if(!s->budget--) { s->failed_pc=0x0c0a82dcu; return 0; }
r[1]+=0x0000001cu;
goto P_0c0a82de;
P_0c0a82de: /* original 20df, guest PC 0x0c0a82de */
if(!s->budget--) { s->failed_pc=0x0c0a82deu; return 0; }
r[19]=(uint32_t)((int32_t)(int16_t)r[0]*(int32_t)(int16_t)r[13]);
goto P_0c0a82e0;
P_0c0a82e0: /* original 0d1a, guest PC 0x0c0a82e0 */
if(!s->budget--) { s->failed_pc=0x0c0a82e0u; return 0; }
r[13]=r[19];
goto P_0c0a82e2;
P_0c0a82e2: /* original 6ddf, guest PC 0x0c0a82e2 */
if(!s->budget--) { s->failed_pc=0x0c0a82e2u; return 0; }
r[13]=(uint32_t)(int32_t)(int16_t)r[13];
goto P_0c0a82e4;
P_0c0a82e4: /* original 3d1c, guest PC 0x0c0a82e4 */
if(!s->budget--) { s->failed_pc=0x0c0a82e4u; return 0; }
r[13]+=r[1];
goto P_0c0a82e6;
P_0c0a82e6: /* original d11e, guest PC 0x0c0a82e6 */
if(!s->budget--) { s->failed_pc=0x0c0a82e6u; return 0; }
r[1]=read(ram,0x0c0a8360u,4);
goto P_0c0a82e8;
P_0c0a82e8: /* original 410b, guest PC 0x0c0a82e8 */
if(!s->budget--) { s->failed_pc=0x0c0a82e8u; return 0; }
target=r[1];
r[16]=code_base|0x0c0a82ecu;
r[4]=read(ram,r[13]+12,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a82ecu) { target=s->pc; goto dispatch; }
goto P_0c0a82ec;
P_0c0a82ea: /* original 54d3, guest PC 0x0c0a82ea */
if(!s->budget--) { s->failed_pc=0x0c0a82eau; return 0; }
r[4]=read(ram,r[13]+12,4);
goto P_0c0a82ec;
P_0c0a82ec: /* original dc1d, guest PC 0x0c0a82ec */
if(!s->budget--) { s->failed_pc=0x0c0a82ecu; return 0; }
r[12]=read(ram,0x0c0a8364u,4);
goto P_0c0a82ee;
P_0c0a82ee: /* original 4c0b, guest PC 0x0c0a82ee */
if(!s->budget--) { s->failed_pc=0x0c0a82eeu; return 0; }
target=r[12];
r[16]=code_base|0x0c0a82f2u;
r[4]=read(ram,r[13]+12,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a82f2u) { target=s->pc; goto dispatch; }
goto P_0c0a82f2;
P_0c0a82f0: /* original 54d3, guest PC 0x0c0a82f0 */
if(!s->budget--) { s->failed_pc=0x0c0a82f0u; return 0; }
r[4]=read(ram,r[13]+12,4);
goto P_0c0a82f2;
P_0c0a82f2: /* original 8802, guest PC 0x0c0a82f2 */
if(!s->budget--) { s->failed_pc=0x0c0a82f2u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c0a82f4;
P_0c0a82f4: /* original 8dfb, guest PC 0x0c0a82f4 */
if(!s->budget--) { s->failed_pc=0x0c0a82f4u; return 0; }
cond=r[17]&1u;
r[4]=r[0];
if(cond) { goto P_0c0a82ee; }
goto P_0c0a82f8;
P_0c0a82f6: /* original 6403, guest PC 0x0c0a82f6 */
if(!s->budget--) { s->failed_pc=0x0c0a82f6u; return 0; }
r[4]=r[0];
goto P_0c0a82f8;
P_0c0a82f8: /* original 53d5, guest PC 0x0c0a82f8 */
if(!s->budget--) { s->failed_pc=0x0c0a82f8u; return 0; }
r[3]=read(ram,r[13]+20,4);
goto P_0c0a82fa;
P_0c0a82fa: /* original 2338, guest PC 0x0c0a82fa */
if(!s->budget--) { s->failed_pc=0x0c0a82fau; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c0a82fc;
P_0c0a82fc: /* original 8904, guest PC 0x0c0a82fc */
if(!s->budget--) { s->failed_pc=0x0c0a82fcu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a8308; }
goto P_0c0a82fe;
P_0c0a82fe: /* original 53d5, guest PC 0x0c0a82fe */
if(!s->budget--) { s->failed_pc=0x0c0a82feu; return 0; }
r[3]=read(ram,r[13]+20,4);
goto P_0c0a8300;
P_0c0a8300: /* original e5ff, guest PC 0x0c0a8300 */
if(!s->budget--) { s->failed_pc=0x0c0a8300u; return 0; }
r[5]=0xffffffffu;
goto P_0c0a8302;
P_0c0a8302: /* original 430b, guest PC 0x0c0a8302 */
if(!s->budget--) { s->failed_pc=0x0c0a8302u; return 0; }
target=r[3];
r[16]=code_base|0x0c0a8306u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a8306u) { target=s->pc; goto dispatch; }
goto P_0c0a8306;
P_0c0a8304: /* original 64d3, guest PC 0x0c0a8304 */
if(!s->budget--) { s->failed_pc=0x0c0a8304u; return 0; }
r[4]=r[13];
goto P_0c0a8306;
P_0c0a8306: /* original 2008, guest PC 0x0c0a8306 */
if(!s->budget--) { s->failed_pc=0x0c0a8306u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c0a8308;
P_0c0a8308: /* original d317, guest PC 0x0c0a8308 */
if(!s->budget--) { s->failed_pc=0x0c0a8308u; return 0; }
r[3]=read(ram,0x0c0a8368u,4);
goto P_0c0a830a;
P_0c0a830a: /* original 430b, guest PC 0x0c0a830a */
if(!s->budget--) { s->failed_pc=0x0c0a830au; return 0; }
target=r[3];
r[16]=code_base|0x0c0a830eu;
r[4]=read(ram,r[13]+12,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a830eu) { target=s->pc; goto dispatch; }
goto P_0c0a830e;
P_0c0a830c: /* original 54d3, guest PC 0x0c0a830c */
if(!s->budget--) { s->failed_pc=0x0c0a830cu; return 0; }
r[4]=read(ram,r[13]+12,4);
goto P_0c0a830e;
P_0c0a830e: /* original 62e2, guest PC 0x0c0a830e */
if(!s->budget--) { s->failed_pc=0x0c0a830eu; return 0; }
tmp=read(ram,r[14],4);
r[2]=tmp;
goto P_0c0a8310;
P_0c0a8310: /* original d316, guest PC 0x0c0a8310 */
if(!s->budget--) { s->failed_pc=0x0c0a8310u; return 0; }
r[3]=read(ram,0x0c0a836cu,4);
goto P_0c0a8312;
P_0c0a8312: /* original 2239, guest PC 0x0c0a8312 */
if(!s->budget--) { s->failed_pc=0x0c0a8312u; return 0; }
r[2]&=r[3];
goto P_0c0a8314;
P_0c0a8314: /* original a014, guest PC 0x0c0a8314 */
if(!s->budget--) { s->failed_pc=0x0c0a8314u; return 0; }
write(ram,r[14],r[2],4);
goto P_0c0a8340;
P_0c0a8316: /* original 2e22, guest PC 0x0c0a8316 */
if(!s->budget--) { s->failed_pc=0x0c0a8316u; return 0; }
write(ram,r[14],r[2],4);
goto P_0c0a8318;
P_0c0a8318: /* original 85eb, guest PC 0x0c0a8318 */
if(!s->budget--) { s->failed_pc=0x0c0a8318u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+22,2);
goto P_0c0a831a;
P_0c0a831a: /* original ed34, guest PC 0x0c0a831a */
if(!s->budget--) { s->failed_pc=0x0c0a831au; return 0; }
r[13]=0x00000034u;
goto P_0c0a831c;
P_0c0a831c: /* original 63e3, guest PC 0x0c0a831c */
if(!s->budget--) { s->failed_pc=0x0c0a831cu; return 0; }
r[3]=r[14];
goto P_0c0a831e;
P_0c0a831e: /* original 731c, guest PC 0x0c0a831e */
if(!s->budget--) { s->failed_pc=0x0c0a831eu; return 0; }
r[3]+=0x0000001cu;
goto P_0c0a8320;
P_0c0a8320: /* original 7001, guest PC 0x0c0a8320 */
if(!s->budget--) { s->failed_pc=0x0c0a8320u; return 0; }
r[0]+=0x00000001u;
goto P_0c0a8322;
P_0c0a8322: /* original c91f, guest PC 0x0c0a8322 */
if(!s->budget--) { s->failed_pc=0x0c0a8322u; return 0; }
r[0]&=31u;
goto P_0c0a8324;
P_0c0a8324: /* original 81eb, guest PC 0x0c0a8324 */
if(!s->budget--) { s->failed_pc=0x0c0a8324u; return 0; }
write(ram,r[14]+22,r[0],2);
goto P_0c0a8326;
P_0c0a8326: /* original 85eb, guest PC 0x0c0a8326 */
if(!s->budget--) { s->failed_pc=0x0c0a8326u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+22,2);
goto P_0c0a8328;
P_0c0a8328: /* original 20df, guest PC 0x0c0a8328 */
if(!s->budget--) { s->failed_pc=0x0c0a8328u; return 0; }
r[19]=(uint32_t)((int32_t)(int16_t)r[0]*(int32_t)(int16_t)r[13]);
goto P_0c0a832a;
P_0c0a832a: /* original 0d1a, guest PC 0x0c0a832a */
if(!s->budget--) { s->failed_pc=0x0c0a832au; return 0; }
r[13]=r[19];
goto P_0c0a832c;
P_0c0a832c: /* original 6ddf, guest PC 0x0c0a832c */
if(!s->budget--) { s->failed_pc=0x0c0a832cu; return 0; }
r[13]=(uint32_t)(int32_t)(int16_t)r[13];
goto P_0c0a832e;
P_0c0a832e: /* original 3d3c, guest PC 0x0c0a832e */
if(!s->budget--) { s->failed_pc=0x0c0a832eu; return 0; }
r[13]+=r[3];
goto P_0c0a8330;
P_0c0a8330: /* original 52d5, guest PC 0x0c0a8330 */
if(!s->budget--) { s->failed_pc=0x0c0a8330u; return 0; }
r[2]=read(ram,r[13]+20,4);
goto P_0c0a8332;
P_0c0a8332: /* original 2228, guest PC 0x0c0a8332 */
if(!s->budget--) { s->failed_pc=0x0c0a8332u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c0a8334;
P_0c0a8334: /* original 8904, guest PC 0x0c0a8334 */
if(!s->budget--) { s->failed_pc=0x0c0a8334u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a8340; }
goto P_0c0a8336;
P_0c0a8336: /* original 52d5, guest PC 0x0c0a8336 */
if(!s->budget--) { s->failed_pc=0x0c0a8336u; return 0; }
r[2]=read(ram,r[13]+20,4);
goto P_0c0a8338;
P_0c0a8338: /* original e5ff, guest PC 0x0c0a8338 */
if(!s->budget--) { s->failed_pc=0x0c0a8338u; return 0; }
r[5]=0xffffffffu;
goto P_0c0a833a;
P_0c0a833a: /* original 420b, guest PC 0x0c0a833a */
if(!s->budget--) { s->failed_pc=0x0c0a833au; return 0; }
target=r[2];
r[16]=code_base|0x0c0a833eu;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a833eu) { target=s->pc; goto dispatch; }
goto P_0c0a833e;
P_0c0a833c: /* original 64d3, guest PC 0x0c0a833c */
if(!s->budget--) { s->failed_pc=0x0c0a833cu; return 0; }
r[4]=r[13];
goto P_0c0a833e;
P_0c0a833e: /* original 2008, guest PC 0x0c0a833e */
if(!s->budget--) { s->failed_pc=0x0c0a833eu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c0a8340;
P_0c0a8340: /* original 85eb, guest PC 0x0c0a8340 */
if(!s->budget--) { s->failed_pc=0x0c0a8340u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+22,2);
goto P_0c0a8342;
P_0c0a8342: /* original 6303, guest PC 0x0c0a8342 */
if(!s->budget--) { s->failed_pc=0x0c0a8342u; return 0; }
r[3]=r[0];
goto P_0c0a8344;
P_0c0a8344: /* original 85ed, guest PC 0x0c0a8344 */
if(!s->budget--) { s->failed_pc=0x0c0a8344u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+26,2);
goto P_0c0a8346;
P_0c0a8346: /* original 3300, guest PC 0x0c0a8346 */
if(!s->budget--) { s->failed_pc=0x0c0a8346u; return 0; }
r[17]=(r[17]&~1u)|((r[3]==r[0])!=0);
goto P_0c0a8348;
P_0c0a8348: /* original 8be6, guest PC 0x0c0a8348 */
if(!s->budget--) { s->failed_pc=0x0c0a8348u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a8318; }
goto P_0c0a834a;
P_0c0a834a: /* original 4f16, guest PC 0x0c0a834a */
if(!s->budget--) { s->failed_pc=0x0c0a834au; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a834c;
P_0c0a834c: /* original 4f26, guest PC 0x0c0a834c */
if(!s->budget--) { s->failed_pc=0x0c0a834cu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a834e;
P_0c0a834e: /* original 6cf6, guest PC 0x0c0a834e */
if(!s->budget--) { s->failed_pc=0x0c0a834eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0a8350;
P_0c0a8350: /* original 6df6, guest PC 0x0c0a8350 */
if(!s->budget--) { s->failed_pc=0x0c0a8350u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0a8352;
P_0c0a8352: /* original 000b, guest PC 0x0c0a8352 */
if(!s->budget--) { s->failed_pc=0x0c0a8352u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0a8354: /* original 6ef6, guest PC 0x0c0a8354 */
if(!s->budget--) { s->failed_pc=0x0c0a8354u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0a8356u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0a8356u; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
