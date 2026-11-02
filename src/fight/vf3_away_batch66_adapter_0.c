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
int vf3_away_batch66_adapter_0(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c092f1cu: goto P_0c092f1c;
case 0x0c092f1eu: goto P_0c092f1e;
case 0x0c092f20u: goto P_0c092f20;
case 0x0c092f22u: goto P_0c092f22;
case 0x0c092f24u: goto P_0c092f24;
case 0x0c092f26u: goto P_0c092f26;
case 0x0c092f28u: goto P_0c092f28;
case 0x0c092f2au: goto P_0c092f2a;
case 0x0c092f2cu: goto P_0c092f2c;
case 0x0c092f2eu: goto P_0c092f2e;
case 0x0c092f30u: goto P_0c092f30;
case 0x0c092f32u: goto P_0c092f32;
case 0x0c092f34u: goto P_0c092f34;
case 0x0c092f36u: goto P_0c092f36;
case 0x0c092f38u: goto P_0c092f38;
case 0x0c092f3au: goto P_0c092f3a;
case 0x0c092f3cu: goto P_0c092f3c;
case 0x0c092f3eu: goto P_0c092f3e;
case 0x0c092f40u: goto P_0c092f40;
case 0x0c092f42u: goto P_0c092f42;
case 0x0c092f44u: goto P_0c092f44;
case 0x0c092f46u: goto P_0c092f46;
case 0x0c092f48u: goto P_0c092f48;
case 0x0c092f4au: goto P_0c092f4a;
case 0x0c092f4cu: goto P_0c092f4c;
case 0x0c092f4eu: goto P_0c092f4e;
case 0x0c092f50u: goto P_0c092f50;
case 0x0c092f52u: goto P_0c092f52;
case 0x0c092f54u: goto P_0c092f54;
case 0x0c092f56u: goto P_0c092f56;
case 0x0c092f58u: goto P_0c092f58;
case 0x0c092f5au: goto P_0c092f5a;
case 0x0c092f5cu: goto P_0c092f5c;
case 0x0c092f5eu: goto P_0c092f5e;
case 0x0c092f60u: goto P_0c092f60;
case 0x0c092f62u: goto P_0c092f62;
case 0x0c092f64u: goto P_0c092f64;
case 0x0c092f66u: goto P_0c092f66;
case 0x0c092f68u: goto P_0c092f68;
case 0x0c092f6au: goto P_0c092f6a;
case 0x0c092f6cu: goto P_0c092f6c;
case 0x0c092f6eu: goto P_0c092f6e;
case 0x0c092f70u: goto P_0c092f70;
case 0x0c092f72u: goto P_0c092f72;
case 0x0c092f74u: goto P_0c092f74;
case 0x0c092f76u: goto P_0c092f76;
case 0x0c092f78u: goto P_0c092f78;
case 0x0c092f7au: goto P_0c092f7a;
case 0x0c092f7cu: goto P_0c092f7c;
case 0x0c092f7eu: goto P_0c092f7e;
case 0x0c092f80u: goto P_0c092f80;
case 0x0c092f82u: goto P_0c092f82;
case 0x0c092f84u: goto P_0c092f84;
case 0x0c092f86u: goto P_0c092f86;
case 0x0c092f88u: goto P_0c092f88;
case 0x0c092f8au: goto P_0c092f8a;
case 0x0c092f8cu: goto P_0c092f8c;
case 0x0c092f8eu: goto P_0c092f8e;
case 0x0c092f90u: goto P_0c092f90;
case 0x0c092f92u: goto P_0c092f92;
case 0x0c092f94u: goto P_0c092f94;
case 0x0c092f96u: goto P_0c092f96;
case 0x0c092f98u: goto P_0c092f98;
case 0x0c092f9au: goto P_0c092f9a;
case 0x0c092f9cu: goto P_0c092f9c;
case 0x0c092f9eu: goto P_0c092f9e;
case 0x0c092fa0u: goto P_0c092fa0;
case 0x0c092fa2u: goto P_0c092fa2;
case 0x0c092fa4u: goto P_0c092fa4;
case 0x0c092fa6u: goto P_0c092fa6;
case 0x0c092fa8u: goto P_0c092fa8;
case 0x0c092faau: goto P_0c092faa;
case 0x0c092facu: goto P_0c092fac;
case 0x0c092faeu: goto P_0c092fae;
case 0x0c092fb0u: goto P_0c092fb0;
case 0x0c092fb2u: goto P_0c092fb2;
case 0x0c092fb4u: goto P_0c092fb4;
case 0x0c092fb6u: goto P_0c092fb6;
case 0x0c092fb8u: goto P_0c092fb8;
case 0x0c092fbau: goto P_0c092fba;
case 0x0c092fbcu: goto P_0c092fbc;
case 0x0c092fbeu: goto P_0c092fbe;
case 0x0c092fc0u: goto P_0c092fc0;
case 0x0c092fc2u: goto P_0c092fc2;
case 0x0c092fc4u: goto P_0c092fc4;
case 0x0c092fc6u: goto P_0c092fc6;
case 0x0c092fc8u: goto P_0c092fc8;
case 0x0c092fcau: goto P_0c092fca;
case 0x0c092fccu: goto P_0c092fcc;
case 0x0c092fceu: goto P_0c092fce;
case 0x0c092fd0u: goto P_0c092fd0;
case 0x0c092fd2u: goto P_0c092fd2;
case 0x0c092fd4u: goto P_0c092fd4;
case 0x0c092fd6u: goto P_0c092fd6;
case 0x0c092fd8u: goto P_0c092fd8;
case 0x0c092fdau: goto P_0c092fda;
case 0x0c092fdcu: goto P_0c092fdc;
case 0x0c092fdeu: goto P_0c092fde;
case 0x0c092fe0u: goto P_0c092fe0;
case 0x0c092fe2u: goto P_0c092fe2;
case 0x0c092fe4u: goto P_0c092fe4;
case 0x0c092fe6u: goto P_0c092fe6;
case 0x0c092fe8u: goto P_0c092fe8;
case 0x0c092feau: goto P_0c092fea;
case 0x0c092fecu: goto P_0c092fec;
case 0x0c092feeu: goto P_0c092fee;
case 0x0c092ff0u: goto P_0c092ff0;
case 0x0c092ff2u: goto P_0c092ff2;
case 0x0c092ff4u: goto P_0c092ff4;
case 0x0c092ff6u: goto P_0c092ff6;
case 0x0c092ff8u: goto P_0c092ff8;
case 0x0c092ffau: goto P_0c092ffa;
case 0x0c092ffcu: goto P_0c092ffc;
case 0x0c092ffeu: goto P_0c092ffe;
case 0x0c093000u: goto P_0c093000;
case 0x0c093002u: goto P_0c093002;
case 0x0c093004u: goto P_0c093004;
case 0x0c093006u: goto P_0c093006;
case 0x0c093008u: goto P_0c093008;
case 0x0c09300au: goto P_0c09300a;
case 0x0c09300cu: goto P_0c09300c;
case 0x0c09300eu: goto P_0c09300e;
case 0x0c093010u: goto P_0c093010;
case 0x0c093012u: goto P_0c093012;
case 0x0c093014u: goto P_0c093014;
case 0x0c093016u: goto P_0c093016;
case 0x0c093018u: goto P_0c093018;
case 0x0c09301au: goto P_0c09301a;
case 0x0c09301cu: goto P_0c09301c;
case 0x0c09301eu: goto P_0c09301e;
case 0x0c093020u: goto P_0c093020;
case 0x0c093022u: goto P_0c093022;
case 0x0c093024u: goto P_0c093024;
case 0x0c093026u: goto P_0c093026;
case 0x0c093028u: goto P_0c093028;
case 0x0c093266u: goto P_0c093266;
case 0x0c093268u: goto P_0c093268;
case 0x0c09326au: goto P_0c09326a;
case 0x0c09326cu: goto P_0c09326c;
case 0x0c09326eu: goto P_0c09326e;
case 0x0c093270u: goto P_0c093270;
case 0x0c093272u: goto P_0c093272;
case 0x0c093274u: goto P_0c093274;
case 0x0c093276u: goto P_0c093276;
case 0x0c093278u: goto P_0c093278;
case 0x0c09327au: goto P_0c09327a;
case 0x0c09327cu: goto P_0c09327c;
case 0x0c09327eu: goto P_0c09327e;
case 0x0c093280u: goto P_0c093280;
case 0x0c093282u: goto P_0c093282;
case 0x0c093284u: goto P_0c093284;
case 0x0c093286u: goto P_0c093286;
case 0x0c093288u: goto P_0c093288;
case 0x0c09328au: goto P_0c09328a;
case 0x0c09328cu: goto P_0c09328c;
case 0x0c09328eu: goto P_0c09328e;
case 0x0c093290u: goto P_0c093290;
case 0x0c093292u: goto P_0c093292;
case 0x0c093294u: goto P_0c093294;
case 0x0c093296u: goto P_0c093296;
case 0x0c093298u: goto P_0c093298;
case 0x0c09329au: goto P_0c09329a;
case 0x0c09329cu: goto P_0c09329c;
case 0x0c09329eu: goto P_0c09329e;
case 0x0c0932a0u: goto P_0c0932a0;
case 0x0c0932a2u: goto P_0c0932a2;
case 0x0c0932a4u: goto P_0c0932a4;
case 0x0c0932a6u: goto P_0c0932a6;
case 0x0c0932a8u: goto P_0c0932a8;
case 0x0c0932c8u: goto P_0c0932c8;
case 0x0c0932cau: goto P_0c0932ca;
case 0x0c0932ccu: goto P_0c0932cc;
case 0x0c0932ceu: goto P_0c0932ce;
case 0x0c0932d0u: goto P_0c0932d0;
case 0x0c0932d2u: goto P_0c0932d2;
case 0x0c0932d4u: goto P_0c0932d4;
case 0x0c0932d6u: goto P_0c0932d6;
case 0x0c0932d8u: goto P_0c0932d8;
case 0x0c0932dau: goto P_0c0932da;
case 0x0c0932dcu: goto P_0c0932dc;
case 0x0c0932deu: goto P_0c0932de;
case 0x0c0932e0u: goto P_0c0932e0;
case 0x0c0932e2u: goto P_0c0932e2;
case 0x0c0932e4u: goto P_0c0932e4;
case 0x0c0932e6u: goto P_0c0932e6;
case 0x0c0932e8u: goto P_0c0932e8;
case 0x0c0932eau: goto P_0c0932ea;
case 0x0c0932ecu: goto P_0c0932ec;
case 0x0c0932eeu: goto P_0c0932ee;
case 0x0c0932f0u: goto P_0c0932f0;
case 0x0c0932f2u: goto P_0c0932f2;
case 0x0c0932f4u: goto P_0c0932f4;
case 0x0c0932f6u: goto P_0c0932f6;
case 0x0c0932f8u: goto P_0c0932f8;
case 0x0c0932fau: goto P_0c0932fa;
case 0x0c0932fcu: goto P_0c0932fc;
case 0x0c0932feu: goto P_0c0932fe;
case 0x0c093300u: goto P_0c093300;
case 0x0c093302u: goto P_0c093302;
case 0x0c093304u: goto P_0c093304;
case 0x0c093306u: goto P_0c093306;
case 0x0c093308u: goto P_0c093308;
case 0x0c09330au: goto P_0c09330a;
case 0x0c09330cu: goto P_0c09330c;
case 0x0c09330eu: goto P_0c09330e;
case 0x0c093310u: goto P_0c093310;
case 0x0c093312u: goto P_0c093312;
case 0x0c093314u: goto P_0c093314;
case 0x0c093316u: goto P_0c093316;
case 0x0c093318u: goto P_0c093318;
case 0x0c09331au: goto P_0c09331a;
case 0x0c09331cu: goto P_0c09331c;
case 0x0c09331eu: goto P_0c09331e;
case 0x0c093320u: goto P_0c093320;
case 0x0c093322u: goto P_0c093322;
case 0x0c093324u: goto P_0c093324;
case 0x0c093326u: goto P_0c093326;
case 0x0c093328u: goto P_0c093328;
case 0x0c09332au: goto P_0c09332a;
case 0x0c09332cu: goto P_0c09332c;
case 0x0c09332eu: goto P_0c09332e;
case 0x0c093330u: goto P_0c093330;
case 0x0c093332u: goto P_0c093332;
case 0x0c093334u: goto P_0c093334;
case 0x0c093336u: goto P_0c093336;
case 0x0c093338u: goto P_0c093338;
case 0x0c09333au: goto P_0c09333a;
case 0x0c09333cu: goto P_0c09333c;
case 0x0c09333eu: goto P_0c09333e;
case 0x0c093340u: goto P_0c093340;
case 0x0c093342u: goto P_0c093342;
case 0x0c093344u: goto P_0c093344;
case 0x0c093346u: goto P_0c093346;
case 0x0c093348u: goto P_0c093348;
case 0x0c09334au: goto P_0c09334a;
case 0x0c09334cu: goto P_0c09334c;
case 0x0c09334eu: goto P_0c09334e;
case 0x0c093350u: goto P_0c093350;
case 0x0c093352u: goto P_0c093352;
case 0x0c093354u: goto P_0c093354;
case 0x0c093356u: goto P_0c093356;
case 0x0c093358u: goto P_0c093358;
case 0x0c09335au: goto P_0c09335a;
case 0x0c09335cu: goto P_0c09335c;
case 0x0c09335eu: goto P_0c09335e;
case 0x0c093360u: goto P_0c093360;
case 0x0c093362u: goto P_0c093362;
case 0x0c093364u: goto P_0c093364;
case 0x0c093366u: goto P_0c093366;
case 0x0c093368u: goto P_0c093368;
case 0x0c093378u: goto P_0c093378;
case 0x0c09337au: goto P_0c09337a;
case 0x0c09337cu: goto P_0c09337c;
case 0x0c09337eu: goto P_0c09337e;
case 0x0c093380u: goto P_0c093380;
case 0x0c093382u: goto P_0c093382;
case 0x0c093384u: goto P_0c093384;
case 0x0c093386u: goto P_0c093386;
case 0x0c093388u: goto P_0c093388;
case 0x0c09338au: goto P_0c09338a;
case 0x0c09338cu: goto P_0c09338c;
case 0x0c09338eu: goto P_0c09338e;
case 0x0c093390u: goto P_0c093390;
case 0x0c093392u: goto P_0c093392;
case 0x0c093394u: goto P_0c093394;
case 0x0c093396u: goto P_0c093396;
case 0x0c093398u: goto P_0c093398;
case 0x0c09339au: goto P_0c09339a;
case 0x0c09339cu: goto P_0c09339c;
case 0x0c09339eu: goto P_0c09339e;
case 0x0c0933a0u: goto P_0c0933a0;
case 0x0c0933a2u: goto P_0c0933a2;
case 0x0c0933a4u: goto P_0c0933a4;
case 0x0c0933a6u: goto P_0c0933a6;
case 0x0c0933a8u: goto P_0c0933a8;
case 0x0c0933aau: goto P_0c0933aa;
case 0x0c0933acu: goto P_0c0933ac;
case 0x0c0933aeu: goto P_0c0933ae;
case 0x0c0933b0u: goto P_0c0933b0;
case 0x0c0933b2u: goto P_0c0933b2;
case 0x0c0933b4u: goto P_0c0933b4;
case 0x0c0933b6u: goto P_0c0933b6;
case 0x0c0933b8u: goto P_0c0933b8;
case 0x0c0933bau: goto P_0c0933ba;
case 0x0c0933bcu: goto P_0c0933bc;
case 0x0c0933beu: goto P_0c0933be;
case 0x0c0933c0u: goto P_0c0933c0;
case 0x0c0933c2u: goto P_0c0933c2;
case 0x0c0933c4u: goto P_0c0933c4;
case 0x0c0933c6u: goto P_0c0933c6;
case 0x0c0933c8u: goto P_0c0933c8;
case 0x0c0933cau: goto P_0c0933ca;
case 0x0c0933ccu: goto P_0c0933cc;
case 0x0c0933ceu: goto P_0c0933ce;
case 0x0c0933d0u: goto P_0c0933d0;
case 0x0c0933d2u: goto P_0c0933d2;
case 0x0c0933d4u: goto P_0c0933d4;
case 0x0c0933d6u: goto P_0c0933d6;
case 0x0c0933d8u: goto P_0c0933d8;
case 0x0c0933dau: goto P_0c0933da;
case 0x0c0933dcu: goto P_0c0933dc;
case 0x0c0933deu: goto P_0c0933de;
case 0x0c0933e0u: goto P_0c0933e0;
case 0x0c0933e2u: goto P_0c0933e2;
case 0x0c0933e4u: goto P_0c0933e4;
case 0x0c0933e6u: goto P_0c0933e6;
case 0x0c0933e8u: goto P_0c0933e8;
case 0x0c0933eau: goto P_0c0933ea;
case 0x0c0933ecu: goto P_0c0933ec;
case 0x0c0933eeu: goto P_0c0933ee;
case 0x0c0933f0u: goto P_0c0933f0;
case 0x0c0933f2u: goto P_0c0933f2;
case 0x0c0933f4u: goto P_0c0933f4;
case 0x0c0933f6u: goto P_0c0933f6;
case 0x0c0933f8u: goto P_0c0933f8;
case 0x0c0933fau: goto P_0c0933fa;
case 0x0c0933fcu: goto P_0c0933fc;
case 0x0c0933feu: goto P_0c0933fe;
case 0x0c093400u: goto P_0c093400;
case 0x0c093402u: goto P_0c093402;
case 0x0c093404u: goto P_0c093404;
case 0x0c093406u: goto P_0c093406;
case 0x0c093408u: goto P_0c093408;
case 0x0c09340au: goto P_0c09340a;
case 0x0c09340cu: goto P_0c09340c;
case 0x0c09340eu: goto P_0c09340e;
case 0x0c093410u: goto P_0c093410;
case 0x0c093412u: goto P_0c093412;
case 0x0c093414u: goto P_0c093414;
case 0x0c093416u: goto P_0c093416;
case 0x0c093418u: goto P_0c093418;
case 0x0c09341au: goto P_0c09341a;
case 0x0c09341cu: goto P_0c09341c;
default: return vf3_matrix_family(target,s,ram);
}
P_0c092f1c: /* original 2fe6, guest PC 0x0c092f1c */
if(!s->budget--) { s->failed_pc=0x0c092f1cu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c092f1e;
P_0c092f1e: /* original e050, guest PC 0x0c092f1e */
if(!s->budget--) { s->failed_pc=0x0c092f1eu; return 0; }
r[0]=0x00000050u;
goto P_0c092f20;
P_0c092f20: /* original 6372, guest PC 0x0c092f20 */
if(!s->budget--) { s->failed_pc=0x0c092f20u; return 0; }
tmp=read(ram,r[7],4);
r[3]=tmp;
goto P_0c092f22;
P_0c092f22: /* original 5ef3, guest PC 0x0c092f22 */
if(!s->budget--) { s->failed_pc=0x0c092f22u; return 0; }
r[14]=read(ram,r[15]+12,4);
goto P_0c092f24;
P_0c092f24: /* original 2338, guest PC 0x0c092f24 */
if(!s->budget--) { s->failed_pc=0x0c092f24u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c092f26;
P_0c092f26: /* original 8f02, guest PC 0x0c092f26 */
if(!s->budget--) { s->failed_pc=0x0c092f26u; return 0; }
cond=r[17]&1u;
vf3_matrix_load(s,ram,4,r[4]+r[0]);
if(!cond) { goto P_0c092f2e; }
goto P_0c092f2a;
P_0c092f28: /* original f446, guest PC 0x0c092f28 */
if(!s->budget--) { s->failed_pc=0x0c092f28u; return 0; }
vf3_matrix_load(s,ram,4,r[4]+r[0]);
goto P_0c092f2a;
P_0c092f2a: /* original a07c, guest PC 0x0c092f2a */
if(!s->budget--) { s->failed_pc=0x0c092f2au; return 0; }
goto P_0c093026;
P_0c092f2c: /* original 0009, guest PC 0x0c092f2c */
if(!s->budget--) { s->failed_pc=0x0c092f2cu; return 0; }
goto P_0c092f2e;
P_0c092f2e: /* original f38d, guest PC 0x0c092f2e */
if(!s->budget--) { s->failed_pc=0x0c092f2eu; return 0; }
fr[3]=0;
goto P_0c092f30;
P_0c092f30: /* original f434, guest PC 0x0c092f30 */
if(!s->budget--) { s->failed_pc=0x0c092f30u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[4])==as_float(fr[3]))!=0);
goto P_0c092f32;
P_0c092f32: /* original 8978, guest PC 0x0c092f32 */
if(!s->budget--) { s->failed_pc=0x0c092f32u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c093026; }
goto P_0c092f34;
P_0c092f34: /* original 6372, guest PC 0x0c092f34 */
if(!s->budget--) { s->failed_pc=0x0c092f34u; return 0; }
tmp=read(ram,r[7],4);
r[3]=tmp;
goto P_0c092f36;
P_0c092f36: /* original e004, guest PC 0x0c092f36 */
if(!s->budget--) { s->failed_pc=0x0c092f36u; return 0; }
r[0]=0x00000004u;
goto P_0c092f38;
P_0c092f38: /* original 7304, guest PC 0x0c092f38 */
if(!s->budget--) { s->failed_pc=0x0c092f38u; return 0; }
r[3]+=0x00000004u;
goto P_0c092f3a;
P_0c092f3a: /* original 2732, guest PC 0x0c092f3a */
if(!s->budget--) { s->failed_pc=0x0c092f3au; return 0; }
write(ram,r[7],r[3],4);
goto P_0c092f3c;
P_0c092f3c: /* original f338, guest PC 0x0c092f3c */
if(!s->budget--) { s->failed_pc=0x0c092f3cu; return 0; }
vf3_matrix_load(s,ram,3,r[3]);
goto P_0c092f3e;
P_0c092f3e: /* original 53f1, guest PC 0x0c092f3e */
if(!s->budget--) { s->failed_pc=0x0c092f3eu; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c092f40;
P_0c092f40: /* original f342, guest PC 0x0c092f40 */
if(!s->budget--) { s->failed_pc=0x0c092f40u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'*');
goto P_0c092f42;
P_0c092f42: /* original f236, guest PC 0x0c092f42 */
if(!s->budget--) { s->failed_pc=0x0c092f42u; return 0; }
vf3_matrix_load(s,ram,2,r[3]+r[0]);
goto P_0c092f44;
P_0c092f44: /* original e044, guest PC 0x0c092f44 */
if(!s->budget--) { s->failed_pc=0x0c092f44u; return 0; }
r[0]=0x00000044u;
goto P_0c092f46;
P_0c092f46: /* original f846, guest PC 0x0c092f46 */
if(!s->budget--) { s->failed_pc=0x0c092f46u; return 0; }
vf3_matrix_load(s,ram,8,r[4]+r[0]);
goto P_0c092f48;
P_0c092f48: /* original e04c, guest PC 0x0c092f48 */
if(!s->budget--) { s->failed_pc=0x0c092f48u; return 0; }
r[0]=0x0000004cu;
goto P_0c092f4a;
P_0c092f4a: /* original fa46, guest PC 0x0c092f4a */
if(!s->budget--) { s->failed_pc=0x0c092f4au; return 0; }
vf3_matrix_load(s,ram,10,r[4]+r[0]);
goto P_0c092f4c;
P_0c092f4c: /* original c74f, guest PC 0x0c092f4c */
if(!s->budget--) { s->failed_pc=0x0c092f4cu; return 0; }
r[0]=code_base|0x0009308cu;
goto P_0c092f4e;
P_0c092f4e: /* original f908, guest PC 0x0c092f4e */
if(!s->budget--) { s->failed_pc=0x0c092f4eu; return 0; }
vf3_matrix_load(s,ram,9,r[0]);
goto P_0c092f50;
P_0c092f50: /* original f53c, guest PC 0x0c092f50 */
if(!s->budget--) { s->failed_pc=0x0c092f50u; return 0; }
vf3_matrix_move(s,5,3);
goto P_0c092f52;
P_0c092f52: /* original f521, guest PC 0x0c092f52 */
if(!s->budget--) { s->failed_pc=0x0c092f52u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[2],r[18],'-');
goto P_0c092f54;
P_0c092f54: /* original 8548, guest PC 0x0c092f54 */
if(!s->budget--) { s->failed_pc=0x0c092f54u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+16,2);
goto P_0c092f56;
P_0c092f56: /* original 600d, guest PC 0x0c092f56 */
if(!s->budget--) { s->failed_pc=0x0c092f56u; return 0; }
r[0]=r[0]&65535u;
goto P_0c092f58;
P_0c092f58: /* original c801, guest PC 0x0c092f58 */
if(!s->budget--) { s->failed_pc=0x0c092f58u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&1u)==0)!=0);
goto P_0c092f5a;
P_0c092f5a: /* original 8d2a, guest PC 0x0c092f5a */
if(!s->budget--) { s->failed_pc=0x0c092f5au; return 0; }
cond=r[17]&1u;
fr[7]=0x3f800000u;
if(cond) { goto P_0c092fb2; }
goto P_0c092f5e;
P_0c092f5c: /* original f79d, guest PC 0x0c092f5c */
if(!s->budget--) { s->failed_pc=0x0c092f5cu; return 0; }
fr[7]=0x3f800000u;
goto P_0c092f5e;
P_0c092f5e: /* original e010, guest PC 0x0c092f5e */
if(!s->budget--) { s->failed_pc=0x0c092f5eu; return 0; }
r[0]=0x00000010u;
goto P_0c092f60;
P_0c092f60: /* original f47c, guest PC 0x0c092f60 */
if(!s->budget--) { s->failed_pc=0x0c092f60u; return 0; }
vf3_matrix_move(s,4,7);
goto P_0c092f62;
P_0c092f62: /* original f366, guest PC 0x0c092f62 */
if(!s->budget--) { s->failed_pc=0x0c092f62u; return 0; }
vf3_matrix_load(s,ram,3,r[6]+r[0]);
goto P_0c092f64;
P_0c092f64: /* original e004, guest PC 0x0c092f64 */
if(!s->budget--) { s->failed_pc=0x0c092f64u; return 0; }
r[0]=0x00000004u;
goto P_0c092f66;
P_0c092f66: /* original f666, guest PC 0x0c092f66 */
if(!s->budget--) { s->failed_pc=0x0c092f66u; return 0; }
vf3_matrix_load(s,ram,6,r[6]+r[0]);
goto P_0c092f68;
P_0c092f68: /* original fb7c, guest PC 0x0c092f68 */
if(!s->budget--) { s->failed_pc=0x0c092f68u; return 0; }
vf3_matrix_move(s,11,7);
goto P_0c092f6a;
P_0c092f6a: /* original f631, guest PC 0x0c092f6a */
if(!s->budget--) { s->failed_pc=0x0c092f6au; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[3],r[18],'-');
goto P_0c092f6c;
P_0c092f6c: /* original f37c, guest PC 0x0c092f6c */
if(!s->budget--) { s->failed_pc=0x0c092f6cu; return 0; }
vf3_matrix_move(s,3,7);
goto P_0c092f6e;
P_0c092f6e: /* original f06c, guest PC 0x0c092f6e */
if(!s->budget--) { s->failed_pc=0x0c092f6eu; return 0; }
vf3_matrix_move(s,0,6);
goto P_0c092f70;
P_0c092f70: /* original f45e, guest PC 0x0c092f70 */
if(!s->budget--) { s->failed_pc=0x0c092f70u; return 0; }
fr[4]=vf3_fpu_mac(fr[0],fr[5],fr[4],r[18]);
goto P_0c092f72;
P_0c092f72: /* original f05c, guest PC 0x0c092f72 */
if(!s->budget--) { s->failed_pc=0x0c092f72u; return 0; }
vf3_matrix_move(s,0,5);
goto P_0c092f74;
P_0c092f74: /* original fb5e, guest PC 0x0c092f74 */
if(!s->budget--) { s->failed_pc=0x0c092f74u; return 0; }
fr[11]=vf3_fpu_mac(fr[0],fr[5],fr[11],r[18]);
goto P_0c092f76;
P_0c092f76: /* original f06c, guest PC 0x0c092f76 */
if(!s->budget--) { s->failed_pc=0x0c092f76u; return 0; }
vf3_matrix_move(s,0,6);
goto P_0c092f78;
P_0c092f78: /* original f36e, guest PC 0x0c092f78 */
if(!s->budget--) { s->failed_pc=0x0c092f78u; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[6],fr[3],r[18]);
goto P_0c092f7a;
P_0c092f7a: /* original f9b5, guest PC 0x0c092f7a */
if(!s->budget--) { s->failed_pc=0x0c092f7au; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[9])>as_float(fr[11]))!=0);
goto P_0c092f7c;
P_0c092f7c: /* original 8f02, guest PC 0x0c092f7c */
if(!s->budget--) { s->failed_pc=0x0c092f7cu; return 0; }
cond=r[17]&1u;
vf3_matrix_move(s,6,3);
if(!cond) { goto P_0c092f84; }
goto P_0c092f80;
P_0c092f7e: /* original f63c, guest PC 0x0c092f7e */
if(!s->budget--) { s->failed_pc=0x0c092f7eu; return 0; }
vf3_matrix_move(s,6,3);
goto P_0c092f80;
P_0c092f80: /* original a002, guest PC 0x0c092f80 */
if(!s->budget--) { s->failed_pc=0x0c092f80u; return 0; }
fr[2]=0;
goto P_0c092f88;
P_0c092f82: /* original f28d, guest PC 0x0c092f82 */
if(!s->budget--) { s->failed_pc=0x0c092f82u; return 0; }
fr[2]=0;
goto P_0c092f84;
P_0c092f84: /* original f2bc, guest PC 0x0c092f84 */
if(!s->budget--) { s->failed_pc=0x0c092f84u; return 0; }
vf3_matrix_move(s,2,11);
goto P_0c092f86;
P_0c092f86: /* original f27d, guest PC 0x0c092f86 */
if(!s->budget--) { s->failed_pc=0x0c092f86u; return 0; }
if(!vf3_fpu_fsrra(fr[2],r[18],&fr[2])) goto unsupported;
goto P_0c092f88;
P_0c092f88: /* original f965, guest PC 0x0c092f88 */
if(!s->budget--) { s->failed_pc=0x0c092f88u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[9])>as_float(fr[6]))!=0);
goto P_0c092f8a;
P_0c092f8a: /* original 8f02, guest PC 0x0c092f8a */
if(!s->budget--) { s->failed_pc=0x0c092f8au; return 0; }
cond=r[17]&1u;
fr[4]=vf3_fpu_binary(fr[4],fr[2],r[18],'*');
if(!cond) { goto P_0c092f92; }
goto P_0c092f8e;
P_0c092f8c: /* original f422, guest PC 0x0c092f8c */
if(!s->budget--) { s->failed_pc=0x0c092f8cu; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[2],r[18],'*');
goto P_0c092f8e;
P_0c092f8e: /* original a002, guest PC 0x0c092f8e */
if(!s->budget--) { s->failed_pc=0x0c092f8eu; return 0; }
fr[3]=0;
goto P_0c092f96;
P_0c092f90: /* original f38d, guest PC 0x0c092f90 */
if(!s->budget--) { s->failed_pc=0x0c092f90u; return 0; }
fr[3]=0;
goto P_0c092f92;
P_0c092f92: /* original f36c, guest PC 0x0c092f92 */
if(!s->budget--) { s->failed_pc=0x0c092f92u; return 0; }
vf3_matrix_move(s,3,6);
goto P_0c092f94;
P_0c092f94: /* original f37d, guest PC 0x0c092f94 */
if(!s->budget--) { s->failed_pc=0x0c092f94u; return 0; }
if(!vf3_fpu_fsrra(fr[3],r[18],&fr[3])) goto unsupported;
goto P_0c092f96;
P_0c092f96: /* original f432, guest PC 0x0c092f96 */
if(!s->budget--) { s->failed_pc=0x0c092f96u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'*');
goto P_0c092f98;
P_0c092f98: /* original f34c, guest PC 0x0c092f98 */
if(!s->budget--) { s->failed_pc=0x0c092f98u; return 0; }
vf3_matrix_move(s,3,4);
goto P_0c092f9a;
P_0c092f9a: /* original f342, guest PC 0x0c092f9a */
if(!s->budget--) { s->failed_pc=0x0c092f9au; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'*');
goto P_0c092f9c;
P_0c092f9c: /* original f47c, guest PC 0x0c092f9c */
if(!s->budget--) { s->failed_pc=0x0c092f9cu; return 0; }
vf3_matrix_move(s,4,7);
goto P_0c092f9e;
P_0c092f9e: /* original f431, guest PC 0x0c092f9e */
if(!s->budget--) { s->failed_pc=0x0c092f9eu; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'-');
goto P_0c092fa0;
P_0c092fa0: /* original f945, guest PC 0x0c092fa0 */
if(!s->budget--) { s->failed_pc=0x0c092fa0u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[9])>as_float(fr[4]))!=0);
goto P_0c092fa2;
P_0c092fa2: /* original 8b01, guest PC 0x0c092fa2 */
if(!s->budget--) { s->failed_pc=0x0c092fa2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c092fa8; }
goto P_0c092fa4;
P_0c092fa4: /* original a002, guest PC 0x0c092fa4 */
if(!s->budget--) { s->failed_pc=0x0c092fa4u; return 0; }
fr[6]=0;
goto P_0c092fac;
P_0c092fa6: /* original f68d, guest PC 0x0c092fa6 */
if(!s->budget--) { s->failed_pc=0x0c092fa6u; return 0; }
fr[6]=0;
goto P_0c092fa8;
P_0c092fa8: /* original f64c, guest PC 0x0c092fa8 */
if(!s->budget--) { s->failed_pc=0x0c092fa8u; return 0; }
vf3_matrix_move(s,6,4);
goto P_0c092faa;
P_0c092faa: /* original f66d, guest PC 0x0c092faa */
if(!s->budget--) { s->failed_pc=0x0c092faau; return 0; }
fr[6]=vf3_fpu_sqrt(fr[6],r[18]);
goto P_0c092fac;
P_0c092fac: /* original f862, guest PC 0x0c092fac */
if(!s->budget--) { s->failed_pc=0x0c092facu; return 0; }
fr[8]=vf3_fpu_binary(fr[8],fr[6],r[18],'*');
goto P_0c092fae;
P_0c092fae: /* original a028, guest PC 0x0c092fae */
if(!s->budget--) { s->failed_pc=0x0c092faeu; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[6],r[18],'*');
goto P_0c093002;
P_0c092fb0: /* original f562, guest PC 0x0c092fb0 */
if(!s->budget--) { s->failed_pc=0x0c092fb0u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[6],r[18],'*');
goto P_0c092fb2;
P_0c092fb2: /* original e048, guest PC 0x0c092fb2 */
if(!s->budget--) { s->failed_pc=0x0c092fb2u; return 0; }
r[0]=0x00000048u;
goto P_0c092fb4;
P_0c092fb4: /* original d336, guest PC 0x0c092fb4 */
if(!s->budget--) { s->failed_pc=0x0c092fb4u; return 0; }
r[3]=read(ram,0x0c093090u,4);
goto P_0c092fb6;
P_0c092fb6: /* original 025e, guest PC 0x0c092fb6 */
if(!s->budget--) { s->failed_pc=0x0c092fb6u; return 0; }
r[2]=read(ram,r[5]+r[0],4);
goto P_0c092fb8;
P_0c092fb8: /* original 2238, guest PC 0x0c092fb8 */
if(!s->budget--) { s->failed_pc=0x0c092fb8u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c092fba;
P_0c092fba: /* original 8b34, guest PC 0x0c092fba */
if(!s->budget--) { s->failed_pc=0x0c092fbau; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c093026; }
goto P_0c092fbc;
P_0c092fbc: /* original e014, guest PC 0x0c092fbc */
if(!s->budget--) { s->failed_pc=0x0c092fbcu; return 0; }
r[0]=0x00000014u;
goto P_0c092fbe;
P_0c092fbe: /* original f268, guest PC 0x0c092fbe */
if(!s->budget--) { s->failed_pc=0x0c092fbeu; return 0; }
vf3_matrix_load(s,ram,2,r[6]);
goto P_0c092fc0;
P_0c092fc0: /* original f066, guest PC 0x0c092fc0 */
if(!s->budget--) { s->failed_pc=0x0c092fc0u; return 0; }
vf3_matrix_load(s,ram,0,r[6]+r[0]);
goto P_0c092fc2;
P_0c092fc2: /* original e008, guest PC 0x0c092fc2 */
if(!s->budget--) { s->failed_pc=0x0c092fc2u; return 0; }
r[0]=0x00000008u;
goto P_0c092fc4;
P_0c092fc4: /* original f366, guest PC 0x0c092fc4 */
if(!s->budget--) { s->failed_pc=0x0c092fc4u; return 0; }
vf3_matrix_load(s,ram,3,r[6]+r[0]);
goto P_0c092fc6;
P_0c092fc6: /* original e00c, guest PC 0x0c092fc6 */
if(!s->budget--) { s->failed_pc=0x0c092fc6u; return 0; }
r[0]=0x0000000cu;
goto P_0c092fc8;
P_0c092fc8: /* original f301, guest PC 0x0c092fc8 */
if(!s->budget--) { s->failed_pc=0x0c092fc8u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[0],r[18],'-');
goto P_0c092fca;
P_0c092fca: /* original f066, guest PC 0x0c092fca */
if(!s->budget--) { s->failed_pc=0x0c092fcau; return 0; }
vf3_matrix_load(s,ram,0,r[6]+r[0]);
goto P_0c092fcc;
P_0c092fcc: /* original e054, guest PC 0x0c092fcc */
if(!s->budget--) { s->failed_pc=0x0c092fccu; return 0; }
r[0]=0x00000054u;
goto P_0c092fce;
P_0c092fce: /* original f201, guest PC 0x0c092fce */
if(!s->budget--) { s->failed_pc=0x0c092fceu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[0],r[18],'-');
goto P_0c092fd0;
P_0c092fd0: /* original f0ac, guest PC 0x0c092fd0 */
if(!s->budget--) { s->failed_pc=0x0c092fd0u; return 0; }
vf3_matrix_move(s,0,10);
goto P_0c092fd2;
P_0c092fd2: /* original f282, guest PC 0x0c092fd2 */
if(!s->budget--) { s->failed_pc=0x0c092fd2u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[8],r[18],'*');
goto P_0c092fd4;
P_0c092fd4: /* original f23e, guest PC 0x0c092fd4 */
if(!s->budget--) { s->failed_pc=0x0c092fd4u; return 0; }
fr[2]=vf3_fpu_mac(fr[0],fr[3],fr[2],r[18]);
goto P_0c092fd6;
P_0c092fd6: /* original f346, guest PC 0x0c092fd6 */
if(!s->budget--) { s->failed_pc=0x0c092fd6u; return 0; }
vf3_matrix_load(s,ram,3,r[4]+r[0]);
goto P_0c092fd8;
P_0c092fd8: /* original e028, guest PC 0x0c092fd8 */
if(!s->budget--) { s->failed_pc=0x0c092fd8u; return 0; }
r[0]=0x00000028u;
goto P_0c092fda;
P_0c092fda: /* original f42c, guest PC 0x0c092fda */
if(!s->budget--) { s->failed_pc=0x0c092fdau; return 0; }
vf3_matrix_move(s,4,2);
goto P_0c092fdc;
P_0c092fdc: /* original f266, guest PC 0x0c092fdc */
if(!s->budget--) { s->failed_pc=0x0c092fdcu; return 0; }
vf3_matrix_load(s,ram,2,r[6]+r[0]);
goto P_0c092fde;
P_0c092fde: /* original f232, guest PC 0x0c092fde */
if(!s->budget--) { s->failed_pc=0x0c092fdeu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c092fe0;
P_0c092fe0: /* original f422, guest PC 0x0c092fe0 */
if(!s->budget--) { s->failed_pc=0x0c092fe0u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[2],r[18],'*');
goto P_0c092fe2;
P_0c092fe2: /* original f28d, guest PC 0x0c092fe2 */
if(!s->budget--) { s->failed_pc=0x0c092fe2u; return 0; }
fr[2]=0;
goto P_0c092fe4;
P_0c092fe4: /* original f442, guest PC 0x0c092fe4 */
if(!s->budget--) { s->failed_pc=0x0c092fe4u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[4],r[18],'*');
goto P_0c092fe6;
P_0c092fe6: /* original f34c, guest PC 0x0c092fe6 */
if(!s->budget--) { s->failed_pc=0x0c092fe6u; return 0; }
vf3_matrix_move(s,3,4);
goto P_0c092fe8;
P_0c092fe8: /* original f47c, guest PC 0x0c092fe8 */
if(!s->budget--) { s->failed_pc=0x0c092fe8u; return 0; }
vf3_matrix_move(s,4,7);
goto P_0c092fea;
P_0c092fea: /* original f431, guest PC 0x0c092fea */
if(!s->budget--) { s->failed_pc=0x0c092feau; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'-');
goto P_0c092fec;
P_0c092fec: /* original f425, guest PC 0x0c092fec */
if(!s->budget--) { s->failed_pc=0x0c092fecu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[4])>as_float(fr[2]))!=0);
goto P_0c092fee;
P_0c092fee: /* original 8901, guest PC 0x0c092fee */
if(!s->budget--) { s->failed_pc=0x0c092feeu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c092ff4; }
goto P_0c092ff0;
P_0c092ff0: /* original a006, guest PC 0x0c092ff0 */
if(!s->budget--) { s->failed_pc=0x0c092ff0u; return 0; }
vf3_matrix_move(s,6,7);
goto P_0c093000;
P_0c092ff2: /* original f67c, guest PC 0x0c092ff2 */
if(!s->budget--) { s->failed_pc=0x0c092ff2u; return 0; }
vf3_matrix_move(s,6,7);
goto P_0c092ff4;
P_0c092ff4: /* original f945, guest PC 0x0c092ff4 */
if(!s->budget--) { s->failed_pc=0x0c092ff4u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[9])>as_float(fr[4]))!=0);
goto P_0c092ff6;
P_0c092ff6: /* original 8b01, guest PC 0x0c092ff6 */
if(!s->budget--) { s->failed_pc=0x0c092ff6u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c092ffc; }
goto P_0c092ff8;
P_0c092ff8: /* original a002, guest PC 0x0c092ff8 */
if(!s->budget--) { s->failed_pc=0x0c092ff8u; return 0; }
fr[6]=0;
goto P_0c093000;
P_0c092ffa: /* original f68d, guest PC 0x0c092ffa */
if(!s->budget--) { s->failed_pc=0x0c092ffau; return 0; }
fr[6]=0;
goto P_0c092ffc;
P_0c092ffc: /* original f64c, guest PC 0x0c092ffc */
if(!s->budget--) { s->failed_pc=0x0c092ffcu; return 0; }
vf3_matrix_move(s,6,4);
goto P_0c092ffe;
P_0c092ffe: /* original f66d, guest PC 0x0c092ffe */
if(!s->budget--) { s->failed_pc=0x0c092ffeu; return 0; }
fr[6]=vf3_fpu_sqrt(fr[6],r[18]);
goto P_0c093000;
P_0c093000: /* original f862, guest PC 0x0c093000 */
if(!s->budget--) { s->failed_pc=0x0c093000u; return 0; }
fr[8]=vf3_fpu_binary(fr[8],fr[6],r[18],'*');
goto P_0c093002;
P_0c093002: /* original 53f2, guest PC 0x0c093002 */
if(!s->budget--) { s->failed_pc=0x0c093002u; return 0; }
r[3]=read(ram,r[15]+8,4);
goto P_0c093004;
P_0c093004: /* original e004, guest PC 0x0c093004 */
if(!s->budget--) { s->failed_pc=0x0c093004u; return 0; }
r[0]=0x00000004u;
goto P_0c093006;
P_0c093006: /* original fa62, guest PC 0x0c093006 */
if(!s->budget--) { s->failed_pc=0x0c093006u; return 0; }
fr[10]=vf3_fpu_binary(fr[10],fr[6],r[18],'*');
goto P_0c093008;
P_0c093008: /* original 6232, guest PC 0x0c093008 */
if(!s->budget--) { s->failed_pc=0x0c093008u; return 0; }
tmp=read(ram,r[3],4);
r[2]=tmp;
goto P_0c09300a;
P_0c09300a: /* original f426, guest PC 0x0c09300a */
if(!s->budget--) { s->failed_pc=0x0c09300au; return 0; }
vf3_matrix_load(s,ram,4,r[2]+r[0]);
goto P_0c09300c;
P_0c09300c: /* original 7204, guest PC 0x0c09300c */
if(!s->budget--) { s->failed_pc=0x0c09300cu; return 0; }
r[2]+=0x00000004u;
goto P_0c09300e;
P_0c09300e: /* original 2322, guest PC 0x0c09300e */
if(!s->budget--) { s->failed_pc=0x0c09300eu; return 0; }
write(ram,r[3],r[2],4);
goto P_0c093010;
P_0c093010: /* original f04c, guest PC 0x0c093010 */
if(!s->budget--) { s->failed_pc=0x0c093010u; return 0; }
vf3_matrix_move(s,0,4);
goto P_0c093012;
P_0c093012: /* original f3e8, guest PC 0x0c093012 */
if(!s->budget--) { s->failed_pc=0x0c093012u; return 0; }
vf3_matrix_load(s,ram,3,r[14]);
goto P_0c093014;
P_0c093014: /* original f38e, guest PC 0x0c093014 */
if(!s->budget--) { s->failed_pc=0x0c093014u; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[8],fr[3],r[18]);
goto P_0c093016;
P_0c093016: /* original fe3a, guest PC 0x0c093016 */
if(!s->budget--) { s->failed_pc=0x0c093016u; return 0; }
vf3_matrix_store(s,ram,3,r[14]);
goto P_0c093018;
P_0c093018: /* original f2e6, guest PC 0x0c093018 */
if(!s->budget--) { s->failed_pc=0x0c093018u; return 0; }
vf3_matrix_load(s,ram,2,r[14]+r[0]);
goto P_0c09301a;
P_0c09301a: /* original f25e, guest PC 0x0c09301a */
if(!s->budget--) { s->failed_pc=0x0c09301au; return 0; }
fr[2]=vf3_fpu_mac(fr[0],fr[5],fr[2],r[18]);
goto P_0c09301c;
P_0c09301c: /* original fe27, guest PC 0x0c09301c */
if(!s->budget--) { s->failed_pc=0x0c09301cu; return 0; }
vf3_matrix_store(s,ram,2,r[14]+r[0]);
goto P_0c09301e;
P_0c09301e: /* original e008, guest PC 0x0c09301e */
if(!s->budget--) { s->failed_pc=0x0c09301eu; return 0; }
r[0]=0x00000008u;
goto P_0c093020;
P_0c093020: /* original f3e6, guest PC 0x0c093020 */
if(!s->budget--) { s->failed_pc=0x0c093020u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c093022;
P_0c093022: /* original f3ae, guest PC 0x0c093022 */
if(!s->budget--) { s->failed_pc=0x0c093022u; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[10],fr[3],r[18]);
goto P_0c093024;
P_0c093024: /* original fe37, guest PC 0x0c093024 */
if(!s->budget--) { s->failed_pc=0x0c093024u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c093026;
P_0c093026: /* original 000b, guest PC 0x0c093026 */
if(!s->budget--) { s->failed_pc=0x0c093026u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c093028: /* original 6ef6, guest PC 0x0c093028 */
if(!s->budget--) { s->failed_pc=0x0c093028u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c09302au,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c09302au; return 0; } return 1;
P_0c093266: /* original 2fe6, guest PC 0x0c093266 */
if(!s->budget--) { s->failed_pc=0x0c093266u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c093268;
P_0c093268: /* original 6e63, guest PC 0x0c093268 */
if(!s->budget--) { s->failed_pc=0x0c093268u; return 0; }
r[14]=r[6];
goto P_0c09326a;
P_0c09326a: /* original 2fd6, guest PC 0x0c09326a */
if(!s->budget--) { s->failed_pc=0x0c09326au; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09326c;
P_0c09326c: /* original 6d43, guest PC 0x0c09326c */
if(!s->budget--) { s->failed_pc=0x0c09326cu; return 0; }
r[13]=r[4];
goto P_0c09326e;
P_0c09326e: /* original 2fc6, guest PC 0x0c09326e */
if(!s->budget--) { s->failed_pc=0x0c09326eu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c093270;
P_0c093270: /* original 4f22, guest PC 0x0c093270 */
if(!s->budget--) { s->failed_pc=0x0c093270u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c093272;
P_0c093272: /* original 7fd0, guest PC 0x0c093272 */
if(!s->budget--) { s->failed_pc=0x0c093272u; return 0; }
r[15]+=0xffffffd0u;
goto P_0c093274;
P_0c093274: /* original 1f51, guest PC 0x0c093274 */
if(!s->budget--) { s->failed_pc=0x0c093274u; return 0; }
write(ram,r[15]+4,r[5],4);
goto P_0c093276;
P_0c093276: /* original 1f72, guest PC 0x0c093276 */
if(!s->budget--) { s->failed_pc=0x0c093276u; return 0; }
write(ram,r[15]+8,r[7],4);
goto P_0c093278;
P_0c093278: /* original e034, guest PC 0x0c093278 */
if(!s->budget--) { s->failed_pc=0x0c093278u; return 0; }
r[0]=0x00000034u;
goto P_0c09327a;
P_0c09327a: /* original 03ed, guest PC 0x0c09327a */
if(!s->budget--) { s->failed_pc=0x0c09327au; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c09327c;
P_0c09327c: /* original e501, guest PC 0x0c09327c */
if(!s->budget--) { s->failed_pc=0x0c09327cu; return 0; }
r[5]=0x00000001u;
goto P_0c09327e;
P_0c09327e: /* original 633d, guest PC 0x0c09327e */
if(!s->budget--) { s->failed_pc=0x0c09327eu; return 0; }
r[3]=r[3]&65535u;
goto P_0c093280;
P_0c093280: /* original 2358, guest PC 0x0c093280 */
if(!s->budget--) { s->failed_pc=0x0c093280u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[5])==0)!=0);
goto P_0c093282;
P_0c093282: /* original 8f03, guest PC 0x0c093282 */
if(!s->budget--) { s->failed_pc=0x0c093282u; return 0; }
cond=r[17]&1u;
write(ram,r[15],r[3],4);
if(!cond) { goto P_0c09328c; }
goto P_0c093286;
P_0c093284: /* original 2f32, guest PC 0x0c093284 */
if(!s->budget--) { s->failed_pc=0x0c093284u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c093286;
P_0c093286: /* original d20e, guest PC 0x0c093286 */
if(!s->budget--) { s->failed_pc=0x0c093286u; return 0; }
r[2]=read(ram,0x0c0932c0u,4);
goto P_0c093288;
P_0c093288: /* original 422b, guest PC 0x0c093288 */
if(!s->budget--) { s->failed_pc=0x0c093288u; return 0; }
target=r[2];
code_base=target&0xff000000u;
switch(target&0x1fffffffu) {
case 0x0c093412u: goto P_0c093412;
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
P_0c09328a: /* original 0009, guest PC 0x0c09328a */
if(!s->budget--) { s->failed_pc=0x0c09328au; return 0; }
goto P_0c09328c;
P_0c09328c: /* original 60f2, guest PC 0x0c09328c */
if(!s->budget--) { s->failed_pc=0x0c09328cu; return 0; }
tmp=read(ram,r[15],4);
r[0]=tmp;
goto P_0c09328e;
P_0c09328e: /* original c802, guest PC 0x0c09328e */
if(!s->budget--) { s->failed_pc=0x0c09328eu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&2u)==0)!=0);
goto P_0c093290;
P_0c093290: /* original 8947, guest PC 0x0c093290 */
if(!s->budget--) { s->failed_pc=0x0c093290u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c093322; }
goto P_0c093292;
P_0c093292: /* original 60f2, guest PC 0x0c093292 */
if(!s->budget--) { s->failed_pc=0x0c093292u; return 0; }
tmp=read(ram,r[15],4);
r[0]=tmp;
goto P_0c093294;
P_0c093294: /* original c804, guest PC 0x0c093294 */
if(!s->budget--) { s->failed_pc=0x0c093294u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&4u)==0)!=0);
goto P_0c093296;
P_0c093296: /* original 8d03, guest PC 0x0c093296 */
if(!s->budget--) { s->failed_pc=0x0c093296u; return 0; }
cond=r[17]&1u;
r[12]=0x00000058u;
if(cond) { goto P_0c0932a0; }
goto P_0c09329a;
P_0c093298: /* original ec58, guest PC 0x0c093298 */
if(!s->budget--) { s->failed_pc=0x0c093298u; return 0; }
r[12]=0x00000058u;
goto P_0c09329a;
P_0c09329a: /* original d30a, guest PC 0x0c09329a */
if(!s->budget--) { s->failed_pc=0x0c09329au; return 0; }
r[3]=read(ram,0x0c0932c4u,4);
goto P_0c09329c;
P_0c09329c: /* original 432b, guest PC 0x0c09329c */
if(!s->budget--) { s->failed_pc=0x0c09329cu; return 0; }
target=r[3];
code_base=target&0xff000000u;
switch(target&0x1fffffffu) {
case 0x0c09340cu: goto P_0c09340c;
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
P_0c09329e: /* original 0009, guest PC 0x0c09329e */
if(!s->budget--) { s->failed_pc=0x0c09329eu; return 0; }
goto P_0c0932a0;
P_0c0932a0: /* original 60f2, guest PC 0x0c0932a0 */
if(!s->budget--) { s->failed_pc=0x0c0932a0u; return 0; }
tmp=read(ram,r[15],4);
r[0]=tmp;
goto P_0c0932a2;
P_0c0932a2: /* original c840, guest PC 0x0c0932a2 */
if(!s->budget--) { s->failed_pc=0x0c0932a2u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&64u)==0)!=0);
goto P_0c0932a4;
P_0c0932a4: /* original 8910, guest PC 0x0c0932a4 */
if(!s->budget--) { s->failed_pc=0x0c0932a4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0932c8; }
goto P_0c0932a6;
P_0c0932a6: /* original a010, guest PC 0x0c0932a6 */
if(!s->budget--) { s->failed_pc=0x0c0932a6u; return 0; }
r[4]=0x00000000u;
goto P_0c0932ca;
P_0c0932a8: /* original e400, guest PC 0x0c0932a8 */
if(!s->budget--) { s->failed_pc=0x0c0932a8u; return 0; }
r[4]=0x00000000u;
if(!vf3_matrix_family(0x0c0932aau,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0932aau; return 0; } return 1;
P_0c0932c8: /* original 6453, guest PC 0x0c0932c8 */
if(!s->budget--) { s->failed_pc=0x0c0932c8u; return 0; }
r[4]=r[5];
goto P_0c0932ca;
P_0c0932ca: /* original 60f2, guest PC 0x0c0932ca */
if(!s->budget--) { s->failed_pc=0x0c0932cau; return 0; }
tmp=read(ram,r[15],4);
r[0]=tmp;
goto P_0c0932cc;
P_0c0932cc: /* original c820, guest PC 0x0c0932cc */
if(!s->budget--) { s->failed_pc=0x0c0932ccu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&32u)==0)!=0);
goto P_0c0932ce;
P_0c0932ce: /* original 8919, guest PC 0x0c0932ce */
if(!s->budget--) { s->failed_pc=0x0c0932ceu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c093304; }
goto P_0c0932d0;
P_0c0932d0: /* original e05c, guest PC 0x0c0932d0 */
if(!s->budget--) { s->failed_pc=0x0c0932d0u; return 0; }
r[0]=0x0000005cu;
goto P_0c0932d2;
P_0c0932d2: /* original f3d6, guest PC 0x0c0932d2 */
if(!s->budget--) { s->failed_pc=0x0c0932d2u; return 0; }
vf3_matrix_load(s,ram,3,r[13]+r[0]);
goto P_0c0932d4;
P_0c0932d4: /* original e074, guest PC 0x0c0932d4 */
if(!s->budget--) { s->failed_pc=0x0c0932d4u; return 0; }
r[0]=0x00000074u;
goto P_0c0932d6;
P_0c0932d6: /* original fd37, guest PC 0x0c0932d6 */
if(!s->budget--) { s->failed_pc=0x0c0932d6u; return 0; }
vf3_matrix_store(s,ram,3,r[13]+r[0]);
goto P_0c0932d8;
P_0c0932d8: /* original e060, guest PC 0x0c0932d8 */
if(!s->budget--) { s->failed_pc=0x0c0932d8u; return 0; }
r[0]=0x00000060u;
goto P_0c0932da;
P_0c0932da: /* original f3d6, guest PC 0x0c0932da */
if(!s->budget--) { s->failed_pc=0x0c0932dau; return 0; }
vf3_matrix_load(s,ram,3,r[13]+r[0]);
goto P_0c0932dc;
P_0c0932dc: /* original e078, guest PC 0x0c0932dc */
if(!s->budget--) { s->failed_pc=0x0c0932dcu; return 0; }
r[0]=0x00000078u;
goto P_0c0932de;
P_0c0932de: /* original fd37, guest PC 0x0c0932de */
if(!s->budget--) { s->failed_pc=0x0c0932deu; return 0; }
vf3_matrix_store(s,ram,3,r[13]+r[0]);
goto P_0c0932e0;
P_0c0932e0: /* original e064, guest PC 0x0c0932e0 */
if(!s->budget--) { s->failed_pc=0x0c0932e0u; return 0; }
r[0]=0x00000064u;
goto P_0c0932e2;
P_0c0932e2: /* original f3d6, guest PC 0x0c0932e2 */
if(!s->budget--) { s->failed_pc=0x0c0932e2u; return 0; }
vf3_matrix_load(s,ram,3,r[13]+r[0]);
goto P_0c0932e4;
P_0c0932e4: /* original e07c, guest PC 0x0c0932e4 */
if(!s->budget--) { s->failed_pc=0x0c0932e4u; return 0; }
r[0]=0x0000007cu;
goto P_0c0932e6;
P_0c0932e6: /* original fd37, guest PC 0x0c0932e6 */
if(!s->budget--) { s->failed_pc=0x0c0932e6u; return 0; }
vf3_matrix_store(s,ram,3,r[13]+r[0]);
goto P_0c0932e8;
P_0c0932e8: /* original e024, guest PC 0x0c0932e8 */
if(!s->budget--) { s->failed_pc=0x0c0932e8u; return 0; }
r[0]=0x00000024u;
goto P_0c0932ea;
P_0c0932ea: /* original f3f6, guest PC 0x0c0932ea */
if(!s->budget--) { s->failed_pc=0x0c0932eau; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0932ec;
P_0c0932ec: /* original e068, guest PC 0x0c0932ec */
if(!s->budget--) { s->failed_pc=0x0c0932ecu; return 0; }
r[0]=0x00000068u;
goto P_0c0932ee;
P_0c0932ee: /* original fd37, guest PC 0x0c0932ee */
if(!s->budget--) { s->failed_pc=0x0c0932eeu; return 0; }
vf3_matrix_store(s,ram,3,r[13]+r[0]);
goto P_0c0932f0;
P_0c0932f0: /* original e028, guest PC 0x0c0932f0 */
if(!s->budget--) { s->failed_pc=0x0c0932f0u; return 0; }
r[0]=0x00000028u;
goto P_0c0932f2;
P_0c0932f2: /* original f3f6, guest PC 0x0c0932f2 */
if(!s->budget--) { s->failed_pc=0x0c0932f2u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0932f4;
P_0c0932f4: /* original e06c, guest PC 0x0c0932f4 */
if(!s->budget--) { s->failed_pc=0x0c0932f4u; return 0; }
r[0]=0x0000006cu;
goto P_0c0932f6;
P_0c0932f6: /* original fd37, guest PC 0x0c0932f6 */
if(!s->budget--) { s->failed_pc=0x0c0932f6u; return 0; }
vf3_matrix_store(s,ram,3,r[13]+r[0]);
goto P_0c0932f8;
P_0c0932f8: /* original e02c, guest PC 0x0c0932f8 */
if(!s->budget--) { s->failed_pc=0x0c0932f8u; return 0; }
r[0]=0x0000002cu;
goto P_0c0932fa;
P_0c0932fa: /* original d31c, guest PC 0x0c0932fa */
if(!s->budget--) { s->failed_pc=0x0c0932fau; return 0; }
r[3]=read(ram,0x0c09336cu,4);
goto P_0c0932fc;
P_0c0932fc: /* original f3f6, guest PC 0x0c0932fc */
if(!s->budget--) { s->failed_pc=0x0c0932fcu; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0932fe;
P_0c0932fe: /* original e070, guest PC 0x0c0932fe */
if(!s->budget--) { s->failed_pc=0x0c0932feu; return 0; }
r[0]=0x00000070u;
goto P_0c093300;
P_0c093300: /* original 432b, guest PC 0x0c093300 */
if(!s->budget--) { s->failed_pc=0x0c093300u; return 0; }
target=r[3];
vf3_matrix_store(s,ram,3,r[13]+r[0]);
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
P_0c093302: /* original fd37, guest PC 0x0c093302 */
if(!s->budget--) { s->failed_pc=0x0c093302u; return 0; }
vf3_matrix_store(s,ram,3,r[13]+r[0]);
goto P_0c093304;
P_0c093304: /* original 62f3, guest PC 0x0c093304 */
if(!s->budget--) { s->failed_pc=0x0c093304u; return 0; }
r[2]=r[15];
goto P_0c093306;
P_0c093306: /* original 2f26, guest PC 0x0c093306 */
if(!s->budget--) { s->failed_pc=0x0c093306u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c093308;
P_0c093308: /* original 63f3, guest PC 0x0c093308 */
if(!s->budget--) { s->failed_pc=0x0c093308u; return 0; }
r[3]=r[15];
goto P_0c09330a;
P_0c09330a: /* original 7328, guest PC 0x0c09330a */
if(!s->budget--) { s->failed_pc=0x0c09330au; return 0; }
r[3]+=0x00000028u;
goto P_0c09330c;
P_0c09330c: /* original 2f36, guest PC 0x0c09330c */
if(!s->budget--) { s->failed_pc=0x0c09330cu; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09330e;
P_0c09330e: /* original e050, guest PC 0x0c09330e */
if(!s->budget--) { s->failed_pc=0x0c09330eu; return 0; }
r[0]=0x00000050u;
goto P_0c093310;
P_0c093310: /* original 2f46, guest PC 0x0c093310 */
if(!s->budget--) { s->failed_pc=0x0c093310u; return 0; }
tmp=r[4]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c093312;
P_0c093312: /* original 66e3, guest PC 0x0c093312 */
if(!s->budget--) { s->failed_pc=0x0c093312u; return 0; }
r[6]=r[14];
goto P_0c093314;
P_0c093314: /* original 55f4, guest PC 0x0c093314 */
if(!s->budget--) { s->failed_pc=0x0c093314u; return 0; }
r[5]=read(ram,r[15]+16,4);
goto P_0c093316;
P_0c093316: /* original d316, guest PC 0x0c093316 */
if(!s->budget--) { s->failed_pc=0x0c093316u; return 0; }
r[3]=read(ram,0x0c093370u,4);
goto P_0c093318;
P_0c093318: /* original 07fe, guest PC 0x0c093318 */
if(!s->budget--) { s->failed_pc=0x0c093318u; return 0; }
r[7]=read(ram,r[15]+r[0],4);
goto P_0c09331a;
P_0c09331a: /* original 430b, guest PC 0x0c09331a */
if(!s->budget--) { s->failed_pc=0x0c09331au; return 0; }
target=r[3];
r[16]=code_base|0x0c09331eu;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09331eu) { target=s->pc; goto dispatch; }
goto P_0c09331e;
P_0c09331c: /* original 64d3, guest PC 0x0c09331c */
if(!s->budget--) { s->failed_pc=0x0c09331cu; return 0; }
r[4]=r[13];
goto P_0c09331e;
P_0c09331e: /* original a001, guest PC 0x0c09331e */
if(!s->budget--) { s->failed_pc=0x0c09331eu; return 0; }
r[15]+=0x0000000cu;
goto P_0c093324;
P_0c093320: /* original 7f0c, guest PC 0x0c093320 */
if(!s->budget--) { s->failed_pc=0x0c093320u; return 0; }
r[15]+=0x0000000cu;
goto P_0c093322;
P_0c093322: /* original ec38, guest PC 0x0c093322 */
if(!s->budget--) { s->failed_pc=0x0c093322u; return 0; }
r[12]=0x00000038u;
goto P_0c093324;
P_0c093324: /* original 54f1, guest PC 0x0c093324 */
if(!s->budget--) { s->failed_pc=0x0c093324u; return 0; }
r[4]=read(ram,r[15]+4,4);
goto P_0c093326;
P_0c093326: /* original e061, guest PC 0x0c093326 */
if(!s->budget--) { s->failed_pc=0x0c093326u; return 0; }
r[0]=0x00000061u;
goto P_0c093328;
P_0c093328: /* original 044c, guest PC 0x0c093328 */
if(!s->budget--) { s->failed_pc=0x0c093328u; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c09332a;
P_0c09332a: /* original 644c, guest PC 0x0c09332a */
if(!s->budget--) { s->failed_pc=0x0c09332au; return 0; }
r[4]=r[4]&255u;
goto P_0c09332c;
P_0c09332c: /* original 6043, guest PC 0x0c09332c */
if(!s->budget--) { s->failed_pc=0x0c09332cu; return 0; }
r[0]=r[4];
goto P_0c09332e;
P_0c09332e: /* original 8801, guest PC 0x0c09332e */
if(!s->budget--) { s->failed_pc=0x0c09332eu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c093330;
P_0c093330: /* original 8913, guest PC 0x0c093330 */
if(!s->budget--) { s->failed_pc=0x0c093330u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09335a; }
goto P_0c093332;
P_0c093332: /* original 6043, guest PC 0x0c093332 */
if(!s->budget--) { s->failed_pc=0x0c093332u; return 0; }
r[0]=r[4];
goto P_0c093334;
P_0c093334: /* original 8805, guest PC 0x0c093334 */
if(!s->budget--) { s->failed_pc=0x0c093334u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000005u)!=0);
goto P_0c093336;
P_0c093336: /* original 8910, guest PC 0x0c093336 */
if(!s->budget--) { s->failed_pc=0x0c093336u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09335a; }
goto P_0c093338;
P_0c093338: /* original e024, guest PC 0x0c093338 */
if(!s->budget--) { s->failed_pc=0x0c093338u; return 0; }
r[0]=0x00000024u;
goto P_0c09333a;
P_0c09333a: /* original f3f6, guest PC 0x0c09333a */
if(!s->budget--) { s->failed_pc=0x0c09333au; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c09333c;
P_0c09333c: /* original e018, guest PC 0x0c09333c */
if(!s->budget--) { s->failed_pc=0x0c09333cu; return 0; }
r[0]=0x00000018u;
goto P_0c09333e;
P_0c09333e: /* original ff37, guest PC 0x0c09333e */
if(!s->budget--) { s->failed_pc=0x0c09333eu; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c093340;
P_0c093340: /* original e024, guest PC 0x0c093340 */
if(!s->budget--) { s->failed_pc=0x0c093340u; return 0; }
r[0]=0x00000024u;
goto P_0c093342;
P_0c093342: /* original f3e6, guest PC 0x0c093342 */
if(!s->budget--) { s->failed_pc=0x0c093342u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c093344;
P_0c093344: /* original e028, guest PC 0x0c093344 */
if(!s->budget--) { s->failed_pc=0x0c093344u; return 0; }
r[0]=0x00000028u;
goto P_0c093346;
P_0c093346: /* original f2f6, guest PC 0x0c093346 */
if(!s->budget--) { s->failed_pc=0x0c093346u; return 0; }
vf3_matrix_load(s,ram,2,r[15]+r[0]);
goto P_0c093348;
P_0c093348: /* original e01c, guest PC 0x0c093348 */
if(!s->budget--) { s->failed_pc=0x0c093348u; return 0; }
r[0]=0x0000001cu;
goto P_0c09334a;
P_0c09334a: /* original f231, guest PC 0x0c09334a */
if(!s->budget--) { s->failed_pc=0x0c09334au; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'-');
goto P_0c09334c;
P_0c09334c: /* original ff27, guest PC 0x0c09334c */
if(!s->budget--) { s->failed_pc=0x0c09334cu; return 0; }
vf3_matrix_store(s,ram,2,r[15]+r[0]);
goto P_0c09334e;
P_0c09334e: /* original e02c, guest PC 0x0c09334e */
if(!s->budget--) { s->failed_pc=0x0c09334eu; return 0; }
r[0]=0x0000002cu;
goto P_0c093350;
P_0c093350: /* original d308, guest PC 0x0c093350 */
if(!s->budget--) { s->failed_pc=0x0c093350u; return 0; }
r[3]=read(ram,0x0c093374u,4);
goto P_0c093352;
P_0c093352: /* original f3f6, guest PC 0x0c093352 */
if(!s->budget--) { s->failed_pc=0x0c093352u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c093354;
P_0c093354: /* original e020, guest PC 0x0c093354 */
if(!s->budget--) { s->failed_pc=0x0c093354u; return 0; }
r[0]=0x00000020u;
goto P_0c093356;
P_0c093356: /* original 432b, guest PC 0x0c093356 */
if(!s->budget--) { s->failed_pc=0x0c093356u; return 0; }
target=r[3];
vf3_matrix_store(s,ram,3,r[15]+r[0]);
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
P_0c093358: /* original ff37, guest PC 0x0c093358 */
if(!s->budget--) { s->failed_pc=0x0c093358u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c09335a;
P_0c09335a: /* original 65f3, guest PC 0x0c09335a */
if(!s->budget--) { s->failed_pc=0x0c09335au; return 0; }
r[5]=r[15];
goto P_0c09335c;
P_0c09335c: /* original 64f3, guest PC 0x0c09335c */
if(!s->budget--) { s->failed_pc=0x0c09335cu; return 0; }
r[4]=r[15];
goto P_0c09335e;
P_0c09335e: /* original 66d3, guest PC 0x0c09335e */
if(!s->budget--) { s->failed_pc=0x0c09335eu; return 0; }
r[6]=r[13];
goto P_0c093360;
P_0c093360: /* original 7418, guest PC 0x0c093360 */
if(!s->budget--) { s->failed_pc=0x0c093360u; return 0; }
r[4]+=0x00000018u;
goto P_0c093362;
P_0c093362: /* original 765c, guest PC 0x0c093362 */
if(!s->budget--) { s->failed_pc=0x0c093362u; return 0; }
r[6]+=0x0000005cu;
goto P_0c093364;
P_0c093364: /* original 7524, guest PC 0x0c093364 */
if(!s->budget--) { s->failed_pc=0x0c093364u; return 0; }
r[5]+=0x00000024u;
goto P_0c093366;
P_0c093366: /* original a007, guest PC 0x0c093366 */
if(!s->budget--) { s->failed_pc=0x0c093366u; return 0; }
goto P_0c093378;
P_0c093368: /* original 0009, guest PC 0x0c093368 */
if(!s->budget--) { s->failed_pc=0x0c093368u; return 0; }
if(!vf3_matrix_family(0x0c09336au,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c09336au; return 0; } return 1;
P_0c093378: /* original f059, guest PC 0x0c093378 */
if(!s->budget--) { s->failed_pc=0x0c093378u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c09337a;
P_0c09337a: /* original f369, guest PC 0x0c09337a */
if(!s->budget--) { s->failed_pc=0x0c09337au; return 0; }
vf3_matrix_load(s,ram,3,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c09337c;
P_0c09337c: /* original f159, guest PC 0x0c09337c */
if(!s->budget--) { s->failed_pc=0x0c09337cu; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c09337e;
P_0c09337e: /* original f469, guest PC 0x0c09337e */
if(!s->budget--) { s->failed_pc=0x0c09337eu; return 0; }
vf3_matrix_load(s,ram,4,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c093380;
P_0c093380: /* original f259, guest PC 0x0c093380 */
if(!s->budget--) { s->failed_pc=0x0c093380u; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c093382;
P_0c093382: /* original f569, guest PC 0x0c093382 */
if(!s->budget--) { s->failed_pc=0x0c093382u; return 0; }
vf3_matrix_load(s,ram,5,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c093384;
P_0c093384: /* original 740c, guest PC 0x0c093384 */
if(!s->budget--) { s->failed_pc=0x0c093384u; return 0; }
r[4]+=0x0000000cu;
goto P_0c093386;
P_0c093386: /* original f030, guest PC 0x0c093386 */
if(!s->budget--) { s->failed_pc=0x0c093386u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'+');
goto P_0c093388;
P_0c093388: /* original f250, guest PC 0x0c093388 */
if(!s->budget--) { s->failed_pc=0x0c093388u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'+');
goto P_0c09338a;
P_0c09338a: /* original f140, guest PC 0x0c09338a */
if(!s->budget--) { s->failed_pc=0x0c09338au; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'+');
goto P_0c09338c;
P_0c09338c: /* original f42b, guest PC 0x0c09338c */
if(!s->budget--) { s->failed_pc=0x0c09338cu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c09338e;
P_0c09338e: /* original f41b, guest PC 0x0c09338e */
if(!s->budget--) { s->failed_pc=0x0c09338eu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c093390;
P_0c093390: /* original f40b, guest PC 0x0c093390 */
if(!s->budget--) { s->failed_pc=0x0c093390u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c093392;
P_0c093392: /* original 0009, guest PC 0x0c093392 */
if(!s->budget--) { s->failed_pc=0x0c093392u; return 0; }
goto P_0c093394;
P_0c093394: /* original 63f3, guest PC 0x0c093394 */
if(!s->budget--) { s->failed_pc=0x0c093394u; return 0; }
r[3]=r[15];
goto P_0c093396;
P_0c093396: /* original e044, guest PC 0x0c093396 */
if(!s->budget--) { s->failed_pc=0x0c093396u; return 0; }
r[0]=0x00000044u;
goto P_0c093398;
P_0c093398: /* original 2f36, guest PC 0x0c093398 */
if(!s->budget--) { s->failed_pc=0x0c093398u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09339a;
P_0c09339a: /* original 65e3, guest PC 0x0c09339a */
if(!s->budget--) { s->failed_pc=0x0c09339au; return 0; }
r[5]=r[14];
goto P_0c09339c;
P_0c09339c: /* original 02fe, guest PC 0x0c09339c */
if(!s->budget--) { s->failed_pc=0x0c09339cu; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c09339e;
P_0c09339e: /* original 2f26, guest PC 0x0c09339e */
if(!s->budget--) { s->failed_pc=0x0c09339eu; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0933a0;
P_0c0933a0: /* original 53f4, guest PC 0x0c0933a0 */
if(!s->budget--) { s->failed_pc=0x0c0933a0u; return 0; }
r[3]=read(ram,r[15]+16,4);
goto P_0c0933a2;
P_0c0933a2: /* original 2f36, guest PC 0x0c0933a2 */
if(!s->budget--) { s->failed_pc=0x0c0933a2u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0933a4;
P_0c0933a4: /* original 66f3, guest PC 0x0c0933a4 */
if(!s->budget--) { s->failed_pc=0x0c0933a4u; return 0; }
r[6]=r[15];
goto P_0c0933a6;
P_0c0933a6: /* original d352, guest PC 0x0c0933a6 */
if(!s->budget--) { s->failed_pc=0x0c0933a6u; return 0; }
r[3]=read(ram,0x0c0934f0u,4);
goto P_0c0933a8;
P_0c0933a8: /* original 67f3, guest PC 0x0c0933a8 */
if(!s->budget--) { s->failed_pc=0x0c0933a8u; return 0; }
r[7]=r[15];
goto P_0c0933aa;
P_0c0933aa: /* original 7730, guest PC 0x0c0933aa */
if(!s->budget--) { s->failed_pc=0x0c0933aau; return 0; }
r[7]+=0x00000030u;
goto P_0c0933ac;
P_0c0933ac: /* original 7624, guest PC 0x0c0933ac */
if(!s->budget--) { s->failed_pc=0x0c0933acu; return 0; }
r[6]+=0x00000024u;
goto P_0c0933ae;
P_0c0933ae: /* original 430b, guest PC 0x0c0933ae */
if(!s->budget--) { s->failed_pc=0x0c0933aeu; return 0; }
target=r[3];
r[16]=code_base|0x0c0933b2u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0933b2u) { target=s->pc; goto dispatch; }
goto P_0c0933b2;
P_0c0933b0: /* original 64d3, guest PC 0x0c0933b0 */
if(!s->budget--) { s->failed_pc=0x0c0933b0u; return 0; }
r[4]=r[13];
goto P_0c0933b2;
P_0c0933b2: /* original 7f0c, guest PC 0x0c0933b2 */
if(!s->budget--) { s->failed_pc=0x0c0933b2u; return 0; }
r[15]+=0x0000000cu;
goto P_0c0933b4;
P_0c0933b4: /* original d24f, guest PC 0x0c0933b4 */
if(!s->budget--) { s->failed_pc=0x0c0933b4u; return 0; }
r[2]=read(ram,0x0c0934f4u,4);
goto P_0c0933b6;
P_0c0933b6: /* original 65f3, guest PC 0x0c0933b6 */
if(!s->budget--) { s->failed_pc=0x0c0933b6u; return 0; }
r[5]=r[15];
goto P_0c0933b8;
P_0c0933b8: /* original 66f3, guest PC 0x0c0933b8 */
if(!s->budget--) { s->failed_pc=0x0c0933b8u; return 0; }
r[6]=r[15];
goto P_0c0933ba;
P_0c0933ba: /* original 67f3, guest PC 0x0c0933ba */
if(!s->budget--) { s->failed_pc=0x0c0933bau; return 0; }
r[7]=r[15];
goto P_0c0933bc;
P_0c0933bc: /* original 7518, guest PC 0x0c0933bc */
if(!s->budget--) { s->failed_pc=0x0c0933bcu; return 0; }
r[5]+=0x00000018u;
goto P_0c0933be;
P_0c0933be: /* original 7624, guest PC 0x0c0933be */
if(!s->budget--) { s->failed_pc=0x0c0933beu; return 0; }
r[6]+=0x00000024u;
goto P_0c0933c0;
P_0c0933c0: /* original 770c, guest PC 0x0c0933c0 */
if(!s->budget--) { s->failed_pc=0x0c0933c0u; return 0; }
r[7]+=0x0000000cu;
goto P_0c0933c2;
P_0c0933c2: /* original 420b, guest PC 0x0c0933c2 */
if(!s->budget--) { s->failed_pc=0x0c0933c2u; return 0; }
target=r[2];
r[16]=code_base|0x0c0933c6u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0933c6u) { target=s->pc; goto dispatch; }
goto P_0c0933c6;
P_0c0933c4: /* original 64e3, guest PC 0x0c0933c4 */
if(!s->budget--) { s->failed_pc=0x0c0933c4u; return 0; }
r[4]=r[14];
goto P_0c0933c6;
P_0c0933c6: /* original e018, guest PC 0x0c0933c6 */
if(!s->budget--) { s->failed_pc=0x0c0933c6u; return 0; }
r[0]=0x00000018u;
goto P_0c0933c8;
P_0c0933c8: /* original f3f6, guest PC 0x0c0933c8 */
if(!s->budget--) { s->failed_pc=0x0c0933c8u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0933ca;
P_0c0933ca: /* original e01c, guest PC 0x0c0933ca */
if(!s->budget--) { s->failed_pc=0x0c0933cau; return 0; }
r[0]=0x0000001cu;
goto P_0c0933cc;
P_0c0933cc: /* original fe3a, guest PC 0x0c0933cc */
if(!s->budget--) { s->failed_pc=0x0c0933ccu; return 0; }
vf3_matrix_store(s,ram,3,r[14]);
goto P_0c0933ce;
P_0c0933ce: /* original f3f6, guest PC 0x0c0933ce */
if(!s->budget--) { s->failed_pc=0x0c0933ceu; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0933d0;
P_0c0933d0: /* original e004, guest PC 0x0c0933d0 */
if(!s->budget--) { s->failed_pc=0x0c0933d0u; return 0; }
r[0]=0x00000004u;
goto P_0c0933d2;
P_0c0933d2: /* original fe37, guest PC 0x0c0933d2 */
if(!s->budget--) { s->failed_pc=0x0c0933d2u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c0933d4;
P_0c0933d4: /* original e020, guest PC 0x0c0933d4 */
if(!s->budget--) { s->failed_pc=0x0c0933d4u; return 0; }
r[0]=0x00000020u;
goto P_0c0933d6;
P_0c0933d6: /* original f3f6, guest PC 0x0c0933d6 */
if(!s->budget--) { s->failed_pc=0x0c0933d6u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0933d8;
P_0c0933d8: /* original e008, guest PC 0x0c0933d8 */
if(!s->budget--) { s->failed_pc=0x0c0933d8u; return 0; }
r[0]=0x00000008u;
goto P_0c0933da;
P_0c0933da: /* original fe37, guest PC 0x0c0933da */
if(!s->budget--) { s->failed_pc=0x0c0933dau; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c0933dc;
P_0c0933dc: /* original e024, guest PC 0x0c0933dc */
if(!s->budget--) { s->failed_pc=0x0c0933dcu; return 0; }
r[0]=0x00000024u;
goto P_0c0933de;
P_0c0933de: /* original f3f6, guest PC 0x0c0933de */
if(!s->budget--) { s->failed_pc=0x0c0933deu; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0933e0;
P_0c0933e0: /* original e00c, guest PC 0x0c0933e0 */
if(!s->budget--) { s->failed_pc=0x0c0933e0u; return 0; }
r[0]=0x0000000cu;
goto P_0c0933e2;
P_0c0933e2: /* original fe37, guest PC 0x0c0933e2 */
if(!s->budget--) { s->failed_pc=0x0c0933e2u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c0933e4;
P_0c0933e4: /* original e028, guest PC 0x0c0933e4 */
if(!s->budget--) { s->failed_pc=0x0c0933e4u; return 0; }
r[0]=0x00000028u;
goto P_0c0933e6;
P_0c0933e6: /* original f3f6, guest PC 0x0c0933e6 */
if(!s->budget--) { s->failed_pc=0x0c0933e6u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0933e8;
P_0c0933e8: /* original e010, guest PC 0x0c0933e8 */
if(!s->budget--) { s->failed_pc=0x0c0933e8u; return 0; }
r[0]=0x00000010u;
goto P_0c0933ea;
P_0c0933ea: /* original fe37, guest PC 0x0c0933ea */
if(!s->budget--) { s->failed_pc=0x0c0933eau; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c0933ec;
P_0c0933ec: /* original e02c, guest PC 0x0c0933ec */
if(!s->budget--) { s->failed_pc=0x0c0933ecu; return 0; }
r[0]=0x0000002cu;
goto P_0c0933ee;
P_0c0933ee: /* original f3f6, guest PC 0x0c0933ee */
if(!s->budget--) { s->failed_pc=0x0c0933eeu; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0933f0;
P_0c0933f0: /* original e014, guest PC 0x0c0933f0 */
if(!s->budget--) { s->failed_pc=0x0c0933f0u; return 0; }
r[0]=0x00000014u;
goto P_0c0933f2;
P_0c0933f2: /* original fe37, guest PC 0x0c0933f2 */
if(!s->budget--) { s->failed_pc=0x0c0933f2u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c0933f4;
P_0c0933f4: /* original e018, guest PC 0x0c0933f4 */
if(!s->budget--) { s->failed_pc=0x0c0933f4u; return 0; }
r[0]=0x00000018u;
goto P_0c0933f6;
P_0c0933f6: /* original f3f6, guest PC 0x0c0933f6 */
if(!s->budget--) { s->failed_pc=0x0c0933f6u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0933f8;
P_0c0933f8: /* original e024, guest PC 0x0c0933f8 */
if(!s->budget--) { s->failed_pc=0x0c0933f8u; return 0; }
r[0]=0x00000024u;
goto P_0c0933fa;
P_0c0933fa: /* original ff37, guest PC 0x0c0933fa */
if(!s->budget--) { s->failed_pc=0x0c0933fau; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0933fc;
P_0c0933fc: /* original e01c, guest PC 0x0c0933fc */
if(!s->budget--) { s->failed_pc=0x0c0933fcu; return 0; }
r[0]=0x0000001cu;
goto P_0c0933fe;
P_0c0933fe: /* original f3f6, guest PC 0x0c0933fe */
if(!s->budget--) { s->failed_pc=0x0c0933feu; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c093400;
P_0c093400: /* original e028, guest PC 0x0c093400 */
if(!s->budget--) { s->failed_pc=0x0c093400u; return 0; }
r[0]=0x00000028u;
goto P_0c093402;
P_0c093402: /* original ff37, guest PC 0x0c093402 */
if(!s->budget--) { s->failed_pc=0x0c093402u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c093404;
P_0c093404: /* original e020, guest PC 0x0c093404 */
if(!s->budget--) { s->failed_pc=0x0c093404u; return 0; }
r[0]=0x00000020u;
goto P_0c093406;
P_0c093406: /* original f3f6, guest PC 0x0c093406 */
if(!s->budget--) { s->failed_pc=0x0c093406u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c093408;
P_0c093408: /* original e02c, guest PC 0x0c093408 */
if(!s->budget--) { s->failed_pc=0x0c093408u; return 0; }
r[0]=0x0000002cu;
goto P_0c09340a;
P_0c09340a: /* original ff37, guest PC 0x0c09340a */
if(!s->budget--) { s->failed_pc=0x0c09340au; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c09340c;
P_0c09340c: /* original d33a, guest PC 0x0c09340c */
if(!s->budget--) { s->failed_pc=0x0c09340cu; return 0; }
r[3]=read(ram,0x0c0934f8u,4);
goto P_0c09340e;
P_0c09340e: /* original 432b, guest PC 0x0c09340e */
if(!s->budget--) { s->failed_pc=0x0c09340eu; return 0; }
target=r[3];
r[14]+=r[12];
code_base=target&0xff000000u;
switch(target&0x1fffffffu) {
case 0x0c093278u: goto P_0c093278;
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
P_0c093410: /* original 3ecc, guest PC 0x0c093410 */
if(!s->budget--) { s->failed_pc=0x0c093410u; return 0; }
r[14]+=r[12];
goto P_0c093412;
P_0c093412: /* original 7f30, guest PC 0x0c093412 */
if(!s->budget--) { s->failed_pc=0x0c093412u; return 0; }
r[15]+=0x00000030u;
goto P_0c093414;
P_0c093414: /* original 4f26, guest PC 0x0c093414 */
if(!s->budget--) { s->failed_pc=0x0c093414u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c093416;
P_0c093416: /* original 6cf6, guest PC 0x0c093416 */
if(!s->budget--) { s->failed_pc=0x0c093416u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c093418;
P_0c093418: /* original 6df6, guest PC 0x0c093418 */
if(!s->budget--) { s->failed_pc=0x0c093418u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c09341a;
P_0c09341a: /* original 000b, guest PC 0x0c09341a */
if(!s->budget--) { s->failed_pc=0x0c09341au; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c09341c: /* original 6ef6, guest PC 0x0c09341c */
if(!s->budget--) { s->failed_pc=0x0c09341cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c09341eu,s,ram);
unsupported: s->failed_pc=target; return 0;
}
