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
int vf3_away_batch193_adapter_0(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
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
case 0x0c042460u: goto P_0c042460;
case 0x0c042462u: goto P_0c042462;
case 0x0c042464u: goto P_0c042464;
case 0x0c042466u: goto P_0c042466;
case 0x0c042468u: goto P_0c042468;
case 0x0c04246au: goto P_0c04246a;
case 0x0c04246cu: goto P_0c04246c;
case 0x0c04246eu: goto P_0c04246e;
case 0x0c042490u: goto P_0c042490;
case 0x0c042492u: goto P_0c042492;
case 0x0c042494u: goto P_0c042494;
case 0x0c042496u: goto P_0c042496;
case 0x0c042498u: goto P_0c042498;
case 0x0c04249au: goto P_0c04249a;
case 0x0c04249cu: goto P_0c04249c;
case 0x0c04249eu: goto P_0c04249e;
case 0x0c0424a0u: goto P_0c0424a0;
case 0x0c0424a2u: goto P_0c0424a2;
case 0x0c0424a4u: goto P_0c0424a4;
case 0x0c0424a6u: goto P_0c0424a6;
case 0x0c0424a8u: goto P_0c0424a8;
case 0x0c0424aau: goto P_0c0424aa;
case 0x0c0424acu: goto P_0c0424ac;
case 0x0c0424aeu: goto P_0c0424ae;
case 0x0c0424b0u: goto P_0c0424b0;
case 0x0c0424b2u: goto P_0c0424b2;
case 0x0c0424b4u: goto P_0c0424b4;
case 0x0c0424b6u: goto P_0c0424b6;
case 0x0c0424d0u: goto P_0c0424d0;
case 0x0c0424d2u: goto P_0c0424d2;
case 0x0c0424d4u: goto P_0c0424d4;
case 0x0c0424d6u: goto P_0c0424d6;
case 0x0c0424d8u: goto P_0c0424d8;
case 0x0c0424dau: goto P_0c0424da;
case 0x0c0424dcu: goto P_0c0424dc;
case 0x0c0424deu: goto P_0c0424de;
case 0x0c0424e0u: goto P_0c0424e0;
case 0x0c0424e2u: goto P_0c0424e2;
case 0x0c0424e4u: goto P_0c0424e4;
case 0x0c0424e6u: goto P_0c0424e6;
case 0x0c0424e8u: goto P_0c0424e8;
case 0x0c0424eau: goto P_0c0424ea;
case 0x0c0424ecu: goto P_0c0424ec;
case 0x0c0424eeu: goto P_0c0424ee;
case 0x0c0424f0u: goto P_0c0424f0;
case 0x0c0424f2u: goto P_0c0424f2;
case 0x0c0424f4u: goto P_0c0424f4;
case 0x0c0424f6u: goto P_0c0424f6;
case 0x0c0424f8u: goto P_0c0424f8;
case 0x0c0424fau: goto P_0c0424fa;
case 0x0c0424fcu: goto P_0c0424fc;
case 0x0c0424feu: goto P_0c0424fe;
case 0x0c042500u: goto P_0c042500;
case 0x0c042502u: goto P_0c042502;
case 0x0c042504u: goto P_0c042504;
case 0x0c042506u: goto P_0c042506;
case 0x0c042508u: goto P_0c042508;
case 0x0c04250au: goto P_0c04250a;
case 0x0c04250cu: goto P_0c04250c;
case 0x0c04250eu: goto P_0c04250e;
case 0x0c042510u: goto P_0c042510;
case 0x0c042512u: goto P_0c042512;
case 0x0c042514u: goto P_0c042514;
case 0x0c042516u: goto P_0c042516;
case 0x0c042518u: goto P_0c042518;
case 0x0c04251au: goto P_0c04251a;
case 0x0c04251cu: goto P_0c04251c;
case 0x0c04251eu: goto P_0c04251e;
case 0x0c042520u: goto P_0c042520;
case 0x0c042522u: goto P_0c042522;
case 0x0c042524u: goto P_0c042524;
case 0x0c042526u: goto P_0c042526;
case 0x0c042528u: goto P_0c042528;
case 0x0c04252au: goto P_0c04252a;
case 0x0c04252cu: goto P_0c04252c;
case 0x0c04252eu: goto P_0c04252e;
case 0x0c042530u: goto P_0c042530;
case 0x0c042532u: goto P_0c042532;
case 0x0c042534u: goto P_0c042534;
case 0x0c042536u: goto P_0c042536;
case 0x0c042538u: goto P_0c042538;
case 0x0c04253au: goto P_0c04253a;
case 0x0c04253cu: goto P_0c04253c;
case 0x0c04253eu: goto P_0c04253e;
case 0x0c042540u: goto P_0c042540;
case 0x0c042542u: goto P_0c042542;
case 0x0c042544u: goto P_0c042544;
case 0x0c042546u: goto P_0c042546;
case 0x0c042548u: goto P_0c042548;
case 0x0c04254au: goto P_0c04254a;
case 0x0c04254cu: goto P_0c04254c;
case 0x0c04254eu: goto P_0c04254e;
case 0x0c042550u: goto P_0c042550;
case 0x0c042552u: goto P_0c042552;
case 0x0c042554u: goto P_0c042554;
case 0x0c042556u: goto P_0c042556;
case 0x0c042558u: goto P_0c042558;
case 0x0c04255au: goto P_0c04255a;
case 0x0c04255cu: goto P_0c04255c;
case 0x0c04255eu: goto P_0c04255e;
case 0x0c042560u: goto P_0c042560;
case 0x0c042562u: goto P_0c042562;
case 0x0c042564u: goto P_0c042564;
case 0x0c042566u: goto P_0c042566;
case 0x0c042568u: goto P_0c042568;
case 0x0c04256au: goto P_0c04256a;
case 0x0c04256cu: goto P_0c04256c;
case 0x0c04256eu: goto P_0c04256e;
case 0x0c042570u: goto P_0c042570;
case 0x0c042572u: goto P_0c042572;
case 0x0c042574u: goto P_0c042574;
case 0x0c042576u: goto P_0c042576;
case 0x0c042578u: goto P_0c042578;
case 0x0c04257au: goto P_0c04257a;
case 0x0c04257cu: goto P_0c04257c;
case 0x0c04257eu: goto P_0c04257e;
case 0x0c042580u: goto P_0c042580;
case 0x0c042582u: goto P_0c042582;
case 0x0c042584u: goto P_0c042584;
case 0x0c042586u: goto P_0c042586;
case 0x0c042588u: goto P_0c042588;
case 0x0c04258au: goto P_0c04258a;
case 0x0c04258cu: goto P_0c04258c;
case 0x0c04258eu: goto P_0c04258e;
case 0x0c042590u: goto P_0c042590;
case 0x0c042592u: goto P_0c042592;
case 0x0c042594u: goto P_0c042594;
case 0x0c042596u: goto P_0c042596;
case 0x0c042598u: goto P_0c042598;
case 0x0c04259au: goto P_0c04259a;
case 0x0c04259cu: goto P_0c04259c;
case 0x0c04259eu: goto P_0c04259e;
case 0x0c0425a0u: goto P_0c0425a0;
case 0x0c0425a2u: goto P_0c0425a2;
case 0x0c0425a4u: goto P_0c0425a4;
case 0x0c0425a6u: goto P_0c0425a6;
case 0x0c0425a8u: goto P_0c0425a8;
case 0x0c0425aau: goto P_0c0425aa;
case 0x0c0425acu: goto P_0c0425ac;
case 0x0c0425aeu: goto P_0c0425ae;
case 0x0c0425b0u: goto P_0c0425b0;
case 0x0c0425b2u: goto P_0c0425b2;
case 0x0c0425b4u: goto P_0c0425b4;
case 0x0c0425b6u: goto P_0c0425b6;
case 0x0c0425b8u: goto P_0c0425b8;
case 0x0c0425bau: goto P_0c0425ba;
case 0x0c0425bcu: goto P_0c0425bc;
case 0x0c0425beu: goto P_0c0425be;
case 0x0c0425c0u: goto P_0c0425c0;
case 0x0c0425c2u: goto P_0c0425c2;
case 0x0c0425c4u: goto P_0c0425c4;
case 0x0c0425c6u: goto P_0c0425c6;
case 0x0c0425c8u: goto P_0c0425c8;
case 0x0c0425cau: goto P_0c0425ca;
case 0x0c0425ccu: goto P_0c0425cc;
case 0x0c0425ceu: goto P_0c0425ce;
case 0x0c0425d0u: goto P_0c0425d0;
case 0x0c0425d2u: goto P_0c0425d2;
case 0x0c0425d4u: goto P_0c0425d4;
case 0x0c0425d6u: goto P_0c0425d6;
case 0x0c0425d8u: goto P_0c0425d8;
case 0x0c0425dau: goto P_0c0425da;
case 0x0c0425dcu: goto P_0c0425dc;
case 0x0c0425deu: goto P_0c0425de;
case 0x0c0425e0u: goto P_0c0425e0;
case 0x0c0425e2u: goto P_0c0425e2;
case 0x0c0425e4u: goto P_0c0425e4;
case 0x0c0425e6u: goto P_0c0425e6;
case 0x0c0425e8u: goto P_0c0425e8;
case 0x0c0425eau: goto P_0c0425ea;
case 0x0c0425ecu: goto P_0c0425ec;
case 0x0c0425eeu: goto P_0c0425ee;
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
P_0c042460: /* original d207, guest PC 0x0c042460 */
if(!s->budget--) { s->failed_pc=0x0c042460u; return 0; }
r[2]=read(ram,0x0c042480u,4);
goto P_0c042462;
P_0c042462: /* original e303, guest PC 0x0c042462 */
if(!s->budget--) { s->failed_pc=0x0c042462u; return 0; }
r[3]=0x00000003u;
goto P_0c042464;
P_0c042464: /* original 2439, guest PC 0x0c042464 */
if(!s->budget--) { s->failed_pc=0x0c042464u; return 0; }
r[4]&=r[3];
goto P_0c042466;
P_0c042466: /* original 2539, guest PC 0x0c042466 */
if(!s->budget--) { s->failed_pc=0x0c042466u; return 0; }
r[5]&=r[3];
goto P_0c042468;
P_0c042468: /* original 2240, guest PC 0x0c042468 */
if(!s->budget--) { s->failed_pc=0x0c042468u; return 0; }
write(ram,r[2],r[4],1);
goto P_0c04246a;
P_0c04246a: /* original d106, guest PC 0x0c04246a */
if(!s->budget--) { s->failed_pc=0x0c04246au; return 0; }
r[1]=read(ram,0x0c042484u,4);
goto P_0c04246c;
P_0c04246c: /* original 000b, guest PC 0x0c04246c */
if(!s->budget--) { s->failed_pc=0x0c04246cu; return 0; }
target=r[16];
write(ram,r[1],r[5],1);
s->pc=target; return ram->oob==0;
P_0c04246e: /* original 2150, guest PC 0x0c04246e */
if(!s->budget--) { s->failed_pc=0x0c04246eu; return 0; }
write(ram,r[1],r[5],1);
if(!vf3_matrix_family(0x0c042470u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c042470u; return 0; } return 1;
P_0c042490: /* original d30a, guest PC 0x0c042490 */
if(!s->budget--) { s->failed_pc=0x0c042490u; return 0; }
r[3]=read(ram,0x0c0424bcu,4);
goto P_0c042492;
P_0c042492: /* original d20b, guest PC 0x0c042492 */
if(!s->budget--) { s->failed_pc=0x0c042492u; return 0; }
r[2]=read(ram,0x0c0424c0u,4);
goto P_0c042494;
P_0c042494: /* original 6530, guest PC 0x0c042494 */
if(!s->budget--) { s->failed_pc=0x0c042494u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[3],1);
r[5]=tmp;
goto P_0c042496;
P_0c042496: /* original d10b, guest PC 0x0c042496 */
if(!s->budget--) { s->failed_pc=0x0c042496u; return 0; }
r[1]=read(ram,0x0c0424c4u,4);
goto P_0c042498;
P_0c042498: /* original 4f12, guest PC 0x0c042498 */
if(!s->budget--) { s->failed_pc=0x0c042498u; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c04249a;
P_0c04249a: /* original 0527, guest PC 0x0c04249a */
if(!s->budget--) { s->failed_pc=0x0c04249au; return 0; }
r[19]=r[5]*r[2];
goto P_0c04249c;
P_0c04249c: /* original 6412, guest PC 0x0c04249c */
if(!s->budget--) { s->failed_pc=0x0c04249cu; return 0; }
tmp=read(ram,r[1],4);
r[4]=tmp;
goto P_0c04249e;
P_0c04249e: /* original 2448, guest PC 0x0c04249e */
if(!s->budget--) { s->failed_pc=0x0c04249eu; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c0424a0;
P_0c0424a0: /* original 8d08, guest PC 0x0c0424a0 */
if(!s->budget--) { s->failed_pc=0x0c0424a0u; return 0; }
cond=r[17]&1u;
r[5]=r[19];
if(cond) { goto P_0c0424b4; }
goto P_0c0424a4;
P_0c0424a2: /* original 051a, guest PC 0x0c0424a2 */
if(!s->budget--) { s->failed_pc=0x0c0424a2u; return 0; }
r[5]=r[19];
goto P_0c0424a4;
P_0c0424a4: /* original 9608, guest PC 0x0c0424a4 */
if(!s->budget--) { s->failed_pc=0x0c0424a4u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0424b8u,2);
goto P_0c0424a6;
P_0c0424a6: /* original 364c, guest PC 0x0c0424a6 */
if(!s->budget--) { s->failed_pc=0x0c0424a6u; return 0; }
r[6]+=r[4];
goto P_0c0424a8;
P_0c0424a8: /* original d407, guest PC 0x0c0424a8 */
if(!s->budget--) { s->failed_pc=0x0c0424a8u; return 0; }
r[4]=read(ram,0x0c0424c8u,4);
goto P_0c0424aa;
P_0c0424aa: /* original 74ff, guest PC 0x0c0424aa */
if(!s->budget--) { s->failed_pc=0x0c0424aau; return 0; }
r[4]+=0xffffffffu;
goto P_0c0424ac;
P_0c0424ac: /* original 2652, guest PC 0x0c0424ac */
if(!s->budget--) { s->failed_pc=0x0c0424acu; return 0; }
write(ram,r[6],r[5],4);
goto P_0c0424ae;
P_0c0424ae: /* original 4411, guest PC 0x0c0424ae */
if(!s->budget--) { s->failed_pc=0x0c0424aeu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=0)!=0);
goto P_0c0424b0;
P_0c0424b0: /* original 8dfb, guest PC 0x0c0424b0 */
if(!s->budget--) { s->failed_pc=0x0c0424b0u; return 0; }
cond=r[17]&1u;
r[6]+=0x00000004u;
if(cond) { goto P_0c0424aa; }
goto P_0c0424b4;
P_0c0424b2: /* original 7604, guest PC 0x0c0424b2 */
if(!s->budget--) { s->failed_pc=0x0c0424b2u; return 0; }
r[6]+=0x00000004u;
goto P_0c0424b4;
P_0c0424b4: /* original 000b, guest PC 0x0c0424b4 */
if(!s->budget--) { s->failed_pc=0x0c0424b4u; return 0; }
target=r[16];
r[19]=read(ram,r[15],4); r[15]+=4;
s->pc=target; return ram->oob==0;
P_0c0424b6: /* original 4f16, guest PC 0x0c0424b6 */
if(!s->budget--) { s->failed_pc=0x0c0424b6u; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
if(!vf3_matrix_family(0x0c0424b8u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0424b8u; return 0; } return 1;
P_0c0424d0: /* original 2fe6, guest PC 0x0c0424d0 */
if(!s->budget--) { s->failed_pc=0x0c0424d0u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0424d2;
P_0c0424d2: /* original 2fd6, guest PC 0x0c0424d2 */
if(!s->budget--) { s->failed_pc=0x0c0424d2u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0424d4;
P_0c0424d4: /* original 2fc6, guest PC 0x0c0424d4 */
if(!s->budget--) { s->failed_pc=0x0c0424d4u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0424d6;
P_0c0424d6: /* original d24a, guest PC 0x0c0424d6 */
if(!s->budget--) { s->failed_pc=0x0c0424d6u; return 0; }
r[2]=read(ram,0x0c042600u,4);
goto P_0c0424d8;
P_0c0424d8: /* original 4f22, guest PC 0x0c0424d8 */
if(!s->budget--) { s->failed_pc=0x0c0424d8u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0424da;
P_0c0424da: /* original 6322, guest PC 0x0c0424da */
if(!s->budget--) { s->failed_pc=0x0c0424dau; return 0; }
tmp=read(ram,r[2],4);
r[3]=tmp;
goto P_0c0424dc;
P_0c0424dc: /* original 2338, guest PC 0x0c0424dc */
if(!s->budget--) { s->failed_pc=0x0c0424dcu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c0424de;
P_0c0424de: /* original 8b01, guest PC 0x0c0424de */
if(!s->budget--) { s->failed_pc=0x0c0424deu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0424e4; }
goto P_0c0424e0;
P_0c0424e0: /* original a081, guest PC 0x0c0424e0 */
if(!s->budget--) { s->failed_pc=0x0c0424e0u; return 0; }
goto P_0c0425e6;
P_0c0424e2: /* original 0009, guest PC 0x0c0424e2 */
if(!s->budget--) { s->failed_pc=0x0c0424e2u; return 0; }
goto P_0c0424e4;
P_0c0424e4: /* original d049, guest PC 0x0c0424e4 */
if(!s->budget--) { s->failed_pc=0x0c0424e4u; return 0; }
r[0]=read(ram,0x0c04260cu,4);
goto P_0c0424e6;
P_0c0424e6: /* original d148, guest PC 0x0c0424e6 */
if(!s->budget--) { s->failed_pc=0x0c0424e6u; return 0; }
r[1]=read(ram,0x0c042608u,4);
goto P_0c0424e8;
P_0c0424e8: /* original 6700, guest PC 0x0c0424e8 */
if(!s->budget--) { s->failed_pc=0x0c0424e8u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[0],1);
r[7]=tmp;
goto P_0c0424ea;
P_0c0424ea: /* original e001, guest PC 0x0c0424ea */
if(!s->budget--) { s->failed_pc=0x0c0424eau; return 0; }
r[0]=0x00000001u;
goto P_0c0424ec;
P_0c0424ec: /* original 6312, guest PC 0x0c0424ec */
if(!s->budget--) { s->failed_pc=0x0c0424ecu; return 0; }
tmp=read(ram,r[1],4);
r[3]=tmp;
goto P_0c0424ee;
P_0c0424ee: /* original e11b, guest PC 0x0c0424ee */
if(!s->budget--) { s->failed_pc=0x0c0424eeu; return 0; }
r[1]=0x0000001bu;
goto P_0c0424f0;
P_0c0424f0: /* original 6273, guest PC 0x0c0424f0 */
if(!s->budget--) { s->failed_pc=0x0c0424f0u; return 0; }
r[2]=r[7];
goto P_0c0424f2;
P_0c0424f2: /* original 4708, guest PC 0x0c0424f2 */
if(!s->budget--) { s->failed_pc=0x0c0424f2u; return 0; }
r[7]<<=2;
goto P_0c0424f4;
P_0c0424f4: /* original 372c, guest PC 0x0c0424f4 */
if(!s->budget--) { s->failed_pc=0x0c0424f4u; return 0; }
r[7]+=r[2];
goto P_0c0424f6;
P_0c0424f6: /* original 5632, guest PC 0x0c0424f6 */
if(!s->budget--) { s->failed_pc=0x0c0424f6u; return 0; }
r[6]=read(ram,r[3]+8,4);
goto P_0c0424f8;
P_0c0424f8: /* original 4708, guest PC 0x0c0424f8 */
if(!s->budget--) { s->failed_pc=0x0c0424f8u; return 0; }
r[7]<<=2;
goto P_0c0424fa;
P_0c0424fa: /* original d345, guest PC 0x0c0424fa */
if(!s->budget--) { s->failed_pc=0x0c0424fau; return 0; }
r[3]=read(ram,0x0c042610u,4);
goto P_0c0424fc;
P_0c0424fc: /* original 4700, guest PC 0x0c0424fc */
if(!s->budget--) { s->failed_pc=0x0c0424fcu; return 0; }
r[17]=(r[17]&~1u)|((r[7]>>31)!=0);
r[7]<<=1;
goto P_0c0424fe;
P_0c0424fe: /* original d441, guest PC 0x0c0424fe */
if(!s->budget--) { s->failed_pc=0x0c0424feu; return 0; }
r[4]=read(ram,0x0c042604u,4);
goto P_0c042500;
P_0c042500: /* original 677e, guest PC 0x0c042500 */
if(!s->budget--) { s->failed_pc=0x0c042500u; return 0; }
r[7]=(uint32_t)(int32_t)(int8_t)r[7];
goto P_0c042502;
P_0c042502: /* original 373c, guest PC 0x0c042502 */
if(!s->budget--) { s->failed_pc=0x0c042502u; return 0; }
r[7]+=r[3];
goto P_0c042504;
P_0c042504: /* original 5576, guest PC 0x0c042504 */
if(!s->budget--) { s->failed_pc=0x0c042504u; return 0; }
r[5]=read(ram,r[7]+24,4);
goto P_0c042506;
P_0c042506: /* original e208, guest PC 0x0c042506 */
if(!s->budget--) { s->failed_pc=0x0c042506u; return 0; }
r[2]=0x00000008u;
goto P_0c042508;
P_0c042508: /* original 5372, guest PC 0x0c042508 */
if(!s->budget--) { s->failed_pc=0x0c042508u; return 0; }
r[3]=read(ram,r[7]+8,4);
goto P_0c04250a;
P_0c04250a: /* original 2059, guest PC 0x0c04250a */
if(!s->budget--) { s->failed_pc=0x0c04250au; return 0; }
r[0]&=r[5];
goto P_0c04250c;
P_0c04250c: /* original 2259, guest PC 0x0c04250c */
if(!s->budget--) { s->failed_pc=0x0c04250cu; return 0; }
r[2]&=r[5];
goto P_0c04250e;
P_0c04250e: /* original c901, guest PC 0x0c04250e */
if(!s->budget--) { s->failed_pc=0x0c04250eu; return 0; }
r[0]&=1u;
goto P_0c042510;
P_0c042510: /* original 421d, guest PC 0x0c042510 */
if(!s->budget--) { s->failed_pc=0x0c042510u; return 0; }
r[2]=(r[1]&0x80000000u)?((r[1]&31u)?r[2]>>((-r[1])&31u):0):r[2]<<(r[1]&31u);
goto P_0c042512;
P_0c042512: /* original 4005, guest PC 0x0c042512 */
if(!s->budget--) { s->failed_pc=0x0c042512u; return 0; }
r[17]=(r[17]&~1u)|((r[0]&1u)!=0);
r[0]=(r[0]>>1)|(r[0]<<31);
goto P_0c042514;
P_0c042514: /* original 202b, guest PC 0x0c042514 */
if(!s->budget--) { s->failed_pc=0x0c042514u; return 0; }
r[0]|=r[2];
goto P_0c042516;
P_0c042516: /* original d23f, guest PC 0x0c042516 */
if(!s->budget--) { s->failed_pc=0x0c042516u; return 0; }
r[2]=read(ram,0x0c042614u,4);
goto P_0c042518;
P_0c042518: /* original 2329, guest PC 0x0c042518 */
if(!s->budget--) { s->failed_pc=0x0c042518u; return 0; }
r[3]&=r[2];
goto P_0c04251a;
P_0c04251a: /* original 203b, guest PC 0x0c04251a */
if(!s->budget--) { s->failed_pc=0x0c04251au; return 0; }
r[0]|=r[3];
goto P_0c04251c;
P_0c04251c: /* original 6303, guest PC 0x0c04251c */
if(!s->budget--) { s->failed_pc=0x0c04251cu; return 0; }
r[3]=r[0];
goto P_0c04251e;
P_0c04251e: /* original 6057, guest PC 0x0c04251e */
if(!s->budget--) { s->failed_pc=0x0c04251eu; return 0; }
r[0]=~r[5];
goto P_0c042520;
P_0c042520: /* original c904, guest PC 0x0c042520 */
if(!s->budget--) { s->failed_pc=0x0c042520u; return 0; }
r[0]&=4u;
goto P_0c042522;
P_0c042522: /* original 4028, guest PC 0x0c042522 */
if(!s->budget--) { s->failed_pc=0x0c042522u; return 0; }
r[0]<<=16;
goto P_0c042524;
P_0c042524: /* original 4018, guest PC 0x0c042524 */
if(!s->budget--) { s->failed_pc=0x0c042524u; return 0; }
r[0]<<=8;
goto P_0c042526;
P_0c042526: /* original 230b, guest PC 0x0c042526 */
if(!s->budget--) { s->failed_pc=0x0c042526u; return 0; }
r[3]|=r[0];
goto P_0c042528;
P_0c042528: /* original e010, guest PC 0x0c042528 */
if(!s->budget--) { s->failed_pc=0x0c042528u; return 0; }
r[0]=0x00000010u;
goto P_0c04252a;
P_0c04252a: /* original e215, guest PC 0x0c04252a */
if(!s->budget--) { s->failed_pc=0x0c04252au; return 0; }
r[2]=0x00000015u;
goto P_0c04252c;
P_0c04252c: /* original 2059, guest PC 0x0c04252c */
if(!s->budget--) { s->failed_pc=0x0c04252cu; return 0; }
r[0]&=r[5];
goto P_0c04252e;
P_0c04252e: /* original 402d, guest PC 0x0c04252e */
if(!s->budget--) { s->failed_pc=0x0c04252eu; return 0; }
r[0]=(r[2]&0x80000000u)?((r[2]&31u)?r[0]>>((-r[2])&31u):0):r[0]<<(r[2]&31u);
goto P_0c042530;
P_0c042530: /* original 230b, guest PC 0x0c042530 */
if(!s->budget--) { s->failed_pc=0x0c042530u; return 0; }
r[3]|=r[0];
goto P_0c042532;
P_0c042532: /* original 5077, guest PC 0x0c042532 */
if(!s->budget--) { s->failed_pc=0x0c042532u; return 0; }
r[0]=read(ram,r[7]+28,4);
goto P_0c042534;
P_0c042534: /* original 4009, guest PC 0x0c042534 */
if(!s->budget--) { s->failed_pc=0x0c042534u; return 0; }
r[0]>>=2;
goto P_0c042536;
P_0c042536: /* original 4001, guest PC 0x0c042536 */
if(!s->budget--) { s->failed_pc=0x0c042536u; return 0; }
r[17]=(r[17]&~1u)|((r[0]&1)!=0);
r[0]>>=1;
goto P_0c042538;
P_0c042538: /* original 230b, guest PC 0x0c042538 */
if(!s->budget--) { s->failed_pc=0x0c042538u; return 0; }
r[3]|=r[0];
goto P_0c04253a;
P_0c04253a: /* original 1433, guest PC 0x0c04253a */
if(!s->budget--) { s->failed_pc=0x0c04253au; return 0; }
write(ram,r[4]+12,r[3],4);
goto P_0c04253c;
P_0c04253c: /* original 6363, guest PC 0x0c04253c */
if(!s->budget--) { s->failed_pc=0x0c04253cu; return 0; }
r[3]=r[6];
goto P_0c04253e;
P_0c04253e: /* original d036, guest PC 0x0c04253e */
if(!s->budget--) { s->failed_pc=0x0c04253eu; return 0; }
r[0]=read(ram,0x0c042618u,4);
goto P_0c042540;
P_0c042540: /* original 4329, guest PC 0x0c042540 */
if(!s->budget--) { s->failed_pc=0x0c042540u; return 0; }
r[3]>>=16;
goto P_0c042542;
P_0c042542: /* original 4319, guest PC 0x0c042542 */
if(!s->budget--) { s->failed_pc=0x0c042542u; return 0; }
r[3]>>=8;
goto P_0c042544;
P_0c042544: /* original 2032, guest PC 0x0c042544 */
if(!s->budget--) { s->failed_pc=0x0c042544u; return 0; }
write(ram,r[0],r[3],4);
goto P_0c042546;
P_0c042546: /* original d235, guest PC 0x0c042546 */
if(!s->budget--) { s->failed_pc=0x0c042546u; return 0; }
r[2]=read(ram,0x0c04261cu,4);
goto P_0c042548;
P_0c042548: /* original 2232, guest PC 0x0c042548 */
if(!s->budget--) { s->failed_pc=0x0c042548u; return 0; }
write(ram,r[2],r[3],4);
goto P_0c04254a;
P_0c04254a: /* original de35, guest PC 0x0c04254a */
if(!s->budget--) { s->failed_pc=0x0c04254au; return 0; }
r[14]=read(ram,0x0c042620u,4);
goto P_0c04254c;
P_0c04254c: /* original d335, guest PC 0x0c04254c */
if(!s->budget--) { s->failed_pc=0x0c04254cu; return 0; }
r[3]=read(ram,0x0c042624u,4);
goto P_0c04254e;
P_0c04254e: /* original 6242, guest PC 0x0c04254e */
if(!s->budget--) { s->failed_pc=0x0c04254eu; return 0; }
tmp=read(ram,r[4],4);
r[2]=tmp;
goto P_0c042550;
P_0c042550: /* original 2e69, guest PC 0x0c042550 */
if(!s->budget--) { s->failed_pc=0x0c042550u; return 0; }
r[14]&=r[6];
goto P_0c042552;
P_0c042552: /* original 2e3b, guest PC 0x0c042552 */
if(!s->budget--) { s->failed_pc=0x0c042552u; return 0; }
r[14]|=r[3];
goto P_0c042554;
P_0c042554: /* original 2e22, guest PC 0x0c042554 */
if(!s->budget--) { s->failed_pc=0x0c042554u; return 0; }
write(ram,r[14],r[2],4);
goto P_0c042556;
P_0c042556: /* original 5141, guest PC 0x0c042556 */
if(!s->budget--) { s->failed_pc=0x0c042556u; return 0; }
r[1]=read(ram,r[4]+4,4);
goto P_0c042558;
P_0c042558: /* original 1e11, guest PC 0x0c042558 */
if(!s->budget--) { s->failed_pc=0x0c042558u; return 0; }
write(ram,r[14]+4,r[1],4);
goto P_0c04255a;
P_0c04255a: /* original 5242, guest PC 0x0c04255a */
if(!s->budget--) { s->failed_pc=0x0c04255au; return 0; }
r[2]=read(ram,r[4]+8,4);
goto P_0c04255c;
P_0c04255c: /* original 1e22, guest PC 0x0c04255c */
if(!s->budget--) { s->failed_pc=0x0c04255cu; return 0; }
write(ram,r[14]+8,r[2],4);
goto P_0c04255e;
P_0c04255e: /* original 5143, guest PC 0x0c04255e */
if(!s->budget--) { s->failed_pc=0x0c04255eu; return 0; }
r[1]=read(ram,r[4]+12,4);
goto P_0c042560;
P_0c042560: /* original 1e13, guest PC 0x0c042560 */
if(!s->budget--) { s->failed_pc=0x0c042560u; return 0; }
write(ram,r[14]+12,r[1],4);
goto P_0c042562;
P_0c042562: /* original 5244, guest PC 0x0c042562 */
if(!s->budget--) { s->failed_pc=0x0c042562u; return 0; }
r[2]=read(ram,r[4]+16,4);
goto P_0c042564;
P_0c042564: /* original 1e24, guest PC 0x0c042564 */
if(!s->budget--) { s->failed_pc=0x0c042564u; return 0; }
write(ram,r[14]+16,r[2],4);
goto P_0c042566;
P_0c042566: /* original dd30, guest PC 0x0c042566 */
if(!s->budget--) { s->failed_pc=0x0c042566u; return 0; }
r[13]=read(ram,0x0c042628u,4);
goto P_0c042568;
P_0c042568: /* original 4d0b, guest PC 0x0c042568 */
if(!s->budget--) { s->failed_pc=0x0c042568u; return 0; }
target=r[13];
r[16]=code_base|0x0c04256cu;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04256cu) { target=s->pc; goto dispatch; }
goto P_0c04256c;
P_0c04256a: /* original 64e3, guest PC 0x0c04256a */
if(!s->budget--) { s->failed_pc=0x0c04256au; return 0; }
r[4]=r[14];
goto P_0c04256c;
P_0c04256c: /* original c72f, guest PC 0x0c04256c */
if(!s->budget--) { s->failed_pc=0x0c04256cu; return 0; }
r[0]=code_base|0x0004262cu;
goto P_0c04256e;
P_0c04256e: /* original 7e20, guest PC 0x0c04256e */
if(!s->budget--) { s->failed_pc=0x0c04256eu; return 0; }
r[14]+=0x00000020u;
goto P_0c042570;
P_0c042570: /* original e3ff, guest PC 0x0c042570 */
if(!s->budget--) { s->failed_pc=0x0c042570u; return 0; }
r[3]=0xffffffffu;
goto P_0c042572;
P_0c042572: /* original 2e32, guest PC 0x0c042572 */
if(!s->budget--) { s->failed_pc=0x0c042572u; return 0; }
write(ram,r[14],r[3],4);
goto P_0c042574;
P_0c042574: /* original f308, guest PC 0x0c042574 */
if(!s->budget--) { s->failed_pc=0x0c042574u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c042576;
P_0c042576: /* original e004, guest PC 0x0c042576 */
if(!s->budget--) { s->failed_pc=0x0c042576u; return 0; }
r[0]=0x00000004u;
goto P_0c042578;
P_0c042578: /* original fe37, guest PC 0x0c042578 */
if(!s->budget--) { s->failed_pc=0x0c042578u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c04257a;
P_0c04257a: /* original e008, guest PC 0x0c04257a */
if(!s->budget--) { s->failed_pc=0x0c04257au; return 0; }
r[0]=0x00000008u;
goto P_0c04257c;
P_0c04257c: /* original f48d, guest PC 0x0c04257c */
if(!s->budget--) { s->failed_pc=0x0c04257cu; return 0; }
fr[4]=0;
goto P_0c04257e;
P_0c04257e: /* original fe47, guest PC 0x0c04257e */
if(!s->budget--) { s->failed_pc=0x0c04257eu; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c042580;
P_0c042580: /* original e00c, guest PC 0x0c042580 */
if(!s->budget--) { s->failed_pc=0x0c042580u; return 0; }
r[0]=0x0000000cu;
goto P_0c042582;
P_0c042582: /* original dc2b, guest PC 0x0c042582 */
if(!s->budget--) { s->failed_pc=0x0c042582u; return 0; }
r[12]=read(ram,0x0c042630u,4);
goto P_0c042584;
P_0c042584: /* original f3c8, guest PC 0x0c042584 */
if(!s->budget--) { s->failed_pc=0x0c042584u; return 0; }
vf3_matrix_load(s,ram,3,r[12]);
goto P_0c042586;
P_0c042586: /* original fe37, guest PC 0x0c042586 */
if(!s->budget--) { s->failed_pc=0x0c042586u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c042588;
P_0c042588: /* original c72a, guest PC 0x0c042588 */
if(!s->budget--) { s->failed_pc=0x0c042588u; return 0; }
r[0]=code_base|0x00042634u;
goto P_0c04258a;
P_0c04258a: /* original f508, guest PC 0x0c04258a */
if(!s->budget--) { s->failed_pc=0x0c04258au; return 0; }
vf3_matrix_load(s,ram,5,r[0]);
goto P_0c04258c;
P_0c04258c: /* original e010, guest PC 0x0c04258c */
if(!s->budget--) { s->failed_pc=0x0c04258cu; return 0; }
r[0]=0x00000010u;
goto P_0c04258e;
P_0c04258e: /* original fe57, guest PC 0x0c04258e */
if(!s->budget--) { s->failed_pc=0x0c04258eu; return 0; }
vf3_matrix_store(s,ram,5,r[14]+r[0]);
goto P_0c042590;
P_0c042590: /* original e014, guest PC 0x0c042590 */
if(!s->budget--) { s->failed_pc=0x0c042590u; return 0; }
r[0]=0x00000014u;
goto P_0c042592;
P_0c042592: /* original fe47, guest PC 0x0c042592 */
if(!s->budget--) { s->failed_pc=0x0c042592u; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c042594;
P_0c042594: /* original e018, guest PC 0x0c042594 */
if(!s->budget--) { s->failed_pc=0x0c042594u; return 0; }
r[0]=0x00000018u;
goto P_0c042596;
P_0c042596: /* original f3c8, guest PC 0x0c042596 */
if(!s->budget--) { s->failed_pc=0x0c042596u; return 0; }
vf3_matrix_load(s,ram,3,r[12]);
goto P_0c042598;
P_0c042598: /* original fe37, guest PC 0x0c042598 */
if(!s->budget--) { s->failed_pc=0x0c042598u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c04259a;
P_0c04259a: /* original e01c, guest PC 0x0c04259a */
if(!s->budget--) { s->failed_pc=0x0c04259au; return 0; }
r[0]=0x0000001cu;
goto P_0c04259c;
P_0c04259c: /* original fe57, guest PC 0x0c04259c */
if(!s->budget--) { s->failed_pc=0x0c04259cu; return 0; }
vf3_matrix_store(s,ram,5,r[14]+r[0]);
goto P_0c04259e;
P_0c04259e: /* original 4d0b, guest PC 0x0c04259e */
if(!s->budget--) { s->failed_pc=0x0c04259eu; return 0; }
target=r[13];
r[16]=code_base|0x0c0425a2u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0425a2u) { target=s->pc; goto dispatch; }
goto P_0c0425a2;
P_0c0425a0: /* original 64e3, guest PC 0x0c0425a0 */
if(!s->budget--) { s->failed_pc=0x0c0425a0u; return 0; }
r[4]=r[14];
goto P_0c0425a2;
P_0c0425a2: /* original c725, guest PC 0x0c0425a2 */
if(!s->budget--) { s->failed_pc=0x0c0425a2u; return 0; }
r[0]=code_base|0x00042638u;
goto P_0c0425a4;
P_0c0425a4: /* original f408, guest PC 0x0c0425a4 */
if(!s->budget--) { s->failed_pc=0x0c0425a4u; return 0; }
vf3_matrix_load(s,ram,4,r[0]);
goto P_0c0425a6;
P_0c0425a6: /* original e004, guest PC 0x0c0425a6 */
if(!s->budget--) { s->failed_pc=0x0c0425a6u; return 0; }
r[0]=0x00000004u;
goto P_0c0425a8;
P_0c0425a8: /* original 7e20, guest PC 0x0c0425a8 */
if(!s->budget--) { s->failed_pc=0x0c0425a8u; return 0; }
r[14]+=0x00000020u;
goto P_0c0425aa;
P_0c0425aa: /* original e200, guest PC 0x0c0425aa */
if(!s->budget--) { s->failed_pc=0x0c0425aau; return 0; }
r[2]=0x00000000u;
goto P_0c0425ac;
P_0c0425ac: /* original fe4a, guest PC 0x0c0425ac */
if(!s->budget--) { s->failed_pc=0x0c0425acu; return 0; }
vf3_matrix_store(s,ram,4,r[14]);
goto P_0c0425ae;
P_0c0425ae: /* original f3c8, guest PC 0x0c0425ae */
if(!s->budget--) { s->failed_pc=0x0c0425aeu; return 0; }
vf3_matrix_load(s,ram,3,r[12]);
goto P_0c0425b0;
P_0c0425b0: /* original fe37, guest PC 0x0c0425b0 */
if(!s->budget--) { s->failed_pc=0x0c0425b0u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c0425b2;
P_0c0425b2: /* original c71e, guest PC 0x0c0425b2 */
if(!s->budget--) { s->failed_pc=0x0c0425b2u; return 0; }
r[0]=code_base|0x0004262cu;
goto P_0c0425b4;
P_0c0425b4: /* original f308, guest PC 0x0c0425b4 */
if(!s->budget--) { s->failed_pc=0x0c0425b4u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c0425b6;
P_0c0425b6: /* original e008, guest PC 0x0c0425b6 */
if(!s->budget--) { s->failed_pc=0x0c0425b6u; return 0; }
r[0]=0x00000008u;
goto P_0c0425b8;
P_0c0425b8: /* original fe37, guest PC 0x0c0425b8 */
if(!s->budget--) { s->failed_pc=0x0c0425b8u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c0425ba;
P_0c0425ba: /* original e00c, guest PC 0x0c0425ba */
if(!s->budget--) { s->failed_pc=0x0c0425bau; return 0; }
r[0]=0x0000000cu;
goto P_0c0425bc;
P_0c0425bc: /* original fe47, guest PC 0x0c0425bc */
if(!s->budget--) { s->failed_pc=0x0c0425bcu; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c0425be;
P_0c0425be: /* original d31f, guest PC 0x0c0425be */
if(!s->budget--) { s->failed_pc=0x0c0425beu; return 0; }
r[3]=read(ram,0x0c04263cu,4);
goto P_0c0425c0;
P_0c0425c0: /* original 1e34, guest PC 0x0c0425c0 */
if(!s->budget--) { s->failed_pc=0x0c0425c0u; return 0; }
write(ram,r[14]+16,r[3],4);
goto P_0c0425c2;
P_0c0425c2: /* original 1e25, guest PC 0x0c0425c2 */
if(!s->budget--) { s->failed_pc=0x0c0425c2u; return 0; }
write(ram,r[14]+20,r[2],4);
goto P_0c0425c4;
P_0c0425c4: /* original d31e, guest PC 0x0c0425c4 */
if(!s->budget--) { s->failed_pc=0x0c0425c4u; return 0; }
r[3]=read(ram,0x0c042640u,4);
goto P_0c0425c6;
P_0c0425c6: /* original 1e36, guest PC 0x0c0425c6 */
if(!s->budget--) { s->failed_pc=0x0c0425c6u; return 0; }
write(ram,r[14]+24,r[3],4);
goto P_0c0425c8;
P_0c0425c8: /* original d21e, guest PC 0x0c0425c8 */
if(!s->budget--) { s->failed_pc=0x0c0425c8u; return 0; }
r[2]=read(ram,0x0c042644u,4);
goto P_0c0425ca;
P_0c0425ca: /* original 1e27, guest PC 0x0c0425ca */
if(!s->budget--) { s->failed_pc=0x0c0425cau; return 0; }
write(ram,r[14]+28,r[2],4);
goto P_0c0425cc;
P_0c0425cc: /* original 4d0b, guest PC 0x0c0425cc */
if(!s->budget--) { s->failed_pc=0x0c0425ccu; return 0; }
target=r[13];
r[16]=code_base|0x0c0425d0u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0425d0u) { target=s->pc; goto dispatch; }
goto P_0c0425d0;
P_0c0425ce: /* original 64e3, guest PC 0x0c0425ce */
if(!s->budget--) { s->failed_pc=0x0c0425ceu; return 0; }
r[4]=r[14];
goto P_0c0425d0;
P_0c0425d0: /* original d30d, guest PC 0x0c0425d0 */
if(!s->budget--) { s->failed_pc=0x0c0425d0u; return 0; }
r[3]=read(ram,0x0c042608u,4);
goto P_0c0425d2;
P_0c0425d2: /* original 7e20, guest PC 0x0c0425d2 */
if(!s->budget--) { s->failed_pc=0x0c0425d2u; return 0; }
r[14]+=0x00000020u;
goto P_0c0425d4;
P_0c0425d4: /* original d012, guest PC 0x0c0425d4 */
if(!s->budget--) { s->failed_pc=0x0c0425d4u; return 0; }
r[0]=read(ram,0x0c042620u,4);
goto P_0c0425d6;
P_0c0425d6: /* original 6432, guest PC 0x0c0425d6 */
if(!s->budget--) { s->failed_pc=0x0c0425d6u; return 0; }
tmp=read(ram,r[3],4);
r[4]=tmp;
goto P_0c0425d8;
P_0c0425d8: /* original d21b, guest PC 0x0c0425d8 */
if(!s->budget--) { s->failed_pc=0x0c0425d8u; return 0; }
r[2]=read(ram,0x0c042648u,4);
goto P_0c0425da;
P_0c0425da: /* original 2e09, guest PC 0x0c0425da */
if(!s->budget--) { s->failed_pc=0x0c0425dau; return 0; }
r[14]&=r[0];
goto P_0c0425dc;
P_0c0425dc: /* original 7408, guest PC 0x0c0425dc */
if(!s->budget--) { s->failed_pc=0x0c0425dcu; return 0; }
r[4]+=0x00000008u;
goto P_0c0425de;
P_0c0425de: /* original 6142, guest PC 0x0c0425de */
if(!s->budget--) { s->failed_pc=0x0c0425deu; return 0; }
tmp=read(ram,r[4],4);
r[1]=tmp;
goto P_0c0425e0;
P_0c0425e0: /* original 2129, guest PC 0x0c0425e0 */
if(!s->budget--) { s->failed_pc=0x0c0425e0u; return 0; }
r[1]&=r[2];
goto P_0c0425e2;
P_0c0425e2: /* original 21eb, guest PC 0x0c0425e2 */
if(!s->budget--) { s->failed_pc=0x0c0425e2u; return 0; }
r[1]|=r[14];
goto P_0c0425e4;
P_0c0425e4: /* original 2412, guest PC 0x0c0425e4 */
if(!s->budget--) { s->failed_pc=0x0c0425e4u; return 0; }
write(ram,r[4],r[1],4);
goto P_0c0425e6;
P_0c0425e6: /* original 4f26, guest PC 0x0c0425e6 */
if(!s->budget--) { s->failed_pc=0x0c0425e6u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0425e8;
P_0c0425e8: /* original 6cf6, guest PC 0x0c0425e8 */
if(!s->budget--) { s->failed_pc=0x0c0425e8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0425ea;
P_0c0425ea: /* original 6df6, guest PC 0x0c0425ea */
if(!s->budget--) { s->failed_pc=0x0c0425eau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0425ec;
P_0c0425ec: /* original 000b, guest PC 0x0c0425ec */
if(!s->budget--) { s->failed_pc=0x0c0425ecu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0425ee: /* original 6ef6, guest PC 0x0c0425ee */
if(!s->budget--) { s->failed_pc=0x0c0425eeu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0425f0u,s,ram);
unsupported: s->failed_pc=target; return 0;
}
