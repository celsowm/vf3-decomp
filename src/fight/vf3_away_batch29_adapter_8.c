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
int vf3_away_batch29_adapter_8(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
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
case 0x0c0633e0u: goto P_0c0633e0;
case 0x0c0633e2u: goto P_0c0633e2;
case 0x0c0633e4u: goto P_0c0633e4;
case 0x0c0633e6u: goto P_0c0633e6;
case 0x0c0633e8u: goto P_0c0633e8;
case 0x0c0633eau: goto P_0c0633ea;
case 0x0c0633ecu: goto P_0c0633ec;
case 0x0c0633eeu: goto P_0c0633ee;
case 0x0c0633f0u: goto P_0c0633f0;
case 0x0c0633f2u: goto P_0c0633f2;
case 0x0c0633f4u: goto P_0c0633f4;
case 0x0c0633f6u: goto P_0c0633f6;
case 0x0c0633f8u: goto P_0c0633f8;
case 0x0c0633fau: goto P_0c0633fa;
case 0x0c0633fcu: goto P_0c0633fc;
case 0x0c0633feu: goto P_0c0633fe;
case 0x0c063400u: goto P_0c063400;
case 0x0c063402u: goto P_0c063402;
case 0x0c063404u: goto P_0c063404;
case 0x0c063406u: goto P_0c063406;
case 0x0c063408u: goto P_0c063408;
case 0x0c06340au: goto P_0c06340a;
case 0x0c063418u: goto P_0c063418;
case 0x0c06341au: goto P_0c06341a;
case 0x0c06341cu: goto P_0c06341c;
case 0x0c06341eu: goto P_0c06341e;
case 0x0c063420u: goto P_0c063420;
case 0x0c063422u: goto P_0c063422;
case 0x0c063424u: goto P_0c063424;
case 0x0c063426u: goto P_0c063426;
case 0x0c063428u: goto P_0c063428;
case 0x0c06342au: goto P_0c06342a;
case 0x0c06342cu: goto P_0c06342c;
case 0x0c06342eu: goto P_0c06342e;
case 0x0c063430u: goto P_0c063430;
case 0x0c063432u: goto P_0c063432;
case 0x0c063434u: goto P_0c063434;
case 0x0c064594u: goto P_0c064594;
case 0x0c064596u: goto P_0c064596;
case 0x0c064598u: goto P_0c064598;
case 0x0c06459au: goto P_0c06459a;
case 0x0c06459cu: goto P_0c06459c;
case 0x0c06459eu: goto P_0c06459e;
case 0x0c0645a0u: goto P_0c0645a0;
case 0x0c0645a2u: goto P_0c0645a2;
case 0x0c0645a4u: goto P_0c0645a4;
case 0x0c0645a6u: goto P_0c0645a6;
case 0x0c0645a8u: goto P_0c0645a8;
case 0x0c0645aau: goto P_0c0645aa;
case 0x0c0645acu: goto P_0c0645ac;
case 0x0c0645aeu: goto P_0c0645ae;
case 0x0c0645b0u: goto P_0c0645b0;
case 0x0c0645b2u: goto P_0c0645b2;
case 0x0c0645b4u: goto P_0c0645b4;
case 0x0c0645b6u: goto P_0c0645b6;
case 0x0c0645b8u: goto P_0c0645b8;
case 0x0c0645bau: goto P_0c0645ba;
case 0x0c0645bcu: goto P_0c0645bc;
case 0x0c0645beu: goto P_0c0645be;
case 0x0c0645c0u: goto P_0c0645c0;
case 0x0c0645c2u: goto P_0c0645c2;
case 0x0c0645c4u: goto P_0c0645c4;
case 0x0c0645c6u: goto P_0c0645c6;
case 0x0c0645c8u: goto P_0c0645c8;
case 0x0c0645cau: goto P_0c0645ca;
case 0x0c0645ccu: goto P_0c0645cc;
case 0x0c0645ceu: goto P_0c0645ce;
case 0x0c0645d0u: goto P_0c0645d0;
case 0x0c0645d2u: goto P_0c0645d2;
case 0x0c0645d4u: goto P_0c0645d4;
case 0x0c0645d6u: goto P_0c0645d6;
case 0x0c0645d8u: goto P_0c0645d8;
case 0x0c0645dau: goto P_0c0645da;
case 0x0c0645dcu: goto P_0c0645dc;
case 0x0c0645deu: goto P_0c0645de;
case 0x0c0645e0u: goto P_0c0645e0;
case 0x0c0645e2u: goto P_0c0645e2;
case 0x0c0645e4u: goto P_0c0645e4;
case 0x0c0645e6u: goto P_0c0645e6;
case 0x0c0645e8u: goto P_0c0645e8;
case 0x0c0645eau: goto P_0c0645ea;
case 0x0c0645ecu: goto P_0c0645ec;
case 0x0c0645eeu: goto P_0c0645ee;
case 0x0c0645f0u: goto P_0c0645f0;
case 0x0c0645f2u: goto P_0c0645f2;
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
P_0c0633e0: /* original 4f22, guest PC 0x0c0633e0 */
if(!s->budget--) { s->failed_pc=0x0c0633e0u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0633e2;
P_0c0633e2: /* original 7ff8, guest PC 0x0c0633e2 */
if(!s->budget--) { s->failed_pc=0x0c0633e2u; return 0; }
r[15]+=0xfffffff8u;
goto P_0c0633e4;
P_0c0633e4: /* original d30a, guest PC 0x0c0633e4 */
if(!s->budget--) { s->failed_pc=0x0c0633e4u; return 0; }
r[3]=read(ram,0x0c063410u,4);
goto P_0c0633e6;
P_0c0633e6: /* original 2f52, guest PC 0x0c0633e6 */
if(!s->budget--) { s->failed_pc=0x0c0633e6u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0633e8;
P_0c0633e8: /* original d508, guest PC 0x0c0633e8 */
if(!s->budget--) { s->failed_pc=0x0c0633e8u; return 0; }
r[5]=read(ram,0x0c06340cu,4);
goto P_0c0633ea;
P_0c0633ea: /* original 430b, guest PC 0x0c0633ea */
if(!s->budget--) { s->failed_pc=0x0c0633eau; return 0; }
target=r[3];
r[16]=code_base|0x0c0633eeu;
write(ram,r[15]+4,r[6],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0633eeu) { target=s->pc; goto dispatch; }
goto P_0c0633ee;
P_0c0633ec: /* original 1f61, guest PC 0x0c0633ec */
if(!s->budget--) { s->failed_pc=0x0c0633ecu; return 0; }
write(ram,r[15]+4,r[6],4);
goto P_0c0633ee;
P_0c0633ee: /* original 2008, guest PC 0x0c0633ee */
if(!s->budget--) { s->failed_pc=0x0c0633eeu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c0633f0;
P_0c0633f0: /* original 8b07, guest PC 0x0c0633f0 */
if(!s->budget--) { s->failed_pc=0x0c0633f0u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c063402; }
goto P_0c0633f2;
P_0c0633f2: /* original d508, guest PC 0x0c0633f2 */
if(!s->budget--) { s->failed_pc=0x0c0633f2u; return 0; }
r[5]=read(ram,0x0c063414u,4);
goto P_0c0633f4;
P_0c0633f4: /* original d306, guest PC 0x0c0633f4 */
if(!s->budget--) { s->failed_pc=0x0c0633f4u; return 0; }
r[3]=read(ram,0x0c063410u,4);
goto P_0c0633f6;
P_0c0633f6: /* original 430b, guest PC 0x0c0633f6 */
if(!s->budget--) { s->failed_pc=0x0c0633f6u; return 0; }
target=r[3];
r[16]=code_base|0x0c0633fau;
tmp=read(ram,r[15],4);
r[4]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0633fau) { target=s->pc; goto dispatch; }
goto P_0c0633fa;
P_0c0633f8: /* original 64f2, guest PC 0x0c0633f8 */
if(!s->budget--) { s->failed_pc=0x0c0633f8u; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c0633fa;
P_0c0633fa: /* original 2008, guest PC 0x0c0633fa */
if(!s->budget--) { s->failed_pc=0x0c0633fau; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c0633fc;
P_0c0633fc: /* original 8b02, guest PC 0x0c0633fc */
if(!s->budget--) { s->failed_pc=0x0c0633fcu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c063404; }
goto P_0c0633fe;
P_0c0633fe: /* original a001, guest PC 0x0c0633fe */
if(!s->budget--) { s->failed_pc=0x0c0633feu; return 0; }
r[4]=0x00000000u;
goto P_0c063404;
P_0c063400: /* original e400, guest PC 0x0c063400 */
if(!s->budget--) { s->failed_pc=0x0c063400u; return 0; }
r[4]=0x00000000u;
goto P_0c063402;
P_0c063402: /* original 54f1, guest PC 0x0c063402 */
if(!s->budget--) { s->failed_pc=0x0c063402u; return 0; }
r[4]=read(ram,r[15]+4,4);
goto P_0c063404;
P_0c063404: /* original 7f08, guest PC 0x0c063404 */
if(!s->budget--) { s->failed_pc=0x0c063404u; return 0; }
r[15]+=0x00000008u;
goto P_0c063406;
P_0c063406: /* original 4f26, guest PC 0x0c063406 */
if(!s->budget--) { s->failed_pc=0x0c063406u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c063408;
P_0c063408: /* original 000b, guest PC 0x0c063408 */
if(!s->budget--) { s->failed_pc=0x0c063408u; return 0; }
target=r[16];
r[0]=r[4];
s->pc=target; return ram->oob==0;
P_0c06340a: /* original 6043, guest PC 0x0c06340a */
if(!s->budget--) { s->failed_pc=0x0c06340au; return 0; }
r[0]=r[4];
if(!vf3_matrix_family(0x0c06340cu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c06340cu; return 0; } return 1;
P_0c063418: /* original 2fe6, guest PC 0x0c063418 */
if(!s->budget--) { s->failed_pc=0x0c063418u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06341a;
P_0c06341a: /* original e503, guest PC 0x0c06341a */
if(!s->budget--) { s->failed_pc=0x0c06341au; return 0; }
r[5]=0x00000003u;
goto P_0c06341c;
P_0c06341c: /* original 4f22, guest PC 0x0c06341c */
if(!s->budget--) { s->failed_pc=0x0c06341cu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c06341e;
P_0c06341e: /* original de34, guest PC 0x0c06341e */
if(!s->budget--) { s->failed_pc=0x0c06341eu; return 0; }
r[14]=read(ram,0x0c0634f0u,4);
goto P_0c063420;
P_0c063420: /* original 4e0b, guest PC 0x0c063420 */
if(!s->budget--) { s->failed_pc=0x0c063420u; return 0; }
target=r[14];
r[16]=code_base|0x0c063424u;
r[4]=0x00000008u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c063424u) { target=s->pc; goto dispatch; }
goto P_0c063424;
P_0c063422: /* original e408, guest PC 0x0c063422 */
if(!s->budget--) { s->failed_pc=0x0c063422u; return 0; }
r[4]=0x00000008u;
goto P_0c063424;
P_0c063424: /* original e500, guest PC 0x0c063424 */
if(!s->budget--) { s->failed_pc=0x0c063424u; return 0; }
r[5]=0x00000000u;
goto P_0c063426;
P_0c063426: /* original 4e0b, guest PC 0x0c063426 */
if(!s->budget--) { s->failed_pc=0x0c063426u; return 0; }
target=r[14];
r[16]=code_base|0x0c06342au;
r[4]=r[5];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06342au) { target=s->pc; goto dispatch; }
goto P_0c06342a;
P_0c063428: /* original 6453, guest PC 0x0c063428 */
if(!s->budget--) { s->failed_pc=0x0c063428u; return 0; }
r[4]=r[5];
goto P_0c06342a;
P_0c06342a: /* original e500, guest PC 0x0c06342a */
if(!s->budget--) { s->failed_pc=0x0c06342au; return 0; }
r[5]=0x00000000u;
goto P_0c06342c;
P_0c06342c: /* original 4e0b, guest PC 0x0c06342c */
if(!s->budget--) { s->failed_pc=0x0c06342cu; return 0; }
target=r[14];
r[16]=code_base|0x0c063430u;
r[4]=0x00000008u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c063430u) { target=s->pc; goto dispatch; }
goto P_0c063430;
P_0c06342e: /* original e408, guest PC 0x0c06342e */
if(!s->budget--) { s->failed_pc=0x0c06342eu; return 0; }
r[4]=0x00000008u;
goto P_0c063430;
P_0c063430: /* original 4f26, guest PC 0x0c063430 */
if(!s->budget--) { s->failed_pc=0x0c063430u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c063432;
P_0c063432: /* original 000b, guest PC 0x0c063432 */
if(!s->budget--) { s->failed_pc=0x0c063432u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c063434: /* original 6ef6, guest PC 0x0c063434 */
if(!s->budget--) { s->failed_pc=0x0c063434u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c063436u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c063436u; return 0; } return 1;
P_0c064594: /* original d35e, guest PC 0x0c064594 */
if(!s->budget--) { s->failed_pc=0x0c064594u; return 0; }
r[3]=read(ram,0x0c064710u,4);
goto P_0c064596;
P_0c064596: /* original d260, guest PC 0x0c064596 */
if(!s->budget--) { s->failed_pc=0x0c064596u; return 0; }
r[2]=read(ram,0x0c064718u,4);
goto P_0c064598;
P_0c064598: /* original 2322, guest PC 0x0c064598 */
if(!s->budget--) { s->failed_pc=0x0c064598u; return 0; }
write(ram,r[3],r[2],4);
goto P_0c06459a;
P_0c06459a: /* original d160, guest PC 0x0c06459a */
if(!s->budget--) { s->failed_pc=0x0c06459au; return 0; }
r[1]=read(ram,0x0c06471cu,4);
goto P_0c06459c;
P_0c06459c: /* original d260, guest PC 0x0c06459c */
if(!s->budget--) { s->failed_pc=0x0c06459cu; return 0; }
r[2]=read(ram,0x0c064720u,4);
goto P_0c06459e;
P_0c06459e: /* original 2122, guest PC 0x0c06459e */
if(!s->budget--) { s->failed_pc=0x0c06459eu; return 0; }
write(ram,r[1],r[2],4);
goto P_0c0645a0;
P_0c0645a0: /* original d060, guest PC 0x0c0645a0 */
if(!s->budget--) { s->failed_pc=0x0c0645a0u; return 0; }
r[0]=read(ram,0x0c064724u,4);
goto P_0c0645a2;
P_0c0645a2: /* original e300, guest PC 0x0c0645a2 */
if(!s->budget--) { s->failed_pc=0x0c0645a2u; return 0; }
r[3]=0x00000000u;
goto P_0c0645a4;
P_0c0645a4: /* original 2032, guest PC 0x0c0645a4 */
if(!s->budget--) { s->failed_pc=0x0c0645a4u; return 0; }
write(ram,r[0],r[3],4);
goto P_0c0645a6;
P_0c0645a6: /* original d760, guest PC 0x0c0645a6 */
if(!s->budget--) { s->failed_pc=0x0c0645a6u; return 0; }
r[7]=read(ram,0x0c064728u,4);
goto P_0c0645a8;
P_0c0645a8: /* original d260, guest PC 0x0c0645a8 */
if(!s->budget--) { s->failed_pc=0x0c0645a8u; return 0; }
r[2]=read(ram,0x0c06472cu,4);
goto P_0c0645aa;
P_0c0645aa: /* original 2272, guest PC 0x0c0645aa */
if(!s->budget--) { s->failed_pc=0x0c0645aau; return 0; }
write(ram,r[2],r[7],4);
goto P_0c0645ac;
P_0c0645ac: /* original d660, guest PC 0x0c0645ac */
if(!s->budget--) { s->failed_pc=0x0c0645acu; return 0; }
r[6]=read(ram,0x0c064730u,4);
goto P_0c0645ae;
P_0c0645ae: /* original d361, guest PC 0x0c0645ae */
if(!s->budget--) { s->failed_pc=0x0c0645aeu; return 0; }
r[3]=read(ram,0x0c064734u,4);
goto P_0c0645b0;
P_0c0645b0: /* original 2362, guest PC 0x0c0645b0 */
if(!s->budget--) { s->failed_pc=0x0c0645b0u; return 0; }
write(ram,r[3],r[6],4);
goto P_0c0645b2;
P_0c0645b2: /* original 7110, guest PC 0x0c0645b2 */
if(!s->budget--) { s->failed_pc=0x0c0645b2u; return 0; }
r[1]+=0x00000010u;
goto P_0c0645b4;
P_0c0645b4: /* original d560, guest PC 0x0c0645b4 */
if(!s->budget--) { s->failed_pc=0x0c0645b4u; return 0; }
r[5]=read(ram,0x0c064738u,4);
goto P_0c0645b6;
P_0c0645b6: /* original 2152, guest PC 0x0c0645b6 */
if(!s->budget--) { s->failed_pc=0x0c0645b6u; return 0; }
write(ram,r[1],r[5],4);
goto P_0c0645b8;
P_0c0645b8: /* original d460, guest PC 0x0c0645b8 */
if(!s->budget--) { s->failed_pc=0x0c0645b8u; return 0; }
r[4]=read(ram,0x0c06473cu,4);
goto P_0c0645ba;
P_0c0645ba: /* original 720c, guest PC 0x0c0645ba */
if(!s->budget--) { s->failed_pc=0x0c0645bau; return 0; }
r[2]+=0x0000000cu;
goto P_0c0645bc;
P_0c0645bc: /* original 2242, guest PC 0x0c0645bc */
if(!s->budget--) { s->failed_pc=0x0c0645bcu; return 0; }
write(ram,r[2],r[4],4);
goto P_0c0645be;
P_0c0645be: /* original 730c, guest PC 0x0c0645be */
if(!s->budget--) { s->failed_pc=0x0c0645beu; return 0; }
r[3]+=0x0000000cu;
goto P_0c0645c0;
P_0c0645c0: /* original d15f, guest PC 0x0c0645c0 */
if(!s->budget--) { s->failed_pc=0x0c0645c0u; return 0; }
r[1]=read(ram,0x0c064740u,4);
goto P_0c0645c2;
P_0c0645c2: /* original 2312, guest PC 0x0c0645c2 */
if(!s->budget--) { s->failed_pc=0x0c0645c2u; return 0; }
write(ram,r[3],r[1],4);
goto P_0c0645c4;
P_0c0645c4: /* original d05f, guest PC 0x0c0645c4 */
if(!s->budget--) { s->failed_pc=0x0c0645c4u; return 0; }
r[0]=read(ram,0x0c064744u,4);
goto P_0c0645c6;
P_0c0645c6: /* original 2072, guest PC 0x0c0645c6 */
if(!s->budget--) { s->failed_pc=0x0c0645c6u; return 0; }
write(ram,r[0],r[7],4);
goto P_0c0645c8;
P_0c0645c8: /* original 720c, guest PC 0x0c0645c8 */
if(!s->budget--) { s->failed_pc=0x0c0645c8u; return 0; }
r[2]+=0x0000000cu;
goto P_0c0645ca;
P_0c0645ca: /* original 2252, guest PC 0x0c0645ca */
if(!s->budget--) { s->failed_pc=0x0c0645cau; return 0; }
write(ram,r[2],r[5],4);
goto P_0c0645cc;
P_0c0645cc: /* original 730c, guest PC 0x0c0645cc */
if(!s->budget--) { s->failed_pc=0x0c0645ccu; return 0; }
r[3]+=0x0000000cu;
goto P_0c0645ce;
P_0c0645ce: /* original 2342, guest PC 0x0c0645ce */
if(!s->budget--) { s->failed_pc=0x0c0645ceu; return 0; }
write(ram,r[3],r[4],4);
goto P_0c0645d0;
P_0c0645d0: /* original d15d, guest PC 0x0c0645d0 */
if(!s->budget--) { s->failed_pc=0x0c0645d0u; return 0; }
r[1]=read(ram,0x0c064748u,4);
goto P_0c0645d2;
P_0c0645d2: /* original d25e, guest PC 0x0c0645d2 */
if(!s->budget--) { s->failed_pc=0x0c0645d2u; return 0; }
r[2]=read(ram,0x0c06474cu,4);
goto P_0c0645d4;
P_0c0645d4: /* original 2122, guest PC 0x0c0645d4 */
if(!s->budget--) { s->failed_pc=0x0c0645d4u; return 0; }
write(ram,r[1],r[2],4);
goto P_0c0645d6;
P_0c0645d6: /* original d05e, guest PC 0x0c0645d6 */
if(!s->budget--) { s->failed_pc=0x0c0645d6u; return 0; }
r[0]=read(ram,0x0c064750u,4);
goto P_0c0645d8;
P_0c0645d8: /* original 2062, guest PC 0x0c0645d8 */
if(!s->budget--) { s->failed_pc=0x0c0645d8u; return 0; }
write(ram,r[0],r[6],4);
goto P_0c0645da;
P_0c0645da: /* original 730c, guest PC 0x0c0645da */
if(!s->budget--) { s->failed_pc=0x0c0645dau; return 0; }
r[3]+=0x0000000cu;
goto P_0c0645dc;
P_0c0645dc: /* original 2352, guest PC 0x0c0645dc */
if(!s->budget--) { s->failed_pc=0x0c0645dcu; return 0; }
write(ram,r[3],r[5],4);
goto P_0c0645de;
P_0c0645de: /* original d25d, guest PC 0x0c0645de */
if(!s->budget--) { s->failed_pc=0x0c0645deu; return 0; }
r[2]=read(ram,0x0c064754u,4);
goto P_0c0645e0;
P_0c0645e0: /* original 2242, guest PC 0x0c0645e0 */
if(!s->budget--) { s->failed_pc=0x0c0645e0u; return 0; }
write(ram,r[2],r[4],4);
goto P_0c0645e2;
P_0c0645e2: /* original 71e8, guest PC 0x0c0645e2 */
if(!s->budget--) { s->failed_pc=0x0c0645e2u; return 0; }
r[1]+=0xffffffe8u;
goto P_0c0645e4;
P_0c0645e4: /* original 6312, guest PC 0x0c0645e4 */
if(!s->budget--) { s->failed_pc=0x0c0645e4u; return 0; }
tmp=read(ram,r[1],4);
r[3]=tmp;
goto P_0c0645e6;
P_0c0645e6: /* original d05c, guest PC 0x0c0645e6 */
if(!s->budget--) { s->failed_pc=0x0c0645e6u; return 0; }
r[0]=read(ram,0x0c064758u,4);
goto P_0c0645e8;
P_0c0645e8: /* original 2032, guest PC 0x0c0645e8 */
if(!s->budget--) { s->failed_pc=0x0c0645e8u; return 0; }
write(ram,r[0],r[3],4);
goto P_0c0645ea;
P_0c0645ea: /* original d247, guest PC 0x0c0645ea */
if(!s->budget--) { s->failed_pc=0x0c0645eau; return 0; }
r[2]=read(ram,0x0c064708u,4);
goto P_0c0645ec;
P_0c0645ec: /* original d342, guest PC 0x0c0645ec */
if(!s->budget--) { s->failed_pc=0x0c0645ecu; return 0; }
r[3]=read(ram,0x0c0646f8u,4);
goto P_0c0645ee;
P_0c0645ee: /* original 2322, guest PC 0x0c0645ee */
if(!s->budget--) { s->failed_pc=0x0c0645eeu; return 0; }
write(ram,r[3],r[2],4);
goto P_0c0645f0;
P_0c0645f0: /* original 000b, guest PC 0x0c0645f0 */
if(!s->budget--) { s->failed_pc=0x0c0645f0u; return 0; }
target=r[16];
r[0]=0x00000000u;
s->pc=target; return ram->oob==0;
P_0c0645f2: /* original e000, guest PC 0x0c0645f2 */
if(!s->budget--) { s->failed_pc=0x0c0645f2u; return 0; }
r[0]=0x00000000u;
if(!vf3_matrix_family(0x0c0645f4u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0645f4u; return 0; } return 1;
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
unsupported: s->failed_pc=target; return 0;
}
