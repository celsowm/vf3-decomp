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
int vf3_away_batch118_adapter_5(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c05e1b2u: goto P_0c05e1b2;
case 0x0c05e1b4u: goto P_0c05e1b4;
case 0x0c05e1b6u: goto P_0c05e1b6;
case 0x0c05e1b8u: goto P_0c05e1b8;
case 0x0c05e1bau: goto P_0c05e1ba;
case 0x0c05e1bcu: goto P_0c05e1bc;
case 0x0c05e1beu: goto P_0c05e1be;
case 0x0c05e1c0u: goto P_0c05e1c0;
case 0x0c05e3d6u: goto P_0c05e3d6;
case 0x0c05e3d8u: goto P_0c05e3d8;
case 0x0c05e3dau: goto P_0c05e3da;
case 0x0c05e3dcu: goto P_0c05e3dc;
case 0x0c05e3deu: goto P_0c05e3de;
case 0x0c05e3e0u: goto P_0c05e3e0;
case 0x0c05e3e2u: goto P_0c05e3e2;
case 0x0c05e3e4u: goto P_0c05e3e4;
case 0x0c05e3e6u: goto P_0c05e3e6;
case 0x0c05e3e8u: goto P_0c05e3e8;
case 0x0c05e3eau: goto P_0c05e3ea;
case 0x0c05e3ecu: goto P_0c05e3ec;
case 0x0c05e3eeu: goto P_0c05e3ee;
case 0x0c05e3f0u: goto P_0c05e3f0;
case 0x0c05e3f2u: goto P_0c05e3f2;
case 0x0c05e3f4u: goto P_0c05e3f4;
case 0x0c05e3f6u: goto P_0c05e3f6;
case 0x0c05e3f8u: goto P_0c05e3f8;
case 0x0c05ee34u: goto P_0c05ee34;
case 0x0c05ee36u: goto P_0c05ee36;
case 0x0c05ee38u: goto P_0c05ee38;
case 0x0c05ee3au: goto P_0c05ee3a;
case 0x0c05ee3cu: goto P_0c05ee3c;
case 0x0c05ee3eu: goto P_0c05ee3e;
case 0x0c05ee40u: goto P_0c05ee40;
case 0x0c05ee42u: goto P_0c05ee42;
case 0x0c05ee44u: goto P_0c05ee44;
case 0x0c05ee46u: goto P_0c05ee46;
case 0x0c05fcc4u: goto P_0c05fcc4;
case 0x0c05fcc6u: goto P_0c05fcc6;
case 0x0c05fcc8u: goto P_0c05fcc8;
case 0x0c05fccau: goto P_0c05fcca;
case 0x0c05fcccu: goto P_0c05fccc;
case 0x0c05fcceu: goto P_0c05fcce;
case 0x0c060d14u: goto P_0c060d14;
case 0x0c060d16u: goto P_0c060d16;
case 0x0c060d18u: goto P_0c060d18;
case 0x0c060d1au: goto P_0c060d1a;
case 0x0c060d1cu: goto P_0c060d1c;
case 0x0c060d1eu: goto P_0c060d1e;
case 0x0c060d20u: goto P_0c060d20;
case 0x0c060d22u: goto P_0c060d22;
case 0x0c060d24u: goto P_0c060d24;
case 0x0c060d26u: goto P_0c060d26;
case 0x0c060d28u: goto P_0c060d28;
case 0x0c060d2au: goto P_0c060d2a;
case 0x0c060d2cu: goto P_0c060d2c;
case 0x0c060d2eu: goto P_0c060d2e;
case 0x0c060d30u: goto P_0c060d30;
case 0x0c060d32u: goto P_0c060d32;
case 0x0c060d34u: goto P_0c060d34;
case 0x0c060d36u: goto P_0c060d36;
case 0x0c060d38u: goto P_0c060d38;
case 0x0c060d3au: goto P_0c060d3a;
case 0x0c060d3cu: goto P_0c060d3c;
case 0x0c060d3eu: goto P_0c060d3e;
case 0x0c060d40u: goto P_0c060d40;
case 0x0c060d42u: goto P_0c060d42;
case 0x0c060d44u: goto P_0c060d44;
case 0x0c060d78u: goto P_0c060d78;
case 0x0c060d7au: goto P_0c060d7a;
case 0x0c060d7cu: goto P_0c060d7c;
case 0x0c060d7eu: goto P_0c060d7e;
case 0x0c060d80u: goto P_0c060d80;
case 0x0c060d82u: goto P_0c060d82;
case 0x0c060d84u: goto P_0c060d84;
case 0x0c060d86u: goto P_0c060d86;
case 0x0c060d88u: goto P_0c060d88;
case 0x0c060d8au: goto P_0c060d8a;
case 0x0c060d8cu: goto P_0c060d8c;
case 0x0c060d8eu: goto P_0c060d8e;
case 0x0c060d90u: goto P_0c060d90;
case 0x0c060d92u: goto P_0c060d92;
case 0x0c060d94u: goto P_0c060d94;
case 0x0c060d96u: goto P_0c060d96;
case 0x0c060d98u: goto P_0c060d98;
case 0x0c060d9au: goto P_0c060d9a;
case 0x0c060d9cu: goto P_0c060d9c;
case 0x0c060d9eu: goto P_0c060d9e;
case 0x0c060da0u: goto P_0c060da0;
case 0x0c060da2u: goto P_0c060da2;
case 0x0c060da4u: goto P_0c060da4;
case 0x0c060da6u: goto P_0c060da6;
case 0x0c060da8u: goto P_0c060da8;
case 0x0c060daau: goto P_0c060daa;
case 0x0c060dacu: goto P_0c060dac;
case 0x0c060daeu: goto P_0c060dae;
case 0x0c060db0u: goto P_0c060db0;
case 0x0c060db2u: goto P_0c060db2;
case 0x0c060db4u: goto P_0c060db4;
case 0x0c060db6u: goto P_0c060db6;
case 0x0c060db8u: goto P_0c060db8;
case 0x0c060dbau: goto P_0c060dba;
case 0x0c060dbcu: goto P_0c060dbc;
case 0x0c060dbeu: goto P_0c060dbe;
case 0x0c060dc0u: goto P_0c060dc0;
case 0x0c060dc2u: goto P_0c060dc2;
case 0x0c060dc4u: goto P_0c060dc4;
case 0x0c060dc6u: goto P_0c060dc6;
case 0x0c060dc8u: goto P_0c060dc8;
case 0x0c060dcau: goto P_0c060dca;
case 0x0c060dccu: goto P_0c060dcc;
case 0x0c060dceu: goto P_0c060dce;
case 0x0c060dd0u: goto P_0c060dd0;
case 0x0c060dd2u: goto P_0c060dd2;
case 0x0c060dd4u: goto P_0c060dd4;
case 0x0c060dd6u: goto P_0c060dd6;
case 0x0c060dd8u: goto P_0c060dd8;
case 0x0c060ddau: goto P_0c060dda;
case 0x0c060ddcu: goto P_0c060ddc;
case 0x0c060ddeu: goto P_0c060dde;
case 0x0c060de0u: goto P_0c060de0;
case 0x0c060de2u: goto P_0c060de2;
case 0x0c060de4u: goto P_0c060de4;
case 0x0c060de6u: goto P_0c060de6;
case 0x0c060de8u: goto P_0c060de8;
case 0x0c060deau: goto P_0c060dea;
case 0x0c060decu: goto P_0c060dec;
case 0x0c060deeu: goto P_0c060dee;
case 0x0c060df0u: goto P_0c060df0;
case 0x0c060df2u: goto P_0c060df2;
case 0x0c060df4u: goto P_0c060df4;
case 0x0c060df6u: goto P_0c060df6;
case 0x0c060df8u: goto P_0c060df8;
case 0x0c060dfau: goto P_0c060dfa;
case 0x0c060dfcu: goto P_0c060dfc;
case 0x0c060dfeu: goto P_0c060dfe;
case 0x0c060e00u: goto P_0c060e00;
case 0x0c060e02u: goto P_0c060e02;
case 0x0c060e04u: goto P_0c060e04;
case 0x0c060e06u: goto P_0c060e06;
case 0x0c060e08u: goto P_0c060e08;
case 0x0c060e0au: goto P_0c060e0a;
case 0x0c060e0cu: goto P_0c060e0c;
case 0x0c060e0eu: goto P_0c060e0e;
case 0x0c060e10u: goto P_0c060e10;
case 0x0c060e12u: goto P_0c060e12;
case 0x0c060e14u: goto P_0c060e14;
case 0x0c060e16u: goto P_0c060e16;
case 0x0c060e18u: goto P_0c060e18;
case 0x0c060e1au: goto P_0c060e1a;
case 0x0c060e1cu: goto P_0c060e1c;
case 0x0c060e1eu: goto P_0c060e1e;
case 0x0c060e20u: goto P_0c060e20;
case 0x0c060e22u: goto P_0c060e22;
case 0x0c060e24u: goto P_0c060e24;
case 0x0c061998u: goto P_0c061998;
case 0x0c06199au: goto P_0c06199a;
case 0x0c06199cu: goto P_0c06199c;
case 0x0c06199eu: goto P_0c06199e;
case 0x0c0619a0u: goto P_0c0619a0;
case 0x0c0619a2u: goto P_0c0619a2;
case 0x0c0619a4u: goto P_0c0619a4;
case 0x0c0619a6u: goto P_0c0619a6;
case 0x0c0619a8u: goto P_0c0619a8;
case 0x0c0619aau: goto P_0c0619aa;
case 0x0c0619acu: goto P_0c0619ac;
case 0x0c0619aeu: goto P_0c0619ae;
case 0x0c0619b0u: goto P_0c0619b0;
case 0x0c0619b2u: goto P_0c0619b2;
case 0x0c0619b4u: goto P_0c0619b4;
case 0x0c0619b6u: goto P_0c0619b6;
case 0x0c0619b8u: goto P_0c0619b8;
case 0x0c0619bau: goto P_0c0619ba;
case 0x0c0619bcu: goto P_0c0619bc;
case 0x0c0619beu: goto P_0c0619be;
case 0x0c0619c0u: goto P_0c0619c0;
case 0x0c0619c2u: goto P_0c0619c2;
case 0x0c0619c4u: goto P_0c0619c4;
case 0x0c0619c6u: goto P_0c0619c6;
case 0x0c0619c8u: goto P_0c0619c8;
case 0x0c0619cau: goto P_0c0619ca;
case 0x0c0619ccu: goto P_0c0619cc;
case 0x0c0619ceu: goto P_0c0619ce;
case 0x0c0619d0u: goto P_0c0619d0;
case 0x0c0619d2u: goto P_0c0619d2;
case 0x0c0619d4u: goto P_0c0619d4;
case 0x0c0619d6u: goto P_0c0619d6;
case 0x0c0619d8u: goto P_0c0619d8;
case 0x0c0619dau: goto P_0c0619da;
case 0x0c0619dcu: goto P_0c0619dc;
case 0x0c0619deu: goto P_0c0619de;
case 0x0c0619e0u: goto P_0c0619e0;
case 0x0c0619e2u: goto P_0c0619e2;
case 0x0c0619e4u: goto P_0c0619e4;
case 0x0c0619e6u: goto P_0c0619e6;
case 0x0c0619e8u: goto P_0c0619e8;
case 0x0c0619eau: goto P_0c0619ea;
case 0x0c0619ecu: goto P_0c0619ec;
case 0x0c0619eeu: goto P_0c0619ee;
case 0x0c0619f0u: goto P_0c0619f0;
case 0x0c0619f2u: goto P_0c0619f2;
case 0x0c0619f4u: goto P_0c0619f4;
case 0x0c0619f6u: goto P_0c0619f6;
case 0x0c0619f8u: goto P_0c0619f8;
case 0x0c0619fau: goto P_0c0619fa;
case 0x0c0619fcu: goto P_0c0619fc;
case 0x0c0619feu: goto P_0c0619fe;
case 0x0c061a00u: goto P_0c061a00;
case 0x0c061a02u: goto P_0c061a02;
case 0x0c061a04u: goto P_0c061a04;
case 0x0c061a06u: goto P_0c061a06;
case 0x0c061a08u: goto P_0c061a08;
default: return vf3_matrix_family(target,s,ram);
}
P_0c05e1b2: /* original 4f22, guest PC 0x0c05e1b2 */
if(!s->budget--) { s->failed_pc=0x0c05e1b2u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c05e1b4;
P_0c05e1b4: /* original 9461, guest PC 0x0c05e1b4 */
if(!s->budget--) { s->failed_pc=0x0c05e1b4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c05e27au,2);
goto P_0c05e1b6;
P_0c05e1b6: /* original d339, guest PC 0x0c05e1b6 */
if(!s->budget--) { s->failed_pc=0x0c05e1b6u; return 0; }
r[3]=read(ram,0x0c05e29cu,4);
goto P_0c05e1b8;
P_0c05e1b8: /* original 430b, guest PC 0x0c05e1b8 */
if(!s->budget--) { s->failed_pc=0x0c05e1b8u; return 0; }
target=r[3];
r[16]=code_base|0x0c05e1bcu;
r[5]=read(ram,r[15]+4,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c05e1bcu) { target=s->pc; goto dispatch; }
goto P_0c05e1bc;
P_0c05e1ba: /* original 55f1, guest PC 0x0c05e1ba */
if(!s->budget--) { s->failed_pc=0x0c05e1bau; return 0; }
r[5]=read(ram,r[15]+4,4);
goto P_0c05e1bc;
P_0c05e1bc: /* original 4f26, guest PC 0x0c05e1bc */
if(!s->budget--) { s->failed_pc=0x0c05e1bcu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c05e1be;
P_0c05e1be: /* original 000b, guest PC 0x0c05e1be */
if(!s->budget--) { s->failed_pc=0x0c05e1beu; return 0; }
target=r[16];
r[0]=0x00000000u;
s->pc=target; return ram->oob==0;
P_0c05e1c0: /* original e000, guest PC 0x0c05e1c0 */
if(!s->budget--) { s->failed_pc=0x0c05e1c0u; return 0; }
r[0]=0x00000000u;
if(!vf3_matrix_family(0x0c05e1c2u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c05e1c2u; return 0; } return 1;
P_0c05e3d6: /* original 6353, guest PC 0x0c05e3d6 */
if(!s->budget--) { s->failed_pc=0x0c05e3d6u; return 0; }
r[3]=r[5];
goto P_0c05e3d8;
P_0c05e3d8: /* original d011, guest PC 0x0c05e3d8 */
if(!s->budget--) { s->failed_pc=0x0c05e3d8u; return 0; }
r[0]=read(ram,0x0c05e420u,4);
goto P_0c05e3da;
P_0c05e3da: /* original 4308, guest PC 0x0c05e3da */
if(!s->budget--) { s->failed_pc=0x0c05e3dau; return 0; }
r[3]<<=2;
goto P_0c05e3dc;
P_0c05e3dc: /* original 4f22, guest PC 0x0c05e3dc */
if(!s->budget--) { s->failed_pc=0x0c05e3dcu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c05e3de;
P_0c05e3de: /* original 7ffc, guest PC 0x0c05e3de */
if(!s->budget--) { s->failed_pc=0x0c05e3deu; return 0; }
r[15]+=0xfffffffcu;
goto P_0c05e3e0;
P_0c05e3e0: /* original 2f52, guest PC 0x0c05e3e0 */
if(!s->budget--) { s->failed_pc=0x0c05e3e0u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c05e3e2;
P_0c05e3e2: /* original 033e, guest PC 0x0c05e3e2 */
if(!s->budget--) { s->failed_pc=0x0c05e3e2u; return 0; }
r[3]=read(ram,r[3]+r[0],4);
goto P_0c05e3e4;
P_0c05e3e4: /* original 430b, guest PC 0x0c05e3e4 */
if(!s->budget--) { s->failed_pc=0x0c05e3e4u; return 0; }
target=r[3];
r[16]=code_base|0x0c05e3e8u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c05e3e8u) { target=s->pc; goto dispatch; }
goto P_0c05e3e8;
P_0c05e3e6: /* original 0009, guest PC 0x0c05e3e6 */
if(!s->budget--) { s->failed_pc=0x0c05e3e6u; return 0; }
goto P_0c05e3e8;
P_0c05e3e8: /* original d30e, guest PC 0x0c05e3e8 */
if(!s->budget--) { s->failed_pc=0x0c05e3e8u; return 0; }
r[3]=read(ram,0x0c05e424u,4);
goto P_0c05e3ea;
P_0c05e3ea: /* original d20f, guest PC 0x0c05e3ea */
if(!s->budget--) { s->failed_pc=0x0c05e3eau; return 0; }
r[2]=read(ram,0x0c05e428u,4);
goto P_0c05e3ec;
P_0c05e3ec: /* original 6132, guest PC 0x0c05e3ec */
if(!s->budget--) { s->failed_pc=0x0c05e3ecu; return 0; }
tmp=read(ram,r[3],4);
r[1]=tmp;
goto P_0c05e3ee;
P_0c05e3ee: /* original 2129, guest PC 0x0c05e3ee */
if(!s->budget--) { s->failed_pc=0x0c05e3eeu; return 0; }
r[1]&=r[2];
goto P_0c05e3f0;
P_0c05e3f0: /* original 2312, guest PC 0x0c05e3f0 */
if(!s->budget--) { s->failed_pc=0x0c05e3f0u; return 0; }
write(ram,r[3],r[1],4);
goto P_0c05e3f2;
P_0c05e3f2: /* original 7f04, guest PC 0x0c05e3f2 */
if(!s->budget--) { s->failed_pc=0x0c05e3f2u; return 0; }
r[15]+=0x00000004u;
goto P_0c05e3f4;
P_0c05e3f4: /* original 4f26, guest PC 0x0c05e3f4 */
if(!s->budget--) { s->failed_pc=0x0c05e3f4u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c05e3f6;
P_0c05e3f6: /* original 000b, guest PC 0x0c05e3f6 */
if(!s->budget--) { s->failed_pc=0x0c05e3f6u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c05e3f8: /* original 0009, guest PC 0x0c05e3f8 */
if(!s->budget--) { s->failed_pc=0x0c05e3f8u; return 0; }
if(!vf3_matrix_family(0x0c05e3fau,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c05e3fau; return 0; } return 1;
P_0c05ee34: /* original 4f22, guest PC 0x0c05ee34 */
if(!s->budget--) { s->failed_pc=0x0c05ee34u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c05ee36;
P_0c05ee36: /* original d309, guest PC 0x0c05ee36 */
if(!s->budget--) { s->failed_pc=0x0c05ee36u; return 0; }
r[3]=read(ram,0x0c05ee5cu,4);
goto P_0c05ee38;
P_0c05ee38: /* original 430b, guest PC 0x0c05ee38 */
if(!s->budget--) { s->failed_pc=0x0c05ee38u; return 0; }
target=r[3];
r[16]=code_base|0x0c05ee3cu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c05ee3cu) { target=s->pc; goto dispatch; }
goto P_0c05ee3c;
P_0c05ee3a: /* original 0009, guest PC 0x0c05ee3a */
if(!s->budget--) { s->failed_pc=0x0c05ee3au; return 0; }
goto P_0c05ee3c;
P_0c05ee3c: /* original d208, guest PC 0x0c05ee3c */
if(!s->budget--) { s->failed_pc=0x0c05ee3cu; return 0; }
r[2]=read(ram,0x0c05ee60u,4);
goto P_0c05ee3e;
P_0c05ee3e: /* original 420b, guest PC 0x0c05ee3e */
if(!s->budget--) { s->failed_pc=0x0c05ee3eu; return 0; }
target=r[2];
r[16]=code_base|0x0c05ee42u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c05ee42u) { target=s->pc; goto dispatch; }
goto P_0c05ee42;
P_0c05ee40: /* original 0009, guest PC 0x0c05ee40 */
if(!s->budget--) { s->failed_pc=0x0c05ee40u; return 0; }
goto P_0c05ee42;
P_0c05ee42: /* original 4f26, guest PC 0x0c05ee42 */
if(!s->budget--) { s->failed_pc=0x0c05ee42u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c05ee44;
P_0c05ee44: /* original 000b, guest PC 0x0c05ee44 */
if(!s->budget--) { s->failed_pc=0x0c05ee44u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c05ee46: /* original 0009, guest PC 0x0c05ee46 */
if(!s->budget--) { s->failed_pc=0x0c05ee46u; return 0; }
if(!vf3_matrix_family(0x0c05ee48u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c05ee48u; return 0; } return 1;
P_0c05fcc4: /* original d330, guest PC 0x0c05fcc4 */
if(!s->budget--) { s->failed_pc=0x0c05fcc4u; return 0; }
r[3]=read(ram,0x0c05fd88u,4);
goto P_0c05fcc6;
P_0c05fcc6: /* original 7ffc, guest PC 0x0c05fcc6 */
if(!s->budget--) { s->failed_pc=0x0c05fcc6u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c05fcc8;
P_0c05fcc8: /* original 2f42, guest PC 0x0c05fcc8 */
if(!s->budget--) { s->failed_pc=0x0c05fcc8u; return 0; }
write(ram,r[15],r[4],4);
goto P_0c05fcca;
P_0c05fcca: /* original 6232, guest PC 0x0c05fcca */
if(!s->budget--) { s->failed_pc=0x0c05fccau; return 0; }
tmp=read(ram,r[3],4);
r[2]=tmp;
goto P_0c05fccc;
P_0c05fccc: /* original 422b, guest PC 0x0c05fccc */
if(!s->budget--) { s->failed_pc=0x0c05fcccu; return 0; }
target=r[2];
r[15]+=0x00000004u;
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
P_0c05fcce: /* original 7f04, guest PC 0x0c05fcce */
if(!s->budget--) { s->failed_pc=0x0c05fcceu; return 0; }
r[15]+=0x00000004u;
if(!vf3_matrix_family(0x0c05fcd0u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c05fcd0u; return 0; } return 1;
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
goto P_0c060d1e;
P_0c060d1e: /* original 2fe6, guest PC 0x0c060d1e */
if(!s->budget--) { s->failed_pc=0x0c060d1eu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c060d20;
P_0c060d20: /* original 2fd6, guest PC 0x0c060d20 */
if(!s->budget--) { s->failed_pc=0x0c060d20u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c060d22;
P_0c060d22: /* original 6e43, guest PC 0x0c060d22 */
if(!s->budget--) { s->failed_pc=0x0c060d22u; return 0; }
r[14]=r[4];
goto P_0c060d24;
P_0c060d24: /* original 2fc6, guest PC 0x0c060d24 */
if(!s->budget--) { s->failed_pc=0x0c060d24u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c060d26;
P_0c060d26: /* original 6d43, guest PC 0x0c060d26 */
if(!s->budget--) { s->failed_pc=0x0c060d26u; return 0; }
r[13]=r[4];
goto P_0c060d28;
P_0c060d28: /* original 4f22, guest PC 0x0c060d28 */
if(!s->budget--) { s->failed_pc=0x0c060d28u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c060d2a;
P_0c060d2a: /* original 3d5c, guest PC 0x0c060d2a */
if(!s->budget--) { s->failed_pc=0x0c060d2au; return 0; }
r[13]+=r[5];
goto P_0c060d2c;
P_0c060d2c: /* original dc3f, guest PC 0x0c060d2c */
if(!s->budget--) { s->failed_pc=0x0c060d2cu; return 0; }
r[12]=read(ram,0x0c060e2cu,4);
goto P_0c060d2e;
P_0c060d2e: /* original 3ed6, guest PC 0x0c060d2e */
if(!s->budget--) { s->failed_pc=0x0c060d2eu; return 0; }
r[17]=(r[17]&~1u)|((r[14]>r[13])!=0);
goto P_0c060d30;
P_0c060d30: /* original 8904, guest PC 0x0c060d30 */
if(!s->budget--) { s->failed_pc=0x0c060d30u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c060d3c; }
goto P_0c060d32;
P_0c060d32: /* original 4c0b, guest PC 0x0c060d32 */
if(!s->budget--) { s->failed_pc=0x0c060d32u; return 0; }
target=r[12];
r[16]=code_base|0x0c060d36u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c060d36u) { target=s->pc; goto dispatch; }
goto P_0c060d36;
P_0c060d34: /* original 64e3, guest PC 0x0c060d34 */
if(!s->budget--) { s->failed_pc=0x0c060d34u; return 0; }
r[4]=r[14];
goto P_0c060d36;
P_0c060d36: /* original 7e20, guest PC 0x0c060d36 */
if(!s->budget--) { s->failed_pc=0x0c060d36u; return 0; }
r[14]+=0x00000020u;
goto P_0c060d38;
P_0c060d38: /* original 3ed6, guest PC 0x0c060d38 */
if(!s->budget--) { s->failed_pc=0x0c060d38u; return 0; }
r[17]=(r[17]&~1u)|((r[14]>r[13])!=0);
goto P_0c060d3a;
P_0c060d3a: /* original 8bfa, guest PC 0x0c060d3a */
if(!s->budget--) { s->failed_pc=0x0c060d3au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c060d32; }
goto P_0c060d3c;
P_0c060d3c: /* original 4f26, guest PC 0x0c060d3c */
if(!s->budget--) { s->failed_pc=0x0c060d3cu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c060d3e;
P_0c060d3e: /* original 6cf6, guest PC 0x0c060d3e */
if(!s->budget--) { s->failed_pc=0x0c060d3eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c060d40;
P_0c060d40: /* original 6df6, guest PC 0x0c060d40 */
if(!s->budget--) { s->failed_pc=0x0c060d40u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c060d42;
P_0c060d42: /* original 000b, guest PC 0x0c060d42 */
if(!s->budget--) { s->failed_pc=0x0c060d42u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c060d44: /* original 6ef6, guest PC 0x0c060d44 */
if(!s->budget--) { s->failed_pc=0x0c060d44u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c060d46u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c060d46u; return 0; } return 1;
P_0c060d78: /* original 2fe6, guest PC 0x0c060d78 */
if(!s->budget--) { s->failed_pc=0x0c060d78u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c060d7a;
P_0c060d7a: /* original 0002, guest PC 0x0c060d7a */
if(!s->budget--) { s->failed_pc=0x0c060d7au; return 0; }
r[0]=r[17];
goto P_0c060d7c;
P_0c060d7c: /* original 2fd6, guest PC 0x0c060d7c */
if(!s->budget--) { s->failed_pc=0x0c060d7cu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c060d7e;
P_0c060d7e: /* original 6e53, guest PC 0x0c060d7e */
if(!s->budget--) { s->failed_pc=0x0c060d7eu; return 0; }
r[14]=r[5];
goto P_0c060d80;
P_0c060d80: /* original 2fc6, guest PC 0x0c060d80 */
if(!s->budget--) { s->failed_pc=0x0c060d80u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c060d82;
P_0c060d82: /* original 6d43, guest PC 0x0c060d82 */
if(!s->budget--) { s->failed_pc=0x0c060d82u; return 0; }
r[13]=r[4];
goto P_0c060d84;
P_0c060d84: /* original 2fb6, guest PC 0x0c060d84 */
if(!s->budget--) { s->failed_pc=0x0c060d84u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c060d86;
P_0c060d86: /* original 4009, guest PC 0x0c060d86 */
if(!s->budget--) { s->failed_pc=0x0c060d86u; return 0; }
r[0]>>=2;
goto P_0c060d88;
P_0c060d88: /* original 2fa6, guest PC 0x0c060d88 */
if(!s->budget--) { s->failed_pc=0x0c060d88u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c060d8a;
P_0c060d8a: /* original 63d3, guest PC 0x0c060d8a */
if(!s->budget--) { s->failed_pc=0x0c060d8au; return 0; }
r[3]=r[13];
goto P_0c060d8c;
P_0c060d8c: /* original 2f96, guest PC 0x0c060d8c */
if(!s->budget--) { s->failed_pc=0x0c060d8cu; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c060d8e;
P_0c060d8e: /* original 6a63, guest PC 0x0c060d8e */
if(!s->budget--) { s->failed_pc=0x0c060d8eu; return 0; }
r[10]=r[6];
goto P_0c060d90;
P_0c060d90: /* original 2f86, guest PC 0x0c060d90 */
if(!s->budget--) { s->failed_pc=0x0c060d90u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c060d92;
P_0c060d92: /* original 4009, guest PC 0x0c060d92 */
if(!s->budget--) { s->failed_pc=0x0c060d92u; return 0; }
r[0]>>=2;
goto P_0c060d94;
P_0c060d94: /* original 4f22, guest PC 0x0c060d94 */
if(!s->budget--) { s->failed_pc=0x0c060d94u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c060d96;
P_0c060d96: /* original e91f, guest PC 0x0c060d96 */
if(!s->budget--) { s->failed_pc=0x0c060d96u; return 0; }
r[9]=0x0000001fu;
goto P_0c060d98;
P_0c060d98: /* original 7ffc, guest PC 0x0c060d98 */
if(!s->budget--) { s->failed_pc=0x0c060d98u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c060d9a;
P_0c060d9a: /* original c90f, guest PC 0x0c060d9a */
if(!s->budget--) { s->failed_pc=0x0c060d9au; return 0; }
r[0]&=15u;
goto P_0c060d9c;
P_0c060d9c: /* original 2398, guest PC 0x0c060d9c */
if(!s->budget--) { s->failed_pc=0x0c060d9cu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[9])==0)!=0);
goto P_0c060d9e;
P_0c060d9e: /* original 8f31, guest PC 0x0c060d9e */
if(!s->budget--) { s->failed_pc=0x0c060d9eu; return 0; }
cond=r[17]&1u;
r[4]=r[0];
if(!cond) { goto P_0c060e04; }
goto P_0c060da2;
P_0c060da0: /* original 6403, guest PC 0x0c060da0 */
if(!s->budget--) { s->failed_pc=0x0c060da0u; return 0; }
r[4]=r[0];
goto P_0c060da2;
P_0c060da2: /* original 61e3, guest PC 0x0c060da2 */
if(!s->budget--) { s->failed_pc=0x0c060da2u; return 0; }
r[1]=r[14];
goto P_0c060da4;
P_0c060da4: /* original 2198, guest PC 0x0c060da4 */
if(!s->budget--) { s->failed_pc=0x0c060da4u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[9])==0)!=0);
goto P_0c060da6;
P_0c060da6: /* original 8b2d, guest PC 0x0c060da6 */
if(!s->budget--) { s->failed_pc=0x0c060da6u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c060e04; }
goto P_0c060da8;
P_0c060da8: /* original 2448, guest PC 0x0c060da8 */
if(!s->budget--) { s->failed_pc=0x0c060da8u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c060daa;
P_0c060daa: /* original 8b2b, guest PC 0x0c060daa */
if(!s->budget--) { s->failed_pc=0x0c060daau; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c060e04; }
goto P_0c060dac;
P_0c060dac: /* original 65a3, guest PC 0x0c060dac */
if(!s->budget--) { s->failed_pc=0x0c060dacu; return 0; }
r[5]=r[10];
goto P_0c060dae;
P_0c060dae: /* original bfb6, guest PC 0x0c060dae */
if(!s->budget--) { s->failed_pc=0x0c060daeu; return 0; }
target=code_base|0x0c060d1eu; r[16]=code_base|0x0c060db2u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c060db2u) { target=s->pc; goto dispatch; }
goto P_0c060db2;
P_0c060db0: /* original 64e3, guest PC 0x0c060db0 */
if(!s->budget--) { s->failed_pc=0x0c060db0u; return 0; }
r[4]=r[14];
goto P_0c060db2;
P_0c060db2: /* original ece0, guest PC 0x0c060db2 */
if(!s->budget--) { s->failed_pc=0x0c060db2u; return 0; }
r[12]=0xffffffe0u;
goto P_0c060db4;
P_0c060db4: /* original d820, guest PC 0x0c060db4 */
if(!s->budget--) { s->failed_pc=0x0c060db4u; return 0; }
r[8]=read(ram,0x0c060e38u,4);
goto P_0c060db6;
P_0c060db6: /* original 2ca9, guest PC 0x0c060db6 */
if(!s->budget--) { s->failed_pc=0x0c060db6u; return 0; }
r[12]&=r[10];
goto P_0c060db8;
P_0c060db8: /* original 9b35, guest PC 0x0c060db8 */
if(!s->budget--) { s->failed_pc=0x0c060db8u; return 0; }
r[11]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c060e26u,2);
goto P_0c060dba;
P_0c060dba: /* original 38dc, guest PC 0x0c060dba */
if(!s->budget--) { s->failed_pc=0x0c060dbau; return 0; }
r[8]+=r[13];
goto P_0c060dbc;
P_0c060dbc: /* original d21f, guest PC 0x0c060dbc */
if(!s->budget--) { s->failed_pc=0x0c060dbcu; return 0; }
r[2]=read(ram,0x0c060e3cu,4);
goto P_0c060dbe;
P_0c060dbe: /* original 63f3, guest PC 0x0c060dbe */
if(!s->budget--) { s->failed_pc=0x0c060dbeu; return 0; }
r[3]=r[15];
goto P_0c060dc0;
P_0c060dc0: /* original 2f36, guest PC 0x0c060dc0 */
if(!s->budget--) { s->failed_pc=0x0c060dc0u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c060dc2;
P_0c060dc2: /* original e718, guest PC 0x0c060dc2 */
if(!s->budget--) { s->failed_pc=0x0c060dc2u; return 0; }
r[7]=0x00000018u;
goto P_0c060dc4;
P_0c060dc4: /* original 66c3, guest PC 0x0c060dc4 */
if(!s->budget--) { s->failed_pc=0x0c060dc4u; return 0; }
r[6]=r[12];
goto P_0c060dc6;
P_0c060dc6: /* original 65e3, guest PC 0x0c060dc6 */
if(!s->budget--) { s->failed_pc=0x0c060dc6u; return 0; }
r[5]=r[14];
goto P_0c060dc8;
P_0c060dc8: /* original 420b, guest PC 0x0c060dc8 */
if(!s->budget--) { s->failed_pc=0x0c060dc8u; return 0; }
target=r[2];
r[16]=code_base|0x0c060dccu;
r[4]=r[8];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c060dccu) { target=s->pc; goto dispatch; }
goto P_0c060dcc;
P_0c060dca: /* original 6483, guest PC 0x0c060dca */
if(!s->budget--) { s->failed_pc=0x0c060dcau; return 0; }
r[4]=r[8];
goto P_0c060dcc;
P_0c060dcc: /* original 30b0, guest PC 0x0c060dcc */
if(!s->budget--) { s->failed_pc=0x0c060dccu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==r[11])!=0);
goto P_0c060dce;
P_0c060dce: /* original 8df5, guest PC 0x0c060dce */
if(!s->budget--) { s->failed_pc=0x0c060dceu; return 0; }
cond=r[17]&1u;
r[15]+=0x00000004u;
if(cond) { goto P_0c060dbc; }
goto P_0c060dd2;
P_0c060dd0: /* original 7f04, guest PC 0x0c060dd0 */
if(!s->budget--) { s->failed_pc=0x0c060dd0u; return 0; }
r[15]+=0x00000004u;
goto P_0c060dd2;
P_0c060dd2: /* original 62f2, guest PC 0x0c060dd2 */
if(!s->budget--) { s->failed_pc=0x0c060dd2u; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c060dd4;
P_0c060dd4: /* original d11a, guest PC 0x0c060dd4 */
if(!s->budget--) { s->failed_pc=0x0c060dd4u; return 0; }
r[1]=read(ram,0x0c060e40u,4);
goto P_0c060dd6;
P_0c060dd6: /* original 6322, guest PC 0x0c060dd6 */
if(!s->budget--) { s->failed_pc=0x0c060dd6u; return 0; }
tmp=read(ram,r[2],4);
r[3]=tmp;
goto P_0c060dd8;
P_0c060dd8: /* original 2132, guest PC 0x0c060dd8 */
if(!s->budget--) { s->failed_pc=0x0c060dd8u; return 0; }
write(ram,r[1],r[3],4);
goto P_0c060dda;
P_0c060dda: /* original 66a3, guest PC 0x0c060dda */
if(!s->budget--) { s->failed_pc=0x0c060ddau; return 0; }
r[6]=r[10];
goto P_0c060ddc;
P_0c060ddc: /* original 2699, guest PC 0x0c060ddc */
if(!s->budget--) { s->failed_pc=0x0c060ddcu; return 0; }
r[6]&=r[9];
goto P_0c060dde;
P_0c060dde: /* original 2668, guest PC 0x0c060dde */
if(!s->budget--) { s->failed_pc=0x0c060ddeu; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[6])==0)!=0);
goto P_0c060de0;
P_0c060de0: /* original 8906, guest PC 0x0c060de0 */
if(!s->budget--) { s->failed_pc=0x0c060de0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c060df0; }
goto P_0c060de2;
P_0c060de2: /* original 3dcc, guest PC 0x0c060de2 */
if(!s->budget--) { s->failed_pc=0x0c060de2u; return 0; }
r[13]+=r[12];
goto P_0c060de4;
P_0c060de4: /* original d417, guest PC 0x0c060de4 */
if(!s->budget--) { s->failed_pc=0x0c060de4u; return 0; }
r[4]=read(ram,0x0c060e44u,4);
goto P_0c060de6;
P_0c060de6: /* original 3ecc, guest PC 0x0c060de6 */
if(!s->budget--) { s->failed_pc=0x0c060de6u; return 0; }
r[14]+=r[12];
goto P_0c060de8;
P_0c060de8: /* original d212, guest PC 0x0c060de8 */
if(!s->budget--) { s->failed_pc=0x0c060de8u; return 0; }
r[2]=read(ram,0x0c060e34u,4);
goto P_0c060dea;
P_0c060dea: /* original 65e3, guest PC 0x0c060dea */
if(!s->budget--) { s->failed_pc=0x0c060deau; return 0; }
r[5]=r[14];
goto P_0c060dec;
P_0c060dec: /* original 420b, guest PC 0x0c060dec */
if(!s->budget--) { s->failed_pc=0x0c060decu; return 0; }
target=r[2];
r[16]=code_base|0x0c060df0u;
r[4]+=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c060df0u) { target=s->pc; goto dispatch; }
goto P_0c060df0;
P_0c060dee: /* original 34dc, guest PC 0x0c060dee */
if(!s->budget--) { s->failed_pc=0x0c060deeu; return 0; }
r[4]+=r[13];
goto P_0c060df0;
P_0c060df0: /* original d315, guest PC 0x0c060df0 */
if(!s->budget--) { s->failed_pc=0x0c060df0u; return 0; }
r[3]=read(ram,0x0c060e48u,4);
goto P_0c060df2;
P_0c060df2: /* original 6032, guest PC 0x0c060df2 */
if(!s->budget--) { s->failed_pc=0x0c060df2u; return 0; }
tmp=read(ram,r[3],4);
r[0]=tmp;
goto P_0c060df4;
P_0c060df4: /* original 8801, guest PC 0x0c060df4 */
if(!s->budget--) { s->failed_pc=0x0c060df4u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c060df6;
P_0c060df6: /* original 8b0b, guest PC 0x0c060df6 */
if(!s->budget--) { s->failed_pc=0x0c060df6u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c060e10; }
goto P_0c060df8;
P_0c060df8: /* original d111, guest PC 0x0c060df8 */
if(!s->budget--) { s->failed_pc=0x0c060df8u; return 0; }
r[1]=read(ram,0x0c060e40u,4);
goto P_0c060dfa;
P_0c060dfa: /* original d214, guest PC 0x0c060dfa */
if(!s->budget--) { s->failed_pc=0x0c060dfau; return 0; }
r[2]=read(ram,0x0c060e4cu,4);
goto P_0c060dfc;
P_0c060dfc: /* original 420b, guest PC 0x0c060dfc */
if(!s->budget--) { s->failed_pc=0x0c060dfcu; return 0; }
target=r[2];
r[16]=code_base|0x0c060e00u;
tmp=read(ram,r[1],4);
r[4]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c060e00u) { target=s->pc; goto dispatch; }
goto P_0c060e00;
P_0c060dfe: /* original 6412, guest PC 0x0c060dfe */
if(!s->budget--) { s->failed_pc=0x0c060dfeu; return 0; }
tmp=read(ram,r[1],4);
r[4]=tmp;
goto P_0c060e00;
P_0c060e00: /* original a006, guest PC 0x0c060e00 */
if(!s->budget--) { s->failed_pc=0x0c060e00u; return 0; }
goto P_0c060e10;
P_0c060e02: /* original 0009, guest PC 0x0c060e02 */
if(!s->budget--) { s->failed_pc=0x0c060e02u; return 0; }
goto P_0c060e04;
P_0c060e04: /* original d40f, guest PC 0x0c060e04 */
if(!s->budget--) { s->failed_pc=0x0c060e04u; return 0; }
r[4]=read(ram,0x0c060e44u,4);
goto P_0c060e06;
P_0c060e06: /* original 66a3, guest PC 0x0c060e06 */
if(!s->budget--) { s->failed_pc=0x0c060e06u; return 0; }
r[6]=r[10];
goto P_0c060e08;
P_0c060e08: /* original d20a, guest PC 0x0c060e08 */
if(!s->budget--) { s->failed_pc=0x0c060e08u; return 0; }
r[2]=read(ram,0x0c060e34u,4);
goto P_0c060e0a;
P_0c060e0a: /* original 65e3, guest PC 0x0c060e0a */
if(!s->budget--) { s->failed_pc=0x0c060e0au; return 0; }
r[5]=r[14];
goto P_0c060e0c;
P_0c060e0c: /* original 420b, guest PC 0x0c060e0c */
if(!s->budget--) { s->failed_pc=0x0c060e0cu; return 0; }
target=r[2];
r[16]=code_base|0x0c060e10u;
r[4]+=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c060e10u) { target=s->pc; goto dispatch; }
goto P_0c060e10;
P_0c060e0e: /* original 34dc, guest PC 0x0c060e0e */
if(!s->budget--) { s->failed_pc=0x0c060e0eu; return 0; }
r[4]+=r[13];
goto P_0c060e10;
P_0c060e10: /* original e001, guest PC 0x0c060e10 */
if(!s->budget--) { s->failed_pc=0x0c060e10u; return 0; }
r[0]=0x00000001u;
goto P_0c060e12;
P_0c060e12: /* original 7f04, guest PC 0x0c060e12 */
if(!s->budget--) { s->failed_pc=0x0c060e12u; return 0; }
r[15]+=0x00000004u;
goto P_0c060e14;
P_0c060e14: /* original 4f26, guest PC 0x0c060e14 */
if(!s->budget--) { s->failed_pc=0x0c060e14u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c060e16;
P_0c060e16: /* original 68f6, guest PC 0x0c060e16 */
if(!s->budget--) { s->failed_pc=0x0c060e16u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c060e18;
P_0c060e18: /* original 69f6, guest PC 0x0c060e18 */
if(!s->budget--) { s->failed_pc=0x0c060e18u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c060e1a;
P_0c060e1a: /* original 6af6, guest PC 0x0c060e1a */
if(!s->budget--) { s->failed_pc=0x0c060e1au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c060e1c;
P_0c060e1c: /* original 6bf6, guest PC 0x0c060e1c */
if(!s->budget--) { s->failed_pc=0x0c060e1cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c060e1e;
P_0c060e1e: /* original 6cf6, guest PC 0x0c060e1e */
if(!s->budget--) { s->failed_pc=0x0c060e1eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c060e20;
P_0c060e20: /* original 6df6, guest PC 0x0c060e20 */
if(!s->budget--) { s->failed_pc=0x0c060e20u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c060e22;
P_0c060e22: /* original 000b, guest PC 0x0c060e22 */
if(!s->budget--) { s->failed_pc=0x0c060e22u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c060e24: /* original 6ef6, guest PC 0x0c060e24 */
if(!s->budget--) { s->failed_pc=0x0c060e24u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c060e26u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c060e26u; return 0; } return 1;
P_0c061998: /* original 2fe6, guest PC 0x0c061998 */
if(!s->budget--) { s->failed_pc=0x0c061998u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06199a;
P_0c06199a: /* original 2fd6, guest PC 0x0c06199a */
if(!s->budget--) { s->failed_pc=0x0c06199au; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06199c;
P_0c06199c: /* original 4f22, guest PC 0x0c06199c */
if(!s->budget--) { s->failed_pc=0x0c06199cu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c06199e;
P_0c06199e: /* original de1b, guest PC 0x0c06199e */
if(!s->budget--) { s->failed_pc=0x0c06199eu; return 0; }
r[14]=read(ram,0x0c061a0cu,4);
goto P_0c0619a0;
P_0c0619a0: /* original 65e3, guest PC 0x0c0619a0 */
if(!s->budget--) { s->failed_pc=0x0c0619a0u; return 0; }
r[5]=r[14];
goto P_0c0619a2;
P_0c0619a2: /* original 7504, guest PC 0x0c0619a2 */
if(!s->budget--) { s->failed_pc=0x0c0619a2u; return 0; }
r[5]+=0x00000004u;
goto P_0c0619a4;
P_0c0619a4: /* original b62e, guest PC 0x0c0619a4 */
if(!s->budget--) { s->failed_pc=0x0c0619a4u; return 0; }
target=code_base|0x0c062604u; r[16]=code_base|0x0c0619a8u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0619a8u) { target=s->pc; goto dispatch; }
goto P_0c0619a8;
P_0c0619a6: /* original 64e3, guest PC 0x0c0619a6 */
if(!s->budget--) { s->failed_pc=0x0c0619a6u; return 0; }
r[4]=r[14];
goto P_0c0619a8;
P_0c0619a8: /* original dd19, guest PC 0x0c0619a8 */
if(!s->budget--) { s->failed_pc=0x0c0619a8u; return 0; }
r[13]=read(ram,0x0c061a10u,4);
goto P_0c0619aa;
P_0c0619aa: /* original 65d3, guest PC 0x0c0619aa */
if(!s->budget--) { s->failed_pc=0x0c0619aau; return 0; }
r[5]=r[13];
goto P_0c0619ac;
P_0c0619ac: /* original 7504, guest PC 0x0c0619ac */
if(!s->budget--) { s->failed_pc=0x0c0619acu; return 0; }
r[5]+=0x00000004u;
goto P_0c0619ae;
P_0c0619ae: /* original b629, guest PC 0x0c0619ae */
if(!s->budget--) { s->failed_pc=0x0c0619aeu; return 0; }
target=code_base|0x0c062604u; r[16]=code_base|0x0c0619b2u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0619b2u) { target=s->pc; goto dispatch; }
goto P_0c0619b2;
P_0c0619b0: /* original 64d3, guest PC 0x0c0619b0 */
if(!s->budget--) { s->failed_pc=0x0c0619b0u; return 0; }
r[4]=r[13];
goto P_0c0619b2;
P_0c0619b2: /* original 65e3, guest PC 0x0c0619b2 */
if(!s->budget--) { s->failed_pc=0x0c0619b2u; return 0; }
r[5]=r[14];
goto P_0c0619b4;
P_0c0619b4: /* original 750c, guest PC 0x0c0619b4 */
if(!s->budget--) { s->failed_pc=0x0c0619b4u; return 0; }
r[5]+=0x0000000cu;
goto P_0c0619b6;
P_0c0619b6: /* original 64e3, guest PC 0x0c0619b6 */
if(!s->budget--) { s->failed_pc=0x0c0619b6u; return 0; }
r[4]=r[14];
goto P_0c0619b8;
P_0c0619b8: /* original b624, guest PC 0x0c0619b8 */
if(!s->budget--) { s->failed_pc=0x0c0619b8u; return 0; }
target=code_base|0x0c062604u; r[16]=code_base|0x0c0619bcu;
r[4]+=0x00000008u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0619bcu) { target=s->pc; goto dispatch; }
goto P_0c0619bc;
P_0c0619ba: /* original 7408, guest PC 0x0c0619ba */
if(!s->budget--) { s->failed_pc=0x0c0619bau; return 0; }
r[4]+=0x00000008u;
goto P_0c0619bc;
P_0c0619bc: /* original 65d3, guest PC 0x0c0619bc */
if(!s->budget--) { s->failed_pc=0x0c0619bcu; return 0; }
r[5]=r[13];
goto P_0c0619be;
P_0c0619be: /* original 750c, guest PC 0x0c0619be */
if(!s->budget--) { s->failed_pc=0x0c0619beu; return 0; }
r[5]+=0x0000000cu;
goto P_0c0619c0;
P_0c0619c0: /* original 64d3, guest PC 0x0c0619c0 */
if(!s->budget--) { s->failed_pc=0x0c0619c0u; return 0; }
r[4]=r[13];
goto P_0c0619c2;
P_0c0619c2: /* original b61f, guest PC 0x0c0619c2 */
if(!s->budget--) { s->failed_pc=0x0c0619c2u; return 0; }
target=code_base|0x0c062604u; r[16]=code_base|0x0c0619c6u;
r[4]+=0x00000008u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0619c6u) { target=s->pc; goto dispatch; }
goto P_0c0619c6;
P_0c0619c4: /* original 7408, guest PC 0x0c0619c4 */
if(!s->budget--) { s->failed_pc=0x0c0619c4u; return 0; }
r[4]+=0x00000008u;
goto P_0c0619c6;
P_0c0619c6: /* original e000, guest PC 0x0c0619c6 */
if(!s->budget--) { s->failed_pc=0x0c0619c6u; return 0; }
r[0]=0x00000000u;
goto P_0c0619c8;
P_0c0619c8: /* original 4f26, guest PC 0x0c0619c8 */
if(!s->budget--) { s->failed_pc=0x0c0619c8u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0619ca;
P_0c0619ca: /* original 6df6, guest PC 0x0c0619ca */
if(!s->budget--) { s->failed_pc=0x0c0619cau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0619cc;
P_0c0619cc: /* original 000b, guest PC 0x0c0619cc */
if(!s->budget--) { s->failed_pc=0x0c0619ccu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0619ce: /* original 6ef6, guest PC 0x0c0619ce */
if(!s->budget--) { s->failed_pc=0x0c0619ceu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0619d0;
P_0c0619d0: /* original 2fe6, guest PC 0x0c0619d0 */
if(!s->budget--) { s->failed_pc=0x0c0619d0u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0619d2;
P_0c0619d2: /* original 4f22, guest PC 0x0c0619d2 */
if(!s->budget--) { s->failed_pc=0x0c0619d2u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0619d4;
P_0c0619d4: /* original de0d, guest PC 0x0c0619d4 */
if(!s->budget--) { s->failed_pc=0x0c0619d4u; return 0; }
r[14]=read(ram,0x0c061a0cu,4);
goto P_0c0619d6;
P_0c0619d6: /* original 67e3, guest PC 0x0c0619d6 */
if(!s->budget--) { s->failed_pc=0x0c0619d6u; return 0; }
r[7]=r[14];
goto P_0c0619d8;
P_0c0619d8: /* original 7704, guest PC 0x0c0619d8 */
if(!s->budget--) { s->failed_pc=0x0c0619d8u; return 0; }
r[7]+=0x00000004u;
goto P_0c0619da;
P_0c0619da: /* original 66e3, guest PC 0x0c0619da */
if(!s->budget--) { s->failed_pc=0x0c0619dau; return 0; }
r[6]=r[14];
goto P_0c0619dc;
P_0c0619dc: /* original 65e3, guest PC 0x0c0619dc */
if(!s->budget--) { s->failed_pc=0x0c0619dcu; return 0; }
r[5]=r[14];
goto P_0c0619de;
P_0c0619de: /* original 750c, guest PC 0x0c0619de */
if(!s->budget--) { s->failed_pc=0x0c0619deu; return 0; }
r[5]+=0x0000000cu;
goto P_0c0619e0;
P_0c0619e0: /* original 64e3, guest PC 0x0c0619e0 */
if(!s->budget--) { s->failed_pc=0x0c0619e0u; return 0; }
r[4]=r[14];
goto P_0c0619e2;
P_0c0619e2: /* original b665, guest PC 0x0c0619e2 */
if(!s->budget--) { s->failed_pc=0x0c0619e2u; return 0; }
target=code_base|0x0c0626b0u; r[16]=code_base|0x0c0619e6u;
r[4]+=0x00000008u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0619e6u) { target=s->pc; goto dispatch; }
goto P_0c0619e6;
P_0c0619e4: /* original 7408, guest PC 0x0c0619e4 */
if(!s->budget--) { s->failed_pc=0x0c0619e4u; return 0; }
r[4]+=0x00000008u;
goto P_0c0619e6;
P_0c0619e6: /* original 6403, guest PC 0x0c0619e6 */
if(!s->budget--) { s->failed_pc=0x0c0619e6u; return 0; }
r[4]=r[0];
goto P_0c0619e8;
P_0c0619e8: /* original 2448, guest PC 0x0c0619e8 */
if(!s->budget--) { s->failed_pc=0x0c0619e8u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c0619ea;
P_0c0619ea: /* original 8b09, guest PC 0x0c0619ea */
if(!s->budget--) { s->failed_pc=0x0c0619eau; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c061a00; }
goto P_0c0619ec;
P_0c0619ec: /* original de08, guest PC 0x0c0619ec */
if(!s->budget--) { s->failed_pc=0x0c0619ecu; return 0; }
r[14]=read(ram,0x0c061a10u,4);
goto P_0c0619ee;
P_0c0619ee: /* original 67e3, guest PC 0x0c0619ee */
if(!s->budget--) { s->failed_pc=0x0c0619eeu; return 0; }
r[7]=r[14];
goto P_0c0619f0;
P_0c0619f0: /* original 7704, guest PC 0x0c0619f0 */
if(!s->budget--) { s->failed_pc=0x0c0619f0u; return 0; }
r[7]+=0x00000004u;
goto P_0c0619f2;
P_0c0619f2: /* original 66e3, guest PC 0x0c0619f2 */
if(!s->budget--) { s->failed_pc=0x0c0619f2u; return 0; }
r[6]=r[14];
goto P_0c0619f4;
P_0c0619f4: /* original 65e3, guest PC 0x0c0619f4 */
if(!s->budget--) { s->failed_pc=0x0c0619f4u; return 0; }
r[5]=r[14];
goto P_0c0619f6;
P_0c0619f6: /* original 750c, guest PC 0x0c0619f6 */
if(!s->budget--) { s->failed_pc=0x0c0619f6u; return 0; }
r[5]+=0x0000000cu;
goto P_0c0619f8;
P_0c0619f8: /* original 64e3, guest PC 0x0c0619f8 */
if(!s->budget--) { s->failed_pc=0x0c0619f8u; return 0; }
r[4]=r[14];
goto P_0c0619fa;
P_0c0619fa: /* original b659, guest PC 0x0c0619fa */
if(!s->budget--) { s->failed_pc=0x0c0619fau; return 0; }
target=code_base|0x0c0626b0u; r[16]=code_base|0x0c0619feu;
r[4]+=0x00000008u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0619feu) { target=s->pc; goto dispatch; }
goto P_0c0619fe;
P_0c0619fc: /* original 7408, guest PC 0x0c0619fc */
if(!s->budget--) { s->failed_pc=0x0c0619fcu; return 0; }
r[4]+=0x00000008u;
goto P_0c0619fe;
P_0c0619fe: /* original 6403, guest PC 0x0c0619fe */
if(!s->budget--) { s->failed_pc=0x0c0619feu; return 0; }
r[4]=r[0];
goto P_0c061a00;
P_0c061a00: /* original 6043, guest PC 0x0c061a00 */
if(!s->budget--) { s->failed_pc=0x0c061a00u; return 0; }
r[0]=r[4];
goto P_0c061a02;
P_0c061a02: /* original 0009, guest PC 0x0c061a02 */
if(!s->budget--) { s->failed_pc=0x0c061a02u; return 0; }
goto P_0c061a04;
P_0c061a04: /* original 4f26, guest PC 0x0c061a04 */
if(!s->budget--) { s->failed_pc=0x0c061a04u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c061a06;
P_0c061a06: /* original 000b, guest PC 0x0c061a06 */
if(!s->budget--) { s->failed_pc=0x0c061a06u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c061a08: /* original 6ef6, guest PC 0x0c061a08 */
if(!s->budget--) { s->failed_pc=0x0c061a08u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c061a0au,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c061a0au; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
