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
int vf3_away_batch179_adapter_2(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c03b300u: goto P_0c03b300;
case 0x0c03b302u: goto P_0c03b302;
case 0x0c03b304u: goto P_0c03b304;
case 0x0c03b306u: goto P_0c03b306;
case 0x0c03b308u: goto P_0c03b308;
case 0x0c03b30au: goto P_0c03b30a;
case 0x0c03b30cu: goto P_0c03b30c;
case 0x0c03b30eu: goto P_0c03b30e;
case 0x0c03b310u: goto P_0c03b310;
case 0x0c03b312u: goto P_0c03b312;
case 0x0c03b314u: goto P_0c03b314;
case 0x0c03b316u: goto P_0c03b316;
case 0x0c03b318u: goto P_0c03b318;
case 0x0c03b31au: goto P_0c03b31a;
case 0x0c03b31cu: goto P_0c03b31c;
case 0x0c03b31eu: goto P_0c03b31e;
case 0x0c03b320u: goto P_0c03b320;
case 0x0c03b322u: goto P_0c03b322;
case 0x0c03b324u: goto P_0c03b324;
case 0x0c03b326u: goto P_0c03b326;
case 0x0c03b328u: goto P_0c03b328;
case 0x0c03b32au: goto P_0c03b32a;
case 0x0c03b32cu: goto P_0c03b32c;
case 0x0c03b32eu: goto P_0c03b32e;
case 0x0c03b330u: goto P_0c03b330;
case 0x0c03b332u: goto P_0c03b332;
case 0x0c03b334u: goto P_0c03b334;
case 0x0c03b336u: goto P_0c03b336;
case 0x0c03b338u: goto P_0c03b338;
case 0x0c03f5a0u: goto P_0c03f5a0;
case 0x0c03f5a2u: goto P_0c03f5a2;
case 0x0c03f5a4u: goto P_0c03f5a4;
case 0x0c03f5a6u: goto P_0c03f5a6;
case 0x0c03f5a8u: goto P_0c03f5a8;
case 0x0c03f5aau: goto P_0c03f5aa;
case 0x0c03f5acu: goto P_0c03f5ac;
case 0x0c03f5aeu: goto P_0c03f5ae;
case 0x0c03f5b0u: goto P_0c03f5b0;
case 0x0c03f5b2u: goto P_0c03f5b2;
case 0x0c03f5b4u: goto P_0c03f5b4;
case 0x0c03f5b6u: goto P_0c03f5b6;
case 0x0c03f5b8u: goto P_0c03f5b8;
case 0x0c03f5bau: goto P_0c03f5ba;
case 0x0c03f5bcu: goto P_0c03f5bc;
case 0x0c03f5beu: goto P_0c03f5be;
case 0x0c03f5c0u: goto P_0c03f5c0;
case 0x0c03f5c2u: goto P_0c03f5c2;
case 0x0c03f5d0u: goto P_0c03f5d0;
case 0x0c03f5d2u: goto P_0c03f5d2;
case 0x0c03f5d4u: goto P_0c03f5d4;
case 0x0c03f5d6u: goto P_0c03f5d6;
case 0x0c03f5d8u: goto P_0c03f5d8;
case 0x0c03f5dau: goto P_0c03f5da;
case 0x0c03f5dcu: goto P_0c03f5dc;
case 0x0c03f5deu: goto P_0c03f5de;
case 0x0c03f5e0u: goto P_0c03f5e0;
case 0x0c03f5e2u: goto P_0c03f5e2;
case 0x0c03f5e4u: goto P_0c03f5e4;
case 0x0c03f5e6u: goto P_0c03f5e6;
case 0x0c03f5e8u: goto P_0c03f5e8;
case 0x0c03f5eau: goto P_0c03f5ea;
case 0x0c03f5ecu: goto P_0c03f5ec;
case 0x0c03f5eeu: goto P_0c03f5ee;
case 0x0c03f5f0u: goto P_0c03f5f0;
case 0x0c03f5f2u: goto P_0c03f5f2;
case 0x0c03f5f4u: goto P_0c03f5f4;
case 0x0c03f5f6u: goto P_0c03f5f6;
case 0x0c03f5f8u: goto P_0c03f5f8;
case 0x0c03f5fau: goto P_0c03f5fa;
case 0x0c03f5fcu: goto P_0c03f5fc;
case 0x0c03f5feu: goto P_0c03f5fe;
case 0x0c03f600u: goto P_0c03f600;
case 0x0c03f602u: goto P_0c03f602;
case 0x0c03f604u: goto P_0c03f604;
case 0x0c03f606u: goto P_0c03f606;
case 0x0c03f608u: goto P_0c03f608;
case 0x0c03f60au: goto P_0c03f60a;
case 0x0c03f60cu: goto P_0c03f60c;
case 0x0c03f60eu: goto P_0c03f60e;
case 0x0c03f610u: goto P_0c03f610;
case 0x0c03f612u: goto P_0c03f612;
case 0x0c03f614u: goto P_0c03f614;
case 0x0c03f616u: goto P_0c03f616;
case 0x0c03f618u: goto P_0c03f618;
case 0x0c03f61au: goto P_0c03f61a;
case 0x0c03f61cu: goto P_0c03f61c;
case 0x0c03f61eu: goto P_0c03f61e;
case 0x0c03f620u: goto P_0c03f620;
case 0x0c03f622u: goto P_0c03f622;
case 0x0c03f624u: goto P_0c03f624;
case 0x0c03f626u: goto P_0c03f626;
case 0x0c03f628u: goto P_0c03f628;
case 0x0c03f62au: goto P_0c03f62a;
case 0x0c03f62cu: goto P_0c03f62c;
case 0x0c03f62eu: goto P_0c03f62e;
case 0x0c03f630u: goto P_0c03f630;
case 0x0c03f632u: goto P_0c03f632;
case 0x0c03f634u: goto P_0c03f634;
case 0x0c03f636u: goto P_0c03f636;
case 0x0c03f638u: goto P_0c03f638;
case 0x0c03f63au: goto P_0c03f63a;
case 0x0c03f63cu: goto P_0c03f63c;
case 0x0c03f63eu: goto P_0c03f63e;
case 0x0c03f640u: goto P_0c03f640;
case 0x0c03f642u: goto P_0c03f642;
case 0x0c03f644u: goto P_0c03f644;
case 0x0c03f646u: goto P_0c03f646;
case 0x0c03f648u: goto P_0c03f648;
case 0x0c03f64au: goto P_0c03f64a;
case 0x0c03f64cu: goto P_0c03f64c;
case 0x0c03f64eu: goto P_0c03f64e;
case 0x0c03f650u: goto P_0c03f650;
case 0x0c03f652u: goto P_0c03f652;
case 0x0c03f654u: goto P_0c03f654;
case 0x0c03f656u: goto P_0c03f656;
case 0x0c03f658u: goto P_0c03f658;
case 0x0c03f65au: goto P_0c03f65a;
case 0x0c03f65cu: goto P_0c03f65c;
case 0x0c03f65eu: goto P_0c03f65e;
case 0x0c03f660u: goto P_0c03f660;
case 0x0c03f662u: goto P_0c03f662;
case 0x0c03f664u: goto P_0c03f664;
case 0x0c03f666u: goto P_0c03f666;
case 0x0c03f668u: goto P_0c03f668;
case 0x0c03f66au: goto P_0c03f66a;
case 0x0c03f66cu: goto P_0c03f66c;
case 0x0c03f66eu: goto P_0c03f66e;
case 0x0c03f670u: goto P_0c03f670;
case 0x0c03f672u: goto P_0c03f672;
case 0x0c03f674u: goto P_0c03f674;
case 0x0c03f676u: goto P_0c03f676;
case 0x0c03f678u: goto P_0c03f678;
case 0x0c03f67au: goto P_0c03f67a;
case 0x0c03f67cu: goto P_0c03f67c;
case 0x0c03f67eu: goto P_0c03f67e;
case 0x0c03f680u: goto P_0c03f680;
case 0x0c03f682u: goto P_0c03f682;
case 0x0c03f684u: goto P_0c03f684;
case 0x0c03fc90u: goto P_0c03fc90;
case 0x0c03fc92u: goto P_0c03fc92;
case 0x0c03fc94u: goto P_0c03fc94;
case 0x0c03fc96u: goto P_0c03fc96;
case 0x0c03fc98u: goto P_0c03fc98;
case 0x0c03fc9au: goto P_0c03fc9a;
case 0x0c03fc9cu: goto P_0c03fc9c;
case 0x0c03fc9eu: goto P_0c03fc9e;
case 0x0c03fca0u: goto P_0c03fca0;
case 0x0c03fca2u: goto P_0c03fca2;
case 0x0c03fca4u: goto P_0c03fca4;
case 0x0c03fca6u: goto P_0c03fca6;
case 0x0c03fca8u: goto P_0c03fca8;
case 0x0c03fcaau: goto P_0c03fcaa;
case 0x0c03fcacu: goto P_0c03fcac;
case 0x0c03fcaeu: goto P_0c03fcae;
case 0x0c03fcb0u: goto P_0c03fcb0;
case 0x0c03fcb2u: goto P_0c03fcb2;
case 0x0c03fcb4u: goto P_0c03fcb4;
case 0x0c03fcb6u: goto P_0c03fcb6;
case 0x0c03fcb8u: goto P_0c03fcb8;
case 0x0c03fcbau: goto P_0c03fcba;
case 0x0c03fcbcu: goto P_0c03fcbc;
case 0x0c03fcbeu: goto P_0c03fcbe;
case 0x0c03fcc0u: goto P_0c03fcc0;
case 0x0c03fcc2u: goto P_0c03fcc2;
case 0x0c03fcc4u: goto P_0c03fcc4;
case 0x0c03fcc6u: goto P_0c03fcc6;
case 0x0c03fcc8u: goto P_0c03fcc8;
case 0x0c03fccau: goto P_0c03fcca;
case 0x0c03fcccu: goto P_0c03fccc;
case 0x0c03fcceu: goto P_0c03fcce;
case 0x0c03fcd0u: goto P_0c03fcd0;
case 0x0c03fcd2u: goto P_0c03fcd2;
case 0x0c03fcd4u: goto P_0c03fcd4;
case 0x0c03fcd6u: goto P_0c03fcd6;
case 0x0c03fcd8u: goto P_0c03fcd8;
case 0x0c03fcdau: goto P_0c03fcda;
case 0x0c03fcdcu: goto P_0c03fcdc;
case 0x0c03fcdeu: goto P_0c03fcde;
case 0x0c03fce0u: goto P_0c03fce0;
case 0x0c03fce2u: goto P_0c03fce2;
case 0x0c03fce4u: goto P_0c03fce4;
case 0x0c03fce6u: goto P_0c03fce6;
case 0x0c03fce8u: goto P_0c03fce8;
case 0x0c03fceau: goto P_0c03fcea;
case 0x0c03fcecu: goto P_0c03fcec;
case 0x0c03fcf0u: goto P_0c03fcf0;
case 0x0c03fcf2u: goto P_0c03fcf2;
case 0x0c03fcf4u: goto P_0c03fcf4;
case 0x0c03fcf6u: goto P_0c03fcf6;
case 0x0c03fcf8u: goto P_0c03fcf8;
case 0x0c03fcfau: goto P_0c03fcfa;
case 0x0c03fcfcu: goto P_0c03fcfc;
case 0x0c03fcfeu: goto P_0c03fcfe;
case 0x0c03fd00u: goto P_0c03fd00;
case 0x0c03fd02u: goto P_0c03fd02;
case 0x0c03fd04u: goto P_0c03fd04;
case 0x0c03fd06u: goto P_0c03fd06;
case 0x0c03fd08u: goto P_0c03fd08;
case 0x0c03fd0au: goto P_0c03fd0a;
case 0x0c03fd10u: goto P_0c03fd10;
case 0x0c03fd12u: goto P_0c03fd12;
case 0x0c03fd14u: goto P_0c03fd14;
case 0x0c03fd16u: goto P_0c03fd16;
case 0x0c03fd18u: goto P_0c03fd18;
case 0x0c03fd1au: goto P_0c03fd1a;
case 0x0c03fd1cu: goto P_0c03fd1c;
case 0x0c03fd1eu: goto P_0c03fd1e;
case 0x0c03fd20u: goto P_0c03fd20;
case 0x0c03fd22u: goto P_0c03fd22;
case 0x0c03fd24u: goto P_0c03fd24;
case 0x0c03fd26u: goto P_0c03fd26;
case 0x0c03fd28u: goto P_0c03fd28;
case 0x0c03fd2au: goto P_0c03fd2a;
case 0x0c03fd2cu: goto P_0c03fd2c;
case 0x0c03fd2eu: goto P_0c03fd2e;
case 0x0c03fd30u: goto P_0c03fd30;
case 0x0c03fd32u: goto P_0c03fd32;
case 0x0c03fd34u: goto P_0c03fd34;
case 0x0c03fd36u: goto P_0c03fd36;
case 0x0c03fd38u: goto P_0c03fd38;
case 0x0c03fd3au: goto P_0c03fd3a;
case 0x0c03fd3cu: goto P_0c03fd3c;
case 0x0c03fd3eu: goto P_0c03fd3e;
case 0x0c03fd40u: goto P_0c03fd40;
case 0x0c03fd42u: goto P_0c03fd42;
case 0x0c03fd44u: goto P_0c03fd44;
case 0x0c03fd70u: goto P_0c03fd70;
case 0x0c03fd72u: goto P_0c03fd72;
case 0x0c03fd74u: goto P_0c03fd74;
case 0x0c03fd76u: goto P_0c03fd76;
case 0x0c03fd78u: goto P_0c03fd78;
case 0x0c03fd7au: goto P_0c03fd7a;
case 0x0c03fd7cu: goto P_0c03fd7c;
case 0x0c03fd7eu: goto P_0c03fd7e;
case 0x0c03fd80u: goto P_0c03fd80;
case 0x0c03fd82u: goto P_0c03fd82;
case 0x0c03fd84u: goto P_0c03fd84;
case 0x0c03fd86u: goto P_0c03fd86;
case 0x0c03fd88u: goto P_0c03fd88;
case 0x0c03fd8au: goto P_0c03fd8a;
case 0x0c03fd8cu: goto P_0c03fd8c;
case 0x0c03fd8eu: goto P_0c03fd8e;
case 0x0c03fd90u: goto P_0c03fd90;
case 0x0c03fd92u: goto P_0c03fd92;
case 0x0c03fd94u: goto P_0c03fd94;
default: return vf3_matrix_family(target,s,ram);
}
P_0c03b300: /* original 2fe6, guest PC 0x0c03b300 */
if(!s->budget--) { s->failed_pc=0x0c03b300u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03b302;
P_0c03b302: /* original 6743, guest PC 0x0c03b302 */
if(!s->budget--) { s->failed_pc=0x0c03b302u; return 0; }
r[7]=r[4];
goto P_0c03b304;
P_0c03b304: /* original 4f22, guest PC 0x0c03b304 */
if(!s->budget--) { s->failed_pc=0x0c03b304u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c03b306;
P_0c03b306: /* original 4729, guest PC 0x0c03b306 */
if(!s->budget--) { s->failed_pc=0x0c03b306u; return 0; }
r[7]>>=16;
goto P_0c03b308;
P_0c03b308: /* original 6543, guest PC 0x0c03b308 */
if(!s->budget--) { s->failed_pc=0x0c03b308u; return 0; }
r[5]=r[4];
goto P_0c03b30a;
P_0c03b30a: /* original 4719, guest PC 0x0c03b30a */
if(!s->budget--) { s->failed_pc=0x0c03b30au; return 0; }
r[7]>>=8;
goto P_0c03b30c;
P_0c03b30c: /* original 6643, guest PC 0x0c03b30c */
if(!s->budget--) { s->failed_pc=0x0c03b30cu; return 0; }
r[6]=r[4];
goto P_0c03b30e;
P_0c03b30e: /* original 677e, guest PC 0x0c03b30e */
if(!s->budget--) { s->failed_pc=0x0c03b30eu; return 0; }
r[7]=(uint32_t)(int32_t)(int8_t)r[7];
goto P_0c03b310;
P_0c03b310: /* original 7ffc, guest PC 0x0c03b310 */
if(!s->budget--) { s->failed_pc=0x0c03b310u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c03b312;
P_0c03b312: /* original 6073, guest PC 0x0c03b312 */
if(!s->budget--) { s->failed_pc=0x0c03b312u; return 0; }
r[0]=r[7];
goto P_0c03b314;
P_0c03b314: /* original 6ef3, guest PC 0x0c03b314 */
if(!s->budget--) { s->failed_pc=0x0c03b314u; return 0; }
r[14]=r[15];
goto P_0c03b316;
P_0c03b316: /* original 4529, guest PC 0x0c03b316 */
if(!s->budget--) { s->failed_pc=0x0c03b316u; return 0; }
r[5]>>=16;
goto P_0c03b318;
P_0c03b318: /* original 80e3, guest PC 0x0c03b318 */
if(!s->budget--) { s->failed_pc=0x0c03b318u; return 0; }
write(ram,r[14]+3,r[0],1);
goto P_0c03b31a;
P_0c03b31a: /* original 655f, guest PC 0x0c03b31a */
if(!s->budget--) { s->failed_pc=0x0c03b31au; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)r[5];
goto P_0c03b31c;
P_0c03b31c: /* original 6053, guest PC 0x0c03b31c */
if(!s->budget--) { s->failed_pc=0x0c03b31cu; return 0; }
r[0]=r[5];
goto P_0c03b31e;
P_0c03b31e: /* original e3f8, guest PC 0x0c03b31e */
if(!s->budget--) { s->failed_pc=0x0c03b31eu; return 0; }
r[3]=0xfffffff8u;
goto P_0c03b320;
P_0c03b320: /* original 80e2, guest PC 0x0c03b320 */
if(!s->budget--) { s->failed_pc=0x0c03b320u; return 0; }
write(ram,r[14]+2,r[0],1);
goto P_0c03b322;
P_0c03b322: /* original 463c, guest PC 0x0c03b322 */
if(!s->budget--) { s->failed_pc=0x0c03b322u; return 0; }
r[6]=(r[3]&0x80000000u)?((r[3]&31u)?(uint32_t)((int32_t)r[6]>>((-r[3])&31u)):((int32_t)r[6]<0?0xffffffffu:0)):r[6]<<(r[3]&31u);
goto P_0c03b324;
P_0c03b324: /* original 6063, guest PC 0x0c03b324 */
if(!s->budget--) { s->failed_pc=0x0c03b324u; return 0; }
r[0]=r[6];
goto P_0c03b326;
P_0c03b326: /* original 80e1, guest PC 0x0c03b326 */
if(!s->budget--) { s->failed_pc=0x0c03b326u; return 0; }
write(ram,r[14]+1,r[0],1);
goto P_0c03b328;
P_0c03b328: /* original 2e40, guest PC 0x0c03b328 */
if(!s->budget--) { s->failed_pc=0x0c03b328u; return 0; }
write(ram,r[14],r[4],1);
goto P_0c03b32a;
P_0c03b32a: /* original 63e2, guest PC 0x0c03b32a */
if(!s->budget--) { s->failed_pc=0x0c03b32au; return 0; }
tmp=read(ram,r[14],4);
r[3]=tmp;
goto P_0c03b32c;
P_0c03b32c: /* original d21e, guest PC 0x0c03b32c */
if(!s->budget--) { s->failed_pc=0x0c03b32cu; return 0; }
r[2]=read(ram,0x0c03b3a8u,4);
goto P_0c03b32e;
P_0c03b32e: /* original 420b, guest PC 0x0c03b32e */
if(!s->budget--) { s->failed_pc=0x0c03b32eu; return 0; }
target=r[2];
r[16]=code_base|0x0c03b332u;
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c03b332u) { target=s->pc; goto dispatch; }
goto P_0c03b332;
P_0c03b330: /* original 2f36, guest PC 0x0c03b330 */
if(!s->budget--) { s->failed_pc=0x0c03b330u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03b332;
P_0c03b332: /* original 7f08, guest PC 0x0c03b332 */
if(!s->budget--) { s->failed_pc=0x0c03b332u; return 0; }
r[15]+=0x00000008u;
goto P_0c03b334;
P_0c03b334: /* original 4f26, guest PC 0x0c03b334 */
if(!s->budget--) { s->failed_pc=0x0c03b334u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c03b336;
P_0c03b336: /* original 000b, guest PC 0x0c03b336 */
if(!s->budget--) { s->failed_pc=0x0c03b336u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c03b338: /* original 6ef6, guest PC 0x0c03b338 */
if(!s->budget--) { s->failed_pc=0x0c03b338u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c03b33au,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c03b33au; return 0; } return 1;
P_0c03f5a0: /* original 2fe6, guest PC 0x0c03f5a0 */
if(!s->budget--) { s->failed_pc=0x0c03f5a0u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03f5a2;
P_0c03f5a2: /* original e300, guest PC 0x0c03f5a2 */
if(!s->budget--) { s->failed_pc=0x0c03f5a2u; return 0; }
r[3]=0x00000000u;
goto P_0c03f5a4;
P_0c03f5a4: /* original 2fd6, guest PC 0x0c03f5a4 */
if(!s->budget--) { s->failed_pc=0x0c03f5a4u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03f5a6;
P_0c03f5a6: /* original 2fc6, guest PC 0x0c03f5a6 */
if(!s->budget--) { s->failed_pc=0x0c03f5a6u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03f5a8;
P_0c03f5a8: /* original 6c43, guest PC 0x0c03f5a8 */
if(!s->budget--) { s->failed_pc=0x0c03f5a8u; return 0; }
r[12]=r[4];
goto P_0c03f5aa;
P_0c03f5aa: /* original 2fb6, guest PC 0x0c03f5aa */
if(!s->budget--) { s->failed_pc=0x0c03f5aau; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03f5ac;
P_0c03f5ac: /* original 2fa6, guest PC 0x0c03f5ac */
if(!s->budget--) { s->failed_pc=0x0c03f5acu; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03f5ae;
P_0c03f5ae: /* original 2f96, guest PC 0x0c03f5ae */
if(!s->budget--) { s->failed_pc=0x0c03f5aeu; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03f5b0;
P_0c03f5b0: /* original 2f86, guest PC 0x0c03f5b0 */
if(!s->budget--) { s->failed_pc=0x0c03f5b0u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03f5b2;
P_0c03f5b2: /* original 4f22, guest PC 0x0c03f5b2 */
if(!s->budget--) { s->failed_pc=0x0c03f5b2u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c03f5b4;
P_0c03f5b4: /* original 4f12, guest PC 0x0c03f5b4 */
if(!s->budget--) { s->failed_pc=0x0c03f5b4u; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c03f5b6;
P_0c03f5b6: /* original 7ffc, guest PC 0x0c03f5b6 */
if(!s->budget--) { s->failed_pc=0x0c03f5b6u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c03f5b8;
P_0c03f5b8: /* original 2f32, guest PC 0x0c03f5b8 */
if(!s->budget--) { s->failed_pc=0x0c03f5b8u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c03f5ba;
P_0c03f5ba: /* original d37a, guest PC 0x0c03f5ba */
if(!s->budget--) { s->failed_pc=0x0c03f5bau; return 0; }
r[3]=read(ram,0x0c03f7a4u,4);
goto P_0c03f5bc;
P_0c03f5bc: /* original de78, guest PC 0x0c03f5bc */
if(!s->budget--) { s->failed_pc=0x0c03f5bcu; return 0; }
r[14]=read(ram,0x0c03f7a0u,4);
goto P_0c03f5be;
P_0c03f5be: /* original d974, guest PC 0x0c03f5be */
if(!s->budget--) { s->failed_pc=0x0c03f5beu; return 0; }
r[9]=read(ram,0x0c03f790u,4);
goto P_0c03f5c0;
P_0c03f5c0: /* original a052, guest PC 0x0c03f5c0 */
if(!s->budget--) { s->failed_pc=0x0c03f5c0u; return 0; }
tmp=read(ram,r[3],4);
r[11]=tmp;
goto P_0c03f668;
P_0c03f5c2: /* original 6b32, guest PC 0x0c03f5c2 */
if(!s->budget--) { s->failed_pc=0x0c03f5c2u; return 0; }
tmp=read(ram,r[3],4);
r[11]=tmp;
if(!vf3_matrix_family(0x0c03f5c4u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c03f5c4u; return 0; } return 1;
P_0c03f5d0: /* original 6db3, guest PC 0x0c03f5d0 */
if(!s->budget--) { s->failed_pc=0x0c03f5d0u; return 0; }
r[13]=r[11];
goto P_0c03f5d2;
P_0c03f5d2: /* original 63e2, guest PC 0x0c03f5d2 */
if(!s->budget--) { s->failed_pc=0x0c03f5d2u; return 0; }
tmp=read(ram,r[14],4);
r[3]=tmp;
goto P_0c03f5d4;
P_0c03f5d4: /* original 4d08, guest PC 0x0c03f5d4 */
if(!s->budget--) { s->failed_pc=0x0c03f5d4u; return 0; }
r[13]<<=2;
goto P_0c03f5d6;
P_0c03f5d6: /* original 4d00, guest PC 0x0c03f5d6 */
if(!s->budget--) { s->failed_pc=0x0c03f5d6u; return 0; }
r[17]=(r[17]&~1u)|((r[13]>>31)!=0);
r[13]<<=1;
goto P_0c03f5d8;
P_0c03f5d8: /* original 33dc, guest PC 0x0c03f5d8 */
if(!s->budget--) { s->failed_pc=0x0c03f5d8u; return 0; }
r[3]+=r[13];
goto P_0c03f5da;
P_0c03f5da: /* original 6232, guest PC 0x0c03f5da */
if(!s->budget--) { s->failed_pc=0x0c03f5dau; return 0; }
tmp=read(ram,r[3],4);
r[2]=tmp;
goto P_0c03f5dc;
P_0c03f5dc: /* original 2228, guest PC 0x0c03f5dc */
if(!s->budget--) { s->failed_pc=0x0c03f5dcu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c03f5de;
P_0c03f5de: /* original 8f09, guest PC 0x0c03f5de */
if(!s->budget--) { s->failed_pc=0x0c03f5deu; return 0; }
cond=r[17]&1u;
r[4]=r[11];
if(!cond) { goto P_0c03f5f4; }
goto P_0c03f5e2;
P_0c03f5e0: /* original 64b3, guest PC 0x0c03f5e0 */
if(!s->budget--) { s->failed_pc=0x0c03f5e0u; return 0; }
r[4]=r[11];
goto P_0c03f5e2;
P_0c03f5e2: /* original 62e2, guest PC 0x0c03f5e2 */
if(!s->budget--) { s->failed_pc=0x0c03f5e2u; return 0; }
tmp=read(ram,r[14],4);
r[2]=tmp;
goto P_0c03f5e4;
P_0c03f5e4: /* original e104, guest PC 0x0c03f5e4 */
if(!s->budget--) { s->failed_pc=0x0c03f5e4u; return 0; }
r[1]=0x00000004u;
goto P_0c03f5e6;
P_0c03f5e6: /* original d370, guest PC 0x0c03f5e6 */
if(!s->budget--) { s->failed_pc=0x0c03f5e6u; return 0; }
r[3]=read(ram,0x0c03f7a8u,4);
goto P_0c03f5e8;
P_0c03f5e8: /* original 32dc, guest PC 0x0c03f5e8 */
if(!s->budget--) { s->failed_pc=0x0c03f5e8u; return 0; }
r[2]+=r[13];
goto P_0c03f5ea;
P_0c03f5ea: /* original 312c, guest PC 0x0c03f5ea */
if(!s->budget--) { s->failed_pc=0x0c03f5eau; return 0; }
r[1]+=r[2];
goto P_0c03f5ec;
P_0c03f5ec: /* original 430b, guest PC 0x0c03f5ec */
if(!s->budget--) { s->failed_pc=0x0c03f5ecu; return 0; }
target=r[3];
r[16]=code_base|0x0c03f5f0u;
tmp=r[1]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c03f5f0u) { target=s->pc; goto dispatch; }
goto P_0c03f5f0;
P_0c03f5ee: /* original 2f16, guest PC 0x0c03f5ee */
if(!s->budget--) { s->failed_pc=0x0c03f5eeu; return 0; }
tmp=r[1]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03f5f0;
P_0c03f5f0: /* original 63f6, guest PC 0x0c03f5f0 */
if(!s->budget--) { s->failed_pc=0x0c03f5f0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[3]=tmp;
goto P_0c03f5f2;
P_0c03f5f2: /* original 2302, guest PC 0x0c03f5f2 */
if(!s->budget--) { s->failed_pc=0x0c03f5f2u; return 0; }
write(ram,r[3],r[0],4);
goto P_0c03f5f4;
P_0c03f5f4: /* original 62e2, guest PC 0x0c03f5f4 */
if(!s->budget--) { s->failed_pc=0x0c03f5f4u; return 0; }
tmp=read(ram,r[14],4);
r[2]=tmp;
goto P_0c03f5f6;
P_0c03f5f6: /* original ea3c, guest PC 0x0c03f5f6 */
if(!s->budget--) { s->failed_pc=0x0c03f5f6u; return 0; }
r[10]=0x0000003cu;
goto P_0c03f5f8;
P_0c03f5f8: /* original 68b3, guest PC 0x0c03f5f8 */
if(!s->budget--) { s->failed_pc=0x0c03f5f8u; return 0; }
r[8]=r[11];
goto P_0c03f5fa;
P_0c03f5fa: /* original 4800, guest PC 0x0c03f5fa */
if(!s->budget--) { s->failed_pc=0x0c03f5fau; return 0; }
r[17]=(r[17]&~1u)|((r[8]>>31)!=0);
r[8]<<=1;
goto P_0c03f5fc;
P_0c03f5fc: /* original 32dc, guest PC 0x0c03f5fc */
if(!s->budget--) { s->failed_pc=0x0c03f5fcu; return 0; }
r[2]+=r[13];
goto P_0c03f5fe;
P_0c03f5fe: /* original 6322, guest PC 0x0c03f5fe */
if(!s->budget--) { s->failed_pc=0x0c03f5feu; return 0; }
tmp=read(ram,r[2],4);
r[3]=tmp;
goto P_0c03f600;
P_0c03f600: /* original 7301, guest PC 0x0c03f600 */
if(!s->budget--) { s->failed_pc=0x0c03f600u; return 0; }
r[3]+=0x00000001u;
goto P_0c03f602;
P_0c03f602: /* original 2232, guest PC 0x0c03f602 */
if(!s->budget--) { s->failed_pc=0x0c03f602u; return 0; }
write(ram,r[2],r[3],4);
goto P_0c03f604;
P_0c03f604: /* original 62e2, guest PC 0x0c03f604 */
if(!s->budget--) { s->failed_pc=0x0c03f604u; return 0; }
tmp=read(ram,r[14],4);
r[2]=tmp;
goto P_0c03f606;
P_0c03f606: /* original 6192, guest PC 0x0c03f606 */
if(!s->budget--) { s->failed_pc=0x0c03f606u; return 0; }
tmp=read(ram,r[9],4);
r[1]=tmp;
goto P_0c03f608;
P_0c03f608: /* original 32dc, guest PC 0x0c03f608 */
if(!s->budget--) { s->failed_pc=0x0c03f608u; return 0; }
r[2]+=r[13];
goto P_0c03f60a;
P_0c03f60a: /* original 5d21, guest PC 0x0c03f60a */
if(!s->budget--) { s->failed_pc=0x0c03f60au; return 0; }
r[13]=read(ram,r[2]+4,4);
goto P_0c03f60c;
P_0c03f60c: /* original 381c, guest PC 0x0c03f60c */
if(!s->budget--) { s->failed_pc=0x0c03f60cu; return 0; }
r[8]+=r[1];
goto P_0c03f60e;
P_0c03f60e: /* original d267, guest PC 0x0c03f60e */
if(!s->budget--) { s->failed_pc=0x0c03f60eu; return 0; }
r[2]=read(ram,0x0c03f7acu,4);
goto P_0c03f610;
P_0c03f610: /* original 0da7, guest PC 0x0c03f610 */
if(!s->budget--) { s->failed_pc=0x0c03f610u; return 0; }
r[19]=r[13]*r[10];
goto P_0c03f612;
P_0c03f612: /* original 6081, guest PC 0x0c03f612 */
if(!s->budget--) { s->failed_pc=0x0c03f612u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[8],2);
r[0]=tmp;
goto P_0c03f614;
P_0c03f614: /* original 6322, guest PC 0x0c03f614 */
if(!s->budget--) { s->failed_pc=0x0c03f614u; return 0; }
tmp=read(ram,r[2],4);
r[3]=tmp;
goto P_0c03f616;
P_0c03f616: /* original 88ff, guest PC 0x0c03f616 */
if(!s->budget--) { s->failed_pc=0x0c03f616u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xffffffffu)!=0);
goto P_0c03f618;
P_0c03f618: /* original 0a1a, guest PC 0x0c03f618 */
if(!s->budget--) { s->failed_pc=0x0c03f618u; return 0; }
r[10]=r[19];
goto P_0c03f61a;
P_0c03f61a: /* original 8f03, guest PC 0x0c03f61a */
if(!s->budget--) { s->failed_pc=0x0c03f61au; return 0; }
cond=r[17]&1u;
r[10]+=r[3];
if(!cond) { goto P_0c03f624; }
goto P_0c03f61e;
P_0c03f61c: /* original 3a3c, guest PC 0x0c03f61c */
if(!s->budget--) { s->failed_pc=0x0c03f61cu; return 0; }
r[10]+=r[3];
goto P_0c03f61e;
P_0c03f61e: /* original b367, guest PC 0x0c03f61e */
if(!s->budget--) { s->failed_pc=0x0c03f61eu; return 0; }
target=code_base|0x0c03fcf0u; r[16]=code_base|0x0c03f622u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c03f622u) { target=s->pc; goto dispatch; }
goto P_0c03f622;
P_0c03f620: /* original 0009, guest PC 0x0c03f620 */
if(!s->budget--) { s->failed_pc=0x0c03f620u; return 0; }
goto P_0c03f622;
P_0c03f622: /* original 2801, guest PC 0x0c03f622 */
if(!s->budget--) { s->failed_pc=0x0c03f622u; return 0; }
write(ram,r[8],r[0],2);
goto P_0c03f624;
P_0c03f624: /* original 60b3, guest PC 0x0c03f624 */
if(!s->budget--) { s->failed_pc=0x0c03f624u; return 0; }
r[0]=r[11];
goto P_0c03f626;
P_0c03f626: /* original 0009, guest PC 0x0c03f626 */
if(!s->budget--) { s->failed_pc=0x0c03f626u; return 0; }
goto P_0c03f628;
P_0c03f628: /* original 6392, guest PC 0x0c03f628 */
if(!s->budget--) { s->failed_pc=0x0c03f628u; return 0; }
tmp=read(ram,r[9],4);
r[3]=tmp;
goto P_0c03f62a;
P_0c03f62a: /* original 4000, guest PC 0x0c03f62a */
if(!s->budget--) { s->failed_pc=0x0c03f62au; return 0; }
r[17]=(r[17]&~1u)|((r[0]>>31)!=0);
r[0]<<=1;
goto P_0c03f62c;
P_0c03f62c: /* original 083d, guest PC 0x0c03f62c */
if(!s->budget--) { s->failed_pc=0x0c03f62cu; return 0; }
r[8]=(uint32_t)(int32_t)(int16_t)read(ram,r[3]+r[0],2);
goto P_0c03f62e;
P_0c03f62e: /* original 53ab, guest PC 0x0c03f62e */
if(!s->budget--) { s->failed_pc=0x0c03f62eu; return 0; }
r[3]=read(ram,r[10]+44,4);
goto P_0c03f630;
P_0c03f630: /* original 2338, guest PC 0x0c03f630 */
if(!s->budget--) { s->failed_pc=0x0c03f630u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c03f632;
P_0c03f632: /* original 8b0b, guest PC 0x0c03f632 */
if(!s->budget--) { s->failed_pc=0x0c03f632u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c03f64c; }
goto P_0c03f634;
P_0c03f634: /* original d35e, guest PC 0x0c03f634 */
if(!s->budget--) { s->failed_pc=0x0c03f634u; return 0; }
r[3]=read(ram,0x0c03f7b0u,4);
goto P_0c03f636;
P_0c03f636: /* original 65d3, guest PC 0x0c03f636 */
if(!s->budget--) { s->failed_pc=0x0c03f636u; return 0; }
r[5]=r[13];
goto P_0c03f638;
P_0c03f638: /* original 56c2, guest PC 0x0c03f638 */
if(!s->budget--) { s->failed_pc=0x0c03f638u; return 0; }
r[6]=read(ram,r[12]+8,4);
goto P_0c03f63a;
P_0c03f63a: /* original 430b, guest PC 0x0c03f63a */
if(!s->budget--) { s->failed_pc=0x0c03f63au; return 0; }
target=r[3];
r[16]=code_base|0x0c03f63eu;
r[4]=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c03f63eu) { target=s->pc; goto dispatch; }
goto P_0c03f63e;
P_0c03f63c: /* original 64c3, guest PC 0x0c03f63c */
if(!s->budget--) { s->failed_pc=0x0c03f63cu; return 0; }
r[4]=r[12];
goto P_0c03f63e;
P_0c03f63e: /* original 62f2, guest PC 0x0c03f63e */
if(!s->budget--) { s->failed_pc=0x0c03f63eu; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c03f640;
P_0c03f640: /* original 220b, guest PC 0x0c03f640 */
if(!s->budget--) { s->failed_pc=0x0c03f640u; return 0; }
r[2]|=r[0];
goto P_0c03f642;
P_0c03f642: /* original 2f22, guest PC 0x0c03f642 */
if(!s->budget--) { s->failed_pc=0x0c03f642u; return 0; }
write(ram,r[15],r[2],4);
goto P_0c03f644;
P_0c03f644: /* original d35b, guest PC 0x0c03f644 */
if(!s->budget--) { s->failed_pc=0x0c03f644u; return 0; }
r[3]=read(ram,0x0c03f7b4u,4);
goto P_0c03f646;
P_0c03f646: /* original 430b, guest PC 0x0c03f646 */
if(!s->budget--) { s->failed_pc=0x0c03f646u; return 0; }
target=r[3];
r[16]=code_base|0x0c03f64au;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c03f64au) { target=s->pc; goto dispatch; }
goto P_0c03f64a;
P_0c03f648: /* original 64d3, guest PC 0x0c03f648 */
if(!s->budget--) { s->failed_pc=0x0c03f648u; return 0; }
r[4]=r[13];
goto P_0c03f64a;
P_0c03f64a: /* original 1ade, guest PC 0x0c03f64a */
if(!s->budget--) { s->failed_pc=0x0c03f64au; return 0; }
write(ram,r[10]+56,r[13],4);
goto P_0c03f64c;
P_0c03f64c: /* original d253, guest PC 0x0c03f64c */
if(!s->budget--) { s->failed_pc=0x0c03f64cu; return 0; }
r[2]=read(ram,0x0c03f79cu,4);
goto P_0c03f64e;
P_0c03f64e: /* original 6483, guest PC 0x0c03f64e */
if(!s->budget--) { s->failed_pc=0x0c03f64eu; return 0; }
r[4]=r[8];
goto P_0c03f650;
P_0c03f650: /* original 4408, guest PC 0x0c03f650 */
if(!s->budget--) { s->failed_pc=0x0c03f650u; return 0; }
r[4]<<=2;
goto P_0c03f652;
P_0c03f652: /* original 65d3, guest PC 0x0c03f652 */
if(!s->budget--) { s->failed_pc=0x0c03f652u; return 0; }
r[5]=r[13];
goto P_0c03f654;
P_0c03f654: /* original 6322, guest PC 0x0c03f654 */
if(!s->budget--) { s->failed_pc=0x0c03f654u; return 0; }
tmp=read(ram,r[2],4);
r[3]=tmp;
goto P_0c03f656;
P_0c03f656: /* original 4408, guest PC 0x0c03f656 */
if(!s->budget--) { s->failed_pc=0x0c03f656u; return 0; }
r[4]<<=2;
goto P_0c03f658;
P_0c03f658: /* original 4400, guest PC 0x0c03f658 */
if(!s->budget--) { s->failed_pc=0x0c03f658u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c03f65a;
P_0c03f65a: /* original b319, guest PC 0x0c03f65a */
if(!s->budget--) { s->failed_pc=0x0c03f65au; return 0; }
target=code_base|0x0c03fc90u; r[16]=code_base|0x0c03f65eu;
r[4]+=r[3];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c03f65eu) { target=s->pc; goto dispatch; }
goto P_0c03f65e;
P_0c03f65c: /* original 343c, guest PC 0x0c03f65c */
if(!s->budget--) { s->failed_pc=0x0c03f65cu; return 0; }
r[4]+=r[3];
goto P_0c03f65e;
P_0c03f65e: /* original 53ab, guest PC 0x0c03f65e */
if(!s->budget--) { s->failed_pc=0x0c03f65eu; return 0; }
r[3]=read(ram,r[10]+44,4);
goto P_0c03f660;
P_0c03f660: /* original 7b01, guest PC 0x0c03f660 */
if(!s->budget--) { s->failed_pc=0x0c03f660u; return 0; }
r[11]+=0x00000001u;
goto P_0c03f662;
P_0c03f662: /* original 7c10, guest PC 0x0c03f662 */
if(!s->budget--) { s->failed_pc=0x0c03f662u; return 0; }
r[12]+=0x00000010u;
goto P_0c03f664;
P_0c03f664: /* original 7301, guest PC 0x0c03f664 */
if(!s->budget--) { s->failed_pc=0x0c03f664u; return 0; }
r[3]+=0x00000001u;
goto P_0c03f666;
P_0c03f666: /* original 1a3b, guest PC 0x0c03f666 */
if(!s->budget--) { s->failed_pc=0x0c03f666u; return 0; }
write(ram,r[10]+44,r[3],4);
goto P_0c03f668;
P_0c03f668: /* original 50c1, guest PC 0x0c03f668 */
if(!s->budget--) { s->failed_pc=0x0c03f668u; return 0; }
r[0]=read(ram,r[12]+4,4);
goto P_0c03f66a;
P_0c03f66a: /* original 88ff, guest PC 0x0c03f66a */
if(!s->budget--) { s->failed_pc=0x0c03f66au; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xffffffffu)!=0);
goto P_0c03f66c;
P_0c03f66c: /* original 8bb0, guest PC 0x0c03f66c */
if(!s->budget--) { s->failed_pc=0x0c03f66cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c03f5d0; }
goto P_0c03f66e;
P_0c03f66e: /* original 60f2, guest PC 0x0c03f66e */
if(!s->budget--) { s->failed_pc=0x0c03f66eu; return 0; }
tmp=read(ram,r[15],4);
r[0]=tmp;
goto P_0c03f670;
P_0c03f670: /* original 7f04, guest PC 0x0c03f670 */
if(!s->budget--) { s->failed_pc=0x0c03f670u; return 0; }
r[15]+=0x00000004u;
goto P_0c03f672;
P_0c03f672: /* original 4f16, guest PC 0x0c03f672 */
if(!s->budget--) { s->failed_pc=0x0c03f672u; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c03f674;
P_0c03f674: /* original 4f26, guest PC 0x0c03f674 */
if(!s->budget--) { s->failed_pc=0x0c03f674u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c03f676;
P_0c03f676: /* original 68f6, guest PC 0x0c03f676 */
if(!s->budget--) { s->failed_pc=0x0c03f676u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c03f678;
P_0c03f678: /* original 69f6, guest PC 0x0c03f678 */
if(!s->budget--) { s->failed_pc=0x0c03f678u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c03f67a;
P_0c03f67a: /* original 6af6, guest PC 0x0c03f67a */
if(!s->budget--) { s->failed_pc=0x0c03f67au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c03f67c;
P_0c03f67c: /* original 6bf6, guest PC 0x0c03f67c */
if(!s->budget--) { s->failed_pc=0x0c03f67cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c03f67e;
P_0c03f67e: /* original 6cf6, guest PC 0x0c03f67e */
if(!s->budget--) { s->failed_pc=0x0c03f67eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c03f680;
P_0c03f680: /* original 6df6, guest PC 0x0c03f680 */
if(!s->budget--) { s->failed_pc=0x0c03f680u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c03f682;
P_0c03f682: /* original 000b, guest PC 0x0c03f682 */
if(!s->budget--) { s->failed_pc=0x0c03f682u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c03f684: /* original 6ef6, guest PC 0x0c03f684 */
if(!s->budget--) { s->failed_pc=0x0c03f684u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c03f686u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c03f686u; return 0; } return 1;
P_0c03fc90: /* original 2fe6, guest PC 0x0c03fc90 */
if(!s->budget--) { s->failed_pc=0x0c03fc90u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03fc92;
P_0c03fc92: /* original 6e43, guest PC 0x0c03fc92 */
if(!s->budget--) { s->failed_pc=0x0c03fc92u; return 0; }
r[14]=r[4];
goto P_0c03fc94;
P_0c03fc94: /* original d32d, guest PC 0x0c03fc94 */
if(!s->budget--) { s->failed_pc=0x0c03fc94u; return 0; }
r[3]=read(ram,0x0c03fd4cu,4);
goto P_0c03fc96;
P_0c03fc96: /* original 4f22, guest PC 0x0c03fc96 */
if(!s->budget--) { s->failed_pc=0x0c03fc96u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c03fc98;
P_0c03fc98: /* original 2e32, guest PC 0x0c03fc98 */
if(!s->budget--) { s->failed_pc=0x0c03fc98u; return 0; }
write(ram,r[14],r[3],4);
goto P_0c03fc9a;
P_0c03fc9a: /* original d22d, guest PC 0x0c03fc9a */
if(!s->budget--) { s->failed_pc=0x0c03fc9au; return 0; }
r[2]=read(ram,0x0c03fd50u,4);
goto P_0c03fc9c;
P_0c03fc9c: /* original 1e21, guest PC 0x0c03fc9c */
if(!s->budget--) { s->failed_pc=0x0c03fc9cu; return 0; }
write(ram,r[14]+4,r[2],4);
goto P_0c03fc9e;
P_0c03fc9e: /* original e200, guest PC 0x0c03fc9e */
if(!s->budget--) { s->failed_pc=0x0c03fc9eu; return 0; }
r[2]=0x00000000u;
goto P_0c03fca0;
P_0c03fca0: /* original 9352, guest PC 0x0c03fca0 */
if(!s->budget--) { s->failed_pc=0x0c03fca0u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c03fd48u,2);
goto P_0c03fca2;
P_0c03fca2: /* original 1e32, guest PC 0x0c03fca2 */
if(!s->budget--) { s->failed_pc=0x0c03fca2u; return 0; }
write(ram,r[14]+8,r[3],4);
goto P_0c03fca4;
P_0c03fca4: /* original 1e23, guest PC 0x0c03fca4 */
if(!s->budget--) { s->failed_pc=0x0c03fca4u; return 0; }
write(ram,r[14]+12,r[2],4);
goto P_0c03fca6;
P_0c03fca6: /* original d32b, guest PC 0x0c03fca6 */
if(!s->budget--) { s->failed_pc=0x0c03fca6u; return 0; }
r[3]=read(ram,0x0c03fd54u,4);
goto P_0c03fca8;
P_0c03fca8: /* original 430b, guest PC 0x0c03fca8 */
if(!s->budget--) { s->failed_pc=0x0c03fca8u; return 0; }
target=r[3];
r[16]=code_base|0x0c03fcacu;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c03fcacu) { target=s->pc; goto dispatch; }
goto P_0c03fcac;
P_0c03fcaa: /* original 64e3, guest PC 0x0c03fcaa */
if(!s->budget--) { s->failed_pc=0x0c03fcaau; return 0; }
r[4]=r[14];
goto P_0c03fcac;
P_0c03fcac: /* original 55e3, guest PC 0x0c03fcac */
if(!s->budget--) { s->failed_pc=0x0c03fcacu; return 0; }
r[5]=read(ram,r[14]+12,4);
goto P_0c03fcae;
P_0c03fcae: /* original e3e5, guest PC 0x0c03fcae */
if(!s->budget--) { s->failed_pc=0x0c03fcaeu; return 0; }
r[3]=0xffffffe5u;
goto P_0c03fcb0;
P_0c03fcb0: /* original e407, guest PC 0x0c03fcb0 */
if(!s->budget--) { s->failed_pc=0x0c03fcb0u; return 0; }
r[4]=0x00000007u;
goto P_0c03fcb2;
P_0c03fcb2: /* original 453d, guest PC 0x0c03fcb2 */
if(!s->budget--) { s->failed_pc=0x0c03fcb2u; return 0; }
r[5]=(r[3]&0x80000000u)?((r[3]&31u)?r[5]>>((-r[3])&31u):0):r[5]<<(r[3]&31u);
goto P_0c03fcb4;
P_0c03fcb4: /* original 2549, guest PC 0x0c03fcb4 */
if(!s->budget--) { s->failed_pc=0x0c03fcb4u; return 0; }
r[5]&=r[4];
goto P_0c03fcb6;
P_0c03fcb6: /* original 2558, guest PC 0x0c03fcb6 */
if(!s->budget--) { s->failed_pc=0x0c03fcb6u; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[5])==0)!=0);
goto P_0c03fcb8;
P_0c03fcb8: /* original e200, guest PC 0x0c03fcb8 */
if(!s->budget--) { s->failed_pc=0x0c03fcb8u; return 0; }
r[2]=0x00000000u;
goto P_0c03fcba;
P_0c03fcba: /* original 8d04, guest PC 0x0c03fcba */
if(!s->budget--) { s->failed_pc=0x0c03fcbau; return 0; }
cond=r[17]&1u;
write(ram,r[14]+20,r[2],4);
if(cond) { goto P_0c03fcc6; }
goto P_0c03fcbe;
P_0c03fcbc: /* original 1e25, guest PC 0x0c03fcbc */
if(!s->budget--) { s->failed_pc=0x0c03fcbcu; return 0; }
write(ram,r[14]+20,r[2],4);
goto P_0c03fcbe;
P_0c03fcbe: /* original 6053, guest PC 0x0c03fcbe */
if(!s->budget--) { s->failed_pc=0x0c03fcbeu; return 0; }
r[0]=r[5];
goto P_0c03fcc0;
P_0c03fcc0: /* original 0009, guest PC 0x0c03fcc0 */
if(!s->budget--) { s->failed_pc=0x0c03fcc0u; return 0; }
goto P_0c03fcc2;
P_0c03fcc2: /* original 8802, guest PC 0x0c03fcc2 */
if(!s->budget--) { s->failed_pc=0x0c03fcc2u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c03fcc4;
P_0c03fcc4: /* original 8b01, guest PC 0x0c03fcc4 */
if(!s->budget--) { s->failed_pc=0x0c03fcc4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c03fcca; }
goto P_0c03fcc6;
P_0c03fcc6: /* original e301, guest PC 0x0c03fcc6 */
if(!s->budget--) { s->failed_pc=0x0c03fcc6u; return 0; }
r[3]=0x00000001u;
goto P_0c03fcc8;
P_0c03fcc8: /* original 1e35, guest PC 0x0c03fcc8 */
if(!s->budget--) { s->failed_pc=0x0c03fcc8u; return 0; }
write(ram,r[14]+20,r[3],4);
goto P_0c03fcca;
P_0c03fcca: /* original 50e2, guest PC 0x0c03fcca */
if(!s->budget--) { s->failed_pc=0x0c03fccau; return 0; }
r[0]=read(ram,r[14]+8,4);
goto P_0c03fccc;
P_0c03fccc: /* original d522, guest PC 0x0c03fccc */
if(!s->budget--) { s->failed_pc=0x0c03fcccu; return 0; }
r[5]=read(ram,0x0c03fd58u,4);
goto P_0c03fcce;
P_0c03fcce: /* original 4009, guest PC 0x0c03fcce */
if(!s->budget--) { s->failed_pc=0x0c03fcceu; return 0; }
r[0]>>=2;
goto P_0c03fcd0;
P_0c03fcd0: /* original 4001, guest PC 0x0c03fcd0 */
if(!s->budget--) { s->failed_pc=0x0c03fcd0u; return 0; }
r[17]=(r[17]&~1u)|((r[0]&1)!=0);
r[0]>>=1;
goto P_0c03fcd2;
P_0c03fcd2: /* original 2049, guest PC 0x0c03fcd2 */
if(!s->budget--) { s->failed_pc=0x0c03fcd2u; return 0; }
r[0]&=r[4];
goto P_0c03fcd4;
P_0c03fcd4: /* original 4008, guest PC 0x0c03fcd4 */
if(!s->budget--) { s->failed_pc=0x0c03fcd4u; return 0; }
r[0]<<=2;
goto P_0c03fcd6;
P_0c03fcd6: /* original f356, guest PC 0x0c03fcd6 */
if(!s->budget--) { s->failed_pc=0x0c03fcd6u; return 0; }
vf3_matrix_load(s,ram,3,r[5]+r[0]);
goto P_0c03fcd8;
P_0c03fcd8: /* original e018, guest PC 0x0c03fcd8 */
if(!s->budget--) { s->failed_pc=0x0c03fcd8u; return 0; }
r[0]=0x00000018u;
goto P_0c03fcda;
P_0c03fcda: /* original 4f26, guest PC 0x0c03fcda */
if(!s->budget--) { s->failed_pc=0x0c03fcdau; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c03fcdc;
P_0c03fcdc: /* original fe37, guest PC 0x0c03fcdc */
if(!s->budget--) { s->failed_pc=0x0c03fcdcu; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c03fcde;
P_0c03fcde: /* original 50e2, guest PC 0x0c03fcde */
if(!s->budget--) { s->failed_pc=0x0c03fcdeu; return 0; }
r[0]=read(ram,r[14]+8,4);
goto P_0c03fce0;
P_0c03fce0: /* original 2049, guest PC 0x0c03fce0 */
if(!s->budget--) { s->failed_pc=0x0c03fce0u; return 0; }
r[0]&=r[4];
goto P_0c03fce2;
P_0c03fce2: /* original 4008, guest PC 0x0c03fce2 */
if(!s->budget--) { s->failed_pc=0x0c03fce2u; return 0; }
r[0]<<=2;
goto P_0c03fce4;
P_0c03fce4: /* original f356, guest PC 0x0c03fce4 */
if(!s->budget--) { s->failed_pc=0x0c03fce4u; return 0; }
vf3_matrix_load(s,ram,3,r[5]+r[0]);
goto P_0c03fce6;
P_0c03fce6: /* original e01c, guest PC 0x0c03fce6 */
if(!s->budget--) { s->failed_pc=0x0c03fce6u; return 0; }
r[0]=0x0000001cu;
goto P_0c03fce8;
P_0c03fce8: /* original fe37, guest PC 0x0c03fce8 */
if(!s->budget--) { s->failed_pc=0x0c03fce8u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c03fcea;
P_0c03fcea: /* original 000b, guest PC 0x0c03fcea */
if(!s->budget--) { s->failed_pc=0x0c03fceau; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c03fcec: /* original 6ef6, guest PC 0x0c03fcec */
if(!s->budget--) { s->failed_pc=0x0c03fcecu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c03fceeu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c03fceeu; return 0; } return 1;
P_0c03fcf0: /* original 2fe6, guest PC 0x0c03fcf0 */
if(!s->budget--) { s->failed_pc=0x0c03fcf0u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03fcf2;
P_0c03fcf2: /* original 2fd6, guest PC 0x0c03fcf2 */
if(!s->budget--) { s->failed_pc=0x0c03fcf2u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03fcf4;
P_0c03fcf4: /* original 2fb6, guest PC 0x0c03fcf4 */
if(!s->budget--) { s->failed_pc=0x0c03fcf4u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03fcf6;
P_0c03fcf6: /* original eb00, guest PC 0x0c03fcf6 */
if(!s->budget--) { s->failed_pc=0x0c03fcf6u; return 0; }
r[11]=0x00000000u;
goto P_0c03fcf8;
P_0c03fcf8: /* original 2fa6, guest PC 0x0c03fcf8 */
if(!s->budget--) { s->failed_pc=0x0c03fcf8u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03fcfa;
P_0c03fcfa: /* original ea01, guest PC 0x0c03fcfa */
if(!s->budget--) { s->failed_pc=0x0c03fcfau; return 0; }
r[10]=0x00000001u;
goto P_0c03fcfc;
P_0c03fcfc: /* original 2f96, guest PC 0x0c03fcfc */
if(!s->budget--) { s->failed_pc=0x0c03fcfcu; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03fcfe;
P_0c03fcfe: /* original e920, guest PC 0x0c03fcfe */
if(!s->budget--) { s->failed_pc=0x0c03fcfeu; return 0; }
r[9]=0x00000020u;
goto P_0c03fd00;
P_0c03fd00: /* original 2f86, guest PC 0x0c03fd00 */
if(!s->budget--) { s->failed_pc=0x0c03fd00u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03fd02;
P_0c03fd02: /* original 4f22, guest PC 0x0c03fd02 */
if(!s->budget--) { s->failed_pc=0x0c03fd02u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c03fd04;
P_0c03fd04: /* original d716, guest PC 0x0c03fd04 */
if(!s->budget--) { s->failed_pc=0x0c03fd04u; return 0; }
r[7]=read(ram,0x0c03fd60u,4);
goto P_0c03fd06;
P_0c03fd06: /* original d815, guest PC 0x0c03fd06 */
if(!s->budget--) { s->failed_pc=0x0c03fd06u; return 0; }
r[8]=read(ram,0x0c03fd5cu,4);
goto P_0c03fd08;
P_0c03fd08: /* original a033, guest PC 0x0c03fd08 */
if(!s->budget--) { s->failed_pc=0x0c03fd08u; return 0; }
r[5]=r[11];
goto P_0c03fd72;
P_0c03fd0a: /* original 65b3, guest PC 0x0c03fd0a */
if(!s->budget--) { s->failed_pc=0x0c03fd0au; return 0; }
r[5]=r[11];
if(!vf3_matrix_family(0x0c03fd0cu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c03fd0cu; return 0; } return 1;
P_0c03fd10: /* original 6072, guest PC 0x0c03fd10 */
if(!s->budget--) { s->failed_pc=0x0c03fd10u; return 0; }
tmp=read(ram,r[7],4);
r[0]=tmp;
goto P_0c03fd12;
P_0c03fd12: /* original 6e53, guest PC 0x0c03fd12 */
if(!s->budget--) { s->failed_pc=0x0c03fd12u; return 0; }
r[14]=r[5];
goto P_0c03fd14;
P_0c03fd14: /* original 4e08, guest PC 0x0c03fd14 */
if(!s->budget--) { s->failed_pc=0x0c03fd14u; return 0; }
r[14]<<=2;
goto P_0c03fd16;
P_0c03fd16: /* original 00ee, guest PC 0x0c03fd16 */
if(!s->budget--) { s->failed_pc=0x0c03fd16u; return 0; }
r[0]=read(ram,r[14]+r[0],4);
goto P_0c03fd18;
P_0c03fd18: /* original 88ff, guest PC 0x0c03fd18 */
if(!s->budget--) { s->failed_pc=0x0c03fd18u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xffffffffu)!=0);
goto P_0c03fd1a;
P_0c03fd1a: /* original 8d29, guest PC 0x0c03fd1a */
if(!s->budget--) { s->failed_pc=0x0c03fd1au; return 0; }
cond=r[17]&1u;
r[13]=r[0];
if(cond) { goto P_0c03fd70; }
goto P_0c03fd1e;
P_0c03fd1c: /* original 6d03, guest PC 0x0c03fd1c */
if(!s->budget--) { s->failed_pc=0x0c03fd1cu; return 0; }
r[13]=r[0];
goto P_0c03fd1e;
P_0c03fd1e: /* original 6153, guest PC 0x0c03fd1e */
if(!s->budget--) { s->failed_pc=0x0c03fd1eu; return 0; }
r[1]=r[5];
goto P_0c03fd20;
P_0c03fd20: /* original 4108, guest PC 0x0c03fd20 */
if(!s->budget--) { s->failed_pc=0x0c03fd20u; return 0; }
r[1]<<=2;
goto P_0c03fd22;
P_0c03fd22: /* original 4108, guest PC 0x0c03fd22 */
if(!s->budget--) { s->failed_pc=0x0c03fd22u; return 0; }
r[1]<<=2;
goto P_0c03fd24;
P_0c03fd24: /* original 66b3, guest PC 0x0c03fd24 */
if(!s->budget--) { s->failed_pc=0x0c03fd24u; return 0; }
r[6]=r[11];
goto P_0c03fd26;
P_0c03fd26: /* original 4100, guest PC 0x0c03fd26 */
if(!s->budget--) { s->failed_pc=0x0c03fd26u; return 0; }
r[17]=(r[17]&~1u)|((r[1]>>31)!=0);
r[1]<<=1;
goto P_0c03fd28;
P_0c03fd28: /* original 64a3, guest PC 0x0c03fd28 */
if(!s->budget--) { s->failed_pc=0x0c03fd28u; return 0; }
r[4]=r[10];
goto P_0c03fd2a;
P_0c03fd2a: /* original 62d3, guest PC 0x0c03fd2a */
if(!s->budget--) { s->failed_pc=0x0c03fd2au; return 0; }
r[2]=r[13];
goto P_0c03fd2c;
P_0c03fd2c: /* original 2248, guest PC 0x0c03fd2c */
if(!s->budget--) { s->failed_pc=0x0c03fd2cu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[4])==0)!=0);
goto P_0c03fd2e;
P_0c03fd2e: /* original 8b07, guest PC 0x0c03fd2e */
if(!s->budget--) { s->failed_pc=0x0c03fd2eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c03fd40; }
goto P_0c03fd30;
P_0c03fd30: /* original 6072, guest PC 0x0c03fd30 */
if(!s->budget--) { s->failed_pc=0x0c03fd30u; return 0; }
tmp=read(ram,r[7],4);
r[0]=tmp;
goto P_0c03fd32;
P_0c03fd32: /* original 02ee, guest PC 0x0c03fd32 */
if(!s->budget--) { s->failed_pc=0x0c03fd32u; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c03fd34;
P_0c03fd34: /* original 224b, guest PC 0x0c03fd34 */
if(!s->budget--) { s->failed_pc=0x0c03fd34u; return 0; }
r[2]|=r[4];
goto P_0c03fd36;
P_0c03fd36: /* original 0e26, guest PC 0x0c03fd36 */
if(!s->budget--) { s->failed_pc=0x0c03fd36u; return 0; }
write(ram,r[14]+r[0],r[2],4);
goto P_0c03fd38;
P_0c03fd38: /* original 6013, guest PC 0x0c03fd38 */
if(!s->budget--) { s->failed_pc=0x0c03fd38u; return 0; }
r[0]=r[1];
goto P_0c03fd3a;
P_0c03fd3a: /* original 0009, guest PC 0x0c03fd3a */
if(!s->budget--) { s->failed_pc=0x0c03fd3au; return 0; }
goto P_0c03fd3c;
P_0c03fd3c: /* original a023, guest PC 0x0c03fd3c */
if(!s->budget--) { s->failed_pc=0x0c03fd3cu; return 0; }
r[0]+=r[6];
goto P_0c03fd86;
P_0c03fd3e: /* original 306c, guest PC 0x0c03fd3e */
if(!s->budget--) { s->failed_pc=0x0c03fd3eu; return 0; }
r[0]+=r[6];
goto P_0c03fd40;
P_0c03fd40: /* original 4400, guest PC 0x0c03fd40 */
if(!s->budget--) { s->failed_pc=0x0c03fd40u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c03fd42;
P_0c03fd42: /* original aff2, guest PC 0x0c03fd42 */
if(!s->budget--) { s->failed_pc=0x0c03fd42u; return 0; }
r[6]+=0x00000001u;
goto P_0c03fd2a;
P_0c03fd44: /* original 7601, guest PC 0x0c03fd44 */
if(!s->budget--) { s->failed_pc=0x0c03fd44u; return 0; }
r[6]+=0x00000001u;
if(!vf3_matrix_family(0x0c03fd46u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c03fd46u; return 0; } return 1;
P_0c03fd70: /* original 7501, guest PC 0x0c03fd70 */
if(!s->budget--) { s->failed_pc=0x0c03fd70u; return 0; }
r[5]+=0x00000001u;
goto P_0c03fd72;
P_0c03fd72: /* original 6182, guest PC 0x0c03fd72 */
if(!s->budget--) { s->failed_pc=0x0c03fd72u; return 0; }
tmp=read(ram,r[8],4);
r[1]=tmp;
goto P_0c03fd74;
P_0c03fd74: /* original 711f, guest PC 0x0c03fd74 */
if(!s->budget--) { s->failed_pc=0x0c03fd74u; return 0; }
r[1]+=0x0000001fu;
goto P_0c03fd76;
P_0c03fd76: /* original 6093, guest PC 0x0c03fd76 */
if(!s->budget--) { s->failed_pc=0x0c03fd76u; return 0; }
r[0]=r[9];
goto P_0c03fd78;
P_0c03fd78: /* original 0009, guest PC 0x0c03fd78 */
if(!s->budget--) { s->failed_pc=0x0c03fd78u; return 0; }
goto P_0c03fd7a;
P_0c03fd7a: /* original d311, guest PC 0x0c03fd7a */
if(!s->budget--) { s->failed_pc=0x0c03fd7au; return 0; }
r[3]=read(ram,0x0c03fdc0u,4);
goto P_0c03fd7c;
P_0c03fd7c: /* original 430b, guest PC 0x0c03fd7c */
if(!s->budget--) { s->failed_pc=0x0c03fd7cu; return 0; }
target=r[3];
r[16]=code_base|0x0c03fd80u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c03fd80u) { target=s->pc; goto dispatch; }
goto P_0c03fd80;
P_0c03fd7e: /* original 0009, guest PC 0x0c03fd7e */
if(!s->budget--) { s->failed_pc=0x0c03fd7eu; return 0; }
goto P_0c03fd80;
P_0c03fd80: /* original 3503, guest PC 0x0c03fd80 */
if(!s->budget--) { s->failed_pc=0x0c03fd80u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[5]>=(int32_t)r[0])!=0);
goto P_0c03fd82;
P_0c03fd82: /* original 8bc5, guest PC 0x0c03fd82 */
if(!s->budget--) { s->failed_pc=0x0c03fd82u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c03fd10; }
goto P_0c03fd84;
P_0c03fd84: /* original e0ff, guest PC 0x0c03fd84 */
if(!s->budget--) { s->failed_pc=0x0c03fd84u; return 0; }
r[0]=0xffffffffu;
goto P_0c03fd86;
P_0c03fd86: /* original 4f26, guest PC 0x0c03fd86 */
if(!s->budget--) { s->failed_pc=0x0c03fd86u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c03fd88;
P_0c03fd88: /* original 68f6, guest PC 0x0c03fd88 */
if(!s->budget--) { s->failed_pc=0x0c03fd88u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c03fd8a;
P_0c03fd8a: /* original 69f6, guest PC 0x0c03fd8a */
if(!s->budget--) { s->failed_pc=0x0c03fd8au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c03fd8c;
P_0c03fd8c: /* original 6af6, guest PC 0x0c03fd8c */
if(!s->budget--) { s->failed_pc=0x0c03fd8cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c03fd8e;
P_0c03fd8e: /* original 6bf6, guest PC 0x0c03fd8e */
if(!s->budget--) { s->failed_pc=0x0c03fd8eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c03fd90;
P_0c03fd90: /* original 6df6, guest PC 0x0c03fd90 */
if(!s->budget--) { s->failed_pc=0x0c03fd90u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c03fd92;
P_0c03fd92: /* original 000b, guest PC 0x0c03fd92 */
if(!s->budget--) { s->failed_pc=0x0c03fd92u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c03fd94: /* original 6ef6, guest PC 0x0c03fd94 */
if(!s->budget--) { s->failed_pc=0x0c03fd94u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c03fd96u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c03fd96u; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
