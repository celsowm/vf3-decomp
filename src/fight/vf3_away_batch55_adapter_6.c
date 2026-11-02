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
int vf3_away_batch55_adapter_6(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c089270u: goto P_0c089270;
case 0x0c089272u: goto P_0c089272;
case 0x0c089274u: goto P_0c089274;
case 0x0c089276u: goto P_0c089276;
case 0x0c089278u: goto P_0c089278;
case 0x0c08927au: goto P_0c08927a;
case 0x0c08927cu: goto P_0c08927c;
case 0x0c08927eu: goto P_0c08927e;
case 0x0c089280u: goto P_0c089280;
case 0x0c089282u: goto P_0c089282;
case 0x0c089284u: goto P_0c089284;
case 0x0c089286u: goto P_0c089286;
case 0x0c089288u: goto P_0c089288;
case 0x0c08928au: goto P_0c08928a;
case 0x0c08928cu: goto P_0c08928c;
case 0x0c08928eu: goto P_0c08928e;
case 0x0c089290u: goto P_0c089290;
case 0x0c089292u: goto P_0c089292;
case 0x0c089294u: goto P_0c089294;
case 0x0c089296u: goto P_0c089296;
case 0x0c089298u: goto P_0c089298;
case 0x0c0892b8u: goto P_0c0892b8;
case 0x0c0892bau: goto P_0c0892ba;
case 0x0c0892bcu: goto P_0c0892bc;
case 0x0c0892beu: goto P_0c0892be;
case 0x0c0892c0u: goto P_0c0892c0;
case 0x0c0892c2u: goto P_0c0892c2;
case 0x0c0892c4u: goto P_0c0892c4;
case 0x0c0892c6u: goto P_0c0892c6;
case 0x0c0892c8u: goto P_0c0892c8;
case 0x0c0892cau: goto P_0c0892ca;
case 0x0c0892ccu: goto P_0c0892cc;
case 0x0c0892ceu: goto P_0c0892ce;
case 0x0c0892d0u: goto P_0c0892d0;
case 0x0c0892d2u: goto P_0c0892d2;
case 0x0c0892d4u: goto P_0c0892d4;
case 0x0c0892d6u: goto P_0c0892d6;
case 0x0c0892d8u: goto P_0c0892d8;
case 0x0c0892dau: goto P_0c0892da;
case 0x0c0892dcu: goto P_0c0892dc;
case 0x0c0892deu: goto P_0c0892de;
case 0x0c0892e0u: goto P_0c0892e0;
case 0x0c0892e2u: goto P_0c0892e2;
case 0x0c0892e4u: goto P_0c0892e4;
case 0x0c0892e6u: goto P_0c0892e6;
case 0x0c0892e8u: goto P_0c0892e8;
case 0x0c0892eau: goto P_0c0892ea;
case 0x0c0892ecu: goto P_0c0892ec;
case 0x0c0892eeu: goto P_0c0892ee;
case 0x0c0892f0u: goto P_0c0892f0;
case 0x0c0892f2u: goto P_0c0892f2;
case 0x0c0892f4u: goto P_0c0892f4;
case 0x0c0892f6u: goto P_0c0892f6;
case 0x0c0892f8u: goto P_0c0892f8;
case 0x0c0892fau: goto P_0c0892fa;
case 0x0c0892fcu: goto P_0c0892fc;
case 0x0c0892feu: goto P_0c0892fe;
case 0x0c089300u: goto P_0c089300;
case 0x0c089302u: goto P_0c089302;
case 0x0c089304u: goto P_0c089304;
case 0x0c089306u: goto P_0c089306;
case 0x0c089308u: goto P_0c089308;
case 0x0c08930au: goto P_0c08930a;
case 0x0c08930cu: goto P_0c08930c;
case 0x0c08930eu: goto P_0c08930e;
case 0x0c089310u: goto P_0c089310;
case 0x0c089312u: goto P_0c089312;
case 0x0c089314u: goto P_0c089314;
case 0x0c089316u: goto P_0c089316;
case 0x0c089318u: goto P_0c089318;
case 0x0c08931au: goto P_0c08931a;
case 0x0c08931cu: goto P_0c08931c;
case 0x0c08931eu: goto P_0c08931e;
case 0x0c089320u: goto P_0c089320;
case 0x0c089322u: goto P_0c089322;
case 0x0c089324u: goto P_0c089324;
case 0x0c089326u: goto P_0c089326;
case 0x0c089328u: goto P_0c089328;
case 0x0c08932au: goto P_0c08932a;
case 0x0c08932cu: goto P_0c08932c;
case 0x0c08932eu: goto P_0c08932e;
case 0x0c089330u: goto P_0c089330;
case 0x0c089332u: goto P_0c089332;
case 0x0c089334u: goto P_0c089334;
case 0x0c089336u: goto P_0c089336;
case 0x0c089338u: goto P_0c089338;
case 0x0c08933au: goto P_0c08933a;
case 0x0c08933cu: goto P_0c08933c;
case 0x0c08933eu: goto P_0c08933e;
case 0x0c089340u: goto P_0c089340;
case 0x0c089342u: goto P_0c089342;
case 0x0c089344u: goto P_0c089344;
case 0x0c089346u: goto P_0c089346;
case 0x0c0a7662u: goto P_0c0a7662;
case 0x0c0a7664u: goto P_0c0a7664;
case 0x0c0a7666u: goto P_0c0a7666;
case 0x0c0a7668u: goto P_0c0a7668;
case 0x0c0a766au: goto P_0c0a766a;
case 0x0c0a766cu: goto P_0c0a766c;
case 0x0c0a766eu: goto P_0c0a766e;
case 0x0c0a7670u: goto P_0c0a7670;
case 0x0c0a7672u: goto P_0c0a7672;
case 0x0c0a7674u: goto P_0c0a7674;
case 0x0c0a7676u: goto P_0c0a7676;
case 0x0c0a7678u: goto P_0c0a7678;
case 0x0c0a767au: goto P_0c0a767a;
case 0x0c0a767cu: goto P_0c0a767c;
case 0x0c0a767eu: goto P_0c0a767e;
case 0x0c0a7680u: goto P_0c0a7680;
case 0x0c0a7682u: goto P_0c0a7682;
case 0x0c0a7684u: goto P_0c0a7684;
case 0x0c0a7686u: goto P_0c0a7686;
case 0x0c0a7688u: goto P_0c0a7688;
case 0x0c0a768au: goto P_0c0a768a;
case 0x0c0a768cu: goto P_0c0a768c;
case 0x0c0a768eu: goto P_0c0a768e;
case 0x0c0a7690u: goto P_0c0a7690;
case 0x0c0a7692u: goto P_0c0a7692;
case 0x0c0a7694u: goto P_0c0a7694;
case 0x0c0a7696u: goto P_0c0a7696;
case 0x0c0a7698u: goto P_0c0a7698;
case 0x0c0a769au: goto P_0c0a769a;
case 0x0c0a769cu: goto P_0c0a769c;
case 0x0c0a769eu: goto P_0c0a769e;
case 0x0c0a76a0u: goto P_0c0a76a0;
case 0x0c0a76a2u: goto P_0c0a76a2;
case 0x0c0a76a4u: goto P_0c0a76a4;
case 0x0c0a76a6u: goto P_0c0a76a6;
case 0x0c0a76a8u: goto P_0c0a76a8;
case 0x0c0a76aau: goto P_0c0a76aa;
case 0x0c0a76acu: goto P_0c0a76ac;
case 0x0c0a76aeu: goto P_0c0a76ae;
case 0x0c0a76b0u: goto P_0c0a76b0;
case 0x0c0a76b2u: goto P_0c0a76b2;
case 0x0c0a76b4u: goto P_0c0a76b4;
case 0x0c0a76b6u: goto P_0c0a76b6;
case 0x0c0a76b8u: goto P_0c0a76b8;
case 0x0c0a76bau: goto P_0c0a76ba;
case 0x0c0a76bcu: goto P_0c0a76bc;
case 0x0c0a7750u: goto P_0c0a7750;
case 0x0c0a7752u: goto P_0c0a7752;
case 0x0c0a7754u: goto P_0c0a7754;
case 0x0c0a7756u: goto P_0c0a7756;
case 0x0c0a7758u: goto P_0c0a7758;
case 0x0c0a775au: goto P_0c0a775a;
case 0x0c0a775cu: goto P_0c0a775c;
case 0x0c0a775eu: goto P_0c0a775e;
case 0x0c0a7760u: goto P_0c0a7760;
case 0x0c0a7762u: goto P_0c0a7762;
case 0x0c0a7764u: goto P_0c0a7764;
case 0x0c0a7766u: goto P_0c0a7766;
case 0x0c0a7768u: goto P_0c0a7768;
case 0x0c0a776au: goto P_0c0a776a;
case 0x0c0a776cu: goto P_0c0a776c;
case 0x0c0a776eu: goto P_0c0a776e;
default: return vf3_matrix_family(target,s,ram);
}
P_0c089270: /* original 2fe6, guest PC 0x0c089270 */
if(!s->budget--) { s->failed_pc=0x0c089270u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c089272;
P_0c089272: /* original 2fd6, guest PC 0x0c089272 */
if(!s->budget--) { s->failed_pc=0x0c089272u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c089274;
P_0c089274: /* original 2fc6, guest PC 0x0c089274 */
if(!s->budget--) { s->failed_pc=0x0c089274u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c089276;
P_0c089276: /* original 2fb6, guest PC 0x0c089276 */
if(!s->budget--) { s->failed_pc=0x0c089276u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c089278;
P_0c089278: /* original 2fa6, guest PC 0x0c089278 */
if(!s->budget--) { s->failed_pc=0x0c089278u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08927a;
P_0c08927a: /* original 2f96, guest PC 0x0c08927a */
if(!s->budget--) { s->failed_pc=0x0c08927au; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08927c;
P_0c08927c: /* original 2f86, guest PC 0x0c08927c */
if(!s->budget--) { s->failed_pc=0x0c08927cu; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08927e;
P_0c08927e: /* original 4f22, guest PC 0x0c08927e */
if(!s->budget--) { s->failed_pc=0x0c08927eu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c089280;
P_0c089280: /* original 7ffc, guest PC 0x0c089280 */
if(!s->budget--) { s->failed_pc=0x0c089280u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c089282;
P_0c089282: /* original 2f42, guest PC 0x0c089282 */
if(!s->budget--) { s->failed_pc=0x0c089282u; return 0; }
write(ram,r[15],r[4],4);
goto P_0c089284;
P_0c089284: /* original d106, guest PC 0x0c089284 */
if(!s->budget--) { s->failed_pc=0x0c089284u; return 0; }
r[1]=read(ram,0x0c0892a0u,4);
goto P_0c089286;
P_0c089286: /* original d305, guest PC 0x0c089286 */
if(!s->budget--) { s->failed_pc=0x0c089286u; return 0; }
r[3]=read(ram,0x0c08929cu,4);
goto P_0c089288;
P_0c089288: /* original 6212, guest PC 0x0c089288 */
if(!s->budget--) { s->failed_pc=0x0c089288u; return 0; }
tmp=read(ram,r[1],4);
r[2]=tmp;
goto P_0c08928a;
P_0c08928a: /* original 2238, guest PC 0x0c08928a */
if(!s->budget--) { s->failed_pc=0x0c08928au; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c08928c;
P_0c08928c: /* original 8b52, guest PC 0x0c08928c */
if(!s->budget--) { s->failed_pc=0x0c08928cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c089334; }
goto P_0c08928e;
P_0c08928e: /* original 9904, guest PC 0x0c08928e */
if(!s->budget--) { s->failed_pc=0x0c08928eu; return 0; }
r[9]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08929au,2);
goto P_0c089290;
P_0c089290: /* original eb00, guest PC 0x0c089290 */
if(!s->budget--) { s->failed_pc=0x0c089290u; return 0; }
r[11]=0x00000000u;
goto P_0c089292;
P_0c089292: /* original ea1a, guest PC 0x0c089292 */
if(!s->budget--) { s->failed_pc=0x0c089292u; return 0; }
r[10]=0x0000001au;
goto P_0c089294;
P_0c089294: /* original e802, guest PC 0x0c089294 */
if(!s->budget--) { s->failed_pc=0x0c089294u; return 0; }
r[8]=0x00000002u;
goto P_0c089296;
P_0c089296: /* original a04b, guest PC 0x0c089296 */
if(!s->budget--) { s->failed_pc=0x0c089296u; return 0; }
r[12]=0x00000005u;
goto P_0c089330;
P_0c089298: /* original ec05, guest PC 0x0c089298 */
if(!s->budget--) { s->failed_pc=0x0c089298u; return 0; }
r[12]=0x00000005u;
if(!vf3_matrix_family(0x0c08929au,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c08929au; return 0; } return 1;
P_0c0892b8: /* original 64c3, guest PC 0x0c0892b8 */
if(!s->budget--) { s->failed_pc=0x0c0892b8u; return 0; }
r[4]=r[12];
goto P_0c0892ba;
P_0c0892ba: /* original 74ff, guest PC 0x0c0892ba */
if(!s->budget--) { s->failed_pc=0x0c0892bau; return 0; }
r[4]+=0xffffffffu;
goto P_0c0892bc;
P_0c0892bc: /* original 6e43, guest PC 0x0c0892bc */
if(!s->budget--) { s->failed_pc=0x0c0892bcu; return 0; }
r[14]=r[4];
goto P_0c0892be;
P_0c0892be: /* original 60f2, guest PC 0x0c0892be */
if(!s->budget--) { s->failed_pc=0x0c0892beu; return 0; }
tmp=read(ram,r[15],4);
r[0]=tmp;
goto P_0c0892c0;
P_0c0892c0: /* original 4e08, guest PC 0x0c0892c0 */
if(!s->budget--) { s->failed_pc=0x0c0892c0u; return 0; }
r[14]<<=2;
goto P_0c0892c2;
P_0c0892c2: /* original 0eee, guest PC 0x0c0892c2 */
if(!s->budget--) { s->failed_pc=0x0c0892c2u; return 0; }
r[14]=read(ram,r[14]+r[0],4);
goto P_0c0892c4;
P_0c0892c4: /* original e032, guest PC 0x0c0892c4 */
if(!s->budget--) { s->failed_pc=0x0c0892c4u; return 0; }
r[0]=0x00000032u;
goto P_0c0892c6;
P_0c0892c6: /* original 04ec, guest PC 0x0c0892c6 */
if(!s->budget--) { s->failed_pc=0x0c0892c6u; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0892c8;
P_0c0892c8: /* original 2448, guest PC 0x0c0892c8 */
if(!s->budget--) { s->failed_pc=0x0c0892c8u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c0892ca;
P_0c0892ca: /* original 6d43, guest PC 0x0c0892ca */
if(!s->budget--) { s->failed_pc=0x0c0892cau; return 0; }
r[13]=r[4];
goto P_0c0892cc;
P_0c0892cc: /* original 8f09, guest PC 0x0c0892cc */
if(!s->budget--) { s->failed_pc=0x0c0892ccu; return 0; }
cond=r[17]&1u;
r[13]+=0xffffffffu;
if(!cond) { goto P_0c0892e2; }
goto P_0c0892d0;
P_0c0892ce: /* original 7dff, guest PC 0x0c0892ce */
if(!s->budget--) { s->failed_pc=0x0c0892ceu; return 0; }
r[13]+=0xffffffffu;
goto P_0c0892d0;
P_0c0892d0: /* original d23e, guest PC 0x0c0892d0 */
if(!s->budget--) { s->failed_pc=0x0c0892d0u; return 0; }
r[2]=read(ram,0x0c0893ccu,4);
goto P_0c0892d2;
P_0c0892d2: /* original 420b, guest PC 0x0c0892d2 */
if(!s->budget--) { s->failed_pc=0x0c0892d2u; return 0; }
target=r[2];
r[16]=code_base|0x0c0892d6u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0892d6u) { target=s->pc; goto dispatch; }
goto P_0c0892d6;
P_0c0892d4: /* original 0009, guest PC 0x0c0892d4 */
if(!s->budget--) { s->failed_pc=0x0c0892d4u; return 0; }
goto P_0c0892d6;
P_0c0892d6: /* original ed7f, guest PC 0x0c0892d6 */
if(!s->budget--) { s->failed_pc=0x0c0892d6u; return 0; }
r[13]=0x0000007fu;
goto P_0c0892d8;
P_0c0892d8: /* original 6403, guest PC 0x0c0892d8 */
if(!s->budget--) { s->failed_pc=0x0c0892d8u; return 0; }
r[4]=r[0];
goto P_0c0892da;
P_0c0892da: /* original 2d49, guest PC 0x0c0892da */
if(!s->budget--) { s->failed_pc=0x0c0892dau; return 0; }
r[13]&=r[4];
goto P_0c0892dc;
P_0c0892dc: /* original e030, guest PC 0x0c0892dc */
if(!s->budget--) { s->failed_pc=0x0c0892dcu; return 0; }
r[0]=0x00000030u;
goto P_0c0892de;
P_0c0892de: /* original 2499, guest PC 0x0c0892de */
if(!s->budget--) { s->failed_pc=0x0c0892deu; return 0; }
r[4]&=r[9];
goto P_0c0892e0;
P_0c0892e0: /* original 0e45, guest PC 0x0c0892e0 */
if(!s->budget--) { s->failed_pc=0x0c0892e0u; return 0; }
write(ram,r[14]+r[0],r[4],2);
goto P_0c0892e2;
P_0c0892e2: /* original e032, guest PC 0x0c0892e2 */
if(!s->budget--) { s->failed_pc=0x0c0892e2u; return 0; }
r[0]=0x00000032u;
goto P_0c0892e4;
P_0c0892e4: /* original e330, guest PC 0x0c0892e4 */
if(!s->budget--) { s->failed_pc=0x0c0892e4u; return 0; }
r[3]=0x00000030u;
goto P_0c0892e6;
P_0c0892e6: /* original 0ed4, guest PC 0x0c0892e6 */
if(!s->budget--) { s->failed_pc=0x0c0892e6u; return 0; }
write(ram,r[14]+r[0],r[13],1);
goto P_0c0892e8;
P_0c0892e8: /* original 33ec, guest PC 0x0c0892e8 */
if(!s->budget--) { s->failed_pc=0x0c0892e8u; return 0; }
r[3]+=r[14];
goto P_0c0892ea;
P_0c0892ea: /* original e02e, guest PC 0x0c0892ea */
if(!s->budget--) { s->failed_pc=0x0c0892eau; return 0; }
r[0]=0x0000002eu;
goto P_0c0892ec;
P_0c0892ec: /* original 6331, guest PC 0x0c0892ec */
if(!s->budget--) { s->failed_pc=0x0c0892ecu; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[3],2);
r[3]=tmp;
goto P_0c0892ee;
P_0c0892ee: /* original 02ed, guest PC 0x0c0892ee */
if(!s->budget--) { s->failed_pc=0x0c0892eeu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0892f0;
P_0c0892f0: /* original 323c, guest PC 0x0c0892f0 */
if(!s->budget--) { s->failed_pc=0x0c0892f0u; return 0; }
r[2]+=r[3];
goto P_0c0892f2;
P_0c0892f2: /* original 0e25, guest PC 0x0c0892f2 */
if(!s->budget--) { s->failed_pc=0x0c0892f2u; return 0; }
write(ram,r[14]+r[0],r[2],2);
goto P_0c0892f4;
P_0c0892f4: /* original bdfc, guest PC 0x0c0892f4 */
if(!s->budget--) { s->failed_pc=0x0c0892f4u; return 0; }
target=code_base|0x0c088ef0u; r[16]=code_base|0x0c0892f8u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0892f8u) { target=s->pc; goto dispatch; }
goto P_0c0892f8;
P_0c0892f6: /* original 64e3, guest PC 0x0c0892f6 */
if(!s->budget--) { s->failed_pc=0x0c0892f6u; return 0; }
r[4]=r[14];
goto P_0c0892f8;
P_0c0892f8: /* original 3c87, guest PC 0x0c0892f8 */
if(!s->budget--) { s->failed_pc=0x0c0892f8u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[12]>(int32_t)r[8])!=0);
goto P_0c0892fa;
P_0c0892fa: /* original 8b08, guest PC 0x0c0892fa */
if(!s->budget--) { s->failed_pc=0x0c0892fau; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c08930e; }
goto P_0c0892fc;
P_0c0892fc: /* original 85e5, guest PC 0x0c0892fc */
if(!s->budget--) { s->failed_pc=0x0c0892fcu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+10,2);
goto P_0c0892fe;
P_0c0892fe: /* original 6d03, guest PC 0x0c0892fe */
if(!s->budget--) { s->failed_pc=0x0c0892feu; return 0; }
r[13]=r[0];
goto P_0c089300;
P_0c089300: /* original 7d01, guest PC 0x0c089300 */
if(!s->budget--) { s->failed_pc=0x0c089300u; return 0; }
r[13]+=0x00000001u;
goto P_0c089302;
P_0c089302: /* original 3da3, guest PC 0x0c089302 */
if(!s->budget--) { s->failed_pc=0x0c089302u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[13]>=(int32_t)r[10])!=0);
goto P_0c089304;
P_0c089304: /* original 8b03, guest PC 0x0c089304 */
if(!s->budget--) { s->failed_pc=0x0c089304u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c08930e; }
goto P_0c089306;
P_0c089306: /* original 65c3, guest PC 0x0c089306 */
if(!s->budget--) { s->failed_pc=0x0c089306u; return 0; }
r[5]=r[12];
goto P_0c089308;
P_0c089308: /* original be6a, guest PC 0x0c089308 */
if(!s->budget--) { s->failed_pc=0x0c089308u; return 0; }
target=code_base|0x0c088fe0u; r[16]=code_base|0x0c08930cu;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08930cu) { target=s->pc; goto dispatch; }
goto P_0c08930c;
P_0c08930a: /* original 64e3, guest PC 0x0c08930a */
if(!s->budget--) { s->failed_pc=0x0c08930au; return 0; }
r[4]=r[14];
goto P_0c08930c;
P_0c08930c: /* original 6db3, guest PC 0x0c08930c */
if(!s->budget--) { s->failed_pc=0x0c08930cu; return 0; }
r[13]=r[11];
goto P_0c08930e;
P_0c08930e: /* original 60d3, guest PC 0x0c08930e */
if(!s->budget--) { s->failed_pc=0x0c08930eu; return 0; }
r[0]=r[13];
goto P_0c089310;
P_0c089310: /* original 81e5, guest PC 0x0c089310 */
if(!s->budget--) { s->failed_pc=0x0c089310u; return 0; }
write(ram,r[14]+10,r[0],2);
goto P_0c089312;
P_0c089312: /* original 85e4, guest PC 0x0c089312 */
if(!s->budget--) { s->failed_pc=0x0c089312u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+8,2);
goto P_0c089314;
P_0c089314: /* original 6403, guest PC 0x0c089314 */
if(!s->budget--) { s->failed_pc=0x0c089314u; return 0; }
r[4]=r[0];
goto P_0c089316;
P_0c089316: /* original e02c, guest PC 0x0c089316 */
if(!s->budget--) { s->failed_pc=0x0c089316u; return 0; }
r[0]=0x0000002cu;
goto P_0c089318;
P_0c089318: /* original 05ec, guest PC 0x0c089318 */
if(!s->budget--) { s->failed_pc=0x0c089318u; return 0; }
r[5]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c08931a;
P_0c08931a: /* original 3453, guest PC 0x0c08931a */
if(!s->budget--) { s->failed_pc=0x0c08931au; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=(int32_t)r[5])!=0);
goto P_0c08931c;
P_0c08931c: /* original 8b04, guest PC 0x0c08931c */
if(!s->budget--) { s->failed_pc=0x0c08931cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c089328; }
goto P_0c08931e;
P_0c08931e: /* original 65c3, guest PC 0x0c08931e */
if(!s->budget--) { s->failed_pc=0x0c08931eu; return 0; }
r[5]=r[12];
goto P_0c089320;
P_0c089320: /* original beb2, guest PC 0x0c089320 */
if(!s->budget--) { s->failed_pc=0x0c089320u; return 0; }
target=code_base|0x0c089088u; r[16]=code_base|0x0c089324u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c089324u) { target=s->pc; goto dispatch; }
goto P_0c089324;
P_0c089322: /* original 64e3, guest PC 0x0c089322 */
if(!s->budget--) { s->failed_pc=0x0c089322u; return 0; }
r[4]=r[14];
goto P_0c089324;
P_0c089324: /* original a001, guest PC 0x0c089324 */
if(!s->budget--) { s->failed_pc=0x0c089324u; return 0; }
r[4]=r[11];
goto P_0c08932a;
P_0c089326: /* original 64b3, guest PC 0x0c089326 */
if(!s->budget--) { s->failed_pc=0x0c089326u; return 0; }
r[4]=r[11];
goto P_0c089328;
P_0c089328: /* original 7401, guest PC 0x0c089328 */
if(!s->budget--) { s->failed_pc=0x0c089328u; return 0; }
r[4]+=0x00000001u;
goto P_0c08932a;
P_0c08932a: /* original 6043, guest PC 0x0c08932a */
if(!s->budget--) { s->failed_pc=0x0c08932au; return 0; }
r[0]=r[4];
goto P_0c08932c;
P_0c08932c: /* original 7cff, guest PC 0x0c08932c */
if(!s->budget--) { s->failed_pc=0x0c08932cu; return 0; }
r[12]+=0xffffffffu;
goto P_0c08932e;
P_0c08932e: /* original 81e4, guest PC 0x0c08932e */
if(!s->budget--) { s->failed_pc=0x0c08932eu; return 0; }
write(ram,r[14]+8,r[0],2);
goto P_0c089330;
P_0c089330: /* original 2cc8, guest PC 0x0c089330 */
if(!s->budget--) { s->failed_pc=0x0c089330u; return 0; }
r[17]=(r[17]&~1u)|(((r[12]&r[12])==0)!=0);
goto P_0c089332;
P_0c089332: /* original 8bc1, guest PC 0x0c089332 */
if(!s->budget--) { s->failed_pc=0x0c089332u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0892b8; }
goto P_0c089334;
P_0c089334: /* original 7f04, guest PC 0x0c089334 */
if(!s->budget--) { s->failed_pc=0x0c089334u; return 0; }
r[15]+=0x00000004u;
goto P_0c089336;
P_0c089336: /* original 4f26, guest PC 0x0c089336 */
if(!s->budget--) { s->failed_pc=0x0c089336u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c089338;
P_0c089338: /* original 68f6, guest PC 0x0c089338 */
if(!s->budget--) { s->failed_pc=0x0c089338u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c08933a;
P_0c08933a: /* original 69f6, guest PC 0x0c08933a */
if(!s->budget--) { s->failed_pc=0x0c08933au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c08933c;
P_0c08933c: /* original 6af6, guest PC 0x0c08933c */
if(!s->budget--) { s->failed_pc=0x0c08933cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c08933e;
P_0c08933e: /* original 6bf6, guest PC 0x0c08933e */
if(!s->budget--) { s->failed_pc=0x0c08933eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c089340;
P_0c089340: /* original 6cf6, guest PC 0x0c089340 */
if(!s->budget--) { s->failed_pc=0x0c089340u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c089342;
P_0c089342: /* original 6df6, guest PC 0x0c089342 */
if(!s->budget--) { s->failed_pc=0x0c089342u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c089344;
P_0c089344: /* original 000b, guest PC 0x0c089344 */
if(!s->budget--) { s->failed_pc=0x0c089344u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c089346: /* original 6ef6, guest PC 0x0c089346 */
if(!s->budget--) { s->failed_pc=0x0c089346u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c089348u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c089348u; return 0; } return 1;
P_0c0a7662: /* original 2fe6, guest PC 0x0c0a7662 */
if(!s->budget--) { s->failed_pc=0x0c0a7662u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a7664;
P_0c0a7664: /* original 932b, guest PC 0x0c0a7664 */
if(!s->budget--) { s->failed_pc=0x0c0a7664u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a76beu,2);
goto P_0c0a7666;
P_0c0a7666: /* original 4f22, guest PC 0x0c0a7666 */
if(!s->budget--) { s->failed_pc=0x0c0a7666u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0a7668;
P_0c0a7668: /* original 3433, guest PC 0x0c0a7668 */
if(!s->budget--) { s->failed_pc=0x0c0a7668u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=(int32_t)r[3])!=0);
goto P_0c0a766a;
P_0c0a766a: /* original 8925, guest PC 0x0c0a766a */
if(!s->budget--) { s->failed_pc=0x0c0a766au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a76b8; }
goto P_0c0a766c;
P_0c0a766c: /* original d014, guest PC 0x0c0a766c */
if(!s->budget--) { s->failed_pc=0x0c0a766cu; return 0; }
r[0]=read(ram,0x0c0a76c0u,4);
goto P_0c0a766e;
P_0c0a766e: /* original 6e43, guest PC 0x0c0a766e */
if(!s->budget--) { s->failed_pc=0x0c0a766eu; return 0; }
r[14]=r[4];
goto P_0c0a7670;
P_0c0a7670: /* original 4e08, guest PC 0x0c0a7670 */
if(!s->budget--) { s->failed_pc=0x0c0a7670u; return 0; }
r[14]<<=2;
goto P_0c0a7672;
P_0c0a7672: /* original 0eee, guest PC 0x0c0a7672 */
if(!s->budget--) { s->failed_pc=0x0c0a7672u; return 0; }
r[14]=read(ram,r[14]+r[0],4);
goto P_0c0a7674;
P_0c0a7674: /* original 2ee8, guest PC 0x0c0a7674 */
if(!s->budget--) { s->failed_pc=0x0c0a7674u; return 0; }
r[17]=(r[17]&~1u)|(((r[14]&r[14])==0)!=0);
goto P_0c0a7676;
P_0c0a7676: /* original 891f, guest PC 0x0c0a7676 */
if(!s->budget--) { s->failed_pc=0x0c0a7676u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a76b8; }
goto P_0c0a7678;
P_0c0a7678: /* original 60e3, guest PC 0x0c0a7678 */
if(!s->budget--) { s->failed_pc=0x0c0a7678u; return 0; }
r[0]=r[14];
goto P_0c0a767a;
P_0c0a767a: /* original 88ff, guest PC 0x0c0a767a */
if(!s->budget--) { s->failed_pc=0x0c0a767au; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xffffffffu)!=0);
goto P_0c0a767c;
P_0c0a767c: /* original 891c, guest PC 0x0c0a767c */
if(!s->budget--) { s->failed_pc=0x0c0a767cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a76b8; }
goto P_0c0a767e;
P_0c0a767e: /* original d311, guest PC 0x0c0a767e */
if(!s->budget--) { s->failed_pc=0x0c0a767eu; return 0; }
r[3]=read(ram,0x0c0a76c4u,4);
goto P_0c0a7680;
P_0c0a7680: /* original 430b, guest PC 0x0c0a7680 */
if(!s->budget--) { s->failed_pc=0x0c0a7680u; return 0; }
target=r[3];
r[16]=code_base|0x0c0a7684u;
r[4]=0x00000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a7684u) { target=s->pc; goto dispatch; }
goto P_0c0a7684;
P_0c0a7682: /* original e400, guest PC 0x0c0a7682 */
if(!s->budget--) { s->failed_pc=0x0c0a7682u; return 0; }
r[4]=0x00000000u;
goto P_0c0a7684;
P_0c0a7684: /* original d211, guest PC 0x0c0a7684 */
if(!s->budget--) { s->failed_pc=0x0c0a7684u; return 0; }
r[2]=read(ram,0x0c0a76ccu,4);
goto P_0c0a7686;
P_0c0a7686: /* original d410, guest PC 0x0c0a7686 */
if(!s->budget--) { s->failed_pc=0x0c0a7686u; return 0; }
r[4]=read(ram,0x0c0a76c8u,4);
goto P_0c0a7688;
P_0c0a7688: /* original 420b, guest PC 0x0c0a7688 */
if(!s->budget--) { s->failed_pc=0x0c0a7688u; return 0; }
target=r[2];
r[16]=code_base|0x0c0a768cu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a768cu) { target=s->pc; goto dispatch; }
goto P_0c0a768c;
P_0c0a768a: /* original 0009, guest PC 0x0c0a768a */
if(!s->budget--) { s->failed_pc=0x0c0a768au; return 0; }
goto P_0c0a768c;
P_0c0a768c: /* original 50e1, guest PC 0x0c0a768c */
if(!s->budget--) { s->failed_pc=0x0c0a768cu; return 0; }
r[0]=read(ram,r[14]+4,4);
goto P_0c0a768e;
P_0c0a768e: /* original c801, guest PC 0x0c0a768e */
if(!s->budget--) { s->failed_pc=0x0c0a768eu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&1u)==0)!=0);
goto P_0c0a7690;
P_0c0a7690: /* original 8904, guest PC 0x0c0a7690 */
if(!s->budget--) { s->failed_pc=0x0c0a7690u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a769c; }
goto P_0c0a7692;
P_0c0a7692: /* original d213, guest PC 0x0c0a7692 */
if(!s->budget--) { s->failed_pc=0x0c0a7692u; return 0; }
r[2]=read(ram,0x0c0a76e0u,4);
goto P_0c0a7694;
P_0c0a7694: /* original 420b, guest PC 0x0c0a7694 */
if(!s->budget--) { s->failed_pc=0x0c0a7694u; return 0; }
target=r[2];
r[16]=code_base|0x0c0a7698u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a7698u) { target=s->pc; goto dispatch; }
goto P_0c0a7698;
P_0c0a7696: /* original 64e3, guest PC 0x0c0a7696 */
if(!s->budget--) { s->failed_pc=0x0c0a7696u; return 0; }
r[4]=r[14];
goto P_0c0a7698;
P_0c0a7698: /* original a009, guest PC 0x0c0a7698 */
if(!s->budget--) { s->failed_pc=0x0c0a7698u; return 0; }
goto P_0c0a76ae;
P_0c0a769a: /* original 0009, guest PC 0x0c0a769a */
if(!s->budget--) { s->failed_pc=0x0c0a769au; return 0; }
goto P_0c0a769c;
P_0c0a769c: /* original d20d, guest PC 0x0c0a769c */
if(!s->budget--) { s->failed_pc=0x0c0a769cu; return 0; }
r[2]=read(ram,0x0c0a76d4u,4);
goto P_0c0a769e;
P_0c0a769e: /* original 420b, guest PC 0x0c0a769e */
if(!s->budget--) { s->failed_pc=0x0c0a769eu; return 0; }
target=r[2];
r[16]=code_base|0x0c0a76a2u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a76a2u) { target=s->pc; goto dispatch; }
goto P_0c0a76a2;
P_0c0a76a0: /* original 0009, guest PC 0x0c0a76a0 */
if(!s->budget--) { s->failed_pc=0x0c0a76a0u; return 0; }
goto P_0c0a76a2;
P_0c0a76a2: /* original d310, guest PC 0x0c0a76a2 */
if(!s->budget--) { s->failed_pc=0x0c0a76a2u; return 0; }
r[3]=read(ram,0x0c0a76e4u,4);
goto P_0c0a76a4;
P_0c0a76a4: /* original 23e8, guest PC 0x0c0a76a4 */
if(!s->budget--) { s->failed_pc=0x0c0a76a4u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[14])==0)!=0);
goto P_0c0a76a6;
P_0c0a76a6: /* original 8902, guest PC 0x0c0a76a6 */
if(!s->budget--) { s->failed_pc=0x0c0a76a6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a76ae; }
goto P_0c0a76a8;
P_0c0a76a8: /* original d30f, guest PC 0x0c0a76a8 */
if(!s->budget--) { s->failed_pc=0x0c0a76a8u; return 0; }
r[3]=read(ram,0x0c0a76e8u,4);
goto P_0c0a76aa;
P_0c0a76aa: /* original 430b, guest PC 0x0c0a76aa */
if(!s->budget--) { s->failed_pc=0x0c0a76aau; return 0; }
target=r[3];
r[16]=code_base|0x0c0a76aeu;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a76aeu) { target=s->pc; goto dispatch; }
goto P_0c0a76ae;
P_0c0a76ac: /* original 64e3, guest PC 0x0c0a76ac */
if(!s->budget--) { s->failed_pc=0x0c0a76acu; return 0; }
r[4]=r[14];
goto P_0c0a76ae;
P_0c0a76ae: /* original 4f26, guest PC 0x0c0a76ae */
if(!s->budget--) { s->failed_pc=0x0c0a76aeu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a76b0;
P_0c0a76b0: /* original d30a, guest PC 0x0c0a76b0 */
if(!s->budget--) { s->failed_pc=0x0c0a76b0u; return 0; }
r[3]=read(ram,0x0c0a76dcu,4);
goto P_0c0a76b2;
P_0c0a76b2: /* original e401, guest PC 0x0c0a76b2 */
if(!s->budget--) { s->failed_pc=0x0c0a76b2u; return 0; }
r[4]=0x00000001u;
goto P_0c0a76b4;
P_0c0a76b4: /* original 432b, guest PC 0x0c0a76b4 */
if(!s->budget--) { s->failed_pc=0x0c0a76b4u; return 0; }
target=r[3];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
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
P_0c0a76b6: /* original 6ef6, guest PC 0x0c0a76b6 */
if(!s->budget--) { s->failed_pc=0x0c0a76b6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0a76b8;
P_0c0a76b8: /* original 4f26, guest PC 0x0c0a76b8 */
if(!s->budget--) { s->failed_pc=0x0c0a76b8u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a76ba;
P_0c0a76ba: /* original 000b, guest PC 0x0c0a76ba */
if(!s->budget--) { s->failed_pc=0x0c0a76bau; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0a76bc: /* original 6ef6, guest PC 0x0c0a76bc */
if(!s->budget--) { s->failed_pc=0x0c0a76bcu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0a76beu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0a76beu; return 0; } return 1;
P_0c0a7750: /* original 4f22, guest PC 0x0c0a7750 */
if(!s->budget--) { s->failed_pc=0x0c0a7750u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0a7752;
P_0c0a7752: /* original 7ffc, guest PC 0x0c0a7752 */
if(!s->budget--) { s->failed_pc=0x0c0a7752u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c0a7754;
P_0c0a7754: /* original 2f42, guest PC 0x0c0a7754 */
if(!s->budget--) { s->failed_pc=0x0c0a7754u; return 0; }
write(ram,r[15],r[4],4);
goto P_0c0a7756;
P_0c0a7756: /* original d333, guest PC 0x0c0a7756 */
if(!s->budget--) { s->failed_pc=0x0c0a7756u; return 0; }
r[3]=read(ram,0x0c0a7824u,4);
goto P_0c0a7758;
P_0c0a7758: /* original 430b, guest PC 0x0c0a7758 */
if(!s->budget--) { s->failed_pc=0x0c0a7758u; return 0; }
target=r[3];
r[16]=code_base|0x0c0a775cu;
r[4]=0x00000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a775cu) { target=s->pc; goto dispatch; }
goto P_0c0a775c;
P_0c0a775a: /* original e400, guest PC 0x0c0a775a */
if(!s->budget--) { s->failed_pc=0x0c0a775au; return 0; }
r[4]=0x00000000u;
goto P_0c0a775c;
P_0c0a775c: /* original d239, guest PC 0x0c0a775c */
if(!s->budget--) { s->failed_pc=0x0c0a775cu; return 0; }
r[2]=read(ram,0x0c0a7844u,4);
goto P_0c0a775e;
P_0c0a775e: /* original 420b, guest PC 0x0c0a775e */
if(!s->budget--) { s->failed_pc=0x0c0a775eu; return 0; }
target=r[2];
r[16]=code_base|0x0c0a7762u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a7762u) { target=s->pc; goto dispatch; }
goto P_0c0a7762;
P_0c0a7760: /* original 0009, guest PC 0x0c0a7760 */
if(!s->budget--) { s->failed_pc=0x0c0a7760u; return 0; }
goto P_0c0a7762;
P_0c0a7762: /* original bf7e, guest PC 0x0c0a7762 */
if(!s->budget--) { s->failed_pc=0x0c0a7762u; return 0; }
target=code_base|0x0c0a7662u; r[16]=code_base|0x0c0a7766u;
tmp=read(ram,r[15],4);
r[4]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a7766u) { target=s->pc; goto dispatch; }
goto P_0c0a7766;
P_0c0a7764: /* original 64f2, guest PC 0x0c0a7764 */
if(!s->budget--) { s->failed_pc=0x0c0a7764u; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c0a7766;
P_0c0a7766: /* original d236, guest PC 0x0c0a7766 */
if(!s->budget--) { s->failed_pc=0x0c0a7766u; return 0; }
r[2]=read(ram,0x0c0a7840u,4);
goto P_0c0a7768;
P_0c0a7768: /* original 7f04, guest PC 0x0c0a7768 */
if(!s->budget--) { s->failed_pc=0x0c0a7768u; return 0; }
r[15]+=0x00000004u;
goto P_0c0a776a;
P_0c0a776a: /* original e401, guest PC 0x0c0a776a */
if(!s->budget--) { s->failed_pc=0x0c0a776au; return 0; }
r[4]=0x00000001u;
goto P_0c0a776c;
P_0c0a776c: /* original 422b, guest PC 0x0c0a776c */
if(!s->budget--) { s->failed_pc=0x0c0a776cu; return 0; }
target=r[2];
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
P_0c0a776e: /* original 4f26, guest PC 0x0c0a776e */
if(!s->budget--) { s->failed_pc=0x0c0a776eu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
if(!vf3_matrix_family(0x0c0a7770u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0a7770u; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
