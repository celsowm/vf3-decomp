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
int vf3_away_batch28_adapter_8(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c060d14u: goto P_0c060d14;
case 0x0c060d16u: goto P_0c060d16;
case 0x0c060d18u: goto P_0c060d18;
case 0x0c060d1au: goto P_0c060d1a;
case 0x0c060d1cu: goto P_0c060d1c;
case 0x0c060d46u: goto P_0c060d46;
case 0x0c060d48u: goto P_0c060d48;
case 0x0c060d4au: goto P_0c060d4a;
case 0x0c062e60u: goto P_0c062e60;
case 0x0c062e62u: goto P_0c062e62;
case 0x0c062e64u: goto P_0c062e64;
case 0x0c062e66u: goto P_0c062e66;
case 0x0c062e68u: goto P_0c062e68;
case 0x0c062e6au: goto P_0c062e6a;
case 0x0c062e6cu: goto P_0c062e6c;
case 0x0c062e6eu: goto P_0c062e6e;
case 0x0c062e70u: goto P_0c062e70;
case 0x0c062e72u: goto P_0c062e72;
case 0x0c062e74u: goto P_0c062e74;
case 0x0c062e76u: goto P_0c062e76;
case 0x0c062e78u: goto P_0c062e78;
case 0x0c062e7au: goto P_0c062e7a;
case 0x0c062e7cu: goto P_0c062e7c;
case 0x0c062e7eu: goto P_0c062e7e;
case 0x0c062e80u: goto P_0c062e80;
case 0x0c062e82u: goto P_0c062e82;
case 0x0c062e84u: goto P_0c062e84;
case 0x0c062e86u: goto P_0c062e86;
case 0x0c062e88u: goto P_0c062e88;
case 0x0c062e8au: goto P_0c062e8a;
case 0x0c062e8cu: goto P_0c062e8c;
case 0x0c06629cu: goto P_0c06629c;
case 0x0c06629eu: goto P_0c06629e;
case 0x0c0662a0u: goto P_0c0662a0;
case 0x0c0662a2u: goto P_0c0662a2;
case 0x0c0662a4u: goto P_0c0662a4;
case 0x0c0662a6u: goto P_0c0662a6;
case 0x0c0662a8u: goto P_0c0662a8;
case 0x0c0662aau: goto P_0c0662aa;
case 0x0c0662acu: goto P_0c0662ac;
case 0x0c0662aeu: goto P_0c0662ae;
case 0x0c0662b0u: goto P_0c0662b0;
case 0x0c0662b2u: goto P_0c0662b2;
case 0x0c0662b4u: goto P_0c0662b4;
case 0x0c0662b6u: goto P_0c0662b6;
case 0x0c0662b8u: goto P_0c0662b8;
case 0x0c0662bau: goto P_0c0662ba;
case 0x0c0662bcu: goto P_0c0662bc;
case 0x0c0662beu: goto P_0c0662be;
case 0x0c0662c0u: goto P_0c0662c0;
case 0x0c0662c2u: goto P_0c0662c2;
case 0x0c0662c4u: goto P_0c0662c4;
case 0x0c0662c6u: goto P_0c0662c6;
case 0x0c0662c8u: goto P_0c0662c8;
case 0x0c0662cau: goto P_0c0662ca;
case 0x0c0662ccu: goto P_0c0662cc;
case 0x0c0662ceu: goto P_0c0662ce;
case 0x0c0662d0u: goto P_0c0662d0;
case 0x0c0662d2u: goto P_0c0662d2;
case 0x0c0662d4u: goto P_0c0662d4;
case 0x0c0662d6u: goto P_0c0662d6;
case 0x0c0662d8u: goto P_0c0662d8;
case 0x0c0662dau: goto P_0c0662da;
case 0x0c0662dcu: goto P_0c0662dc;
case 0x0c0662deu: goto P_0c0662de;
case 0x0c0662e0u: goto P_0c0662e0;
case 0x0c0662e2u: goto P_0c0662e2;
case 0x0c0662e4u: goto P_0c0662e4;
case 0x0c0662e6u: goto P_0c0662e6;
case 0x0c0662e8u: goto P_0c0662e8;
case 0x0c0662eau: goto P_0c0662ea;
case 0x0c0662ecu: goto P_0c0662ec;
case 0x0c0662eeu: goto P_0c0662ee;
case 0x0c0662f0u: goto P_0c0662f0;
case 0x0c0662f2u: goto P_0c0662f2;
case 0x0c0662f4u: goto P_0c0662f4;
case 0x0c0662f6u: goto P_0c0662f6;
case 0x0c0662f8u: goto P_0c0662f8;
case 0x0c0662fau: goto P_0c0662fa;
case 0x0c0662fcu: goto P_0c0662fc;
case 0x0c0662feu: goto P_0c0662fe;
case 0x0c066300u: goto P_0c066300;
case 0x0c066302u: goto P_0c066302;
case 0x0c066304u: goto P_0c066304;
case 0x0c066306u: goto P_0c066306;
case 0x0c066308u: goto P_0c066308;
case 0x0c06630au: goto P_0c06630a;
case 0x0c06630cu: goto P_0c06630c;
case 0x0c06630eu: goto P_0c06630e;
case 0x0c066310u: goto P_0c066310;
case 0x0c066312u: goto P_0c066312;
case 0x0c066314u: goto P_0c066314;
case 0x0c066316u: goto P_0c066316;
case 0x0c066318u: goto P_0c066318;
case 0x0c06631au: goto P_0c06631a;
case 0x0c06631cu: goto P_0c06631c;
case 0x0c06631eu: goto P_0c06631e;
case 0x0c066320u: goto P_0c066320;
case 0x0c066322u: goto P_0c066322;
case 0x0c066324u: goto P_0c066324;
case 0x0c066326u: goto P_0c066326;
case 0x0c066328u: goto P_0c066328;
case 0x0c06632au: goto P_0c06632a;
case 0x0c06632cu: goto P_0c06632c;
case 0x0c06632eu: goto P_0c06632e;
case 0x0c066330u: goto P_0c066330;
case 0x0c066332u: goto P_0c066332;
case 0x0c066334u: goto P_0c066334;
case 0x0c066336u: goto P_0c066336;
case 0x0c066338u: goto P_0c066338;
case 0x0c06633au: goto P_0c06633a;
case 0x0c06633cu: goto P_0c06633c;
case 0x0c06633eu: goto P_0c06633e;
case 0x0c066340u: goto P_0c066340;
case 0x0c066342u: goto P_0c066342;
case 0x0c066344u: goto P_0c066344;
case 0x0c066346u: goto P_0c066346;
case 0x0c066348u: goto P_0c066348;
case 0x0c06634au: goto P_0c06634a;
case 0x0c06634cu: goto P_0c06634c;
case 0x0c06634eu: goto P_0c06634e;
case 0x0c066350u: goto P_0c066350;
case 0x0c066352u: goto P_0c066352;
case 0x0c066354u: goto P_0c066354;
case 0x0c066356u: goto P_0c066356;
case 0x0c066358u: goto P_0c066358;
case 0x0c06635au: goto P_0c06635a;
case 0x0c06635cu: goto P_0c06635c;
case 0x0c06635eu: goto P_0c06635e;
case 0x0c066360u: goto P_0c066360;
case 0x0c066362u: goto P_0c066362;
case 0x0c066364u: goto P_0c066364;
case 0x0c066366u: goto P_0c066366;
case 0x0c066368u: goto P_0c066368;
case 0x0c06636au: goto P_0c06636a;
case 0x0c06636cu: goto P_0c06636c;
case 0x0c06636eu: goto P_0c06636e;
case 0x0c066370u: goto P_0c066370;
case 0x0c066372u: goto P_0c066372;
case 0x0c066374u: goto P_0c066374;
case 0x0c066376u: goto P_0c066376;
case 0x0c066378u: goto P_0c066378;
case 0x0c06637au: goto P_0c06637a;
case 0x0c06637cu: goto P_0c06637c;
case 0x0c06637eu: goto P_0c06637e;
case 0x0c066380u: goto P_0c066380;
case 0x0c066382u: goto P_0c066382;
case 0x0c066384u: goto P_0c066384;
case 0x0c066386u: goto P_0c066386;
case 0x0c066388u: goto P_0c066388;
case 0x0c06638au: goto P_0c06638a;
case 0x0c06638cu: goto P_0c06638c;
case 0x0c06638eu: goto P_0c06638e;
case 0x0c066390u: goto P_0c066390;
case 0x0c0663d8u: goto P_0c0663d8;
case 0x0c0663dau: goto P_0c0663da;
case 0x0c0663dcu: goto P_0c0663dc;
case 0x0c0663deu: goto P_0c0663de;
case 0x0c0663e0u: goto P_0c0663e0;
case 0x0c0663e2u: goto P_0c0663e2;
case 0x0c0663e4u: goto P_0c0663e4;
case 0x0c0663e6u: goto P_0c0663e6;
case 0x0c0663e8u: goto P_0c0663e8;
case 0x0c0663eau: goto P_0c0663ea;
case 0x0c0663ecu: goto P_0c0663ec;
case 0x0c0663eeu: goto P_0c0663ee;
case 0x0c0663f0u: goto P_0c0663f0;
case 0x0c0663f2u: goto P_0c0663f2;
case 0x0c0663f4u: goto P_0c0663f4;
case 0x0c0663f6u: goto P_0c0663f6;
case 0x0c0663f8u: goto P_0c0663f8;
case 0x0c0663fau: goto P_0c0663fa;
case 0x0c0663fcu: goto P_0c0663fc;
case 0x0c0663feu: goto P_0c0663fe;
case 0x0c066400u: goto P_0c066400;
case 0x0c066402u: goto P_0c066402;
case 0x0c066404u: goto P_0c066404;
case 0x0c066406u: goto P_0c066406;
case 0x0c066408u: goto P_0c066408;
case 0x0c06640au: goto P_0c06640a;
case 0x0c06640cu: goto P_0c06640c;
case 0x0c06640eu: goto P_0c06640e;
case 0x0c066410u: goto P_0c066410;
case 0x0c066412u: goto P_0c066412;
case 0x0c066414u: goto P_0c066414;
case 0x0c066416u: goto P_0c066416;
case 0x0c066418u: goto P_0c066418;
case 0x0c06641au: goto P_0c06641a;
case 0x0c06641cu: goto P_0c06641c;
case 0x0c06641eu: goto P_0c06641e;
case 0x0c066420u: goto P_0c066420;
case 0x0c066422u: goto P_0c066422;
case 0x0c066424u: goto P_0c066424;
case 0x0c066426u: goto P_0c066426;
case 0x0c066428u: goto P_0c066428;
case 0x0c06642au: goto P_0c06642a;
case 0x0c06642cu: goto P_0c06642c;
case 0x0c06642eu: goto P_0c06642e;
case 0x0c066430u: goto P_0c066430;
case 0x0c066432u: goto P_0c066432;
case 0x0c066434u: goto P_0c066434;
case 0x0c066436u: goto P_0c066436;
case 0x0c066438u: goto P_0c066438;
case 0x0c06643au: goto P_0c06643a;
case 0x0c06643cu: goto P_0c06643c;
default: return vf3_matrix_family(target,s,ram);
}
P_0c060d14: /* original d344, guest PC 0x0c060d14 */
if(!s->budget--) { s->failed_pc=0x0c060d14u; return 0; }
r[3]=read(ram,0x0c060e28u,4);
goto P_0c060d16;
P_0c060d16: /* original 343c, guest PC 0x0c060d16 */
if(!s->budget--) { s->failed_pc=0x0c060d16u; return 0; }
r[4]+=r[3];
goto P_0c060d18;
P_0c060d18: /* original 2452, guest PC 0x0c060d18 */
if(!s->budget--) { s->failed_pc=0x0c060d18u; return 0; }
write(ram,r[4],r[5],4);
goto P_0c060d1a;
P_0c060d1a: /* original 000b, guest PC 0x0c060d1a */
if(!s->budget--) { s->failed_pc=0x0c060d1au; return 0; }
target=r[16];
r[0]=0x00000001u;
s->pc=target; return ram->oob==0;
P_0c060d1c: /* original e001, guest PC 0x0c060d1c */
if(!s->budget--) { s->failed_pc=0x0c060d1cu; return 0; }
r[0]=0x00000001u;
if(!vf3_matrix_family(0x0c060d1eu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c060d1eu; return 0; } return 1;
P_0c060d46: /* original d038, guest PC 0x0c060d46 */
if(!s->budget--) { s->failed_pc=0x0c060d46u; return 0; }
r[0]=read(ram,0x0c060e28u,4);
goto P_0c060d48;
P_0c060d48: /* original 000b, guest PC 0x0c060d48 */
if(!s->budget--) { s->failed_pc=0x0c060d48u; return 0; }
target=r[16];
r[0]=read(ram,r[4]+r[0],4);
s->pc=target; return ram->oob==0;
P_0c060d4a: /* original 004e, guest PC 0x0c060d4a */
if(!s->budget--) { s->failed_pc=0x0c060d4au; return 0; }
r[0]=read(ram,r[4]+r[0],4);
if(!vf3_matrix_family(0x0c060d4cu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c060d4cu; return 0; } return 1;
P_0c062e60: /* original 6043, guest PC 0x0c062e60 */
if(!s->budget--) { s->failed_pc=0x0c062e60u; return 0; }
r[0]=r[4];
goto P_0c062e62;
P_0c062e62: /* original 205b, guest PC 0x0c062e62 */
if(!s->budget--) { s->failed_pc=0x0c062e62u; return 0; }
r[0]|=r[5];
goto P_0c062e64;
P_0c062e64: /* original 206b, guest PC 0x0c062e64 */
if(!s->budget--) { s->failed_pc=0x0c062e64u; return 0; }
r[0]|=r[6];
goto P_0c062e66;
P_0c062e66: /* original c807, guest PC 0x0c062e66 */
if(!s->budget--) { s->failed_pc=0x0c062e66u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&7u)==0)!=0);
goto P_0c062e68;
P_0c062e68: /* original 8b09, guest PC 0x0c062e68 */
if(!s->budget--) { s->failed_pc=0x0c062e68u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c062e7e; }
goto P_0c062e6a;
P_0c062e6a: /* original f3fd, guest PC 0x0c062e6a */
if(!s->budget--) { s->failed_pc=0x0c062e6au; return 0; }
r[18]^=0x100000u;
goto P_0c062e6c;
P_0c062e6c: /* original 4609, guest PC 0x0c062e6c */
if(!s->budget--) { s->failed_pc=0x0c062e6cu; return 0; }
r[6]>>=2;
goto P_0c062e6e;
P_0c062e6e: /* original 4601, guest PC 0x0c062e6e */
if(!s->budget--) { s->failed_pc=0x0c062e6eu; return 0; }
r[17]=(r[17]&~1u)|((r[6]&1)!=0);
r[6]>>=1;
goto P_0c062e70;
P_0c062e70: /* original f059, guest PC 0x0c062e70 */
if(!s->budget--) { s->failed_pc=0x0c062e70u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c062e72;
P_0c062e72: /* original 4610, guest PC 0x0c062e72 */
if(!s->budget--) { s->failed_pc=0x0c062e72u; return 0; }
--r[6];
r[17]=(r[17]&~1u)|((r[6]==0)!=0);
goto P_0c062e74;
P_0c062e74: /* original f40a, guest PC 0x0c062e74 */
if(!s->budget--) { s->failed_pc=0x0c062e74u; return 0; }
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c062e76;
P_0c062e76: /* original 8ffb, guest PC 0x0c062e76 */
if(!s->budget--) { s->failed_pc=0x0c062e76u; return 0; }
cond=r[17]&1u;
r[4]+=0x00000008u;
if(!cond) { goto P_0c062e70; }
goto P_0c062e7a;
P_0c062e78: /* original 7408, guest PC 0x0c062e78 */
if(!s->budget--) { s->failed_pc=0x0c062e78u; return 0; }
r[4]+=0x00000008u;
goto P_0c062e7a;
P_0c062e7a: /* original 000b, guest PC 0x0c062e7a */
if(!s->budget--) { s->failed_pc=0x0c062e7au; return 0; }
target=r[16];
r[18]^=0x100000u;
s->pc=target; return ram->oob==0;
P_0c062e7c: /* original f3fd, guest PC 0x0c062e7c */
if(!s->budget--) { s->failed_pc=0x0c062e7cu; return 0; }
r[18]^=0x100000u;
goto P_0c062e7e;
P_0c062e7e: /* original 4609, guest PC 0x0c062e7e */
if(!s->budget--) { s->failed_pc=0x0c062e7eu; return 0; }
r[6]>>=2;
goto P_0c062e80;
P_0c062e80: /* original 6056, guest PC 0x0c062e80 */
if(!s->budget--) { s->failed_pc=0x0c062e80u; return 0; }
tmp=read(ram,r[5],4);
r[5]+=4;
r[0]=tmp;
goto P_0c062e82;
P_0c062e82: /* original 4610, guest PC 0x0c062e82 */
if(!s->budget--) { s->failed_pc=0x0c062e82u; return 0; }
--r[6];
r[17]=(r[17]&~1u)|((r[6]==0)!=0);
goto P_0c062e84;
P_0c062e84: /* original 2402, guest PC 0x0c062e84 */
if(!s->budget--) { s->failed_pc=0x0c062e84u; return 0; }
write(ram,r[4],r[0],4);
goto P_0c062e86;
P_0c062e86: /* original 8ffb, guest PC 0x0c062e86 */
if(!s->budget--) { s->failed_pc=0x0c062e86u; return 0; }
cond=r[17]&1u;
r[4]+=0x00000004u;
if(!cond) { goto P_0c062e80; }
goto P_0c062e8a;
P_0c062e88: /* original 7404, guest PC 0x0c062e88 */
if(!s->budget--) { s->failed_pc=0x0c062e88u; return 0; }
r[4]+=0x00000004u;
goto P_0c062e8a;
P_0c062e8a: /* original 000b, guest PC 0x0c062e8a */
if(!s->budget--) { s->failed_pc=0x0c062e8au; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c062e8c: /* original 0009, guest PC 0x0c062e8c */
if(!s->budget--) { s->failed_pc=0x0c062e8cu; return 0; }
if(!vf3_matrix_family(0x0c062e8eu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c062e8eu; return 0; } return 1;
P_0c06629c: /* original d540, guest PC 0x0c06629c */
if(!s->budget--) { s->failed_pc=0x0c06629cu; return 0; }
r[5]=read(ram,0x0c0663a0u,4);
goto P_0c06629e;
P_0c06629e: /* original d341, guest PC 0x0c06629e */
if(!s->budget--) { s->failed_pc=0x0c06629eu; return 0; }
r[3]=read(ram,0x0c0663a4u,4);
goto P_0c0662a0;
P_0c0662a0: /* original 6032, guest PC 0x0c0662a0 */
if(!s->budget--) { s->failed_pc=0x0c0662a0u; return 0; }
tmp=read(ram,r[3],4);
r[0]=tmp;
goto P_0c0662a2;
P_0c0662a2: /* original 4008, guest PC 0x0c0662a2 */
if(!s->budget--) { s->failed_pc=0x0c0662a2u; return 0; }
r[0]<<=2;
goto P_0c0662a4;
P_0c0662a4: /* original 025e, guest PC 0x0c0662a4 */
if(!s->budget--) { s->failed_pc=0x0c0662a4u; return 0; }
r[2]=read(ram,r[5]+r[0],4);
goto P_0c0662a6;
P_0c0662a6: /* original d140, guest PC 0x0c0662a6 */
if(!s->budget--) { s->failed_pc=0x0c0662a6u; return 0; }
r[1]=read(ram,0x0c0663a8u,4);
goto P_0c0662a8;
P_0c0662a8: /* original 6012, guest PC 0x0c0662a8 */
if(!s->budget--) { s->failed_pc=0x0c0662a8u; return 0; }
tmp=read(ram,r[1],4);
r[0]=tmp;
goto P_0c0662aa;
P_0c0662aa: /* original 4008, guest PC 0x0c0662aa */
if(!s->budget--) { s->failed_pc=0x0c0662aau; return 0; }
r[0]<<=2;
goto P_0c0662ac;
P_0c0662ac: /* original 005e, guest PC 0x0c0662ac */
if(!s->budget--) { s->failed_pc=0x0c0662acu; return 0; }
r[0]=read(ram,r[5]+r[0],4);
goto P_0c0662ae;
P_0c0662ae: /* original 7308, guest PC 0x0c0662ae */
if(!s->budget--) { s->failed_pc=0x0c0662aeu; return 0; }
r[3]+=0x00000008u;
goto P_0c0662b0;
P_0c0662b0: /* original 320c, guest PC 0x0c0662b0 */
if(!s->budget--) { s->failed_pc=0x0c0662b0u; return 0; }
r[2]+=r[0];
goto P_0c0662b2;
P_0c0662b2: /* original 6032, guest PC 0x0c0662b2 */
if(!s->budget--) { s->failed_pc=0x0c0662b2u; return 0; }
tmp=read(ram,r[3],4);
r[0]=tmp;
goto P_0c0662b4;
P_0c0662b4: /* original 4008, guest PC 0x0c0662b4 */
if(!s->budget--) { s->failed_pc=0x0c0662b4u; return 0; }
r[0]<<=2;
goto P_0c0662b6;
P_0c0662b6: /* original 7304, guest PC 0x0c0662b6 */
if(!s->budget--) { s->failed_pc=0x0c0662b6u; return 0; }
r[3]+=0x00000004u;
goto P_0c0662b8;
P_0c0662b8: /* original 005e, guest PC 0x0c0662b8 */
if(!s->budget--) { s->failed_pc=0x0c0662b8u; return 0; }
r[0]=read(ram,r[5]+r[0],4);
goto P_0c0662ba;
P_0c0662ba: /* original 320c, guest PC 0x0c0662ba */
if(!s->budget--) { s->failed_pc=0x0c0662bau; return 0; }
r[2]+=r[0];
goto P_0c0662bc;
P_0c0662bc: /* original 6032, guest PC 0x0c0662bc */
if(!s->budget--) { s->failed_pc=0x0c0662bcu; return 0; }
tmp=read(ram,r[3],4);
r[0]=tmp;
goto P_0c0662be;
P_0c0662be: /* original 4008, guest PC 0x0c0662be */
if(!s->budget--) { s->failed_pc=0x0c0662beu; return 0; }
r[0]<<=2;
goto P_0c0662c0;
P_0c0662c0: /* original 005e, guest PC 0x0c0662c0 */
if(!s->budget--) { s->failed_pc=0x0c0662c0u; return 0; }
r[0]=read(ram,r[5]+r[0],4);
goto P_0c0662c2;
P_0c0662c2: /* original 320c, guest PC 0x0c0662c2 */
if(!s->budget--) { s->failed_pc=0x0c0662c2u; return 0; }
r[2]+=r[0];
goto P_0c0662c4;
P_0c0662c4: /* original 5031, guest PC 0x0c0662c4 */
if(!s->budget--) { s->failed_pc=0x0c0662c4u; return 0; }
r[0]=read(ram,r[3]+4,4);
goto P_0c0662c6;
P_0c0662c6: /* original 4008, guest PC 0x0c0662c6 */
if(!s->budget--) { s->failed_pc=0x0c0662c6u; return 0; }
r[0]<<=2;
goto P_0c0662c8;
P_0c0662c8: /* original 005e, guest PC 0x0c0662c8 */
if(!s->budget--) { s->failed_pc=0x0c0662c8u; return 0; }
r[0]=read(ram,r[5]+r[0],4);
goto P_0c0662ca;
P_0c0662ca: /* original 320c, guest PC 0x0c0662ca */
if(!s->budget--) { s->failed_pc=0x0c0662cau; return 0; }
r[2]+=r[0];
goto P_0c0662cc;
P_0c0662cc: /* original 0247, guest PC 0x0c0662cc */
if(!s->budget--) { s->failed_pc=0x0c0662ccu; return 0; }
r[19]=r[2]*r[4];
goto P_0c0662ce;
P_0c0662ce: /* original 021a, guest PC 0x0c0662ce */
if(!s->budget--) { s->failed_pc=0x0c0662ceu; return 0; }
r[2]=r[19];
goto P_0c0662d0;
P_0c0662d0: /* original 6423, guest PC 0x0c0662d0 */
if(!s->budget--) { s->failed_pc=0x0c0662d0u; return 0; }
r[4]=r[2];
goto P_0c0662d2;
P_0c0662d2: /* original 4408, guest PC 0x0c0662d2 */
if(!s->budget--) { s->failed_pc=0x0c0662d2u; return 0; }
r[4]<<=2;
goto P_0c0662d4;
P_0c0662d4: /* original 000b, guest PC 0x0c0662d4 */
if(!s->budget--) { s->failed_pc=0x0c0662d4u; return 0; }
target=r[16];
r[0]=r[4];
s->pc=target; return ram->oob==0;
P_0c0662d6: /* original 6043, guest PC 0x0c0662d6 */
if(!s->budget--) { s->failed_pc=0x0c0662d6u; return 0; }
r[0]=r[4];
goto P_0c0662d8;
P_0c0662d8: /* original 2fe6, guest PC 0x0c0662d8 */
if(!s->budget--) { s->failed_pc=0x0c0662d8u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0662da;
P_0c0662da: /* original 2fd6, guest PC 0x0c0662da */
if(!s->budget--) { s->failed_pc=0x0c0662dau; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0662dc;
P_0c0662dc: /* original 4f22, guest PC 0x0c0662dc */
if(!s->budget--) { s->failed_pc=0x0c0662dcu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0662de;
P_0c0662de: /* original 6d63, guest PC 0x0c0662de */
if(!s->budget--) { s->failed_pc=0x0c0662deu; return 0; }
r[13]=r[6];
goto P_0c0662e0;
P_0c0662e0: /* original d033, guest PC 0x0c0662e0 */
if(!s->budget--) { s->failed_pc=0x0c0662e0u; return 0; }
r[0]=read(ram,0x0c0663b0u,4);
goto P_0c0662e2;
P_0c0662e2: /* original 7ff4, guest PC 0x0c0662e2 */
if(!s->budget--) { s->failed_pc=0x0c0662e2u; return 0; }
r[15]+=0xfffffff4u;
goto P_0c0662e4;
P_0c0662e4: /* original de31, guest PC 0x0c0662e4 */
if(!s->budget--) { s->failed_pc=0x0c0662e4u; return 0; }
r[14]=read(ram,0x0c0663acu,4);
goto P_0c0662e6;
P_0c0662e6: /* original 4d08, guest PC 0x0c0662e6 */
if(!s->budget--) { s->failed_pc=0x0c0662e6u; return 0; }
r[13]<<=2;
goto P_0c0662e8;
P_0c0662e8: /* original 2f42, guest PC 0x0c0662e8 */
if(!s->budget--) { s->failed_pc=0x0c0662e8u; return 0; }
write(ram,r[15],r[4],4);
goto P_0c0662ea;
P_0c0662ea: /* original 4d08, guest PC 0x0c0662ea */
if(!s->budget--) { s->failed_pc=0x0c0662eau; return 0; }
r[13]<<=2;
goto P_0c0662ec;
P_0c0662ec: /* original 1f51, guest PC 0x0c0662ec */
if(!s->budget--) { s->failed_pc=0x0c0662ecu; return 0; }
write(ram,r[15]+4,r[5],4);
goto P_0c0662ee;
P_0c0662ee: /* original 4d00, guest PC 0x0c0662ee */
if(!s->budget--) { s->failed_pc=0x0c0662eeu; return 0; }
r[17]=(r[17]&~1u)|((r[13]>>31)!=0);
r[13]<<=1;
goto P_0c0662f0;
P_0c0662f0: /* original 944f, guest PC 0x0c0662f0 */
if(!s->budget--) { s->failed_pc=0x0c0662f0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c066392u,2);
goto P_0c0662f2;
P_0c0662f2: /* original 1f62, guest PC 0x0c0662f2 */
if(!s->budget--) { s->failed_pc=0x0c0662f2u; return 0; }
write(ram,r[15]+8,r[6],4);
goto P_0c0662f4;
P_0c0662f4: /* original 4e0b, guest PC 0x0c0662f4 */
if(!s->budget--) { s->failed_pc=0x0c0662f4u; return 0; }
target=r[14];
r[16]=code_base|0x0c0662f8u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0662f8u) { target=s->pc; goto dispatch; }
goto P_0c0662f8;
P_0c0662f6: /* original 05de, guest PC 0x0c0662f6 */
if(!s->budget--) { s->failed_pc=0x0c0662f6u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0662f8;
P_0c0662f8: /* original d02e, guest PC 0x0c0662f8 */
if(!s->budget--) { s->failed_pc=0x0c0662f8u; return 0; }
r[0]=read(ram,0x0c0663b4u,4);
goto P_0c0662fa;
P_0c0662fa: /* original 944b, guest PC 0x0c0662fa */
if(!s->budget--) { s->failed_pc=0x0c0662fau; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c066394u,2);
goto P_0c0662fc;
P_0c0662fc: /* original 4e0b, guest PC 0x0c0662fc */
if(!s->budget--) { s->failed_pc=0x0c0662fcu; return 0; }
target=r[14];
r[16]=code_base|0x0c066300u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c066300u) { target=s->pc; goto dispatch; }
goto P_0c066300;
P_0c0662fe: /* original 05de, guest PC 0x0c0662fe */
if(!s->budget--) { s->failed_pc=0x0c0662feu; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c066300;
P_0c066300: /* original d02d, guest PC 0x0c066300 */
if(!s->budget--) { s->failed_pc=0x0c066300u; return 0; }
r[0]=read(ram,0x0c0663b8u,4);
goto P_0c066302;
P_0c066302: /* original 9448, guest PC 0x0c066302 */
if(!s->budget--) { s->failed_pc=0x0c066302u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c066396u,2);
goto P_0c066304;
P_0c066304: /* original 4e0b, guest PC 0x0c066304 */
if(!s->budget--) { s->failed_pc=0x0c066304u; return 0; }
target=r[14];
r[16]=code_base|0x0c066308u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c066308u) { target=s->pc; goto dispatch; }
goto P_0c066308;
P_0c066306: /* original 05de, guest PC 0x0c066306 */
if(!s->budget--) { s->failed_pc=0x0c066306u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c066308;
P_0c066308: /* original d02c, guest PC 0x0c066308 */
if(!s->budget--) { s->failed_pc=0x0c066308u; return 0; }
r[0]=read(ram,0x0c0663bcu,4);
goto P_0c06630a;
P_0c06630a: /* original 9445, guest PC 0x0c06630a */
if(!s->budget--) { s->failed_pc=0x0c06630au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c066398u,2);
goto P_0c06630c;
P_0c06630c: /* original 4e0b, guest PC 0x0c06630c */
if(!s->budget--) { s->failed_pc=0x0c06630cu; return 0; }
target=r[14];
r[16]=code_base|0x0c066310u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c066310u) { target=s->pc; goto dispatch; }
goto P_0c066310;
P_0c06630e: /* original 05de, guest PC 0x0c06630e */
if(!s->budget--) { s->failed_pc=0x0c06630eu; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c066310;
P_0c066310: /* original 55f1, guest PC 0x0c066310 */
if(!s->budget--) { s->failed_pc=0x0c066310u; return 0; }
r[5]=read(ram,r[15]+4,4);
goto P_0c066312;
P_0c066312: /* original 75ff, guest PC 0x0c066312 */
if(!s->budget--) { s->failed_pc=0x0c066312u; return 0; }
r[5]+=0xffffffffu;
goto P_0c066314;
P_0c066314: /* original 63f2, guest PC 0x0c066314 */
if(!s->budget--) { s->failed_pc=0x0c066314u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c066316;
P_0c066316: /* original 4528, guest PC 0x0c066316 */
if(!s->budget--) { s->failed_pc=0x0c066316u; return 0; }
r[5]<<=16;
goto P_0c066318;
P_0c066318: /* original 943f, guest PC 0x0c066318 */
if(!s->budget--) { s->failed_pc=0x0c066318u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06639au,2);
goto P_0c06631a;
P_0c06631a: /* original 353c, guest PC 0x0c06631a */
if(!s->budget--) { s->failed_pc=0x0c06631au; return 0; }
r[5]+=r[3];
goto P_0c06631c;
P_0c06631c: /* original 4e0b, guest PC 0x0c06631c */
if(!s->budget--) { s->failed_pc=0x0c06631cu; return 0; }
target=r[14];
r[16]=code_base|0x0c066320u;
r[5]+=0xffffffffu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c066320u) { target=s->pc; goto dispatch; }
goto P_0c066320;
P_0c06631e: /* original 75ff, guest PC 0x0c06631e */
if(!s->budget--) { s->failed_pc=0x0c06631eu; return 0; }
r[5]+=0xffffffffu;
goto P_0c066320;
P_0c066320: /* original d320, guest PC 0x0c066320 */
if(!s->budget--) { s->failed_pc=0x0c066320u; return 0; }
r[3]=read(ram,0x0c0663a4u,4);
goto P_0c066322;
P_0c066322: /* original e403, guest PC 0x0c066322 */
if(!s->budget--) { s->failed_pc=0x0c066322u; return 0; }
r[4]=0x00000003u;
goto P_0c066324;
P_0c066324: /* original 6532, guest PC 0x0c066324 */
if(!s->budget--) { s->failed_pc=0x0c066324u; return 0; }
tmp=read(ram,r[3],4);
r[5]=tmp;
goto P_0c066326;
P_0c066326: /* original 2549, guest PC 0x0c066326 */
if(!s->budget--) { s->failed_pc=0x0c066326u; return 0; }
r[5]&=r[4];
goto P_0c066328;
P_0c066328: /* original d11f, guest PC 0x0c066328 */
if(!s->budget--) { s->failed_pc=0x0c066328u; return 0; }
r[1]=read(ram,0x0c0663a8u,4);
goto P_0c06632a;
P_0c06632a: /* original 6212, guest PC 0x0c06632a */
if(!s->budget--) { s->failed_pc=0x0c06632au; return 0; }
tmp=read(ram,r[1],4);
r[2]=tmp;
goto P_0c06632c;
P_0c06632c: /* original 2249, guest PC 0x0c06632c */
if(!s->budget--) { s->failed_pc=0x0c06632cu; return 0; }
r[2]&=r[4];
goto P_0c06632e;
P_0c06632e: /* original 4208, guest PC 0x0c06632e */
if(!s->budget--) { s->failed_pc=0x0c06632eu; return 0; }
r[2]<<=2;
goto P_0c066330;
P_0c066330: /* original d023, guest PC 0x0c066330 */
if(!s->budget--) { s->failed_pc=0x0c066330u; return 0; }
r[0]=read(ram,0x0c0663c0u,4);
goto P_0c066332;
P_0c066332: /* original 4208, guest PC 0x0c066332 */
if(!s->budget--) { s->failed_pc=0x0c066332u; return 0; }
r[2]<<=2;
goto P_0c066334;
P_0c066334: /* original 252b, guest PC 0x0c066334 */
if(!s->budget--) { s->failed_pc=0x0c066334u; return 0; }
r[5]|=r[2];
goto P_0c066336;
P_0c066336: /* original 6202, guest PC 0x0c066336 */
if(!s->budget--) { s->failed_pc=0x0c066336u; return 0; }
tmp=read(ram,r[0],4);
r[2]=tmp;
goto P_0c066338;
P_0c066338: /* original 2249, guest PC 0x0c066338 */
if(!s->budget--) { s->failed_pc=0x0c066338u; return 0; }
r[2]&=r[4];
goto P_0c06633a;
P_0c06633a: /* original 4218, guest PC 0x0c06633a */
if(!s->budget--) { s->failed_pc=0x0c06633au; return 0; }
r[2]<<=8;
goto P_0c06633c;
P_0c06633c: /* original 252b, guest PC 0x0c06633c */
if(!s->budget--) { s->failed_pc=0x0c06633cu; return 0; }
r[5]|=r[2];
goto P_0c06633e;
P_0c06633e: /* original d221, guest PC 0x0c06633e */
if(!s->budget--) { s->failed_pc=0x0c06633eu; return 0; }
r[2]=read(ram,0x0c0663c4u,4);
goto P_0c066340;
P_0c066340: /* original 6322, guest PC 0x0c066340 */
if(!s->budget--) { s->failed_pc=0x0c066340u; return 0; }
tmp=read(ram,r[2],4);
r[3]=tmp;
goto P_0c066342;
P_0c066342: /* original 2349, guest PC 0x0c066342 */
if(!s->budget--) { s->failed_pc=0x0c066342u; return 0; }
r[3]&=r[4];
goto P_0c066344;
P_0c066344: /* original 4318, guest PC 0x0c066344 */
if(!s->budget--) { s->failed_pc=0x0c066344u; return 0; }
r[3]<<=8;
goto P_0c066346;
P_0c066346: /* original 4308, guest PC 0x0c066346 */
if(!s->budget--) { s->failed_pc=0x0c066346u; return 0; }
r[3]<<=2;
goto P_0c066348;
P_0c066348: /* original 4308, guest PC 0x0c066348 */
if(!s->budget--) { s->failed_pc=0x0c066348u; return 0; }
r[3]<<=2;
goto P_0c06634a;
P_0c06634a: /* original 253b, guest PC 0x0c06634a */
if(!s->budget--) { s->failed_pc=0x0c06634au; return 0; }
r[5]|=r[3];
goto P_0c06634c;
P_0c06634c: /* original d31e, guest PC 0x0c06634c */
if(!s->budget--) { s->failed_pc=0x0c06634cu; return 0; }
r[3]=read(ram,0x0c0663c8u,4);
goto P_0c06634e;
P_0c06634e: /* original 6032, guest PC 0x0c06634e */
if(!s->budget--) { s->failed_pc=0x0c06634eu; return 0; }
tmp=read(ram,r[3],4);
r[0]=tmp;
goto P_0c066350;
P_0c066350: /* original 8806, guest PC 0x0c066350 */
if(!s->budget--) { s->failed_pc=0x0c066350u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000006u)!=0);
goto P_0c066352;
P_0c066352: /* original 8f0d, guest PC 0x0c066352 */
if(!s->budget--) { s->failed_pc=0x0c066352u; return 0; }
cond=r[17]&1u;
r[6]=0x00000001u;
if(!cond) { goto P_0c066370; }
goto P_0c066356;
P_0c066354: /* original e601, guest PC 0x0c066354 */
if(!s->budget--) { s->failed_pc=0x0c066354u; return 0; }
r[6]=0x00000001u;
goto P_0c066356;
P_0c066356: /* original d11d, guest PC 0x0c066356 */
if(!s->budget--) { s->failed_pc=0x0c066356u; return 0; }
r[1]=read(ram,0x0c0663ccu,4);
goto P_0c066358;
P_0c066358: /* original 6012, guest PC 0x0c066358 */
if(!s->budget--) { s->failed_pc=0x0c066358u; return 0; }
tmp=read(ram,r[1],4);
r[0]=tmp;
goto P_0c06635a;
P_0c06635a: /* original 2609, guest PC 0x0c06635a */
if(!s->budget--) { s->failed_pc=0x0c06635au; return 0; }
r[6]&=r[0];
goto P_0c06635c;
P_0c06635c: /* original d01c, guest PC 0x0c06635c */
if(!s->budget--) { s->failed_pc=0x0c06635cu; return 0; }
r[0]=read(ram,0x0c0663d0u,4);
goto P_0c06635e;
P_0c06635e: /* original 4628, guest PC 0x0c06635e */
if(!s->budget--) { s->failed_pc=0x0c06635eu; return 0; }
r[6]<<=16;
goto P_0c066360;
P_0c066360: /* original 4608, guest PC 0x0c066360 */
if(!s->budget--) { s->failed_pc=0x0c066360u; return 0; }
r[6]<<=2;
goto P_0c066362;
P_0c066362: /* original 4608, guest PC 0x0c066362 */
if(!s->budget--) { s->failed_pc=0x0c066362u; return 0; }
r[6]<<=2;
goto P_0c066364;
P_0c066364: /* original 256b, guest PC 0x0c066364 */
if(!s->budget--) { s->failed_pc=0x0c066364u; return 0; }
r[5]|=r[6];
goto P_0c066366;
P_0c066366: /* original 6202, guest PC 0x0c066366 */
if(!s->budget--) { s->failed_pc=0x0c066366u; return 0; }
tmp=read(ram,r[0],4);
r[2]=tmp;
goto P_0c066368;
P_0c066368: /* original 2429, guest PC 0x0c066368 */
if(!s->budget--) { s->failed_pc=0x0c066368u; return 0; }
r[4]&=r[2];
goto P_0c06636a;
P_0c06636a: /* original 4428, guest PC 0x0c06636a */
if(!s->budget--) { s->failed_pc=0x0c06636au; return 0; }
r[4]<<=16;
goto P_0c06636c;
P_0c06636c: /* original a005, guest PC 0x0c06636c */
if(!s->budget--) { s->failed_pc=0x0c06636cu; return 0; }
r[5]|=r[4];
goto P_0c06637a;
P_0c06636e: /* original 254b, guest PC 0x0c06636e */
if(!s->budget--) { s->failed_pc=0x0c06636eu; return 0; }
r[5]|=r[4];
goto P_0c066370;
P_0c066370: /* original d016, guest PC 0x0c066370 */
if(!s->budget--) { s->failed_pc=0x0c066370u; return 0; }
r[0]=read(ram,0x0c0663ccu,4);
goto P_0c066372;
P_0c066372: /* original 6102, guest PC 0x0c066372 */
if(!s->budget--) { s->failed_pc=0x0c066372u; return 0; }
tmp=read(ram,r[0],4);
r[1]=tmp;
goto P_0c066374;
P_0c066374: /* original 2619, guest PC 0x0c066374 */
if(!s->budget--) { s->failed_pc=0x0c066374u; return 0; }
r[6]&=r[1];
goto P_0c066376;
P_0c066376: /* original 4628, guest PC 0x0c066376 */
if(!s->budget--) { s->failed_pc=0x0c066376u; return 0; }
r[6]<<=16;
goto P_0c066378;
P_0c066378: /* original 256b, guest PC 0x0c066378 */
if(!s->budget--) { s->failed_pc=0x0c066378u; return 0; }
r[5]|=r[6];
goto P_0c06637a;
P_0c06637a: /* original 940f, guest PC 0x0c06637a */
if(!s->budget--) { s->failed_pc=0x0c06637au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06639cu,2);
goto P_0c06637c;
P_0c06637c: /* original 4e0b, guest PC 0x0c06637c */
if(!s->budget--) { s->failed_pc=0x0c06637cu; return 0; }
target=r[14];
r[16]=code_base|0x0c066380u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c066380u) { target=s->pc; goto dispatch; }
goto P_0c066380;
P_0c06637e: /* original 0009, guest PC 0x0c06637e */
if(!s->budget--) { s->failed_pc=0x0c06637eu; return 0; }
goto P_0c066380;
P_0c066380: /* original d514, guest PC 0x0c066380 */
if(!s->budget--) { s->failed_pc=0x0c066380u; return 0; }
r[5]=read(ram,0x0c0663d4u,4);
goto P_0c066382;
P_0c066382: /* original 940c, guest PC 0x0c066382 */
if(!s->budget--) { s->failed_pc=0x0c066382u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06639eu,2);
goto P_0c066384;
P_0c066384: /* original 4e0b, guest PC 0x0c066384 */
if(!s->budget--) { s->failed_pc=0x0c066384u; return 0; }
target=r[14];
r[16]=code_base|0x0c066388u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c066388u) { target=s->pc; goto dispatch; }
goto P_0c066388;
P_0c066386: /* original 0009, guest PC 0x0c066386 */
if(!s->budget--) { s->failed_pc=0x0c066386u; return 0; }
goto P_0c066388;
P_0c066388: /* original 7f0c, guest PC 0x0c066388 */
if(!s->budget--) { s->failed_pc=0x0c066388u; return 0; }
r[15]+=0x0000000cu;
goto P_0c06638a;
P_0c06638a: /* original 4f26, guest PC 0x0c06638a */
if(!s->budget--) { s->failed_pc=0x0c06638au; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c06638c;
P_0c06638c: /* original 6df6, guest PC 0x0c06638c */
if(!s->budget--) { s->failed_pc=0x0c06638cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c06638e;
P_0c06638e: /* original 000b, guest PC 0x0c06638e */
if(!s->budget--) { s->failed_pc=0x0c06638eu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c066390: /* original 6ef6, guest PC 0x0c066390 */
if(!s->budget--) { s->failed_pc=0x0c066390u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c066392u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c066392u; return 0; } return 1;
P_0c0663d8: /* original d642, guest PC 0x0c0663d8 */
if(!s->budget--) { s->failed_pc=0x0c0663d8u; return 0; }
r[6]=read(ram,0x0c0664e4u,4);
goto P_0c0663da;
P_0c0663da: /* original 6343, guest PC 0x0c0663da */
if(!s->budget--) { s->failed_pc=0x0c0663dau; return 0; }
r[3]=r[4];
goto P_0c0663dc;
P_0c0663dc: /* original d242, guest PC 0x0c0663dc */
if(!s->budget--) { s->failed_pc=0x0c0663dcu; return 0; }
r[2]=read(ram,0x0c0664e8u,4);
goto P_0c0663de;
P_0c0663de: /* original f48d, guest PC 0x0c0663de */
if(!s->budget--) { s->failed_pc=0x0c0663deu; return 0; }
fr[4]=0;
goto P_0c0663e0;
P_0c0663e0: /* original d142, guest PC 0x0c0663e0 */
if(!s->budget--) { s->failed_pc=0x0c0663e0u; return 0; }
r[1]=read(ram,0x0c0664ecu,4);
goto P_0c0663e2;
P_0c0663e2: /* original e00c, guest PC 0x0c0663e2 */
if(!s->budget--) { s->failed_pc=0x0c0663e2u; return 0; }
r[0]=0x0000000cu;
goto P_0c0663e4;
P_0c0663e4: /* original 264b, guest PC 0x0c0663e4 */
if(!s->budget--) { s->failed_pc=0x0c0663e4u; return 0; }
r[6]|=r[4];
goto P_0c0663e6;
P_0c0663e6: /* original 3358, guest PC 0x0c0663e6 */
if(!s->budget--) { s->failed_pc=0x0c0663e6u; return 0; }
r[3]-=r[5];
goto P_0c0663e8;
P_0c0663e8: /* original 4309, guest PC 0x0c0663e8 */
if(!s->budget--) { s->failed_pc=0x0c0663e8u; return 0; }
r[3]>>=2;
goto P_0c0663ea;
P_0c0663ea: /* original 7302, guest PC 0x0c0663ea */
if(!s->budget--) { s->failed_pc=0x0c0663eau; return 0; }
r[3]+=0x00000002u;
goto P_0c0663ec;
P_0c0663ec: /* original 232b, guest PC 0x0c0663ec */
if(!s->budget--) { s->failed_pc=0x0c0663ecu; return 0; }
r[3]|=r[2];
goto P_0c0663ee;
P_0c0663ee: /* original 2632, guest PC 0x0c0663ee */
if(!s->budget--) { s->failed_pc=0x0c0663eeu; return 0; }
write(ram,r[6],r[3],4);
goto P_0c0663f0;
P_0c0663f0: /* original 1611, guest PC 0x0c0663f0 */
if(!s->budget--) { s->failed_pc=0x0c0663f0u; return 0; }
write(ram,r[6]+4,r[1],4);
goto P_0c0663f2;
P_0c0663f2: /* original 7608, guest PC 0x0c0663f2 */
if(!s->budget--) { s->failed_pc=0x0c0663f2u; return 0; }
r[6]+=0x00000008u;
goto P_0c0663f4;
P_0c0663f4: /* original d33e, guest PC 0x0c0663f4 */
if(!s->budget--) { s->failed_pc=0x0c0663f4u; return 0; }
r[3]=read(ram,0x0c0664f0u,4);
goto P_0c0663f6;
P_0c0663f6: /* original 2632, guest PC 0x0c0663f6 */
if(!s->budget--) { s->failed_pc=0x0c0663f6u; return 0; }
write(ram,r[6],r[3],4);
goto P_0c0663f8;
P_0c0663f8: /* original d13e, guest PC 0x0c0663f8 */
if(!s->budget--) { s->failed_pc=0x0c0663f8u; return 0; }
r[1]=read(ram,0x0c0664f4u,4);
goto P_0c0663fa;
P_0c0663fa: /* original e300, guest PC 0x0c0663fa */
if(!s->budget--) { s->failed_pc=0x0c0663fau; return 0; }
r[3]=0x00000000u;
goto P_0c0663fc;
P_0c0663fc: /* original 1611, guest PC 0x0c0663fc */
if(!s->budget--) { s->failed_pc=0x0c0663fcu; return 0; }
write(ram,r[6]+4,r[1],4);
goto P_0c0663fe;
P_0c0663fe: /* original 1632, guest PC 0x0c0663fe */
if(!s->budget--) { s->failed_pc=0x0c0663feu; return 0; }
write(ram,r[6]+8,r[3],4);
goto P_0c066400;
P_0c066400: /* original f647, guest PC 0x0c066400 */
if(!s->budget--) { s->failed_pc=0x0c066400u; return 0; }
vf3_matrix_store(s,ram,4,r[6]+r[0]);
goto P_0c066402;
P_0c066402: /* original e010, guest PC 0x0c066402 */
if(!s->budget--) { s->failed_pc=0x0c066402u; return 0; }
r[0]=0x00000010u;
goto P_0c066404;
P_0c066404: /* original d33d, guest PC 0x0c066404 */
if(!s->budget--) { s->failed_pc=0x0c066404u; return 0; }
r[3]=read(ram,0x0c0664fcu,4);
goto P_0c066406;
P_0c066406: /* original f647, guest PC 0x0c066406 */
if(!s->budget--) { s->failed_pc=0x0c066406u; return 0; }
vf3_matrix_store(s,ram,4,r[6]+r[0]);
goto P_0c066408;
P_0c066408: /* original c73b, guest PC 0x0c066408 */
if(!s->budget--) { s->failed_pc=0x0c066408u; return 0; }
r[0]=code_base|0x000664f8u;
goto P_0c06640a;
P_0c06640a: /* original f508, guest PC 0x0c06640a */
if(!s->budget--) { s->failed_pc=0x0c06640au; return 0; }
vf3_matrix_load(s,ram,5,r[0]);
goto P_0c06640c;
P_0c06640c: /* original e014, guest PC 0x0c06640c */
if(!s->budget--) { s->failed_pc=0x0c06640cu; return 0; }
r[0]=0x00000014u;
goto P_0c06640e;
P_0c06640e: /* original f657, guest PC 0x0c06640e */
if(!s->budget--) { s->failed_pc=0x0c06640eu; return 0; }
vf3_matrix_store(s,ram,5,r[6]+r[0]);
goto P_0c066410;
P_0c066410: /* original 1636, guest PC 0x0c066410 */
if(!s->budget--) { s->failed_pc=0x0c066410u; return 0; }
write(ram,r[6]+24,r[3],4);
goto P_0c066412;
P_0c066412: /* original e01c, guest PC 0x0c066412 */
if(!s->budget--) { s->failed_pc=0x0c066412u; return 0; }
r[0]=0x0000001cu;
goto P_0c066414;
P_0c066414: /* original f647, guest PC 0x0c066414 */
if(!s->budget--) { s->failed_pc=0x0c066414u; return 0; }
vf3_matrix_store(s,ram,4,r[6]+r[0]);
goto P_0c066416;
P_0c066416: /* original c73a, guest PC 0x0c066416 */
if(!s->budget--) { s->failed_pc=0x0c066416u; return 0; }
r[0]=code_base|0x00066500u;
goto P_0c066418;
P_0c066418: /* original d33a, guest PC 0x0c066418 */
if(!s->budget--) { s->failed_pc=0x0c066418u; return 0; }
r[3]=read(ram,0x0c066504u,4);
goto P_0c06641a;
P_0c06641a: /* original f308, guest PC 0x0c06641a */
if(!s->budget--) { s->failed_pc=0x0c06641au; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c06641c;
P_0c06641c: /* original e020, guest PC 0x0c06641c */
if(!s->budget--) { s->failed_pc=0x0c06641cu; return 0; }
r[0]=0x00000020u;
goto P_0c06641e;
P_0c06641e: /* original f637, guest PC 0x0c06641e */
if(!s->budget--) { s->failed_pc=0x0c06641eu; return 0; }
vf3_matrix_store(s,ram,3,r[6]+r[0]);
goto P_0c066420;
P_0c066420: /* original e024, guest PC 0x0c066420 */
if(!s->budget--) { s->failed_pc=0x0c066420u; return 0; }
r[0]=0x00000024u;
goto P_0c066422;
P_0c066422: /* original f657, guest PC 0x0c066422 */
if(!s->budget--) { s->failed_pc=0x0c066422u; return 0; }
vf3_matrix_store(s,ram,5,r[6]+r[0]);
goto P_0c066424;
P_0c066424: /* original 163a, guest PC 0x0c066424 */
if(!s->budget--) { s->failed_pc=0x0c066424u; return 0; }
write(ram,r[6]+40,r[3],4);
goto P_0c066426;
P_0c066426: /* original c738, guest PC 0x0c066426 */
if(!s->budget--) { s->failed_pc=0x0c066426u; return 0; }
r[0]=code_base|0x00066508u;
goto P_0c066428;
P_0c066428: /* original d338, guest PC 0x0c066428 */
if(!s->budget--) { s->failed_pc=0x0c066428u; return 0; }
r[3]=read(ram,0x0c06650cu,4);
goto P_0c06642a;
P_0c06642a: /* original f308, guest PC 0x0c06642a */
if(!s->budget--) { s->failed_pc=0x0c06642au; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c06642c;
P_0c06642c: /* original e02c, guest PC 0x0c06642c */
if(!s->budget--) { s->failed_pc=0x0c06642cu; return 0; }
r[0]=0x0000002cu;
goto P_0c06642e;
P_0c06642e: /* original f637, guest PC 0x0c06642e */
if(!s->budget--) { s->failed_pc=0x0c06642eu; return 0; }
vf3_matrix_store(s,ram,3,r[6]+r[0]);
goto P_0c066430;
P_0c066430: /* original e030, guest PC 0x0c066430 */
if(!s->budget--) { s->failed_pc=0x0c066430u; return 0; }
r[0]=0x00000030u;
goto P_0c066432;
P_0c066432: /* original f647, guest PC 0x0c066432 */
if(!s->budget--) { s->failed_pc=0x0c066432u; return 0; }
vf3_matrix_store(s,ram,4,r[6]+r[0]);
goto P_0c066434;
P_0c066434: /* original e034, guest PC 0x0c066434 */
if(!s->budget--) { s->failed_pc=0x0c066434u; return 0; }
r[0]=0x00000034u;
goto P_0c066436;
P_0c066436: /* original f657, guest PC 0x0c066436 */
if(!s->budget--) { s->failed_pc=0x0c066436u; return 0; }
vf3_matrix_store(s,ram,5,r[6]+r[0]);
goto P_0c066438;
P_0c066438: /* original 163e, guest PC 0x0c066438 */
if(!s->budget--) { s->failed_pc=0x0c066438u; return 0; }
write(ram,r[6]+56,r[3],4);
goto P_0c06643a;
P_0c06643a: /* original 000b, guest PC 0x0c06643a */
if(!s->budget--) { s->failed_pc=0x0c06643au; return 0; }
target=r[16];
r[0]=r[4];
s->pc=target; return ram->oob==0;
P_0c06643c: /* original 6043, guest PC 0x0c06643c */
if(!s->budget--) { s->failed_pc=0x0c06643cu; return 0; }
r[0]=r[4];
return vf3_matrix_family(0x0c06643eu,s,ram);
unsupported: s->failed_pc=target; return 0;
}
