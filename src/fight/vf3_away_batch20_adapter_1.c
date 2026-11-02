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
int vf3_away_batch20_adapter_1(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
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
case 0x0c038600u: goto P_0c038600;
case 0x0c038602u: goto P_0c038602;
case 0x0c038604u: goto P_0c038604;
case 0x0c038606u: goto P_0c038606;
case 0x0c038608u: goto P_0c038608;
case 0x0c03860au: goto P_0c03860a;
case 0x0c03860cu: goto P_0c03860c;
case 0x0c03860eu: goto P_0c03860e;
case 0x0c038610u: goto P_0c038610;
case 0x0c038612u: goto P_0c038612;
case 0x0c038614u: goto P_0c038614;
case 0x0c038616u: goto P_0c038616;
case 0x0c038618u: goto P_0c038618;
case 0x0c03861au: goto P_0c03861a;
case 0x0c03861cu: goto P_0c03861c;
case 0x0c03861eu: goto P_0c03861e;
case 0x0c038620u: goto P_0c038620;
case 0x0c038622u: goto P_0c038622;
case 0x0c038624u: goto P_0c038624;
case 0x0c038626u: goto P_0c038626;
case 0x0c038628u: goto P_0c038628;
case 0x0c03862au: goto P_0c03862a;
case 0x0c03862cu: goto P_0c03862c;
case 0x0c03862eu: goto P_0c03862e;
case 0x0c038630u: goto P_0c038630;
case 0x0c038632u: goto P_0c038632;
case 0x0c038634u: goto P_0c038634;
case 0x0c038636u: goto P_0c038636;
case 0x0c038638u: goto P_0c038638;
case 0x0c03863au: goto P_0c03863a;
case 0x0c03863cu: goto P_0c03863c;
case 0x0c03863eu: goto P_0c03863e;
case 0x0c038640u: goto P_0c038640;
case 0x0c038642u: goto P_0c038642;
case 0x0c038644u: goto P_0c038644;
case 0x0c038646u: goto P_0c038646;
case 0x0c038648u: goto P_0c038648;
case 0x0c03864au: goto P_0c03864a;
case 0x0c03864cu: goto P_0c03864c;
case 0x0c03864eu: goto P_0c03864e;
case 0x0c038650u: goto P_0c038650;
case 0x0c038652u: goto P_0c038652;
case 0x0c038654u: goto P_0c038654;
case 0x0c038656u: goto P_0c038656;
case 0x0c038658u: goto P_0c038658;
case 0x0c03865au: goto P_0c03865a;
case 0x0c03865cu: goto P_0c03865c;
case 0x0c038760u: goto P_0c038760;
case 0x0c038762u: goto P_0c038762;
case 0x0c038764u: goto P_0c038764;
case 0x0c038860u: goto P_0c038860;
case 0x0c038862u: goto P_0c038862;
case 0x0c038864u: goto P_0c038864;
case 0x0c038866u: goto P_0c038866;
case 0x0c038868u: goto P_0c038868;
case 0x0c03886au: goto P_0c03886a;
case 0x0c03886cu: goto P_0c03886c;
case 0x0c03886eu: goto P_0c03886e;
case 0x0c038870u: goto P_0c038870;
case 0x0c038872u: goto P_0c038872;
case 0x0c038874u: goto P_0c038874;
case 0x0c038876u: goto P_0c038876;
case 0x0c038878u: goto P_0c038878;
case 0x0c03887au: goto P_0c03887a;
case 0x0c03887cu: goto P_0c03887c;
case 0x0c038880u: goto P_0c038880;
case 0x0c038882u: goto P_0c038882;
case 0x0c038884u: goto P_0c038884;
case 0x0c038886u: goto P_0c038886;
case 0x0c038888u: goto P_0c038888;
case 0x0c03888au: goto P_0c03888a;
case 0x0c03888cu: goto P_0c03888c;
case 0x0c03888eu: goto P_0c03888e;
case 0x0c038890u: goto P_0c038890;
case 0x0c038892u: goto P_0c038892;
case 0x0c038894u: goto P_0c038894;
case 0x0c038896u: goto P_0c038896;
case 0x0c038898u: goto P_0c038898;
case 0x0c03889au: goto P_0c03889a;
case 0x0c03889cu: goto P_0c03889c;
case 0x0c03889eu: goto P_0c03889e;
case 0x0c0388a0u: goto P_0c0388a0;
case 0x0c0388b0u: goto P_0c0388b0;
case 0x0c0388b2u: goto P_0c0388b2;
case 0x0c0388b4u: goto P_0c0388b4;
case 0x0c0388c0u: goto P_0c0388c0;
case 0x0c0388c2u: goto P_0c0388c2;
case 0x0c0388c4u: goto P_0c0388c4;
case 0x0c0388c6u: goto P_0c0388c6;
case 0x0c0388c8u: goto P_0c0388c8;
case 0x0c0388cau: goto P_0c0388ca;
case 0x0c0388ccu: goto P_0c0388cc;
case 0x0c0388ceu: goto P_0c0388ce;
case 0x0c0388d0u: goto P_0c0388d0;
case 0x0c0388d2u: goto P_0c0388d2;
case 0x0c0388d4u: goto P_0c0388d4;
case 0x0c0388d6u: goto P_0c0388d6;
case 0x0c0388d8u: goto P_0c0388d8;
case 0x0c0388dau: goto P_0c0388da;
case 0x0c0388dcu: goto P_0c0388dc;
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
case 0x0c038fe0u: goto P_0c038fe0;
case 0x0c038fe2u: goto P_0c038fe2;
case 0x0c038fe4u: goto P_0c038fe4;
case 0x0c038fe6u: goto P_0c038fe6;
case 0x0c038fe8u: goto P_0c038fe8;
case 0x0c038feau: goto P_0c038fea;
case 0x0c038fecu: goto P_0c038fec;
case 0x0c038feeu: goto P_0c038fee;
case 0x0c038ff0u: goto P_0c038ff0;
case 0x0c038ff2u: goto P_0c038ff2;
case 0x0c038ff4u: goto P_0c038ff4;
case 0x0c038ff6u: goto P_0c038ff6;
case 0x0c038ff8u: goto P_0c038ff8;
case 0x0c038ffau: goto P_0c038ffa;
case 0x0c038ffcu: goto P_0c038ffc;
case 0x0c038ffeu: goto P_0c038ffe;
case 0x0c039000u: goto P_0c039000;
case 0x0c039002u: goto P_0c039002;
case 0x0c039004u: goto P_0c039004;
case 0x0c039006u: goto P_0c039006;
case 0x0c039008u: goto P_0c039008;
case 0x0c03900au: goto P_0c03900a;
case 0x0c03900cu: goto P_0c03900c;
case 0x0c03900eu: goto P_0c03900e;
case 0x0c039010u: goto P_0c039010;
case 0x0c039012u: goto P_0c039012;
case 0x0c039014u: goto P_0c039014;
case 0x0c039016u: goto P_0c039016;
case 0x0c039018u: goto P_0c039018;
case 0x0c03901au: goto P_0c03901a;
case 0x0c03901cu: goto P_0c03901c;
case 0x0c03901eu: goto P_0c03901e;
case 0x0c039020u: goto P_0c039020;
case 0x0c039022u: goto P_0c039022;
case 0x0c039024u: goto P_0c039024;
case 0x0c039030u: goto P_0c039030;
case 0x0c039032u: goto P_0c039032;
case 0x0c039034u: goto P_0c039034;
case 0x0c039036u: goto P_0c039036;
case 0x0c039038u: goto P_0c039038;
case 0x0c03903au: goto P_0c03903a;
case 0x0c03903cu: goto P_0c03903c;
case 0x0c03903eu: goto P_0c03903e;
case 0x0c039040u: goto P_0c039040;
case 0x0c039042u: goto P_0c039042;
case 0x0c039044u: goto P_0c039044;
case 0x0c039046u: goto P_0c039046;
case 0x0c039048u: goto P_0c039048;
case 0x0c03904au: goto P_0c03904a;
case 0x0c03904cu: goto P_0c03904c;
case 0x0c03904eu: goto P_0c03904e;
case 0x0c039050u: goto P_0c039050;
case 0x0c039052u: goto P_0c039052;
case 0x0c039054u: goto P_0c039054;
case 0x0c039056u: goto P_0c039056;
case 0x0c039058u: goto P_0c039058;
case 0x0c03905au: goto P_0c03905a;
case 0x0c03905cu: goto P_0c03905c;
case 0x0c03905eu: goto P_0c03905e;
case 0x0c039060u: goto P_0c039060;
case 0x0c039062u: goto P_0c039062;
case 0x0c039064u: goto P_0c039064;
case 0x0c039066u: goto P_0c039066;
case 0x0c039068u: goto P_0c039068;
case 0x0c03906au: goto P_0c03906a;
case 0x0c03906cu: goto P_0c03906c;
case 0x0c03906eu: goto P_0c03906e;
case 0x0c039070u: goto P_0c039070;
case 0x0c039072u: goto P_0c039072;
case 0x0c039074u: goto P_0c039074;
case 0x0c039076u: goto P_0c039076;
case 0x0c039078u: goto P_0c039078;
case 0x0c03907au: goto P_0c03907a;
case 0x0c03907cu: goto P_0c03907c;
case 0x0c03907eu: goto P_0c03907e;
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
P_0c038600: /* original 2fe6, guest PC 0x0c038600 */
if(!s->budget--) { s->failed_pc=0x0c038600u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c038602;
P_0c038602: /* original 6e43, guest PC 0x0c038602 */
if(!s->budget--) { s->failed_pc=0x0c038602u; return 0; }
r[14]=r[4];
goto P_0c038604;
P_0c038604: /* original 2fd6, guest PC 0x0c038604 */
if(!s->budget--) { s->failed_pc=0x0c038604u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c038606;
P_0c038606: /* original ed3c, guest PC 0x0c038606 */
if(!s->budget--) { s->failed_pc=0x0c038606u; return 0; }
r[13]=0x0000003cu;
goto P_0c038608;
P_0c038608: /* original 4f22, guest PC 0x0c038608 */
if(!s->budget--) { s->failed_pc=0x0c038608u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c03860a;
P_0c03860a: /* original 4f12, guest PC 0x0c03860a */
if(!s->budget--) { s->failed_pc=0x0c03860au; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c03860c;
P_0c03860c: /* original 05d7, guest PC 0x0c03860c */
if(!s->budget--) { s->failed_pc=0x0c03860cu; return 0; }
r[19]=r[5]*r[13];
goto P_0c03860e;
P_0c03860e: /* original 7ff8, guest PC 0x0c03860e */
if(!s->budget--) { s->failed_pc=0x0c03860eu; return 0; }
r[15]+=0xfffffff8u;
goto P_0c038610;
P_0c038610: /* original 2f62, guest PC 0x0c038610 */
if(!s->budget--) { s->failed_pc=0x0c038610u; return 0; }
write(ram,r[15],r[6],4);
goto P_0c038612;
P_0c038612: /* original 0d1a, guest PC 0x0c038612 */
if(!s->budget--) { s->failed_pc=0x0c038612u; return 0; }
r[13]=r[19];
goto P_0c038614;
P_0c038614: /* original 1fd1, guest PC 0x0c038614 */
if(!s->budget--) { s->failed_pc=0x0c038614u; return 0; }
write(ram,r[15]+4,r[13],4);
goto P_0c038616;
P_0c038616: /* original d284, guest PC 0x0c038616 */
if(!s->budget--) { s->failed_pc=0x0c038616u; return 0; }
r[2]=read(ram,0x0c038828u,4);
goto P_0c038618;
P_0c038618: /* original d484, guest PC 0x0c038618 */
if(!s->budget--) { s->failed_pc=0x0c038618u; return 0; }
r[4]=read(ram,0x0c03882cu,4);
goto P_0c03861a;
P_0c03861a: /* original 6322, guest PC 0x0c03861a */
if(!s->budget--) { s->failed_pc=0x0c03861au; return 0; }
tmp=read(ram,r[2],4);
r[3]=tmp;
goto P_0c03861c;
P_0c03861c: /* original 6142, guest PC 0x0c03861c */
if(!s->budget--) { s->failed_pc=0x0c03861cu; return 0; }
tmp=read(ram,r[4],4);
r[1]=tmp;
goto P_0c03861e;
P_0c03861e: /* original 3d3c, guest PC 0x0c03861e */
if(!s->budget--) { s->failed_pc=0x0c03861eu; return 0; }
r[13]+=r[3];
goto P_0c038620;
P_0c038620: /* original 7101, guest PC 0x0c038620 */
if(!s->budget--) { s->failed_pc=0x0c038620u; return 0; }
r[1]+=0x00000001u;
goto P_0c038622;
P_0c038622: /* original 2412, guest PC 0x0c038622 */
if(!s->budget--) { s->failed_pc=0x0c038622u; return 0; }
write(ram,r[4],r[1],4);
goto P_0c038624;
P_0c038624: /* original 85e1, guest PC 0x0c038624 */
if(!s->budget--) { s->failed_pc=0x0c038624u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+2,2);
goto P_0c038626;
P_0c038626: /* original 57e1, guest PC 0x0c038626 */
if(!s->budget--) { s->failed_pc=0x0c038626u; return 0; }
r[7]=read(ram,r[14]+4,4);
goto P_0c038628;
P_0c038628: /* original 65e1, guest PC 0x0c038628 */
if(!s->budget--) { s->failed_pc=0x0c038628u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[14],2);
r[5]=tmp;
goto P_0c03862a;
P_0c03862a: /* original 6603, guest PC 0x0c03862a */
if(!s->budget--) { s->failed_pc=0x0c03862au; return 0; }
r[6]=r[0];
goto P_0c03862c;
P_0c03862c: /* original d380, guest PC 0x0c03862c */
if(!s->budget--) { s->failed_pc=0x0c03862cu; return 0; }
r[3]=read(ram,0x0c038830u,4);
goto P_0c03862e;
P_0c03862e: /* original 430b, guest PC 0x0c03862e */
if(!s->budget--) { s->failed_pc=0x0c03862eu; return 0; }
target=r[3];
r[16]=code_base|0x0c038632u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c038632u) { target=s->pc; goto dispatch; }
goto P_0c038632;
P_0c038630: /* original 64d3, guest PC 0x0c038630 */
if(!s->budget--) { s->failed_pc=0x0c038630u; return 0; }
r[4]=r[13];
goto P_0c038632;
P_0c038632: /* original 6403, guest PC 0x0c038632 */
if(!s->budget--) { s->failed_pc=0x0c038632u; return 0; }
r[4]=r[0];
goto P_0c038634;
P_0c038634: /* original 2448, guest PC 0x0c038634 */
if(!s->budget--) { s->failed_pc=0x0c038634u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c038636;
P_0c038636: /* original 8f0b, guest PC 0x0c038636 */
if(!s->budget--) { s->failed_pc=0x0c038636u; return 0; }
cond=r[17]&1u;
write(ram,r[13]+40,r[0],4);
if(!cond) { goto P_0c038650; }
goto P_0c03863a;
P_0c038638: /* original 1d0a, guest PC 0x0c038638 */
if(!s->budget--) { s->failed_pc=0x0c038638u; return 0; }
write(ram,r[13]+40,r[0],4);
goto P_0c03863a;
P_0c03863a: /* original d27b, guest PC 0x0c03863a */
if(!s->budget--) { s->failed_pc=0x0c03863au; return 0; }
r[2]=read(ram,0x0c038828u,4);
goto P_0c03863c;
P_0c03863c: /* original e700, guest PC 0x0c03863c */
if(!s->budget--) { s->failed_pc=0x0c03863cu; return 0; }
r[7]=0x00000000u;
goto P_0c03863e;
P_0c03863e: /* original 54f1, guest PC 0x0c03863e */
if(!s->budget--) { s->failed_pc=0x0c03863eu; return 0; }
r[4]=read(ram,r[15]+4,4);
goto P_0c038640;
P_0c038640: /* original 6322, guest PC 0x0c038640 */
if(!s->budget--) { s->failed_pc=0x0c038640u; return 0; }
tmp=read(ram,r[2],4);
r[3]=tmp;
goto P_0c038642;
P_0c038642: /* original 65f2, guest PC 0x0c038642 */
if(!s->budget--) { s->failed_pc=0x0c038642u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c038644;
P_0c038644: /* original 343c, guest PC 0x0c038644 */
if(!s->budget--) { s->failed_pc=0x0c038644u; return 0; }
r[4]+=r[3];
goto P_0c038646;
P_0c038646: /* original d37b, guest PC 0x0c038646 */
if(!s->budget--) { s->failed_pc=0x0c038646u; return 0; }
r[3]=read(ram,0x0c038834u,4);
goto P_0c038648;
P_0c038648: /* original 430b, guest PC 0x0c038648 */
if(!s->budget--) { s->failed_pc=0x0c038648u; return 0; }
target=r[3];
r[16]=code_base|0x0c03864cu;
r[6]=r[7];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c03864cu) { target=s->pc; goto dispatch; }
goto P_0c03864c;
P_0c03864a: /* original 6673, guest PC 0x0c03864a */
if(!s->budget--) { s->failed_pc=0x0c03864au; return 0; }
r[6]=r[7];
goto P_0c03864c;
P_0c03864c: /* original a001, guest PC 0x0c03864c */
if(!s->budget--) { s->failed_pc=0x0c03864cu; return 0; }
r[0]=0x00000000u;
goto P_0c038652;
P_0c03864e: /* original e000, guest PC 0x0c03864e */
if(!s->budget--) { s->failed_pc=0x0c03864eu; return 0; }
r[0]=0x00000000u;
goto P_0c038650;
P_0c038650: /* original e001, guest PC 0x0c038650 */
if(!s->budget--) { s->failed_pc=0x0c038650u; return 0; }
r[0]=0x00000001u;
goto P_0c038652;
P_0c038652: /* original 7f08, guest PC 0x0c038652 */
if(!s->budget--) { s->failed_pc=0x0c038652u; return 0; }
r[15]+=0x00000008u;
goto P_0c038654;
P_0c038654: /* original 4f16, guest PC 0x0c038654 */
if(!s->budget--) { s->failed_pc=0x0c038654u; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c038656;
P_0c038656: /* original 4f26, guest PC 0x0c038656 */
if(!s->budget--) { s->failed_pc=0x0c038656u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c038658;
P_0c038658: /* original 6df6, guest PC 0x0c038658 */
if(!s->budget--) { s->failed_pc=0x0c038658u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c03865a;
P_0c03865a: /* original 000b, guest PC 0x0c03865a */
if(!s->budget--) { s->failed_pc=0x0c03865au; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c03865c: /* original 6ef6, guest PC 0x0c03865c */
if(!s->budget--) { s->failed_pc=0x0c03865cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c03865eu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c03865eu; return 0; } return 1;
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
P_0c038860: /* original 2fe6, guest PC 0x0c038860 */
if(!s->budget--) { s->failed_pc=0x0c038860u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c038862;
P_0c038862: /* original e700, guest PC 0x0c038862 */
if(!s->budget--) { s->failed_pc=0x0c038862u; return 0; }
r[7]=0x00000000u;
goto P_0c038864;
P_0c038864: /* original 2fd6, guest PC 0x0c038864 */
if(!s->budget--) { s->failed_pc=0x0c038864u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c038866;
P_0c038866: /* original 6573, guest PC 0x0c038866 */
if(!s->budget--) { s->failed_pc=0x0c038866u; return 0; }
r[5]=r[7];
goto P_0c038868;
P_0c038868: /* original 2fb6, guest PC 0x0c038868 */
if(!s->budget--) { s->failed_pc=0x0c038868u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03886a;
P_0c03886a: /* original 6e73, guest PC 0x0c03886a */
if(!s->budget--) { s->failed_pc=0x0c03886au; return 0; }
r[14]=r[7];
goto P_0c03886c;
P_0c03886c: /* original 2fa6, guest PC 0x0c03886c */
if(!s->budget--) { s->failed_pc=0x0c03886cu; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03886e;
P_0c03886e: /* original 6a73, guest PC 0x0c03886e */
if(!s->budget--) { s->failed_pc=0x0c03886eu; return 0; }
r[10]=r[7];
goto P_0c038870;
P_0c038870: /* original 2f96, guest PC 0x0c038870 */
if(!s->budget--) { s->failed_pc=0x0c038870u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c038872;
P_0c038872: /* original e901, guest PC 0x0c038872 */
if(!s->budget--) { s->failed_pc=0x0c038872u; return 0; }
r[9]=0x00000001u;
goto P_0c038874;
P_0c038874: /* original 2f86, guest PC 0x0c038874 */
if(!s->budget--) { s->failed_pc=0x0c038874u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c038876;
P_0c038876: /* original d854, guest PC 0x0c038876 */
if(!s->budget--) { s->failed_pc=0x0c038876u; return 0; }
r[8]=read(ram,0x0c0389c8u,4);
goto P_0c038878;
P_0c038878: /* original dd54, guest PC 0x0c038878 */
if(!s->budget--) { s->failed_pc=0x0c038878u; return 0; }
r[13]=read(ram,0x0c0389ccu,4);
goto P_0c03887a;
P_0c03887a: /* original a025, guest PC 0x0c03887a */
if(!s->budget--) { s->failed_pc=0x0c03887au; return 0; }
r[11]=r[7];
goto P_0c0388c8;
P_0c03887c: /* original 6b73, guest PC 0x0c03887c */
if(!s->budget--) { s->failed_pc=0x0c03887cu; return 0; }
r[11]=r[7];
if(!vf3_matrix_family(0x0c03887eu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c03887eu; return 0; } return 1;
P_0c038880: /* original 60d2, guest PC 0x0c038880 */
if(!s->budget--) { s->failed_pc=0x0c038880u; return 0; }
tmp=read(ram,r[13],4);
r[0]=tmp;
goto P_0c038882;
P_0c038882: /* original 00be, guest PC 0x0c038882 */
if(!s->budget--) { s->failed_pc=0x0c038882u; return 0; }
r[0]=read(ram,r[11]+r[0],4);
goto P_0c038884;
P_0c038884: /* original 88ff, guest PC 0x0c038884 */
if(!s->budget--) { s->failed_pc=0x0c038884u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xffffffffu)!=0);
goto P_0c038886;
P_0c038886: /* original 8d1b, guest PC 0x0c038886 */
if(!s->budget--) { s->failed_pc=0x0c038886u; return 0; }
cond=r[17]&1u;
r[1]=r[0];
if(cond) { goto P_0c0388c0; }
goto P_0c03888a;
P_0c038888: /* original 6103, guest PC 0x0c038888 */
if(!s->budget--) { s->failed_pc=0x0c038888u; return 0; }
r[1]=r[0];
goto P_0c03888a;
P_0c03888a: /* original 6493, guest PC 0x0c03888a */
if(!s->budget--) { s->failed_pc=0x0c03888au; return 0; }
r[4]=r[9];
goto P_0c03888c;
P_0c03888c: /* original 6673, guest PC 0x0c03888c */
if(!s->budget--) { s->failed_pc=0x0c03888cu; return 0; }
r[6]=r[7];
goto P_0c03888e;
P_0c03888e: /* original 6213, guest PC 0x0c03888e */
if(!s->budget--) { s->failed_pc=0x0c03888eu; return 0; }
r[2]=r[1];
goto P_0c038890;
P_0c038890: /* original 2248, guest PC 0x0c038890 */
if(!s->budget--) { s->failed_pc=0x0c038890u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[4])==0)!=0);
goto P_0c038892;
P_0c038892: /* original 8b0d, guest PC 0x0c038892 */
if(!s->budget--) { s->failed_pc=0x0c038892u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0388b0; }
goto P_0c038894;
P_0c038894: /* original 60d2, guest PC 0x0c038894 */
if(!s->budget--) { s->failed_pc=0x0c038894u; return 0; }
tmp=read(ram,r[13],4);
r[0]=tmp;
goto P_0c038896;
P_0c038896: /* original 02ee, guest PC 0x0c038896 */
if(!s->budget--) { s->failed_pc=0x0c038896u; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c038898;
P_0c038898: /* original 224b, guest PC 0x0c038898 */
if(!s->budget--) { s->failed_pc=0x0c038898u; return 0; }
r[2]|=r[4];
goto P_0c03889a;
P_0c03889a: /* original 0e26, guest PC 0x0c03889a */
if(!s->budget--) { s->failed_pc=0x0c03889au; return 0; }
write(ram,r[14]+r[0],r[2],4);
goto P_0c03889c;
P_0c03889c: /* original 6053, guest PC 0x0c03889c */
if(!s->budget--) { s->failed_pc=0x0c03889cu; return 0; }
r[0]=r[5];
goto P_0c03889e;
P_0c03889e: /* original a017, guest PC 0x0c03889e */
if(!s->budget--) { s->failed_pc=0x0c03889eu; return 0; }
r[0]+=r[6];
goto P_0c0388d0;
P_0c0388a0: /* original 306c, guest PC 0x0c0388a0 */
if(!s->budget--) { s->failed_pc=0x0c0388a0u; return 0; }
r[0]+=r[6];
if(!vf3_matrix_family(0x0c0388a2u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0388a2u; return 0; } return 1;
P_0c0388b0: /* original 4400, guest PC 0x0c0388b0 */
if(!s->budget--) { s->failed_pc=0x0c0388b0u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c0388b2;
P_0c0388b2: /* original afec, guest PC 0x0c0388b2 */
if(!s->budget--) { s->failed_pc=0x0c0388b2u; return 0; }
r[6]+=0x00000001u;
goto P_0c03888e;
P_0c0388b4: /* original 7601, guest PC 0x0c0388b4 */
if(!s->budget--) { s->failed_pc=0x0c0388b4u; return 0; }
r[6]+=0x00000001u;
if(!vf3_matrix_family(0x0c0388b6u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0388b6u; return 0; } return 1;
P_0c0388c0: /* original 7e04, guest PC 0x0c0388c0 */
if(!s->budget--) { s->failed_pc=0x0c0388c0u; return 0; }
r[14]+=0x00000004u;
goto P_0c0388c2;
P_0c0388c2: /* original 7b04, guest PC 0x0c0388c2 */
if(!s->budget--) { s->failed_pc=0x0c0388c2u; return 0; }
r[11]+=0x00000004u;
goto P_0c0388c4;
P_0c0388c4: /* original 7a01, guest PC 0x0c0388c4 */
if(!s->budget--) { s->failed_pc=0x0c0388c4u; return 0; }
r[10]+=0x00000001u;
goto P_0c0388c6;
P_0c0388c6: /* original 7520, guest PC 0x0c0388c6 */
if(!s->budget--) { s->failed_pc=0x0c0388c6u; return 0; }
r[5]+=0x00000020u;
goto P_0c0388c8;
P_0c0388c8: /* original 6382, guest PC 0x0c0388c8 */
if(!s->budget--) { s->failed_pc=0x0c0388c8u; return 0; }
tmp=read(ram,r[8],4);
r[3]=tmp;
goto P_0c0388ca;
P_0c0388ca: /* original 3a33, guest PC 0x0c0388ca */
if(!s->budget--) { s->failed_pc=0x0c0388cau; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[10]>=(int32_t)r[3])!=0);
goto P_0c0388cc;
P_0c0388cc: /* original 8bd8, guest PC 0x0c0388cc */
if(!s->budget--) { s->failed_pc=0x0c0388ccu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c038880; }
goto P_0c0388ce;
P_0c0388ce: /* original e0ff, guest PC 0x0c0388ce */
if(!s->budget--) { s->failed_pc=0x0c0388ceu; return 0; }
r[0]=0xffffffffu;
goto P_0c0388d0;
P_0c0388d0: /* original 68f6, guest PC 0x0c0388d0 */
if(!s->budget--) { s->failed_pc=0x0c0388d0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c0388d2;
P_0c0388d2: /* original 69f6, guest PC 0x0c0388d2 */
if(!s->budget--) { s->failed_pc=0x0c0388d2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c0388d4;
P_0c0388d4: /* original 6af6, guest PC 0x0c0388d4 */
if(!s->budget--) { s->failed_pc=0x0c0388d4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0388d6;
P_0c0388d6: /* original 6bf6, guest PC 0x0c0388d6 */
if(!s->budget--) { s->failed_pc=0x0c0388d6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0388d8;
P_0c0388d8: /* original 6df6, guest PC 0x0c0388d8 */
if(!s->budget--) { s->failed_pc=0x0c0388d8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0388da;
P_0c0388da: /* original 000b, guest PC 0x0c0388da */
if(!s->budget--) { s->failed_pc=0x0c0388dau; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0388dc: /* original 6ef6, guest PC 0x0c0388dc */
if(!s->budget--) { s->failed_pc=0x0c0388dcu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0388deu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0388deu; return 0; } return 1;
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
P_0c038fe0: /* original 2fc6, guest PC 0x0c038fe0 */
if(!s->budget--) { s->failed_pc=0x0c038fe0u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c038fe2;
P_0c038fe2: /* original e004, guest PC 0x0c038fe2 */
if(!s->budget--) { s->failed_pc=0x0c038fe2u; return 0; }
r[0]=0x00000004u;
goto P_0c038fe4;
P_0c038fe4: /* original 4f22, guest PC 0x0c038fe4 */
if(!s->budget--) { s->failed_pc=0x0c038fe4u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c038fe6;
P_0c038fe6: /* original d74c, guest PC 0x0c038fe6 */
if(!s->budget--) { s->failed_pc=0x0c038fe6u; return 0; }
r[7]=read(ram,0x0c039118u,4);
goto P_0c038fe8;
P_0c038fe8: /* original 7f94, guest PC 0x0c038fe8 */
if(!s->budget--) { s->failed_pc=0x0c038fe8u; return 0; }
r[15]+=0xffffff94u;
goto P_0c038fea;
P_0c038fea: /* original 2742, guest PC 0x0c038fea */
if(!s->budget--) { s->failed_pc=0x0c038feau; return 0; }
write(ram,r[7],r[4],4);
goto P_0c038fec;
P_0c038fec: /* original 1751, guest PC 0x0c038fec */
if(!s->budget--) { s->failed_pc=0x0c038fecu; return 0; }
write(ram,r[7]+4,r[5],4);
goto P_0c038fee;
P_0c038fee: /* original 1762, guest PC 0x0c038fee */
if(!s->budget--) { s->failed_pc=0x0c038feeu; return 0; }
write(ram,r[7]+8,r[6],4);
goto P_0c038ff0;
P_0c038ff0: /* original 67f3, guest PC 0x0c038ff0 */
if(!s->budget--) { s->failed_pc=0x0c038ff0u; return 0; }
r[7]=r[15];
goto P_0c038ff2;
P_0c038ff2: /* original 770c, guest PC 0x0c038ff2 */
if(!s->budget--) { s->failed_pc=0x0c038ff2u; return 0; }
r[7]+=0x0000000cu;
goto P_0c038ff4;
P_0c038ff4: /* original d349, guest PC 0x0c038ff4 */
if(!s->budget--) { s->failed_pc=0x0c038ff4u; return 0; }
r[3]=read(ram,0x0c03911cu,4);
goto P_0c038ff6;
P_0c038ff6: /* original 6273, guest PC 0x0c038ff6 */
if(!s->budget--) { s->failed_pc=0x0c038ff6u; return 0; }
r[2]=r[7];
goto P_0c038ff8;
P_0c038ff8: /* original 6123, guest PC 0x0c038ff8 */
if(!s->budget--) { s->failed_pc=0x0c038ff8u; return 0; }
r[1]=r[2];
goto P_0c038ffa;
P_0c038ffa: /* original 7120, guest PC 0x0c038ffa */
if(!s->budget--) { s->failed_pc=0x0c038ffau; return 0; }
r[1]+=0x00000020u;
goto P_0c038ffc;
P_0c038ffc: /* original 2232, guest PC 0x0c038ffc */
if(!s->budget--) { s->failed_pc=0x0c038ffcu; return 0; }
write(ram,r[2],r[3],4);
goto P_0c038ffe;
P_0c038ffe: /* original f48d, guest PC 0x0c038ffe */
if(!s->budget--) { s->failed_pc=0x0c038ffeu; return 0; }
fr[4]=0;
goto P_0c039000;
P_0c039000: /* original f247, guest PC 0x0c039000 */
if(!s->budget--) { s->failed_pc=0x0c039000u; return 0; }
vf3_matrix_store(s,ram,4,r[2]+r[0]);
goto P_0c039002;
P_0c039002: /* original e008, guest PC 0x0c039002 */
if(!s->budget--) { s->failed_pc=0x0c039002u; return 0; }
r[0]=0x00000008u;
goto P_0c039004;
P_0c039004: /* original f247, guest PC 0x0c039004 */
if(!s->budget--) { s->failed_pc=0x0c039004u; return 0; }
vf3_matrix_store(s,ram,4,r[2]+r[0]);
goto P_0c039006;
P_0c039006: /* original c746, guest PC 0x0c039006 */
if(!s->budget--) { s->failed_pc=0x0c039006u; return 0; }
r[0]=code_base|0x00039120u;
goto P_0c039008;
P_0c039008: /* original f508, guest PC 0x0c039008 */
if(!s->budget--) { s->failed_pc=0x0c039008u; return 0; }
vf3_matrix_load(s,ram,5,r[0]);
goto P_0c03900a;
P_0c03900a: /* original e00c, guest PC 0x0c03900a */
if(!s->budget--) { s->failed_pc=0x0c03900au; return 0; }
r[0]=0x0000000cu;
goto P_0c03900c;
P_0c03900c: /* original f257, guest PC 0x0c03900c */
if(!s->budget--) { s->failed_pc=0x0c03900cu; return 0; }
vf3_matrix_store(s,ram,5,r[2]+r[0]);
goto P_0c03900e;
P_0c03900e: /* original 1244, guest PC 0x0c03900e */
if(!s->budget--) { s->failed_pc=0x0c03900eu; return 0; }
write(ram,r[2]+16,r[4],4);
goto P_0c039010;
P_0c039010: /* original 1246, guest PC 0x0c039010 */
if(!s->budget--) { s->failed_pc=0x0c039010u; return 0; }
write(ram,r[2]+24,r[4],4);
goto P_0c039012;
P_0c039012: /* original 2132, guest PC 0x0c039012 */
if(!s->budget--) { s->failed_pc=0x0c039012u; return 0; }
write(ram,r[1],r[3],4);
goto P_0c039014;
P_0c039014: /* original dc43, guest PC 0x0c039014 */
if(!s->budget--) { s->failed_pc=0x0c039014u; return 0; }
r[12]=read(ram,0x0c039124u,4);
goto P_0c039016;
P_0c039016: /* original 85c2, guest PC 0x0c039016 */
if(!s->budget--) { s->failed_pc=0x0c039016u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[12]+4,2);
goto P_0c039018;
P_0c039018: /* original 6403, guest PC 0x0c039018 */
if(!s->budget--) { s->failed_pc=0x0c039018u; return 0; }
r[4]=r[0];
goto P_0c03901a;
P_0c03901a: /* original 85c5, guest PC 0x0c03901a */
if(!s->budget--) { s->failed_pc=0x0c03901au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[12]+10,2);
goto P_0c03901c;
P_0c03901c: /* original 2008, guest PC 0x0c03901c */
if(!s->budget--) { s->failed_pc=0x0c03901cu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c03901e;
P_0c03901e: /* original 8907, guest PC 0x0c03901e */
if(!s->budget--) { s->failed_pc=0x0c03901eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c039030; }
goto P_0c039020;
P_0c039020: /* original 644f, guest PC 0x0c039020 */
if(!s->budget--) { s->failed_pc=0x0c039020u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)r[4];
goto P_0c039022;
P_0c039022: /* original a006, guest PC 0x0c039022 */
if(!s->budget--) { s->failed_pc=0x0c039022u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c039032;
P_0c039024: /* original 4400, guest PC 0x0c039024 */
if(!s->budget--) { s->failed_pc=0x0c039024u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
if(!vf3_matrix_family(0x0c039026u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c039026u; return 0; } return 1;
P_0c039030: /* original 644f, guest PC 0x0c039030 */
if(!s->budget--) { s->failed_pc=0x0c039030u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)r[4];
goto P_0c039032;
P_0c039032: /* original 445a, guest PC 0x0c039032 */
if(!s->budget--) { s->failed_pc=0x0c039032u; return 0; }
r[53]=r[4];
goto P_0c039034;
P_0c039034: /* original e004, guest PC 0x0c039034 */
if(!s->budget--) { s->failed_pc=0x0c039034u; return 0; }
r[0]=0x00000004u;
goto P_0c039036;
P_0c039036: /* original 6473, guest PC 0x0c039036 */
if(!s->budget--) { s->failed_pc=0x0c039036u; return 0; }
r[4]=r[7];
goto P_0c039038;
P_0c039038: /* original 7440, guest PC 0x0c039038 */
if(!s->budget--) { s->failed_pc=0x0c039038u; return 0; }
r[4]+=0x00000040u;
goto P_0c03903a;
P_0c03903a: /* original f32d, guest PC 0x0c03903a */
if(!s->budget--) { s->failed_pc=0x0c03903au; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c03903c;
P_0c03903c: /* original f137, guest PC 0x0c03903c */
if(!s->budget--) { s->failed_pc=0x0c03903cu; return 0; }
vf3_matrix_store(s,ram,3,r[1]+r[0]);
goto P_0c03903e;
P_0c03903e: /* original e008, guest PC 0x0c03903e */
if(!s->budget--) { s->failed_pc=0x0c03903eu; return 0; }
r[0]=0x00000008u;
goto P_0c039040;
P_0c039040: /* original f147, guest PC 0x0c039040 */
if(!s->budget--) { s->failed_pc=0x0c039040u; return 0; }
vf3_matrix_store(s,ram,4,r[1]+r[0]);
goto P_0c039042;
P_0c039042: /* original e00c, guest PC 0x0c039042 */
if(!s->budget--) { s->failed_pc=0x0c039042u; return 0; }
r[0]=0x0000000cu;
goto P_0c039044;
P_0c039044: /* original f157, guest PC 0x0c039044 */
if(!s->budget--) { s->failed_pc=0x0c039044u; return 0; }
vf3_matrix_store(s,ram,5,r[1]+r[0]);
goto P_0c039046;
P_0c039046: /* original e004, guest PC 0x0c039046 */
if(!s->budget--) { s->failed_pc=0x0c039046u; return 0; }
r[0]=0x00000004u;
goto P_0c039048;
P_0c039048: /* original 1154, guest PC 0x0c039048 */
if(!s->budget--) { s->failed_pc=0x0c039048u; return 0; }
write(ram,r[1]+16,r[5],4);
goto P_0c03904a;
P_0c03904a: /* original 1156, guest PC 0x0c03904a */
if(!s->budget--) { s->failed_pc=0x0c03904au; return 0; }
write(ram,r[1]+24,r[5],4);
goto P_0c03904c;
P_0c03904c: /* original e500, guest PC 0x0c03904c */
if(!s->budget--) { s->failed_pc=0x0c03904cu; return 0; }
r[5]=0x00000000u;
goto P_0c03904e;
P_0c03904e: /* original d336, guest PC 0x0c03904e */
if(!s->budget--) { s->failed_pc=0x0c03904eu; return 0; }
r[3]=read(ram,0x0c039128u,4);
goto P_0c039050;
P_0c039050: /* original 2432, guest PC 0x0c039050 */
if(!s->budget--) { s->failed_pc=0x0c039050u; return 0; }
write(ram,r[4],r[3],4);
goto P_0c039052;
P_0c039052: /* original f447, guest PC 0x0c039052 */
if(!s->budget--) { s->failed_pc=0x0c039052u; return 0; }
vf3_matrix_store(s,ram,4,r[4]+r[0]);
goto P_0c039054;
P_0c039054: /* original 85c3, guest PC 0x0c039054 */
if(!s->budget--) { s->failed_pc=0x0c039054u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[12]+6,2);
goto P_0c039056;
P_0c039056: /* original 6cf3, guest PC 0x0c039056 */
if(!s->budget--) { s->failed_pc=0x0c039056u; return 0; }
r[12]=r[15];
goto P_0c039058;
P_0c039058: /* original 6303, guest PC 0x0c039058 */
if(!s->budget--) { s->failed_pc=0x0c039058u; return 0; }
r[3]=r[0];
goto P_0c03905a;
P_0c03905a: /* original 435a, guest PC 0x0c03905a */
if(!s->budget--) { s->failed_pc=0x0c03905au; return 0; }
r[53]=r[3];
goto P_0c03905c;
P_0c03905c: /* original e008, guest PC 0x0c03905c */
if(!s->budget--) { s->failed_pc=0x0c03905cu; return 0; }
r[0]=0x00000008u;
goto P_0c03905e;
P_0c03905e: /* original f32d, guest PC 0x0c03905e */
if(!s->budget--) { s->failed_pc=0x0c03905eu; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c039060;
P_0c039060: /* original f437, guest PC 0x0c039060 */
if(!s->budget--) { s->failed_pc=0x0c039060u; return 0; }
vf3_matrix_store(s,ram,3,r[4]+r[0]);
goto P_0c039062;
P_0c039062: /* original e00c, guest PC 0x0c039062 */
if(!s->budget--) { s->failed_pc=0x0c039062u; return 0; }
r[0]=0x0000000cu;
goto P_0c039064;
P_0c039064: /* original f457, guest PC 0x0c039064 */
if(!s->budget--) { s->failed_pc=0x0c039064u; return 0; }
vf3_matrix_store(s,ram,5,r[4]+r[0]);
goto P_0c039066;
P_0c039066: /* original 1464, guest PC 0x0c039066 */
if(!s->budget--) { s->failed_pc=0x0c039066u; return 0; }
write(ram,r[4]+16,r[6],4);
goto P_0c039068;
P_0c039068: /* original 1466, guest PC 0x0c039068 */
if(!s->budget--) { s->failed_pc=0x0c039068u; return 0; }
write(ram,r[4]+24,r[6],4);
goto P_0c03906a;
P_0c03906a: /* original e620, guest PC 0x0c03906a */
if(!s->budget--) { s->failed_pc=0x0c03906au; return 0; }
r[6]=0x00000020u;
goto P_0c03906c;
P_0c03906c: /* original 2c22, guest PC 0x0c03906c */
if(!s->budget--) { s->failed_pc=0x0c03906cu; return 0; }
write(ram,r[12],r[2],4);
goto P_0c03906e;
P_0c03906e: /* original 1c11, guest PC 0x0c03906e */
if(!s->budget--) { s->failed_pc=0x0c03906eu; return 0; }
write(ram,r[12]+4,r[1],4);
goto P_0c039070;
P_0c039070: /* original 1c42, guest PC 0x0c039070 */
if(!s->budget--) { s->failed_pc=0x0c039070u; return 0; }
write(ram,r[12]+8,r[4],4);
goto P_0c039072;
P_0c039072: /* original d32e, guest PC 0x0c039072 */
if(!s->budget--) { s->failed_pc=0x0c039072u; return 0; }
r[3]=read(ram,0x0c03912cu,4);
goto P_0c039074;
P_0c039074: /* original 430b, guest PC 0x0c039074 */
if(!s->budget--) { s->failed_pc=0x0c039074u; return 0; }
target=r[3];
r[16]=code_base|0x0c039078u;
r[4]=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c039078u) { target=s->pc; goto dispatch; }
goto P_0c039078;
P_0c039076: /* original 64c3, guest PC 0x0c039076 */
if(!s->budget--) { s->failed_pc=0x0c039076u; return 0; }
r[4]=r[12];
goto P_0c039078;
P_0c039078: /* original 7f6c, guest PC 0x0c039078 */
if(!s->budget--) { s->failed_pc=0x0c039078u; return 0; }
r[15]+=0x0000006cu;
goto P_0c03907a;
P_0c03907a: /* original 4f26, guest PC 0x0c03907a */
if(!s->budget--) { s->failed_pc=0x0c03907au; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c03907c;
P_0c03907c: /* original 000b, guest PC 0x0c03907c */
if(!s->budget--) { s->failed_pc=0x0c03907cu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
s->pc=target; return ram->oob==0;
P_0c03907e: /* original 6cf6, guest PC 0x0c03907e */
if(!s->budget--) { s->failed_pc=0x0c03907eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
if(!vf3_matrix_family(0x0c039080u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c039080u; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
