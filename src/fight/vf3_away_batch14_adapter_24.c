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
int vf3_away_batch14_adapter_24(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
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
case 0x0c0917fcu: goto P_0c0917fc;
case 0x0c0917feu: goto P_0c0917fe;
case 0x0c091800u: goto P_0c091800;
case 0x0c091802u: goto P_0c091802;
case 0x0c091804u: goto P_0c091804;
case 0x0c091806u: goto P_0c091806;
case 0x0c091808u: goto P_0c091808;
case 0x0c09180au: goto P_0c09180a;
case 0x0c09180cu: goto P_0c09180c;
case 0x0c09180eu: goto P_0c09180e;
case 0x0c091810u: goto P_0c091810;
case 0x0c091812u: goto P_0c091812;
case 0x0c091814u: goto P_0c091814;
case 0x0c091816u: goto P_0c091816;
case 0x0c091818u: goto P_0c091818;
case 0x0c09181au: goto P_0c09181a;
case 0x0c09181cu: goto P_0c09181c;
case 0x0c09181eu: goto P_0c09181e;
case 0x0c091820u: goto P_0c091820;
case 0x0c091822u: goto P_0c091822;
case 0x0c091824u: goto P_0c091824;
case 0x0c091826u: goto P_0c091826;
case 0x0c091828u: goto P_0c091828;
case 0x0c09182au: goto P_0c09182a;
case 0x0c09182cu: goto P_0c09182c;
case 0x0c09182eu: goto P_0c09182e;
case 0x0c091830u: goto P_0c091830;
case 0x0c091832u: goto P_0c091832;
case 0x0c091834u: goto P_0c091834;
case 0x0c091836u: goto P_0c091836;
case 0x0c091838u: goto P_0c091838;
case 0x0c09183au: goto P_0c09183a;
case 0x0c09183cu: goto P_0c09183c;
case 0x0c09183eu: goto P_0c09183e;
case 0x0c091840u: goto P_0c091840;
case 0x0c091842u: goto P_0c091842;
case 0x0c091844u: goto P_0c091844;
case 0x0c091846u: goto P_0c091846;
case 0x0c091848u: goto P_0c091848;
case 0x0c09184au: goto P_0c09184a;
case 0x0c09184cu: goto P_0c09184c;
case 0x0c09184eu: goto P_0c09184e;
case 0x0c091850u: goto P_0c091850;
case 0x0c091852u: goto P_0c091852;
case 0x0c091854u: goto P_0c091854;
case 0x0c091856u: goto P_0c091856;
case 0x0c091858u: goto P_0c091858;
case 0x0c09185au: goto P_0c09185a;
case 0x0c09185cu: goto P_0c09185c;
case 0x0c09185eu: goto P_0c09185e;
case 0x0c091860u: goto P_0c091860;
case 0x0c091862u: goto P_0c091862;
case 0x0c091864u: goto P_0c091864;
case 0x0c091866u: goto P_0c091866;
case 0x0c091868u: goto P_0c091868;
case 0x0c09186au: goto P_0c09186a;
case 0x0c09186cu: goto P_0c09186c;
case 0x0c09186eu: goto P_0c09186e;
case 0x0c091870u: goto P_0c091870;
case 0x0c091872u: goto P_0c091872;
case 0x0c091874u: goto P_0c091874;
case 0x0c091876u: goto P_0c091876;
case 0x0c091878u: goto P_0c091878;
case 0x0c09187au: goto P_0c09187a;
case 0x0c09187cu: goto P_0c09187c;
case 0x0c09187eu: goto P_0c09187e;
case 0x0c091880u: goto P_0c091880;
case 0x0c091882u: goto P_0c091882;
case 0x0c091884u: goto P_0c091884;
case 0x0c091886u: goto P_0c091886;
case 0x0c091888u: goto P_0c091888;
case 0x0c09188au: goto P_0c09188a;
case 0x0c09188cu: goto P_0c09188c;
case 0x0c09188eu: goto P_0c09188e;
case 0x0c091890u: goto P_0c091890;
case 0x0c091892u: goto P_0c091892;
case 0x0c091894u: goto P_0c091894;
case 0x0c091896u: goto P_0c091896;
case 0x0c091898u: goto P_0c091898;
case 0x0c09189au: goto P_0c09189a;
case 0x0c09189cu: goto P_0c09189c;
case 0x0c09189eu: goto P_0c09189e;
case 0x0c0918a0u: goto P_0c0918a0;
case 0x0c0918a2u: goto P_0c0918a2;
case 0x0c0918a4u: goto P_0c0918a4;
case 0x0c0918a6u: goto P_0c0918a6;
case 0x0c0918a8u: goto P_0c0918a8;
case 0x0c0918aau: goto P_0c0918aa;
case 0x0c0918acu: goto P_0c0918ac;
case 0x0c0918aeu: goto P_0c0918ae;
case 0x0c0918b0u: goto P_0c0918b0;
case 0x0c0918b2u: goto P_0c0918b2;
case 0x0c0918b4u: goto P_0c0918b4;
case 0x0c0918b6u: goto P_0c0918b6;
case 0x0c0918b8u: goto P_0c0918b8;
case 0x0c0918bau: goto P_0c0918ba;
case 0x0c0918bcu: goto P_0c0918bc;
case 0x0c0918beu: goto P_0c0918be;
case 0x0c0918c0u: goto P_0c0918c0;
case 0x0c0918c2u: goto P_0c0918c2;
case 0x0c0918c4u: goto P_0c0918c4;
case 0x0c0918c6u: goto P_0c0918c6;
case 0x0c0918c8u: goto P_0c0918c8;
case 0x0c0918cau: goto P_0c0918ca;
case 0x0c0918ccu: goto P_0c0918cc;
case 0x0c0918ceu: goto P_0c0918ce;
case 0x0c0918d0u: goto P_0c0918d0;
case 0x0c0918d2u: goto P_0c0918d2;
case 0x0c0918d4u: goto P_0c0918d4;
case 0x0c0918d6u: goto P_0c0918d6;
case 0x0c0918d8u: goto P_0c0918d8;
case 0x0c0918dau: goto P_0c0918da;
case 0x0c0918dcu: goto P_0c0918dc;
case 0x0c0918deu: goto P_0c0918de;
case 0x0c0918e0u: goto P_0c0918e0;
case 0x0c0918e2u: goto P_0c0918e2;
case 0x0c0918e4u: goto P_0c0918e4;
case 0x0c0918e6u: goto P_0c0918e6;
case 0x0c0918e8u: goto P_0c0918e8;
case 0x0c0918eau: goto P_0c0918ea;
case 0x0c0918ecu: goto P_0c0918ec;
case 0x0c0918eeu: goto P_0c0918ee;
case 0x0c0918f0u: goto P_0c0918f0;
case 0x0c0918f2u: goto P_0c0918f2;
case 0x0c0918f4u: goto P_0c0918f4;
case 0x0c0918f6u: goto P_0c0918f6;
case 0x0c0918f8u: goto P_0c0918f8;
case 0x0c0918fau: goto P_0c0918fa;
case 0x0c0918fcu: goto P_0c0918fc;
case 0x0c0918feu: goto P_0c0918fe;
case 0x0c091900u: goto P_0c091900;
case 0x0c091902u: goto P_0c091902;
case 0x0c091904u: goto P_0c091904;
case 0x0c091906u: goto P_0c091906;
case 0x0c091908u: goto P_0c091908;
case 0x0c09190au: goto P_0c09190a;
case 0x0c09190cu: goto P_0c09190c;
case 0x0c09190eu: goto P_0c09190e;
case 0x0c091910u: goto P_0c091910;
case 0x0c091912u: goto P_0c091912;
case 0x0c091914u: goto P_0c091914;
case 0x0c091916u: goto P_0c091916;
case 0x0c091918u: goto P_0c091918;
case 0x0c09191au: goto P_0c09191a;
case 0x0c09191cu: goto P_0c09191c;
case 0x0c09191eu: goto P_0c09191e;
case 0x0c091920u: goto P_0c091920;
case 0x0c091922u: goto P_0c091922;
case 0x0c091924u: goto P_0c091924;
case 0x0c091926u: goto P_0c091926;
case 0x0c091928u: goto P_0c091928;
case 0x0c09192au: goto P_0c09192a;
case 0x0c09192cu: goto P_0c09192c;
case 0x0c09192eu: goto P_0c09192e;
case 0x0c091930u: goto P_0c091930;
case 0x0c091932u: goto P_0c091932;
case 0x0c091934u: goto P_0c091934;
case 0x0c091936u: goto P_0c091936;
case 0x0c091938u: goto P_0c091938;
case 0x0c09193au: goto P_0c09193a;
case 0x0c09193cu: goto P_0c09193c;
case 0x0c09193eu: goto P_0c09193e;
case 0x0c091940u: goto P_0c091940;
case 0x0c091942u: goto P_0c091942;
case 0x0c091944u: goto P_0c091944;
case 0x0c091946u: goto P_0c091946;
case 0x0c091948u: goto P_0c091948;
case 0x0c09194au: goto P_0c09194a;
case 0x0c09194cu: goto P_0c09194c;
case 0x0c09194eu: goto P_0c09194e;
case 0x0c091950u: goto P_0c091950;
case 0x0c091952u: goto P_0c091952;
case 0x0c091954u: goto P_0c091954;
case 0x0c091956u: goto P_0c091956;
case 0x0c091958u: goto P_0c091958;
case 0x0c09195au: goto P_0c09195a;
case 0x0c09195cu: goto P_0c09195c;
case 0x0c09195eu: goto P_0c09195e;
case 0x0c091960u: goto P_0c091960;
case 0x0c091962u: goto P_0c091962;
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
P_0c0917fc: /* original 2fe6, guest PC 0x0c0917fc */
if(!s->budget--) { s->failed_pc=0x0c0917fcu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0917fe;
P_0c0917fe: /* original d359, guest PC 0x0c0917fe */
if(!s->budget--) { s->failed_pc=0x0c0917feu; return 0; }
r[3]=read(ram,0x0c091964u,4);
goto P_0c091800;
P_0c091800: /* original d659, guest PC 0x0c091800 */
if(!s->budget--) { s->failed_pc=0x0c091800u; return 0; }
r[6]=read(ram,0x0c091968u,4);
goto P_0c091802;
P_0c091802: /* original 6532, guest PC 0x0c091802 */
if(!s->budget--) { s->failed_pc=0x0c091802u; return 0; }
tmp=read(ram,r[3],4);
r[5]=tmp;
goto P_0c091804;
P_0c091804: /* original 7514, guest PC 0x0c091804 */
if(!s->budget--) { s->failed_pc=0x0c091804u; return 0; }
r[5]+=0x00000014u;
goto P_0c091806;
P_0c091806: /* original 6052, guest PC 0x0c091806 */
if(!s->budget--) { s->failed_pc=0x0c091806u; return 0; }
tmp=read(ram,r[5],4);
r[0]=tmp;
goto P_0c091808;
P_0c091808: /* original 880c, guest PC 0x0c091808 */
if(!s->budget--) { s->failed_pc=0x0c091808u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000cu)!=0);
goto P_0c09180a;
P_0c09180a: /* original 8d0d, guest PC 0x0c09180a */
if(!s->budget--) { s->failed_pc=0x0c09180au; return 0; }
cond=r[17]&1u;
r[14]=r[0];
if(cond) { goto P_0c091828; }
goto P_0c09180e;
P_0c09180c: /* original 6e03, guest PC 0x0c09180c */
if(!s->budget--) { s->failed_pc=0x0c09180cu; return 0; }
r[14]=r[0];
goto P_0c09180e;
P_0c09180e: /* original e364, guest PC 0x0c09180e */
if(!s->budget--) { s->failed_pc=0x0c09180eu; return 0; }
r[3]=0x00000064u;
goto P_0c091810;
P_0c091810: /* original 2432, guest PC 0x0c091810 */
if(!s->budget--) { s->failed_pc=0x0c091810u; return 0; }
write(ram,r[4],r[3],4);
goto P_0c091812;
P_0c091812: /* original 63e3, guest PC 0x0c091812 */
if(!s->budget--) { s->failed_pc=0x0c091812u; return 0; }
r[3]=r[14];
goto P_0c091814;
P_0c091814: /* original 6262, guest PC 0x0c091814 */
if(!s->budget--) { s->failed_pc=0x0c091814u; return 0; }
tmp=read(ram,r[6],4);
r[2]=tmp;
goto P_0c091816;
P_0c091816: /* original 7301, guest PC 0x0c091816 */
if(!s->budget--) { s->failed_pc=0x0c091816u; return 0; }
r[3]+=0x00000001u;
goto P_0c091818;
P_0c091818: /* original 1428, guest PC 0x0c091818 */
if(!s->budget--) { s->failed_pc=0x0c091818u; return 0; }
write(ram,r[4]+32,r[2],4);
goto P_0c09181a;
P_0c09181a: /* original 62e3, guest PC 0x0c09181a */
if(!s->budget--) { s->failed_pc=0x0c09181au; return 0; }
r[2]=r[14];
goto P_0c09181c;
P_0c09181c: /* original 2532, guest PC 0x0c09181c */
if(!s->budget--) { s->failed_pc=0x0c09181cu; return 0; }
write(ram,r[5],r[3],4);
goto P_0c09181e;
P_0c09181e: /* original 6353, guest PC 0x0c09181e */
if(!s->budget--) { s->failed_pc=0x0c09181eu; return 0; }
r[3]=r[5];
goto P_0c091820;
P_0c091820: /* original 7304, guest PC 0x0c091820 */
if(!s->budget--) { s->failed_pc=0x0c091820u; return 0; }
r[3]+=0x00000004u;
goto P_0c091822;
P_0c091822: /* original 4208, guest PC 0x0c091822 */
if(!s->budget--) { s->failed_pc=0x0c091822u; return 0; }
r[2]<<=2;
goto P_0c091824;
P_0c091824: /* original 323c, guest PC 0x0c091824 */
if(!s->budget--) { s->failed_pc=0x0c091824u; return 0; }
r[2]+=r[3];
goto P_0c091826;
P_0c091826: /* original 2242, guest PC 0x0c091826 */
if(!s->budget--) { s->failed_pc=0x0c091826u; return 0; }
write(ram,r[2],r[4],4);
goto P_0c091828;
P_0c091828: /* original 000b, guest PC 0x0c091828 */
if(!s->budget--) { s->failed_pc=0x0c091828u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c09182a: /* original 6ef6, guest PC 0x0c09182a */
if(!s->budget--) { s->failed_pc=0x0c09182au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c09182c;
P_0c09182c: /* original 2fe6, guest PC 0x0c09182c */
if(!s->budget--) { s->failed_pc=0x0c09182cu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09182e;
P_0c09182e: /* original 6e43, guest PC 0x0c09182e */
if(!s->budget--) { s->failed_pc=0x0c09182eu; return 0; }
r[14]=r[4];
goto P_0c091830;
P_0c091830: /* original 2fd6, guest PC 0x0c091830 */
if(!s->budget--) { s->failed_pc=0x0c091830u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c091832;
P_0c091832: /* original e044, guest PC 0x0c091832 */
if(!s->budget--) { s->failed_pc=0x0c091832u; return 0; }
r[0]=0x00000044u;
goto P_0c091834;
P_0c091834: /* original fffb, guest PC 0x0c091834 */
if(!s->budget--) { s->failed_pc=0x0c091834u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c091836;
P_0c091836: /* original ffeb, guest PC 0x0c091836 */
if(!s->budget--) { s->failed_pc=0x0c091836u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,14,r[15]);
goto P_0c091838;
P_0c091838: /* original dd4c, guest PC 0x0c091838 */
if(!s->budget--) { s->failed_pc=0x0c091838u; return 0; }
r[13]=read(ram,0x0c09196cu,4);
goto P_0c09183a;
P_0c09183a: /* original 4f22, guest PC 0x0c09183a */
if(!s->budget--) { s->failed_pc=0x0c09183au; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c09183c;
P_0c09183c: /* original 04de, guest PC 0x0c09183c */
if(!s->budget--) { s->failed_pc=0x0c09183cu; return 0; }
r[4]=read(ram,r[13]+r[0],4);
goto P_0c09183e;
P_0c09183e: /* original 60e2, guest PC 0x0c09183e */
if(!s->budget--) { s->failed_pc=0x0c09183eu; return 0; }
tmp=read(ram,r[14],4);
r[0]=tmp;
goto P_0c091840;
P_0c091840: /* original 7ff4, guest PC 0x0c091840 */
if(!s->budget--) { s->failed_pc=0x0c091840u; return 0; }
r[15]+=0xfffffff4u;
goto P_0c091842;
P_0c091842: /* original 6543, guest PC 0x0c091842 */
if(!s->budget--) { s->failed_pc=0x0c091842u; return 0; }
r[5]=r[4];
goto P_0c091844;
P_0c091844: /* original 8864, guest PC 0x0c091844 */
if(!s->budget--) { s->failed_pc=0x0c091844u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000064u)!=0);
goto P_0c091846;
P_0c091846: /* original 8d02, guest PC 0x0c091846 */
if(!s->budget--) { s->failed_pc=0x0c091846u; return 0; }
cond=r[17]&1u;
r[5]+=0x00000014u;
if(cond) { goto P_0c09184e; }
goto P_0c09184a;
P_0c091848: /* original 7514, guest PC 0x0c091848 */
if(!s->budget--) { s->failed_pc=0x0c091848u; return 0; }
r[5]+=0x00000014u;
goto P_0c09184a;
P_0c09184a: /* original a082, guest PC 0x0c09184a */
if(!s->budget--) { s->failed_pc=0x0c09184au; return 0; }
goto P_0c091952;
P_0c09184c: /* original 0009, guest PC 0x0c09184c */
if(!s->budget--) { s->failed_pc=0x0c09184cu; return 0; }
goto P_0c09184e;
P_0c09184e: /* original 6452, guest PC 0x0c09184e */
if(!s->budget--) { s->failed_pc=0x0c09184eu; return 0; }
tmp=read(ram,r[5],4);
r[4]=tmp;
goto P_0c091850;
P_0c091850: /* original 4411, guest PC 0x0c091850 */
if(!s->budget--) { s->failed_pc=0x0c091850u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=0)!=0);
goto P_0c091852;
P_0c091852: /* original 8b0d, guest PC 0x0c091852 */
if(!s->budget--) { s->failed_pc=0x0c091852u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c091870; }
goto P_0c091854;
P_0c091854: /* original e30c, guest PC 0x0c091854 */
if(!s->budget--) { s->failed_pc=0x0c091854u; return 0; }
r[3]=0x0000000cu;
goto P_0c091856;
P_0c091856: /* original 3437, guest PC 0x0c091856 */
if(!s->budget--) { s->failed_pc=0x0c091856u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>(int32_t)r[3])!=0);
goto P_0c091858;
P_0c091858: /* original 890a, guest PC 0x0c091858 */
if(!s->budget--) { s->failed_pc=0x0c091858u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c091870; }
goto P_0c09185a;
P_0c09185a: /* original 7504, guest PC 0x0c09185a */
if(!s->budget--) { s->failed_pc=0x0c09185au; return 0; }
r[5]+=0x00000004u;
goto P_0c09185c;
P_0c09185c: /* original 6643, guest PC 0x0c09185c */
if(!s->budget--) { s->failed_pc=0x0c09185cu; return 0; }
r[6]=r[4];
goto P_0c09185e;
P_0c09185e: /* original 6753, guest PC 0x0c09185e */
if(!s->budget--) { s->failed_pc=0x0c09185eu; return 0; }
r[7]=r[5];
goto P_0c091860;
P_0c091860: /* original 6352, guest PC 0x0c091860 */
if(!s->budget--) { s->failed_pc=0x0c091860u; return 0; }
tmp=read(ram,r[5],4);
r[3]=tmp;
goto P_0c091862;
P_0c091862: /* original 6233, guest PC 0x0c091862 */
if(!s->budget--) { s->failed_pc=0x0c091862u; return 0; }
r[2]=r[3];
goto P_0c091864;
P_0c091864: /* original 32e0, guest PC 0x0c091864 */
if(!s->budget--) { s->failed_pc=0x0c091864u; return 0; }
r[17]=(r[17]&~1u)|((r[2]==r[14])!=0);
goto P_0c091866;
P_0c091866: /* original 1f32, guest PC 0x0c091866 */
if(!s->budget--) { s->failed_pc=0x0c091866u; return 0; }
write(ram,r[15]+8,r[3],4);
goto P_0c091868;
P_0c091868: /* original 8904, guest PC 0x0c091868 */
if(!s->budget--) { s->failed_pc=0x0c091868u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c091874; }
goto P_0c09186a;
P_0c09186a: /* original 4410, guest PC 0x0c09186a */
if(!s->budget--) { s->failed_pc=0x0c09186au; return 0; }
--r[4];
r[17]=(r[17]&~1u)|((r[4]==0)!=0);
goto P_0c09186c;
P_0c09186c: /* original 8ff8, guest PC 0x0c09186c */
if(!s->budget--) { s->failed_pc=0x0c09186cu; return 0; }
cond=r[17]&1u;
r[5]+=0x00000004u;
if(!cond) { goto P_0c091860; }
goto P_0c091870;
P_0c09186e: /* original 7504, guest PC 0x0c09186e */
if(!s->budget--) { s->failed_pc=0x0c09186eu; return 0; }
r[5]+=0x00000004u;
goto P_0c091870;
P_0c091870: /* original a070, guest PC 0x0c091870 */
if(!s->budget--) { s->failed_pc=0x0c091870u; return 0; }
r[4]=0x00000001u;
goto P_0c091954;
P_0c091872: /* original e401, guest PC 0x0c091872 */
if(!s->budget--) { s->failed_pc=0x0c091872u; return 0; }
r[4]=0x00000001u;
goto P_0c091874;
P_0c091874: /* original e004, guest PC 0x0c091874 */
if(!s->budget--) { s->failed_pc=0x0c091874u; return 0; }
r[0]=0x00000004u;
goto P_0c091876;
P_0c091876: /* original f3e6, guest PC 0x0c091876 */
if(!s->budget--) { s->failed_pc=0x0c091876u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c091878;
P_0c091878: /* original e004, guest PC 0x0c091878 */
if(!s->budget--) { s->failed_pc=0x0c091878u; return 0; }
r[0]=0x00000004u;
goto P_0c09187a;
P_0c09187a: /* original ff37, guest PC 0x0c09187a */
if(!s->budget--) { s->failed_pc=0x0c09187au; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c09187c;
P_0c09187c: /* original e00c, guest PC 0x0c09187c */
if(!s->budget--) { s->failed_pc=0x0c09187cu; return 0; }
r[0]=0x0000000cu;
goto P_0c09187e;
P_0c09187e: /* original f3e6, guest PC 0x0c09187e */
if(!s->budget--) { s->failed_pc=0x0c09187eu; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c091880;
P_0c091880: /* original e01c, guest PC 0x0c091880 */
if(!s->budget--) { s->failed_pc=0x0c091880u; return 0; }
r[0]=0x0000001cu;
goto P_0c091882;
P_0c091882: /* original ff3a, guest PC 0x0c091882 */
if(!s->budget--) { s->failed_pc=0x0c091882u; return 0; }
vf3_matrix_store(s,ram,3,r[15]);
goto P_0c091884;
P_0c091884: /* original fee6, guest PC 0x0c091884 */
if(!s->budget--) { s->failed_pc=0x0c091884u; return 0; }
vf3_matrix_load(s,ram,14,r[14]+r[0]);
goto P_0c091886;
P_0c091886: /* original 6472, guest PC 0x0c091886 */
if(!s->budget--) { s->failed_pc=0x0c091886u; return 0; }
tmp=read(ram,r[7],4);
r[4]=tmp;
goto P_0c091888;
P_0c091888: /* original 34e0, guest PC 0x0c091888 */
if(!s->budget--) { s->failed_pc=0x0c091888u; return 0; }
r[17]=(r[17]&~1u)|((r[4]==r[14])!=0);
goto P_0c09188a;
P_0c09188a: /* original 8938, guest PC 0x0c09188a */
if(!s->budget--) { s->failed_pc=0x0c09188au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0918fe; }
goto P_0c09188c;
P_0c09188c: /* original e004, guest PC 0x0c09188c */
if(!s->budget--) { s->failed_pc=0x0c09188cu; return 0; }
r[0]=0x00000004u;
goto P_0c09188e;
P_0c09188e: /* original f546, guest PC 0x0c09188e */
if(!s->budget--) { s->failed_pc=0x0c09188eu; return 0; }
vf3_matrix_load(s,ram,5,r[4]+r[0]);
goto P_0c091890;
P_0c091890: /* original e00c, guest PC 0x0c091890 */
if(!s->budget--) { s->failed_pc=0x0c091890u; return 0; }
r[0]=0x0000000cu;
goto P_0c091892;
P_0c091892: /* original f646, guest PC 0x0c091892 */
if(!s->budget--) { s->failed_pc=0x0c091892u; return 0; }
vf3_matrix_load(s,ram,6,r[4]+r[0]);
goto P_0c091894;
P_0c091894: /* original e01c, guest PC 0x0c091894 */
if(!s->budget--) { s->failed_pc=0x0c091894u; return 0; }
r[0]=0x0000001cu;
goto P_0c091896;
P_0c091896: /* original f746, guest PC 0x0c091896 */
if(!s->budget--) { s->failed_pc=0x0c091896u; return 0; }
vf3_matrix_load(s,ram,7,r[4]+r[0]);
goto P_0c091898;
P_0c091898: /* original e004, guest PC 0x0c091898 */
if(!s->budget--) { s->failed_pc=0x0c091898u; return 0; }
r[0]=0x00000004u;
goto P_0c09189a;
P_0c09189a: /* original f3f6, guest PC 0x0c09189a */
if(!s->budget--) { s->failed_pc=0x0c09189au; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c09189c;
P_0c09189c: /* original f354, guest PC 0x0c09189c */
if(!s->budget--) { s->failed_pc=0x0c09189cu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])==as_float(fr[5]))!=0);
goto P_0c09189e;
P_0c09189e: /* original 8b06, guest PC 0x0c09189e */
if(!s->budget--) { s->failed_pc=0x0c09189eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0918ae; }
goto P_0c0918a0;
P_0c0918a0: /* original f3f8, guest PC 0x0c0918a0 */
if(!s->budget--) { s->failed_pc=0x0c0918a0u; return 0; }
vf3_matrix_load(s,ram,3,r[15]);
goto P_0c0918a2;
P_0c0918a2: /* original f364, guest PC 0x0c0918a2 */
if(!s->budget--) { s->failed_pc=0x0c0918a2u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])==as_float(fr[6]))!=0);
goto P_0c0918a4;
P_0c0918a4: /* original 8b03, guest PC 0x0c0918a4 */
if(!s->budget--) { s->failed_pc=0x0c0918a4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0918ae; }
goto P_0c0918a6;
P_0c0918a6: /* original c732, guest PC 0x0c0918a6 */
if(!s->budget--) { s->failed_pc=0x0c0918a6u; return 0; }
r[0]=code_base|0x00091970u;
goto P_0c0918a8;
P_0c0918a8: /* original f408, guest PC 0x0c0918a8 */
if(!s->budget--) { s->failed_pc=0x0c0918a8u; return 0; }
vf3_matrix_load(s,ram,4,r[0]);
goto P_0c0918aa;
P_0c0918aa: /* original f640, guest PC 0x0c0918aa */
if(!s->budget--) { s->failed_pc=0x0c0918aau; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[4],r[18],'+');
goto P_0c0918ac;
P_0c0918ac: /* original f540, guest PC 0x0c0918ac */
if(!s->budget--) { s->failed_pc=0x0c0918acu; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[4],r[18],'+');
goto P_0c0918ae;
P_0c0918ae: /* original e004, guest PC 0x0c0918ae */
if(!s->budget--) { s->failed_pc=0x0c0918aeu; return 0; }
r[0]=0x00000004u;
goto P_0c0918b0;
P_0c0918b0: /* original fff8, guest PC 0x0c0918b0 */
if(!s->budget--) { s->failed_pc=0x0c0918b0u; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
goto P_0c0918b2;
P_0c0918b2: /* original f4f6, guest PC 0x0c0918b2 */
if(!s->budget--) { s->failed_pc=0x0c0918b2u; return 0; }
vf3_matrix_load(s,ram,4,r[15]+r[0]);
goto P_0c0918b4;
P_0c0918b4: /* original ff61, guest PC 0x0c0918b4 */
if(!s->budget--) { s->failed_pc=0x0c0918b4u; return 0; }
fr[15]=vf3_fpu_binary(fr[15],fr[6],r[18],'-');
goto P_0c0918b6;
P_0c0918b6: /* original f67c, guest PC 0x0c0918b6 */
if(!s->budget--) { s->failed_pc=0x0c0918b6u; return 0; }
vf3_matrix_move(s,6,7);
goto P_0c0918b8;
P_0c0918b8: /* original f451, guest PC 0x0c0918b8 */
if(!s->budget--) { s->failed_pc=0x0c0918b8u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[5],r[18],'-');
goto P_0c0918ba;
P_0c0918ba: /* original f672, guest PC 0x0c0918ba */
if(!s->budget--) { s->failed_pc=0x0c0918bau; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[7],r[18],'*');
goto P_0c0918bc;
P_0c0918bc: /* original f0fc, guest PC 0x0c0918bc */
if(!s->budget--) { s->failed_pc=0x0c0918bcu; return 0; }
vf3_matrix_move(s,0,15);
goto P_0c0918be;
P_0c0918be: /* original f34c, guest PC 0x0c0918be */
if(!s->budget--) { s->failed_pc=0x0c0918beu; return 0; }
vf3_matrix_move(s,3,4);
goto P_0c0918c0;
P_0c0918c0: /* original f432, guest PC 0x0c0918c0 */
if(!s->budget--) { s->failed_pc=0x0c0918c0u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'*');
goto P_0c0918c2;
P_0c0918c2: /* original f36c, guest PC 0x0c0918c2 */
if(!s->budget--) { s->failed_pc=0x0c0918c2u; return 0; }
vf3_matrix_move(s,3,6);
goto P_0c0918c4;
P_0c0918c4: /* original f24c, guest PC 0x0c0918c4 */
if(!s->budget--) { s->failed_pc=0x0c0918c4u; return 0; }
vf3_matrix_move(s,2,4);
goto P_0c0918c6;
P_0c0918c6: /* original f2fe, guest PC 0x0c0918c6 */
if(!s->budget--) { s->failed_pc=0x0c0918c6u; return 0; }
fr[2]=vf3_fpu_mac(fr[0],fr[15],fr[2],r[18]);
goto P_0c0918c8;
P_0c0918c8: /* original f0ec, guest PC 0x0c0918c8 */
if(!s->budget--) { s->failed_pc=0x0c0918c8u; return 0; }
vf3_matrix_move(s,0,14);
goto P_0c0918ca;
P_0c0918ca: /* original f3ee, guest PC 0x0c0918ca */
if(!s->budget--) { s->failed_pc=0x0c0918cau; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[14],fr[3],r[18]);
goto P_0c0918cc;
P_0c0918cc: /* original f42c, guest PC 0x0c0918cc */
if(!s->budget--) { s->failed_pc=0x0c0918ccu; return 0; }
vf3_matrix_move(s,4,2);
goto P_0c0918ce;
P_0c0918ce: /* original f63c, guest PC 0x0c0918ce */
if(!s->budget--) { s->failed_pc=0x0c0918ceu; return 0; }
vf3_matrix_move(s,6,3);
goto P_0c0918d0;
P_0c0918d0: /* original f465, guest PC 0x0c0918d0 */
if(!s->budget--) { s->failed_pc=0x0c0918d0u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[4])>as_float(fr[6]))!=0);
goto P_0c0918d2;
P_0c0918d2: /* original 8914, guest PC 0x0c0918d2 */
if(!s->budget--) { s->failed_pc=0x0c0918d2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0918fe; }
goto P_0c0918d4;
P_0c0918d4: /* original c727, guest PC 0x0c0918d4 */
if(!s->budget--) { s->failed_pc=0x0c0918d4u; return 0; }
r[0]=code_base|0x00091974u;
goto P_0c0918d6;
P_0c0918d6: /* original f308, guest PC 0x0c0918d6 */
if(!s->budget--) { s->failed_pc=0x0c0918d6u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c0918d8;
P_0c0918d8: /* original f345, guest PC 0x0c0918d8 */
if(!s->budget--) { s->failed_pc=0x0c0918d8u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[4]))!=0);
goto P_0c0918da;
P_0c0918da: /* original 8f02, guest PC 0x0c0918da */
if(!s->budget--) { s->failed_pc=0x0c0918dau; return 0; }
cond=r[17]&1u;
vf3_matrix_move(s,6,15);
if(!cond) { goto P_0c0918e2; }
goto P_0c0918de;
P_0c0918dc: /* original f6fc, guest PC 0x0c0918dc */
if(!s->budget--) { s->failed_pc=0x0c0918dcu; return 0; }
vf3_matrix_move(s,6,15);
goto P_0c0918de;
P_0c0918de: /* original a001, guest PC 0x0c0918de */
if(!s->budget--) { s->failed_pc=0x0c0918deu; return 0; }
fr[4]=0;
goto P_0c0918e4;
P_0c0918e0: /* original f48d, guest PC 0x0c0918e0 */
if(!s->budget--) { s->failed_pc=0x0c0918e0u; return 0; }
fr[4]=0;
goto P_0c0918e2;
P_0c0918e2: /* original f47d, guest PC 0x0c0918e2 */
if(!s->budget--) { s->failed_pc=0x0c0918e2u; return 0; }
if(!vf3_fpu_fsrra(fr[4],r[18],&fr[4])) goto unsupported;
goto P_0c0918e4;
P_0c0918e4: /* original c724, guest PC 0x0c0918e4 */
if(!s->budget--) { s->failed_pc=0x0c0918e4u; return 0; }
r[0]=code_base|0x00091978u;
goto P_0c0918e6;
P_0c0918e6: /* original f642, guest PC 0x0c0918e6 */
if(!s->budget--) { s->failed_pc=0x0c0918e6u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[4],r[18],'*');
goto P_0c0918e8;
P_0c0918e8: /* original f542, guest PC 0x0c0918e8 */
if(!s->budget--) { s->failed_pc=0x0c0918e8u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[4],r[18],'*');
goto P_0c0918ea;
P_0c0918ea: /* original f408, guest PC 0x0c0918ea */
if(!s->budget--) { s->failed_pc=0x0c0918eau; return 0; }
vf3_matrix_load(s,ram,4,r[0]);
goto P_0c0918ec;
P_0c0918ec: /* original e004, guest PC 0x0c0918ec */
if(!s->budget--) { s->failed_pc=0x0c0918ecu; return 0; }
r[0]=0x00000004u;
goto P_0c0918ee;
P_0c0918ee: /* original f3f6, guest PC 0x0c0918ee */
if(!s->budget--) { s->failed_pc=0x0c0918eeu; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0918f0;
P_0c0918f0: /* original e004, guest PC 0x0c0918f0 */
if(!s->budget--) { s->failed_pc=0x0c0918f0u; return 0; }
r[0]=0x00000004u;
goto P_0c0918f2;
P_0c0918f2: /* original f04c, guest PC 0x0c0918f2 */
if(!s->budget--) { s->failed_pc=0x0c0918f2u; return 0; }
vf3_matrix_move(s,0,4);
goto P_0c0918f4;
P_0c0918f4: /* original f35e, guest PC 0x0c0918f4 */
if(!s->budget--) { s->failed_pc=0x0c0918f4u; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[5],fr[3],r[18]);
goto P_0c0918f6;
P_0c0918f6: /* original ff37, guest PC 0x0c0918f6 */
if(!s->budget--) { s->failed_pc=0x0c0918f6u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0918f8;
P_0c0918f8: /* original f2f8, guest PC 0x0c0918f8 */
if(!s->budget--) { s->failed_pc=0x0c0918f8u; return 0; }
vf3_matrix_load(s,ram,2,r[15]);
goto P_0c0918fa;
P_0c0918fa: /* original f26e, guest PC 0x0c0918fa */
if(!s->budget--) { s->failed_pc=0x0c0918fau; return 0; }
fr[2]=vf3_fpu_mac(fr[0],fr[6],fr[2],r[18]);
goto P_0c0918fc;
P_0c0918fc: /* original ff2a, guest PC 0x0c0918fc */
if(!s->budget--) { s->failed_pc=0x0c0918fcu; return 0; }
vf3_matrix_store(s,ram,2,r[15]);
goto P_0c0918fe;
P_0c0918fe: /* original 4610, guest PC 0x0c0918fe */
if(!s->budget--) { s->failed_pc=0x0c0918feu; return 0; }
--r[6];
r[17]=(r[17]&~1u)|((r[6]==0)!=0);
goto P_0c091900;
P_0c091900: /* original 8fc1, guest PC 0x0c091900 */
if(!s->budget--) { s->failed_pc=0x0c091900u; return 0; }
cond=r[17]&1u;
r[7]+=0x00000004u;
if(!cond) { goto P_0c091886; }
goto P_0c091904;
P_0c091902: /* original 7704, guest PC 0x0c091902 */
if(!s->budget--) { s->failed_pc=0x0c091902u; return 0; }
r[7]+=0x00000004u;
goto P_0c091904;
P_0c091904: /* original e008, guest PC 0x0c091904 */
if(!s->budget--) { s->failed_pc=0x0c091904u; return 0; }
r[0]=0x00000008u;
goto P_0c091906;
P_0c091906: /* original 54d4, guest PC 0x0c091906 */
if(!s->budget--) { s->failed_pc=0x0c091906u; return 0; }
r[4]=read(ram,r[13]+16,4);
goto P_0c091908;
P_0c091908: /* original ffe6, guest PC 0x0c091908 */
if(!s->budget--) { s->failed_pc=0x0c091908u; return 0; }
vf3_matrix_load(s,ram,15,r[14]+r[0]);
goto P_0c09190a;
P_0c09190a: /* original e014, guest PC 0x0c09190a */
if(!s->budget--) { s->failed_pc=0x0c09190au; return 0; }
r[0]=0x00000014u;
goto P_0c09190c;
P_0c09190c: /* original f4e6, guest PC 0x0c09190c */
if(!s->budget--) { s->failed_pc=0x0c09190cu; return 0; }
vf3_matrix_load(s,ram,4,r[14]+r[0]);
goto P_0c09190e;
P_0c09190e: /* original 65f3, guest PC 0x0c09190e */
if(!s->budget--) { s->failed_pc=0x0c09190eu; return 0; }
r[5]=r[15];
goto P_0c091910;
P_0c091910: /* original f5ec, guest PC 0x0c091910 */
if(!s->budget--) { s->failed_pc=0x0c091910u; return 0; }
vf3_matrix_move(s,5,14);
goto P_0c091912;
P_0c091912: /* original 66f3, guest PC 0x0c091912 */
if(!s->budget--) { s->failed_pc=0x0c091912u; return 0; }
r[6]=r[15];
goto P_0c091914;
P_0c091914: /* original ff41, guest PC 0x0c091914 */
if(!s->budget--) { s->failed_pc=0x0c091914u; return 0; }
fr[15]=vf3_fpu_binary(fr[15],fr[4],r[18],'-');
goto P_0c091916;
P_0c091916: /* original ff41, guest PC 0x0c091916 */
if(!s->budget--) { s->failed_pc=0x0c091916u; return 0; }
fr[15]=vf3_fpu_binary(fr[15],fr[4],r[18],'-');
goto P_0c091918;
P_0c091918: /* original f4fc, guest PC 0x0c091918 */
if(!s->budget--) { s->failed_pc=0x0c091918u; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c09191a;
P_0c09191a: /* original b031, guest PC 0x0c09191a */
if(!s->budget--) { s->failed_pc=0x0c09191au; return 0; }
target=code_base|0x0c091980u; r[16]=code_base|0x0c09191eu;
r[5]+=0x00000004u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09191eu) { target=s->pc; goto dispatch; }
goto P_0c09191e;
P_0c09191c: /* original 7504, guest PC 0x0c09191c */
if(!s->budget--) { s->failed_pc=0x0c09191cu; return 0; }
r[5]+=0x00000004u;
goto P_0c09191e;
P_0c09191e: /* original 54d5, guest PC 0x0c09191e */
if(!s->budget--) { s->failed_pc=0x0c09191eu; return 0; }
r[4]=read(ram,r[13]+20,4);
goto P_0c091920;
P_0c091920: /* original 65f3, guest PC 0x0c091920 */
if(!s->budget--) { s->failed_pc=0x0c091920u; return 0; }
r[5]=r[15];
goto P_0c091922;
P_0c091922: /* original f4fc, guest PC 0x0c091922 */
if(!s->budget--) { s->failed_pc=0x0c091922u; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c091924;
P_0c091924: /* original 66f3, guest PC 0x0c091924 */
if(!s->budget--) { s->failed_pc=0x0c091924u; return 0; }
r[6]=r[15];
goto P_0c091926;
P_0c091926: /* original f5ec, guest PC 0x0c091926 */
if(!s->budget--) { s->failed_pc=0x0c091926u; return 0; }
vf3_matrix_move(s,5,14);
goto P_0c091928;
P_0c091928: /* original b02a, guest PC 0x0c091928 */
if(!s->budget--) { s->failed_pc=0x0c091928u; return 0; }
target=code_base|0x0c091980u; r[16]=code_base|0x0c09192cu;
r[5]+=0x00000004u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09192cu) { target=s->pc; goto dispatch; }
goto P_0c09192c;
P_0c09192a: /* original 7504, guest PC 0x0c09192a */
if(!s->budget--) { s->failed_pc=0x0c09192au; return 0; }
r[5]+=0x00000004u;
goto P_0c09192c;
P_0c09192c: /* original f5f8, guest PC 0x0c09192c */
if(!s->budget--) { s->failed_pc=0x0c09192cu; return 0; }
vf3_matrix_load(s,ram,5,r[15]);
goto P_0c09192e;
P_0c09192e: /* original e004, guest PC 0x0c09192e */
if(!s->budget--) { s->failed_pc=0x0c09192eu; return 0; }
r[0]=0x00000004u;
goto P_0c091930;
P_0c091930: /* original d312, guest PC 0x0c091930 */
if(!s->budget--) { s->failed_pc=0x0c091930u; return 0; }
r[3]=read(ram,0x0c09197cu,4);
goto P_0c091932;
P_0c091932: /* original f54d, guest PC 0x0c091932 */
if(!s->budget--) { s->failed_pc=0x0c091932u; return 0; }
fr[5]^=0x80000000u;
goto P_0c091934;
P_0c091934: /* original 430b, guest PC 0x0c091934 */
if(!s->budget--) { s->failed_pc=0x0c091934u; return 0; }
target=r[3];
r[16]=code_base|0x0c091938u;
vf3_matrix_load(s,ram,4,r[15]+r[0]);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c091938u) { target=s->pc; goto dispatch; }
goto P_0c091938;
P_0c091936: /* original f4f6, guest PC 0x0c091936 */
if(!s->budget--) { s->failed_pc=0x0c091936u; return 0; }
vf3_matrix_load(s,ram,4,r[15]+r[0]);
goto P_0c091938;
P_0c091938: /* original e014, guest PC 0x0c091938 */
if(!s->budget--) { s->failed_pc=0x0c091938u; return 0; }
r[0]=0x00000014u;
goto P_0c09193a;
P_0c09193a: /* original f40c, guest PC 0x0c09193a */
if(!s->budget--) { s->failed_pc=0x0c09193au; return 0; }
vf3_matrix_move(s,4,0);
goto P_0c09193c;
P_0c09193c: /* original f5e6, guest PC 0x0c09193c */
if(!s->budget--) { s->failed_pc=0x0c09193cu; return 0; }
vf3_matrix_load(s,ram,5,r[14]+r[0]);
goto P_0c09193e;
P_0c09193e: /* original e004, guest PC 0x0c09193e */
if(!s->budget--) { s->failed_pc=0x0c09193eu; return 0; }
r[0]=0x00000004u;
goto P_0c091940;
P_0c091940: /* original f3f6, guest PC 0x0c091940 */
if(!s->budget--) { s->failed_pc=0x0c091940u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c091942;
P_0c091942: /* original e004, guest PC 0x0c091942 */
if(!s->budget--) { s->failed_pc=0x0c091942u; return 0; }
r[0]=0x00000004u;
goto P_0c091944;
P_0c091944: /* original f451, guest PC 0x0c091944 */
if(!s->budget--) { s->failed_pc=0x0c091944u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[5],r[18],'-');
goto P_0c091946;
P_0c091946: /* original fe37, guest PC 0x0c091946 */
if(!s->budget--) { s->failed_pc=0x0c091946u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c091948;
P_0c091948: /* original e008, guest PC 0x0c091948 */
if(!s->budget--) { s->failed_pc=0x0c091948u; return 0; }
r[0]=0x00000008u;
goto P_0c09194a;
P_0c09194a: /* original fe47, guest PC 0x0c09194a */
if(!s->budget--) { s->failed_pc=0x0c09194au; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c09194c;
P_0c09194c: /* original e00c, guest PC 0x0c09194c */
if(!s->budget--) { s->failed_pc=0x0c09194cu; return 0; }
r[0]=0x0000000cu;
goto P_0c09194e;
P_0c09194e: /* original f3f8, guest PC 0x0c09194e */
if(!s->budget--) { s->failed_pc=0x0c09194eu; return 0; }
vf3_matrix_load(s,ram,3,r[15]);
goto P_0c091950;
P_0c091950: /* original fe37, guest PC 0x0c091950 */
if(!s->budget--) { s->failed_pc=0x0c091950u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c091952;
P_0c091952: /* original e400, guest PC 0x0c091952 */
if(!s->budget--) { s->failed_pc=0x0c091952u; return 0; }
r[4]=0x00000000u;
goto P_0c091954;
P_0c091954: /* original 7f0c, guest PC 0x0c091954 */
if(!s->budget--) { s->failed_pc=0x0c091954u; return 0; }
r[15]+=0x0000000cu;
goto P_0c091956;
P_0c091956: /* original 6043, guest PC 0x0c091956 */
if(!s->budget--) { s->failed_pc=0x0c091956u; return 0; }
r[0]=r[4];
goto P_0c091958;
P_0c091958: /* original 4f26, guest PC 0x0c091958 */
if(!s->budget--) { s->failed_pc=0x0c091958u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c09195a;
P_0c09195a: /* original fef9, guest PC 0x0c09195a */
if(!s->budget--) { s->failed_pc=0x0c09195au; return 0; }
vf3_matrix_load(s,ram,14,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c09195c;
P_0c09195c: /* original fff9, guest PC 0x0c09195c */
if(!s->budget--) { s->failed_pc=0x0c09195cu; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c09195e;
P_0c09195e: /* original 6df6, guest PC 0x0c09195e */
if(!s->budget--) { s->failed_pc=0x0c09195eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c091960;
P_0c091960: /* original 000b, guest PC 0x0c091960 */
if(!s->budget--) { s->failed_pc=0x0c091960u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c091962: /* original 6ef6, guest PC 0x0c091962 */
if(!s->budget--) { s->failed_pc=0x0c091962u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c091964u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c091964u; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
