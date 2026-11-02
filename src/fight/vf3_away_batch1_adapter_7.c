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
int vf3_away_batch1_adapter_7(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c036db8u: goto P_0c036db8;
case 0x0c036dbau: goto P_0c036dba;
case 0x0c036dbcu: goto P_0c036dbc;
case 0x0c036dbeu: goto P_0c036dbe;
case 0x0c036dc0u: goto P_0c036dc0;
case 0x0c036dc2u: goto P_0c036dc2;
case 0x0c036dc4u: goto P_0c036dc4;
case 0x0c036dc6u: goto P_0c036dc6;
case 0x0c036dc8u: goto P_0c036dc8;
case 0x0c036fdcu: goto P_0c036fdc;
case 0x0c036fdeu: goto P_0c036fde;
case 0x0c036fe0u: goto P_0c036fe0;
case 0x0c036fe2u: goto P_0c036fe2;
case 0x0c036fe4u: goto P_0c036fe4;
case 0x0c036fe6u: goto P_0c036fe6;
case 0x0c036fe8u: goto P_0c036fe8;
case 0x0c036feau: goto P_0c036fea;
case 0x0c036fecu: goto P_0c036fec;
case 0x0c036feeu: goto P_0c036fee;
case 0x0c036ff0u: goto P_0c036ff0;
case 0x0c036ff2u: goto P_0c036ff2;
case 0x0c036ff4u: goto P_0c036ff4;
case 0x0c036ff6u: goto P_0c036ff6;
case 0x0c036ff8u: goto P_0c036ff8;
case 0x0c036ffau: goto P_0c036ffa;
case 0x0c036ffcu: goto P_0c036ffc;
case 0x0c036ffeu: goto P_0c036ffe;
case 0x0c037000u: goto P_0c037000;
case 0x0c037002u: goto P_0c037002;
case 0x0c03709cu: goto P_0c03709c;
case 0x0c03709eu: goto P_0c03709e;
case 0x0c0370a0u: goto P_0c0370a0;
case 0x0c0370a2u: goto P_0c0370a2;
case 0x0c0370a4u: goto P_0c0370a4;
case 0x0c0370a6u: goto P_0c0370a6;
case 0x0c0370a8u: goto P_0c0370a8;
case 0x0c0370aau: goto P_0c0370aa;
case 0x0c0370acu: goto P_0c0370ac;
case 0x0c0370aeu: goto P_0c0370ae;
case 0x0c0370b0u: goto P_0c0370b0;
case 0x0c0370b2u: goto P_0c0370b2;
case 0x0c0370b4u: goto P_0c0370b4;
case 0x0c0370b6u: goto P_0c0370b6;
case 0x0c0370b8u: goto P_0c0370b8;
case 0x0c0370bau: goto P_0c0370ba;
case 0x0c0370bcu: goto P_0c0370bc;
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
case 0x0c043500u: goto P_0c043500;
case 0x0c043502u: goto P_0c043502;
case 0x0c043504u: goto P_0c043504;
case 0x0c043506u: goto P_0c043506;
case 0x0c043508u: goto P_0c043508;
case 0x0c04350au: goto P_0c04350a;
case 0x0c04350cu: goto P_0c04350c;
case 0x0c04350eu: goto P_0c04350e;
case 0x0c043510u: goto P_0c043510;
case 0x0c043512u: goto P_0c043512;
case 0x0c043514u: goto P_0c043514;
case 0x0c043516u: goto P_0c043516;
case 0x0c043518u: goto P_0c043518;
case 0x0c04351au: goto P_0c04351a;
case 0x0c04351cu: goto P_0c04351c;
case 0x0c04351eu: goto P_0c04351e;
case 0x0c043520u: goto P_0c043520;
case 0x0c043522u: goto P_0c043522;
case 0x0c043524u: goto P_0c043524;
case 0x0c043526u: goto P_0c043526;
case 0x0c043528u: goto P_0c043528;
case 0x0c04352au: goto P_0c04352a;
case 0x0c04352cu: goto P_0c04352c;
case 0x0c04352eu: goto P_0c04352e;
case 0x0c043530u: goto P_0c043530;
case 0x0c043532u: goto P_0c043532;
case 0x0c043534u: goto P_0c043534;
case 0x0c043536u: goto P_0c043536;
case 0x0c043538u: goto P_0c043538;
case 0x0c04353au: goto P_0c04353a;
case 0x0c04353cu: goto P_0c04353c;
case 0x0c04353eu: goto P_0c04353e;
case 0x0c043540u: goto P_0c043540;
case 0x0c043542u: goto P_0c043542;
case 0x0c043544u: goto P_0c043544;
case 0x0c043546u: goto P_0c043546;
case 0x0c043548u: goto P_0c043548;
case 0x0c04354au: goto P_0c04354a;
case 0x0c04354cu: goto P_0c04354c;
case 0x0c04354eu: goto P_0c04354e;
case 0x0c043550u: goto P_0c043550;
case 0x0c043552u: goto P_0c043552;
case 0x0c043554u: goto P_0c043554;
case 0x0c043556u: goto P_0c043556;
case 0x0c043558u: goto P_0c043558;
case 0x0c04355au: goto P_0c04355a;
case 0x0c04355cu: goto P_0c04355c;
case 0x0c04355eu: goto P_0c04355e;
case 0x0c043560u: goto P_0c043560;
case 0x0c043562u: goto P_0c043562;
case 0x0c043564u: goto P_0c043564;
case 0x0c043566u: goto P_0c043566;
case 0x0c043568u: goto P_0c043568;
case 0x0c04356au: goto P_0c04356a;
case 0x0c04356cu: goto P_0c04356c;
case 0x0c0435dau: goto P_0c0435da;
case 0x0c0435dcu: goto P_0c0435dc;
case 0x0c0435deu: goto P_0c0435de;
case 0x0c0435e0u: goto P_0c0435e0;
case 0x0c0435e2u: goto P_0c0435e2;
case 0x0c0435e4u: goto P_0c0435e4;
case 0x0c0435e6u: goto P_0c0435e6;
case 0x0c0435e8u: goto P_0c0435e8;
case 0x0c0435eau: goto P_0c0435ea;
case 0x0c0435ecu: goto P_0c0435ec;
case 0x0c0435eeu: goto P_0c0435ee;
case 0x0c0435f0u: goto P_0c0435f0;
case 0x0c0435f2u: goto P_0c0435f2;
case 0x0c0435f4u: goto P_0c0435f4;
case 0x0c0435f6u: goto P_0c0435f6;
case 0x0c0435f8u: goto P_0c0435f8;
case 0x0c0435fau: goto P_0c0435fa;
case 0x0c0435fcu: goto P_0c0435fc;
case 0x0c0435feu: goto P_0c0435fe;
case 0x0c043600u: goto P_0c043600;
case 0x0c043602u: goto P_0c043602;
case 0x0c043604u: goto P_0c043604;
case 0x0c043606u: goto P_0c043606;
case 0x0c043608u: goto P_0c043608;
default: return vf3_matrix_family(target,s,ram);
}
P_0c036db8: /* original e034, guest PC 0x0c036db8 */
if(!s->budget--) { s->failed_pc=0x0c036db8u; return 0; }
r[0]=0x00000034u;
goto P_0c036dba;
P_0c036dba: /* original d327, guest PC 0x0c036dba */
if(!s->budget--) { s->failed_pc=0x0c036dbau; return 0; }
r[3]=read(ram,0x0c036e58u,4);
goto P_0c036dbc;
P_0c036dbc: /* original 4f12, guest PC 0x0c036dbc */
if(!s->budget--) { s->failed_pc=0x0c036dbcu; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c036dbe;
P_0c036dbe: /* original 240f, guest PC 0x0c036dbe */
if(!s->budget--) { s->failed_pc=0x0c036dbeu; return 0; }
r[19]=(uint32_t)((int32_t)(int16_t)r[4]*(int32_t)(int16_t)r[0]);
goto P_0c036dc0;
P_0c036dc0: /* original 001a, guest PC 0x0c036dc0 */
if(!s->budget--) { s->failed_pc=0x0c036dc0u; return 0; }
r[0]=r[19];
goto P_0c036dc2;
P_0c036dc2: /* original 600f, guest PC 0x0c036dc2 */
if(!s->budget--) { s->failed_pc=0x0c036dc2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)r[0];
goto P_0c036dc4;
P_0c036dc4: /* original 303c, guest PC 0x0c036dc4 */
if(!s->budget--) { s->failed_pc=0x0c036dc4u; return 0; }
r[0]+=r[3];
goto P_0c036dc6;
P_0c036dc6: /* original 000b, guest PC 0x0c036dc6 */
if(!s->budget--) { s->failed_pc=0x0c036dc6u; return 0; }
target=r[16];
r[19]=read(ram,r[15],4); r[15]+=4;
s->pc=target; return ram->oob==0;
P_0c036dc8: /* original 4f16, guest PC 0x0c036dc8 */
if(!s->budget--) { s->failed_pc=0x0c036dc8u; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
if(!vf3_matrix_family(0x0c036dcau,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c036dcau; return 0; } return 1;
P_0c036fdc: /* original 2fe6, guest PC 0x0c036fdc */
if(!s->budget--) { s->failed_pc=0x0c036fdcu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c036fde;
P_0c036fde: /* original ee00, guest PC 0x0c036fde */
if(!s->budget--) { s->failed_pc=0x0c036fdeu; return 0; }
r[14]=0x00000000u;
goto P_0c036fe0;
P_0c036fe0: /* original 2fd6, guest PC 0x0c036fe0 */
if(!s->budget--) { s->failed_pc=0x0c036fe0u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c036fe2;
P_0c036fe2: /* original 63e3, guest PC 0x0c036fe2 */
if(!s->budget--) { s->failed_pc=0x0c036fe2u; return 0; }
r[3]=r[14];
goto P_0c036fe4;
P_0c036fe4: /* original 2fc6, guest PC 0x0c036fe4 */
if(!s->budget--) { s->failed_pc=0x0c036fe4u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c036fe6;
P_0c036fe6: /* original 6c53, guest PC 0x0c036fe6 */
if(!s->budget--) { s->failed_pc=0x0c036fe6u; return 0; }
r[12]=r[5];
goto P_0c036fe8;
P_0c036fe8: /* original 33c2, guest PC 0x0c036fe8 */
if(!s->budget--) { s->failed_pc=0x0c036fe8u; return 0; }
r[17]=(r[17]&~1u)|((r[3]>=r[12])!=0);
goto P_0c036fea;
P_0c036fea: /* original 8d07, guest PC 0x0c036fea */
if(!s->budget--) { s->failed_pc=0x0c036feau; return 0; }
cond=r[17]&1u;
r[13]=r[4];
if(cond) { goto P_0c036ffc; }
goto P_0c036fee;
P_0c036fec: /* original 6d43, guest PC 0x0c036fec */
if(!s->budget--) { s->failed_pc=0x0c036fecu; return 0; }
r[13]=r[4];
goto P_0c036fee;
P_0c036fee: /* original 64d3, guest PC 0x0c036fee */
if(!s->budget--) { s->failed_pc=0x0c036feeu; return 0; }
r[4]=r[13];
goto P_0c036ff0;
P_0c036ff0: /* original 04a3, guest PC 0x0c036ff0 */
if(!s->budget--) { s->failed_pc=0x0c036ff0u; return 0; }
goto P_0c036ff2;
P_0c036ff2: /* original 0009, guest PC 0x0c036ff2 */
if(!s->budget--) { s->failed_pc=0x0c036ff2u; return 0; }
goto P_0c036ff4;
P_0c036ff4: /* original 7e01, guest PC 0x0c036ff4 */
if(!s->budget--) { s->failed_pc=0x0c036ff4u; return 0; }
r[14]+=0x00000001u;
goto P_0c036ff6;
P_0c036ff6: /* original 3ec2, guest PC 0x0c036ff6 */
if(!s->budget--) { s->failed_pc=0x0c036ff6u; return 0; }
r[17]=(r[17]&~1u)|((r[14]>=r[12])!=0);
goto P_0c036ff8;
P_0c036ff8: /* original 8ff9, guest PC 0x0c036ff8 */
if(!s->budget--) { s->failed_pc=0x0c036ff8u; return 0; }
cond=r[17]&1u;
r[13]+=0x00000020u;
if(!cond) { goto P_0c036fee; }
goto P_0c036ffc;
P_0c036ffa: /* original 7d20, guest PC 0x0c036ffa */
if(!s->budget--) { s->failed_pc=0x0c036ffau; return 0; }
r[13]+=0x00000020u;
goto P_0c036ffc;
P_0c036ffc: /* original 6cf6, guest PC 0x0c036ffc */
if(!s->budget--) { s->failed_pc=0x0c036ffcu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c036ffe;
P_0c036ffe: /* original 6df6, guest PC 0x0c036ffe */
if(!s->budget--) { s->failed_pc=0x0c036ffeu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c037000;
P_0c037000: /* original 000b, guest PC 0x0c037000 */
if(!s->budget--) { s->failed_pc=0x0c037000u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c037002: /* original 6ef6, guest PC 0x0c037002 */
if(!s->budget--) { s->failed_pc=0x0c037002u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c037004u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c037004u; return 0; } return 1;
P_0c03709c: /* original 0602, guest PC 0x0c03709c */
if(!s->budget--) { s->failed_pc=0x0c03709cu; return 0; }
r[6]=r[17];
goto P_0c03709e;
P_0c03709e: /* original 931d, guest PC 0x0c03709e */
if(!s->budget--) { s->failed_pc=0x0c03709eu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0370dcu,2);
goto P_0c0370a0;
P_0c0370a0: /* original 236b, guest PC 0x0c0370a0 */
if(!s->budget--) { s->failed_pc=0x0c0370a0u; return 0; }
r[3]|=r[6];
goto P_0c0370a2;
P_0c0370a2: /* original 430e, guest PC 0x0c0370a2 */
if(!s->budget--) { s->failed_pc=0x0c0370a2u; return 0; }
r[17]=r[3];
goto P_0c0370a4;
P_0c0370a4: /* original 931b, guest PC 0x0c0370a4 */
if(!s->budget--) { s->failed_pc=0x0c0370a4u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0370deu,2);
goto P_0c0370a6;
P_0c0370a6: /* original 0222, guest PC 0x0c0370a6 */
if(!s->budget--) { s->failed_pc=0x0c0370a6u; return 0; }
r[2]=0x0c00f400u;
goto P_0c0370a8;
P_0c0370a8: /* original 343c, guest PC 0x0c0370a8 */
if(!s->budget--) { s->failed_pc=0x0c0370a8u; return 0; }
r[4]+=r[3];
goto P_0c0370aa;
P_0c0370aa: /* original 4409, guest PC 0x0c0370aa */
if(!s->budget--) { s->failed_pc=0x0c0370aau; return 0; }
r[4]>>=2;
goto P_0c0370ac;
P_0c0370ac: /* original 4401, guest PC 0x0c0370ac */
if(!s->budget--) { s->failed_pc=0x0c0370acu; return 0; }
r[17]=(r[17]&~1u)|((r[4]&1)!=0);
r[4]>>=1;
goto P_0c0370ae;
P_0c0370ae: /* original 324c, guest PC 0x0c0370ae */
if(!s->budget--) { s->failed_pc=0x0c0370aeu; return 0; }
r[2]+=r[4];
goto P_0c0370b0;
P_0c0370b0: /* original 9416, guest PC 0x0c0370b0 */
if(!s->budget--) { s->failed_pc=0x0c0370b0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0370e0u,2);
goto P_0c0370b2;
P_0c0370b2: /* original 342c, guest PC 0x0c0370b2 */
if(!s->budget--) { s->failed_pc=0x0c0370b2u; return 0; }
r[4]+=r[2];
goto P_0c0370b4;
P_0c0370b4: /* original 6042, guest PC 0x0c0370b4 */
if(!s->budget--) { s->failed_pc=0x0c0370b4u; return 0; }
tmp=read(ram,r[4],4);
r[0]=tmp;
goto P_0c0370b6;
P_0c0370b6: /* original 2452, guest PC 0x0c0370b6 */
if(!s->budget--) { s->failed_pc=0x0c0370b6u; return 0; }
write(ram,r[4],r[5],4);
goto P_0c0370b8;
P_0c0370b8: /* original 460e, guest PC 0x0c0370b8 */
if(!s->budget--) { s->failed_pc=0x0c0370b8u; return 0; }
r[17]=r[6];
goto P_0c0370ba;
P_0c0370ba: /* original 000b, guest PC 0x0c0370ba */
if(!s->budget--) { s->failed_pc=0x0c0370bau; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c0370bc: /* original 0009, guest PC 0x0c0370bc */
if(!s->budget--) { s->failed_pc=0x0c0370bcu; return 0; }
if(!vf3_matrix_family(0x0c0370beu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0370beu; return 0; } return 1;
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
P_0c043500: /* original 4615, guest PC 0x0c043500 */
if(!s->budget--) { s->failed_pc=0x0c043500u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[6]>0)!=0);
goto P_0c043502;
P_0c043502: /* original 6743, guest PC 0x0c043502 */
if(!s->budget--) { s->failed_pc=0x0c043502u; return 0; }
r[7]=r[4];
goto P_0c043504;
P_0c043504: /* original 8f06, guest PC 0x0c043504 */
if(!s->budget--) { s->failed_pc=0x0c043504u; return 0; }
cond=r[17]&1u;
r[4]=r[5];
if(!cond) { goto P_0c043514; }
goto P_0c043508;
P_0c043506: /* original 6453, guest PC 0x0c043506 */
if(!s->budget--) { s->failed_pc=0x0c043506u; return 0; }
r[4]=r[5];
goto P_0c043508;
P_0c043508: /* original 6374, guest PC 0x0c043508 */
if(!s->budget--) { s->failed_pc=0x0c043508u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[7],1);
r[7]+=1;
r[3]=tmp;
goto P_0c04350a;
P_0c04350a: /* original 76ff, guest PC 0x0c04350a */
if(!s->budget--) { s->failed_pc=0x0c04350au; return 0; }
r[6]+=0xffffffffu;
goto P_0c04350c;
P_0c04350c: /* original 4615, guest PC 0x0c04350c */
if(!s->budget--) { s->failed_pc=0x0c04350cu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[6]>0)!=0);
goto P_0c04350e;
P_0c04350e: /* original 2430, guest PC 0x0c04350e */
if(!s->budget--) { s->failed_pc=0x0c04350eu; return 0; }
write(ram,r[4],r[3],1);
goto P_0c043510;
P_0c043510: /* original 8dfa, guest PC 0x0c043510 */
if(!s->budget--) { s->failed_pc=0x0c043510u; return 0; }
cond=r[17]&1u;
r[4]+=0x00000001u;
if(cond) { goto P_0c043508; }
goto P_0c043514;
P_0c043512: /* original 7401, guest PC 0x0c043512 */
if(!s->budget--) { s->failed_pc=0x0c043512u; return 0; }
r[4]+=0x00000001u;
goto P_0c043514;
P_0c043514: /* original 000b, guest PC 0x0c043514 */
if(!s->budget--) { s->failed_pc=0x0c043514u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c043516: /* original 0009, guest PC 0x0c043516 */
if(!s->budget--) { s->failed_pc=0x0c043516u; return 0; }
goto P_0c043518;
P_0c043518: /* original 2fe6, guest PC 0x0c043518 */
if(!s->budget--) { s->failed_pc=0x0c043518u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04351a;
P_0c04351a: /* original a023, guest PC 0x0c04351a */
if(!s->budget--) { s->failed_pc=0x0c04351au; return 0; }
goto P_0c043564;
P_0c04351c: /* original 0009, guest PC 0x0c04351c */
if(!s->budget--) { s->failed_pc=0x0c04351cu; return 0; }
goto P_0c04351e;
P_0c04351e: /* original 6240, guest PC 0x0c04351e */
if(!s->budget--) { s->failed_pc=0x0c04351eu; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[4],1);
r[2]=tmp;
goto P_0c043520;
P_0c043520: /* original 2228, guest PC 0x0c043520 */
if(!s->budget--) { s->failed_pc=0x0c043520u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c043522;
P_0c043522: /* original 8918, guest PC 0x0c043522 */
if(!s->budget--) { s->failed_pc=0x0c043522u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c043556; }
goto P_0c043524;
P_0c043524: /* original 6744, guest PC 0x0c043524 */
if(!s->budget--) { s->failed_pc=0x0c043524u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[4],1);
r[4]+=1;
r[7]=tmp;
goto P_0c043526;
P_0c043526: /* original ee61, guest PC 0x0c043526 */
if(!s->budget--) { s->failed_pc=0x0c043526u; return 0; }
r[14]=0x00000061u;
goto P_0c043528;
P_0c043528: /* original 607e, guest PC 0x0c043528 */
if(!s->budget--) { s->failed_pc=0x0c043528u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)r[7];
goto P_0c04352a;
P_0c04352a: /* original 30e3, guest PC 0x0c04352a */
if(!s->budget--) { s->failed_pc=0x0c04352au; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[0]>=(int32_t)r[14])!=0);
goto P_0c04352c;
P_0c04352c: /* original 8b03, guest PC 0x0c04352c */
if(!s->budget--) { s->failed_pc=0x0c04352cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c043536; }
goto P_0c04352e;
P_0c04352e: /* original e27a, guest PC 0x0c04352e */
if(!s->budget--) { s->failed_pc=0x0c04352eu; return 0; }
r[2]=0x0000007au;
goto P_0c043530;
P_0c043530: /* original 3027, guest PC 0x0c043530 */
if(!s->budget--) { s->failed_pc=0x0c043530u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[0]>(int32_t)r[2])!=0);
goto P_0c043532;
P_0c043532: /* original 8900, guest PC 0x0c043532 */
if(!s->budget--) { s->failed_pc=0x0c043532u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c043536; }
goto P_0c043534;
P_0c043534: /* original 77e0, guest PC 0x0c043534 */
if(!s->budget--) { s->failed_pc=0x0c043534u; return 0; }
r[7]+=0xffffffe0u;
goto P_0c043536;
P_0c043536: /* original 6173, guest PC 0x0c043536 */
if(!s->budget--) { s->failed_pc=0x0c043536u; return 0; }
r[1]=r[7];
goto P_0c043538;
P_0c043538: /* original 6754, guest PC 0x0c043538 */
if(!s->budget--) { s->failed_pc=0x0c043538u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[5],1);
r[5]+=1;
r[7]=tmp;
goto P_0c04353a;
P_0c04353a: /* original 607e, guest PC 0x0c04353a */
if(!s->budget--) { s->failed_pc=0x0c04353au; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)r[7];
goto P_0c04353c;
P_0c04353c: /* original 30e3, guest PC 0x0c04353c */
if(!s->budget--) { s->failed_pc=0x0c04353cu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[0]>=(int32_t)r[14])!=0);
goto P_0c04353e;
P_0c04353e: /* original 8b03, guest PC 0x0c04353e */
if(!s->budget--) { s->failed_pc=0x0c04353eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c043548; }
goto P_0c043540;
P_0c043540: /* original e27a, guest PC 0x0c043540 */
if(!s->budget--) { s->failed_pc=0x0c043540u; return 0; }
r[2]=0x0000007au;
goto P_0c043542;
P_0c043542: /* original 3027, guest PC 0x0c043542 */
if(!s->budget--) { s->failed_pc=0x0c043542u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[0]>(int32_t)r[2])!=0);
goto P_0c043544;
P_0c043544: /* original 8900, guest PC 0x0c043544 */
if(!s->budget--) { s->failed_pc=0x0c043544u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c043548; }
goto P_0c043546;
P_0c043546: /* original 77e0, guest PC 0x0c043546 */
if(!s->budget--) { s->failed_pc=0x0c043546u; return 0; }
r[7]+=0xffffffe0u;
goto P_0c043548;
P_0c043548: /* original 6e73, guest PC 0x0c043548 */
if(!s->budget--) { s->failed_pc=0x0c043548u; return 0; }
r[14]=r[7];
goto P_0c04354a;
P_0c04354a: /* original 6eee, guest PC 0x0c04354a */
if(!s->budget--) { s->failed_pc=0x0c04354au; return 0; }
r[14]=(uint32_t)(int32_t)(int8_t)r[14];
goto P_0c04354c;
P_0c04354c: /* original 611e, guest PC 0x0c04354c */
if(!s->budget--) { s->failed_pc=0x0c04354cu; return 0; }
r[1]=(uint32_t)(int32_t)(int8_t)r[1];
goto P_0c04354e;
P_0c04354e: /* original 31e0, guest PC 0x0c04354e */
if(!s->budget--) { s->failed_pc=0x0c04354eu; return 0; }
r[17]=(r[17]&~1u)|((r[1]==r[14])!=0);
goto P_0c043550;
P_0c043550: /* original 8907, guest PC 0x0c043550 */
if(!s->budget--) { s->failed_pc=0x0c043550u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c043562; }
goto P_0c043552;
P_0c043552: /* original a003, guest PC 0x0c043552 */
if(!s->budget--) { s->failed_pc=0x0c043552u; return 0; }
goto P_0c04355c;
P_0c043554: /* original 0009, guest PC 0x0c043554 */
if(!s->budget--) { s->failed_pc=0x0c043554u; return 0; }
goto P_0c043556;
P_0c043556: /* original 6350, guest PC 0x0c043556 */
if(!s->budget--) { s->failed_pc=0x0c043556u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[5],1);
r[3]=tmp;
goto P_0c043558;
P_0c043558: /* original 2338, guest PC 0x0c043558 */
if(!s->budget--) { s->failed_pc=0x0c043558u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c04355a;
P_0c04355a: /* original 8905, guest PC 0x0c04355a */
if(!s->budget--) { s->failed_pc=0x0c04355au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c043568; }
goto P_0c04355c;
P_0c04355c: /* original e000, guest PC 0x0c04355c */
if(!s->budget--) { s->failed_pc=0x0c04355cu; return 0; }
r[0]=0x00000000u;
goto P_0c04355e;
P_0c04355e: /* original 000b, guest PC 0x0c04355e */
if(!s->budget--) { s->failed_pc=0x0c04355eu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c043560: /* original 6ef6, guest PC 0x0c043560 */
if(!s->budget--) { s->failed_pc=0x0c043560u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c043562;
P_0c043562: /* original 76ff, guest PC 0x0c043562 */
if(!s->budget--) { s->failed_pc=0x0c043562u; return 0; }
r[6]+=0xffffffffu;
goto P_0c043564;
P_0c043564: /* original 4615, guest PC 0x0c043564 */
if(!s->budget--) { s->failed_pc=0x0c043564u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[6]>0)!=0);
goto P_0c043566;
P_0c043566: /* original 89da, guest PC 0x0c043566 */
if(!s->budget--) { s->failed_pc=0x0c043566u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04351e; }
goto P_0c043568;
P_0c043568: /* original e001, guest PC 0x0c043568 */
if(!s->budget--) { s->failed_pc=0x0c043568u; return 0; }
r[0]=0x00000001u;
goto P_0c04356a;
P_0c04356a: /* original 000b, guest PC 0x0c04356a */
if(!s->budget--) { s->failed_pc=0x0c04356au; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c04356c: /* original 6ef6, guest PC 0x0c04356c */
if(!s->budget--) { s->failed_pc=0x0c04356cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c04356eu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c04356eu; return 0; } return 1;
P_0c0435da: /* original 6340, guest PC 0x0c0435da */
if(!s->budget--) { s->failed_pc=0x0c0435dau; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[4],1);
r[3]=tmp;
goto P_0c0435dc;
P_0c0435dc: /* original 2338, guest PC 0x0c0435dc */
if(!s->budget--) { s->failed_pc=0x0c0435dcu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c0435de;
P_0c0435de: /* original 8d11, guest PC 0x0c0435de */
if(!s->budget--) { s->failed_pc=0x0c0435deu; return 0; }
cond=r[17]&1u;
r[7]=0x00000000u;
if(cond) { goto P_0c043604; }
goto P_0c0435e2;
P_0c0435e0: /* original e700, guest PC 0x0c0435e0 */
if(!s->budget--) { s->failed_pc=0x0c0435e0u; return 0; }
r[7]=0x00000000u;
goto P_0c0435e2;
P_0c0435e2: /* original 6653, guest PC 0x0c0435e2 */
if(!s->budget--) { s->failed_pc=0x0c0435e2u; return 0; }
r[6]=r[5];
goto P_0c0435e4;
P_0c0435e4: /* original 6360, guest PC 0x0c0435e4 */
if(!s->budget--) { s->failed_pc=0x0c0435e4u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[6],1);
r[3]=tmp;
goto P_0c0435e6;
P_0c0435e6: /* original 2338, guest PC 0x0c0435e6 */
if(!s->budget--) { s->failed_pc=0x0c0435e6u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c0435e8;
P_0c0435e8: /* original 8907, guest PC 0x0c0435e8 */
if(!s->budget--) { s->failed_pc=0x0c0435e8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0435fa; }
goto P_0c0435ea;
P_0c0435ea: /* original 6360, guest PC 0x0c0435ea */
if(!s->budget--) { s->failed_pc=0x0c0435eau; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[6],1);
r[3]=tmp;
goto P_0c0435ec;
P_0c0435ec: /* original 6140, guest PC 0x0c0435ec */
if(!s->budget--) { s->failed_pc=0x0c0435ecu; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[4],1);
r[1]=tmp;
goto P_0c0435ee;
P_0c0435ee: /* original 3130, guest PC 0x0c0435ee */
if(!s->budget--) { s->failed_pc=0x0c0435eeu; return 0; }
r[17]=(r[17]&~1u)|((r[1]==r[3])!=0);
goto P_0c0435f0;
P_0c0435f0: /* original 8908, guest PC 0x0c0435f0 */
if(!s->budget--) { s->failed_pc=0x0c0435f0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c043604; }
goto P_0c0435f2;
P_0c0435f2: /* original 7601, guest PC 0x0c0435f2 */
if(!s->budget--) { s->failed_pc=0x0c0435f2u; return 0; }
r[6]+=0x00000001u;
goto P_0c0435f4;
P_0c0435f4: /* original 6360, guest PC 0x0c0435f4 */
if(!s->budget--) { s->failed_pc=0x0c0435f4u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[6],1);
r[3]=tmp;
goto P_0c0435f6;
P_0c0435f6: /* original 2338, guest PC 0x0c0435f6 */
if(!s->budget--) { s->failed_pc=0x0c0435f6u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c0435f8;
P_0c0435f8: /* original 8bf7, guest PC 0x0c0435f8 */
if(!s->budget--) { s->failed_pc=0x0c0435f8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0435ea; }
goto P_0c0435fa;
P_0c0435fa: /* original 7401, guest PC 0x0c0435fa */
if(!s->budget--) { s->failed_pc=0x0c0435fau; return 0; }
r[4]+=0x00000001u;
goto P_0c0435fc;
P_0c0435fc: /* original 6340, guest PC 0x0c0435fc */
if(!s->budget--) { s->failed_pc=0x0c0435fcu; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[4],1);
r[3]=tmp;
goto P_0c0435fe;
P_0c0435fe: /* original 2338, guest PC 0x0c0435fe */
if(!s->budget--) { s->failed_pc=0x0c0435feu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c043600;
P_0c043600: /* original 8fef, guest PC 0x0c043600 */
if(!s->budget--) { s->failed_pc=0x0c043600u; return 0; }
cond=r[17]&1u;
r[7]+=0x00000001u;
if(!cond) { goto P_0c0435e2; }
goto P_0c043604;
P_0c043602: /* original 7701, guest PC 0x0c043602 */
if(!s->budget--) { s->failed_pc=0x0c043602u; return 0; }
r[7]+=0x00000001u;
goto P_0c043604;
P_0c043604: /* original 6073, guest PC 0x0c043604 */
if(!s->budget--) { s->failed_pc=0x0c043604u; return 0; }
r[0]=r[7];
goto P_0c043606;
P_0c043606: /* original 000b, guest PC 0x0c043606 */
if(!s->budget--) { s->failed_pc=0x0c043606u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c043608: /* original 0009, guest PC 0x0c043608 */
if(!s->budget--) { s->failed_pc=0x0c043608u; return 0; }
return vf3_matrix_family(0x0c04360au,s,ram);
unsupported: s->failed_pc=target; return 0;
}
