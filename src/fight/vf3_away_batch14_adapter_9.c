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
int vf3_away_batch14_adapter_9(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c086f80u: goto P_0c086f80;
case 0x0c086f82u: goto P_0c086f82;
case 0x0c086f84u: goto P_0c086f84;
case 0x0c086f86u: goto P_0c086f86;
case 0x0c086f88u: goto P_0c086f88;
case 0x0c086f8au: goto P_0c086f8a;
case 0x0c086f8cu: goto P_0c086f8c;
case 0x0c086f8eu: goto P_0c086f8e;
case 0x0c086f90u: goto P_0c086f90;
case 0x0c086f92u: goto P_0c086f92;
case 0x0c086f94u: goto P_0c086f94;
case 0x0c086f96u: goto P_0c086f96;
case 0x0c086f98u: goto P_0c086f98;
case 0x0c086f9au: goto P_0c086f9a;
case 0x0c086f9cu: goto P_0c086f9c;
case 0x0c086f9eu: goto P_0c086f9e;
case 0x0c086fa0u: goto P_0c086fa0;
case 0x0c086fa2u: goto P_0c086fa2;
case 0x0c086fa4u: goto P_0c086fa4;
case 0x0c086fa6u: goto P_0c086fa6;
case 0x0c086fa8u: goto P_0c086fa8;
case 0x0c086faau: goto P_0c086faa;
case 0x0c086facu: goto P_0c086fac;
case 0x0c086faeu: goto P_0c086fae;
case 0x0c086fb0u: goto P_0c086fb0;
case 0x0c086fb2u: goto P_0c086fb2;
case 0x0c086fb4u: goto P_0c086fb4;
case 0x0c086fb6u: goto P_0c086fb6;
case 0x0c086fb8u: goto P_0c086fb8;
case 0x0c086fbau: goto P_0c086fba;
case 0x0c086fbcu: goto P_0c086fbc;
case 0x0c086fbeu: goto P_0c086fbe;
case 0x0c086fc0u: goto P_0c086fc0;
case 0x0c086fc2u: goto P_0c086fc2;
case 0x0c086fc4u: goto P_0c086fc4;
case 0x0c086fc6u: goto P_0c086fc6;
case 0x0c086fc8u: goto P_0c086fc8;
case 0x0c086fcau: goto P_0c086fca;
case 0x0c086fccu: goto P_0c086fcc;
case 0x0c086fceu: goto P_0c086fce;
case 0x0c086fd0u: goto P_0c086fd0;
case 0x0c086fd2u: goto P_0c086fd2;
case 0x0c086fd4u: goto P_0c086fd4;
case 0x0c086fd6u: goto P_0c086fd6;
case 0x0c086fd8u: goto P_0c086fd8;
case 0x0c086fdau: goto P_0c086fda;
case 0x0c086fdcu: goto P_0c086fdc;
case 0x0c086fdeu: goto P_0c086fde;
case 0x0c086fe0u: goto P_0c086fe0;
case 0x0c086fe2u: goto P_0c086fe2;
case 0x0c086fe4u: goto P_0c086fe4;
case 0x0c086fe6u: goto P_0c086fe6;
case 0x0c086fe8u: goto P_0c086fe8;
case 0x0c086feau: goto P_0c086fea;
case 0x0c086fecu: goto P_0c086fec;
case 0x0c086feeu: goto P_0c086fee;
case 0x0c086ff0u: goto P_0c086ff0;
case 0x0c086ff2u: goto P_0c086ff2;
case 0x0c086ff4u: goto P_0c086ff4;
case 0x0c086ff6u: goto P_0c086ff6;
case 0x0c086ff8u: goto P_0c086ff8;
case 0x0c086ffau: goto P_0c086ffa;
case 0x0c086ffcu: goto P_0c086ffc;
case 0x0c086ffeu: goto P_0c086ffe;
case 0x0c087000u: goto P_0c087000;
case 0x0c087002u: goto P_0c087002;
case 0x0c087004u: goto P_0c087004;
case 0x0c087006u: goto P_0c087006;
case 0x0c087008u: goto P_0c087008;
case 0x0c08700au: goto P_0c08700a;
case 0x0c08700cu: goto P_0c08700c;
case 0x0c08700eu: goto P_0c08700e;
case 0x0c087010u: goto P_0c087010;
case 0x0c087012u: goto P_0c087012;
case 0x0c087014u: goto P_0c087014;
case 0x0c087016u: goto P_0c087016;
case 0x0c087018u: goto P_0c087018;
case 0x0c08701au: goto P_0c08701a;
case 0x0c08701cu: goto P_0c08701c;
case 0x0c08701eu: goto P_0c08701e;
case 0x0c087020u: goto P_0c087020;
case 0x0c087022u: goto P_0c087022;
case 0x0c087024u: goto P_0c087024;
case 0x0c087026u: goto P_0c087026;
case 0x0c087028u: goto P_0c087028;
case 0x0c08702au: goto P_0c08702a;
case 0x0c08702cu: goto P_0c08702c;
case 0x0c08702eu: goto P_0c08702e;
case 0x0c087030u: goto P_0c087030;
case 0x0c087032u: goto P_0c087032;
case 0x0c087034u: goto P_0c087034;
case 0x0c087036u: goto P_0c087036;
case 0x0c087038u: goto P_0c087038;
case 0x0c08703au: goto P_0c08703a;
case 0x0c08703cu: goto P_0c08703c;
case 0x0c08703eu: goto P_0c08703e;
case 0x0c087040u: goto P_0c087040;
case 0x0c087042u: goto P_0c087042;
case 0x0c087044u: goto P_0c087044;
case 0x0c087046u: goto P_0c087046;
case 0x0c087048u: goto P_0c087048;
case 0x0c08704au: goto P_0c08704a;
case 0x0c08704cu: goto P_0c08704c;
case 0x0c08704eu: goto P_0c08704e;
case 0x0c087050u: goto P_0c087050;
case 0x0c087052u: goto P_0c087052;
case 0x0c087054u: goto P_0c087054;
case 0x0c087056u: goto P_0c087056;
case 0x0c087058u: goto P_0c087058;
case 0x0c08705au: goto P_0c08705a;
case 0x0c08705cu: goto P_0c08705c;
case 0x0c08705eu: goto P_0c08705e;
case 0x0c087060u: goto P_0c087060;
case 0x0c087062u: goto P_0c087062;
case 0x0c087064u: goto P_0c087064;
case 0x0c087066u: goto P_0c087066;
case 0x0c087068u: goto P_0c087068;
case 0x0c08706au: goto P_0c08706a;
case 0x0c08706cu: goto P_0c08706c;
case 0x0c08706eu: goto P_0c08706e;
case 0x0c087070u: goto P_0c087070;
case 0x0c087072u: goto P_0c087072;
case 0x0c087074u: goto P_0c087074;
case 0x0c087076u: goto P_0c087076;
case 0x0c087078u: goto P_0c087078;
case 0x0c08707au: goto P_0c08707a;
case 0x0c08708cu: goto P_0c08708c;
case 0x0c08708eu: goto P_0c08708e;
case 0x0c087090u: goto P_0c087090;
case 0x0c087092u: goto P_0c087092;
case 0x0c087094u: goto P_0c087094;
case 0x0c087096u: goto P_0c087096;
case 0x0c087098u: goto P_0c087098;
case 0x0c08709au: goto P_0c08709a;
case 0x0c08709cu: goto P_0c08709c;
case 0x0c08709eu: goto P_0c08709e;
case 0x0c0870a0u: goto P_0c0870a0;
case 0x0c0870a2u: goto P_0c0870a2;
case 0x0c0870a4u: goto P_0c0870a4;
case 0x0c0870a6u: goto P_0c0870a6;
case 0x0c0870a8u: goto P_0c0870a8;
case 0x0c0870aau: goto P_0c0870aa;
case 0x0c0870acu: goto P_0c0870ac;
case 0x0c0870aeu: goto P_0c0870ae;
case 0x0c0870b0u: goto P_0c0870b0;
case 0x0c0870b2u: goto P_0c0870b2;
case 0x0c0870b4u: goto P_0c0870b4;
case 0x0c0870b6u: goto P_0c0870b6;
case 0x0c0870b8u: goto P_0c0870b8;
case 0x0c0870bau: goto P_0c0870ba;
case 0x0c0870bcu: goto P_0c0870bc;
case 0x0c0870beu: goto P_0c0870be;
case 0x0c0870c0u: goto P_0c0870c0;
case 0x0c0870c2u: goto P_0c0870c2;
case 0x0c0870c4u: goto P_0c0870c4;
case 0x0c0870c6u: goto P_0c0870c6;
case 0x0c0870c8u: goto P_0c0870c8;
case 0x0c0870cau: goto P_0c0870ca;
case 0x0c0870ccu: goto P_0c0870cc;
case 0x0c0870ceu: goto P_0c0870ce;
case 0x0c0870d0u: goto P_0c0870d0;
case 0x0c0870d2u: goto P_0c0870d2;
case 0x0c0870d4u: goto P_0c0870d4;
case 0x0c0870d6u: goto P_0c0870d6;
case 0x0c0870d8u: goto P_0c0870d8;
case 0x0c0870dau: goto P_0c0870da;
case 0x0c0870dcu: goto P_0c0870dc;
case 0x0c0870deu: goto P_0c0870de;
case 0x0c0870e0u: goto P_0c0870e0;
case 0x0c0870e2u: goto P_0c0870e2;
case 0x0c0870e4u: goto P_0c0870e4;
case 0x0c0870e6u: goto P_0c0870e6;
case 0x0c0870e8u: goto P_0c0870e8;
case 0x0c0870eau: goto P_0c0870ea;
case 0x0c0870ecu: goto P_0c0870ec;
case 0x0c0870eeu: goto P_0c0870ee;
case 0x0c0870f0u: goto P_0c0870f0;
case 0x0c0870f2u: goto P_0c0870f2;
case 0x0c0870f4u: goto P_0c0870f4;
case 0x0c0870f6u: goto P_0c0870f6;
case 0x0c0870f8u: goto P_0c0870f8;
case 0x0c0870fau: goto P_0c0870fa;
case 0x0c0870fcu: goto P_0c0870fc;
case 0x0c0870feu: goto P_0c0870fe;
case 0x0c087100u: goto P_0c087100;
case 0x0c087102u: goto P_0c087102;
case 0x0c087104u: goto P_0c087104;
case 0x0c087106u: goto P_0c087106;
case 0x0c087108u: goto P_0c087108;
case 0x0c08710au: goto P_0c08710a;
case 0x0c08710cu: goto P_0c08710c;
case 0x0c08710eu: goto P_0c08710e;
case 0x0c087110u: goto P_0c087110;
case 0x0c087112u: goto P_0c087112;
case 0x0c087114u: goto P_0c087114;
case 0x0c087116u: goto P_0c087116;
case 0x0c087118u: goto P_0c087118;
case 0x0c08711au: goto P_0c08711a;
case 0x0c08711cu: goto P_0c08711c;
case 0x0c08711eu: goto P_0c08711e;
case 0x0c087120u: goto P_0c087120;
case 0x0c087122u: goto P_0c087122;
case 0x0c087124u: goto P_0c087124;
case 0x0c087126u: goto P_0c087126;
case 0x0c087128u: goto P_0c087128;
case 0x0c08712au: goto P_0c08712a;
case 0x0c08712cu: goto P_0c08712c;
case 0x0c08712eu: goto P_0c08712e;
case 0x0c087130u: goto P_0c087130;
case 0x0c087132u: goto P_0c087132;
case 0x0c087134u: goto P_0c087134;
case 0x0c087136u: goto P_0c087136;
case 0x0c087138u: goto P_0c087138;
case 0x0c08713au: goto P_0c08713a;
case 0x0c08713cu: goto P_0c08713c;
case 0x0c08713eu: goto P_0c08713e;
case 0x0c087140u: goto P_0c087140;
case 0x0c087142u: goto P_0c087142;
case 0x0c087144u: goto P_0c087144;
case 0x0c087146u: goto P_0c087146;
case 0x0c087148u: goto P_0c087148;
case 0x0c08714au: goto P_0c08714a;
case 0x0c08714cu: goto P_0c08714c;
case 0x0c08714eu: goto P_0c08714e;
case 0x0c087150u: goto P_0c087150;
case 0x0c087152u: goto P_0c087152;
case 0x0c087154u: goto P_0c087154;
case 0x0c087156u: goto P_0c087156;
case 0x0c087158u: goto P_0c087158;
case 0x0c08715au: goto P_0c08715a;
case 0x0c08715cu: goto P_0c08715c;
case 0x0c08715eu: goto P_0c08715e;
case 0x0c087160u: goto P_0c087160;
case 0x0c087162u: goto P_0c087162;
case 0x0c087164u: goto P_0c087164;
case 0x0c087166u: goto P_0c087166;
case 0x0c087168u: goto P_0c087168;
default: return vf3_matrix_family(target,s,ram);
}
P_0c086f80: /* original 2fe6, guest PC 0x0c086f80 */
if(!s->budget--) { s->failed_pc=0x0c086f80u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c086f82;
P_0c086f82: /* original 2fd6, guest PC 0x0c086f82 */
if(!s->budget--) { s->failed_pc=0x0c086f82u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c086f84;
P_0c086f84: /* original 6d53, guest PC 0x0c086f84 */
if(!s->budget--) { s->failed_pc=0x0c086f84u; return 0; }
r[13]=r[5];
goto P_0c086f86;
P_0c086f86: /* original 2fc6, guest PC 0x0c086f86 */
if(!s->budget--) { s->failed_pc=0x0c086f86u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c086f88;
P_0c086f88: /* original fffb, guest PC 0x0c086f88 */
if(!s->budget--) { s->failed_pc=0x0c086f88u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c086f8a;
P_0c086f8a: /* original ffeb, guest PC 0x0c086f8a */
if(!s->budget--) { s->failed_pc=0x0c086f8au; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,14,r[15]);
goto P_0c086f8c;
P_0c086f8c: /* original ffdb, guest PC 0x0c086f8c */
if(!s->budget--) { s->failed_pc=0x0c086f8cu; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,13,r[15]);
goto P_0c086f8e;
P_0c086f8e: /* original ffcb, guest PC 0x0c086f8e */
if(!s->budget--) { s->failed_pc=0x0c086f8eu; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,12,r[15]);
goto P_0c086f90;
P_0c086f90: /* original 4f22, guest PC 0x0c086f90 */
if(!s->budget--) { s->failed_pc=0x0c086f90u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c086f92;
P_0c086f92: /* original 7ff8, guest PC 0x0c086f92 */
if(!s->budget--) { s->failed_pc=0x0c086f92u; return 0; }
r[15]+=0xfffffff8u;
goto P_0c086f94;
P_0c086f94: /* original 2f42, guest PC 0x0c086f94 */
if(!s->budget--) { s->failed_pc=0x0c086f94u; return 0; }
write(ram,r[15],r[4],4);
goto P_0c086f96;
P_0c086f96: /* original 60d2, guest PC 0x0c086f96 */
if(!s->budget--) { s->failed_pc=0x0c086f96u; return 0; }
tmp=read(ram,r[13],4);
r[0]=tmp;
goto P_0c086f98;
P_0c086f98: /* original 88ff, guest PC 0x0c086f98 */
if(!s->budget--) { s->failed_pc=0x0c086f98u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xffffffffu)!=0);
goto P_0c086f9a;
P_0c086f9a: /* original 8d65, guest PC 0x0c086f9a */
if(!s->budget--) { s->failed_pc=0x0c086f9au; return 0; }
cond=r[17]&1u;
r[4]=r[0];
if(cond) { goto P_0c087068; }
goto P_0c086f9e;
P_0c086f9c: /* original 6403, guest PC 0x0c086f9c */
if(!s->budget--) { s->failed_pc=0x0c086f9cu; return 0; }
r[4]=r[0];
goto P_0c086f9e;
P_0c086f9e: /* original c738, guest PC 0x0c086f9e */
if(!s->budget--) { s->failed_pc=0x0c086f9eu; return 0; }
r[0]=code_base|0x00087080u;
goto P_0c086fa0;
P_0c086fa0: /* original fd08, guest PC 0x0c086fa0 */
if(!s->budget--) { s->failed_pc=0x0c086fa0u; return 0; }
vf3_matrix_load(s,ram,13,r[0]);
goto P_0c086fa2;
P_0c086fa2: /* original e018, guest PC 0x0c086fa2 */
if(!s->budget--) { s->failed_pc=0x0c086fa2u; return 0; }
r[0]=0x00000018u;
goto P_0c086fa4;
P_0c086fa4: /* original f3d6, guest PC 0x0c086fa4 */
if(!s->budget--) { s->failed_pc=0x0c086fa4u; return 0; }
vf3_matrix_load(s,ram,3,r[13]+r[0]);
goto P_0c086fa6;
P_0c086fa6: /* original e004, guest PC 0x0c086fa6 */
if(!s->budget--) { s->failed_pc=0x0c086fa6u; return 0; }
r[0]=0x00000004u;
goto P_0c086fa8;
P_0c086fa8: /* original ff37, guest PC 0x0c086fa8 */
if(!s->budget--) { s->failed_pc=0x0c086fa8u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c086faa;
P_0c086faa: /* original e01c, guest PC 0x0c086faa */
if(!s->budget--) { s->failed_pc=0x0c086faau; return 0; }
r[0]=0x0000001cu;
goto P_0c086fac;
P_0c086fac: /* original fcd6, guest PC 0x0c086fac */
if(!s->budget--) { s->failed_pc=0x0c086facu; return 0; }
vf3_matrix_load(s,ram,12,r[13]+r[0]);
goto P_0c086fae;
P_0c086fae: /* original 6e43, guest PC 0x0c086fae */
if(!s->budget--) { s->failed_pc=0x0c086faeu; return 0; }
r[14]=r[4];
goto P_0c086fb0;
P_0c086fb0: /* original 84e8, guest PC 0x0c086fb0 */
if(!s->budget--) { s->failed_pc=0x0c086fb0u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+8,1);
goto P_0c086fb2;
P_0c086fb2: /* original 88ff, guest PC 0x0c086fb2 */
if(!s->budget--) { s->failed_pc=0x0c086fb2u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xffffffffu)!=0);
goto P_0c086fb4;
P_0c086fb4: /* original 8b05, guest PC 0x0c086fb4 */
if(!s->budget--) { s->failed_pc=0x0c086fb4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c086fc2; }
goto P_0c086fb6;
P_0c086fb6: /* original dc33, guest PC 0x0c086fb6 */
if(!s->budget--) { s->failed_pc=0x0c086fb6u; return 0; }
r[12]=read(ram,0x0c087084u,4);
goto P_0c086fb8;
P_0c086fb8: /* original 65e3, guest PC 0x0c086fb8 */
if(!s->budget--) { s->failed_pc=0x0c086fb8u; return 0; }
r[5]=r[14];
goto P_0c086fba;
P_0c086fba: /* original 4c0b, guest PC 0x0c086fba */
if(!s->budget--) { s->failed_pc=0x0c086fbau; return 0; }
target=r[12];
r[16]=code_base|0x0c086fbeu;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c086fbeu) { target=s->pc; goto dispatch; }
goto P_0c086fbe;
P_0c086fbc: /* original 64d3, guest PC 0x0c086fbc */
if(!s->budget--) { s->failed_pc=0x0c086fbcu; return 0; }
r[4]=r[13];
goto P_0c086fbe;
P_0c086fbe: /* original a04f, guest PC 0x0c086fbe */
if(!s->budget--) { s->failed_pc=0x0c086fbeu; return 0; }
r[14]=r[0];
goto P_0c087060;
P_0c086fc0: /* original 6e03, guest PC 0x0c086fc0 */
if(!s->budget--) { s->failed_pc=0x0c086fc0u; return 0; }
r[14]=r[0];
goto P_0c086fc2;
P_0c086fc2: /* original e018, guest PC 0x0c086fc2 */
if(!s->budget--) { s->failed_pc=0x0c086fc2u; return 0; }
r[0]=0x00000018u;
goto P_0c086fc4;
P_0c086fc4: /* original f3e6, guest PC 0x0c086fc4 */
if(!s->budget--) { s->failed_pc=0x0c086fc4u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c086fc6;
P_0c086fc6: /* original e00c, guest PC 0x0c086fc6 */
if(!s->budget--) { s->failed_pc=0x0c086fc6u; return 0; }
r[0]=0x0000000cu;
goto P_0c086fc8;
P_0c086fc8: /* original f2e6, guest PC 0x0c086fc8 */
if(!s->budget--) { s->failed_pc=0x0c086fc8u; return 0; }
vf3_matrix_load(s,ram,2,r[14]+r[0]);
goto P_0c086fca;
P_0c086fca: /* original f230, guest PC 0x0c086fca */
if(!s->budget--) { s->failed_pc=0x0c086fcau; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'+');
goto P_0c086fcc;
P_0c086fcc: /* original fe27, guest PC 0x0c086fcc */
if(!s->budget--) { s->failed_pc=0x0c086fccu; return 0; }
vf3_matrix_store(s,ram,2,r[14]+r[0]);
goto P_0c086fce;
P_0c086fce: /* original e020, guest PC 0x0c086fce */
if(!s->budget--) { s->failed_pc=0x0c086fceu; return 0; }
r[0]=0x00000020u;
goto P_0c086fd0;
P_0c086fd0: /* original f3e6, guest PC 0x0c086fd0 */
if(!s->budget--) { s->failed_pc=0x0c086fd0u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c086fd2;
P_0c086fd2: /* original e014, guest PC 0x0c086fd2 */
if(!s->budget--) { s->failed_pc=0x0c086fd2u; return 0; }
r[0]=0x00000014u;
goto P_0c086fd4;
P_0c086fd4: /* original f2e6, guest PC 0x0c086fd4 */
if(!s->budget--) { s->failed_pc=0x0c086fd4u; return 0; }
vf3_matrix_load(s,ram,2,r[14]+r[0]);
goto P_0c086fd6;
P_0c086fd6: /* original f230, guest PC 0x0c086fd6 */
if(!s->budget--) { s->failed_pc=0x0c086fd6u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'+');
goto P_0c086fd8;
P_0c086fd8: /* original fe27, guest PC 0x0c086fd8 */
if(!s->budget--) { s->failed_pc=0x0c086fd8u; return 0; }
vf3_matrix_store(s,ram,2,r[14]+r[0]);
goto P_0c086fda;
P_0c086fda: /* original e01c, guest PC 0x0c086fda */
if(!s->budget--) { s->failed_pc=0x0c086fdau; return 0; }
r[0]=0x0000001cu;
goto P_0c086fdc;
P_0c086fdc: /* original ffe6, guest PC 0x0c086fdc */
if(!s->budget--) { s->failed_pc=0x0c086fdcu; return 0; }
vf3_matrix_load(s,ram,15,r[14]+r[0]);
goto P_0c086fde;
P_0c086fde: /* original e028, guest PC 0x0c086fde */
if(!s->budget--) { s->failed_pc=0x0c086fdeu; return 0; }
r[0]=0x00000028u;
goto P_0c086fe0;
P_0c086fe0: /* original fed6, guest PC 0x0c086fe0 */
if(!s->budget--) { s->failed_pc=0x0c086fe0u; return 0; }
vf3_matrix_load(s,ram,14,r[13]+r[0]);
goto P_0c086fe2;
P_0c086fe2: /* original e010, guest PC 0x0c086fe2 */
if(!s->budget--) { s->failed_pc=0x0c086fe2u; return 0; }
r[0]=0x00000010u;
goto P_0c086fe4;
P_0c086fe4: /* original f4e6, guest PC 0x0c086fe4 */
if(!s->budget--) { s->failed_pc=0x0c086fe4u; return 0; }
vf3_matrix_load(s,ram,4,r[14]+r[0]);
goto P_0c086fe6;
P_0c086fe6: /* original f4f0, guest PC 0x0c086fe6 */
if(!s->budget--) { s->failed_pc=0x0c086fe6u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[15],r[18],'+');
goto P_0c086fe8;
P_0c086fe8: /* original fe45, guest PC 0x0c086fe8 */
if(!s->budget--) { s->failed_pc=0x0c086fe8u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[14])>as_float(fr[4]))!=0);
goto P_0c086fea;
P_0c086fea: /* original 8b23, guest PC 0x0c086fea */
if(!s->budget--) { s->failed_pc=0x0c086feau; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c087034; }
goto P_0c086fec;
P_0c086fec: /* original dc26, guest PC 0x0c086fec */
if(!s->budget--) { s->failed_pc=0x0c086fecu; return 0; }
r[12]=read(ram,0x0c087088u,4);
goto P_0c086fee;
P_0c086fee: /* original 4c0b, guest PC 0x0c086fee */
if(!s->budget--) { s->failed_pc=0x0c086feeu; return 0; }
target=r[12];
r[16]=code_base|0x0c086ff2u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c086ff2u) { target=s->pc; goto dispatch; }
goto P_0c086ff2;
P_0c086ff0: /* original 0009, guest PC 0x0c086ff0 */
if(!s->budget--) { s->failed_pc=0x0c086ff0u; return 0; }
goto P_0c086ff2;
P_0c086ff2: /* original e407, guest PC 0x0c086ff2 */
if(!s->budget--) { s->failed_pc=0x0c086ff2u; return 0; }
r[4]=0x00000007u;
goto P_0c086ff4;
P_0c086ff4: /* original 6503, guest PC 0x0c086ff4 */
if(!s->budget--) { s->failed_pc=0x0c086ff4u; return 0; }
r[5]=r[0];
goto P_0c086ff6;
P_0c086ff6: /* original 2459, guest PC 0x0c086ff6 */
if(!s->budget--) { s->failed_pc=0x0c086ff6u; return 0; }
r[4]&=r[5];
goto P_0c086ff8;
P_0c086ff8: /* original 445a, guest PC 0x0c086ff8 */
if(!s->budget--) { s->failed_pc=0x0c086ff8u; return 0; }
r[53]=r[4];
goto P_0c086ffa;
P_0c086ffa: /* original e024, guest PC 0x0c086ffa */
if(!s->budget--) { s->failed_pc=0x0c086ffau; return 0; }
r[0]=0x00000024u;
goto P_0c086ffc;
P_0c086ffc: /* original f4d6, guest PC 0x0c086ffc */
if(!s->budget--) { s->failed_pc=0x0c086ffcu; return 0; }
vf3_matrix_load(s,ram,4,r[13]+r[0]);
goto P_0c086ffe;
P_0c086ffe: /* original e026, guest PC 0x0c086ffe */
if(!s->budget--) { s->failed_pc=0x0c086ffeu; return 0; }
r[0]=0x00000026u;
goto P_0c087000;
P_0c087000: /* original 943c, guest PC 0x0c087000 */
if(!s->budget--) { s->failed_pc=0x0c087000u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08707cu,2);
goto P_0c087002;
P_0c087002: /* original f32d, guest PC 0x0c087002 */
if(!s->budget--) { s->failed_pc=0x0c087002u; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c087004;
P_0c087004: /* original 05ec, guest PC 0x0c087004 */
if(!s->budget--) { s->failed_pc=0x0c087004u; return 0; }
r[5]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c087006;
P_0c087006: /* original 2459, guest PC 0x0c087006 */
if(!s->budget--) { s->failed_pc=0x0c087006u; return 0; }
r[4]&=r[5];
goto P_0c087008;
P_0c087008: /* original 2448, guest PC 0x0c087008 */
if(!s->budget--) { s->failed_pc=0x0c087008u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c08700a;
P_0c08700a: /* original f53c, guest PC 0x0c08700a */
if(!s->budget--) { s->failed_pc=0x0c08700au; return 0; }
vf3_matrix_move(s,5,3);
goto P_0c08700c;
P_0c08700c: /* original f452, guest PC 0x0c08700c */
if(!s->budget--) { s->failed_pc=0x0c08700cu; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[5],r[18],'*');
goto P_0c08700e;
P_0c08700e: /* original f3fc, guest PC 0x0c08700e */
if(!s->budget--) { s->failed_pc=0x0c08700eu; return 0; }
vf3_matrix_move(s,3,15);
goto P_0c087010;
P_0c087010: /* original ff4c, guest PC 0x0c087010 */
if(!s->budget--) { s->failed_pc=0x0c087010u; return 0; }
vf3_matrix_move(s,15,4);
goto P_0c087012;
P_0c087012: /* original ff32, guest PC 0x0c087012 */
if(!s->budget--) { s->failed_pc=0x0c087012u; return 0; }
fr[15]=vf3_fpu_binary(fr[15],fr[3],r[18],'*');
goto P_0c087014;
P_0c087014: /* original f5fc, guest PC 0x0c087014 */
if(!s->budget--) { s->failed_pc=0x0c087014u; return 0; }
vf3_matrix_move(s,5,15);
goto P_0c087016;
P_0c087016: /* original 8f08, guest PC 0x0c087016 */
if(!s->budget--) { s->failed_pc=0x0c087016u; return 0; }
cond=r[17]&1u;
fr[5]^=0x80000000u;
if(!cond) { goto P_0c08702a; }
goto P_0c08701a;
P_0c087018: /* original f54d, guest PC 0x0c087018 */
if(!s->budget--) { s->failed_pc=0x0c087018u; return 0; }
fr[5]^=0x80000000u;
goto P_0c08701a;
P_0c08701a: /* original e4c0, guest PC 0x0c08701a */
if(!s->budget--) { s->failed_pc=0x0c08701au; return 0; }
r[4]=0xffffffc0u;
goto P_0c08701c;
P_0c08701c: /* original 0e44, guest PC 0x0c08701c */
if(!s->budget--) { s->failed_pc=0x0c08701cu; return 0; }
write(ram,r[14]+r[0],r[4],1);
goto P_0c08701e;
P_0c08701e: /* original e018, guest PC 0x0c08701e */
if(!s->budget--) { s->failed_pc=0x0c08701eu; return 0; }
r[0]=0x00000018u;
goto P_0c087020;
P_0c087020: /* original f48d, guest PC 0x0c087020 */
if(!s->budget--) { s->failed_pc=0x0c087020u; return 0; }
fr[4]=0;
goto P_0c087022;
P_0c087022: /* original f54c, guest PC 0x0c087022 */
if(!s->budget--) { s->failed_pc=0x0c087022u; return 0; }
vf3_matrix_move(s,5,4);
goto P_0c087024;
P_0c087024: /* original fe57, guest PC 0x0c087024 */
if(!s->budget--) { s->failed_pc=0x0c087024u; return 0; }
vf3_matrix_store(s,ram,5,r[14]+r[0]);
goto P_0c087026;
P_0c087026: /* original e020, guest PC 0x0c087026 */
if(!s->budget--) { s->failed_pc=0x0c087026u; return 0; }
r[0]=0x00000020u;
goto P_0c087028;
P_0c087028: /* original fe57, guest PC 0x0c087028 */
if(!s->budget--) { s->failed_pc=0x0c087028u; return 0; }
vf3_matrix_store(s,ram,5,r[14]+r[0]);
goto P_0c08702a;
P_0c08702a: /* original e010, guest PC 0x0c08702a */
if(!s->budget--) { s->failed_pc=0x0c08702au; return 0; }
r[0]=0x00000010u;
goto P_0c08702c;
P_0c08702c: /* original fee7, guest PC 0x0c08702c */
if(!s->budget--) { s->failed_pc=0x0c08702cu; return 0; }
vf3_matrix_store(s,ram,14,r[14]+r[0]);
goto P_0c08702e;
P_0c08702e: /* original e01c, guest PC 0x0c08702e */
if(!s->budget--) { s->failed_pc=0x0c08702eu; return 0; }
r[0]=0x0000001cu;
goto P_0c087030;
P_0c087030: /* original a016, guest PC 0x0c087030 */
if(!s->budget--) { s->failed_pc=0x0c087030u; return 0; }
vf3_matrix_store(s,ram,5,r[14]+r[0]);
goto P_0c087060;
P_0c087032: /* original fe57, guest PC 0x0c087032 */
if(!s->budget--) { s->failed_pc=0x0c087032u; return 0; }
vf3_matrix_store(s,ram,5,r[14]+r[0]);
goto P_0c087034;
P_0c087034: /* original ffd0, guest PC 0x0c087034 */
if(!s->budget--) { s->failed_pc=0x0c087034u; return 0; }
fr[15]=vf3_fpu_binary(fr[15],fr[13],r[18],'+');
goto P_0c087036;
P_0c087036: /* original fe47, guest PC 0x0c087036 */
if(!s->budget--) { s->failed_pc=0x0c087036u; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c087038;
P_0c087038: /* original e02c, guest PC 0x0c087038 */
if(!s->budget--) { s->failed_pc=0x0c087038u; return 0; }
r[0]=0x0000002cu;
goto P_0c08703a;
P_0c08703a: /* original f4d6, guest PC 0x0c08703a */
if(!s->budget--) { s->failed_pc=0x0c08703au; return 0; }
vf3_matrix_load(s,ram,4,r[13]+r[0]);
goto P_0c08703c;
P_0c08703c: /* original ff45, guest PC 0x0c08703c */
if(!s->budget--) { s->failed_pc=0x0c08703cu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[15])>as_float(fr[4]))!=0);
goto P_0c08703e;
P_0c08703e: /* original 8d01, guest PC 0x0c08703e */
if(!s->budget--) { s->failed_pc=0x0c08703eu; return 0; }
cond=r[17]&1u;
r[0]=0x0000001cu;
if(cond) { goto P_0c087044; }
goto P_0c087042;
P_0c087040: /* original e01c, guest PC 0x0c087040 */
if(!s->budget--) { s->failed_pc=0x0c087040u; return 0; }
r[0]=0x0000001cu;
goto P_0c087042;
P_0c087042: /* original ffd1, guest PC 0x0c087042 */
if(!s->budget--) { s->failed_pc=0x0c087042u; return 0; }
fr[15]=vf3_fpu_binary(fr[15],fr[13],r[18],'-');
goto P_0c087044;
P_0c087044: /* original fef7, guest PC 0x0c087044 */
if(!s->budget--) { s->failed_pc=0x0c087044u; return 0; }
vf3_matrix_store(s,ram,15,r[14]+r[0]);
goto P_0c087046;
P_0c087046: /* original e026, guest PC 0x0c087046 */
if(!s->budget--) { s->failed_pc=0x0c087046u; return 0; }
r[0]=0x00000026u;
goto P_0c087048;
P_0c087048: /* original 9519, guest PC 0x0c087048 */
if(!s->budget--) { s->failed_pc=0x0c087048u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08707eu,2);
goto P_0c08704a;
P_0c08704a: /* original 04ec, guest PC 0x0c08704a */
if(!s->budget--) { s->failed_pc=0x0c08704au; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c08704c;
P_0c08704c: /* original 2459, guest PC 0x0c08704c */
if(!s->budget--) { s->failed_pc=0x0c08704cu; return 0; }
r[4]&=r[5];
goto P_0c08704e;
P_0c08704e: /* original 2448, guest PC 0x0c08704e */
if(!s->budget--) { s->failed_pc=0x0c08704eu; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c087050;
P_0c087050: /* original 8b06, guest PC 0x0c087050 */
if(!s->budget--) { s->failed_pc=0x0c087050u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c087060; }
goto P_0c087052;
P_0c087052: /* original e004, guest PC 0x0c087052 */
if(!s->budget--) { s->failed_pc=0x0c087052u; return 0; }
r[0]=0x00000004u;
goto P_0c087054;
P_0c087054: /* original 65d3, guest PC 0x0c087054 */
if(!s->budget--) { s->failed_pc=0x0c087054u; return 0; }
r[5]=r[13];
goto P_0c087056;
P_0c087056: /* original f4f6, guest PC 0x0c087056 */
if(!s->budget--) { s->failed_pc=0x0c087056u; return 0; }
vf3_matrix_load(s,ram,4,r[15]+r[0]);
goto P_0c087058;
P_0c087058: /* original 66e3, guest PC 0x0c087058 */
if(!s->budget--) { s->failed_pc=0x0c087058u; return 0; }
r[6]=r[14];
goto P_0c08705a;
P_0c08705a: /* original f5cc, guest PC 0x0c08705a */
if(!s->budget--) { s->failed_pc=0x0c08705au; return 0; }
vf3_matrix_move(s,5,12);
goto P_0c08705c;
P_0c08705c: /* original bf23, guest PC 0x0c08705c */
if(!s->budget--) { s->failed_pc=0x0c08705cu; return 0; }
target=code_base|0x0c086ea6u; r[16]=code_base|0x0c087060u;
tmp=read(ram,r[15],4);
r[4]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c087060u) { target=s->pc; goto dispatch; }
goto P_0c087060;
P_0c08705e: /* original 64f2, guest PC 0x0c08705e */
if(!s->budget--) { s->failed_pc=0x0c08705eu; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c087060;
P_0c087060: /* original 60e2, guest PC 0x0c087060 */
if(!s->budget--) { s->failed_pc=0x0c087060u; return 0; }
tmp=read(ram,r[14],4);
r[0]=tmp;
goto P_0c087062;
P_0c087062: /* original 88ff, guest PC 0x0c087062 */
if(!s->budget--) { s->failed_pc=0x0c087062u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xffffffffu)!=0);
goto P_0c087064;
P_0c087064: /* original 8fa3, guest PC 0x0c087064 */
if(!s->budget--) { s->failed_pc=0x0c087064u; return 0; }
cond=r[17]&1u;
r[4]=r[0];
if(!cond) { goto P_0c086fae; }
goto P_0c087068;
P_0c087066: /* original 6403, guest PC 0x0c087066 */
if(!s->budget--) { s->failed_pc=0x0c087066u; return 0; }
r[4]=r[0];
goto P_0c087068;
P_0c087068: /* original 7f08, guest PC 0x0c087068 */
if(!s->budget--) { s->failed_pc=0x0c087068u; return 0; }
r[15]+=0x00000008u;
goto P_0c08706a;
P_0c08706a: /* original 4f26, guest PC 0x0c08706a */
if(!s->budget--) { s->failed_pc=0x0c08706au; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c08706c;
P_0c08706c: /* original fcf9, guest PC 0x0c08706c */
if(!s->budget--) { s->failed_pc=0x0c08706cu; return 0; }
vf3_matrix_load(s,ram,12,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c08706e;
P_0c08706e: /* original fdf9, guest PC 0x0c08706e */
if(!s->budget--) { s->failed_pc=0x0c08706eu; return 0; }
vf3_matrix_load(s,ram,13,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c087070;
P_0c087070: /* original fef9, guest PC 0x0c087070 */
if(!s->budget--) { s->failed_pc=0x0c087070u; return 0; }
vf3_matrix_load(s,ram,14,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c087072;
P_0c087072: /* original fff9, guest PC 0x0c087072 */
if(!s->budget--) { s->failed_pc=0x0c087072u; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c087074;
P_0c087074: /* original 6cf6, guest PC 0x0c087074 */
if(!s->budget--) { s->failed_pc=0x0c087074u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c087076;
P_0c087076: /* original 6df6, guest PC 0x0c087076 */
if(!s->budget--) { s->failed_pc=0x0c087076u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c087078;
P_0c087078: /* original 000b, guest PC 0x0c087078 */
if(!s->budget--) { s->failed_pc=0x0c087078u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c08707a: /* original 6ef6, guest PC 0x0c08707a */
if(!s->budget--) { s->failed_pc=0x0c08707au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c08707cu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c08707cu; return 0; } return 1;
P_0c08708c: /* original 2fe6, guest PC 0x0c08708c */
if(!s->budget--) { s->failed_pc=0x0c08708cu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08708e;
P_0c08708e: /* original e004, guest PC 0x0c08708e */
if(!s->budget--) { s->failed_pc=0x0c08708eu; return 0; }
r[0]=0x00000004u;
goto P_0c087090;
P_0c087090: /* original 2fd6, guest PC 0x0c087090 */
if(!s->budget--) { s->failed_pc=0x0c087090u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c087092;
P_0c087092: /* original 2fc6, guest PC 0x0c087092 */
if(!s->budget--) { s->failed_pc=0x0c087092u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c087094;
P_0c087094: /* original 6c43, guest PC 0x0c087094 */
if(!s->budget--) { s->failed_pc=0x0c087094u; return 0; }
r[12]=r[4];
goto P_0c087096;
P_0c087096: /* original fffb, guest PC 0x0c087096 */
if(!s->budget--) { s->failed_pc=0x0c087096u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c087098;
P_0c087098: /* original ffeb, guest PC 0x0c087098 */
if(!s->budget--) { s->failed_pc=0x0c087098u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,14,r[15]);
goto P_0c08709a;
P_0c08709a: /* original ffdb, guest PC 0x0c08709a */
if(!s->budget--) { s->failed_pc=0x0c08709au; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,13,r[15]);
goto P_0c08709c;
P_0c08709c: /* original ffcb, guest PC 0x0c08709c */
if(!s->budget--) { s->failed_pc=0x0c08709cu; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,12,r[15]);
goto P_0c08709e;
P_0c08709e: /* original d435, guest PC 0x0c08709e */
if(!s->budget--) { s->failed_pc=0x0c08709eu; return 0; }
r[4]=read(ram,0x0c087174u,4);
goto P_0c0870a0;
P_0c0870a0: /* original 4f22, guest PC 0x0c0870a0 */
if(!s->budget--) { s->failed_pc=0x0c0870a0u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0870a2;
P_0c0870a2: /* original f346, guest PC 0x0c0870a2 */
if(!s->budget--) { s->failed_pc=0x0c0870a2u; return 0; }
vf3_matrix_load(s,ram,3,r[4]+r[0]);
goto P_0c0870a4;
P_0c0870a4: /* original e008, guest PC 0x0c0870a4 */
if(!s->budget--) { s->failed_pc=0x0c0870a4u; return 0; }
r[0]=0x00000008u;
goto P_0c0870a6;
P_0c0870a6: /* original 9e60, guest PC 0x0c0870a6 */
if(!s->budget--) { s->failed_pc=0x0c0870a6u; return 0; }
r[14]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08716au,2);
goto P_0c0870a8;
P_0c0870a8: /* original 7ffc, guest PC 0x0c0870a8 */
if(!s->budget--) { s->failed_pc=0x0c0870a8u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c0870aa;
P_0c0870aa: /* original ff48, guest PC 0x0c0870aa */
if(!s->budget--) { s->failed_pc=0x0c0870aau; return 0; }
vf3_matrix_load(s,ram,15,r[4]);
goto P_0c0870ac;
P_0c0870ac: /* original ff3a, guest PC 0x0c0870ac */
if(!s->budget--) { s->failed_pc=0x0c0870acu; return 0; }
vf3_matrix_store(s,ram,3,r[15]);
goto P_0c0870ae;
P_0c0870ae: /* original fc46, guest PC 0x0c0870ae */
if(!s->budget--) { s->failed_pc=0x0c0870aeu; return 0; }
vf3_matrix_load(s,ram,12,r[4]+r[0]);
goto P_0c0870b0;
P_0c0870b0: /* original e00c, guest PC 0x0c0870b0 */
if(!s->budget--) { s->failed_pc=0x0c0870b0u; return 0; }
r[0]=0x0000000cu;
goto P_0c0870b2;
P_0c0870b2: /* original fd46, guest PC 0x0c0870b2 */
if(!s->budget--) { s->failed_pc=0x0c0870b2u; return 0; }
vf3_matrix_load(s,ram,13,r[4]+r[0]);
goto P_0c0870b4;
P_0c0870b4: /* original e010, guest PC 0x0c0870b4 */
if(!s->budget--) { s->failed_pc=0x0c0870b4u; return 0; }
r[0]=0x00000010u;
goto P_0c0870b6;
P_0c0870b6: /* original d330, guest PC 0x0c0870b6 */
if(!s->budget--) { s->failed_pc=0x0c0870b6u; return 0; }
r[3]=read(ram,0x0c087178u,4);
goto P_0c0870b8;
P_0c0870b8: /* original fe46, guest PC 0x0c0870b8 */
if(!s->budget--) { s->failed_pc=0x0c0870b8u; return 0; }
vf3_matrix_load(s,ram,14,r[4]+r[0]);
goto P_0c0870ba;
P_0c0870ba: /* original 6030, guest PC 0x0c0870ba */
if(!s->budget--) { s->failed_pc=0x0c0870bau; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[3],1);
r[0]=tmp;
goto P_0c0870bc;
P_0c0870bc: /* original 600c, guest PC 0x0c0870bc */
if(!s->budget--) { s->failed_pc=0x0c0870bcu; return 0; }
r[0]=r[0]&255u;
goto P_0c0870be;
P_0c0870be: /* original 8803, guest PC 0x0c0870be */
if(!s->budget--) { s->failed_pc=0x0c0870beu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000003u)!=0);
goto P_0c0870c0;
P_0c0870c0: /* original 8f2c, guest PC 0x0c0870c0 */
if(!s->budget--) { s->failed_pc=0x0c0870c0u; return 0; }
cond=r[17]&1u;
r[14]+=r[12];
if(!cond) { goto P_0c08711c; }
goto P_0c0870c4;
P_0c0870c2: /* original 3ecc, guest PC 0x0c0870c2 */
if(!s->budget--) { s->failed_pc=0x0c0870c2u; return 0; }
r[14]+=r[12];
goto P_0c0870c4;
P_0c0870c4: /* original d32d, guest PC 0x0c0870c4 */
if(!s->budget--) { s->failed_pc=0x0c0870c4u; return 0; }
r[3]=read(ram,0x0c08717cu,4);
goto P_0c0870c6;
P_0c0870c6: /* original e700, guest PC 0x0c0870c6 */
if(!s->budget--) { s->failed_pc=0x0c0870c6u; return 0; }
r[7]=0x00000000u;
goto P_0c0870c8;
P_0c0870c8: /* original 9650, guest PC 0x0c0870c8 */
if(!s->budget--) { s->failed_pc=0x0c0870c8u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08716cu,2);
goto P_0c0870ca;
P_0c0870ca: /* original 6432, guest PC 0x0c0870ca */
if(!s->budget--) { s->failed_pc=0x0c0870cau; return 0; }
tmp=read(ram,r[3],4);
r[4]=tmp;
goto P_0c0870cc;
P_0c0870cc: /* original 924f, guest PC 0x0c0870cc */
if(!s->budget--) { s->failed_pc=0x0c0870ccu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08716eu,2);
goto P_0c0870ce;
P_0c0870ce: /* original 6543, guest PC 0x0c0870ce */
if(!s->budget--) { s->failed_pc=0x0c0870ceu; return 0; }
r[5]=r[4];
goto P_0c0870d0;
P_0c0870d0: /* original 2569, guest PC 0x0c0870d0 */
if(!s->budget--) { s->failed_pc=0x0c0870d0u; return 0; }
r[5]&=r[6];
goto P_0c0870d2;
P_0c0870d2: /* original 3520, guest PC 0x0c0870d2 */
if(!s->budget--) { s->failed_pc=0x0c0870d2u; return 0; }
r[17]=(r[17]&~1u)|((r[5]==r[2])!=0);
goto P_0c0870d4;
P_0c0870d4: /* original 8f02, guest PC 0x0c0870d4 */
if(!s->budget--) { s->failed_pc=0x0c0870d4u; return 0; }
cond=r[17]&1u;
r[13]=0x00000001u;
if(!cond) { goto P_0c0870dc; }
goto P_0c0870d8;
P_0c0870d6: /* original ed01, guest PC 0x0c0870d6 */
if(!s->budget--) { s->failed_pc=0x0c0870d6u; return 0; }
r[13]=0x00000001u;
goto P_0c0870d8;
P_0c0870d8: /* original a001, guest PC 0x0c0870d8 */
if(!s->budget--) { s->failed_pc=0x0c0870d8u; return 0; }
r[5]=r[7];
goto P_0c0870de;
P_0c0870da: /* original 6573, guest PC 0x0c0870da */
if(!s->budget--) { s->failed_pc=0x0c0870dau; return 0; }
r[5]=r[7];
goto P_0c0870dc;
P_0c0870dc: /* original 65d3, guest PC 0x0c0870dc */
if(!s->budget--) { s->failed_pc=0x0c0870dcu; return 0; }
r[5]=r[13];
goto P_0c0870de;
P_0c0870de: /* original 9346, guest PC 0x0c0870de */
if(!s->budget--) { s->failed_pc=0x0c0870deu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08716eu,2);
goto P_0c0870e0;
P_0c0870e0: /* original 4419, guest PC 0x0c0870e0 */
if(!s->budget--) { s->failed_pc=0x0c0870e0u; return 0; }
r[4]>>=8;
goto P_0c0870e2;
P_0c0870e2: /* original 2469, guest PC 0x0c0870e2 */
if(!s->budget--) { s->failed_pc=0x0c0870e2u; return 0; }
r[4]&=r[6];
goto P_0c0870e4;
P_0c0870e4: /* original 3430, guest PC 0x0c0870e4 */
if(!s->budget--) { s->failed_pc=0x0c0870e4u; return 0; }
r[17]=(r[17]&~1u)|((r[4]==r[3])!=0);
goto P_0c0870e6;
P_0c0870e6: /* original 8f02, guest PC 0x0c0870e6 */
if(!s->budget--) { s->failed_pc=0x0c0870e6u; return 0; }
cond=r[17]&1u;
r[3]=r[5];
if(!cond) { goto P_0c0870ee; }
goto P_0c0870ea;
P_0c0870e8: /* original 6353, guest PC 0x0c0870e8 */
if(!s->budget--) { s->failed_pc=0x0c0870e8u; return 0; }
r[3]=r[5];
goto P_0c0870ea;
P_0c0870ea: /* original a001, guest PC 0x0c0870ea */
if(!s->budget--) { s->failed_pc=0x0c0870eau; return 0; }
r[4]=r[7];
goto P_0c0870f0;
P_0c0870ec: /* original 6473, guest PC 0x0c0870ec */
if(!s->budget--) { s->failed_pc=0x0c0870ecu; return 0; }
r[4]=r[7];
goto P_0c0870ee;
P_0c0870ee: /* original 64d3, guest PC 0x0c0870ee */
if(!s->budget--) { s->failed_pc=0x0c0870eeu; return 0; }
r[4]=r[13];
goto P_0c0870f0;
P_0c0870f0: /* original 2348, guest PC 0x0c0870f0 */
if(!s->budget--) { s->failed_pc=0x0c0870f0u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[4])==0)!=0);
goto P_0c0870f2;
P_0c0870f2: /* original 8b13, guest PC 0x0c0870f2 */
if(!s->budget--) { s->failed_pc=0x0c0870f2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c08711c; }
goto P_0c0870f4;
P_0c0870f4: /* original c722, guest PC 0x0c0870f4 */
if(!s->budget--) { s->failed_pc=0x0c0870f4u; return 0; }
r[0]=code_base|0x00087180u;
goto P_0c0870f6;
P_0c0870f6: /* original 6673, guest PC 0x0c0870f6 */
if(!s->budget--) { s->failed_pc=0x0c0870f6u; return 0; }
r[6]=r[7];
goto P_0c0870f8;
P_0c0870f8: /* original ff08, guest PC 0x0c0870f8 */
if(!s->budget--) { s->failed_pc=0x0c0870f8u; return 0; }
vf3_matrix_load(s,ram,15,r[0]);
goto P_0c0870fa;
P_0c0870fa: /* original 2448, guest PC 0x0c0870fa */
if(!s->budget--) { s->failed_pc=0x0c0870fau; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c0870fc;
P_0c0870fc: /* original 8f01, guest PC 0x0c0870fc */
if(!s->budget--) { s->failed_pc=0x0c0870fcu; return 0; }
cond=r[17]&1u;
fr[12]=0;
if(!cond) { goto P_0c087102; }
goto P_0c087100;
P_0c0870fe: /* original fc8d, guest PC 0x0c0870fe */
if(!s->budget--) { s->failed_pc=0x0c0870feu; return 0; }
fr[12]=0;
goto P_0c087100;
P_0c087100: /* original 66d3, guest PC 0x0c087100 */
if(!s->budget--) { s->failed_pc=0x0c087100u; return 0; }
r[6]=r[13];
goto P_0c087102;
P_0c087102: /* original 254b, guest PC 0x0c087102 */
if(!s->budget--) { s->failed_pc=0x0c087102u; return 0; }
r[5]|=r[4];
goto P_0c087104;
P_0c087104: /* original 2558, guest PC 0x0c087104 */
if(!s->budget--) { s->failed_pc=0x0c087104u; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[5])==0)!=0);
goto P_0c087106;
P_0c087106: /* original 8b04, guest PC 0x0c087106 */
if(!s->budget--) { s->failed_pc=0x0c087106u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c087112; }
goto P_0c087108;
P_0c087108: /* original d31e, guest PC 0x0c087108 */
if(!s->budget--) { s->failed_pc=0x0c087108u; return 0; }
r[3]=read(ram,0x0c087184u,4);
goto P_0c08710a;
P_0c08710a: /* original 430b, guest PC 0x0c08710a */
if(!s->budget--) { s->failed_pc=0x0c08710au; return 0; }
target=r[3];
r[16]=code_base|0x0c08710eu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08710eu) { target=s->pc; goto dispatch; }
goto P_0c08710e;
P_0c08710c: /* original 0009, guest PC 0x0c08710c */
if(!s->budget--) { s->failed_pc=0x0c08710cu; return 0; }
goto P_0c08710e;
P_0c08710e: /* original 6603, guest PC 0x0c08710e */
if(!s->budget--) { s->failed_pc=0x0c08710eu; return 0; }
r[6]=r[0];
goto P_0c087110;
P_0c087110: /* original 26d9, guest PC 0x0c087110 */
if(!s->budget--) { s->failed_pc=0x0c087110u; return 0; }
r[6]&=r[13];
goto P_0c087112;
P_0c087112: /* original 6063, guest PC 0x0c087112 */
if(!s->budget--) { s->failed_pc=0x0c087112u; return 0; }
r[0]=r[6];
goto P_0c087114;
P_0c087114: /* original 8801, guest PC 0x0c087114 */
if(!s->budget--) { s->failed_pc=0x0c087114u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c087116;
P_0c087116: /* original 8b01, guest PC 0x0c087116 */
if(!s->budget--) { s->failed_pc=0x0c087116u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c08711c; }
goto P_0c087118;
P_0c087118: /* original c71b, guest PC 0x0c087118 */
if(!s->budget--) { s->failed_pc=0x0c087118u; return 0; }
r[0]=code_base|0x00087188u;
goto P_0c08711a;
P_0c08711a: /* original ff08, guest PC 0x0c08711a */
if(!s->budget--) { s->failed_pc=0x0c08711au; return 0; }
vf3_matrix_load(s,ram,15,r[0]);
goto P_0c08711c;
P_0c08711c: /* original f3dc, guest PC 0x0c08711c */
if(!s->budget--) { s->failed_pc=0x0c08711cu; return 0; }
vf3_matrix_move(s,3,13);
goto P_0c08711e;
P_0c08711e: /* original e00c, guest PC 0x0c08711e */
if(!s->budget--) { s->failed_pc=0x0c08711eu; return 0; }
r[0]=0x0000000cu;
goto P_0c087120;
P_0c087120: /* original fdfc, guest PC 0x0c087120 */
if(!s->budget--) { s->failed_pc=0x0c087120u; return 0; }
vf3_matrix_move(s,13,15);
goto P_0c087122;
P_0c087122: /* original fd30, guest PC 0x0c087122 */
if(!s->budget--) { s->failed_pc=0x0c087122u; return 0; }
fr[13]=vf3_fpu_binary(fr[13],fr[3],r[18],'+');
goto P_0c087124;
P_0c087124: /* original f3ec, guest PC 0x0c087124 */
if(!s->budget--) { s->failed_pc=0x0c087124u; return 0; }
vf3_matrix_move(s,3,14);
goto P_0c087126;
P_0c087126: /* original fecc, guest PC 0x0c087126 */
if(!s->budget--) { s->failed_pc=0x0c087126u; return 0; }
vf3_matrix_move(s,14,12);
goto P_0c087128;
P_0c087128: /* original fe30, guest PC 0x0c087128 */
if(!s->budget--) { s->failed_pc=0x0c087128u; return 0; }
fr[14]=vf3_fpu_binary(fr[14],fr[3],r[18],'+');
goto P_0c08712a;
P_0c08712a: /* original fef7, guest PC 0x0c08712a */
if(!s->budget--) { s->failed_pc=0x0c08712au; return 0; }
vf3_matrix_store(s,ram,15,r[14]+r[0]);
goto P_0c08712c;
P_0c08712c: /* original e010, guest PC 0x0c08712c */
if(!s->budget--) { s->failed_pc=0x0c08712cu; return 0; }
r[0]=0x00000010u;
goto P_0c08712e;
P_0c08712e: /* original f3f8, guest PC 0x0c08712e */
if(!s->budget--) { s->failed_pc=0x0c08712eu; return 0; }
vf3_matrix_load(s,ram,3,r[15]);
goto P_0c087130;
P_0c087130: /* original fe37, guest PC 0x0c087130 */
if(!s->budget--) { s->failed_pc=0x0c087130u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c087132;
P_0c087132: /* original e014, guest PC 0x0c087132 */
if(!s->budget--) { s->failed_pc=0x0c087132u; return 0; }
r[0]=0x00000014u;
goto P_0c087134;
P_0c087134: /* original fec7, guest PC 0x0c087134 */
if(!s->budget--) { s->failed_pc=0x0c087134u; return 0; }
vf3_matrix_store(s,ram,12,r[14]+r[0]);
goto P_0c087136;
P_0c087136: /* original e018, guest PC 0x0c087136 */
if(!s->budget--) { s->failed_pc=0x0c087136u; return 0; }
r[0]=0x00000018u;
goto P_0c087138;
P_0c087138: /* original fed7, guest PC 0x0c087138 */
if(!s->budget--) { s->failed_pc=0x0c087138u; return 0; }
vf3_matrix_store(s,ram,13,r[14]+r[0]);
goto P_0c08713a;
P_0c08713a: /* original e01c, guest PC 0x0c08713a */
if(!s->budget--) { s->failed_pc=0x0c08713au; return 0; }
r[0]=0x0000001cu;
goto P_0c08713c;
P_0c08713c: /* original fee7, guest PC 0x0c08713c */
if(!s->budget--) { s->failed_pc=0x0c08713cu; return 0; }
vf3_matrix_store(s,ram,14,r[14]+r[0]);
goto P_0c08713e;
P_0c08713e: /* original e048, guest PC 0x0c08713e */
if(!s->budget--) { s->failed_pc=0x0c08713eu; return 0; }
r[0]=0x00000048u;
goto P_0c087140;
P_0c087140: /* original 9316, guest PC 0x0c087140 */
if(!s->budget--) { s->failed_pc=0x0c087140u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c087170u,2);
goto P_0c087142;
P_0c087142: /* original 0e35, guest PC 0x0c087142 */
if(!s->budget--) { s->failed_pc=0x0c087142u; return 0; }
write(ram,r[14]+r[0],r[3],2);
goto P_0c087144;
P_0c087144: /* original be98, guest PC 0x0c087144 */
if(!s->budget--) { s->failed_pc=0x0c087144u; return 0; }
target=code_base|0x0c086e78u; r[16]=code_base|0x0c087148u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c087148u) { target=s->pc; goto dispatch; }
goto P_0c087148;
P_0c087146: /* original 64e3, guest PC 0x0c087146 */
if(!s->budget--) { s->failed_pc=0x0c087146u; return 0; }
r[4]=r[14];
goto P_0c087148;
P_0c087148: /* original a003, guest PC 0x0c087148 */
if(!s->budget--) { s->failed_pc=0x0c087148u; return 0; }
r[14]=0x00000078u;
goto P_0c087152;
P_0c08714a: /* original ee78, guest PC 0x0c08714a */
if(!s->budget--) { s->failed_pc=0x0c08714au; return 0; }
r[14]=0x00000078u;
goto P_0c08714c;
P_0c08714c: /* original b04b, guest PC 0x0c08714c */
if(!s->budget--) { s->failed_pc=0x0c08714cu; return 0; }
target=code_base|0x0c0871e6u; r[16]=code_base|0x0c087150u;
r[4]=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c087150u) { target=s->pc; goto dispatch; }
goto P_0c087150;
P_0c08714e: /* original 64c3, guest PC 0x0c08714e */
if(!s->budget--) { s->failed_pc=0x0c08714eu; return 0; }
r[4]=r[12];
goto P_0c087150;
P_0c087150: /* original 7eff, guest PC 0x0c087150 */
if(!s->budget--) { s->failed_pc=0x0c087150u; return 0; }
r[14]+=0xffffffffu;
goto P_0c087152;
P_0c087152: /* original 2ee8, guest PC 0x0c087152 */
if(!s->budget--) { s->failed_pc=0x0c087152u; return 0; }
r[17]=(r[17]&~1u)|(((r[14]&r[14])==0)!=0);
goto P_0c087154;
P_0c087154: /* original 8bfa, guest PC 0x0c087154 */
if(!s->budget--) { s->failed_pc=0x0c087154u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c08714c; }
goto P_0c087156;
P_0c087156: /* original 7f04, guest PC 0x0c087156 */
if(!s->budget--) { s->failed_pc=0x0c087156u; return 0; }
r[15]+=0x00000004u;
goto P_0c087158;
P_0c087158: /* original 4f26, guest PC 0x0c087158 */
if(!s->budget--) { s->failed_pc=0x0c087158u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c08715a;
P_0c08715a: /* original fcf9, guest PC 0x0c08715a */
if(!s->budget--) { s->failed_pc=0x0c08715au; return 0; }
vf3_matrix_load(s,ram,12,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c08715c;
P_0c08715c: /* original fdf9, guest PC 0x0c08715c */
if(!s->budget--) { s->failed_pc=0x0c08715cu; return 0; }
vf3_matrix_load(s,ram,13,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c08715e;
P_0c08715e: /* original fef9, guest PC 0x0c08715e */
if(!s->budget--) { s->failed_pc=0x0c08715eu; return 0; }
vf3_matrix_load(s,ram,14,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c087160;
P_0c087160: /* original fff9, guest PC 0x0c087160 */
if(!s->budget--) { s->failed_pc=0x0c087160u; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c087162;
P_0c087162: /* original 6cf6, guest PC 0x0c087162 */
if(!s->budget--) { s->failed_pc=0x0c087162u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c087164;
P_0c087164: /* original 6df6, guest PC 0x0c087164 */
if(!s->budget--) { s->failed_pc=0x0c087164u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c087166;
P_0c087166: /* original 000b, guest PC 0x0c087166 */
if(!s->budget--) { s->failed_pc=0x0c087166u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c087168: /* original 6ef6, guest PC 0x0c087168 */
if(!s->budget--) { s->failed_pc=0x0c087168u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c08716au,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c08716au; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
