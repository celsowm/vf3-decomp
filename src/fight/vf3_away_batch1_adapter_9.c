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
int vf3_away_batch1_adapter_9(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c043eccu: goto P_0c043ecc;
case 0x0c043eceu: goto P_0c043ece;
case 0x0c043ed0u: goto P_0c043ed0;
case 0x0c043ed2u: goto P_0c043ed2;
case 0x0c043ed4u: goto P_0c043ed4;
case 0x0c043ed6u: goto P_0c043ed6;
case 0x0c043ed8u: goto P_0c043ed8;
case 0x0c0441b6u: goto P_0c0441b6;
case 0x0c0441b8u: goto P_0c0441b8;
case 0x0c0441bau: goto P_0c0441ba;
case 0x0c0441bcu: goto P_0c0441bc;
case 0x0c0441beu: goto P_0c0441be;
case 0x0c0441c0u: goto P_0c0441c0;
case 0x0c0441c2u: goto P_0c0441c2;
case 0x0c0441c4u: goto P_0c0441c4;
case 0x0c0441c6u: goto P_0c0441c6;
case 0x0c0441c8u: goto P_0c0441c8;
case 0x0c0441cau: goto P_0c0441ca;
case 0x0c0441ccu: goto P_0c0441cc;
case 0x0c0441ceu: goto P_0c0441ce;
case 0x0c0441d0u: goto P_0c0441d0;
case 0x0c0441d2u: goto P_0c0441d2;
case 0x0c0441d4u: goto P_0c0441d4;
case 0x0c0441d6u: goto P_0c0441d6;
case 0x0c0441d8u: goto P_0c0441d8;
case 0x0c0441dau: goto P_0c0441da;
case 0x0c0441dcu: goto P_0c0441dc;
case 0x0c0441deu: goto P_0c0441de;
case 0x0c0441e0u: goto P_0c0441e0;
case 0x0c0441e2u: goto P_0c0441e2;
case 0x0c0441e4u: goto P_0c0441e4;
case 0x0c0441e6u: goto P_0c0441e6;
case 0x0c0441e8u: goto P_0c0441e8;
case 0x0c0441eau: goto P_0c0441ea;
case 0x0c0441ecu: goto P_0c0441ec;
case 0x0c0441eeu: goto P_0c0441ee;
case 0x0c0441f0u: goto P_0c0441f0;
case 0x0c0441f2u: goto P_0c0441f2;
case 0x0c0441f4u: goto P_0c0441f4;
case 0x0c0441f6u: goto P_0c0441f6;
case 0x0c0441f8u: goto P_0c0441f8;
case 0x0c0441fau: goto P_0c0441fa;
case 0x0c0441fcu: goto P_0c0441fc;
case 0x0c0441feu: goto P_0c0441fe;
case 0x0c044200u: goto P_0c044200;
case 0x0c044202u: goto P_0c044202;
case 0x0c044204u: goto P_0c044204;
case 0x0c044206u: goto P_0c044206;
case 0x0c044208u: goto P_0c044208;
case 0x0c04420au: goto P_0c04420a;
case 0x0c04420cu: goto P_0c04420c;
case 0x0c04420eu: goto P_0c04420e;
case 0x0c044210u: goto P_0c044210;
case 0x0c044212u: goto P_0c044212;
case 0x0c044214u: goto P_0c044214;
case 0x0c044216u: goto P_0c044216;
case 0x0c044218u: goto P_0c044218;
case 0x0c04421au: goto P_0c04421a;
case 0x0c04421cu: goto P_0c04421c;
case 0x0c04421eu: goto P_0c04421e;
case 0x0c044220u: goto P_0c044220;
case 0x0c044222u: goto P_0c044222;
case 0x0c044224u: goto P_0c044224;
case 0x0c044226u: goto P_0c044226;
case 0x0c044228u: goto P_0c044228;
case 0x0c04422au: goto P_0c04422a;
case 0x0c04422cu: goto P_0c04422c;
case 0x0c04422eu: goto P_0c04422e;
case 0x0c045f34u: goto P_0c045f34;
case 0x0c045f36u: goto P_0c045f36;
case 0x0c045f38u: goto P_0c045f38;
case 0x0c045f3au: goto P_0c045f3a;
case 0x0c045f3cu: goto P_0c045f3c;
case 0x0c045f3eu: goto P_0c045f3e;
case 0x0c045f40u: goto P_0c045f40;
case 0x0c045f42u: goto P_0c045f42;
case 0x0c045f44u: goto P_0c045f44;
case 0x0c045f46u: goto P_0c045f46;
case 0x0c045f48u: goto P_0c045f48;
case 0x0c045f4au: goto P_0c045f4a;
case 0x0c045f4cu: goto P_0c045f4c;
case 0x0c045f4eu: goto P_0c045f4e;
case 0x0c045f50u: goto P_0c045f50;
case 0x0c045f52u: goto P_0c045f52;
case 0x0c045f54u: goto P_0c045f54;
case 0x0c045f56u: goto P_0c045f56;
case 0x0c045f58u: goto P_0c045f58;
case 0x0c045f5au: goto P_0c045f5a;
case 0x0c045f5cu: goto P_0c045f5c;
case 0x0c045f7eu: goto P_0c045f7e;
case 0x0c045f80u: goto P_0c045f80;
case 0x0c045f82u: goto P_0c045f82;
case 0x0c045f84u: goto P_0c045f84;
case 0x0c045f86u: goto P_0c045f86;
case 0x0c045f88u: goto P_0c045f88;
case 0x0c045f8au: goto P_0c045f8a;
case 0x0c045f8cu: goto P_0c045f8c;
case 0x0c045f8eu: goto P_0c045f8e;
case 0x0c045f90u: goto P_0c045f90;
case 0x0c045f92u: goto P_0c045f92;
case 0x0c045f94u: goto P_0c045f94;
case 0x0c045f96u: goto P_0c045f96;
case 0x0c045f98u: goto P_0c045f98;
case 0x0c045f9au: goto P_0c045f9a;
case 0x0c045f9cu: goto P_0c045f9c;
case 0x0c045f9eu: goto P_0c045f9e;
case 0x0c045fa0u: goto P_0c045fa0;
case 0x0c045fa2u: goto P_0c045fa2;
case 0x0c045fa4u: goto P_0c045fa4;
case 0x0c045fa6u: goto P_0c045fa6;
case 0x0c045fa8u: goto P_0c045fa8;
case 0x0c045faau: goto P_0c045faa;
case 0x0c045facu: goto P_0c045fac;
case 0x0c045faeu: goto P_0c045fae;
case 0x0c045fb0u: goto P_0c045fb0;
case 0x0c045fb2u: goto P_0c045fb2;
case 0x0c045fb4u: goto P_0c045fb4;
case 0x0c045fb6u: goto P_0c045fb6;
case 0x0c045fb8u: goto P_0c045fb8;
case 0x0c045fbau: goto P_0c045fba;
case 0x0c045fbcu: goto P_0c045fbc;
case 0x0c045fbeu: goto P_0c045fbe;
case 0x0c045fc0u: goto P_0c045fc0;
case 0x0c045fc2u: goto P_0c045fc2;
case 0x0c045fc4u: goto P_0c045fc4;
case 0x0c045fc6u: goto P_0c045fc6;
case 0x0c045fc8u: goto P_0c045fc8;
case 0x0c045fcau: goto P_0c045fca;
case 0x0c045fccu: goto P_0c045fcc;
case 0x0c045fceu: goto P_0c045fce;
case 0x0c045fd0u: goto P_0c045fd0;
case 0x0c045fd2u: goto P_0c045fd2;
case 0x0c045fd4u: goto P_0c045fd4;
case 0x0c045fd6u: goto P_0c045fd6;
case 0x0c045fd8u: goto P_0c045fd8;
case 0x0c045fdau: goto P_0c045fda;
case 0x0c045fdcu: goto P_0c045fdc;
case 0x0c045fdeu: goto P_0c045fde;
case 0x0c045fe0u: goto P_0c045fe0;
case 0x0c045fe2u: goto P_0c045fe2;
case 0x0c045fe4u: goto P_0c045fe4;
case 0x0c045fe6u: goto P_0c045fe6;
case 0x0c045fe8u: goto P_0c045fe8;
case 0x0c045feau: goto P_0c045fea;
case 0x0c045fecu: goto P_0c045fec;
case 0x0c045feeu: goto P_0c045fee;
case 0x0c045ff0u: goto P_0c045ff0;
case 0x0c045ff2u: goto P_0c045ff2;
case 0x0c045ff4u: goto P_0c045ff4;
case 0x0c045ff6u: goto P_0c045ff6;
case 0x0c045ff8u: goto P_0c045ff8;
case 0x0c045ffau: goto P_0c045ffa;
case 0x0c045ffcu: goto P_0c045ffc;
case 0x0c045ffeu: goto P_0c045ffe;
case 0x0c046180u: goto P_0c046180;
case 0x0c046182u: goto P_0c046182;
case 0x0c046184u: goto P_0c046184;
case 0x0c046186u: goto P_0c046186;
case 0x0c046188u: goto P_0c046188;
case 0x0c04618au: goto P_0c04618a;
case 0x0c04618cu: goto P_0c04618c;
case 0x0c04618eu: goto P_0c04618e;
case 0x0c046190u: goto P_0c046190;
case 0x0c046192u: goto P_0c046192;
case 0x0c046194u: goto P_0c046194;
case 0x0c046196u: goto P_0c046196;
case 0x0c046198u: goto P_0c046198;
case 0x0c04619au: goto P_0c04619a;
case 0x0c04619cu: goto P_0c04619c;
case 0x0c04619eu: goto P_0c04619e;
case 0x0c0461a0u: goto P_0c0461a0;
case 0x0c0461a2u: goto P_0c0461a2;
case 0x0c0461a4u: goto P_0c0461a4;
case 0x0c0461a6u: goto P_0c0461a6;
case 0x0c0461a8u: goto P_0c0461a8;
case 0x0c0461aau: goto P_0c0461aa;
case 0x0c0461acu: goto P_0c0461ac;
case 0x0c0461aeu: goto P_0c0461ae;
case 0x0c0461b0u: goto P_0c0461b0;
case 0x0c0461b2u: goto P_0c0461b2;
case 0x0c0461b4u: goto P_0c0461b4;
case 0x0c0461b6u: goto P_0c0461b6;
case 0x0c0461b8u: goto P_0c0461b8;
case 0x0c0461bau: goto P_0c0461ba;
case 0x0c0461bcu: goto P_0c0461bc;
case 0x0c0461beu: goto P_0c0461be;
case 0x0c0461c0u: goto P_0c0461c0;
case 0x0c0461c2u: goto P_0c0461c2;
case 0x0c0461c4u: goto P_0c0461c4;
case 0x0c0461c6u: goto P_0c0461c6;
case 0x0c0461c8u: goto P_0c0461c8;
case 0x0c0461cau: goto P_0c0461ca;
case 0x0c0461ccu: goto P_0c0461cc;
case 0x0c0461ceu: goto P_0c0461ce;
case 0x0c0461d0u: goto P_0c0461d0;
case 0x0c0461d2u: goto P_0c0461d2;
case 0x0c04621cu: goto P_0c04621c;
case 0x0c04621eu: goto P_0c04621e;
case 0x0c046220u: goto P_0c046220;
case 0x0c046222u: goto P_0c046222;
case 0x0c046224u: goto P_0c046224;
case 0x0c046226u: goto P_0c046226;
case 0x0c046228u: goto P_0c046228;
case 0x0c04622au: goto P_0c04622a;
case 0x0c04622cu: goto P_0c04622c;
case 0x0c04622eu: goto P_0c04622e;
case 0x0c046230u: goto P_0c046230;
case 0x0c046232u: goto P_0c046232;
case 0x0c046234u: goto P_0c046234;
case 0x0c046236u: goto P_0c046236;
case 0x0c046238u: goto P_0c046238;
case 0x0c04623au: goto P_0c04623a;
case 0x0c04623cu: goto P_0c04623c;
case 0x0c04623eu: goto P_0c04623e;
case 0x0c046240u: goto P_0c046240;
case 0x0c046242u: goto P_0c046242;
case 0x0c046244u: goto P_0c046244;
case 0x0c046246u: goto P_0c046246;
case 0x0c046248u: goto P_0c046248;
case 0x0c04624au: goto P_0c04624a;
case 0x0c04624cu: goto P_0c04624c;
case 0x0c04624eu: goto P_0c04624e;
case 0x0c046250u: goto P_0c046250;
case 0x0c046252u: goto P_0c046252;
case 0x0c046254u: goto P_0c046254;
case 0x0c046256u: goto P_0c046256;
case 0x0c046258u: goto P_0c046258;
case 0x0c04625au: goto P_0c04625a;
default: return vf3_matrix_family(target,s,ram);
}
P_0c043ecc: /* original 4f22, guest PC 0x0c043ecc */
if(!s->budget--) { s->failed_pc=0x0c043eccu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c043ece;
P_0c043ece: /* original d317, guest PC 0x0c043ece */
if(!s->budget--) { s->failed_pc=0x0c043eceu; return 0; }
r[3]=read(ram,0x0c043f2cu,4);
goto P_0c043ed0;
P_0c043ed0: /* original 430b, guest PC 0x0c043ed0 */
if(!s->budget--) { s->failed_pc=0x0c043ed0u; return 0; }
target=r[3];
r[16]=code_base|0x0c043ed4u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c043ed4u) { target=s->pc; goto dispatch; }
goto P_0c043ed4;
P_0c043ed2: /* original 0009, guest PC 0x0c043ed2 */
if(!s->budget--) { s->failed_pc=0x0c043ed2u; return 0; }
goto P_0c043ed4;
P_0c043ed4: /* original 4f26, guest PC 0x0c043ed4 */
if(!s->budget--) { s->failed_pc=0x0c043ed4u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c043ed6;
P_0c043ed6: /* original 000b, guest PC 0x0c043ed6 */
if(!s->budget--) { s->failed_pc=0x0c043ed6u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c043ed8: /* original 0009, guest PC 0x0c043ed8 */
if(!s->budget--) { s->failed_pc=0x0c043ed8u; return 0; }
if(!vf3_matrix_family(0x0c043edau,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c043edau; return 0; } return 1;
P_0c0441b6: /* original 6743, guest PC 0x0c0441b6 */
if(!s->budget--) { s->failed_pc=0x0c0441b6u; return 0; }
r[7]=r[4];
goto P_0c0441b8;
P_0c0441b8: /* original 2fc6, guest PC 0x0c0441b8 */
if(!s->budget--) { s->failed_pc=0x0c0441b8u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0441ba;
P_0c0441ba: /* original d63d, guest PC 0x0c0441ba */
if(!s->budget--) { s->failed_pc=0x0c0441bau; return 0; }
r[6]=read(ram,0x0c0442b0u,4);
goto P_0c0441bc;
P_0c0441bc: /* original e020, guest PC 0x0c0441bc */
if(!s->budget--) { s->failed_pc=0x0c0441bcu; return 0; }
r[0]=0x00000020u;
goto P_0c0441be;
P_0c0441be: /* original 6c46, guest PC 0x0c0441be */
if(!s->budget--) { s->failed_pc=0x0c0441beu; return 0; }
tmp=read(ram,r[4],4);
r[4]+=4;
r[12]=tmp;
goto P_0c0441c0;
P_0c0441c0: /* original 7704, guest PC 0x0c0441c0 */
if(!s->budget--) { s->failed_pc=0x0c0441c0u; return 0; }
r[7]+=0x00000004u;
goto P_0c0441c2;
P_0c0441c2: /* original e100, guest PC 0x0c0441c2 */
if(!s->budget--) { s->failed_pc=0x0c0441c2u; return 0; }
r[1]=0x00000000u;
goto P_0c0441c4;
P_0c0441c4: /* original 6363, guest PC 0x0c0441c4 */
if(!s->budget--) { s->failed_pc=0x0c0441c4u; return 0; }
r[3]=r[6];
goto P_0c0441c6;
P_0c0441c6: /* original 23c8, guest PC 0x0c0441c6 */
if(!s->budget--) { s->failed_pc=0x0c0441c6u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[12])==0)!=0);
goto P_0c0441c8;
P_0c0441c8: /* original 8906, guest PC 0x0c0441c8 */
if(!s->budget--) { s->failed_pc=0x0c0441c8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0441d8; }
goto P_0c0441ca;
P_0c0441ca: /* original 3560, guest PC 0x0c0441ca */
if(!s->budget--) { s->failed_pc=0x0c0441cau; return 0; }
r[17]=(r[17]&~1u)|((r[5]==r[6])!=0);
goto P_0c0441cc;
P_0c0441cc: /* original 8b02, guest PC 0x0c0441cc */
if(!s->budget--) { s->failed_pc=0x0c0441ccu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0441d4; }
goto P_0c0441ce;
P_0c0441ce: /* original 6073, guest PC 0x0c0441ce */
if(!s->budget--) { s->failed_pc=0x0c0441ceu; return 0; }
r[0]=r[7];
goto P_0c0441d0;
P_0c0441d0: /* original 000b, guest PC 0x0c0441d0 */
if(!s->budget--) { s->failed_pc=0x0c0441d0u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
s->pc=target; return ram->oob==0;
P_0c0441d2: /* original 6cf6, guest PC 0x0c0441d2 */
if(!s->budget--) { s->failed_pc=0x0c0441d2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0441d4;
P_0c0441d4: /* original 7404, guest PC 0x0c0441d4 */
if(!s->budget--) { s->failed_pc=0x0c0441d4u; return 0; }
r[4]+=0x00000004u;
goto P_0c0441d6;
P_0c0441d6: /* original 6743, guest PC 0x0c0441d6 */
if(!s->budget--) { s->failed_pc=0x0c0441d6u; return 0; }
r[7]=r[4];
goto P_0c0441d8;
P_0c0441d8: /* original 7101, guest PC 0x0c0441d8 */
if(!s->budget--) { s->failed_pc=0x0c0441d8u; return 0; }
r[1]+=0x00000001u;
goto P_0c0441da;
P_0c0441da: /* original 4601, guest PC 0x0c0441da */
if(!s->budget--) { s->failed_pc=0x0c0441dau; return 0; }
r[17]=(r[17]&~1u)|((r[6]&1)!=0);
r[6]>>=1;
goto P_0c0441dc;
P_0c0441dc: /* original 3102, guest PC 0x0c0441dc */
if(!s->budget--) { s->failed_pc=0x0c0441dcu; return 0; }
r[17]=(r[17]&~1u)|((r[1]>=r[0])!=0);
goto P_0c0441de;
P_0c0441de: /* original 8bf1, guest PC 0x0c0441de */
if(!s->budget--) { s->failed_pc=0x0c0441deu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0441c4; }
goto P_0c0441e0;
P_0c0441e0: /* original e000, guest PC 0x0c0441e0 */
if(!s->budget--) { s->failed_pc=0x0c0441e0u; return 0; }
r[0]=0x00000000u;
goto P_0c0441e2;
P_0c0441e2: /* original 000b, guest PC 0x0c0441e2 */
if(!s->budget--) { s->failed_pc=0x0c0441e2u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
s->pc=target; return ram->oob==0;
P_0c0441e4: /* original 6cf6, guest PC 0x0c0441e4 */
if(!s->budget--) { s->failed_pc=0x0c0441e4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0441e6;
P_0c0441e6: /* original 4f22, guest PC 0x0c0441e6 */
if(!s->budget--) { s->failed_pc=0x0c0441e6u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0441e8;
P_0c0441e8: /* original 7ff8, guest PC 0x0c0441e8 */
if(!s->budget--) { s->failed_pc=0x0c0441e8u; return 0; }
r[15]+=0xfffffff8u;
goto P_0c0441ea;
P_0c0441ea: /* original 2f42, guest PC 0x0c0441ea */
if(!s->budget--) { s->failed_pc=0x0c0441eau; return 0; }
write(ram,r[15],r[4],4);
goto P_0c0441ec;
P_0c0441ec: /* original 1f51, guest PC 0x0c0441ec */
if(!s->budget--) { s->failed_pc=0x0c0441ecu; return 0; }
write(ram,r[15]+4,r[5],4);
goto P_0c0441ee;
P_0c0441ee: /* original e501, guest PC 0x0c0441ee */
if(!s->budget--) { s->failed_pc=0x0c0441eeu; return 0; }
r[5]=0x00000001u;
goto P_0c0441f0;
P_0c0441f0: /* original bfe1, guest PC 0x0c0441f0 */
if(!s->budget--) { s->failed_pc=0x0c0441f0u; return 0; }
target=code_base|0x0c0441b6u; r[16]=code_base|0x0c0441f4u;
r[4]=read(ram,r[15]+4,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0441f4u) { target=s->pc; goto dispatch; }
goto P_0c0441f4;
P_0c0441f2: /* original 54f1, guest PC 0x0c0441f2 */
if(!s->budget--) { s->failed_pc=0x0c0441f2u; return 0; }
r[4]=read(ram,r[15]+4,4);
goto P_0c0441f4;
P_0c0441f4: /* original 6403, guest PC 0x0c0441f4 */
if(!s->budget--) { s->failed_pc=0x0c0441f4u; return 0; }
r[4]=r[0];
goto P_0c0441f6;
P_0c0441f6: /* original 2448, guest PC 0x0c0441f6 */
if(!s->budget--) { s->failed_pc=0x0c0441f6u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c0441f8;
P_0c0441f8: /* original 8b03, guest PC 0x0c0441f8 */
if(!s->budget--) { s->failed_pc=0x0c0441f8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c044202; }
goto P_0c0441fa;
P_0c0441fa: /* original 7f08, guest PC 0x0c0441fa */
if(!s->budget--) { s->failed_pc=0x0c0441fau; return 0; }
r[15]+=0x00000008u;
goto P_0c0441fc;
P_0c0441fc: /* original 4f26, guest PC 0x0c0441fc */
if(!s->budget--) { s->failed_pc=0x0c0441fcu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0441fe;
P_0c0441fe: /* original 000b, guest PC 0x0c0441fe */
if(!s->budget--) { s->failed_pc=0x0c0441feu; return 0; }
target=r[16];
r[0]=0xffffffffu;
s->pc=target; return ram->oob==0;
P_0c044200: /* original e0ff, guest PC 0x0c044200 */
if(!s->budget--) { s->failed_pc=0x0c044200u; return 0; }
r[0]=0xffffffffu;
goto P_0c044202;
P_0c044202: /* original 8441, guest PC 0x0c044202 */
if(!s->budget--) { s->failed_pc=0x0c044202u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+1,1);
goto P_0c044204;
P_0c044204: /* original 6140, guest PC 0x0c044204 */
if(!s->budget--) { s->failed_pc=0x0c044204u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[4],1);
r[1]=tmp;
goto P_0c044206;
P_0c044206: /* original 600c, guest PC 0x0c044206 */
if(!s->budget--) { s->failed_pc=0x0c044206u; return 0; }
r[0]=r[0]&255u;
goto P_0c044208;
P_0c044208: /* original 63f2, guest PC 0x0c044208 */
if(!s->budget--) { s->failed_pc=0x0c044208u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c04420a;
P_0c04420a: /* original 4028, guest PC 0x0c04420a */
if(!s->budget--) { s->failed_pc=0x0c04420au; return 0; }
r[0]<<=16;
goto P_0c04420c;
P_0c04420c: /* original 6203, guest PC 0x0c04420c */
if(!s->budget--) { s->failed_pc=0x0c04420cu; return 0; }
r[2]=r[0];
goto P_0c04420e;
P_0c04420e: /* original 8442, guest PC 0x0c04420e */
if(!s->budget--) { s->failed_pc=0x0c04420eu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+2,1);
goto P_0c044210;
P_0c044210: /* original 611c, guest PC 0x0c044210 */
if(!s->budget--) { s->failed_pc=0x0c044210u; return 0; }
r[1]=r[1]&255u;
goto P_0c044212;
P_0c044212: /* original 600c, guest PC 0x0c044212 */
if(!s->budget--) { s->failed_pc=0x0c044212u; return 0; }
r[0]=r[0]&255u;
goto P_0c044214;
P_0c044214: /* original 4018, guest PC 0x0c044214 */
if(!s->budget--) { s->failed_pc=0x0c044214u; return 0; }
r[0]<<=8;
goto P_0c044216;
P_0c044216: /* original 220b, guest PC 0x0c044216 */
if(!s->budget--) { s->failed_pc=0x0c044216u; return 0; }
r[2]|=r[0];
goto P_0c044218;
P_0c044218: /* original 8443, guest PC 0x0c044218 */
if(!s->budget--) { s->failed_pc=0x0c044218u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+3,1);
goto P_0c04421a;
P_0c04421a: /* original 4128, guest PC 0x0c04421a */
if(!s->budget--) { s->failed_pc=0x0c04421au; return 0; }
r[1]<<=16;
goto P_0c04421c;
P_0c04421c: /* original 4118, guest PC 0x0c04421c */
if(!s->budget--) { s->failed_pc=0x0c04421cu; return 0; }
r[1]<<=8;
goto P_0c04421e;
P_0c04421e: /* original 600c, guest PC 0x0c04421e */
if(!s->budget--) { s->failed_pc=0x0c04421eu; return 0; }
r[0]=r[0]&255u;
goto P_0c044220;
P_0c044220: /* original 221b, guest PC 0x0c044220 */
if(!s->budget--) { s->failed_pc=0x0c044220u; return 0; }
r[2]|=r[1];
goto P_0c044222;
P_0c044222: /* original 220b, guest PC 0x0c044222 */
if(!s->budget--) { s->failed_pc=0x0c044222u; return 0; }
r[2]|=r[0];
goto P_0c044224;
P_0c044224: /* original e000, guest PC 0x0c044224 */
if(!s->budget--) { s->failed_pc=0x0c044224u; return 0; }
r[0]=0x00000000u;
goto P_0c044226;
P_0c044226: /* original 2322, guest PC 0x0c044226 */
if(!s->budget--) { s->failed_pc=0x0c044226u; return 0; }
write(ram,r[3],r[2],4);
goto P_0c044228;
P_0c044228: /* original 7f08, guest PC 0x0c044228 */
if(!s->budget--) { s->failed_pc=0x0c044228u; return 0; }
r[15]+=0x00000008u;
goto P_0c04422a;
P_0c04422a: /* original 4f26, guest PC 0x0c04422a */
if(!s->budget--) { s->failed_pc=0x0c04422au; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c04422c;
P_0c04422c: /* original 000b, guest PC 0x0c04422c */
if(!s->budget--) { s->failed_pc=0x0c04422cu; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c04422e: /* original 0009, guest PC 0x0c04422e */
if(!s->budget--) { s->failed_pc=0x0c04422eu; return 0; }
if(!vf3_matrix_family(0x0c044230u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c044230u; return 0; } return 1;
P_0c045f34: /* original d439, guest PC 0x0c045f34 */
if(!s->budget--) { s->failed_pc=0x0c045f34u; return 0; }
r[4]=read(ram,0x0c04601cu,4);
goto P_0c045f36;
P_0c045f36: /* original e500, guest PC 0x0c045f36 */
if(!s->budget--) { s->failed_pc=0x0c045f36u; return 0; }
r[5]=0x00000000u;
goto P_0c045f38;
P_0c045f38: /* original e70d, guest PC 0x0c045f38 */
if(!s->budget--) { s->failed_pc=0x0c045f38u; return 0; }
r[7]=0x0000000du;
goto P_0c045f3a;
P_0c045f3a: /* original 6653, guest PC 0x0c045f3a */
if(!s->budget--) { s->failed_pc=0x0c045f3au; return 0; }
r[6]=r[5];
goto P_0c045f3c;
P_0c045f3c: /* original 7601, guest PC 0x0c045f3c */
if(!s->budget--) { s->failed_pc=0x0c045f3cu; return 0; }
r[6]+=0x00000001u;
goto P_0c045f3e;
P_0c045f3e: /* original 2452, guest PC 0x0c045f3e */
if(!s->budget--) { s->failed_pc=0x0c045f3eu; return 0; }
write(ram,r[4],r[5],4);
goto P_0c045f40;
P_0c045f40: /* original 3673, guest PC 0x0c045f40 */
if(!s->budget--) { s->failed_pc=0x0c045f40u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[6]>=(int32_t)r[7])!=0);
goto P_0c045f42;
P_0c045f42: /* original 8ffb, guest PC 0x0c045f42 */
if(!s->budget--) { s->failed_pc=0x0c045f42u; return 0; }
cond=r[17]&1u;
r[4]+=0x00000004u;
if(!cond) { goto P_0c045f3c; }
goto P_0c045f46;
P_0c045f44: /* original 7404, guest PC 0x0c045f44 */
if(!s->budget--) { s->failed_pc=0x0c045f44u; return 0; }
r[4]+=0x00000004u;
goto P_0c045f46;
P_0c045f46: /* original d237, guest PC 0x0c045f46 */
if(!s->budget--) { s->failed_pc=0x0c045f46u; return 0; }
r[2]=read(ram,0x0c046024u,4);
goto P_0c045f48;
P_0c045f48: /* original d435, guest PC 0x0c045f48 */
if(!s->budget--) { s->failed_pc=0x0c045f48u; return 0; }
r[4]=read(ram,0x0c046020u,4);
goto P_0c045f4a;
P_0c045f4a: /* original 2242, guest PC 0x0c045f4a */
if(!s->budget--) { s->failed_pc=0x0c045f4au; return 0; }
write(ram,r[2],r[4],4);
goto P_0c045f4c;
P_0c045f4c: /* original 9664, guest PC 0x0c045f4c */
if(!s->budget--) { s->failed_pc=0x0c045f4cu; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c046018u,2);
goto P_0c045f4e;
P_0c045f4e: /* original 6343, guest PC 0x0c045f4e */
if(!s->budget--) { s->failed_pc=0x0c045f4eu; return 0; }
r[3]=r[4];
goto P_0c045f50;
P_0c045f50: /* original 7310, guest PC 0x0c045f50 */
if(!s->budget--) { s->failed_pc=0x0c045f50u; return 0; }
r[3]+=0x00000010u;
goto P_0c045f52;
P_0c045f52: /* original 4610, guest PC 0x0c045f52 */
if(!s->budget--) { s->failed_pc=0x0c045f52u; return 0; }
--r[6];
r[17]=(r[17]&~1u)|((r[6]==0)!=0);
goto P_0c045f54;
P_0c045f54: /* original 1431, guest PC 0x0c045f54 */
if(!s->budget--) { s->failed_pc=0x0c045f54u; return 0; }
write(ram,r[4]+4,r[3],4);
goto P_0c045f56;
P_0c045f56: /* original 8ffa, guest PC 0x0c045f56 */
if(!s->budget--) { s->failed_pc=0x0c045f56u; return 0; }
cond=r[17]&1u;
r[4]+=0x00000010u;
if(!cond) { goto P_0c045f4e; }
goto P_0c045f5a;
P_0c045f58: /* original 7410, guest PC 0x0c045f58 */
if(!s->budget--) { s->failed_pc=0x0c045f58u; return 0; }
r[4]+=0x00000010u;
goto P_0c045f5a;
P_0c045f5a: /* original 000b, guest PC 0x0c045f5a */
if(!s->budget--) { s->failed_pc=0x0c045f5au; return 0; }
target=r[16];
write(ram,r[4]+4,r[5],4);
s->pc=target; return ram->oob==0;
P_0c045f5c: /* original 1451, guest PC 0x0c045f5c */
if(!s->budget--) { s->failed_pc=0x0c045f5cu; return 0; }
write(ram,r[4]+4,r[5],4);
if(!vf3_matrix_family(0x0c045f5eu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c045f5eu; return 0; } return 1;
P_0c045f7e: /* original d52a, guest PC 0x0c045f7e */
if(!s->budget--) { s->failed_pc=0x0c045f7eu; return 0; }
r[5]=read(ram,0x0c046028u,4);
goto P_0c045f80;
P_0c045f80: /* original e70d, guest PC 0x0c045f80 */
if(!s->budget--) { s->failed_pc=0x0c045f80u; return 0; }
r[7]=0x0000000du;
goto P_0c045f82;
P_0c045f82: /* original e600, guest PC 0x0c045f82 */
if(!s->budget--) { s->failed_pc=0x0c045f82u; return 0; }
r[6]=0x00000000u;
goto P_0c045f84;
P_0c045f84: /* original 6351, guest PC 0x0c045f84 */
if(!s->budget--) { s->failed_pc=0x0c045f84u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[5],2);
r[3]=tmp;
goto P_0c045f86;
P_0c045f86: /* original 624f, guest PC 0x0c045f86 */
if(!s->budget--) { s->failed_pc=0x0c045f86u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)r[4];
goto P_0c045f88;
P_0c045f88: /* original 3320, guest PC 0x0c045f88 */
if(!s->budget--) { s->failed_pc=0x0c045f88u; return 0; }
r[17]=(r[17]&~1u)|((r[3]==r[2])!=0);
goto P_0c045f8a;
P_0c045f8a: /* original 8b01, guest PC 0x0c045f8a */
if(!s->budget--) { s->failed_pc=0x0c045f8au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c045f90; }
goto P_0c045f8c;
P_0c045f8c: /* original 000b, guest PC 0x0c045f8c */
if(!s->budget--) { s->failed_pc=0x0c045f8cu; return 0; }
target=r[16];
r[0]=r[5];
s->pc=target; return ram->oob==0;
P_0c045f8e: /* original 6053, guest PC 0x0c045f8e */
if(!s->budget--) { s->failed_pc=0x0c045f8eu; return 0; }
r[0]=r[5];
goto P_0c045f90;
P_0c045f90: /* original 7601, guest PC 0x0c045f90 */
if(!s->budget--) { s->failed_pc=0x0c045f90u; return 0; }
r[6]+=0x00000001u;
goto P_0c045f92;
P_0c045f92: /* original 3672, guest PC 0x0c045f92 */
if(!s->budget--) { s->failed_pc=0x0c045f92u; return 0; }
r[17]=(r[17]&~1u)|((r[6]>=r[7])!=0);
goto P_0c045f94;
P_0c045f94: /* original 8ff6, guest PC 0x0c045f94 */
if(!s->budget--) { s->failed_pc=0x0c045f94u; return 0; }
cond=r[17]&1u;
r[5]+=0x00000008u;
if(!cond) { goto P_0c045f84; }
goto P_0c045f98;
P_0c045f96: /* original 7508, guest PC 0x0c045f96 */
if(!s->budget--) { s->failed_pc=0x0c045f96u; return 0; }
r[5]+=0x00000008u;
goto P_0c045f98;
P_0c045f98: /* original e000, guest PC 0x0c045f98 */
if(!s->budget--) { s->failed_pc=0x0c045f98u; return 0; }
r[0]=0x00000000u;
goto P_0c045f9a;
P_0c045f9a: /* original 000b, guest PC 0x0c045f9a */
if(!s->budget--) { s->failed_pc=0x0c045f9au; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c045f9c: /* original 0009, guest PC 0x0c045f9c */
if(!s->budget--) { s->failed_pc=0x0c045f9cu; return 0; }
goto P_0c045f9e;
P_0c045f9e: /* original 2fe6, guest PC 0x0c045f9e */
if(!s->budget--) { s->failed_pc=0x0c045f9eu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c045fa0;
P_0c045fa0: /* original d320, guest PC 0x0c045fa0 */
if(!s->budget--) { s->failed_pc=0x0c045fa0u; return 0; }
r[3]=read(ram,0x0c046024u,4);
goto P_0c045fa2;
P_0c045fa2: /* original 6e32, guest PC 0x0c045fa2 */
if(!s->budget--) { s->failed_pc=0x0c045fa2u; return 0; }
tmp=read(ram,r[3],4);
r[14]=tmp;
goto P_0c045fa4;
P_0c045fa4: /* original 2ee8, guest PC 0x0c045fa4 */
if(!s->budget--) { s->failed_pc=0x0c045fa4u; return 0; }
r[17]=(r[17]&~1u)|(((r[14]&r[14])==0)!=0);
goto P_0c045fa6;
P_0c045fa6: /* original 8b02, guest PC 0x0c045fa6 */
if(!s->budget--) { s->failed_pc=0x0c045fa6u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c045fae; }
goto P_0c045fa8;
P_0c045fa8: /* original e000, guest PC 0x0c045fa8 */
if(!s->budget--) { s->failed_pc=0x0c045fa8u; return 0; }
r[0]=0x00000000u;
goto P_0c045faa;
P_0c045faa: /* original 000b, guest PC 0x0c045faa */
if(!s->budget--) { s->failed_pc=0x0c045faau; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c045fac: /* original 6ef6, guest PC 0x0c045fac */
if(!s->budget--) { s->failed_pc=0x0c045facu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c045fae;
P_0c045fae: /* original d21d, guest PC 0x0c045fae */
if(!s->budget--) { s->failed_pc=0x0c045faeu; return 0; }
r[2]=read(ram,0x0c046024u,4);
goto P_0c045fb0;
P_0c045fb0: /* original 2668, guest PC 0x0c045fb0 */
if(!s->budget--) { s->failed_pc=0x0c045fb0u; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[6])==0)!=0);
goto P_0c045fb2;
P_0c045fb2: /* original 53e1, guest PC 0x0c045fb2 */
if(!s->budget--) { s->failed_pc=0x0c045fb2u; return 0; }
r[3]=read(ram,r[14]+4,4);
goto P_0c045fb4;
P_0c045fb4: /* original 8f01, guest PC 0x0c045fb4 */
if(!s->budget--) { s->failed_pc=0x0c045fb4u; return 0; }
cond=r[17]&1u;
write(ram,r[2],r[3],4);
if(!cond) { goto P_0c045fba; }
goto P_0c045fb8;
P_0c045fb6: /* original 2232, guest PC 0x0c045fb6 */
if(!s->budget--) { s->failed_pc=0x0c045fb6u; return 0; }
write(ram,r[2],r[3],4);
goto P_0c045fb8;
P_0c045fb8: /* original e601, guest PC 0x0c045fb8 */
if(!s->budget--) { s->failed_pc=0x0c045fb8u; return 0; }
r[6]=0x00000001u;
goto P_0c045fba;
P_0c045fba: /* original d31c, guest PC 0x0c045fba */
if(!s->budget--) { s->failed_pc=0x0c045fbau; return 0; }
r[3]=read(ram,0x0c04602cu,4);
goto P_0c045fbc;
P_0c045fbc: /* original 3632, guest PC 0x0c045fbc */
if(!s->budget--) { s->failed_pc=0x0c045fbcu; return 0; }
r[17]=(r[17]&~1u)|((r[6]>=r[3])!=0);
goto P_0c045fbe;
P_0c045fbe: /* original 8f01, guest PC 0x0c045fbe */
if(!s->budget--) { s->failed_pc=0x0c045fbeu; return 0; }
cond=r[17]&1u;
write(ram,r[14],r[5],4);
if(!cond) { goto P_0c045fc4; }
goto P_0c045fc2;
P_0c045fc0: /* original 2e52, guest PC 0x0c045fc0 */
if(!s->budget--) { s->failed_pc=0x0c045fc0u; return 0; }
write(ram,r[14],r[5],4);
goto P_0c045fc2;
P_0c045fc2: /* original d61b, guest PC 0x0c045fc2 */
if(!s->budget--) { s->failed_pc=0x0c045fc2u; return 0; }
r[6]=read(ram,0x0c046030u,4);
goto P_0c045fc4;
P_0c045fc4: /* original e300, guest PC 0x0c045fc4 */
if(!s->budget--) { s->failed_pc=0x0c045fc4u; return 0; }
r[3]=0x00000000u;
goto P_0c045fc6;
P_0c045fc6: /* original 6243, guest PC 0x0c045fc6 */
if(!s->budget--) { s->failed_pc=0x0c045fc6u; return 0; }
r[2]=r[4];
goto P_0c045fc8;
P_0c045fc8: /* original 1e31, guest PC 0x0c045fc8 */
if(!s->budget--) { s->failed_pc=0x0c045fc8u; return 0; }
write(ram,r[14]+4,r[3],4);
goto P_0c045fca;
P_0c045fca: /* original 4228, guest PC 0x0c045fca */
if(!s->budget--) { s->failed_pc=0x0c045fcau; return 0; }
r[2]<<=16;
goto P_0c045fcc;
P_0c045fcc: /* original 1e72, guest PC 0x0c045fcc */
if(!s->budget--) { s->failed_pc=0x0c045fccu; return 0; }
write(ram,r[14]+8,r[7],4);
goto P_0c045fce;
P_0c045fce: /* original 6743, guest PC 0x0c045fce */
if(!s->budget--) { s->failed_pc=0x0c045fceu; return 0; }
r[7]=r[4];
goto P_0c045fd0;
P_0c045fd0: /* original 4708, guest PC 0x0c045fd0 */
if(!s->budget--) { s->failed_pc=0x0c045fd0u; return 0; }
r[7]<<=2;
goto P_0c045fd2;
P_0c045fd2: /* original 226b, guest PC 0x0c045fd2 */
if(!s->budget--) { s->failed_pc=0x0c045fd2u; return 0; }
r[2]|=r[6];
goto P_0c045fd4;
P_0c045fd4: /* original 1e23, guest PC 0x0c045fd4 */
if(!s->budget--) { s->failed_pc=0x0c045fd4u; return 0; }
write(ram,r[14]+12,r[2],4);
goto P_0c045fd6;
P_0c045fd6: /* original d311, guest PC 0x0c045fd6 */
if(!s->budget--) { s->failed_pc=0x0c045fd6u; return 0; }
r[3]=read(ram,0x0c04601cu,4);
goto P_0c045fd8;
P_0c045fd8: /* original 373c, guest PC 0x0c045fd8 */
if(!s->budget--) { s->failed_pc=0x0c045fd8u; return 0; }
r[7]+=r[3];
goto P_0c045fda;
P_0c045fda: /* original 6572, guest PC 0x0c045fda */
if(!s->budget--) { s->failed_pc=0x0c045fdau; return 0; }
tmp=read(ram,r[7],4);
r[5]=tmp;
goto P_0c045fdc;
P_0c045fdc: /* original 2558, guest PC 0x0c045fdc */
if(!s->budget--) { s->failed_pc=0x0c045fdcu; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[5])==0)!=0);
goto P_0c045fde;
P_0c045fde: /* original 8b02, guest PC 0x0c045fde */
if(!s->budget--) { s->failed_pc=0x0c045fdeu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c045fe6; }
goto P_0c045fe0;
P_0c045fe0: /* original a00b, guest PC 0x0c045fe0 */
if(!s->budget--) { s->failed_pc=0x0c045fe0u; return 0; }
write(ram,r[7],r[14],4);
goto P_0c045ffa;
P_0c045fe2: /* original 27e2, guest PC 0x0c045fe2 */
if(!s->budget--) { s->failed_pc=0x0c045fe2u; return 0; }
write(ram,r[7],r[14],4);
goto P_0c045fe4;
P_0c045fe4: /* original 5551, guest PC 0x0c045fe4 */
if(!s->budget--) { s->failed_pc=0x0c045fe4u; return 0; }
r[5]=read(ram,r[5]+4,4);
goto P_0c045fe6;
P_0c045fe6: /* original 5353, guest PC 0x0c045fe6 */
if(!s->budget--) { s->failed_pc=0x0c045fe6u; return 0; }
r[3]=read(ram,r[5]+12,4);
goto P_0c045fe8;
P_0c045fe8: /* original 633d, guest PC 0x0c045fe8 */
if(!s->budget--) { s->failed_pc=0x0c045fe8u; return 0; }
r[3]=r[3]&65535u;
goto P_0c045fea;
P_0c045fea: /* original 3362, guest PC 0x0c045fea */
if(!s->budget--) { s->failed_pc=0x0c045feau; return 0; }
r[17]=(r[17]&~1u)|((r[3]>=r[6])!=0);
goto P_0c045fec;
P_0c045fec: /* original 8902, guest PC 0x0c045fec */
if(!s->budget--) { s->failed_pc=0x0c045fecu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c045ff4; }
goto P_0c045fee;
P_0c045fee: /* original 5351, guest PC 0x0c045fee */
if(!s->budget--) { s->failed_pc=0x0c045feeu; return 0; }
r[3]=read(ram,r[5]+4,4);
goto P_0c045ff0;
P_0c045ff0: /* original 2338, guest PC 0x0c045ff0 */
if(!s->budget--) { s->failed_pc=0x0c045ff0u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c045ff2;
P_0c045ff2: /* original 8bf7, guest PC 0x0c045ff2 */
if(!s->budget--) { s->failed_pc=0x0c045ff2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c045fe4; }
goto P_0c045ff4;
P_0c045ff4: /* original 5351, guest PC 0x0c045ff4 */
if(!s->budget--) { s->failed_pc=0x0c045ff4u; return 0; }
r[3]=read(ram,r[5]+4,4);
goto P_0c045ff6;
P_0c045ff6: /* original 1e31, guest PC 0x0c045ff6 */
if(!s->budget--) { s->failed_pc=0x0c045ff6u; return 0; }
write(ram,r[14]+4,r[3],4);
goto P_0c045ff8;
P_0c045ff8: /* original 15e1, guest PC 0x0c045ff8 */
if(!s->budget--) { s->failed_pc=0x0c045ff8u; return 0; }
write(ram,r[5]+4,r[14],4);
goto P_0c045ffa;
P_0c045ffa: /* original 50e3, guest PC 0x0c045ffa */
if(!s->budget--) { s->failed_pc=0x0c045ffau; return 0; }
r[0]=read(ram,r[14]+12,4);
goto P_0c045ffc;
P_0c045ffc: /* original 000b, guest PC 0x0c045ffc */
if(!s->budget--) { s->failed_pc=0x0c045ffcu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c045ffe: /* original 6ef6, guest PC 0x0c045ffe */
if(!s->budget--) { s->failed_pc=0x0c045ffeu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c046000u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c046000u; return 0; } return 1;
P_0c046180: /* original 0002, guest PC 0x0c046180 */
if(!s->budget--) { s->failed_pc=0x0c046180u; return 0; }
r[0]=r[17];
goto P_0c046182;
P_0c046182: /* original 4f22, guest PC 0x0c046182 */
if(!s->budget--) { s->failed_pc=0x0c046182u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c046184;
P_0c046184: /* original 4009, guest PC 0x0c046184 */
if(!s->budget--) { s->failed_pc=0x0c046184u; return 0; }
r[0]>>=2;
goto P_0c046186;
P_0c046186: /* original 4009, guest PC 0x0c046186 */
if(!s->budget--) { s->failed_pc=0x0c046186u; return 0; }
r[0]>>=2;
goto P_0c046188;
P_0c046188: /* original c90f, guest PC 0x0c046188 */
if(!s->budget--) { s->failed_pc=0x0c046188u; return 0; }
r[0]&=15u;
goto P_0c04618a;
P_0c04618a: /* original 7ffc, guest PC 0x0c04618a */
if(!s->budget--) { s->failed_pc=0x0c04618au; return 0; }
r[15]+=0xfffffffcu;
goto P_0c04618c;
P_0c04618c: /* original 2f02, guest PC 0x0c04618c */
if(!s->budget--) { s->failed_pc=0x0c04618cu; return 0; }
write(ram,r[15],r[0],4);
goto P_0c04618e;
P_0c04618e: /* original 0002, guest PC 0x0c04618e */
if(!s->budget--) { s->failed_pc=0x0c04618eu; return 0; }
r[0]=r[17];
goto P_0c046190;
P_0c046190: /* original 9320, guest PC 0x0c046190 */
if(!s->budget--) { s->failed_pc=0x0c046190u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0461d4u,2);
goto P_0c046192;
P_0c046192: /* original 2039, guest PC 0x0c046192 */
if(!s->budget--) { s->failed_pc=0x0c046192u; return 0; }
r[0]&=r[3];
goto P_0c046194;
P_0c046194: /* original cbe0, guest PC 0x0c046194 */
if(!s->budget--) { s->failed_pc=0x0c046194u; return 0; }
r[0]|=224u;
goto P_0c046196;
P_0c046196: /* original 400e, guest PC 0x0c046196 */
if(!s->budget--) { s->failed_pc=0x0c046196u; return 0; }
r[17]=r[0];
goto P_0c046198;
P_0c046198: /* original becc, guest PC 0x0c046198 */
if(!s->budget--) { s->failed_pc=0x0c046198u; return 0; }
target=code_base|0x0c045f34u; r[16]=code_base|0x0c04619cu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04619cu) { target=s->pc; goto dispatch; }
goto P_0c04619c;
P_0c04619a: /* original 0009, guest PC 0x0c04619a */
if(!s->budget--) { s->failed_pc=0x0c04619au; return 0; }
goto P_0c04619c;
P_0c04619c: /* original d31b, guest PC 0x0c04619c */
if(!s->budget--) { s->failed_pc=0x0c04619cu; return 0; }
r[3]=read(ram,0x0c04620cu,4);
goto P_0c04619e;
P_0c04619e: /* original 941d, guest PC 0x0c04619e */
if(!s->budget--) { s->failed_pc=0x0c04619eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0461dcu,2);
goto P_0c0461a0;
P_0c0461a0: /* original d519, guest PC 0x0c0461a0 */
if(!s->budget--) { s->failed_pc=0x0c0461a0u; return 0; }
r[5]=read(ram,0x0c046208u,4);
goto P_0c0461a2;
P_0c0461a2: /* original 430b, guest PC 0x0c0461a2 */
if(!s->budget--) { s->failed_pc=0x0c0461a2u; return 0; }
target=r[3];
r[16]=code_base|0x0c0461a6u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0461a6u) { target=s->pc; goto dispatch; }
goto P_0c0461a6;
P_0c0461a4: /* original 0009, guest PC 0x0c0461a4 */
if(!s->budget--) { s->failed_pc=0x0c0461a4u; return 0; }
goto P_0c0461a6;
P_0c0461a6: /* original d21b, guest PC 0x0c0461a6 */
if(!s->budget--) { s->failed_pc=0x0c0461a6u; return 0; }
r[2]=read(ram,0x0c046214u,4);
goto P_0c0461a8;
P_0c0461a8: /* original d419, guest PC 0x0c0461a8 */
if(!s->budget--) { s->failed_pc=0x0c0461a8u; return 0; }
r[4]=read(ram,0x0c046210u,4);
goto P_0c0461aa;
P_0c0461aa: /* original 420b, guest PC 0x0c0461aa */
if(!s->budget--) { s->failed_pc=0x0c0461aau; return 0; }
target=r[2];
r[16]=code_base|0x0c0461aeu;
r[5]=0x00000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0461aeu) { target=s->pc; goto dispatch; }
goto P_0c0461ae;
P_0c0461ac: /* original e500, guest PC 0x0c0461ac */
if(!s->budget--) { s->failed_pc=0x0c0461acu; return 0; }
r[5]=0x00000000u;
goto P_0c0461ae;
P_0c0461ae: /* original 2008, guest PC 0x0c0461ae */
if(!s->budget--) { s->failed_pc=0x0c0461aeu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c0461b0;
P_0c0461b0: /* original 8900, guest PC 0x0c0461b0 */
if(!s->budget--) { s->failed_pc=0x0c0461b0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0461b4; }
goto P_0c0461b2;
P_0c0461b2: /* original c331, guest PC 0x0c0461b2 */
if(!s->budget--) { s->failed_pc=0x0c0461b2u; return 0; }
s->failed_pc=0x0c0461b2u; return 0;
goto P_0c0461b4;
P_0c0461b4: /* original d318, guest PC 0x0c0461b4 */
if(!s->budget--) { s->failed_pc=0x0c0461b4u; return 0; }
r[3]=read(ram,0x0c046218u,4);
goto P_0c0461b6;
P_0c0461b6: /* original e200, guest PC 0x0c0461b6 */
if(!s->budget--) { s->failed_pc=0x0c0461b6u; return 0; }
r[2]=0x00000000u;
goto P_0c0461b8;
P_0c0461b8: /* original 0102, guest PC 0x0c0461b8 */
if(!s->budget--) { s->failed_pc=0x0c0461b8u; return 0; }
r[1]=r[17];
goto P_0c0461ba;
P_0c0461ba: /* original 2322, guest PC 0x0c0461ba */
if(!s->budget--) { s->failed_pc=0x0c0461bau; return 0; }
write(ram,r[3],r[2],4);
goto P_0c0461bc;
P_0c0461bc: /* original 60f2, guest PC 0x0c0461bc */
if(!s->budget--) { s->failed_pc=0x0c0461bcu; return 0; }
tmp=read(ram,r[15],4);
r[0]=tmp;
goto P_0c0461be;
P_0c0461be: /* original 9209, guest PC 0x0c0461be */
if(!s->budget--) { s->failed_pc=0x0c0461beu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0461d4u,2);
goto P_0c0461c0;
P_0c0461c0: /* original c90f, guest PC 0x0c0461c0 */
if(!s->budget--) { s->failed_pc=0x0c0461c0u; return 0; }
r[0]&=15u;
goto P_0c0461c2;
P_0c0461c2: /* original 4008, guest PC 0x0c0461c2 */
if(!s->budget--) { s->failed_pc=0x0c0461c2u; return 0; }
r[0]<<=2;
goto P_0c0461c4;
P_0c0461c4: /* original 2129, guest PC 0x0c0461c4 */
if(!s->budget--) { s->failed_pc=0x0c0461c4u; return 0; }
r[1]&=r[2];
goto P_0c0461c6;
P_0c0461c6: /* original 4008, guest PC 0x0c0461c6 */
if(!s->budget--) { s->failed_pc=0x0c0461c6u; return 0; }
r[0]<<=2;
goto P_0c0461c8;
P_0c0461c8: /* original 201b, guest PC 0x0c0461c8 */
if(!s->budget--) { s->failed_pc=0x0c0461c8u; return 0; }
r[0]|=r[1];
goto P_0c0461ca;
P_0c0461ca: /* original 400e, guest PC 0x0c0461ca */
if(!s->budget--) { s->failed_pc=0x0c0461cau; return 0; }
r[17]=r[0];
goto P_0c0461cc;
P_0c0461cc: /* original 7f04, guest PC 0x0c0461cc */
if(!s->budget--) { s->failed_pc=0x0c0461ccu; return 0; }
r[15]+=0x00000004u;
goto P_0c0461ce;
P_0c0461ce: /* original 4f26, guest PC 0x0c0461ce */
if(!s->budget--) { s->failed_pc=0x0c0461ceu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0461d0;
P_0c0461d0: /* original 000b, guest PC 0x0c0461d0 */
if(!s->budget--) { s->failed_pc=0x0c0461d0u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c0461d2: /* original 0009, guest PC 0x0c0461d2 */
if(!s->budget--) { s->failed_pc=0x0c0461d2u; return 0; }
if(!vf3_matrix_family(0x0c0461d4u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0461d4u; return 0; } return 1;
P_0c04621c: /* original 0002, guest PC 0x0c04621c */
if(!s->budget--) { s->failed_pc=0x0c04621cu; return 0; }
r[0]=r[17];
goto P_0c04621e;
P_0c04621e: /* original 2fe6, guest PC 0x0c04621e */
if(!s->budget--) { s->failed_pc=0x0c04621eu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c046220;
P_0c046220: /* original 4f22, guest PC 0x0c046220 */
if(!s->budget--) { s->failed_pc=0x0c046220u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c046222;
P_0c046222: /* original 4009, guest PC 0x0c046222 */
if(!s->budget--) { s->failed_pc=0x0c046222u; return 0; }
r[0]>>=2;
goto P_0c046224;
P_0c046224: /* original 4009, guest PC 0x0c046224 */
if(!s->budget--) { s->failed_pc=0x0c046224u; return 0; }
r[0]>>=2;
goto P_0c046226;
P_0c046226: /* original 7fec, guest PC 0x0c046226 */
if(!s->budget--) { s->failed_pc=0x0c046226u; return 0; }
r[15]+=0xffffffecu;
goto P_0c046228;
P_0c046228: /* original c90f, guest PC 0x0c046228 */
if(!s->budget--) { s->failed_pc=0x0c046228u; return 0; }
r[0]&=15u;
goto P_0c04622a;
P_0c04622a: /* original 2f41, guest PC 0x0c04622a */
if(!s->budget--) { s->failed_pc=0x0c04622au; return 0; }
write(ram,r[15],r[4],2);
goto P_0c04622c;
P_0c04622c: /* original 1f51, guest PC 0x0c04622c */
if(!s->budget--) { s->failed_pc=0x0c04622cu; return 0; }
write(ram,r[15]+4,r[5],4);
goto P_0c04622e;
P_0c04622e: /* original 1f63, guest PC 0x0c04622e */
if(!s->budget--) { s->failed_pc=0x0c04622eu; return 0; }
write(ram,r[15]+12,r[6],4);
goto P_0c046230;
P_0c046230: /* original 1f72, guest PC 0x0c046230 */
if(!s->budget--) { s->failed_pc=0x0c046230u; return 0; }
write(ram,r[15]+8,r[7],4);
goto P_0c046232;
P_0c046232: /* original 1f04, guest PC 0x0c046232 */
if(!s->budget--) { s->failed_pc=0x0c046232u; return 0; }
write(ram,r[15]+16,r[0],4);
goto P_0c046234;
P_0c046234: /* original 0002, guest PC 0x0c046234 */
if(!s->budget--) { s->failed_pc=0x0c046234u; return 0; }
r[0]=r[17];
goto P_0c046236;
P_0c046236: /* original 9336, guest PC 0x0c046236 */
if(!s->budget--) { s->failed_pc=0x0c046236u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0462a6u,2);
goto P_0c046238;
P_0c046238: /* original 2039, guest PC 0x0c046238 */
if(!s->budget--) { s->failed_pc=0x0c046238u; return 0; }
r[0]&=r[3];
goto P_0c04623a;
P_0c04623a: /* original cbe0, guest PC 0x0c04623a */
if(!s->budget--) { s->failed_pc=0x0c04623au; return 0; }
r[0]|=224u;
goto P_0c04623c;
P_0c04623c: /* original 400e, guest PC 0x0c04623c */
if(!s->budget--) { s->failed_pc=0x0c04623cu; return 0; }
r[17]=r[0];
goto P_0c04623e;
P_0c04623e: /* original d41a, guest PC 0x0c04623e */
if(!s->budget--) { s->failed_pc=0x0c04623eu; return 0; }
r[4]=read(ram,0x0c0462a8u,4);
goto P_0c046240;
P_0c046240: /* original 6242, guest PC 0x0c046240 */
if(!s->budget--) { s->failed_pc=0x0c046240u; return 0; }
tmp=read(ram,r[4],4);
r[2]=tmp;
goto P_0c046242;
P_0c046242: /* original 2228, guest PC 0x0c046242 */
if(!s->budget--) { s->failed_pc=0x0c046242u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c046244;
P_0c046244: /* original 8902, guest PC 0x0c046244 */
if(!s->budget--) { s->failed_pc=0x0c046244u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04624c; }
goto P_0c046246;
P_0c046246: /* original e300, guest PC 0x0c046246 */
if(!s->budget--) { s->failed_pc=0x0c046246u; return 0; }
r[3]=0x00000000u;
goto P_0c046248;
P_0c046248: /* original bf9a, guest PC 0x0c046248 */
if(!s->budget--) { s->failed_pc=0x0c046248u; return 0; }
target=code_base|0x0c046180u; r[16]=code_base|0x0c04624cu;
write(ram,r[4],r[3],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04624cu) { target=s->pc; goto dispatch; }
goto P_0c04624c;
P_0c04624a: /* original 2432, guest PC 0x0c04624a */
if(!s->budget--) { s->failed_pc=0x0c04624au; return 0; }
write(ram,r[4],r[3],4);
goto P_0c04624c;
P_0c04624c: /* original 51f1, guest PC 0x0c04624c */
if(!s->budget--) { s->failed_pc=0x0c04624cu; return 0; }
r[1]=read(ram,r[15]+4,4);
goto P_0c04624e;
P_0c04624e: /* original 2118, guest PC 0x0c04624e */
if(!s->budget--) { s->failed_pc=0x0c04624eu; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[1])==0)!=0);
goto P_0c046250;
P_0c046250: /* original 8b04, guest PC 0x0c046250 */
if(!s->budget--) { s->failed_pc=0x0c046250u; return 0; }
cond=r[17]&1u;
if(!cond) { return vf3_matrix_family(0x0c04625cu,s,ram); }
goto P_0c046252;
P_0c046252: /* original 7f14, guest PC 0x0c046252 */
if(!s->budget--) { s->failed_pc=0x0c046252u; return 0; }
r[15]+=0x00000014u;
goto P_0c046254;
P_0c046254: /* original 4f26, guest PC 0x0c046254 */
if(!s->budget--) { s->failed_pc=0x0c046254u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c046256;
P_0c046256: /* original e000, guest PC 0x0c046256 */
if(!s->budget--) { s->failed_pc=0x0c046256u; return 0; }
r[0]=0x00000000u;
goto P_0c046258;
P_0c046258: /* original 000b, guest PC 0x0c046258 */
if(!s->budget--) { s->failed_pc=0x0c046258u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c04625a: /* original 6ef6, guest PC 0x0c04625a */
if(!s->budget--) { s->failed_pc=0x0c04625au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c04625cu,s,ram);
unsupported: s->failed_pc=target; return 0;
}
