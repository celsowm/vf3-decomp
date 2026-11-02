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
int vf3_away_batch175_adapter_9(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
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
case 0x0c04760cu: goto P_0c04760c;
case 0x0c04760eu: goto P_0c04760e;
case 0x0c047610u: goto P_0c047610;
case 0x0c047612u: goto P_0c047612;
case 0x0c047614u: goto P_0c047614;
case 0x0c047616u: goto P_0c047616;
case 0x0c047618u: goto P_0c047618;
case 0x0c04761au: goto P_0c04761a;
case 0x0c055d40u: goto P_0c055d40;
case 0x0c055d42u: goto P_0c055d42;
case 0x0c055d44u: goto P_0c055d44;
case 0x0c055d46u: goto P_0c055d46;
case 0x0c055d48u: goto P_0c055d48;
case 0x0c055d4au: goto P_0c055d4a;
case 0x0c055d4cu: goto P_0c055d4c;
case 0x0c055d4eu: goto P_0c055d4e;
case 0x0c055d50u: goto P_0c055d50;
case 0x0c055d52u: goto P_0c055d52;
case 0x0c055d54u: goto P_0c055d54;
case 0x0c055d56u: goto P_0c055d56;
case 0x0c055d58u: goto P_0c055d58;
case 0x0c055d5au: goto P_0c055d5a;
case 0x0c055d5cu: goto P_0c055d5c;
case 0x0c055d5eu: goto P_0c055d5e;
case 0x0c055d60u: goto P_0c055d60;
case 0x0c055d62u: goto P_0c055d62;
case 0x0c055d64u: goto P_0c055d64;
case 0x0c055d66u: goto P_0c055d66;
case 0x0c055d68u: goto P_0c055d68;
case 0x0c055d6au: goto P_0c055d6a;
case 0x0c055d6cu: goto P_0c055d6c;
case 0x0c055d6eu: goto P_0c055d6e;
case 0x0c055d70u: goto P_0c055d70;
case 0x0c055d72u: goto P_0c055d72;
case 0x0c055d74u: goto P_0c055d74;
case 0x0c055d76u: goto P_0c055d76;
case 0x0c055d78u: goto P_0c055d78;
case 0x0c055d7au: goto P_0c055d7a;
case 0x0c055d7cu: goto P_0c055d7c;
case 0x0c055d7eu: goto P_0c055d7e;
case 0x0c055d80u: goto P_0c055d80;
case 0x0c055d82u: goto P_0c055d82;
case 0x0c055d84u: goto P_0c055d84;
case 0x0c055d86u: goto P_0c055d86;
case 0x0c055d88u: goto P_0c055d88;
case 0x0c055d8au: goto P_0c055d8a;
case 0x0c055d8cu: goto P_0c055d8c;
case 0x0c055d8eu: goto P_0c055d8e;
case 0x0c055d90u: goto P_0c055d90;
case 0x0c055d92u: goto P_0c055d92;
case 0x0c055d94u: goto P_0c055d94;
case 0x0c055d96u: goto P_0c055d96;
case 0x0c055d98u: goto P_0c055d98;
case 0x0c055d9au: goto P_0c055d9a;
case 0x0c055d9cu: goto P_0c055d9c;
case 0x0c055d9eu: goto P_0c055d9e;
case 0x0c055da0u: goto P_0c055da0;
case 0x0c055da2u: goto P_0c055da2;
case 0x0c055da4u: goto P_0c055da4;
case 0x0c055da6u: goto P_0c055da6;
case 0x0c055da8u: goto P_0c055da8;
case 0x0c055daau: goto P_0c055daa;
case 0x0c055dacu: goto P_0c055dac;
case 0x0c055daeu: goto P_0c055dae;
case 0x0c055db0u: goto P_0c055db0;
case 0x0c055db2u: goto P_0c055db2;
case 0x0c055db4u: goto P_0c055db4;
case 0x0c055db6u: goto P_0c055db6;
case 0x0c055db8u: goto P_0c055db8;
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
if(!vf3_matrix_family(0x0c042f08u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c042f08u; return 0; } return 1;
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
if(cond) { goto P_0c04760c; }
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
goto P_0c04760c;
P_0c04760c: /* original 6156, guest PC 0x0c04760c */
if(!s->budget--) { s->failed_pc=0x0c04760cu; return 0; }
tmp=read(ram,r[5],4);
r[5]+=4;
r[1]=tmp;
goto P_0c04760e;
P_0c04760e: /* original 4610, guest PC 0x0c04760e */
if(!s->budget--) { s->failed_pc=0x0c04760eu; return 0; }
--r[6];
r[17]=(r[17]&~1u)|((r[6]==0)!=0);
goto P_0c047610;
P_0c047610: /* original 0416, guest PC 0x0c047610 */
if(!s->budget--) { s->failed_pc=0x0c047610u; return 0; }
write(ram,r[4]+r[0],r[1],4);
goto P_0c047612;
P_0c047612: /* original 8ffb, guest PC 0x0c047612 */
if(!s->budget--) { s->failed_pc=0x0c047612u; return 0; }
cond=r[17]&1u;
r[4]+=0x00000004u;
if(!cond) { goto P_0c04760c; }
goto P_0c047616;
P_0c047614: /* original 7404, guest PC 0x0c047614 */
if(!s->budget--) { s->failed_pc=0x0c047614u; return 0; }
r[4]+=0x00000004u;
goto P_0c047616;
P_0c047616: /* original e001, guest PC 0x0c047616 */
if(!s->budget--) { s->failed_pc=0x0c047616u; return 0; }
r[0]=0x00000001u;
goto P_0c047618;
P_0c047618: /* original 000b, guest PC 0x0c047618 */
if(!s->budget--) { s->failed_pc=0x0c047618u; return 0; }
target=r[16];
if(!s->gbr_known) goto unsupported;
write(ram,s->gbr+0,r[0],1);
s->pc=target; return ram->oob==0;
P_0c04761a: /* original c000, guest PC 0x0c04761a */
if(!s->budget--) { s->failed_pc=0x0c04761au; return 0; }
if(!s->gbr_known) goto unsupported;
write(ram,s->gbr+0,r[0],1);
if(!vf3_matrix_family(0x0c04761cu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c04761cu; return 0; } return 1;
P_0c055d40: /* original 4f22, guest PC 0x0c055d40 */
if(!s->budget--) { s->failed_pc=0x0c055d40u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c055d42;
P_0c055d42: /* original d01f, guest PC 0x0c055d42 */
if(!s->budget--) { s->failed_pc=0x0c055d42u; return 0; }
r[0]=read(ram,0x0c055dc0u,4);
goto P_0c055d44;
P_0c055d44: /* original 6102, guest PC 0x0c055d44 */
if(!s->budget--) { s->failed_pc=0x0c055d44u; return 0; }
tmp=read(ram,r[0],4);
r[1]=tmp;
goto P_0c055d46;
P_0c055d46: /* original 4115, guest PC 0x0c055d46 */
if(!s->budget--) { s->failed_pc=0x0c055d46u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[1]>0)!=0);
goto P_0c055d48;
P_0c055d48: /* original d01c, guest PC 0x0c055d48 */
if(!s->budget--) { s->failed_pc=0x0c055d48u; return 0; }
r[0]=read(ram,0x0c055dbcu,4);
goto P_0c055d4a;
P_0c055d4a: /* original 8d0e, guest PC 0x0c055d4a */
if(!s->budget--) { s->failed_pc=0x0c055d4au; return 0; }
cond=r[17]&1u;
r[4]=r[0];
if(cond) { goto P_0c055d6a; }
goto P_0c055d4e;
P_0c055d4c: /* original 6403, guest PC 0x0c055d4c */
if(!s->budget--) { s->failed_pc=0x0c055d4cu; return 0; }
r[4]=r[0];
goto P_0c055d4e;
P_0c055d4e: /* original 7440, guest PC 0x0c055d4e */
if(!s->budget--) { s->failed_pc=0x0c055d4eu; return 0; }
r[4]+=0x00000040u;
goto P_0c055d50;
P_0c055d50: /* original 6503, guest PC 0x0c055d50 */
if(!s->budget--) { s->failed_pc=0x0c055d50u; return 0; }
r[5]=r[0];
goto P_0c055d52;
P_0c055d52: /* original d31c, guest PC 0x0c055d52 */
if(!s->budget--) { s->failed_pc=0x0c055d52u; return 0; }
r[3]=read(ram,0x0c055dc4u,4);
goto P_0c055d54;
P_0c055d54: /* original 430b, guest PC 0x0c055d54 */
if(!s->budget--) { s->failed_pc=0x0c055d54u; return 0; }
target=r[3];
r[16]=code_base|0x0c055d58u;
r[5]+=0x00000068u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c055d58u) { target=s->pc; goto dispatch; }
goto P_0c055d58;
P_0c055d56: /* original 7568, guest PC 0x0c055d56 */
if(!s->budget--) { s->failed_pc=0x0c055d56u; return 0; }
r[5]+=0x00000068u;
goto P_0c055d58;
P_0c055d58: /* original d01c, guest PC 0x0c055d58 */
if(!s->budget--) { s->failed_pc=0x0c055d58u; return 0; }
r[0]=read(ram,0x0c055dccu,4);
goto P_0c055d5a;
P_0c055d5a: /* original d11f, guest PC 0x0c055d5a */
if(!s->budget--) { s->failed_pc=0x0c055d5au; return 0; }
r[1]=read(ram,0x0c055dd8u,4);
goto P_0c055d5c;
P_0c055d5c: /* original d220, guest PC 0x0c055d5c */
if(!s->budget--) { s->failed_pc=0x0c055d5cu; return 0; }
r[2]=read(ram,0x0c055de0u,4);
goto P_0c055d5e;
P_0c055d5e: /* original c204, guest PC 0x0c055d5e */
if(!s->budget--) { s->failed_pc=0x0c055d5eu; return 0; }
if(!s->gbr_known) goto unsupported;
write(ram,s->gbr+16,r[0],4);
goto P_0c055d60;
P_0c055d60: /* original 6013, guest PC 0x0c055d60 */
if(!s->budget--) { s->failed_pc=0x0c055d60u; return 0; }
r[0]=r[1];
goto P_0c055d62;
P_0c055d62: /* original c205, guest PC 0x0c055d62 */
if(!s->budget--) { s->failed_pc=0x0c055d62u; return 0; }
if(!s->gbr_known) goto unsupported;
write(ram,s->gbr+20,r[0],4);
goto P_0c055d64;
P_0c055d64: /* original 6023, guest PC 0x0c055d64 */
if(!s->budget--) { s->failed_pc=0x0c055d64u; return 0; }
r[0]=r[2];
goto P_0c055d66;
P_0c055d66: /* original a025, guest PC 0x0c055d66 */
if(!s->budget--) { s->failed_pc=0x0c055d66u; return 0; }
if(!s->gbr_known) goto unsupported;
write(ram,s->gbr+12,r[0],4);
goto P_0c055db4;
P_0c055d68: /* original c203, guest PC 0x0c055d68 */
if(!s->budget--) { s->failed_pc=0x0c055d68u; return 0; }
if(!s->gbr_known) goto unsupported;
write(ram,s->gbr+12,r[0],4);
goto P_0c055d6a;
P_0c055d6a: /* original 2fe6, guest PC 0x0c055d6a */
if(!s->budget--) { s->failed_pc=0x0c055d6au; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c055d6c;
P_0c055d6c: /* original 2fd6, guest PC 0x0c055d6c */
if(!s->budget--) { s->failed_pc=0x0c055d6cu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c055d6e;
P_0c055d6e: /* original 6e03, guest PC 0x0c055d6e */
if(!s->budget--) { s->failed_pc=0x0c055d6eu; return 0; }
r[14]=r[0];
goto P_0c055d70;
P_0c055d70: /* original ed10, guest PC 0x0c055d70 */
if(!s->budget--) { s->failed_pc=0x0c055d70u; return 0; }
r[13]=0x00000010u;
goto P_0c055d72;
P_0c055d72: /* original 61e2, guest PC 0x0c055d72 */
if(!s->budget--) { s->failed_pc=0x0c055d72u; return 0; }
tmp=read(ram,r[14],4);
r[1]=tmp;
goto P_0c055d74;
P_0c055d74: /* original 4115, guest PC 0x0c055d74 */
if(!s->budget--) { s->failed_pc=0x0c055d74u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[1]>0)!=0);
goto P_0c055d76;
P_0c055d76: /* original 8f0b, guest PC 0x0c055d76 */
if(!s->budget--) { s->failed_pc=0x0c055d76u; return 0; }
cond=r[17]&1u;
r[4]=r[14];
if(!cond) { goto P_0c055d90; }
goto P_0c055d7a;
P_0c055d78: /* original 64e3, guest PC 0x0c055d78 */
if(!s->budget--) { s->failed_pc=0x0c055d78u; return 0; }
r[4]=r[14];
goto P_0c055d7a;
P_0c055d7a: /* original 7440, guest PC 0x0c055d7a */
if(!s->budget--) { s->failed_pc=0x0c055d7au; return 0; }
r[4]+=0x00000040u;
goto P_0c055d7c;
P_0c055d7c: /* original 65e3, guest PC 0x0c055d7c */
if(!s->budget--) { s->failed_pc=0x0c055d7cu; return 0; }
r[5]=r[14];
goto P_0c055d7e;
P_0c055d7e: /* original d311, guest PC 0x0c055d7e */
if(!s->budget--) { s->failed_pc=0x0c055d7eu; return 0; }
r[3]=read(ram,0x0c055dc4u,4);
goto P_0c055d80;
P_0c055d80: /* original 430b, guest PC 0x0c055d80 */
if(!s->budget--) { s->failed_pc=0x0c055d80u; return 0; }
target=r[3];
r[16]=code_base|0x0c055d84u;
r[5]+=0x00000068u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c055d84u) { target=s->pc; goto dispatch; }
goto P_0c055d84;
P_0c055d82: /* original 7568, guest PC 0x0c055d82 */
if(!s->budget--) { s->failed_pc=0x0c055d82u; return 0; }
r[5]+=0x00000068u;
goto P_0c055d84;
P_0c055d84: /* original 64e3, guest PC 0x0c055d84 */
if(!s->budget--) { s->failed_pc=0x0c055d84u; return 0; }
r[4]=r[14];
goto P_0c055d86;
P_0c055d86: /* original 7434, guest PC 0x0c055d86 */
if(!s->budget--) { s->failed_pc=0x0c055d86u; return 0; }
r[4]+=0x00000034u;
goto P_0c055d88;
P_0c055d88: /* original 65e3, guest PC 0x0c055d88 */
if(!s->budget--) { s->failed_pc=0x0c055d88u; return 0; }
r[5]=r[14];
goto P_0c055d8a;
P_0c055d8a: /* original d30f, guest PC 0x0c055d8a */
if(!s->budget--) { s->failed_pc=0x0c055d8au; return 0; }
r[3]=read(ram,0x0c055dc8u,4);
goto P_0c055d8c;
P_0c055d8c: /* original 430b, guest PC 0x0c055d8c */
if(!s->budget--) { s->failed_pc=0x0c055d8cu; return 0; }
target=r[3];
r[16]=code_base|0x0c055d90u;
r[5]+=0x0000005cu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c055d90u) { target=s->pc; goto dispatch; }
goto P_0c055d90;
P_0c055d8e: /* original 755c, guest PC 0x0c055d8e */
if(!s->budget--) { s->failed_pc=0x0c055d8eu; return 0; }
r[5]+=0x0000005cu;
goto P_0c055d90;
P_0c055d90: /* original e3b0, guest PC 0x0c055d90 */
if(!s->budget--) { s->failed_pc=0x0c055d90u; return 0; }
r[3]=0xffffffb0u;
goto P_0c055d92;
P_0c055d92: /* original 623c, guest PC 0x0c055d92 */
if(!s->budget--) { s->failed_pc=0x0c055d92u; return 0; }
r[2]=r[3]&255u;
goto P_0c055d94;
P_0c055d94: /* original 4d10, guest PC 0x0c055d94 */
if(!s->budget--) { s->failed_pc=0x0c055d94u; return 0; }
--r[13];
r[17]=(r[17]&~1u)|((r[13]==0)!=0);
goto P_0c055d96;
P_0c055d96: /* original 8fec, guest PC 0x0c055d96 */
if(!s->budget--) { s->failed_pc=0x0c055d96u; return 0; }
cond=r[17]&1u;
r[14]+=r[2];
if(!cond) { goto P_0c055d72; }
goto P_0c055d9a;
P_0c055d98: /* original 3e2c, guest PC 0x0c055d98 */
if(!s->budget--) { s->failed_pc=0x0c055d98u; return 0; }
r[14]+=r[2];
goto P_0c055d9a;
P_0c055d9a: /* original 6df6, guest PC 0x0c055d9a */
if(!s->budget--) { s->failed_pc=0x0c055d9au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c055d9c;
P_0c055d9c: /* original 6ef6, guest PC 0x0c055d9c */
if(!s->budget--) { s->failed_pc=0x0c055d9cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c055d9e;
P_0c055d9e: /* original d00c, guest PC 0x0c055d9e */
if(!s->budget--) { s->failed_pc=0x0c055d9eu; return 0; }
r[0]=read(ram,0x0c055dd0u,4);
goto P_0c055da0;
P_0c055da0: /* original e380, guest PC 0x0c055da0 */
if(!s->budget--) { s->failed_pc=0x0c055da0u; return 0; }
r[3]=0xffffff80u;
goto P_0c055da2;
P_0c055da2: /* original d10e, guest PC 0x0c055da2 */
if(!s->budget--) { s->failed_pc=0x0c055da2u; return 0; }
r[1]=read(ram,0x0c055ddcu,4);
goto P_0c055da4;
P_0c055da4: /* original 633c, guest PC 0x0c055da4 */
if(!s->budget--) { s->failed_pc=0x0c055da4u; return 0; }
r[3]=r[3]&255u;
goto P_0c055da6;
P_0c055da6: /* original d20e, guest PC 0x0c055da6 */
if(!s->budget--) { s->failed_pc=0x0c055da6u; return 0; }
r[2]=read(ram,0x0c055de0u,4);
goto P_0c055da8;
P_0c055da8: /* original c204, guest PC 0x0c055da8 */
if(!s->budget--) { s->failed_pc=0x0c055da8u; return 0; }
if(!s->gbr_known) goto unsupported;
write(ram,s->gbr+16,r[0],4);
goto P_0c055daa;
P_0c055daa: /* original 6013, guest PC 0x0c055daa */
if(!s->budget--) { s->failed_pc=0x0c055daau; return 0; }
r[0]=r[1];
goto P_0c055dac;
P_0c055dac: /* original c205, guest PC 0x0c055dac */
if(!s->budget--) { s->failed_pc=0x0c055dacu; return 0; }
if(!s->gbr_known) goto unsupported;
write(ram,s->gbr+20,r[0],4);
goto P_0c055dae;
P_0c055dae: /* original 6023, guest PC 0x0c055dae */
if(!s->budget--) { s->failed_pc=0x0c055daeu; return 0; }
r[0]=r[2];
goto P_0c055db0;
P_0c055db0: /* original 303c, guest PC 0x0c055db0 */
if(!s->budget--) { s->failed_pc=0x0c055db0u; return 0; }
r[0]+=r[3];
goto P_0c055db2;
P_0c055db2: /* original c203, guest PC 0x0c055db2 */
if(!s->budget--) { s->failed_pc=0x0c055db2u; return 0; }
if(!s->gbr_known) goto unsupported;
write(ram,s->gbr+12,r[0],4);
goto P_0c055db4;
P_0c055db4: /* original 4f26, guest PC 0x0c055db4 */
if(!s->budget--) { s->failed_pc=0x0c055db4u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c055db6;
P_0c055db6: /* original 000b, guest PC 0x0c055db6 */
if(!s->budget--) { s->failed_pc=0x0c055db6u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c055db8: /* original 0009, guest PC 0x0c055db8 */
if(!s->budget--) { s->failed_pc=0x0c055db8u; return 0; }
if(!vf3_matrix_family(0x0c055dbau,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c055dbau; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
