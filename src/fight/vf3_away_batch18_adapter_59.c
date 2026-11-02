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
int vf3_away_batch18_adapter_59(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c0c1a62u: goto P_0c0c1a62;
case 0x0c0c1a64u: goto P_0c0c1a64;
case 0x0c0c27aau: goto P_0c0c27aa;
case 0x0c0c27acu: goto P_0c0c27ac;
case 0x0c0c27aeu: goto P_0c0c27ae;
case 0x0c0c27b0u: goto P_0c0c27b0;
case 0x0c0c27b2u: goto P_0c0c27b2;
case 0x0c0c27b4u: goto P_0c0c27b4;
case 0x0c0c27b6u: goto P_0c0c27b6;
case 0x0c0c27b8u: goto P_0c0c27b8;
case 0x0c0c27bau: goto P_0c0c27ba;
case 0x0c0c27bcu: goto P_0c0c27bc;
case 0x0c0c27beu: goto P_0c0c27be;
case 0x0c0c27c0u: goto P_0c0c27c0;
case 0x0c0c27c2u: goto P_0c0c27c2;
case 0x0c0c27c4u: goto P_0c0c27c4;
case 0x0c0c27c6u: goto P_0c0c27c6;
case 0x0c0c27c8u: goto P_0c0c27c8;
case 0x0c0c27cau: goto P_0c0c27ca;
case 0x0c0c27ccu: goto P_0c0c27cc;
case 0x0c0c27ceu: goto P_0c0c27ce;
case 0x0c0c27d0u: goto P_0c0c27d0;
case 0x0c0c27d2u: goto P_0c0c27d2;
case 0x0c0c27d4u: goto P_0c0c27d4;
case 0x0c0c27d6u: goto P_0c0c27d6;
case 0x0c0c27d8u: goto P_0c0c27d8;
case 0x0c0c27dau: goto P_0c0c27da;
case 0x0c0c27dcu: goto P_0c0c27dc;
case 0x0c0c27deu: goto P_0c0c27de;
case 0x0c0c27e0u: goto P_0c0c27e0;
case 0x0c0c27e2u: goto P_0c0c27e2;
case 0x0c0c27e4u: goto P_0c0c27e4;
case 0x0c0c27e6u: goto P_0c0c27e6;
case 0x0c0c27e8u: goto P_0c0c27e8;
case 0x0c0c27eau: goto P_0c0c27ea;
case 0x0c0c27ecu: goto P_0c0c27ec;
case 0x0c0c27eeu: goto P_0c0c27ee;
case 0x0c0c27f0u: goto P_0c0c27f0;
case 0x0c0c27f2u: goto P_0c0c27f2;
case 0x0c0c27f4u: goto P_0c0c27f4;
case 0x0c0c27f6u: goto P_0c0c27f6;
case 0x0c0c27f8u: goto P_0c0c27f8;
case 0x0c0c27fau: goto P_0c0c27fa;
case 0x0c0c27fcu: goto P_0c0c27fc;
case 0x0c0c27feu: goto P_0c0c27fe;
case 0x0c0c2800u: goto P_0c0c2800;
case 0x0c0c2802u: goto P_0c0c2802;
case 0x0c0c2804u: goto P_0c0c2804;
case 0x0c0c2806u: goto P_0c0c2806;
case 0x0c0c2808u: goto P_0c0c2808;
case 0x0c0c42ecu: goto P_0c0c42ec;
case 0x0c0c42eeu: goto P_0c0c42ee;
case 0x0c0c42f0u: goto P_0c0c42f0;
case 0x0c0c42f2u: goto P_0c0c42f2;
case 0x0c0c42f4u: goto P_0c0c42f4;
case 0x0c0c42f6u: goto P_0c0c42f6;
case 0x0c0c42f8u: goto P_0c0c42f8;
case 0x0c0c42fau: goto P_0c0c42fa;
case 0x0c0c42fcu: goto P_0c0c42fc;
case 0x0c0c42feu: goto P_0c0c42fe;
case 0x0c0c4300u: goto P_0c0c4300;
case 0x0c0c4302u: goto P_0c0c4302;
case 0x0c0c4304u: goto P_0c0c4304;
case 0x0c0c4306u: goto P_0c0c4306;
case 0x0c0c4308u: goto P_0c0c4308;
case 0x0c0c430au: goto P_0c0c430a;
case 0x0c0c430cu: goto P_0c0c430c;
case 0x0c0c430eu: goto P_0c0c430e;
case 0x0c0c4310u: goto P_0c0c4310;
case 0x0c0c4312u: goto P_0c0c4312;
case 0x0c0c4314u: goto P_0c0c4314;
case 0x0c0c4316u: goto P_0c0c4316;
case 0x0c0c4318u: goto P_0c0c4318;
case 0x0c0c431au: goto P_0c0c431a;
case 0x0c0c431cu: goto P_0c0c431c;
case 0x0c0c431eu: goto P_0c0c431e;
case 0x0c0c4320u: goto P_0c0c4320;
case 0x0c0c4322u: goto P_0c0c4322;
case 0x0c0c4324u: goto P_0c0c4324;
case 0x0c0c434cu: goto P_0c0c434c;
case 0x0c0c434eu: goto P_0c0c434e;
case 0x0c0c4350u: goto P_0c0c4350;
case 0x0c0c4352u: goto P_0c0c4352;
case 0x0c0c4354u: goto P_0c0c4354;
case 0x0c0c4356u: goto P_0c0c4356;
case 0x0c0c4358u: goto P_0c0c4358;
case 0x0c0c435au: goto P_0c0c435a;
case 0x0c0c435cu: goto P_0c0c435c;
case 0x0c0c435eu: goto P_0c0c435e;
case 0x0c0c4360u: goto P_0c0c4360;
case 0x0c0c4362u: goto P_0c0c4362;
case 0x0c0c4364u: goto P_0c0c4364;
case 0x0c0c4366u: goto P_0c0c4366;
case 0x0c0c4368u: goto P_0c0c4368;
case 0x0c0c436au: goto P_0c0c436a;
case 0x0c0c436cu: goto P_0c0c436c;
case 0x0c0c436eu: goto P_0c0c436e;
case 0x0c0c4370u: goto P_0c0c4370;
case 0x0c0c4372u: goto P_0c0c4372;
case 0x0c0c4374u: goto P_0c0c4374;
case 0x0c0c4376u: goto P_0c0c4376;
case 0x0c0c4378u: goto P_0c0c4378;
case 0x0c0c437au: goto P_0c0c437a;
case 0x0c0c5c94u: goto P_0c0c5c94;
case 0x0c0c5c96u: goto P_0c0c5c96;
case 0x0c0c5c98u: goto P_0c0c5c98;
case 0x0c0c5c9au: goto P_0c0c5c9a;
case 0x0c0c5c9cu: goto P_0c0c5c9c;
case 0x0c0c5c9eu: goto P_0c0c5c9e;
case 0x0c0c5ca0u: goto P_0c0c5ca0;
case 0x0c0c5ca2u: goto P_0c0c5ca2;
case 0x0c0c5ca4u: goto P_0c0c5ca4;
case 0x0c0c5ca6u: goto P_0c0c5ca6;
case 0x0c0c5ca8u: goto P_0c0c5ca8;
case 0x0c0c5caau: goto P_0c0c5caa;
case 0x0c0c5cacu: goto P_0c0c5cac;
case 0x0c0c5caeu: goto P_0c0c5cae;
case 0x0c0c5cb0u: goto P_0c0c5cb0;
case 0x0c0c5cf4u: goto P_0c0c5cf4;
case 0x0c0c5cf6u: goto P_0c0c5cf6;
case 0x0c0c5cf8u: goto P_0c0c5cf8;
case 0x0c0c5cfau: goto P_0c0c5cfa;
case 0x0c0c5cfcu: goto P_0c0c5cfc;
case 0x0c0c5cfeu: goto P_0c0c5cfe;
case 0x0c0c5d00u: goto P_0c0c5d00;
case 0x0c0c5d02u: goto P_0c0c5d02;
case 0x0c0c5d04u: goto P_0c0c5d04;
case 0x0c0c5d06u: goto P_0c0c5d06;
case 0x0c0c5d08u: goto P_0c0c5d08;
case 0x0c0c5d0au: goto P_0c0c5d0a;
case 0x0c0c5d0cu: goto P_0c0c5d0c;
case 0x0c0c5d0eu: goto P_0c0c5d0e;
case 0x0c0c5d10u: goto P_0c0c5d10;
case 0x0c0c5d12u: goto P_0c0c5d12;
case 0x0c0c5d14u: goto P_0c0c5d14;
case 0x0c0c5d16u: goto P_0c0c5d16;
case 0x0c0c5d18u: goto P_0c0c5d18;
case 0x0c0c5d1au: goto P_0c0c5d1a;
case 0x0c0c5d1cu: goto P_0c0c5d1c;
case 0x0c0c5d1eu: goto P_0c0c5d1e;
case 0x0c0c5d20u: goto P_0c0c5d20;
case 0x0c0c5d22u: goto P_0c0c5d22;
case 0x0c0c5d24u: goto P_0c0c5d24;
case 0x0c0c5d26u: goto P_0c0c5d26;
case 0x0c0c5d28u: goto P_0c0c5d28;
case 0x0c0c5d2au: goto P_0c0c5d2a;
case 0x0c0c5d2cu: goto P_0c0c5d2c;
case 0x0c0c5d2eu: goto P_0c0c5d2e;
case 0x0c0c5d30u: goto P_0c0c5d30;
case 0x0c0c5d32u: goto P_0c0c5d32;
case 0x0c0c5d34u: goto P_0c0c5d34;
case 0x0c0c5d36u: goto P_0c0c5d36;
case 0x0c0c5d38u: goto P_0c0c5d38;
case 0x0c0c5d3au: goto P_0c0c5d3a;
case 0x0c0c5d3cu: goto P_0c0c5d3c;
case 0x0c0c5d3eu: goto P_0c0c5d3e;
case 0x0c0c5d40u: goto P_0c0c5d40;
case 0x0c0c5d42u: goto P_0c0c5d42;
case 0x0c0c5d44u: goto P_0c0c5d44;
case 0x0c0c5d46u: goto P_0c0c5d46;
case 0x0c0c5d48u: goto P_0c0c5d48;
case 0x0c0c5d4au: goto P_0c0c5d4a;
case 0x0c0c5d4cu: goto P_0c0c5d4c;
case 0x0c0c5d4eu: goto P_0c0c5d4e;
case 0x0c0c5d50u: goto P_0c0c5d50;
case 0x0c0c5d52u: goto P_0c0c5d52;
case 0x0c0c5d54u: goto P_0c0c5d54;
case 0x0c0c5d56u: goto P_0c0c5d56;
case 0x0c0c5d58u: goto P_0c0c5d58;
case 0x0c0c5d5au: goto P_0c0c5d5a;
case 0x0c0c5d5cu: goto P_0c0c5d5c;
case 0x0c0c5d5eu: goto P_0c0c5d5e;
case 0x0c0c5d60u: goto P_0c0c5d60;
case 0x0c0c5d62u: goto P_0c0c5d62;
case 0x0c0c5d64u: goto P_0c0c5d64;
case 0x0c0c5d66u: goto P_0c0c5d66;
case 0x0c0c5d68u: goto P_0c0c5d68;
case 0x0c0c5d6au: goto P_0c0c5d6a;
case 0x0c0c5d6cu: goto P_0c0c5d6c;
case 0x0c0c5d6eu: goto P_0c0c5d6e;
case 0x0c0c5d70u: goto P_0c0c5d70;
case 0x0c0c5d72u: goto P_0c0c5d72;
case 0x0c0c5d74u: goto P_0c0c5d74;
case 0x0c0c5d76u: goto P_0c0c5d76;
case 0x0c0c5d78u: goto P_0c0c5d78;
case 0x0c0c5d7au: goto P_0c0c5d7a;
case 0x0c0c5d7cu: goto P_0c0c5d7c;
case 0x0c0c5d7eu: goto P_0c0c5d7e;
case 0x0c0c5d80u: goto P_0c0c5d80;
case 0x0c0c5d82u: goto P_0c0c5d82;
case 0x0c0c5d84u: goto P_0c0c5d84;
case 0x0c0c5d86u: goto P_0c0c5d86;
case 0x0c0c5d88u: goto P_0c0c5d88;
case 0x0c0c5d8au: goto P_0c0c5d8a;
case 0x0c0c5d8cu: goto P_0c0c5d8c;
case 0x0c0c5d8eu: goto P_0c0c5d8e;
case 0x0c0c5d90u: goto P_0c0c5d90;
case 0x0c0c5d92u: goto P_0c0c5d92;
case 0x0c0c5d94u: goto P_0c0c5d94;
case 0x0c0c5d96u: goto P_0c0c5d96;
case 0x0c0c5d98u: goto P_0c0c5d98;
case 0x0c0c5d9au: goto P_0c0c5d9a;
case 0x0c0c5d9cu: goto P_0c0c5d9c;
case 0x0c0c5d9eu: goto P_0c0c5d9e;
case 0x0c0c5da0u: goto P_0c0c5da0;
case 0x0c0c5da2u: goto P_0c0c5da2;
case 0x0c0c5da4u: goto P_0c0c5da4;
case 0x0c0c5da6u: goto P_0c0c5da6;
case 0x0c0c5da8u: goto P_0c0c5da8;
case 0x0c0c5daau: goto P_0c0c5daa;
case 0x0c0c5dacu: goto P_0c0c5dac;
case 0x0c0c5daeu: goto P_0c0c5dae;
case 0x0c0c5db0u: goto P_0c0c5db0;
case 0x0c0c5db2u: goto P_0c0c5db2;
case 0x0c0c5db4u: goto P_0c0c5db4;
case 0x0c0c5db6u: goto P_0c0c5db6;
case 0x0c0c5db8u: goto P_0c0c5db8;
default: return vf3_matrix_family(target,s,ram);
}
P_0c0c1a62: /* original 000b, guest PC 0x0c0c1a62 */
if(!s->budget--) { s->failed_pc=0x0c0c1a62u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c0c1a64: /* original 0009, guest PC 0x0c0c1a64 */
if(!s->budget--) { s->failed_pc=0x0c0c1a64u; return 0; }
if(!vf3_matrix_family(0x0c0c1a66u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0c1a66u; return 0; } return 1;
P_0c0c27aa: /* original 2fe6, guest PC 0x0c0c27aa */
if(!s->budget--) { s->failed_pc=0x0c0c27aau; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c27ac;
P_0c0c27ac: /* original d324, guest PC 0x0c0c27ac */
if(!s->budget--) { s->failed_pc=0x0c0c27acu; return 0; }
r[3]=read(ram,0x0c0c2840u,4);
goto P_0c0c27ae;
P_0c0c27ae: /* original 4f22, guest PC 0x0c0c27ae */
if(!s->budget--) { s->failed_pc=0x0c0c27aeu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0c27b0;
P_0c0c27b0: /* original d224, guest PC 0x0c0c27b0 */
if(!s->budget--) { s->failed_pc=0x0c0c27b0u; return 0; }
r[2]=read(ram,0x0c0c2844u,4);
goto P_0c0c27b2;
P_0c0c27b2: /* original 6532, guest PC 0x0c0c27b2 */
if(!s->budget--) { s->failed_pc=0x0c0c27b2u; return 0; }
tmp=read(ram,r[3],4);
r[5]=tmp;
goto P_0c0c27b4;
P_0c0c27b4: /* original 420b, guest PC 0x0c0c27b4 */
if(!s->budget--) { s->failed_pc=0x0c0c27b4u; return 0; }
target=r[2];
r[16]=code_base|0x0c0c27b8u;
r[4]=0x0000001du;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c27b8u) { target=s->pc; goto dispatch; }
goto P_0c0c27b8;
P_0c0c27b6: /* original e41d, guest PC 0x0c0c27b6 */
if(!s->budget--) { s->failed_pc=0x0c0c27b6u; return 0; }
r[4]=0x0000001du;
goto P_0c0c27b8;
P_0c0c27b8: /* original de1c, guest PC 0x0c0c27b8 */
if(!s->budget--) { s->failed_pc=0x0c0c27b8u; return 0; }
r[14]=read(ram,0x0c0c282cu,4);
goto P_0c0c27ba;
P_0c0c27ba: /* original 942f, guest PC 0x0c0c27ba */
if(!s->budget--) { s->failed_pc=0x0c0c27bau; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c281cu,2);
goto P_0c0c27bc;
P_0c0c27bc: /* original d31c, guest PC 0x0c0c27bc */
if(!s->budget--) { s->failed_pc=0x0c0c27bcu; return 0; }
r[3]=read(ram,0x0c0c2830u,4);
goto P_0c0c27be;
P_0c0c27be: /* original 66e3, guest PC 0x0c0c27be */
if(!s->budget--) { s->failed_pc=0x0c0c27beu; return 0; }
r[6]=r[14];
goto P_0c0c27c0;
P_0c0c27c0: /* original 7658, guest PC 0x0c0c27c0 */
if(!s->budget--) { s->failed_pc=0x0c0c27c0u; return 0; }
r[6]+=0x00000058u;
goto P_0c0c27c2;
P_0c0c27c2: /* original 430b, guest PC 0x0c0c27c2 */
if(!s->budget--) { s->failed_pc=0x0c0c27c2u; return 0; }
target=r[3];
r[16]=code_base|0x0c0c27c6u;
r[5]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c27c6u) { target=s->pc; goto dispatch; }
goto P_0c0c27c6;
P_0c0c27c4: /* original 65e3, guest PC 0x0c0c27c4 */
if(!s->budget--) { s->failed_pc=0x0c0c27c4u; return 0; }
r[5]=r[14];
goto P_0c0c27c6;
P_0c0c27c6: /* original d220, guest PC 0x0c0c27c6 */
if(!s->budget--) { s->failed_pc=0x0c0c27c6u; return 0; }
r[2]=read(ram,0x0c0c2848u,4);
goto P_0c0c27c8;
P_0c0c27c8: /* original 420b, guest PC 0x0c0c27c8 */
if(!s->budget--) { s->failed_pc=0x0c0c27c8u; return 0; }
target=r[2];
r[16]=code_base|0x0c0c27ccu;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c27ccu) { target=s->pc; goto dispatch; }
goto P_0c0c27cc;
P_0c0c27ca: /* original 64e3, guest PC 0x0c0c27ca */
if(!s->budget--) { s->failed_pc=0x0c0c27cau; return 0; }
r[4]=r[14];
goto P_0c0c27cc;
P_0c0c27cc: /* original e300, guest PC 0x0c0c27cc */
if(!s->budget--) { s->failed_pc=0x0c0c27ccu; return 0; }
r[3]=0x00000000u;
goto P_0c0c27ce;
P_0c0c27ce: /* original 64e3, guest PC 0x0c0c27ce */
if(!s->budget--) { s->failed_pc=0x0c0c27ceu; return 0; }
r[4]=r[14];
goto P_0c0c27d0;
P_0c0c27d0: /* original 6533, guest PC 0x0c0c27d0 */
if(!s->budget--) { s->failed_pc=0x0c0c27d0u; return 0; }
r[5]=r[3];
goto P_0c0c27d2;
P_0c0c27d2: /* original e63f, guest PC 0x0c0c27d2 */
if(!s->budget--) { s->failed_pc=0x0c0c27d2u; return 0; }
r[6]=0x0000003fu;
goto P_0c0c27d4;
P_0c0c27d4: /* original 2f36, guest PC 0x0c0c27d4 */
if(!s->budget--) { s->failed_pc=0x0c0c27d4u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c27d6;
P_0c0c27d6: /* original e731, guest PC 0x0c0c27d6 */
if(!s->budget--) { s->failed_pc=0x0c0c27d6u; return 0; }
r[7]=0x00000031u;
goto P_0c0c27d8;
P_0c0c27d8: /* original b82d, guest PC 0x0c0c27d8 */
if(!s->budget--) { s->failed_pc=0x0c0c27d8u; return 0; }
target=code_base|0x0c0c1836u; r[16]=code_base|0x0c0c27dcu;
r[4]+=0x00000058u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c27dcu) { target=s->pc; goto dispatch; }
goto P_0c0c27dc;
P_0c0c27da: /* original 7458, guest PC 0x0c0c27da */
if(!s->budget--) { s->failed_pc=0x0c0c27dau; return 0; }
r[4]+=0x00000058u;
goto P_0c0c27dc;
P_0c0c27dc: /* original 901f, guest PC 0x0c0c27dc */
if(!s->budget--) { s->failed_pc=0x0c0c27dcu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c281eu,2);
goto P_0c0c27de;
P_0c0c27de: /* original e400, guest PC 0x0c0c27de */
if(!s->budget--) { s->failed_pc=0x0c0c27deu; return 0; }
r[4]=0x00000000u;
goto P_0c0c27e0;
P_0c0c27e0: /* original e32f, guest PC 0x0c0c27e0 */
if(!s->budget--) { s->failed_pc=0x0c0c27e0u; return 0; }
r[3]=0x0000002fu;
goto P_0c0c27e2;
P_0c0c27e2: /* original 0e46, guest PC 0x0c0c27e2 */
if(!s->budget--) { s->failed_pc=0x0c0c27e2u; return 0; }
write(ram,r[14]+r[0],r[4],4);
goto P_0c0c27e4;
P_0c0c27e4: /* original 7f04, guest PC 0x0c0c27e4 */
if(!s->budget--) { s->failed_pc=0x0c0c27e4u; return 0; }
r[15]+=0x00000004u;
goto P_0c0c27e6;
P_0c0c27e6: /* original 901b, guest PC 0x0c0c27e6 */
if(!s->budget--) { s->failed_pc=0x0c0c27e6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c2820u,2);
goto P_0c0c27e8;
P_0c0c27e8: /* original 0e46, guest PC 0x0c0c27e8 */
if(!s->budget--) { s->failed_pc=0x0c0c27e8u; return 0; }
write(ram,r[14]+r[0],r[4],4);
goto P_0c0c27ea;
P_0c0c27ea: /* original 901a, guest PC 0x0c0c27ea */
if(!s->budget--) { s->failed_pc=0x0c0c27eau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c2822u,2);
goto P_0c0c27ec;
P_0c0c27ec: /* original 0e35, guest PC 0x0c0c27ec */
if(!s->budget--) { s->failed_pc=0x0c0c27ecu; return 0; }
write(ram,r[14]+r[0],r[3],2);
goto P_0c0c27ee;
P_0c0c27ee: /* original d317, guest PC 0x0c0c27ee */
if(!s->budget--) { s->failed_pc=0x0c0c27eeu; return 0; }
r[3]=read(ram,0x0c0c284cu,4);
goto P_0c0c27f0;
P_0c0c27f0: /* original 430b, guest PC 0x0c0c27f0 */
if(!s->budget--) { s->failed_pc=0x0c0c27f0u; return 0; }
target=r[3];
r[16]=code_base|0x0c0c27f4u;
r[4]=0x00000015u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c27f4u) { target=s->pc; goto dispatch; }
goto P_0c0c27f4;
P_0c0c27f2: /* original e415, guest PC 0x0c0c27f2 */
if(!s->budget--) { s->failed_pc=0x0c0c27f2u; return 0; }
r[4]=0x00000015u;
goto P_0c0c27f4;
P_0c0c27f4: /* original d317, guest PC 0x0c0c27f4 */
if(!s->budget--) { s->failed_pc=0x0c0c27f4u; return 0; }
r[3]=read(ram,0x0c0c2854u,4);
goto P_0c0c27f6;
P_0c0c27f6: /* original d416, guest PC 0x0c0c27f6 */
if(!s->budget--) { s->failed_pc=0x0c0c27f6u; return 0; }
r[4]=read(ram,0x0c0c2850u,4);
goto P_0c0c27f8;
P_0c0c27f8: /* original d211, guest PC 0x0c0c27f8 */
if(!s->budget--) { s->failed_pc=0x0c0c27f8u; return 0; }
r[2]=read(ram,0x0c0c2840u,4);
goto P_0c0c27fa;
P_0c0c27fa: /* original 430b, guest PC 0x0c0c27fa */
if(!s->budget--) { s->failed_pc=0x0c0c27fau; return 0; }
target=r[3];
r[16]=code_base|0x0c0c27feu;
tmp=read(ram,r[2],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c27feu) { target=s->pc; goto dispatch; }
goto P_0c0c27fe;
P_0c0c27fc: /* original 6522, guest PC 0x0c0c27fc */
if(!s->budget--) { s->failed_pc=0x0c0c27fcu; return 0; }
tmp=read(ram,r[2],4);
r[5]=tmp;
goto P_0c0c27fe;
P_0c0c27fe: /* original 4f26, guest PC 0x0c0c27fe */
if(!s->budget--) { s->failed_pc=0x0c0c27feu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0c2800;
P_0c0c2800: /* original d215, guest PC 0x0c0c2800 */
if(!s->budget--) { s->failed_pc=0x0c0c2800u; return 0; }
r[2]=read(ram,0x0c0c2858u,4);
goto P_0c0c2802;
P_0c0c2802: /* original e315, guest PC 0x0c0c2802 */
if(!s->budget--) { s->failed_pc=0x0c0c2802u; return 0; }
r[3]=0x00000015u;
goto P_0c0c2804;
P_0c0c2804: /* original 2231, guest PC 0x0c0c2804 */
if(!s->budget--) { s->failed_pc=0x0c0c2804u; return 0; }
write(ram,r[2],r[3],2);
goto P_0c0c2806;
P_0c0c2806: /* original 000b, guest PC 0x0c0c2806 */
if(!s->budget--) { s->failed_pc=0x0c0c2806u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0c2808: /* original 6ef6, guest PC 0x0c0c2808 */
if(!s->budget--) { s->failed_pc=0x0c0c2808u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0c280au,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0c280au; return 0; } return 1;
P_0c0c42ec: /* original d313, guest PC 0x0c0c42ec */
if(!s->budget--) { s->failed_pc=0x0c0c42ecu; return 0; }
r[3]=read(ram,0x0c0c433cu,4);
goto P_0c0c42ee;
P_0c0c42ee: /* original 7ff8, guest PC 0x0c0c42ee */
if(!s->budget--) { s->failed_pc=0x0c0c42eeu; return 0; }
r[15]+=0xfffffff8u;
goto P_0c0c42f0;
P_0c0c42f0: /* original 2f32, guest PC 0x0c0c42f0 */
if(!s->budget--) { s->failed_pc=0x0c0c42f0u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c0c42f2;
P_0c0c42f2: /* original e306, guest PC 0x0c0c42f2 */
if(!s->budget--) { s->failed_pc=0x0c0c42f2u; return 0; }
r[3]=0x00000006u;
goto P_0c0c42f4;
P_0c0c42f4: /* original d213, guest PC 0x0c0c42f4 */
if(!s->budget--) { s->failed_pc=0x0c0c42f4u; return 0; }
r[2]=read(ram,0x0c0c4344u,4);
goto P_0c0c42f6;
P_0c0c42f6: /* original 1f21, guest PC 0x0c0c42f6 */
if(!s->budget--) { s->failed_pc=0x0c0c42f6u; return 0; }
write(ram,r[15]+4,r[2],4);
goto P_0c0c42f8;
P_0c0c42f8: /* original 6742, guest PC 0x0c0c42f8 */
if(!s->budget--) { s->failed_pc=0x0c0c42f8u; return 0; }
tmp=read(ram,r[4],4);
r[7]=tmp;
goto P_0c0c42fa;
P_0c0c42fa: /* original 2738, guest PC 0x0c0c42fa */
if(!s->budget--) { s->failed_pc=0x0c0c42fau; return 0; }
r[17]=(r[17]&~1u)|(((r[7]&r[3])==0)!=0);
goto P_0c0c42fc;
P_0c0c42fc: /* original 8b10, guest PC 0x0c0c42fc */
if(!s->budget--) { s->failed_pc=0x0c0c42fcu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c4320; }
goto P_0c0c42fe;
P_0c0c42fe: /* original 9019, guest PC 0x0c0c42fe */
if(!s->budget--) { s->failed_pc=0x0c0c42feu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c4334u,2);
goto P_0c0c4300;
P_0c0c4300: /* original 53f1, guest PC 0x0c0c4300 */
if(!s->budget--) { s->failed_pc=0x0c0c4300u; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c0c4302;
P_0c0c4302: /* original 023c, guest PC 0x0c0c4302 */
if(!s->budget--) { s->failed_pc=0x0c0c4302u; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[3]+r[0],1);
goto P_0c0c4304;
P_0c0c4304: /* original 2228, guest PC 0x0c0c4304 */
if(!s->budget--) { s->failed_pc=0x0c0c4304u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c0c4306;
P_0c0c4306: /* original 8b02, guest PC 0x0c0c4306 */
if(!s->budget--) { s->failed_pc=0x0c0c4306u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c430e; }
goto P_0c0c4308;
P_0c0c4308: /* original 6253, guest PC 0x0c0c4308 */
if(!s->budget--) { s->failed_pc=0x0c0c4308u; return 0; }
r[2]=r[5];
goto P_0c0c430a;
P_0c0c430a: /* original 2268, guest PC 0x0c0c430a */
if(!s->budget--) { s->failed_pc=0x0c0c430au; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[6])==0)!=0);
goto P_0c0c430c;
P_0c0c430c: /* original 8908, guest PC 0x0c0c430c */
if(!s->budget--) { s->failed_pc=0x0c0c430cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c4320; }
goto P_0c0c430e;
P_0c0c430e: /* original e305, guest PC 0x0c0c430e */
if(!s->budget--) { s->failed_pc=0x0c0c430eu; return 0; }
r[3]=0x00000005u;
goto P_0c0c4310;
P_0c0c4310: /* original 2432, guest PC 0x0c0c4310 */
if(!s->budget--) { s->failed_pc=0x0c0c4310u; return 0; }
write(ram,r[4],r[3],4);
goto P_0c0c4312;
P_0c0c4312: /* original 6667, guest PC 0x0c0c4312 */
if(!s->budget--) { s->failed_pc=0x0c0c4312u; return 0; }
r[6]=~r[6];
goto P_0c0c4314;
P_0c0c4314: /* original d20c, guest PC 0x0c0c4314 */
if(!s->budget--) { s->failed_pc=0x0c0c4314u; return 0; }
r[2]=read(ram,0x0c0c4348u,4);
goto P_0c0c4316;
P_0c0c4316: /* original 2569, guest PC 0x0c0c4316 */
if(!s->budget--) { s->failed_pc=0x0c0c4316u; return 0; }
r[5]&=r[6];
goto P_0c0c4318;
P_0c0c4318: /* original 1423, guest PC 0x0c0c4318 */
if(!s->budget--) { s->failed_pc=0x0c0c4318u; return 0; }
write(ram,r[4]+12,r[2],4);
goto P_0c0c431a;
P_0c0c431a: /* original 920c, guest PC 0x0c0c431a */
if(!s->budget--) { s->failed_pc=0x0c0c431au; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c4336u,2);
goto P_0c0c431c;
P_0c0c431c: /* original 63f2, guest PC 0x0c0c431c */
if(!s->budget--) { s->failed_pc=0x0c0c431cu; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c0c431e;
P_0c0c431e: /* original 132b, guest PC 0x0c0c431e */
if(!s->budget--) { s->failed_pc=0x0c0c431eu; return 0; }
write(ram,r[3]+44,r[2],4);
goto P_0c0c4320;
P_0c0c4320: /* original 6053, guest PC 0x0c0c4320 */
if(!s->budget--) { s->failed_pc=0x0c0c4320u; return 0; }
r[0]=r[5];
goto P_0c0c4322;
P_0c0c4322: /* original 000b, guest PC 0x0c0c4322 */
if(!s->budget--) { s->failed_pc=0x0c0c4322u; return 0; }
target=r[16];
r[15]+=0x00000008u;
s->pc=target; return ram->oob==0;
P_0c0c4324: /* original 7f08, guest PC 0x0c0c4324 */
if(!s->budget--) { s->failed_pc=0x0c0c4324u; return 0; }
r[15]+=0x00000008u;
if(!vf3_matrix_family(0x0c0c4326u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0c4326u; return 0; } return 1;
P_0c0c434c: /* original d740, guest PC 0x0c0c434c */
if(!s->budget--) { s->failed_pc=0x0c0c434cu; return 0; }
r[7]=read(ram,0x0c0c4450u,4);
goto P_0c0c434e;
P_0c0c434e: /* original e302, guest PC 0x0c0c434e */
if(!s->budget--) { s->failed_pc=0x0c0c434eu; return 0; }
r[3]=0x00000002u;
goto P_0c0c4350;
P_0c0c4350: /* original d53e, guest PC 0x0c0c4350 */
if(!s->budget--) { s->failed_pc=0x0c0c4350u; return 0; }
r[5]=read(ram,0x0c0c444cu,4);
goto P_0c0c4352;
P_0c0c4352: /* original 567a, guest PC 0x0c0c4352 */
if(!s->budget--) { s->failed_pc=0x0c0c4352u; return 0; }
r[6]=read(ram,r[7]+40,4);
goto P_0c0c4354;
P_0c0c4354: /* original 6662, guest PC 0x0c0c4354 */
if(!s->budget--) { s->failed_pc=0x0c0c4354u; return 0; }
tmp=read(ram,r[6],4);
r[6]=tmp;
goto P_0c0c4356;
P_0c0c4356: /* original 2368, guest PC 0x0c0c4356 */
if(!s->budget--) { s->failed_pc=0x0c0c4356u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[6])==0)!=0);
goto P_0c0c4358;
P_0c0c4358: /* original 8f03, guest PC 0x0c0c4358 */
if(!s->budget--) { s->failed_pc=0x0c0c4358u; return 0; }
cond=r[17]&1u;
r[4]=0x00000000u;
if(!cond) { goto P_0c0c4362; }
goto P_0c0c435c;
P_0c0c435a: /* original e400, guest PC 0x0c0c435a */
if(!s->budget--) { s->failed_pc=0x0c0c435au; return 0; }
r[4]=0x00000000u;
goto P_0c0c435c;
P_0c0c435c: /* original e204, guest PC 0x0c0c435c */
if(!s->budget--) { s->failed_pc=0x0c0c435cu; return 0; }
r[2]=0x00000004u;
goto P_0c0c435e;
P_0c0c435e: /* original 2628, guest PC 0x0c0c435e */
if(!s->budget--) { s->failed_pc=0x0c0c435eu; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[2])==0)!=0);
goto P_0c0c4360;
P_0c0c4360: /* original 8900, guest PC 0x0c0c4360 */
if(!s->budget--) { s->failed_pc=0x0c0c4360u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c4364; }
goto P_0c0c4362;
P_0c0c4362: /* original e401, guest PC 0x0c0c4362 */
if(!s->budget--) { s->failed_pc=0x0c0c4362u; return 0; }
r[4]=0x00000001u;
goto P_0c0c4364;
P_0c0c4364: /* original 567b, guest PC 0x0c0c4364 */
if(!s->budget--) { s->failed_pc=0x0c0c4364u; return 0; }
r[6]=read(ram,r[7]+44,4);
goto P_0c0c4366;
P_0c0c4366: /* original e302, guest PC 0x0c0c4366 */
if(!s->budget--) { s->failed_pc=0x0c0c4366u; return 0; }
r[3]=0x00000002u;
goto P_0c0c4368;
P_0c0c4368: /* original 6662, guest PC 0x0c0c4368 */
if(!s->budget--) { s->failed_pc=0x0c0c4368u; return 0; }
tmp=read(ram,r[6],4);
r[6]=tmp;
goto P_0c0c436a;
P_0c0c436a: /* original 2368, guest PC 0x0c0c436a */
if(!s->budget--) { s->failed_pc=0x0c0c436au; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[6])==0)!=0);
goto P_0c0c436c;
P_0c0c436c: /* original 8f03, guest PC 0x0c0c436c */
if(!s->budget--) { s->failed_pc=0x0c0c436cu; return 0; }
cond=r[17]&1u;
r[0]=0x00000029u;
if(!cond) { goto P_0c0c4376; }
goto P_0c0c4370;
P_0c0c436e: /* original e029, guest PC 0x0c0c436e */
if(!s->budget--) { s->failed_pc=0x0c0c436eu; return 0; }
r[0]=0x00000029u;
goto P_0c0c4370;
P_0c0c4370: /* original e204, guest PC 0x0c0c4370 */
if(!s->budget--) { s->failed_pc=0x0c0c4370u; return 0; }
r[2]=0x00000004u;
goto P_0c0c4372;
P_0c0c4372: /* original 2628, guest PC 0x0c0c4372 */
if(!s->budget--) { s->failed_pc=0x0c0c4372u; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[2])==0)!=0);
goto P_0c0c4374;
P_0c0c4374: /* original 8900, guest PC 0x0c0c4374 */
if(!s->budget--) { s->failed_pc=0x0c0c4374u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c4378; }
goto P_0c0c4376;
P_0c0c4376: /* original 7402, guest PC 0x0c0c4376 */
if(!s->budget--) { s->failed_pc=0x0c0c4376u; return 0; }
r[4]+=0x00000002u;
goto P_0c0c4378;
P_0c0c4378: /* original 000b, guest PC 0x0c0c4378 */
if(!s->budget--) { s->failed_pc=0x0c0c4378u; return 0; }
target=r[16];
write(ram,r[5]+r[0],r[4],1);
s->pc=target; return ram->oob==0;
P_0c0c437a: /* original 0544, guest PC 0x0c0c437a */
if(!s->budget--) { s->failed_pc=0x0c0c437au; return 0; }
write(ram,r[5]+r[0],r[4],1);
if(!vf3_matrix_family(0x0c0c437cu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0c437cu; return 0; } return 1;
P_0c0c5c94: /* original 2fe6, guest PC 0x0c0c5c94 */
if(!s->budget--) { s->failed_pc=0x0c0c5c94u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c5c96;
P_0c0c5c96: /* original 6043, guest PC 0x0c0c5c96 */
if(!s->budget--) { s->failed_pc=0x0c0c5c96u; return 0; }
r[0]=r[4];
goto P_0c0c5c98;
P_0c0c5c98: /* original 2fd6, guest PC 0x0c0c5c98 */
if(!s->budget--) { s->failed_pc=0x0c0c5c98u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c5c9a;
P_0c0c5c9a: /* original 88ff, guest PC 0x0c0c5c9a */
if(!s->budget--) { s->failed_pc=0x0c0c5c9au; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xffffffffu)!=0);
goto P_0c0c5c9c;
P_0c0c5c9c: /* original 2fc6, guest PC 0x0c0c5c9c */
if(!s->budget--) { s->failed_pc=0x0c0c5c9cu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c5c9e;
P_0c0c5c9e: /* original 6d43, guest PC 0x0c0c5c9e */
if(!s->budget--) { s->failed_pc=0x0c0c5c9eu; return 0; }
r[13]=r[4];
goto P_0c0c5ca0;
P_0c0c5ca0: /* original 2fb6, guest PC 0x0c0c5ca0 */
if(!s->budget--) { s->failed_pc=0x0c0c5ca0u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c5ca2;
P_0c0c5ca2: /* original 4f22, guest PC 0x0c0c5ca2 */
if(!s->budget--) { s->failed_pc=0x0c0c5ca2u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0c5ca4;
P_0c0c5ca4: /* original 8d03, guest PC 0x0c0c5ca4 */
if(!s->budget--) { s->failed_pc=0x0c0c5ca4u; return 0; }
cond=r[17]&1u;
r[11]=r[5];
if(cond) { goto P_0c0c5cae; }
goto P_0c0c5ca8;
P_0c0c5ca6: /* original 6b53, guest PC 0x0c0c5ca6 */
if(!s->budget--) { s->failed_pc=0x0c0c5ca6u; return 0; }
r[11]=r[5];
goto P_0c0c5ca8;
P_0c0c5ca8: /* original 930d, guest PC 0x0c0c5ca8 */
if(!s->budget--) { s->failed_pc=0x0c0c5ca8u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c5cc6u,2);
goto P_0c0c5caa;
P_0c0c5caa: /* original 3d30, guest PC 0x0c0c5caa */
if(!s->budget--) { s->failed_pc=0x0c0c5caau; return 0; }
r[17]=(r[17]&~1u)|((r[13]==r[3])!=0);
goto P_0c0c5cac;
P_0c0c5cac: /* original 8b22, guest PC 0x0c0c5cac */
if(!s->budget--) { s->failed_pc=0x0c0c5cacu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c5cf4; }
goto P_0c0c5cae;
P_0c0c5cae: /* original a064, guest PC 0x0c0c5cae */
if(!s->budget--) { s->failed_pc=0x0c0c5caeu; return 0; }
r[0]=0xffffffffu;
goto P_0c0c5d7a;
P_0c0c5cb0: /* original e0ff, guest PC 0x0c0c5cb0 */
if(!s->budget--) { s->failed_pc=0x0c0c5cb0u; return 0; }
r[0]=0xffffffffu;
if(!vf3_matrix_family(0x0c0c5cb2u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0c5cb2u; return 0; } return 1;
P_0c0c5cf4: /* original 9381, guest PC 0x0c0c5cf4 */
if(!s->budget--) { s->failed_pc=0x0c0c5cf4u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c5dfau,2);
goto P_0c0c5cf6;
P_0c0c5cf6: /* original de43, guest PC 0x0c0c5cf6 */
if(!s->budget--) { s->failed_pc=0x0c0c5cf6u; return 0; }
r[14]=read(ram,0x0c0c5e04u,4);
goto P_0c0c5cf8;
P_0c0c5cf8: /* original 3d30, guest PC 0x0c0c5cf8 */
if(!s->budget--) { s->failed_pc=0x0c0c5cf8u; return 0; }
r[17]=(r[17]&~1u)|((r[13]==r[3])!=0);
goto P_0c0c5cfa;
P_0c0c5cfa: /* original 8905, guest PC 0x0c0c5cfa */
if(!s->budget--) { s->failed_pc=0x0c0c5cfau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c5d08; }
goto P_0c0c5cfc;
P_0c0c5cfc: /* original 917e, guest PC 0x0c0c5cfc */
if(!s->budget--) { s->failed_pc=0x0c0c5cfcu; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c5dfcu,2);
goto P_0c0c5cfe;
P_0c0c5cfe: /* original 3d10, guest PC 0x0c0c5cfe */
if(!s->budget--) { s->failed_pc=0x0c0c5cfeu; return 0; }
r[17]=(r[17]&~1u)|((r[13]==r[1])!=0);
goto P_0c0c5d00;
P_0c0c5d00: /* original 8902, guest PC 0x0c0c5d00 */
if(!s->budget--) { s->failed_pc=0x0c0c5d00u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c5d08; }
goto P_0c0c5d02;
P_0c0c5d02: /* original 907c, guest PC 0x0c0c5d02 */
if(!s->budget--) { s->failed_pc=0x0c0c5d02u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c5dfeu,2);
goto P_0c0c5d04;
P_0c0c5d04: /* original 3d00, guest PC 0x0c0c5d04 */
if(!s->budget--) { s->failed_pc=0x0c0c5d04u; return 0; }
r[17]=(r[17]&~1u)|((r[13]==r[0])!=0);
goto P_0c0c5d06;
P_0c0c5d06: /* original 8b07, guest PC 0x0c0c5d06 */
if(!s->budget--) { s->failed_pc=0x0c0c5d06u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c5d18; }
goto P_0c0c5d08;
P_0c0c5d08: /* original 65d3, guest PC 0x0c0c5d08 */
if(!s->budget--) { s->failed_pc=0x0c0c5d08u; return 0; }
r[5]=r[13];
goto P_0c0c5d0a;
P_0c0c5d0a: /* original 66b3, guest PC 0x0c0c5d0a */
if(!s->budget--) { s->failed_pc=0x0c0c5d0au; return 0; }
r[6]=r[11];
goto P_0c0c5d0c;
P_0c0c5d0c: /* original 4e0b, guest PC 0x0c0c5d0c */
if(!s->budget--) { s->failed_pc=0x0c0c5d0cu; return 0; }
target=r[14];
r[16]=code_base|0x0c0c5d10u;
r[4]=0x00000004u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c5d10u) { target=s->pc; goto dispatch; }
goto P_0c0c5d10;
P_0c0c5d0e: /* original e404, guest PC 0x0c0c5d0e */
if(!s->budget--) { s->failed_pc=0x0c0c5d0eu; return 0; }
r[4]=0x00000004u;
goto P_0c0c5d10;
P_0c0c5d10: /* original 65d3, guest PC 0x0c0c5d10 */
if(!s->budget--) { s->failed_pc=0x0c0c5d10u; return 0; }
r[5]=r[13];
goto P_0c0c5d12;
P_0c0c5d12: /* original 66b3, guest PC 0x0c0c5d12 */
if(!s->budget--) { s->failed_pc=0x0c0c5d12u; return 0; }
r[6]=r[11];
goto P_0c0c5d14;
P_0c0c5d14: /* original a02f, guest PC 0x0c0c5d14 */
if(!s->budget--) { s->failed_pc=0x0c0c5d14u; return 0; }
r[4]=0x00000003u;
goto P_0c0c5d76;
P_0c0c5d16: /* original e403, guest PC 0x0c0c5d16 */
if(!s->budget--) { s->failed_pc=0x0c0c5d16u; return 0; }
r[4]=0x00000003u;
goto P_0c0c5d18;
P_0c0c5d18: /* original d33c, guest PC 0x0c0c5d18 */
if(!s->budget--) { s->failed_pc=0x0c0c5d18u; return 0; }
r[3]=read(ram,0x0c0c5e0cu,4);
goto P_0c0c5d1a;
P_0c0c5d1a: /* original dc3b, guest PC 0x0c0c5d1a */
if(!s->budget--) { s->failed_pc=0x0c0c5d1au; return 0; }
r[12]=read(ram,0x0c0c5e08u,4);
goto P_0c0c5d1c;
P_0c0c5d1c: /* original 3d30, guest PC 0x0c0c5d1c */
if(!s->budget--) { s->failed_pc=0x0c0c5d1cu; return 0; }
r[17]=(r[17]&~1u)|((r[13]==r[3])!=0);
goto P_0c0c5d1e;
P_0c0c5d1e: /* original 8b0b, guest PC 0x0c0c5d1e */
if(!s->budget--) { s->failed_pc=0x0c0c5d1eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c5d38; }
goto P_0c0c5d20;
P_0c0c5d20: /* original 65c3, guest PC 0x0c0c5d20 */
if(!s->budget--) { s->failed_pc=0x0c0c5d20u; return 0; }
r[5]=r[12];
goto P_0c0c5d22;
P_0c0c5d22: /* original e600, guest PC 0x0c0c5d22 */
if(!s->budget--) { s->failed_pc=0x0c0c5d22u; return 0; }
r[6]=0x00000000u;
goto P_0c0c5d24;
P_0c0c5d24: /* original 4e0b, guest PC 0x0c0c5d24 */
if(!s->budget--) { s->failed_pc=0x0c0c5d24u; return 0; }
target=r[14];
r[16]=code_base|0x0c0c5d28u;
r[4]=0x00000001u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c5d28u) { target=s->pc; goto dispatch; }
goto P_0c0c5d28;
P_0c0c5d26: /* original e401, guest PC 0x0c0c5d26 */
if(!s->budget--) { s->failed_pc=0x0c0c5d26u; return 0; }
r[4]=0x00000001u;
goto P_0c0c5d28;
P_0c0c5d28: /* original 65c3, guest PC 0x0c0c5d28 */
if(!s->budget--) { s->failed_pc=0x0c0c5d28u; return 0; }
r[5]=r[12];
goto P_0c0c5d2a;
P_0c0c5d2a: /* original e600, guest PC 0x0c0c5d2a */
if(!s->budget--) { s->failed_pc=0x0c0c5d2au; return 0; }
r[6]=0x00000000u;
goto P_0c0c5d2c;
P_0c0c5d2c: /* original 4e0b, guest PC 0x0c0c5d2c */
if(!s->budget--) { s->failed_pc=0x0c0c5d2cu; return 0; }
target=r[14];
r[16]=code_base|0x0c0c5d30u;
r[4]=0x00000002u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c5d30u) { target=s->pc; goto dispatch; }
goto P_0c0c5d30;
P_0c0c5d2e: /* original e402, guest PC 0x0c0c5d2e */
if(!s->budget--) { s->failed_pc=0x0c0c5d2eu; return 0; }
r[4]=0x00000002u;
goto P_0c0c5d30;
P_0c0c5d30: /* original 65c3, guest PC 0x0c0c5d30 */
if(!s->budget--) { s->failed_pc=0x0c0c5d30u; return 0; }
r[5]=r[12];
goto P_0c0c5d32;
P_0c0c5d32: /* original e600, guest PC 0x0c0c5d32 */
if(!s->budget--) { s->failed_pc=0x0c0c5d32u; return 0; }
r[6]=0x00000000u;
goto P_0c0c5d34;
P_0c0c5d34: /* original a00a, guest PC 0x0c0c5d34 */
if(!s->budget--) { s->failed_pc=0x0c0c5d34u; return 0; }
r[4]=0x00000003u;
goto P_0c0c5d4c;
P_0c0c5d36: /* original e403, guest PC 0x0c0c5d36 */
if(!s->budget--) { s->failed_pc=0x0c0c5d36u; return 0; }
r[4]=0x00000003u;
goto P_0c0c5d38;
P_0c0c5d38: /* original d135, guest PC 0x0c0c5d38 */
if(!s->budget--) { s->failed_pc=0x0c0c5d38u; return 0; }
r[1]=read(ram,0x0c0c5e10u,4);
goto P_0c0c5d3a;
P_0c0c5d3a: /* original 3d10, guest PC 0x0c0c5d3a */
if(!s->budget--) { s->failed_pc=0x0c0c5d3au; return 0; }
r[17]=(r[17]&~1u)|((r[13]==r[1])!=0);
goto P_0c0c5d3c;
P_0c0c5d3c: /* original 8b18, guest PC 0x0c0c5d3c */
if(!s->budget--) { s->failed_pc=0x0c0c5d3cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c5d70; }
goto P_0c0c5d3e;
P_0c0c5d3e: /* original 65c3, guest PC 0x0c0c5d3e */
if(!s->budget--) { s->failed_pc=0x0c0c5d3eu; return 0; }
r[5]=r[12];
goto P_0c0c5d40;
P_0c0c5d40: /* original e600, guest PC 0x0c0c5d40 */
if(!s->budget--) { s->failed_pc=0x0c0c5d40u; return 0; }
r[6]=0x00000000u;
goto P_0c0c5d42;
P_0c0c5d42: /* original 4e0b, guest PC 0x0c0c5d42 */
if(!s->budget--) { s->failed_pc=0x0c0c5d42u; return 0; }
target=r[14];
r[16]=code_base|0x0c0c5d46u;
r[4]=0x00000001u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c5d46u) { target=s->pc; goto dispatch; }
goto P_0c0c5d46;
P_0c0c5d44: /* original e401, guest PC 0x0c0c5d44 */
if(!s->budget--) { s->failed_pc=0x0c0c5d44u; return 0; }
r[4]=0x00000001u;
goto P_0c0c5d46;
P_0c0c5d46: /* original e402, guest PC 0x0c0c5d46 */
if(!s->budget--) { s->failed_pc=0x0c0c5d46u; return 0; }
r[4]=0x00000002u;
goto P_0c0c5d48;
P_0c0c5d48: /* original 65c3, guest PC 0x0c0c5d48 */
if(!s->budget--) { s->failed_pc=0x0c0c5d48u; return 0; }
r[5]=r[12];
goto P_0c0c5d4a;
P_0c0c5d4a: /* original e600, guest PC 0x0c0c5d4a */
if(!s->budget--) { s->failed_pc=0x0c0c5d4au; return 0; }
r[6]=0x00000000u;
goto P_0c0c5d4c;
P_0c0c5d4c: /* original 4e0b, guest PC 0x0c0c5d4c */
if(!s->budget--) { s->failed_pc=0x0c0c5d4cu; return 0; }
target=r[14];
r[16]=code_base|0x0c0c5d50u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c5d50u) { target=s->pc; goto dispatch; }
goto P_0c0c5d50;
P_0c0c5d4e: /* original 0009, guest PC 0x0c0c5d4e */
if(!s->budget--) { s->failed_pc=0x0c0c5d4eu; return 0; }
goto P_0c0c5d50;
P_0c0c5d50: /* original 65c3, guest PC 0x0c0c5d50 */
if(!s->budget--) { s->failed_pc=0x0c0c5d50u; return 0; }
r[5]=r[12];
goto P_0c0c5d52;
P_0c0c5d52: /* original e600, guest PC 0x0c0c5d52 */
if(!s->budget--) { s->failed_pc=0x0c0c5d52u; return 0; }
r[6]=0x00000000u;
goto P_0c0c5d54;
P_0c0c5d54: /* original 4e0b, guest PC 0x0c0c5d54 */
if(!s->budget--) { s->failed_pc=0x0c0c5d54u; return 0; }
target=r[14];
r[16]=code_base|0x0c0c5d58u;
r[4]=0x00000004u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c5d58u) { target=s->pc; goto dispatch; }
goto P_0c0c5d58;
P_0c0c5d56: /* original e404, guest PC 0x0c0c5d56 */
if(!s->budget--) { s->failed_pc=0x0c0c5d56u; return 0; }
r[4]=0x00000004u;
goto P_0c0c5d58;
P_0c0c5d58: /* original 65c3, guest PC 0x0c0c5d58 */
if(!s->budget--) { s->failed_pc=0x0c0c5d58u; return 0; }
r[5]=r[12];
goto P_0c0c5d5a;
P_0c0c5d5a: /* original e600, guest PC 0x0c0c5d5a */
if(!s->budget--) { s->failed_pc=0x0c0c5d5au; return 0; }
r[6]=0x00000000u;
goto P_0c0c5d5c;
P_0c0c5d5c: /* original 4e0b, guest PC 0x0c0c5d5c */
if(!s->budget--) { s->failed_pc=0x0c0c5d5cu; return 0; }
target=r[14];
r[16]=code_base|0x0c0c5d60u;
r[4]=0x00000005u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c5d60u) { target=s->pc; goto dispatch; }
goto P_0c0c5d60;
P_0c0c5d5e: /* original e405, guest PC 0x0c0c5d5e */
if(!s->budget--) { s->failed_pc=0x0c0c5d5eu; return 0; }
r[4]=0x00000005u;
goto P_0c0c5d60;
P_0c0c5d60: /* original 65c3, guest PC 0x0c0c5d60 */
if(!s->budget--) { s->failed_pc=0x0c0c5d60u; return 0; }
r[5]=r[12];
goto P_0c0c5d62;
P_0c0c5d62: /* original e600, guest PC 0x0c0c5d62 */
if(!s->budget--) { s->failed_pc=0x0c0c5d62u; return 0; }
r[6]=0x00000000u;
goto P_0c0c5d64;
P_0c0c5d64: /* original 4e0b, guest PC 0x0c0c5d64 */
if(!s->budget--) { s->failed_pc=0x0c0c5d64u; return 0; }
target=r[14];
r[16]=code_base|0x0c0c5d68u;
r[4]=0x00000006u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c5d68u) { target=s->pc; goto dispatch; }
goto P_0c0c5d68;
P_0c0c5d66: /* original e406, guest PC 0x0c0c5d66 */
if(!s->budget--) { s->failed_pc=0x0c0c5d66u; return 0; }
r[4]=0x00000006u;
goto P_0c0c5d68;
P_0c0c5d68: /* original 65c3, guest PC 0x0c0c5d68 */
if(!s->budget--) { s->failed_pc=0x0c0c5d68u; return 0; }
r[5]=r[12];
goto P_0c0c5d6a;
P_0c0c5d6a: /* original e600, guest PC 0x0c0c5d6a */
if(!s->budget--) { s->failed_pc=0x0c0c5d6au; return 0; }
r[6]=0x00000000u;
goto P_0c0c5d6c;
P_0c0c5d6c: /* original a003, guest PC 0x0c0c5d6c */
if(!s->budget--) { s->failed_pc=0x0c0c5d6cu; return 0; }
r[4]=0x00000007u;
goto P_0c0c5d76;
P_0c0c5d6e: /* original e407, guest PC 0x0c0c5d6e */
if(!s->budget--) { s->failed_pc=0x0c0c5d6eu; return 0; }
r[4]=0x00000007u;
goto P_0c0c5d70;
P_0c0c5d70: /* original e400, guest PC 0x0c0c5d70 */
if(!s->budget--) { s->failed_pc=0x0c0c5d70u; return 0; }
r[4]=0x00000000u;
goto P_0c0c5d72;
P_0c0c5d72: /* original 65d3, guest PC 0x0c0c5d72 */
if(!s->budget--) { s->failed_pc=0x0c0c5d72u; return 0; }
r[5]=r[13];
goto P_0c0c5d74;
P_0c0c5d74: /* original 66b3, guest PC 0x0c0c5d74 */
if(!s->budget--) { s->failed_pc=0x0c0c5d74u; return 0; }
r[6]=r[11];
goto P_0c0c5d76;
P_0c0c5d76: /* original 4e0b, guest PC 0x0c0c5d76 */
if(!s->budget--) { s->failed_pc=0x0c0c5d76u; return 0; }
target=r[14];
r[16]=code_base|0x0c0c5d7au;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c5d7au) { target=s->pc; goto dispatch; }
goto P_0c0c5d7a;
P_0c0c5d78: /* original 0009, guest PC 0x0c0c5d78 */
if(!s->budget--) { s->failed_pc=0x0c0c5d78u; return 0; }
goto P_0c0c5d7a;
P_0c0c5d7a: /* original 4f26, guest PC 0x0c0c5d7a */
if(!s->budget--) { s->failed_pc=0x0c0c5d7au; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0c5d7c;
P_0c0c5d7c: /* original 6bf6, guest PC 0x0c0c5d7c */
if(!s->budget--) { s->failed_pc=0x0c0c5d7cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0c5d7e;
P_0c0c5d7e: /* original 6cf6, guest PC 0x0c0c5d7e */
if(!s->budget--) { s->failed_pc=0x0c0c5d7eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0c5d80;
P_0c0c5d80: /* original 6df6, guest PC 0x0c0c5d80 */
if(!s->budget--) { s->failed_pc=0x0c0c5d80u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0c5d82;
P_0c0c5d82: /* original 000b, guest PC 0x0c0c5d82 */
if(!s->budget--) { s->failed_pc=0x0c0c5d82u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0c5d84: /* original 6ef6, guest PC 0x0c0c5d84 */
if(!s->budget--) { s->failed_pc=0x0c0c5d84u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0c5d86;
P_0c0c5d86: /* original 4f22, guest PC 0x0c0c5d86 */
if(!s->budget--) { s->failed_pc=0x0c0c5d86u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0c5d88;
P_0c0c5d88: /* original 7ff8, guest PC 0x0c0c5d88 */
if(!s->budget--) { s->failed_pc=0x0c0c5d88u; return 0; }
r[15]+=0xfffffff8u;
goto P_0c0c5d8a;
P_0c0c5d8a: /* original 2f42, guest PC 0x0c0c5d8a */
if(!s->budget--) { s->failed_pc=0x0c0c5d8au; return 0; }
write(ram,r[15],r[4],4);
goto P_0c0c5d8c;
P_0c0c5d8c: /* original d421, guest PC 0x0c0c5d8c */
if(!s->budget--) { s->failed_pc=0x0c0c5d8cu; return 0; }
r[4]=read(ram,0x0c0c5e14u,4);
goto P_0c0c5d8e;
P_0c0c5d8e: /* original d322, guest PC 0x0c0c5d8e */
if(!s->budget--) { s->failed_pc=0x0c0c5d8eu; return 0; }
r[3]=read(ram,0x0c0c5e18u,4);
goto P_0c0c5d90;
P_0c0c5d90: /* original 1f31, guest PC 0x0c0c5d90 */
if(!s->budget--) { s->failed_pc=0x0c0c5d90u; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c0c5d92;
P_0c0c5d92: /* original 8448, guest PC 0x0c0c5d92 */
if(!s->budget--) { s->failed_pc=0x0c0c5d92u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+8,1);
goto P_0c0c5d94;
P_0c0c5d94: /* original 600c, guest PC 0x0c0c5d94 */
if(!s->budget--) { s->failed_pc=0x0c0c5d94u; return 0; }
r[0]=r[0]&255u;
goto P_0c0c5d96;
P_0c0c5d96: /* original 8803, guest PC 0x0c0c5d96 */
if(!s->budget--) { s->failed_pc=0x0c0c5d96u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000003u)!=0);
goto P_0c0c5d98;
P_0c0c5d98: /* original 8f07, guest PC 0x0c0c5d98 */
if(!s->budget--) { s->failed_pc=0x0c0c5d98u; return 0; }
cond=r[17]&1u;
r[4]=r[0];
if(!cond) { goto P_0c0c5daa; }
goto P_0c0c5d9c;
P_0c0c5d9a: /* original 6403, guest PC 0x0c0c5d9a */
if(!s->budget--) { s->failed_pc=0x0c0c5d9au; return 0; }
r[4]=r[0];
goto P_0c0c5d9c;
P_0c0c5d9c: /* original d31f, guest PC 0x0c0c5d9c */
if(!s->budget--) { s->failed_pc=0x0c0c5d9cu; return 0; }
r[3]=read(ram,0x0c0c5e1cu,4);
goto P_0c0c5d9e;
P_0c0c5d9e: /* original 54f1, guest PC 0x0c0c5d9e */
if(!s->budget--) { s->failed_pc=0x0c0c5d9eu; return 0; }
r[4]=read(ram,r[15]+4,4);
goto P_0c0c5da0;
P_0c0c5da0: /* original 430b, guest PC 0x0c0c5da0 */
if(!s->budget--) { s->failed_pc=0x0c0c5da0u; return 0; }
target=r[3];
r[16]=code_base|0x0c0c5da4u;
r[4]+=0x00000003u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c5da4u) { target=s->pc; goto dispatch; }
goto P_0c0c5da4;
P_0c0c5da2: /* original 7403, guest PC 0x0c0c5da2 */
if(!s->budget--) { s->failed_pc=0x0c0c5da2u; return 0; }
r[4]+=0x00000003u;
goto P_0c0c5da4;
P_0c0c5da4: /* original 640c, guest PC 0x0c0c5da4 */
if(!s->budget--) { s->failed_pc=0x0c0c5da4u; return 0; }
r[4]=r[0]&255u;
goto P_0c0c5da6;
P_0c0c5da6: /* original 2448, guest PC 0x0c0c5da6 */
if(!s->budget--) { s->failed_pc=0x0c0c5da6u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c0c5da8;
P_0c0c5da8: /* original 8b03, guest PC 0x0c0c5da8 */
if(!s->budget--) { s->failed_pc=0x0c0c5da8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c5db2; }
goto P_0c0c5daa;
P_0c0c5daa: /* original 64f2, guest PC 0x0c0c5daa */
if(!s->budget--) { s->failed_pc=0x0c0c5daau; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c0c5dac;
P_0c0c5dac: /* original 7f08, guest PC 0x0c0c5dac */
if(!s->budget--) { s->failed_pc=0x0c0c5dacu; return 0; }
r[15]+=0x00000008u;
goto P_0c0c5dae;
P_0c0c5dae: /* original a004, guest PC 0x0c0c5dae */
if(!s->budget--) { s->failed_pc=0x0c0c5daeu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
return vf3_matrix_family(0x0c0c5dbau,s,ram);
P_0c0c5db0: /* original 4f26, guest PC 0x0c0c5db0 */
if(!s->budget--) { s->failed_pc=0x0c0c5db0u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0c5db2;
P_0c0c5db2: /* original 7f08, guest PC 0x0c0c5db2 */
if(!s->budget--) { s->failed_pc=0x0c0c5db2u; return 0; }
r[15]+=0x00000008u;
goto P_0c0c5db4;
P_0c0c5db4: /* original 4f26, guest PC 0x0c0c5db4 */
if(!s->budget--) { s->failed_pc=0x0c0c5db4u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0c5db6;
P_0c0c5db6: /* original 000b, guest PC 0x0c0c5db6 */
if(!s->budget--) { s->failed_pc=0x0c0c5db6u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c0c5db8: /* original 0009, guest PC 0x0c0c5db8 */
if(!s->budget--) { s->failed_pc=0x0c0c5db8u; return 0; }
return vf3_matrix_family(0x0c0c5dbau,s,ram);
unsupported: s->failed_pc=target; return 0;
}
