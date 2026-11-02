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
int vf3_away_batch25_adapter_10(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
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
case 0x0c042efcu: goto P_0c042efc;
case 0x0c042efeu: goto P_0c042efe;
case 0x0c042f00u: goto P_0c042f00;
case 0x0c042f02u: goto P_0c042f02;
case 0x0c042f04u: goto P_0c042f04;
case 0x0c042f06u: goto P_0c042f06;
case 0x0c042f08u: goto P_0c042f08;
case 0x0c042f0au: goto P_0c042f0a;
case 0x0c042f0cu: goto P_0c042f0c;
case 0x0c042f0eu: goto P_0c042f0e;
case 0x0c042f10u: goto P_0c042f10;
case 0x0c042f12u: goto P_0c042f12;
case 0x0c043018u: goto P_0c043018;
case 0x0c04301au: goto P_0c04301a;
case 0x0c04301cu: goto P_0c04301c;
case 0x0c04301eu: goto P_0c04301e;
case 0x0c043020u: goto P_0c043020;
case 0x0c043022u: goto P_0c043022;
case 0x0c043024u: goto P_0c043024;
case 0x0c043026u: goto P_0c043026;
case 0x0c043028u: goto P_0c043028;
case 0x0c04302au: goto P_0c04302a;
case 0x0c04302cu: goto P_0c04302c;
case 0x0c04302eu: goto P_0c04302e;
case 0x0c043030u: goto P_0c043030;
case 0x0c043032u: goto P_0c043032;
case 0x0c043034u: goto P_0c043034;
case 0x0c043036u: goto P_0c043036;
case 0x0c043038u: goto P_0c043038;
case 0x0c04303au: goto P_0c04303a;
case 0x0c04303cu: goto P_0c04303c;
case 0x0c04303eu: goto P_0c04303e;
case 0x0c043040u: goto P_0c043040;
case 0x0c043042u: goto P_0c043042;
case 0x0c043044u: goto P_0c043044;
case 0x0c043046u: goto P_0c043046;
case 0x0c043048u: goto P_0c043048;
case 0x0c04304au: goto P_0c04304a;
case 0x0c04304cu: goto P_0c04304c;
case 0x0c04304eu: goto P_0c04304e;
case 0x0c043050u: goto P_0c043050;
case 0x0c043052u: goto P_0c043052;
case 0x0c043054u: goto P_0c043054;
case 0x0c043056u: goto P_0c043056;
case 0x0c043058u: goto P_0c043058;
case 0x0c04305au: goto P_0c04305a;
case 0x0c04305cu: goto P_0c04305c;
case 0x0c04305eu: goto P_0c04305e;
case 0x0c043060u: goto P_0c043060;
case 0x0c046314u: goto P_0c046314;
case 0x0c046316u: goto P_0c046316;
case 0x0c0474d0u: goto P_0c0474d0;
case 0x0c0474d2u: goto P_0c0474d2;
case 0x0c0474d4u: goto P_0c0474d4;
case 0x0c0474d6u: goto P_0c0474d6;
case 0x0c0474d8u: goto P_0c0474d8;
case 0x0c0474dau: goto P_0c0474da;
case 0x0c0474dcu: goto P_0c0474dc;
case 0x0c0474deu: goto P_0c0474de;
case 0x0c0474e0u: goto P_0c0474e0;
case 0x0c0474e2u: goto P_0c0474e2;
case 0x0c0474e4u: goto P_0c0474e4;
case 0x0c0474e6u: goto P_0c0474e6;
case 0x0c0474e8u: goto P_0c0474e8;
case 0x0c0474eau: goto P_0c0474ea;
case 0x0c0474ecu: goto P_0c0474ec;
case 0x0c0474eeu: goto P_0c0474ee;
case 0x0c0474f0u: goto P_0c0474f0;
case 0x0c0474f2u: goto P_0c0474f2;
case 0x0c0474f4u: goto P_0c0474f4;
case 0x0c0474f6u: goto P_0c0474f6;
case 0x0c0474f8u: goto P_0c0474f8;
case 0x0c0474fau: goto P_0c0474fa;
case 0x0c0474fcu: goto P_0c0474fc;
case 0x0c047520u: goto P_0c047520;
case 0x0c047522u: goto P_0c047522;
case 0x0c047524u: goto P_0c047524;
case 0x0c047526u: goto P_0c047526;
case 0x0c047528u: goto P_0c047528;
case 0x0c04752au: goto P_0c04752a;
case 0x0c04752cu: goto P_0c04752c;
case 0x0c04752eu: goto P_0c04752e;
case 0x0c047530u: goto P_0c047530;
case 0x0c047532u: goto P_0c047532;
case 0x0c047534u: goto P_0c047534;
case 0x0c047536u: goto P_0c047536;
case 0x0c047538u: goto P_0c047538;
case 0x0c04753au: goto P_0c04753a;
case 0x0c0475f0u: goto P_0c0475f0;
case 0x0c0475f2u: goto P_0c0475f2;
case 0x0c0475f4u: goto P_0c0475f4;
case 0x0c0475f6u: goto P_0c0475f6;
case 0x0c0475f8u: goto P_0c0475f8;
case 0x0c0475fau: goto P_0c0475fa;
case 0x0c0475fcu: goto P_0c0475fc;
case 0x0c0475feu: goto P_0c0475fe;
case 0x0c047600u: goto P_0c047600;
case 0x0c047602u: goto P_0c047602;
case 0x0c047604u: goto P_0c047604;
case 0x0c047606u: goto P_0c047606;
case 0x0c047608u: goto P_0c047608;
case 0x0c04760au: goto P_0c04760a;
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
P_0c042efc: /* original 2f36, guest PC 0x0c042efc */
if(!s->budget--) { s->failed_pc=0x0c042efcu; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c042efe;
P_0c042efe: /* original d305, guest PC 0x0c042efe */
if(!s->budget--) { s->failed_pc=0x0c042efeu; return 0; }
r[3]=read(ram,0x0c042f14u,4);
goto P_0c042f00;
P_0c042f00: /* original 033e, guest PC 0x0c042f00 */
if(!s->budget--) { s->failed_pc=0x0c042f00u; return 0; }
r[3]=read(ram,r[3]+r[0],4);
goto P_0c042f02;
P_0c042f02: /* original 70fc, guest PC 0x0c042f02 */
if(!s->budget--) { s->failed_pc=0x0c042f02u; return 0; }
r[0]+=0xfffffffcu;
goto P_0c042f04;
P_0c042f04: /* original 432b, guest PC 0x0c042f04 */
if(!s->budget--) { s->failed_pc=0x0c042f04u; return 0; }
target=r[3];
r[0]=read(ram,r[2]+r[0],4);
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
P_0c042f06: /* original 002e, guest PC 0x0c042f06 */
if(!s->budget--) { s->failed_pc=0x0c042f06u; return 0; }
r[0]=read(ram,r[2]+r[0],4);
goto P_0c042f08;
P_0c042f08: /* original 2f36, guest PC 0x0c042f08 */
if(!s->budget--) { s->failed_pc=0x0c042f08u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c042f0a;
P_0c042f0a: /* original d302, guest PC 0x0c042f0a */
if(!s->budget--) { s->failed_pc=0x0c042f0au; return 0; }
r[3]=read(ram,0x0c042f14u,4);
goto P_0c042f0c;
P_0c042f0c: /* original 033e, guest PC 0x0c042f0c */
if(!s->budget--) { s->failed_pc=0x0c042f0cu; return 0; }
r[3]=read(ram,r[3]+r[0],4);
goto P_0c042f0e;
P_0c042f0e: /* original 70fc, guest PC 0x0c042f0e */
if(!s->budget--) { s->failed_pc=0x0c042f0eu; return 0; }
r[0]+=0xfffffffcu;
goto P_0c042f10;
P_0c042f10: /* original 432b, guest PC 0x0c042f10 */
if(!s->budget--) { s->failed_pc=0x0c042f10u; return 0; }
target=r[3];
r[3]=read(ram,r[2]+r[0],4);
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
P_0c042f12: /* original 032e, guest PC 0x0c042f12 */
if(!s->budget--) { s->failed_pc=0x0c042f12u; return 0; }
r[3]=read(ram,r[2]+r[0],4);
if(!vf3_matrix_family(0x0c042f14u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c042f14u; return 0; } return 1;
P_0c043018: /* original 3450, guest PC 0x0c043018 */
if(!s->budget--) { s->failed_pc=0x0c043018u; return 0; }
r[17]=(r[17]&~1u)|((r[4]==r[5])!=0);
goto P_0c04301a;
P_0c04301a: /* original 8d20, guest PC 0x0c04301a */
if(!s->budget--) { s->failed_pc=0x0c04301au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04305e; }
goto P_0c04301e;
P_0c04301c: /* original 0009, guest PC 0x0c04301c */
if(!s->budget--) { s->failed_pc=0x0c04301cu; return 0; }
goto P_0c04301e;
P_0c04301e: /* original 3452, guest PC 0x0c04301e */
if(!s->budget--) { s->failed_pc=0x0c04301eu; return 0; }
r[17]=(r[17]&~1u)|((r[4]>=r[5])!=0);
goto P_0c043020;
P_0c043020: /* original 8d0e, guest PC 0x0c043020 */
if(!s->budget--) { s->failed_pc=0x0c043020u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c043040; }
goto P_0c043024;
P_0c043022: /* original 0009, guest PC 0x0c043022 */
if(!s->budget--) { s->failed_pc=0x0c043022u; return 0; }
goto P_0c043024;
P_0c043024: /* original 6753, guest PC 0x0c043024 */
if(!s->budget--) { s->failed_pc=0x0c043024u; return 0; }
r[7]=r[5];
goto P_0c043026;
P_0c043026: /* original e500, guest PC 0x0c043026 */
if(!s->budget--) { s->failed_pc=0x0c043026u; return 0; }
r[5]=0x00000000u;
goto P_0c043028;
P_0c043028: /* original 6353, guest PC 0x0c043028 */
if(!s->budget--) { s->failed_pc=0x0c043028u; return 0; }
r[3]=r[5];
goto P_0c04302a;
P_0c04302a: /* original 3362, guest PC 0x0c04302a */
if(!s->budget--) { s->failed_pc=0x0c04302au; return 0; }
r[17]=(r[17]&~1u)|((r[3]>=r[6])!=0);
goto P_0c04302c;
P_0c04302c: /* original 8d17, guest PC 0x0c04302c */
if(!s->budget--) { s->failed_pc=0x0c04302cu; return 0; }
cond=r[17]&1u;
r[0]=r[4];
if(cond) { goto P_0c04305e; }
goto P_0c043030;
P_0c04302e: /* original 6043, guest PC 0x0c04302e */
if(!s->budget--) { s->failed_pc=0x0c04302eu; return 0; }
r[0]=r[4];
goto P_0c043030;
P_0c043030: /* original 6374, guest PC 0x0c043030 */
if(!s->budget--) { s->failed_pc=0x0c043030u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[7],1);
r[7]+=1;
r[3]=tmp;
goto P_0c043032;
P_0c043032: /* original 7501, guest PC 0x0c043032 */
if(!s->budget--) { s->failed_pc=0x0c043032u; return 0; }
r[5]+=0x00000001u;
goto P_0c043034;
P_0c043034: /* original 2030, guest PC 0x0c043034 */
if(!s->budget--) { s->failed_pc=0x0c043034u; return 0; }
write(ram,r[0],r[3],1);
goto P_0c043036;
P_0c043036: /* original 3562, guest PC 0x0c043036 */
if(!s->budget--) { s->failed_pc=0x0c043036u; return 0; }
r[17]=(r[17]&~1u)|((r[5]>=r[6])!=0);
goto P_0c043038;
P_0c043038: /* original 8ffa, guest PC 0x0c043038 */
if(!s->budget--) { s->failed_pc=0x0c043038u; return 0; }
cond=r[17]&1u;
r[0]+=0x00000001u;
if(!cond) { goto P_0c043030; }
goto P_0c04303c;
P_0c04303a: /* original 7001, guest PC 0x0c04303a */
if(!s->budget--) { s->failed_pc=0x0c04303au; return 0; }
r[0]+=0x00000001u;
goto P_0c04303c;
P_0c04303c: /* original a00f, guest PC 0x0c04303c */
if(!s->budget--) { s->failed_pc=0x0c04303cu; return 0; }
goto P_0c04305e;
P_0c04303e: /* original 0009, guest PC 0x0c04303e */
if(!s->budget--) { s->failed_pc=0x0c04303eu; return 0; }
goto P_0c043040;
P_0c043040: /* original 6743, guest PC 0x0c043040 */
if(!s->budget--) { s->failed_pc=0x0c043040u; return 0; }
r[7]=r[4];
goto P_0c043042;
P_0c043042: /* original 376c, guest PC 0x0c043042 */
if(!s->budget--) { s->failed_pc=0x0c043042u; return 0; }
r[7]+=r[6];
goto P_0c043044;
P_0c043044: /* original 6053, guest PC 0x0c043044 */
if(!s->budget--) { s->failed_pc=0x0c043044u; return 0; }
r[0]=r[5];
goto P_0c043046;
P_0c043046: /* original 0009, guest PC 0x0c043046 */
if(!s->budget--) { s->failed_pc=0x0c043046u; return 0; }
goto P_0c043048;
P_0c043048: /* original e500, guest PC 0x0c043048 */
if(!s->budget--) { s->failed_pc=0x0c043048u; return 0; }
r[5]=0x00000000u;
goto P_0c04304a;
P_0c04304a: /* original 6253, guest PC 0x0c04304a */
if(!s->budget--) { s->failed_pc=0x0c04304au; return 0; }
r[2]=r[5];
goto P_0c04304c;
P_0c04304c: /* original 3262, guest PC 0x0c04304c */
if(!s->budget--) { s->failed_pc=0x0c04304cu; return 0; }
r[17]=(r[17]&~1u)|((r[2]>=r[6])!=0);
goto P_0c04304e;
P_0c04304e: /* original 8d06, guest PC 0x0c04304e */
if(!s->budget--) { s->failed_pc=0x0c04304eu; return 0; }
cond=r[17]&1u;
r[0]+=r[6];
if(cond) { goto P_0c04305e; }
goto P_0c043052;
P_0c043050: /* original 306c, guest PC 0x0c043050 */
if(!s->budget--) { s->failed_pc=0x0c043050u; return 0; }
r[0]+=r[6];
goto P_0c043052;
P_0c043052: /* original 70ff, guest PC 0x0c043052 */
if(!s->budget--) { s->failed_pc=0x0c043052u; return 0; }
r[0]+=0xffffffffu;
goto P_0c043054;
P_0c043054: /* original 6300, guest PC 0x0c043054 */
if(!s->budget--) { s->failed_pc=0x0c043054u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[0],1);
r[3]=tmp;
goto P_0c043056;
P_0c043056: /* original 7501, guest PC 0x0c043056 */
if(!s->budget--) { s->failed_pc=0x0c043056u; return 0; }
r[5]+=0x00000001u;
goto P_0c043058;
P_0c043058: /* original 3562, guest PC 0x0c043058 */
if(!s->budget--) { s->failed_pc=0x0c043058u; return 0; }
r[17]=(r[17]&~1u)|((r[5]>=r[6])!=0);
goto P_0c04305a;
P_0c04305a: /* original 8ffa, guest PC 0x0c04305a */
if(!s->budget--) { s->failed_pc=0x0c04305au; return 0; }
cond=r[17]&1u;
tmp=r[3]; r[7]-=1; write(ram,r[7],tmp,1);
if(!cond) { goto P_0c043052; }
goto P_0c04305e;
P_0c04305c: /* original 2734, guest PC 0x0c04305c */
if(!s->budget--) { s->failed_pc=0x0c04305cu; return 0; }
tmp=r[3]; r[7]-=1; write(ram,r[7],tmp,1);
goto P_0c04305e;
P_0c04305e: /* original 000b, guest PC 0x0c04305e */
if(!s->budget--) { s->failed_pc=0x0c04305eu; return 0; }
target=r[16];
r[0]=r[4];
s->pc=target; return ram->oob==0;
P_0c043060: /* original 6043, guest PC 0x0c043060 */
if(!s->budget--) { s->failed_pc=0x0c043060u; return 0; }
r[0]=r[4];
if(!vf3_matrix_family(0x0c043062u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c043062u; return 0; } return 1;
P_0c046314: /* original 000b, guest PC 0x0c046314 */
if(!s->budget--) { s->failed_pc=0x0c046314u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c046316: /* original 0009, guest PC 0x0c046316 */
if(!s->budget--) { s->failed_pc=0x0c046316u; return 0; }
if(!vf3_matrix_family(0x0c046318u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c046318u; return 0; } return 1;
P_0c0474d0: /* original 6343, guest PC 0x0c0474d0 */
if(!s->budget--) { s->failed_pc=0x0c0474d0u; return 0; }
r[3]=r[4];
goto P_0c0474d2;
P_0c0474d2: /* original e2fc, guest PC 0x0c0474d2 */
if(!s->budget--) { s->failed_pc=0x0c0474d2u; return 0; }
r[2]=0xfffffffcu;
goto P_0c0474d4;
P_0c0474d4: /* original 2fe6, guest PC 0x0c0474d4 */
if(!s->budget--) { s->failed_pc=0x0c0474d4u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0474d6;
P_0c0474d6: /* original 432c, guest PC 0x0c0474d6 */
if(!s->budget--) { s->failed_pc=0x0c0474d6u; return 0; }
r[3]=(r[2]&0x80000000u)?((r[2]&31u)?(uint32_t)((int32_t)r[3]>>((-r[2])&31u)):((int32_t)r[3]<0?0xffffffffu:0)):r[3]<<(r[2]&31u);
goto P_0c0474d8;
P_0c0474d8: /* original e701, guest PC 0x0c0474d8 */
if(!s->budget--) { s->failed_pc=0x0c0474d8u; return 0; }
r[7]=0x00000001u;
goto P_0c0474da;
P_0c0474da: /* original 6633, guest PC 0x0c0474da */
if(!s->budget--) { s->failed_pc=0x0c0474dau; return 0; }
r[6]=r[3];
goto P_0c0474dc;
P_0c0474dc: /* original e20f, guest PC 0x0c0474dc */
if(!s->budget--) { s->failed_pc=0x0c0474dcu; return 0; }
r[2]=0x0000000fu;
goto P_0c0474de;
P_0c0474de: /* original 6173, guest PC 0x0c0474de */
if(!s->budget--) { s->failed_pc=0x0c0474deu; return 0; }
r[1]=r[7];
goto P_0c0474e0;
P_0c0474e0: /* original 7ff8, guest PC 0x0c0474e0 */
if(!s->budget--) { s->failed_pc=0x0c0474e0u; return 0; }
r[15]+=0xfffffff8u;
goto P_0c0474e2;
P_0c0474e2: /* original 2429, guest PC 0x0c0474e2 */
if(!s->budget--) { s->failed_pc=0x0c0474e2u; return 0; }
r[4]&=r[2];
goto P_0c0474e4;
P_0c0474e4: /* original 2f52, guest PC 0x0c0474e4 */
if(!s->budget--) { s->failed_pc=0x0c0474e4u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0474e6;
P_0c0474e6: /* original 414c, guest PC 0x0c0474e6 */
if(!s->budget--) { s->failed_pc=0x0c0474e6u; return 0; }
r[1]=(r[4]&0x80000000u)?((r[4]&31u)?(uint32_t)((int32_t)r[1]>>((-r[4])&31u)):((int32_t)r[1]<0?0xffffffffu:0)):r[1]<<(r[4]&31u);
goto P_0c0474e8;
P_0c0474e8: /* original 1f31, guest PC 0x0c0474e8 */
if(!s->budget--) { s->failed_pc=0x0c0474e8u; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c0474ea;
P_0c0474ea: /* original 65f2, guest PC 0x0c0474ea */
if(!s->budget--) { s->failed_pc=0x0c0474eau; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0474ec;
P_0c0474ec: /* original 6413, guest PC 0x0c0474ec */
if(!s->budget--) { s->failed_pc=0x0c0474ecu; return 0; }
r[4]=r[1];
goto P_0c0474ee;
P_0c0474ee: /* original e1fc, guest PC 0x0c0474ee */
if(!s->budget--) { s->failed_pc=0x0c0474eeu; return 0; }
r[1]=0xfffffffcu;
goto P_0c0474f0;
P_0c0474f0: /* original de07, guest PC 0x0c0474f0 */
if(!s->budget--) { s->failed_pc=0x0c0474f0u; return 0; }
r[14]=read(ram,0x0c047510u,4);
goto P_0c0474f2;
P_0c0474f2: /* original 352c, guest PC 0x0c0474f2 */
if(!s->budget--) { s->failed_pc=0x0c0474f2u; return 0; }
r[5]+=r[2];
goto P_0c0474f4;
P_0c0474f4: /* original 451c, guest PC 0x0c0474f4 */
if(!s->budget--) { s->failed_pc=0x0c0474f4u; return 0; }
r[5]=(r[1]&0x80000000u)?((r[1]&31u)?(uint32_t)((int32_t)r[5]>>((-r[1])&31u)):((int32_t)r[5]<0?0xffffffffu:0)):r[5]<<(r[1]&31u);
goto P_0c0474f6;
P_0c0474f6: /* original d103, guest PC 0x0c0474f6 */
if(!s->budget--) { s->failed_pc=0x0c0474f6u; return 0; }
r[1]=read(ram,0x0c047504u,4);
goto P_0c0474f8;
P_0c0474f8: /* original 4600, guest PC 0x0c0474f8 */
if(!s->budget--) { s->failed_pc=0x0c0474f8u; return 0; }
r[17]=(r[17]&~1u)|((r[6]>>31)!=0);
r[6]<<=1;
goto P_0c0474fa;
P_0c0474fa: /* original a019, guest PC 0x0c0474fa */
if(!s->budget--) { s->failed_pc=0x0c0474fau; return 0; }
r[6]+=r[1];
goto P_0c047530;
P_0c0474fc: /* original 361c, guest PC 0x0c0474fc */
if(!s->budget--) { s->failed_pc=0x0c0474fcu; return 0; }
r[6]+=r[1];
if(!vf3_matrix_family(0x0c0474feu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0474feu; return 0; } return 1;
P_0c047520: /* original 6361, guest PC 0x0c047520 */
if(!s->budget--) { s->failed_pc=0x0c047520u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[6],2);
r[3]=tmp;
goto P_0c047522;
P_0c047522: /* original 234b, guest PC 0x0c047522 */
if(!s->budget--) { s->failed_pc=0x0c047522u; return 0; }
r[3]|=r[4];
goto P_0c047524;
P_0c047524: /* original 344c, guest PC 0x0c047524 */
if(!s->budget--) { s->failed_pc=0x0c047524u; return 0; }
r[4]+=r[4];
goto P_0c047526;
P_0c047526: /* original 34e3, guest PC 0x0c047526 */
if(!s->budget--) { s->failed_pc=0x0c047526u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=(int32_t)r[14])!=0);
goto P_0c047528;
P_0c047528: /* original 8f02, guest PC 0x0c047528 */
if(!s->budget--) { s->failed_pc=0x0c047528u; return 0; }
cond=r[17]&1u;
write(ram,r[6],r[3],2);
if(!cond) { goto P_0c047530; }
goto P_0c04752c;
P_0c04752a: /* original 2631, guest PC 0x0c04752a */
if(!s->budget--) { s->failed_pc=0x0c04752au; return 0; }
write(ram,r[6],r[3],2);
goto P_0c04752c;
P_0c04752c: /* original 6473, guest PC 0x0c04752c */
if(!s->budget--) { s->failed_pc=0x0c04752cu; return 0; }
r[4]=r[7];
goto P_0c04752e;
P_0c04752e: /* original 7602, guest PC 0x0c04752e */
if(!s->budget--) { s->failed_pc=0x0c04752eu; return 0; }
r[6]+=0x00000002u;
goto P_0c047530;
P_0c047530: /* original 4515, guest PC 0x0c047530 */
if(!s->budget--) { s->failed_pc=0x0c047530u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[5]>0)!=0);
goto P_0c047532;
P_0c047532: /* original 8df5, guest PC 0x0c047532 */
if(!s->budget--) { s->failed_pc=0x0c047532u; return 0; }
cond=r[17]&1u;
r[5]+=0xffffffffu;
if(cond) { goto P_0c047520; }
goto P_0c047536;
P_0c047534: /* original 75ff, guest PC 0x0c047534 */
if(!s->budget--) { s->failed_pc=0x0c047534u; return 0; }
r[5]+=0xffffffffu;
goto P_0c047536;
P_0c047536: /* original 7f08, guest PC 0x0c047536 */
if(!s->budget--) { s->failed_pc=0x0c047536u; return 0; }
r[15]+=0x00000008u;
goto P_0c047538;
P_0c047538: /* original 000b, guest PC 0x0c047538 */
if(!s->budget--) { s->failed_pc=0x0c047538u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c04753a: /* original 6ef6, guest PC 0x0c04753a */
if(!s->budget--) { s->failed_pc=0x0c04753au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c04753cu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c04753cu; return 0; } return 1;
P_0c0475f0: /* original c401, guest PC 0x0c0475f0 */
if(!s->budget--) { s->failed_pc=0x0c0475f0u; return 0; }
if(!s->gbr_known) goto unsupported;
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,s->gbr+1,1);
goto P_0c0475f2;
P_0c0475f2: /* original d20a, guest PC 0x0c0475f2 */
if(!s->budget--) { s->failed_pc=0x0c0475f2u; return 0; }
r[2]=read(ram,0x0c04761cu,4);
goto P_0c0475f4;
P_0c0475f4: /* original 8803, guest PC 0x0c0475f4 */
if(!s->budget--) { s->failed_pc=0x0c0475f4u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000003u)!=0);
goto P_0c0475f6;
P_0c0475f6: /* original 4408, guest PC 0x0c0475f6 */
if(!s->budget--) { s->failed_pc=0x0c0475f6u; return 0; }
r[4]<<=2;
goto P_0c0475f8;
P_0c0475f8: /* original 6023, guest PC 0x0c0475f8 */
if(!s->budget--) { s->failed_pc=0x0c0475f8u; return 0; }
r[0]=r[2];
goto P_0c0475fa;
P_0c0475fa: /* original 8907, guest PC 0x0c0475fa */
if(!s->budget--) { s->failed_pc=0x0c0475fau; return 0; }
cond=r[17]&1u;
if(cond) { return vf3_matrix_family(0x0c04760cu,s,ram); }
goto P_0c0475fc;
P_0c0475fc: /* original 6155, guest PC 0x0c0475fc */
if(!s->budget--) { s->failed_pc=0x0c0475fcu; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[5],2);
r[5]+=2;
r[1]=tmp;
goto P_0c0475fe;
P_0c0475fe: /* original 4610, guest PC 0x0c0475fe */
if(!s->budget--) { s->failed_pc=0x0c0475feu; return 0; }
--r[6];
r[17]=(r[17]&~1u)|((r[6]==0)!=0);
goto P_0c047600;
P_0c047600: /* original 0415, guest PC 0x0c047600 */
if(!s->budget--) { s->failed_pc=0x0c047600u; return 0; }
write(ram,r[4]+r[0],r[1],2);
goto P_0c047602;
P_0c047602: /* original 8ffb, guest PC 0x0c047602 */
if(!s->budget--) { s->failed_pc=0x0c047602u; return 0; }
cond=r[17]&1u;
r[4]+=0x00000004u;
if(!cond) { goto P_0c0475fc; }
goto P_0c047606;
P_0c047604: /* original 7404, guest PC 0x0c047604 */
if(!s->budget--) { s->failed_pc=0x0c047604u; return 0; }
r[4]+=0x00000004u;
goto P_0c047606;
P_0c047606: /* original e001, guest PC 0x0c047606 */
if(!s->budget--) { s->failed_pc=0x0c047606u; return 0; }
r[0]=0x00000001u;
goto P_0c047608;
P_0c047608: /* original 000b, guest PC 0x0c047608 */
if(!s->budget--) { s->failed_pc=0x0c047608u; return 0; }
target=r[16];
if(!s->gbr_known) goto unsupported;
write(ram,s->gbr+0,r[0],1);
s->pc=target; return ram->oob==0;
P_0c04760a: /* original c000, guest PC 0x0c04760a */
if(!s->budget--) { s->failed_pc=0x0c04760au; return 0; }
if(!s->gbr_known) goto unsupported;
write(ram,s->gbr+0,r[0],1);
return vf3_matrix_family(0x0c04760cu,s,ram);
unsupported: s->failed_pc=target; return 0;
}
