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
int vf3_away_batch6_adapter_22(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c053f36u: goto P_0c053f36;
case 0x0c053f38u: goto P_0c053f38;
case 0x0c053f3au: goto P_0c053f3a;
case 0x0c053f3cu: goto P_0c053f3c;
case 0x0c053f3eu: goto P_0c053f3e;
case 0x0c053f40u: goto P_0c053f40;
case 0x0c053f42u: goto P_0c053f42;
case 0x0c053f44u: goto P_0c053f44;
case 0x0c053f46u: goto P_0c053f46;
case 0x0c053f48u: goto P_0c053f48;
case 0x0c053f4au: goto P_0c053f4a;
case 0x0c053f4cu: goto P_0c053f4c;
case 0x0c053f4eu: goto P_0c053f4e;
case 0x0c053f50u: goto P_0c053f50;
case 0x0c053f52u: goto P_0c053f52;
case 0x0c053f54u: goto P_0c053f54;
case 0x0c053f56u: goto P_0c053f56;
case 0x0c053f58u: goto P_0c053f58;
case 0x0c053f5au: goto P_0c053f5a;
case 0x0c053f5cu: goto P_0c053f5c;
case 0x0c053f5eu: goto P_0c053f5e;
case 0x0c053f60u: goto P_0c053f60;
case 0x0c053f62u: goto P_0c053f62;
case 0x0c053f64u: goto P_0c053f64;
case 0x0c053f66u: goto P_0c053f66;
case 0x0c053f68u: goto P_0c053f68;
case 0x0c053f6au: goto P_0c053f6a;
case 0x0c053f6cu: goto P_0c053f6c;
case 0x0c053f6eu: goto P_0c053f6e;
case 0x0c053f70u: goto P_0c053f70;
case 0x0c053f72u: goto P_0c053f72;
case 0x0c053f74u: goto P_0c053f74;
case 0x0c053f76u: goto P_0c053f76;
case 0x0c053f78u: goto P_0c053f78;
case 0x0c053f7au: goto P_0c053f7a;
case 0x0c053f7cu: goto P_0c053f7c;
case 0x0c053f7eu: goto P_0c053f7e;
case 0x0c053f80u: goto P_0c053f80;
case 0x0c053f82u: goto P_0c053f82;
case 0x0c053f84u: goto P_0c053f84;
case 0x0c053f86u: goto P_0c053f86;
case 0x0c053f88u: goto P_0c053f88;
case 0x0c053f8au: goto P_0c053f8a;
case 0x0c053f8cu: goto P_0c053f8c;
case 0x0c053f8eu: goto P_0c053f8e;
case 0x0c053f90u: goto P_0c053f90;
case 0x0c053f92u: goto P_0c053f92;
case 0x0c053f94u: goto P_0c053f94;
case 0x0c053f96u: goto P_0c053f96;
case 0x0c053f98u: goto P_0c053f98;
case 0x0c053f9au: goto P_0c053f9a;
case 0x0c053f9cu: goto P_0c053f9c;
case 0x0c053f9eu: goto P_0c053f9e;
case 0x0c053fa0u: goto P_0c053fa0;
case 0x0c053fa2u: goto P_0c053fa2;
case 0x0c053fa4u: goto P_0c053fa4;
case 0x0c053fa6u: goto P_0c053fa6;
case 0x0c053fa8u: goto P_0c053fa8;
case 0x0c053faau: goto P_0c053faa;
case 0x0c053facu: goto P_0c053fac;
case 0x0c053faeu: goto P_0c053fae;
case 0x0c053fb0u: goto P_0c053fb0;
case 0x0c053fb2u: goto P_0c053fb2;
case 0x0c053fb4u: goto P_0c053fb4;
case 0x0c053fb6u: goto P_0c053fb6;
case 0x0c053fb8u: goto P_0c053fb8;
case 0x0c053fbau: goto P_0c053fba;
case 0x0c053fbcu: goto P_0c053fbc;
case 0x0c053fbeu: goto P_0c053fbe;
case 0x0c053fc0u: goto P_0c053fc0;
case 0x0c053fc2u: goto P_0c053fc2;
case 0x0c053fc4u: goto P_0c053fc4;
case 0x0c053fc6u: goto P_0c053fc6;
case 0x0c053fc8u: goto P_0c053fc8;
case 0x0c053fcau: goto P_0c053fca;
case 0x0c053fccu: goto P_0c053fcc;
case 0x0c053fceu: goto P_0c053fce;
case 0x0c053fd0u: goto P_0c053fd0;
case 0x0c053fd2u: goto P_0c053fd2;
case 0x0c053fd4u: goto P_0c053fd4;
case 0x0c053fd6u: goto P_0c053fd6;
case 0x0c053fd8u: goto P_0c053fd8;
case 0x0c053fdau: goto P_0c053fda;
case 0x0c053fdcu: goto P_0c053fdc;
case 0x0c053fdeu: goto P_0c053fde;
case 0x0c053fe0u: goto P_0c053fe0;
case 0x0c053fe2u: goto P_0c053fe2;
case 0x0c053fe4u: goto P_0c053fe4;
case 0x0c053fe6u: goto P_0c053fe6;
case 0x0c053fe8u: goto P_0c053fe8;
case 0x0c053feau: goto P_0c053fea;
case 0x0c053fecu: goto P_0c053fec;
case 0x0c053feeu: goto P_0c053fee;
case 0x0c053ff0u: goto P_0c053ff0;
case 0x0c053ff2u: goto P_0c053ff2;
case 0x0c053ff4u: goto P_0c053ff4;
case 0x0c053ff6u: goto P_0c053ff6;
case 0x0c053ff8u: goto P_0c053ff8;
case 0x0c053ffau: goto P_0c053ffa;
case 0x0c053ffcu: goto P_0c053ffc;
case 0x0c053ffeu: goto P_0c053ffe;
case 0x0c054000u: goto P_0c054000;
case 0x0c054002u: goto P_0c054002;
case 0x0c054004u: goto P_0c054004;
case 0x0c054006u: goto P_0c054006;
case 0x0c054008u: goto P_0c054008;
case 0x0c05400au: goto P_0c05400a;
case 0x0c05400cu: goto P_0c05400c;
case 0x0c05400eu: goto P_0c05400e;
case 0x0c054010u: goto P_0c054010;
case 0x0c054012u: goto P_0c054012;
case 0x0c054014u: goto P_0c054014;
case 0x0c054016u: goto P_0c054016;
case 0x0c054018u: goto P_0c054018;
case 0x0c05404cu: goto P_0c05404c;
case 0x0c05404eu: goto P_0c05404e;
case 0x0c054050u: goto P_0c054050;
case 0x0c054052u: goto P_0c054052;
case 0x0c054054u: goto P_0c054054;
case 0x0c054056u: goto P_0c054056;
case 0x0c054058u: goto P_0c054058;
case 0x0c05405au: goto P_0c05405a;
case 0x0c05405cu: goto P_0c05405c;
case 0x0c05405eu: goto P_0c05405e;
case 0x0c054060u: goto P_0c054060;
case 0x0c054062u: goto P_0c054062;
case 0x0c054064u: goto P_0c054064;
case 0x0c054066u: goto P_0c054066;
case 0x0c054068u: goto P_0c054068;
case 0x0c05406au: goto P_0c05406a;
case 0x0c05406cu: goto P_0c05406c;
case 0x0c05406eu: goto P_0c05406e;
case 0x0c054070u: goto P_0c054070;
case 0x0c054072u: goto P_0c054072;
case 0x0c054074u: goto P_0c054074;
case 0x0c054076u: goto P_0c054076;
case 0x0c054078u: goto P_0c054078;
case 0x0c05407au: goto P_0c05407a;
case 0x0c05407cu: goto P_0c05407c;
case 0x0c05407eu: goto P_0c05407e;
case 0x0c054080u: goto P_0c054080;
case 0x0c054082u: goto P_0c054082;
case 0x0c054084u: goto P_0c054084;
case 0x0c054086u: goto P_0c054086;
case 0x0c054088u: goto P_0c054088;
case 0x0c05408au: goto P_0c05408a;
case 0x0c05408cu: goto P_0c05408c;
case 0x0c05408eu: goto P_0c05408e;
case 0x0c054090u: goto P_0c054090;
case 0x0c054092u: goto P_0c054092;
case 0x0c054094u: goto P_0c054094;
case 0x0c054096u: goto P_0c054096;
case 0x0c054098u: goto P_0c054098;
case 0x0c05409au: goto P_0c05409a;
case 0x0c05409cu: goto P_0c05409c;
case 0x0c05409eu: goto P_0c05409e;
case 0x0c0540a0u: goto P_0c0540a0;
case 0x0c0540a2u: goto P_0c0540a2;
case 0x0c0540a4u: goto P_0c0540a4;
case 0x0c0540a6u: goto P_0c0540a6;
case 0x0c0540a8u: goto P_0c0540a8;
case 0x0c0540aau: goto P_0c0540aa;
case 0x0c0540acu: goto P_0c0540ac;
case 0x0c0540aeu: goto P_0c0540ae;
case 0x0c0540b0u: goto P_0c0540b0;
case 0x0c0540b2u: goto P_0c0540b2;
case 0x0c0540b4u: goto P_0c0540b4;
case 0x0c0540b6u: goto P_0c0540b6;
case 0x0c0540b8u: goto P_0c0540b8;
case 0x0c0540bau: goto P_0c0540ba;
case 0x0c0540bcu: goto P_0c0540bc;
case 0x0c0540beu: goto P_0c0540be;
case 0x0c0540c0u: goto P_0c0540c0;
case 0x0c0540c2u: goto P_0c0540c2;
case 0x0c0540c4u: goto P_0c0540c4;
case 0x0c0540c6u: goto P_0c0540c6;
case 0x0c0540c8u: goto P_0c0540c8;
case 0x0c0540cau: goto P_0c0540ca;
case 0x0c0540ccu: goto P_0c0540cc;
case 0x0c0540ceu: goto P_0c0540ce;
case 0x0c0540d0u: goto P_0c0540d0;
case 0x0c0540d2u: goto P_0c0540d2;
case 0x0c0540d4u: goto P_0c0540d4;
case 0x0c0540d6u: goto P_0c0540d6;
case 0x0c0540d8u: goto P_0c0540d8;
case 0x0c0540dau: goto P_0c0540da;
case 0x0c0540dcu: goto P_0c0540dc;
case 0x0c0540deu: goto P_0c0540de;
case 0x0c0540e0u: goto P_0c0540e0;
case 0x0c0540e2u: goto P_0c0540e2;
case 0x0c0540e4u: goto P_0c0540e4;
case 0x0c0540e6u: goto P_0c0540e6;
case 0x0c0540e8u: goto P_0c0540e8;
case 0x0c0540eau: goto P_0c0540ea;
case 0x0c0540ecu: goto P_0c0540ec;
case 0x0c0540eeu: goto P_0c0540ee;
case 0x0c0540f0u: goto P_0c0540f0;
case 0x0c0540f2u: goto P_0c0540f2;
case 0x0c0540f4u: goto P_0c0540f4;
case 0x0c0540f6u: goto P_0c0540f6;
case 0x0c0540f8u: goto P_0c0540f8;
case 0x0c0540fau: goto P_0c0540fa;
case 0x0c0540fcu: goto P_0c0540fc;
case 0x0c0540feu: goto P_0c0540fe;
case 0x0c054100u: goto P_0c054100;
case 0x0c054102u: goto P_0c054102;
case 0x0c054104u: goto P_0c054104;
case 0x0c054106u: goto P_0c054106;
case 0x0c054108u: goto P_0c054108;
case 0x0c05410au: goto P_0c05410a;
case 0x0c05410cu: goto P_0c05410c;
case 0x0c05410eu: goto P_0c05410e;
case 0x0c054110u: goto P_0c054110;
case 0x0c054112u: goto P_0c054112;
case 0x0c054114u: goto P_0c054114;
case 0x0c054116u: goto P_0c054116;
case 0x0c054118u: goto P_0c054118;
case 0x0c05411au: goto P_0c05411a;
case 0x0c05411cu: goto P_0c05411c;
case 0x0c05411eu: goto P_0c05411e;
case 0x0c054120u: goto P_0c054120;
case 0x0c054122u: goto P_0c054122;
case 0x0c054124u: goto P_0c054124;
case 0x0c054126u: goto P_0c054126;
case 0x0c054140u: goto P_0c054140;
case 0x0c054142u: goto P_0c054142;
case 0x0c054144u: goto P_0c054144;
case 0x0c054146u: goto P_0c054146;
case 0x0c054148u: goto P_0c054148;
case 0x0c05414au: goto P_0c05414a;
case 0x0c05414cu: goto P_0c05414c;
case 0x0c05414eu: goto P_0c05414e;
case 0x0c054150u: goto P_0c054150;
case 0x0c054152u: goto P_0c054152;
case 0x0c054154u: goto P_0c054154;
case 0x0c054156u: goto P_0c054156;
case 0x0c054158u: goto P_0c054158;
case 0x0c05415au: goto P_0c05415a;
case 0x0c05415cu: goto P_0c05415c;
case 0x0c05415eu: goto P_0c05415e;
case 0x0c054160u: goto P_0c054160;
case 0x0c054162u: goto P_0c054162;
case 0x0c054164u: goto P_0c054164;
case 0x0c054166u: goto P_0c054166;
case 0x0c054168u: goto P_0c054168;
case 0x0c05416au: goto P_0c05416a;
case 0x0c05416cu: goto P_0c05416c;
case 0x0c05416eu: goto P_0c05416e;
case 0x0c054170u: goto P_0c054170;
case 0x0c054172u: goto P_0c054172;
case 0x0c054174u: goto P_0c054174;
case 0x0c054176u: goto P_0c054176;
case 0x0c054178u: goto P_0c054178;
case 0x0c05417au: goto P_0c05417a;
case 0x0c05417cu: goto P_0c05417c;
case 0x0c05417eu: goto P_0c05417e;
case 0x0c054180u: goto P_0c054180;
case 0x0c054182u: goto P_0c054182;
case 0x0c054184u: goto P_0c054184;
case 0x0c054186u: goto P_0c054186;
case 0x0c054188u: goto P_0c054188;
case 0x0c05418au: goto P_0c05418a;
case 0x0c05418cu: goto P_0c05418c;
case 0x0c05418eu: goto P_0c05418e;
case 0x0c054190u: goto P_0c054190;
case 0x0c054192u: goto P_0c054192;
case 0x0c054194u: goto P_0c054194;
case 0x0c054196u: goto P_0c054196;
case 0x0c054198u: goto P_0c054198;
case 0x0c05419au: goto P_0c05419a;
case 0x0c05419cu: goto P_0c05419c;
case 0x0c05419eu: goto P_0c05419e;
case 0x0c0541a0u: goto P_0c0541a0;
case 0x0c0541a2u: goto P_0c0541a2;
case 0x0c0541a4u: goto P_0c0541a4;
case 0x0c0541a6u: goto P_0c0541a6;
case 0x0c0541a8u: goto P_0c0541a8;
case 0x0c0541aau: goto P_0c0541aa;
case 0x0c0541acu: goto P_0c0541ac;
case 0x0c0541aeu: goto P_0c0541ae;
case 0x0c0541b0u: goto P_0c0541b0;
case 0x0c0541b2u: goto P_0c0541b2;
case 0x0c0541b4u: goto P_0c0541b4;
case 0x0c0541b6u: goto P_0c0541b6;
case 0x0c0541b8u: goto P_0c0541b8;
case 0x0c0541bau: goto P_0c0541ba;
case 0x0c0541bcu: goto P_0c0541bc;
case 0x0c0541beu: goto P_0c0541be;
case 0x0c0541c0u: goto P_0c0541c0;
case 0x0c0541c2u: goto P_0c0541c2;
case 0x0c0541c4u: goto P_0c0541c4;
case 0x0c0541c6u: goto P_0c0541c6;
case 0x0c0541c8u: goto P_0c0541c8;
case 0x0c0541cau: goto P_0c0541ca;
case 0x0c0541ccu: goto P_0c0541cc;
case 0x0c0541ceu: goto P_0c0541ce;
case 0x0c0541d0u: goto P_0c0541d0;
case 0x0c0541d2u: goto P_0c0541d2;
case 0x0c0541d4u: goto P_0c0541d4;
case 0x0c0541d6u: goto P_0c0541d6;
case 0x0c0541d8u: goto P_0c0541d8;
case 0x0c0541dau: goto P_0c0541da;
default: return vf3_matrix_family(target,s,ram);
}
P_0c053f36: /* original 2fe6, guest PC 0x0c053f36 */
if(!s->budget--) { s->failed_pc=0x0c053f36u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c053f38;
P_0c053f38: /* original 2fd6, guest PC 0x0c053f38 */
if(!s->budget--) { s->failed_pc=0x0c053f38u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c053f3a;
P_0c053f3a: /* original 6e43, guest PC 0x0c053f3a */
if(!s->budget--) { s->failed_pc=0x0c053f3au; return 0; }
r[14]=r[4];
goto P_0c053f3c;
P_0c053f3c: /* original d23f, guest PC 0x0c053f3c */
if(!s->budget--) { s->failed_pc=0x0c053f3cu; return 0; }
r[2]=read(ram,0x0c05403cu,4);
goto P_0c053f3e;
P_0c053f3e: /* original 2fc6, guest PC 0x0c053f3e */
if(!s->budget--) { s->failed_pc=0x0c053f3eu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c053f40;
P_0c053f40: /* original 2fb6, guest PC 0x0c053f40 */
if(!s->budget--) { s->failed_pc=0x0c053f40u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c053f42;
P_0c053f42: /* original 2fa6, guest PC 0x0c053f42 */
if(!s->budget--) { s->failed_pc=0x0c053f42u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c053f44;
P_0c053f44: /* original 2f96, guest PC 0x0c053f44 */
if(!s->budget--) { s->failed_pc=0x0c053f44u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c053f46;
P_0c053f46: /* original 2f86, guest PC 0x0c053f46 */
if(!s->budget--) { s->failed_pc=0x0c053f46u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c053f48;
P_0c053f48: /* original 4f22, guest PC 0x0c053f48 */
if(!s->budget--) { s->failed_pc=0x0c053f48u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c053f4a;
P_0c053f4a: /* original 7fec, guest PC 0x0c053f4a */
if(!s->budget--) { s->failed_pc=0x0c053f4au; return 0; }
r[15]+=0xffffffecu;
goto P_0c053f4c;
P_0c053f4c: /* original d83a, guest PC 0x0c053f4c */
if(!s->budget--) { s->failed_pc=0x0c053f4cu; return 0; }
r[8]=read(ram,0x0c054038u,4);
goto P_0c053f4e;
P_0c053f4e: /* original 53ff, guest PC 0x0c053f4e */
if(!s->budget--) { s->failed_pc=0x0c053f4eu; return 0; }
r[3]=read(ram,r[15]+60,4);
goto P_0c053f50;
P_0c053f50: /* original 2f36, guest PC 0x0c053f50 */
if(!s->budget--) { s->failed_pc=0x0c053f50u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c053f52;
P_0c053f52: /* original 53ff, guest PC 0x0c053f52 */
if(!s->budget--) { s->failed_pc=0x0c053f52u; return 0; }
r[3]=read(ram,r[15]+60,4);
goto P_0c053f54;
P_0c053f54: /* original 420b, guest PC 0x0c053f54 */
if(!s->budget--) { s->failed_pc=0x0c053f54u; return 0; }
target=r[2];
r[16]=code_base|0x0c053f58u;
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c053f58u) { target=s->pc; goto dispatch; }
goto P_0c053f58;
P_0c053f56: /* original 2f36, guest PC 0x0c053f56 */
if(!s->budget--) { s->failed_pc=0x0c053f56u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c053f58;
P_0c053f58: /* original 7f08, guest PC 0x0c053f58 */
if(!s->budget--) { s->failed_pc=0x0c053f58u; return 0; }
r[15]+=0x00000008u;
goto P_0c053f5a;
P_0c053f5a: /* original 2008, guest PC 0x0c053f5a */
if(!s->budget--) { s->failed_pc=0x0c053f5au; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c053f5c;
P_0c053f5c: /* original 8d1d, guest PC 0x0c053f5c */
if(!s->budget--) { s->failed_pc=0x0c053f5cu; return 0; }
cond=r[17]&1u;
r[4]=r[0];
if(cond) { goto P_0c053f9a; }
goto P_0c053f60;
P_0c053f5e: /* original 6403, guest PC 0x0c053f5e */
if(!s->budget--) { s->failed_pc=0x0c053f5eu; return 0; }
r[4]=r[0];
goto P_0c053f60;
P_0c053f60: /* original 6043, guest PC 0x0c053f60 */
if(!s->budget--) { s->failed_pc=0x0c053f60u; return 0; }
r[0]=r[4];
goto P_0c053f62;
P_0c053f62: /* original 0009, guest PC 0x0c053f62 */
if(!s->budget--) { s->failed_pc=0x0c053f62u; return 0; }
goto P_0c053f64;
P_0c053f64: /* original 8801, guest PC 0x0c053f64 */
if(!s->budget--) { s->failed_pc=0x0c053f64u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c053f66;
P_0c053f66: /* original 8f03, guest PC 0x0c053f66 */
if(!s->budget--) { s->failed_pc=0x0c053f66u; return 0; }
cond=r[17]&1u;
r[0]=r[4];
if(!cond) { goto P_0c053f70; }
goto P_0c053f6a;
P_0c053f68: /* original 6043, guest PC 0x0c053f68 */
if(!s->budget--) { s->failed_pc=0x0c053f68u; return 0; }
r[0]=r[4];
goto P_0c053f6a;
P_0c053f6a: /* original 9356, guest PC 0x0c053f6a */
if(!s->budget--) { s->failed_pc=0x0c053f6au; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c05401au,2);
goto P_0c053f6c;
P_0c053f6c: /* original d234, guest PC 0x0c053f6c */
if(!s->budget--) { s->failed_pc=0x0c053f6cu; return 0; }
r[2]=read(ram,0x0c054040u,4);
goto P_0c053f6e;
P_0c053f6e: /* original 2232, guest PC 0x0c053f6e */
if(!s->budget--) { s->failed_pc=0x0c053f6eu; return 0; }
write(ram,r[2],r[3],4);
goto P_0c053f70;
P_0c053f70: /* original 8802, guest PC 0x0c053f70 */
if(!s->budget--) { s->failed_pc=0x0c053f70u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c053f72;
P_0c053f72: /* original 8f03, guest PC 0x0c053f72 */
if(!s->budget--) { s->failed_pc=0x0c053f72u; return 0; }
cond=r[17]&1u;
r[4]=0xffffffffu;
if(!cond) { goto P_0c053f7c; }
goto P_0c053f76;
P_0c053f74: /* original e4ff, guest PC 0x0c053f74 */
if(!s->budget--) { s->failed_pc=0x0c053f74u; return 0; }
r[4]=0xffffffffu;
goto P_0c053f76;
P_0c053f76: /* original 9251, guest PC 0x0c053f76 */
if(!s->budget--) { s->failed_pc=0x0c053f76u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c05401cu,2);
goto P_0c053f78;
P_0c053f78: /* original d331, guest PC 0x0c053f78 */
if(!s->budget--) { s->failed_pc=0x0c053f78u; return 0; }
r[3]=read(ram,0x0c054040u,4);
goto P_0c053f7a;
P_0c053f7a: /* original 2322, guest PC 0x0c053f7a */
if(!s->budget--) { s->failed_pc=0x0c053f7au; return 0; }
write(ram,r[3],r[2],4);
goto P_0c053f7c;
P_0c053f7c: /* original 62f3, guest PC 0x0c053f7c */
if(!s->budget--) { s->failed_pc=0x0c053f7cu; return 0; }
r[2]=r[15];
goto P_0c053f7e;
P_0c053f7e: /* original 7238, guest PC 0x0c053f7e */
if(!s->budget--) { s->failed_pc=0x0c053f7eu; return 0; }
r[2]+=0x00000038u;
goto P_0c053f80;
P_0c053f80: /* original 2242, guest PC 0x0c053f80 */
if(!s->budget--) { s->failed_pc=0x0c053f80u; return 0; }
write(ram,r[2],r[4],4);
goto P_0c053f82;
P_0c053f82: /* original 63f3, guest PC 0x0c053f82 */
if(!s->budget--) { s->failed_pc=0x0c053f82u; return 0; }
r[3]=r[15];
goto P_0c053f84;
P_0c053f84: /* original 7338, guest PC 0x0c053f84 */
if(!s->budget--) { s->failed_pc=0x0c053f84u; return 0; }
r[3]+=0x00000038u;
goto P_0c053f86;
P_0c053f86: /* original 1341, guest PC 0x0c053f86 */
if(!s->budget--) { s->failed_pc=0x0c053f86u; return 0; }
write(ram,r[3]+4,r[4],4);
goto P_0c053f88;
P_0c053f88: /* original 51fd, guest PC 0x0c053f88 */
if(!s->budget--) { s->failed_pc=0x0c053f88u; return 0; }
r[1]=read(ram,r[15]+52,4);
goto P_0c053f8a;
P_0c053f8a: /* original 63f3, guest PC 0x0c053f8a */
if(!s->budget--) { s->failed_pc=0x0c053f8au; return 0; }
r[3]=r[15];
goto P_0c053f8c;
P_0c053f8c: /* original 7338, guest PC 0x0c053f8c */
if(!s->budget--) { s->failed_pc=0x0c053f8cu; return 0; }
r[3]+=0x00000038u;
goto P_0c053f8e;
P_0c053f8e: /* original 6032, guest PC 0x0c053f8e */
if(!s->budget--) { s->failed_pc=0x0c053f8eu; return 0; }
tmp=read(ram,r[3],4);
r[0]=tmp;
goto P_0c053f90;
P_0c053f90: /* original 2102, guest PC 0x0c053f90 */
if(!s->budget--) { s->failed_pc=0x0c053f90u; return 0; }
write(ram,r[1],r[0],4);
goto P_0c053f92;
P_0c053f92: /* original 5031, guest PC 0x0c053f92 */
if(!s->budget--) { s->failed_pc=0x0c053f92u; return 0; }
r[0]=read(ram,r[3]+4,4);
goto P_0c053f94;
P_0c053f94: /* original 1101, guest PC 0x0c053f94 */
if(!s->budget--) { s->failed_pc=0x0c053f94u; return 0; }
write(ram,r[1]+4,r[0],4);
goto P_0c053f96;
P_0c053f96: /* original a07d, guest PC 0x0c053f96 */
if(!s->budget--) { s->failed_pc=0x0c053f96u; return 0; }
goto P_0c054094;
P_0c053f98: /* original 0009, guest PC 0x0c053f98 */
if(!s->budget--) { s->failed_pc=0x0c053f98u; return 0; }
goto P_0c053f9a;
P_0c053f9a: /* original e200, guest PC 0x0c053f9a */
if(!s->budget--) { s->failed_pc=0x0c053f9au; return 0; }
r[2]=0x00000000u;
goto P_0c053f9c;
P_0c053f9c: /* original 53ff, guest PC 0x0c053f9c */
if(!s->budget--) { s->failed_pc=0x0c053f9cu; return 0; }
r[3]=read(ram,r[15]+60,4);
goto P_0c053f9e;
P_0c053f9e: /* original 2f36, guest PC 0x0c053f9e */
if(!s->budget--) { s->failed_pc=0x0c053f9eu; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c053fa0;
P_0c053fa0: /* original 53ff, guest PC 0x0c053fa0 */
if(!s->budget--) { s->failed_pc=0x0c053fa0u; return 0; }
r[3]=read(ram,r[15]+60,4);
goto P_0c053fa2;
P_0c053fa2: /* original 2f36, guest PC 0x0c053fa2 */
if(!s->budget--) { s->failed_pc=0x0c053fa2u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c053fa4;
P_0c053fa4: /* original 2f26, guest PC 0x0c053fa4 */
if(!s->budget--) { s->failed_pc=0x0c053fa4u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c053fa6;
P_0c053fa6: /* original d327, guest PC 0x0c053fa6 */
if(!s->budget--) { s->failed_pc=0x0c053fa6u; return 0; }
r[3]=read(ram,0x0c054044u,4);
goto P_0c053fa8;
P_0c053fa8: /* original 430b, guest PC 0x0c053fa8 */
if(!s->budget--) { s->failed_pc=0x0c053fa8u; return 0; }
target=r[3];
r[16]=code_base|0x0c053facu;
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c053facu) { target=s->pc; goto dispatch; }
goto P_0c053fac;
P_0c053faa: /* original 2f26, guest PC 0x0c053faa */
if(!s->budget--) { s->failed_pc=0x0c053faau; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c053fac;
P_0c053fac: /* original 8800, guest PC 0x0c053fac */
if(!s->budget--) { s->failed_pc=0x0c053facu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000000u)!=0);
goto P_0c053fae;
P_0c053fae: /* original 8f09, guest PC 0x0c053fae */
if(!s->budget--) { s->failed_pc=0x0c053faeu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c053fc4; }
goto P_0c053fb2;
P_0c053fb0: /* original 0009, guest PC 0x0c053fb0 */
if(!s->budget--) { s->failed_pc=0x0c053fb0u; return 0; }
goto P_0c053fb2;
P_0c053fb2: /* original e200, guest PC 0x0c053fb2 */
if(!s->budget--) { s->failed_pc=0x0c053fb2u; return 0; }
r[2]=0x00000000u;
goto P_0c053fb4;
P_0c053fb4: /* original 2e22, guest PC 0x0c053fb4 */
if(!s->budget--) { s->failed_pc=0x0c053fb4u; return 0; }
write(ram,r[14],r[2],4);
goto P_0c053fb6;
P_0c053fb6: /* original 51fd, guest PC 0x0c053fb6 */
if(!s->budget--) { s->failed_pc=0x0c053fb6u; return 0; }
r[1]=read(ram,r[15]+52,4);
goto P_0c053fb8;
P_0c053fb8: /* original 6023, guest PC 0x0c053fb8 */
if(!s->budget--) { s->failed_pc=0x0c053fb8u; return 0; }
r[0]=r[2];
goto P_0c053fba;
P_0c053fba: /* original 0009, guest PC 0x0c053fba */
if(!s->budget--) { s->failed_pc=0x0c053fbau; return 0; }
goto P_0c053fbc;
P_0c053fbc: /* original 2122, guest PC 0x0c053fbc */
if(!s->budget--) { s->failed_pc=0x0c053fbcu; return 0; }
write(ram,r[1],r[2],4);
goto P_0c053fbe;
P_0c053fbe: /* original 1101, guest PC 0x0c053fbe */
if(!s->budget--) { s->failed_pc=0x0c053fbeu; return 0; }
write(ram,r[1]+4,r[0],4);
goto P_0c053fc0;
P_0c053fc0: /* original a068, guest PC 0x0c053fc0 */
if(!s->budget--) { s->failed_pc=0x0c053fc0u; return 0; }
goto P_0c054094;
P_0c053fc2: /* original 0009, guest PC 0x0c053fc2 */
if(!s->budget--) { s->failed_pc=0x0c053fc2u; return 0; }
goto P_0c053fc4;
P_0c053fc4: /* original 932b, guest PC 0x0c053fc4 */
if(!s->budget--) { s->failed_pc=0x0c053fc4u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c05401eu,2);
goto P_0c053fc6;
P_0c053fc6: /* original 6df3, guest PC 0x0c053fc6 */
if(!s->budget--) { s->failed_pc=0x0c053fc6u; return 0; }
r[13]=r[15];
goto P_0c053fc8;
P_0c053fc8: /* original 922a, guest PC 0x0c053fc8 */
if(!s->budget--) { s->failed_pc=0x0c053fc8u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c054020u,2);
goto P_0c053fca;
P_0c053fca: /* original 7d38, guest PC 0x0c053fca */
if(!s->budget--) { s->failed_pc=0x0c053fcau; return 0; }
r[13]+=0x00000038u;
goto P_0c053fcc;
P_0c053fcc: /* original 9129, guest PC 0x0c053fcc */
if(!s->budget--) { s->failed_pc=0x0c053fccu; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c054022u,2);
goto P_0c053fce;
P_0c053fce: /* original 64d3, guest PC 0x0c053fce */
if(!s->budget--) { s->failed_pc=0x0c053fceu; return 0; }
r[4]=r[13];
goto P_0c053fd0;
P_0c053fd0: /* original 7406, guest PC 0x0c053fd0 */
if(!s->budget--) { s->failed_pc=0x0c053fd0u; return 0; }
r[4]+=0x00000006u;
goto P_0c053fd2;
P_0c053fd2: /* original 2f42, guest PC 0x0c053fd2 */
if(!s->budget--) { s->failed_pc=0x0c053fd2u; return 0; }
write(ram,r[15],r[4],4);
goto P_0c053fd4;
P_0c053fd4: /* original 6441, guest PC 0x0c053fd4 */
if(!s->budget--) { s->failed_pc=0x0c053fd4u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[4],2);
r[4]=tmp;
goto P_0c053fd6;
P_0c053fd6: /* original 644d, guest PC 0x0c053fd6 */
if(!s->budget--) { s->failed_pc=0x0c053fd6u; return 0; }
r[4]=r[4]&65535u;
goto P_0c053fd8;
P_0c053fd8: /* original 4409, guest PC 0x0c053fd8 */
if(!s->budget--) { s->failed_pc=0x0c053fd8u; return 0; }
r[4]>>=2;
goto P_0c053fda;
P_0c053fda: /* original 4409, guest PC 0x0c053fda */
if(!s->budget--) { s->failed_pc=0x0c053fdau; return 0; }
r[4]>>=2;
goto P_0c053fdc;
P_0c053fdc: /* original 2439, guest PC 0x0c053fdc */
if(!s->budget--) { s->failed_pc=0x0c053fdcu; return 0; }
r[4]&=r[3];
goto P_0c053fde;
P_0c053fde: /* original 342c, guest PC 0x0c053fde */
if(!s->budget--) { s->failed_pc=0x0c053fdeu; return 0; }
r[4]+=r[2];
goto P_0c053fe0;
P_0c053fe0: /* original 6043, guest PC 0x0c053fe0 */
if(!s->budget--) { s->failed_pc=0x0c053fe0u; return 0; }
r[0]=r[4];
goto P_0c053fe2;
P_0c053fe2: /* original 0009, guest PC 0x0c053fe2 */
if(!s->budget--) { s->failed_pc=0x0c053fe2u; return 0; }
goto P_0c053fe4;
P_0c053fe4: /* original 301c, guest PC 0x0c053fe4 */
if(!s->budget--) { s->failed_pc=0x0c053fe4u; return 0; }
r[0]+=r[1];
goto P_0c053fe6;
P_0c053fe6: /* original 2008, guest PC 0x0c053fe6 */
if(!s->budget--) { s->failed_pc=0x0c053fe6u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c053fe8;
P_0c053fe8: /* original 8f44, guest PC 0x0c053fe8 */
if(!s->budget--) { s->failed_pc=0x0c053fe8u; return 0; }
cond=r[17]&1u;
write(ram,r[14],r[4],4);
if(!cond) { goto P_0c054074; }
goto P_0c053fec;
P_0c053fea: /* original 2e42, guest PC 0x0c053fea */
if(!s->budget--) { s->failed_pc=0x0c053feau; return 0; }
write(ram,r[14],r[4],4);
goto P_0c053fec;
P_0c053fec: /* original 63e2, guest PC 0x0c053fec */
if(!s->budget--) { s->failed_pc=0x0c053fecu; return 0; }
tmp=read(ram,r[14],4);
r[3]=tmp;
goto P_0c053fee;
P_0c053fee: /* original 6af3, guest PC 0x0c053fee */
if(!s->budget--) { s->failed_pc=0x0c053feeu; return 0; }
r[10]=r[15];
goto P_0c053ff0;
P_0c053ff0: /* original dc15, guest PC 0x0c053ff0 */
if(!s->budget--) { s->failed_pc=0x0c053ff0u; return 0; }
r[12]=read(ram,0x0c054048u,4);
goto P_0c053ff2;
P_0c053ff2: /* original 65d3, guest PC 0x0c053ff2 */
if(!s->budget--) { s->failed_pc=0x0c053ff2u; return 0; }
r[5]=r[13];
goto P_0c053ff4;
P_0c053ff4: /* original 7301, guest PC 0x0c053ff4 */
if(!s->budget--) { s->failed_pc=0x0c053ff4u; return 0; }
r[3]+=0x00000001u;
goto P_0c053ff6;
P_0c053ff6: /* original 7a0c, guest PC 0x0c053ff6 */
if(!s->budget--) { s->failed_pc=0x0c053ff6u; return 0; }
r[10]+=0x0000000cu;
goto P_0c053ff8;
P_0c053ff8: /* original 2e32, guest PC 0x0c053ff8 */
if(!s->budget--) { s->failed_pc=0x0c053ff8u; return 0; }
write(ram,r[14],r[3],4);
goto P_0c053ffa;
P_0c053ffa: /* original 7504, guest PC 0x0c053ffa */
if(!s->budget--) { s->failed_pc=0x0c053ffau; return 0; }
r[5]+=0x00000004u;
goto P_0c053ffc;
P_0c053ffc: /* original 63f2, guest PC 0x0c053ffc */
if(!s->budget--) { s->failed_pc=0x0c053ffcu; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c053ffe;
P_0c053ffe: /* original 6031, guest PC 0x0c053ffe */
if(!s->budget--) { s->failed_pc=0x0c053ffeu; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[3],2);
r[0]=tmp;
goto P_0c054000;
P_0c054000: /* original 2089, guest PC 0x0c054000 */
if(!s->budget--) { s->failed_pc=0x0c054000u; return 0; }
r[0]&=r[8];
goto P_0c054002;
P_0c054002: /* original 2301, guest PC 0x0c054002 */
if(!s->budget--) { s->failed_pc=0x0c054002u; return 0; }
write(ram,r[3],r[0],2);
goto P_0c054004;
P_0c054004: /* original 1f51, guest PC 0x0c054004 */
if(!s->budget--) { s->failed_pc=0x0c054004u; return 0; }
write(ram,r[15]+4,r[5],4);
goto P_0c054006;
P_0c054006: /* original 4c0b, guest PC 0x0c054006 */
if(!s->budget--) { s->failed_pc=0x0c054006u; return 0; }
target=r[12];
r[16]=code_base|0x0c05400au;
r[4]=r[10];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c05400au) { target=s->pc; goto dispatch; }
goto P_0c05400a;
P_0c054008: /* original 64a3, guest PC 0x0c054008 */
if(!s->budget--) { s->failed_pc=0x0c054008u; return 0; }
r[4]=r[10];
goto P_0c05400a;
P_0c05400a: /* original 65d3, guest PC 0x0c05400a */
if(!s->budget--) { s->failed_pc=0x0c05400au; return 0; }
r[5]=r[13];
goto P_0c05400c;
P_0c05400c: /* original 64a3, guest PC 0x0c05400c */
if(!s->budget--) { s->failed_pc=0x0c05400cu; return 0; }
r[4]=r[10];
goto P_0c05400e;
P_0c05400e: /* original 4c0b, guest PC 0x0c05400e */
if(!s->budget--) { s->failed_pc=0x0c05400eu; return 0; }
target=r[12];
r[16]=code_base|0x0c054012u;
r[4]+=0x00000004u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c054012u) { target=s->pc; goto dispatch; }
goto P_0c054012;
P_0c054010: /* original 7404, guest PC 0x0c054010 */
if(!s->budget--) { s->failed_pc=0x0c054010u; return 0; }
r[4]+=0x00000004u;
goto P_0c054012;
P_0c054012: /* original 6ba3, guest PC 0x0c054012 */
if(!s->budget--) { s->failed_pc=0x0c054012u; return 0; }
r[11]=r[10];
goto P_0c054014;
P_0c054014: /* original 7b01, guest PC 0x0c054014 */
if(!s->budget--) { s->failed_pc=0x0c054014u; return 0; }
r[11]+=0x00000001u;
goto P_0c054016;
P_0c054016: /* original a020, guest PC 0x0c054016 */
if(!s->budget--) { s->failed_pc=0x0c054016u; return 0; }
r[9]=0x00000010u;
goto P_0c05405a;
P_0c054018: /* original e910, guest PC 0x0c054018 */
if(!s->budget--) { s->failed_pc=0x0c054018u; return 0; }
r[9]=0x00000010u;
if(!vf3_matrix_family(0x0c05401au,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c05401au; return 0; } return 1;
P_0c05404c: /* original d239, guest PC 0x0c05404c */
if(!s->budget--) { s->failed_pc=0x0c05404cu; return 0; }
r[2]=read(ram,0x0c054134u,4);
goto P_0c05404e;
P_0c05404e: /* original e507, guest PC 0x0c05404e */
if(!s->budget--) { s->failed_pc=0x0c05404eu; return 0; }
r[5]=0x00000007u;
goto P_0c054050;
P_0c054050: /* original 420b, guest PC 0x0c054050 */
if(!s->budget--) { s->failed_pc=0x0c054050u; return 0; }
target=r[2];
r[16]=code_base|0x0c054054u;
r[4]=r[11];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c054054u) { target=s->pc; goto dispatch; }
goto P_0c054054;
P_0c054052: /* original 64b3, guest PC 0x0c054052 */
if(!s->budget--) { s->failed_pc=0x0c054052u; return 0; }
r[4]=r[11];
goto P_0c054054;
P_0c054054: /* original 63e2, guest PC 0x0c054054 */
if(!s->budget--) { s->failed_pc=0x0c054054u; return 0; }
tmp=read(ram,r[14],4);
r[3]=tmp;
goto P_0c054056;
P_0c054056: /* original 73ff, guest PC 0x0c054056 */
if(!s->budget--) { s->failed_pc=0x0c054056u; return 0; }
r[3]+=0xffffffffu;
goto P_0c054058;
P_0c054058: /* original 2e32, guest PC 0x0c054058 */
if(!s->budget--) { s->failed_pc=0x0c054058u; return 0; }
write(ram,r[14],r[3],4);
goto P_0c05405a;
P_0c05405a: /* original 62b0, guest PC 0x0c05405a */
if(!s->budget--) { s->failed_pc=0x0c05405au; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[11],1);
r[2]=tmp;
goto P_0c05405c;
P_0c05405c: /* original 622c, guest PC 0x0c05405c */
if(!s->budget--) { s->failed_pc=0x0c05405cu; return 0; }
r[2]=r[2]&255u;
goto P_0c05405e;
P_0c05405e: /* original 2298, guest PC 0x0c05405e */
if(!s->budget--) { s->failed_pc=0x0c05405eu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[9])==0)!=0);
goto P_0c054060;
P_0c054060: /* original 8df4, guest PC 0x0c054060 */
if(!s->budget--) { s->failed_pc=0x0c054060u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05404c; }
goto P_0c054064;
P_0c054062: /* original 0009, guest PC 0x0c054062 */
if(!s->budget--) { s->failed_pc=0x0c054062u; return 0; }
goto P_0c054064;
P_0c054064: /* original 1fa2, guest PC 0x0c054064 */
if(!s->budget--) { s->failed_pc=0x0c054064u; return 0; }
write(ram,r[15]+8,r[10],4);
goto P_0c054066;
P_0c054066: /* original 65a3, guest PC 0x0c054066 */
if(!s->budget--) { s->failed_pc=0x0c054066u; return 0; }
r[5]=r[10];
goto P_0c054068;
P_0c054068: /* original 4c0b, guest PC 0x0c054068 */
if(!s->budget--) { s->failed_pc=0x0c054068u; return 0; }
target=r[12];
r[16]=code_base|0x0c05406cu;
r[4]=read(ram,r[15]+4,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c05406cu) { target=s->pc; goto dispatch; }
goto P_0c05406c;
P_0c05406a: /* original 54f1, guest PC 0x0c05406a */
if(!s->budget--) { s->failed_pc=0x0c05406au; return 0; }
r[4]=read(ram,r[15]+4,4);
goto P_0c05406c;
P_0c05406c: /* original 55f2, guest PC 0x0c05406c */
if(!s->budget--) { s->failed_pc=0x0c05406cu; return 0; }
r[5]=read(ram,r[15]+8,4);
goto P_0c05406e;
P_0c05406e: /* original 7504, guest PC 0x0c05406e */
if(!s->budget--) { s->failed_pc=0x0c05406eu; return 0; }
r[5]+=0x00000004u;
goto P_0c054070;
P_0c054070: /* original 4c0b, guest PC 0x0c054070 */
if(!s->budget--) { s->failed_pc=0x0c054070u; return 0; }
target=r[12];
r[16]=code_base|0x0c054074u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c054074u) { target=s->pc; goto dispatch; }
goto P_0c054074;
P_0c054072: /* original 64d3, guest PC 0x0c054072 */
if(!s->budget--) { s->failed_pc=0x0c054072u; return 0; }
r[4]=r[13];
goto P_0c054074;
P_0c054074: /* original 63f2, guest PC 0x0c054074 */
if(!s->budget--) { s->failed_pc=0x0c054074u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c054076;
P_0c054076: /* original 61f3, guest PC 0x0c054076 */
if(!s->budget--) { s->failed_pc=0x0c054076u; return 0; }
r[1]=r[15];
goto P_0c054078;
P_0c054078: /* original 9456, guest PC 0x0c054078 */
if(!s->budget--) { s->failed_pc=0x0c054078u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c054128u,2);
goto P_0c05407a;
P_0c05407a: /* original 7138, guest PC 0x0c05407a */
if(!s->budget--) { s->failed_pc=0x0c05407au; return 0; }
r[1]+=0x00000038u;
goto P_0c05407c;
P_0c05407c: /* original 6231, guest PC 0x0c05407c */
if(!s->budget--) { s->failed_pc=0x0c05407cu; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[3],2);
r[2]=tmp;
goto P_0c05407e;
P_0c05407e: /* original 2289, guest PC 0x0c05407e */
if(!s->budget--) { s->failed_pc=0x0c05407eu; return 0; }
r[2]&=r[8];
goto P_0c054080;
P_0c054080: /* original 2321, guest PC 0x0c054080 */
if(!s->budget--) { s->failed_pc=0x0c054080u; return 0; }
write(ram,r[3],r[2],2);
goto P_0c054082;
P_0c054082: /* original 63f2, guest PC 0x0c054082 */
if(!s->budget--) { s->failed_pc=0x0c054082u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c054084;
P_0c054084: /* original 6231, guest PC 0x0c054084 */
if(!s->budget--) { s->failed_pc=0x0c054084u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[3],2);
r[2]=tmp;
goto P_0c054086;
P_0c054086: /* original 224b, guest PC 0x0c054086 */
if(!s->budget--) { s->failed_pc=0x0c054086u; return 0; }
r[2]|=r[4];
goto P_0c054088;
P_0c054088: /* original 2321, guest PC 0x0c054088 */
if(!s->budget--) { s->failed_pc=0x0c054088u; return 0; }
write(ram,r[3],r[2],2);
goto P_0c05408a;
P_0c05408a: /* original 50fd, guest PC 0x0c05408a */
if(!s->budget--) { s->failed_pc=0x0c05408au; return 0; }
r[0]=read(ram,r[15]+52,4);
goto P_0c05408c;
P_0c05408c: /* original 6212, guest PC 0x0c05408c */
if(!s->budget--) { s->failed_pc=0x0c05408cu; return 0; }
tmp=read(ram,r[1],4);
r[2]=tmp;
goto P_0c05408e;
P_0c05408e: /* original 2022, guest PC 0x0c05408e */
if(!s->budget--) { s->failed_pc=0x0c05408eu; return 0; }
write(ram,r[0],r[2],4);
goto P_0c054090;
P_0c054090: /* original 5211, guest PC 0x0c054090 */
if(!s->budget--) { s->failed_pc=0x0c054090u; return 0; }
r[2]=read(ram,r[1]+4,4);
goto P_0c054092;
P_0c054092: /* original 1021, guest PC 0x0c054092 */
if(!s->budget--) { s->failed_pc=0x0c054092u; return 0; }
write(ram,r[0]+4,r[2],4);
goto P_0c054094;
P_0c054094: /* original 7f14, guest PC 0x0c054094 */
if(!s->budget--) { s->failed_pc=0x0c054094u; return 0; }
r[15]+=0x00000014u;
goto P_0c054096;
P_0c054096: /* original 4f26, guest PC 0x0c054096 */
if(!s->budget--) { s->failed_pc=0x0c054096u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c054098;
P_0c054098: /* original 68f6, guest PC 0x0c054098 */
if(!s->budget--) { s->failed_pc=0x0c054098u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c05409a;
P_0c05409a: /* original 69f6, guest PC 0x0c05409a */
if(!s->budget--) { s->failed_pc=0x0c05409au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c05409c;
P_0c05409c: /* original 6af6, guest PC 0x0c05409c */
if(!s->budget--) { s->failed_pc=0x0c05409cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c05409e;
P_0c05409e: /* original 6bf6, guest PC 0x0c05409e */
if(!s->budget--) { s->failed_pc=0x0c05409eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0540a0;
P_0c0540a0: /* original 6cf6, guest PC 0x0c0540a0 */
if(!s->budget--) { s->failed_pc=0x0c0540a0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0540a2;
P_0c0540a2: /* original 6df6, guest PC 0x0c0540a2 */
if(!s->budget--) { s->failed_pc=0x0c0540a2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0540a4;
P_0c0540a4: /* original 000b, guest PC 0x0c0540a4 */
if(!s->budget--) { s->failed_pc=0x0c0540a4u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0540a6: /* original 6ef6, guest PC 0x0c0540a6 */
if(!s->budget--) { s->failed_pc=0x0c0540a6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0540a8;
P_0c0540a8: /* original 2fe6, guest PC 0x0c0540a8 */
if(!s->budget--) { s->failed_pc=0x0c0540a8u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0540aa;
P_0c0540aa: /* original 6e43, guest PC 0x0c0540aa */
if(!s->budget--) { s->failed_pc=0x0c0540aau; return 0; }
r[14]=r[4];
goto P_0c0540ac;
P_0c0540ac: /* original d222, guest PC 0x0c0540ac */
if(!s->budget--) { s->failed_pc=0x0c0540acu; return 0; }
r[2]=read(ram,0x0c054138u,4);
goto P_0c0540ae;
P_0c0540ae: /* original 2fd6, guest PC 0x0c0540ae */
if(!s->budget--) { s->failed_pc=0x0c0540aeu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0540b0;
P_0c0540b0: /* original 4f22, guest PC 0x0c0540b0 */
if(!s->budget--) { s->failed_pc=0x0c0540b0u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0540b2;
P_0c0540b2: /* original edff, guest PC 0x0c0540b2 */
if(!s->budget--) { s->failed_pc=0x0c0540b2u; return 0; }
r[13]=0xffffffffu;
goto P_0c0540b4;
P_0c0540b4: /* original 53f5, guest PC 0x0c0540b4 */
if(!s->budget--) { s->failed_pc=0x0c0540b4u; return 0; }
r[3]=read(ram,r[15]+20,4);
goto P_0c0540b6;
P_0c0540b6: /* original 2f36, guest PC 0x0c0540b6 */
if(!s->budget--) { s->failed_pc=0x0c0540b6u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0540b8;
P_0c0540b8: /* original 53f5, guest PC 0x0c0540b8 */
if(!s->budget--) { s->failed_pc=0x0c0540b8u; return 0; }
r[3]=read(ram,r[15]+20,4);
goto P_0c0540ba;
P_0c0540ba: /* original 420b, guest PC 0x0c0540ba */
if(!s->budget--) { s->failed_pc=0x0c0540bau; return 0; }
target=r[2];
r[16]=code_base|0x0c0540beu;
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0540beu) { target=s->pc; goto dispatch; }
goto P_0c0540be;
P_0c0540bc: /* original 2f36, guest PC 0x0c0540bc */
if(!s->budget--) { s->failed_pc=0x0c0540bcu; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0540be;
P_0c0540be: /* original 7f08, guest PC 0x0c0540be */
if(!s->budget--) { s->failed_pc=0x0c0540beu; return 0; }
r[15]+=0x00000008u;
goto P_0c0540c0;
P_0c0540c0: /* original 2008, guest PC 0x0c0540c0 */
if(!s->budget--) { s->failed_pc=0x0c0540c0u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c0540c2;
P_0c0540c2: /* original 8d1d, guest PC 0x0c0540c2 */
if(!s->budget--) { s->failed_pc=0x0c0540c2u; return 0; }
cond=r[17]&1u;
r[4]=r[0];
if(cond) { goto P_0c054100; }
goto P_0c0540c6;
P_0c0540c4: /* original 6403, guest PC 0x0c0540c4 */
if(!s->budget--) { s->failed_pc=0x0c0540c4u; return 0; }
r[4]=r[0];
goto P_0c0540c6;
P_0c0540c6: /* original 6043, guest PC 0x0c0540c6 */
if(!s->budget--) { s->failed_pc=0x0c0540c6u; return 0; }
r[0]=r[4];
goto P_0c0540c8;
P_0c0540c8: /* original 0009, guest PC 0x0c0540c8 */
if(!s->budget--) { s->failed_pc=0x0c0540c8u; return 0; }
goto P_0c0540ca;
P_0c0540ca: /* original 8801, guest PC 0x0c0540ca */
if(!s->budget--) { s->failed_pc=0x0c0540cau; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c0540cc;
P_0c0540cc: /* original 8f03, guest PC 0x0c0540cc */
if(!s->budget--) { s->failed_pc=0x0c0540ccu; return 0; }
cond=r[17]&1u;
r[0]=r[4];
if(!cond) { goto P_0c0540d6; }
goto P_0c0540d0;
P_0c0540ce: /* original 6043, guest PC 0x0c0540ce */
if(!s->budget--) { s->failed_pc=0x0c0540ceu; return 0; }
r[0]=r[4];
goto P_0c0540d0;
P_0c0540d0: /* original 932b, guest PC 0x0c0540d0 */
if(!s->budget--) { s->failed_pc=0x0c0540d0u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c05412au,2);
goto P_0c0540d2;
P_0c0540d2: /* original d21a, guest PC 0x0c0540d2 */
if(!s->budget--) { s->failed_pc=0x0c0540d2u; return 0; }
r[2]=read(ram,0x0c05413cu,4);
goto P_0c0540d4;
P_0c0540d4: /* original 2232, guest PC 0x0c0540d4 */
if(!s->budget--) { s->failed_pc=0x0c0540d4u; return 0; }
write(ram,r[2],r[3],4);
goto P_0c0540d6;
P_0c0540d6: /* original 8802, guest PC 0x0c0540d6 */
if(!s->budget--) { s->failed_pc=0x0c0540d6u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c0540d8;
P_0c0540d8: /* original 8f03, guest PC 0x0c0540d8 */
if(!s->budget--) { s->failed_pc=0x0c0540d8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0540e2; }
goto P_0c0540dc;
P_0c0540da: /* original 0009, guest PC 0x0c0540da */
if(!s->budget--) { s->failed_pc=0x0c0540dau; return 0; }
goto P_0c0540dc;
P_0c0540dc: /* original 9226, guest PC 0x0c0540dc */
if(!s->budget--) { s->failed_pc=0x0c0540dcu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c05412cu,2);
goto P_0c0540de;
P_0c0540de: /* original d317, guest PC 0x0c0540de */
if(!s->budget--) { s->failed_pc=0x0c0540deu; return 0; }
r[3]=read(ram,0x0c05413cu,4);
goto P_0c0540e0;
P_0c0540e0: /* original 2322, guest PC 0x0c0540e0 */
if(!s->budget--) { s->failed_pc=0x0c0540e0u; return 0; }
write(ram,r[3],r[2],4);
goto P_0c0540e2;
P_0c0540e2: /* original 61f3, guest PC 0x0c0540e2 */
if(!s->budget--) { s->failed_pc=0x0c0540e2u; return 0; }
r[1]=r[15];
goto P_0c0540e4;
P_0c0540e4: /* original 7110, guest PC 0x0c0540e4 */
if(!s->budget--) { s->failed_pc=0x0c0540e4u; return 0; }
r[1]+=0x00000010u;
goto P_0c0540e6;
P_0c0540e6: /* original 63f3, guest PC 0x0c0540e6 */
if(!s->budget--) { s->failed_pc=0x0c0540e6u; return 0; }
r[3]=r[15];
goto P_0c0540e8;
P_0c0540e8: /* original 21d2, guest PC 0x0c0540e8 */
if(!s->budget--) { s->failed_pc=0x0c0540e8u; return 0; }
write(ram,r[1],r[13],4);
goto P_0c0540ea;
P_0c0540ea: /* original 7310, guest PC 0x0c0540ea */
if(!s->budget--) { s->failed_pc=0x0c0540eau; return 0; }
r[3]+=0x00000010u;
goto P_0c0540ec;
P_0c0540ec: /* original 13d1, guest PC 0x0c0540ec */
if(!s->budget--) { s->failed_pc=0x0c0540ecu; return 0; }
write(ram,r[3]+4,r[13],4);
goto P_0c0540ee;
P_0c0540ee: /* original 63f3, guest PC 0x0c0540ee */
if(!s->budget--) { s->failed_pc=0x0c0540eeu; return 0; }
r[3]=r[15];
goto P_0c0540f0;
P_0c0540f0: /* original 51f3, guest PC 0x0c0540f0 */
if(!s->budget--) { s->failed_pc=0x0c0540f0u; return 0; }
r[1]=read(ram,r[15]+12,4);
goto P_0c0540f2;
P_0c0540f2: /* original 7310, guest PC 0x0c0540f2 */
if(!s->budget--) { s->failed_pc=0x0c0540f2u; return 0; }
r[3]+=0x00000010u;
goto P_0c0540f4;
P_0c0540f4: /* original 6032, guest PC 0x0c0540f4 */
if(!s->budget--) { s->failed_pc=0x0c0540f4u; return 0; }
tmp=read(ram,r[3],4);
r[0]=tmp;
goto P_0c0540f6;
P_0c0540f6: /* original 2102, guest PC 0x0c0540f6 */
if(!s->budget--) { s->failed_pc=0x0c0540f6u; return 0; }
write(ram,r[1],r[0],4);
goto P_0c0540f8;
P_0c0540f8: /* original 5031, guest PC 0x0c0540f8 */
if(!s->budget--) { s->failed_pc=0x0c0540f8u; return 0; }
r[0]=read(ram,r[3]+4,4);
goto P_0c0540fa;
P_0c0540fa: /* original 1101, guest PC 0x0c0540fa */
if(!s->budget--) { s->failed_pc=0x0c0540fau; return 0; }
write(ram,r[1]+4,r[0],4);
goto P_0c0540fc;
P_0c0540fc: /* original a06a, guest PC 0x0c0540fc */
if(!s->budget--) { s->failed_pc=0x0c0540fcu; return 0; }
goto P_0c0541d4;
P_0c0540fe: /* original 0009, guest PC 0x0c0540fe */
if(!s->budget--) { s->failed_pc=0x0c0540feu; return 0; }
goto P_0c054100;
P_0c054100: /* original 9315, guest PC 0x0c054100 */
if(!s->budget--) { s->failed_pc=0x0c054100u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c05412eu,2);
goto P_0c054102;
P_0c054102: /* original 64f3, guest PC 0x0c054102 */
if(!s->budget--) { s->failed_pc=0x0c054102u; return 0; }
r[4]=r[15];
goto P_0c054104;
P_0c054104: /* original 9214, guest PC 0x0c054104 */
if(!s->budget--) { s->failed_pc=0x0c054104u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c054130u,2);
goto P_0c054106;
P_0c054106: /* original 7410, guest PC 0x0c054106 */
if(!s->budget--) { s->failed_pc=0x0c054106u; return 0; }
r[4]+=0x00000010u;
goto P_0c054108;
P_0c054108: /* original 8543, guest PC 0x0c054108 */
if(!s->budget--) { s->failed_pc=0x0c054108u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+6,2);
goto P_0c05410a;
P_0c05410a: /* original 640d, guest PC 0x0c05410a */
if(!s->budget--) { s->failed_pc=0x0c05410au; return 0; }
r[4]=r[0]&65535u;
goto P_0c05410c;
P_0c05410c: /* original 4409, guest PC 0x0c05410c */
if(!s->budget--) { s->failed_pc=0x0c05410cu; return 0; }
r[4]>>=2;
goto P_0c05410e;
P_0c05410e: /* original 4409, guest PC 0x0c05410e */
if(!s->budget--) { s->failed_pc=0x0c05410eu; return 0; }
r[4]>>=2;
goto P_0c054110;
P_0c054110: /* original 2439, guest PC 0x0c054110 */
if(!s->budget--) { s->failed_pc=0x0c054110u; return 0; }
r[4]&=r[3];
goto P_0c054112;
P_0c054112: /* original 342c, guest PC 0x0c054112 */
if(!s->budget--) { s->failed_pc=0x0c054112u; return 0; }
r[4]+=r[2];
goto P_0c054114;
P_0c054114: /* original 4411, guest PC 0x0c054114 */
if(!s->budget--) { s->failed_pc=0x0c054114u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=0)!=0);
goto P_0c054116;
P_0c054116: /* original 8d13, guest PC 0x0c054116 */
if(!s->budget--) { s->failed_pc=0x0c054116u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c054140; }
goto P_0c05411a;
P_0c054118: /* original 0009, guest PC 0x0c054118 */
if(!s->budget--) { s->failed_pc=0x0c054118u; return 0; }
goto P_0c05411a;
P_0c05411a: /* original 60e3, guest PC 0x0c05411a */
if(!s->budget--) { s->failed_pc=0x0c05411au; return 0; }
r[0]=r[14];
goto P_0c05411c;
P_0c05411c: /* original 0009, guest PC 0x0c05411c */
if(!s->budget--) { s->failed_pc=0x0c05411cu; return 0; }
goto P_0c05411e;
P_0c05411e: /* original e100, guest PC 0x0c05411e */
if(!s->budget--) { s->failed_pc=0x0c05411eu; return 0; }
r[1]=0x00000000u;
goto P_0c054120;
P_0c054120: /* original 2012, guest PC 0x0c054120 */
if(!s->budget--) { s->failed_pc=0x0c054120u; return 0; }
write(ram,r[0],r[1],4);
goto P_0c054122;
P_0c054122: /* original 1011, guest PC 0x0c054122 */
if(!s->budget--) { s->failed_pc=0x0c054122u; return 0; }
write(ram,r[0]+4,r[1],4);
goto P_0c054124;
P_0c054124: /* original a030, guest PC 0x0c054124 */
if(!s->budget--) { s->failed_pc=0x0c054124u; return 0; }
goto P_0c054188;
P_0c054126: /* original 0009, guest PC 0x0c054126 */
if(!s->budget--) { s->failed_pc=0x0c054126u; return 0; }
if(!vf3_matrix_family(0x0c054128u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c054128u; return 0; } return 1;
P_0c054140: /* original 61f3, guest PC 0x0c054140 */
if(!s->budget--) { s->failed_pc=0x0c054140u; return 0; }
r[1]=r[15];
goto P_0c054142;
P_0c054142: /* original 7110, guest PC 0x0c054142 */
if(!s->budget--) { s->failed_pc=0x0c054142u; return 0; }
r[1]+=0x00000010u;
goto P_0c054144;
P_0c054144: /* original 60e3, guest PC 0x0c054144 */
if(!s->budget--) { s->failed_pc=0x0c054144u; return 0; }
r[0]=r[14];
goto P_0c054146;
P_0c054146: /* original 0009, guest PC 0x0c054146 */
if(!s->budget--) { s->failed_pc=0x0c054146u; return 0; }
goto P_0c054148;
P_0c054148: /* original 6312, guest PC 0x0c054148 */
if(!s->budget--) { s->failed_pc=0x0c054148u; return 0; }
tmp=read(ram,r[1],4);
r[3]=tmp;
goto P_0c05414a;
P_0c05414a: /* original e634, guest PC 0x0c05414a */
if(!s->budget--) { s->failed_pc=0x0c05414au; return 0; }
r[6]=0x00000034u;
goto P_0c05414c;
P_0c05414c: /* original 2032, guest PC 0x0c05414c */
if(!s->budget--) { s->failed_pc=0x0c05414cu; return 0; }
write(ram,r[0],r[3],4);
goto P_0c05414e;
P_0c05414e: /* original 3463, guest PC 0x0c05414e */
if(!s->budget--) { s->failed_pc=0x0c05414eu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=(int32_t)r[6])!=0);
goto P_0c054150;
P_0c054150: /* original 5311, guest PC 0x0c054150 */
if(!s->budget--) { s->failed_pc=0x0c054150u; return 0; }
r[3]=read(ram,r[1]+4,4);
goto P_0c054152;
P_0c054152: /* original 8d19, guest PC 0x0c054152 */
if(!s->budget--) { s->failed_pc=0x0c054152u; return 0; }
cond=r[17]&1u;
write(ram,r[0]+4,r[3],4);
if(cond) { goto P_0c054188; }
goto P_0c054156;
P_0c054154: /* original 1031, guest PC 0x0c054154 */
if(!s->budget--) { s->failed_pc=0x0c054154u; return 0; }
write(ram,r[0]+4,r[3],4);
goto P_0c054156;
P_0c054156: /* original 6563, guest PC 0x0c054156 */
if(!s->budget--) { s->failed_pc=0x0c054156u; return 0; }
r[5]=r[6];
goto P_0c054158;
P_0c054158: /* original d320, guest PC 0x0c054158 */
if(!s->budget--) { s->failed_pc=0x0c054158u; return 0; }
r[3]=read(ram,0x0c0541dcu,4);
goto P_0c05415a;
P_0c05415a: /* original 3548, guest PC 0x0c05415a */
if(!s->budget--) { s->failed_pc=0x0c05415au; return 0; }
r[5]-=r[4];
goto P_0c05415c;
P_0c05415c: /* original 6153, guest PC 0x0c05415c */
if(!s->budget--) { s->failed_pc=0x0c05415cu; return 0; }
r[1]=r[5];
goto P_0c05415e;
P_0c05415e: /* original 430b, guest PC 0x0c05415e */
if(!s->budget--) { s->failed_pc=0x0c05415eu; return 0; }
target=r[3];
r[16]=code_base|0x0c054162u;
r[0]=0x00000020u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c054162u) { target=s->pc; goto dispatch; }
goto P_0c054162;
P_0c054160: /* original e020, guest PC 0x0c054160 */
if(!s->budget--) { s->failed_pc=0x0c054160u; return 0; }
r[0]=0x00000020u;
goto P_0c054162;
P_0c054162: /* original 4015, guest PC 0x0c054162 */
if(!s->budget--) { s->failed_pc=0x0c054162u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[0]>0)!=0);
goto P_0c054164;
P_0c054164: /* original 8f04, guest PC 0x0c054164 */
if(!s->budget--) { s->failed_pc=0x0c054164u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c054170; }
goto P_0c054168;
P_0c054166: /* original 0009, guest PC 0x0c054166 */
if(!s->budget--) { s->failed_pc=0x0c054166u; return 0; }
goto P_0c054168;
P_0c054168: /* original 63f3, guest PC 0x0c054168 */
if(!s->budget--) { s->failed_pc=0x0c054168u; return 0; }
r[3]=r[15];
goto P_0c05416a;
P_0c05416a: /* original 7310, guest PC 0x0c05416a */
if(!s->budget--) { s->failed_pc=0x0c05416au; return 0; }
r[3]+=0x00000010u;
goto P_0c05416c;
P_0c05416c: /* original e100, guest PC 0x0c05416c */
if(!s->budget--) { s->failed_pc=0x0c05416cu; return 0; }
r[1]=0x00000000u;
goto P_0c05416e;
P_0c05416e: /* original 2312, guest PC 0x0c05416e */
if(!s->budget--) { s->failed_pc=0x0c05416eu; return 0; }
write(ram,r[3],r[1],4);
goto P_0c054170;
P_0c054170: /* original d31b, guest PC 0x0c054170 */
if(!s->budget--) { s->failed_pc=0x0c054170u; return 0; }
r[3]=read(ram,0x0c0541e0u,4);
goto P_0c054172;
P_0c054172: /* original 6153, guest PC 0x0c054172 */
if(!s->budget--) { s->failed_pc=0x0c054172u; return 0; }
r[1]=r[5];
goto P_0c054174;
P_0c054174: /* original 430b, guest PC 0x0c054174 */
if(!s->budget--) { s->failed_pc=0x0c054174u; return 0; }
target=r[3];
r[16]=code_base|0x0c054178u;
r[0]=0x00000020u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c054178u) { target=s->pc; goto dispatch; }
goto P_0c054178;
P_0c054176: /* original e020, guest PC 0x0c054176 */
if(!s->budget--) { s->failed_pc=0x0c054176u; return 0; }
r[0]=0x00000020u;
goto P_0c054178;
P_0c054178: /* original 64d3, guest PC 0x0c054178 */
if(!s->budget--) { s->failed_pc=0x0c054178u; return 0; }
r[4]=r[13];
goto P_0c05417a;
P_0c05417a: /* original 0009, guest PC 0x0c05417a */
if(!s->budget--) { s->failed_pc=0x0c05417au; return 0; }
goto P_0c05417c;
P_0c05417c: /* original 440d, guest PC 0x0c05417c */
if(!s->budget--) { s->failed_pc=0x0c05417cu; return 0; }
r[4]=(r[0]&0x80000000u)?((r[0]&31u)?r[4]>>((-r[0])&31u):0):r[4]<<(r[0]&31u);
goto P_0c05417e;
P_0c05417e: /* original 63f3, guest PC 0x0c05417e */
if(!s->budget--) { s->failed_pc=0x0c05417eu; return 0; }
r[3]=r[15];
goto P_0c054180;
P_0c054180: /* original 7310, guest PC 0x0c054180 */
if(!s->budget--) { s->failed_pc=0x0c054180u; return 0; }
r[3]+=0x00000010u;
goto P_0c054182;
P_0c054182: /* original 5231, guest PC 0x0c054182 */
if(!s->budget--) { s->failed_pc=0x0c054182u; return 0; }
r[2]=read(ram,r[3]+4,4);
goto P_0c054184;
P_0c054184: /* original 2249, guest PC 0x0c054184 */
if(!s->budget--) { s->failed_pc=0x0c054184u; return 0; }
r[2]&=r[4];
goto P_0c054186;
P_0c054186: /* original 1321, guest PC 0x0c054186 */
if(!s->budget--) { s->failed_pc=0x0c054186u; return 0; }
write(ram,r[3]+4,r[2],4);
goto P_0c054188;
P_0c054188: /* original 53f5, guest PC 0x0c054188 */
if(!s->budget--) { s->failed_pc=0x0c054188u; return 0; }
r[3]=read(ram,r[15]+20,4);
goto P_0c05418a;
P_0c05418a: /* original 2f36, guest PC 0x0c05418a */
if(!s->budget--) { s->failed_pc=0x0c05418au; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05418c;
P_0c05418c: /* original 53f5, guest PC 0x0c05418c */
if(!s->budget--) { s->failed_pc=0x0c05418cu; return 0; }
r[3]=read(ram,r[15]+20,4);
goto P_0c05418e;
P_0c05418e: /* original 2f36, guest PC 0x0c05418e */
if(!s->budget--) { s->failed_pc=0x0c05418eu; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c054190;
P_0c054190: /* original 53e1, guest PC 0x0c054190 */
if(!s->budget--) { s->failed_pc=0x0c054190u; return 0; }
r[3]=read(ram,r[14]+4,4);
goto P_0c054192;
P_0c054192: /* original 2f36, guest PC 0x0c054192 */
if(!s->budget--) { s->failed_pc=0x0c054192u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c054194;
P_0c054194: /* original 63e2, guest PC 0x0c054194 */
if(!s->budget--) { s->failed_pc=0x0c054194u; return 0; }
tmp=read(ram,r[14],4);
r[3]=tmp;
goto P_0c054196;
P_0c054196: /* original 2f36, guest PC 0x0c054196 */
if(!s->budget--) { s->failed_pc=0x0c054196u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c054198;
P_0c054198: /* original 62f3, guest PC 0x0c054198 */
if(!s->budget--) { s->failed_pc=0x0c054198u; return 0; }
r[2]=r[15];
goto P_0c05419a;
P_0c05419a: /* original 7220, guest PC 0x0c05419a */
if(!s->budget--) { s->failed_pc=0x0c05419au; return 0; }
r[2]+=0x00000020u;
goto P_0c05419c;
P_0c05419c: /* original 2f26, guest PC 0x0c05419c */
if(!s->budget--) { s->failed_pc=0x0c05419cu; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05419e;
P_0c05419e: /* original d211, guest PC 0x0c05419e */
if(!s->budget--) { s->failed_pc=0x0c05419eu; return 0; }
r[2]=read(ram,0x0c0541e4u,4);
goto P_0c0541a0;
P_0c0541a0: /* original 420b, guest PC 0x0c0541a0 */
if(!s->budget--) { s->failed_pc=0x0c0541a0u; return 0; }
target=r[2];
r[16]=code_base|0x0c0541a4u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0541a4u) { target=s->pc; goto dispatch; }
goto P_0c0541a4;
P_0c0541a2: /* original 0009, guest PC 0x0c0541a2 */
if(!s->budget--) { s->failed_pc=0x0c0541a2u; return 0; }
goto P_0c0541a4;
P_0c0541a4: /* original 53e1, guest PC 0x0c0541a4 */
if(!s->budget--) { s->failed_pc=0x0c0541a4u; return 0; }
r[3]=read(ram,r[14]+4,4);
goto P_0c0541a6;
P_0c0541a6: /* original e200, guest PC 0x0c0541a6 */
if(!s->budget--) { s->failed_pc=0x0c0541a6u; return 0; }
r[2]=0x00000000u;
goto P_0c0541a8;
P_0c0541a8: /* original 2f36, guest PC 0x0c0541a8 */
if(!s->budget--) { s->failed_pc=0x0c0541a8u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0541aa;
P_0c0541aa: /* original 63e2, guest PC 0x0c0541aa */
if(!s->budget--) { s->failed_pc=0x0c0541aau; return 0; }
tmp=read(ram,r[14],4);
r[3]=tmp;
goto P_0c0541ac;
P_0c0541ac: /* original 2f36, guest PC 0x0c0541ac */
if(!s->budget--) { s->failed_pc=0x0c0541acu; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0541ae;
P_0c0541ae: /* original 2f26, guest PC 0x0c0541ae */
if(!s->budget--) { s->failed_pc=0x0c0541aeu; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0541b0;
P_0c0541b0: /* original d30d, guest PC 0x0c0541b0 */
if(!s->budget--) { s->failed_pc=0x0c0541b0u; return 0; }
r[3]=read(ram,0x0c0541e8u,4);
goto P_0c0541b2;
P_0c0541b2: /* original 430b, guest PC 0x0c0541b2 */
if(!s->budget--) { s->failed_pc=0x0c0541b2u; return 0; }
target=r[3];
r[16]=code_base|0x0c0541b6u;
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0541b6u) { target=s->pc; goto dispatch; }
goto P_0c0541b6;
P_0c0541b4: /* original 2f26, guest PC 0x0c0541b4 */
if(!s->budget--) { s->failed_pc=0x0c0541b4u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0541b6;
P_0c0541b6: /* original 8800, guest PC 0x0c0541b6 */
if(!s->budget--) { s->failed_pc=0x0c0541b6u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000000u)!=0);
goto P_0c0541b8;
P_0c0541b8: /* original 8d05, guest PC 0x0c0541b8 */
if(!s->budget--) { s->failed_pc=0x0c0541b8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0541c6; }
goto P_0c0541bc;
P_0c0541ba: /* original 0009, guest PC 0x0c0541ba */
if(!s->budget--) { s->failed_pc=0x0c0541bau; return 0; }
goto P_0c0541bc;
P_0c0541bc: /* original 63f3, guest PC 0x0c0541bc */
if(!s->budget--) { s->failed_pc=0x0c0541bcu; return 0; }
r[3]=r[15];
goto P_0c0541be;
P_0c0541be: /* original 7310, guest PC 0x0c0541be */
if(!s->budget--) { s->failed_pc=0x0c0541beu; return 0; }
r[3]+=0x00000010u;
goto P_0c0541c0;
P_0c0541c0: /* original 8437, guest PC 0x0c0541c0 */
if(!s->budget--) { s->failed_pc=0x0c0541c0u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[3]+7,1);
goto P_0c0541c2;
P_0c0541c2: /* original cb80, guest PC 0x0c0541c2 */
if(!s->budget--) { s->failed_pc=0x0c0541c2u; return 0; }
r[0]|=128u;
goto P_0c0541c4;
P_0c0541c4: /* original 8037, guest PC 0x0c0541c4 */
if(!s->budget--) { s->failed_pc=0x0c0541c4u; return 0; }
write(ram,r[3]+7,r[0],1);
goto P_0c0541c6;
P_0c0541c6: /* original 62f3, guest PC 0x0c0541c6 */
if(!s->budget--) { s->failed_pc=0x0c0541c6u; return 0; }
r[2]=r[15];
goto P_0c0541c8;
P_0c0541c8: /* original 51f3, guest PC 0x0c0541c8 */
if(!s->budget--) { s->failed_pc=0x0c0541c8u; return 0; }
r[1]=read(ram,r[15]+12,4);
goto P_0c0541ca;
P_0c0541ca: /* original 7210, guest PC 0x0c0541ca */
if(!s->budget--) { s->failed_pc=0x0c0541cau; return 0; }
r[2]+=0x00000010u;
goto P_0c0541cc;
P_0c0541cc: /* original 6022, guest PC 0x0c0541cc */
if(!s->budget--) { s->failed_pc=0x0c0541ccu; return 0; }
tmp=read(ram,r[2],4);
r[0]=tmp;
goto P_0c0541ce;
P_0c0541ce: /* original 2102, guest PC 0x0c0541ce */
if(!s->budget--) { s->failed_pc=0x0c0541ceu; return 0; }
write(ram,r[1],r[0],4);
goto P_0c0541d0;
P_0c0541d0: /* original 5021, guest PC 0x0c0541d0 */
if(!s->budget--) { s->failed_pc=0x0c0541d0u; return 0; }
r[0]=read(ram,r[2]+4,4);
goto P_0c0541d2;
P_0c0541d2: /* original 1101, guest PC 0x0c0541d2 */
if(!s->budget--) { s->failed_pc=0x0c0541d2u; return 0; }
write(ram,r[1]+4,r[0],4);
goto P_0c0541d4;
P_0c0541d4: /* original 4f26, guest PC 0x0c0541d4 */
if(!s->budget--) { s->failed_pc=0x0c0541d4u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0541d6;
P_0c0541d6: /* original 6df6, guest PC 0x0c0541d6 */
if(!s->budget--) { s->failed_pc=0x0c0541d6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0541d8;
P_0c0541d8: /* original 000b, guest PC 0x0c0541d8 */
if(!s->budget--) { s->failed_pc=0x0c0541d8u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0541da: /* original 6ef6, guest PC 0x0c0541da */
if(!s->budget--) { s->failed_pc=0x0c0541dau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0541dcu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0541dcu; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
