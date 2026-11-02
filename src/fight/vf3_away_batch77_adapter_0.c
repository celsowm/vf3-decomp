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
int vf3_away_batch77_adapter_0(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
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
case 0x0c0371ecu: goto P_0c0371ec;
case 0x0c0371eeu: goto P_0c0371ee;
case 0x0c0371f0u: goto P_0c0371f0;
case 0x0c0371f2u: goto P_0c0371f2;
case 0x0c0371f4u: goto P_0c0371f4;
case 0x0c0371f6u: goto P_0c0371f6;
case 0x0c0371f8u: goto P_0c0371f8;
case 0x0c0371fau: goto P_0c0371fa;
case 0x0c0371fcu: goto P_0c0371fc;
case 0x0c037240u: goto P_0c037240;
case 0x0c037242u: goto P_0c037242;
case 0x0c037244u: goto P_0c037244;
case 0x0c037246u: goto P_0c037246;
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
case 0x0c03a140u: goto P_0c03a140;
case 0x0c03a142u: goto P_0c03a142;
case 0x0c03a144u: goto P_0c03a144;
case 0x0c03a146u: goto P_0c03a146;
case 0x0c03a148u: goto P_0c03a148;
case 0x0c03a14au: goto P_0c03a14a;
case 0x0c03a14cu: goto P_0c03a14c;
case 0x0c03a14eu: goto P_0c03a14e;
case 0x0c03a150u: goto P_0c03a150;
case 0x0c03a152u: goto P_0c03a152;
case 0x0c03a154u: goto P_0c03a154;
case 0x0c03a156u: goto P_0c03a156;
case 0x0c03a6e0u: goto P_0c03a6e0;
case 0x0c03a6e2u: goto P_0c03a6e2;
case 0x0c03a6e4u: goto P_0c03a6e4;
case 0x0c03a6e6u: goto P_0c03a6e6;
case 0x0c03a6e8u: goto P_0c03a6e8;
case 0x0c03a6eau: goto P_0c03a6ea;
case 0x0c03a6ecu: goto P_0c03a6ec;
case 0x0c03a6eeu: goto P_0c03a6ee;
case 0x0c03a6f0u: goto P_0c03a6f0;
case 0x0c03a6f2u: goto P_0c03a6f2;
case 0x0c03a6f4u: goto P_0c03a6f4;
case 0x0c03a6f6u: goto P_0c03a6f6;
case 0x0c03a6f8u: goto P_0c03a6f8;
case 0x0c03a6fau: goto P_0c03a6fa;
case 0x0c03a6fcu: goto P_0c03a6fc;
case 0x0c03a6feu: goto P_0c03a6fe;
case 0x0c03a700u: goto P_0c03a700;
case 0x0c03a702u: goto P_0c03a702;
case 0x0c03a704u: goto P_0c03a704;
case 0x0c03a706u: goto P_0c03a706;
case 0x0c03a708u: goto P_0c03a708;
case 0x0c03a70au: goto P_0c03a70a;
case 0x0c03a70cu: goto P_0c03a70c;
case 0x0c03a70eu: goto P_0c03a70e;
case 0x0c03a710u: goto P_0c03a710;
case 0x0c03a712u: goto P_0c03a712;
case 0x0c03a714u: goto P_0c03a714;
case 0x0c03a716u: goto P_0c03a716;
case 0x0c03a718u: goto P_0c03a718;
case 0x0c03a71au: goto P_0c03a71a;
case 0x0c03a71cu: goto P_0c03a71c;
case 0x0c03a71eu: goto P_0c03a71e;
case 0x0c03a720u: goto P_0c03a720;
case 0x0c03a722u: goto P_0c03a722;
case 0x0c03a724u: goto P_0c03a724;
case 0x0c03a726u: goto P_0c03a726;
case 0x0c03a728u: goto P_0c03a728;
case 0x0c03a72au: goto P_0c03a72a;
case 0x0c03a72cu: goto P_0c03a72c;
case 0x0c03a72eu: goto P_0c03a72e;
case 0x0c03a730u: goto P_0c03a730;
case 0x0c03a732u: goto P_0c03a732;
case 0x0c03a734u: goto P_0c03a734;
case 0x0c03a736u: goto P_0c03a736;
case 0x0c03a738u: goto P_0c03a738;
case 0x0c03a73au: goto P_0c03a73a;
case 0x0c03a73cu: goto P_0c03a73c;
case 0x0c03a73eu: goto P_0c03a73e;
case 0x0c03a740u: goto P_0c03a740;
case 0x0c03a742u: goto P_0c03a742;
case 0x0c03a744u: goto P_0c03a744;
case 0x0c03a746u: goto P_0c03a746;
case 0x0c03a748u: goto P_0c03a748;
case 0x0c03a74au: goto P_0c03a74a;
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
P_0c0371ec: /* original d312, guest PC 0x0c0371ec */
if(!s->budget--) { s->failed_pc=0x0c0371ecu; return 0; }
r[3]=read(ram,0x0c037238u,4);
goto P_0c0371ee;
P_0c0371ee: /* original 432b, guest PC 0x0c0371ee */
if(!s->budget--) { s->failed_pc=0x0c0371eeu; return 0; }
target=r[3];
r[4]=0x00000000u;
code_base=target&0xff000000u;
switch(target&0x1fffffffu) {
case 0x0c046aeeu: return vf3_matrix_family(0x0c046aeeu,s,ram);
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
P_0c0371f0: /* original e400, guest PC 0x0c0371f0 */
if(!s->budget--) { s->failed_pc=0x0c0371f0u; return 0; }
r[4]=0x00000000u;
goto P_0c0371f2;
P_0c0371f2: /* original d312, guest PC 0x0c0371f2 */
if(!s->budget--) { s->failed_pc=0x0c0371f2u; return 0; }
r[3]=read(ram,0x0c03723cu,4);
goto P_0c0371f4;
P_0c0371f4: /* original 432b, guest PC 0x0c0371f4 */
if(!s->budget--) { s->failed_pc=0x0c0371f4u; return 0; }
target=r[3];
r[4]=0x00000000u;
code_base=target&0xff000000u;
switch(target&0x1fffffffu) {
case 0x0c046b08u: return vf3_matrix_family(0x0c046b08u,s,ram);
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
P_0c0371f6: /* original e400, guest PC 0x0c0371f6 */
if(!s->budget--) { s->failed_pc=0x0c0371f6u; return 0; }
r[4]=0x00000000u;
goto P_0c0371f8;
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
P_0c03a140: /* original 2fe6, guest PC 0x0c03a140 */
if(!s->budget--) { s->failed_pc=0x0c03a140u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03a142;
P_0c03a142: /* original 6e4d, guest PC 0x0c03a142 */
if(!s->budget--) { s->failed_pc=0x0c03a142u; return 0; }
r[14]=r[4]&65535u;
goto P_0c03a144;
P_0c03a144: /* original d337, guest PC 0x0c03a144 */
if(!s->budget--) { s->failed_pc=0x0c03a144u; return 0; }
r[3]=read(ram,0x0c03a224u,4);
goto P_0c03a146;
P_0c03a146: /* original 3e37, guest PC 0x0c03a146 */
if(!s->budget--) { s->failed_pc=0x0c03a146u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[14]>(int32_t)r[3])!=0);
goto P_0c03a148;
P_0c03a148: /* original 8b02, guest PC 0x0c03a148 */
if(!s->budget--) { s->failed_pc=0x0c03a148u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c03a150; }
goto P_0c03a14a;
P_0c03a14a: /* original d137, guest PC 0x0c03a14a */
if(!s->budget--) { s->failed_pc=0x0c03a14au; return 0; }
r[1]=read(ram,0x0c03a228u,4);
goto P_0c03a14c;
P_0c03a14c: /* original 31e8, guest PC 0x0c03a14c */
if(!s->budget--) { s->failed_pc=0x0c03a14cu; return 0; }
r[1]-=r[14];
goto P_0c03a14e;
P_0c03a14e: /* original 6e13, guest PC 0x0c03a14e */
if(!s->budget--) { s->failed_pc=0x0c03a14eu; return 0; }
r[14]=r[1];
goto P_0c03a150;
P_0c03a150: /* original 9466, guest PC 0x0c03a150 */
if(!s->budget--) { s->failed_pc=0x0c03a150u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c03a220u,2);
goto P_0c03a152;
P_0c03a152: /* original 34e8, guest PC 0x0c03a152 */
if(!s->budget--) { s->failed_pc=0x0c03a152u; return 0; }
r[4]-=r[14];
goto P_0c03a154;
P_0c03a154: /* original a2c4, guest PC 0x0c03a154 */
if(!s->budget--) { s->failed_pc=0x0c03a154u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c03a6e0;
P_0c03a156: /* original 6ef6, guest PC 0x0c03a156 */
if(!s->budget--) { s->failed_pc=0x0c03a156u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c03a158u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c03a158u; return 0; } return 1;
P_0c03a6e0: /* original 644d, guest PC 0x0c03a6e0 */
if(!s->budget--) { s->failed_pc=0x0c03a6e0u; return 0; }
r[4]=r[4]&65535u;
goto P_0c03a6e2;
P_0c03a6e2: /* original 445a, guest PC 0x0c03a6e2 */
if(!s->budget--) { s->failed_pc=0x0c03a6e2u; return 0; }
r[53]=r[4];
goto P_0c03a6e4;
P_0c03a6e4: /* original c78d, guest PC 0x0c03a6e4 */
if(!s->budget--) { s->failed_pc=0x0c03a6e4u; return 0; }
r[0]=code_base|0x0003a91cu;
goto P_0c03a6e6;
P_0c03a6e6: /* original f708, guest PC 0x0c03a6e6 */
if(!s->budget--) { s->failed_pc=0x0c03a6e6u; return 0; }
vf3_matrix_load(s,ram,7,r[0]);
goto P_0c03a6e8;
P_0c03a6e8: /* original c78d, guest PC 0x0c03a6e8 */
if(!s->budget--) { s->failed_pc=0x0c03a6e8u; return 0; }
r[0]=code_base|0x0003a920u;
goto P_0c03a6ea;
P_0c03a6ea: /* original f208, guest PC 0x0c03a6ea */
if(!s->budget--) { s->failed_pc=0x0c03a6eau; return 0; }
vf3_matrix_load(s,ram,2,r[0]);
goto P_0c03a6ec;
P_0c03a6ec: /* original c78d, guest PC 0x0c03a6ec */
if(!s->budget--) { s->failed_pc=0x0c03a6ecu; return 0; }
r[0]=code_base|0x0003a924u;
goto P_0c03a6ee;
P_0c03a6ee: /* original f32d, guest PC 0x0c03a6ee */
if(!s->budget--) { s->failed_pc=0x0c03a6eeu; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c03a6f0;
P_0c03a6f0: /* original f108, guest PC 0x0c03a6f0 */
if(!s->budget--) { s->failed_pc=0x0c03a6f0u; return 0; }
vf3_matrix_load(s,ram,1,r[0]);
goto P_0c03a6f2;
P_0c03a6f2: /* original c78d, guest PC 0x0c03a6f2 */
if(!s->budget--) { s->failed_pc=0x0c03a6f2u; return 0; }
r[0]=code_base|0x0003a928u;
goto P_0c03a6f4;
P_0c03a6f4: /* original f508, guest PC 0x0c03a6f4 */
if(!s->budget--) { s->failed_pc=0x0c03a6f4u; return 0; }
vf3_matrix_load(s,ram,5,r[0]);
goto P_0c03a6f6;
P_0c03a6f6: /* original c78d, guest PC 0x0c03a6f6 */
if(!s->budget--) { s->failed_pc=0x0c03a6f6u; return 0; }
r[0]=code_base|0x0003a92cu;
goto P_0c03a6f8;
P_0c03a6f8: /* original f008, guest PC 0x0c03a6f8 */
if(!s->budget--) { s->failed_pc=0x0c03a6f8u; return 0; }
vf3_matrix_load(s,ram,0,r[0]);
goto P_0c03a6fa;
P_0c03a6fa: /* original e40b, guest PC 0x0c03a6fa */
if(!s->budget--) { s->failed_pc=0x0c03a6fau; return 0; }
r[4]=0x0000000bu;
goto P_0c03a6fc;
P_0c03a6fc: /* original e503, guest PC 0x0c03a6fc */
if(!s->budget--) { s->failed_pc=0x0c03a6fcu; return 0; }
r[5]=0x00000003u;
goto P_0c03a6fe;
P_0c03a6fe: /* original f322, guest PC 0x0c03a6fe */
if(!s->budget--) { s->failed_pc=0x0c03a6feu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[2],r[18],'*');
goto P_0c03a700;
P_0c03a700: /* original f313, guest PC 0x0c03a700 */
if(!s->budget--) { s->failed_pc=0x0c03a700u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[1],r[18],'/');
goto P_0c03a702;
P_0c03a702: /* original f43c, guest PC 0x0c03a702 */
if(!s->budget--) { s->failed_pc=0x0c03a702u; return 0; }
vf3_matrix_move(s,4,3);
goto P_0c03a704;
P_0c03a704: /* original f473, guest PC 0x0c03a704 */
if(!s->budget--) { s->failed_pc=0x0c03a704u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[7],r[18],'/');
goto P_0c03a706;
P_0c03a706: /* original f34c, guest PC 0x0c03a706 */
if(!s->budget--) { s->failed_pc=0x0c03a706u; return 0; }
vf3_matrix_move(s,3,4);
goto P_0c03a708;
P_0c03a708: /* original f353, guest PC 0x0c03a708 */
if(!s->budget--) { s->failed_pc=0x0c03a708u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[5],r[18],'/');
goto P_0c03a70a;
P_0c03a70a: /* original f300, guest PC 0x0c03a70a */
if(!s->budget--) { s->failed_pc=0x0c03a70au; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[0],r[18],'+');
goto P_0c03a70c;
P_0c03a70c: /* original f33d, guest PC 0x0c03a70c */
if(!s->budget--) { s->failed_pc=0x0c03a70cu; return 0; }
r[53]=truncate_float(fr[3]);
goto P_0c03a70e;
P_0c03a70e: /* original 065a, guest PC 0x0c03a70e */
if(!s->budget--) { s->failed_pc=0x0c03a70eu; return 0; }
r[6]=r[53];
goto P_0c03a710;
P_0c03a710: /* original 465a, guest PC 0x0c03a710 */
if(!s->budget--) { s->failed_pc=0x0c03a710u; return 0; }
r[53]=r[6];
goto P_0c03a712;
P_0c03a712: /* original f32d, guest PC 0x0c03a712 */
if(!s->budget--) { s->failed_pc=0x0c03a712u; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c03a714;
P_0c03a714: /* original f352, guest PC 0x0c03a714 */
if(!s->budget--) { s->failed_pc=0x0c03a714u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[5],r[18],'*');
goto P_0c03a716;
P_0c03a716: /* original f58d, guest PC 0x0c03a716 */
if(!s->budget--) { s->failed_pc=0x0c03a716u; return 0; }
fr[5]=0;
goto P_0c03a718;
P_0c03a718: /* original f431, guest PC 0x0c03a718 */
if(!s->budget--) { s->failed_pc=0x0c03a718u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'-');
goto P_0c03a71a;
P_0c03a71a: /* original f64c, guest PC 0x0c03a71a */
if(!s->budget--) { s->failed_pc=0x0c03a71au; return 0; }
vf3_matrix_move(s,6,4);
goto P_0c03a71c;
P_0c03a71c: /* original f642, guest PC 0x0c03a71c */
if(!s->budget--) { s->failed_pc=0x0c03a71cu; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[4],r[18],'*');
goto P_0c03a71e;
P_0c03a71e: /* original 445a, guest PC 0x0c03a71e */
if(!s->budget--) { s->failed_pc=0x0c03a71eu; return 0; }
r[53]=r[4];
goto P_0c03a720;
P_0c03a720: /* original 74fe, guest PC 0x0c03a720 */
if(!s->budget--) { s->failed_pc=0x0c03a720u; return 0; }
r[4]+=0xfffffffeu;
goto P_0c03a722;
P_0c03a722: /* original 3453, guest PC 0x0c03a722 */
if(!s->budget--) { s->failed_pc=0x0c03a722u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=(int32_t)r[5])!=0);
goto P_0c03a724;
P_0c03a724: /* original f22d, guest PC 0x0c03a724 */
if(!s->budget--) { s->failed_pc=0x0c03a724u; return 0; }
fr[2]=vf3_fpu_float(r[53],r[18]);
goto P_0c03a726;
P_0c03a726: /* original f251, guest PC 0x0c03a726 */
if(!s->budget--) { s->failed_pc=0x0c03a726u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'-');
goto P_0c03a728;
P_0c03a728: /* original f56c, guest PC 0x0c03a728 */
if(!s->budget--) { s->failed_pc=0x0c03a728u; return 0; }
vf3_matrix_move(s,5,6);
goto P_0c03a72a;
P_0c03a72a: /* original 8df8, guest PC 0x0c03a72a */
if(!s->budget--) { s->failed_pc=0x0c03a72au; return 0; }
cond=r[17]&1u;
fr[5]=vf3_fpu_binary(fr[5],fr[2],r[18],'/');
if(cond) { goto P_0c03a71e; }
goto P_0c03a72e;
P_0c03a72c: /* original f523, guest PC 0x0c03a72c */
if(!s->budget--) { s->failed_pc=0x0c03a72cu; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[2],r[18],'/');
goto P_0c03a72e;
P_0c03a72e: /* original f69d, guest PC 0x0c03a72e */
if(!s->budget--) { s->failed_pc=0x0c03a72eu; return 0; }
fr[6]=0x3f800000u;
goto P_0c03a730;
P_0c03a730: /* original e301, guest PC 0x0c03a730 */
if(!s->budget--) { s->failed_pc=0x0c03a730u; return 0; }
r[3]=0x00000001u;
goto P_0c03a732;
P_0c03a732: /* original f36c, guest PC 0x0c03a732 */
if(!s->budget--) { s->failed_pc=0x0c03a732u; return 0; }
vf3_matrix_move(s,3,6);
goto P_0c03a734;
P_0c03a734: /* original f351, guest PC 0x0c03a734 */
if(!s->budget--) { s->failed_pc=0x0c03a734u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[5],r[18],'-');
goto P_0c03a736;
P_0c03a736: /* original 2638, guest PC 0x0c03a736 */
if(!s->budget--) { s->failed_pc=0x0c03a736u; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[3])==0)!=0);
goto P_0c03a738;
P_0c03a738: /* original f433, guest PC 0x0c03a738 */
if(!s->budget--) { s->failed_pc=0x0c03a738u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'/');
goto P_0c03a73a;
P_0c03a73a: /* original f24c, guest PC 0x0c03a73a */
if(!s->budget--) { s->failed_pc=0x0c03a73au; return 0; }
vf3_matrix_move(s,2,4);
goto P_0c03a73c;
P_0c03a73c: /* original f272, guest PC 0x0c03a73c */
if(!s->budget--) { s->failed_pc=0x0c03a73cu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[7],r[18],'*');
goto P_0c03a73e;
P_0c03a73e: /* original f04c, guest PC 0x0c03a73e */
if(!s->budget--) { s->failed_pc=0x0c03a73eu; return 0; }
vf3_matrix_move(s,0,4);
goto P_0c03a740;
P_0c03a740: /* original f64e, guest PC 0x0c03a740 */
if(!s->budget--) { s->failed_pc=0x0c03a740u; return 0; }
fr[6]=vf3_fpu_mac(fr[0],fr[4],fr[6],r[18]);
goto P_0c03a742;
P_0c03a742: /* original f42c, guest PC 0x0c03a742 */
if(!s->budget--) { s->failed_pc=0x0c03a742u; return 0; }
vf3_matrix_move(s,4,2);
goto P_0c03a744;
P_0c03a744: /* original 8f04, guest PC 0x0c03a744 */
if(!s->budget--) { s->failed_pc=0x0c03a744u; return 0; }
cond=r[17]&1u;
fr[4]=vf3_fpu_binary(fr[4],fr[6],r[18],'/');
if(!cond) { return vf3_matrix_family(0x0c03a750u,s,ram); }
goto P_0c03a748;
P_0c03a746: /* original f463, guest PC 0x0c03a746 */
if(!s->budget--) { s->failed_pc=0x0c03a746u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[6],r[18],'/');
goto P_0c03a748;
P_0c03a748: /* original 000b, guest PC 0x0c03a748 */
if(!s->budget--) { s->failed_pc=0x0c03a748u; return 0; }
target=r[16];
vf3_matrix_move(s,0,4);
s->pc=target; return ram->oob==0;
P_0c03a74a: /* original f04c, guest PC 0x0c03a74a */
if(!s->budget--) { s->failed_pc=0x0c03a74au; return 0; }
vf3_matrix_move(s,0,4);
if(!vf3_matrix_family(0x0c03a74cu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c03a74cu; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
