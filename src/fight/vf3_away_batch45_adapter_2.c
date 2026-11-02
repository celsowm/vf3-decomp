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
int vf3_away_batch45_adapter_2(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c042cc0u: goto P_0c042cc0;
case 0x0c042cc2u: goto P_0c042cc2;
case 0x0c042cc4u: goto P_0c042cc4;
case 0x0c042cc6u: goto P_0c042cc6;
case 0x0c042cc8u: goto P_0c042cc8;
case 0x0c042ccau: goto P_0c042cca;
case 0x0c042d7cu: goto P_0c042d7c;
case 0x0c042d7eu: goto P_0c042d7e;
case 0x0c042d80u: goto P_0c042d80;
case 0x0c042d82u: goto P_0c042d82;
case 0x0c042d84u: goto P_0c042d84;
case 0x0c042d86u: goto P_0c042d86;
case 0x0c042d88u: goto P_0c042d88;
case 0x0c042d8au: goto P_0c042d8a;
case 0x0c042d8cu: goto P_0c042d8c;
case 0x0c042d8eu: goto P_0c042d8e;
case 0x0c042d90u: goto P_0c042d90;
case 0x0c042d92u: goto P_0c042d92;
case 0x0c042d94u: goto P_0c042d94;
case 0x0c042d96u: goto P_0c042d96;
case 0x0c042d98u: goto P_0c042d98;
case 0x0c042d9au: goto P_0c042d9a;
case 0x0c042d9cu: goto P_0c042d9c;
case 0x0c042d9eu: goto P_0c042d9e;
case 0x0c042da0u: goto P_0c042da0;
case 0x0c042da2u: goto P_0c042da2;
case 0x0c042da4u: goto P_0c042da4;
case 0x0c042da6u: goto P_0c042da6;
case 0x0c042da8u: goto P_0c042da8;
case 0x0c042daau: goto P_0c042daa;
case 0x0c042dacu: goto P_0c042dac;
case 0x0c042daeu: goto P_0c042dae;
case 0x0c042db0u: goto P_0c042db0;
case 0x0c042db2u: goto P_0c042db2;
case 0x0c042db4u: goto P_0c042db4;
case 0x0c042db6u: goto P_0c042db6;
case 0x0c042db8u: goto P_0c042db8;
case 0x0c042dbau: goto P_0c042dba;
case 0x0c042dbcu: goto P_0c042dbc;
case 0x0c042dbeu: goto P_0c042dbe;
case 0x0c042dc0u: goto P_0c042dc0;
case 0x0c042dc2u: goto P_0c042dc2;
case 0x0c042dc4u: goto P_0c042dc4;
case 0x0c042dc6u: goto P_0c042dc6;
case 0x0c042dc8u: goto P_0c042dc8;
case 0x0c042dcau: goto P_0c042dca;
case 0x0c042dccu: goto P_0c042dcc;
case 0x0c042dceu: goto P_0c042dce;
case 0x0c042dd0u: goto P_0c042dd0;
case 0x0c042dd2u: goto P_0c042dd2;
case 0x0c042dd4u: goto P_0c042dd4;
case 0x0c042dd6u: goto P_0c042dd6;
case 0x0c042dd8u: goto P_0c042dd8;
case 0x0c042ddau: goto P_0c042dda;
case 0x0c042ddcu: goto P_0c042ddc;
case 0x0c042ddeu: goto P_0c042dde;
case 0x0c042de0u: goto P_0c042de0;
case 0x0c042de2u: goto P_0c042de2;
case 0x0c042de4u: goto P_0c042de4;
case 0x0c042de6u: goto P_0c042de6;
case 0x0c042de8u: goto P_0c042de8;
case 0x0c042deau: goto P_0c042dea;
case 0x0c042decu: goto P_0c042dec;
case 0x0c042deeu: goto P_0c042dee;
case 0x0c042df0u: goto P_0c042df0;
case 0x0c042df2u: goto P_0c042df2;
case 0x0c042df4u: goto P_0c042df4;
case 0x0c042df6u: goto P_0c042df6;
case 0x0c042df8u: goto P_0c042df8;
case 0x0c042dfau: goto P_0c042dfa;
case 0x0c042dfcu: goto P_0c042dfc;
case 0x0c042dfeu: goto P_0c042dfe;
case 0x0c042e00u: goto P_0c042e00;
case 0x0c042e02u: goto P_0c042e02;
case 0x0c042e04u: goto P_0c042e04;
case 0x0c042e06u: goto P_0c042e06;
case 0x0c042e08u: goto P_0c042e08;
case 0x0c042e0au: goto P_0c042e0a;
case 0x0c042e0cu: goto P_0c042e0c;
case 0x0c042e0eu: goto P_0c042e0e;
case 0x0c042e10u: goto P_0c042e10;
case 0x0c042e12u: goto P_0c042e12;
case 0x0c042e14u: goto P_0c042e14;
case 0x0c042e16u: goto P_0c042e16;
case 0x0c042e18u: goto P_0c042e18;
case 0x0c042e1au: goto P_0c042e1a;
case 0x0c042e1cu: goto P_0c042e1c;
case 0x0c042e1eu: goto P_0c042e1e;
case 0x0c042e20u: goto P_0c042e20;
case 0x0c042e22u: goto P_0c042e22;
case 0x0c042e24u: goto P_0c042e24;
case 0x0c042e26u: goto P_0c042e26;
case 0x0c042e28u: goto P_0c042e28;
case 0x0c042e2au: goto P_0c042e2a;
case 0x0c042e2cu: goto P_0c042e2c;
case 0x0c042e2eu: goto P_0c042e2e;
case 0x0c042e30u: goto P_0c042e30;
case 0x0c042e32u: goto P_0c042e32;
case 0x0c042e34u: goto P_0c042e34;
case 0x0c042e36u: goto P_0c042e36;
case 0x0c042e38u: goto P_0c042e38;
case 0x0c042e3au: goto P_0c042e3a;
case 0x0c06c5c8u: goto P_0c06c5c8;
case 0x0c06c5cau: goto P_0c06c5ca;
case 0x0c06c5ccu: goto P_0c06c5cc;
case 0x0c06c5ceu: goto P_0c06c5ce;
case 0x0c06c5d0u: goto P_0c06c5d0;
case 0x0c06c5d2u: goto P_0c06c5d2;
case 0x0c06c5d4u: goto P_0c06c5d4;
case 0x0c06c5d6u: goto P_0c06c5d6;
case 0x0c06c5d8u: goto P_0c06c5d8;
case 0x0c06c5dau: goto P_0c06c5da;
case 0x0c06c5dcu: goto P_0c06c5dc;
case 0x0c06c5deu: goto P_0c06c5de;
case 0x0c06c5e0u: goto P_0c06c5e0;
case 0x0c06c5e2u: goto P_0c06c5e2;
case 0x0c06c5e4u: goto P_0c06c5e4;
case 0x0c06c5e6u: goto P_0c06c5e6;
case 0x0c06c5e8u: goto P_0c06c5e8;
case 0x0c06c5eau: goto P_0c06c5ea;
case 0x0c06c5ecu: goto P_0c06c5ec;
case 0x0c06c5eeu: goto P_0c06c5ee;
case 0x0c06c5f0u: goto P_0c06c5f0;
case 0x0c06c5f2u: goto P_0c06c5f2;
case 0x0c06c5f4u: goto P_0c06c5f4;
case 0x0c06c5f6u: goto P_0c06c5f6;
case 0x0c06c5f8u: goto P_0c06c5f8;
case 0x0c06c5fau: goto P_0c06c5fa;
case 0x0c06c5fcu: goto P_0c06c5fc;
case 0x0c06c5feu: goto P_0c06c5fe;
case 0x0c06c600u: goto P_0c06c600;
case 0x0c06c602u: goto P_0c06c602;
case 0x0c06c604u: goto P_0c06c604;
case 0x0c06c606u: goto P_0c06c606;
case 0x0c06c608u: goto P_0c06c608;
case 0x0c06c60au: goto P_0c06c60a;
case 0x0c06c60cu: goto P_0c06c60c;
case 0x0c06c60eu: goto P_0c06c60e;
case 0x0c06c610u: goto P_0c06c610;
case 0x0c06c612u: goto P_0c06c612;
case 0x0c06c614u: goto P_0c06c614;
case 0x0c06c616u: goto P_0c06c616;
case 0x0c06c618u: goto P_0c06c618;
case 0x0c06c61au: goto P_0c06c61a;
case 0x0c06c61cu: goto P_0c06c61c;
case 0x0c06c61eu: goto P_0c06c61e;
case 0x0c06c620u: goto P_0c06c620;
case 0x0c06c622u: goto P_0c06c622;
case 0x0c06c624u: goto P_0c06c624;
case 0x0c06c626u: goto P_0c06c626;
case 0x0c06c628u: goto P_0c06c628;
case 0x0c06c62au: goto P_0c06c62a;
case 0x0c06c62cu: goto P_0c06c62c;
case 0x0c06c62eu: goto P_0c06c62e;
case 0x0c06c630u: goto P_0c06c630;
case 0x0c06c632u: goto P_0c06c632;
case 0x0c06c634u: goto P_0c06c634;
case 0x0c06c636u: goto P_0c06c636;
case 0x0c06c638u: goto P_0c06c638;
case 0x0c06c63au: goto P_0c06c63a;
case 0x0c06c63cu: goto P_0c06c63c;
case 0x0c06c63eu: goto P_0c06c63e;
case 0x0c06c640u: goto P_0c06c640;
case 0x0c06c642u: goto P_0c06c642;
case 0x0c06c644u: goto P_0c06c644;
case 0x0c06c646u: goto P_0c06c646;
case 0x0c06c648u: goto P_0c06c648;
case 0x0c06c64au: goto P_0c06c64a;
case 0x0c06c64cu: goto P_0c06c64c;
case 0x0c06c64eu: goto P_0c06c64e;
case 0x0c06c650u: goto P_0c06c650;
case 0x0c06c652u: goto P_0c06c652;
case 0x0c06c654u: goto P_0c06c654;
case 0x0c06c656u: goto P_0c06c656;
case 0x0c06c658u: goto P_0c06c658;
case 0x0c06c65au: goto P_0c06c65a;
case 0x0c06c65cu: goto P_0c06c65c;
case 0x0c06c65eu: goto P_0c06c65e;
case 0x0c06c660u: goto P_0c06c660;
case 0x0c06c662u: goto P_0c06c662;
case 0x0c06c664u: goto P_0c06c664;
case 0x0c06c666u: goto P_0c06c666;
case 0x0c06c668u: goto P_0c06c668;
case 0x0c06c66au: goto P_0c06c66a;
case 0x0c06c66cu: goto P_0c06c66c;
case 0x0c06c66eu: goto P_0c06c66e;
case 0x0c06c670u: goto P_0c06c670;
case 0x0c06c672u: goto P_0c06c672;
case 0x0c06c674u: goto P_0c06c674;
case 0x0c06c676u: goto P_0c06c676;
case 0x0c06c678u: goto P_0c06c678;
case 0x0c06c67au: goto P_0c06c67a;
case 0x0c06c67cu: goto P_0c06c67c;
case 0x0c06c67eu: goto P_0c06c67e;
case 0x0c06c680u: goto P_0c06c680;
case 0x0c06c682u: goto P_0c06c682;
case 0x0c06c684u: goto P_0c06c684;
case 0x0c06c686u: goto P_0c06c686;
case 0x0c06c688u: goto P_0c06c688;
case 0x0c06c68au: goto P_0c06c68a;
case 0x0c06c68cu: goto P_0c06c68c;
case 0x0c06c68eu: goto P_0c06c68e;
case 0x0c06c690u: goto P_0c06c690;
case 0x0c06c692u: goto P_0c06c692;
case 0x0c06c694u: goto P_0c06c694;
case 0x0c06c696u: goto P_0c06c696;
case 0x0c06c698u: goto P_0c06c698;
case 0x0c06c69au: goto P_0c06c69a;
case 0x0c06c69cu: goto P_0c06c69c;
case 0x0c06c69eu: goto P_0c06c69e;
case 0x0c06c6a0u: goto P_0c06c6a0;
case 0x0c06c6a2u: goto P_0c06c6a2;
case 0x0c06c6a4u: goto P_0c06c6a4;
case 0x0c06c6a6u: goto P_0c06c6a6;
case 0x0c06c6a8u: goto P_0c06c6a8;
default: return vf3_matrix_family(target,s,ram);
}
P_0c042cc0: /* original d102, guest PC 0x0c042cc0 */
if(!s->budget--) { s->failed_pc=0x0c042cc0u; return 0; }
r[1]=read(ram,0x0c042cccu,4);
goto P_0c042cc2;
P_0c042cc2: /* original d203, guest PC 0x0c042cc2 */
if(!s->budget--) { s->failed_pc=0x0c042cc2u; return 0; }
r[2]=read(ram,0x0c042cd0u,4);
goto P_0c042cc4;
P_0c042cc4: /* original e000, guest PC 0x0c042cc4 */
if(!s->budget--) { s->failed_pc=0x0c042cc4u; return 0; }
r[0]=0x00000000u;
goto P_0c042cc6;
P_0c042cc6: /* original 2122, guest PC 0x0c042cc6 */
if(!s->budget--) { s->failed_pc=0x0c042cc6u; return 0; }
write(ram,r[1],r[2],4);
goto P_0c042cc8;
P_0c042cc8: /* original 000b, guest PC 0x0c042cc8 */
if(!s->budget--) { s->failed_pc=0x0c042cc8u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[2]=tmp;
s->pc=target; return ram->oob==0;
P_0c042cca: /* original 62f6, guest PC 0x0c042cca */
if(!s->budget--) { s->failed_pc=0x0c042ccau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[2]=tmp;
if(!vf3_matrix_family(0x0c042cccu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c042cccu; return 0; } return 1;
P_0c042d7c: /* original 2008, guest PC 0x0c042d7c */
if(!s->budget--) { s->failed_pc=0x0c042d7cu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c042d7e;
P_0c042d7e: /* original 2f26, guest PC 0x0c042d7e */
if(!s->budget--) { s->failed_pc=0x0c042d7eu; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c042d80;
P_0c042d80: /* original 8d56, guest PC 0x0c042d80 */
if(!s->budget--) { s->failed_pc=0x0c042d80u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c042e30; }
goto P_0c042d84;
P_0c042d82: /* original 0009, guest PC 0x0c042d82 */
if(!s->budget--) { s->failed_pc=0x0c042d82u; return 0; }
goto P_0c042d84;
P_0c042d84: /* original 2f36, guest PC 0x0c042d84 */
if(!s->budget--) { s->failed_pc=0x0c042d84u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c042d86;
P_0c042d86: /* original e200, guest PC 0x0c042d86 */
if(!s->budget--) { s->failed_pc=0x0c042d86u; return 0; }
r[2]=0x00000000u;
goto P_0c042d88;
P_0c042d88: /* original 2f46, guest PC 0x0c042d88 */
if(!s->budget--) { s->failed_pc=0x0c042d88u; return 0; }
tmp=r[4]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c042d8a;
P_0c042d8a: /* original 2127, guest PC 0x0c042d8a */
if(!s->budget--) { s->failed_pc=0x0c042d8au; return 0; }
r[17]=(r[17]&~0x301u)|((r[1]>>31)<<8)|((r[2]>>31)<<9)|(((r[1]^r[2])>>31)&1u);
goto P_0c042d8c;
P_0c042d8c: /* original 0429, guest PC 0x0c042d8c */
if(!s->budget--) { s->failed_pc=0x0c042d8cu; return 0; }
r[4]=r[17]&1u;
goto P_0c042d8e;
P_0c042d8e: /* original 333a, guest PC 0x0c042d8e */
if(!s->budget--) { s->failed_pc=0x0c042d8eu; return 0; }
wide=(uint64_t)r[3]-r[3]-(r[17]&1u); r[3]=(uint32_t)wide;
r[17]=(r[17]&~1u)|((wide>>32)!=0);
goto P_0c042d90;
P_0c042d90: /* original 312a, guest PC 0x0c042d90 */
if(!s->budget--) { s->failed_pc=0x0c042d90u; return 0; }
wide=(uint64_t)r[1]-r[2]-(r[17]&1u); r[1]=(uint32_t)wide;
r[17]=(r[17]&~1u)|((wide>>32)!=0);
goto P_0c042d92;
P_0c042d92: /* original 2307, guest PC 0x0c042d92 */
if(!s->budget--) { s->failed_pc=0x0c042d92u; return 0; }
r[17]=(r[17]&~0x301u)|((r[3]>>31)<<8)|((r[0]>>31)<<9)|(((r[3]^r[0])>>31)&1u);
goto P_0c042d94;
P_0c042d94: /* original 4124, guest PC 0x0c042d94 */
if(!s->budget--) { s->failed_pc=0x0c042d94u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042d96;
P_0c042d96: /* original 3304, guest PC 0x0c042d96 */
if(!s->budget--) { s->failed_pc=0x0c042d96u; return 0; }
divide_step(s,3,0);
goto P_0c042d98;
P_0c042d98: /* original 4124, guest PC 0x0c042d98 */
if(!s->budget--) { s->failed_pc=0x0c042d98u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042d9a;
P_0c042d9a: /* original 3304, guest PC 0x0c042d9a */
if(!s->budget--) { s->failed_pc=0x0c042d9au; return 0; }
divide_step(s,3,0);
goto P_0c042d9c;
P_0c042d9c: /* original 4124, guest PC 0x0c042d9c */
if(!s->budget--) { s->failed_pc=0x0c042d9cu; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042d9e;
P_0c042d9e: /* original 3304, guest PC 0x0c042d9e */
if(!s->budget--) { s->failed_pc=0x0c042d9eu; return 0; }
divide_step(s,3,0);
goto P_0c042da0;
P_0c042da0: /* original 4124, guest PC 0x0c042da0 */
if(!s->budget--) { s->failed_pc=0x0c042da0u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042da2;
P_0c042da2: /* original 3304, guest PC 0x0c042da2 */
if(!s->budget--) { s->failed_pc=0x0c042da2u; return 0; }
divide_step(s,3,0);
goto P_0c042da4;
P_0c042da4: /* original 4124, guest PC 0x0c042da4 */
if(!s->budget--) { s->failed_pc=0x0c042da4u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042da6;
P_0c042da6: /* original 3304, guest PC 0x0c042da6 */
if(!s->budget--) { s->failed_pc=0x0c042da6u; return 0; }
divide_step(s,3,0);
goto P_0c042da8;
P_0c042da8: /* original 4124, guest PC 0x0c042da8 */
if(!s->budget--) { s->failed_pc=0x0c042da8u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042daa;
P_0c042daa: /* original 3304, guest PC 0x0c042daa */
if(!s->budget--) { s->failed_pc=0x0c042daau; return 0; }
divide_step(s,3,0);
goto P_0c042dac;
P_0c042dac: /* original 4124, guest PC 0x0c042dac */
if(!s->budget--) { s->failed_pc=0x0c042dacu; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042dae;
P_0c042dae: /* original 3304, guest PC 0x0c042dae */
if(!s->budget--) { s->failed_pc=0x0c042daeu; return 0; }
divide_step(s,3,0);
goto P_0c042db0;
P_0c042db0: /* original 4124, guest PC 0x0c042db0 */
if(!s->budget--) { s->failed_pc=0x0c042db0u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042db2;
P_0c042db2: /* original 3304, guest PC 0x0c042db2 */
if(!s->budget--) { s->failed_pc=0x0c042db2u; return 0; }
divide_step(s,3,0);
goto P_0c042db4;
P_0c042db4: /* original 4124, guest PC 0x0c042db4 */
if(!s->budget--) { s->failed_pc=0x0c042db4u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042db6;
P_0c042db6: /* original 3304, guest PC 0x0c042db6 */
if(!s->budget--) { s->failed_pc=0x0c042db6u; return 0; }
divide_step(s,3,0);
goto P_0c042db8;
P_0c042db8: /* original 4124, guest PC 0x0c042db8 */
if(!s->budget--) { s->failed_pc=0x0c042db8u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042dba;
P_0c042dba: /* original 3304, guest PC 0x0c042dba */
if(!s->budget--) { s->failed_pc=0x0c042dbau; return 0; }
divide_step(s,3,0);
goto P_0c042dbc;
P_0c042dbc: /* original 4124, guest PC 0x0c042dbc */
if(!s->budget--) { s->failed_pc=0x0c042dbcu; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042dbe;
P_0c042dbe: /* original 3304, guest PC 0x0c042dbe */
if(!s->budget--) { s->failed_pc=0x0c042dbeu; return 0; }
divide_step(s,3,0);
goto P_0c042dc0;
P_0c042dc0: /* original 4124, guest PC 0x0c042dc0 */
if(!s->budget--) { s->failed_pc=0x0c042dc0u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042dc2;
P_0c042dc2: /* original 3304, guest PC 0x0c042dc2 */
if(!s->budget--) { s->failed_pc=0x0c042dc2u; return 0; }
divide_step(s,3,0);
goto P_0c042dc4;
P_0c042dc4: /* original 4124, guest PC 0x0c042dc4 */
if(!s->budget--) { s->failed_pc=0x0c042dc4u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042dc6;
P_0c042dc6: /* original 3304, guest PC 0x0c042dc6 */
if(!s->budget--) { s->failed_pc=0x0c042dc6u; return 0; }
divide_step(s,3,0);
goto P_0c042dc8;
P_0c042dc8: /* original 4124, guest PC 0x0c042dc8 */
if(!s->budget--) { s->failed_pc=0x0c042dc8u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042dca;
P_0c042dca: /* original 3304, guest PC 0x0c042dca */
if(!s->budget--) { s->failed_pc=0x0c042dcau; return 0; }
divide_step(s,3,0);
goto P_0c042dcc;
P_0c042dcc: /* original 4124, guest PC 0x0c042dcc */
if(!s->budget--) { s->failed_pc=0x0c042dccu; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042dce;
P_0c042dce: /* original 3304, guest PC 0x0c042dce */
if(!s->budget--) { s->failed_pc=0x0c042dceu; return 0; }
divide_step(s,3,0);
goto P_0c042dd0;
P_0c042dd0: /* original 4124, guest PC 0x0c042dd0 */
if(!s->budget--) { s->failed_pc=0x0c042dd0u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042dd2;
P_0c042dd2: /* original 3304, guest PC 0x0c042dd2 */
if(!s->budget--) { s->failed_pc=0x0c042dd2u; return 0; }
divide_step(s,3,0);
goto P_0c042dd4;
P_0c042dd4: /* original 4124, guest PC 0x0c042dd4 */
if(!s->budget--) { s->failed_pc=0x0c042dd4u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042dd6;
P_0c042dd6: /* original 3304, guest PC 0x0c042dd6 */
if(!s->budget--) { s->failed_pc=0x0c042dd6u; return 0; }
divide_step(s,3,0);
goto P_0c042dd8;
P_0c042dd8: /* original 4124, guest PC 0x0c042dd8 */
if(!s->budget--) { s->failed_pc=0x0c042dd8u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042dda;
P_0c042dda: /* original 3304, guest PC 0x0c042dda */
if(!s->budget--) { s->failed_pc=0x0c042ddau; return 0; }
divide_step(s,3,0);
goto P_0c042ddc;
P_0c042ddc: /* original 4124, guest PC 0x0c042ddc */
if(!s->budget--) { s->failed_pc=0x0c042ddcu; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042dde;
P_0c042dde: /* original 3304, guest PC 0x0c042dde */
if(!s->budget--) { s->failed_pc=0x0c042ddeu; return 0; }
divide_step(s,3,0);
goto P_0c042de0;
P_0c042de0: /* original 4124, guest PC 0x0c042de0 */
if(!s->budget--) { s->failed_pc=0x0c042de0u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042de2;
P_0c042de2: /* original 3304, guest PC 0x0c042de2 */
if(!s->budget--) { s->failed_pc=0x0c042de2u; return 0; }
divide_step(s,3,0);
goto P_0c042de4;
P_0c042de4: /* original 4124, guest PC 0x0c042de4 */
if(!s->budget--) { s->failed_pc=0x0c042de4u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042de6;
P_0c042de6: /* original 3304, guest PC 0x0c042de6 */
if(!s->budget--) { s->failed_pc=0x0c042de6u; return 0; }
divide_step(s,3,0);
goto P_0c042de8;
P_0c042de8: /* original 4124, guest PC 0x0c042de8 */
if(!s->budget--) { s->failed_pc=0x0c042de8u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042dea;
P_0c042dea: /* original 3304, guest PC 0x0c042dea */
if(!s->budget--) { s->failed_pc=0x0c042deau; return 0; }
divide_step(s,3,0);
goto P_0c042dec;
P_0c042dec: /* original 4124, guest PC 0x0c042dec */
if(!s->budget--) { s->failed_pc=0x0c042decu; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042dee;
P_0c042dee: /* original 3304, guest PC 0x0c042dee */
if(!s->budget--) { s->failed_pc=0x0c042deeu; return 0; }
divide_step(s,3,0);
goto P_0c042df0;
P_0c042df0: /* original 4124, guest PC 0x0c042df0 */
if(!s->budget--) { s->failed_pc=0x0c042df0u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042df2;
P_0c042df2: /* original 3304, guest PC 0x0c042df2 */
if(!s->budget--) { s->failed_pc=0x0c042df2u; return 0; }
divide_step(s,3,0);
goto P_0c042df4;
P_0c042df4: /* original 4124, guest PC 0x0c042df4 */
if(!s->budget--) { s->failed_pc=0x0c042df4u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042df6;
P_0c042df6: /* original 3304, guest PC 0x0c042df6 */
if(!s->budget--) { s->failed_pc=0x0c042df6u; return 0; }
divide_step(s,3,0);
goto P_0c042df8;
P_0c042df8: /* original 4124, guest PC 0x0c042df8 */
if(!s->budget--) { s->failed_pc=0x0c042df8u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042dfa;
P_0c042dfa: /* original 3304, guest PC 0x0c042dfa */
if(!s->budget--) { s->failed_pc=0x0c042dfau; return 0; }
divide_step(s,3,0);
goto P_0c042dfc;
P_0c042dfc: /* original 4124, guest PC 0x0c042dfc */
if(!s->budget--) { s->failed_pc=0x0c042dfcu; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042dfe;
P_0c042dfe: /* original 3304, guest PC 0x0c042dfe */
if(!s->budget--) { s->failed_pc=0x0c042dfeu; return 0; }
divide_step(s,3,0);
goto P_0c042e00;
P_0c042e00: /* original 4124, guest PC 0x0c042e00 */
if(!s->budget--) { s->failed_pc=0x0c042e00u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042e02;
P_0c042e02: /* original 3304, guest PC 0x0c042e02 */
if(!s->budget--) { s->failed_pc=0x0c042e02u; return 0; }
divide_step(s,3,0);
goto P_0c042e04;
P_0c042e04: /* original 4124, guest PC 0x0c042e04 */
if(!s->budget--) { s->failed_pc=0x0c042e04u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042e06;
P_0c042e06: /* original 3304, guest PC 0x0c042e06 */
if(!s->budget--) { s->failed_pc=0x0c042e06u; return 0; }
divide_step(s,3,0);
goto P_0c042e08;
P_0c042e08: /* original 4124, guest PC 0x0c042e08 */
if(!s->budget--) { s->failed_pc=0x0c042e08u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042e0a;
P_0c042e0a: /* original 3304, guest PC 0x0c042e0a */
if(!s->budget--) { s->failed_pc=0x0c042e0au; return 0; }
divide_step(s,3,0);
goto P_0c042e0c;
P_0c042e0c: /* original 4124, guest PC 0x0c042e0c */
if(!s->budget--) { s->failed_pc=0x0c042e0cu; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042e0e;
P_0c042e0e: /* original 3304, guest PC 0x0c042e0e */
if(!s->budget--) { s->failed_pc=0x0c042e0eu; return 0; }
divide_step(s,3,0);
goto P_0c042e10;
P_0c042e10: /* original 4124, guest PC 0x0c042e10 */
if(!s->budget--) { s->failed_pc=0x0c042e10u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042e12;
P_0c042e12: /* original 3304, guest PC 0x0c042e12 */
if(!s->budget--) { s->failed_pc=0x0c042e12u; return 0; }
divide_step(s,3,0);
goto P_0c042e14;
P_0c042e14: /* original 2327, guest PC 0x0c042e14 */
if(!s->budget--) { s->failed_pc=0x0c042e14u; return 0; }
r[17]=(r[17]&~0x301u)|((r[3]>>31)<<8)|((r[2]>>31)<<9)|(((r[3]^r[2])>>31)&1u);
goto P_0c042e16;
P_0c042e16: /* original 0229, guest PC 0x0c042e16 */
if(!s->budget--) { s->failed_pc=0x0c042e16u; return 0; }
r[2]=r[17]&1u;
goto P_0c042e18;
P_0c042e18: /* original 224a, guest PC 0x0c042e18 */
if(!s->budget--) { s->failed_pc=0x0c042e18u; return 0; }
r[2]^=r[4];
goto P_0c042e1a;
P_0c042e1a: /* original 4225, guest PC 0x0c042e1a */
if(!s->budget--) { s->failed_pc=0x0c042e1au; return 0; }
tmp=r[2]&1u; r[2]=(r[2]>>1)|((r[17]&1u)<<31);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042e1c;
P_0c042e1c: /* original 8b02, guest PC 0x0c042e1c */
if(!s->budget--) { s->failed_pc=0x0c042e1cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c042e24; }
goto P_0c042e1e;
P_0c042e1e: /* original 2307, guest PC 0x0c042e1e */
if(!s->budget--) { s->failed_pc=0x0c042e1eu; return 0; }
r[17]=(r[17]&~0x301u)|((r[3]>>31)<<8)|((r[0]>>31)<<9)|(((r[3]^r[0])>>31)&1u);
goto P_0c042e20;
P_0c042e20: /* original 4321, guest PC 0x0c042e20 */
if(!s->budget--) { s->failed_pc=0x0c042e20u; return 0; }
r[17]=(r[17]&~1u)|((r[3]&1)!=0);
r[3]=(uint32_t)((int32_t)r[3]>>1);
goto P_0c042e22;
P_0c042e22: /* original 3304, guest PC 0x0c042e22 */
if(!s->budget--) { s->failed_pc=0x0c042e22u; return 0; }
divide_step(s,3,0);
goto P_0c042e24;
P_0c042e24: /* original 334c, guest PC 0x0c042e24 */
if(!s->budget--) { s->failed_pc=0x0c042e24u; return 0; }
r[3]+=r[4];
goto P_0c042e26;
P_0c042e26: /* original 6033, guest PC 0x0c042e26 */
if(!s->budget--) { s->failed_pc=0x0c042e26u; return 0; }
r[0]=r[3];
goto P_0c042e28;
P_0c042e28: /* original 64f6, guest PC 0x0c042e28 */
if(!s->budget--) { s->failed_pc=0x0c042e28u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[4]=tmp;
goto P_0c042e2a;
P_0c042e2a: /* original 63f6, guest PC 0x0c042e2a */
if(!s->budget--) { s->failed_pc=0x0c042e2au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[3]=tmp;
goto P_0c042e2c;
P_0c042e2c: /* original 000b, guest PC 0x0c042e2c */
if(!s->budget--) { s->failed_pc=0x0c042e2cu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[2]=tmp;
s->pc=target; return ram->oob==0;
P_0c042e2e: /* original 62f6, guest PC 0x0c042e2e */
if(!s->budget--) { s->failed_pc=0x0c042e2eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[2]=tmp;
goto P_0c042e30;
P_0c042e30: /* original d102, guest PC 0x0c042e30 */
if(!s->budget--) { s->failed_pc=0x0c042e30u; return 0; }
r[1]=read(ram,0x0c042e3cu,4);
goto P_0c042e32;
P_0c042e32: /* original d203, guest PC 0x0c042e32 */
if(!s->budget--) { s->failed_pc=0x0c042e32u; return 0; }
r[2]=read(ram,0x0c042e40u,4);
goto P_0c042e34;
P_0c042e34: /* original e000, guest PC 0x0c042e34 */
if(!s->budget--) { s->failed_pc=0x0c042e34u; return 0; }
r[0]=0x00000000u;
goto P_0c042e36;
P_0c042e36: /* original 2122, guest PC 0x0c042e36 */
if(!s->budget--) { s->failed_pc=0x0c042e36u; return 0; }
write(ram,r[1],r[2],4);
goto P_0c042e38;
P_0c042e38: /* original 000b, guest PC 0x0c042e38 */
if(!s->budget--) { s->failed_pc=0x0c042e38u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[2]=tmp;
s->pc=target; return ram->oob==0;
P_0c042e3a: /* original 62f6, guest PC 0x0c042e3a */
if(!s->budget--) { s->failed_pc=0x0c042e3au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[2]=tmp;
if(!vf3_matrix_family(0x0c042e3cu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c042e3cu; return 0; } return 1;
P_0c06c5c8: /* original 2fe6, guest PC 0x0c06c5c8 */
if(!s->budget--) { s->failed_pc=0x0c06c5c8u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06c5ca;
P_0c06c5ca: /* original d346, guest PC 0x0c06c5ca */
if(!s->budget--) { s->failed_pc=0x0c06c5cau; return 0; }
r[3]=read(ram,0x0c06c6e4u,4);
goto P_0c06c5cc;
P_0c06c5cc: /* original d246, guest PC 0x0c06c5cc */
if(!s->budget--) { s->failed_pc=0x0c06c5ccu; return 0; }
r[2]=read(ram,0x0c06c6e8u,4);
goto P_0c06c5ce;
P_0c06c5ce: /* original 6530, guest PC 0x0c06c5ce */
if(!s->budget--) { s->failed_pc=0x0c06c5ceu; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[3],1);
r[5]=tmp;
goto P_0c06c5d0;
P_0c06c5d0: /* original 4f22, guest PC 0x0c06c5d0 */
if(!s->budget--) { s->failed_pc=0x0c06c5d0u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c06c5d2;
P_0c06c5d2: /* original 6422, guest PC 0x0c06c5d2 */
if(!s->budget--) { s->failed_pc=0x0c06c5d2u; return 0; }
tmp=read(ram,r[2],4);
r[4]=tmp;
goto P_0c06c5d4;
P_0c06c5d4: /* original 655c, guest PC 0x0c06c5d4 */
if(!s->budget--) { s->failed_pc=0x0c06c5d4u; return 0; }
r[5]=r[5]&255u;
goto P_0c06c5d6;
P_0c06c5d6: /* original de42, guest PC 0x0c06c5d6 */
if(!s->budget--) { s->failed_pc=0x0c06c5d6u; return 0; }
r[14]=read(ram,0x0c06c6e0u,4);
goto P_0c06c5d8;
P_0c06c5d8: /* original 2558, guest PC 0x0c06c5d8 */
if(!s->budget--) { s->failed_pc=0x0c06c5d8u; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[5])==0)!=0);
goto P_0c06c5da;
P_0c06c5da: /* original 8d0f, guest PC 0x0c06c5da */
if(!s->budget--) { s->failed_pc=0x0c06c5dau; return 0; }
cond=r[17]&1u;
r[4]+=0x00000001u;
if(cond) { goto P_0c06c5fc; }
goto P_0c06c5de;
P_0c06c5dc: /* original 7401, guest PC 0x0c06c5dc */
if(!s->budget--) { s->failed_pc=0x0c06c5dcu; return 0; }
r[4]+=0x00000001u;
goto P_0c06c5de;
P_0c06c5de: /* original 6053, guest PC 0x0c06c5de */
if(!s->budget--) { s->failed_pc=0x0c06c5deu; return 0; }
r[0]=r[5];
goto P_0c06c5e0;
P_0c06c5e0: /* original 8801, guest PC 0x0c06c5e0 */
if(!s->budget--) { s->failed_pc=0x0c06c5e0u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c06c5e2;
P_0c06c5e2: /* original 8b05, guest PC 0x0c06c5e2 */
if(!s->budget--) { s->failed_pc=0x0c06c5e2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06c5f0; }
goto P_0c06c5e4;
P_0c06c5e4: /* original 4f26, guest PC 0x0c06c5e4 */
if(!s->budget--) { s->failed_pc=0x0c06c5e4u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c06c5e6;
P_0c06c5e6: /* original 6543, guest PC 0x0c06c5e6 */
if(!s->budget--) { s->failed_pc=0x0c06c5e6u; return 0; }
r[5]=r[4];
goto P_0c06c5e8;
P_0c06c5e8: /* original e404, guest PC 0x0c06c5e8 */
if(!s->budget--) { s->failed_pc=0x0c06c5e8u; return 0; }
r[4]=0x00000004u;
goto P_0c06c5ea;
P_0c06c5ea: /* original e627, guest PC 0x0c06c5ea */
if(!s->budget--) { s->failed_pc=0x0c06c5eau; return 0; }
r[6]=0x00000027u;
goto P_0c06c5ec;
P_0c06c5ec: /* original a023, guest PC 0x0c06c5ec */
if(!s->budget--) { s->failed_pc=0x0c06c5ecu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c06c636;
P_0c06c5ee: /* original 6ef6, guest PC 0x0c06c5ee */
if(!s->budget--) { s->failed_pc=0x0c06c5eeu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c06c5f0;
P_0c06c5f0: /* original 4f26, guest PC 0x0c06c5f0 */
if(!s->budget--) { s->failed_pc=0x0c06c5f0u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c06c5f2;
P_0c06c5f2: /* original 6543, guest PC 0x0c06c5f2 */
if(!s->budget--) { s->failed_pc=0x0c06c5f2u; return 0; }
r[5]=r[4];
goto P_0c06c5f4;
P_0c06c5f4: /* original e427, guest PC 0x0c06c5f4 */
if(!s->budget--) { s->failed_pc=0x0c06c5f4u; return 0; }
r[4]=0x00000027u;
goto P_0c06c5f6;
P_0c06c5f6: /* original e604, guest PC 0x0c06c5f6 */
if(!s->budget--) { s->failed_pc=0x0c06c5f6u; return 0; }
r[6]=0x00000004u;
goto P_0c06c5f8;
P_0c06c5f8: /* original a01d, guest PC 0x0c06c5f8 */
if(!s->budget--) { s->failed_pc=0x0c06c5f8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c06c636;
P_0c06c5fa: /* original 6ef6, guest PC 0x0c06c5fa */
if(!s->budget--) { s->failed_pc=0x0c06c5fau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c06c5fc;
P_0c06c5fc: /* original e307, guest PC 0x0c06c5fc */
if(!s->budget--) { s->failed_pc=0x0c06c5fcu; return 0; }
r[3]=0x00000007u;
goto P_0c06c5fe;
P_0c06c5fe: /* original e220, guest PC 0x0c06c5fe */
if(!s->budget--) { s->failed_pc=0x0c06c5feu; return 0; }
r[2]=0x00000020u;
goto P_0c06c600;
P_0c06c600: /* original e508, guest PC 0x0c06c600 */
if(!s->budget--) { s->failed_pc=0x0c06c600u; return 0; }
r[5]=0x00000008u;
goto P_0c06c602;
P_0c06c602: /* original 2f26, guest PC 0x0c06c602 */
if(!s->budget--) { s->failed_pc=0x0c06c602u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06c604;
P_0c06c604: /* original d139, guest PC 0x0c06c604 */
if(!s->budget--) { s->failed_pc=0x0c06c604u; return 0; }
r[1]=read(ram,0x0c06c6ecu,4);
goto P_0c06c606;
P_0c06c606: /* original 443c, guest PC 0x0c06c606 */
if(!s->budget--) { s->failed_pc=0x0c06c606u; return 0; }
r[4]=(r[3]&0x80000000u)?((r[3]&31u)?(uint32_t)((int32_t)r[4]>>((-r[3])&31u)):((int32_t)r[4]<0?0xffffffffu:0)):r[4]<<(r[3]&31u);
goto P_0c06c608;
P_0c06c608: /* original e615, guest PC 0x0c06c608 */
if(!s->budget--) { s->failed_pc=0x0c06c608u; return 0; }
r[6]=0x00000015u;
goto P_0c06c60a;
P_0c06c60a: /* original e701, guest PC 0x0c06c60a */
if(!s->budget--) { s->failed_pc=0x0c06c60au; return 0; }
r[7]=0x00000001u;
goto P_0c06c60c;
P_0c06c60c: /* original 254b, guest PC 0x0c06c60c */
if(!s->budget--) { s->failed_pc=0x0c06c60cu; return 0; }
r[5]|=r[4];
goto P_0c06c60e;
P_0c06c60e: /* original 410b, guest PC 0x0c06c60e */
if(!s->budget--) { s->failed_pc=0x0c06c60eu; return 0; }
target=r[1];
r[16]=code_base|0x0c06c612u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06c612u) { target=s->pc; goto dispatch; }
goto P_0c06c612;
P_0c06c610: /* original 64e3, guest PC 0x0c06c610 */
if(!s->budget--) { s->failed_pc=0x0c06c610u; return 0; }
r[4]=r[14];
goto P_0c06c612;
P_0c06c612: /* original d335, guest PC 0x0c06c612 */
if(!s->budget--) { s->failed_pc=0x0c06c612u; return 0; }
r[3]=read(ram,0x0c06c6e8u,4);
goto P_0c06c614;
P_0c06c614: /* original e207, guest PC 0x0c06c614 */
if(!s->budget--) { s->failed_pc=0x0c06c614u; return 0; }
r[2]=0x00000007u;
goto P_0c06c616;
P_0c06c616: /* original e120, guest PC 0x0c06c616 */
if(!s->budget--) { s->failed_pc=0x0c06c616u; return 0; }
r[1]=0x00000020u;
goto P_0c06c618;
P_0c06c618: /* original 6032, guest PC 0x0c06c618 */
if(!s->budget--) { s->failed_pc=0x0c06c618u; return 0; }
tmp=read(ram,r[3],4);
r[0]=tmp;
goto P_0c06c61a;
P_0c06c61a: /* original e54e, guest PC 0x0c06c61a */
if(!s->budget--) { s->failed_pc=0x0c06c61au; return 0; }
r[5]=0x0000004eu;
goto P_0c06c61c;
P_0c06c61c: /* original e615, guest PC 0x0c06c61c */
if(!s->budget--) { s->failed_pc=0x0c06c61cu; return 0; }
r[6]=0x00000015u;
goto P_0c06c61e;
P_0c06c61e: /* original 2f16, guest PC 0x0c06c61e */
if(!s->budget--) { s->failed_pc=0x0c06c61eu; return 0; }
tmp=r[1]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06c620;
P_0c06c620: /* original 7001, guest PC 0x0c06c620 */
if(!s->budget--) { s->failed_pc=0x0c06c620u; return 0; }
r[0]+=0x00000001u;
goto P_0c06c622;
P_0c06c622: /* original d332, guest PC 0x0c06c622 */
if(!s->budget--) { s->failed_pc=0x0c06c622u; return 0; }
r[3]=read(ram,0x0c06c6ecu,4);
goto P_0c06c624;
P_0c06c624: /* original 402c, guest PC 0x0c06c624 */
if(!s->budget--) { s->failed_pc=0x0c06c624u; return 0; }
r[0]=(r[2]&0x80000000u)?((r[2]&31u)?(uint32_t)((int32_t)r[0]>>((-r[2])&31u)):((int32_t)r[0]<0?0xffffffffu:0)):r[0]<<(r[2]&31u);
goto P_0c06c626;
P_0c06c626: /* original e701, guest PC 0x0c06c626 */
if(!s->budget--) { s->failed_pc=0x0c06c626u; return 0; }
r[7]=0x00000001u;
goto P_0c06c628;
P_0c06c628: /* original 250b, guest PC 0x0c06c628 */
if(!s->budget--) { s->failed_pc=0x0c06c628u; return 0; }
r[5]|=r[0];
goto P_0c06c62a;
P_0c06c62a: /* original 430b, guest PC 0x0c06c62a */
if(!s->budget--) { s->failed_pc=0x0c06c62au; return 0; }
target=r[3];
r[16]=code_base|0x0c06c62eu;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06c62eu) { target=s->pc; goto dispatch; }
goto P_0c06c62e;
P_0c06c62c: /* original 64e3, guest PC 0x0c06c62c */
if(!s->budget--) { s->failed_pc=0x0c06c62cu; return 0; }
r[4]=r[14];
goto P_0c06c62e;
P_0c06c62e: /* original 7f08, guest PC 0x0c06c62e */
if(!s->budget--) { s->failed_pc=0x0c06c62eu; return 0; }
r[15]+=0x00000008u;
goto P_0c06c630;
P_0c06c630: /* original 4f26, guest PC 0x0c06c630 */
if(!s->budget--) { s->failed_pc=0x0c06c630u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c06c632;
P_0c06c632: /* original 000b, guest PC 0x0c06c632 */
if(!s->budget--) { s->failed_pc=0x0c06c632u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c06c634: /* original 6ef6, guest PC 0x0c06c634 */
if(!s->budget--) { s->failed_pc=0x0c06c634u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c06c636;
P_0c06c636: /* original 2fe6, guest PC 0x0c06c636 */
if(!s->budget--) { s->failed_pc=0x0c06c636u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06c638;
P_0c06c638: /* original 4400, guest PC 0x0c06c638 */
if(!s->budget--) { s->failed_pc=0x0c06c638u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c06c63a;
P_0c06c63a: /* original 4f22, guest PC 0x0c06c63a */
if(!s->budget--) { s->failed_pc=0x0c06c63au; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c06c63c;
P_0c06c63c: /* original e101, guest PC 0x0c06c63c */
if(!s->budget--) { s->failed_pc=0x0c06c63cu; return 0; }
r[1]=0x00000001u;
goto P_0c06c63e;
P_0c06c63e: /* original 6e53, guest PC 0x0c06c63e */
if(!s->budget--) { s->failed_pc=0x0c06c63eu; return 0; }
r[14]=r[5];
goto P_0c06c640;
P_0c06c640: /* original 7ff8, guest PC 0x0c06c640 */
if(!s->budget--) { s->failed_pc=0x0c06c640u; return 0; }
r[15]+=0xfffffff8u;
goto P_0c06c642;
P_0c06c642: /* original 2f62, guest PC 0x0c06c642 */
if(!s->budget--) { s->failed_pc=0x0c06c642u; return 0; }
write(ram,r[15],r[6],4);
goto P_0c06c644;
P_0c06c644: /* original 6643, guest PC 0x0c06c644 */
if(!s->budget--) { s->failed_pc=0x0c06c644u; return 0; }
r[6]=r[4];
goto P_0c06c646;
P_0c06c646: /* original d326, guest PC 0x0c06c646 */
if(!s->budget--) { s->failed_pc=0x0c06c646u; return 0; }
r[3]=read(ram,0x0c06c6e0u,4);
goto P_0c06c648;
P_0c06c648: /* original 1f31, guest PC 0x0c06c648 */
if(!s->budget--) { s->failed_pc=0x0c06c648u; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c06c64a;
P_0c06c64a: /* original e307, guest PC 0x0c06c64a */
if(!s->budget--) { s->failed_pc=0x0c06c64au; return 0; }
r[3]=0x00000007u;
goto P_0c06c64c;
P_0c06c64c: /* original d228, guest PC 0x0c06c64c */
if(!s->budget--) { s->failed_pc=0x0c06c64cu; return 0; }
r[2]=read(ram,0x0c06c6f0u,4);
goto P_0c06c64e;
P_0c06c64e: /* original 4e3d, guest PC 0x0c06c64e */
if(!s->budget--) { s->failed_pc=0x0c06c64eu; return 0; }
r[14]=(r[3]&0x80000000u)?((r[3]&31u)?r[14]>>((-r[3])&31u):0):r[14]<<(r[3]&31u);
goto P_0c06c650;
P_0c06c650: /* original 6422, guest PC 0x0c06c650 */
if(!s->budget--) { s->failed_pc=0x0c06c650u; return 0; }
tmp=read(ram,r[2],4);
r[4]=tmp;
goto P_0c06c652;
P_0c06c652: /* original 3416, guest PC 0x0c06c652 */
if(!s->budget--) { s->failed_pc=0x0c06c652u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>r[1])!=0);
goto P_0c06c654;
P_0c06c654: /* original 8d03, guest PC 0x0c06c654 */
if(!s->budget--) { s->failed_pc=0x0c06c654u; return 0; }
cond=r[17]&1u;
r[6]|=r[14];
if(cond) { goto P_0c06c65e; }
goto P_0c06c658;
P_0c06c656: /* original 26eb, guest PC 0x0c06c656 */
if(!s->budget--) { s->failed_pc=0x0c06c656u; return 0; }
r[6]|=r[14];
goto P_0c06c658;
P_0c06c658: /* original d526, guest PC 0x0c06c658 */
if(!s->budget--) { s->failed_pc=0x0c06c658u; return 0; }
r[5]=read(ram,0x0c06c6f4u,4);
goto P_0c06c65a;
P_0c06c65a: /* original a001, guest PC 0x0c06c65a */
if(!s->budget--) { s->failed_pc=0x0c06c65au; return 0; }
goto P_0c06c660;
P_0c06c65c: /* original 0009, guest PC 0x0c06c65c */
if(!s->budget--) { s->failed_pc=0x0c06c65cu; return 0; }
goto P_0c06c65e;
P_0c06c65e: /* original d526, guest PC 0x0c06c65e */
if(!s->budget--) { s->failed_pc=0x0c06c65eu; return 0; }
r[5]=read(ram,0x0c06c6f8u,4);
goto P_0c06c660;
P_0c06c660: /* original b023, guest PC 0x0c06c660 */
if(!s->budget--) { s->failed_pc=0x0c06c660u; return 0; }
target=code_base|0x0c06c6aau; r[16]=code_base|0x0c06c664u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06c664u) { target=s->pc; goto dispatch; }
goto P_0c06c664;
P_0c06c662: /* original 0009, guest PC 0x0c06c662 */
if(!s->budget--) { s->failed_pc=0x0c06c662u; return 0; }
goto P_0c06c664;
P_0c06c664: /* original d225, guest PC 0x0c06c664 */
if(!s->budget--) { s->failed_pc=0x0c06c664u; return 0; }
r[2]=read(ram,0x0c06c6fcu,4);
goto P_0c06c666;
P_0c06c666: /* original d326, guest PC 0x0c06c666 */
if(!s->budget--) { s->failed_pc=0x0c06c666u; return 0; }
r[3]=read(ram,0x0c06c700u,4);
goto P_0c06c668;
P_0c06c668: /* original 6422, guest PC 0x0c06c668 */
if(!s->budget--) { s->failed_pc=0x0c06c668u; return 0; }
tmp=read(ram,r[2],4);
r[4]=tmp;
goto P_0c06c66a;
P_0c06c66a: /* original 2438, guest PC 0x0c06c66a */
if(!s->budget--) { s->failed_pc=0x0c06c66au; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[3])==0)!=0);
goto P_0c06c66c;
P_0c06c66c: /* original 8b0e, guest PC 0x0c06c66c */
if(!s->budget--) { s->failed_pc=0x0c06c66cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06c68c; }
goto P_0c06c66e;
P_0c06c66e: /* original d125, guest PC 0x0c06c66e */
if(!s->budget--) { s->failed_pc=0x0c06c66eu; return 0; }
r[1]=read(ram,0x0c06c704u,4);
goto P_0c06c670;
P_0c06c670: /* original 6010, guest PC 0x0c06c670 */
if(!s->budget--) { s->failed_pc=0x0c06c670u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[1],1);
r[0]=tmp;
goto P_0c06c672;
P_0c06c672: /* original 600c, guest PC 0x0c06c672 */
if(!s->budget--) { s->failed_pc=0x0c06c672u; return 0; }
r[0]=r[0]&255u;
goto P_0c06c674;
P_0c06c674: /* original 8803, guest PC 0x0c06c674 */
if(!s->budget--) { s->failed_pc=0x0c06c674u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000003u)!=0);
goto P_0c06c676;
P_0c06c676: /* original 8b14, guest PC 0x0c06c676 */
if(!s->budget--) { s->failed_pc=0x0c06c676u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06c6a2; }
goto P_0c06c678;
P_0c06c678: /* original 64f2, guest PC 0x0c06c678 */
if(!s->budget--) { s->failed_pc=0x0c06c678u; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c06c67a;
P_0c06c67a: /* original d523, guest PC 0x0c06c67a */
if(!s->budget--) { s->failed_pc=0x0c06c67au; return 0; }
r[5]=read(ram,0x0c06c708u,4);
goto P_0c06c67c;
P_0c06c67c: /* original 7403, guest PC 0x0c06c67c */
if(!s->budget--) { s->failed_pc=0x0c06c67cu; return 0; }
r[4]+=0x00000003u;
goto P_0c06c67e;
P_0c06c67e: /* original d223, guest PC 0x0c06c67e */
if(!s->budget--) { s->failed_pc=0x0c06c67eu; return 0; }
r[2]=read(ram,0x0c06c70cu,4);
goto P_0c06c680;
P_0c06c680: /* original 4400, guest PC 0x0c06c680 */
if(!s->budget--) { s->failed_pc=0x0c06c680u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c06c682;
P_0c06c682: /* original 24eb, guest PC 0x0c06c682 */
if(!s->budget--) { s->failed_pc=0x0c06c682u; return 0; }
r[4]|=r[14];
goto P_0c06c684;
P_0c06c684: /* original 420b, guest PC 0x0c06c684 */
if(!s->budget--) { s->failed_pc=0x0c06c684u; return 0; }
target=r[2];
r[16]=code_base|0x0c06c688u;
r[6]=0x00000001u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06c688u) { target=s->pc; goto dispatch; }
goto P_0c06c688;
P_0c06c686: /* original e601, guest PC 0x0c06c686 */
if(!s->budget--) { s->failed_pc=0x0c06c686u; return 0; }
r[6]=0x00000001u;
goto P_0c06c688;
P_0c06c688: /* original a00b, guest PC 0x0c06c688 */
if(!s->budget--) { s->failed_pc=0x0c06c688u; return 0; }
goto P_0c06c6a2;
P_0c06c68a: /* original 0009, guest PC 0x0c06c68a */
if(!s->budget--) { s->failed_pc=0x0c06c68au; return 0; }
goto P_0c06c68c;
P_0c06c68c: /* original 65f2, guest PC 0x0c06c68c */
if(!s->budget--) { s->failed_pc=0x0c06c68cu; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c06c68e;
P_0c06c68e: /* original e120, guest PC 0x0c06c68e */
if(!s->budget--) { s->failed_pc=0x0c06c68eu; return 0; }
r[1]=0x00000020u;
goto P_0c06c690;
P_0c06c690: /* original e615, guest PC 0x0c06c690 */
if(!s->budget--) { s->failed_pc=0x0c06c690u; return 0; }
r[6]=0x00000015u;
goto P_0c06c692;
P_0c06c692: /* original 2f16, guest PC 0x0c06c692 */
if(!s->budget--) { s->failed_pc=0x0c06c692u; return 0; }
tmp=r[1]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06c694;
P_0c06c694: /* original d215, guest PC 0x0c06c694 */
if(!s->budget--) { s->failed_pc=0x0c06c694u; return 0; }
r[2]=read(ram,0x0c06c6ecu,4);
goto P_0c06c696;
P_0c06c696: /* original 4500, guest PC 0x0c06c696 */
if(!s->budget--) { s->failed_pc=0x0c06c696u; return 0; }
r[17]=(r[17]&~1u)|((r[5]>>31)!=0);
r[5]<<=1;
goto P_0c06c698;
P_0c06c698: /* original e701, guest PC 0x0c06c698 */
if(!s->budget--) { s->failed_pc=0x0c06c698u; return 0; }
r[7]=0x00000001u;
goto P_0c06c69a;
P_0c06c69a: /* original 25eb, guest PC 0x0c06c69a */
if(!s->budget--) { s->failed_pc=0x0c06c69au; return 0; }
r[5]|=r[14];
goto P_0c06c69c;
P_0c06c69c: /* original 420b, guest PC 0x0c06c69c */
if(!s->budget--) { s->failed_pc=0x0c06c69cu; return 0; }
target=r[2];
r[16]=code_base|0x0c06c6a0u;
r[4]=read(ram,r[15]+8,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06c6a0u) { target=s->pc; goto dispatch; }
goto P_0c06c6a0;
P_0c06c69e: /* original 54f2, guest PC 0x0c06c69e */
if(!s->budget--) { s->failed_pc=0x0c06c69eu; return 0; }
r[4]=read(ram,r[15]+8,4);
goto P_0c06c6a0;
P_0c06c6a0: /* original 7f04, guest PC 0x0c06c6a0 */
if(!s->budget--) { s->failed_pc=0x0c06c6a0u; return 0; }
r[15]+=0x00000004u;
goto P_0c06c6a2;
P_0c06c6a2: /* original 7f08, guest PC 0x0c06c6a2 */
if(!s->budget--) { s->failed_pc=0x0c06c6a2u; return 0; }
r[15]+=0x00000008u;
goto P_0c06c6a4;
P_0c06c6a4: /* original 4f26, guest PC 0x0c06c6a4 */
if(!s->budget--) { s->failed_pc=0x0c06c6a4u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c06c6a6;
P_0c06c6a6: /* original 000b, guest PC 0x0c06c6a6 */
if(!s->budget--) { s->failed_pc=0x0c06c6a6u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c06c6a8: /* original 6ef6, guest PC 0x0c06c6a8 */
if(!s->budget--) { s->failed_pc=0x0c06c6a8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c06c6aau,s,ram);
unsupported: s->failed_pc=target; return 0;
}
