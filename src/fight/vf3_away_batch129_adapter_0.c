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
int vf3_away_batch129_adapter_0(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c036794u: goto P_0c036794;
case 0x0c036796u: goto P_0c036796;
case 0x0c036798u: goto P_0c036798;
case 0x0c0368aau: goto P_0c0368aa;
case 0x0c0368acu: goto P_0c0368ac;
case 0x0c0368aeu: goto P_0c0368ae;
case 0x0c0368b0u: goto P_0c0368b0;
case 0x0c0368b2u: goto P_0c0368b2;
case 0x0c0368b4u: goto P_0c0368b4;
case 0x0c0368b6u: goto P_0c0368b6;
case 0x0c0368b8u: goto P_0c0368b8;
case 0x0c0368bau: goto P_0c0368ba;
case 0x0c0368bcu: goto P_0c0368bc;
case 0x0c0368beu: goto P_0c0368be;
case 0x0c0368c0u: goto P_0c0368c0;
case 0x0c0368c2u: goto P_0c0368c2;
case 0x0c0368c4u: goto P_0c0368c4;
case 0x0c0368c6u: goto P_0c0368c6;
case 0x0c0368c8u: goto P_0c0368c8;
case 0x0c0368cau: goto P_0c0368ca;
case 0x0c0368ccu: goto P_0c0368cc;
case 0x0c0368ceu: goto P_0c0368ce;
case 0x0c0368d0u: goto P_0c0368d0;
case 0x0c0368d2u: goto P_0c0368d2;
case 0x0c0368d4u: goto P_0c0368d4;
case 0x0c0368d6u: goto P_0c0368d6;
case 0x0c0368d8u: goto P_0c0368d8;
case 0x0c0368dau: goto P_0c0368da;
case 0x0c0368dcu: goto P_0c0368dc;
case 0x0c0368deu: goto P_0c0368de;
case 0x0c0368e0u: goto P_0c0368e0;
case 0x0c0368e2u: goto P_0c0368e2;
case 0x0c0368e4u: goto P_0c0368e4;
case 0x0c0368e6u: goto P_0c0368e6;
case 0x0c0368e8u: goto P_0c0368e8;
case 0x0c0368eau: goto P_0c0368ea;
case 0x0c0368ecu: goto P_0c0368ec;
case 0x0c0368eeu: goto P_0c0368ee;
case 0x0c0368f0u: goto P_0c0368f0;
case 0x0c0368f2u: goto P_0c0368f2;
case 0x0c0368f4u: goto P_0c0368f4;
case 0x0c0368f6u: goto P_0c0368f6;
case 0x0c0368f8u: goto P_0c0368f8;
case 0x0c0368fau: goto P_0c0368fa;
case 0x0c0368fcu: goto P_0c0368fc;
case 0x0c0368feu: goto P_0c0368fe;
case 0x0c036900u: goto P_0c036900;
case 0x0c036902u: goto P_0c036902;
case 0x0c036904u: goto P_0c036904;
case 0x0c036906u: goto P_0c036906;
case 0x0c036908u: goto P_0c036908;
case 0x0c03690au: goto P_0c03690a;
case 0x0c03690cu: goto P_0c03690c;
case 0x0c03690eu: goto P_0c03690e;
case 0x0c036910u: goto P_0c036910;
case 0x0c036912u: goto P_0c036912;
case 0x0c036914u: goto P_0c036914;
case 0x0c036916u: goto P_0c036916;
case 0x0c036918u: goto P_0c036918;
case 0x0c03691au: goto P_0c03691a;
case 0x0c03691cu: goto P_0c03691c;
case 0x0c03691eu: goto P_0c03691e;
case 0x0c036920u: goto P_0c036920;
case 0x0c036922u: goto P_0c036922;
case 0x0c036924u: goto P_0c036924;
case 0x0c036926u: goto P_0c036926;
case 0x0c036928u: goto P_0c036928;
case 0x0c03692au: goto P_0c03692a;
case 0x0c03692cu: goto P_0c03692c;
case 0x0c03692eu: goto P_0c03692e;
case 0x0c036930u: goto P_0c036930;
case 0x0c036932u: goto P_0c036932;
case 0x0c036934u: goto P_0c036934;
case 0x0c036936u: goto P_0c036936;
case 0x0c036938u: goto P_0c036938;
case 0x0c03693au: goto P_0c03693a;
case 0x0c03693cu: goto P_0c03693c;
case 0x0c03693eu: goto P_0c03693e;
case 0x0c036940u: goto P_0c036940;
case 0x0c036942u: goto P_0c036942;
case 0x0c036944u: goto P_0c036944;
case 0x0c036946u: goto P_0c036946;
case 0x0c036948u: goto P_0c036948;
case 0x0c03694au: goto P_0c03694a;
case 0x0c03694cu: goto P_0c03694c;
case 0x0c03694eu: goto P_0c03694e;
case 0x0c036950u: goto P_0c036950;
case 0x0c036952u: goto P_0c036952;
case 0x0c036954u: goto P_0c036954;
case 0x0c036956u: goto P_0c036956;
case 0x0c036958u: goto P_0c036958;
case 0x0c03695au: goto P_0c03695a;
case 0x0c03695cu: goto P_0c03695c;
case 0x0c03695eu: goto P_0c03695e;
case 0x0c036960u: goto P_0c036960;
case 0x0c036962u: goto P_0c036962;
case 0x0c036964u: goto P_0c036964;
case 0x0c036966u: goto P_0c036966;
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
case 0x0c0371f8u: goto P_0c0371f8;
case 0x0c0371fau: goto P_0c0371fa;
case 0x0c0371fcu: goto P_0c0371fc;
case 0x0c037240u: goto P_0c037240;
case 0x0c037242u: goto P_0c037242;
case 0x0c037244u: goto P_0c037244;
case 0x0c037246u: goto P_0c037246;
case 0x0c038760u: goto P_0c038760;
case 0x0c038762u: goto P_0c038762;
case 0x0c038764u: goto P_0c038764;
case 0x0c038cb0u: goto P_0c038cb0;
case 0x0c038cb2u: goto P_0c038cb2;
case 0x0c038cb4u: goto P_0c038cb4;
case 0x0c038cb6u: goto P_0c038cb6;
case 0x0c038cb8u: goto P_0c038cb8;
case 0x0c038cbau: goto P_0c038cba;
case 0x0c038cbcu: goto P_0c038cbc;
case 0x0c038cbeu: goto P_0c038cbe;
case 0x0c038cc0u: goto P_0c038cc0;
case 0x0c038cc2u: goto P_0c038cc2;
case 0x0c038cc4u: goto P_0c038cc4;
case 0x0c038cc6u: goto P_0c038cc6;
case 0x0c038cc8u: goto P_0c038cc8;
case 0x0c038ccau: goto P_0c038cca;
case 0x0c038cccu: goto P_0c038ccc;
case 0x0c038cceu: goto P_0c038cce;
case 0x0c038cd0u: goto P_0c038cd0;
case 0x0c038cd2u: goto P_0c038cd2;
case 0x0c038cd4u: goto P_0c038cd4;
case 0x0c038cd6u: goto P_0c038cd6;
case 0x0c038cd8u: goto P_0c038cd8;
case 0x0c038ce0u: goto P_0c038ce0;
case 0x0c038ce2u: goto P_0c038ce2;
case 0x0c038ce4u: goto P_0c038ce4;
case 0x0c03f2d0u: goto P_0c03f2d0;
case 0x0c03f2d2u: goto P_0c03f2d2;
case 0x0c03f2d4u: goto P_0c03f2d4;
case 0x0c03f2d6u: goto P_0c03f2d6;
case 0x0c03f2d8u: goto P_0c03f2d8;
case 0x0c03f2dau: goto P_0c03f2da;
case 0x0c03f2dcu: goto P_0c03f2dc;
case 0x0c03f2deu: goto P_0c03f2de;
case 0x0c03f2e0u: goto P_0c03f2e0;
case 0x0c03f2e2u: goto P_0c03f2e2;
case 0x0c03f2e4u: goto P_0c03f2e4;
case 0x0c03f2e6u: goto P_0c03f2e6;
case 0x0c03f2e8u: goto P_0c03f2e8;
case 0x0c03f2eau: goto P_0c03f2ea;
case 0x0c03f2ecu: goto P_0c03f2ec;
case 0x0c03f2eeu: goto P_0c03f2ee;
case 0x0c03f2f0u: goto P_0c03f2f0;
case 0x0c03f350u: goto P_0c03f350;
case 0x0c03f352u: goto P_0c03f352;
case 0x0c03f354u: goto P_0c03f354;
case 0x0c03f356u: goto P_0c03f356;
case 0x0c03f358u: goto P_0c03f358;
case 0x0c03f35au: goto P_0c03f35a;
case 0x0c03f35cu: goto P_0c03f35c;
case 0x0c03f35eu: goto P_0c03f35e;
case 0x0c03f360u: goto P_0c03f360;
case 0x0c03f362u: goto P_0c03f362;
case 0x0c03f364u: goto P_0c03f364;
case 0x0c03f366u: goto P_0c03f366;
case 0x0c03f368u: goto P_0c03f368;
case 0x0c03f36au: goto P_0c03f36a;
case 0x0c03f36cu: goto P_0c03f36c;
case 0x0c03f36eu: goto P_0c03f36e;
case 0x0c03f370u: goto P_0c03f370;
case 0x0c03f372u: goto P_0c03f372;
case 0x0c03f374u: goto P_0c03f374;
case 0x0c03f376u: goto P_0c03f376;
case 0x0c03f378u: goto P_0c03f378;
case 0x0c03f37au: goto P_0c03f37a;
case 0x0c03f37cu: goto P_0c03f37c;
case 0x0c03f37eu: goto P_0c03f37e;
case 0x0c03f380u: goto P_0c03f380;
case 0x0c03f390u: goto P_0c03f390;
case 0x0c03f392u: goto P_0c03f392;
case 0x0c03f394u: goto P_0c03f394;
case 0x0c03f396u: goto P_0c03f396;
case 0x0c03f398u: goto P_0c03f398;
case 0x0c03f39au: goto P_0c03f39a;
case 0x0c03f39cu: goto P_0c03f39c;
case 0x0c03f39eu: goto P_0c03f39e;
case 0x0c03f3a0u: goto P_0c03f3a0;
case 0x0c03f3a2u: goto P_0c03f3a2;
case 0x0c03f3b0u: goto P_0c03f3b0;
case 0x0c03f3b2u: goto P_0c03f3b2;
case 0x0c03f3b4u: goto P_0c03f3b4;
case 0x0c03f3b6u: goto P_0c03f3b6;
case 0x0c03f3b8u: goto P_0c03f3b8;
case 0x0c03f3bau: goto P_0c03f3ba;
case 0x0c03f3bcu: goto P_0c03f3bc;
case 0x0c03f3beu: goto P_0c03f3be;
case 0x0c03f3c0u: goto P_0c03f3c0;
case 0x0c03f3c2u: goto P_0c03f3c2;
case 0x0c03f3c4u: goto P_0c03f3c4;
case 0x0c03f3c6u: goto P_0c03f3c6;
case 0x0c03f3c8u: goto P_0c03f3c8;
case 0x0c03f3cau: goto P_0c03f3ca;
case 0x0c03f3ccu: goto P_0c03f3cc;
case 0x0c03f3ceu: goto P_0c03f3ce;
case 0x0c03f3d0u: goto P_0c03f3d0;
case 0x0c03f3d2u: goto P_0c03f3d2;
case 0x0c03f3d4u: goto P_0c03f3d4;
case 0x0c03f3d6u: goto P_0c03f3d6;
case 0x0c03f3d8u: goto P_0c03f3d8;
case 0x0c03f3dau: goto P_0c03f3da;
default: return vf3_matrix_family(target,s,ram);
}
P_0c036794: /* original d374, guest PC 0x0c036794 */
if(!s->budget--) { s->failed_pc=0x0c036794u; return 0; }
r[3]=read(ram,0x0c036968u,4);
goto P_0c036796;
P_0c036796: /* original 432b, guest PC 0x0c036796 */
if(!s->budget--) { s->failed_pc=0x0c036796u; return 0; }
target=r[3];
code_base=target&0xff000000u;
switch(target&0x1fffffffu) {
case 0x0c036db8u: goto P_0c036db8;
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
P_0c036798: /* original 0009, guest PC 0x0c036798 */
if(!s->budget--) { s->failed_pc=0x0c036798u; return 0; }
if(!vf3_matrix_family(0x0c03679au,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c03679au; return 0; } return 1;
P_0c0368aa: /* original 000b, guest PC 0x0c0368aa */
if(!s->budget--) { s->failed_pc=0x0c0368aau; return 0; }
target=r[16];
r[0]=0x00000000u;
s->pc=target; return ram->oob==0;
P_0c0368ac: /* original e000, guest PC 0x0c0368ac */
if(!s->budget--) { s->failed_pc=0x0c0368acu; return 0; }
r[0]=0x00000000u;
goto P_0c0368ae;
P_0c0368ae: /* original affc, guest PC 0x0c0368ae */
if(!s->budget--) { s->failed_pc=0x0c0368aeu; return 0; }
goto P_0c0368aa;
P_0c0368b0: /* original 0009, guest PC 0x0c0368b0 */
if(!s->budget--) { s->failed_pc=0x0c0368b0u; return 0; }
goto P_0c0368b2;
P_0c0368b2: /* original 2fe6, guest PC 0x0c0368b2 */
if(!s->budget--) { s->failed_pc=0x0c0368b2u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0368b4;
P_0c0368b4: /* original 2fd6, guest PC 0x0c0368b4 */
if(!s->budget--) { s->failed_pc=0x0c0368b4u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0368b6;
P_0c0368b6: /* original 2fc6, guest PC 0x0c0368b6 */
if(!s->budget--) { s->failed_pc=0x0c0368b6u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0368b8;
P_0c0368b8: /* original 2fb6, guest PC 0x0c0368b8 */
if(!s->budget--) { s->failed_pc=0x0c0368b8u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0368ba;
P_0c0368ba: /* original 2fa6, guest PC 0x0c0368ba */
if(!s->budget--) { s->failed_pc=0x0c0368bau; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0368bc;
P_0c0368bc: /* original 2f96, guest PC 0x0c0368bc */
if(!s->budget--) { s->failed_pc=0x0c0368bcu; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0368be;
P_0c0368be: /* original d439, guest PC 0x0c0368be */
if(!s->budget--) { s->failed_pc=0x0c0368beu; return 0; }
r[4]=read(ram,0x0c0369a4u,4);
goto P_0c0368c0;
P_0c0368c0: /* original 4f22, guest PC 0x0c0368c0 */
if(!s->budget--) { s->failed_pc=0x0c0368c0u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0368c2;
P_0c0368c2: /* original 6342, guest PC 0x0c0368c2 */
if(!s->budget--) { s->failed_pc=0x0c0368c2u; return 0; }
tmp=read(ram,r[4],4);
r[3]=tmp;
goto P_0c0368c4;
P_0c0368c4: /* original d238, guest PC 0x0c0368c4 */
if(!s->budget--) { s->failed_pc=0x0c0368c4u; return 0; }
r[2]=read(ram,0x0c0369a8u,4);
goto P_0c0368c6;
P_0c0368c6: /* original 7301, guest PC 0x0c0368c6 */
if(!s->budget--) { s->failed_pc=0x0c0368c6u; return 0; }
r[3]+=0x00000001u;
goto P_0c0368c8;
P_0c0368c8: /* original 420b, guest PC 0x0c0368c8 */
if(!s->budget--) { s->failed_pc=0x0c0368c8u; return 0; }
target=r[2];
r[16]=code_base|0x0c0368ccu;
write(ram,r[4],r[3],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0368ccu) { target=s->pc; goto dispatch; }
goto P_0c0368cc;
P_0c0368ca: /* original 2432, guest PC 0x0c0368ca */
if(!s->budget--) { s->failed_pc=0x0c0368cau; return 0; }
write(ram,r[4],r[3],4);
goto P_0c0368cc;
P_0c0368cc: /* original d238, guest PC 0x0c0368cc */
if(!s->budget--) { s->failed_pc=0x0c0368ccu; return 0; }
r[2]=read(ram,0x0c0369b0u,4);
goto P_0c0368ce;
P_0c0368ce: /* original d137, guest PC 0x0c0368ce */
if(!s->budget--) { s->failed_pc=0x0c0368ceu; return 0; }
r[1]=read(ram,0x0c0369acu,4);
goto P_0c0368d0;
P_0c0368d0: /* original 6322, guest PC 0x0c0368d0 */
if(!s->budget--) { s->failed_pc=0x0c0368d0u; return 0; }
tmp=read(ram,r[2],4);
r[3]=tmp;
goto P_0c0368d2;
P_0c0368d2: /* original 2132, guest PC 0x0c0368d2 */
if(!s->budget--) { s->failed_pc=0x0c0368d2u; return 0; }
write(ram,r[1],r[3],4);
goto P_0c0368d4;
P_0c0368d4: /* original ea00, guest PC 0x0c0368d4 */
if(!s->budget--) { s->failed_pc=0x0c0368d4u; return 0; }
r[10]=0x00000000u;
goto P_0c0368d6;
P_0c0368d6: /* original dd39, guest PC 0x0c0368d6 */
if(!s->budget--) { s->failed_pc=0x0c0368d6u; return 0; }
r[13]=read(ram,0x0c0369bcu,4);
goto P_0c0368d8;
P_0c0368d8: /* original e902, guest PC 0x0c0368d8 */
if(!s->budget--) { s->failed_pc=0x0c0368d8u; return 0; }
r[9]=0x00000002u;
goto P_0c0368da;
P_0c0368da: /* original db37, guest PC 0x0c0368da */
if(!s->budget--) { s->failed_pc=0x0c0368dau; return 0; }
r[11]=read(ram,0x0c0369b8u,4);
goto P_0c0368dc;
P_0c0368dc: /* original dc38, guest PC 0x0c0368dc */
if(!s->budget--) { s->failed_pc=0x0c0368dcu; return 0; }
r[12]=read(ram,0x0c0369c0u,4);
goto P_0c0368de;
P_0c0368de: /* original de35, guest PC 0x0c0368de */
if(!s->budget--) { s->failed_pc=0x0c0368deu; return 0; }
r[14]=read(ram,0x0c0369b4u,4);
goto P_0c0368e0;
P_0c0368e0: /* original bf58, guest PC 0x0c0368e0 */
if(!s->budget--) { s->failed_pc=0x0c0368e0u; return 0; }
target=code_base|0x0c036794u; r[16]=code_base|0x0c0368e4u;
tmp=read(ram,r[12],4);
r[12]+=4;
r[4]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0368e4u) { target=s->pc; goto dispatch; }
goto P_0c0368e4;
P_0c0368e2: /* original 64c6, guest PC 0x0c0368e2 */
if(!s->budget--) { s->failed_pc=0x0c0368e2u; return 0; }
tmp=read(ram,r[12],4);
r[12]+=4;
r[4]=tmp;
goto P_0c0368e4;
P_0c0368e4: /* original 6403, guest PC 0x0c0368e4 */
if(!s->budget--) { s->failed_pc=0x0c0368e4u; return 0; }
r[4]=r[0];
goto P_0c0368e6;
P_0c0368e6: /* original 60b1, guest PC 0x0c0368e6 */
if(!s->budget--) { s->failed_pc=0x0c0368e6u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[11],2);
r[0]=tmp;
goto P_0c0368e8;
P_0c0368e8: /* original e2f8, guest PC 0x0c0368e8 */
if(!s->budget--) { s->failed_pc=0x0c0368e8u; return 0; }
r[2]=0xfffffff8u;
goto P_0c0368ea;
P_0c0368ea: /* original 81e2, guest PC 0x0c0368ea */
if(!s->budget--) { s->failed_pc=0x0c0368eau; return 0; }
write(ram,r[14]+4,r[0],2);
goto P_0c0368ec;
P_0c0368ec: /* original 5542, guest PC 0x0c0368ec */
if(!s->budget--) { s->failed_pc=0x0c0368ecu; return 0; }
r[5]=read(ram,r[4]+8,4);
goto P_0c0368ee;
P_0c0368ee: /* original 655d, guest PC 0x0c0368ee */
if(!s->budget--) { s->failed_pc=0x0c0368eeu; return 0; }
r[5]=r[5]&65535u;
goto P_0c0368f0;
P_0c0368f0: /* original 6353, guest PC 0x0c0368f0 */
if(!s->budget--) { s->failed_pc=0x0c0368f0u; return 0; }
r[3]=r[5];
goto P_0c0368f2;
P_0c0368f2: /* original 6053, guest PC 0x0c0368f2 */
if(!s->budget--) { s->failed_pc=0x0c0368f2u; return 0; }
r[0]=r[5];
goto P_0c0368f4;
P_0c0368f4: /* original 432c, guest PC 0x0c0368f4 */
if(!s->budget--) { s->failed_pc=0x0c0368f4u; return 0; }
r[3]=(r[2]&0x80000000u)?((r[2]&31u)?(uint32_t)((int32_t)r[3]>>((-r[2])&31u)):((int32_t)r[3]<0?0xffffffffu:0)):r[3]<<(r[2]&31u);
goto P_0c0368f6;
P_0c0368f6: /* original 4018, guest PC 0x0c0368f6 */
if(!s->budget--) { s->failed_pc=0x0c0368f6u; return 0; }
r[0]<<=8;
goto P_0c0368f8;
P_0c0368f8: /* original 633c, guest PC 0x0c0368f8 */
if(!s->budget--) { s->failed_pc=0x0c0368f8u; return 0; }
r[3]=r[3]&255u;
goto P_0c0368fa;
P_0c0368fa: /* original 20d9, guest PC 0x0c0368fa */
if(!s->budget--) { s->failed_pc=0x0c0368fau; return 0; }
r[0]&=r[13];
goto P_0c0368fc;
P_0c0368fc: /* original 203b, guest PC 0x0c0368fc */
if(!s->budget--) { s->failed_pc=0x0c0368fcu; return 0; }
r[0]|=r[3];
goto P_0c0368fe;
P_0c0368fe: /* original 81e1, guest PC 0x0c0368fe */
if(!s->budget--) { s->failed_pc=0x0c0368feu; return 0; }
write(ram,r[14]+2,r[0],2);
goto P_0c036900;
P_0c036900: /* original 5544, guest PC 0x0c036900 */
if(!s->budget--) { s->failed_pc=0x0c036900u; return 0; }
r[5]=read(ram,r[4]+16,4);
goto P_0c036902;
P_0c036902: /* original 655d, guest PC 0x0c036902 */
if(!s->budget--) { s->failed_pc=0x0c036902u; return 0; }
r[5]=r[5]&65535u;
goto P_0c036904;
P_0c036904: /* original 6353, guest PC 0x0c036904 */
if(!s->budget--) { s->failed_pc=0x0c036904u; return 0; }
r[3]=r[5];
goto P_0c036906;
P_0c036906: /* original 6053, guest PC 0x0c036906 */
if(!s->budget--) { s->failed_pc=0x0c036906u; return 0; }
r[0]=r[5];
goto P_0c036908;
P_0c036908: /* original 432c, guest PC 0x0c036908 */
if(!s->budget--) { s->failed_pc=0x0c036908u; return 0; }
r[3]=(r[2]&0x80000000u)?((r[2]&31u)?(uint32_t)((int32_t)r[3]>>((-r[2])&31u)):((int32_t)r[3]<0?0xffffffffu:0)):r[3]<<(r[2]&31u);
goto P_0c03690a;
P_0c03690a: /* original 4018, guest PC 0x0c03690a */
if(!s->budget--) { s->failed_pc=0x0c03690au; return 0; }
r[0]<<=8;
goto P_0c03690c;
P_0c03690c: /* original 633c, guest PC 0x0c03690c */
if(!s->budget--) { s->failed_pc=0x0c03690cu; return 0; }
r[3]=r[3]&255u;
goto P_0c03690e;
P_0c03690e: /* original 20d9, guest PC 0x0c03690e */
if(!s->budget--) { s->failed_pc=0x0c03690eu; return 0; }
r[0]&=r[13];
goto P_0c036910;
P_0c036910: /* original 203b, guest PC 0x0c036910 */
if(!s->budget--) { s->failed_pc=0x0c036910u; return 0; }
r[0]|=r[3];
goto P_0c036912;
P_0c036912: /* original 81e3, guest PC 0x0c036912 */
if(!s->budget--) { s->failed_pc=0x0c036912u; return 0; }
write(ram,r[14]+6,r[0],2);
goto P_0c036914;
P_0c036914: /* original 5545, guest PC 0x0c036914 */
if(!s->budget--) { s->failed_pc=0x0c036914u; return 0; }
r[5]=read(ram,r[4]+20,4);
goto P_0c036916;
P_0c036916: /* original 655d, guest PC 0x0c036916 */
if(!s->budget--) { s->failed_pc=0x0c036916u; return 0; }
r[5]=r[5]&65535u;
goto P_0c036918;
P_0c036918: /* original 6353, guest PC 0x0c036918 */
if(!s->budget--) { s->failed_pc=0x0c036918u; return 0; }
r[3]=r[5];
goto P_0c03691a;
P_0c03691a: /* original 6053, guest PC 0x0c03691a */
if(!s->budget--) { s->failed_pc=0x0c03691au; return 0; }
r[0]=r[5];
goto P_0c03691c;
P_0c03691c: /* original 432c, guest PC 0x0c03691c */
if(!s->budget--) { s->failed_pc=0x0c03691cu; return 0; }
r[3]=(r[2]&0x80000000u)?((r[2]&31u)?(uint32_t)((int32_t)r[3]>>((-r[2])&31u)):((int32_t)r[3]<0?0xffffffffu:0)):r[3]<<(r[2]&31u);
goto P_0c03691e;
P_0c03691e: /* original 4018, guest PC 0x0c03691e */
if(!s->budget--) { s->failed_pc=0x0c03691eu; return 0; }
r[0]<<=8;
goto P_0c036920;
P_0c036920: /* original 633c, guest PC 0x0c036920 */
if(!s->budget--) { s->failed_pc=0x0c036920u; return 0; }
r[3]=r[3]&255u;
goto P_0c036922;
P_0c036922: /* original 20d9, guest PC 0x0c036922 */
if(!s->budget--) { s->failed_pc=0x0c036922u; return 0; }
r[0]&=r[13];
goto P_0c036924;
P_0c036924: /* original 203b, guest PC 0x0c036924 */
if(!s->budget--) { s->failed_pc=0x0c036924u; return 0; }
r[0]|=r[3];
goto P_0c036926;
P_0c036926: /* original 81e4, guest PC 0x0c036926 */
if(!s->budget--) { s->failed_pc=0x0c036926u; return 0; }
write(ram,r[14]+8,r[0],2);
goto P_0c036928;
P_0c036928: /* original 7a01, guest PC 0x0c036928 */
if(!s->budget--) { s->failed_pc=0x0c036928u; return 0; }
r[10]+=0x00000001u;
goto P_0c03692a;
P_0c03692a: /* original 854c, guest PC 0x0c03692a */
if(!s->budget--) { s->failed_pc=0x0c03692au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+24,2);
goto P_0c03692c;
P_0c03692c: /* original 3a93, guest PC 0x0c03692c */
if(!s->budget--) { s->failed_pc=0x0c03692cu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[10]>=(int32_t)r[9])!=0);
goto P_0c03692e;
P_0c03692e: /* original 80ea, guest PC 0x0c03692e */
if(!s->budget--) { s->failed_pc=0x0c03692eu; return 0; }
write(ram,r[14]+10,r[0],1);
goto P_0c036930;
P_0c036930: /* original 854d, guest PC 0x0c036930 */
if(!s->budget--) { s->failed_pc=0x0c036930u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+26,2);
goto P_0c036932;
P_0c036932: /* original 80eb, guest PC 0x0c036932 */
if(!s->budget--) { s->failed_pc=0x0c036932u; return 0; }
write(ram,r[14]+11,r[0],1);
goto P_0c036934;
P_0c036934: /* original 854e, guest PC 0x0c036934 */
if(!s->budget--) { s->failed_pc=0x0c036934u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+28,2);
goto P_0c036936;
P_0c036936: /* original 80ec, guest PC 0x0c036936 */
if(!s->budget--) { s->failed_pc=0x0c036936u; return 0; }
write(ram,r[14]+12,r[0],1);
goto P_0c036938;
P_0c036938: /* original 854f, guest PC 0x0c036938 */
if(!s->budget--) { s->failed_pc=0x0c036938u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+30,2);
goto P_0c03693a;
P_0c03693a: /* original 80ed, guest PC 0x0c03693a */
if(!s->budget--) { s->failed_pc=0x0c03693au; return 0; }
write(ram,r[14]+13,r[0],1);
goto P_0c03693c;
P_0c03693c: /* original e020, guest PC 0x0c03693c */
if(!s->budget--) { s->failed_pc=0x0c03693cu; return 0; }
r[0]=0x00000020u;
goto P_0c03693e;
P_0c03693e: /* original 004c, guest PC 0x0c03693e */
if(!s->budget--) { s->failed_pc=0x0c03693eu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c036940;
P_0c036940: /* original 80ee, guest PC 0x0c036940 */
if(!s->budget--) { s->failed_pc=0x0c036940u; return 0; }
write(ram,r[14]+14,r[0],1);
goto P_0c036942;
P_0c036942: /* original e022, guest PC 0x0c036942 */
if(!s->budget--) { s->failed_pc=0x0c036942u; return 0; }
r[0]=0x00000022u;
goto P_0c036944;
P_0c036944: /* original 004c, guest PC 0x0c036944 */
if(!s->budget--) { s->failed_pc=0x0c036944u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c036946;
P_0c036946: /* original 80ef, guest PC 0x0c036946 */
if(!s->budget--) { s->failed_pc=0x0c036946u; return 0; }
write(ram,r[14]+15,r[0],1);
goto P_0c036948;
P_0c036948: /* original 85e1, guest PC 0x0c036948 */
if(!s->budget--) { s->failed_pc=0x0c036948u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+2,2);
goto P_0c03694a;
P_0c03694a: /* original 2b01, guest PC 0x0c03694a */
if(!s->budget--) { s->failed_pc=0x0c03694au; return 0; }
write(ram,r[11],r[0],2);
goto P_0c03694c;
P_0c03694c: /* original 8fc8, guest PC 0x0c03694c */
if(!s->budget--) { s->failed_pc=0x0c03694cu; return 0; }
cond=r[17]&1u;
r[14]+=0x00000010u;
if(!cond) { goto P_0c0368e0; }
goto P_0c036950;
P_0c03694e: /* original 7e10, guest PC 0x0c03694e */
if(!s->budget--) { s->failed_pc=0x0c03694eu; return 0; }
r[14]+=0x00000010u;
goto P_0c036950;
P_0c036950: /* original d117, guest PC 0x0c036950 */
if(!s->budget--) { s->failed_pc=0x0c036950u; return 0; }
r[1]=read(ram,0x0c0369b0u,4);
goto P_0c036952;
P_0c036952: /* original d21c, guest PC 0x0c036952 */
if(!s->budget--) { s->failed_pc=0x0c036952u; return 0; }
r[2]=read(ram,0x0c0369c4u,4);
goto P_0c036954;
P_0c036954: /* original 6312, guest PC 0x0c036954 */
if(!s->budget--) { s->failed_pc=0x0c036954u; return 0; }
tmp=read(ram,r[1],4);
r[3]=tmp;
goto P_0c036956;
P_0c036956: /* original 4f26, guest PC 0x0c036956 */
if(!s->budget--) { s->failed_pc=0x0c036956u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c036958;
P_0c036958: /* original 2232, guest PC 0x0c036958 */
if(!s->budget--) { s->failed_pc=0x0c036958u; return 0; }
write(ram,r[2],r[3],4);
goto P_0c03695a;
P_0c03695a: /* original 69f6, guest PC 0x0c03695a */
if(!s->budget--) { s->failed_pc=0x0c03695au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c03695c;
P_0c03695c: /* original 6af6, guest PC 0x0c03695c */
if(!s->budget--) { s->failed_pc=0x0c03695cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c03695e;
P_0c03695e: /* original 6bf6, guest PC 0x0c03695e */
if(!s->budget--) { s->failed_pc=0x0c03695eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c036960;
P_0c036960: /* original 6cf6, guest PC 0x0c036960 */
if(!s->budget--) { s->failed_pc=0x0c036960u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c036962;
P_0c036962: /* original 6df6, guest PC 0x0c036962 */
if(!s->budget--) { s->failed_pc=0x0c036962u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c036964;
P_0c036964: /* original 000b, guest PC 0x0c036964 */
if(!s->budget--) { s->failed_pc=0x0c036964u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c036966: /* original 6ef6, guest PC 0x0c036966 */
if(!s->budget--) { s->failed_pc=0x0c036966u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c036968u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c036968u; return 0; } return 1;
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
P_0c0371f8: /* original d001, guest PC 0x0c0371f8 */
if(!s->budget--) { s->failed_pc=0x0c0371f8u; return 0; }
r[0]=read(ram,0x0c037200u,4);
goto P_0c0371fa;
P_0c0371fa: /* original 000b, guest PC 0x0c0371fa */
if(!s->budget--) { s->failed_pc=0x0c0371fau; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c0371fc: /* original 0009, guest PC 0x0c0371fc */
if(!s->budget--) { s->failed_pc=0x0c0371fcu; return 0; }
if(!vf3_matrix_family(0x0c0371feu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0371feu; return 0; } return 1;
P_0c037240: /* original d346, guest PC 0x0c037240 */
if(!s->budget--) { s->failed_pc=0x0c037240u; return 0; }
r[3]=read(ram,0x0c03735cu,4);
goto P_0c037242;
P_0c037242: /* original d545, guest PC 0x0c037242 */
if(!s->budget--) { s->failed_pc=0x0c037242u; return 0; }
r[5]=read(ram,0x0c037358u,4);
goto P_0c037244;
P_0c037244: /* original 432b, guest PC 0x0c037244 */
if(!s->budget--) { s->failed_pc=0x0c037244u; return 0; }
target=r[3];
r[4]=0x00000000u;
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
P_0c037246: /* original e400, guest PC 0x0c037246 */
if(!s->budget--) { s->failed_pc=0x0c037246u; return 0; }
r[4]=0x00000000u;
if(!vf3_matrix_family(0x0c037248u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c037248u; return 0; } return 1;
P_0c038760: /* original d23a, guest PC 0x0c038760 */
if(!s->budget--) { s->failed_pc=0x0c038760u; return 0; }
r[2]=read(ram,0x0c03884cu,4);
goto P_0c038762;
P_0c038762: /* original 000b, guest PC 0x0c038762 */
if(!s->budget--) { s->failed_pc=0x0c038762u; return 0; }
target=r[16];
write(ram,r[2],r[4],4);
s->pc=target; return ram->oob==0;
P_0c038764: /* original 2242, guest PC 0x0c038764 */
if(!s->budget--) { s->failed_pc=0x0c038764u; return 0; }
write(ram,r[2],r[4],4);
if(!vf3_matrix_family(0x0c038766u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c038766u; return 0; } return 1;
P_0c038cb0: /* original 4f22, guest PC 0x0c038cb0 */
if(!s->budget--) { s->failed_pc=0x0c038cb0u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c038cb2;
P_0c038cb2: /* original d118, guest PC 0x0c038cb2 */
if(!s->budget--) { s->failed_pc=0x0c038cb2u; return 0; }
r[1]=read(ram,0x0c038d14u,4);
goto P_0c038cb4;
P_0c038cb4: /* original e301, guest PC 0x0c038cb4 */
if(!s->budget--) { s->failed_pc=0x0c038cb4u; return 0; }
r[3]=0x00000001u;
goto P_0c038cb6;
P_0c038cb6: /* original d218, guest PC 0x0c038cb6 */
if(!s->budget--) { s->failed_pc=0x0c038cb6u; return 0; }
r[2]=read(ram,0x0c038d18u,4);
goto P_0c038cb8;
P_0c038cb8: /* original 420b, guest PC 0x0c038cb8 */
if(!s->budget--) { s->failed_pc=0x0c038cb8u; return 0; }
target=r[2];
r[16]=code_base|0x0c038cbcu;
write(ram,r[1],r[3],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c038cbcu) { target=s->pc; goto dispatch; }
goto P_0c038cbc;
P_0c038cba: /* original 2132, guest PC 0x0c038cba */
if(!s->budget--) { s->failed_pc=0x0c038cbau; return 0; }
write(ram,r[1],r[3],4);
goto P_0c038cbc;
P_0c038cbc: /* original d317, guest PC 0x0c038cbc */
if(!s->budget--) { s->failed_pc=0x0c038cbcu; return 0; }
r[3]=read(ram,0x0c038d1cu,4);
goto P_0c038cbe;
P_0c038cbe: /* original e000, guest PC 0x0c038cbe */
if(!s->budget--) { s->failed_pc=0x0c038cbeu; return 0; }
r[0]=0x00000000u;
goto P_0c038cc0;
P_0c038cc0: /* original d214, guest PC 0x0c038cc0 */
if(!s->budget--) { s->failed_pc=0x0c038cc0u; return 0; }
r[2]=read(ram,0x0c038d14u,4);
goto P_0c038cc2;
P_0c038cc2: /* original 430b, guest PC 0x0c038cc2 */
if(!s->budget--) { s->failed_pc=0x0c038cc2u; return 0; }
target=r[3];
r[16]=code_base|0x0c038cc6u;
write(ram,r[2],r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c038cc6u) { target=s->pc; goto dispatch; }
goto P_0c038cc6;
P_0c038cc4: /* original 2202, guest PC 0x0c038cc4 */
if(!s->budget--) { s->failed_pc=0x0c038cc4u; return 0; }
write(ram,r[2],r[0],4);
goto P_0c038cc6;
P_0c038cc6: /* original d416, guest PC 0x0c038cc6 */
if(!s->budget--) { s->failed_pc=0x0c038cc6u; return 0; }
r[4]=read(ram,0x0c038d20u,4);
goto P_0c038cc8;
P_0c038cc8: /* original 6240, guest PC 0x0c038cc8 */
if(!s->budget--) { s->failed_pc=0x0c038cc8u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[4],1);
r[2]=tmp;
goto P_0c038cca;
P_0c038cca: /* original 2228, guest PC 0x0c038cca */
if(!s->budget--) { s->failed_pc=0x0c038ccau; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c038ccc;
P_0c038ccc: /* original 8908, guest PC 0x0c038ccc */
if(!s->budget--) { s->failed_pc=0x0c038cccu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c038ce0; }
goto P_0c038cce;
P_0c038cce: /* original e100, guest PC 0x0c038cce */
if(!s->budget--) { s->failed_pc=0x0c038cceu; return 0; }
r[1]=0x00000000u;
goto P_0c038cd0;
P_0c038cd0: /* original 2410, guest PC 0x0c038cd0 */
if(!s->budget--) { s->failed_pc=0x0c038cd0u; return 0; }
write(ram,r[4],r[1],1);
goto P_0c038cd2;
P_0c038cd2: /* original d315, guest PC 0x0c038cd2 */
if(!s->budget--) { s->failed_pc=0x0c038cd2u; return 0; }
r[3]=read(ram,0x0c038d28u,4);
goto P_0c038cd4;
P_0c038cd4: /* original d413, guest PC 0x0c038cd4 */
if(!s->budget--) { s->failed_pc=0x0c038cd4u; return 0; }
r[4]=read(ram,0x0c038d24u,4);
goto P_0c038cd6;
P_0c038cd6: /* original 432b, guest PC 0x0c038cd6 */
if(!s->budget--) { s->failed_pc=0x0c038cd6u; return 0; }
target=r[3];
r[16]=read(ram,r[15],4); r[15]+=4;
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
P_0c038cd8: /* original 4f26, guest PC 0x0c038cd8 */
if(!s->budget--) { s->failed_pc=0x0c038cd8u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
if(!vf3_matrix_family(0x0c038cdau,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c038cdau; return 0; } return 1;
P_0c038ce0: /* original 4f26, guest PC 0x0c038ce0 */
if(!s->budget--) { s->failed_pc=0x0c038ce0u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c038ce2;
P_0c038ce2: /* original 000b, guest PC 0x0c038ce2 */
if(!s->budget--) { s->failed_pc=0x0c038ce2u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c038ce4: /* original 0009, guest PC 0x0c038ce4 */
if(!s->budget--) { s->failed_pc=0x0c038ce4u; return 0; }
if(!vf3_matrix_family(0x0c038ce6u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c038ce6u; return 0; } return 1;
P_0c03f2d0: /* original 2fe6, guest PC 0x0c03f2d0 */
if(!s->budget--) { s->failed_pc=0x0c03f2d0u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03f2d2;
P_0c03f2d2: /* original 2fd6, guest PC 0x0c03f2d2 */
if(!s->budget--) { s->failed_pc=0x0c03f2d2u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03f2d4;
P_0c03f2d4: /* original 2fc6, guest PC 0x0c03f2d4 */
if(!s->budget--) { s->failed_pc=0x0c03f2d4u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03f2d6;
P_0c03f2d6: /* original 2fb6, guest PC 0x0c03f2d6 */
if(!s->budget--) { s->failed_pc=0x0c03f2d6u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03f2d8;
P_0c03f2d8: /* original 2fa6, guest PC 0x0c03f2d8 */
if(!s->budget--) { s->failed_pc=0x0c03f2d8u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03f2da;
P_0c03f2da: /* original 2f96, guest PC 0x0c03f2da */
if(!s->budget--) { s->failed_pc=0x0c03f2dau; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03f2dc;
P_0c03f2dc: /* original 2f86, guest PC 0x0c03f2dc */
if(!s->budget--) { s->failed_pc=0x0c03f2dcu; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03f2de;
P_0c03f2de: /* original 6342, guest PC 0x0c03f2de */
if(!s->budget--) { s->failed_pc=0x0c03f2deu; return 0; }
tmp=read(ram,r[4],4);
r[3]=tmp;
goto P_0c03f2e0;
P_0c03f2e0: /* original 4f22, guest PC 0x0c03f2e0 */
if(!s->budget--) { s->failed_pc=0x0c03f2e0u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c03f2e2;
P_0c03f2e2: /* original 4311, guest PC 0x0c03f2e2 */
if(!s->budget--) { s->failed_pc=0x0c03f2e2u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>=0)!=0);
goto P_0c03f2e4;
P_0c03f2e4: /* original 8f03, guest PC 0x0c03f2e4 */
if(!s->budget--) { s->failed_pc=0x0c03f2e4u; return 0; }
cond=r[17]&1u;
r[12]=0x00000000u;
if(!cond) { goto P_0c03f2ee; }
goto P_0c03f2e8;
P_0c03f2e6: /* original ec00, guest PC 0x0c03f2e6 */
if(!s->budget--) { s->failed_pc=0x0c03f2e6u; return 0; }
r[12]=0x00000000u;
goto P_0c03f2e8;
P_0c03f2e8: /* original 5146, guest PC 0x0c03f2e8 */
if(!s->budget--) { s->failed_pc=0x0c03f2e8u; return 0; }
r[1]=read(ram,r[4]+24,4);
goto P_0c03f2ea;
P_0c03f2ea: /* original 2118, guest PC 0x0c03f2ea */
if(!s->budget--) { s->failed_pc=0x0c03f2eau; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[1])==0)!=0);
goto P_0c03f2ec;
P_0c03f2ec: /* original 8b30, guest PC 0x0c03f2ec */
if(!s->budget--) { s->failed_pc=0x0c03f2ecu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c03f350; }
goto P_0c03f2ee;
P_0c03f2ee: /* original a06c, guest PC 0x0c03f2ee */
if(!s->budget--) { s->failed_pc=0x0c03f2eeu; return 0; }
r[0]=0x00000000u;
goto P_0c03f3ca;
P_0c03f2f0: /* original e000, guest PC 0x0c03f2f0 */
if(!s->budget--) { s->failed_pc=0x0c03f2f0u; return 0; }
r[0]=0x00000000u;
if(!vf3_matrix_family(0x0c03f2f2u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c03f2f2u; return 0; } return 1;
P_0c03f350: /* original da65, guest PC 0x0c03f350 */
if(!s->budget--) { s->failed_pc=0x0c03f350u; return 0; }
r[10]=read(ram,0x0c03f4e8u,4);
goto P_0c03f352;
P_0c03f352: /* original 6d43, guest PC 0x0c03f352 */
if(!s->budget--) { s->failed_pc=0x0c03f352u; return 0; }
r[13]=r[4];
goto P_0c03f354;
P_0c03f354: /* original e901, guest PC 0x0c03f354 */
if(!s->budget--) { s->failed_pc=0x0c03f354u; return 0; }
r[9]=0x00000001u;
goto P_0c03f356;
P_0c03f356: /* original 7d18, guest PC 0x0c03f356 */
if(!s->budget--) { s->failed_pc=0x0c03f356u; return 0; }
r[13]+=0x00000018u;
goto P_0c03f358;
P_0c03f358: /* original e8ff, guest PC 0x0c03f358 */
if(!s->budget--) { s->failed_pc=0x0c03f358u; return 0; }
r[8]=0xffffffffu;
goto P_0c03f35a;
P_0c03f35a: /* original 6ed3, guest PC 0x0c03f35a */
if(!s->budget--) { s->failed_pc=0x0c03f35au; return 0; }
r[14]=r[13];
goto P_0c03f35c;
P_0c03f35c: /* original 55e8, guest PC 0x0c03f35c */
if(!s->budget--) { s->failed_pc=0x0c03f35cu; return 0; }
r[5]=read(ram,r[14]+32,4);
goto P_0c03f35e;
P_0c03f35e: /* original 4511, guest PC 0x0c03f35e */
if(!s->budget--) { s->failed_pc=0x0c03f35eu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[5]>=0)!=0);
goto P_0c03f360;
P_0c03f360: /* original 8f17, guest PC 0x0c03f360 */
if(!s->budget--) { s->failed_pc=0x0c03f360u; return 0; }
cond=r[17]&1u;
r[13]+=0x00000050u;
if(!cond) { goto P_0c03f392; }
goto P_0c03f364;
P_0c03f362: /* original 7d50, guest PC 0x0c03f362 */
if(!s->budget--) { s->failed_pc=0x0c03f362u; return 0; }
r[13]+=0x00000050u;
goto P_0c03f364;
P_0c03f364: /* original d261, guest PC 0x0c03f364 */
if(!s->budget--) { s->failed_pc=0x0c03f364u; return 0; }
r[2]=read(ram,0x0c03f4ecu,4);
goto P_0c03f366;
P_0c03f366: /* original d062, guest PC 0x0c03f366 */
if(!s->budget--) { s->failed_pc=0x0c03f366u; return 0; }
r[0]=read(ram,0x0c03f4f0u,4);
goto P_0c03f368;
P_0c03f368: /* original 6322, guest PC 0x0c03f368 */
if(!s->budget--) { s->failed_pc=0x0c03f368u; return 0; }
tmp=read(ram,r[2],4);
r[3]=tmp;
goto P_0c03f36a;
P_0c03f36a: /* original 6102, guest PC 0x0c03f36a */
if(!s->budget--) { s->failed_pc=0x0c03f36au; return 0; }
tmp=read(ram,r[0],4);
r[1]=tmp;
goto P_0c03f36c;
P_0c03f36c: /* original 353c, guest PC 0x0c03f36c */
if(!s->budget--) { s->failed_pc=0x0c03f36cu; return 0; }
r[5]+=r[3];
goto P_0c03f36e;
P_0c03f36e: /* original 6453, guest PC 0x0c03f36e */
if(!s->budget--) { s->failed_pc=0x0c03f36eu; return 0; }
r[4]=r[5];
goto P_0c03f370;
P_0c03f370: /* original 4408, guest PC 0x0c03f370 */
if(!s->budget--) { s->failed_pc=0x0c03f370u; return 0; }
r[4]<<=2;
goto P_0c03f372;
P_0c03f372: /* original 4400, guest PC 0x0c03f372 */
if(!s->budget--) { s->failed_pc=0x0c03f372u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c03f374;
P_0c03f374: /* original 341c, guest PC 0x0c03f374 */
if(!s->budget--) { s->failed_pc=0x0c03f374u; return 0; }
r[4]+=r[1];
goto P_0c03f376;
P_0c03f376: /* original 6342, guest PC 0x0c03f376 */
if(!s->budget--) { s->failed_pc=0x0c03f376u; return 0; }
tmp=read(ram,r[4],4);
r[3]=tmp;
goto P_0c03f378;
P_0c03f378: /* original 2338, guest PC 0x0c03f378 */
if(!s->budget--) { s->failed_pc=0x0c03f378u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c03f37a;
P_0c03f37a: /* original 8b09, guest PC 0x0c03f37a */
if(!s->budget--) { s->failed_pc=0x0c03f37au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c03f390; }
goto P_0c03f37c;
P_0c03f37c: /* original 6c93, guest PC 0x0c03f37c */
if(!s->budget--) { s->failed_pc=0x0c03f37cu; return 0; }
r[12]=r[9];
goto P_0c03f37e;
P_0c03f37e: /* original a008, guest PC 0x0c03f37e */
if(!s->budget--) { s->failed_pc=0x0c03f37eu; return 0; }
r[5]=r[8];
goto P_0c03f392;
P_0c03f380: /* original 6583, guest PC 0x0c03f380 */
if(!s->budget--) { s->failed_pc=0x0c03f380u; return 0; }
r[5]=r[8];
if(!vf3_matrix_family(0x0c03f382u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c03f382u; return 0; } return 1;
P_0c03f390: /* original 5541, guest PC 0x0c03f390 */
if(!s->budget--) { s->failed_pc=0x0c03f390u; return 0; }
r[5]=read(ram,r[4]+4,4);
goto P_0c03f392;
P_0c03f392: /* original 5be3, guest PC 0x0c03f392 */
if(!s->budget--) { s->failed_pc=0x0c03f392u; return 0; }
r[11]=read(ram,r[14]+12,4);
goto P_0c03f394;
P_0c03f394: /* original 4511, guest PC 0x0c03f394 */
if(!s->budget--) { s->failed_pc=0x0c03f394u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[5]>=0)!=0);
goto P_0c03f396;
P_0c03f396: /* original 8f0b, guest PC 0x0c03f396 */
if(!s->budget--) { s->failed_pc=0x0c03f396u; return 0; }
cond=r[17]&1u;
r[11]&=r[10];
if(!cond) { goto P_0c03f3b0; }
goto P_0c03f39a;
P_0c03f398: /* original 2ba9, guest PC 0x0c03f398 */
if(!s->budget--) { s->failed_pc=0x0c03f398u; return 0; }
r[11]&=r[10];
goto P_0c03f39a;
P_0c03f39a: /* original d356, guest PC 0x0c03f39a */
if(!s->budget--) { s->failed_pc=0x0c03f39au; return 0; }
r[3]=read(ram,0x0c03f4f4u,4);
goto P_0c03f39c;
P_0c03f39c: /* original 430b, guest PC 0x0c03f39c */
if(!s->budget--) { s->failed_pc=0x0c03f39cu; return 0; }
target=r[3];
r[16]=code_base|0x0c03f3a0u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c03f3a0u) { target=s->pc; goto dispatch; }
goto P_0c03f3a0;
P_0c03f39e: /* original 64e3, guest PC 0x0c03f39e */
if(!s->budget--) { s->failed_pc=0x0c03f39eu; return 0; }
r[4]=r[14];
goto P_0c03f3a0;
P_0c03f3a0: /* original a009, guest PC 0x0c03f3a0 */
if(!s->budget--) { s->failed_pc=0x0c03f3a0u; return 0; }
goto P_0c03f3b6;
P_0c03f3a2: /* original 0009, guest PC 0x0c03f3a2 */
if(!s->budget--) { s->failed_pc=0x0c03f3a2u; return 0; }
if(!vf3_matrix_family(0x0c03f3a4u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c03f3a4u; return 0; } return 1;
P_0c03f3b0: /* original d351, guest PC 0x0c03f3b0 */
if(!s->budget--) { s->failed_pc=0x0c03f3b0u; return 0; }
r[3]=read(ram,0x0c03f4f8u,4);
goto P_0c03f3b2;
P_0c03f3b2: /* original 430b, guest PC 0x0c03f3b2 */
if(!s->budget--) { s->failed_pc=0x0c03f3b2u; return 0; }
target=r[3];
r[16]=code_base|0x0c03f3b6u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c03f3b6u) { target=s->pc; goto dispatch; }
goto P_0c03f3b6;
P_0c03f3b4: /* original 64e3, guest PC 0x0c03f3b4 */
if(!s->budget--) { s->failed_pc=0x0c03f3b4u; return 0; }
r[4]=r[14];
goto P_0c03f3b6;
P_0c03f3b6: /* original e04c, guest PC 0x0c03f3b6 */
if(!s->budget--) { s->failed_pc=0x0c03f3b6u; return 0; }
r[0]=0x0000004cu;
goto P_0c03f3b8;
P_0c03f3b8: /* original 52e3, guest PC 0x0c03f3b8 */
if(!s->budget--) { s->failed_pc=0x0c03f3b8u; return 0; }
r[2]=read(ram,r[14]+12,4);
goto P_0c03f3ba;
P_0c03f3ba: /* original 22bb, guest PC 0x0c03f3ba */
if(!s->budget--) { s->failed_pc=0x0c03f3bau; return 0; }
r[2]|=r[11];
goto P_0c03f3bc;
P_0c03f3bc: /* original 1e23, guest PC 0x0c03f3bc */
if(!s->budget--) { s->failed_pc=0x0c03f3bcu; return 0; }
write(ram,r[14]+12,r[2],4);
goto P_0c03f3be;
P_0c03f3be: /* original 03ee, guest PC 0x0c03f3be */
if(!s->budget--) { s->failed_pc=0x0c03f3beu; return 0; }
r[3]=read(ram,r[14]+r[0],4);
goto P_0c03f3c0;
P_0c03f3c0: /* original 3d3c, guest PC 0x0c03f3c0 */
if(!s->budget--) { s->failed_pc=0x0c03f3c0u; return 0; }
r[13]+=r[3];
goto P_0c03f3c2;
P_0c03f3c2: /* original 64d2, guest PC 0x0c03f3c2 */
if(!s->budget--) { s->failed_pc=0x0c03f3c2u; return 0; }
tmp=read(ram,r[13],4);
r[4]=tmp;
goto P_0c03f3c4;
P_0c03f3c4: /* original 2448, guest PC 0x0c03f3c4 */
if(!s->budget--) { s->failed_pc=0x0c03f3c4u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c03f3c6;
P_0c03f3c6: /* original 8bc8, guest PC 0x0c03f3c6 */
if(!s->budget--) { s->failed_pc=0x0c03f3c6u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c03f35a; }
goto P_0c03f3c8;
P_0c03f3c8: /* original 60c3, guest PC 0x0c03f3c8 */
if(!s->budget--) { s->failed_pc=0x0c03f3c8u; return 0; }
r[0]=r[12];
goto P_0c03f3ca;
P_0c03f3ca: /* original 4f26, guest PC 0x0c03f3ca */
if(!s->budget--) { s->failed_pc=0x0c03f3cau; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c03f3cc;
P_0c03f3cc: /* original 68f6, guest PC 0x0c03f3cc */
if(!s->budget--) { s->failed_pc=0x0c03f3ccu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c03f3ce;
P_0c03f3ce: /* original 69f6, guest PC 0x0c03f3ce */
if(!s->budget--) { s->failed_pc=0x0c03f3ceu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c03f3d0;
P_0c03f3d0: /* original 6af6, guest PC 0x0c03f3d0 */
if(!s->budget--) { s->failed_pc=0x0c03f3d0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c03f3d2;
P_0c03f3d2: /* original 6bf6, guest PC 0x0c03f3d2 */
if(!s->budget--) { s->failed_pc=0x0c03f3d2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c03f3d4;
P_0c03f3d4: /* original 6cf6, guest PC 0x0c03f3d4 */
if(!s->budget--) { s->failed_pc=0x0c03f3d4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c03f3d6;
P_0c03f3d6: /* original 6df6, guest PC 0x0c03f3d6 */
if(!s->budget--) { s->failed_pc=0x0c03f3d6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c03f3d8;
P_0c03f3d8: /* original 000b, guest PC 0x0c03f3d8 */
if(!s->budget--) { s->failed_pc=0x0c03f3d8u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c03f3da: /* original 6ef6, guest PC 0x0c03f3da */
if(!s->budget--) { s->failed_pc=0x0c03f3dau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c03f3dcu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c03f3dcu; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
