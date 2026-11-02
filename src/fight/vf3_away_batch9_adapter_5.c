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
int vf3_away_batch9_adapter_5(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c066f88u: goto P_0c066f88;
case 0x0c066f8au: goto P_0c066f8a;
case 0x0c066f8cu: goto P_0c066f8c;
case 0x0c066f8eu: goto P_0c066f8e;
case 0x0c066f90u: goto P_0c066f90;
case 0x0c066f92u: goto P_0c066f92;
case 0x0c066f94u: goto P_0c066f94;
case 0x0c066f96u: goto P_0c066f96;
case 0x0c066f98u: goto P_0c066f98;
case 0x0c066f9au: goto P_0c066f9a;
case 0x0c066f9cu: goto P_0c066f9c;
case 0x0c066f9eu: goto P_0c066f9e;
case 0x0c066fa0u: goto P_0c066fa0;
case 0x0c066fa2u: goto P_0c066fa2;
case 0x0c066fa4u: goto P_0c066fa4;
case 0x0c066fa6u: goto P_0c066fa6;
case 0x0c066fa8u: goto P_0c066fa8;
case 0x0c066faau: goto P_0c066faa;
case 0x0c066facu: goto P_0c066fac;
case 0x0c066faeu: goto P_0c066fae;
case 0x0c066fb0u: goto P_0c066fb0;
case 0x0c066fb2u: goto P_0c066fb2;
case 0x0c066fb4u: goto P_0c066fb4;
case 0x0c066fd8u: goto P_0c066fd8;
case 0x0c066fdau: goto P_0c066fda;
case 0x0c066fdcu: goto P_0c066fdc;
case 0x0c066fdeu: goto P_0c066fde;
case 0x0c066fe0u: goto P_0c066fe0;
case 0x0c066fe2u: goto P_0c066fe2;
case 0x0c066fe4u: goto P_0c066fe4;
case 0x0c066fe6u: goto P_0c066fe6;
case 0x0c066fe8u: goto P_0c066fe8;
case 0x0c066feau: goto P_0c066fea;
case 0x0c066fecu: goto P_0c066fec;
case 0x0c066feeu: goto P_0c066fee;
case 0x0c066ff0u: goto P_0c066ff0;
case 0x0c066ff2u: goto P_0c066ff2;
case 0x0c066ff4u: goto P_0c066ff4;
case 0x0c066ff6u: goto P_0c066ff6;
case 0x0c066ff8u: goto P_0c066ff8;
case 0x0c066ffau: goto P_0c066ffa;
case 0x0c066ffcu: goto P_0c066ffc;
case 0x0c066ffeu: goto P_0c066ffe;
case 0x0c067000u: goto P_0c067000;
case 0x0c067002u: goto P_0c067002;
case 0x0c067004u: goto P_0c067004;
case 0x0c067006u: goto P_0c067006;
case 0x0c067008u: goto P_0c067008;
case 0x0c06700au: goto P_0c06700a;
case 0x0c06700cu: goto P_0c06700c;
case 0x0c06700eu: goto P_0c06700e;
case 0x0c067010u: goto P_0c067010;
case 0x0c067012u: goto P_0c067012;
case 0x0c067014u: goto P_0c067014;
case 0x0c067016u: goto P_0c067016;
case 0x0c067018u: goto P_0c067018;
case 0x0c06701au: goto P_0c06701a;
case 0x0c06701cu: goto P_0c06701c;
case 0x0c06701eu: goto P_0c06701e;
case 0x0c067020u: goto P_0c067020;
case 0x0c067022u: goto P_0c067022;
case 0x0c067024u: goto P_0c067024;
case 0x0c067026u: goto P_0c067026;
case 0x0c067028u: goto P_0c067028;
case 0x0c06702au: goto P_0c06702a;
case 0x0c06702cu: goto P_0c06702c;
case 0x0c06702eu: goto P_0c06702e;
case 0x0c067030u: goto P_0c067030;
case 0x0c067032u: goto P_0c067032;
case 0x0c067034u: goto P_0c067034;
case 0x0c067036u: goto P_0c067036;
case 0x0c067038u: goto P_0c067038;
case 0x0c06703au: goto P_0c06703a;
case 0x0c06703cu: goto P_0c06703c;
case 0x0c06703eu: goto P_0c06703e;
case 0x0c067040u: goto P_0c067040;
case 0x0c067042u: goto P_0c067042;
case 0x0c067044u: goto P_0c067044;
case 0x0c067046u: goto P_0c067046;
case 0x0c067048u: goto P_0c067048;
case 0x0c06704au: goto P_0c06704a;
case 0x0c06704cu: goto P_0c06704c;
case 0x0c06704eu: goto P_0c06704e;
case 0x0c067050u: goto P_0c067050;
case 0x0c067052u: goto P_0c067052;
case 0x0c067054u: goto P_0c067054;
case 0x0c067056u: goto P_0c067056;
case 0x0c067058u: goto P_0c067058;
case 0x0c06705au: goto P_0c06705a;
case 0x0c06705cu: goto P_0c06705c;
case 0x0c06705eu: goto P_0c06705e;
case 0x0c067060u: goto P_0c067060;
case 0x0c067062u: goto P_0c067062;
case 0x0c067064u: goto P_0c067064;
case 0x0c067066u: goto P_0c067066;
case 0x0c067068u: goto P_0c067068;
case 0x0c06706au: goto P_0c06706a;
case 0x0c06706cu: goto P_0c06706c;
case 0x0c06706eu: goto P_0c06706e;
case 0x0c067070u: goto P_0c067070;
case 0x0c067072u: goto P_0c067072;
case 0x0c067074u: goto P_0c067074;
case 0x0c067076u: goto P_0c067076;
case 0x0c067078u: goto P_0c067078;
case 0x0c06707au: goto P_0c06707a;
case 0x0c06707cu: goto P_0c06707c;
case 0x0c06707eu: goto P_0c06707e;
case 0x0c067080u: goto P_0c067080;
case 0x0c067082u: goto P_0c067082;
case 0x0c067084u: goto P_0c067084;
case 0x0c067086u: goto P_0c067086;
case 0x0c067088u: goto P_0c067088;
case 0x0c06708au: goto P_0c06708a;
case 0x0c06708cu: goto P_0c06708c;
case 0x0c06708eu: goto P_0c06708e;
case 0x0c067090u: goto P_0c067090;
case 0x0c067092u: goto P_0c067092;
case 0x0c067094u: goto P_0c067094;
case 0x0c067096u: goto P_0c067096;
case 0x0c067098u: goto P_0c067098;
case 0x0c06709au: goto P_0c06709a;
case 0x0c06709cu: goto P_0c06709c;
case 0x0c06709eu: goto P_0c06709e;
case 0x0c0670a0u: goto P_0c0670a0;
case 0x0c0670a2u: goto P_0c0670a2;
case 0x0c0670a4u: goto P_0c0670a4;
case 0x0c0670a6u: goto P_0c0670a6;
case 0x0c0670a8u: goto P_0c0670a8;
case 0x0c0670aau: goto P_0c0670aa;
case 0x0c0670acu: goto P_0c0670ac;
case 0x0c0670aeu: goto P_0c0670ae;
case 0x0c0670b0u: goto P_0c0670b0;
case 0x0c0670b2u: goto P_0c0670b2;
case 0x0c0670b4u: goto P_0c0670b4;
case 0x0c0670b6u: goto P_0c0670b6;
case 0x0c0670b8u: goto P_0c0670b8;
case 0x0c0670bau: goto P_0c0670ba;
case 0x0c0670bcu: goto P_0c0670bc;
case 0x0c0670beu: goto P_0c0670be;
case 0x0c0670c0u: goto P_0c0670c0;
case 0x0c0670c2u: goto P_0c0670c2;
case 0x0c0670d8u: goto P_0c0670d8;
case 0x0c0670dau: goto P_0c0670da;
case 0x0c0670dcu: goto P_0c0670dc;
case 0x0c0670deu: goto P_0c0670de;
case 0x0c0670e0u: goto P_0c0670e0;
case 0x0c0670e2u: goto P_0c0670e2;
case 0x0c0670e4u: goto P_0c0670e4;
case 0x0c0670e6u: goto P_0c0670e6;
case 0x0c0670e8u: goto P_0c0670e8;
case 0x0c0670eau: goto P_0c0670ea;
case 0x0c0670ecu: goto P_0c0670ec;
case 0x0c0670eeu: goto P_0c0670ee;
case 0x0c0670f0u: goto P_0c0670f0;
case 0x0c0670f2u: goto P_0c0670f2;
case 0x0c0670f4u: goto P_0c0670f4;
case 0x0c0670f6u: goto P_0c0670f6;
case 0x0c0670f8u: goto P_0c0670f8;
case 0x0c0670fau: goto P_0c0670fa;
case 0x0c0670fcu: goto P_0c0670fc;
case 0x0c0670feu: goto P_0c0670fe;
case 0x0c067100u: goto P_0c067100;
case 0x0c067102u: goto P_0c067102;
case 0x0c067104u: goto P_0c067104;
case 0x0c067106u: goto P_0c067106;
case 0x0c067108u: goto P_0c067108;
case 0x0c06710au: goto P_0c06710a;
case 0x0c06710cu: goto P_0c06710c;
case 0x0c06710eu: goto P_0c06710e;
case 0x0c067110u: goto P_0c067110;
case 0x0c067112u: goto P_0c067112;
case 0x0c067114u: goto P_0c067114;
case 0x0c067116u: goto P_0c067116;
case 0x0c067118u: goto P_0c067118;
case 0x0c06711au: goto P_0c06711a;
case 0x0c06711cu: goto P_0c06711c;
case 0x0c06711eu: goto P_0c06711e;
case 0x0c067120u: goto P_0c067120;
case 0x0c067122u: goto P_0c067122;
case 0x0c067124u: goto P_0c067124;
case 0x0c067126u: goto P_0c067126;
case 0x0c067128u: goto P_0c067128;
case 0x0c06712au: goto P_0c06712a;
case 0x0c06712cu: goto P_0c06712c;
case 0x0c06712eu: goto P_0c06712e;
case 0x0c067130u: goto P_0c067130;
case 0x0c067132u: goto P_0c067132;
case 0x0c067134u: goto P_0c067134;
case 0x0c067136u: goto P_0c067136;
case 0x0c067138u: goto P_0c067138;
case 0x0c06713au: goto P_0c06713a;
case 0x0c06713cu: goto P_0c06713c;
case 0x0c06713eu: goto P_0c06713e;
case 0x0c067140u: goto P_0c067140;
case 0x0c067142u: goto P_0c067142;
case 0x0c067144u: goto P_0c067144;
case 0x0c067146u: goto P_0c067146;
case 0x0c067148u: goto P_0c067148;
case 0x0c06714au: goto P_0c06714a;
case 0x0c06714cu: goto P_0c06714c;
case 0x0c06714eu: goto P_0c06714e;
case 0x0c067150u: goto P_0c067150;
case 0x0c067152u: goto P_0c067152;
case 0x0c067154u: goto P_0c067154;
case 0x0c067156u: goto P_0c067156;
case 0x0c067158u: goto P_0c067158;
case 0x0c06715au: goto P_0c06715a;
case 0x0c06715cu: goto P_0c06715c;
case 0x0c06715eu: goto P_0c06715e;
case 0x0c067160u: goto P_0c067160;
case 0x0c067162u: goto P_0c067162;
case 0x0c067164u: goto P_0c067164;
case 0x0c067166u: goto P_0c067166;
case 0x0c067168u: goto P_0c067168;
case 0x0c06716au: goto P_0c06716a;
case 0x0c06716cu: goto P_0c06716c;
case 0x0c06716eu: goto P_0c06716e;
case 0x0c067170u: goto P_0c067170;
case 0x0c067172u: goto P_0c067172;
case 0x0c067174u: goto P_0c067174;
case 0x0c067176u: goto P_0c067176;
case 0x0c067178u: goto P_0c067178;
case 0x0c06717au: goto P_0c06717a;
case 0x0c06717cu: goto P_0c06717c;
case 0x0c06717eu: goto P_0c06717e;
case 0x0c067180u: goto P_0c067180;
case 0x0c067182u: goto P_0c067182;
case 0x0c067184u: goto P_0c067184;
case 0x0c067186u: goto P_0c067186;
case 0x0c067188u: goto P_0c067188;
case 0x0c06718au: goto P_0c06718a;
case 0x0c06718cu: goto P_0c06718c;
case 0x0c06718eu: goto P_0c06718e;
case 0x0c067190u: goto P_0c067190;
case 0x0c067192u: goto P_0c067192;
case 0x0c067194u: goto P_0c067194;
case 0x0c067196u: goto P_0c067196;
case 0x0c067198u: goto P_0c067198;
case 0x0c06719au: goto P_0c06719a;
case 0x0c06719cu: goto P_0c06719c;
case 0x0c06719eu: goto P_0c06719e;
case 0x0c0671a0u: goto P_0c0671a0;
case 0x0c0671a2u: goto P_0c0671a2;
case 0x0c0671a4u: goto P_0c0671a4;
case 0x0c0671a6u: goto P_0c0671a6;
case 0x0c0671a8u: goto P_0c0671a8;
default: return vf3_matrix_family(target,s,ram);
}
P_0c066f88: /* original 6343, guest PC 0x0c066f88 */
if(!s->budget--) { s->failed_pc=0x0c066f88u; return 0; }
r[3]=r[4];
goto P_0c066f8a;
P_0c066f8a: /* original 6243, guest PC 0x0c066f8a */
if(!s->budget--) { s->failed_pc=0x0c066f8au; return 0; }
r[2]=r[4];
goto P_0c066f8c;
P_0c066f8c: /* original d110, guest PC 0x0c066f8c */
if(!s->budget--) { s->failed_pc=0x0c066f8cu; return 0; }
r[1]=read(ram,0x0c066fd0u,4);
goto P_0c066f8e;
P_0c066f8e: /* original 4329, guest PC 0x0c066f8e */
if(!s->budget--) { s->failed_pc=0x0c066f8eu; return 0; }
r[3]>>=16;
goto P_0c066f90;
P_0c066f90: /* original 4219, guest PC 0x0c066f90 */
if(!s->budget--) { s->failed_pc=0x0c066f90u; return 0; }
r[2]>>=8;
goto P_0c066f92;
P_0c066f92: /* original d010, guest PC 0x0c066f92 */
if(!s->budget--) { s->failed_pc=0x0c066f92u; return 0; }
r[0]=read(ram,0x0c066fd4u,4);
goto P_0c066f94;
P_0c066f94: /* original 4319, guest PC 0x0c066f94 */
if(!s->budget--) { s->failed_pc=0x0c066f94u; return 0; }
r[3]>>=8;
goto P_0c066f96;
P_0c066f96: /* original 2219, guest PC 0x0c066f96 */
if(!s->budget--) { s->failed_pc=0x0c066f96u; return 0; }
r[2]&=r[1];
goto P_0c066f98;
P_0c066f98: /* original 633c, guest PC 0x0c066f98 */
if(!s->budget--) { s->failed_pc=0x0c066f98u; return 0; }
r[3]=r[3]&255u;
goto P_0c066f9a;
P_0c066f9a: /* original 232b, guest PC 0x0c066f9a */
if(!s->budget--) { s->failed_pc=0x0c066f9au; return 0; }
r[3]|=r[2];
goto P_0c066f9c;
P_0c066f9c: /* original 6243, guest PC 0x0c066f9c */
if(!s->budget--) { s->failed_pc=0x0c066f9cu; return 0; }
r[2]=r[4];
goto P_0c066f9e;
P_0c066f9e: /* original 4218, guest PC 0x0c066f9e */
if(!s->budget--) { s->failed_pc=0x0c066f9eu; return 0; }
r[2]<<=8;
goto P_0c066fa0;
P_0c066fa0: /* original 2209, guest PC 0x0c066fa0 */
if(!s->budget--) { s->failed_pc=0x0c066fa0u; return 0; }
r[2]&=r[0];
goto P_0c066fa2;
P_0c066fa2: /* original 232b, guest PC 0x0c066fa2 */
if(!s->budget--) { s->failed_pc=0x0c066fa2u; return 0; }
r[3]|=r[2];
goto P_0c066fa4;
P_0c066fa4: /* original 6243, guest PC 0x0c066fa4 */
if(!s->budget--) { s->failed_pc=0x0c066fa4u; return 0; }
r[2]=r[4];
goto P_0c066fa6;
P_0c066fa6: /* original 4228, guest PC 0x0c066fa6 */
if(!s->budget--) { s->failed_pc=0x0c066fa6u; return 0; }
r[2]<<=16;
goto P_0c066fa8;
P_0c066fa8: /* original 6433, guest PC 0x0c066fa8 */
if(!s->budget--) { s->failed_pc=0x0c066fa8u; return 0; }
r[4]=r[3];
goto P_0c066faa;
P_0c066faa: /* original 4128, guest PC 0x0c066faa */
if(!s->budget--) { s->failed_pc=0x0c066faau; return 0; }
r[1]<<=16;
goto P_0c066fac;
P_0c066fac: /* original 4218, guest PC 0x0c066fac */
if(!s->budget--) { s->failed_pc=0x0c066facu; return 0; }
r[2]<<=8;
goto P_0c066fae;
P_0c066fae: /* original 2219, guest PC 0x0c066fae */
if(!s->budget--) { s->failed_pc=0x0c066faeu; return 0; }
r[2]&=r[1];
goto P_0c066fb0;
P_0c066fb0: /* original 242b, guest PC 0x0c066fb0 */
if(!s->budget--) { s->failed_pc=0x0c066fb0u; return 0; }
r[4]|=r[2];
goto P_0c066fb2;
P_0c066fb2: /* original 000b, guest PC 0x0c066fb2 */
if(!s->budget--) { s->failed_pc=0x0c066fb2u; return 0; }
target=r[16];
r[0]=r[4];
s->pc=target; return ram->oob==0;
P_0c066fb4: /* original 6043, guest PC 0x0c066fb4 */
if(!s->budget--) { s->failed_pc=0x0c066fb4u; return 0; }
r[0]=r[4];
if(!vf3_matrix_family(0x0c066fb6u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c066fb6u; return 0; } return 1;
P_0c066fd8: /* original 2fe6, guest PC 0x0c066fd8 */
if(!s->budget--) { s->failed_pc=0x0c066fd8u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c066fda;
P_0c066fda: /* original 6e43, guest PC 0x0c066fda */
if(!s->budget--) { s->failed_pc=0x0c066fdau; return 0; }
r[14]=r[4];
goto P_0c066fdc;
P_0c066fdc: /* original 2fd6, guest PC 0x0c066fdc */
if(!s->budget--) { s->failed_pc=0x0c066fdcu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c066fde;
P_0c066fde: /* original 2fc6, guest PC 0x0c066fde */
if(!s->budget--) { s->failed_pc=0x0c066fdeu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c066fe0;
P_0c066fe0: /* original 6c53, guest PC 0x0c066fe0 */
if(!s->budget--) { s->failed_pc=0x0c066fe0u; return 0; }
r[12]=r[5];
goto P_0c066fe2;
P_0c066fe2: /* original 2fb6, guest PC 0x0c066fe2 */
if(!s->budget--) { s->failed_pc=0x0c066fe2u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c066fe4;
P_0c066fe4: /* original 6b63, guest PC 0x0c066fe4 */
if(!s->budget--) { s->failed_pc=0x0c066fe4u; return 0; }
r[11]=r[6];
goto P_0c066fe6;
P_0c066fe6: /* original 4f22, guest PC 0x0c066fe6 */
if(!s->budget--) { s->failed_pc=0x0c066fe6u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c066fe8;
P_0c066fe8: /* original 7ffc, guest PC 0x0c066fe8 */
if(!s->budget--) { s->failed_pc=0x0c066fe8u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c066fea;
P_0c066fea: /* original 2f72, guest PC 0x0c066fea */
if(!s->budget--) { s->failed_pc=0x0c066feau; return 0; }
write(ram,r[15],r[7],4);
goto P_0c066fec;
P_0c066fec: /* original 64c2, guest PC 0x0c066fec */
if(!s->budget--) { s->failed_pc=0x0c066fecu; return 0; }
tmp=read(ram,r[12],4);
r[4]=tmp;
goto P_0c066fee;
P_0c066fee: /* original 9069, guest PC 0x0c066fee */
if(!s->budget--) { s->failed_pc=0x0c066feeu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0670c4u,2);
goto P_0c066ff0;
P_0c066ff0: /* original 24b9, guest PC 0x0c066ff0 */
if(!s->budget--) { s->failed_pc=0x0c066ff0u; return 0; }
r[4]&=r[11];
goto P_0c066ff2;
P_0c066ff2: /* original 2448, guest PC 0x0c066ff2 */
if(!s->budget--) { s->failed_pc=0x0c066ff2u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c066ff4;
P_0c066ff4: /* original 8d0e, guest PC 0x0c066ff4 */
if(!s->budget--) { s->failed_pc=0x0c066ff4u; return 0; }
cond=r[17]&1u;
r[13]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
if(cond) { goto P_0c067014; }
goto P_0c066ff8;
P_0c066ff6: /* original 0ded, guest PC 0x0c066ff6 */
if(!s->budget--) { s->failed_pc=0x0c066ff6u; return 0; }
r[13]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c066ff8;
P_0c066ff8: /* original 62c2, guest PC 0x0c066ff8 */
if(!s->budget--) { s->failed_pc=0x0c066ff8u; return 0; }
tmp=read(ram,r[12],4);
r[2]=tmp;
goto P_0c066ffa;
P_0c066ffa: /* original 63b7, guest PC 0x0c066ffa */
if(!s->budget--) { s->failed_pc=0x0c066ffau; return 0; }
r[3]=~r[11];
goto P_0c066ffc;
P_0c066ffc: /* original 2239, guest PC 0x0c066ffc */
if(!s->budget--) { s->failed_pc=0x0c066ffcu; return 0; }
r[2]&=r[3];
goto P_0c066ffe;
P_0c066ffe: /* original 2c22, guest PC 0x0c066ffe */
if(!s->budget--) { s->failed_pc=0x0c066ffeu; return 0; }
write(ram,r[12],r[2],4);
goto P_0c067000;
P_0c067000: /* original 9061, guest PC 0x0c067000 */
if(!s->budget--) { s->failed_pc=0x0c067000u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0670c6u,2);
goto P_0c067002;
P_0c067002: /* original bfc1, guest PC 0x0c067002 */
if(!s->budget--) { s->failed_pc=0x0c067002u; return 0; }
target=code_base|0x0c066f88u; r[16]=code_base|0x0c067006u;
r[4]=read(ram,r[14]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c067006u) { target=s->pc; goto dispatch; }
goto P_0c067006;
P_0c067004: /* original 04ee, guest PC 0x0c067004 */
if(!s->budget--) { s->failed_pc=0x0c067004u; return 0; }
r[4]=read(ram,r[14]+r[0],4);
goto P_0c067006;
P_0c067006: /* original 6403, guest PC 0x0c067006 */
if(!s->budget--) { s->failed_pc=0x0c067006u; return 0; }
r[4]=r[0];
goto P_0c067008;
P_0c067008: /* original 2448, guest PC 0x0c067008 */
if(!s->budget--) { s->failed_pc=0x0c067008u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c06700a;
P_0c06700a: /* original 8b03, guest PC 0x0c06700a */
if(!s->budget--) { s->failed_pc=0x0c06700au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c067014; }
goto P_0c06700c;
P_0c06700c: /* original 62e3, guest PC 0x0c06700c */
if(!s->budget--) { s->failed_pc=0x0c06700cu; return 0; }
r[2]=r[14];
goto P_0c06700e;
P_0c06700e: /* original 32dc, guest PC 0x0c06700e */
if(!s->budget--) { s->failed_pc=0x0c06700eu; return 0; }
r[2]+=r[13];
goto P_0c067010;
P_0c067010: /* original 6d21, guest PC 0x0c067010 */
if(!s->budget--) { s->failed_pc=0x0c067010u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[2],2);
r[13]=tmp;
goto P_0c067012;
P_0c067012: /* original 6ddd, guest PC 0x0c067012 */
if(!s->budget--) { s->failed_pc=0x0c067012u; return 0; }
r[13]=r[13]&65535u;
goto P_0c067014;
P_0c067014: /* original 63f2, guest PC 0x0c067014 */
if(!s->budget--) { s->failed_pc=0x0c067014u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c067016;
P_0c067016: /* original 9055, guest PC 0x0c067016 */
if(!s->budget--) { s->failed_pc=0x0c067016u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0670c4u,2);
goto P_0c067018;
P_0c067018: /* original 3d38, guest PC 0x0c067018 */
if(!s->budget--) { s->failed_pc=0x0c067018u; return 0; }
r[13]-=r[3];
goto P_0c06701a;
P_0c06701a: /* original 4d15, guest PC 0x0c06701a */
if(!s->budget--) { s->failed_pc=0x0c06701au; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[13]>0)!=0);
goto P_0c06701c;
P_0c06701c: /* original 8d18, guest PC 0x0c06701c */
if(!s->budget--) { s->failed_pc=0x0c06701cu; return 0; }
cond=r[17]&1u;
write(ram,r[14]+r[0],r[13],2);
if(cond) { goto P_0c067050; }
goto P_0c067020;
P_0c06701e: /* original 0ed5, guest PC 0x0c06701e */
if(!s->budget--) { s->failed_pc=0x0c06701eu; return 0; }
write(ram,r[14]+r[0],r[13],2);
goto P_0c067020;
P_0c067020: /* original 9052, guest PC 0x0c067020 */
if(!s->budget--) { s->failed_pc=0x0c067020u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0670c8u,2);
goto P_0c067022;
P_0c067022: /* original 04ee, guest PC 0x0c067022 */
if(!s->budget--) { s->failed_pc=0x0c067022u; return 0; }
r[4]=read(ram,r[14]+r[0],4);
goto P_0c067024;
P_0c067024: /* original 7404, guest PC 0x0c067024 */
if(!s->budget--) { s->failed_pc=0x0c067024u; return 0; }
r[4]+=0x00000004u;
goto P_0c067026;
P_0c067026: /* original 6546, guest PC 0x0c067026 */
if(!s->budget--) { s->failed_pc=0x0c067026u; return 0; }
tmp=read(ram,r[4],4);
r[4]+=4;
r[5]=tmp;
goto P_0c067028;
P_0c067028: /* original 6746, guest PC 0x0c067028 */
if(!s->budget--) { s->failed_pc=0x0c067028u; return 0; }
tmp=read(ram,r[4],4);
r[4]+=4;
r[7]=tmp;
goto P_0c06702a;
P_0c06702a: /* original 2558, guest PC 0x0c06702a */
if(!s->budget--) { s->failed_pc=0x0c06702au; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[5])==0)!=0);
goto P_0c06702c;
P_0c06702c: /* original 6642, guest PC 0x0c06702c */
if(!s->budget--) { s->failed_pc=0x0c06702cu; return 0; }
tmp=read(ram,r[4],4);
r[6]=tmp;
goto P_0c06702e;
P_0c06702e: /* original 8f07, guest PC 0x0c06702e */
if(!s->budget--) { s->failed_pc=0x0c06702eu; return 0; }
cond=r[17]&1u;
write(ram,r[14]+r[0],r[4],4);
if(!cond) { goto P_0c067040; }
goto P_0c067032;
P_0c067030: /* original 0e46, guest PC 0x0c067030 */
if(!s->budget--) { s->failed_pc=0x0c067030u; return 0; }
write(ram,r[14]+r[0],r[4],4);
goto P_0c067032;
P_0c067032: /* original 9047, guest PC 0x0c067032 */
if(!s->budget--) { s->failed_pc=0x0c067032u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0670c4u,2);
goto P_0c067034;
P_0c067034: /* original 0e75, guest PC 0x0c067034 */
if(!s->budget--) { s->failed_pc=0x0c067034u; return 0; }
write(ram,r[14]+r[0],r[7],2);
goto P_0c067036;
P_0c067036: /* original 7008, guest PC 0x0c067036 */
if(!s->budget--) { s->failed_pc=0x0c067036u; return 0; }
r[0]+=0x00000008u;
goto P_0c067038;
P_0c067038: /* original 0e65, guest PC 0x0c067038 */
if(!s->budget--) { s->failed_pc=0x0c067038u; return 0; }
write(ram,r[14]+r[0],r[6],2);
goto P_0c06703a;
P_0c06703a: /* original d326, guest PC 0x0c06703a */
if(!s->budget--) { s->failed_pc=0x0c06703au; return 0; }
r[3]=read(ram,0x0c0670d4u,4);
goto P_0c06703c;
P_0c06703c: /* original a008, guest PC 0x0c06703c */
if(!s->budget--) { s->failed_pc=0x0c06703cu; return 0; }
write(ram,r[14]+48,r[3],4);
goto P_0c067050;
P_0c06703e: /* original 1e3c, guest PC 0x0c06703e */
if(!s->budget--) { s->failed_pc=0x0c06703eu; return 0; }
write(ram,r[14]+48,r[3],4);
goto P_0c067040;
P_0c067040: /* original 61c2, guest PC 0x0c067040 */
if(!s->budget--) { s->failed_pc=0x0c067040u; return 0; }
tmp=read(ram,r[12],4);
r[1]=tmp;
goto P_0c067042;
P_0c067042: /* original 21bb, guest PC 0x0c067042 */
if(!s->budget--) { s->failed_pc=0x0c067042u; return 0; }
r[1]|=r[11];
goto P_0c067044;
P_0c067044: /* original 2c12, guest PC 0x0c067044 */
if(!s->budget--) { s->failed_pc=0x0c067044u; return 0; }
write(ram,r[12],r[1],4);
goto P_0c067046;
P_0c067046: /* original 903d, guest PC 0x0c067046 */
if(!s->budget--) { s->failed_pc=0x0c067046u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0670c4u,2);
goto P_0c067048;
P_0c067048: /* original 0e75, guest PC 0x0c067048 */
if(!s->budget--) { s->failed_pc=0x0c067048u; return 0; }
write(ram,r[14]+r[0],r[7],2);
goto P_0c06704a;
P_0c06704a: /* original 7008, guest PC 0x0c06704a */
if(!s->budget--) { s->failed_pc=0x0c06704au; return 0; }
r[0]+=0x00000008u;
goto P_0c06704c;
P_0c06704c: /* original 0e65, guest PC 0x0c06704c */
if(!s->budget--) { s->failed_pc=0x0c06704cu; return 0; }
write(ram,r[14]+r[0],r[6],2);
goto P_0c06704e;
P_0c06704e: /* original 1e5c, guest PC 0x0c06704e */
if(!s->budget--) { s->failed_pc=0x0c06704eu; return 0; }
write(ram,r[14]+48,r[5],4);
goto P_0c067050;
P_0c067050: /* original 7f04, guest PC 0x0c067050 */
if(!s->budget--) { s->failed_pc=0x0c067050u; return 0; }
r[15]+=0x00000004u;
goto P_0c067052;
P_0c067052: /* original 4f26, guest PC 0x0c067052 */
if(!s->budget--) { s->failed_pc=0x0c067052u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c067054;
P_0c067054: /* original 6bf6, guest PC 0x0c067054 */
if(!s->budget--) { s->failed_pc=0x0c067054u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c067056;
P_0c067056: /* original 6cf6, guest PC 0x0c067056 */
if(!s->budget--) { s->failed_pc=0x0c067056u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c067058;
P_0c067058: /* original 6df6, guest PC 0x0c067058 */
if(!s->budget--) { s->failed_pc=0x0c067058u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c06705a;
P_0c06705a: /* original 000b, guest PC 0x0c06705a */
if(!s->budget--) { s->failed_pc=0x0c06705au; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c06705c: /* original 6ef6, guest PC 0x0c06705c */
if(!s->budget--) { s->failed_pc=0x0c06705cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c06705e;
P_0c06705e: /* original 2fe6, guest PC 0x0c06705e */
if(!s->budget--) { s->failed_pc=0x0c06705eu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c067060;
P_0c067060: /* original 6e43, guest PC 0x0c067060 */
if(!s->budget--) { s->failed_pc=0x0c067060u; return 0; }
r[14]=r[4];
goto P_0c067062;
P_0c067062: /* original 2fd6, guest PC 0x0c067062 */
if(!s->budget--) { s->failed_pc=0x0c067062u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c067064;
P_0c067064: /* original 2fc6, guest PC 0x0c067064 */
if(!s->budget--) { s->failed_pc=0x0c067064u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c067066;
P_0c067066: /* original 2fb6, guest PC 0x0c067066 */
if(!s->budget--) { s->failed_pc=0x0c067066u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c067068;
P_0c067068: /* original fffb, guest PC 0x0c067068 */
if(!s->budget--) { s->failed_pc=0x0c067068u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c06706a;
P_0c06706a: /* original ffeb, guest PC 0x0c06706a */
if(!s->budget--) { s->failed_pc=0x0c06706au; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,14,r[15]);
goto P_0c06706c;
P_0c06706c: /* original 902d, guest PC 0x0c06706c */
if(!s->budget--) { s->failed_pc=0x0c06706cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0670cau,2);
goto P_0c06706e;
P_0c06706e: /* original 4f22, guest PC 0x0c06706e */
if(!s->budget--) { s->failed_pc=0x0c06706eu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c067070;
P_0c067070: /* original 03ed, guest PC 0x0c067070 */
if(!s->budget--) { s->failed_pc=0x0c067070u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c067072;
P_0c067072: /* original 73ff, guest PC 0x0c067072 */
if(!s->budget--) { s->failed_pc=0x0c067072u; return 0; }
r[3]+=0xffffffffu;
goto P_0c067074;
P_0c067074: /* original 7ffc, guest PC 0x0c067074 */
if(!s->budget--) { s->failed_pc=0x0c067074u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c067076;
P_0c067076: /* original 0e35, guest PC 0x0c067076 */
if(!s->budget--) { s->failed_pc=0x0c067076u; return 0; }
write(ram,r[14]+r[0],r[3],2);
goto P_0c067078;
P_0c067078: /* original 02ed, guest PC 0x0c067078 */
if(!s->budget--) { s->failed_pc=0x0c067078u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c06707a;
P_0c06707a: /* original 4215, guest PC 0x0c06707a */
if(!s->budget--) { s->failed_pc=0x0c06707au; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[2]>0)!=0);
goto P_0c06707c;
P_0c06707c: /* original 8b01, guest PC 0x0c06707c */
if(!s->budget--) { s->failed_pc=0x0c06707cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c067082; }
goto P_0c06707e;
P_0c06707e: /* original a08b, guest PC 0x0c06707e */
if(!s->budget--) { s->failed_pc=0x0c06707eu; return 0; }
goto P_0c067198;
P_0c067080: /* original 0009, guest PC 0x0c067080 */
if(!s->budget--) { s->failed_pc=0x0c067080u; return 0; }
goto P_0c067082;
P_0c067082: /* original 9023, guest PC 0x0c067082 */
if(!s->budget--) { s->failed_pc=0x0c067082u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0670ccu,2);
goto P_0c067084;
P_0c067084: /* original 04ee, guest PC 0x0c067084 */
if(!s->budget--) { s->failed_pc=0x0c067084u; return 0; }
r[4]=read(ram,r[14]+r[0],4);
goto P_0c067086;
P_0c067086: /* original 6340, guest PC 0x0c067086 */
if(!s->budget--) { s->failed_pc=0x0c067086u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[4],1);
r[3]=tmp;
goto P_0c067088;
P_0c067088: /* original 633c, guest PC 0x0c067088 */
if(!s->budget--) { s->failed_pc=0x0c067088u; return 0; }
r[3]=r[3]&255u;
goto P_0c06708a;
P_0c06708a: /* original 2f32, guest PC 0x0c06708a */
if(!s->budget--) { s->failed_pc=0x0c06708au; return 0; }
write(ram,r[15],r[3],4);
goto P_0c06708c;
P_0c06708c: /* original 8441, guest PC 0x0c06708c */
if(!s->budget--) { s->failed_pc=0x0c06708cu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+1,1);
goto P_0c06708e;
P_0c06708e: /* original 5641, guest PC 0x0c06708e */
if(!s->budget--) { s->failed_pc=0x0c06708eu; return 0; }
r[6]=read(ram,r[4]+4,4);
goto P_0c067090;
P_0c067090: /* original 650c, guest PC 0x0c067090 */
if(!s->budget--) { s->failed_pc=0x0c067090u; return 0; }
r[5]=r[0]&255u;
goto P_0c067092;
P_0c067092: /* original 8541, guest PC 0x0c067092 */
if(!s->budget--) { s->failed_pc=0x0c067092u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+2,2);
goto P_0c067094;
P_0c067094: /* original 5d45, guest PC 0x0c067094 */
if(!s->budget--) { s->failed_pc=0x0c067094u; return 0; }
r[13]=read(ram,r[4]+20,4);
goto P_0c067096;
P_0c067096: /* original 6b03, guest PC 0x0c067096 */
if(!s->budget--) { s->failed_pc=0x0c067096u; return 0; }
r[11]=r[0];
goto P_0c067098;
P_0c067098: /* original e008, guest PC 0x0c067098 */
if(!s->budget--) { s->failed_pc=0x0c067098u; return 0; }
r[0]=0x00000008u;
goto P_0c06709a;
P_0c06709a: /* original fe46, guest PC 0x0c06709a */
if(!s->budget--) { s->failed_pc=0x0c06709au; return 0; }
vf3_matrix_load(s,ram,14,r[4]+r[0]);
goto P_0c06709c;
P_0c06709c: /* original e00c, guest PC 0x0c06709c */
if(!s->budget--) { s->failed_pc=0x0c06709cu; return 0; }
r[0]=0x0000000cu;
goto P_0c06709e;
P_0c06709e: /* original f546, guest PC 0x0c06709e */
if(!s->budget--) { s->failed_pc=0x0c06709eu; return 0; }
vf3_matrix_load(s,ram,5,r[4]+r[0]);
goto P_0c0670a0;
P_0c0670a0: /* original e010, guest PC 0x0c0670a0 */
if(!s->budget--) { s->failed_pc=0x0c0670a0u; return 0; }
r[0]=0x00000010u;
goto P_0c0670a2;
P_0c0670a2: /* original ff46, guest PC 0x0c0670a2 */
if(!s->budget--) { s->failed_pc=0x0c0670a2u; return 0; }
vf3_matrix_load(s,ram,15,r[4]+r[0]);
goto P_0c0670a4;
P_0c0670a4: /* original 7418, guest PC 0x0c0670a4 */
if(!s->budget--) { s->failed_pc=0x0c0670a4u; return 0; }
r[4]+=0x00000018u;
goto P_0c0670a6;
P_0c0670a6: /* original 9010, guest PC 0x0c0670a6 */
if(!s->budget--) { s->failed_pc=0x0c0670a6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0670cau,2);
goto P_0c0670a8;
P_0c0670a8: /* original ff4d, guest PC 0x0c0670a8 */
if(!s->budget--) { s->failed_pc=0x0c0670a8u; return 0; }
fr[15]^=0x80000000u;
goto P_0c0670aa;
P_0c0670aa: /* original 0e65, guest PC 0x0c0670aa */
if(!s->budget--) { s->failed_pc=0x0c0670aau; return 0; }
write(ram,r[14]+r[0],r[6],2);
goto P_0c0670ac;
P_0c0670ac: /* original 70f2, guest PC 0x0c0670ac */
if(!s->budget--) { s->failed_pc=0x0c0670acu; return 0; }
r[0]+=0xfffffff2u;
goto P_0c0670ae;
P_0c0670ae: /* original 930e, guest PC 0x0c0670ae */
if(!s->budget--) { s->failed_pc=0x0c0670aeu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0670ceu,2);
goto P_0c0670b0;
P_0c0670b0: /* original 3530, guest PC 0x0c0670b0 */
if(!s->budget--) { s->failed_pc=0x0c0670b0u; return 0; }
r[17]=(r[17]&~1u)|((r[5]==r[3])!=0);
goto P_0c0670b2;
P_0c0670b2: /* original 8f11, guest PC 0x0c0670b2 */
if(!s->budget--) { s->failed_pc=0x0c0670b2u; return 0; }
cond=r[17]&1u;
write(ram,r[14]+r[0],r[4],4);
if(!cond) { goto P_0c0670d8; }
goto P_0c0670b6;
P_0c0670b4: /* original 0e46, guest PC 0x0c0670b4 */
if(!s->budget--) { s->failed_pc=0x0c0670b4u; return 0; }
write(ram,r[14]+r[0],r[4],4);
goto P_0c0670b6;
P_0c0670b6: /* original 900b, guest PC 0x0c0670b6 */
if(!s->budget--) { s->failed_pc=0x0c0670b6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0670d0u,2);
goto P_0c0670b8;
P_0c0670b8: /* original e3fe, guest PC 0x0c0670b8 */
if(!s->budget--) { s->failed_pc=0x0c0670b8u; return 0; }
r[3]=0xfffffffeu;
goto P_0c0670ba;
P_0c0670ba: /* original 0e54, guest PC 0x0c0670ba */
if(!s->budget--) { s->failed_pc=0x0c0670bau; return 0; }
write(ram,r[14]+r[0],r[5],1);
goto P_0c0670bc;
P_0c0670bc: /* original 62e2, guest PC 0x0c0670bc */
if(!s->budget--) { s->failed_pc=0x0c0670bcu; return 0; }
tmp=read(ram,r[14],4);
r[2]=tmp;
goto P_0c0670be;
P_0c0670be: /* original 2239, guest PC 0x0c0670be */
if(!s->budget--) { s->failed_pc=0x0c0670beu; return 0; }
r[2]&=r[3];
goto P_0c0670c0;
P_0c0670c0: /* original a06a, guest PC 0x0c0670c0 */
if(!s->budget--) { s->failed_pc=0x0c0670c0u; return 0; }
write(ram,r[14],r[2],4);
goto P_0c067198;
P_0c0670c2: /* original 2e22, guest PC 0x0c0670c2 */
if(!s->budget--) { s->failed_pc=0x0c0670c2u; return 0; }
write(ram,r[14],r[2],4);
if(!vf3_matrix_family(0x0c0670c4u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0670c4u; return 0; } return 1;
P_0c0670d8: /* original e060, guest PC 0x0c0670d8 */
if(!s->budget--) { s->failed_pc=0x0c0670d8u; return 0; }
r[0]=0x00000060u;
goto P_0c0670da;
P_0c0670da: /* original 03ec, guest PC 0x0c0670da */
if(!s->budget--) { s->failed_pc=0x0c0670dau; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0670dc;
P_0c0670dc: /* original 633c, guest PC 0x0c0670dc */
if(!s->budget--) { s->failed_pc=0x0c0670dcu; return 0; }
r[3]=r[3]&255u;
goto P_0c0670de;
P_0c0670de: /* original 3350, guest PC 0x0c0670de */
if(!s->budget--) { s->failed_pc=0x0c0670deu; return 0; }
r[17]=(r[17]&~1u)|((r[3]==r[5])!=0);
goto P_0c0670e0;
P_0c0670e0: /* original 8f3b, guest PC 0x0c0670e0 */
if(!s->budget--) { s->failed_pc=0x0c0670e0u; return 0; }
cond=r[17]&1u;
r[12]=0x00000001u;
if(!cond) { goto P_0c06715a; }
goto P_0c0670e4;
P_0c0670e2: /* original ec01, guest PC 0x0c0670e2 */
if(!s->budget--) { s->failed_pc=0x0c0670e2u; return 0; }
r[12]=0x00000001u;
goto P_0c0670e4;
P_0c0670e4: /* original 63e2, guest PC 0x0c0670e4 */
if(!s->budget--) { s->failed_pc=0x0c0670e4u; return 0; }
tmp=read(ram,r[14],4);
r[3]=tmp;
goto P_0c0670e6;
P_0c0670e6: /* original 23c8, guest PC 0x0c0670e6 */
if(!s->budget--) { s->failed_pc=0x0c0670e6u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[12])==0)!=0);
goto P_0c0670e8;
P_0c0670e8: /* original 8937, guest PC 0x0c0670e8 */
if(!s->budget--) { s->failed_pc=0x0c0670e8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c06715a; }
goto P_0c0670ea;
P_0c0670ea: /* original 6053, guest PC 0x0c0670ea */
if(!s->budget--) { s->failed_pc=0x0c0670eau; return 0; }
r[0]=r[5];
goto P_0c0670ec;
P_0c0670ec: /* original 8816, guest PC 0x0c0670ec */
if(!s->budget--) { s->failed_pc=0x0c0670ecu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000016u)!=0);
goto P_0c0670ee;
P_0c0670ee: /* original 8905, guest PC 0x0c0670ee */
if(!s->budget--) { s->failed_pc=0x0c0670eeu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0670fc; }
goto P_0c0670f0;
P_0c0670f0: /* original d331, guest PC 0x0c0670f0 */
if(!s->budget--) { s->failed_pc=0x0c0670f0u; return 0; }
r[3]=read(ram,0x0c0671b8u,4);
goto P_0c0670f2;
P_0c0670f2: /* original f5fc, guest PC 0x0c0670f2 */
if(!s->budget--) { s->failed_pc=0x0c0670f2u; return 0; }
vf3_matrix_move(s,5,15);
goto P_0c0670f4;
P_0c0670f4: /* original f54d, guest PC 0x0c0670f4 */
if(!s->budget--) { s->failed_pc=0x0c0670f4u; return 0; }
fr[5]^=0x80000000u;
goto P_0c0670f6;
P_0c0670f6: /* original 430b, guest PC 0x0c0670f6 */
if(!s->budget--) { s->failed_pc=0x0c0670f6u; return 0; }
target=r[3];
r[16]=code_base|0x0c0670fau;
vf3_matrix_move(s,4,14);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0670fau) { target=s->pc; goto dispatch; }
goto P_0c0670fa;
P_0c0670f8: /* original f4ec, guest PC 0x0c0670f8 */
if(!s->budget--) { s->failed_pc=0x0c0670f8u; return 0; }
vf3_matrix_move(s,4,14);
goto P_0c0670fa;
P_0c0670fa: /* original f50c, guest PC 0x0c0670fa */
if(!s->budget--) { s->failed_pc=0x0c0670fau; return 0; }
vf3_matrix_move(s,5,0);
goto P_0c0670fc;
P_0c0670fc: /* original e010, guest PC 0x0c0670fc */
if(!s->budget--) { s->failed_pc=0x0c0670fcu; return 0; }
r[0]=0x00000010u;
goto P_0c0670fe;
P_0c0670fe: /* original fee7, guest PC 0x0c0670fe */
if(!s->budget--) { s->failed_pc=0x0c0670feu; return 0; }
vf3_matrix_store(s,ram,14,r[14]+r[0]);
goto P_0c067100;
P_0c067100: /* original e014, guest PC 0x0c067100 */
if(!s->budget--) { s->failed_pc=0x0c067100u; return 0; }
r[0]=0x00000014u;
goto P_0c067102;
P_0c067102: /* original fe57, guest PC 0x0c067102 */
if(!s->budget--) { s->failed_pc=0x0c067102u; return 0; }
vf3_matrix_store(s,ram,5,r[14]+r[0]);
goto P_0c067104;
P_0c067104: /* original e018, guest PC 0x0c067104 */
if(!s->budget--) { s->failed_pc=0x0c067104u; return 0; }
r[0]=0x00000018u;
goto P_0c067106;
P_0c067106: /* original fef7, guest PC 0x0c067106 */
if(!s->budget--) { s->failed_pc=0x0c067106u; return 0; }
vf3_matrix_store(s,ram,15,r[14]+r[0]);
goto P_0c067108;
P_0c067108: /* original 9051, guest PC 0x0c067108 */
if(!s->budget--) { s->failed_pc=0x0c067108u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0671aeu,2);
goto P_0c06710a;
P_0c06710a: /* original fee7, guest PC 0x0c06710a */
if(!s->budget--) { s->failed_pc=0x0c06710au; return 0; }
vf3_matrix_store(s,ram,14,r[14]+r[0]);
goto P_0c06710c;
P_0c06710c: /* original 7004, guest PC 0x0c06710c */
if(!s->budget--) { s->failed_pc=0x0c06710cu; return 0; }
r[0]+=0x00000004u;
goto P_0c06710e;
P_0c06710e: /* original fe57, guest PC 0x0c06710e */
if(!s->budget--) { s->failed_pc=0x0c06710eu; return 0; }
vf3_matrix_store(s,ram,5,r[14]+r[0]);
goto P_0c067110;
P_0c067110: /* original 7004, guest PC 0x0c067110 */
if(!s->budget--) { s->failed_pc=0x0c067110u; return 0; }
r[0]+=0x00000004u;
goto P_0c067112;
P_0c067112: /* original fef7, guest PC 0x0c067112 */
if(!s->budget--) { s->failed_pc=0x0c067112u; return 0; }
vf3_matrix_store(s,ram,15,r[14]+r[0]);
goto P_0c067114;
P_0c067114: /* original 904d, guest PC 0x0c067114 */
if(!s->budget--) { s->failed_pc=0x0c067114u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0671b2u,2);
goto P_0c067116;
P_0c067116: /* original 934b, guest PC 0x0c067116 */
if(!s->budget--) { s->failed_pc=0x0c067116u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0671b0u,2);
goto P_0c067118;
P_0c067118: /* original 0e34, guest PC 0x0c067118 */
if(!s->budget--) { s->failed_pc=0x0c067118u; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c06711a;
P_0c06711a: /* original 60b3, guest PC 0x0c06711a */
if(!s->budget--) { s->failed_pc=0x0c06711au; return 0; }
r[0]=r[11];
goto P_0c06711c;
P_0c06711c: /* original 81ef, guest PC 0x0c06711c */
if(!s->budget--) { s->failed_pc=0x0c06711cu; return 0; }
write(ram,r[14]+30,r[0],2);
goto P_0c06711e;
P_0c06711e: /* original 60d3, guest PC 0x0c06711e */
if(!s->budget--) { s->failed_pc=0x0c06711eu; return 0; }
r[0]=r[13];
goto P_0c067120;
P_0c067120: /* original 62e2, guest PC 0x0c067120 */
if(!s->budget--) { s->failed_pc=0x0c067120u; return 0; }
tmp=read(ram,r[14],4);
r[2]=tmp;
goto P_0c067122;
P_0c067122: /* original 88ff, guest PC 0x0c067122 */
if(!s->budget--) { s->failed_pc=0x0c067122u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xffffffffu)!=0);
goto P_0c067124;
P_0c067124: /* original d325, guest PC 0x0c067124 */
if(!s->budget--) { s->failed_pc=0x0c067124u; return 0; }
r[3]=read(ram,0x0c0671bcu,4);
goto P_0c067126;
P_0c067126: /* original 2239, guest PC 0x0c067126 */
if(!s->budget--) { s->failed_pc=0x0c067126u; return 0; }
r[2]&=r[3];
goto P_0c067128;
P_0c067128: /* original 8d36, guest PC 0x0c067128 */
if(!s->budget--) { s->failed_pc=0x0c067128u; return 0; }
cond=r[17]&1u;
write(ram,r[14],r[2],4);
if(cond) { goto P_0c067198; }
goto P_0c06712c;
P_0c06712a: /* original 2e22, guest PC 0x0c06712a */
if(!s->budget--) { s->failed_pc=0x0c06712au; return 0; }
write(ram,r[14],r[2],4);
goto P_0c06712c;
P_0c06712c: /* original 53ee, guest PC 0x0c06712c */
if(!s->budget--) { s->failed_pc=0x0c06712cu; return 0; }
r[3]=read(ram,r[14]+56,4);
goto P_0c06712e;
P_0c06712e: /* original 33d0, guest PC 0x0c06712e */
if(!s->budget--) { s->failed_pc=0x0c06712eu; return 0; }
r[17]=(r[17]&~1u)|((r[3]==r[13])!=0);
goto P_0c067130;
P_0c067130: /* original 8d02, guest PC 0x0c067130 */
if(!s->budget--) { s->failed_pc=0x0c067130u; return 0; }
cond=r[17]&1u;
r[4]=0x00000000u;
if(cond) { goto P_0c067138; }
goto P_0c067134;
P_0c067132: /* original e400, guest PC 0x0c067132 */
if(!s->budget--) { s->failed_pc=0x0c067132u; return 0; }
r[4]=0x00000000u;
goto P_0c067134;
P_0c067134: /* original 1edc, guest PC 0x0c067134 */
if(!s->budget--) { s->failed_pc=0x0c067134u; return 0; }
write(ram,r[14]+48,r[13],4);
goto P_0c067136;
P_0c067136: /* original 1e4e, guest PC 0x0c067136 */
if(!s->budget--) { s->failed_pc=0x0c067136u; return 0; }
write(ram,r[14]+56,r[4],4);
goto P_0c067138;
P_0c067138: /* original 62e2, guest PC 0x0c067138 */
if(!s->budget--) { s->failed_pc=0x0c067138u; return 0; }
tmp=read(ram,r[14],4);
r[2]=tmp;
goto P_0c06713a;
P_0c06713a: /* original e066, guest PC 0x0c06713a */
if(!s->budget--) { s->failed_pc=0x0c06713au; return 0; }
r[0]=0x00000066u;
goto P_0c06713c;
P_0c06713c: /* original d320, guest PC 0x0c06713c */
if(!s->budget--) { s->failed_pc=0x0c06713cu; return 0; }
r[3]=read(ram,0x0c0671c0u,4);
goto P_0c06713e;
P_0c06713e: /* original 2239, guest PC 0x0c06713e */
if(!s->budget--) { s->failed_pc=0x0c06713eu; return 0; }
r[2]&=r[3];
goto P_0c067140;
P_0c067140: /* original 2e22, guest PC 0x0c067140 */
if(!s->budget--) { s->failed_pc=0x0c067140u; return 0; }
write(ram,r[14],r[2],4);
goto P_0c067142;
P_0c067142: /* original 9237, guest PC 0x0c067142 */
if(!s->budget--) { s->failed_pc=0x0c067142u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0671b4u,2);
goto P_0c067144;
P_0c067144: /* original 61e2, guest PC 0x0c067144 */
if(!s->budget--) { s->failed_pc=0x0c067144u; return 0; }
tmp=read(ram,r[14],4);
r[1]=tmp;
goto P_0c067146;
P_0c067146: /* original 212b, guest PC 0x0c067146 */
if(!s->budget--) { s->failed_pc=0x0c067146u; return 0; }
r[1]|=r[2];
goto P_0c067148;
P_0c067148: /* original 2e12, guest PC 0x0c067148 */
if(!s->budget--) { s->failed_pc=0x0c067148u; return 0; }
write(ram,r[14],r[1],4);
goto P_0c06714a;
P_0c06714a: /* original 0e45, guest PC 0x0c06714a */
if(!s->budget--) { s->failed_pc=0x0c06714au; return 0; }
write(ram,r[14]+r[0],r[4],2);
goto P_0c06714c;
P_0c06714c: /* original e048, guest PC 0x0c06714c */
if(!s->budget--) { s->failed_pc=0x0c06714cu; return 0; }
r[0]=0x00000048u;
goto P_0c06714e;
P_0c06714e: /* original 0e46, guest PC 0x0c06714e */
if(!s->budget--) { s->failed_pc=0x0c06714eu; return 0; }
write(ram,r[14]+r[0],r[4],4);
goto P_0c067150;
P_0c067150: /* original 84e4, guest PC 0x0c067150 */
if(!s->budget--) { s->failed_pc=0x0c067150u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+4,1);
goto P_0c067152;
P_0c067152: /* original 2008, guest PC 0x0c067152 */
if(!s->budget--) { s->failed_pc=0x0c067152u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c067154;
P_0c067154: /* original 8b20, guest PC 0x0c067154 */
if(!s->budget--) { s->failed_pc=0x0c067154u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c067198; }
goto P_0c067156;
P_0c067156: /* original a01f, guest PC 0x0c067156 */
if(!s->budget--) { s->failed_pc=0x0c067156u; return 0; }
goto P_0c067198;
P_0c067158: /* original 0009, guest PC 0x0c067158 */
if(!s->budget--) { s->failed_pc=0x0c067158u; return 0; }
goto P_0c06715a;
P_0c06715a: /* original 60d3, guest PC 0x0c06715a */
if(!s->budget--) { s->failed_pc=0x0c06715au; return 0; }
r[0]=r[13];
goto P_0c06715c;
P_0c06715c: /* original 88ff, guest PC 0x0c06715c */
if(!s->budget--) { s->failed_pc=0x0c06715cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xffffffffu)!=0);
goto P_0c06715e;
P_0c06715e: /* original 8f01, guest PC 0x0c06715e */
if(!s->budget--) { s->failed_pc=0x0c06715eu; return 0; }
cond=r[17]&1u;
r[0]=0x00000060u;
if(!cond) { goto P_0c067164; }
goto P_0c067162;
P_0c067160: /* original e060, guest PC 0x0c067160 */
if(!s->budget--) { s->failed_pc=0x0c067160u; return 0; }
r[0]=0x00000060u;
goto P_0c067162;
P_0c067162: /* original dd18, guest PC 0x0c067162 */
if(!s->budget--) { s->failed_pc=0x0c067162u; return 0; }
r[13]=read(ram,0x0c0671c4u,4);
goto P_0c067164;
P_0c067164: /* original 0e54, guest PC 0x0c067164 */
if(!s->budget--) { s->failed_pc=0x0c067164u; return 0; }
write(ram,r[14]+r[0],r[5],1);
goto P_0c067166;
P_0c067166: /* original 66b3, guest PC 0x0c067166 */
if(!s->budget--) { s->failed_pc=0x0c067166u; return 0; }
r[6]=r[11];
goto P_0c067168;
P_0c067168: /* original 65f2, guest PC 0x0c067168 */
if(!s->budget--) { s->failed_pc=0x0c067168u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c06716a;
P_0c06716a: /* original d317, guest PC 0x0c06716a */
if(!s->budget--) { s->failed_pc=0x0c06716au; return 0; }
r[3]=read(ram,0x0c0671c8u,4);
goto P_0c06716c;
P_0c06716c: /* original f4ec, guest PC 0x0c06716c */
if(!s->budget--) { s->failed_pc=0x0c06716cu; return 0; }
vf3_matrix_move(s,4,14);
goto P_0c06716e;
P_0c06716e: /* original f6fc, guest PC 0x0c06716e */
if(!s->budget--) { s->failed_pc=0x0c06716eu; return 0; }
vf3_matrix_move(s,6,15);
goto P_0c067170;
P_0c067170: /* original 430b, guest PC 0x0c067170 */
if(!s->budget--) { s->failed_pc=0x0c067170u; return 0; }
target=r[3];
r[16]=code_base|0x0c067174u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c067174u) { target=s->pc; goto dispatch; }
goto P_0c067174;
P_0c067172: /* original 64e3, guest PC 0x0c067172 */
if(!s->budget--) { s->failed_pc=0x0c067172u; return 0; }
r[4]=r[14];
goto P_0c067174;
P_0c067174: /* original 1edc, guest PC 0x0c067174 */
if(!s->budget--) { s->failed_pc=0x0c067174u; return 0; }
write(ram,r[14]+48,r[13],4);
goto P_0c067176;
P_0c067176: /* original d215, guest PC 0x0c067176 */
if(!s->budget--) { s->failed_pc=0x0c067176u; return 0; }
r[2]=read(ram,0x0c0671ccu,4);
goto P_0c067178;
P_0c067178: /* original 1e23, guest PC 0x0c067178 */
if(!s->budget--) { s->failed_pc=0x0c067178u; return 0; }
write(ram,r[14]+12,r[2],4);
goto P_0c06717a;
P_0c06717a: /* original 84e4, guest PC 0x0c06717a */
if(!s->budget--) { s->failed_pc=0x0c06717au; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+4,1);
goto P_0c06717c;
P_0c06717c: /* original 2008, guest PC 0x0c06717c */
if(!s->budget--) { s->failed_pc=0x0c06717cu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c06717e;
P_0c06717e: /* original 8b04, guest PC 0x0c06717e */
if(!s->budget--) { s->failed_pc=0x0c06717eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06718a; }
goto P_0c067180;
P_0c067180: /* original 62e2, guest PC 0x0c067180 */
if(!s->budget--) { s->failed_pc=0x0c067180u; return 0; }
tmp=read(ram,r[14],4);
r[2]=tmp;
goto P_0c067182;
P_0c067182: /* original e3fe, guest PC 0x0c067182 */
if(!s->budget--) { s->failed_pc=0x0c067182u; return 0; }
r[3]=0xfffffffeu;
goto P_0c067184;
P_0c067184: /* original 2239, guest PC 0x0c067184 */
if(!s->budget--) { s->failed_pc=0x0c067184u; return 0; }
r[2]&=r[3];
goto P_0c067186;
P_0c067186: /* original a005, guest PC 0x0c067186 */
if(!s->budget--) { s->failed_pc=0x0c067186u; return 0; }
write(ram,r[14],r[2],4);
goto P_0c067194;
P_0c067188: /* original 2e22, guest PC 0x0c067188 */
if(!s->budget--) { s->failed_pc=0x0c067188u; return 0; }
write(ram,r[14],r[2],4);
goto P_0c06718a;
P_0c06718a: /* original d011, guest PC 0x0c06718a */
if(!s->budget--) { s->failed_pc=0x0c06718au; return 0; }
r[0]=read(ram,0x0c0671d0u,4);
goto P_0c06718c;
P_0c06718c: /* original 6402, guest PC 0x0c06718c */
if(!s->budget--) { s->failed_pc=0x0c06718cu; return 0; }
tmp=read(ram,r[0],4);
r[4]=tmp;
goto P_0c06718e;
P_0c06718e: /* original 6342, guest PC 0x0c06718e */
if(!s->budget--) { s->failed_pc=0x0c06718eu; return 0; }
tmp=read(ram,r[4],4);
r[3]=tmp;
goto P_0c067190;
P_0c067190: /* original 23cb, guest PC 0x0c067190 */
if(!s->budget--) { s->failed_pc=0x0c067190u; return 0; }
r[3]|=r[12];
goto P_0c067192;
P_0c067192: /* original 2432, guest PC 0x0c067192 */
if(!s->budget--) { s->failed_pc=0x0c067192u; return 0; }
write(ram,r[4],r[3],4);
goto P_0c067194;
P_0c067194: /* original d20f, guest PC 0x0c067194 */
if(!s->budget--) { s->failed_pc=0x0c067194u; return 0; }
r[2]=read(ram,0x0c0671d4u,4);
goto P_0c067196;
P_0c067196: /* original 22c0, guest PC 0x0c067196 */
if(!s->budget--) { s->failed_pc=0x0c067196u; return 0; }
write(ram,r[2],r[12],1);
goto P_0c067198;
P_0c067198: /* original 7f04, guest PC 0x0c067198 */
if(!s->budget--) { s->failed_pc=0x0c067198u; return 0; }
r[15]+=0x00000004u;
goto P_0c06719a;
P_0c06719a: /* original 4f26, guest PC 0x0c06719a */
if(!s->budget--) { s->failed_pc=0x0c06719au; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c06719c;
P_0c06719c: /* original fef9, guest PC 0x0c06719c */
if(!s->budget--) { s->failed_pc=0x0c06719cu; return 0; }
vf3_matrix_load(s,ram,14,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c06719e;
P_0c06719e: /* original fff9, guest PC 0x0c06719e */
if(!s->budget--) { s->failed_pc=0x0c06719eu; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0671a0;
P_0c0671a0: /* original 6bf6, guest PC 0x0c0671a0 */
if(!s->budget--) { s->failed_pc=0x0c0671a0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0671a2;
P_0c0671a2: /* original 6cf6, guest PC 0x0c0671a2 */
if(!s->budget--) { s->failed_pc=0x0c0671a2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0671a4;
P_0c0671a4: /* original 6df6, guest PC 0x0c0671a4 */
if(!s->budget--) { s->failed_pc=0x0c0671a4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0671a6;
P_0c0671a6: /* original 000b, guest PC 0x0c0671a6 */
if(!s->budget--) { s->failed_pc=0x0c0671a6u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0671a8: /* original 6ef6, guest PC 0x0c0671a8 */
if(!s->budget--) { s->failed_pc=0x0c0671a8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0671aau,s,ram);
unsupported: s->failed_pc=target; return 0;
}
