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
int vf3_away_batch8_adapter_16(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c063f86u: goto P_0c063f86;
case 0x0c063f88u: goto P_0c063f88;
case 0x0c063f8au: goto P_0c063f8a;
case 0x0c063f8cu: goto P_0c063f8c;
case 0x0c063f8eu: goto P_0c063f8e;
case 0x0c063f90u: goto P_0c063f90;
case 0x0c063f92u: goto P_0c063f92;
case 0x0c063f94u: goto P_0c063f94;
case 0x0c063f96u: goto P_0c063f96;
case 0x0c063f98u: goto P_0c063f98;
case 0x0c063f9au: goto P_0c063f9a;
case 0x0c063f9cu: goto P_0c063f9c;
case 0x0c063f9eu: goto P_0c063f9e;
case 0x0c063fa0u: goto P_0c063fa0;
case 0x0c063fa2u: goto P_0c063fa2;
case 0x0c063fa4u: goto P_0c063fa4;
case 0x0c063fa6u: goto P_0c063fa6;
case 0x0c063fa8u: goto P_0c063fa8;
case 0x0c063faau: goto P_0c063faa;
case 0x0c063facu: goto P_0c063fac;
case 0x0c063faeu: goto P_0c063fae;
case 0x0c063fb0u: goto P_0c063fb0;
case 0x0c063fb2u: goto P_0c063fb2;
case 0x0c063fb4u: goto P_0c063fb4;
case 0x0c063fb6u: goto P_0c063fb6;
case 0x0c063fb8u: goto P_0c063fb8;
case 0x0c063fbau: goto P_0c063fba;
case 0x0c063fbcu: goto P_0c063fbc;
case 0x0c063fbeu: goto P_0c063fbe;
case 0x0c063fc0u: goto P_0c063fc0;
case 0x0c063fc2u: goto P_0c063fc2;
case 0x0c063fc4u: goto P_0c063fc4;
case 0x0c063fc6u: goto P_0c063fc6;
case 0x0c063fc8u: goto P_0c063fc8;
case 0x0c063fcau: goto P_0c063fca;
case 0x0c063fccu: goto P_0c063fcc;
case 0x0c063fceu: goto P_0c063fce;
case 0x0c063fd0u: goto P_0c063fd0;
case 0x0c063fd2u: goto P_0c063fd2;
case 0x0c063fd4u: goto P_0c063fd4;
case 0x0c063fd6u: goto P_0c063fd6;
case 0x0c063fd8u: goto P_0c063fd8;
case 0x0c063fdau: goto P_0c063fda;
case 0x0c063fdcu: goto P_0c063fdc;
case 0x0c063fdeu: goto P_0c063fde;
case 0x0c063fe0u: goto P_0c063fe0;
case 0x0c063fe2u: goto P_0c063fe2;
case 0x0c063fe4u: goto P_0c063fe4;
case 0x0c063fe6u: goto P_0c063fe6;
case 0x0c063fe8u: goto P_0c063fe8;
case 0x0c063feau: goto P_0c063fea;
case 0x0c063fecu: goto P_0c063fec;
case 0x0c063feeu: goto P_0c063fee;
case 0x0c063ff0u: goto P_0c063ff0;
case 0x0c063ff2u: goto P_0c063ff2;
case 0x0c063ff4u: goto P_0c063ff4;
case 0x0c063ff6u: goto P_0c063ff6;
case 0x0c063ff8u: goto P_0c063ff8;
case 0x0c063ffau: goto P_0c063ffa;
case 0x0c063ffcu: goto P_0c063ffc;
case 0x0c063ffeu: goto P_0c063ffe;
case 0x0c064000u: goto P_0c064000;
case 0x0c064002u: goto P_0c064002;
case 0x0c064004u: goto P_0c064004;
case 0x0c064006u: goto P_0c064006;
case 0x0c064008u: goto P_0c064008;
case 0x0c06400au: goto P_0c06400a;
case 0x0c06400cu: goto P_0c06400c;
case 0x0c06400eu: goto P_0c06400e;
case 0x0c064010u: goto P_0c064010;
case 0x0c064012u: goto P_0c064012;
case 0x0c064014u: goto P_0c064014;
case 0x0c064016u: goto P_0c064016;
case 0x0c064018u: goto P_0c064018;
case 0x0c06401au: goto P_0c06401a;
case 0x0c06401cu: goto P_0c06401c;
case 0x0c06401eu: goto P_0c06401e;
case 0x0c064020u: goto P_0c064020;
case 0x0c064022u: goto P_0c064022;
case 0x0c064024u: goto P_0c064024;
case 0x0c064026u: goto P_0c064026;
case 0x0c064028u: goto P_0c064028;
case 0x0c06402au: goto P_0c06402a;
case 0x0c06402cu: goto P_0c06402c;
case 0x0c06402eu: goto P_0c06402e;
case 0x0c064030u: goto P_0c064030;
case 0x0c064032u: goto P_0c064032;
case 0x0c064034u: goto P_0c064034;
case 0x0c064036u: goto P_0c064036;
case 0x0c064098u: goto P_0c064098;
case 0x0c06409au: goto P_0c06409a;
case 0x0c06409cu: goto P_0c06409c;
case 0x0c06409eu: goto P_0c06409e;
case 0x0c0640a0u: goto P_0c0640a0;
case 0x0c0640a2u: goto P_0c0640a2;
case 0x0c0640a4u: goto P_0c0640a4;
case 0x0c0640a6u: goto P_0c0640a6;
case 0x0c0640a8u: goto P_0c0640a8;
case 0x0c0640aau: goto P_0c0640aa;
case 0x0c0640acu: goto P_0c0640ac;
case 0x0c0640aeu: goto P_0c0640ae;
case 0x0c0640b0u: goto P_0c0640b0;
case 0x0c0640b2u: goto P_0c0640b2;
case 0x0c0640b4u: goto P_0c0640b4;
case 0x0c0640b6u: goto P_0c0640b6;
case 0x0c0640b8u: goto P_0c0640b8;
case 0x0c0640bau: goto P_0c0640ba;
case 0x0c0640bcu: goto P_0c0640bc;
case 0x0c0640beu: goto P_0c0640be;
case 0x0c0640c0u: goto P_0c0640c0;
case 0x0c0640c2u: goto P_0c0640c2;
case 0x0c0640c4u: goto P_0c0640c4;
case 0x0c0640c6u: goto P_0c0640c6;
case 0x0c0640c8u: goto P_0c0640c8;
case 0x0c0640cau: goto P_0c0640ca;
case 0x0c0640ccu: goto P_0c0640cc;
case 0x0c0640ceu: goto P_0c0640ce;
case 0x0c0640d0u: goto P_0c0640d0;
case 0x0c0640d2u: goto P_0c0640d2;
case 0x0c0640d4u: goto P_0c0640d4;
case 0x0c0640d6u: goto P_0c0640d6;
case 0x0c0640d8u: goto P_0c0640d8;
case 0x0c0640dau: goto P_0c0640da;
case 0x0c0640dcu: goto P_0c0640dc;
case 0x0c0640deu: goto P_0c0640de;
case 0x0c0640e0u: goto P_0c0640e0;
case 0x0c0640e2u: goto P_0c0640e2;
case 0x0c0640e4u: goto P_0c0640e4;
case 0x0c0640e6u: goto P_0c0640e6;
case 0x0c0640e8u: goto P_0c0640e8;
case 0x0c0640eau: goto P_0c0640ea;
case 0x0c0640ecu: goto P_0c0640ec;
case 0x0c0640eeu: goto P_0c0640ee;
case 0x0c0640f0u: goto P_0c0640f0;
case 0x0c0640f2u: goto P_0c0640f2;
case 0x0c0640f4u: goto P_0c0640f4;
case 0x0c0640f6u: goto P_0c0640f6;
case 0x0c0640f8u: goto P_0c0640f8;
case 0x0c0640fau: goto P_0c0640fa;
case 0x0c0640fcu: goto P_0c0640fc;
case 0x0c0640feu: goto P_0c0640fe;
case 0x0c064100u: goto P_0c064100;
case 0x0c064102u: goto P_0c064102;
case 0x0c064104u: goto P_0c064104;
case 0x0c064106u: goto P_0c064106;
case 0x0c064108u: goto P_0c064108;
case 0x0c06410au: goto P_0c06410a;
case 0x0c06410cu: goto P_0c06410c;
case 0x0c06410eu: goto P_0c06410e;
case 0x0c064110u: goto P_0c064110;
case 0x0c064112u: goto P_0c064112;
case 0x0c064114u: goto P_0c064114;
case 0x0c064116u: goto P_0c064116;
case 0x0c064118u: goto P_0c064118;
case 0x0c06411au: goto P_0c06411a;
case 0x0c06411cu: goto P_0c06411c;
case 0x0c06411eu: goto P_0c06411e;
case 0x0c064120u: goto P_0c064120;
case 0x0c064122u: goto P_0c064122;
case 0x0c064124u: goto P_0c064124;
case 0x0c064126u: goto P_0c064126;
case 0x0c064128u: goto P_0c064128;
case 0x0c06412au: goto P_0c06412a;
case 0x0c06412cu: goto P_0c06412c;
case 0x0c06412eu: goto P_0c06412e;
case 0x0c064130u: goto P_0c064130;
case 0x0c064132u: goto P_0c064132;
case 0x0c064134u: goto P_0c064134;
case 0x0c064136u: goto P_0c064136;
case 0x0c064138u: goto P_0c064138;
case 0x0c06413au: goto P_0c06413a;
case 0x0c06413cu: goto P_0c06413c;
case 0x0c06413eu: goto P_0c06413e;
case 0x0c064140u: goto P_0c064140;
case 0x0c064142u: goto P_0c064142;
case 0x0c064144u: goto P_0c064144;
case 0x0c064146u: goto P_0c064146;
case 0x0c064148u: goto P_0c064148;
case 0x0c06414au: goto P_0c06414a;
case 0x0c06414cu: goto P_0c06414c;
case 0x0c06414eu: goto P_0c06414e;
case 0x0c064150u: goto P_0c064150;
case 0x0c064152u: goto P_0c064152;
case 0x0c064154u: goto P_0c064154;
case 0x0c064156u: goto P_0c064156;
case 0x0c064158u: goto P_0c064158;
case 0x0c06415au: goto P_0c06415a;
case 0x0c06415cu: goto P_0c06415c;
case 0x0c06415eu: goto P_0c06415e;
case 0x0c064160u: goto P_0c064160;
case 0x0c064162u: goto P_0c064162;
case 0x0c064164u: goto P_0c064164;
case 0x0c064166u: goto P_0c064166;
case 0x0c064168u: goto P_0c064168;
case 0x0c06416au: goto P_0c06416a;
case 0x0c06416cu: goto P_0c06416c;
case 0x0c06416eu: goto P_0c06416e;
case 0x0c064170u: goto P_0c064170;
case 0x0c064172u: goto P_0c064172;
case 0x0c064174u: goto P_0c064174;
case 0x0c064176u: goto P_0c064176;
case 0x0c064178u: goto P_0c064178;
case 0x0c06417au: goto P_0c06417a;
case 0x0c06417cu: goto P_0c06417c;
case 0x0c06417eu: goto P_0c06417e;
case 0x0c064180u: goto P_0c064180;
case 0x0c064182u: goto P_0c064182;
case 0x0c064184u: goto P_0c064184;
case 0x0c064186u: goto P_0c064186;
case 0x0c064188u: goto P_0c064188;
case 0x0c06418au: goto P_0c06418a;
case 0x0c06418cu: goto P_0c06418c;
case 0x0c06418eu: goto P_0c06418e;
case 0x0c064190u: goto P_0c064190;
case 0x0c064192u: goto P_0c064192;
case 0x0c064194u: goto P_0c064194;
case 0x0c064196u: goto P_0c064196;
case 0x0c064198u: goto P_0c064198;
case 0x0c06419au: goto P_0c06419a;
case 0x0c06419cu: goto P_0c06419c;
default: return vf3_matrix_family(target,s,ram);
}
P_0c063f86: /* original d735, guest PC 0x0c063f86 */
if(!s->budget--) { s->failed_pc=0x0c063f86u; return 0; }
r[7]=read(ram,0x0c06405cu,4);
goto P_0c063f88;
P_0c063f88: /* original d335, guest PC 0x0c063f88 */
if(!s->budget--) { s->failed_pc=0x0c063f88u; return 0; }
r[3]=read(ram,0x0c064060u,4);
goto P_0c063f8a;
P_0c063f8a: /* original 6032, guest PC 0x0c063f8a */
if(!s->budget--) { s->failed_pc=0x0c063f8au; return 0; }
tmp=read(ram,r[3],4);
r[0]=tmp;
goto P_0c063f8c;
P_0c063f8c: /* original d12a, guest PC 0x0c063f8c */
if(!s->budget--) { s->failed_pc=0x0c063f8cu; return 0; }
r[1]=read(ram,0x0c064038u,4);
goto P_0c063f8e;
P_0c063f8e: /* original 4008, guest PC 0x0c063f8e */
if(!s->budget--) { s->failed_pc=0x0c063f8eu; return 0; }
r[0]<<=2;
goto P_0c063f90;
P_0c063f90: /* original 001e, guest PC 0x0c063f90 */
if(!s->budget--) { s->failed_pc=0x0c063f90u; return 0; }
r[0]=read(ram,r[1]+r[0],4);
goto P_0c063f92;
P_0c063f92: /* original 88ff, guest PC 0x0c063f92 */
if(!s->budget--) { s->failed_pc=0x0c063f92u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xffffffffu)!=0);
goto P_0c063f94;
P_0c063f94: /* original 8945, guest PC 0x0c063f94 */
if(!s->budget--) { s->failed_pc=0x0c063f94u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c064022; }
goto P_0c063f96;
P_0c063f96: /* original d233, guest PC 0x0c063f96 */
if(!s->budget--) { s->failed_pc=0x0c063f96u; return 0; }
r[2]=read(ram,0x0c064064u,4);
goto P_0c063f98;
P_0c063f98: /* original 6022, guest PC 0x0c063f98 */
if(!s->budget--) { s->failed_pc=0x0c063f98u; return 0; }
tmp=read(ram,r[2],4);
r[0]=tmp;
goto P_0c063f9a;
P_0c063f9a: /* original 2008, guest PC 0x0c063f9a */
if(!s->budget--) { s->failed_pc=0x0c063f9au; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c063f9c;
P_0c063f9c: /* original 8b09, guest PC 0x0c063f9c */
if(!s->budget--) { s->failed_pc=0x0c063f9cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c063fb2; }
goto P_0c063f9e;
P_0c063f9e: /* original d332, guest PC 0x0c063f9e */
if(!s->budget--) { s->failed_pc=0x0c063f9eu; return 0; }
r[3]=read(ram,0x0c064068u,4);
goto P_0c063fa0;
P_0c063fa0: /* original 6032, guest PC 0x0c063fa0 */
if(!s->budget--) { s->failed_pc=0x0c063fa0u; return 0; }
tmp=read(ram,r[3],4);
r[0]=tmp;
goto P_0c063fa2;
P_0c063fa2: /* original cb20, guest PC 0x0c063fa2 */
if(!s->budget--) { s->failed_pc=0x0c063fa2u; return 0; }
r[0]|=32u;
goto P_0c063fa4;
P_0c063fa4: /* original 2302, guest PC 0x0c063fa4 */
if(!s->budget--) { s->failed_pc=0x0c063fa4u; return 0; }
write(ram,r[3],r[0],4);
goto P_0c063fa6;
P_0c063fa6: /* original e103, guest PC 0x0c063fa6 */
if(!s->budget--) { s->failed_pc=0x0c063fa6u; return 0; }
r[1]=0x00000003u;
goto P_0c063fa8;
P_0c063fa8: /* original d02d, guest PC 0x0c063fa8 */
if(!s->budget--) { s->failed_pc=0x0c063fa8u; return 0; }
r[0]=read(ram,0x0c064060u,4);
goto P_0c063faa;
P_0c063faa: /* original 6302, guest PC 0x0c063faa */
if(!s->budget--) { s->failed_pc=0x0c063faau; return 0; }
tmp=read(ram,r[0],4);
r[3]=tmp;
goto P_0c063fac;
P_0c063fac: /* original 4308, guest PC 0x0c063fac */
if(!s->budget--) { s->failed_pc=0x0c063facu; return 0; }
r[3]<<=2;
goto P_0c063fae;
P_0c063fae: /* original 70e8, guest PC 0x0c063fae */
if(!s->budget--) { s->failed_pc=0x0c063faeu; return 0; }
r[0]+=0xffffffe8u;
goto P_0c063fb0;
P_0c063fb0: /* original 0316, guest PC 0x0c063fb0 */
if(!s->budget--) { s->failed_pc=0x0c063fb0u; return 0; }
write(ram,r[3]+r[0],r[1],4);
goto P_0c063fb2;
P_0c063fb2: /* original e501, guest PC 0x0c063fb2 */
if(!s->budget--) { s->failed_pc=0x0c063fb2u; return 0; }
r[5]=0x00000001u;
goto P_0c063fb4;
P_0c063fb4: /* original d22e, guest PC 0x0c063fb4 */
if(!s->budget--) { s->failed_pc=0x0c063fb4u; return 0; }
r[2]=read(ram,0x0c064070u,4);
goto P_0c063fb6;
P_0c063fb6: /* original d62d, guest PC 0x0c063fb6 */
if(!s->budget--) { s->failed_pc=0x0c063fb6u; return 0; }
r[6]=read(ram,0x0c06406cu,4);
goto P_0c063fb8;
P_0c063fb8: /* original 6322, guest PC 0x0c063fb8 */
if(!s->budget--) { s->failed_pc=0x0c063fb8u; return 0; }
tmp=read(ram,r[2],4);
r[3]=tmp;
goto P_0c063fba;
P_0c063fba: /* original 2358, guest PC 0x0c063fba */
if(!s->budget--) { s->failed_pc=0x0c063fbau; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[5])==0)!=0);
goto P_0c063fbc;
P_0c063fbc: /* original 8901, guest PC 0x0c063fbc */
if(!s->budget--) { s->failed_pc=0x0c063fbcu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c063fc2; }
goto P_0c063fbe;
P_0c063fbe: /* original a008, guest PC 0x0c063fbe */
if(!s->budget--) { s->failed_pc=0x0c063fbeu; return 0; }
tmp=read(ram,r[6],4);
r[4]=tmp;
goto P_0c063fd2;
P_0c063fc0: /* original 6462, guest PC 0x0c063fc0 */
if(!s->budget--) { s->failed_pc=0x0c063fc0u; return 0; }
tmp=read(ram,r[6],4);
r[4]=tmp;
goto P_0c063fc2;
P_0c063fc2: /* original d327, guest PC 0x0c063fc2 */
if(!s->budget--) { s->failed_pc=0x0c063fc2u; return 0; }
r[3]=read(ram,0x0c064060u,4);
goto P_0c063fc4;
P_0c063fc4: /* original 6432, guest PC 0x0c063fc4 */
if(!s->budget--) { s->failed_pc=0x0c063fc4u; return 0; }
tmp=read(ram,r[3],4);
r[4]=tmp;
goto P_0c063fc6;
P_0c063fc6: /* original 2459, guest PC 0x0c063fc6 */
if(!s->budget--) { s->failed_pc=0x0c063fc6u; return 0; }
r[4]&=r[5];
goto P_0c063fc8;
P_0c063fc8: /* original d02a, guest PC 0x0c063fc8 */
if(!s->budget--) { s->failed_pc=0x0c063fc8u; return 0; }
r[0]=read(ram,0x0c064074u,4);
goto P_0c063fca;
P_0c063fca: /* original 4408, guest PC 0x0c063fca */
if(!s->budget--) { s->failed_pc=0x0c063fcau; return 0; }
r[4]<<=2;
goto P_0c063fcc;
P_0c063fcc: /* original 4408, guest PC 0x0c063fcc */
if(!s->budget--) { s->failed_pc=0x0c063fccu; return 0; }
r[4]<<=2;
goto P_0c063fce;
P_0c063fce: /* original 4400, guest PC 0x0c063fce */
if(!s->budget--) { s->failed_pc=0x0c063fceu; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c063fd0;
P_0c063fd0: /* original 044e, guest PC 0x0c063fd0 */
if(!s->budget--) { s->failed_pc=0x0c063fd0u; return 0; }
r[4]=read(ram,r[4]+r[0],4);
goto P_0c063fd2;
P_0c063fd2: /* original d223, guest PC 0x0c063fd2 */
if(!s->budget--) { s->failed_pc=0x0c063fd2u; return 0; }
r[2]=read(ram,0x0c064060u,4);
goto P_0c063fd4;
P_0c063fd4: /* original 6322, guest PC 0x0c063fd4 */
if(!s->budget--) { s->failed_pc=0x0c063fd4u; return 0; }
tmp=read(ram,r[2],4);
r[3]=tmp;
goto P_0c063fd6;
P_0c063fd6: /* original 2359, guest PC 0x0c063fd6 */
if(!s->budget--) { s->failed_pc=0x0c063fd6u; return 0; }
r[3]&=r[5];
goto P_0c063fd8;
P_0c063fd8: /* original 4308, guest PC 0x0c063fd8 */
if(!s->budget--) { s->failed_pc=0x0c063fd8u; return 0; }
r[3]<<=2;
goto P_0c063fda;
P_0c063fda: /* original 6173, guest PC 0x0c063fda */
if(!s->budget--) { s->failed_pc=0x0c063fdau; return 0; }
r[1]=r[7];
goto P_0c063fdc;
P_0c063fdc: /* original 7124, guest PC 0x0c063fdc */
if(!s->budget--) { s->failed_pc=0x0c063fdcu; return 0; }
r[1]+=0x00000024u;
goto P_0c063fde;
P_0c063fde: /* original 331c, guest PC 0x0c063fde */
if(!s->budget--) { s->failed_pc=0x0c063fdeu; return 0; }
r[3]+=r[1];
goto P_0c063fe0;
P_0c063fe0: /* original 6062, guest PC 0x0c063fe0 */
if(!s->budget--) { s->failed_pc=0x0c063fe0u; return 0; }
tmp=read(ram,r[6],4);
r[0]=tmp;
goto P_0c063fe2;
P_0c063fe2: /* original 2302, guest PC 0x0c063fe2 */
if(!s->budget--) { s->failed_pc=0x0c063fe2u; return 0; }
write(ram,r[3],r[0],4);
goto P_0c063fe4;
P_0c063fe4: /* original d324, guest PC 0x0c063fe4 */
if(!s->budget--) { s->failed_pc=0x0c063fe4u; return 0; }
r[3]=read(ram,0x0c064078u,4);
goto P_0c063fe6;
P_0c063fe6: /* original d025, guest PC 0x0c063fe6 */
if(!s->budget--) { s->failed_pc=0x0c063fe6u; return 0; }
r[0]=read(ram,0x0c06407cu,4);
goto P_0c063fe8;
P_0c063fe8: /* original 6102, guest PC 0x0c063fe8 */
if(!s->budget--) { s->failed_pc=0x0c063fe8u; return 0; }
tmp=read(ram,r[0],4);
r[1]=tmp;
goto P_0c063fea;
P_0c063fea: /* original 2139, guest PC 0x0c063fea */
if(!s->budget--) { s->failed_pc=0x0c063feau; return 0; }
r[1]&=r[3];
goto P_0c063fec;
P_0c063fec: /* original 6023, guest PC 0x0c063fec */
if(!s->budget--) { s->failed_pc=0x0c063fecu; return 0; }
r[0]=r[2];
goto P_0c063fee;
P_0c063fee: /* original 0009, guest PC 0x0c063fee */
if(!s->budget--) { s->failed_pc=0x0c063feeu; return 0; }
goto P_0c063ff0;
P_0c063ff0: /* original 6202, guest PC 0x0c063ff0 */
if(!s->budget--) { s->failed_pc=0x0c063ff0u; return 0; }
tmp=read(ram,r[0],4);
r[2]=tmp;
goto P_0c063ff2;
P_0c063ff2: /* original 2259, guest PC 0x0c063ff2 */
if(!s->budget--) { s->failed_pc=0x0c063ff2u; return 0; }
r[2]&=r[5];
goto P_0c063ff4;
P_0c063ff4: /* original d022, guest PC 0x0c063ff4 */
if(!s->budget--) { s->failed_pc=0x0c063ff4u; return 0; }
r[0]=read(ram,0x0c064080u,4);
goto P_0c063ff6;
P_0c063ff6: /* original 4208, guest PC 0x0c063ff6 */
if(!s->budget--) { s->failed_pc=0x0c063ff6u; return 0; }
r[2]<<=2;
goto P_0c063ff8;
P_0c063ff8: /* original 4208, guest PC 0x0c063ff8 */
if(!s->budget--) { s->failed_pc=0x0c063ff8u; return 0; }
r[2]<<=2;
goto P_0c063ffa;
P_0c063ffa: /* original 4200, guest PC 0x0c063ffa */
if(!s->budget--) { s->failed_pc=0x0c063ffau; return 0; }
r[17]=(r[17]&~1u)|((r[2]>>31)!=0);
r[2]<<=1;
goto P_0c063ffc;
P_0c063ffc: /* original 022e, guest PC 0x0c063ffc */
if(!s->budget--) { s->failed_pc=0x0c063ffcu; return 0; }
r[2]=read(ram,r[2]+r[0],4);
goto P_0c063ffe;
P_0c063ffe: /* original 6343, guest PC 0x0c063ffe */
if(!s->budget--) { s->failed_pc=0x0c063ffeu; return 0; }
r[3]=r[4];
goto P_0c064000;
P_0c064000: /* original 3328, guest PC 0x0c064000 */
if(!s->budget--) { s->failed_pc=0x0c064000u; return 0; }
r[3]-=r[2];
goto P_0c064002;
P_0c064002: /* original 4300, guest PC 0x0c064002 */
if(!s->budget--) { s->failed_pc=0x0c064002u; return 0; }
r[17]=(r[17]&~1u)|((r[3]>>31)!=0);
r[3]<<=1;
goto P_0c064004;
P_0c064004: /* original d21f, guest PC 0x0c064004 */
if(!s->budget--) { s->failed_pc=0x0c064004u; return 0; }
r[2]=read(ram,0x0c064084u,4);
goto P_0c064006;
P_0c064006: /* original 2329, guest PC 0x0c064006 */
if(!s->budget--) { s->failed_pc=0x0c064006u; return 0; }
r[3]&=r[2];
goto P_0c064008;
P_0c064008: /* original 213b, guest PC 0x0c064008 */
if(!s->budget--) { s->failed_pc=0x0c064008u; return 0; }
r[1]|=r[3];
goto P_0c06400a;
P_0c06400a: /* original d31f, guest PC 0x0c06400a */
if(!s->budget--) { s->failed_pc=0x0c06400au; return 0; }
r[3]=read(ram,0x0c064088u,4);
goto P_0c06400c;
P_0c06400c: /* original 2312, guest PC 0x0c06400c */
if(!s->budget--) { s->failed_pc=0x0c06400cu; return 0; }
write(ram,r[3],r[1],4);
goto P_0c06400e;
P_0c06400e: /* original d61f, guest PC 0x0c06400e */
if(!s->budget--) { s->failed_pc=0x0c06400eu; return 0; }
r[6]=read(ram,0x0c06408cu,4);
goto P_0c064010;
P_0c064010: /* original d21f, guest PC 0x0c064010 */
if(!s->budget--) { s->failed_pc=0x0c064010u; return 0; }
r[2]=read(ram,0x0c064090u,4);
goto P_0c064012;
P_0c064012: /* original e530, guest PC 0x0c064012 */
if(!s->budget--) { s->failed_pc=0x0c064012u; return 0; }
r[5]=0x00000030u;
goto P_0c064014;
P_0c064014: /* original 342c, guest PC 0x0c064014 */
if(!s->budget--) { s->failed_pc=0x0c064014u; return 0; }
r[4]+=r[2];
goto P_0c064016;
P_0c064016: /* original 75ff, guest PC 0x0c064016 */
if(!s->budget--) { s->failed_pc=0x0c064016u; return 0; }
r[5]+=0xffffffffu;
goto P_0c064018;
P_0c064018: /* original 6266, guest PC 0x0c064018 */
if(!s->budget--) { s->failed_pc=0x0c064018u; return 0; }
tmp=read(ram,r[6],4);
r[6]+=4;
r[2]=tmp;
goto P_0c06401a;
P_0c06401a: /* original 2558, guest PC 0x0c06401a */
if(!s->budget--) { s->failed_pc=0x0c06401au; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[5])==0)!=0);
goto P_0c06401c;
P_0c06401c: /* original 2422, guest PC 0x0c06401c */
if(!s->budget--) { s->failed_pc=0x0c06401cu; return 0; }
write(ram,r[4],r[2],4);
goto P_0c06401e;
P_0c06401e: /* original 8ffa, guest PC 0x0c06401e */
if(!s->budget--) { s->failed_pc=0x0c06401eu; return 0; }
cond=r[17]&1u;
r[4]+=0x00000004u;
if(!cond) { goto P_0c064016; }
goto P_0c064022;
P_0c064020: /* original 7404, guest PC 0x0c064020 */
if(!s->budget--) { s->failed_pc=0x0c064020u; return 0; }
r[4]+=0x00000004u;
goto P_0c064022;
P_0c064022: /* original e200, guest PC 0x0c064022 */
if(!s->budget--) { s->failed_pc=0x0c064022u; return 0; }
r[2]=0x00000000u;
goto P_0c064024;
P_0c064024: /* original d30b, guest PC 0x0c064024 */
if(!s->budget--) { s->failed_pc=0x0c064024u; return 0; }
r[3]=read(ram,0x0c064054u,4);
goto P_0c064026;
P_0c064026: /* original 2322, guest PC 0x0c064026 */
if(!s->budget--) { s->failed_pc=0x0c064026u; return 0; }
write(ram,r[3],r[2],4);
goto P_0c064028;
P_0c064028: /* original d01a, guest PC 0x0c064028 */
if(!s->budget--) { s->failed_pc=0x0c064028u; return 0; }
r[0]=read(ram,0x0c064094u,4);
goto P_0c06402a;
P_0c06402a: /* original 6202, guest PC 0x0c06402a */
if(!s->budget--) { s->failed_pc=0x0c06402au; return 0; }
tmp=read(ram,r[0],4);
r[2]=tmp;
goto P_0c06402c;
P_0c06402c: /* original e048, guest PC 0x0c06402c */
if(!s->budget--) { s->failed_pc=0x0c06402cu; return 0; }
r[0]=0x00000048u;
goto P_0c06402e;
P_0c06402e: /* original 017e, guest PC 0x0c06402e */
if(!s->budget--) { s->failed_pc=0x0c06402eu; return 0; }
r[1]=read(ram,r[7]+r[0],4);
goto P_0c064030;
P_0c064030: /* original 3128, guest PC 0x0c064030 */
if(!s->budget--) { s->failed_pc=0x0c064030u; return 0; }
r[1]-=r[2];
goto P_0c064032;
P_0c064032: /* original e04c, guest PC 0x0c064032 */
if(!s->budget--) { s->failed_pc=0x0c064032u; return 0; }
r[0]=0x0000004cu;
goto P_0c064034;
P_0c064034: /* original 000b, guest PC 0x0c064034 */
if(!s->budget--) { s->failed_pc=0x0c064034u; return 0; }
target=r[16];
write(ram,r[7]+r[0],r[1],4);
s->pc=target; return ram->oob==0;
P_0c064036: /* original 0716, guest PC 0x0c064036 */
if(!s->budget--) { s->failed_pc=0x0c064036u; return 0; }
write(ram,r[7]+r[0],r[1],4);
if(!vf3_matrix_family(0x0c064038u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c064038u; return 0; } return 1;
P_0c064098: /* original 2fe6, guest PC 0x0c064098 */
if(!s->budget--) { s->failed_pc=0x0c064098u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06409a;
P_0c06409a: /* original 2fd6, guest PC 0x0c06409a */
if(!s->budget--) { s->failed_pc=0x0c06409au; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06409c;
P_0c06409c: /* original 2fc6, guest PC 0x0c06409c */
if(!s->budget--) { s->failed_pc=0x0c06409cu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06409e;
P_0c06409e: /* original 2fb6, guest PC 0x0c06409e */
if(!s->budget--) { s->failed_pc=0x0c06409eu; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0640a0;
P_0c0640a0: /* original 2fa6, guest PC 0x0c0640a0 */
if(!s->budget--) { s->failed_pc=0x0c0640a0u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0640a2;
P_0c0640a2: /* original eb02, guest PC 0x0c0640a2 */
if(!s->budget--) { s->failed_pc=0x0c0640a2u; return 0; }
r[11]=0x00000002u;
goto P_0c0640a4;
P_0c0640a4: /* original de41, guest PC 0x0c0640a4 */
if(!s->budget--) { s->failed_pc=0x0c0640a4u; return 0; }
r[14]=read(ram,0x0c0641acu,4);
goto P_0c0640a6;
P_0c0640a6: /* original 2f96, guest PC 0x0c0640a6 */
if(!s->budget--) { s->failed_pc=0x0c0640a6u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0640a8;
P_0c0640a8: /* original 2f86, guest PC 0x0c0640a8 */
if(!s->budget--) { s->failed_pc=0x0c0640a8u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0640aa;
P_0c0640aa: /* original 4f22, guest PC 0x0c0640aa */
if(!s->budget--) { s->failed_pc=0x0c0640aau; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0640ac;
P_0c0640ac: /* original 9a77, guest PC 0x0c0640ac */
if(!s->budget--) { s->failed_pc=0x0c0640acu; return 0; }
r[10]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06419eu,2);
goto P_0c0640ae;
P_0c0640ae: /* original 7ff8, guest PC 0x0c0640ae */
if(!s->budget--) { s->failed_pc=0x0c0640aeu; return 0; }
r[15]+=0xfffffff8u;
goto P_0c0640b0;
P_0c0640b0: /* original 6043, guest PC 0x0c0640b0 */
if(!s->budget--) { s->failed_pc=0x0c0640b0u; return 0; }
r[0]=r[4];
goto P_0c0640b2;
P_0c0640b2: /* original 0009, guest PC 0x0c0640b2 */
if(!s->budget--) { s->failed_pc=0x0c0640b2u; return 0; }
goto P_0c0640b4;
P_0c0640b4: /* original 8800, guest PC 0x0c0640b4 */
if(!s->budget--) { s->failed_pc=0x0c0640b4u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000000u)!=0);
goto P_0c0640b6;
P_0c0640b6: /* original 8d04, guest PC 0x0c0640b6 */
if(!s->budget--) { s->failed_pc=0x0c0640b6u; return 0; }
cond=r[17]&1u;
r[13]=0x00000000u;
if(cond) { goto P_0c0640c2; }
goto P_0c0640ba;
P_0c0640b8: /* original ed00, guest PC 0x0c0640b8 */
if(!s->budget--) { s->failed_pc=0x0c0640b8u; return 0; }
r[13]=0x00000000u;
goto P_0c0640ba;
P_0c0640ba: /* original 8801, guest PC 0x0c0640ba */
if(!s->budget--) { s->failed_pc=0x0c0640bau; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c0640bc;
P_0c0640bc: /* original 8929, guest PC 0x0c0640bc */
if(!s->budget--) { s->failed_pc=0x0c0640bcu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c064112; }
goto P_0c0640be;
P_0c0640be: /* original a063, guest PC 0x0c0640be */
if(!s->budget--) { s->failed_pc=0x0c0640beu; return 0; }
goto P_0c064188;
P_0c0640c0: /* original 0009, guest PC 0x0c0640c0 */
if(!s->budget--) { s->failed_pc=0x0c0640c0u; return 0; }
goto P_0c0640c2;
P_0c0640c2: /* original e300, guest PC 0x0c0640c2 */
if(!s->budget--) { s->failed_pc=0x0c0640c2u; return 0; }
r[3]=0x00000000u;
goto P_0c0640c4;
P_0c0640c4: /* original 986c, guest PC 0x0c0640c4 */
if(!s->budget--) { s->failed_pc=0x0c0640c4u; return 0; }
r[8]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0641a0u,2);
goto P_0c0640c6;
P_0c0640c6: /* original 69d3, guest PC 0x0c0640c6 */
if(!s->budget--) { s->failed_pc=0x0c0640c6u; return 0; }
r[9]=r[13];
goto P_0c0640c8;
P_0c0640c8: /* original 2f32, guest PC 0x0c0640c8 */
if(!s->budget--) { s->failed_pc=0x0c0640c8u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c0640ca;
P_0c0640ca: /* original 6cd3, guest PC 0x0c0640ca */
if(!s->budget--) { s->failed_pc=0x0c0640cau; return 0; }
r[12]=r[13];
goto P_0c0640cc;
P_0c0640cc: /* original d038, guest PC 0x0c0640cc */
if(!s->budget--) { s->failed_pc=0x0c0640ccu; return 0; }
r[0]=read(ram,0x0c0641b0u,4);
goto P_0c0640ce;
P_0c0640ce: /* original 039e, guest PC 0x0c0640ce */
if(!s->budget--) { s->failed_pc=0x0c0640ceu; return 0; }
r[3]=read(ram,r[9]+r[0],4);
goto P_0c0640d0;
P_0c0640d0: /* original 338c, guest PC 0x0c0640d0 */
if(!s->budget--) { s->failed_pc=0x0c0640d0u; return 0; }
r[3]+=r[8];
goto P_0c0640d2;
P_0c0640d2: /* original 70f0, guest PC 0x0c0640d2 */
if(!s->budget--) { s->failed_pc=0x0c0640d2u; return 0; }
r[0]+=0xfffffff0u;
goto P_0c0640d4;
P_0c0640d4: /* original 029e, guest PC 0x0c0640d4 */
if(!s->budget--) { s->failed_pc=0x0c0640d4u; return 0; }
r[2]=read(ram,r[9]+r[0],4);
goto P_0c0640d6;
P_0c0640d6: /* original 32ac, guest PC 0x0c0640d6 */
if(!s->budget--) { s->failed_pc=0x0c0640d6u; return 0; }
r[2]+=r[10];
goto P_0c0640d8;
P_0c0640d8: /* original 3322, guest PC 0x0c0640d8 */
if(!s->budget--) { s->failed_pc=0x0c0640d8u; return 0; }
r[17]=(r[17]&~1u)|((r[3]>=r[2])!=0);
goto P_0c0640da;
P_0c0640da: /* original 890a, guest PC 0x0c0640da */
if(!s->budget--) { s->failed_pc=0x0c0640dau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0640f2; }
goto P_0c0640dc;
P_0c0640dc: /* original d034, guest PC 0x0c0640dc */
if(!s->budget--) { s->failed_pc=0x0c0640dcu; return 0; }
r[0]=read(ram,0x0c0641b0u,4);
goto P_0c0640de;
P_0c0640de: /* original 02ce, guest PC 0x0c0640de */
if(!s->budget--) { s->failed_pc=0x0c0640deu; return 0; }
r[2]=read(ram,r[12]+r[0],4);
goto P_0c0640e0;
P_0c0640e0: /* original 328c, guest PC 0x0c0640e0 */
if(!s->budget--) { s->failed_pc=0x0c0640e0u; return 0; }
r[2]+=r[8];
goto P_0c0640e2;
P_0c0640e2: /* original 0c26, guest PC 0x0c0640e2 */
if(!s->budget--) { s->failed_pc=0x0c0640e2u; return 0; }
write(ram,r[12]+r[0],r[2],4);
goto P_0c0640e4;
P_0c0640e4: /* original 935d, guest PC 0x0c0640e4 */
if(!s->budget--) { s->failed_pc=0x0c0640e4u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0641a2u,2);
goto P_0c0640e6;
P_0c0640e6: /* original 01ce, guest PC 0x0c0640e6 */
if(!s->budget--) { s->failed_pc=0x0c0640e6u; return 0; }
r[1]=read(ram,r[12]+r[0],4);
goto P_0c0640e8;
P_0c0640e8: /* original 313c, guest PC 0x0c0640e8 */
if(!s->budget--) { s->failed_pc=0x0c0640e8u; return 0; }
r[1]+=r[3];
goto P_0c0640ea;
P_0c0640ea: /* original 70f4, guest PC 0x0c0640ea */
if(!s->budget--) { s->failed_pc=0x0c0640eau; return 0; }
r[0]+=0xfffffff4u;
goto P_0c0640ec;
P_0c0640ec: /* original 0c16, guest PC 0x0c0640ec */
if(!s->budget--) { s->failed_pc=0x0c0640ecu; return 0; }
write(ram,r[12]+r[0],r[1],4);
goto P_0c0640ee;
P_0c0640ee: /* original a007, guest PC 0x0c0640ee */
if(!s->budget--) { s->failed_pc=0x0c0640eeu; return 0; }
write(ram,r[14]+20,r[13],4);
goto P_0c064100;
P_0c0640f0: /* original 1ed5, guest PC 0x0c0640f0 */
if(!s->budget--) { s->failed_pc=0x0c0640f0u; return 0; }
write(ram,r[14]+20,r[13],4);
goto P_0c0640f2;
P_0c0640f2: /* original e300, guest PC 0x0c0640f2 */
if(!s->budget--) { s->failed_pc=0x0c0640f2u; return 0; }
r[3]=0x00000000u;
goto P_0c0640f4;
P_0c0640f4: /* original 52e5, guest PC 0x0c0640f4 */
if(!s->budget--) { s->failed_pc=0x0c0640f4u; return 0; }
r[2]=read(ram,r[14]+20,4);
goto P_0c0640f6;
P_0c0640f6: /* original 3236, guest PC 0x0c0640f6 */
if(!s->budget--) { s->failed_pc=0x0c0640f6u; return 0; }
r[17]=(r[17]&~1u)|((r[2]>r[3])!=0);
goto P_0c0640f8;
P_0c0640f8: /* original 8b02, guest PC 0x0c0640f8 */
if(!s->budget--) { s->failed_pc=0x0c0640f8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c064100; }
goto P_0c0640fa;
P_0c0640fa: /* original d22e, guest PC 0x0c0640fa */
if(!s->budget--) { s->failed_pc=0x0c0640fau; return 0; }
r[2]=read(ram,0x0c0641b4u,4);
goto P_0c0640fc;
P_0c0640fc: /* original 420b, guest PC 0x0c0640fc */
if(!s->budget--) { s->failed_pc=0x0c0640fcu; return 0; }
target=r[2];
r[16]=code_base|0x0c064100u;
r[4]=0x00000003u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c064100u) { target=s->pc; goto dispatch; }
goto P_0c064100;
P_0c0640fe: /* original e403, guest PC 0x0c0640fe */
if(!s->budget--) { s->failed_pc=0x0c0640feu; return 0; }
r[4]=0x00000003u;
goto P_0c064100;
P_0c064100: /* original 63f2, guest PC 0x0c064100 */
if(!s->budget--) { s->failed_pc=0x0c064100u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c064102;
P_0c064102: /* original 7c20, guest PC 0x0c064102 */
if(!s->budget--) { s->failed_pc=0x0c064102u; return 0; }
r[12]+=0x00000020u;
goto P_0c064104;
P_0c064104: /* original 7301, guest PC 0x0c064104 */
if(!s->budget--) { s->failed_pc=0x0c064104u; return 0; }
r[3]+=0x00000001u;
goto P_0c064106;
P_0c064106: /* original 33b3, guest PC 0x0c064106 */
if(!s->budget--) { s->failed_pc=0x0c064106u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>=(int32_t)r[11])!=0);
goto P_0c064108;
P_0c064108: /* original 2f32, guest PC 0x0c064108 */
if(!s->budget--) { s->failed_pc=0x0c064108u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c06410a;
P_0c06410a: /* original 8fdf, guest PC 0x0c06410a */
if(!s->budget--) { s->failed_pc=0x0c06410au; return 0; }
cond=r[17]&1u;
r[9]+=0x00000020u;
if(!cond) { goto P_0c0640cc; }
goto P_0c06410e;
P_0c06410c: /* original 7920, guest PC 0x0c06410c */
if(!s->budget--) { s->failed_pc=0x0c06410cu; return 0; }
r[9]+=0x00000020u;
goto P_0c06410e;
P_0c06410e: /* original a03b, guest PC 0x0c06410e */
if(!s->budget--) { s->failed_pc=0x0c06410eu; return 0; }
goto P_0c064188;
P_0c064110: /* original 0009, guest PC 0x0c064110 */
if(!s->budget--) { s->failed_pc=0x0c064110u; return 0; }
goto P_0c064112;
P_0c064112: /* original e200, guest PC 0x0c064112 */
if(!s->budget--) { s->failed_pc=0x0c064112u; return 0; }
r[2]=0x00000000u;
goto P_0c064114;
P_0c064114: /* original 9946, guest PC 0x0c064114 */
if(!s->budget--) { s->failed_pc=0x0c064114u; return 0; }
r[9]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0641a4u,2);
goto P_0c064116;
P_0c064116: /* original 6cd3, guest PC 0x0c064116 */
if(!s->budget--) { s->failed_pc=0x0c064116u; return 0; }
r[12]=r[13];
goto P_0c064118;
P_0c064118: /* original 2f22, guest PC 0x0c064118 */
if(!s->budget--) { s->failed_pc=0x0c064118u; return 0; }
write(ram,r[15],r[2],4);
goto P_0c06411a;
P_0c06411a: /* original 68c3, guest PC 0x0c06411a */
if(!s->budget--) { s->failed_pc=0x0c06411au; return 0; }
r[8]=r[12];
goto P_0c06411c;
P_0c06411c: /* original 1fd1, guest PC 0x0c06411c */
if(!s->budget--) { s->failed_pc=0x0c06411cu; return 0; }
write(ram,r[15]+4,r[13],4);
goto P_0c06411e;
P_0c06411e: /* original 64f2, guest PC 0x0c06411e */
if(!s->budget--) { s->failed_pc=0x0c06411eu; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c064120;
P_0c064120: /* original d025, guest PC 0x0c064120 */
if(!s->budget--) { s->failed_pc=0x0c064120u; return 0; }
r[0]=read(ram,0x0c0641b8u,4);
goto P_0c064122;
P_0c064122: /* original 4408, guest PC 0x0c064122 */
if(!s->budget--) { s->failed_pc=0x0c064122u; return 0; }
r[4]<<=2;
goto P_0c064124;
P_0c064124: /* original 4408, guest PC 0x0c064124 */
if(!s->budget--) { s->failed_pc=0x0c064124u; return 0; }
r[4]<<=2;
goto P_0c064126;
P_0c064126: /* original 4400, guest PC 0x0c064126 */
if(!s->budget--) { s->failed_pc=0x0c064126u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c064128;
P_0c064128: /* original 034e, guest PC 0x0c064128 */
if(!s->budget--) { s->failed_pc=0x0c064128u; return 0; }
r[3]=read(ram,r[4]+r[0],4);
goto P_0c06412a;
P_0c06412a: /* original 339c, guest PC 0x0c06412a */
if(!s->budget--) { s->failed_pc=0x0c06412au; return 0; }
r[3]+=r[9];
goto P_0c06412c;
P_0c06412c: /* original 923b, guest PC 0x0c06412c */
if(!s->budget--) { s->failed_pc=0x0c06412cu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0641a6u,2);
goto P_0c06412e;
P_0c06412e: /* original 7008, guest PC 0x0c06412e */
if(!s->budget--) { s->failed_pc=0x0c06412eu; return 0; }
r[0]+=0x00000008u;
goto P_0c064130;
P_0c064130: /* original 014e, guest PC 0x0c064130 */
if(!s->budget--) { s->failed_pc=0x0c064130u; return 0; }
r[1]=read(ram,r[4]+r[0],4);
goto P_0c064132;
P_0c064132: /* original 312c, guest PC 0x0c064132 */
if(!s->budget--) { s->failed_pc=0x0c064132u; return 0; }
r[1]+=r[2];
goto P_0c064134;
P_0c064134: /* original 3316, guest PC 0x0c064134 */
if(!s->budget--) { s->failed_pc=0x0c064134u; return 0; }
r[17]=(r[17]&~1u)|((r[3]>r[1])!=0);
goto P_0c064136;
P_0c064136: /* original 8b16, guest PC 0x0c064136 */
if(!s->budget--) { s->failed_pc=0x0c064136u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c064166; }
goto P_0c064138;
P_0c064138: /* original 53f1, guest PC 0x0c064138 */
if(!s->budget--) { s->failed_pc=0x0c064138u; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c06413a;
P_0c06413a: /* original 61e3, guest PC 0x0c06413a */
if(!s->budget--) { s->failed_pc=0x0c06413au; return 0; }
r[1]=r[14];
goto P_0c06413c;
P_0c06413c: /* original d01f, guest PC 0x0c06413c */
if(!s->budget--) { s->failed_pc=0x0c06413cu; return 0; }
r[0]=read(ram,0x0c0641bcu,4);
goto P_0c06413e;
P_0c06413e: /* original 7124, guest PC 0x0c06413e */
if(!s->budget--) { s->failed_pc=0x0c06413eu; return 0; }
r[1]+=0x00000024u;
goto P_0c064140;
P_0c064140: /* original 318c, guest PC 0x0c064140 */
if(!s->budget--) { s->failed_pc=0x0c064140u; return 0; }
r[1]+=r[8];
goto P_0c064142;
P_0c064142: /* original 303c, guest PC 0x0c064142 */
if(!s->budget--) { s->failed_pc=0x0c064142u; return 0; }
r[0]+=r[3];
goto P_0c064144;
P_0c064144: /* original 5304, guest PC 0x0c064144 */
if(!s->budget--) { s->failed_pc=0x0c064144u; return 0; }
r[3]=read(ram,r[0]+16,4);
goto P_0c064146;
P_0c064146: /* original 339c, guest PC 0x0c064146 */
if(!s->budget--) { s->failed_pc=0x0c064146u; return 0; }
r[3]+=r[9];
goto P_0c064148;
P_0c064148: /* original 6112, guest PC 0x0c064148 */
if(!s->budget--) { s->failed_pc=0x0c064148u; return 0; }
tmp=read(ram,r[1],4);
r[1]=tmp;
goto P_0c06414a;
P_0c06414a: /* original 3132, guest PC 0x0c06414a */
if(!s->budget--) { s->failed_pc=0x0c06414au; return 0; }
r[17]=(r[17]&~1u)|((r[1]>=r[3])!=0);
goto P_0c06414c;
P_0c06414c: /* original 8909, guest PC 0x0c06414c */
if(!s->budget--) { s->failed_pc=0x0c06414cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c064162; }
goto P_0c06414e;
P_0c06414e: /* original d01a, guest PC 0x0c06414e */
if(!s->budget--) { s->failed_pc=0x0c06414eu; return 0; }
r[0]=read(ram,0x0c0641b8u,4);
goto P_0c064150;
P_0c064150: /* original 932a, guest PC 0x0c064150 */
if(!s->budget--) { s->failed_pc=0x0c064150u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0641a8u,2);
goto P_0c064152;
P_0c064152: /* original 01ce, guest PC 0x0c064152 */
if(!s->budget--) { s->failed_pc=0x0c064152u; return 0; }
r[1]=read(ram,r[12]+r[0],4);
goto P_0c064154;
P_0c064154: /* original 3138, guest PC 0x0c064154 */
if(!s->budget--) { s->failed_pc=0x0c064154u; return 0; }
r[1]-=r[3];
goto P_0c064156;
P_0c064156: /* original 0c16, guest PC 0x0c064156 */
if(!s->budget--) { s->failed_pc=0x0c064156u; return 0; }
write(ram,r[12]+r[0],r[1],4);
goto P_0c064158;
P_0c064158: /* original 00ce, guest PC 0x0c064158 */
if(!s->budget--) { s->failed_pc=0x0c064158u; return 0; }
r[0]=read(ram,r[12]+r[0],4);
goto P_0c06415a;
P_0c06415a: /* original 30ac, guest PC 0x0c06415a */
if(!s->budget--) { s->failed_pc=0x0c06415au; return 0; }
r[0]+=r[10];
goto P_0c06415c;
P_0c06415c: /* original d114, guest PC 0x0c06415c */
if(!s->budget--) { s->failed_pc=0x0c06415cu; return 0; }
r[1]=read(ram,0x0c0641b0u,4);
goto P_0c06415e;
P_0c06415e: /* original 31cc, guest PC 0x0c06415e */
if(!s->budget--) { s->failed_pc=0x0c06415eu; return 0; }
r[1]+=r[12];
goto P_0c064160;
P_0c064160: /* original 2102, guest PC 0x0c064160 */
if(!s->budget--) { s->failed_pc=0x0c064160u; return 0; }
write(ram,r[1],r[0],4);
goto P_0c064162;
P_0c064162: /* original a007, guest PC 0x0c064162 */
if(!s->budget--) { s->failed_pc=0x0c064162u; return 0; }
write(ram,r[14]+16,r[13],4);
goto P_0c064174;
P_0c064164: /* original 1ed4, guest PC 0x0c064164 */
if(!s->budget--) { s->failed_pc=0x0c064164u; return 0; }
write(ram,r[14]+16,r[13],4);
goto P_0c064166;
P_0c064166: /* original e10a, guest PC 0x0c064166 */
if(!s->budget--) { s->failed_pc=0x0c064166u; return 0; }
r[1]=0x0000000au;
goto P_0c064168;
P_0c064168: /* original 53e4, guest PC 0x0c064168 */
if(!s->budget--) { s->failed_pc=0x0c064168u; return 0; }
r[3]=read(ram,r[14]+16,4);
goto P_0c06416a;
P_0c06416a: /* original 3316, guest PC 0x0c06416a */
if(!s->budget--) { s->failed_pc=0x0c06416au; return 0; }
r[17]=(r[17]&~1u)|((r[3]>r[1])!=0);
goto P_0c06416c;
P_0c06416c: /* original 8b02, guest PC 0x0c06416c */
if(!s->budget--) { s->failed_pc=0x0c06416cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c064174; }
goto P_0c06416e;
P_0c06416e: /* original d311, guest PC 0x0c06416e */
if(!s->budget--) { s->failed_pc=0x0c06416eu; return 0; }
r[3]=read(ram,0x0c0641b4u,4);
goto P_0c064170;
P_0c064170: /* original 430b, guest PC 0x0c064170 */
if(!s->budget--) { s->failed_pc=0x0c064170u; return 0; }
target=r[3];
r[16]=code_base|0x0c064174u;
r[4]=0x00000003u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c064174u) { target=s->pc; goto dispatch; }
goto P_0c064174;
P_0c064172: /* original e403, guest PC 0x0c064172 */
if(!s->budget--) { s->failed_pc=0x0c064172u; return 0; }
r[4]=0x00000003u;
goto P_0c064174;
P_0c064174: /* original 62f2, guest PC 0x0c064174 */
if(!s->budget--) { s->failed_pc=0x0c064174u; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c064176;
P_0c064176: /* original 7c20, guest PC 0x0c064176 */
if(!s->budget--) { s->failed_pc=0x0c064176u; return 0; }
r[12]+=0x00000020u;
goto P_0c064178;
P_0c064178: /* original 7201, guest PC 0x0c064178 */
if(!s->budget--) { s->failed_pc=0x0c064178u; return 0; }
r[2]+=0x00000001u;
goto P_0c06417a;
P_0c06417a: /* original 32b3, guest PC 0x0c06417a */
if(!s->budget--) { s->failed_pc=0x0c06417au; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[2]>=(int32_t)r[11])!=0);
goto P_0c06417c;
P_0c06417c: /* original 2f22, guest PC 0x0c06417c */
if(!s->budget--) { s->failed_pc=0x0c06417cu; return 0; }
write(ram,r[15],r[2],4);
goto P_0c06417e;
P_0c06417e: /* original 53f1, guest PC 0x0c06417e */
if(!s->budget--) { s->failed_pc=0x0c06417eu; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c064180;
P_0c064180: /* original 7320, guest PC 0x0c064180 */
if(!s->budget--) { s->failed_pc=0x0c064180u; return 0; }
r[3]+=0x00000020u;
goto P_0c064182;
P_0c064182: /* original 1f31, guest PC 0x0c064182 */
if(!s->budget--) { s->failed_pc=0x0c064182u; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c064184;
P_0c064184: /* original 8fcb, guest PC 0x0c064184 */
if(!s->budget--) { s->failed_pc=0x0c064184u; return 0; }
cond=r[17]&1u;
r[8]+=0x00000004u;
if(!cond) { goto P_0c06411e; }
goto P_0c064188;
P_0c064186: /* original 7804, guest PC 0x0c064186 */
if(!s->budget--) { s->failed_pc=0x0c064186u; return 0; }
r[8]+=0x00000004u;
goto P_0c064188;
P_0c064188: /* original e000, guest PC 0x0c064188 */
if(!s->budget--) { s->failed_pc=0x0c064188u; return 0; }
r[0]=0x00000000u;
goto P_0c06418a;
P_0c06418a: /* original 7f08, guest PC 0x0c06418a */
if(!s->budget--) { s->failed_pc=0x0c06418au; return 0; }
r[15]+=0x00000008u;
goto P_0c06418c;
P_0c06418c: /* original 4f26, guest PC 0x0c06418c */
if(!s->budget--) { s->failed_pc=0x0c06418cu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c06418e;
P_0c06418e: /* original 68f6, guest PC 0x0c06418e */
if(!s->budget--) { s->failed_pc=0x0c06418eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c064190;
P_0c064190: /* original 69f6, guest PC 0x0c064190 */
if(!s->budget--) { s->failed_pc=0x0c064190u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c064192;
P_0c064192: /* original 6af6, guest PC 0x0c064192 */
if(!s->budget--) { s->failed_pc=0x0c064192u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c064194;
P_0c064194: /* original 6bf6, guest PC 0x0c064194 */
if(!s->budget--) { s->failed_pc=0x0c064194u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c064196;
P_0c064196: /* original 6cf6, guest PC 0x0c064196 */
if(!s->budget--) { s->failed_pc=0x0c064196u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c064198;
P_0c064198: /* original 6df6, guest PC 0x0c064198 */
if(!s->budget--) { s->failed_pc=0x0c064198u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c06419a;
P_0c06419a: /* original 000b, guest PC 0x0c06419a */
if(!s->budget--) { s->failed_pc=0x0c06419au; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c06419c: /* original 6ef6, guest PC 0x0c06419c */
if(!s->budget--) { s->failed_pc=0x0c06419cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c06419eu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c06419eu; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
