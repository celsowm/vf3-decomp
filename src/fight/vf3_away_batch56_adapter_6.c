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
int vf3_away_batch56_adapter_6(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c089f8eu: goto P_0c089f8e;
case 0x0c089f90u: goto P_0c089f90;
case 0x0c089f92u: goto P_0c089f92;
case 0x0c089f94u: goto P_0c089f94;
case 0x0c089f96u: goto P_0c089f96;
case 0x0c089f98u: goto P_0c089f98;
case 0x0c089f9au: goto P_0c089f9a;
case 0x0c089f9cu: goto P_0c089f9c;
case 0x0c089f9eu: goto P_0c089f9e;
case 0x0c089fa0u: goto P_0c089fa0;
case 0x0c089fa2u: goto P_0c089fa2;
case 0x0c089fa4u: goto P_0c089fa4;
case 0x0c089fa6u: goto P_0c089fa6;
case 0x0c089fa8u: goto P_0c089fa8;
case 0x0c089faau: goto P_0c089faa;
case 0x0c089facu: goto P_0c089fac;
case 0x0c089faeu: goto P_0c089fae;
case 0x0c089fb0u: goto P_0c089fb0;
case 0x0c089fb2u: goto P_0c089fb2;
case 0x0c089fb4u: goto P_0c089fb4;
case 0x0c089fb6u: goto P_0c089fb6;
case 0x0c089fb8u: goto P_0c089fb8;
case 0x0c089fbau: goto P_0c089fba;
case 0x0c089fbcu: goto P_0c089fbc;
case 0x0c089fbeu: goto P_0c089fbe;
case 0x0c089fc0u: goto P_0c089fc0;
case 0x0c089fc2u: goto P_0c089fc2;
case 0x0c089fc4u: goto P_0c089fc4;
case 0x0c089fc6u: goto P_0c089fc6;
case 0x0c089fc8u: goto P_0c089fc8;
case 0x0c089fcau: goto P_0c089fca;
case 0x0c089fccu: goto P_0c089fcc;
case 0x0c089fceu: goto P_0c089fce;
case 0x0c089fd0u: goto P_0c089fd0;
case 0x0c089fd2u: goto P_0c089fd2;
case 0x0c089fd4u: goto P_0c089fd4;
case 0x0c089fd6u: goto P_0c089fd6;
case 0x0c089fd8u: goto P_0c089fd8;
case 0x0c089fdau: goto P_0c089fda;
case 0x0c089fdcu: goto P_0c089fdc;
case 0x0c089fdeu: goto P_0c089fde;
case 0x0c089fe0u: goto P_0c089fe0;
case 0x0c089fe2u: goto P_0c089fe2;
case 0x0c089fe4u: goto P_0c089fe4;
case 0x0c089fe6u: goto P_0c089fe6;
case 0x0c089fe8u: goto P_0c089fe8;
case 0x0c089feau: goto P_0c089fea;
case 0x0c089fecu: goto P_0c089fec;
case 0x0c089feeu: goto P_0c089fee;
case 0x0c089ff0u: goto P_0c089ff0;
case 0x0c089ff2u: goto P_0c089ff2;
case 0x0c089ff4u: goto P_0c089ff4;
case 0x0c089ff6u: goto P_0c089ff6;
case 0x0c089ff8u: goto P_0c089ff8;
case 0x0c089ffau: goto P_0c089ffa;
case 0x0c089ffcu: goto P_0c089ffc;
case 0x0c089ffeu: goto P_0c089ffe;
case 0x0c08a000u: goto P_0c08a000;
case 0x0c08a002u: goto P_0c08a002;
case 0x0c08a004u: goto P_0c08a004;
case 0x0c08a006u: goto P_0c08a006;
case 0x0c08a008u: goto P_0c08a008;
case 0x0c08a00au: goto P_0c08a00a;
case 0x0c08a00cu: goto P_0c08a00c;
case 0x0c08a00eu: goto P_0c08a00e;
case 0x0c08a010u: goto P_0c08a010;
case 0x0c08a012u: goto P_0c08a012;
case 0x0c08a014u: goto P_0c08a014;
case 0x0c08a016u: goto P_0c08a016;
case 0x0c08a018u: goto P_0c08a018;
case 0x0c08a01au: goto P_0c08a01a;
case 0x0c08a01cu: goto P_0c08a01c;
case 0x0c08a01eu: goto P_0c08a01e;
case 0x0c08a020u: goto P_0c08a020;
case 0x0c08a022u: goto P_0c08a022;
case 0x0c08a024u: goto P_0c08a024;
case 0x0c08a026u: goto P_0c08a026;
case 0x0c08a028u: goto P_0c08a028;
case 0x0c08a02au: goto P_0c08a02a;
case 0x0c08a02cu: goto P_0c08a02c;
case 0x0c08a02eu: goto P_0c08a02e;
case 0x0c08a030u: goto P_0c08a030;
case 0x0c08a032u: goto P_0c08a032;
case 0x0c08a034u: goto P_0c08a034;
case 0x0c08a036u: goto P_0c08a036;
case 0x0c08a038u: goto P_0c08a038;
case 0x0c08a03au: goto P_0c08a03a;
case 0x0c08a03cu: goto P_0c08a03c;
case 0x0c08a03eu: goto P_0c08a03e;
case 0x0c08a040u: goto P_0c08a040;
case 0x0c08a042u: goto P_0c08a042;
case 0x0c08a044u: goto P_0c08a044;
case 0x0c0a7662u: goto P_0c0a7662;
case 0x0c0a7664u: goto P_0c0a7664;
case 0x0c0a7666u: goto P_0c0a7666;
case 0x0c0a7668u: goto P_0c0a7668;
case 0x0c0a766au: goto P_0c0a766a;
case 0x0c0a766cu: goto P_0c0a766c;
case 0x0c0a766eu: goto P_0c0a766e;
case 0x0c0a7670u: goto P_0c0a7670;
case 0x0c0a7672u: goto P_0c0a7672;
case 0x0c0a7674u: goto P_0c0a7674;
case 0x0c0a7676u: goto P_0c0a7676;
case 0x0c0a7678u: goto P_0c0a7678;
case 0x0c0a767au: goto P_0c0a767a;
case 0x0c0a767cu: goto P_0c0a767c;
case 0x0c0a767eu: goto P_0c0a767e;
case 0x0c0a7680u: goto P_0c0a7680;
case 0x0c0a7682u: goto P_0c0a7682;
case 0x0c0a7684u: goto P_0c0a7684;
case 0x0c0a7686u: goto P_0c0a7686;
case 0x0c0a7688u: goto P_0c0a7688;
case 0x0c0a768au: goto P_0c0a768a;
case 0x0c0a768cu: goto P_0c0a768c;
case 0x0c0a768eu: goto P_0c0a768e;
case 0x0c0a7690u: goto P_0c0a7690;
case 0x0c0a7692u: goto P_0c0a7692;
case 0x0c0a7694u: goto P_0c0a7694;
case 0x0c0a7696u: goto P_0c0a7696;
case 0x0c0a7698u: goto P_0c0a7698;
case 0x0c0a769au: goto P_0c0a769a;
case 0x0c0a769cu: goto P_0c0a769c;
case 0x0c0a769eu: goto P_0c0a769e;
case 0x0c0a76a0u: goto P_0c0a76a0;
case 0x0c0a76a2u: goto P_0c0a76a2;
case 0x0c0a76a4u: goto P_0c0a76a4;
case 0x0c0a76a6u: goto P_0c0a76a6;
case 0x0c0a76a8u: goto P_0c0a76a8;
case 0x0c0a76aau: goto P_0c0a76aa;
case 0x0c0a76acu: goto P_0c0a76ac;
case 0x0c0a76aeu: goto P_0c0a76ae;
case 0x0c0a76b0u: goto P_0c0a76b0;
case 0x0c0a76b2u: goto P_0c0a76b2;
case 0x0c0a76b4u: goto P_0c0a76b4;
case 0x0c0a76b6u: goto P_0c0a76b6;
case 0x0c0a76b8u: goto P_0c0a76b8;
case 0x0c0a76bau: goto P_0c0a76ba;
case 0x0c0a76bcu: goto P_0c0a76bc;
default: return vf3_matrix_family(target,s,ram);
}
P_0c089f8e: /* original 2fe6, guest PC 0x0c089f8e */
if(!s->budget--) { s->failed_pc=0x0c089f8eu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c089f90;
P_0c089f90: /* original 6e43, guest PC 0x0c089f90 */
if(!s->budget--) { s->failed_pc=0x0c089f90u; return 0; }
r[14]=r[4];
goto P_0c089f92;
P_0c089f92: /* original 2fd6, guest PC 0x0c089f92 */
if(!s->budget--) { s->failed_pc=0x0c089f92u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c089f94;
P_0c089f94: /* original 7e14, guest PC 0x0c089f94 */
if(!s->budget--) { s->failed_pc=0x0c089f94u; return 0; }
r[14]+=0x00000014u;
goto P_0c089f96;
P_0c089f96: /* original 2fc6, guest PC 0x0c089f96 */
if(!s->budget--) { s->failed_pc=0x0c089f96u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c089f98;
P_0c089f98: /* original 2fb6, guest PC 0x0c089f98 */
if(!s->budget--) { s->failed_pc=0x0c089f98u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c089f9a;
P_0c089f9a: /* original 2fa6, guest PC 0x0c089f9a */
if(!s->budget--) { s->failed_pc=0x0c089f9au; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c089f9c;
P_0c089f9c: /* original 2f96, guest PC 0x0c089f9c */
if(!s->budget--) { s->failed_pc=0x0c089f9cu; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c089f9e;
P_0c089f9e: /* original 2f86, guest PC 0x0c089f9e */
if(!s->budget--) { s->failed_pc=0x0c089f9eu; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c089fa0;
P_0c089fa0: /* original fffb, guest PC 0x0c089fa0 */
if(!s->budget--) { s->failed_pc=0x0c089fa0u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c089fa2;
P_0c089fa2: /* original ffeb, guest PC 0x0c089fa2 */
if(!s->budget--) { s->failed_pc=0x0c089fa2u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,14,r[15]);
goto P_0c089fa4;
P_0c089fa4: /* original ffdb, guest PC 0x0c089fa4 */
if(!s->budget--) { s->failed_pc=0x0c089fa4u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,13,r[15]);
goto P_0c089fa6;
P_0c089fa6: /* original ffcb, guest PC 0x0c089fa6 */
if(!s->budget--) { s->failed_pc=0x0c089fa6u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,12,r[15]);
goto P_0c089fa8;
P_0c089fa8: /* original 4f22, guest PC 0x0c089fa8 */
if(!s->budget--) { s->failed_pc=0x0c089fa8u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c089faa;
P_0c089faa: /* original d327, guest PC 0x0c089faa */
if(!s->budget--) { s->failed_pc=0x0c089faau; return 0; }
r[3]=read(ram,0x0c08a048u,4);
goto P_0c089fac;
P_0c089fac: /* original 7ff4, guest PC 0x0c089fac */
if(!s->budget--) { s->failed_pc=0x0c089facu; return 0; }
r[15]+=0xfffffff4u;
goto P_0c089fae;
P_0c089fae: /* original 430b, guest PC 0x0c089fae */
if(!s->budget--) { s->failed_pc=0x0c089faeu; return 0; }
target=r[3];
r[16]=code_base|0x0c089fb2u;
r[4]=0x00000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c089fb2u) { target=s->pc; goto dispatch; }
goto P_0c089fb2;
P_0c089fb0: /* original e400, guest PC 0x0c089fb0 */
if(!s->budget--) { s->failed_pc=0x0c089fb0u; return 0; }
r[4]=0x00000000u;
goto P_0c089fb2;
P_0c089fb2: /* original dd28, guest PC 0x0c089fb2 */
if(!s->budget--) { s->failed_pc=0x0c089fb2u; return 0; }
r[13]=read(ram,0x0c08a054u,4);
goto P_0c089fb4;
P_0c089fb4: /* original ec02, guest PC 0x0c089fb4 */
if(!s->budget--) { s->failed_pc=0x0c089fb4u; return 0; }
r[12]=0x00000002u;
goto P_0c089fb6;
P_0c089fb6: /* original d926, guest PC 0x0c089fb6 */
if(!s->budget--) { s->failed_pc=0x0c089fb6u; return 0; }
r[9]=read(ram,0x0c08a050u,4);
goto P_0c089fb8;
P_0c089fb8: /* original d824, guest PC 0x0c089fb8 */
if(!s->budget--) { s->failed_pc=0x0c089fb8u; return 0; }
r[8]=read(ram,0x0c08a04cu,4);
goto P_0c089fba;
P_0c089fba: /* original ff9d, guest PC 0x0c089fba */
if(!s->budget--) { s->failed_pc=0x0c089fbau; return 0; }
fr[15]=0x3f800000u;
goto P_0c089fbc;
P_0c089fbc: /* original e02e, guest PC 0x0c089fbc */
if(!s->budget--) { s->failed_pc=0x0c089fbcu; return 0; }
r[0]=0x0000002eu;
goto P_0c089fbe;
P_0c089fbe: /* original f3e8, guest PC 0x0c089fbe */
if(!s->budget--) { s->failed_pc=0x0c089fbeu; return 0; }
vf3_matrix_load(s,ram,3,r[14]);
goto P_0c089fc0;
P_0c089fc0: /* original 0aed, guest PC 0x0c089fc0 */
if(!s->budget--) { s->failed_pc=0x0c089fc0u; return 0; }
r[10]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c089fc2;
P_0c089fc2: /* original e028, guest PC 0x0c089fc2 */
if(!s->budget--) { s->failed_pc=0x0c089fc2u; return 0; }
r[0]=0x00000028u;
goto P_0c089fc4;
P_0c089fc4: /* original 0bed, guest PC 0x0c089fc4 */
if(!s->budget--) { s->failed_pc=0x0c089fc4u; return 0; }
r[11]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c089fc6;
P_0c089fc6: /* original e008, guest PC 0x0c089fc6 */
if(!s->budget--) { s->failed_pc=0x0c089fc6u; return 0; }
r[0]=0x00000008u;
goto P_0c089fc8;
P_0c089fc8: /* original ff37, guest PC 0x0c089fc8 */
if(!s->budget--) { s->failed_pc=0x0c089fc8u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c089fca;
P_0c089fca: /* original e004, guest PC 0x0c089fca */
if(!s->budget--) { s->failed_pc=0x0c089fcau; return 0; }
r[0]=0x00000004u;
goto P_0c089fcc;
P_0c089fcc: /* original fce6, guest PC 0x0c089fcc */
if(!s->budget--) { s->failed_pc=0x0c089fccu; return 0; }
vf3_matrix_load(s,ram,12,r[14]+r[0]);
goto P_0c089fce;
P_0c089fce: /* original e008, guest PC 0x0c089fce */
if(!s->budget--) { s->failed_pc=0x0c089fceu; return 0; }
r[0]=0x00000008u;
goto P_0c089fd0;
P_0c089fd0: /* original f3e6, guest PC 0x0c089fd0 */
if(!s->budget--) { s->failed_pc=0x0c089fd0u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c089fd2;
P_0c089fd2: /* original e00c, guest PC 0x0c089fd2 */
if(!s->budget--) { s->failed_pc=0x0c089fd2u; return 0; }
r[0]=0x0000000cu;
goto P_0c089fd4;
P_0c089fd4: /* original f3f2, guest PC 0x0c089fd4 */
if(!s->budget--) { s->failed_pc=0x0c089fd4u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[15],r[18],'*');
goto P_0c089fd6;
P_0c089fd6: /* original fd3c, guest PC 0x0c089fd6 */
if(!s->budget--) { s->failed_pc=0x0c089fd6u; return 0; }
vf3_matrix_move(s,13,3);
goto P_0c089fd8;
P_0c089fd8: /* original f3e6, guest PC 0x0c089fd8 */
if(!s->budget--) { s->failed_pc=0x0c089fd8u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c089fda;
P_0c089fda: /* original e004, guest PC 0x0c089fda */
if(!s->budget--) { s->failed_pc=0x0c089fdau; return 0; }
r[0]=0x00000004u;
goto P_0c089fdc;
P_0c089fdc: /* original fd4d, guest PC 0x0c089fdc */
if(!s->budget--) { s->failed_pc=0x0c089fdcu; return 0; }
fr[13]^=0x80000000u;
goto P_0c089fde;
P_0c089fde: /* original ff37, guest PC 0x0c089fde */
if(!s->budget--) { s->failed_pc=0x0c089fdeu; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c089fe0;
P_0c089fe0: /* original e010, guest PC 0x0c089fe0 */
if(!s->budget--) { s->failed_pc=0x0c089fe0u; return 0; }
r[0]=0x00000010u;
goto P_0c089fe2;
P_0c089fe2: /* original f3e6, guest PC 0x0c089fe2 */
if(!s->budget--) { s->failed_pc=0x0c089fe2u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c089fe4;
P_0c089fe4: /* original e014, guest PC 0x0c089fe4 */
if(!s->budget--) { s->failed_pc=0x0c089fe4u; return 0; }
r[0]=0x00000014u;
goto P_0c089fe6;
P_0c089fe6: /* original ff3a, guest PC 0x0c089fe6 */
if(!s->budget--) { s->failed_pc=0x0c089fe6u; return 0; }
vf3_matrix_store(s,ram,3,r[15]);
goto P_0c089fe8;
P_0c089fe8: /* original f3e6, guest PC 0x0c089fe8 */
if(!s->budget--) { s->failed_pc=0x0c089fe8u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c089fea;
P_0c089fea: /* original f3f2, guest PC 0x0c089fea */
if(!s->budget--) { s->failed_pc=0x0c089feau; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[15],r[18],'*');
goto P_0c089fec;
P_0c089fec: /* original fe3c, guest PC 0x0c089fec */
if(!s->budget--) { s->failed_pc=0x0c089fecu; return 0; }
vf3_matrix_move(s,14,3);
goto P_0c089fee;
P_0c089fee: /* original 490b, guest PC 0x0c089fee */
if(!s->budget--) { s->failed_pc=0x0c089feeu; return 0; }
target=r[9];
r[16]=code_base|0x0c089ff2u;
fr[14]^=0x80000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c089ff2u) { target=s->pc; goto dispatch; }
goto P_0c089ff2;
P_0c089ff0: /* original fe4d, guest PC 0x0c089ff0 */
if(!s->budget--) { s->failed_pc=0x0c089ff0u; return 0; }
fr[14]^=0x80000000u;
goto P_0c089ff2;
P_0c089ff2: /* original f5f8, guest PC 0x0c089ff2 */
if(!s->budget--) { s->failed_pc=0x0c089ff2u; return 0; }
vf3_matrix_load(s,ram,5,r[15]);
goto P_0c089ff4;
P_0c089ff4: /* original e004, guest PC 0x0c089ff4 */
if(!s->budget--) { s->failed_pc=0x0c089ff4u; return 0; }
r[0]=0x00000004u;
goto P_0c089ff6;
P_0c089ff6: /* original f6ec, guest PC 0x0c089ff6 */
if(!s->budget--) { s->failed_pc=0x0c089ff6u; return 0; }
vf3_matrix_move(s,6,14);
goto P_0c089ff8;
P_0c089ff8: /* original 4d0b, guest PC 0x0c089ff8 */
if(!s->budget--) { s->failed_pc=0x0c089ff8u; return 0; }
target=r[13];
r[16]=code_base|0x0c089ffcu;
vf3_matrix_load(s,ram,4,r[15]+r[0]);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c089ffcu) { target=s->pc; goto dispatch; }
goto P_0c089ffc;
P_0c089ffa: /* original f4f6, guest PC 0x0c089ffa */
if(!s->budget--) { s->failed_pc=0x0c089ffau; return 0; }
vf3_matrix_load(s,ram,4,r[15]+r[0]);
goto P_0c089ffc;
P_0c089ffc: /* original 480b, guest PC 0x0c089ffc */
if(!s->budget--) { s->failed_pc=0x0c089ffcu; return 0; }
target=r[8];
r[16]=code_base|0x0c08a000u;
r[4]=r[11];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08a000u) { target=s->pc; goto dispatch; }
goto P_0c08a000;
P_0c089ffe: /* original 64b3, guest PC 0x0c089ffe */
if(!s->budget--) { s->failed_pc=0x0c089ffeu; return 0; }
r[4]=r[11];
goto P_0c08a000;
P_0c08a000: /* original e008, guest PC 0x0c08a000 */
if(!s->budget--) { s->failed_pc=0x0c08a000u; return 0; }
r[0]=0x00000008u;
goto P_0c08a002;
P_0c08a002: /* original f5cc, guest PC 0x0c08a002 */
if(!s->budget--) { s->failed_pc=0x0c08a002u; return 0; }
vf3_matrix_move(s,5,12);
goto P_0c08a004;
P_0c08a004: /* original f6dc, guest PC 0x0c08a004 */
if(!s->budget--) { s->failed_pc=0x0c08a004u; return 0; }
vf3_matrix_move(s,6,13);
goto P_0c08a006;
P_0c08a006: /* original 4d0b, guest PC 0x0c08a006 */
if(!s->budget--) { s->failed_pc=0x0c08a006u; return 0; }
target=r[13];
r[16]=code_base|0x0c08a00au;
vf3_matrix_load(s,ram,4,r[15]+r[0]);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08a00au) { target=s->pc; goto dispatch; }
goto P_0c08a00a;
P_0c08a008: /* original f4f6, guest PC 0x0c08a008 */
if(!s->budget--) { s->failed_pc=0x0c08a008u; return 0; }
vf3_matrix_load(s,ram,4,r[15]+r[0]);
goto P_0c08a00a;
P_0c08a00a: /* original d313, guest PC 0x0c08a00a */
if(!s->budget--) { s->failed_pc=0x0c08a00au; return 0; }
r[3]=read(ram,0x0c08a058u,4);
goto P_0c08a00c;
P_0c08a00c: /* original e034, guest PC 0x0c08a00c */
if(!s->budget--) { s->failed_pc=0x0c08a00cu; return 0; }
r[0]=0x00000034u;
goto P_0c08a00e;
P_0c08a00e: /* original 430b, guest PC 0x0c08a00e */
if(!s->budget--) { s->failed_pc=0x0c08a00eu; return 0; }
target=r[3];
r[16]=code_base|0x0c08a012u;
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08a012u) { target=s->pc; goto dispatch; }
goto P_0c08a012;
P_0c08a010: /* original 04ed, guest PC 0x0c08a010 */
if(!s->budget--) { s->failed_pc=0x0c08a010u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c08a012;
P_0c08a012: /* original d312, guest PC 0x0c08a012 */
if(!s->budget--) { s->failed_pc=0x0c08a012u; return 0; }
r[3]=read(ram,0x0c08a05cu,4);
goto P_0c08a014;
P_0c08a014: /* original e036, guest PC 0x0c08a014 */
if(!s->budget--) { s->failed_pc=0x0c08a014u; return 0; }
r[0]=0x00000036u;
goto P_0c08a016;
P_0c08a016: /* original 430b, guest PC 0x0c08a016 */
if(!s->budget--) { s->failed_pc=0x0c08a016u; return 0; }
target=r[3];
r[16]=code_base|0x0c08a01au;
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08a01au) { target=s->pc; goto dispatch; }
goto P_0c08a01a;
P_0c08a018: /* original 04ed, guest PC 0x0c08a018 */
if(!s->budget--) { s->failed_pc=0x0c08a018u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c08a01a;
P_0c08a01a: /* original d211, guest PC 0x0c08a01a */
if(!s->budget--) { s->failed_pc=0x0c08a01au; return 0; }
r[2]=read(ram,0x0c08a060u,4);
goto P_0c08a01c;
P_0c08a01c: /* original 420b, guest PC 0x0c08a01c */
if(!s->budget--) { s->failed_pc=0x0c08a01cu; return 0; }
target=r[2];
r[16]=code_base|0x0c08a020u;
r[4]=(uint32_t)(int32_t)(int16_t)r[10];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08a020u) { target=s->pc; goto dispatch; }
goto P_0c08a020;
P_0c08a01e: /* original 64af, guest PC 0x0c08a01e */
if(!s->budget--) { s->failed_pc=0x0c08a01eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)r[10];
goto P_0c08a020;
P_0c08a020: /* original 4c10, guest PC 0x0c08a020 */
if(!s->budget--) { s->failed_pc=0x0c08a020u; return 0; }
--r[12];
r[17]=(r[17]&~1u)|((r[12]==0)!=0);
goto P_0c08a022;
P_0c08a022: /* original 8fcb, guest PC 0x0c08a022 */
if(!s->budget--) { s->failed_pc=0x0c08a022u; return 0; }
cond=r[17]&1u;
r[14]+=0x0000003cu;
if(!cond) { goto P_0c089fbc; }
goto P_0c08a026;
P_0c08a024: /* original 7e3c, guest PC 0x0c08a024 */
if(!s->budget--) { s->failed_pc=0x0c08a024u; return 0; }
r[14]+=0x0000003cu;
goto P_0c08a026;
P_0c08a026: /* original 7f0c, guest PC 0x0c08a026 */
if(!s->budget--) { s->failed_pc=0x0c08a026u; return 0; }
r[15]+=0x0000000cu;
goto P_0c08a028;
P_0c08a028: /* original d20e, guest PC 0x0c08a028 */
if(!s->budget--) { s->failed_pc=0x0c08a028u; return 0; }
r[2]=read(ram,0x0c08a064u,4);
goto P_0c08a02a;
P_0c08a02a: /* original 4f26, guest PC 0x0c08a02a */
if(!s->budget--) { s->failed_pc=0x0c08a02au; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c08a02c;
P_0c08a02c: /* original e401, guest PC 0x0c08a02c */
if(!s->budget--) { s->failed_pc=0x0c08a02cu; return 0; }
r[4]=0x00000001u;
goto P_0c08a02e;
P_0c08a02e: /* original fcf9, guest PC 0x0c08a02e */
if(!s->budget--) { s->failed_pc=0x0c08a02eu; return 0; }
vf3_matrix_load(s,ram,12,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c08a030;
P_0c08a030: /* original fdf9, guest PC 0x0c08a030 */
if(!s->budget--) { s->failed_pc=0x0c08a030u; return 0; }
vf3_matrix_load(s,ram,13,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c08a032;
P_0c08a032: /* original fef9, guest PC 0x0c08a032 */
if(!s->budget--) { s->failed_pc=0x0c08a032u; return 0; }
vf3_matrix_load(s,ram,14,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c08a034;
P_0c08a034: /* original fff9, guest PC 0x0c08a034 */
if(!s->budget--) { s->failed_pc=0x0c08a034u; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c08a036;
P_0c08a036: /* original 68f6, guest PC 0x0c08a036 */
if(!s->budget--) { s->failed_pc=0x0c08a036u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c08a038;
P_0c08a038: /* original 69f6, guest PC 0x0c08a038 */
if(!s->budget--) { s->failed_pc=0x0c08a038u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c08a03a;
P_0c08a03a: /* original 6af6, guest PC 0x0c08a03a */
if(!s->budget--) { s->failed_pc=0x0c08a03au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c08a03c;
P_0c08a03c: /* original 6bf6, guest PC 0x0c08a03c */
if(!s->budget--) { s->failed_pc=0x0c08a03cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c08a03e;
P_0c08a03e: /* original 6cf6, guest PC 0x0c08a03e */
if(!s->budget--) { s->failed_pc=0x0c08a03eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c08a040;
P_0c08a040: /* original 6df6, guest PC 0x0c08a040 */
if(!s->budget--) { s->failed_pc=0x0c08a040u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c08a042;
P_0c08a042: /* original 422b, guest PC 0x0c08a042 */
if(!s->budget--) { s->failed_pc=0x0c08a042u; return 0; }
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
P_0c08a044: /* original 6ef6, guest PC 0x0c08a044 */
if(!s->budget--) { s->failed_pc=0x0c08a044u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c08a046u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c08a046u; return 0; } return 1;
P_0c0a7662: /* original 2fe6, guest PC 0x0c0a7662 */
if(!s->budget--) { s->failed_pc=0x0c0a7662u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a7664;
P_0c0a7664: /* original 932b, guest PC 0x0c0a7664 */
if(!s->budget--) { s->failed_pc=0x0c0a7664u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a76beu,2);
goto P_0c0a7666;
P_0c0a7666: /* original 4f22, guest PC 0x0c0a7666 */
if(!s->budget--) { s->failed_pc=0x0c0a7666u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0a7668;
P_0c0a7668: /* original 3433, guest PC 0x0c0a7668 */
if(!s->budget--) { s->failed_pc=0x0c0a7668u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=(int32_t)r[3])!=0);
goto P_0c0a766a;
P_0c0a766a: /* original 8925, guest PC 0x0c0a766a */
if(!s->budget--) { s->failed_pc=0x0c0a766au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a76b8; }
goto P_0c0a766c;
P_0c0a766c: /* original d014, guest PC 0x0c0a766c */
if(!s->budget--) { s->failed_pc=0x0c0a766cu; return 0; }
r[0]=read(ram,0x0c0a76c0u,4);
goto P_0c0a766e;
P_0c0a766e: /* original 6e43, guest PC 0x0c0a766e */
if(!s->budget--) { s->failed_pc=0x0c0a766eu; return 0; }
r[14]=r[4];
goto P_0c0a7670;
P_0c0a7670: /* original 4e08, guest PC 0x0c0a7670 */
if(!s->budget--) { s->failed_pc=0x0c0a7670u; return 0; }
r[14]<<=2;
goto P_0c0a7672;
P_0c0a7672: /* original 0eee, guest PC 0x0c0a7672 */
if(!s->budget--) { s->failed_pc=0x0c0a7672u; return 0; }
r[14]=read(ram,r[14]+r[0],4);
goto P_0c0a7674;
P_0c0a7674: /* original 2ee8, guest PC 0x0c0a7674 */
if(!s->budget--) { s->failed_pc=0x0c0a7674u; return 0; }
r[17]=(r[17]&~1u)|(((r[14]&r[14])==0)!=0);
goto P_0c0a7676;
P_0c0a7676: /* original 891f, guest PC 0x0c0a7676 */
if(!s->budget--) { s->failed_pc=0x0c0a7676u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a76b8; }
goto P_0c0a7678;
P_0c0a7678: /* original 60e3, guest PC 0x0c0a7678 */
if(!s->budget--) { s->failed_pc=0x0c0a7678u; return 0; }
r[0]=r[14];
goto P_0c0a767a;
P_0c0a767a: /* original 88ff, guest PC 0x0c0a767a */
if(!s->budget--) { s->failed_pc=0x0c0a767au; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xffffffffu)!=0);
goto P_0c0a767c;
P_0c0a767c: /* original 891c, guest PC 0x0c0a767c */
if(!s->budget--) { s->failed_pc=0x0c0a767cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a76b8; }
goto P_0c0a767e;
P_0c0a767e: /* original d311, guest PC 0x0c0a767e */
if(!s->budget--) { s->failed_pc=0x0c0a767eu; return 0; }
r[3]=read(ram,0x0c0a76c4u,4);
goto P_0c0a7680;
P_0c0a7680: /* original 430b, guest PC 0x0c0a7680 */
if(!s->budget--) { s->failed_pc=0x0c0a7680u; return 0; }
target=r[3];
r[16]=code_base|0x0c0a7684u;
r[4]=0x00000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a7684u) { target=s->pc; goto dispatch; }
goto P_0c0a7684;
P_0c0a7682: /* original e400, guest PC 0x0c0a7682 */
if(!s->budget--) { s->failed_pc=0x0c0a7682u; return 0; }
r[4]=0x00000000u;
goto P_0c0a7684;
P_0c0a7684: /* original d211, guest PC 0x0c0a7684 */
if(!s->budget--) { s->failed_pc=0x0c0a7684u; return 0; }
r[2]=read(ram,0x0c0a76ccu,4);
goto P_0c0a7686;
P_0c0a7686: /* original d410, guest PC 0x0c0a7686 */
if(!s->budget--) { s->failed_pc=0x0c0a7686u; return 0; }
r[4]=read(ram,0x0c0a76c8u,4);
goto P_0c0a7688;
P_0c0a7688: /* original 420b, guest PC 0x0c0a7688 */
if(!s->budget--) { s->failed_pc=0x0c0a7688u; return 0; }
target=r[2];
r[16]=code_base|0x0c0a768cu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a768cu) { target=s->pc; goto dispatch; }
goto P_0c0a768c;
P_0c0a768a: /* original 0009, guest PC 0x0c0a768a */
if(!s->budget--) { s->failed_pc=0x0c0a768au; return 0; }
goto P_0c0a768c;
P_0c0a768c: /* original 50e1, guest PC 0x0c0a768c */
if(!s->budget--) { s->failed_pc=0x0c0a768cu; return 0; }
r[0]=read(ram,r[14]+4,4);
goto P_0c0a768e;
P_0c0a768e: /* original c801, guest PC 0x0c0a768e */
if(!s->budget--) { s->failed_pc=0x0c0a768eu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&1u)==0)!=0);
goto P_0c0a7690;
P_0c0a7690: /* original 8904, guest PC 0x0c0a7690 */
if(!s->budget--) { s->failed_pc=0x0c0a7690u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a769c; }
goto P_0c0a7692;
P_0c0a7692: /* original d213, guest PC 0x0c0a7692 */
if(!s->budget--) { s->failed_pc=0x0c0a7692u; return 0; }
r[2]=read(ram,0x0c0a76e0u,4);
goto P_0c0a7694;
P_0c0a7694: /* original 420b, guest PC 0x0c0a7694 */
if(!s->budget--) { s->failed_pc=0x0c0a7694u; return 0; }
target=r[2];
r[16]=code_base|0x0c0a7698u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a7698u) { target=s->pc; goto dispatch; }
goto P_0c0a7698;
P_0c0a7696: /* original 64e3, guest PC 0x0c0a7696 */
if(!s->budget--) { s->failed_pc=0x0c0a7696u; return 0; }
r[4]=r[14];
goto P_0c0a7698;
P_0c0a7698: /* original a009, guest PC 0x0c0a7698 */
if(!s->budget--) { s->failed_pc=0x0c0a7698u; return 0; }
goto P_0c0a76ae;
P_0c0a769a: /* original 0009, guest PC 0x0c0a769a */
if(!s->budget--) { s->failed_pc=0x0c0a769au; return 0; }
goto P_0c0a769c;
P_0c0a769c: /* original d20d, guest PC 0x0c0a769c */
if(!s->budget--) { s->failed_pc=0x0c0a769cu; return 0; }
r[2]=read(ram,0x0c0a76d4u,4);
goto P_0c0a769e;
P_0c0a769e: /* original 420b, guest PC 0x0c0a769e */
if(!s->budget--) { s->failed_pc=0x0c0a769eu; return 0; }
target=r[2];
r[16]=code_base|0x0c0a76a2u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a76a2u) { target=s->pc; goto dispatch; }
goto P_0c0a76a2;
P_0c0a76a0: /* original 0009, guest PC 0x0c0a76a0 */
if(!s->budget--) { s->failed_pc=0x0c0a76a0u; return 0; }
goto P_0c0a76a2;
P_0c0a76a2: /* original d310, guest PC 0x0c0a76a2 */
if(!s->budget--) { s->failed_pc=0x0c0a76a2u; return 0; }
r[3]=read(ram,0x0c0a76e4u,4);
goto P_0c0a76a4;
P_0c0a76a4: /* original 23e8, guest PC 0x0c0a76a4 */
if(!s->budget--) { s->failed_pc=0x0c0a76a4u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[14])==0)!=0);
goto P_0c0a76a6;
P_0c0a76a6: /* original 8902, guest PC 0x0c0a76a6 */
if(!s->budget--) { s->failed_pc=0x0c0a76a6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a76ae; }
goto P_0c0a76a8;
P_0c0a76a8: /* original d30f, guest PC 0x0c0a76a8 */
if(!s->budget--) { s->failed_pc=0x0c0a76a8u; return 0; }
r[3]=read(ram,0x0c0a76e8u,4);
goto P_0c0a76aa;
P_0c0a76aa: /* original 430b, guest PC 0x0c0a76aa */
if(!s->budget--) { s->failed_pc=0x0c0a76aau; return 0; }
target=r[3];
r[16]=code_base|0x0c0a76aeu;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a76aeu) { target=s->pc; goto dispatch; }
goto P_0c0a76ae;
P_0c0a76ac: /* original 64e3, guest PC 0x0c0a76ac */
if(!s->budget--) { s->failed_pc=0x0c0a76acu; return 0; }
r[4]=r[14];
goto P_0c0a76ae;
P_0c0a76ae: /* original 4f26, guest PC 0x0c0a76ae */
if(!s->budget--) { s->failed_pc=0x0c0a76aeu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a76b0;
P_0c0a76b0: /* original d30a, guest PC 0x0c0a76b0 */
if(!s->budget--) { s->failed_pc=0x0c0a76b0u; return 0; }
r[3]=read(ram,0x0c0a76dcu,4);
goto P_0c0a76b2;
P_0c0a76b2: /* original e401, guest PC 0x0c0a76b2 */
if(!s->budget--) { s->failed_pc=0x0c0a76b2u; return 0; }
r[4]=0x00000001u;
goto P_0c0a76b4;
P_0c0a76b4: /* original 432b, guest PC 0x0c0a76b4 */
if(!s->budget--) { s->failed_pc=0x0c0a76b4u; return 0; }
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
P_0c0a76b6: /* original 6ef6, guest PC 0x0c0a76b6 */
if(!s->budget--) { s->failed_pc=0x0c0a76b6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0a76b8;
P_0c0a76b8: /* original 4f26, guest PC 0x0c0a76b8 */
if(!s->budget--) { s->failed_pc=0x0c0a76b8u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a76ba;
P_0c0a76ba: /* original 000b, guest PC 0x0c0a76ba */
if(!s->budget--) { s->failed_pc=0x0c0a76bau; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0a76bc: /* original 6ef6, guest PC 0x0c0a76bc */
if(!s->budget--) { s->failed_pc=0x0c0a76bcu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0a76beu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0a76beu; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
